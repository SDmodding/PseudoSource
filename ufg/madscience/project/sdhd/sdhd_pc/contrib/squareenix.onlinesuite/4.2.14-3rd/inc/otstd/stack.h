// File Line: 41
// RVA: 0x428DE0
void __fastcall OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::~TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>(
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *m_pList; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  m_pList = this->m_pList;
  if ( m_pList )
    m_pList->OSuite::ZListBase::OSuite::ZObject::vfptr->__vecDelDtor(m_pList, 1u);
}

// File Line: 138
// RVA: 0x42B140
unsigned int __fastcall OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::ComputeHash(
        OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this)
{
  unsigned __int64 *p_m_nFree; // rbx
  _exception *v3; // rcx
  unsigned int v4; // esi
  __int64 v5; // rdi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax

  p_m_nFree = &this->m_nFree;
  v4 = OSuite::FComputeHashBegin((_exception *)this);
  v5 = 5i64;
  do
  {
    v6 = OSuite::FComputeHashBegin(v3);
    v7 = OSuite::FComputeHashAdd(v6, p_m_nFree, 8ui64);
    v8 = OSuite::FComputeHashEnd(v7);
    ++p_m_nFree;
    v4 = OSuite::FComputeHashAdd(v4, v8);
    --v5;
  }
  while ( v5 );
  v9 = OSuite::FComputeHashBegin(v3);
  v10 = OSuite::FComputeHashAdd(v9, &this->m_staticList[4], 8ui64);
  v11 = OSuite::FComputeHashEnd(v10);
  v12 = OSuite::FComputeHashAdd(v4, v11);
  return OSuite::FComputeHashEnd(v12);
}

