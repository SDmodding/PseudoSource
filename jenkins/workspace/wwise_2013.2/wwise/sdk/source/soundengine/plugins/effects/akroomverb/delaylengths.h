// File Line: 41
// RVA: 0xAE5810
char __fastcall DelayLengths::AkDelayQSortCompareFloat(const void *a, const void *b)
{
  float v2; // xmm0_4
  char result; // al

  v2 = *(float *)a - *(float *)b;
  if ( v2 >= 0.0 )
    result = v2 > 0.0;
  else
    result = -1;
  return result;
}

// File Line: 58
// RVA: 0xAE5840
void __fastcall DelayLengths::ComputeFDNDelayTimes(float in_fDensity, float in_fRoomShape, unsigned int in_uNumDelayLines, AlgorithmTunings *in_Tunings, float *out_pfFDNDelayTimes)
{
  unsigned __int64 v5; // r10
  unsigned int v6; // er8
  int v7; // eax
  signed __int64 v8; // r11
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  signed int v12; // esi
  float v13; // xmm8_4
  float *v14; // rdi
  float v15; // xmm9_4
  float v16; // xmm2_4
  int v17; // eax
  float v18; // xmm0_4
  int v19; // eax
  signed int v20; // ecx
  int v21; // eax
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  signed int v25; // ecx
  float v26; // xmm2_4
  int v27; // edx
  float v28; // xmm2_4
  signed int v29; // ecx
  float v30; // xmm5_4
  float *v31; // rdx
  float v32; // xmm2_4

  v5 = in_uNumDelayLines;
  v6 = 0;
  v7 = 7032007;
  v8 = 0i64;
  v9 = (float)((float)((float)(in_Tunings->fDensityDelayMax - in_Tunings->fDensityDelayMin) * 0.0099999998) * in_fDensity)
     + in_Tunings->fDensityDelayMin;
  v10 = (float)((float)((float)((float)(in_Tunings->fRoomShapeMax - in_Tunings->fRoomShapeMin) * 0.0099999998)
                      * in_fRoomShape)
              + in_Tunings->fRoomShapeMin)
      * v9;
  v11 = (float)(v9 - v10) + v9;
  if ( (signed int)v5 >= 4 )
  {
    v12 = 2;
    v13 = v11 - v10;
    v14 = out_pfFDNDelayTimes + 2;
    v8 = 4i64 * (((unsigned int)(v5 - 4) >> 2) + 1);
    v15 = 1.0 / (float)((signed int)v5 - 1);
    do
    {
      v16 = (float)(signed int)v6;
      v6 += 4;
      v14 += 4;
      v17 = 196314165 * v7 + 907633515;
      v18 = (float)v17;
      v19 = 196314165 * v17 + 907633515;
      v20 = v19;
      v21 = 196314165 * v19 + 907633515;
      v22 = (float)((float)(v16 * v13) * v15) + v10;
      v23 = (float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998) * v22) * (float)(v18 * 2.3283064e-10);
      v24 = (float)v20;
      v25 = v12;
      *(v14 - 6) = v23 + v22;
      v26 = (float)(v12 - 1);
      v27 = v12 + 1;
      v12 += 4;
      *(v14 - 5) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)(v26 * v13) * v15) + v10))
                         * (float)(v24 * 2.3283064e-10))
                 + (float)((float)((float)(v26 * v13) * v15) + v10);
      v28 = (float)v25;
      v29 = v21;
      v7 = 196314165 * v21 + 907633515;
      *(v14 - 4) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)(v28 * v13) * v15) + v10))
                         * (float)((float)v29 * 2.3283064e-10))
                 + (float)((float)((float)(v28 * v13) * v15) + v10);
      *(v14 - 3) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)((float)v27 * v13) * v15) + v10))
                         * (float)((float)v7 * 2.3283064e-10))
                 + (float)((float)((float)((float)v27 * v13) * v15) + v10);
    }
    while ( v6 < (signed int)v5 - 3 );
  }
  if ( v6 < (unsigned int)v5 )
  {
    v30 = v11 - v10;
    v31 = &out_pfFDNDelayTimes[v8];
    do
    {
      v32 = (float)(signed int)v6++;
      ++v31;
      v7 = 196314165 * v7 + 907633515;
      *(v31 - 1) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)(v32 * v30) * (float)(1.0 / (float)((signed int)v5 - 1))) + v10))
                         * (float)((float)v7 * 2.3283064e-10))
                 + (float)((float)((float)(v32 * v30) * (float)(1.0 / (float)((signed int)v5 - 1))) + v10);
    }
    while ( v6 < (unsigned int)v5 );
  }
  qsort(
    out_pfFDNDelayTimes,
    v5,
    4ui64,
    (int (__fastcall *)(const void *, const void *))DelayLengths::AkDelayQSortCompareFloat);
}

// File Line: 85
// RVA: 0xAE5B30
void __fastcall DelayLengths::ComputeFDNInputDelayTimes(unsigned int in_uNumDelayLines, AlgorithmTunings *in_Tunings, float *out_pfFDNInputDelayTimes)
{
  unsigned int v3; // er11
  float *v4; // rbx
  AlgorithmTunings *v5; // r9
  signed __int64 v6; // rdi
  signed int v7; // er10
  int v8; // eax
  float *v9; // r8
  unsigned int v10; // ecx
  __int64 v11; // rdx
  float v12; // xmm7_4
  float v13; // xmm2_4
  int v14; // eax
  float v15; // xmm0_4
  int v16; // eax
  signed int v17; // ecx
  int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  signed int v21; // ecx
  signed __int64 v22; // rdx
  __int64 v23; // r8

  v3 = 0;
  v4 = out_pfFDNInputDelayTimes;
  v5 = in_Tunings;
  v6 = 0i64;
  v7 = in_uNumDelayLines;
  v8 = 29101977;
  if ( (signed int)in_uNumDelayLines >= 4 )
  {
    v9 = out_pfFDNInputDelayTimes + 2;
    v10 = ((in_uNumDelayLines - 4) >> 2) + 1;
    v11 = v10;
    v3 = 4 * v10;
    v6 = 4i64 * v10;
    v12 = 1.0 / (float)v7;
    do
    {
      v13 = v12 * v5->fReverbUnitInputDelay;
      v9 += 4;
      v14 = 196314165 * v8 + 907633515;
      v15 = (float)v14;
      v16 = 196314165 * v14 + 907633515;
      v17 = v16;
      v18 = 196314165 * v16 + 907633515;
      v19 = (float)((float)(v5->fReverbUnitInputDelayRmdPerc * 0.0099999998) * v13) * (float)(v15 * 2.3283064e-10);
      v20 = (float)v17;
      v21 = v18;
      v8 = 196314165 * v18 + 907633515;
      *(v9 - 6) = v19 + v13;
      *(v9 - 5) = (float)((float)((float)(v5->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                * (float)(v12 * v5->fReverbUnitInputDelay))
                        * (float)(v20 * 2.3283064e-10))
                + (float)(v12 * v5->fReverbUnitInputDelay);
      *(v9 - 4) = (float)((float)((float)(v5->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                * (float)(v12 * v5->fReverbUnitInputDelay))
                        * (float)((float)v21 * 2.3283064e-10))
                + (float)(v12 * v5->fReverbUnitInputDelay);
      *(v9 - 3) = (float)((float)((float)(v5->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                * (float)(v12 * v5->fReverbUnitInputDelay))
                        * (float)((float)v8 * 2.3283064e-10))
                + (float)(v12 * v5->fReverbUnitInputDelay);
      --v11;
    }
    while ( v11 );
  }
  if ( v3 < v7 )
  {
    v22 = (signed __int64)&v4[v6];
    v23 = v7 - v3;
    do
    {
      v22 += 4i64;
      v8 = 196314165 * v8 + 907633515;
      *(float *)(v22 - 4) = (float)((float)((float)(v5->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                          * (float)((float)(1.0 / (float)v7) * v5->fReverbUnitInputDelay))
                                  * (float)((float)v8 * 2.3283064e-10))
                          + (float)((float)(1.0 / (float)v7) * v5->fReverbUnitInputDelay);
      --v23;
    }
    while ( v23 );
  }
}

// File Line: 104
// RVA: 0xAE5D30
void __fastcall DelayLengths::ComputeDiffusionFiltersDelayTimes(unsigned int in_uNumReverbUnits, AlgorithmTunings *in_Tunings, float *out_pfAPFDelayTimes)
{
  float v3; // xmm4_4
  unsigned int v4; // er9
  float *v5; // r11
  unsigned __int64 v6; // r10
  signed __int64 v7; // rdi
  int v8; // eax
  float *v9; // rbx
  unsigned int v10; // ecx
  __int64 v11; // r8
  float v12; // xmm2_4
  int v13; // eax
  signed int v14; // ecx
  float v15; // xmm4_4
  int v16; // eax
  float v17; // xmm0_4
  signed int v18; // ecx
  float v19; // xmm3_4
  int v20; // eax
  float v21; // xmm4_4
  float v22; // xmm0_4
  signed int v23; // ecx
  float v24; // xmm3_4
  signed __int64 v25; // r8
  __int64 v26; // r9
  float v27; // xmm2_4

  v3 = in_Tunings->fDiffusionDelayMax;
  v4 = 0;
  v5 = out_pfAPFDelayTimes;
  v6 = in_uNumReverbUnits;
  v7 = 0i64;
  v8 = 3072007;
  if ( (signed int)in_uNumReverbUnits >= 4 )
  {
    v9 = out_pfAPFDelayTimes + 2;
    v10 = ((unsigned int)(v6 - 4) >> 2) + 1;
    v11 = v10;
    v4 = 4 * v10;
    v7 = 4i64 * v10;
    do
    {
      v12 = v3;
      v9 += 4;
      v13 = 196314165 * v8 + 907633515;
      v14 = v13;
      v15 = v3 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      v16 = 196314165 * v13 + 907633515;
      v17 = (float)v14;
      v18 = v16;
      v19 = v15;
      v20 = 196314165 * v16 + 907633515;
      *(v9 - 6) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v12)
                        * (float)(v17 * 2.3283064e-10))
                + v12;
      v21 = v15 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      v22 = (float)v18;
      v23 = v20;
      v8 = 196314165 * v20 + 907633515;
      *(v9 - 5) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v19)
                        * (float)(v22 * 2.3283064e-10))
                + v19;
      v24 = v21 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(v9 - 4) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v21)
                        * (float)((float)v23 * 2.3283064e-10))
                + v21;
      v3 = v24 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(v9 - 3) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v24)
                        * (float)((float)v8 * 2.3283064e-10))
                + v24;
      --v11;
    }
    while ( v11 );
  }
  if ( v4 < (unsigned int)v6 )
  {
    v25 = (signed __int64)&v5[v7];
    v26 = (unsigned int)v6 - v4;
    do
    {
      v27 = v3;
      v25 += 4i64;
      v8 = 196314165 * v8 + 907633515;
      v3 = v3 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(float *)(v25 - 4) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v27)
                                  * (float)((float)v8 * 2.3283064e-10))
                          + v27;
      --v26;
    }
    while ( v26 );
  }
  qsort(v5, v6, 4ui64, (int (__fastcall *)(const void *, const void *))DelayLengths::AkDelayQSortCompareFloat);
}

// File Line: 128
// RVA: 0xAE5F40
void __fastcall DelayLengths::MakePrimeNumber(unsigned int *in_uIn, unsigned int in_uPrevVal)
{
  unsigned int *v2; // r10
  __m128d v3; // xmm0
  int v4; // er9
  signed int v5; // ecx
  unsigned int v6; // er8

  v2 = in_uIn;
  if ( !(*in_uIn & 1) )
    ++*in_uIn;
  v3 = 0i64;
  v3.m128d_f64[0] = (double)(signed int)*in_uIn;
  v4 = (signed int)COERCE_DOUBLE(_mm_sqrt_pd(v3)) + 1;
  while ( 1 )
  {
    v5 = 3;
    if ( v4 <= 3 )
      break;
    v6 = *v2;
    while ( v6 % v5 )
    {
      v5 += 2;
      if ( v5 >= v4 )
        goto LABEL_8;
    }
LABEL_9:
    *v2 = v6 + 2;
  }
LABEL_8:
  v6 = *v2;
  if ( *v2 == in_uPrevVal )
    goto LABEL_9;
}

// File Line: 165
// RVA: 0xAE5FA0
void __fastcall DelayLengths::ComputePrimeDelayLengths(float *in_pfDelayTimes, unsigned int in_uSampleRate, unsigned int in_uNumDelays, unsigned int *out_puDelayLengths)
{
  unsigned int v4; // ebx
  unsigned int *v5; // r14
  unsigned int v6; // edi
  unsigned int *v7; // r10
  signed __int64 v8; // rsi
  float v9; // xmm2_4
  signed int v10; // edx
  __m128d v11; // xmm0
  int v12; // er9
  signed int v13; // ecx
  unsigned int v14; // er8
  unsigned int v15; // er11
  __m128d v16; // xmm0
  int v17; // er9
  signed int v18; // ecx
  unsigned int v19; // er8

  if ( in_uNumDelays )
  {
    v4 = 0;
    v5 = out_puDelayLengths;
    v6 = in_uNumDelays;
    v7 = out_puDelayLengths;
    v8 = (char *)in_pfDelayTimes - (char *)out_puDelayLengths;
    v9 = (float)(signed int)in_uSampleRate;
    do
    {
      v10 = (signed int)(float)((float)(*(float *)((char *)v7 + v8) * 0.001) * v9);
      *v7 = v10;
      if ( !v4 )
      {
        if ( !(v10 & 1) )
          *v7 = v10 + 1;
        v11 = 0i64;
        v11.m128d_f64[0] = (double)(signed int)*v7;
        v12 = (signed int)COERCE_DOUBLE(_mm_sqrt_pd(v11)) + 1;
        while ( 1 )
        {
          v13 = 3;
          if ( v12 <= 3 )
          {
LABEL_11:
            v14 = *v7;
            if ( *v7 )
              goto LABEL_22;
          }
          else
          {
            v14 = *v7;
            while ( v14 % v13 )
            {
              v13 += 2;
              if ( v13 >= v12 )
                goto LABEL_11;
            }
          }
          *v7 = v14 + 2;
        }
      }
      v15 = v5[v4 - 1];
      if ( !(v10 & 1) )
        *v7 = v10 + 1;
      v16 = 0i64;
      v16.m128d_f64[0] = (double)(signed int)*v7;
      v17 = (signed int)COERCE_DOUBLE(_mm_sqrt_pd(v16)) + 1;
      while ( 1 )
      {
        v18 = 3;
        if ( v17 <= 3 )
          break;
        v19 = *v7;
        while ( v19 % v18 )
        {
          v18 += 2;
          if ( v18 >= v17 )
            goto LABEL_20;
        }
LABEL_21:
        *v7 = v19 + 2;
      }
LABEL_20:
      v19 = *v7;
      if ( *v7 == v15 )
        goto LABEL_21;
LABEL_22:
      ++v4;
      ++v7;
    }
    while ( v4 < v6 );
  }
}

