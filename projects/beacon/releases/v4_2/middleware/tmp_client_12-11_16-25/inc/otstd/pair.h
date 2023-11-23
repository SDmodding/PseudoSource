// File Line: 39
// RVA: 0xED09EC
void __fastcall OSuite::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString>>::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString>>(
        OSuite::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString> > *this,
        OSuite::ZString *v1)
{
  OSuite::ZObject *v3; // rdx
  OSuite::ZString *v4; // rax

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>::`vftable;
  OSuite::ZString::ZString(&this->m_First, v1);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_Second, v3);
  this->m_Second.m_pList = 0i64;
  this->m_Second.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::ZListBase};
  this->m_Second.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable{for `OSuite::IHashable};
  v4 = OSuite::TList<OSuite::ZString>::AllocList(&this->m_Second, 0i64, 0x10ui64);
  this->m_Second.m_nTop = 0i64;
  this->m_Second.m_nSize = 16i64;
  this->m_Second.m_pList = v4;
}

