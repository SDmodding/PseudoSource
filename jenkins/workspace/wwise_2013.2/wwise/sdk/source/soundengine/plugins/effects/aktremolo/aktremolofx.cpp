// File Line: 27
// RVA: 0xAF2B70
void __fastcall CreateTremoloFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkTremoloFX *v1; // rax

  v1 = (CAkTremoloFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 312i64);
  if ( v1 )
    CAkTremoloFX::CAkTremoloFX(v1);
}

// File Line: 35
// RVA: 0xAF2BF0
void __fastcall CAkTremoloFX::CAkTremoloFX(CAkTremoloFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkTremoloFX::`vftable;
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
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 52
// RVA: 0xAF2D10
__int64 __fastcall CAkTremoloFX::Init(
        CAkTremoloFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkTremoloFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  unsigned int uSampleRate; // eax
  int v8; // edx

  this->m_pSharedParams = in_pParams;
  this->m_FXInfo.Params.RTPC.fModDepth = in_pParams->m_Params.RTPC.fModDepth;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = in_pParams->m_Params.RTPC.modParams.lfoParams.eWaveform;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.modParams.lfoParams.fFrequency;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.modParams.lfoParams.fPWM;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.fOutputGain = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.fOutputGain;
  *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bProcessCenter = *(_DWORD *)&in_pParams->m_Params.NonRTPC.bProcessCenter;
  CAkTremoloFXParams::SetDirty(in_pParams, 0);
  this->m_FXInfo.PrevParams = this->m_FXInfo.Params;
  uSampleRate = in_rFormat->uSampleRate;
  this->m_pAllocator = in_pAllocator;
  this->m_FXInfo.uSampleRate = uSampleRate;
  v8 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (*((_BYTE *)in_rFormat + 4) & 7) == 7 )
    v8 = *((_DWORD *)in_rFormat + 1) & 0x3FFFB;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    v8 &= ~8u;
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
    (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&this->m_lfo,
    v8,
    this->m_FXInfo.uSampleRate,
    &this->m_FXInfo.Params.RTPC.modParams);
  return 1i64;
}

// File Line: 69
// RVA: 0xAF30F0
void __fastcall CAkTremoloFX::SetupLFO(CAkTremoloFX *this, unsigned int in_uChannelMask)
{
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (in_uChannelMask & 7) == 7 )
    in_uChannelMask &= ~4u;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    in_uChannelMask &= ~8u;
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
    (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&this->m_lfo,
    in_uChannelMask,
    this->m_FXInfo.uSampleRate,
    &this->m_FXInfo.Params.RTPC.modParams);
}

// File Line: 85
// RVA: 0xAF2E20
__int64 __fastcall CAkTremoloFX::Term(CAkTremoloFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 93
// RVA: 0xAF2E70
__int64 __fastcall CAkTremoloFX::GetPluginInfo(CAkTremoloFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 106
// RVA: 0xAF3130
void __fastcall CAkTremoloFX::LiveParametersUpdate(CAkTremoloFX *this, AkAudioBuffer *io_pBuffer)
{
  bool bProcessLFE; // cl
  unsigned int uChannelMask; // edx

  bProcessLFE = this->m_FXInfo.Params.NonRTPC.bProcessLFE;
  if ( this->m_FXInfo.PrevParams.NonRTPC.bProcessLFE != bProcessLFE
    || this->m_FXInfo.PrevParams.NonRTPC.bProcessCenter != this->m_FXInfo.Params.NonRTPC.bProcessCenter )
  {
    uChannelMask = io_pBuffer->uChannelMask;
    if ( !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (uChannelMask & 7) == 7 )
      uChannelMask &= ~4u;
    if ( !bProcessLFE )
      uChannelMask &= ~8u;
    DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
      (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&this->m_lfo,
      uChannelMask,
      this->m_FXInfo.uSampleRate,
      &this->m_FXInfo.Params.RTPC.modParams);
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
  CAkTremoloFXParams *m_pSharedParams; // rcx
  bool bProcessLFE; // cl
  unsigned int uChannelMask; // edx
  unsigned int v7; // ecx
  bool v8; // bp
  signed int uValidFrames; // r15d
  float fOutputGain; // xmm7_4
  float fModDepth; // xmm8_4
  __int64 v12; // rdi
  unsigned int v13; // esi
  float in_fPrevAmp; // xmm9_4
  float in_fPWM; // xmm10_4
  float i; // xmm6_4
  float *pData; // rax
  __int64 uMaxFrames; // rcx
  TremoloOutputPolicy in_rParams; // [rsp+B0h] [rbp+8h] BYREF

  if ( this->m_lfo.m_uNumChannels )
  {
    m_pSharedParams = this->m_pSharedParams;
    this->m_FXInfo.Params = m_pSharedParams->m_Params;
    CAkTremoloFXParams::SetDirty(m_pSharedParams, 0);
    if ( this->m_FXInfo.Params.NonRTPC.bHasChanged )
    {
      bProcessLFE = this->m_FXInfo.Params.NonRTPC.bProcessLFE;
      if ( this->m_FXInfo.PrevParams.NonRTPC.bProcessLFE != bProcessLFE
        || this->m_FXInfo.PrevParams.NonRTPC.bProcessCenter != this->m_FXInfo.Params.NonRTPC.bProcessCenter )
      {
        uChannelMask = io_pBuffer->uChannelMask;
        if ( !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (uChannelMask & 7) == 7 )
          uChannelMask &= ~4u;
        if ( !bProcessLFE )
          uChannelMask &= ~8u;
        DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
          (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)&this->m_lfo,
          uChannelMask,
          this->m_FXInfo.uSampleRate,
          &this->m_FXInfo.Params.RTPC.modParams);
      }
    }
    if ( this->m_FXInfo.Params.RTPC.bHasChanged )
      DSP::MultiChannelLFO<DSP::Unipolar,TremoloOutputPolicy>::SetParams(
        &this->m_lfo,
        this->m_FXInfo.uSampleRate,
        &this->m_FXInfo.Params.RTPC.modParams.lfoParams);
    v7 = io_pBuffer->uChannelMask;
    if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
      v7 &= ~8u;
    v8 = !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (v7 & 7) == 7;
    uValidFrames = io_pBuffer->uValidFrames;
    fOutputGain = this->m_FXInfo.Params.RTPC.fOutputGain;
    fModDepth = this->m_FXInfo.Params.RTPC.fModDepth;
    v12 = 0i64;
    v13 = 0;
    in_fPrevAmp = this->m_FXInfo.PrevParams.RTPC.fModDepth;
    in_fPWM = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
    for ( i = (float)(fOutputGain - this->m_FXInfo.PrevParams.RTPC.fOutputGain) / (float)uValidFrames; v7; v7 &= v7 - 1 )
      ++v13;
    if ( v13 )
    {
      do
      {
        if ( !v8 || (_DWORD)v12 != 2 )
        {
          pData = (float *)io_pBuffer->pData;
          uMaxFrames = io_pBuffer->uMaxFrames;
          in_rParams.fGain = fOutputGain;
          in_rParams.fGainInc = i;
          DSP::MonoLFO<DSP::Unipolar,TremoloOutputPolicy>::ProduceBuffer(
            &this->m_lfo.m_arLfo[v12],
            &pData[(unsigned int)v12 * uMaxFrames],
            uValidFrames,
            fModDepth,
            in_fPrevAmp,
            in_fPWM,
            &in_rParams);
        }
        v12 = (unsigned int)(v12 + 1);
      }
      while ( (unsigned int)v12 < v13 );
    }
    this->m_FXInfo.PrevParams.RTPC.fModDepth = this->m_FXInfo.Params.RTPC.fModDepth;
    this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
    this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
    this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
    this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
    this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
    this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
    this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
    this->m_FXInfo.PrevParams.RTPC.fOutputGain = this->m_FXInfo.Params.RTPC.fOutputGain;
    *(_DWORD *)&this->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&this->m_FXInfo.Params.RTPC.bHasChanged;
    *(_DWORD *)&this->m_FXInfo.PrevParams.NonRTPC.bProcessCenter = *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bProcessCenter;
  }
}

// File Line: 212
// RVA: 0xAF2E60
__int64 __fastcall CAkTremoloFX::Reset(CAkTremoloFX *this)
{
  return 1i64;
}

