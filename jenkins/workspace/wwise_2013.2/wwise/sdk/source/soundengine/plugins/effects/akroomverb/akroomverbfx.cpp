// File Line: 53
// RVA: 0xAE1070
void __fastcall CreateRoomVerbFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFX *v1; // rax

  v1 = (CAkRoomVerbFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 496i64);
  if ( v1 )
    CAkRoomVerbFX::CAkRoomVerbFX(v1);
}

// File Line: 60
// RVA: 0xAE10A0
void __fastcall CAkRoomVerbFX::CAkRoomVerbFX(CAkRoomVerbFX *this)
{
  ReverbState *p_m_Reverb; // rcx

  p_m_Reverb = &this->m_Reverb;
  *(_QWORD *)p_m_Reverb[-1].uTCFilterIndex = &CAkRoomVerbFX::`vftable;
  ReverbState::ReverbState(p_m_Reverb);
  this->m_pParams = 0i64;
  this->m_pAllocator = 0i64;
  this->m_pReverbUnitsState = 0i64;
  this->m_pTCFiltersState = 0i64;
  this->m_pERUnit = 0i64;
  memset(&this->m_PrevRTPCParams, 0, sizeof(this->m_PrevRTPCParams));
  *(_QWORD *)&this->m_PrevInvariantParams.uERPattern = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.fRoomSize = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.fDensity = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.uNumReverbUnits = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.fInputLFELevel = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.eFilter1Curve = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.eFilter2Curve = 0i64;
  *(_QWORD *)&this->m_PrevInvariantParams.eFilter3Curve = 0i64;
}

// File Line: 72
// RVA: 0xAE1140
void __fastcall CAkRoomVerbFX::~CAkRoomVerbFX(CAkRoomVerbFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 82
// RVA: 0xAE1160
AKRESULT __fastcall CAkRoomVerbFX::Init(
        CAkRoomVerbFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkRoomVerbFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  unsigned int uSampleRate; // eax
  char v8; // al
  CAkRoomVerbFXParams *m_pParams; // rcx
  char v10; // dl
  char v11; // al
  AKRESULT result; // eax

  uSampleRate = in_rFormat->uSampleRate;
  this->m_pParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  this->m_Reverb.uSampleRate = uSampleRate;
  this->m_Reverb.uNumReverbUnits = in_pParams->sInvariantParams.uNumReverbUnits;
  v8 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  this->m_Reverb.bIsSentMode = v8;
  if ( v8 )
    this->m_pParams->sRTPCParams.fDryLevel = 0.0;
  m_pParams = this->m_pParams;
  this->m_PrevRTPCParams.fDecayTime = m_pParams->sRTPCParams.fDecayTime;
  this->m_PrevRTPCParams.fHFDamping = m_pParams->sRTPCParams.fHFDamping;
  this->m_PrevRTPCParams.fDiffusion = m_pParams->sRTPCParams.fDiffusion;
  this->m_PrevRTPCParams.fStereoWidth = m_pParams->sRTPCParams.fStereoWidth;
  this->m_PrevRTPCParams.fFilter1Gain = m_pParams->sRTPCParams.fFilter1Gain;
  this->m_PrevRTPCParams.fFilter1Freq = m_pParams->sRTPCParams.fFilter1Freq;
  this->m_PrevRTPCParams.fFilter1Q = m_pParams->sRTPCParams.fFilter1Q;
  this->m_PrevRTPCParams.fFilter2Gain = m_pParams->sRTPCParams.fFilter2Gain;
  this->m_PrevRTPCParams.fFilter2Freq = m_pParams->sRTPCParams.fFilter2Freq;
  this->m_PrevRTPCParams.fFilter2Q = m_pParams->sRTPCParams.fFilter2Q;
  this->m_PrevRTPCParams.fFilter3Gain = m_pParams->sRTPCParams.fFilter3Gain;
  this->m_PrevRTPCParams.fFilter3Freq = m_pParams->sRTPCParams.fFilter3Freq;
  this->m_PrevRTPCParams.fFilter3Q = m_pParams->sRTPCParams.fFilter3Q;
  this->m_PrevRTPCParams.fFrontLevel = m_pParams->sRTPCParams.fFrontLevel;
  this->m_PrevRTPCParams.fRearLevel = m_pParams->sRTPCParams.fRearLevel;
  this->m_PrevRTPCParams.fCenterLevel = m_pParams->sRTPCParams.fCenterLevel;
  this->m_PrevRTPCParams.fLFELevel = m_pParams->sRTPCParams.fLFELevel;
  this->m_PrevRTPCParams.fDryLevel = m_pParams->sRTPCParams.fDryLevel;
  this->m_PrevRTPCParams.fERLevel = m_pParams->sRTPCParams.fERLevel;
  this->m_PrevRTPCParams.fReverbLevel = m_pParams->sRTPCParams.fReverbLevel;
  *(_DWORD *)&this->m_PrevRTPCParams.bDirty = *(_DWORD *)&m_pParams->sRTPCParams.bDirty;
  v10 = m_pParams->sInvariantParams.bEnableEarlyReflections ? 2 : 0;
  this->m_Reverb.uNumERSignals = v10;
  v11 = v10;
  if ( (*((_DWORD *)in_rFormat + 1) & 0x3FFFF) == 8 )
    v11 = 0;
  this->m_Reverb.uNumERSignals = v11;
  CAkRoomVerbFX::SetupDCFilters(this);
  result = CAkRoomVerbFX::SetupToneControlFilters(this);
  if ( result == AK_Success )
  {
    result = CAkRoomVerbFX::SetupFDNs(this, in_pAllocator);
    if ( result == AK_Success )
    {
      result = CAkRoomVerbFX::SetupERDelay(this, in_pAllocator);
      if ( result == AK_Success )
      {
        result = CAkRoomVerbFX::SetupReverbDelay(this, in_pAllocator);
        if ( result == AK_Success )
        {
          result = CAkRoomVerbFX::SetupERUnit(this, in_pAllocator);
          if ( result == AK_Success )
          {
            result = CAkRoomVerbFX::SetupERFrontBackDelay(this, in_pAllocator, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
            if ( result == AK_Success )
            {
              result = CAkRoomVerbFX::SetupDiffusionAPF(this, in_pAllocator);
              if ( result == AK_Success )
              {
                this->m_Reverb.uTailLength = (int)(float)((float)((float)(this->m_pParams->sInvariantParams.fReverbDelay
                                                                        * 0.001)
                                                                + this->m_pParams->sRTPCParams.fDecayTime)
                                                        * (float)(int)this->m_Reverb.uSampleRate);
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return result;
}    }
            }
      

// File Line: 171
// RVA: 0xAE17C0
void __fastcall CAkRoomVerbFX::SetupDCFilters(CAkRoomVerbFX *this)
{
  this->m_Reverb.DCFilter[0].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[1].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[2].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[3].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[4].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(int)this->m_Reverb.uSampleRate);
  this->m_Reverb.DCFilter[5].m_fA1 = 1.0
                                   - (float)((float)(this->m_pParams->sAlgoTunings.fDCFilterCutFreq * 6.2831855)
                                           / (float)(int)this->m_Reverb.uSampleRate);
}

// File Line: 180
// RVA: 0xAE1910
void __fastcall CAkRoomVerbFX::ComputeTCCoefs1(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *m_pParams; // rdx
  FilterInsertType eFilter1Pos; // eax
  CAkRoomVerbFXParams *v4; // rdx

  m_pParams = this->m_pParams;
  if ( m_pParams->sInvariantParams.bEnableToneControls )
  {
    eFilter1Pos = m_pParams->sInvariantParams.eFilter1Pos;
    if ( eFilter1Pos )
    {
      if ( eFilter1Pos != FILTERINSERTTYPE_ERONLY || this->m_Reverb.uNumERSignals )
      {
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
          &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[1]].Filter,
          (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)m_pParams->sInvariantParams.eFilter1Curve,
          (float)(int)this->m_Reverb.uSampleRate,
          m_pParams->sRTPCParams.fFilter1Freq,
          m_pParams->sRTPCParams.fFilter1Gain,
          m_pParams->sRTPCParams.fFilter1Q);
        this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[1]].FilterPos = this->m_pParams->sInvariantParams.eFilter1Pos;
        v4 = this->m_pParams;
        if ( v4->sInvariantParams.eFilter1Pos == FILTERINSERTTYPE_ERONLY && this->m_Reverb.uNumERSignals == 2 )
        {
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
            &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[1] + 1].Filter,
            (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v4->sInvariantParams.eFilter1Curve,
            (float)(int)this->m_Reverb.uSampleRate,
            v4->sRTPCParams.fFilter1Freq,
            v4->sRTPCParams.fFilter1Gain,
            v4->sRTPCParams.fFilter1Q);
          this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[1] + 1].FilterPos = this->m_pParams->sInvariantParams.eFilter1Pos;
        }
      }
    }
  }
}

// File Line: 205
// RVA: 0xAE1A70
void __fastcall CAkRoomVerbFX::ComputeTCCoefs2(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *m_pParams; // rdx
  FilterInsertType eFilter2Pos; // eax
  CAkRoomVerbFXParams *v4; // rdx

  m_pParams = this->m_pParams;
  if ( m_pParams->sInvariantParams.bEnableToneControls )
  {
    eFilter2Pos = m_pParams->sInvariantParams.eFilter2Pos;
    if ( eFilter2Pos )
    {
      if ( eFilter2Pos != FILTERINSERTTYPE_ERONLY || this->m_Reverb.uNumERSignals )
      {
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
          &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[2]].Filter,
          (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)m_pParams->sInvariantParams.eFilter2Curve,
          (float)(int)this->m_Reverb.uSampleRate,
          m_pParams->sRTPCParams.fFilter2Freq,
          m_pParams->sRTPCParams.fFilter2Gain,
          m_pParams->sRTPCParams.fFilter2Q);
        this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[2]].FilterPos = this->m_pParams->sInvariantParams.eFilter2Pos;
        v4 = this->m_pParams;
        if ( v4->sInvariantParams.eFilter2Pos == FILTERINSERTTYPE_ERONLY && this->m_Reverb.uNumERSignals == 2 )
        {
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
            &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[2] + 1].Filter,
            (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v4->sInvariantParams.eFilter2Curve,
            (float)(int)this->m_Reverb.uSampleRate,
            v4->sRTPCParams.fFilter2Freq,
            v4->sRTPCParams.fFilter2Gain,
            v4->sRTPCParams.fFilter2Q);
          this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[2] + 1].FilterPos = this->m_pParams->sInvariantParams.eFilter2Pos;
        }
      }
    }
  }
}

// File Line: 230
// RVA: 0xAE1BD0
void __fastcall CAkRoomVerbFX::ComputeTCCoefs3(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *m_pParams; // rdx
  FilterInsertType eFilter3Pos; // eax
  CAkRoomVerbFXParams *v4; // rdx

  m_pParams = this->m_pParams;
  if ( m_pParams->sInvariantParams.bEnableToneControls )
  {
    eFilter3Pos = m_pParams->sInvariantParams.eFilter3Pos;
    if ( eFilter3Pos )
    {
      if ( eFilter3Pos != FILTERINSERTTYPE_ERONLY || this->m_Reverb.uNumERSignals )
      {
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
          &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[3]].Filter,
          (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)m_pParams->sInvariantParams.eFilter3Curve,
          (float)(int)this->m_Reverb.uSampleRate,
          m_pParams->sRTPCParams.fFilter3Freq,
          m_pParams->sRTPCParams.fFilter3Gain,
          m_pParams->sRTPCParams.fFilter3Q);
        this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[3]].FilterPos = this->m_pParams->sInvariantParams.eFilter3Pos;
        v4 = this->m_pParams;
        if ( v4->sInvariantParams.eFilter3Pos == FILTERINSERTTYPE_ERONLY && this->m_Reverb.uNumERSignals == 2 )
        {
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
            &this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[3] + 1].Filter,
            (DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType)v4->sInvariantParams.eFilter3Curve,
            (float)(int)this->m_Reverb.uSampleRate,
            v4->sRTPCParams.fFilter3Freq,
            v4->sRTPCParams.fFilter3Gain,
            v4->sRTPCParams.fFilter3Q);
          this->m_pTCFiltersState[(unsigned __int8)this->m_Reverb.uTCFilterIndex[3] + 1].FilterPos = this->m_pParams->sInvariantParams.eFilter3Pos;
        }
      }
    }
  }
}

// File Line: 255
// RVA: 0xAE71D0
__int64 __fastcall CAkRoomVerbFX::SetupToneControlFilters(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *m_pParams; // rax
  unsigned int uNumERSignals; // edi
  FilterInsertType eFilter1Pos; // eax
  FilterInsertType eFilter2Pos; // eax
  FilterInsertType eFilter3Pos; // eax
  __int64 v7; // rsi
  ToneControlsState *v8; // rax
  __int64 v10; // rdi
  ToneControlsState *v11; // rcx

  m_pParams = this->m_pParams;
  uNumERSignals = 0;
  if ( m_pParams->sInvariantParams.bEnableToneControls )
  {
    this->m_Reverb.uTCFilterIndex[1] = 0;
    eFilter1Pos = m_pParams->sInvariantParams.eFilter1Pos;
    if ( eFilter1Pos == FILTERINSERTTYPE_ERONLY )
    {
      uNumERSignals = (unsigned __int8)this->m_Reverb.uNumERSignals;
    }
    else if ( (unsigned int)(eFilter1Pos - 2) <= 1 )
    {
      uNumERSignals = 1;
    }
    this->m_Reverb.uTCFilterIndex[2] = uNumERSignals;
    eFilter2Pos = this->m_pParams->sInvariantParams.eFilter2Pos;
    if ( eFilter2Pos == FILTERINSERTTYPE_ERONLY )
    {
      uNumERSignals += (unsigned __int8)this->m_Reverb.uNumERSignals;
    }
    else if ( (unsigned int)(eFilter2Pos - 2) <= 1 )
    {
      ++uNumERSignals;
    }
    this->m_Reverb.uTCFilterIndex[3] = uNumERSignals;
    eFilter3Pos = this->m_pParams->sInvariantParams.eFilter3Pos;
    if ( eFilter3Pos == FILTERINSERTTYPE_ERONLY )
    {
      uNumERSignals += (unsigned __int8)this->m_Reverb.uNumERSignals;
    }
    else if ( (unsigned int)(eFilter3Pos - 2) <= 1 )
    {
      ++uNumERSignals;
    }
  }
  this->m_Reverb.uTCFilterIndex[0] = uNumERSignals;
  if ( uNumERSignals )
  {
    v7 = uNumERSignals;
    v8 = (ToneControlsState *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 192i64 * uNumERSignals);
    this->m_pTCFiltersState = v8;
    if ( !v8 )
      return 52i64;
    v10 = 0i64;
    do
    {
      v11 = &this->m_pTCFiltersState[v10];
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
  CAkRoomVerbFX::ComputeTCCoefs1(this);
  CAkRoomVerbFX::ComputeTCCoefs2(this);
  CAkRoomVerbFX::ComputeTCCoefs3(this);
  return 1i64;
}

// File Line: 320
// RVA: 0xAE6BC0
AKRESULT __fastcall CAkRoomVerbFX::SetupERDelay(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFXParams *m_pParams; // rbx
  float v5; // xmm0_4
  __int64 uERPattern; // rax
  float v7; // xmm1_4
  float v8; // xmm0_4
  unsigned int v9; // eax

  if ( !this->m_Reverb.uNumERSignals )
    return 1;
  m_pParams = this->m_pParams;
  v5 = powf(2.0, m_pParams->sInvariantParams.fRoomSize * 0.0099999998);
  uERPattern = m_pParams->sInvariantParams.uERPattern;
  v7 = v5 * g_ERPatternsList[uERPattern].TapInfoLeft->fTapTime;
  v8 = v5 * g_ERPatternsList[uERPattern].TapInfoRight->fTapTime;
  if ( v7 >= v8 )
    v7 = v8;
  v9 = (int)(float)((float)(int)this->m_Reverb.uSampleRate * (float)(v7 * 0.001));
  if ( v9 )
    return DSP::DelayLine::Init(&this->m_Reverb.ERDelay, in_pAllocator, v9);
  else
    return 1;
}

// File Line: 341
// RVA: 0xAE7180
AKRESULT __fastcall CAkRoomVerbFX::SetupReverbDelay(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int v2; // eax

  v2 = (int)(float)((float)(this->m_pParams->sInvariantParams.fReverbDelay * 0.001)
                  * (float)(int)this->m_Reverb.uSampleRate);
  if ( v2 )
    return DSP::DelayLine::Init(&this->m_Reverb.ReverbDelay, in_pAllocator, v2);
  else
    return 1;
}

// File Line: 352
// RVA: 0xAE6C90
AKRESULT __fastcall CAkRoomVerbFX::SetupERFrontBackDelay(
        CAkRoomVerbFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        char in_uChannelMask)
{
  unsigned int v6; // esi
  AKRESULT result; // eax

  if ( !this->m_Reverb.uNumERSignals )
    return 1;
  v6 = (int)(float)((float)(this->m_pParams->sInvariantParams.fERFrontBackDelay * 0.001)
                  * (float)(int)this->m_Reverb.uSampleRate);
  if ( !v6 )
    return 1;
  if ( (in_uChannelMask & 0x10) == 0
    || (result = DSP::DelayLine::Init(this->m_Reverb.ERFrontBackDelay, in_pAllocator, v6), result == AK_Success) )
  {
    if ( (in_uChannelMask & 0x20) == 0 )
      return 1;
    result = DSP::DelayLine::Init(&this->m_Reverb.ERFrontBackDelay[1], in_pAllocator, v6);
    if ( result == AK_Success )
      return 1;
  }
  return result;
}

// File Line: 376
// RVA: 0xAE6D40
__int64 __fastcall CAkRoomVerbFX::SetupERUnit(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int v4; // ecx
  __int64 uERPattern; // rbp
  _QWORD *v6; // rbx

  v4 = 1;
  uERPattern = this->m_pParams->sInvariantParams.uERPattern;
  if ( this->m_Reverb.uNumERSignals )
  {
    v6 = in_pAllocator->vfptr->Malloc(in_pAllocator, 800i64);
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
    this->m_pERUnit = (DSP::ERUnitDual *)v6;
    if ( !v6 )
      return 52i64;
    return (unsigned int)DSP::ERUnitDual::Init(
                           (DSP::ERUnitDual *)v6,
                           in_pAllocator,
                           this->m_pParams->sInvariantParams.fRoomSize,
                           g_ERPatternsList[uERPattern].TapInfoLeft,
                           g_ERPatternsList[uERPattern].TapInfoRight,
                           g_ERPatternsList[uERPattern].uNumTapsLeft,
                           g_ERPatternsList[uERPattern].uNumTapsRight,
                           this->m_Reverb.uSampleRate);
  }
  return v4;
}

// File Line: 397
// RVA: 0xAE6E70
AKRESULT __fastcall CAkRoomVerbFX::SetupFDNs(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  ReverbUnitState *v4; // rax
  AKRESULT result; // eax
  unsigned int v6; // ebx
  unsigned int i; // ecx
  ReverbUnitState *v8; // rax
  unsigned int uNumReverbUnits; // r8d
  __m128 v10; // xmm0
  __int64 v11; // rsi
  __int64 v12; // r8
  __int64 v13; // r9
  unsigned int v14; // r10d
  unsigned int *v15; // r11
  char *v16; // rdx
  __int64 v17; // rbp
  unsigned int v18; // eax
  __int64 v19; // rax
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  __int64 v22; // rcx
  __int64 v23; // rdx
  float uSampleRate; // xmm1_4
  float v25; // xmm0_4
  int j; // esi
  __int64 v27; // r14
  float out_pfFDNInputDelayTimes[32]; // [rsp+30h] [rbp-398h] BYREF
  unsigned int out_puDelayLengths[64]; // [rsp+B0h] [rbp-318h] BYREF
  float in_pfDelayTimes[66]; // [rsp+1B0h] [rbp-218h] BYREF
  char v31; // [rsp+2B8h] [rbp-110h] BYREF

  v4 = (ReverbUnitState *)in_pAllocator->vfptr->Malloc(in_pAllocator, 168i64 * this->m_Reverb.uNumReverbUnits);
  this->m_pReverbUnitsState = v4;
  if ( !v4 )
    return 52;
  v6 = 0;
  for ( i = 0; i < this->m_Reverb.uNumReverbUnits; ++i )
  {
    v8 = &this->m_pReverbUnitsState[i];
    if ( v8 )
    {
      v8->ReverbUnits.FDNDelayLine[0].uDelayLineLength = 0;
      v8->ReverbUnits.FDNDelayLine[0].pfDelay = 0i64;
      v8->ReverbUnits.FDNDelayLine[0].uCurOffset = 0;
      v8->ReverbUnits.FDNDelayLine[1].uDelayLineLength = 0;
      v8->ReverbUnits.FDNDelayLine[1].pfDelay = 0i64;
      v8->ReverbUnits.FDNDelayLine[1].uCurOffset = 0;
      v8->ReverbUnits.FDNDelayLine[2].uDelayLineLength = 0;
      v8->ReverbUnits.FDNDelayLine[2].pfDelay = 0i64;
      v8->ReverbUnits.FDNDelayLine[2].uCurOffset = 0;
      v8->ReverbUnits.FDNDelayLine[3].uDelayLineLength = 0;
      v8->ReverbUnits.FDNDelayLine[3].pfDelay = 0i64;
      v8->ReverbUnits.FDNDelayLine[3].uCurOffset = 0;
      *(_QWORD *)&v8->ReverbUnits.delayLowPassFilter[0].fFFbk1 = 0i64;
      *(_QWORD *)&v8->ReverbUnits.delayLowPassFilter[0].fA1 = 0i64;
      *(_QWORD *)&v8->ReverbUnits.delayLowPassFilter[1].fB0 = 0i64;
      *(_QWORD *)&v8->ReverbUnits.delayLowPassFilter[2].fFFbk1 = 0i64;
      *(_QWORD *)&v8->ReverbUnits.delayLowPassFilter[2].fA1 = 0i64;
      *(_QWORD *)&v8->ReverbUnits.delayLowPassFilter[3].fB0 = 0i64;
      v8->RUInputDelay.uDelayLineLength = 0;
      v8->RUInputDelay.pfDelay = 0i64;
      v8->RUInputDelay.uCurOffset = 0;
    }
  }
  uNumReverbUnits = this->m_Reverb.uNumReverbUnits;
  this->m_Reverb.fReverbUnitsMixGain = 1.0;
  if ( uNumReverbUnits > 1 )
  {
    v10 = 0i64;
    v10.m128_f32[0] = (float)(int)uNumReverbUnits;
    this->m_Reverb.fReverbUnitsMixGain = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  }
  DelayLengths::ComputeFDNDelayTimes(
    this->m_pParams->sInvariantParams.fDensity,
    this->m_pParams->sInvariantParams.fRoomShape,
    4 * uNumReverbUnits,
    &this->m_pParams->sAlgoTunings,
    in_pfDelayTimes);
  DelayLengths::ComputePrimeDelayLengths(
    in_pfDelayTimes,
    this->m_Reverb.uSampleRate,
    4 * this->m_Reverb.uNumReverbUnits,
    (char *)out_puDelayLengths);
  v11 = this->m_Reverb.uNumReverbUnits;
  if ( (_DWORD)v11 )
  {
    v12 = (unsigned int)(3 * v11);
    v13 = (unsigned int)(2 * v11);
    v14 = this->m_Reverb.uNumReverbUnits;
    v15 = out_puDelayLengths;
    v16 = &v31;
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
  DelayLengths::ComputeFDNInputDelayTimes(v11, &this->m_pParams->sAlgoTunings, out_pfFDNInputDelayTimes);
  if ( (_DWORD)v11 )
  {
    v22 = 0i64;
    v23 = v11;
    uSampleRate = (float)(int)this->m_Reverb.uSampleRate;
    do
    {
      v25 = out_pfFDNInputDelayTimes[v22++];
      LODWORD(out_pfFDNInputDelayTimes[v22 + 15]) = (int)(float)((float)(v25 * 0.001) * uSampleRate);
      --v23;
    }
    while ( v23 );
  }
  if ( !(_DWORD)v11 )
    return 1;
  for ( j = 0; ; j += 4 )
  {
    v27 = v6;
    result = DSP::FDN4::Init(
               &this->m_pReverbUnitsState[v27].ReverbUnits,
               in_pAllocator,
               (unsigned int *)&in_pfDelayTimes[j + 64],
               this->m_pParams->sRTPCParams.fDecayTime,
               this->m_pParams->sRTPCParams.fHFDamping,
               this->m_Reverb.uSampleRate);
    if ( result != AK_Success )
      break;
    result = DSP::DelayLine::Init(
               &this->m_pReverbUnitsState[v27].RUInputDelay,
               in_pAllocator,
               LODWORD(out_pfFDNInputDelayTimes[v6 + 16]));
    if ( result != AK_Success )
      break;
    if ( ++v6 >= this->m_Reverb.uNumReverbUnits )
      return 1;
  }
  return result;
}

// File Line: 465
// RVA: 0xAE6A90
AKRESULT __fastcall CAkRoomVerbFX::SetupDiffusionAPF(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  __int64 v4; // rbx
  unsigned int *v5; // rdi
  float v6; // xmm3_4
  AKRESULT result; // eax
  float in_pfDelayTimes[4]; // [rsp+20h] [rbp-68h] BYREF
  char out_puDelayLengths[48]; // [rsp+30h] [rbp-58h] BYREF

  DelayLengths::ComputeDiffusionFiltersDelayTimes(4, &this->m_pParams->sAlgoTunings, in_pfDelayTimes);
  DelayLengths::ComputePrimeDelayLengths(in_pfDelayTimes, this->m_Reverb.uSampleRate, 4u, out_puDelayLengths);
  v4 = 0i64;
  v5 = (unsigned int *)out_puDelayLengths;
  do
  {
    v6 = (float)((float)((float)(this->m_pParams->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0)
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
               (DSP::AllpassFilter *)((char *)this->m_Reverb.DiffusionFilters + 16 * v4 + 8 * (unsigned int)v4),
               in_pAllocator,
               *v5,
               v6);
    if ( result != AK_Success )
      break;
    v4 = (unsigned int)(v4 + 1);
    ++v5;
  }
  while ( (unsigned int)v4 < 4 );
  return result;
}

// File Line: 492
// RVA: 0xAE1390
__int64 __fastcall CAkRoomVerbFX::Term(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::ERUnitDual *m_pERUnit; // rcx
  ReverbState *p_m_Reverb; // rbx
  __int64 v6; // rbp

  DSP::DelayLine::Term(&this->m_Reverb.ERDelay, in_pAllocator);
  DSP::DelayLine::Term(&this->m_Reverb.ReverbDelay, in_pAllocator);
  DSP::DelayLine::Term(this->m_Reverb.ERFrontBackDelay, in_pAllocator);
  DSP::DelayLine::Term(&this->m_Reverb.ERFrontBackDelay[1], in_pAllocator);
  if ( this->m_Reverb.uNumERSignals )
  {
    m_pERUnit = this->m_pERUnit;
    if ( m_pERUnit )
    {
      DSP::ERUnitDual::Term(m_pERUnit, in_pAllocator);
      if ( this->m_pERUnit )
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
      this->m_pERUnit = 0i64;
    }
  }
  if ( this->m_pTCFiltersState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pTCFiltersState = 0i64;
  }
  CAkRoomVerbFX::TermFDNs(this, in_pAllocator);
  p_m_Reverb = &this->m_Reverb;
  v6 = 4i64;
  do
  {
    DSP::AllpassFilter::Term(p_m_Reverb->DiffusionFilters, in_pAllocator);
    p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
    --v6;
  }
  while ( v6 );
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 507
// RVA: 0xAE1D30
void __fastcall CAkRoomVerbFX::TermToneControlFilters(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pTCFiltersState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pTCFiltersState = 0i64;
  }
}

// File Line: 521
// RVA: 0xAE1D70
void __fastcall CAkRoomVerbFX::TermFDNs(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int i; // esi
  __int64 v5; // rdi

  if ( this->m_pReverbUnitsState )
  {
    for ( i = 0; i < this->m_Reverb.uNumReverbUnits; ++i )
    {
      v5 = i;
      DSP::FDN4::Term(&this->m_pReverbUnitsState[v5].ReverbUnits, in_pAllocator);
      DSP::DelayLine::Term(&this->m_pReverbUnitsState[v5].RUInputDelay, in_pAllocator);
    }
    in_pAllocator->vfptr->Free(in_pAllocator, this->m_pReverbUnitsState);
    this->m_pReverbUnitsState = 0i64;
  }
}

// File Line: 537
// RVA: 0xAE1E20
void __fastcall CAkRoomVerbFX::TermDiffusionAPF(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  ReverbState *p_m_Reverb; // rbx
  __int64 v4; // rdi

  p_m_Reverb = &this->m_Reverb;
  v4 = 4i64;
  do
  {
    DSP::AllpassFilter::Term(p_m_Reverb->DiffusionFilters, in_pAllocator);
    p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
    --v4;
  }
  while ( v4 );
}

// File Line: 545
// RVA: 0xAE1E70
void __fastcall CAkRoomVerbFX::TermERUnit(CAkRoomVerbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::ERUnitDual *m_pERUnit; // rcx

  if ( this->m_Reverb.uNumERSignals )
  {
    m_pERUnit = this->m_pERUnit;
    if ( m_pERUnit )
    {
      DSP::ERUnitDual::Term(m_pERUnit, in_pAllocator);
      if ( this->m_pERUnit )
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
      this->m_pERUnit = 0i64;
    }
  }
}

// File Line: 559
// RVA: 0xAE14A0
__int64 __fastcall CAkRoomVerbFX::Reset(CAkRoomVerbFX *this)
{
  DSP::ERUnitDual *m_pERUnit; // rcx
  __int64 v3; // rdx
  ToneControlsState *m_pTCFiltersState; // rax
  __int64 v5; // rcx
  ReverbState *p_m_Reverb; // rbx
  __int64 v7; // rdi

  DSP::DelayLine::Reset(&this->m_Reverb.ERDelay);
  DSP::DelayLine::Reset(&this->m_Reverb.ReverbDelay);
  DSP::DelayLine::Reset(this->m_Reverb.ERFrontBackDelay);
  DSP::DelayLine::Reset(&this->m_Reverb.ERFrontBackDelay[1]);
  m_pERUnit = this->m_pERUnit;
  if ( m_pERUnit )
    DSP::ERUnitDual::Reset(m_pERUnit);
  v3 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[0].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[1].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[2].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[3].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[4].m_fFFwd1 = 0i64;
  *(_QWORD *)&this->m_Reverb.DCFilter[5].m_fFFwd1 = 0i64;
  if ( this->m_pParams->sInvariantParams.bEnableToneControls && this->m_Reverb.uTCFilterIndex[0] )
  {
    do
    {
      m_pTCFiltersState = this->m_pTCFiltersState;
      v5 = v3;
      v3 = (unsigned int)(v3 + 1);
      *(_QWORD *)&m_pTCFiltersState[v5].Filter.m_Memories.m_Memories.fFFwd1 = 0i64;
      *(_QWORD *)&m_pTCFiltersState[v5].Filter.m_Memories.m_Memories.fFFbk1 = 0i64;
    }
    while ( (unsigned int)v3 < (unsigned __int8)this->m_Reverb.uTCFilterIndex[0] );
  }
  CAkRoomVerbFX::ResetFDNs(this);
  p_m_Reverb = &this->m_Reverb;
  v7 = 4i64;
  do
  {
    DSP::AllpassFilter::Reset(p_m_Reverb->DiffusionFilters);
    p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
    --v7;
  }
  while ( v7 );
  return 1i64;
}

// File Line: 573
// RVA: 0xAE1ED0
void __fastcall CAkRoomVerbFX::ResetFDNs(CAkRoomVerbFX *this)
{
  unsigned int i; // esi
  __int64 v3; // rdi

  if ( this->m_pReverbUnitsState )
  {
    for ( i = 0; i < this->m_Reverb.uNumReverbUnits; ++i )
    {
      v3 = i;
      DSP::FDN4::Reset(&this->m_pReverbUnitsState[v3].ReverbUnits);
      DSP::DelayLine::Reset(&this->m_pReverbUnitsState[v3].RUInputDelay);
    }
  }
}

// File Line: 585
// RVA: 0xAE1F50
void __fastcall CAkRoomVerbFX::ResetDiffusionAPF(CAkRoomVerbFX *this)
{
  ReverbState *p_m_Reverb; // rbx
  __int64 v2; // rdi

  p_m_Reverb = &this->m_Reverb;
  v2 = 4i64;
  do
  {
    DSP::AllpassFilter::Reset(p_m_Reverb->DiffusionFilters);
    p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
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
  __int64 i; // rdx
  ToneControlsState *m_pTCFiltersState; // rax
  __int64 v4; // rcx

  if ( this->m_pParams->sInvariantParams.bEnableToneControls )
  {
    for ( i = 0i64;
          (unsigned int)i < (unsigned __int8)this->m_Reverb.uTCFilterIndex[0];
          *(_QWORD *)&m_pTCFiltersState[v4].Filter.m_Memories.m_Memories.fFFbk1 = 0i64 )
    {
      m_pTCFiltersState = this->m_pTCFiltersState;
      v4 = i;
      i = (unsigned int)(i + 1);
      *(_QWORD *)&m_pTCFiltersState[v4].Filter.m_Memories.m_Memories.fFFwd1 = 0i64;
    }
  }
}

// File Line: 612
// RVA: 0xAE2020
void __fastcall CAkRoomVerbFX::ResetERUnit(CAkRoomVerbFX *this)
{
  DSP::ERUnitDual *m_pERUnit; // rcx

  m_pERUnit = this->m_pERUnit;
  if ( m_pERUnit )
    DSP::ERUnitDual::Reset(m_pERUnit);
}

// File Line: 621
// RVA: 0xAE15A0
__int64 __fastcall CAkRoomVerbFX::GetPluginInfo(CAkRoomVerbFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 633
// RVA: 0xAE2040
char __fastcall CAkRoomVerbFX::LiveParametersUpdate(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  CAkRoomVerbFXParams *m_pParams; // rcx
  AK::IAkPluginMemAlloc *m_pAllocator; // rdx
  AK::IAkPluginMemAlloc *v7; // rdi
  DSP::ERUnitDual *m_pERUnit; // rcx
  CAkRoomVerbFXParams *v9; // rax
  AK::IAkPluginMemAlloc *v10; // rdx
  char v11; // al
  char v12; // cl
  DSP::ERUnitDual *v13; // rcx
  CAkRoomVerbFXParams *v14; // rax
  CAkRoomVerbFXParams *v15; // rcx
  DSP::ERUnitDual *v16; // rcx
  CAkRoomVerbFXParams *v17; // rcx
  bool bEnableToneControls; // dl
  CAkRoomVerbFXParams *v19; // rcx

  m_pParams = this->m_pParams;
  if ( this->m_PrevInvariantParams.uNumReverbUnits != m_pParams->sInvariantParams.uNumReverbUnits
    || m_pParams->sInvariantParams.fRoomShape != this->m_PrevInvariantParams.fRoomShape
    || m_pParams->sInvariantParams.fDensity != this->m_PrevInvariantParams.fDensity )
  {
    CAkRoomVerbFX::TermFDNs(this, this->m_pAllocator);
    m_pAllocator = this->m_pAllocator;
    this->m_Reverb.uNumReverbUnits = this->m_pParams->sInvariantParams.uNumReverbUnits;
    if ( CAkRoomVerbFX::SetupFDNs(this, m_pAllocator) != AK_Success )
      return 1;
    CAkRoomVerbFX::ResetFDNs(this);
  }
  if ( this->m_PrevInvariantParams.bEnableEarlyReflections != this->m_pParams->sInvariantParams.bEnableEarlyReflections )
  {
    DSP::DelayLine::Term(this->m_Reverb.ERFrontBackDelay, this->m_pAllocator);
    DSP::DelayLine::Term(&this->m_Reverb.ERFrontBackDelay[1], this->m_pAllocator);
    DSP::DelayLine::Term(&this->m_Reverb.ERDelay, this->m_pAllocator);
    v7 = this->m_pAllocator;
    if ( this->m_Reverb.uNumERSignals )
    {
      m_pERUnit = this->m_pERUnit;
      if ( m_pERUnit )
      {
        DSP::ERUnitDual::Term(m_pERUnit, this->m_pAllocator);
        if ( this->m_pERUnit )
          ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v7->vfptr->Free)(v7);
        this->m_pERUnit = 0i64;
      }
    }
    v9 = this->m_pParams;
    if ( v9->sInvariantParams.bEnableToneControls
      && (v9->sInvariantParams.eFilter1Pos || v9->sInvariantParams.eFilter2Pos || v9->sInvariantParams.eFilter3Pos)
      && this->m_pTCFiltersState )
    {
      ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
      this->m_pTCFiltersState = 0i64;
    }
    v10 = this->m_pAllocator;
    v11 = this->m_pParams->sInvariantParams.bEnableEarlyReflections ? 2 : 0;
    this->m_Reverb.uNumERSignals = v11;
    v12 = v11;
    if ( io_pBuffer->uChannelMask == 8 )
      v12 = 0;
    this->m_Reverb.uNumERSignals = v12;
    if ( CAkRoomVerbFX::SetupERFrontBackDelay(this, v10, io_pBuffer->uChannelMask) != AK_Success )
      return 1;
    DSP::DelayLine::Reset(this->m_Reverb.ERFrontBackDelay);
    DSP::DelayLine::Reset(&this->m_Reverb.ERFrontBackDelay[1]);
    if ( CAkRoomVerbFX::SetupERDelay(this, this->m_pAllocator) != AK_Success )
      return 1;
    DSP::DelayLine::Reset(&this->m_Reverb.ERDelay);
    if ( CAkRoomVerbFX::SetupERUnit(this, this->m_pAllocator) != AK_Success )
      return 1;
    v13 = this->m_pERUnit;
    if ( v13 )
      DSP::ERUnitDual::Reset(v13);
    v14 = this->m_pParams;
    if ( v14->sInvariantParams.bEnableToneControls
      && (v14->sInvariantParams.eFilter1Pos || v14->sInvariantParams.eFilter2Pos || v14->sInvariantParams.eFilter3Pos) )
    {
      if ( CAkRoomVerbFX::SetupToneControlFilters(this) != AK_Success )
        return 1;
      CAkRoomVerbFX::ResetToneControlFilters(this);
    }
  }
  if ( this->m_pParams->sInvariantParams.fERFrontBackDelay != this->m_PrevInvariantParams.fERFrontBackDelay )
  {
    DSP::DelayLine::Term(this->m_Reverb.ERFrontBackDelay, this->m_pAllocator);
    DSP::DelayLine::Term(&this->m_Reverb.ERFrontBackDelay[1], this->m_pAllocator);
    if ( CAkRoomVerbFX::SetupERFrontBackDelay(this, this->m_pAllocator, io_pBuffer->uChannelMask) != AK_Success )
      return 1;
    DSP::DelayLine::Reset(this->m_Reverb.ERFrontBackDelay);
    DSP::DelayLine::Reset(&this->m_Reverb.ERFrontBackDelay[1]);
  }
  v15 = this->m_pParams;
  if ( v15->sInvariantParams.fReverbDelay != this->m_PrevInvariantParams.fReverbDelay )
  {
    DSP::DelayLine::Term(&this->m_Reverb.ReverbDelay, this->m_pAllocator);
    if ( CAkRoomVerbFX::SetupReverbDelay(this, this->m_pAllocator) == AK_Success )
    {
      DSP::DelayLine::Reset(&this->m_Reverb.ReverbDelay);
      v15 = this->m_pParams;
      this->m_Reverb.uTailLength = (int)(float)((float)((float)(v15->sInvariantParams.fReverbDelay * 0.001)
                                                      + v15->sRTPCParams.fDecayTime)
                                              * (float)(int)this->m_Reverb.uSampleRate);
      goto LABEL_38;
    }
    return 1;
  }
LABEL_38:
  if ( this->m_PrevInvariantParams.uERPattern != v15->sInvariantParams.uERPattern
    || v15->sInvariantParams.fRoomSize != this->m_PrevInvariantParams.fRoomSize )
  {
    DSP::DelayLine::Term(&this->m_Reverb.ERDelay, this->m_pAllocator);
    if ( CAkRoomVerbFX::SetupERDelay(this, this->m_pAllocator) != AK_Success )
      return 1;
    DSP::DelayLine::Reset(&this->m_Reverb.ERDelay);
    CAkRoomVerbFX::TermERUnit(this, this->m_pAllocator);
    if ( CAkRoomVerbFX::SetupERUnit(this, this->m_pAllocator) != AK_Success )
      return 1;
    v16 = this->m_pERUnit;
    if ( v16 )
      DSP::ERUnitDual::Reset(v16);
  }
  v17 = this->m_pParams;
  bEnableToneControls = v17->sInvariantParams.bEnableToneControls;
  if ( (this->m_PrevInvariantParams.bEnableToneControls != bEnableToneControls
     || this->m_PrevInvariantParams.eFilter1Pos != v17->sInvariantParams.eFilter1Pos
     || this->m_PrevInvariantParams.eFilter2Pos != v17->sInvariantParams.eFilter2Pos
     || this->m_PrevInvariantParams.eFilter3Pos != v17->sInvariantParams.eFilter3Pos)
    && bEnableToneControls
    && (v17->sInvariantParams.eFilter1Pos || v17->sInvariantParams.eFilter2Pos || v17->sInvariantParams.eFilter3Pos) )
  {
    CAkRoomVerbFX::TermToneControlFilters(this, this->m_pAllocator);
    if ( CAkRoomVerbFX::SetupToneControlFilters(this) != AK_Success )
      return 1;
    CAkRoomVerbFX::ResetToneControlFilters(this);
  }
  if ( this->m_PrevInvariantParams.eFilter1Curve != this->m_pParams->sInvariantParams.eFilter1Curve )
    CAkRoomVerbFX::ComputeTCCoefs1(this);
  if ( this->m_PrevInvariantParams.eFilter2Curve != this->m_pParams->sInvariantParams.eFilter2Curve )
    CAkRoomVerbFX::ComputeTCCoefs2(this);
  if ( this->m_PrevInvariantParams.eFilter3Curve != this->m_pParams->sInvariantParams.eFilter3Curve )
    CAkRoomVerbFX::ComputeTCCoefs3(this);
  v19 = this->m_pParams;
  this->m_PrevInvariantParams.uERPattern = v19->sInvariantParams.uERPattern;
  this->m_PrevInvariantParams.fReverbDelay = v19->sInvariantParams.fReverbDelay;
  this->m_PrevInvariantParams.fRoomSize = v19->sInvariantParams.fRoomSize;
  this->m_PrevInvariantParams.fERFrontBackDelay = v19->sInvariantParams.fERFrontBackDelay;
  this->m_PrevInvariantParams.fDensity = v19->sInvariantParams.fDensity;
  this->m_PrevInvariantParams.fRoomShape = v19->sInvariantParams.fRoomShape;
  this->m_PrevInvariantParams.uNumReverbUnits = v19->sInvariantParams.uNumReverbUnits;
  this->m_PrevInvariantParams.fInputCenterLevel = v19->sInvariantParams.fInputCenterLevel;
  this->m_PrevInvariantParams.fInputLFELevel = v19->sInvariantParams.fInputLFELevel;
  this->m_PrevInvariantParams.eFilter1Pos = v19->sInvariantParams.eFilter1Pos;
  this->m_PrevInvariantParams.eFilter1Curve = v19->sInvariantParams.eFilter1Curve;
  this->m_PrevInvariantParams.eFilter2Pos = v19->sInvariantParams.eFilter2Pos;
  this->m_PrevInvariantParams.eFilter2Curve = v19->sInvariantParams.eFilter2Curve;
  this->m_PrevInvariantParams.eFilter3Pos = v19->sInvariantParams.eFilter3Pos;
  this->m_PrevInvariantParams.eFilter3Curve = v19->sInvariantParams.eFilter3Curve;
  *(_DWORD *)&this->m_PrevInvariantParams.bEnableToneControls = *(_DWORD *)&v19->sInvariantParams.bEnableToneControls;
  v19->sInvariantParams.bDirty = 0;
  return 0;
}nableToneControls;
  v19->sInvariantParams.bDirty = 0;
  return 0;
}

// File Line: 755
// RVA: 0xAE25F0
void __fastcall CAkRoomVerbFX::RTPCParametersUpdate(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *m_pParams; // rcx
  CAkRoomVerbFXParams *v3; // rax
  CAkRoomVerbFXParams *v4; // rax
  CAkRoomVerbFXParams *v5; // rax
  CAkRoomVerbFXParams *v6; // rax

  m_pParams = this->m_pParams;
  if ( this->m_PrevRTPCParams.fDecayTime != m_pParams->sRTPCParams.fDecayTime
    || this->m_PrevRTPCParams.fHFDamping != m_pParams->sRTPCParams.fHFDamping )
  {
    CAkRoomVerbFX::ChangeDecay(this);
    m_pParams = this->m_pParams;
    this->m_Reverb.uTailLength = (int)(float)((float)((float)(m_pParams->sInvariantParams.fReverbDelay * 0.001)
                                                    + m_pParams->sRTPCParams.fDecayTime)
                                            * (float)(int)this->m_Reverb.uSampleRate);
  }
  if ( this->m_PrevRTPCParams.fDiffusion != m_pParams->sRTPCParams.fDiffusion )
    CAkRoomVerbFX::ChangeDiffusion(this);
  v3 = this->m_pParams;
  if ( this->m_PrevRTPCParams.fFilter1Gain != v3->sRTPCParams.fFilter1Gain
    || this->m_PrevRTPCParams.fFilter1Freq != v3->sRTPCParams.fFilter1Freq
    || this->m_PrevRTPCParams.fFilter1Q != v3->sRTPCParams.fFilter1Q )
  {
    CAkRoomVerbFX::ComputeTCCoefs1(this);
  }
  v4 = this->m_pParams;
  if ( this->m_PrevRTPCParams.fFilter2Gain != v4->sRTPCParams.fFilter2Gain
    || this->m_PrevRTPCParams.fFilter2Freq != v4->sRTPCParams.fFilter2Freq
    || this->m_PrevRTPCParams.fFilter2Q != v4->sRTPCParams.fFilter2Q )
  {
    CAkRoomVerbFX::ComputeTCCoefs2(this);
  }
  v5 = this->m_pParams;
  if ( this->m_PrevRTPCParams.fFilter3Gain != v5->sRTPCParams.fFilter3Gain
    || this->m_PrevRTPCParams.fFilter3Freq != v5->sRTPCParams.fFilter3Freq
    || this->m_PrevRTPCParams.fFilter3Q != v5->sRTPCParams.fFilter3Q )
  {
    CAkRoomVerbFX::ComputeTCCoefs3(this);
  }
  v6 = this->m_pParams;
  if ( this->m_Reverb.bIsSentMode )
  {
    v6->sRTPCParams.fDryLevel = 0.0;
    v6 = this->m_pParams;
  }
  v6->sRTPCParams.bDirty = 0;
}

// File Line: 804
// RVA: 0xAE15C0
void __fastcall CAkRoomVerbFX::Execute(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int uChannelMask; // ecx
  unsigned int v5; // ecx
  CAkRoomVerbFXParams *m_pParams; // rcx

  if ( !this->m_pParams->sInvariantParams.bDirty || !CAkRoomVerbFX::LiveParametersUpdate(this, io_pBuffer) )
  {
    if ( this->m_pParams->sRTPCParams.bDirty )
      CAkRoomVerbFX::RTPCParametersUpdate(this);
    AkFXTailHandler::HandleTail(&this->m_Reverb.FXTailHandler, io_pBuffer, this->m_Reverb.uTailLength);
    if ( io_pBuffer->uValidFrames )
    {
      uChannelMask = io_pBuffer->uChannelMask;
      if ( uChannelMask <= 0x37 )
      {
        if ( uChannelMask != 55 )
        {
          switch ( uChannelMask )
          {
            case 3u:
            case 4u:
            case 8u:
            case 0xBu:
            case 0xCu:
              CAkRoomVerbFX::ProcessSpread1Out(this, io_pBuffer);
              break;
            case 7u:
            case 0xFu:
            case 0x33u:
              CAkRoomVerbFX::ProcessSpread2Out(this, io_pBuffer);
              break;
            default:
              goto LABEL_20;
          }
          goto LABEL_20;
        }
        goto LABEL_16;
      }
      if ( uChannelMask > 0x637 )
      {
        v5 = uChannelMask - 1595;
        if ( v5 && v5 != 4 )
          goto LABEL_20;
      }
      else if ( uChannelMask != 1591 )
      {
        if ( ((uChannelMask - 59) & 0xFFFFFFFB) == 0 )
        {
LABEL_16:
          CAkRoomVerbFX::ProcessSpread3Out(this, io_pBuffer);
LABEL_20:
          m_pParams = this->m_pParams;
          this->m_PrevRTPCParams.fDecayTime = m_pParams->sRTPCParams.fDecayTime;
          this->m_PrevRTPCParams.fHFDamping = m_pParams->sRTPCParams.fHFDamping;
          this->m_PrevRTPCParams.fDiffusion = m_pParams->sRTPCParams.fDiffusion;
          this->m_PrevRTPCParams.fStereoWidth = m_pParams->sRTPCParams.fStereoWidth;
          this->m_PrevRTPCParams.fFilter1Gain = m_pParams->sRTPCParams.fFilter1Gain;
          this->m_PrevRTPCParams.fFilter1Freq = m_pParams->sRTPCParams.fFilter1Freq;
          this->m_PrevRTPCParams.fFilter1Q = m_pParams->sRTPCParams.fFilter1Q;
          this->m_PrevRTPCParams.fFilter2Gain = m_pParams->sRTPCParams.fFilter2Gain;
          this->m_PrevRTPCParams.fFilter2Freq = m_pParams->sRTPCParams.fFilter2Freq;
          this->m_PrevRTPCParams.fFilter2Q = m_pParams->sRTPCParams.fFilter2Q;
          this->m_PrevRTPCParams.fFilter3Gain = m_pParams->sRTPCParams.fFilter3Gain;
          this->m_PrevRTPCParams.fFilter3Freq = m_pParams->sRTPCParams.fFilter3Freq;
          this->m_PrevRTPCParams.fFilter3Q = m_pParams->sRTPCParams.fFilter3Q;
          this->m_PrevRTPCParams.fFrontLevel = m_pParams->sRTPCParams.fFrontLevel;
          this->m_PrevRTPCParams.fRearLevel = m_pParams->sRTPCParams.fRearLevel;
          this->m_PrevRTPCParams.fCenterLevel = m_pParams->sRTPCParams.fCenterLevel;
          this->m_PrevRTPCParams.fLFELevel = m_pParams->sRTPCParams.fLFELevel;
          this->m_PrevRTPCParams.fDryLevel = m_pParams->sRTPCParams.fDryLevel;
          this->m_PrevRTPCParams.fERLevel = m_pParams->sRTPCParams.fERLevel;
          this->m_PrevRTPCParams.fReverbLevel = m_pParams->sRTPCParams.fReverbLevel;
          *(_DWORD *)&this->m_PrevRTPCParams.bDirty = *(_DWORD *)&m_pParams->sRTPCParams.bDirty;
          return;
        }
        if ( uChannelMask != 1587 )
          goto LABEL_20;
      }
      CAkRoomVerbFX::ProcessSpread4Out(this, io_pBuffer);
      goto LABEL_20;
    }
  }
}

// File Line: 1026
// RVA: 0xAE6210
void __fastcall CAkRoomVerbFX::ChangeDiffusion(CAkRoomVerbFX *this)
{
  CAkRoomVerbFXParams *m_pParams; // rax
  float v2; // xmm1_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  m_pParams = this->m_pParams;
  v2 = (float)((float)((float)(m_pParams->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0) - 1.85409;
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 0.61803001 )
  {
    v2 = FLOAT_0_61803001;
  }
  this->m_Reverb.DiffusionFilters[0].fG = v2;
  v3 = (float)((float)((float)(m_pParams->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0) - 1.23606;
  if ( v3 <= 0.0 )
  {
    v3 = 0.0;
  }
  else if ( v3 >= 0.61803001 )
  {
    v3 = FLOAT_0_61803001;
  }
  this->m_Reverb.DiffusionFilters[1].fG = v3;
  v4 = (float)((float)((float)(m_pParams->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0) - 0.61803001;
  if ( v4 <= 0.0 )
  {
    v4 = 0.0;
  }
  else if ( v4 >= 0.61803001 )
  {
    v4 = FLOAT_0_61803001;
  }
  this->m_Reverb.DiffusionFilters[2].fG = v4;
  v5 = (float)((float)(m_pParams->sRTPCParams.fDiffusion * 0.0099999998) * 0.61803001) * 4.0;
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
  unsigned int i; // edi

  for ( i = 0; i < this->m_Reverb.uNumReverbUnits; ++i )
    DSP::FDN4::ChangeDecay(
      &this->m_pReverbUnitsState[i].ReverbUnits,
      this->m_pParams->sRTPCParams.fDecayTime,
      this->m_pParams->sRTPCParams.fHFDamping,
      this->m_Reverb.uSampleRate);
}

// File Line: 1048
// RVA: 0xAE2750
void __fastcall CAkRoomVerbFX::WetPreProcess(
        CAkRoomVerbFX *this,
        AkAudioBuffer *in_pBuffer,
        float *out_pfWetIn,
        unsigned int in_uNumFrames,
        unsigned int in_uFrameOffset)
{
  unsigned __int8 i; // si
  ToneControlsState *v9; // rdi
  unsigned int v10; // eax
  float *v11; // rdx
  __int64 v12; // rbx
  unsigned int v13; // eax
  int v14; // r8d
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  __m128 v17; // xmm0
  float *v18; // rcx
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  float v23; // [rsp+40h] [rbp-68h]
  float v24; // [rsp+50h] [rbp-58h]
  float v25; // [rsp+60h] [rbp-48h]
  float v26; // [rsp+70h] [rbp-38h]

  DSP::ConstantPowerChannelMixdown(
    in_pBuffer,
    in_uNumFrames,
    in_uFrameOffset,
    out_pfWetIn,
    in_pBuffer->uChannelMask,
    this->m_pParams->sInvariantParams.fInputCenterLevel,
    this->m_pParams->sInvariantParams.fInputLFELevel);
  if ( this->m_pParams->sInvariantParams.bEnableToneControls )
  {
    for ( i = 0; i < (unsigned int)this->m_Reverb.uTCFilterIndex[0]; ++i )
    {
      v9 = &this->m_pTCFiltersState[i];
      if ( v9->FilterPos == FILTERINSERTTYPE_ERANDREVERB )
      {
        v10 = in_uNumFrames;
        v11 = out_pfWetIn;
        if ( ((unsigned __int8)out_pfWetIn & 0xF) != 0 )
        {
          v12 = in_uNumFrames;
          v13 = (16 - ((unsigned __int8)out_pfWetIn & 0xFu)) >> 2;
          if ( v13 < in_uNumFrames )
            v12 = v13;
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(
            &this->m_pTCFiltersState[i].Filter,
            out_pfWetIn,
            v12,
            0);
          v11 = &out_pfWetIn[v12];
          v10 = in_uNumFrames - v12;
        }
        v14 = v10 & 3;
        v15 = _mm_shuffle_ps(
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFwd1),
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFwd1),
                0);
        v16 = _mm_shuffle_ps(
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFwd2),
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFwd2),
                0);
        v17 = _mm_shuffle_ps(
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFbk1),
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFbk1),
                0);
        v18 = &v11[v10 - v14];
        v23 = v15.m128_f32[0];
        v24 = v16.m128_f32[0];
        v25 = v17.m128_f32[0];
        v19 = _mm_shuffle_ps(
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFbk2),
                (__m128)LODWORD(v9->Filter.m_Memories.m_Memories.fFFbk2),
                0);
        v26 = v19.m128_f32[0];
        if ( v11 < v18 )
        {
          do
          {
            v20 = *(__m128 *)v11;
            v11 += 4;
            v21 = _mm_add_ps(
                    _mm_mul_ps(v9->Filter.m_Coefficients.vXPrev2, v16),
                    _mm_mul_ps(v9->Filter.m_Coefficients.vXPrev1, v15));
            v16 = _mm_shuffle_ps(v20, v20, 170);
            v15 = _mm_shuffle_ps(v20, v20, 255);
            v22 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(v19, v9->Filter.m_Coefficients.vYPrev2),
                          _mm_mul_ps(v17, v9->Filter.m_Coefficients.vYPrev1)),
                        _mm_mul_ps(v9->Filter.m_Coefficients.vSecond, v16)),
                      _mm_add_ps(v21, _mm_mul_ps(v20, v9->Filter.m_Coefficients.vFirst))),
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v9->Filter.m_Coefficients.vThird),
                      _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v9->Filter.m_Coefficients.vFourth)));
            *((__m128 *)v11 - 1) = v22;
            v17 = _mm_shuffle_ps(v22, v22, 255);
            v19 = _mm_shuffle_ps(v22, v22, 170);
          }
          while ( v11 < v18 );
          v26 = v19.m128_f32[0];
          v25 = v17.m128_f32[0];
          v24 = v16.m128_f32[0];
          v23 = v15.m128_f32[0];
        }
        v9->Filter.m_Memories.m_Memories.fFFwd1 = v23;
        v9->Filter.m_Memories.m_Memories.fFFwd2 = v24;
        v9->Filter.m_Memories.m_Memories.fFFbk1 = v25;
        v9->Filter.m_Memories.m_Memories.fFFbk2 = v26;
        if ( (v10 & 3) != 0 )
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(&v9->Filter, v11, v14, 0);
      }
    }
  }
}

// File Line: 1063
// RVA: 0xAE29C0
void __fastcall CAkRoomVerbFX::ReverbPreProcess(CAkRoomVerbFX *this, float *io_pfBuffer, unsigned int in_uNumFrames)
{
  unsigned __int8 i; // si
  ToneControlsState *v7; // rdi
  unsigned int v8; // eax
  float *v9; // rdx
  __int64 v10; // rbx
  unsigned int v11; // eax
  int v12; // r8d
  __m128 v13; // xmm7
  __m128 v14; // xmm6
  __m128 v15; // xmm8
  float *v16; // rcx
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  float v21; // [rsp+20h] [rbp-88h]
  float v22; // [rsp+30h] [rbp-78h]
  float v23; // [rsp+40h] [rbp-68h]
  float v24; // [rsp+50h] [rbp-58h]

  if ( this->m_pParams->sInvariantParams.bEnableToneControls )
  {
    for ( i = 0; i < (unsigned int)this->m_Reverb.uTCFilterIndex[0]; ++i )
    {
      v7 = &this->m_pTCFiltersState[i];
      if ( v7->FilterPos == FILTERINSERTTYPE_REVERBONLY )
      {
        v8 = in_uNumFrames;
        v9 = io_pfBuffer;
        if ( ((unsigned __int8)io_pfBuffer & 0xF) != 0 )
        {
          v10 = in_uNumFrames;
          v11 = (16 - ((unsigned __int8)io_pfBuffer & 0xFu)) >> 2;
          if ( v11 < in_uNumFrames )
            v10 = v11;
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(
            &this->m_pTCFiltersState[i].Filter,
            io_pfBuffer,
            v10,
            0);
          v9 = &io_pfBuffer[v10];
          v8 = in_uNumFrames - v10;
        }
        v12 = v8 & 3;
        v13 = _mm_shuffle_ps(
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFwd1),
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFwd1),
                0);
        v14 = _mm_shuffle_ps(
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFwd2),
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFwd2),
                0);
        v15 = _mm_shuffle_ps(
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFbk1),
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFbk1),
                0);
        v16 = &v9[v8 - v12];
        v21 = v13.m128_f32[0];
        v22 = v14.m128_f32[0];
        v23 = v15.m128_f32[0];
        v17 = _mm_shuffle_ps(
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFbk2),
                (__m128)LODWORD(v7->Filter.m_Memories.m_Memories.fFFbk2),
                0);
        v24 = v17.m128_f32[0];
        if ( v9 < v16 )
        {
          do
          {
            v18 = *(__m128 *)v9;
            v9 += 4;
            v19 = _mm_add_ps(
                    _mm_mul_ps(v7->Filter.m_Coefficients.vXPrev2, v14),
                    _mm_mul_ps(v7->Filter.m_Coefficients.vXPrev1, v13));
            v14 = _mm_shuffle_ps(v18, v18, 170);
            v13 = _mm_shuffle_ps(v18, v18, 255);
            v20 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(v17, v7->Filter.m_Coefficients.vYPrev2),
                          _mm_mul_ps(v7->Filter.m_Coefficients.vYPrev1, v15)),
                        _mm_mul_ps(v7->Filter.m_Coefficients.vSecond, v14)),
                      _mm_add_ps(_mm_mul_ps(v7->Filter.m_Coefficients.vFirst, v18), v19)),
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v7->Filter.m_Coefficients.vFourth),
                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v7->Filter.m_Coefficients.vThird)));
            *((__m128 *)v9 - 1) = v20;
            v15 = _mm_shuffle_ps(v20, v20, 255);
            v17 = _mm_shuffle_ps(v20, v20, 170);
          }
          while ( v9 < v16 );
          v24 = v17.m128_f32[0];
          v22 = v14.m128_f32[0];
          v21 = v13.m128_f32[0];
          v23 = v15.m128_f32[0];
        }
        v7->Filter.m_Memories.m_Memories.fFFwd1 = v21;
        v7->Filter.m_Memories.m_Memories.fFFwd2 = v22;
        v7->Filter.m_Memories.m_Memories.fFFbk1 = v23;
        v7->Filter.m_Memories.m_Memories.fFFbk2 = v24;
        if ( (v8 & 3) != 0 )
          DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(&v7->Filter, v9, v12, 0);
      }
    }
  }
}

// File Line: 1075
// RVA: 0xAE2C10
void __fastcall CAkRoomVerbFX::ReverbPostProcess(
        CAkRoomVerbFX *this,
        float **out_ppfReverb,
        unsigned int in_uNumOutSignals,
        float in_fGain,
        unsigned int in_uNumFrames)
{
  __int64 v5; // rsi
  DSP::OnePoleZeroHPFilter *DCFilter; // rbx

  if ( in_uNumOutSignals )
  {
    v5 = in_uNumOutSignals;
    DCFilter = this->m_Reverb.DCFilter;
    do
    {
      DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(DCFilter++, *out_ppfReverb++, in_uNumFrames, in_fGain);
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 1106
// RVA: 0xAE2C80
__int64 __fastcall CAkRoomVerbFX::ProcessSpread1Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r14
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
  unsigned int uValidFrames; // ecx
  unsigned int in_uFrameOffset; // eax
  DSP::DelayLine *p_ERDelay; // rbx
  unsigned int in_uNumFrames; // ebp
  unsigned __int8 i; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *p_Filter; // rcx
  ReverbState *p_m_Reverb; // rbx
  __int64 v23; // rdi
  unsigned int j; // r14d
  __int64 v25; // rbx
  float **v26; // rbx
  DSP::OnePoleZeroHPFilter *DCFilter; // rdi
  __int64 v28; // r14
  float v29; // xmm6_4
  AkAudioBuffer *v30; // r14
  unsigned int v31; // ebx
  unsigned int uChannelMask; // edi
  float *v33; // rbx
  float *v34; // r14
  float *v35; // r14
  float in_fTargetGain2; // xmm1_4
  CAkRoomVerbFXParams *m_pParams; // rdx
  float in_fTargetGain3; // xmm1_4
  CAkRoomVerbFXParams *v39; // rdx
  bool v40; // zf
  float in_fCurrentGain2; // [rsp+28h] [rbp-100h]
  float *io_pfOutBuffer[2]; // [rsp+50h] [rbp-D8h] BYREF
  unsigned int v43; // [rsp+130h] [rbp+8h]
  unsigned int v45; // [rsp+140h] [rbp+18h]
  float *in_pfInput3; // [rsp+148h] [rbp+20h]

  v2 = io_pBuffer;
  v4 = (float *)this->m_pAllocator->vfptr->Malloc(
                  this->m_pAllocator,
                  (unsigned __int64)((unsigned int)(unsigned __int8)this->m_Reverb.uNumERSignals + 4) << 10);
  v5 = v4;
  if ( !v4 )
    return 52i64;
  v7 = v4 + 256;
  v8 = 0i64;
  io_pfOutBuffer[0] = v4 + 512;
  v9 = 0i64;
  in_pfInput3 = 0i64;
  io_pfOutBuffer[1] = v4 + 768;
  if ( this->m_Reverb.uNumERSignals )
  {
    v8 = v4 + 1280;
    v9 = v4 + 1024;
    in_pfInput3 = v4 + 1280;
  }
  v10 = 0.0;
  v11 = (float)((float)(this->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v12 = (__m128)(unsigned int)FLOAT_1_0;
  v12.m128_f32[0] = 1.0 - (float)(v11 * v11);
  if ( v12.m128_f32[0] <= 0.0 )
    v13 = 0.0;
  else
    LODWORD(v13) = _mm_sqrt_ps(v12).m128_u32[0];
  v15 = (__m128)(unsigned int)FLOAT_1_0;
  v14 = (float)((float)(this->m_pParams->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v15.m128_f32[0] = 1.0 - (float)(v14 * v14);
  if ( v15.m128_f32[0] > 0.0 )
    LODWORD(v10) = _mm_sqrt_ps(v15).m128_u32[0];
  uValidFrames = v2->uValidFrames;
  in_uFrameOffset = 0;
  v43 = 0;
  v45 = uValidFrames;
  if ( v2->uValidFrames )
  {
    p_ERDelay = &this->m_Reverb.ERDelay;
    do
    {
      in_uNumFrames = 256;
      if ( uValidFrames < 0x100 )
        in_uNumFrames = uValidFrames;
      CAkRoomVerbFX::WetPreProcess(this, v2, v5, in_uNumFrames, in_uFrameOffset);
      if ( this->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ReverbDelay, v5, v7, in_uNumFrames);
      else
        memmove(v7, v5, 4 * in_uNumFrames);
      if ( p_ERDelay->uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(p_ERDelay, v5, in_uNumFrames);
      if ( this->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(this->m_pERUnit, v5, v9, v8, in_uNumFrames);
        if ( this->m_pParams->sInvariantParams.bEnableToneControls )
        {
          for ( i = 0; i < (unsigned int)this->m_Reverb.uTCFilterIndex[0]; ++i )
          {
            p_Filter = &this->m_pTCFiltersState[i].Filter;
            if ( p_Filter[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
            {
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(p_Filter, v9, in_uNumFrames, 0);
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                &this->m_pTCFiltersState[++i].Filter,
                v8,
                in_uNumFrames,
                0);
            }
          }
        }
      }
      p_m_Reverb = &this->m_Reverb;
      v23 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(p_m_Reverb->DiffusionFilters, v7, in_uNumFrames);
        p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
        --v23;
      }
      while ( v23 );
      CAkRoomVerbFX::ReverbPreProcess(this, v7, in_uNumFrames);
      memset(v5 + 512, 0, 0x800ui64);
      for ( j = 0; j < this->m_Reverb.uNumReverbUnits; ++j )
      {
        v25 = j;
        DSP::DelayLine::ProcessBuffer(&this->m_pReverbUnitsState[v25].RUInputDelay, v7, in_uNumFrames);
        DSP::FDN4::ProcessBufferAccum(
          &this->m_pReverbUnitsState[v25].ReverbUnits,
          v7,
          io_pfOutBuffer[j & 1],
          in_uNumFrames);
      }
      v26 = io_pfOutBuffer;
      DCFilter = this->m_Reverb.DCFilter;
      v28 = 2i64;
      v29 = this->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(DCFilter++, *v26++, in_uNumFrames, v29);
        --v28;
      }
      while ( v28 );
      v30 = io_pBuffer;
      v31 = 0;
      uChannelMask = io_pBuffer->uChannelMask;
      if ( (uChannelMask & 1) != 0 )
      {
        v33 = (float *)((char *)io_pBuffer->pData + 4 * v43);
        DSP::Mix3Interp(
          v33,
          v5 + 512,
          v5 + 768,
          this->m_PrevRTPCParams.fDryLevel,
          this->m_pParams->sRTPCParams.fDryLevel,
          this->m_PrevRTPCParams.fReverbLevel * v11,
          this->m_pParams->sRTPCParams.fReverbLevel * v14,
          this->m_PrevRTPCParams.fReverbLevel * v13,
          this->m_pParams->sRTPCParams.fReverbLevel * v10,
          in_uNumFrames);
        if ( this->m_Reverb.uNumERSignals )
          DSP::Mix3Interp(
            v33,
            v9,
            in_pfInput3,
            1.0,
            1.0,
            this->m_PrevRTPCParams.fERLevel * v11,
            this->m_pParams->sRTPCParams.fERLevel * v14,
            this->m_PrevRTPCParams.fERLevel * v13,
            this->m_pParams->sRTPCParams.fERLevel * v10,
            in_uNumFrames);
        v31 = 1;
      }
      if ( (uChannelMask & 2) != 0 )
      {
        v34 = (float *)((char *)io_pBuffer->pData + 4 * v43 + 4 * v31 * (unsigned __int64)io_pBuffer->uMaxFrames);
        DSP::Mix3Interp(
          v34,
          v5 + 512,
          v5 + 768,
          this->m_PrevRTPCParams.fDryLevel,
          this->m_pParams->sRTPCParams.fDryLevel,
          this->m_PrevRTPCParams.fReverbLevel * v13,
          this->m_pParams->sRTPCParams.fReverbLevel * v10,
          this->m_PrevRTPCParams.fReverbLevel * v11,
          this->m_pParams->sRTPCParams.fReverbLevel * v14,
          in_uNumFrames);
        if ( this->m_Reverb.uNumERSignals )
          DSP::Mix3Interp(
            v34,
            v9,
            in_pfInput3,
            1.0,
            1.0,
            this->m_PrevRTPCParams.fERLevel * v13,
            this->m_pParams->sRTPCParams.fERLevel * v10,
            this->m_PrevRTPCParams.fERLevel * v11,
            this->m_pParams->sRTPCParams.fERLevel * v14,
            in_uNumFrames);
        v30 = io_pBuffer;
        ++v31;
      }
      if ( (uChannelMask & 4) != 0 )
      {
        v35 = (float *)((char *)v30->pData + 4 * v43 + 4 * v31 * (unsigned __int64)v30->uMaxFrames);
        DSP::Mix3Interp(
          v35,
          v5 + 512,
          v5 + 768,
          this->m_PrevRTPCParams.fDryLevel,
          this->m_pParams->sRTPCParams.fDryLevel,
          this->m_PrevRTPCParams.fReverbLevel * 0.70710599,
          this->m_pParams->sRTPCParams.fReverbLevel * 0.70710599,
          this->m_PrevRTPCParams.fReverbLevel * 0.70710599,
          this->m_pParams->sRTPCParams.fReverbLevel * 0.70710599,
          in_uNumFrames);
        if ( this->m_Reverb.uNumERSignals )
        {
          in_fTargetGain2 = this->m_pParams->sRTPCParams.fERLevel * 0.70710599;
          DSP::Mix3Interp(
            v35,
            v9,
            in_pfInput3,
            1.0,
            1.0,
            this->m_PrevRTPCParams.fERLevel * 0.70710599,
            in_fTargetGain2,
            this->m_PrevRTPCParams.fERLevel * 0.70710599,
            in_fTargetGain2,
            in_uNumFrames);
        }
        ++v31;
      }
      v2 = io_pBuffer;
      if ( (uChannelMask & 8) != 0 )
      {
        m_pParams = this->m_pParams;
        in_fTargetGain3 = (float)(m_pParams->sRTPCParams.fReverbLevel * m_pParams->sRTPCParams.fLFELevel) * 0.70710599;
        in_fCurrentGain2 = (float)(this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fLFELevel) * 0.70710599;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + v43 + v31 * (unsigned __int64)io_pBuffer->uMaxFrames,
          v5 + 512,
          v5 + 768,
          this->m_PrevRTPCParams.fDryLevel,
          m_pParams->sRTPCParams.fDryLevel,
          in_fCurrentGain2,
          in_fTargetGain3,
          in_fCurrentGain2,
          in_fTargetGain3,
          in_uNumFrames);
      }
      v39 = this->m_pParams;
      v8 = in_pfInput3;
      v11 = v14;
      v13 = v10;
      p_ERDelay = &this->m_Reverb.ERDelay;
      this->m_PrevRTPCParams.fDryLevel = v39->sRTPCParams.fDryLevel;
      this->m_PrevRTPCParams.fERLevel = v39->sRTPCParams.fERLevel;
      this->m_PrevRTPCParams.fReverbLevel = v39->sRTPCParams.fReverbLevel;
      in_uFrameOffset = in_uNumFrames + v43;
      this->m_PrevRTPCParams.fLFELevel = v39->sRTPCParams.fLFELevel;
      v43 += in_uNumFrames;
      v40 = v45 == in_uNumFrames;
      uValidFrames = v45 - in_uNumFrames;
      v45 -= in_uNumFrames;
    }
    while ( !v40 );
  }
  this->m_pAllocator->vfptr->Free(this->m_pAllocator, v5);
  return 1i64;
}

// File Line: 1322
// RVA: 0xAE34D0
__int64 __fastcall CAkRoomVerbFX::ProcessSpread2Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int uChannelMask; // eax
  AkAudioBuffer *v3; // r14
  int uNumERSignals; // edx
  int v6; // ebx
  CAkRoomVerbFXParams *m_pParams; // rax
  AK::IAkPluginMemAlloc *m_pAllocator; // rcx
  int v9; // ebp
  float *v10; // rax
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
  unsigned int uValidFrames; // ecx
  char v25; // dl
  DSP::DelayLine *p_ERDelay; // rbx
  unsigned int in_uNumFrames; // ebp
  unsigned __int8 i; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *p_Filter; // rcx
  ReverbState *p_m_Reverb; // rbx
  __int64 v31; // rdi
  unsigned int j; // r14d
  __int64 v33; // rbx
  float **v34; // rbx
  DSP::OnePoleZeroHPFilter *DCFilter; // rdi
  __int64 v36; // r14
  float v37; // xmm6_4
  unsigned int v38; // ebx
  float *v39; // rbx
  CAkRoomVerbFXParams *v40; // rax
  float v41; // xmm0_4
  float v42; // xmm3_4
  float *v43; // r14
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm0_4
  float *v47; // rdi
  CAkRoomVerbFXParams *v48; // rax
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  CAkRoomVerbFXParams *v52; // rdx
  unsigned int v53; // edi
  float in_fTargetGain2; // xmm1_4
  float v55; // xmm0_4
  float *v56; // rdi
  CAkRoomVerbFXParams *v57; // rax
  float v58; // xmm3_4
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm0_4
  float *v62; // rdi
  CAkRoomVerbFXParams *v63; // rax
  float v64; // xmm3_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  CAkRoomVerbFXParams *v67; // rdx
  float in_fTargetGain3; // xmm1_4
  CAkRoomVerbFXParams *v69; // rdx
  bool v70; // zf
  float in_fCurrentGain2; // [rsp+28h] [rbp-140h]
  float in_fCurrentGain2a; // [rsp+28h] [rbp-140h]
  float *v73; // [rsp+50h] [rbp-118h]
  float *in_pfInput3; // [rsp+58h] [rbp-110h]
  float *out_pfOutBuffer; // [rsp+60h] [rbp-108h]
  int v76; // [rsp+68h] [rbp-100h]
  int v77; // [rsp+6Ch] [rbp-FCh]
  int v78; // [rsp+70h] [rbp-F8h]
  int v79; // [rsp+74h] [rbp-F4h]
  int v80; // [rsp+78h] [rbp-F0h]
  int v81; // [rsp+7Ch] [rbp-ECh]
  float *io_pfOutBuffer2[4]; // [rsp+80h] [rbp-E8h] BYREF
  unsigned int v83; // [rsp+170h] [rbp+8h]
  char v85; // [rsp+180h] [rbp+18h]
  int v86; // [rsp+180h] [rbp+18h]
  unsigned int v87; // [rsp+188h] [rbp+20h]

  uChannelMask = io_pBuffer->uChannelMask;
  v3 = io_pBuffer;
  uNumERSignals = (unsigned __int8)this->m_Reverb.uNumERSignals;
  v85 = uChannelMask;
  v6 = uChannelMask & 0x30;
  m_pParams = this->m_pParams;
  m_pAllocator = this->m_pAllocator;
  v9 = 0;
  if ( m_pParams->sInvariantParams.bEnableEarlyReflections )
    v9 = v6 != 0 ? 2 : 0;
  v81 = v9;
  v10 = (float *)m_pAllocator->vfptr->Malloc(
                   m_pAllocator,
                   (unsigned __int64)(unsigned int)(v9 + uNumERSignals + 6) << 10);
  v11 = v10;
  if ( !v10 )
    return 52i64;
  v13 = v10 + 256;
  io_pfOutBuffer2[0] = v10 + 512;
  v14 = 0i64;
  io_pfOutBuffer2[1] = v10 + 768;
  v15 = 0i64;
  io_pfOutBuffer2[2] = v10 + 1024;
  in_pfInput3 = 0i64;
  out_pfOutBuffer = 0i64;
  v73 = 0i64;
  io_pfOutBuffer2[3] = v10 + 1280;
  if ( this->m_Reverb.uNumERSignals )
  {
    v15 = v10 + 1792;
    v14 = v10 + 1536;
    in_pfInput3 = v10 + 1792;
    if ( v9 == 2 )
    {
      out_pfOutBuffer = v10 + 2048;
      v73 = v10 + 2304;
    }
  }
  v16 = 0.0;
  v17 = (float)((float)(this->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v18 = (__m128)(unsigned int)FLOAT_1_0;
  v18.m128_f32[0] = 1.0 - (float)(v17 * v17);
  if ( v18.m128_f32[0] <= 0.0 )
    v19 = 0.0;
  else
    LODWORD(v19) = _mm_sqrt_ps(v18).m128_u32[0];
  v20 = this->m_pParams;
  v22 = (__m128)(unsigned int)FLOAT_1_0;
  v21 = (float)((float)(v20->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v22.m128_f32[0] = 1.0 - (float)(v21 * v21);
  if ( v22.m128_f32[0] > 0.0 )
    LODWORD(v16) = _mm_sqrt_ps(v22).m128_u32[0];
  if ( !v6 )
  {
    v20->sRTPCParams.fFrontLevel = 1.0;
    this->m_pParams->sRTPCParams.fRearLevel = 1.0;
  }
  in_uFrameOffset = 0;
  v83 = 0;
  uValidFrames = v3->uValidFrames;
  v87 = uValidFrames;
  if ( v3->uValidFrames )
  {
    v25 = v85;
    p_ERDelay = &this->m_Reverb.ERDelay;
    v77 = v85 & 1;
    v78 = v85 & 2;
    v80 = v85 & 4;
    v76 = v85 & 0x10;
    v86 = v85 & 8;
    v79 = v25 & 0x20;
    do
    {
      in_uNumFrames = 256;
      if ( uValidFrames < 0x100 )
        in_uNumFrames = uValidFrames;
      CAkRoomVerbFX::WetPreProcess(this, v3, v11, in_uNumFrames, in_uFrameOffset);
      if ( this->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ReverbDelay, v11, v13, in_uNumFrames);
      else
        memmove(v13, v11, 4 * in_uNumFrames);
      if ( p_ERDelay->uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(p_ERDelay, v11, in_uNumFrames);
      if ( this->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(this->m_pERUnit, v11, v14, v15, in_uNumFrames);
        if ( this->m_pParams->sInvariantParams.bEnableToneControls )
        {
          for ( i = 0; i < (unsigned int)this->m_Reverb.uTCFilterIndex[0]; ++i )
          {
            p_Filter = &this->m_pTCFiltersState[i].Filter;
            if ( p_Filter[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
            {
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(p_Filter, v14, in_uNumFrames, 0);
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                &this->m_pTCFiltersState[++i].Filter,
                v15,
                in_uNumFrames,
                0);
            }
          }
        }
        if ( v81 == 2 )
        {
          if ( this->m_Reverb.ERFrontBackDelay[0].uDelayLineLength )
          {
            DSP::DelayLine::ProcessBuffer(this->m_Reverb.ERFrontBackDelay, v14, out_pfOutBuffer, in_uNumFrames);
            DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ERFrontBackDelay[1], v15, v73, in_uNumFrames);
          }
          else
          {
            out_pfOutBuffer = v14;
            v73 = v15;
          }
        }
      }
      p_m_Reverb = &this->m_Reverb;
      v31 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(p_m_Reverb->DiffusionFilters, v13, in_uNumFrames);
        p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
        --v31;
      }
      while ( v31 );
      CAkRoomVerbFX::ReverbPreProcess(this, v13, in_uNumFrames);
      memset(v11 + 512, 0, 0x1000ui64);
      for ( j = 0; j < this->m_Reverb.uNumReverbUnits; ++j )
      {
        v33 = j;
        DSP::DelayLine::ProcessBuffer(&this->m_pReverbUnitsState[v33].RUInputDelay, v13, in_uNumFrames);
        DSP::FDN4::ProcessBufferAccum(
          &this->m_pReverbUnitsState[v33].ReverbUnits,
          v13,
          io_pfOutBuffer2[j & 1],
          io_pfOutBuffer2[(j & 1) + 2],
          in_uNumFrames);
      }
      v34 = io_pfOutBuffer2;
      DCFilter = this->m_Reverb.DCFilter;
      v36 = 4i64;
      v37 = this->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(DCFilter++, *v34++, in_uNumFrames, v37);
        --v36;
      }
      while ( v36 );
      v38 = 0;
      if ( v77 )
      {
        v39 = (float *)((char *)io_pBuffer->pData + 4 * v83);
        v40 = this->m_pParams;
        v41 = this->m_PrevRTPCParams.fFrontLevel * this->m_PrevRTPCParams.fReverbLevel;
        v42 = v40->sRTPCParams.fReverbLevel * v40->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(
          v39,
          v11 + 512,
          v11 + 768,
          this->m_PrevRTPCParams.fDryLevel,
          v40->sRTPCParams.fDryLevel,
          v41 * v17,
          v42 * v21,
          v41 * v19,
          v42 * v16,
          in_uNumFrames);
        v43 = in_pfInput3;
        if ( this->m_Reverb.uNumERSignals )
        {
          v44 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fFrontLevel;
          v45 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fFrontLevel;
          DSP::Mix3Interp(v39, v14, in_pfInput3, 1.0, 1.0, v44 * v17, v45 * v21, v44 * v19, v45 * v16, in_uNumFrames);
        }
        v38 = 1;
      }
      else
      {
        v43 = in_pfInput3;
      }
      if ( v78 )
      {
        v46 = this->m_PrevRTPCParams.fFrontLevel * this->m_PrevRTPCParams.fReverbLevel;
        v47 = (float *)((char *)io_pBuffer->pData + 4 * v83 + 4 * v38 * (unsigned __int64)io_pBuffer->uMaxFrames);
        v48 = this->m_pParams;
        v49 = v48->sRTPCParams.fReverbLevel * v48->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(
          v47,
          v11 + 512,
          v11 + 768,
          this->m_PrevRTPCParams.fDryLevel,
          v48->sRTPCParams.fDryLevel,
          v46 * v19,
          v49 * v16,
          v46 * v17,
          v49 * v21,
          in_uNumFrames);
        if ( this->m_Reverb.uNumERSignals )
        {
          v50 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fFrontLevel;
          v51 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fFrontLevel;
          DSP::Mix3Interp(v47, v14, v43, 1.0, 1.0, v50 * v19, v51 * v16, v50 * v17, v51 * v21, in_uNumFrames);
        }
        ++v38;
      }
      v3 = io_pBuffer;
      if ( v80 )
      {
        v52 = this->m_pParams;
        v53 = v83;
        in_fTargetGain2 = (float)(v52->sRTPCParams.fReverbLevel * v52->sRTPCParams.fCenterLevel) * 0.70710599;
        in_fCurrentGain2 = (float)(this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fCenterLevel)
                         * 0.70710599;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + v83 + v38++ * (unsigned __int64)io_pBuffer->uMaxFrames,
          v11 + 1024,
          v11 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v52->sRTPCParams.fDryLevel,
          in_fCurrentGain2,
          in_fTargetGain2,
          in_fCurrentGain2,
          in_fTargetGain2,
          in_uNumFrames);
      }
      else
      {
        v53 = v83;
      }
      if ( v76 )
      {
        v55 = this->m_PrevRTPCParams.fRearLevel * this->m_PrevRTPCParams.fReverbLevel;
        v56 = (float *)((char *)io_pBuffer->pData + 4 * v53 + 4 * v38 * (unsigned __int64)io_pBuffer->uMaxFrames);
        v57 = this->m_pParams;
        v58 = v57->sRTPCParams.fReverbLevel * v57->sRTPCParams.fRearLevel;
        DSP::Mix3Interp(
          v56,
          v11 + 1024,
          v11 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v57->sRTPCParams.fDryLevel,
          v55 * v17,
          v58 * v21,
          v55 * v19,
          v58 * v16,
          in_uNumFrames);
        if ( this->m_Reverb.uNumERSignals )
        {
          v59 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fRearLevel;
          v60 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fRearLevel;
          DSP::Mix3Interp(
            v56,
            out_pfOutBuffer,
            v73,
            1.0,
            1.0,
            v59 * v17,
            v60 * v21,
            v59 * v19,
            v60 * v16,
            in_uNumFrames);
        }
        ++v38;
      }
      if ( v79 )
      {
        v61 = this->m_PrevRTPCParams.fRearLevel * this->m_PrevRTPCParams.fReverbLevel;
        v62 = (float *)((char *)io_pBuffer->pData + 4 * v83 + 4 * v38 * (unsigned __int64)io_pBuffer->uMaxFrames);
        v63 = this->m_pParams;
        v64 = v63->sRTPCParams.fReverbLevel * v63->sRTPCParams.fRearLevel;
        DSP::Mix3Interp(
          v62,
          v11 + 1024,
          v11 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v63->sRTPCParams.fDryLevel,
          v61 * v19,
          v64 * v16,
          v61 * v17,
          v64 * v21,
          in_uNumFrames);
        if ( this->m_Reverb.uNumERSignals )
        {
          v65 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fRearLevel;
          v66 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fRearLevel;
          DSP::Mix3Interp(
            v62,
            out_pfOutBuffer,
            v73,
            1.0,
            1.0,
            v65 * v19,
            v66 * v16,
            v65 * v17,
            v66 * v21,
            in_uNumFrames);
        }
        ++v38;
      }
      if ( v86 )
      {
        v67 = this->m_pParams;
        in_fTargetGain3 = (float)(v67->sRTPCParams.fReverbLevel * v67->sRTPCParams.fLFELevel) * 0.70710599;
        in_fCurrentGain2a = (float)(this->m_PrevRTPCParams.fLFELevel * this->m_PrevRTPCParams.fReverbLevel) * 0.70710599;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + v83 + v38 * (unsigned __int64)io_pBuffer->uMaxFrames,
          v11 + 1024,
          v11 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v67->sRTPCParams.fDryLevel,
          in_fCurrentGain2a,
          in_fTargetGain3,
          in_fCurrentGain2a,
          in_fTargetGain3,
          in_uNumFrames);
      }
      v69 = this->m_pParams;
      v15 = in_pfInput3;
      v17 = v21;
      v19 = v16;
      p_ERDelay = &this->m_Reverb.ERDelay;
      this->m_PrevRTPCParams.fDryLevel = v69->sRTPCParams.fDryLevel;
      this->m_PrevRTPCParams.fERLevel = v69->sRTPCParams.fERLevel;
      this->m_PrevRTPCParams.fReverbLevel = v69->sRTPCParams.fReverbLevel;
      this->m_PrevRTPCParams.fFrontLevel = v69->sRTPCParams.fFrontLevel;
      this->m_PrevRTPCParams.fCenterLevel = v69->sRTPCParams.fCenterLevel;
      this->m_PrevRTPCParams.fRearLevel = v69->sRTPCParams.fRearLevel;
      in_uFrameOffset = in_uNumFrames + v83;
      this->m_PrevRTPCParams.fLFELevel = v69->sRTPCParams.fLFELevel;
      v83 += in_uNumFrames;
      v70 = v87 == in_uNumFrames;
      uValidFrames = v87 - in_uNumFrames;
      v87 -= in_uNumFrames;
    }
    while ( !v70 );
  }
  this->m_pAllocator->vfptr->Free(this->m_pAllocator, v11);
  return 1i64;
}

// File Line: 1613
// RVA: 0xAE40A0
__int64 __fastcall CAkRoomVerbFX::ProcessSpread3Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int uChannelMask; // ebp
  AkAudioBuffer *v3; // rbx
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
  unsigned int uValidFrames; // eax
  unsigned int in_uFrameOffset; // ecx
  unsigned int v20; // ebp
  unsigned __int8 i; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *p_Filter; // rcx
  ReverbState *p_m_Reverb; // rbx
  __int64 v24; // rdi
  unsigned int j; // r14d
  __int64 v26; // rbx
  float **v27; // rbx
  DSP::OnePoleZeroHPFilter *DCFilter; // rdi
  __int64 v29; // r14
  float v30; // xmm6_4
  float v31; // xmm0_4
  float *v32; // rbx
  CAkRoomVerbFXParams *m_pParams; // rax
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float *v38; // rbx
  CAkRoomVerbFXParams *v39; // rax
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  unsigned int v43; // ebx
  CAkRoomVerbFXParams *v44; // rdx
  float v45; // xmm0_4
  float *v46; // rdi
  CAkRoomVerbFXParams *v47; // rax
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  unsigned int v51; // ebx
  float v52; // xmm0_4
  float *v53; // rdi
  CAkRoomVerbFXParams *v54; // rax
  float v55; // xmm3_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  CAkRoomVerbFXParams *v58; // rdx
  __int64 v59; // rcx
  float in_fTargetGain3; // xmm1_4
  CAkRoomVerbFXParams *v61; // rcx
  bool v62; // zf
  float in_uNumFrames; // [rsp+28h] [rbp-140h]
  float in_uNumFramesa; // [rsp+28h] [rbp-140h]
  float in_fTargetGain2; // [rsp+30h] [rbp-138h]
  int v66; // [rsp+50h] [rbp-118h]
  float *out_pfOutBuffer; // [rsp+58h] [rbp-110h]
  float *in_pfInput2; // [rsp+60h] [rbp-108h]
  float *in_pfInput3; // [rsp+68h] [rbp-100h]
  float *io_pfOutBuffer3[6]; // [rsp+70h] [rbp-F8h] BYREF
  unsigned int v71; // [rsp+170h] [rbp+8h]
  unsigned int v73; // [rsp+180h] [rbp+18h]
  int v74; // [rsp+188h] [rbp+20h]

  uChannelMask = io_pBuffer->uChannelMask;
  v3 = io_pBuffer;
  v5 = (float *)this->m_pAllocator->vfptr->Malloc(
                  this->m_pAllocator,
                  (unsigned __int64)(2 * (unsigned int)(unsigned __int8)this->m_Reverb.uNumERSignals + 8) << 10);
  v6 = v5;
  if ( !v5 )
    return 52i64;
  v8 = v5 + 256;
  io_pfOutBuffer3[0] = v5 + 512;
  v9 = 0i64;
  io_pfOutBuffer3[1] = v5 + 768;
  v10 = 0i64;
  io_pfOutBuffer3[2] = v5 + 1024;
  v11 = 0i64;
  io_pfOutBuffer3[3] = v5 + 1280;
  in_pfInput3 = 0i64;
  io_pfOutBuffer3[4] = v5 + 1536;
  in_pfInput2 = 0i64;
  out_pfOutBuffer = 0i64;
  io_pfOutBuffer3[5] = v5 + 1792;
  if ( this->m_Reverb.uNumERSignals )
  {
    v9 = v5 + 2304;
    v10 = v5 + 2560;
    in_pfInput3 = v5 + 2304;
    in_pfInput2 = v5 + 2560;
    out_pfOutBuffer = v5 + 2816;
    v11 = v5 + 2048;
  }
  v12 = 0.0;
  v13 = (float)((float)(this->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v14 = (__m128)(unsigned int)FLOAT_1_0;
  v14.m128_f32[0] = 1.0 - (float)(v13 * v13);
  if ( v14.m128_f32[0] <= 0.0 )
    v15 = 0.0;
  else
    LODWORD(v15) = _mm_sqrt_ps(v14).m128_u32[0];
  v17 = (__m128)(unsigned int)FLOAT_1_0;
  v16 = (float)((float)(this->m_pParams->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v17.m128_f32[0] = 1.0 - (float)(v16 * v16);
  if ( v17.m128_f32[0] > 0.0 )
    LODWORD(v12) = _mm_sqrt_ps(v17).m128_u32[0];
  uValidFrames = v3->uValidFrames;
  in_uFrameOffset = 0;
  v71 = 0;
  v73 = uValidFrames;
  if ( v3->uValidFrames )
  {
    v66 = uChannelMask & 8;
    v74 = uChannelMask & 4;
    do
    {
      v20 = 256;
      if ( uValidFrames < 0x100 )
        v20 = uValidFrames;
      CAkRoomVerbFX::WetPreProcess(this, v3, v6, v20, in_uFrameOffset);
      if ( this->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ReverbDelay, v6, v8, v20);
      else
        memmove(v8, v6, 4 * v20);
      if ( this->m_Reverb.ERDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ERDelay, v6, v20);
      if ( this->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(this->m_pERUnit, v6, v11, v9, v20);
        if ( this->m_pParams->sInvariantParams.bEnableToneControls )
        {
          for ( i = 0; i < (unsigned int)this->m_Reverb.uTCFilterIndex[0]; ++i )
          {
            p_Filter = &this->m_pTCFiltersState[i].Filter;
            if ( p_Filter[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
            {
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(p_Filter, v11, v20, 0);
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                &this->m_pTCFiltersState[++i].Filter,
                v9,
                v20,
                0);
            }
          }
        }
        if ( this->m_Reverb.ERFrontBackDelay[0].uDelayLineLength )
        {
          DSP::DelayLine::ProcessBuffer(this->m_Reverb.ERFrontBackDelay, v11, v10, v20);
          DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ERFrontBackDelay[1], v9, out_pfOutBuffer, v20);
        }
        else
        {
          in_pfInput2 = v11;
          out_pfOutBuffer = v9;
        }
      }
      p_m_Reverb = &this->m_Reverb;
      v24 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(p_m_Reverb->DiffusionFilters, v8, v20);
        p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
        --v24;
      }
      while ( v24 );
      CAkRoomVerbFX::ReverbPreProcess(this, v8, v20);
      memset(v6 + 512, 0, 0x1800ui64);
      for ( j = 0; j < this->m_Reverb.uNumReverbUnits; ++j )
      {
        v26 = j;
        DSP::DelayLine::ProcessBuffer(&this->m_pReverbUnitsState[v26].RUInputDelay, v8, v20);
        DSP::FDN4::ProcessBufferAccum(
          &this->m_pReverbUnitsState[v26].ReverbUnits,
          v8,
          io_pfOutBuffer3[j & 1],
          io_pfOutBuffer3[(j & 1) + 2],
          io_pfOutBuffer3[(j & 1) + 4],
          v20);
      }
      v27 = io_pfOutBuffer3;
      DCFilter = this->m_Reverb.DCFilter;
      v29 = 6i64;
      v30 = this->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(DCFilter++, *v27++, v20, v30);
        --v29;
      }
      while ( v29 );
      v31 = this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fFrontLevel;
      v32 = (float *)((char *)io_pBuffer->pData + 4 * v71);
      m_pParams = this->m_pParams;
      v34 = m_pParams->sRTPCParams.fReverbLevel * m_pParams->sRTPCParams.fFrontLevel;
      DSP::Mix3Interp(
        v32,
        v6 + 512,
        v6 + 768,
        this->m_PrevRTPCParams.fDryLevel,
        m_pParams->sRTPCParams.fDryLevel,
        v31 * v13,
        v34 * v16,
        v31 * v15,
        v34 * v12,
        v20);
      if ( this->m_Reverb.uNumERSignals )
      {
        v35 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fFrontLevel;
        v36 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v32, v11, in_pfInput3, 1.0, 1.0, v35 * v13, v36 * v16, v35 * v15, v36 * v12, v20);
      }
      v37 = this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fFrontLevel;
      v38 = (float *)((char *)io_pBuffer->pData + 4 * v71 + 4 * (unsigned __int64)io_pBuffer->uMaxFrames);
      v39 = this->m_pParams;
      v40 = v39->sRTPCParams.fReverbLevel * v39->sRTPCParams.fFrontLevel;
      DSP::Mix3Interp(
        v38,
        v6 + 512,
        v6 + 768,
        this->m_PrevRTPCParams.fDryLevel,
        v39->sRTPCParams.fDryLevel,
        v37 * v15,
        v40 * v12,
        v37 * v13,
        v40 * v16,
        v20);
      if ( this->m_Reverb.uNumERSignals )
      {
        v41 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fFrontLevel;
        v42 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v38, v11, in_pfInput3, 1.0, 1.0, v41 * v15, v42 * v12, v41 * v13, v42 * v16, v20);
      }
      v43 = 2;
      if ( v74 )
      {
        v44 = this->m_pParams;
        in_fTargetGain2 = (float)(v44->sRTPCParams.fReverbLevel * v44->sRTPCParams.fCenterLevel) * 0.70710599;
        in_uNumFrames = (float)(this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fCenterLevel) * 0.70710599;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + 2 * io_pBuffer->uMaxFrames + v71,
          v6 + 1024,
          v6 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v44->sRTPCParams.fDryLevel,
          in_uNumFrames,
          in_fTargetGain2,
          in_uNumFrames,
          in_fTargetGain2,
          v20);
        v43 = 3;
      }
      v45 = this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fRearLevel;
      v46 = (float *)((char *)io_pBuffer->pData + 4 * v71 + 4 * v43 * (unsigned __int64)io_pBuffer->uMaxFrames);
      v47 = this->m_pParams;
      v48 = v47->sRTPCParams.fReverbLevel * v47->sRTPCParams.fRearLevel;
      DSP::Mix3Interp(
        v46,
        v6 + 1536,
        v6 + 1792,
        this->m_PrevRTPCParams.fDryLevel,
        v47->sRTPCParams.fDryLevel,
        v45 * v13,
        v48 * v16,
        v45 * v15,
        v48 * v12,
        v20);
      if ( this->m_Reverb.uNumERSignals )
      {
        v49 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fRearLevel;
        v50 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fRearLevel;
        DSP::Mix3Interp(v46, in_pfInput2, out_pfOutBuffer, 1.0, 1.0, v49 * v13, v50 * v16, v49 * v15, v50 * v12, v20);
      }
      v51 = v43 + 1;
      v52 = this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fRearLevel;
      v53 = (float *)((char *)io_pBuffer->pData + 4 * v71 + 4 * v51 * (unsigned __int64)io_pBuffer->uMaxFrames);
      v54 = this->m_pParams;
      v55 = v54->sRTPCParams.fReverbLevel * v54->sRTPCParams.fRearLevel;
      DSP::Mix3Interp(
        v53,
        v6 + 1536,
        v6 + 1792,
        this->m_PrevRTPCParams.fDryLevel,
        v54->sRTPCParams.fDryLevel,
        v52 * v15,
        v55 * v12,
        v52 * v13,
        v55 * v16,
        v20);
      if ( this->m_Reverb.uNumERSignals )
      {
        v56 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fRearLevel;
        v57 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fRearLevel;
        DSP::Mix3Interp(v53, in_pfInput2, out_pfOutBuffer, 1.0, 1.0, v56 * v15, v57 * v12, v56 * v13, v57 * v16, v20);
      }
      if ( v66 )
      {
        v58 = this->m_pParams;
        v59 = v51 + 1;
        v3 = io_pBuffer;
        in_fTargetGain3 = (float)(v58->sRTPCParams.fReverbLevel * v58->sRTPCParams.fLFELevel) * 0.70710599;
        in_uNumFramesa = (float)(this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fLFELevel) * 0.70710599;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + v71 + io_pBuffer->uMaxFrames * v59,
          v6 + 1024,
          v6 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v58->sRTPCParams.fDryLevel,
          in_uNumFramesa,
          in_fTargetGain3,
          in_uNumFramesa,
          in_fTargetGain3,
          v20);
      }
      else
      {
        v3 = io_pBuffer;
      }
      v61 = this->m_pParams;
      v9 = in_pfInput3;
      v10 = in_pfInput2;
      v13 = v16;
      v15 = v12;
      this->m_PrevRTPCParams.fDryLevel = v61->sRTPCParams.fDryLevel;
      this->m_PrevRTPCParams.fERLevel = v61->sRTPCParams.fERLevel;
      this->m_PrevRTPCParams.fReverbLevel = v61->sRTPCParams.fReverbLevel;
      this->m_PrevRTPCParams.fFrontLevel = v61->sRTPCParams.fFrontLevel;
      this->m_PrevRTPCParams.fCenterLevel = v61->sRTPCParams.fCenterLevel;
      this->m_PrevRTPCParams.fRearLevel = v61->sRTPCParams.fRearLevel;
      this->m_PrevRTPCParams.fLFELevel = v61->sRTPCParams.fLFELevel;
      in_uFrameOffset = v20 + v71;
      v62 = v73 == v20;
      uValidFrames = v73 - v20;
      v71 += v20;
      v73 -= v20;
    }
    while ( !v62 );
  }
  this->m_pAllocator->vfptr->Free(this->m_pAllocator, v6);
  return 1i64;
}vel = v61->sRTPCParams.fRe

// File Line: 1893
// RVA: 0xAE4BB0
__int64 __fastcall CAkRoomVerbFX::ProcessSpread4Out(CAkRoomVerbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int uChannelMask; // ebp
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
  unsigned int uValidFrames; // eax
  DSP::DelayLine *p_ERDelay; // rbx
  unsigned int v21; // ebp
  unsigned __int8 i; // bl
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *p_Filter; // rcx
  ReverbState *p_m_Reverb; // rbx
  __int64 v25; // rdi
  unsigned int j; // r14d
  __int64 v27; // rbx
  float **v28; // rbx
  DSP::OnePoleZeroHPFilter *DCFilter; // rdi
  __int64 v30; // r14
  float v31; // xmm6_4
  float *v32; // rbx
  CAkRoomVerbFXParams *m_pParams; // rax
  float v34; // xmm0_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float *v39; // rbx
  CAkRoomVerbFXParams *v40; // rax
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  unsigned int v44; // ebx
  CAkRoomVerbFXParams *v45; // rdx
  float in_fTargetGain2; // xmm1_4
  CAkRoomVerbFXParams *v47; // rdx
  float fRearLevel; // xmm10_4
  float v49; // xmm6_4
  float v50; // xmm12_4
  float *v51; // r14
  float v52; // xmm13_4
  float in_fTargetGain3; // xmm11_4
  float in_fCurrentGain3; // xmm10_4
  float v55; // xmm12_4
  float v56; // xmm8_4
  float v57; // xmm6_4
  float v58; // xmm8_4
  float v59; // xmm13_4
  float v60; // xmm9_4
  float v61; // xmm7_4
  float v62; // xmm9_4
  unsigned int v63; // ebx
  float *v64; // r14
  unsigned int v65; // ebx
  float *v66; // r14
  unsigned int v67; // ebx
  float *v68; // r14
  CAkRoomVerbFXParams *v69; // rdx
  float v70; // xmm1_4
  CAkRoomVerbFXParams *v71; // rcx
  bool v72; // zf
  float in_uNumFrames; // [rsp+28h] [rbp-170h]
  float in_uNumFramesa; // [rsp+28h] [rbp-170h]
  float *out_pfOutBuffer; // [rsp+50h] [rbp-148h]
  float *v76; // [rsp+58h] [rbp-140h]
  float *in_pfInput3; // [rsp+60h] [rbp-138h]
  float *in_pfInput2; // [rsp+68h] [rbp-130h]
  int v79; // [rsp+70h] [rbp-128h]
  int v80; // [rsp+74h] [rbp-124h]
  float *io_pfOutBuffer3[7]; // [rsp+78h] [rbp-120h] BYREF
  float v82; // [rsp+1A0h] [rbp+8h]
  float v83; // [rsp+1A8h] [rbp+10h]
  unsigned int v84; // [rsp+1B0h] [rbp+18h]
  unsigned int v85; // [rsp+1B8h] [rbp+20h]

  uChannelMask = io_pBuffer->uChannelMask;
  v5 = (float *)this->m_pAllocator->vfptr->Malloc(
                  this->m_pAllocator,
                  (unsigned __int64)(2 * (unsigned int)(unsigned __int8)this->m_Reverb.uNumERSignals + 8) << 10);
  v6 = v5;
  if ( !v5 )
    return 52i64;
  in_uFrameOffset = 0;
  v9 = v5 + 256;
  io_pfOutBuffer3[0] = v5 + 512;
  v10 = 0i64;
  io_pfOutBuffer3[1] = v5 + 768;
  in_pfInput2 = 0i64;
  io_pfOutBuffer3[2] = v5 + 1024;
  v11 = 0i64;
  io_pfOutBuffer3[3] = v5 + 1280;
  in_pfInput3 = 0i64;
  io_pfOutBuffer3[4] = v5 + 1536;
  out_pfOutBuffer = 0i64;
  v76 = 0i64;
  io_pfOutBuffer3[5] = v5 + 1792;
  if ( this->m_Reverb.uNumERSignals )
  {
    v10 = v5 + 2048;
    v11 = v5 + 2304;
    out_pfOutBuffer = v5 + 2560;
    in_pfInput2 = v5 + 2048;
    v76 = v5 + 2816;
    in_pfInput3 = v5 + 2304;
  }
  v12 = 0.0;
  v13 = FLOAT_0_70710599;
  v82 = 0.0;
  v15 = (__m128)(unsigned int)FLOAT_1_0;
  v14 = (float)((float)(this->m_PrevRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v15.m128_f32[0] = 1.0 - (float)(v14 * v14);
  if ( v15.m128_f32[0] <= 0.0 )
    v16 = 0.0;
  else
    LODWORD(v16) = _mm_sqrt_ps(v15).m128_u32[0];
  v18 = (__m128)(unsigned int)FLOAT_1_0;
  v83 = v16;
  v17 = (float)((float)(this->m_pParams->sRTPCParams.fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v18.m128_f32[0] = 1.0 - (float)(v17 * v17);
  if ( v18.m128_f32[0] > 0.0 )
  {
    LODWORD(v12) = _mm_sqrt_ps(v18).m128_u32[0];
    v82 = v12;
  }
  uValidFrames = io_pBuffer->uValidFrames;
  v84 = 0;
  v85 = uValidFrames;
  if ( io_pBuffer->uValidFrames )
  {
    v80 = uChannelMask & 8;
    p_ERDelay = &this->m_Reverb.ERDelay;
    v79 = uChannelMask & 4;
    do
    {
      v21 = 256;
      if ( uValidFrames < 0x100 )
        v21 = uValidFrames;
      CAkRoomVerbFX::WetPreProcess(this, io_pBuffer, v6, v21, in_uFrameOffset);
      if ( this->m_Reverb.ReverbDelay.uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ReverbDelay, v6, v9, v21);
      else
        memmove(v9, v6, 4 * v21);
      if ( p_ERDelay->uDelayLineLength )
        DSP::DelayLine::ProcessBuffer(p_ERDelay, v6, v21);
      if ( this->m_Reverb.uNumERSignals )
      {
        DSP::ERUnitDual::ProcessBuffer(this->m_pERUnit, v6, v10, v11, v21);
        if ( this->m_pParams->sInvariantParams.bEnableToneControls )
        {
          for ( i = 0; i < (unsigned int)this->m_Reverb.uTCFilterIndex[0]; ++i )
          {
            p_Filter = &this->m_pTCFiltersState[i].Filter;
            if ( p_Filter[1].m_Coefficients.vFirst.m128_i32[0] == 1 )
            {
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(p_Filter, v10, v21, 0);
              DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
                &this->m_pTCFiltersState[++i].Filter,
                v11,
                v21,
                0);
            }
          }
        }
        if ( this->m_Reverb.ERFrontBackDelay[0].uDelayLineLength )
        {
          DSP::DelayLine::ProcessBuffer(this->m_Reverb.ERFrontBackDelay, v10, out_pfOutBuffer, v21);
          DSP::DelayLine::ProcessBuffer(&this->m_Reverb.ERFrontBackDelay[1], v11, v76, v21);
        }
        else
        {
          out_pfOutBuffer = v10;
          v76 = v11;
        }
      }
      p_m_Reverb = &this->m_Reverb;
      v25 = 4i64;
      do
      {
        DSP::AllpassFilter::ProcessBuffer(p_m_Reverb->DiffusionFilters, v9, v21);
        p_m_Reverb = (ReverbState *)((char *)p_m_Reverb + 24);
        --v25;
      }
      while ( v25 );
      CAkRoomVerbFX::ReverbPreProcess(this, v9, v21);
      memset(v6 + 512, 0, 0x1800ui64);
      for ( j = 0; j < this->m_Reverb.uNumReverbUnits; ++j )
      {
        v27 = j;
        DSP::DelayLine::ProcessBuffer(&this->m_pReverbUnitsState[v27].RUInputDelay, v9, v21);
        DSP::FDN4::ProcessBufferAccum(
          &this->m_pReverbUnitsState[v27].ReverbUnits,
          v9,
          io_pfOutBuffer3[j & 1],
          io_pfOutBuffer3[(j & 1) + 2],
          io_pfOutBuffer3[(j & 1) + 4],
          v21);
      }
      v28 = io_pfOutBuffer3;
      DCFilter = this->m_Reverb.DCFilter;
      v30 = 6i64;
      v31 = this->m_Reverb.fReverbUnitsMixGain * 1.4142135;
      do
      {
        DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(DCFilter++, *v28++, v21, v31);
        --v30;
      }
      while ( v30 );
      v32 = (float *)((char *)io_pBuffer->pData + 4 * v84);
      m_pParams = this->m_pParams;
      v34 = this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fFrontLevel;
      v35 = m_pParams->sRTPCParams.fReverbLevel * m_pParams->sRTPCParams.fFrontLevel;
      DSP::Mix3Interp(
        v32,
        v6 + 512,
        v6 + 768,
        this->m_PrevRTPCParams.fDryLevel,
        m_pParams->sRTPCParams.fDryLevel,
        v34 * v14,
        v35 * v17,
        v34 * v16,
        v35 * v12,
        v21);
      if ( this->m_Reverb.uNumERSignals )
      {
        v36 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fFrontLevel;
        v37 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v32, in_pfInput2, in_pfInput3, 1.0, 1.0, v36 * v14, v37 * v17, v36 * v16, v37 * v12, v21);
      }
      v38 = this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fFrontLevel;
      v39 = (float *)((char *)io_pBuffer->pData + 4 * v84 + 4 * (unsigned __int64)io_pBuffer->uMaxFrames);
      v40 = this->m_pParams;
      v41 = v40->sRTPCParams.fReverbLevel * v40->sRTPCParams.fFrontLevel;
      DSP::Mix3Interp(
        v39,
        v6 + 512,
        v6 + 768,
        this->m_PrevRTPCParams.fDryLevel,
        v40->sRTPCParams.fDryLevel,
        v38 * v16,
        v41 * v12,
        v38 * v14,
        v41 * v17,
        v21);
      if ( this->m_Reverb.uNumERSignals )
      {
        v42 = this->m_PrevRTPCParams.fERLevel * this->m_PrevRTPCParams.fFrontLevel;
        v43 = this->m_pParams->sRTPCParams.fERLevel * this->m_pParams->sRTPCParams.fFrontLevel;
        DSP::Mix3Interp(v39, in_pfInput2, in_pfInput3, 1.0, 1.0, v42 * v16, v43 * v12, v42 * v14, v43 * v17, v21);
      }
      v44 = 2;
      if ( v79 )
      {
        v45 = this->m_pParams;
        in_fTargetGain2 = (float)(v45->sRTPCParams.fReverbLevel * v45->sRTPCParams.fCenterLevel) * v13;
        in_uNumFrames = (float)(this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fCenterLevel) * v13;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + 2 * io_pBuffer->uMaxFrames + v84,
          v6 + 1024,
          v6 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v45->sRTPCParams.fDryLevel,
          in_uNumFrames,
          in_fTargetGain2,
          in_uNumFrames,
          in_fTargetGain2,
          v21);
        v44 = 3;
      }
      v47 = this->m_pParams;
      fRearLevel = this->m_PrevRTPCParams.fRearLevel;
      v49 = fRearLevel * this->m_PrevRTPCParams.fERLevel;
      v50 = fRearLevel * this->m_PrevRTPCParams.fReverbLevel;
      v51 = (float *)((char *)io_pBuffer->pData + 4 * v84 + 4 * v44 * (unsigned __int64)io_pBuffer->uMaxFrames);
      v52 = v47->sRTPCParams.fRearLevel * v47->sRTPCParams.fReverbLevel;
      in_fTargetGain3 = v52 * v82;
      in_fCurrentGain3 = v50 * v16;
      v55 = v50 * v14;
      v56 = v49;
      v57 = v49 * v83;
      v58 = v56 * v14;
      v59 = v52 * v17;
      v60 = v47->sRTPCParams.fRearLevel * v47->sRTPCParams.fERLevel;
      v61 = v60 * v82;
      v62 = v60 * v17;
      DSP::Mix3Interp(
        v51,
        v6 + 1536,
        v6 + 1792,
        this->m_PrevRTPCParams.fDryLevel,
        v47->sRTPCParams.fDryLevel,
        v55,
        v59,
        in_fCurrentGain3,
        in_fTargetGain3,
        v21);
      if ( this->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v51, out_pfOutBuffer, v76, 1.0, 1.0, v58, v62, v57, v61, v21);
      v63 = v44 + 1;
      v64 = (float *)((char *)io_pBuffer->pData + 4 * v84 + 4 * v63 * (unsigned __int64)io_pBuffer->uMaxFrames);
      DSP::Mix3Interp(
        v64,
        v6 + 1536,
        v6 + 1792,
        this->m_PrevRTPCParams.fDryLevel,
        this->m_pParams->sRTPCParams.fDryLevel,
        in_fCurrentGain3,
        in_fTargetGain3,
        v55,
        v59,
        v21);
      if ( this->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v64, out_pfOutBuffer, v76, 1.0, 1.0, v57, v61, v58, v62, v21);
      v65 = v63 + 1;
      v66 = (float *)((char *)io_pBuffer->pData + 4 * v84 + 4 * v65 * (unsigned __int64)io_pBuffer->uMaxFrames);
      DSP::Mix3Interp(
        v66,
        v6 + 1536,
        v6 + 1792,
        this->m_PrevRTPCParams.fDryLevel,
        this->m_pParams->sRTPCParams.fDryLevel,
        v55,
        v59,
        in_fCurrentGain3,
        in_fTargetGain3,
        v21);
      if ( this->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v66, out_pfOutBuffer, v76, 1.0, 1.0, v58, v62, v57, v61, v21);
      v67 = v65 + 1;
      v68 = (float *)((char *)io_pBuffer->pData + 4 * v84 + 4 * v67 * (unsigned __int64)io_pBuffer->uMaxFrames);
      DSP::Mix3Interp(
        v68,
        v6 + 1536,
        v6 + 1792,
        this->m_PrevRTPCParams.fDryLevel,
        this->m_pParams->sRTPCParams.fDryLevel,
        in_fCurrentGain3,
        in_fTargetGain3,
        v55,
        v59,
        v21);
      if ( this->m_Reverb.uNumERSignals )
        DSP::Mix3Interp(v68, out_pfOutBuffer, v76, 1.0, 1.0, v57, v61, v58, v62, v21);
      v13 = FLOAT_0_70710599;
      if ( v80 )
      {
        v69 = this->m_pParams;
        v70 = (float)(v69->sRTPCParams.fReverbLevel * v69->sRTPCParams.fLFELevel) * 0.70710599;
        in_uNumFramesa = (float)(this->m_PrevRTPCParams.fReverbLevel * this->m_PrevRTPCParams.fLFELevel) * 0.70710599;
        DSP::Mix3Interp(
          (float *)io_pBuffer->pData + v84 + io_pBuffer->uMaxFrames * (unsigned __int64)(v67 + 1),
          v6 + 1024,
          v6 + 1280,
          this->m_PrevRTPCParams.fDryLevel,
          v69->sRTPCParams.fDryLevel,
          in_uNumFramesa,
          v70,
          in_uNumFramesa,
          v70,
          v21);
      }
      v71 = this->m_pParams;
      v12 = v82;
      v10 = in_pfInput2;
      v11 = in_pfInput3;
      v14 = v17;
      v16 = v82;
      v83 = v82;
      this->m_PrevRTPCParams.fDryLevel = v71->sRTPCParams.fDryLevel;
      p_ERDelay = &this->m_Reverb.ERDelay;
      this->m_PrevRTPCParams.fERLevel = v71->sRTPCParams.fERLevel;
      this->m_PrevRTPCParams.fReverbLevel = v71->sRTPCParams.fReverbLevel;
      this->m_PrevRTPCParams.fFrontLevel = v71->sRTPCParams.fFrontLevel;
      this->m_PrevRTPCParams.fCenterLevel = v71->sRTPCParams.fCenterLevel;
      this->m_PrevRTPCParams.fRearLevel = v71->sRTPCParams.fRearLevel;
      this->m_PrevRTPCParams.fLFELevel = v71->sRTPCParams.fLFELevel;
      in_uFrameOffset = v21 + v84;
      v72 = v85 == v21;
      uValidFrames = v85 - v21;
      v84 += v21;
      v85 -= v21;
    }
    while ( !v72 );
  }
  this->m_pAllocator->vfptr->Free(this->m_pAllocator, v6);
  return 1i64;
}

