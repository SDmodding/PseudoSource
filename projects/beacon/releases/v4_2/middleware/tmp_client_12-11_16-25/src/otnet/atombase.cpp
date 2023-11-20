// File Line: 15
// RVA: 0x15D8AF8
__int64 dynamic_initializer_for__OSuite::ZAtomBase::s_nClassId__()
{
  OSuite::ZAtomBase::s_nClassId = nId;
  return (unsigned int)(nId++ + 1);
}

// File Line: 46
// RVA: 0xED218C
void __fastcall OSuite::ZAtomBase::ZAtomBase(OSuite::ZAtomBase *this)
{
  OSuite::ZAtomBase *v1; // rbx

  v1 = this;
  OSuite::ZString::ZString(&this->m_sAuthorName);
  OSuite::ZString::ZString(&v1->m_sIdentifier);
  OSuite::ZString::ZString(&v1->m_sTitle);
  OSuite::ZString::ZString(&v1->m_sEditURL);
  OSuite::ZString::ZString(&v1->m_sBaseURL);
  v1->m_bHasValidSource = 0;
}

// File Line: 53
// RVA: 0xED2134
void __fastcall OSuite::ZAtomBase::ZAtomBase(OSuite::ZAtomBase *this, OSuite::ZString *baseUrl)
{
  OSuite::ZAtomBase *v2; // rdi
  OSuite::ZString *v3; // rbx

  v2 = this;
  v3 = baseUrl;
  OSuite::ZString::ZString(&this->m_sAuthorName);
  OSuite::ZString::ZString(&v2->m_sIdentifier);
  OSuite::ZString::ZString(&v2->m_sTitle);
  OSuite::ZString::ZString(&v2->m_sEditURL);
  OSuite::ZString::ZString(&v2->m_sBaseURL, v3);
  v2->m_bHasValidSource = 0;
}

// File Line: 58
// RVA: 0xED21D4
void __fastcall OSuite::ZAtomBase::~ZAtomBase(OSuite::ZAtomBase *this)
{
  OSuite::ZAtomBase *v1; // rbx

  v1 = this;
  OSuite::ZString::~ZString(&this->m_sBaseURL);
  OSuite::ZString::~ZString(&v1->m_sEditURL);
  OSuite::ZString::~ZString(&v1->m_sTitle);
  OSuite::ZString::~ZString(&v1->m_sIdentifier);
  OSuite::ZString::~ZString(&v1->m_sAuthorName);
}

// File Line: 119
// RVA: 0xED221C
OSuite::ZUrl *__fastcall OSuite::ZAtomBase::EditURL(OSuite::ZAtomBase *this, OSuite::ZUrl *result)
{
  OSuite::ZAtomBase *v2; // rdi
  OSuite::ZUrl *v3; // rbx

  v2 = this;
  v3 = result;
  if ( OSuite::ZString::operator bool(&this->m_sEditURL) )
    OSuite::ZAtomBase::GetUrlFromString(v2, v3, &v2->m_sEditURL);
  else
    OSuite::ZUrl::ZUrl(v3);
  return v3;
}

// File Line: 148
// RVA: 0xED231C
bool __fastcall OSuite::ZAtomBase::HasValidSource(OSuite::ZAtomBase *this)
{
  return this->m_bHasValidSource;
}

// File Line: 155
// RVA: 0xED2280
OSuite::ZUrl *__fastcall OSuite::ZAtomBase::GetUrlFromString(OSuite::ZAtomBase *this, OSuite::ZUrl *result, OSuite::ZString *sUrlString)
{
  OSuite::ZUrl *v3; // rdi
  OSuite::ZAtomBase *v4; // rbp
  OSuite::ZString *v5; // rsi
  bool v6; // bl
  OSuite::ZString *v7; // rax
  OSuite::ZString InternalString; // [rsp+20h] [rbp-28h]

  v3 = result;
  v4 = this;
  v5 = sUrlString;
  OSuite::ZString::ZString(&InternalString, "://");
  v6 = OSuite::ZString::IndexOf(v5, &InternalString, 0i64) < 0;
  OSuite::ZString::~ZString(&InternalString);
  if ( v6 )
  {
    v7 = OSuite::ZString::operator+(&v4->m_sBaseURL, &InternalString, v5);
    OSuite::ZUrl::Parse(v3, v7);
    OSuite::ZString::~ZString(&InternalString);
  }
  else
  {
    OSuite::ZUrl::Parse(v3, v5);
  }
  return v3;
}

// File Line: 174
// RVA: 0xED2210
bool __fastcall OSuite::ZAtomBase::ClassMatch(OSuite::ZAtomBase *this, int nClassId)
{
  return OSuite::ZAtomBase::s_nClassId == nClassId;
}

// File Line: 181
// RVA: 0xED2324
void __fastcall OSuite::ZAtomBase::Parse(OSuite::ZAtomBase *pAtom, OSuite::ZJsonObject *pJson)
{
  OSuite::ZAtomBase::ParseJson(pAtom, pJson);
}

// File Line: 188
// RVA: 0xED232C
void __fastcall OSuite::ZAtomBase::ParseJson(OSuite::ZAtomBase *this, OSuite::ZJsonObject *pJson)
{
  OSuite::ZJsonObject *v2; // rdi
  OSuite::ZAtomBase *v3; // rbx
  OSuite::ZError *v4; // rax
  OSuite::ZError *v5; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-E0h]
  void **v7; // [rsp+A0h] [rbp-60h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v8; // [rsp+A8h] [rbp-58h]

  v2 = pJson;
  v3 = this;
  v4 = OSuite::TSingleton<OSuite::ZError>::Object();
  if ( OSuite::ZError::GetThreadLastError(v4)->m_First != 7 )
  {
    v8.m_pMap = 0i64;
    v8.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    _mm_store_si128((__m128i *)&v8.m_iterator.m_iterator.m_pList, (__m128i)0i64);
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v2->m_Pairs,
      &result);
    v8.m_pMap = result.m_pMap;
    v8.m_iCurrentHash = result.m_iCurrentHash;
    v7 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v8.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v8.m_iterator.m_iterator.vfptr,
      (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&result.m_iterator.m_iterator.vfptr);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v8.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v8.m_iterator.m_iterator) )
    {
      if ( v8.m_iterator.m_iterator.m_pElement[2].vfptr )
      {
        v3->vfptr[3].__vecDelDtor(
          (OSuite::ZObject *)&v3->vfptr,
          (unsigned int)&v8.m_iterator.m_iterator.m_pElement[1].m_pLeft);
        v5 = OSuite::TSingleton<OSuite::ZError>::Object();
        if ( OSuite::ZError::GetThreadLastError(v5)->m_First == 7 )
        {
          v3->m_bHasValidSource = 0;
          break;
        }
      }
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v8);
    }
    v8.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v8.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v8.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v7 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v8.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v8.m_iterator.m_iterator.m_parents.m_pList )
      v8.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)v8.m_iterator.m_iterator.m_parents.m_pList,
        1u);
  }
}

// File Line: 216
// RVA: 0xED226C
__int64 __fastcall OSuite::ZAtomBase::GenerateClassId()
{
  return (unsigned int)nId++;
}

