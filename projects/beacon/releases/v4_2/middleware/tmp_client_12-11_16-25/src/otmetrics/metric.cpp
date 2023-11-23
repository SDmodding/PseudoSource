// File Line: 18
// RVA: 0xEC0754
void __fastcall OSuite::ZMetric::ZMetric(OSuite::ZMetric *this, OSuite::ZString *sName, OSuite::ZClock *startTime)
{
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *GameConfig; // rbx
  OSuite::ZString *v8; // rax
  const char *v9; // rax
  unsigned __int64 Clock; // rax
  int v11; // eax
  int v12; // eax
  int v13; // r8d
  OSuite::ZString result; // [rsp+20h] [rbp-48h] BYREF
  OSuite::ZUuid v15; // [rsp+38h] [rbp-30h] BYREF

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::`vftable;
  OSuite::ZString::ZString(&this->m_sName, sName);
  OSuite::ZDoublyLinkedListBase::ZDoublyLinkedListBase(&this->m_attributes);
  this->m_attributes.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_attributes.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable{for `OSuite::ZObject};
  this->m_attributes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOrderedMap<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable;
  OSuite::ZString::IndexOf(sName, 32, 0i64);
  v6 = OSuite::ZOnlineSuite::Instance();
  GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v6);
  if ( !GameConfig->vfptr->IsFinal(GameConfig) )
  {
    v15.OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::ZObject};
    v15.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::ZUuid::`vftable{for `OSuite::IHashable};
    OSuite::psock::uuid::create(v15.m_anUuid, 1);
    v8 = OSuite::ZUuid::ToString(&v15, &result);
    OSuite::ZMetric::SetProperty(this, "s__UUID", v8);
    OSuite::ZString::~ZString(&result);
  }
  OSuite::ZMetric::SetProperty(this, "s__SaveID", &customCaption);
  OSuite::ZMetric::SetProperty(this, "s__PSaveID", &customCaption);
  v9 = GameConfig->vfptr->LanguageString(GameConfig);
  OSuite::ZMetric::SetProperty(this, "s__Language", v9);
  Clock = OSuite::ZClock::_GetClock();
  v11 = OSuite::ZClock::_ClockToTime(Clock - startTime->m_clock, UNIT_MILLI);
  OSuite::ZMetric::SetProperty(this, "i32__STime", v11);
  v12 = GameConfig->vfptr->GameTime(GameConfig);
  OSuite::ZMetric::SetProperty(this, "i32__GameTime", v12);
  v13 = OSuite::ZMetric::s_uSeqID++;
  OSuite::ZMetric::SetProperty(this, "i32__SeqID", v13);
}

// File Line: 45
// RVA: 0xEC08EC
void __fastcall OSuite::ZMetric::~ZMetric(OSuite::ZMetric *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::`vftable;
  OSuite::ZMetric::Clear(this);
  this->m_attributes.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZMetric::IStoredData *>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZMetric::IStoredData *,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_attributes.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_attributes.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(&this->m_attributes);
  OSuite::ZString::~ZString(&this->m_sName);
}

// File Line: 50
// RVA: 0xEC0B38
void __fastcall OSuite::ZMetric::Clear(OSuite::ZMetric *this)
{
  void (__fastcall ***v2)(_QWORD, __int64); // rcx
  OSuite::ZRedBlackTreeBase::ZIteratorBase that; // [rsp+28h] [rbp-C0h] BYREF
  __int128 v4; // [rsp+88h] [rbp-60h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v5; // [rsp+98h] [rbp-50h] BYREF

  v5.m_parents.m_staticList[2] = 0i64;
  v4 = 0i64;
  that.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v5);
  that.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&that, &this->m_attributes);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::operator=(
    (OSuite::ZRedBlackTreeBase::ZIteratorBase *)&that.m_parents.m_pList,
    &that);
  that.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  that.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  that.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( that.m_parents.m_staticList[2] )
    that.m_parents.m_staticList[2]->vfptr->__vecDelDtor(that.m_parents.m_staticList[2], 1u);
  while ( !OSuite::ZString::IsNull((OSuite::ZString *)&that.m_parents.m_pList) )
  {
    v2 = *(void (__fastcall ****)(_QWORD, __int64))(*((_QWORD *)&v4 + 1) + 64i64);
    if ( v2 )
      (**v2)(v2, 1i64);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::Next((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&that.m_parents.m_pList);
  }
  that.m_parents.m_staticList[4] = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  that.m_parents.m_pList = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v5.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  v5.m_pList = (OSuite::ZRedBlackTreeBase *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( v5.m_parents.m_staticList[2] )
    v5.m_parents.m_staticList[2]->vfptr->__vecDelDtor(v5.m_parents.m_staticList[2], 1u);
}

// File Line: 80
// RVA: 0xEC0F64
OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *__fastcall OSuite::ZMetric::Iterator(
        OSuite::ZMetric *this,
        OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString> *result)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Iterator(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
    result);
  return result;
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
  char *v6; // rax
  OSuite::ZUsageTracker *v7; // rbx
  OSuite::ZUsageTracker *v8; // [rsp+30h] [rbp-40h] BYREF
  OSuite::ZString key; // [rsp+38h] [rbp-38h] BYREF
  OSuite::ZString value; // [rsp+50h] [rbp-20h] BYREF

  strchr(sAttrName, 32);
  value.m_pString = 0i64;
  OSuite::ZString::ZString(&value, pszValue);
  OSuite::ZString::ReplaceChar(&value, 34, 39, 0i64, 1);
  if ( !OSuite::ZMetric::ReplaceIfExist<OSuite::ZString>(this, sAttrName, &value) )
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
    OSuite::ZString::ZString(&key, sAttrName);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
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
  char *v6; // rax
  OSuite::ZUsageTracker *v7; // rbx
  OSuite::ZUsageTracker *v8; // [rsp+30h] [rbp-40h] BYREF
  OSuite::ZString key; // [rsp+38h] [rbp-38h] BYREF
  OSuite::ZString value; // [rsp+50h] [rbp-20h] BYREF

  strchr(sAttrName, 32);
  value.m_pString = 0i64;
  OSuite::ZString::ZString(&value, sValue);
  OSuite::ZString::ReplaceChar(&value, 34, 39, 0i64, 1);
  if ( !OSuite::ZMetric::ReplaceIfExist<OSuite::ZString>(this, sAttrName, &value) )
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
    OSuite::ZString::ZString(&key, sAttrName);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
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
  OSuite::ZUsageTracker *v6; // rax
  OSuite::ZUsageTracker *v7; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString key; // [rsp+28h] [rbp-30h] BYREF
  int value; // [rsp+70h] [rbp+18h] BYREF

  value = i32Value;
  strchr(sAttrName, 32);
  if ( !OSuite::ZMetric::ReplaceIfExist<int>(this, sAttrName, &value) )
  {
    v6 = (OSuite::ZUsageTracker *)OSuite::ZObject::operator new(0x10ui64);
    if ( v6 )
    {
      LODWORD(v6->m_samplingInterval) = i32Value;
      v7 = v6;
      v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::TStoredData<int>::`vftable;
    }
    else
    {
      v7 = 0i64;
    }
    OSuite::ZString::ZString(&key, sAttrName);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
      &key,
      &v7);
    OSuite::ZString::~ZString(&key);
  }
}

// File Line: 116
// RVA: 0xEC12BC
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, unsigned __int64 i64Value)
{
  OSuite::ZUsageTracker *v6; // rax
  OSuite::ZUsageTracker *v7; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString key; // [rsp+28h] [rbp-30h] BYREF
  __int64 value; // [rsp+70h] [rbp+18h] BYREF

  value = i64Value;
  strchr(sAttrName, 32);
  if ( !OSuite::ZMetric::ReplaceIfExist<__int64>(
          this,
          sAttrName,
          (void *(__fastcall **)(OSuite::ZObject *, unsigned int))&value) )
  {
    v6 = (OSuite::ZUsageTracker *)OSuite::ZObject::operator new(0x10ui64);
    if ( v6 )
    {
      v6->m_samplingInterval = i64Value;
      v7 = v6;
      v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::TStoredData<__int64>::`vftable;
    }
    else
    {
      v7 = 0i64;
    }
    OSuite::ZString::ZString(&key, sAttrName);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
      &key,
      &v7);
    OSuite::ZString::~ZString(&key);
  }
}

// File Line: 123
// RVA: 0xEC1218
void __fastcall OSuite::ZMetric::SetProperty(OSuite::ZMetric *this, const char *sAttrName, long double dValue)
{
  long double *v5; // rax
  OSuite::ZUsageTracker *v6; // [rsp+20h] [rbp-38h] BYREF
  OSuite::ZString key; // [rsp+28h] [rbp-30h] BYREF
  __int64 value; // [rsp+70h] [rbp+18h] BYREF

  value = *(_QWORD *)&dValue;
  strchr(sAttrName, 32);
  if ( !OSuite::ZMetric::ReplaceIfExist<__int64>(
          this,
          sAttrName,
          (void *(__fastcall **)(OSuite::ZObject *, unsigned int))&value) )
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
    OSuite::ZString::ZString(&key, sAttrName);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZJsonValue *,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
      &key,
      &v6);
    OSuite::ZString::~ZString(&key);
  }
}

