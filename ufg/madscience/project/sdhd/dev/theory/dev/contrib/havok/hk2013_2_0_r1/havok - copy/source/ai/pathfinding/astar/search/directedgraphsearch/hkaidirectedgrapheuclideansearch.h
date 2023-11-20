// File Line: 57
// RVA: 0xC20F10
signed __int64 __fastcall hkaiDirectedGraphEuclideanSearch::getParent(hkaiDirectedGraphEuclideanSearch *this, unsigned int nid)
{
  hkaiHashSearchState *v2; // rbx
  __int16 v3; // cx
  signed __int64 result; // rax

  v2 = &this->m_state;
  v3 = hkaiHashSearchState::getNodeStateRO(&this->m_state, nid)->m_parentIndex;
  if ( v3 == -1 )
    result = 0xFFFFFFFFi64;
  else
    result = v2->m_nodes[v3].m_index;
  return result;
}

// File Line: 68
// RVA: 0xC20E00
float __fastcall hkaiDirectedGraphEuclideanSearch::getCost(hkaiDirectedGraphEuclideanSearch *this, int nid)
{
  hkaiDirectedGraphEuclideanSearch *v2; // rdi
  hkaiSearchStateNode *v3; // rax

  v2 = this;
  v3 = hkaiHashSearchState::getNodeState(&this->m_state, nid);
  v2->m_state.m_currentNodeState = v3;
  v2->m_state.m_parentNodeState = v3;
  v2->m_state.m_parentIndex = (signed __int16)((signed __int64)(unsigned int)((_DWORD)v3 - LODWORD(v2->m_state.m_nodes)) >> 4);
  return v3->m_gCost;
}

