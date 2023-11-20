// File Line: 27
// RVA: 0xAF7190
AK::IAkPlugin *__fastcall CreateHarmonizerFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 3160ui64);
  v2 = result;
  if ( result )
  {
    result[1].vfptr = 0i64;
    result->vfptr = (AK::IAkPluginVtbl *)&CAkHarmonizerFX::`vftable;
    result[2].vfptr = 0i64;
    AkHarmonizerFXInfo::AkHarmonizerFXInfo((AkHarmonizerFXInfo *)&result[3]);
    result = v2;
  }
  return result;
}

// File Line: 36
// RVA: 0xAF71F0
void __fastcall CAkHarmonizerFX::CAkHarmonizerFX(CAkHarmonizerFX *this)
{
  AkHarmonizerFXInfo *v1; // rcx

  v1 = &this->m_FXInfo;
  *(_QWORD *)&v1[-1].uNumProcessedChannels = &CAkHarmonizerFX::`vftable;
  *(_QWORD *)&v1[-1].uTotalNumChannels = 0i64;
  *(_QWORD *)&v1[-1].bWetPathEnabled = 0i64;
  AkHarmonizerFXInfo::AkHarmonizerFXInfo(v1);
}

// File Line: 42
// RVA: 0xAF7230
void __fastcall CAkHarmonizerFX::~CAkHarmonizerFX(CAkHarmonizerFX *this)
{
  CAkHarmonizerFX *v1; // rsi
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v2; // rbx
  signed int v3; // edi

  v1 = this;
  v2 = (DSP::AkFFTAllButterflies::CAkPhaseVocoder *)this->m_FXInfo.Filter;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkHarmonizerFX::`vftable;
  v3 = 1;
  do
  {
    v2 = (DSP::AkFFTAllButterflies::CAkPhaseVocoder *)((char *)v2 - 1232);
    DSP::AkFFTAllButterflies::CAkPhaseVocoder::~CAkPhaseVocoder(v2);
    --v3;
  }
  while ( v3 >= 0 );
  v1->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 52
// RVA: 0xAF72A0
AKRESULT __fastcall CAkHarmonizerFX::Init(CAkHarmonizerFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkHarmonizerFX *v5; // rbx
  char v6; // si
  unsigned int v7; // edx
  int i; // ecx
  CAkHarmonizerFXParams *v9; // rcx
  int v10; // edi
  char v11; // al
  AKRESULT result; // eax
  CAkHarmonizerFXParams *v13; // rcx

  this->m_pParams = (CAkHarmonizerFXParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  v5 = this;
  v6 = 0;
  this->m_FXInfo.bSendMode = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v7 = 0;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  v9 = v5->m_pParams;
  v5->m_FXInfo.uTotalNumChannels = v7;
  CAkHarmonizerFXParams::GetParams(v9, &v5->m_FXInfo.Params);
  if ( v5->m_FXInfo.bSendMode )
    v5->m_FXInfo.Params.fDryLevel = 0.0;
  v5->m_FXInfo.PrevParams.Voice[0].Filter.eFilterType = v5->m_FXInfo.Params.Voice[0].Filter.eFilterType;
  v5->m_FXInfo.PrevParams.Voice[0].Filter.fFilterGain = v5->m_FXInfo.Params.Voice[0].Filter.fFilterGain;
  v5->m_FXInfo.PrevParams.Voice[0].Filter.fFilterFrequency = v5->m_FXInfo.Params.Voice[0].Filter.fFilterFrequency;
  v5->m_FXInfo.PrevParams.Voice[0].Filter.fFilterQFactor = v5->m_FXInfo.Params.Voice[0].Filter.fFilterQFactor;
  v5->m_FXInfo.PrevParams.Voice[0].fPitchFactor = v5->m_FXInfo.Params.Voice[0].fPitchFactor;
  v5->m_FXInfo.PrevParams.Voice[0].fGain = v5->m_FXInfo.Params.Voice[0].fGain;
  *(_DWORD *)&v5->m_FXInfo.PrevParams.Voice[0].bEnable = *(_DWORD *)&v5->m_FXInfo.Params.Voice[0].bEnable;
  v5->m_FXInfo.PrevParams.Voice[1].Filter.eFilterType = v5->m_FXInfo.Params.Voice[1].Filter.eFilterType;
  v5->m_FXInfo.PrevParams.Voice[1].Filter.fFilterGain = v5->m_FXInfo.Params.Voice[1].Filter.fFilterGain;
  v5->m_FXInfo.PrevParams.Voice[1].Filter.fFilterFrequency = v5->m_FXInfo.Params.Voice[1].Filter.fFilterFrequency;
  v5->m_FXInfo.PrevParams.Voice[1].Filter.fFilterQFactor = v5->m_FXInfo.Params.Voice[1].Filter.fFilterQFactor;
  v5->m_FXInfo.PrevParams.Voice[1].fPitchFactor = v5->m_FXInfo.Params.Voice[1].fPitchFactor;
  v5->m_FXInfo.PrevParams.Voice[1].fGain = v5->m_FXInfo.Params.Voice[1].fGain;
  *(_DWORD *)&v5->m_FXInfo.PrevParams.Voice[1].bEnable = *(_DWORD *)&v5->m_FXInfo.Params.Voice[1].bEnable;
  v5->m_FXInfo.PrevParams.eInputType = v5->m_FXInfo.Params.eInputType;
  v5->m_FXInfo.PrevParams.fDryLevel = v5->m_FXInfo.Params.fDryLevel;
  v5->m_FXInfo.PrevParams.fWetLevel = v5->m_FXInfo.Params.fWetLevel;
  v5->m_FXInfo.PrevParams.uWindowSize = v5->m_FXInfo.Params.uWindowSize;
  *(_DWORD *)&v5->m_FXInfo.PrevParams.bProcessLFE = *(_DWORD *)&v5->m_FXInfo.Params.bProcessLFE;
  v5->m_FXInfo.uSampleRate = in_rFormat->uSampleRate;
  v10 = *((_DWORD *)in_rFormat + 1) & 0x3FFFF;
  CAkHarmonizerFX::ComputeNumProcessedChannels(v5, v10);
  v11 = 0;
  if ( v5->m_FXInfo.Params.Voice[0].bEnable )
    v11 = 1;
  if ( (v5->m_FXInfo.Params.Voice[1].bEnable || v11) && v10 & v5->m_FXInfo.eProcessChannelMask )
    v6 = 1;
  v5->m_FXInfo.bWetPathEnabled = v6;
  result = CAkHarmonizerFX::InitPitchVoices(v5);
  if ( result == 1 )
  {
    result = CAkHarmonizerFX::InitDryDelay(v5);
    if ( result == 1 )
    {
      v13 = v5->m_pParams;
      result = 1;
      *(_WORD *)v13->m_ParamChangeHandler.m_uParamBitArray = 0;
      v13->m_ParamChangeHandler.m_uParamBitArray[2] = 0;
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
  unsigned int v5; // er8
  unsigned int v6; // edx
  unsigned int i; // edx
  unsigned int j; // edx
  unsigned int k; // edx
  unsigned int l; // edx
  unsigned int m; // edx
  unsigned int n; // edx

  v2 = in_eChannelMask;
  switch ( this->m_FXInfo.Params.eInputType )
  {
    case 0:
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
    case 1:
      v3 = 0;
      for ( i = in_eChannelMask & 4; i; i &= i - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 4;
      goto LABEL_23;
    case 2:
      v3 = 0;
      for ( j = in_eChannelMask & 3; j; j &= j - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 3;
      goto LABEL_23;
    case 3:
      v3 = 0;
      for ( k = in_eChannelMask & 7; k; k &= k - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 7;
      goto LABEL_23;
    case 4:
      v3 = 0;
      for ( l = in_eChannelMask & 0x33; l; l &= l - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 51;
      goto LABEL_23;
    case 5:
      v3 = 0;
      for ( m = in_eChannelMask & 0x37; m; m &= m - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 55;
      goto LABEL_23;
    case 6:
      v3 = 0;
      for ( n = in_eChannelMask & 1; n; n &= n - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 1;
LABEL_23:
      this->m_FXInfo.uNumProcessedChannels = v3;
      break;
    default:
      break;
  }
  if ( this->m_FXInfo.Params.bProcessLFE )
  {
    if ( v2 & 8 )
    {
      ++this->m_FXInfo.uNumProcessedChannels;
      this->m_FXInfo.eProcessChannelMask |= 8u;
    }
  }
}

// File Line: 125
// RVA: 0xAF7A20
void __fastcall CAkHarmonizerFX::ComputeWetPathEnabled(CAkHarmonizerFX *this, unsigned int in_eChannelMask)
{
  char v2; // al

  v2 = 0;
  if ( this->m_FXInfo.Params.Voice[0].bEnable )
    v2 = 1;
  this->m_FXInfo.bWetPathEnabled = (this->m_FXInfo.Params.Voice[1].bEnable || v2)
                                && in_eChannelMask & this->m_FXInfo.eProcessChannelMask;
}

// File Line: 136
// RVA: 0xAF7A70
AKRESULT __fastcall CAkHarmonizerFX::InitPitchVoices(CAkHarmonizerFX *this)
{
  CAkHarmonizerFX *v1; // rsi
  unsigned int v2; // edi
  char *v3; // rbx
  AKRESULT result; // eax
  int v5; // edx

  v1 = this;
  v2 = 0;
  v3 = (char *)&this->m_FXInfo.Params.Voice[0].Filter.fFilterQFactor;
  do
  {
    if ( v3[12] )
    {
      result = DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Init(
                 &v1->m_FXInfo.PhaseVocoder[v2],
                 v1->m_pAllocator,
                 v1->m_FXInfo.uNumProcessedChannels,
                 v1->m_FXInfo.uSampleRate,
                 v1->m_FXInfo.Params.uWindowSize,
                 0);
      if ( result != 1 )
        return result;
      v5 = *((_DWORD *)v3 - 3);
      if ( v5 )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          &v1->m_FXInfo.Filter[v2],
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v5 - 1),
          v1->m_FXInfo.uSampleRate,
          *((float *)v3 - 1),
          *((float *)v3 - 2),
          *(float *)v3);
    }
    ++v2;
    v3 += 28;
  }
  while ( v2 < 2 );
  return 1;
}

// File Line: 166
// RVA: 0xAF7B50
void __fastcall CAkHarmonizerFX::TermPitchVoices(CAkHarmonizerFX *this)
{
  CAkHarmonizerFX *v1; // rsi
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v2; // rbx
  signed __int64 v3; // rdi

  v1 = this;
  v2 = this->m_FXInfo.PhaseVocoder;
  v3 = 2i64;
  do
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(v2, v1->m_pAllocator);
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 174
// RVA: 0xAF7BA0
void __fastcall CAkHarmonizerFX::ResetPitchVoices(CAkHarmonizerFX *this)
{
  CAkHarmonizerFX *v1; // r14
  bool *v2; // rbp
  _QWORD *v3; // rdi
  unsigned int v4; // esi
  signed __int64 v5; // rbx

  v1 = this;
  v2 = &this->m_FXInfo.Params.Voice[0].bEnable;
  v3 = (_QWORD *)&this->m_FXInfo.Filter[0].m_Memories[0].fFFbk1;
  v4 = 0;
  do
  {
    if ( *v2 )
    {
      v5 = v4;
      DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Reset(&v1->m_FXInfo.PhaseVocoder[v5]);
      DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ResetInputFill(&v1->m_FXInfo.PhaseVocoder[v5]);
      *v3 = 0i64;
      *(v3 - 1) = 0i64;
      v3[2] = 0i64;
      v3[1] = 0i64;
      v3[4] = 0i64;
      v3[3] = 0i64;
      v3[6] = 0i64;
      v3[5] = 0i64;
      v3[8] = 0i64;
      v3[7] = 0i64;
      v3[10] = 0i64;
      v3[9] = 0i64;
      v3[12] = 0i64;
      v3[11] = 0i64;
      v3[14] = 0i64;
      v3[13] = 0i64;
    }
    ++v4;
    v2 += 28;
    v3 = (_QWORD *)((char *)v3 + 148);
  }
  while ( v4 < 2 );
}

// File Line: 187
// RVA: 0xAF7C70
signed __int64 __fastcall CAkHarmonizerFX::InitDryDelay(CAkHarmonizerFX *this)
{
  unsigned int v1; // esi
  CAkHarmonizerFX *v2; // rdi
  unsigned int v3; // ebx
  signed __int64 result; // rax

  v1 = this->m_FXInfo.Params.uWindowSize;
  v2 = this;
  if ( !this->m_FXInfo.Params.bSyncDry )
    return 1i64;
  if ( !this->m_FXInfo.bWetPathEnabled )
    return 1i64;
  v3 = 0;
  if ( !this->m_FXInfo.uTotalNumChannels )
    return 1i64;
  while ( 1 )
  {
    result = DSP::CDelayLight::Init((DSP::CDelayLight *)v2 + v3 + 116i64, v2->m_pAllocator, v1);
    if ( (_DWORD)result != 1 )
      break;
    if ( ++v3 >= v2->m_FXInfo.uTotalNumChannels )
      return 1i64;
  }
  return result;
}

// File Line: 202
// RVA: 0xAF7D00
void __fastcall CAkHarmonizerFX::TermDryDelay(CAkHarmonizerFX *this)
{
  unsigned int v1; // ebx
  CAkHarmonizerFX *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->m_FXInfo.uTotalNumChannels )
  {
    do
      DSP::CDelayLight::Term((DSP::CDelayLight *)v2 + v1++ + 116i64, v2->m_pAllocator);
    while ( v1 < v2->m_FXInfo.uTotalNumChannels );
  }
}

// File Line: 210
// RVA: 0xAF7D60
void __fastcall CAkHarmonizerFX::ResetDryDelay(CAkHarmonizerFX *this)
{
  unsigned int v1; // ebx
  CAkHarmonizerFX *v2; // rdi

  v1 = 0;
  v2 = this;
  if ( this->m_FXInfo.uTotalNumChannels )
  {
    do
      DSP::CDelayLight::Reset((DSP::CDelayLight *)v2 + v1++ + 116i64);
    while ( v1 < v2->m_FXInfo.uTotalNumChannels );
  }
}

// File Line: 217
// RVA: 0xAF7470
signed __int64 __fastcall CAkHarmonizerFX::Term(CAkHarmonizerFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // r14
  CAkHarmonizerFX *v3; // rbx
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v4; // rdi
  signed __int64 v5; // rsi
  unsigned int v6; // edi

  v2 = in_pAllocator;
  v3 = this;
  v4 = this->m_FXInfo.PhaseVocoder;
  v5 = 2i64;
  do
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(v4, v3->m_pAllocator);
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = 0;
  if ( v3->m_FXInfo.uTotalNumChannels )
  {
    do
      DSP::CDelayLight::Term((DSP::CDelayLight *)v3 + v6++ + 116i64, v3->m_pAllocator);
    while ( v6 < v3->m_FXInfo.uTotalNumChannels );
  }
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 226
// RVA: 0xAF7520
signed __int64 __fastcall CAkHarmonizerFX::Reset(CAkHarmonizerFX *this)
{
  CAkHarmonizerFX *v1; // rdi
  unsigned int v2; // ebx

  v1 = this;
  CAkHarmonizerFX::ResetPitchVoices(this);
  v2 = 0;
  if ( v1->m_FXInfo.uTotalNumChannels )
  {
    do
      DSP::CDelayLight::Reset((DSP::CDelayLight *)v1 + v2++ + 116i64);
    while ( v2 < v1->m_FXInfo.uTotalNumChannels );
  }
  return 1i64;
}

// File Line: 235
// RVA: 0xAF7580
signed __int64 __fastcall CAkHarmonizerFX::GetPluginInfo(CAkHarmonizerFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 251
// RVA: 0xAF75A0
void __fastcall CAkHarmonizerFX::Execute(CAkHarmonizerFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r13
  CAkHarmonizerFX *v3; // rbx
  int v4; // esi
  CAkHarmonizerFXParams *v5; // rdx
  int v6; // ecx
  signed __int64 v7; // r14
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v8; // rdi
  signed __int64 v9; // rbp
  CAkHarmonizerFXParams *v10; // rcx
  char v11; // al
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v12; // rdi
  unsigned int i; // edi
  char v14; // cl
  char v15; // al
  char v16; // cl
  AkFilterType v17; // edx
  char v18; // cl
  AkFilterType v19; // edx
  CAkHarmonizerFXParams *v20; // rax
  float *v21; // rax
  float *v22; // rdi

  v2 = io_pBuffer;
  v3 = this;
  CAkHarmonizerFXParams::GetParams(this->m_pParams, &this->m_FXInfo.Params);
  v4 = 0;
  if ( v3->m_FXInfo.bSendMode )
    v3->m_FXInfo.Params.fDryLevel = 0.0;
  v5 = v3->m_pParams;
  v6 = 0;
  while ( v5->m_ParamChangeHandler.m_uParamBitArray[v6] <= 0u )
  {
    if ( (unsigned int)++v6 >= 3 )
      goto LABEL_46;
  }
  v7 = 2i64;
  if ( v5->m_ParamChangeHandler.m_uParamBitArray[0] < 0 || v5->m_ParamChangeHandler.m_uParamBitArray[1] & 0x40 )
  {
    v8 = v3->m_FXInfo.PhaseVocoder;
    v9 = 2i64;
    do
    {
      DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(v8, v3->m_pAllocator);
      ++v8;
      --v9;
    }
    while ( v9 );
    if ( CAkHarmonizerFX::InitPitchVoices(v3) != 1 )
      return;
    CAkHarmonizerFX::ResetPitchVoices(v3);
  }
  v10 = v3->m_pParams;
  v11 = v10->m_ParamChangeHandler.m_uParamBitArray[0];
  if ( !(v11 & 0x20)
    && !(v11 & 0x40)
    && !(v10->m_ParamChangeHandler.m_uParamBitArray[1] & 0x20)
    && !(v11 & 1)
    && !(v11 & 2) )
  {
LABEL_31:
    if ( v3->m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] & 4 )
    {
      CAkHarmonizerFX::TermDryDelay(v3);
      if ( CAkHarmonizerFX::InitDryDelay(v3) != 1 )
        return;
      CAkHarmonizerFX::ResetDryDelay(v3);
    }
    v16 = v3->m_pParams->m_ParamChangeHandler.m_uParamBitArray[1];
    if ( v16 & 2 || v16 & 8 || v16 & 4 || v16 & 0x10 )
    {
      v17 = v3->m_FXInfo.Params.Voice[0].Filter.eFilterType;
      if ( v17 )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          v3->m_FXInfo.Filter,
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v17 - 1),
          v3->m_FXInfo.uSampleRate,
          v3->m_FXInfo.Params.Voice[0].Filter.fFilterFrequency,
          v3->m_FXInfo.Params.Voice[0].Filter.fFilterGain,
          v3->m_FXInfo.Params.Voice[0].Filter.fFilterQFactor);
    }
    v18 = v3->m_pParams->m_ParamChangeHandler.m_uParamBitArray[2];
    if ( v18 & 1 || v18 & 4 || v18 & 2 || v18 & 8 )
    {
      v19 = v3->m_FXInfo.Params.Voice[1].Filter.eFilterType;
      if ( v19 )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          &v3->m_FXInfo.Filter[1],
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v19 - 1),
          v3->m_FXInfo.uSampleRate,
          v3->m_FXInfo.Params.Voice[1].Filter.fFilterFrequency,
          v3->m_FXInfo.Params.Voice[1].Filter.fFilterGain,
          v3->m_FXInfo.Params.Voice[1].Filter.fFilterQFactor);
    }
LABEL_46:
    v20 = v3->m_pParams;
    *(_WORD *)v20->m_ParamChangeHandler.m_uParamBitArray = 0;
    v20->m_ParamChangeHandler.m_uParamBitArray[2] = 0;
    if ( v3->m_FXInfo.Params.Voice[0].bEnable )
      v4 = 4 * v3->m_FXInfo.PhaseVocoder[0].m_uFFTSize;
    if ( v3->m_FXInfo.Params.Voice[1].bEnable )
      v4 = 4 * v3->m_FXInfo.PhaseVocoder[1].m_uFFTSize;
    v21 = (float *)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, v4 + 8 * (unsigned int)v2->uMaxFrames);
    v22 = v21;
    if ( v21 )
    {
      AkHarmonizerDSPProcess(v2, &v3->m_FXInfo, v21);
      v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, v22);
    }
    return;
  }
  v12 = v3->m_FXInfo.PhaseVocoder;
  do
  {
    DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(v12, v3->m_pAllocator);
    ++v12;
    --v7;
  }
  while ( v7 );
  for ( i = 0; i < v3->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Term((DSP::CDelayLight *)v3 + i + 116i64, v3->m_pAllocator);
  CAkHarmonizerFX::ComputeNumProcessedChannels(v3, v2->uChannelMask);
  v14 = 0;
  v15 = 1;
  if ( v3->m_FXInfo.Params.Voice[0].bEnable )
    v14 = 1;
  if ( !v3->m_FXInfo.Params.Voice[1].bEnable && !v14 || !(v2->uChannelMask & v3->m_FXInfo.eProcessChannelMask) )
    v15 = 0;
  v3->m_FXInfo.bWetPathEnabled = v15;
  if ( CAkHarmonizerFX::InitPitchVoices(v3) == 1 && CAkHarmonizerFX::InitDryDelay(v3) == 1 )
  {
    CAkHarmonizerFX::ResetPitchVoices(v3);
    CAkHarmonizerFX::ResetDryDelay(v3);
    goto LABEL_31;
  }
}

