// File Line: 20
// RVA: 0xAD4370
AK::IAkPluginParam *__fastcall CreateSoundSeedWindParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 240i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable;
    result[1].vfptr = 0i64;
    result[2].vfptr = 0i64;
    result[3].vfptr = 0i64;
    result[4].vfptr = 0i64;
    result[5].vfptr = 0i64;
    result[6].vfptr = 0i64;
    result[7].vfptr = 0i64;
    result[8].vfptr = 0i64;
    result[9].vfptr = 0i64;
    result[10].vfptr = 0i64;
    result[11].vfptr = 0i64;
    result[12].vfptr = 0i64;
    result[13].vfptr = 0i64;
    result[14].vfptr = 0i64;
    result[27].vfptr = 0i64;
    result[28].vfptr = 0i64;
    result[29].vfptr = 0i64;
  }
  return result;
}

// File Line: 30
// RVA: 0xAD4400
void __fastcall CAkSoundSeedWindParams::CAkSoundSeedWindParams(CAkSoundSeedWindParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable;
  this->m_Curves[0].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[0].m_ulArraySize = 0i64;
  this->m_Curves[1].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[1].m_ulArraySize = 0i64;
  this->m_Curves[2].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[2].m_ulArraySize = 0i64;
  this->m_Curves[3].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[3].m_ulArraySize = 0i64;
  this->m_Curves[4].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[4].m_ulArraySize = 0i64;
  this->m_Curves[5].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[5].m_ulArraySize = 0i64;
  this->m_Curves[6].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[6].m_ulArraySize = 0i64;
  this->m_pAllocator = 0i64;
  this->m_pDeflectors = 0i64;
  *(_QWORD *)&this->m_uChangeMask = 0i64;
}

// File Line: 36
// RVA: 0xAD4720
void __fastcall CAkSoundSeedWindParams::~CAkSoundSeedWindParams(CAkSoundSeedWindParams *this)
{
  AkWindDeflectorParams *m_pDeflectors; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_Curves; // rbx
  __int64 v4; // rdi

  m_pDeflectors = this->m_pDeflectors;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable;
  if ( m_pDeflectors )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
  m_Curves = this->m_Curves;
  v4 = 7i64;
  do
  {
    if ( m_Curves->m_pArrayGraphPoints )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_Curves->m_pArrayGraphPoints);
      m_Curves->m_pArrayGraphPoints = 0i64;
    }
    *(_QWORD *)&m_Curves->m_ulArraySize = 0i64;
    ++m_Curves;
    --v4;
  }
  while ( v4 );
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 46
// RVA: 0xAD4470
void __fastcall CAkSoundSeedWindParams::CAkSoundSeedWindParams(
        CAkSoundSeedWindParams *this,
        CAkSoundSeedWindParams *in_rCopy,
        AKRESULT *out_eResult)
{
  int v4; // ebx
  AK::IAkPluginMemAlloc *m_pAllocator; // rcx
  int v8; // eax
  unsigned int m_cDeflectors; // eax
  AkWindDeflectorParams *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // r9d
  __int64 v13; // rax
  AkWindDeflectorParams *m_pDeflectors; // rcx
  AkWindDeflectorParams *v15; // r8
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *i; // rsi

  v4 = 0;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable;
  this->m_Curves[0].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[0].m_ulArraySize = 0i64;
  this->m_Curves[1].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[1].m_ulArraySize = 0i64;
  this->m_Curves[2].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[2].m_ulArraySize = 0i64;
  this->m_Curves[3].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[3].m_ulArraySize = 0i64;
  this->m_Curves[4].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[4].m_ulArraySize = 0i64;
  this->m_Curves[5].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[5].m_ulArraySize = 0i64;
  this->m_Curves[6].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[6].m_ulArraySize = 0i64;
  *out_eResult = AK_Success;
  m_pAllocator = in_rCopy->m_pAllocator;
  this->m_pAllocator = m_pAllocator;
  this->m_Params.fDuration = in_rCopy->m_Params.fDuration;
  this->m_Params.fDurationRdm = in_rCopy->m_Params.fDurationRdm;
  this->m_Params.uChannelMask = in_rCopy->m_Params.uChannelMask;
  this->m_Params.fMinDistance = in_rCopy->m_Params.fMinDistance;
  this->m_Params.fAttenuationRolloff = in_rCopy->m_Params.fAttenuationRolloff;
  this->m_Params.fMaxDistance = in_rCopy->m_Params.fMaxDistance;
  this->m_Params.fDynamicRange = in_rCopy->m_Params.fDynamicRange;
  this->m_Params.fPlaybackRate = in_rCopy->m_Params.fPlaybackRate;
  this->m_Params.fBaseValue[0] = in_rCopy->m_Params.fBaseValue[0];
  this->m_Params.fBaseValue[1] = in_rCopy->m_Params.fBaseValue[1];
  this->m_Params.fBaseValue[2] = in_rCopy->m_Params.fBaseValue[2];
  this->m_Params.fBaseValue[3] = in_rCopy->m_Params.fBaseValue[3];
  this->m_Params.fBaseValue[4] = in_rCopy->m_Params.fBaseValue[4];
  this->m_Params.fBaseValue[5] = in_rCopy->m_Params.fBaseValue[5];
  this->m_Params.fBaseValue[6] = in_rCopy->m_Params.fBaseValue[6];
  this->m_Params.fRandomValue[0] = in_rCopy->m_Params.fRandomValue[0];
  this->m_Params.fRandomValue[1] = in_rCopy->m_Params.fRandomValue[1];
  this->m_Params.fRandomValue[2] = in_rCopy->m_Params.fRandomValue[2];
  this->m_Params.fRandomValue[3] = in_rCopy->m_Params.fRandomValue[3];
  this->m_Params.fRandomValue[4] = in_rCopy->m_Params.fRandomValue[4];
  this->m_Params.fRandomValue[5] = in_rCopy->m_Params.fRandomValue[5];
  this->m_Params.fRandomValue[6] = in_rCopy->m_Params.fRandomValue[6];
  *(_DWORD *)this->m_Params.bAutomation = *(_DWORD *)in_rCopy->m_Params.bAutomation;
  v8 = *(_DWORD *)&in_rCopy->m_Params.bAutomation[4];
  *(_QWORD *)&this->m_uChangeMask = 63i64;
  *(_DWORD *)&this->m_Params.bAutomation[4] = v8;
  this->m_pDeflectors = 0i64;
  if ( in_rCopy->m_pDeflectors )
  {
    m_cDeflectors = in_rCopy->m_cDeflectors;
    if ( m_cDeflectors )
    {
      v10 = (AkWindDeflectorParams *)m_pAllocator->vfptr->Malloc(m_pAllocator, 20 * m_cDeflectors);
      this->m_pDeflectors = v10;
      if ( !v10 )
        goto LABEL_10;
      v11 = in_rCopy->m_cDeflectors;
      v12 = 0;
      for ( this->m_cDeflectors = v11; v12 < this->m_cDeflectors; v15->fGain = m_pDeflectors[v13].fGain )
      {
        v13 = v12++;
        m_pDeflectors = in_rCopy->m_pDeflectors;
        v15 = &this->m_pDeflectors[v13];
        v15->fDistance = m_pDeflectors[v13].fDistance;
        v15->fAngle = m_pDeflectors[v13].fAngle;
        v15->fFrequency = m_pDeflectors[v13].fFrequency;
        v15->fQFactor = m_pDeflectors[v13].fQFactor;
      }
    }
  }
  for ( i = in_rCopy->m_Curves;
        (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                        &this->m_Curves[v4],
                        i->m_pArrayGraphPoints,
                        i->m_ulArraySize,
                        AkCurveScaling_None) != 52;
        ++i )
  {
    if ( (unsigned int)++v4 >= 7 )
      return;
  }
LABEL_10:
  *out_eResult = AK_InsufficientMemory;
}

// File Line: 88
// RVA: 0xAD47B0
void __fastcall CAkSoundSeedWindParams::Clone(CAkSoundSeedWindParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAllocVtbl *vfptr; // rax
  CAkSoundSeedWindParams *v5; // rax
  __int64 v6; // rax
  AKRESULT out_eResult; // [rsp+38h] [rbp+10h] BYREF

  vfptr = in_pAllocator->vfptr;
  out_eResult = AK_Success;
  v5 = (CAkSoundSeedWindParams *)vfptr->Malloc(in_pAllocator, 240ui64);
  if ( v5 )
  {
    CAkSoundSeedWindParams::CAkSoundSeedWindParams(v5, this, &out_eResult);
    if ( v6 )
    {
      if ( out_eResult != AK_Success )
        (*(void (__fastcall **)(__int64, AK::IAkPluginMemAlloc *))(*(_QWORD *)v6 + 32i64))(v6, in_pAllocator);
    }
  }
}

// File Line: 104
// RVA: 0xAD4820
__int64 __fastcall CAkSoundSeedWindParams::Init(
        CAkSoundSeedWindParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int64 result; // rax
  __int128 v7; // xmm1
  __int128 v8; // xmm1

  this->m_pAllocator = in_pAllocator;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkSoundSeedWindParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  v4 = *(_OWORD *)&g_DefaultPreset.fDuration;
  v5 = *(_OWORD *)&g_DefaultPreset.fAttenuationRolloff;
  this->m_uChangeMask = 63;
  result = 1i64;
  *(_OWORD *)&this->m_Params.fDuration = v4;
  *(_OWORD *)&this->m_Params.fAttenuationRolloff = v5;
  v7 = *(_OWORD *)&g_DefaultPreset.fBaseValue[4];
  *(_OWORD *)this->m_Params.fBaseValue = *(_OWORD *)g_DefaultPreset.fBaseValue;
  *(_OWORD *)&this->m_Params.fBaseValue[4] = v7;
  v8 = *(_OWORD *)&g_DefaultPreset.fRandomValue[5];
  *(_OWORD *)&this->m_Params.fRandomValue[1] = *(_OWORD *)&g_DefaultPreset.fRandomValue[1];
  *(_OWORD *)&this->m_Params.fRandomValue[5] = v8;
  return result;
}

// File Line: 120
// RVA: 0xAD48B0
__int64 __fastcall CAkSoundSeedWindParams::Term(CAkSoundSeedWindParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 129
// RVA: 0xAD48F0
int __fastcall CAkSoundSeedWindParams::SetParamsBlock(
        CAkSoundSeedWindParams *this,
        unsigned __int16 *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  float v7; // xmm0_4
  char *v8; // rdx
  float v9; // xmm1_4
  int result; // eax
  AKRESULT AllCurves; // eax
  int v12; // ecx
  void *io_ppData; // [rsp+30h] [rbp+8h] BYREF

  this->m_Params.fDuration = *(float *)in_pParamsBlock;
  this->m_Params.fDurationRdm = *((float *)in_pParamsBlock + 1);
  v4 = in_pParamsBlock[4];
  v5 = v4;
  this->m_Params.uChannelMask = v4;
  if ( v4 )
  {
    v6 = 51;
    if ( v5 != 2 )
      v6 = 3;
    this->m_Params.uChannelMask = v6;
  }
  else
  {
    this->m_Params.uChannelMask = 4;
  }
  v7 = *(float *)(in_pParamsBlock + 5);
  v8 = (char *)in_pParamsBlock + 89;
  this->m_Params.fMinDistance = v7;
  v9 = *(float *)(v8 - 75);
  io_ppData = v8;
  this->m_Params.fAttenuationRolloff = v9;
  this->m_Params.fDynamicRange = *(float *)(v8 - 71);
  this->m_Params.fPlaybackRate = *(float *)(v8 - 67);
  this->m_Params.fBaseValue[0] = *(float *)(v8 - 63);
  this->m_Params.fRandomValue[0] = *(float *)(v8 - 59);
  this->m_Params.bAutomation[0] = *(v8 - 55);
  this->m_Params.fBaseValue[1] = *(float *)(v8 - 54);
  this->m_Params.fRandomValue[1] = *(float *)(v8 - 50);
  this->m_Params.bAutomation[1] = *(v8 - 46);
  this->m_Params.fBaseValue[2] = *(float *)(v8 - 45);
  this->m_Params.fRandomValue[2] = *(float *)(v8 - 41);
  this->m_Params.bAutomation[2] = *(v8 - 37);
  this->m_Params.fBaseValue[3] = *((float *)v8 - 9);
  this->m_Params.fRandomValue[3] = *((float *)v8 - 8);
  this->m_Params.bAutomation[3] = *(v8 - 28);
  this->m_Params.fBaseValue[4] = *(float *)(v8 - 27);
  this->m_Params.fRandomValue[4] = *(float *)(v8 - 23);
  this->m_Params.bAutomation[4] = *(v8 - 19);
  this->m_Params.fBaseValue[5] = *(float *)(v8 - 18);
  this->m_Params.fRandomValue[5] = *(float *)(v8 - 14);
  this->m_Params.bAutomation[5] = *(v8 - 10);
  this->m_Params.fBaseValue[6] = *(float *)(v8 - 9);
  this->m_Params.fRandomValue[6] = *(float *)(v8 - 5);
  this->m_Params.bAutomation[6] = *(v8 - 1);
  this->m_Params.fBaseValue[6] = powf(10.0, this->m_Params.fBaseValue[6] * 0.050000001);
  this->m_uChangeMask = 63;
  result = CAkSoundSeedWindParams::ReadDeflectors(this, (const void **)&io_ppData);
  if ( result == 1 )
  {
    AllCurves = CAkSoundSeedWindParams::ReadAllCurves(this, (const void **)&io_ppData);
    v12 = 1;
    if ( AllCurves != AK_Success )
      return AllCurves;
    return v12;
  }
  return result;
}

// File Line: 164
// RVA: 0xAD4F10
__int64 __fastcall CAkSoundSeedWindParams::ReadDeflectors(CAkSoundSeedWindParams *this, float **io_ppData)
{
  float *v2; // rdi
  AkWindDeflectorParams *m_pDeflectors; // rdx
  unsigned int v5; // eax
  unsigned int v6; // ebp
  float *v7; // rdi
  unsigned int v9; // ebx
  AkWindDeflectorParams *v10; // rax
  float v12; // xmm0_4
  __int64 v13; // rbx

  v2 = *io_ppData;
  m_pDeflectors = this->m_pDeflectors;
  v5 = *(unsigned __int16 *)v2;
  v6 = 0;
  v7 = (float *)((char *)v2 + 6);
  this->m_Params.fMaxDistance = *(v7 - 1);
  v9 = v5;
  if ( m_pDeflectors && this->m_cDeflectors != v5 )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pDeflectors = 0i64;
    this->m_cDeflectors = 0;
  }
  if ( v9 )
  {
    this->m_cDeflectors = v9;
    if ( !this->m_pDeflectors )
    {
      v10 = (AkWindDeflectorParams *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 20 * v9);
      this->m_pDeflectors = v10;
      if ( !v10 )
      {
        this->m_cDeflectors = 0;
        return 52i64;
      }
    }
    if ( this->m_cDeflectors )
    {
      do
      {
        v12 = *v7;
        v7 += 5;
        v13 = v6;
        this->m_pDeflectors[v13].fDistance = v12;
        this->m_pDeflectors[v13].fAngle = *(v7 - 4);
        this->m_pDeflectors[v13].fFrequency = *(v7 - 3);
        this->m_pDeflectors[v13].fQFactor = *(v7 - 2);
        ++v6;
        this->m_pDeflectors[v13].fGain = powf(10.0, *(v7 - 1) * 0.050000001);
      }
      while ( v6 < this->m_cDeflectors );
    }
  }
  *io_ppData = v7;
  return 1i64;
}

// File Line: 208
// RVA: 0xAD50A0
__int64 __fastcall CAkSoundSeedWindParams::ReadAllCurves(CAkSoundSeedWindParams *this, unsigned int **io_ppData)
{
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_Curves; // rbx
  __int64 v5; // rdi
  __int16 v6; // si
  unsigned int *v7; // rbx
  int v8; // r14d
  unsigned __int16 v9; // bp
  unsigned int v10; // edx
  unsigned int v11; // eax

  m_Curves = this->m_Curves;
  v5 = 7i64;
  v6 = 0;
  do
  {
    if ( m_Curves->m_pArrayGraphPoints )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_Curves->m_pArrayGraphPoints);
      m_Curves->m_pArrayGraphPoints = 0i64;
    }
    *(_QWORD *)&m_Curves->m_ulArraySize = 0i64;
    ++m_Curves;
    --v5;
  }
  while ( v5 );
  v7 = (unsigned int *)((char *)*io_ppData + 2);
  v8 = *(unsigned __int16 *)*io_ppData;
  if ( !*(_WORD *)*io_ppData )
  {
LABEL_10:
    *io_ppData = v7;
    return 1i64;
  }
  while ( 1 )
  {
    v9 = *((_WORD *)v7 + 2);
    v10 = *v7;
    v7 = (unsigned int *)((char *)v7 + 6);
    if ( v9 )
      break;
LABEL_9:
    if ( (unsigned __int16)++v6 >= v8 )
      goto LABEL_10;
  }
  v11 = CAkSoundSeedWindParams::CurveIDToIndex(this, v10);
  if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                       &this->m_Curves[v11],
                       (AkRTPCGraphPointBase<float> *)v7,
                       v9,
                       AkCurveScaling_None) != 52 )
  {
    v7 += 3 * v9;
    goto LABEL_9;
  }
  return 52i64;
}

// File Line: 230
// RVA: 0xAD51A0
__int64 __fastcall CAkSoundSeedWindParams::ReadCurve(CAkSoundSeedWindParams *this, unsigned int **io_ppData)
{
  unsigned int *v2; // rdi
  unsigned __int16 v5; // si
  unsigned int v6; // edx
  AkRTPCGraphPointBase<float> *v7; // rdi
  unsigned int v8; // eax
  __int64 result; // rax

  v2 = *io_ppData;
  v5 = *((_WORD *)*io_ppData + 2);
  v6 = **io_ppData;
  v7 = (AkRTPCGraphPointBase<float> *)((char *)v2 + 6);
  if ( v5 )
  {
    v8 = CAkSoundSeedWindParams::CurveIDToIndex(this, v6);
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
               &this->m_Curves[v8],
               v7,
               v5,
               AkCurveScaling_None);
    if ( (_DWORD)result == 52 )
      return result;
    v7 += v5;
  }
  *io_ppData = (unsigned int *)v7;
  return 1i64;
}

// File Line: 257
// RVA: 0xAD5260
__int64 __fastcall CAkSoundSeedWindParams::CurveIDToIndex(CAkSoundSeedWindParams *this, unsigned int in_uCurveID)
{
  unsigned int v2; // r8d
  __int64 result; // rax

  v2 = 0;
  switch ( in_uCurveID )
  {
    case 3u:
      result = 1i64;
      break;
    case 6u:
      result = 2i64;
      break;
    case 9u:
      result = 3i64;
      break;
    case 0x14u:
      result = 4i64;
      break;
    case 0x17u:
      result = 5i64;
      break;
    case 0x1Au:
      v2 = 6;
      goto $LN1_50;
    default:
$LN1_50:
      result = v2;
      break;
  }
  return result;
}

// File Line: 294
// RVA: 0xAD4AE0
AKRESULT __fastcall CAkSoundSeedWindParams::SetParam(
        CAkSoundSeedWindParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  AKRESULT result; // eax
  AKRESULT Deflectors; // edi
  unsigned int v7; // eax
  float v8; // xmm0_4
  void *io_ppData; // [rsp+40h] [rbp+18h] BYREF

  io_ppData = in_pValue;
  if ( !in_pValue )
    return 31;
  Deflectors = AK_Success;
  if ( in_ParamID == 0x7FFF )
  {
    this->m_uChangeMask |= 0x17u;
    Deflectors = CAkSoundSeedWindParams::ReadDeflectors(this, (const void **)&io_ppData);
    if ( Deflectors == AK_Success )
      return CAkSoundSeedWindParams::ReadAllCurves(this, (const void **)&io_ppData);
    else
      return Deflectors;
  }
  else
  {
    switch ( in_ParamID )
    {
      case -1:
        return Deflectors;
      case 0:
        this->m_Params.fBaseValue[0] = *in_pValue;
        result = AK_Success;
        break;
      case 1:
        this->m_Params.fRandomValue[0] = *in_pValue;
        result = AK_Success;
        break;
      case 2:
        this->m_Params.bAutomation[0] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 3:
        this->m_uChangeMask |= 0x10u;
        this->m_Params.fBaseValue[1] = *in_pValue;
        result = AK_Success;
        break;
      case 4:
        this->m_Params.fRandomValue[1] = *in_pValue;
        result = AK_Success;
        break;
      case 5:
        this->m_Params.bAutomation[1] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 6:
        this->m_Params.fBaseValue[2] = *in_pValue;
        result = AK_Success;
        break;
      case 7:
        this->m_Params.fRandomValue[2] = *in_pValue;
        result = AK_Success;
        break;
      case 8:
        this->m_Params.bAutomation[2] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 9:
        this->m_Params.fBaseValue[3] = *in_pValue;
        result = AK_Success;
        break;
      case 10:
        this->m_Params.fRandomValue[3] = *in_pValue;
        result = AK_Success;
        break;
      case 11:
        this->m_Params.bAutomation[3] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 20:
        this->m_Params.fBaseValue[4] = *in_pValue;
        result = AK_Success;
        break;
      case 21:
        this->m_Params.fRandomValue[4] = *in_pValue;
        result = AK_Success;
        break;
      case 22:
        this->m_Params.bAutomation[4] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 23:
        this->m_Params.fBaseValue[5] = *in_pValue;
        result = AK_Success;
        break;
      case 24:
        this->m_Params.fRandomValue[5] = *in_pValue;
        result = AK_Success;
        break;
      case 25:
        this->m_Params.bAutomation[5] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 26:
        v8 = powf(10.0, *in_pValue * 0.050000001);
        result = AK_Success;
        this->m_Params.fBaseValue[6] = v8;
        break;
      case 27:
        this->m_Params.fRandomValue[6] = *in_pValue;
        result = AK_Success;
        break;
      case 28:
        this->m_Params.bAutomation[6] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 40:
        if ( *(_WORD *)in_pValue )
        {
          v7 = 51;
          if ( *(_WORD *)in_pValue != 2 )
            v7 = 3;
          this->m_Params.uChannelMask = v7;
          result = AK_Success;
        }
        else
        {
          this->m_Params.uChannelMask = 4;
          result = AK_Success;
        }
        break;
      case 42:
        this->m_Params.fDuration = *in_pValue;
        result = AK_Success;
        break;
      case 43:
        this->m_Params.fDurationRdm = *in_pValue;
        result = AK_Success;
        break;
      case 44:
        this->m_Params.fMinDistance = *in_pValue;
        result = AK_Success;
        break;
      case 45:
        this->m_Params.fAttenuationRolloff = *in_pValue;
        result = AK_Success;
        break;
      case 46:
        this->m_Params.fDynamicRange = *in_pValue;
        result = AK_Success;
        break;
      case 48:
        this->m_Params.fPlaybackRate = *in_pValue;
        result = AK_Success;
        break;
      default:
        return 31;
    }
  }
  return result;
}

// File Line: 455
// RVA: 0xAD5230
void __fastcall CAkSoundSeedWindParams::SetChannelMask(CAkSoundSeedWindParams *this, unsigned int in_uChanMaskIndex)
{
  unsigned int v2; // eax

  if ( in_uChanMaskIndex )
  {
    v2 = 51;
    if ( in_uChanMaskIndex != 2 )
      v2 = 3;
    this->m_Params.uChannelMask = v2;
  }
  else
  {
    this->m_Params.uChannelMask = 4;
  }
}

