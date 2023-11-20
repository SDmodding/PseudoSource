// File Line: 38
// RVA: 0xAF64A0
AK::IAkPlugin *__fastcall CreateGainFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32ui64);
  if ( result )
    result->vfptr = (AK::IAkPluginVtbl *)&CAkGainFX::`vftable';
  return result;
}

// File Line: 46
// RVA: 0xAF64D0
void __fastcall CAkGainFX::CAkGainFX(CAkGainFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkGainFX::`vftable';
}

// File Line: 51
// RVA: 0xAF64F0
void __fastcall CAkGainFX::~CAkGainFX(CAkGainFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 61
// RVA: 0xAF6510
signed __int64 __fastcall CAkGainFX::Init(CAkGainFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkGainFX *v5; // rbx
  AK::IAkPluginParam *v6; // rdi
  unsigned int v7; // er8
  int i; // edx
  float v9; // xmm0_4
  signed __int64 result; // rax

  v5 = this;
  v6 = in_pParams;
  v7 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  this->m_uNumProcessedChannels = v7;
  this->m_uSampleRate = in_rFormat->uSampleRate;
  this->m_pSharedParams = (CAkGainFXParams *)in_pParams;
  this->m_fCurrentFullBandGain = powf(10.0, *(float *)&in_pParams[1].vfptr * 0.050000001);
  v9 = powf(10.0, *((float *)&v6[1].vfptr + 1) * 0.050000001);
  result = 1i64;
  v5->m_fCurrentLFEGain = v9;
  return result;
}

// File Line: 80
// RVA: 0xAF65B0
signed __int64 __fastcall CAkGainFX::Term(CAkGainFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkGainFX *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkPlugin *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 88
// RVA: 0xAF65F0
signed __int64 __fastcall CAkGainFX::Reset(CAkGainFX *this)
{
  return 1i64;
}

// File Line: 94
// RVA: 0xAF6600
signed __int64 __fastcall CAkGainFX::GetPluginInfo(CAkGainFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 144
// RVA: 0xAF6620
void __fastcall CAkGainFX::Execute(CAkGainFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rsi
  CAkGainFX *v3; // rdi
  CAkGainFXParams *v4; // rbx
  float v5; // xmm8_4
  float v6; // xmm6_4
  unsigned int v7; // ecx
  float v8; // xmm1_4
  int i; // edx
  float *v10; // rcx

  v2 = io_pBuffer;
  v3 = this;
  if ( this->m_uNumProcessedChannels && io_pBuffer->uValidFrames )
  {
    v4 = this->m_pSharedParams;
    v5 = powf(10.0, v4->m_Params.fFullbandGain * 0.050000001);
    v6 = powf(10.0, v4->m_Params.fLFEGain * 0.050000001);
    AK::DSP::ApplyGain_9(v2, v3->m_fCurrentFullBandGain, v5, 0);
    v7 = v2->uChannelMask;
    v8 = v3->m_fCurrentLFEGain;
    if ( v7 & 8 )
    {
      for ( i = 0; v7; v7 &= v7 - 1 )
        ++i;
      v10 = (float *)((char *)v2->pData + 4 * v2->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1));
      if ( v6 == v8 )
        AK::DSP::ApplyGain_8(v10, v8, v2->uValidFrames);
      else
        AK::DSP::ApplyGainRamp_3(v10, v8, v6, v2->uValidFrames);
    }
    v3->m_fCurrentFullBandGain = v5;
    v3->m_fCurrentLFEGain = v6;
  }
}

