// File Line: 24
// RVA: 0xB028C0
long double __fastcall GetTCScalar(long double timeInSamples)
{
  double v1; // xmm2_8
  long double result; // xmm0_8

  v1 = timeInSamples;
  if ( timeInSamples == 0.0 )
    return DOUBLE_1_0;
  result = 1.0 / timeInSamples;
  if ( 1.0 / v1 > 1.0 )
    result = DOUBLE_1_0;
  return result;
}

// File Line: 48
// RVA: 0xB02900
long double __fastcall GetSoftKneeThreshold(long double knee, long double threshold)
{
  double v2; // xmm7_8
  long double result; // xmm0_8

  v2 = knee;
  result = threshold - (1.0 - pow(threshold, 0.005)) * 0.0025;
  if ( v2 < 0.0 )
    result = result * (1.0 - (1.0 - threshold * threshold) * (v2 * -0.1));
  return result;
}

// File Line: 68
// RVA: 0xB02980
void __fastcall GenerateCompressionTable(float *compressionTable, int tableSize, long double threshold, long double ratio, long double knee, long double *softThreshold)
{
  int v6; // edi
  float *v7; // rsi
  double v8; // xmm11_8
  double v9; // xmm15_8
  __int16 v10; // bx
  signed int v11; // eax
  double v12; // xmm7_8
  double v13; // xmm6_8
  double v14; // xmm2_8
  double v15; // xmm2_8
  double v16; // xmm0_8
  __int64 v17; // rax
  double v18; // [rsp+20h] [rbp-B8h]

  v6 = tableSize;
  v7 = compressionTable;
  v8 = threshold;
  v9 = 1.0 / (double)tableSize;
  v10 = 0;
  v18 = GetSoftKneeThreshold(knee, threshold);
  *softThreshold = v18;
  if ( v6 > 0 )
  {
    v11 = 0;
    do
    {
      v12 = (double)v11 * v9;
      if ( knee > 0.0 )
      {
        v13 = pow(v12, 0.4);
        v12 = pow(v12, knee * 0.1 + 1.0) * (1.0 - v13) + v13 * v12;
        if ( knee > 10.0 )
          v12 = v12 * (1.0 - (1.0 - v8) * 0.1 * (knee - 10.0) * v12);
      }
      v14 = 1.0 - pow(1.0 - v12, 0.5);
      if ( knee <= 0.0 )
        v15 = v14 / v8;
      else
        v15 = v14 / v18;
      v16 = pow(v15 + 1.0, 1.0 / ratio - 1.0);
      v17 = v10++;
      *(float *)&v16 = v16;
      v7[v17] = *(float *)&v16;
      v11 = v10;
    }
    while ( v10 < v6 );
  }
}

// File Line: 127
// RVA: 0xB02B90
void __fastcall GenerateGCompressionTable(float *compressionTable, int tableSize, long double threshold, long double ratio, bool bypassed)
{
  int v5; // esi
  float *v6; // r14
  double v7; // xmm11_8
  double v8; // xmm8_8
  double v9; // xmm10_8
  signed int v10; // edi
  double v11; // xmm9_8
  __m128i v12; // xmm14
  double v13; // xmm12_8
  __int64 v14; // rbx
  double v15; // xmm0_8
  signed __int64 v16; // rbx
  double v17; // xmm0_8
  float v18; // xmm1_4
  double v19; // [rsp+20h] [rbp-C8h]
  double v20; // [rsp+100h] [rbp+18h]

  v5 = tableSize;
  v6 = compressionTable;
  v7 = ratio;
  v8 = 1.0 / (double)tableSize;
  v19 = 1.0 / (double)tableSize;
  if ( bypassed )
  {
    v20 = DOUBLE_1_0;
    v9 = DOUBLE_1_0;
    v7 = DOUBLE_1_0;
  }
  else
  {
    v20 = pow(10.0, threshold * 0.05);
    v9 = v20;
  }
  v10 = 0;
  if ( v5 > 0 && (unsigned int)v5 >= 4 )
  {
    *(_QWORD *)&v11 = (unsigned __int128)_mm_unpckl_pd(
                                           (__m128d)*(unsigned __int64 *)&v19,
                                           (__m128d)*(unsigned __int64 *)&v19);
    v12 = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&v13 = (unsigned __int128)_mm_unpckl_pd(
                                           (__m128d)*(unsigned __int64 *)&v20,
                                           (__m128d)*(unsigned __int64 *)&v20);
    do
    {
      _vdecl_pow2();
      _vdecl_pow2();
      *(double *)&v6[v10] = (*(double *)_xmm
                           - (*(double *)_xmm
                            - COERCE_DOUBLE(_mm_cvtepi32_pd(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10), 0), v12)))
                            * v11))
                          / v13
                          + *(double *)_xmm;
      v14 = v10 + 2;
      v15 = COERCE_DOUBLE(_mm_cvtepi32_pd(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10 + 2), 0), v12))) * v11;
      _vdecl_pow2();
      _vdecl_pow2();
      v10 += 4;
      *(double *)&v6[v14] = (*(double *)_xmm - (*(double *)_xmm - v15)) / v13 + *(double *)_xmm;
    }
    while ( v10 < v5 - v5 % 4 );
  }
  if ( v10 < v5 )
  {
    v16 = (signed __int64)&v6[v10];
    do
    {
      v17 = pow(1.0 - (double)v10++ * v8, 0.5);
      v16 += 4i64;
      v18 = pow((1.0 - v17) * (1.0 / v9) + 1.0, 1.0 / v7 - 1.0);
      *(float *)(v16 - 4) = v18;
    }
    while ( v10 < v5 );
  }
}

// File Line: 162
// RVA: 0xB02E90
void __fastcall GenerateGGateTable(float *gateTable, int tableSize, long double threshold, long double ratio, long double range, bool bypassed)
{
  int v6; // esi
  double v7; // xmm8_8
  float *v8; // rdi
  double v9; // xmm9_8
  double v10; // xmm7_8
  signed int v11; // ebx
  double v12; // xmm8_8
  double v13; // xmm0_8
  double v14; // xmm0_8
  float v15; // xmm0_4

  v6 = tableSize;
  v7 = ratio;
  v8 = gateTable;
  v9 = 1.0 / (double)(tableSize - 1);
  if ( bypassed )
  {
    v7 = DOUBLE_1_0;
    v10 = DOUBLE_1_0;
  }
  else
  {
    v10 = pow(10.0, range * 0.05);
  }
  v11 = 0;
  if ( v6 > 0 )
  {
    v12 = v7 - 1.0;
    do
    {
      v13 = pow(1.0 - (double)v11 * v9, 0.5);
      v14 = pow(1.0 - v13, v12);
      if ( v14 > 1.0 )
        v14 = DOUBLE_1_0;
      if ( v14 < v10 )
        v14 = v10;
      v15 = v14;
      ++v11;
      ++v8;
      *(v8 - 1) = v15;
    }
    while ( v11 < v6 );
  }
}

