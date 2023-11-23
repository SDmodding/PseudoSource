// File Line: 39
// RVA: 0xACDFB0
AK::IAkPluginParam *__fastcall AkCreateMotionGeneratorParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 128i64);
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
  result[15].vfptr = (AK::IAkRTPCSubscriberVtbl *)in_pAllocator;
  return result;
}

// File Line: 51
// RVA: 0xACDD90
void __fastcall CAkMotionGeneratorParams::CAkMotionGeneratorParams(
        CAkMotionGeneratorParams *this,
        CAkMotionGeneratorParams *Copy)
{
  int v2; // ebx
  unsigned __int16 m_uCurves; // ax
  AkCurve *m_Curves; // rsi

  v2 = 0;
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
  m_uCurves = Copy->m_Params.m_uCurves;
  this->m_Params.m_uCurves = m_uCurves;
  if ( m_uCurves )
  {
    m_Curves = Copy->m_Params.m_Curves;
    do
    {
      CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
        &this->m_Params.m_Curves[v2++],
        m_Curves->m_pArrayGraphPoints,
        m_Curves->m_ulArraySize,
        AkCurveScaling_None);
      ++m_Curves;
    }
    while ( v2 < this->m_Params.m_uCurves );
  }
}

// File Line: 77
// RVA: 0xACDE60
void __fastcall CAkMotionGeneratorParams::~CAkMotionGeneratorParams(CAkMotionGeneratorParams *this)
{
  int v2; // edi
  AkCurve *m_Curves; // rbx
  AkCurve *v4; // rbx
  __int64 v5; // rdi

  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMotionGeneratorParams::`vftable;
  v2 = 0;
  if ( this->m_Params.m_uCurves )
  {
    m_Curves = this->m_Params.m_Curves;
    do
    {
      if ( m_Curves->m_pArrayGraphPoints )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_Curves->m_pArrayGraphPoints);
        m_Curves->m_pArrayGraphPoints = 0i64;
      }
      *(_QWORD *)&m_Curves->m_ulArraySize = 0i64;
      ++v2;
      ++m_Curves;
    }
    while ( v2 < this->m_Params.m_uCurves );
  }
  v4 = this->m_Params.m_Curves;
  v5 = 4i64;
  do
  {
    if ( v4->m_pArrayGraphPoints )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v4->m_pArrayGraphPoints);
      v4->m_pArrayGraphPoints = 0i64;
    }
    *(_QWORD *)&v4->m_ulArraySize = 0i64;
    ++v4;
    --v5;
  }
  while ( v5 );
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 84
// RVA: 0xACE010
void __fastcall CAkMotionGeneratorParams::Clone(CAkMotionGeneratorParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkMotionGeneratorParams *v3; // rax

  v3 = (CAkMotionGeneratorParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 128i64);
  if ( v3 )
    CAkMotionGeneratorParams::CAkMotionGeneratorParams(v3, this);
}

// File Line: 93
// RVA: 0xACE400
__int64 __fastcall CAkMotionGeneratorParams::Init(
        CAkMotionGeneratorParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pvParamsBlock,
        unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkMotionGeneratorParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pvParamsBlock,
             in_ulBlockSize);
  else
    return 1i64;
}

// File Line: 111
// RVA: 0xACE820
__int64 __fastcall CAkMotionGeneratorParams::SetParamsBlock(
        CAkMotionGeneratorParams *this,
        char *in_pvParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v5; // xmm0_4
  void *io_ppData; // [rsp+38h] [rbp+10h] BYREF

  if ( !in_pvParamsBlock || in_ulBlockSize < 0x22 )
    return 31i64;
  *(_QWORD *)&this->m_Params.m_fPeriod = *(_QWORD *)in_pvParamsBlock;
  *(_QWORD *)&this->m_Params.m_fDuration = *((_QWORD *)in_pvParamsBlock + 1);
  *(_QWORD *)&this->m_Params.m_fDecayTime = *((_QWORD *)in_pvParamsBlock + 2);
  *(_QWORD *)&this->m_Params.m_fReleaseTime = *((_QWORD *)in_pvParamsBlock + 3);
  this->m_Params.m_eDurationType = *((_WORD *)in_pvParamsBlock + 16);
  v5 = powf(10.0, this->m_Params.m_fSustainLevel * 0.050000001);
  io_ppData = in_pvParamsBlock + 34;
  this->m_Params.m_fSustainLevel = v5;
  return CAkMotionGeneratorParams::ReadAllCurves(this, (AkRTPCGraphPointBase<float> **)&io_ppData);
}

// File Line: 136
// RVA: 0xACE6C0
__int64 __fastcall CAkMotionGeneratorParams::SetParam(
        CAkMotionGeneratorParams *this,
        __int16 in_ParamID,
        float *in_pvValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
  float v6; // xmm0_4
  void *io_ppData; // [rsp+40h] [rbp+18h] BYREF

  io_ppData = in_pvValue;
  if ( !in_pvValue )
    return 31i64;
  if ( in_ParamID <= 13 )
  {
    switch ( in_ParamID )
    {
      case 13:
        this->m_Params.m_fDecayTime = *in_pvValue;
        return 1i64;
      case 0:
        this->m_Params.m_fPeriod = *in_pvValue;
        return 1i64;
      case 1:
        this->m_Params.m_fPeriodMultiplier = *in_pvValue;
        return 1i64;
      case 2:
        this->m_Params.m_eDurationType = *(_WORD *)in_pvValue;
        return 1i64;
      case 3:
        this->m_Params.m_fDuration = *in_pvValue;
        return 1i64;
      case 12:
        this->m_Params.m_fAttackTime = *in_pvValue;
        return 1i64;
    }
    return 31i64;
  }
  switch ( in_ParamID )
  {
    case 0xE:
      this->m_Params.m_fSustainTime = *in_pvValue;
      return 1i64;
    case 0xF:
      v6 = powf(10.0, *in_pvValue * 0.050000001);
      result = 1i64;
      this->m_Params.m_fSustainLevel = v6;
      break;
    case 0x10:
      this->m_Params.m_fReleaseTime = *in_pvValue;
      return 1i64;
    case 0x7FFF:
      return CAkMotionGeneratorParams::ReadAllCurves(this, (AkRTPCGraphPointBase<float> **)&io_ppData);
    default:
      return 31i64;
  }
  return result;
}

// File Line: 216
// RVA: 0xACE420
__int64 __fastcall CAkMotionGeneratorParams::ReadAllCurves(
        CAkMotionGeneratorParams *this,
        AkRTPCGraphPointBase<float> **io_ppData)
{
  unsigned __int16 v2; // di
  AkRTPCGraphPointBase<float> *v5; // rbx
  int From_low; // r14d
  unsigned __int16 v7; // si

  v2 = 0;
  this->m_Params.m_uCurves = 0;
  v5 = (AkRTPCGraphPointBase<float> *)((char *)&(*io_ppData)->From + 2);
  From_low = LOWORD((*io_ppData)->From);
  if ( LOWORD((*io_ppData)->From) )
  {
    do
    {
      v7 = LOWORD(v5->From);
      v5 = (AkRTPCGraphPointBase<float> *)((char *)v5 + 2);
      if ( v7 )
      {
        CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
          &this->m_Params.m_Curves[v2],
          v5,
          v7,
          AkCurveScaling_None);
        v5 += v7;
      }
      ++this->m_Params.m_uCurves;
      ++v2;
    }
    while ( v2 < From_low );
    *io_ppData = v5;
  }
  else
  {
    *io_ppData = v5;
  }
  return 1i64;
}

// File Line: 243
// RVA: 0xACDF40
AK::IAkPlugin *__fastcall AkCreateMotionGenerator(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112i64);
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
    return v2;
  }
  return result;
}

// File Line: 287
// RVA: 0xACE3A0
__int64 __fastcall CAkMotionGenerator::Init(
        CAkMotionGenerator *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkSourcePluginContext *in_pSourceFXContext,
        CAkMotionGeneratorParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  this->m_pSourceFXContext = in_pSourceFXContext;
  this->m_pSharedParams = in_pParams;
  switch ( in_pParams->m_Params.m_uCurves )
  {
    case 1u:
      *((_DWORD *)io_rFormat + 1) &= 0xFFFC0004;
      *((_DWORD *)io_rFormat + 1) |= 4u;
      break;
    case 2u:
      *((_DWORD *)io_rFormat + 1) &= 0xFFFC0003;
      *((_DWORD *)io_rFormat + 1) |= 3u;
      break;
    case 4u:
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
__int64 __fastcall CAkMotionGenerator::Reset(CAkMotionGenerator *this)
{
  unsigned __int16 v2; // ax
  CAkMotionGeneratorParams *m_pSharedParams; // rax
  float m_fAttackTime; // xmm0_4
  float m_fDuration; // xmm2_4
  signed int m_uSampleRate; // eax
  float v7; // xmm1_4
  float m_fDecayTime; // xmm0_4
  float v9; // xmm1_4
  CAkMotionGeneratorParams *v10; // rax
  CAkMotionGeneratorParams *v11; // rcx
  float m_fReleaseTime; // xmm1_4
  CAkMotionGeneratorParams *v13; // rax
  unsigned __int16 m_eDurationType; // cx
  float v15; // xmm0_4

  this->m_fTime = 0.0;
  *(_QWORD *)this->m_iCurvePoint = 0i64;
  this->m_uSamplesProduced = 0;
  v2 = ((__int64 (__fastcall *)(AK::IAkSourcePluginContext *))this->m_pSourceFXContext->vfptr[1].__vecDelDtor)(this->m_pSourceFXContext);
  this->m_uLoops = v2;
  if ( !v2 )
    this->m_uLoops = -1;
  m_pSharedParams = this->m_pSharedParams;
  if ( m_pSharedParams->m_Params.m_eDurationType == 2 )
  {
    m_fAttackTime = m_pSharedParams->m_Params.m_fAttackTime;
    m_fDuration = 0.0;
    if ( m_fAttackTime == 0.0 )
    {
      *(_QWORD *)&this->m_ADSRState[0].m_fStep = 0i64;
      this->m_ADSRState[0].m_iNextSection = -1;
    }
    else
    {
      m_uSampleRate = this->m_uSampleRate;
      this->m_ADSRState[0].m_fStartVol = 0.0;
      v7 = (float)m_uSampleRate * m_fAttackTime;
      this->m_ADSRState[0].m_iNextSection = (int)v7;
      this->m_ADSRState[0].m_fStep = 1.0 / v7;
    }
    m_fDecayTime = this->m_pSharedParams->m_Params.m_fDecayTime;
    if ( m_fDecayTime == 0.0 )
    {
      this->m_ADSRState[1].m_fStep = 0.0;
      this->m_ADSRState[1].m_iNextSection = -1;
    }
    else
    {
      v9 = (float)(int)this->m_uSampleRate * m_fDecayTime;
      this->m_ADSRState[1].m_iNextSection = this->m_ADSRState[0].m_iNextSection + (int)v9;
      this->m_ADSRState[1].m_fStep = (float)(1.0 - this->m_pSharedParams->m_Params.m_fSustainLevel) * (float)(-1.0 / v9);
    }
    this->m_ADSRState[1].m_fStartVol = 1.0;
    v10 = this->m_pSharedParams;
    if ( v10->m_Params.m_fSustainTime == 0.0 )
    {
      this->m_ADSRState[2].m_fStartVol = 1.0;
      this->m_ADSRState[2].m_iNextSection = -1;
    }
    else
    {
      this->m_ADSRState[2].m_fStartVol = v10->m_Params.m_fSustainLevel;
      this->m_ADSRState[2].m_iNextSection = this->m_ADSRState[1].m_iNextSection
                                          + (int)(float)((float)(int)this->m_uSampleRate
                                                       * this->m_pSharedParams->m_Params.m_fSustainTime);
    }
    this->m_ADSRState[2].m_fStep = 0.0;
    v11 = this->m_pSharedParams;
    m_fReleaseTime = v11->m_Params.m_fReleaseTime;
    if ( m_fReleaseTime == 0.0 )
    {
      *(_QWORD *)&this->m_ADSRState[3].m_fStep = 0i64;
    }
    else
    {
      this->m_ADSRState[3].m_fStep = (float)(-1.0 / (float)((float)(int)this->m_uSampleRate * m_fReleaseTime))
                                   * v11->m_Params.m_fSustainLevel;
      this->m_ADSRState[3].m_fStartVol = v11->m_Params.m_fSustainLevel;
    }
    v13 = this->m_pSharedParams;
    m_eDurationType = v13->m_Params.m_eDurationType;
    if ( m_eDurationType )
    {
      if ( m_eDurationType == 1 )
      {
        m_fDuration = v13->m_Params.m_fDuration;
      }
      else if ( m_eDurationType == 2 )
      {
        m_fDuration = (float)((float)(v13->m_Params.m_fDecayTime + v13->m_Params.m_fAttackTime)
                            + v13->m_Params.m_fSustainTime)
                    + v13->m_Params.m_fReleaseTime;
      }
    }
    else
    {
      m_fDuration = v13->m_Params.m_fPeriodMultiplier * v13->m_Params.m_fPeriod;
    }
    v15 = (float)(int)this->m_uSampleRate * m_fDuration;
    this->m_uDuration = (int)v15;
    this->m_ADSRState[3].m_iNextSection = (int)v15 - 1;
    this->m_fVol = 0.0;
  }
  else
  {
    this->m_ADSRState[0].m_fStep = 0.0;
    this->m_ADSRState[0].m_fStartVol = 1.0;
    this->m_fVol = 1.0;
  }
  this->m_uSection = 0;
  return 1i64;
}

// File Line: 418
// RVA: 0xACE380
__int64 __fastcall CAkMotionGenerator::GetPluginInfo(CAkMotionGenerator *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeMotionSource;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 434
// RVA: 0xACE050
void __fastcall CAkMotionGenerator::Execute(CAkMotionGenerator *this, AkAudioBuffer *io_pBufferOut)
{
  CAkMotionGeneratorParams *m_pSharedParams; // rcx
  float m_uSampleRate; // xmm1_4
  unsigned __int16 m_eDurationType; // ax
  float v7; // xmm8_4
  float m_fDuration; // xmm0_4
  unsigned int m_uSamplesProduced; // eax
  unsigned int v10; // ecx
  signed int v11; // eax
  __int64 v12; // rcx
  unsigned int v13; // r15d
  float i; // xmm9_4
  unsigned int j; // ebp
  float *pData; // rbx
  unsigned __int64 v17; // rdi
  float v18; // xmm0_4
  float v19; // xmm0_4
  CAkMotionGeneratorParams *v20; // rax
  float v21; // xmm1_4
  float m_fPeriod; // xmm0_4
  unsigned int k; // edx
  __int64 v24; // rcx

  io_pBufferOut->eState = AK_DataReady;
  m_pSharedParams = this->m_pSharedParams;
  m_uSampleRate = (float)(int)this->m_uSampleRate;
  m_eDurationType = m_pSharedParams->m_Params.m_eDurationType;
  v7 = 1.0 / (float)(m_pSharedParams->m_Params.m_fPeriodMultiplier * m_uSampleRate);
  m_fDuration = 0.0;
  if ( m_eDurationType )
  {
    if ( m_eDurationType == 1 )
    {
      m_fDuration = m_pSharedParams->m_Params.m_fDuration;
    }
    else if ( m_eDurationType == 2 )
    {
      m_fDuration = (float)((float)(m_pSharedParams->m_Params.m_fDecayTime + m_pSharedParams->m_Params.m_fAttackTime)
                          + m_pSharedParams->m_Params.m_fSustainTime)
                  + m_pSharedParams->m_Params.m_fReleaseTime;
    }
  }
  else
  {
    m_fDuration = m_pSharedParams->m_Params.m_fPeriodMultiplier * m_pSharedParams->m_Params.m_fPeriod;
  }
  m_uSamplesProduced = this->m_uSamplesProduced;
  v10 = (int)(float)(m_uSampleRate * m_fDuration);
  this->m_uDuration = v10;
  if ( m_uSamplesProduced >= v10 )
  {
    v11 = m_uSamplesProduced - v10;
    this->m_uSamplesProduced = v11;
    this->m_fTime = (float)v11 * v7;
    *(_QWORD *)this->m_iCurvePoint = 0i64;
    --this->m_uLoops;
  }
  if ( this->m_pSharedParams->m_Params.m_eDurationType == 2
    && (signed int)this->m_uSamplesProduced >= this->m_ADSRState[(unsigned __int8)this->m_uSection].m_iNextSection )
  {
    LOBYTE(v12) = this->m_uSection;
    do
    {
      v12 = ((_BYTE)v12 + 1) & 3;
      this->m_uSection = v12;
    }
    while ( this->m_ADSRState[v12].m_iNextSection == -1 );
    this->m_fVol = this->m_ADSRState[v12].m_fStartVol;
  }
  v13 = 0;
  for ( i = this->m_ADSRState[(unsigned __int8)this->m_uSection].m_fStep; v13 < io_pBufferOut->uMaxFrames; ++v13 )
  {
    for ( j = 0; j < this->m_pSharedParams->m_Params.m_uCurves; pData[v17] = v18 * this->m_fVol )
    {
      pData = (float *)io_pBufferOut->pData;
      v17 = v13 + j * (unsigned __int64)io_pBufferOut->uMaxFrames;
      v18 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
              &this->m_pSharedParams->m_Params.m_Curves[j],
              this->m_fTime,
              this->m_iCurvePoint[j],
              &this->m_iCurvePoint[j]);
      ++j;
    }
    v19 = i + this->m_fVol;
    this->m_fVol = v19;
    if ( v19 < 0.0 )
      v19 = 0.0;
    this->m_fVol = v19;
    if ( v19 > 1.0 )
      v19 = *(float *)&FLOAT_1_0;
    v20 = this->m_pSharedParams;
    this->m_fVol = v19;
    v21 = v7 + this->m_fTime;
    this->m_fTime = v21;
    m_fPeriod = v20->m_Params.m_fPeriod;
    if ( v21 >= m_fPeriod )
    {
      this->m_fTime = v21 - m_fPeriod;
      *(_QWORD *)this->m_iCurvePoint = 0i64;
    }
  }
  this->m_uSamplesProduced += io_pBufferOut->uMaxFrames;
  if ( this->m_uSamplesProduced >= this->m_uDuration && this->m_uLoops <= 1 )
  {
    io_pBufferOut->eState = AK_NoMoreData;
    for ( k = 0;
          k < this->m_pSharedParams->m_Params.m_uCurves;
          *((_DWORD *)io_pBufferOut->pData + io_pBufferOut->uMaxFrames * (v24 + 1) - 1) = 0 )
    {
      v24 = k++;
    }
  }
  io_pBufferOut->uValidFrames = io_pBufferOut->uMaxFrames;
}

// File Line: 528
// RVA: 0xACE310
float __fastcall CAkMotionGenerator::GetDuration(CAkMotionGenerator *this)
{
  CAkMotionGeneratorParams *m_pSharedParams; // rax
  float m_fDuration; // xmm0_4
  unsigned __int16 m_eDurationType; // dx
  float v4; // xmm1_4
  float result; // xmm0_4

  m_pSharedParams = this->m_pSharedParams;
  m_fDuration = 0.0;
  m_eDurationType = m_pSharedParams->m_Params.m_eDurationType;
  if ( m_eDurationType )
  {
    if ( m_eDurationType == 1 )
    {
      m_fDuration = m_pSharedParams->m_Params.m_fDuration;
    }
    else if ( m_eDurationType == 2 )
    {
      m_fDuration = (float)((float)(m_pSharedParams->m_Params.m_fDecayTime + m_pSharedParams->m_Params.m_fAttackTime)
                          + m_pSharedParams->m_Params.m_fSustainTime)
                  + m_pSharedParams->m_Params.m_fReleaseTime;
    }
  }
  else
  {
    m_fDuration = m_pSharedParams->m_Params.m_fPeriodMultiplier * m_pSharedParams->m_Params.m_fPeriod;
  }
  v4 = (float)(int)this->m_uSampleRate * m_fDuration;
  result = m_fDuration * 1000.0;
  this->m_uDuration = (int)v4;
  return result;
}

// File Line: 533
// RVA: 0xACE8C0
__int64 __fastcall CAkMotionGenerator::StopLooping(CAkMotionGenerator *this)
{
  this->m_uLoops = 1;
  return 1i64;
}

