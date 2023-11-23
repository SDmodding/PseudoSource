// File Line: 7
// RVA: 0xEEA080
void __fastcall OSuite::ZObjectAccessor::ZObjectAccessor(OSuite::ZObjectAccessor *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZObjectAccessor::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_mapMutex);
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>(
    &this->m_LockedObjectAccessMap,
    0x10ui64);
}

// File Line: 12
// RVA: 0xEEA0B4
void __fastcall OSuite::ZObjectAccessor::~ZObjectAccessor(OSuite::ZObjectAccessor *this)
{
  OSuite::ZMutex *p_m_mapMutex; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rcx
  OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > *m_pLists; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  p_m_mapMutex = &this->m_mapMutex;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZObjectAccessor::`vftable;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    &this->m_LockedObjectAccessMap,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    m_pRight = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
    if ( m_pRight )
      m_pRight->vfptr->__vecDelDtor(m_pRight, 1u);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Clear(&this->m_LockedObjectAccessMap);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(p_m_mapMutex);
  m_pLists = this->m_LockedObjectAccessMap.m_pLists;
  this->m_LockedObjectAccessMap.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
  OSuite::ZMutex::~ZMutex(p_m_mapMutex);
}

// File Line: 26
// RVA: 0xEEAC1C
char __fastcall OSuite::ZObjectAccessor::RegisterObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZMutex *p_m_mapMutex; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *p_m_LockedObjectAccessMap; // rsi
  __int64 v6; // rax
  OSuite::ZObjectAccessor::InternalObjectAccessor *v7; // rdi
  OSuite::ZObjectAccessor::InternalObjectAccessor *value; // [rsp+20h] [rbp-59h] BYREF
  void *key; // [rsp+28h] [rbp-51h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-49h] BYREF

  key = pObject;
  if ( !pObject )
    return 0;
  p_m_mapMutex = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  p_m_LockedObjectAccessMap = &this->m_LockedObjectAccessMap;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &this->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v6 = OSuite::ZObject::operator new(0x28ui64);
    v7 = (OSuite::ZObjectAccessor::InternalObjectAccessor *)v6;
    if ( v6 )
    {
      *(_QWORD *)(v6 + 24) = 0i64;
      *(_QWORD *)v6 = &OSuite::ZObjectAccessor::InternalObjectAccessor::`vftable;
      OSuite::ZMutex::ZMutex((OSuite::ZMutex *)(v6 + 8));
      v7->m_count = 1;
      value = v7;
    }
    else
    {
      value = 0i64;
    }
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Insert(
      p_m_LockedObjectAccessMap,
      &key,
      &value);
  }
  else
  {
    ++LODWORD(result.m_iterator.m_iterator.m_pElement[1].m_pRight[1].vfptr);
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
  OSuite::ZMutex::Unlock(p_m_mapMutex);
  return 1;
}

// File Line: 50
// RVA: 0xEEAEBC
char __fastcall OSuite::ZObjectAccessor::UnRegisterObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZMutex *p_m_mapMutex; // rbx
  char v5; // di
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rcx
  void *key; // [rsp+20h] [rbp-49h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-39h] BYREF

  key = pObject;
  if ( !pObject )
    return 0;
  p_m_mapMutex = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &this->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator)
    || OSuite::ZMutex::IsLocked((OSuite::ZMutex *)&result.m_iterator.m_iterator.m_pElement[1].m_pRight->m_pLeft) )
  {
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    v5 = 0;
  }
  else
  {
    v5 = 1;
    --LODWORD(result.m_iterator.m_iterator.m_pElement[1].m_pRight[1].vfptr);
    m_pRight = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
    if ( !LODWORD(m_pRight[1].vfptr) )
    {
      if ( m_pRight )
        m_pRight->vfptr->__vecDelDtor(m_pRight, 1u);
      OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::ZIterator::Remove(&result);
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
  OSuite::ZMutex::Unlock(p_m_mapMutex);
  return v5;
}

// File Line: 76
// RVA: 0xEEA4C0
char __fastcall OSuite::ZObjectAccessor::AccessObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZMutex *p_m_mapMutex; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rdi
  void *key; // [rsp+20h] [rbp-49h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-39h] BYREF

  key = pObject;
  if ( !pObject )
    return 0;
  p_m_mapMutex = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &this->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(p_m_mapMutex);
    return 0;
  }
  m_pRight = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(p_m_mapMutex);
  OSuite::ZMutex::Lock((OSuite::ZMutex *)&m_pRight->m_pLeft);
  return 1;
}

// File Line: 122
// RVA: 0xEEAD60
char __fastcall OSuite::ZObjectAccessor::ReleaseObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZMutex *p_m_mapMutex; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rdi
  void *key; // [rsp+20h] [rbp-49h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-39h] BYREF

  key = pObject;
  if ( !pObject )
    return 0;
  p_m_mapMutex = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &this->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(p_m_mapMutex);
    return 0;
  }
  m_pRight = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(p_m_mapMutex);
  if ( OSuite::ZMutex::IsLocked((OSuite::ZMutex *)&m_pRight->m_pLeft) )
    OSuite::ZMutex::Unlock((OSuite::ZMutex *)&m_pRight->m_pLeft);
  return 1;
}

