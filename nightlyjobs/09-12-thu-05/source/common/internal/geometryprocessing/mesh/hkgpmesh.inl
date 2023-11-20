// File Line: 237
// RVA: 0xCDC230
void __fastcall hkgpMesh::TriangleShape::getSupportingVertex(hkgpMesh::TriangleShape *this, hkVector4f *direction, hkVector4f *out)
{
  __m128 v3; // xmm3
  hkgpMeshBase::Triangle *v4; // r9
  __m128 v5; // xmm4
  hkgpMeshBase::Vertex *v6; // rax
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  int v14; // edx
  __m128 v15; // [rsp+0h] [rbp-38h]
  __m128 v16; // [rsp+10h] [rbp-28h]
  __m128 v17; // [rsp+20h] [rbp-18h]

  v3 = direction->m_quad;
  v4 = this->m_triangle;
  v5 = direction->m_quad;
  v6 = v4->m_vertices[1];
  v15 = v4->m_vertices[0]->m_position.m_quad;
  v7 = _mm_mul_ps(v5, v15);
  v8 = v4->m_vertices[2]->m_position.m_quad;
  v16 = v6->m_position.m_quad;
  v9 = _mm_mul_ps(v3, v16);
  v10 = _mm_mul_ps(v3, v8);
  v17 = v8;
  v11 = _mm_unpacklo_ps(v7, v9);
  v12 = _mm_movelh_ps(v11, v10);
  v13 = _mm_add_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(v7, v9), v10, 228),
          _mm_add_ps(v12, _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10, 212)));
  LODWORD(v6) = _mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmpleps(
                      _mm_max_ps(
                        _mm_shuffle_ps(v13, v13, 170),
                        _mm_max_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0))),
                      v13),
                    (__m128)xmmword_141A79E80));
  v14 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[(signed int)v6];
  *out = *((hkVector4f *)&v15 + (unsigned __int8)hkVector4Comparison_maskToLastIndex[(signed int)v6]);
  out->m_quad.m128_i32[3] = v14 | 0x3F000000;
}

// File Line: 248
// RVA: 0xCDBFE0
hkAabb *__fastcall hkgpMesh::TriangleShape::getBoundingBox(hkgpMesh::TriangleShape *this, hkAabb *result)
{
  hkgpMeshBase::Triangle *v2; // r8
  hkAabb *v3; // rbx
  hkVector4f vertexArray; // [rsp+20h] [rbp-38h]
  __int128 v6; // [rsp+30h] [rbp-28h]
  __int128 v7; // [rsp+40h] [rbp-18h]

  v2 = this->m_triangle;
  v3 = result;
  _mm_store_si128((__m128i *)&vertexArray, (__m128i)v2->m_vertices[0]->m_position.m_quad);
  _mm_store_si128((__m128i *)&v6, (__m128i)v2->m_vertices[1]->m_position.m_quad);
  _mm_store_si128((__m128i *)&v7, (__m128i)v2->m_vertices[2]->m_position.m_quad);
  hkAabbUtil::calcAabb(&vertexArray, 3, result);
  return v3;
}

// File Line: 257
// RVA: 0xCDBFB0
hkAabb *__fastcall hkgpMesh::ExternShape::getBoundingBox(hkgpMesh::ExternShape *this, hkAabb *result)
{
  hkAabb *v2; // rbx

  v2 = result;
  hkAabbUtil::calcAabb(this->m_vertices, this->m_numVertices, result);
  return v2;
}

// File Line: 265
// RVA: 0xCDC1A0
void __fastcall hkgpMesh::ExternShape::getSupportingVertex(hkgpMesh::ExternShape *this, hkVector4f *direction, hkVector4f *out)
{
  __m128 v3; // xmm4
  hkVector4f *v4; // r10
  int v5; // edx
  signed int v6; // eax
  signed int v7; // er9
  __m128 v8; // xmm1
  float v9; // xmm3_4
  __m128 *v10; // rcx
  __m128 v11; // xmm1
  float v12; // xmm2_4

  v3 = direction->m_quad;
  v4 = this->m_vertices;
  v5 = this->m_numVertices;
  v6 = 1;
  v7 = 0;
  v8 = _mm_mul_ps(v4->m_quad, v3);
  v9 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
     + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170));
  if ( v5 > 1 )
  {
    v10 = &v4[1].m_quad;
    do
    {
      v11 = _mm_mul_ps(*v10, v3);
      v12 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
      if ( v12 > v9 )
      {
        v9 = v12;
        v7 = v6;
      }
      ++v6;
      ++v10;
    }
    while ( v6 < v5 );
  }
  *out = v4[v7];
  out->m_quad.m128_i32[3] = v7 | 0x3F000000;
}

