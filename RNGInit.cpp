#include "RNGInit.h"

#ifdef AVR
void RNGInit (unsigned int EEPROMAddress)
{
  Log ("Initializing RNG...", 3, LibLogSect);
  // Load seed
  unsigned long Seed;
  Seed = EEPROM.read (EEPROMAddress) << 24;
  Seed += EEPROM.read (EEPROMAddress + 1) << 16;
  Seed += EEPROM.read (EEPROMAddress + 2) << 8;
  Seed += EEPROM.read (EEPROMAddress + 3);
  randomSeed (Seed);
  String X = F ("Random seed: ");
  X += String (Seed);
  Log (X, 4, LibLogSect);
  byte Y = Seed % 256;
  for (byte i = 0; i < Y; i++)
    Seed = random ();
  // Save Random seed
  EEPROM.write (EEPROMAddress, Seed >> 24);
  EEPROM.write (EEPROMAddress + 1, Seed >> 16);
  EEPROM.write (EEPROMAddress + 2, Seed >> 8);
  EEPROM.write (EEPROMAddress + 3, Seed);
  Log ("", 4, LibLogSect);
}
#elif ESP8266
void RNGInit (unsigned int EEPROMAddress)
{
  Log ("Initializing RNG...", 3, LibLogSect);
  // Load seed
  unsigned long Seed;
  Seed = EEPROM.read (EEPROMAddress) << 24;
  Seed += EEPROM.read (EEPROMAddress + 1) << 16;
  Seed += EEPROM.read (EEPROMAddress + 2) << 8;
  Seed += EEPROM.read (EEPROMAddress + 3);
  randomSeed (Seed);
  String X = F ("Seed: ");
  X += String (Seed);
  Log (X, 4, LibLogSect);
  byte Y = Seed % 256;
  for (byte i = 0; i < Y; i++)
    Seed = rand ();
  // Save Random seed
  EEPROM.write (EEPROMAddress, Seed >> 24);
  EEPROM.write (EEPROMAddress + 1, Seed >> 16);
  EEPROM.write (EEPROMAddress + 2, Seed >> 8);
  EEPROM.write (EEPROMAddress + 3, Seed);
  EEPROM.commit ();
  Log ("", 4, LibLogSect);
}
#endif
