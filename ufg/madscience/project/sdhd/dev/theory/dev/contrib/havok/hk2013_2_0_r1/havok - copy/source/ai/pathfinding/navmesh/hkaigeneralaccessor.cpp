// File Line: 13
// RVA: 0xBD4960
hkaiNavMesh::Edge *__fastcall hkaiGeneralAccessor::getEdgeFromPacked(hkaiGeneralAccessor *this, unsigned int edgeKey)
{
  unsigned int v2; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> **v3; // rbx

  v2 = edgeKey;
  v3 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> **)this;
  hkaiGeneralAccessor::setSection(this, edgeKey >> 22);
  return hkaiNavMeshInstance_get_hkaiNavMesh::Edge__5(
           (*v3)[2].m_data,
           (*v3)[2].m_size,
           *v3 + 16,
           *v3 + 18,
           (hkArray<int,hkContainerHeapAllocator> *)&(*v3)[13],
           v2 & 0x3FFFFF);
}

// File Line: 19
// RVA: 0xBD49C0
hkaiNavMesh::Edge *__fastcall hkaiGeneralAccessor::getEdgeAndDataPtrFromPacked(hkaiGeneralAccessor *this, unsigned int edgeKey, const int **edgeDataOut)
{
  unsigned int v3; // esi
  const int **dataPtrOut; // rdi
  hkArray<int,hkContainerHeapAllocator> **v5; // rbx

  v3 = edgeKey;
  dataPtrOut = edgeDataOut;
  v5 = (hkArray<int,hkContainerHeapAllocator> **)this;
  hkaiGeneralAccessor::setSection(this, edgeKey >> 22);
  return hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__0(
           (hkaiNavMesh::Edge *)(*v5)[2].m_data,
           (*v5)[2].m_size,
           (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v5)[16],
           (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v5)[18],
           (*v5)[5].m_data,
           *v5 + 23,
           *v5 + 25,
           *v5 + 13,
           v3 & 0x3FFFFF,
           (*v5)[5].m_size,
           dataPtrOut);
}

// File Line: 25
// RVA: 0xBD4AC0
hkaiNavMesh::Face *__fastcall hkaiGeneralAccessor::getFaceFromPacked(hkaiGeneralAccessor *this, unsigned int faceKey)
{
  unsigned int v2; // edi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> **v3; // rbx

  v2 = faceKey;
  v3 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> **)this;
  hkaiGeneralAccessor::setSection(this, faceKey >> 22);
  return hkaiNavMeshInstance_get_hkaiNavMesh::Face__5(
           (*v3)[1].m_data,
           (*v3)[1].m_size,
           *v3 + 15,
           *v3 + 17,
           (hkArray<int,hkContainerHeapAllocator> *)&(*v3)[14],
           v2 & 0x3FFFFF);
}

// File Line: 31
// RVA: 0xBD4940
void __fastcall hkaiGeneralAccessor::setSection(hkaiGeneralAccessor *this, int section)
{
  hkaiNavMeshInstance *v2; // r8

  v2 = this->m_sectionInfo[section].m_instancePtr;
  this->m_currentSection = section;
  this->m_accessor = v2;
}

// File Line: 47
// RVA: 0xBD4A60
hkaiNavMesh::Edge *__fastcall hkaiGeneralAccessor::getEdgeAndVertsFromPacked(hkaiGeneralAccessor *this, unsigned int edgeKey, hkVector4f *edgeAOut, hkVector4f *edgeBOut, const int **edgeDataOut)
{
  hkVector4f *v5; // rsi
  hkVector4f *v6; // rdi
  hkaiGeneralAccessor *v7; // r14
  hkaiNavMesh::Edge *v8; // rbx

  v5 = edgeAOut;
  v6 = edgeBOut;
  v7 = this;
  v8 = hkaiGeneralAccessor::getEdgeAndDataPtrFromPacked(this, edgeKey, edgeDataOut);
  hkaiNavMeshInstance::getEdgePoints(v7->m_accessor, v8, v5, v6);
  return v8;
}

