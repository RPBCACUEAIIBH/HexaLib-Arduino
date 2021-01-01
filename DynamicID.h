#ifndef DynamicID_H
#define DynamicID_H

#include <Arduino.h>
#include <Hash.h>
#include "HexaLog.h"
#include "HexaLib.h" // LibLogSect is defined here for all members...

class DynamicID
{
  private:
  String DID;
  unsigned long AccessTime;
  unsigned long ExpireAfter; // in Seconds
  
  public:
  String User; // This stores information about the user. If it's empty the ID has expired or logged out...

  DynamicID (){};
  
  String Create (unsigned long EXP, String USR);
  String Check (String PreviousID);
  void Delete ();
};

#endif
