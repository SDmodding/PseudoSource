// File Line: 54
// RVA: 0x428D50
void __fastcall OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::~TPair<OSuite::ZUrl,OSuite::ZCachedObject *>(
        OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *> *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZUrl,OSuite::ZCachedObject *>::`vftable;
  OSuite::ZUrl::~ZUrl(&this->m_First);
}

