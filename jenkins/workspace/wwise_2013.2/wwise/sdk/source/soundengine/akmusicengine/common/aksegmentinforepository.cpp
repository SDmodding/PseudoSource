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
  CAkSegmentInfoRepository *v2; // rsi
  unsigned int v3; // edi
  LARGE_INTEGER *v4; // rax
  unsigned int v5; // edi

  v2 = this;
  v3 = in_PlayingID;
  EnterCriticalSection(&this->m_lock.m_csLock);
  v4 = (LARGE_INTEGER *)CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Set(&v2->m_mapSegmentInfo, v3);
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
  LeaveCriticalSection(&v2->m_lock.m_csLock);
  return v5;
}

// File Line: 111
// RVA: 0xAAB850
void __fastcall CAkSegmentInfoRepository::UpdateSegmentInfo(CAkSegmentInfoRepository *this, unsigned int in_PlayingID, AkSegmentInfo *in_segmentInfo)
{
  CAkSegmentInfoRepository *v3; // rdi
  AkSegmentInfo *v4; // r14
  unsigned int v5; // esi
  LARGE_INTEGER *v6; // rax
  signed __int64 v7; // rcx
  signed __int64 v8; // rcx

  v3 = this;
  v4 = in_segmentInfo;
  v5 = in_PlayingID;
  EnterCriticalSection(&this->m_lock.m_csLock);
  v6 = (LARGE_INTEGER *)v3->m_mapSegmentInfo.m_pItems;
  v7 = (signed __int64)&v3->m_mapSegmentInfo.m_pItems[v3->m_mapSegmentInfo.m_uLength];
  if ( v3->m_mapSegmentInfo.m_pItems != (MapStruct<unsigned long,AkSegmentInfoRecord> *)v7 )
  {
    do
    {
      if ( LODWORD(v6->QuadPart) == v5 )
        break;
      v6 += 5;
    }
    while ( v6 != (LARGE_INTEGER *)v7 );
    if ( v6 != (LARGE_INTEGER *)v7 && v6 != (LARGE_INTEGER *)-8i64 )
    {
      v8 = (signed __int64)&v6[4];
      *(_DWORD *)(v8 - 24) = v4->iCurrentPosition;
      *(_DWORD *)(v8 - 20) = v4->iPreEntryDuration;
      *(_DWORD *)(v8 - 16) = v4->iActiveDuration;
      *(_DWORD *)(v8 - 12) = v4->iPostExitDuration;
      *(_DWORD *)(v8 - 8) = v4->iRemainingLookAheadTime;
      QueryPerformanceCounter(v6 + 4);
    }
  }
  LeaveCriticalSection(&v3->m_lock.m_csLock);
}

// File Line: 130
// RVA: 0xAAB6B0
__int64 __fastcall CAkSegmentInfoRepository::GetSegmentInfo(CAkSegmentInfoRepository *this, unsigned int in_PlayingID, AkSegmentInfo *out_info, bool in_bExtrapolate)
{
  _RTL_CRITICAL_SECTION *v4; // rbx
  CAkSegmentInfoRepository *v5; // rdi
  bool v6; // r14
  AkSegmentInfo *v7; // rsi
  unsigned int v8; // ebp
  MapStruct<unsigned long,AkSegmentInfoRecord> *v9; // rax
  signed __int64 v10; // rcx
  int *v11; // rdi
  unsigned int v12; // edi
  LARGE_INTEGER PerformanceCount; // [rsp+40h] [rbp+8h]

  v4 = &this->m_lock.m_csLock;
  v5 = this;
  v6 = in_bExtrapolate;
  v7 = out_info;
  v8 = in_PlayingID;
  EnterCriticalSection(&this->m_lock.m_csLock);
  v9 = v5->m_mapSegmentInfo.m_pItems;
  v10 = (signed __int64)&v5->m_mapSegmentInfo.m_pItems[v5->m_mapSegmentInfo.m_uLength];
  if ( v5->m_mapSegmentInfo.m_pItems == (MapStruct<unsigned long,AkSegmentInfoRecord> *)v10 )
    goto LABEL_16;
  do
  {
    if ( v9->key == v8 )
      break;
    ++v9;
  }
  while ( v9 != (MapStruct<unsigned long,AkSegmentInfoRecord> *)v10 );
  if ( v9 == (MapStruct<unsigned long,AkSegmentInfoRecord> *)v10
    || (v11 = &v9->item.segmentInfo.iCurrentPosition, v9 == (MapStruct<unsigned long,AkSegmentInfoRecord> *)-8i64) )
  {
LABEL_16:
    v12 = 2;
  }
  else
  {
    v7->iCurrentPosition = *v11;
    v7->iPreEntryDuration = v9->item.segmentInfo.iPreEntryDuration;
    v7->iActiveDuration = v9->item.segmentInfo.iActiveDuration;
    v7->iPostExitDuration = v9->item.segmentInfo.iPostExitDuration;
    v7->iRemainingLookAheadTime = v9->item.segmentInfo.iRemainingLookAheadTime;
    if ( v6 && (v7->iActiveDuration > 0 || v7->iPreEntryDuration > 0 || v7->iPostExitDuration > 0) )
    {
      QueryPerformanceCounter(&PerformanceCount);
      v7->iCurrentPosition += (signed int)(float)((float)(PerformanceCount.LowPart - v11[6]) / AK::g_fFreqRatio);
    }
    v12 = 1;
  }
  LeaveCriticalSection(v4);
  return v12;
}

