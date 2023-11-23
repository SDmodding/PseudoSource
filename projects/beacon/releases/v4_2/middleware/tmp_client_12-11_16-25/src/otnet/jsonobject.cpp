// File Line: 10
// RVA: 0xECFD60
void __fastcall OSuite::ZJsonValue::ZJsonValue(OSuite::ZJsonValue *this)
{
  OSuite::ZObject *v2; // rdx
  OSuite::ZJsonValue **v3; // rax

  this->m_Type = JSONTYPE_STRING;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable;
  OSuite::ZString::ZString(&this->m_literal);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_array, v2);
  this->m_array.m_pList = 0i64;
  this->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v3 = (OSuite::ZJsonValue **)OSuite::ZObject::malloc(&this->m_array, 0x80ui64, 0i64);
  this->m_array.m_nTop = 0i64;
  this->m_array.m_nSize = 16i64;
  this->m_array.m_pList = v3;
  this->m_object = 0i64;
  this->m_quotes = 1;
}

// File Line: 16
// RVA: 0xECFCCC
void __fastcall OSuite::ZJsonValue::ZJsonValue(OSuite::ZJsonValue *this, OSuite::ZJsonObject *pElement)
{
  OSuite::ZObject *v4; // rdx
  OSuite::ZJsonValue **v5; // rax

  this->m_Type = JSONTYPE_OBJECT;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable;
  OSuite::ZString::ZString(&this->m_literal);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_array, v4);
  this->m_array.m_pList = 0i64;
  this->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v5 = (OSuite::ZJsonValue **)OSuite::ZObject::malloc(&this->m_array, 0x80ui64, 0i64);
  this->m_array.m_nTop = 0i64;
  this->m_array.m_nSize = 16i64;
  this->m_array.m_pList = v5;
  this->m_object = pElement;
  this->m_quotes = 0;
}

// File Line: 23
// RVA: 0xECFC3C
void __fastcall OSuite::ZJsonValue::ZJsonValue(OSuite::ZJsonValue *this, OSuite::ZString *sValue, bool hasQuotes)
{
  OSuite::ZObject *v5; // rdx
  OSuite::ZJsonValue **v6; // rax

  this->m_Type = JSONTYPE_STRING;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable;
  OSuite::ZString::ZString(&this->m_literal, sValue);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_array, v5);
  this->m_array.m_pList = 0i64;
  this->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v6 = (OSuite::ZJsonValue **)OSuite::ZObject::malloc(&this->m_array, 0x80ui64, 0i64);
  this->m_array.m_nTop = 0i64;
  this->m_array.m_nSize = 16i64;
  this->m_array.m_pList = v6;
  this->m_object = 0i64;
  this->m_quotes = hasQuotes;
}

// File Line: 26
// RVA: 0xECFE38
void __fastcall OSuite::ZJsonValue::~ZJsonValue(OSuite::ZJsonValue *this)
{
  OSuite::ZJsonValue **m_pList; // rdx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable;
  OSuite::ZJsonValue::Clear(this);
  m_pList = this->m_array.m_pList;
  this->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_array, m_pList);
  OSuite::ZString::~ZString(&this->m_literal);
}

// File Line: 71
// RVA: 0xECFF18
void __fastcall OSuite::ZJsonValue::Add(OSuite::ZJsonValue *this, OSuite::ZJsonValue *pValue)
{
  if ( this->m_Type != JSONTYPE_ARRAY )
  {
    OSuite::ZJsonValue::Clear(this);
    this->m_Type = JSONTYPE_ARRAY;
  }
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_array,
    this->m_array.m_nTop + 1);
  this->m_array.m_pList[this->m_array.m_nTop++] = pValue;
}

// File Line: 81
// RVA: 0xED004C
void __fastcall OSuite::ZJsonValue::Clear(OSuite::ZJsonValue *this)
{
  unsigned __int64 m_nIndex; // rsi
  OSuite::ZListBase *m_pListBase; // rdi
  unsigned __int64 v4; // r14
  void (__fastcall ***v5)(_QWORD, __int64); // rcx
  OSuite::ZJsonObject *m_object; // rcx
  OSuite::ZString that; // [rsp+20h] [rbp-40h] BYREF
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+38h] [rbp-28h] BYREF

  v8.m_pListBase = 0i64;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, &this->m_array);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    m_nIndex = v8.m_nIndex;
    m_pListBase = v8.m_pListBase;
    v4 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( m_nIndex >= m_pListBase->m_nTop )
      m_pListBase->m_nTop = v4;
    v5 = *(void (__fastcall ****)(_QWORD, __int64))(m_pListBase[1].m_nSize + 8 * m_nIndex);
    if ( v5 )
      (**v5)(v5, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  m_object = this->m_object;
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable;
  if ( m_object )
  {
    m_object->vfptr->__vecDelDtor(m_object, 1u);
    this->m_object = 0i64;
  }
  OSuite::ZString::ZString(&that, &customCaption);
  OSuite::ZString::operator=(&this->m_literal, &that);
  OSuite::ZString::~ZString(&that);
}

// File Line: 95
// RVA: 0xED0334
OSuite::ZString *__fastcall OSuite::ZJsonValue::GetForSerialization(OSuite::ZJsonValue *this, OSuite::ZString *result)
{
  OSuite::ZString *v3; // rax
  OSuite::ZString resulta; // [rsp+20h] [rbp-28h] BYREF

  if ( this->m_quotes )
  {
    v3 = OSuite::operator+(&resulta, "\"", &this->m_literal);
    OSuite::ZString::operator+(v3, result, "\"");
    OSuite::ZString::~ZString(&resulta);
  }
  else
  {
    OSuite::ZString::ZString(result, &this->m_literal);
  }
  return result;
}

// File Line: 115
// RVA: 0xECFC10
void __fastcall OSuite::ZJsonObject::ZJsonObject(OSuite::ZJsonObject *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonObject::`vftable;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs,
    0x10ui64);
}

// File Line: 140
// RVA: 0xECFDE4
void __fastcall OSuite::ZJsonObject::~ZJsonObject(OSuite::ZJsonObject *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonObject::`vftable;
  OSuite::ZJsonObject::Clear(this);
  m_pLists = this->m_Pairs.m_pLists;
  this->m_Pairs.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      Illusion::ShaderParam::operator delete(&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
}

// File Line: 145
// RVA: 0xECFF68
void __fastcall OSuite::ZJsonObject::Clear(OSuite::ZJsonObject *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *> *p_m_Pairs; // rbx
  OSuite::ZObjectVtbl *vfptr; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  p_m_Pairs = &this->m_Pairs;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_Pairs,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( vfptr )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
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
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear((OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)p_m_Pairs);
}

// File Line: 154
// RVA: 0xED038C
OSuite::ZObjectVtbl *__fastcall OSuite::ZJsonObject::Value(OSuite::ZJsonObject *this, OSuite::ZString *sName)
{
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+20h] [rbp-39h] BYREF

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs,
    &result,
    sName);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    vfptr = 0i64;
  else
    vfptr = result.m_iterator.m_iterator.m_pElement[2].vfptr;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  return vfptr;
}

// File Line: 164
// RVA: 0xECFEE0
void __fastcall OSuite::ZJsonObject::Add(
        OSuite::ZJsonObject *this,
        OSuite::ZString *sName,
        OSuite::ZUsageTracker *vValue)
{
  OSuite::ZUsageTracker *value; // [rsp+20h] [rbp-18h] BYREF

  value = vValue;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::Insert(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs,
    sName,
    &value);
}

