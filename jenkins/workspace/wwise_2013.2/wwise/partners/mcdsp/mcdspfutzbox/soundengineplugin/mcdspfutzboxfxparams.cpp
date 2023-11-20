// File Line: 16
// RVA: 0xB03A10
AK::IAkPluginParam *__fastcall CreateMcDSPFutzBoxFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 176ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPFutzBoxFXParams::`vftable';
  return result;
}

// File Line: 22
// RVA: 0xB02FC0
void __fastcall CMcDSPFutzBoxFXParams::CMcDSPFutzBoxFXParams(CMcDSPFutzBoxFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPFutzBoxFXParams::`vftable';
}

// File Line: 27
// RVA: 0xB030C0
void __fastcall CMcDSPFutzBoxFXParams::~CMcDSPFutzBoxFXParams(CMcDSPFutzBoxFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 32
// RVA: 0xB02FE0
void __fastcall CMcDSPFutzBoxFXParams::CMcDSPFutzBoxFXParams(CMcDSPFutzBoxFXParams *this, CMcDSPFutzBoxFXParams *in_rCopy)
{
  McDSPFutzBoxFXParams *v2; // rdx
  CMcDSPFutzBoxFXParams *v3; // rbx
  McDSPFutzBoxFXParams *v4; // rcx
  signed __int64 v5; // rax
  __int128 v6; // xmm0

  v2 = &in_rCopy->m_Params;
  v3 = this;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPFutzBoxFXParams::`vftable';
  v4 = &this->m_Params;
  if ( ((unsigned __int8)v4 | (unsigned __int8)v2) & 0xF )
  {
    memmove(v4, v2, 0xA4ui64);
  }
  else
  {
    v5 = 1i64;
    do
    {
      v6 = *(_OWORD *)&v2->Filters.LPFSlope;
      v4 = (McDSPFutzBoxFXParams *)((char *)v4 + 128);
      v2 = (McDSPFutzBoxFXParams *)((char *)v2 + 128);
      *(_OWORD *)&v4[-1].Distortion.fIntensity = v6;
      *(_OWORD *)&v4[-1].EQ.fFreq = *(_OWORD *)&v2[-1].EQ.fFreq;
      *(_OWORD *)&v4[-1].Noise.fLevel = *(_OWORD *)&v2[-1].Noise.fLevel;
      *(_OWORD *)&v4[-1].Noise.fRange = *(_OWORD *)&v2[-1].Noise.fRange;
      *(_OWORD *)&v4[-1].Gate.fRange = *(_OWORD *)&v2[-1].Gate.fRange;
      *(_OWORD *)&v4[-1].Gate.bParamsHaveChanged = *(_OWORD *)&v2[-1].Gate.bParamsHaveChanged;
      v4[-1].LoFi = v2[-1].LoFi;
      v4[-1].Global = v2[-1].Global;
      --v5;
    }
    while ( v5 );
    *(_OWORD *)&v4->Filters.LPFSlope = *(_OWORD *)&v2->Filters.LPFSlope;
    *(_OWORD *)&v4->Filters.fHPFFreq = *(_OWORD *)&v2->Filters.fHPFFreq;
    v4->Distortion.fAmount = v2->Distortion.fAmount;
  }
  v3->m_Params.Filters.bParamsHaveChanged = 1;
  v3->m_Params.Distortion.bParamsHaveChanged = 1;
  v3->m_Params.EQ.bParamsHaveChanged = 1;
  v3->m_Params.Noise.bParamsHaveChanged = 1;
  v3->m_Params.Gate.bParamsHaveChanged = 1;
  v3->m_Params.SIM.bParamsHaveChanged = 1;
  v3->m_Params.LoFi.bParamsHaveChanged = 1;
}

// File Line: 48
// RVA: 0xB030E0
void __fastcall CMcDSPFutzBoxFXParams::Clone(CMcDSPFutzBoxFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CMcDSPFutzBoxFXParams *v2; // rbx
  CMcDSPFutzBoxFXParams *v3; // rax

  v2 = this;
  v3 = (CMcDSPFutzBoxFXParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 176ui64);
  if ( v3 )
    CMcDSPFutzBoxFXParams::CMcDSPFutzBoxFXParams(v3, v2);
}

// File Line: 56
// RVA: 0xB03120
__int64 __fastcall CMcDSPFutzBoxFXParams::Init(CMcDSPFutzBoxFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CMcDSPFutzBoxFXParams *v4; // rbx
  float v5; // xmm0_4
  __int64 result; // rax

  v4 = this;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CMcDSPFutzBoxFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  *(_QWORD *)&this->m_Params.Filters.fLPFFreq = 1183621120i64;
  *(_QWORD *)&this->m_Params.Filters.fHPFFreq = 1109393408i64;
  this->m_Params.EQ.FilterType = 1;
  this->m_Params.Filters.LPFSlope = 0;
  this->m_Params.Filters.HPFSlope = 0;
  *(_QWORD *)&this->m_Params.Distortion.iMode = 0i64;
  *(_QWORD *)&this->m_Params.Distortion.fIntensity = 0i64;
  *(_QWORD *)&this->m_Params.EQ.fFreq = 1148846080i64;
  this->m_Params.EQ.fGain = -96.0;
  this->m_Params.Noise.fLevel = -96.0;
  this->m_Params.Noise.fLPFFreq = 18000.0;
  *(_QWORD *)&this->m_Params.Noise.fHPFFreq = 1109393408i64;
  this->m_Params.Noise.fRange = -20.0;
  this->m_Params.Noise.fRecovery = 20.0;
  this->m_Params.Gate.fThreshold = -40.0;
  this->m_Params.Gate.fRange = 0.0;
  this->m_Params.Gate.fAttack = 1.0;
  this->m_Params.Gate.fHold = 10.0;
  this->m_Params.Gate.fRelease = 100.0;
  this->m_Params.SIM.iType = 0;
  this->m_Params.SIM.fTuning = 100.0;
  *(_QWORD *)&this->m_Params.LoFi.iBitDepthType = 0i64;
  this->m_Params.LoFi.fFilter = 0.0;
  v5 = powf(10.0, 0.0);
  v4->m_Params.Global.fBalance = 100.0;
  result = 1i64;
  v4->m_Params.Global.fInputGain = v5;
  v4->m_Params.Global.fOutputGain = v5;
  v4->m_Params.Filters.bParamsHaveChanged = 1;
  v4->m_Params.Distortion.bParamsHaveChanged = 1;
  v4->m_Params.EQ.bParamsHaveChanged = 1;
  v4->m_Params.Noise.bParamsHaveChanged = 1;
  v4->m_Params.Gate.bParamsHaveChanged = 1;
  v4->m_Params.SIM.bParamsHaveChanged = 1;
  v4->m_Params.LoFi.bParamsHaveChanged = 1;
  v4->m_Params.Global.bParamsHaveChanged = 1;
  return result;
}

// File Line: 114
// RVA: 0xB03250
signed __int64 __fastcall CMcDSPFutzBoxFXParams::Term(CMcDSPFutzBoxFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CMcDSPFutzBoxFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 122
// RVA: 0xB03290
signed __int64 __fastcall CMcDSPFutzBoxFXParams::SetParamsBlock(CMcDSPFutzBoxFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CMcDSPFutzBoxFXParams *v4; // rdi

  v3 = (char *)in_pParamsBlock + 1;
  v4 = this;
  this->m_Params.Filters.bEnable = *(_BYTE *)in_pParamsBlock;
  this->m_Params.Filters.LPFSlope = *(_DWORD *)((char *)in_pParamsBlock + 1);
  this->m_Params.Filters.fLPFFreq = *(float *)((char *)in_pParamsBlock + 5);
  this->m_Params.Filters.fLPFQ = *(float *)((char *)in_pParamsBlock + 9);
  this->m_Params.Filters.HPFSlope = *(_DWORD *)((char *)in_pParamsBlock + 13);
  this->m_Params.Filters.fHPFFreq = *(float *)((char *)in_pParamsBlock + 17);
  this->m_Params.Filters.fHPFQ = *(float *)((char *)in_pParamsBlock + 21);
  this->m_Params.Distortion.bEnable = *((_BYTE *)in_pParamsBlock + 25);
  this->m_Params.Distortion.iMode = *(_DWORD *)((char *)in_pParamsBlock + 26);
  this->m_Params.Distortion.fAmount = *(float *)((char *)in_pParamsBlock + 30);
  this->m_Params.Distortion.fIntensity = *(float *)((char *)in_pParamsBlock + 34);
  this->m_Params.Distortion.fRectify = *(float *)((char *)in_pParamsBlock + 38);
  this->m_Params.EQ.bEnable = *((_BYTE *)in_pParamsBlock + 42);
  this->m_Params.EQ.FilterType = *(_DWORD *)((char *)in_pParamsBlock + 43);
  this->m_Params.EQ.fFreq = *(float *)((char *)in_pParamsBlock + 47);
  this->m_Params.EQ.fQ = *(float *)((char *)in_pParamsBlock + 51);
  this->m_Params.EQ.fGain = *(float *)((char *)in_pParamsBlock + 55);
  this->m_Params.Noise.bEnable = *((_BYTE *)in_pParamsBlock + 59);
  this->m_Params.Noise.fLevel = *((float *)in_pParamsBlock + 15);
  this->m_Params.Noise.fLPFFreq = *((float *)in_pParamsBlock + 16);
  this->m_Params.Noise.fHPFFreq = *((float *)in_pParamsBlock + 17);
  this->m_Params.Noise.fThresh = *((float *)in_pParamsBlock + 18);
  this->m_Params.Noise.fRange = *((float *)in_pParamsBlock + 19);
  this->m_Params.Noise.fRecovery = *((float *)in_pParamsBlock + 20);
  this->m_Params.SIM.bEnable = *((_BYTE *)in_pParamsBlock + 84);
  this->m_Params.SIM.iType = *(_DWORD *)((char *)in_pParamsBlock + 85);
  this->m_Params.SIM.fTuning = *(float *)((char *)in_pParamsBlock + 89);
  this->m_Params.Gate.bEnable = *((_BYTE *)in_pParamsBlock + 93);
  this->m_Params.Gate.fThreshold = *(float *)((char *)in_pParamsBlock + 94);
  this->m_Params.Gate.fRange = *(float *)((char *)in_pParamsBlock + 98);
  this->m_Params.Gate.fAttack = *(float *)((char *)in_pParamsBlock + 102);
  this->m_Params.Gate.fHold = *(float *)((char *)in_pParamsBlock + 106);
  this->m_Params.Gate.fRelease = *(float *)((char *)in_pParamsBlock + 110);
  this->m_Params.LoFi.bEnable = *((_BYTE *)in_pParamsBlock + 114);
  this->m_Params.LoFi.iBitDepthType = *(_DWORD *)((char *)in_pParamsBlock + 115);
  this->m_Params.LoFi.iDownSampleIndex = *(_DWORD *)((char *)in_pParamsBlock + 119);
  this->m_Params.LoFi.fFilter = *(float *)((char *)in_pParamsBlock + 123);
  this->m_Params.Global.fInputGain = powf(10.0, *(float *)((char *)in_pParamsBlock + 127) * 0.050000001);
  v4->m_Params.Global.fOutputGain = powf(10.0, *(float *)(v3 + 130) * 0.050000001);
  v4->m_Params.Global.fBalance = *(float *)(v3 + 134);
  v4->m_Params.Filters.bParamsHaveChanged = 1;
  v4->m_Params.Distortion.bParamsHaveChanged = 1;
  v4->m_Params.EQ.bParamsHaveChanged = 1;
  v4->m_Params.Noise.bParamsHaveChanged = 1;
  v4->m_Params.Gate.bParamsHaveChanged = 1;
  v4->m_Params.SIM.bParamsHaveChanged = 1;
  v4->m_Params.LoFi.bParamsHaveChanged = 1;
  v4->m_Params.Global.bParamsHaveChanged = 1;
  return 1i64;
}

// File Line: 196
// RVA: 0xB03490
signed __int64 __fastcall CMcDSPFutzBoxFXParams::SetParam(CMcDSPFutzBoxFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CMcDSPFutzBoxFXParams *v4; // rbx
  signed __int64 result; // rax
  bool v6; // zf
  FutzFilterSlope v7; // eax
  float v8; // eax
  float v9; // eax
  FutzFilterSlope v10; // eax
  float v11; // eax
  float v12; // eax
  FutzDistortionMode v13; // eax
  float v14; // eax
  float v15; // eax
  float v16; // eax
  FutzEQType v17; // eax
  float v18; // eax
  float v19; // eax
  float v20; // eax
  float v21; // eax
  float v22; // eax
  float v23; // eax
  float v24; // eax
  float v25; // eax
  float v26; // eax
  FutzSIMType v27; // eax
  float v28; // eax
  float v29; // eax
  float v30; // eax
  float v31; // eax
  float v32; // eax
  float v33; // eax
  FutzBitDepthType v34; // eax
  int v35; // eax
  float v36; // eax
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // eax

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.Distortion.bParamsHaveChanged = 1;
      this->m_Params.Distortion.bEnable = !v6;
      result = 1i64;
      break;
    case 1:
      v13 = *(_DWORD *)in_pValue;
      this->m_Params.Distortion.bParamsHaveChanged = 1;
      this->m_Params.Distortion.iMode = v13;
      result = 1i64;
      break;
    case 2:
      v14 = *(float *)in_pValue;
      this->m_Params.Distortion.bParamsHaveChanged = 1;
      this->m_Params.Distortion.fAmount = v14;
      result = 1i64;
      break;
    case 3:
      v15 = *(float *)in_pValue;
      this->m_Params.Distortion.bParamsHaveChanged = 1;
      this->m_Params.Distortion.fIntensity = v15;
      result = 1i64;
      break;
    case 4:
      v16 = *(float *)in_pValue;
      this->m_Params.Distortion.bParamsHaveChanged = 1;
      this->m_Params.Distortion.fRectify = v16;
      result = 1i64;
      break;
    case 10:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.Gate.bParamsHaveChanged = 1;
      this->m_Params.Gate.bEnable = !v6;
      result = 1i64;
      break;
    case 11:
      v29 = *(float *)in_pValue;
      this->m_Params.Gate.bParamsHaveChanged = 1;
      this->m_Params.Gate.fThreshold = v29;
      result = 1i64;
      break;
    case 12:
      v30 = *(float *)in_pValue;
      this->m_Params.Gate.bParamsHaveChanged = 1;
      this->m_Params.Gate.fRange = v30;
      result = 1i64;
      break;
    case 13:
      v31 = *(float *)in_pValue;
      this->m_Params.Gate.bParamsHaveChanged = 1;
      this->m_Params.Gate.fAttack = v31;
      result = 1i64;
      break;
    case 14:
      v32 = *(float *)in_pValue;
      this->m_Params.Gate.bParamsHaveChanged = 1;
      this->m_Params.Gate.fHold = v32;
      result = 1i64;
      break;
    case 15:
      v33 = *(float *)in_pValue;
      this->m_Params.Gate.bParamsHaveChanged = 1;
      this->m_Params.Gate.fRelease = v33;
      result = 1i64;
      break;
    case 20:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.SIM.bParamsHaveChanged = 1;
      this->m_Params.SIM.bEnable = !v6;
      result = 1i64;
      break;
    case 21:
      v27 = *(_DWORD *)in_pValue;
      this->m_Params.SIM.bParamsHaveChanged = 1;
      this->m_Params.SIM.iType = v27;
      result = 1i64;
      break;
    case 22:
      v28 = *(float *)in_pValue;
      this->m_Params.SIM.bParamsHaveChanged = 1;
      this->m_Params.SIM.fTuning = v28;
      result = 1i64;
      break;
    case 30:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.LoFi.bParamsHaveChanged = 1;
      this->m_Params.LoFi.bEnable = !v6;
      result = 1i64;
      break;
    case 31:
      v34 = (signed int)*(float *)in_pValue;
      this->m_Params.LoFi.bParamsHaveChanged = 1;
      this->m_Params.LoFi.iBitDepthType = v34;
      result = 1i64;
      break;
    case 32:
      v35 = (signed int)*(float *)in_pValue;
      this->m_Params.LoFi.bParamsHaveChanged = 1;
      this->m_Params.LoFi.iDownSampleIndex = v35;
      result = 1i64;
      break;
    case 33:
      v36 = *(float *)in_pValue;
      this->m_Params.LoFi.bParamsHaveChanged = 1;
      this->m_Params.LoFi.fFilter = v36;
      result = 1i64;
      break;
    case 40:
      v37 = powf(10.0, *(float *)in_pValue * 0.050000001);
      v4->m_Params.Global.bParamsHaveChanged = 1;
      result = 1i64;
      v4->m_Params.Global.fInputGain = v37;
      break;
    case 41:
      v38 = powf(10.0, *(float *)in_pValue * 0.050000001);
      v4->m_Params.Global.bParamsHaveChanged = 1;
      result = 1i64;
      v4->m_Params.Global.fOutputGain = v38;
      break;
    case 42:
      v39 = *(float *)in_pValue;
      this->m_Params.Global.bParamsHaveChanged = 1;
      this->m_Params.Global.fBalance = v39;
      result = 1i64;
      break;
    case 50:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.bEnable = !v6;
      result = 1i64;
      break;
    case 51:
      v7 = *(_DWORD *)in_pValue;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.LPFSlope = v7;
      result = 1i64;
      break;
    case 52:
      v8 = *(float *)in_pValue;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.fLPFFreq = v8;
      result = 1i64;
      break;
    case 53:
      v9 = *(float *)in_pValue;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.fLPFQ = v9;
      result = 1i64;
      break;
    case 54:
      v10 = *(_DWORD *)in_pValue;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.HPFSlope = v10;
      result = 1i64;
      break;
    case 55:
      v11 = *(float *)in_pValue;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.fHPFFreq = v11;
      result = 1i64;
      break;
    case 56:
      v12 = *(float *)in_pValue;
      this->m_Params.Filters.bParamsHaveChanged = 1;
      this->m_Params.Filters.fHPFQ = v12;
      result = 1i64;
      break;
    case 60:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.EQ.bParamsHaveChanged = 1;
      this->m_Params.EQ.bEnable = !v6;
      result = 1i64;
      break;
    case 61:
      v17 = *(_DWORD *)in_pValue;
      this->m_Params.EQ.bParamsHaveChanged = 1;
      this->m_Params.EQ.FilterType = v17;
      result = 1i64;
      break;
    case 62:
      v18 = *(float *)in_pValue;
      this->m_Params.EQ.bParamsHaveChanged = 1;
      this->m_Params.EQ.fFreq = v18;
      result = 1i64;
      break;
    case 63:
      v19 = *(float *)in_pValue;
      this->m_Params.EQ.bParamsHaveChanged = 1;
      this->m_Params.EQ.fQ = v19;
      result = 1i64;
      break;
    case 64:
      v20 = *(float *)in_pValue;
      this->m_Params.EQ.bParamsHaveChanged = 1;
      this->m_Params.EQ.fGain = v20;
      result = 1i64;
      break;
    case 70:
      v6 = *(_BYTE *)in_pValue == 0;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.bEnable = !v6;
      result = 1i64;
      break;
    case 71:
      v21 = *(float *)in_pValue;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.fLevel = v21;
      result = 1i64;
      break;
    case 72:
      v22 = *(float *)in_pValue;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.fLPFFreq = v22;
      result = 1i64;
      break;
    case 73:
      v23 = *(float *)in_pValue;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.fHPFFreq = v23;
      result = 1i64;
      break;
    case 74:
      v24 = *(float *)in_pValue;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.fThresh = v24;
      result = 1i64;
      break;
    case 75:
      v25 = *(float *)in_pValue;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.fRange = v25;
      result = 1i64;
      break;
    case 76:
      v26 = *(float *)in_pValue;
      this->m_Params.Noise.bParamsHaveChanged = 1;
      this->m_Params.Noise.fRecovery = v26;
      result = 1i64;
      break;
    default:
      result = 31i64;
      break;
  }
  return result;
}   result = 1i64;
      bre

