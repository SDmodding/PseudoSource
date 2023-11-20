// File Line: 20
// RVA: 0xAD4370
AK::IAkPluginParam *__fastcall CreateSoundSeedWindParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 240ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable';
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
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable';
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
  AkWindDeflectorParams *v1; // rdx
  CAkSoundSeedWindParams *v2; // rsi
  signed __int64 v3; // rbx
  signed __int64 v4; // rdi

  v1 = this->m_pDeflectors;
  v2 = this;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable';
  if ( v1 )
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
  v3 = (signed __int64)v2->m_Curves;
  v4 = 7i64;
  do
  {
    if ( *(_QWORD *)v3 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, *(void **)v3);
      *(_QWORD *)v3 = 0i64;
    }
    *(_QWORD *)(v3 + 8) = 0i64;
    v3 += 16i64;
    --v4;
  }
  while ( v4 );
  v2->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 46
// RVA: 0xAD4470
void __fastcall CAkSoundSeedWindParams::CAkSoundSeedWindParams(CAkSoundSeedWindParams *this, CAkSoundSeedWindParams *in_rCopy, AKRESULT *out_eResult)
{
  CAkSoundSeedWindParams *v3; // rdi
  unsigned int v4; // ebx
  AK::IAkPluginMemAlloc *v5; // rcx
  AKRESULT *v6; // r14
  CAkSoundSeedWindParams *v7; // rsi
  int v8; // eax
  unsigned int v9; // eax
  __int64 v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // er9
  __int64 v13; // rax
  AkWindDeflectorParams *v14; // rcx
  _DWORD *v15; // r8
  signed __int64 v16; // rsi

  v3 = this;
  v4 = 0;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWindParams::`vftable';
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
  *out_eResult = 1;
  v5 = in_rCopy->m_pAllocator;
  v6 = out_eResult;
  v3->m_pAllocator = v5;
  v7 = in_rCopy;
  v3->m_Params.fDuration = in_rCopy->m_Params.fDuration;
  v3->m_Params.fDurationRdm = in_rCopy->m_Params.fDurationRdm;
  v3->m_Params.uChannelMask = in_rCopy->m_Params.uChannelMask;
  v3->m_Params.fMinDistance = in_rCopy->m_Params.fMinDistance;
  v3->m_Params.fAttenuationRolloff = in_rCopy->m_Params.fAttenuationRolloff;
  v3->m_Params.fMaxDistance = in_rCopy->m_Params.fMaxDistance;
  v3->m_Params.fDynamicRange = in_rCopy->m_Params.fDynamicRange;
  v3->m_Params.fPlaybackRate = in_rCopy->m_Params.fPlaybackRate;
  v3->m_Params.fBaseValue[0] = in_rCopy->m_Params.fBaseValue[0];
  v3->m_Params.fBaseValue[1] = in_rCopy->m_Params.fBaseValue[1];
  v3->m_Params.fBaseValue[2] = in_rCopy->m_Params.fBaseValue[2];
  v3->m_Params.fBaseValue[3] = in_rCopy->m_Params.fBaseValue[3];
  v3->m_Params.fBaseValue[4] = in_rCopy->m_Params.fBaseValue[4];
  v3->m_Params.fBaseValue[5] = in_rCopy->m_Params.fBaseValue[5];
  v3->m_Params.fBaseValue[6] = in_rCopy->m_Params.fBaseValue[6];
  v3->m_Params.fRandomValue[0] = in_rCopy->m_Params.fRandomValue[0];
  v3->m_Params.fRandomValue[1] = in_rCopy->m_Params.fRandomValue[1];
  v3->m_Params.fRandomValue[2] = in_rCopy->m_Params.fRandomValue[2];
  v3->m_Params.fRandomValue[3] = in_rCopy->m_Params.fRandomValue[3];
  v3->m_Params.fRandomValue[4] = in_rCopy->m_Params.fRandomValue[4];
  v3->m_Params.fRandomValue[5] = in_rCopy->m_Params.fRandomValue[5];
  v3->m_Params.fRandomValue[6] = in_rCopy->m_Params.fRandomValue[6];
  *(_DWORD *)v3->m_Params.bAutomation = *(_DWORD *)in_rCopy->m_Params.bAutomation;
  v8 = *(_DWORD *)&in_rCopy->m_Params.bAutomation[4];
  *(_QWORD *)&v3->m_uChangeMask = 63i64;
  *(_DWORD *)&v3->m_Params.bAutomation[4] = v8;
  v3->m_pDeflectors = 0i64;
  if ( in_rCopy->m_pDeflectors )
  {
    v9 = in_rCopy->m_cDeflectors;
    if ( v9 )
    {
      v10 = (__int64)v5->vfptr->Malloc(v5, 20 * v9);
      v3->m_pDeflectors = (AkWindDeflectorParams *)v10;
      if ( !v10 )
        goto LABEL_10;
      v11 = v7->m_cDeflectors;
      v12 = 0;
      v3->m_cDeflectors = v11;
      if ( v11 )
      {
        do
        {
          v13 = v12++;
          v14 = v7->m_pDeflectors;
          v15 = (_DWORD *)&v3->m_pDeflectors[v13].fDistance;
          *v15 = LODWORD(v14[v13].fDistance);
          v15[1] = LODWORD(v14[v13].fAngle);
          v15[2] = LODWORD(v14[v13].fFrequency);
          v15[3] = LODWORD(v14[v13].fQFactor);
          v15[4] = LODWORD(v14[v13].fGain);
        }
        while ( v12 < v3->m_cDeflectors );
      }
    }
  }
  v16 = (signed __int64)v7->m_Curves;
  while ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                          &v3->m_Curves[v4],
                          *(AkRTPCGraphPointBase<float> **)v16,
                          *(_DWORD *)(v16 + 8),
                          0) != 52 )
  {
    ++v4;
    v16 += 16i64;
    if ( v4 >= 7 )
      return;
  }
LABEL_10:
  *v6 = 52;
}

// File Line: 88
// RVA: 0xAD47B0
void __fastcall CAkSoundSeedWindParams::Clone(CAkSoundSeedWindParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAllocVtbl *v2; // rax
  AK::IAkPluginMemAlloc *v3; // rbx
  CAkSoundSeedWindParams *v4; // rdi
  CAkSoundSeedWindParams *v5; // rax
  __int64 v6; // rax
  AKRESULT out_eResult; // [rsp+38h] [rbp+10h]

  v2 = in_pAllocator->vfptr;
  v3 = in_pAllocator;
  v4 = this;
  out_eResult = 1;
  v5 = (CAkSoundSeedWindParams *)v2->Malloc(in_pAllocator, 240ui64);
  if ( v5 )
  {
    CAkSoundSeedWindParams::CAkSoundSeedWindParams(v5, v4, &out_eResult);
    if ( v6 )
    {
      if ( out_eResult != 1 )
        (*(void (__fastcall **)(__int64, AK::IAkPluginMemAlloc *))(*(_QWORD *)v6 + 32i64))(v6, v3);
    }
  }
}

// File Line: 104
// RVA: 0xAD4820
__int64 __fastcall CAkSoundSeedWindParams::Init(CAkSoundSeedWindParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
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
signed __int64 __fastcall CAkSoundSeedWindParams::Term(CAkSoundSeedWindParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkSoundSeedWindParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 129
// RVA: 0xAD48F0
AKRESULT __fastcall CAkSoundSeedWindParams::SetParamsBlock(CAkSoundSeedWindParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkSoundSeedWindParams *v3; // rbx
  unsigned int v4; // eax
  int v5; // ecx
  signed int v6; // eax
  float v7; // xmm0_4
  char *v8; // rdx
  float v9; // xmm1_4
  AKRESULT result; // eax
  AKRESULT v11; // eax
  AKRESULT v12; // ecx
  void *io_ppData; // [rsp+30h] [rbp+8h]

  v3 = this;
  this->m_Params.fDuration = *(float *)in_pParamsBlock;
  this->m_Params.fDurationRdm = *((float *)in_pParamsBlock + 1);
  v4 = *((unsigned __int16 *)in_pParamsBlock + 4);
  v5 = *((unsigned __int16 *)in_pParamsBlock + 4);
  v3->m_Params.uChannelMask = v4;
  if ( v4 )
  {
    v6 = 51;
    if ( v5 != 2 )
      v6 = 3;
    v3->m_Params.uChannelMask = v6;
  }
  else
  {
    v3->m_Params.uChannelMask = 4;
  }
  v7 = *(float *)((char *)in_pParamsBlock + 10);
  v8 = (char *)in_pParamsBlock + 89;
  v3->m_Params.fMinDistance = v7;
  v9 = *(float *)(v8 - 75);
  io_ppData = v8;
  v3->m_Params.fAttenuationRolloff = v9;
  v3->m_Params.fDynamicRange = *(float *)(v8 - 71);
  v3->m_Params.fPlaybackRate = *(float *)(v8 - 67);
  v3->m_Params.fBaseValue[0] = *(float *)(v8 - 63);
  v3->m_Params.fRandomValue[0] = *(float *)(v8 - 59);
  v3->m_Params.bAutomation[0] = *(v8 - 55);
  v3->m_Params.fBaseValue[1] = *(float *)(v8 - 54);
  v3->m_Params.fRandomValue[1] = *(float *)(v8 - 50);
  v3->m_Params.bAutomation[1] = *(v8 - 46);
  v3->m_Params.fBaseValue[2] = *(float *)(v8 - 45);
  v3->m_Params.fRandomValue[2] = *(float *)(v8 - 41);
  v3->m_Params.bAutomation[2] = *(v8 - 37);
  v3->m_Params.fBaseValue[3] = *((float *)v8 - 9);
  v3->m_Params.fRandomValue[3] = *((float *)v8 - 8);
  v3->m_Params.bAutomation[3] = *(v8 - 28);
  v3->m_Params.fBaseValue[4] = *(float *)(v8 - 27);
  v3->m_Params.fRandomValue[4] = *(float *)(v8 - 23);
  v3->m_Params.bAutomation[4] = *(v8 - 19);
  v3->m_Params.fBaseValue[5] = *(float *)(v8 - 18);
  v3->m_Params.fRandomValue[5] = *(float *)(v8 - 14);
  v3->m_Params.bAutomation[5] = *(v8 - 10);
  v3->m_Params.fBaseValue[6] = *(float *)(v8 - 9);
  v3->m_Params.fRandomValue[6] = *(float *)(v8 - 5);
  v3->m_Params.bAutomation[6] = *(v8 - 1);
  v3->m_Params.fBaseValue[6] = powf(10.0, v3->m_Params.fBaseValue[6] * 0.050000001);
  v3->m_uChangeMask = 63;
  result = CAkSoundSeedWindParams::ReadDeflectors(v3, (const void **)&io_ppData);
  if ( result == 1 )
  {
    v11 = CAkSoundSeedWindParams::ReadAllCurves(v3, (const void **)&io_ppData);
    v12 = 1;
    if ( v11 != 1 )
      v12 = v11;
    result = v12;
  }
  return result;
}

// File Line: 164
// RVA: 0xAD4F10
signed __int64 __fastcall CAkSoundSeedWindParams::ReadDeflectors(CAkSoundSeedWindParams *this, const void **io_ppData)
{
  unsigned __int16 *v2; // rdi
  const void **v3; // r14
  AkWindDeflectorParams *v4; // rdx
  unsigned int v5; // eax
  unsigned int v6; // ebp
  float *v7; // rdi
  CAkSoundSeedWindParams *v8; // rsi
  unsigned int v9; // ebx
  __int64 v10; // rax
  float v12; // xmm0_4
  signed __int64 v13; // rbx

  v2 = (unsigned __int16 *)*io_ppData;
  v3 = io_ppData;
  v4 = this->m_pDeflectors;
  v5 = *v2;
  v6 = 0;
  v7 = (float *)(v2 + 3);
  this->m_Params.fMaxDistance = *(v7 - 1);
  v8 = this;
  v9 = v5;
  if ( v4 && this->m_cDeflectors != v5 )
  {
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
    v8->m_pDeflectors = 0i64;
    v8->m_cDeflectors = 0;
  }
  if ( v9 )
  {
    v8->m_cDeflectors = v9;
    if ( !v8->m_pDeflectors )
    {
      v10 = (__int64)v8->m_pAllocator->vfptr->Malloc(v8->m_pAllocator, 20 * v9);
      v8->m_pDeflectors = (AkWindDeflectorParams *)v10;
      if ( !v10 )
      {
        v8->m_cDeflectors = 0;
        return 52i64;
      }
    }
    if ( v8->m_cDeflectors > 0 )
    {
      do
      {
        v12 = *v7;
        v7 += 5;
        v13 = v6;
        v8->m_pDeflectors[v13].fDistance = v12;
        v8->m_pDeflectors[v13].fAngle = *(v7 - 4);
        v8->m_pDeflectors[v13].fFrequency = *(v7 - 3);
        v8->m_pDeflectors[v13].fQFactor = *(v7 - 2);
        ++v6;
        v8->m_pDeflectors[v13].fGain = powf(10.0, *(v7 - 1) * 0.050000001);
      }
      while ( v6 < v8->m_cDeflectors );
    }
  }
  *v3 = v7;
  return 1i64;
}

// File Line: 208
// RVA: 0xAD50A0
signed __int64 __fastcall CAkSoundSeedWindParams::ReadAllCurves(CAkSoundSeedWindParams *this, const void **io_ppData)
{
  const void **v2; // r12
  CAkSoundSeedWindParams *v3; // r15
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v4; // rbx
  signed __int64 v5; // rdi
  __int16 v6; // si
  signed __int64 v7; // rbx
  signed int v8; // er14
  unsigned __int16 v9; // bp
  unsigned int v10; // edx
  unsigned int v11; // eax

  v2 = io_ppData;
  v3 = this;
  v4 = this->m_Curves;
  v5 = 7i64;
  v6 = 0;
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
  v7 = (signed __int64)*v2 + 2;
  v8 = *(unsigned __int16 *)*v2;
  if ( v8 <= 0 )
  {
LABEL_10:
    *v2 = (const void *)v7;
    return 1i64;
  }
  while ( 1 )
  {
    v9 = *(_WORD *)(v7 + 4);
    v10 = *(_DWORD *)v7;
    v7 += 6i64;
    if ( v9 )
      break;
LABEL_9:
    if ( (unsigned __int16)++v6 >= v8 )
      goto LABEL_10;
  }
  v11 = CAkSoundSeedWindParams::CurveIDToIndex(v3, v10);
  if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                       &v3->m_Curves[v11],
                       (AkRTPCGraphPointBase<float> *)v7,
                       v9,
                       0) != 52 )
  {
    v7 += 12i64 * v9;
    goto LABEL_9;
  }
  return 52i64;
}

// File Line: 230
// RVA: 0xAD51A0
signed __int64 __fastcall CAkSoundSeedWindParams::ReadCurve(CAkSoundSeedWindParams *this, const void **io_ppData)
{
  char *v2; // rdi
  const void **v3; // r14
  CAkSoundSeedWindParams *v4; // rbp
  unsigned __int16 v5; // si
  unsigned int v6; // edx
  AkRTPCGraphPointBase<float> *v7; // rdi
  unsigned int v8; // eax
  signed __int64 result; // rax

  v2 = (char *)*io_ppData;
  v3 = io_ppData;
  v4 = this;
  v5 = *((_WORD *)*io_ppData + 2);
  v6 = *(_DWORD *)*io_ppData;
  v7 = (AkRTPCGraphPointBase<float> *)(v2 + 6);
  if ( v5 )
  {
    v8 = CAkSoundSeedWindParams::CurveIDToIndex(this, v6);
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(&v4->m_Curves[v8], v7, v5, 0);
    if ( (_DWORD)result == 52 )
      return result;
    v7 += v5;
  }
  *v3 = v7;
  return 1i64;
}

// File Line: 257
// RVA: 0xAD5260
signed __int64 __fastcall CAkSoundSeedWindParams::CurveIDToIndex(CAkSoundSeedWindParams *this, unsigned int in_uCurveID)
{
  unsigned int v2; // er8
  signed __int64 result; // rax

  v2 = 0;
  switch ( 0x40000000 )
  {
    case 3:
      result = 1i64;
      break;
    case 6:
      result = 2i64;
      break;
    case 9:
      result = 3i64;
      break;
    case 20:
      result = 4i64;
      break;
    case 23:
      result = 5i64;
      break;
    case 26:
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
AKRESULT __fastcall CAkSoundSeedWindParams::SetParam(CAkSoundSeedWindParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkSoundSeedWindParams *v4; // rbx
  AKRESULT result; // eax
  AKRESULT v6; // edi
  unsigned int v7; // eax
  float v8; // xmm0_4
  void *io_ppData; // [rsp+40h] [rbp+18h]

  io_ppData = (void *)in_pValue;
  v4 = this;
  if ( !in_pValue )
    return 31;
  v6 = 1;
  if ( in_ParamID > 0x7FFF )
    return 31;
  if ( in_ParamID != 0x7FFF )
  {
    switch ( in_ParamID + 1 )
    {
      case 0:
        return v6;
      case 1:
        this->m_Params.fBaseValue[0] = *(float *)in_pValue;
        return 1;
      case 2:
        this->m_Params.fRandomValue[0] = *(float *)in_pValue;
        return 1;
      case 3:
        this->m_Params.bAutomation[0] = *(_BYTE *)in_pValue;
        return 1;
      case 4:
        this->m_uChangeMask |= 0x10u;
        this->m_Params.fBaseValue[1] = *(float *)in_pValue;
        return 1;
      case 5:
        this->m_Params.fRandomValue[1] = *(float *)in_pValue;
        return 1;
      case 6:
        this->m_Params.bAutomation[1] = *(_BYTE *)in_pValue;
        return 1;
      case 7:
        this->m_Params.fBaseValue[2] = *(float *)in_pValue;
        return 1;
      case 8:
        this->m_Params.fRandomValue[2] = *(float *)in_pValue;
        return 1;
      case 9:
        this->m_Params.bAutomation[2] = *(_BYTE *)in_pValue;
        return 1;
      case 10:
        this->m_Params.fBaseValue[3] = *(float *)in_pValue;
        return 1;
      case 11:
        this->m_Params.fRandomValue[3] = *(float *)in_pValue;
        return 1;
      case 12:
        this->m_Params.bAutomation[3] = *(_BYTE *)in_pValue;
        return 1;
      case 21:
        this->m_Params.fBaseValue[4] = *(float *)in_pValue;
        return 1;
      case 22:
        this->m_Params.fRandomValue[4] = *(float *)in_pValue;
        return 1;
      case 23:
        this->m_Params.bAutomation[4] = *(_BYTE *)in_pValue;
        return 1;
      case 24:
        this->m_Params.fBaseValue[5] = *(float *)in_pValue;
        return 1;
      case 25:
        this->m_Params.fRandomValue[5] = *(float *)in_pValue;
        return 1;
      case 26:
        this->m_Params.bAutomation[5] = *(_BYTE *)in_pValue;
        return 1;
      case 27:
        v8 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = 1;
        v4->m_Params.fBaseValue[6] = v8;
        return result;
      case 28:
        this->m_Params.fRandomValue[6] = *(float *)in_pValue;
        return 1;
      case 29:
        this->m_Params.bAutomation[6] = *(_BYTE *)in_pValue;
        return 1;
      case 41:
        if ( *(_WORD *)in_pValue )
        {
          v7 = 51;
          if ( *(_WORD *)in_pValue != 2 )
            v7 = 3;
          this->m_Params.uChannelMask = v7;
          result = 1;
        }
        else
        {
          this->m_Params.uChannelMask = 4;
          result = 1;
        }
        return result;
      case 43:
        this->m_Params.fDuration = *(float *)in_pValue;
        return 1;
      case 44:
        this->m_Params.fDurationRdm = *(float *)in_pValue;
        return 1;
      case 45:
        this->m_Params.fMinDistance = *(float *)in_pValue;
        return 1;
      case 46:
        this->m_Params.fAttenuationRolloff = *(float *)in_pValue;
        return 1;
      case 47:
        this->m_Params.fDynamicRange = *(float *)in_pValue;
        return 1;
      case 49:
        this->m_Params.fPlaybackRate = *(float *)in_pValue;
        return 1;
      default:
        return 31;
    }
    return 31;
  }
  this->m_uChangeMask |= 0x17u;
  v6 = CAkSoundSeedWindParams::ReadDeflectors(this, (const void **)&io_ppData);
  if ( v6 == 1 )
    return CAkSoundSeedWindParams::ReadAllCurves(v4, (const void **)&io_ppData);
  return v6;
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

