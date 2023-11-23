// File Line: 104
// RVA: 0xAD3F80
void __fastcall CAkToneGen::ProcessWaveTableNoSweep(
        CAkToneGen *this,
        float *out_pBuffer,
        unsigned int in_uSampToProduce)
{
  CAkToneGenParams *m_pSharedParams; // rax
  float fStartFreq; // xmm6_4
  float v8; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm6_4
  float m_fOscMaxFreq; // xmm0_4
  unsigned int v13; // r9d
  float v14; // xmm6_4
  int v15; // r10d
  float v16; // xmm6_4
  float *m_pOscWaveTable; // rcx
  float m_fPhaseIndexFrac; // xmm2_4
  __int64 v19; // rdx
  unsigned int v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  __int64 m_uCurEnvSegment; // rcx
  float v25; // xmm0_4
  float v26; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  unsigned int v31; // eax
  bool v32; // zf

  m_pSharedParams = this->m_pSharedParams;
  fStartFreq = m_pSharedParams->m_Params.fStartFreq;
  v8 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v8;
  v10 = v8 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v10) & _xmm) / m_fStepIncrement);
  if ( v10 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v11 = fStartFreq + this->m_fStartFreqModifier;
  if ( v11 >= 0.001 )
  {
    m_fOscMaxFreq = this->m_fOscMaxFreq;
    if ( v11 >= m_fOscMaxFreq )
      v11 = m_fOscMaxFreq - 1.0;
  }
  else
  {
    v11 = FLOAT_0_001;
  }
  v13 = in_uSampToProduce;
  v14 = (float)(v11 * 512.0) / (float)(int)this->m_uSampleRate;
  v15 = (int)v14;
  this->m_fSampleInc = v14;
  v16 = v14 - (float)(int)v14;
  while ( v13 )
  {
    m_pOscWaveTable = this->m_pOscWaveTable;
    m_fPhaseIndexFrac = this->m_fPhaseIndexFrac;
    --v13;
    v19 = this->m_uPhaseIndex & 0x1FF;
    v20 = this->m_uPhaseIndex + v15;
    v21 = (float)(m_pOscWaveTable[((this->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - m_pOscWaveTable[v19])
        * m_fPhaseIndexFrac;
    v22 = m_fPhaseIndexFrac + v16;
    v23 = v21 + m_pOscWaveTable[v19];
    this->m_fPhaseIndexFrac = v22;
    this->m_uPhaseIndex = v20;
    if ( v22 > 1.0 )
    {
      this->m_fPhaseIndexFrac = v22 - 1.0;
      this->m_uPhaseIndex = v20 + 1;
    }
    this->m_uPhaseIndex &= 0x1FFu;
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v25 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v26 = v25 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v26;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v28 = v23 * v26;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v29 = this->m_GainRamp.m_fInc + this->m_GainRamp.m_fCurrent;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v29;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v30 = v28 * this->m_GainRamp.m_fCurrent;
    v31 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v30;
    if ( v31 >= this->m_uIterNumSamples )
    {
      v32 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v32 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 199
// RVA: 0xAD3A10
void __fastcall CAkToneGen::ProcessWaveTableLinSweep(
        CAkToneGen *this,
        float *out_pBuffer,
        unsigned int in_uSampToProduce)
{
  CAkToneGenParams *m_pSharedParams; // rax
  float fStartFreq; // xmm7_4
  float fStopFreq; // xmm6_4
  float v9; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float m_fOscMaxFreq; // xmm1_4
  float v15; // xmm0_4
  unsigned int v16; // r10d
  float v17; // xmm6_4
  float *m_pOscWaveTable; // rcx
  unsigned int m_uPhaseIndex; // r8d
  __int64 v20; // rax
  float v21; // xmm3_4
  float v22; // xmm2_4
  unsigned int v23; // ecx
  float v24; // xmm3_4
  __int64 m_uCurEnvSegment; // rcx
  float v26; // xmm0_4
  float v27; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  unsigned int v32; // eax
  bool v33; // zf

  m_pSharedParams = this->m_pSharedParams;
  fStartFreq = m_pSharedParams->m_Params.fStartFreq;
  fStopFreq = m_pSharedParams->m_Params.fStopFreq;
  v9 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v9;
  v11 = v9 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / m_fStepIncrement);
  if ( v11 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v12 = fStartFreq + this->m_fStartFreqModifier;
  v13 = fStopFreq + this->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    m_fOscMaxFreq = this->m_fOscMaxFreq;
    if ( v12 >= m_fOscMaxFreq )
      v12 = m_fOscMaxFreq - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = this->m_fOscMaxFreq;
    if ( v13 >= v15 )
      v13 = v15 - 1.0;
  }
  else
  {
    v13 = FLOAT_0_001;
  }
  v16 = in_uSampToProduce;
  v17 = (float)(v13 - v12) / (float)(int)this->m_uIterNumSamples;
  this->m_fFreqSweepScaleFactor = v17;
  while ( v16 )
  {
    m_pOscWaveTable = this->m_pOscWaveTable;
    m_uPhaseIndex = this->m_uPhaseIndex;
    --v16;
    v20 = ((this->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF;
    v21 = (float)((float)((float)((float)(int)this->m_uIterOutSampCount * v17) + v12) * 512.0)
        / (float)(int)this->m_uSampleRate;
    this->m_fSampleInc = v21;
    v22 = (float)((float)(m_pOscWaveTable[v20] - m_pOscWaveTable[m_uPhaseIndex & 0x1FF]) * this->m_fPhaseIndexFrac)
        + m_pOscWaveTable[m_uPhaseIndex & 0x1FF];
    v23 = m_uPhaseIndex + (int)v21;
    this->m_uPhaseIndex = v23;
    v24 = (float)(v21 - (float)(int)v21) + this->m_fPhaseIndexFrac;
    this->m_fPhaseIndexFrac = v24;
    if ( v24 > 1.0 )
    {
      this->m_fPhaseIndexFrac = v24 - 1.0;
      this->m_uPhaseIndex = v23 + 1;
    }
    this->m_uPhaseIndex &= 0x1FFu;
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v26 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v27 = v26 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v27;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v29 = v22 * v27;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v30 = this->m_GainRamp.m_fCurrent + this->m_GainRamp.m_fInc;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v30;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v31 = v29 * this->m_GainRamp.m_fCurrent;
    v32 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v31;
    if ( v32 >= this->m_uIterNumSamples )
    {
      v33 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v33 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 307
// RVA: 0xAD3CB0
void __fastcall CAkToneGen::ProcessWaveTableLogSweep(
        CAkToneGen *this,
        float *out_pBuffer,
        unsigned int in_uSampToProduce)
{
  CAkToneGenParams *m_pSharedParams; // rax
  float fStartFreq; // xmm7_4
  float fStopFreq; // xmm6_4
  float v9; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float m_fOscMaxFreq; // xmm1_4
  float v15; // xmm0_4
  bool v16; // r11
  float v17; // xmm6_4
  __m128 v18; // xmm0
  float v19; // xmm6_4
  unsigned int v20; // r10d
  signed int m_uIterOutSampCount; // eax
  __m128 v22; // xmm0
  float v23; // xmm2_4
  float *m_pOscWaveTable; // rcx
  unsigned int m_uPhaseIndex; // r8d
  __int64 v26; // rax
  float v27; // xmm2_4
  float v28; // xmm3_4
  unsigned int v29; // ecx
  float v30; // xmm2_4
  __int64 m_uCurEnvSegment; // rcx
  float v32; // xmm0_4
  float v33; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm3_4
  unsigned int v38; // eax
  bool v39; // zf

  m_pSharedParams = this->m_pSharedParams;
  fStartFreq = m_pSharedParams->m_Params.fStartFreq;
  fStopFreq = m_pSharedParams->m_Params.fStopFreq;
  v9 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v9;
  v11 = v9 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / m_fStepIncrement);
  if ( v11 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v12 = fStartFreq + this->m_fStartFreqModifier;
  v13 = fStopFreq + this->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    m_fOscMaxFreq = this->m_fOscMaxFreq;
    if ( v12 >= m_fOscMaxFreq )
      v12 = m_fOscMaxFreq - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = this->m_fOscMaxFreq;
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
  v18.m128_f32[0] = (float)(int)this->m_uIterNumSamples;
  if ( v16 )
    v19 = v17 / _mm_sqrt_ps(v18).m128_f32[0];
  else
    v19 = v17 / (float)(v18.m128_f32[0] * v18.m128_f32[0]);
  this->m_fFreqSweepScaleFactor = v19;
  v20 = in_uSampToProduce;
  while ( v20 )
  {
    m_uIterOutSampCount = this->m_uIterOutSampCount;
    --v20;
    if ( v16 )
    {
      v22 = 0i64;
      v22.m128_f32[0] = (float)m_uIterOutSampCount;
      LODWORD(v23) = _mm_sqrt_ps(v22).m128_u32[0];
    }
    else
    {
      v23 = (float)m_uIterOutSampCount * (float)m_uIterOutSampCount;
    }
    m_pOscWaveTable = this->m_pOscWaveTable;
    m_uPhaseIndex = this->m_uPhaseIndex;
    v26 = ((this->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF;
    v27 = (float)((float)((float)(v23 * this->m_fFreqSweepScaleFactor) + v12) * 512.0) / (float)(int)this->m_uSampleRate;
    this->m_fSampleInc = v27;
    v28 = (float)((float)(m_pOscWaveTable[v26] - m_pOscWaveTable[m_uPhaseIndex & 0x1FF]) * this->m_fPhaseIndexFrac)
        + m_pOscWaveTable[m_uPhaseIndex & 0x1FF];
    v29 = m_uPhaseIndex + (int)v27;
    this->m_uPhaseIndex = v29;
    v30 = (float)(v27 - (float)(int)v27) + this->m_fPhaseIndexFrac;
    this->m_fPhaseIndexFrac = v30;
    if ( v30 > 1.0 )
    {
      this->m_fPhaseIndexFrac = v30 - 1.0;
      this->m_uPhaseIndex = v29 + 1;
    }
    this->m_uPhaseIndex &= 0x1FFu;
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v32 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v33 = v32 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v33;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v35 = v28 * v33;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v36 = this->m_GainRamp.m_fCurrent + this->m_GainRamp.m_fInc;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v36;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v37 = v35 * this->m_GainRamp.m_fCurrent;
    v38 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v37;
    if ( v38 >= this->m_uIterNumSamples )
    {
      v39 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v39 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 437
// RVA: 0xAD33F0
void __fastcall CAkToneGen::ProcessOversampledWaveTableNoSweep(
        CAkToneGen *this,
        float *out_pBuffer,
        unsigned int in_uSampToProduce)
{
  CAkToneGenParams *m_pSharedParams; // rax
  float fStartFreq; // xmm7_4
  float v8; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float m_fOscMaxFreq; // xmm0_4
  unsigned int v13; // r11d
  float v14; // xmm7_4
  int v15; // r10d
  float v16; // xmm7_4
  __int64 v17; // r9
  float *m_pOscWaveTable; // rcx
  float m_fPhaseIndexFrac; // xmm1_4
  __int64 v20; // rdx
  unsigned int v21; // eax
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float m_fIn1; // xmm3_4
  float m_fOut1; // xmm4_4
  float v27; // xmm5_4
  float m_fB2; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  float m_fIn2; // xmm1_4
  float m_fOut2; // xmm2_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  float v45; // xmm0_4
  float v46; // xmm5_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm5_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm5_4
  __int64 m_uCurEnvSegment; // rcx
  float v54; // xmm0_4
  float v55; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v57; // xmm5_4
  float v58; // xmm0_4
  float v59; // xmm5_4
  unsigned int v60; // eax
  bool v61; // zf

  m_pSharedParams = this->m_pSharedParams;
  fStartFreq = m_pSharedParams->m_Params.fStartFreq;
  v8 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v8;
  v10 = v8 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v10) & _xmm) / m_fStepIncrement);
  if ( v10 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v11 = fStartFreq + this->m_fStartFreqModifier;
  if ( v11 >= 0.001 )
  {
    m_fOscMaxFreq = this->m_fOscMaxFreq;
    if ( v11 >= m_fOscMaxFreq )
      v11 = m_fOscMaxFreq - 1.0;
  }
  else
  {
    v11 = FLOAT_0_001;
  }
  v13 = in_uSampToProduce;
  v14 = (float)(v11 * 512.0) / this->m_fOverSamplingFrequency;
  v15 = (int)v14;
  this->m_fSampleInc = v14;
  v16 = v14 - (float)(int)v14;
  while ( v13 )
  {
    --v13;
    v17 = 4i64;
    do
    {
      m_pOscWaveTable = this->m_pOscWaveTable;
      m_fPhaseIndexFrac = this->m_fPhaseIndexFrac;
      v20 = this->m_uPhaseIndex & 0x1FF;
      v21 = this->m_uPhaseIndex + v15;
      v22 = (float)(m_pOscWaveTable[((this->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - m_pOscWaveTable[v20])
          * m_fPhaseIndexFrac;
      v23 = m_fPhaseIndexFrac + v16;
      v24 = v22 + m_pOscWaveTable[v20];
      this->m_fPhaseIndexFrac = v23;
      this->m_uPhaseIndex = v21;
      if ( v23 > 1.0 )
      {
        this->m_fPhaseIndexFrac = v23 - 1.0;
        this->m_uPhaseIndex = v21 + 1;
      }
      this->m_uPhaseIndex &= 0x1FFu;
      m_fIn1 = this->m_LpFilters[0].m_fIn1;
      m_fOut1 = this->m_LpFilters[0].m_fOut1;
      v27 = v24 * this->m_LpFilters[0].m_fB0;
      m_fB2 = this->m_LpFilters[0].m_fB2;
      this->m_LpFilters[0].m_fIn1 = v24;
      v29 = m_fOut1 * this->m_LpFilters[0].m_fA1;
      v30 = v27 + (float)(m_fIn1 * this->m_LpFilters[0].m_fB1);
      v31 = this->m_LpFilters[0].m_fA2 * this->m_LpFilters[0].m_fOut2;
      v32 = m_fB2 * this->m_LpFilters[0].m_fIn2;
      this->m_LpFilters[0].m_fIn2 = m_fIn1;
      this->m_LpFilters[0].m_fOut2 = m_fOut1;
      v33 = (float)(v30 + v32) - (float)(v29 + v31);
      this->m_LpFilters[0].m_fOut1 = v33;
      v34 = this->m_LpFilters[1].m_fIn1;
      v35 = this->m_LpFilters[1].m_fOut1;
      v36 = v33 * this->m_LpFilters[1].m_fB0;
      v37 = v34 * this->m_LpFilters[1].m_fB1;
      m_fIn2 = this->m_LpFilters[1].m_fIn2;
      m_fOut2 = this->m_LpFilters[1].m_fOut2;
      this->m_LpFilters[1].m_fIn1 = v33;
      v40 = m_fOut2 * this->m_LpFilters[1].m_fA2;
      v41 = m_fIn2 * this->m_LpFilters[1].m_fB2;
      this->m_LpFilters[1].m_fIn2 = v34;
      this->m_LpFilters[1].m_fOut2 = v35;
      v42 = (float)((float)(v36 + v37) + v41) - (float)(v40 + (float)(v35 * this->m_LpFilters[1].m_fA1));
      this->m_LpFilters[1].m_fOut1 = v42;
      v43 = this->m_LpFilters[2].m_fIn1;
      v44 = this->m_LpFilters[2].m_fOut1;
      v45 = v42 * this->m_LpFilters[2].m_fB0;
      v46 = v43 * this->m_LpFilters[2].m_fB1;
      v47 = v44 * this->m_LpFilters[2].m_fA1;
      v48 = this->m_LpFilters[2].m_fB2;
      this->m_LpFilters[2].m_fIn1 = v42;
      v49 = v46 + v45;
      v50 = v48 * this->m_LpFilters[2].m_fIn2;
      v51 = this->m_LpFilters[2].m_fA2 * this->m_LpFilters[2].m_fOut2;
      this->m_LpFilters[2].m_fIn2 = v43;
      this->m_LpFilters[2].m_fOut2 = v44;
      v52 = (float)(v49 + v50) - (float)(v47 + v51);
      this->m_LpFilters[2].m_fOut1 = v52;
      --v17;
    }
    while ( v17 );
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v54 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v55 = v54 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v55;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v57 = v52 * v55;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v58 = this->m_GainRamp.m_fCurrent + this->m_GainRamp.m_fInc;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v58;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v59 = v57 * this->m_GainRamp.m_fCurrent;
    v60 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v59;
    if ( v60 >= this->m_uIterNumSamples )
    {
      v61 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v61 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 541
// RVA: 0xAD2AD0
void __fastcall CAkToneGen::ProcessOversampledWaveTableLinSweep(
        CAkToneGen *this,
        float *out_pBuffer,
        unsigned int in_uSampToProduce)
{
  CAkToneGenParams *m_pSharedParams; // rax
  float fStartFreq; // xmm9_4
  float fStopFreq; // xmm6_4
  float v9; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  float m_fOscMaxFreq; // xmm1_4
  float v15; // xmm0_4
  unsigned int v16; // r11d
  __int64 v17; // r10
  float v18; // xmm7_4
  int v19; // r9d
  float v20; // xmm7_4
  float *m_pOscWaveTable; // rcx
  float m_fPhaseIndexFrac; // xmm1_4
  __int64 v23; // rdx
  unsigned int v24; // eax
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  float m_fIn1; // xmm3_4
  float m_fOut1; // xmm4_4
  float v30; // xmm0_4
  float m_fB2; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm5_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm5_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm6_4
  float m_fIn2; // xmm1_4
  float m_fOut2; // xmm2_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm6_4
  float v46; // xmm3_4
  float v47; // xmm4_4
  float v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm5_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm5_4
  __int64 m_uCurEnvSegment; // rcx
  float v57; // xmm0_4
  float v58; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v60; // xmm5_4
  float v61; // xmm0_4
  float v62; // xmm5_4
  unsigned int v63; // eax
  bool v64; // zf

  m_pSharedParams = this->m_pSharedParams;
  fStartFreq = m_pSharedParams->m_Params.fStartFreq;
  fStopFreq = m_pSharedParams->m_Params.fStopFreq;
  v9 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v9;
  v11 = v9 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / m_fStepIncrement);
  if ( v11 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v12 = fStartFreq + this->m_fStartFreqModifier;
  v13 = fStopFreq + this->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    m_fOscMaxFreq = this->m_fOscMaxFreq;
    if ( v12 >= m_fOscMaxFreq )
      v12 = m_fOscMaxFreq - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = this->m_fOscMaxFreq;
    if ( v13 >= v15 )
      v13 = v15 - 1.0;
  }
  else
  {
    v13 = FLOAT_0_001;
  }
  v16 = in_uSampToProduce;
  this->m_fFreqSweepScaleFactor = (float)(v13 - v12) / (float)(4 * this->m_uIterNumSamples);
  while ( v16 )
  {
    --v16;
    v17 = 4i64;
    v18 = (float)((float)((float)((float)(4 * this->m_uIterOutSampCount) * this->m_fFreqSweepScaleFactor) + v12) * 512.0)
        / this->m_fOverSamplingFrequency;
    v19 = (int)v18;
    this->m_fSampleInc = v18;
    v20 = v18 - (float)(int)v18;
    do
    {
      m_pOscWaveTable = this->m_pOscWaveTable;
      m_fPhaseIndexFrac = this->m_fPhaseIndexFrac;
      v23 = this->m_uPhaseIndex & 0x1FF;
      v24 = this->m_uPhaseIndex + v19;
      v25 = (float)(m_pOscWaveTable[((this->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - m_pOscWaveTable[v23])
          * m_fPhaseIndexFrac;
      v26 = m_fPhaseIndexFrac + v20;
      v27 = v25 + m_pOscWaveTable[v23];
      this->m_fPhaseIndexFrac = v26;
      this->m_uPhaseIndex = v24;
      if ( v26 > 1.0 )
      {
        this->m_fPhaseIndexFrac = v26 - 1.0;
        this->m_uPhaseIndex = v24 + 1;
      }
      this->m_uPhaseIndex &= 0x1FFu;
      m_fIn1 = this->m_LpFilters[0].m_fIn1;
      m_fOut1 = this->m_LpFilters[0].m_fOut1;
      v30 = v27 * this->m_LpFilters[0].m_fB0;
      m_fB2 = this->m_LpFilters[0].m_fB2;
      this->m_LpFilters[0].m_fIn1 = v27;
      v32 = m_fOut1 * this->m_LpFilters[0].m_fA1;
      v33 = (float)(m_fIn1 * this->m_LpFilters[0].m_fB1) + v30;
      v34 = this->m_LpFilters[0].m_fA2 * this->m_LpFilters[0].m_fOut2;
      v35 = m_fB2 * this->m_LpFilters[0].m_fIn2;
      this->m_LpFilters[0].m_fIn2 = m_fIn1;
      this->m_LpFilters[0].m_fOut2 = m_fOut1;
      v36 = (float)(v33 + v35) - (float)(v32 + v34);
      this->m_LpFilters[0].m_fOut1 = v36;
      v37 = this->m_LpFilters[1].m_fIn1;
      v38 = this->m_LpFilters[1].m_fOut1;
      v39 = v36 * this->m_LpFilters[1].m_fB0;
      v40 = v37 * this->m_LpFilters[1].m_fB1;
      m_fIn2 = this->m_LpFilters[1].m_fIn2;
      m_fOut2 = this->m_LpFilters[1].m_fOut2;
      this->m_LpFilters[1].m_fIn1 = v36;
      v43 = m_fOut2 * this->m_LpFilters[1].m_fA2;
      v44 = m_fIn2 * this->m_LpFilters[1].m_fB2;
      this->m_LpFilters[1].m_fIn2 = v37;
      this->m_LpFilters[1].m_fOut2 = v38;
      v45 = (float)((float)(v40 + v39) + v44) - (float)(v43 + (float)(v38 * this->m_LpFilters[1].m_fA1));
      this->m_LpFilters[1].m_fOut1 = v45;
      v46 = this->m_LpFilters[2].m_fIn1;
      v47 = this->m_LpFilters[2].m_fOut1;
      v48 = v45 * this->m_LpFilters[2].m_fB0;
      v49 = v46 * this->m_LpFilters[2].m_fB1;
      v50 = v47 * this->m_LpFilters[2].m_fA1;
      v51 = this->m_LpFilters[2].m_fB2;
      this->m_LpFilters[2].m_fIn1 = v45;
      v52 = v49 + v48;
      v53 = v51 * this->m_LpFilters[2].m_fIn2;
      v54 = this->m_LpFilters[2].m_fA2 * this->m_LpFilters[2].m_fOut2;
      this->m_LpFilters[2].m_fIn2 = v46;
      this->m_LpFilters[2].m_fOut2 = v47;
      v55 = (float)(v52 + v53) - (float)(v50 + v54);
      this->m_LpFilters[2].m_fOut1 = v55;
      --v17;
    }
    while ( v17 );
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v57 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v58 = v57 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v58;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v60 = v55 * v58;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v61 = this->m_GainRamp.m_fCurrent + this->m_GainRamp.m_fInc;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v61;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v62 = v60 * this->m_GainRamp.m_fCurrent;
    v63 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v62;
    if ( v63 >= this->m_uIterNumSamples )
    {
      v64 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v64 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 661
// RVA: 0xAD2F40
void __fastcall CAkToneGen::ProcessOversampledWaveTableLogSweep(
        CAkToneGen *this,
        float *out_pBuffer,
        unsigned int in_uSampToProduce)
{
  CAkToneGenParams *m_pSharedParams; // rax
  float fStartFreq; // xmm9_4
  float fStopFreq; // xmm6_4
  float v9; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  float m_fOscMaxFreq; // xmm1_4
  float v15; // xmm0_4
  bool v16; // bp
  float v17; // xmm6_4
  __m128 v18; // xmm0
  float v19; // xmm6_4
  unsigned int v20; // r11d
  __m128 v21; // xmm7
  float v22; // xmm7_4
  __int64 v23; // r10
  float v24; // xmm7_4
  int v25; // r9d
  float v26; // xmm7_4
  float *m_pOscWaveTable; // rcx
  float m_fPhaseIndexFrac; // xmm1_4
  __int64 v29; // rdx
  unsigned int v30; // eax
  float v31; // xmm6_4
  float v32; // xmm1_4
  float v33; // xmm6_4
  float m_fIn1; // xmm3_4
  float m_fOut1; // xmm4_4
  float v36; // xmm0_4
  float m_fB2; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm5_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  float v45; // xmm0_4
  float v46; // xmm6_4
  float m_fIn2; // xmm1_4
  float m_fOut2; // xmm2_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm6_4
  float v52; // xmm3_4
  float v53; // xmm4_4
  float v54; // xmm5_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm5_4
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm5_4
  __int64 m_uCurEnvSegment; // rcx
  float v63; // xmm0_4
  float v64; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v66; // xmm5_4
  float v67; // xmm0_4
  float v68; // xmm5_4
  unsigned int v69; // eax
  bool v70; // zf

  m_pSharedParams = this->m_pSharedParams;
  fStartFreq = m_pSharedParams->m_Params.fStartFreq;
  fStopFreq = m_pSharedParams->m_Params.fStopFreq;
  v9 = powf(10.0, m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v9;
  v11 = v9 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v11) & _xmm) / m_fStepIncrement);
  if ( v11 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v12 = fStartFreq + this->m_fStartFreqModifier;
  v13 = fStopFreq + this->m_fStopFreqModifier;
  if ( v12 >= 0.001 )
  {
    m_fOscMaxFreq = this->m_fOscMaxFreq;
    if ( v12 >= m_fOscMaxFreq )
      v12 = m_fOscMaxFreq - 1.0;
  }
  else
  {
    v12 = FLOAT_0_001;
  }
  if ( v13 >= 0.001 )
  {
    v15 = this->m_fOscMaxFreq;
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
  v18.m128_f32[0] = (float)(int)this->m_uIterNumSamples * 4.0;
  if ( v16 )
    v19 = v17 / _mm_sqrt_ps(v18).m128_f32[0];
  else
    v19 = v17 / (float)(v18.m128_f32[0] * v18.m128_f32[0]);
  this->m_fFreqSweepScaleFactor = v19;
  v20 = in_uSampToProduce;
  while ( v20 )
  {
    v21 = 0i64;
    --v20;
    v21.m128_f32[0] = (float)(4 * this->m_uIterOutSampCount);
    if ( v16 )
      LODWORD(v22) = _mm_sqrt_ps(v21).m128_u32[0];
    else
      v22 = v21.m128_f32[0] * v21.m128_f32[0];
    v23 = 4i64;
    v24 = (float)((float)((float)(v22 * this->m_fFreqSweepScaleFactor) + v12) * 512.0) / this->m_fOverSamplingFrequency;
    v25 = (int)v24;
    this->m_fSampleInc = v24;
    v26 = v24 - (float)(int)v24;
    do
    {
      m_pOscWaveTable = this->m_pOscWaveTable;
      m_fPhaseIndexFrac = this->m_fPhaseIndexFrac;
      v29 = this->m_uPhaseIndex & 0x1FF;
      v30 = this->m_uPhaseIndex + v25;
      v31 = (float)(m_pOscWaveTable[((this->m_uPhaseIndex & 0x1FF) + 1) & 0x1FF] - m_pOscWaveTable[v29])
          * m_fPhaseIndexFrac;
      v32 = m_fPhaseIndexFrac + v26;
      v33 = v31 + m_pOscWaveTable[v29];
      this->m_fPhaseIndexFrac = v32;
      this->m_uPhaseIndex = v30;
      if ( v32 > 1.0 )
      {
        this->m_fPhaseIndexFrac = v32 - 1.0;
        this->m_uPhaseIndex = v30 + 1;
      }
      this->m_uPhaseIndex &= 0x1FFu;
      m_fIn1 = this->m_LpFilters[0].m_fIn1;
      m_fOut1 = this->m_LpFilters[0].m_fOut1;
      v36 = v33 * this->m_LpFilters[0].m_fB0;
      m_fB2 = this->m_LpFilters[0].m_fB2;
      this->m_LpFilters[0].m_fIn1 = v33;
      v38 = m_fOut1 * this->m_LpFilters[0].m_fA1;
      v39 = (float)(m_fIn1 * this->m_LpFilters[0].m_fB1) + v36;
      v40 = this->m_LpFilters[0].m_fA2 * this->m_LpFilters[0].m_fOut2;
      v41 = m_fB2 * this->m_LpFilters[0].m_fIn2;
      this->m_LpFilters[0].m_fIn2 = m_fIn1;
      this->m_LpFilters[0].m_fOut2 = m_fOut1;
      v42 = (float)(v39 + v41) - (float)(v38 + v40);
      this->m_LpFilters[0].m_fOut1 = v42;
      v43 = this->m_LpFilters[1].m_fIn1;
      v44 = this->m_LpFilters[1].m_fOut1;
      v45 = v42 * this->m_LpFilters[1].m_fB0;
      v46 = v43 * this->m_LpFilters[1].m_fB1;
      m_fIn2 = this->m_LpFilters[1].m_fIn2;
      m_fOut2 = this->m_LpFilters[1].m_fOut2;
      this->m_LpFilters[1].m_fIn1 = v42;
      v49 = m_fOut2 * this->m_LpFilters[1].m_fA2;
      v50 = m_fIn2 * this->m_LpFilters[1].m_fB2;
      this->m_LpFilters[1].m_fIn2 = v43;
      this->m_LpFilters[1].m_fOut2 = v44;
      v51 = (float)((float)(v46 + v45) + v50) - (float)(v49 + (float)(v44 * this->m_LpFilters[1].m_fA1));
      this->m_LpFilters[1].m_fOut1 = v51;
      v52 = this->m_LpFilters[2].m_fIn1;
      v53 = this->m_LpFilters[2].m_fOut1;
      v54 = v51 * this->m_LpFilters[2].m_fB0;
      v55 = v52 * this->m_LpFilters[2].m_fB1;
      v56 = v53 * this->m_LpFilters[2].m_fA1;
      v57 = this->m_LpFilters[2].m_fB2;
      this->m_LpFilters[2].m_fIn1 = v51;
      v58 = v54 + v55;
      v59 = v57 * this->m_LpFilters[2].m_fIn2;
      v60 = this->m_LpFilters[2].m_fA2 * this->m_LpFilters[2].m_fOut2;
      this->m_LpFilters[2].m_fIn2 = v52;
      this->m_LpFilters[2].m_fOut2 = v53;
      v61 = (float)(v58 + v59) - (float)(v56 + v60);
      this->m_LpFilters[2].m_fOut1 = v61;
      --v23;
    }
    while ( v23 );
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v63 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v64 = v63 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v64;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v66 = v61 * v64;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v67 = this->m_GainRamp.m_fCurrent + this->m_GainRamp.m_fInc;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v67;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v68 = v66 * this->m_GainRamp.m_fCurrent;
    v69 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v68;
    if ( v69 >= this->m_uIterNumSamples )
    {
      v70 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v70 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 804
// RVA: 0xAD41D0
void __fastcall CAkToneGen::ProcessWhiteNoise(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  float v6; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v8; // xmm2_4
  unsigned int v9; // edx
  __int64 m_uCurEnvSegment; // rcx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  unsigned int v18; // eax
  bool v19; // zf

  v6 = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v6;
  v8 = v6 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v8) & _xmm) / m_fStepIncrement);
  if ( v8 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v9 = in_uSampToProduce;
  while ( v9 )
  {
    --v9;
    CAkToneGen::s_uSeedVal = 196314165 * CAkToneGen::s_uSeedVal + 907633515;
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    v11 = (float)(int)CAkToneGen::s_uSeedVal * 4.6566129e-10;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v12 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v13 = v12 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v13;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v15 = v11 * v13;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v16 = this->m_GainRamp.m_fCurrent + this->m_GainRamp.m_fInc;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v16;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v17 = v15 * this->m_GainRamp.m_fCurrent;
    v18 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v17;
    if ( v18 >= this->m_uIterNumSamples )
    {
      v19 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v19 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

// File Line: 848
// RVA: 0xAD37E0
void __fastcall CAkToneGen::ProcessPinkNoise(CAkToneGen *this, float *out_pBuffer, unsigned int in_uSampToProduce)
{
  float v6; // xmm0_4
  float m_fStepIncrement; // xmm3_4
  float v8; // xmm2_4
  unsigned int v9; // edx
  bool v10; // zf
  unsigned int v11; // eax
  __int64 i; // rcx
  float *m_pPinkNoiseRandGen; // rax
  float v14; // xmm1_4
  __int64 m_uCurEnvSegment; // rcx
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  unsigned int m_uRampCount; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  unsigned int v23; // eax

  v6 = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  m_fStepIncrement = this->m_GainRamp.m_fStepIncrement;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fTarget = v6;
  v8 = v6 - this->m_GainRamp.m_fCurrent;
  this->m_GainRamp.m_uRampLength = (int)(float)(COERCE_FLOAT(LODWORD(v8) & _xmm) / m_fStepIncrement);
  if ( v8 <= 0.0 )
    LODWORD(m_fStepIncrement) ^= _xmm[0];
  this->m_GainRamp.m_fInc = m_fStepIncrement;
  v9 = in_uSampToProduce;
  while ( v9 )
  {
    --v9;
    v10 = (this->m_uPinkNoiseIndMask & (this->m_uPinkNoiseInd + 1)) == 0;
    v11 = this->m_uPinkNoiseIndMask & (this->m_uPinkNoiseInd + 1);
    this->m_uPinkNoiseInd = v11;
    if ( !v10 )
    {
      for ( i = 0i64; (v11 & 1) == 0; i = (unsigned int)(i + 1) )
        v11 >>= 1;
      this->m_fPinkNoiseRunSum = this->m_fPinkNoiseRunSum - this->m_pPinkNoiseRandGen[i];
      CAkToneGen::s_uSeedVal = 196314165 * CAkToneGen::s_uSeedVal + 907633515;
      m_pPinkNoiseRandGen = this->m_pPinkNoiseRandGen;
      v14 = (float)(int)CAkToneGen::s_uSeedVal * 4.6566129e-10;
      this->m_fPinkNoiseRunSum = v14 + this->m_fPinkNoiseRunSum;
      m_pPinkNoiseRandGen[i] = v14;
    }
    CAkToneGen::s_uSeedVal = 196314165 * CAkToneGen::s_uSeedVal + 907633515;
    m_uCurEnvSegment = this->m_uCurEnvSegment;
    v16 = (float)((float)((float)(int)CAkToneGen::s_uSeedVal * 4.6566129e-10) + this->m_fPinkNoiseRunSum)
        * this->m_fNoiseScale;
    if ( this->m_uEnvSegmentCount >= this->m_uEnvSegmentDur[m_uCurEnvSegment] )
    {
      this->m_uEnvSegmentCount = 0;
      this->m_uCurEnvSegment = m_uCurEnvSegment + 1;
    }
    v17 = this->m_fEnvInc[this->m_uCurEnvSegment];
    ++this->m_uEnvSegmentCount;
    v18 = v17 + this->m_fEnvCurGain;
    this->m_fEnvCurGain = v18;
    m_uRampCount = this->m_GainRamp.m_uRampCount;
    v20 = v16 * v18;
    if ( m_uRampCount < this->m_GainRamp.m_uRampLength )
    {
      v21 = this->m_GainRamp.m_fInc + this->m_GainRamp.m_fCurrent;
      this->m_GainRamp.m_uRampCount = m_uRampCount + 1;
      this->m_GainRamp.m_fCurrent = v21;
    }
    else
    {
      this->m_GainRamp.m_fCurrent = this->m_GainRamp.m_fTarget;
    }
    v22 = v20 * this->m_GainRamp.m_fCurrent;
    if ( v22 > -1.0 )
    {
      if ( v22 >= 1.0 )
        v22 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v22 = FLOAT_N1_0;
    }
    v23 = ++this->m_uIterOutSampCount;
    *out_pBuffer++ = v22;
    if ( v23 >= this->m_uIterNumSamples )
    {
      v10 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
      this->m_uIterOutSampCount = 0;
      this->m_uCurEnvSegment = 0;
      this->m_uEnvSegmentCount = 0;
      if ( v10 || this->m_iNumLoops == 1 )
        this->m_fEnvCurGain = 0.0;
      else
        this->m_fEnvCurGain = 1.0;
    }
  }
  this->m_uTotalOutSampCount += in_uSampToProduce;
}

