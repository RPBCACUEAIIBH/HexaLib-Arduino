HexaLib is a collection of my own libraries all under the same license. A multi tool for arduinos, and ESP8266.

Simply put #include <HexaLib.h> at the top of your sketch, and you have access to all libraries within.

Some member libraries have documentation and/or other resources, the rest of them only have example sketches you can analyze.

List of member libraies:
- HexaLog library v1.0.0 - A fancy selective Serial.println() It can display/hide a string based on log level, and/or based section number. You can assign both a loglevel (1 for Error, 2 for Warning, 3 for Info, and 4 for Debug) and a section number.
- RNGInit library v1.0.1 - Loads a random seed from EEPROM, and saves a new one for next boot. An alternative for taking a measurement from a floating analog pin. (I more often run out of pins then EEPROM space, even on atmega, but especially on the ESP8266. This works on both.)
- HWRNG  library v1.0.0 (Atmega 168A/P, 328/P/Pb, 32u4 only) - Generates random numbers by reading the internal temperature sensor's LSB several times. Way faster and more compact compiled then the Entropy library, but may not be as random... (Haven't tested it's randomness yet...)
- InternalTemp library v1.0.0 (Atmega 168A/P, 328/P/Pb, 32u4 only) - Read and calibrate the Atmega's internal temperature sensor. (Accuracy and resolution is disappointing even when calibrated... :-/)
- TouchLib library v1.1.0 - Touch library for arduino and ESP8266 that only requires an external pull up resistor, and no extra pin to drive it.
- TouchBar library v2.1.0 - Advanced touch bar library for Arduino and ESP8266 using only 3-4 inputs with my TouchLib library, or MPR121 module with the adafruit library. (Also includes KiCAD library with sybols, and footprints.)
- Delinearizer library v2.0.0 - Meant to delinearize touchbar output (emulate non linear potmeter).
- DynamicID library v1.0.1 (ESP8266 only) - Handles IDs, assigning a new one to the user(s) every time the ID is returned. It's more secure then using the same pre-defined ID for every action.
- CTFArray library v1.0.0 - Compressed Tiny Float Array is a library that allows up to ~35% less memory usage for small floats in exchange for extra cpu cycles. This is great for artificial neurons, and vector stuff. (Most efficient usage is when storing multiples of 4 floats, the bigger the array the better.)

Update (1 Feb 2021):
- Added examples for CTFArray and HWRNG libraries.
- Fixed auto ranging bug and type mismatch(unsigned int vs uint16_t) that only affected ESP8266 in CTFArray (v1.0.1)
- Excluded HWRNG, and InternalTemp libraries form non AVR architectures, it caused compillation error on ESP8266.

Update (1 Feb 2021):
- Added CTFArray and InternalTemp libraries. (no examples or documentation yet...)

Update (29 Jan 2021):
- Encountered problems with RNGInit on AVR, Updated it to use EEPROM.update, but needs more testing... (v1.0.1)
- Added HWRNG library. (v1.0.0)
- Updated Delinearizer with several new curves, and selectable ranges. Examples and docs have not yet been updated... (v2.0.0)

Update (21 Jan 2021):
- Bug fix in DynamicID library - caused compillation error for atmega... (v1.0.1)
- Added (artificial neuron) LearningCurve and simplified the Delinearizer library. (v1.1.0)

[If you find this useful, please consider donationg.](http://osrc.rip/Support.html)
