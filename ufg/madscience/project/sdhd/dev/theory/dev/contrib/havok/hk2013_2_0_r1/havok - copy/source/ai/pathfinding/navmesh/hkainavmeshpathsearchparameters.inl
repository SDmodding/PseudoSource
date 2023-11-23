// File Line: 34
// RVA: 0xC085A0
_BOOL8 __fastcall hkaiNavMeshPathSearchParameters::operator==(
        hkaiNavMeshPathSearchParameters *this,
        hkaiNavMeshPathSearchParameters *o)
{
  return this->m_costModifier == o->m_costModifier
      && this->m_edgeFilter == o->m_edgeFilter
      && (this->m_validateInputs.m_bool != 0) == (o->m_validateInputs.m_bool != 0)
      && o->m_outputPathFlags.m_storage == this->m_outputPathFlags.m_storage
      && o->m_lineOfSightFlags.m_storage == this->m_lineOfSightFlags.m_storage
      && (this->m_useHierarchicalHeuristic.m_bool != 0) == (o->m_useHierarchicalHeuristic.m_bool != 0)
      && (this->m_projectedRadiusCheck.m_bool != 0) == (o->m_projectedRadiusCheck.m_bool != 0)
      && o->m_heuristicWeight == this->m_heuristicWeight
      && this->m_userEdgeTraversalTestType.m_storage == o->m_userEdgeTraversalTestType.m_storage
      && (this->m_useGrandparentDistanceCalculation.m_bool != 0) == (o->m_useGrandparentDistanceCalculation.m_bool != 0)
      && o->m_simpleRadiusThreshold == this->m_simpleRadiusThreshold
      && o->m_maximumPathLength == this->m_maximumPathLength
      && o->m_searchSphereRadius == this->m_searchSphereRadius
      && o->m_searchCapsuleRadius == this->m_searchCapsuleRadius
      && this->m_bufferSizes.m_maxOpenSetSizeBytes == o->m_bufferSizes.m_maxOpenSetSizeBytes
      && this->m_bufferSizes.m_maxSearchStateSizeBytes == o->m_bufferSizes.m_maxSearchStateSizeBytes
      && this->m_hierarchyBufferSizes.m_maxOpenSetSizeBytes == o->m_hierarchyBufferSizes.m_maxOpenSetSizeBytes
      && this->m_hierarchyBufferSizes.m_maxSearchStateSizeBytes == o->m_hierarchyBufferSizes.m_maxSearchStateSizeBytes;
}

