// File Line: 104
// RVA: 0xAD3F80
void __fastcall CAkToneGen::ProcessWaveTableNoSweep(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  CAkToneGenParams *v3; // rax
  unsigned int v4; // esi
  float *v5; // rdi
  CAkToneGen *v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  unsigned int v13; // er9
  float v14; // xmm6_4
  signed int v15; // er10
  float v16; // xmm6_4
  float *v17; // rcx
  float v18; // xmm2_4
  __int64 v19; // rdx
  int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  __int64 v24; // rcx
  float v25; // xmm0_4
  float v26; // xmm0_4
  unsigned int v27; // eax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  unsigned int v31; // eax
  bool v32; // zf

  v3 = this->m_pSharedParams;
  v4 = in_uSampToProduce;
  v5 = out_pBuffer;
  v6 = this;
  v7 = v3->m_Params.fStartFreq;
  v8 = powf(10.0, v3->m_Params.fGain * 0.050000001);
  v9 = v6->m_GainRamp.m_fStepIncrement;
  v6->m_GainRamp.m_uRampCount = 0;
  v6->m_GainRamp.m_fTarget = v8;
  v10 = v8 - v6->m_GainRamp.m_fCurrent;
  v6->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v10) & _xmm) / v9);
  if ( v10 <= 0.0 )
    LODWORD(v9) ^= _xmm[0];
  v6->m_GainRamp.m_fInc = v9;
  v11 = v7 + v6->m_fStartFreqModifier;
  if ( v11 >= 0.001 )
  {
    v12 = v6->m_fOscMaxFreq;
    if ( v11 >= v12 )
      v11 = v12 - 1.0;
  }
  else
  {
    v11 = FLOAT_0_001;
  }
  v13 = v4;
  v14 = (float)(v11 * 512.0) / (float)(signed int)v6->m_uSampleRate;
  v15 = (signed int)v14;
  v6->m_fSampleInc = v14;
  v16 = v14 - (float)(signed int)v14;
  while ( v13 )
  {
    v17 = v6->m_pOscWaveTable;
    v18 = v6->m_fPhaseIndexFrac;
    --v13;
    v19 = v6->m_uPhaseIndex & 0x1FF;
    v20 = v6->m_uPhaseIndex + v15;
    v21 = (float)(v17[((v6->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - v17[v19]) * v18;
    v22 = v18 + v16;
    v23 = v21 + v17[v19];
    v6->m_fPhaseIndexFrac = v22;
    v6->m_uPhaseIndex = v20;
    if ( v22 > 1.0 )
    {
      v6->m_fPhaseIndexFrac = v22 - 1.0;
      v6->m_uPhaseIndex = v20 + 1;
    }
    v6->m_uPhaseIndex &= 0x1FFu;
    v24 = v6->m_uCurEnvSegment;
    if ( v6->m_uEnvSegmentCount >= v6->m_uEnvSegmentDur[v24] )
    {
      v6->m_uEnvSegmentCount = 0;
      v6->m_uCurEnvSegment = v24 + 1;
    }
    v25 = v6->m_fEnvInc[v6->m_uCurEnvSegment];
    ++v6->m_uEnvSegmentCount;
    v26 = v25 + v6->m_fEnvCurGain;
    v6->m_fEnvCurGain = v26;
    v27 = v6->m_GainRamp.m_uRampCount;
    v28 = v23 * v26;
    if ( v27 < v6->m_GainRamp.m_uRampLength )
    {
      v29 = v6->m_GainRamp.m_fInc + v6->m_GainRamp.m_fCurrent;
      v6->m_GainRamp.m_uRampCount = v27 + 1;
      v6->m_GainRamp.m_fCurrent = v29;
    }
    else
    {
      v6->m_GainRamp.m_fCurrent = v6->m_GainRamp.m_fTarget;
    }
    v30 = v28 * v6->m_GainRamp.m_fCurrent;
    v31 = ++v6->m_uIterOutSampCount;
    ++v5;
    *(v5 - 1) = v30;
    if ( v31 >= v6->m_uIterNumSamples )
    {
      v32 = v6->m_staticParams.eGenMode == 1;
      v6->m_uIterOutSampCount = 0;
      v6->m_uCurEnvSegment = 0;
      v6->m_uEnvSegmentCount = 0;
      if ( v32 || v6->m_iNumLoops == 1 )
        v6->m_fEnvCurGain = 0.0;
      else
        v6->m_fEnvCurGain = 1.0;
    }
  }
  v6->m_uTotalOutSampCount += v4;
}

// File Line: 199
// RVA: 0xAD3A10
void __fastcall CAkToneGen::ProcessWaveTableLinSweep(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  CAkToneGenParams *v3; // rax
  unsigned int v4; // esi
  float *v5; // rdi
  CAkToneGen *v6; // rbx
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  unsigned int v16; // er10
  float v17; // xmm6_4
  float *v18; // rcx
  unsigned int v19; // er8
  __int64 v20; // rdx
  __int64 v21; // rax
  float v22; // xmm3_4
  float v23; // xmm2_4
  int v24; // ecx
  float v25; // xmm3_4
  __int64 v26; // rcx
  float v27; // xmm0_4
  float v28; // xmm0_4
  unsigned int v29; // eax
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  unsigned int v33; // eax
  bool v34; // zf

  v3 = this->m_pSharedParams;
  v4 = in_uSampToProduce;
  v5 = out_pBuffer;
  v6 = this;
  v7 = v3->m_Params.fStartFreq;
  v8 = v3->m_Params.fStopFreq;
  v9 = powf(10.0, v3->m_Params.fGain * 0.050000001);
  v10 = v6->m_GainRamp.m_fStepIncrement;
  v6->m_GainRamp.m_uRampCount = 0;
  v6->m_GainRamp.m_fTarget = v9;
  v11 = v9 - v6->m_GainRamp.m_fCurrent;
  v6->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / v10);
  if ( v11 <= 0.0 )
    LODWORD(v10) ^= _xmm[0];
  v6->m_GainRamp.m_fInc = v10;
  v12 = v7 + v6->m_fStartFreqModifier;
  v13 = v8 + v6->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    v14 = v6->m_fOscMaxFreq;
    if ( v12 >= v14 )
      v12 = v14 - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = v6->m_fOscMaxFreq;
    if ( v13 >= v15 )
      v13 = v15 - 1.0;
  }
  else
  {
    v13 = FLOAT_0_001;
  }
  v16 = v4;
  v17 = (float)(v13 - v12) / (float)(signed int)v6->m_uIterNumSamples;
  v6->m_fFreqSweepScaleFactor = v17;
  while ( v16 )
  {
    v18 = v6->m_pOscWaveTable;
    v19 = v6->m_uPhaseIndex;
    --v16;
    v20 = v6->m_uPhaseIndex & 0x1FF;
    v21 = ((v6->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF;
    v22 = (float)((float)((float)((float)(signed int)v6->m_uIterOutSampCount * v17) + v12) * 512.0)
        / (float)(signed int)v6->m_uSampleRate;
    v6->m_fSampleInc = v22;
    v23 = (float)((float)(v18[v21] - v18[v20]) * v6->m_fPhaseIndexFrac) + v18[v20];
    v24 = v19 + (signed int)v22;
    v6->m_uPhaseIndex = v24;
    v25 = (float)(v22 - (float)(signed int)v22) + v6->m_fPhaseIndexFrac;
    v6->m_fPhaseIndexFrac = v25;
    if ( v25 > 1.0 )
    {
      v6->m_fPhaseIndexFrac = v25 - 1.0;
      v6->m_uPhaseIndex = v24 + 1;
    }
    v6->m_uPhaseIndex &= 0x1FFu;
    v26 = v6->m_uCurEnvSegment;
    if ( v6->m_uEnvSegmentCount >= v6->m_uEnvSegmentDur[v26] )
    {
      v6->m_uEnvSegmentCount = 0;
      v6->m_uCurEnvSegment = v26 + 1;
    }
    v27 = v6->m_fEnvInc[v6->m_uCurEnvSegment];
    ++v6->m_uEnvSegmentCount;
    v28 = v27 + v6->m_fEnvCurGain;
    v6->m_fEnvCurGain = v28;
    v29 = v6->m_GainRamp.m_uRampCount;
    v30 = v23 * v28;
    if ( v29 < v6->m_GainRamp.m_uRampLength )
    {
      v31 = v6->m_GainRamp.m_fCurrent + v6->m_GainRamp.m_fInc;
      v6->m_GainRamp.m_uRampCount = v29 + 1;
      v6->m_GainRamp.m_fCurrent = v31;
    }
    else
    {
      v6->m_GainRamp.m_fCurrent = v6->m_GainRamp.m_fTarget;
    }
    v32 = v30 * v6->m_GainRamp.m_fCurrent;
    v33 = ++v6->m_uIterOutSampCount;
    ++v5;
    *(v5 - 1) = v32;
    if ( v33 >= v6->m_uIterNumSamples )
    {
      v34 = v6->m_staticParams.eGenMode == 1;
      v6->m_uIterOutSampCount = 0;
      v6->m_uCurEnvSegment = 0;
      v6->m_uEnvSegmentCount = 0;
      if ( v34 || v6->m_iNumLoops == 1 )
        v6->m_fEnvCurGain = 0.0;
      else
        v6->m_fEnvCurGain = 1.0;
    }
  }
  v6->m_uTotalOutSampCount += v4;
}

// File Line: 307
// RVA: 0xAD3CB0
void __fastcall CAkToneGen::ProcessWaveTableLogSweep(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  CAkToneGenParams *v3; // rax
  unsigned int v4; // esi
  float *v5; // rdi
  CAkToneGen *v6; // rbx
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  bool v16; // r11
  float v17; // xmm6_4
  __m128 v18; // xmm0
  float v19; // xmm6_4
  unsigned int v20; // er10
  signed int v21; // eax
  __m128 v22; // xmm0
  float v23; // xmm2_4
  float *v24; // rcx
  unsigned int v25; // er8
  __int64 v26; // rdx
  __int64 v27; // rax
  float v28; // xmm2_4
  float v29; // xmm3_4
  int v30; // ecx
  float v31; // xmm2_4
  __int64 v32; // rcx
  float v33; // xmm0_4
  float v34; // xmm0_4
  unsigned int v35; // eax
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  unsigned int v39; // eax
  bool v40; // zf

  v3 = this->m_pSharedParams;
  v4 = in_uSampToProduce;
  v5 = out_pBuffer;
  v6 = this;
  v7 = v3->m_Params.fStartFreq;
  v8 = v3->m_Params.fStopFreq;
  v9 = powf(10.0, v3->m_Params.fGain * 0.050000001);
  v10 = v6->m_GainRamp.m_fStepIncrement;
  v6->m_GainRamp.m_uRampCount = 0;
  v6->m_GainRamp.m_fTarget = v9;
  v11 = v9 - v6->m_GainRamp.m_fCurrent;
  v6->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / v10);
  if ( v11 <= 0.0 )
    LODWORD(v10) ^= _xmm[0];
  v6->m_GainRamp.m_fInc = v10;
  v12 = v7 + v6->m_fStartFreqModifier;
  v13 = v8 + v6->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    v14 = v6->m_fOscMaxFreq;
    if ( v12 >= v14 )
      v12 = v14 - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = v6->m_fOscMaxFreq;
    if ( v13 >= v15 )
      v13 = v15 - 1.0;
  }
  else
  {
    v13 = FLOAT_0_001;
  }
  v18 = 0i64;
  v16 = v12 >= v13;
  v17 = v13 - v12;
  v18.m128_f32[0] = (float)(signed int)v6->m_uIterNumSamples;
  if ( v16 )
    v19 = v17 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  else
    v19 = v17 / (float)(v18.m128_f32[0] * v18.m128_f32[0]);
  v6->m_fFreqSweepScaleFactor = v19;
  v20 = v4;
  while ( v20 )
  {
    v21 = v6->m_uIterOutSampCount;
    --v20;
    if ( v16 )
    {
      v22 = 0i64;
      v22.m128_f32[0] = (float)v21;
      LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v22);
    }
    else
    {
      v23 = (float)v21 * (float)v21;
    }
    v24 = v6->m_pOscWaveTable;
    v25 = v6->m_uPhaseIndex;
    v26 = v6->m_uPhaseIndex & 0x1FF;
    v27 = ((v6->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF;
    v28 = (float)((float)((float)(v23 * v6->m_fFreqSweepScaleFactor) + v12) * 512.0)
        / (float)(signed int)v6->m_uSampleRate;
    v6->m_fSampleInc = v28;
    v29 = (float)((float)(v24[v27] - v24[v26]) * v6->m_fPhaseIndexFrac) + v24[v26];
    v30 = v25 + (signed int)v28;
    v6->m_uPhaseIndex = v30;
    v31 = (float)(v28 - (float)(signed int)v28) + v6->m_fPhaseIndexFrac;
    v6->m_fPhaseIndexFrac = v31;
    if ( v31 > 1.0 )
    {
      v6->m_fPhaseIndexFrac = v31 - 1.0;
      v6->m_uPhaseIndex = v30 + 1;
    }
    v6->m_uPhaseIndex &= 0x1FFu;
    v32 = v6->m_uCurEnvSegment;
    if ( v6->m_uEnvSegmentCount >= v6->m_uEnvSegmentDur[v32] )
    {
      v6->m_uEnvSegmentCount = 0;
      v6->m_uCurEnvSegment = v32 + 1;
    }
    v33 = v6->m_fEnvInc[v6->m_uCurEnvSegment];
    ++v6->m_uEnvSegmentCount;
    v34 = v33 + v6->m_fEnvCurGain;
    v6->m_fEnvCurGain = v34;
    v35 = v6->m_GainRamp.m_uRampCount;
    v36 = v29 * v34;
    if ( v35 < v6->m_GainRamp.m_uRampLength )
    {
      v37 = v6->m_GainRamp.m_fCurrent + v6->m_GainRamp.m_fInc;
      v6->m_GainRamp.m_uRampCount = v35 + 1;
      v6->m_GainRamp.m_fCurrent = v37;
    }
    else
    {
      v6->m_GainRamp.m_fCurrent = v6->m_GainRamp.m_fTarget;
    }
    v38 = v36 * v6->m_GainRamp.m_fCurrent;
    v39 = ++v6->m_uIterOutSampCount;
    ++v5;
    *(v5 - 1) = v38;
    if ( v39 >= v6->m_uIterNumSamples )
    {
      v40 = v6->m_staticParams.eGenMode == 1;
      v6->m_uIterOutSampCount = 0;
      v6->m_uCurEnvSegment = 0;
      v6->m_uEnvSegmentCount = 0;
      if ( v40 || v6->m_iNumLoops == 1 )
        v6->m_fEnvCurGain = 0.0;
      else
        v6->m_fEnvCurGain = 1.0;
    }
  }
  v6->m_uTotalOutSampCount += v4;
}

// File Line: 437
// RVA: 0xAD33F0
void __fastcall CAkToneGen::ProcessOversampledWaveTableNoSweep(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  CAkToneGenParams *v3; // rax
  unsigned int v4; // esi
  float *v5; // rdi
  CAkToneGen *v6; // rbx
  float v7; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  unsigned int v13; // er11
  float v14; // xmm7_4
  signed int v15; // er10
  float v16; // xmm7_4
  signed __int64 v17; // r9
  float *v18; // rcx
  float v19; // xmm1_4
  __int64 v20; // rdx
  int v21; // eax
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm3_4
  float v37; // xmm4_4
  float v38; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm6_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm5_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm5_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm5_4
  __int64 v55; // rcx
  float v56; // xmm0_4
  float v57; // xmm0_4
  unsigned int v58; // eax
  float v59; // xmm5_4
  float v60; // xmm0_4
  float v61; // xmm5_4
  unsigned int v62; // eax
  bool v63; // zf

  v3 = this->m_pSharedParams;
  v4 = in_uSampToProduce;
  v5 = out_pBuffer;
  v6 = this;
  v7 = v3->m_Params.fStartFreq;
  v8 = powf(10.0, v3->m_Params.fGain * 0.050000001);
  v9 = v6->m_GainRamp.m_fStepIncrement;
  v6->m_GainRamp.m_uRampCount = 0;
  v6->m_GainRamp.m_fTarget = v8;
  v10 = v8 - v6->m_GainRamp.m_fCurrent;
  v6->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v10) & _xmm) / v9);
  if ( v10 <= 0.0 )
    LODWORD(v9) ^= _xmm[0];
  v6->m_GainRamp.m_fInc = v9;
  v11 = v7 + v6->m_fStartFreqModifier;
  if ( v11 >= 0.001 )
  {
    v12 = v6->m_fOscMaxFreq;
    if ( v11 >= v12 )
      v11 = v12 - 1.0;
  }
  else
  {
    v11 = FLOAT_0_001;
  }
  v13 = v4;
  v14 = (float)(v11 * 512.0) / v6->m_fOverSamplingFrequency;
  v15 = (signed int)v14;
  v6->m_fSampleInc = v14;
  v16 = v14 - (float)(signed int)v14;
  while ( v13 )
  {
    --v13;
    v17 = 4i64;
    do
    {
      v18 = v6->m_pOscWaveTable;
      v19 = v6->m_fPhaseIndexFrac;
      v20 = v6->m_uPhaseIndex & 0x1FF;
      v21 = v6->m_uPhaseIndex + v15;
      v22 = (float)(v18[((v6->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - v18[v20]) * v19;
      v23 = v19 + v16;
      v24 = v22 + v18[v20];
      v6->m_fPhaseIndexFrac = v23;
      v6->m_uPhaseIndex = v21;
      if ( v23 > 1.0 )
      {
        v6->m_fPhaseIndexFrac = v23 - 1.0;
        v6->m_uPhaseIndex = v21 + 1;
      }
      v6->m_uPhaseIndex &= 0x1FFu;
      v25 = v6->m_LpFilters[0].m_fIn1;
      v26 = v6->m_LpFilters[0].m_fOut1;
      v27 = v6->m_LpFilters[0].m_fIn1;
      v28 = v6->m_LpFilters[0].m_fOut1;
      v29 = v24 * v6->m_LpFilters[0].m_fB0;
      v30 = v6->m_LpFilters[0].m_fB2;
      v6->m_LpFilters[0].m_fIn1 = v24;
      v31 = v28 * v6->m_LpFilters[0].m_fA1;
      v32 = v29 + (float)(v27 * v6->m_LpFilters[0].m_fB1);
      v33 = v6->m_LpFilters[0].m_fA2 * v6->m_LpFilters[0].m_fOut2;
      v34 = v30 * v6->m_LpFilters[0].m_fIn2;
      v6->m_LpFilters[0].m_fIn2 = v25;
      v6->m_LpFilters[0].m_fOut2 = v26;
      v35 = (float)(v32 + v34) - (float)(v31 + v33);
      v6->m_LpFilters[0].m_fOut1 = v35;
      v36 = v6->m_LpFilters[1].m_fIn1;
      v37 = v6->m_LpFilters[1].m_fOut1;
      v38 = v35 * v6->m_LpFilters[1].m_fB0;
      v39 = v6->m_LpFilters[1].m_fIn1 * v6->m_LpFilters[1].m_fB1;
      v40 = v6->m_LpFilters[1].m_fIn2;
      v41 = v6->m_LpFilters[1].m_fOut2;
      v6->m_LpFilters[1].m_fIn1 = v35;
      v42 = v41 * v6->m_LpFilters[1].m_fA2;
      v43 = v40 * v6->m_LpFilters[1].m_fB2;
      v6->m_LpFilters[1].m_fIn2 = v36;
      v6->m_LpFilters[1].m_fOut2 = v37;
      v44 = (float)((float)(v38 + v39) + v43) - (float)(v42 + (float)(v37 * v6->m_LpFilters[1].m_fA1));
      v6->m_LpFilters[1].m_fOut1 = v44;
      v45 = v6->m_LpFilters[2].m_fIn1;
      v46 = v6->m_LpFilters[2].m_fOut1;
      v47 = v44 * v6->m_LpFilters[2].m_fB0;
      v48 = v6->m_LpFilters[2].m_fIn1 * v6->m_LpFilters[2].m_fB1;
      v49 = v6->m_LpFilters[2].m_fOut1 * v6->m_LpFilters[2].m_fA1;
      v50 = v6->m_LpFilters[2].m_fB2;
      v6->m_LpFilters[2].m_fIn1 = v44;
      v51 = v48 + v47;
      v52 = v50 * v6->m_LpFilters[2].m_fIn2;
      v53 = v6->m_LpFilters[2].m_fA2 * v6->m_LpFilters[2].m_fOut2;
      v6->m_LpFilters[2].m_fIn2 = v45;
      v6->m_LpFilters[2].m_fOut2 = v46;
      v54 = (float)(v51 + v52) - (float)(v49 + v53);
      v6->m_LpFilters[2].m_fOut1 = v54;
      --v17;
    }
    while ( v17 );
    v55 = v6->m_uCurEnvSegment;
    if ( v6->m_uEnvSegmentCount >= v6->m_uEnvSegmentDur[v55] )
    {
      v6->m_uEnvSegmentCount = 0;
      v6->m_uCurEnvSegment = v55 + 1;
    }
    v56 = v6->m_fEnvInc[v6->m_uCurEnvSegment];
    ++v6->m_uEnvSegmentCount;
    v57 = v56 + v6->m_fEnvCurGain;
    v6->m_fEnvCurGain = v57;
    v58 = v6->m_GainRamp.m_uRampCount;
    v59 = v54 * v57;
    if ( v58 < v6->m_GainRamp.m_uRampLength )
    {
      v60 = v6->m_GainRamp.m_fCurrent + v6->m_GainRamp.m_fInc;
      v6->m_GainRamp.m_uRampCount = v58 + 1;
      v6->m_GainRamp.m_fCurrent = v60;
    }
    else
    {
      v6->m_GainRamp.m_fCurrent = v6->m_GainRamp.m_fTarget;
    }
    v61 = v59 * v6->m_GainRamp.m_fCurrent;
    v62 = ++v6->m_uIterOutSampCount;
    ++v5;
    *(v5 - 1) = v61;
    if ( v62 >= v6->m_uIterNumSamples )
    {
      v63 = v6->m_staticParams.eGenMode == 1;
      v6->m_uIterOutSampCount = 0;
      v6->m_uCurEnvSegment = 0;
      v6->m_uEnvSegmentCount = 0;
      if ( v63 || v6->m_iNumLoops == 1 )
        v6->m_fEnvCurGain = 0.0;
      else
        v6->m_fEnvCurGain = 1.0;
    }
  }
  v6->m_uTotalOutSampCount += v4;
}

// File Line: 541
// RVA: 0xAD2AD0
void __fastcall CAkToneGen::ProcessOversampledWaveTableLinSweep(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  CAkToneGenParams *v3; // rax
  unsigned int v4; // esi
  float *v5; // rdi
  CAkToneGen *v6; // rbx
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  unsigned int v16; // er11
  signed __int64 v17; // r10
  float v18; // xmm7_4
  signed int v19; // er9
  float v20; // xmm7_4
  float *v21; // rcx
  float v22; // xmm1_4
  __int64 v23; // rdx
  int v24; // eax
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm6_4
  float v48; // xmm3_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm5_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm5_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm5_4
  __int64 v58; // rcx
  float v59; // xmm0_4
  float v60; // xmm0_4
  unsigned int v61; // eax
  float v62; // xmm5_4
  float v63; // xmm0_4
  float v64; // xmm5_4
  unsigned int v65; // eax
  bool v66; // zf

  v3 = this->m_pSharedParams;
  v4 = in_uSampToProduce;
  v5 = out_pBuffer;
  v6 = this;
  v7 = v3->m_Params.fStartFreq;
  v8 = v3->m_Params.fStopFreq;
  v9 = powf(10.0, v3->m_Params.fGain * 0.050000001);
  v10 = v6->m_GainRamp.m_fStepIncrement;
  v6->m_GainRamp.m_uRampCount = 0;
  v6->m_GainRamp.m_fTarget = v9;
  v11 = v9 - v6->m_GainRamp.m_fCurrent;
  v6->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / v10);
  if ( v11 <= 0.0 )
    LODWORD(v10) ^= _xmm[0];
  v6->m_GainRamp.m_fInc = v10;
  v12 = v7 + v6->m_fStartFreqModifier;
  v13 = v8 + v6->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    v14 = v6->m_fOscMaxFreq;
    if ( v12 >= v14 )
      v12 = v14 - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = v6->m_fOscMaxFreq;
    if ( v13 >= v15 )
      v13 = v15 - 1.0;
  }
  else
  {
    v13 = FLOAT_0_001;
  }
  v16 = v4;
  v6->m_fFreqSweepScaleFactor = (float)(v13 - v12) / (float)(4 * v6->m_uIterNumSamples);
  while ( v16 )
  {
    --v16;
    v17 = 4i64;
    v18 = (float)((float)((float)((float)(4 * v6->m_uIterOutSampCount) * v6->m_fFreqSweepScaleFactor) + v12) * 512.0)
        / v6->m_fOverSamplingFrequency;
    v19 = (signed int)v18;
    v6->m_fSampleInc = v18;
    v20 = v18 - (float)(signed int)v18;
    do
    {
      v21 = v6->m_pOscWaveTable;
      v22 = v6->m_fPhaseIndexFrac;
      v23 = v6->m_uPhaseIndex & 0x1FF;
      v24 = v6->m_uPhaseIndex + v19;
      v25 = (float)(v21[((v6->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - v21[v23]) * v22;
      v26 = v22 + v20;
      v27 = v25 + v21[v23];
      v6->m_fPhaseIndexFrac = v26;
      v6->m_uPhaseIndex = v24;
      if ( v26 > 1.0 )
      {
        v6->m_fPhaseIndexFrac = v26 - 1.0;
        v6->m_uPhaseIndex = v24 + 1;
      }
      v6->m_uPhaseIndex &= 0x1FFu;
      v28 = v6->m_LpFilters[0].m_fIn1;
      v29 = v6->m_LpFilters[0].m_fOut1;
      v30 = v6->m_LpFilters[0].m_fIn1;
      v31 = v6->m_LpFilters[0].m_fOut1;
      v32 = v27 * v6->m_LpFilters[0].m_fB0;
      v33 = v6->m_LpFilters[0].m_fB2;
      v6->m_LpFilters[0].m_fIn1 = v27;
      v34 = v31 * v6->m_LpFilters[0].m_fA1;
      v35 = (float)(v30 * v6->m_LpFilters[0].m_fB1) + v32;
      v36 = v6->m_LpFilters[0].m_fA2 * v6->m_LpFilters[0].m_fOut2;
      v37 = v33 * v6->m_LpFilters[0].m_fIn2;
      v6->m_LpFilters[0].m_fIn2 = v28;
      v6->m_LpFilters[0].m_fOut2 = v29;
      v38 = (float)(v35 + v37) - (float)(v34 + v36);
      v6->m_LpFilters[0].m_fOut1 = v38;
      v39 = v6->m_LpFilters[1].m_fIn1;
      v40 = v6->m_LpFilters[1].m_fOut1;
      v41 = v38 * v6->m_LpFilters[1].m_fB0;
      v42 = v6->m_LpFilters[1].m_fIn1 * v6->m_LpFilters[1].m_fB1;
      v43 = v6->m_LpFilters[1].m_fIn2;
      v44 = v6->m_LpFilters[1].m_fOut2;
      v6->m_LpFilters[1].m_fIn1 = v38;
      v45 = v44 * v6->m_LpFilters[1].m_fA2;
      v46 = v43 * v6->m_LpFilters[1].m_fB2;
      v6->m_LpFilters[1].m_fIn2 = v39;
      v6->m_LpFilters[1].m_fOut2 = v40;
      v47 = (float)((float)(v42 + v41) + v46) - (float)(v45 + (float)(v40 * v6->m_LpFilters[1].m_fA1));
      v6->m_LpFilters[1].m_fOut1 = v47;
      v48 = v6->m_LpFilters[2].m_fIn1;
      v49 = v6->m_LpFilters[2].m_fOut1;
      v50 = v47 * v6->m_LpFilters[2].m_fB0;
      v51 = v6->m_LpFilters[2].m_fIn1 * v6->m_LpFilters[2].m_fB1;
      v52 = v6->m_LpFilters[2].m_fOut1 * v6->m_LpFilters[2].m_fA1;
      v53 = v6->m_LpFilters[2].m_fB2;
      v6->m_LpFilters[2].m_fIn1 = v47;
      v54 = v51 + v50;
      v55 = v53 * v6->m_LpFilters[2].m_fIn2;
      v56 = v6->m_LpFilters[2].m_fA2 * v6->m_LpFilters[2].m_fOut2;
      v6->m_LpFilters[2].m_fIn2 = v48;
      v6->m_LpFilters[2].m_fOut2 = v49;
      v57 = (float)(v54 + v55) - (float)(v52 + v56);
      v6->m_LpFilters[2].m_fOut1 = v57;
      --v17;
    }
    while ( v17 );
    v58 = v6->m_uCurEnvSegment;
    if ( v6->m_uEnvSegmentCount >= v6->m_uEnvSegmentDur[v58] )
    {
      v6->m_uEnvSegmentCount = 0;
      v6->m_uCurEnvSegment = v58 + 1;
    }
    v59 = v6->m_fEnvInc[v6->m_uCurEnvSegment];
    ++v6->m_uEnvSegmentCount;
    v60 = v59 + v6->m_fEnvCurGain;
    v6->m_fEnvCurGain = v60;
    v61 = v6->m_GainRamp.m_uRampCount;
    v62 = v57 * v60;
    if ( v61 < v6->m_GainRamp.m_uRampLength )
    {
      v63 = v6->m_GainRamp.m_fCurrent + v6->m_GainRamp.m_fInc;
      v6->m_GainRamp.m_uRampCount = v61 + 1;
      v6->m_GainRamp.m_fCurrent = v63;
    }
    else
    {
      v6->m_GainRamp.m_fCurrent = v6->m_GainRamp.m_fTarget;
    }
    v64 = v62 * v6->m_GainRamp.m_fCurrent;
    v65 = ++v6->m_uIterOutSampCount;
    ++v5;
    *(v5 - 1) = v64;
    if ( v65 >= v6->m_uIterNumSamples )
    {
      v66 = v6->m_staticParams.eGenMode == 1;
      v6->m_uIterOutSampCount = 0;
      v6->m_uCurEnvSegment = 0;
      v6->m_uEnvSegmentCount = 0;
      if ( v66 || v6->m_iNumLoops == 1 )
        v6->m_fEnvCurGain = 0.0;
      else
        v6->m_fEnvCurGain = 1.0;
    }
  }
  v6->m_uTotalOutSampCount += v4;
}

// File Line: 661
// RVA: 0xAD2F40
void __fastcall CAkToneGen::ProcessOversampledWaveTableLogSweep(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  unsigned int v3; // esi
  float *v4; // rdi
  CAkToneGen *v5; // rbx
  CAkToneGenParams *v6; // rax
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  bool v16; // bp
  float v17; // xmm6_4
  __m128 v18; // xmm0
  float v19; // xmm6_4
  unsigned int v20; // er11
  __m128 v21; // xmm7
  float v22; // xmm7_4
  signed __int64 v23; // r10
  float v24; // xmm7_4
  signed int v25; // er9
  float v26; // xmm7_4
  float *v27; // rcx
  float v28; // xmm1_4
  __int64 v29; // rdx
  int v30; // eax
  float v31; // xmm6_4
  float v32; // xmm1_4
  float v33; // xmm6_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm5_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm6_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm6_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm5_4
  float v61; // xmm1_4
  float v62; // xmm0_4
  float v63; // xmm5_4
  __int64 v64; // rcx
  float v65; // xmm0_4
  float v66; // xmm0_4
  unsigned int v67; // eax
  float v68; // xmm5_4
  float v69; // xmm0_4
  float v70; // xmm5_4
  unsigned int v71; // eax
  bool v72; // zf

  v3 = in_uSampToProduce;
  v4 = out_pBuffer;
  v5 = this;
  v6 = this->m_pSharedParams;
  v7 = v6->m_Params.fStartFreq;
  v8 = v6->m_Params.fStopFreq;
  v9 = powf(10.0, v6->m_Params.fGain * 0.050000001);
  v10 = v5->m_GainRamp.m_fStepIncrement;
  v5->m_GainRamp.m_uRampCount = 0;
  v5->m_GainRamp.m_fTarget = v9;
  v11 = v9 - v5->m_GainRamp.m_fCurrent;
  v5->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / v10);
  if ( v11 <= 0.0 )
    LODWORD(v10) ^= _xmm[0];
  v5->m_GainRamp.m_fInc = v10;
  v12 = v7 + v5->m_fStartFreqModifier;
  v13 = v8 + v5->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    v14 = v5->m_fOscMaxFreq;
    if ( v12 >= v14 )
      v12 = v14 - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = v5->m_fOscMaxFreq;
    if ( v13 >= v15 )
      v13 = v15 - 1.0;
  }
  else
  {
    v13 = FLOAT_0_001;
  }
  v18 = 0i64;
  v16 = v12 >= v13;
  v17 = v13 - v12;
  v18.m128_f32[0] = (float)(signed int)v5->m_uIterNumSamples * 4.0;
  if ( v16 )
    v19 = v17 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  else
    v19 = v17 / (float)(v18.m128_f32[0] * v18.m128_f32[0]);
  v5->m_fFreqSweepScaleFactor = v19;
  v20 = v3;
  while ( v20 )
  {
    v21 = 0i64;
    --v20;
    v21.m128_f32[0] = (float)(4 * v5->m_uIterOutSampCount);
    if ( v16 )
      LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
    else
      v22 = v21.m128_f32[0] * v21.m128_f32[0];
    v23 = 4i64;
    v24 = (float)((float)((float)(v22 * v5->m_fFreqSweepScaleFactor) + v12) * 512.0) / v5->m_fOverSamplingFrequency;
    v25 = (signed int)v24;
    v5->m_fSampleInc = v24;
    v26 = v24 - (float)(signed int)v24;
    do
    {
      v27 = v5->m_pOscWaveTable;
      v28 = v5->m_fPhaseIndexFrac;
      v29 = v5->m_uPhaseIndex & 0x1FF;
      v30 = v5->m_uPhaseIndex + v25;
      v31 = (float)(v27[((v5->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - v27[v29]) * v28;
      v32 = v28 + v26;
      v33 = v31 + v27[v29];
      v5->m_fPhaseIndexFrac = v32;
      v5->m_uPhaseIndex = v30;
      if ( v32 > 1.0 )
      {
        v5->m_fPhaseIndexFrac = v32 - 1.0;
        v5->m_uPhaseIndex = v30 + 1;
      }
      v5->m_uPhaseIndex &= 0x1FFu;
      v34 = v5->m_LpFilters[0].m_fIn1;
      v35 = v5->m_LpFilters[0].m_fOut1;
      v36 = v5->m_LpFilters[0].m_fIn1;
      v37 = v5->m_LpFilters[0].m_fOut1;
      v38 = v33 * v5->m_LpFilters[0].m_fB0;
      v39 = v5->m_LpFilters[0].m_fB2;
      v5->m_LpFilters[0].m_fIn1 = v33;
      v40 = v37 * v5->m_LpFilters[0].m_fA1;
      v41 = (float)(v36 * v5->m_LpFilters[0].m_fB1) + v38;
      v42 = v5->m_LpFilters[0].m_fA2 * v5->m_LpFilters[0].m_fOut2;
      v43 = v39 * v5->m_LpFilters[0].m_fIn2;
      v5->m_LpFilters[0].m_fIn2 = v34;
      v5->m_LpFilters[0].m_fOut2 = v35;
      v44 = (float)(v41 + v43) - (float)(v40 + v42);
      v5->m_LpFilters[0].m_fOut1 = v44;
      v45 = v5->m_LpFilters[1].m_fIn1;
      v46 = v5->m_LpFilters[1].m_fOut1;
      v47 = v44 * v5->m_LpFilters[1].m_fB0;
      v48 = v5->m_LpFilters[1].m_fIn1 * v5->m_LpFilters[1].m_fB1;
      v49 = v5->m_LpFilters[1].m_fIn2;
      v50 = v5->m_LpFilters[1].m_fOut2;
      v5->m_LpFilters[1].m_fIn1 = v44;
      v51 = v50 * v5->m_LpFilters[1].m_fA2;
      v52 = v49 * v5->m_LpFilters[1].m_fB2;
      v5->m_LpFilters[1].m_fIn2 = v45;
      v5->m_LpFilters[1].m_fOut2 = v46;
      v53 = (float)((float)(v48 + v47) + v52) - (float)(v51 + (float)(v46 * v5->m_LpFilters[1].m_fA1));
      v5->m_LpFilters[1].m_fOut1 = v53;
      v54 = v5->m_LpFilters[2].m_fIn1;
      v55 = v5->m_LpFilters[2].m_fOut1;
      v56 = v53 * v5->m_LpFilters[2].m_fB0;
      v57 = v5->m_LpFilters[2].m_fIn1 * v5->m_LpFilters[2].m_fB1;
      v58 = v5->m_LpFilters[2].m_fOut1 * v5->m_LpFilters[2].m_fA1;
      v59 = v5->m_LpFilters[2].m_fB2;
      v5->m_LpFilters[2].m_fIn1 = v53;
      v60 = v56 + v57;
      v61 = v59 * v5->m_LpFilters[2].m_fIn2;
      v62 = v5->m_LpFilters[2].m_fA2 * v5->m_LpFilters[2].m_fOut2;
      v5->m_LpFilters[2].m_fIn2 = v54;
      v5->m_LpFilters[2].m_fOut2 = v55;
      v63 = (float)(v60 + v61) - (float)(v58 + v62);
      v5->m_LpFilters[2].m_fOut1 = v63;
      --v23;
    }
    while ( v23 );
    v64 = v5->m_uCurEnvSegment;
    if ( v5->m_uEnvSegmentCount >= v5->m_uEnvSegmentDur[v64] )
    {
      v5->m_uEnvSegmentCount = 0;
      v5->m_uCurEnvSegment = v64 + 1;
    }
    v65 = v5->m_fEnvInc[v5->m_uCurEnvSegment];
    ++v5->m_uEnvSegmentCount;
    v66 = v65 + v5->m_fEnvCurGain;
    v5->m_fEnvCurGain = v66;
    v67 = v5->m_GainRamp.m_uRampCount;
    v68 = v63 * v66;
    if ( v67 < v5->m_GainRamp.m_uRampLength )
    {
      v69 = v5->m_GainRamp.m_fCurrent + v5->m_GainRamp.m_fInc;
      v5->m_GainRamp.m_uRampCount = v67 + 1;
      v5->m_GainRamp.m_fCurrent = v69;
    }
    else
    {
      v5->m_GainRamp.m_fCurrent = v5->m_GainRamp.m_fTarget;
    }
    v70 = v68 * v5->m_GainRamp.m_fCurrent;
    v71 = ++v5->m_uIterOutSampCount;
    ++v4;
    *(v4 - 1) = v70;
    if ( v71 >= v5->m_uIterNumSamples )
    {
      v72 = v5->m_staticParams.eGenMode == 1;
      v5->m_uIterOutSampCount = 0;
      v5->m_uCurEnvSegment = 0;
      v5->m_uEnvSegmentCount = 0;
      if ( v72 || v5->m_iNumLoops == 1 )
        v5->m_fEnvCurGain = 0.0;
      else
        v5->m_fEnvCurGain = 1.0;
    }
  }
  v5->m_uTotalOutSampCount += v3;
}

// File Line: 804
// RVA: 0xAD41D0
void __fastcall CAkToneGen::ProcessWhiteNoise(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  unsigned int v3; // esi
  float *v4; // rdi
  CAkToneGen *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  unsigned int v9; // edx
  __int64 v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  unsigned int v18; // eax
  bool v19; // zf

  v3 = in_uSampToProduce;
  v4 = out_pBuffer;
  v5 = this;
  v6 = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  v7 = v5->m_GainRamp.m_fStepIncrement;
  v5->m_GainRamp.m_uRampCount = 0;
  v5->m_GainRamp.m_fTarget = v6;
  v8 = v6 - v5->m_GainRamp.m_fCurrent;
  v5->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v8) & _xmm) / v7);
  if ( v8 <= 0.0 )
    LODWORD(v7) ^= _xmm[0];
  v5->m_GainRamp.m_fInc = v7;
  v9 = v3;
  while ( v9 )
  {
    --v9;
    CAkToneGen::s_uSeedVal = 196314165 * CAkToneGen::s_uSeedVal + 907633515;
    v10 = v5->m_uCurEnvSegment;
    v11 = (float)(signed int)CAkToneGen::s_uSeedVal * 4.6566129e-10;
    if ( v5->m_uEnvSegmentCount >= v5->m_uEnvSegmentDur[v10] )
    {
      v5->m_uEnvSegmentCount = 0;
      v5->m_uCurEnvSegment = v10 + 1;
    }
    v12 = v5->m_fEnvInc[v5->m_uCurEnvSegment];
    ++v5->m_uEnvSegmentCount;
    v13 = v12 + v5->m_fEnvCurGain;
    v5->m_fEnvCurGain = v13;
    v14 = v5->m_GainRamp.m_uRampCount;
    v15 = v11 * v13;
    if ( v14 < v5->m_GainRamp.m_uRampLength )
    {
      v16 = v5->m_GainRamp.m_fCurrent + v5->m_GainRamp.m_fInc;
      v5->m_GainRamp.m_uRampCount = v14 + 1;
      v5->m_GainRamp.m_fCurrent = v16;
    }
    else
    {
      v5->m_GainRamp.m_fCurrent = v5->m_GainRamp.m_fTarget;
    }
    v17 = v15 * v5->m_GainRamp.m_fCurrent;
    v18 = ++v5->m_uIterOutSampCount;
    ++v4;
    *(v4 - 1) = v17;
    if ( v18 >= v5->m_uIterNumSamples )
    {
      v19 = v5->m_staticParams.eGenMode == 1;
      v5->m_uIterOutSampCount = 0;
      v5->m_uCurEnvSegment = 0;
      v5->m_uEnvSegmentCount = 0;
      if ( v19 || v5->m_iNumLoops == 1 )
        v5->m_fEnvCurGain = 0.0;
      else
        v5->m_fEnvCurGain = 1.0;
    }
  }
  v5->m_uTotalOutSampCount += v3;
}

// File Line: 848
// RVA: 0xAD37E0
void __fastcall CAkToneGen::ProcessPinkNoise(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  unsigned int v3; // esi
  float *v4; // rdi
  CAkToneGen *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  unsigned int v9; // edx
  bool v10; // zf
  unsigned int v11; // eax
  __int64 i; // rcx
  float *v13; // rax
  float v14; // xmm1_4
  __int64 v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  unsigned int v19; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  unsigned int v23; // eax

  v3 = in_uSampToProduce;
  v4 = out_pBuffer;
  v5 = this;
  v6 = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  v7 = v5->m_GainRamp.m_fStepIncrement;
  v5->m_GainRamp.m_uRampCount = 0;
  v5->m_GainRamp.m_fTarget = v6;
  v8 = v6 - v5->m_GainRamp.m_fCurrent;
  v5->m_GainRamp.m_uRampLength = (signed int)(float)(COERCE_FLOAT(LODWORD(v8) & _xmm) / v7);
  if ( v8 <= 0.0 )
    LODWORD(v7) ^= _xmm[0];
  v5->m_GainRamp.m_fInc = v7;
  v9 = v3;
  while ( v9 )
  {
    --v9;
    v10 = (v5->m_uPinkNoiseIndMask & (v5->m_uPinkNoiseInd + 1)) == 0;
    v11 = v5->m_uPinkNoiseIndMask & (v5->m_uPinkNoiseInd + 1);
    v5->m_uPinkNoiseInd = v11;
    if ( !v10 )
    {
      for ( i = 0i64; !(v11 & 1); i = (unsigned int)(i + 1) )
        v11 >>= 1;
      v5->m_fPinkNoiseRunSum = v5->m_fPinkNoiseRunSum - v5->m_pPinkNoiseRandGen[i];
      CAkToneGen::s_uSeedVal = 196314165 * CAkToneGen::s_uSeedVal + 907633515;
      v13 = v5->m_pPinkNoiseRandGen;
      v14 = (float)(signed int)CAkToneGen::s_uSeedVal * 4.6566129e-10;
      v5->m_fPinkNoiseRunSum = v14 + v5->m_fPinkNoiseRunSum;
      v13[i] = v14;
    }
    CAkToneGen::s_uSeedVal = 196314165 * CAkToneGen::s_uSeedVal + 907633515;
    v15 = v5->m_uCurEnvSegment;
    v16 = (float)((float)((float)(signed int)CAkToneGen::s_uSeedVal * 4.6566129e-10) + v5->m_fPinkNoiseRunSum)
        * v5->m_fNoiseScale;
    if ( v5->m_uEnvSegmentCount >= v5->m_uEnvSegmentDur[v15] )
    {
      v5->m_uEnvSegmentCount = 0;
      v5->m_uCurEnvSegment = v15 + 1;
    }
    v17 = v5->m_fEnvInc[v5->m_uCurEnvSegment];
    ++v5->m_uEnvSegmentCount;
    v18 = v17 + v5->m_fEnvCurGain;
    v5->m_fEnvCurGain = v18;
    v19 = v5->m_GainRamp.m_uRampCount;
    v20 = v16 * v18;
    if ( v19 < v5->m_GainRamp.m_uRampLength )
    {
      v21 = v5->m_GainRamp.m_fInc + v5->m_GainRamp.m_fCurrent;
      v5->m_GainRamp.m_uRampCount = v19 + 1;
      v5->m_GainRamp.m_fCurrent = v21;
    }
    else
    {
      v5->m_GainRamp.m_fCurrent = v5->m_GainRamp.m_fTarget;
    }
    v22 = v20 * v5->m_GainRamp.m_fCurrent;
    if ( v22 > -1.0 )
    {
      if ( v22 >= 1.0 )
        v22 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v22 = FLOAT_N1_0;
    }
    v23 = ++v5->m_uIterOutSampCount;
    *v4 = v22;
    ++v4;
    if ( v23 >= v5->m_uIterNumSamples )
    {
      v10 = v5->m_staticParams.eGenMode == 1;
      v5->m_uIterOutSampCount = 0;
      v5->m_uCurEnvSegment = 0;
      v5->m_uEnvSegmentCount = 0;
      if ( v10 || v5->m_iNumLoops == 1 )
        v5->m_fEnvCurGain = 0.0;
      else
        v5->m_fEnvCurGain = 1.0;
    }
  }
  v5->m_uTotalOutSampCount += v3;
}

