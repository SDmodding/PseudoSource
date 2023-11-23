// File Line: 60
// RVA: 0xEC13EC
OSuite::ZString *__fastcall OSuite::ZMetric::TStoredData<__int64>::ToString(
        OSuite::ZMetric::TStoredData<__int64> *this,
        OSuite::ZString *result)
{
  OSuite::ZString::ZString(result, this->m_data);
  return result;
}

// File Line: 65
// RVA: 0xEC0B20
bool __fastcall OSuite::ZMetric::TStoredData<OSuite::ZString>::CanSerialize(
        OSuite::ZMetric::TStoredData<OSuite::ZString> *this)
{
  return OSuite::ZString::c_str(&this->m_data) != 0i64;
}

// File Line: 70
// RVA: 0xEC0F80
bool __fastcall OSuite::ZMetric::TStoredData<double>::JSonQuotesRequired(OSuite::ZLog *this)
{
  return 0;
}

// File Line: 75
// RVA: 0xEC0C98
OSuite::ZMetric::IStoredData *__fastcall OSuite::ZMetric::TStoredData<double>::Clone(
        OSuite::ZMetric::TStoredData<double> *this)
{
  OSuite::ZMetric::IStoredData *result; // rax

  result = (OSuite::ZMetric::IStoredData *)OSuite::ZObject::operator new(0x10ui64);
  if ( result )
  {
    result->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMetric::TStoredData<double>::`vftable;
    result[1].vfptr = *(OSuite::ZObjectVtbl **)&this->m_data;
  }
  return result;
}

// File Line: 186
// RVA: 0xEC0494
char __fastcall OSuite::ZMetric::ReplaceIfExist<int>(OSuite::ZMetric *this, const char *sAttrName, const int *value)
{
  char v5; // bl
  OSuite::ZString key; // [rsp+20h] [rbp-49h] BYREF
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIterator result; // [rsp+40h] [rbp-29h] BYREF

  result.m_iterator.m_parents.m_pList = 0i64;
  *(_OWORD *)&result.m_iterator.m_pList = 0i64;
  OSuite::ZString::ZString(&key, sAttrName);
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::Find(
    (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *)&this->m_attributes,
    &result,
    &key);
  OSuite::ZString::~ZString(&key);
  if ( OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator) )
  {
    v5 = 0;
  }
  else
  {
    v5 = 1;
    LODWORD(result.m_iterator.m_pElement[2].vfptr[1].__vecDelDtor) = *value;
  }
  result.vfptr = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  result.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  if ( result.m_iterator.m_parents.m_pList )
    result.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(result.m_iterator.m_parents.m_pList, 1u);
  return v5;
}

