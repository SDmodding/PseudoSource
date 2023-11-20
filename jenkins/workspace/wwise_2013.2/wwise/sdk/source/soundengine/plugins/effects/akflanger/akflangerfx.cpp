// File Line: 29
// RVA: 0xAF9870
AK::IAkPlugin *__fastcall CreateFlangerFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 192ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkPluginVtbl *)&CAkFlangerFX::`vftable';
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
  this->vfptr = (AK::IAkPluginVtbl *)&CAkFlangerFX::`vftable';
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
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 65
// RVA: 0xAF9A20
AKRESULT __fastcall CAkFlangerFX::Init(CAkFlangerFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AK::IAkPluginMemAlloc *v5; // rsi
  CAkFlangerFX *v6; // rbx
  AK::IAkEffectPluginContext *v7; // rdi
  unsigned int v8; // edx
  float v9; // eax
  int v10; // edi
  int i; // ecx
  unsigned int v12; // eax
  AKRESULT result; // eax
  AKRESULT v14; // eax
  AKRESULT v15; // ecx

  this->m_pSharedParams = (CAkFlangerFXParams *)in_pParams;
  v5 = in_pAllocator;
  this->m_FXInfo.Params.RTPC.fDryLevel = *(float *)&in_pParams[1].vfptr;
  v6 = this;
  this->m_FXInfo.Params.RTPC.fFfwdLevel = *((float *)&in_pParams[1].vfptr + 1);
  this->m_FXInfo.Params.RTPC.fFbackLevel = *(float *)&in_pParams[2].vfptr;
  v7 = in_pFXCtx;
  this->m_FXInfo.Params.RTPC.fModDepth = *((float *)&in_pParams[2].vfptr + 1);
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = (DSP::LFO::Waveform)in_pParams[3].vfptr;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = *((float *)&in_pParams[3].vfptr + 1);
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth = *(float *)&in_pParams[4].vfptr;
  this->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM = *((float *)&in_pParams[4].vfptr + 1);
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset = *(float *)&in_pParams[5].vfptr;
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = *((float *)&in_pParams[5].vfptr + 1);
  this->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode = (DSP::LFO::MultiChannel::PhaseMode)in_pParams[6].vfptr;
  this->m_FXInfo.Params.RTPC.fOutputLevel = *((float *)&in_pParams[6].vfptr + 1);
  this->m_FXInfo.Params.RTPC.fWetDryMix = *(float *)&in_pParams[7].vfptr;
  *(_DWORD *)&this->m_FXInfo.Params.RTPC.bHasChanged = HIDWORD(in_pParams[7].vfptr);
  this->m_FXInfo.Params.NonRTPC.fDelayTime = *(float *)&in_pParams[8].vfptr;
  *(_DWORD *)&this->m_FXInfo.Params.NonRTPC.bEnableLFO = HIDWORD(in_pParams[8].vfptr);
  CAkFlangerFXParams::SetDirty((CAkFlangerFXParams *)in_pParams, 0);
  v8 = 0;
  if ( !v6->m_FXInfo.Params.NonRTPC.bEnableLFO )
    v6->m_FXInfo.Params.RTPC.fModDepth = 0.0;
  v9 = v6->m_FXInfo.Params.RTPC.fDryLevel;
  v6->m_pFXCtx = v7;
  v6->m_FXInfo.PrevParams.RTPC.fDryLevel = v9;
  v6->m_FXInfo.PrevParams.RTPC.fFfwdLevel = v6->m_FXInfo.Params.RTPC.fFfwdLevel;
  v6->m_FXInfo.PrevParams.RTPC.fFbackLevel = v6->m_FXInfo.Params.RTPC.fFbackLevel;
  v6->m_FXInfo.PrevParams.RTPC.fModDepth = v6->m_FXInfo.Params.RTPC.fModDepth;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
  v6->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = v6->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
  v6->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = v6->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
  v6->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = v6->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
  v6->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = v6->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
  v6->m_FXInfo.PrevParams.RTPC.fOutputLevel = v6->m_FXInfo.Params.RTPC.fOutputLevel;
  v6->m_FXInfo.PrevParams.RTPC.fWetDryMix = v6->m_FXInfo.Params.RTPC.fWetDryMix;
  *(_DWORD *)&v6->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&v6->m_FXInfo.Params.RTPC.bHasChanged;
  v6->m_FXInfo.PrevParams.NonRTPC.fDelayTime = v6->m_FXInfo.Params.NonRTPC.fDelayTime;
  *(_DWORD *)&v6->m_FXInfo.PrevParams.NonRTPC.bEnableLFO = *(_DWORD *)&v6->m_FXInfo.Params.NonRTPC.bEnableLFO;
  v10 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  if ( !v6->m_FXInfo.Params.NonRTPC.bProcessLFE )
    v10 = *((_DWORD *)in_rFormat + 1) & 0x3FFF7;
  if ( (v10 & 7) == 7 && !v6->m_FXInfo.Params.NonRTPC.bProcessCenter )
    v10 &= 0xFFFFFFFB;
  for ( i = v10; i; i &= i - 1 )
    ++v8;
  v6->m_FXInfo.uNumProcessedChannels = v8;
  v12 = in_rFormat->uSampleRate;
  v6->m_pAllocator = v5;
  v6->m_FXInfo.uSampleRate = v12;
  result = CAkFlangerFX::InitUniCombs(v6, v10);
  if ( result == 1 )
  {
    v14 = CAkFlangerFX::InitLFO(v6, v10);
    v15 = 1;
    if ( v14 != 1 )
      v15 = v14;
    result = v15;
  }
  return result;
}

// File Line: 91
// RVA: 0xAFA1F0
__int64 __fastcall CAkFlangerFX::AdjustEffectiveChannelMask(CAkFlangerFX *this, unsigned int in_uChannelMask)
{
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    in_uChannelMask &= 0xFFFFFFF7;
  if ( (in_uChannelMask & 7) == 7 && !this->m_FXInfo.Params.NonRTPC.bProcessCenter )
    in_uChannelMask &= 0xFFFFFFFB;
  return in_uChannelMask;
}

// File Line: 102
// RVA: 0xAFA220
AKRESULT __fastcall CAkFlangerFX::InitUniCombs(CAkFlangerFX *this, unsigned int in_uChannelMask)
{
  int v2; // ebx
  CAkFlangerFX *v3; // rdi
  unsigned int v4; // esi
  DSP::UniComb *v5; // rax
  __int64 v6; // rdx
  AKRESULT result; // eax
  unsigned int v8; // er10
  signed __int64 v9; // r8
  unsigned int v10; // eax
  __int64 v11; // r9
  char *v12; // rcx
  signed __int64 v13; // rcx
  signed __int64 v14; // rcx
  signed __int64 v15; // rcx
  char *v16; // rcx
  unsigned int v17; // ebp
  unsigned __int16 v18; // ax

  v2 = 0;
  v3 = this;
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
  v3->m_pUniCombs = v5;
  if ( !v5 )
    return 52;
  v8 = 0;
  v9 = 0i64;
  if ( (signed int)v4 >= 4 )
  {
    v6 = 0i64;
    v10 = ((v4 - 4) >> 2) + 1;
    v11 = v10;
    v8 = 4 * v10;
    v9 = 4i64 * v10;
    do
    {
      v12 = (char *)v3->m_pUniCombs + v6;
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
      v13 = (signed __int64)&v3->m_pUniCombs[1] + v6;
      if ( v13 )
      {
        *(_QWORD *)v13 = 0i64;
        *(_DWORD *)(v13 + 8) = 0;
        *(_QWORD *)(v13 + 16) = 0i64;
        *(_QWORD *)(v13 + 24) = 0i64;
        *(_QWORD *)(v13 + 32) = 0i64;
        *(_QWORD *)(v13 + 40) = 0i64;
        *(_DWORD *)(v13 + 48) = 0;
      }
      v14 = (signed __int64)&v3->m_pUniCombs[2] + v6;
      if ( v14 )
      {
        *(_QWORD *)v14 = 0i64;
        *(_DWORD *)(v14 + 8) = 0;
        *(_QWORD *)(v14 + 16) = 0i64;
        *(_QWORD *)(v14 + 24) = 0i64;
        *(_QWORD *)(v14 + 32) = 0i64;
        *(_QWORD *)(v14 + 40) = 0i64;
        *(_DWORD *)(v14 + 48) = 0;
      }
      v15 = (signed __int64)&v3->m_pUniCombs[3] + v6;
      if ( v15 )
      {
        *(_QWORD *)v15 = 0i64;
        *(_DWORD *)(v15 + 8) = 0;
        *(_QWORD *)(v15 + 16) = 0i64;
        *(_QWORD *)(v15 + 24) = 0i64;
        *(_QWORD *)(v15 + 32) = 0i64;
        *(_QWORD *)(v15 + 40) = 0i64;
        *(_DWORD *)(v15 + 48) = 0;
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
      v16 = (char *)v3->m_pUniCombs + v9;
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
  v17 = (signed int)(float)((float)(v3->m_FXInfo.Params.NonRTPC.fDelayTime * 0.001)
                          * (float)(signed int)v3->m_FXInfo.uSampleRate);
  if ( !v4 )
    return 1;
  while ( 1 )
  {
    v18 = (*(__int64 (__fastcall **)(AK::IAkEffectPluginContext *, __int64, signed __int64))&v3->m_pFXCtx->vfptr->gap8[8])(
            v3->m_pFXCtx,
            v6,
            v9);
    result = DSP::UniComb::Init(
               &v3->m_pUniCombs[v2],
               v3->m_pAllocator,
               v17,
               v18,
               v3->m_FXInfo.Params.RTPC.fFbackLevel,
               v3->m_FXInfo.Params.RTPC.fFfwdLevel,
               v3->m_FXInfo.Params.RTPC.fDryLevel,
               v3->m_FXInfo.Params.RTPC.fModDepth);
    if ( result != 1 )
      break;
    if ( ++v2 >= v4 )
      return 1;
  }
  return result;
}

// File Line: 136
// RVA: 0xAFA430
signed __int64 __fastcall CAkFlangerFX::InitLFO(CAkFlangerFX *this, unsigned int in_uChannelMask)
{
  unsigned int v2; // esi
  CAkFlangerFX *v3; // rdi
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v4; // rbx
  unsigned int v5; // er8
  int v6; // er9
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v7; // rax
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v8; // rax

  v2 = in_uChannelMask;
  v3 = this;
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
                                                                         196ui64);
        if ( v7 )
        {
          DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>(v7);
          v4 = v8;
        }
        v3->m_pLFO = v4;
        if ( !v4 )
          return 52i64;
        DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy>::Setup(
          v4,
          v2,
          v3->m_FXInfo.uSampleRate,
          &v3->m_FXInfo.Params.RTPC.modParams);
      }
    }
  }
  return 1i64;
}

// File Line: 155
// RVA: 0xAF9BD0
signed __int64 __fastcall CAkFlangerFX::Term(CAkFlangerFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rsi
  CAkFlangerFX *v3; // rbx
  unsigned int v4; // edi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pUniCombs )
  {
    v4 = 0;
    if ( this->m_FXInfo.uNumProcessedChannels )
    {
      do
        DSP::UniComb::Term(&v3->m_pUniCombs[v4++], v3->m_pAllocator);
      while ( v4 < v3->m_FXInfo.uNumProcessedChannels );
    }
    v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, v3->m_pUniCombs);
    v3->m_pUniCombs = 0i64;
  }
  if ( v3->m_pLFO )
  {
    ((void (*)(void))v3->m_pAllocator->vfptr->Free)();
    v3->m_pLFO = 0i64;
  }
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 164
// RVA: 0xAFA4E0
void __fastcall CAkFlangerFX::TermUniCombs(CAkFlangerFX *this)
{
  CAkFlangerFX *v1; // rbx
  unsigned int v2; // edi

  v1 = this;
  if ( this->m_pUniCombs )
  {
    v2 = 0;
    if ( this->m_FXInfo.uNumProcessedChannels )
    {
      do
        DSP::UniComb::Term(&v1->m_pUniCombs[v2++], v1->m_pAllocator);
      while ( v2 < v1->m_FXInfo.uNumProcessedChannels );
    }
    v1->m_pAllocator->vfptr->Free(v1->m_pAllocator, v1->m_pUniCombs);
    v1->m_pUniCombs = 0i64;
  }
}

// File Line: 176
// RVA: 0xAFA550
void __fastcall CAkFlangerFX::TermLFO(CAkFlangerFX *this)
{
  CAkFlangerFX *v1; // rbx

  v1 = this;
  if ( this->m_pLFO )
  {
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
    v1->m_pLFO = 0i64;
  }
}

// File Line: 186
// RVA: 0xAF9CE0
signed __int64 __fastcall CAkFlangerFX::GetPluginInfo(CAkFlangerFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 199
// RVA: 0xAFA5D0
unsigned int __fastcall CAkFlangerFX::LiveParametersUpdate(CAkFlangerFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int v2; // ebp
  CAkFlangerFX *v3; // rbx
  __int64 v4; // rsi
  unsigned int v5; // ecx
  unsigned int i; // edi
  bool v7; // r14
  unsigned int result; // eax
  __int64 v9; // rbp

  v2 = io_pBuffer->uChannelMask;
  v3 = this;
  if ( !this->m_FXInfo.Params.NonRTPC.bProcessLFE )
    v2 &= 0xFFFFFFF7;
  if ( (v2 & 7) == 7 && !this->m_FXInfo.Params.NonRTPC.bProcessCenter )
    v2 &= 0xFFFFFFFB;
  v4 = 0i64;
  v5 = v2;
  for ( i = 0; v5; v5 &= v5 - 1 )
    ++i;
  v7 = i != v3->m_FXInfo.uNumProcessedChannels;
  if ( v3->m_FXInfo.PrevParams.NonRTPC.bEnableLFO == v3->m_FXInfo.Params.NonRTPC.bEnableLFO && !v7 )
    goto LABEL_23;
  if ( v3->m_pLFO )
  {
    ((void (*)(void))v3->m_pAllocator->vfptr->Free)();
    v3->m_pLFO = 0i64;
  }
  result = CAkFlangerFX::InitLFO(v3, v2);
  if ( result == 1 )
  {
LABEL_23:
    if ( v3->m_FXInfo.Params.NonRTPC.fDelayTime != v3->m_FXInfo.PrevParams.NonRTPC.fDelayTime || v7 )
    {
      CAkFlangerFX::TermUniCombs(v3);
      result = CAkFlangerFX::InitUniCombs(v3, v2);
      if ( result != 1 )
        return result;
      if ( v3->m_pUniCombs && i )
      {
        v9 = i;
        do
        {
          DSP::UniComb::Reset(&v3->m_pUniCombs[v4]);
          ++v4;
          --v9;
        }
        while ( v9 );
      }
    }
    v3->m_FXInfo.uNumProcessedChannels = i;
    result = 1;
  }
  return result;
}

// File Line: 227
// RVA: 0xAFA6F0
void __fastcall CAkFlangerFX::RTPCParametersUpdate(CAkFlangerFX *this)
{
  signed __int64 v1; // rsi
  CAkFlangerFX *v2; // rdi
  unsigned int v3; // ebx
  DSP::MultiChannelLFO<DSP::Bipolar,FlangerOutputPolicy> *v4; // rbx
  signed int v5; // ebp
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  signed __int64 v12; // rcx
  float v13; // xmm0_4
  DSP::LFO::Waveform v14; // eax
  DSP::LFO::Waveform v15; // edx
  float v16; // xmm0_4
  float out_fA1; // [rsp+70h] [rbp+8h]
  float out_fB0; // [rsp+78h] [rbp+10h]

  v1 = 0i64;
  v2 = this;
  v3 = 0;
  if ( this->m_FXInfo.uNumProcessedChannels )
  {
    do
      DSP::UniComb::SetParams(
        &v2->m_pUniCombs[v3++],
        v2->m_FXInfo.Params.RTPC.fFbackLevel,
        v2->m_FXInfo.Params.RTPC.fFfwdLevel,
        v2->m_FXInfo.Params.RTPC.fDryLevel,
        v2->m_FXInfo.Params.RTPC.fModDepth);
    while ( v3 < v2->m_FXInfo.uNumProcessedChannels );
  }
  v4 = v2->m_pLFO;
  if ( v4 && v2->m_FXInfo.Params.NonRTPC.bEnableLFO )
  {
    v5 = v2->m_FXInfo.uSampleRate;
    v6 = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
    if ( v6 == 0.0 )
    {
      DSP::OnePoleFilter::ComputeCoefs(0, 0.0, 0, &out_fB0, &out_fA1);
    }
    else
    {
      v7 = (float)v5 * 0.5;
      v8 = logf(v7 / v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency);
      v9 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 * v6) ^ _xmm[0]));
      DSP::OnePoleFilter::ComputeCoefs(FILTERCURVETYPE_LOWPASS, v9 * v7, v5, &out_fB0, &out_fA1);
    }
    if ( v4->m_uNumChannels > 0 )
    {
      v10 = out_fA1;
      v11 = out_fB0;
      while ( 1 )
      {
        v12 = v1;
        v13 = (float)(1.0 / (float)v5) * v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
        v4->m_arLfo[v1].m_state.fPhaseDelta = v13;
        if ( v2->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform == WAVEFORM_SINE )
          v4->m_arLfo[v1].m_state.fPhaseDelta = v13 * 6.2831855;
        v4->m_arLfo[v1].m_state.filter.fB0 = v11;
        v4->m_arLfo[v1].m_state.filter.fA1 = v10;
        v14 = v4->m_arLfo[v1].m_state.eWaveform;
        v15 = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
        if ( v14 == v15 )
          goto LABEL_18;
        if ( v14 == WAVEFORM_SINE )
          break;
        if ( v15 == WAVEFORM_SINE )
        {
          v16 = v4->m_arLfo[v1].m_state.fPhase * 6.2831855;
          goto LABEL_17;
        }
LABEL_18:
        v1 = (unsigned int)(v1 + 1);
        v4->m_arLfo[v12].m_state.eWaveform = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
        if ( (unsigned int)v1 >= v4->m_uNumChannels )
          return;
      }
      v16 = v4->m_arLfo[v1].m_state.fPhase * 0.15915494;
LABEL_17:
      v4->m_arLfo[v1].m_state.fPhase = v16;
      goto LABEL_18;
    }
  }
}

// File Line: 251
// RVA: 0xAF9D00
void __fastcall CAkFlangerFX::Execute(CAkFlangerFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkFlangerFX *v2; // rdi
  CAkFlangerFXParams *v3; // rcx
  AkAudioBuffer *v4; // rbx
  __int64 v5; // r14
  unsigned __int16 v6; // ax
  unsigned int v7; // edx
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
  float v20; // xmm10_4
  float in_fPrevAmp; // xmm11_4
  char *v22; // rbx
  unsigned int v23; // esi
  char *v24; // rbx
  char in_rParams; // [rsp+F0h] [rbp+8h]
  AkAudioBuffer *v26; // [rsp+F8h] [rbp+10h]
  void *Dst; // [rsp+100h] [rbp+18h]

  v26 = io_pBuffer;
  v2 = this;
  v3 = this->m_pSharedParams;
  v4 = io_pBuffer;
  v2->m_FXInfo.Params.RTPC.fDryLevel = v3->m_Params.RTPC.fDryLevel;
  v2->m_FXInfo.Params.RTPC.fFfwdLevel = v3->m_Params.RTPC.fFfwdLevel;
  v2->m_FXInfo.Params.RTPC.fFbackLevel = v3->m_Params.RTPC.fFbackLevel;
  v2->m_FXInfo.Params.RTPC.fModDepth = v3->m_Params.RTPC.fModDepth;
  v2->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform = v3->m_Params.RTPC.modParams.lfoParams.eWaveform;
  v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency = v3->m_Params.RTPC.modParams.lfoParams.fFrequency;
  v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth = v3->m_Params.RTPC.modParams.lfoParams.fSmooth;
  v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM = v3->m_Params.RTPC.modParams.lfoParams.fPWM;
  v2->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset = v3->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
  v2->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread = v3->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
  v2->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode = v3->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
  v2->m_FXInfo.Params.RTPC.fOutputLevel = v3->m_Params.RTPC.fOutputLevel;
  v2->m_FXInfo.Params.RTPC.fWetDryMix = v3->m_Params.RTPC.fWetDryMix;
  *(_DWORD *)&v2->m_FXInfo.Params.RTPC.bHasChanged = *(_DWORD *)&v3->m_Params.RTPC.bHasChanged;
  v2->m_FXInfo.Params.NonRTPC.fDelayTime = v3->m_Params.NonRTPC.fDelayTime;
  *(_DWORD *)&v2->m_FXInfo.Params.NonRTPC.bEnableLFO = *(_DWORD *)&v3->m_Params.NonRTPC.bEnableLFO;
  CAkFlangerFXParams::SetDirty(v3, 0);
  v5 = 0i64;
  if ( !v2->m_FXInfo.Params.NonRTPC.bEnableLFO )
    v2->m_FXInfo.Params.RTPC.fModDepth = 0.0;
  if ( v2->m_FXInfo.Params.NonRTPC.bHasChanged )
  {
    if ( CAkFlangerFX::LiveParametersUpdate(v2, v4) != 1 )
      return;
    v2->m_FXInfo.Params.NonRTPC.bHasChanged = 0;
  }
  if ( v2->m_FXInfo.Params.RTPC.bHasChanged )
  {
    CAkFlangerFX::RTPCParametersUpdate(v2);
    v2->m_FXInfo.Params.RTPC.bHasChanged = 0;
  }
  if ( v2->m_FXInfo.uNumProcessedChannels )
  {
    AkFXTailHandler::HandleTail(
      &v2->m_FXInfo.FXTailHandler,
      v4,
      (signed int)(float)((float)(v2->m_FXInfo.Params.NonRTPC.fDelayTime * 0.001)
                        * (float)(signed int)v2->m_FXInfo.uSampleRate));
    v6 = v4->uValidFrames;
    if ( v6 )
    {
      v7 = v4->uChannelMask;
      v8 = v6;
      if ( !v2->m_FXInfo.Params.NonRTPC.bProcessLFE )
        v7 &= 0xFFFFFFF7;
      v9 = v7;
      for ( i = 0; v9; v9 &= v9 - 1 )
        ++i;
      v11 = !v2->m_FXInfo.Params.NonRTPC.bProcessCenter && (v7 & 7) == 7;
      v12 = v2->m_pAllocator->vfptr->Malloc(v2->m_pAllocator, 4i64 * v4->uMaxFrames);
      Dst = v12;
      if ( v12 )
      {
        v13 = (float)(100.0 - v2->m_FXInfo.Params.RTPC.fWetDryMix) * 0.0099999998;
        v14 = (float)(100.0 - v2->m_FXInfo.PrevParams.RTPC.fWetDryMix) * 0.0099999998;
        v15 = 1.0 - v13;
        v16 = 1.0 - v14;
        if ( v2->m_FXInfo.Params.NonRTPC.bEnableLFO )
        {
          v17 = 0;
          v18 = (float *)v2->m_pAllocator->vfptr->Malloc(v2->m_pAllocator, 4 * v8);
          in_fPWM = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
          v20 = v2->m_FXInfo.Params.RTPC.fModDepth;
          in_fPrevAmp = v2->m_FXInfo.PrevParams.RTPC.fModDepth;
          if ( i )
          {
            do
            {
              if ( !v11 || v17 != 2 )
              {
                if ( v18 )
                  DSP::MonoLFO<DSP::Bipolar,FlangerOutputPolicy>::ProduceBuffer(
                    &v2->m_pLFO->m_arLfo[v5],
                    v18,
                    v8,
                    v20,
                    in_fPrevAmp,
                    in_fPWM,
                    (FlangerOutputPolicy *)&in_rParams);
                v22 = (char *)v4->pData + 4 * v17 * (unsigned __int64)v4->uMaxFrames;
                memmove(Dst, v22, (unsigned int)(4 * v8));
                DSP::UniComb::ProcessBuffer(&v2->m_pUniCombs[(unsigned int)v5], (float *)v22, v8, v18);
                v5 = (unsigned int)(v5 + 1);
                DSP::Mix2Interp(
                  (float *)v22,
                  (float *)Dst,
                  v2->m_FXInfo.PrevParams.RTPC.fOutputLevel * v16,
                  v2->m_FXInfo.Params.RTPC.fOutputLevel * v15,
                  v2->m_FXInfo.PrevParams.RTPC.fOutputLevel * v14,
                  v2->m_FXInfo.Params.RTPC.fOutputLevel * v13,
                  v8);
                v4 = v26;
              }
              ++v17;
            }
            while ( v17 < i );
          }
          if ( v18 )
            v2->m_pAllocator->vfptr->Free(v2->m_pAllocator, v18);
          v12 = Dst;
        }
        else
        {
          v23 = 0;
          if ( i )
          {
            do
            {
              if ( !v11 || v23 != 2 )
              {
                v24 = (char *)v4->pData + 4 * v23 * (unsigned __int64)v4->uMaxFrames;
                memmove(v12, v24, (unsigned int)(4 * v8));
                DSP::UniComb::ProcessBuffer(&v2->m_pUniCombs[(unsigned int)v5], (float *)v24, v8, 0i64);
                LODWORD(v5) = v5 + 1;
                DSP::Mix2Interp(
                  (float *)v24,
                  (float *)v12,
                  v2->m_FXInfo.PrevParams.RTPC.fOutputLevel * v16,
                  v2->m_FXInfo.Params.RTPC.fOutputLevel * v15,
                  v2->m_FXInfo.PrevParams.RTPC.fOutputLevel * v14,
                  v2->m_FXInfo.Params.RTPC.fOutputLevel * v13,
                  v8);
                v4 = v26;
              }
              ++v23;
            }
            while ( v23 < i );
          }
        }
        v2->m_pAllocator->vfptr->Free(v2->m_pAllocator, v12);
        v2->m_FXInfo.PrevParams.RTPC.fDryLevel = v2->m_FXInfo.Params.RTPC.fDryLevel;
        v2->m_FXInfo.PrevParams.RTPC.fFfwdLevel = v2->m_FXInfo.Params.RTPC.fFfwdLevel;
        v2->m_FXInfo.PrevParams.RTPC.fFbackLevel = v2->m_FXInfo.Params.RTPC.fFbackLevel;
        v2->m_FXInfo.PrevParams.RTPC.fModDepth = v2->m_FXInfo.Params.RTPC.fModDepth;
        v2->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.eWaveform = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.eWaveform;
        v2->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fFrequency = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fFrequency;
        v2->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fSmooth = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fSmooth;
        v2->m_FXInfo.PrevParams.RTPC.modParams.lfoParams.fPWM = v2->m_FXInfo.Params.RTPC.modParams.lfoParams.fPWM;
        v2->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseOffset = v2->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseOffset;
        v2->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.fPhaseSpread = v2->m_FXInfo.Params.RTPC.modParams.phaseParams.fPhaseSpread;
        v2->m_FXInfo.PrevParams.RTPC.modParams.phaseParams.ePhaseMode = v2->m_FXInfo.Params.RTPC.modParams.phaseParams.ePhaseMode;
        v2->m_FXInfo.PrevParams.RTPC.fOutputLevel = v2->m_FXInfo.Params.RTPC.fOutputLevel;
        v2->m_FXInfo.PrevParams.RTPC.fWetDryMix = v2->m_FXInfo.Params.RTPC.fWetDryMix;
        *(_DWORD *)&v2->m_FXInfo.PrevParams.RTPC.bHasChanged = *(_DWORD *)&v2->m_FXInfo.Params.RTPC.bHasChanged;
        v2->m_FXInfo.PrevParams.NonRTPC.fDelayTime = v2->m_FXInfo.Params.NonRTPC.fDelayTime;
        *(_DWORD *)&v2->m_FXInfo.PrevParams.NonRTPC.bEnableLFO = *(_DWORD *)&v2->m_FXInfo.Params.NonRTPC.bEnableLFO;
      }
    }
  }
}

// File Line: 423
// RVA: 0xAF9C80
signed __int64 __fastcall CAkFlangerFX::Reset(CAkFlangerFX *this)
{
  unsigned int v1; // eax
  CAkFlangerFX *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rbx

  v1 = this->m_FXInfo.uNumProcessedChannels;
  v2 = this;
  if ( this->m_pUniCombs && v1 )
  {
    v3 = v1;
    v4 = 0i64;
    do
    {
      DSP::UniComb::Reset(&v2->m_pUniCombs[v4]);
      ++v4;
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
  CAkFlangerFX *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rbx

  v2 = this;
  if ( this->m_pUniCombs && in_uNumProcessedChannels )
  {
    v3 = in_uNumProcessedChannels;
    v4 = 0i64;
    do
    {
      DSP::UniComb::Reset(&v2->m_pUniCombs[v4]);
      ++v4;
      --v3;
    }
    while ( v3 );
  }
}

