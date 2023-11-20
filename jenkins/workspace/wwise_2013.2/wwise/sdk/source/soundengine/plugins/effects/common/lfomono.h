// File Line: 69
// RVA: 0xAFB430
void __fastcall DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::Setup(DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this, unsigned int in_uSampleRate, DSP::LFO::Params *in_lfoParams, float in_fInitPhase)
{
  DSP::LFO::Params *v4; // rbx
  DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *v5; // rdi
  float v6; // xmm5_4
  DSP::LFO::Waveform v7; // xmm7_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  float v10; // ST2C_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  __int64 v14; // [rsp+30h] [rbp-68h]

  v4 = in_lfoParams;
  v5 = this;
  DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(this, in_uSampleRate, in_lfoParams);
  v6 = v5->m_state.fPhaseDelta;
  v7 = v5->m_state.eWaveform;
  v8 = v5->m_state.filter.fB0;
  v9 = v5->m_state.filter.fA1;
  v10 = v5->m_state.fPhase;
  v14 = *(_QWORD *)&v5->m_state.fPhaseDelta;
  if ( v4->eWaveform )
    v11 = *(float *)&FLOAT_1_0;
  else
    v11 = FLOAT_6_2831855;
  v12 = (float)(v11 * in_fInitPhase) * 0.0027777778;
  if ( HIDWORD(v14) == 1 )
  {
    v12 = v12 + 0.25;
  }
  else if ( HIDWORD(v14) == 3 )
  {
    v12 = v12 + 0.5;
  }
  if ( v12 < 0.0 )
    v12 = v12 + v11;
  if ( v12 >= v11 )
    v12 = v12 - v11;
  v5->m_state.filter.fFFbk1 = v5->m_state.filter.fFFbk1;
  v5->m_state.filter.fB0 = v8;
  v5->m_state.filter.fA1 = v9;
  v5->m_state.fPhase = v12;
  v5->m_state.fPhaseDelta = v6;
  v5->m_state.eWaveform = v7;
  if ( HIDWORD(v14) )
    v13 = *(float *)&FLOAT_1_0;
  else
    v13 = FLOAT_6_2831855;
  v5->m_state.fPhase = fmodf(v12, v13);
}

// File Line: 97
// RVA: 0xAFB350
void __fastcall DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this, unsigned int in_uSampleRate, DSP::LFO::Params *in_lfoParams)
{
  float v3; // xmm7_4
  DSP::LFO::Params *v4; // rbx
  unsigned int v5; // edi
  DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *v6; // rsi
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float in_fA1; // [rsp+70h] [rbp+18h]
  float out_fB0; // [rsp+78h] [rbp+20h]

  v3 = in_lfoParams->fSmooth;
  v4 = in_lfoParams;
  v5 = in_uSampleRate;
  v6 = this;
  if ( v3 == 0.0 )
  {
    DSP::OnePoleFilter::ComputeCoefs(0, 0.0, 0, &out_fB0, &in_fA1);
  }
  else
  {
    v7 = (float)(signed int)in_uSampleRate * 0.5;
    v8 = logf(v7 / in_lfoParams->fFrequency);
    v9 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * v3) ^ _xmm[0]));
    DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_LOWPASS, v9 * v7, v5, &out_fB0, &in_fA1);
  }
  DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::SetParams(v6, v5, v4, out_fB0, in_fA1);
}

// File Line: 110
// RVA: 0xAF4E30
void __fastcall DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::SetParams(DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this, unsigned int in_uSampleRate, DSP::LFO::Params *in_lfoParams, float in_fB0, float in_fA1)
{
  float v5; // xmm1_4
  DSP::LFO::Waveform v6; // edx
  DSP::LFO::Waveform v7; // eax

  v5 = in_lfoParams->fFrequency / (float)(signed int)in_uSampleRate;
  this->m_state.fPhaseDelta = v5;
  if ( in_lfoParams->eWaveform == WAVEFORM_SINE )
    this->m_state.fPhaseDelta = v5 * 6.2831855;
  this->m_state.filter.fB0 = in_fB0;
  this->m_state.filter.fA1 = in_fA1;
  v6 = this->m_state.eWaveform;
  v7 = in_lfoParams->eWaveform;
  if ( v6 != in_lfoParams->eWaveform )
  {
    if ( v6 == WAVEFORM_SINE )
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
void __fastcall DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::ProduceBuffer(DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *this, float *io_pfBuffer, unsigned int in_uNumFrames, float in_fAmp, float in_fPrevAmp, float in_fPWM, FlangerOutputPolicy *in_rParams)
{
  DSP::LFO::Waveform v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy> *v10; // rbx
  float *v11; // r9
  float v12; // xmm8_4
  float v13; // xmm10_4
  float v14; // xmm6_4
  float v15; // xmm11_4
  float v16; // xmm9_4
  bool v17; // r11
  float v18; // xmm0_4
  __m128 v19; // xmm1
  signed int v20; // ecx
  signed int v21; // eax
  float *v22; // rcx
  unsigned __int64 v23; // rax
  __m128 v24; // xmm1
  signed int v25; // ecx
  signed int v26; // eax
  float *v27; // rcx
  unsigned __int64 v28; // rax
  float v29; // xmm3_4
  __m128 v30; // xmm1
  signed int v31; // ecx
  signed int v32; // eax
  float *v33; // rcx
  unsigned __int64 v34; // rax
  __m128 v35; // xmm1
  signed int v36; // ecx
  signed int v37; // eax
  float *v38; // rcx
  unsigned __int64 v39; // rax
  float v40; // xmm3_4
  __m128 v41; // xmm1
  signed int v42; // ecx
  signed int v43; // eax
  float *v44; // rcx
  unsigned __int64 v45; // rax
  __m128 v46; // xmm1
  signed int v47; // ecx
  signed int v48; // eax
  float *v49; // rcx
  unsigned __int64 v50; // rax
  __m128 v51; // xmm2
  float v52; // xmm3_4
  __m128 v53; // xmm1
  signed int v54; // ecx
  signed int v55; // eax
  float *v56; // rcx
  unsigned __int64 v57; // rax
  __m128 v58; // xmm1
  signed int v59; // ecx
  signed int v60; // eax
  float *v61; // rcx
  unsigned __int64 v62; // rax
  float v63; // xmm3_4
  __m128 v64; // xmm1
  signed int v65; // ecx
  signed int v66; // eax
  float *v67; // rcx
  unsigned __int64 v68; // rax
  float v69; // xmm3_4
  float v70; // xmm0_4
  __m128 v71; // xmm1
  signed int v72; // ecx
  signed int v73; // eax
  float *v74; // rcx
  unsigned __int64 v75; // rax
  float v76; // xmm3_4
  float v77; // xmm1_4
  DSP::LFO::Waveform v78; // [rsp+34h] [rbp-B4h]
  DSP::LFO::Waveform v79; // [rsp+100h] [rbp+18h]

  v7 = this->m_state.eWaveform;
  v8 = this->m_state.filter.fFFbk1;
  v9 = this->m_state.fPhase;
  v10 = this;
  v11 = &io_pfBuffer[in_uNumFrames];
  v12 = this->m_state.fPhaseDelta;
  v13 = this->m_state.filter.fB0;
  v14 = in_fPrevAmp;
  v15 = this->m_state.filter.fA1;
  v79 = this->m_state.eWaveform;
  v78 = this->m_state.eWaveform;
  v16 = (float)(in_fAmp - in_fPrevAmp) / (float)(signed int)in_uNumFrames;
  v17 = v12 == 0.0;
  if ( v12 <= 0.0000000099999999 )
    v12 = FLOAT_9_9999999eN9;
  v18 = FLOAT_6_2831855;
  switch ( v78 )
  {
    case 0:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      v51 = (__m128)LODWORD(FLOAT_3_1415927);
      v52 = 1.0 / v12;
      do
      {
        v53 = (__m128)LODWORD(FLOAT_1_5707964);
        v53.m128_f32[0] = (float)(1.5707964 - v9) * v52;
        v54 = (signed int)v53.m128_f32[0];
        if ( (signed int)v53.m128_f32[0] != 0x80000000 && (float)v54 != v53.m128_f32[0] )
          v53.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v53, v53)) & 1 ^ 1) + v54);
        v55 = (signed int)v53.m128_f32[0];
        if ( (signed int)v53.m128_f32[0] >= 0 )
        {
          if ( v55 > (signed int)in_uNumFrames )
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
            v9 = v9 + v12;
            v14 = v14 + v16;
            ++io_pfBuffer;
            *(io_pfBuffer - 1) = (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                               - (float)((float)(v9 * v9) * 0.00018363654))
                                                                       * (float)(v9 * v9))
                                                               - 0.16664828)
                                                       * (float)(v9 * v9))
                                               + 0.9999966)
                                       * v9)
                               * v14;
          }
          while ( (unsigned __int64)io_pfBuffer < v57 );
          v51 = (__m128)LODWORD(FLOAT_3_1415927);
        }
        v58 = v51;
        v58.m128_f32[0] = (float)(v51.m128_f32[0] - v9) * v52;
        v59 = (signed int)v58.m128_f32[0];
        if ( (signed int)v58.m128_f32[0] != 0x80000000 && (float)v59 != v58.m128_f32[0] )
          v58.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v58, v58)) & 1 ^ 1) + v59);
        v60 = (signed int)v58.m128_f32[0];
        if ( (signed int)v58.m128_f32[0] >= 0 )
        {
          if ( v60 > (signed int)in_uNumFrames )
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
            v9 = v9 + v12;
            v63 = v51.m128_f32[0] - v9;
            v14 = v14 + v16;
            ++io_pfBuffer;
            *(io_pfBuffer - 1) = (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                               - (float)((float)(v63 * v63)
                                                                                       * 0.00018363654))
                                                                       * (float)(v63 * v63))
                                                               - 0.16664828)
                                                       * (float)(v63 * v63))
                                               + 0.9999966)
                                       * v63)
                               * v14;
            v51.m128_f32[0] = FLOAT_3_1415927;
          }
          while ( (unsigned __int64)io_pfBuffer < v62 );
          v52 = 1.0 / v12;
        }
        v64 = (__m128)LODWORD(FLOAT_4_712389);
        v64.m128_f32[0] = (float)(4.712389 - v9) * v52;
        v65 = (signed int)v64.m128_f32[0];
        if ( (signed int)v64.m128_f32[0] != 0x80000000 && (float)v65 != v64.m128_f32[0] )
          v64.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v64, v64)) & 1 ^ 1) + v65);
        v66 = (signed int)v64.m128_f32[0];
        if ( (signed int)v64.m128_f32[0] >= 0 )
        {
          if ( v66 > (signed int)in_uNumFrames )
            v66 = in_uNumFrames;
        }
        else
        {
          v66 = -1;
        }
        v67 = &io_pfBuffer[v66];
        v68 = (unsigned __int64)v11;
        if ( v67 < v11 )
          v68 = (unsigned __int64)v67;
        if ( (unsigned __int64)io_pfBuffer < v68 )
        {
          do
          {
            v9 = v9 + v12;
            v14 = v14 + v16;
            ++io_pfBuffer;
            v69 = v9 - v51.m128_f32[0];
            *((_DWORD *)io_pfBuffer - 1) = COERCE_UNSIGNED_INT(
                                             (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                                           - (float)((float)(v69 * v69) * 0.00018363654))
                                                                                   * (float)(v69 * v69))
                                                                           - 0.16664828)
                                                                   * (float)(v69 * v69))
                                                           + 0.9999966)
                                                   * v69)
                                           * v14) ^ _xmm[0];
            v51.m128_f32[0] = FLOAT_3_1415927;
          }
          while ( (unsigned __int64)io_pfBuffer < v68 );
          v52 = 1.0 / v12;
        }
        v70 = FLOAT_6_2831855;
        v71 = (__m128)LODWORD(FLOAT_6_2831855);
        v71.m128_f32[0] = (float)(6.2831855 - v9) * v52;
        v72 = (signed int)v71.m128_f32[0];
        if ( (signed int)v71.m128_f32[0] != 0x80000000 )
        {
          v70 = FLOAT_6_2831855;
          if ( (float)v72 != v71.m128_f32[0] )
            v71.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v71, v71)) & 1 ^ 1) + v72);
        }
        v73 = (signed int)v71.m128_f32[0];
        if ( (signed int)v71.m128_f32[0] >= 0 )
        {
          if ( v73 > (signed int)in_uNumFrames )
            v73 = in_uNumFrames;
        }
        else
        {
          v73 = -1;
        }
        v74 = &io_pfBuffer[v73];
        v75 = (unsigned __int64)v11;
        if ( v74 < v11 )
          v75 = (unsigned __int64)v74;
        if ( (unsigned __int64)io_pfBuffer < v75 )
        {
          do
          {
            v9 = v9 + v12;
            v76 = v70 - v9;
            v14 = v14 + v16;
            ++io_pfBuffer;
            v70 = FLOAT_6_2831855;
            *((_DWORD *)io_pfBuffer - 1) = COERCE_UNSIGNED_INT(
                                             (float)((float)((float)((float)((float)((float)(0.0083063254
                                                                                           - (float)((float)(v76 * v76) * 0.00018363654))
                                                                                   * (float)(v76 * v76))
                                                                           - 0.16664828)
                                                                   * (float)(v76 * v76))
                                                           + 0.9999966)
                                                   * v76)
                                           * v14) ^ _xmm[0];
          }
          while ( (unsigned __int64)io_pfBuffer < v75 );
          v52 = 1.0 / v12;
        }
        v18 = FLOAT_6_2831855;
        if ( v9 >= 6.2831855 )
          v9 = v9 + -6.2831855;
        v51 = (__m128)LODWORD(FLOAT_3_1415927);
      }
      while ( io_pfBuffer < v11 );
      goto LABEL_149;
    case 1:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      v40 = 1.0 / v12;
      do
      {
        v41 = (__m128)LODWORD(FLOAT_0_5);
        v41.m128_f32[0] = (float)(0.5 - v9) * v40;
        v42 = (signed int)v41.m128_f32[0];
        if ( (signed int)v41.m128_f32[0] != 0x80000000 && (float)v42 != v41.m128_f32[0] )
          v41.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v41, v41)) & 1 ^ 1) + v42);
        v43 = (signed int)v41.m128_f32[0];
        if ( (signed int)v41.m128_f32[0] >= 0 )
        {
          if ( v43 > (signed int)in_uNumFrames )
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
        for ( ; (unsigned __int64)io_pfBuffer < v45; *(io_pfBuffer - 1) = v8 )
        {
          v9 = v9 + v12;
          v14 = v14 + v16;
          ++io_pfBuffer;
          v8 = (float)((float)((float)((float)(v9 * 4.0) - 1.0) * v14) * v13) - (float)(v8 * v15);
        }
        v46 = (__m128)(unsigned int)FLOAT_1_0;
        v46.m128_f32[0] = (float)(1.0 - v9) * v40;
        v47 = (signed int)v46.m128_f32[0];
        if ( (signed int)v46.m128_f32[0] != 0x80000000 && (float)v47 != v46.m128_f32[0] )
          v46.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v46, v46)) & 1 ^ 1) + v47);
        v48 = (signed int)v46.m128_f32[0];
        if ( (signed int)v46.m128_f32[0] >= 0 )
        {
          if ( v48 > (signed int)in_uNumFrames )
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
        for ( ; (unsigned __int64)io_pfBuffer < v50; *(io_pfBuffer - 1) = v8 )
        {
          v9 = v9 + v12;
          v14 = v14 + v16;
          ++io_pfBuffer;
          v8 = (float)((float)((float)((float)((float)(1.0 - v9) * 4.0) - 1.0) * v14) * v13) - (float)(v8 * v15);
        }
        if ( v9 >= 1.0 )
          v9 = v9 - 1.0;
      }
      while ( io_pfBuffer < v11 );
      v18 = FLOAT_6_2831855;
      goto LABEL_149;
    case 2:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      v29 = 1.0 / v12;
      do
      {
        v30 = (__m128)LODWORD(in_fPWM);
        v30.m128_f32[0] = (float)(in_fPWM - v9) * v29;
        v31 = (signed int)v30.m128_f32[0];
        if ( (signed int)v30.m128_f32[0] != 0x80000000 && (float)v31 != v30.m128_f32[0] )
          v30.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v30, v30)) & 1 ^ 1) + v31);
        v32 = (signed int)v30.m128_f32[0];
        if ( (signed int)v30.m128_f32[0] >= 0 )
        {
          if ( v32 > (signed int)in_uNumFrames )
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
        for ( ; (unsigned __int64)io_pfBuffer < v34; *(io_pfBuffer - 1) = v8 )
        {
          v14 = v14 + v16;
          ++io_pfBuffer;
          v9 = v9 + v12;
          v8 = (float)(v13 * v14) - (float)(v8 * v15);
        }
        v35 = (__m128)(unsigned int)FLOAT_1_0;
        v35.m128_f32[0] = (float)(1.0 - v9) * v29;
        v36 = (signed int)v35.m128_f32[0];
        if ( (signed int)v35.m128_f32[0] != 0x80000000 && (float)v36 != v35.m128_f32[0] )
          v35.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1 ^ 1) + v36);
        v37 = (signed int)v35.m128_f32[0];
        if ( (signed int)v35.m128_f32[0] >= 0 )
        {
          if ( v37 > (signed int)in_uNumFrames )
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
        for ( ; (unsigned __int64)io_pfBuffer < v39; *(io_pfBuffer - 1) = v8 )
        {
          v14 = v14 + v16;
          ++io_pfBuffer;
          v9 = v9 + v12;
          v8 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 * v14) ^ _xmm[0]) - (float)(v8 * v15);
        }
        if ( v9 >= 1.0 )
          v9 = v9 - 1.0;
      }
      while ( io_pfBuffer < v11 );
      v18 = FLOAT_6_2831855;
      goto LABEL_149;
    case 3:
      if ( io_pfBuffer >= v11 )
        goto LABEL_150;
      do
      {
        v24 = (__m128)(unsigned int)FLOAT_1_0;
        v24.m128_f32[0] = (float)(1.0 - v9) * (float)(1.0 / v12);
        v25 = (signed int)v24.m128_f32[0];
        if ( (signed int)v24.m128_f32[0] != 0x80000000 && (float)v25 != v24.m128_f32[0] )
          v24.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v24, v24)) & 1 ^ 1) + v25);
        v26 = (signed int)v24.m128_f32[0];
        if ( (signed int)v24.m128_f32[0] >= 0 )
        {
          if ( v26 > (signed int)in_uNumFrames )
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
        for ( ; (unsigned __int64)io_pfBuffer < v28; *(io_pfBuffer - 1) = v8 )
        {
          v9 = v9 + v12;
          v14 = v14 + v16;
          ++io_pfBuffer;
          v8 = (float)((float)((float)((float)(v9 * 2.0) - 1.0) * v14) * v13) - (float)(v8 * v15);
        }
        if ( v9 >= 1.0 )
          v9 = v9 - 1.0;
      }
      while ( io_pfBuffer < v11 );
      v18 = FLOAT_6_2831855;
      goto LABEL_149;
  }
  if ( v78 == 4 && io_pfBuffer < v11 )
  {
    do
    {
      v19 = (__m128)(unsigned int)FLOAT_1_0;
      v19.m128_f32[0] = (float)(1.0 - v9) * (float)(1.0 / v12);
      v20 = (signed int)v19.m128_f32[0];
      if ( (signed int)v19.m128_f32[0] != 0x80000000 && (float)v20 != v19.m128_f32[0] )
        v19.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1 ^ 1) + v20);
      v21 = (signed int)v19.m128_f32[0];
      if ( (signed int)v19.m128_f32[0] >= 0 )
      {
        if ( v21 > (signed int)in_uNumFrames )
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
      for ( ; (unsigned __int64)io_pfBuffer < v23; *(io_pfBuffer - 1) = v8 )
      {
        v9 = v9 + v12;
        v14 = v14 + v16;
        ++io_pfBuffer;
        v8 = (float)((float)((float)(1.0 - (float)(v9 * 2.0)) * v14) * v13) - (float)(v8 * v15);
      }
      if ( v9 >= 1.0 )
        v9 = v9 - 1.0;
    }
    while ( io_pfBuffer < v11 );
    v18 = FLOAT_6_2831855;
LABEL_149:
    v7 = v79;
  }
LABEL_150:
  if ( !v17 )
  {
    v10->m_state.filter.fFFbk1 = v8;
    v10->m_state.filter.fB0 = v13;
    v10->m_state.filter.fA1 = v15;
    v10->m_state.fPhase = v9;
    v10->m_state.fPhaseDelta = v12;
    v10->m_state.eWaveform = v7;
    if ( v78 )
      v77 = *(float *)&FLOAT_1_0;
    else
      v77 = v18;
    v10->m_state.fPhase = fmodf(v9, v77);
  }
}

