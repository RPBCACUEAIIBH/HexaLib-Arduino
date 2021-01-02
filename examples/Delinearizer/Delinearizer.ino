/*
The Delinearizer library is designed to simulate Logarithmic, Inverse Logarithmic, and S-Curve tapered potmeter output on Arduino.


Hardware requirements:
- Arduino connected to PC.


Libraries requirements:
- Delinearizer (This one.)


Skill requirements:
- You need to have basic arduino skills. (Understanding arduino code, installing and using libraries, etc. This is a library of source code with an example sketch not a tutorial, so I won't explain everything here.)


If you find this useful, please consider donationg: http://osrc.rip/Support.html
*/

#include <Delinearizer.h>


void setup ()
{
  Serial.begin(115200); // << At 9600 you have to wait a lot for the 3000 results it spits out... ;)
  
  Serial.println(F("Logarithmic"));
  for (float i = 0; i <= 100; i += 0.1)
    Serial.println(Logarithmic(i)); // Takes a percentage (float value between 0.0 and 100.0) and returns the logarithmic equivalent in percentage.
  
  Serial.println(F("InverseLogarithmic"));
  for (float i = 0; i <= 100; i += 0.1) // Takes a percentage (float value between 0.0 and 100.0) and returns the inverse logarithmic equivalent in percentage.
    Serial.println(InverseLogarithmic(i));
  
  Serial.println(F("S-Curve"));
  for (float i = 0; i <= 100; i += 0.1)
    Serial.println(SCurve(i)); // Takes a percentage (float value between 0.0 and 100.0) and below 50% returns the inverse logarithmic, from 50% upward returns logarithmic equivalent in percentage.

    Serial.println ();
    
    // It also does conversion from unsigned int to float and vice versa. Integer range 0 to 10000, Float range 0.0 to 100.0
    Serial.println (ItoF(9735)); // Should print 97.35
    Serial.println (FtoI(86.57)); // Should print 8657
}

void loop ()
{
  
}
