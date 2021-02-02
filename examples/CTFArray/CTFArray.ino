#include <HexaLib.h>

/*
Compressed Tiny Float Array - Stores 4 floats in 10 bytes instead of 16 bytes (saving up to 37.5% memory).
Do note that:
- If you're using multiple instances, each uses 4 extra bytes to hold a pointer, and a length variable.
- The compiler won't tell you how much memory it uses, as it's not pre defined.
  It allocates memory dynamically, so you need to check calling name.Check() method to find out if it could allocate the neccessary memory!
- It has limited ranges:
    2 Decimal places: ±1023.99
    3 Decimal places: ±127.999
    4 Decimal places: ±7.9999
    5 Decimal places: ±1.31070
- It's auto ranging not fixed point!
  For example: it has 5 decimal places between -1.31070 and +1.31070, but drops to 4 decimal places when you write 1.3108 or -1.3108 into it.
*/

#ifdef ESP8266
CTFArray CTFA(20500); // ESP8266 (ESP12F generic module)
#else
CTFArray CTFA(600); // << That's 600 float values in memory, which wouldn't work with normal floats on an Atmega328P but this does. :)
#endif

void setup()
{
  Serial.begin (115200);
  Serial.println ();
  Serial.println ();

  // Array check
  if (CTFA.Check() > 0)
  {
    Log (F ("Failed to create CTFArray"), 1);
    while (1);
  }
  else
  {
    String Msg = F ("Size of CTFA: ");
    Msg += String (CTFA.Size ());
    Log (Msg + F (" byte"), 3);
  }

  Log ("", 3);
  delay (3000);
}

void loop()
{
  for (unsigned int i = 0; i < CTFA.Length(); i++)
  {
    Log ("", 3);
    float Z = -1023.99 + float (i) * (2051.0 / CTFA.Length()); // This should produce floats over the whole range that CTFA can hold.
    CTFA.Put (i, Z);
    String Msg = F ("Float ");
    Msg += String (i);
    Log (Msg, 3);
    Msg = F ("Input:  ");
    Msg += String(Z, DEC);
    Log (Msg, 3);
    Msg = F ("Output: ");
    Msg += String (CTFA.Get(i), DEC);
    Log (Msg, 3);
    yield (); // This is for ESP8266 compatibility...
  }
  delay (60000);
}
