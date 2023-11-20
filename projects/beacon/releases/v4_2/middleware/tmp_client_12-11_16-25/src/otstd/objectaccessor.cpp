// File Line: 7
// RVA: 0xEEA080
void __fastcall OSuite::ZObjectAccessor::ZObjectAccessor(OSuite::ZObjectAccessor *this)
{
  OSuite::ZObjectAccessor *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZObjectAccessor::`vftable';
  OSuite::ZMutex::ZMutex(&this->m_mapMutex);
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>(
    &v1->m_LockedObjectAccessMap,
    0x10ui64);
}

// File Line: 12
// RVA: 0xEEA0B4
void __fastcall OSuite::ZObjectAccessor::~ZObjectAccessor(OSuite::ZObjectAccessor *this)
{
  OSuite::ZMutex *v1; // rbx
  OSuite::ZObjectAccessor *v2; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rcx
  OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > *v4; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  v1 = &this->m_mapMutex;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZObjectAccessor::`vftable';
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(&v2->m_LockedObjectAccessMap, &result);
  while ( !(unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v3 = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
    if ( v3 )
      v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Clear(&v2->m_LockedObjectAccessMap);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(v1);
  v4 = v2->m_LockedObjectAccessMap.m_pLists;
  v2->m_LockedObjectAccessMap.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  if ( v4 )
  {
    if ( LODWORD(v4[-1].m_Comparer.vfptr) )
      v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v4[-1].m_Comparer.vfptr);
  }
  OSuite::ZMutex::~ZMutex(v1);
}

// File Line: 26
// RVA: 0xEEAC1C
char __fastcall OSuite::ZObjectAccessor::RegisterObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZObjectAccessor *v2; // rdi
  OSuite::ZMutex *v4; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *v5; // rsi
  __int64 v6; // rax
  OSuite::ZObjectAccessor::InternalObjectAccessor *v7; // rdi
  OSuite::ZObjectAccessor::InternalObjectAccessor *value; // [rsp+20h] [rbp-59h]
  void *key; // [rsp+28h] [rbp-51h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-49h]

  v2 = this;
  key = pObject;
  if ( !pObject )
    return 0;
  v4 = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v5 = &v2->m_LockedObjectAccessMap;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &v2->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( (unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v6 = OSuite::ZObject::operator new(0x28ui64);
    v7 = (OSuite::ZObjectAccessor::InternalObjectAccessor *)v6;
    if ( v6 )
    {
      *(_QWORD *)(v6 + 24) = 0i64;
      *(_QWORD *)v6 = &OSuite::ZObjectAccessor::InternalObjectAccessor::`vftable';
      OSuite::ZMutex::ZMutex((OSuite::ZMutex *)(v6 + 8));
      v7->m_count = 1;
      value = v7;
    }
    else
    {
      value = 0i64;
    }
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Insert(v5, &key, &value);
  }
  else
  {
    ++LODWORD(result.m_iterator.m_iterator.m_pElement[1].m_pRight[1].vfptr);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(v4);
  return 1;
}

// File Line: 50
// RVA: 0xEEAEBC
char __fastcall OSuite::ZObjectAccessor::UnRegisterObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZObjectAccessor *v2; // rdi
  OSuite::ZMutex *v4; // rbx
  char v5; // di
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // rcx
  void *key; // [rsp+20h] [rbp-49h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-39h]

  v2 = this;
  key = pObject;
  if ( !pObject )
    return 0;
  v4 = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &v2->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( (unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator)
    || OSuite::ZMutex::IsLocked((OSuite::ZMutex *)&result.m_iterator.m_iterator.m_pElement[1].m_pRight->m_pLeft) )
  {
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    v5 = 0;
  }
  else
  {
    v5 = 1;
    --LODWORD(result.m_iterator.m_iterator.m_pElement[1].m_pRight[1].vfptr);
    v6 = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
    if ( !LODWORD(v6[1].vfptr) )
    {
      if ( v6 )
        v6->vfptr->__vecDelDtor((OSuite::ZObject *)&v6->vfptr, 1u);
      OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::ZIterator::Remove(&result);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
  OSuite::ZMutex::Unlock(v4);
  return v5;
}

// File Line: 76
// RVA: 0xEEA4C0
char __fastcall OSuite::ZObjectAccessor::AccessObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZObjectAccessor *v2; // rdi
  OSuite::ZMutex *v4; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rdi
  void *key; // [rsp+20h] [rbp-49h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-39h]

  v2 = this;
  key = pObject;
  if ( !pObject )
    return 0;
  v4 = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &v2->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( (unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(v4);
    return 0;
  }
  v5 = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(v4);
  OSuite::ZMutex::Lock((OSuite::ZMutex *)&v5->m_pLeft);
  return 1;
}

// File Line: 122
// RVA: 0xEEAD60
char __fastcall OSuite::ZObjectAccessor::ReleaseObject(OSuite::ZObjectAccessor *this, void *pObject)
{
  OSuite::ZObjectAccessor *v2; // rdi
  OSuite::ZMutex *v4; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rdi
  void *key; // [rsp+20h] [rbp-49h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+30h] [rbp-39h]

  v2 = this;
  key = pObject;
  if ( !pObject )
    return 0;
  v4 = &this->m_mapMutex;
  OSuite::ZMutex::Lock(&this->m_mapMutex);
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::Find(
    &v2->m_LockedObjectAccessMap,
    &result,
    &key);
  if ( (unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(v4);
    return 0;
  }
  v5 = result.m_iterator.m_iterator.m_pElement[1].m_pRight;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(v4);
  if ( OSuite::ZMutex::IsLocked((OSuite::ZMutex *)&v5->m_pLeft) )
    OSuite::ZMutex::Unlock((OSuite::ZMutex *)&v5->m_pLeft);
  return 1;
}

