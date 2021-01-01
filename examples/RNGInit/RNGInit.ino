#include <HexaLib.h>

#ifdef AVR

void setup ()
{
  // ATMEGAs
  Serial.begin (115200);
  RNGInit (0); // This does not use an analog reading for random seed, but writes a random number (unsigned long) in EEPROM, and uses it as a seed at next boot. Make sure to Only call it once in the Setup!
  Serial.println (random ());
  // Now Press reset... The random number should be different as it should start with a different seed...
}

#elif ESP8266

void setup()
{
  // ESP8266
  EEPROM.begin (4096);
  Serial.begin (115200);
  Serial.println ();
  Serial.println ();
  RNGInit (); // This does not use an analog reading for random seed, but writes a random number (unsigned long) in EEPROM, and uses it as a seed at next boot. Make sure to Only call it once in the Setup!
  Serial.println (rand ());
  // Now Press reset... The random number should be different as it should start with a different seed...
}

#endif

void loop()
{}
