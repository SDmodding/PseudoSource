// File Line: 58
// RVA: 0xEE3CB0
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>>::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>>(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > > *this, OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *data)
{
  OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *v2; // rbx
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > > *v3; // rdi

  v2 = data;
  v3 = this;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
    (OSuite::ZObject *)&this->vfptr,
    (OSuite::ZObject *)&data->vfptr);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>>::`vftable';
  v3->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::`vftable';
  v3->m_data.m_First = v2->m_First;
  v3->m_data.m_Second.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable';
  v3->m_data.m_Second.m_First = v2->m_Second.m_First;
  OSuite::ZString::ZString(&v3->m_data.m_Second.m_Second, &v2->m_Second.m_Second);
  v3->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::`vftable';
}

// File Line: 66
// RVA: 0xED0AE4
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>>::~TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>>(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString> > > *this)
{
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString> > > *v1; // rbx
  OSuite::ZString *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>>::`vftable';
  this->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>::`vftable';
  this->m_data.m_Second.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
  this->m_data.m_Second.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
  v2 = this->m_data.m_Second.m_pList;
  if ( v2 )
  {
    if ( LODWORD(v2[-1].m_pString) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].m_pString);
  }
  OSuite::ZString::~ZString(&v1->m_data.m_First);
}

// File Line: 80
// RVA: 0xED876C
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>>::DeepClone(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *this)
{
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *v1; // rdi
  OSuite::ZObject *v2; // rdx
  char *v3; // rbx

  v1 = this;
  v3 = (char *)OSuite::ZObject::operator new(0x48ui64);
  if ( v3 )
  {
    *((_QWORD *)v3 + 1) = 0i64;
    *((_QWORD *)v3 + 2) = 0i64;
    *((_QWORD *)v3 + 7) = 0i64;
    *((_QWORD *)v3 + 8) = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)v3, v2);
    *(_QWORD *)v3 = &OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>>::`vftable';
    *((_QWORD *)v3 + 4) = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
    OSuite::ZString::ZString((OSuite::ZString *)(v3 + 40), &v1->m_data.m_First);
    *((_QWORD *)v3 + 8) = v1->m_data.m_Second;
    *((_QWORD *)v3 + 4) = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  }
  else
  {
    v3 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::ZElementBase::DeepCloneFrom(
    (OSuite::ZRedBlackTreeBase::ZElementBase *)v3,
    (OSuite::ZRedBlackTreeBase::ZElementBase *)&v1->vfptr);
  return (OSuite::ZRedBlackTreeBase::ZElementBase *)v3;
}

// File Line: 87
// RVA: 0xEC0D74
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::CopyValueFrom(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *this, OSuite::ZRedBlackTreeBase::ZElementBase *that)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *v3; // rdi

  v2 = that + 1;
  v3 = &this->m_data;
  if ( &this->m_data != (OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *)&that[1] )
  {
    OSuite::ZString::operator=(&this->m_data.m_First, (OSuite::ZString *)&that[1].m_pLeft);
    v3->m_Second = (OSuite::ZUsageTracker *)v2[1].vfptr;
  }
}

// File Line: 312
// RVA: 0xEEAB80
void __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>>::Insert(OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > > *this, OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *data)
{
  OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > > *v2; // rdi
  OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *v3; // rsi
  OSuite::ZObject *v4; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rbx

  v2 = this;
  v3 = data;
  v5 = (OSuite::ZRedBlackTreeBase::ZElementBase *)OSuite::ZObject::operator new(0x38ui64);
  if ( v5 )
  {
    v5->m_pLeft = 0i64;
    v5->m_pRight = 0i64;
    v5[1].m_pLeft = 0i64;
    v5[1].m_pRight = 0i64;
    OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v5->vfptr, v4);
    v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>>::`vftable';
    v5[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
    v5[1].m_pLeft = (OSuite::ZRedBlackTreeBase::ZElementBase *)v3->m_First;
    v5[1].m_pRight = (OSuite::ZRedBlackTreeBase::ZElementBase *)v3->m_Second;
    v5[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  }
  else
  {
    v5 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v2->vfptr, v5);
}

// File Line: 375
// RVA: 0xED0248
OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *__fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::Find(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > > *this, OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *result, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *data)
{
  OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > > *v3; // rsi
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *v4; // rbx
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> > *v5; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // r8
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // r9
  OSuite::ZObject v9; // [rsp+20h] [rbp-39h]
  void **v10; // [rsp+40h] [rbp-19h]
  OSuite::ZString v11; // [rsp+48h] [rbp-11h]
  OSuite::ZUsageTracker *v12; // [rsp+60h] [rbp+7h]
  OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> resulta; // [rsp+68h] [rbp+Fh]

  *(_OWORD *)&resulta.m_First = 0ui64;
  v3 = this;
  v4 = data;
  v5 = result;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v9, (OSuite::ZObject *)&result->vfptr);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>>::`vftable';
  v10 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  OSuite::ZString::ZString(&v11, &v4->m_First);
  v12 = v4->m_Second;
  v10 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  OSuite::ZRedBlackTreeBase::FindKeyElement(
    (OSuite::ZRedBlackTreeBase *)&v3->vfptr,
    &resulta,
    (OSuite::ZRedBlackTreeBase::ZElementBase *)&v9);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>>::`vftable';
  v10 = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  OSuite::ZString::~ZString(&v11);
  v6 = resulta.m_First;
  if ( resulta.m_First )
  {
    v7 = resulta.m_Second;
  }
  else
  {
    v7 = 0i64;
    v6 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v5->vfptr,
    (OSuite::ZRedBlackTreeBase *)&v3->vfptr,
    v6,
    v7);
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  return v5;
}

// File Line: 415
// RVA: 0xEEA790
_BOOL8 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>>::ElementsEqual(OSuite::TRedBlackTree<OSuite::TKeyValueElement<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>,1,OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> > > *this, OSuite::ZRedBlackTreeBase::ZElementBase *p1, OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return *(_OWORD *)&p1[1].m_pLeft == *(_OWORD *)&p2[1].m_pLeft;
}

// File Line: 420
// RVA: 0xED70CC
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>,1,OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>>::ElementKeysEqual(OSuite::TRedBlackTree<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> >,1,OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > > *this, OSuite::ZRedBlackTreeBase::ZElementBase *p1, OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return ((__int64 (__fastcall *)(OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->m_Comparer.vfptr[1].__vecDelDtor)(
           &this->m_Comparer,
           &p1[1],
           &p2[1]);
}

// File Line: 425
// RVA: 0xED0158
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZJsonValue *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementKeysLessThan(OSuite::TRedBlackTree<OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> >,1,OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > > *this, OSuite::ZRedBlackTreeBase::ZElementBase *p1, OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return this->m_Comparer.vfptr[1].Equals(
           (OSuite::IComparer<unsigned __int64> *)&this->m_Comparer,
           (const unsigned __int64 *)&p1[1],
           (const unsigned __int64 *)&p2[1]);
}

