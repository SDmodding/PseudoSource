// File Line: 58
// RVA: 0xEE3CB0
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>>::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>>(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > > *this,
        OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *data)
{
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(this, data);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>>::`vftable;
  this->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::`vftable;
  this->m_data.m_First = data->m_First;
  this->m_data.m_Second.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
  this->m_data.m_Second.m_First = data->m_Second.m_First;
  OSuite::ZString::ZString(&this->m_data.m_Second.m_Second, &data->m_Second.m_Second);
  this->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::`vftable;
}

// File Line: 66
// RVA: 0xED0AE4
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>>::~TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>>(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString> > > *this)
{
  OSuite::ZString *m_pList; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>>::`vftable;
  this->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>::`vftable;
  this->m_data.m_Second.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
  this->m_data.m_Second.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
  m_pList = this->m_data.m_Second.m_pList;
  if ( m_pList )
  {
    if ( LODWORD(m_pList[-1].m_pString) )
      m_pList->OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pList[-1].m_pString);
  }
  OSuite::ZString::~ZString(&this->m_data.m_First);
}

// File Line: 80
// RVA: 0xED876C
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>>::DeepClone(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *this)
{
  OSuite::ZObject *v2; // rdx
  char *v3; // rbx

  v3 = (char *)OSuite::ZObject::operator new(0x48ui64);
  if ( v3 )
  {
    *((_QWORD *)v3 + 1) = 0i64;
    *((_QWORD *)v3 + 2) = 0i64;
    *((_QWORD *)v3 + 7) = 0i64;
    *((_QWORD *)v3 + 8) = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)v3, v2);
    *(_QWORD *)v3 = &OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>>::`vftable;
    *((_QWORD *)v3 + 4) = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
    OSuite::ZString::ZString((OSuite::ZString *)(v3 + 40), &this->m_data.m_First);
    *((_QWORD *)v3 + 8) = this->m_data.m_Second;
    *((_QWORD *)v3 + 4) = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::ZElementBase::DeepCloneFrom((OSuite::ZRedBlackTreeBase::ZElementBase *)v3, this);
  return (OSuite::ZRedBlackTreeBase::ZElementBase *)v3;
}

// File Line: 87
// RVA: 0xEC0D74
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::CopyValueFrom(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *that)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *p_m_data; // rdi

  v2 = that + 1;
  p_m_data = &this->m_data;
  if ( &this->m_data != (OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *)&that[1] )
  {
    OSuite::ZString::operator=(&this->m_data.m_First, (OSuite::ZString *)&that[1].m_pLeft);
    p_m_data->m_Second = (OSuite::ZUsageTracker *)v2[1].vfptr;
  }
}

// File Line: 312
// RVA: 0xEEAB80
void __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>>::Insert(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > > *this,
        OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *data)
{
  OSuite::ZObject *v4; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rbx

  v5 = (OSuite::ZRedBlackTreeBase::ZElementBase *)OSuite::ZObject::operator new(0x38ui64);
  if ( v5 )
  {
    v5->m_pLeft = 0i64;
    v5->m_pRight = 0i64;
    v5[1].m_pLeft = 0i64;
    v5[1].m_pRight = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(v5, v4);
    v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>>::`vftable;
    v5[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
    v5[1].m_pLeft = (OSuite::ZRedBlackTreeBase::ZElementBase *)data->m_First;
    v5[1].m_pRight = (OSuite::ZRedBlackTreeBase::ZElementBase *)data->m_Second;
    v5[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::InsertElementSet(this, v5);
}

// File Line: 375
// RVA: 0xED0248
OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *__fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::Find(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > > *this,
        OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *result,
        OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *data)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *m_First; // r8
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // r9
  OSuite::ZRedBlackTreeBase::ZElementBase v9; // [rsp+20h] [rbp-39h] BYREF
  void **v10; // [rsp+40h] [rbp-19h]
  OSuite::ZString v11; // [rsp+48h] [rbp-11h] BYREF
  OSuite::ZUsageTracker *m_Second; // [rsp+60h] [rbp+7h]
  OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> resulta; // [rsp+68h] [rbp+Fh] BYREF

  resulta.m_First = 0i64;
  resulta.m_Second = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v9, result);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>>::`vftable;
  v10 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::ZString::ZString(&v11, &data->m_First);
  m_Second = data->m_Second;
  v10 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::ZRedBlackTreeBase::FindKeyElement(this, &resulta, &v9);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>>::`vftable;
  v10 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  OSuite::ZString::~ZString(&v11);
  m_First = resulta.m_First;
  if ( resulta.m_First )
  {
    v7 = resulta.m_Second;
  }
  else
  {
    v7 = 0i64;
    m_First = 0i64;
  }
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(result, this, m_First, v7);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  return result;
}

// File Line: 415
// RVA: 0xEEA790
_BOOL8 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>>::ElementsEqual(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *p1,
        OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return p1[1].m_pLeft == p2[1].m_pLeft && p1[1].m_pRight == p2[1].m_pRight;
}

// File Line: 420
// RVA: 0xED70CC
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>,1,OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>>::ElementKeysEqual(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> >,1,OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *p1,
        OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return ((__int64 (__fastcall *)(OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->m_Comparer.vfptr[1].__vecDelDtor)(
           &this->m_Comparer,
           &p1[1],
           &p2[1]);
}

// File Line: 425
// RVA: 0xED0158
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementKeysLessThan(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> >,1,OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *p1,
        OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return ((__int64 (__fastcall *)(OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->m_Comparer.vfptr[1].Equals)(
           &this->m_Comparer,
           &p1[1],
           &p2[1]);
}

