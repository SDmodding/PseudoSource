// File Line: 48
// RVA: 0x95AEC0
Scaleform::Render::Color *__fastcall Scaleform::Render::Color::Blend(
        Scaleform::Render::Color *result,
        unsigned __int8 *c1,
        unsigned __int8 *c2,
        float f)
{
  result->Channels.Red = (int)(float)((float)((float)((float)((float)c2[2] - (float)c1[2]) * f) + (float)c1[2]) + 0.5);
  result->Channels.Green = (int)(float)((float)((float)((float)((float)c2[1] - (float)c1[1]) * f) + (float)c1[1]) + 0.5);
  result->Channels.Blue = (int)(float)((float)((float)((float)((float)*c2 - (float)*c1) * f) + (float)*c1) + 0.5);
  result->Channels.Alpha = (int)(float)((float)((float)((float)((float)c2[3] - (float)c1[3]) * f) + (float)c1[3]) + 0.5);
  return result;
}

// File Line: 198
// RVA: 0x9B0790
void __fastcall Scaleform::Render::Color::SetHSV(Scaleform::Render::Color *this, int h, int s, int v)
{
  int v5; // r10d
  char v6; // r11
  char v7; // bl
  int v8; // r8d
  int v9; // r10d
  unsigned int v10; // edx
  int v11; // r8d
  int v12; // r8d

  v5 = h;
  v6 = v;
  v7 = v;
  if ( !s || h <= -1 )
    goto LABEL_19;
  if ( h >= 360 )
    v5 = 360
       * (((unsigned int)(((unsigned __int64)(1240768329i64 * h) >> 32) - h) >> 31)
        + ((int)(((unsigned __int64)(1240768329i64 * h) >> 32) - h) >> 8))
       + h;
  v8 = v5 / 60;
  v9 = v5 % 60;
  if ( (v8 & 1) != 0 )
  {
    v10 = (2 * v * (15300 - s * v9) + 15300) / 0x7788u;
    v11 = v8 - 1;
    if ( !v11 )
    {
      v6 = (2 * v * (15300 - s * v9) + 15300) / 0x7788u;
      LOBYTE(v) = (2 * v * (255 - s) + 255) / 0x1FEu;
      goto LABEL_19;
    }
    v12 = v11 - 2;
    if ( v12 )
    {
      if ( v12 == 2 )
      {
        v7 = (2 * v * (255 - s) + 255) / 0x1FEu;
        LOBYTE(v) = (2 * v * (15300 - s * v9) + 15300) / 0x7788u;
      }
      goto LABEL_19;
    }
    v6 = (2 * v * (255 - s) + 255) / 0x1FEu;
LABEL_18:
    v7 = v10;
    goto LABEL_19;
  }
  v10 = (2 * v * (15300 - s * (60 - v9)) + 15300) / 0x7788u;
  switch ( v8 )
  {
    case 0:
      LOBYTE(v) = (2 * v * (255 - s) + 255) / 0x1FEu;
      goto LABEL_18;
    case 2:
      v6 = (2 * v * (255 - s) + 255) / 0x1FEu;
      LOBYTE(v) = (2 * v * (15300 - s * (60 - v9)) + 15300) / 0x7788u;
      break;
    case 4:
      v6 = (2 * v * (15300 - s * (60 - v9)) + 15300) / 0x7788u;
      v7 = (2 * v * (255 - s) + 255) / 0x1FEu;
      break;
  }
LABEL_19:
  this->Channels.Green = v7;
  this->Channels.Red = v6;
  this->Channels.Blue = v;
}

// File Line: 273
// RVA: 0x9B08E0
void __fastcall Scaleform::Render::Color::SetHSV(Scaleform::Render::Color *this, float h, float s, float v)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  int v8; // ecx
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx

  if ( s == 0.0 )
  {
    v5 = v;
    v6 = v;
    goto $convert_rgb;
  }
  if ( h == 1.0 )
    v7 = 0.0;
  else
    v7 = h * 6.0;
  v8 = (int)v7;
  v9 = (float)(1.0 - s) * v;
  v10 = v7 - (float)(int)v7;
  v11 = (float)(1.0 - (float)(v10 * s)) * v;
  v12 = (float)(1.0 - (float)((float)(1.0 - v10) * s)) * v;
  if ( !v8 )
  {
    v6 = v;
    v5 = v12;
    goto LABEL_17;
  }
  v13 = v8 - 1;
  if ( !v13 )
  {
    v6 = (float)(1.0 - (float)(v10 * s)) * v;
    v5 = v;
LABEL_17:
    v = v9;
    goto $convert_rgb;
  }
  v14 = v13 - 1;
  if ( v14 )
  {
    v15 = v14 - 1;
    if ( v15 )
    {
      v5 = (float)(1.0 - s) * v;
      if ( v15 == 1 )
      {
        v6 = v12;
      }
      else
      {
        v6 = v;
        v = v11;
      }
    }
    else
    {
      v6 = (float)(1.0 - s) * v;
      v5 = v11;
    }
  }
  else
  {
    v5 = v;
    v6 = (float)(1.0 - s) * v;
    v = v12;
  }
$convert_rgb:
  this->Channels.Red = (int)(float)(v6 * 255.0);
  this->Channels.Green = (int)(float)(v5 * 255.0);
  this->Channels.Blue = (int)(float)(v * 255.0);
}

// File Line: 335
// RVA: 0x984F90
void __fastcall Scaleform::Render::Color::GetHSV(
        Scaleform::Render::Color *this,
        int *ph,
        unsigned int *ps,
        unsigned int *pv)
{
  unsigned int Red; // ebx
  unsigned int Green; // r11d
  unsigned int Blue; // r10d
  int v7; // edi
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // r8d
  unsigned int v12; // eax
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ecx

  Red = (unsigned __int8)this->Channels.Red;
  Green = (unsigned __int8)this->Channels.Green;
  Blue = (unsigned __int8)this->Channels.Blue;
  v7 = 0;
  v9 = Red;
  if ( Green > Red )
  {
    v9 = Green;
    v7 = 1;
  }
  if ( Blue > v9 )
  {
    v9 = Blue;
    v7 = 2;
  }
  v10 = Red;
  if ( Green < Red )
    v10 = Green;
  *pv = v9;
  if ( Blue < v10 )
    v10 = Blue;
  v11 = v9 - v10;
  if ( v9 )
    v12 = (v9 + 510 * v11) / (2 * v9);
  else
    v12 = 0;
  *ps = v12;
  if ( !v12 )
  {
    *ph = 0;
    return;
  }
  if ( v7 )
  {
    v13 = v7 - 1;
    if ( v13 )
    {
      if ( v13 != 1 )
        return;
      v14 = 2 * v11;
      if ( (int)Red <= (int)Green )
        v15 = (int)(v11 + 120 * (Red + v11 - Green)) / v14 + 180;
      else
        v15 = (int)(v11 + 120 * (Red - Green)) / v14 + 240;
    }
    else
    {
      v16 = 2 * v11;
      if ( (int)Blue <= (int)Red )
        v15 = (int)(v11 + 120 * (Blue + v11 - Red)) / v16 + 60;
      else
        v15 = (int)(v11 + 120 * (Blue - Red)) / v16 + 120;
    }
  }
  else
  {
    v17 = 2 * v11;
    if ( (int)Green < (int)Blue )
      v15 = (int)(v11 + 120 * (Green + v11 - Blue)) / v17 + 300;
    else
      v15 = (int)(v11 + 120 * (Green - Blue)) / v17;
  }
  *ph = v15;
}

// File Line: 452
// RVA: 0x9850E0
void __fastcall Scaleform::Render::Color::GetHSV(Scaleform::Render::Color *this, float *ph, float *ps, float *pv)
{
  unsigned __int8 Red; // al
  float v5; // xmm1_4
  unsigned __int8 Green; // al
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4

  Red = this->Channels.Red;
  if ( Red )
    v5 = (float)Red * 0.0039215689;
  else
    v5 = 0.0;
  Green = this->Channels.Green;
  if ( Green )
    v7 = (float)Green * 0.0039215689;
  else
    v7 = 0.0;
  if ( this->Channels.Blue )
    v8 = (float)(unsigned __int8)this->Channels.Blue * 0.0039215689;
  else
    v8 = 0.0;
  if ( v7 >= v8 )
    v9 = v8;
  else
    v9 = v7;
  if ( v5 < v9 )
    v9 = v5;
  if ( v8 >= v7 )
    v10 = v8;
  else
    v10 = v7;
  if ( v10 < v5 )
    v10 = v5;
  *pv = v10;
  v11 = v10 - v9;
  if ( v10 == 0.0 )
  {
    *ps = 0.0;
    *ph = 0.0;
  }
  else
  {
    *ps = v11 / v10;
    if ( (float)(v11 / v10) == 0.0 )
    {
      *ph = 0.0;
    }
    else
    {
      if ( v5 == v10 )
      {
        *ph = (float)(v7 - v8) / v11;
      }
      else if ( v7 == v10 )
      {
        *ph = (float)((float)(v8 - v5) / v11) + 2.0;
      }
      else
      {
        *ph = (float)((float)(v5 - v7) / v11) + 4.0;
      }
      v12 = *ph * 0.16666667;
      *ph = v12;
      if ( v12 < 0.0 )
        *ph = v12 + 1.0;
      if ( *ph > 1.0 )
        *ph = *ph - 1.0;
    }
  }
}

// File Line: 499
// RVA: 0x9B06B0
void __fastcall Scaleform::Render::Color::SetHSI(Scaleform::Render::Color *this, int h, int s, int i)
{
  Scaleform::Render::Color::SetHSI(this, (float)h * 0.0027777778, (float)s * 0.0039215689, (float)i * 0.0039215689);
}

// File Line: 507
// RVA: 0x984D90
void __fastcall Scaleform::Render::Color::GetHSI(Scaleform::Render::Color *this, int *ph, int *ps, int *pi)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  float pha; // [rsp+48h] [rbp+10h] BYREF
  float psa; // [rsp+50h] [rbp+18h] BYREF
  float pia; // [rsp+58h] [rbp+20h] BYREF

  Scaleform::Render::Color::GetHSI(this, &pha, &psa, &pia);
  v7 = psa * 255.0;
  v8 = pia * 255.0;
  *ph = (int)(float)(pha * 360.0);
  *ps = (int)v7;
  *pi = (int)v8;
}

// File Line: 516
// RVA: 0x9B06F0
void __fastcall Scaleform::Render::Color::SetHSI(Scaleform::Render::Color *this, float h, float s, float i)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  int v7; // eax
  double v8; // xmm0_8
  long double pg; // [rsp+30h] [rbp-18h] BYREF
  long double pb[2]; // [rsp+38h] [rbp-10h] BYREF
  long double pr; // [rsp+50h] [rbp+8h] BYREF

  Scaleform::Render::Color::ConvertHSIToRGB(h, s, i, &pr, &pg, pb);
  v5 = pr;
  v6 = (float)pb[0] * 255.0;
  v7 = (int)(float)(v5 * 255.0);
  v8 = pg;
  this->Channels.Red = v7;
  this->Channels.Green = (int)(float)((float)v8 * 255.0);
  this->Channels.Blue = (int)v6;
}

// File Line: 550
// RVA: 0x984E00
void __fastcall Scaleform::Render::Color::GetHSI(Scaleform::Render::Color *this, float *ph, float *ps, float *pi)
{
  unsigned __int8 Red; // al
  float v8; // xmm0_4
  __m128 v9; // xmm1
  unsigned __int8 Green; // al
  float v11; // xmm2_4
  __m128d v12; // xmm3
  double v13; // xmm7_8
  double v14; // xmm8_8
  double v15; // xmm1_8
  double v16; // xmm6_8
  double v17; // xmm9_8
  double v18; // xmm0_8
  long double v19; // xmm2_8
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4

  Red = this->Channels.Red;
  v8 = 0.0;
  if ( Red )
  {
    v9 = (__m128)COERCE_UNSIGNED_INT((float)Red);
    v9.m128_f32[0] = v9.m128_f32[0] * 0.0039215689;
  }
  else
  {
    v9 = 0i64;
  }
  Green = this->Channels.Green;
  if ( Green )
    v11 = (float)Green * 0.0039215689;
  else
    v11 = 0.0;
  if ( this->Channels.Blue )
    v8 = (float)(unsigned __int8)this->Channels.Blue * 0.0039215689;
  v12 = _mm_cvtps_pd(v9);
  v13 = v11;
  v14 = v8;
  v15 = 0.0;
  v16 = (v12.m128d_f64[0] + v11 + v8) * 0.3333333333333333;
  if ( v16 == 0.0 )
  {
    v17 = DOUBLE_1_0;
  }
  else
  {
    if ( v12.m128d_f64[0] >= v13 )
      v18 = v11;
    else
      v18 = v12.m128d_f64[0];
    if ( v18 >= v14 )
      v18 = v14;
    v17 = 1.0 - v18 / v16;
  }
  if ( v12.m128d_f64[0] != v13 || v13 != v14 )
  {
    v19 = v12.m128d_f64[0] - v13 + v12.m128d_f64[0];
    v12.m128d_f64[0] = (v12.m128d_f64[0] - v14) * (v13 - v14) + (v12.m128d_f64[0] - v13) * (v12.m128d_f64[0] - v13);
    v15 = acos((v19 - v14) * 0.5 / _mm_sqrt_pd(v12).m128d_f64[0]);
    if ( v13 <= v14 )
      v15 = 0.6366197723675814 - v15;
  }
  v20 = v15;
  v21 = v17;
  *ph = v20;
  *ps = v21;
  v22 = v16;
  *pi = v22;
}

// File Line: 598
// RVA: 0x963740
void __fastcall Scaleform::Render::Color::ConvertRGBToHSI(
        double r,
        double g,
        double b,
        long double *ph,
        long double *ps,
        long double *pi)
{
  long double v8; // xmm6_8
  double v9; // xmm3_8
  double v10; // xmm1_8
  double v11; // xmm6_8
  double v12; // xmm9_8

  v8 = r + g;
  v9 = r;
  v10 = 0.0;
  v11 = (v8 + b) * 0.3333333333333333;
  if ( v11 == 0.0 )
  {
    v12 = DOUBLE_1_0;
  }
  else
  {
    if ( r >= g )
      r = g;
    if ( r >= b )
      r = b;
    v12 = 1.0 - r / v11;
  }
  if ( v9 != g || g != b )
  {
    v10 = acos((v9 - g + v9 - b) * 0.5 / sqrt((v9 - b) * (g - b) + (v9 - g) * (v9 - g)));
    if ( g <= b )
      v10 = 0.6366197723675814 - v10;
  }
  *ph = v10;
  *ps = v12;
  *pi = v11;
}

// File Line: 620
// RVA: 0x963090
void __fastcall Scaleform::Render::Color::ConvertHSIToRGB(
        double h,
        long double s,
        double i,
        long double *pr,
        long double *pg,
        long double *pb)
{
  double v7; // xmm3_8
  double v8; // xmm4_8
  double v9; // xmm5_8
  long double v10; // xmm4_8
  long double v11; // xmm0_8
  long double v12; // xmm3_8
  long double v13; // xmm0_8
  long double v14; // xmm5_8

  if ( h != 0.0 )
  {
    if ( h <= 0.0 )
    {
      if ( h < 2.094395102393196 )
        goto LABEL_9;
    }
    else if ( h < 2.094395102393196 )
    {
      v7 = (1.0 - s) * i;
      v10 = tan(h - 1.047197551196598) / _mm_sqrt_pd((__m128d)*(unsigned __int64 *)&DOUBLE_3_0).m128d_f64[0] * 1.5;
      v8 = (v10 + 1.5) * i - (v10 + 0.5) * v7;
      v9 = i * 3.0 - v8 - v7;
      goto LABEL_10;
    }
    if ( h < 4.188790204786391 )
    {
      v11 = tan(h - 3.141592653589793);
      v9 = (1.0 - s) * i;
      v12 = v11 / _mm_sqrt_pd((__m128d)*(unsigned __int64 *)&DOUBLE_3_0).m128d_f64[0] * 1.5;
      v7 = (v12 + 1.5) * i - (v12 + 0.5) * v9;
      v8 = i * 3.0 - v7 - v9;
      goto LABEL_10;
    }
LABEL_9:
    v13 = tan(h - 5.235987755982989);
    v8 = (1.0 - s) * i;
    v14 = v13 / _mm_sqrt_pd((__m128d)*(unsigned __int64 *)&DOUBLE_3_0).m128d_f64[0] * 1.5;
    v9 = (v14 + 1.5) * i - (v14 + 0.5) * v8;
    v7 = i * 3.0 - v9 - v8;
    goto LABEL_10;
  }
  v7 = i;
  v8 = i;
  v9 = i;
LABEL_10:
  *pr = v9;
  *pg = v8;
  *pb = v7;
}

