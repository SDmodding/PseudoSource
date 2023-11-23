// File Line: 13
// RVA: 0xBFE890
hkaiSearchStateNode *__fastcall hkaiHashSearchState::getNodeState(hkaiHashSearchState *this, unsigned int sid)
{
  __int64 v3; // rdi
  __int16 v4; // r8
  hkaiSearchStateNode *m_nodes; // rdx
  __int64 m_nodeSize_low; // r10
  hkaiSearchStateNode *v7; // r9
  hkaiSearchStateNode *result; // rax

  v3 = (unsigned __int8)(-79 * sid);
  v4 = this->m_hashFirst[v3];
  if ( v4 < 0 )
  {
LABEL_5:
    m_nodeSize_low = SLOWORD(this->m_nodeSize);
    v7 = &this->m_nodes[this->m_nodeSize++];
    v7->m_gCost = 3.40282e38;
    v7->m_hCost = 3.40282e38;
    v7->m_index = sid;
    v7->m_parentIndex = -1;
    v7->m_flags.m_storage = 0;
    result = v7;
    this->m_hashNext[m_nodeSize_low] = this->m_hashFirst[v3];
    this->m_hashFirst[v3] = m_nodeSize_low;
  }
  else
  {
    m_nodes = this->m_nodes;
    while ( m_nodes[v4].m_index != sid )
    {
      v4 = this->m_hashNext[v4];
      if ( v4 < 0 )
        goto LABEL_5;
    }
    return &m_nodes[v4];
  }
  return result;
}

// File Line: 47
// RVA: 0xBFE970
hkaiSearchStateNode *__fastcall hkaiHashSearchState::getNodeStateRO(hkaiHashSearchState *this, unsigned int sid)
{
  __int16 v2; // r9
  hkaiSearchStateNode *m_nodes; // r8

  v2 = this->m_hashFirst[(unsigned __int8)(-79 * sid)];
  if ( v2 < 0 )
    return &this->m_dummyNode;
  m_nodes = this->m_nodes;
  while ( m_nodes[v2].m_index != sid )
  {
    v2 = this->m_hashNext[v2];
    if ( v2 < 0 )
      return &this->m_dummyNode;
  }
  return &m_nodes[v2];
}

// File Line: 68
// RVA: 0xBFE790
void __fastcall hkaiHashSearchState::setStorage(hkaiHashSearchState *this, char *storage, int size)
{
  hkaiSearchStateNode *v4; // r10
  unsigned __int64 v5; // rdx
  int v6; // edi
  __int16 *m_hashFirst; // rcx
  __int64 v8; // rdx
  int v9; // eax
  __int16 *m_hashNext; // rdi
  __int64 i; // rcx

  if ( size > 512 )
  {
    this->m_hashFirst = (__int16 *)storage;
    v4 = (hkaiSearchStateNode *)(storage + 512);
    v5 = (size - 512) / 0x12ui64;
    if ( (v5 & 0x80000000) == 0i64 )
    {
      if ( (int)v5 > 0x8000 )
        LODWORD(v5) = 0x8000;
    }
    else
    {
      LODWORD(v5) = 0;
    }
    this->m_nodeCapacity = v5;
    v6 = 2 * v5;
    this->m_nodes = v4;
    this->m_hashNext = (__int16 *)&v4[(int)v5];
    m_hashFirst = this->m_hashFirst;
    if ( m_hashFirst )
    {
      v8 = 8i64;
      do
      {
        *(_QWORD *)m_hashFirst = -1i64;
        *((_QWORD *)m_hashFirst + 1) = -1i64;
        *((_QWORD *)m_hashFirst + 2) = -1i64;
        m_hashFirst += 32;
        *((_QWORD *)m_hashFirst - 5) = -1i64;
        *((_QWORD *)m_hashFirst - 4) = -1i64;
        *((_QWORD *)m_hashFirst - 3) = -1i64;
        *((_QWORD *)m_hashFirst - 2) = -1i64;
        *((_QWORD *)m_hashFirst - 1) = -1i64;
        --v8;
      }
      while ( v8 );
      v9 = v6 / 4 - 1;
      if ( v9 >= 0 )
      {
        m_hashNext = this->m_hashNext;
        for ( i = (unsigned int)(v9 + 1); i; --i )
        {
          *(_DWORD *)m_hashNext = -1;
          m_hashNext += 2;
        }
      }
    }
  }
}

