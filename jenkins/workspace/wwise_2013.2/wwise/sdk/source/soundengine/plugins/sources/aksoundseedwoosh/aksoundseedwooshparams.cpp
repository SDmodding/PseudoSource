// File Line: 20
// RVA: 0xAD8F30
AK::IAkPluginParam *__fastcall CreateSoundSeedWooshParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 208i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable;
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
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable;
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
  AkWooshDeflectorParams *m_pDeflectors; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_Curves; // rbx
  __int64 v4; // rdi

  m_pDeflectors = this->m_pDeflectors;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable;
  if ( m_pDeflectors )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
  m_Curves = this->m_Curves;
  v4 = 4i64;
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
  if ( this->m_pPath )
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 52
// RVA: 0xAD9010
void __fastcall CAkSoundSeedWooshParams::CAkSoundSeedWooshParams(
        CAkSoundSeedWooshParams *this,
        CAkSoundSeedWooshParams *in_rCopy,
        AKRESULT *out_eResult)
{
  unsigned int v4; // esi
  AK::IAkPluginMemAlloc *m_pAllocator; // rcx
  int v8; // eax
  unsigned int m_cDeflectors; // eax
  AkWooshDeflectorParams *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // r9d
  AkWooshDeflectorParams *m_pDeflectors; // rcx
  AkWooshDeflectorParams *v14; // rdx
  __int64 v15; // r8
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_Curves; // r14
  unsigned int i; // edi
  unsigned int m_cPathPoints; // eax
  AkWooshPathPoint *v19; // rax
  unsigned int v20; // eax
  AkWooshPathPoint *m_pPath; // rcx
  AkWooshPathPoint *v22; // rdx
  __int64 v23; // r8

  v4 = 0;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkSoundSeedWooshParams::`vftable;
  this->m_Curves[0].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[0].m_ulArraySize = 0i64;
  this->m_Curves[1].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[1].m_ulArraySize = 0i64;
  this->m_Curves[2].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[2].m_ulArraySize = 0i64;
  this->m_Curves[3].m_pArrayGraphPoints = 0i64;
  *(_QWORD *)&this->m_Curves[3].m_ulArraySize = 0i64;
  *out_eResult = AK_Success;
  m_pAllocator = in_rCopy->m_pAllocator;
  this->m_pAllocator = m_pAllocator;
  this->m_Params.fDuration = in_rCopy->m_Params.fDuration;
  this->m_Params.fDurationRdm = in_rCopy->m_Params.fDurationRdm;
  this->m_Params.uChannelMask = in_rCopy->m_Params.uChannelMask;
  this->m_Params.fMinDistance = in_rCopy->m_Params.fMinDistance;
  this->m_Params.fAttenuationRolloff = in_rCopy->m_Params.fAttenuationRolloff;
  this->m_Params.fDynamicRange = in_rCopy->m_Params.fDynamicRange;
  this->m_Params.fPlaybackRate = in_rCopy->m_Params.fPlaybackRate;
  this->m_Params.iAnchorIndex = in_rCopy->m_Params.iAnchorIndex;
  this->m_Params.eNoiseColor = in_rCopy->m_Params.eNoiseColor;
  this->m_Params.fRandomSpeedX = in_rCopy->m_Params.fRandomSpeedX;
  this->m_Params.fRandomSpeedY = in_rCopy->m_Params.fRandomSpeedY;
  this->m_Params.uOversamplingFactor = in_rCopy->m_Params.uOversamplingFactor;
  *(_OWORD *)this->m_Params.fBaseValue = *(_OWORD *)in_rCopy->m_Params.fBaseValue;
  *(_OWORD *)this->m_Params.fRandomValue = *(_OWORD *)in_rCopy->m_Params.fRandomValue;
  *(_DWORD *)this->m_Params.bAutomation = *(_DWORD *)in_rCopy->m_Params.bAutomation;
  v8 = *(_DWORD *)&in_rCopy->m_Params.bEnableDistanceBasedAttenuation;
  *(_QWORD *)&this->m_uChangeMask = 15i64;
  this->m_pDeflectors = 0i64;
  this->m_cPathPoints = 0;
  this->m_pPath = 0i64;
  *(_DWORD *)&this->m_Params.bEnableDistanceBasedAttenuation = v8;
  this->m_fTotalPathDistance = in_rCopy->m_fTotalPathDistance;
  if ( in_rCopy->m_pDeflectors )
  {
    m_cDeflectors = in_rCopy->m_cDeflectors;
    if ( m_cDeflectors )
    {
      v10 = (AkWooshDeflectorParams *)m_pAllocator->vfptr->Malloc(m_pAllocator, 12 * m_cDeflectors);
      this->m_pDeflectors = v10;
      if ( !v10 )
      {
        *out_eResult = AK_InsufficientMemory;
        return;
      }
      v11 = in_rCopy->m_cDeflectors;
      v12 = 0;
      for ( this->m_cDeflectors = v11; v12 < this->m_cDeflectors; v14[v15].fGain = m_pDeflectors[v15].fGain )
      {
        m_pDeflectors = in_rCopy->m_pDeflectors;
        v14 = this->m_pDeflectors;
        v15 = v12++;
        v14[v15].fFrequency = m_pDeflectors[v15].fFrequency;
        v14[v15].fQFactor = m_pDeflectors[v15].fQFactor;
      }
    }
  }
  m_Curves = in_rCopy->m_Curves;
  for ( i = 0; i < 4; ++i )
  {
    if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                         &this->m_Curves[i],
                         m_Curves->m_pArrayGraphPoints,
                         m_Curves->m_ulArraySize,
                         AkCurveScaling_None) == 52 )
      goto LABEL_16;
    ++m_Curves;
  }
  if ( in_rCopy->m_pPath )
  {
    m_cPathPoints = in_rCopy->m_cPathPoints;
    if ( m_cPathPoints )
    {
      v19 = (AkWooshPathPoint *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 12 * m_cPathPoints);
      this->m_pPath = v19;
      if ( !v19 )
      {
LABEL_16:
        *out_eResult = AK_InsufficientMemory;
        return;
      }
      v20 = in_rCopy->m_cPathPoints;
      this->m_cPathPoints = v20;
      if ( v20 )
      {
        do
        {
          m_pPath = in_rCopy->m_pPath;
          v22 = this->m_pPath;
          v23 = v4++;
          v22[v23].fDistanceTravelled = m_pPath[v23].fDistanceTravelled;
          v22[v23].fX = m_pPath[v23].fX;
          v22[v23].fY = m_pPath[v23].fY;
        }
        while ( v4 < this->m_cPathPoints );
      }
    }
  }
}

// File Line: 116
// RVA: 0xAD9390
void __fastcall CAkSoundSeedWooshParams::Clone(CAkSoundSeedWooshParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAllocVtbl *vfptr; // rax
  CAkSoundSeedWooshParams *v5; // rax
  __int64 v6; // rax
  AKRESULT out_eResult; // [rsp+38h] [rbp+10h] BYREF

  vfptr = in_pAllocator->vfptr;
  out_eResult = AK_Success;
  v5 = (CAkSoundSeedWooshParams *)vfptr->Malloc(in_pAllocator, 208ui64);
  if ( v5 )
  {
    CAkSoundSeedWooshParams::CAkSoundSeedWooshParams(v5, this, &out_eResult);
    if ( v6 )
    {
      if ( out_eResult != AK_Success )
        (*(void (__fastcall **)(__int64, AK::IAkPluginMemAlloc *))(*(_QWORD *)v6 + 32i64))(v6, in_pAllocator);
    }
  }
}

// File Line: 132
// RVA: 0xAD9400
__int64 __fastcall CAkSoundSeedWooshParams::Init(
        CAkSoundSeedWooshParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
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
__int64 __fastcall CAkSoundSeedWooshParams::Term(CAkSoundSeedWooshParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 157
// RVA: 0xAD94C0
int __fastcall CAkSoundSeedWooshParams::SetParamsBlock(
        CAkSoundSeedWooshParams *this,
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
  AKRESULT Path; // eax
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
  v8 = (char *)in_pParamsBlock + 75;
  this->m_Params.fMinDistance = v7;
  v9 = *(float *)(v8 - 61);
  io_ppData = v8;
  this->m_Params.fAttenuationRolloff = v9;
  this->m_Params.fDynamicRange = *(float *)(v8 - 57);
  this->m_Params.fPlaybackRate = *(float *)(v8 - 53);
  this->m_Params.eNoiseColor = *(unsigned __int16 *)(v8 - 49);
  this->m_Params.fRandomSpeedX = *(float *)(v8 - 47);
  this->m_Params.fRandomSpeedY = *(float *)(v8 - 43);
  this->m_Params.bEnableDistanceBasedAttenuation = *(v8 - 39);
  this->m_Params.uOversamplingFactor = *((unsigned __int16 *)v8 - 19);
  this->m_Params.fBaseValue[0] = *((float *)v8 - 9);
  this->m_Params.fRandomValue[0] = *((float *)v8 - 8);
  this->m_Params.bAutomation[0] = *(v8 - 28);
  this->m_Params.fBaseValue[1] = *(float *)(v8 - 27);
  this->m_Params.fRandomValue[1] = *(float *)(v8 - 23);
  this->m_Params.bAutomation[1] = *(v8 - 19);
  this->m_Params.fBaseValue[2] = *(float *)(v8 - 18);
  this->m_Params.fRandomValue[2] = *(float *)(v8 - 14);
  this->m_Params.bAutomation[2] = *(v8 - 10);
  this->m_Params.fBaseValue[3] = *(float *)(v8 - 9);
  this->m_Params.fRandomValue[3] = *(float *)(v8 - 5);
  this->m_Params.bAutomation[3] = *(v8 - 1);
  this->m_Params.fBaseValue[3] = powf(10.0, this->m_Params.fBaseValue[3] * 0.050000001);
  this->m_uChangeMask = 15;
  result = CAkSoundSeedWooshParams::ReadDeflectors(this, (const void **)&io_ppData);
  if ( result == 1 )
  {
    result = CAkSoundSeedWooshParams::ReadAllCurves(this, (const void **)&io_ppData);
    if ( result == 1 )
    {
      Path = CAkSoundSeedWooshParams::ReadPath(this, (const void **)&io_ppData);
      v12 = 1;
      if ( Path != AK_Success )
        return Path;
      return v12;
    }
  }
  return result;
}

// File Line: 202
// RVA: 0xAD9A10
__int64 __fastcall CAkSoundSeedWooshParams::ReadDeflectors(CAkSoundSeedWooshParams *this, float **io_ppData)
{
  float *v2; // rsi
  AkWooshDeflectorParams *m_pDeflectors; // rdx
  int v5; // eax
  unsigned int v6; // ebp
  float *v7; // rsi
  unsigned int v9; // ebx
  AkWooshDeflectorParams *v10; // rax
  float v12; // xmm0_4
  __int64 v13; // rbx

  v2 = *io_ppData;
  m_pDeflectors = this->m_pDeflectors;
  v5 = *(__int16 *)v2;
  v6 = 0;
  v7 = v2 + 1;
  this->m_Params.iAnchorIndex = v5;
  v9 = *((unsigned __int16 *)v7 - 1);
  if ( m_pDeflectors && this->m_cDeflectors != *((unsigned __int16 *)v7 - 1) )
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
      v10 = (AkWooshDeflectorParams *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 12 * v9);
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
        v7 += 3;
        v13 = v6;
        this->m_pDeflectors[v13].fFrequency = v12;
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

// File Line: 245
// RVA: 0xAD9D30
__int64 __fastcall CAkSoundSeedWooshParams::ReadPath(CAkSoundSeedWooshParams *this, float **io_ppData)
{
  float *v2; // rbx
  AkWooshPathPoint *m_pPath; // rdx
  unsigned int v5; // eax
  unsigned int v6; // esi
  float *v7; // rbx
  unsigned int v9; // r14d
  AkWooshPathPoint *v10; // rax
  float v12; // xmm0_4
  __int64 v13; // rax
  __int64 v14; // rcx

  v2 = *io_ppData;
  m_pPath = this->m_pPath;
  v5 = *(unsigned __int16 *)v2;
  v6 = 0;
  v7 = (float *)((char *)v2 + 6);
  this->m_fTotalPathDistance = *(v7 - 1);
  v9 = v5;
  if ( m_pPath && this->m_cPathPoints != v5 )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pPath = 0i64;
    this->m_cPathPoints = 0;
  }
  if ( v9 )
  {
    this->m_cPathPoints = v9;
    if ( !this->m_pPath )
    {
      v10 = (AkWooshPathPoint *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 12 * v9);
      this->m_pPath = v10;
      if ( !v10 )
      {
        this->m_cPathPoints = 0;
        return 52i64;
      }
    }
    if ( this->m_cPathPoints )
    {
      do
      {
        v12 = *v7;
        v13 = v6++;
        v14 = v13;
        v7 += 3;
        this->m_pPath[v14].fDistanceTravelled = v12;
        this->m_pPath[v14].fX = *(v7 - 2);
        this->m_pPath[v14].fY = *(v7 - 1);
      }
      while ( v6 < this->m_cPathPoints );
    }
  }
  *io_ppData = v7;
  return 1i64;
}

// File Line: 288
// RVA: 0xAD9B70
__int64 __fastcall CAkSoundSeedWooshParams::ReadAllCurves(CAkSoundSeedWooshParams *this, const void **io_ppData)
{
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *m_Curves; // rbx
  __int64 v5; // rdi
  __int16 v6; // si
  int *v7; // rbx
  int v8; // ebp
  int v9; // ecx
  __int64 v10; // rax
  unsigned __int16 v11; // di

  m_Curves = this->m_Curves;
  v5 = 4i64;
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
  v6 = 0;
  v7 = (int *)((char *)*io_ppData + 2);
  v8 = *(unsigned __int16 *)*io_ppData;
  if ( !*(_WORD *)*io_ppData )
  {
LABEL_18:
    *io_ppData = v7;
    return 1i64;
  }
  while ( 1 )
  {
    v9 = *v7;
    v10 = 0i64;
    if ( *v7 )
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
    v11 = *((_WORD *)v7 + 2);
    v7 = (int *)((char *)v7 + 6);
    if ( !v11 )
      goto LABEL_17;
    if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                         &this->m_Curves[v10],
                         (AkRTPCGraphPointBase<float> *)v7,
                         v11,
                         AkCurveScaling_None) == 52 )
      return 52i64;
    v7 += 3 * v11;
LABEL_17:
    if ( (unsigned __int16)++v6 >= v8 )
      goto LABEL_18;
  }
}

// File Line: 310
// RVA: 0xAD9C80
__int64 __fastcall CAkSoundSeedWooshParams::ReadCurve(
        CAkSoundSeedWooshParams *this,
        AkRTPCGraphPointBase<float> **io_ppData)
{
  AkRTPCGraphPointBase<float> *v2; // rbx
  __int64 v3; // rax
  float From; // r8d
  unsigned __int16 To_low; // di
  AkRTPCGraphPointBase<float> *v7; // rbx
  __int64 result; // rax

  v2 = *io_ppData;
  v3 = 0i64;
  From = (*io_ppData)->From;
  if ( From != 0.0 )
  {
    switch ( LODWORD(From) )
    {
      case 0x14:
        v3 = 1i64;
        break;
      case 0x17:
        v3 = 2i64;
        break;
      case 0x1A:
        v3 = 3i64;
        break;
    }
  }
  To_low = LOWORD(v2->To);
  v7 = (AkRTPCGraphPointBase<float> *)((char *)&v2->To + 2);
  if ( To_low )
  {
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
               &this->m_Curves[v3],
               v7,
               To_low,
               AkCurveScaling_None);
    if ( (_DWORD)result == 52 )
      return result;
    v7 += To_low;
  }
  *io_ppData = v7;
  return 1i64;
}

// File Line: 337
// RVA: 0xAD9EA0
__int64 __fastcall CAkSoundSeedWooshParams::CurveIDToIndex(CAkSoundSeedWooshParams *this, unsigned int in_uCurveID)
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
AKRESULT __fastcall CAkSoundSeedWooshParams::SetParam(
        CAkSoundSeedWooshParams *this,
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
    this->m_uChangeMask |= 7u;
    Deflectors = CAkSoundSeedWooshParams::ReadDeflectors(this, (const void **)&io_ppData);
    if ( Deflectors == AK_Success
      && (Deflectors = CAkSoundSeedWooshParams::ReadAllCurves(this, (const void **)&io_ppData), Deflectors == AK_Success) )
    {
      return CAkSoundSeedWooshParams::ReadPath(this, (const void **)&io_ppData);
    }
    else
    {
      return Deflectors;
    }
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
      case 20:
        this->m_Params.fBaseValue[1] = *in_pValue;
        result = AK_Success;
        break;
      case 21:
        this->m_Params.fRandomValue[1] = *in_pValue;
        result = AK_Success;
        break;
      case 22:
        this->m_Params.bAutomation[1] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 23:
        this->m_Params.fBaseValue[2] = *in_pValue;
        result = AK_Success;
        break;
      case 24:
        this->m_Params.fRandomValue[2] = *in_pValue;
        result = AK_Success;
        break;
      case 25:
        this->m_Params.bAutomation[2] = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 26:
        v8 = powf(10.0, *in_pValue * 0.050000001);
        result = AK_Success;
        this->m_Params.fBaseValue[3] = v8;
        break;
      case 27:
        this->m_Params.fRandomValue[3] = *in_pValue;
        result = AK_Success;
        break;
      case 28:
        this->m_Params.bAutomation[3] = *(_BYTE *)in_pValue;
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
        this->m_Params.eNoiseColor = *(unsigned __int16 *)in_pValue;
        result = AK_Success;
        break;
      case 47:
        this->m_Params.fRandomSpeedX = *in_pValue;
        result = AK_Success;
        break;
      case 48:
        this->m_Params.fRandomSpeedY = *in_pValue;
        result = AK_Success;
        break;
      case 49:
        this->m_Params.bEnableDistanceBasedAttenuation = *(_BYTE *)in_pValue;
        result = AK_Success;
        break;
      case 50:
        this->m_Params.fPlaybackRate = *in_pValue;
        result = AK_Success;
        break;
      case 51:
        this->m_Params.uOversamplingFactor = *(unsigned __int16 *)in_pValue;
        result = AK_Success;
        break;
      case 52:
        this->m_Params.fDynamicRange = *in_pValue;
        result = AK_Success;
        break;
      default:
        return 31;
    }
  }
  return result;
}Params.fDynamicRange = *in_p

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

