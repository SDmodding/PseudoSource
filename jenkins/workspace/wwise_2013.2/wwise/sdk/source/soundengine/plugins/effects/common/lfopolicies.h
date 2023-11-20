// File Line: 38
// RVA: 0xAF9920
float __fastcall DSP::QuickSin_0(const float x)
{
  return (float)((float)((float)((float)((float)(0.0083063254 - (float)((float)(x * x) * 0.00018363654)) * (float)(x * x))
                               - 0.16664828)
                       * (float)(x * x))
               + 0.9999966)
       * x;
}

