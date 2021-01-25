#include "Delinearizer.h"


/* Calculation */

float Logarithmic (float Input, boolean Range)
{
  if (Range == false)
  {
    Input = 100.0 - Trim (Input) * 99.0 / 100.0;
    return 100.0 - 50.0 * log10(Input);
  }
  else
  {
    Input = 100.0 - Trim (Input + 1.0, 0.0, 2.0) * 99.0 / 1.99999;
    return 1.0 - log10(Input);
  }
}// Execution time: 222.18us (Range: 0.0 to 100.0); 229.496us (Range: -1.0 to 1.0)

float InverseLogarithmic (float Input, boolean Range)
{
  if (Range == false)
  {
    Input = Trim (Input) * 99.0 / 100.0 + 1.0;
    return 50.0 * log10(Input);
  }
  else
  {
    Input = Trim (Input + 1.0, 0.0, 2.0) * 99.0 / 1.99999 + 1.0;
    return log10(Input) - 1.0;
  }
}// Execution time: 223.02us (Range: 0.0 to 100.0); 230.292us (Range: -1.0 to 1.0)

float SCurve (float Input, boolean Range)
{
  if (Range == false)
  {
    Input = Trim (Input);
    if (Input < 50.0)
      return InverseLogarithmic (Input) / ScaleILL;
    else
      return Logarithmic (Input) / ScaleILL + OffsetILL;
  }
  else
  {
    Input = Trim (Input + 1.0, 0.0, 2.0) * 50.0;
    if (Input < 50.0)
      return (InverseLogarithmic (Input) / ScaleILL) / 50 - 1;
    else
      return (Logarithmic (Input) / ScaleILL + OffsetILL) / 50 - 1;
  }
}// Execution time: 281.124us (Range: 0.0 to 100.0); 335.092us (Range: -1.0 to 1.0)

float BellCurve (float Input, boolean Range)
{
  if (Range == false)
  {
    Input = Trim (Input);
    return 50.0 + 50.0 * sin ((-90.0 + Input * (360.0 / 100.0)) * (PI / 180.0));
  }
  else
  {
    Input = Trim (Input + 1.0, 0.0, 2.0);
    return sin ((-90.0 + Input * (360.0 / 2.0)) * (PI / 180.0));
  }
}// Execution time: 151.1us (Range: 0.0 to 100.0); 158.828us (Range: -1.0 to 1.0)

float ReLU (float Input, boolean Range = 1)
{
  if (Range == true)
    return Trim (Input, 0.0, 1.0);
  else
    return Trim (Input, 50.0, 100.0);
}// Execution time: 16.496us (Range: 0.0 to 100.0); 16.568us (Range: -1.0 to 1.0)

float SigmoidExp (float Input, boolean Range)
{
  if (Range == true)
  {
    Input = Trim (Input, -1.0, 1.0) * 10;
    return (1.0 / (1.0 + exp (-Input))) * 2 - 1;
  }
  else
  {
    Input = Trim (Input);
    return (1.0 / (1.0 + exp (-((Input - 50) / 5)))) * 100;
  }
}// Execution time: 218.224us (Range: 0.0 to 100.0); 190.088us (Range: -1.0 to 1.0)

float SigmoidSine (float Input, boolean Range)
{
  if (Range == true)
  {
    Input = Trim (Input + 1, 0.0, 2.0);
    return sin ((-90.0 + Input * (180.0 / 2.0)) * (PI / 180.0));
  }
  else
  {
    Input = Trim (Input);
    return 50.0 + 50.0 * sin ((-90.0 + Input * (180.0 / 100.0)) * (PI / 180.0));
  }
}// Execution time: 148.748us (Range: 0.0 to 100.0); 156.468us (Range: -1.0 to 1.0)

float SigmoidInvLog (float Input, boolean Range)
{
  if (Range == true)
  {
    Input = Trim (Input + 1.0, 0.0, 2.0) * 50.0;
    if (Input < 49.99999)
      return (50.00856 - InverseLogarithmic (50.0 - Input) / ScaleILL) / 50.0 - 1.0;
    else
      return (InverseLogarithmic (Input - 50.0) / ScaleILL + 49.99144) / 50.0 - 1.0;
  }
  else
  {
    Input = Trim (Input);
    if (Input < 49.99999)
      return 50.00856 - InverseLogarithmic (50.0 - Input) / ScaleILL;
    else
      return InverseLogarithmic (Input - 50.0) / ScaleILL + 49.99144;
  }
}// Execution time: 285.128us (Range: 0.0 to 100.0); 338.396us (Range: -1.0 to 1.0)





/*float TestCurve (float Input, boolean Range)
{
  //Input = Trim (Input);
  //return 50.0 + 50.0 * sin ((-90.0 + Input * (180.0 / 100.0)) * (PI / 180.0));
  
  if (Input < -5.0)
    Input = -5.0;
  else if (Input > 5.0)
    Input = 5.0;
  return sin ((Input * (180.0 / 10.0)) * (PI / 180.0)) / 2.0 + 0.5;
}// Execution time: us (Range: 0.0 to 100.0); us (Range: -1.0 to 1.0) */





/* Conversion */

float ItoF (unsigned int Input)
{
  if (Input > 10000)
    Input = 10000;
  return float(Input) / 100;
}

unsigned int FtoI (float Input)
{
  if (Input > 100)
    Input = 100;
  return (unsigned int)(Input * 100);
}

float Trim (float Input, float LowerLimit, float UpperLimit)
{
  if (Input < LowerLimit)
    return LowerLimit;
  else if (Input > UpperLimit)
    return UpperLimit;
  else
    return Input;
}
