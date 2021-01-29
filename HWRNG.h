#ifndef HWRNG_H
#define HWRNG_H

#include <Arduino.h>

// Generates random numbers reading the LSB of the internal temperature sensor 32+ times. It is way faster but may be less random then the Entropy library. It's range is 0x0 to 0xFFFFFFD
// Only works for Atmega 168A/P, 328/P/Pb, 32U4 chips.

unsigned long HWRandom();
unsigned long HWRandom(unsigned long Max);
unsigned long HWRandom(unsigned long Min, unsigned long Max);

#endif
