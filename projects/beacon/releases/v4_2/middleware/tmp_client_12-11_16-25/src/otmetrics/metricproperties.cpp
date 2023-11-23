// File Line: 10
// RVA: 0xEC1DFC
void __fastcall OSuite::ZMetricProperties::ZTransferIterator::ZTransferIterator(
        OSuite::ZMetricProperties::ZTransferIterator *this,
        OSuite::ZMetricProperties *pParent)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator *p_m_it; // rdi
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *p_m_iterator; // r15
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v5; // r14
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v7; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v8; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-A8h] BYREF

  p_m_it = &this->m_it;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::ZTransferIterator::`vftable;
  p_m_iterator = &this->m_it.m_iterator;
  this->m_it.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v5 = &this->m_it.m_iterator.m_iterator;
  this->m_it.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&this->m_it.m_iterator.m_iterator);
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  this->m_pParent = pParent;
  OSuite::ZMutex::Lock(&pParent->m_Mutex);
  v7 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
         (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)this->m_pParent->m_pNewProps,
         &result);
  v8 = v7;
  if ( p_m_it != (OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator *)v7 )
  {
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(p_m_it, v7);
    p_m_it->m_pMap = (OSuite::TMap<OSuite::ZString,OSuite::ZString> *)v8->m_pMap;
    p_m_it->m_iCurrentHash = v8->m_iCurrentHash;
    if ( p_m_iterator != (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *)&v8->m_iterator )
      OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(v5, &v8->m_iterator.m_iterator);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
}

// File Line: 23
// RVA: 0xEC1FA8
void __fastcall OSuite::ZMetricProperties::ZTransferIterator::~ZTransferIterator(
        OSuite::ZMetricProperties::ZTransferIterator *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::ZTransferIterator::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Clear(this->m_pParent->m_pNewProps);
  OSuite::ZMutex::Unlock(&this->m_pParent->m_Mutex);
  this->m_it.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  this->m_it.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  this->m_it.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  m_pList = this->m_it.m_iterator.m_iterator.m_parents.m_pList;
  this->m_it.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_it.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
}

// File Line: 30
// RVA: 0xEC27A0
OSuite::ZRedBlackTreeBase::ZElementBase **__fastcall OSuite::ZMetricProperties::ZTransferIterator::Key(
        OSuite::ZMetricProperties::ZTransferIterator *this)
{
  return &this->m_it.m_iterator.m_iterator.m_pElement[1].m_pLeft;
}

// File Line: 35
// RVA: 0xEC2A44
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZMetricProperties::ZTransferIterator::Value(
        OSuite::ZMetricProperties::ZTransferIterator *this)
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
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(
    this->m_pParent->m_pOldProps,
    (OSuite::ZString *)&this->m_it.m_iterator.m_iterator.m_pElement[1].m_pLeft,
    (OSuite::ZString *)&this->m_it.m_iterator.m_iterator.m_pElement[2]);
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next((OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *)&this->m_it);
}

// File Line: 52
// RVA: 0xEC1D94
void __fastcall OSuite::ZMetricProperties::ZMetricProperties(OSuite::ZMetricProperties *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *p_m_propsMapA; // rdi

  p_m_propsMapA = &this->m_propsMapA;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&this->m_propsMapA, 0x10ui64);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&this->m_propsMapB, 0x10ui64);
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
  this->m_pNewProps = &this->m_propsMapB;
  this->m_bValid = 1;
  this->m_pOldProps = p_m_propsMapA;
}

// File Line: 58
// RVA: 0xEC1F1C
void __fastcall OSuite::ZMetricProperties::~ZMetricProperties(OSuite::ZMetricProperties *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetricProperties::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Clear(this->m_pNewProps);
  OSuite::ZMutex::~ZMutex(&this->m_Mutex);
  m_pLists = this->m_propsMapB.m_pLists;
  this->m_propsMapB.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
  v3 = this->m_propsMapA.m_pLists;
  this->m_propsMapA.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  if ( v3 )
  {
    if ( LODWORD(v3[-1].m_Comparer.vfptr) )
      v3->vfptr->__vecDelDtor(v3, 3u);
    else
      Illusion::ShaderParam::operator delete(&v3[-1].m_Comparer.OSuite::ZObject);
  }
}

// File Line: 68
// RVA: 0xEC27E0
void __fastcall OSuite::ZMetricProperties::SetProperty(
        OSuite::ZMetricProperties *this,
        const char *sName,
        const char *sValue)
{
  const char *v6; // rdx
  OSuite::ZString key; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString value; // [rsp+38h] [rbp-20h] BYREF

  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( strlen(sName) >= 3 && strlen(sName) > 3 )
    strncmp(sName, "s__", 3ui64);
  v6 = &customCaption;
  if ( sValue )
    v6 = sValue;
  OSuite::ZString::ZString(&value, v6);
  OSuite::ZString::ZString(&key, sName);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(this->m_pNewProps, &key, &value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  OSuite::ZMetricProperties::Validate(this, this->m_pNewProps);
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

// File Line: 101
// RVA: 0xEC2510
const char *__fastcall OSuite::ZMetricProperties::GetProperty(OSuite::ZMetricProperties *this, const char *sName)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  const char *v5; // r14
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator *v6; // rax
  OSuite::ZString key; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::ZIterator result; // [rsp+38h] [rbp-C8h] BYREF
  void **v10; // [rsp+C0h] [rbp-40h]
  void **v11; // [rsp+C8h] [rbp-38h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *m_pMap; // [rsp+D0h] [rbp-30h]
  int m_iCurrentHash; // [rsp+D8h] [rbp-28h]
  void **v14; // [rsp+E0h] [rbp-20h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v15; // [rsp+E8h] [rbp-18h] BYREF

  p_m_Mutex = &this->m_Mutex;
  v5 = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  m_pMap = 0i64;
  v15.m_parents.m_pList = 0i64;
  *(_OWORD *)&v15.m_pList = 0i64;
  OSuite::ZString::ZString(&key, sName);
  v6 = OSuite::TMap<OSuite::ZString,OSuite::ZString>::Find(this->m_pOldProps, &result, &key);
  v10 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
  v11 = &OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  m_pMap = v6->m_pMap;
  m_iCurrentHash = v6->m_iCurrentHash;
  v14 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v15, &v6->m_iterator.m_iterator);
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZString::~ZString(&key);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&v15) )
    v5 = OSuite::ZString::c_str((OSuite::ZString *)&v15.m_pElement[2]);
  v10 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
  v15.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v11 = &OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v14 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v15.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v15.m_parents.m_pList )
    v15.m_parents.m_pList->vfptr->__vecDelDtor(v15.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return v5;
}

// File Line: 123
// RVA: 0xEC2694
void __fastcall OSuite::ZMetricProperties::Invalidate(OSuite::ZMetricProperties *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *m_pNewProps; // rcx
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *m_pOldProps; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  OSuite::ZMutex::Lock(&this->m_Mutex);
  m_pNewProps = this->m_pNewProps;
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)m_pNewProps,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(
      this->m_pOldProps,
      (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft,
      (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[2]);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::Clear(this->m_pNewProps);
  m_pOldProps = this->m_pOldProps;
  this->m_pOldProps = this->m_pNewProps;
  this->m_pNewProps = m_pOldProps;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

// File Line: 168
// RVA: 0xEC28AC
OSuite::ZMetricProperties::ZTransferIterator *__fastcall OSuite::ZMetricProperties::TransferIterator(
        OSuite::ZMetricProperties *this,
        OSuite::ZMetricProperties::ZTransferIterator *result)
{
  OSuite::ZMetricProperties::ZTransferIterator::ZTransferIterator(result, this);
  return result;
}

// File Line: 174
// RVA: 0xEC28CC
bool __fastcall OSuite::ZMetricProperties::Valid(OSuite::ZMetricProperties *this)
{
  return this->m_bValid;
}

// File Line: 189
// RVA: 0xEC28D0
void __fastcall OSuite::ZMetricProperties::Validate(
        OSuite::ZMetricProperties *this,
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *pMap)
{
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v4; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-E0h] BYREF
  void **v6; // [rsp+A0h] [rbp-60h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v7; // [rsp+A8h] [rbp-58h] BYREF

  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7.m_pMap = 0i64;
  v7.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  *(_OWORD *)&v7.m_iterator.m_iterator.m_pList = 0i64;
  this->m_bValid = 1;
  v4 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(pMap, &result);
  v6 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v7.m_pMap = v4->m_pMap;
  v7.m_iCurrentHash = v4->m_iCurrentHash;
  v7.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7.m_iterator.m_iterator, &v4->m_iterator.m_iterator);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v7.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v7.m_iterator.m_iterator) )
  {
    if ( OSuite::ZString::IsNull((OSuite::ZString *)&v7.m_iterator.m_iterator.m_pElement[2]) )
    {
      this->m_bValid = 0;
      break;
    }
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v7);
  }
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v6 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
  v7.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v7.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v7.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v7.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v7.m_iterator.m_iterator.m_parents.m_pList )
    v7.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v7.m_iterator.m_iterator.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

