// File Line: 28
// RVA: 0xB83880
hkSimdFloat32 *__fastcall getNormalComponentInUp(
        hkSimdFloat32 *result,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *up)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm3
  hkSimdFloat32 *v9; // rax

  v5 = _mm_sub_ps(v2->m_quad, v0->m_quad);
  v6 = _mm_sub_ps(v1->m_quad, v0->m_quad);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), up->m_quad);
  v9 = result;
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                     _mm_shuffle_ps(v8, v8, 170));
  return v9;
}

// File Line: 86
// RVA: 0xB838E0
hkResult *__fastcall triangulatorAddEdges(
        hkResult *result,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkVector4f *points,
        const int numPoints,
        CleanEdgesOutput *edgesOutput)
{
  __int64 m_size; // r15
  int v7; // edi
  int v9; // r14d
  char *v10; // rsi
  int v11; // r9d
  __int64 v12; // r12
  hkResultEnum m_enum; // eax
  __int64 v15; // rax
  int m_margin; // edi
  __int64 v17; // rcx
  CleanEdgesOutput::CleanEdge *m_data; // rax
  __int64 m_a; // rcx
  int v20; // eax
  __m128 m_quad; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128i v27; // xmm1
  int v28; // esi
  int v29; // ecx
  __int64 v30; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *inserted; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_triangle; // r14
  __int64 v33; // r15
  int v34; // ecx
  char *v35; // rdx
  __int64 v36; // rax
  char *v37; // rdi
  int v38; // ecx
  __int64 v39; // r8
  int v40; // edi
  int v41; // eax
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  __m128i v48; // xmm1
  int v49; // esi
  int v50; // ecx
  __int64 v51; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v52; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v53; // r14
  __int64 v54; // r15
  int v55; // ecx
  char *v56; // rdx
  __int64 v57; // rax
  char *v58; // rdi
  int v59; // ecx
  char *v60; // rdx
  __int64 v61; // rcx
  __int64 v62; // r14
  __int64 v63; // r13
  __int64 v64; // r15
  __int64 v65; // rdi
  hkResult *v66; // rbx
  int v67; // r8d
  int v68; // r8d
  char *v69; // [rsp+50h] [rbp-B0h] BYREF
  int v70; // [rsp+58h] [rbp-A8h]
  int v71; // [rsp+5Ch] [rbp-A4h]
  char *array; // [rsp+60h] [rbp-A0h] BYREF
  int v73; // [rsp+68h] [rbp-98h]
  int v74; // [rsp+6Ch] [rbp-94h]
  hkResult v75; // [rsp+70h] [rbp-90h] BYREF
  hkResult resulta; // [rsp+74h] [rbp-8Ch] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Location location; // [rsp+78h] [rbp-88h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v78; // [rsp+90h] [rbp-70h] BYREF
  __int64 v79; // [rsp+A8h] [rbp-58h]
  __int64 v80; // [rsp+B0h] [rbp-50h]
  __int64 v81; // [rsp+B8h] [rbp-48h]
  hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > icrossing; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v83; // [rsp+F0h] [rbp-10h]

  m_size = edgesOutput->m_edges.m_size;
  v7 = 0x80000000;
  v9 = 2 * m_size;
  array = 0i64;
  v73 = 0;
  v74 = 0x80000000;
  v10 = 0i64;
  v69 = 0i64;
  v70 = 0;
  v71 = 0x80000000;
  if ( 2 * (int)m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v11 = 2 * m_size;
    if ( (m_size & 0x40000000) != 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v11, 32);
    v7 = v71;
    v10 = v69;
  }
  v12 = 8i64;
  if ( (v7 & 0x3FFFFFFF) >= v9 )
  {
    m_enum = HK_SUCCESS;
    v75.m_enum = HK_SUCCESS;
  }
  else
  {
    if ( v9 < 2 * (v7 & 0x3FFFFFFF) )
      v9 = 2 * (v7 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v75, &hkContainerHeapAllocator::s_alloc, &v69, v9, 8);
    v7 = v71;
    v10 = v69;
    m_enum = v75.m_enum;
  }
  if ( resulta.m_enum || m_enum )
  {
    v70 = 0;
    result->m_enum = HK_FAILURE;
    if ( v7 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 8 * v7);
    v69 = 0i64;
    v71 = 0x80000000;
    v73 = 0;
    if ( v74 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v74);
    return result;
  }
  else
  {
    hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>::hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>(&icrossing);
    v15 = 0i64;
    v81 = m_size;
    v80 = 0i64;
    if ( (int)m_size <= 0 )
    {
LABEL_62:
      v62 = 0i64;
      v63 = v73 / 2;
      if ( v73 / 2 <= 0 )
      {
LABEL_68:
        v66 = result;
        v70 = 0;
        result->m_enum = HK_SUCCESS;
        if ( v7 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 8 * v7);
        v69 = 0i64;
        v73 = 0;
      }
      else
      {
        v64 = 0i64;
        v65 = 0i64;
        while ( 1 )
        {
          hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>::setPossibleVertsAndTriangulator(
            &icrossing,
            *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)&v10[v64],
            *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)&v10[v12],
            triangulator);
          LODWORD(edgesOutput) = 0;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertCrossingEdge<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>>(
            triangulator,
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *)&location,
            *(_DWORD *)&array[v65 + 16],
            *(_DWORD *)&array[v65 + 20],
            *(_DWORD *)&array[v65 + 48],
            *(_DWORD *)&array[v65 + 52],
            1,
            &icrossing,
            (hkaiNavMeshGenTriangulatorEdgeData *)&edgesOutput);
          if ( location.m_type.m_storage == 10 || triangulator->m_status.m_storage )
            break;
          v10 = v69;
          ++v62;
          v64 += 16i64;
          v12 += 16i64;
          v65 += 64i64;
          if ( v62 >= v63 )
          {
            v7 = v71;
            goto LABEL_68;
          }
        }
        v66 = result;
        v68 = v71;
        v70 = 0;
        result->m_enum = HK_FAILURE;
        if ( v68 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v69, 8 * v68);
        v69 = 0i64;
        v73 = 0;
      }
      v71 = 0x80000000;
      if ( v74 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v74);
      return v66;
    }
    else
    {
      while ( 1 )
      {
        m_margin = triangulator->m_margin;
        v17 = v15;
        m_data = edgesOutput->m_edges.m_data;
        v79 = v17 * 8;
        m_a = m_data[v17].m_a;
        v20 = 0x7FFFFF - m_margin;
        m_quad = points[m_a].m_quad;
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), triangulator->m_worldToLocal.m_col0.m_quad),
                    triangulator->m_worldToLocal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), triangulator->m_worldToLocal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), triangulator->m_worldToLocal.m_col2.m_quad));
        v23 = _mm_sub_ps(v22, (__m128)xmmword_141A711B0);
        v24 = _mm_add_ps(v22, (__m128)xmmword_141A711B0);
        v25 = _mm_cmplt_ps(v22, (__m128)0i64);
        v26 = _mm_or_ps(_mm_andnot_ps(v25, v24), _mm_and_ps(v23, v25));
        v27 = _mm_xor_si128(
                (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v26),
                _mm_cvttps_epi32(v26));
        v28 = _mm_cvtsi128_si32(v27);
        if ( v28 >= m_margin )
        {
          if ( v28 > v20 )
            v28 = 0x7FFFFF - m_margin;
        }
        else
        {
          v28 = m_margin;
        }
        v29 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v27, 85));
        if ( v29 >= m_margin )
        {
          m_margin = v29;
          if ( v29 > v20 )
            m_margin = v20;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
          triangulator,
          &location,
          v28,
          m_margin);
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
          triangulator,
          &v78,
          v28,
          m_margin,
          1,
          &location,
          0);
        LODWORD(v30) = v78.m_type.m_storage;
        if ( v78.m_type.m_storage == 2 )
        {
          location.m_edge = v78.m_edge;
          location.m_type.m_storage = 1;
          inserted = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
                       triangulator,
                       &v78,
                       v28,
                       m_margin,
                       1,
                       &location,
                       1);
          v30 = *(_QWORD *)&inserted->m_type.m_storage;
          m_triangle = inserted->m_edge.m_triangle;
          v33 = *(_QWORD *)&inserted->m_edge.m_index;
        }
        else
        {
          LODWORD(v33) = v78.m_edge.m_index;
          m_triangle = v78.m_edge.m_triangle;
        }
        if ( (_DWORD)v30 == 10 || triangulator->m_status.m_storage )
          break;
        if ( (unsigned int)v30 > 1 )
        {
          v39 = v79;
        }
        else
        {
          v34 = v73;
          if ( v73 == (v74 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 32);
            v34 = v73;
          }
          v35 = &array[32 * v34];
          if ( v35 )
          {
            v36 = v83;
            *((_DWORD *)v35 + 4) = v28;
            *((_DWORD *)v35 + 5) = m_margin;
            *((_QWORD *)v35 + 3) = v36;
            v34 = v73;
          }
          v37 = (char *)m_triangle + 8 * (int)v33;
          v73 = v34 + 1;
          v38 = v70;
          if ( v70 == (v71 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v69, 8);
            v38 = v70;
          }
          v39 = v79;
          *(_QWORD *)&v69[8 * v38] = *((_QWORD *)v37 + 2);
          ++v70;
          *(_QWORD *)(*((_QWORD *)v37 + 2) + 24i64) = *(_DWORD *)(*((_QWORD *)v37 + 2) + 24i64) & 3 | (unsigned __int64)(4i64 * *(int *)((char *)&edgesOutput->m_edges.m_data->m_a + v39));
        }
        v40 = triangulator->m_margin;
        v41 = 0x7FFFFF - v40;
        v42 = points[*(int *)((char *)&edgesOutput->m_edges.m_data->m_b + v39)].m_quad;
        v43 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), triangulator->m_worldToLocal.m_col0.m_quad),
                    triangulator->m_worldToLocal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), triangulator->m_worldToLocal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), triangulator->m_worldToLocal.m_col2.m_quad));
        v44 = _mm_sub_ps(v43, (__m128)xmmword_141A711B0);
        v45 = _mm_add_ps(v43, (__m128)xmmword_141A711B0);
        v46 = _mm_cmplt_ps(v43, (__m128)0i64);
        v47 = _mm_or_ps(_mm_andnot_ps(v46, v45), _mm_and_ps(v44, v46));
        v48 = _mm_xor_si128(
                (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v47),
                _mm_cvttps_epi32(v47));
        v49 = _mm_cvtsi128_si32(v48);
        if ( v49 >= v40 )
        {
          if ( v49 > v41 )
            v49 = 0x7FFFFF - v40;
        }
        else
        {
          v49 = triangulator->m_margin;
        }
        v50 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v48, 85));
        if ( v50 >= v40 )
        {
          v40 = v50;
          if ( v50 > v41 )
            v40 = v41;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
          triangulator,
          &location,
          v49,
          v40);
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
          triangulator,
          &v78,
          v49,
          v40,
          1,
          &location,
          0);
        LODWORD(v51) = v78.m_type.m_storage;
        if ( v78.m_type.m_storage == 2 )
        {
          location.m_edge = v78.m_edge;
          location.m_type.m_storage = 1;
          v52 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
                  triangulator,
                  &v78,
                  v49,
                  v40,
                  1,
                  &location,
                  1);
          v51 = *(_QWORD *)&v52->m_type.m_storage;
          v53 = v52->m_edge.m_triangle;
          v54 = *(_QWORD *)&v52->m_edge.m_index;
        }
        else
        {
          LODWORD(v54) = v78.m_edge.m_index;
          v53 = v78.m_edge.m_triangle;
        }
        if ( (_DWORD)v51 == 10 || triangulator->m_status.m_storage )
          break;
        if ( (unsigned int)v51 <= 1 )
        {
          v55 = v73;
          if ( v73 == (v74 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 32);
            v55 = v73;
          }
          v56 = &array[32 * v55];
          if ( v56 )
          {
            v57 = v83;
            *((_DWORD *)v56 + 4) = v49;
            *((_DWORD *)v56 + 5) = v40;
            *((_QWORD *)v56 + 3) = v57;
            v55 = v73;
          }
          v58 = (char *)v53 + 8 * (int)v54;
          v73 = v55 + 1;
          v59 = v70;
          if ( v70 == (v71 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v69, 8);
            v59 = v70;
          }
          v60 = &v69[8 * v59];
          v61 = v79;
          *(_QWORD *)v60 = *((_QWORD *)v58 + 2);
          ++v70;
          *(_QWORD *)(*((_QWORD *)v58 + 2) + 24i64) = *(_DWORD *)(*((_QWORD *)v58 + 2) + 24i64) & 3 | (unsigned __int64)(4i64 * *(int *)((char *)&edgesOutput->m_edges.m_data->m_b + v61));
        }
        v15 = v80 + 1;
        v80 = v15;
        if ( v15 >= v81 )
        {
          v7 = v71;
          v10 = v69;
          goto LABEL_62;
        }
      }
      v67 = v71;
      result->m_enum = HK_FAILURE;
      v70 = 0;
      if ( v67 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v69, 8 * v67);
      v69 = 0i64;
      v71 = 0x80000000;
      v73 = 0;
      if ( v74 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 32 * v74);
      return result;
    }
  }
}

// File Line: 180
// RVA: 0xB84110
_BOOL8 __fastcall OrderCleanEdge(CleanEdgesOutput::CleanEdge *a, CleanEdgesOutput::CleanEdge *b)
{
  int v2; // r8d
  int v3; // r9d
  int v4; // ecx
  int v5; // eax

  v2 = (int)*a;
  if ( v2 <= (int)HIDWORD(*(unsigned __int64 *)a) )
  {
    v3 = HIDWORD(*(unsigned __int64 *)a);
  }
  else
  {
    v3 = (int)*a;
    v2 = HIDWORD(*(unsigned __int64 *)a);
  }
  v4 = (int)*b;
  if ( v4 <= (int)HIDWORD(*(unsigned __int64 *)b) )
  {
    v5 = HIDWORD(*(unsigned __int64 *)b);
  }
  else
  {
    v5 = (int)*b;
    v4 = HIDWORD(*(unsigned __int64 *)b);
  }
  return v2 < v4 || v2 == v4 && v3 < v5;
}

// File Line: 197
// RVA: 0xB84170
hkResult *__fastcall getAllEdges(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *srcVertices,
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end,
        CleanEdgesOutput *cleanEdgesOutput)
{
  CleanEdgesOutput *v5; // rbx
  hkaiEdgeGeometry::Edge *const *v6; // rdi
  int v8; // eax
  __int64 v9; // r8
  int v12; // eax
  int m_size; // r8d
  CleanEdgesOutput::CleanEdge v15; // [rsp+60h] [rbp+18h]

  v5 = cleanEdgesOutput;
  v6 = start;
  v8 = cleanEdgesOutput->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = end - start;
  if ( v8 >= (int)v9 )
  {
    LODWORD(cleanEdgesOutput) = 0;
  }
  else
  {
    v12 = 2 * v8;
    if ( (int)v9 < v12 )
      LODWORD(v9) = v12;
    hkArrayUtil::_reserve((hkResult *)&cleanEdgesOutput, &hkContainerHeapAllocator::s_alloc, cleanEdgesOutput, v9, 8);
    if ( (_DWORD)cleanEdgesOutput )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  for ( ; v6 != end; ++v6 )
  {
    v15 = **(CleanEdgesOutput::CleanEdge **)v6;
    if ( (_mm_movemask_ps(_mm_cmpeq_ps(srcVertices->m_data[v15.m_a].m_quad, srcVertices->m_data[(*v6)->m_b].m_quad)) & 7) != 7 )
    {
      if ( v5->m_edges.m_size == (v5->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v5, 8);
      v5->m_edges.m_data[v5->m_edges.m_size++] = v15;
    }
  }
  m_size = v5->m_edges.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<CleanEdgesOutput::CleanEdge,unsigned int (*)(CleanEdgesOutput::CleanEdge const &,CleanEdgesOutput::CleanEdge const &)>(
      (hkaiStaticObstacleSystem::VelocityObstacleEdge *)v5->m_edges.m_data,
      0,
      m_size - 1,
      (unsigned int (__fastcall *)(hkaiStaticObstacleSystem::VelocityObstacleEdge *, hkaiStaticObstacleSystem::VelocityObstacleEdge *))OrderCleanEdge);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 228
// RVA: 0xB842C0
hkResult *__fastcall hkaiNavMeshGenerationUtils_triangulateFace(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *globalTriangulator,
        hkAabb *globalDomainAabb,
        hkArray<hkVector4f,hkContainerHeapAllocator> *srcVertices,
        CleanEdgesOutput *edgesOutput,
        hkVector4f *faceNormal,
        hkArray<int,hkContainerHeapAllocator> *trisOut,
        hkArray<int,hkContainerHeapAllocator> *triConnectivityOut,
        hkStopwatch *watch)
{
  hkResult *v10; // rbx
  _QWORD *Value; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r10
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  CleanEdgesOutput *v18; // r12
  __int64 m_size; // rax
  unsigned int m_slotID; // ecx
  _QWORD *v21; // r9
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v24; // rbx
  char v25; // si
  __int64 v26; // r8
  hkVector4f *m_data; // r10
  hkVector4f v28; // xmm2
  hkVector4f v29; // xmm3
  CleanEdgesOutput::CleanEdge *v30; // rdx
  __m128 m_quad; // xmm0
  __m128 v32; // xmm0
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *v33; // r13
  int v34; // edx
  int v35; // r8d
  int v36; // r15d
  __int64 v37; // rsi
  hkVector4f *v38; // rbx
  hkVector4f *v39; // rdi
  int v40; // ecx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v42; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v43; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v44; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v45; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *i; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v47; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v48; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v49; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v50; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *j; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v52; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v53; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *k; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v55; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v56; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *m; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v58; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v59; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *n; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v61; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v62; // rdx
  hkStopwatch *v63; // rbx
  unsigned __int64 TickCounter; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_used; // rdi
  hkArray<int,hkContainerHeapAllocator> *v66; // rbx
  hkArray<int,hkContainerHeapAllocator> *v67; // rsi
  __int64 v68; // r15
  __int64 v69; // r13
  __int64 v70; // r12
  int m_capacityAndFlags; // eax
  int v72; // eax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v73; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v74; // r8
  int m_x; // ecx
  int v76; // eax
  unsigned __int64 v77; // rax
  __int64 v78; // rcx
  unsigned __int64 v79; // rax
  BOOL v80; // r15d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v81; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v82; // r8
  int v83; // ecx
  int v84; // eax
  unsigned __int64 v85; // rax
  __int64 v86; // rcx
  unsigned __int64 v87; // rax
  BOOL v88; // r15d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v89; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v90; // r8
  int v91; // ecx
  int v92; // eax
  unsigned __int64 v93; // rax
  __int64 v94; // rcx
  unsigned __int64 v95; // rax
  BOOL v96; // r15d
  unsigned __int64 v97; // rax
  unsigned __int64 v98; // rcx
  _QWORD *v99; // rax
  unsigned __int64 v100; // r8
  _QWORD *v101; // r9
  unsigned __int64 v102; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *ii; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v105; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v106; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *jj; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v108; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v109; // rdx
  hkVector4f dmin; // [rsp+30h] [rbp-D0h] BYREF
  int v111[4]; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f dmax; // [rsp+50h] [rbp-B0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> v113; // [rsp+60h] [rbp-A0h] BYREF

  v10 = result;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)Value[1];
  v15 = Value;
  if ( (unsigned __int64)v14 < Value[3] )
  {
    *v14 = "TttriangulateFace";
    v16 = __rdtsc();
    v17 = v14 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v15[1] = v17;
  }
  v18 = edgesOutput;
  m_size = edgesOutput->m_edges.m_size;
  if ( (_DWORD)m_size )
  {
    v24 = srcVertices;
    v25 = 0;
    v26 = 0i64;
    if ( (int)m_size > 0 )
    {
      m_data = srcVertices->m_data;
      v28.m_quad = (__m128)globalDomainAabb->m_max;
      v29.m_quad = (__m128)globalDomainAabb->m_min;
      v30 = edgesOutput->m_edges.m_data;
      while ( 1 )
      {
        m_quad = m_data[v30->m_a].m_quad;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v29.m_quad, m_quad), _mm_cmple_ps(m_quad, v28.m_quad))) & 7) != 7 )
          break;
        v32 = m_data[v30->m_b].m_quad;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v29.m_quad, v32), _mm_cmple_ps(v32, v28.m_quad))) & 7) != 7 )
          break;
        ++v26;
        ++v30;
        if ( v26 >= m_size )
          goto LABEL_13;
      }
      v25 = 1;
    }
LABEL_13:
    memset(&v113.m_mesh.m_vertices, 0, 20);
    v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
    v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    dmin.m_quad = (__m128)_xmm;
    dmax.m_quad = _xmm;
    *(_DWORD *)&v113.m_memSizeAndFlags = 0x1FFFF;
    *(_DWORD *)&v113.m_mesh.m_memSizeAndFlags = 0x1FFFF;
    memset(&v113.m_mesh.m_triangles, 0, 20);
    v113.m_stack.m_data = v113.m_stack.m_storage;
    v113.m_stack.m_size = 0;
    v113.m_stack.m_capacityAndFlags = -2147483584;
    v113.m_status.m_storage = 0;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
      &v113,
      &dmin,
      &dmax,
      0.0,
      1);
    v33 = &v113;
    if ( !v25 )
      v33 = globalTriangulator;
    edgesOutput = (CleanEdgesOutput *)v33;
    if ( v25 )
    {
      v34 = 0;
      v35 = 0x80000000;
      dmin.m_quad.m128_u64[0] = 0i64;
      dmin.m_quad.m128_u64[1] = 0x8000000000000000ui64;
      v36 = 0;
      if ( v18->m_edges.m_size > 0 )
      {
        v37 = 0i64;
        while ( 1 )
        {
          v38 = &srcVertices->m_data[v18->m_edges.m_data[v37].m_a];
          v39 = &srcVertices->m_data[v18->m_edges.m_data[v37].m_b];
          if ( v34 == (v35 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &dmin, 16);
            v34 = dmin.m_quad.m128_i32[2];
          }
          *(hkVector4f *)(dmin.m_quad.m128_u64[0] + 16i64 * v34) = (hkVector4f)v38->m_quad;
          v40 = dmin.m_quad.m128_i32[2] + 1;
          dmin.m_quad.m128_i32[2] = v40;
          if ( v40 == (dmin.m_quad.m128_i32[3] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &dmin, 16);
            v40 = dmin.m_quad.m128_i32[2];
          }
          ++v36;
          ++v37;
          *(hkVector4f *)(dmin.m_quad.m128_u64[0] + 16i64 * v40) = (hkVector4f)v39->m_quad;
          v34 = ++dmin.m_quad.m128_i32[2];
          if ( v36 >= v18->m_edges.m_size )
            break;
          v35 = dmin.m_quad.m128_i32[3];
        }
        v33 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *)edgesOutput;
        v24 = srcVertices;
      }
      dmax.m_quad.m128_u64[1] = (unsigned int)v34 | 0x1000000000i64;
      dmax.m_quad.m128_u64[0] = dmin.m_quad.m128_u64[0];
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        v33,
        (hkStridedVertices *)&dmax,
        faceNormal,
        1,
        1,
        0);
      dmin.m_quad.m128_i32[2] = 0;
      if ( dmin.m_quad.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          (void *)dmin.m_quad.m128_u64[0],
          16 * dmin.m_quad.m128_i32[3]);
    }
    else
    {
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        v33,
        1);
    }
    if ( v33->m_status.m_storage )
    {
      v10 = result;
      v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      result->m_enum = HK_FAILURE;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v113,
        1);
      v113.m_stack.m_size = 0;
      if ( v113.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v113.m_stack.m_data,
          16 * v113.m_stack.m_capacityAndFlags);
      m_firstPool = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
      v113.m_stack.m_data = 0i64;
      v113.m_stack.m_capacityAndFlags = 0x80000000;
      for ( v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
            v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            m_firstPool = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
      {
        v42 = m_firstPool->m_links[0];
        if ( v42 )
          v42->m_links[1] = m_firstPool->m_links[1];
        else
          v113.m_mesh.m_triangles.m_allocator.m_firstPool = m_firstPool->m_links[1];
        v43 = m_firstPool->m_links[1];
        if ( v43 )
          v43->m_links[0] = m_firstPool->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m_firstPool, 3616);
      }
      v113.m_mesh.m_triangles.m_used = 0i64;
      v113.m_mesh.m_triangles.m_numUsed = 0;
      if ( m_firstPool )
      {
        do
        {
          v44 = m_firstPool->m_links[0];
          if ( v44 )
            v44->m_links[1] = m_firstPool->m_links[1];
          else
            v113.m_mesh.m_triangles.m_allocator.m_firstPool = m_firstPool->m_links[1];
          v45 = m_firstPool->m_links[1];
          if ( v45 )
            v45->m_links[0] = m_firstPool->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m_firstPool, 3616);
          m_firstPool = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
        }
        while ( v113.m_mesh.m_triangles.m_allocator.m_firstPool );
      }
      for ( i = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            i = v113.m_mesh.m_vertices.m_allocator.m_firstPool )
      {
        v47 = i->m_links[0];
        if ( v47 )
          v47->m_links[1] = i->m_links[1];
        else
          v113.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
        v48 = i->m_links[1];
        if ( v48 )
          v48->m_links[0] = i->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, i, 1568);
      }
      v113.m_mesh.m_vertices.m_used = 0i64;
      v113.m_mesh.m_vertices.m_numUsed = 0;
      if ( i )
      {
        do
        {
          v49 = i->m_links[0];
          if ( v49 )
            v49->m_links[1] = i->m_links[1];
          else
            v113.m_mesh.m_vertices.m_allocator.m_firstPool = i->m_links[1];
          v50 = i->m_links[1];
          if ( v50 )
            v50->m_links[0] = i->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, i, 1568);
          i = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
        }
        while ( v113.m_mesh.m_vertices.m_allocator.m_firstPool );
      }
      goto LABEL_138;
    }
    triangulatorAddEdges((hkResult *)&edgesOutput, v33, v24->m_data, v24->m_size, v18);
    if ( (_DWORD)edgesOutput )
    {
      v10 = result;
      v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      result->m_enum = HK_FAILURE;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v113,
        1);
      v113.m_stack.m_size = 0;
      if ( v113.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v113.m_stack.m_data,
          16 * v113.m_stack.m_capacityAndFlags);
      v113.m_stack.m_data = 0i64;
      v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      v113.m_stack.m_capacityAndFlags = 0x80000000;
      hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
      for ( j = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            j = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
      {
        v52 = j->m_links[0];
        if ( v52 )
          v52->m_links[1] = j->m_links[1];
        else
          v113.m_mesh.m_triangles.m_allocator.m_firstPool = j->m_links[1];
        v53 = j->m_links[1];
        if ( v53 )
          v53->m_links[0] = j->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, j, 3616);
      }
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_vertices);
      for ( k = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            k = v113.m_mesh.m_vertices.m_allocator.m_firstPool )
      {
        v55 = k->m_links[0];
        if ( v55 )
          v55->m_links[1] = k->m_links[1];
        else
          v113.m_mesh.m_vertices.m_allocator.m_firstPool = k->m_links[1];
        v56 = k->m_links[1];
        if ( v56 )
          v56->m_links[0] = k->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, k, 1568);
      }
      goto LABEL_138;
    }
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::partitionWithPolicy<hkaiNavMeshFloodPolicy>(
      v33,
      (hkResult *)&edgesOutput,
      (hkaiNavMeshFloodPolicy *)&edgesOutput);
    if ( (_DWORD)edgesOutput )
    {
      v10 = result;
      v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      result->m_enum = HK_FAILURE;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v113,
        1);
      v113.m_stack.m_size = 0;
      if ( v113.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v113.m_stack.m_data,
          16 * v113.m_stack.m_capacityAndFlags);
      v113.m_stack.m_data = 0i64;
      v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      v113.m_stack.m_capacityAndFlags = 0x80000000;
      hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
      for ( m = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            m = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
      {
        v58 = m->m_links[0];
        if ( v58 )
          v58->m_links[1] = m->m_links[1];
        else
          v113.m_mesh.m_triangles.m_allocator.m_firstPool = m->m_links[1];
        v59 = m->m_links[1];
        if ( v59 )
          v59->m_links[0] = m->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m, 3616);
      }
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_vertices);
      for ( n = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            n = v113.m_mesh.m_vertices.m_allocator.m_firstPool )
      {
        v61 = n->m_links[0];
        if ( v61 )
          v61->m_links[1] = n->m_links[1];
        else
          v113.m_mesh.m_vertices.m_allocator.m_firstPool = n->m_links[1];
        v62 = n->m_links[1];
        if ( v62 )
          v62->m_links[0] = n->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, n, 1568);
      }
      goto LABEL_138;
    }
    v63 = watch;
    watch->m_running_flag.m_bool = 1;
    TickCounter = hkStopwatch::getTickCounter();
    v63->m_ticks_at_start = TickCounter;
    v63->m_ticks_at_split = TickCounter;
    m_used = v33->m_mesh.m_triangles.m_used;
    if ( m_used )
    {
      v66 = triConnectivityOut;
      v67 = trisOut;
      while ( 1 )
      {
        if ( (*((_WORD *)m_used + 44) & 0xFFE0) == 32 )
        {
          v68 = *((_QWORD *)m_used->m_vertices[0] + 3) >> 2;
          v69 = *((_QWORD *)m_used->m_vertices[2] + 3) >> 2;
          v70 = *((_QWORD *)m_used->m_vertices[1] + 3) >> 2;
          hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
            (hkaiArrayUtil *)&edgesOutput,
            (hkResult *)v67,
            (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v67->m_size + 3),
            -1);
          hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
            (hkaiArrayUtil *)v111,
            (hkResult *)v66,
            (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v66->m_size + 3),
            -1);
          if ( (_DWORD)edgesOutput )
          {
            v10 = result;
            v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
            result->m_enum = HK_FAILURE;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &v113,
              1);
            v113.m_stack.m_size = 0;
            if ( v113.m_stack.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v113.m_stack.m_data,
                16 * v113.m_stack.m_capacityAndFlags);
            v113.m_stack.m_data = 0i64;
            v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
            v113.m_stack.m_capacityAndFlags = 0x80000000;
            hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
            for ( ii = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
                  v113.m_mesh.m_triangles.m_allocator.m_firstPool;
                  ii = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
            {
              v105 = ii->m_links[0];
              if ( v105 )
                v105->m_links[1] = ii->m_links[1];
              else
                v113.m_mesh.m_triangles.m_allocator.m_firstPool = ii->m_links[1];
              v106 = ii->m_links[1];
              if ( v106 )
                v106->m_links[0] = ii->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, ii, 3616);
            }
            hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_vertices);
            for ( jj = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
                  v113.m_mesh.m_vertices.m_allocator.m_firstPool;
                  jj = v113.m_mesh.m_vertices.m_allocator.m_firstPool )
            {
              v108 = jj->m_links[0];
              if ( v108 )
                v108->m_links[1] = jj->m_links[1];
              else
                v113.m_mesh.m_vertices.m_allocator.m_firstPool = jj->m_links[1];
              v109 = jj->m_links[1];
              if ( v109 )
                v109->m_links[0] = jj->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, jj, 1568);
            }
            goto LABEL_138;
          }
          if ( v111[0] )
          {
            v10 = result;
            result->m_enum = HK_FAILURE;
            goto LABEL_135;
          }
          if ( v67->m_size == (v67->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v67, 4);
          v67->m_data[v67->m_size] = v68;
          m_capacityAndFlags = v67->m_capacityAndFlags;
          if ( ++v67->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v67, 4);
          v67->m_data[v67->m_size] = v70;
          v72 = v67->m_capacityAndFlags;
          if ( ++v67->m_size == (v72 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v67, 4);
          v67->m_data[v67->m_size++] = v69;
          v73 = m_used->m_vertices[1];
          v74 = m_used->m_vertices[0];
          m_x = v73->m_x;
          v76 = v74->m_x;
          if ( v76 >= m_x
            && (v76 > m_x || v74->m_y > v73->m_y)
            && (v77 = m_used->m_links[0], (v77 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
          {
            v78 = m_used->m_links[0] & 3;
            v79 = v77 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v79 = (unsigned __int64)m_used;
            LOBYTE(v78) = 0;
          }
          v80 = ((unsigned __int8)(1 << v78) & (unsigned __int8)*(_WORD *)(v79 + 88) & 7) != 0;
          if ( v66->m_size == (v66->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v66, 4);
          v66->m_data[v66->m_size++] = v80;
          v81 = m_used->m_vertices[2];
          v82 = m_used->m_vertices[1];
          v83 = v81->m_x;
          v84 = v82->m_x;
          if ( v84 >= v83
            && (v84 > v83 || v82->m_y > v81->m_y)
            && (v85 = m_used->m_links[1], (v85 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
          {
            v86 = m_used->m_links[1] & 3;
            v87 = v85 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v87 = (unsigned __int64)m_used;
            LOBYTE(v86) = 1;
          }
          v88 = ((unsigned __int8)(1 << v86) & (unsigned __int8)*(_WORD *)(v87 + 88) & 7) != 0;
          if ( v66->m_size == (v66->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v66, 4);
          v66->m_data[v66->m_size++] = v88;
          v89 = m_used->m_vertices[0];
          v90 = m_used->m_vertices[2];
          v91 = v89->m_x;
          v92 = v90->m_x;
          if ( v92 >= v91
            && (v92 > v91 || v90->m_y > v89->m_y)
            && (v93 = m_used->m_links[2], (v93 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
          {
            v94 = m_used->m_links[2] & 3;
            v95 = v93 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v95 = (unsigned __int64)m_used;
            LOBYTE(v94) = 2;
          }
          v96 = ((unsigned __int8)(1 << v94) & (unsigned __int8)*(_WORD *)(v95 + 88) & 7) != 0;
          if ( v66->m_size == (v66->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v66, 4);
          v66->m_data[v66->m_size++] = v96;
        }
        m_used = m_used->m_next;
        if ( !m_used )
        {
          v63 = watch;
          break;
        }
      }
    }
    v97 = hkStopwatch::getTickCounter();
    v63->m_running_flag.m_bool = 0;
    v98 = v97 - v63->m_ticks_at_start;
    v63->m_split_total += v97 - v63->m_ticks_at_split;
    v63->m_ticks_total += v98;
    ++v63->m_num_timings;
    v10 = result;
    result->m_enum = HK_SUCCESS;
LABEL_135:
    v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &v113,
      1);
    v113.m_stack.m_size = 0;
    if ( v113.m_stack.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v113.m_stack.m_data,
        16 * v113.m_stack.m_capacityAndFlags);
    v113.m_stack.m_data = 0i64;
    v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
    v113.m_stack.m_capacityAndFlags = 0x80000000;
    hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
    hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *)&v113.m_mesh.m_triangles);
    hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_vertices);
    hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&v113.m_mesh.m_vertices);
LABEL_138:
    v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    v113.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    v99 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v100 = v99[1];
    v101 = v99;
    if ( v100 < v99[3] )
    {
      v102 = __rdtsc();
      *(_DWORD *)(v100 + 8) = v102;
      *(_QWORD *)v100 = "Et";
      v101[1] = v100 + 16;
    }
  }
  else
  {
    m_slotID = hkMonitorStream__m_instance.m_slotID;
    v10->m_enum = HK_SUCCESS;
    v21 = TlsGetValue(m_slotID);
    v22 = v21[1];
    if ( v22 < v21[3] )
    {
      *(_QWORD *)v22 = "Et";
      v23 = __rdtsc();
      *(_DWORD *)(v22 + 8) = v23;
      v21[1] = v22 + 16;
    }
  }
  return v10;
};
    }
  }
  return v10;
}

// File Line: 420
// RVA: 0xB82210
hkResult *__fastcall hkaiNavMeshGenerationUtils::_triangulate(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkaiEdgeGeometry *geom,
        hkArray<int,hkContainerHeapAllocator> *trisOut,
        hkArray<int,hkContainerHeapAllocator> *trisPerFaceOut,
        hkArray<int,hkContainerHeapAllocator> *triConnectivityOut,
        hkArray<int,hkContainerHeapAllocator> *materialsOut,
        bool forceLocalDomain)
{
  hkaiFaceEdges v10; // [rsp+50h] [rbp-28h] BYREF

  v10.m_faceEdges.m_data = 0i64;
  v10.m_faceEdges.m_size = 0;
  v10.m_faceEdges.m_capacityAndFlags = 0x80000000;
  v10.m_faceStartEdges.m_data = 0i64;
  v10.m_faceStartEdges.m_size = 0;
  v10.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshGenerationUtils::_triangulate(
    result,
    input,
    geom,
    &v10,
    trisOut,
    trisPerFaceOut,
    triConnectivityOut,
    materialsOut,
    forceLocalDomain);
  v10.m_faceStartEdges.m_size = 0;
  if ( v10.m_faceStartEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v10.m_faceStartEdges.m_data,
      8 * v10.m_faceStartEdges.m_capacityAndFlags);
  v10.m_faceStartEdges.m_data = 0i64;
  v10.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  v10.m_faceEdges.m_size = 0;
  if ( v10.m_faceEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v10.m_faceEdges.m_data,
      8 * v10.m_faceEdges.m_capacityAndFlags);
  return result;
}

// File Line: 428
// RVA: 0xB81AA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_triangulate(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkaiEdgeGeometry *geom,
        hkaiFaceEdges *faceEdges,
        hkArray<int,hkContainerHeapAllocator> *trisOut,
        hkArray<int,hkContainerHeapAllocator> *trisPerFaceOut,
        hkArray<int,hkContainerHeapAllocator> *triConnectivityOut,
        hkArray<int,hkContainerHeapAllocator> *materialsOut,
        bool forceLocalDomain)
{
  _QWORD *Value; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  unsigned int m_slotID; // ecx
  _QWORD *v19; // rax
  unsigned __int64 v20; // r8
  _QWORD *v21; // r9
  unsigned __int64 v22; // rax
  int v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  int v30; // r8d
  __m128i si128; // xmm3
  __int64 v32; // rsi
  __m128 v33; // xmm3
  __int64 v34; // rax
  __m128 m_quad; // xmm1
  __int64 v36; // r12
  hkaiEdgeGeometry::Edge *const **m_data; // r8
  int m_size; // edi
  int v39; // edi
  int v40; // r9d
  int v41; // eax
  int v42; // eax
  int v43; // r8d
  __int64 v44; // rsi
  unsigned int v45; // edi
  _QWORD *v46; // r9
  unsigned __int64 v47; // r8
  unsigned __int64 v48; // rax
  hkVector4f dmax; // [rsp+50h] [rbp-B0h] BYREF
  hkResult resulta; // [rsp+60h] [rbp-A0h] BYREF
  hkResult v52; // [rsp+64h] [rbp-9Ch] BYREF
  hkResult v53; // [rsp+68h] [rbp-98h] BYREF
  hkResult v54; // [rsp+6Ch] [rbp-94h] BYREF
  hkVector4f dmin; // [rsp+70h] [rbp-90h] BYREF
  hkAabb globalDomainAabb; // [rsp+80h] [rbp-80h] BYREF
  __int128 v57; // [rsp+A0h] [rbp-60h]
  __int64 v58; // [rsp+B0h] [rbp-50h]
  hkStopwatch watch; // [rsp+B8h] [rbp-48h] BYREF
  hkVector4f normalOut; // [rsp+F0h] [rbp-10h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> globalTriangulator; // [rsp+100h] [rbp+0h] BYREF

  watch.m_name = 0i64;
  memset(&watch, 0, 33);
  watch.m_num_timings = 0;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)Value[1];
  v15 = Value;
  if ( (unsigned __int64)v14 < Value[3] )
  {
    *v14 = "Tt_triangulate";
    v16 = __rdtsc();
    v17 = v14 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v15[1] = v17;
  }
  hkaiFaceEdges::clear(faceEdges);
  hkaiFaceEdges::setGeometry(faceEdges, &resulta, geom);
  if ( resulta.m_enum )
  {
    m_slotID = hkMonitorStream__m_instance.m_slotID;
    result->m_enum = HK_FAILURE;
    v19 = TlsGetValue(m_slotID);
    v20 = v19[1];
    v21 = v19;
    if ( v20 < v19[3] )
    {
      *(_QWORD *)v20 = "Et";
      v22 = __rdtsc();
      *(_DWORD *)(v20 + 8) = v22;
      v21[1] = v20 + 16;
    }
    return result;
  }
  v23 = faceEdges->m_faceStartEdges.m_size - 1;
  v24 = trisPerFaceOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 >= v23 )
  {
    v52.m_enum = HK_SUCCESS;
    goto LABEL_12;
  }
  v25 = 2 * v24;
  v26 = faceEdges->m_faceStartEdges.m_size - 1;
  if ( v23 < v25 )
    v26 = v25;
  hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, trisPerFaceOut, v26, 4);
  if ( v52.m_enum == HK_SUCCESS )
  {
    if ( !materialsOut )
      goto LABEL_18;
    v27 = materialsOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 >= v23 )
      goto LABEL_18;
LABEL_12:
    v28 = 2 * v27;
    v29 = v23;
    if ( v23 < v28 )
      v29 = v28;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, materialsOut, v29, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
LABEL_18:
      globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      memset(&globalTriangulator.m_mesh.m_vertices, 0, 20);
      globalTriangulator.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      memset(&globalTriangulator.m_mesh.m_triangles, 0, 20);
      dmin.m_quad = (__m128)_xmm;
      dmax.m_quad = _xmm;
      globalTriangulator.m_stack.m_size = 0;
      globalTriangulator.m_status.m_storage = 0;
      *(_DWORD *)&globalTriangulator.m_memSizeAndFlags = 0x1FFFF;
      *(_DWORD *)&globalTriangulator.m_mesh.m_memSizeAndFlags = 0x1FFFF;
      globalTriangulator.m_stack.m_data = globalTriangulator.m_stack.m_storage;
      globalTriangulator.m_stack.m_capacityAndFlags = -2147483584;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
        &globalTriangulator,
        &dmin,
        &dmax,
        0.0,
        1);
      globalDomainAabb.m_max = (hkVector4f)_xmm_c4fa0000c4fa0000c4fa0000c4fa0000;
      v57 = _xmm;
      globalDomainAabb.m_min.m_quad.m128_u64[0] = (unsigned __int64)&globalDomainAabb.m_max;
      globalDomainAabb.m_min.m_quad.m128_u64[1] = 0x8000000200000002ui64;
      dmax.m_quad.m128_u64[0] = (unsigned __int64)&globalDomainAabb.m_max;
      dmax.m_quad.m128_u64[1] = 0x1000000002i64;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        &globalTriangulator,
        (hkStridedVertices *)&dmax,
        &input->m_up,
        0,
        1,
        0);
      v30 = globalDomainAabb.m_min.m_quad.m128_i32[3];
      if ( globalTriangulator.m_status.m_storage )
      {
        result->m_enum = HK_FAILURE;
        globalDomainAabb.m_min.m_quad.m128_i32[2] = 0;
        if ( v30 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)globalDomainAabb.m_min.m_quad.m128_u64[0],
            16 * v30);
        globalDomainAabb.m_min.m_quad.m128_u64[0] = 0i64;
        globalDomainAabb.m_min.m_quad.m128_i32[3] = 0x80000000;
        globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
          &globalTriangulator,
          1);
      }
      else
      {
        globalDomainAabb.m_min.m_quad.m128_i32[2] = 0;
        if ( globalDomainAabb.m_min.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)globalDomainAabb.m_min.m_quad.m128_u64[0],
            16 * globalDomainAabb.m_min.m_quad.m128_i32[3]);
        si128 = _mm_load_si128((const __m128i *)&input->m_up);
        v52.m_enum = HK_FAILURE;
        v32 = 1i64;
        v58 = 1i64;
        v33 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
        dmin.m_quad = (__m128)_xmm;
        dmax.m_quad = (__m128)_xmm_c4f98000c4f98000c4f98000c4f98000;
        v34 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmple_ps(
                                                                         _mm_max_ps(
                                                                           _mm_shuffle_ps(v33, v33, 170),
                                                                           _mm_max_ps(
                                                                             _mm_shuffle_ps(v33, v33, 85),
                                                                             _mm_shuffle_ps(v33, v33, 0))),
                                                                         v33),
                                                                       (__m128)xmmword_141A4D8E0))];
        dmin.m_quad.m128_i32[v34] = 2139095022;
        m_quad = dmin.m_quad;
        dmax.m_quad.m128_i32[v34] = -8388626;
        globalDomainAabb.m_max.m_quad = m_quad;
        dmin.m_quad.m128_u64[0] = v23;
        globalDomainAabb.m_min = (hkVector4f)dmax.m_quad;
        if ( v23 <= 1i64 )
        {
LABEL_50:
          result->m_enum = HK_SUCCESS;
          globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            &globalTriangulator,
            1);
        }
        else
        {
          v36 = 1i64;
          while ( 1 )
          {
            dmax.m_quad.m128_u64[0] = 0i64;
            m_data = faceEdges->m_faceStartEdges.m_data;
            m_size = trisOut->m_size;
            dmax.m_quad.m128_u64[1] = 0x8000000000000000ui64;
            getAllEdges(&v53, &geom->m_vertices, m_data[v32], m_data[v32 + 1], (CleanEdgesOutput *)&dmax);
            if ( v53.m_enum )
              break;
            if ( forceLocalDomain )
            {
              globalDomainAabb.m_min = (hkVector4f)xmmword_141A712A0;
              globalDomainAabb.m_max.m_quad = _mm_xor_ps(
                                                (__m128)_mm_shuffle_epi32(
                                                          _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                          0),
                                                (__m128)xmmword_141A712A0);
            }
            hkaiEdgeGeometry::calculateFaceNormal(geom, faceEdges, v52.m_enum, &normalOut);
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &globalTriangulator,
              1);
            hkaiNavMeshGenerationUtils_triangulateFace(
              &v54,
              input,
              &globalTriangulator,
              &globalDomainAabb,
              &geom->m_vertices,
              (CleanEdgesOutput *)&dmax,
              &normalOut,
              trisOut,
              triConnectivityOut,
              &watch);
            if ( v54.m_enum )
              break;
            v39 = (trisOut->m_size - m_size) / 3;
            if ( trisPerFaceOut->m_size == (trisPerFaceOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, trisPerFaceOut, 4);
            trisPerFaceOut->m_data[trisPerFaceOut->m_size++] = v39;
            if ( materialsOut )
            {
              v40 = v39 + materialsOut->m_size;
              v41 = materialsOut->m_capacityAndFlags & 0x3FFFFFFF;
              if ( v41 >= v40 )
              {
                resulta.m_enum = HK_SUCCESS;
              }
              else
              {
                v42 = 2 * v41;
                if ( v40 < v42 )
                  v40 = v42;
                hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, materialsOut, v40, 4);
                if ( resulta.m_enum )
                  break;
              }
              if ( v39 > 0 )
              {
                v44 = (unsigned int)v39;
                do
                {
                  v45 = geom->m_faces.m_data[v36].m_data;
                  if ( materialsOut->m_size == (materialsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, materialsOut, 4);
                  materialsOut->m_data[materialsOut->m_size++] = v45;
                  --v44;
                }
                while ( v44 );
                v32 = v58;
              }
            }
            dmax.m_quad.m128_i32[2] = 0;
            if ( dmax.m_quad.m128_i32[3] >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                (void *)dmax.m_quad.m128_u64[0],
                8 * dmax.m_quad.m128_i32[3]);
            ++v52.m_enum;
            ++v32;
            ++v36;
            dmax.m_quad.m128_u64[0] = 0i64;
            dmax.m_quad.m128_i32[3] = 0x80000000;
            v58 = v32;
            if ( v32 >= dmin.m_quad.m128_i64[0] )
              goto LABEL_50;
          }
          v43 = dmax.m_quad.m128_i32[3];
          dmax.m_quad.m128_i32[2] = 0;
          result->m_enum = HK_FAILURE;
          if ( v43 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              (void *)dmax.m_quad.m128_u64[0],
              8 * v43);
          dmax.m_quad.m128_u64[0] = 0i64;
          dmax.m_quad.m128_i32[3] = 0x80000000;
          globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            &globalTriangulator,
            1);
        }
      }
      globalTriangulator.m_stack.m_size = 0;
      if ( globalTriangulator.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          globalTriangulator.m_stack.m_data,
          16 * globalTriangulator.m_stack.m_capacityAndFlags);
      globalTriangulator.m_stack.m_data = 0i64;
      globalTriangulator.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      globalTriangulator.m_stack.m_capacityAndFlags = 0x80000000;
      hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&globalTriangulator.m_mesh.m_triangles);
      hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *)&globalTriangulator.m_mesh.m_triangles);
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&globalTriangulator.m_mesh.m_vertices);
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&globalTriangulator.m_mesh.m_vertices);
      globalTriangulator.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    goto LABEL_54;
  }
  result->m_enum = HK_FAILURE;
LABEL_54:
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = v46[1];
  if ( v47 < v46[3] )
  {
    v48 = __rdtsc();
    *(_DWORD *)(v47 + 8) = v48;
    *(_QWORD *)v47 = "Et";
    v46[1] = v47 + 16;
  }
  return result;
}

// File Line: 600
// RVA: 0xB81830
hkResult *__fastcall hkaiNavMeshGenerationUtils::_findSharedEdges(
        hkResult *result,
        const int *indicesPtr,
        unsigned int numIndices,
        int *oppositeEdgesOut)
{
  __int64 v4; // rbx
  __int64 v8; // rcx
  int *v9; // rdi
  Edge *v10; // rcx
  int v11; // r11d
  __int64 v12; // r10
  int v13; // r15d
  int v14; // r9d
  __int64 v15; // rdi
  __int64 v16; // rax
  __int64 v17; // r8
  __int64 v18; // rdx
  __int64 v19; // rax
  unsigned __int64 v20; // rcx
  int v21; // r8d
  Edge *v22; // rdx
  int v23; // eax
  Edge *v24; // rdi
  Edge *v25; // r9
  char *v26; // rax
  Edge *array; // [rsp+30h] [rbp-38h] BYREF
  int v29; // [rsp+38h] [rbp-30h]
  int v30; // [rsp+3Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+80h] [rbp+18h] BYREF

  v4 = (int)numIndices;
  if ( (int)(numIndices - 1) >= 0 )
  {
    v8 = numIndices;
    v9 = oppositeEdgesOut;
    while ( v8 )
    {
      *v9++ = -1;
      --v8;
    }
  }
  if ( (int)numIndices <= 3 )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v10 = 0i64;
  v29 = 0;
  array = 0i64;
  v30 = 0x80000000;
  if ( (int)(numIndices + 1) > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, numIndices + 1, 16);
    if ( resulta.m_enum )
    {
      v21 = v30;
      result->m_enum = HK_FAILURE;
      v29 = 0;
      if ( v21 < 0 )
        return result;
      v22 = array;
LABEL_30:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v22, 16 * v21);
      return result;
    }
    v10 = array;
  }
  v29 = v4 + 1;
  v11 = 0;
  v10[v4].m_key = -1i64;
  v12 = 0i64;
  do
  {
    v13 = 2;
    v14 = 0;
    v15 = 0i64;
    v16 = 8i64;
    v17 = v12;
    do
    {
      v18 = *(const int *)((char *)&indicesPtr[v12] + v16);
      v19 = indicesPtr[v12 + v15];
      if ( (int)v18 >= (int)v19 )
        v20 = v18 | (v19 << 32);
      else
        v20 = v19 | (v18 << 32);
      array[v17++].m_key = v20;
      array[v17 - 1].m_edgeIdx = v13 + v11;
      v13 = v14++;
      v16 = v15 * 4;
      ++v15;
    }
    while ( v14 < 3 );
    v12 += 3i64;
    v11 += 3;
  }
  while ( v12 < v4 );
  v23 = v29;
  if ( v29 - 1 > 1 )
  {
    hkAlgorithm::quickSortRecursive<Edge,hkAlgorithm::less<Edge>>(array, 0, v29 - 2, 0);
    v23 = v29;
  }
  v24 = array;
  v25 = &array[v23 - 1];
  if ( array < v25 )
  {
    do
    {
      v26 = (char *)&v24[1];
      if ( v24[1].m_key == v24->m_key )
      {
        do
          v26 += 16;
        while ( *(_QWORD *)v26 == v24->m_key );
      }
      if ( (unsigned int)((v26 - (char *)v24) >> 4) == 2 )
      {
        oppositeEdgesOut[v24[1].m_edgeIdx] = v24->m_edgeIdx;
        oppositeEdgesOut[v24->m_edgeIdx] = v24[1].m_edgeIdx;
      }
      v24 = (Edge *)v26;
    }
    while ( v26 < (char *)v25 );
    v24 = array;
  }
  v21 = v30;
  result->m_enum = HK_SUCCESS;
  v29 = 0;
  if ( v21 >= 0 )
  {
    v22 = v24;
    goto LABEL_30;
  }
  return result;
}

// File Line: 725
// RVA: 0xB81750
hkResult *__fastcall hkaiNavMeshGenerationUtils::_nullHertelMehlhorn(
        hkResult *result,
        hkVector4f *verts,
        char *triangleIndices,
        char *materials,
        char *oppEdges,
        int numIndices,
        int *convexIndices,
        int *convexMaterials,
        int *oppConvexEdges,
        int *numIndicesPerPiece,
        int *numPieces)
{
  __int64 v12; // rdx
  signed __int64 v13; // r10
  int v14; // eax
  char *v15; // rcx
  __int64 v16; // rdx
  int v17; // eax
  __int64 v18; // rcx
  signed __int64 v19; // r8
  int v20; // eax
  int i; // eax
  hkResult *v23; // rax

  if ( numIndices > 0 )
  {
    v12 = (unsigned int)numIndices;
    v13 = (char *)convexIndices - triangleIndices;
    do
    {
      v14 = *(_DWORD *)triangleIndices;
      triangleIndices += 4;
      *(_DWORD *)&triangleIndices[v13 - 4] = v14;
      --v12;
    }
    while ( v12 );
  }
  v15 = oppEdges;
  if ( numIndices > 0 )
  {
    v16 = (unsigned int)numIndices;
    do
    {
      v17 = *(_DWORD *)v15;
      v15 += 4;
      *(_DWORD *)&v15[(char *)oppConvexEdges - oppEdges - 4] = v17;
      --v16;
    }
    while ( v16 );
  }
  *numPieces = numIndices / 3;
  if ( numIndices / 3 > 0 )
  {
    v18 = (unsigned int)(numIndices / 3);
    v19 = (char *)convexMaterials - materials;
    do
    {
      v20 = *(_DWORD *)materials;
      materials += 4;
      *(_DWORD *)&materials[v19 - 4] = v20;
      --v18;
    }
    while ( v18 );
  }
  for ( i = 0; i < *numPieces; ++numIndicesPerPiece )
  {
    *numIndicesPerPiece = 3;
    ++i;
  }
  v23 = result;
  result->m_enum = HK_SUCCESS;
  return v23;
}

// File Line: 741
// RVA: 0xB85100
__int64 __fastcall getNumSharedVertices(hkArrayBase<int> *polyA, hkArrayBase<int> *polyB)
{
  __int64 m_size; // rbx
  unsigned int v3; // r11d
  __int64 v4; // r10
  __int64 v7; // r9
  int v8; // edx
  __int64 v9; // rcx
  int *m_data; // rax

  m_size = polyA->m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size > 0 )
  {
    v7 = polyB->m_size;
    do
    {
      v8 = 0;
      v9 = 0i64;
      if ( v7 > 0 )
      {
        m_data = polyB->m_data;
        while ( *m_data != polyA->m_data[v4] )
        {
          ++v9;
          ++v8;
          ++m_data;
          if ( v9 >= v7 )
            goto LABEL_10;
        }
        if ( v8 != -1 )
          ++v3;
      }
LABEL_10:
      ++v4;
    }
    while ( v4 < m_size );
  }
  return v3;
}

// File Line: 765
// RVA: 0xB7FAA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_hertelMehlhorn(
        hkResult *result,
        hkVector4f *verts,
        const int *triangleIndices,
        int *materials,
        __int32 *oppEdges,
        const __m128i *numIndices,
        hkaiNavMeshGenerationSettings *settings,
        int *convexIndices,
        int *convexMaterials,
        int *oppConvexEdges,
        int *numIndicesPerPiece,
        int *numPieces,
        hkVector4f *norm)
{
  _DWORD *v13; // rdi
  __m128i si128; // xmm5
  __m128i v17; // xmm7
  __m128 v18; // xmm8
  __m128 v19; // xmm2
  __m128i v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm9
  __m128 v26; // xmm0
  __m128i v27; // xmm4
  __m128 v28; // xmm3
  unsigned int v29; // esi
  int v30; // eax
  hkResultEnum m_enum; // r13d
  int *v32; // rbx
  int v33; // r8d
  _DWORD *v34; // r9
  __int32 v35; // r14d
  char *v36; // rdx
  __int64 v37; // rdi
  int *v38; // rbx
  int v39; // r8d
  int v40; // eax
  char *v41; // rcx
  __int64 v42; // r8
  __int64 v43; // r14
  int v44; // r9d
  __int64 v45; // rdi
  int *v46; // rbx
  int v47; // r8d
  __int64 v48; // rcx
  char *v49; // r8
  __int64 v50; // rdi
  int *v51; // rbx
  int v52; // r8d
  __int64 v53; // rdi
  int *v54; // rbx
  int v55; // r8d
  __int64 v57; // rdi
  int *v58; // rbx
  int v59; // r8d
  __int64 v60; // rdi
  int *v61; // rbx
  int v62; // r8d
  hkResultEnum v63; // r15d
  __int64 v64; // rbx
  _DWORD *v65; // rdi
  char *v66; // r12
  char *v67; // r14
  int v68; // r9d
  char *v69; // r14
  int v70; // r9d
  hkResultEnum v71; // eax
  int v72; // ecx
  unsigned __int64 v73; // rdx
  unsigned __int64 v74; // rdx
  int v75; // ecx
  unsigned __int64 v76; // rdx
  __int64 v77; // rcx
  bool v78; // cc
  int v79; // ecx
  __int64 v80; // r10
  _DWORD *v81; // r8
  __int64 v82; // rdi
  char *v83; // rax
  __int64 v84; // rdx
  __int64 v85; // r14
  unsigned __int64 v86; // rax
  int v87; // ebx
  __int64 v88; // rax
  __int64 v89; // r15
  int v90; // r12d
  __int64 v91; // r13
  int NumSharedVertices; // eax
  __int64 v93; // r9
  __int64 v94; // r10
  __int32 v95; // edx
  __int64 v96; // rbx
  __int64 v97; // r11
  __int64 v98; // r14
  _DWORD *v99; // r14
  __int64 v100; // rdi
  int *v101; // rbx
  int v102; // r8d
  __int64 v103; // rdi
  int *v104; // rbx
  int v105; // r8d
  __int64 v106; // rdi
  int *v107; // rbx
  int v108; // r8d
  __int64 v109; // rdi
  int *v110; // rbx
  int v111; // r8d
  __int128 v112; // xmm0
  __m128 v113; // xmm1
  __int64 v114; // rdx
  __int64 v115; // r10
  __int128 v116; // xmm0
  __int64 v117; // r10
  __int64 v118; // r11
  __int128 v119; // xmm0
  __int64 v120; // r10
  __int128 v121; // xmm0
  __int64 v122; // r10
  __int128 v123; // xmm0
  __int64 v124; // r9
  __int128 v125; // xmm0
  float v126; // xmm15_4
  char v127; // dl
  char v128; // r9
  float v129; // xmm8_4
  float v130; // xmm2_4
  float v131; // xmm1_4
  float v132; // xmm12_4
  float v133; // xmm11_4
  float v134; // xmm8_4
  float v135; // xmm10_4
  bool v136; // cl
  float v137; // xmm5_4
  float v138; // xmm6_4
  bool v139; // al
  __int64 v140; // rax
  int v141; // eax
  int v142; // r9d
  int v143; // eax
  char *v144; // r10
  int v145; // eax
  int v146; // r9d
  int v147; // eax
  hkResultEnum v148; // eax
  __int64 v149; // r15
  __int32 v150; // esi
  int v151; // r11d
  __int64 v152; // r9
  int v153; // ebx
  int v154; // r14d
  __int64 v155; // rax
  __int64 v156; // rcx
  __int64 v157; // rcx
  int v158; // edx
  __int64 v159; // rdx
  __int64 v160; // rax
  char *v161; // rax
  __int64 v162; // rcx
  int v163; // edx
  __int64 v164; // rdx
  int v165; // eax
  int v166; // r8d
  __int64 v167; // r11
  __int64 v168; // r9
  __int64 v169; // rcx
  __int64 v170; // rcx
  int v171; // edi
  int *v172; // r14
  int v173; // r15d
  hkResult *v174; // rbx
  _DWORD *v175; // rsi
  int v176; // edi
  hkVector4f *v177; // r15
  __int64 v178; // r10
  __int64 v179; // r11
  __int64 v180; // r13
  char *v181; // rdx
  __int64 v182; // r9
  hkResultEnum *v183; // rcx
  hkResult *v184; // r8
  __int64 v185; // rdx
  hkResultEnum v186; // eax
  bool v187; // sf
  int v188; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v189; // rbx
  int v190; // edi
  hkArray<int,hkContainerHeapAllocator> *v191; // rbx
  int v192; // r8d
  int v193; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v194; // rbx
  int v195; // edi
  hkArray<int,hkContainerHeapAllocator> *v196; // rbx
  int v197; // r8d
  int v198; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v199; // rbx
  int v200; // edi
  hkArray<int,hkContainerHeapAllocator> *v201; // rbx
  unsigned int v202; // r13d
  _DWORD *v203; // r8
  _DWORD *v204; // rdi
  __int64 v205; // r12
  int v206; // ebx
  __int64 v207; // r11
  __int64 v208; // r10
  int v209; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v210; // rbx
  int v211; // edi
  hkArray<int,hkContainerHeapAllocator> *v212; // rbx
  char *v213; // [rsp+30h] [rbp-98h] BYREF
  unsigned int v214; // [rsp+38h] [rbp-90h]
  int v215; // [rsp+3Ch] [rbp-8Ch]
  char *array; // [rsp+40h] [rbp-88h] BYREF
  __int64 v217; // [rsp+48h] [rbp-80h]
  __int64 v218; // [rsp+50h] [rbp-78h]
  hkResult v219; // [rsp+58h] [rbp-70h] BYREF
  hkResult v220; // [rsp+5Ch] [rbp-6Ch] BYREF
  __int64 v221; // [rsp+60h] [rbp-68h]
  void *v222; // [rsp+68h] [rbp-60h] BYREF
  __int64 v223; // [rsp+70h] [rbp-58h]
  __int64 v224; // [rsp+78h] [rbp-50h]
  __int64 v225; // [rsp+80h] [rbp-48h]
  __int64 v226; // [rsp+88h] [rbp-40h]
  __int64 v227; // [rsp+90h] [rbp-38h]
  __int64 v228; // [rsp+98h] [rbp-30h]
  __int64 v229; // [rsp+A0h] [rbp-28h]
  __int64 v230; // [rsp+A8h] [rbp-20h]
  __int64 v231; // [rsp+B0h] [rbp-18h]
  __int64 v232; // [rsp+B8h] [rbp-10h]
  __int64 v233; // [rsp+C0h] [rbp-8h]
  __int64 v234; // [rsp+C8h] [rbp+0h]
  __int64 v235; // [rsp+D0h] [rbp+8h]
  __int64 v236; // [rsp+D8h] [rbp+10h]
  __int64 v237; // [rsp+E0h] [rbp+18h]
  __m128 v238; // [rsp+E8h] [rbp+20h]
  _DWORD *v239; // [rsp+1D8h] [rbp+110h]
  __int64 v240; // [rsp+1E0h] [rbp+118h]
  __int64 v241; // [rsp+1F0h] [rbp+128h]
  __int64 v242; // [rsp+1F8h] [rbp+130h]
  hkResult resulta; // [rsp+200h] [rbp+138h] BYREF
  float *retaddr; // [rsp+208h] [rbp+140h]
  _DWORD *v247; // [rsp+220h] [rbp+158h]

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v17 = _mm_add_epi32(si128, si128);
  *(float *)&v218 = retaddr[13] * 0.017453292;
  v18 = _mm_add_ps((__m128)(unsigned int)v218, *(__m128 *)_xmm);
  v19 = _mm_andnot_ps(*(__m128 *)_xmm, v18);
  v20 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v19, *(__m128 *)_xmm)), si128));
  v21 = _mm_cvtepi32_ps(v20);
  v22 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v20, v17), (__m128i)0i64);
  v23 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v21, *(__m128 *)DP1_0), v19), _mm_mul_ps(v21, *(__m128 *)DP2)),
          _mm_mul_ps(v21, *(__m128 *)DP3));
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_andnot_ps(
          v22,
          _mm_add_ps(
            _mm_sub_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v24, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v24),
                    *(__m128 *)cosCoeff2_0),
                  v24),
                v24),
              _mm_mul_ps(v24, *(__m128 *)_xmm)),
            *(__m128 *)_xmm));
  v26 = _mm_and_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v24, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v24),
                  *(__m128 *)sinCoeff2_0),
                v24),
              v23),
            v23),
          v22);
  v27 = _mm_load_si128(numIndices);
  v28 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u);
  v238 = _mm_xor_ps(
           _mm_xor_ps(
             _mm_or_ps(v25, v26),
             _mm_xor_ps(
               (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v17, v17), v20), 0x1Du),
               _mm_and_ps(v18, *(__m128 *)_xmm))),
           *(__m128 *)_xmm);
  v29 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v28, v28, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v28, v28, 85),
                                                                       _mm_shuffle_ps(v28, v28, 0))),
                                                                   v28),
                                                                 (__m128)xmmword_141A4D8E0))];
  LODWORD(v218) = v29;
  v30 = _mm_movemask_ps(_mm_cmplt_ps((__m128)v27, (__m128)0i64));
  if ( _bittest(&v30, v29) )
  {
    v29 += 3;
    LODWORD(v218) = v29;
  }
  m_enum = resulta.m_enum;
  v32 = oppEdges;
  v247 = v13;
  v33 = 0;
  v217 = 0x8000000000000000ui64;
  v34 = 0i64;
  v213 = 0i64;
  v214 = 0;
  v215 = 0x80000000;
  v35 = resulta.m_enum / 3;
  v36 = 0i64;
  array = 0i64;
  *oppEdges = resulta.m_enum / 3;
  if ( v35 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v35, 16);
    v36 = array;
    v34 = v213;
    if ( resulta.m_enum )
      goto LABEL_19;
    v33 = v217;
  }
  v37 = v33 - v35 - 1;
  if ( v33 - v35 - 1 >= 0 )
  {
    v38 = (int *)&v36[16 * v35 + 12 + 16 * v37];
    do
    {
      v39 = *v38;
      *(v38 - 1) = 0;
      if ( v39 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v38 - 3),
          (unsigned int)(4 * v39),
          v34);
      *(_QWORD *)(v38 - 3) = 0i64;
      *v38 = 0x80000000;
      v38 -= 4;
      --v37;
    }
    while ( v37 >= 0 );
    v33 = v217;
    v36 = array;
    v34 = v213;
    v32 = oppEdges;
  }
  v40 = v35 - v33;
  v41 = &v36[16 * v33];
  v42 = v35 - v33;
  if ( v40 > 0 )
  {
    do
    {
      if ( v41 )
      {
        *(_QWORD *)v41 = 0i64;
        *((_DWORD *)v41 + 2) = 0;
        *((_DWORD *)v41 + 3) = 0x80000000;
      }
      v41 += 16;
      --v42;
    }
    while ( v42 );
    v36 = array;
    v34 = v213;
  }
  LODWORD(v217) = v35;
LABEL_19:
  v43 = *v32;
  if ( (v215 & 0x3FFFFFFF) >= (int)v43 )
  {
    LODWORD(numIndices) = 0;
LABEL_25:
    v45 = (int)(v214 - v43 - 1);
    if ( (int)(v214 - v43 - 1) >= 0 )
    {
      v46 = &v34[4 * v43 + 3 + 4 * v45];
      do
      {
        v47 = *v46;
        *(v46 - 1) = 0;
        if ( v47 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v46 - 3),
            8 * v47);
        *(_QWORD *)(v46 - 3) = 0i64;
        *v46 = 0x80000000;
        v46 -= 4;
        --v45;
      }
      while ( v45 >= 0 );
      v36 = array;
      v34 = v213;
    }
    v48 = (int)(v43 - v214);
    v49 = (char *)&v34[4 * v214];
    if ( (int)(v43 - v214) > 0 )
    {
      do
      {
        if ( v49 )
        {
          *(_QWORD *)v49 = 0i64;
          *((_DWORD *)v49 + 2) = 0;
          *((_DWORD *)v49 + 3) = 0x80000000;
        }
        v49 += 16;
        --v48;
      }
      while ( v48 );
      v36 = array;
      v34 = v213;
    }
    v214 = v43;
    goto LABEL_37;
  }
  v44 = *v32;
  if ( (int)v43 < 2 * (v215 & 0x3FFFFFFF) )
    v44 = 2 * (v215 & 0x3FFFFFFF);
  hkArrayUtil::_reserve((hkResult *)&numIndices, &hkContainerHeapAllocator::s_alloc, &v213, v44, 16);
  v36 = array;
  v34 = v213;
  if ( !(_DWORD)numIndices )
    goto LABEL_25;
  LODWORD(v43) = v214;
LABEL_37:
  if ( resulta.m_enum )
  {
    result->m_enum = HK_FAILURE;
    v50 = (int)v43 - 1;
    if ( (int)v43 - 1 >= 0 )
    {
      v51 = &v34[4 * v50 + 3];
      do
      {
        v52 = *v51;
        *(v51 - 1) = 0;
        if ( v52 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v51 - 3),
            8 * v52);
        *(_QWORD *)(v51 - 3) = 0i64;
        *v51 = 0x80000000;
        v51 -= 4;
        --v50;
      }
      while ( v50 >= 0 );
      v36 = array;
      v34 = v213;
    }
    v214 = 0;
    if ( v215 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v34, 16 * v215);
      v36 = array;
    }
    v213 = 0i64;
    v215 = 0x80000000;
    v53 = (int)v217 - 1;
    if ( (int)v217 - 1 < 0 )
      goto LABEL_52;
    v54 = (int *)&v36[16 * (int)v217 - 4];
    do
    {
      v55 = *v54;
      *(v54 - 1) = 0;
      if ( v55 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v54 - 3),
          (unsigned int)(4 * v55),
          v34);
      *(_QWORD *)(v54 - 3) = 0i64;
      *v54 = 0x80000000;
      v54 -= 4;
      --v53;
    }
    while ( v53 >= 0 );
LABEL_51:
    v36 = array;
LABEL_52:
    LODWORD(v217) = 0;
    if ( v217 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v36,
        (unsigned int)(16 * HIDWORD(v217)),
        v34);
    return result;
  }
  if ( (_DWORD)numIndices )
  {
    result->m_enum = HK_FAILURE;
    v57 = (int)v43 - 1;
    if ( (int)v43 - 1 >= 0 )
    {
      v58 = &v34[4 * v57 + 3];
      do
      {
        v59 = *v58;
        *(v58 - 1) = 0;
        if ( v59 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v58 - 3),
            8 * v59);
        *(_QWORD *)(v58 - 3) = 0i64;
        *v58 = 0x80000000;
        v58 -= 4;
        --v57;
      }
      while ( v57 >= 0 );
      v36 = array;
      v34 = v213;
    }
    v214 = 0;
    if ( v215 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v34, 16 * v215);
      v36 = array;
    }
    v213 = 0i64;
    v215 = 0x80000000;
    v60 = (int)v217 - 1;
    if ( (int)v217 - 1 < 0 )
      goto LABEL_52;
    v61 = (int *)&v36[16 * (int)v217 - 4];
    do
    {
      v62 = *v61;
      *(v61 - 1) = 0;
      if ( v62 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v61 - 3),
          (unsigned int)(4 * v62),
          v34);
      *(_QWORD *)(v61 - 3) = 0i64;
      *v61 = 0x80000000;
      v61 -= 4;
      --v60;
    }
    while ( v60 >= 0 );
    goto LABEL_51;
  }
  v63 = HK_SUCCESS;
  if ( m_enum <= HK_SUCCESS )
    goto LABEL_100;
  v64 = 0i64;
  v65 = (_DWORD *)(v242 + 4);
  v66 = (char *)triangleIndices - v242;
  while ( 1 )
  {
    v67 = &v36[v64];
    if ( (*(_DWORD *)&v36[v64 + 12] & 0x3FFFFFFFu) >= 3 )
    {
      LODWORD(numIndices) = 0;
LABEL_78:
      *((_DWORD *)v67 + 2) = 3;
      goto LABEL_79;
    }
    v68 = 3;
    if ( 2 * (*(_DWORD *)&v36[v64 + 12] & 0x3FFFFFFF) > 3 )
      v68 = 2 * (*(_DWORD *)&v36[v64 + 12] & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&numIndices, &hkContainerHeapAllocator::s_alloc, v67, v68, 4);
    if ( !(_DWORD)numIndices )
      goto LABEL_78;
LABEL_79:
    v69 = &v213[v64];
    if ( (*(_DWORD *)&v213[v64 + 12] & 0x3FFFFFFFu) >= 3 )
    {
      resulta.m_enum = HK_SUCCESS;
LABEL_85:
      *((_DWORD *)v69 + 2) = 3;
      v71 = resulta.m_enum;
      goto LABEL_86;
    }
    v70 = 3;
    if ( 2 * (*(_DWORD *)&v213[v64 + 12] & 0x3FFFFFFF) > 3 )
      v70 = 2 * (*(_DWORD *)&v213[v64 + 12] & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v213[v64], v70, 8);
    v71 = resulta.m_enum;
    if ( resulta.m_enum == HK_SUCCESS )
      goto LABEL_85;
LABEL_86:
    if ( (_DWORD)numIndices )
    {
      v99 = v239;
      *v239 = 1;
      v106 = (int)(v214 - 1);
      if ( (int)(v214 - 1) >= 0 )
      {
        v107 = (int *)&v213[16 * (v214 - 1) + 12];
        do
        {
          v108 = *v107;
          *(v107 - 1) = 0;
          if ( v108 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v107 - 3),
              8 * v108);
          *(_QWORD *)(v107 - 3) = 0i64;
          *v107 = 0x80000000;
          v107 -= 4;
          --v106;
        }
        while ( v106 >= 0 );
      }
      v214 = 0;
      if ( v215 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v213, 16 * v215);
      v213 = 0i64;
      v215 = 0x80000000;
      v109 = (int)v217 - 1;
      if ( (int)v217 - 1 >= 0 )
      {
        v110 = (int *)&array[16 * (int)v217 - 4];
        do
        {
          v111 = *v110;
          *(v110 - 1) = 0;
          if ( v111 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v110 - 3),
              4 * v111);
          *(_QWORD *)(v110 - 3) = 0i64;
          *v110 = 0x80000000;
          v110 -= 4;
          --v109;
        }
        while ( v109 >= 0 );
      }
      goto LABEL_136;
    }
    if ( v71 )
    {
      v99 = v239;
      *v239 = 1;
      v100 = (int)(v214 - 1);
      if ( (int)(v214 - 1) >= 0 )
      {
        v101 = (int *)&v213[16 * (v214 - 1) + 12];
        do
        {
          v102 = *v101;
          *(v101 - 1) = 0;
          if ( v102 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v101 - 3),
              8 * v102);
          *(_QWORD *)(v101 - 3) = 0i64;
          *v101 = 0x80000000;
          v101 -= 4;
          --v100;
        }
        while ( v100 >= 0 );
      }
      v214 = 0;
      if ( v215 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v213, 16 * v215);
      v213 = 0i64;
      v215 = 0x80000000;
      v103 = (int)v217 - 1;
      if ( (int)v217 - 1 >= 0 )
      {
        v104 = (int *)&array[16 * (int)v217 - 4];
        do
        {
          v105 = *v104;
          *(v104 - 1) = 0;
          if ( v105 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(v104 - 3),
              4 * v105);
          *(_QWORD *)(v104 - 3) = 0i64;
          *v104 = 0x80000000;
          v104 -= 4;
          --v103;
        }
        while ( v103 >= 0 );
      }
LABEL_136:
      LODWORD(v217) = 0;
      if ( v217 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * HIDWORD(v217));
      return (hkResult *)v99;
    }
    **(_DWORD **)&array[v64] = *(_DWORD *)((char *)v65 + (_QWORD)v66 - 4);
    *(_DWORD *)(*(_QWORD *)&array[v64] + 4i64) = *(_DWORD *)((char *)v65 + (_QWORD)v66);
    *(_DWORD *)(*(_QWORD *)&array[v64] + 8i64) = *(_DWORD *)((char *)v65 + (_QWORD)v66 + 4);
    v72 = *(v65 - 1);
    v73 = v72 == -1 ? -1i64 : (v72 % 3) | (unsigned __int64)((__int64)(v72 / 3) << 32);
    **(_QWORD **)&v213[v64] = v73;
    v74 = *v65 == -1 ? -1i64 : (*v65 % 3) | (unsigned __int64)((__int64)(*v65 / 3) << 32);
    *(_QWORD *)(*(_QWORD *)&v213[v64] + 8i64) = v74;
    v75 = v65[1];
    v76 = v75 == -1 ? -1i64 : (v75 % 3) | (unsigned __int64)((__int64)(v75 / 3) << 32);
    v63 += 3;
    v65 += 3;
    v77 = *(_QWORD *)&v213[v64];
    v64 += 16i64;
    *(_QWORD *)(v77 + 16) = v76;
    if ( v63 >= m_enum )
      break;
    v36 = array;
  }
  v34 = v213;
  do
  {
LABEL_100:
    v78 = (int)v217 <= 0;
    v79 = 0;
    v80 = 0i64;
    v217 = 0i64;
    LOBYTE(resulta.m_enum) = 0;
    LODWORD(numIndices) = 0;
    if ( v78 )
      break;
    v81 = array;
    do
    {
      v82 = 16 * v80;
      v228 = 16 * v80;
      if ( v81[4 * v80 + 2] )
      {
        v83 = v213;
        v84 = 0i64;
        v219.m_enum = HK_SUCCESS;
        v78 = *(_DWORD *)&v213[v82 + 8] <= 0;
        v218 = 0i64;
        if ( !v78 )
        {
          do
          {
            v85 = *(_QWORD *)&v83[v82];
            v235 = v85;
            v86 = *(_QWORD *)(v85 + 8 * v84);
            if ( v86 == -1i64 )
              goto LABEL_243;
            v87 = *(_DWORD *)((char *)v81 + v82 + 8);
            v88 = HIDWORD(v86);
            v89 = (int)v88;
            v229 = v88;
            v223 = 16i64 * (int)v88;
            v90 = *(_DWORD *)((char *)v81 + v223 + 8);
            if ( !v87 || !v90 || v87 + v90 - 2 >= *((_DWORD *)retaddr + 14) )
              goto LABEL_243;
            v230 = v79;
            v91 = 16i64 * v79;
            NumSharedVertices = getNumSharedVertices(
                                  (hkArrayBase<int> *)&v81[(unsigned __int64)v91 / 4],
                                  (hkArrayBase<int> *)((char *)v81 + v223));
            v80 = v217;
            if ( NumSharedVertices == 2 )
            {
              v81 = array;
              if ( *(_DWORD *)(v241 + 4 * v217) != *(_DWORD *)(v241 + 4 * v89) )
                goto LABEL_242;
              v93 = *(_QWORD *)&array[v82];
              v94 = *(int *)(v93 + 4 * v218);
              LODWORD(v224) = (v87 + v219.m_enum - 1) % v87;
              v95 = (v219.m_enum + 2) % v87;
              v96 = *(int *)(v85 + 8 * v218);
              v97 = v95;
              LODWORD(v221) = ((int)v96 + v90 - 1) % v90;
              LODWORD(v224) = ((int)v96 + 1) % v90;
              v98 = ((int)v96 + 2) % v90;
              switch ( v29 )
              {
                case 0u:
                  *(_QWORD *)&v112 = _mm_shuffle_ps(*(__m128 *)(v240 + 16 * v94), *(__m128 *)(v240 + 16 * v94), 233).m128_u64[0];
                  goto LABEL_145;
                case 1u:
                  v113 = (__m128)xmmword_141A71320;
                  *(_QWORD *)&v112 = _mm_mul_ps(
                                       _mm_shuffle_ps(*(__m128 *)(v240 + 16 * v94), *(__m128 *)(v240 + 16 * v94), 136),
                                       (__m128)xmmword_141A71320).m128_u64[0];
                  goto LABEL_146;
                case 2u:
                  v112 = *(_OWORD *)(v240 + 16 * v94);
                  goto LABEL_145;
                case 3u:
                  *(_QWORD *)&v112 = _mm_shuffle_ps(*(__m128 *)(v240 + 16 * v94), *(__m128 *)(v240 + 16 * v94), 230).m128_u64[0];
                  goto LABEL_145;
                case 4u:
                  v113 = (__m128)xmmword_141A71320;
                  *(_QWORD *)&v112 = _mm_mul_ps(
                                       _mm_shuffle_ps(*(__m128 *)(v240 + 16 * v94), *(__m128 *)(v240 + 16 * v94), 210),
                                       (__m128)xmmword_141A71320).m128_u64[0];
                  goto LABEL_146;
                case 5u:
                  *(_QWORD *)&v112 = _mm_shuffle_ps(*(__m128 *)(v240 + 16 * v94), *(__m128 *)(v240 + 16 * v94), 225).m128_u64[0];
                  goto LABEL_145;
                default:
                  *(_QWORD *)&v112 = 0i64;
LABEL_145:
                  v113 = (__m128)xmmword_141A71320;
LABEL_146:
                  v236 = v112;
                  v114 = *(_QWORD *)&array[v223];
                  v221 = v112;
                  v115 = *(int *)(v114 + 4 * v96);
                  switch ( v29 )
                  {
                    case 0u:
                      *(_QWORD *)&v116 = _mm_shuffle_ps(
                                           *(__m128 *)(v240 + 16 * v115),
                                           *(__m128 *)(v240 + 16 * v115),
                                           233).m128_u64[0];
                      break;
                    case 1u:
                      *(_QWORD *)&v116 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v240 + 16 * v115),
                                             *(__m128 *)(v240 + 16 * v115),
                                             136),
                                           v113).m128_u64[0];
                      break;
                    case 2u:
                      v116 = *(_OWORD *)(v240 + 16 * v115);
                      break;
                    case 3u:
                      *(_QWORD *)&v116 = _mm_shuffle_ps(
                                           *(__m128 *)(v240 + 16 * v115),
                                           *(__m128 *)(v240 + 16 * v115),
                                           230).m128_u64[0];
                      break;
                    case 4u:
                      *(_QWORD *)&v116 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v240 + 16 * v115),
                                             *(__m128 *)(v240 + 16 * v115),
                                             210),
                                           v113).m128_u64[0];
                      break;
                    case 5u:
                      *(_QWORD *)&v116 = _mm_shuffle_ps(
                                           *(__m128 *)(v240 + 16 * v115),
                                           *(__m128 *)(v240 + 16 * v115),
                                           225).m128_u64[0];
                      break;
                    default:
                      *(_QWORD *)&v116 = 0i64;
                      break;
                  }
                  v117 = *(int *)(v93 + 4 * v97);
                  v233 = v116;
                  v225 = v116;
                  switch ( v29 )
                  {
                    case 0u:
                      v118 = v240;
                      *(_QWORD *)&v119 = _mm_shuffle_ps(
                                           *(__m128 *)(v240 + 16 * v117),
                                           *(__m128 *)(v240 + 16 * v117),
                                           233).m128_u64[0];
                      break;
                    case 1u:
                      v118 = v240;
                      *(_QWORD *)&v119 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v240 + 16 * v117),
                                             *(__m128 *)(v240 + 16 * v117),
                                             136),
                                           v113).m128_u64[0];
                      break;
                    case 2u:
                      v118 = v240;
                      v119 = *(_OWORD *)(v240 + 16 * v117);
                      break;
                    case 3u:
                      v118 = v240;
                      *(_QWORD *)&v119 = _mm_shuffle_ps(
                                           *(__m128 *)(v240 + 16 * v117),
                                           *(__m128 *)(v240 + 16 * v117),
                                           230).m128_u64[0];
                      break;
                    case 4u:
                      v118 = v240;
                      *(_QWORD *)&v119 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v240 + 16 * v117),
                                             *(__m128 *)(v240 + 16 * v117),
                                             210),
                                           v113).m128_u64[0];
                      break;
                    case 5u:
                      v118 = v240;
                      *(_QWORD *)&v119 = _mm_shuffle_ps(
                                           *(__m128 *)(v240 + 16 * v117),
                                           *(__m128 *)(v240 + 16 * v117),
                                           225).m128_u64[0];
                      break;
                    default:
                      v118 = v240;
                      *(_QWORD *)&v119 = 0i64;
                      break;
                  }
                  v120 = *(int *)(v114 + 4 * v98);
                  v232 = v119;
                  v227 = v119;
                  switch ( v29 )
                  {
                    case 0u:
                      *(_QWORD *)&v121 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v120),
                                           *(__m128 *)(v118 + 16 * v120),
                                           233).m128_u64[0];
                      break;
                    case 1u:
                      *(_QWORD *)&v121 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v118 + 16 * v120),
                                             *(__m128 *)(v118 + 16 * v120),
                                             136),
                                           v113).m128_u64[0];
                      break;
                    case 2u:
                      v121 = *(_OWORD *)(v118 + 16 * v120);
                      break;
                    case 3u:
                      *(_QWORD *)&v121 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v120),
                                           *(__m128 *)(v118 + 16 * v120),
                                           230).m128_u64[0];
                      break;
                    case 4u:
                      *(_QWORD *)&v121 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v118 + 16 * v120),
                                             *(__m128 *)(v118 + 16 * v120),
                                             210),
                                           v113).m128_u64[0];
                      break;
                    case 5u:
                      *(_QWORD *)&v121 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v120),
                                           *(__m128 *)(v118 + 16 * v120),
                                           225).m128_u64[0];
                      break;
                    default:
                      *(_QWORD *)&v121 = 0i64;
                      break;
                  }
                  v234 = v121;
                  v226 = v121;
                  v122 = *(int *)(v93 + 4i64 * (int)v224);
                  switch ( v29 )
                  {
                    case 0u:
                      *(_QWORD *)&v123 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v122),
                                           *(__m128 *)(v118 + 16 * v122),
                                           233).m128_u64[0];
                      break;
                    case 1u:
                      *(_QWORD *)&v123 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v118 + 16 * v122),
                                             *(__m128 *)(v118 + 16 * v122),
                                             136),
                                           v113).m128_u64[0];
                      break;
                    case 2u:
                      v123 = *(_OWORD *)(v118 + 16 * v122);
                      break;
                    case 3u:
                      *(_QWORD *)&v123 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v122),
                                           *(__m128 *)(v118 + 16 * v122),
                                           230).m128_u64[0];
                      break;
                    case 4u:
                      *(_QWORD *)&v123 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v118 + 16 * v122),
                                             *(__m128 *)(v118 + 16 * v122),
                                             210),
                                           v113).m128_u64[0];
                      break;
                    case 5u:
                      *(_QWORD *)&v123 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v122),
                                           *(__m128 *)(v118 + 16 * v122),
                                           225).m128_u64[0];
                      break;
                    default:
                      *(_QWORD *)&v123 = 0i64;
                      break;
                  }
                  v237 = v123;
                  v224 = v123;
                  v124 = *(int *)(v114 + 4i64 * (int)v221);
                  switch ( v29 )
                  {
                    case 0u:
                      *(_QWORD *)&v125 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v124),
                                           *(__m128 *)(v118 + 16 * v124),
                                           233).m128_u64[0];
                      break;
                    case 1u:
                      *(_QWORD *)&v125 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v118 + 16 * v124),
                                             *(__m128 *)(v118 + 16 * v124),
                                             136),
                                           v113).m128_u64[0];
                      break;
                    case 2u:
                      v125 = *(_OWORD *)(v118 + 16 * v124);
                      break;
                    case 3u:
                      *(_QWORD *)&v125 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v124),
                                           *(__m128 *)(v118 + 16 * v124),
                                           230).m128_u64[0];
                      break;
                    case 4u:
                      *(_QWORD *)&v125 = _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             *(__m128 *)(v118 + 16 * v124),
                                             *(__m128 *)(v118 + 16 * v124),
                                             210),
                                           v113).m128_u64[0];
                      break;
                    case 5u:
                      *(_QWORD *)&v125 = _mm_shuffle_ps(
                                           *(__m128 *)(v118 + 16 * v124),
                                           *(__m128 *)(v118 + 16 * v124),
                                           225).m128_u64[0];
                      break;
                    default:
                      *(_QWORD *)&v125 = 0i64;
                      break;
                  }
                  v126 = *(float *)&v221;
                  v127 = 1;
                  v128 = 1;
                  v129 = *(float *)&v221;
                  v130 = *((float *)&v221 + 1);
                  v231 = v125;
                  v131 = *((float *)&v221 + 1) - *((float *)&v224 + 1);
                  v221 = v125;
                  v132 = *((float *)&v224 + 1) - v130;
                  v133 = *(float *)&v224 - v126;
                  v134 = (float)((float)(v129 - *(float *)&v224) * (float)(*((float *)&v226 + 1) - *((float *)&v224 + 1)))
                       - (float)(v131 * (float)(*(float *)&v226 - *(float *)&v224));
                  v135 = (float)((float)(*(float *)&v225 - *(float *)&v125)
                               * (float)(*((float *)&v227 + 1) - *((float *)&v125 + 1)))
                       - (float)((float)(*(float *)&v227 - *(float *)&v125)
                               * (float)(*((float *)&v225 + 1) - *((float *)&v125 + 1)));
                  if ( (float)((float)((float)(*((float *)&v224 + 1) - v130) * *((float *)&v226 + 1))
                             + (float)((float)(*(float *)&v224 - v126) * *(float *)&v226)) <= (float)((float)((float)(*(float *)&v224 - v126) * v126) + (float)((float)(*((float *)&v224 + 1) - v130) * *((float *)&v125 + 1))) )
                  {
                    v136 = v134 >= 0.0;
                  }
                  else
                  {
                    v127 = 0;
                    v136 = v134 > 0.0;
                  }
                  v137 = *(float *)&v125 - *(float *)&v225;
                  v138 = *((float *)&v125 + 1) - *((float *)&v225 + 1);
                  if ( (float)((float)(v138 * *((float *)&v227 + 1)) + (float)(v137 * *(float *)&v227)) <= (float)((float)(v137 * *(float *)&v225) + (float)(v138 * *((float *)&v225 + 1))) )
                  {
                    v139 = v135 >= 0.0;
                  }
                  else
                  {
                    v128 = 0;
                    v139 = v135 > 0.0;
                  }
                  if ( retaddr[13] != 0.0 )
                  {
                    if ( !v136 )
                    {
                      if ( v127 )
                      {
                        *(float *)&v224 = (float)(v132 * v132) + (float)(v133 * v133);
                        *(float *)&v221 = (float)((float)(*((float *)&v226 + 1) - *((float *)&v221 + 1))
                                                * (float)(*((float *)&v226 + 1) - *((float *)&v221 + 1)))
                                        + (float)((float)(*(float *)&v226 - v126) * (float)(*(float *)&v226 - v126));
                        if ( v238.m128_f32[0] > (float)((float)((float)((float)(*((float *)&v226 + 1)
                                                                              - *((float *)&v221 + 1))
                                                                      * v132)
                                                              + (float)((float)(*(float *)&v226 - v126) * v133))
                                                      / (float)(fsqrt(*(float *)&v221) * fsqrt(*(float *)&v224))) )
                          v136 = 1;
                      }
                    }
                    if ( !v139 )
                    {
                      if ( v128 )
                      {
                        *(float *)&v224 = (float)(v138 * v138) + (float)(v137 * v137);
                        *(float *)&v221 = (float)((float)(*((float *)&v227 + 1) - *((float *)&v225 + 1))
                                                * (float)(*((float *)&v227 + 1) - *((float *)&v225 + 1)))
                                        + (float)((float)(*(float *)&v227 - *(float *)&v225)
                                                * (float)(*(float *)&v227 - *(float *)&v225));
                        if ( v238.m128_f32[0] > (float)((float)((float)((float)(*((float *)&v227 + 1)
                                                                              - *((float *)&v225 + 1))
                                                                      * v138)
                                                              + (float)((float)(*(float *)&v227 - *(float *)&v225) * v137))
                                                      / (float)(fsqrt(*(float *)&v221) * fsqrt(*(float *)&v224))) )
                          v139 = 1;
                      }
                    }
                  }
                  if ( !v136 || !v139 )
                  {
                    v80 = v217;
                    goto LABEL_242;
                  }
                  v140 = *(_QWORD *)&v213[v223];
                  LOBYTE(resulta.m_enum) = 1;
                  *(_QWORD *)(v235 + 8 * v218) = *(_QWORD *)(v140 + 8i64 * (int)v224);
                  v141 = *(_DWORD *)&array[v82 + 12] & 0x3FFFFFFF;
                  v142 = v90 + *(_DWORD *)&array[v82 + 8];
                  if ( v141 >= v142 )
                  {
                    v220.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v143 = 2 * v141;
                    if ( v142 < v143 )
                      v142 = v143;
                    hkArrayUtil::_reserve(&v220, &hkContainerHeapAllocator::s_alloc, &array[v82], v142, 4);
                  }
                  v144 = v213;
                  v145 = *(_DWORD *)&v213[v82 + 12] & 0x3FFFFFFF;
                  v146 = v90 + *(_DWORD *)&v213[v82 + 8];
                  if ( v145 >= v146 )
                  {
                    v148 = HK_SUCCESS;
                    v219.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v147 = 2 * v145;
                    if ( v146 < v147 )
                      v146 = v147;
                    hkArrayUtil::_reserve(&v219, &hkContainerHeapAllocator::s_alloc, &v213[v82], v146, 8);
                    v144 = v213;
                    v148 = v219.m_enum;
                  }
                  if ( v220.m_enum )
                  {
                    v99 = v239;
                    v187 = (int)(v214 - 1) < 0;
                    v193 = v214 - 1;
                    *v239 = 1;
                    if ( !v187 )
                    {
                      v194 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v144[16 * v193];
                      do
                      {
                        hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v194--, 0);
                        --v193;
                      }
                      while ( v193 >= 0 );
                      v144 = v213;
                    }
                    v214 = 0;
                    if ( v215 >= 0 )
                      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                        &hkContainerHeapAllocator::s_alloc,
                        v144,
                        16 * v215);
                    v213 = 0i64;
                    v215 = 0x80000000;
                    v195 = v217 - 1;
                    if ( (int)v217 - 1 >= 0 )
                    {
                      v196 = (hkArray<int,hkContainerHeapAllocator> *)&array[16 * v195];
                      do
                      {
                        hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v196--, 0);
                        --v195;
                      }
                      while ( v195 >= 0 );
                    }
LABEL_269:
                    LODWORD(v217) = 0;
LABEL_270:
                    v192 = HIDWORD(v217);
                    if ( v217 >= 0 )
                    {
                      v181 = array;
                      goto LABEL_316;
                    }
                    return (hkResult *)v99;
                  }
                  if ( v148 )
                  {
                    v99 = v239;
                    v187 = (int)(v214 - 1) < 0;
                    v188 = v214 - 1;
                    *v239 = 1;
                    if ( !v187 )
                    {
                      v189 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v144[16 * v188];
                      do
                      {
                        hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v189--, 0);
                        --v188;
                      }
                      while ( v188 >= 0 );
                      v144 = v213;
                    }
                    v214 = 0;
                    if ( v215 >= 0 )
                      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                        &hkContainerHeapAllocator::s_alloc,
                        v144,
                        16 * v215);
                    v213 = 0i64;
                    v215 = 0x80000000;
                    v190 = v217 - 1;
                    if ( (int)v217 - 1 >= 0 )
                    {
                      v191 = (hkArray<int,hkContainerHeapAllocator> *)&array[16 * v190];
                      do
                      {
                        hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v191--, 0);
                        --v190;
                      }
                      while ( v190 >= 0 );
                    }
                    goto LABEL_269;
                  }
                  if ( (_DWORD)v98 != (_DWORD)v96 )
                  {
                    v149 = 2 * v89;
                    v150 = v219.m_enum + 1;
                    do
                    {
                      hkArrayBase<int>::_insertAt(
                        (hkArrayBase<int> *)&array[v91],
                        &hkContainerHeapAllocator::s_alloc,
                        v150,
                        (const int *)(*(_QWORD *)&array[8 * v149] + 4i64 * (int)v98));
                      hkArrayBase<hkClass *>::_insertAt(
                        (hkArrayBase<hkClass *> *)&v213[v91],
                        &hkContainerHeapAllocator::s_alloc,
                        v150++,
                        (hkClass *const *)(*(_QWORD *)&v213[8 * v149] + 8i64 * (int)v98));
                      LODWORD(v98) = ((int)v98 + 1) % v90;
                    }
                    while ( (_DWORD)v98 != (_DWORD)v96 );
                    v144 = v213;
                    v82 = v228;
                    v29 = v218;
                  }
                  v151 = *(_DWORD *)&v144[v82 + 8] - 1;
                  v152 = v151;
                  if ( v151 >= 0 )
                  {
                    v153 = v229;
                    v154 = (int)numIndices;
                    do
                    {
                      v155 = *(_QWORD *)&v144[v82];
                      v156 = HIDWORD(*(_QWORD *)(v155 + 8 * v152));
                      if ( (_DWORD)v156 == v153 || (_DWORD)v156 == v154 )
                      {
                        --*(_DWORD *)&v144[v82 + 8];
                        v157 = v155 + 8 * v152;
                        v158 = 8 * (*(_DWORD *)&v144[v82 + 8] - v151);
                        if ( v158 > 0 )
                        {
                          v159 = ((unsigned int)(v158 - 1) >> 3) + 1;
                          do
                          {
                            v160 = *(_QWORD *)(v157 + 8);
                            v157 += 8i64;
                            *(_QWORD *)(v157 - 8) = v160;
                            --v159;
                          }
                          while ( v159 );
                        }
                        v161 = array;
                        --*(_DWORD *)&array[v82 + 8];
                        v162 = *(_QWORD *)&v161[v82] + 4 * v152;
                        v163 = 4 * (*(_DWORD *)&v161[v82 + 8] - v151);
                        if ( v163 > 0 )
                        {
                          v164 = ((unsigned int)(v163 - 1) >> 2) + 1;
                          do
                          {
                            v165 = *(_DWORD *)(v162 + 4);
                            v162 += 4i64;
                            *(_DWORD *)(v162 - 4) = v165;
                            --v164;
                          }
                          while ( v164 );
                        }
                        v144 = v213;
                      }
                      --v151;
                      --v152;
                    }
                    while ( v152 >= 0 );
                  }
                  if ( *(_DWORD *)&array[v82 + 8] == 2 )
                  {
                    *(_DWORD *)&array[v82 + 8] = 0;
                    *(_DWORD *)&v213[v82 + 8] = 0;
                    v144 = v213;
                  }
                  v166 = 0;
                  if ( *(int *)&v144[v82 + 8] > 0 )
                  {
                    v167 = v230;
                    v168 = 0i64;
                    do
                    {
                      v169 = *(_QWORD *)(v168 + *(_QWORD *)&v144[v82]);
                      if ( v169 != -1 )
                      {
                        *(_QWORD *)(*(_QWORD *)&v144[16 * SHIDWORD(v169)] + 8i64 * (int)v169) = v166 | (unsigned __int64)(v167 << 32);
                        v144 = v213;
                      }
                      ++v166;
                      v168 += 8i64;
                    }
                    while ( v166 < *(_DWORD *)&v144[v82 + 8] );
                  }
                  v170 = v223;
                  v80 = v217;
                  *(_DWORD *)&array[v223 + 8] = 0;
                  *(_DWORD *)&v213[v170 + 8] = 0;
                  break;
              }
            }
            v81 = array;
LABEL_242:
            v79 = (int)numIndices;
LABEL_243:
            ++v218;
            v83 = v213;
            v84 = v218;
            ++v219.m_enum;
          }
          while ( v219.m_enum < *(_DWORD *)&v213[v82 + 8] );
        }
        v34 = v213;
      }
      ++v79;
      ++v80;
      LODWORD(numIndices) = v79;
      v217 = v80;
    }
    while ( v79 < (int)v80 );
  }
  while ( LOBYTE(resulta.m_enum) );
  v171 = v217;
  v172 = materials;
  v173 = 0x80000000;
  v174 = result;
  v175 = 0i64;
  v222 = 0i64;
  v223 = 0x8000000000000000ui64;
  if ( (int)v217 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v222, v217, 4);
    if ( resulta.m_enum )
    {
      v99 = v239;
      v197 = HIDWORD(v223);
      *v239 = 1;
      LODWORD(v223) = 0;
      if ( v197 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v222, 4 * v197);
      v222 = 0i64;
      HIDWORD(v223) = 0x80000000;
      v198 = v214 - 1;
      if ( (int)(v214 - 1) >= 0 )
      {
        v199 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v213[16 * v198];
        do
        {
          hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v199--, 0);
          --v198;
        }
        while ( v198 >= 0 );
      }
      v214 = 0;
      if ( v215 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v213, 16 * v215);
      v213 = 0i64;
      v215 = 0x80000000;
      v200 = v217 - 1;
      if ( (int)v217 - 1 >= 0 )
      {
        v201 = (hkArray<int,hkContainerHeapAllocator> *)&array[16 * v200];
        do
        {
          hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v201--, 0);
          --v200;
        }
        while ( v200 >= 0 );
      }
      LODWORD(v217) = 0;
      goto LABEL_270;
    }
    v173 = HIDWORD(v223);
    v175 = v222;
    v34 = v213;
  }
  LODWORD(v223) = v171;
  v176 = 0;
  if ( (int)v217 <= 0 )
  {
    v181 = array;
  }
  else
  {
    v177 = verts;
    v178 = 0i64;
    v179 = 0i64;
    v180 = v241;
    do
    {
      v175[v178] = v174 - result;
      v181 = array;
      v182 = *(int *)&array[v179 + 8];
      if ( (_DWORD)v182 )
      {
        v183 = *(hkResultEnum **)&array[v179];
        v184 = v174;
        if ( (int)v182 > 0 )
        {
          v185 = (unsigned int)v182;
          do
          {
            v186 = *v183;
            ++v184;
            ++v183;
            v184[-1].m_enum = v186;
            --v185;
          }
          while ( v185 );
          v181 = array;
        }
        *v172++ = v182;
        v177->m_quad.m128_i32[0] = *(_DWORD *)(v178 * 4 + v180);
        v177 = (hkVector4f *)((char *)v177 + 4);
        v174 += v182;
      }
      v175 = v222;
      ++v176;
      v179 += 16i64;
      ++v178;
    }
    while ( v176 < (int)v217 );
    v173 = HIDWORD(v223);
    v34 = v213;
  }
  v202 = v214;
  v203 = v247;
  if ( (int)v214 > 0 )
  {
    v204 = v34 + 2;
    v205 = v214;
    do
    {
      v206 = 0;
      if ( (int)*v204 > 0 )
      {
        v207 = 0i64;
        do
        {
          v208 = *(_QWORD *)(v207 + *((_QWORD *)v204 - 1));
          if ( v208 == -1 )
            *v203 = -1;
          else
            *v203 = v208 + v175[SHIDWORD(v208)];
          ++v206;
          ++v203;
          v207 += 8i64;
        }
        while ( v206 < *v204 );
      }
      v204 += 4;
      --v205;
    }
    while ( v205 );
  }
  LODWORD(v223) = 0;
  *oppEdges = v172 - materials;
  v99 = v239;
  *v239 = 0;
  if ( v173 >= 0 )
  {
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v175,
      (unsigned int)(4 * v173),
      v34);
    v202 = v214;
    v181 = array;
    v34 = v213;
  }
  v209 = v202 - 1;
  v222 = 0i64;
  HIDWORD(v223) = 0x80000000;
  if ( (int)(v202 - 1) >= 0 )
  {
    v210 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v34[4 * v209];
    do
    {
      hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v210--, 0);
      --v209;
    }
    while ( v209 >= 0 );
    v181 = array;
    v34 = v213;
  }
  v214 = 0;
  if ( v215 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v34, 16 * v215);
    v181 = array;
  }
  v213 = 0i64;
  v215 = 0x80000000;
  v211 = v217 - 1;
  if ( (int)v217 - 1 >= 0 )
  {
    v212 = (hkArray<int,hkContainerHeapAllocator> *)&v181[16 * v211];
    do
    {
      hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v212--, 0);
      --v211;
    }
    while ( v211 >= 0 );
    v181 = array;
  }
  v192 = HIDWORD(v217);
  LODWORD(v217) = 0;
  if ( v217 >= 0 )
LABEL_316:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v181, 16 * v192);
  return (hkResult *)v99;
}

// File Line: 1210
// RVA: 0xB85190
hkSimdFloat32 *__fastcall getWidthSquared(hkSimdFloat32 *result, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm2
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1

  v4 = result;
  v5 = _mm_sub_ps(c->m_quad, a->m_quad);
  v6 = _mm_sub_ps(b->m_quad, a->m_quad);
  v7 = _mm_sub_ps(b->m_quad, c->m_quad);
  v8 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6);
  v9 = _mm_mul_ps(v7, v7);
  v10 = _mm_shuffle_ps(v6, v6, 201);
  v11 = _mm_mul_ps(v6, v6);
  v12 = _mm_mul_ps(v10, v5);
  v13 = _mm_mul_ps(v5, v5);
  v14 = _mm_sub_ps(v8, v12);
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_max_ps(
          _mm_max_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170))),
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)));
  v19 = _mm_rcp_ps(v18);
  result->m_real = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v18)), v19), v17);
  return v4;
}

// File Line: 1234
// RVA: 0xB82300
hkResult *__fastcall hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn,
        hkArray<int,hkContainerHeapAllocator> *tris,
        hkArray<int,hkContainerHeapAllocator> *trisPerFace,
        hkArray<int,hkContainerHeapAllocator> *triConnectivity,
        hkArrayBase<int> *perTriangleData,
        __m128 *input)
{
  __m128 *v7; // r13
  int m_size; // ecx
  int v11; // r15d
  int v12; // ebx
  __int32 v13; // eax
  unsigned int *m_data; // rdi
  int m_capacityAndFlags; // r8d
  int v16; // r9d
  __int64 i; // rcx
  int v18; // r8d
  float v19; // xmm9_4
  float v20; // xmm11_4
  char v21; // r11
  __int64 v22; // r10
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // r9
  hkVector4f *v26; // rax
  __int64 v27; // rdx
  __int64 v28; // r9
  hkVector4f *v29; // rcx
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm3
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm10
  __m128 v38; // xmm7
  __m128 v39; // xmm6
  __m128 v40; // xmm6
  __m128 v41; // xmm3
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  float v45; // xmm5_4
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  float v48; // xmm1_4
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  hkBitField array; // [rsp+30h] [rbp-71h] BYREF
  hkResult resulta; // [rsp+100h] [rbp+5Fh] BYREF
  hkArray<int,hkContainerHeapAllocator> *trisPerFaceInOut; // [rsp+108h] [rbp+67h]

  trisPerFaceInOut = trisPerFace;
  v7 = input;
  m_size = tris->m_size;
  LOBYTE(input) = input[10].m128_i8[0] != 0;
  if ( m_size )
  {
    array.m_storage.m_words.m_data = 0i64;
    array.m_storage.m_words.m_size = 0;
    array.m_storage.m_words.m_capacityAndFlags = 0x80000000;
    v11 = m_size / 3;
    v12 = (m_size / 3 + 31) >> 5;
    v13 = v12;
    if ( v12 )
    {
      resulta.m_enum = 4 * v12;
      m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerHeapAllocator::s_alloc,
                                 &resulta);
      v13 = resulta.m_enum / 4;
    }
    else
    {
      m_data = 0i64;
    }
    m_capacityAndFlags = 0x80000000;
    array.m_storage.m_numBits = v11;
    if ( v13 )
      m_capacityAndFlags = v13;
    array.m_storage.m_words.m_data = m_data;
    array.m_storage.m_words.m_size = v12;
    array.m_storage.m_words.m_capacityAndFlags = m_capacityAndFlags;
    if ( (m_capacityAndFlags & 0x3FFFFFFF) < v12 )
    {
      v16 = v12;
      if ( v12 < 2 * (m_capacityAndFlags & 0x3FFFFFFF) )
        v16 = 2 * (m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v16, 4);
      m_capacityAndFlags = array.m_storage.m_words.m_capacityAndFlags;
      m_data = array.m_storage.m_words.m_data;
    }
    array.m_storage.m_words.m_size = v12;
    if ( m_data )
    {
      if ( v12 - 1 >= 0 )
      {
        for ( i = (unsigned int)v12; i; --i )
          *m_data++ = 0;
        m_data = array.m_storage.m_words.m_data;
      }
      v18 = 0;
      LODWORD(v19) = _mm_shuffle_ps((__m128)v7[3].m128_u32[0], (__m128)v7[3].m128_u32[0], 0).m128_u32[0];
      LODWORD(v20) = _mm_shuffle_ps((__m128)v7[2].m128_u32[3], (__m128)v7[2].m128_u32[3], 0).m128_u32[0];
      if ( tris->m_size > 0 )
      {
        v21 = (char)input;
        v22 = 2i64;
        do
        {
          v23 = tris->m_data[v22 - 1];
          v24 = tris->m_data[v22 - 2];
          if ( (_DWORD)v23 == (_DWORD)v24 )
            goto LABEL_31;
          v25 = tris->m_data[v22];
          if ( (_DWORD)v25 == (_DWORD)v24 )
            goto LABEL_31;
          if ( (_DWORD)v25 == (_DWORD)v23 )
            goto LABEL_31;
          v26 = vertsIn->m_data;
          v27 = v23;
          v28 = v25;
          v29 = &vertsIn->m_data[v24];
          if ( v20 != 0.0 )
          {
            v30 = _mm_sub_ps(v26[v27].m_quad, v29->m_quad);
            v31 = _mm_sub_ps(v26[v28].m_quad, v29->m_quad);
            v32 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30),
                    _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v31));
            v33 = _mm_shuffle_ps(v32, v32, 201);
            v34 = _mm_mul_ps(v33, v33);
            v35 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                    _mm_shuffle_ps(v34, v34, 170));
            v36 = _mm_rsqrt_ps(v35);
            if ( COERCE_FLOAT((2
                             * _mm_andnot_ps(
                                 _mm_cmple_ps(v35, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v36)),
                                   v35)).m128_u32[0]) >> 1) < v20 )
              goto LABEL_31;
          }
          v37 = _mm_sub_ps(v26[v28].m_quad, v29->m_quad);
          v38 = _mm_sub_ps(v26[v27].m_quad, v29->m_quad);
          v39 = _mm_sub_ps(v26[v27].m_quad, v26[v28].m_quad);
          v40 = _mm_mul_ps(v39, v39);
          v41 = _mm_mul_ps(v38, v38);
          v42 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v38),
                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v37));
          v43 = _mm_shuffle_ps(v42, v42, 201);
          v44 = _mm_mul_ps(v43, v43);
          v45 = (float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0] + _mm_shuffle_ps(v44, v44, 0).m128_f32[0])
              + _mm_shuffle_ps(v44, v44, 170).m128_f32[0];
          v46 = _mm_mul_ps(v37, v37);
          v47 = _mm_max_ps(
                  _mm_max_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                      _mm_shuffle_ps(v41, v41, 170)),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                      _mm_shuffle_ps(v46, v46, 170))),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                    _mm_shuffle_ps(v40, v40, 170)));
          LODWORD(v48) = _mm_rcp_ps(v47).m128_u32[0];
          if ( v19 != 0.0
            && (float)((float)((float)(2.0 - (float)(v48 * v47.m128_f32[0])) * v48) * v45) < (float)(v19 * v19) )
          {
            goto LABEL_31;
          }
          if ( !v21 )
          {
            v49 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v38),
                    _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v37));
            v50 = _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v7[1]);
            if ( (float)((float)(_mm_shuffle_ps(v50, v50, 85).m128_f32[0] + _mm_shuffle_ps(v50, v50, 0).m128_f32[0])
                       + _mm_shuffle_ps(v50, v50, 170).m128_f32[0]) < 0.0 )
            {
LABEL_31:
              m_data[(__int64)(v18 / 3) >> 5] |= 1 << ((v18 / 3) & 0x1F);
              m_data = array.m_storage.m_words.m_data;
            }
          }
          v18 += 3;
          v22 += 3i64;
        }
        while ( v18 < tris->m_size );
      }
      hkaiNavMeshGenerationUtils::_removeTriangles(
        &array,
        tris,
        triConnectivity,
        trisPerFaceInOut,
        perTriangleData,
        0i64);
      array.m_storage.m_words.m_size = 0;
      if ( array.m_storage.m_words.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_storage.m_words.m_data,
          4 * array.m_storage.m_words.m_capacityAndFlags);
      result->m_enum = HK_SUCCESS;
    }
    else
    {
      result->m_enum = HK_FAILURE;
      array.m_storage.m_words.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          0i64,
          4 * m_capacityAndFlags);
    }
  }
  else
  {
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 1328
// RVA: 0xB829C0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_createNavMesh(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn,
        hkArray<int,hkContainerHeapAllocator> *tris,
        hkArray<int,hkContainerHeapAllocator> *trisPerFace,
        hkArray<int,hkContainerHeapAllocator> *triConnectivity,
        hkArray<int,hkContainerHeapAllocator> *triangleMaterials,
        hkaiCarverTree *carverTree,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *navMeshOut)
{
  hkaiNavMeshGenerationUtils::_createNavMeshImpl(
    result,
    vertsIn,
    tris,
    trisPerFace,
    triConnectivity,
    triangleMaterials,
    0i64,
    0i64,
    carverTree,
    settings,
    navMeshOut);
  return result;
}

// File Line: 1333
// RVA: 0xB82A30
hkResult *__fastcall hkaiNavMeshGenerationUtils::_createNavMesh(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn,
        hkArray<int,hkContainerHeapAllocator> *tris,
        hkArray<int,hkContainerHeapAllocator> *trisPerFace,
        hkArray<int,hkContainerHeapAllocator> *triConnectivity,
        hkArray<int,hkContainerHeapAllocator> *originalFaceIndices,
        hkGeometry *triMeshIn,
        hkaiCarverTree *carverTree,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *navMeshOut)
{
  hkaiNavMeshGenerationUtils::_createNavMeshImpl(
    result,
    vertsIn,
    tris,
    trisPerFace,
    triConnectivity,
    0i64,
    originalFaceIndices,
    triMeshIn,
    carverTree,
    settings,
    navMeshOut);
  return result;
}

// File Line: 1338
// RVA: 0xB82AA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_createNavMeshImpl(
        hkResult *result,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *vertsIn,
        hkArray<int,hkContainerHeapAllocator> *tris,
        hkArray<int,hkContainerHeapAllocator> *trisPerFace,
        hkArray<int,hkContainerHeapAllocator> *triConnectivity,
        hkArray<int,hkContainerHeapAllocator> *allTriangleMaterials,
        hkArray<int,hkContainerHeapAllocator> *originalFaceIndices,
        hkGeometry *triMeshIn,
        hkaiCarverTree *carverTree,
        hkaiNavMeshGenerationSettings *settings,
        hkaiNavMesh *navMeshOut)
{
  int m_size; // edi
  hkArray<int,hkContainerHeapAllocator> *v12; // r13
  int v16; // esi
  int v17; // r8d
  int v18; // r14d
  __int64 v19; // r11
  int v20; // r9d
  int v21; // r10d
  int v22; // r8d
  int v23; // edi
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  unsigned int v27; // edx
  int v28; // edx
  SortedTriangle *v29; // rax
  int v30; // edi
  int v31; // r14d
  int v32; // ecx
  int v33; // r12d
  unsigned int *v34; // rax
  unsigned int *m_data; // r8
  int m_capacityAndFlags; // eax
  int v37; // edi
  int v38; // ecx
  int v39; // r9d
  hkResult *v40; // rdi
  __int64 v41; // rcx
  unsigned int *v42; // rdi
  int v43; // r9d
  __int64 v44; // rdi
  hkArray<int,hkContainerHeapAllocator> *v45; // r14
  int v46; // edi
  int v47; // r8d
  int *v48; // rdx
  int *v49; // rsi
  int *v50; // r15
  int v51; // r12d
  __int64 v52; // r14
  int v53; // edi
  int *v54; // rdx
  __int64 v55; // rax
  int v56; // ecx
  unsigned __int64 v57; // rcx
  hkaiNavMesh *v58; // rsi
  int *v59; // rdi
  hkResultEnum v60; // ecx
  SortedTriangle *v61; // r12
  int *v62; // rdx
  int *v63; // r14
  __m128 v64; // xmm0
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm1
  int v68; // edi
  __m128 v69; // xmm5
  __m128 v70; // xmm5
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  __m128 v73; // xmm3
  int v74; // r9d
  int v75; // edi
  int v76; // r9d
  int v77; // edi
  int v78; // r9d
  int v79; // edi
  int v80; // r9d
  int v81; // edi
  int v82; // r9d
  hkResultEnum m_enum; // eax
  int *v84; // rax
  __int64 v85; // r8
  int v86; // r15d
  __int64 v87; // rdi
  __m128 v88; // xmm0
  int v89; // r8d
  int PaintedMaterialForPoint; // eax
  hkResult *v91; // rax
  int v92; // r14d
  int *v93; // r15
  int *v94; // r12
  __int64 v95; // rdi
  hkaiNavMesh::Face *v96; // rax
  __int64 v97; // rcx
  __int64 p_m_numUserEdges; // r14
  __int64 v99; // r8
  __int64 v100; // r13
  int v101; // eax
  hkaiNavMesh::Edge *v102; // rdi
  __int64 v103; // r9
  __int64 v104; // r8
  __int64 v105; // r10
  __int64 v106; // r11
  __int64 v107; // rdx
  __int64 v108; // r14
  __int64 m_edgeDataStriding; // rax
  int v110; // eax
  __int64 v111; // rcx
  int v112; // edx
  __int64 v113; // rcx
  int v114; // r11d
  __int64 v115; // r8
  hkaiNavMesh::Face *v116; // r10
  __int64 m_startEdgeIndex; // rdx
  __int64 v118; // rdi
  hkaiNavMesh::Edge *v119; // r9
  __int64 m_oppositeEdge; // rax
  hkArrayBase<int> *perTriangleDataInOut2; // [rsp+28h] [rbp-D8h]
  int *numIndicesPerPiece; // [rsp+70h] [rbp-90h] BYREF
  int v123; // [rsp+78h] [rbp-88h]
  int v124; // [rsp+7Ch] [rbp-84h]
  int *oppConvexEdges; // [rsp+80h] [rbp-80h] BYREF
  int v126; // [rsp+88h] [rbp-78h]
  int v127; // [rsp+8Ch] [rbp-74h]
  int *convexMaterials; // [rsp+90h] [rbp-70h] BYREF
  int v129; // [rsp+98h] [rbp-68h]
  int v130; // [rsp+9Ch] [rbp-64h]
  int *convexIndices; // [rsp+A0h] [rbp-60h] BYREF
  int v132; // [rsp+A8h] [rbp-58h]
  int v133; // [rsp+ACh] [rbp-54h]
  int *materials; // [rsp+B0h] [rbp-50h] BYREF
  int v135; // [rsp+B8h] [rbp-48h]
  int v136; // [rsp+BCh] [rbp-44h]
  int *oppositeEdgesOut; // [rsp+C0h] [rbp-40h] BYREF
  int v138; // [rsp+C8h] [rbp-38h]
  int v139; // [rsp+CCh] [rbp-34h]
  int v140; // [rsp+D0h] [rbp-30h] BYREF
  hkResult resulta; // [rsp+D4h] [rbp-2Ch] BYREF
  SortedTriangle *array; // [rsp+D8h] [rbp-28h] BYREF
  int v143; // [rsp+E0h] [rbp-20h]
  int v144; // [rsp+E4h] [rbp-1Ch]
  hkResult v145; // [rsp+E8h] [rbp-18h] BYREF
  hkResult v146; // [rsp+ECh] [rbp-14h] BYREF
  int *triangleIndices; // [rsp+F0h] [rbp-10h]
  hkResult v148; // [rsp+F8h] [rbp-8h] BYREF
  hkBitField trisToRemove; // [rsp+100h] [rbp+0h] BYREF
  hkResult v150; // [rsp+120h] [rbp+20h] BYREF
  int n; // [rsp+124h] [rbp+24h] BYREF
  int v152; // [rsp+128h] [rbp+28h]
  hkResult v153; // [rsp+12Ch] [rbp+2Ch] BYREF
  hkResult resultOut; // [rsp+130h] [rbp+30h] BYREF
  __int64 v155; // [rsp+138h] [rbp+38h]
  int *oppEdges; // [rsp+140h] [rbp+40h]
  int estimatedMaxNumEdges; // [rsp+148h] [rbp+48h]
  int estimatedMaxNumFaces; // [rsp+14Ch] [rbp+4Ch]
  int v159; // [rsp+150h] [rbp+50h]
  __int64 v160; // [rsp+158h] [rbp+58h]
  __int64 v161; // [rsp+160h] [rbp+60h]
  hkResult v162; // [rsp+168h] [rbp+68h] BYREF
  hkResult v163; // [rsp+16Ch] [rbp+6Ch] BYREF
  hkVector4f v164; // [rsp+170h] [rbp+70h] BYREF
  hkArray<int,hkContainerHeapAllocator> *v167; // [rsp+1F0h] [rbp+F0h] BYREF
  hkArray<int,hkContainerHeapAllocator> *v168; // [rsp+1F8h] [rbp+F8h]

  v168 = trisPerFace;
  v167 = tris;
  m_size = tris->m_size;
  v12 = trisPerFace;
  if ( !m_size )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  array = 0i64;
  v143 = 0;
  v144 = 0x80000000;
  v16 = m_size / 3;
  if ( m_size / 3 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size / 3, 16);
    if ( resulta.m_enum )
    {
      v17 = v144;
      result->m_enum = HK_FAILURE;
      v143 = 0;
      if ( v17 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v17);
      return result;
    }
  }
  v143 = m_size / 3;
  v18 = 0;
  if ( tris->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v19 += 3i64;
      v20 = tris->m_data[v19 - 1];
      v21 = tris->m_data[v19 - 3];
      v22 = tris->m_data[v19 - 2];
      v23 = v20;
      v24 = v20;
      v25 = v22;
      if ( v21 < v22 )
        v25 = tris->m_data[v19 - 3];
      if ( v25 < v20 )
        v23 = v25;
      v26 = tris->m_data[v19 - 2];
      if ( v21 > v22 )
        v26 = tris->m_data[v19 - 3];
      if ( v26 > v20 )
        v24 = v26;
      v27 = (unsigned __int64)(1431655766i64 * v18) >> 32;
      v18 += 3;
      v28 = (v27 >> 31) + v27;
      v29 = &array[v28];
      v29->i[0] = v23;
      v29->i[1] = v21 + v22 + v20 - v24 - v23;
      v29->i[2] = v24;
      v29->index = v28;
    }
    while ( v18 < tris->m_size );
    v16 = v143;
  }
  if ( v16 > 1 )
  {
    hkAlgorithm::quickSortRecursive<SortedTriangle,hkAlgorithm::less<SortedTriangle>>(array, 0, v16 - 1, 0);
    v16 = v143;
  }
  v30 = v16 + 31;
  v31 = v16;
  trisToRemove.m_storage.m_words.m_data = 0i64;
  trisToRemove.m_storage.m_words.m_size = 0;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v32 = (v16 + 31) >> 5;
  v33 = v32;
  if ( v32 )
  {
    v140 = 4 * v32;
    v34 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v140);
    v16 = v143;
    m_data = v34;
    v32 = v140 / 4;
  }
  else
  {
    m_data = 0i64;
  }
  m_capacityAndFlags = 0x80000000;
  trisToRemove.m_storage.m_words.m_data = m_data;
  if ( v32 )
    m_capacityAndFlags = v32;
  v37 = v30 >> 5;
  trisToRemove.m_storage.m_words.m_size = v33;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = m_capacityAndFlags;
  trisToRemove.m_storage.m_numBits = v31;
  v38 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < v37 )
  {
    v39 = v37;
    if ( v37 < 2 * v38 )
      v39 = 2 * v38;
    hkArrayUtil::_reserve(&v145, &hkContainerHeapAllocator::s_alloc, &trisToRemove, v39, 4);
    v16 = v143;
    m_capacityAndFlags = trisToRemove.m_storage.m_words.m_capacityAndFlags;
    m_data = trisToRemove.m_storage.m_words.m_data;
  }
  trisToRemove.m_storage.m_words.m_size = v37;
  if ( !m_data )
  {
    v40 = result;
    trisToRemove.m_storage.m_words.m_size = 0;
    result->m_enum = HK_FAILURE;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * m_capacityAndFlags);
    trisToRemove.m_storage.m_words.m_data = 0i64;
    trisToRemove.m_storage.m_words.m_capacityAndFlags = 0x80000000;
    v143 = 0;
    if ( v144 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v144);
    return v40;
  }
  if ( v37 - 1 >= 0 )
  {
    v41 = (unsigned int)v37;
    v42 = m_data;
    while ( v41 )
    {
      *v42++ = 0;
      --v41;
    }
    v16 = v143;
    m_data = trisToRemove.m_storage.m_words.m_data;
  }
  v43 = 0;
  if ( v16 - 1 > 0 )
  {
    v44 = 0i64;
    do
    {
      if ( array[v44].i[0] == array[v44 + 1].i[0]
        && array[v44].i[1] == array[v44 + 1].i[1]
        && array[v44].i[2] == array[v44 + 1].i[2] )
      {
        m_data[(__int64)array[v44].index >> 5] |= 1 << (array[v44].index & 0x1F);
        v16 = v143;
        m_data = trisToRemove.m_storage.m_words.m_data;
      }
      ++v43;
      ++v44;
    }
    while ( v43 < v16 - 1 );
  }
  v45 = triConnectivity;
  hkaiNavMeshGenerationUtils::_removeTriangles(&trisToRemove, tris, triConnectivity, v12, allTriangleMaterials, 0i64);
  trisToRemove.m_storage.m_words.m_size = 0;
  if ( trisToRemove.m_storage.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      trisToRemove.m_storage.m_words.m_data,
      4 * trisToRemove.m_storage.m_words.m_capacityAndFlags);
  trisToRemove.m_storage.m_words.m_data = 0i64;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v143 = 0;
  if ( v144 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v144);
  v46 = tris->m_size;
  oppositeEdgesOut = 0i64;
  v138 = 0;
  v139 = 0x80000000;
  estimatedMaxNumEdges = v46;
  estimatedMaxNumFaces = v46 / 3;
  if ( v46 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &oppositeEdgesOut, v46, 4);
    if ( resulta.m_enum )
    {
      v40 = result;
      v47 = v139;
      v138 = 0;
      result->m_enum = HK_FAILURE;
      if ( v47 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, oppositeEdgesOut, 4 * v47);
      return v40;
    }
  }
  v48 = tris->m_data;
  v49 = oppositeEdgesOut;
  v50 = v45->m_data;
  triangleIndices = v48;
  v138 = v46;
  v51 = 0;
  if ( v12->m_size > 0 )
  {
    v52 = 0i64;
    do
    {
      hkaiNavMeshGenerationUtils::_findSharedEdges(&v145, v48, 3 * v12->m_data[v52], v49);
      v53 = 0;
      if ( 3 * v12->m_data[v52] > 0 )
      {
        v54 = v49;
        do
        {
          if ( *(int *)((char *)v54 + (char *)v50 - (char *)v49) == 1 )
          {
            v55 = *v54;
            *v54 = -1;
            if ( (_DWORD)v55 != -1 )
              v49[v55] = -1;
          }
          ++v53;
          ++v54;
        }
        while ( v53 < 3 * v12->m_data[v52] );
      }
      ++v51;
      v56 = v12->m_data[v52++];
      v57 = 12i64 * v56;
      v48 = &triangleIndices[v57 / 4];
      v49 = (int *)((char *)v49 + v57);
      v50 = (int *)((char *)v50 + v57);
      triangleIndices = (int *)((char *)triangleIndices + v57);
    }
    while ( v51 < v12->m_size );
  }
  v58 = navMeshOut;
  oppEdges = oppositeEdgesOut;
  v140 = 0;
  v59 = v167->m_data;
  convexIndices = 0i64;
  v132 = 0;
  v133 = 0x80000000;
  materials = 0i64;
  v135 = 0;
  triangleIndices = v59;
  v136 = 0x80000000;
  convexMaterials = 0i64;
  v129 = 0;
  v130 = 0x80000000;
  oppConvexEdges = 0i64;
  v126 = 0;
  v127 = 0x80000000;
  numIndicesPerPiece = 0i64;
  v123 = 0;
  v124 = 0x80000000;
  v60 = HK_SUCCESS;
  resulta.m_enum = HK_SUCCESS;
  if ( v12->m_size <= 0 )
  {
LABEL_137:
    v114 = 0;
    if ( v58->m_faces.m_size > 0 )
    {
      v115 = 0i64;
      do
      {
        v116 = v58->m_faces.m_data;
        m_startEdgeIndex = v116[v115].m_startEdgeIndex;
        if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v116[v115].m_numEdges )
        {
          v118 = m_startEdgeIndex;
          do
          {
            v119 = v58->m_edges.m_data;
            m_oppositeEdge = (int)v119[v118].m_oppositeEdge;
            if ( (_DWORD)m_oppositeEdge != -1 )
              v119[m_oppositeEdge].m_oppositeFace = v114;
            LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
            ++v118;
          }
          while ( (int)m_startEdgeIndex < v116[v115].m_startEdgeIndex + v116[v115].m_numEdges );
        }
        ++v114;
        ++v115;
      }
      while ( v114 < v58->m_faces.m_size );
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v58->m_vertices,
      vertsIn);
    v40 = result;
    result->m_enum = HK_SUCCESS;
    goto LABEL_146;
  }
  v61 = 0i64;
  array = 0i64;
  while ( 1 )
  {
    v62 = v12->m_data;
    if ( !*(int *)((char *)v61->i + (unsigned __int64)v12->m_data) )
      goto LABEL_136;
    v63 = v59 + 2;
    v64 = (__m128)vertsIn->m_data[*v59];
    v65 = _mm_sub_ps((__m128)vertsIn->m_data[v59[1]], v64);
    v66 = (__m128)vertsIn->m_data[v59[2]];
    v132 = 0;
    v135 = 0;
    v129 = 0;
    v126 = 0;
    v123 = 0;
    v67 = _mm_sub_ps(v66, v64);
    v68 = 3 * *(int *)((char *)v62 + (_QWORD)v61);
    v69 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v65), _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v67));
    v70 = _mm_shuffle_ps(v69, v69, 201);
    v71 = _mm_mul_ps(v70, v70);
    v72 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
            _mm_shuffle_ps(v71, v71, 170));
    v73 = _mm_rsqrt_ps(v72);
    v164.m_quad = _mm_mul_ps(
                    v70,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v72, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v73, v72), v73)),
                        _mm_mul_ps(*(__m128 *)_xmm, v73))));
    if ( (v133 & 0x3FFFFFFF) >= v68 )
    {
      LODWORD(v167) = 0;
LABEL_74:
      v132 = v68;
      goto LABEL_75;
    }
    v74 = v68;
    if ( v68 < 2 * (v133 & 0x3FFFFFFF) )
      v74 = 2 * (v133 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&v167, &hkContainerHeapAllocator::s_alloc, &convexIndices, v74, 4);
    if ( !(_DWORD)v167 )
      goto LABEL_74;
LABEL_75:
    v75 = *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( (v136 & 0x3FFFFFFF) >= v75 )
    {
      v150.m_enum = HK_SUCCESS;
LABEL_81:
      v135 = v75;
      goto LABEL_82;
    }
    v76 = *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( v75 < 2 * (v136 & 0x3FFFFFFF) )
      v76 = 2 * (v136 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, &materials, v76, 4);
    if ( v150.m_enum == HK_SUCCESS )
      goto LABEL_81;
LABEL_82:
    v77 = *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( (v130 & 0x3FFFFFFF) >= v77 )
    {
      v148.m_enum = HK_SUCCESS;
LABEL_88:
      v129 = v77;
      goto LABEL_89;
    }
    v78 = *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( v77 < 2 * (v130 & 0x3FFFFFFF) )
      v78 = 2 * (v130 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v148, &hkContainerHeapAllocator::s_alloc, &convexMaterials, v78, 4);
    if ( v148.m_enum == HK_SUCCESS )
      goto LABEL_88;
LABEL_89:
    v79 = 3 * *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( (v127 & 0x3FFFFFFF) >= v79 )
    {
      v146.m_enum = HK_SUCCESS;
LABEL_95:
      v126 = v79;
      goto LABEL_96;
    }
    v80 = 3 * *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( v79 < 2 * (v127 & 0x3FFFFFFF) )
      v80 = 2 * (v127 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v146, &hkContainerHeapAllocator::s_alloc, &oppConvexEdges, v80, 4);
    if ( v146.m_enum == HK_SUCCESS )
      goto LABEL_95;
LABEL_96:
    v81 = *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( (v124 & 0x3FFFFFFF) >= v81 )
    {
      m_enum = HK_SUCCESS;
      v153.m_enum = HK_SUCCESS;
LABEL_102:
      v123 = v81;
      goto LABEL_103;
    }
    v82 = *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
    if ( v81 < 2 * (v124 & 0x3FFFFFFF) )
      v82 = 2 * (v124 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v153, &hkContainerHeapAllocator::s_alloc, &numIndicesPerPiece, v82, 4);
    m_enum = v153.m_enum;
    if ( v153.m_enum == HK_SUCCESS )
      goto LABEL_102;
LABEL_103:
    if ( (_DWORD)v167 || v150.m_enum || v148.m_enum || v146.m_enum || m_enum )
      goto LABEL_159;
    v84 = v12->m_data;
    v85 = v140;
    v86 = 0;
    v155 = v140;
    if ( *(int *)((char *)v84 + (_QWORD)v61) > 0 )
      break;
LABEL_115:
    if ( settings->m_convexThreshold >= 0.0 )
    {
      LODWORD(perTriangleDataInOut2) = 3 * *(int *)((char *)v61->i + (unsigned __int64)v12->m_data);
      v91 = hkaiNavMeshGenerationUtils::_hertelMehlhorn(
              &v162,
              (hkVector4f *)vertsIn->m_data,
              triangleIndices,
              materials,
              oppEdges,
              (const __m128i *)perTriangleDataInOut2,
              settings,
              convexIndices,
              convexMaterials,
              oppConvexEdges,
              numIndicesPerPiece,
              &n,
              &v164);
    }
    else
    {
      v91 = hkaiNavMeshGenerationUtils::_nullHertelMehlhorn(
              &v163,
              (hkVector4f *)vertsIn->m_data,
              (char *)triangleIndices,
              (char *)materials,
              (char *)oppEdges,
              3 * *(int *)((char *)v61->i + (unsigned __int64)v12->m_data),
              convexIndices,
              convexMaterials,
              oppConvexEdges,
              numIndicesPerPiece,
              &n);
    }
    if ( v91->m_enum )
      goto LABEL_159;
    v92 = n;
    v93 = convexIndices;
    v94 = oppConvexEdges;
    v95 = v58->m_faces.m_size;
    v145.m_enum = v58->m_edges.m_size;
    v96 = hkaiNavMesh::expandFacesBy(v58, n, estimatedMaxNumFaces);
    if ( !v96 )
      goto LABEL_159;
    v97 = v95;
    v152 = 0;
    v160 = v95;
    if ( v92 > 0 )
    {
      p_m_numUserEdges = (__int64)&v96->m_numUserEdges;
      v99 = 0i64;
      v155 = 0i64;
      v161 = (__int64)&v96->m_numUserEdges;
      while ( 1 )
      {
        v100 = *(unsigned int *)((char *)numIndicesPerPiece + v99);
        *(_DWORD *)(p_m_numUserEdges - 2) = 0;
        *(_DWORD *)(p_m_numUserEdges - 10) = -1;
        *(_DWORD *)(p_m_numUserEdges - 6) = -1;
        *(_WORD *)(p_m_numUserEdges + 2) = -1;
        *(_WORD *)(p_m_numUserEdges + 4) = -12851;
        v101 = v58->m_edges.m_size;
        *(_WORD *)(p_m_numUserEdges - 2) = v100;
        *(_DWORD *)(p_m_numUserEdges - 10) = v101;
        if ( v58->m_faceDataStriding )
          v58->m_faceData.m_data[v97 * v58->m_faceDataStriding] = *(int *)((char *)convexMaterials + v99);
        v159 = v58->m_edges.m_size;
        v102 = hkaiNavMesh::expandEdgesBy(v58, v100, estimatedMaxNumEdges);
        if ( !v102 )
          goto LABEL_159;
        v103 = 0i64;
        v104 = (int)v100 - 1;
        if ( (int)v100 > 0 )
        {
          v105 = 0i64;
          v106 = v100;
          v107 = 20i64 * ((int)v100 - 1);
          v108 = v159;
          do
          {
            *(int *)((char *)&v102->m_a + v107) = v93[v104];
            *(int *)((char *)&v102->m_b + v107) = v93[v103];
            *(_QWORD *)((char *)&v102->m_oppositeEdge + v107) = -1i64;
            *(_DWORD *)(&v102->m_flags.m_storage + v107) = 4;
            m_edgeDataStriding = v58->m_edgeDataStriding;
            if ( (_DWORD)m_edgeDataStriding )
              v58->m_edgeData.m_data[m_edgeDataStriding * (v104 + v108)] = 0;
            v110 = v94[v104];
            if ( v110 != -1 )
              *(unsigned int *)((char *)&v102->m_oppositeEdge + v107) = v145.m_enum + v110;
            v104 = v103;
            v107 = v105;
            ++v103;
            v105 += 20i64;
            --v106;
          }
          while ( v106 );
          p_m_numUserEdges = v161;
        }
        p_m_numUserEdges += 16i64;
        v111 = 4i64 * *(int *)((char *)numIndicesPerPiece + v155);
        v99 = v155 + 4;
        ++v152;
        v93 = (int *)((char *)v93 + v111);
        v94 = (int *)((char *)v94 + v111);
        v97 = v160 + 1;
        v161 = p_m_numUserEdges;
        v155 += 4i64;
        ++v160;
        if ( v152 >= n )
        {
          v12 = v168;
          break;
        }
      }
    }
    v61 = array;
    v112 = *(int *)((char *)array->i + (unsigned __int64)v12->m_data);
    v113 = 3i64 * v112;
    oppEdges = (int *)((char *)oppEdges + v113 * 4);
    v59 = &triangleIndices[v113];
    v140 += v112;
    v60 = resulta.m_enum;
    triangleIndices = v59;
LABEL_136:
    ++v60;
    v61 = (SortedTriangle *)((char *)v61 + 4);
    resulta.m_enum = v60;
    array = v61;
    if ( v60 >= v12->m_size )
      goto LABEL_137;
  }
  v87 = 0i64;
  while ( 1 )
  {
    v88 = _mm_add_ps(
            _mm_add_ps((__m128)vertsIn->m_data[*(v63 - 2)], (__m128)vertsIn->m_data[*(v63 - 1)]),
            (__m128)vertsIn->m_data[*v63]);
    resultOut.m_enum = HK_SUCCESS;
    trisToRemove.m_storage.m_words = (hkArray<unsigned int,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                                       v88,
                                                                                       (__m128)xmmword_141A711C0);
    v89 = allTriangleMaterials
        ? allTriangleMaterials->m_data[v85 + v87]
        : triMeshIn->m_triangles.m_data[*(int *)((char *)originalFaceIndices->m_data + (unsigned __int64)v61 + 4) - 1].m_material;
    PaintedMaterialForPoint = hkaiCarverTree::getPaintedMaterialForPoint(
                                carverTree,
                                (hkVector4f *)&trisToRemove,
                                v89,
                                settings->m_painterOverlapCallback,
                                &resultOut);
    if ( resultOut.m_enum )
      break;
    v85 = v155;
    ++v86;
    materials[v87] = PaintedMaterialForPoint;
    v63 += 3;
    ++v87;
    if ( v86 >= *(int *)((char *)v61->i + (unsigned __int64)v12->m_data) )
      goto LABEL_115;
  }
LABEL_159:
  v40 = result;
  result->m_enum = HK_FAILURE;
LABEL_146:
  v123 = 0;
  if ( v124 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, numIndicesPerPiece, 4 * v124);
  v126 = 0;
  v124 = 0x80000000;
  numIndicesPerPiece = 0i64;
  if ( v127 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, oppConvexEdges, 4 * v127);
  v129 = 0;
  v127 = 0x80000000;
  oppConvexEdges = 0i64;
  if ( v130 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, convexMaterials, 4 * v130);
  v135 = 0;
  v130 = 0x80000000;
  convexMaterials = 0i64;
  if ( v136 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, materials, 4 * v136);
  v132 = 0;
  v136 = 0x80000000;
  materials = 0i64;
  if ( v133 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, convexIndices, 4 * v133);
  v138 = 0;
  v133 = 0x80000000;
  convexIndices = 0i64;
  if ( v139 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, oppositeEdgesOut, 4 * v139);
  return v40;
}r::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, oppositeEdgesOut, 4 * v139);
  return v40;
}

// File Line: 1698
// RVA: 0xB827A0
void __fastcall hkaiNavMeshGenerationUtils::_removeTriangles(
        hkBitField *trisToRemove,
        hkArray<int,hkContainerHeapAllocator> *trisInOut,
        hkArray<int,hkContainerHeapAllocator> *triConnectivityInOut,
        hkArray<int,hkContainerHeapAllocator> *trisPerFaceInOut,
        hkArrayBase<int> *perTriangleDataInOut,
        hkArrayBase<int> *perTriangleDataInOut2)
{
  hkArrayBase<int> *v6; // r11
  int *m_data; // r10
  int *v8; // r13
  hkArray<int,hkContainerHeapAllocator> *v9; // rax
  hkArray<int,hkContainerHeapAllocator> *v10; // rsi
  int *v12; // r15
  hkArrayBase<int> *v13; // r8
  int *v14; // rbx
  int v15; // edi
  int v16; // ebp
  __int64 v17; // r9
  __int64 v18; // r14
  int *v19; // rax
  bool v20; // zf
  int *v21; // rax
  int v22; // esi
  int v23; // edx
  __int64 v24; // r10
  hkBitField *v25; // [rsp+50h] [rbp+8h]
  int v26; // [rsp+58h] [rbp+10h]

  v25 = trisToRemove;
  v6 = perTriangleDataInOut;
  m_data = trisInOut->m_data;
  v8 = triConnectivityInOut->m_data;
  v9 = trisPerFaceInOut;
  v10 = triConnectivityInOut;
  if ( perTriangleDataInOut )
    v12 = perTriangleDataInOut->m_data;
  else
    v12 = 0i64;
  v13 = perTriangleDataInOut2;
  if ( perTriangleDataInOut2 )
    v14 = perTriangleDataInOut2->m_data;
  else
    v14 = 0i64;
  v15 = 0;
  v16 = 0;
  v17 = 0i64;
  v26 = 0;
  if ( trisInOut->m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      v19 = v9->m_data;
      v20 = v19[v17] == 0;
      v21 = &v19[v17];
      if ( v20 )
      {
        do
        {
          ++v21;
          ++v17;
        }
        while ( !*v21 );
      }
      v22 = v16 / 3;
      if ( ((trisToRemove->m_storage.m_words.m_data[(__int64)(v16 / 3) >> 5] >> ((v16 / 3) & 0x1F)) & 1) == 0 )
      {
        *m_data = trisInOut->m_data[v18];
        m_data[1] = trisInOut->m_data[v18 + 1];
        m_data[2] = trisInOut->m_data[v18 + 2];
        *v8 = triConnectivityInOut->m_data[v18];
        v8[1] = triConnectivityInOut->m_data[v18 + 1];
        v8[2] = triConnectivityInOut->m_data[v18 + 2];
        if ( v12 )
          *v12++ = perTriangleDataInOut->m_data[v22];
        if ( v14 )
          *v14++ = perTriangleDataInOut2->m_data[v22];
        m_data += 3;
        v8 += 3;
        ++v15;
      }
      v23 = trisPerFaceInOut->m_data[v17] + v26;
      if ( v22 >= v23 - 1 )
      {
        trisPerFaceInOut->m_data[v17] = v15;
        v15 = 0;
        v26 = v23;
        ++v17;
      }
      v9 = trisPerFaceInOut;
      trisToRemove = v25;
      v16 += 3;
      v18 += 3i64;
    }
    while ( v16 < trisInOut->m_size );
    v13 = perTriangleDataInOut2;
    v6 = perTriangleDataInOut;
    v10 = triConnectivityInOut;
  }
  v24 = m_data - trisInOut->m_data;
  trisInOut->m_size = v24;
  v10->m_size = v24;
  if ( v6 )
    v6->m_size = (int)v24 / 3;
  if ( v13 )
    v13->m_size = (int)v24 / 3;
}

