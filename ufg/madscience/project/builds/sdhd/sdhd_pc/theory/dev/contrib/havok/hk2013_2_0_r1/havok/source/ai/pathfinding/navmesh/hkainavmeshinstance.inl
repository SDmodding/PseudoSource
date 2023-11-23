// File Line: 184
// RVA: 0xF5100
hkaiNavMesh::Face *__fastcall hkaiNavMeshInstance::getFace(hkaiNavMeshInstance *this, int fIdx)
{
  int m_numOriginalFaces; // eax
  int v4; // r9d

  m_numOriginalFaces = this->m_numOriginalFaces;
  if ( fIdx >= m_numOriginalFaces )
    return &this->m_ownedFaces.m_data[fIdx - m_numOriginalFaces];
  if ( this->m_faceMap.m_size )
    v4 = this->m_faceMap.m_data[fIdx];
  else
    v4 = fIdx;
  if ( v4 == -1 )
    return &this->m_originalFaces[fIdx];
  else
    return &this->m_instancedFaces.m_data[v4];
}

// File Line: 311
// RVA: 0xF4FC0
void __fastcall hkaiNavMeshInstance::getEdgePoints(
        hkaiNavMeshInstance *this,
        int eIdx,
        hkVector4f *edgeA,
        hkVector4f *edgeB)
{
  int m_numOriginalEdges; // eax
  hkaiNavMesh::Edge *v7; // rcx
  int v8; // r8d
  __int64 v9; // rcx
  hkaiNavMesh::Edge *m_originalEdges; // rax
  __int64 m_a; // rax
  int m_numOriginalVertices; // edx
  hkVector4f *v13; // rax
  __m128 m_quad; // xmm1
  hkVector4f v15; // xmm4
  hkVector4f v16; // xmm5
  __int64 m_b; // rax
  hkVector4f v18; // xmm6
  hkVector4f v19; // xmm7
  hkVector4f v20; // xmm3
  hkVector4f *v21; // rax
  __m128 v22; // xmm1

  m_numOriginalEdges = this->m_numOriginalEdges;
  if ( eIdx < m_numOriginalEdges )
  {
    if ( this->m_edgeMap.m_size )
      v8 = this->m_edgeMap.m_data[eIdx];
    else
      v8 = eIdx;
    if ( v8 == -1 )
    {
      v9 = eIdx;
      m_originalEdges = this->m_originalEdges;
    }
    else
    {
      v9 = v8;
      m_originalEdges = this->m_instancedEdges.m_data;
    }
    v7 = &m_originalEdges[v9];
  }
  else
  {
    v7 = &this->m_ownedEdges.m_data[eIdx - m_numOriginalEdges];
  }
  m_a = v7->m_a;
  m_numOriginalVertices = this->m_numOriginalVertices;
  if ( (int)m_a >= m_numOriginalVertices )
    v13 = &this->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
  else
    v13 = &this->m_originalVertices[m_a];
  m_quad = v13->m_quad;
  v15.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col1;
  v16.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col0;
  m_b = v7->m_b;
  v18.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col2;
  v19.m_quad = (__m128)this->m_referenceFrame.m_transform.m_translation;
  v20.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v16.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v15.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v18.m_quad)),
                 v19.m_quad);
  if ( (int)m_b >= m_numOriginalVertices )
    v21 = &this->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
  else
    v21 = &this->m_originalVertices[m_b];
  v22 = v21->m_quad;
  *edgeA = (hkVector4f)v20.m_quad;
  edgeB->m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v16.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v15.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v18.m_quad)),
                    v19.m_quad);
}

// File Line: 323
// RVA: 0xF4EE0
void __fastcall hkaiNavMeshInstance::getEdgePoints(
        hkaiNavMeshInstance *this,
        hkaiNavMesh::Edge *edge,
        hkVector4f *edgeA,
        hkVector4f *edgeB)
{
  __int64 m_a; // rax
  int m_numOriginalVertices; // r10d
  hkVector4f *v6; // rax
  __m128 m_quad; // xmm1
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm5
  __int64 m_b; // rax
  hkVector4f v11; // xmm6
  hkVector4f v12; // xmm7
  hkVector4f v13; // xmm3
  hkVector4f *v14; // rax
  __m128 v15; // xmm1

  m_a = edge->m_a;
  m_numOriginalVertices = this->m_numOriginalVertices;
  if ( (int)m_a >= m_numOriginalVertices )
    v6 = &this->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
  else
    v6 = &this->m_originalVertices[m_a];
  m_quad = v6->m_quad;
  v8.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col1;
  v9.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col0;
  m_b = edge->m_b;
  v11.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col2;
  v12.m_quad = (__m128)this->m_referenceFrame.m_transform.m_translation;
  v13.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v9.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v8.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v11.m_quad)),
                 v12.m_quad);
  if ( (int)m_b >= m_numOriginalVertices )
    v14 = &this->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
  else
    v14 = &this->m_originalVertices[m_b];
  v15 = v14->m_quad;
  *edgeA = (hkVector4f)v13.m_quad;
  edgeB->m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v9.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v8.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v11.m_quad)),
                    v12.m_quad);
}

