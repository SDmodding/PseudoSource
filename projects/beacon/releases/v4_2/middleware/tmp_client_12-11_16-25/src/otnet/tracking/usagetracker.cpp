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
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *v1; // rbx
  OSuite::ZObjectVtbl *v2; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v1 = &this->m_trackers;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTrackingManager::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_trackers,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v2 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( v2 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v2->__vecDelDtor)(v2, 1i64);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear(v1);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  v3 = v1->m_pLists;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( v3 )
  {
    if ( LODWORD(v3[-1].m_Comparer.vfptr) )
      v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v3[-1].m_Comparer.vfptr);
  }
}

// File Line: 52
// RVA: 0xED824C
OSuite::ZObjectVtbl *__fastcall OSuite::ZUsageTrackingManager::CreateForHost(OSuite::ZUsageTrackingManager *this, const char *hostName)
{
  OSuite::ZUsageTrackingManager *v2; // rsi
  const char *v3; // rdi
  OSuite::ZObjectVtbl *v4; // rbx
  OSuite::ZUsageTracker *v5; // rax
  OSuite::ZUsageTracker *v6; // rax
  OSuite::ZUsageTracker *value; // [rsp+20h] [rbp-89h]
  OSuite::ZString v9; // [rsp+28h] [rbp-81h]
  OSuite::ZString key; // [rsp+40h] [rbp-69h]
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+60h] [rbp-49h]

  key.m_pString = 0i64;
  v2 = this;
  v3 = hostName;
  OSuite::ZString::ZString(&key, hostName);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(&v2->m_trackers, &result, &key);
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
      v4 = (OSuite::ZObjectVtbl *)v6;
      value = v6;
    }
    else
    {
      v4 = 0i64;
      value = 0i64;
    }
    OSuite::ZString::ZString(&v9, v3);
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::Insert(&v2->m_trackers, &v9, &value);
    OSuite::ZString::~ZString(&v9);
  }
  else
  {
    v4 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZString::~ZString(&key);
  return v4;
}

// File Line: 70
// RVA: 0xED8E80
OSuite::ZObjectVtbl *__fastcall OSuite::ZUsageTrackingManager::GetForHost(OSuite::ZUsageTrackingManager *this, const char *hostName)
{
  OSuite::ZUsageTrackingManager *v2; // rbx
  OSuite::ZObjectVtbl *v3; // rbx
  OSuite::ZString key; // [rsp+20h] [rbp-59h]
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+40h] [rbp-39h]

  key.m_pString = 0i64;
  v2 = this;
  OSuite::ZString::ZString(&key, hostName);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(&v2->m_trackers, &result, &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    v3 = 0i64;
  else
    v3 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZString::~ZString(&key);
  return v3;
}

// File Line: 83
// RVA: 0xED99DC
void __fastcall OSuite::ZUsageTrackingManager::Update(OSuite::ZUsageTrackingManager *this)
{
  OSuite::ZUsageTrackingManager *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdi
  OSuite::ZUsageTracker *v5; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  v1 = this;
  v2 = OSuite::ZClock::_GetClock();
  v3 = OSuite::ZClock::_ClockToTime(v2, UNIT_MILLI);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v4 = v3;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v1->m_trackers,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v5 = (OSuite::ZUsageTracker *)result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( v5->m_bEnabled )
      OSuite::ZUsageTracker::Update(v5, v4);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 99
// RVA: 0xED8914
void __fastcall OSuite::ZUsageTrackingManager::DumpUsageStatistics(OSuite::ZUsageTrackingManager *this)
{
  OSuite::ZUsageTracker *v1; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_trackers,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v1 = (OSuite::ZUsageTracker *)result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( v1->m_bEnabled )
      OSuite::ZUsageTracker::DumpUsageStatistics(v1);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 167
// RVA: 0xED7B24
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::~ZResourceUsage(OSuite::ZUsageTracker::ZResourceUsage *this)
{
  OSuite::ZUsageTracker::ZResourceUsage *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::ZResourceUsage::`vftable;
  OSuite::Statistics::~Statistics(&this->m_bytesPerRequestReceivedSamples);
  OSuite::Statistics::~Statistics(&v1->m_bytesPerSecondReceivedSamples);
  OSuite::Statistics::~Statistics(&v1->m_bytesPerRequestSentSamples);
  OSuite::Statistics::~Statistics(&v1->m_bytesPerSecondSentSamples);
  OSuite::Statistics::~Statistics(&v1->m_requestsPerSecondSamples);
  v1->m_sampleRecords.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  OSuite::ZMutex::~ZMutex(&v1->m_mutex);
}

// File Line: 253
// RVA: 0xED793C
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::ZResourceUsage(OSuite::ZUsageTracker::ZResourceUsage *this)
{
  OSuite::ZUsageTracker::ZResourceUsage *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rax

  this->m_totalRequests = 0i64;
  this->m_totalBytesSent = 0i64;
  this->m_totalBytesReceived = 0i64;
  this->m_maxBytesSent = 0i64;
  this->m_minBytesSent = 0i64;
  this->m_maxBytesReceived = 0i64;
  this->m_minBytesReceived = 0i64;
  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::ZResourceUsage::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  v1->m_sampleRecords.m_totalBytesSent = 0i64;
  v1->m_sampleRecords.m_totalBytesReceived = 0i64;
  v1->m_sampleRecords.m_totalRequests = 0i64;
  v1->m_sampleRecords.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  v2 = OSuite::ZClock::_GetClock();
  v3 = OSuite::ZClock::_ClockToTime(v2, UNIT_MILLI);
  v1->m_sampleRecords.m_lastTime = 0i64;
  v1->m_sampleRecords.m_startTime = v3;
  OSuite::Statistics::Statistics(&v1->m_requestsPerSecondSamples, 1);
  OSuite::Statistics::Statistics(&v1->m_bytesPerSecondSentSamples, 1);
  OSuite::Statistics::Statistics(&v1->m_bytesPerRequestSentSamples, 1);
  OSuite::Statistics::Statistics(&v1->m_bytesPerSecondReceivedSamples, 1);
  OSuite::Statistics::Statistics(&v1->m_bytesPerRequestReceivedSamples, 1);
  memset(v1->m_thresholds, 0, 8ui64);
}

// File Line: 307
// RVA: 0xED990C
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleRequestsPerSecond(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 currentTime)
{
  signed __int64 v2; // rax
  float result; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  __int64 v7; // [rsp+30h] [rbp-18h]
  __int64 v8; // [rsp+60h] [rbp+18h]
  __int64 v9; // [rsp+68h] [rbp+20h]

  v8 = 0i64;
  v2 = OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
         this,
         currentTime,
         (unsigned __int64 *)&v8,
         (unsigned __int64 *)&v7,
         (unsigned __int64 *)&v9);
  result = 0.0;
  if ( v2 )
  {
    v4 = (float)(signed int)v8;
    if ( v8 < 0 )
      v4 = v4 + 1.8446744e19;
    v5 = v4 * 1000.0;
    v6 = (float)(signed int)v2;
    if ( v2 < 0 )
      v6 = v6 + 1.8446744e19;
    result = v5 / v6;
  }
  return result;
}

// File Line: 323
// RVA: 0xED98A4
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondSent(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 currentTime)
{
  signed __int64 v2; // rax
  float result; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  __int64 v7; // [rsp+30h] [rbp-18h]
  __int64 v8; // [rsp+60h] [rbp+18h]
  __int64 v9; // [rsp+68h] [rbp+20h]

  v8 = 0i64;
  v2 = OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
         this,
         currentTime,
         (unsigned __int64 *)&v7,
         (unsigned __int64 *)&v8,
         (unsigned __int64 *)&v9);
  result = 0.0;
  if ( v2 )
  {
    v4 = (float)(signed int)v8;
    if ( v8 < 0 )
      v4 = v4 + 1.8446744e19;
    v5 = v4 * 1000.0;
    v6 = (float)(signed int)v2;
    if ( v2 < 0 )
      v6 = v6 + 1.8446744e19;
    result = v5 / v6;
  }
  return result;
}

// File Line: 339
// RVA: 0xED97C8
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestSent(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 currentTime)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  __int64 v5; // [rsp+30h] [rbp-18h]
  __int64 v6; // [rsp+60h] [rbp+18h]
  __int64 v7; // [rsp+68h] [rbp+20h]

  v7 = 0i64;
  v6 = 0i64;
  if ( !OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
          this,
          currentTime,
          (unsigned __int64 *)&v6,
          (unsigned __int64 *)&v7,
          (unsigned __int64 *)&v5)
    || !v6 )
  {
    return 0.0;
  }
  v2 = (float)(signed int)v7;
  if ( v7 < 0 )
    v2 = v2 + 1.8446744e19;
  v3 = (float)(signed int)v6;
  if ( v6 < 0 )
    v3 = v3 + 1.8446744e19;
  return v2 / v3;
}

// File Line: 354
// RVA: 0xED983C
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondReceived(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 currentTime)
{
  signed __int64 v2; // rax
  float result; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  __int64 v7; // [rsp+30h] [rbp-18h]
  __int64 v8; // [rsp+60h] [rbp+18h]
  __int64 v9; // [rsp+68h] [rbp+20h]

  v8 = 0i64;
  v2 = OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
         this,
         currentTime,
         (unsigned __int64 *)&v7,
         (unsigned __int64 *)&v9,
         (unsigned __int64 *)&v8);
  result = 0.0;
  if ( v2 )
  {
    v4 = (float)(signed int)v8;
    if ( v8 < 0 )
      v4 = v4 + 1.8446744e19;
    v5 = v4 * 1000.0;
    v6 = (float)(signed int)v2;
    if ( v2 < 0 )
      v6 = v6 + 1.8446744e19;
    result = v5 / v6;
  }
  return result;
}

// File Line: 370
// RVA: 0xED9754
float __fastcall OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestReceived(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 currentTime)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  __int64 v5; // [rsp+30h] [rbp-18h]
  __int64 v6; // [rsp+60h] [rbp+18h]
  __int64 v7; // [rsp+68h] [rbp+20h]

  v7 = 0i64;
  v6 = 0i64;
  if ( !OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(
          this,
          currentTime,
          (unsigned __int64 *)&v6,
          (unsigned __int64 *)&v5,
          (unsigned __int64 *)&v7)
    || !v6 )
  {
    return 0.0;
  }
  v2 = (float)(signed int)v7;
  if ( v7 < 0 )
    v2 = v2 + 1.8446744e19;
  v3 = (float)(signed int)v6;
  if ( v6 < 0 )
    v3 = v3 + 1.8446744e19;
  return v2 / v3;
}

// File Line: 385
// RVA: 0xED9570
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::Sample(OSuite::ZUsageTracker::ZResourceUsage *this)
{
  OSuite::ZUsageTracker::ZResourceUsage *v1; // rsi
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_mutex);
  if ( v1->m_sampleRecords.m_totalRequests )
  {
    v2 = OSuite::ZClock::_GetClock();
    v3 = OSuite::ZClock::_ClockToTime(v2, UNIT_MILLI);
    v4 = OSuite::ZUsageTracker::ZResourceUsage::SampleRequestsPerSecond(v1, v3);
    OSuite::Statistics::AddValue(&v1->m_requestsPerSecondSamples, v4);
    v5 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondSent(v1, v3);
    OSuite::Statistics::AddValue(&v1->m_bytesPerSecondSentSamples, v5);
    v6 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestSent(v1, v3);
    OSuite::Statistics::AddValue(&v1->m_bytesPerRequestSentSamples, v6);
    v7 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondReceived(v1, v3);
    OSuite::Statistics::AddValue(&v1->m_bytesPerSecondReceivedSamples, v7);
    v8 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerRequestReceived(v1, v3);
    OSuite::Statistics::AddValue(&v1->m_bytesPerRequestReceivedSamples, v8);
    v9 = OSuite::ZClock::_GetClock();
    v10 = OSuite::ZClock::_ClockToTime(v9, UNIT_MILLI);
    v1->m_sampleRecords.m_lastTime = 0i64;
    v1->m_sampleRecords.m_totalBytesSent = 0i64;
    v1->m_sampleRecords.m_totalBytesReceived = 0i64;
    v1->m_sampleRecords.m_totalRequests = 0i64;
    v1->m_sampleRecords.m_startTime = v10;
  }
  OSuite::ZMutex::Unlock(&v1->m_mutex);
}

// File Line: 404
// RVA: 0xED839C
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::CreateMetrics(OSuite::ZUsageTracker::ZResourceUsage *this, OSuite::ZMetricAppender *pMetricAppender, const char *resourceName)
{
  OSuite::Statistics *v3; // rbx
  OSuite::ZUsageTracker::ZResourceUsage *v4; // rsi
  const char *v5; // r14
  OSuite::ZMetricAppender *v6; // rbp
  OSuite::ZMetric *v7; // rax
  OSuite::ZMetric *v8; // rdi
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
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

  v3 = &this->m_requestsPerSecondSamples;
  v4 = this;
  v5 = resourceName;
  v6 = pMetricAppender;
  if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState(&this->m_requestsPerSecondSamples) )
  {
    v7 = OSuite::ZMetricAppender::NewMetric(v6, "UsageTracking");
    v8 = v7;
    if ( v7 )
    {
      OSuite::ZMetric::SetProperty(v7, "s_ResourceName", v5);
      OSuite::ZMetric::SetProperty(v8, "i32_TotalBytesSent", v4->m_totalBytesSent);
      OSuite::ZMetric::SetProperty(v8, "i32_TotalRequests", v4->m_totalRequests);
      OSuite::ZMetric::SetProperty(v8, "i32_MaxBytesSent", v4->m_maxBytesSent);
      OSuite::ZMetric::SetProperty(v8, "i32_MinBytesSent", v4->m_minBytesSent);
      v9 = OSuite::Statistics::GetMax(v3);
      OSuite::ZMetric::SetProperty(v8, "f_MaxRequestsPerSecond", v9);
      v10 = OSuite::Statistics::GetAverage(v3);
      OSuite::ZMetric::SetProperty(v8, "f_AverageRequestsPerSecond", v10);
      v11 = OSuite::Statistics::GetMin(v3);
      OSuite::ZMetric::SetProperty(v8, "f_MinRequestsPerSecond", v11);
      v12 = OSuite::Statistics::GetMax(&v4->m_bytesPerSecondSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerSecondSent", v12);
      v13 = OSuite::Statistics::GetAverage(&v4->m_bytesPerSecondSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerSecondSent", v13);
      v14 = OSuite::Statistics::GetMin(&v4->m_bytesPerSecondSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerSecondSent", v14);
      v15 = OSuite::Statistics::GetMax(&v4->m_bytesPerSecondReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerSecondReceived", v15);
      v16 = OSuite::Statistics::GetAverage(&v4->m_bytesPerSecondReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerSecondReceived", v16);
      v17 = OSuite::Statistics::GetMin(&v4->m_bytesPerSecondReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerSecondReceived", v17);
      v18 = OSuite::Statistics::GetMax(&v4->m_bytesPerRequestSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerRequestSent", v18);
      v19 = OSuite::Statistics::GetAverage(&v4->m_bytesPerRequestSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerRequestSent", v19);
      v20 = OSuite::Statistics::GetMin(&v4->m_bytesPerRequestSentSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerRequestSent", v20);
      v21 = OSuite::Statistics::GetMax(&v4->m_bytesPerRequestReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MaxBytesPerRequestReceived", v21);
      v22 = OSuite::Statistics::GetAverage(&v4->m_bytesPerRequestReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_AverageBytesPerRequestReceived", v22);
      v23 = OSuite::Statistics::GetMin(&v4->m_bytesPerRequestReceivedSamples);
      OSuite::ZMetric::SetProperty(v8, "f_MinBytesPerRequestReceived", v23);
      OSuite::ZMetricAppender::AddMetric(v6, v8);
      OSuite::ZWebServiceClient::ReleaseEntry((OSuite::ZWebServiceClient *)v6, (OSuite::ZOEntry *)v8);
    }
  }
}

// File Line: 455
// RVA: 0xED9430
void __fastcall OSuite::ZUsageTracker::ZResourceUsage::Record(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 bytesSent, unsigned __int64 bytesReceived)
{
  OSuite::ZUsageTracker::ZResourceUsage *v3; // rdi
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax

  v3 = this;
  v4 = bytesReceived;
  v5 = bytesSent;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v6 = OSuite::ZClock::_GetClock();
  v7 = OSuite::ZClock::_ClockToTime(v6, UNIT_MILLI);
  v3->m_sampleRecords.m_totalBytesSent += v5;
  v3->m_sampleRecords.m_totalBytesReceived += v4;
  ++v3->m_sampleRecords.m_totalRequests;
  v3->m_sampleRecords.m_lastTime = v7;
  v8 = v3->m_maxBytesSent;
  v9 = v3->m_totalRequests;
  if ( v5 > v8 )
    v8 = v5;
  v3->m_maxBytesSent = v8;
  v10 = v3->m_maxBytesReceived;
  if ( v4 > v10 )
    v10 = v4;
  v3->m_maxBytesReceived = v10;
  if ( v9 )
  {
    v11 = v3->m_minBytesSent;
    if ( v5 < v11 )
      v11 = v5;
    v3->m_minBytesSent = v11;
    v12 = v3->m_minBytesReceived;
    if ( v4 < v12 )
      v12 = v4;
    v3->m_minBytesReceived = v12;
  }
  else
  {
    v3->m_minBytesSent = v5;
    v3->m_minBytesReceived = v4;
  }
  v3->m_totalBytesSent += v5;
  v3->m_totalBytesReceived += v4;
  v3->m_totalRequests = v9 + 1;
  OSuite::ZMutex::Unlock(&v3->m_mutex);
}

// File Line: 498
// RVA: 0xED8A1C
bool __fastcall OSuite::ZUsageTracker::ZResourceUsage::ExceedsThreshold(OSuite::ZUsageTracker::ZResourceUsage *this, OSuite::ZUsageTracker::StatType thresholdType, float *outThresholdValue)
{
  OSuite::ZUsageTracker::StatType v3; // ebx
  float v4; // xmm6_4
  float *v5; // rbp
  OSuite::ZUsageTracker::ZResourceUsage *v6; // rsi
  float v7; // xmm0_4
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rax
  float v10; // xmm0_4

  v3 = thresholdType;
  v4 = 0.0;
  v5 = outThresholdValue;
  v6 = this;
  v7 = this->m_thresholds[thresholdType];
  *outThresholdValue = v7;
  if ( v7 > 0.0 )
  {
    v8 = OSuite::ZClock::_GetClock();
    v9 = OSuite::ZClock::_ClockToTime(v8, UNIT_MILLI);
    if ( v3 )
    {
      if ( v3 != 1 )
        return v4 >= *v5;
      v10 = OSuite::ZUsageTracker::ZResourceUsage::SampleBytesPerSecondSent(v6, v9);
    }
    else
    {
      v10 = OSuite::ZUsageTracker::ZResourceUsage::SampleRequestsPerSecond(v6, v9);
    }
    v4 = v10;
    return v4 >= *v5;
  }
  return 0;
}

// File Line: 534
// RVA: 0xED8E00
unsigned __int64 __fastcall OSuite::ZUsageTracker::ZResourceUsage::GatherStatistics(OSuite::ZUsageTracker::ZResourceUsage *this, unsigned __int64 currentTime, unsigned __int64 *numRequests, unsigned __int64 *numBytesSent, unsigned __int64 *numBytesReceived)
{
  OSuite::ZUsageTracker::ZResourceUsage *v5; // rsi
  unsigned __int64 *v6; // r14
  unsigned __int64 *v7; // r15
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // rdi

  v5 = this;
  v6 = numBytesSent;
  v7 = numRequests;
  v8 = currentTime;
  v9 = 0i64;
  OSuite::ZMutex::Lock(&this->m_mutex);
  if ( v5->m_sampleRecords.m_totalRequests > 0 )
  {
    *v6 = v5->m_sampleRecords.m_totalBytesSent;
    *numBytesReceived = v5->m_sampleRecords.m_totalBytesReceived;
    *v7 = v5->m_sampleRecords.m_totalRequests;
    v9 = v8 - v5->m_sampleRecords.m_startTime;
  }
  OSuite::ZMutex::Unlock(&v5->m_mutex);
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
void __fastcall OSuitePrivate::ZPlayerConsumableData::SetConsumablesData(OSuite::ZUsageTracker *this, OSuite::ZMetricAppender *pMetricAppender)
{
  this->m_pMetricAppender = pMetricAppender;
}

// File Line: 580
// RVA: 0xED94F8
void __fastcall OSuite::ZUsageTracker::Record(OSuite::ZUsageTracker *this, const char *resourceName, unsigned __int64 bytesSent, unsigned __int64 bytesReceived)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  OSuite::ZUsageTracker *v6; // rdi
  OSuite::ZObjectVtbl *v7; // rbx
  float outThresholdValue; // [rsp+30h] [rbp+8h]

  v4 = bytesReceived;
  v5 = bytesSent;
  v6 = this;
  if ( this->m_bEnabled )
  {
    v7 = OSuite::ZUsageTracker::GetResourceUsage(this, resourceName);
    OSuite::ZUsageTracker::ZResourceUsage::Record((OSuite::ZUsageTracker::ZResourceUsage *)v7, v5, v4);
    OSuite::ZUsageTracker::ZResourceUsage::Record(v6->m_overallUsage, v5, v4);
    outThresholdValue = 0.0;
    OSuite::ZUsageTracker::ZResourceUsage::ExceedsThreshold(
      (OSuite::ZUsageTracker::ZResourceUsage *)v7,
      0,
      &outThresholdValue);
  }
}

// File Line: 610
// RVA: 0xED8240
void __fastcall OSuite::ZUsageTracker::Configure(OSuite::ZUsageTracker *this, unsigned __int64 samplingInterval, unsigned __int64 metricsInterval)
{
  this->m_samplingInterval = samplingInterval;
  this->m_metricsInterval = metricsInterval;
}

// File Line: 860
// RVA: 0xED87F8
void __fastcall OSuite::ZUsageTracker::DumpUsageStatistics(OSuite::ZUsageTracker *this)
{
  OSuite::ZUsageTracker *v1; // rbx
  OSuite::ZStringBuilder v2; // [rsp+20h] [rbp-69h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+50h] [rbp-39h]

  v2.m_Chars.m_pList = 0i64;
  v1 = this;
  OSuite::ZStringBuilder::ZStringBuilder(&v2, 0x800ui64);
  OSuite::ZStringBuilder::AppendFormat(&v2, "\n\nUsage Statistics Summary\n------------------------------------\n");
  OSuite::ZStringBuilder::AppendFormat(&v2, "\n---- By Resource -----------------\n");
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v1->m_resourceStatistics,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    OSuite::ZString::c_str((OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
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
  OSuite::ZUsageTracker *v1; // rdi
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rax
  OSuite::ZUsageTracker::ZResourceUsage *v5; // rbx
  OSuite::ZUsageTracker::ZResourceUsage *v6; // rax
  OSuite::ZUsageTracker::ZResourceUsage *v7; // rax

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::`vftable;
  this->m_samplingInterval = USAGETRACKER_DEFAULT_SAMPLING_INTERVAL;
  this->m_metricsInterval = USAGETRACKER_DEFAULT_METRICS_INTERVAL;
  v2 = OSuite::ZClock::_GetClock();
  v1->m_lastSampleTime = OSuite::ZClock::_ClockToTime(v2, UNIT_MILLI);
  v3 = OSuite::ZClock::_GetClock();
  v4 = OSuite::ZClock::_ClockToTime(v3, UNIT_MILLI);
  v5 = 0i64;
  v1->m_overallUsage = 0i64;
  v1->m_pMetricAppender = 0i64;
  v1->m_lastMetricsTime = v4;
  OSuite::ZMutex::ZMutex(&v1->m_mutex);
  v1->m_bEnabled = 0;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&v1->m_resourceStatistics,
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
  v1->m_overallUsage = v5;
}

// File Line: 892
// RVA: 0xED7B8C
void __fastcall OSuite::ZUsageTracker::~ZUsageTracker(OSuite::ZUsageTracker *this)
{
  OSuite::ZUsageTracker *v1; // rbx
  OSuite::ZUsageTracker::ZResourceUsage *v2; // rcx
  OSuite::ZObjectVtbl *v3; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v4; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString> > *v5; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUsageTracker::`vftable;
  v2 = this->m_overallUsage;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v1->m_overallUsage = 0i64;
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v1->m_resourceStatistics,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v3 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( v3 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear((OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&v1->m_resourceStatistics);
  v4 = result.m_iterator.m_iterator.m_parents.m_pList;
  v1->m_pMetricAppender = 0i64;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v4 )
    v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
  v5 = v1->m_resourceStatistics.m_pLists;
  v1->m_resourceStatistics.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( v5 )
  {
    if ( LODWORD(v5[-1].m_Comparer.vfptr) )
      v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v5[-1].m_Comparer.vfptr);
  }
  OSuite::ZMutex::~ZMutex(&v1->m_mutex);
}

// File Line: 910
// RVA: 0xED9678
void __fastcall OSuite::ZUsageTracker::Sample(OSuite::ZUsageTracker *this)
{
  OSuite::ZUsageTracker *v1; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  v1 = this;
  OSuite::ZUsageTracker::ZResourceUsage::Sample(this->m_overallUsage);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v1->m_resourceStatistics,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    OSuite::ZUsageTracker::ZResourceUsage::Sample((OSuite::ZUsageTracker::ZResourceUsage *)result.m_iterator.m_iterator.m_pElement[2].vfptr);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 923
// RVA: 0xED8660
void __fastcall OSuite::ZUsageTracker::CreateMetrics(OSuite::ZUsageTracker *this)
{
  OSuite::ZMetricAppender *v1; // rdx
  OSuite::ZUsageTracker *v2; // rdi
  OSuite::ZObjectVtbl *v3; // rbx
  const char *v4; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  v1 = this->m_pMetricAppender;
  v2 = this;
  if ( v1 )
  {
    OSuite::ZUsageTracker::ZResourceUsage::CreateMetrics(this->m_overallUsage, v1, USAGETRACKER_OVERALL_STATLABEL);
    result.m_pMap = 0i64;
    result.m_iterator.m_iterator.m_pList = 0i64;
    result.m_iterator.m_iterator.m_pElement = 0i64;
    result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v2->m_resourceStatistics,
      &result);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    {
      v3 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
      v4 = OSuite::ZString::c_str((OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      OSuite::ZUsageTracker::ZResourceUsage::CreateMetrics(
        (OSuite::ZUsageTracker::ZResourceUsage *)v3,
        v2->m_pMetricAppender,
        v4);
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
}

// File Line: 944
// RVA: 0xED9980
void __fastcall OSuite::ZUsageTracker::Update(OSuite::ZUsageTracker *this, unsigned __int64 currentTime)
{
  unsigned __int64 v2; // rdi
  OSuite::ZUsageTracker *v3; // rbx
  bool v4; // si

  v2 = currentTime;
  v3 = this;
  v4 = currentTime - this->m_lastMetricsTime >= this->m_metricsInterval;
  if ( currentTime - this->m_lastSampleTime >= this->m_samplingInterval )
  {
    this->m_lastSampleTime = currentTime;
    OSuite::ZUsageTracker::Sample(this);
  }
  if ( v4 )
  {
    v3->m_lastMetricsTime = v2;
    OSuite::ZUsageTracker::CreateMetrics(v3);
  }
}

// File Line: 965
// RVA: 0xED8F64
OSuite::ZObjectVtbl *__fastcall OSuite::ZUsageTracker::GetResourceUsage(OSuite::ZUsageTracker *this, const char *resourceName)
{
  OSuite::ZUsageTracker *v2; // rdi
  OSuite::ZMutex *v4; // rbx
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *v5; // rsi
  OSuite::ZUsageTracker::ZResourceUsage *v6; // rax
  OSuite::ZUsageTracker *v7; // rax
  OSuite::ZObjectVtbl *v8; // rdi
  OSuite::ZUsageTracker *value; // [rsp+20h] [rbp-69h]
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+28h] [rbp-61h]
  OSuite::ZString key; // [rsp+A8h] [rbp+1Fh]

  v2 = this;
  if ( !resourceName )
    return (OSuite::ZObjectVtbl *)this->m_overallUsage;
  key.m_pString = 0i64;
  OSuite::ZString::ZString(&key, resourceName);
  v4 = &v2->m_mutex;
  OSuite::ZMutex::Lock(&v2->m_mutex);
  v5 = (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&v2->m_resourceStatistics;
  if ( OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Exists(&v2->m_resourceStatistics, &key) )
  {
    v8 = OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(
           (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&v2->m_resourceStatistics,
           &result,
           &key)->m_iterator.m_iterator.m_pElement[2].vfptr;
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
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
      v8 = (OSuite::ZObjectVtbl *)v7;
      value = v7;
    }
    else
    {
      v8 = 0i64;
      value = 0i64;
    }
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::Insert(v5, &key, &value);
  }
  OSuite::ZMutex::Unlock(v4);
  OSuite::ZString::~ZString(&key);
  return v8;
}

