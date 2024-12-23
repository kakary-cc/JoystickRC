#define AIL 0
#define ELE 1
#define THR 2
#define RUD 3

// Debug toggle: Set to 1 to enable debug output, 0 to disable
#define DEBUG 0

#include "PPMEncoder.h"
#include "JoystickParser.h"

const uint8_t ppmPin = 7;

const uint16_t MIN = PPMEncoder::MIN;
const uint16_t MAX = PPMEncoder::MAX;
const uint16_t MID = (MIN + MAX) / 2;

USB Usb;
HIDUniversal Hid(&Usb);
JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

void GamePadHandler(const GamePadEventData* evt) {
  ppmEncoder.setChannel(AIL, map(evt->x, 0, 16383, MIN, MAX));
  ppmEncoder.setChannel(ELE, map(evt->y, 16383, 0, MIN, MAX));
  ppmEncoder.setChannel(THR, map(evt->slider, 255, 0, MIN, MAX));
  ppmEncoder.setChannel(RUD, map(evt->twist, 0, 255, MIN, MAX));
}

void setup() {
#if DEBUG
  JoyEvents.enableDebug();
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial)
    ;  // Wait for Serial connection
#endif
  Serial.println("Program Start");
  if (Usb.Init() == -1) {
    Serial.println("USB Initialization failed.");
  }
  if (!Hid.SetReportParser(0, &Joy)) {
    Serial.println("Failed to set report parser.");
  }
#else
  Usb.Init();
  Hid.SetReportParser(0, &Joy);
#endif
  ppmEncoder.begin(ppmPin, 8);
  ppmEncoder.setChannel(AIL, MID);
  ppmEncoder.setChannel(ELE, MID);
  ppmEncoder.setChannel(THR, MIN);
  ppmEncoder.setChannel(RUD, MID);
  JoyEvents.setCallback(GamePadHandler);
}

void loop() {
  Usb.Task();
}
