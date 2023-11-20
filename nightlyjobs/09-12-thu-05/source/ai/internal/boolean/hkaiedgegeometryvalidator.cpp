// File Line: 12
// RVA: 0xBA9780
void __fastcall hkaiEdgeGeometryValidator::clear(hkaiEdgeGeometryValidator *this)
{
  hkaiEdgeGeometryValidator *v1; // rbx

  v1 = this;
  hkaiFaceEdges::clear(&this->m_faceEdges);
  v1->m_vertexIndexMap.m_size = 0;
  v1->m_faceIndices.m_size = 0;
  v1->m_indicesCount.m_size = 0;
}

