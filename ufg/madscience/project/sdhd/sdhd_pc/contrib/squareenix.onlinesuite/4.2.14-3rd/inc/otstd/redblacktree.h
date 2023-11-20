// File Line: 58
// RVA: 0x428040
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *this, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *data)
{
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v2; // rbx
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v3; // rsi
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v4; // [rsp+48h] [rbp+10h]

  v2 = data;
  v3 = this;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(
    (OSuite::ZObject *)&this->vfptr,
    (OSuite::ZObject *)&data->vfptr);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::`vftable;
  v4 = &v3->m_data;
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
  OSuite::ZString::ZString(&v3->m_data.m_First, &v2->m_First);
  OSuite::ZString::ZString(&v3->m_data.m_Second, &v2->m_Second);
  v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
}

// File Line: 66
// RVA: 0x428AD0
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::~TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this)
{
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *v1; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v1 = &this->m_data;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::~ZUrl(&v1->m_First);
}

// File Line: 80
// RVA: 0x42B9C0
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::DeepClone(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this)
{
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v1; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v2; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rbx

  v1 = this;
  v2 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *)OSuite::ZObject::operator new(0x108ui64);
  if ( v2 )
  {
    OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>(
      v2,
      &v1->m_data);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::ZElementBase::DeepCloneFrom(v4, (OSuite::ZRedBlackTreeBase::ZElementBase *)&v1->vfptr);
  return v4;
}

// File Line: 87
// RVA: 0x42B340
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::CopyValueFrom(OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this, OSuite::ZRedBlackTreeBase::ZElementBase *that)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *v3; // rdi

  v2 = that + 1;
  v3 = &this->m_data;
  if ( &this->m_data != (OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *)&that[1] )
  {
    OSuite::ZUrl::operator=(&this->m_data.m_First, (OSuite::ZUrl *)&that[1].m_pLeft);
    v3->m_Second = (OSuite::ZCachedObject *)v2[7].vfptr;
  }
}

// File Line: 103
// RVA: 0x429630
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::~ZIteratorBase(OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rcx

  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  v1 = this->m_parents.m_pList;
  if ( v1 )
    v1->vfptr->__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 1u);
}

// File Line: 152
// RVA: 0x428B20
void __fastcall OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::~TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>(OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  v1 = this->m_parents.m_pList;
  if ( v1 )
    v1->vfptr->__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 1u);
}

// File Line: 246
// RVA: 0x428D80
void __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::~TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this)
{
  OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v1; // [rsp+48h] [rbp+10h]

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  v1 = &this->m_Comparer;
  v1->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  v1->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&this->vfptr);
}

// File Line: 291
// RVA: 0x42E810
OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *__fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::IteratorEnd(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > > *this, OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *result)
{
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v2; // rbx

  v2 = result;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result->vfptr,
    (OSuite::ZRedBlackTreeBase *)&this->vfptr,
    0i64,
    0i64);
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  return v2;
}

// File Line: 375
// RVA: 0x42C320
OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *__fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::Find(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > > *this, OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *result, OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *data)
{
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *v3; // rbx
  OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v4; // rdi
  OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > > *v5; // rsi
  OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> resulta; // [rsp+28h] [rbp-D8h]
  __int64 v8; // [rsp+40h] [rbp-C0h]
  OSuite::ZObject v9; // [rsp+48h] [rbp-B8h]
  void **v10; // [rsp+68h] [rbp-98h]
  OSuite::ZUrl v11; // [rsp+70h] [rbp-90h]
  OSuite::ZCachedObject *v12; // [rsp+148h] [rbp+48h]

  v8 = -2i64;
  v3 = data;
  v4 = result;
  v5 = this;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v9, (OSuite::ZObject *)&result->vfptr);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v10 = &OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::ZUrl(&v11, &v3->m_First);
  v12 = v3->m_Second;
  v10 = &OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZRedBlackTreeBase::FindKeyElement(
    (OSuite::ZRedBlackTreeBase *)&v5->vfptr,
    &resulta,
    (OSuite::ZRedBlackTreeBase::ZElementBase *)&v9);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v10 = &OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::~ZUrl(&v11);
  if ( resulta.m_First )
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v4->vfptr,
      (OSuite::ZRedBlackTreeBase *)&v5->vfptr,
      resulta.m_First,
      resulta.m_Second);
    v4->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  }
  else
  {
    OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::IteratorEnd(
      v5,
      v4);
  }
  return v4;
}

// File Line: 415
// RVA: 0x42C040
bool __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementsEqual(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this, OSuite::ZRedBlackTreeBase::ZElementBase *p1, OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rdi
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rbx

  v3 = p1;
  v4 = p2;
  return OSuite::ZString::operator==((OSuite::ZString *)&p1[1].m_pLeft, (OSuite::ZString *)&p2[1].m_pLeft)
      && OSuite::ZString::operator==((OSuite::ZString *)&v3[2], (OSuite::ZString *)&v4[2]);
}

// File Line: 420
// RVA: 0x42C000
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementKeysEqual(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this, OSuite::ZRedBlackTreeBase::ZElementBase *p1, OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return ((__int64 (__fastcall *)(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->m_Comparer.vfptr[1].__vecDelDtor)(
           &this->m_Comparer,
           &p1[1],
           &p2[1]);
}

// File Line: 425
// RVA: 0x42C020
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementKeysLessThan(OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this, OSuite::ZRedBlackTreeBase::ZElementBase *p1, OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return this->m_Comparer.vfptr[1].Equals(
           (OSuite::IComparer<OSuite::ZString> *)&this->m_Comparer,
           (OSuite::ZString *)&p1[1],
           (OSuite::ZString *)&p2[1]);
}

