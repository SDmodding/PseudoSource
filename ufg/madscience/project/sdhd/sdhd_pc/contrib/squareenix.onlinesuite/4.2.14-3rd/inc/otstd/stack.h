// File Line: 41
// RVA: 0x428DE0
void __fastcall OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::~TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>(OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  this->vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  v1 = this->m_pList;
  if ( v1 )
    v1->vfptr->__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 1u);
}

// File Line: 138
// RVA: 0x42B140
unsigned int __fastcall OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::ComputeHash(OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *this)
{
  OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbp
  unsigned __int64 *v2; // rbx
  _exception *v3; // rcx
  unsigned int v4; // esi
  signed __int64 v5; // rdi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax

  v1 = this;
  v2 = &this->m_nFree;
  v4 = OSuite::FComputeHashBegin((_exception *)this);
  v5 = 5i64;
  do
  {
    v6 = OSuite::FComputeHashBegin(v3);
    v7 = OSuite::FComputeHashAdd(v6, v2, 8ui64);
    v8 = OSuite::FComputeHashEnd(v7);
    ++v2;
    v4 = OSuite::FComputeHashAdd(v4, v8);
    --v5;
  }
  while ( v5 );
  v9 = OSuite::FComputeHashBegin(v3);
  v10 = OSuite::FComputeHashAdd(v9, &v1->m_staticList[4], 8ui64);
  v11 = OSuite::FComputeHashEnd(v10);
  v12 = OSuite::FComputeHashAdd(v4, v11);
  return OSuite::FComputeHashEnd(v12);
}

