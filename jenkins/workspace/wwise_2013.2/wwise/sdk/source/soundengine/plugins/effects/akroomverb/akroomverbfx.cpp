// File Line: 53
// RVA: 0xAE1070
void __fastcall CreateRoomVerbFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFX *v1; // rax

  v1 = (CAkRoomVerbFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 496ui64);
  if ( v1 )
    CAkRoomVerbFX::CAkRoomVerbFX(v1);
}

// File Line: 60
// RVA: 0xAE10A0
void __fastcall CAkRoomVerbFX::CAkRoomVerbFX(CAkRoomVerbFX *this)
{
  CAkRoomVerbFX *v1; // rbx
  ReverbState *v2; // rcx

  v1 = this;
  v2 = &this->m_Reverb;
  *(_QWORD *)v2[-1].uTCFilterIndex = &CAkRoomVerbFX::`vftable';
  ReverbState::ReverbState(v2);
  v1->m_pParams = 0i64;
  v1->m_pAllocator = 0i64;
  v1->m_pReverbUnitsState = 0i64;
  v1->m_pTCFiltersState = 0i64;
  v1->m_pERUnit = 0i64;
  memset(&v1->m_PrevRTPCParams, 0, 0x54ui64);
  *(_QWORD *)&v1->m_PrevInvariantParams.uERPattern = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.fRoomSize = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.fDensity = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.uNumReverbUnits = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.fInputLFELevel = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.eFilter1Curve = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.eFilter2Curve = 0i64;
  *(_QWORD *)&v1->m_PrevInvariantParams.eFilter3Curve = 0i64;
}

// File Line: 72
// RVA: 0xAE1140
void __fastcall CAkRoomVerbFX::~CAkRoomVerbFX(CAkRoomVerbFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 82
// RVA: 0xAE1160
AKRESULT __fastcall CAkRoomVerbFX::Init(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkRoomVerbFX *v5; // rbx
  AK::IAkPluginMemAlloc *v6; // rdi
  unsigned int v7; // eax
  char v8; // al
  CAkRoomVerbFXParams *v9; // rcx
  char v10; // dl
  char v11; // al
  AKRESULT result; // eax

  v5 = this;
  v6 = in_pAllocator;
  v7 = in_rFormat->uSampleRate;
  this->m_pParams = (CAkRoomVerbFXParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  this->m_Reverb.uSampleRate = v7;
  this->m_Reverb.uNumReverbUnits = HIDWORD(in_pParams[14].vfptr);
  v8 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v5->m_Reverb.bIsSentMode = v8;
  if ( v8 )
    v5->m_pParams->sRTPCParams.fDryLevel = 0.0;
  v9 = v5->m_pParams;
  v5->m_PrevRTPCParams.fDecayTime = v9->sRTPCParams.fDecayTime;
  v5->m_PrevRTPCParams.fHFDamping = v9->sRTPCParams.fHFDamping;
  v5->m_PrevRTPCParams.fDiffusion = v9->sRTPCParams.fDiffusion;
  v5->m_PrevRTPCParams.fStereoWidth = v9->sRTPCParams.fStereoWidth;
  v5->m_PrevRTPCParams.fFilter1Gain = v9->sRTPCParams.fFilter1Gain;
  v5->m_PrevRTPCParams.fFilter1Freq = v9->sRTPCParams.fFilter1Freq;
  v5->m_PrevRTPCParams.fFilter1Q = v9->sRTPCParams.fFilter1Q;
  v5->m_PrevRTPCParams.fFilter2Gain = v9->sRTPCParams.fFilter2Gain;
  v5->m_PrevRTPCParams.fFilter2Freq = v9->sRTPCParams.fFilter2Freq;
  v5->m_PrevRTPCParams.fFilter2Q = v9->sRTPCParams.fFilter2Q;
  v5->m_PrevRTPCParams.fFilter3Gain = v9->sRTPCParams.fFilter3Gain;
  v5->m_PrevRTPCParams.fFilter3Freq = v9->sRTPCParams.fFilter3Freq;
  v5->m_PrevRTPCParams.fFilter3Q = v9->sRTPCParams.fFilter3Q;
  v5->m_PrevRTPCParams.fFrontLevel = v9->sRTPCParams.fFrontLevel;
  v5->m_PrevRTPCParams.fRearLevel = v9->sRTPCParams.fRearLevel;
  v5->m_PrevRTPCParams.fCenterLevel = v9->sRTPCParams.fCenterLevel;
  v5->m_PrevRTPCParams.fLFELevel = v9->sRTPCParams.fLFELevel;
  v5->m_PrevRTPCParams.fDryLevel = v9->sRTPCParams.fDryLevel;
  v5->m_PrevRTPCParams.fERLevel = v9->sRTPCParams.fERLevel;
  v5->m_PrevRTPCParams.fReverbLevel = v9->sRTPCParams.fReverbLevel;
  *(_DWORD *)&v5->m_PrevRTPCParams.bDirty = *(_DWORD *)&v9->sRTPCParams.bDirty;
  v10 = v9->sInvariantParams.bEnableEarlyReflections != 0 ? 2 : 0;
  v5->m_Reverb.uNumERSignals = v10;
  v11 = v10;
  if ( (*((_DWORD *)in_rFormat + 1) & 0x3FFFF) == 8 )
    v11 = 0;
  v5->m_Reverb.uNumERSignals = v11;
  CAkRoomVerbFX::SetupDCFilters(v5);
  result = CAkRoomVerbFX::SetupToneControlFilters(v5);
  if ( result == 1 )
  {
    result = CAkRoomVerbFX::SetupFDNs(v5, v6);
    if ( result == 1 )
    {
      result = CAkRoomVerbFX::SetupERDelay(v5, v6);
      if ( result == 1 )
      {
        result = CAkRoomVerbFX::SetupReverbDelay(v5, v6);
        if ( result == 1 )
        {
          result = CAkRoomVerbFX::SetupERUnit(v5, v6);
          if ( result == 1 )
          {
            result = CAkRoomVerbFX::SetupERFrontBackDelay(v5, v6, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
            if ( result == 1 )
            {
              result = CAkRoomVerbFX::SetupDiffusionAPF(v5, v6);
              if ( result == 1 )
              {
                v5->m_Reverb.uTailLength = (signed int)(float)((float)((float)(v5->m_pParams->sInvariantParams.fReverbDelay
                                                                             * 0.001)
                                                                     + v5->m_pParams->sRTPCParams.fDecayTime)
                                                             * (float)(signed int)v5->m_Reverb.uSampleRate);
                result = 1;
              }
            }
          }
        }
      }
    }
  }
  return result;
}

// File Line: 171
// RVA: 0xAE17C0
void __fastcall CAkRoomVerbFX::SetupDCFilters(CAkRoomVerbFX *this)
{
  this->m_Reverb.DCFilter[0].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(signed int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[1].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(signed int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[2].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(signed int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[3].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(signed int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[4].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(signed int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[5].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(signed int)this->m_Reverb.uSampleRate);
}

// File Line: 180
// RVA: 0xAE1910
void __fastcall CAkRoomVerbFX::ComputeTCCoefs1(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *v1; // rdx
  CAkRoomVerbFX *v2; // rbx
  FilterInsertType v3; // eax
  CAkRoomVerbFXParams *v4; // rdx

  v1 = this->m_pParams;
  v2 = this;
  if ( v1->sInvariantParams.bEnableToneControls )
  {
    v3 = v1->sInvariantParams.eFilter1Pos;
    if ( v3 )
    {
      if ( v3 != 1 || this->m_Reverb.uNumERSignals )
      {
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
          &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[1]].Filter,
          (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v1->sInvariantParams.eFilter1Curve,
          (float)(signed int)this->m_Reverb.uSampleRate,
          v1->sRTPCParams.fFilter1Freq,
          v1->sRTPCParams.fFilter1Gain,
          v1->sRTPCParams.fFilter1Q);
        v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[1]].FilterPos = v2->m_pParams->sInvariantParams.eFilter1Pos;
        v4 = v2->m_pParams;
        if ( v4->sInvariantParams.eFilter1Pos == 1 && v2->m_Reverb.uNumERSignals == 2 )
        {
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
            &v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[1] + 1].Filter,
            (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v4->sInvariantParams.eFilter1Curve,
            (float)(signed int)v2->m_Reverb.uSampleRate,
            v4->sRTPCParams.fFilter1Freq,
            v4->sRTPCParams.fFilter1Gain,
            v4->sRTPCParams.fFilter1Q);
          v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[1] + 1].FilterPos = v2->m_pParams->sInvariantParams.eFilter1Pos;
        }
      }
    }
  }
}

// File Line: 205
// RVA: 0xAE1A70
void __fastcall CAkRoomVerbFX::ComputeTCCoefs2(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *v1; // rdx
  CAkRoomVerbFX *v2; // rbx
  FilterInsertType v3; // eax
  CAkRoomVerbFXParams *v4; // rdx

  v1 = this->m_pParams;
  v2 = this;
  if ( v1->sInvariantParams.bEnableToneControls )
  {
    v3 = v1->sInvariantParams.eFilter2Pos;
    if ( v3 )
    {
      if ( v3 != 1 || this->m_Reverb.uNumERSignals )
      {
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
          &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[2]].Filter,
          (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v1->sInvariantParams.eFilter2Curve,
          (float)(signed int)this->m_Reverb.uSampleRate,
          v1->sRTPCParams.fFilter2Freq,
          v1->sRTPCParams.fFilter2Gain,
          v1->sRTPCParams.fFilter2Q);
        v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[2]].FilterPos = v2->m_pParams->sInvariantParams.eFilter2Pos;
        v4 = v2->m_pParams;
        if ( v4->sInvariantParams.eFilter2Pos == 1 && v2->m_Reverb.uNumERSignals == 2 )
        {
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
            &v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[2] + 1].Filter,
            (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v4->sInvariantParams.eFilter2Curve,
            (float)(signed int)v2->m_Reverb.uSampleRate,
            v4->sRTPCParams.fFilter2Freq,
            v4->sRTPCParams.fFilter2Gain,
            v4->sRTPCParams.fFilter2Q);
          v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[2] + 1].FilterPos = v2->m_pParams->sInvariantParams.eFilter2Pos;
        }
      }
    }
  }
}

// File Line: 230
// RVA: 0xAE1BD0
void __fastcall CAkRoomVerbFX::ComputeTCCoefs3(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *v1; // rdx
  CAkRoomVerbFX *v2; // rbx
  FilterInsertType v3; // eax
  CAkRoomVerbFXParams *v4; // rdx

  v1 = this->m_pParams;
  v2 = this;
  if ( v1->sInvariantParams.bEnableToneControls )
  {
    v3 = v1->sInvariantParams.eFilter3Pos;
    if ( v3 )
    {
      if ( v3 != 1 || this->m_Reverb.uNumERSignals )
      {
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
          &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[3]].Filter,
          (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v1->sInvariantParams.eFilter3Curve,
          (float)(signed int)this->m_Reverb.uSampleRate,
          v1->sRTPCParams.fFilter3Freq,
          v1->sRTPCParams.fFilter3Gain,
          v1->sRTPCParams.fFilter3Q);
        v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[3]].FilterPos = v2->m_pParams->sInvariantParams.eFilter3Pos;
        v4 = v2->m_pParams;
        if ( v4->sInvariantParams.eFilter3Pos == 1 && v2->m_Reverb.uNumERSignals == 2 )
        {
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
            &v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[3] + 1].Filter,
            (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v4->sInvariantParams.eFilter3Curve,
            (float)(signed int)v2->m_Reverb.uSampleRate,
            v4->sRTPCParams.fFilter3Freq,
            v4->sRTPCParams.fFilter3Gain,
            v4->sRTPCParams.fFilter3Q);
          v2->m_pTCFiltersState[(unsigned __int8)v2->m_Reverb.uTCFilterIndex[3] + 1].FilterPos = v2->m_pParams->sInvariantParams.eFilter3Pos;
        }
      }
    }
  }
}

// File Line: 255
// RVA: 0xAE71D0
signed __int64 __fastcall CAkRoomVerbFX::SetupToneControlFilters(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *v1; // rax
  CAkRoomVerbFX *v2; // rbx
  unsigned int v3; // edi
  FilterInsertType v4; // eax
  FilterInsertType v5; // eax
  FilterInsertType v6; // eax
  __int64 v7; // rsi
  ToneControlsState *v8; // rax
  __int64 v10; // rdi
  ToneControlsState *v11; // rcx

  v1 = this->m_pParams;
  v2 = this;
  v3 = 0;
  if ( v1->sInvariantParams.bEnableToneControls )
  {
    this->m_Reverb.uTCFilterIndex[1] = 0;
    v4 = v1->sInvariantParams.eFilter1Pos;
    if ( v4 == 1 )
    {
      v3 = (unsigned __int8)this->m_Reverb.uNumERSignals;
    }
    else if ( (unsigned int)(v4 - 2) <= 1 )
    {
      v3 = 1;
    }
    this->m_Reverb.uTCFilterIndex[2] = v3;
    v5 = this->m_pParams->sInvariantParams.eFilter2Pos;
    if ( v5 == 1 )
    {
      v3 += (unsigned __int8)this->m_Reverb.uNumERSignals;
    }
    else if ( (unsigned int)(v5 - 2) <= 1 )
    {
      ++v3;
    }
    this->m_Reverb.uTCFilterIndex[3] = v3;
    v6 = this->m_pParams->sInvariantParams.eFilter3Pos;
    if ( v6 == 1 )
    {
      v3 += (unsigned __int8)this->m_Reverb.uNumERSignals;
    }
    else if ( (unsigned int)(v6 - 2) <= 1 )
    {
      ++v3;
    }
  }
  this->m_Reverb.uTCFilterIndex[0] = v3;
  if ( v3 )
  {
    v7 = v3;
    v8 = (ToneControlsState *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 192i64 * v3);
    v2->m_pTCFiltersState = v8;
    if ( !v8 )
      return 52i64;
    if ( v3 )
    {
      v10 = 0i64;
      do
      {
        v11 = &v2->m_pTCFiltersState[v10];
        if ( v11 )
        {
          *(_QWORD *)&v11->Filter.m_Memories.m_Memories.fFFwd1 = 0i64;
          *(_QWORD *)&v11->Filter.m_Memories.m_Memories.fFFbk1 = 0i64;
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(&v11->Filter, 1.0, 0.0, 0.0, 0.0, 0.0);
        }
        ++v10;
        --v7;
      }
      while ( v7 );
    }
  }
  CAkRoomVerbFX::ComputeTCCoefs1(v2);
  CAkRoomVerbFX::ComputeTCCoefs2(v2);
  CAkRoomVerbFX::ComputeTCCoefs3(v2);
  return 1i64;
}

// File Line: 320
// RVA: 0xAE6BC0
AKRESULT __fastcall CAkRoomVerbFX::SetupERDelay(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rsi
  CAkRoomVerbFX *v3; // rdi
  CAkRoomVerbFXParams *v4; // rbx
  float v5; // xmm0_4
  __int64 v6; // rax
  float v7; // xmm1_4
  float v8; // xmm0_4
  unsigned int v9; // eax
  AKRESULT result; // eax

  v2 = in_pAllocator;
  v3 = this;
  if ( !this->m_Reverb.uNumERSignals )
    goto LABEL_9;
  v4 = this->m_pParams;
  v5 = powf(2.0, v4->sInvariantParams.fRoomSize * 0.0099999998);
  v6 = v4->sInvariantParams.uERPattern;
  v7 = v5 * g_ERPatternsList[v6].TapInfoLeft->fTapTime;
  v8 = v5 * g_ERPatternsList[v6].TapInfoRight->fTapTime;
  if ( v7 >= v8 )
    v7 = v8;
  v9 = (signed int)(float)((float)(signed int)v3->m_Reverb.uSampleRate * (float)(v7 * 0.001));
  if ( v9 )
    result = DSP::DelayLine::Init(&v3->m_Reverb.ERDelay, v2, v9);
  else
LABEL_9:
    result = 1;
  return result;
}

// File Line: 341
// RVA: 0xAE7180
AKRESULT __fastcall CAkRoomVerbFX::SetupReverbDelay(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int v2; // eax
  AKRESULT result; // eax

  v2 = (signed int)(float)((float)(this->m_pParams->sInvariantParams.fReverbDelay * 0.001)
                         * (float)(signed int)this->m_Reverb.uSampleRate);
  if ( v2 )
    result = DSP::DelayLine::Init(&this->m_Reverb.ReverbDelay, in_pAllocator, v2);
  else
    result = 1;
  return result;
}

// File Line: 352
// RVA: 0xAE6C90
AKRESULT __fastcall CAkRoomVerbFX::SetupERFrontBackDelay(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uChannelMask)
{
  char v3; // di
  AK::IAkPluginMemAlloc *v4; // rbp
  CAkRoomVerbFX *v5; // rbx
  unsigned int v6; // esi
  AKRESULT result; // eax

  v3 = in_uChannelMask;
  v4 = in_pAllocator;
  v5 = this;
  if ( !this->m_Reverb.uNumERSignals
    || (v6 = (signed int)(float)((float)(this->m_pParams->sInvariantParams.fERFrontBackDelay * 0.001)
                               * (float)(signed int)this->m_Reverb.uSampleRate)) == 0
    || (!(in_uChannelMask & 0x10)
     || (result = DSP::DelayLine::Init(this->m_Reverb.ERFrontBackDelay, in_pAllocator, v6), result == 1))
    && (!(v3 & 0x20) || (result = DSP::DelayLine::Init(&v5->m_Reverb.ERFrontBackDelay[1], v4, v6), result == 1)) )
  {
    result = 1;
  }
  return result;
}

// File Line: 376
// RVA: 0xAE6D40
signed __int64 __fastcall CAkRoomVerbFX::SetupERUnit(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFX *v2; // rdi
  AK::IAkPluginMemAlloc *v3; // rsi
  AKRESULT v4; // ecx
  __int64 v5; // rbp
  _QWORD *v6; // rbx

  v2 = this;
  v3 = in_pAllocator;
  v4 = 1;
  v5 = v2->m_pParams->sInvariantParams.uERPattern;
  if ( v2->m_Reverb.uNumERSignals )
  {
    v6 = (_QWORD *)in_pAllocator->vfptr->Malloc(in_pAllocator, 800ui64);
    if ( v6 )
    {
      *(_DWORD *)v6 = 0;
      v6[1] = 0i64;
      *((_DWORD *)v6 + 4) = 0;
      *(_QWORD *)((char *)v6 + 788) = 0i64;
      memset((char *)v6 + 20, 0, 0x100ui64);
      memset((char *)v6 + 276, 0, 0x100ui64);
      memset((char *)v6 + 532, 0, 0x80ui64);
      memset((char *)v6 + 660, 0, 0x80ui64);
    }
    else
    {
      v6 = 0i64;
    }
    v2->m_pERUnit = (DSP::ERUnitDual *)v6;
    if ( !v6 )
      return 52i64;
    v4 = DSP::ERUnitDual::Init(
           (DSP::ERUnitDual *)v6,
           v3,
           v2->m_pParams->sInvariantParams.fRoomSize,
           g_ERPatternsList[v5].TapInfoLeft,
           g_ERPatternsList[v5].TapInfoRight,
           g_ERPatternsList[v5].uNumTapsLeft,
           g_ERPatternsList[v5].uNumTapsRight,
           v2->m_Reverb.uSampleRate);
  }
  return (unsigned int)v4;
}

// File Line: 397
// RVA: 0xAE6E70
AKRESULT __fastcall CAkRoomVerbFX::SetupFDNs(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // r15
  CAkRoomVerbFX *v3; // rdi
  ReverbUnitState *v4; // rax
  AKRESULT result; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  signed __int64 v8; // rax
  signed int v9; // er8
  __m128 v10; // xmm0
  __int64 v11; // rsi
  __int64 v12; // r8
  __int64 v13; // r9
  unsigned int v14; // er10
  unsigned int *v15; // r11
  char *v16; // rdx
  __int64 v17; // rbp
  unsigned int v18; // eax
  __int64 v19; // rax
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  __int64 v22; // rcx
  __int64 v23; // rdx
  float v24; // xmm1_4
  float v25; // xmm0_4
  int v26; // esi
  signed __int64 v27; // r14
  float out_pfFDNInputDelayTimes[15]; // [rsp+30h] [rbp-398h]
  int v29; // [rsp+6Ch] [rbp-35Ch]
  unsigned int in_uDelayLineLength[16]; // [rsp+70h] [rbp-358h]
  unsigned int out_puDelayLengths[64]; // [rsp+B0h] [rbp-318h]
  float in_pfDelayTimes; // [rsp+1B0h] [rbp-218h]
  char v33[8]; // [rsp+2B0h] [rbp-118h]
  char v34; // [rsp+2B8h] [rbp-110h]

  v2 = in_pAllocator;
  v3 = this;
  v4 = (ReverbUnitState *)in_pAllocator->vfptr->Malloc(in_pAllocator, 168i64 * this->m_Reverb.uNumReverbUnits);
  v3->m_pReverbUnitsState = v4;
  if ( !v4 )
    return 52;
  v6 = 0;
  v7 = 0;
  if ( v3->m_Reverb.uNumReverbUnits )
  {
    do
    {
      v8 = (signed __int64)&v3->m_pReverbUnitsState[v7];
      if ( v8 )
      {
        *(_DWORD *)v8 = 0;
        *(_QWORD *)(v8 + 8) = 0i64;
        *(_DWORD *)(v8 + 16) = 0;
        *(_DWORD *)(v8 + 24) = 0;
        *(_QWORD *)(v8 + 32) = 0i64;
        *(_DWORD *)(v8 + 40) = 0;
        *(_DWORD *)(v8 + 48) = 0;
        *(_QWORD *)(v8 + 56) = 0i64;
        *(_DWORD *)(v8 + 64) = 0;
        *(_DWORD *)(v8 + 72) = 0;
        *(_QWORD *)(v8 + 80) = 0i64;
        *(_DWORD *)(v8 + 88) = 0;
        *(_QWORD *)(v8 + 96) = 0i64;
        *(_QWORD *)(v8 + 104) = 0i64;
        *(_QWORD *)(v8 + 112) = 0i64;
        *(_QWORD *)(v8 + 120) = 0i64;
        *(_QWORD *)(v8 + 128) = 0i64;
        *(_QWORD *)(v8 + 136) = 0i64;
        *(_DWORD *)(v8 + 144) = 0;
        *(_QWORD *)(v8 + 152) = 0i64;
        *(_DWORD *)(v8 + 160) = 0;
      }
      ++v7;
    }
    while ( v7 < v3->m_Reverb.uNumReverbUnits );
  }
  v9 = v3->m_Reverb.uNumReverbUnits;
  v3->m_Reverb.fReverbUnitsMixGain = 1.0;
  if ( (unsigned int)v9 > 1 )
  {
    v10 = 0i64;
    v10.m128_f32[0] = (float)v9;
    v3->m_Reverb.fReverbUnitsMixGain = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  }
  DelayLengths::ComputeFDNDelayTimes(
    v3->m_pParams->sInvariantParams.fDensity,
    v3->m_pParams->sInvariantParams.fRoomShape,
    4 * v9,
    &v3->m_pParams->sAlgoTunings,
    &in_pfDelayTimes);
  DelayLengths::ComputePrimeDelayLengths(
    &in_pfDelayTimes,
    v3->m_Reverb.uSampleRate,
    4 * v3->m_Reverb.uNumReverbUnits,
    out_puDelayLengths);
  v11 = v3->m_Reverb.uNumReverbUnits;
  if ( (_DWORD)v11 )
  {
    v12 = (unsigned int)(3 * v11);
    v13 = (unsigned int)(2 * v11);
    v14 = v3->m_Reverb.uNumReverbUnits;
    v15 = out_puDelayLengths;
    v16 = &v34;
    v17 = (unsigned int)v11;
    do
    {
      v18 = *v15;
      v16 += 16;
      ++v15;
      *((_DWORD *)v16 - 6) = v18;
      v19 = v14++;
      *((_DWORD *)v16 - 5) = out_puDelayLengths[v19];
      v20 = out_puDelayLengths[v13];
      v13 = (unsigned int)(v13 + 1);
      *((_DWORD *)v16 - 4) = v20;
      v21 = out_puDelayLengths[v12];
      v12 = (unsigned int)(v12 + 1);
      *((_DWORD *)v16 - 3) = v21;
      --v17;
    }
    while ( v17 );
  }
  DelayLengths::ComputeFDNInputDelayTimes(v11, &v3->m_pParams->sAlgoTunings, out_pfFDNInputDelayTimes);
  if ( (_DWORD)v11 )
  {
    v22 = 0i64;
    v23 = v11;
    v24 = (float)(signed int)v3->m_Reverb.uSampleRate;
    do
    {
      v25 = out_pfFDNInputDelayTimes[v22];
      ++v22;
      *(int *)((char *)&v29 + v22 * 4) = (signed int)(float)((float)(v25 * 0.001) * v24);
      --v23;
    }
    while ( v23 );
  }
  if ( !(_DWORD)v11 )
    return 1;
  v26 = 0;
  while ( 1 )
  {
    v27 = v6;
    result = DSP::FDN4::Init(
               &v3->m_pReverbUnitsState[v27].ReverbUnits,
               v2,
               (unsigned int *)&v33[4 * v26],
               v3->m_pParams->sRTPCParams.fDecayTime,
               v3->m_pParams->sRTPCParams.fHFDamping,
               v3->m_Reverb.uSampleRate);
    if ( result != 1 )
      break;
    result = DSP::DelayLine::Init(&v3->m_pReverbUnitsState[v27].RUInputDelay, v2, in_uDelayLineLength[v6]);
    if ( result != 1 )
      break;
    ++v6;
    v26 += 4;
    if ( v6 >= v3->m_Reverb.uNumReverbUnits )
      return 1;
  }
  return result;
}

// File Line: 465
// RVA: 0xAE6A90
AKRESULT __fastcall CAkRoomVerbFX::SetupDiffusionAPF(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rbp
  CAkRoomVerbFX *v3; // rsi
  __int64 v4; // rbx
  unsigned int *v5; // rdi
  float v6; // xmm3_4
  AKRESULT result; // eax
  float in_pfDelayTimes; // [rsp+20h] [rbp-68h]
  unsigned int out_puDelayLengths; // [rsp+30h] [rbp-58h]

  v2 = in_pAllocator;
  v3 = this;
  DelayLengths::ComputeDiffusionFiltersDelayTimes(4u, &this->m_pParams->sAlgoTunings, &in_pfDelayTimes);
  DelayLengths::ComputePrimeDelayLengths(&in_pfDelayTimes, v3->m_Reverb.uSampleRate, 4u, &out_puDelayLengths);
  v4 = 0i64;
  v5 = &out_puDelayLengths;
  do
  {
    v6 = (float)((float)((float)(v3->m_pParams->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0)
       - (float)((float)(3 - v4) * 0.61803001);
    if ( v6 <= 0.0 )
    {
      v6 = 0.0;
    }
    else if ( v6 >= 0.61803001 )
    {
      v6 = FLOAT_0_61803001;
    }
    result = DSP::AllpassFilter::Init(
               (DSP::AllpassFilter *)(&v3->vfptr + (unsigned int)v4 + 1i64 + 2 * v4),
               v2,
               *v5,
               v6);
    if ( result != 1 )
      break;
    v4 = (unsigned int)(v4 + 1);
    ++v5;
  }
  while ( (unsigned int)v4 < 4 );
  return result;
}

// File Line: 492
// RVA: 0xAE1390
signed __int64 __fastcall CAkRoomVerbFX::Term(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFX *v2; // rsi
  AK::IAkPluginMemAlloc *v3; // rdi
  DSP::ERUnitDual *v4; // rcx
  DSP::AllpassFilter *v5; // rbx
  signed __int64 v6; // rbp

  v2 = this;
  v3 = in_pAllocator;
  DSP::DelayLine::Term(&this->m_Reverb.ERDelay, in_pAllocator);
  DSP::DelayLine::Term(&v2->m_Reverb.ReverbDelay, v3);
  DSP::DelayLine::Term(v2->m_Reverb.ERFrontBackDelay, v3);
  DSP::DelayLine::Term(&v2->m_Reverb.ERFrontBackDelay[1], v3);
  if ( v2->m_Reverb.uNumERSignals )
  {
    v4 = v2->m_pERUnit;
    if ( v4 )
    {
      DSP::ERUnitDual::Term(v4, v3);
      if ( v2->m_pERUnit )
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v3->vfptr->Free)(v3);
      v2->m_pERUnit = 0i64;
    }
  }
  if ( v2->m_pTCFiltersState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v3->vfptr->Free)(v3);
    v2->m_pTCFiltersState = 0i64;
  }
  CAkRoomVerbFX::TermFDNs(v2, v3);
  v5 = v2->m_Reverb.DiffusionFilters;
  v6 = 4i64;
  do
  {
    DSP::AllpassFilter::Term(v5, v3);
    ++v5;
    --v6;
  }
  while ( v6 );
  v2->vfptr->__vecDelDtor((AK::IAkPlugin *)&v2->vfptr, 0);
  v3->vfptr->Free(v3, v2);
  return 1i64;
}

// File Line: 507
// RVA: 0xAE1D30
void __fastcall CAkRoomVerbFX::TermToneControlFilters(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFX *v2; // rbx

  v2 = this;
  if ( this->m_pTCFiltersState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->m_pTCFiltersState = 0i64;
  }
}

// File Line: 521
// RVA: 0xAE1D70
void __fastcall CAkRoomVerbFX::TermFDNs(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // r14
  CAkRoomVerbFX *v3; // rbx
  unsigned int v4; // esi
  signed __int64 v5; // rdi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pReverbUnitsState )
  {
    v4 = 0;
    if ( this->m_Reverb.uNumReverbUnits )
    {
      do
      {
        v5 = v4;
        DSP::FDN4::Term(&v3->m_pReverbUnitsState[v5].ReverbUnits, v2);
        DSP::DelayLine::Term(&v3->m_pReverbUnitsState[v5].RUInputDelay, v2);
        ++v4;
      }
      while ( v4 < v3->m_Reverb.uNumReverbUnits );
    }
    v2->vfptr->Free(v2, v3->m_pReverbUnitsState);
    v3->m_pReverbUnitsState = 0i64;
  }
}

// File Line: 537
// RVA: 0xAE1E20
void __fastcall CAkRoomVerbFX::TermDiffusionAPF(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rsi
  DSP::AllpassFilter *v3; // rbx
  signed __int64 v4; // rdi

  v2 = in_pAllocator;
  v3 = this->m_Reverb.DiffusionFilters;
  v4 = 4i64;
  do
  {
    DSP::AllpassFilter::Term(v3, v2);
    ++v3;
    --v4;
  }
  while ( v4 );
}

// File Line: 545
// RVA: 0xAE1E70
void __fastcall CAkRoomVerbFX::TermERUnit(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkRoomVerbFX *v3; // rbx
  DSP::ERUnitDual *v4; // rcx

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_Reverb.uNumERSignals )
  {
    v4 = this->m_pERUnit;
    if ( v4 )
    {
      DSP::ERUnitDual::Term(v4, in_pAllocator);
      if ( v3->m_pERUnit )
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
      v3->m_pERUnit = 0i64;
    }
  }
}

// File Line: 559
// RVA: 0xAE14A0
signed __int64 __fastcall CAkRoomVerbFX::Reset(CAkRoomVerbFX *this)
{
  CAkRoomVerbFX *v1; // rbx
  DSP::ERUnitDual *v2; // rcx
  signed __int64 v3; // rdx
  ToneControlsState *v4; // rax
  signed __int64 v5; // rcx
  DSP::AllpassFilter *v6; // rbx
  signed __int64 v7; // rdi

  v1 = this;
  DSP::DelayLine::Reset(&this->m_Reverb.ERDelay);
  DSP::DelayLine::Reset(&v1->m_Reverb.ReverbDelay);
  DSP::DelayLine::Reset(v1->m_Reverb.ERFrontBackDelay);
  DSP::DelayLine::Reset(&v1->m_Reverb.ERFrontBackDelay[1]);
  v2 = v1->m_pERUnit;
  if ( v2 )
    DSP::ERUnitDual::Reset(v2);
  v3 = 0i64;
  *(_QWORD *)&v1->m_Reverb.DCFilter[0].m_fFFwd1 = 0i64;
  *(_QWORD *)&v1->m_Reverb.DCFilter[1].m_fFFwd1 = 0i64;
  *(_QWORD *)&v1->m_Reverb.DCFilter[2].m_fFFwd1 = 0i64;
  *(_QWORD *)&v1->m_Reverb.DCFilter[3].m_fFFwd1 = 0i64;
  *(_QWORD *)&v1->m_Reverb.DCFilter[4].m_fFFwd1 = 0i64;
  *(_QWORD *)&v1->m_Reverb.DCFilter[5].m_fFFwd1 = 0i64;
  if ( v1->m_pParams->sInvariantParams.bEnableToneControls && v1->m_Reverb.uTCFilterIndex[0] > 0u )
  {
    do
    {
      v4 = v1->m_pTCFiltersState;
      v5 = v3;
      v3 = (unsigned int)(v3 + 1);
      *(_QWORD *)&v4[v5].Filter.m_Memories.m_Memories.fFFwd1 = 0i64;
      *(_QWORD *)&v4[v5].Filter.m_Memories.m_Memories.fFFbk1 = 0i64;
    }
    while ( (unsigned int)v3 < (unsigned __int8)v1->m_Reverb.uTCFilterIndex[0] );
  }
  CAkRoomVerbFX::ResetFDNs(v1);
  v6 = v1->m_Reverb.DiffusionFilters;
  v7 = 4i64;
  do
  {
    DSP::AllpassFilter::Reset(v6);
    ++v6;
    --v7;
  }
  while ( v7 );
  return 1i64;
}

// File Line: 573
// RVA: 0xAE1ED0
void __fastcall CAkRoomVerbFX::ResetFDNs(CAkRoomVerbFX *this)
{
  CAkRoomVerbFX *v1; // rbx
  unsigned int v2; // esi
  signed __int64 v3; // rdi

  v1 = this;
  if ( this->m_pReverbUnitsState )
  {
    v2 = 0;
    if ( this->m_Reverb.uNumReverbUnits )
    {
      do
      {
        v3 = v2;
        DSP::FDN4::Reset(&v1->m_pReverbUnitsState[v3].ReverbUnits);
        DSP::DelayLine::Reset(&v1->m_pReverbUnitsState[v3].RUInputDelay);
        ++v2;
      }
      while ( v2 < v1->m_Reverb.uNumReverbUnits );
    }
  }
}

// File Line: 585
// RVA: 0xAE1F50
void __fastcall CAkRoomVerbFX::ResetDiffusionAPF(CAkRoomVerbFX *this)
{
  DSP::AllpassFilter *v1; // rbx
  signed __int64 v2; // rdi

  v1 = this->m_Reverb.DiffusionFilters;
  v2 = 4i64;
  do
  {
    DSP::AllpassFilter::Reset(v1);
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 593
// RVA: 0xAE1F90
void __fastcall CAkRoomVerbFX::ResetDCFilters(CAkRoomVerbFX *this)
{
  *(_QWORD *)&this->m_Reverb.DCFilter[0].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[1].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[2].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[3].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[4].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[5].m_fFFwd1 = 0i64;
}

// File Line: 601
// RVA: 0xAE1FC0
void __fastcall CAkRoomVerbFX::ResetToneControlFilters(CAkRoomVerbFX *this)
{
  CAkRoomVerbFX *v1; // r8
  signed __int64 v2; // rdx
  ToneControlsState *v3; // rax
  signed __int64 v4; // rcx

  v1 = this;
  if ( this->m_pParams->sInvariantParams.bEnableToneControls )
  {
    v2 = 0i64;
    if ( this->m_Reverb.uTCFilterIndex[0] )
    {
      do
      {
        v3 = v1->m_pTCFiltersState;
        v4 = v2;
        v2 = (unsigned int)(v2 + 1);
        *(_QWORD *)&v3[v4].Filter.m_Memories.m_Memories.fFFwd1 = 0i64;
        *(_QWORD *)&v3[v4].Filter.m_Memories.m_Memories.fFFbk1 = 0i64;
      }
      while ( (unsigned int)v2 < (unsigned __int8)v1->m_Reverb.uTCFilterIndex[0] );
    }
  }
}

// File Line: 612
// RVA: 0xAE2020
void __fastcall CAkRoomVerbFX::ResetERUnit(CAkRoomVerbFX *this)
{
  JUMPOUT(this->m_pERUnit, 0i64, DSP::ERUnitDual::Reset);
}

// File Line: 621
// RVA: 0xAE15A0
signed __int64 __fastcall CAkRoomVerbFX::GetPluginInfo(CAkRoomVerbFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 633
// RVA: 0xAE2040
char __fastcall CAkRoomVerbFX::LiveParametersUpdate(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkRoomVerbFX *v2; // rbx
  CAkRoomVerbFXParams *v3; // rcx
  AkAudioBuffer *v4; // r15
  AK::IAkPluginMemAlloc *v5; // rdx
  AK::IAkPluginMemAlloc *v7; // rdi
  DSP::ERUnitDual *v8; // rcx
  CAkRoomVerbFXParams *v9; // rax
  AK::IAkPluginMemAlloc *v10; // rdx
  char v11; // al
  char v12; // cl
  DSP::ERUnitDual *v13; // rcx
  CAkRoomVerbFXParams *v14; // rax
  CAkRoomVerbFXParams *v15; // rcx
  DSP::ERUnitDual *v16; // rcx
  CAkRoomVerbFXParams *v17; // rcx
  bool v18; // dl
  CAkRoomVerbFXParams *v19; // rcx

  v2 = this;
  v3 = this->m_pParams;
  v4 = io_pBuffer;
  if ( v2->m_PrevInvariantParams.uNumReverbUnits != v3->sInvariantParams.uNumReverbUnits
    || v3->sInvariantParams.fRoomShape != v2->m_PrevInvariantParams.fRoomShape
    || v3->sInvariantParams.fDensity != v2->m_PrevInvariantParams.fDensity )
  {
    CAkRoomVerbFX::TermFDNs(v2, v2->m_pAllocator);
    v5 = v2->m_pAllocator;
    v2->m_Reverb.uNumReverbUnits = v2->m_pParams->sInvariantParams.uNumReverbUnits;
    if ( CAkRoomVerbFX::SetupFDNs(v2, v5) != 1 )
      return 1;
    CAkRoomVerbFX::ResetFDNs(v2);
  }
  if ( v2->m_PrevInvariantParams.bEnableEarlyReflections != v2->m_pParams->sInvariantParams.bEnableEarlyReflections )
  {
    DSP::DelayLine::Term(v2->m_Reverb.ERFrontBackDelay, v2->m_pAllocator);
    DSP::DelayLine::Term(&v2->m_Reverb.ERFrontBackDelay[1], v2->m_pAllocator);
    DSP::DelayLine::Term(&v2->m_Reverb.ERDelay, v2->m_pAllocator);
    v7 = v2->m_pAllocator;
    if ( v2->m_Reverb.uNumERSignals )
    {
      v8 = v2->m_pERUnit;
      if ( v8 )
      {
        DSP::ERUnitDual::Term(v8, v2->m_pAllocator);
        if ( v2->m_pERUnit )
          ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v7->vfptr->Free)(v7);
        v2->m_pERUnit = 0i64;
      }
    }
    v9 = v2->m_pParams;
    if ( v9->sInvariantParams.bEnableToneControls
      && (v9->sInvariantParams.eFilter1Pos || v9->sInvariantParams.eFilter2Pos || v9->sInvariantParams.eFilter3Pos)
      && v2->m_pTCFiltersState )
    {
      ((void (*)(void))v2->m_pAllocator->vfptr->Free)();
      v2->m_pTCFiltersState = 0i64;
    }
    v10 = v2->m_pAllocator;
    v11 = v2->m_pParams->sInvariantParams.bEnableEarlyReflections != 0 ? 2 : 0;
    v2->m_Reverb.uNumERSignals = v11;
    v12 = v11;
    if ( v4->uChannelMask == 8 )
      v12 = 0;
    v2->m_Reverb.uNumERSignals = v12;
    if ( CAkRoomVerbFX::SetupERFrontBackDelay(v2, v10, v4->uChannelMask) != 1 )
      return 1;
    DSP::DelayLine::Reset(v2->m_Reverb.ERFrontBackDelay);
    DSP::DelayLine::Reset(&v2->m_Reverb.ERFrontBackDelay[1]);
    if ( CAkRoomVerbFX::SetupERDelay(v2, v2->m_pAllocator) != 1 )
      return 1;
    DSP::DelayLine::Reset(&v2->m_Reverb.ERDelay);
    if ( CAkRoomVerbFX::SetupERUnit(v2, v2->m_pAllocator) != 1 )
      return 1;
    v13 = v2->m_pERUnit;
    if ( v13 )
      DSP::ERUnitDual::Reset(v13);
    v14 = v2->m_pParams;
    if ( v14->sInvariantParams.bEnableToneControls )
    {
      if ( v14->sInvariantParams.eFilter1Pos || v14->sInvariantParams.eFilter2Pos || v14->sInvariantParams.eFilter3Pos )
      {
        if ( CAkRoomVerbFX::SetupToneControlFilters(v2) != 1 )
          return 1;
        CAkRoomVerbFX::ResetToneControlFilters(v2);
      }
    }
  }
  if ( v2->m_pParams->sInvariantParams.fERFrontBackDelay != v2->m_PrevInvariantParams.fERFrontBackDelay )
  {
    DSP::DelayLine::Term(v2->m_Reverb.ERFrontBackDelay, v2->m_pAllocator);
    DSP::DelayLine::Term(&v2->m_Reverb.ERFrontBackDelay[1], v2->m_pAllocator);
    if ( CAkRoomVerbFX::SetupERFrontBackDelay(v2, v2->m_pAllocator, v4->uChannelMask) != 1 )
      return 1;
    DSP::DelayLine::Reset(v2->m_Reverb.ERFrontBackDelay);
    DSP::DelayLine::Reset(&v2->m_Reverb.ERFrontBackDelay[1]);
  }
  v15 = v2->m_pParams;
  if ( v15->sInvariantParams.fReverbDelay != v2->m_PrevInvariantParams.fReverbDelay )
  {
    DSP::DelayLine::Term(&v2->m_Reverb.ReverbDelay, v2->m_pAllocator);
    if ( CAkRoomVerbFX::SetupReverbDelay(v2, v2->m_pAllocator) == 1 )
    {
      DSP::DelayLine::Reset(&v2->m_Reverb.ReverbDelay);
      v15 = v2->m_pParams;
      v2->m_Reverb.uTailLength = (signed int)(float)((float)((float)(v15->sInvariantParams.fReverbDelay * 0.001)
                                                           + v15->sRTPCParams.fDecayTime)
                                                   * (float)(signed int)v2->m_Reverb.uSampleRate);
      goto LABEL_38;
    }
    return 1;
  }
LABEL_38:
  if ( v2->m_PrevInvariantParams.uERPattern != v15->sInvariantParams.uERPattern
    || v15->sInvariantParams.fRoomSize != v2->m_PrevInvariantParams.fRoomSize )
  {
    DSP::DelayLine::Term(&v2->m_Reverb.ERDelay, v2->m_pAllocator);
    if ( CAkRoomVerbFX::SetupERDelay(v2, v2->m_pAllocator) != 1 )
      return 1;
    DSP::DelayLine::Reset(&v2->m_Reverb.ERDelay);
    CAkRoomVerbFX::TermERUnit(v2, v2->m_pAllocator);
    if ( CAkRoomVerbFX::SetupERUnit(v2, v2->m_pAllocator) != 1 )
      return 1;
    v16 = v2->m_pERUnit;
    if ( v16 )
      DSP::ERUnitDual::Reset(v16);
  }
  v17 = v2->m_pParams;
  v18 = v17->sInvariantParams.bEnableToneControls;
  if ( (v2->m_PrevInvariantParams.bEnableToneControls != v18
     || v2->m_PrevInvariantParams.eFilter1Pos != v17->sInvariantParams.eFilter1Pos
     || v2->m_PrevInvariantParams.eFilter2Pos != v17->sInvariantParams.eFilter2Pos
     || v2->m_PrevInvariantParams.eFilter3Pos != v17->sInvariantParams.eFilter3Pos)
    && v18
    && (v17->sInvariantParams.eFilter1Pos || v17->sInvariantParams.eFilter2Pos || v17->sInvariantParams.eFilter3Pos) )
  {
    CAkRoomVerbFX::TermToneControlFilters(v2, v2->m_pAllocator);
    if ( CAkRoomVerbFX::SetupToneControlFilters(v2) != 1 )
      return 1;
    CAkRoomVerbFX::ResetToneControlFilters(v2);
  }
  if ( v2->m_PrevInvariantParams.eFilter1Curve != v2->m_pParams->sInvariantParams.eFilter1Curve )
    CAkRoomVerbFX::ComputeTCCoefs1(v2);
  if ( v2->m_PrevInvariantParams.eFilter2Curve != v2->m_pParams->sInvariantParams.eFilter2Curve )
    CAkRoomVerbFX::ComputeTCCoefs2(v2);
  if ( v2->m_PrevInvariantParams.eFilter3Curve != v2->m_pParams->sInvariantParams.eFilter3Curve )
    CAkRoomVerbFX::ComputeTCCoefs3(v2);
  v19 = v2->m_pParams;
  v2->m_PrevInvariantParams.uERPattern = v19->sInvariantParams.uERPattern;
  v2->m_PrevInvariantParams.fReverbDelay = v19->sInvariantParams.fReverbDelay;
  v2->m_PrevInvariantParams.fRoomSize = v19->sInvariantParams.fRoomSize;
  v2->m_PrevInvariantParams.fERFrontBackDelay = v19->sInvariantParams.fERFrontBackDelay;
  v2->m_PrevInvariantParams.fDensity = v19->sInvariantParams.fDensity;
  v2->m_PrevInvariantParams.fRoomShape = v19->sInvariantParams.fRoomShape;
  v2->m_PrevInvariantParams.uNumReverbUnits = v19->sInvariantParams.uNumReverbUnits;
  v2->m_PrevInvariantParams.fInputCenterLevel = v19->sInvariantParams.fInputCenterLevel;
  v2->m_PrevInvariantParams.fInputLFELevel = v19->sInvariantParams.fInputLFELevel;
  v2->m_PrevInvariantParams.eFilter1Pos = v19->sInvariantParams.eFilter1Pos;
  v2->m_PrevInvariantParams.eFilter1Curve = v19->sInvariantParams.eFilter1Curve;
  v2->m_PrevInvariantParams.eFilter2Pos = v19->sInvariantParams.eFilter2Pos;
  v2->m_PrevInvariantParams.eFilter2Curve = v19->sInvariantParams.eFilter2Curve;
  v2->m_PrevInvariantParams.eFilter3Pos = v19->sInvariantParams.eFilter3Pos;
  v2->m_PrevInvariantParams.eFilter3Curve = v19->sInvariantParams.eFilter3Curve;
  *(_DWORD *)&v2->m_PrevInvariantParams.bEnableToneControls = *(_DWORD *)&v19->sInvariantParams.bEnableToneControls;
  v19->sInvariantParams.bDirty = 0;
  return 0;
}

// File Line: 755
// RVA: 0xAE25F0
void __fastcall CAkRoomVerbFX::RTPCParametersUpdate(CAkRoomVerbFX *this)
{
  CAkRoomVerbFX *v1; // rbx
  CAkRoomVerbFXParams *v2; // rcx
  float *v3; // rax
  float *v4; // rax
  float *v5; // rax
  CAkRoomVerbFXParams *v6; // rax

  v1 = this;
  v2 = this->m_pParams;
  if ( v1->m_PrevRTPCParams.fDecayTime != v2->sRTPCParams.fDecayTime
    || v1->m_PrevRTPCParams.fHFDamping != v2->sRTPCParams.fHFDamping )
  {
    CAkRoomVerbFX::ChangeDecay(v1);
    v2 = v1->m_pParams;
    v1->m_Reverb.uTailLength = (signed int)(float)((float)((float)(v2->sInvariantParams.fReverbDelay * 0.001)
                                                         + v2->sRTPCParams.fDecayTime)
                                                 * (float)(signed int)v1->m_Reverb.uSampleRate);
  }
  if ( v1->m_PrevRTPCParams.fDiffusion != v2->sRTPCParams.fDiffusion )
    CAkRoomVerbFX::ChangeDiffusion(v1);
  v3 = (float *)v1->m_pParams;
  if ( v1->m_PrevRTPCParams.fFilter1Gain != v3[6]
    || v1->m_PrevRTPCParams.fFilter1Freq != v3[7]
    || v1->m_PrevRTPCParams.fFilter1Q != v3[8] )
  {
    CAkRoomVerbFX::ComputeTCCoefs1(v1);
  }
  v4 = (float *)v1->m_pParams;
  if ( v1->m_PrevRTPCParams.fFilter2Gain != v4[9]
    || v1->m_PrevRTPCParams.fFilter2Freq != v4[10]
    || v1->m_PrevRTPCParams.fFilter2Q != v4[11] )
  {
    CAkRoomVerbFX::ComputeTCCoefs2(v1);
  }
  v5 = (float *)v1->m_pParams;
  if ( v1->m_PrevRTPCParams.fFilter3Gain != v5[12]
    || v1->m_PrevRTPCParams.fFilter3Freq != v5[13]
    || v1->m_PrevRTPCParams.fFilter3Q != v5[14] )
  {
    CAkRoomVerbFX::ComputeTCCoefs3(v1);
  }
  v6 = v1->m_pParams;
  if ( v1->m_Reverb.bIsSentMode )
  {
    v6->sRTPCParams.fDryLevel = 0.0;
    v6 = v1->m_pParams;
  }
  v6->sRTPCParams.bDirty = 0;
}

// File Line: 804
// RVA: 0xAE15C0
void __fastcall CAkRoomVerbFX::Execute(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rdi
  CAkRoomVerbFX *v3; // rbx
  unsigned int v4; // ecx
  int v5; // ecx
  CAkRoomVerbFXParams *v6; // rcx

  v2 = io_pBuffer;
  v3 = this;
  if ( !this->m_pParams->sInvariantParams.bDirty || !CAkRoomVerbFX::LiveParametersUpdate(this, io_pBuffer) )
  {
    if ( v3->m_pParams->sRTPCParams.bDirty )
      CAkRoomVerbFX::RTPCParametersUpdate(v3);
    AkFXTailHandler::HandleTail(&v3->m_Reverb.FXTailHandler, v2, v3->m_Reverb.uTailLength);
    if ( v2->uValidFrames )
    {
      v4 = v2->uChannelMask;
      if ( v4 <= 0x37 )
      {
        if ( v4 != 55 )
        {
          switch ( v4 )
          {
            case 3u:
            case 4u:
            case 8u:
            case 0xBu:
            case 0xCu:
              CAkRoomVerbFX::ProcessSpread1Out(v3, v2);
              break;
            case 7u:
            case 0xFu:
            case 0x33u:
              CAkRoomVerbFX::ProcessSpread2Out(v3, v2);
              break;
            default:
              goto LABEL_20;
          }
          goto LABEL_20;
        }
        goto LABEL_16;
      }
      if ( v4 > 0x637 )
      {
        v5 = v4 - 1595;
        if ( v5 && v5 != 4 )
          goto LABEL_20;
      }
      else if ( v4 != 1591 )
      {
        if ( !((v4 - 59) & 0xFFFFFFFB) )
        {
LABEL_16:
          CAkRoomVerbFX::ProcessSpread3Out(v3, v2);
LABEL_20:
          v6 = v3->m_pParams;
          v3->m_PrevRTPCParams.fDecayTime = v6->sRTPCParams.fDecayTime;
          v3->m_PrevRTPCParams.fHFDamping = v6->sRTPCParams.fHFDamping;
          v3->m_PrevRTPCParams.fDiffusion = v6->sRTPCParams.fDiffusion;
          v3->m_PrevRTPCParams.fStereoWidth = v6->sRTPCParams.fStereoWidth;
          v3->m_PrevRTPCParams.fFilter1Gain = v6->sRTPCParams.fFilter1Gain;
          v3->m_PrevRTPCParams.fFilter1Freq = v6->sRTPCParams.fFilter1Freq;
          v3->m_PrevRTPCParams.fFilter1Q = v6->sRTPCParams.fFilter1Q;
          v3->m_PrevRTPCParams.fFilter2Gain = v6->sRTPCParams.fFilter2Gain;
          v3->m_PrevRTPCParams.fFilter2Freq = v6->sRTPCParams.fFilter2Freq;
          v3->m_PrevRTPCParams.fFilter2Q = v6->sRTPCParams.fFilter2Q;
          v3->m_PrevRTPCParams.fFilter3Gain = v6->sRTPCParams.fFilter3Gain;
          v3->m_PrevRTPCParams.fFilter3Freq = v6->sRTPCParams.fFilter3Freq;
          v3->m_PrevRTPCParams.fFilter3Q = v6->sRTPCParams.fFilter3Q;
          v3->m_PrevRTPCParams.fFrontLevel = v6->sRTPCParams.fFrontLevel;
          v3->m_PrevRTPCParams.fRearLevel = v6->sRTPCParams.fRearLevel;
          v3->m_PrevRTPCParams.fCenterLevel = v6->sRTPCParams.fCenterLevel;
          v3->m_PrevRTPCParams.fLFELevel = v6->sRTPCParams.fLFELevel;
          v3->m_PrevRTPCParams.fDryLevel = v6->sRTPCParams.fDryLevel;
          v3->m_PrevRTPCParams.fERLevel = v6->sRTPCParams.fERLevel;
          v3->m_PrevRTPCParams.fReverbLevel = v6->sRTPCParams.fReverbLevel;
          *(_DWORD *)&v3->m_PrevRTPCParams.bDirty = *(_DWORD *)&v6->sRTPCParams.bDirty;
          return;
        }
        if ( v4 != 1587 )
          goto LABEL_20;
      }
      CAkRoomVerbFX::ProcessSpread4Out(v3, v2);
      goto LABEL_20;
    }
  }
}

// File Line: 1026
// RVA: 0xAE6210
void __fastcall CAkRoomVerbFX::ChangeDiffusion(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this->m_pParams;
  v2 = (float)((float)((float)(v1->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0) - 1.85409;
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 0.61803001 )
  {
    v2 = FLOAT_0_61803001;
  }
  this->m_Reverb.DiffusionFilters[0].fG = v2;
  v3 = (float)((float)((float)(v1->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0) - 1.23606;
  if ( v3 <= 0.0 )
  {
    v3 = 0.0;
  }
  else if ( v3 >= 0.61803001 )
  {
    v3 = FLOAT_0_61803001;
  }
  this->m_Reverb.DiffusionFilters[1].fG = v3;
  v4 = (float)((float)((float)(v1->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0) - 0.61803001;
  if ( v4 <= 0.0 )
  {
    v4 = 0.0;
  }
  else if ( v4 >= 0.61803001 )
  {
    v4 = FLOAT_0_61803001;
  }
  this->m_Reverb.DiffusionFilters[2].fG = v4;
  v5 = (float)((float)(v1->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0;
  if ( v5 <= 0.0 )
  {
    this->m_Reverb.DiffusionFilters[3].fG = 0.0;
  }
  else if ( v5 < 0.61803001 )
  {
    this->m_Reverb.DiffusionFilters[3].fG = v5;
  }
  else
  {
    this->m_Reverb.DiffusionFilters[3].fG = FLOAT_0_61803001;
  }
}

// File Line: 1036
// RVA: 0xAE61A0
void __fastcall CAkRoomVerbFX::ChangeDecay(CAkRoomVerbFX *this)
{
  unsigned int v1; // edi
  CAkRoomVerbFX *v2; // rbx

  v1 = 0;
  v2 = this;
  if ( this->m_Reverb.uNumReverbUnits )
  {
    do
      DSP::FDN4::ChangeDecay(
        &v2->m_pReverbUnitsState[v1++].ReverbUnits,
        v2->m_pParams->sRTPCParams.fDecayTime,
        v2->m_pParams->sRTPCParams.fHFDamping,
        v2->m_Reverb.uSampleRate);
    while ( v1 < v2->m_Reverb.uNumReverbUnits );
  }
}

// File Line: 1048
// RVA: 0xAE2750
void __fastcall CAkRoomVerbFX::WetPreProcess(CAkRoomVerbFX *this, AkAudioBuffer *in_pBuffer, float *out_pfWetIn, unsigned int in_uNumFrames, unsigned int in_uFrameOffset)
{
  unsigned int v5; // ebp
  float *v6; // r14
  CAkRoomVerbFX *v7; // r15
  unsigned __int8 v8; // si
  signed __int64 v9; // rdi
  unsigned int v10; // eax
  float *v11; // rdx
  __int64 v12; // rbx
  unsigned int v13; // eax
  int v14; // er8
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  __m128 v17; // xmm0
  unsigned __int64 v18; // rcx
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  int v23; // [rsp+40h] [rbp-68h]
  int v24; // [rsp+50h] [rbp-58h]
  int v25; // [rsp+60h] [rbp-48h]
  int v26; // [rsp+70h] [rbp-38h]

  v5 = in_uNumFrames;
  v6 = out_pfWetIn;
  v7 = this;
  DSP::ConstantPowerChannelMixdown(
    in_pBuffer,
    in_uNumFrames,
    in_uFrameOffset,
    out_pfWetIn,
    in_pBuffer->uChannelMask,
    this->m_pParams->sInvariantParams.fInputCenterLevel,
    this->m_pParams->sInvariantParams.fInputLFELevel);
  if ( v7->m_pParams->sInvariantParams.bEnableToneControls )
  {
    v8 = 0;
    if ( v7->m_Reverb.uTCFilterIndex[0] )
    {
      do
      {
        v9 = (signed __int64)&v7->m_pTCFiltersState[v8];
        if ( *(_DWORD *)(v9 + 176) == 3 )
        {
          v10 = v5;
          v11 = v6;
          if ( (unsigned __int8)v6 & 0xF )
          {
            v12 = v5;
            v13 = (16 - ((unsigned __int8)v6 & 0xFu)) >> 2;
            if ( v13 < v5 )
              v12 = v13;
            DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(
              &v7->m_pTCFiltersState[v8].Filter,
              v6,
              v12,
              0);
            v11 = &v6[v12];
            v10 = v5 - v12;
          }
          v14 = v10 & 3;
          v15 = _mm_shuffle_ps((__m128)*(unsigned int *)(v9 + 160), (__m128)*(unsigned int *)(v9 + 160), 0);
          v16 = _mm_shuffle_ps((__m128)*(unsigned int *)(v9 + 164), (__m128)*(unsigned int *)(v9 + 164), 0);
          v17 = _mm_shuffle_ps((__m128)*(unsigned int *)(v9 + 168), (__m128)*(unsigned int *)(v9 + 168), 0);
          v18 = (unsigned __int64)&v11[v10 - v14];
          v23 = v15.m128_i32[0];
          v24 = v16.m128_i32[0];
          v25 = v17.m128_i32[0];
          v19 = _mm_shuffle_ps((__m128)*(unsigned int *)(v9 + 172), (__m128)*(unsigned int *)(v9 + 172), 0);
          v26 = v19.m128_i32[0];
          if ( (unsigned __int64)v11 < v18 )
          {
            do
            {
              v20 = *(__m128 *)v11;
              v11 += 4;
              v21 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v9 + 80), v16), _mm_mul_ps(*(__m128 *)(v9 + 64), v15));
              v16 = _mm_shuffle_ps(v20, v20, 170);
              v15 = _mm_shuffle_ps(v20, v20, 255);
              v22 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v19, *(__m128 *)(v9 + 112)), _mm_mul_ps(v17, *(__m128 *)(v9 + 96))),
                          _mm_mul_ps(*(__m128 *)(v9 + 16), v16)),
                        _mm_add_ps(v21, _mm_mul_ps(v20, *(__m128 *)v9))),
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), *(__m128 *)(v9 + 32)),
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), *(__m128 *)(v9 + 48))));
              *((__m128 *)v11 - 1) = v22;
              v17 = _mm_shuffle_ps(v22, v22, 255);
              v19 = _mm_shuffle_ps(v22, v22, 170);
            }
            while ( (unsigned __int64)v11 < v18 );
            v26 = v19.m128_i32[0];
            v25 = v17.m128_i32[0];
            v24 = v16.m128_i32[0];
            v23 = v15.m128_i32[0];
          }
          *(_DWORD *)(v9 + 160) = v23;
          *(_DWORD *)(v9 + 164) = v24;
          *(_DWORD *)(v9 + 168) = v25;
          *(_DWORD *)(v9 + 172) = v26;
          if ( v10 & 3 )
            DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(
              (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)v9,
              v11,
              v14,
              0);
        }
        ++v8;
      }
      while ( v8 < v7->m_Reverb.uTCFilterIndex[0] );
    }
  }
}

// File Line: 1063
// RVA: 0xAE29C0
void __fastcall CAkRoomVerbFX::ReverbPreProcess(CAkRoomVerbFX *this, float *io_pfBuffer, unsigned int in_uNumFrames)
{
  unsigned int v3; // ebp
  float *v4; // r14
  CAkRoomVerbFX *v5; // r15
  unsigned __int8 v6; // si
  signed __int64 v7; // rdi
  unsigned int v8; // eax
  float *v9; // rdx
  __int64 v10; // rbx
  unsigned int v11; // eax
  int v12; // er8
  __m128 v13; // xmm7
  __m128 v14; // xmm6
  __m128 v15; // xmm8
  unsigned __int64 v16; // rcx
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  int v21; // [rsp+20h] [rbp-88h]
  int v22; // [rsp+30h] [rbp-78h]
  int v23; // [rsp+40h] [rbp-68h]
  int v24; // [rsp+50h] [rbp-58h]

  v3 = in_uNumFrames;
  v4 = io_pfBuffer;
  v5 = this;
  if ( this->m_pParams->sInvariantParams.bEnableToneControls )
  {
    v6 = 0;
    if ( this->m_Reverb.uTCFilterIndex[0] )
    {
      do
      {
        v7 = (signed __int64)&v5->m_pTCFiltersState[v6];
        if ( *(_DWORD *)(v7 + 176) == 2 )
        {
          v8 = v3;
          v9 = v4;
          if ( (unsigned __int8)v4 & 0xF )
          {
            v10 = v3;
            v11 = (16 - ((unsigned __int8)v4 & 0xFu)) >> 2;
            if ( v11 < v3 )
              v10 = v11;
            DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(
              &v5->m_pTCFiltersState[v6].Filter,
              v4,
              v10,
              0);
            v9 = &v4[v10];
            v8 = v3 - v10;
          }
          v12 = v8 & 3;
          v13 = _mm_shuffle_ps((__m128)*(unsigned int *)(v7 + 160), (__m128)*(unsigned int *)(v7 + 160), 0);
          v14 = _mm_shuffle_ps((__m128)*(unsigned int *)(v7 + 164), (__m128)*(unsigned int *)(v7 + 164), 0);
          v15 = _mm_shuffle_ps((__m128)*(unsigned int *)(v7 + 168), (__m128)*(unsigned int *)(v7 + 168), 0);
          v16 = (unsigned __int64)&v9[v8 - v12];
          v21 = v13.m128_i32[0];
          v22 = v14.m128_i32[0];
          v23 = v15.m128_i32[0];
          v17 = _mm_shuffle_ps((__m128)*(unsigned int *)(v7 + 172), (__m128)*(unsigned int *)(v7 + 172), 0);
          v24 = v17.m128_i32[0];
          if ( (unsigned __int64)v9 < v16 )
          {
            do
            {
              v18 = *(__m128 *)v9;
              v9 += 4;
              v19 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v7 + 80), v14), _mm_mul_ps(*(__m128 *)(v7 + 64), v13));
              v14 = _mm_shuffle_ps(v18, v18, 170);
              v13 = _mm_shuffle_ps(v18, v18, 255);
              v20 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v17, *(__m128 *)(v7 + 112)), _mm_mul_ps(*(__m128 *)(v7 + 96), v15)),
                          _mm_mul_ps(*(__m128 *)(v7 + 16), v14)),
                        _mm_add_ps(_mm_mul_ps(*(__m128 *)v7, v18), v19)),
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), *(__m128 *)(v7 + 48)),
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), *(__m128 *)(v7 + 32))));
              *((__m128 *)v9 - 1) = v20;
              v15 = _mm_shuffle_ps(v20, v20, 255);
              v17 = _mm_shuffle_ps(v20, v20, 170);
            }
            while ( (unsigned __int64)v9 < v16 );
            v24 = v17.m128_i32[0];
            v22 = v14.m128_i32[0];
            v21 = v13.m128_i32[0];
            v23 = v15.m128_i32[0];
          }
          *(_DWORD *)(v7 + 160) = v21;
          *(_DWORD *)(v7 + 164) = v22;
          *(_DWORD *)(v7 + 168) = v23;
          *(_DWORD *)(v7 + 172) = v24;
          if ( v8 & 3 )
            DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(
              (DSP::BiquadFilter<DSP::SingleChannelPolicy> *)v7,
              v9,
              v12,
              0);
        }
        ++v6;
      }
      while ( v6 < v5->m_Reverb.uTCFilterIndex[0] );
    }
  }
}

// File Line: 1075
// RVA: 0xAE2C10
void __fastcall CAkRoomVerbFX::ReverbPostProcess(CAkRoomVerbFX *this, float **out_ppfReverb, unsigned int in_uNumOutSignals, float in_fGain, unsigned int in_uNumFrames)
{
  __int64 v5; // rsi
  float **v6; // rdi
  DSP::OnePoleZeroHPFilter *v7; // rbx

  if ( in_uNumOutSignals )
  {
    v5 = in_uNumOutSignals;
    v6 = out_ppfReverb;
    v7 = this->m_Reverb.DCFilter;
    do
    {
      DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(v7, *v6, in_uNumFrames, in_fGain);
      ++v7;
      ++v6;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 1106
// RVA: 0xAE2C80
signed __int64 __fastcall CAkRoomVerbFX::ProcessSpread1Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r14
  CAkRoomVerbFX *v3; // rsi
  float *v4; // rax
  float *v5; // r13
  float *v7; // r15
  float *v8; // rdi
  float *v9; // r12
  float v10; // xmm10_4
  float v11; // xmm7_4
  __m128 v12; // xmm1
  float v13; // xmm9_4
  float v14; // xmm8_4
  __m128 v15; // xmm1
  unsigned int v16; // ecx
  unsigned int in_uFrameOffset; // eax
  DSP::DelayLine *v18; // rbx
  unsigned int in_uNumFrames; // ebp
  unsigned __int8 v20; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v21; // rcx
  DSP::AllpassFilter *v22; // rbx
  signed __int64 v23; // rdi
  unsigned int v24; // er14
  signed __int64 v25; // rbx
  float **v26; // rbx
  DSP::OnePoleZeroHPFilter *v27; // rdi
  signed __int64 v28; // r14
  float v29; // xmm6_4
  AkAudioBuffer *v30; // r14
  unsigned int v31; // ebx
  unsigned int v32; // edi
  float *v33; // rbx
  float *v34; // r14
  float *v35; // r14
  float in_fTargetGain2; // xmm1_4
  float *v37; // rdx
  float in_fTargetGain3; // xmm1_4
  CAkRoomVerbFXParams *v39; // rdx
  bool v40; // zf
  float *io_pfOutBuffer; // [rsp+50h] [rbp-D8h]
  char *v42; // [rsp+58h] [rbp-D0h]
  unsigned int v43; // [rsp+130h] [rbp+8h]
  AkAudioBuffer *v44; // [rsp+138h] [rbp+10h]
  int v45; // [rsp+140h] [rbp+18h]
  float *in_pfInput3; // [rsp+148h] [rbp+20h]

  v44 = io_pBuffer;
  v2 = io_pBuffer;
  v3 = this;
  v4 = (float *)this->m_pAllocator->vfptr->Malloc(
                  this->m_pAllocator,
                  (unsigned __int64)((unsigned int)(unsigned __int8)this->m_Reverb.uNumERSignals + 4) << 10);
  v5 = v4;
  if ( !v4 )
    return 52i64;
  v7 = v4 + 256;
  v8 = 0i64;
  io_pfOutBuffer = v4 + 512;
  v9 = 0i64;
  in_pfInput3 = 0i64;
  v42 = (char *)(v4 + 768);
  if ( v3->m_Reverb.uNumERSignals )
  {
    v8 = v4 + 1280;
    v9 = v4 + 1024;
    in_pfInput3 = v4 + 1280;
  }
  v10 = 0.0;
  v11 = (float)((float)(v3->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v12 = (__m128)(unsigned int)FLOAT_1_0;
  v12.m128_f32[0] = 1.0 - (float)(v11 * v11);
  if ( v12.m128_f32[0] <= 0.0 )
    v13 = 0.0;
  else
    LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v12);
  v15 = (__m128)(unsigned int)FLOAT_1_0;
  v14 = (float)((float)(v3->m_pParams->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v15.m128_f32[0] = 1.0 - (float)(v14 * v14);
  if ( v15.m128_f32[0] > 0.0 )
    LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v15);
  v16 = v2->uValidFrames;
  in_uFrameOffset = 0;
  v43 = 0;
  v45 = v2->uValidFrames;
  if ( v2->uValidFrames )
  {
    v18 = &v3->m_Reverb.ERDelay;
    do
    {
      in_uNumFrames = 256;
      if ( v16 < 0x100 )
        in_uNumFrames = v16;
      CAkRoomVerbFX::WetPreProcess(v3, v2, v5, in_uNumFrames, in_uFrameOffset);
      if ( v3->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&v3->m_Reverb.ReverbDelay, v5, v7, in_uNumFrames);
      else
        memmove(v7, v5, 4 * in_uNumFrames);
      if ( v18->uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(v18, v5, in_uNumFrames);
      if ( v3->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(v3->m_pERUnit, v5, v9, v8, in_uNumFrames);
        if ( v3->m_pParams->sInvariantParams.bEnableToneControls )
        {
          v20 = 0;
          if ( v3->m_Reverb.uTCFilterIndex[0] )
          {
            do
            {
              v21 = &v3->m_pTCFiltersState[v20].Filter;
              if ( v21[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
              {
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(v21, v9, in_uNumFrames, 0);
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                  &v3->m_pTCFiltersState[v20++ + 1].Filter,
                  v8,
                  in_uNumFrames,
                  0);
              }
              ++v20;
            }
            while ( v20 < v3->m_Reverb.uTCFilterIndex[0] );
          }
        }
      }
      v22 = v3->m_Reverb.DiffusionFilters;
      v23 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(v22, v7, in_uNumFrames);
        ++v22;
        --v23;
      }
      while ( v23 );
      CAkRoomVerbFX::ReverbPreProcess(v3, v7, in_uNumFrames);
      memset(v5 + 512, 0, 0x800ui64);
      v24 = 0;
      if ( v3->m_Reverb.uNumReverbUnits )
      {
        do
        {
          v25 = v24;
          DSP::DelayLine::ProcessBuffer(&v3->m_pReverbUnitsState[v25].RUInputDelay, v7, in_uNumFrames);
          DSP::FDN4::ProcessBufferAccum(
            &v3->m_pReverbUnitsState[v25].ReverbUnits,
            v7,
            (&io_pfOutBuffer)[v24++ & 1],
            in_uNumFrames);
        }
        while ( v24 < v3->m_Reverb.uNumReverbUnits );
      }
      v26 = &io_pfOutBuffer;
      v27 = v3->m_Reverb.DCFilter;
      v28 = 2i64;
      v29 = v3->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(v27, *v26, in_uNumFrames, v29);
        ++v27;
        ++v26;
        --v28;
      }
      while ( v28 );
      v30 = v44;
      v31 = 0;
      v32 = v44->uChannelMask;
      if ( v32 & 1 )
      {
        v33 = (float *)((char *)v44->pData + 4 * v43);
        DSP::Mix3Interp(
          v33,
          v5 + 512,
          v5 + 768,
          v3->m_PrevRTPCParams.fDryLevel,
          v3->m_pParams->sRTPCParams.fDryLevel,
          v3->m_PrevRTPCParams.fReverbLevel * v11,
          v3->m_pParams->sRTPCParams.fReverbLevel * v14,
          v3->m_PrevRTPCParams.fReverbLevel * v13,
          v3->m_pParams->sRTPCParams.fReverbLevel * v10,
          in_uNumFrames);
        if ( v3->m_Reverb.uNumERSignals )
          DSP::Mix3Interp(
            v33,
            v9,
            in_pfInput3,
            1.0,
            1.0,
            v3->m_PrevRTPCParams.fERLevel * v11,
            v3->m_pParams->sRTPCParams.fERLevel * v14,
            v3->m_PrevRTPCParams.fERLevel * v13,
            v3->m_pParams->sRTPCParams.fERLevel * v10,
            in_uNumFrames);
        v31 = 1;
      }
      if ( v32 & 2 )
      {
        v34 = (float *)((char *)v44->pData + 4 * (v43 + v31 * (unsigned __int64)v44->uMaxFrames));
        DSP::Mix3Interp(
          v34,
          v5 + 512,
          v5 + 768,
          v3->m_PrevRTPCParams.fDryLevel,
          v3->m_pParams->sRTPCParams.fDryLevel,
          v3->m_PrevRTPCParams.fReverbLevel * v13,
          v3->m_pParams->sRTPCParams.fReverbLevel * v10,
          v3->m_PrevRTPCParams.fReverbLevel * v11,
          v3->m_pParams->sRTPCParams.fReverbLevel * v14,
          in_uNumFrames);
        if ( v3->m_Reverb.uNumERSignals )
          DSP::Mix3Interp(
            v34,
            v9,
            in_pfInput3,
            1.0,
            1.0,
            v3->m_PrevRTPCParams.fERLevel * v13,
            v3->m_pParams->sRTPCParams.fERLevel * v10,
            v3->m_PrevRTPCParams.fERLevel * v11,
            v3->m_pParams->sRTPCParams.fERLevel * v14,
            in_uNumFrames);
        v30 = v44;
        ++v31;
      }
      if ( v32 & 4 )
      {
        v35 = (float *)((char *)v30->pData + 4 * (v43 + v31 * (unsigned __int64)v30->uMaxFrames));
        DSP::Mix3Interp(
          v35,
          v5 + 512,
          v5 + 768,
          v3->m_PrevRTPCParams.fDryLevel,
          v3->m_pParams->sRTPCParams.fDryLevel,
          v3->m_PrevRTPCParams.fReverbLevel * 0.70710599,
          v3->m_pParams->sRTPCParams.fReverbLevel * 0.70710599,
          v3->m_PrevRTPCParams.fReverbLevel * 0.70710599,
          v3->m_pParams->sRTPCParams.fReverbLevel * 0.70710599,
          in_uNumFrames);
        if ( v3->m_Reverb.uNumERSignals )
        {
          in_fTargetGain2 = v3->m_pParams->sRTPCParams.fERLevel * 0.70710599;
          DSP::Mix3Interp(
            v35,
            v9,
            in_pfInput3,
            1.0,
            1.0,
            v3->m_PrevRTPCParams.fERLevel * 0.70710599,
            in_fTargetGain2,
            v3->m_PrevRTPCParams.fERLevel * 0.70710599,
            in_fTargetGain2,
            in_uNumFrames);
        }
        ++v31;
      }
      v2 = v44;
      if ( v32 & 8 )
      {
        v37 = (float *)v3->m_pParams;
        in_fTargetGain3 = (float)(v37[21] * v37[18]) * 0.70710599;
        DSP::Mix3Interp(
          (float *)v44->pData + v43 + v31 * (unsigned __int64)v44->uMaxFrames,
          v5 + 512,
          v5 + 768,
          v3->m_PrevRTPCParams.fDryLevel,
          v37[19],
          (float)(v3->m_PrevRTPCParams.fReverbLevel * v3->m_PrevRTPCParams.fLFELevel) * 0.70710599,
          in_fTargetGain3,
          (float)(v3->m_PrevRTPCParams.fReverbLevel * v3->m_PrevRTPCParams.fLFELevel) * 0.70710599,
          in_fTargetGain3,
          in_uNumFrames);
      }
      v39 = v3->m_pParams;
      v8 = in_pfInput3;
      v11 = v14;
      v13 = v10;
      v18 = &v3->m_Reverb.ERDelay;
      v3->m_PrevRTPCParams.fDryLevel = v39->sRTPCParams.fDryLevel;
      v3->m_PrevRTPCParams.fERLevel = v39->sRTPCParams.fERLevel;
      v3->m_PrevRTPCParams.fReverbLevel = v39->sRTPCParams.fReverbLevel;
      in_uFrameOffset = in_uNumFrames + v43;
      v3->m_PrevRTPCParams.fLFELevel = v39->sRTPCParams.fLFELevel;
      v43 += in_uNumFrames;
      v40 = v45 == in_uNumFrames;
      v16 = v45 - in_uNumFrames;
      v45 -= in_uNumFrames;
    }
    while ( !v40 );
  }
  v3->m_pAllocator->vfptr->Free(v3->m_pAllocator, v5);
  return 1i64;
}

// File Line: 1322
// RVA: 0xAE34D0
signed __int64 __fastcall CAkRoomVerbFX::ProcessSpread2Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int v2; // eax
  AkAudioBuffer *v3; // r14
  int v4; // edx
  CAkRoomVerbFX *v5; // rsi
  int v6; // ebx
  CAkRoomVerbFXParams *v7; // rax
  AK::IAkPluginMemAlloc *v8; // rcx
  int v9; // ebp
  __int64 v10; // rax
  float *v11; // r15
  float *v13; // r12
  float *v14; // r13
  float *v15; // rdi
  float v16; // xmm9_4
  float v17; // xmm7_4
  __m128 v18; // xmm1
  float v19; // xmm10_4
  CAkRoomVerbFXParams *v20; // rax
  float v21; // xmm8_4
  __m128 v22; // xmm1
  unsigned int in_uFrameOffset; // eax
  unsigned int v24; // ecx
  char v25; // dl
  DSP::DelayLine *v26; // rbx
  unsigned int in_uNumFrames; // ebp
  unsigned __int8 v28; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v29; // rcx
  DSP::AllpassFilter *v30; // rbx
  signed __int64 v31; // rdi
  unsigned int v32; // er14
  signed __int64 v33; // rbx
  float **v34; // rbx
  DSP::OnePoleZeroHPFilter *v35; // rdi
  signed __int64 v36; // r14
  float v37; // xmm6_4
  unsigned int v38; // ebx
  float *v39; // rbx
  float *v40; // rax
  float v41; // xmm3_4
  float *v42; // r14
  float v43; // xmm2_4
  float v44; // xmm3_4
  float *v45; // rdi
  float *v46; // rax
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float *v50; // rdx
  unsigned int v51; // edi
  float in_fTargetGain2; // xmm1_4
  float *v53; // rdi
  float *v54; // rax
  float v55; // xmm3_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float *v58; // rdi
  float *v59; // rax
  float v60; // xmm3_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float *v63; // rdx
  float in_fTargetGain3; // xmm1_4
  CAkRoomVerbFXParams *v65; // rdx
  bool v66; // zf
  float *v67; // [rsp+50h] [rbp-118h]
  float *in_pfInput3; // [rsp+58h] [rbp-110h]
  float *out_pfOutBuffer; // [rsp+60h] [rbp-108h]
  int v70; // [rsp+68h] [rbp-100h]
  int v71; // [rsp+6Ch] [rbp-FCh]
  int v72; // [rsp+70h] [rbp-F8h]
  int v73; // [rsp+74h] [rbp-F4h]
  int v74; // [rsp+78h] [rbp-F0h]
  int v75; // [rsp+7Ch] [rbp-ECh]
  float *io_pfOutBuffer2; // [rsp+80h] [rbp-E8h]
  __int64 v77; // [rsp+88h] [rbp-E0h]
  __int64 v78; // [rsp+90h] [rbp-D8h]
  __int64 v79; // [rsp+98h] [rbp-D0h]
  unsigned int v80; // [rsp+170h] [rbp+8h]
  AkAudioBuffer *v81; // [rsp+178h] [rbp+10h]
  unsigned int v82; // [rsp+180h] [rbp+18h]
  int v83; // [rsp+180h] [rbp+18h]
  int v84; // [rsp+188h] [rbp+20h]

  v81 = io_pBuffer;
  v2 = io_pBuffer->uChannelMask;
  v3 = io_pBuffer;
  v4 = (unsigned __int8)this->m_Reverb.uNumERSignals;
  v82 = v2;
  v5 = this;
  v6 = v2 & 0x30;
  v7 = this->m_pParams;
  v8 = this->m_pAllocator;
  v9 = 0;
  if ( v7->sInvariantParams.bEnableEarlyReflections )
    v9 = v6 != 0 ? 2 : 0;
  v75 = v9;
  v10 = (__int64)v8->vfptr->Malloc(v8, (unsigned __int64)(unsigned int)(v9 + v4 + 6) << 10);
  v11 = (float *)v10;
  if ( !v10 )
    return 52i64;
  v13 = (float *)(v10 + 1024);
  io_pfOutBuffer2 = (float *)(v10 + 2048);
  v14 = 0i64;
  v77 = v10 + 3072;
  v15 = 0i64;
  v78 = v10 + 4096;
  in_pfInput3 = 0i64;
  out_pfOutBuffer = 0i64;
  v67 = 0i64;
  v79 = v10 + 5120;
  if ( v5->m_Reverb.uNumERSignals )
  {
    v15 = (float *)(v10 + 7168);
    v14 = (float *)(v10 + 6144);
    in_pfInput3 = (float *)(v10 + 7168);
    if ( v9 == 2 )
    {
      out_pfOutBuffer = (float *)(v10 + 0x2000);
      v67 = (float *)(v10 + 9216);
    }
  }
  v16 = 0.0;
  v17 = (float)((float)(v5->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v18 = (__m128)(unsigned int)FLOAT_1_0;
  v18.m128_f32[0] = 1.0 - (float)(v17 * v17);
  if ( v18.m128_f32[0] <= 0.0 )
    v19 = 0.0;
  else
    LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v18);
  v20 = v5->m_pParams;
  v22 = (__m128)(unsigned int)FLOAT_1_0;
  v21 = (float)((float)(v20->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v22.m128_f32[0] = 1.0 - (float)(v21 * v21);
  if ( v22.m128_f32[0] > 0.0 )
    LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v22);
  if ( !v6 )
  {
    v20->sRTPCParams.fFrontLevel = 1.0;
    v5->m_pParams->sRTPCParams.fRearLevel = 1.0;
  }
  in_uFrameOffset = 0;
  v80 = 0;
  v24 = v3->uValidFrames;
  v84 = v3->uValidFrames;
  if ( v3->uValidFrames )
  {
    v25 = v82;
    v26 = &v5->m_Reverb.ERDelay;
    v71 = v82 & 1;
    v72 = v82 & 2;
    v74 = v82 & 4;
    v70 = v82 & 0x10;
    v83 = v82 & 8;
    v73 = v25 & 0x20;
    do
    {
      in_uNumFrames = 256;
      if ( v24 < 0x100 )
        in_uNumFrames = v24;
      CAkRoomVerbFX::WetPreProcess(v5, v3, v11, in_uNumFrames, in_uFrameOffset);
      if ( v5->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&v5->m_Reverb.ReverbDelay, v11, v13, in_uNumFrames);
      else
        memmove(v13, v11, 4 * in_uNumFrames);
      if ( v26->uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(v26, v11, in_uNumFrames);
      if ( v5->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(v5->m_pERUnit, v11, v14, v15, in_uNumFrames);
        if ( v5->m_pParams->sInvariantParams.bEnableToneControls )
        {
          v28 = 0;
          if ( v5->m_Reverb.uTCFilterIndex[0] )
          {
            do
            {
              v29 = &v5->m_pTCFiltersState[v28].Filter;
              if ( v29[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
              {
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(v29, v14, in_uNumFrames, 0);
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                  &v5->m_pTCFiltersState[v28++ + 1].Filter,
                  v15,
                  in_uNumFrames,
                  0);
              }
              ++v28;
            }
            while ( v28 < v5->m_Reverb.uTCFilterIndex[0] );
          }
        }
        if ( v75 == 2 )
        {
          if ( v5->m_Reverb.ERFrontBackDelay[0].uDelayLineLength )
          {
            DSP::DelayLine::ProcessBuffer(v5->m_Reverb.ERFrontBackDelay, v14, out_pfOutBuffer, in_uNumFrames);
            DSP::DelayLine::ProcessBuffer(&v5->m_Reverb.ERFrontBackDelay[1], v15, v67, in_uNumFrames);
          }
          else
          {
            out_pfOutBuffer = v14;
            v67 = v15;
          }
        }
      }
      v30 = v5->m_Reverb.DiffusionFilters;
      v31 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(v30, v13, in_uNumFrames);
        ++v30;
        --v31;
      }
      while ( v31 );
      CAkRoomVerbFX::ReverbPreProcess(v5, v13, in_uNumFrames);
      memset(v11 + 512, 0, 0x1000ui64);
      v32 = 0;
      if ( v5->m_Reverb.uNumReverbUnits )
      {
        do
        {
          v33 = v32;
          DSP::DelayLine::ProcessBuffer(&v5->m_pReverbUnitsState[v33].RUInputDelay, v13, in_uNumFrames);
          DSP::FDN4::ProcessBufferAccum(
            &v5->m_pReverbUnitsState[v33].ReverbUnits,
            v13,
            (&io_pfOutBuffer2)[v32 & 1],
            (&io_pfOutBuffer2)[(v32 & 1) + 2],
            in_uNumFrames);
          ++v32;
        }
        while ( v32 < v5->m_Reverb.uNumReverbUnits );
      }
      v34 = &io_pfOutBuffer2;
      v35 = v5->m_Reverb.DCFilter;
      v36 = 4i64;
      v37 = v5->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(v35, *v34, in_uNumFrames, v37);
        ++v35;
        ++v34;
        --v36;
      }
      while ( v36 );
      v38 = 0;
      if ( v71 )
      {
        v39 = (float *)((char *)v81->pData + 4 * v80);
        v40 = (float *)v5->m_pParams;
        v41 = v40[21] * v40[15];
        DSP::Mix3Interp(
          v39,
          v11 + 512,
          v11 + 768,
          v5->m_PrevRTPCParams.fDryLevel,
          v40[19],
          (float)(v5->m_PrevRTPCParams.fFrontLevel * v5->m_PrevRTPCParams.fReverbLevel) * v17,
          v41 * v21,
          (float)(v5->m_PrevRTPCParams.fFrontLevel * v5->m_PrevRTPCParams.fReverbLevel) * v19,
          v41 * v16,
          in_uNumFrames);
        v42 = in_pfInput3;
        if ( v5->m_Reverb.uNumERSignals )
        {
          v43 = v5->m_PrevRTPCParams.fERLevel * v5->m_PrevRTPCParams.fFrontLevel;
          v44 = v5->m_pParams->sRTPCParams.fERLevel * v5->m_pParams->sRTPCParams.fFrontLevel;
          DSP::Mix3Interp(v39, v14, in_pfInput3, 1.0, 1.0, v43 * v17, v44 * v21, v43 * v19, v44 * v16, in_uNumFrames);
        }
        v38 = 1;
      }
      else
      {
        v42 = in_pfInput3;
      }
      if ( v72 )
      {
        v45 = (float *)((char *)v81->pData + 4 * (v80 + v38 * (unsigned __int64)v81->uMaxFrames));
        v46 = (float *)v5->m_pParams;
        v47 = v46[21] * v46[15];
        DSP::Mix3Interp(
          v45,
          v11 + 512,
          v11 + 768,
          v5->m_PrevRTPCParams.fDryLevel,
          v46[19],
          (float)(v5->m_PrevRTPCParams.fFrontLevel * v5->m_PrevRTPCParams.fReverbLevel) * v19,
          v47 * v16,
          (float)(v5->m_PrevRTPCParams.fFrontLevel * v5->m_PrevRTPCParams.fReverbLevel) * v17,
          v47 * v21,
          in_uNumFrames);
        if ( v5->m_Reverb.uNumERSignals )
        {
          v48 = v5->m_PrevRTPCParams.fERLevel * v5->m_PrevRTPCParams.fFrontLevel;
          v49 = v5->m_pParams->sRTPCParams.fERLevel * v5->m_pParams->sRTPCParams.fFrontLevel;
          DSP::Mix3Interp(v45, v14, v42, 1.0, 1.0, v48 * v19, v49 * v16, v48 * v17, v49 * v21, in_uNumFrames);
        }
        ++v38;
      }
      v3 = v81;
      if ( v74 )
      {
        v50 = (float *)v5->m_pParams;
        v51 = v80;
        in_fTargetGain2 = (float)(v50[21] * v50[17]) * 0.70710599;
        DSP::Mix3Interp(
          (float *)v81->pData + v80 + v38++ * (unsigned __int64)v81->uMaxFrames,
          v11 + 1024,
          v11 + 1280,
          v5->m_PrevRTPCParams.fDryLevel,
          v50[19],
          (float)(v5->m_PrevRTPCParams.fReverbLevel * v5->m_PrevRTPCParams.fCenterLevel) * 0.70710599,
          in_fTargetGain2,
          (float)(v5->m_PrevRTPCParams.fReverbLevel * v5->m_PrevRTPCParams.fCenterLevel) * 0.70710599,
          in_fTargetGain2,
          in_uNumFrames);
      }
      else
      {
        v51 = v80;
      }
      if ( v70 )
      {
        v53 = (float *)((char *)v81->pData + 4 * (v51 + v38 * (unsigned __int64)v81->uMaxFrames));
        v54 = (float *)v5->m_pParams;
        v55 = v54[21] * v54[16];
        DSP::Mix3Interp(
          v53,
          v11 + 1024,
          v11 + 1280,
          v5->m_PrevRTPCParams.fDryLevel,
          v54[19],
          (float)(v5->m_PrevRTPCParams.fRearLevel * v5->m_PrevRTPCParams.fReverbLevel) * v17,
          v55 * v21,
          (float)(v5->m_PrevRTPCParams.fRearLevel * v5->m_PrevRTPCParams.fReverbLevel) * v19,
          v55 * v16,
          in_uNumFrames);
        if ( v5->m_Reverb.uNumERSignals )
        {
          v56 = v5->m_PrevRTPCParams.fERLevel * v5->m_PrevRTPCParams.fRearLevel;
          v57 = v5->m_pParams->sRTPCParams.fERLevel * v5->m_pParams->sRTPCParams.fRearLevel;
          DSP::Mix3Interp(
            v53,
            out_pfOutBuffer,
            v67,
            1.0,
            1.0,
            v56 * v17,
            v57 * v21,
            v56 * v19,
            v57 * v16,
            in_uNumFrames);
        }
        ++v38;
      }
      if ( v73 )
      {
        v58 = (float *)((char *)v81->pData + 4 * (v80 + v38 * (unsigned __int64)v81->uMaxFrames));
        v59 = (float *)v5->m_pParams;
        v60 = v59[21] * v59[16];
        DSP::Mix3Interp(
          v58,
          v11 + 1024,
          v11 + 1280,
          v5->m_PrevRTPCParams.fDryLevel,
          v59[19],
          (float)(v5->m_PrevRTPCParams.fRearLevel * v5->m_PrevRTPCParams.fReverbLevel) * v19,
          v60 * v16,
          (float)(v5->m_PrevRTPCParams.fRearLevel * v5->m_PrevRTPCParams.fReverbLevel) * v17,
          v60 * v21,
          in_uNumFrames);
        if ( v5->m_Reverb.uNumERSignals )
        {
          v61 = v5->m_PrevRTPCParams.fERLevel * v5->m_PrevRTPCParams.fRearLevel;
          v62 = v5->m_pParams->sRTPCParams.fERLevel * v5->m_pParams->sRTPCParams.fRearLevel;
          DSP::Mix3Interp(
            v58,
            out_pfOutBuffer,
            v67,
            1.0,
            1.0,
            v61 * v19,
            v62 * v16,
            v61 * v17,
            v62 * v21,
            in_uNumFrames);
        }
        ++v38;
      }
      if ( v83 )
      {
        v63 = (float *)v5->m_pParams;
        in_fTargetGain3 = (float)(v63[21] * v63[18]) * 0.70710599;
        DSP::Mix3Interp(
          (float *)v81->pData + v80 + v38 * (unsigned __int64)v81->uMaxFrames,
          v11 + 1024,
          v11 + 1280,
          v5->m_PrevRTPCParams.fDryLevel,
          v63[19],
          (float)(v5->m_PrevRTPCParams.fLFELevel * v5->m_PrevRTPCParams.fReverbLevel) * 0.70710599,
          in_fTargetGain3,
          (float)(v5->m_PrevRTPCParams.fLFELevel * v5->m_PrevRTPCParams.fReverbLevel) * 0.70710599,
          in_fTargetGain3,
          in_uNumFrames);
      }
      v65 = v5->m_pParams;
      v15 = in_pfInput3;
      v17 = v21;
      v19 = v16;
      v26 = &v5->m_Reverb.ERDelay;
      v5->m_PrevRTPCParams.fDryLevel = v65->sRTPCParams.fDryLevel;
      v5->m_PrevRTPCParams.fERLevel = v65->sRTPCParams.fERLevel;
      v5->m_PrevRTPCParams.fReverbLevel = v65->sRTPCParams.fReverbLevel;
      v5->m_PrevRTPCParams.fFrontLevel = v65->sRTPCParams.fFrontLevel;
      v5->m_PrevRTPCParams.fCenterLevel = v65->sRTPCParams.fCenterLevel;
      v5->m_PrevRTPCParams.fRearLevel = v65->sRTPCParams.fRearLevel;
      in_uFrameOffset = in_uNumFrames + v80;
      v5->m_PrevRTPCParams.fLFELevel = v65->sRTPCParams.fLFELevel;
      v80 += in_uNumFrames;
      v66 = v84 == in_uNumFrames;
      v24 = v84 - in_uNumFrames;
      v84 -= in_uNumFrames;
    }
    while ( !v66 );
  }
  v5->m_pAllocator->vfptr->Free(v5->m_pAllocator, v11);
  return 1i64;
}

// File Line: 1613
// RVA: 0xAE40A0
signed __int64 __fastcall CAkRoomVerbFX::ProcessSpread3Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int v2; // ebp
  AkAudioBuffer *v3; // rbx
  CAkRoomVerbFX *v4; // rsi
  float *v5; // rax
  float *v6; // r15
  float *v8; // r12
  float *v9; // rdi
  float *v10; // r14
  float *v11; // r13
  float v12; // xmm9_4
  float v13; // xmm7_4
  __m128 v14; // xmm1
  float v15; // xmm10_4
  float v16; // xmm8_4
  __m128 v17; // xmm1
  unsigned int v18; // eax
  unsigned int in_uFrameOffset; // ecx
  unsigned int v20; // ebp
  unsigned __int8 v21; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v22; // rcx
  DSP::AllpassFilter *v23; // rbx
  signed __int64 v24; // rdi
  unsigned int v25; // er14
  signed __int64 v26; // rbx
  float **v27; // rbx
  DSP::OnePoleZeroHPFilter *v28; // rdi
  signed __int64 v29; // r14
  float v30; // xmm6_4
  float v31; // xmm2_4
  float *v32; // rbx
  float *v33; // rax
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float *v38; // rbx
  float *v39; // rax
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  unsigned int v43; // ebx
  float *v44; // rdx
  float in_fTargetGain2; // ST30_4
  float in_uNumFrames; // ST28_4
  float v47; // xmm2_4
  float *v48; // rdi
  float *v49; // rax
  float v50; // xmm3_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  unsigned int v53; // ebx
  float *v54; // rdi
  float *v55; // rax
  float v56; // xmm3_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float *v59; // rdx
  __int64 v60; // rcx
  float in_fTargetGain3; // xmm1_4
  CAkRoomVerbFXParams *v62; // rcx
  bool v63; // zf
  int v64; // [rsp+50h] [rbp-118h]
  float *out_pfOutBuffer; // [rsp+58h] [rbp-110h]
  float *in_pfInput2; // [rsp+60h] [rbp-108h]
  float *in_pfInput3; // [rsp+68h] [rbp-100h]
  float *io_pfOutBuffer3; // [rsp+70h] [rbp-F8h]
  char *v69; // [rsp+78h] [rbp-F0h]
  char *v70; // [rsp+80h] [rbp-E8h]
  char *v71; // [rsp+88h] [rbp-E0h]
  char *v72; // [rsp+90h] [rbp-D8h]
  char *v73; // [rsp+98h] [rbp-D0h]
  unsigned int v74; // [rsp+170h] [rbp+8h]
  AkAudioBuffer *v75; // [rsp+178h] [rbp+10h]
  int v76; // [rsp+180h] [rbp+18h]
  int v77; // [rsp+188h] [rbp+20h]

  v75 = io_pBuffer;
  v2 = io_pBuffer->uChannelMask;
  v3 = io_pBuffer;
  v4 = this;
  v5 = (float *)this->m_pAllocator->vfptr->Malloc(
                  this->m_pAllocator,
                  (unsigned __int64)(2 * (unsigned int)(unsigned __int8)this->m_Reverb.uNumERSignals + 8) << 10);
  v6 = v5;
  if ( !v5 )
    return 52i64;
  v8 = v5 + 256;
  io_pfOutBuffer3 = v5 + 512;
  v9 = 0i64;
  v69 = (char *)(v5 + 768);
  v10 = 0i64;
  v70 = (char *)(v5 + 1024);
  v11 = 0i64;
  v71 = (char *)(v5 + 1280);
  in_pfInput3 = 0i64;
  v72 = (char *)(v5 + 1536);
  in_pfInput2 = 0i64;
  out_pfOutBuffer = 0i64;
  v73 = (char *)(v5 + 1792);
  if ( v4->m_Reverb.uNumERSignals )
  {
    v9 = v5 + 2304;
    v10 = v5 + 2560;
    in_pfInput3 = v5 + 2304;
    in_pfInput2 = v5 + 2560;
    out_pfOutBuffer = v5 + 2816;
    v11 = v5 + 2048;
  }
  v12 = 0.0;
  v13 = (float)((float)(v4->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v14 = (__m128)(unsigned int)FLOAT_1_0;
  v14.m128_f32[0] = 1.0 - (float)(v13 * v13);
  if ( v14.m128_f32[0] <= 0.0 )
    v15 = 0.0;
  else
    LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
  v17 = (__m128)(unsigned int)FLOAT_1_0;
  v16 = (float)((float)(v4->m_pParams->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v17.m128_f32[0] = 1.0 - (float)(v16 * v16);
  if ( v17.m128_f32[0] > 0.0 )
    LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v17);
  v18 = v3->uValidFrames;
  in_uFrameOffset = 0;
  v74 = 0;
  v76 = v3->uValidFrames;
  if ( v3->uValidFrames )
  {
    v64 = v2 & 8;
    v77 = v2 & 4;
    do
    {
      v20 = 256;
      if ( v18 < 0x100 )
        v20 = v18;
      CAkRoomVerbFX::WetPreProcess(v4, v3, v6, v20, in_uFrameOffset);
      if ( v4->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&v4->m_Reverb.ReverbDelay, v6, v8, v20);
      else
        memmove(v8, v6, 4 * v20);
      if ( v4->m_Reverb.ERDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&v4->m_Reverb.ERDelay, v6, v20);
      if ( v4->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(v4->m_pERUnit, v6, v11, v9, v20);
        if ( v4->m_pParams->sInvariantParams.bEnableToneControls )
        {
          v21 = 0;
          if ( v4->m_Reverb.uTCFilterIndex[0] )
          {
            do
            {
              v22 = &v4->m_pTCFiltersState[v21].Filter;
              if ( v22[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
              {
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(v22, v11, v20, 0);
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                  &v4->m_pTCFiltersState[v21++ + 1].Filter,
                  v9,
                  v20,
                  0);
              }
              ++v21;
            }
            while ( v21 < v4->m_Reverb.uTCFilterIndex[0] );
          }
        }
        if ( v4->m_Reverb.ERFrontBackDelay[0].uDelayLineLength )
        {
          DSP::DelayLine::ProcessBuffer(v4->m_Reverb.ERFrontBackDelay, v11, v10, v20);
          DSP::DelayLine::ProcessBuffer(&v4->m_Reverb.ERFrontBackDelay[1], v9, out_pfOutBuffer, v20);
        }
        else
        {
          in_pfInput2 = v11;
          out_pfOutBuffer = v9;
        }
      }
      v23 = v4->m_Reverb.DiffusionFilters;
      v24 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(v23, v8, v20);
        ++v23;
        --v24;
      }
      while ( v24 );
      CAkRoomVerbFX::ReverbPreProcess(v4, v8, v20);
      memset(v6 + 512, 0, 0x1800ui64);
      v25 = 0;
      if ( v4->m_Reverb.uNumReverbUnits )
      {
        do
        {
          v26 = v25;
          DSP::DelayLine::ProcessBuffer(&v4->m_pReverbUnitsState[v26].RUInputDelay, v8, v20);
          DSP::FDN4::ProcessBufferAccum(
            &v4->m_pReverbUnitsState[v26].ReverbUnits,
            v8,
            (&io_pfOutBuffer3)[v25 & 1],
            (&io_pfOutBuffer3)[(v25 & 1) + 2],
            (&io_pfOutBuffer3)[(v25 & 1) + 4],
            v20);
          ++v25;
        }
        while ( v25 < v4->m_Reverb.uNumReverbUnits );
      }
      v27 = &io_pfOutBuffer3;
      v28 = v4->m_Reverb.DCFilter;
      v29 = 6i64;
      v30 = v4->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(v28, *v27, v20, v30);
        ++v28;
        ++v27;
        --v29;
      }
      while ( v29 );
      v31 = v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fFrontLevel;
      v32 = (float *)((char *)v75->pData + 4 * v74);
      v33 = (float *)v4->m_pParams;
      v34 = v33[21] * v33[15];
      DSP::Mix3Interp(
        v32,
        v6 + 512,
        v6 + 768,
        v4->m_PrevRTPCParams.fDryLevel,
        v33[19],
        v31 * v13,
        v34 * v16,
        v31 * v15,
        v34 * v12,
        v20);
      if ( v4->m_Reverb.uNumERSignals )
      {
        v35 = v4->m_PrevRTPCParams.fERLevel * v4->m_PrevRTPCParams.fFrontLevel;
        v36 = v4->m_pParams->sRTPCParams.fERLevel * v4->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v32, v11, in_pfInput3, 1.0, 1.0, v35 * v13, v36 * v16, v35 * v15, v36 * v12, v20);
      }
      v37 = v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fFrontLevel;
      v38 = (float *)((char *)v75->pData + 4 * (v74 + (unsigned __int64)v75->uMaxFrames));
      v39 = (float *)v4->m_pParams;
      v40 = v39[21] * v39[15];
      DSP::Mix3Interp(
        v38,
        v6 + 512,
        v6 + 768,
        v4->m_PrevRTPCParams.fDryLevel,
        v39[19],
        v37 * v15,
        v40 * v12,
        v37 * v13,
        v40 * v16,
        v20);
      if ( v4->m_Reverb.uNumERSignals )
      {
        v41 = v4->m_PrevRTPCParams.fERLevel * v4->m_PrevRTPCParams.fFrontLevel;
        v42 = v4->m_pParams->sRTPCParams.fERLevel * v4->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v38, v11, in_pfInput3, 1.0, 1.0, v41 * v15, v42 * v12, v41 * v13, v42 * v16, v20);
      }
      v43 = 2;
      if ( v77 )
      {
        v44 = (float *)v4->m_pParams;
        in_fTargetGain2 = (float)(v44[21] * v44[17]) * 0.70710599;
        in_uNumFrames = (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fCenterLevel) * 0.70710599;
        DSP::Mix3Interp(
          (float *)v75->pData + v74 + 2i64 * v75->uMaxFrames,
          v6 + 1024,
          v6 + 1280,
          v4->m_PrevRTPCParams.fDryLevel,
          v44[19],
          in_uNumFrames,
          in_fTargetGain2,
          in_uNumFrames,
          in_fTargetGain2,
          v20);
        v43 = 3;
      }
      v47 = v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fRearLevel;
      v48 = (float *)((char *)v75->pData + 4 * (v74 + v43 * (unsigned __int64)v75->uMaxFrames));
      v49 = (float *)v4->m_pParams;
      v50 = v49[21] * v49[16];
      DSP::Mix3Interp(
        v48,
        v6 + 1536,
        v6 + 1792,
        v4->m_PrevRTPCParams.fDryLevel,
        v49[19],
        v47 * v13,
        v50 * v16,
        v47 * v15,
        v50 * v12,
        v20);
      if ( v4->m_Reverb.uNumERSignals )
      {
        v51 = v4->m_PrevRTPCParams.fERLevel * v4->m_PrevRTPCParams.fRearLevel;
        v52 = v4->m_pParams->sRTPCParams.fERLevel * v4->m_pParams->sRTPCParams.fRearLevel;
        DSP::Mix3Interp(v48, in_pfInput2, out_pfOutBuffer, 1.0, 1.0, v51 * v13, v52 * v16, v51 * v15, v52 * v12, v20);
      }
      v53 = v43 + 1;
      v54 = (float *)((char *)v75->pData + 4 * (v74 + v53 * (unsigned __int64)v75->uMaxFrames));
      v55 = (float *)v4->m_pParams;
      v56 = v55[21] * v55[16];
      DSP::Mix3Interp(
        v54,
        v6 + 1536,
        v6 + 1792,
        v4->m_PrevRTPCParams.fDryLevel,
        v55[19],
        (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fRearLevel) * v15,
        v56 * v12,
        (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fRearLevel) * v13,
        v56 * v16,
        v20);
      if ( v4->m_Reverb.uNumERSignals )
      {
        v57 = v4->m_PrevRTPCParams.fERLevel * v4->m_PrevRTPCParams.fRearLevel;
        v58 = v4->m_pParams->sRTPCParams.fERLevel * v4->m_pParams->sRTPCParams.fRearLevel;
        DSP::Mix3Interp(v54, in_pfInput2, out_pfOutBuffer, 1.0, 1.0, v57 * v15, v58 * v12, v57 * v13, v58 * v16, v20);
      }
      if ( v64 )
      {
        v59 = (float *)v4->m_pParams;
        v60 = v53 + 1;
        v3 = v75;
        in_fTargetGain3 = (float)(v59[21] * v59[18]) * 0.70710599;
        DSP::Mix3Interp(
          (float *)v75->pData + v74 + v75->uMaxFrames * v60,
          v6 + 1024,
          v6 + 1280,
          v4->m_PrevRTPCParams.fDryLevel,
          v59[19],
          (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fLFELevel) * 0.70710599,
          in_fTargetGain3,
          (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fLFELevel) * 0.70710599,
          in_fTargetGain3,
          v20);
      }
      else
      {
        v3 = v75;
      }
      v62 = v4->m_pParams;
      v9 = in_pfInput3;
      v10 = in_pfInput2;
      v13 = v16;
      v15 = v12;
      v4->m_PrevRTPCParams.fDryLevel = v62->sRTPCParams.fDryLevel;
      v4->m_PrevRTPCParams.fERLevel = v62->sRTPCParams.fERLevel;
      v4->m_PrevRTPCParams.fReverbLevel = v62->sRTPCParams.fReverbLevel;
      v4->m_PrevRTPCParams.fFrontLevel = v62->sRTPCParams.fFrontLevel;
      v4->m_PrevRTPCParams.fCenterLevel = v62->sRTPCParams.fCenterLevel;
      v4->m_PrevRTPCParams.fRearLevel = v62->sRTPCParams.fRearLevel;
      v4->m_PrevRTPCParams.fLFELevel = v62->sRTPCParams.fLFELevel;
      in_uFrameOffset = v20 + v74;
      v63 = v76 == v20;
      v18 = v76 - v20;
      v74 += v20;
      v76 -= v20;
    }
    while ( !v63 );
  }
  v4->m_pAllocator->vfptr->Free(v4->m_pAllocator, v6);
  return 1i64;
}      v4->m_PrevRTPCParams.fRearLevel = v62->sRTPCParams.fRearLevel;
      v4->m_PrevRTPCParams.fLFELevel = v62->sRTPCParams.fLFELevel;
      in_uFrameOffset = v20 + v74;
      v63 = v76 == v20;
      v18 = v76 - v20;
      v74 += v20;
      v76 -= v20;
    }
    while ( !v63 );
  }
  v

// File Line: 1893
// RVA: 0xAE4BB0
signed __int64 __fastcall CAkRoomVerbFX::ProcessSpread4Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int v2; // ebp
  AkAudioBuffer *v3; // r12
  CAkRoomVerbFX *v4; // rsi
  float *v5; // rax
  float *v6; // r13
  unsigned int in_uFrameOffset; // ecx
  float *v9; // r15
  float *v10; // rdi
  float *v11; // r14
  float v12; // xmm7_4
  float v13; // xmm10_4
  float v14; // xmm9_4
  __m128 v15; // xmm1
  float v16; // xmm8_4
  float v17; // xmm15_4
  __m128 v18; // xmm1
  unsigned int v19; // eax
  DSP::DelayLine *v20; // rbx
  unsigned int v21; // ebp
  unsigned __int8 v22; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v23; // rcx
  DSP::AllpassFilter *v24; // rbx
  signed __int64 v25; // rdi
  unsigned int v26; // er14
  signed __int64 v27; // rbx
  float **v28; // rbx
  DSP::OnePoleZeroHPFilter *v29; // rdi
  signed __int64 v30; // r14
  float v31; // xmm6_4
  float *v32; // rbx
  float *v33; // rax
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float *v39; // rbx
  float *v40; // rax
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  unsigned int v44; // ebx
  float *v45; // rdx
  float in_fTargetGain2; // xmm1_4
  float in_uNumFrames; // ST28_4
  float *v48; // rdx
  float v49; // xmm10_4
  float v50; // xmm11_4
  float v51; // xmm12_4
  float *v52; // r14
  float v53; // xmm13_4
  float in_fTargetGain3; // xmm11_4
  float in_fCurrentGain3; // xmm10_4
  float v56; // xmm12_4
  float v57; // xmm8_4
  float v58; // xmm6_4
  float v59; // xmm8_4
  float v60; // xmm13_4
  float v61; // xmm9_4
  float v62; // xmm7_4
  float v63; // xmm9_4
  unsigned int v64; // ebx
  float *v65; // r14
  unsigned int v66; // ebx
  float *v67; // r14
  unsigned int v68; // ebx
  float *v69; // r14
  float *v70; // rdx
  float v71; // xmm1_4
  CAkRoomVerbFXParams *v72; // rcx
  bool v73; // zf
  float *out_pfOutBuffer; // [rsp+50h] [rbp-148h]
  float *v75; // [rsp+58h] [rbp-140h]
  float *in_pfInput3; // [rsp+60h] [rbp-138h]
  float *in_pfInput2; // [rsp+68h] [rbp-130h]
  int v78; // [rsp+70h] [rbp-128h]
  int v79; // [rsp+74h] [rbp-124h]
  float *io_pfOutBuffer3; // [rsp+78h] [rbp-120h]
  char *v81; // [rsp+80h] [rbp-118h]
  char *v82; // [rsp+88h] [rbp-110h]
  char *v83; // [rsp+90h] [rbp-108h]
  char *v84; // [rsp+98h] [rbp-100h]
  char *v85; // [rsp+A0h] [rbp-F8h]
  float v86; // [rsp+1A0h] [rbp+8h]
  float v87; // [rsp+1A8h] [rbp+10h]
  unsigned int v88; // [rsp+1B0h] [rbp+18h]
  int v89; // [rsp+1B8h] [rbp+20h]

  v2 = io_pBuffer->uChannelMask;
  v3 = io_pBuffer;
  v4 = this;
  v5 = (float *)this->m_pAllocator->vfptr->Malloc(
                  this->m_pAllocator,
                  (unsigned __int64)(2 * (unsigned int)(unsigned __int8)this->m_Reverb.uNumERSignals + 8) << 10);
  v6 = v5;
  if ( !v5 )
    return 52i64;
  in_uFrameOffset = 0;
  v9 = v5 + 256;
  io_pfOutBuffer3 = v5 + 512;
  v10 = 0i64;
  v81 = (char *)(v5 + 768);
  in_pfInput2 = 0i64;
  v82 = (char *)(v5 + 1024);
  v11 = 0i64;
  v83 = (char *)(v5 + 1280);
  in_pfInput3 = 0i64;
  v84 = (char *)(v5 + 1536);
  out_pfOutBuffer = 0i64;
  v75 = 0i64;
  v85 = (char *)(v5 + 1792);
  if ( v4->m_Reverb.uNumERSignals )
  {
    v10 = v5 + 2048;
    v11 = v5 + 2304;
    out_pfOutBuffer = v5 + 2560;
    in_pfInput2 = v5 + 2048;
    v75 = v5 + 2816;
    in_pfInput3 = v5 + 2304;
  }
  v12 = 0.0;
  v13 = FLOAT_0_70710599;
  v86 = 0.0;
  v15 = (__m128)(unsigned int)FLOAT_1_0;
  v14 = (float)((float)(v4->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v15.m128_f32[0] = 1.0 - (float)(v14 * v14);
  if ( v15.m128_f32[0] <= 0.0 )
    v16 = 0.0;
  else
    LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
  v18 = (__m128)(unsigned int)FLOAT_1_0;
  v87 = v16;
  v17 = (float)((float)(v4->m_pParams->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v18.m128_f32[0] = 1.0 - (float)(v17 * v17);
  if ( v18.m128_f32[0] > 0.0 )
  {
    LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v18);
    v86 = v12;
  }
  v19 = v3->uValidFrames;
  v88 = 0;
  v89 = v3->uValidFrames;
  if ( v3->uValidFrames )
  {
    v79 = v2 & 8;
    v20 = &v4->m_Reverb.ERDelay;
    v78 = v2 & 4;
    do
    {
      v21 = 256;
      if ( v19 < 0x100 )
        v21 = v19;
      CAkRoomVerbFX::WetPreProcess(v4, v3, v6, v21, in_uFrameOffset);
      if ( v4->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&v4->m_Reverb.ReverbDelay, v6, v9, v21);
      else
        memmove(v9, v6, 4 * v21);
      if ( v20->uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(v20, v6, v21);
      if ( v4->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(v4->m_pERUnit, v6, v10, v11, v21);
        if ( v4->m_pParams->sInvariantParams.bEnableToneControls )
        {
          v22 = 0;
          if ( v4->m_Reverb.uTCFilterIndex[0] )
          {
            do
            {
              v23 = &v4->m_pTCFiltersState[v22].Filter;
              if ( v23[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
              {
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(v23, v10, v21, 0);
                DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                  &v4->m_pTCFiltersState[v22++ + 1].Filter,
                  v11,
                  v21,
                  0);
              }
              ++v22;
            }
            while ( v22 < v4->m_Reverb.uTCFilterIndex[0] );
          }
        }
        if ( v4->m_Reverb.ERFrontBackDelay[0].uDelayLineLength )
        {
          DSP::DelayLine::ProcessBuffer(v4->m_Reverb.ERFrontBackDelay, v10, out_pfOutBuffer, v21);
          DSP::DelayLine::ProcessBuffer(&v4->m_Reverb.ERFrontBackDelay[1], v11, v75, v21);
        }
        else
        {
          out_pfOutBuffer = v10;
          v75 = v11;
        }
      }
      v24 = v4->m_Reverb.DiffusionFilters;
      v25 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(v24, v9, v21);
        ++v24;
        --v25;
      }
      while ( v25 );
      CAkRoomVerbFX::ReverbPreProcess(v4, v9, v21);
      memset(v6 + 512, 0, 0x1800ui64);
      v26 = 0;
      if ( v4->m_Reverb.uNumReverbUnits )
      {
        do
        {
          v27 = v26;
          DSP::DelayLine::ProcessBuffer(&v4->m_pReverbUnitsState[v27].RUInputDelay, v9, v21);
          DSP::FDN4::ProcessBufferAccum(
            &v4->m_pReverbUnitsState[v27].ReverbUnits,
            v9,
            (&io_pfOutBuffer3)[v26 & 1],
            (&io_pfOutBuffer3)[(v26 & 1) + 2],
            (&io_pfOutBuffer3)[(v26 & 1) + 4],
            v21);
          ++v26;
        }
        while ( v26 < v4->m_Reverb.uNumReverbUnits );
      }
      v28 = &io_pfOutBuffer3;
      v29 = v4->m_Reverb.DCFilter;
      v30 = 6i64;
      v31 = v4->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(v29, *v28, v21, v31);
        ++v29;
        ++v28;
        --v30;
      }
      while ( v30 );
      v32 = (float *)((char *)v3->pData + 4 * v88);
      v33 = (float *)v4->m_pParams;
      v34 = v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fFrontLevel;
      v35 = v33[21] * v33[15];
      DSP::Mix3Interp(
        v32,
        v6 + 512,
        v6 + 768,
        v4->m_PrevRTPCParams.fDryLevel,
        v33[19],
        v34 * v14,
        v35 * v17,
        v34 * v16,
        v35 * v12,
        v21);
      if ( v4->m_Reverb.uNumERSignals )
      {
        v36 = v4->m_PrevRTPCParams.fERLevel * v4->m_PrevRTPCParams.fFrontLevel;
        v37 = v4->m_pParams->sRTPCParams.fERLevel * v4->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v32, in_pfInput2, in_pfInput3, 1.0, 1.0, v36 * v14, v37 * v17, v36 * v16, v37 * v12, v21);
      }
      v38 = v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fFrontLevel;
      v39 = (float *)((char *)v3->pData + 4 * (v88 + (unsigned __int64)v3->uMaxFrames));
      v40 = (float *)v4->m_pParams;
      v41 = v40[21] * v40[15];
      DSP::Mix3Interp(
        v39,
        v6 + 512,
        v6 + 768,
        v4->m_PrevRTPCParams.fDryLevel,
        v40[19],
        v38 * v16,
        v41 * v12,
        v38 * v14,
        v41 * v17,
        v21);
      if ( v4->m_Reverb.uNumERSignals )
      {
        v42 = v4->m_PrevRTPCParams.fERLevel * v4->m_PrevRTPCParams.fFrontLevel;
        v43 = v4->m_pParams->sRTPCParams.fERLevel * v4->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v39, in_pfInput2, in_pfInput3, 1.0, 1.0, v42 * v16, v43 * v12, v42 * v14, v43 * v17, v21);
      }
      v44 = 2;
      if ( v78 )
      {
        v45 = (float *)v4->m_pParams;
        in_fTargetGain2 = (float)(v45[21] * v45[17]) * v13;
        in_uNumFrames = (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fCenterLevel) * v13;
        DSP::Mix3Interp(
          (float *)v3->pData + v88 + 2i64 * v3->uMaxFrames,
          v6 + 1024,
          v6 + 1280,
          v4->m_PrevRTPCParams.fDryLevel,
          v45[19],
          in_uNumFrames,
          in_fTargetGain2,
          in_uNumFrames,
          in_fTargetGain2,
          v21);
        v44 = 3;
      }
      v48 = (float *)v4->m_pParams;
      v49 = v4->m_PrevRTPCParams.fRearLevel * v4->m_PrevRTPCParams.fReverbLevel;
      v50 = v48[16] * v48[21];
      v51 = v49;
      v52 = (float *)((char *)v3->pData + 4 * (v88 + v44 * (unsigned __int64)v3->uMaxFrames));
      v53 = v50;
      in_fTargetGain3 = v50 * v86;
      in_fCurrentGain3 = v49 * v16;
      v56 = v51 * v14;
      v57 = v4->m_PrevRTPCParams.fRearLevel * v4->m_PrevRTPCParams.fERLevel;
      v58 = v57 * v87;
      v59 = v57 * v14;
      v60 = v53 * v17;
      v61 = v48[16] * v48[20];
      v62 = v61 * v86;
      v63 = v61 * v17;
      DSP::Mix3Interp(
        v52,
        v6 + 1536,
        v6 + 1792,
        v4->m_PrevRTPCParams.fDryLevel,
        v48[19],
        v56,
        v60,
        in_fCurrentGain3,
        in_fTargetGain3,
        v21);
      if ( v4->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v52, out_pfOutBuffer, v75, 1.0, 1.0, v59, v63, v58, v62, v21);
      v64 = v44 + 1;
      v65 = (float *)((char *)v3->pData + 4 * (v88 + v64 * (unsigned __int64)v3->uMaxFrames));
      DSP::Mix3Interp(
        v65,
        v6 + 1536,
        v6 + 1792,
        v4->m_PrevRTPCParams.fDryLevel,
        v4->m_pParams->sRTPCParams.fDryLevel,
        in_fCurrentGain3,
        in_fTargetGain3,
        v56,
        v60,
        v21);
      if ( v4->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v65, out_pfOutBuffer, v75, 1.0, 1.0, v58, v62, v59, v63, v21);
      v66 = v64 + 1;
      v67 = (float *)((char *)v3->pData + 4 * (v88 + v66 * (unsigned __int64)v3->uMaxFrames));
      DSP::Mix3Interp(
        v67,
        v6 + 1536,
        v6 + 1792,
        v4->m_PrevRTPCParams.fDryLevel,
        v4->m_pParams->sRTPCParams.fDryLevel,
        v56,
        v60,
        in_fCurrentGain3,
        in_fTargetGain3,
        v21);
      if ( v4->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v67, out_pfOutBuffer, v75, 1.0, 1.0, v59, v63, v58, v62, v21);
      v68 = v66 + 1;
      v69 = (float *)((char *)v3->pData + 4 * (v88 + v68 * (unsigned __int64)v3->uMaxFrames));
      DSP::Mix3Interp(
        v69,
        v6 + 1536,
        v6 + 1792,
        v4->m_PrevRTPCParams.fDryLevel,
        v4->m_pParams->sRTPCParams.fDryLevel,
        in_fCurrentGain3,
        in_fTargetGain3,
        v56,
        v60,
        v21);
      if ( v4->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v69, out_pfOutBuffer, v75, 1.0, 1.0, v58, v62, v59, v63, v21);
      v13 = FLOAT_0_70710599;
      if ( v79 )
      {
        v70 = (float *)v4->m_pParams;
        v71 = (float)(v70[21] * v70[18]) * 0.70710599;
        DSP::Mix3Interp(
          (float *)v3->pData + v88 + v3->uMaxFrames * (unsigned __int64)(v68 + 1),
          v6 + 1024,
          v6 + 1280,
          v4->m_PrevRTPCParams.fDryLevel,
          v70[19],
          (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fLFELevel) * 0.70710599,
          v71,
          (float)(v4->m_PrevRTPCParams.fReverbLevel * v4->m_PrevRTPCParams.fLFELevel) * 0.70710599,
          v71,
          v21);
      }
      v72 = v4->m_pParams;
      v12 = v86;
      v10 = in_pfInput2;
      v11 = in_pfInput3;
      v14 = v17;
      v16 = v86;
      v87 = v86;
      v4->m_PrevRTPCParams.fDryLevel = v72->sRTPCParams.fDryLevel;
      v20 = &v4->m_Reverb.ERDelay;
      v4->m_PrevRTPCParams.fERLevel = v72->sRTPCParams.fERLevel;
      v4->m_PrevRTPCParams.fReverbLevel = v72->sRTPCParams.fReverbLevel;
      v4->m_PrevRTPCParams.fFrontLevel = v72->sRTPCParams.fFrontLevel;
      v4->m_PrevRTPCParams.fCenterLevel = v72->sRTPCParams.fCenterLevel;
      v4->m_PrevRTPCParams.fRearLevel = v72->sRTPCParams.fRearLevel;
      v4->m_PrevRTPCParams.fLFELevel = v72->sRTPCParams.fLFELevel;
      in_uFrameOffset = v21 + v88;
      v73 = v89 == v21;
      v19 = v89 - v21;
      v88 += v21;
      v89 -= v21;
    }
    while ( !v73 );
  }
  v4->m_pAllocator->vfptr->Free(v4->m_pAllocator, v6);
  return 1i64;
}

