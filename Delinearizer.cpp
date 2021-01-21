#include "Delinearizer.h"


/* Calculation */

float Logarithmic (float Input)
{
  return 100 - 100 / 2 * log10(100 - Input * 99 / 100);
}

float InverseLogarithmic (float Input)
{
  return 100 / 2 * log10(Input * 99 / 100 + 1);
}

float SCurve (float Input)
{
  if (Input < 50)
    return InverseLogarithmic (Input) / ScaleILL;
  else
    return Logarithmic (Input) / ScaleILL + OffsetILL;
}

float LearningCurve (float Input)
{
  if (Input < 49.99999)
    return 49.99144 - SCurve (50 - Input);
  else
    return SCurve (Input - 50) + 49.99144;
}

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
