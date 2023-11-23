// File Line: 25
// RVA: 0xB04AC0
void __fastcall CreateMcDSPFutzBoxFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CMcDSPFutzBoxFX *v1; // rax

  v1 = (CMcDSPFutzBoxFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 424i64);
  if ( v1 )
    CMcDSPFutzBoxFX::CMcDSPFutzBoxFX(v1);
}

// File Line: 33
// RVA: 0xB03A40
void __fastcall CMcDSPFutzBoxFX::CMcDSPFutzBoxFX(CMcDSPFutzBoxFX *this)
{
  this->m_pSharedParams = 0i64;
  this->vfptr = (AK::IAkPluginVtbl *)&CMcDSPFutzBoxFX::`vftable;
  McDSP::CAkWhiteNoise::CAkWhiteNoise(&this->m_State.WhiteNoise);
  this->m_State.tailHandler.uTailFramesRemaining = -1;
  this->m_State.tailHandler.uTotalTailFrames = 0;
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_FiltersPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_DistortionPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_EQPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_NoisePool);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_SIMPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_GatePool);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->m_LoFiPool);
  FutzFiltersImpl::FutzFiltersImpl(&this->m_FutzFiltersImpl);
  FutzDistortionImpl::FutzDistortionImpl(&this->m_FutzDistortionImpl);
  FutzEQFilterImpl::FutzEQFilterImpl(&this->m_FutzEQFilterImpl);
  FutzNoiseGenImpl::FutzNoiseGenImpl(&this->m_FutzNoiseGenImpl);
  FutzSIMImpl::FutzSIMImpl(&this->m_FutzSIMImpl);
  FutzGateImpl::FutzGateImpl(&this->m_FutzGateImpl);
  FutzLoFiImpl::FutzLoFiImpl(&this->m_FutzLoFiImpl);
}

// File Line: 39
// RVA: 0xB03B30
void __fastcall CMcDSPFutzBoxFX::~CMcDSPFutzBoxFX(CMcDSPFutzBoxFX *this)
{
  FutzLoFiImpl *p_m_FutzLoFiImpl; // rcx

  p_m_FutzLoFiImpl = &this->m_FutzLoFiImpl;
  p_m_FutzLoFiImpl[-26].MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxLoFiMemoryMap *)&CMcDSPFutzBoxFX::`vftable;
  FutzLoFiImpl::~FutzLoFiImpl(p_m_FutzLoFiImpl);
  FutzGateImpl::~FutzGateImpl(&this->m_FutzGateImpl);
  FutzSIMImpl::~FutzSIMImpl(&this->m_FutzSIMImpl);
  FutzNoiseGenImpl::~FutzNoiseGenImpl(&this->m_FutzNoiseGenImpl);
  FutzEQFilterImpl::~FutzEQFilterImpl(&this->m_FutzEQFilterImpl);
  FutzDistortionImpl::~FutzDistortionImpl(&this->m_FutzDistortionImpl);
  FutzFiltersImpl::~FutzFiltersImpl(&this->m_FutzFiltersImpl);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_LoFiPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_GatePool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_SIMPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_NoisePool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_EQPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_DistortionPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->m_FiltersPool);
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 48
// RVA: 0xB03C00
unsigned int __fastcall CMcDSPFutzBoxFX::Init(
        CMcDSPFutzBoxFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CMcDSPFutzBoxFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  AK::IAkPluginParam *p_m_Params; // rdx
  char *v8; // rcx
  __int64 v9; // rax
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm1
  int vfptr; // eax
  unsigned int v20; // edi
  int i; // ecx
  unsigned int MemoryMapSize; // eax
  unsigned int result; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // eax
  float v30; // xmm1_4
  float v31; // xmm0_4
  char Dst[148]; // [rsp+20h] [rbp-C8h] BYREF
  float v33; // [rsp+B4h] [rbp-34h]
  float v34; // [rsp+B8h] [rbp-30h]
  float v35; // [rsp+BCh] [rbp-2Ch]

  this->m_pAllocator = in_pAllocator;
  p_m_Params = (AK::IAkPluginParam *)&in_pParams->m_Params;
  this->m_pSharedParams = in_pParams;
  v8 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)((_BYTE)in_pParams + 8)) & 0xF) != 0 )
  {
    memmove(Dst, p_m_Params, 0xA4ui64);
  }
  else
  {
    v9 = 1i64;
    do
    {
      v10 = *(_OWORD *)&p_m_Params->vfptr;
      v11 = *(_OWORD *)&p_m_Params[2].vfptr;
      v8 += 128;
      p_m_Params += 16;
      *((_OWORD *)v8 - 8) = v10;
      v12 = *(_OWORD *)&p_m_Params[-12].vfptr;
      *((_OWORD *)v8 - 7) = v11;
      v13 = *(_OWORD *)&p_m_Params[-10].vfptr;
      *((_OWORD *)v8 - 6) = v12;
      v14 = *(_OWORD *)&p_m_Params[-8].vfptr;
      *((_OWORD *)v8 - 5) = v13;
      v15 = *(_OWORD *)&p_m_Params[-6].vfptr;
      *((_OWORD *)v8 - 4) = v14;
      v16 = *(_OWORD *)&p_m_Params[-4].vfptr;
      *((_OWORD *)v8 - 3) = v15;
      v17 = *(_OWORD *)&p_m_Params[-2].vfptr;
      *((_OWORD *)v8 - 2) = v16;
      *((_OWORD *)v8 - 1) = v17;
      --v9;
    }
    while ( v9 );
    v18 = *(_OWORD *)&p_m_Params[2].vfptr;
    vfptr = (int)p_m_Params[4].vfptr;
    *(_OWORD *)v8 = *(_OWORD *)&p_m_Params->vfptr;
    *((_OWORD *)v8 + 1) = v18;
    *((_DWORD *)v8 + 8) = vfptr;
  }
  v20 = 0;
  this->m_State.uSampleRate = in_rFormat->uSampleRate;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v20;
  this->m_State.uNumActiveModules = 0;
  this->m_State.uNumTailFrames = 0;
  if ( Dst[25] )
  {
    MemoryMapSize = FutzFiltersImpl::GetMemoryMapSize(&this->m_FutzFiltersImpl, v20);
    result = PooledMemoryAllocator::Init(&this->m_FiltersPool, in_pAllocator, MemoryMapSize);
    if ( result != 1 )
      return result;
    result = FutzFiltersImpl::Init(&this->m_FutzFiltersImpl, &this->m_FiltersPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++this->m_State.uNumActiveModules;
  }
  if ( Dst[45] )
  {
    v24 = FutzDistortionImpl::GetMemoryMapSize(&this->m_FutzDistortionImpl, v20);
    result = PooledMemoryAllocator::Init(&this->m_DistortionPool, in_pAllocator, v24);
    if ( result != 1 )
      return result;
    result = FutzDistortionImpl::Init(
               &this->m_FutzDistortionImpl,
               &this->m_DistortionPool,
               v20,
               in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++this->m_State.uNumActiveModules;
  }
  if ( Dst[65] )
  {
    v25 = FutzEQFilterImpl::GetMemoryMapSize(&this->m_FutzEQFilterImpl, v20);
    result = PooledMemoryAllocator::Init(&this->m_EQPool, in_pAllocator, v25);
    if ( result != 1 )
      return result;
    result = FutzEQFilterImpl::Init(&this->m_FutzEQFilterImpl, &this->m_EQPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++this->m_State.uNumActiveModules;
  }
  if ( Dst[93] )
  {
    v26 = FutzNoiseGenImpl::GetMemoryMapSize(&this->m_FutzNoiseGenImpl, v20);
    result = PooledMemoryAllocator::Init(&this->m_NoisePool, in_pAllocator, v26);
    if ( result != 1 )
      return result;
    result = FutzNoiseGenImpl::Init(&this->m_FutzNoiseGenImpl, &this->m_NoisePool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++this->m_State.uNumActiveModules;
  }
  if ( Dst[117] )
  {
    v27 = FutzGateImpl::GetMemoryMapSize(&this->m_FutzGateImpl, v20);
    result = PooledMemoryAllocator::Init(&this->m_GatePool, in_pAllocator, v27);
    if ( result != 1 )
      return result;
    result = FutzGateImpl::Init(&this->m_FutzGateImpl, &this->m_GatePool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++this->m_State.uNumActiveModules;
  }
  if ( Dst[129] )
  {
    v28 = FutzSIMImpl::GetMemoryMapSize(&this->m_FutzSIMImpl, v20);
    result = PooledMemoryAllocator::Init(&this->m_SIMPool, in_pAllocator, v28);
    if ( result != 1 )
      return result;
    result = FutzSIMImpl::Init(&this->m_FutzSIMImpl, &this->m_SIMPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++this->m_State.uNumActiveModules;
  }
  if ( !Dst[145] )
  {
LABEL_36:
    v30 = v34;
    result = 1;
    this->m_State.fPrevInputGain = v33;
    v31 = v35;
    this->m_State.fPrevOutputGain = v30;
    this->m_State.fPrevWetDryMix = v31;
    return result;
  }
  v29 = FutzLoFiImpl::GetMemoryMapSize(&this->m_FutzLoFiImpl, v20);
  result = PooledMemoryAllocator::Init(&this->m_LoFiPool, in_pAllocator, v29);
  if ( result == 1 )
  {
    result = FutzLoFiImpl::Init(&this->m_FutzLoFiImpl, &this->m_LoFiPool, v20, in_rFormat->uSampleRate);
    if ( result == 1 )
    {
      ++this->m_State.uNumActiveModules;
      goto LABEL_36;
    }
  }
  return result;
}

// File Line: 128
// RVA: 0xB03FA0
__int64 __fastcall CMcDSPFutzBoxFX::Term(CMcDSPFutzBoxFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  PooledMemoryAllocator::Term(&this->m_FiltersPool, in_pAllocator);
  PooledMemoryAllocator::Term(&this->m_DistortionPool, in_pAllocator);
  PooledMemoryAllocator::Term(&this->m_EQPool, in_pAllocator);
  PooledMemoryAllocator::Term(&this->m_NoisePool, in_pAllocator);
  PooledMemoryAllocator::Term(&this->m_SIMPool, in_pAllocator);
  PooledMemoryAllocator::Term(&this->m_GatePool, in_pAllocator);
  PooledMemoryAllocator::Term(&this->m_LoFiPool, in_pAllocator);
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 144
// RVA: 0xB04050
__int64 __fastcall CMcDSPFutzBoxFX::Reset(CMcDSPFutzBoxFX *this)
{
  return 1i64;
}

// File Line: 159
// RVA: 0xB04060
__int64 __fastcall CMcDSPFutzBoxFX::GetPluginInfo(CMcDSPFutzBoxFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 287
// RVA: 0xB045B0
void __fastcall CMcDSPFutzBoxFX::PushParamsToMemoryMaps(CMcDSPFutzBoxFX *this, McDSPFutzBoxFXParams *in_rFXParams)
{
  float fLPFFreq; // xmm0_4
  float fLPFQ; // xmm1_4
  unsigned int m_uNumTailFrames; // ebx
  FutzFilterSlope HPFSlope; // eax
  float fHPFFreq; // xmm0_4
  float fHPFQ; // xmm1_4
  float fAmount; // xmm0_4
  float fIntensity; // xmm1_4
  FutzDistortionMode iMode; // eax
  float fRectify; // xmm0_4
  unsigned int v14; // ebx
  long double fFreq; // xmm0_8
  long double fQ; // xmm1_8
  float fLevel; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  long double fThresh; // xmm1_8
  float fRange; // xmm0_4
  long double fRecovery; // xmm1_8
  FutzSIMType iType; // eax
  unsigned int v24; // ebx
  float fThreshold; // xmm0_4
  float v26; // xmm1_4
  float fAttack; // xmm0_4
  float fHold; // xmm1_4
  long double fRelease; // xmm0_8
  float fFilter; // xmm0_4
  int iDownSampleIndex; // eax
  FutzFilterParameters fFilterParams; // [rsp+20h] [rbp-50h] BYREF
  FutzNoiseParameters hpfFilterParams; // [rsp+38h] [rbp-38h] BYREF

  if ( in_rFXParams->Filters.bEnable && in_rFXParams->Filters.bParamsHaveChanged )
  {
    fLPFFreq = in_rFXParams->Filters.fLPFFreq;
    fLPFQ = in_rFXParams->Filters.fLPFQ;
    m_uNumTailFrames = this->m_FutzFiltersImpl.m_uNumTailFrames;
    fFilterParams.slope = in_rFXParams->Filters.LPFSlope;
    HPFSlope = in_rFXParams->Filters.HPFSlope;
    fFilterParams.bypassed = 0;
    fFilterParams.frequency = fLPFFreq;
    fHPFFreq = in_rFXParams->Filters.fHPFFreq;
    fFilterParams.peakPercent = fLPFQ;
    LODWORD(hpfFilterParams.lpfFrequency) = HPFSlope;
    BYTE4(hpfFilterParams.lpfFrequency) = 0;
    fHPFQ = in_rFXParams->Filters.fHPFQ;
    hpfFilterParams.level = fHPFFreq;
    hpfFilterParams.hpfFrequency = fHPFQ;
    FutzFiltersImpl::SetParameters(&this->m_FutzFiltersImpl, (FutzFilterParameters *)&hpfFilterParams, &fFilterParams);
    this->m_State.uNumTailFrames += this->m_FutzFiltersImpl.m_uNumTailFrames - m_uNumTailFrames;
  }
  if ( in_rFXParams->Distortion.bEnable && in_rFXParams->Distortion.bParamsHaveChanged )
  {
    fAmount = in_rFXParams->Distortion.fAmount;
    fIntensity = in_rFXParams->Distortion.fIntensity;
    iMode = in_rFXParams->Distortion.iMode;
    BYTE4(hpfFilterParams.threshold) = 0;
    LODWORD(hpfFilterParams.threshold) = iMode;
    hpfFilterParams.level = fAmount;
    fRectify = in_rFXParams->Distortion.fRectify;
    hpfFilterParams.hpfFrequency = fIntensity;
    hpfFilterParams.lpfFrequency = fRectify;
    FutzDistortionImpl::SetParameters(&this->m_FutzDistortionImpl, (FutzDistortionParameters *)&hpfFilterParams);
  }
  if ( in_rFXParams->EQ.bEnable && in_rFXParams->EQ.bParamsHaveChanged )
  {
    v14 = this->m_FutzEQFilterImpl.m_uNumTailFrames;
    fFreq = in_rFXParams->EQ.fFreq;
    fQ = in_rFXParams->EQ.fQ;
    LODWORD(hpfFilterParams.threshold) = in_rFXParams->EQ.FilterType;
    BYTE4(hpfFilterParams.threshold) = 0;
    hpfFilterParams.level = fFreq;
    *(float *)&fFreq = in_rFXParams->EQ.fGain;
    hpfFilterParams.hpfFrequency = fQ;
    hpfFilterParams.lpfFrequency = *(float *)&fFreq;
    FutzEQFilterImpl::SetParameters(&this->m_FutzEQFilterImpl, (FutzEQParameters *)&hpfFilterParams);
    this->m_State.uNumTailFrames += this->m_FutzEQFilterImpl.m_uNumTailFrames - v14;
  }
  if ( in_rFXParams->Noise.bEnable && in_rFXParams->Noise.bParamsHaveChanged )
  {
    fLevel = in_rFXParams->Noise.fLevel;
    v18 = in_rFXParams->Noise.fHPFFreq;
    hpfFilterParams.bypassed = 0;
    hpfFilterParams.level = fLevel;
    v19 = in_rFXParams->Noise.fLPFFreq;
    hpfFilterParams.hpfFrequency = v18;
    fThresh = in_rFXParams->Noise.fThresh;
    hpfFilterParams.lpfFrequency = v19;
    fRange = in_rFXParams->Noise.fRange;
    hpfFilterParams.threshold = fThresh;
    fRecovery = in_rFXParams->Noise.fRecovery;
    hpfFilterParams.range = fRange;
    hpfFilterParams.recovery = fRecovery;
    FutzNoiseGenImpl::SetParameters(&this->m_FutzNoiseGenImpl, &hpfFilterParams);
  }
  if ( in_rFXParams->SIM.bEnable && in_rFXParams->SIM.bParamsHaveChanged )
  {
    iType = in_rFXParams->SIM.iType;
    v24 = this->m_FutzSIMImpl.m_uNumTailFrames;
    hpfFilterParams.hpfFrequency = in_rFXParams->SIM.fTuning;
    LODWORD(hpfFilterParams.level) = iType;
    LOBYTE(hpfFilterParams.lpfFrequency) = 0;
    FutzSIMImpl::SetParameters(&this->m_FutzSIMImpl, (FutzSIMParameters *)&hpfFilterParams);
    this->m_State.uNumTailFrames += this->m_FutzSIMImpl.m_uNumTailFrames - v24;
  }
  if ( in_rFXParams->Gate.bEnable && in_rFXParams->Gate.bParamsHaveChanged )
  {
    fThreshold = in_rFXParams->Gate.fThreshold;
    v26 = in_rFXParams->Gate.fRange;
    LOBYTE(hpfFilterParams.recovery) = 0;
    hpfFilterParams.level = fThreshold;
    fAttack = in_rFXParams->Gate.fAttack;
    hpfFilterParams.hpfFrequency = v26;
    fHold = in_rFXParams->Gate.fHold;
    hpfFilterParams.lpfFrequency = fAttack;
    fRelease = in_rFXParams->Gate.fRelease;
    hpfFilterParams.threshold = fHold;
    hpfFilterParams.range = fRelease;
    FutzGateImpl::SetParameters(&this->m_FutzGateImpl, (FutzGateParameters *)&hpfFilterParams);
  }
  if ( in_rFXParams->LoFi.bEnable && in_rFXParams->LoFi.bParamsHaveChanged )
  {
    fFilter = in_rFXParams->LoFi.fFilter;
    LODWORD(hpfFilterParams.level) = in_rFXParams->LoFi.iBitDepthType;
    iDownSampleIndex = in_rFXParams->LoFi.iDownSampleIndex;
    hpfFilterParams.hpfFrequency = fFilter;
    LOBYTE(hpfFilterParams.lpfFrequency) = 0;
    HIDWORD(hpfFilterParams.level) = iDownSampleIndex;
    FutzLoFiImpl::SetParameters(&this->m_FutzLoFiImpl, (FutzLoFiParameters *)&hpfFilterParams);
  }
}

// File Line: 479
// RVA: 0xB04080
void __fastcall CMcDSPFutzBoxFX::Execute(CMcDSPFutzBoxFX *this, AkAudioBuffer *io_pBuffer)
{
  McDSPFutzBoxFXParams *p_Dst; // r8
  McDSPFutzBoxFXParams *p_m_Params; // rdx
  __int64 v6; // rax
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  McDSPFutzLoFiFXParams LoFi; // xmm0
  McDSPGlobalFXParams Global; // xmm1
  __int128 v15; // xmm1
  float fAmount; // eax
  CMcDSPFutzBoxFXParams *m_pSharedParams; // rax
  unsigned __int16 uValidFrames; // bp
  unsigned int uChannelMask; // ecx
  __int64 v20; // r15
  unsigned int i; // ebx
  unsigned __int64 v22; // rdi
  float *v23; // r13
  float v24; // xmm7_4
  float fBalance; // xmm11_4
  float v26; // xmm9_4
  float v27; // xmm7_4
  float fOutputGain; // xmm12_4
  float in_fTargetGain2; // xmm10_4
  float v30; // xmm8_4
  char *v31; // rax
  float fInputGain; // xmm6_4
  __int64 v33; // r14
  float fPrevInputGain; // xmm1_4
  float *v35; // rbx
  size_t v36; // r10
  char *v37; // [rsp+40h] [rbp-198h]
  float *in_pfInput2; // [rsp+48h] [rbp-190h]
  char *v39; // [rsp+50h] [rbp-188h]
  char *v40; // [rsp+58h] [rbp-180h]
  McDSPFutzBoxFXParams Dst; // [rsp+70h] [rbp-168h] BYREF
  char *memoryBlock; // [rsp+1E0h] [rbp+8h]
  char *PointerToPooledMemory; // [rsp+1E8h] [rbp+10h]
  char *v44; // [rsp+1F0h] [rbp+18h]
  char *v45; // [rsp+1F8h] [rbp+20h]

  p_Dst = &Dst;
  p_m_Params = &this->m_pSharedParams->m_Params;
  if ( (((unsigned __int8)&Dst | (unsigned __int8)p_m_Params) & 0xF) != 0 )
  {
    memmove(&Dst, p_m_Params, 0xA4ui64);
  }
  else
  {
    v6 = 1i64;
    do
    {
      v7 = *(_OWORD *)&p_m_Params->Filters.LPFSlope;
      v8 = *(_OWORD *)&p_m_Params->Filters.fHPFFreq;
      p_Dst = (McDSPFutzBoxFXParams *)((char *)p_Dst + 128);
      p_m_Params = (McDSPFutzBoxFXParams *)((char *)p_m_Params + 128);
      *(_OWORD *)&p_Dst[-1].Distortion.fIntensity = v7;
      v9 = *(_OWORD *)&p_m_Params[-1].Noise.fLevel;
      *(_OWORD *)&p_Dst[-1].EQ.fFreq = v8;
      v10 = *(_OWORD *)&p_m_Params[-1].Noise.fRange;
      *(_OWORD *)&p_Dst[-1].Noise.fLevel = v9;
      v11 = *(_OWORD *)&p_m_Params[-1].Gate.fRange;
      *(_OWORD *)&p_Dst[-1].Noise.fRange = v10;
      v12 = *(_OWORD *)&p_m_Params[-1].Gate.bParamsHaveChanged;
      *(_OWORD *)&p_Dst[-1].Gate.fRange = v11;
      LoFi = p_m_Params[-1].LoFi;
      *(_OWORD *)&p_Dst[-1].Gate.bParamsHaveChanged = v12;
      Global = p_m_Params[-1].Global;
      p_Dst[-1].LoFi = LoFi;
      p_Dst[-1].Global = Global;
      --v6;
    }
    while ( v6 );
    v15 = *(_OWORD *)&p_m_Params->Filters.fHPFFreq;
    fAmount = p_m_Params->Distortion.fAmount;
    *(_OWORD *)&p_Dst->Filters.LPFSlope = *(_OWORD *)&p_m_Params->Filters.LPFSlope;
    *(_OWORD *)&p_Dst->Filters.fHPFFreq = v15;
    p_Dst->Distortion.fAmount = fAmount;
  }
  CMcDSPFutzBoxFX::PushParamsToMemoryMaps(this, &Dst);
  m_pSharedParams = this->m_pSharedParams;
  m_pSharedParams->m_Params.Filters.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.Distortion.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.EQ.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.Noise.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.Gate.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.SIM.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.LoFi.bParamsHaveChanged = 0;
  m_pSharedParams->m_Params.Global.bParamsHaveChanged = 0;
  AkFXTailHandler::HandleTail(&this->m_State.tailHandler, io_pBuffer, this->m_State.uNumTailFrames);
  uValidFrames = io_pBuffer->uValidFrames;
  if ( uValidFrames )
  {
    uChannelMask = io_pBuffer->uChannelMask;
    v20 = 0i64;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    v22 = 4i64 * io_pBuffer->uMaxFrames;
    v23 = 0i64;
    in_pfInput2 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v22);
    if ( in_pfInput2 )
    {
      if ( !Dst.Noise.bEnable || (v23 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v22)) != 0i64 )
      {
        v24 = this->m_State.fPrevWetDryMix * 0.0099999998;
        fBalance = Dst.Global.fBalance;
        v26 = 1.0 - v24;
        v27 = v24 * this->m_State.fPrevOutputGain;
        fOutputGain = Dst.Global.fOutputGain;
        in_fTargetGain2 = 1.0 - (float)(Dst.Global.fBalance * 0.0099999998);
        v30 = (float)(Dst.Global.fBalance * 0.0099999998) * Dst.Global.fOutputGain;
        memoryBlock = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_FiltersPool, 0i64);
        PointerToPooledMemory = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_DistortionPool, 0i64);
        v44 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_EQPool, 0i64);
        v45 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_NoisePool, 0i64);
        v40 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_SIMPool, 0i64);
        v39 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_GatePool, 0i64);
        v31 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->m_LoFiPool, 0i64);
        fInputGain = Dst.Global.fInputGain;
        v37 = v31;
        if ( i )
        {
          v33 = i;
          do
          {
            fPrevInputGain = this->m_State.fPrevInputGain;
            v35 = (float *)((char *)io_pBuffer->pData + 4 * v20 * io_pBuffer->uMaxFrames);
            if ( fInputGain == fPrevInputGain )
              AK::DSP::ApplyGain_12(v35, fPrevInputGain, uValidFrames);
            else
              AK::DSP::ApplyGainRamp_5(v35, fPrevInputGain, fInputGain, uValidFrames);
            memmove(in_pfInput2, v35, v36);
            if ( Dst.Filters.bEnable )
              memoryBlock = ProcessFutzBoxFiltersWwise(memoryBlock, v35, v35, uValidFrames);
            if ( Dst.Distortion.bEnable )
              PointerToPooledMemory = ProcessFutzBoxDistortionWwise(PointerToPooledMemory, v35, v35, uValidFrames);
            if ( Dst.EQ.bEnable )
              v44 = ProcessFutzBoxEQFilterWwise(v44, v35, v35, uValidFrames);
            if ( Dst.Noise.bEnable )
            {
              McDSP::CAkWhiteNoise::GenerateBuffer(&this->m_State.WhiteNoise, v23, uValidFrames);
              v45 = ProcessFutzBoxNoiseGenWwise(v45, v35, v23, v35, uValidFrames);
            }
            if ( Dst.SIM.bEnable )
              v40 = ProcessFutzBoxSIMWwise(v40, v35, v35, uValidFrames);
            if ( Dst.Gate.bEnable )
              v39 = ProcessFutzBoxGateWwise(v39, v35, v35, uValidFrames);
            if ( Dst.LoFi.bEnable )
              v37 = ProcessFutzBoxLoFiWwise(v37, v35, v35, uValidFrames);
            McDSP::Mix2Interp(v35, in_pfInput2, v27, v30, v26, in_fTargetGain2, uValidFrames);
            ++v20;
            --v33;
          }
          while ( v33 );
        }
        this->m_State.fPrevInputGain = fInputGain;
        this->m_State.fPrevOutputGain = fOutputGain;
        this->m_State.fPrevWetDryMix = fBalance;
        if ( v23 )
          this->m_pAllocator->vfptr->Free(this->m_pAllocator, v23);
      }
      this->m_pAllocator->vfptr->Free(this->m_pAllocator, in_pfInput2);
    }
  }
}

