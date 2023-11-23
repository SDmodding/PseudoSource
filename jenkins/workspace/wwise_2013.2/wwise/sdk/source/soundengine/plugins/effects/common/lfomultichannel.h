// File Line: 51
// RVA: 0xAFA8B0
void __fastcall DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>(
        DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *this)
{
  *(_QWORD *)&this->m_arLfo[0].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[0].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[0].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[1].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[1].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[1].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[2].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[2].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[2].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[3].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[3].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[3].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[4].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[4].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[4].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[5].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[5].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[5].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[6].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[6].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[6].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_arLfo[7].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_arLfo[7].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_arLfo[7].m_state.fPhaseDelta = 0i64;
  this->m_uNumChannels = 0;
}

// File Line: 60
// RVA: 0xAFB560
void __fastcall DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
        DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *this,
        unsigned int in_uChannelMask,
        int in_uSampleRate,
        DSP::LFO::MultiChannel::AllParams *in_params)
{
  __int64 v4; // rbx
  unsigned int v7; // r11d
  unsigned int i; // r10d
  unsigned __int64 v10; // rax
  __int64 v11; // rcx
  signed __int64 v12; // rcx
  void *v13; // rsp
  void *v14; // rsp
  float out_uChannelPhase[4]; // [rsp+20h] [rbp+0h] BYREF

  v4 = 0i64;
  v7 = 0;
  for ( i = in_uChannelMask; i; i &= i - 1 )
    ++v7;
  this->m_uNumChannels = v7;
  if ( v7 )
  {
    v10 = 4i64 * v7;
    v11 = v10 + 15;
    if ( v10 + 15 <= v10 )
      v11 = 0xFFFFFFFFFFFFFF0i64;
    v12 = v11 & 0xFFFFFFFFFFFFFFF0ui64;
    v13 = alloca(v12);
    v14 = alloca(v12);
    DSP::LFO::MultiChannel::ComputeInitialPhase(in_uChannelMask, &in_params->phaseParams, out_uChannelPhase);
    if ( this->m_uNumChannels )
    {
      do
      {
        DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::Setup(
          &this->m_arLfo[v4],
          in_uSampleRate,
          &in_params->lfoParams,
          out_uChannelPhase[v4]);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < this->m_uNumChannels );
    }
  }
}

// File Line: 87
// RVA: 0xAF4EB0
void __fastcall DSP::MultiChannelLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(
        DSP::MultiChannelLFO<DSP::Unipolar,TremoloOutputPolicy> *this,
        int in_uSampleRate,
        DSP::LFO::Params *in_lfoParams)
{
  float fSmooth; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  __int64 v10; // rdx
  float v11; // xmm3_4
  float v12; // xmm4_4
  __int64 v13; // rcx
  float v14; // xmm0_4
  DSP::LFO::Waveform eWaveform; // eax
  float v16; // xmm0_4
  float out_fA1; // [rsp+60h] [rbp+8h] BYREF
  float out_fB0; // [rsp+70h] [rbp+18h] BYREF

  fSmooth = in_lfoParams->fSmooth;
  if ( fSmooth == 0.0 )
  {
    DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_NONE, 0.0, 0, &out_fB0, &out_fA1);
  }
  else
  {
    v7 = (float)in_uSampleRate * 0.5;
    v8 = logf(v7 / in_lfoParams->fFrequency);
    v9 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * fSmooth) ^ _xmm[0]));
    DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_LOWPASS, v9 * v7, in_uSampleRate, &out_fB0, &out_fA1);
  }
  v10 = 0i64;
  if ( this->m_uNumChannels )
  {
    v11 = out_fA1;
    v12 = out_fB0;
    while ( 1 )
    {
      v13 = v10;
      v14 = (float)(1.0 / (float)in_uSampleRate) * in_lfoParams->fFrequency;
      this->m_arLfo[v10].m_state.fPhaseDelta = v14;
      if ( in_lfoParams->eWaveform == WAVEFORM_SINE )
        this->m_arLfo[v10].m_state.fPhaseDelta = v14 * 6.2831855;
      this->m_arLfo[v10].m_state.filter.fB0 = v12;
      this->m_arLfo[v10].m_state.filter.fA1 = v11;
      eWaveform = this->m_arLfo[v10].m_state.eWaveform;
      if ( eWaveform == in_lfoParams->eWaveform )
        goto LABEL_14;
      if ( eWaveform == WAVEFORM_SINE )
        break;
      if ( in_lfoParams->eWaveform == WAVEFORM_SINE )
      {
        v16 = this->m_arLfo[v10].m_state.fPhase * 6.2831855;
        goto LABEL_13;
      }
LABEL_14:
      v10 = (unsigned int)(v10 + 1);
      this->m_arLfo[v13].m_state.eWaveform = in_lfoParams->eWaveform;
      if ( (unsigned int)v10 >= this->m_uNumChannels )
        return;
    }
    v16 = this->m_arLfo[v10].m_state.fPhase * 0.15915494;
LABEL_13:
    this->m_arLfo[v10].m_state.fPhase = v16;
    goto LABEL_14;
  }
}

