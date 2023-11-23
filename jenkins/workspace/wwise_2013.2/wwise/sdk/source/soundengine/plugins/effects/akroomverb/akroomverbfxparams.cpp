// File Line: 20
// RVA: 0xAE0220
AK::IAkPluginParam *__fastcall CreateRoomVerbFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 200i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkRoomVerbFXParams::`vftable;
  return result;
}

// File Line: 26
// RVA: 0xAE0250
void __fastcall CAkRoomVerbFXParams::CAkRoomVerbFXParams(CAkRoomVerbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkRoomVerbFXParams::`vftable;
}

// File Line: 30
// RVA: 0xAE0270
void __fastcall CAkRoomVerbFXParams::~CAkRoomVerbFXParams(CAkRoomVerbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 35
// RVA: 0xAE0290
void __fastcall CAkRoomVerbFXParams::CAkRoomVerbFXParams(CAkRoomVerbFXParams *this, CAkRoomVerbFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkRoomVerbFXParams::`vftable;
  this->sRTPCParams.fDecayTime = in_rCopy->sRTPCParams.fDecayTime;
  this->sRTPCParams.fHFDamping = in_rCopy->sRTPCParams.fHFDamping;
  this->sRTPCParams.fDiffusion = in_rCopy->sRTPCParams.fDiffusion;
  this->sRTPCParams.fStereoWidth = in_rCopy->sRTPCParams.fStereoWidth;
  this->sRTPCParams.fFilter1Gain = in_rCopy->sRTPCParams.fFilter1Gain;
  this->sRTPCParams.fFilter1Freq = in_rCopy->sRTPCParams.fFilter1Freq;
  this->sRTPCParams.fFilter1Q = in_rCopy->sRTPCParams.fFilter1Q;
  this->sRTPCParams.fFilter2Gain = in_rCopy->sRTPCParams.fFilter2Gain;
  this->sRTPCParams.fFilter2Freq = in_rCopy->sRTPCParams.fFilter2Freq;
  this->sRTPCParams.fFilter2Q = in_rCopy->sRTPCParams.fFilter2Q;
  this->sRTPCParams.fFilter3Gain = in_rCopy->sRTPCParams.fFilter3Gain;
  this->sRTPCParams.fFilter3Freq = in_rCopy->sRTPCParams.fFilter3Freq;
  this->sRTPCParams.fFilter3Q = in_rCopy->sRTPCParams.fFilter3Q;
  this->sRTPCParams.fFrontLevel = in_rCopy->sRTPCParams.fFrontLevel;
  this->sRTPCParams.fRearLevel = in_rCopy->sRTPCParams.fRearLevel;
  this->sRTPCParams.fCenterLevel = in_rCopy->sRTPCParams.fCenterLevel;
  this->sRTPCParams.fLFELevel = in_rCopy->sRTPCParams.fLFELevel;
  this->sRTPCParams.fDryLevel = in_rCopy->sRTPCParams.fDryLevel;
  this->sRTPCParams.fERLevel = in_rCopy->sRTPCParams.fERLevel;
  this->sRTPCParams.fReverbLevel = in_rCopy->sRTPCParams.fReverbLevel;
  *(_DWORD *)&this->sRTPCParams.bDirty = *(_DWORD *)&in_rCopy->sRTPCParams.bDirty;
  this->sRTPCParams.bDirty = 1;
  this->sInvariantParams = in_rCopy->sInvariantParams;
  this->sInvariantParams.bDirty = 1;
  this->sAlgoTunings = in_rCopy->sAlgoTunings;
}

// File Line: 45
// RVA: 0xAE0440
void __fastcall CAkRoomVerbFXParams::Clone(CAkRoomVerbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkRoomVerbFXParams *v3; // rax

  v3 = (CAkRoomVerbFXParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 200i64);
  if ( v3 )
    CAkRoomVerbFXParams::CAkRoomVerbFXParams(v3, this);
}

// File Line: 54
// RVA: 0xAE0480
__int64 __fastcall CAkRoomVerbFXParams::Init(
        CAkRoomVerbFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v5; // xmm8_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float fDensityDelayMin; // eax
  float fDiffusionDelayScalePerc; // ecx
  float fDensityDelayRdmPerc; // eax
  float fRoomShapeMin; // eax
  float fRoomShapeMax; // eax
  float fDiffusionDelayRdmPerc; // ecx
  float fDCFilterCutFreq; // ecx
  float fReverbUnitInputDelay; // ecx
  float fReverbUnitInputDelayRmdPerc; // ecx

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkRoomVerbFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->sRTPCParams.fDecayTime = 1.2;
  this->sRTPCParams.fHFDamping = 2.25;
  this->sRTPCParams.fDiffusion = 100.0;
  *(_QWORD *)&this->sRTPCParams.fStereoWidth = 1127481344i64;
  this->sRTPCParams.fFilter1Freq = 100.0;
  *(_QWORD *)&this->sRTPCParams.fFilter1Q = 1065353216i64;
  this->sRTPCParams.fFilter2Freq = 1000.0;
  *(_QWORD *)&this->sRTPCParams.fFilter2Q = 1065353216i64;
  this->sRTPCParams.fFilter3Freq = 10000.0;
  this->sRTPCParams.fFilter3Q = 1.0;
  v5 = powf(10.0, 0.0);
  this->sRTPCParams.fFrontLevel = v5;
  this->sRTPCParams.fRearLevel = v5;
  this->sRTPCParams.fCenterLevel = v5;
  v6 = powf(10.0, -4.8000002);
  this->sRTPCParams.fDryLevel = v5;
  v7 = v6;
  this->sRTPCParams.fLFELevel = v6;
  this->sRTPCParams.fERLevel = powf(10.0, -1.0);
  v8 = powf(10.0, -1.15);
  fDensityDelayMin = g_AlgoTunings.fDensityDelayMin;
  fDiffusionDelayScalePerc = g_AlgoTunings.fDiffusionDelayScalePerc;
  this->sInvariantParams.fInputLFELevel = v7;
  this->sInvariantParams.fInputCenterLevel = v5;
  this->sRTPCParams.fReverbLevel = v8;
  this->sAlgoTunings.fDensityDelayMin = fDensityDelayMin;
  this->sAlgoTunings.fDensityDelayMax = g_AlgoTunings.fDensityDelayMax;
  fDensityDelayRdmPerc = g_AlgoTunings.fDensityDelayRdmPerc;
  this->sInvariantParams.uERPattern = 23;
  this->sAlgoTunings.fDensityDelayRdmPerc = fDensityDelayRdmPerc;
  fRoomShapeMin = g_AlgoTunings.fRoomShapeMin;
  *(_QWORD *)&this->sInvariantParams.fReverbDelay = 1103626240i64;
  this->sAlgoTunings.fRoomShapeMin = fRoomShapeMin;
  fRoomShapeMax = g_AlgoTunings.fRoomShapeMax;
  this->sInvariantParams.fERFrontBackDelay = 40.0;
  this->sAlgoTunings.fRoomShapeMax = fRoomShapeMax;
  this->sAlgoTunings.fDiffusionDelayScalePerc = fDiffusionDelayScalePerc;
  this->sAlgoTunings.fDiffusionDelayMax = g_AlgoTunings.fDiffusionDelayMax;
  fDiffusionDelayRdmPerc = g_AlgoTunings.fDiffusionDelayRdmPerc;
  *(_WORD *)&this->sInvariantParams.bEnableToneControls = 256;
  this->sAlgoTunings.fDiffusionDelayRdmPerc = fDiffusionDelayRdmPerc;
  fDCFilterCutFreq = g_AlgoTunings.fDCFilterCutFreq;
  this->sInvariantParams.fDensity = 80.0;
  this->sAlgoTunings.fDCFilterCutFreq = fDCFilterCutFreq;
  fReverbUnitInputDelay = g_AlgoTunings.fReverbUnitInputDelay;
  this->sInvariantParams.fRoomShape = 100.0;
  this->sAlgoTunings.fReverbUnitInputDelay = fReverbUnitInputDelay;
  fReverbUnitInputDelayRmdPerc = g_AlgoTunings.fReverbUnitInputDelayRmdPerc;
  this->sInvariantParams.uNumReverbUnits = 8;
  *(_QWORD *)&this->sInvariantParams.eFilter1Pos = 3i64;
  this->sInvariantParams.eFilter2Pos = FILTERINSERTTYPE_ERANDREVERB;
  this->sInvariantParams.eFilter2Curve = FILTERCURVETYPE_PEAKING;
  this->sAlgoTunings.fReverbUnitInputDelayRmdPerc = fReverbUnitInputDelayRmdPerc;
  this->sInvariantParams.eFilter3Pos = FILTERINSERTTYPE_ERANDREVERB;
  this->sInvariantParams.eFilter3Curve = FILTERCURVETYPE_HIGHSHELF;
  this->sRTPCParams.bDirty = 1;
  this->sInvariantParams.bDirty = 1;
  return 1i64;
}

// File Line: 117
// RVA: 0xAE06A0
__int64 __fastcall CAkRoomVerbFXParams::Term(CAkRoomVerbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 126
// RVA: 0xAE06E0
__int64 __fastcall CAkRoomVerbFXParams::SetParamsBlock(
        CAkRoomVerbFXParams *this,
        float *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  char *v3; // rbx

  v3 = (char *)(in_pParamsBlock + 1);
  this->sRTPCParams.fDecayTime = *in_pParamsBlock;
  this->sRTPCParams.fHFDamping = in_pParamsBlock[1];
  this->sRTPCParams.fDiffusion = in_pParamsBlock[2];
  this->sRTPCParams.fStereoWidth = in_pParamsBlock[3];
  this->sRTPCParams.fFilter1Gain = in_pParamsBlock[4];
  this->sRTPCParams.fFilter1Freq = in_pParamsBlock[5];
  this->sRTPCParams.fFilter1Q = in_pParamsBlock[6];
  this->sRTPCParams.fFilter2Gain = in_pParamsBlock[7];
  this->sRTPCParams.fFilter2Freq = in_pParamsBlock[8];
  this->sRTPCParams.fFilter2Q = in_pParamsBlock[9];
  this->sRTPCParams.fFilter3Gain = in_pParamsBlock[10];
  this->sRTPCParams.fFilter3Freq = in_pParamsBlock[11];
  this->sRTPCParams.fFilter3Q = in_pParamsBlock[12];
  this->sRTPCParams.fFrontLevel = powf(10.0, in_pParamsBlock[13] * 0.050000001);
  this->sRTPCParams.fRearLevel = powf(10.0, *((float *)v3 + 13) * 0.050000001);
  this->sRTPCParams.fCenterLevel = powf(10.0, *((float *)v3 + 14) * 0.050000001);
  this->sRTPCParams.fLFELevel = powf(10.0, *((float *)v3 + 15) * 0.050000001);
  this->sRTPCParams.fDryLevel = powf(10.0, *((float *)v3 + 16) * 0.050000001);
  this->sRTPCParams.fERLevel = powf(10.0, *((float *)v3 + 17) * 0.050000001);
  this->sRTPCParams.fReverbLevel = powf(10.0, (float)(*((float *)v3 + 18) - 3.0) * 0.050000001);
  this->sInvariantParams.bEnableEarlyReflections = v3[76];
  this->sInvariantParams.uERPattern = *(_DWORD *)(v3 + 77);
  this->sInvariantParams.fReverbDelay = *(float *)(v3 + 81);
  this->sInvariantParams.fRoomSize = *(float *)(v3 + 85);
  this->sInvariantParams.fERFrontBackDelay = *(float *)(v3 + 89);
  this->sInvariantParams.fDensity = *(float *)(v3 + 93);
  this->sInvariantParams.fRoomShape = *(float *)(v3 + 97);
  this->sInvariantParams.uNumReverbUnits = *(_DWORD *)(v3 + 101);
  this->sInvariantParams.bEnableToneControls = v3[105];
  this->sInvariantParams.eFilter1Pos = *(_DWORD *)(v3 + 106);
  this->sInvariantParams.eFilter1Curve = *(_DWORD *)(v3 + 110);
  this->sInvariantParams.eFilter2Pos = *(_DWORD *)(v3 + 114);
  this->sInvariantParams.eFilter2Curve = *(_DWORD *)(v3 + 118);
  this->sInvariantParams.eFilter3Pos = *(_DWORD *)(v3 + 122);
  this->sInvariantParams.eFilter3Curve = *(_DWORD *)(v3 + 126);
  this->sInvariantParams.fInputCenterLevel = powf(10.0, *(float *)(v3 + 130) * 0.050000001);
  this->sInvariantParams.fInputLFELevel = powf(10.0, *(float *)(v3 + 134) * 0.050000001);
  this->sAlgoTunings = *(AlgorithmTunings *)(v3 + 138);
  this->sRTPCParams.bDirty = 1;
  this->sInvariantParams.bDirty = 1;
  return 1i64;
}

// File Line: 201
// RVA: 0xAE09C0
__int64 __fastcall CAkRoomVerbFXParams::SetParam(
        CAkRoomVerbFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
  float v6; // eax
  float v7; // eax
  float v8; // eax
  float v9; // eax
  float v10; // eax
  float v11; // eax
  float v12; // eax
  float v13; // eax
  float v14; // eax
  float v15; // eax
  float v16; // eax
  float v17; // eax
  float v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  bool v26; // zf
  float v27; // eax
  float v28; // eax
  float v29; // eax
  float v30; // eax
  float v31; // eax
  float v32; // eax
  unsigned int v33; // eax
  float v34; // xmm0_4
  float v35; // xmm0_4
  FilterInsertType v36; // eax
  FilterCurveType v37; // eax
  FilterInsertType v38; // eax
  FilterCurveType v39; // eax
  FilterInsertType v40; // eax
  FilterCurveType v41; // eax

  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      v27 = *in_pValue;
      this->sInvariantParams.bDirty = 1;
      *(float *)&this->sInvariantParams.uERPattern = v27;
      result = 1i64;
      break;
    case 1:
      v28 = *in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.fReverbDelay = v28;
      result = 1i64;
      break;
    case 2:
      v29 = *in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.fRoomSize = v29;
      result = 1i64;
      break;
    case 3:
      v30 = *in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.fERFrontBackDelay = v30;
      result = 1i64;
      break;
    case 4:
      v26 = *(_BYTE *)in_pValue == 0;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.bEnableEarlyReflections = !v26;
      result = 1i64;
      break;
    case 10:
      v6 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fDecayTime = v6;
      result = 1i64;
      break;
    case 11:
      v7 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fHFDamping = v7;
      result = 1i64;
      break;
    case 12:
      v31 = *in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.fDensity = v31;
      result = 1i64;
      break;
    case 13:
      v32 = *in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.fRoomShape = v32;
      result = 1i64;
      break;
    case 14:
      v33 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.uNumReverbUnits = v33;
      result = 1i64;
      break;
    case 15:
      v8 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fDiffusion = v8;
      result = 1i64;
      break;
    case 16:
      v9 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fStereoWidth = v9;
      result = 1i64;
      break;
    case 20:
      v26 = *(_BYTE *)in_pValue == 0;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.bEnableToneControls = !v26;
      result = 1i64;
      break;
    case 21:
      v36 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.eFilter1Pos = v36;
      result = 1i64;
      break;
    case 22:
      v37 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.eFilter1Curve = v37;
      result = 1i64;
      break;
    case 23:
      v10 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter1Gain = v10;
      result = 1i64;
      break;
    case 24:
      v11 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter1Freq = v11;
      result = 1i64;
      break;
    case 25:
      v12 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter1Q = v12;
      result = 1i64;
      break;
    case 26:
      v38 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.eFilter2Pos = v38;
      result = 1i64;
      break;
    case 27:
      v39 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.eFilter2Curve = v39;
      result = 1i64;
      break;
    case 28:
      v13 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter2Gain = v13;
      result = 1i64;
      break;
    case 29:
      v14 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter2Freq = v14;
      result = 1i64;
      break;
    case 30:
      v15 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter2Q = v15;
      result = 1i64;
      break;
    case 31:
      v40 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.eFilter3Pos = v40;
      result = 1i64;
      break;
    case 32:
      v41 = *(_DWORD *)in_pValue;
      this->sInvariantParams.bDirty = 1;
      this->sInvariantParams.eFilter3Curve = v41;
      result = 1i64;
      break;
    case 33:
      v16 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter3Gain = v16;
      result = 1i64;
      break;
    case 34:
      v17 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter3Freq = v17;
      result = 1i64;
      break;
    case 35:
      v18 = *in_pValue;
      this->sRTPCParams.bDirty = 1;
      this->sRTPCParams.fFilter3Q = v18;
      result = 1i64;
      break;
    case 40:
      v34 = powf(10.0, *in_pValue * 0.050000001);
      this->sInvariantParams.bDirty = 1;
      result = 1i64;
      this->sInvariantParams.fInputCenterLevel = v34;
      break;
    case 41:
      v35 = powf(10.0, *in_pValue * 0.050000001);
      this->sInvariantParams.bDirty = 1;
      result = 1i64;
      this->sInvariantParams.fInputLFELevel = v35;
      break;
    case 50:
      v19 = powf(10.0, *in_pValue * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fFrontLevel = v19;
      break;
    case 51:
      v20 = powf(10.0, *in_pValue * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fRearLevel = v20;
      break;
    case 52:
      v21 = powf(10.0, *in_pValue * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fCenterLevel = v21;
      break;
    case 53:
      v22 = powf(10.0, *in_pValue * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fLFELevel = v22;
      break;
    case 60:
      v23 = powf(10.0, *in_pValue * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fDryLevel = v23;
      break;
    case 61:
      v24 = powf(10.0, *in_pValue * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fERLevel = v24;
      break;
    case 62:
      v25 = powf(10.0, (float)(*in_pValue - 3.0) * 0.050000001);
      this->sRTPCParams.bDirty = 1;
      result = 1i64;
      this->sRTPCParams.fReverbLevel = v25;
      break;
    case 100:
      this->sAlgoTunings.fDensityDelayMin = *in_pValue;
      result = 1i64;
      break;
    case 101:
      this->sAlgoTunings.fDensityDelayMax = *in_pValue;
      result = 1i64;
      break;
    case 102:
      this->sAlgoTunings.fDensityDelayRdmPerc = *in_pValue;
      result = 1i64;
      break;
    case 103:
      this->sAlgoTunings.fRoomShapeMin = *in_pValue;
      result = 1i64;
      break;
    case 104:
      this->sAlgoTunings.fRoomShapeMax = *in_pValue;
      result = 1i64;
      break;
    case 105:
      this->sAlgoTunings.fDiffusionDelayScalePerc = *in_pValue;
      result = 1i64;
      break;
    case 106:
      this->sAlgoTunings.fDiffusionDelayMax = *in_pValue;
      result = 1i64;
      break;
    case 107:
      this->sAlgoTunings.fDiffusionDelayRdmPerc = *in_pValue;
      result = 1i64;
      break;
    case 108:
      this->sAlgoTunings.fDCFilterCutFreq = *in_pValue;
      result = 1i64;
      break;
    case 109:
      this->sAlgoTunings.fReverbUnitInputDelay = *in_pValue;
      result = 1i64;
      break;
    case 110:
      this->sAlgoTunings.fReverbUnitInputDelayRmdPerc = *in_pValue;
      goto LABEL_52;
    default:
LABEL_52:
      result = 1i64;
      break;
  }
  return result;
}

