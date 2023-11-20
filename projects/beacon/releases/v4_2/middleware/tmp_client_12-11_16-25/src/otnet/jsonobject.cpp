// File Line: 10
// RVA: 0xECFD60
void __fastcall OSuite::ZJsonValue::ZJsonValue(OSuite::ZJsonValue *this)
{
  OSuite::ZJsonValue *v1; // rdi
  OSuite::ZObject *v2; // rdx
  OSuite::ZJsonValue **v3; // rax

  this->m_Type = 0;
  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable';
  OSuite::ZString::ZString(&this->m_literal);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v1->m_array.vfptr, v2);
  v1->m_array.m_pList = 0i64;
  v1->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v1->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v3 = (OSuite::ZJsonValue **)OSuite::ZObject::malloc((OSuite::ZObject *)&v1->m_array.vfptr, 0x80ui64, 0i64);
  v1->m_array.m_nTop = 0i64;
  v1->m_array.m_nSize = 16i64;
  v1->m_array.m_pList = v3;
  v1->m_object = 0i64;
  v1->m_quotes = 1;
}

// File Line: 16
// RVA: 0xECFCCC
void __fastcall OSuite::ZJsonValue::ZJsonValue(OSuite::ZJsonValue *this, OSuite::ZJsonObject *pElement)
{
  OSuite::ZJsonValue *v2; // rsi
  OSuite::ZJsonObject *v3; // rdi
  OSuite::ZObject *v4; // rdx
  OSuite::ZJsonValue **v5; // rax

  v2 = this;
  this->m_Type = 1;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable';
  v3 = pElement;
  OSuite::ZString::ZString(&this->m_literal);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v2->m_array.vfptr, v4);
  v2->m_array.m_pList = 0i64;
  v2->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v5 = (OSuite::ZJsonValue **)OSuite::ZObject::malloc((OSuite::ZObject *)&v2->m_array.vfptr, 0x80ui64, 0i64);
  v2->m_array.m_nTop = 0i64;
  v2->m_array.m_nSize = 16i64;
  v2->m_array.m_pList = v5;
  v2->m_object = v3;
  v2->m_quotes = 0;
}

// File Line: 23
// RVA: 0xECFC3C
void __fastcall OSuite::ZJsonValue::ZJsonValue(OSuite::ZJsonValue *this, OSuite::ZString *sValue, bool hasQuotes)
{
  OSuite::ZJsonValue *v3; // rdi
  bool v4; // si
  OSuite::ZObject *v5; // rdx
  OSuite::ZJsonValue **v6; // rax

  this->m_Type = 0;
  v3 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable';
  v4 = hasQuotes;
  OSuite::ZString::ZString(&this->m_literal, sValue);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v3->m_array.vfptr, v5);
  v3->m_array.m_pList = 0i64;
  v3->m_array.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v3->m_array.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v6 = (OSuite::ZJsonValue **)OSuite::ZObject::malloc((OSuite::ZObject *)&v3->m_array.vfptr, 0x80ui64, 0i64);
  v3->m_array.m_nTop = 0i64;
  v3->m_array.m_nSize = 16i64;
  v3->m_array.m_pList = v6;
  v3->m_object = 0i64;
  v3->m_quotes = v4;
}

// File Line: 26
// RVA: 0xECFE38
void __fastcall OSuite::ZJsonValue::~ZJsonValue(OSuite::ZJsonValue *this)
{
  OSuite::ZJsonValue *v1; // rbx
  OSuite::TList<OSuite::ZJsonValue *> *v2; // rcx
  OSuite::ZJsonValue **v3; // rdx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonValue::`vftable';
  OSuite::ZJsonValue::Clear(this);
  v2 = &v1->m_array;
  v3 = v1->m_array.m_pList;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_array.vfptr, v3);
  OSuite::ZString::~ZString(&v1->m_literal);
}

// File Line: 71
// RVA: 0xECFF18
void __fastcall OSuite::ZJsonValue::Add(OSuite::ZJsonValue *this, OSuite::ZJsonValue *pValue)
{
  OSuite::ZJsonValue *v2; // rdi
  OSuite::ZJsonValue *v3; // rbx

  v2 = pValue;
  v3 = this;
  if ( this->m_Type != 2 )
  {
    OSuite::ZJsonValue::Clear(this);
    v3->m_Type = 2;
  }
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_array,
    v3->m_array.m_nTop + 1);
  v3->m_array.m_pList[v3->m_array.m_nTop++] = v2;
}

// File Line: 81
// RVA: 0xED004C
void __fastcall OSuite::ZJsonValue::Clear(OSuite::ZJsonValue *this)
{
  OSuite::ZJsonValue *v1; // rbx
  unsigned __int64 v2; // rsi
  OSuite::ZListBase *v3; // rdi
  unsigned __int64 v4; // r14
  void (__fastcall ***v5)(_QWORD, signed __int64); // rcx
  OSuite::ZJsonObject *v6; // rcx
  OSuite::ZString that; // [rsp+20h] [rbp-40h]
  OSuite::ZListBase::ZListIteratorBase v8; // [rsp+38h] [rbp-28h]

  v8.m_pListBase = 0i64;
  v1 = this;
  OSuite::ZListBase::ZListIteratorBase::ZListIteratorBase(&v8, (OSuite::ZListBase *)&this->m_array.vfptr);
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&v8) )
  {
    OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v8.m_pListBase);
    v2 = v8.m_nIndex;
    v3 = v8.m_pListBase;
    v4 = v8.m_nIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)v8.m_pListBase,
      v8.m_nIndex + 1);
    if ( v2 >= v3->m_nTop )
      v3->m_nTop = v4;
    v5 = *(void (__fastcall ****)(_QWORD, signed __int64))(v3[1].m_nSize + 8 * v2);
    if ( v5 )
      (**v5)(v5, 1i64);
    OSuite::ZListBase::ZListIteratorBase::Next(&v8);
  }
  v6 = v1->m_object;
  v8.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonValue *>::ZIterator::`vftable';
  if ( v6 )
  {
    v6->vfptr->__vecDelDtor((OSuite::ZObject *)&v6->vfptr, 1u);
    v1->m_object = 0i64;
  }
  OSuite::ZString::ZString(&that, &customWorldMapCaption);
  OSuite::ZString::operator=(&v1->m_literal, &that);
  OSuite::ZString::~ZString(&that);
}

// File Line: 95
// RVA: 0xED0334
OSuite::ZString *__fastcall OSuite::ZJsonValue::GetForSerialization(OSuite::ZJsonValue *this, OSuite::ZString *result)
{
  OSuite::ZString *v2; // rbx
  OSuite::ZString *v3; // rax
  OSuite::ZString resulta; // [rsp+20h] [rbp-28h]

  v2 = result;
  if ( this->m_quotes )
  {
    v3 = OSuite::operator+(&resulta, "\"", &this->m_literal);
    OSuite::ZString::operator+(v3, v2, "\"");
    OSuite::ZString::~ZString(&resulta);
  }
  else
  {
    OSuite::ZString::ZString(result, &this->m_literal);
  }
  return v2;
}

// File Line: 115
// RVA: 0xECFC10
void __fastcall OSuite::ZJsonObject::ZJsonObject(OSuite::ZJsonObject *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonObject::`vftable';
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs,
    0x10ui64);
}

// File Line: 140
// RVA: 0xECFDE4
void __fastcall OSuite::ZJsonObject::~ZJsonObject(OSuite::ZJsonObject *this)
{
  OSuite::ZJsonObject *v1; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZJsonObject::`vftable';
  OSuite::ZJsonObject::Clear(this);
  v2 = v1->m_Pairs.m_pLists;
  v1->m_Pairs.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::`vftable';
  if ( v2 )
  {
    if ( LODWORD(v2[-1].m_Comparer.vfptr) )
      v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 3u);
    else
      Illusion::ShaderParam::operator delete(&v2[-1].m_Comparer.vfptr);
  }
}

// File Line: 145
// RVA: 0xECFF68
void __fastcall OSuite::ZJsonObject::Clear(OSuite::ZJsonObject *this)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *v1; // rbx
  OSuite::ZObjectVtbl *v2; // rcx
  OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator result; // [rsp+20h] [rbp-39h]

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  v1 = (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Iterator(
    (OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *> *)&this->m_Pairs,
    &result);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
  {
    v2 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
    if ( v2 )
      (*(void (__fastcall **)(OSuite::ZObjectVtbl *, signed __int64))v2->__vecDelDtor)(v2, 1i64);
    OSuite::TMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *>::ZIterator::Next(&result);
  }
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>::Clear(v1);
}

// File Line: 154
// RVA: 0xED038C
OSuite::ZObjectVtbl *__fastcall OSuite::ZJsonObject::Value(OSuite::ZJsonObject *this, OSuite::ZString *sName)
{
  OSuite::ZObjectVtbl *v2; // rbx
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::ZIterator result; // [rsp+20h] [rbp-39h]

  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::Find(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs,
    &result,
    sName);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) )
    v2 = 0i64;
  else
    v2 = result.m_iterator.m_iterator.m_pElement[2].vfptr;
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable';
  result.m_iterator.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
  if ( result.m_iterator.m_iterator.m_parents.m_pList )
    result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
      (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
      1u);
  return v2;
}

// File Line: 164
// RVA: 0xECFEE0
void __fastcall OSuite::ZJsonObject::Add(OSuite::ZJsonObject *this, OSuite::ZString *sName, OSuite::ZJsonValue *vValue)
{
  OSuite::ZUsageTracker *value; // [rsp+20h] [rbp-18h]

  value = (OSuite::ZUsageTracker *)vValue;
  OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *>::Insert(
    (OSuite::TMap<OSuite::ZString,OSuite::ZUsageTracker *> *)&this->m_Pairs,
    sName,
    &value);
}

