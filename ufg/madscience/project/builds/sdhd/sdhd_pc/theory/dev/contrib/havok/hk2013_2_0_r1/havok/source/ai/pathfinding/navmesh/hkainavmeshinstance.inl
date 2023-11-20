// File Line: 184
// RVA: 0xF5100
hkaiNavMesh::Face *__fastcall hkaiNavMeshInstance::getFace(hkaiNavMeshInstance *this, int fIdx)
{
  int v2; // eax
  hkaiNavMesh::Face *result; // rax
  int v4; // er9

  v2 = this->m_numOriginalFaces;
  if ( fIdx >= v2 )
    return &this->m_ownedFaces.m_data[fIdx - v2];
  if ( this->m_faceMap.m_size )
    v4 = this->m_faceMap.m_data[fIdx];
  else
    v4 = fIdx;
  if ( v4 == -1 )
    result = &this->m_originalFaces[fIdx];
  else
    result = &this->m_instancedFaces.m_data[v4];
  return result;
}

// File Line: 311
// RVA: 0xF4FC0
void __fastcall hkaiNavMeshInstance::getEdgePoints(hkaiNavMeshInstance *this, int eIdx, hkVector4f *edgeA, hkVector4f *edgeB)
{
  int v4; // eax
  hkVector4f *v5; // r11
  hkaiNavMeshInstance *v6; // r10
  hkaiNavMesh::Edge *v7; // rcx
  int v8; // er8
  signed __int64 v9; // rcx
  hkaiNavMesh::Edge *v10; // rax
  __int64 v11; // rax
  signed int v12; // edx
  __m128 *v13; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __int64 v17; // rax
  __m128 v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm3
  __m128 *v21; // rax
  __m128 v22; // xmm1

  v4 = this->m_numOriginalEdges;
  v5 = edgeA;
  v6 = this;
  if ( eIdx < v4 )
  {
    if ( this->m_edgeMap.m_size )
      v8 = this->m_edgeMap.m_data[eIdx];
    else
      v8 = eIdx;
    if ( v8 == -1 )
    {
      v9 = eIdx;
      v10 = v6->m_originalEdges;
    }
    else
    {
      v9 = v8;
      v10 = v6->m_instancedEdges.m_data;
    }
    v7 = &v10[v9];
  }
  else
  {
    v7 = &this->m_ownedEdges.m_data[eIdx - v4];
  }
  v11 = v7->m_a;
  v12 = v6->m_numOriginalVertices;
  if ( (signed int)v11 >= v12 )
    v13 = &v6->m_ownedVertices.m_data[(signed int)v11 - v12].m_quad;
  else
    v13 = &v6->m_originalVertices[v11].m_quad;
  v14 = *v13;
  v15 = v6->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
  v16 = v6->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
  v17 = v7->m_b;
  v18 = v6->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
  v19 = v6->m_referenceFrame.m_transform.m_translation.m_quad;
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v16), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v15)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v18)),
          v19);
  if ( (signed int)v17 >= v12 )
    v21 = &v6->m_ownedVertices.m_data[(signed int)v17 - v12].m_quad;
  else
    v21 = &v6->m_originalVertices[v17].m_quad;
  v22 = *v21;
  *v5 = (hkVector4f)v20;
  edgeB->m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v16),
                        _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v15)),
                      _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v18)),
                    v19);
}

// File Line: 323
// RVA: 0xF4EE0
void __fastcall hkaiNavMeshInstance::getEdgePoints(hkaiNavMeshInstance *this, hkaiNavMesh::Edge *edge, hkVector4f *edgeA, hkVector4f *edgeB)
{
  __int64 v4; // rax
  int v5; // er10
  hkVector4f *v6; // rax
  __m128 v7; // xmm1
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm5
  __int64 v10; // rax
  hkVector4f v11; // xmm6
  hkVector4f v12; // xmm7
  hkVector4f v13; // xmm3
  hkVector4f *v14; // rax
  __m128 v15; // xmm1

  v4 = edge->m_a;
  v5 = this->m_numOriginalVertices;
  if ( (signed int)v4 >= v5 )
    v6 = &this->m_ownedVertices.m_data[(signed int)v4 - v5];
  else
    v6 = &this->m_originalVertices[v4];
  v7 = v6->m_quad;
  v8.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col1;
  v9.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col0;
  v10 = edge->m_b;
  v11.m_quad = (__m128)this->m_referenceFrame.m_transform.m_rotation.m_col2;
  v12.m_quad = (__m128)this->m_referenceFrame.m_transform.m_translation;
  v13.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v9.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v8.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v11.m_quad)),
                 v12.m_quad);
  if ( (signed int)v10 >= v5 )
    v14 = &this->m_ownedVertices.m_data[(signed int)v10 - v5];
  else
    v14 = &this->m_originalVertices[v10];
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

