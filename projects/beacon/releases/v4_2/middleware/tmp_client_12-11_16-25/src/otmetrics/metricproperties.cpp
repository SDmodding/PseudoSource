// File Line: 10
// RVA: 0xEC1DFC
void __fastcall OSuite::ZMetricProperties::ZTransferIterator::ZTransferIterator(OSuite::ZMetricProperties::ZTransferIterator *this, OSuite::ZMetricProperties *pParent)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator *v2; // rdi
  OSuite::ZMetricProperties::ZTransferIterator *v3; // rsi
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *v4; // r15
  OSuite::ZRedBlackTreeBase::ZIteratorBase *v5; // r14
  OSuite::ZMetricProperties *v6; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v7; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v8; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-A8h]

  v2 = &this->m_it;
  v3 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::ZTransferIterator::`vftable';
  v4 = &this->m_it.m_iterator;
  this->m_it.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v5 = (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&this->m_it.m_iterator.m_iterator.vfptr;
  v6 = pParent;
  this->m_it.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&this->m_it.m_iterator.m_iterator.vfptr);
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v3->m_pParent = v6;
  OSuite::ZMutex::Lock(&v6->m_Mutex);
  v7 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
         (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)v3->m_pParent->m_pNewProps,
         &result);
  v8 = v7;
  if ( v2 != (OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator *)v7 )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v2->vfptr, (OSuite::ZObject *)&v7->vfptr);
    v2->m_pMap = (OSuite::TMap<OSuite::ZString,OSuite::ZString> *)v8->m_pMap;
    v2->m_iCurrentHash = v8->m_iCurrentHash;
    if ( v4 != (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *)&v8->m_iterator )
      OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(
        v5,
        (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v8->m_iterator.m_iterator.vfptr);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 23
// RVA: 0xEC1FA8
void __fastcall OSuite::ZMetricProperties::ZTransferIterator::~ZTransferIterator(OSuite::ZMetricProperties::ZTransferIterator *this)
{
  OSuite::ZMetricProperties::ZTransferIterator *v1; // rbx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::ZTransferIterator::`vftable';
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Clear(this->m_pParent->m_pNewProps);
  OSuite::ZMutex::Unlock(&v1->m_pParent->m_Mutex);
  v1->m_it.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v1->m_it.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v1->m_it.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v2 = v1->m_it.m_iterator.m_iterator.m_parents.m_pList;
  v1->m_it.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v1->m_it.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
}

// File Line: 30
// RVA: 0xEC27A0
OSuite::ZRedBlackTreeBase::ZElementBase **__fastcall OSuite::ZMetricProperties::ZTransferIterator::Key(OSuite::ZMetricProperties::ZTransferIterator *this)
{
  return &this->m_it.m_iterator.m_iterator.m_pElement[1].m_pLeft;
}

// File Line: 35
// RVA: 0xEC2A44
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZMetricProperties::ZTransferIterator::Value(OSuite::ZMetricProperties::ZTransferIterator *this)
{
  return this->m_it.m_iterator.m_iterator.m_pElement + 2;
}

// File Line: 40
// RVA: 0xEC2090
bool __fastcall OSuite::ZMetricProperties::ZTransferIterator::AtEnd(OSuite::ZMetricProperties::ZTransferIterator *this)
{
  return OSuite::ZString::IsNull((OSuite::ZString *)&this->m_it.m_iterator.m_iterator);
}

// File Line: 45
// RVA: 0xEC27AC
void __fastcall OSuite::ZMetricProperties::ZTransferIterator::Next(OSuite::ZMetricProperties::ZTransferIterator *this)
{
  OSuite::ZMetricProperties::ZTransferIterator *v1; // rbx

  v1 = this;
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(
    this->m_pParent->m_pOldProps,
    (OSuite::ZString *)&this->m_it.m_iterator.m_iterator.m_pElement[1].m_pLeft,
    (OSuite::ZString *)&this->m_it.m_iterator.m_iterator.m_pElement[2]);
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next((OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&v1->m_it);
}

// File Line: 52
// RVA: 0xEC1D94
void __fastcall OSuite::ZMetricProperties::ZMetricProperties(OSuite::ZMetricProperties *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *v1; // rdi
  OSuite::ZMetricProperties *v2; // rsi

  v1 = &this->m_propsMapA;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::`vftable';
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&this->m_propsMapA, 0x10ui64);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&v2->m_propsMapB, 0x10ui64);
  OSuite::ZMutex::ZMutex(&v2->m_Mutex);
  v2->m_pNewProps = &v2->m_propsMapB;
  v2->m_bValid = 1;
  v2->m_pOldProps = v1;
}

// File Line: 58
// RVA: 0xEC1F1C
void __fastcall OSuite::ZMetricProperties::~ZMetricProperties(OSuite::ZMetricProperties *this)
{
  OSuite::ZMetricProperties *v1; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::`vftable';
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Clear(this->m_pNewProps);
  OSuite::ZMutex::~ZMutex(&v1->m_Mutex);
  v2 = v1->m_propsMapB.m_pLists;
  v1->m_propsMapB.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
  if ( v2 )
  {
    if ( LODWORD(v2[-1].m_Comparer.vfptr) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].m_Comparer.vfptr);
  }
  v3 = v1->m_propsMapA.m_pLists;
  v1->m_propsMapA.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
  if ( v3 )
  {
    if ( LODWORD(v3[-1].m_Comparer.vfptr) )
      v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v3[-1].m_Comparer.vfptr);
  }
}

// File Line: 68
// RVA: 0xEC27E0
void __fastcall OSuite::ZMetricProperties::SetProperty(OSuite::ZMetricProperties *this, const char *sName, const char *sValue)
{
  OSuite::ZMetricProperties *v3; // rsi
  const char *v4; // rbp
  const char *v5; // rdi
  const char *v6; // rdx
  OSuite::ZString key; // [rsp+20h] [rbp-38h]
  OSuite::ZString value; // [rsp+38h] [rbp-20h]

  v3 = this;
  v4 = sValue;
  v5 = sName;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( strlen(v5) >= 3 && strlen(v5) > 3 )
    strncmp(v5, "s__", 3ui64);
  v6 = &customWorldMapCaption;
  if ( v4 )
    v6 = v4;
  OSuite::ZString::ZString(&value, v6);
  OSuite::ZString::ZString(&key, v5);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(v3->m_pNewProps, &key, &value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZMetricProperties::Validate(v3, v3->m_pNewProps);
  OSuite::ZMutex::Unlock(&v3->m_Mutex);
}

// File Line: 101
// RVA: 0xEC2510
const char *__fastcall OSuite::ZMetricProperties::GetProperty(OSuite::ZMetricProperties *this, const char *sName)
{
  OSuite::ZMutex *v2; // rbx
  OSuite::ZMetricProperties *v3; // rsi
  const char *v4; // rdi
  const char *v5; // r14
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator *v6; // rax
  OSuite::ZString key; // [rsp+20h] [rbp-E0h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator result; // [rsp+38h] [rbp-C8h]
  void **v10; // [rsp+C0h] [rbp-40h]
  void **v11; // [rsp+C8h] [rbp-38h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *v12; // [rsp+D0h] [rbp-30h]
  int v13; // [rsp+D8h] [rbp-28h]
  void **v14; // [rsp+E0h] [rbp-20h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v15; // [rsp+E8h] [rbp-18h]

  v2 = &this->m_Mutex;
  v3 = this;
  v4 = sName;
  v5 = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v12 = 0i64;
  v15.m_parents.m_pList = 0i64;
  _mm_store_si128((__m128i *)&v15.m_pList, (__m128i)0i64);
  OSuite::ZString::ZString(&key, v4);
  v6 = OSuite::TMap<OSuite::ZString,OSuite::ZString>::Find(v3->m_pOldProps, &result, &key);
  v10 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
  v11 = &OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v12 = v6->m_pMap;
  v13 = v6->m_iCurrentHash;
  v14 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    &v15,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v6->m_iterator.m_iterator.vfptr);
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZString::~ZString(&key);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&v15) )
    v5 = OSuite::ZString::c_str((OSuite::ZString *)&v15.m_pElement[2]);
  v10 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
  v15.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v11 = &OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v14 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v15.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v15.m_parents.m_pList )
    v15.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v15.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(v2);
  return v5;
}

// File Line: 123
// RVA: 0xEC2694
void __fastcall OSuite::ZMetricProperties::Invalidate(OSuite::ZMetricProperties *this)
{
  OSuite::ZMetricProperties *v1; // rdi
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *v2; // rcx
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *v3; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v2 = (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)v1->m_pNewProps;
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(v2, &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(
      v1->m_pOldProps,
      (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft,
      (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[2]);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Clear(v1->m_pNewProps);
  v3 = v1->m_pOldProps;
  v1->m_pOldProps = v1->m_pNewProps;
  v1->m_pNewProps = v3;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(&v1->m_Mutex);
}

// File Line: 168
// RVA: 0xEC28AC
OSuite::ZMetricProperties::ZTransferIterator *__fastcall OSuite::ZMetricProperties::TransferIterator(OSuite::ZMetricProperties *this, OSuite::ZMetricProperties::ZTransferIterator *result)
{
  OSuite::ZMetricProperties::ZTransferIterator *v2; // rbx

  v2 = result;
  OSuite::ZMetricProperties::ZTransferIterator::ZTransferIterator(result, this);
  return v2;
}

// File Line: 174
// RVA: 0xEC28CC
bool __fastcall OSuite::ZMetricProperties::Valid(OSuite::ZMetricProperties *this)
{
  return this->m_bValid;
}

// File Line: 189
// RVA: 0xEC28D0
void __fastcall OSuite::ZMetricProperties::Validate(OSuite::ZMetricProperties *this, OSuite::TMap<OSuite::ZString,OSuite::ZString> *pMap)
{
  OSuite::ZMetricProperties *v2; // rsi
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *v3; // rdi
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v4; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-E0h]
  void **v6; // [rsp+A0h] [rbp-60h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v7; // [rsp+A8h] [rbp-58h]

  v2 = this;
  v3 = pMap;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7.m_pMap = 0i64;
  v7.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  _mm_store_si128((__m128i *)&v7.m_iterator.m_iterator.m_pList, (__m128i)0i64);
  v2->m_bValid = 1;
  v4 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
         (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)v3,
         &result);
  v6 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v7.m_pMap = v4->m_pMap;
  v7.m_iCurrentHash = v4->m_iCurrentHash;
  v7.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v7.m_iterator.m_iterator.vfptr,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->m_iterator.m_iterator.vfptr);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v7.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v7.m_iterator.m_iterator) )
  {
    if ( OSuite::ZString::IsNull((OSuite::ZString *)&v7.m_iterator.m_iterator.m_pElement[2]) )
    {
      v2->m_bValid = 0;
      break;
    }
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v7);
  }
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v6 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
  v7.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v7.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v7.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v7.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v7.m_iterator.m_iterator.m_parents.m_pList )
    v7.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)v7.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(&v2->m_Mutex);
}

