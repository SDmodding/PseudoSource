// File Line: 28
// RVA: 0xAEA280
AK::IAkPlugin *__fastcall CreatePitchShifterFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 720i64);
  v2 = result;
  if ( result )
  {
    result[1].vfptr = 0i64;
    result->vfptr = (AK::IAkPluginVtbl *)&CAkPitchShifterFX::`vftable;
    result[2].vfptr = 0i64;
    AkPitchShifterFXInfo::AkPitchShifterFXInfo((AkPitchShifterFXInfo *)&result[3]);
    return v2;
  }
  return result;
}

// File Line: 37
// RVA: 0xAEA2E0
void __fastcall CAkPitchShifterFX::CAkPitchShifterFX(CAkPitchShifterFX *this)
{
  AkPitchShifterFXInfo *p_m_FXInfo; // rcx

  p_m_FXInfo = &this->m_FXInfo;
  *(_QWORD *)&p_m_FXInfo[-1].uNumProcessedChannels = &CAkPitchShifterFX::`vftable;
  *(_QWORD *)&p_m_FXInfo[-1].uTotalNumChannels = 0i64;
  *(_QWORD *)&p_m_FXInfo[-1].uTailLength = 0i64;
  AkPitchShifterFXInfo::AkPitchShifterFXInfo(p_m_FXInfo);
}

// File Line: 43
// RVA: 0xAEA320
void __fastcall CAkPitchShifterFX::~CAkPitchShifterFX(CAkPitchShifterFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 53
// RVA: 0xAEA340
AKRESULT __fastcall CAkPitchShifterFX::Init(
        CAkPitchShifterFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkPitchShifterFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  char v6; // al
  unsigned int v7; // ecx
  int i; // edx
  AKRESULT result; // eax

  this->m_pParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  v6 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v7 = 0;
  this->m_FXInfo.bSendMode = v6;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  this->m_FXInfo.uTotalNumChannels = v7;
  CAkPitchShifterFXParams::GetParams(this->m_pParams, &this->m_FXInfo.Params);
  if ( this->m_FXInfo.bSendMode )
    this->m_FXInfo.Params.fDryLevel = 0.0;
  this->m_FXInfo.PrevParams.Voice.Filter.eFilterType = this->m_FXInfo.Params.Voice.Filter.eFilterType;
  this->m_FXInfo.PrevParams.Voice.Filter.fFilterGain = this->m_FXInfo.Params.Voice.Filter.fFilterGain;
  this->m_FXInfo.PrevParams.Voice.Filter.fFilterFrequency = this->m_FXInfo.Params.Voice.Filter.fFilterFrequency;
  this->m_FXInfo.PrevParams.Voice.Filter.fFilterQFactor = this->m_FXInfo.Params.Voice.Filter.fFilterQFactor;
  this->m_FXInfo.PrevParams.Voice.fPitchFactor = this->m_FXInfo.Params.Voice.fPitchFactor;
  this->m_FXInfo.PrevParams.eInputType = this->m_FXInfo.Params.eInputType;
  this->m_FXInfo.PrevParams.fDryLevel = this->m_FXInfo.Params.fDryLevel;
  this->m_FXInfo.PrevParams.fWetLevel = this->m_FXInfo.Params.fWetLevel;
  this->m_FXInfo.PrevParams.fDelayTime = this->m_FXInfo.Params.fDelayTime;
  *(_DWORD *)&this->m_FXInfo.PrevParams.bProcessLFE = *(_DWORD *)&this->m_FXInfo.Params.bProcessLFE;
  this->m_FXInfo.uSampleRate = in_rFormat->uSampleRate;
  CAkPitchShifterFX::ComputeNumProcessedChannels(this, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
  this->m_FXInfo.uTailLength = (int)(float)((float)(this->m_FXInfo.Params.fDelayTime * 0.001)
                                          * (float)(int)this->m_FXInfo.uSampleRate);
  result = CAkPitchShifterFX::InitPitchVoice(this);
  if ( result == AK_Success )
  {
    result = CAkPitchShifterFX::InitDryDelay(this);
    if ( result == AK_Success )
    {
      this->m_pParams->m_ParamChangeHandler = 0;
      return 1;
    }
  }
  return result;
}

// File Line: 85
// RVA: 0xAEA7E0
void __fastcall CAkPitchShifterFX::ComputeNumProcessedChannels(CAkPitchShifterFX *this, unsigned int in_eChannelMask)
{
  char v2; // r10
  unsigned int v3; // eax
  bool v4; // zf
  unsigned int v5; // r8d
  unsigned int v6; // edx
  unsigned int i; // edx
  unsigned int j; // edx
  unsigned int k; // edx
  unsigned int m; // edx
  unsigned int n; // edx

  v2 = in_eChannelMask;
  switch ( this->m_FXInfo.Params.eInputType )
  {
    case AKINPUTTYPE_ASINPUT:
      v3 = 0;
      v4 = (in_eChannelMask & 0xFFFFFFF7) == 0;
      v5 = in_eChannelMask & 0xFFFFFFF7;
      v6 = in_eChannelMask & 0xFFFFFFF7;
      if ( !v4 )
      {
        do
        {
          ++v3;
          v6 &= v6 - 1;
        }
        while ( v6 );
      }
      this->m_FXInfo.eProcessChannelMask = v5;
      goto LABEL_20;
    case AKINPUTTYPE_CENTER:
      v3 = 0;
      for ( i = in_eChannelMask & 4; i; i &= i - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 4;
      goto LABEL_20;
    case AKINPUTTYPE_STEREO:
      v3 = 0;
      for ( j = in_eChannelMask & 3; j; j &= j - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 3;
      goto LABEL_20;
    case AKINPUTCHANNELTYPE_3POINT0:
      v3 = 0;
      for ( k = in_eChannelMask & 7; k; k &= k - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 7;
      goto LABEL_20;
    case AKINPUTTYPE_4POINT0:
      v3 = 0;
      for ( m = in_eChannelMask & 0x33; m; m &= m - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 51;
      goto LABEL_20;
    case AKINPUTTYPE_5POINT0:
      v3 = 0;
      for ( n = in_eChannelMask & 0x37; n; n &= n - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 55;
LABEL_20:
      this->m_FXInfo.uNumProcessedChannels = v3;
      break;
    default:
      break;
  }
  if ( this->m_FXInfo.Params.bProcessLFE && (v2 & 8) != 0 )
  {
    ++this->m_FXInfo.uNumProcessedChannels;
    this->m_FXInfo.eProcessChannelMask |= 8u;
  }
}

// File Line: 122
// RVA: 0xAEA920
void __fastcall CAkPitchShifterFX::ComputeTailLength(CAkPitchShifterFX *this)
{
  this->m_FXInfo.uTailLength = (int)(float)((float)(this->m_FXInfo.Params.fDelayTime * 0.001)
                                          * (float)(int)this->m_FXInfo.uSampleRate);
}

// File Line: 127
// RVA: 0xAEA960
AKRESULT __fastcall CAkPitchShifterFX::InitPitchVoice(CAkPitchShifterFX *this)
{
  unsigned int uNumProcessedChannels; // r9d
  AKRESULT result; // eax
  AkFilterType eFilterType; // edx

  uNumProcessedChannels = this->m_FXInfo.uNumProcessedChannels;
  if ( uNumProcessedChannels )
  {
    result = AK::DSP::AkDelayPitchShift::Init(
               &this->m_FXInfo.PitchShifter,
               this->m_pAllocator,
               this->m_FXInfo.Params.fDelayTime,
               uNumProcessedChannels,
               this->m_FXInfo.uSampleRate);
    if ( result != AK_Success )
      return result;
    AK::DSP::AkDelayPitchShift::SetPitchFactor(&this->m_FXInfo.PitchShifter, this->m_FXInfo.Params.Voice.fPitchFactor);
    eFilterType = this->m_FXInfo.Params.Voice.Filter.eFilterType;
    if ( eFilterType )
      AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
        &this->m_FXInfo.Filter,
        (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(eFilterType - 1),
        this->m_FXInfo.uSampleRate,
        this->m_FXInfo.Params.Voice.Filter.fFilterFrequency,
        this->m_FXInfo.Params.Voice.Filter.fFilterGain,
        this->m_FXInfo.Params.Voice.Filter.fFilterQFactor);
  }
  return 1;
}

// File Line: 150
// RVA: 0xAEAA10
void __fastcall CAkPitchShifterFX::TermPitchVoice(CAkPitchShifterFX *this)
{
  if ( this->m_FXInfo.uNumProcessedChannels )
    AK::DSP::AkDelayPitchShift::Term(&this->m_FXInfo.PitchShifter, this->m_pAllocator);
}

// File Line: 156
// RVA: 0xAEAA40
void __fastcall CAkPitchShifterFX::ResetPitchVoice(CAkPitchShifterFX *this)
{
  if ( this->m_FXInfo.uNumProcessedChannels )
  {
    AK::DSP::AkDelayPitchShift::Reset(&this->m_FXInfo.PitchShifter);
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[0].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[0].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[1].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[1].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[2].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[2].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[3].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[3].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[4].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[4].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[5].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[5].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[6].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[6].fFFwd1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[7].fFFbk1 = 0i64;
    *(_QWORD *)&this->m_FXInfo.Filter.m_Memories[7].fFFwd1 = 0i64;
  }
}

// File Line: 165
// RVA: 0xAEAAE0
AKRESULT __fastcall CAkPitchShifterFX::InitDryDelay(CAkPitchShifterFX *this)
{
  unsigned int v2; // esi
  __int64 v3; // rbx
  AKRESULT result; // eax

  v2 = this->m_FXInfo.uTailLength >> 1;
  if ( !this->m_FXInfo.Params.bSyncDry )
    return 1;
  v3 = 0i64;
  if ( !this->m_FXInfo.uTotalNumChannels )
    return 1;
  while ( 1 )
  {
    result = DSP::CDelayLight::Init(
               (DSP::CDelayLight *)((char *)this->m_FXInfo.DryDelay + 16 * v3 + 8 * v3),
               this->m_pAllocator,
               v2);
    if ( result != AK_Success )
      break;
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= this->m_FXInfo.uTotalNumChannels )
      return 1;
  }
  return result;
}

// File Line: 180
// RVA: 0xAEAB60
void __fastcall CAkPitchShifterFX::TermDryDelay(CAkPitchShifterFX *this)
{
  __int64 i; // rbx

  for ( i = 0i64; (unsigned int)i < this->m_FXInfo.uTotalNumChannels; i = (unsigned int)(i + 1) )
    DSP::CDelayLight::Term((DSP::CDelayLight *)((char *)this->m_FXInfo.DryDelay + 16 * i + 8 * i), this->m_pAllocator);
}

// File Line: 186
// RVA: 0xAEABB0
void __fastcall CAkPitchShifterFX::ResetDryDelay(CAkPitchShifterFX *this)
{
  __int64 i; // rbx

  for ( i = 0i64; (unsigned int)i < this->m_FXInfo.uTotalNumChannels; i = (unsigned int)(i + 1) )
    DSP::CDelayLight::Reset((DSP::CDelayLight *)((char *)this->m_FXInfo.DryDelay + 16 * i + 8 * i));
}

// File Line: 193
// RVA: 0xAEA4A0
__int64 __fastcall CAkPitchShifterFX::Term(CAkPitchShifterFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  __int64 i; // rdi

  if ( this->m_FXInfo.uNumProcessedChannels )
    AK::DSP::AkDelayPitchShift::Term(&this->m_FXInfo.PitchShifter, this->m_pAllocator);
  for ( i = 0i64; (unsigned int)i < this->m_FXInfo.uTotalNumChannels; i = (unsigned int)(i + 1) )
    DSP::CDelayLight::Term((DSP::CDelayLight *)((char *)this->m_FXInfo.DryDelay + 16 * i + 8 * i), this->m_pAllocator);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 202
// RVA: 0xAEA530
__int64 __fastcall CAkPitchShifterFX::Reset(CAkPitchShifterFX *this)
{
  __int64 i; // rbx

  CAkPitchShifterFX::ResetPitchVoice(this);
  for ( i = 0i64; (unsigned int)i < this->m_FXInfo.uTotalNumChannels; i = (unsigned int)(i + 1) )
    DSP::CDelayLight::Reset((DSP::CDelayLight *)((char *)this->m_FXInfo.DryDelay + 16 * i + 8 * i));
  return 1i64;
}

// File Line: 211
// RVA: 0xAEA590
__int64 __fastcall CAkPitchShifterFX::GetPluginInfo(CAkPitchShifterFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 228
// RVA: 0xAEA5B0
void __fastcall CAkPitchShifterFX::Execute(CAkPitchShifterFX *this, AkAudioBuffer *io_pBuffer)
{
  float *v4; // rsi
  CAkPitchShifterFXParams *m_pParams; // rdx
  int v6; // ecx
  char v7; // al
  unsigned int i; // edi
  CAkPitchShifterFXParams *v9; // rax
  char v10; // al
  AkFilterType eFilterType; // edx

  CAkPitchShifterFXParams::GetParams(this->m_pParams, &this->m_FXInfo.Params);
  v4 = 0i64;
  if ( this->m_FXInfo.bSendMode )
    this->m_FXInfo.Params.fDryLevel = 0.0;
  m_pParams = this->m_pParams;
  v6 = 0;
  while ( !m_pParams->m_ParamChangeHandler.m_uParamBitArray[v6] )
  {
    if ( (unsigned int)++v6 >= 2 )
      goto LABEL_28;
  }
  v7 = m_pParams->m_ParamChangeHandler.m_uParamBitArray[0];
  if ( (v7 & 0x20) == 0 && (v7 & 1) == 0 && (v7 & 2) == 0 )
  {
LABEL_17:
    if ( (this->m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] & 4) != 0 )
    {
      CAkPitchShifterFX::TermDryDelay(this);
      if ( CAkPitchShifterFX::InitDryDelay(this) != AK_Success )
        return;
      CAkPitchShifterFX::ResetDryDelay(this);
    }
    if ( (this->m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] & 0x40) != 0 )
      AK::DSP::AkDelayPitchShift::SetPitchFactor(&this->m_FXInfo.PitchShifter, this->m_FXInfo.Params.Voice.fPitchFactor);
    v9 = this->m_pParams;
    if ( v9->m_ParamChangeHandler.m_uParamBitArray[0] < 0
      || (v10 = v9->m_ParamChangeHandler.m_uParamBitArray[1], (v10 & 2) != 0)
      || (v10 & 1) != 0
      || (v10 & 4) != 0 )
    {
      eFilterType = this->m_FXInfo.Params.Voice.Filter.eFilterType;
      if ( eFilterType )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          &this->m_FXInfo.Filter,
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(eFilterType - 1),
          this->m_FXInfo.uSampleRate,
          this->m_FXInfo.Params.Voice.Filter.fFilterFrequency,
          this->m_FXInfo.Params.Voice.Filter.fFilterGain,
          this->m_FXInfo.Params.Voice.Filter.fFilterQFactor);
    }
LABEL_28:
    this->m_pParams->m_ParamChangeHandler = 0;
    if ( !this->m_FXInfo.uNumProcessedChannels
      || (v4 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 4i64 * io_pBuffer->uMaxFrames)) != 0i64 )
    {
      AkPitchShifterDSPProcess(io_pBuffer, &this->m_FXInfo, v4, 0i64);
      if ( v4 )
        this->m_pAllocator->vfptr->Free(this->m_pAllocator, v4);
    }
    return;
  }
  if ( this->m_FXInfo.uNumProcessedChannels )
    AK::DSP::AkDelayPitchShift::Term(&this->m_FXInfo.PitchShifter, this->m_pAllocator);
  for ( i = 0; i < this->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Term((DSP::CDelayLight *)((char *)this->m_FXInfo.DryDelay + 16 * i + 8 * i), this->m_pAllocator);
  this->m_FXInfo.uTailLength = (int)(float)((float)(this->m_FXInfo.Params.fDelayTime * 0.001)
                                          * (float)(int)this->m_FXInfo.uSampleRate);
  CAkPitchShifterFX::ComputeNumProcessedChannels(this, io_pBuffer->uChannelMask);
  if ( CAkPitchShifterFX::InitPitchVoice(this) == AK_Success && CAkPitchShifterFX::InitDryDelay(this) == AK_Success )
  {
    CAkPitchShifterFX::ResetPitchVoice(this);
    CAkPitchShifterFX::ResetDryDelay(this);
    goto LABEL_17;
  }
}

