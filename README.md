HexaLib is a collection of my own libraries.

Simply include put #include <HexaLib.h> at the top of your sketch, and you have access to all libraries within.

Version 1.0.0:
- HexaLog library - A fancy selective Serial.println() It can display a string based on log level, and/or based section definition. You can assign both a loglevel (1 for Error, 2 for Warning, 3 for Info, and 4 for Debug) and a section number.
- RNGInit library - Loads a random seed from EEPROM, and saves a new one for next boot. An alternative for taking a measurement from a floating analog pin. (I more often run out of pins then EEPROM space, even on atmega, but especially on the ESP8266. This works on both.)
- DynamicID library (ESP8266 only) - Handles IDs, assigning a new one to the user(s) every time the ID is returned. It's more secure then using the same pre-defined ID for every action.


[If you find this useful, please consider donationg.](http://osrc.rip/Support.html)
