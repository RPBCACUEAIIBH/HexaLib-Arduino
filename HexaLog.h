#ifndef HexaLog_H
#define HexaLog_H

#include <Arduino.h>
#ifdef ESP8266
#include <pgmspace.h>
#elif AVR
#include <avr/pgmspace.h>
#endif

static byte LogLevel = 3; // 0 = Silent, 1 = Errors, 2 Errors and  Warnings, 3 = Errors, Warnings, and Info
static byte LogSection = 0; // 0 = Silent, 1 = Section1, 2 = Section2, and so on... 255 = Default Section(if no Section specified...)
void LogSettings (byte Level, byte Section = 0);
void Log (String Message, byte Level, byte Section = 255); // Level should range from 1 to 3, anything above is undefined; Section should range from 1 - 255; 0 is ignored for both.
String LeadingSpaces (byte Number);
String LeadingSpaces (unsigned long Number);

#endif
