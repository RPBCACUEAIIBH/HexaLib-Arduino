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

void setup()
{
  Serial.begin (115200);

  // CTFArray Declaration
  CTFArray CTFA(11);

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

  // Autoranging demo
  CTFA.Put (0, 1.31067);
  CTFA.Put (1, 1.31068);
  CTFA.Put (2, 1.31069);
  CTFA.Put (3, 1.31070);
  CTFA.Put (4, 1.31071);
  CTFA.Put (5, 1.31072);
  CTFA.Put (6, 1.31073);
  CTFA.Put (7, 1.31074);
  CTFA.Put (8, 1.31075);
  CTFA.Put (9, 1.31076);
  CTFA.Put (10, 1.31077);
  Log ("", 3);
  for (unsigned int i = 67; i < 78; i++)
  {
    String Msg = F("In: 1.310");
    Msg += String (i);
    Msg += F (" - Out: ");
    Msg += String (CTFA.Get (i - 67), 5);
    if (i > 70)
      Msg += F (" <- 4 decimals");
    else
      Msg += F (" <- 5 decimals");
    Log (Msg, 3);
  }

  CTFA.Put (0, 7.9997);
  CTFA.Put (1, 7.9998);
  CTFA.Put (2, 7.9999);
  CTFA.Put (3, 8.0000);
  CTFA.Put (4, 8.0001);
  CTFA.Put (5, 8.0002);
  CTFA.Put (6, 8.0003);
  CTFA.Put (7, 8.0004);
  CTFA.Put (8, 8.0005);
  CTFA.Put (9, 8.0006);
  CTFA.Put (10, 8.0007);
  Log ("", 3);
  for (unsigned int i = 7; i < 18; i++)
  {
    String Msg;
    if (i > 9)
    {
      Msg = F("In: 8.000");
      Msg += String (i % 10);
      Msg += F (" - Out: ");
      Msg += String (CTFA.Get (i - 7), 4);
      Msg += F (" <- 3 decimals");
    }
    else
    {
      Msg = F("In: 7.999");
      Msg += String (i % 10);
      Msg += F (" - Out: ");
      Msg += String (CTFA.Get (i - 7), 4);
      Msg += F (" <- 4 decimals");
    }
    Log (Msg, 3);
  }
  
  CTFA.Put (0, 127.997);
  CTFA.Put (1, 127.998);
  CTFA.Put (2, 127.999);
  CTFA.Put (3, 128.000);
  CTFA.Put (4, 128.001);
  CTFA.Put (5, 128.002);
  CTFA.Put (6, 128.003);
  CTFA.Put (7, 128.004);
  CTFA.Put (8, 128.005);
  CTFA.Put (9, 128.006);
  CTFA.Put (10, 128.007);
  Log ("", 3);
  for (unsigned int i = 7; i < 18; i++)
  {
    String Msg;
    if (i > 9)
    {
      Msg = F("In: 128.00");
      Msg += String (i % 10);
      Msg += F (" - Out: ");
      Msg += String (CTFA.Get (i - 7), 3);
      Msg += F (" <- 2 decimals");
    }
    else
    {
      Msg = F("In: 127.99");
      Msg += String (i % 10);
      Msg += F (" - Out: ");
      Msg += String (CTFA.Get (i - 7), 3);
      Msg += F (" <- 3 decimals");
    }
    Log (Msg, 3);
  }
}

void loop()
{}
