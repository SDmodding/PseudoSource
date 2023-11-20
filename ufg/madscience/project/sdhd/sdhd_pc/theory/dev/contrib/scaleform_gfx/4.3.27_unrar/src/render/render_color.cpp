// File Line: 48
// RVA: 0x95AEC0
Scaleform::Render::Color *__fastcall Scaleform::Render::Color::Blend(Scaleform::Render::Color *result, __int64 c1, __int64 c2, float f)
{
  result->Channels.Red = (signed int)(float)((float)((float)((float)((float)*(unsigned __int8 *)(c2 + 2)
                                                                   - (float)*(unsigned __int8 *)(c1 + 2))
                                                           * f)
                                                   + (float)*(unsigned __int8 *)(c1 + 2))
                                           + 0.5);
  result->Channels.Green = (signed int)(float)((float)((float)((float)((float)*(unsigned __int8 *)(c2 + 1)
                                                                     - (float)*(unsigned __int8 *)(c1 + 1))
                                                             * f)
                                                     + (float)*(unsigned __int8 *)(c1 + 1))
                                             + 0.5);
  result->Channels.Blue = (signed int)(float)((float)((float)((float)((float)*(unsigned __int8 *)c2
                                                                    - (float)*(unsigned __int8 *)c1)
                                                            * f)
                                                    + (float)*(unsigned __int8 *)c1)
                                            + 0.5);
  result->Channels.Alpha = (signed int)(float)((float)((float)((float)((float)*(unsigned __int8 *)(c2 + 3)
                                                                     - (float)*(unsigned __int8 *)(c1 + 3))
                                                             * f)
                                                     + (float)*(unsigned __int8 *)(c1 + 3))
                                             + 0.5);
  return result;
}

// File Line: 198
// RVA: 0x9B0790
void __fastcall Scaleform::Render::Color::SetHSV(Scaleform::Render::Color *this, int h, int s, int v)
{
  int v4; // ebp
  int v5; // er10
  char v6; // r11
  char v7; // bl
  int v8; // er8
  int v9; // er10
  unsigned int v10; // edx
  int v11; // er8
  int v12; // er8

  v4 = s;
  v5 = h;
  v6 = v;
  v7 = v;
  if ( !s || h <= -1 )
    goto LABEL_19;
  if ( h >= 360 )
    v5 = 360
       * (((unsigned int)(((unsigned __int64)(1240768329i64 * h) >> 32) - h) >> 31)
        + ((signed int)(((unsigned __int64)(1240768329i64 * h) >> 32) - h) >> 8))
       + h;
  v8 = v5 / 60;
  v9 = v5 % 60;
  if ( v8 & 1 )
  {
    v10 = (2 * v * (15300 - v4 * v9) + 15300) / 0x7788u;
    v11 = v8 - 1;
    if ( !v11 )
    {
      v6 = (2 * v * (15300 - v4 * v9) + 15300) / 0x7788u;
      LOBYTE(v) = (2 * v * (255 - v4) + 255) / 0x1FEu;
      goto LABEL_19;
    }
    v12 = v11 - 2;
    if ( v12 )
    {
      if ( v12 == 2 )
      {
        v7 = (2 * v * (255 - v4) + 255) / 0x1FEu;
        LOBYTE(v) = (2 * v * (15300 - v4 * v9) + 15300) / 0x7788u;
      }
      goto LABEL_19;
    }
    v6 = (2 * v * (255 - v4) + 255) / 0x1FEu;
LABEL_18:
    v7 = v10;
    goto LABEL_19;
  }
  v10 = (2 * v * (15300 - v4 * (60 - v9)) + 15300) / 0x7788u;
  switch ( v8 )
  {
    case 0:
      LOBYTE(v) = (2 * v * (255 - v4) + 255) / 0x1FEu;
      goto LABEL_18;
    case 2:
      v6 = (2 * v * (255 - v4) + 255) / 0x1FEu;
      LOBYTE(v) = (2 * v * (15300 - v4 * (60 - v9)) + 15300) / 0x7788u;
      break;
    case 4:
      v6 = (2 * v * (15300 - v4 * (60 - v9)) + 15300) / 0x7788u;
      v7 = (2 * v * (255 - v4) + 255) / 0x1FEu;
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
  Scaleform::Render::Color *v4; // rdx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  signed int v8; // ecx
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx

  v4 = this;
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
  v8 = (signed int)v7;
  v9 = (float)(1.0 - s) * v;
  v10 = v7 - (float)(signed int)v7;
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
  v4->Channels.Red = (signed int)(float)(v6 * 255.0);
  v4->Channels.Green = (signed int)(float)(v5 * 255.0);
  v4->Channels.Blue = (signed int)(float)(v * 255.0);
}

// File Line: 335
// RVA: 0x984F90
void __fastcall Scaleform::Render::Color::GetHSV(Scaleform::Render::Color *this, int *ph, int *ps, int *pv)
{
  unsigned int v4; // ebx
  unsigned int v5; // er11
  unsigned int v6; // er10
  signed int v7; // edi
  int *v8; // r14
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // er8
  unsigned int v12; // eax
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ecx

  v4 = (unsigned __int8)this->Channels.Red;
  v5 = (unsigned __int8)this->Channels.Green;
  v6 = (unsigned __int8)this->Channels.Blue;
  v7 = 0;
  v8 = ps;
  v9 = (unsigned __int8)this->Channels.Red;
  if ( v5 > v4 )
  {
    v9 = v5;
    v7 = 1;
  }
  if ( v6 > v9 )
  {
    v9 = v6;
    v7 = 2;
  }
  v10 = v4;
  if ( v5 < v4 )
    v10 = v5;
  *pv = v9;
  if ( v6 < v10 )
    v10 = v6;
  v11 = v9 - v10;
  if ( v9 )
    v12 = (v9 + 510 * v11) / (2 * v9);
  else
    v12 = 0;
  *v8 = v12;
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
      if ( (signed int)v4 <= (signed int)v5 )
        v15 = (signed int)(v11 + 120 * (v4 + v11 - v5)) / v14 + 180;
      else
        v15 = (signed int)(v11 + 120 * (v4 - v5)) / v14 + 240;
    }
    else
    {
      v16 = 2 * v11;
      if ( (signed int)v6 <= (signed int)v4 )
        v15 = (signed int)(v11 + 120 * (v6 + v11 - v4)) / v16 + 60;
      else
        v15 = (signed int)(v11 + 120 * (v6 - v4)) / v16 + 120;
    }
  }
  else
  {
    v17 = 2 * v11;
    if ( (signed int)v5 < (signed int)v6 )
      v15 = (signed int)(v11 + 120 * (v5 + v11 - v6)) / v17 + 300;
    else
      v15 = (signed int)(v11 + 120 * (v5 - v6)) / v17;
  }
  *ph = v15;
}

// File Line: 452
// RVA: 0x9850E0
void __fastcall Scaleform::Render::Color::GetHSV(Scaleform::Render::Color *this, float *ph, float *ps, float *pv)
{
  unsigned __int8 v4; // al
  float v5; // xmm1_4
  unsigned __int8 v6; // al
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4

  v4 = this->Channels.Red;
  if ( v4 )
    v5 = (float)v4 * 0.0039215689;
  else
    v5 = 0.0;
  v6 = this->Channels.Green;
  if ( v6 )
    v7 = (float)v6 * 0.0039215689;
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
  int *v4; // rsi
  int *v5; // rdi
  int *v6; // rbx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float pha; // [rsp+48h] [rbp+10h]
  float psa; // [rsp+50h] [rbp+18h]
  float pia; // [rsp+58h] [rbp+20h]

  v4 = pi;
  v5 = ps;
  v6 = ph;
  Scaleform::Render::Color::GetHSI(this, &pha, &psa, &pia);
  v7 = psa * 255.0;
  v8 = pia * 255.0;
  *v6 = (signed int)(float)(pha * 360.0);
  *v5 = (signed int)v7;
  *v4 = (signed int)v8;
}

// File Line: 516
// RVA: 0x9B06F0
void __fastcall Scaleform::Render::Color::SetHSI(Scaleform::Render::Color *this, float h, float s, float i)
{
  Scaleform::Render::Color *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm1_4
  signed int v7; // eax
  double v8; // xmm0_8
  long double pg; // [rsp+30h] [rbp-18h]
  long double pb; // [rsp+38h] [rbp-10h]
  long double pr; // [rsp+50h] [rbp+8h]

  v4 = this;
  Scaleform::Render::Color::ConvertHSIToRGB(h, s, i, &pr, &pg, &pb);
  v5 = pr;
  v6 = (float)pb * 255.0;
  v7 = (signed int)(float)(v5 * 255.0);
  v8 = pg;
  v4->Channels.Red = v7;
  v4->Channels.Green = (signed int)(float)((float)v8 * 255.0);
  v4->Channels.Blue = (signed int)v6;
}

// File Line: 550
// RVA: 0x984E00
void __fastcall Scaleform::Render::Color::GetHSI(Scaleform::Render::Color *this, float *ph, float *ps, float *pi)
{
  unsigned __int8 v4; // al
  float *v5; // rbx
  float *v6; // rdi
  float *v7; // rsi
  float v8; // xmm0_4
  __m128 v9; // xmm1
  unsigned __int8 v10; // al
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

  v4 = this->Channels.Red;
  v5 = pi;
  v6 = ps;
  v7 = ph;
  v8 = 0.0;
  if ( v4 )
  {
    v9 = (__m128)COERCE_UNSIGNED_INT((float)v4);
    v9.m128_f32[0] = v9.m128_f32[0] * 0.0039215689;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = this->Channels.Green;
  if ( v10 )
    v11 = (float)v10 * 0.0039215689;
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
    v15 = acos((v19 - v14) * 0.5 / COERCE_DOUBLE(_mm_sqrt_pd(v12)));
    if ( v13 <= v14 )
      v15 = 0.6366197723675814 - v15;
  }
  v20 = v15;
  v21 = v17;
  *v7 = v20;
  *v6 = v21;
  v22 = v16;
  *v5 = v22;
}

// File Line: 598
// RVA: 0x963740
void __fastcall Scaleform::Render::Color::ConvertRGBToHSI(long double r, long double g, long double b, long double *ph, long double *ps, long double *pi)
{
  double v6; // xmm7_8
  long double *v7; // rbx
  long double v8; // xmm6_8
  double v9; // xmm3_8
  double v10; // xmm1_8
  double v11; // xmm6_8
  double v12; // xmm9_8

  v6 = g;
  v7 = ph;
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
    if ( r >= v6 )
      r = v6;
    if ( r >= b )
      r = b;
    v12 = 1.0 - r / v11;
  }
  if ( v9 != v6 || v6 != b )
  {
    v10 = acos((v9 - v6 + v9 - b) * 0.5 / sqrt((v9 - b) * (v6 - b) + (v9 - v6) * (v9 - v6)));
    if ( v6 <= b )
      v10 = 0.6366197723675814 - v10;
  }
  *v7 = v10;
  *ps = v12;
  *pi = v11;
}

// File Line: 620
// RVA: 0x963090
void __fastcall Scaleform::Render::Color::ConvertHSIToRGB(long double h, long double s, long double i, long double *pr, long double *pg, long double *pb)
{
  long double *v6; // rbx
  double v7; // xmm3_8
  double v8; // xmm4_8
  double v9; // xmm5_8
  long double v10; // xmm0_8
  long double v11; // xmm0_8
  long double v12; // xmm0_8
  long double v13; // xmm0_8
  long double v14; // xmm0_8

  v6 = pr;
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
      v10 = tan(h - 1.047197551196598) / COERCE_DOUBLE(_mm_sqrt_pd((__m128d)*(unsigned __int64 *)&DOUBLE_3_0)) * 1.5;
      v8 = (v10 + 1.5) * i - (v10 + 0.5) * v7;
      v9 = i * 3.0 - v8 - v7;
      goto LABEL_10;
    }
    if ( h < 4.188790204786391 )
    {
      v11 = tan(h - 3.141592653589793);
      v9 = (1.0 - s) * i;
      v12 = v11 / COERCE_DOUBLE(_mm_sqrt_pd((__m128d)*(unsigned __int64 *)&DOUBLE_3_0)) * 1.5;
      v7 = (v12 + 1.5) * i - (v12 + 0.5) * v9;
      v8 = i * 3.0 - v7 - v9;
      goto LABEL_10;
    }
LABEL_9:
    v13 = tan(h - 5.235987755982989);
    v8 = (1.0 - s) * i;
    v14 = v13 / COERCE_DOUBLE(_mm_sqrt_pd((__m128d)*(unsigned __int64 *)&DOUBLE_3_0)) * 1.5;
    v9 = (v14 + 1.5) * i - (v14 + 0.5) * v8;
    v7 = i * 3.0 - v9 - v8;
    goto LABEL_10;
  }
  v7 = i;
  v8 = i;
  v9 = i;
LABEL_10:
  *v6 = v9;
  *pg = v8;
  *pb = v7;
}

