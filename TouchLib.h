#ifndef TouchLib_H
#define TouchLib_H

#include <Arduino.h>



class AnalogTouch // This works on analog inputs that can be digital I/Os as well. (does not work on A6 and A7 of ATMEGA 328P, those are analog only pins!)
{
  private:
  // User adjustable variables.
  byte Pin;
  byte CalibrationLimit = 100;
  byte Threshold = 15;
  // Internal variables
  boolean LastState = false;
  byte Counter = 0;
  unsigned int UntouchedValue;
  
  public:
  // Constructor
  AnalogTouch(byte AnalogPin);
  /* Public Methods */
  // Settings
  void SetCalibLimit (byte NewLimit);
  void SetThreshold (byte NewThreshold);
  // Operation
  boolean Calibrate ();
  byte Read ();
  boolean ReadState ();
};



class DigitalTouch // Meant for 16MHz arduinos! Not guaranteed to work correctly on other speeds!
{
  private:
  // User adjustable variables.
  byte Pin;
  byte CalibrationLimit = 7;
  byte Threshold = 4;
  // Internal variables
  boolean LastState = false;
  byte Counter = 0;
  unsigned int UntouchedValue;
  
  public:
  // Constructor
  DigitalTouch (byte DigitalPin);
  /* Public Methods */
  // Settings
  void SetCalibLimit (byte NewLimit);
  void SetThreshold (byte NewThreshold);
  // Operation
  boolean Calibrate ();
  byte Read ();
  boolean ReadState ();
};

#endif
