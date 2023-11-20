// File Line: 15
// RVA: 0xED0A60
void __fastcall OSuite::ZUrlParameters::ZUrlParameters(OSuite::ZUrlParameters *this)
{
  OSuite::ZUrlParameters *v1; // rdi
  OSuite::ZRedBlackTreeBase *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable'{for `OSuite::ZObject'};
  v2 = (OSuite::ZRedBlackTreeBase *)&this->m_parameters.vfptr;
  v2[-1].m_nTotalElements = (unsigned __int64)&OSuite::ZUrlParameters::`vftable'{for `OSuite::IHashable'};
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(v2);
  v1->m_parameters.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->m_parameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  v1->m_parameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable';
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v1->m_arrayParameters.vfptr);
  v1->m_arrayParameters.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v1->m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  v1->m_arrayParameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
}

// File Line: 20
// RVA: 0xED0B4C
void __fastcall OSuite::ZUrlParameters::~ZUrlParameters(OSuite::ZUrlParameters *this)
{
  OSuite::ZUrlParameters *v1; // rbx
  OSuite::ZRedBlackTreeBase *v2; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable'{for `OSuite::ZObject'};
  v2 = (OSuite::ZRedBlackTreeBase *)&this->m_arrayParameters.vfptr;
  v2[-2].vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable'{for `OSuite::IHashable'};
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v2[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v2[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(v2);
  v3 = &v1->m_parameters;
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v3->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v3->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&v1->m_parameters.vfptr);
}

// File Line: 33
// RVA: 0xED0C6C
OSuite::ZUrlParameters *__fastcall OSuite::ZUrlParameters::operator=(OSuite::ZUrlParameters *this, OSuite::ZUrlParameters *that)
{
  OSuite::ZUrlParameters *v2; // rdi
  OSuite::ZUrlParameters *v3; // rbx

  v2 = that;
  v3 = this;
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::operator=(
      (OSuite::ZRedBlackTreeBase *)&this->m_parameters.vfptr,
      (OSuite::ZRedBlackTreeBase *)&that->m_parameters.vfptr);
    OSuite::ZRedBlackTreeBase::operator=(
      (OSuite::ZRedBlackTreeBase *)&v3->m_arrayParameters.vfptr,
      (OSuite::ZRedBlackTreeBase *)&v2->m_arrayParameters.vfptr);
  }
  return v3;
}

// File Line: 48
// RVA: 0xED0D34
char __fastcall OSuite::ZUrlParameters::operator==(OSuite::ZUrlParameters *this, OSuite::ZUrlParameters *that)
{
  OSuite::ZUrlParameters *v2; // rdi
  OSuite::ZUrlParameters *v3; // rsi
  char v4; // bl

  v2 = that;
  v3 = this;
  v4 = 0;
  if ( OSuite::ZRedBlackTreeBase::operator==(
         (OSuite::ZRedBlackTreeBase *)&this->m_parameters.vfptr,
         (OSuite::ZRedBlackTreeBase *)&that->m_parameters.vfptr)
    && OSuite::ZRedBlackTreeBase::operator==(
         (OSuite::ZRedBlackTreeBase *)&v3->m_arrayParameters.vfptr,
         (OSuite::ZRedBlackTreeBase *)&v2->m_arrayParameters.vfptr) )
  {
    v4 = 1;
  }
  return v4;
}

// File Line: 62
// RVA: 0xED127C
bool __fastcall OSuite::ZUrlParameters::operator<(OSuite::ZUrlParameters *this, OSuite::ZUrlParameters *that)
{
  OSuite::ZUrlParameters *v2; // rbx
  OSuite::ZUrlParameters *v3; // rdi
  bool result; // al

  v2 = that;
  v3 = this;
  if ( OSuite::ZRedBlackTreeBase::operator==(
         (OSuite::ZRedBlackTreeBase *)&this->m_parameters.vfptr,
         (OSuite::ZRedBlackTreeBase *)&that->m_parameters.vfptr) )
  {
    result = OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::operator<(
               &v3->m_arrayParameters,
               &v2->m_arrayParameters);
  }
  else
  {
    result = OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::operator<(
               &v3->m_parameters,
               &v2->m_parameters);
  }
  return result;
}

// File Line: 71
// RVA: 0xED140C
void __fastcall OSuite::ZUrlParameters::Clear(OSuite::ZUrlParameters *this)
{
  OSuite::ZUrlParameters *v1; // rbx

  v1 = this;
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&this->m_parameters.vfptr);
  OSuite::ZRedBlackTreeBase::Clear((OSuite::ZRedBlackTreeBase *)&v1->m_arrayParameters.vfptr);
}

// File Line: 146
// RVA: 0xED1E14
OSuite::ZString *__fastcall OSuite::ZUrlParameters::ToString(OSuite::ZUrlParameters *this, OSuite::ZString *result)
{
  OSuite::ZUrlParameters *v2; // rdi
  OSuite::ZString *v3; // r14
  char v4; // bl
  unsigned __int64 v5; // rdi
  OSuite::ZListBase *v6; // rbx
  unsigned __int64 v7; // rsi
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-E0h]
  void **v10; // [rsp+38h] [rbp-C8h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-C0h]
  OSuite::ZStringBuilder v12; // [rsp+58h] [rbp-A8h]
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> resulta; // [rsp+90h] [rbp-70h]

  v12.m_Chars.m_pList = 0i64;
  v2 = this;
  v3 = result;
  OSuite::ZStringBuilder::ZStringBuilder(&v12, 0x28ui64);
  resulta.m_iterator.m_iterator.m_pList = 0i64;
  resulta.m_iterator.m_iterator.m_pElement = 0i64;
  resulta.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v4 = 0;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&v2->m_parameters,
    &resulta);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.m_iterator.vfptr) )
  {
    OSuite::ZStringBuilder::Append(&v12, 63);
    v4 = 1;
    do
    {
      OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      OSuite::ZStringBuilder::Append(&v12, 61);
      OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[2]);
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.m_iterator.vfptr);
      if ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) )
        OSuite::ZStringBuilder::Append(&v12, 38);
    }
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) );
  }
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
    resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)resulta.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  resulta.m_iterator.m_iterator.m_pList = 0i64;
  resulta.m_iterator.m_iterator.m_pElement = 0i64;
  resulta.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    &v2->m_arrayParameters,
    &resulta);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.m_iterator.vfptr) )
  {
    if ( !v4 )
      OSuite::ZStringBuilder::Append(&v12, 63);
    do
    {
      v11.m_pListBase = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        &that,
        (OSuite::ZListBase *)&resulta.m_iterator.m_iterator.m_pElement[2]);
      v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable';
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
      v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
      if ( OSuite::ZListBase::ZListIteratorBase::operator bool(&v11) )
      {
        do
        {
          OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[1].m_pLeft);
          OSuite::ZStringBuilder::Append(&v12, 61);
          OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
          v5 = v11.m_nIndex;
          v6 = v11.m_pListBase;
          v7 = v11.m_nIndex + 1;
          OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v11.m_pListBase, v11.m_nIndex + 1);
          if ( v5 >= v6->m_nTop )
            v6->m_nTop = v7;
          OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)(v6[1].m_nSize + 24 * v5));
          OSuite::ZListBase::ZListIteratorBase::Next(&v11);
          if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
            OSuite::ZStringBuilder::Append(&v12, 38);
        }
        while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) );
      }
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&resulta.m_iterator.m_iterator.vfptr);
      if ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) )
        OSuite::ZStringBuilder::Append(&v12, 38);
    }
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) );
  }
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
    resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)resulta.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZStringBuilder::ToString(&v12, (OSuite::ZString *)&that);
  OSuite::ZString::ZString(v3, (OSuite::ZString *)&that);
  OSuite::ZString::~ZString((OSuite::ZString *)&that);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v12);
  return v3;
}

// File Line: 206
// RVA: 0xED1AD0
void __fastcall OSuite::ZUrlParameters::Parse(OSuite::ZUrlParameters *this, const char *pszParams)
{
  char v2; // al
  const char *v3; // rdi
  OSuite::ZUrlParameters *i; // rsi
  const char *v5; // rbx
  const char *v6; // rbx
  char j; // al
  OSuite::ZString *v8; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rbx
  OSuite::ZObject *v10; // rdx
  OSuite::ZString *v11; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v12; // rbx
  OSuite::ZString v13; // [rsp+20h] [rbp-E0h]
  void **v14; // [rsp+38h] [rbp-C8h]
  OSuite::ZString *v15; // [rsp+40h] [rbp-C0h]
  OSuite::ZString that; // [rsp+48h] [rbp-B8h]
  OSuite::ZString key; // [rsp+60h] [rbp-A0h]
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator v18; // [rsp+80h] [rbp-80h]
  OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator result; // [rsp+F0h] [rbp-10h]

  v2 = *pszParams;
  v3 = pszParams;
  for ( i = this; *v3; v2 = *v3 )
  {
    v5 = v3;
    while ( v2 && v2 != 61 && v2 != 38 )
      v2 = *++v5;
    key.m_pString = 0i64;
    OSuite::ZString::ZString(&key, v3, v5 - v3);
    that.m_pString = 0i64;
    OSuite::ZString::ZString(&that);
    if ( *v5 == 61 )
    {
      v6 = v5 + 1;
      v3 = v6;
      for ( j = *v6; j && j != 38; j = *v3 )
        ++v3;
      OSuite::ZString::ZString(&v13, v6, v3 - v6);
      OSuite::ZString::operator=(&that, v8);
      OSuite::ZString::~ZString(&v13);
    }
    else
    {
      v3 = v5;
    }
    if ( *v3 == 38 )
      ++v3;
    result.m_iterator.m_parents.m_pList = 0i64;
    _mm_store_si128((__m128i *)&result.m_iterator.m_pList, (__m128i)0i64);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
      &i->m_arrayParameters,
      &result,
      &key);
    if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator) )
    {
      v18.m_iterator.m_parents.m_pList = 0i64;
      _mm_store_si128((__m128i *)&v18.m_iterator.m_pList, (__m128i)0i64);
      OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
        &i->m_parameters,
        &v18,
        &key);
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&v18.m_iterator) )
      {
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
          &i->m_parameters,
          &key,
          &that);
      }
      else
      {
        v15 = 0i64;
        OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v13.vfptr, v10);
        v15 = 0i64;
        v13.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
        v14 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
        v11 = OSuite::TList<OSuite::ZString>::AllocList((OSuite::TList<OSuite::ZString> *)&v13, 0i64, 0x10ui64);
        v13.m_pString = 0i64;
        v13.vfptr = (OSuite::IHashableVtbl *)16;
        v12 = v18.m_iterator.m_pElement;
        v15 = v11;
        OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)&v13, 1ui64);
        OSuite::ZString::operator=(&v15[(_QWORD)v13.m_pString], (OSuite::ZString *)&v12[2]);
        OSuite::TList<OSuite::ZString>::Grow(
          (OSuite::TList<OSuite::ZString> *)&v13,
          (unsigned __int64)&(++v13.m_pString)->m_nRefCount + 1);
        OSuite::ZString::operator=(&v15[(_QWORD)v13.m_pString], &that);
        ++v13.m_pString;
        OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
          &i->m_arrayParameters,
          &key,
          (OSuite::TList<OSuite::ZString> *)&v13);
        OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v18.m_iterator.vfptr);
        v13.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
        v14 = &OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
        if ( v15 )
        {
          if ( LODWORD(v15[-1].m_pString) )
            v15->vfptr->__vecDelDtor((OSuite::ZObject *)&v15->vfptr, 3u);
          else
            Illusion::ShaderParam::operator delete(&v15[-1].m_pString);
        }
      }
      v18.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
      v18.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
      v18.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
      v18.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
      if ( v18.m_iterator.m_parents.m_pList )
        v18.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v18.m_iterator.m_parents.m_pList, 1u);
    }
    else
    {
      v9 = result.m_iterator.m_pElement;
      OSuite::TList<OSuite::ZString>::Grow(
        (OSuite::TList<OSuite::ZString> *)&result.m_iterator.m_pElement[2],
        (unsigned __int64)&result.m_iterator.m_pElement[2].m_pRight->vfptr + 1);
      OSuite::ZString::operator=((OSuite::ZString *)&v9[3].vfptr[3 * (_QWORD)v9[2].m_pRight], &that);
      ++v9[2].m_pRight;
    }
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZString::~ZString(&that);
    OSuite::ZString::~ZString(&key);
  }
}

// File Line: 266
// RVA: 0xED142C
unsigned int __fastcall OSuite::ZUrlParameters::ComputeHash(OSuite::ZUrlParameters *this)
{
  OSuite::ZUrlParameters *v1; // rdi
  unsigned int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  __int64 v8; // r8
  unsigned int v9; // eax
  __int64 v10; // rdx
  __int64 v11; // r8
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> result; // [rsp+20h] [rbp-E0h]
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> v14; // [rsp+90h] [rbp-70h]

  v1 = this;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v2 = OSuite::FComputeHashBegin((_exception *)this);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&v1->vfptr,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v3 = ((__int64 (*)(void))result.m_iterator.m_iterator.m_pElement[1].m_pRight->m_pLeft)();
    v4 = OSuite::FComputeHashAdd(v2, v3);
    v5 = ((__int64 (*)(void))result.m_iterator.m_iterator.m_pElement[2].m_pLeft->m_pLeft)();
    v2 = OSuite::FComputeHashAdd(v4, v5);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result.m_iterator.m_iterator.vfptr);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  v14.m_iterator.m_iterator.m_pList = 0i64;
  v14.m_iterator.m_iterator.m_pElement = 0i64;
  v14.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&v1->m_parameters.m_Comparer.vfptr,
    &v14);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v14.m_iterator.m_iterator) )
  {
    v6 = ((__int64 (__cdecl *)(OSuite::ZRedBlackTreeBase::ZElementBase **, __int64, __int64))v14.m_iterator.m_iterator.m_pElement[1].m_pRight->m_pLeft)(
           &v14.m_iterator.m_iterator.m_pElement[1].m_pRight,
           v10,
           v11);
    v7 = OSuite::FComputeHashAdd(v2, v6);
    v9 = (*(__int64 (__cdecl **)(OSuite::ZRedBlackTreeBase::EColour *, _QWORD, __int64))(*(_QWORD *)&v14.m_iterator.m_iterator.m_pElement[2].m_eColour
                                                                                       + 8i64))(
           &v14.m_iterator.m_iterator.m_pElement[2].m_eColour,
           *(_QWORD *)&v14.m_iterator.m_iterator.m_pElement[2].m_eColour,
           v8);
    v2 = OSuite::FComputeHashAdd(v7, v9);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v14.m_iterator.m_iterator.vfptr);
  }
  v14.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  v14.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
  v14.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  v14.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  v14.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  if ( v14.m_iterator.m_iterator.m_parents.m_pList )
    v14.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)v14.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  return OSuite::FComputeHashEnd(v2);
}

