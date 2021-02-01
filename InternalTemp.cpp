#include "InternalTemp.h"

float InternalTemp()
{
  ADMUX |= 0xC8; // Set the internal reference and mux.
  ADCSRA |= 0xC0;  // Enable the ADC and start conversion
  while (bitRead(ADCSRA,ADSC)); // Detect end-of-conversion
  return (float (ADCW) - Offset) / Devider;
}

void InternalTemp(float offset, float devider)
{
  Offset = offset;
  Devider = devider;
}
