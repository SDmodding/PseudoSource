// File Line: 98
// RVA: 0xEC8B4C
void __fastcall OSuite::ZAtomCache::Open<OSuite::ZOFeed>(
        OSuite::ZAtomCache *this,
        OSuite::ZUrl *url,
        OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *Callback,
        OSuite::ZString *format,
        OSuite::ZString *httpMethod)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > *p_m_Objects; // r13
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *v11; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZCachedObject *v13; // rcx
  OSuite::ZCachedObject *v14; // rdi
  OSuite::ZCachedObject *value; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator result; // [rsp+28h] [rbp-D8h] BYREF
  void **v17; // [rsp+90h] [rbp-70h] BYREF
  OSuite::ZRedBlackTreeBase::ZIteratorBase v18; // [rsp+98h] [rbp-68h] BYREF

  if ( OSuite::ZUrl::operator bool(url) )
  {
    v18.m_parents.m_pList = 0i64;
    v17 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    *(_OWORD *)&v18.m_pList = 0i64;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v18);
    p_m_Mutex = &this->m_Mutex;
    v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    OSuite::ZMutex::Lock(&this->m_Mutex);
    p_m_Objects = &this->m_Objects;
    v11 = OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
            &this->m_Objects,
            &result,
            url);
    if ( &v17 != (void ***)v11 )
      OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(&v18, &v11->m_iterator);
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
    OSuite::ZMutex::Unlock(&this->m_Mutex);
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
        OSuite::ZCachedObject::ZCachedObject(v14, url, format, httpMethod);
        v14->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TAtomObject<OSuite::ZOFeed>::`vftable;
      }
      else
      {
        v14 = 0i64;
      }
      OSuite::ZCachedObject::AddCallback(v14, Callback);
      OSuite::ZMutex::Lock(p_m_Mutex);
      value = v14;
      OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Insert(
        p_m_Objects,
        url,
        &value);
      OSuite::ZMutex::Unlock(p_m_Mutex);
      v13 = v14;
    }
    else
    {
      vfptr = v18.m_pElement[8].vfptr;
      OSuite::ZCachedObject::AddCallback((OSuite::ZCachedObject *)vfptr, Callback);
      v13 = (OSuite::ZCachedObject *)vfptr;
    }
    OSuite::ZCachedObject::FetchAsync(v13);
    v17 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    v18.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    v18.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v18.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v18.m_parents.m_pList )
      v18.m_parents.m_pList->vfptr->__vecDelDtor(v18.m_parents.m_pList, 1u);
  }
}

// File Line: 146
// RVA: 0xEC97BC
OSuite::ZOMetadata *__fastcall OSuite::ZAtomCache::TryOpen<OSuite::ZOMetadata>(
        OSuite::ZAtomCache *this,
        OSuite::ZUrl *url,
        OSuite::SCallbackData *pStatus)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  OSuite::ZObjectVtbl *vfptr; // rdi
  OSuite::ZAtomBase *AtomObject; // rax
  OSuite::ZAtomBase *v10; // rsi
  char v11; // al
  __int64 v12; // rdi
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator result; // [rsp+20h] [rbp-49h] BYREF

  if ( !OSuite::ZUrl::operator bool(url) )
    return 0i64;
  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  result.m_iterator.m_parents.m_pList = 0i64;
  *(_OWORD *)&result.m_iterator.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
    &this->m_Objects,
    &result,
    url);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&result.m_iterator)
    && (vfptr = result.m_iterator.m_pElement[8].vfptr,
        LODWORD(OSuite::ZUrl::GetFakeHost((OSuite::ZUrl *)vfptr)->OSuite::IHashable::vfptr) == 4)
    && (AtomObject = OSuite::ZCachedObject::GetAtomObject((OSuite::ZCachedObject *)vfptr, pStatus),
        (v10 = AtomObject) != 0i64) )
  {
    v11 = (char)AtomObject->vfptr[1].__vecDelDtor(AtomObject, OSuite::ZOMetadata::s_nClassId);
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    v12 = (unsigned __int64)v10 & -(__int64)(v11 != 0);
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
  }
  else
  {
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
    v12 = 0i64;
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return (OSuite::ZOMetadata *)v12;
}

