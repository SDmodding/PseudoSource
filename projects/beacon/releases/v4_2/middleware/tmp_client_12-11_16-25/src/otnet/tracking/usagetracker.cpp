// File Line: 32
// RVA: 0xED7AF0
void __fastcall OSuite::ZUsageTrackingManager::ZUsageTrackingManager(OSuite::ZUsageTrackingManager *this)
{
  this->m_lastSampleTime = 0i64;
  this->m_lastUpdateTime = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTrackingManager::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>(
    &this->m_trackers,
    0x10ui64);
}

// File Line: 39
// RVA: 0xED7CD8
void __fastcall OSuite::ZUsageTrackingManager::~ZUsageTrackingManager(OSuite::ZUsageTrackingManager *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *p_m_trackers; // rbx
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  p_m_trackers = &this->m_trackers;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTrackingManager::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_trackers,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear(p_m_trackers);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  m_pLists = p_m_trackers->m_pLists;
  p_m_trackers->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
}

// File Line: 52
// RVA: 0xED824C
OSuite::ZObjectVtbl *__fastcall OSuite::ZUsageTrackingManager::CreateForHost(
        OSuite::ZUsageTrackingManager *this,
        const char *hostName)
{
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZUsageTracker *v5; // rax
  OSuite::ZUsageTracker *v6; // rax
  OSuite::ZUsageTracker *value; // [rsp+20h] [rbp-89h] BYREF
  OSuite::ZString v9; // [rsp+28h] [rbp-81h] BYREF
  OSuite::ZString key; // [rsp+40h] [rbp-69h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+60h] [rbp-49h] BYREF

  key.m_pString = 0i64;
  OSuite::ZString::ZString(&key, hostName);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(&this->m_trackers, &result, &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v5 = (OSuite::ZUsageTracker *)OSuite::ZObject::operator new(0x78ui64);
    if ( v5 )
    {
      v5->m_overallUsage = 0i64;
      v5->m_pMetricAppender = 0i64;
      v5->m_mutex.m_pInternalMutex = 0i64;
      v5->m_resourceStatistics.m_pLists = 0i64;
      OSuite::ZUsageTracker::ZUsageTracker(v5);
      vfptr = (OSuite::ZObjectVtbl *)v6;
      value = v6;
    }
    else
    {
      vfptr = 0i64;
      value = 0i64;
    }
    OSuite::ZString::ZString(&v9, hostName);
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::Insert(&this->m_trackers, &v9, &value);
    OSuite::ZString::~ZString(&v9);
  }
  else
  {
    vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZString::~ZString(&key);
  return vfptr;
}

// File Line: 70
// RVA: 0xED8E80
OSuite::ZObjectVtbl *__fastcall OSuite::ZUsageTrackingManager::GetForHost(
        OSuite::ZUsageTrackingManager *this,
        const char *hostName)
{
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZString key; // [rsp+20h] [rbp-59h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+40h] [rbp-39h] BYREF

  key.m_pString = 0i64;
  OSuite::ZString::ZString(&key, hostName);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(&this->m_trackers, &result, &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    vfptr = 0i64;
  else
    vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZString::~ZString(&key);
  return vfptr;
}

// File Line: 83
// RVA: 0xED99DC
void __fastcall OSuite::ZUsageTrackingManager::Update(OSuite::ZUsageTrackingManager *this)
{
  unsigned __int64 Clock; // rax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdi
  OSuite::ZUsageTracker *vfptr; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  Clock = OSuite::ZClock::_GetClock();
  v3 = OSuite::ZClock::_ClockToTime(Clock, UNIT_MILLI);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v4 = v3;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_trackers,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    vfptr = (OSuite::ZUsageTracker *)result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( vfptr->m_bEnabled )
      OSuite::ZUsageTracker::Update(vfptr, v4);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 99
// RVA: 0xED8914
void __fastcall OSuite::ZUsageTrackingManager::DumpUsageStatistics(OSuite::ZUsageTrackingManager *this)
{
  OSuite::ZUsageTracker *vfptr; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_trackers,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    vfptr = (OSuite::ZUsageTracker *)result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( vfptr->m_bEnabled )
      OSuite::ZUsageTracker::DumpUsageStatistics(vfptr);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 167
// RVA: 0xED7B24
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::~ZResourceUsage(OSuite::ZUsageTracker::ZResourceUsage *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::ZResourceUsage::`vftable;
  OSuite::Statistics::~Statistics(&this->m_bytesPerRequestReceivedSamples);
  OSuite::Statistics::~Statistics(&this->m_bytesPerSecondReceivedSamples);
  OSuite::Statistics::~Statistics(&this->m_bytesPerRequestSentSamples);
  OSuite::Statistics::~Statistics(&this->m_bytesPerSecondSentSamples);
  OSuite::Statistics::~Statistics(&this->m_requestsPerSecondSamples);
  this->m_sampleRecords.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
}

// File Line: 253
// RVA: 0xED793C
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::ZResourceUsage(OSuite::ZUsageTracker::ZResourceUsage *this)
{
  unsigned __int64 Clock; // rax
  unsigned __int64 v3; // rax

  this->m_totalRequests = 0i64;
  this->m_totalBytesSent = 0i64;
  this->m_totalBytesReceived = 0i64;
  this->m_maxBytesSent = 0i64;
  this->m_minBytesSent = 0i64;
  this->m_maxBytesReceived = 0i64;
  this->m_minBytesReceived = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::ZResourceUsage::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  this->m_sampleRecords.m_totalBytesSent = 0i64;
  this->m_sampleRecords.m_totalBytesReceived = 0i64;
  this->m_sampleRecords.m_totalRequests = 0i64;
  this->m_sampleRecords.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  Clock = OSuite::ZClock::_GetClock();
  v3 = OSuite::ZClock::_ClockToTime(Clock, UNIT_MILLI);
  this->m_sampleRecords.m_lastTime = 0i64;
  this->m_sampleRecords.m_startTime = v3;
  OSuite::Statistics::Statistics(&this->m_requestsPerSecondSamples, 1);
  OSuite::Statistics::Statistics(&this->m_bytesPerSecondSentSamples, 1);
  OSuite::Statistics::Statistics(&this->m_bytesPerRequestSentSamples, 1);
  OSuite::Statistics::Statistics(&this->m_bytesPerSecondReceivedSamples, 1);
  OSuite::Statistics::Statistics(&this->m_bytesPerRequestReceivedSamples, 1);
  memset(this->m_thresholds, 0, sizeof(this->m_thresholds));
}

// File Line: 307
// RVA: 0xED990C
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleRequestsPerSecond(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 currentTime)
{
  __int64 v2; // rax
  float result; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  unsigned __int64 v7[3]; // [rsp+30h] [rbp-18h] BYREF
  __int64 v8; // [rsp+60h] [rbp+18h] BYREF
  unsigned __int64 v9; // [rsp+68h] [rbp+20h] BYREF

  v8 = 0i64;
  v2 = OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(this, currentTime, (unsigned __int64 *)&v8, v7, &v9);
  result = 0.0;
  if ( v2 )
  {
    v4 = (float)(int)v8;
    if ( v8 < 0 )
      v4 = v4 + 1.8446744e19;
    v5 = v4 * 1000.0;
    v6 = (float)(int)v2;
    if ( v2 < 0 )
      v6 = v6 + 1.8446744e19;
    return v5 / v6;
  }
  return result;
}

// File Line: 323
// RVA: 0xED98A4
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondSent(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 currentTime)
{
  __int64 v2; // rax
  float result; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  unsigned __int64 v7[3]; // [rsp+30h] [rbp-18h] BYREF
  __int64 v8; // [rsp+60h] [rbp+18h] BYREF
  unsigned __int64 v9; // [rsp+68h] [rbp+20h] BYREF

  v8 = 0i64;
  v2 = OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(this, currentTime, v7, (unsigned __int64 *)&v8, &v9);
  result = 0.0;
  if ( v2 )
  {
    v4 = (float)(int)v8;
    if ( v8 < 0 )
      v4 = v4 + 1.8446744e19;
    v5 = v4 * 1000.0;
    v6 = (float)(int)v2;
    if ( v2 < 0 )
      v6 = v6 + 1.8446744e19;
    return v5 / v6;
  }
  return result;
}

// File Line: 339
// RVA: 0xED97C8
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestSent(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 currentTime)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  unsigned __int64 v5[3]; // [rsp+30h] [rbp-18h] BYREF
  __int64 v6; // [rsp+60h] [rbp+18h] BYREF
  __int64 v7; // [rsp+68h] [rbp+20h] BYREF

  v7 = 0i64;
  v6 = 0i64;
  if ( !OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
          this,
          currentTime,
          (unsigned __int64 *)&v6,
          (unsigned __int64 *)&v7,
          v5)
    || !v6 )
  {
    return 0.0;
  }
  v2 = (float)(int)v7;
  if ( v7 < 0 )
    v2 = v2 + 1.8446744e19;
  v3 = (float)(int)v6;
  if ( v6 < 0 )
    v3 = v3 + 1.8446744e19;
  return v2 / v3;
}

// File Line: 354
// RVA: 0xED983C
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondReceived(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 currentTime)
{
  __int64 v2; // rax
  float result; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  unsigned __int64 v7[3]; // [rsp+30h] [rbp-18h] BYREF
  __int64 v8; // [rsp+60h] [rbp+18h] BYREF
  unsigned __int64 v9; // [rsp+68h] [rbp+20h] BYREF

  v8 = 0i64;
  v2 = OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(this, currentTime, v7, &v9, (unsigned __int64 *)&v8);
  result = 0.0;
  if ( v2 )
  {
    v4 = (float)(int)v8;
    if ( v8 < 0 )
      v4 = v4 + 1.8446744e19;
    v5 = v4 * 1000.0;
    v6 = (float)(int)v2;
    if ( v2 < 0 )
      v6 = v6 + 1.8446744e19;
    return v5 / v6;
  }
  return result;
}

// File Line: 370
// RVA: 0xED9754
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestReceived(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 currentTime)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  unsigned __int64 v5[3]; // [rsp+30h] [rbp-18h] BYREF
  __int64 v6; // [rsp+60h] [rbp+18h] BYREF
  __int64 v7; // [rsp+68h] [rbp+20h] BYREF

  v7 = 0i64;
  v6 = 0i64;
  if ( !OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
          this,
          currentTime,
          (unsigned __int64 *)&v6,
          v5,
          (unsigned __int64 *)&v7)
    || !v6 )
  {
    return 0.0;
  }
  v2 = (float)(int)v7;
  if ( v7 < 0 )
    v2 = v2 + 1.8446744e19;
  v3 = (float)(int)v6;
  if ( v6 < 0 )
    v3 = v3 + 1.8446744e19;
  return v2 / v3;
}

// File Line: 385
// RVA: 0xED9570
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::Sample(OSuite::ZUsageTracker::ZResourceUsage *this)
{
  unsigned __int64 Clock; // rax
  unsigned __int64 v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax

  OSuite::ZMutex::Lock(&this->m_mutex);
  if ( this->m_sampleRecords.m_totalRequests )
  {
    Clock = OSuite::ZClock::_GetClock();
    v3 = OSuite::ZClock::_ClockToTime(Clock, UNIT_MILLI);
    v4 = OSuite::ZUsageTracker::ZResourceUsage::SampleRequestsPerSecond(this, v3);
    OSuite::Statistics::AddValue(&this->m_requestsPerSecondSamples, v4);
    v5 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondSent(this, v3);
    OSuite::Statistics::AddValue(&this->m_bytesPerSecondSentSamples, v5);
    v6 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestSent(this, v3);
    OSuite::Statistics::AddValue(&this->m_bytesPerRequestSentSamples, v6);
    v7 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondReceived(this, v3);
    OSuite::Statistics::AddValue(&this->m_bytesPerSecondReceivedSamples, v7);
    v8 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestReceived(this, v3);
    OSuite::Statistics::AddValue(&this->m_bytesPerRequestReceivedSamples, v8);
    v9 = OSuite::ZClock::_GetClock();
    v10 = OSuite::ZClock::_ClockToTime(v9, UNIT_MILLI);
    this->m_sampleRecords.m_lastTime = 0i64;
    this->m_sampleRecords.m_totalBytesSent = 0i64;
    this->m_sampleRecords.m_totalBytesReceived = 0i64;
    this->m_sampleRecords.m_totalRequests = 0i64;
    this->m_sampleRecords.m_startTime = v10;
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
}

// File Line: 404
// RVA: 0xED839C
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::CreateMetrics(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        OSuite::ZMetricAppender *pMetricAppender,
        const char *resourceName)
{
  OSuite::Statistics *p_m_requestsPerSecondSamples; // rbx
  OSuite::ZMetric *v7; // rax
  OSuite::ZMetric *v8; // rdi
  float Max; // xmm0_4
  float Average; // xmm0_4
  float Min; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4

  p_m_requestsPerSecondSamples = &this->m_requestsPerSecondSamples;
  if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState(&this->m_requestsPerSecondSamples) )
  {
    v7 = OSuite::ZMetricAppender::NewMetric(pMetricAppender, "UsageTracking");
    v8 = v7;
    if ( v7 )
    {
      OSuite::ZMetric::SetProperty(v7, "s_ResourceName", resourceName);
      OSuite::ZMetric::SetProperty(v8, "i32_TotalBytesSent", this->m_totalBytesSent);
      OSuite::ZMetric::SetProperty(v8, "i32_TotalRequests", this->m_totalRequests);
      OSuite::ZMetric::SetProperty(v8, "i32_MaxBytesSent", this->m_maxBytesSent);
      OSuite::ZMetric::SetProperty(v8, "i32_MinBytesSent", this->m_minBytesSent);
      Max = OSuite::Statistics::GetMax(p_m_requestsPerSecondSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxRequestsPerSecond", Max);
      Average = OSuite::Statistics::GetAverage(p_m_requestsPerSecondSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageRequestsPerSecond", Average);
      Min = OSuite::Statistics::GetMin(p_m_requestsPerSecondSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinRequestsPerSecond", Min);
      v12 = OSuite::Statistics::GetMax(&this->m_bytesPerSecondSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerSecondSent", v12);
      v13 = OSuite::Statistics::GetAverage(&this->m_bytesPerSecondSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerSecondSent", v13);
      v14 = OSuite::Statistics::GetMin(&this->m_bytesPerSecondSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerSecondSent", v14);
      v15 = OSuite::Statistics::GetMax(&this->m_bytesPerSecondReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerSecondReceived", v15);
      v16 = OSuite::Statistics::GetAverage(&this->m_bytesPerSecondReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerSecondReceived", v16);
      v17 = OSuite::Statistics::GetMin(&this->m_bytesPerSecondReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerSecondReceived", v17);
      v18 = OSuite::Statistics::GetMax(&this->m_bytesPerRequestSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerRequestSent", v18);
      v19 = OSuite::Statistics::GetAverage(&this->m_bytesPerRequestSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerRequestSent", v19);
      v20 = OSuite::Statistics::GetMin(&this->m_bytesPerRequestSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerRequestSent", v20);
      v21 = OSuite::Statistics::GetMax(&this->m_bytesPerRequestReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerRequestReceived", v21);
      v22 = OSuite::Statistics::GetAverage(&this->m_bytesPerRequestReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerRequestReceived", v22);
      v23 = OSuite::Statistics::GetMin(&this->m_bytesPerRequestReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerRequestReceived", v23);
      OSuite::ZMetricAppender::AddMetric(pMetricAppender, v8);
      OSuite::ZWebServiceClient::ReleaseEntry((OSuite::ZWebServiceClient *)pMetricAppender, (OSuite::ZOEntry *)v8);
    }
  }
}

// File Line: 455
// RVA: 0xED9430
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::Record(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 bytesSent,
        unsigned __int64 bytesReceived)
{
  unsigned __int64 Clock; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 m_maxBytesSent; // rax
  unsigned __int64 m_totalRequests; // rcx
  unsigned __int64 m_maxBytesReceived; // rax
  unsigned __int64 m_minBytesSent; // rax
  unsigned __int64 m_minBytesReceived; // rax

  OSuite::ZMutex::Lock(&this->m_mutex);
  Clock = OSuite::ZClock::_GetClock();
  v7 = OSuite::ZClock::_ClockToTime(Clock, UNIT_MILLI);
  this->m_sampleRecords.m_totalBytesSent += bytesSent;
  this->m_sampleRecords.m_totalBytesReceived += bytesReceived;
  ++this->m_sampleRecords.m_totalRequests;
  this->m_sampleRecords.m_lastTime = v7;
  m_maxBytesSent = this->m_maxBytesSent;
  m_totalRequests = this->m_totalRequests;
  if ( bytesSent > m_maxBytesSent )
    m_maxBytesSent = bytesSent;
  this->m_maxBytesSent = m_maxBytesSent;
  m_maxBytesReceived = this->m_maxBytesReceived;
  if ( bytesReceived > m_maxBytesReceived )
    m_maxBytesReceived = bytesReceived;
  this->m_maxBytesReceived = m_maxBytesReceived;
  if ( m_totalRequests )
  {
    m_minBytesSent = this->m_minBytesSent;
    if ( bytesSent < m_minBytesSent )
      m_minBytesSent = bytesSent;
    this->m_minBytesSent = m_minBytesSent;
    m_minBytesReceived = this->m_minBytesReceived;
    if ( bytesReceived < m_minBytesReceived )
      m_minBytesReceived = bytesReceived;
    this->m_minBytesReceived = m_minBytesReceived;
  }
  else
  {
    this->m_minBytesSent = bytesSent;
    this->m_minBytesReceived = bytesReceived;
  }
  this->m_totalBytesSent += bytesSent;
  this->m_totalBytesReceived += bytesReceived;
  this->m_totalRequests = m_totalRequests + 1;
  OSuite::ZMutex::Unlock(&this->m_mutex);
}

// File Line: 498
// RVA: 0xED8A1C
bool __fastcall OSuite::ZUsageTracker::ZResourceUsage::ExceedsThreshold(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        OSuite::ZUsageTracker::StatType thresholdType,
        float *outThresholdValue)
{
  float v4; // xmm6_4
  float v7; // xmm0_4
  unsigned __int64 Clock; // rax
  unsigned __int64 v9; // rax
  float v10; // xmm0_4

  v4 = 0.0;
  v7 = this->m_thresholds[thresholdType];
  *outThresholdValue = v7;
  if ( v7 > 0.0 )
  {
    Clock = OSuite::ZClock::_GetClock();
    v9 = OSuite::ZClock::_ClockToTime(Clock, UNIT_MILLI);
    if ( thresholdType )
    {
      if ( thresholdType != STATTYPE_BYTES_PER_SECOND_SENT )
        return v4 >= *outThresholdValue;
      v10 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondSent(this, v9);
    }
    else
    {
      v10 = OSuite::ZUsageTracker::ZResourceUsage::SampleRequestsPerSecond(this, v9);
    }
    v4 = v10;
    return v4 >= *outThresholdValue;
  }
  return 0;
}

// File Line: 534
// RVA: 0xED8E00
unsigned __int64 __fastcall OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
        OSuite::ZUsageTracker::ZResourceUsage *this,
        unsigned __int64 currentTime,
        unsigned __int64 *numRequests,
        unsigned __int64 *numBytesSent,
        unsigned __int64 *numBytesReceived)
{
  __int64 v9; // rdi

  v9 = 0i64;
  OSuite::ZMutex::Lock(&this->m_mutex);
  if ( this->m_sampleRecords.m_totalRequests )
  {
    *numBytesSent = this->m_sampleRecords.m_totalBytesSent;
    *numBytesReceived = this->m_sampleRecords.m_totalBytesReceived;
    *numRequests = this->m_sampleRecords.m_totalRequests;
    v9 = currentTime - this->m_sampleRecords.m_startTime;
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v9;
}

// File Line: 559
// RVA: 0xED9974
void __fastcall OSuite::ZUsageTracker::SetEnabled(OSuite::ZUsageTracker *this, bool bEnabled)
{
  this->m_bEnabled = bEnabled;
}

// File Line: 566
// RVA: 0xED9978
void __fastcall OSuitePrivate::ZPlayerConsumableData::SetConsumablesData(
        OSuite::ZUsageTracker *this,
        OSuite::ZMetricAppender *pMetricAppender)
{
  this->m_pMetricAppender = pMetricAppender;
}

// File Line: 580
// RVA: 0xED94F8
void __fastcall OSuite::ZUsageTracker::Record(
        OSuite::ZUsageTracker *this,
        const char *resourceName,
        unsigned __int64 bytesSent,
        unsigned __int64 bytesReceived)
{
  OSuite::ZObjectVtbl *ResourceUsage; // rbx
  float outThresholdValue; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_bEnabled )
  {
    ResourceUsage = OSuite::ZUsageTracker::GetResourceUsage(this, resourceName);
    OSuite::ZUsageTracker::ZResourceUsage::Record(
      (OSuite::ZUsageTracker::ZResourceUsage *)ResourceUsage,
      bytesSent,
      bytesReceived);
    OSuite::ZUsageTracker::ZResourceUsage::Record(this->m_overallUsage, bytesSent, bytesReceived);
    outThresholdValue = 0.0;
    OSuite::ZUsageTracker::ZResourceUsage::ExceedsThreshold(
      (OSuite::ZUsageTracker::ZResourceUsage *)ResourceUsage,
      STATTYPE_REQUESTS_PER_SECOND,
      &outThresholdValue);
  }
}

// File Line: 610
// RVA: 0xED8240
void __fastcall OSuite::ZUsageTracker::Configure(
        OSuite::ZUsageTracker *this,
        unsigned __int64 samplingInterval,
        unsigned __int64 metricsInterval)
{
  this->m_samplingInterval = samplingInterval;
  this->m_metricsInterval = metricsInterval;
}

// File Line: 860
// RVA: 0xED87F8
void __fastcall OSuite::ZUsageTracker::DumpUsageStatistics(OSuite::ZUsageTracker *this)
{
  OSuite::ZStringBuilder v2; // [rsp+20h] [rbp-69h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+50h] [rbp-39h] BYREF

  v2.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v2, 0x800ui64);
  OSuite::ZStringBuilder::AppendFormat(&v2, "\n\nUsage Statistics Summary\n------------------------------------\n");
  OSuite::ZStringBuilder::AppendFormat(&v2, "\n---- By Resource -----------------\n");
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_resourceStatistics,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    OSuite::ZString::c_str((OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZStringBuilder::AppendFormat(
    &v2,
    "\n-------------------------------------\nEnd of Usage Statistics Summary\n\n");
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v2);
}

// File Line: 885
// RVA: 0xED7A20
void __fastcall OSuite::ZUsageTracker::ZUsageTracker(OSuite::ZUsageTracker *this)
{
  unsigned __int64 Clock; // rax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rax
  OSuite::ZUsageTracker::ZResourceUsage *v5; // rbx
  OSuite::ZUsageTracker::ZResourceUsage *v6; // rax
  OSuite::ZUsageTracker::ZResourceUsage *v7; // rax

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::`vftable;
  this->m_samplingInterval = USAGETRACKER_DEFAULT_SAMPLING_INTERVAL;
  this->m_metricsInterval = USAGETRACKER_DEFAULT_METRICS_INTERVAL;
  Clock = OSuite::ZClock::_GetClock();
  this->m_lastSampleTime = OSuite::ZClock::_ClockToTime(Clock, UNIT_MILLI);
  v3 = OSuite::ZClock::_GetClock();
  v4 = OSuite::ZClock::_ClockToTime(v3, UNIT_MILLI);
  v5 = 0i64;
  this->m_overallUsage = 0i64;
  this->m_pMetricAppender = 0i64;
  this->m_lastMetricsTime = v4;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  this->m_bEnabled = 0;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_resourceStatistics,
    0x10ui64);
  v6 = (OSuite::ZUsageTracker::ZResourceUsage *)OSuite::ZObject::operator new(0x180ui64);
  if ( v6 )
  {
    v6->m_mutex.m_pInternalMutex = 0i64;
    v6->m_requestsPerSecondSamples.maData = 0i64;
    v6->m_bytesPerSecondSentSamples.maData = 0i64;
    v6->m_bytesPerRequestSentSamples.maData = 0i64;
    v6->m_bytesPerSecondReceivedSamples.maData = 0i64;
    v6->m_bytesPerRequestReceivedSamples.maData = 0i64;
    OSuite::ZUsageTracker::ZResourceUsage::ZResourceUsage(v6);
    v5 = v7;
  }
  this->m_overallUsage = v5;
}

// File Line: 892
// RVA: 0xED7B8C
void __fastcall OSuite::ZUsageTracker::~ZUsageTracker(OSuite::ZUsageTracker *this)
{
  OSuite::ZUsageTracker::ZResourceUsage *m_overallUsage; // rcx
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::`vftable;
  m_overallUsage = this->m_overallUsage;
  if ( m_overallUsage )
    m_overallUsage->vfptr->__vecDelDtor(m_overallUsage, 1u);
  this->m_overallUsage = 0i64;
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_resourceStatistics,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear((OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_resourceStatistics);
  m_pList = result.m_iterator.m_iterator.m_parents.m_pList;
  this->m_pMetricAppender = 0i64;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  m_pLists = this->m_resourceStatistics.m_pLists;
  this->m_resourceStatistics.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
}

// File Line: 910
// RVA: 0xED9678
void __fastcall OSuite::ZUsageTracker::Sample(OSuite::ZUsageTracker *this)
{
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  OSuite::ZUsageTracker::ZResourceUsage::Sample(this->m_overallUsage);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_resourceStatistics,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    OSuite::ZUsageTracker::ZResourceUsage::Sample((OSuite::ZUsageTracker::ZResourceUsage *)result.m_iterator.m_iterator.m_pElement[2].vfptr);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 923
// RVA: 0xED8660
void __fastcall OSuite::ZUsageTracker::CreateMetrics(OSuite::ZUsageTracker *this)
{
  OSuite::ZMetricAppender *m_pMetricAppender; // rdx
  OSuite::ZObjectVtbl *vfptr; // rbx
  const char *v4; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  m_pMetricAppender = this->m_pMetricAppender;
  if ( m_pMetricAppender )
  {
    OSuite::ZUsageTracker::ZResourceUsage::CreateMetrics(
      this->m_overallUsage,
      m_pMetricAppender,
      USAGETRACKER_OVERALL_STATLABEL);
    result.m_pMap = 0i64;
    result.m_iterator.m_iterator.m_pList = 0i64;
    result.m_iterator.m_iterator.m_pElement = 0i64;
    result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_resourceStatistics,
      &result);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    {
      vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
      v4 = OSuite::ZString::c_str((OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      OSuite::ZUsageTracker::ZResourceUsage::CreateMetrics(
        (OSuite::ZUsageTracker::ZResourceUsage *)vfptr,
        this->m_pMetricAppender,
        v4);
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
}

// File Line: 944
// RVA: 0xED9980
void __fastcall OSuite::ZUsageTracker::Update(OSuite::ZUsageTracker *this, unsigned __int64 currentTime)
{
  bool v4; // si

  v4 = currentTime - this->m_lastMetricsTime >= this->m_metricsInterval;
  if ( currentTime - this->m_lastSampleTime >= this->m_samplingInterval )
  {
    this->m_lastSampleTime = currentTime;
    OSuite::ZUsageTracker::Sample(this);
  }
  if ( v4 )
  {
    this->m_lastMetricsTime = currentTime;
    OSuite::ZUsageTracker::CreateMetrics(this);
  }
}

// File Line: 965
// RVA: 0xED8F64
OSuite::ZObjectVtbl *__fastcall OSuite::ZUsageTracker::GetResourceUsage(
        OSuite::ZUsageTracker *this,
        const char *resourceName)
{
  OSuite::ZMutex *p_m_mutex; // rbx
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *p_m_resourceStatistics; // rsi
  OSuite::ZUsageTracker::ZResourceUsage *v6; // rax
  OSuite::ZUsageTracker *v7; // rax
  OSuite::ZObjectVtbl *vfptr; // rdi
  OSuite::ZUsageTracker *value; // [rsp+20h] [rbp-69h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+28h] [rbp-61h] BYREF
  OSuite::ZString key; // [rsp+A8h] [rbp+1Fh] BYREF

  if ( !resourceName )
    return (OSuite::ZObjectVtbl *)this->m_overallUsage;
  key.m_pString = 0i64;
  OSuite::ZString::ZString(&key, resourceName);
  p_m_mutex = &this->m_mutex;
  OSuite::ZMutex::Lock(&this->m_mutex);
  p_m_resourceStatistics = &this->m_resourceStatistics;
  if ( OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Exists(&this->m_resourceStatistics, &key) )
  {
    vfptr = OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(
              (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_resourceStatistics,
              &result,
              &key)->m_iterator.m_iterator.m_pElement[2].vfptr;
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  else
  {
    v6 = (OSuite::ZUsageTracker::ZResourceUsage *)OSuite::ZObject::operator new(0x180ui64);
    if ( v6 )
    {
      v6->m_mutex.m_pInternalMutex = 0i64;
      v6->m_requestsPerSecondSamples.maData = 0i64;
      v6->m_bytesPerSecondSentSamples.maData = 0i64;
      v6->m_bytesPerRequestSentSamples.maData = 0i64;
      v6->m_bytesPerSecondReceivedSamples.maData = 0i64;
      v6->m_bytesPerRequestReceivedSamples.maData = 0i64;
      OSuite::ZUsageTracker::ZResourceUsage::ZResourceUsage(v6);
      vfptr = (OSuite::ZObjectVtbl *)v7;
      value = v7;
    }
    else
    {
      vfptr = 0i64;
      value = 0i64;
    }
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::Insert(
      (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)p_m_resourceStatistics,
      &key,
      &value);
  }
  OSuite::ZMutex::Unlock(p_m_mutex);
  OSuite::ZString::~ZString(&key);
  return vfptr;
}

