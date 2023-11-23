// File Line: 25
// RVA: 0xED6CC0
void __fastcall OSuite::ZAtomCache::ZAtomCache(OSuite::ZAtomCache *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomCache::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_Objects);
  this->m_Objects.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZUrl>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::`vftable{for `OSuite::IComparer<OSuite::ZUrl>};
  this->m_Objects.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::`vftable{for `OSuite::ZObject};
  this->m_Objects.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
}

// File Line: 31
// RVA: 0xED6D18
void __fastcall OSuite::ZAtomCache::~ZAtomCache(OSuite::ZAtomCache *this)
{
  OSuite::ZMutex *p_m_Mutex; // rbx
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > *p_m_Objects; // rdi
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase v5; // [rsp+28h] [rbp-D8h] BYREF
  void **v6; // [rsp+90h] [rbp-70h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v7; // [rsp+98h] [rbp-68h] BYREF

  p_m_Mutex = &this->m_Mutex;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomCache::`vftable;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v5.m_parents.m_pList = 0i64;
  p_m_Objects = &this->m_Objects;
  *(_OWORD *)&v5.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v5, p_m_Objects);
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v5) )
  {
    OSuite::ZCachedObject::Abort((OSuite::ZCachedObject *)v5.m_pElement[8].vfptr);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v5);
  }
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v5.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v5.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v5.m_parents.m_pList )
    v5.m_parents.m_pList->vfptr->__vecDelDtor(v5.m_parents.m_pList, 1u);
  v7.m_parents.m_pList = 0i64;
  v6 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
  *(_OWORD *)&v7.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7, p_m_Objects);
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v7) )
  {
    vfptr = v7.m_pElement[8].vfptr;
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v7);
  }
  v6 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v7.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v7.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v7.m_parents.m_pList )
    v7.m_parents.m_pList->vfptr->__vecDelDtor(v7.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(p_m_Mutex);
  OSuite::ZMutex::~ZMutex(p_m_Mutex);
  p_m_Objects->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::`vftable;
  p_m_Objects->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > >::vfptr = (OSuite::IComparer<OSuite::ZUrl>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZUrl>::`vftable{for `OSuite::IComparer<OSuite::ZUrl>};
  p_m_Objects->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(p_m_Objects);
}

// File Line: 89
// RVA: 0xED6F8C
void __fastcall OSuite::ZAtomCache::CloseObject(OSuite::ZAtomCache *this, OSuite::ZAtomBase *obj)
{
  OSuite::ZMutex *p_m_Mutex; // rdi
  bool i; // al
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase v7; // [rsp+10h] [rbp-31h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7.m_parents.m_pList = 0i64;
  *(_OWORD *)&v7.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7, &this->m_Objects);
  for ( i = OSuite::ZString::IsNull((OSuite::ZString *)&v7); !i; i = OSuite::ZString::IsNull((OSuite::ZString *)&v7) )
  {
    if ( OSuite::ZCachedObject::GetAtomObject((OSuite::ZCachedObject *)v7.m_pElement[8].vfptr, 0i64) == obj )
    {
      OSuite::ZCachedObject::Abort((OSuite::ZCachedObject *)v7.m_pElement[8].vfptr);
      vfptr = v7.m_pElement[8].vfptr;
      if ( vfptr )
        (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(&v7);
      break;
    }
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v7);
  }
  v7.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v7.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v7.m_parents.m_pList )
    v7.m_parents.m_pList->vfptr->__vecDelDtor(v7.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(p_m_Mutex);
}

