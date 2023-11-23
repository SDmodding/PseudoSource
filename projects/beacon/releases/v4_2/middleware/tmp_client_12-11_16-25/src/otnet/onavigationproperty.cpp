// File Line: 15
// RVA: 0xED61D8
void __fastcall OSuite::ZONavigationProperty::ZONavigationProperty(
        OSuite::ZONavigationProperty *this,
        OSuite::ZOEdmNavigationProperty *const pEdm,
        OSuite::ZString *sName,
        OSuite::ZString *sUri,
        OSuite::ZString *sBaseUrl)
{
  OSuite::ZAtomBase::ZAtomBase(this, sBaseUrl);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZONavigationProperty::`vftable;
  OSuite::ZString::ZString(&this->m_sName, sName);
  OSuite::ZString::ZString(&this->m_sHref, sUri);
  this->m_pEdm = pEdm;
}

// File Line: 19
// RVA: 0xED624C
void __fastcall OSuite::ZONavigationProperty::~ZONavigationProperty(OSuite::ZONavigationProperty *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZONavigationProperty::`vftable;
  OSuite::ZString::~ZString(&this->m_sHref);
  OSuite::ZString::~ZString(&this->m_sName);
  OSuite::ZAtomBase::~ZAtomBase(this);
}

