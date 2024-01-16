/*
This code shows how the XiaoS3 board can input keystrokes from a USB keyboard using it's USB Host female port 
and output the keystrokes via bluetooth.  In otherwords we have created a keyboard dongle.
This code can be the starting point for a number of projects such as a wireless keyboard controller or a
keyboard dongle that add functionality to a keyboard such as macros or recording keystrokes etc.
On the XiaoS3 board you only have one USB port so it will not be possible to us Serial Monitor output and also 
after uploading and running the code you will need to hold down the Boot button when plugging in the USB-C cable
to get it back into code upload mode.
If using a different ESP32-S3 based board you will have to determine how to manage the USB port(s).
*/
#include <Arduino.h>
#include <SPI.h>
#include "EspUsbHostEx.h"
#include <BLEDevice.h>
#include <BLEAdvertising.h>

BLEMultiAdvertising advert(1); // Max number of advertisement data 

bool insertMode = true;

bool isText(uint8_t code)
{
  return ((code >= HID_KEY_A && code <= HID_KEY_0) ||
          (code >= HID_KEY_KEYPAD_1 && code <= HID_KEY_KEYPAD_EQUAL));
}

/// @brief The USB Host class used to administer and controll the USB Host port.
///        It includes several "call-back" methods such as onKeyboard(...) and onKeyboardKey(...) to return keycode information when a key is pressed.
///        Enable or Disable the RAW_REPORT and/or the KEY_REPORT defines in EspUsbHostEx.h depending on which versions you need for porcessing.
class UsbHost : public EspUsbHost
{
  #ifdef RAW_REPORT
  void onKeyboard(hid_keyboard_report_t report, hid_keyboard_report_t prevReport, hid_key_modifier mod)
  {
    if (report.keycode[0] == HID_KEY_INSERT)
      insertMode = !insertMode; 
    else
    {
      if (!insertMode)
      {
        if (isText(report.keycode[0]))
        {
          hid_keyboard_report_t tmpReport = report;
          tmpReport.keycode[0] = HID_KEY_DELETE;
          sendInputReport(tmpReport);
        }
      }
      sendInputReport(report);  //Send it out via BLE
    }
  }
  #endif

};

UsbHost usbHost;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  // start the Bluetooth task
  xTaskCreate(bluetoothTask, "bluetooth", 20000, NULL, 5, NULL);  //Second to last parameter is called uxPriority and was set to 5 on some boards this may need to be tweeked.

  usbHost.begin();
  usbHost.setHIDLocal(HID_LOCAL_International);
}

void loop(void)
{
  usbHost.task();
}
