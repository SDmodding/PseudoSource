// File Line: 274
// RVA: 0xBDE380
void __fastcall hkMath::atan2(const float y, const float x)
{
  atan2f(y, x);
}

// File Line: 1140
// RVA: 0xBDE390
float __fastcall hkMath::interpolate2d(float x, float x0, float x1, float y0, float y1)
{
  return (float)((float)((float)(x - x0) * (float)(y1 - y0)) / (float)(x1 - x0)) + y0;
}

