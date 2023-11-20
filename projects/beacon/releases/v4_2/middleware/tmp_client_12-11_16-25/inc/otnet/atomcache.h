// File Line: 98
// RVA: 0xEC8B4C
void __fastcall OSuite::ZAtomCache::Open<OSuite::ZOFeed>(OSuite::ZAtomCache *this, OSuite::ZUrl *url, OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *Callback, OSuite::ZString *format, OSuite::ZString *httpMethod)
{
  OSuite::ZAtomCache *v5; // rdi
  OSuite::ZString *v6; // r15
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *v7; // r14
  OSuite::ZUrl *v8; // rsi
  OSuite::ZMutex *v9; // rbx
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > *v10; // r13
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  OSuite::ZCachedObject *v13; // rcx
  OSuite::ZCachedObject *v14; // rdi
  OSuite::ZCachedObject *value; // [rsp+20h] [rbp-E0h]
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator result; // [rsp+28h] [rbp-D8h]
  void **v17; // [rsp+90h] [rbp-70h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v18; // [rsp+98h] [rbp-68h]

  v5 = this;
  v6 = format;
  v7 = Callback;
  v8 = url;
  if ( OSuite::ZUrl::operator bool(url) )
  {
    v18.m_parents.m_pList = 0i64;
    v17 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
    _mm_store_si128((__m128i *)&v18.m_pList, (__m128i)0i64);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v18);
    v9 = &v5->m_Mutex;
    v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
    OSuite::ZMutex::Lock(&v5->m_Mutex);
    v10 = &v5->m_Objects;
    v11 = OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
            &v5->m_Objects,
            &result,
            v8);
    if ( &v17 != (void ***)v11 )
      OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(
        &v18,
        (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v11->m_iterator.vfptr);
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(&v5->m_Mutex);
    if ( OSuite::ZString::IsNull((OSuite::ZString *)&v18) )
    {
      v14 = (OSuite::ZCachedObject *)OSuite::ZObject::operator new(0x198ui64);
      if ( v14 )
      {
        v14->m_UpdatedEvent.m_event = 0i64;
        v14->m_Callbacks.m_delegates.m_pHead = 0i64;
        v14->m_Format.m_pString = 0i64;
        v14->m_HttpMethod.m_pString = 0i64;
        v14->m_pAtomObject = 0i64;
        v14->m_pNewAtomObject = 0i64;
        v14->m_pHttpRequest = 0i64;
        OSuite::ZCachedObject::ZCachedObject(v14, v8, v6, httpMethod);
        v14->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TAtomObject<OSuite::ZOFeed>::`vftable';
      }
      else
      {
        v14 = 0i64;
      }
      OSuite::ZCachedObject::AddCallback(v14, v7);
      OSuite::ZMutex::Lock(v9);
      value = v14;
      OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Insert(
        v10,
        v8,
        &value);
      OSuite::ZMutex::Unlock(v9);
      v13 = v14;
    }
    else
    {
      v12 = v18.m_pElement[8].vfptr;
      OSuite::ZCachedObject::AddCallback((OSuite::ZCachedObject *)v18.m_pElement[8].vfptr, v7);
      v13 = (OSuite::ZCachedObject *)v12;
    }
    OSuite::ZCachedObject::FetchAsync(v13);
    v17 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
    v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
    v18.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    v18.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v18.m_parents.m_pList )
      v18.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v18.m_parents.m_pList, 1u);
  }
}

// File Line: 146
// RVA: 0xEC97BC
OSuite::ZOMetadata *__fastcall OSuite::ZAtomCache::TryOpen<OSuite::ZOMetadata>(OSuite::ZAtomCache *this, OSuite::ZUrl *url, OSuite::SCallbackData *pStatus)
{
  OSuite::ZAtomCache *v3; // rdi
  OSuite::SCallbackData *v4; // r14
  OSuite::ZUrl *v5; // rsi
  OSuite::ZMutex *v7; // rbx
  OSuite::ZObjectVtbl *v8; // rdi
  OSuite::ZAtomBase *v9; // rax
  OSuite::ZAtomBase *v10; // rsi
  char v11; // al
  signed __int64 v12; // rdi
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator result; // [rsp+20h] [rbp-49h]

  v3 = this;
  v4 = pStatus;
  v5 = url;
  if ( !OSuite::ZUrl::operator bool(url) )
    return 0i64;
  v7 = &v3->m_Mutex;
  OSuite::ZMutex::Lock(&v3->m_Mutex);
  result.m_iterator.m_parents.m_pList = 0i64;
  _mm_store_si128((__m128i *)&result.m_iterator.m_pList, (__m128i)0i64);
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
    &v3->m_Objects,
    &result,
    v5);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result.m_iterator.vfptr)
    && (v8 = result.m_iterator.m_pElement[8].vfptr,
        LODWORD(OSuite::ZUrl::GetFakeHost((OSuite::ZUrl *)result.m_iterator.m_pElement[8].vfptr)->vfptr) == 4)
    && (v9 = OSuite::ZCachedObject::GetAtomObject((OSuite::ZCachedObject *)v8, v4), (v10 = v9) != 0i64) )
  {
    v11 = (__int64)v9->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v9->vfptr, OSuite::ZOMetadata::s_nClassId);
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
    v12 = (unsigned __int64)v10 & -(signed __int64)(v11 != 0);
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_parents.m_pList,
        1u);
  }
  else
  {
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_parents.m_pList,
        1u);
    v12 = 0i64;
  }
  OSuite::ZMutex::Unlock(v7);
  return (OSuite::ZOMetadata *)v12;
}

