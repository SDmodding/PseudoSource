// File Line: 59
// RVA: 0xB0A2A0
void __fastcall CoefficientCalculator::CalculateBypassed(SCoefs *outCoefs)
{
  outCoefs->a0 = 1.0;
  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 0.0;
  outCoefs->b2 = 0.0;
}

// File Line: 71
// RVA: 0xB0A2D0
void __fastcall CoefficientCalculator::CalculateParametric(unsigned int sampleRate, long double frequency, long double q, long double gain, SCoefs *outCoefs)
{
  double v5; // xmm7_8
  long double v6; // xmm0_8
  double v7; // xmm11_8
  double v8; // xmm9_8
  double v9; // xmm12_8
  double v10; // xmm0_8
  double v11; // xmm8_8
  double v12; // xmm10_8
  double v13; // xmm4_8
  double v14; // xmm5_8
  double v15; // xmm5_8
  double v16; // xmm9_8
  double v17; // xmm10_8
  double v18; // xmm6_8

  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v5 = frequency / (double)(signed int)sampleRate;
  if ( v5 >= 0.0002083333333333333 )
  {
    if ( v5 > 0.4583333333333333 )
      v5 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v5 = DOUBLE_0_0002083333333333333;
  }
  v6 = tan(v5 * 3.141592653589793);
  v7 = v6;
  v8 = (v6 + 1.0) * (1.0 / q);
  v9 = v6 * v6;
  v10 = pow(10.0, gain * 0.05);
  *(_QWORD *)&v11 = COERCE_UNSIGNED_INT64(gain * 0.08333333333333333) & _xmm;
  if ( v10 < 1.0 )
  {
    v12 = v8;
    v13 = DOUBLE_1_0;
    v15 = v5 * (1.0 / v10 * v8);
    v8 = 1.0 / v10 * v8;
    v14 = (v15 + 1.0 - v5) * v11 + 1.0 - v11;
    if ( v14 < 1.0 )
      v14 = DOUBLE_1_0;
    if ( v14 > 1.0 / v10 )
      v14 = 1.0 / v10;
  }
  else
  {
    v12 = v10 * v8;
    v13 = (v5 * (v10 * v8) + 1.0 - v5) * v11 + 1.0 - v11;
    if ( v13 < 1.0 )
      v13 = DOUBLE_1_0;
    if ( v13 > v10 )
      v13 = v10;
    v14 = DOUBLE_1_0;
  }
  v16 = v8 * v7;
  v17 = v12 * v7;
  outCoefs->b0 = 1.0;
  v18 = 1.0 / (v16 + v14 + v9);
  outCoefs->a0 = (v17 + v13 + v9) * v18;
  outCoefs->a2 = (v13 - v17 + v9) * v18;
  outCoefs->a1 = (v9 * 2.0 - v13 * 2.0) * v18;
  outCoefs->b1 = (v9 * 2.0 - v14 * 2.0) * v18;
  outCoefs->b2 = (v14 - v16 + v9) * v18;
}

// File Line: 132
// RVA: 0xB0A540
void __fastcall CoefficientCalculator::CalculateFirstOrderHighPass(unsigned int sampleRate, long double frequency, SCoefs *outCoefs)
{
  SCoefs *v3; // rbx
  double v4; // xmm1_8
  long double v5; // xmm0_8
  long double v6; // xmm4_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v3 = outCoefs;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v4 = frequency / (double)(signed int)sampleRate;
  if ( v4 >= 0.0002083333333333333 )
  {
    if ( v4 > 0.4583333333333333 )
      v4 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v4 = DOUBLE_0_0002083333333333333;
  }
  v5 = tan(v4 * 3.141592653589793);
  v3->b0 = 1.0;
  v6 = 1.0 / (v5 + 1.0);
  v3->a0 = v6;
  v3->b1 = (v5 - 1.0) * v6;
  v3->a1 = v6 * -1.0;
  v3->a2 = v6 * 0.0;
  v3->b2 = v6 * 0.0;
}

// File Line: 153
// RVA: 0xB0A620
void __fastcall CoefficientCalculator::CalculateSecondOrderHighPass(unsigned int sampleRate, long double frequency, long double peak, SCoefs *outCoefs)
{
  SCoefs *v4; // rbx
  double v5; // xmm1_8
  long double v6; // xmm0_8
  long double v7; // xmm4_8
  long double v8; // xmm2_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v4 = outCoefs;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v5 = frequency / (double)(signed int)sampleRate;
  if ( v5 >= 0.0002083333333333333 )
  {
    if ( v5 > 0.4583333333333333 )
      v5 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v5 = DOUBLE_0_0002083333333333333;
  }
  v6 = tan(v5 * 3.141592653589793);
  v4->b0 = 1.0;
  v7 = v6 * peak;
  v8 = 1.0 / (v6 * peak + 1.0 + v6 * v6);
  v4->a0 = v8;
  v4->a2 = v8;
  v4->b2 = (1.0 - v7 + v6 * v6) * v8;
  v4->a1 = v8 * -2.0;
  v4->b1 = (v6 * v6 * 2.0 - 2.0) * v8;
}

// File Line: 174
// RVA: 0xB0A730
void __fastcall CoefficientCalculator::CalculateFirstOrderLowPass(unsigned int sampleRate, long double frequency, SCoefs *outCoefs)
{
  SCoefs *v3; // rbx
  double v4; // xmm1_8
  long double v5; // xmm0_8
  long double v6; // xmm5_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v3 = outCoefs;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v4 = frequency / (double)(signed int)sampleRate;
  if ( v4 >= 0.0002083333333333333 )
  {
    if ( v4 > 0.4583333333333333 )
      v4 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v4 = DOUBLE_0_0002083333333333333;
  }
  v5 = tan(v4 * 3.141592653589793);
  v3->b0 = 1.0;
  v6 = 1.0 / (v5 + 1.0);
  v3->a0 = v6 * v5;
  v3->a1 = v6 * v5;
  v3->a2 = v6 * 0.0;
  v3->b2 = v6 * 0.0;
  v3->b1 = (v5 - 1.0) * v6;
}

// File Line: 193
// RVA: 0xB0ADB0
float __fastcall CoefficientCalculator::CalculateDecayTime(BiquadCoefficients *in_coeffs)
{
  __m128 v1; // xmm3
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4

  v1 = (__m128)LODWORD(in_coeffs->b1);
  v2 = v1;
  v2.m128_f32[0] = v1.m128_f32[0] * v1.m128_f32[0];
  v3 = v2;
  v3.m128_f32[0] = (float)(v1.m128_f32[0] * v1.m128_f32[0]) - (float)(in_coeffs->b2 * 4.0);
  if ( v3.m128_f32[0] >= 0.0 )
  {
    LODWORD(v5) = (unsigned __int128)_mm_sqrt_ps(v3);
    v6 = COERCE_FLOAT(v1.m128_i32[0] ^ _xmm[0]) - v5;
    LODWORD(v7) = COERCE_UNSIGNED_INT(v5 - v1.m128_f32[0]) & _xmm;
    LODWORD(v4) = LODWORD(v6) & _xmm;
    if ( v4 <= v7 )
      v4 = v7;
  }
  else
  {
    v2.m128_f32[0] = v2.m128_f32[0] - v3.m128_f32[0];
    LODWORD(v4) = (unsigned __int128)_mm_sqrt_ps(v2);
  }
  return 1.0 / (float)(1.0 - (float)(v4 * 0.5));
}

// File Line: 217
// RVA: 0xB0A800
void __fastcall CoefficientCalculator::CalculateSecondOrderLowPass(unsigned int sampleRate, long double frequency, long double peak, SCoefs *outCoefs)
{
  SCoefs *v4; // rbx
  double v5; // xmm1_8
  long double v6; // xmm0_8
  long double v7; // xmm6_8
  long double v8; // xmm3_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v4 = outCoefs;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v5 = frequency / (double)(signed int)sampleRate;
  if ( v5 >= 0.0002083333333333333 )
  {
    if ( v5 > 0.4583333333333333 )
      v5 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v5 = DOUBLE_0_0002083333333333333;
  }
  v6 = tan(v5 * 3.141592653589793);
  v4->b0 = 1.0;
  v7 = v6 * v6 * 2.0;
  v8 = 1.0 / (v6 * peak + 1.0 + v6 * v6);
  v4->b1 = (v7 - 2.0) * v8;
  v4->a1 = v7 * v8;
  v4->b2 = (1.0 - v6 * peak + v6 * v6) * v8;
  v4->a0 = v8 * (v6 * v6);
  v4->a2 = v8 * (v6 * v6);
}

// File Line: 239
// RVA: 0xB0A930
void __fastcall CoefficientCalculator::CalculateDualHPFAndLPF(unsigned int sampleRate, long double hpFrequency, long double lpFrequency, SCoefs *outCoefs)
{
  SCoefs *v4; // rdi
  unsigned int v5; // ebx
  double v6; // xmm5_8
  double v7; // xmm2_8
  double v8; // xmm0_8
  long double v9; // xmm0_8
  long double v10; // xmm3_8
  long double v11; // xmm3_8
  double v12; // xmm0_8
  long double v13; // xmm2_8
  long double v14; // xmm0_8
  SCoefs v15; // [rsp+20h] [rbp-78h]
  SCoefs outCoefsa; // [rsp+50h] [rbp-48h]

  v4 = outCoefs;
  v5 = sampleRate;
  CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, hpFrequency, &outCoefsa);
  CoefficientCalculator::CalculateFirstOrderLowPass(v5, lpFrequency, &v15);
  v6 = outCoefsa.a1;
  v7 = v15.b1;
  v8 = v15.a0;
  v4->b0 = 1.0;
  v4->a0 = v8 * outCoefsa.a0;
  v9 = v15.a1 * outCoefsa.a0;
  v10 = v6 * v15.a0;
  v4->a2 = v6 * v15.a1;
  v11 = v10 + v9;
  v12 = v7;
  v13 = v7 * outCoefsa.b1;
  v14 = v12 + outCoefsa.b1;
  v4->a1 = v11;
  v4->b1 = v14;
  v4->b2 = v13;
}

// File Line: 258
// RVA: 0xB0AA00
void __fastcall CoefficientCalculator::CalculateGParametric(unsigned int sampleRate, long double frequency, long double q, long double gain, SCoefs *outCoefs)
{
  double v5; // xmm7_8
  long double v6; // xmm0_8
  double v7; // xmm11_8
  double v8; // xmm8_8
  double v9; // xmm12_8
  double v10; // xmm0_8
  double v11; // xmm9_8
  double v12; // xmm4_8
  double v13; // xmm5_8
  double v14; // xmm8_8
  double v15; // xmm9_8
  double v16; // xmm6_8

  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v5 = frequency / (double)(signed int)sampleRate;
  if ( v5 >= 0.0002083333333333333 )
  {
    if ( v5 > 0.4583333333333333 )
      v5 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v5 = DOUBLE_0_0002083333333333333;
  }
  v6 = tan(v5 * 3.141592653589793);
  v7 = v6;
  v8 = (v6 + 1.0) * (1.0 / q);
  v9 = v6 * v6;
  v10 = pow(10.0, gain * 0.05);
  if ( v10 < 1.0 )
  {
    v11 = v8;
    v12 = DOUBLE_1_0;
    v8 = 1.0 / v10 * v8;
    v13 = (v5 * v8 + 1.0 - v5) * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm)
        + 1.0
        - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm);
    if ( v13 < 1.0 )
      v13 = DOUBLE_1_0;
    if ( v13 > 1.0 / v10 )
      v13 = 1.0 / v10;
  }
  else
  {
    v11 = v10 * v8;
    v12 = (v5 * (v10 * v8) + 1.0 - v5) * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm)
        + 1.0
        - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm);
    if ( v12 < 1.0 )
      v12 = DOUBLE_1_0;
    if ( v12 > v10 )
      v12 = v10;
    v13 = DOUBLE_1_0;
  }
  v14 = v8 * v7;
  v15 = v11 * v7;
  outCoefs->b0 = 1.0;
  v16 = 1.0 / (v14 + v13 + v9);
  outCoefs->a0 = (v15 + v12 + v9) * v16;
  outCoefs->a2 = (v12 - v15 + v9) * v16;
  outCoefs->a1 = (v9 * 2.0 - v12 * 2.0) * v16;
  outCoefs->b1 = (v9 * 2.0 - v13 * 2.0) * v16;
  outCoefs->b2 = (v13 - v14 + v9) * v16;
}

// File Line: 345
// RVA: 0xB0AC80
void __fastcall CoefficientCalculator::CalculatePostGLowShelf(unsigned int sampleRate, long double frequency, long double slope, long double gain, SCoefs *outCoefs)
{
  long double v5; // xmm6_8
  unsigned int v6; // ebx
  long double v7; // xmm3_8

  v5 = gain;
  v6 = sampleRate;
  v7 = pow(slope, 0.25) * 100.0 * -0.016;
  CalculationFirstSecondMixLowShelfInSDomain(v6, frequency, 0.85, v7, -0.0, v5, 1, 0, 1.0, outCoefs);
}

// File Line: 358
// RVA: 0xB0AD20
void __fastcall CoefficientCalculator::CalculatePostGHighShelf(unsigned int sampleRate, long double frequency, long double slope, long double gain, SCoefs *outCoefs)
{
  long double v5; // xmm6_8
  unsigned int v6; // ebx
  double v7; // xmm3_8

  v5 = gain;
  v6 = sampleRate;
  v7 = pow(slope, 0.25);
  CalculationFirstSecondMixHighShelfInSDomain(v6, frequency, 0.85, v7 * 100.0 * -0.016, -0.0, v5, 1, 0, outCoefs);
}

// File Line: 367
// RVA: 0xB0AE30
void __fastcall InitCoefficientValues(SCoefs *outCoefs)
{
  outCoefs->a0 = 1.0;
  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  outCoefs->b2 = 0.0;
}

// File Line: 381
// RVA: 0xB0AE60
void __fastcall PrepareOmegaValues(unsigned int sampleRate, long double frequency, long double *outFlippedFrequency, long double *outWc, long double *outWcSqrd)
{
  long double *v5; // rbx
  double v6; // xmm1_8
  long double v7; // xmm0_8

  v5 = outWc;
  v6 = frequency / (double)(signed int)sampleRate;
  if ( v6 >= 0.0002083333333333333 )
  {
    if ( v6 > 0.4583333333333333 )
      v6 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v6 = DOUBLE_0_0002083333333333333;
  }
  *outFlippedFrequency = v6;
  v7 = tan(v6 * 3.141592653589793);
  *v5 = v7;
  *outWcSqrd = v7 * v7;
}

// File Line: 405
// RVA: 0xB0AED0
void __fastcall NormalizeCoefficientValues(SCoefs *outCoefs)
{
  long double v1; // xmm2_8
  long double v2; // xmm1_8
  long double v3; // xmm0_8
  long double v4; // xmm1_8
  long double v5; // xmm2_8

  v1 = 1.0 / outCoefs->b0;
  outCoefs->b0 = 1.0;
  v2 = v1 * outCoefs->a1;
  outCoefs->a0 = v1 * outCoefs->a0;
  outCoefs->a1 = v2;
  v3 = v1 * outCoefs->a2;
  v4 = v1 * outCoefs->b1;
  v5 = v1 * outCoefs->b2;
  outCoefs->a2 = v3;
  outCoefs->b1 = v4;
  outCoefs->b2 = v5;
}

// File Line: 420
// RVA: 0xB0AF30
void __fastcall CalculationFirstSecondMixLowShelfInSDomain(unsigned int sampleRate, long double frequency, long double slope, long double dipDelta, long double peakDelta, long double gain, bool normalizeCoefs, bool scalePeakDip, long double spread, SCoefs *outCoefs)
{
  double v10; // xmm14_8
  double v11; // xmm6_8
  double v12; // xmm7_8
  double v13; // xmm6_8
  double v14; // xmm11_8
  double v15; // xmm0_8
  double v16; // xmm12_8
  double v17; // xmm8_8
  double v18; // xmm10_8
  double v19; // xmm13_8
  double v20; // xmm9_8
  double v21; // xmm0_8
  __m128d v22; // xmm11
  double v23; // xmm0_8
  double v24; // xmm15_8
  double v25; // xmm2_8
  bool v26; // cf
  bool v27; // zf
  double v28; // xmm7_8
  double v29; // xmm4_8
  double v30; // xmm11_8
  double v31; // xmm5_8
  double v32; // xmm4_8
  double v33; // xmm1_8
  double v34; // xmm2_8
  double v35; // xmm15_8
  double v36; // xmm4_8
  double v37; // xmm0_8
  double v38; // xmm5_8
  double v39; // xmm12_8
  double v40; // xmm8_8
  double v41; // xmm15_8
  double v42; // xmm10_8
  double v43; // xmm3_8
  double v44; // xmm14_8
  double v45; // xmm9_8
  double peakDeltaa; // [rsp+F0h] [rbp+28h]
  double gaina; // [rsp+F8h] [rbp+30h]

  v10 = slope;
  v11 = frequency / (double)(signed int)sampleRate;
  if ( v11 >= 0.0002083333333333333 )
  {
    if ( v11 > 0.4583333333333333 )
      v11 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v11 = DOUBLE_0_0002083333333333333;
  }
  v12 = gain;
  v13 = v11 * 3.141592653589793;
  v14 = pow(10.0, gain * 0.05);
  if ( gain <= 0.0 )
  {
    v15 = tan(v13);
    v13 = v13 * spread;
  }
  else
  {
    v15 = tan(v13 * spread);
  }
  v16 = v15;
  v17 = v15 * v15;
  v18 = DOUBLE_1_0;
  v19 = tan(v13);
  v20 = v19 * v19;
  if ( gain <= 0.0 )
  {
    gaina = DOUBLE_1_0;
    v21 = sqrt(v14);
    v18 = 1.0 / v21 * (1.0 / v21);
  }
  else
  {
    gaina = v14;
  }
  v22 = (__m128d)*(unsigned __int64 *)&ONEOVERMAX_G_GAIN;
  if ( scalePeakDip )
    v12 = MAX_PEAK_G_GAIN * v12 * v22.m128d_f64[0];
  v23 = pow(10.0, v12 * 0.05);
  v24 = dipDelta * 0.5;
  v25 = peakDelta * 0.5;
  v22.m128d_f64[0] = v22.m128d_f64[0] * v12;
  v26 = v12 < 0.0;
  v27 = v12 == 0.0;
  v28 = DOUBLE_1_0;
  *(_QWORD *)&v29 = (unsigned __int128)_mm_sqrt_pd(_mm_and_pd(v22, (__m128d)_xmm));
  if ( v26 || v27 )
  {
    peakDeltaa = DOUBLE_1_0;
    v33 = DOUBLE_1_0;
    v28 = 1.0 / sqrt(v23);
    v31 = v29 * v24;
    v32 = v29 * v25;
    v30 = v28 * v28;
  }
  else
  {
    v30 = DOUBLE_1_0;
    v31 = v29 * v25;
    v32 = v29 * v24;
    peakDeltaa = sqrt(v23);
    v33 = v23;
  }
  v34 = v10 * -2.0;
  v35 = gaina - gaina * v10 + v33 * v10;
  v36 = ((v32 + 1.414213562373095) * v10 * peakDeltaa + 1.0 - v10) * v16;
  v37 = v35 * v17;
  v38 = ((v31 + 1.414213562373095) * v10 * v28 + 1.0 - v10) * v19;
  v39 = v36 + v10 + v35 * v17;
  outCoefs->a0 = v39;
  v40 = v17 * 2.0 * v35 + v10 * -2.0;
  outCoefs->a1 = v40;
  v41 = v10 - v36 + v37;
  outCoefs->a2 = v41;
  v42 = v18 - v18 * v10 + v30 * v10;
  v43 = v38 + v10 + v42 * v20;
  v44 = v10 - v38 + v42 * v20;
  outCoefs->b0 = v43;
  outCoefs->b2 = v44;
  v45 = v20 * 2.0 * v42 + v34;
  outCoefs->b1 = v45;
  if ( normalizeCoefs )
  {
    outCoefs->b0 = 1.0;
    outCoefs->a0 = v39 * (1.0 / v43);
    outCoefs->a1 = v40 * (1.0 / v43);
    outCoefs->a2 = v41 * (1.0 / v43);
    outCoefs->b1 = v45 * (1.0 / v43);
    outCoefs->b2 = v44 * (1.0 / v43);
  }
}

// File Line: 554
// RVA: 0xB0B2E0
void __fastcall CalculationFirstSecondMixHighShelfInSDomain(unsigned int sampleRate, long double frequency, long double slope, long double dipDelta, long double peakDelta, long double gain, bool normalizeCoefs, bool scalePeakDip, SCoefs *outCoefs)
{
  double v9; // xmm10_8
  double v10; // xmm8_8
  double v11; // xmm9_8
  double v12; // xmm11_8
  double v13; // xmm7_8
  double v14; // xmm15_8
  double v15; // xmm12_8
  double v16; // xmm0_8
  __m128d v17; // xmm11
  double v18; // xmm0_8
  double v19; // xmm13_8
  double v20; // xmm2_8
  double v21; // xmm5_8
  double v22; // xmm11_8
  double v23; // xmm14_8
  double v24; // xmm3_8
  double v25; // xmm9_8
  double v26; // xmm5_8
  double v27; // xmm5_8
  double v28; // xmm9_8
  double v29; // xmm10_8
  double v30; // xmm2_8
  double v31; // xmm12_8
  double v32; // xmm5_8
  double v33; // xmm8_8
  double v34; // xmm13_8
  double v35; // xmm9_8
  double v36; // xmm12_8
  double v37; // xmm7_8
  double v38; // xmm4_8
  double v39; // xmm10_8
  double v40; // xmm7_8
  double v41; // [rsp+D8h] [rbp+10h]
  double gaina; // [rsp+F8h] [rbp+30h]

  v9 = slope;
  v10 = frequency / (double)(signed int)sampleRate;
  if ( v10 >= 0.0002083333333333333 )
  {
    if ( v10 > 0.4583333333333333 )
      v10 = DOUBLE_0_4583333333333333;
  }
  else
  {
    v10 = DOUBLE_0_0002083333333333333;
  }
  v11 = gain;
  v12 = pow(10.0, gain * 0.05);
  v13 = DOUBLE_1_0;
  v41 = tan(1.570796326794897 - v10 * 3.141592653589793);
  v14 = v41 * v41;
  if ( gain <= 0.0 )
  {
    v15 = DOUBLE_1_0;
    v16 = sqrt(v12);
    v13 = 1.0 / v16 * (1.0 / v16);
  }
  else
  {
    v15 = v12;
  }
  v17 = (__m128d)*(unsigned __int64 *)&ONEOVERMAX_G_GAIN;
  if ( scalePeakDip )
    v11 = MAX_PEAK_G_GAIN * gain * v17.m128d_f64[0];
  v18 = pow(10.0, v11 * 0.05);
  v19 = dipDelta * 0.5;
  v20 = peakDelta * 0.5;
  v17.m128d_f64[0] = v17.m128d_f64[0] * v11;
  *(_QWORD *)&v21 = (unsigned __int128)_mm_sqrt_pd(_mm_and_pd(v17, (__m128d)_xmm));
  v22 = DOUBLE_1_0;
  if ( v11 <= 0.0 )
  {
    gaina = DOUBLE_1_0;
    v24 = DOUBLE_1_0;
    v22 = 1.0 / sqrt(v18);
    v25 = v21 * v19;
    v26 = v21 * v20;
    v23 = v22 * v22;
  }
  else
  {
    v23 = DOUBLE_1_0;
    v24 = v18;
    v25 = v21 * v20;
    v26 = v21 * v19;
    gaina = sqrt(v18);
  }
  v27 = v26 + 1.414213562373095;
  v28 = v25 + 1.414213562373095;
  v29 = v9 * (1.0 - v10);
  if ( v29 < 0.015 )
    v29 = DOUBLE_0_015;
  v30 = v29 * -2.0;
  v31 = v15 - v15 * v29 + v24 * v29;
  v32 = (v27 * v29 * gaina + 1.0 - v29) * v41;
  v33 = v32 + v29 + v31 * v14;
  v34 = v29 - v32 + v31 * v14;
  outCoefs->a0 = v33;
  v35 = (v28 * v29 * v22 + 1.0 - v29) * v41;
  v36 = -(v31 * (v14 * 2.0) + v29 * -2.0);
  outCoefs->a2 = v34;
  v37 = v13 - v13 * v29 + v23 * v29;
  outCoefs->a1 = v36;
  v38 = v35 + v29 + v37 * v14;
  v39 = v29 - v35 + v37 * v14;
  v40 = -(v37 * (v14 * 2.0) + v30);
  outCoefs->b1 = v40;
  outCoefs->b0 = v38;
  outCoefs->b2 = v39;
  if ( normalizeCoefs )
  {
    outCoefs->b0 = 1.0;
    outCoefs->a0 = v33 * (1.0 / v38);
    outCoefs->a1 = v36 * (1.0 / v38);
    outCoefs->a2 = v34 * (1.0 / v38);
    outCoefs->b1 = v40 * (1.0 / v38);
    outCoefs->b2 = v39 * (1.0 / v38);
  }
}

