#include "EspUsbHostEx.h"

/// @brief Used to check if the modifier has the Shift bit set
/// @param modifier 
/// @return Returns true if Shift bit is set
bool hasShift(uint8_t modifier)
{
  return (modifier & SHIFT_MASK) != 0;
}

/// @brief Used to check if the modifier has the Alt bit set
/// @param modifier 
/// @return Returns true if Alt bit is set
bool hasAlt(uint8_t modifier)
{
  return (modifier & ALT_MASK) != 0;
}

/// @brief Used to check if the modifier has the Ctrl bit set
/// @param modifier 
/// @return Returns true if Ctrl bit is set
bool hasCtrl(uint8_t modifier)
{
  return (modifier & CTRL_MASK) != 0;
}

/// @brief Used to check if the modifier has the Win bit set
/// @param modifier 
/// @return Returns true if Win bit is set
bool hasWin(uint8_t modifier) //4JAN24 - TR Added support for WIN keys
{
  return (modifier & WIN_MASK) != 0;
}

/// @brief Translates a HID keycode and outputs a human readable key name like "F1" etc.
/// @param hidCode Keycode to translate.
/// @return Key name as a string.
String XlatHidCode(uint8_t hidCode)
{
 /* Not Processed, add if needed
 HID_KEY_KEYPAD_DIVIDE             0x54
 HID_KEY_KEYPAD_MULTIPLY           0x55
 HID_KEY_KEYPAD_SUBTRACT           0x56
 HID_KEY_KEYPAD_ADD                0x57
 HID_KEY_KEYPAD_ENTER              0x58
 HID_KEY_KEYPAD_1                  0x59
 HID_KEY_KEYPAD_2                  0x5A
 HID_KEY_KEYPAD_3                  0x5B
 HID_KEY_KEYPAD_4                  0x5C
 HID_KEY_KEYPAD_5                  0x5D
 HID_KEY_KEYPAD_6                  0x5E
 HID_KEY_KEYPAD_7                  0x5F
 HID_KEY_KEYPAD_8                  0x60
 HID_KEY_KEYPAD_9                  0x61
 HID_KEY_KEYPAD_0                  0x62
 HID_KEY_KEYPAD_DECIMAL            0x63
 HID_KEY_EUROPE_2                  0x64
 HID_KEY_APPLICATION               0x65 Menu Key?
 HID_KEY_F13                       0x68
 HID_KEY_F14                       0x69
 HID_KEY_F15                       0x6A
 HID_KEY_F16                       0x6B
 HID_KEY_F17                       0x6C
 HID_KEY_F18                       0x6D
 HID_KEY_F19                       0x6E
 HID_KEY_F20                       0x6F
 HID_KEY_F21                       0x70
 HID_KEY_F22                       0x71
 HID_KEY_F23                       0x72
 HID_KEY_F24                       0x73
 HID_KEY_APPLICATION               0x65
 HID_KEY_POWER                     0x66
 HID_KEY_KEYPAD_EQUAL              0x67
 HID_KEY_EXECUTE                   0x74
 HID_KEY_HELP                      0x75
 HID_KEY_MENU                      0x76
 HID_KEY_SELECT                    0x77
 HID_KEY_STOP                      0x78
 HID_KEY_AGAIN                     0x79
 HID_KEY_UNDO                      0x7A
 HID_KEY_CUT                       0x7B
 HID_KEY_COPY                      0x7C
 HID_KEY_PASTE                     0x7D
 HID_KEY_FIND                      0x7E
 HID_KEY_MUTE                      0x7F
 HID_KEY_VOLUME_UP                 0x80
 HID_KEY_VOLUME_DOWN               0x81
 HID_KEY_LOCKING_CAPS_LOCK         0x82
 HID_KEY_LOCKING_NUM_LOCK          0x83
 HID_KEY_LOCKING_SCROLL_LOCK       0x84
 HID_KEY_KEYPAD_COMMA              0x85
 HID_KEY_KEYPAD_EQUAL_SIGN         0x86
 HID_KEY_ALTERNATE_ERASE           0x99
 HID_KEY_SYSREQ_ATTENTION          0x9A
 HID_KEY_CANCEL                    0x9B
 HID_KEY_CLEAR                     0x9C
 HID_KEY_PRIOR                     0x9D
 HID_KEY_RETURN                    0x9E
 HID_KEY_SEPARATOR                 0x9F
 HID_KEY_OUT                       0xA0
 HID_KEY_OPER                      0xA1
 HID_KEY_CLEAR_AGAIN               0xA2
 HID_KEY_CRSEL_PROPS               0xA3
 HID_KEY_EXSEL                     0xA4
 HID_KEY_CONTROL_LEFT              0xE0
 HID_KEY_SHIFT_LEFT                0xE1
 HID_KEY_ALT_LEFT                  0xE2
 HID_KEY_CONTROL_RIGHT             0xE4
 HID_KEY_SHIFT_RIGHT               0xE5
 HID_KEY_ALT_RIGHT                 0xE6
*/
  switch (hidCode)
  {
    case (HID_KEY_ENTER):
      return ("Enter");
    case (HID_KEY_ESCAPE):
      return "Esc";
    case (HID_KEY_BACKSPACE):
      return "Backspace";
    case (HID_KEY_TAB):
      return "Tab";
    case (HID_KEY_CAPS_LOCK):
      return "Caps";
    case (HID_KEY_F1):
      return "F1";
    case (HID_KEY_F2):
      return "F2";
    case (HID_KEY_F3):
      return "F3";
    case (HID_KEY_F4):
      return "F4";
    case (HID_KEY_F5):
      return "F5";
    case (HID_KEY_F6):
      return "F6";
    case (HID_KEY_F7):
      return "F7";
    case (HID_KEY_F8):
      return "F8";
    case (HID_KEY_F9):
      return "F9";
    case (HID_KEY_F10):
      return "F10";
    case (HID_KEY_F11):
      return "F11";
    case (HID_KEY_F12):
      return "F12";
    case (HID_KEY_PRINT_SCREEN):
      return "PrtSc";
    case (HID_KEY_SCROLL_LOCK):
      return "ScrLk";
    case (HID_KEY_PAUSE):
      return "Pause";
    case (HID_KEY_INSERT):
      return "Ins";
    case (HID_KEY_HOME):
      return "Home";
    case (HID_KEY_PAGE_UP):
      return "PgUp";
    case (HID_KEY_DELETE):
      return "Del";
    case (HID_KEY_END):
      return "End";
    case (HID_KEY_PAGE_DOWN):
      return "PgDn";
    case (HID_KEY_ARROW_RIGHT):
      return "Right";
    case (HID_KEY_ARROW_LEFT):
      return "Left";
    case (HID_KEY_ARROW_DOWN):
      return "Down";
    case (HID_KEY_ARROW_UP):
      return "Up";
    case (HID_KEY_NUM_LOCK):
      return "NumLk";
    case (HID_KEY_APPLICATION):
      return "Menu";
    case (HID_KEY_GUI_LEFT): //4JAN24 Added support for Win key
    case (HID_KEY_GUI_RIGHT):
      return"Win";
    default:
      return "n/a";
  }
  return "?";  //Should never come here...
}

void EspUsbHost::_printPcapText(const char *title, uint16_t function, uint8_t direction, uint8_t endpoint, uint8_t type, uint8_t size, uint8_t stage, const uint8_t *data)
{
  uint8_t urbsize = 0x1c;
  if (stage == 0xff) {
    urbsize = 0x1b;
  }

  String data_str = "";
  for (int i = 0; i < size; i++) {
    if (data[i] < 16) {
      data_str += "0";
    }
    data_str += String(data[i], HEX) + " ";
  }

  printf("\n");
  printf("[PCAP TEXT]%s\n", title);
  printf("0000  %02x 00 00 00 00 00 00 00 00 00 00 00 00 00 %02x %02x\n", urbsize, (function & 0xff), ((function >> 8) & 0xff));
  printf("0010  %02x 01 00 01 00 %02x %02x %02x 00 00 00", direction, endpoint, type, size);
  if (stage != 0xff) {
    printf(" %02x\n", stage);
  } else {
    printf("\n");
  }
  printf("00%02x  %s\n", urbsize, data_str.c_str());
  printf("\n");
}

void EspUsbHost::begin(void)
{
  usbTransferSize = 0;
  const usb_host_config_t config = {
    .skip_phy_setup = false,
    .intr_flags = ESP_INTR_FLAG_LEVEL1,
  };
  esp_err_t err = usb_host_install(&config);
  if (err != ESP_OK) {
    ESP_LOGI("EspUsbHost", "usb_host_install() err=%x", err);
  } else {
    ESP_LOGI("EspUsbHost", "usb_host_install() ESP_OK");
  }

  const usb_host_client_config_t client_config = {
    .is_synchronous = true,
    .max_num_event_msg = 10,
    .async = {
      .client_event_callback = this->_clientEventCallback,
      .callback_arg = this,
    }
  };
  err = usb_host_client_register(&client_config, &this->clientHandle);
  if (err != ESP_OK) {
    ESP_LOGI("EspUsbHost", "usb_host_client_register() err=%x", err);
  } else {
    ESP_LOGI("EspUsbHost", "usb_host_client_register() ESP_OK");
  }
}

//TR - Added 9JAN24
void decodeModifiers(uint8_t modifier, hid_key_modifier& keyMod)
{
  //TR - Added functionality to include Win, Alt and Ctrl aswell as Shift
  keyMod.shift = (modifier & KEYBOARD_MODIFIER_LEFTSHIFT) || (modifier & KEYBOARD_MODIFIER_RIGHTSHIFT);
  keyMod.alt = (modifier & KEYBOARD_MODIFIER_LEFTALT) || (modifier & KEYBOARD_MODIFIER_RIGHTALT);
  keyMod.ctrl = (modifier & KEYBOARD_MODIFIER_LEFTCTRL) || (modifier & KEYBOARD_MODIFIER_RIGHTCTRL);
  keyMod.win = (modifier & KEYBOARD_MODIFIER_LEFTGUI) || (modifier & KEYBOARD_MODIFIER_RIGHTGUI); //4JAN24 - TR Added support for WIN keys
  keyMod.modbyte = 0;
  if (keyMod.shift)
    keyMod.modbyte |= SHIFT_MASK; //Bit 0 signifies shift
  if (keyMod.alt)
    keyMod.modbyte |= ALT_MASK; //Bit 1 signifies alt //30DEC23 - Added support for ALT and CTRL keys
  if (keyMod.ctrl)
    keyMod.modbyte |= CTRL_MASK; //Bit 2 signifies ctrl
  if (keyMod.win)
    keyMod.modbyte |= WIN_MASK; //Bit 3 signifies Win //4JAN24 - TR Added support for WIN keys
}

void EspUsbHost::_clientEventCallback(const usb_host_client_event_msg_t *eventMsg, void *arg)
{
  EspUsbHost *usbHost = (EspUsbHost *)arg;

  esp_err_t err;
  switch (eventMsg->event)
  {
    case USB_HOST_CLIENT_EVENT_NEW_DEV:
      ESP_LOGI("EspUsbHost", "USB_HOST_CLIENT_EVENT_NEW_DEV new_dev.address=%d", eventMsg->new_dev.address);
      err = usb_host_device_open(usbHost->clientHandle, eventMsg->new_dev.address, &usbHost->deviceHandle);
      if (err != ESP_OK)
      {
        ESP_LOGI("EspUsbHost", "usb_host_device_open() err=%x", err);
      } 
      else
      {
        ESP_LOGI("EspUsbHost", "usb_host_device_open() ESP_OK");
      }

      usb_device_info_t dev_info;
      err = usb_host_device_info(usbHost->deviceHandle, &dev_info);
      if (err != ESP_OK)
      {
        ESP_LOGI("EspUsbHost", "usb_host_device_info() err=%x", err);
      } 
      else
      {
        ESP_LOGI("EspUsbHost", "usb_host_device_info() ESP_OK\n"
                               "# speed                 = %d\n"
                               "# dev_addr              = %d\n"
                               "# vMaxPacketSize0       = %d\n"
                               "# bConfigurationValue   = %d\n"
                               "# str_desc_manufacturer = \"%s\"\n"
                               "# str_desc_product      = \"%s\"\n"
                               "# str_desc_serial_num   = \"%s\"",
                 dev_info.speed,
                 dev_info.dev_addr,
                 dev_info.bMaxPacketSize0,
                 dev_info.bConfigurationValue,
                 getUsbDescString(dev_info.str_desc_manufacturer).c_str(),
                 getUsbDescString(dev_info.str_desc_product).c_str(),
                 getUsbDescString(dev_info.str_desc_serial_num).c_str());
      }

      const usb_device_desc_t *dev_desc;
      err = usb_host_get_device_descriptor(usbHost->deviceHandle, &dev_desc);
      if (err != ESP_OK)
      {
        ESP_LOGI("EspUsbHost", "usb_host_get_device_descriptor() err=%x", err);
      } 
      else
      {
        const uint8_t setup[8] = { 0x80, 0x06, 0x00, 0x01, 0x00, 0x00, 0x12, 0x00 };
        _printPcapText("GET DESCRIPTOR Request DEVICE", 0x000b, 0x00, 0x80, 0x02, sizeof(setup), 0x00, setup);
        _printPcapText("GET DESCRIPTOR Response DEVICE", 0x0008, 0x01, 0x80, 0x02, sizeof(usb_device_desc_t), 0x03, (const uint8_t *)dev_desc);

        ESP_LOGI("EspUsbHost", "usb_host_get_device_descriptor() ESP_OK\n"
                               "#### DESCRIPTOR DEVICE ####\n"
                               "# bLength            = %d\n"
                               "# bDescriptorType    = %d\n"
                               "# bcdUSB             = 0x%x\n"
                               "# bDeviceClass       = 0x%x\n"
                               "# bDeviceSubClass    = 0x%x\n"
                               "# bDeviceProtocol    = 0x%x\n"
                               "# bMaxPacketSize0    = %d\n"
                               "# idVendor           = 0x%x\n"
                               "# idProduct          = 0x%x\n"
                               "# bcdDevice          = 0x%x\n"
                               "# iManufacturer      = %d\n"
                               "# iProduct           = %d\n"
                               "# iSerialNumber      = %d\n"
                               "# bNumConfigurations = %d",
                 dev_desc->bLength,
                 dev_desc->bDescriptorType,
                 dev_desc->bcdUSB,
                 dev_desc->bDeviceClass,
                 dev_desc->bDeviceSubClass,
                 dev_desc->bDeviceProtocol,
                 dev_desc->bMaxPacketSize0,
                 dev_desc->idVendor,
                 dev_desc->idProduct,
                 dev_desc->bcdDevice,
                 dev_desc->iManufacturer,
                 dev_desc->iProduct,
                 dev_desc->iSerialNumber,
                 dev_desc->bNumConfigurations);
      }

      const usb_config_desc_t *config_desc;
      err = usb_host_get_active_config_descriptor(usbHost->deviceHandle, &config_desc);
      if (err != ESP_OK)
      {
        ESP_LOGI("EspUsbHost", "usb_host_get_active_config_descriptor() err=%x", err);
      } 
      else 
      {
        const uint8_t setup[8] = { 0x80, 0x06, 0x00, 0x02, 0x00, 0x00, 0x09, 0x00 };
        _printPcapText("GET DESCRIPTOR Request CONFIGURATION", 0x000b, 0x00, 0x80, 0x02, sizeof(setup), 0x00, setup);
        _printPcapText("GET DESCRIPTOR Response CONFIGURATION", 0x0008, 0x01, 0x80, 0x02, sizeof(usb_config_desc_t), 0x03, (const uint8_t *)config_desc);

        ESP_LOGI("EspUsbHost", "usb_host_get_active_config_descriptor() ESP_OK\n"
                               "# bLength             = %d\n"
                               "# bDescriptorType     = %d\n"
                               "# wTotalLength        = %d\n"
                               "# bNumInterfaces      = %d\n"
                               "# bConfigurationValue = %d\n"
                               "# iConfiguration      = %d\n"
                               "# bmAttributes        = 0x%x\n"
                               "# bMaxPower           = %dmA",
                 config_desc->bLength,
                 config_desc->bDescriptorType,
                 config_desc->wTotalLength,
                 config_desc->bNumInterfaces,
                 config_desc->bConfigurationValue,
                 config_desc->iConfiguration,
                 config_desc->bmAttributes,
                 config_desc->bMaxPower * 2);
      }

      usbHost->_configCallback(config_desc);
      break;

    case USB_HOST_CLIENT_EVENT_DEV_GONE:
      {
        ESP_LOGI("EspUsbHost", "USB_HOST_CLIENT_EVENT_DEV_GONE dev_gone.dev_hdl=%x", eventMsg->dev_gone.dev_hdl);
        for (int i = 0; i < usbHost->usbTransferSize; i++)
        {
          if (usbHost->usbTransfer[i] == NULL)
          {
            continue;
          }

          err = usb_host_endpoint_clear(eventMsg->dev_gone.dev_hdl, usbHost->usbTransfer[i]->bEndpointAddress);
          if (err != ESP_OK)
          {
            ESP_LOGI("EspUsbHost", "usb_host_endpoint_clear() err=%x, dev_hdl=%x, bEndpointAddress=%x", err, eventMsg->dev_gone.dev_hdl, usbHost->usbTransfer[i]->bEndpointAddress);
          } 
          else 
          {
            ESP_LOGI("EspUsbHost", "usb_host_endpoint_clear() ESP_OK, dev_hdl=%x, bEndpointAddress=%x", eventMsg->dev_gone.dev_hdl, usbHost->usbTransfer[i]->bEndpointAddress);
          }

          err = usb_host_transfer_free(usbHost->usbTransfer[i]);
          if (err != ESP_OK) 
          {
            ESP_LOGI("EspUsbHost", "usb_host_transfer_free() err=%x, err, usbTransfer=%x", err, usbHost->usbTransfer[i]);
          } 
          else 
          {
            ESP_LOGI("EspUsbHost", "usb_host_transfer_free() ESP_OK, usbTransfer=%x", usbHost->usbTransfer[i]);
          }

          usbHost->usbTransfer[i] = NULL;
        }
        usbHost->usbTransferSize = 0;

        for (int i = 0; i < usbHost->usbInterfaceSize; i++)
        {
          err = usb_host_interface_release(usbHost->clientHandle, usbHost->deviceHandle, usbHost->usbInterface[i]);
          if (err != ESP_OK) 
          {
            ESP_LOGI("EspUsbHost", "usb_host_interface_release() err=%x, err, clientHandle=%x, deviceHandle=%x, Interface=%x", err, usbHost->clientHandle, usbHost->deviceHandle, usbHost->usbInterface[i]);
          } 
          else 
          {
            ESP_LOGI("EspUsbHost", "usb_host_interface_release() ESP_OK, clientHandle=%x, deviceHandle=%x, Interface=%x", usbHost->clientHandle, usbHost->deviceHandle, usbHost->usbInterface[i]);
          }

          usbHost->usbInterface[i] = 0;
        }
        usbHost->usbInterfaceSize = 0;

        usb_host_device_close(usbHost->clientHandle, usbHost->deviceHandle);

        usbHost->onGone(eventMsg);
      }
      break;

    default:
      ESP_LOGI("EspUsbHost", "clientEventCallback() default %d", eventMsg->event);
      break;
  }
}

void EspUsbHost::_configCallback(const usb_config_desc_t *config_desc) 
{
  const uint8_t *p = &config_desc->val[0];
  uint8_t bLength;

  const uint8_t setup[8] = { 0x80, 0x06, 0x00, 0x02, 0x00, 0x00, config_desc->wTotalLength, 0x00 };
  _printPcapText("GET DESCRIPTOR Request CONFIGURATION", 0x000b, 0x00, 0x80, 0x02, sizeof(setup), 0x00, setup);
  _printPcapText("GET DESCRIPTOR Response CONFIGURATION", 0x0008, 0x01, 0x80, 0x02, config_desc->wTotalLength, 0x03, (const uint8_t *)config_desc);

  for (int i = 0; i < config_desc->wTotalLength; i += bLength, p += bLength) 
  {
    bLength = *p;
    if ((i + bLength) <= config_desc->wTotalLength) 
    {
      const uint8_t bDescriptorType = *(p + 1);
      this->onConfig(bDescriptorType, p);
    } 
    else 
    {
      return;
    }
  }
}

void EspUsbHost::task(void) 
{
  esp_err_t err = usb_host_lib_handle_events(1, &this->eventFlags);
  if (err != ESP_OK && err != ESP_ERR_TIMEOUT) 
  {
    ESP_LOGI("EspUsbHost", "usb_host_lib_handle_events() err=%x eventFlags=%x", err, this->eventFlags);
  }

  err = usb_host_client_handle_events(this->clientHandle, 1);
  if (err != ESP_OK && err != ESP_ERR_TIMEOUT) 
  {
    ESP_LOGI("EspUsbHost", "usb_host_client_handle_events() err=%x", err);
  }

  if (this->isReady) 
  {
    unsigned long now = millis();
    if ((now - this->lastCheck) > this->interval) 
    {
      this->lastCheck = now;

      for (int i = 0; i < this->usbTransferSize; i++) 
      {
        if (this->usbTransfer[i] == NULL) 
        {
          continue;
        }

        esp_err_t err = usb_host_transfer_submit(this->usbTransfer[i]);
        if (err != ESP_OK && err != ESP_ERR_NOT_FINISHED && err != ESP_ERR_INVALID_STATE) 
        {
          //ESP_LOGI("EspUsbHost", "usb_host_transfer_submit() err=%x", err);
        }
      }
    }
  }
}

String EspUsbHost::getUsbDescString(const usb_str_desc_t *str_desc) 
{
  String str = "";
  if (str_desc == NULL) 
  {
    return str;
  }

  for (int i = 0; i < str_desc->bLength / 2; i++) 
  {
    if (str_desc->wData[i] > 0xFF) {
      continue;
    }
    str += char(str_desc->wData[i]);
  }
  return str;
}

void EspUsbHost::onConfig(const uint8_t bDescriptorType, const uint8_t *p) 
{
  switch (bDescriptorType) 
  {
    case USB_DEVICE_DESC:
      {
        ESP_LOGI("EspUsbHost", "USB_DEVICE_DESC(0x01)");
      }
      break;

    case USB_CONFIGURATION_DESC:
      {
      #if (ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_INFO)
        const usb_config_desc_t *config_desc = (const usb_config_desc_t *)p;
        ESP_LOGI("EspUsbHost", "USB_CONFIGURATION_DESC(0x02)\n"
                               "# bLength             = %d\n"
                               "# bDescriptorType     = %d\n"
                               "# wTotalLength        = %d\n"
                               "# bNumInterfaces      = %d\n"
                               "# bConfigurationValue = %d\n"
                               "# iConfiguration      = %d\n"
                               "# bmAttributes        = 0x%x\n"
                               "# bMaxPower           = %dmA",
                 config_desc->bLength,
                 config_desc->bDescriptorType,
                 config_desc->wTotalLength,
                 config_desc->bNumInterfaces,
                 config_desc->bConfigurationValue,
                 config_desc->iConfiguration,
                 config_desc->bmAttributes,
                 config_desc->bMaxPower * 2);
      #endif
      }
      break;

    case USB_STRING_DESC:
      {
      #if (ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_INFO)
        const usb_standard_desc_t *desc = (const usb_standard_desc_t *)p;
        String data_str = "";
        for (int i = 0; i < (desc->bLength - 2); i++) 
        {
          if (desc->val[i] < 16) {
            data_str += "0";
          }
          data_str += String(desc->val[i], HEX) + " ";
        }
        ESP_LOGI("EspUsbHost", "USB_STRING_DESC(0x03) bLength=%d, bDescriptorType=0x%x, data=[%s]",
                 desc->bLength,
                 desc->bDescriptorType,
                 data_str);
      #endif
      }
      break;

    case USB_INTERFACE_DESC:
      {
        const usb_intf_desc_t *intf = (const usb_intf_desc_t *)p;
        ESP_LOGI("EspUsbHost", "USB_INTERFACE_DESC(0x04)\n"
                               "# bLength            = %d\n"
                               "# bDescriptorType    = %d\n"
                               "# bInterfaceNumber   = %d\n"
                               "# bAlternateSetting  = %d\n"
                               "# bNumEndpoints      = %d\n"
                               "# bInterfaceClass    = 0x%x\n"
                               "# bInterfaceSubClass = 0x%x\n"
                               "# bInterfaceProtocol = 0x%x\n"
                               "# iInterface         = %d",
                 intf->bLength,
                 intf->bDescriptorType,
                 intf->bInterfaceNumber,
                 intf->bAlternateSetting,
                 intf->bNumEndpoints,
                 intf->bInterfaceClass,
                 intf->bInterfaceSubClass,
                 intf->bInterfaceProtocol,
                 intf->iInterface);

        this->claim_err = usb_host_interface_claim(this->clientHandle, this->deviceHandle, intf->bInterfaceNumber, intf->bAlternateSetting);
        if (this->claim_err != ESP_OK) 
        {
          ESP_LOGI("EspUsbHost", "usb_host_interface_claim() err=%x", claim_err);
        } 
        else 
        {
          ESP_LOGI("EspUsbHost", "usb_host_interface_claim() ESP_OK");
          this->usbInterface[this->usbInterfaceSize] = intf->bInterfaceNumber;
          this->usbInterfaceSize++;
          _bInterfaceClass = intf->bInterfaceClass;
          _bInterfaceSubClass = intf->bInterfaceSubClass;
          _bInterfaceProtocol = intf->bInterfaceProtocol;
        }
      }
      break;

    case USB_ENDPOINT_DESC:
      {
        const usb_ep_desc_t *ep_desc = (const usb_ep_desc_t *)p;
        ESP_LOGI("EspUsbHost", "USB_ENDPOINT_DESC(0x05)\n"
                               "# bLength          = %d\n"
                               "# bDescriptorType  = %d\n"
                               "# bEndpointAddress = 0x%x(EndpointID=%d, Direction=%s)\n"
                               "# bmAttributes     = 0x%x(%s)\n"
                               "# wMaxPacketSize   = %d\n"
                               "# bInterval        = %d",
                 ep_desc->bLength,
                 ep_desc->bDescriptorType,
                 ep_desc->bEndpointAddress, USB_EP_DESC_GET_EP_NUM(ep_desc), USB_EP_DESC_GET_EP_DIR(ep_desc) ? "IN" : "OUT",
                 ep_desc->bmAttributes,
                 (ep_desc->bmAttributes & USB_BM_ATTRIBUTES_XFERTYPE_MASK) == USB_BM_ATTRIBUTES_XFER_CONTROL ? "CTRL" : (ep_desc->bmAttributes & USB_BM_ATTRIBUTES_XFERTYPE_MASK) == USB_BM_ATTRIBUTES_XFER_ISOC ? "ISOC"
                                                                                                                      : (ep_desc->bmAttributes & USB_BM_ATTRIBUTES_XFERTYPE_MASK) == USB_BM_ATTRIBUTES_XFER_BULK ? "BULK"
                                                                                                                      : (ep_desc->bmAttributes & USB_BM_ATTRIBUTES_XFERTYPE_MASK) == USB_BM_ATTRIBUTES_XFER_INT  ? "Interrupt"
                                                                                                                                                                                                                 : "",
                 ep_desc->wMaxPacketSize,
                 ep_desc->bInterval);

        if (this->claim_err != ESP_OK) 
        {
          ESP_LOGI("EspUsbHost", "claim_err skip");
          return;
        }

        this->endpoint_data_list[USB_EP_DESC_GET_EP_NUM(ep_desc)].bInterfaceClass = _bInterfaceClass;
        this->endpoint_data_list[USB_EP_DESC_GET_EP_NUM(ep_desc)].bInterfaceSubClass = _bInterfaceSubClass;
        this->endpoint_data_list[USB_EP_DESC_GET_EP_NUM(ep_desc)].bInterfaceProtocol = _bInterfaceProtocol;
        this->endpoint_data_list[USB_EP_DESC_GET_EP_NUM(ep_desc)].bCountryCode = _bCountryCode;

        if ((ep_desc->bmAttributes & USB_BM_ATTRIBUTES_XFERTYPE_MASK) != USB_BM_ATTRIBUTES_XFER_INT) 
        {
          ESP_LOGI("EspUsbHost", "err ep_desc->bmAttributes=%x", ep_desc->bmAttributes);
          return;
        }

        if (ep_desc->bEndpointAddress & USB_B_ENDPOINT_ADDRESS_EP_DIR_MASK) 
        {
          esp_err_t err = usb_host_transfer_alloc(ep_desc->wMaxPacketSize + 1, 0, &this->usbTransfer[this->usbTransferSize]);
          if (err != ESP_OK) {
            this->usbTransfer[this->usbTransferSize] = NULL;
            ESP_LOGI("EspUsbHost", "usb_host_transfer_alloc() err=%x", err);
            return;
          } else {
            ESP_LOGI("EspUsbHost", "usb_host_transfer_alloc() ESP_OK data_buffer_size=%d", ep_desc->wMaxPacketSize + 1);
          }

          this->usbTransfer[this->usbTransferSize]->device_handle = this->deviceHandle;
          this->usbTransfer[this->usbTransferSize]->bEndpointAddress = ep_desc->bEndpointAddress;
          this->usbTransfer[this->usbTransferSize]->callback = this->_onReceive;
          this->usbTransfer[this->usbTransferSize]->context = this;
          this->usbTransfer[this->usbTransferSize]->num_bytes = ep_desc->wMaxPacketSize;
          interval = ep_desc->bInterval;
          isReady = true;
          this->usbTransferSize++;
        }
      }
      break;

    case USB_INTERFACE_ASSOC_DESC:
      {
      #if (ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_INFO)
        const usb_iad_desc_t *iad_desc = (const usb_iad_desc_t *)p;
        ESP_LOGI("EspUsbHost", "USB_INTERFACE_ASSOC_DESC(0x0b)\n"
                               "# bLength           = %d\n"
                               "# bDescriptorType   = %d\n"
                               "# bFirstInterface   = %d\n"
                               "# bInterfaceCount   = %d\n"
                               "# bFunctionClass    = 0x%x\n"
                               "# bFunctionSubClass = 0x%x\n"
                               "# bFunctionProtocol = 0x%x\n"
                               "# iFunction         = %d",
                 iad_desc->bLength,
                 iad_desc->bDescriptorType,
                 iad_desc->bFirstInterface,
                 iad_desc->bInterfaceCount,
                 iad_desc->bFunctionClass,
                 iad_desc->bFunctionSubClass,
                 iad_desc->bFunctionProtocol,
                 iad_desc->iFunction);
      #endif
      }
      break;

    case USB_HID_DESC:
      {
        const tusb_hid_descriptor_hid_t *hid_desc = (const tusb_hid_descriptor_hid_t *)p;
        ESP_LOGI("EspUsbHost", "USB_HID_DESC(0x21)\n"
                               "# bLength         = %d\n"
                               "# bDescriptorType = 0x%x\n"
                               "# bcdHID          = 0x%x\n"
                               "# bCountryCode    = 0x%x\n"
                               "# bNumDescriptors = %d\n"
                               "# bReportType     = 0x%x\n"
                               "# wReportLength   = %d",
                 hid_desc->bLength,
                 hid_desc->bDescriptorType,
                 hid_desc->bcdHID,
                 hid_desc->bCountryCode,
                 hid_desc->bNumDescriptors,
                 hid_desc->bReportType,
                 hid_desc->wReportLength);
        _bCountryCode = hid_desc->bCountryCode;

        submitControl(0x81, 0x00, 0x22, 0x0000, 136);
      }
      break;

    default:
      {
      #if (ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_INFO)
        const usb_standard_desc_t *desc = (const usb_standard_desc_t *)p;
        String data_str = "";
        for (int i = 0; i < (desc->bLength - 2); i++) 
        {
          if (desc->val[i] < 16) {
            data_str += "0";
          }
          data_str += String(desc->val[i], HEX) + " ";
        }
        ESP_LOGI("EspUsbHost", "USB_???_DESC(%02x) bLength=%d, bDescriptorType=0x%x, data=[%s]",
                 bDescriptorType,
                 desc->bLength,
                 desc->bDescriptorType,
                 data_str);
      #endif
      }
  }
}

void EspUsbHost::_onReceive(usb_transfer_t *transfer) 
{
  EspUsbHost *usbHost = (EspUsbHost *)transfer->context;
  endpoint_data_t *endpoint_data = &usbHost->endpoint_data_list[(transfer->bEndpointAddress & USB_B_ENDPOINT_ADDRESS_EP_NUM_MASK)];

#if (ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_VERBOSE)
  _printPcapText("URB_INTERRUPT in", 0x0009, 0x01, transfer->bEndpointAddress, 0x01, transfer->actual_num_bytes, 0xff, (const uint8_t *)transfer->data_buffer);

  String buffer_str = "";
  for (int i = 0; i < transfer->actual_num_bytes; i++) {
    if (transfer->data_buffer[i] < 16) {
      buffer_str += "0";
    }
    buffer_str += String(transfer->data_buffer[i], HEX) + " ";
  }
  buffer_str.trim();
  ESP_LOGV("EspUsbHost", "transfer\n"
                         "# bInterfaceClass    = 0x%x\n"
                         "# bInterfaceSubClass = 0x%x\n"
                         "# bInterfaceProtocol = 0x%x\n"
                         "# bCountryCode       = 0x%x > usb_transfer_t data_buffer=[%s]\n"
                         "# data_buffer_size   = %d\n"
                         "# num_bytes          = %d\n"
                         "# actual_num_bytes   = %d\n"
                         "# flags              = 0x%x\n"
                         "# bEndpointAddress   = 0x%x\n"
                         "# timeout_ms         = %d\n"
                         "# num_isoc_packets   = %d",
           endpoint_data->bInterfaceClass,
           endpoint_data->bInterfaceSubClass,
           endpoint_data->bInterfaceProtocol,
           endpoint_data->bCountryCode,
           buffer_str.c_str(),
           transfer->data_buffer_size,
           transfer->num_bytes,
           transfer->actual_num_bytes,
           transfer->flags,
           transfer->bEndpointAddress,
           transfer->timeout_ms,
           transfer->num_isoc_packets);
#endif

  if (endpoint_data->bInterfaceClass == USB_CLASS_HID)
  {
    if (endpoint_data->bInterfaceSubClass == HID_SUBCLASS_BOOT)
    {
      if (endpoint_data->bInterfaceProtocol == HID_ITF_PROTOCOL_KEYBOARD)
      {
        //static bool lastWin = false; // Used to respond to the Win key remembering when it was pressed 
        static hid_keyboard_report_t last_report = {};

        // if (transfer->data_buffer[2] == HID_KEY_NUM_LOCK)
        // {
        //   // HID_KEY_NUM_LOCK TODO!  //Not sure but I suspect you have to send a cmd to the keyboard to enable / disable the keypad and to set the led?
        // } 
        //else 

        if (memcmp(&last_report, transfer->data_buffer, sizeof(last_report)))
        {
          // Get the report data from the buffer
          hid_keyboard_report_t report = {};
          report.modifier = transfer->data_buffer[0];
          report.reserved = transfer->data_buffer[1];
          report.keycode[0] = transfer->data_buffer[2];
          report.keycode[1] = transfer->data_buffer[3];
          report.keycode[2] = transfer->data_buffer[4];
          report.keycode[3] = transfer->data_buffer[5];
          report.keycode[4] = transfer->data_buffer[6];
          report.keycode[5] = transfer->data_buffer[7];
          /// onKeyboard sends lower level reports for processing; remember that the keyboard will generate a report when 
          /// scanned by the host if there was any change since the last report including modifier keys like Ctrl, Shift, 
          /// Alt, and Win.  If you want just the raw keyboard reports you can use the onReceive callback instead.
          /// The last report is included so it can be determined what changed exactly, like you would not want to
          /// duplicate a key in some circumstances.  The onKeyboardKey callback processes the report and outputs for each keycode
          /// included in the report.
          hid_key_modifier keyModifier;
          decodeModifiers(report.modifier, keyModifier);
          #ifdef RAW_REPORT
          usbHost->onKeyboard(report, last_report, keyModifier);
          #endif
          #ifdef KEY_REPORT
          // This loop will examine each of the 6 key codes and if they changed the key code will be reported
          for (int i = 0; i < 6; i++)
          {
            if (report.keycode[i] != 0 && last_report.keycode[i] == 0)
            {
              // Send key press info on, if the WIN key is down it will be reported as a modifier...
              usbHost->onKeyboardKey(usbHost->getKeycodeToAscii(report.keycode[i], shift), report.keycode[i], keyModifier);
            }
          }
          #endif
          memcpy(&last_report, &report, sizeof(last_report)); //Save the report for comparision next time round...
        }
      } 
      else if (endpoint_data->bInterfaceProtocol == HID_ITF_PROTOCOL_MOUSE)
      {
        static uint8_t last_buttons = 0;
        hid_mouse_report_t report = {};
        report.buttons = transfer->data_buffer[1];
        report.x = (uint8_t)transfer->data_buffer[2];
        report.y = (uint8_t)transfer->data_buffer[4];
        report.wheel = (uint8_t)transfer->data_buffer[6];
        usbHost->onMouse(report, last_buttons);
        if (report.buttons != last_buttons) {
          usbHost->onMouseButtons(report, last_buttons);
          last_buttons = report.buttons;
        }
        if (report.x != 0 || report.y != 0 || report.wheel != 0)
        {
          usbHost->onMouseMove(report);
        }
      }
    } 
    else 
    {
      //usbHost->_onReceiveGamepad();
    }
  }
  usbHost->onReceive(transfer);
}

void EspUsbHost::onMouse(hid_mouse_report_t report, uint8_t last_buttons) {
  ESP_LOGD("EspUsbHost", "last_buttons=0x%02x(%c%c%c%c%c), buttons=0x%02x(%c%c%c%c%c), x=%d, y=%d, wheel=%d",
           last_buttons,
           (last_buttons & MOUSE_BUTTON_LEFT) ? 'L' : ' ',
           (last_buttons & MOUSE_BUTTON_RIGHT) ? 'R' : ' ',
           (last_buttons & MOUSE_BUTTON_MIDDLE) ? 'M' : ' ',
           (last_buttons & MOUSE_BUTTON_BACKWARD) ? 'B' : ' ',
           (last_buttons & MOUSE_BUTTON_FORWARD) ? 'F' : ' ',
           report.buttons,
           (report.buttons & MOUSE_BUTTON_LEFT) ? 'L' : ' ',
           (report.buttons & MOUSE_BUTTON_RIGHT) ? 'R' : ' ',
           (report.buttons & MOUSE_BUTTON_MIDDLE) ? 'M' : ' ',
           (report.buttons & MOUSE_BUTTON_BACKWARD) ? 'B' : ' ',
           (report.buttons & MOUSE_BUTTON_FORWARD) ? 'F' : ' ',
           report.x,
           report.y,
           report.wheel);
}

void EspUsbHost::onMouseButtons(hid_mouse_report_t report, uint8_t last_buttons) {
  ESP_LOGD("EspUsbHost", "last_buttons=0x%02x(%c%c%c%c%c), buttons=0x%02x(%c%c%c%c%c), x=%d, y=%d, wheel=%d",
           last_buttons,
           (last_buttons & MOUSE_BUTTON_LEFT) ? 'L' : ' ',
           (last_buttons & MOUSE_BUTTON_RIGHT) ? 'R' : ' ',
           (last_buttons & MOUSE_BUTTON_MIDDLE) ? 'M' : ' ',
           (last_buttons & MOUSE_BUTTON_BACKWARD) ? 'B' : ' ',
           (last_buttons & MOUSE_BUTTON_FORWARD) ? 'F' : ' ',
           report.buttons,
           (report.buttons & MOUSE_BUTTON_LEFT) ? 'L' : ' ',
           (report.buttons & MOUSE_BUTTON_RIGHT) ? 'R' : ' ',
           (report.buttons & MOUSE_BUTTON_MIDDLE) ? 'M' : ' ',
           (report.buttons & MOUSE_BUTTON_BACKWARD) ? 'B' : ' ',
           (report.buttons & MOUSE_BUTTON_FORWARD) ? 'F' : ' ',
           report.x,
           report.y,
           report.wheel);

  // LEFT
  if (!(last_buttons & MOUSE_BUTTON_LEFT) && (report.buttons & MOUSE_BUTTON_LEFT)) {
    ESP_LOGI("EspUsbHost", "Mouse LEFT Click");
  }
  if ((last_buttons & MOUSE_BUTTON_LEFT) && !(report.buttons & MOUSE_BUTTON_LEFT)) {
    ESP_LOGI("EspUsbHost", "Mouse LEFT Release");
  }

  // RIGHT
  if (!(last_buttons & MOUSE_BUTTON_RIGHT) && (report.buttons & MOUSE_BUTTON_RIGHT)) {
    ESP_LOGI("EspUsbHost", "Mouse RIGHT Click");
  }
  if ((last_buttons & MOUSE_BUTTON_RIGHT) && !(report.buttons & MOUSE_BUTTON_RIGHT)) {
    ESP_LOGI("EspUsbHost", "Mouse RIGHT Release");
  }

  // MIDDLE
  if (!(last_buttons & MOUSE_BUTTON_MIDDLE) && (report.buttons & MOUSE_BUTTON_MIDDLE)) {
    ESP_LOGI("EspUsbHost", "Mouse MIDDLE Click");
  }
  if ((last_buttons & MOUSE_BUTTON_MIDDLE) && !(report.buttons & MOUSE_BUTTON_MIDDLE)) {
    ESP_LOGI("EspUsbHost", "Mouse MIDDLE Release");
  }

  // BACKWARD
  if (!(last_buttons & MOUSE_BUTTON_BACKWARD) && (report.buttons & MOUSE_BUTTON_BACKWARD)) {
    ESP_LOGI("EspUsbHost", "Mouse BACKWARD Click");
  }
  if ((last_buttons & MOUSE_BUTTON_BACKWARD) && !(report.buttons & MOUSE_BUTTON_BACKWARD)) {
    ESP_LOGI("EspUsbHost", "Mouse BACKWARD Release");
  }

  // FORWARD
  if (!(last_buttons & MOUSE_BUTTON_FORWARD) && (report.buttons & MOUSE_BUTTON_FORWARD)) {
    ESP_LOGI("EspUsbHost", "Mouse FORWARD Click");
  }
  if ((last_buttons & MOUSE_BUTTON_FORWARD) && !(report.buttons & MOUSE_BUTTON_FORWARD)) {
    ESP_LOGI("EspUsbHost", "Mouse FORWARD Release");
  }
}

void EspUsbHost::onMouseMove(hid_mouse_report_t report) {
  ESP_LOGD("EspUsbHost", "buttons=0x%02x(%c%c%c%c%c), x=%d, y=%d, wheel=%d",
           report.buttons,
           (report.buttons & MOUSE_BUTTON_LEFT) ? 'L' : ' ',
           (report.buttons & MOUSE_BUTTON_RIGHT) ? 'R' : ' ',
           (report.buttons & MOUSE_BUTTON_MIDDLE) ? 'M' : ' ',
           (report.buttons & MOUSE_BUTTON_BACKWARD) ? 'B' : ' ',
           (report.buttons & MOUSE_BUTTON_FORWARD) ? 'F' : ' ',
           report.x,
           report.y,
           report.wheel);
}

void EspUsbHost::onKeyboard(hid_keyboard_report_t report, hid_keyboard_report_t last_report, hid_key_modifier key_modifier)
{
  ESP_LOGD("EspUsbHost", "modifier=[0x%02x]->[0x%02x], Key0=[0x%02x]->[0x%02x], Key1=[0x%02x]->[0x%02x], Key2=[0x%02x]->[0x%02x], Key3=[0x%02x]->[0x%02x], Key4=[0x%02x]->[0x%02x], Key5=[0x%02x]->[0x%02x]",
           last_report.modifier,
           report.modifier,
           last_report.keycode[0],
           report.keycode[0],
           last_report.keycode[1],
           report.keycode[1],
           last_report.keycode[2],
           report.keycode[2],
           last_report.keycode[3],
           report.keycode[3],
           last_report.keycode[4],
           report.keycode[4],
           last_report.keycode[5],
           report.keycode[5]);
}

uint8_t EspUsbHost::getKeycodeToAscii(uint8_t keycode, uint8_t shift) {
  static uint8_t const keyboard_conv_table[128][2] = { HID_KEYCODE_TO_ASCII };

  if (shift > 1) shift = 1;
  return keyboard_conv_table[keycode][shift];
}

void EspUsbHost::onKeyboardKey(uint8_t ascii, uint8_t keycode, hid_key_modifier modifier) {
  if (' ' <= ascii && ascii <= '~')
  {
    // printable
    ESP_LOGV("EspUsbHost", "Keyboard Type=0x%02x(%c), keycode=0x%02x, modifier=0x%02x",
             ascii,
             ascii,
             keycode,
             modifier.keyModifier);
  } else {
    ESP_LOGV("EspUsbHost", "Keyboard Type=0x%02x, keycode=0x%02x, modifier=0x%02x",
             ascii,
             keycode,
             modifier.keyModifier);
  }
}

void EspUsbHost::setHIDLocal(hid_local_enum_t code) {
  hidLocal = code;
}

esp_err_t EspUsbHost::submitControl(const uint8_t bmRequestType, const uint8_t bDescriptorIndex, const uint8_t bDescriptorType, const uint16_t wInterfaceNumber, const uint16_t wDescriptorLength) {
  usb_transfer_t *transfer;
  usb_host_transfer_alloc(wDescriptorLength + 9, 0, &transfer);

  transfer->num_bytes = wDescriptorLength + 8;
  transfer->data_buffer[0] = bmRequestType;
  transfer->data_buffer[1] = 0x06;
  transfer->data_buffer[2] = bDescriptorIndex;
  transfer->data_buffer[3] = bDescriptorType;
  transfer->data_buffer[4] = wInterfaceNumber & 0xff;
  transfer->data_buffer[5] = wInterfaceNumber >> 8;
  transfer->data_buffer[6] = wDescriptorLength & 0xff;
  transfer->data_buffer[7] = wDescriptorLength >> 8;

  transfer->device_handle = deviceHandle;
  transfer->bEndpointAddress = 0x00;
  transfer->callback = _onReceiveControl;
  transfer->context = this;

  //submitControl(0x81, 0x00, 0x22, 0x0000, 136);
  if (bmRequestType == 0x81 && bDescriptorIndex == 0x00 && bDescriptorType == 0x22) {
    _printPcapText("GET DESCRIPTOR Request HID Report", 0x0028, 0x00, 0x80, 0x02, 8, 0, transfer->data_buffer);
  }

  esp_err_t err = usb_host_transfer_submit_control(clientHandle, transfer);
  if (err != ESP_OK) {
    ESP_LOGI("EspUsbHost", "usb_host_transfer_submit_control() err=%x", err);
  }
  return err;
}

void EspUsbHost::_onReceiveControl(usb_transfer_t *transfer) {
  EspUsbHost *usbHost = (EspUsbHost *)transfer->context;

  _printPcapText("GET DESCRIPTOR Response HID Report", 0x0008, 0x01, 0x80, 0x02, transfer->actual_num_bytes - 8, 0x03, &transfer->data_buffer[8]);

  ESP_LOGV("EspUsbHost", "_onReceiveControl()\n"
                         "# data_buffer_size   = %d\n"
                         "# num_bytes          = %d\n"
                         "# actual_num_bytes   = %d\n"
                         "# flags              = 0x%x\n"
                         "# bEndpointAddress   = 0x%x\n"
                         "# timeout_ms         = %d\n"
                         "# num_isoc_packets   = %d",
           transfer->data_buffer_size,
           transfer->num_bytes,
           transfer->actual_num_bytes,
           transfer->flags,
           transfer->bEndpointAddress,
           transfer->timeout_ms,
           transfer->num_isoc_packets);

  usb_host_transfer_free(transfer);
}