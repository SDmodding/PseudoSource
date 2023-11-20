// File Line: 13
// RVA: 0xBFE890
hkaiSearchStateNode *__fastcall hkaiHashSearchState::getNodeState(hkaiHashSearchState *this, unsigned int sid)
{
  unsigned int v2; // ebx
  __int64 v3; // rdi
  __int16 v4; // r8
  hkaiSearchStateNode *v5; // rdx
  __int64 v6; // r10
  hkaiSearchStateNode *v7; // r9
  hkaiSearchStateNode *result; // rax

  v2 = sid;
  v3 = -79 * (_WORD)sid & 0xFF;
  v4 = this->m_hashFirst[v3];
  if ( v4 < 0 )
  {
LABEL_5:
    v6 = SLOWORD(this->m_nodeSize);
    v7 = &this->m_nodes[this->m_nodeSize++];
    v7->m_gCost = 3.40282e38;
    v7->m_hCost = 3.40282e38;
    v7->m_index = v2;
    v7->m_parentIndex = -1;
    v7->m_flags.m_storage = 0;
    result = v7;
    this->m_hashNext[v6] = this->m_hashFirst[v3];
    this->m_hashFirst[v3] = v6;
  }
  else
  {
    v5 = this->m_nodes;
    while ( v5[v4].m_index != v2 )
    {
      v4 = this->m_hashNext[v4];
      if ( v4 < 0 )
        goto LABEL_5;
    }
    result = &v5[v4];
  }
  return result;
}

// File Line: 47
// RVA: 0xBFE970
hkaiSearchStateNode *__fastcall hkaiHashSearchState::getNodeStateRO(hkaiHashSearchState *this, unsigned int sid)
{
  __int16 v2; // r9
  hkaiSearchStateNode *v3; // r8

  v2 = this->m_hashFirst[(unsigned __int8)(-79 * sid)];
  if ( v2 < 0 )
    return &this->m_dummyNode;
  v3 = this->m_nodes;
  while ( v3[v2].m_index != sid )
  {
    v2 = this->m_hashNext[v2];
    if ( v2 < 0 )
      return &this->m_dummyNode;
  }
  return &v3[v2];
}

// File Line: 68
// RVA: 0xBFE790
void __fastcall hkaiHashSearchState::setStorage(hkaiHashSearchState *this, char *storage, int size)
{
  hkaiHashSearchState *v3; // r9
  hkaiSearchStateNode *v4; // r10
  unsigned __int64 v5; // rdx
  int v6; // edi
  __int16 *v7; // rcx
  signed __int64 v8; // rdx
  int v9; // eax
  __int16 *v10; // rdi
  __int64 i; // rcx

  v3 = this;
  if ( size > 512 )
  {
    this->m_hashFirst = (__int16 *)storage;
    v4 = (hkaiSearchStateNode *)(storage + 512);
    v5 = (unsigned __int64)((unsigned __int64)(size - 512) * (unsigned __int128)0xE38E38E38E38E38Fui64 >> 64) >> 4;
    if ( (v5 & 0x80000000) == 0i64 )
    {
      if ( (signed int)v5 > 0x8000 )
        LODWORD(v5) = 0x8000;
    }
    else
    {
      LODWORD(v5) = 0;
    }
    this->m_nodeCapacity = v5;
    v6 = 2 * v5;
    this->m_nodes = v4;
    this->m_hashNext = (__int16 *)&v4[(signed int)v5];
    v7 = this->m_hashFirst;
    if ( v7 )
    {
      v8 = 8i64;
      do
      {
        *(_QWORD *)v7 = -1i64;
        *((_QWORD *)v7 + 1) = -1i64;
        *((_QWORD *)v7 + 2) = -1i64;
        v7 += 32;
        *((_QWORD *)v7 - 5) = -1i64;
        *((_QWORD *)v7 - 4) = -1i64;
        *((_QWORD *)v7 - 3) = -1i64;
        *((_QWORD *)v7 - 2) = -1i64;
        *((_QWORD *)v7 - 1) = -1i64;
        --v8;
      }
      while ( v8 );
      v9 = v6 / 4 - 1;
      if ( v9 >= 0 )
      {
        v10 = v3->m_hashNext;
        for ( i = (unsigned int)(v9 + 1); i; --i )
        {
          *(_DWORD *)v10 = -1;
          v10 += 2;
        }
      }
    }
  }
}

