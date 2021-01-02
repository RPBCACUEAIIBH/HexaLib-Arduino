HexaLib is a collection of my own libraries all under the same license. A multi tool for arduinos, and ESP8266.

Simply put #include <HexaLib.h> at the top of your sketch, and you have access to all libraries within.

Some member libraries have documentation and/or other resources, the rest of them only have example sketches you can analyze.

List of member libraies:
- HexaLog library v1.0.0 - A fancy selective Serial.println() It can display/hide a string based on log level, and/or based section number. You can assign both a loglevel (1 for Error, 2 for Warning, 3 for Info, and 4 for Debug) and a section number.
- RNGInit library v1.0.0 - Loads a random seed from EEPROM, and saves a new one for next boot. An alternative for taking a measurement from a floating analog pin. (I more often run out of pins then EEPROM space, even on atmega, but especially on the ESP8266. This works on both.)
- TouchLib library v1.1.0 - Touch library for arduino and ESP8266 that only requires an external pull up resistor, and no extra pin to drive it.
- TouchBar library V2.1.0 - Advanced touch bar library for Arduino and ESP8266 using only 3-4 inputs with my TouchLib library, or MPR121 module with the adafruit library. (Also includes KiCAD library with sybols, and footprints.)
- Delinearizer library v1.0.0 - Meant to delinearize touchbar output (emulate non linear potmeter).
- DynamicID library v1.0.0 (ESP8266 only) - Handles IDs, assigning a new one to the user(s) every time the ID is returned. It's more secure then using the same pre-defined ID for every action.


[If you find this useful, please consider donationg.](http://osrc.rip/Support.html)
