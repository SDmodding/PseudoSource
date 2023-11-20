// File Line: 25
// RVA: 0xED6CC0
void __fastcall OSuite::ZAtomCache::ZAtomCache(OSuite::ZAtomCache *this)
{
  OSuite::ZAtomCache *v1; // rdi

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomCache::`vftable';
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->m_Objects.vfptr);
  v1->m_Objects.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZUrl>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::`vftable'{for `OSuite::IComparer<OSuite::ZUrl>'};
  v1->m_Objects.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::`vftable'{for `OSuite::ZObject'};
  v1->m_Objects.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::`vftable';
  OSuite::ZMutex::ZMutex(&v1->m_Mutex);
}

// File Line: 31
// RVA: 0xED6D18
void __fastcall OSuite::ZAtomCache::~ZAtomCache(OSuite::ZAtomCache *this)
{
  OSuite::ZMutex *v1; // rbx
  OSuite::ZAtomCache *v2; // rdi
  OSuite::ZRedBlackTreeBase *v3; // rdi
  OSuite::ZObjectVtbl *v4; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase v5; // [rsp+28h] [rbp-D8h]
  void **v6; // [rsp+90h] [rbp-70h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v7; // [rsp+98h] [rbp-68h]

  v1 = &this->m_Mutex;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomCache::`vftable';
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v5.m_parents.m_pList = 0i64;
  v3 = (OSuite::ZRedBlackTreeBase *)&v2->m_Objects.vfptr;
  _mm_store_si128((__m128i *)&v5.m_pList, (__m128i)0i64);
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v5, v3);
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v5) )
  {
    OSuite::ZCachedObject::Abort((OSuite::ZCachedObject *)v5.m_pElement[8].vfptr);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v5);
  }
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  v5.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v5.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v5.m_parents.m_pList )
    v5.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v5.m_parents.m_pList, 1u);
  v7.m_parents.m_pList = 0i64;
  v6 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
  _mm_store_si128((__m128i *)&v7.m_pList, (__m128i)0i64);
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7, v3);
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v7) )
  {
    v4 = v7.m_pElement[8].vfptr;
    if ( v4 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v4->__vecDelDtor)(v4, 1i64);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v7);
  }
  v6 = &OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  v7.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v7.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v7.m_parents.m_pList )
    v7.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v7.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(v1);
  OSuite::ZMutex::~ZMutex(v1);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::`vftable';
  v3[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZUrl>::`vftable'{for `OSuite::IComparer<OSuite::ZUrl>'};
  v3[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(v3);
}

// File Line: 89
// RVA: 0xED6F8C
void __fastcall OSuite::ZAtomCache::CloseObject(OSuite::ZAtomCache *this, OSuite::ZAtomBase *obj)
{
  OSuite::ZMutex *v2; // rdi
  OSuite::ZAtomCache *v3; // rbx
  OSuite::ZAtomBase *v4; // rsi
  bool i; // al
  OSuite::ZObjectVtbl *v6; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase v7; // [rsp+10h] [rbp-31h]

  v2 = &this->m_Mutex;
  v3 = this;
  v4 = obj;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7.m_parents.m_pList = 0i64;
  _mm_store_si128((__m128i *)&v7.m_pList, (__m128i)0i64);
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v7, (OSuite::ZRedBlackTreeBase *)&v3->m_Objects.vfptr);
  for ( i = OSuite::ZString::IsNull((OSuite::ZString *)&v7); !i; i = OSuite::ZString::IsNull((OSuite::ZString *)&v7) )
  {
    if ( OSuite::ZCachedObject::GetAtomObject((OSuite::ZCachedObject *)v7.m_pElement[8].vfptr, 0i64) == v4 )
    {
      OSuite::ZCachedObject::Abort((OSuite::ZCachedObject *)v7.m_pElement[8].vfptr);
      v6 = v7.m_pElement[8].vfptr;
      if ( v6 )
        (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v6->__vecDelDtor)(v6, 1i64);
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(&v7);
      break;
    }
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v7);
  }
  v7.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v7.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  v7.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v7.m_parents.m_pList )
    v7.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v7.m_parents.m_pList, 1u);
  OSuite::ZMutex::Unlock(v2);
}

