// File Line: 64
// RVA: 0x4295C0
void __fastcall OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::~ZIterator(
        OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx

  this->vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
  this->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  this->m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  m_pList = this->m_iterator.m_parents.m_pList;
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
}

// File Line: 119
// RVA: 0x428200
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this)
{
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > >::vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  this->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > >::vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
}

// File Line: 139
// RVA: 0x428C90
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::~TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > >::vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > >::vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(this);
}

// File Line: 215
// RVA: 0x42E2E0
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this,
        OSuite::ZString *key,
        OSuite::ZString *value)
{
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v5; // rax
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+28h] [rbp-40h] BYREF

  OSuite::ZString::ZString(&data.m_First, key);
  OSuite::ZString::ZString(&data.m_Second, value);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
  v5 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
  if ( v5 )
    OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
      v5,
      &data);
  OSuite::ZRedBlackTreeBase::InsertElementSet(this, v5);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
  OSuite::ZString::~ZString(&data.m_Second);
  OSuite::ZString::~ZString(&data.m_First);
}

// File Line: 241
// RVA: 0x42C210
OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *__fastcall OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::Find(
        OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > *this,
        OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIterator *result,
        OSuite::ZUrl *key)
{
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v5; // rax
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > resulta; // [rsp+30h] [rbp-168h] BYREF
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> data; // [rsp+90h] [rbp-108h] BYREF

  OSuite::ZUrl::ZUrl(&data.m_First, key);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  v5 = OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::Find(
         this,
         &resulta,
         &data);
  result->vfptr = (OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> >::ZIteratorVtbl *)&OSuite::TOrderedMap<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator, v5);
  result->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  resulta.m_parents.OSuite::ZRedBlackTreeBase::ZIteratorBase::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( resulta.m_parents.m_pList )
    resulta.m_parents.m_pList->vfptr->__vecDelDtor(resulta.m_parents.m_pList, 1u);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::~ZUrl(&data.m_First);
  return result;
}

