// File Line: 39
// RVA: 0xED09EC
void __fastcall OSuite::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString>>::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString>>(OSuite::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString> > *this, OSuite::ZString *v1)
{
  OSuite::TPair<OSuite::ZString,OSuite::TList<OSuite::ZString> > *v2; // rdi
  OSuite::ZObject *v3; // rdx
  OSuite::ZString *v4; // rax

  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::TList<OSuite::ZString>>::`vftable';
  OSuite::ZString::ZString(&this->m_First, v1);
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v2->m_Second.vfptr, v3);
  v2->m_Second.m_pList = 0i64;
  v2->m_Second.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::ZListBase'};
  v2->m_Second.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZString>::`vftable'{for `OSuite::IHashable'};
  v4 = OSuite::TList<OSuite::ZString>::AllocList(&v2->m_Second, 0i64, 0x10ui64);
  v2->m_Second.m_nTop = 0i64;
  v2->m_Second.m_nSize = 16i64;
  v2->m_Second.m_pList = v4;
}

