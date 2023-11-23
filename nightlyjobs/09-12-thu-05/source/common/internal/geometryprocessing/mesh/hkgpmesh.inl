// File Line: 237
// RVA: 0xCDC230
void __fastcall hkgpMesh::TriangleShape::getSupportingVertex(
        hkgpMesh::TriangleShape *this,
        hkVector4f *direction,
        hkVector4f *out)
{
  __m128 m_quad; // xmm3
  hkgpMeshBase::Triangle *m_triangle; // r9
  __m128 v5; // xmm4
  __m128 *v6; // rax
  __m128 v7; // xmm2
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __int64 v15; // rcx
  int v16; // edx
  __m128 v17; // [rsp+0h] [rbp-38h]
  __m128 v18; // [rsp+10h] [rbp-28h]
  __m128 v19; // [rsp+20h] [rbp-18h]

  m_quad = direction->m_quad;
  m_triangle = this->m_triangle;
  v5 = direction->m_quad;
  v6 = (__m128 *)m_triangle->m_vertices[1];
  v17 = m_triangle->m_vertices[0]->m_position.m_quad;
  v7 = m_triangle->m_vertices[2]->m_position.m_quad;
  v18 = v6[2];
  v8 = _mm_mul_ps(m_quad, v18);
  v9 = _mm_mul_ps(m_quad, v7);
  v19 = v7;
  v10 = _mm_mul_ps(v5, v17);
  v11 = _mm_unpackhi_ps(v10, v8);
  v12 = _mm_unpacklo_ps(v10, v8);
  v13 = _mm_movelh_ps(v12, v9);
  v14 = _mm_add_ps(_mm_shuffle_ps(v11, v9, 228), _mm_add_ps(v13, _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v9, 212)));
  v15 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_shuffle_ps(v14, v14, 170),
                _mm_max_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0))),
              v14),
            (__m128)xmmword_141A79E80));
  v16 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v15] | 0x3F000000;
  *out = *((hkVector4f *)&v17 + (unsigned __int8)hkVector4Comparison_maskToLastIndex[v15]);
  out->m_quad.m128_i32[3] = v16;
}

// File Line: 248
// RVA: 0xCDBFE0
hkAabb *__fastcall hkgpMesh::TriangleShape::getBoundingBox(hkgpMesh::TriangleShape *this, hkAabb *result)
{
  hkgpMeshBase::Triangle *m_triangle; // r8
  hkVector4f vertexArray; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f v6; // [rsp+30h] [rbp-28h]
  hkVector4f v7; // [rsp+40h] [rbp-18h]

  m_triangle = this->m_triangle;
  vertexArray.m_quad = (__m128)m_triangle->m_vertices[0]->m_position;
  v6.m_quad = (__m128)m_triangle->m_vertices[1]->m_position;
  v7.m_quad = (__m128)m_triangle->m_vertices[2]->m_position;
  hkAabbUtil::calcAabb(&vertexArray, 3, result);
  return result;
}

// File Line: 257
// RVA: 0xCDBFB0
hkAabb *__fastcall hkgpMesh::ExternShape::getBoundingBox(hkgpMesh::ExternShape *this, hkAabb *result)
{
  hkAabbUtil::calcAabb(this->m_vertices, this->m_numVertices, result);
  return result;
}

// File Line: 265
// RVA: 0xCDC1A0
void __fastcall hkgpMesh::ExternShape::getSupportingVertex(
        hkgpMesh::ExternShape *this,
        hkVector4f *direction,
        hkVector4f *out)
{
  __m128 m_quad; // xmm4
  hkVector4f *m_vertices; // r10
  int m_numVertices; // edx
  int v6; // eax
  int v7; // r9d
  __m128 v8; // xmm1
  float v9; // xmm3_4
  __m128 *p_m_quad; // rcx
  __m128 v11; // xmm1
  float v12; // xmm2_4

  m_quad = direction->m_quad;
  m_vertices = this->m_vertices;
  m_numVertices = this->m_numVertices;
  v6 = 1;
  v7 = 0;
  v8 = _mm_mul_ps(m_vertices->m_quad, m_quad);
  v9 = (float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
     + _mm_shuffle_ps(v8, v8, 170).m128_f32[0];
  if ( m_numVertices > 1 )
  {
    p_m_quad = &m_vertices[1].m_quad;
    do
    {
      v11 = _mm_mul_ps(*p_m_quad, m_quad);
      v12 = (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
          + _mm_shuffle_ps(v11, v11, 170).m128_f32[0];
      if ( v12 > v9 )
      {
        v9 = v12;
        v7 = v6;
      }
      ++v6;
      ++p_m_quad;
    }
    while ( v6 < m_numVertices );
  }
  *out = m_vertices[v7];
  out->m_quad.m128_i32[3] = v7 | 0x3F000000;
}

