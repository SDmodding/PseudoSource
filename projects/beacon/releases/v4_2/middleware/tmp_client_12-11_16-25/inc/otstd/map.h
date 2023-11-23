// File Line: 97
// RVA: 0xED932C
void __fastcall OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *this)
{
  OSuite::ZString *p_m_iterator; // rdi
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *m_pMap; // rdx
  int m_iCurrentHash; // ecx
  OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > *m_pLists; // rax
  void **v6; // [rsp+20h] [rbp-78h] BYREF
  OSuite::ZRedBlackTreeBase::ZIteratorBase that; // [rsp+28h] [rbp-70h] BYREF

  p_m_iterator = (OSuite::ZString *)&this->m_iterator.m_iterator;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&this->m_iterator.m_iterator);
  if ( OSuite::ZString::IsNull(p_m_iterator) )
  {
    while ( 1 )
    {
      m_pMap = this->m_pMap;
      m_iCurrentHash = this->m_iCurrentHash;
      if ( m_iCurrentHash == m_pMap->m_nHashSize - 1 )
        break;
      this->m_iCurrentHash = m_iCurrentHash + 1;
      m_pLists = m_pMap->m_pLists;
      v6 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&that, &m_pLists[m_iCurrentHash + 1]);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      if ( &this->m_iterator != (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIterator *)&v6 )
        OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(&this->m_iterator.m_iterator, &that);
      v6 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      that.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      that.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( that.m_parents.m_pList )
        that.m_parents.m_pList->vfptr->__vecDelDtor(that.m_parents.m_pList, 1u);
      if ( !OSuite::ZString::IsNull(p_m_iterator) )
        return;
    }
    this->m_iCurrentHash = -1;
  }
}

// File Line: 124
// RVA: 0xECC174
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::ZIterator::Remove(
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *this)
{
  OSuite::ZRedBlackTreeBase::ZIteratorBase v2; // [rsp+28h] [rbp-80h] BYREF

  *(_OWORD *)&v2.m_pList = 0i64;
  v2.m_parents.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v2, &this->m_iterator.m_iterator);
  v2.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(this);
  OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(&v2);
  --this->m_pMap->m_nCount;
  v2.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v2.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v2.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v2.m_parents.m_pList )
    v2.m_parents.m_pList->vfptr->__vecDelDtor(v2.m_parents.m_pList, 1u);
}

// File Line: 148
// RVA: 0xEC998C
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>(
        OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> > *this,
        unsigned __int64 nHashSize)
{
  int v3; // ebp
  char *v4; // rax
  __int64 v5; // rax
  bool v6; // cf
  unsigned __int64 v7; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> > *v8; // rsi
  int v9; // ebp
  OSuite::ZRedBlackTreeBase *i; // rdi

  this->m_nCount = 0i64;
  this->m_nHashSize = nHashSize;
  v3 = nHashSize;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( (_DWORD)nHashSize )
  {
    v5 = 40i64 * (int)nHashSize;
    if ( !is_mul_ok((int)nHashSize, 0x28ui64) )
      v5 = -1i64;
    v6 = __CFADD__(v5, 8i64);
    v7 = v5 + 8;
    if ( v6 )
      v7 = -1i64;
    v4 = (char *)OSuite::ZObject::operator new(v7);
  }
  else
  {
    v4 = AMemory::malloc_default(8ui64);
  }
  if ( v4 )
  {
    v8 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> > *)(v4 + 8);
    *(_DWORD *)v4 = v3;
    v9 = v3 - 1;
    for ( i = (OSuite::ZRedBlackTreeBase *)(v4 + 8); v9 >= 0; --v9 )
    {
      OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(i);
      i[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
      i[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
      i->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
      i = (OSuite::ZRedBlackTreeBase *)((char *)i + 40);
    }
  }
  else
  {
    v8 = 0i64;
  }
  this->m_pLists = v8;
}

// File Line: 252
// RVA: 0xED8168
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear(
        OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx
  unsigned __int64 m_nHashSize; // rsi
  char *v4; // rax
  __int64 v5; // rax
  bool v6; // cf
  unsigned __int64 v7; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *v8; // rbp
  int v9; // esi
  OSuite::ZRedBlackTreeBase *i; // rdi

  m_pLists = this->m_pLists;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
  m_nHashSize = this->m_nHashSize;
  if ( this->m_nHashSize )
  {
    v5 = 40 * m_nHashSize;
    if ( !is_mul_ok(m_nHashSize, 0x28ui64) )
      v5 = -1i64;
    v6 = __CFADD__(v5, 8i64);
    v7 = v5 + 8;
    if ( v6 )
      v7 = -1i64;
    v4 = (char *)OSuite::ZObject::operator new(v7);
  }
  else
  {
    v4 = AMemory::malloc_default((unsigned int)(m_nHashSize + 8));
  }
  if ( v4 )
  {
    v8 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)(v4 + 8);
    *(_DWORD *)v4 = m_nHashSize;
    v9 = m_nHashSize - 1;
    for ( i = (OSuite::ZRedBlackTreeBase *)(v4 + 8); v9 >= 0; --v9 )
    {
      OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(i);
      i[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
      i[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
      i->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
      i = (OSuite::ZRedBlackTreeBase *)((char *)i + 40);
    }
  }
  else
  {
    v8 = 0i64;
  }
  this->m_nCount = 0i64;
  this->m_pLists = v8;
}

// File Line: 272
// RVA: 0xEE46BC
void __fastcall OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::Insert(
        OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *this,
        _exception *key,
        OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *value)
{
  unsigned int v6; // eax
  __int64 v7; // rbx

  v6 = OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>(key);
  v7 = (int)((this->m_nHashSize - 1) & v6);
  this->m_nCount -= OSuite::ZHttpStreamReader::Tell(&this->m_pLists[(this->m_nHashSize - 1) & v6]);
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::Insert(
    &this->m_pLists[v7],
    (const unsigned __int64 *)key,
    value);
  this->m_nCount += OSuite::ZHttpStreamReader::Tell(&this->m_pLists[v7]);
}

// File Line: 286
// RVA: 0xED8AB0
bool __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Exists(
        OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *this,
        OSuite::ZString *key)
{
  bool IsNull; // al
  bool v3; // bl
  OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> result; // [rsp+20h] [rbp-49h] BYREF

  result.m_iterator.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  *(_OWORD *)&result.m_iterator.m_iterator.m_iterator.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Find(this, &result, key);
  IsNull = OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator.m_iterator);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
  v3 = !IsNull;
  result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  return v3;
}

// File Line: 302
// RVA: 0xECAA18
OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator *__fastcall OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Find(
        OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> > *this,
        OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator *result,
        OSuite::ZString *key)
{
  OSuite::IHashable *v6; // rcx
  unsigned int v7; // eax
  int m_nHashSize; // esi
  int v9; // esi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *v11; // rax
  int v12; // ecx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator resulta; // [rsp+20h] [rbp-59h] BYREF

  if ( key )
    v6 = &key->OSuite::IHashable;
  else
    v6 = 0i64;
  v7 = v6->vfptr->ComputeHash(v6);
  m_nHashSize = this->m_nHashSize;
  resulta.m_iterator.m_parents.m_pList = 0i64;
  *(_OWORD *)&resulta.m_iterator.m_pList = 0i64;
  v9 = v7 & (m_nHashSize - 1);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    &this->m_pLists[v9],
    &resulta,
    key);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&resulta.m_iterator) )
  {
    result->m_iCurrentHash = v9;
    result->m_pMap = this;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator.m_iterator, &resulta.m_iterator);
    m_pList = resulta.m_iterator.m_parents.m_pList;
    result->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( m_pList )
LABEL_10:
      m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  }
  else
  {
    resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( resulta.m_iterator.m_parents.m_pList )
      resulta.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(resulta.m_iterator.m_parents.m_pList, 1u);
    v11 = OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::IteratorEnd(
            (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *)&this->m_pLists[this->m_nHashSize - 1],
            (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *)&resulta);
    v12 = this->m_nHashSize - 1;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result->m_pMap = this;
    result->m_iCurrentHash = v12;
    result->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator.m_iterator, &v11->m_iterator);
    m_pList = resulta.m_iterator.m_parents.m_pList;
    result->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( m_pList )
      goto LABEL_10;
  }
  return result;
}

// File Line: 325
// RVA: 0xED8B74
OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> *__fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Find(
        OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *this,
        OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> *result,
        OSuite::ZString *key)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator *v4; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator resulta; // [rsp+20h] [rbp-88h] BYREF

  v4 = OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(
         (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)this,
         &resulta,
         key);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
  result->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result->m_iterator.m_pMap = (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *)v4->m_pMap;
  result->m_iterator.m_iCurrentHash = v4->m_iCurrentHash;
  result->m_iterator.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    &result->m_iterator.m_iterator.m_iterator,
    &v4->m_iterator.m_iterator);
  m_pList = resulta.m_iterator.m_iterator.m_parents.m_pList;
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result->m_iterator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  return result;
}

// File Line: 366
// RVA: 0xED9148
OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *__fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *this,
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *result)
{
  int i; // ebx
  int m_nHashSize; // eax
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *v6; // rax
  int v7; // ecx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator resulta; // [rsp+8h] [rbp-29h] BYREF

  for ( i = 0; i < this->m_nHashSize; ++i )
  {
    if ( !OSuite::ZRedBlackTreeBase::IsEmpty(&this->m_pLists[i]) )
      break;
  }
  m_nHashSize = this->m_nHashSize;
  if ( i == m_nHashSize )
  {
    v6 = OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::IteratorEnd(
           (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *)&this->m_pLists[m_nHashSize - 1],
           &resulta);
    v7 = this->m_nHashSize - 1;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result->m_pMap = this;
    result->m_iCurrentHash = v7;
    result->m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator.m_iterator, &v6->m_iterator);
  }
  else
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&resulta.m_iterator, &this->m_pLists[i]);
    result->m_pMap = this;
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result->m_iCurrentHash = i;
    result->m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator.m_iterator, &resulta.m_iterator);
  }
  m_pList = resulta.m_iterator.m_parents.m_pList;
  resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  return result;
}

