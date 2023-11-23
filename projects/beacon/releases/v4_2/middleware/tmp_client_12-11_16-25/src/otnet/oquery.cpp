// File Line: 16
// RVA: 0xECC2E4
void __fastcall OSuite::ZOQuery::ZOQuery(OSuite::ZOQuery *this)
{
  this->m_eMode = QM_NONE;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOQuery::`vftable;
  OSuite::ZString::ZString(&this->m_entityName);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&this->m_queryMap, 0x10ui64);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(
    &this->m_functionParameters,
    0x10ui64);
}

// File Line: 21
// RVA: 0xECC32C
void __fastcall OSuite::ZOQuery::~ZOQuery(OSuite::ZOQuery *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOQuery::`vftable;
  this->m_functionParameters.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  m_pLists = this->m_functionParameters.m_pLists;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
  v3 = this->m_queryMap.m_pLists;
  this->m_queryMap.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  if ( v3 )
  {
    if ( LODWORD(v3[-1].m_Comparer.vfptr) )
      v3->vfptr->__vecDelDtor(v3, 3u);
    else
      Illusion::ShaderParam::operator delete(&v3[-1].m_Comparer.OSuite::ZObject);
  }
  OSuite::ZString::~ZString(&this->m_entityName);
}

// File Line: 67
// RVA: 0xECC464
OSuite::ZOQuery *__fastcall OSuite::ZOQuery::Filter(OSuite::ZOQuery *this, const char *filterString)
{
  OSuite::ZString key; // [rsp+20h] [rbp-48h] BYREF
  OSuite::ZString result; // [rsp+38h] [rbp-30h] BYREF

  if ( filterString )
  {
    result.m_pString = 0i64;
    OSuite::ZOQuery::SanitizeString(this, &result, filterString, 1);
    OSuite::ZString::ZString(&key, "$filter");
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(&this->m_queryMap, &key, &result);
    OSuite::ZString::~ZString(&key);
    OSuite::ZString::~ZString(&result);
  }
  return this;
}

// File Line: 82
// RVA: 0xECC420
OSuite::ZOQuery *__fastcall OSuite::ZOQuery::Filter(OSuite::ZOQuery *this, OSuite::ZOFilter *filterExpression)
{
  OSuite::ZString *v3; // rax
  const char *v4; // rax
  OSuite::ZOQuery *v5; // rbx
  OSuite::ZString result; // [rsp+20h] [rbp-28h] BYREF

  v3 = OSuite::ZOFilter::ToString(filterExpression, &result);
  v4 = OSuite::ZString::c_str(v3);
  v5 = OSuite::ZOQuery::Filter(this, v4);
  OSuite::ZString::~ZString(&result);
  return v5;
}

// File Line: 182
// RVA: 0xECC3E0
OSuite::ZOQuery *__fastcall OSuite::ZOQuery::EntitySet(OSuite::ZOQuery *this, const char *entitySetName)
{
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  if ( entitySetName )
  {
    OSuite::ZString::ZString(&that, entitySetName);
    OSuite::ZString::operator=(&this->m_entityName, &that);
    OSuite::ZString::~ZString(&that);
    this->m_eMode = QM_ENTITYSET;
  }
  return this;
}

// File Line: 199
// RVA: 0xECC6D4
OSuite::ZOQuery *__fastcall OSuite::ZOQuery::ServiceOperation(
        OSuite::ZOQuery *this,
        const char *serviceOperation,
        OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *params)
{
  OSuite::ZString *v5; // rax
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator *v6; // rax
  OSuite::ZString v8; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+38h] [rbp-C8h] BYREF
  void **v10; // [rsp+C0h] [rbp-40h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator v11; // [rsp+C8h] [rbp-38h] BYREF

  if ( serviceOperation )
  {
    this->m_eMode = QM_FUNCTIONIMPORT;
    OSuite::ZString::ZString(&v8, serviceOperation);
    OSuite::ZString::operator=(&this->m_entityName, v5);
    OSuite::ZString::~ZString(&v8);
    v11.m_pMap = 0i64;
    v11.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    *(_OWORD *)&v11.m_iterator.m_iterator.m_pList = 0i64;
    v6 = OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(params, &result);
    v10 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v11.m_pMap = v6->m_pMap;
    v11.m_iCurrentHash = v6->m_iCurrentHash;
    v11.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v11.m_iterator.m_iterator, &v6->m_iterator.m_iterator);
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v11.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v11.m_iterator.m_iterator) )
    {
      OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(
        &this->m_functionParameters,
        (OSuite::ZString *)&v11.m_iterator.m_iterator.m_pElement[1].m_pLeft,
        (OSuite::ZString *)&v11.m_iterator.m_iterator.m_pElement[2]);
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&v11);
    }
    v10 = &OSuite::TConstIterator<OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::ZIterator,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::ZString>::`vftable;
    v11.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    v11.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v11.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v11.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v11.m_iterator.m_iterator.m_parents.m_pList )
      v11.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(v11.m_iterator.m_iterator.m_parents.m_pList, 1u);
  }
  return this;
}

// File Line: 223
// RVA: 0xECC4E8
OSuite::ZString *__fastcall OSuite::ZOQuery::SanitizeString(
        OSuite::ZOQuery *this,
        OSuite::ZString *result,
        const char *inputString,
        bool keepSingleQuotes)
{
  size_t v7; // rbx
  size_t v8; // rsi
  char v9; // dl
  const char *v10; // rdx
  OSuite::ZStringBuilder v12; // [rsp+20h] [rbp-40h] BYREF

  v12.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v12, 0x100ui64);
  v7 = 0i64;
  v8 = strlen(inputString);
  if ( v8 )
  {
    do
    {
      v9 = inputString[v7];
      switch ( v9 )
      {
        case 32:
          v10 = "%20";
          break;
        case 33:
          v10 = "%21";
          break;
        case 42:
          v10 = "%2A";
          break;
        case 39:
          if ( keepSingleQuotes )
            goto LABEL_44;
          v10 = "%27%27";
          break;
        case 40:
          v10 = "%28";
          break;
        case 41:
          v10 = "%29";
          break;
        case 59:
          v10 = "%3B";
          break;
        case 58:
          v10 = "%3A";
          break;
        case 64:
          v10 = "%40";
          break;
        case 38:
          v10 = "%26";
          break;
        case 61:
          v10 = "%3D";
          break;
        case 43:
          v10 = "%2B";
          break;
        case 36:
          v10 = "%24";
          break;
        case 44:
          v10 = "%2C";
          break;
        case 47:
          v10 = "%2F";
          break;
        case 63:
          v10 = "%3F";
          break;
        case 91:
          v10 = "%5B";
          break;
        case 93:
          v10 = "%5D";
          break;
        case 10:
          v10 = "%0A";
          break;
        case 13:
          v10 = "%0D";
          break;
        default:
LABEL_44:
          OSuite::ZStringBuilder::Append(&v12, v9);
          goto LABEL_45;
      }
      OSuite::ZStringBuilder::Append(&v12, v10);
LABEL_45:
      ++v7;
    }
    while ( v7 < v8 );
  }
  OSuite::ZStringBuilder::ToString(&v12, result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v12);
  return result;
}

