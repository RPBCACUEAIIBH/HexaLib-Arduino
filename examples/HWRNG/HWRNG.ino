#include <HexaLib.h>

unsigned long T1, T2;

void setup()
{
  Serial.begin (115200);
  Log ("Random number from 0 to 100: " + String (HWRandom (100)), 3);
  Log ("Random number from 1000 to 10000: " + String (HWRandom (1000, 10000)), 3);
  Log ("Random float between 0.00000 and 1.00000: " + String (float (HWRandom (10000)) / 10000.0, DEC), 3);
  Log ("", 3);
  Log ("Try pressing the reset button, the numbers should not always start the same, as it's done by hardware.", 3);
  Log ("Warming up your arduino will have an effect. It uses the internal temperature sensor. ;)", 3);
  Log ("", 3);
  delay (7000);
}

void loop()
{
  // HWRandom() generates 32 bit unsigned long random numbers however the max value is 2^32 -2.
  // It can usually generate over 250 random numbers / second, however it will take new reading if the reading is too stable(0x00000000 or 0xFFFFFFFF). In those cases it's slower.
  T1 = micros ();
  unsigned long X = HWRandom ();
  T2 = micros ();
  Log ("Random number " + String (X) + " generated in " + String ((float (T2) - float (T1)) / 1000) + " milliseconds.", 3);
  delay (1000); // Disable this delay, set Serial.begin() to 2000000, and see how fast it gets. ;) (115200 baud rate is a bottle neck.)
}
