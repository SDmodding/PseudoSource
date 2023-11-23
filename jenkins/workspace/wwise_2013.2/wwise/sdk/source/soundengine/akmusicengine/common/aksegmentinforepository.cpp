// File Line: 48
// RVA: 0xAAB630
void __fastcall CAkSegmentInfoRepository::~CAkSegmentInfoRepository(CAkSegmentInfoRepository *this)
{
  DeleteCriticalSection(&this->m_lock.m_csLock);
}

// File Line: 80
// RVA: 0xAAB640
__int64 __fastcall CAkSegmentInfoRepository::CreateEntry(CAkSegmentInfoRepository *this, unsigned int in_PlayingID)
{
  LARGE_INTEGER *v4; // rax
  unsigned int v5; // edi

  EnterCriticalSection(&this->m_lock.m_csLock);
  v4 = (LARGE_INTEGER *)CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Set(&this->m_mapSegmentInfo, in_PlayingID);
  if ( v4 )
  {
    v4->QuadPart = 0i64;
    v4[1].QuadPart = 0i64;
    v4[2].LowPart = 0;
    QueryPerformanceCounter(v4 + 3);
    v5 = 1;
  }
  else
  {
    v5 = 2;
  }
  LeaveCriticalSection(&this->m_lock.m_csLock);
  return v5;
}

// File Line: 111
// RVA: 0xAAB850
void __fastcall CAkSegmentInfoRepository::UpdateSegmentInfo(
        CAkSegmentInfoRepository *this,
        unsigned int in_PlayingID,
        AkSegmentInfo *in_segmentInfo)
{
  LARGE_INTEGER *m_pItems; // rax
  MapStruct<unsigned long,AkSegmentInfoRecord> *v7; // rcx

  EnterCriticalSection(&this->m_lock.m_csLock);
  m_pItems = (LARGE_INTEGER *)this->m_mapSegmentInfo.m_pItems;
  v7 = &this->m_mapSegmentInfo.m_pItems[this->m_mapSegmentInfo.m_uLength];
  if ( this->m_mapSegmentInfo.m_pItems != v7 )
  {
    do
    {
      if ( m_pItems->LowPart == in_PlayingID )
        break;
      m_pItems += 5;
    }
    while ( m_pItems != (LARGE_INTEGER *)v7 );
    if ( m_pItems != (LARGE_INTEGER *)v7 && m_pItems != (LARGE_INTEGER *)-8i64 )
    {
      m_pItems[1].LowPart = in_segmentInfo->iCurrentPosition;
      m_pItems[1].HighPart = in_segmentInfo->iPreEntryDuration;
      m_pItems[2].LowPart = in_segmentInfo->iActiveDuration;
      m_pItems[2].HighPart = in_segmentInfo->iPostExitDuration;
      m_pItems[3].LowPart = in_segmentInfo->iRemainingLookAheadTime;
      QueryPerformanceCounter(m_pItems + 4);
    }
  }
  LeaveCriticalSection(&this->m_lock.m_csLock);
}

// File Line: 130
// RVA: 0xAAB6B0
__int64 __fastcall CAkSegmentInfoRepository::GetSegmentInfo(
        CAkSegmentInfoRepository *this,
        unsigned int in_PlayingID,
        AkSegmentInfo *out_info,
        bool in_bExtrapolate)
{
  CAkLock *p_m_lock; // rbx
  MapStruct<unsigned long,AkSegmentInfoRecord> *m_pItems; // rax
  MapStruct<unsigned long,AkSegmentInfoRecord> *v10; // rcx
  int *p_iCurrentPosition; // rdi
  unsigned int v12; // edi
  LARGE_INTEGER PerformanceCount; // [rsp+40h] [rbp+8h] BYREF

  p_m_lock = &this->m_lock;
  EnterCriticalSection(&this->m_lock.m_csLock);
  m_pItems = this->m_mapSegmentInfo.m_pItems;
  v10 = &this->m_mapSegmentInfo.m_pItems[this->m_mapSegmentInfo.m_uLength];
  if ( this->m_mapSegmentInfo.m_pItems == v10 )
    goto LABEL_12;
  do
  {
    if ( m_pItems->key == in_PlayingID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v10 );
  if ( m_pItems == v10
    || (p_iCurrentPosition = &m_pItems->item.segmentInfo.iCurrentPosition,
        m_pItems == (MapStruct<unsigned long,AkSegmentInfoRecord> *)-8i64) )
  {
LABEL_12:
    v12 = 2;
  }
  else
  {
    out_info->iCurrentPosition = *p_iCurrentPosition;
    out_info->iPreEntryDuration = m_pItems->item.segmentInfo.iPreEntryDuration;
    out_info->iActiveDuration = m_pItems->item.segmentInfo.iActiveDuration;
    out_info->iPostExitDuration = m_pItems->item.segmentInfo.iPostExitDuration;
    out_info->iRemainingLookAheadTime = m_pItems->item.segmentInfo.iRemainingLookAheadTime;
    if ( in_bExtrapolate
      && (out_info->iActiveDuration > 0 || out_info->iPreEntryDuration > 0 || out_info->iPostExitDuration > 0) )
    {
      QueryPerformanceCounter(&PerformanceCount);
      out_info->iCurrentPosition += (int)(float)((float)(PerformanceCount.LowPart - p_iCurrentPosition[6])
                                               / AK::g_fFreqRatio);
    }
    v12 = 1;
  }
  LeaveCriticalSection(&p_m_lock->m_csLock);
  return v12;
}

