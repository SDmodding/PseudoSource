// File Line: 20
// RVA: 0xAD8F30
AK::IAkPluginParam *__fastcall CreateSoundSeedWooshParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 208ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable';
    result[1].vfptr = 0i64;
    result[2].vfptr = 0i64;
    result[3].vfptr = 0i64;
    result[4].vfptr = 0i64;
    result[5].vfptr = 0i64;
    result[6].vfptr = 0i64;
    result[7].vfptr = 0i64;
    result[8].vfptr = 0i64;
    result[20].vfptr = 0i64;
    result[21].vfptr = 0i64;
    result[22].vfptr = 0i64;
    LODWORD(result[23].vfptr) = 0;
    result[24].vfptr = 0i64;
    LODWORD(result[25].vfptr) = 0;
  }
  return result;
}

// File Line: 33
// RVA: 0xAD8FB0
void __fastcall CAkSoundSeedWooshParams::CAkSoundSeedWooshParams(CAkSoundSeedWooshParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable';
  this->m_Curves[0].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[0].m_ulArraySize = 0i64;
  this->m_Curves[1].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[1].m_ulArraySize = 0i64;
  this->m_Curves[2].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[2].m_ulArraySize = 0i64;
  this->m_Curves[3].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[3].m_ulArraySize = 0i64;
  this->m_pAllocator = 0i64;
  *(_QWORD *)&this->m_uChangeMask = 0i64;
  this->m_pDeflectors = 0i64;
  this->m_cPathPoints = 0;
  this->m_pPath = 0i64;
  this->m_fTotalPathDistance = 0.0;
}

// File Line: 39
// RVA: 0xAD92E0
void __fastcall CAkSoundSeedWooshParams::~CAkSoundSeedWooshParams(CAkSoundSeedWooshParams *this)
{
  AkWooshDeflectorParams *v1; // rdx
  CAkSoundSeedWooshParams *v2; // rsi
  signed __int64 v3; // rbx
  signed __int64 v4; // rdi

  v1 = this->m_pDeflectors;
  v2 = this;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable';
  if ( v1 )
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
  v3 = (signed __int64)v2->m_Curves;
  v4 = 4i64;
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
  if ( v2->m_pPath )
    ((void (*)(void))v2->m_pAllocator->vfptr->Free)();
  v2->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 52
// RVA: 0xAD9010
void __fastcall CAkSoundSeedWooshParams::CAkSoundSeedWooshParams(CAkSoundSeedWooshParams *this, CAkSoundSeedWooshParams *in_rCopy, AKRESULT *out_eResult)
{
  CAkSoundSeedWooshParams *v3; // rbx
  unsigned int v4; // esi
  AK::IAkPluginMemAlloc *v5; // rcx
  AKRESULT *v6; // r15
  CAkSoundSeedWooshParams *v7; // rbp
  int v8; // eax
  unsigned int v9; // eax
  __int64 v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // er9
  AkWooshDeflectorParams *v13; // rcx
  AkWooshDeflectorParams *v14; // rdx
  signed __int64 v15; // r8
  signed __int64 v16; // r14
  unsigned int v17; // edi
  unsigned int v18; // eax
  __int64 v19; // rax
  unsigned int v20; // eax
  AkWooshPathPoint *v21; // rcx
  AkWooshPathPoint *v22; // rdx
  signed __int64 v23; // r8

  v3 = this;
  v4 = 0;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable';
  this->m_Curves[0].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[0].m_ulArraySize = 0i64;
  this->m_Curves[1].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[1].m_ulArraySize = 0i64;
  this->m_Curves[2].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[2].m_ulArraySize = 0i64;
  this->m_Curves[3].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[3].m_ulArraySize = 0i64;
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
  v3->m_Params.fDynamicRange = in_rCopy->m_Params.fDynamicRange;
  v3->m_Params.fPlaybackRate = in_rCopy->m_Params.fPlaybackRate;
  v3->m_Params.iAnchorIndex = in_rCopy->m_Params.iAnchorIndex;
  v3->m_Params.eNoiseColor = in_rCopy->m_Params.eNoiseColor;
  v3->m_Params.fRandomSpeedX = in_rCopy->m_Params.fRandomSpeedX;
  v3->m_Params.fRandomSpeedY = in_rCopy->m_Params.fRandomSpeedY;
  v3->m_Params.uOversamplingFactor = in_rCopy->m_Params.uOversamplingFactor;
  v3->m_Params.fBaseValue[0] = in_rCopy->m_Params.fBaseValue[0];
  v3->m_Params.fBaseValue[1] = in_rCopy->m_Params.fBaseValue[1];
  v3->m_Params.fBaseValue[2] = in_rCopy->m_Params.fBaseValue[2];
  v3->m_Params.fBaseValue[3] = in_rCopy->m_Params.fBaseValue[3];
  v3->m_Params.fRandomValue[0] = in_rCopy->m_Params.fRandomValue[0];
  v3->m_Params.fRandomValue[1] = in_rCopy->m_Params.fRandomValue[1];
  v3->m_Params.fRandomValue[2] = in_rCopy->m_Params.fRandomValue[2];
  v3->m_Params.fRandomValue[3] = in_rCopy->m_Params.fRandomValue[3];
  *(_DWORD *)v3->m_Params.bAutomation = *(_DWORD *)in_rCopy->m_Params.bAutomation;
  v8 = *(_DWORD *)&in_rCopy->m_Params.bEnableDistanceBasedAttenuation;
  *(_QWORD *)&v3->m_uChangeMask = 15i64;
  v3->m_pDeflectors = 0i64;
  v3->m_cPathPoints = 0;
  v3->m_pPath = 0i64;
  *(_DWORD *)&v3->m_Params.bEnableDistanceBasedAttenuation = v8;
  v3->m_fTotalPathDistance = in_rCopy->m_fTotalPathDistance;
  if ( in_rCopy->m_pDeflectors )
  {
    v9 = in_rCopy->m_cDeflectors;
    if ( v9 )
    {
      v10 = (__int64)v5->vfptr->Malloc(v5, 12 * v9);
      v3->m_pDeflectors = (AkWooshDeflectorParams *)v10;
      if ( !v10 )
      {
        *v6 = 52;
        return;
      }
      v11 = v7->m_cDeflectors;
      v12 = 0;
      v3->m_cDeflectors = v11;
      if ( v11 )
      {
        do
        {
          v13 = v7->m_pDeflectors;
          v14 = v3->m_pDeflectors;
          v15 = v12++;
          v14[v15].fFrequency = v13[v15].fFrequency;
          v14[v15].fQFactor = v13[v15].fQFactor;
          v14[v15].fGain = v13[v15].fGain;
        }
        while ( v12 < v3->m_cDeflectors );
      }
    }
  }
  v16 = (signed __int64)v7->m_Curves;
  v17 = 0;
  do
  {
    if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                         &v3->m_Curves[v17],
                         *(AkRTPCGraphPointBase<float> **)v16,
                         *(_DWORD *)(v16 + 8),
                         0) == 52 )
      goto LABEL_16;
    ++v17;
    v16 += 16i64;
  }
  while ( v17 < 4 );
  if ( v7->m_pPath )
  {
    v18 = v7->m_cPathPoints;
    if ( v18 )
    {
      v19 = (__int64)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 12 * v18);
      v3->m_pPath = (AkWooshPathPoint *)v19;
      if ( !v19 )
      {
LABEL_16:
        *v6 = 52;
        return;
      }
      v20 = v7->m_cPathPoints;
      v3->m_cPathPoints = v20;
      if ( v20 )
      {
        do
        {
          v21 = v7->m_pPath;
          v22 = v3->m_pPath;
          v23 = v4++;
          v22[v23].fDistanceTravelled = v21[v23].fDistanceTravelled;
          v22[v23].fX = v21[v23].fX;
          v22[v23].fY = v21[v23].fY;
        }
        while ( v4 < v3->m_cPathPoints );
      }
    }
  }
}

// File Line: 116
// RVA: 0xAD9390
void __fastcall CAkSoundSeedWooshParams::Clone(CAkSoundSeedWooshParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAllocVtbl *v2; // rax
  AK::IAkPluginMemAlloc *v3; // rbx
  CAkSoundSeedWooshParams *v4; // rdi
  CAkSoundSeedWooshParams *v5; // rax
  __int64 v6; // rax
  AKRESULT out_eResult; // [rsp+38h] [rbp+10h]

  v2 = in_pAllocator->vfptr;
  v3 = in_pAllocator;
  v4 = this;
  out_eResult = 1;
  v5 = (CAkSoundSeedWooshParams *)v2->Malloc(in_pAllocator, 208ui64);
  if ( v5 )
  {
    CAkSoundSeedWooshParams::CAkSoundSeedWooshParams(v5, v4, &out_eResult);
    if ( v6 )
    {
      if ( out_eResult != 1 )
        (*(void (__fastcall **)(__int64, AK::IAkPluginMemAlloc *))(*(_QWORD *)v6 + 32i64))(v6, v3);
    }
  }
}

// File Line: 132
// RVA: 0xAD9400
__int64 __fastcall CAkSoundSeedWooshParams::Init(CAkSoundSeedWooshParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int64 result; // rax
  __int128 v7; // xmm1

  this->m_pAllocator = in_pAllocator;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkSoundSeedWooshParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  v4 = *(_OWORD *)&g_DefaultPreset_2.fDuration;
  v5 = *(_OWORD *)&g_DefaultPreset_2.fAttenuationRolloff;
  this->m_uChangeMask = 15;
  result = 1i64;
  *(_OWORD *)&this->m_Params.fDuration = v4;
  *(_OWORD *)&this->m_Params.fAttenuationRolloff = v5;
  v7 = *(_OWORD *)g_DefaultPreset_2.fBaseValue;
  *(_OWORD *)&this->m_Params.eNoiseColor = *(_OWORD *)&g_DefaultPreset_2.eNoiseColor;
  *(_OWORD *)this->m_Params.fBaseValue = v7;
  *(_QWORD *)&v7 = *(_QWORD *)g_DefaultPreset_2.bAutomation;
  *(_OWORD *)this->m_Params.fRandomValue = *(_OWORD *)g_DefaultPreset_2.fRandomValue;
  *(_QWORD *)this->m_Params.bAutomation = v7;
  return result;
}

// File Line: 148
// RVA: 0xAD9480
signed __int64 __fastcall CAkSoundSeedWooshParams::Term(CAkSoundSeedWooshParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkSoundSeedWooshParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 157
// RVA: 0xAD94C0
AKRESULT __fastcall CAkSoundSeedWooshParams::SetParamsBlock(CAkSoundSeedWooshParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkSoundSeedWooshParams *v3; // rbx
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
  v8 = (char *)in_pParamsBlock + 75;
  v3->m_Params.fMinDistance = v7;
  v9 = *(float *)(v8 - 61);
  io_ppData = v8;
  v3->m_Params.fAttenuationRolloff = v9;
  v3->m_Params.fDynamicRange = *(float *)(v8 - 57);
  v3->m_Params.fPlaybackRate = *(float *)(v8 - 53);
  v3->m_Params.eNoiseColor = *(unsigned __int16 *)(v8 - 49);
  v3->m_Params.fRandomSpeedX = *(float *)(v8 - 47);
  v3->m_Params.fRandomSpeedY = *(float *)(v8 - 43);
  v3->m_Params.bEnableDistanceBasedAttenuation = *(v8 - 39);
  v3->m_Params.uOversamplingFactor = *((unsigned __int16 *)v8 - 19);
  v3->m_Params.fBaseValue[0] = *((float *)v8 - 9);
  v3->m_Params.fRandomValue[0] = *((float *)v8 - 8);
  v3->m_Params.bAutomation[0] = *(v8 - 28);
  v3->m_Params.fBaseValue[1] = *(float *)(v8 - 27);
  v3->m_Params.fRandomValue[1] = *(float *)(v8 - 23);
  v3->m_Params.bAutomation[1] = *(v8 - 19);
  v3->m_Params.fBaseValue[2] = *(float *)(v8 - 18);
  v3->m_Params.fRandomValue[2] = *(float *)(v8 - 14);
  v3->m_Params.bAutomation[2] = *(v8 - 10);
  v3->m_Params.fBaseValue[3] = *(float *)(v8 - 9);
  v3->m_Params.fRandomValue[3] = *(float *)(v8 - 5);
  v3->m_Params.bAutomation[3] = *(v8 - 1);
  v3->m_Params.fBaseValue[3] = powf(10.0, v3->m_Params.fBaseValue[3] * 0.050000001);
  v3->m_uChangeMask = 15;
  result = CAkSoundSeedWooshParams::ReadDeflectors(v3, (const void **)&io_ppData);
  if ( result == 1 )
  {
    result = CAkSoundSeedWooshParams::ReadAllCurves(v3, (const void **)&io_ppData);
    if ( result == 1 )
    {
      v11 = CAkSoundSeedWooshParams::ReadPath(v3, (const void **)&io_ppData);
      v12 = 1;
      if ( v11 != 1 )
        v12 = v11;
      result = v12;
    }
  }
  return result;
}

// File Line: 202
// RVA: 0xAD9A10
signed __int64 __fastcall CAkSoundSeedWooshParams::ReadDeflectors(CAkSoundSeedWooshParams *this, const void **io_ppData)
{
  signed __int16 *v2; // rsi
  const void **v3; // r14
  AkWooshDeflectorParams *v4; // rdx
  int v5; // eax
  unsigned int v6; // ebp
  float *v7; // rsi
  CAkSoundSeedWooshParams *v8; // rdi
  unsigned int v9; // ebx
  __int64 v10; // rax
  float v12; // xmm0_4
  signed __int64 v13; // rbx

  v2 = (signed __int16 *)*io_ppData;
  v3 = io_ppData;
  v4 = this->m_pDeflectors;
  v5 = *v2;
  v6 = 0;
  v7 = (float *)(v2 + 2);
  this->m_Params.iAnchorIndex = v5;
  v8 = this;
  v9 = *((unsigned __int16 *)v7 - 1);
  if ( v4 && this->m_cDeflectors != *((unsigned __int16 *)v7 - 1) )
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
      v10 = (__int64)v8->m_pAllocator->vfptr->Malloc(v8->m_pAllocator, 12 * v9);
      v8->m_pDeflectors = (AkWooshDeflectorParams *)v10;
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
        v7 += 3;
        v13 = v6;
        v8->m_pDeflectors[v13].fFrequency = v12;
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

// File Line: 245
// RVA: 0xAD9D30
signed __int64 __fastcall CAkSoundSeedWooshParams::ReadPath(CAkSoundSeedWooshParams *this, const void **io_ppData)
{
  unsigned __int16 *v2; // rbx
  const void **v3; // r15
  AkWooshPathPoint *v4; // rdx
  unsigned int v5; // eax
  unsigned int v6; // esi
  float *v7; // rbx
  CAkSoundSeedWooshParams *v8; // rdi
  unsigned int v9; // er14
  __int64 v10; // rax
  float v12; // xmm0_4
  signed __int64 v13; // rax
  signed __int64 v14; // rcx

  v2 = (unsigned __int16 *)*io_ppData;
  v3 = io_ppData;
  v4 = this->m_pPath;
  v5 = *v2;
  v6 = 0;
  v7 = (float *)(v2 + 3);
  this->m_fTotalPathDistance = *(v7 - 1);
  v8 = this;
  v9 = v5;
  if ( v4 && this->m_cPathPoints != v5 )
  {
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
    v8->m_pPath = 0i64;
    v8->m_cPathPoints = 0;
  }
  if ( v9 )
  {
    v8->m_cPathPoints = v9;
    if ( !v8->m_pPath )
    {
      v10 = (__int64)v8->m_pAllocator->vfptr->Malloc(v8->m_pAllocator, 12 * v9);
      v8->m_pPath = (AkWooshPathPoint *)v10;
      if ( !v10 )
      {
        v8->m_cPathPoints = 0;
        return 52i64;
      }
    }
    if ( v8->m_cPathPoints > 0 )
    {
      do
      {
        v12 = *v7;
        v13 = v6++;
        v14 = v13;
        v7 += 3;
        v8->m_pPath[v14].fDistanceTravelled = v12;
        v8->m_pPath[v14].fX = *(v7 - 2);
        v8->m_pPath[v14].fY = *(v7 - 1);
      }
      while ( v6 < v8->m_cPathPoints );
    }
  }
  *v3 = v7;
  return 1i64;
}

// File Line: 288
// RVA: 0xAD9B70
signed __int64 __fastcall CAkSoundSeedWooshParams::ReadAllCurves(CAkSoundSeedWooshParams *this, const void **io_ppData)
{
  const void **v2; // r15
  CAkSoundSeedWooshParams *v3; // r14
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v4; // rbx
  signed __int64 v5; // rdi
  __int16 v6; // si
  signed __int64 v7; // rbx
  signed int v8; // ebp
  int v9; // ecx
  signed __int64 v10; // rax
  unsigned __int16 v11; // di

  v2 = io_ppData;
  v3 = this;
  v4 = this->m_Curves;
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
  v6 = 0;
  v7 = (signed __int64)*v2 + 2;
  v8 = *(unsigned __int16 *)*v2;
  if ( v8 <= 0 )
  {
LABEL_18:
    *v2 = (const void *)v7;
    return 1i64;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)v7;
    v10 = 0i64;
    if ( *(_DWORD *)v7 )
    {
      switch ( v9 )
      {
        case 20:
          v10 = 1i64;
          break;
        case 23:
          v10 = 2i64;
          break;
        case 26:
          v10 = 3i64;
          break;
      }
    }
    else
    {
      v10 = 0i64;
    }
    v11 = *(_WORD *)(v7 + 4);
    v7 += 6i64;
    if ( !v11 )
      goto LABEL_17;
    if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                         &v3->m_Curves[v10],
                         (AkRTPCGraphPointBase<float> *)v7,
                         v11,
                         0) == 52 )
      return 52i64;
    v7 += 12i64 * v11;
LABEL_17:
    if ( (unsigned __int16)++v6 >= v8 )
      goto LABEL_18;
  }
}

// File Line: 310
// RVA: 0xAD9C80
signed __int64 __fastcall CAkSoundSeedWooshParams::ReadCurve(CAkSoundSeedWooshParams *this, const void **io_ppData)
{
  char *v2; // rbx
  signed __int64 v3; // rax
  const void **v4; // rsi
  int v5; // er8
  unsigned __int16 v6; // di
  AkRTPCGraphPointBase<float> *v7; // rbx
  signed __int64 result; // rax

  v2 = (char *)*io_ppData;
  v3 = 0i64;
  v4 = io_ppData;
  v5 = *(_DWORD *)*io_ppData;
  if ( v5 )
  {
    switch ( v5 )
    {
      case 20:
        v3 = 1i64;
        break;
      case 23:
        v3 = 2i64;
        break;
      case 26:
        v3 = 3i64;
        break;
    }
  }
  v6 = *((_WORD *)v2 + 2);
  v7 = (AkRTPCGraphPointBase<float> *)(v2 + 6);
  if ( v6 )
  {
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(&this->m_Curves[v3], v7, v6, 0);
    if ( (_DWORD)result == 52 )
      return result;
    v7 += v6;
  }
  *v4 = v7;
  return 1i64;
}

// File Line: 337
// RVA: 0xAD9EA0
signed __int64 __fastcall CAkSoundSeedWooshParams::CurveIDToIndex(CAkSoundSeedWooshParams *this, unsigned int in_uCurveID)
{
  if ( in_uCurveID )
  {
    switch ( in_uCurveID )
    {
      case 0x14u:
        return 1i64;
      case 0x17u:
        return 2i64;
      case 0x1Au:
        return 3i64;
    }
  }
  return 0i64;
}

// File Line: 365
// RVA: 0xAD9670
AKRESULT __fastcall CAkSoundSeedWooshParams::SetParam(CAkSoundSeedWooshParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkSoundSeedWooshParams *v4; // rbx
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
      case 21:
        this->m_Params.fBaseValue[1] = *(float *)in_pValue;
        return 1;
      case 22:
        this->m_Params.fRandomValue[1] = *(float *)in_pValue;
        return 1;
      case 23:
        this->m_Params.bAutomation[1] = *(_BYTE *)in_pValue;
        return 1;
      case 24:
        this->m_Params.fBaseValue[2] = *(float *)in_pValue;
        return 1;
      case 25:
        this->m_Params.fRandomValue[2] = *(float *)in_pValue;
        return 1;
      case 26:
        this->m_Params.bAutomation[2] = *(_BYTE *)in_pValue;
        return 1;
      case 27:
        v8 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = 1;
        v4->m_Params.fBaseValue[3] = v8;
        return result;
      case 28:
        this->m_Params.fRandomValue[3] = *(float *)in_pValue;
        return 1;
      case 29:
        this->m_Params.bAutomation[3] = *(_BYTE *)in_pValue;
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
        this->m_Params.eNoiseColor = *(unsigned __int16 *)in_pValue;
        return 1;
      case 48:
        this->m_Params.fRandomSpeedX = *(float *)in_pValue;
        return 1;
      case 49:
        this->m_Params.fRandomSpeedY = *(float *)in_pValue;
        return 1;
      case 50:
        this->m_Params.bEnableDistanceBasedAttenuation = *(_BYTE *)in_pValue;
        return 1;
      case 51:
        this->m_Params.fPlaybackRate = *(float *)in_pValue;
        return 1;
      case 52:
        this->m_Params.uOversamplingFactor = *(unsigned __int16 *)in_pValue;
        return 1;
      case 53:
        this->m_Params.fDynamicRange = *(float *)in_pValue;
        return 1;
      default:
        return 31;
    }
    return 31;
  }
  this->m_uChangeMask |= 7u;
  v6 = CAkSoundSeedWooshParams::ReadDeflectors(this, (const void **)&io_ppData);
  if ( v6 == 1 )
  {
    v6 = CAkSoundSeedWooshParams::ReadAllCurves(v4, (const void **)&io_ppData);
    if ( v6 == 1 )
      return CAkSoundSeedWooshParams::ReadPath(v4, (const void **)&io_ppData);
  }
  return v6;
}

// File Line: 512
// RVA: 0xAD9E70
void __fastcall CAkSoundSeedWooshParams::SetChannelMask(CAkSoundSeedWooshParams *this, unsigned int in_uChanMaskIndex)
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

