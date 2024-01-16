/******************************************************************
 This code was based on code found on GitHub at: 
 https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 Edited by Ed Paay @ Tech-Relief LLC
 The code is used with an ESP32-S3 board such as the Seeed Studio
 Xiao ESP32-S3 or the Espressif ESP32-S3-USB-OTG board.
 However, this code may well work with other boards or board types.
*******************************************************************/
#include <arduino.h>
#include "BLEDevice.h"
#include "BLEHIDDevice.h"
#include "HIDTypes.h"
#include "HIDKeyboardTypes.h"
#include <class/hid/hid.h>

#define DEVICE_NAME "Xiao-KBD"
#define US_KEYBOARD
#define KEY_SYSRQ 0x46 // Keyboard Print Screen
#define KEY_SCROLLLOCK 0x47 // Keyboard Scroll Lock
#define KEY_PAUSE 0x48 // Keyboard Pause
#define KEY_INSERT 0x49 // Keyboard Insert
#define KEY_HOME 0x4a // Keyboard Home
#define KEY_PAGEUP 0x4b // Keyboard Page Up
#define KEY_DELETE 0x4c // Keyboard Delete Forward
#define KEY_END 0x4d // Keyboard End
#define KEY_PAGEDOWN 0x4e // Keyboard Page Down
#define KEY_RIGHT 0x4f // Keyboard Right Arrow
#define KEY_LEFT 0x50 // Keyboard Left Arrow
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_UP 0x52 // Keyboard Up Arrow

// Message (report) received when an LED's state changed
typedef struct TU_ATTR_PACKED
{
  uint8_t leds; // bitmask: num lock = 1, caps lock = 2, scroll lock = 4, compose = 8, kana = 16
} hid_keyboard_output_report_t;

/// @brief The Modifier struct is used to store key modifier information.
struct hid_key_modifier
{
  uint8_t modbyte; //The decoded modifier byte.
  bool shift; //True if Shift is set.
  bool ctrl; //True if Ctrl is set.
  bool alt; //True if Alt is set.
  bool win; //True if Win is set.
};

bool numLockIsOn();
bool capsLockIsOn();
bool scrollLockIsOn();

//void updateLeds();

/// @brief True if the Bluetooth Connection was made by a host.
bool bleIsConnected();

/// @brief Used to initialize and setup the required components of the Bluetooth HID connection.
void bluetoothTask(void *);

/// @brief Send a control key code like Ctrl C etc.
/// @param key The control key code to send.
void sendCtrlKey(char key);

/// @brief Send the text characters to the host via Bluetooth HID connection
/// @param text The text characters to send.
void typeText(const char *text);

/// @brief Sends a keyboard report with modifiers and up to 6 keycodes
/// @param report Struct contains Modifiers and HID Keycodes
void sendInputReport(hid_keyboard_report_t report);

/// @brief Similar to sendInputReport, sends a report with Modifiers and up to 6 keycodes. However it also sends the key up report.
/// @param report Struct contains Modifiers and HID Keycodes
void sendReport(hid_keyboard_report_t report);

/// @brief Send a key code to the host directly.  See HIDKeyboardTypes.h for available key codes.
/// @param keyCode The keycode to send.
void sendKeyCode(uint8_t keyCode);

