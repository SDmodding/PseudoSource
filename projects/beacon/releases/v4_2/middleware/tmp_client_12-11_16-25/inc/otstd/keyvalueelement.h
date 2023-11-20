// File Line: 88
// RVA: 0xEE421C
bool __fastcall OSuite::TKeyValueElementComparer<void *,OSuite::ZObjectAccessor::InternalObjectAccessor *,OSuite::TOperatorComparer<void *>>::Equals(OSuite::TKeyValueElementComparer<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> > *this, OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *v1, OSuite::TKeyValueElement<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> > *v2)
{
  return v1->m_First == v2->m_First;
}

// File Line: 93
// RVA: 0xEC0F84
bool __fastcall OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *,OSuite::TOperatorComparer<OSuite::ZString>>::LessThan(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZUsageTracker *,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *v1, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker *> *v2)
{
  return OSuite::ZString::operator<(&v1->m_First, &v2->m_First);
}

