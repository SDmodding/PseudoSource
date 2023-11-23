// File Line: 89
// RVA: 0xBA3D80
__int64 __fastcall hkMath::abs_int__0(int t)
{
  return abs32(t);
}

// File Line: 100
// RVA: 0x132CA30
// attributes: thunk
double __fastcall hkMath::pow_0(float r, float s)
{
  double result; // xmm0_8

  *(float *)&result = powf(r, s);
  return result;
}

// File Line: 274
// RVA: 0xE30E20
// attributes: thunk
double __fastcall hkMath::atan2_0(float y, float x)
{
  double result; // xmm0_8

  *(float *)&result = atan2f(y, x);
  return result;
}

// File Line: 828
// RVA: 0xDC9FD0
__int64 __fastcall hkMath::_max2_int__0(unsigned int x, unsigned int y)
{
  if ( (int)x > (int)y )
    return x;
  return y;
}

// File Line: 842
// RVA: 0xD0C8A0
__int64 __fastcall hkMath::_min2_int_(unsigned int x, unsigned int y)
{
  if ( (int)x < (int)y )
    return x;
  return y;
}

// File Line: 1131
// RVA: 0xB3E500
__int64 __fastcall hkMath::intInRange_0(int value, int lowInclusive, int highExclusive)
{
  return (value < highExclusive) & (unsigned __int8)(lowInclusive <= value);
}

// File Line: 1140
// RVA: 0xE106B0
float __fastcall hkMath::interpolate2d_1(float x, float x0, float x1, float y0, float y1)
{
  return (float)((float)((float)(x - x0) * (float)(y1 - y0)) / (float)(x1 - x0)) + y0;
}

