#ifndef InternalTemp_H
#define InternalTemp_H

#include <Arduino.h>

// Reads the internal temperature sensor and returns temperature in °C. Works, but "not accurate" is an understatement... (±10°C Accuracy, and somewhat less then 2°C resolution...)
// Only available on Atmega 168A/P, 328/P/Pb, 32U4 chips.
static float Offset = 355.7;
static float Devider = 0.571;

void InternalTemp(float offset, float devider);
float InternalTemp();

#endif
