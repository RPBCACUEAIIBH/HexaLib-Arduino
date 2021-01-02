/*
The AnalogTouch class works by reseting the pin(pinMode(Pin, OUTPUT), which also sets the pin low, and pinMode(Pin, INPUT) right after that) then taking an analog measurement.


Advantages:
- No need to waste an extra transmit pin! - Unlike with the CapacitiveSensor library, it uses 1 digita I/O pin with an external 1M pullup to VCC for an input, that's it.
- It has auto calibration. - I found that dirt on the pads or flux residue at the joints close to each other may affect the readings, so I implemented it, but I would still recommend cleaning it!
- It is somewhat more compact when compiled then DigitalTouch class.
- May be more suitable for sensing touch intensity then the DigitalTouch class as it has higher resolution.


Disadvantages:
- Unfortunately couln't get away doing it with the internal pullup resistor, that's far too low value, and not very accurate either as I found out, so you do need an external 1M pullup for each pin. :-/
- Only works on Analog inputs that have digital I/O function as well since it sets the pin to output in order to reset it. (Won't work on the ATMEGA 328P's A6 and A7 pins that are only analog inputs.)
- Not as responsive as the DigitalTouch class, it's speed is limited by the arduinos analog sample rate. (Takes about 100us to read an input.:-/)


Advantage or Disadvantage you decide depending on your application:
- It does not react to proximity, it absolutely needs skin contact with bare pad. (Maybe it could read proximity with a way higher value resistor, but currently the highest I have is 1M so I can't test it...)


If you find this useful, please consider donationg: http://osrc.rip/Support.html
*/

#include <TouchLib.h>

AnalogTouch TInA(A0);
AnalogTouch TInB(A1);

void setup()
{
  Serial.begin (115200);
  
  // These are set for 16MHz arduinos, you may need to tweak them for different frequency boards. (I'm using a 5V Pro-Mini runing at 16MHz with ATMEGA 328P.)
  // TInA.SetCalibLimit (); // Calibration will fail if this value exceeds the untouched average.(Opposite of the DigitalTouch calibration.) It takes: byte NewLimit; Default: 100; Valid: <= 120
  // TInA.SetThreshold (); // This determines the sensitivity; It takes: byte NewThreshold; Default: 15; Valid: >= 15

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
