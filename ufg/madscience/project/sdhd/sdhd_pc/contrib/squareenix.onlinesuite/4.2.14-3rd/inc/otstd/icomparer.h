// File Line: 27
// RVA: 0x428C70
void __fastcall OSuite::TOperatorComparer<OSuite::ZString>::~TOperatorComparer<OSuite::ZString>(OSuite::TOperatorComparer<OSuite::ZString> *this)
{
  this->vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
}

// File Line: 30
// RVA: 0x42C0A0
bool __fastcall OSuite::TOperatorComparer<OSuite::ZString>::Equals(OSuite::TOperatorComparer<OSuite::ZString> *this, OSuite::ZString *v1, OSuite::ZString *v2)
{
  return OSuite::ZString::operator==(v1, v2);
}

// File Line: 35
// RVA: 0x42E8E0
bool __fastcall OSuite::TOperatorComparer<OSuite::ZString>::LessThan(OSuite::TOperatorComparer<OSuite::ZString> *this, OSuite::ZString *v1, OSuite::ZString *v2)
{
  return OSuite::ZString::operator<(v1, v2);
}

