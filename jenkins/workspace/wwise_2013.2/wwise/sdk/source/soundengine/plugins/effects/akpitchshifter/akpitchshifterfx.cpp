// File Line: 28
// RVA: 0xAEA280
AK::IAkPlugin *__fastcall CreatePitchShifterFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 720ui64);
  v2 = result;
  if ( result )
  {
    result[1].vfptr = 0i64;
    result->vfptr = (AK::IAkPluginVtbl *)&CAkPitchShifterFX::`vftable';
    result[2].vfptr = 0i64;
    AkPitchShifterFXInfo::AkPitchShifterFXInfo((AkPitchShifterFXInfo *)&result[3]);
    result = v2;
  }
  return result;
}

// File Line: 37
// RVA: 0xAEA2E0
void __fastcall CAkPitchShifterFX::CAkPitchShifterFX(CAkPitchShifterFX *this)
{
  AkPitchShifterFXInfo *v1; // rcx

  v1 = &this->m_FXInfo;
  *(_QWORD *)&v1[-1].uNumProcessedChannels = &CAkPitchShifterFX::`vftable';
  *(_QWORD *)&v1[-1].uTotalNumChannels = 0i64;
  *(_QWORD *)&v1[-1].uTailLength = 0i64;
  AkPitchShifterFXInfo::AkPitchShifterFXInfo(v1);
}

// File Line: 43
// RVA: 0xAEA320
void __fastcall CAkPitchShifterFX::~CAkPitchShifterFX(CAkPitchShifterFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 53
// RVA: 0xAEA340
AKRESULT __fastcall CAkPitchShifterFX::Init(CAkPitchShifterFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkPitchShifterFX *v5; // rbx
  char v6; // al
  unsigned int v7; // ecx
  int i; // edx
  AKRESULT result; // eax

  this->m_pParams = (CAkPitchShifterFXParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  v5 = this;
  v6 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v7 = 0;
  v5->m_FXInfo.bSendMode = v6;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v7;
  v5->m_FXInfo.uTotalNumChannels = v7;
  CAkPitchShifterFXParams::GetParams(v5->m_pParams, &v5->m_FXInfo.Params);
  if ( v5->m_FXInfo.bSendMode )
    v5->m_FXInfo.Params.fDryLevel = 0.0;
  v5->m_FXInfo.PrevParams.Voice.Filter.eFilterType = v5->m_FXInfo.Params.Voice.Filter.eFilterType;
  v5->m_FXInfo.PrevParams.Voice.Filter.fFilterGain = v5->m_FXInfo.Params.Voice.Filter.fFilterGain;
  v5->m_FXInfo.PrevParams.Voice.Filter.fFilterFrequency = v5->m_FXInfo.Params.Voice.Filter.fFilterFrequency;
  v5->m_FXInfo.PrevParams.Voice.Filter.fFilterQFactor = v5->m_FXInfo.Params.Voice.Filter.fFilterQFactor;
  v5->m_FXInfo.PrevParams.Voice.fPitchFactor = v5->m_FXInfo.Params.Voice.fPitchFactor;
  v5->m_FXInfo.PrevParams.Voice.fGain = v5->m_FXInfo.Params.Voice.fGain;
  v5->m_FXInfo.PrevParams.fDryLevel = v5->m_FXInfo.Params.fDryLevel;
  v5->m_FXInfo.PrevParams.fWetLevel = v5->m_FXInfo.Params.fWetLevel;
  v5->m_FXInfo.PrevParams.fDelayTime = v5->m_FXInfo.Params.fDelayTime;
  *(_DWORD *)&v5->m_FXInfo.PrevParams.bProcessLFE = *(_DWORD *)&v5->m_FXInfo.Params.bProcessLFE;
  v5->m_FXInfo.uSampleRate = in_rFormat->uSampleRate;
  CAkPitchShifterFX::ComputeNumProcessedChannels(v5, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
  v5->m_FXInfo.uTailLength = (signed int)(float)((float)(v5->m_FXInfo.Params.fDelayTime * 0.001)
                                               * (float)(signed int)v5->m_FXInfo.uSampleRate);
  result = CAkPitchShifterFX::InitPitchVoice(v5);
  if ( result == 1 )
  {
    result = CAkPitchShifterFX::InitDryDelay(v5);
    if ( result == 1 )
    {
      v5->m_pParams->m_ParamChangeHandler = 0;
      result = 1;
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
  unsigned int v5; // er8
  unsigned int v6; // edx
  unsigned int i; // edx
  unsigned int j; // edx
  unsigned int k; // edx
  unsigned int l; // edx
  unsigned int m; // edx

  v2 = in_eChannelMask;
  switch ( LODWORD(this->m_FXInfo.Params.Voice.fGain) )
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
      goto LABEL_20;
    case 1:
      v3 = 0;
      for ( i = in_eChannelMask & 4; i; i &= i - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 4;
      goto LABEL_20;
    case 2:
      v3 = 0;
      for ( j = in_eChannelMask & 3; j; j &= j - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 3;
      goto LABEL_20;
    case 3:
      v3 = 0;
      for ( k = in_eChannelMask & 7; k; k &= k - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 7;
      goto LABEL_20;
    case 4:
      v3 = 0;
      for ( l = in_eChannelMask & 0x33; l; l &= l - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 51;
      goto LABEL_20;
    case 5:
      v3 = 0;
      for ( m = in_eChannelMask & 0x37; m; m &= m - 1 )
        ++v3;
      this->m_FXInfo.eProcessChannelMask = 55;
LABEL_20:
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

// File Line: 122
// RVA: 0xAEA920
void __fastcall CAkPitchShifterFX::ComputeTailLength(CAkPitchShifterFX *this)
{
  this->m_FXInfo.uTailLength = (signed int)(float)((float)(this->m_FXInfo.Params.fDelayTime * 0.001)
                                                 * (float)(signed int)this->m_FXInfo.uSampleRate);
}

// File Line: 127
// RVA: 0xAEA960
AKRESULT __fastcall CAkPitchShifterFX::InitPitchVoice(CAkPitchShifterFX *this)
{
  unsigned int v1; // er9
  CAkPitchShifterFX *v2; // rbx
  AKRESULT result; // eax
  AkFilterType v4; // edx

  v1 = this->m_FXInfo.uNumProcessedChannels;
  v2 = this;
  if ( v1 )
  {
    result = AK::DSP::AkDelayPitchShift::Init(
               &this->m_FXInfo.PitchShifter,
               this->m_pAllocator,
               this->m_FXInfo.Params.fDelayTime,
               v1,
               this->m_FXInfo.uSampleRate);
    if ( result != 1 )
      return result;
    AK::DSP::AkDelayPitchShift::SetPitchFactor(&v2->m_FXInfo.PitchShifter, v2->m_FXInfo.Params.Voice.fPitchFactor);
    v4 = v2->m_FXInfo.Params.Voice.Filter.eFilterType;
    if ( v4 )
      AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
        &v2->m_FXInfo.Filter,
        (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v4 - 1),
        v2->m_FXInfo.uSampleRate,
        v2->m_FXInfo.Params.Voice.Filter.fFilterFrequency,
        v2->m_FXInfo.Params.Voice.Filter.fFilterGain,
        v2->m_FXInfo.Params.Voice.Filter.fFilterQFactor);
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
  CAkPitchShifterFX *v1; // rbx

  v1 = this;
  if ( this->m_FXInfo.uNumProcessedChannels )
  {
    AK::DSP::AkDelayPitchShift::Reset(&this->m_FXInfo.PitchShifter);
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[0].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[0].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[1].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[1].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[2].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[2].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[3].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[3].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[4].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[4].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[5].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[5].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[6].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[6].fFFwd1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[7].fFFbk1 = 0i64;
    *(_QWORD *)&v1->m_FXInfo.Filter.m_Memories[7].fFFwd1 = 0i64;
  }
}

// File Line: 165
// RVA: 0xAEAAE0
AKRESULT __fastcall CAkPitchShifterFX::InitDryDelay(CAkPitchShifterFX *this)
{
  CAkPitchShifterFX *v1; // rdi
  unsigned int v2; // esi
  __int64 v3; // rbx
  AKRESULT result; // eax

  v1 = this;
  v2 = this->m_FXInfo.uTailLength >> 1;
  if ( !this->m_FXInfo.Params.bSyncDry )
    return 1;
  v3 = 0i64;
  if ( !this->m_FXInfo.uTotalNumChannels )
    return 1;
  while ( 1 )
  {
    result = DSP::CDelayLight::Init((DSP::CDelayLight *)(&v1->vfptr + v3 + 2 * (v3 + 26)), v1->m_pAllocator, v2);
    if ( result != 1 )
      break;
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= v1->m_FXInfo.uTotalNumChannels )
      return 1;
  }
  return result;
}

// File Line: 180
// RVA: 0xAEAB60
void __fastcall CAkPitchShifterFX::TermDryDelay(CAkPitchShifterFX *this)
{
  __int64 v1; // rbx
  CAkPitchShifterFX *v2; // rdi

  v1 = 0i64;
  v2 = this;
  if ( this->m_FXInfo.uTotalNumChannels )
  {
    do
    {
      DSP::CDelayLight::Term((DSP::CDelayLight *)(&v2->vfptr + v1 + 2 * (v1 + 26)), v2->m_pAllocator);
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_FXInfo.uTotalNumChannels );
  }
}

// File Line: 186
// RVA: 0xAEABB0
void __fastcall CAkPitchShifterFX::ResetDryDelay(CAkPitchShifterFX *this)
{
  __int64 v1; // rbx
  CAkPitchShifterFX *v2; // rdi

  v1 = 0i64;
  v2 = this;
  if ( this->m_FXInfo.uTotalNumChannels )
  {
    do
    {
      DSP::CDelayLight::Reset((DSP::CDelayLight *)(&v2->vfptr + v1 + 2 * (v1 + 26)));
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_FXInfo.uTotalNumChannels );
  }
}

// File Line: 193
// RVA: 0xAEA4A0
signed __int64 __fastcall CAkPitchShifterFX::Term(CAkPitchShifterFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rsi
  CAkPitchShifterFX *v3; // rbx
  __int64 v4; // rdi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_FXInfo.uNumProcessedChannels )
    AK::DSP::AkDelayPitchShift::Term(&this->m_FXInfo.PitchShifter, this->m_pAllocator);
  v4 = 0i64;
  if ( v3->m_FXInfo.uTotalNumChannels )
  {
    do
    {
      DSP::CDelayLight::Term((DSP::CDelayLight *)(&v3->vfptr + v4 + 2 * (v4 + 26)), v3->m_pAllocator);
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v3->m_FXInfo.uTotalNumChannels );
  }
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 202
// RVA: 0xAEA530
signed __int64 __fastcall CAkPitchShifterFX::Reset(CAkPitchShifterFX *this)
{
  CAkPitchShifterFX *v1; // rdi
  __int64 v2; // rbx

  v1 = this;
  CAkPitchShifterFX::ResetPitchVoice(this);
  v2 = 0i64;
  if ( v1->m_FXInfo.uTotalNumChannels )
  {
    do
    {
      DSP::CDelayLight::Reset((DSP::CDelayLight *)(&v1->vfptr + v2 + 2 * (v2 + 26)));
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->m_FXInfo.uTotalNumChannels );
  }
  return 1i64;
}

// File Line: 211
// RVA: 0xAEA590
signed __int64 __fastcall CAkPitchShifterFX::GetPluginInfo(CAkPitchShifterFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 228
// RVA: 0xAEA5B0
void __fastcall CAkPitchShifterFX::Execute(CAkPitchShifterFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rbp
  CAkPitchShifterFX *v3; // rbx
  float *v4; // rsi
  CAkPitchShifterFXParams *v5; // rdx
  int v6; // ecx
  char v7; // al
  unsigned int i; // edi
  CAkPitchShifterFXParams *v9; // rax
  char v10; // al
  AkFilterType v11; // edx

  v2 = io_pBuffer;
  v3 = this;
  CAkPitchShifterFXParams::GetParams(this->m_pParams, &this->m_FXInfo.Params);
  v4 = 0i64;
  if ( v3->m_FXInfo.bSendMode )
    v3->m_FXInfo.Params.fDryLevel = 0.0;
  v5 = v3->m_pParams;
  v6 = 0;
  while ( v5->m_ParamChangeHandler.m_uParamBitArray[v6] <= 0u )
  {
    if ( (unsigned int)++v6 >= 2 )
      goto LABEL_28;
  }
  v7 = v5->m_ParamChangeHandler.m_uParamBitArray[0];
  if ( !(v7 & 0x20) && !(v7 & 1) && !(v7 & 2) )
  {
LABEL_17:
    if ( v3->m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] & 4 )
    {
      CAkPitchShifterFX::TermDryDelay(v3);
      if ( CAkPitchShifterFX::InitDryDelay(v3) != 1 )
        return;
      CAkPitchShifterFX::ResetDryDelay(v3);
    }
    if ( v3->m_pParams->m_ParamChangeHandler.m_uParamBitArray[0] & 0x40 )
      AK::DSP::AkDelayPitchShift::SetPitchFactor(&v3->m_FXInfo.PitchShifter, v3->m_FXInfo.Params.Voice.fPitchFactor);
    v9 = v3->m_pParams;
    if ( v9->m_ParamChangeHandler.m_uParamBitArray[0] < 0
      || (v10 = v9->m_ParamChangeHandler.m_uParamBitArray[1], v10 & 2)
      || v10 & 1
      || v10 & 4 )
    {
      v11 = v3->m_FXInfo.Params.Voice.Filter.eFilterType;
      if ( v11 )
        AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
          &v3->m_FXInfo.Filter,
          (AK::DSP::MultiChannelBiquadFilter<8>::FilterType)(v11 - 1),
          v3->m_FXInfo.uSampleRate,
          v3->m_FXInfo.Params.Voice.Filter.fFilterFrequency,
          v3->m_FXInfo.Params.Voice.Filter.fFilterGain,
          v3->m_FXInfo.Params.Voice.Filter.fFilterQFactor);
    }
LABEL_28:
    v3->m_pParams->m_ParamChangeHandler = 0;
    if ( !v3->m_FXInfo.uNumProcessedChannels
      || (v4 = (float *)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 4i64 * v2->uMaxFrames)) != 0i64 )
    {
      AkPitchShifterDSPProcess(v2, &v3->m_FXInfo, v4, 0i64);
      if ( v4 )
        v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, v4);
    }
    return;
  }
  if ( v3->m_FXInfo.uNumProcessedChannels > 0 )
    AK::DSP::AkDelayPitchShift::Term(&v3->m_FXInfo.PitchShifter, v3->m_pAllocator);
  for ( i = 0; i < v3->m_FXInfo.uTotalNumChannels; ++i )
    DSP::CDelayLight::Term((DSP::CDelayLight *)(&v3->vfptr + i + 2 * (i + 26i64)), v3->m_pAllocator);
  v3->m_FXInfo.uTailLength = (signed int)(float)((float)(v3->m_FXInfo.Params.fDelayTime * 0.001)
                                               * (float)(signed int)v3->m_FXInfo.uSampleRate);
  CAkPitchShifterFX::ComputeNumProcessedChannels(v3, v2->uChannelMask);
  if ( CAkPitchShifterFX::InitPitchVoice(v3) == 1 && CAkPitchShifterFX::InitDryDelay(v3) == 1 )
  {
    CAkPitchShifterFX::ResetPitchVoice(v3);
    CAkPitchShifterFX::ResetDryDelay(v3);
    goto LABEL_17;
  }
}

