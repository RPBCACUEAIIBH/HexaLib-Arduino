#ifndef CTFArray_H
#define CTFArray_H

// Compressed Tiny Float Array - Stores 4 floats in 10 bytes instead of 16 bytes (saving up to 37.5% memory).

// It has limited ranges:
// 2 Decimal places: ±1023.99
// 3 Decimal places: ±127.999
// 4 Decimal places: ±7.9999
// 5 Decimal places: ±1.31070

#include <Arduino.h>
#include <HexaLib.h>

class CTFArray
{
  private:
  unsigned int CTFArrayLength; //Actual size = ArrLen * 2.5 bytes; (1 sign bit + 2 range bits, + 17 data bits, so 3 bytes for 1 float, +2 bytes for the second, as 2 floats share a byte.)
  uint16_t * Array;
  
  public:
  CTFArray (unsigned int ArrayLength);
  ~CTFArray ();
  
  boolean Check ();
  unsigned int Length ();
  unsigned int Size ();
  
  void Put (unsigned int Position, float Value);
  float Get (unsigned int Position);
};

#endif
