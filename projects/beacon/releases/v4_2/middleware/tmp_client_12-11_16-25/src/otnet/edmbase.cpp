// File Line: 15
// RVA: 0xED2714
void __fastcall OSuite::ZOEdmBase::ZOEdmBase(OSuite::ZOEdmBase *this)
{
  OSuite::ZString::ZString(&this->m_Name);
  OSuite::ZString::ZString(&this->m_Schema);
}

// File Line: 21
// RVA: 0xED26E0
void __fastcall OSuite::ZOEdmBase::ZOEdmBase(OSuite::ZOEdmBase *this, OSuite::ZString *schema)
{
  OSuite::ZString::ZString(&this->m_Name);
  OSuite::ZString::ZString(&this->m_Schema, schema);
}

// File Line: 28
// RVA: 0xED26A8
void __fastcall OSuite::ZOEdmBase::ZOEdmBase(OSuite::ZOEdmBase *this, OSuite::ZString *schema, OSuite::ZString *name)
{
  OSuite::ZString::ZString(&this->m_Name, name);
  OSuite::ZString::ZString(&this->m_Schema, schema);
}

// File Line: 33
// RVA: 0xED2738
void __fastcall OSuite::ZOEdmBase::~ZOEdmBase(OSuite::ZOEdmBase *this)
{
  OSuite::ZString::~ZString(&this->m_Schema);
  OSuite::ZString::~ZString(&this->m_Name);
}

// File Line: 38
// RVA: 0xED2758
OSuite::ZString *__fastcall OSuite::ZOEdmBase::FullyQualifiedName(OSuite::ZOEdmBase *this, OSuite::ZString *result)
{
  OSuite::ZStringBuilder v5; // [rsp+20h] [rbp-48h] BYREF

  v5.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v5, 0x40ui64);
  if ( OSuite::ZString::operator bool(&this->m_Schema) )
  {
    OSuite::ZStringBuilder::Append(&v5, &this->m_Schema);
    OSuite::ZStringBuilder::Append(&v5, ".");
  }
  OSuite::ZStringBuilder::Append(&v5, &this->m_Name);
  OSuite::ZStringBuilder::ToString(&v5, result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v5);
  return result;
}

// File Line: 51
// RVA: 0xED2804
void __fastcall OSuite::ZOEdmBase::ParseJson(OSuite::ZOEdmBase *this, OSuite::ZJsonObject *pJson)
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
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v8.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v8.m_iterator.m_iterator) )
    {
      if ( v8.m_iterator.m_iterator.m_pElement[2].vfptr )
      {
        this->vfptr[1].__vecDelDtor(this, (unsigned int)&v8.m_iterator.m_iterator.m_pElement[1].m_pLeft);
        v5 = OSuite::TSingleton<OSuite::ZError>::Object();
        if ( OSuite::ZError::GetThreadLastError(v5)->m_First == ZERROR_PARSING_FAILED )
          break;
      }
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v8);
    }
    v8.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v8.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    v8.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v8.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v7 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    if ( v8.m_iterator.m_iterator.m_parents.m_pList )
      v8.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v8.m_iterator.m_iterator.m_parents.m_pList, 1u);
  }
}

