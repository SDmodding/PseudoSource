// File Line: 146
// RVA: 0x4276B0
OSuite::ZAtomBase *__fastcall OSuite::ZAtomCache::TryOpen<OSuite::ZOEntry>(OSuite::ZAtomCache *this, OSuite::ZUrl *url, OSuite::SCallbackData *pStatus)
{
  OSuite::SCallbackData *v3; // rbp
  OSuite::ZUrl *v4; // rdi
  OSuite::ZAtomCache *v5; // rsi
  OSuite::ZObjectVtbl *v6; // rdi
  OSuite::ZAtomBase *v7; // rax
  OSuite::ZAtomBase *v8; // rdi
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator result; // [rsp+30h] [rbp-88h]
  __int64 v11; // [rsp+A0h] [rbp-18h]

  v11 = -2i64;
  v3 = pStatus;
  v4 = url;
  v5 = this;
  if ( !OSuite::ZUrl::operator bool(url) )
    return 0i64;
  OSuite::ZMutex::Lock(&v5->m_Mutex);
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
    &v5->m_Objects,
    &result,
    v4);
  if ( !OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result.m_iterator.vfptr)
    || (v6 = result.m_iterator.m_pElement[8].vfptr,
        LODWORD(OSuite::ZUrl::GetFakeHost((OSuite::ZUrl *)result.m_iterator.m_pElement[8].vfptr)->vfptr) != 4)
    || (v7 = OSuite::ZCachedObject::GetAtomObject((OSuite::ZCachedObject *)v6, v3)) == 0i64 )
  {
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(&v5->m_Mutex);
    return 0i64;
  }
  v8 = OSuite::ZAtomBase::Cast<OSuite::ZOEntry>(v7);
  result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_parents.m_pList )
    result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)result.m_iterator.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(&v5->m_Mutex);
  return v8;
}

