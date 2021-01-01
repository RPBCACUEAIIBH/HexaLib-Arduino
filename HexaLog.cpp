#include "HexaLog.h"

void LogSettings (byte Level, byte Section)
{
  LogLevel = Level;
  LogSection = Section;
}

void Log (String Message, byte Level, byte Section)
{
  if (Level <= LogLevel && Level > 0 || LogSection == Section && Section > 0)
  {
    Serial.print (LeadingSpaces (millis ()));
    Serial.print (F ("ms [S "));
    Serial.print (LeadingSpaces (Section));
    Serial.print (F (" --> "));
    switch (Level)
    {
      case 1: Serial.print (F ("  Error"));
      break;;
      case 2: Serial.print (F ("Warning"));
      break;;
      case 3: Serial.print (F ("   Info"));
      break;;
      case 4: Serial.print (F ("  Debug"));
      break;;
      default: Serial.print (F ("    ???"));
      break;;
    }
    Serial.print (F ("]: "));
    Serial.println (Message);
  }
}

String LeadingSpaces (byte Number)
{
  String X;
  if (Number < 100 && Number >= 10)
    X += " ";
  else if (Number < 10)
    X += "  ";
  X += String (Number);
  return X;
}

String LeadingSpaces (unsigned long Number)
{
  String X;
  if (Number < 1000000 && Number >= 100000)
    X += " ";
  else if (Number < 100000 && Number >= 10000)
    X += "  ";
  else if (Number < 10000 && Number >= 1000)
    X += "   ";
  else if (Number < 1000 && Number >= 100)
    X += "    ";
  else if (Number < 100 && Number >= 10)
    X += "     ";
  else if (Number < 10)
    X += "      ";
  X += String (Number);
  return X;
}
