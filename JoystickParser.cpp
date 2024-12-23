/*
 * This code is adapted from the Simplified Thrustmaster T.16000M FCS Joystick Report
 * Parser originally developed by gdsports:
 * https://github.com/felis/USB_Host_Shield_2.0/tree/master/examples/HID/t16km
 * 
 * All rights to the original implementation belong to its creator.
 */

#include "JoystickParser.h"

JoystickReportParser::JoystickReportParser(JoystickEvents* evt)
  : joyEvents(evt) {}

void JoystickReportParser::Parse(USBHID* hid, bool is_rpt_id, uint8_t len, uint8_t* buf) {
  // Check for changes in joystick state
  bool match = (sizeof(oldPad) == len) && (memcmp(oldPad, buf, len) == 0);

  // Call the event handler if state has changed
  if (!match && joyEvents) {
    joyEvents->OnGamePadChanged((const GamePadEventData*)buf);
    memcpy(oldPad, buf, len);
  }
}

const uint8_t* JoystickReportParser::getPad() const {
  return oldPad;
}

// Event handler implementation
void JoystickEvents::OnGamePadChanged(const GamePadEventData* evt) {
  if (callback) {
    callback(evt);
  }
  if (debug) {
    Serial.print("X: ");
    Serial.print(evt->x);
    Serial.print(" Y: ");
    Serial.print(evt->y);
    Serial.print(" Hat: ");
    Serial.print(evt->hat);
    Serial.print(" Twist: ");
    Serial.print(evt->twist);
    Serial.print(" Slider: ");
    Serial.print(evt->slider);
    Serial.print(" Buttons: ");
    Serial.println(evt->buttons, BIN);
  }
}
