// File Line: 205
// RVA: 0xC741F0
__int64 __fastcall hkColor::rgbFromChars(
        unsigned __int8 red,
        unsigned __int8 green,
        unsigned __int8 blue,
        unsigned __int8 alpha)
{
  return blue + ((green + ((red + (alpha << 8)) << 8)) << 8);
}

// File Line: 214
// RVA: 0xC74220
__int64 __fastcall hkColor::rgbFromFloats(const float red, const float green, const float blue, const float alpha)
{
  return hkColor::rgbFromChars(
           (int)(float)(red * 255.0),
           (int)(float)(green * 255.0),
           (int)(float)(blue * 255.0),
           (int)(float)(alpha * 255.0));
}

// File Line: 231
// RVA: 0xC744C0
void __fastcall HSVtoRGB(float *r, float *g, float *b, float h, float s, float v)
{
  float v7; // xmm6_4
  int v8; // ecx
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx

  if ( s == 0.0 )
  {
    *b = v;
    *g = v;
    *r = v;
  }
  else
  {
    if ( h == 1.0 )
    {
      v7 = FLOAT_6_0;
      v8 = 5;
    }
    else
    {
      v7 = h * 6.0;
      v9 = _mm_sub_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_sub_ps((__m128)COERCE_UNSIGNED_INT(h * 6.0), *(__m128 *)two23), *(__m128 *)two23),
               *(__m128 *)two23),
             *(__m128 *)two23);
      v10 = _mm_cmplt_ps(
              *(__m128 *)two23,
              (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)COERCE_UNSIGNED_INT(h * 6.0), 1u), 1u));
      v8 = (int)COERCE_FLOAT(_mm_andnot_ps(
                               v10,
                               _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)LODWORD(v7), v9)), v9)).m128_u32[0] | v10.m128_i32[0] & LODWORD(v7));
    }
    v11 = (float)(1.0 - s) * v;
    v12 = v7 - (float)v8;
    v13 = (float)(1.0 - (float)(v12 * s)) * v;
    v14 = (float)(1.0 - (float)((float)(1.0 - v12) * s)) * v;
    if ( v8 )
    {
      v15 = v8 - 1;
      if ( v15 )
      {
        v16 = v15 - 1;
        if ( v16 )
        {
          v17 = v16 - 1;
          if ( v17 )
          {
            if ( v17 == 1 )
            {
              *r = v14;
              *g = v11;
              *b = v;
            }
            else
            {
              *r = v;
              *g = v11;
              *b = v13;
            }
          }
          else
          {
            *r = v11;
            *g = v13;
            *b = v;
          }
        }
        else
        {
          *r = v11;
          *g = v;
          *b = v14;
        }
      }
      else
      {
        *r = v13;
        *g = v;
        *b = v11;
      }
    }
    else
    {
      *r = v;
      *g = v14;
      *b = v11;
    }
  }
}

// File Line: 266
// RVA: 0xC74290
__int64 __fastcall hkColor::rgbFromHSV(float h, float s, float v, float alpha)
{
  float b; // [rsp+30h] [rbp-28h] BYREF
  float g; // [rsp+34h] [rbp-24h] BYREF
  float r; // [rsp+38h] [rbp-20h] BYREF

  HSVtoRGB(&r, &g, &b, h, s, v);
  return hkColor::rgbFromFloats(r, g, b, alpha);
}

// File Line: 280
// RVA: 0xC742F0
unsigned int __fastcall hkColor::getRandomColor()
{
  if ( (_S1_42 & 1) == 0 )
  {
    _S1_42 |= 1u;
    prng = 0i64;
  }
  return hkColor::getRandomColor(&prng);
}

// File Line: 286
// RVA: 0xC74320
__int64 __fastcall hkColor::getRandomColor(hkPseudoRandomGenerator *rand)
{
  signed int v1; // r8d
  signed int v2; // eax

  v1 = 1664525 * rand->m_current + 1013904223;
  v2 = 1664525 * (1664525 * v1 + 1013904223) + 1013904223;
  rand->m_current = v2;
  return hkColor::rgbFromFloats(
           (float)v1 * 2.3283064e-10,
           (float)(1664525 * v1 + 1013904223) * 2.3283064e-10,
           (float)v2 * 2.3283064e-10,
           1.0);
}

// File Line: 296
// RVA: 0xC743A0
__int64 __fastcall hkColor::getSpectrumColor(float value)
{
  __m128 v1; // xmm1
  __m128 red; // [rsp+20h] [rbp-78h]
  __int128 v4; // [rsp+30h] [rbp-68h]
  __int128 v5[5]; // [rsp+40h] [rbp-58h]

  v5[0] = _xmm;
  v5[2] = _xmm;
  v5[1] = _xmm;
  v5[4] = _xmm;
  v4 = _xmm;
  v5[3] = _xmm;
  if ( value > 0.0 )
  {
    if ( value < 1.0 )
    {
      v1 = (__m128)v5[(int)(float)(value * 5.0) - 1];
      red = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)v5[(float)(value * 5.0)], v1),
                _mm_shuffle_ps(
                  (__m128)COERCE_UNSIGNED_INT((float)(value * 5.0) - (float)(int)(float)(value * 5.0)),
                  (__m128)COERCE_UNSIGNED_INT((float)(value * 5.0) - (float)(int)(float)(value * 5.0)),
                  0)),
              v1);
    }
    else
    {
      red = (__m128)_xmm;
    }
  }
  else
  {
    red = (__m128)_xmm;
  }
  return hkColor::rgbFromFloats(red.m128_f32[0], red.m128_f32[1], red.m128_f32[2], 1.0);
}

// File Line: 318
// RVA: 0xC74490
__int64 __fastcall hkColor::getPaletteColor(char i, unsigned __int8 alpha)
{
  return (alpha << 24) | hkColor::s_colorTable[i & 0x1F] & 0xFFFFFF;
}

