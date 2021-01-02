/*
The DigitalTouch class works by reseting the pin(pinMode(Pin, OUTPUT), which also sets the pin low, and pinMode(Pin, INPUT) right after that) then counting while the 330K pull up resistor pulls it high.


Advantages:
- No need to waste an extra transmit pin! - Unlike with the CapacitiveSensor library, it uses 1 digita I/O pin with an external 330K pullup to VCC for an input, that's it.
- It has auto calibration. - I found that dirt on the pads or flux residue at the joints close to each other may affect the readings, so I implemented it, but I would still recommend cleaning it!
- Highly responsive. - It's way faster then reading an MPR121 module via I2C. (The normal is 2-7 count when untouched, and anywhere up to 20-25 count when touched. So it's fast because it doesn't normally do long loops, of course this is highly dependent on the external pullup as well.)
- Readings also seem to be more stable then with the MPR 121 module and the adafruit library. (Probably due to the built in hysteresis.)


Disadvantages:
- Unfortunately couln't get away doing it with the internal pullup resistor, that's far too low value, and not very accurate either as I found out, so you do need an external 330K pullup for each pin. :-/
- Uses somewhat more flash memory then then the AnalogTouch class.
- Due to the ESP's higher speed, it's far more sensitive then the arduino's input, thus require 330K resistor instead of 1M, some twitch suppression, and also different calibration settings.


Advantage or Disadvantage you decide depending on your application:
- It does not react to proximity, it absolutely needs skin contact with bare pad.


If you find this useful, please consider donationg: http://osrc.rip/Support.html
*/

#include <TouchLib.h>

DigitalTouch TInA(12);
DigitalTouch TInB(13);

byte APadState = 0;
byte BPadState = 0;

void setup()
{
  Serial.begin (115200);
  
  // ESP8266 calibration settings (Tested with ESP12F generic module, soldered on a breakout board, 330K pullup resistors, and clean joints. Very important to clean up flux residue to avoid cross talk!)
  TInA.SetCalibLimit (20);
  TInA.SetThreshold (25);
  TInB.SetCalibLimit (20);
  TInB.SetThreshold (25);

  /*
  Debug code (use it to tune your pads if needed. This can be touchy, so clean up flux residue, before tuning as it may infuence the readings, create crosstalk between pins, etc.)
  You will need to use it if your ESP runs on other then 80MHz, you didn't clean flux residue, you used other then 330K resistors or if you have more interference then I have...
  It was originally designed for 16MHz AVRs and it's really sensitive due to the ESP's high speed...
  
  - TInX.SetCalibLimit () should be somewhat a higher value then what it reads when not touched.
  - Stat will be high when Untouched value + TInX.SetThreshold () value is exceeded.
  TInA.Calibrate() will wait till the pad is released, read actual untouched value, and calculat when the state should turn HIGH.
    Once the stat is HIGH it will stay high until the readings retunr to untouched value to avoid oscillation.
  */
  /*
  while(1)
  {
    byte X = TInA.Read ();
    if (X < 10)
      Serial.print ("TInA:   ");
    else if (X < 100)
      Serial.print ("TInA:  ");
    else
      Serial.print ("TInA: ");
    Serial.print (X);
    X = TInB.Read ();
    if (X < 10)
      Serial.print ("   TInB:   ");
    else if (X < 100)
      Serial.print ("   TInB:  ");
    else
      Serial.print ("   TInB: ");
    Serial.print (X);
    yield();
  }
  */

  // Calibration - Required for TInX.ReadState() onyl. Not for TInX.Read ()
  while (TInA.Calibrate())
  {
    Serial.println (F("Calibration for Touch Input A failed! Retrying..."));
    yield ();
  }
  while (TInB.Calibrate())
  {
    Serial.println (F("Calibration for Touch Input B failed! Retrying..."));
    yield ();
  }
}

void loop()
{
  // Twitch suppression
  APadState <<= 1;
  bitWrite (APadState, 0, TInA.ReadState());
  // Rising Edge event
  if (APadState == 0x0F)
    Serial.println (F("The pad A got touched!"));
  // Falling Edge event
  if (APadState == 0xF0)
    Serial.println (F("The pad A got released!"));

  // Twitch suppression
  BPadState <<= 1;
  bitWrite (BPadState, 0, TInB.ReadState());
  // Rising Edge event
  if (BPadState == 0x0F)
    Serial.println (F("The pad B got touched!"));
  // Falling Edge event
  if (BPadState == 0xF0)
    Serial.println (F("The pad B got released!"));

  Serial.print (F("A: "));
  Serial.print (TInA.ReadState()); // This one reads the pad's boolean state 1/0, touched/not touched
  Serial.print (F("   B: "));
  Serial.print (TInB.Read()); // This returns the counter value when the pin goes high. This is good for debugging...
  Serial.println ();
}
