// File Line: 57
// RVA: 0xC20F10
__int64 __fastcall hkaiDirectedGraphEuclideanSearch::getParent(
        hkaiDirectedGraphEuclideanSearch *this,
        unsigned int nid)
{
  hkaiHashSearchState *p_m_state; // rbx
  __int16 m_parentIndex; // cx

  p_m_state = &this->m_state;
  m_parentIndex = hkaiHashSearchState::getNodeStateRO(&this->m_state, nid)->m_parentIndex;
  if ( m_parentIndex == -1 )
    return 0xFFFFFFFFi64;
  else
    return p_m_state->m_nodes[m_parentIndex].m_index;
}

// File Line: 68
// RVA: 0xC20E00
float __fastcall hkaiDirectedGraphEuclideanSearch::getCost(hkaiDirectedGraphEuclideanSearch *this, unsigned int nid)
{
  hkaiSearchStateNode *NodeState; // rax

  NodeState = hkaiHashSearchState::getNodeState(&this->m_state, nid);
  this->m_state.m_currentNodeState = NodeState;
  this->m_state.m_parentNodeState = NodeState;
  this->m_state.m_parentIndex = (__int16)((__int64)(unsigned int)((_DWORD)NodeState - LODWORD(this->m_state.m_nodes)) >> 4);
  return NodeState->m_gCost;
}

