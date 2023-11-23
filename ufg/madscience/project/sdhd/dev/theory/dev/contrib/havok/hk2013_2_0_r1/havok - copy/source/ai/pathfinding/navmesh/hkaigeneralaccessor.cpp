// File Line: 13
// RVA: 0xBD4960
hkaiNavMesh::Edge *__fastcall hkaiGeneralAccessor::getEdgeFromPacked(hkaiGeneralAccessor *this, unsigned int edgeKey)
{
  hkaiGeneralAccessor::setSection(this, edgeKey >> 22);
  return hkaiNavMeshInstance_get_hkaiNavMesh::Edge__5(
           this->m_accessor->m_originalEdges,
           this->m_accessor->m_numOriginalEdges,
           &this->m_accessor->m_instancedEdges,
           &this->m_accessor->m_ownedEdges,
           &this->m_accessor->m_edgeMap,
           edgeKey & 0x3FFFFF);
}

// File Line: 19
// RVA: 0xBD49C0
hkaiNavMesh::Edge *__fastcall hkaiGeneralAccessor::getEdgeAndDataPtrFromPacked(
        hkaiGeneralAccessor *this,
        unsigned int edgeKey,
        const int **edgeDataOut)
{
  hkaiGeneralAccessor::setSection(this, edgeKey >> 22);
  return hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__0(
           this->m_accessor->m_originalEdges,
           this->m_accessor->m_numOriginalEdges,
           &this->m_accessor->m_instancedEdges,
           &this->m_accessor->m_ownedEdges,
           this->m_accessor->m_originalEdgeData,
           &this->m_accessor->m_instancedEdgeData,
           &this->m_accessor->m_ownedEdgeData,
           &this->m_accessor->m_edgeMap,
           edgeKey & 0x3FFFFF,
           this->m_accessor->m_edgeDataStriding,
           edgeDataOut);
}

// File Line: 25
// RVA: 0xBD4AC0
hkaiNavMesh::Face *__fastcall hkaiGeneralAccessor::getFaceFromPacked(hkaiGeneralAccessor *this, unsigned int faceKey)
{
  hkaiGeneralAccessor::setSection(this, faceKey >> 22);
  return hkaiNavMeshInstance_get_hkaiNavMesh::Face__5(
           this->m_accessor->m_originalFaces,
           this->m_accessor->m_numOriginalFaces,
           &this->m_accessor->m_instancedFaces,
           &this->m_accessor->m_ownedFaces,
           &this->m_accessor->m_faceMap,
           faceKey & 0x3FFFFF);
}

// File Line: 31
// RVA: 0xBD4940
void __fastcall hkaiGeneralAccessor::setSection(hkaiGeneralAccessor *this, int section)
{
  hkaiNavMeshInstance *m_instancePtr; // r8

  m_instancePtr = this->m_sectionInfo[section].m_instancePtr;
  this->m_currentSection = section;
  this->m_accessor = m_instancePtr;
}

// File Line: 47
// RVA: 0xBD4A60
hkaiNavMesh::Edge *__fastcall hkaiGeneralAccessor::getEdgeAndVertsFromPacked(
        hkaiGeneralAccessor *this,
        unsigned int edgeKey,
        hkVector4f *edgeAOut,
        hkVector4f *edgeBOut,
        const int **edgeDataOut)
{
  hkaiNavMesh::Edge *EdgeAndDataPtrFromPacked; // rbx

  EdgeAndDataPtrFromPacked = hkaiGeneralAccessor::getEdgeAndDataPtrFromPacked(this, edgeKey, edgeDataOut);
  hkaiNavMeshInstance::getEdgePoints(this->m_accessor, EdgeAndDataPtrFromPacked, edgeAOut, edgeBOut);
  return EdgeAndDataPtrFromPacked;
}

