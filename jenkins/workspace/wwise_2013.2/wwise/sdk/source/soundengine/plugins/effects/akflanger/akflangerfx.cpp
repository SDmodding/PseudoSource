// File Line: 29
// RVA: 0xAF9870
AK::IAkPlugin *__fastcall CreateFlangerFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 192i64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkPluginVtbl *)&CAkFlangerFX::`vftable;
  result[1].vfptr = 0i64;
  result[2].vfptr = 0i64;
  result[3].vfptr = 0i64;
  result[4].vfptr = 0i64;
  result[5].vfptr = 0i64;
  LODWORD(result[22].vfptr) = -1;
  HIDWORD(result[22].vfptr) = 0;
  result[6].vfptr = 0i64;
  result[7].vfptr = 0i64;
  result[8].vfptr = 0i64;
  result[9].vfptr = 0i64;
  result[10].vfptr = 0i64;
  result[11].vfptr = 0i64;
  result[12].vfptr = 0i64;
  result[13].vfptr = 0i64;
  result[14].vfptr = 0i64;
  result[15].vfptr = 0i64;
  result[16].vfptr = 0i64;
  result[17].vfptr = 0i64;
  result[18].vfptr = 0i64;
  result[19].vfptr = 0i64;
  result[20].vfptr = 0i64;
  result[21].vfptr = 0i64;
  return result;
}

// File Line: 40
// RVA: 0xAF9970
void __fastcall CAkFlangerFX::CAkFlangerFX(CAkFlangerFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkFlangerFX::`vftable;
  this->m_pUniCombs = 0i64;
  this->m_pLFO = 0i64;
  this->m_pSharedParams = 0i64;
  this->m_pAllocator = 0i64;
  this->m_pFXCtx = 0i64;
  this->m_FXInfo.FXTailHandler.uTotalTailFrames = 0;
  this->m_FXInfo.FXTailHandler.uTailFramesRemaining = -1;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.fDryLevel = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.fFbackLevel = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode = 0i64;
  *(_QWORD *)&this->m_FXInfo.Params.RTPC.fWetDryMix = 0i64;
  this->m_FXInfo.Params.NonRTPC = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.fDryLevel = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.fFbackLevel = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = 0i64;
  *(_QWORD *)&this->m_FXInfo.PrevParams.RTPC.fWetDryMix = 0i64;
  this->m_FXInfo.PrevParams.NonRTPC = 0i64;
}

// File Line: 47
// RVA: 0xAF9A00
void __fastcall CAkFlangerFX::~CAkFlangerFX(CAkFlangerFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 65
// RVA: 0xAF9A20
int __fastcall CAkFlangerFX::Init(
        CAkFlangerFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkFlangerFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  unsigned int v8; // edx
  float fDryLevel; // eax
  int v10; // edi
  int i; // ecx
  unsigned int uSampleRate; // eax
  int result; // eax
  AKRESULT inited; // eax
  int v15; // ecx

  this->m_pSharedParams = in_pParams;
  this->m_FXInfo.Params.RTPC.fDryLevel = in_pParams->m_Params.RTPC.fDryLevel;
  this->m_FXInfo.Params.RTPC.fFfwdLevel = in_pParams->m_Params.RTPC.fFfwdLevel;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.fFbackLevel = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.fFbackLevel;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = in_pParams->m_Params.RTPC.modParams.lfoParams.eWaveform;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = in_pParams->m_Params.RTPC.modParams.lfoParams.fFrequency;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.modParams.lfoParams.fSmooth;
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset = in_pParams->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = in_pParams->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
  *(AK::IAkPluginParam *)&this->m_FXInfo.Params.RTPC.fWetDryMix = *(AK::IAkPluginParam *)&in_pParams->m_Params.RTPC.fWetDryMix;
  this->m_FXInfo.Params.NonRTPC = in_pParams->m_Params.NonRTPC;
  CAkFlangerFXParams::SetDirty(in_pParams, 0);
  v8 = 0;
  if ( !this->m_FXInfo.Params.NonRTPC.bEnableLFO )
    this->m_FXInfo.Params.RTPC.fModDepth = 0.0;
  fDryLevel = this->m_FXInfo.Params.RTPC.fDryLevel;
  this->m_pFXCtx = in_pFXCtx;
  this->m_FXInfo.PrevParams.RTPC.fDryLevel = fDryLevel;
  this->m_FXInfo.PrevParams.RTPC.fFfwdLevel = this->m_FXInfo.Params.RTPC.fFfwdLevel;
  this->m_FXInfo.PrevParams.RTPC.fFbackLevel = this->m_FXInfo.Params.RTPC.fFbackLevel;
  this->m_FXInfo.PrevParams.RTPC.fModDepth = this->m_FXInfo.Params.RTPC.fModDepth;
  this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
  this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
  this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
  this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
  this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
  this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
  this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
  this->m_FXInfo.PrevParams.RTPC.fOutputLevel = this->m_FXInfo.Params.RTPC.fOutputLevel;
  this->m_FXInfo.PrevParams.RTPC.fWetDryMix = this->m_FXInfo.Params.RTPC.fWetDryMix;
  *(_DWORD *)&this->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&this->m_FXInfo.Params.RTPC.bHasChanged;
  this->m_FXInfo.PrevParams.NonRTPC.fDelayTime = this->m_FXInfo.Params.NonRTPC.fDelayTime;
  *(_DWORD *)&this->m_FXInfo.PrevParams.NonRTPC.bEnableLFO = *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bEnableLFO;
  v10 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    v10 = *((_DWORD *)in_rFormat + 1) & 0x3FFF7;
  if ( (v10 & 7) == 7 && !this->m_FXInfo.Params.NonRTPC.bProcessCenter )
    v10 &= ~4u;
  for ( i = v10; i; i &= i - 1 )
    ++v8;
  this->m_FXInfo.uNumProcessedChannels = v8;
  uSampleRate = in_rFormat->uSampleRate;
  this->m_pAllocator = in_pAllocator;
  this->m_FXInfo.uSampleRate = uSampleRate;
  result = CAkFlangerFX::InitUniCombs(this, v10);
  if ( result == 1 )
  {
    inited = CAkFlangerFX::InitLFO(this, v10);
    v15 = 1;
    if ( inited != AK_Success )
      return inited;
    return v15;
  }
  return result;
}

// File Line: 91
// RVA: 0xAFA1F0
__int64 __fastcall CAkFlangerFX::AdjustEffectiveChannelMask(CAkFlangerFX *this, unsigned int in_uChannelMask)
{
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    in_uChannelMask &= ~8u;
  if ( (in_uChannelMask & 7) == 7 && !this->m_FXInfo.Params.NonRTPC.bProcessCenter )
    in_uChannelMask &= ~4u;
  return in_uChannelMask;
}

// File Line: 102
// RVA: 0xAFA220
AKRESULT __fastcall CAkFlangerFX::InitUniCombs(CAkFlangerFX *this, unsigned int in_uChannelMask)
{
  int v2; // ebx
  unsigned int v4; // esi
  DSP::UniComb *v5; // rax
  __int64 v6; // rdx
  AKRESULT result; // eax
  unsigned int v8; // r10d
  __int64 v9; // r8
  unsigned int v10; // eax
  __int64 v11; // r9
  char *v12; // rcx
  char *v13; // rcx
  char *v14; // rcx
  char *v15; // rcx
  char *v16; // rcx
  unsigned int v17; // ebp
  unsigned __int16 v18; // ax

  v2 = 0;
  v4 = 0;
  if ( !in_uChannelMask )
    return 1;
  do
  {
    ++v4;
    in_uChannelMask &= in_uChannelMask - 1;
  }
  while ( in_uChannelMask );
  if ( !v4 )
    return 1;
  v5 = (DSP::UniComb *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 56i64 * v4);
  this->m_pUniCombs = v5;
  if ( !v5 )
    return 52;
  v8 = 0;
  v9 = 0i64;
  if ( (int)v4 >= 4 )
  {
    v6 = 0i64;
    v10 = ((v4 - 4) >> 2) + 1;
    v11 = v10;
    v8 = 4 * v10;
    v9 = 4i64 * v10;
    do
    {
      v12 = (char *)this->m_pUniCombs + v6;
      if ( v12 )
      {
        *(_QWORD *)v12 = 0i64;
        *((_DWORD *)v12 + 2) = 0;
        *((_QWORD *)v12 + 2) = 0i64;
        *((_QWORD *)v12 + 3) = 0i64;
        *((_QWORD *)v12 + 4) = 0i64;
        *((_QWORD *)v12 + 5) = 0i64;
        *((_DWORD *)v12 + 12) = 0;
      }
      v13 = (char *)&this->m_pUniCombs[1] + v6;
      if ( v13 )
      {
        *(_QWORD *)v13 = 0i64;
        *((_DWORD *)v13 + 2) = 0;
        *((_QWORD *)v13 + 2) = 0i64;
        *((_QWORD *)v13 + 3) = 0i64;
        *((_QWORD *)v13 + 4) = 0i64;
        *((_QWORD *)v13 + 5) = 0i64;
        *((_DWORD *)v13 + 12) = 0;
      }
      v14 = (char *)&this->m_pUniCombs[2] + v6;
      if ( v14 )
      {
        *(_QWORD *)v14 = 0i64;
        *((_DWORD *)v14 + 2) = 0;
        *((_QWORD *)v14 + 2) = 0i64;
        *((_QWORD *)v14 + 3) = 0i64;
        *((_QWORD *)v14 + 4) = 0i64;
        *((_QWORD *)v14 + 5) = 0i64;
        *((_DWORD *)v14 + 12) = 0;
      }
      v15 = (char *)&this->m_pUniCombs[3] + v6;
      if ( v15 )
      {
        *(_QWORD *)v15 = 0i64;
        *((_DWORD *)v15 + 2) = 0;
        *((_QWORD *)v15 + 2) = 0i64;
        *((_QWORD *)v15 + 3) = 0i64;
        *((_QWORD *)v15 + 4) = 0i64;
        *((_QWORD *)v15 + 5) = 0i64;
        *((_DWORD *)v15 + 12) = 0;
      }
      v6 += 224i64;
      --v11;
    }
    while ( v11 );
  }
  if ( v8 < v4 )
  {
    v9 *= 56i64;
    v6 = v4 - v8;
    do
    {
      v16 = (char *)this->m_pUniCombs + v9;
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *((_DWORD *)v16 + 2) = 0;
        *((_QWORD *)v16 + 2) = 0i64;
        *((_QWORD *)v16 + 3) = 0i64;
        *((_QWORD *)v16 + 4) = 0i64;
        *((_QWORD *)v16 + 5) = 0i64;
        *((_DWORD *)v16 + 12) = 0;
      }
      v9 += 56i64;
      --v6;
    }
    while ( v6 );
  }
  v17 = (int)(float)((float)(this->m_FXInfo.Params.NonRTPC.fDelayTime * 0.001) * (float)(int)this->m_FXInfo.uSampleRate);
  while ( 1 )
  {
    v18 = (*(__int64 (__fastcall **)(AK::IAkEffectPluginContext *, __int64, __int64))&this->m_pFXCtx->vfptr->gap8[8])(
            this->m_pFXCtx,
            v6,
            v9);
    result = DSP::UniComb::Init(
               &this->m_pUniCombs[v2],
               this->m_pAllocator,
               v17,
               v18,
               this->m_FXInfo.Params.RTPC.fFbackLevel,
               this->m_FXInfo.Params.RTPC.fFfwdLevel,
               this->m_FXInfo.Params.RTPC.fDryLevel,
               this->m_FXInfo.Params.RTPC.fModDepth);
    if ( result != AK_Success )
      break;
    if ( ++v2 >= v4 )
      return 1;
  }
  return result;
}

// File Line: 136
// RVA: 0xAFA430
__int64 __fastcall CAkFlangerFX::InitLFO(CAkFlangerFX *this, unsigned int in_uChannelMask)
{
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v4; // rbx
  unsigned int v5; // r8d
  int v6; // r9d
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v7; // rax
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v8; // rax

  if ( this->m_FXInfo.Params.NonRTPC.bEnableLFO )
  {
    v4 = 0i64;
    v5 = in_uChannelMask;
    v6 = 0;
    if ( in_uChannelMask )
    {
      do
      {
        ++v6;
        v5 &= v5 - 1;
      }
      while ( v5 );
      if ( v6 )
      {
        v7 = (DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *)this->m_pAllocator->vfptr->Malloc(
                                                                         this->m_pAllocator,
                                                                         196i64);
        if ( v7 )
        {
          DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>(v7);
          v4 = v8;
        }
        this->m_pLFO = v4;
        if ( !v4 )
          return 52i64;
        DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
          v4,
          in_uChannelMask,
          this->m_FXInfo.uSampleRate,
          &this->m_FXInfo.Params.RTPC.modParams);
      }
    }
  }
  return 1i64;
}

// File Line: 155
// RVA: 0xAF9BD0
__int64 __fastcall CAkFlangerFX::Term(CAkFlangerFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int i; // edi

  if ( this->m_pUniCombs )
  {
    for ( i = 0; i < this->m_FXInfo.uNumProcessedChannels; ++i )
      DSP::UniComb::Term(&this->m_pUniCombs[i], this->m_pAllocator);
    this->m_pAllocator->vfptr->Free(this->m_pAllocator, this->m_pUniCombs);
    this->m_pUniCombs = 0i64;
  }
  if ( this->m_pLFO )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pLFO = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 164
// RVA: 0xAFA4E0
void __fastcall CAkFlangerFX::TermUniCombs(CAkFlangerFX *this)
{
  unsigned int i; // edi

  if ( this->m_pUniCombs )
  {
    for ( i = 0; i < this->m_FXInfo.uNumProcessedChannels; ++i )
      DSP::UniComb::Term(&this->m_pUniCombs[i], this->m_pAllocator);
    this->m_pAllocator->vfptr->Free(this->m_pAllocator, this->m_pUniCombs);
    this->m_pUniCombs = 0i64;
  }
}

// File Line: 176
// RVA: 0xAFA550
void __fastcall CAkFlangerFX::TermLFO(CAkFlangerFX *this)
{
  if ( this->m_pLFO )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pLFO = 0i64;
  }
}

// File Line: 186
// RVA: 0xAF9CE0
__int64 __fastcall CAkFlangerFX::GetPluginInfo(CAkFlangerFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 199
// RVA: 0xAFA5D0
unsigned int __fastcall CAkFlangerFX::LiveParametersUpdate(CAkFlangerFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int uChannelMask; // ebp
  __int64 v4; // rsi
  unsigned int v5; // ecx
  unsigned int i; // edi
  bool v7; // r14
  unsigned int result; // eax
  __int64 v9; // rbp

  uChannelMask = io_pBuffer->uChannelMask;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    uChannelMask &= ~8u;
  if ( (uChannelMask & 7) == 7 && !this->m_FXInfo.Params.NonRTPC.bProcessCenter )
    uChannelMask &= ~4u;
  v4 = 0i64;
  v5 = uChannelMask;
  for ( i = 0; v5; v5 &= v5 - 1 )
    ++i;
  v7 = i != this->m_FXInfo.uNumProcessedChannels;
  if ( this->m_FXInfo.PrevParams.NonRTPC.bEnableLFO == this->m_FXInfo.Params.NonRTPC.bEnableLFO
    && i == this->m_FXInfo.uNumProcessedChannels )
  {
    goto LABEL_14;
  }
  if ( this->m_pLFO )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pLFO = 0i64;
  }
  result = CAkFlangerFX::InitLFO(this, uChannelMask);
  if ( result == 1 )
  {
LABEL_14:
    if ( this->m_FXInfo.Params.NonRTPC.fDelayTime != this->m_FXInfo.PrevParams.NonRTPC.fDelayTime || v7 )
    {
      CAkFlangerFX::TermUniCombs(this);
      result = CAkFlangerFX::InitUniCombs(this, uChannelMask);
      if ( result != 1 )
        return result;
      if ( this->m_pUniCombs && i )
      {
        v9 = i;
        do
        {
          DSP::UniComb::Reset(&this->m_pUniCombs[v4++]);
          --v9;
        }
        while ( v9 );
      }
    }
    this->m_FXInfo.uNumProcessedChannels = i;
    return 1;
  }
  return result;
}

// File Line: 227
// RVA: 0xAFA6F0
void __fastcall CAkFlangerFX::RTPCParametersUpdate(CAkFlangerFX *this)
{
  __int64 v1; // rsi
  unsigned int i; // ebx
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *m_pLFO; // rbx
  int uSampleRate; // ebp
  float fSmooth; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  __int64 v12; // rcx
  float v13; // xmm0_4
  DSP::LFO::Waveform eWaveform; // eax
  DSP::LFO::Waveform v15; // edx
  float v16; // xmm0_4
  float out_fA1; // [rsp+70h] [rbp+8h] BYREF
  float out_fB0; // [rsp+78h] [rbp+10h] BYREF

  v1 = 0i64;
  for ( i = 0; i < this->m_FXInfo.uNumProcessedChannels; ++i )
    DSP::UniComb::SetParams(
      &this->m_pUniCombs[i],
      this->m_FXInfo.Params.RTPC.fFbackLevel,
      this->m_FXInfo.Params.RTPC.fFfwdLevel,
      this->m_FXInfo.Params.RTPC.fDryLevel,
      this->m_FXInfo.Params.RTPC.fModDepth);
  m_pLFO = this->m_pLFO;
  if ( m_pLFO && this->m_FXInfo.Params.NonRTPC.bEnableLFO )
  {
    uSampleRate = this->m_FXInfo.uSampleRate;
    fSmooth = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
    if ( fSmooth == 0.0 )
    {
      DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_NONE, 0.0, 0, &out_fB0, &out_fA1);
    }
    else
    {
      v7 = (float)uSampleRate * 0.5;
      v8 = logf(v7 / this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency);
      v9 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * fSmooth) ^ _xmm[0]));
      DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_LOWPASS, v9 * v7, uSampleRate, &out_fB0, &out_fA1);
    }
    if ( m_pLFO->m_uNumChannels )
    {
      v10 = out_fA1;
      v11 = out_fB0;
      while ( 1 )
      {
        v12 = v1;
        v13 = (float)(1.0 / (float)uSampleRate) * this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
        m_pLFO->m_arLfo[v1].m_state.fPhaseDelta = v13;
        if ( this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform == WAVEFORM_SINE )
          m_pLFO->m_arLfo[v1].m_state.fPhaseDelta = v13 * 6.2831855;
        m_pLFO->m_arLfo[v1].m_state.filter.fB0 = v11;
        m_pLFO->m_arLfo[v1].m_state.filter.fA1 = v10;
        eWaveform = m_pLFO->m_arLfo[v1].m_state.eWaveform;
        v15 = this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
        if ( eWaveform == v15 )
          goto LABEL_18;
        if ( eWaveform == WAVEFORM_SINE )
          break;
        if ( v15 == WAVEFORM_SINE )
        {
          v16 = m_pLFO->m_arLfo[v1].m_state.fPhase * 6.2831855;
          goto LABEL_17;
        }
LABEL_18:
        v1 = (unsigned int)(v1 + 1);
        m_pLFO->m_arLfo[v12].m_state.eWaveform = this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
        if ( (unsigned int)v1 >= m_pLFO->m_uNumChannels )
          return;
      }
      v16 = m_pLFO->m_arLfo[v1].m_state.fPhase * 0.15915494;
LABEL_17:
      m_pLFO->m_arLfo[v1].m_state.fPhase = v16;
      goto LABEL_18;
    }
  }
}

// File Line: 251
// RVA: 0xAF9D00
void __fastcall CAkFlangerFX::Execute(CAkFlangerFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkFlangerFXParams *m_pSharedParams; // rcx
  AkAudioBuffer *v4; // rbx
  __int64 v5; // r14
  unsigned __int16 uValidFrames; // ax
  unsigned int uChannelMask; // edx
  __int64 v8; // r13
  unsigned int v9; // ecx
  unsigned int i; // ebp
  bool v11; // r12
  void *v12; // r15
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  float v16; // xmm12_4
  unsigned int v17; // esi
  float *v18; // r15
  float in_fPWM; // xmm9_4
  float fModDepth; // xmm10_4
  float in_fPrevAmp; // xmm11_4
  char *v22; // rbx
  double v23; // xmm3_8
  double v24; // xmm2_8
  float v25; // xmm1_4
  unsigned int j; // esi
  char *v27; // rbx
  double v28; // xmm3_8
  double v29; // xmm2_8
  float v30; // xmm1_4
  FlangerOutputPolicy in_rParams; // [rsp+F0h] [rbp+8h] BYREF
  AkAudioBuffer *v32; // [rsp+F8h] [rbp+10h]
  void *Dst; // [rsp+100h] [rbp+18h]

  v32 = io_pBuffer;
  m_pSharedParams = this->m_pSharedParams;
  v4 = io_pBuffer;
  this->m_FXInfo.Params = m_pSharedParams->m_Params;
  CAkFlangerFXParams::SetDirty(m_pSharedParams, 0);
  v5 = 0i64;
  if ( !this->m_FXInfo.Params.NonRTPC.bEnableLFO )
    this->m_FXInfo.Params.RTPC.fModDepth = 0.0;
  if ( this->m_FXInfo.Params.NonRTPC.bHasChanged )
  {
    if ( CAkFlangerFX::LiveParametersUpdate(this, v4) != AK_Success )
      return;
    this->m_FXInfo.Params.NonRTPC.bHasChanged = 0;
  }
  if ( this->m_FXInfo.Params.RTPC.bHasChanged )
  {
    CAkFlangerFX::RTPCParametersUpdate(this);
    this->m_FXInfo.Params.RTPC.bHasChanged = 0;
  }
  if ( this->m_FXInfo.uNumProcessedChannels )
  {
    AkFXTailHandler::HandleTail(
      &this->m_FXInfo.FXTailHandler,
      v4,
      (int)(float)((float)(this->m_FXInfo.Params.NonRTPC.fDelayTime * 0.001) * (float)(int)this->m_FXInfo.uSampleRate));
    uValidFrames = v4->uValidFrames;
    if ( uValidFrames )
    {
      uChannelMask = v4->uChannelMask;
      v8 = uValidFrames;
      if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
        uChannelMask &= ~8u;
      v9 = uChannelMask;
      for ( i = 0; v9; v9 &= v9 - 1 )
        ++i;
      v11 = !this->m_FXInfo.Params.NonRTPC.bProcessCenter && (uChannelMask & 7) == 7;
      v12 = this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 4i64 * v4->uMaxFrames);
      Dst = v12;
      if ( v12 )
      {
        v13 = (float)(100.0 - this->m_FXInfo.Params.RTPC.fWetDryMix) * 0.0099999998;
        v14 = (float)(100.0 - this->m_FXInfo.PrevParams.RTPC.fWetDryMix) * 0.0099999998;
        v15 = 1.0 - v13;
        v16 = 1.0 - v14;
        if ( this->m_FXInfo.Params.NonRTPC.bEnableLFO )
        {
          v17 = 0;
          v18 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 4 * v8);
          in_fPWM = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
          fModDepth = this->m_FXInfo.Params.RTPC.fModDepth;
          for ( in_fPrevAmp = this->m_FXInfo.PrevParams.RTPC.fModDepth; v17 < i; ++v17 )
          {
            if ( !v11 || v17 != 2 )
            {
              if ( v18 )
                DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::ProduceBuffer(
                  &this->m_pLFO->m_arLfo[v5],
                  v18,
                  v8,
                  fModDepth,
                  in_fPrevAmp,
                  in_fPWM,
                  &in_rParams);
              v22 = (char *)v4->pData + 4 * v17 * (unsigned __int64)v4->uMaxFrames;
              memmove(Dst, v22, (unsigned int)(4 * v8));
              DSP::UniComb::ProcessBuffer(&this->m_pUniCombs[(unsigned int)v5], (float *)v22, v8, v18);
              *(_QWORD *)&v23 = LODWORD(this->m_FXInfo.Params.RTPC.fOutputLevel);
              *(_QWORD *)&v24 = LODWORD(this->m_FXInfo.PrevParams.RTPC.fOutputLevel);
              v25 = *(float *)&v23;
              *(float *)&v23 = *(float *)&v23 * v15;
              *(float *)&v24 = *(float *)&v24 * v16;
              v5 = (unsigned int)(v5 + 1);
              DSP::Mix2Interp(
                (float *)v22,
                (float *)Dst,
                v24,
                v23,
                this->m_FXInfo.PrevParams.RTPC.fOutputLevel * v14,
                v25 * v13,
                v8);
              v4 = v32;
            }
          }
          if ( v18 )
            this->m_pAllocator->vfptr->Free(this->m_pAllocator, v18);
          v12 = Dst;
        }
        else
        {
          for ( j = 0; j < i; ++j )
          {
            if ( !v11 || j != 2 )
            {
              v27 = (char *)v4->pData + 4 * j * (unsigned __int64)v4->uMaxFrames;
              memmove(v12, v27, (unsigned int)(4 * v8));
              DSP::UniComb::ProcessBuffer(&this->m_pUniCombs[(unsigned int)v5], (float *)v27, v8, 0i64);
              *(_QWORD *)&v28 = LODWORD(this->m_FXInfo.Params.RTPC.fOutputLevel);
              *(_QWORD *)&v29 = LODWORD(this->m_FXInfo.PrevParams.RTPC.fOutputLevel);
              LODWORD(v5) = v5 + 1;
              v30 = *(float *)&v28;
              *(float *)&v28 = *(float *)&v28 * v15;
              *(float *)&v29 = *(float *)&v29 * v16;
              DSP::Mix2Interp(
                (float *)v27,
                (float *)v12,
                v29,
                v28,
                this->m_FXInfo.PrevParams.RTPC.fOutputLevel * v14,
                v30 * v13,
                v8);
              v4 = v32;
            }
          }
        }
        this->m_pAllocator->vfptr->Free(this->m_pAllocator, v12);
        this->m_FXInfo.PrevParams.RTPC.fDryLevel = this->m_FXInfo.Params.RTPC.fDryLevel;
        this->m_FXInfo.PrevParams.RTPC.fFfwdLevel = this->m_FXInfo.Params.RTPC.fFfwdLevel;
        this->m_FXInfo.PrevParams.RTPC.fFbackLevel = this->m_FXInfo.Params.RTPC.fFbackLevel;
        this->m_FXInfo.PrevParams.RTPC.fModDepth = this->m_FXInfo.Params.RTPC.fModDepth;
        this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
        this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
        this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
        this->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
        this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
        this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
        this->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
        this->m_FXInfo.PrevParams.RTPC.fOutputLevel = this->m_FXInfo.Params.RTPC.fOutputLevel;
        this->m_FXInfo.PrevParams.RTPC.fWetDryMix = this->m_FXInfo.Params.RTPC.fWetDryMix;
        *(_DWORD *)&this->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&this->m_FXInfo.Params.RTPC.bHasChanged;
        this->m_FXInfo.PrevParams.NonRTPC.fDelayTime = this->m_FXInfo.Params.NonRTPC.fDelayTime;
        *(_DWORD *)&this->m_FXInfo.PrevParams.NonRTPC.bEnableLFO = *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bEnableLFO;
      }
    }
  }
}

// File Line: 423
// RVA: 0xAF9C80
__int64 __fastcall CAkFlangerFX::Reset(CAkFlangerFX *this)
{
  unsigned int uNumProcessedChannels; // eax
  __int64 v3; // rdi
  __int64 v4; // rbx

  uNumProcessedChannels = this->m_FXInfo.uNumProcessedChannels;
  if ( this->m_pUniCombs && uNumProcessedChannels )
  {
    v3 = uNumProcessedChannels;
    v4 = 0i64;
    do
    {
      DSP::UniComb::Reset(&this->m_pUniCombs[v4++]);
      --v3;
    }
    while ( v3 );
  }
  return 1i64;
}

// File Line: 429
// RVA: 0xAFA580
void __fastcall CAkFlangerFX::ResetUniCombs(CAkFlangerFX *this, unsigned int in_uNumProcessedChannels)
{
  __int64 v3; // rdi
  __int64 v4; // rbx

  if ( this->m_pUniCombs && in_uNumProcessedChannels )
  {
    v3 = in_uNumProcessedChannels;
    v4 = 0i64;
    do
    {
      DSP::UniComb::Reset(&this->m_pUniCombs[v4++]);
      --v3;
    }
    while ( v3 );
  }
}

