// File Line: 18
// RVA: 0xEC0754
void __fastcall OSuite::ZMetric::ZMetric(OSuite::ZMetric *this, OSuite::ZString *sName, OSuite::ZClock *startTime)
{
  OSuite::ZMetric *v3; // rsi
  OSuite::ZClock *v4; // rbp
  OSuite::ZString *v5; // rdi
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *v7; // rbx
  OSuite::ZString *v8; // rax
  const char *v9; // rax
  unsigned __int64 v10; // rax
  int v11; // eax
  int v12; // eax
  int v13; // er8
  OSuite::ZString result; // [rsp+20h] [rbp-48h]
  OSuite::ZUuid v15; // [rsp+38h] [rbp-30h]

  v3 = this;
  v4 = startTime;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::`vftable;
  v5 = sName;
  OSuite::ZString::ZString(&this->m_sName, sName);
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase((OSuite::ZRedBlackTreeBase *)&v3->m_attributes.vfptr);
  v3->m_attributes.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  v3->m_attributes.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  v3->m_attributes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZString::IndexOf(v5, 32, 0i64);
  v6 = OSuite::ZOnlineSuite::Instance();
  v7 = OSuite::ZOnlineSuite::GetGameConfig(v6);
  if ( !v7->vfptr->IsFinal(v7) )
  {
    v15.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::ZObject};
    v15.vfptr = (OSuite::IHashableVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::IHashable};
    OSuite::psock::uuid::create(v15.m_anUuid, 1);
    v8 = OSuite::ZUuid::ToString(&v15, &result);
    OSuite::ZMetric::SetProperty(v3, "s__UUID", v8);
    OSuite::ZString::~ZString(&result);
  }
  OSuite::ZMetric::SetProperty(v3, "s__SaveID", &customWorldMapCaption);
  OSuite::ZMetric::SetProperty(v3, "s__PSaveID", &customWorldMapCaption);
  v9 = v7->vfptr->LanguageString(v7);
  OSuite::ZMetric::SetProperty(v3, "s__Language", v9);
  v10 = OSuite::ZClock::_GetClock();
  v11 = OSuite::ZClock::_ClockToTime(v10 - v4->m_clock, UNIT_MILLI);
  OSuite::ZMetric::SetProperty(v3, "i32__STime", v11);
  v12 = v7->vfptr->GameTime(v7);
  OSuite::ZMetric::SetProperty(v3, "i32__GameTime", v12);
  v13 = OSuite::ZMetric::s_uSeqID++;
  OSuite::ZMetric::SetProperty(v3, "i32__SeqID", v13);
}

// File Line: 45
// RVA: 0xEC08EC
void __fastcall OSuite::ZMetric::~ZMetric(OSuite::ZMetric *this)
{
  OSuite::ZMetric *v1; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::`vftable;
  OSuite::ZMetric::Clear(this);
  v2 = &v1->m_attributes;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  v2->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  v2->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&v1->m_attributes.vfptr);
  OSuite::ZString::~ZString(&v1->m_sName);
}

// File Line: 50
// RVA: 0xEC0B38
void __fastcall OSuite::ZMetric::Clear(OSuite::ZMetric *this)
{
  OSuite::ZMetric *v1; // rbx
  void (__fastcall ***v2)(_QWORD, signed __int64); // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase that; // [rsp+28h] [rbp-C0h]
  __int64 v4; // [rsp+90h] [rbp-58h]
  void **v5; // [rsp+98h] [rbp-50h]
  void **v6; // [rsp+A0h] [rbp-48h]
  void (__fastcall ***v7)(_QWORD, signed __int64); // [rsp+D8h] [rbp-10h]

  v7 = 0i64;
  v1 = this;
  _mm_store_si128((__m128i *)&v6, (__m128i)0i64);
  that.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v5);
  that.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&that, (OSuite::ZRedBlackTreeBase *)&v1->m_attributes.vfptr);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)((char *)&that + 88),
    &that);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  that.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  that.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( that.m_parents.m_staticList[2] )
    that.m_parents.m_staticList[2]->vfptr->__vecDelDtor((OSuite::ZObject *)that.m_parents.m_staticList[2], 1u);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&that.m_parents.m_pList) )
  {
    v2 = *(void (__fastcall ****)(_QWORD, signed __int64))(v4 + 64);
    if ( v2 )
      (**v2)(v2, 1i64);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)((char *)&that + 88));
  }
  that.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  that.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v5 = &OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v6 = &OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v7 )
    (**v7)(v7, 1i64);
}

// File Line: 80
// RVA: 0xEC0F64
OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZMetric::IStoredData *,OSuite::ZString> *__fastcall OSuite::ZMetric::Iterator(OSuite::ZMetric *this, OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZMetric::IStoredData *,OSuite::ZString> *result)
{
  OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::ZMetric::IStoredData *,OSuite::ZString> *v2; // rbx

  v2 = result;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
    (OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *)result);
  return v2;
}

// File Line: 85
// RVA: 0xEC0F94
OSuite::ZUrl *__fastcall OSuite::ZHttpConnection::Url(OSuite::ZHttpConnection *this)
{
  return &this->m_url;
}

// File Line: 91
// RVA: 0xEC0F9C
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, const char *pszValue)
{
  const char *v3; // rdi
  OSuite::ZMetric *v4; // rsi
  const char *v5; // rbx
  char *v6; // rax
  OSuite::ZUsageTracker *v7; // rbx
  OSuite::ZUsageTracker *v8; // [rsp+30h] [rbp-40h]
  OSuite::ZString key; // [rsp+38h] [rbp-38h]
  OSuite::ZString value; // [rsp+50h] [rbp-20h]

  v3 = sAttrName;
  v4 = this;
  v5 = pszValue;
  strchr(sAttrName, 32);
  value.m_pString = 0i64;
  OSuite::ZString::ZString(&value, v5);
  OSuite::ZString::ReplaceChar(&value, 34, 39, 0i64, 1);
  if ( !OSuite::ZMetric::ReplaceIfExist<OSuite::ZString>(v4, v3, &value) )
  {
    v6 = (char *)OSuite::ZObject::operator new(0x20ui64);
    v7 = (OSuite::ZUsageTracker *)v6;
    if ( v6 )
    {
      *((_QWORD *)v6 + 3) = 0i64;
      *(_QWORD *)v6 = &OSuite::ZMetric::TStoredData<OSuite::ZString>::`vftable;
      OSuite::ZString::ZString((OSuite::ZString *)(v6 + 8), &value);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    OSuite::ZString::ZString(&key, v3);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&v4->m_attributes,
      &key,
      &v8);
    OSuite::ZString::~ZString(&key);
  }
  OSuite::ZString::~ZString(&value);
}

// File Line: 100
// RVA: 0xEC1090
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, OSuite::ZString *sValue)
{
  const char *v3; // rdi
  OSuite::ZMetric *v4; // rsi
  OSuite::ZString *v5; // rbx
  char *v6; // rax
  OSuite::ZUsageTracker *v7; // rbx
  OSuite::ZUsageTracker *v8; // [rsp+30h] [rbp-40h]
  OSuite::ZString key; // [rsp+38h] [rbp-38h]
  OSuite::ZString value; // [rsp+50h] [rbp-20h]

  v3 = sAttrName;
  v4 = this;
  v5 = sValue;
  strchr(sAttrName, 32);
  value.m_pString = 0i64;
  OSuite::ZString::ZString(&value, v5);
  OSuite::ZString::ReplaceChar(&value, 34, 39, 0i64, 1);
  if ( !OSuite::ZMetric::ReplaceIfExist<OSuite::ZString>(v4, v3, &value) )
  {
    v6 = (char *)OSuite::ZObject::operator new(0x20ui64);
    v7 = (OSuite::ZUsageTracker *)v6;
    if ( v6 )
    {
      *((_QWORD *)v6 + 3) = 0i64;
      *(_QWORD *)v6 = &OSuite::ZMetric::TStoredData<OSuite::ZString>::`vftable;
      OSuite::ZString::ZString((OSuite::ZString *)(v6 + 8), &value);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    OSuite::ZString::ZString(&key, v3);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&v4->m_attributes,
      &key,
      &v8);
    OSuite::ZString::~ZString(&key);
  }
  OSuite::ZString::~ZString(&value);
}

// File Line: 109
// RVA: 0xEC1184
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, int i32Value)
{
  const char *v3; // rdi
  OSuite::ZMetric *v4; // rsi
  int v5; // ebx
  OSuite::ZUsageTracker *v6; // rax
  OSuite::ZUsageTracker *v7; // [rsp+20h] [rbp-38h]
  OSuite::ZString key; // [rsp+28h] [rbp-30h]
  int value; // [rsp+70h] [rbp+18h]

  value = i32Value;
  v3 = sAttrName;
  v4 = this;
  v5 = i32Value;
  strchr(sAttrName, 32);
  if ( !OSuite::ZMetric::ReplaceIfExist<int>(v4, v3, &value) )
  {
    v6 = (OSuite::ZUsageTracker *)OSuite::ZObject::operator new(0x10ui64);
    if ( v6 )
    {
      LODWORD(v6->m_samplingInterval) = v5;
      v7 = v6;
      v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::TStoredData<int>::`vftable;
    }
    else
    {
      v7 = 0i64;
    }
    OSuite::ZString::ZString(&key, v3);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&v4->m_attributes,
      &key,
      &v7);
    OSuite::ZString::~ZString(&key);
  }
}

// File Line: 116
// RVA: 0xEC12BC
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, __int64 i64Value)
{
  const char *v3; // rdi
  OSuite::ZMetric *v4; // rsi
  __int64 v5; // rbx
  OSuite::ZUsageTracker *v6; // rax
  OSuite::ZUsageTracker *v7; // [rsp+20h] [rbp-38h]
  OSuite::ZString key; // [rsp+28h] [rbp-30h]
  __int64 value; // [rsp+70h] [rbp+18h]

  value = i64Value;
  v3 = sAttrName;
  v4 = this;
  v5 = i64Value;
  strchr(sAttrName, 32);
  if ( !OSuite::ZMetric::ReplaceIfExist<__int64>(v4, v3, &value) )
  {
    v6 = (OSuite::ZUsageTracker *)OSuite::ZObject::operator new(0x10ui64);
    if ( v6 )
    {
      v6->m_samplingInterval = v5;
      v7 = v6;
      v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::TStoredData<__int64>::`vftable;
    }
    else
    {
      v7 = 0i64;
    }
    OSuite::ZString::ZString(&key, v3);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&v4->m_attributes,
      &key,
      &v7);
    OSuite::ZString::~ZString(&key);
  }
}

// File Line: 123
// RVA: 0xEC1218
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, long double dValue)
{
  const char *v3; // rbx
  OSuite::ZMetric *v4; // rdi
  long double *v5; // rax
  OSuite::ZUsageTracker *v6; // [rsp+20h] [rbp-38h]
  OSuite::ZString key; // [rsp+28h] [rbp-30h]
  __int64 value; // [rsp+70h] [rbp+18h]

  value = *(_QWORD *)&dValue;
  v3 = sAttrName;
  v4 = this;
  strchr(sAttrName, 32);
  if ( !OSuite::ZMetric::ReplaceIfExist<__int64>(v4, v3, &value) )
  {
    v5 = (long double *)OSuite::ZObject::operator new(0x10ui64);
    if ( v5 )
    {
      v5[1] = dValue;
      v6 = (OSuite::ZUsageTracker *)v5;
      *(_QWORD *)v5 = &OSuite::ZMetric::TStoredData<double>::`vftable;
    }
    else
    {
      v6 = 0i64;
    }
    OSuite::ZString::ZString(&key, v3);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&v4->m_attributes,
      &key,
      &v6);
    OSuite::ZString::~ZString(&key);
  }
}

