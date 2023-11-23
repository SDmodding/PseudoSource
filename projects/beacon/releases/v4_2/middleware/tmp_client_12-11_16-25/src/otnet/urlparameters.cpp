// File Line: 15
// RVA: 0xED0A60
void __fastcall OSuite::ZUrlParameters::ZUrlParameters(OSuite::ZUrlParameters *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *p_m_parameters; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable{for `OSuite::ZObject};
  p_m_parameters = &this->m_parameters;
  p_m_parameters[-1].m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable{for `OSuite::IHashable};
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(p_m_parameters);
  this->m_parameters.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_parameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_parameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_arrayParameters);
  this->m_arrayParameters.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_arrayParameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
}

// File Line: 20
// RVA: 0xED0B4C
void __fastcall OSuite::ZUrlParameters::~ZUrlParameters(OSuite::ZUrlParameters *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *p_m_arrayParameters; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable{for `OSuite::ZObject};
  p_m_arrayParameters = &this->m_arrayParameters;
  p_m_arrayParameters[-2].m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUrlParameters::`vftable{for `OSuite::IHashable};
  p_m_arrayParameters->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  p_m_arrayParameters->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString> >,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > >::vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  p_m_arrayParameters->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(p_m_arrayParameters);
  this->m_parameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_parameters.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_parameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(&this->m_parameters);
}

// File Line: 33
// RVA: 0xED0C6C
OSuite::ZUrlParameters *__fastcall OSuite::ZUrlParameters::operator=(
        OSuite::ZUrlParameters *this,
        OSuite::ZUrlParameters *that)
{
  if ( this != that )
  {
    OSuite::ZRedBlackTreeBase::operator=(&this->m_parameters, &that->m_parameters);
    OSuite::ZRedBlackTreeBase::operator=(&this->m_arrayParameters, &that->m_arrayParameters);
  }
  return this;
}

// File Line: 48
// RVA: 0xED0D34
char __fastcall OSuite::ZUrlParameters::operator==(OSuite::ZUrlParameters *this, OSuite::ZUrlParameters *that)
{
  char v4; // bl

  v4 = 0;
  if ( OSuite::ZRedBlackTreeBase::operator==(&this->m_parameters, &that->m_parameters)
    && OSuite::ZRedBlackTreeBase::operator==(&this->m_arrayParameters, &that->m_arrayParameters) )
  {
    return 1;
  }
  return v4;
}

// File Line: 62
// RVA: 0xED127C
bool __fastcall OSuite::ZUrlParameters::operator<(OSuite::ZUrlParameters *this, OSuite::ZUrlParameters *that)
{
  if ( OSuite::ZRedBlackTreeBase::operator==(&this->m_parameters, &that->m_parameters) )
    return OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::operator<(
             &this->m_arrayParameters,
             &that->m_arrayParameters);
  else
    return OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::operator<(
             &this->m_parameters,
             (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&that->m_parameters);
}

// File Line: 71
// RVA: 0xED140C
void __fastcall OSuite::ZUrlParameters::Clear(OSuite::ZUrlParameters *this)
{
  OSuite::ZRedBlackTreeBase::Clear(&this->m_parameters);
  OSuite::ZRedBlackTreeBase::Clear(&this->m_arrayParameters);
}

// File Line: 146
// RVA: 0xED1E14
OSuite::ZString *__fastcall OSuite::ZUrlParameters::ToString(OSuite::ZUrlParameters *this, OSuite::ZString *result)
{
  char v4; // bl
  unsigned __int64 m_nIndex; // rdi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v7; // rsi
  OSuite::ZListBase::ZListIteratorBase that; // [rsp+20h] [rbp-E0h] BYREF
  void **v10; // [rsp+38h] [rbp-C8h]
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::ZStringBuilder v12; // [rsp+58h] [rbp-A8h] BYREF
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> resulta; // [rsp+90h] [rbp-70h] BYREF

  v12.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v12, 0x28ui64);
  resulta.m_iterator.m_iterator.m_pList = 0i64;
  resulta.m_iterator.m_iterator.m_pElement = 0i64;
  resulta.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v4 = 0;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_parameters,
    &resulta);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&resulta.m_iterator.m_iterator) )
  {
    OSuite::ZStringBuilder::Append(&v12, 63);
    v4 = 1;
    do
    {
      OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[1].m_pLeft);
      OSuite::ZStringBuilder::Append(&v12, 61);
      OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[2]);
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&resulta.m_iterator.m_iterator);
      if ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) )
        OSuite::ZStringBuilder::Append(&v12, 38);
    }
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) );
  }
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
    resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      resulta.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  resulta.m_iterator.m_iterator.m_pList = 0i64;
  resulta.m_iterator.m_iterator.m_pElement = 0i64;
  resulta.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    &this->m_arrayParameters,
    &resulta);
  if ( OSuite::ZRedBlackTreeBase::ZIteratorBase::operator bool(&resulta.m_iterator.m_iterator) )
  {
    if ( !v4 )
      OSuite::ZStringBuilder::Append(&v12, 63);
    do
    {
      v11.m_pListBase = 0i64;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(
        &that,
        (OSuite::ZListBase *)&resulta.m_iterator.m_iterator.m_pElement[2]);
      v10 = &OSuite::TConstIterator<OSuite::TList<OSuite::ZOEdmEndRole *>::ZIterator,OSuite::ZOEdmEndRole *,int>::`vftable;
      that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, &that);
      v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
      if ( OSuite::ZListBase::ZListIteratorBase::operator bool(&v11) )
      {
        do
        {
          OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)&resulta.m_iterator.m_iterator.m_pElement[1].m_pLeft);
          OSuite::ZStringBuilder::Append(&v12, 61);
          OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
          m_nIndex = v11.m_nIndex;
          m_pListBase = v11.m_pListBase;
          v7 = v11.m_nIndex + 1;
          OSuite::TList<OSuite::ZString>::Grow((OSuite::TList<OSuite::ZString> *)v11.m_pListBase, v11.m_nIndex + 1);
          if ( m_nIndex >= m_pListBase->m_nTop )
            m_pListBase->m_nTop = v7;
          OSuite::ZStringBuilder::Append(&v12, (OSuite::ZString *)(m_pListBase[1].m_nSize + 24 * m_nIndex));
          OSuite::ZListBase::ZListIteratorBase::Next(&v11);
          if ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
            OSuite::ZStringBuilder::Append(&v12, 38);
        }
        while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) );
      }
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&resulta.m_iterator.m_iterator);
      if ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) )
        OSuite::ZStringBuilder::Append(&v12, 38);
    }
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&resulta.m_iterator.m_iterator) );
  }
  resulta.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  resulta.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  resulta.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  resulta.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( resulta.m_iterator.m_iterator.m_parents.m_pList )
    resulta.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      resulta.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::ZStringBuilder::ToString(&v12, (OSuite::ZString *)&that);
  OSuite::ZString::ZString(result, (OSuite::ZString *)&that);
  OSuite::ZString::~ZString((OSuite::ZString *)&that);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v12);
  return result;
}

// File Line: 206
// RVA: 0xED1AD0
void __fastcall OSuite::ZUrlParameters::Parse(OSuite::ZUrlParameters *this, char *pszParams)
{
  char v2; // al
  const char *i; // rdi
  const char *v5; // rbx
  const char *v6; // rbx
  char j; // al
  OSuite::ZString *v8; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rbx
  OSuite::ZObject *v10; // rdx
  OSuite::ZString *v11; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pElement; // rbx
  OSuite::TList<OSuite::ZString> v13; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZString that; // [rsp+48h] [rbp-B8h] BYREF
  OSuite::ZString key; // [rsp+60h] [rbp-A0h] BYREF
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator v16; // [rsp+80h] [rbp-80h] BYREF
  OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator result; // [rsp+F0h] [rbp-10h] BYREF

  v2 = *pszParams;
  for ( i = pszParams; *i; v2 = *i )
  {
    v5 = i;
    while ( v2 && v2 != 61 && v2 != 38 )
      v2 = *++v5;
    key.m_pString = 0i64;
    OSuite::ZString::ZString(&key, i, v5 - i);
    that.m_pString = 0i64;
    OSuite::ZString::ZString(&that);
    if ( *v5 == 61 )
    {
      v6 = v5 + 1;
      i = v6;
      for ( j = *v6; j && j != 38; j = *i )
        ++i;
      OSuite::ZString::ZString((OSuite::ZString *)&v13, v6, i - v6);
      OSuite::ZString::operator=(&that, v8);
      OSuite::ZString::~ZString((OSuite::ZString *)&v13);
    }
    else
    {
      i = v5;
    }
    if ( *i == 38 )
      ++i;
    result.m_iterator.m_parents.m_pList = 0i64;
    *(_OWORD *)&result.m_iterator.m_pList = 0i64;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
      &this->m_arrayParameters,
      &result,
      &key);
    if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator) )
    {
      v16.m_iterator.m_parents.m_pList = 0i64;
      *(_OWORD *)&v16.m_iterator.m_pList = 0i64;
      OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
        &this->m_parameters,
        &v16,
        &key);
      if ( OSuite::ZString::IsNull((OSuite::ZString *)&v16.m_iterator) )
      {
        OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
          &this->m_parameters,
          &key,
          &that);
      }
      else
      {
        v13.m_pList = 0i64;
        OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v13, v10);
        v13.m_pList = 0i64;
        v13.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
        v13.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
        v11 = OSuite::TList<OSuite::ZString>::AllocList(&v13, 0i64, 0x10ui64);
        v13.m_nTop = 0i64;
        v13.m_nSize = 16i64;
        m_pElement = v16.m_iterator.m_pElement;
        v13.m_pList = v11;
        OSuite::TList<OSuite::ZString>::Grow(&v13, 1ui64);
        OSuite::ZString::operator=(&v13.m_pList[v13.m_nTop], (OSuite::ZString *)&m_pElement[2]);
        OSuite::TList<OSuite::ZString>::Grow(&v13, ++v13.m_nTop + 1);
        OSuite::ZString::operator=(&v13.m_pList[v13.m_nTop++], &that);
        OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
          &this->m_arrayParameters,
          &key,
          (OSuite::ZListBase::ZListIteratorBase *)&v13);
        OSuite::ZRedBlackTreeBase::ZIteratorBase::Remove(&v16.m_iterator);
        v13.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
        v13.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
        if ( v13.m_pList )
        {
          if ( LODWORD(v13.m_pList[-1].m_pString) )
            v13.m_pList->vfptr->__vecDelDtor(v13.m_pList, 3u);
          else
            Illusion::ShaderParam::operator delete(&v13.m_pList[-1].m_pString);
        }
      }
      v16.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
      v16.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
      v16.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
      v16.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
      if ( v16.m_iterator.m_parents.m_pList )
        v16.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v16.m_iterator.m_parents.m_pList, 1u);
    }
    else
    {
      v9 = result.m_iterator.m_pElement;
      OSuite::TList<OSuite::ZString>::Grow(
        (OSuite::TList<OSuite::ZString> *)&result.m_iterator.m_pElement[2],
        (unsigned __int64)&result.m_iterator.m_pElement[2].m_pRight->vfptr + 1);
      OSuite::ZString::operator=((OSuite::ZString *)&v9[3].vfptr[3 * (__int64)v9[2].m_pRight++], &that);
    }
    result.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_parents.m_pList )
      result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
    OSuite::ZString::~ZString(&that);
    OSuite::ZString::~ZString(&key);
  }
}

// File Line: 266
// RVA: 0xED142C
unsigned int __fastcall OSuite::ZUrlParameters::ComputeHash(OSuite::ZUrlParameters *this)
{
  unsigned int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> result; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> v11; // [rsp+90h] [rbp-70h] BYREF

  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v2 = OSuite::FComputeHashBegin((_exception *)this);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->OSuite::IHashable,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v3 = ((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase **))result.m_iterator.m_iterator.m_pElement[1].m_pRight->m_pLeft)(&result.m_iterator.m_iterator.m_pElement[1].m_pRight);
    v4 = OSuite::FComputeHashAdd(v2, v3);
    v5 = ((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase **))result.m_iterator.m_iterator.m_pElement[2].m_pLeft->m_pLeft)(&result.m_iterator.m_iterator.m_pElement[2].m_pLeft);
    v2 = OSuite::FComputeHashAdd(v4, v5);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&result.m_iterator.m_iterator);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  v11.m_iterator.m_iterator.m_pList = 0i64;
  v11.m_iterator.m_iterator.m_pElement = 0i64;
  v11.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_parameters.m_Comparer.OSuite::ZObject,
    &v11);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v11.m_iterator.m_iterator) )
  {
    v6 = ((__int64 (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase **))v11.m_iterator.m_iterator.m_pElement[1].m_pRight->m_pLeft)(&v11.m_iterator.m_iterator.m_pElement[1].m_pRight);
    v7 = OSuite::FComputeHashAdd(v2, v6);
    v8 = (*(__int64 (__fastcall **)(OSuite::ZRedBlackTreeBase::EColour *))(*(_QWORD *)&v11.m_iterator.m_iterator.m_pElement[2].m_eColour
                                                                         + 8i64))(&v11.m_iterator.m_iterator.m_pElement[2].m_eColour);
    v2 = OSuite::FComputeHashAdd(v7, v8);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v11.m_iterator.m_iterator);
  }
  v11.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
  v11.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  v11.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  v11.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  if ( v11.m_iterator.m_iterator.m_parents.m_pList )
    v11.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v11.m_iterator.m_iterator.m_parents.m_pList, 1u);
  return OSuite::FComputeHashEnd(v2);
}

