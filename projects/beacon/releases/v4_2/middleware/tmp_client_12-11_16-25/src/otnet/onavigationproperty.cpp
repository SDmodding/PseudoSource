// File Line: 15
// RVA: 0xED61D8
void __fastcall OSuite::ZONavigationProperty::ZONavigationProperty(OSuite::ZONavigationProperty *this, OSuite::ZOEdmNavigationProperty *const pEdm, OSuite::ZString *sName, OSuite::ZString *sUri, OSuite::ZString *sBaseUrl)
{
  OSuite::ZOEdmNavigationProperty *v5; // rsi
  OSuite::ZString *v6; // rdi
  OSuite::ZString *v7; // rbx
  OSuite::ZONavigationProperty *v8; // r14

  v5 = pEdm;
  v6 = sUri;
  v7 = sName;
  v8 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr, sBaseUrl);
  v8->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZONavigationProperty::`vftable;
  OSuite::ZString::ZString(&v8->m_sName, v7);
  OSuite::ZString::ZString(&v8->m_sHref, v6);
  v8->m_pEdm = v5;
}

// File Line: 19
// RVA: 0xED624C
void __fastcall OSuite::ZONavigationProperty::~ZONavigationProperty(OSuite::ZONavigationProperty *this)
{
  OSuite::ZONavigationProperty *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZONavigationProperty::`vftable;
  OSuite::ZString::~ZString(&this->m_sHref);
  OSuite::ZString::~ZString(&v1->m_sName);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v1->vfptr);
}

