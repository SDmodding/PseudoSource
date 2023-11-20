// File Line: 17
// RVA: 0xE65E0
void __fastcall hkaiUFGAStarEdgeFilter::~hkaiUFGAStarEdgeFilter(hkaiUFGAStarEdgeFilter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiUFGAStarEdgeFilter::`vftable';
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAstarEdgeFilter::`vftable';
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 20
// RVA: 0xF5800
bool __fastcall hkaiUFGAStarEdgeFilter::isEnabled(hkaiUFGAStarEdgeFilter *this, hkaiAstarEdgeFilter::NavMeshIsEnabledCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *v2; // r8
  hkaiAgentTraversalInfo *v3; // r9
  bool result; // al
  hkaiNavMesh::Edge *v5; // rcx
  hkaiNavMesh::Edge *v6; // rax

  v2 = context->m_edgeFaceInfo;
  v3 = context->m_agentInfo;
  result = 0;
  if ( !v2->m_face || BYTE1(v3->m_filterInfo) & *(_BYTE *)v2->m_faceData )
  {
    v5 = v2->m_incomingEdgeInfo.m_edge;
    v6 = v2->m_outgoingEdgeInfo.m_edge;
    if ( v3->m_filterInfo & 1 || (!v5 || !(v5->m_flags.m_storage & 0x10)) && (!v6 || !(v6->m_flags.m_storage & 0x10)) )
      result = 1;
  }
  return result;
}

