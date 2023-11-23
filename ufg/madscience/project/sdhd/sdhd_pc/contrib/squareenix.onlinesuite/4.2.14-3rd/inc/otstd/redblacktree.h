// File Line: 58
// RVA: 0x428040
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *this,
        OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *data)
{
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(this, data);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::`vftable;
  this->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
  OSuite::ZString::ZString(&this->m_data.m_First, &data->m_First);
  OSuite::ZString::ZString(&this->m_data.m_Second, &data->m_Second);
  this->m_data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
}

// File Line: 66
// RVA: 0x428AD0
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::~TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this)
{
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *p_m_data; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  p_m_data = &this->m_data;
  p_m_data->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  p_m_data->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::~ZUrl(&p_m_data->m_First);
}

// File Line: 80
// RVA: 0x42B9C0
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::DeepClone(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this)
{
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *v2; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v3; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v4; // rbx

  v2 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *)OSuite::ZObject::operator new(0x108ui64);
  if ( v2 )
  {
    OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>(
      v2,
      &this->m_data);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  OSuite::ZRedBlackTreeBase::ZElementBase::DeepCloneFrom(v4, this);
  return v4;
}

// File Line: 87
// RVA: 0x42B340
void __fastcall OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::CopyValueFrom(
        OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *that)
{
  OSuite::ZRedBlackTreeBase::ZElementBase *v2; // rbx
  OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *p_m_data; // rdi

  v2 = that + 1;
  p_m_data = &this->m_data;
  if ( &this->m_data != (OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *)&that[1] )
  {
    OSuite::ZUrl::operator=(&this->m_data.m_First, (OSuite::ZUrl *)&that[1].m_pLeft);
    p_m_data->m_Second = (OSuite::ZCachedObject *)v2[7].vfptr;
  }
}

// File Line: 103
// RVA: 0x429630
void __fastcall OSuite::ZRedBlackTreeBase::ZIteratorBase::~ZIteratorBase(
        OSuite::ZRedBlackTreeBase::ZIteratorBase *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx

  this->m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  m_pList = this->m_parents.m_pList;
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
}

// File Line: 152
// RVA: 0x428B20
void __fastcall OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::~TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>(
        OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  this->m_parents.OSuite::ZRedBlackTreeBase::ZIteratorBase::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  m_pList = this->m_parents.m_pList;
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
}

// File Line: 246
// RVA: 0x428D80
void __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::~TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(this);
}

// File Line: 291
// RVA: 0x42E810
OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *__fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::IteratorEnd(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > > *this,
        OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *result)
{
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(result, this, 0i64, 0i64);
  result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  return result;
}

// File Line: 375
// RVA: 0x42C320
OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *__fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::Find(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl> > > *this,
        OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> > *result,
        OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *> *data)
{
  OSuite::TPair<OSuite::ZRedBlackTreeBase::ZElementBase *,OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *> resulta; // [rsp+28h] [rbp-D8h] BYREF
  __int64 v8; // [rsp+40h] [rbp-C0h]
  OSuite::ZRedBlackTreeBase::ZElementBase v9; // [rsp+48h] [rbp-B8h] BYREF
  void **v10; // [rsp+68h] [rbp-98h]
  OSuite::ZUrl v11; // [rsp+70h] [rbp-90h] BYREF
  OSuite::ZCachedObject *m_Second; // [rsp+148h] [rbp+48h]

  v8 = -2i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v9, result);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v10 = &OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::ZUrl(&v11, &data->m_First);
  m_Second = data->m_Second;
  v10 = &OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZRedBlackTreeBase::FindKeyElement(this, &resulta, &v9);
  v9.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  v10 = &OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::~ZUrl(&v11);
  if ( resulta.m_First )
  {
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(result, this, resulta.m_First, resulta.m_Second);
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>>::`vftable;
  }
  else
  {
    OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZUrl,OSuite::ZCachedObject *>,1,OSuite::TKeyValueElementComparer<OSuite::ZUrl,OSuite::ZCachedObject *,OSuite::TOperatorComparer<OSuite::ZUrl>>>::IteratorEnd(
      this,
      result);
  }
  return result;
}

// File Line: 415
// RVA: 0x42C040
bool __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementsEqual(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *p1,
        OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return OSuite::ZString::operator==((OSuite::ZString *)&p1[1].m_pLeft, (OSuite::ZString *)&p2[1].m_pLeft)
      && OSuite::ZString::operator==((OSuite::ZString *)&p1[2], (OSuite::ZString *)&p2[2]);
}

// File Line: 420
// RVA: 0x42C000
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementKeysEqual(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *p1,
        OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return ((__int64 (__fastcall *)(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->m_Comparer.vfptr[1].__vecDelDtor)(
           &this->m_Comparer,
           &p1[1],
           &p2[1]);
}

// File Line: 425
// RVA: 0x42C020
__int64 __fastcall OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::ElementKeysLessThan(
        OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > > *this,
        OSuite::ZRedBlackTreeBase::ZElementBase *p1,
        OSuite::ZRedBlackTreeBase::ZElementBase *p2)
{
  return ((__int64 (__fastcall *)(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *, OSuite::ZRedBlackTreeBase::ZElementBase *, OSuite::ZRedBlackTreeBase::ZElementBase *))this->m_Comparer.vfptr[1].Equals)(
           &this->m_Comparer,
           &p1[1],
           &p2[1]);
}

