// File Line: 148
// RVA: 0x428140
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(
        OSuite::TMap<OSuite::ZString,OSuite::ZString> *this,
        unsigned __int64 nHashSize)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rdi
  int v4; // esi
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  bool v7; // cf
  unsigned __int64 v8; // rax

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  this->m_nHashSize = nHashSize;
  v3 = 0i64;
  this->m_nCount = 0i64;
  v4 = nHashSize;
  if ( (_DWORD)nHashSize )
  {
    v6 = 40i64 * (int)nHashSize;
    if ( !is_mul_ok((int)nHashSize, 0x28ui64) )
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
    v3 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v5[1];
    `eh vector constructor iterator(
      &v5[1],
      0x28ui64,
      v4,
      (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
  }
  this->m_pLists = v3;
}

// File Line: 216
// RVA: 0x428C40
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZString>::~TMap<OSuite::ZString,OSuite::ZString>(
        OSuite::TMap<OSuite::ZString,OSuite::ZString> *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  m_pLists = this->m_pLists;
  if ( m_pLists )
  {
    if ( LODWORD(m_pLists[-1].m_Comparer.vfptr) )
      m_pLists->vfptr->__vecDelDtor(m_pLists, 3u);
    else
      operator delete[](&m_pLists[-1].m_Comparer.OSuite::ZObject);
  }
}

// File Line: 272
// RVA: 0x42E250
void __fastcall OSuite::TMap<OSuite::ZString,OSuite::ZString>::Insert(
        OSuite::TMap<OSuite::ZString,OSuite::ZString> *this,
        OSuite::ZString *key,
        OSuite::ZString *value)
{
  OSuite::IHashable *v6; // rcx
  __int64 v7; // rbx
  unsigned __int64 v8; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *m_pLists; // rcx

  if ( key )
    v6 = &key->OSuite::IHashable;
  else
    v6 = 0i64;
  v7 = (int)((this->m_nHashSize - 1) & ((__int64 (__fastcall *)(OSuite::IHashable *))v6->vfptr->ComputeHash)(v6));
  v8 = OSuite::ZHttpStreamReader::Tell(&this->m_pLists[v7]);
  m_pLists = this->m_pLists;
  this->m_nCount -= v8;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &m_pLists[v7],
    key,
    value);
  this->m_nCount += OSuite::ZHttpStreamReader::Tell(&this->m_pLists[v7]);
}

