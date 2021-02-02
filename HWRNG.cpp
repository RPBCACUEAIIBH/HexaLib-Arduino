#include "HWRNG.h"


#ifdef AVR

unsigned long HWRandom(void)
{
  // 32 sample of LSB from internal temperature sensor. (only for Atmega 168A/P 328 and 32u4)
  unsigned long X = 0;
  while (X == 0x0 || X == 0xFFFFFFFF)
    for (byte i = 0; i < 32; i++)
    {
      ADMUX |= 0xC8; // Set the internal reference and mux.
      ADCSRA |= 0xC0;  // Enable the ADC and start conversion
      while (bitRead(ADCSRA,ADSC)); // Detect end-of-conversion
      bitWrite (X, i, bitRead (ADCW, 0));
    }
  return X - 1;
}

unsigned long HWRandom(unsigned long Max)
{
  // 32 sample of LSB from internal temperature sensor. (only for Atmega 168A/P 328 and 32u4)
  unsigned long X = 0;
  while (X == 0x0 || X == 0xFFFFFFFF)
    for (byte i = 0; i < 32; i++)
    {
      ADMUX |= 0xC8; // Set the internal reference and mux.
      ADCSRA |= 0xC0;  // Enable the ADC and start conversion
      while (bitRead(ADCSRA,ADSC)); // Detect end-of-conversion
      bitWrite (X, i, bitRead (ADCW, 0));
    }
  return (X - 1) % Max;
}

unsigned long HWRandom(unsigned long Min, unsigned long Max)
{
  // 32 sample of LSB from internal temperature sensor. (only for Atmega 168A/P 328 and 32u4)
  unsigned long X = 0;
  while (X == 0x0 || X == 0xFFFFFFFF)
    for (byte i = 0; i < 32; i++)
    {
      ADMUX |= 0xC8; // Set the internal reference and mux.
      ADCSRA |= 0xC0;  // Enable the ADC and start conversion
      while (bitRead(ADCSRA,ADSC)); // Detect end-of-conversion
      bitWrite (X, i, bitRead (ADCW, 0));
    }
  return (X - 1) % (Max - Min) + Min;
}

#endif
