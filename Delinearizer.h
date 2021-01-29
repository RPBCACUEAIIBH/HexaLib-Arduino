#ifndef Delinearizer_H
#define Delinearizer_H

#include <Arduino.h>

/* Calculation */

#define ScaleILL 1.703
#define OffsetILL 100-(100-100/2*log10(1))/ScaleILL

// These are meant for simulating non linear potmeter value.
// Default range is from 0.0 to 100.0
float Logarithmic (float Input, boolean Range = 0);
float InverseLogarithmic (float Input, boolean Range = 0);
float SCurve (float Input, boolean Range = 0);

// Not sure what this will be good for...
// Default range is from 0.0 to 100.0
float BellCurve (float Input, boolean Range = 0); // Just cause I can... :P

// These are meant for artificial neurons.
// Default range is from -1.0 to 1.0
float ReLU (float Input, boolean Range = 1);
float SigmoidExp (float Input, boolean Range = 1);
float SigmoidSine (float Input, boolean Range = 1); // This is my invention...
float SigmoidInvLog (float Input, boolean Range = 1); // Also my invention...

/* Conversion and trimming */
float ItoF (unsigned int Input);
unsigned int FtoI (float Input);
float Trim (float Input, float LowerLimit = 0.0, float UpperLimit = 100.0);

#endif
