// File Line: 41
// RVA: 0xAE5810
__int64 __fastcall DelayLengths::AkDelayQSortCompareFloat(float *a, float *b)
{
  float v2; // xmm0_4

  v2 = *a - *b;
  if ( v2 >= 0.0 )
    return v2 > 0.0;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 58
// RVA: 0xAE5840
void __fastcall DelayLengths::ComputeFDNDelayTimes(
        float in_fDensity,
        float in_fRoomShape,
        unsigned int in_uNumDelayLines,
        AlgorithmTunings *in_Tunings,
        float *out_pfFDNDelayTimes)
{
  unsigned __int64 v5; // r10
  unsigned int v6; // r8d
  int v7; // eax
  __int64 v8; // r11
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  int v12; // esi
  float v13; // xmm8_4
  float *v14; // rdi
  float v15; // xmm9_4
  float v16; // xmm2_4
  int v17; // ecx
  float v18; // xmm0_4
  int v19; // ecx
  int v20; // eax
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  int v24; // ecx
  float v25; // xmm2_4
  int v26; // edx
  float v27; // xmm2_4
  int v28; // ecx
  float v29; // xmm5_4
  float *v30; // rdx
  float v31; // xmm2_4

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
  if ( (int)v5 >= 4 )
  {
    v12 = 2;
    v13 = v11 - v10;
    v14 = out_pfFDNDelayTimes + 2;
    v8 = 4i64 * (((unsigned int)(v5 - 4) >> 2) + 1);
    v15 = 1.0 / (float)((int)v5 - 1);
    do
    {
      v16 = (float)(int)v6;
      v6 += 4;
      v14 += 4;
      v17 = 196314165 * v7 + 907633515;
      v18 = (float)v17;
      v19 = 196314165 * v17 + 907633515;
      v20 = 196314165 * v19 + 907633515;
      v21 = (float)((float)(v16 * v13) * v15) + v10;
      v22 = (float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998) * v21) * (float)(v18 * 2.3283064e-10);
      v23 = (float)v19;
      v24 = v12;
      *(v14 - 6) = v22 + v21;
      v25 = (float)(v12 - 1);
      v26 = v12 + 1;
      v12 += 4;
      *(v14 - 5) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)(v25 * v13) * v15) + v10))
                         * (float)(v23 * 2.3283064e-10))
                 + (float)((float)((float)(v25 * v13) * v15) + v10);
      v27 = (float)v24;
      v28 = v20;
      v7 = 196314165 * v20 + 907633515;
      *(v14 - 4) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)(v27 * v13) * v15) + v10))
                         * (float)((float)v28 * 2.3283064e-10))
                 + (float)((float)((float)(v27 * v13) * v15) + v10);
      *(v14 - 3) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)((float)v26 * v13) * v15) + v10))
                         * (float)((float)v7 * 2.3283064e-10))
                 + (float)((float)((float)((float)v26 * v13) * v15) + v10);
    }
    while ( v6 < (int)v5 - 3 );
  }
  if ( v6 < (unsigned int)v5 )
  {
    v29 = v11 - v10;
    v30 = &out_pfFDNDelayTimes[v8];
    do
    {
      v31 = (float)(int)v6++;
      ++v30;
      v7 = 196314165 * v7 + 907633515;
      *(v30 - 1) = (float)((float)((float)(in_Tunings->fDensityDelayRdmPerc * 0.0099999998)
                                 * (float)((float)((float)(v31 * v29) * (float)(1.0 / (float)((int)v5 - 1))) + v10))
                         * (float)((float)v7 * 2.3283064e-10))
                 + (float)((float)((float)(v31 * v29) * (float)(1.0 / (float)((int)v5 - 1))) + v10);
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
void __fastcall DelayLengths::ComputeFDNInputDelayTimes(
        int in_uNumDelayLines,
        AlgorithmTunings *in_Tunings,
        float *out_pfFDNInputDelayTimes)
{
  unsigned int v3; // r11d
  __int64 v6; // rdi
  int v8; // eax
  float *v9; // r8
  unsigned int v10; // ecx
  __int64 v11; // rdx
  float v12; // xmm7_4
  float v13; // xmm2_4
  int v14; // ecx
  float v15; // xmm0_4
  int v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm0_4
  int v19; // ecx
  float *v20; // rdx
  __int64 v21; // r8

  v3 = 0;
  v6 = 0i64;
  v8 = 29101977;
  if ( in_uNumDelayLines >= 4 )
  {
    v9 = out_pfFDNInputDelayTimes + 2;
    v10 = ((unsigned int)(in_uNumDelayLines - 4) >> 2) + 1;
    v11 = v10;
    v3 = 4 * v10;
    v6 = 4i64 * v10;
    v12 = 1.0 / (float)in_uNumDelayLines;
    do
    {
      v13 = v12 * in_Tunings->fReverbUnitInputDelay;
      v9 += 4;
      v14 = 196314165 * v8 + 907633515;
      v15 = (float)v14;
      v16 = 196314165 * v14 + 907633515;
      v17 = (float)((float)(in_Tunings->fReverbUnitInputDelayRmdPerc * 0.0099999998) * v13)
          * (float)(v15 * 2.3283064e-10);
      v18 = (float)v16;
      v19 = 196314165 * v16 + 907633515;
      v8 = 196314165 * v19 + 907633515;
      *(v9 - 6) = v17 + v13;
      *(v9 - 5) = (float)((float)((float)(in_Tunings->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                * (float)(v12 * in_Tunings->fReverbUnitInputDelay))
                        * (float)(v18 * 2.3283064e-10))
                + (float)(v12 * in_Tunings->fReverbUnitInputDelay);
      *(v9 - 4) = (float)((float)((float)(in_Tunings->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                * (float)(v12 * in_Tunings->fReverbUnitInputDelay))
                        * (float)((float)v19 * 2.3283064e-10))
                + (float)(v12 * in_Tunings->fReverbUnitInputDelay);
      *(v9 - 3) = (float)((float)((float)(in_Tunings->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                * (float)(v12 * in_Tunings->fReverbUnitInputDelay))
                        * (float)((float)v8 * 2.3283064e-10))
                + (float)(v12 * in_Tunings->fReverbUnitInputDelay);
      --v11;
    }
    while ( v11 );
  }
  if ( v3 < in_uNumDelayLines )
  {
    v20 = &out_pfFDNInputDelayTimes[v6];
    v21 = in_uNumDelayLines - v3;
    do
    {
      ++v20;
      v8 = 196314165 * v8 + 907633515;
      *(v20 - 1) = (float)((float)((float)(in_Tunings->fReverbUnitInputDelayRmdPerc * 0.0099999998)
                                 * (float)((float)(1.0 / (float)in_uNumDelayLines) * in_Tunings->fReverbUnitInputDelay))
                         * (float)((float)v8 * 2.3283064e-10))
                 + (float)((float)(1.0 / (float)in_uNumDelayLines) * in_Tunings->fReverbUnitInputDelay);
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 104
// RVA: 0xAE5D30
void __fastcall DelayLengths::ComputeDiffusionFiltersDelayTimes(
        int in_uNumReverbUnits,
        AlgorithmTunings *in_Tunings,
        float *out_pfAPFDelayTimes)
{
  float fDiffusionDelayMax; // xmm4_4
  unsigned int v4; // r9d
  unsigned __int64 v6; // r10
  __int64 v7; // rdi
  int v8; // eax
  float *v9; // rbx
  unsigned int v10; // ecx
  __int64 v11; // r8
  int v12; // ecx
  float v13; // xmm0_4
  int v14; // ecx
  float v15; // xmm3_4
  float v16; // xmm0_4
  int v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm3_4
  float *v20; // r8
  __int64 v21; // r9
  float v22; // xmm2_4

  fDiffusionDelayMax = in_Tunings->fDiffusionDelayMax;
  v4 = 0;
  v6 = (unsigned int)in_uNumReverbUnits;
  v7 = 0i64;
  v8 = 3072007;
  if ( in_uNumReverbUnits >= 4 )
  {
    v9 = out_pfAPFDelayTimes + 2;
    v10 = ((unsigned int)(in_uNumReverbUnits - 4) >> 2) + 1;
    v11 = v10;
    v4 = 4 * v10;
    v7 = 4i64 * v10;
    do
    {
      v9 += 4;
      v12 = 196314165 * v8 + 907633515;
      v13 = (float)v12;
      v14 = 196314165 * v12 + 907633515;
      v15 = fDiffusionDelayMax * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(v9 - 6) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * fDiffusionDelayMax)
                        * (float)(v13 * 2.3283064e-10))
                + fDiffusionDelayMax;
      v16 = (float)v14;
      v17 = 196314165 * v14 + 907633515;
      v18 = v15 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      v8 = 196314165 * v17 + 907633515;
      *(v9 - 5) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v15)
                        * (float)(v16 * 2.3283064e-10))
                + v15;
      v19 = v18 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(v9 - 4) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v18)
                        * (float)((float)v17 * 2.3283064e-10))
                + v18;
      fDiffusionDelayMax = v19 * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(v9 - 3) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v19)
                        * (float)((float)v8 * 2.3283064e-10))
                + v19;
      --v11;
    }
    while ( v11 );
  }
  if ( v4 < (unsigned int)v6 )
  {
    v20 = &out_pfAPFDelayTimes[v7];
    v21 = (unsigned int)v6 - v4;
    do
    {
      v22 = fDiffusionDelayMax;
      ++v20;
      v8 = 196314165 * v8 + 907633515;
      fDiffusionDelayMax = fDiffusionDelayMax * (float)(in_Tunings->fDiffusionDelayScalePerc * 0.0099999998);
      *(v20 - 1) = (float)((float)((float)(in_Tunings->fDiffusionDelayRdmPerc * 0.0099999998) * v22)
                         * (float)((float)v8 * 2.3283064e-10))
                 + v22;
      --v21;
    }
    while ( v21 );
  }
  qsort(
    out_pfAPFDelayTimes,
    v6,
    4ui64,
    (int (__fastcall *)(const void *, const void *))DelayLengths::AkDelayQSortCompareFloat);
}

// File Line: 128
// RVA: 0xAE5F40
void __fastcall DelayLengths::MakePrimeNumber(unsigned int *in_uIn, unsigned int in_uPrevVal)
{
  __m128d v3; // xmm0
  int v4; // r9d
  int v5; // ecx
  unsigned int v6; // r8d

  if ( (*in_uIn & 1) == 0 )
    ++*in_uIn;
  v3 = 0i64;
  v3.m128d_f64[0] = (double)(int)*in_uIn;
  v4 = (int)_mm_sqrt_pd(v3).m128d_f64[0] + 1;
  while ( 1 )
  {
    v5 = 3;
    if ( v4 <= 3 )
      break;
    v6 = *in_uIn;
    while ( v6 % v5 )
    {
      v5 += 2;
      if ( v5 >= v4 )
        goto LABEL_8;
    }
LABEL_9:
    *in_uIn = v6 + 2;
  }
LABEL_8:
  v6 = *in_uIn;
  if ( *in_uIn == in_uPrevVal )
    goto LABEL_9;
}

// File Line: 165
// RVA: 0xAE5FA0
void __fastcall DelayLengths::ComputePrimeDelayLengths(
        float *in_pfDelayTimes,
        int in_uSampleRate,
        unsigned int in_uNumDelays,
        char *out_puDelayLengths)
{
  unsigned int v4; // ebx
  char *v7; // r10
  signed __int64 v8; // rsi
  float v9; // xmm2_4
  int v10; // edx
  __m128d v11; // xmm0
  int v12; // r9d
  int v13; // ecx
  unsigned int v14; // r8d
  unsigned int v15; // r11d
  __m128d v16; // xmm0
  int v17; // r9d
  int v18; // ecx
  unsigned int v19; // r8d

  if ( in_uNumDelays )
  {
    v4 = 0;
    v7 = out_puDelayLengths;
    v8 = (char *)in_pfDelayTimes - out_puDelayLengths;
    v9 = (float)in_uSampleRate;
    do
    {
      v10 = (int)(float)((float)(*(float *)&v7[v8] * 0.001) * v9);
      *(_DWORD *)v7 = v10;
      if ( !v4 )
      {
        if ( (v10 & 1) == 0 )
          *(_DWORD *)v7 = v10 + 1;
        v11 = 0i64;
        v11.m128d_f64[0] = (double)*(int *)v7;
        v12 = (int)_mm_sqrt_pd(v11).m128d_f64[0] + 1;
        while ( 1 )
        {
          v13 = 3;
          if ( v12 <= 3 )
          {
LABEL_11:
            v14 = *(_DWORD *)v7;
            if ( *(_DWORD *)v7 )
              goto LABEL_22;
          }
          else
          {
            v14 = *(_DWORD *)v7;
            while ( v14 % v13 )
            {
              v13 += 2;
              if ( v13 >= v12 )
                goto LABEL_11;
            }
          }
          *(_DWORD *)v7 = v14 + 2;
        }
      }
      v15 = *(_DWORD *)&out_puDelayLengths[4 * v4 - 4];
      if ( (v10 & 1) == 0 )
        *(_DWORD *)v7 = v10 + 1;
      v16 = 0i64;
      v16.m128d_f64[0] = (double)*(int *)v7;
      v17 = (int)_mm_sqrt_pd(v16).m128d_f64[0] + 1;
      while ( 1 )
      {
        v18 = 3;
        if ( v17 <= 3 )
          break;
        v19 = *(_DWORD *)v7;
        while ( v19 % v18 )
        {
          v18 += 2;
          if ( v18 >= v17 )
            goto LABEL_20;
        }
LABEL_21:
        *(_DWORD *)v7 = v19 + 2;
      }
LABEL_20:
      v19 = *(_DWORD *)v7;
      if ( *(_DWORD *)v7 == v15 )
        goto LABEL_21;
LABEL_22:
      ++v4;
      v7 += 4;
    }
    while ( v4 < in_uNumDelays );
  }
}

