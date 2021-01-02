#include "TouchLib.h"



DigitalTouch::DigitalTouch (byte DigitalPin)
{
  Pin = DigitalPin;
}



// Settings
void DigitalTouch::SetCalibLimit (byte NewLimit)
{
  CalibrationLimit = NewLimit;
}

void DigitalTouch::SetThreshold (byte NewThreshold)
{
  Threshold = NewThreshold;
}



// Operation
byte DigitalTouch::Read()
{
  Counter = 0;
  pinMode (Pin, OUTPUT);
  pinMode (Pin, INPUT);
  while (digitalRead (Pin) == LOW)
    Counter += 1;
  return Counter;
}

boolean DigitalTouch::ReadState ()
{
  if (Read() >= UntouchedValue + Threshold && LastState == false)
  {
    LastState = true;
    return true;
  }
  else if (Read() <= UntouchedValue + 1 && LastState == true)
  {
    LastState = false;
    return false;
  }
  else
    return LastState;
}

boolean DigitalTouch::Calibrate()
{
  UntouchedValue = 0;
  for (byte i=0; i < 60; i++)
    UntouchedValue += Read();
  if (UntouchedValue < CalibrationLimit * 60)
  {
    UntouchedValue /= 60;
    return false;
  }
  else
    return true;
}
