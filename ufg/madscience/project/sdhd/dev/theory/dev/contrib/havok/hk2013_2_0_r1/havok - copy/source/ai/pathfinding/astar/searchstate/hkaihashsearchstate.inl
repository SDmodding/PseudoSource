// File Line: 237
// RVA: 0xC00A40
_BOOL8 __fastcall hkaiHashSearchState::setStartNode<hkaiHierarchicalNavMeshHeuristic>(
        hkaiHashSearchState *this,
        hkaiHierarchicalNavMeshHeuristic *heuristic,
        unsigned int sid,
        float initialCost)
{
  hkaiSearchStateNode *NodeState; // rsi
  float v8; // xmm0_4

  NodeState = hkaiHashSearchState::getNodeState(this, sid);
  NodeState->m_gCost = initialCost;
  v8 = hkaiHierarchicalNavMeshHeuristic::getHeuristic(heuristic, sid);
  NodeState->m_hCost = v8;
  NodeState->m_flags.m_storage |= 5u;
  if ( v8 < this->m_bestNodeCost )
  {
    this->m_bestNodeCost = v8;
    this->m_bestNode = sid;
  }
  return NodeState->m_hCost < 3.40282e38;
}

// File Line: 255
// RVA: 0xC03540
void __fastcall hkaiHashSearchState::setCost<hkaiHierarchicalGraphHeuristic>(
        hkaiHashSearchState *this,
        hkaiHierarchicalGraphHeuristic *heuristic,
        unsigned int sid,
        float d)
{
  hkaiSearchStateNode *m_currentNodeState; // rsi
  bool v6; // zf
  float v8; // xmm0_4

  m_currentNodeState = this->m_currentNodeState;
  v6 = (m_currentNodeState->m_flags.m_storage & 3) == 0;
  m_currentNodeState->m_gCost = d;
  if ( v6 )
  {
    v8 = hkaiHierarchicalGraphHeuristic::getHeuristic(heuristic, sid);
    m_currentNodeState->m_hCost = v8;
    if ( v8 < this->m_bestNodeCost )
    {
      this->m_bestNodeCost = v8;
      this->m_bestNode = sid;
    }
  }
}

