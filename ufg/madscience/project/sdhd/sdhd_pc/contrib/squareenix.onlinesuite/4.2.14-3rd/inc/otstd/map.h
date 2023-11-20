// File Line: 148
// RVA: 0x428140
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(OSuite::TMap<OSuite::ZString,OSuite::ZString> *this, unsigned __int64 nHashSize)
{
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *v2; // rbx
  signed __int64 v3; // rdi
  int v4; // esi
  UFG::allocator::free_link *v5; // rax
  signed __int64 v6; // rax
  unsigned __int8 v7; // cf
  unsigned __int64 v8; // rax

  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  this->m_nHashSize = nHashSize;
  v3 = 0i64;
  this->m_nCount = 0i64;
  v4 = nHashSize;
  if ( (_DWORD)nHashSize )
  {
    v6 = 40i64 * (signed int)nHashSize;
    if ( !is_mul_ok((signed int)nHashSize, 0x28ui64) )
      v6 = -1i64;
    v7 = __CFADD__(v6, 8i64);
    v8 = v6 + 8;
    if ( v7 )
      v8 = -1i64;
    v5 = (UFG::allocator::free_link *)OSuite::ZObject::operator new(v8);
  }
  else
  {
    v5 = UFG::qMalloc(8ui64, UFG::gGlobalNewName, 0i64);
  }
  if ( v5 )
  {
    LODWORD(v5->mNext) = v4;
    v3 = (signed __int64)&v5[1];
    `eh vector constructor iterator(
      &v5[1],
      0x28ui64,
      v4,
      (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
  }
  v2->m_pLists = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)v3;
}

// File Line: 216
// RVA: 0x428C40
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZString>::~TMap<OSuite::ZString,OSuite::ZString>(OSuite::TMap<OSuite::ZString,OSuite::ZString> *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v1; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  v1 = this->m_pLists;
  if ( v1 )
  {
    if ( LODWORD(v1[-1].m_Comparer.vfptr) )
      v1->vfptr->__vecDelDtor((OSuite::ZObject *)&v1->vfptr, 3u);
    else
      operator delete[](&v1[-1].m_Comparer.vfptr);
  }
}

// File Line: 272
// RVA: 0x42E250
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(OSuite::TMap<OSuite::ZString,OSuite::ZString> *this, OSuite::ZString *key, OSuite::ZString *value)
{
  OSuite::ZString *v3; // rbp
  OSuite::ZString *v4; // rdi
  OSuite::TMap<OSuite::ZString,OSuite::ZString> *v5; // rsi
  OSuite::IHashable *v6; // rcx
  signed __int64 v7; // rbx
  unsigned __int64 v8; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v9; // rcx

  v3 = value;
  v4 = key;
  v5 = this;
  if ( key )
    v6 = (OSuite::IHashable *)&key->vfptr;
  else
    v6 = 0i64;
  v7 = (signed int)((v5->m_nHashSize - 1) & (unsigned __int64)((__int64 (*)(void))v6->vfptr->ComputeHash)());
  v8 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v5->m_pLists[v7].vfptr);
  v9 = v5->m_pLists;
  v5->m_nCount -= v8;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &v9[v7],
    v4,
    v3);
  v5->m_nCount += OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v5->m_pLists[v7].vfptr);
}

