#include "TouchLib.h"



AnalogTouch::AnalogTouch(byte AnalogPin)
{
  Pin = AnalogPin;
}



// Settings
void AnalogTouch::SetCalibLimit (byte NewLimit)
{
  CalibrationLimit = NewLimit;
}

void AnalogTouch::SetThreshold (byte NewThreshold)
{
  Threshold = NewThreshold;
}



// Operation
byte AnalogTouch::Read()
{
  pinMode (Pin, OUTPUT);
  pinMode (Pin, INPUT);
  return analogRead(Pin) / 4;
}

boolean AnalogTouch::ReadState ()
{
  if (Read() <= UntouchedValue - Threshold && LastState == false)
  {
    LastState = true;
    return true;
  }
  else if (Read() >= UntouchedValue - 12 && LastState == true)
  {
    LastState = false;
    return false;
  }
  else
    return LastState;
}

boolean AnalogTouch::Calibrate()
{
  UntouchedValue = 0;
  for (byte i=0; i < 60; i++)
    UntouchedValue += Read();
  if (UntouchedValue > CalibrationLimit * 60)
  {
    UntouchedValue /= 60;
    return false;
  }
  else
    return true;
}
