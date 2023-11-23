// File Line: 28
// RVA: 0xAECD00
AK::IAkPlugin *__fastcall CreateTimeStretchFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 1064i64);
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
    return v2;
  }
  return result;
}

// File Line: 37
// RVA: 0xAECD70
void __fastcall CAkTimeStretchFX::CAkTimeStretchFX(CAkTimeStretchFX *this)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *p_PhaseVocoder; // rcx

  p_PhaseVocoder = &this->m_FXInfo.PhaseVocoder;
  p_PhaseVocoder[-1].m_pfPrevSynthesisPhase[7] = (float *)&CAkTimeStretchFX::`vftable;
  *(_QWORD *)p_PhaseVocoder[-1].m_uFreqWindowIndex = 0i64;
  p_PhaseVocoder[-1].m_pFFTState = 0i64;
  p_PhaseVocoder[-1].m_pIFFTState = (ak_fftr_state *)2048;
  LODWORD(p_PhaseVocoder[-1].m_uFFTSpaceRequirements) = 0;
  HIDWORD(p_PhaseVocoder[-1].m_uFFTSpaceRequirements) = 1065353216;
  p_PhaseVocoder[-1].m_uIFFTSpaceRequirements = 2048i64;
  p_PhaseVocoder[-1].m_uNumChannels = 0;
  p_PhaseVocoder[-1].m_uSampleRate = 1065353216;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::CAkPhaseVocoder(p_PhaseVocoder);
}

// File Line: 43
// RVA: 0xAECDD0
void __fastcall CAkTimeStretchFX::~CAkTimeStretchFX(CAkTimeStretchFX *this)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *p_PhaseVocoder; // rcx

  p_PhaseVocoder = &this->m_FXInfo.PhaseVocoder;
  p_PhaseVocoder[-1].m_pfPrevSynthesisPhase[7] = (float *)&CAkTimeStretchFX::`vftable;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::~CAkPhaseVocoder(p_PhaseVocoder);
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 53
// RVA: 0xAECE10
AKRESULT __fastcall CAkTimeStretchFX::Init(
        CAkTimeStretchFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkTimeStretchFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  unsigned int v7; // r10d
  int i; // r8d
  int v9; // eax
  unsigned int v10; // r8d
  int j; // ecx
  AKRESULT result; // eax

  this->m_pSharedParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  v7 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  this->m_FXInfo.uNumChannels = v7;
  this->m_FXInfo.uSampleRate = in_rFormat->uSampleRate;
  CAkTimeStretchFXParams::GetParams(in_pParams, &this->m_FXInfo.Params);
  this->m_FXInfo.PrevParams.uWindowSize = this->m_FXInfo.Params.uWindowSize;
  this->m_FXInfo.PrevParams.fTimeStretch = this->m_FXInfo.Params.fTimeStretch;
  this->m_FXInfo.PrevParams.fTimeStretchRandom = this->m_FXInfo.Params.fTimeStretchRandom;
  this->m_FXInfo.PrevParams.fOutputGain = this->m_FXInfo.Params.fOutputGain;
  v9 = rand();
  v10 = 0;
  this->m_FXInfo.fTSRandomOffset = (float)((float)((float)(214013 * v9 + 2531011) * 2.3283064e-10)
                                         * (float)(this->m_FXInfo.Params.fTimeStretchRandom
                                                 - COERCE_FLOAT(LODWORD(this->m_FXInfo.Params.fTimeStretchRandom) ^ _xmm[0])))
                                 + COERCE_FLOAT(LODWORD(this->m_FXInfo.Params.fTimeStretchRandom) ^ _xmm[0]);
  for ( j = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; j; j &= j - 1 )
    ++v10;
  result = DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
             &this->m_FXInfo.PhaseVocoder,
             in_pAllocator,
             v10,
             in_rFormat->uSampleRate,
             this->m_FXInfo.Params.uWindowSize,
             1);
  *(_WORD *)&this->m_FXInfo.uNoTSModeCount = 0;
  this->m_fSkippedFrames = 0.0;
  return result;
}

// File Line: 90
// RVA: 0xAECF40
__int64 __fastcall CAkTimeStretchFX::Term(CAkTimeStretchFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(&this->m_FXInfo.PhaseVocoder, in_pAllocator);
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 101
// RVA: 0xAECF90
__int64 __fastcall CAkTimeStretchFX::Reset(CAkTimeStretchFX *this)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(&this->m_FXInfo.PhaseVocoder);
  return 1i64;
}

// File Line: 114
// RVA: 0xAECFB0
__int64 __fastcall CAkTimeStretchFX::GetPluginInfo(CAkTimeStretchFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 0;
  return 1i64;
}

// File Line: 132
// RVA: 0xAECFD0
void __fastcall CAkTimeStretchFX::Execute(
        CAkTimeStretchFX *this,
        AkAudioBuffer *in_pBuffer,
        unsigned int in_uInOffset,
        AkAudioBuffer *out_pBuffer)
{
  float fTSRandomOffset; // xmm0_4
  float v9; // xmm1_4
  unsigned __int64 v10; // rdx
  float v11; // xmm6_4
  bool v12; // r12
  float *in_pfTempStorage; // rax
  float *v14; // rbp
  AKRESULT eState; // eax

  this->m_fSkippedFrames = 0.0;
  CAkTimeStretchFXParams::GetParams(this->m_pSharedParams, &this->m_FXInfo.Params);
  if ( this->m_FXInfo.Params.uWindowSize != this->m_FXInfo.PrevParams.uWindowSize )
  {
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(&this->m_FXInfo.PhaseVocoder, this->m_pAllocator);
    if ( DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
           &this->m_FXInfo.PhaseVocoder,
           this->m_pAllocator,
           this->m_FXInfo.uNumChannels,
           this->m_FXInfo.uSampleRate,
           this->m_FXInfo.Params.uWindowSize,
           1) != AK_Success )
    {
LABEL_3:
      CAkTimeStretchFX::Bypass(this, in_pBuffer, in_uInOffset, out_pBuffer);
      return;
    }
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(&this->m_FXInfo.PhaseVocoder);
    this->m_FXInfo.PrevParams.uWindowSize = this->m_FXInfo.Params.uWindowSize;
  }
  fTSRandomOffset = this->m_FXInfo.fTSRandomOffset;
  v9 = FLOAT_1600_0;
  v10 = 4 * this->m_FXInfo.PhaseVocoder.m_uFFTSize;
  v11 = fTSRandomOffset + this->m_FXInfo.Params.fTimeStretch;
  if ( v11 >= 1600.0 || (v9 = FLOAT_25_0, v11 <= 25.0) )
  {
    v11 = v9;
    goto LABEL_13;
  }
  if ( v11 != 100.0 )
  {
LABEL_13:
    *(_WORD *)&this->m_FXInfo.uNoTSModeCount = 0;
    goto LABEL_14;
  }
  if ( (float)(fTSRandomOffset + this->m_FXInfo.PrevParams.fTimeStretch) != 100.0 )
    *(_WORD *)&this->m_FXInfo.uNoTSModeCount = 256;
  if ( this->m_FXInfo.bCanEnterNoTSMode )
    ++this->m_FXInfo.uNoTSModeCount;
LABEL_14:
  v12 = this->m_FXInfo.uNoTSModeCount == 8;
  in_pfTempStorage = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v10);
  v14 = in_pfTempStorage;
  if ( !in_pfTempStorage )
    goto LABEL_3;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Execute(
    &this->m_FXInfo.PhaseVocoder,
    in_pBuffer,
    in_uInOffset,
    out_pBuffer,
    v11,
    v12,
    in_pfTempStorage);
  if ( v12 )
    *(_WORD *)&this->m_FXInfo.uNoTSModeCount = 0;
  this->m_pAllocator->vfptr->Free(this->m_pAllocator, v14);
  eState = out_pBuffer->eState;
  if ( eState == AK_DataReady || eState == AK_NoMoreData )
  {
    AK::DSP::ApplyGain_6(out_pBuffer, this->m_FXInfo.PrevParams.fOutputGain, this->m_FXInfo.Params.fOutputGain, 1);
    this->m_FXInfo.PrevParams.uWindowSize = this->m_FXInfo.Params.uWindowSize;
    this->m_FXInfo.PrevParams.fTimeStretch = this->m_FXInfo.Params.fTimeStretch;
    this->m_FXInfo.PrevParams.fTimeStretchRandom = this->m_FXInfo.Params.fTimeStretchRandom;
    this->m_FXInfo.PrevParams.fOutputGain = this->m_FXInfo.Params.fOutputGain;
  }
}

// File Line: 266
// RVA: 0xAED1B0
void __fastcall CAkTimeStretchFX::Bypass(
        CAkTimeStretchFX *this,
        AkAudioBuffer *in_pBuffer,
        unsigned int in_uInOffset,
        AkAudioBuffer *out_pBuffer)
{
  unsigned int uChannelMask; // r10d
  __int64 v5; // rdi
  __int64 v7; // r11
  unsigned int v9; // ecx
  unsigned int i; // r9d
  unsigned int v11; // edx
  unsigned int v12; // r8d
  unsigned int v13; // ecx
  unsigned int j; // eax
  int uValidFrames; // ebp
  __int64 v16; // r12
  __int64 v17; // r14
  AKRESULT v18; // ecx

  uChannelMask = in_pBuffer->uChannelMask;
  v5 = 0i64;
  v7 = in_uInOffset;
  v9 = uChannelMask;
  for ( i = 0; v9; v9 &= v9 - 1 )
    ++i;
  v11 = out_pBuffer->uChannelMask;
  v12 = 0;
  v13 = v11;
  if ( !v11 )
    goto LABEL_9;
  do
  {
    ++v12;
    v13 &= v13 - 1;
  }
  while ( v13 );
  if ( i < v12 )
  {
    for ( j = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++j;
  }
  else
  {
LABEL_9:
    for ( j = 0; v11; v11 &= v11 - 1 )
      ++j;
  }
  uValidFrames = out_pBuffer->uMaxFrames - out_pBuffer->uValidFrames;
  if ( in_pBuffer->uValidFrames < uValidFrames )
    uValidFrames = in_pBuffer->uValidFrames;
  if ( j )
  {
    v16 = v7;
    v17 = j;
    do
    {
      memmove(
        (char *)out_pBuffer->pData + 4 * out_pBuffer->uValidFrames + 4 * v5 * out_pBuffer->uMaxFrames,
        (char *)in_pBuffer->pData + 4 * v16 + 4 * v5 * in_pBuffer->uMaxFrames,
        (unsigned int)(4 * uValidFrames));
      ++v5;
      --v17;
    }
    while ( v17 );
  }
  out_pBuffer->uValidFrames += uValidFrames;
  in_pBuffer->uValidFrames -= uValidFrames;
  if ( in_pBuffer->eState != AK_NoMoreData || in_pBuffer->uValidFrames )
  {
    v18 = AK_DataNeeded;
    if ( out_pBuffer->uValidFrames == out_pBuffer->uMaxFrames )
      v18 = AK_DataReady;
    out_pBuffer->eState = v18;
  }
  else
  {
    out_pBuffer->eState = AK_NoMoreData;
  }
}

// File Line: 287
// RVA: 0xAED300
__int64 __fastcall CAkTimeStretchFX::TimeSkip(CAkTimeStretchFX *this, unsigned int *io_uFrames)
{
  float v5; // xmm0_4
  float v6; // xmm2_4
  float m_fSkippedFrames; // xmm1_4
  float v8; // xmm0_4

  if ( !*io_uFrames )
    return 17i64;
  CAkTimeStretchFXParams::GetParams(this->m_pSharedParams, &this->m_FXInfo.Params);
  v5 = FLOAT_1600_0;
  v6 = this->m_FXInfo.fTSRandomOffset + this->m_FXInfo.Params.fTimeStretch;
  if ( v6 >= 1600.0 || (v5 = FLOAT_25_0, v6 <= 25.0) )
    v6 = v5;
  m_fSkippedFrames = this->m_fSkippedFrames;
  v8 = (float)((float)((float)(int)*io_uFrames * 100.0) / v6) + m_fSkippedFrames;
  this->m_fSkippedFrames = v8;
  *io_uFrames = (int)(float)(v8 - m_fSkippedFrames);
  return 45i64;
}

