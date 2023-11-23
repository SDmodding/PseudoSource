// File Line: 12
// RVA: 0xBA9780
void __fastcall hkaiEdgeGeometryValidator::clear(hkaiEdgeGeometryValidator *this)
{
  hkaiFaceEdges::clear(&this->m_faceEdges);
  this->m_vertexIndexMap.m_size = 0;
  this->m_faceIndices.m_size = 0;
  this->m_indicesCount.m_size = 0;
}

