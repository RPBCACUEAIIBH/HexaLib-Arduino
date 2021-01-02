#include <HexaLib.h>

void setup ()
{
  Serial.begin (115200);
  Serial.println ();
  Serial.println ();

  // The first attribute is log level, the second is section, which can represent a specific section of your code.
  // Uncomment 1 at a time, upload, and watch the serial monitor
  //LogSettings (0, 0); // Silent: Nothing sent to serial
  //LogSettings (1, 0); // Minimal: Only show Errors
  //LogSettings (2, 0); // Normal: Only show Errors and Warnings
  //LogSettings (3, 0); // Verbose(Default): Errors, Warnings, and Info but not Debug messages
  //LogSettings (4, 0); // All: Errors, Warnings, Info and Debug messages
  //LogSettings (0, 1); // Show Section 1 mesages only
  //LogSettings (1, 1); // Errors from all sections + all messages from section 1

  // Default (No section specified.)
  Log ("S255 Error", 1); // Note that there is only 2 attribute
  Log ("S255 Warning", 2, 255); // You can also specify section 255 which is the default section.
  Log ("S255 Info", 3);
  Log ("S255 Debug", 4);

  // Group 1
  Log ("S1 Error", 1, 1);
  Log ("S1 Warning", 2, 1);
  Log ("S1 Info", 3, 1);
  Log ("S1 Debug", 4, 1);

  // Group 2
  Log ("S2 Error", 1, 2);
  Log ("S2 Warning", 2, 2);
  Log ("S2 Info", 3, 2);
  Log ("S2 Debug", 4, 2);

  float A = 756.56;
  Log ("Simple string with a numeric variable A: " + String (A), 3, 3); // F() macro doesn't like being combined this way, but the next example shows a workaround...
  
  String X = F("This is a string in flash memory combined with a number: "); // string with F() macro must be in separate line...
  X += String (52) + ", and a string from RAM displayed in 1 line."; // but strings in RAM can be added with + sign just fine...
  Log (X + " And this works too.", 3, 3);
}

void loop ()
{}
