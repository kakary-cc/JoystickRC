/*
 * This code is adapted from the Simplified Thrustmaster T.16000M FCS Joystick Report
 * Parser originally developed by gdsports:
 * https://github.com/felis/USB_Host_Shield_2.0/tree/master/examples/HID/t16km
 * 
 * All rights to the original implementation belong to its creator.
 */

#ifndef JOYSTICKPARSER_H
#define JOYSTICKPARSER_H

#define VID 0x044F
#define PID 0xB10A

#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>
#include <SPI.h>

struct GamePadEventData {
  uint16_t buttons;  // Buttons state (16 bits)
  uint8_t hat;       // Hat switch (8 bits)
  uint16_t x;        // X-axis
  uint16_t y;        // Y-axis
  uint8_t twist;     // Twist (rotation)
  uint8_t slider;    // Slider
} __attribute__((packed));

class JoystickEvents {
  bool debug = false;
  void (*callback)(const GamePadEventData*) = nullptr;

public:
  void enableDebug() {
    debug = true;
  }
  void OnGamePadChanged(const GamePadEventData* evt);  // Event callback
  void setCallback(void (*cb)(const GamePadEventData*)) {
    callback = cb;
  }
};

// Joystick report parser class
class JoystickReportParser : public HIDReportParser {
  JoystickEvents* joyEvents;
  uint8_t oldPad[sizeof(GamePadEventData)];  // Previous state for comparison

public:
  JoystickReportParser(JoystickEvents* evt);
  void Parse(USBHID* hid, bool is_rpt_id, uint8_t len, uint8_t* buf);
  const uint8_t* getPad() const;
};

#endif
