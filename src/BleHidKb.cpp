
#include "BleHidKb.h"

// Forward declarations
void bluetoothTask(void *);
void typeText(const char *text);

/// @brief True if the Bluetooth Connection was made by a host.
bool isBleConnected = false;
bool bCapsLock = false; //If true caps lock is active
bool bNumLock = false; //If true num lock is active
bool bScrollLock = false; //If true scroll lock is active

bool numLockIsOn()
{
  return bNumLock;
}

bool capsLockIsOn()
{
  return bCapsLock;
}

bool scrollLockIsOn()
{
  return bScrollLock;
}

bool bleIsConnected()
{
    return isBleConnected;
}

// The report map describes the HID device (a keyboard in this case) and
// the messages (reports in HID terms) sent and received.
static const uint8_t REPORT_MAP[] =
{
        USAGE_PAGE(1), 0x01,      // Generic Desktop Controls
        USAGE(1), 0x06,           // Keyboard
        COLLECTION(1), 0x01,      // Application
        REPORT_ID(1), 0x01,       //   Report ID (1)
        USAGE_PAGE(1), 0x07,      //   Keyboard/Keypad
        USAGE_MINIMUM(1), 0xE0,   //   Keyboard Left Control
        USAGE_MAXIMUM(1), 0xE7,   //   Keyboard Right Control
        LOGICAL_MINIMUM(1), 0x00, //   Each bit is either 0 or 1
        LOGICAL_MAXIMUM(1), 0x01,
        REPORT_COUNT(1), 0x08,    //   8 bits for the modifier keys
        REPORT_SIZE(1), 0x01,
        HIDINPUT(1), 0x02,        //   Data, Var, Abs
        REPORT_COUNT(1), 0x01,    //   1 byte (unused)
        REPORT_SIZE(1), 0x08,
        HIDINPUT(1), 0x01,        //   Const, Array, Abs
        REPORT_COUNT(1), 0x06,    //   6 bytes (for up to 6 concurrently pressed keys)
        REPORT_SIZE(1), 0x08,
        LOGICAL_MINIMUM(1), 0x00,
        LOGICAL_MAXIMUM(1), 0x65, //   101 keys
        USAGE_MINIMUM(1), 0x00,
        USAGE_MAXIMUM(1), 0x65,
        HIDINPUT(1), 0x00,        //   Data, Array, Abs
        REPORT_COUNT(1), 0x05,    //   5 bits (Num lock, Caps lock, Scroll lock, Compose, Kana)
        REPORT_SIZE(1), 0x01,
        USAGE_PAGE(1), 0x08,      //   LEDs
        USAGE_MINIMUM(1), 0x01,   //   Num Lock
        USAGE_MAXIMUM(1), 0x05,   //   Kana
        LOGICAL_MINIMUM(1), 0x00,
        LOGICAL_MAXIMUM(1), 0x01,
        HIDOUTPUT(1), 0x02,       //   Data, Var, Abs
        REPORT_COUNT(1), 0x01,    //   3 bits (Padding)
        REPORT_SIZE(1), 0x03,
        HIDOUTPUT(1), 0x01,       //   Const, Array, Abs
        END_COLLECTION(0)         // End application collection
};

BLEHIDDevice *hid;
BLECharacteristic *input;
BLECharacteristic *output;

const hid_keyboard_report_t NO_KEY_PRESSED = {0, 0, 0, 0, 0, 0, 0, 0};

/*
 * Callbacks related to BLE connection
 */
class BleKeyboardCallbacks : public BLEServerCallbacks
{
  void onConnect(BLEServer *server)
  {
    isBleConnected = true;

    // Allow notifications for characteristics
    BLE2902 *cccDesc = (BLE2902 *)input->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    cccDesc->setNotifications(true);

    //Serial.println("Client has connected");
  }

  // void onDisconnect(BLEServer *server)
  // {
  //   isBleConnected = false;

  //   // Disallow notifications for characteristics
  //   BLE2902 *cccDesc = (BLE2902 *)input->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
  //   cccDesc->setNotifications(false);

  //   Serial.println("Client has disconnected");
  // }

  void onDisconnect(BLEServer *server)
  {
    isBleConnected = false;

    // Disallow notifications for characteristics
    BLE2902 *cccDesc = (BLE2902 *)input->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    cccDesc->setNotifications(false);

    server->getAdvertising()->start();
    //Serial.println("BLE client has disconnected.");
  }
};

/*
 * Called when the client (computer, smart phone) wants to turn on or off
 * the LEDs in the keyboard.  Sets the capsLock, numLock and scrollLock static variables.
 * When the ESP32 is used as a keyboard manager the LEDs will be connected to the ESP32 board instead.
 *
 * bit 0 - NUM LOCK
 * bit 1 - CAPS LOCK
 * bit 2 - SCROLL LOCK
 */
class OutputCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *characteristic)
  {
    hid_keyboard_output_report_t *report = (hid_keyboard_output_report_t *)characteristic->getData();
    //Serial.printf("LED state: %02X\n", report->leds);
    bCapsLock = (report->leds & 0x02) != 0;
    bNumLock = (report->leds & 0x01) != 0;
    bScrollLock = (report->leds & 0x04) != 0;
    //updateLeds();
    //Serial.printf("(onWrite) numLock is: %s, capsLock is: %s, scrollLock is: %s\n", bNumLock ? "On" : "Off", bCapsLock ? "On" : "Off", bScrollLock ? "On" : "Off");
  }
};

void bluetoothTask(void *)
{
  // initialize the device
  BLEDevice::init(DEVICE_NAME);
  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new BleKeyboardCallbacks());

  // create an HID device
  hid = new BLEHIDDevice(server);
  input = hid->inputReport(1);   // report ID
  output = hid->outputReport(1); // report ID
  output->setCallbacks(new OutputCallbacks());

  // set manufacturer name
  hid->manufacturer()->setValue("Tech-Relief");
  // set USB vendor and product ID
  hid->pnp(0x02, 0xe502, 0xa111, 0x0210);
  // information about HID device: device is not localized, device can be connected
  hid->hidInfo(0x00, 0x02);

  // Security: device requires bonding
  BLESecurity *security = new BLESecurity();
  security->setAuthenticationMode(ESP_LE_AUTH_BOND);

  // set report map
  hid->reportMap((uint8_t *)REPORT_MAP, sizeof(REPORT_MAP));
  hid->startServices();

  // set battery level to 100%
  hid->setBatteryLevel(100); //TODO: Check battery voltage and compute battery level

  // advertise the services
  BLEAdvertising *advertising = server->getAdvertising();
  advertising->setAppearance(HID_KEYBOARD);
  advertising->addServiceUUID(hid->hidService()->getUUID());
  advertising->addServiceUUID(hid->deviceInfo()->getUUID());
  advertising->addServiceUUID(hid->batteryService()->getUUID());
  advertising->start();

  //Serial.println("BLE ready");
  delay(portMAX_DELAY);
};

void sendCtrlKey(char key)
{
    // create input report
    hid_keyboard_report_t report =
    {
        .modifier = KEY_CTRL,
        .reserved = 0,
        .keycode = { keymap[(uint8_t)key].usage, 0, 0, 0, 0, 0 }
    };

    // send the input report
    input->setValue((uint8_t*)&report, sizeof(report));
    input->notify();
    delay(5);

    // release all keys
    input->setValue((uint8_t*)&NO_KEY_PRESSED, sizeof(NO_KEY_PRESSED));
    input->notify();
    delay(5);
}

void typeText(const char *text)
{
  int len = strlen(text);
  for (int i = 0; i < len; i++)
  {
    //Serial.println("Typing...");
    // translate character to key combination
    uint8_t val = (uint8_t)text[i];
    if (val > KEYMAP_SIZE)
      continue; // character not available on keyboard - skip
    KEYMAP map = keymap[val];

    // create input report
    hid_keyboard_report_t report = {
        .modifier = map.modifier,
        .reserved = 0,
        .keycode = {
            map.usage,
            0, 0, 0, 0, 0}};

    // send the input report
    input->setValue((uint8_t *)&report, sizeof(report));
    input->notify();

    delay(5);

    // release all keys between two characters; otherwise two identical
    // consecutive characters are treated as just one key press
    input->setValue((uint8_t *)&NO_KEY_PRESSED, sizeof(NO_KEY_PRESSED));
    input->notify();

    delay(5);
  }
}

void sendInputReport(hid_keyboard_report_t report)
{
  // send the input report
  input->setValue((uint8_t*)&report, sizeof(report));
  input->notify();
  delay(5);
}

void sendReport(hid_keyboard_report_t report)
{
  // send the input report
  sendInputReport(report);

  // release all keys
  input->setValue((uint8_t*)&NO_KEY_PRESSED, sizeof(NO_KEY_PRESSED));
  input->notify();
  delay(5);
}

void sendKeyCode(uint8_t keyCode, uint8_t modifier)
{
  // create input report
  hid_keyboard_report_t report = {
      .modifier = modifier,
      .reserved = 0,
      .keycode = { keyCode, 0, 0, 0, 0, 0 }
  };
  // send the input report
  sendReport(report);
}

// example: sendKeyCode(KEY_DOWN);
void sendKeyCode(uint8_t keyCode)
{
  sendKeyCode(keyCode, 0);
}
