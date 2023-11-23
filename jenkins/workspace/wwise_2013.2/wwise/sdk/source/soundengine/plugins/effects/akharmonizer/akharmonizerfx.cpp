// File Line: 27
// RVA: 0xAF7190
AK::IAkPlugin *__fastcall CreateHarmonizerFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 3160i64);
  v2 = result;
  if ( result )
  {
    result[1].vfptr = 0i64;
    result->vfptr = (AK::IAkPluginVtbl *)&CAkHarmonizerFX::`vftable;
    result[2].vfptr = 0i64;
    AkHarmonizerFXInfo::AkHarmonizerFXInfo((AkHarmonizerFXInfo *)&result[3]);
    return v2;
  }
  return result;
}

// File Line: 36
// RVA: 0xAF71F0
void __fastcall CAkHarmonizerFX::CAkHarmonizerFX(CAkHarmonizerFX *this)
{
  AkHarmonizerFXInfo *p_m_FXInfo; // rcx

  p_m_FXInfo = &this->m_FXInfo;
  *(_QWORD *)&p_m_FXInfo[-1].uNumProcessedChannels = &CAkHarmonizerFX::`vftable;
  *(_QWORD *)&p_m_FXInfo[-1].uTotalNumChannels = 0i64;
  *(_QWORD *)&p_m_FXInfo[-1].bWetPathEnabled = 0i64;
  AkHarmonizerFXInfo::AkHarmonizerFXInfo(p_m_FXInfo);
}

// File Line: 42
// RVA: 0xAF7230
void __fastcall CAkHarmonizerFX::~CAkHarmonizerFX(CAkHarmonizerFX *this)
{
  AK::DSP::MultiChannelBiquadFilter<8> *Filter; // rbx
  int i; // edi

  Filter = this->m_FXInfo.Filter;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkHarmonizerFX::`vftable;
  for ( i = 1; i >= 0; --i )
  {
    Filter = (AK::DSP::MultiChannelBiquadFilter<8> *)((char *)Filter - 1232);
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::~CAkPhaseVocoder((DSP::AkFFTAllButterflies::CAkPhaseVocoder *)Filter);
  }
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 52
// RVA: 0xAF72A0
AKRESULT __fastcall CAkHarmonizerFX::Init(
        CAkHarmonizerFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkHarmonizerFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  bool v6; // si
  unsigned int v7; // edx
  int i; // ecx
  CAkHarmonizerFXParams *m_pParams; // rcx
  int v10; // edi
  AKRESULT result; // eax
  CAkHarmonizerFXParams *v12; // rcx

  this->m_pParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  v6 = 0;
  this->m_FXInfo.bSendMode = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v7 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  m_pParams = this->m_pParams;
  this->m_FXInfo.uTotalNumChannels = v7;
  CAkHarmonizerFXParams::GetParams(m_pParams, &this->m_FXInfo.Params);
  if ( this->m_FXInfo.bSendMode )
    this->m_FXInfo.Params.fDryLevel = 0.0;
  this->m_FXInfo.PrevParams.Voice[0].Filter.eFilterType = this->m_FXInfo.Params.Voice[0].Filter.eFilterType;
  this->m_FXInfo.PrevParams.Voice[0].Filter.fFilterGain = this->m_FXInfo.Params.Voice[0].Filter.fFilterGain;
  this->m_FXInfo.PrevParams.Voice[0].Filter.fFilterFrequency = this->m_FXInfo.Params.Voice[0].Filter.fFilterFrequency;
  this->m_FXInfo.PrevParams.Voice[0].Filter.fFilterQFactor = this->m_FXInfo.Params.Voice[0].Filter.fFilterQFactor;
  this->m_FXInfo.PrevParams.Voice[0].fPitchFactor = this->m_FXInfo.Params.Voice[0].fPitchFactor;
  this->m_FXInfo.PrevParams.Voice[0].fGain = this->m_FXInfo.Params.Voice[0].fGain;
  *(_DWORD *)&this->m_FXInfo.PrevParams.Voice[0].bEnable = *(_DWORD *)&this->m_FXInfo.Params.Voice[0].bEnable;
  this->m_FXInfo.PrevParams.Voice[1].Filter.eFilterType = this->m_FXInfo.Params.Voice[1].Filter.eFilterType;
  this->m_FXInfo.PrevParams.Voice[1].Filter.fFilterGain = this->m_FXInfo.Params.Voice[1].Filter.fFilterGain;
  this->m_FXInfo.PrevParams.Voice[1].Filter.fFilterFrequency = this->m_FXInfo.Params.Voice[1].Filter.fFilterFrequency;
  this->m_FXInfo.PrevParams.Voice[1].Filter.fFilterQFactor = this->m_FXInfo.Params.Voice[1].Filter.fFilterQFactor;
  this->m_FXInfo.PrevParams.Voice[1].fPitchFactor = this->m_FXInfo.Params.Voice[1].fPitchFactor;
  this->m_FXInfo.PrevParams.Voice[1].fGain = this->m_FXInfo.Params.Voice[1].fGain;
  *(_DWORD *)&this->m_FXInfo.PrevParams.Voice[1].bEnable = *(_DWORD *)&this->m_FXInfo.Params.Voice[1].bEnable;
  this->m_FXInfo.PrevParams.eInputType = this->m_FXInfo.Params.eInputType;
  this->m_FXInfo.PrevParams.fDryLevel = this->m_FXInfo.Params.fDryLevel;
  this->m_FXInfo.PrevParams.fWetLevel = this->m_FXInfo.Params.fWetLevel;
  this->m_FXInfo.PrevParams.uWindowSize = this->m_FXInfo.Params.uWindowSize;
  *(_DWORD *)&this->m_FXInfo.PrevParams.bProcessLFE = *(_DWORD *)&this->m_FXInfo.Params.bProcessLFE;
  this->m_FXInfo.uSampleRate = in_rFormat->uSampleRate;
  v10 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  CAkHarmonizerFX::ComputeNumProcessedChannels(this, v10);
  if ( (this->m_FXInfo.Params.Voice[1].bEnable || this->m_FXInfo.Params.Voice[0].bEnable)
    && (v10 & this->m_FXInfo.eProcessChannelMask) != 0 )
  {
    v6 = 1;
  }
  this->m_FXInfo.bWetPathEnabled = v6;
  result = CAkHarmonizerFX::InitPitchVoices(this);
  if ( result == AK_Success )
  {
    result = CAkHarmonizerFX::InitDryDelay(this);
    if ( result == AK_Success )
    {
      v12 = this->m_pParams;
      result = AK_Success;
      *(_WORD *)v12->m_ParamChangeHandler.m_uParamBitArray = 0;
      v12->m_ParamChangeHandler.m_uParamBitArray[2] = 0;
    }
  }
  return result;
}

// File Line: 84
// RVA: 0xAF78B0
void __fastcall CAkHarmonizerFX::ComputeNumProcessedChannels(CAkHarmonizerFX *this, unsigned int in_eChannelMask)
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
  unsigned int ii; // edx

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
      goto LABEL_23;
    case AKINPUTTYPE_CENTER:
      v3 = 0;
      for ( i = in_eChannelMask & 4; i; i &= i - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 4;
      goto LABEL_23;
    case AKINPUTTYPE_STEREO:
      v3 = 0;
      for ( j = in_eChannelMask & 3; j; j &= j - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 3;
      goto LABEL_23;
    case AKINPUTCHANNELTYPE_3POINT0:
      v3 = 0;
      for ( k = in_eChannelMask & 7; k; k &= k - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 7;
      goto LABEL_23;
    case AKINPUTTYPE_4POINT0:
      v3 = 0;
      for ( m = in_eChannelMask & 0x33; m; m &= m - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 51;
      goto LABEL_23;
    case AKINPUTTYPE_5POINT0:
      v3 = 0;
      for ( n = in_eChannelMask & 0x37; n; n &= n - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 55;
      goto LABEL_23;
    case AKINPUTTYPE_4POINT0|AKINPUTTYPE_STEREO:
      v3 = 0;
      for ( ii = in_eChannelMask & 1; ii; ii &= ii - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 1;
LABEL_23:
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

// File Line: 125
// RVA: 0xAF7A20
void __fastcall CAkHarmonizerFX::ComputeWetPathEnabled(CAkHarmonizerFX *this, unsigned int in_eChannelMask)
{
  this->m_FXInfo.bWetPathEnabled = (this->m_FXInfo.Params.Voice[1].bEnable || this->m_FXInfo.Params.Voice[0].bEnable)
                                && (in_eChannelMask & this->m_FXInfo.eProcessChannelMask) != 0;
}

// File Line: 136
// RVA: 0xAF7A70
AKRESULT __fastcall CAkHarmonizerFX::InitPitchVoices(CAkHarmonizerFX *this)
{
  unsigned int v2; // edi
  float *p_fFilterQFactor; // rbx
  AKRESULT result; // eax
  int v5; // edx

  v2 = 0;
  p_fFilterQFactor = &this->m_FXInfo.Params.Voice[0].Filter.fFilterQFactor;
  do
  {
    if ( *((_BYTE *)p_fFilterQFactor + 12) )
    {
      result = DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Init(
                 &this->m_FXInfo.PhaseVocoder[v2],
                 this->m_pAllocator,
                 this->m_FXInfo.uNumProcessedChannels,
                 this->m_FXInfo.uSampleRate,
                 this->m_FXInfo.Params.uWindowSize,
                 0);
      if ( result != AK_Success )
        return result;
      v5 = *((_DWORD *)p_fFilterQFactor - 3);
      if ( v5 )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          &this->m_FXInfo.Filter[v2],
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v5 - 1),
          this->m_FXInfo.uSampleRate,
          *(p_fFilterQFactor - 1),
          *(p_fFilterQFactor - 2),
          *p_fFilterQFactor);
    }
    ++v2;
    p_fFilterQFactor += 7;
  }
  while ( v2 < 2 );
  return 1;
}

// File Line: 166
// RVA: 0xAF7B50
void __fastcall CAkHarmonizerFX::TermPitchVoices(CAkHarmonizerFX *this)
{
  AkHarmonizerFXInfo *p_m_FXInfo; // rbx
  __int64 v3; // rdi

  p_m_FXInfo = &this->m_FXInfo;
  v3 = 2i64;
  do
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(p_m_FXInfo->PhaseVocoder, this->m_pAllocator);
    p_m_FXInfo = (AkHarmonizerFXInfo *)((char *)p_m_FXInfo + 1232);
    --v3;
  }
  while ( v3 );
}

// File Line: 174
// RVA: 0xAF7BA0
void __fastcall CAkHarmonizerFX::ResetPitchVoices(CAkHarmonizerFX *this)
{
  bool *p_bEnable; // rbp
  float *p_fFFbk1; // rdi
  unsigned int i; // esi
  __int64 v5; // rbx

  p_bEnable = &this->m_FXInfo.Params.Voice[0].bEnable;
  p_fFFbk1 = &this->m_FXInfo.Filter[0].m_Memories[0].fFFbk1;
  for ( i = 0; i < 2; ++i )
  {
    if ( *p_bEnable )
    {
      v5 = i;
      DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Reset(&this->m_FXInfo.PhaseVocoder[v5]);
      DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ResetInputFill(&this->m_FXInfo.PhaseVocoder[v5]);
      *(_QWORD *)p_fFFbk1 = 0i64;
      *((_QWORD *)p_fFFbk1 - 1) = 0i64;
      *((_QWORD *)p_fFFbk1 + 2) = 0i64;
      *((_QWORD *)p_fFFbk1 + 1) = 0i64;
      *((_QWORD *)p_fFFbk1 + 4) = 0i64;
      *((_QWORD *)p_fFFbk1 + 3) = 0i64;
      *((_QWORD *)p_fFFbk1 + 6) = 0i64;
      *((_QWORD *)p_fFFbk1 + 5) = 0i64;
      *((_QWORD *)p_fFFbk1 + 8) = 0i64;
      *((_QWORD *)p_fFFbk1 + 7) = 0i64;
      *((_QWORD *)p_fFFbk1 + 10) = 0i64;
      *((_QWORD *)p_fFFbk1 + 9) = 0i64;
      *((_QWORD *)p_fFFbk1 + 12) = 0i64;
      *((_QWORD *)p_fFFbk1 + 11) = 0i64;
      *((_QWORD *)p_fFFbk1 + 14) = 0i64;
      *((_QWORD *)p_fFFbk1 + 13) = 0i64;
    }
    p_bEnable += 28;
    p_fFFbk1 += 37;
  }
}

// File Line: 187
// RVA: 0xAF7C70
__int64 __fastcall CAkHarmonizerFX::InitDryDelay(CAkHarmonizerFX *this)
{
  unsigned int uWindowSize; // esi
  int v3; // ebx
  __int64 result; // rax

  uWindowSize = this->m_FXInfo.Params.uWindowSize;
  if ( !this->m_FXInfo.Params.bSyncDry )
    return 1i64;
  if ( !this->m_FXInfo.bWetPathEnabled )
    return 1i64;
  v3 = 0;
  if ( !this->m_FXInfo.uTotalNumChannels )
    return 1i64;
  while ( 1 )
  {
    result = DSP::CDelayLight::Init(&this->m_FXInfo.DryDelay[v3], this->m_pAllocator, uWindowSize);
    if ( (_DWORD)result != 1 )
      break;
    if ( ++v3 >= this->m_FXInfo.uTotalNumChannels )
      return 1i64;
  }
  return result;
}

// File Line: 202
// RVA: 0xAF7D00
void __fastcall CAkHarmonizerFX::TermDryDelay(CAkHarmonizerFX *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Term(&this->m_FXInfo.DryDelay[i], this->m_pAllocator);
}

// File Line: 210
// RVA: 0xAF7D60
void __fastcall CAkHarmonizerFX::ResetDryDelay(CAkHarmonizerFX *this)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Reset(&this->m_FXInfo.DryDelay[i]);
}

// File Line: 217
// RVA: 0xAF7470
__int64 __fastcall CAkHarmonizerFX::Term(CAkHarmonizerFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AkHarmonizerFXInfo *p_m_FXInfo; // rdi
  __int64 v5; // rsi
  unsigned int i; // edi

  p_m_FXInfo = &this->m_FXInfo;
  v5 = 2i64;
  do
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(p_m_FXInfo->PhaseVocoder, this->m_pAllocator);
    p_m_FXInfo = (AkHarmonizerFXInfo *)((char *)p_m_FXInfo + 1232);
    --v5;
  }
  while ( v5 );
  for ( i = 0; i < this->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Term(&this->m_FXInfo.DryDelay[i], this->m_pAllocator);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 226
// RVA: 0xAF7520
__int64 __fastcall CAkHarmonizerFX::Reset(CAkHarmonizerFX *this)
{
  unsigned int i; // ebx

  CAkHarmonizerFX::ResetPitchVoices(this);
  for ( i = 0; i < this->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Reset(&this->m_FXInfo.DryDelay[i]);
  return 1i64;
}

// File Line: 235
// RVA: 0xAF7580
__int64 __fastcall CAkHarmonizerFX::GetPluginInfo(CAkHarmonizerFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 251
// RVA: 0xAF75A0
void __fastcall CAkHarmonizerFX::Execute(CAkHarmonizerFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int v4; // esi
  CAkHarmonizerFXParams *m_pParams; // rdx
  int v6; // ecx
  __int64 v7; // r14
  AkHarmonizerFXInfo *p_m_FXInfo; // rdi
  __int64 v9; // rbp
  CAkHarmonizerFXParams *v10; // rcx
  char v11; // al
  AkHarmonizerFXInfo *v12; // rdi
  unsigned int i; // edi
  char v14; // cl
  bool v15; // al
  char v16; // cl
  AkFilterType eFilterType; // edx
  char v18; // cl
  AkFilterType v19; // edx
  CAkHarmonizerFXParams *v20; // rax
  float *v21; // rax
  float *v22; // rdi

  CAkHarmonizerFXParams::GetParams(this->m_pParams, &this->m_FXInfo.Params);
  v4 = 0;
  if ( this->m_FXInfo.bSendMode )
    this->m_FXInfo.Params.fDryLevel = 0.0;
  m_pParams = this->m_pParams;
  v6 = 0;
  while ( !m_pParams->m_ParamChangeHandler.m_uParamBitArray[v6] )
  {
    if ( (unsigned int)++v6 >= 3 )
      goto LABEL_46;
  }
  v7 = 2i64;
  if ( m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] < 0
    || (m_pParams->m_ParamChangeHandler.m_uParamBitArray[1] & 0x40) != 0 )
  {
    p_m_FXInfo = &this->m_FXInfo;
    v9 = 2i64;
    do
    {
      DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(p_m_FXInfo->PhaseVocoder, this->m_pAllocator);
      p_m_FXInfo = (AkHarmonizerFXInfo *)((char *)p_m_FXInfo + 1232);
      --v9;
    }
    while ( v9 );
    if ( CAkHarmonizerFX::InitPitchVoices(this) != AK_Success )
      return;
    CAkHarmonizerFX::ResetPitchVoices(this);
  }
  v10 = this->m_pParams;
  v11 = v10->m_ParamChangeHandler.m_uParamBitArray[0];
  if ( (v11 & 0x20) == 0
    && (v11 & 0x40) == 0
    && (v10->m_ParamChangeHandler.m_uParamBitArray[1] & 0x20) == 0
    && (v11 & 1) == 0
    && (v11 & 2) == 0 )
  {
LABEL_31:
    if ( (this->m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] & 4) != 0 )
    {
      CAkHarmonizerFX::TermDryDelay(this);
      if ( CAkHarmonizerFX::InitDryDelay(this) != AK_Success )
        return;
      CAkHarmonizerFX::ResetDryDelay(this);
    }
    v16 = this->m_pParams->m_ParamChangeHandler.m_uParamBitArray[1];
    if ( (v16 & 2) != 0 || (v16 & 8) != 0 || (v16 & 4) != 0 || (v16 & 0x10) != 0 )
    {
      eFilterType = this->m_FXInfo.Params.Voice[0].Filter.eFilterType;
      if ( eFilterType )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          this->m_FXInfo.Filter,
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(eFilterType - 1),
          this->m_FXInfo.uSampleRate,
          this->m_FXInfo.Params.Voice[0].Filter.fFilterFrequency,
          this->m_FXInfo.Params.Voice[0].Filter.fFilterGain,
          this->m_FXInfo.Params.Voice[0].Filter.fFilterQFactor);
    }
    v18 = this->m_pParams->m_ParamChangeHandler.m_uParamBitArray[2];
    if ( (v18 & 1) != 0 || (v18 & 4) != 0 || (v18 & 2) != 0 || (v18 & 8) != 0 )
    {
      v19 = this->m_FXInfo.Params.Voice[1].Filter.eFilterType;
      if ( v19 )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          &this->m_FXInfo.Filter[1],
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v19 - 1),
          this->m_FXInfo.uSampleRate,
          this->m_FXInfo.Params.Voice[1].Filter.fFilterFrequency,
          this->m_FXInfo.Params.Voice[1].Filter.fFilterGain,
          this->m_FXInfo.Params.Voice[1].Filter.fFilterQFactor);
    }
LABEL_46:
    v20 = this->m_pParams;
    *(_WORD *)v20->m_ParamChangeHandler.m_uParamBitArray = 0;
    v20->m_ParamChangeHandler.m_uParamBitArray[2] = 0;
    if ( this->m_FXInfo.Params.Voice[0].bEnable )
      v4 = 4 * this->m_FXInfo.PhaseVocoder[0].m_uFFTSize;
    if ( this->m_FXInfo.Params.Voice[1].bEnable )
      v4 = 4 * this->m_FXInfo.PhaseVocoder[1].m_uFFTSize;
    v21 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v4 + 8 * io_pBuffer->uMaxFrames);
    v22 = v21;
    if ( v21 )
    {
      AkHarmonizerDSPProcess(io_pBuffer, &this->m_FXInfo, v21);
      this->m_pAllocator->vfptr->Free(this->m_pAllocator, v22);
    }
    return;
  }
  v12 = &this->m_FXInfo;
  do
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(v12->PhaseVocoder, this->m_pAllocator);
    v12 = (AkHarmonizerFXInfo *)((char *)v12 + 1232);
    --v7;
  }
  while ( v7 );
  for ( i = 0; i < this->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Term(&this->m_FXInfo.DryDelay[i], this->m_pAllocator);
  CAkHarmonizerFX::ComputeNumProcessedChannels(this, io_pBuffer->uChannelMask);
  v14 = 0;
  v15 = 1;
  if ( this->m_FXInfo.Params.Voice[0].bEnable )
    v14 = 1;
  if ( !this->m_FXInfo.Params.Voice[1].bEnable && !v14
    || (io_pBuffer->uChannelMask & this->m_FXInfo.eProcessChannelMask) == 0 )
  {
    v15 = 0;
  }
  this->m_FXInfo.bWetPathEnabled = v15;
  if ( CAkHarmonizerFX::InitPitchVoices(this) == AK_Success && CAkHarmonizerFX::InitDryDelay(this) == AK_Success )
  {
    CAkHarmonizerFX::ResetPitchVoices(this);
    CAkHarmonizerFX::ResetDryDelay(this);
    goto LABEL_31;
  }
}

