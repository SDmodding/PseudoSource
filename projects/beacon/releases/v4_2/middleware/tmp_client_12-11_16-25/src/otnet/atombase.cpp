// File Line: 15
// RVA: 0x15D8AF8
__int64 dynamic_initializer_for__OSuite::ZAtomBase::s_nClassId__()
{
  OSuite::ZAtomBase::s_nClassId = nId;
  return (unsigned int)++nId;
}

// File Line: 46
// RVA: 0xED218C
void __fastcall OSuite::ZAtomBase::ZAtomBase(OSuite::ZAtomBase *this)
{
  OSuite::ZString::ZString(&this->m_sAuthorName);
  OSuite::ZString::ZString(&this->m_sIdentifier);
  OSuite::ZString::ZString(&this->m_sTitle);
  OSuite::ZString::ZString(&this->m_sEditURL);
  OSuite::ZString::ZString(&this->m_sBaseURL);
  this->m_bHasValidSource = 0;
}

// File Line: 53
// RVA: 0xED2134
void __fastcall OSuite::ZAtomBase::ZAtomBase(OSuite::ZAtomBase *this, OSuite::ZString *baseUrl)
{
  OSuite::ZString::ZString(&this->m_sAuthorName);
  OSuite::ZString::ZString(&this->m_sIdentifier);
  OSuite::ZString::ZString(&this->m_sTitle);
  OSuite::ZString::ZString(&this->m_sEditURL);
  OSuite::ZString::ZString(&this->m_sBaseURL, baseUrl);
  this->m_bHasValidSource = 0;
}

// File Line: 58
// RVA: 0xED21D4
void __fastcall OSuite::ZAtomBase::~ZAtomBase(OSuite::ZAtomBase *this)
{
  OSuite::ZString::~ZString(&this->m_sBaseURL);
  OSuite::ZString::~ZString(&this->m_sEditURL);
  OSuite::ZString::~ZString(&this->m_sTitle);
  OSuite::ZString::~ZString(&this->m_sIdentifier);
  OSuite::ZString::~ZString(&this->m_sAuthorName);
}

// File Line: 119
// RVA: 0xED221C
OSuite::ZUrl *__fastcall OSuite::ZAtomBase::EditURL(OSuite::ZAtomBase *this, OSuite::ZUrl *result)
{
  if ( OSuite::ZString::operator bool(&this->m_sEditURL) )
    OSuite::ZAtomBase::GetUrlFromString(this, result, &this->m_sEditURL);
  else
    OSuite::ZUrl::ZUrl(result);
  return result;
}

// File Line: 148
// RVA: 0xED231C
bool __fastcall OSuite::ZAtomBase::HasValidSource(OSuite::ZAtomBase *this)
{
  return this->m_bHasValidSource;
}

// File Line: 155
// RVA: 0xED2280
OSuite::ZUrl *__fastcall OSuite::ZAtomBase::GetUrlFromString(
        OSuite::ZAtomBase *this,
        OSuite::ZUrl *result,
        OSuite::ZString *sUrlString)
{
  bool v6; // bl
  OSuite::ZString *v7; // rax
  OSuite::ZString InternalString; // [rsp+20h] [rbp-28h] BYREF

  OSuite::ZString::ZString(&InternalString, "://");
  v6 = OSuite::ZString::IndexOf(sUrlString, &InternalString, 0i64) < 0;
  OSuite::ZString::~ZString(&InternalString);
  if ( v6 )
  {
    v7 = OSuite::ZString::operator+(&this->m_sBaseURL, &InternalString, sUrlString);
    OSuite::ZUrl::Parse(result, v7);
    OSuite::ZString::~ZString(&InternalString);
  }
  else
  {
    OSuite::ZUrl::Parse(result, sUrlString);
  }
  return result;
}

// File Line: 174
// RVA: 0xED2210
bool __fastcall OSuite::ZAtomBase::ClassMatch(OSuite::ZAtomBase *this, int nClassId)
{
  return OSuite::ZAtomBase::s_nClassId == nClassId;
}

// File Line: 181
// RVA: 0xED2324
// attributes: thunk
void __fastcall OSuite::ZAtomBase::Parse(OSuite::ZAtomBase *pAtom, OSuite::ZJsonObject *pJson)
{
  OSuite::ZAtomBase::ParseJson(pAtom, pJson);
}

// File Line: 188
// RVA: 0xED232C
void __fastcall OSuite::ZAtomBase::ParseJson(OSuite::ZAtomBase *this, OSuite::ZJsonObject *pJson)
{
  OSuite::ZError *v4; // rax
  OSuite::ZError *v5; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-E0h] BYREF
  void **v7; // [rsp+A0h] [rbp-60h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v8; // [rsp+A8h] [rbp-58h] BYREF

  v4 = OSuite::TSingleton<OSuite::ZError>::Object();
  if ( OSuite::ZError::GetThreadLastError(v4)->m_First != ZERROR_PARSING_FAILED )
  {
    v8.m_pMap = 0i64;
    v8.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    *(_OWORD *)&v8.m_iterator.m_iterator.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&pJson->m_Pairs,
      &result);
    v8.m_pMap = result.m_pMap;
    v8.m_iCurrentHash = result.m_iCurrentHash;
    v7 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v8.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v8.m_iterator.m_iterator, &result.m_iterator.m_iterator);
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v8.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v8.m_iterator.m_iterator) )
    {
      if ( v8.m_iterator.m_iterator.m_pElement[2].vfptr )
      {
        this->vfptr[3].__vecDelDtor(this, (unsigned int)&v8.m_iterator.m_iterator.m_pElement[1].m_pLeft);
        v5 = OSuite::TSingleton<OSuite::ZError>::Object();
        if ( OSuite::ZError::GetThreadLastError(v5)->m_First == ZERROR_PARSING_FAILED )
        {
          this->m_bHasValidSource = 0;
          break;
        }
      }
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v8);
    }
    v8.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v8.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v8.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v7 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v8.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v8.m_iterator.m_iterator.m_parents.m_pList )
      v8.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v8.m_iterator.m_iterator.m_parents.m_pList, 1u);
  }
}

// File Line: 216
// RVA: 0xED226C
__int64 __fastcall OSuite::ZAtomBase::GenerateClassId()
{
  return (unsigned int)nId++;
}

