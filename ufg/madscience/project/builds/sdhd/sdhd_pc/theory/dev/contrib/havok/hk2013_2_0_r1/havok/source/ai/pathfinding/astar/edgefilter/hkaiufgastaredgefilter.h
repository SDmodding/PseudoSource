// File Line: 17
// RVA: 0xE65E0
void __fastcall hkaiUFGAStarEdgeFilter::~hkaiUFGAStarEdgeFilter(hkaiUFGAStarEdgeFilter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiUFGAStarEdgeFilter::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAstarEdgeFilter::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 20
// RVA: 0xF5800
bool __fastcall hkaiUFGAStarEdgeFilter::isEnabled(
        hkaiUFGAStarEdgeFilter *this,
        hkaiAstarEdgeFilter::NavMeshIsEnabledCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *m_edgeFaceInfo; // r8
  hkaiAgentTraversalInfo *m_agentInfo; // r9
  bool result; // al
  hkaiNavMesh::Edge *m_edge; // rcx
  hkaiNavMesh::Edge *v6; // rax

  m_edgeFaceInfo = context->m_edgeFaceInfo;
  m_agentInfo = context->m_agentInfo;
  result = 0;
  if ( !m_edgeFaceInfo->m_face || (BYTE1(m_agentInfo->m_filterInfo) & *(_BYTE *)m_edgeFaceInfo->m_faceData) != 0 )
  {
    m_edge = m_edgeFaceInfo->m_incomingEdgeInfo.m_edge;
    v6 = m_edgeFaceInfo->m_outgoingEdgeInfo.m_edge;
    if ( (m_agentInfo->m_filterInfo & 1) != 0
      || (!m_edge || (m_edge->m_flags.m_storage & 0x10) == 0) && (!v6 || (v6->m_flags.m_storage & 0x10) == 0) )
    {
      return 1;
    }
  }
  return result;
}

