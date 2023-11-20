// File Line: 237
// RVA: 0xC00A40
bool __fastcall hkaiHashSearchState::setStartNode<hkaiHierarchicalNavMeshHeuristic>(hkaiHashSearchState *this, hkaiHierarchicalNavMeshHeuristic *heuristic, unsigned int sid, float initialCost)
{
  hkaiHierarchicalNavMeshHeuristic *v4; // rbx
  unsigned int v5; // ebp
  hkaiHashSearchState *v6; // rdi
  hkaiSearchStateNode *v7; // rsi
  float v8; // xmm0_4

  v4 = heuristic;
  v5 = sid;
  v6 = this;
  v7 = hkaiHashSearchState::getNodeState(this, sid);
  v7->m_gCost = initialCost;
  v8 = hkaiHierarchicalNavMeshHeuristic::getHeuristic(v4, v5);
  v7->m_hCost = v8;
  v7->m_flags.m_storage |= 5u;
  if ( v8 < v6->m_bestNodeCost )
  {
    v6->m_bestNodeCost = v8;
    v6->m_bestNode = v5;
  }
  return 3.40282e38 > v7->m_hCost;
}

// File Line: 255
// RVA: 0xC03540
void __fastcall hkaiHashSearchState::setCost<hkaiHierarchicalGraphHeuristic>(hkaiHashSearchState *this, hkaiHierarchicalGraphHeuristic *heuristic, unsigned int sid, float d)
{
  hkaiSearchStateNode *v4; // rsi
  unsigned int v5; // edi
  bool v6; // zf
  hkaiHashSearchState *v7; // rbx
  float v8; // xmm0_4

  v4 = this->m_currentNodeState;
  v5 = sid;
  v6 = (v4->m_flags.m_storage & 3) == 0;
  v7 = this;
  v4->m_gCost = d;
  if ( v6 )
  {
    v8 = hkaiHierarchicalGraphHeuristic::getHeuristic(heuristic, sid);
    v4->m_hCost = v8;
    if ( v8 < v7->m_bestNodeCost )
    {
      v7->m_bestNodeCost = v8;
      v7->m_bestNode = v5;
    }
  }
}

