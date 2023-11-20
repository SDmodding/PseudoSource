// File Line: 165
// RVA: 0xED1068
bool __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::operator<(OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *that)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // r14
  OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rdi
  bool v4; // al
  unsigned __int64 v5; // rbx
  OSuite::ZString *v6; // rbx
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rdi
  bool v9; // bl
  bool v10; // al
  unsigned __int64 v11; // rbx
  OSuite::ZString v12; // [rsp+20h] [rbp-E0h]
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> result; // [rsp+40h] [rbp-C0h]
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> v14; // [rsp+B0h] [rbp-50h]

  v2 = that;
  v3 = this;
  if ( this == that )
    return 0;
  v5 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&that->vfptr);
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->vfptr) == v5 )
  {
    result.m_iterator.m_iterator.m_pList = 0i64;
    result.m_iterator.m_iterator.m_pElement = 0i64;
    result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
      v3,
      &result);
    v14.m_iterator.m_iterator.m_pList = 0i64;
    v14.m_iterator.m_iterator.m_pElement = 0i64;
    v14.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(v2, &v14);
    while ( 1 )
    {
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator)
        || OSuite::ZString::IsNull((OSuite::ZString *)&v14.m_iterator.m_iterator) )
      {
        v9 = 0;
        goto LABEL_11;
      }
      v6 = (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft;
      OSuite::ZString::ZString(&v12, (OSuite::ZString *)&v14.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      v8 = v7;
      LOBYTE(v6) = OSuite::ZString::operator==(v6, v7) == 0;
      OSuite::ZString::~ZString(v8);
      if ( (_BYTE)v6 )
        break;
      if ( !OSuite::TList<OSuite::ZString>::operator==(
              (OSuite::TList<OSuite::ZString> *)&result.m_iterator.m_iterator.m_pElement[2],
              (OSuite::TList<OSuite::ZString> *)&v14.m_iterator.m_iterator.m_pElement[2]) )
      {
        v10 = OSuite::TList<OSuite::ZString>::operator<(
                (OSuite::TList<OSuite::ZString> *)&result.m_iterator.m_iterator.m_pElement[2],
                (OSuite::TList<OSuite::ZString> *)&v14.m_iterator.m_iterator.m_pElement[2]);
        goto LABEL_18;
      }
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result.m_iterator.m_iterator.vfptr);
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v14.m_iterator.m_iterator.vfptr);
    }
    v10 = OSuite::ZString::operator<(
            (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft,
            (OSuite::ZString *)&v14.m_iterator.m_iterator.m_pElement[1].m_pLeft);
LABEL_18:
    v9 = v10;
LABEL_11:
    v14.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    v14.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v14.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    v14.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    v14.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v14.m_iterator.m_iterator.m_parents.m_pList )
      v14.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)v14.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    v4 = v9;
  }
  else
  {
    v11 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->vfptr);
    v4 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v3->vfptr) < v11;
  }
  return v4;
}

// File Line: 215
// RVA: 0xEC0DAC
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::ZString *key, OSuite::ZUsageTracker *const *value)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rdi
  OSuite::ZUsageTracker **v4; // rbx
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> data; // [rsp+20h] [rbp-38h]

  v3 = this;
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  v4 = (OSuite::ZUsageTracker **)value;
  OSuite::ZString::ZString(&data.m_First, key);
  data.m_Second = *v4;
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::Insert(
    (OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > > *)&v3->vfptr,
    &data);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  OSuite::ZString::~ZString(&data.m_First);
}

// File Line: 241
// RVA: 0xED017C
OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *__fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::Find(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *result, OSuite::ZString *key)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *v4; // rdi
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *v5; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v6; // rcx
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> data; // [rsp+20h] [rbp-98h]
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > resulta; // [rsp+48h] [rbp-70h]

  v3 = this;
  v4 = result;
  OSuite::ZString::ZString(&data.m_First, key);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  v5 = OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::Find(
         (OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > > *)&v3->vfptr,
         &resulta,
         &data);
  v4->vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->m_iterator.vfptr,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v5->vfptr);
  v6 = resulta.m_parents.m_pList;
  v4->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v6 )
    v6->vfptr->__vecDelDtor((OSuite::ZObject *)&v6->vfptr, 1u);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  OSuite::ZString::~ZString(&data.m_First);
  return v4;
}

// File Line: 255
// RVA: 0xED170C
OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> *__fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> *result, OSuite::ZString *key)
{
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> *v3; // rdi
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *v4; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v5; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator resulta; // [rsp+20h] [rbp-78h]

  v3 = result;
  v4 = OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
         this,
         &resulta,
         key);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  v3->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v3->m_iterator.m_iterator.vfptr,
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->m_iterator.vfptr);
  v5 = resulta.m_iterator.m_parents.m_pList;
  resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v3->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v5 )
    v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
  return v3;
}

// File Line: 289
// RVA: 0xEC0EB0
OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *__fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *result)
{
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *v2; // rdi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+28h] [rbp-70h]

  v2 = result;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, (OSuite::ZRedBlackTreeBase *)&this->vfptr);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  v2->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v2->m_iterator.m_iterator.vfptr,
    &other);
  v3 = other.m_parents.m_pList;
  v2->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
  return v2;
}

// File Line: 322
// RVA: 0xED9290
OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *__fastcall OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::IteratorEnd(OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *this, OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *result)
{
  OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *v2; // rdi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+20h] [rbp-68h]

  v2 = result;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, (OSuite::ZRedBlackTreeBase *)&this->vfptr, 0i64, 0i64);
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  v2->vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v2->m_iterator.vfptr,
    &other);
  v3 = other.m_parents.m_pList;
  v2->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
  return v2;
}

