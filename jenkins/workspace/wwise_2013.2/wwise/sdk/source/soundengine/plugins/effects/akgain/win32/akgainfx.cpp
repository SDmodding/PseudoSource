// File Line: 38
// RVA: 0xAF64A0
AK::IAkPlugin *__fastcall CreateGainFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32i64);
  if ( result )
    result->vfptr = (AK::IAkPluginVtbl *)&CAkGainFX::`vftable;
  return result;
}

// File Line: 46
// RVA: 0xAF64D0
void __fastcall CAkGainFX::CAkGainFX(CAkGainFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkGainFX::`vftable;
}

// File Line: 51
// RVA: 0xAF64F0
void __fastcall CAkGainFX::~CAkGainFX(CAkGainFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 61
// RVA: 0xAF6510
__int64 __fastcall CAkGainFX::Init(
        CAkGainFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkGainFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  unsigned int v7; // r8d
  int i; // edx
  float v9; // xmm0_4
  __int64 result; // rax

  v7 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  this->m_uNumProcessedChannels = v7;
  this->m_uSampleRate = in_rFormat->uSampleRate;
  this->m_pSharedParams = in_pParams;
  this->m_fCurrentFullBandGain = powf(10.0, in_pParams->m_Params.fFullbandGain * 0.050000001);
  v9 = powf(10.0, in_pParams->m_Params.fLFEGain * 0.050000001);
  result = 1i64;
  this->m_fCurrentLFEGain = v9;
  return result;
}

// File Line: 80
// RVA: 0xAF65B0
__int64 __fastcall CAkGainFX::Term(CAkGainFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 88
// RVA: 0xAF65F0
__int64 __fastcall CAkGainFX::Reset(CAkGainFX *this)
{
  return 1i64;
}

// File Line: 94
// RVA: 0xAF6600
__int64 __fastcall CAkGainFX::GetPluginInfo(CAkGainFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 144
// RVA: 0xAF6620
void __fastcall CAkGainFX::Execute(CAkGainFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkGainFXParams *m_pSharedParams; // rbx
  float v5; // xmm8_4
  float v6; // xmm6_4
  unsigned int uChannelMask; // ecx
  float m_fCurrentLFEGain; // xmm1_4
  int i; // edx
  float *v10; // rcx

  if ( this->m_uNumProcessedChannels && io_pBuffer->uValidFrames )
  {
    m_pSharedParams = this->m_pSharedParams;
    v5 = powf(10.0, m_pSharedParams->m_Params.fFullbandGain * 0.050000001);
    v6 = powf(10.0, m_pSharedParams->m_Params.fLFEGain * 0.050000001);
    AK::DSP::ApplyGain_9(io_pBuffer, this->m_fCurrentFullBandGain, v5, 0);
    uChannelMask = io_pBuffer->uChannelMask;
    m_fCurrentLFEGain = this->m_fCurrentLFEGain;
    if ( (uChannelMask & 8) != 0 )
    {
      for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
        ++i;
      v10 = (float *)((char *)io_pBuffer->pData + 4 * io_pBuffer->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1));
      if ( v6 == m_fCurrentLFEGain )
        AK::DSP::ApplyGain_8(v10, m_fCurrentLFEGain, io_pBuffer->uValidFrames);
      else
        AK::DSP::ApplyGainRamp_3(v10, m_fCurrentLFEGain, v6, io_pBuffer->uValidFrames);
    }
    this->m_fCurrentFullBandGain = v5;
    this->m_fCurrentLFEGain = v6;
  }
}

