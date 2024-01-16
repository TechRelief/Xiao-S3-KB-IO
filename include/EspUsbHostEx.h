/*
This code is based on code downloaded from https://github.com/tanakamasayuki/EspUsbHost and edited by Ed Paay 
from Tech-Relief LLC.  The original did not handle modifiers such as CTRL, ALT or WIN etc.
*/
#ifndef __EspUsbHost_H__
#define __EspUsbHost_H__

#include <Arduino.h>
#include <usb/usb_host.h>
#include <class/hid/hid.h>
#include <rom/usb/usb_common.h>
#include "BleHidKb.h"

#define SHIFT_MASK 0x01 //Bitmasks used to signify various control keys
#define ALT_MASK 0x02
#define CTRL_MASK 0x04
#define WIN_MASK 0x08 //4JAN24 - TR Added support for WIN keys
#define RAW_REPORT //Enable sending the raw report as received from the keyboard
//#define KEY_REPORT //Enable sending the current and last reports received from the keyboard including the ASCII value

/// @brief Used to check if the modifier has the Shift bit set
/// @param modifier 
/// @return Returns true if Shift bit is set
bool hasShift(uint8_t modifier);

/// @brief Used to check if the modifier has the Alt bit set
/// @param modifier 
/// @return Returns true if Alt bit is set
bool hasAlt(uint8_t modifier);

/// @brief Used to check if the modifier has the Ctrl bit set
/// @param modifier 
/// @return Returns true if Ctrl bit is set
bool hasCtrl(uint8_t modifier);

/// @brief Used to check if the modifier has the Win bit set
/// @param modifier 
/// @return Returns true if Win bit is set
bool hasWin(uint8_t modifier); //4JAN24 - TR Added support for WIN keys

/// @brief Translates a HID keycode and outputs a human readable key name like "F1" etc.
/// @param hidCode Keycode to translate.
/// @return Key name as a string.
String XlatHidCode(uint8_t hidCode);

/// @brief Decode the modifier byte returned by a keyboard transfer report.  
/// @param modifier The modifier byte to decode.
/// @param keyModifier The decoded modifier structure.
void decodeModifiers(uint8_t modifier, hid_key_modifier& keyModifier);

/// @brief The main USB HOST class used to administer and control the USB Host port.
class EspUsbHost
{
public:
  bool isReady = false;
  uint8_t interval;
  unsigned long lastCheck;

  struct endpoint_data_t
  {
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint8_t bCountryCode;    
  };
  endpoint_data_t endpoint_data_list[17];
  uint8_t _bInterfaceClass;
  uint8_t _bInterfaceSubClass;
  uint8_t _bInterfaceProtocol;
  uint8_t _bCountryCode;
  esp_err_t claim_err;

  usb_host_client_handle_t clientHandle;
  usb_device_handle_t deviceHandle;
  uint32_t eventFlags;
  usb_transfer_t *usbTransfer[16];
  uint8_t usbTransferSize;
  uint8_t usbInterface[16];
  uint8_t usbInterfaceSize;

  hid_local_enum_t hidLocal;

  void begin(void);
  void task(void);

  static void _clientEventCallback(const usb_host_client_event_msg_t *eventMsg, void *arg);
  void _configCallback(const usb_config_desc_t *config_desc);
  void onConfig(const uint8_t bDescriptorType, const uint8_t *p);
  static String getUsbDescString(const usb_str_desc_t *str_desc);
  static void _onReceive(usb_transfer_t *transfer);

  static void _printPcapText(const char* title, uint16_t function, uint8_t direction, uint8_t endpoint, uint8_t type, uint8_t size, uint8_t stage, const uint8_t *data);
  esp_err_t submitControl(const uint8_t bmRequestType, const uint8_t bDescriptorIndex, const uint8_t bDescriptorType, const uint16_t wInterfaceNumber, const uint16_t wDescriptorLength);
  static void _onReceiveControl(usb_transfer_t *transfer);

  virtual void onReceive(const usb_transfer_t *transfer){};
  virtual void onGone(const usb_host_client_event_msg_t *eventMsg){};

  /// @brief Takes the HID keycode and the modifiers such as SHIFT and returns the relevant ASCII code.
  /// @param keycode The HID key scan code
  /// @param shift The key code modifier, only Shift is used.
  /// @return The ASCII code
  virtual uint8_t getKeycodeToAscii(uint8_t keycode, uint8_t shift);
  virtual void onKeyboard(hid_keyboard_report_t report, hid_keyboard_report_t last_report, hid_key_modifier key_modifier);
  virtual void onKeyboardKey(uint8_t ascii, uint8_t keycode, hid_key_modifier modifier);

  virtual void onMouse(hid_mouse_report_t report, uint8_t last_buttons);
  virtual void onMouseButtons(hid_mouse_report_t report, uint8_t last_buttons);
  virtual void onMouseMove(hid_mouse_report_t report);

  // void _onDataGamepad();

  void setHIDLocal(hid_local_enum_t code);
};


#endif
