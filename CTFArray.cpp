#include "CTFArray.h"

CTFArray::CTFArray (unsigned int ArrayLength)
{
  CTFArrayLength = ArrayLength;
  if (ArrayLength % 4 > 0)
    Array = (uint16_t*)calloc(ArrayLength + ArrayLength / 4 + 1, sizeof(uint16_t));
  else
    Array = (uint16_t*)calloc(ArrayLength + ArrayLength / 4, sizeof(uint16_t));
}

CTFArray::~CTFArray ()
{
  free(Array);
}

boolean CTFArray::Check()
{
  if (Array == NULL)
    return 1;
  else
    return 0;
}

unsigned int CTFArray::Length ()
{
  return CTFArrayLength;
}

unsigned int CTFArray::Size ()
{
    if (CTFArrayLength % 4 > 0)
    return (CTFArrayLength + CTFArrayLength / 4 + 1) * (sizeof (uint16_t)) + sizeof (CTFArrayLength) + sizeof (Array);
  else
    return (CTFArrayLength + CTFArrayLength / 4) * (sizeof(uint16_t)) + sizeof (CTFArrayLength) + sizeof (Array);
}

void CTFArray::Put (unsigned int Position, float Value)
{
  if (Position >= 0 && Position < CTFArrayLength)
  {
    byte DecimalPlaces = 5;
    if (Value > 127.999 || Value < -127.999 )
      DecimalPlaces = 2;
    else if (Value > 7.9999 || Value < -7.9999)
      DecimalPlaces = 3;
    else if (Value > 1.31071 || Value < -1.31071)
      DecimalPlaces = 4;
    switch (DecimalPlaces)
    {
      case 2: Value *= 100;
      break;;
      case 3: Value *= 1000;
      break;;
      case 4: Value *= 10000;
      break;;
      case 5: Value *= 100000;
      break;;
    }
    long X = round(Value); // << This must be rounded otherwise it glitches at decimal place change: 127.996, 127.997, 127.998, 127.99(whihc is < 127.998), 128.00, 127.01 and so on...
    if (X < 0)
    {
      X *= -1;
      bitSet (X, 19);
    }
    X += (long(DecimalPlaces) - 2) << 17;
    Array[Position] = X;
    unsigned int SharedPosition = CTFArrayLength + Position / 4;
    switch (Position % 4)
    {
      case 0: Array[SharedPosition] &= 0xFFF0;
              Array[SharedPosition] |= X >> 16 & 0x000F;
      break;;
      case 1: Array[SharedPosition] &= 0xFF0F;
              Array[SharedPosition] |= X >> 12 & 0x00F0;
      break;;
      case 2: Array[SharedPosition] &= 0xF0FF;
              Array[SharedPosition] |= X >> 8 & 0x0F00;
      break;;
      case 3: Array[SharedPosition] &= 0x0FFF;
              Array[SharedPosition] |= X >> 4 & 0xF000;
      break;;
    }
  }
}

float CTFArray::Get (unsigned int Position)
{
  if (Position < 0)
    Position = 0;
  if (Position >= CTFArrayLength)
    Position = CTFArrayLength - 1;
  unsigned int SharedPosition = CTFArrayLength + Position / 4;
  long X = Array[Position];
  bitWrite (X, 16, bitRead(Array[SharedPosition], Position % 4 * 4));
  if (bitRead(Array[SharedPosition], Position % 4 * 4 + 3) == true)
    X *= -1;
  float Value;
  switch (((Array[SharedPosition] >> Position % 4 * 4 + 1) & 0x0003) + 2)
  {
    case 2: Value = float(X) / 100;
    break;;
    case 3: Value = float(X) / 1000;
    break;;
    case 4: Value = float(X) / 10000;
    break;;
    case 5: Value = float(X) / 100000;
    break;;
  }
  return Value;
}
