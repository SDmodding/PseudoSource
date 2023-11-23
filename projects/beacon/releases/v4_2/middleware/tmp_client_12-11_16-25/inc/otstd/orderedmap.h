// File Line: 165
// RVA: 0xED1068
bool __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::operator<(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *this,
        OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *that)
{
  unsigned __int64 v5; // rbx
  OSuite::ZString *p_m_pLeft; // rbx
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rdi
  bool v9; // bl
  bool v10; // al
  unsigned __int64 v11; // rbx
  OSuite::ZString v12; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> result; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> v14; // [rsp+B0h] [rbp-50h] BYREF

  if ( this == that )
    return 0;
  v5 = OSuite::ZHttpStreamReader::Tell(that);
  if ( OSuite::ZHttpStreamReader::Tell(this) == v5 )
  {
    result.m_iterator.m_iterator.m_pList = 0i64;
    result.m_iterator.m_iterator.m_pElement = 0i64;
    result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
      this,
      &result);
    v14.m_iterator.m_iterator.m_pList = 0i64;
    v14.m_iterator.m_iterator.m_pElement = 0i64;
    v14.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
      that,
      &v14);
    while ( 1 )
    {
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator)
        || OSuite::ZString::IsNull((OSuite::ZString *)&v14.m_iterator.m_iterator) )
      {
        v9 = 0;
        goto LABEL_11;
      }
      p_m_pLeft = (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft;
      OSuite::ZString::ZString(&v12, (OSuite::ZString *)&v14.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      v8 = v7;
      LOBYTE(p_m_pLeft) = !OSuite::ZString::operator==(p_m_pLeft, v7);
      OSuite::ZString::~ZString(v8);
      if ( (_BYTE)p_m_pLeft )
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
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&result.m_iterator.m_iterator);
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v14.m_iterator.m_iterator);
    }
    v10 = OSuite::ZString::operator<(
            (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft,
            (OSuite::ZString *)&v14.m_iterator.m_iterator.m_pElement[1].m_pLeft);
LABEL_18:
    v9 = v10;
LABEL_11:
    v14.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v14.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v14.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v14.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v14.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v14.m_iterator.m_iterator.m_parents.m_pList )
      v14.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v14.m_iterator.m_iterator.m_parents.m_pList, 1u);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    return v9;
  }
  else
  {
    v11 = OSuite::ZHttpStreamReader::Tell(that);
    return OSuite::ZHttpStreamReader::Tell(this) < v11;
  }
}

// File Line: 215
// RVA: 0xEC0DAC
void __fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *this,
        OSuite::ZString *key,
        OSuite::ZUsageTracker **value)
{
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> data; // [rsp+20h] [rbp-38h] BYREF

  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::ZString::ZString(&data.m_First, key);
  data.m_Second = *value;
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::Insert(
    this,
    &data);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::ZString::~ZString(&data.m_First);
}

// File Line: 241
// RVA: 0xED017C
OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *__fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *this,
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *result,
        OSuite::ZString *key)
{
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *v5; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> data; // [rsp+20h] [rbp-98h] BYREF
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > resulta; // [rsp+48h] [rbp-70h] BYREF

  OSuite::ZString::ZString(&data.m_First, key);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  v5 = OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::Find(
         this,
         &resulta,
         &data);
  result->vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator, v5);
  m_pList = resulta.m_parents.m_pList;
  result->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_parents.OSuite::ZRedBlackTreeBase::ZIteratorBase::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::ZString::~ZString(&data.m_First);
  return result;
}

// File Line: 255
// RVA: 0xED170C
OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> *__fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this,
        OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZString,OSuite::ZString> *result,
        OSuite::ZString *key)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator *v4; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator resulta; // [rsp+20h] [rbp-78h] BYREF

  v4 = OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
         this,
         &resulta,
         key);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  result->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator.m_iterator, &v4->m_iterator);
  m_pList = resulta.m_iterator.m_parents.m_pList;
  resulta.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  return result;
}

// File Line: 289
// RVA: 0xEC0EB0
OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *__fastcall OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
        OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *this,
        OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *result)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+28h] [rbp-70h] BYREF

  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, this);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  result->m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator.m_iterator, &other);
  m_pList = other.m_parents.m_pList;
  result->m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  return result;
}

// File Line: 322
// RVA: 0xED9290
OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *__fastcall OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::IteratorEnd(
        OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *this,
        OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIterator *result)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+20h] [rbp-68h] BYREF

  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, this, 0i64, 0i64);
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result->vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&result->m_iterator, &other);
  m_pList = other.m_parents.m_pList;
  result->m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
  return result;
}

