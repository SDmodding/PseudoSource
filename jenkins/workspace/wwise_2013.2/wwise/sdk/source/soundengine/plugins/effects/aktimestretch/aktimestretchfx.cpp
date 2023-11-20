// File Line: 28
// RVA: 0xAECD00
AK::IAkPlugin *__fastcall CreateTimeStretchFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 1064ui64);
  v2 = result;
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkTimeStretchFX::`vftable;
    result[1].vfptr = 0i64;
    result[2].vfptr = 0i64;
    result[3].vfptr = (AK::IAkPluginVtbl *)2048;
    LODWORD(result[4].vfptr) = 0;
    HIDWORD(result[4].vfptr) = 1065353216;
    result[5].vfptr = (AK::IAkPluginVtbl *)2048;
    LODWORD(result[6].vfptr) = 0;
    HIDWORD(result[6].vfptr) = 1065353216;
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::CAkPhaseVocoder((DSP::AkFFTAllButterflies::CAkPhaseVocoder *)&result[9]);
    result = v2;
  }
  return result;
}

// File Line: 37
// RVA: 0xAECD70
void __fastcall CAkTimeStretchFX::CAkTimeStretchFX(CAkTimeStretchFX *this)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v1; // rcx

  v1 = &this->m_FXInfo.PhaseVocoder;
  v1[-1].m_pfPrevSynthesisPhase[7] = (float *)&CAkTimeStretchFX::`vftable;
  *(_QWORD *)v1[-1].m_uFreqWindowIndex = 0i64;
  v1[-1].m_pFFTState = 0i64;
  v1[-1].m_pIFFTState = (ak_fftr_state *)2048;
  LODWORD(v1[-1].m_uFFTSpaceRequirements) = 0;
  HIDWORD(v1[-1].m_uFFTSpaceRequirements) = 1065353216;
  v1[-1].m_uIFFTSpaceRequirements = 2048i64;
  v1[-1].m_uNumChannels = 0;
  v1[-1].m_uSampleRate = 1065353216;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::CAkPhaseVocoder(v1);
}

// File Line: 43
// RVA: 0xAECDD0
void __fastcall CAkTimeStretchFX::~CAkTimeStretchFX(CAkTimeStretchFX *this)
{
  CAkTimeStretchFX *v1; // rbx
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v2; // rcx

  v1 = this;
  v2 = &this->m_FXInfo.PhaseVocoder;
  v2[-1].m_pfPrevSynthesisPhase[7] = (float *)&CAkTimeStretchFX::`vftable;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::~CAkPhaseVocoder(v2);
  v1->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 53
// RVA: 0xAECE10
AKRESULT __fastcall CAkTimeStretchFX::Init(CAkTimeStretchFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AK::IAkPluginMemAlloc *v5; // rsi
  CAkTimeStretchFX *v6; // rbx
  unsigned int v7; // er10
  int i; // er8
  int v9; // eax
  unsigned int v10; // er8
  int j; // ecx
  AKRESULT result; // eax

  this->m_pSharedParams = (CAkTimeStretchFXParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  v5 = in_pAllocator;
  v6 = this;
  v7 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  this->m_FXInfo.uNumChannels = v7;
  this->m_FXInfo.uSampleRate = in_rFormat->uSampleRate;
  CAkTimeStretchFXParams::GetParams((CAkTimeStretchFXParams *)in_pParams, &this->m_FXInfo.Params);
  v6->m_FXInfo.PrevParams.uWindowSize = v6->m_FXInfo.Params.uWindowSize;
  v6->m_FXInfo.PrevParams.fTimeStretch = v6->m_FXInfo.Params.fTimeStretch;
  v6->m_FXInfo.PrevParams.fTimeStretchRandom = v6->m_FXInfo.Params.fTimeStretchRandom;
  v6->m_FXInfo.PrevParams.fOutputGain = v6->m_FXInfo.Params.fOutputGain;
  v9 = rand();
  v10 = 0;
  v6->m_FXInfo.fTSRandomOffset = (float)((float)((float)(214013 * v9 + 2531011) * 2.3283064e-10)
                                       * (float)(v6->m_FXInfo.Params.fTimeStretchRandom
                                               - COERCE_FLOAT(LODWORD(v6->m_FXInfo.Params.fTimeStretchRandom) ^ _xmm[0])))
                               + COERCE_FLOAT(LODWORD(v6->m_FXInfo.Params.fTimeStretchRandom) ^ _xmm[0]);
  for ( j = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; j; j &= j - 1 )
    ++v10;
  result = DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
             &v6->m_FXInfo.PhaseVocoder,
             v5,
             v10,
             in_rFormat->uSampleRate,
             v6->m_FXInfo.Params.uWindowSize,
             1);
  *(_WORD *)&v6->m_FXInfo.uNoTSModeCount = 0;
  v6->m_fSkippedFrames = 0.0;
  return result;
}

// File Line: 90
// RVA: 0xAECF40
signed __int64 __fastcall CAkTimeStretchFX::Term(CAkTimeStretchFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkTimeStretchFX *v2; // rbx
  AK::IAkPluginMemAlloc *v3; // rdi

  v2 = this;
  v3 = in_pAllocator;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(&this->m_FXInfo.PhaseVocoder, in_pAllocator);
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((AK::IAkPlugin *)&v2->vfptr, 0);
    v3->vfptr->Free(v3, v2);
  }
  return 1i64;
}

// File Line: 101
// RVA: 0xAECF90
signed __int64 __fastcall CAkTimeStretchFX::Reset(CAkTimeStretchFX *this)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(&this->m_FXInfo.PhaseVocoder);
  return 1i64;
}

// File Line: 114
// RVA: 0xAECFB0
signed __int64 __fastcall CAkTimeStretchFX::GetPluginInfo(CAkTimeStretchFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 0;
  return 1i64;
}

// File Line: 132
// RVA: 0xAECFD0
void __fastcall CAkTimeStretchFX::Execute(CAkTimeStretchFX *this, AkAudioBuffer *in_pBuffer, unsigned int in_uInOffset, AkAudioBuffer *out_pBuffer)
{
  AkAudioBuffer *v4; // r15
  CAkTimeStretchFX *v5; // rbx
  AkAudioBuffer *v6; // rsi
  unsigned int v7; // er14
  float v8; // xmm0_4
  float v9; // xmm1_4
  unsigned __int64 v10; // rdx
  float v11; // xmm6_4
  bool v12; // r12
  float *in_pfTempStorage; // rax
  float *v14; // rbp
  AKRESULT v15; // eax

  v4 = in_pBuffer;
  v5 = this;
  this->m_fSkippedFrames = 0.0;
  v6 = out_pBuffer;
  v7 = in_uInOffset;
  CAkTimeStretchFXParams::GetParams(this->m_pSharedParams, &this->m_FXInfo.Params);
  if ( v5->m_FXInfo.Params.uWindowSize != v5->m_FXInfo.PrevParams.uWindowSize )
  {
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(&v5->m_FXInfo.PhaseVocoder, v5->m_pAllocator);
    if ( DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
           &v5->m_FXInfo.PhaseVocoder,
           v5->m_pAllocator,
           v5->m_FXInfo.uNumChannels,
           v5->m_FXInfo.uSampleRate,
           v5->m_FXInfo.Params.uWindowSize,
           1) != 1 )
    {
      CAkTimeStretchFX::Bypass(v5, v4, v7, v6);
      return;
    }
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(&v5->m_FXInfo.PhaseVocoder);
    v5->m_FXInfo.PrevParams.uWindowSize = v5->m_FXInfo.Params.uWindowSize;
  }
  v8 = v5->m_FXInfo.fTSRandomOffset;
  v9 = FLOAT_1600_0;
  v10 = 4 * v5->m_FXInfo.PhaseVocoder.m_uFFTSize;
  v11 = v8 + v5->m_FXInfo.Params.fTimeStretch;
  if ( v11 >= 1600.0 || (v9 = FLOAT_25_0, v11 <= 25.0) )
  {
    v11 = v9;
  }
  else if ( v11 == 100.0 )
  {
    if ( (float)(v8 + v5->m_FXInfo.PrevParams.fTimeStretch) != 100.0 )
      *(_WORD *)&v5->m_FXInfo.uNoTSModeCount = 256;
    if ( v5->m_FXInfo.bCanEnterNoTSMode )
      ++v5->m_FXInfo.uNoTSModeCount;
    goto LABEL_14;
  }
  *(_WORD *)&v5->m_FXInfo.uNoTSModeCount = 0;
LABEL_14:
  v12 = v5->m_FXInfo.uNoTSModeCount == 8;
  in_pfTempStorage = (float *)v5->m_pAllocator->vfptr->Malloc(v5->m_pAllocator, v10);
  v14 = in_pfTempStorage;
  if ( in_pfTempStorage )
  {
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::Execute(
      &v5->m_FXInfo.PhaseVocoder,
      v4,
      v7,
      v6,
      v11,
      v12,
      in_pfTempStorage);
    if ( v12 )
      *(_WORD *)&v5->m_FXInfo.uNoTSModeCount = 0;
    v5->m_pAllocator->vfptr->Free(v5->m_pAllocator, v14);
    v15 = v6->eState;
    if ( v15 == 45 || v15 == 17 )
    {
      AK::DSP::ApplyGain_6(v6, v5->m_FXInfo.PrevParams.fOutputGain, v5->m_FXInfo.Params.fOutputGain, 1);
      v5->m_FXInfo.PrevParams.uWindowSize = v5->m_FXInfo.Params.uWindowSize;
      v5->m_FXInfo.PrevParams.fTimeStretch = v5->m_FXInfo.Params.fTimeStretch;
      v5->m_FXInfo.PrevParams.fTimeStretchRandom = v5->m_FXInfo.Params.fTimeStretchRandom;
      v5->m_FXInfo.PrevParams.fOutputGain = v5->m_FXInfo.Params.fOutputGain;
    }
  }
  else
  {
    CAkTimeStretchFX::Bypass(v5, v4, v7, v6);
  }
}

// File Line: 266
// RVA: 0xAED1B0
void __fastcall CAkTimeStretchFX::Bypass(CAkTimeStretchFX *this, AkAudioBuffer *in_pBuffer, unsigned int in_uInOffset, AkAudioBuffer *out_pBuffer)
{
  unsigned int v4; // er10
  __int64 v5; // rdi
  AkAudioBuffer *v6; // rbx
  __int64 v7; // r11
  AkAudioBuffer *v8; // rsi
  unsigned int v9; // ecx
  unsigned int i; // er9
  unsigned int v11; // edx
  unsigned int v12; // er8
  unsigned int v13; // ecx
  unsigned int j; // eax
  int v15; // ebp
  __int64 v16; // r12
  __int64 v17; // r14
  signed int v18; // ecx

  v4 = in_pBuffer->uChannelMask;
  v5 = 0i64;
  v6 = out_pBuffer;
  v7 = in_uInOffset;
  v8 = in_pBuffer;
  v9 = v4;
  for ( i = 0; v9; v9 &= v9 - 1 )
    ++i;
  v11 = v6->uChannelMask;
  v12 = 0;
  v13 = v11;
  if ( !v11 )
    goto LABEL_24;
  do
  {
    ++v12;
    v13 &= v13 - 1;
  }
  while ( v13 );
  if ( i < v12 )
  {
    for ( j = 0; v4; v4 &= v4 - 1 )
      ++j;
  }
  else
  {
LABEL_24:
    for ( j = 0; v11; v11 &= v11 - 1 )
      ++j;
  }
  v15 = v6->uMaxFrames - v6->uValidFrames;
  if ( v8->uValidFrames < v15 )
    v15 = v8->uValidFrames;
  if ( j )
  {
    v16 = v7;
    v17 = j;
    do
    {
      memmove(
        (char *)v6->pData + 4 * (v6->uValidFrames + v5 * v6->uMaxFrames),
        (char *)v8->pData + 4 * (v16 + v5 * v8->uMaxFrames),
        (unsigned int)(4 * v15));
      ++v5;
      --v17;
    }
    while ( v17 );
  }
  v6->uValidFrames += v15;
  v8->uValidFrames -= v15;
  if ( v8->eState != 17 || v8->uValidFrames )
  {
    v18 = 43;
    if ( v6->uValidFrames == v6->uMaxFrames )
      v18 = 45;
    v6->eState = v18;
  }
  else
  {
    v6->eState = 17;
  }
}

// File Line: 287
// RVA: 0xAED300
signed __int64 __fastcall CAkTimeStretchFX::TimeSkip(CAkTimeStretchFX *this, unsigned int *io_uFrames)
{
  unsigned int *v2; // rdi
  CAkTimeStretchFX *v3; // rbx
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  v2 = io_uFrames;
  v3 = this;
  if ( !*io_uFrames )
    return 17i64;
  CAkTimeStretchFXParams::GetParams(this->m_pSharedParams, &this->m_FXInfo.Params);
  v5 = FLOAT_1600_0;
  v6 = v3->m_FXInfo.fTSRandomOffset + v3->m_FXInfo.Params.fTimeStretch;
  if ( v6 >= 1600.0 || (v5 = FLOAT_25_0, v6 <= 25.0) )
    v6 = v5;
  v7 = v3->m_fSkippedFrames;
  v8 = (float)((float)((float)(signed int)*v2 * 100.0) / v6) + v7;
  v3->m_fSkippedFrames = v8;
  *v2 = (signed int)(float)(v8 - v7);
  return 45i64;
}

