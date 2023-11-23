// File Line: 69
// RVA: 0xAFB430
void __fastcall DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::Setup(
        DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this,
        int in_uSampleRate,
        DSP::LFO::Params *in_lfoParams,
        float in_fInitPhase)
{
  float fPhaseDelta; // xmm5_4
  DSP::LFO::Waveform eWaveform; // xmm7_4
  float fB0; // xmm9_4
  float fA1; // xmm10_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  __int64 v13; // [rsp+30h] [rbp-68h]

  DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(this, in_uSampleRate, in_lfoParams);
  fPhaseDelta = this->m_state.fPhaseDelta;
  eWaveform = this->m_state.eWaveform;
  fB0 = this->m_state.filter.fB0;
  fA1 = this->m_state.filter.fA1;
  v13 = *(_QWORD *)&this->m_state.fPhaseDelta;
  if ( in_lfoParams->eWaveform )
    v10 = *(float *)&FLOAT_1_0;
  else
    v10 = FLOAT_6_2831855;
  v11 = (float)(v10 * in_fInitPhase) * 0.0027777778;
  if ( HIDWORD(v13) == 1 )
  {
    v11 = v11 + 0.25;
  }
  else if ( HIDWORD(v13) == 3 )
  {
    v11 = v11 + 0.5;
  }
  if ( v11 < 0.0 )
    v11 = v11 + v10;
  if ( v11 >= v10 )
    v11 = v11 - v10;
  this->m_state.filter.fFFbk1 = this->m_state.filter.fFFbk1;
  this->m_state.filter.fB0 = fB0;
  this->m_state.filter.fA1 = fA1;
  this->m_state.fPhase = v11;
  this->m_state.fPhaseDelta = fPhaseDelta;
  this->m_state.eWaveform = eWaveform;
  if ( HIDWORD(v13) )
    v12 = *(float *)&FLOAT_1_0;
  else
    v12 = FLOAT_6_2831855;
  this->m_state.fPhase = fmodf(v11, v12);
}

// File Line: 97
// RVA: 0xAFB350
void __fastcall DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(
        DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this,
        int in_uSampleRate,
        DSP::LFO::Params *in_lfoParams)
{
  float fSmooth; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float in_fA1; // [rsp+70h] [rbp+18h] BYREF
  float out_fB0; // [rsp+78h] [rbp+20h] BYREF

  fSmooth = in_lfoParams->fSmooth;
  if ( fSmooth == 0.0 )
  {
    DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_NONE, 0.0, 0, &out_fB0, &in_fA1);
  }
  else
  {
    v7 = (float)in_uSampleRate * 0.5;
    v8 = logf(v7 / in_lfoParams->fFrequency);
    v9 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * fSmooth) ^ _xmm[0]));
    DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_LOWPASS, v9 * v7, in_uSampleRate, &out_fB0, &in_fA1);
  }
  DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::SetParams(this, in_uSampleRate, in_lfoParams, out_fB0, in_fA1);
}

// File Line: 110
// RVA: 0xAF4E30
void __fastcall DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::SetParams(
        DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this,
        int in_uSampleRate,
        DSP::LFO::Params *in_lfoParams,
        float in_fB0,
        float in_fA1)
{
  float v5; // xmm1_4
  DSP::LFO::Waveform eWaveform; // edx
  DSP::LFO::Waveform v7; // eax

  v5 = in_lfoParams->fFrequency / (float)in_uSampleRate;
  this->m_state.fPhaseDelta = v5;
  if ( in_lfoParams->eWaveform == WAVEFORM_SINE )
    this->m_state.fPhaseDelta = v5 * 6.2831855;
  this->m_state.filter.fB0 = in_fB0;
  this->m_state.filter.fA1 = in_fA1;
  eWaveform = this->m_state.eWaveform;
  v7 = in_lfoParams->eWaveform;
  if ( eWaveform != in_lfoParams->eWaveform )
  {
    if ( eWaveform == WAVEFORM_SINE )
    {
      this->m_state.fPhase = this->m_state.fPhase * 0.15915494;
      this->m_state.eWaveform = in_lfoParams->eWaveform;
      return;
    }
    if ( v7 == WAVEFORM_SINE )
    {
      this->m_state.fPhase = this->m_state.fPhase * 6.2831855;
      v7 = in_lfoParams->eWaveform;
    }
  }
  this->m_state.eWaveform = v7;
}

// File Line: 193
// RVA: 0xAFA940
void __fastcall DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::ProduceBuffer(
        DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this,
        float *io_pfBuffer,
        int in_uNumFrames,
        float in_fAmp,
        float in_fPrevAmp,
        float in_fPWM,
        FlangerOutputPolicy *in_rParams)
{
  DSP::LFO::Waveform eWaveform; // xmm1_4
  float fFFbk1; // xmm5_4
  float fPhase; // xmm4_4
  float *v11; // r9
  float fPhaseDelta; // xmm8_4
  float fB0; // xmm10_4
  float v14; // xmm6_4
  float fA1; // xmm11_4
  float v16; // xmm9_4
  bool v17; // r11
  float v18; // xmm0_4
  __m128 v19; // xmm1
  int v20; // ecx
  int v21; // eax
  float *v22; // rcx
  unsigned __int64 v23; // rax
  __m128 v24; // xmm1
  int v25; // ecx
  int v26; // eax
  float *v27; // rcx
  unsigned __int64 v28; // rax
  float v29; // xmm3_4
  __m128 v30; // xmm1
  int v31; // ecx
  int v32; // eax
  float *v33; // rcx
  unsigned __int64 v34; // rax
  __m128 v35; // xmm1
  int v36; // ecx
  int v37; // eax
  float *v38; // rcx
  unsigned __int64 v39; // rax
  float v40; // xmm3_4
  __m128 v41; // xmm1
  int v42; // ecx
  int v43; // eax
  float *v44; // rcx
  unsigned __int64 v45; // rax
  __m128 v46; // xmm1
  int v47; // ecx
  int v48; // eax
  float *v49; // rcx
  unsigned __int64 v50; // rax
  __m128 v51; // xmm2
  float v52; // xmm3_4
  __m128 v53; // xmm1
  int v54; // ecx
  int v55; // eax
  float *v56; // rcx
  unsigned __int64 v57; // rax
  __m128 v58; // xmm1
  int v59; // ecx
  int v60; // eax
  float *v61; // rcx
  unsigned __int64 v62; // rax
  __m128 v63; // xmm1
  int v64; // ecx
  int v65; // eax
  float *v66; // rcx
  unsigned __int64 v67; // rax
  float v68; // xmm0_4
  __m128 v69; // xmm1
  int v70; // ecx
  int v71; // eax
  float *v72; // rcx
  unsigned __int64 v73; // rax
  float v74; // xmm3_4
  float v75; // xmm1_4
  DSP::LFO::Waveform v76; // [rsp+34h] [rbp-B4h]
  DSP::LFO::Waveform v77; // [rsp+100h] [rbp+18h]

  eWaveform = this->m_state.eWaveform;
  fFFbk1 = this->m_state.filter.fFFbk1;
  fPhase = this->m_state.fPhase;
  v11 = &io_pfBuffer[in_uNumFrames];
  fPhaseDelta = this->m_state.fPhaseDelta;
  fB0 = this->m_state.filter.fB0;
  v14 = in_fPrevAmp;
  fA1 = this->m_state.filter.fA1;
  v77 = eWaveform;
  v76 = eWaveform;
  v16 = (float)(in_fAmp - in_fPrevAmp) / (float)in_uNumFrames;
  v17 = fPhaseDelta == 0.0;
  if ( fPhaseDelta <= 0.0000000099999999 )
    fPhaseDelta = FLOAT_9_9999999eN9;
  v18 = FLOAT_6_2831855;
  switch ( eWaveform )
  {
    case WAVEFORM_SINE:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      v51 = (__m128)LODWORD(FLOAT_3_1415927);
      v52 = 1.0 / fPhaseDelta;
      do
      {
        v53 = (__m128)LODWORD(FLOAT_1_5707964);
        v53.m128_f32[0] = (float)(1.5707964 - fPhase) * v52;
        v54 = (int)v53.m128_f32[0];
        if ( (int)v53.m128_f32[0] != 0x80000000 && (float)v54 != v53.m128_f32[0] )
          v53.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v53, v53)) & 1) + v54);
        v55 = (int)v53.m128_f32[0];
        if ( (int)v53.m128_f32[0] >= 0 )
        {
          if ( v55 > in_uNumFrames )
            v55 = in_uNumFrames;
        }
        else
        {
          v55 = -1;
        }
        v56 = &io_pfBuffer[v55];
        v57 = (unsigned __int64)v11;
        if ( v56 < v11 )
          v57 = (unsigned __int64)v56;
        if ( (unsigned __int64)io_pfBuffer < v57 )
        {
          do
          {
            fPhase = fPhase + fPhaseDelta;
            v14 = v14 + v16;
            *io_pfBuffer++ = (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                           - (float)((float)(fPhase * fPhase)
                                                                                   * 0.00018363654))
                                                                   * (float)(fPhase * fPhase))
                                                           - 0.16664828)
                                                   * (float)(fPhase * fPhase))
                                           + 0.9999966)
                                   * fPhase)
                           * v14;
          }
          while ( (unsigned __int64)io_pfBuffer < v57 );
          v51 = (__m128)LODWORD(FLOAT_3_1415927);
        }
        v58 = v51;
        v58.m128_f32[0] = (float)(v51.m128_f32[0] - fPhase) * v52;
        v59 = (int)v58.m128_f32[0];
        if ( (int)v58.m128_f32[0] != 0x80000000 && (float)v59 != v58.m128_f32[0] )
          v58.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v58, v58)) & 1) + v59);
        v60 = (int)v58.m128_f32[0];
        if ( (int)v58.m128_f32[0] >= 0 )
        {
          if ( v60 > in_uNumFrames )
            v60 = in_uNumFrames;
        }
        else
        {
          v60 = -1;
        }
        v61 = &io_pfBuffer[v60];
        v62 = (unsigned __int64)v11;
        if ( v61 < v11 )
          v62 = (unsigned __int64)v61;
        if ( (unsigned __int64)io_pfBuffer < v62 )
        {
          do
          {
            fPhase = fPhase + fPhaseDelta;
            v14 = v14 + v16;
            *io_pfBuffer++ = (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                           - (float)((float)((float)(v51.m128_f32[0] - fPhase)
                                                                                           * (float)(v51.m128_f32[0] - fPhase))
                                                                                   * 0.00018363654))
                                                                   * (float)((float)(v51.m128_f32[0] - fPhase)
                                                                           * (float)(v51.m128_f32[0] - fPhase)))
                                                           - 0.16664828)
                                                   * (float)((float)(v51.m128_f32[0] - fPhase)
                                                           * (float)(v51.m128_f32[0] - fPhase)))
                                           + 0.9999966)
                                   * (float)(v51.m128_f32[0] - fPhase))
                           * v14;
            v51.m128_f32[0] = FLOAT_3_1415927;
          }
          while ( (unsigned __int64)io_pfBuffer < v62 );
          v52 = 1.0 / fPhaseDelta;
        }
        v63 = (__m128)LODWORD(FLOAT_4_712389);
        v63.m128_f32[0] = (float)(4.712389 - fPhase) * v52;
        v64 = (int)v63.m128_f32[0];
        if ( (int)v63.m128_f32[0] != 0x80000000 && (float)v64 != v63.m128_f32[0] )
          v63.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v63, v63)) & 1) + v64);
        v65 = (int)v63.m128_f32[0];
        if ( (int)v63.m128_f32[0] >= 0 )
        {
          if ( v65 > in_uNumFrames )
            v65 = in_uNumFrames;
        }
        else
        {
          v65 = -1;
        }
        v66 = &io_pfBuffer[v65];
        v67 = (unsigned __int64)v11;
        if ( v66 < v11 )
          v67 = (unsigned __int64)v66;
        if ( (unsigned __int64)io_pfBuffer < v67 )
        {
          do
          {
            fPhase = fPhase + fPhaseDelta;
            v14 = v14 + v16;
            *((_DWORD *)++io_pfBuffer - 1) = COERCE_UNSIGNED_INT(
                                               (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                                             - (float)((float)((float)(fPhase - v51.m128_f32[0]) * (float)(fPhase - v51.m128_f32[0])) * 0.00018363654))
                                                                                     * (float)((float)(fPhase - v51.m128_f32[0])
                                                                                             * (float)(fPhase - v51.m128_f32[0])))
                                                                             - 0.16664828)
                                                                     * (float)((float)(fPhase - v51.m128_f32[0])
                                                                             * (float)(fPhase - v51.m128_f32[0])))
                                                             + 0.9999966)
                                                     * (float)(fPhase - v51.m128_f32[0]))
                                             * v14) ^ _xmm[0];
            v51.m128_f32[0] = FLOAT_3_1415927;
          }
          while ( (unsigned __int64)io_pfBuffer < v67 );
          v52 = 1.0 / fPhaseDelta;
        }
        v68 = FLOAT_6_2831855;
        v69 = (__m128)LODWORD(FLOAT_6_2831855);
        v69.m128_f32[0] = (float)(6.2831855 - fPhase) * v52;
        v70 = (int)v69.m128_f32[0];
        if ( (int)v69.m128_f32[0] != 0x80000000 )
        {
          v68 = FLOAT_6_2831855;
          if ( (float)v70 != v69.m128_f32[0] )
            v69.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v69, v69)) & 1) + v70);
        }
        v71 = (int)v69.m128_f32[0];
        if ( (int)v69.m128_f32[0] >= 0 )
        {
          if ( v71 > in_uNumFrames )
            v71 = in_uNumFrames;
        }
        else
        {
          v71 = -1;
        }
        v72 = &io_pfBuffer[v71];
        v73 = (unsigned __int64)v11;
        if ( v72 < v11 )
          v73 = (unsigned __int64)v72;
        if ( (unsigned __int64)io_pfBuffer < v73 )
        {
          do
          {
            fPhase = fPhase + fPhaseDelta;
            v74 = v68 - fPhase;
            v14 = v14 + v16;
            ++io_pfBuffer;
            v68 = FLOAT_6_2831855;
            *((_DWORD *)io_pfBuffer - 1) = COERCE_UNSIGNED_INT(
                                             (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                                           - (float)((float)(v74 * v74) * 0.00018363654))
                                                                                   * (float)(v74 * v74))
                                                                           - 0.16664828)
                                                                   * (float)(v74 * v74))
                                                           + 0.9999966)
                                                   * v74)
                                           * v14) ^ _xmm[0];
          }
          while ( (unsigned __int64)io_pfBuffer < v73 );
          v52 = 1.0 / fPhaseDelta;
        }
        v18 = FLOAT_6_2831855;
        if ( fPhase >= 6.2831855 )
          fPhase = fPhase + -6.2831855;
        v51 = (__m128)LODWORD(FLOAT_3_1415927);
      }
      while ( io_pfBuffer < v11 );
      goto LABEL_149;
    case WAVEFORM_TRIANGLE:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      v40 = 1.0 / fPhaseDelta;
      do
      {
        v41 = (__m128)LODWORD(FLOAT_0_5);
        v41.m128_f32[0] = (float)(0.5 - fPhase) * v40;
        v42 = (int)v41.m128_f32[0];
        if ( (int)v41.m128_f32[0] != 0x80000000 && (float)v42 != v41.m128_f32[0] )
          v41.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v41, v41)) & 1) + v42);
        v43 = (int)v41.m128_f32[0];
        if ( (int)v41.m128_f32[0] >= 0 )
        {
          if ( v43 > in_uNumFrames )
            v43 = in_uNumFrames;
        }
        else
        {
          v43 = -1;
        }
        v44 = &io_pfBuffer[v43];
        v45 = (unsigned __int64)v11;
        if ( v44 < v11 )
          v45 = (unsigned __int64)v44;
        for ( ; (unsigned __int64)io_pfBuffer < v45; *(io_pfBuffer - 1) = fFFbk1 )
        {
          fPhase = fPhase + fPhaseDelta;
          v14 = v14 + v16;
          ++io_pfBuffer;
          fFFbk1 = (float)((float)((float)((float)(fPhase * 4.0) - 1.0) * v14) * fB0) - (float)(fFFbk1 * fA1);
        }
        v46 = (__m128)(unsigned int)FLOAT_1_0;
        v46.m128_f32[0] = (float)(1.0 - fPhase) * v40;
        v47 = (int)v46.m128_f32[0];
        if ( (int)v46.m128_f32[0] != 0x80000000 && (float)v47 != v46.m128_f32[0] )
          v46.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v46, v46)) & 1) + v47);
        v48 = (int)v46.m128_f32[0];
        if ( (int)v46.m128_f32[0] >= 0 )
        {
          if ( v48 > in_uNumFrames )
            v48 = in_uNumFrames;
        }
        else
        {
          v48 = -1;
        }
        v49 = &io_pfBuffer[v48];
        v50 = (unsigned __int64)v11;
        if ( v49 < v11 )
          v50 = (unsigned __int64)v49;
        for ( ; (unsigned __int64)io_pfBuffer < v50; *(io_pfBuffer - 1) = fFFbk1 )
        {
          fPhase = fPhase + fPhaseDelta;
          v14 = v14 + v16;
          ++io_pfBuffer;
          fFFbk1 = (float)((float)((float)((float)((float)(1.0 - fPhase) * 4.0) - 1.0) * v14) * fB0)
                 - (float)(fFFbk1 * fA1);
        }
        if ( fPhase >= 1.0 )
          fPhase = fPhase - 1.0;
      }
      while ( io_pfBuffer < v11 );
      v18 = FLOAT_6_2831855;
      goto LABEL_149;
    case WAVEFORM_SQUARE:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      v29 = 1.0 / fPhaseDelta;
      do
      {
        v30 = (__m128)LODWORD(in_fPWM);
        v30.m128_f32[0] = (float)(in_fPWM - fPhase) * v29;
        v31 = (int)v30.m128_f32[0];
        if ( (int)v30.m128_f32[0] != 0x80000000 && (float)v31 != v30.m128_f32[0] )
          v30.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1) + v31);
        v32 = (int)v30.m128_f32[0];
        if ( (int)v30.m128_f32[0] >= 0 )
        {
          if ( v32 > in_uNumFrames )
            v32 = in_uNumFrames;
        }
        else
        {
          v32 = -1;
        }
        v33 = &io_pfBuffer[v32];
        v34 = (unsigned __int64)v11;
        if ( v33 < v11 )
          v34 = (unsigned __int64)v33;
        for ( ; (unsigned __int64)io_pfBuffer < v34; *(io_pfBuffer - 1) = fFFbk1 )
        {
          v14 = v14 + v16;
          ++io_pfBuffer;
          fPhase = fPhase + fPhaseDelta;
          fFFbk1 = (float)(fB0 * v14) - (float)(fFFbk1 * fA1);
        }
        v35 = (__m128)(unsigned int)FLOAT_1_0;
        v35.m128_f32[0] = (float)(1.0 - fPhase) * v29;
        v36 = (int)v35.m128_f32[0];
        if ( (int)v35.m128_f32[0] != 0x80000000 && (float)v36 != v35.m128_f32[0] )
          v35.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1) + v36);
        v37 = (int)v35.m128_f32[0];
        if ( (int)v35.m128_f32[0] >= 0 )
        {
          if ( v37 > in_uNumFrames )
            v37 = in_uNumFrames;
        }
        else
        {
          v37 = -1;
        }
        v38 = &io_pfBuffer[v37];
        v39 = (unsigned __int64)v11;
        if ( v38 < v11 )
          v39 = (unsigned __int64)v38;
        for ( ; (unsigned __int64)io_pfBuffer < v39; *(io_pfBuffer - 1) = fFFbk1 )
        {
          v14 = v14 + v16;
          ++io_pfBuffer;
          fPhase = fPhase + fPhaseDelta;
          fFFbk1 = COERCE_FLOAT(COERCE_UNSIGNED_INT(fB0 * v14) ^ _xmm[0]) - (float)(fFFbk1 * fA1);
        }
        if ( fPhase >= 1.0 )
          fPhase = fPhase - 1.0;
      }
      while ( io_pfBuffer < v11 );
      v18 = FLOAT_6_2831855;
      goto LABEL_149;
    case WAVEFORM_SAW_UP:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      do
      {
        v24 = (__m128)(unsigned int)FLOAT_1_0;
        v24.m128_f32[0] = (float)(1.0 - fPhase) * (float)(1.0 / fPhaseDelta);
        v25 = (int)v24.m128_f32[0];
        if ( (int)v24.m128_f32[0] != 0x80000000 && (float)v25 != v24.m128_f32[0] )
          v24.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v24, v24)) & 1) + v25);
        v26 = (int)v24.m128_f32[0];
        if ( (int)v24.m128_f32[0] >= 0 )
        {
          if ( v26 > in_uNumFrames )
            v26 = in_uNumFrames;
        }
        else
        {
          v26 = -1;
        }
        v27 = &io_pfBuffer[v26];
        v28 = (unsigned __int64)v11;
        if ( v27 < v11 )
          v28 = (unsigned __int64)v27;
        for ( ; (unsigned __int64)io_pfBuffer < v28; *(io_pfBuffer - 1) = fFFbk1 )
        {
          fPhase = fPhase + fPhaseDelta;
          v14 = v14 + v16;
          ++io_pfBuffer;
          fFFbk1 = (float)((float)((float)((float)(fPhase * 2.0) - 1.0) * v14) * fB0) - (float)(fFFbk1 * fA1);
        }
        if ( fPhase >= 1.0 )
          fPhase = fPhase - 1.0;
      }
      while ( io_pfBuffer < v11 );
      v18 = FLOAT_6_2831855;
      goto LABEL_149;
  }
  if ( eWaveform == WAVEFORM_SAW_DOWN && io_pfBuffer < v11 )
  {
    do
    {
      v19 = (__m128)(unsigned int)FLOAT_1_0;
      v19.m128_f32[0] = (float)(1.0 - fPhase) * (float)(1.0 / fPhaseDelta);
      v20 = (int)v19.m128_f32[0];
      if ( (int)v19.m128_f32[0] != 0x80000000 && (float)v20 != v19.m128_f32[0] )
        v19.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1) + v20);
      v21 = (int)v19.m128_f32[0];
      if ( (int)v19.m128_f32[0] >= 0 )
      {
        if ( v21 > in_uNumFrames )
          v21 = in_uNumFrames;
      }
      else
      {
        v21 = -1;
      }
      v22 = &io_pfBuffer[v21];
      v23 = (unsigned __int64)v11;
      if ( v22 < v11 )
        v23 = (unsigned __int64)v22;
      for ( ; (unsigned __int64)io_pfBuffer < v23; *(io_pfBuffer - 1) = fFFbk1 )
      {
        fPhase = fPhase + fPhaseDelta;
        v14 = v14 + v16;
        ++io_pfBuffer;
        fFFbk1 = (float)((float)((float)(1.0 - (float)(fPhase * 2.0)) * v14) * fB0) - (float)(fFFbk1 * fA1);
      }
      if ( fPhase >= 1.0 )
        fPhase = fPhase - 1.0;
    }
    while ( io_pfBuffer < v11 );
    v18 = FLOAT_6_2831855;
LABEL_149:
    eWaveform = v77;
  }
LABEL_150:
  if ( !v17 )
  {
    this->m_state.filter.fFFbk1 = fFFbk1;
    this->m_state.filter.fB0 = fB0;
    this->m_state.filter.fA1 = fA1;
    this->m_state.fPhase = fPhase;
    this->m_state.fPhaseDelta = fPhaseDelta;
    this->m_state.eWaveform = eWaveform;
    if ( v76 )
      v75 = *(float *)&FLOAT_1_0;
    else
      v75 = v18;
    this->m_state.fPhase = fmodf(fPhase, v75);
  }
}

