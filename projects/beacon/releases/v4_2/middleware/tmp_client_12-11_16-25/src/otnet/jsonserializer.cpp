// File Line: 9
// RVA: 0xED0558
void __fastcall OSuite::ZDateTime::ZDateTime(OSuite::ZDateTime *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
}

// File Line: 18
// RVA: 0xED0568
void __fastcall OSuite::ZJsonSerializer::Serialize(
        OSuite::ZJsonSerializer *this,
        OSuite::ZUtf8Buffer *pDest,
        OSuite::ZJsonDocument *doc)
{
  if ( pDest )
    OSuite::ZJsonSerializer::SerializeObject(this, pDest, doc);
}

// File Line: 30
// RVA: 0xED0684
char __fastcall OSuite::ZJsonSerializer::SerializeObject(
        OSuite::ZJsonSerializer *this,
        OSuite::ZUtf8Buffer *buf,
        OSuite::ZJsonObject *obj)
{
  char v6; // r14
  OSuite::ZObjectVtbl *v7; // rsi
  OSuite::ZObjectVtbl *vfptr; // rdi
  OSuite::ZString sName; // [rsp+20h] [rbp-79h] BYREF
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+40h] [rbp-59h] BYREF

  if ( obj->m_Pairs.m_nCount )
  {
    OSuite::ZUtf8Buffer::Append(buf, "{");
    v6 = 0;
    OSuite::ZString::ZString(&sName, "__metadata");
    v7 = OSuite::ZJsonObject::Value(obj, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v7 )
    {
      v6 = 1;
      OSuite::ZUtf8Buffer::Append(buf, "\"");
      OSuite::ZUtf8Buffer::Append(buf, "__metadata");
      OSuite::ZUtf8Buffer::Append(buf, "\"");
      OSuite::ZUtf8Buffer::Append(buf, ": ");
      if ( !OSuite::ZJsonSerializer::SerializeValue(this, buf, (OSuite::ZJsonValue *)v7) )
        return 0;
    }
    result.m_pMap = 0i64;
    result.m_iterator.m_iterator.m_pList = 0i64;
    result.m_iterator.m_iterator.m_pElement = 0i64;
    result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&obj->m_Pairs,
      &result);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    {
      vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
      if ( vfptr != v7 )
      {
        if ( v6 == 1 )
          OSuite::ZUtf8Buffer::Append(buf, ",");
        v6 = 1;
        OSuite::ZUtf8Buffer::Append(buf, "\"");
        OSuite::ZUtf8Buffer::Append(buf, (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft);
        OSuite::ZUtf8Buffer::Append(buf, "\"");
        OSuite::ZUtf8Buffer::Append(buf, ": ");
        if ( !OSuite::ZJsonSerializer::SerializeValue(this, buf, (OSuite::ZJsonValue *)vfptr) )
        {
          result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
          result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
          result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
          result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
          result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
          if ( result.m_iterator.m_iterator.m_parents.m_pList )
            result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
              result.m_iterator.m_iterator.m_parents.m_pList,
              1u);
          return 0;
        }
      }
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZUtf8Buffer::Append(buf, "}");
  }
  return 1;
}

// File Line: 85
// RVA: 0xED057C
char __fastcall OSuite::ZJsonSerializer::SerializeArray(
        OSuite::ZJsonSerializer *this,
        OSuite::ZUtf8Buffer *buf,
        OSuite::TList<OSuite::ZJsonValue *> *array)
{
  char v6; // r14
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 v9; // rbp
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+20h] [rbp-48h] BYREF

  OSuite::ZUtf8Buffer::Append(buf, "[");
  v11.m_pListBase = 0i64;
  v6 = 0;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, array);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
    {
      OSuite::ZUtf8Buffer::Append(buf, "]");
      return 1;
    }
    if ( v6 == 1 )
      OSuite::ZUtf8Buffer::Append(buf, ",");
    v6 = 1;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    m_nIndex = v11.m_nIndex;
    m_pListBase = v11.m_pListBase;
    v9 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v9;
    if ( !OSuite::ZJsonSerializer::SerializeValue(
            this,
            buf,
            *(OSuite::ZJsonValue **)(m_pListBase[1].m_nSize + 8 * m_nIndex)) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v11);
  }
  return 0;
}

// File Line: 110
// RVA: 0xED08DC
char __fastcall OSuite::ZJsonSerializer::SerializeValue(
        OSuite::ZJsonSerializer *this,
        OSuite::ZUtf8Buffer *buf,
        OSuite::ZJsonValue *value)
{
  OSuite::ZJsonValue::ZJsonValueType m_Type; // r9d
  __int32 v5; // r9d
  OSuite::ZJsonObject *m_object; // r8
  OSuite::ZError *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-28h] BYREF

  m_Type = value->m_Type;
  if ( m_Type == JSONTYPE_STRING )
  {
    v9 = OSuite::ZJsonValue::GetForSerialization(value, &result);
    OSuite::ZUtf8Buffer::Append(buf, v9);
    OSuite::ZString::~ZString(&result);
    return 1;
  }
  v5 = m_Type - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
      return OSuite::ZJsonSerializer::SerializeArray(this, buf, &value->m_array);
    return 1;
  }
  m_object = value->m_object;
  if ( m_object )
    return OSuite::ZJsonSerializer::SerializeObject(this, buf, m_object);
  v8 = OSuite::TSingleton<OSuite::ZError>::Object();
  OSuite::ZError::SetThreadLastError(v8, ZERROR_SERIALIZATION_FAILED, 1);
  return 0;
}

