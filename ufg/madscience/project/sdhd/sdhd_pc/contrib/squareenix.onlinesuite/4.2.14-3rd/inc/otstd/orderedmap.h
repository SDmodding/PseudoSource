// File Line: 64
// RVA: 0x4295C0
void __fastcall OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::~ZIterator(OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *this)
{
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v1; // rcx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rcx

  this->vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
  v1 = &this->m_iterator;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  v1->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v1->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  v2 = v1->m_parents.m_pList;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
}

// File Line: 119
// RVA: 0x428200
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v1; // rbx
  OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&this->vfptr);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v2 = &v1->m_Comparer;
  v2->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  v2->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
}

// File Line: 139
// RVA: 0x428C90
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::~TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this)
{
  OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v1; // [rsp+48h] [rbp+10h]

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v1 = &this->m_Comparer;
  v1->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  v1->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&this->vfptr);
}

// File Line: 215
// RVA: 0x42E2E0
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::ZString *key, OSuite::ZString *value)
{
  OSuite::ZString *v3; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v4; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v5; // rax
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+28h] [rbp-40h]

  v3 = value;
  v4 = this;
  OSuite::ZString::ZString(&data.m_First, key);
  OSuite::ZString::ZString(&data.m_Second, v3);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
  v5 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
  if ( v5 )
    OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
      v5,
      &data);
  OSuite::ZRedBlackTreeBase::InsertElementSet(
    (OSuite::ZRedBlackTreeBase *)&v4->vfptr,
    (OSuite::ZRedBlackTreeBase::ZElementBase *)&v5->vfptr);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
  OSuite::ZString::~ZString(&data.m_Second);
  OSuite::ZString::~ZString(&data.m_First);
}

// File Line: 241
// RVA: 0x42C210
OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *__fastcall OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > *this, OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *result, OSuite::ZUrl *key)
{
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *v3; // rdi
  OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > *v4; // rbx
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v5; // rax
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > resulta; // [rsp+30h] [rbp-168h]
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> data; // [rsp+90h] [rbp-108h]

  v3 = result;
  v4 = this;
  OSuite::ZUrl::ZUrl(&data.m_First, key);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable';
  v5 = OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::Find(
         (OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > > *)&v4->vfptr,
         &resulta,
         &data);
  v3->vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v3->m_iterator.vfptr,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v5->vfptr);
  v3->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable';
  resulta.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( resulta.m_parents.m_pList )
    resulta.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)resulta.m_parents.m_pList, 1u);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable';
  OSuite::ZUrl::~ZUrl(&data.m_First);
  return v3;
}

