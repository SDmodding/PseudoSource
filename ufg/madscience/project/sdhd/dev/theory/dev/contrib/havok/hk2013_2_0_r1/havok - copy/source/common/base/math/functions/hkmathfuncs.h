// File Line: 274
// RVA: 0xBDE380
// attributes: thunk
double __fastcall hkMath::atan2(float y, float x)
{
  double result; // xmm0_8

  *(float *)&result = atan2f(y, x);
  return result;
}

// File Line: 1140
// RVA: 0xBDE390
float __fastcall hkMath::interpolate2d(float x, float x0, float x1, float y0, float y1)
{
  return (float)((float)((float)(x - x0) * (float)(y1 - y0)) / (float)(x1 - x0)) + y0;
}

