// File Line: 34
// RVA: 0xC085A0
_BOOL8 __fastcall hkaiNavMeshPathSearchParameters::operator==(hkaiNavMeshPathSearchParameters *this, hkaiNavMeshPathSearchParameters *o)
{
  return *(_OWORD *)&this->m_costModifier == *(_OWORD *)&o->m_costModifier
      && (this->m_validateInputs.m_bool != 0) == (o->m_validateInputs.m_bool != 0)
      && *(_WORD *)&o->m_outputPathFlags.m_storage == *(_WORD *)&this->m_outputPathFlags.m_storage
      && (this->m_useHierarchicalHeuristic.m_bool != 0) == (o->m_useHierarchicalHeuristic.m_bool != 0)
      && (this->m_projectedRadiusCheck.m_bool != 0) == (o->m_projectedRadiusCheck.m_bool != 0)
      && o->m_heuristicWeight == this->m_heuristicWeight
      && this->m_userEdgeTraversalTestType.m_storage == o->m_userEdgeTraversalTestType.m_storage
      && (this->m_useGrandparentDistanceCalculation.m_bool != 0) == (o->m_useGrandparentDistanceCalculation.m_bool != 0)
      && o->m_simpleRadiusThreshold == this->m_simpleRadiusThreshold
      && o->m_maximumPathLength == this->m_maximumPathLength
      && o->m_searchSphereRadius == this->m_searchSphereRadius
      && o->m_searchCapsuleRadius == this->m_searchCapsuleRadius
      && *(_OWORD *)&this->m_bufferSizes.m_maxOpenSetSizeBytes == *(_OWORD *)&o->m_bufferSizes.m_maxOpenSetSizeBytes;
}

