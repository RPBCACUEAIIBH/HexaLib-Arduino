/*
The DigitalTouch class works by reseting the pin(pinMode(Pin, OUTPUT), which also sets the pin low, and pinMode(Pin, INPUT) right after that) then counting while the 1M pull up resistor pulls it high.


Advantages:
- No need to waste an extra transmit pin! - Unlike with the CapacitiveSensor library, it uses 1 digita I/O pin with an external 1M pullup to VCC for an input, that's it.
- It has auto calibration. - I found that dirt on the pads or flux residue at the joints close to each other may affect the readings, so I implemented it, but I would still recommend cleaning it!
- Highly responsive. - It's way faster then reading an MPR121 module via I2C. (The normal is 2-7 count when untouched, and anywhere up to 20-25 count when touched. So it's fast because it doesn't normally do long loops, of course this is highly dependent on the external pullup as well.)
- Readings also seem to be more stable then with the MPR 121 module and the adafruit library. (Probably due to the built in hysteresis.)


Disadvantages:
- Unfortunately couln't get away doing it with the internal pullup resistor, that's far too low value, and not very accurate either as I found out, so you do need an external 1M pullup for each pin. :-/
- Uses somewhat more flash memory then then the AnalogTouch class.


Advantage or Disadvantage you decide depending on your application:
- It does not react to proximity, it absolutely needs skin contact with bare pad. (Maybe it could read proximity with a way higher value resistor, but currently the highest I have is 1M so I can't test it...)


If you find this useful, please consider donationg: http://osrc.rip/Support.html
*/

#include <TouchLib.h>

DigitalTouch TInA(A0);
DigitalTouch TInB(A1);

void setup()
{
  Serial.begin (115200);
  
  // These are set for 16MHz arduinos, you may need to tweak them for different frequency boards. (I'm using a 5V Pro-Mini runing at 16MHz with ATMEGA 328P.)
  // TInA.SetCalibLimit (); // Calibration will fail if this value is exceeded. It takes: byte NewLimit; Default: 7; Valid: >= 1;
  // TInA.SetThreshold (); // This determines the sensitivity; It takes: byte NewThreshold; Default: 4; Valid: >= 3;

  // Calibration
  while (TInA.Calibrate())
    Serial.println (F("Calibration for Touch Input A failed! Retrying..."));
  while (TInB.Calibrate())
    Serial.println (F("Calibration for Touch Input B failed! Retrying..."));
}

void loop()
{
  Serial.print (F("A: "));
  Serial.print (TInA.ReadState()); // This one reads the pad's boolean state 1/0, touched/not touched
  Serial.print (F("   B: "));
  Serial.print (TInB.Read()); // This returns the counter value when the pin goes high. This is good for debugging...
  Serial.println ();
}
