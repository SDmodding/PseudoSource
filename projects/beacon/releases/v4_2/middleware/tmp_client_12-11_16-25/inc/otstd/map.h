// File Line: 97
// RVA: 0xED932C
void __fastcall OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *this)
{
  OSuite::ZString *v1; // rdi
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v2; // rbx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *v3; // rdx
  int v4; // ecx
  OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > *v5; // rax
  void **v6; // [rsp+20h] [rbp-78h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase that; // [rsp+28h] [rbp-70h]

  v1 = (OSuite::ZString *)&this->m_iterator.m_iterator;
  v2 = this;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&this->m_iterator.m_iterator.vfptr);
  if ( OSuite::ZString::IsNull(v1) )
  {
    while ( 1 )
    {
      v3 = v2->m_pMap;
      v4 = v2->m_iCurrentHash;
      if ( v4 == v3->m_nHashSize - 1 )
        break;
      v2->m_iCurrentHash = v4 + 1;
      v5 = v3->m_pLists;
      v6 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
      OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&that, (OSuite::ZRedBlackTreeBase *)&v5[v4 + 1].vfptr);
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
      if ( &v2->m_iterator != (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIterator *)&v6 )
        OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(
          (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v2->m_iterator.m_iterator.vfptr,
          &that);
      v6 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
      that.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
      that.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
      if ( that.m_parents.m_pList )
        that.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)that.m_parents.m_pList, 1u);
      if ( !OSuite::ZString::IsNull(v1) )
        return;
    }
    v2->m_iCurrentHash = -1;
  }
}

// File Line: 124
// RVA: 0xECC174
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::ZIterator::Remove(OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *this)
{
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v1; // rbx
  OSuite::ZRedBlackTreeBase::ZIteratorBase v2; // [rsp+28h] [rbp-80h]

  v1 = this;
  _mm_store_si128((__m128i *)&v2.m_pList, (__m128i)0i64);
  v2.m_parents.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    &v2,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&this->m_iterator.m_iterator.vfptr);
  v2.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(v1);
  OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(&v2);
  --v1->m_pMap->m_nCount;
  v2.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v2.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v2.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v2.m_parents.m_pList )
    v2.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v2.m_parents.m_pList, 1u);
}

// File Line: 148
// RVA: 0xEC998C
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>(OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> > *this, unsigned __int64 nHashSize)
{
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> > *v2; // rbx
  int v3; // ebp
  char *v4; // rax
  signed __int64 v5; // rax
  unsigned __int8 v6; // cf
  unsigned __int64 v7; // rax
  signed __int64 v8; // rsi
  int v9; // ebp
  OSuite::ZRedBlackTreeBase *i; // rdi

  this->m_nCount = 0i64;
  v2 = this;
  this->m_nHashSize = nHashSize;
  v3 = nHashSize;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  if ( (_DWORD)nHashSize )
  {
    v5 = 40i64 * (signed int)nHashSize;
    if ( !is_mul_ok((signed int)nHashSize, 0x28ui64) )
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
    v8 = (signed __int64)(v4 + 8);
    *(_DWORD *)v4 = v3;
    v9 = v3 - 1;
    for ( i = (OSuite::ZRedBlackTreeBase *)(v4 + 8); v9 >= 0; --v9 )
    {
      OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(i);
      i[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
      i[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
      i->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
      i = (OSuite::ZRedBlackTreeBase *)((char *)i + 40);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v2->m_pLists = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> > *)v8;
}

// File Line: 252
// RVA: 0xED8168
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear(OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *v1; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // rcx
  unsigned __int64 v3; // rsi
  char *v4; // rax
  signed __int64 v5; // rax
  unsigned __int8 v6; // cf
  unsigned __int64 v7; // rax
  signed __int64 v8; // rbp
  int v9; // esi
  OSuite::ZRedBlackTreeBase *i; // rdi

  v1 = this;
  v2 = this->m_pLists;
  if ( v2 )
  {
    if ( LODWORD(v2[-1].m_Comparer.vfptr) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].m_Comparer.vfptr);
  }
  v3 = v1->m_nHashSize;
  if ( v1->m_nHashSize )
  {
    v5 = 40 * v3;
    if ( !is_mul_ok(v3, 0x28ui64) )
      v5 = -1i64;
    v6 = __CFADD__(v5, 8i64);
    v7 = v5 + 8;
    if ( v6 )
      v7 = -1i64;
    v4 = (char *)OSuite::ZObject::operator new(v7);
  }
  else
  {
    v4 = AMemory::malloc_default((unsigned int)(v3 + 8));
  }
  if ( v4 )
  {
    v8 = (signed __int64)(v4 + 8);
    *(_DWORD *)v4 = v3;
    v9 = v3 - 1;
    for ( i = (OSuite::ZRedBlackTreeBase *)(v4 + 8); v9 >= 0; --v9 )
    {
      OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(i);
      i[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
      i[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
      i->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
      i = (OSuite::ZRedBlackTreeBase *)((char *)i + 40);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v1->m_nCount = 0i64;
  v1->m_pLists = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)v8;
}

// File Line: 272
// RVA: 0xEE46BC
void __fastcall OSuite::TMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::Insert(OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *this, const unsigned __int64 *key, OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *value)
{
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *v3; // rbp
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *v4; // rdi
  const unsigned __int64 *v5; // rsi
  unsigned int v6; // eax
  signed __int64 v7; // rbx

  v3 = this;
  v4 = value;
  v5 = key;
  v6 = OSuite::FComputeHash<OSuite::TList<OSuite::ZJsonObject *> *>(key);
  v7 = (signed int)((v3->m_nHashSize - 1) & v6);
  v3->m_nCount -= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->m_pLists[(v3->m_nHashSize - 1) & v6].vfptr);
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::Insert(
    &v3->m_pLists[v7],
    v5,
    v4);
  v3->m_nCount += OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->m_pLists[v7].vfptr);
}

// File Line: 286
// RVA: 0xED8AB0
bool __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Exists(OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *this, OSuite::ZString *key)
{
  bool v2; // al
  bool v3; // bl
  OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> result; // [rsp+20h] [rbp-49h]

  result.m_iterator.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  _mm_store_si128((__m128i *)&result.m_iterator.m_iterator.m_iterator.m_pList, (__m128i)0i64);
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Find(this, &result, key);
  v2 = OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator.m_iterator);
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
  v3 = v2 == 0;
  result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  return v3;
}

// File Line: 302
// RVA: 0xECAA18
OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator *__fastcall OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>>::Find(OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> > *this, OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator *result, OSuite::ZString *key)
{
  OSuite::ZString *v3; // rbx
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> >::ZIterator *v4; // rdi
  OSuite::TMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> > *v5; // r13
  OSuite::IHashable *v6; // rcx
  int v7; // eax
  int v8; // esi
  int v9; // esi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v10; // rcx
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *v11; // rax
  int v12; // ecx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v13; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator resulta; // [rsp+20h] [rbp-59h]

  v3 = key;
  v4 = result;
  v5 = this;
  if ( key )
    v6 = (OSuite::IHashable *)&key->vfptr;
  else
    v6 = 0i64;
  v7 = ((__int64 (*)(void))v6->vfptr->ComputeHash)();
  v8 = v5->m_nHashSize;
  resulta.m_iterator.m_parents.m_pList = 0i64;
  _mm_store_si128((__m128i *)&resulta.m_iterator.m_pList, (__m128i)0i64);
  v9 = v7 & (v8 - 1);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    &v5->m_pLists[v9],
    &resulta,
    v3);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.vfptr) )
  {
    v4->m_iCurrentHash = v9;
    v4->m_pMap = v5;
    v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    v4->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.vfptr);
    v10 = resulta.m_iterator.m_parents.m_pList;
    v4->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v10 )
      v10->vfptr->__vecDelDtor((OSuite::ZObject *)&v10->vfptr, 1u);
  }
  else
  {
    resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( resulta.m_iterator.m_parents.m_pList )
      resulta.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)resulta.m_iterator.m_parents.m_pList,
        1u);
    v11 = OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::IteratorEnd(
            (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *)&v5->m_pLists[v5->m_nHashSize - 1],
            (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *)&resulta);
    v12 = v5->m_nHashSize - 1;
    v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    v4->m_pMap = v5;
    v4->m_iCurrentHash = v12;
    v4->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v11->m_iterator.vfptr);
    v13 = resulta.m_iterator.m_parents.m_pList;
    v4->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v13 )
      v13->vfptr->__vecDelDtor((OSuite::ZObject *)&v13->vfptr, 1u);
  }
  return v4;
}

// File Line: 325
// RVA: 0xED8B74
OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> *__fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Find(OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *this, OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> *result, OSuite::ZString *key)
{
  OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString> *v3; // rdi
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator *v4; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rcx
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator resulta; // [rsp+20h] [rbp-88h]

  v3 = result;
  v4 = OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(
         (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)this,
         &resulta,
         key);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable';
  v3->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  v3->m_iterator.m_pMap = (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *> *)v4->m_pMap;
  v3->m_iterator.m_iCurrentHash = v4->m_iCurrentHash;
  v3->m_iterator.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v3->m_iterator.m_iterator.m_iterator.vfptr,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->m_iterator.m_iterator.vfptr);
  v5 = resulta.m_iterator.m_iterator.m_parents.m_pList;
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v3->m_iterator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v5 )
    v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
  return v3;
}

// File Line: 366
// RVA: 0xED9148
OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *__fastcall OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *this, OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *result)
{
  int v2; // ebx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v3; // rdi
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *i; // rsi
  int v5; // eax
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *v6; // rax
  int v7; // ecx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rcx
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator resulta; // [rsp+8h] [rbp-29h]

  v2 = 0;
  v3 = result;
  for ( i = this; v2 < i->m_nHashSize; ++v2 )
  {
    if ( !OSuite::ZRedBlackTreeBase::IsEmpty((OSuite::ZRedBlackTreeBase *)&i->m_pLists[v2].vfptr) )
      break;
  }
  v5 = i->m_nHashSize;
  if ( v2 == v5 )
  {
    v6 = OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::IteratorEnd(
           (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *)&i->m_pLists[v5 - 1],
           &resulta);
    v7 = i->m_nHashSize - 1;
    v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    v3->m_pMap = i;
    v3->m_iCurrentHash = v7;
    v3->m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v3->m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v6->m_iterator.vfptr);
  }
  else
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase *)&i->m_pLists[v2].vfptr);
    v3->m_pMap = i;
    v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
    v3->m_iCurrentHash = v2;
    v3->m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v3->m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.vfptr);
  }
  v8 = resulta.m_iterator.m_parents.m_pList;
  resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v3->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v8 )
    v8->vfptr->__vecDelDtor((OSuite::ZObject *)&v8->vfptr, 1u);
  return v3;
}

