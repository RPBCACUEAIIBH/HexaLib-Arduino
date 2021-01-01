#ifndef RNGInit_H
#define RNGInit_H

#include <Arduino.h>
#include <EEPROM.h>
#include "HexaLog.h"
#include "HexaLib.h" // LibLogSect is defined here for all members...

void RNGInit (unsigned int EEPROMAddress);

#endif
