// File Line: 27
// RVA: 0xAF2B70
void __fastcall CreateTremoloFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkTremoloFX *v1; // rax

  v1 = (CAkTremoloFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 312ui64);
  if ( v1 )
    CAkTremoloFX::CAkTremoloFX(v1);
}

// File Line: 35
// RVA: 0xAF2BF0
void __fastcall CAkTremoloFX::CAkTremoloFX(CAkTremoloFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkTremoloFX::`vftable';
  *(_QWORD *)&this->m_lfo.m_arLfo[0].m_state.filter.fFFbk1 = 0i64;
  this->m_pSharedParams = 0i64;
  this->m_pAllocator = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[0].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[0].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[1].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[1].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[1].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[2].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[2].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[2].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[3].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[3].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[3].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[4].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[4].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[4].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[5].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[5].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[5].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[6].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[6].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[6].m_state.fPhaseDelta = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[7].m_state.filter.fFFbk1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[7].m_state.filter.fA1 = 0i64;
  *(_QWORD *)&this->m_lfo.m_arLfo[7].m_state.fPhaseDelta = 0i64;
  this->m_lfo.m_uNumChannels = 0;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.fModDepth = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.fOutputGain = 0i64;
  *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bProcessCenter = 0;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.fModDepth = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.fOutputGain = 0i64;
  *(_DWORD *)&this->m_FXInfo.PrevParams.NonRTPC.bProcessCenter = 0;
}

// File Line: 42
// RVA: 0xAF2CF0
void __fastcall CAkTremoloFX::~CAkTremoloFX(CAkTremoloFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 52
// RVA: 0xAF2D10
signed __int64 __fastcall CAkTremoloFX::Init(CAkTremoloFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AK::IAkPluginMemAlloc *v5; // rbx
  CAkTremoloFX *v6; // rdi
  unsigned int v7; // eax
  int v8; // edx

  this->m_pSharedParams = (CAkTremoloFXParams *)in_pParams;
  v5 = in_pAllocator;
  this->m_FXInfo.Params.RTPC.fModDepth = *(float *)&in_pParams[1].vfptr;
  v6 = this;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = HIDWORD(in_pParams[1].vfptr);
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = *(float *)&in_pParams[2].vfptr;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth = *((float *)&in_pParams[2].vfptr + 1);
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM = *(float *)&in_pParams[3].vfptr;
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset = *((float *)&in_pParams[3].vfptr + 1);
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = *(float *)&in_pParams[4].vfptr;
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode = HIDWORD(in_pParams[4].vfptr);
  this->m_FXInfo.Params.RTPC.fOutputGain = *(float *)&in_pParams[5].vfptr;
  *(_DWORD *)&this->m_FXInfo.Params.RTPC.bHasChanged = HIDWORD(in_pParams[5].vfptr);
  *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bProcessCenter = in_pParams[6].vfptr;
  CAkTremoloFXParams::SetDirty((CAkTremoloFXParams *)in_pParams, 0);
  v6->m_FXInfo.PrevParams.RTPC.fModDepth = v6->m_FXInfo.Params.RTPC.fModDepth;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
  v6->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = v6->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
  v6->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = v6->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
  v6->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = v6->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
  v6->m_FXInfo.PrevParams.RTPC.fOutputGain = v6->m_FXInfo.Params.RTPC.fOutputGain;
  *(_DWORD *)&v6->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&v6->m_FXInfo.Params.RTPC.bHasChanged;
  *(_DWORD *)&v6->m_FXInfo.PrevParams.NonRTPC.bProcessCenter = *(_DWORD *)&v6->m_FXInfo.Params.NonRTPC.bProcessCenter;
  v7 = in_rFormat->uSampleRate;
  v6->m_pAllocator = v5;
  v6->m_FXInfo.uSampleRate = v7;
  v8 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( !v6->m_FXInfo.Params.NonRTPC.bProcessCenter && (*((_BYTE *)in_rFormat + 4) & 7) == 7 )
    v8 = *((_DWORD *)in_rFormat + 1) & 0x3FFFB;
  if ( !v6->m_FXInfo.Params.NonRTPC.bProcessLFE )
    v8 &= 0xFFFFFFF7;
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
    (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&v6->m_lfo,
    v8,
    v6->m_FXInfo.uSampleRate,
    &v6->m_FXInfo.Params.RTPC.modParams);
  return 1i64;
}

// File Line: 69
// RVA: 0xAF30F0
void __fastcall CAkTremoloFX::SetupLFO(CAkTremoloFX *this, unsigned int in_uChannelMask)
{
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (in_uChannelMask & 7) == 7 )
    in_uChannelMask &= 0xFFFFFFFB;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    in_uChannelMask &= 0xFFFFFFF7;
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
    (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&this->m_lfo,
    in_uChannelMask,
    this->m_FXInfo.uSampleRate,
    &this->m_FXInfo.Params.RTPC.modParams);
}

// File Line: 85
// RVA: 0xAF2E20
signed __int64 __fastcall CAkTremoloFX::Term(CAkTremoloFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkTremoloFX *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkPlugin *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 93
// RVA: 0xAF2E70
signed __int64 __fastcall CAkTremoloFX::GetPluginInfo(CAkTremoloFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 106
// RVA: 0xAF3130
void __fastcall CAkTremoloFX::LiveParametersUpdate(CAkTremoloFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkTremoloFX *v2; // r8
  bool v3; // cl
  unsigned int v4; // edx

  v2 = this;
  v3 = this->m_FXInfo.Params.NonRTPC.bProcessLFE;
  if ( v2->m_FXInfo.PrevParams.NonRTPC.bProcessLFE != v3
    || v2->m_FXInfo.PrevParams.NonRTPC.bProcessCenter != v2->m_FXInfo.Params.NonRTPC.bProcessCenter )
  {
    v4 = io_pBuffer->uChannelMask;
    if ( !v2->m_FXInfo.Params.NonRTPC.bProcessCenter && (v4 & 7) == 7 )
      v4 &= 0xFFFFFFFB;
    if ( !v3 )
      v4 &= 0xFFFFFFF7;
    DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
      (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&v2->m_lfo,
      v4,
      v2->m_FXInfo.uSampleRate,
      &v2->m_FXInfo.Params.RTPC.modParams);
  }
}

// File Line: 117
// RVA: 0xAF3180
void __fastcall CAkTremoloFX::RTPCParametersUpdate(CAkTremoloFX *this)
{
  DSP::MultiChannelLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(
    &this->m_lfo,
    this->m_FXInfo.uSampleRate,
    &this->m_FXInfo.Params.RTPC.modParams.lfoParams);
}

// File Line: 131
// RVA: 0xAF2E90
void __fastcall CAkTremoloFX::Execute(CAkTremoloFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r14
  CAkTremoloFX *v3; // rbx
  CAkTremoloFXParams *v4; // rcx
  bool v5; // cl
  unsigned int v6; // edx
  unsigned int v7; // ecx
  bool v8; // bp
  signed int v9; // er15
  float v10; // xmm7_4
  float v11; // xmm8_4
  __int64 v12; // rdi
  unsigned int v13; // esi
  float in_fPrevAmp; // xmm9_4
  float in_fPWM; // xmm10_4
  float i; // xmm6_4
  float *v17; // rax
  __int64 v18; // rcx
  TremoloOutputPolicy in_rParams; // [rsp+B0h] [rbp+8h]

  v2 = io_pBuffer;
  v3 = this;
  if ( this->m_lfo.m_uNumChannels )
  {
    v4 = this->m_pSharedParams;
    v3->m_FXInfo.Params.RTPC.fModDepth = v4->m_Params.RTPC.fModDepth;
    v3->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = v4->m_Params.RTPC.modParams.lfoParams.eWaveform;
    v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = v4->m_Params.RTPC.modParams.lfoParams.fFrequency;
    v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth = v4->m_Params.RTPC.modParams.lfoParams.fSmooth;
    v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM = v4->m_Params.RTPC.modParams.lfoParams.fPWM;
    v3->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset = v4->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
    v3->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = v4->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
    v3->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode = v4->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
    v3->m_FXInfo.Params.RTPC.fOutputGain = v4->m_Params.RTPC.fOutputGain;
    *(_DWORD *)&v3->m_FXInfo.Params.RTPC.bHasChanged = *(_DWORD *)&v4->m_Params.RTPC.bHasChanged;
    *(_DWORD *)&v3->m_FXInfo.Params.NonRTPC.bProcessCenter = *(_DWORD *)&v4->m_Params.NonRTPC.bProcessCenter;
    CAkTremoloFXParams::SetDirty(v4, 0);
    if ( v3->m_FXInfo.Params.NonRTPC.bHasChanged )
    {
      v5 = v3->m_FXInfo.Params.NonRTPC.bProcessLFE;
      if ( v3->m_FXInfo.PrevParams.NonRTPC.bProcessLFE != v5
        || v3->m_FXInfo.PrevParams.NonRTPC.bProcessCenter != v3->m_FXInfo.Params.NonRTPC.bProcessCenter )
      {
        v6 = v2->uChannelMask;
        if ( !v3->m_FXInfo.Params.NonRTPC.bProcessCenter && (v6 & 7) == 7 )
          v6 &= 0xFFFFFFFB;
        if ( !v5 )
          v6 &= 0xFFFFFFF7;
        DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
          (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&v3->m_lfo,
          v6,
          v3->m_FXInfo.uSampleRate,
          &v3->m_FXInfo.Params.RTPC.modParams);
      }
    }
    if ( v3->m_FXInfo.Params.RTPC.bHasChanged )
      DSP::MultiChannelLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(
        &v3->m_lfo,
        v3->m_FXInfo.uSampleRate,
        &v3->m_FXInfo.Params.RTPC.modParams.lfoParams);
    v7 = v2->uChannelMask;
    if ( !v3->m_FXInfo.Params.NonRTPC.bProcessLFE )
      v7 &= 0xFFFFFFF7;
    v8 = !v3->m_FXInfo.Params.NonRTPC.bProcessCenter && (v7 & 7) == 7;
    v9 = v2->uValidFrames;
    v10 = v3->m_FXInfo.Params.RTPC.fOutputGain;
    v11 = v3->m_FXInfo.Params.RTPC.fModDepth;
    v12 = 0i64;
    v13 = 0;
    in_fPrevAmp = v3->m_FXInfo.PrevParams.RTPC.fModDepth;
    in_fPWM = v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
    for ( i = (float)(v3->m_FXInfo.Params.RTPC.fOutputGain - v3->m_FXInfo.PrevParams.RTPC.fOutputGain) / (float)v9;
          v7;
          v7 &= v7 - 1 )
    {
      ++v13;
    }
    if ( v13 )
    {
      do
      {
        if ( !v8 || (_DWORD)v12 != 2 )
        {
          v17 = (float *)v2->pData;
          v18 = v2->uMaxFrames;
          in_rParams.fGain = v10;
          in_rParams.fGainInc = i;
          DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::ProduceBuffer(
            &v3->m_lfo.m_arLfo[v12],
            &v17[(unsigned int)v12 * v18],
            v9,
            v11,
            in_fPrevAmp,
            in_fPWM,
            &in_rParams);
        }
        v12 = (unsigned int)(v12 + 1);
      }
      while ( (unsigned int)v12 < v13 );
    }
    v3->m_FXInfo.PrevParams.RTPC.fModDepth = v3->m_FXInfo.Params.RTPC.fModDepth;
    v3->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = v3->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
    v3->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
    v3->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
    v3->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = v3->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
    v3->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = v3->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
    v3->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = v3->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
    v3->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = v3->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
    v3->m_FXInfo.PrevParams.RTPC.fOutputGain = v3->m_FXInfo.Params.RTPC.fOutputGain;
    *(_DWORD *)&v3->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&v3->m_FXInfo.Params.RTPC.bHasChanged;
    *(_DWORD *)&v3->m_FXInfo.PrevParams.NonRTPC.bProcessCenter = *(_DWORD *)&v3->m_FXInfo.Params.NonRTPC.bProcessCenter;
  }
}

// File Line: 212
// RVA: 0xAF2E60
signed __int64 __fastcall CAkTremoloFX::Reset(CAkTremoloFX *this)
{
  return 1i64;
}

