/*
 * This code is adapted from the PPMEncoder library originally developed by schinken:
 * https://github.com/schinken/PPMEncoder
 * 
 * All rights to the original implementation belong to its creator.
 */

#ifndef PPMENCODER_H
#define PPMENCODER_H

#include "Arduino.h"

#define PPM_DEFAULT_CHANNELS 8

#define PPM_PULSE_LENGTH_uS 500
#define PPM_FRAME_LENGTH_uS 22500

class PPMEncoder {

private:
  int16_t channels[10];
  uint16_t elapsedUs;

  uint8_t numChannels;
  uint8_t currentChannel;
  byte outputPin;
  boolean state;
  boolean enabled;

  uint8_t onState;
  uint8_t offState;


public:
  static const uint16_t MIN = 900;
  static const uint16_t MAX = 2100;

  void setChannel(uint8_t channel, uint16_t value);
  void setChannelPercent(uint8_t channel, uint8_t percent);

  void begin(uint8_t pin);
  void begin(uint8_t pin, uint8_t ch);
  void begin(uint8_t pin, uint8_t ch, boolean inverted);

  void disable();
  void enable();

  void interrupt();
};

extern PPMEncoder ppmEncoder;

#endif
