// File Line: 36
// RVA: 0xA63D00
__int64 __fastcall CAkPositionRepository::Init(CAkPositionRepository *this)
{
  MapStruct<unsigned long,AkPositionInfo> *v2; // rax

  v2 = (MapStruct<unsigned long,AkPositionInfo> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x140ui64);
  this->m_mapPosInfo.m_pItems = v2;
  if ( !v2 )
    return 52i64;
  this->m_mapPosInfo.m_ulReserved = 8;
  return 1i64;
}

// File Line: 45
// RVA: 0xA63ED0
void __fastcall CAkLimiter::Term(CAkSegmentInfoRepository *this)
{
  MapStruct<unsigned long,AkSegmentInfoRecord> *m_pItems; // rdx

  m_pItems = this->m_mapSegmentInfo.m_pItems;
  if ( this->m_mapSegmentInfo.m_pItems )
  {
    this->m_mapSegmentInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapSegmentInfo.m_pItems = 0i64;
    this->m_mapSegmentInfo.m_ulReserved = 0;
  }
}

// File Line: 55
// RVA: 0xA63E50
void __fastcall CAkPositionRepository::SetRate(
        CAkPositionRepository *this,
        unsigned int in_PlayingID,
        float in_fNewRate)
{
  MapStruct<unsigned long,AkPositionInfo> *m_pItems; // rax
  MapStruct<unsigned long,AkPositionInfo> *v5; // r8
  AkPositionInfo *p_item; // rdi
  __int64 m_i64LastTimeUpdated; // rax

  m_pItems = this->m_mapPosInfo.m_pItems;
  v5 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems != v5 )
  {
    do
    {
      if ( m_pItems->key == in_PlayingID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v5 );
    if ( m_pItems != v5 )
    {
      p_item = &m_pItems->item;
      if ( m_pItems != (MapStruct<unsigned long,AkPositionInfo> *)-8i64 )
      {
        EnterCriticalSection(&this->m_lock.m_csLock);
        m_i64LastTimeUpdated = this->m_i64LastTimeUpdated;
        p_item->bufferPosInfo.fLastRate = in_fNewRate;
        p_item->timeUpdated = m_i64LastTimeUpdated;
        LeaveCriticalSection(&this->m_lock.m_csLock);
      }
    }
  }
}

// File Line: 70
// RVA: 0xA63AD0
void __fastcall CAkPositionRepository::AddSource(
        CAkPositionRepository *this,
        unsigned int in_PlayingID,
        void *in_cookie)
{
  MapStruct<unsigned long,AkPositionInfo> *m_pItems; // rax
  MapStruct<unsigned long,AkPositionInfo> *v7; // r9
  unsigned __int64 m_uLength; // rbp
  __int64 v9; // rdx
  MapStruct<unsigned long,AkPositionInfo> *v10; // r8

  m_pItems = this->m_mapPosInfo.m_pItems;
  v7 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems == v7 )
    goto LABEL_6;
  do
  {
    if ( m_pItems->key == in_PlayingID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v7 );
  if ( m_pItems == v7 || m_pItems == (MapStruct<unsigned long,AkPositionInfo> *)-8i64 )
  {
LABEL_6:
    EnterCriticalSection(&this->m_lock.m_csLock);
    m_uLength = this->m_mapPosInfo.m_uLength;
    if ( (m_uLength < this->m_mapPosInfo.m_ulReserved
       || AkArray<MapStruct<unsigned long,AkPositionInfo>,MapStruct<unsigned long,AkPositionInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
            (AkArray<MapStruct<unsigned long,AkSegmentInfoRecord>,MapStruct<unsigned long,AkSegmentInfoRecord> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)this,
            1u))
      && m_uLength < this->m_mapPosInfo.m_ulReserved )
    {
      v9 = this->m_mapPosInfo.m_uLength;
      v10 = &this->m_mapPosInfo.m_pItems[v9];
      this->m_mapPosInfo.m_uLength = v9 + 1;
      if ( v10 )
      {
        v10->key = in_PlayingID;
        v10->item.cookie = in_cookie;
        v10->item.bufferPosInfo.uStartPos = -1;
        v10->item.bufferPosInfo.fLastRate = 1.0;
        v10->item.bufferPosInfo.uFileEnd = -1;
        v10->item.bufferPosInfo.uSampleRate = 1;
      }
    }
    LeaveCriticalSection(&this->m_lock.m_csLock);
  }
}

// File Line: 96
// RVA: 0xA63D90
void __fastcall CAkPositionRepository::RemoveSource(
        CAkPositionRepository *this,
        unsigned int in_PlayingID,
        void *in_cookie)
{
  MapStruct<unsigned long,AkPositionInfo> *m_pItems; // rdi
  MapStruct<unsigned long,AkPositionInfo> *v5; // rax
  MapStruct<unsigned long,AkPositionInfo> *v6; // rdx

  m_pItems = this->m_mapPosInfo.m_pItems;
  v5 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems != v5 )
  {
    do
    {
      if ( m_pItems->key == in_PlayingID )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v5 );
    if ( m_pItems != v5 && m_pItems->item.cookie == in_cookie )
    {
      EnterCriticalSection(&this->m_lock.m_csLock);
      v6 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength - 1];
      if ( m_pItems < v6 )
        qmemcpy(m_pItems, &m_pItems[1], 40 * (((char *)v6 - (char *)m_pItems - 1) / 0x28ui64 + 1));
      --this->m_mapPosInfo.m_uLength;
      LeaveCriticalSection(&this->m_lock.m_csLock);
    }
  }
}

// File Line: 113
// RVA: 0xA63F80
void __fastcall CAkPositionRepository::UpdatePositionInfo(
        CAkPositionRepository *this,
        unsigned int in_PlayingID,
        AkBufferPosInformation *in_pPosInfo,
        void *in_cookie)
{
  MapStruct<unsigned long,AkPositionInfo> *m_pItems; // rax
  MapStruct<unsigned long,AkPositionInfo> *v8; // r10
  AkSegmentInfoRecord *p_item; // rdi

  m_pItems = this->m_mapPosInfo.m_pItems;
  v8 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems == v8 )
    goto LABEL_6;
  do
  {
    if ( m_pItems->key == in_PlayingID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v8 );
  if ( m_pItems == v8 )
LABEL_6:
    p_item = 0i64;
  else
    p_item = (AkSegmentInfoRecord *)&m_pItems->item;
  EnterCriticalSection(&this->m_lock.m_csLock);
  if ( p_item )
  {
    if ( in_cookie == (void *)p_item->timeUpdated )
    {
LABEL_13:
      p_item->segmentInfo.iCurrentPosition = in_pPosInfo->uStartPos;
      p_item->segmentInfo.iPreEntryDuration = LODWORD(in_pPosInfo->fLastRate);
      p_item->segmentInfo.iActiveDuration = in_pPosInfo->uFileEnd;
      p_item->segmentInfo.iPostExitDuration = in_pPosInfo->uSampleRate;
      *(_QWORD *)&p_item->segmentInfo.iRemainingLookAheadTime = this->m_i64LastTimeUpdated;
    }
  }
  else
  {
    p_item = CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Set(
               (CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *)this,
               in_PlayingID);
    if ( p_item )
    {
      if ( this->m_mapPosInfo.m_uLength )
        QueryPerformanceCounter((LARGE_INTEGER *)&this->m_i64LastTimeUpdated);
      p_item->timeUpdated = (__int64)in_cookie;
      goto LABEL_13;
    }
  }
  LeaveCriticalSection(&this->m_lock.m_csLock);
}

// File Line: 141
// RVA: 0xA63BC0
__int64 __fastcall CAkPositionRepository::GetCurrPosition(
        CAkPositionRepository *this,
        unsigned int in_PlayingID,
        unsigned int *out_puPos,
        bool in_bExtrapolate)
{
  CAkLock *p_m_lock; // rbx
  MapStruct<unsigned long,AkPositionInfo> *m_pItems; // rax
  MapStruct<unsigned long,AkPositionInfo> *v10; // rcx
  AkPositionInfo *p_item; // rdi
  int uSampleRate; // eax
  float v13; // xmm2_4
  float v14; // xmm6_4
  unsigned int v15; // esi
  unsigned int v16; // edi
  LARGE_INTEGER PerformanceCount; // [rsp+50h] [rbp+8h] BYREF

  p_m_lock = &this->m_lock;
  EnterCriticalSection(&this->m_lock.m_csLock);
  m_pItems = this->m_mapPosInfo.m_pItems;
  v10 = &this->m_mapPosInfo.m_pItems[this->m_mapPosInfo.m_uLength];
  if ( this->m_mapPosInfo.m_pItems == v10 )
    goto LABEL_12;
  do
  {
    if ( m_pItems->key == in_PlayingID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v10 );
  if ( m_pItems == v10
    || (p_item = &m_pItems->item, m_pItems == (MapStruct<unsigned long,AkPositionInfo> *)-8i64)
    || (uSampleRate = m_pItems->item.bufferPosInfo.uSampleRate, uSampleRate == 1) )
  {
LABEL_12:
    *out_puPos = 0;
    v16 = 2;
  }
  else
  {
    v13 = 1.0 / (float)uSampleRate;
    v14 = (float)((float)(int)p_item->bufferPosInfo.uStartPos * 1000.0) * v13;
    v15 = (int)(float)((float)((float)(int)p_item->bufferPosInfo.uFileEnd * 1000.0) * v13);
    if ( in_bExtrapolate )
    {
      QueryPerformanceCounter(&PerformanceCount);
      v14 = v14
          + (float)((float)((float)(PerformanceCount.LowPart - LODWORD(p_item->timeUpdated)) / AK::g_fFreqRatio)
                  * p_item->bufferPosInfo.fLastRate);
    }
    v16 = 1;
    if ( (int)v14 < v15 )
      v15 = (int)v14;
    *out_puPos = v15;
  }
  LeaveCriticalSection(&p_m_lock->m_csLock);
  return v16;
}

// File Line: 179
// RVA: 0xA63D40
void __fastcall CAkPositionRepository::RemovePlayingID(CAkSegmentInfoRepository *this, unsigned int in_PlayingID)
{
  EnterCriticalSection(&this->m_lock.m_csLock);
  CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Unset(&this->m_mapSegmentInfo, in_PlayingID);
  LeaveCriticalSection(&this->m_lock.m_csLock);
}

