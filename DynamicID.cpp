#include "DynamicID.h"

#ifdef ESP8266

String DynamicID::Create (unsigned long EXP, String USR)
{
  String X = F ("Created: ");
  DID = sha1(String(millis()) + String(rand()));
  ExpireAfter = EXP;
  User = USR;
  AccessTime = millis();
  Log (X + String (DID), 4, LibLogSect);
  X = F("User: ");
  Log (X + String (User), 4, LibLogSect);
  X = F("AccessTime: ");
  Log (X + String(AccessTime), 4, LibLogSect);
  X = F("Expire after: ");
  X += String (ExpireAfter);
  X += F(" Seconds");
  Log (X, 4, LibLogSect);
  Log ("", 4, LibLogSect);
  return DID;
}

String DynamicID::Check (String PreviousID)
{
  String X = F ("Checking: ");
  X += PreviousID;
  Log (X, 4, LibLogSect);
  if (User != "")
  {
    unsigned long Time = millis ();
    unsigned long EXP = ExpireAfter * 1000;
    if(Time > AccessTime + EXP || Time < EXP && Time > EXP - (0xffffffff - AccessTime))  // Normal expiry case || Rollover expiry case
    {
      Log (F ("Expired!"), 4, LibLogSect);
      Delete ();
    }
    else if (PreviousID == DID)
    {
      X = F ("User: ");
      X += String (User);
      Log (X, 4, LibLogSect);
      AccessTime = millis();
      DID = sha1(PreviousID + String(rand()));
      X = F("New ID: ");
      Log (X + String (DID), 4, LibLogSect);
      X = F("AccessTime: ");
      Log (X + String (AccessTime), 4, LibLogSect);
      Log ("", 4, LibLogSect);
      return DID;
    }
    else
    {
      Log (F ("No match..."), 4, LibLogSect);
      Log ("", 4, LibLogSect);
    }
  }
  return "";
}

#endif

void DynamicID::Delete ()
{
  DID = "";
  ExpireAfter = 0;
  User = "";
  AccessTime = 0;
  Log (F("ID Deleted!"), 4, LibLogSect);
  Log ("", 4, LibLogSect);
}
