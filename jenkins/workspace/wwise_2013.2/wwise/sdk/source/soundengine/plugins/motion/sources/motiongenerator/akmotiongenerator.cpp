// File Line: 39
// RVA: 0xACDFB0
AK::IAkPluginParam *__fastcall AkCreateMotionGeneratorParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v1; // rbx
  AK::IAkPluginParam *result; // rax

  v1 = in_pAllocator;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 128ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMotionGeneratorParams::`vftable;
  result[6].vfptr = 0i64;
  result[7].vfptr = 0i64;
  result[8].vfptr = 0i64;
  result[9].vfptr = 0i64;
  result[10].vfptr = 0i64;
  result[11].vfptr = 0i64;
  result[12].vfptr = 0i64;
  result[13].vfptr = 0i64;
  result[15].vfptr = (AK::IAkRTPCSubscriberVtbl *)v1;
  return result;
}

// File Line: 51
// RVA: 0xACDD90
void __fastcall CAkMotionGeneratorParams::CAkMotionGeneratorParams(CAkMotionGeneratorParams *this, CAkMotionGeneratorParams *Copy)
{
  signed int v2; // ebx
  CAkMotionGeneratorParams *v3; // rdi
  unsigned __int16 v4; // ax
  AkCurve *v5; // rsi

  v2 = 0;
  v3 = this;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMotionGeneratorParams::`vftable;
  this->m_Params.m_Curves[0].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Params.m_Curves[0].m_ulArraySize = 0i64;
  this->m_Params.m_Curves[1].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Params.m_Curves[1].m_ulArraySize = 0i64;
  this->m_Params.m_Curves[2].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Params.m_Curves[2].m_ulArraySize = 0i64;
  this->m_Params.m_Curves[3].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Params.m_Curves[3].m_ulArraySize = 0i64;
  this->m_pAllocator = Copy->m_pAllocator;
  this->m_Params.m_fPeriod = Copy->m_Params.m_fPeriod;
  this->m_Params.m_fPeriodMultiplier = Copy->m_Params.m_fPeriodMultiplier;
  this->m_Params.m_fDuration = Copy->m_Params.m_fDuration;
  this->m_Params.m_fAttackTime = Copy->m_Params.m_fAttackTime;
  this->m_Params.m_fDecayTime = Copy->m_Params.m_fDecayTime;
  this->m_Params.m_fSustainTime = Copy->m_Params.m_fSustainTime;
  this->m_Params.m_fSustainLevel = Copy->m_Params.m_fSustainLevel;
  this->m_Params.m_fReleaseTime = Copy->m_Params.m_fReleaseTime;
  this->m_Params.m_eDurationType = Copy->m_Params.m_eDurationType;
  v4 = Copy->m_Params.m_uCurves;
  this->m_Params.m_uCurves = v4;
  if ( v4 > 0u )
  {
    v5 = Copy->m_Params.m_Curves;
    do
    {
      CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
        (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)v3 + v2++ + 3i64,
        v5->m_pArrayGraphPoints,
        v5->m_ulArraySize,
        0);
      ++v5;
    }
    while ( v2 < v3->m_Params.m_uCurves );
  }
}

// File Line: 77
// RVA: 0xACDE60
void __fastcall CAkMotionGeneratorParams::~CAkMotionGeneratorParams(CAkMotionGeneratorParams *this)
{
  CAkMotionGeneratorParams *v1; // rsi
  signed int v2; // edi
  AkCurve *v3; // rbx
  signed __int64 v4; // rbx
  signed __int64 v5; // rdi

  v1 = this;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMotionGeneratorParams::`vftable;
  v2 = 0;
  if ( this->m_Params.m_uCurves > 0u )
  {
    v3 = this->m_Params.m_Curves;
    do
    {
      if ( v3->m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3->m_pArrayGraphPoints);
        v3->m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&v3->m_ulArraySize = 0i64;
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_Params.m_uCurves );
  }
  v4 = (signed __int64)v1->m_Params.m_Curves;
  v5 = 4i64;
  do
  {
    if ( *(_QWORD *)v4 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, *(void **)v4);
      *(_QWORD *)v4 = 0i64;
    }
    *(_QWORD *)(v4 + 8) = 0i64;
    v4 += 16i64;
    --v5;
  }
  while ( v5 );
  v1->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 84
// RVA: 0xACE010
void __fastcall CAkMotionGeneratorParams::Clone(CAkMotionGeneratorParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkMotionGeneratorParams *v2; // rbx
  CAkMotionGeneratorParams *v3; // rax

  v2 = this;
  v3 = (CAkMotionGeneratorParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 128ui64);
  if ( v3 )
    CAkMotionGeneratorParams::CAkMotionGeneratorParams(v3, v2);
}

// File Line: 93
// RVA: 0xACE400
__int64 __fastcall CAkMotionGeneratorParams::Init(CAkMotionGeneratorParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pvParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    result = ((__int64 (__fastcall *)(CAkMotionGeneratorParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
               this,
               in_pvParamsBlock,
               in_ulBlockSize);
  else
    result = 1i64;
  return result;
}

// File Line: 111
// RVA: 0xACE820
signed __int64 __fastcall CAkMotionGeneratorParams::SetParamsBlock(CAkMotionGeneratorParams *this, const void *in_pvParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CAkMotionGeneratorParams *v4; // rdi
  float v5; // xmm0_4
  void *io_ppData; // [rsp+38h] [rbp+10h]

  v3 = (char *)in_pvParamsBlock;
  v4 = this;
  if ( !in_pvParamsBlock || in_ulBlockSize < 0x22 )
    return 31i64;
  *(_QWORD *)&this->m_Params.m_fPeriod = *(_QWORD *)in_pvParamsBlock;
  *(_QWORD *)&this->m_Params.m_fDuration = *((_QWORD *)in_pvParamsBlock + 1);
  *(_QWORD *)&this->m_Params.m_fDecayTime = *((_QWORD *)in_pvParamsBlock + 2);
  *(_QWORD *)&this->m_Params.m_fReleaseTime = *((_QWORD *)in_pvParamsBlock + 3);
  this->m_Params.m_eDurationType = *((_WORD *)in_pvParamsBlock + 16);
  v5 = powf(10.0, this->m_Params.m_fSustainLevel * 0.050000001);
  io_ppData = v3 + 34;
  v4->m_Params.m_fSustainLevel = v5;
  return CAkMotionGeneratorParams::ReadAllCurves(v4, (const void **)&io_ppData);
}

// File Line: 136
// RVA: 0xACE6C0
signed __int64 __fastcall CAkMotionGeneratorParams::SetParam(CAkMotionGeneratorParams *this, __int16 in_ParamID, const void *in_pvValue, unsigned int in_ulParamSize)
{
  CAkMotionGeneratorParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // xmm0_4
  void *io_ppData; // [rsp+40h] [rbp+18h]

  io_ppData = (void *)in_pvValue;
  v4 = this;
  if ( !in_pvValue )
    return 31i64;
  if ( in_ParamID <= 13 )
  {
    switch ( in_ParamID )
    {
      case 13:
        this->m_Params.m_fDecayTime = *(float *)in_pvValue;
        return 1i64;
      case 0:
        this->m_Params.m_fPeriod = *(float *)in_pvValue;
        return 1i64;
      case 1:
        this->m_Params.m_fPeriodMultiplier = *(float *)in_pvValue;
        return 1i64;
      case 2:
        this->m_Params.m_eDurationType = *(_WORD *)in_pvValue;
        return 1i64;
      case 3:
        this->m_Params.m_fDuration = *(float *)in_pvValue;
        return 1i64;
      case 12:
        this->m_Params.m_fAttackTime = *(float *)in_pvValue;
        return 1i64;
    }
    return 31i64;
  }
  switch ( in_ParamID )
  {
    case 0xE:
      this->m_Params.m_fSustainTime = *(float *)in_pvValue;
      result = 1i64;
      break;
    case 0xF:
      v6 = powf(10.0, *(float *)in_pvValue * 0.050000001);
      result = 1i64;
      v4->m_Params.m_fSustainLevel = v6;
      break;
    case 0x10:
      this->m_Params.m_fReleaseTime = *(float *)in_pvValue;
      result = 1i64;
      break;
    case 0x7FFF:
      result = CAkMotionGeneratorParams::ReadAllCurves(this, (const void **)&io_ppData);
      break;
    default:
      return 31i64;
  }
  return result;
}

// File Line: 216
// RVA: 0xACE420
signed __int64 __fastcall CAkMotionGeneratorParams::ReadAllCurves(CAkMotionGeneratorParams *this, const void **io_ppData)
{
  unsigned __int16 v2; // di
  const void **v3; // r15
  CAkMotionGeneratorParams *v4; // rbp
  AkRTPCGraphPointBase<float> *v5; // rbx
  signed int v6; // er14
  unsigned __int16 v7; // si

  v2 = 0;
  v3 = io_ppData;
  v4 = this;
  this->m_Params.m_uCurves = 0;
  v5 = (AkRTPCGraphPointBase<float> *)((char *)*io_ppData + 2);
  v6 = *(unsigned __int16 *)*io_ppData;
  if ( v6 <= 0 )
  {
    *io_ppData = v5;
  }
  else
  {
    do
    {
      v7 = LOWORD(v5->From);
      v5 = (AkRTPCGraphPointBase<float> *)((char *)v5 + 2);
      if ( v7 )
      {
        CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
          (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)v4 + v2 + 3i64,
          v5,
          v7,
          0);
        v5 += v7;
      }
      ++v4->m_Params.m_uCurves;
      ++v2;
    }
    while ( v2 < v6 );
    *v3 = v5;
  }
  return 1i64;
}

// File Line: 243
// RVA: 0xACDF40
AK::IAkPlugin *__fastcall AkCreateMotionGenerator(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112ui64);
  v2 = result;
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkMotionGenerator::`vftable;
    result[1].vfptr = 0i64;
    result[13].vfptr = 0i64;
    result[12].vfptr = 0i64;
    result[2].vfptr = 0i64;
    *(AK::IAkPluginVtbl **)((char *)&result[4].vfptr + 4) = 0i64;
    result[3].vfptr = 0i64;
    BYTE4(result[11].vfptr) = 0;
    LODWORD(result[4].vfptr) = 1065353216;
    memset((char *)&result[5].vfptr + 4, 0, 0x30ui64);
    result = v2;
  }
  return result;
}

// File Line: 287
// RVA: 0xACE3A0
signed __int64 __fastcall CAkMotionGenerator::Init(CAkMotionGenerator *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkSourcePluginContext *in_pSourceFXContext, AK::IAkPluginParam *in_pParams, AkAudioFormat *io_rFormat)
{
  this->m_pSourceFXContext = in_pSourceFXContext;
  this->m_pSharedParams = (CAkMotionGeneratorParams *)in_pParams;
  switch ( LOWORD(in_pParams[14].vfptr) )
  {
    case 1:
      *((_DWORD *)io_rFormat + 1) &= 0xFFFC0004;
      *((_DWORD *)io_rFormat + 1) |= 4u;
      break;
    case 2:
      *((_DWORD *)io_rFormat + 1) &= 0xFFFC0003;
      *((_DWORD *)io_rFormat + 1) |= 3u;
      break;
    case 4:
      *((_DWORD *)io_rFormat + 1) &= 0xFFFC0033;
      *((_DWORD *)io_rFormat + 1) |= 0x33u;
      break;
  }
  this->m_uSampleRate = io_rFormat->uSampleRate;
  this->m_uBytesPerSample = (*((_DWORD *)io_rFormat + 1) >> 21) & 7;
  return 1i64;
}

// File Line: 323
// RVA: 0xACE4D0
signed __int64 __fastcall CAkMotionGenerator::Reset(CAkMotionGenerator *this)
{
  CAkMotionGenerator *v1; // rbx
  unsigned __int16 v2; // ax
  CAkMotionGeneratorParams *v3; // rax
  float v4; // xmm0_4
  float v5; // xmm2_4
  signed int v6; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  CAkMotionGeneratorParams *v10; // rax
  CAkMotionGeneratorParams *v11; // rcx
  float v12; // xmm1_4
  CAkMotionGeneratorParams *v13; // rax
  unsigned __int16 v14; // cx
  float v15; // xmm0_4

  v1 = this;
  this->m_fTime = 0.0;
  *(_QWORD *)this->m_iCurvePoint = 0i64;
  this->m_uSamplesProduced = 0;
  v2 = ((__int64 (*)(void))this->m_pSourceFXContext->vfptr[1].__vecDelDtor)();
  v1->m_uLoops = v2;
  if ( !v2 )
    v1->m_uLoops = -1;
  v3 = v1->m_pSharedParams;
  if ( v3->m_Params.m_eDurationType == 2 )
  {
    v4 = v3->m_Params.m_fAttackTime;
    v5 = 0.0;
    if ( v4 == 0.0 )
    {
      *(_QWORD *)&v1->m_ADSRState[0].m_fStep = 0i64;
      v1->m_ADSRState[0].m_iNextSection = -1;
    }
    else
    {
      v6 = v1->m_uSampleRate;
      v1->m_ADSRState[0].m_fStartVol = 0.0;
      v7 = (float)v6 * v4;
      v1->m_ADSRState[0].m_iNextSection = (signed int)v7;
      v1->m_ADSRState[0].m_fStep = 1.0 / v7;
    }
    v8 = v1->m_pSharedParams->m_Params.m_fDecayTime;
    if ( v8 == 0.0 )
    {
      v1->m_ADSRState[1].m_fStep = 0.0;
      v1->m_ADSRState[1].m_iNextSection = -1;
    }
    else
    {
      v9 = (float)(signed int)v1->m_uSampleRate * v8;
      v1->m_ADSRState[1].m_iNextSection = v1->m_ADSRState[0].m_iNextSection + (signed int)v9;
      v1->m_ADSRState[1].m_fStep = (float)(1.0 - v1->m_pSharedParams->m_Params.m_fSustainLevel) * (float)(-1.0 / v9);
    }
    v1->m_ADSRState[1].m_fStartVol = 1.0;
    v10 = v1->m_pSharedParams;
    if ( 0.0 == v10->m_Params.m_fSustainTime )
    {
      v1->m_ADSRState[2].m_fStartVol = 1.0;
      v1->m_ADSRState[2].m_iNextSection = -1;
    }
    else
    {
      v1->m_ADSRState[2].m_fStartVol = v10->m_Params.m_fSustainLevel;
      v1->m_ADSRState[2].m_iNextSection = v1->m_ADSRState[1].m_iNextSection
                                        + (signed int)(float)((float)(signed int)v1->m_uSampleRate
                                                            * v1->m_pSharedParams->m_Params.m_fSustainTime);
    }
    v1->m_ADSRState[2].m_fStep = 0.0;
    v11 = v1->m_pSharedParams;
    v12 = v11->m_Params.m_fReleaseTime;
    if ( v12 == 0.0 )
    {
      *(_QWORD *)&v1->m_ADSRState[3].m_fStep = 0i64;
    }
    else
    {
      v1->m_ADSRState[3].m_fStep = (float)(-1.0 / (float)((float)(signed int)v1->m_uSampleRate * v12))
                                 * v11->m_Params.m_fSustainLevel;
      v1->m_ADSRState[3].m_fStartVol = v11->m_Params.m_fSustainLevel;
    }
    v13 = v1->m_pSharedParams;
    v14 = v13->m_Params.m_eDurationType;
    if ( v14 )
    {
      if ( v14 == 1 )
      {
        v5 = v13->m_Params.m_fDuration;
      }
      else if ( v14 == 2 )
      {
        v5 = (float)((float)(v13->m_Params.m_fDecayTime + v13->m_Params.m_fAttackTime) + v13->m_Params.m_fSustainTime)
           + v13->m_Params.m_fReleaseTime;
      }
    }
    else
    {
      v5 = v13->m_Params.m_fPeriodMultiplier * v13->m_Params.m_fPeriod;
    }
    v15 = (float)(signed int)v1->m_uSampleRate * v5;
    v1->m_uDuration = (signed int)v15;
    v1->m_ADSRState[3].m_iNextSection = (signed int)v15 - 1;
    v1->m_fVol = 0.0;
  }
  else
  {
    v1->m_ADSRState[0].m_fStep = 0.0;
    v1->m_ADSRState[0].m_fStartVol = 1.0;
    v1->m_fVol = 1.0;
  }
  v1->m_uSection = 0;
  return 1i64;
}

// File Line: 418
// RVA: 0xACE380
signed __int64 __fastcall CAkMotionGenerator::GetPluginInfo(CAkMotionGenerator *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 5;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 434
// RVA: 0xACE050
void __fastcall CAkMotionGenerator::Execute(CAkMotionGenerator *this, AkAudioBuffer *io_pBufferOut)
{
  CAkMotionGenerator *v2; // rsi
  CAkMotionGeneratorParams *v3; // rcx
  AkAudioBuffer *v4; // r14
  float v5; // xmm1_4
  unsigned __int16 v6; // ax
  float v7; // xmm8_4
  float v8; // xmm0_4
  unsigned int v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned int v14; // er15
  float v15; // xmm9_4
  unsigned int i; // ebp
  float *v17; // rbx
  unsigned __int64 v18; // rdi
  float v19; // xmm0_4
  float v20; // xmm0_4
  CAkMotionGeneratorParams *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  unsigned int j; // edx
  __int64 v25; // rcx

  io_pBufferOut->eState = 45;
  v2 = this;
  v3 = this->m_pSharedParams;
  v4 = io_pBufferOut;
  v5 = (float)(signed int)v2->m_uSampleRate;
  v6 = v3->m_Params.m_eDurationType;
  v7 = 1.0 / (float)(v3->m_Params.m_fPeriodMultiplier * v5);
  v8 = 0.0;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      v8 = v3->m_Params.m_fDuration;
    }
    else if ( v6 == 2 )
    {
      v8 = (float)((float)(v3->m_Params.m_fDecayTime + v3->m_Params.m_fAttackTime) + v3->m_Params.m_fSustainTime)
         + v3->m_Params.m_fReleaseTime;
    }
  }
  else
  {
    v8 = v3->m_Params.m_fPeriodMultiplier * v3->m_Params.m_fPeriod;
  }
  v9 = v2->m_uSamplesProduced;
  v10 = (signed int)(float)(v5 * v8);
  v2->m_uDuration = v10;
  if ( v9 >= v10 )
  {
    v11 = v9 - v10;
    v2->m_uSamplesProduced = v11;
    v2->m_fTime = (float)v11 * v7;
    *(_QWORD *)v2->m_iCurvePoint = 0i64;
    --v2->m_uLoops;
  }
  if ( v2->m_pSharedParams->m_Params.m_eDurationType == 2 )
  {
    v12 = (unsigned __int8)v2->m_uSection;
    if ( (signed int)v2->m_uSamplesProduced >= v2->m_ADSRState[v12].m_iNextSection )
    {
      LOBYTE(v13) = v2->m_uSection;
      do
      {
        v13 = ((_BYTE)v13 + 1) & 3;
        v2->m_uSection = v13;
      }
      while ( v2->m_ADSRState[v13].m_iNextSection == -1 );
      v2->m_fVol = v2->m_ADSRState[v13].m_fStartVol;
    }
  }
  v14 = 0;
  v15 = *((float *)&v2->vfptr + 3 * ((unsigned __int8)v2->m_uSection + 4i64));
  if ( v4->uMaxFrames > 0u )
  {
    do
    {
      for ( i = 0; i < v2->m_pSharedParams->m_Params.m_uCurves; v17[v18] = v19 * v2->m_fVol )
      {
        v17 = (float *)v4->pData;
        v18 = v14 + i * (unsigned __int64)v4->uMaxFrames;
        v19 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)&v2->m_pSharedParams->m_Params.m_Curves[i].m_pArrayGraphPoints,
                v2->m_fTime,
                v2->m_iCurvePoint[i],
                &v2->m_iCurvePoint[i]);
        ++i;
      }
      v20 = v15 + v2->m_fVol;
      v2->m_fVol = v20;
      if ( v20 < 0.0 )
        v20 = 0.0;
      v2->m_fVol = v20;
      if ( v20 > 1.0 )
        v20 = *(float *)&FLOAT_1_0;
      v21 = v2->m_pSharedParams;
      v2->m_fVol = v20;
      v22 = v7 + v2->m_fTime;
      v2->m_fTime = v22;
      v23 = v21->m_Params.m_fPeriod;
      if ( v22 >= v23 )
      {
        v2->m_fTime = v22 - v23;
        *(_QWORD *)v2->m_iCurvePoint = 0i64;
      }
      ++v14;
    }
    while ( v14 < v4->uMaxFrames );
  }
  v2->m_uSamplesProduced += v4->uMaxFrames;
  if ( v2->m_uSamplesProduced >= v2->m_uDuration && v2->m_uLoops <= 1 )
  {
    v4->eState = 17;
    for ( j = 0; j < v2->m_pSharedParams->m_Params.m_uCurves; *((_DWORD *)v4->pData + v4->uMaxFrames * (v25 + 1) - 1) = 0 )
      v25 = j++;
  }
  v4->uValidFrames = v4->uMaxFrames;
}

// File Line: 528
// RVA: 0xACE310
float __fastcall CAkMotionGenerator::GetDuration(CAkMotionGenerator *this)
{
  CAkMotionGeneratorParams *v1; // rax
  float v2; // xmm0_4
  unsigned __int16 v3; // dx
  float v4; // xmm1_4
  float result; // xmm0_4

  v1 = this->m_pSharedParams;
  v2 = 0.0;
  v3 = v1->m_Params.m_eDurationType;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v2 = v1->m_Params.m_fDuration;
    }
    else if ( v3 == 2 )
    {
      v2 = (float)((float)(v1->m_Params.m_fDecayTime + v1->m_Params.m_fAttackTime) + v1->m_Params.m_fSustainTime)
         + v1->m_Params.m_fReleaseTime;
    }
  }
  else
  {
    v2 = v1->m_Params.m_fPeriodMultiplier * v1->m_Params.m_fPeriod;
  }
  v4 = (float)(signed int)this->m_uSampleRate * v2;
  result = v2 * 1000.0;
  this->m_uDuration = (signed int)v4;
  return result;
}

// File Line: 533
// RVA: 0xACE8C0
signed __int64 __fastcall CAkMotionGenerator::StopLooping(CAkMotionGenerator *this)
{
  this->m_uLoops = 1;
  return 1i64;
}

