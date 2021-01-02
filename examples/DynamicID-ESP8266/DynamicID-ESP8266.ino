#include <HexaLib.h>

DynamicID ID[2];

void setup ()
{
  EEPROM.begin (4096);
  
  Serial.begin(115200);
  Serial.println ();
  Serial.println ();
  
  LogSettings (4, 0); // Debug mode... Section 254 messages are produced by the HexaLib library for debug purpose...
  String X, Y;
  
  RNGInit (0); // This is not a must for, but it's recommended otherwise you may find familiar IDs after each reboot... Depends on your application. Syntax: RNGInit (EEPROMAddress)
  
  ID[0].Create (millis () / 1000 + 60, "User4574"); // ID expires in 1 minute
  X = ID[1].Create (millis () / 1000 + 2, "User001"); // ID expires in 2 sencods

  Log ("For loop starts here.", 3, 1);
  Log ("", 3, 1);
  for (byte i = 0; i < 2; i++)
  {
    Log ("Checking: ID[" + String (i) + "]", 3, 1); // Section 1 message...
    Log ("", 3, 1);
    Y = ID[i].Check (X);
    if (Y != "")
    {
      Log ("Match found! " + ID[i].User + " recognized!", 3, 1);
      Log ("", 3, 1);
      break;
    }
  }
  Log ("For loop ends here.", 3, 1);
  Log ("", 3, 1);
  X = ID[1].Check (X); // Note that X contains the old ID, the library gave us a new one when it found a match in the for loop, so Y contains the new ID now... so this should fail
  X = ID[1].Check (Y); // This should work... No match does not produce a new ID...
  yield ();
  delay (2000);
  X = ID[1].Check (X); // Since it expires in 2 seconds, this should fail... It automatically deletes expired IDs when next checked whether it matches or not and returns empty string...
  Log ("X: " + X, 3, 1);
  Log ("", 3, 1);
  Log ("Deleting ID[0]", 3, 1);
  ID[0].Delete (); // You can also delete an ID if the user logs out.
}

void loop ()
{}
