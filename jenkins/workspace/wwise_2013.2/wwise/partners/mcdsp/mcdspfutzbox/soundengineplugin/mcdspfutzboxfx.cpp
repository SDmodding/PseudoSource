// File Line: 25
// RVA: 0xB04AC0
void __fastcall CreateMcDSPFutzBoxFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CMcDSPFutzBoxFX *v1; // rax

  v1 = (CMcDSPFutzBoxFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 424ui64);
  if ( v1 )
    CMcDSPFutzBoxFX::CMcDSPFutzBoxFX(v1);
}

// File Line: 33
// RVA: 0xB03A40
void __fastcall CMcDSPFutzBoxFX::CMcDSPFutzBoxFX(CMcDSPFutzBoxFX *this)
{
  CMcDSPFutzBoxFX *v1; // rdi

  v1 = this;
  this->m_pSharedParams = 0i64;
  this->vfptr = (AK::IAkPluginVtbl *)&CMcDSPFutzBoxFX::`vftable';
  McDSP::CAkWhiteNoise::CAkWhiteNoise(&this->m_State.WhiteNoise);
  v1->m_State.tailHandler.uTailFramesRemaining = -1;
  v1->m_State.tailHandler.uTotalTailFrames = 0;
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_FiltersPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_DistortionPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_EQPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_NoisePool);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_SIMPool);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_GatePool);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->m_LoFiPool);
  FutzFiltersImpl::FutzFiltersImpl(&v1->m_FutzFiltersImpl);
  FutzDistortionImpl::FutzDistortionImpl(&v1->m_FutzDistortionImpl);
  FutzEQFilterImpl::FutzEQFilterImpl(&v1->m_FutzEQFilterImpl);
  FutzNoiseGenImpl::FutzNoiseGenImpl(&v1->m_FutzNoiseGenImpl);
  FutzSIMImpl::FutzSIMImpl(&v1->m_FutzSIMImpl);
  FutzGateImpl::FutzGateImpl(&v1->m_FutzGateImpl);
  FutzLoFiImpl::FutzLoFiImpl(&v1->m_FutzLoFiImpl);
}

// File Line: 39
// RVA: 0xB03B30
void __fastcall CMcDSPFutzBoxFX::~CMcDSPFutzBoxFX(CMcDSPFutzBoxFX *this)
{
  CMcDSPFutzBoxFX *v1; // rbx
  FutzLoFiImpl *v2; // rcx

  v1 = this;
  v2 = &this->m_FutzLoFiImpl;
  v2[-26].MemoryMapHelper.FutzBoxMemMapPtr = (FutzBoxLoFiMemoryMap *)&CMcDSPFutzBoxFX::`vftable';
  FutzLoFiImpl::~FutzLoFiImpl(v2);
  FutzGateImpl::~FutzGateImpl(&v1->m_FutzGateImpl);
  FutzSIMImpl::~FutzSIMImpl(&v1->m_FutzSIMImpl);
  FutzNoiseGenImpl::~FutzNoiseGenImpl(&v1->m_FutzNoiseGenImpl);
  FutzEQFilterImpl::~FutzEQFilterImpl(&v1->m_FutzEQFilterImpl);
  FutzDistortionImpl::~FutzDistortionImpl(&v1->m_FutzDistortionImpl);
  FutzFiltersImpl::~FutzFiltersImpl(&v1->m_FutzFiltersImpl);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_LoFiPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_GatePool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_SIMPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_NoisePool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_EQPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_DistortionPool);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->m_FiltersPool);
  v1->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 48
// RVA: 0xB03C00
unsigned int __fastcall CMcDSPFutzBoxFX::Init(CMcDSPFutzBoxFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  AK::IAkPluginMemAlloc *v5; // r15
  AK::IAkPluginParam *v6; // rdx
  CMcDSPFutzBoxFX *v7; // rbx
  char *v8; // rcx
  signed __int64 v9; // rax
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm1
  int v19; // eax
  unsigned int v20; // edi
  int i; // ecx
  unsigned int v22; // eax
  unsigned int result; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // eax
  int v30; // xmm1_4
  int v31; // xmm0_4
  char Dst; // [rsp+20h] [rbp-C8h]
  char v33; // [rsp+39h] [rbp-AFh]
  char v34; // [rsp+4Dh] [rbp-9Bh]
  char v35; // [rsp+61h] [rbp-87h]
  char v36; // [rsp+7Dh] [rbp-6Bh]
  char v37; // [rsp+95h] [rbp-53h]
  char v38; // [rsp+A1h] [rbp-47h]
  char v39; // [rsp+B1h] [rbp-37h]
  float v40; // [rsp+B4h] [rbp-34h]
  int v41; // [rsp+B8h] [rbp-30h]
  int v42; // [rsp+BCh] [rbp-2Ch]

  this->m_pAllocator = in_pAllocator;
  v5 = in_pAllocator;
  v6 = in_pParams + 1;
  v7 = this;
  this->m_pSharedParams = (CMcDSPFutzBoxFXParams *)in_pParams;
  v8 = &Dst;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)((_BYTE)in_pParams + 8)) & 0xF )
  {
    memmove(&Dst, v6, 0xA4ui64);
  }
  else
  {
    v9 = 1i64;
    do
    {
      v10 = *(_OWORD *)&v6->vfptr;
      v11 = *(_OWORD *)&v6[2].vfptr;
      v8 += 128;
      v6 += 16;
      *((_OWORD *)v8 - 8) = v10;
      v12 = *(_OWORD *)&v6[-12].vfptr;
      *((_OWORD *)v8 - 7) = v11;
      v13 = *(_OWORD *)&v6[-10].vfptr;
      *((_OWORD *)v8 - 6) = v12;
      v14 = *(_OWORD *)&v6[-8].vfptr;
      *((_OWORD *)v8 - 5) = v13;
      v15 = *(_OWORD *)&v6[-6].vfptr;
      *((_OWORD *)v8 - 4) = v14;
      v16 = *(_OWORD *)&v6[-4].vfptr;
      *((_OWORD *)v8 - 3) = v15;
      v17 = *(_OWORD *)&v6[-2].vfptr;
      *((_OWORD *)v8 - 2) = v16;
      *((_OWORD *)v8 - 1) = v17;
      --v9;
    }
    while ( v9 );
    v18 = *(_OWORD *)&v6[2].vfptr;
    v19 = (int)v6[4].vfptr;
    *(_OWORD *)v8 = *(_OWORD *)&v6->vfptr;
    *((_OWORD *)v8 + 1) = v18;
    *((_DWORD *)v8 + 8) = v19;
  }
  v20 = 0;
  v7->m_State.uSampleRate = in_rFormat->uSampleRate;
  for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
    ++v20;
  v7->m_State.uNumActiveModules = 0;
  v7->m_State.uNumTailFrames = 0;
  if ( v33 )
  {
    v22 = FutzFiltersImpl::GetMemoryMapSize(&v7->m_FutzFiltersImpl, v20);
    result = PooledMemoryAllocator::Init(&v7->m_FiltersPool, v5, v22);
    if ( result != 1 )
      return result;
    result = FutzFiltersImpl::Init(&v7->m_FutzFiltersImpl, &v7->m_FiltersPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++v7->m_State.uNumActiveModules;
  }
  if ( v34 )
  {
    v24 = FutzDistortionImpl::GetMemoryMapSize(&v7->m_FutzDistortionImpl, v20);
    result = PooledMemoryAllocator::Init(&v7->m_DistortionPool, v5, v24);
    if ( result != 1 )
      return result;
    result = FutzDistortionImpl::Init(&v7->m_FutzDistortionImpl, &v7->m_DistortionPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++v7->m_State.uNumActiveModules;
  }
  if ( v35 )
  {
    v25 = FutzEQFilterImpl::GetMemoryMapSize(&v7->m_FutzEQFilterImpl, v20);
    result = PooledMemoryAllocator::Init(&v7->m_EQPool, v5, v25);
    if ( result != 1 )
      return result;
    result = FutzEQFilterImpl::Init(&v7->m_FutzEQFilterImpl, &v7->m_EQPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++v7->m_State.uNumActiveModules;
  }
  if ( v36 )
  {
    v26 = FutzNoiseGenImpl::GetMemoryMapSize(&v7->m_FutzNoiseGenImpl, v20);
    result = PooledMemoryAllocator::Init(&v7->m_NoisePool, v5, v26);
    if ( result != 1 )
      return result;
    result = FutzNoiseGenImpl::Init(&v7->m_FutzNoiseGenImpl, &v7->m_NoisePool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++v7->m_State.uNumActiveModules;
  }
  if ( v37 )
  {
    v27 = FutzGateImpl::GetMemoryMapSize(&v7->m_FutzGateImpl, v20);
    result = PooledMemoryAllocator::Init(&v7->m_GatePool, v5, v27);
    if ( result != 1 )
      return result;
    result = FutzGateImpl::Init(&v7->m_FutzGateImpl, &v7->m_GatePool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++v7->m_State.uNumActiveModules;
  }
  if ( v38 )
  {
    v28 = FutzSIMImpl::GetMemoryMapSize(&v7->m_FutzSIMImpl, v20);
    result = PooledMemoryAllocator::Init(&v7->m_SIMPool, v5, v28);
    if ( result != 1 )
      return result;
    result = FutzSIMImpl::Init(&v7->m_FutzSIMImpl, &v7->m_SIMPool, v20, in_rFormat->uSampleRate);
    if ( result != 1 )
      return result;
    ++v7->m_State.uNumActiveModules;
  }
  if ( !v39 )
  {
LABEL_36:
    v30 = v41;
    result = 1;
    v7->m_State.fPrevInputGain = v40;
    v31 = v42;
    LODWORD(v7->m_State.fPrevOutputGain) = v30;
    LODWORD(v7->m_State.fPrevWetDryMix) = v31;
    return result;
  }
  v29 = FutzLoFiImpl::GetMemoryMapSize(&v7->m_FutzLoFiImpl, v20);
  result = PooledMemoryAllocator::Init(&v7->m_LoFiPool, v5, v29);
  if ( result == 1 )
  {
    result = FutzLoFiImpl::Init(&v7->m_FutzLoFiImpl, &v7->m_LoFiPool, v20, in_rFormat->uSampleRate);
    if ( result == 1 )
    {
      ++v7->m_State.uNumActiveModules;
      goto LABEL_36;
    }
  }
  return result;
}

// File Line: 128
// RVA: 0xB03FA0
signed __int64 __fastcall CMcDSPFutzBoxFX::Term(CMcDSPFutzBoxFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CMcDSPFutzBoxFX *v2; // rbx
  AK::IAkPluginMemAlloc *v3; // rdi

  v2 = this;
  v3 = in_pAllocator;
  PooledMemoryAllocator::Term(&this->m_FiltersPool, in_pAllocator);
  PooledMemoryAllocator::Term(&v2->m_DistortionPool, v3);
  PooledMemoryAllocator::Term(&v2->m_EQPool, v3);
  PooledMemoryAllocator::Term(&v2->m_NoisePool, v3);
  PooledMemoryAllocator::Term(&v2->m_SIMPool, v3);
  PooledMemoryAllocator::Term(&v2->m_GatePool, v3);
  PooledMemoryAllocator::Term(&v2->m_LoFiPool, v3);
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((AK::IAkPlugin *)&v2->vfptr, 0);
    v3->vfptr->Free(v3, v2);
  }
  return 1i64;
}

// File Line: 144
// RVA: 0xB04050
signed __int64 __fastcall CMcDSPFutzBoxFX::Reset(CMcDSPFutzBoxFX *this)
{
  return 1i64;
}

// File Line: 159
// RVA: 0xB04060
signed __int64 __fastcall CMcDSPFutzBoxFX::GetPluginInfo(CMcDSPFutzBoxFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 287
// RVA: 0xB045B0
void __fastcall CMcDSPFutzBoxFX::PushParamsToMemoryMaps(CMcDSPFutzBoxFX *this, McDSPFutzBoxFXParams *in_rFXParams)
{
  McDSPFutzBoxFXParams *v2; // rdi
  CMcDSPFutzBoxFX *v3; // rsi
  float v4; // xmm0_4
  float v5; // xmm1_4
  unsigned int v6; // ebx
  FutzFilterSlope v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  FutzDistortionMode v12; // eax
  float v13; // xmm0_4
  unsigned int v14; // ebx
  long double v15; // xmm0_8
  long double v16; // xmm1_8
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  double v20; // xmm1_8
  float v21; // xmm0_4
  double v22; // xmm1_8
  FutzSIMType v23; // eax
  unsigned int v24; // ebx
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  double v29; // xmm0_8
  float v30; // xmm0_4
  int v31; // eax
  FutzFilterParameters fFilterParams; // [rsp+20h] [rbp-50h]
  FutzFilterParameters hpfFilterParams; // [rsp+38h] [rbp-38h]
  double v34; // [rsp+50h] [rbp-20h]
  double v35; // [rsp+58h] [rbp-18h]
  double v36; // [rsp+60h] [rbp-10h]
  char v37; // [rsp+68h] [rbp-8h]

  v2 = in_rFXParams;
  v3 = this;
  if ( in_rFXParams->Filters.bEnable && in_rFXParams->Filters.bParamsHaveChanged )
  {
    v4 = in_rFXParams->Filters.fLPFFreq;
    v5 = in_rFXParams->Filters.fLPFQ;
    v6 = this->m_FutzFiltersImpl.m_uNumTailFrames;
    fFilterParams.slope = in_rFXParams->Filters.LPFSlope;
    v7 = in_rFXParams->Filters.HPFSlope;
    fFilterParams.bypassed = 0;
    fFilterParams.frequency = v4;
    v8 = in_rFXParams->Filters.fHPFFreq;
    fFilterParams.peakPercent = v5;
    hpfFilterParams.slope = v7;
    hpfFilterParams.bypassed = 0;
    v9 = in_rFXParams->Filters.fHPFQ;
    hpfFilterParams.frequency = v8;
    hpfFilterParams.peakPercent = v9;
    FutzFiltersImpl::SetParameters(&this->m_FutzFiltersImpl, &hpfFilterParams, &fFilterParams);
    v3->m_State.uNumTailFrames += v3->m_FutzFiltersImpl.m_uNumTailFrames - v6;
  }
  if ( v2->Distortion.bEnable && v2->Distortion.bParamsHaveChanged )
  {
    v10 = v2->Distortion.fAmount;
    v11 = v2->Distortion.fIntensity;
    v12 = v2->Distortion.iMode;
    BYTE4(v34) = 0;
    LODWORD(v34) = v12;
    hpfFilterParams.frequency = v10;
    v13 = v2->Distortion.fRectify;
    hpfFilterParams.peakPercent = v11;
    *(double *)&hpfFilterParams.slope = v13;
    FutzDistortionImpl::SetParameters(&v3->m_FutzDistortionImpl, (FutzDistortionParameters *)&hpfFilterParams);
  }
  if ( v2->EQ.bEnable && v2->EQ.bParamsHaveChanged )
  {
    v14 = v3->m_FutzEQFilterImpl.m_uNumTailFrames;
    v15 = v2->EQ.fFreq;
    v16 = v2->EQ.fQ;
    LODWORD(v34) = v2->EQ.FilterType;
    BYTE4(v34) = 0;
    hpfFilterParams.frequency = v15;
    *(float *)&v15 = v2->EQ.fGain;
    hpfFilterParams.peakPercent = v16;
    *(double *)&hpfFilterParams.slope = *(float *)&v15;
    FutzEQFilterImpl::SetParameters(&v3->m_FutzEQFilterImpl, (FutzEQParameters *)&hpfFilterParams);
    v3->m_State.uNumTailFrames += v3->m_FutzEQFilterImpl.m_uNumTailFrames - v14;
  }
  if ( v2->Noise.bEnable && v2->Noise.bParamsHaveChanged )
  {
    v17 = v2->Noise.fLevel;
    v18 = v2->Noise.fHPFFreq;
    v37 = 0;
    hpfFilterParams.frequency = v17;
    v19 = v2->Noise.fLPFFreq;
    hpfFilterParams.peakPercent = v18;
    v20 = v2->Noise.fThresh;
    *(double *)&hpfFilterParams.slope = v19;
    v21 = v2->Noise.fRange;
    v34 = v20;
    v22 = v2->Noise.fRecovery;
    v35 = v21;
    v36 = v22;
    FutzNoiseGenImpl::SetParameters(&v3->m_FutzNoiseGenImpl, (FutzNoiseParameters *)&hpfFilterParams);
  }
  if ( v2->SIM.bEnable && v2->SIM.bParamsHaveChanged )
  {
    v23 = v2->SIM.iType;
    v24 = v3->m_FutzSIMImpl.m_uNumTailFrames;
    hpfFilterParams.peakPercent = v2->SIM.fTuning;
    LODWORD(hpfFilterParams.frequency) = v23;
    LOBYTE(hpfFilterParams.slope) = 0;
    FutzSIMImpl::SetParameters(&v3->m_FutzSIMImpl, (FutzSIMParameters *)&hpfFilterParams);
    v3->m_State.uNumTailFrames += v3->m_FutzSIMImpl.m_uNumTailFrames - v24;
  }
  if ( v2->Gate.bEnable && v2->Gate.bParamsHaveChanged )
  {
    v25 = v2->Gate.fThreshold;
    v26 = v2->Gate.fRange;
    LOBYTE(v36) = 0;
    hpfFilterParams.frequency = v25;
    v27 = v2->Gate.fAttack;
    hpfFilterParams.peakPercent = v26;
    v28 = v2->Gate.fHold;
    *(double *)&hpfFilterParams.slope = v27;
    v29 = v2->Gate.fRelease;
    v34 = v28;
    v35 = v29;
    FutzGateImpl::SetParameters(&v3->m_FutzGateImpl, (FutzGateParameters *)&hpfFilterParams);
  }
  if ( v2->LoFi.bEnable )
  {
    if ( v2->LoFi.bParamsHaveChanged )
    {
      v30 = v2->LoFi.fFilter;
      LODWORD(hpfFilterParams.frequency) = v2->LoFi.iBitDepthType;
      v31 = v2->LoFi.iDownSampleIndex;
      hpfFilterParams.peakPercent = v30;
      LOBYTE(hpfFilterParams.slope) = 0;
      HIDWORD(hpfFilterParams.frequency) = v31;
      FutzLoFiImpl::SetParameters(&v3->m_FutzLoFiImpl, (FutzLoFiParameters *)&hpfFilterParams);
    }
  }
}

// File Line: 479
// RVA: 0xB04080
void __fastcall CMcDSPFutzBoxFX::Execute(CMcDSPFutzBoxFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // r12
  char *v3; // r8
  McDSPFutzBoxFXParams *v4; // rdx
  CMcDSPFutzBoxFX *v5; // rsi
  signed __int64 v6; // rax
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  McDSPFutzLoFiFXParams v13; // xmm0
  McDSPGlobalFXParams v14; // xmm1
  __int128 v15; // xmm1
  float v16; // eax
  CMcDSPFutzBoxFXParams *v17; // rax
  unsigned __int16 v18; // bp
  unsigned int v19; // ecx
  __int64 v20; // r15
  unsigned int i; // ebx
  signed __int64 v22; // rdi
  float *v23; // r13
  float v24; // xmm7_4
  float v25; // xmm11_4
  float v26; // xmm9_4
  float v27; // xmm7_4
  float v28; // xmm12_4
  float in_fTargetGain2; // xmm10_4
  float v30; // xmm8_4
  char *v31; // rax
  float v32; // xmm6_4
  __int64 v33; // r14
  float v34; // xmm1_4
  char *v35; // rbx
  float *v36; // rcx
  size_t v37; // r10
  char *v38; // [rsp+40h] [rbp-198h]
  float *in_pfInput2; // [rsp+48h] [rbp-190h]
  char *v40; // [rsp+50h] [rbp-188h]
  char *v41; // [rsp+58h] [rbp-180h]
  char Dst; // [rsp+70h] [rbp-168h]
  char v43; // [rsp+89h] [rbp-14Fh]
  char v44; // [rsp+9Dh] [rbp-13Bh]
  char v45; // [rsp+B1h] [rbp-127h]
  char v46; // [rsp+CDh] [rbp-10Bh]
  char v47; // [rsp+E5h] [rbp-F3h]
  char v48; // [rsp+F1h] [rbp-E7h]
  char v49; // [rsp+101h] [rbp-D7h]
  float in_fTargetGain; // [rsp+104h] [rbp-D4h]
  float v51; // [rsp+108h] [rbp-D0h]
  float v52; // [rsp+10Ch] [rbp-CCh]
  char *memoryBlock; // [rsp+1E0h] [rbp+8h]
  char *v54; // [rsp+1E8h] [rbp+10h]
  char *v55; // [rsp+1F0h] [rbp+18h]
  char *v56; // [rsp+1F8h] [rbp+20h]

  v2 = io_pBuffer;
  v3 = &Dst;
  v4 = &this->m_pSharedParams->m_Params;
  v5 = this;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v4) & 0xF )
  {
    memmove(&Dst, v4, 0xA4ui64);
  }
  else
  {
    v6 = 1i64;
    do
    {
      v7 = *(_OWORD *)&v4->Filters.LPFSlope;
      v8 = *(_OWORD *)&v4->Filters.fHPFFreq;
      v3 += 128;
      v4 = (McDSPFutzBoxFXParams *)((char *)v4 + 128);
      *((_OWORD *)v3 - 8) = v7;
      v9 = *(_OWORD *)&v4[-1].Noise.fLevel;
      *((_OWORD *)v3 - 7) = v8;
      v10 = *(_OWORD *)&v4[-1].Noise.fRange;
      *((_OWORD *)v3 - 6) = v9;
      v11 = *(_OWORD *)&v4[-1].Gate.fRange;
      *((_OWORD *)v3 - 5) = v10;
      v12 = *(_OWORD *)&v4[-1].Gate.bParamsHaveChanged;
      *((_OWORD *)v3 - 4) = v11;
      v13 = v4[-1].LoFi;
      *((_OWORD *)v3 - 3) = v12;
      v14 = v4[-1].Global;
      *((McDSPFutzLoFiFXParams *)v3 - 2) = v13;
      *((McDSPGlobalFXParams *)v3 - 1) = v14;
      --v6;
    }
    while ( v6 );
    v15 = *(_OWORD *)&v4->Filters.fHPFFreq;
    v16 = v4->Distortion.fAmount;
    *(_OWORD *)v3 = *(_OWORD *)&v4->Filters.LPFSlope;
    *((_OWORD *)v3 + 1) = v15;
    *((float *)v3 + 8) = v16;
  }
  CMcDSPFutzBoxFX::PushParamsToMemoryMaps(v5, (McDSPFutzBoxFXParams *)&Dst);
  v17 = v5->m_pSharedParams;
  v17->m_Params.Filters.bParamsHaveChanged = 0;
  v17->m_Params.Distortion.bParamsHaveChanged = 0;
  v17->m_Params.EQ.bParamsHaveChanged = 0;
  v17->m_Params.Noise.bParamsHaveChanged = 0;
  v17->m_Params.Gate.bParamsHaveChanged = 0;
  v17->m_Params.SIM.bParamsHaveChanged = 0;
  v17->m_Params.LoFi.bParamsHaveChanged = 0;
  v17->m_Params.Global.bParamsHaveChanged = 0;
  AkFXTailHandler::HandleTail(&v5->m_State.tailHandler, v2, v5->m_State.uNumTailFrames);
  v18 = v2->uValidFrames;
  if ( v18 )
  {
    v19 = v2->uChannelMask;
    v20 = 0i64;
    for ( i = 0; v19; v19 &= v19 - 1 )
      ++i;
    v22 = 4i64 * v2->uMaxFrames;
    v23 = 0i64;
    in_pfInput2 = (float *)v5->m_pAllocator->vfptr->Malloc(v5->m_pAllocator, 4i64 * v2->uMaxFrames);
    if ( in_pfInput2 )
    {
      if ( !v46 || (v23 = (float *)v5->m_pAllocator->vfptr->Malloc(v5->m_pAllocator, v22)) != 0i64 )
      {
        v24 = v5->m_State.fPrevWetDryMix * 0.0099999998;
        v25 = v52;
        v26 = 1.0 - v24;
        v27 = v24 * v5->m_State.fPrevOutputGain;
        v28 = v51;
        in_fTargetGain2 = 1.0 - (float)(v52 * 0.0099999998);
        v30 = (float)(v52 * 0.0099999998) * v51;
        memoryBlock = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_FiltersPool, 0i64);
        v54 = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_DistortionPool, 0i64);
        v55 = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_EQPool, 0i64);
        v56 = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_NoisePool, 0i64);
        v41 = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_SIMPool, 0i64);
        v40 = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_GatePool, 0i64);
        v31 = PooledMemoryAllocator::GetPointerToPooledMemory(&v5->m_LoFiPool, 0i64);
        v32 = in_fTargetGain;
        v38 = v31;
        if ( i )
        {
          v33 = i;
          do
          {
            v34 = v5->m_State.fPrevInputGain;
            v35 = (char *)v2->pData + 4 * v20 * v2->uMaxFrames;
            v36 = (float *)((char *)v2->pData + 4 * v20 * v2->uMaxFrames);
            if ( v32 == v34 )
              AK::DSP::ApplyGain_12(v36, v34, v18);
            else
              AK::DSP::ApplyGainRamp_5(v36, v34, v32, v18);
            memmove(in_pfInput2, v35, v37);
            if ( v43 )
              memoryBlock = ProcessFutzBoxFiltersWwise(memoryBlock, (float *)v35, (float *)v35, v18);
            if ( v44 )
              v54 = ProcessFutzBoxDistortionWwise(v54, (float *)v35, (float *)v35, v18);
            if ( v45 )
              v55 = ProcessFutzBoxEQFilterWwise(v55, (float *)v35, (float *)v35, v18);
            if ( v46 )
            {
              McDSP::CAkWhiteNoise::GenerateBuffer(&v5->m_State.WhiteNoise, v23, v18);
              v56 = ProcessFutzBoxNoiseGenWwise(v56, (float *)v35, v23, (float *)v35, v18);
            }
            if ( v48 )
              v41 = ProcessFutzBoxSIMWwise(v41, (float *)v35, (float *)v35, v18);
            if ( v47 )
              v40 = ProcessFutzBoxGateWwise(v40, (float *)v35, (float *)v35, v18);
            if ( v49 )
              v38 = ProcessFutzBoxLoFiWwise(v38, (float *)v35, (float *)v35, v18);
            McDSP::Mix2Interp((float *)v35, in_pfInput2, v27, v30, v26, in_fTargetGain2, v18);
            ++v20;
            --v33;
          }
          while ( v33 );
        }
        v5->m_State.fPrevInputGain = v32;
        v5->m_State.fPrevOutputGain = v28;
        v5->m_State.fPrevWetDryMix = v25;
        if ( v23 )
          v5->m_pAllocator->vfptr->Free(v5->m_pAllocator, v23);
      }
      v5->m_pAllocator->vfptr->Free(v5->m_pAllocator, in_pfInput2);
    }
  }
}

