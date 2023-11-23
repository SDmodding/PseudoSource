// File Line: 12
// RVA: 0xB86DF0
void __fastcall hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>::hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>(
        hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > *this)
{
  this->m_triangulator = 0i64;
  this->m_possibleVerts[0] = 0i64;
  this->m_possibleVerts[1] = 0i64;
}

// File Line: 19
// RVA: 0xB8B900
void __fastcall hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>::setPossibleVertsAndTriangulator(
        hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v0,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v1,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *t)
{
  this->m_possibleVerts[0] = v0;
  this->m_possibleVerts[1] = v1;
  this->m_triangulator = t;
}

// File Line: 33
// RVA: 0xB8A740
void __fastcall hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>::notifyNewVertex(
        hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *edgeStart,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *edgeEnd,
        float __formal,
        float __formala,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *newVertex)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *m_triangulator; // rax
  __m128 v7; // xmm1
  __int64 v8; // r9
  __int64 v9; // r10
  __m128 v10; // xmm1
  __m128i v11; // xmm0
  const __m128i *v12; // r8
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm8
  __m128 v19; // xmm2
  __m128 v20; // xmm2
  __m128 v21; // xmm9
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  float v29; // xmm12_4
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  float v38; // xmm11_4
  __m128 v39; // xmm3
  __m128 v40; // xmm6
  __m128 v41; // xmm1
  __m128 v42; // xmm6
  float v43; // xmm7_4
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  float v46; // xmm3_4
  __int64 v47; // rax

  m_triangulator = this->m_triangulator;
  v7 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&edgeStart->m_x));
  v8 = *((_QWORD *)edgeStart + 3) >> 2;
  v9 = *((_QWORD *)edgeEnd + 3) >> 2;
  v10 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 180), 4),
                  4);
  v11 = _mm_loadl_epi64((const __m128i *)&edgeEnd->m_x);
  v12 = (const __m128i *)this->m_possibleVerts[1];
  v13 = _mm_cvtepi32_ps(v11);
  v14 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, (__m128)0i64), 180), 4),
                  4);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), m_triangulator->m_localToWorld.m_col0.m_quad),
              m_triangulator->m_localToWorld.m_col3.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), m_triangulator->m_localToWorld.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), m_triangulator->m_localToWorld.m_col2.m_quad));
  v16 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&this->m_possibleVerts[0]->m_x));
  v17 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, (__m128)0i64), 180), 4),
                  4);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), m_triangulator->m_localToWorld.m_col0.m_quad),
              m_triangulator->m_localToWorld.m_col3.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), m_triangulator->m_localToWorld.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), m_triangulator->m_localToWorld.m_col2.m_quad));
  v19 = _mm_cvtepi32_ps(_mm_loadl_epi64(v12 + 1));
  v20 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)0i64), 180), 4),
                  4);
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), m_triangulator->m_localToWorld.m_col0.m_quad),
              m_triangulator->m_localToWorld.m_col3.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), m_triangulator->m_localToWorld.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), m_triangulator->m_localToWorld.m_col2.m_quad));
  v22 = _mm_cvtepi32_ps(_mm_loadl_epi64((const __m128i *)&newVertex->m_x));
  v23 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, (__m128)0i64), 180), 4),
                  4);
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), m_triangulator->m_localToWorld.m_col0.m_quad),
              m_triangulator->m_localToWorld.m_col3.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), m_triangulator->m_localToWorld.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), m_triangulator->m_localToWorld.m_col2.m_quad));
  v25 = _mm_sub_ps(
          v24,
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), m_triangulator->m_localToWorld.m_col0.m_quad),
                m_triangulator->m_localToWorld.m_col3.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), m_triangulator->m_localToWorld.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), m_triangulator->m_localToWorld.m_col2.m_quad)));
  v26 = _mm_mul_ps(v25, v25);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_rsqrt_ps(v27);
  v29 = _mm_andnot_ps(
          _mm_cmple_ps(v27, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v28), v28)),
              _mm_mul_ps(*(__m128 *)_xmm, v28)),
            v27)).m128_f32[0];
  v30 = _mm_sub_ps(v24, v15);
  v31 = _mm_mul_ps(v30, v30);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rsqrt_ps(v32);
  v34 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v33), v33));
  v35 = _mm_mul_ps(*(__m128 *)_xmm, v33);
  v36 = _mm_sub_ps(v24, v18);
  v37 = _mm_mul_ps(v36, v36);
  v38 = _mm_andnot_ps(_mm_cmple_ps(v32, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v34, v35), v32)).m128_f32[0];
  v39 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v40 = _mm_sub_ps(v24, v21);
  v41 = _mm_rsqrt_ps(v39);
  v42 = _mm_mul_ps(v40, v40);
  LODWORD(v43) = _mm_andnot_ps(
                   _mm_cmple_ps(v39, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v41), v41)),
                       _mm_mul_ps(*(__m128 *)_xmm, v41)),
                     v39)).m128_u32[0];
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)), _mm_shuffle_ps(v42, v42, 170));
  v45 = _mm_rsqrt_ps(v44);
  LODWORD(v46) = _mm_andnot_ps(
                   _mm_cmple_ps(v44, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v45), v45)),
                       _mm_mul_ps(v45, *(__m128 *)_xmm)),
                     v44)).m128_u32[0];
  if ( v29 >= v38 || v29 >= v43 || v29 >= v46 )
  {
    if ( v38 >= v29 || v38 >= v43 || v38 >= v46 )
    {
      if ( v43 >= v46 || v43 >= v29 || v43 >= v38 )
        v47 = v12[1].m128i_i64[1] ^ (*((_DWORD *)newVertex + 6) ^ v12[1].m128i_i32[2]) & 3;
      else
        v47 = *((_QWORD *)this->m_possibleVerts[0] + 3) ^ (*((_DWORD *)newVertex + 6) ^ *((_DWORD *)this->m_possibleVerts[0]
                                                                                        + 6)) & 3;
      *((_QWORD *)newVertex + 3) = v47;
    }
    else
    {
      *((_QWORD *)newVertex + 3) &= 3ui64;
      *((_QWORD *)newVertex + 3) |= 4i64 * (int)v9;
    }
  }
  else
  {
    *((_QWORD *)newVertex + 3) &= 3ui64;
    *((_QWORD *)newVertex + 3) |= 4i64 * (int)v8;
  }
}

