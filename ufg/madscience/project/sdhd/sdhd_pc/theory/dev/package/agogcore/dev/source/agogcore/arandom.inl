// File Line: 406
// RVA: 0x13CDD0
__int64 __fastcall ARandom::thorn(ARandom *this, unsigned int limit)
{
  unsigned int v3; // r9d
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // r9d
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx

  v3 = 1664525 * this->i_seed + 1013904223;
  v4 = 1664525 * v3 + 1013904223;
  v5 = HIWORD(v4);
  v6 = (limit * HIWORD(v3)) >> 16;
  v7 = 1664525 * v4 + 1013904223;
  this->i_seed = v7;
  v8 = (limit * (v5 + HIWORD(v7))) >> 16;
  if ( v8 >= limit )
    v9 = v8 - limit;
  else
    v9 = limit - v8 - 1;
  return (v9 + v6 + 1) >> 1;
}

// File Line: 433
// RVA: 0x126970
__int64 __fastcall ARandom::nose(ARandom *this, unsigned int limit)
{
  unsigned int v2; // r8d
  unsigned int v3; // r9d
  unsigned int v4; // eax
  unsigned int v5; // r8d
  int v6; // r9d
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx

  v2 = 1664525 * this->i_seed + 1013904223;
  v3 = 1664525 * v2 + 1013904223;
  this->i_seed = v3;
  v4 = (limit * (HIWORD(v2) + HIWORD(v3))) >> 16;
  if ( v4 >= limit )
    v5 = v4 - limit;
  else
    v5 = limit - v4 - 1;
  v6 = 1664525 * v3;
  v7 = 1664525 * (v6 + 1013904223) + 1013904223;
  this->i_seed = v7;
  v8 = (limit * (((unsigned int)(v6 + 1013904223) >> 16) + HIWORD(v7))) >> 16;
  if ( v8 >= limit )
    v9 = v8 - limit;
  else
    v9 = limit - v8 - 1;
  return (v9 + v5 + 1) >> 1;
}

// File Line: 662
// RVA: 0x13EA70
float __fastcall ARandom::up_slope(ARandom *this)
{
  unsigned int v1; // edx
  float result; // xmm0_4
  float v3; // [rsp+10h] [rbp+10h]

  v1 = 1664525 * (1664525 * this->i_seed + 1013904223);
  LODWORD(v3) = ((1664525 * this->i_seed + 1013904223) >> 9) | 0x3F800000;
  this->i_seed = v1 + 1013904223;
  result = (float)(COERCE_FLOAT(((v1 + 1013904223) >> 9) | 0x3F800000) + v3) - 2.0;
  if ( result >= 1.0 )
    return 2.0 - result;
  return result;
}

// File Line: 696
// RVA: 0x113C20
float __fastcall ARandom::down_slope(ARandom *this)
{
  unsigned int v1; // edx
  float v2; // xmm0_4
  float v4; // [rsp+10h] [rbp+10h]

  v1 = 1664525 * (1664525 * this->i_seed + 1013904223);
  LODWORD(v4) = ((1664525 * this->i_seed + 1013904223) >> 9) | 0x3F800000;
  this->i_seed = v1 + 1013904223;
  v2 = (float)(COERCE_FLOAT(((v1 + 1013904223) >> 9) | 0x3F800000) + v4) - 2.0;
  if ( v2 >= 1.0 )
    return v2 - 1.0;
  else
    return 1.0 - v2;
}

// File Line: 730
// RVA: 0x13CE40
float __fastcall ARandom::thorn(ARandom *this)
{
  unsigned int v1; // edx
  int v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v6; // [rsp+18h] [rbp+18h]

  v1 = 1664525 * (1664525 * this->i_seed + 1013904223) + 1013904223;
  LODWORD(v6) = ((1664525 * this->i_seed + 1013904223) >> 9) | 0x3F800000;
  v2 = (v1 >> 9) | 0x3F800000;
  v1 *= 1664525;
  this->i_seed = v1 + 1013904223;
  v3 = (float)(COERCE_FLOAT(((v1 + 1013904223) >> 9) | 0x3F800000) + *(float *)&v2) - 2.0;
  if ( v3 >= 1.0 )
    v4 = v3 - 1.0;
  else
    v4 = 1.0 - v3;
  return (float)((float)(v6 - 1.0) + v4) * 0.5;
}

// File Line: 753
// RVA: 0x126A10
float __fastcall ARandom::nose(ARandom *this)
{
  unsigned int v2; // ecx
  float v3; // xmm2_4
  float v4; // xmm1_4
  unsigned int v5; // ecx
  unsigned int v6; // eax
  float v7; // xmm2_4
  float v9; // [rsp+10h] [rbp+10h]

  LODWORD(v9) = ((1664525 * this->i_seed + 1013904223) >> 9) | 0x3F800000;
  v2 = 1664525 * (1664525 * this->i_seed + 1013904223) + 1013904223;
  this->i_seed = v2;
  v3 = (float)(COERCE_FLOAT((v2 >> 9) | 0x3F800000) + v9) - 2.0;
  if ( v3 >= 1.0 )
    v4 = v3 - 1.0;
  else
    v4 = 1.0 - v3;
  v5 = 1664525 * v2 + 1013904223;
  v6 = v5 >> 9;
  v5 *= 1664525;
  this->i_seed = v5 + 1013904223;
  v7 = (float)(COERCE_FLOAT(((v5 + 1013904223) >> 9) | 0x3F800000) + COERCE_FLOAT(v6 | 0x3F800000)) - 2.0;
  if ( v7 >= 1.0 )
    return (float)((float)(v7 - 1.0) + v4) * 0.5;
  else
    return (float)((float)(1.0 - v7) + v4) * 0.5;
}

