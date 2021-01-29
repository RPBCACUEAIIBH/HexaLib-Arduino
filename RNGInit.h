#ifndef RNGInit_H
#define RNGInit_H

#include <Arduino.h>
#include <EEPROM.h>
#include "HexaLog.h"
#include "HexaLib.h" // LibLogSect is defined here for all members...

// This primes randomSeed() with a saved random value at boot. This may fail if the EEPROM, is cleared or broken.
// Works for AVR, and ESP8266

void RNGInit (unsigned int EEPROMAddress);

#endif
