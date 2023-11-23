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
void __fastcall CoefficientCalculator::CalculateParametric(
        int sampleRate,
        long double frequency,
        long double q,
        long double gain,
        SCoefs *outCoefs)
{
  double v5; // xmm7_8
  double v6; // xmm11_8
  double v7; // xmm9_8
  double v8; // xmm12_8
  double v9; // xmm0_8
  double v10; // xmm8_8
  double v11; // xmm10_8
  double v12; // xmm4_8
  double v13; // xmm5_8
  double v14; // xmm5_8
  double v15; // xmm9_8
  double v16; // xmm10_8
  double v17; // xmm6_8

  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v5 = frequency / (double)sampleRate;
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
  v7 = (v6 + 1.0) * (1.0 / q);
  v8 = v6 * v6;
  v9 = pow(10.0, gain * 0.05);
  *(_QWORD *)&v10 = COERCE_UNSIGNED_INT64(gain * 0.08333333333333333) & _xmm;
  if ( v9 < 1.0 )
  {
    v11 = (v6 + 1.0) * (1.0 / q);
    v12 = DOUBLE_1_0;
    v14 = v5 * (1.0 / v9 * v7);
    v7 = 1.0 / v9 * v7;
    v13 = (v14 + 1.0 - v5) * v10 + 1.0 - v10;
    if ( v13 < 1.0 )
      v13 = DOUBLE_1_0;
    if ( v13 > 1.0 / v9 )
      v13 = 1.0 / v9;
  }
  else
  {
    v11 = v9 * v7;
    v12 = (v5 * (v9 * v7) + 1.0 - v5) * v10 + 1.0 - v10;
    if ( v12 < 1.0 )
      v12 = DOUBLE_1_0;
    if ( v12 > v9 )
      v12 = v9;
    v13 = DOUBLE_1_0;
  }
  v15 = v7 * v6;
  v16 = v11 * v6;
  outCoefs->b0 = 1.0;
  v17 = 1.0 / (v15 + v13 + v8);
  outCoefs->a0 = (v16 + v12 + v8) * v17;
  outCoefs->a2 = (v12 - v16 + v8) * v17;
  outCoefs->a1 = (v8 * 2.0 - v12 * 2.0) * v17;
  outCoefs->b1 = (v8 * 2.0 - v13 * 2.0) * v17;
  outCoefs->b2 = (v13 - v15 + v8) * v17;
}

// File Line: 132
// RVA: 0xB0A540
void __fastcall CoefficientCalculator::CalculateFirstOrderHighPass(
        int sampleRate,
        long double frequency,
        SCoefs *outCoefs)
{
  double v4; // xmm1_8
  long double v5; // xmm0_8
  long double v6; // xmm4_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v4 = frequency / (double)sampleRate;
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
  outCoefs->b0 = 1.0;
  v6 = 1.0 / (v5 + 1.0);
  outCoefs->a0 = v6;
  outCoefs->b1 = (v5 - 1.0) * v6;
  outCoefs->a1 = v6 * -1.0;
  outCoefs->a2 = v6 * 0.0;
  outCoefs->b2 = v6 * 0.0;
}

// File Line: 153
// RVA: 0xB0A620
void __fastcall CoefficientCalculator::CalculateSecondOrderHighPass(
        int sampleRate,
        long double frequency,
        long double peak,
        SCoefs *outCoefs)
{
  double v5; // xmm1_8
  long double v6; // xmm0_8
  long double v7; // xmm4_8
  long double v8; // xmm2_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v5 = frequency / (double)sampleRate;
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
  outCoefs->b0 = 1.0;
  v7 = v6 * peak;
  v8 = 1.0 / (v6 * peak + 1.0 + v6 * v6);
  outCoefs->a0 = v8;
  outCoefs->a2 = v8;
  outCoefs->b2 = (1.0 - v7 + v6 * v6) * v8;
  outCoefs->a1 = v8 * -2.0;
  outCoefs->b1 = (v6 * v6 * 2.0 - 2.0) * v8;
}

// File Line: 174
// RVA: 0xB0A730
void __fastcall CoefficientCalculator::CalculateFirstOrderLowPass(
        int sampleRate,
        long double frequency,
        SCoefs *outCoefs)
{
  double v4; // xmm1_8
  long double v5; // xmm0_8
  long double v6; // xmm5_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v4 = frequency / (double)sampleRate;
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
  outCoefs->b0 = 1.0;
  v6 = 1.0 / (v5 + 1.0);
  outCoefs->a0 = v6 * v5;
  outCoefs->a1 = v6 * v5;
  outCoefs->a2 = v6 * 0.0;
  outCoefs->b2 = v6 * 0.0;
  outCoefs->b1 = (v5 - 1.0) * v6;
}

// File Line: 193
// RVA: 0xB0ADB0
float __fastcall CoefficientCalculator::CalculateDecayTime(BiquadCoefficients *in_coeffs)
{
  __m128 b1_low; // xmm3
  __m128 v2; // xmm1
  __m128 v3; // xmm2
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4

  b1_low = (__m128)LODWORD(in_coeffs->b1);
  v2 = b1_low;
  v2.m128_f32[0] = b1_low.m128_f32[0] * b1_low.m128_f32[0];
  v3 = v2;
  v3.m128_f32[0] = (float)(b1_low.m128_f32[0] * b1_low.m128_f32[0]) - (float)(in_coeffs->b2 * 4.0);
  if ( v3.m128_f32[0] >= 0.0 )
  {
    v5 = _mm_sqrt_ps(v3).m128_f32[0];
    v6 = COERCE_FLOAT(b1_low.m128_i32[0] ^ _xmm[0]) - v5;
    LODWORD(v7) = COERCE_UNSIGNED_INT(v5 - b1_low.m128_f32[0]) & _xmm;
    LODWORD(v4) = LODWORD(v6) & _xmm;
    if ( v4 <= v7 )
      v4 = v7;
  }
  else
  {
    v2.m128_f32[0] = v2.m128_f32[0] - v3.m128_f32[0];
    LODWORD(v4) = _mm_sqrt_ps(v2).m128_u32[0];
  }
  return 1.0 / (float)(1.0 - (float)(v4 * 0.5));
}

// File Line: 217
// RVA: 0xB0A800
void __fastcall CoefficientCalculator::CalculateSecondOrderLowPass(
        int sampleRate,
        long double frequency,
        long double peak,
        SCoefs *outCoefs)
{
  double v5; // xmm1_8
  long double v6; // xmm0_8
  long double v7; // xmm6_8
  long double v8; // xmm3_8

  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  v5 = frequency / (double)sampleRate;
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
  outCoefs->b0 = 1.0;
  v7 = v6 * v6 * 2.0;
  v8 = 1.0 / (v6 * peak + 1.0 + v6 * v6);
  outCoefs->b1 = (v7 - 2.0) * v8;
  outCoefs->a1 = v7 * v8;
  outCoefs->b2 = (1.0 - v6 * peak + v6 * v6) * v8;
  outCoefs->a0 = v8 * (v6 * v6);
  outCoefs->a2 = v8 * (v6 * v6);
}

// File Line: 239
// RVA: 0xB0A930
void __fastcall CoefficientCalculator::CalculateDualHPFAndLPF(
        int sampleRate,
        long double hpFrequency,
        long double lpFrequency,
        SCoefs *outCoefs)
{
  double a1; // xmm5_8
  double b1; // xmm2_8
  double a0; // xmm0_8
  long double v9; // xmm0_8
  long double v10; // xmm3_8
  long double v11; // xmm3_8
  double v12; // xmm0_8
  long double v13; // xmm2_8
  long double v14; // xmm0_8
  SCoefs v15; // [rsp+20h] [rbp-78h] BYREF
  SCoefs outCoefsa; // [rsp+50h] [rbp-48h] BYREF

  CoefficientCalculator::CalculateFirstOrderHighPass(sampleRate, hpFrequency, &outCoefsa);
  CoefficientCalculator::CalculateFirstOrderLowPass(sampleRate, lpFrequency, &v15);
  a1 = outCoefsa.a1;
  b1 = v15.b1;
  a0 = v15.a0;
  outCoefs->b0 = 1.0;
  outCoefs->a0 = a0 * outCoefsa.a0;
  v9 = v15.a1 * outCoefsa.a0;
  v10 = a1 * v15.a0;
  outCoefs->a2 = a1 * v15.a1;
  v11 = v10 + v9;
  v12 = b1;
  v13 = b1 * outCoefsa.b1;
  v14 = v12 + outCoefsa.b1;
  outCoefs->a1 = v11;
  outCoefs->b1 = v14;
  outCoefs->b2 = v13;
}

// File Line: 258
// RVA: 0xB0AA00
void __fastcall CoefficientCalculator::CalculateGParametric(
        int sampleRate,
        long double frequency,
        long double q,
        long double gain,
        SCoefs *outCoefs)
{
  double v5; // xmm7_8
  double v6; // xmm11_8
  double v7; // xmm8_8
  double v8; // xmm12_8
  double v9; // xmm0_8
  double v10; // xmm9_8
  double v11; // xmm4_8
  double v12; // xmm5_8
  double v13; // xmm8_8
  double v14; // xmm9_8
  double v15; // xmm6_8

  outCoefs->a0 = 1.0;
  outCoefs->b0 = 1.0;
  outCoefs->b1 = 1.0;
  outCoefs->a1 = 0.0;
  outCoefs->a2 = 0.0;
  outCoefs->b2 = 0.0;
  v5 = frequency / (double)sampleRate;
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
  v7 = (v6 + 1.0) * (1.0 / q);
  v8 = v6 * v6;
  v9 = pow(10.0, gain * 0.05);
  if ( v9 < 1.0 )
  {
    v10 = (v6 + 1.0) * (1.0 / q);
    v11 = DOUBLE_1_0;
    v7 = 1.0 / v9 * v7;
    v12 = (v5 * v7 + 1.0 - v5) * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm)
        + 1.0
        - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm);
    if ( v12 < 1.0 )
      v12 = DOUBLE_1_0;
    if ( v12 > 1.0 / v9 )
      v12 = 1.0 / v9;
  }
  else
  {
    v10 = v9 * v7;
    v11 = (v5 * (v9 * v7) + 1.0 - v5) * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm)
        + 1.0
        - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(ONEOVERMAX_G_GAIN * gain) & _xmm);
    if ( v11 < 1.0 )
      v11 = DOUBLE_1_0;
    if ( v11 > v9 )
      v11 = v9;
    v12 = DOUBLE_1_0;
  }
  v13 = v7 * v6;
  v14 = v10 * v6;
  outCoefs->b0 = 1.0;
  v15 = 1.0 / (v13 + v12 + v8);
  outCoefs->a0 = (v14 + v11 + v8) * v15;
  outCoefs->a2 = (v11 - v14 + v8) * v15;
  outCoefs->a1 = (v8 * 2.0 - v11 * 2.0) * v15;
  outCoefs->b1 = (v8 * 2.0 - v12 * 2.0) * v15;
  outCoefs->b2 = (v12 - v13 + v8) * v15;
}

// File Line: 345
// RVA: 0xB0AC80
void __fastcall CoefficientCalculator::CalculatePostGLowShelf(
        unsigned int sampleRate,
        long double frequency,
        double slope,
        long double gain,
        SCoefs *outCoefs)
{
  long double v7; // xmm3_8

  v7 = pow(slope, 0.25) * 100.0 * -0.016;
  CalculationFirstSecondMixLowShelfInSDomain(sampleRate, frequency, 0.85, v7, -0.0, gain, 1, 0, 1.0, outCoefs);
}

// File Line: 358
// RVA: 0xB0AD20
void __fastcall CoefficientCalculator::CalculatePostGHighShelf(
        unsigned int sampleRate,
        long double frequency,
        double slope,
        long double gain,
        SCoefs *outCoefs)
{
  double v7; // xmm3_8

  v7 = pow(slope, 0.25);
  CalculationFirstSecondMixHighShelfInSDomain(
    sampleRate,
    frequency,
    0.85,
    v7 * 100.0 * -0.016,
    -0.0,
    gain,
    1,
    0,
    outCoefs);
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
void __fastcall PrepareOmegaValues(
        int sampleRate,
        long double frequency,
        long double *outFlippedFrequency,
        long double *outWc,
        long double *outWcSqrd)
{
  double v6; // xmm1_8
  long double v7; // xmm0_8

  v6 = frequency / (double)sampleRate;
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
  *outWc = v7;
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
void __fastcall CalculationFirstSecondMixLowShelfInSDomain(
        int sampleRate,
        long double frequency,
        long double slope,
        long double dipDelta,
        long double peakDelta,
        double gain,
        bool normalizeCoefs,
        bool scalePeakDip,
        long double spread,
        SCoefs *outCoefs)
{
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
  bool v26; // cc
  double v27; // xmm7_8
  double v28; // xmm4_8
  double v29; // xmm11_8
  double v30; // xmm5_8
  double v31; // xmm4_8
  double v32; // xmm1_8
  long double v33; // xmm2_8
  long double v34; // xmm15_8
  long double v35; // xmm4_8
  long double v36; // xmm0_8
  long double v37; // xmm5_8
  double v38; // xmm12_8
  double v39; // xmm8_8
  double v40; // xmm15_8
  long double v41; // xmm10_8
  double v42; // xmm3_8
  double v43; // xmm14_8
  double v44; // xmm9_8
  double peakDeltaa; // [rsp+F0h] [rbp+28h]
  double gaina; // [rsp+F8h] [rbp+30h]

  v11 = frequency / (double)sampleRate;
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
    v12 = MAX_PEAK_G_GAIN * v12 * ONEOVERMAX_G_GAIN;
  v23 = pow(10.0, v12 * 0.05);
  v24 = dipDelta * 0.5;
  v25 = peakDelta * 0.5;
  v22.m128d_f64[0] = v22.m128d_f64[0] * v12;
  v26 = v12 <= 0.0;
  v27 = DOUBLE_1_0;
  *(_QWORD *)&v28 = *(_OWORD *)&_mm_sqrt_pd(_mm_and_pd(v22, (__m128d)_xmm));
  if ( v26 )
  {
    peakDeltaa = DOUBLE_1_0;
    v32 = DOUBLE_1_0;
    v27 = 1.0 / sqrt(v23);
    v30 = v28 * v24;
    v31 = v28 * v25;
    v29 = v27 * v27;
  }
  else
  {
    v29 = DOUBLE_1_0;
    v30 = v28 * v25;
    v31 = v28 * v24;
    peakDeltaa = sqrt(v23);
    v32 = v23;
  }
  v33 = slope * -2.0;
  v34 = gaina - gaina * slope + v32 * slope;
  v35 = ((v31 + 1.414213562373095) * slope * peakDeltaa + 1.0 - slope) * v16;
  v36 = v34 * v17;
  v37 = ((v30 + 1.414213562373095) * slope * v27 + 1.0 - slope) * v19;
  v38 = v35 + slope + v34 * v17;
  outCoefs->a0 = v38;
  v39 = v17 * 2.0 * v34 + slope * -2.0;
  outCoefs->a1 = v39;
  v40 = slope - v35 + v36;
  outCoefs->a2 = v40;
  v41 = v18 - v18 * slope + v29 * slope;
  v42 = v37 + slope + v41 * v20;
  v43 = slope - v37 + v41 * v20;
  outCoefs->b0 = v42;
  outCoefs->b2 = v43;
  v44 = v20 * 2.0 * v41 + v33;
  outCoefs->b1 = v44;
  if ( normalizeCoefs )
  {
    outCoefs->b0 = 1.0;
    outCoefs->a0 = v38 * (1.0 / v42);
    outCoefs->a1 = v39 * (1.0 / v42);
    outCoefs->a2 = v40 * (1.0 / v42);
    outCoefs->b1 = v44 * (1.0 / v42);
    outCoefs->b2 = v43 * (1.0 / v42);
  }
}

// File Line: 554
// RVA: 0xB0B2E0
void __fastcall CalculationFirstSecondMixHighShelfInSDomain(
        int sampleRate,
        long double frequency,
        long double slope,
        long double dipDelta,
        long double peakDelta,
        double gain,
        bool normalizeCoefs,
        bool scalePeakDip,
        SCoefs *outCoefs)
{
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

  v10 = frequency / (double)sampleRate;
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
    v11 = MAX_PEAK_G_GAIN * gain * ONEOVERMAX_G_GAIN;
  v18 = pow(10.0, v11 * 0.05);
  v19 = dipDelta * 0.5;
  v20 = peakDelta * 0.5;
  v17.m128d_f64[0] = v17.m128d_f64[0] * v11;
  *(_QWORD *)&v21 = *(_OWORD *)&_mm_sqrt_pd(_mm_and_pd(v17, (__m128d)_xmm));
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
  v29 = slope * (1.0 - v10);
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

