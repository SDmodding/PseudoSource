// File Line: 9
// RVA: 0xED0558
void __fastcall OSuite::ZDateTime::ZDateTime(OSuite::ZDateTime *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
}

// File Line: 18
// RVA: 0xED0568
void __fastcall OSuite::ZJsonSerializer::Serialize(OSuite::ZJsonSerializer *this, OSuite::ZUtf8Buffer *pDest, OSuite::ZJsonDocument *doc)
{
  if ( pDest )
    OSuite::ZJsonSerializer::SerializeObject(this, pDest, (OSuite::ZJsonObject *)&doc->vfptr);
}

// File Line: 30
// RVA: 0xED0684
char __fastcall OSuite::ZJsonSerializer::SerializeObject(OSuite::ZJsonSerializer *this, OSuite::ZUtf8Buffer *buf, OSuite::ZJsonObject *obj)
{
  OSuite::ZJsonObject *v3; // rdi
  OSuite::ZUtf8Buffer *v4; // rbx
  OSuite::ZJsonSerializer *v5; // r15
  char v6; // r14
  OSuite::ZObjectVtbl *v7; // rsi
  OSuite::ZObjectVtbl *v9; // rdi
  OSuite::ZString sName; // [rsp+20h] [rbp-79h]
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+40h] [rbp-59h]

  v3 = obj;
  v4 = buf;
  v5 = this;
  if ( obj->m_Pairs.m_nCount )
  {
    OSuite::ZUtf8Buffer::Append(buf, "{");
    v6 = 0;
    OSuite::ZString::ZString(&sName, "__metadata");
    v7 = OSuite::ZJsonObject::Value(v3, &sName);
    OSuite::ZString::~ZString(&sName);
    if ( v7 )
    {
      v6 = 1;
      OSuite::ZUtf8Buffer::Append(v4, "\"");
      OSuite::ZUtf8Buffer::Append(v4, "__metadata");
      OSuite::ZUtf8Buffer::Append(v4, "\"");
      OSuite::ZUtf8Buffer::Append(v4, ": ");
      if ( !OSuite::ZJsonSerializer::SerializeValue(v5, v4, (OSuite::ZJsonValue *)v7) )
        return 0;
    }
    result.m_pMap = 0i64;
    result.m_iterator.m_iterator.m_pList = 0i64;
    result.m_iterator.m_iterator.m_pElement = 0i64;
    result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
    OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
      (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&v3->m_Pairs,
      &result);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    {
      v9 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
      if ( v9 != v7 )
      {
        if ( v6 == 1 )
          OSuite::ZUtf8Buffer::Append(v4, ",");
        v6 = 1;
        OSuite::ZUtf8Buffer::Append(v4, "\"");
        OSuite::ZUtf8Buffer::Append(v4, (OSuite::ZString *)&result.m_iterator.m_iterator.m_pElement[1].m_pLeft);
        OSuite::ZUtf8Buffer::Append(v4, "\"");
        OSuite::ZUtf8Buffer::Append(v4, ": ");
        if ( !OSuite::ZJsonSerializer::SerializeValue(v5, v4, (OSuite::ZJsonValue *)v9) )
        {
          result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
          result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
          result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
          result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
          result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
          if ( result.m_iterator.m_iterator.m_parents.m_pList )
            result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
              (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
              1u);
          return 0;
        }
      }
      OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
    }
    result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
    result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZUtf8Buffer::Append(v4, "}");
  }
  return 1;
}

// File Line: 85
// RVA: 0xED057C
char __fastcall OSuite::ZJsonSerializer::SerializeArray(OSuite::ZJsonSerializer *this, OSuite::ZUtf8Buffer *buf, OSuite::TList<OSuite::ZJsonValue *> *array)
{
  OSuite::ZUtf8Buffer *v3; // rdi
  OSuite::ZJsonSerializer *v4; // r15
  OSuite::TList<OSuite::ZJsonValue *> *v5; // rbx
  char v6; // r14
  unsigned __int64 v7; // rsi
  OSuite::ZListBase *v8; // rbx
  unsigned __int64 v9; // rbp
  OSuite::ZListBase::ZListIteratorBase v11; // [rsp+20h] [rbp-48h]

  v3 = buf;
  v4 = this;
  v5 = array;
  OSuite::ZUtf8Buffer::Append(buf, "[");
  v11.m_pListBase = 0i64;
  v6 = 0;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v11, (OSuite::ZListBase *)&v5->vfptr);
  v11.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( 1 )
  {
    if ( OSuite::ZListBase::ZListIteratorBase::AtEnd(&v11) )
    {
      OSuite::ZUtf8Buffer::Append(v3, "]");
      return 1;
    }
    if ( v6 == 1 )
      OSuite::ZUtf8Buffer::Append(v3, ",");
    v6 = 1;
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11.m_pListBase);
    v7 = v11.m_nIndex;
    v8 = v11.m_pListBase;
    v9 = v11.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v11.m_pListBase,
      v11.m_nIndex + 1);
    if ( v7 >= v8->m_nTop )
      v8->m_nTop = v9;
    if ( !OSuite::ZJsonSerializer::SerializeValue(v4, v3, *(OSuite::ZJsonValue **)(v8[1].m_nSize + 8 * v7)) )
      break;
    OSuite::ZListBase::ZListIteratorBase::Next(&v11);
  }
  return 0;
}

// File Line: 110
// RVA: 0xED08DC
char __fastcall OSuite::ZJsonSerializer::SerializeValue(OSuite::ZJsonSerializer *this, OSuite::ZUtf8Buffer *buf, OSuite::ZJsonValue *value)
{
  OSuite::ZJsonValue::ZJsonValueType v3; // er9
  OSuite::ZUtf8Buffer *v4; // rbx
  int v5; // er9
  OSuite::ZJsonObject *v7; // r8
  OSuite::ZError *v8; // rax
  OSuite::ZString *v9; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-28h]

  v3 = value->m_Type;
  v4 = buf;
  if ( v3 == JSONTYPE_STRING )
  {
    v9 = OSuite::ZJsonValue::GetForSerialization(value, &result);
    OSuite::ZUtf8Buffer::Append(v4, v9);
    OSuite::ZString::~ZString(&result);
    return 1;
  }
  v5 = v3 - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
      return OSuite::ZJsonSerializer::SerializeArray(this, buf, &value->m_array);
    return 1;
  }
  v7 = value->m_object;
  if ( v7 )
    return OSuite::ZJsonSerializer::SerializeObject(this, buf, v7);
  v8 = OSuite::TSingleton<OSuite::ZError>::Object();
  OSuite::ZError::SetThreadLastError(v8, ZERROR_SERIALIZATION_FAILED, 1);
  return 0;
}

