// File Line: 146
// RVA: 0x4276B0
OSuite::ZOEntry *__fastcall OSuite::ZAtomCache::TryOpen<OSuite::ZOEntry>(
        OSuite::ZAtomCache *this,
        OSuite::ZUrl *url,
        OSuite::SCallbackData *pStatus)
{
  OSuite::ZObjectVtbl *vfptr; // rdi
  OSuite::ZAtomBase *AtomObject; // rax
  OSuite::ZOEntry *v8; // rdi
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator result; // [rsp+30h] [rbp-88h] BYREF
  __int64 v11; // [rsp+A0h] [rbp-18h]

  v11 = -2i64;
  if ( !OSuite::ZUrl::operator bool(url) )
    return 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
    &this->m_Objects,
    &result,
    url);
  if ( !OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&result.m_iterator)
    || (vfptr = result.m_iterator.m_pElement[8].vfptr,
        LODWORD(OSuite::ZUrl::GetFakeHost((OSuite::ZUrl *)vfptr)->OSuite::IHashable::vfptr) != 4)
    || (AtomObject = OSuite::ZCachedObject::GetAtomObject((OSuite::ZCachedObject *)vfptr, pStatus)) == 0i64 )
  {
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
    OSuite::ZMutex::Unlock(&this->m_Mutex);
    return 0i64;
  }
  v8 = OSuite::ZAtomBase::Cast<OSuite::ZOEntry>(AtomObject);
  result.vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_parents.m_pList )
    result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return v8;
}

