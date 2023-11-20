// File Line: 29
// RVA: 0x428B70
void __fastcall OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::~TKeyValueElement<OSuite::ZString,OSuite::ZString>(OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *this)
{
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
  OSuite::ZString::~ZString(&this->m_Second);
  OSuite::ZString::~ZString(&v1->m_First);
}

// File Line: 82
// RVA: 0x428C00
void __fastcall OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::~TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this)
{
  this->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
}

// File Line: 88
// RVA: 0x42C090
bool __fastcall OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Equals(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v1, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v2)
{
  return OSuite::ZString::operator==(&v1->m_First, &v2->m_First);
}

// File Line: 93
// RVA: 0x42E8D0
bool __fastcall OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::LessThan(OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *this, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v1, OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *v2)
{
  return OSuite::ZString::operator<(&v1->m_First, &v2->m_First);
}

