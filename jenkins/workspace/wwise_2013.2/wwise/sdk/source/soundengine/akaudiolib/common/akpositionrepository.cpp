// File Line: 36
// RVA: 0xA63D00
signed __int64 __fastcall CAkPositionRepository::Init(CAkPositionRepository *this)
{
  CAkPositionRepository *v1; // rbx
  MapStruct<unsigned long,AkPositionInfo> *v2; // rax

  v1 = this;
  v2 = (MapStruct<unsigned long,AkPositionInfo> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x140ui64);
  v1->m_mapPosInfo.m_pItems = v2;
  if ( !v2 )
    return 52i64;
  v1->m_mapPosInfo.m_ulReserved = 8;
  return 1i64;
}

// File Line: 45
// RVA: 0xA63ED0
void __fastcall CAkLimiter::Term(CAkSegmentInfoRepository *this)
{
  MapStruct<unsigned long,AkSegmentInfoRecord> *v1; // rdx
  CAkSegmentInfoRepository *v2; // rbx

  v1 = this->m_mapSegmentInfo.m_pItems;
  v2 = this;
  if ( this->m_mapSegmentInfo.m_pItems )
  {
    this->m_mapSegmentInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_mapSegmentInfo.m_pItems = 0i64;
    v2->m_mapSegmentInfo.m_ulReserved = 0;
  }
}

// File Line: 55
// RVA: 0xA63E50
void __fastcall CAkPositionRepository::SetRate(CAkPositionRepository *this, unsigned int in_PlayingID, float in_fNewRate)
{
  MapStruct<unsigned long,AkPositionInfo> *v3; // rax
  CAkPositionRepository *v4; // rsi
  MapStruct<unsigned long,AkPositionInfo> *v5; // r8
  signed __int64 v6; // rdi
  __int64 v7; // rax

  v3 = this->m_mapPosInfo.m_pItems;
  v4 = this;
  v5 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems != v5 )
  {
    do
    {
      if ( v3->key == in_PlayingID )
        break;
      ++v3;
    }
    while ( v3 != v5 );
    if ( v3 != v5 )
    {
      v6 = (signed __int64)&v3->item;
      if ( v3 != (MapStruct<unsigned long,AkPositionInfo> *)-8i64 )
      {
        EnterCriticalSection(&this->m_lock.m_csLock);
        v7 = v4->m_i64LastTimeUpdated;
        *(float *)(v6 + 4) = in_fNewRate;
        *(_QWORD *)(v6 + 16) = v7;
        LeaveCriticalSection(&v4->m_lock.m_csLock);
      }
    }
  }
}

// File Line: 70
// RVA: 0xA63AD0
void __fastcall CAkPositionRepository::AddSource(CAkPositionRepository *this, unsigned int in_PlayingID, void *in_cookie)
{
  MapStruct<unsigned long,AkPositionInfo> *v3; // rax
  void *v4; // r14
  unsigned int v5; // esi
  CAkPositionRepository *v6; // rdi
  MapStruct<unsigned long,AkPositionInfo> *v7; // r9
  unsigned __int64 v8; // rbp
  __int64 v9; // rdx
  signed __int64 v10; // r8

  v3 = this->m_mapPosInfo.m_pItems;
  v4 = in_cookie;
  v5 = in_PlayingID;
  v6 = this;
  v7 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems == v7 )
    goto LABEL_14;
  do
  {
    if ( v3->key == in_PlayingID )
      break;
    ++v3;
  }
  while ( v3 != v7 );
  if ( v3 == v7 || v3 == (MapStruct<unsigned long,AkPositionInfo> *)-8i64 )
  {
LABEL_14:
    EnterCriticalSection(&this->m_lock.m_csLock);
    v8 = v6->m_mapPosInfo.m_uLength;
    if ( (v8 < v6->m_mapPosInfo.m_ulReserved
       || AkArray<MapStruct<unsigned long,AkPositionInfo>,MapStruct<unsigned long,AkPositionInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
            (AkArray<MapStruct<unsigned long,AkSegmentInfoRecord>,MapStruct<unsigned long,AkSegmentInfoRecord> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)v6,
            1u))
      && v8 < v6->m_mapPosInfo.m_ulReserved )
    {
      v9 = v6->m_mapPosInfo.m_uLength;
      v10 = (signed __int64)&v6->m_mapPosInfo.m_pItems[v9];
      v6->m_mapPosInfo.m_uLength = v9 + 1;
      if ( v10 )
      {
        *(_DWORD *)v10 = v5;
        *(_QWORD *)(v10 + 32) = v4;
        *(_DWORD *)(v10 + 8) = -1;
        *(_DWORD *)(v10 + 12) = 1065353216;
        *(_DWORD *)(v10 + 16) = -1;
        *(_DWORD *)(v10 + 20) = 1;
      }
    }
    LeaveCriticalSection(&v6->m_lock.m_csLock);
  }
}

// File Line: 96
// RVA: 0xA63D90
void __fastcall CAkPositionRepository::RemoveSource(CAkPositionRepository *this, unsigned int in_PlayingID, void *in_cookie)
{
  MapStruct<unsigned long,AkPositionInfo> *v3; // rdi
  CAkPositionRepository *v4; // r14
  MapStruct<unsigned long,AkPositionInfo> *v5; // rax
  unsigned __int64 v6; // rdx

  v3 = this->m_mapPosInfo.m_pItems;
  v4 = this;
  v5 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems != v5 )
  {
    do
    {
      if ( v3->key == in_PlayingID )
        break;
      ++v3;
    }
    while ( v3 != v5 );
    if ( v3 != v5 && v3->item.cookie == in_cookie )
    {
      EnterCriticalSection(&this->m_lock.m_csLock);
      v6 = (unsigned __int64)v4->m_mapPosInfo.m_pItems + 8 * (5i64 * v4->m_mapPosInfo.m_uLength - 5);
      if ( (unsigned __int64)v3 < v6 )
        qmemcpy(
          v3,
          &v3[1],
          40
        * (((unsigned __int64)((v6 - (unsigned __int64)v3 - 1) * (unsigned __int128)0xCCCCCCCCCCCCCCCDui64 >> 64) >> 5)
         + 1));
      --v4->m_mapPosInfo.m_uLength;
      LeaveCriticalSection(&v4->m_lock.m_csLock);
    }
  }
}

// File Line: 113
// RVA: 0xA63F80
void __fastcall CAkPositionRepository::UpdatePositionInfo(CAkPositionRepository *this, unsigned int in_PlayingID, AkBufferPosInformation *in_pPosInfo, void *in_cookie)
{
  MapStruct<unsigned long,AkPositionInfo> *v4; // rax
  void *v5; // r15
  AkBufferPosInformation *v6; // r14
  unsigned int v7; // ebp
  MapStruct<unsigned long,AkPositionInfo> *v8; // r10
  CAkPositionRepository *v9; // rsi
  AkSegmentInfoRecord *v10; // rdi

  v4 = this->m_mapPosInfo.m_pItems;
  v5 = in_cookie;
  v6 = in_pPosInfo;
  v7 = in_PlayingID;
  v8 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  v9 = this;
  if ( this->m_mapPosInfo.m_pItems == v8 )
    goto LABEL_17;
  do
  {
    if ( v4->key == in_PlayingID )
      break;
    ++v4;
  }
  while ( v4 != v8 );
  if ( v4 == v8 )
LABEL_17:
    v10 = 0i64;
  else
    v10 = (AkSegmentInfoRecord *)&v4->item;
  EnterCriticalSection(&this->m_lock.m_csLock);
  if ( v10 )
  {
    if ( v5 == (void *)v10->timeUpdated )
    {
LABEL_13:
      v10->segmentInfo.iCurrentPosition = v6->uStartPos;
      v10->segmentInfo.iPreEntryDuration = LODWORD(v6->fLastRate);
      v10->segmentInfo.iActiveDuration = v6->uFileEnd;
      v10->segmentInfo.iPostExitDuration = v6->uSampleRate;
      *(_QWORD *)&v10->segmentInfo.iRemainingLookAheadTime = v9->m_i64LastTimeUpdated;
      goto LABEL_14;
    }
  }
  else
  {
    v10 = CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Set(
            (CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *)v9,
            v7);
    if ( v10 )
    {
      if ( v9->m_mapPosInfo.m_uLength )
        QueryPerformanceCounter((LARGE_INTEGER *)&v9->m_i64LastTimeUpdated);
      v10->timeUpdated = (__int64)v5;
      goto LABEL_13;
    }
  }
LABEL_14:
  LeaveCriticalSection(&v9->m_lock.m_csLock);
}

// File Line: 141
// RVA: 0xA63BC0
__int64 __fastcall CAkPositionRepository::GetCurrPosition(CAkPositionRepository *this, unsigned int in_PlayingID, int *out_puPos, bool in_bExtrapolate)
{
  _RTL_CRITICAL_SECTION *v4; // rbx
  CAkPositionRepository *v5; // rdi
  bool v6; // bp
  int *v7; // r14
  unsigned int v8; // esi
  MapStruct<unsigned long,AkPositionInfo> *v9; // rax
  signed __int64 v10; // rcx
  signed __int64 v11; // rdi
  signed int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm6_4
  unsigned int v15; // esi
  unsigned int v16; // edi
  LARGE_INTEGER PerformanceCount; // [rsp+50h] [rbp+8h]

  v4 = &this->m_lock.m_csLock;
  v5 = this;
  v6 = in_bExtrapolate;
  v7 = out_puPos;
  v8 = in_PlayingID;
  EnterCriticalSection(&this->m_lock.m_csLock);
  v9 = v5->m_mapPosInfo.m_pItems;
  v10 = (signed __int64)&v5->m_mapPosInfo.m_pItems[v5->m_mapPosInfo.m_uLength];
  if ( v5->m_mapPosInfo.m_pItems == (MapStruct<unsigned long,AkPositionInfo> *)v10 )
    goto LABEL_16;
  do
  {
    if ( v9->key == v8 )
      break;
    ++v9;
  }
  while ( v9 != (MapStruct<unsigned long,AkPositionInfo> *)v10 );
  if ( v9 == (MapStruct<unsigned long,AkPositionInfo> *)v10
    || (v11 = (signed __int64)&v9->item, v9 == (MapStruct<unsigned long,AkPositionInfo> *)-8i64)
    || (v12 = v9->item.bufferPosInfo.uSampleRate, v12 == 1) )
  {
LABEL_16:
    *v7 = 0;
    v16 = 2;
  }
  else
  {
    v13 = 1.0 / (float)v12;
    v14 = (float)((float)*(signed int *)v11 * 1000.0) * v13;
    v15 = (signed int)(float)((float)((float)*(signed int *)(v11 + 8) * 1000.0) * v13);
    if ( v6 )
    {
      QueryPerformanceCounter(&PerformanceCount);
      v14 = v14
          + (float)((float)((float)(PerformanceCount.LowPart - *(_DWORD *)(v11 + 16)) / AK::g_fFreqRatio)
                  * *(float *)(v11 + 4));
    }
    v16 = 1;
    if ( (signed int)v14 < v15 )
      v15 = (signed int)v14;
    *v7 = v15;
  }
  LeaveCriticalSection(v4);
  return v16;
}

// File Line: 179
// RVA: 0xA63D40
void __fastcall CAkPositionRepository::RemovePlayingID(CAkSegmentInfoRepository *this, unsigned int in_PlayingID)
{
  CAkSegmentInfoRepository *v2; // rsi
  unsigned int v3; // edi

  v2 = this;
  v3 = in_PlayingID;
  EnterCriticalSection(&this->m_lock.m_csLock);
  CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Unset(&v2->m_mapSegmentInfo, v3);
  LeaveCriticalSection(&v2->m_lock.m_csLock);
}

