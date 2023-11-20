// File Line: 28
// RVA: 0xB83880
hkSimdFloat32 *__fastcall getNormalComponentInUp(hkSimdFloat32 *result, hkVector4f *v0, hkVector4f *v1, hkVector4f *v2, hkVector4f *up)
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
hkResult *__fastcall triangulatorAddEdges(hkResult *result, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkVector4f *points, const int numPoints, CleanEdgesOutput *edgesOutput)
{
  hkResult *v5; // r13
  __int64 v6; // r15
  signed int v7; // edi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *v8; // rbx
  int v9; // er14
  char *v10; // rsi
  int v11; // er9
  signed __int64 v12; // r12
  hkResultEnum v13; // eax
  hkResult *v14; // rax
  __int64 v15; // rax
  int v16; // edi
  signed __int64 v17; // rcx
  CleanEdgesOutput::CleanEdge *v18; // rax
  __int64 v19; // rcx
  int v20; // eax
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128i v27; // xmm1
  int v28; // esi
  int v29; // ecx
  __int64 v30; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v31; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v32; // r14
  __int64 v33; // r15
  int v34; // ecx
  __int64 v35; // rdx
  __int64 v36; // rax
  signed __int64 v37; // rdi
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
  __int64 v56; // rdx
  __int64 v57; // rax
  signed __int64 v58; // rdi
  int v59; // ecx
  char *v60; // rdx
  __int64 v61; // rcx
  __int64 v62; // r14
  __int64 v63; // r13
  __int64 v64; // r15
  __int64 v65; // rdi
  hkResult *v66; // rbx
  int v67; // er8
  int v68; // er8
  char *v69; // [rsp+50h] [rbp-B0h]
  int v70; // [rsp+58h] [rbp-A8h]
  int v71; // [rsp+5Ch] [rbp-A4h]
  char *array; // [rsp+60h] [rbp-A0h]
  int v73; // [rsp+68h] [rbp-98h]
  int v74; // [rsp+6Ch] [rbp-94h]
  hkResult v75; // [rsp+70h] [rbp-90h]
  hkResult resulta; // [rsp+74h] [rbp-8Ch]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Location location; // [rsp+78h] [rbp-88h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v78; // [rsp+90h] [rbp-70h]
  __int64 v79; // [rsp+A8h] [rbp-58h]
  __int64 v80; // [rsp+B0h] [rbp-50h]
  __int64 v81; // [rsp+B8h] [rbp-48h]
  hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> > icrossing; // [rsp+C0h] [rbp-40h]
  __int64 v83; // [rsp+F0h] [rbp-10h]
  hkResult *v84; // [rsp+150h] [rbp+50h]
  hkVector4f *v85; // [rsp+160h] [rbp+60h]

  v85 = points;
  v84 = result;
  v5 = result;
  v6 = edgesOutput->m_edges.m_size;
  v7 = 2147483648;
  v8 = triangulator;
  v9 = 2 * v6;
  array = 0i64;
  v73 = 0;
  v74 = 2147483648;
  v10 = 0i64;
  v69 = 0i64;
  v70 = 0;
  v71 = 2147483648;
  if ( 2 * (signed int)v6 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v11 = 2 * v6;
    if ( v9 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 32);
    v7 = v71;
    v10 = v69;
  }
  v12 = 8i64;
  if ( (v7 & 0x3FFFFFFF) >= v9 )
  {
    v13 = 0;
    v75.m_enum = 0;
  }
  else
  {
    if ( v9 < 2 * (v7 & 0x3FFFFFFF) )
      v9 = 2 * (v7 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v75, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v69, v9, 8);
    v7 = v71;
    v10 = v69;
    v13 = v75.m_enum;
  }
  if ( resulta.m_enum || v13 )
  {
    v70 = 0;
    v5->m_enum = 1;
    if ( v7 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v10,
        8 * v7);
    v69 = 0i64;
    v71 = 2147483648;
    v73 = 0;
    if ( v74 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        32 * v74);
    v14 = v5;
  }
  else
  {
    hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>::hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>(&icrossing);
    v15 = 0i64;
    v81 = v6;
    v80 = 0i64;
    if ( (signed int)v6 <= 0 )
    {
LABEL_62:
      v62 = 0i64;
      v63 = v73 / 2;
      if ( v73 / 2 <= 0 )
      {
LABEL_68:
        v66 = v84;
        v70 = 0;
        v84->m_enum = 0;
        if ( v7 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v10,
            8 * v7);
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
            v8);
          LODWORD(edgesOutput) = 0;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertCrossingEdge<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>>>(
            v8,
            (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *)&location,
            *(_DWORD *)&array[v65 + 16],
            *(_DWORD *)&array[v65 + 20],
            *(_DWORD *)&array[v65 + 48],
            *(_DWORD *)&array[v65 + 52],
            1,
            &icrossing,
            (hkaiNavMeshGenTriangulatorEdgeData *)&edgesOutput);
          if ( location.m_type.m_storage == 10 || v8->m_status.m_storage )
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
        v66 = v84;
        v68 = v71;
        v70 = 0;
        v84->m_enum = 1;
        if ( v68 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v69,
            8 * v68);
        v69 = 0i64;
        v73 = 0;
      }
      v71 = 2147483648;
      if ( v74 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          32 * v74);
      v14 = v66;
    }
    else
    {
      while ( 1 )
      {
        v16 = v8->m_margin;
        v17 = v15;
        v18 = edgesOutput->m_edges.m_data;
        v79 = v17 * 8;
        v19 = v18[v17].m_a;
        v20 = 0x7FFFFF - v16;
        v21 = v85[v19].m_quad;
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v8->m_worldToLocal.m_col0.m_quad),
                    v8->m_worldToLocal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v8->m_worldToLocal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v8->m_worldToLocal.m_col2.m_quad));
        v23 = _mm_sub_ps(v22, (__m128)xmmword_141A711B0);
        v24 = _mm_add_ps(v22, (__m128)xmmword_141A711B0);
        v25 = _mm_cmpltps(v22, (__m128)0i64);
        v26 = _mm_or_ps(_mm_andnot_ps(v25, v24), _mm_and_ps(v23, v25));
        v27 = _mm_xor_si128(
                (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v26),
                _mm_cvttps_epi32(v26));
        v28 = _mm_cvtsi128_si32(v27);
        if ( v28 >= v16 )
        {
          if ( v28 > v20 )
            v28 = 0x7FFFFF - v16;
        }
        else
        {
          v28 = v16;
        }
        v29 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v27, 85));
        if ( v29 >= v16 )
        {
          v16 = v29;
          if ( v29 > v20 )
            v16 = v20;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
          v8,
          &location,
          v28,
          v16);
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
          v8,
          &v78,
          v28,
          v16,
          1,
          &location,
          0);
        LODWORD(v30) = v78.m_type.m_storage;
        if ( v78.m_type.m_storage == 2 )
        {
          location.m_edge.m_triangle = v78.m_edge.m_triangle;
          *(_QWORD *)&location.m_edge.m_index = *(_QWORD *)&v78.m_edge.m_index;
          location.m_type.m_storage = 1;
          v31 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
                  v8,
                  &v78,
                  v28,
                  v16,
                  1,
                  &location,
                  1);
          v30 = *(_QWORD *)&v31->m_type.m_storage;
          v32 = v31->m_edge.m_triangle;
          v33 = *(_QWORD *)&v31->m_edge.m_index;
        }
        else
        {
          LODWORD(v33) = v78.m_edge.m_index;
          v32 = v78.m_edge.m_triangle;
        }
        if ( (_DWORD)v30 == 10 || v8->m_status.m_storage )
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
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 32);
            v34 = v73;
          }
          v35 = (__int64)&array[32 * v34];
          if ( v35 )
          {
            v36 = v83;
            *(_DWORD *)(v35 + 16) = v28;
            *(_DWORD *)(v35 + 20) = v16;
            *(_QWORD *)(v35 + 24) = v36;
            v34 = v73;
          }
          v37 = (signed __int64)v32 + 8 * (signed int)v33;
          v73 = v34 + 1;
          v38 = v70;
          if ( v70 == (v71 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v69, 8);
            v38 = v70;
          }
          v39 = v79;
          *(_QWORD *)&v69[8 * v38] = *(_QWORD *)(v37 + 16);
          ++v70;
          *(_QWORD *)(*(_QWORD *)(v37 + 16) + 24i64) = *(_DWORD *)(*(_QWORD *)(v37 + 16) + 24i64) & 3 | (unsigned __int64)(4i64 * *(int *)((char *)&edgesOutput->m_edges.m_data->m_a + v39));
        }
        v40 = v8->m_margin;
        v41 = 0x7FFFFF - v40;
        v42 = v85[*(int *)((char *)&edgesOutput->m_edges.m_data->m_b + v39)].m_quad;
        v43 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v8->m_worldToLocal.m_col0.m_quad),
                    v8->m_worldToLocal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v8->m_worldToLocal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v8->m_worldToLocal.m_col2.m_quad));
        v44 = _mm_sub_ps(v43, (__m128)xmmword_141A711B0);
        v45 = _mm_add_ps(v43, (__m128)xmmword_141A711B0);
        v46 = _mm_cmpltps(v43, (__m128)0i64);
        v47 = _mm_or_ps(_mm_andnot_ps(v46, v45), _mm_and_ps(v44, v46));
        v48 = _mm_xor_si128(
                (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v47),
                _mm_cvttps_epi32(v47));
        v49 = _mm_cvtsi128_si32(v48);
        if ( v49 >= v40 )
        {
          if ( v49 > v41 )
            v49 = 0x7FFFFF - v40;
        }
        else
        {
          v49 = v8->m_margin;
        }
        v50 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v48, 85));
        if ( v50 >= v40 )
        {
          v40 = v50;
          if ( v50 > v41 )
            v40 = v41;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
          v8,
          &location,
          v49,
          v40);
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
          v8,
          &v78,
          v49,
          v40,
          1,
          &location,
          0);
        LODWORD(v51) = v78.m_type.m_storage;
        if ( v78.m_type.m_storage == 2 )
        {
          location.m_edge.m_triangle = v78.m_edge.m_triangle;
          *(_QWORD *)&location.m_edge.m_index = *(_QWORD *)&v78.m_edge.m_index;
          location.m_type.m_storage = 1;
          v52 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
                  v8,
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
        if ( (_DWORD)v51 == 10 || v8->m_status.m_storage )
          break;
        if ( (unsigned int)v51 <= 1 )
        {
          v55 = v73;
          if ( v73 == (v74 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 32);
            v55 = v73;
          }
          v56 = (__int64)&array[32 * v55];
          if ( v56 )
          {
            v57 = v83;
            *(_DWORD *)(v56 + 16) = v49;
            *(_DWORD *)(v56 + 20) = v40;
            *(_QWORD *)(v56 + 24) = v57;
            v55 = v73;
          }
          v58 = (signed __int64)v53 + 8 * (signed int)v54;
          v73 = v55 + 1;
          v59 = v70;
          if ( v70 == (v71 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v69, 8);
            v59 = v70;
          }
          v60 = &v69[8 * v59];
          v61 = v79;
          *(_QWORD *)v60 = *(_QWORD *)(v58 + 16);
          ++v70;
          *(_QWORD *)(*(_QWORD *)(v58 + 16) + 24i64) = *(_DWORD *)(*(_QWORD *)(v58 + 16) + 24i64) & 3 | (unsigned __int64)(4i64 * *(int *)((char *)&edgesOutput->m_edges.m_data->m_b + v61));
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
      v5->m_enum = 1;
      v70 = 0;
      if ( v67 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v69,
          8 * v67);
      v69 = 0i64;
      v71 = 2147483648;
      v73 = 0;
      if ( v74 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          32 * v74);
      v14 = v5;
    }
  }
  return v14;
}ator::s_alloc,
          array,
          32 * v74);
      v14 = v5;
    }
  }
  return v14;
}

// File Line: 180
// RVA: 0xB84110
_BOOL8 __fastcall OrderCleanEdge(CleanEdgesOutput::CleanEdge *a, CleanEdgesOutput::CleanEdge *b)
{
  signed int v2; // er8
  int v3; // er9
  signed int v4; // ecx
  int v5; // eax
  CleanEdgesOutput::CleanEdge v7; // [rsp+8h] [rbp+8h]
  CleanEdgesOutput::CleanEdge v8; // [rsp+8h] [rbp+8h]

  v7 = *a;
  v2 = (signed int)*a;
  if ( v2 <= (signed int)(*(unsigned __int64 *)a >> 32) )
  {
    v3 = v7.m_b;
  }
  else
  {
    v3 = (int)*a;
    v2 = v7.m_b;
  }
  v8 = *b;
  v4 = (signed int)*b;
  if ( v4 <= (signed int)(*(unsigned __int64 *)b >> 32) )
  {
    v5 = v8.m_b;
  }
  else
  {
    v5 = (int)*b;
    v4 = v8.m_b;
  }
  return v2 < v4 || v2 == v4 && v3 < v5;
}

// File Line: 197
// RVA: 0xB84170
hkResult *__fastcall getAllEdges(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *srcVertices, hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end, CleanEdgesOutput *cleanEdgesOutput)
{
  CleanEdgesOutput *v5; // rbx
  hkaiEdgeGeometry::Edge *const *v6; // rdi
  hkaiEdgeGeometry::Edge *const *v7; // rbp
  int v8; // eax
  signed __int64 v9; // r8
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // r14
  hkResult *v11; // rsi
  int v12; // eax
  signed int v13; // er8
  CleanEdgesOutput::CleanEdge v15; // [rsp+60h] [rbp+18h]

  v5 = cleanEdgesOutput;
  v6 = start;
  v7 = end;
  v8 = cleanEdgesOutput->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = end - start;
  v10 = srcVertices;
  v11 = result;
  if ( v8 >= (signed int)v9 )
  {
    LODWORD(cleanEdgesOutput) = 0;
  }
  else
  {
    v12 = 2 * v8;
    if ( (signed int)v9 < v12 )
      LODWORD(v9) = v12;
    hkArrayUtil::_reserve(
      (hkResult *)&cleanEdgesOutput,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      cleanEdgesOutput,
      v9,
      8);
    if ( (_DWORD)cleanEdgesOutput )
    {
      v11->m_enum = 1;
      return v11;
    }
  }
  for ( ; v6 != v7; ++v6 )
  {
    v15 = **(CleanEdgesOutput::CleanEdge **)v6;
    if ( (_mm_movemask_ps(_mm_cmpeqps(v10->m_data[v15.m_a].m_quad, v10->m_data[(*v6)->m_b].m_quad)) & 7) != 7 )
    {
      if ( v5->m_edges.m_size == (v5->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
      v5->m_edges.m_data[v5->m_edges.m_size++] = v15;
    }
  }
  v13 = v5->m_edges.m_size;
  if ( v13 > 1 )
    hkAlgorithm::quickSortRecursive<CleanEdgesOutput::CleanEdge,unsigned int (*)(CleanEdgesOutput::CleanEdge const &,CleanEdgesOutput::CleanEdge const &)>(
      (hkaiStaticObstacleSystem::VelocityObstacleEdge *)v5->m_edges.m_data,
      0,
      v13 - 1,
      (unsigned int (__fastcall *)(hkaiStaticObstacleSystem::VelocityObstacleEdge *, hkaiStaticObstacleSystem::VelocityObstacleEdge *))OrderCleanEdge);
  v11->m_enum = 0;
  return v11;
}

// File Line: 228
// RVA: 0xB842C0
hkResult *__fastcall hkaiNavMeshGenerationUtils_triangulateFace(hkResult *result, hkaiNavMeshGenerationSettings *input, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *globalTriangulator, hkAabb *globalDomainAabb, hkArray<hkVector4f,hkContainerHeapAllocator> *srcVertices, CleanEdgesOutput *edgesOutput, hkVector4f *faceNormal, hkArray<int,hkContainerHeapAllocator> *trisOut, hkArray<int,hkContainerHeapAllocator> *triConnectivityOut, hkStopwatch *watch)
{
  hkResult *v10; // rbx
  hkAabb *v11; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *v12; // r15
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r10
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  CleanEdgesOutput *v18; // r12
  int v19; // eax
  unsigned int v20; // ecx
  _QWORD *v21; // r9
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v24; // rbx
  char v25; // si
  signed __int64 v26; // r8
  hkVector4f *v27; // r10
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  CleanEdgesOutput::CleanEdge *v30; // rdx
  __m128 v31; // xmm0
  __m128 v32; // xmm0
  CleanEdgesOutput *v33; // r13
  int v34; // edx
  float v35; // er8
  int v36; // er15
  __int64 v37; // rsi
  hkVector4f *v38; // rbx
  hkVector4f *v39; // rdi
  int v40; // ecx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v41; // rcx
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
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *l; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v58; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v59; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *m; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v61; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v62; // rdx
  hkStopwatch *v63; // rbx
  unsigned __int64 v64; // rax
  unsigned __int64 v65; // rdi
  hkArray<int,hkContainerHeapAllocator> *v66; // rbx
  hkArray<int,hkContainerHeapAllocator> *v67; // rsi
  __int64 v68; // r15
  __int64 v69; // r13
  __int64 v70; // r12
  int v71; // eax
  int v72; // eax
  __int64 v73; // rdx
  __int64 v74; // r8
  int v75; // ecx
  int v76; // eax
  __int64 v77; // rax
  signed __int64 v78; // rcx
  unsigned __int64 v79; // rax
  BOOL v80; // er15
  __int64 v81; // rdx
  __int64 v82; // r8
  int v83; // ecx
  int v84; // eax
  __int64 v85; // rax
  signed __int64 v86; // rcx
  unsigned __int64 v87; // rax
  BOOL v88; // er15
  __int64 v89; // rdx
  __int64 v90; // r8
  int v91; // ecx
  int v92; // eax
  __int64 v93; // rax
  signed __int64 v94; // rcx
  unsigned __int64 v95; // rax
  BOOL v96; // er15
  unsigned __int64 v97; // rax
  unsigned __int64 v98; // rcx
  _QWORD *v99; // rax
  unsigned __int64 v100; // r8
  _QWORD *v101; // r9
  unsigned __int64 v102; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *n; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v105; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v106; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *ii; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v108; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v109; // rdx
  hkVector4f dmin; // [rsp+30h] [rbp-D0h]
  int v111; // [rsp+40h] [rbp-C0h]
  hkVector4f dmax; // [rsp+50h] [rbp-B0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> v113; // [rsp+60h] [rbp-A0h]
  hkResult *v114; // [rsp+D80h] [rbp+C80h]

  v114 = result;
  v10 = result;
  v11 = globalDomainAabb;
  v12 = globalTriangulator;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "TttriangulateFace";
    v16 = __rdtsc();
    v17 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v15[1] = v17;
  }
  v18 = edgesOutput;
  v19 = edgesOutput->m_edges.m_size;
  if ( v19 )
  {
    v24 = srcVertices;
    v25 = 0;
    v26 = 0i64;
    if ( v19 > 0 )
    {
      v27 = srcVertices->m_data;
      v28 = v11->m_max.m_quad;
      v29 = v11->m_min.m_quad;
      v30 = edgesOutput->m_edges.m_data;
      while ( 1 )
      {
        v31 = v27[v30->m_a].m_quad;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v29, v31), _mm_cmpleps(v31, v28))) & 7) != 7 )
          break;
        v32 = v27[v30->m_b].m_quad;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v29, v32), _mm_cmpleps(v32, v28))) & 7) != 7 )
          break;
        ++v26;
        ++v30;
        if ( v26 >= edgesOutput->m_edges.m_size )
          goto LABEL_13;
      }
      v25 = 1;
    }
LABEL_13:
    _mm_store_si128((__m128i *)&v113.m_mesh.m_vertices, (__m128i)0i64);
    v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
    v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    dmin.m_quad = (__m128)_xmm;
    dmax.m_quad = _xmm;
    *(_DWORD *)&v113.m_memSizeAndFlags = 0x1FFFF;
    *(_DWORD *)&v113.m_mesh.m_memSizeAndFlags = 0x1FFFF;
    v113.m_mesh.m_vertices.m_numUsed = 0;
    v113.m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
    v113.m_mesh.m_triangles.m_used = 0i64;
    v113.m_mesh.m_triangles.m_numUsed = 0;
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
    v33 = (CleanEdgesOutput *)&v113;
    if ( !v25 )
      v33 = (CleanEdgesOutput *)v12;
    edgesOutput = v33;
    if ( v25 )
    {
      v34 = 0;
      v35 = -0.0;
      dmin.m_quad.m128_u64[0] = 0i64;
      dmin.m_quad.m128_u64[1] = 0x8000000000000000i64;
      v36 = 0;
      if ( v18->m_edges.m_size > 0 )
      {
        v37 = 0i64;
        while ( 1 )
        {
          v38 = &srcVertices->m_data[v18->m_edges.m_data[v37].m_a];
          v39 = &srcVertices->m_data[v18->m_edges.m_data[v37].m_b];
          if ( v34 == (LODWORD(v35) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &dmin, 16);
            v34 = dmin.m_quad.m128_i32[2];
          }
          *(hkVector4f *)(dmin.m_quad.m128_u64[0] + 16i64 * v34) = (hkVector4f)v38->m_quad;
          v40 = dmin.m_quad.m128_i32[2] + 1;
          dmin.m_quad.m128_i32[2] = v40;
          if ( v40 == (dmin.m_quad.m128_i32[3] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &dmin, 16);
            v40 = dmin.m_quad.m128_i32[2];
          }
          ++v36;
          ++v37;
          *(hkVector4f *)(dmin.m_quad.m128_u64[0] + 16i64 * v40) = (hkVector4f)v39->m_quad;
          v34 = dmin.m_quad.m128_i32[2]++ + 1;
          if ( v36 >= v18->m_edges.m_size )
            break;
          v35 = dmin.m_quad.m128_f32[3];
        }
        v33 = edgesOutput;
        v24 = srcVertices;
      }
      dmax.m_quad.m128_u64[1] = __PAIR__(16, v34);
      dmax.m_quad.m128_u64[0] = dmin.m_quad.m128_u64[0];
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *)v33,
        (hkStridedVertices *)&dmax,
        faceNormal,
        1,
        1,
        0);
      dmin.m_quad.m128_i32[2] = 0;
      if ( dmin.m_quad.m128_i32[3] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          (void *)dmin.m_quad.m128_u64[0],
          16 * dmin.m_quad.m128_i32[3]);
    }
    else
    {
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *)v33,
        1);
    }
    if ( LOBYTE(v33[198].m_edges.m_capacityAndFlags) )
    {
      v10 = v114;
      v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      v114->m_enum = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v113,
        1);
      v113.m_stack.m_size = 0;
      if ( v113.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v113.m_stack.m_data,
          16 * v113.m_stack.m_capacityAndFlags);
      v41 = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
      v113.m_stack.m_data = 0i64;
      v113.m_stack.m_capacityAndFlags = 2147483648;
      for ( v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
            v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            v41 = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
      {
        v42 = v41->m_links[0];
        if ( v42 )
          v42->m_links[1] = v41->m_links[1];
        else
          v113.m_mesh.m_triangles.m_allocator.m_firstPool = v41->m_links[1];
        v43 = v41->m_links[1];
        if ( v43 )
          v43->m_links[0] = v41->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v41,
          3616);
      }
      v113.m_mesh.m_triangles.m_used = 0i64;
      v113.m_mesh.m_triangles.m_numUsed = 0;
      if ( v41 )
      {
        do
        {
          v44 = v41->m_links[0];
          if ( v44 )
            v44->m_links[1] = v41->m_links[1];
          else
            v113.m_mesh.m_triangles.m_allocator.m_firstPool = v41->m_links[1];
          v45 = v41->m_links[1];
          if ( v45 )
            v45->m_links[0] = v41->m_links[0];
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v41,
            3616);
          v41 = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
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
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          i,
          1568);
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
          hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            i,
            1568);
          i = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
        }
        while ( v113.m_mesh.m_vertices.m_allocator.m_firstPool );
      }
      goto LABEL_138;
    }
    triangulatorAddEdges(
      (hkResult *)&edgesOutput,
      (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *)v33,
      v24->m_data,
      v24->m_size,
      v18);
    if ( (_DWORD)edgesOutput )
    {
      v10 = v114;
      v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      v114->m_enum = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v113,
        1);
      v113.m_stack.m_size = 0;
      if ( v113.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v113.m_stack.m_data,
          16 * v113.m_stack.m_capacityAndFlags);
      v113.m_stack.m_data = 0i64;
      v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      v113.m_stack.m_capacityAndFlags = 2147483648;
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
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          j,
          3616);
      }
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&v113.m_mesh.m_vertices);
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
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          k,
          1568);
      }
      goto LABEL_138;
    }
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::partitionWithPolicy<hkaiNavMeshFloodPolicy>(
      (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *)v33,
      (hkResult *)&edgesOutput,
      (hkaiNavMeshFloodPolicy *)&edgesOutput);
    if ( (_DWORD)edgesOutput )
    {
      v10 = v114;
      v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      v114->m_enum = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
        &v113,
        1);
      v113.m_stack.m_size = 0;
      if ( v113.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v113.m_stack.m_data,
          16 * v113.m_stack.m_capacityAndFlags);
      v113.m_stack.m_data = 0i64;
      v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      v113.m_stack.m_capacityAndFlags = 2147483648;
      hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
      for ( l = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            v113.m_mesh.m_triangles.m_allocator.m_firstPool;
            l = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
      {
        v58 = l->m_links[0];
        if ( v58 )
          v58->m_links[1] = l->m_links[1];
        else
          v113.m_mesh.m_triangles.m_allocator.m_firstPool = l->m_links[1];
        v59 = l->m_links[1];
        if ( v59 )
          v59->m_links[0] = l->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          l,
          3616);
      }
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&v113.m_mesh.m_vertices);
      for ( m = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            v113.m_mesh.m_vertices.m_allocator.m_firstPool;
            m = v113.m_mesh.m_vertices.m_allocator.m_firstPool )
      {
        v61 = m->m_links[0];
        if ( v61 )
          v61->m_links[1] = m->m_links[1];
        else
          v113.m_mesh.m_vertices.m_allocator.m_firstPool = m->m_links[1];
        v62 = m->m_links[1];
        if ( v62 )
          v62->m_links[0] = m->m_links[0];
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          m,
          1568);
      }
      goto LABEL_138;
    }
    v63 = watch;
    watch->m_running_flag.m_bool = 1;
    v64 = hkStopwatch::getTickCounter();
    v63->m_ticks_at_start = v64;
    v63->m_ticks_at_split = v64;
    v65 = (unsigned __int64)v33[4].m_edges.m_data;
    if ( v65 )
    {
      v66 = triConnectivityOut;
      v67 = trisOut;
      while ( 1 )
      {
        if ( (*(_WORD *)(v65 + 88) & 0xFFE0) == 32 )
        {
          v68 = *(_QWORD *)(*(_QWORD *)(v65 + 16) + 24i64) >> 2;
          v69 = *(_QWORD *)(*(_QWORD *)(v65 + 32) + 24i64) >> 2;
          v70 = *(_QWORD *)(*(_QWORD *)(v65 + 24) + 24i64) >> 2;
          hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
            (hkaiArrayUtil *)&edgesOutput,
            (hkResult *)v67,
            (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v67->m_size + 3),
            -1);
          hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
            (hkaiArrayUtil *)&v111,
            (hkResult *)v66,
            (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)(v66->m_size + 3),
            -1);
          if ( (_DWORD)edgesOutput )
          {
            v10 = v114;
            v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
            v114->m_enum = 1;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &v113,
              1);
            v113.m_stack.m_size = 0;
            if ( v113.m_stack.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v113.m_stack.m_data,
                16 * v113.m_stack.m_capacityAndFlags);
            v113.m_stack.m_data = 0i64;
            v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
            v113.m_stack.m_capacityAndFlags = 2147483648;
            hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
            for ( n = v113.m_mesh.m_triangles.m_allocator.m_firstPool;
                  v113.m_mesh.m_triangles.m_allocator.m_firstPool;
                  n = v113.m_mesh.m_triangles.m_allocator.m_firstPool )
            {
              v105 = n->m_links[0];
              if ( v105 )
                v105->m_links[1] = n->m_links[1];
              else
                v113.m_mesh.m_triangles.m_allocator.m_firstPool = n->m_links[1];
              v106 = n->m_links[1];
              if ( v106 )
                v106->m_links[0] = n->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                n,
                3616);
            }
            hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&v113.m_mesh.m_vertices);
            for ( ii = v113.m_mesh.m_vertices.m_allocator.m_firstPool;
                  v113.m_mesh.m_vertices.m_allocator.m_firstPool;
                  ii = v113.m_mesh.m_vertices.m_allocator.m_firstPool )
            {
              v108 = ii->m_links[0];
              if ( v108 )
                v108->m_links[1] = ii->m_links[1];
              else
                v113.m_mesh.m_vertices.m_allocator.m_firstPool = ii->m_links[1];
              v109 = ii->m_links[1];
              if ( v109 )
                v109->m_links[0] = ii->m_links[0];
              hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                ii,
                1568);
            }
            goto LABEL_138;
          }
          if ( v111 )
          {
            v10 = v114;
            v114->m_enum = 1;
            goto LABEL_135;
          }
          if ( v67->m_size == (v67->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v67, 4);
          v67->m_data[v67->m_size] = v68;
          v71 = v67->m_capacityAndFlags;
          if ( ++v67->m_size == (v71 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v67, 4);
          v67->m_data[v67->m_size] = v70;
          v72 = v67->m_capacityAndFlags;
          if ( ++v67->m_size == (v72 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v67, 4);
          v67->m_data[v67->m_size++] = v69;
          v73 = *(_QWORD *)(v65 + 24);
          v74 = *(_QWORD *)(v65 + 16);
          v75 = *(_DWORD *)(v73 + 16);
          v76 = *(_DWORD *)(v74 + 16);
          if ( v76 >= v75
            && (v76 > v75 || *(_DWORD *)(v74 + 20) > *(_DWORD *)(v73 + 20))
            && (v77 = *(_QWORD *)(v65 + 40), v77 & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v78 = *(_QWORD *)(v65 + 40) & 3i64;
            v79 = v77 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v79 = v65;
            LOBYTE(v78) = 0;
          }
          v80 = ((unsigned __int8)(1 << v78) & (unsigned __int8)*(_WORD *)(v79 + 88) & 7) != 0;
          if ( v66->m_size == (v66->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v66, 4);
          v66->m_data[v66->m_size++] = v80;
          v81 = *(_QWORD *)(v65 + 32);
          v82 = *(_QWORD *)(v65 + 24);
          v83 = *(_DWORD *)(v81 + 16);
          v84 = *(_DWORD *)(v82 + 16);
          if ( v84 >= v83
            && (v84 > v83 || *(_DWORD *)(v82 + 20) > *(_DWORD *)(v81 + 20))
            && (v85 = *(_QWORD *)(v65 + 48), v85 & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v86 = *(_QWORD *)(v65 + 48) & 3i64;
            v87 = v85 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v87 = v65;
            LOBYTE(v86) = 1;
          }
          v88 = ((unsigned __int8)(1 << v86) & (unsigned __int8)*(_WORD *)(v87 + 88) & 7) != 0;
          if ( v66->m_size == (v66->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v66, 4);
          v66->m_data[v66->m_size++] = v88;
          v89 = *(_QWORD *)(v65 + 16);
          v90 = *(_QWORD *)(v65 + 32);
          v91 = *(_DWORD *)(v89 + 16);
          v92 = *(_DWORD *)(v90 + 16);
          if ( v92 >= v91
            && (v92 > v91 || *(_DWORD *)(v90 + 20) > *(_DWORD *)(v89 + 20))
            && (v93 = *(_QWORD *)(v65 + 56), v93 & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v94 = *(_QWORD *)(v65 + 56) & 3i64;
            v95 = v93 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v95 = v65;
            LOBYTE(v94) = 2;
          }
          v96 = ((unsigned __int8)(1 << v94) & (unsigned __int8)*(_WORD *)(v95 + 88) & 7) != 0;
          if ( v66->m_size == (v66->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v66, 4);
          v66->m_data[v66->m_size++] = v96;
        }
        v65 = *(_QWORD *)v65;
        if ( !v65 )
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
    v10 = v114;
    v114->m_enum = 0;
LABEL_135:
    v113.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
      &v113,
      1);
    v113.m_stack.m_size = 0;
    if ( v113.m_stack.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v113.m_stack.m_data,
        16 * v113.m_stack.m_capacityAndFlags);
    v113.m_stack.m_data = 0i64;
    v113.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
    v113.m_stack.m_capacityAndFlags = 2147483648;
    hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v113.m_mesh.m_triangles);
    hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *)&v113.m_mesh.m_triangles);
    hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&v113.m_mesh.m_vertices);
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
    v20 = hkMonitorStream__m_instance.m_slotID;
    v10->m_enum = 0;
    v21 = TlsGetValue(v20);
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
}

// File Line: 420
// RVA: 0xB82210
hkResult *__fastcall hkaiNavMeshGenerationUtils::_triangulate(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiEdgeGeometry *geom, hkArray<int,hkContainerHeapAllocator> *trisOut, hkArray<int,hkContainerHeapAllocator> *trisPerFaceOut, hkArray<int,hkContainerHeapAllocator> *triConnectivityOut, hkArray<int,hkContainerHeapAllocator> *materialsOut, bool forceLocalDomain)
{
  hkResult *v8; // rbx
  void *v10; // [rsp+50h] [rbp-28h]
  int v11; // [rsp+58h] [rbp-20h]
  int v12; // [rsp+5Ch] [rbp-1Ch]
  void *v13; // [rsp+60h] [rbp-18h]
  int v14; // [rsp+68h] [rbp-10h]
  int v15; // [rsp+6Ch] [rbp-Ch]

  v8 = result;
  v10 = 0i64;
  v11 = 0;
  v12 = 2147483648;
  v13 = 0i64;
  v14 = 0;
  v15 = 2147483648;
  hkaiNavMeshGenerationUtils::_triangulate(
    result,
    input,
    geom,
    (hkaiFaceEdges *)&v10,
    trisOut,
    trisPerFaceOut,
    triConnectivityOut,
    materialsOut,
    forceLocalDomain);
  v14 = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      8 * v15);
  v13 = 0i64;
  v15 = 2147483648;
  v11 = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v10,
      8 * v12);
  return v8;
}

// File Line: 428
// RVA: 0xB81AA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_triangulate(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiEdgeGeometry *geom, hkaiFaceEdges *faceEdges, hkArray<int,hkContainerHeapAllocator> *trisOut, hkArray<int,hkContainerHeapAllocator> *trisPerFaceOut, hkArray<int,hkContainerHeapAllocator> *triConnectivityOut, hkArray<int,hkContainerHeapAllocator> *materialsOut, bool forceLocalDomain)
{
  hkResult *v9; // r14
  hkaiFaceEdges *v10; // rbx
  hkaiEdgeGeometry *v11; // r13
  hkaiNavMeshGenerationSettings *v12; // rsi
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  unsigned int v18; // ecx
  _QWORD *v19; // rax
  unsigned __int64 v20; // r8
  _QWORD *v21; // r9
  unsigned __int64 v22; // rax
  int v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // er9
  int v27; // eax
  int v28; // eax
  int v29; // er9
  float v30; // er8
  __m128i v31; // xmm3
  signed __int64 v32; // rsi
  __m128 v33; // xmm3
  __int64 v34; // rax
  __m128 v35; // xmm1
  signed __int64 v36; // r12
  hkaiEdgeGeometry::Edge *const **v37; // r8
  int v38; // edi
  int v39; // edi
  int v40; // er9
  int v41; // eax
  int v42; // eax
  float v43; // er8
  __int64 v44; // rsi
  int v45; // edi
  _QWORD *v46; // r9
  unsigned __int64 v47; // r8
  unsigned __int64 v48; // rax
  hkVector4f dmax; // [rsp+50h] [rbp-B0h]
  hkResult resulta; // [rsp+60h] [rbp-A0h]
  hkResult v52; // [rsp+64h] [rbp-9Ch]
  hkResult v53; // [rsp+68h] [rbp-98h]
  hkResult v54; // [rsp+6Ch] [rbp-94h]
  hkVector4f dmin; // [rsp+70h] [rbp-90h]
  hkAabb globalDomainAabb; // [rsp+80h] [rbp-80h]
  __int128 v57; // [rsp+A0h] [rbp-60h]
  __int64 v58; // [rsp+B0h] [rbp-50h]
  hkStopwatch watch; // [rsp+B8h] [rbp-48h]
  hkVector4f normalOut; // [rsp+F0h] [rbp-10h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> globalTriangulator; // [rsp+100h] [rbp+0h]
  hkaiNavMeshGenerationSettings *inputa; // [rsp+E38h] [rbp+D38h]
  hkaiFaceEdges *faceEdgesa; // [rsp+E48h] [rbp+D48h]

  faceEdgesa = faceEdges;
  inputa = input;
  v9 = result;
  v10 = faceEdges;
  v11 = geom;
  v12 = input;
  watch.m_name = 0i64;
  watch.m_ticks_at_start = 0i64;
  watch.m_ticks_total = 0i64;
  watch.m_ticks_at_split = 0i64;
  watch.m_split_total = 0i64;
  watch.m_running_flag.m_bool = 0;
  watch.m_num_timings = 0;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Tt_triangulate";
    v16 = __rdtsc();
    v17 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v15[1] = v17;
  }
  hkaiFaceEdges::clear(v10);
  hkaiFaceEdges::setGeometry(v10, &resulta, v11);
  if ( resulta.m_enum )
  {
    v18 = hkMonitorStream__m_instance.m_slotID;
    v9->m_enum = 1;
    v19 = TlsGetValue(v18);
    v20 = v19[1];
    v21 = v19;
    if ( v20 < v19[3] )
    {
      *(_QWORD *)v20 = "Et";
      v22 = __rdtsc();
      *(_DWORD *)(v20 + 8) = v22;
      v21[1] = v20 + 16;
    }
    return v9;
  }
  v23 = v10->m_faceStartEdges.m_size - 1;
  v24 = trisPerFaceOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 >= v23 )
  {
    v52.m_enum = 0;
    goto LABEL_12;
  }
  v25 = 2 * v24;
  v26 = v10->m_faceStartEdges.m_size - 1;
  if ( v23 < v25 )
    v26 = v25;
  hkArrayUtil::_reserve(&v52, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, trisPerFaceOut, v26, 4);
  if ( v52.m_enum == HK_SUCCESS )
  {
    if ( !materialsOut )
      goto LABEL_59;
    v27 = materialsOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 >= v23 )
      goto LABEL_59;
LABEL_12:
    v28 = 2 * v27;
    v29 = v23;
    if ( v23 < v28 )
      v29 = v28;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, materialsOut, v29, 4);
    if ( resulta.m_enum )
    {
      v9->m_enum = 1;
    }
    else
    {
LABEL_59:
      globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
      _mm_store_si128((__m128i *)&globalTriangulator.m_mesh.m_vertices, (__m128i)0i64);
      globalTriangulator.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      globalTriangulator.m_mesh.m_vertices.m_numUsed = 0;
      globalTriangulator.m_mesh.m_triangles.m_allocator.m_firstPool = 0i64;
      dmin.m_quad = (__m128)_xmm;
      dmax.m_quad = _xmm;
      globalTriangulator.m_mesh.m_triangles.m_used = 0i64;
      globalTriangulator.m_mesh.m_triangles.m_numUsed = 0;
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
      globalDomainAabb.m_min.m_quad.m128_u64[1] = -9223372028264841214i64;
      dmax.m_quad.m128_u64[0] = (unsigned __int64)&globalDomainAabb.m_max;
      dmax.m_quad.m128_u64[1] = 68719476738i64;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        &globalTriangulator,
        (hkStridedVertices *)&dmax,
        &v12->m_up,
        0,
        1,
        0);
      v30 = globalDomainAabb.m_min.m_quad.m128_f32[3];
      if ( globalTriangulator.m_status.m_storage )
      {
        v9->m_enum = 1;
        globalDomainAabb.m_min.m_quad.m128_i32[2] = 0;
        if ( v30 >= 0.0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)globalDomainAabb.m_min.m_quad.m128_u64[0],
            16 * LODWORD(v30));
        globalDomainAabb.m_min.m_quad.m128_u64[0] = 0i64;
        globalDomainAabb.m_min.m_quad.m128_i32[3] = 2147483648;
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
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)globalDomainAabb.m_min.m_quad.m128_u64[0],
            16 * globalDomainAabb.m_min.m_quad.m128_i32[3]);
        v31 = _mm_load_si128((const __m128i *)&v12->m_up);
        v52.m_enum = 1;
        v32 = 1i64;
        v58 = 1i64;
        v33 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u);
        dmin.m_quad = (__m128)_xmm;
        dmax.m_quad = (__m128)_xmm_c4f98000c4f98000c4f98000c4f98000;
        v34 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmpleps(
                                                                         _mm_max_ps(
                                                                           _mm_shuffle_ps(v33, v33, 170),
                                                                           _mm_max_ps(
                                                                             _mm_shuffle_ps(v33, v33, 85),
                                                                             _mm_shuffle_ps(v33, v33, 0))),
                                                                         v33),
                                                                       (__m128)xmmword_141A4D8E0))];
        dmin.m_quad.m128_i32[v34] = 2139095022;
        v35 = dmin.m_quad;
        dmax.m_quad.m128_i32[v34] = -8388626;
        globalDomainAabb.m_max.m_quad = v35;
        dmin.m_quad.m128_u64[0] = v23;
        globalDomainAabb.m_min = (hkVector4f)dmax.m_quad;
        if ( v23 <= 1i64 )
        {
LABEL_50:
          v9->m_enum = 0;
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
            v37 = faceEdgesa->m_faceStartEdges.m_data;
            v38 = trisOut->m_size;
            dmax.m_quad.m128_u64[1] = 0x8000000000000000i64;
            getAllEdges(&v53, &v11->m_vertices, v37[v32], v37[v32 + 1], (CleanEdgesOutput *)&dmax);
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
            hkaiEdgeGeometry::calculateFaceNormal(v11, faceEdgesa, v52.m_enum, &normalOut);
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
              &globalTriangulator,
              1);
            hkaiNavMeshGenerationUtils_triangulateFace(
              &v54,
              inputa,
              &globalTriangulator,
              &globalDomainAabb,
              &v11->m_vertices,
              (CleanEdgesOutput *)&dmax,
              &normalOut,
              trisOut,
              triConnectivityOut,
              &watch);
            if ( v54.m_enum )
              break;
            v39 = (trisOut->m_size - v38) / 3;
            if ( trisPerFaceOut->m_size == (trisPerFaceOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                trisPerFaceOut,
                4);
            trisPerFaceOut->m_data[trisPerFaceOut->m_size++] = v39;
            if ( materialsOut )
            {
              v40 = v39 + materialsOut->m_size;
              v41 = materialsOut->m_capacityAndFlags & 0x3FFFFFFF;
              if ( v41 >= v40 )
              {
                resulta.m_enum = 0;
              }
              else
              {
                v42 = 2 * v41;
                if ( v40 < v42 )
                  v40 = v42;
                hkArrayUtil::_reserve(
                  &resulta,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  materialsOut,
                  v40,
                  4);
                if ( resulta.m_enum )
                  break;
              }
              if ( v39 > 0 )
              {
                v44 = (unsigned int)v39;
                do
                {
                  v45 = v11->m_faces.m_data[v36].m_data;
                  if ( materialsOut->m_size == (materialsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      materialsOut,
                      4);
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
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                (void *)dmax.m_quad.m128_u64[0],
                8 * dmax.m_quad.m128_i32[3]);
            ++v52.m_enum;
            ++v32;
            ++v36;
            dmax.m_quad.m128_u64[0] = 0i64;
            dmax.m_quad.m128_i32[3] = 2147483648;
            v58 = v32;
            if ( v32 >= (signed __int64)dmin.m_quad.m128_u64[0] )
              goto LABEL_50;
          }
          v43 = dmax.m_quad.m128_f32[3];
          dmax.m_quad.m128_i32[2] = 0;
          v9->m_enum = 1;
          if ( v43 >= 0.0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (void *)dmax.m_quad.m128_u64[0],
              8 * LODWORD(v43));
          dmax.m_quad.m128_u64[0] = 0i64;
          dmax.m_quad.m128_i32[3] = 2147483648;
          globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::`vftable;
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
            &globalTriangulator,
            1);
        }
      }
      globalTriangulator.m_stack.m_size = 0;
      if ( globalTriangulator.m_stack.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          globalTriangulator.m_stack.m_data,
          16 * globalTriangulator.m_stack.m_capacityAndFlags);
      globalTriangulator.m_stack.m_data = 0i64;
      globalTriangulator.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkgpAbstractMesh<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkContainerHeapAllocator>::`vftable;
      globalTriangulator.m_stack.m_capacityAndFlags = 2147483648;
      hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&globalTriangulator.m_mesh.m_triangles);
      hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *)&globalTriangulator.m_mesh.m_triangles);
      hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&globalTriangulator.m_mesh.m_vertices);
      hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&globalTriangulator.m_mesh.m_vertices);
      globalTriangulator.m_mesh.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      globalTriangulator.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    goto LABEL_54;
  }
  v9->m_enum = 1;
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
  return v9;
}

// File Line: 600
// RVA: 0xB81830
hkResult *__fastcall hkaiNavMeshGenerationUtils::_findSharedEdges(hkResult *result, const int *indicesPtr, int numIndices, int *oppositeEdgesOut)
{
  signed __int64 v4; // rbx
  int *v5; // r13
  const int *v6; // r14
  hkResult *v7; // r12
  __int64 v8; // rcx
  int *v9; // rdi
  Edge *v10; // rcx
  int v11; // er9
  int v12; // er11
  signed __int64 v13; // r10
  signed int v14; // er15
  signed int v15; // er9
  __int64 v16; // rdi
  signed __int64 v17; // rax
  signed __int64 v18; // r8
  __int64 v19; // rdx
  __int64 v20; // rax
  unsigned __int64 v21; // rcx
  int v22; // er8
  Edge *v23; // rdx
  int v24; // eax
  Edge *v25; // rdi
  unsigned __int64 v26; // r9
  Edge *i; // rax
  Edge *array; // [rsp+30h] [rbp-38h]
  int v30; // [rsp+38h] [rbp-30h]
  int v31; // [rsp+3Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+80h] [rbp+18h]

  v4 = numIndices;
  v5 = oppositeEdgesOut;
  v6 = indicesPtr;
  v7 = result;
  if ( numIndices - 1 >= 0 )
  {
    v8 = (unsigned int)numIndices;
    v9 = oppositeEdgesOut;
    while ( v8 )
    {
      *v9 = -1;
      ++v9;
      --v8;
    }
  }
  if ( numIndices <= 3 )
  {
    v7->m_enum = 0;
    return v7;
  }
  v10 = 0i64;
  v30 = 0;
  array = 0i64;
  v31 = 2147483648;
  if ( numIndices + 1 > 0 )
  {
    v11 = numIndices + 1;
    if ( numIndices + 1 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v11, 16);
    if ( resulta.m_enum )
    {
      v22 = v31;
      v7->m_enum = 1;
      v30 = 0;
      if ( v22 < 0 )
        return v7;
      v23 = array;
LABEL_32:
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v23,
        16 * v22);
      return v7;
    }
    v10 = array;
  }
  v30 = v4 + 1;
  v12 = 0;
  v10[v4].m_key = -1i64;
  v13 = 0i64;
  if ( (signed int)v4 > 0 )
  {
    do
    {
      v14 = 2;
      v15 = 0;
      v16 = 0i64;
      v17 = 8i64;
      v18 = v13;
      do
      {
        v19 = *(const int *)((char *)&v6[v13] + v17);
        v20 = v6[v13 + v16];
        if ( (signed int)v19 >= (signed int)v20 )
          v21 = v19 | (v20 << 32);
        else
          v21 = v20 | (v19 << 32);
        ++v18;
        array[v18 - 1].m_key = v21;
        *((_DWORD *)&array[v18] - 2) = v14 + v12;
        v14 = v15++;
        v17 = v16 * 4;
        ++v16;
      }
      while ( v15 < 3 );
      v13 += 3i64;
      v12 += 3;
    }
    while ( v13 < v4 );
  }
  v24 = v30;
  if ( v30 - 1 > 1 )
  {
    hkAlgorithm::quickSortRecursive<Edge,hkAlgorithm::less<Edge>>(array, 0, v30 - 2, 0);
    v24 = v30;
  }
  v25 = array;
  v26 = (unsigned __int64)&array[v24 - 1];
  if ( (unsigned __int64)array < v26 )
  {
    do
    {
      for ( i = v25 + 1; i->m_key == v25->m_key; ++i )
        ;
      if ( (unsigned int)(i - v25) == 2 )
      {
        v5[v25[1].m_edgeIdx] = v25->m_edgeIdx;
        v5[v25->m_edgeIdx] = v25[1].m_edgeIdx;
      }
      v25 = i;
    }
    while ( (unsigned __int64)i < v26 );
    v25 = array;
  }
  v22 = v31;
  v7->m_enum = 0;
  v30 = 0;
  if ( v22 >= 0 )
  {
    v23 = v25;
    goto LABEL_32;
  }
  return v7;
}

// File Line: 725
// RVA: 0xB81750
hkResult *__fastcall hkaiNavMeshGenerationUtils::_nullHertelMehlhorn(hkResult *result, hkVector4f *verts, const int *triangleIndices, const int *materials, const int *oppEdges, int numIndices, int *convexIndices, int *convexMaterials, int *oppConvexEdges, int *numIndicesPerPiece, int *numPieces)
{
  hkResult *v11; // r11
  __int64 v12; // rdx
  signed __int64 v13; // r10
  int v14; // eax
  const int *v15; // rcx
  __int64 v16; // rdx
  int v17; // eax
  __int64 v18; // rcx
  signed __int64 v19; // r8
  int v20; // eax
  int v21; // eax
  int *v22; // rcx
  hkResult *v23; // rax

  v11 = result;
  if ( numIndices > 0 )
  {
    v12 = (unsigned int)numIndices;
    v13 = (char *)convexIndices - (char *)triangleIndices;
    do
    {
      v14 = *triangleIndices;
      ++triangleIndices;
      *(const int *)((char *)triangleIndices + v13 - 4) = v14;
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
      v17 = *v15;
      ++v15;
      *(const int *)((char *)v15 + (char *)oppConvexEdges - (char *)oppEdges - 4) = v17;
      --v16;
    }
    while ( v16 );
  }
  *numPieces = numIndices / 3;
  if ( numIndices / 3 > 0 )
  {
    v18 = numIndices / 3;
    v19 = (char *)convexMaterials - (char *)materials;
    do
    {
      v20 = *materials;
      ++materials;
      *(const int *)((char *)materials + v19 - 4) = v20;
      --v18;
    }
    while ( v18 );
  }
  v21 = 0;
  if ( *numPieces > 0 )
  {
    v22 = numIndicesPerPiece;
    do
    {
      *v22 = 3;
      ++v21;
      ++v22;
    }
    while ( v21 < *numPieces );
  }
  v23 = v11;
  v11->m_enum = 0;
  return v23;
}

// File Line: 741
// RVA: 0xB85100
__int64 __fastcall getNumSharedVertices(hkArrayBase<int> *polyA, hkArrayBase<int> *polyB)
{
  __int64 v2; // rbx
  unsigned int v3; // er11
  __int64 v4; // r10
  hkArrayBase<int> *v5; // rdi
  hkArrayBase<int> *v6; // rsi
  __int64 v7; // r9
  int v8; // edx
  __int64 v9; // rcx
  int *v10; // rax

  v2 = polyA->m_size;
  v3 = 0;
  v4 = 0i64;
  v5 = polyB;
  v6 = polyA;
  if ( v2 > 0 )
  {
    v7 = polyB->m_size;
    do
    {
      v8 = 0;
      v9 = 0i64;
      if ( v7 > 0 )
      {
        v10 = v5->m_data;
        while ( *v10 != v6->m_data[v4] )
        {
          ++v9;
          ++v8;
          ++v10;
          if ( v9 >= v7 )
            goto LABEL_10;
        }
        if ( v8 != -1 )
          ++v3;
      }
LABEL_10:
      ++v4;
    }
    while ( v4 < v2 );
  }
  return v3;
}

// File Line: 765
// RVA: 0xB7FAA0
hkResult *__usercall hkaiNavMeshGenerationUtils::_hertelMehlhorn@<rax>(hkResult *result@<rcx>, hkVector4f *verts@<rdx>, const int *triangleIndices@<r8>, const int *materials@<r9>, _DWORD *a5@<rdi>, const int *oppEdges, int numIndices, hkaiNavMeshGenerationSettings *settings, int *convexIndices, int *convexMaterials, int *oppConvexEdges, int *numIndicesPerPiece, int *numPieces, hkVector4f *norm)
{
  __m128i v14; // xmm5
  const int *v15; // r12
  hkResult *v16; // r15
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
  hkResultEnum v31; // er13
  const int *v32; // rbx
  int v33; // er8
  _DWORD *v34; // r9
  __int32 v35; // er14
  char *v36; // rdx
  int v37; // er9
  __int64 v38; // rdi
  char *v39; // rbx
  int v40; // er8
  int v41; // eax
  signed __int64 v42; // rcx
  __int64 v43; // r8
  __int64 v44; // r14
  int v45; // er9
  __int64 v46; // rdi
  int *v47; // rbx
  int v48; // er8
  __int64 v49; // rcx
  signed __int64 v50; // r8
  __int64 v51; // rdi
  int *v52; // rbx
  int v53; // er8
  __int64 v54; // rdi
  char *v55; // rbx
  int v56; // er8
  __int64 v58; // rdi
  int *v59; // rbx
  int v60; // er8
  __int64 v61; // rdi
  char *v62; // rbx
  int v63; // er8
  hkResultEnum v64; // er15
  __int64 v65; // rbx
  _DWORD *v66; // rdi
  __int64 v67; // r12
  char *v68; // r14
  int v69; // eax
  int v70; // eax
  int v71; // er9
  __int64 v72; // r14
  int v73; // eax
  int v74; // eax
  int v75; // er9
  hkResultEnum v76; // eax
  int v77; // ecx
  signed __int64 v78; // rdx
  signed __int64 v79; // rdx
  int v80; // ecx
  signed __int64 v81; // rdx
  __int64 v82; // rcx
  bool v83; // zf
  bool v84; // sf
  signed int v85; // ecx
  __int64 v86; // r10
  _DWORD *v87; // r8
  signed __int64 v88; // rdi
  char *v89; // rax
  __int64 v90; // rdx
  __int64 v91; // r14
  unsigned __int64 v92; // rax
  int v93; // ebx
  __int64 v94; // rax
  __int64 v95; // r15
  int v96; // er12
  signed __int64 v97; // r13
  int v98; // eax
  __int64 v99; // r9
  __int64 v100; // r10
  __int32 v101; // edx
  __int64 v102; // rbx
  __int64 v103; // r11
  __int64 v104; // r14
  _DWORD *v105; // r14
  __int64 v106; // rdi
  char *v107; // rbx
  int v108; // er8
  __int64 v109; // rdi
  char *v110; // rbx
  int v111; // er8
  __int64 v112; // rdi
  char *v113; // rbx
  int v114; // er8
  __int64 v115; // rdi
  char *v116; // rbx
  int v117; // er8
  __int128 v118; // xmm0
  __m128 v119; // xmm1
  __int64 v120; // rdx
  __int64 v121; // r10
  __int128 v122; // xmm0
  __int64 v123; // r10
  __int64 v124; // r11
  __int128 v125; // xmm0
  __int64 v126; // r10
  __int128 v127; // xmm0
  __int64 v128; // r10
  __int128 v129; // xmm0
  __int64 v130; // r9
  __int128 v131; // xmm0
  float v132; // xmm15_4
  char v133; // dl
  char v134; // r9
  __int64 v135; // kr00_8
  float v136; // xmm1_4
  float v137; // xmm12_4
  float v138; // xmm11_4
  float v139; // xmm8_4
  float v140; // xmm10_4
  bool v141; // cl
  float v142; // xmm5_4
  float v143; // xmm6_4
  bool v144; // al
  __int64 v145; // rax
  int v146; // eax
  int v147; // er9
  int v148; // eax
  char *v149; // r10
  int v150; // eax
  int v151; // er9
  int v152; // eax
  hkResultEnum v153; // eax
  signed __int64 v154; // r15
  __int32 v155; // esi
  int v156; // er11
  __int64 v157; // r9
  int v158; // ebx
  int v159; // er14
  __int64 v160; // rax
  __int64 v161; // rcx
  signed __int64 v162; // rcx
  int v163; // edx
  __int64 v164; // rdx
  __int64 v165; // rax
  char *v166; // rax
  signed __int64 v167; // rcx
  int v168; // edx
  __int64 v169; // rdx
  int v170; // eax
  int v171; // er8
  __int64 v172; // r11
  __int64 v173; // r9
  __int64 v174; // rcx
  __int64 v175; // rcx
  int v176; // edi
  int *v177; // r14
  signed int v178; // er15
  hkResult *v179; // rbx
  _DWORD *v180; // rsi
  int v181; // er9
  signed int v182; // edi
  hkVector4f *v183; // r15
  __int64 v184; // r10
  __int64 v185; // r11
  __int64 v186; // r13
  char *v187; // rdx
  __int64 v188; // r9
  hkResultEnum *v189; // rcx
  hkResult *v190; // r8
  __int64 v191; // rdx
  hkResultEnum v192; // eax
  int v193; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v194; // rbx
  int v195; // edi
  hkArray<int,hkContainerHeapAllocator> *v196; // rbx
  int v197; // er8
  int v198; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v199; // rbx
  int v200; // edi
  hkArray<int,hkContainerHeapAllocator> *v201; // rbx
  int v202; // er8
  int v203; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v204; // rbx
  int v205; // edi
  hkArray<int,hkContainerHeapAllocator> *v206; // rbx
  unsigned int v207; // er13
  _DWORD *v208; // r8
  _DWORD *v209; // rdi
  __int64 v210; // r12
  int v211; // ebx
  __int64 v212; // r11
  __int64 v213; // r10
  int v214; // edi
  hkArray<unsigned __int64,hkContainerHeapAllocator> *v215; // rbx
  int v216; // edi
  hkArray<int,hkContainerHeapAllocator> *v217; // rbx
  char *v218; // [rsp+30h] [rbp-98h]
  unsigned int v219; // [rsp+38h] [rbp-90h]
  int v220; // [rsp+3Ch] [rbp-8Ch]
  char *array; // [rsp+40h] [rbp-88h]
  __int64 v222; // [rsp+48h] [rbp-80h]
  __int64 v223; // [rsp+50h] [rbp-78h]
  hkResult v224; // [rsp+58h] [rbp-70h]
  hkResult v225; // [rsp+5Ch] [rbp-6Ch]
  __int64 v226; // [rsp+60h] [rbp-68h]
  void *v227; // [rsp+68h] [rbp-60h]
  __int64 v228; // [rsp+70h] [rbp-58h]
  __int64 v229; // [rsp+78h] [rbp-50h]
  __int64 v230; // [rsp+80h] [rbp-48h]
  __int64 v231; // [rsp+88h] [rbp-40h]
  __int64 v232; // [rsp+90h] [rbp-38h]
  __int64 v233; // [rsp+98h] [rbp-30h]
  __int64 v234; // [rsp+A0h] [rbp-28h]
  __int64 v235; // [rsp+A8h] [rbp-20h]
  __int64 v236; // [rsp+B0h] [rbp-18h]
  __int64 v237; // [rsp+B8h] [rbp-10h]
  __int64 v238; // [rsp+C0h] [rbp-8h]
  __int64 v239; // [rsp+C8h] [rbp+0h]
  __int64 v240; // [rsp+D0h] [rbp+8h]
  __int64 v241; // [rsp+D8h] [rbp+10h]
  __int64 v242; // [rsp+E0h] [rbp+18h]
  __m128 v243; // [rsp+E8h] [rbp+20h]
  _DWORD *v244; // [rsp+1D8h] [rbp+110h]
  __int64 v245; // [rsp+1E0h] [rbp+118h]
  __int64 v246; // [rsp+1F0h] [rbp+128h]
  __int64 v247; // [rsp+1F8h] [rbp+130h]
  hkResult resulta; // [rsp+200h] [rbp+138h]
  float *retaddr; // [rsp+208h] [rbp+140h]
  hkResult *v250; // [rsp+210h] [rbp+148h]
  hkVector4f *v251; // [rsp+218h] [rbp+150h]
  _DWORD *v252; // [rsp+220h] [rbp+158h]
  const int *v253; // [rsp+228h] [rbp+160h]

  v253 = materials;
  v251 = verts;
  v250 = result;
  v14 = _mm_load_si128((const __m128i *)_xmm);
  v15 = triangleIndices;
  v16 = result;
  v17 = _mm_add_epi32(v14, v14);
  *(float *)&v223 = retaddr[13] * 0.017453292;
  v18 = _mm_add_ps((__m128)(unsigned int)v223, *(__m128 *)_xmm);
  v19 = _mm_andnot_ps(*(__m128 *)_xmm, v18);
  v20 = _mm_andnot_si128(v14, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v19, *(__m128 *)_xmm)), v14));
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
  v27 = _mm_load_si128(*(const __m128i **)&numIndices);
  v28 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u);
  v243 = _mm_xor_ps(
           _mm_xor_ps(
             _mm_or_ps(v25, v26),
             _mm_xor_ps(
               (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v17, v17), v20), 0x1Du),
               _mm_and_ps(v18, *(__m128 *)_xmm))),
           *(__m128 *)_xmm);
  v29 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v28, v28, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v28, v28, 85),
                                                                       _mm_shuffle_ps(v28, v28, 0))),
                                                                   v28),
                                                                 (__m128)xmmword_141A4D8E0))];
  LODWORD(v223) = v29;
  v30 = _mm_movemask_ps(_mm_cmpltps((__m128)v27, (__m128)0i64));
  if ( _bittest(&v30, v29) )
  {
    v29 += 3;
    LODWORD(v223) = v29;
  }
  v31 = resulta.m_enum;
  v32 = oppEdges;
  v252 = a5;
  v33 = 0;
  v222 = 0x8000000000000000i64;
  v34 = 0i64;
  v218 = 0i64;
  v219 = 0;
  v220 = 2147483648;
  v35 = resulta.m_enum / 3;
  v36 = 0i64;
  array = 0i64;
  *oppEdges = resulta.m_enum / 3;
  if ( v35 <= 0 )
  {
    resulta.m_enum = 0;
    goto LABEL_9;
  }
  v37 = v35;
  if ( v35 < 0 )
    v37 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v37, 16);
  v36 = array;
  v34 = v218;
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v33 = v222;
LABEL_9:
    v38 = v33 - v35 - 1;
    if ( v33 - v35 - 1 >= 0 )
    {
      v39 = &v36[16 * v35 + 12 + 16 * v38];
      do
      {
        v40 = *(_DWORD *)v39;
        *((_DWORD *)v39 - 1) = 0;
        if ( v40 >= 0 )
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            *(_QWORD *)(v39 - 12),
            (unsigned int)(4 * v40),
            v34);
        *(_QWORD *)(v39 - 12) = 0i64;
        *(_DWORD *)v39 = 2147483648;
        v39 -= 16;
        --v38;
      }
      while ( v38 >= 0 );
      v33 = v222;
      v36 = array;
      v34 = v218;
      v32 = oppEdges;
    }
    v41 = v35 - v33;
    v42 = (signed __int64)&v36[16 * v33];
    v43 = v35 - v33;
    if ( v41 > 0 )
    {
      do
      {
        if ( v42 )
        {
          *(_QWORD *)v42 = 0i64;
          *(_DWORD *)(v42 + 8) = 0;
          *(_DWORD *)(v42 + 12) = 2147483648;
        }
        v42 += 16i64;
        --v43;
      }
      while ( v43 );
      v36 = array;
      v34 = v218;
    }
    LODWORD(v222) = v35;
  }
  v44 = *v32;
  if ( (v220 & 0x3FFFFFFF) >= (signed int)v44 )
  {
    numIndices = 0;
LABEL_27:
    v46 = (signed int)(v219 - v44 - 1);
    if ( (signed int)(v219 - v44 - 1) >= 0 )
    {
      v47 = &v34[4 * v44 + 3 + 4 * v46];
      do
      {
        v48 = *v47;
        *(v47 - 1) = 0;
        if ( v48 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v47 - 3),
            8 * v48);
        *(_QWORD *)(v47 - 3) = 0i64;
        *v47 = 2147483648;
        v47 -= 4;
        --v46;
      }
      while ( v46 >= 0 );
      v36 = array;
      v34 = v218;
    }
    v49 = (signed int)(v44 - v219);
    v50 = (signed __int64)&v34[4 * v219];
    if ( (signed int)(v44 - v219) > 0 )
    {
      do
      {
        if ( v50 )
        {
          *(_QWORD *)v50 = 0i64;
          *(_DWORD *)(v50 + 8) = 0;
          *(_DWORD *)(v50 + 12) = 2147483648;
        }
        v50 += 16i64;
        --v49;
      }
      while ( v49 );
      v36 = array;
      v34 = v218;
    }
    v219 = v44;
    goto LABEL_39;
  }
  v45 = *v32;
  if ( (signed int)v44 < 2 * (v220 & 0x3FFFFFFF) )
    v45 = 2 * (v220 & 0x3FFFFFFF);
  hkArrayUtil::_reserve(
    (hkResult *)&numIndices,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    &v218,
    v45,
    16);
  v36 = array;
  v34 = v218;
  if ( !numIndices )
    goto LABEL_27;
  LODWORD(v44) = v219;
LABEL_39:
  if ( resulta.m_enum )
  {
    v16->m_enum = 1;
    v51 = (signed int)v44 - 1;
    if ( (signed int)v44 - 1 >= 0 )
    {
      v52 = &v34[4 * v51 + 3];
      do
      {
        v53 = *v52;
        *(v52 - 1) = 0;
        if ( v53 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v52 - 3),
            8 * v53);
        *(_QWORD *)(v52 - 3) = 0i64;
        *v52 = 2147483648;
        v52 -= 4;
        --v51;
      }
      while ( v51 >= 0 );
      v36 = array;
      v34 = v218;
    }
    v219 = 0;
    if ( v220 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v34,
        16 * v220);
      v36 = array;
    }
    v218 = 0i64;
    v220 = 2147483648;
    v54 = (signed int)v222 - 1;
    if ( (signed int)v222 - 1 < 0 )
      goto LABEL_54;
    v55 = &v36[16 * ((signed int)v222 - 1) + 12];
    do
    {
      v56 = *(_DWORD *)v55;
      *((_DWORD *)v55 - 1) = 0;
      if ( v56 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v55 - 12),
          (unsigned int)(4 * v56),
          v34);
      *(_QWORD *)(v55 - 12) = 0i64;
      *(_DWORD *)v55 = 2147483648;
      v55 -= 16;
      --v54;
    }
    while ( v54 >= 0 );
LABEL_53:
    v36 = array;
LABEL_54:
    LODWORD(v222) = 0;
    if ( v222 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v36,
        (unsigned int)(16 * HIDWORD(v222)),
        v34);
    return v16;
  }
  if ( numIndices )
  {
    v16->m_enum = 1;
    v58 = (signed int)v44 - 1;
    if ( (signed int)v44 - 1 >= 0 )
    {
      v59 = &v34[4 * v58 + 3];
      do
      {
        v60 = *v59;
        *(v59 - 1) = 0;
        if ( v60 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v59 - 3),
            8 * v60);
        *(_QWORD *)(v59 - 3) = 0i64;
        *v59 = 2147483648;
        v59 -= 4;
        --v58;
      }
      while ( v58 >= 0 );
      v36 = array;
      v34 = v218;
    }
    v219 = 0;
    if ( v220 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v34,
        16 * v220);
      v36 = array;
    }
    v218 = 0i64;
    v220 = 2147483648;
    v61 = (signed int)v222 - 1;
    if ( (signed int)v222 - 1 < 0 )
      goto LABEL_54;
    v62 = &v36[16 * ((signed int)v222 - 1) + 12];
    do
    {
      v63 = *(_DWORD *)v62;
      *((_DWORD *)v62 - 1) = 0;
      if ( v63 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v62 - 12),
          (unsigned int)(4 * v63),
          v34);
      *(_QWORD *)(v62 - 12) = 0i64;
      *(_DWORD *)v62 = 2147483648;
      v62 -= 16;
      --v61;
    }
    while ( v61 >= 0 );
    goto LABEL_53;
  }
  v64 = 0;
  if ( (signed int)v31 <= 0 )
    goto LABEL_102;
  v65 = 0i64;
  v66 = (_DWORD *)(v247 + 4);
  v67 = (__int64)v15 - v247;
  while ( 1 )
  {
    v68 = &v36[v65];
    v69 = *(_DWORD *)&v36[v65 + 12] & 0x3FFFFFFF;
    if ( v69 >= 3 )
    {
      numIndices = 0;
LABEL_80:
      *((_DWORD *)v68 + 2) = 3;
      goto LABEL_81;
    }
    v70 = 2 * v69;
    v71 = 3;
    if ( v70 > 3 )
      v71 = v70;
    hkArrayUtil::_reserve(
      (hkResult *)&numIndices,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v68,
      v71,
      4);
    if ( !numIndices )
      goto LABEL_80;
LABEL_81:
    v72 = (__int64)&v218[v65];
    v73 = *(_DWORD *)&v218[v65 + 12] & 0x3FFFFFFF;
    if ( v73 >= 3 )
    {
      resulta.m_enum = 0;
LABEL_87:
      *(_DWORD *)(v72 + 8) = 3;
      v76 = resulta.m_enum;
      goto LABEL_88;
    }
    v74 = 2 * v73;
    v75 = 3;
    if ( v74 > 3 )
      v75 = v74;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v218[v65], v75, 8);
    v76 = resulta.m_enum;
    if ( resulta.m_enum == HK_SUCCESS )
      goto LABEL_87;
LABEL_88:
    if ( numIndices )
    {
      v105 = v244;
      *v244 = 1;
      v112 = (signed int)(v219 - 1);
      if ( (signed int)(v219 - 1) >= 0 )
      {
        v113 = &v218[16 * (v219 - 1) + 12];
        do
        {
          v114 = *(_DWORD *)v113;
          *((_DWORD *)v113 - 1) = 0;
          if ( v114 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v113 - 12),
              8 * v114);
          *(_QWORD *)(v113 - 12) = 0i64;
          *(_DWORD *)v113 = 2147483648;
          v113 -= 16;
          --v112;
        }
        while ( v112 >= 0 );
      }
      v219 = 0;
      if ( v220 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v218,
          16 * v220);
      v218 = 0i64;
      v220 = 2147483648;
      v115 = (signed int)v222 - 1;
      if ( (signed int)v222 - 1 >= 0 )
      {
        v116 = &array[16 * ((signed int)v222 - 1) + 12];
        do
        {
          v117 = *(_DWORD *)v116;
          *((_DWORD *)v116 - 1) = 0;
          if ( v117 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v116 - 12),
              4 * v117);
          *(_QWORD *)(v116 - 12) = 0i64;
          *(_DWORD *)v116 = 2147483648;
          v116 -= 16;
          --v115;
        }
        while ( v115 >= 0 );
      }
      goto LABEL_138;
    }
    if ( v76 )
    {
      v105 = v244;
      *v244 = 1;
      v106 = (signed int)(v219 - 1);
      if ( (signed int)(v219 - 1) >= 0 )
      {
        v107 = &v218[16 * (v219 - 1) + 12];
        do
        {
          v108 = *(_DWORD *)v107;
          *((_DWORD *)v107 - 1) = 0;
          if ( v108 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v107 - 12),
              8 * v108);
          *(_QWORD *)(v107 - 12) = 0i64;
          *(_DWORD *)v107 = 2147483648;
          v107 -= 16;
          --v106;
        }
        while ( v106 >= 0 );
      }
      v219 = 0;
      if ( v220 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v218,
          16 * v220);
      v218 = 0i64;
      v220 = 2147483648;
      v109 = (signed int)v222 - 1;
      if ( (signed int)v222 - 1 >= 0 )
      {
        v110 = &array[16 * ((signed int)v222 - 1) + 12];
        do
        {
          v111 = *(_DWORD *)v110;
          *((_DWORD *)v110 - 1) = 0;
          if ( v111 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v110 - 12),
              4 * v111);
          *(_QWORD *)(v110 - 12) = 0i64;
          *(_DWORD *)v110 = 2147483648;
          v110 -= 16;
          --v109;
        }
        while ( v109 >= 0 );
      }
LABEL_138:
      LODWORD(v222) = 0;
      if ( v222 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          16 * HIDWORD(v222));
      return (hkResult *)v105;
    }
    **(_DWORD **)&array[v65] = *(_DWORD *)((char *)v66 + v67 - 4);
    *(_DWORD *)(*(_QWORD *)&array[v65] + 4i64) = *(_DWORD *)((char *)v66 + v67);
    *(_DWORD *)(*(_QWORD *)&array[v65] + 8i64) = *(_DWORD *)((char *)v66 + v67 + 4);
    v77 = *(v66 - 1);
    v78 = v77 == -1 ? -1i64 : v77 % 3 | (unsigned __int64)((signed __int64)(v77 / 3) << 32);
    **(_QWORD **)&v218[v65] = v78;
    v79 = *v66 == -1 ? -1i64 : *v66 % 3 | (unsigned __int64)((signed __int64)(*v66 / 3) << 32);
    *(_QWORD *)(*(_QWORD *)&v218[v65] + 8i64) = v79;
    v80 = v66[1];
    v81 = v80 == -1 ? -1i64 : v80 % 3 | (unsigned __int64)((signed __int64)(v80 / 3) << 32);
    v64 += 3;
    v66 += 3;
    v82 = *(_QWORD *)&v218[v65];
    v65 += 16i64;
    *(_QWORD *)(v82 + 16) = v81;
    if ( v64 >= v31 )
      break;
    v36 = array;
  }
  v34 = v218;
  do
  {
LABEL_102:
    v83 = (_DWORD)v222 == 0;
    v84 = (signed int)v222 < 0;
    v85 = 0;
    v86 = 0i64;
    v222 = 0i64;
    LOBYTE(resulta.m_enum) = 0;
    numIndices = 0;
    if ( v84 || v83 )
      break;
    v87 = array;
    do
    {
      v88 = 16 * v86;
      v233 = 16 * v86;
      if ( v87[4 * v86 + 2] )
      {
        v89 = v218;
        v90 = 0i64;
        v224.m_enum = 0;
        v83 = *(_DWORD *)&v218[v88 + 8] == 0;
        v84 = *(_DWORD *)&v218[v88 + 8] < 0;
        v223 = 0i64;
        if ( !v84 && !v83 )
        {
          do
          {
            v91 = *(_QWORD *)&v89[v88];
            v240 = v91;
            v92 = *(_QWORD *)(v91 + 8 * v90);
            if ( v92 == -1i64 )
              goto LABEL_245;
            v93 = *(_DWORD *)((char *)v87 + v88 + 8);
            v94 = v92 >> 32;
            v95 = (signed int)v94;
            v234 = v94;
            v228 = 16i64 * (signed int)v94;
            v96 = *(_DWORD *)((char *)v87 + v228 + 8);
            if ( !v93 || !v96 || v93 + v96 - 2 >= *((_DWORD *)retaddr + 14) )
              goto LABEL_245;
            v235 = v85;
            v97 = 16i64 * v85;
            v98 = getNumSharedVertices(
                    (hkArrayBase<int> *)&v87[(unsigned __int64)v97 / 4],
                    (hkArrayBase<int> *)((char *)v87 + v228));
            v86 = v222;
            if ( v98 == 2 )
            {
              v87 = array;
              if ( *(_DWORD *)(v246 + 4 * v222) != *(_DWORD *)(v246 + 4 * v95) )
                goto LABEL_244;
              v99 = *(_QWORD *)&array[v88];
              v100 = *(signed int *)(v99 + 4 * v223);
              LODWORD(v229) = (v93 + v224.m_enum - 1) % v93;
              v101 = (v224.m_enum + 2) % v93;
              v102 = *(signed int *)(v91 + 8 * v223);
              v103 = v101;
              LODWORD(v226) = ((signed int)v102 + v96 - 1) % v96;
              LODWORD(v229) = ((signed int)v102 + 1) % v96;
              v104 = ((signed int)v102 + 2) % v96;
              switch ( v29 )
              {
                case 0u:
                  *(_QWORD *)&v118 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v100),
                                                          *(__m128 *)(v245 + 16 * v100),
                                                          233);
                  break;
                case 1u:
                  v119 = (__m128)xmmword_141A71320;
                  *(_QWORD *)&v118 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v245 + 16 * v100),
                                                            *(__m128 *)(v245 + 16 * v100),
                                                            136),
                                                          (__m128)xmmword_141A71320);
                  goto LABEL_148;
                case 2u:
                  v118 = *(_OWORD *)(v245 + 16 * v100);
                  break;
                case 3u:
                  *(_QWORD *)&v118 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v100),
                                                          *(__m128 *)(v245 + 16 * v100),
                                                          230);
                  break;
                case 4u:
                  v119 = (__m128)xmmword_141A71320;
                  *(_QWORD *)&v118 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v245 + 16 * v100),
                                                            *(__m128 *)(v245 + 16 * v100),
                                                            210),
                                                          (__m128)xmmword_141A71320);
                  goto LABEL_148;
                case 5u:
                  *(_QWORD *)&v118 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v100),
                                                          *(__m128 *)(v245 + 16 * v100),
                                                          225);
                  break;
                default:
                  *(_QWORD *)&v118 = 0i64;
                  break;
              }
              v119 = (__m128)xmmword_141A71320;
LABEL_148:
              v241 = v118;
              v120 = *(_QWORD *)&array[v228];
              v226 = v118;
              v121 = *(signed int *)(v120 + 4 * v102);
              switch ( v29 )
              {
                case 0u:
                  *(_QWORD *)&v122 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v121),
                                                          *(__m128 *)(v245 + 16 * v121),
                                                          233);
                  break;
                case 1u:
                  *(_QWORD *)&v122 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v245 + 16 * v121),
                                                            *(__m128 *)(v245 + 16 * v121),
                                                            136),
                                                          v119);
                  break;
                case 2u:
                  v122 = *(_OWORD *)(v245 + 16 * v121);
                  break;
                case 3u:
                  *(_QWORD *)&v122 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v121),
                                                          *(__m128 *)(v245 + 16 * v121),
                                                          230);
                  break;
                case 4u:
                  *(_QWORD *)&v122 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v245 + 16 * v121),
                                                            *(__m128 *)(v245 + 16 * v121),
                                                            210),
                                                          v119);
                  break;
                case 5u:
                  *(_QWORD *)&v122 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v121),
                                                          *(__m128 *)(v245 + 16 * v121),
                                                          225);
                  break;
                default:
                  *(_QWORD *)&v122 = 0i64;
                  break;
              }
              v123 = *(signed int *)(v99 + 4 * v103);
              v238 = v122;
              v230 = v122;
              switch ( v29 )
              {
                case 0u:
                  v124 = v245;
                  *(_QWORD *)&v125 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v123),
                                                          *(__m128 *)(v245 + 16 * v123),
                                                          233);
                  break;
                case 1u:
                  v124 = v245;
                  *(_QWORD *)&v125 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v245 + 16 * v123),
                                                            *(__m128 *)(v245 + 16 * v123),
                                                            136),
                                                          v119);
                  break;
                case 2u:
                  v124 = v245;
                  v125 = *(_OWORD *)(v245 + 16 * v123);
                  break;
                case 3u:
                  v124 = v245;
                  *(_QWORD *)&v125 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v123),
                                                          *(__m128 *)(v245 + 16 * v123),
                                                          230);
                  break;
                case 4u:
                  v124 = v245;
                  *(_QWORD *)&v125 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v245 + 16 * v123),
                                                            *(__m128 *)(v245 + 16 * v123),
                                                            210),
                                                          v119);
                  break;
                case 5u:
                  v124 = v245;
                  *(_QWORD *)&v125 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v245 + 16 * v123),
                                                          *(__m128 *)(v245 + 16 * v123),
                                                          225);
                  break;
                default:
                  v124 = v245;
                  *(_QWORD *)&v125 = 0i64;
                  break;
              }
              v126 = *(signed int *)(v120 + 4 * v104);
              v237 = v125;
              v232 = v125;
              switch ( v29 )
              {
                case 0u:
                  *(_QWORD *)&v127 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v126),
                                                          *(__m128 *)(v124 + 16 * v126),
                                                          233);
                  break;
                case 1u:
                  *(_QWORD *)&v127 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v124 + 16 * v126),
                                                            *(__m128 *)(v124 + 16 * v126),
                                                            136),
                                                          v119);
                  break;
                case 2u:
                  v127 = *(_OWORD *)(v124 + 16 * v126);
                  break;
                case 3u:
                  *(_QWORD *)&v127 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v126),
                                                          *(__m128 *)(v124 + 16 * v126),
                                                          230);
                  break;
                case 4u:
                  *(_QWORD *)&v127 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v124 + 16 * v126),
                                                            *(__m128 *)(v124 + 16 * v126),
                                                            210),
                                                          v119);
                  break;
                case 5u:
                  *(_QWORD *)&v127 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v126),
                                                          *(__m128 *)(v124 + 16 * v126),
                                                          225);
                  break;
                default:
                  *(_QWORD *)&v127 = 0i64;
                  break;
              }
              v239 = v127;
              v231 = v127;
              v128 = *(signed int *)(v99 + 4i64 * (signed int)v229);
              switch ( v29 )
              {
                case 0u:
                  *(_QWORD *)&v129 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v128),
                                                          *(__m128 *)(v124 + 16 * v128),
                                                          233);
                  break;
                case 1u:
                  *(_QWORD *)&v129 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v124 + 16 * v128),
                                                            *(__m128 *)(v124 + 16 * v128),
                                                            136),
                                                          v119);
                  break;
                case 2u:
                  v129 = *(_OWORD *)(v124 + 16 * v128);
                  break;
                case 3u:
                  *(_QWORD *)&v129 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v128),
                                                          *(__m128 *)(v124 + 16 * v128),
                                                          230);
                  break;
                case 4u:
                  *(_QWORD *)&v129 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v124 + 16 * v128),
                                                            *(__m128 *)(v124 + 16 * v128),
                                                            210),
                                                          v119);
                  break;
                case 5u:
                  *(_QWORD *)&v129 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v128),
                                                          *(__m128 *)(v124 + 16 * v128),
                                                          225);
                  break;
                default:
                  *(_QWORD *)&v129 = 0i64;
                  break;
              }
              v242 = v129;
              v229 = v129;
              v130 = *(signed int *)(v120 + 4i64 * (signed int)v226);
              switch ( v29 )
              {
                case 0u:
                  *(_QWORD *)&v131 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v130),
                                                          *(__m128 *)(v124 + 16 * v130),
                                                          233);
                  break;
                case 1u:
                  *(_QWORD *)&v131 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v124 + 16 * v130),
                                                            *(__m128 *)(v124 + 16 * v130),
                                                            136),
                                                          v119);
                  break;
                case 2u:
                  v131 = *(_OWORD *)(v124 + 16 * v130);
                  break;
                case 3u:
                  *(_QWORD *)&v131 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v130),
                                                          *(__m128 *)(v124 + 16 * v130),
                                                          230);
                  break;
                case 4u:
                  *(_QWORD *)&v131 = (unsigned __int128)_mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            *(__m128 *)(v124 + 16 * v130),
                                                            *(__m128 *)(v124 + 16 * v130),
                                                            210),
                                                          v119);
                  break;
                case 5u:
                  *(_QWORD *)&v131 = (unsigned __int128)_mm_shuffle_ps(
                                                          *(__m128 *)(v124 + 16 * v130),
                                                          *(__m128 *)(v124 + 16 * v130),
                                                          225);
                  break;
                default:
                  *(_QWORD *)&v131 = 0i64;
                  break;
              }
              v132 = *(float *)&v226;
              v133 = 1;
              v134 = 1;
              v135 = v226;
              v236 = v131;
              v136 = *((float *)&v226 + 1) - *((float *)&v229 + 1);
              v226 = v131;
              v137 = *((float *)&v229 + 1) - *((float *)&v135 + 1);
              v138 = *(float *)&v229 - v132;
              v139 = (float)((float)(*(float *)&v135 - *(float *)&v229)
                           * (float)(*((float *)&v231 + 1) - *((float *)&v229 + 1)))
                   - (float)(v136 * (float)(*(float *)&v231 - *(float *)&v229));
              v140 = (float)((float)(*(float *)&v230 - *(float *)&v131)
                           * (float)(*((float *)&v232 + 1) - *((float *)&v131 + 1)))
                   - (float)((float)(*(float *)&v232 - *(float *)&v131)
                           * (float)(*((float *)&v230 + 1) - *((float *)&v131 + 1)));
              if ( (float)((float)((float)(*((float *)&v229 + 1) - *((float *)&v135 + 1)) * *((float *)&v231 + 1))
                         + (float)((float)(*(float *)&v229 - v132) * *(float *)&v231)) <= (float)((float)((float)(*(float *)&v229 - v132) * v132)
                                                                                                + (float)((float)(*((float *)&v229 + 1) - *((float *)&v135 + 1)) * *((float *)&v131 + 1))) )
              {
                v141 = v139 >= 0.0;
              }
              else
              {
                v133 = 0;
                v141 = v139 > 0.0;
              }
              v142 = *(float *)&v131 - *(float *)&v230;
              v143 = *((float *)&v131 + 1) - *((float *)&v230 + 1);
              if ( (float)((float)(v143 * *((float *)&v232 + 1)) + (float)(v142 * *(float *)&v232)) <= (float)((float)(v142 * *(float *)&v230) + (float)(v143 * *((float *)&v230 + 1))) )
              {
                v144 = v140 >= 0.0;
              }
              else
              {
                v134 = 0;
                v144 = v140 > 0.0;
              }
              if ( 0.0 != retaddr[13] )
              {
                if ( !v141 )
                {
                  if ( v133 )
                  {
                    *(float *)&v229 = (float)(v137 * v137) + (float)(v138 * v138);
                    *(float *)&v226 = (float)((float)(*((float *)&v231 + 1) - *((float *)&v226 + 1))
                                            * (float)(*((float *)&v231 + 1) - *((float *)&v226 + 1)))
                                    + (float)((float)(*(float *)&v231 - v132) * (float)(*(float *)&v231 - v132));
                    if ( v243.m128_f32[0] > (float)((float)((float)((float)(*((float *)&v231 + 1) - *((float *)&v226 + 1))
                                                                  * v137)
                                                          + (float)((float)(*(float *)&v231 - v132) * v138))
                                                  / (float)(fsqrt(*(float *)&v226) * fsqrt(*(float *)&v229))) )
                      v141 = 1;
                  }
                }
                if ( !v144 )
                {
                  if ( v134 )
                  {
                    *(float *)&v229 = (float)(v143 * v143) + (float)(v142 * v142);
                    *(float *)&v226 = (float)((float)(*((float *)&v232 + 1) - *((float *)&v230 + 1))
                                            * (float)(*((float *)&v232 + 1) - *((float *)&v230 + 1)))
                                    + (float)((float)(*(float *)&v232 - *(float *)&v230)
                                            * (float)(*(float *)&v232 - *(float *)&v230));
                    if ( v243.m128_f32[0] > (float)((float)((float)((float)(*((float *)&v232 + 1) - *((float *)&v230 + 1))
                                                                  * v143)
                                                          + (float)((float)(*(float *)&v232 - *(float *)&v230) * v142))
                                                  / (float)(fsqrt(*(float *)&v226) * fsqrt(*(float *)&v229))) )
                      v144 = 1;
                  }
                }
              }
              if ( !v141 || !v144 )
              {
                v86 = v222;
                goto LABEL_244;
              }
              v145 = *(_QWORD *)&v218[v228];
              LOBYTE(resulta.m_enum) = 1;
              *(_QWORD *)(v240 + 8 * v223) = *(_QWORD *)(v145 + 8i64 * (signed int)v229);
              v146 = *(_DWORD *)&array[v88 + 12] & 0x3FFFFFFF;
              v147 = v96 + *(_DWORD *)&array[v88 + 8];
              if ( v146 >= v147 )
              {
                v225.m_enum = 0;
              }
              else
              {
                v148 = 2 * v146;
                if ( v147 < v148 )
                  v147 = v148;
                hkArrayUtil::_reserve(
                  &v225,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &array[v88],
                  v147,
                  4);
              }
              v149 = v218;
              v150 = *(_DWORD *)&v218[v88 + 12] & 0x3FFFFFFF;
              v151 = v96 + *(_DWORD *)&v218[v88 + 8];
              if ( v150 >= v151 )
              {
                v153 = 0;
                v224.m_enum = 0;
              }
              else
              {
                v152 = 2 * v150;
                if ( v151 < v152 )
                  v151 = v152;
                hkArrayUtil::_reserve(
                  &v224,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v218[v88],
                  v151,
                  8);
                v149 = v218;
                v153 = v224.m_enum;
              }
              if ( v225.m_enum )
              {
                v105 = v244;
                v84 = (signed int)(v219 - 1) < 0;
                v198 = v219 - 1;
                *v244 = 1;
                if ( !v84 )
                {
                  v199 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v149[16 * v198];
                  do
                  {
                    hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v199, 0);
                    --v199;
                    --v198;
                  }
                  while ( v198 >= 0 );
                  v149 = v218;
                }
                v219 = 0;
                if ( v220 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v149,
                    16 * v220);
                v218 = 0i64;
                v220 = 2147483648;
                v200 = v222 - 1;
                if ( (signed int)v222 - 1 >= 0 )
                {
                  v201 = (hkArray<int,hkContainerHeapAllocator> *)&array[16 * v200];
                  do
                  {
                    hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v201, 0);
                    --v201;
                    --v200;
                  }
                  while ( v200 >= 0 );
                }
LABEL_273:
                LODWORD(v222) = 0;
LABEL_274:
                v197 = HIDWORD(v222);
                if ( v222 >= 0 )
                {
                  v187 = array;
                  goto LABEL_320;
                }
                return (hkResult *)v105;
              }
              if ( v153 )
              {
                v105 = v244;
                v84 = (signed int)(v219 - 1) < 0;
                v193 = v219 - 1;
                *v244 = 1;
                if ( !v84 )
                {
                  v194 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v149[16 * v193];
                  do
                  {
                    hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v194, 0);
                    --v194;
                    --v193;
                  }
                  while ( v193 >= 0 );
                  v149 = v218;
                }
                v219 = 0;
                if ( v220 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    v149,
                    16 * v220);
                v218 = 0i64;
                v220 = 2147483648;
                v195 = v222 - 1;
                if ( (signed int)v222 - 1 >= 0 )
                {
                  v196 = (hkArray<int,hkContainerHeapAllocator> *)&array[16 * v195];
                  do
                  {
                    hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v196, 0);
                    --v196;
                    --v195;
                  }
                  while ( v195 >= 0 );
                }
                goto LABEL_273;
              }
              if ( (_DWORD)v104 != (_DWORD)v102 )
              {
                v154 = 2 * v95;
                v155 = v224.m_enum + 1;
                do
                {
                  hkArrayBase<int>::_insertAt(
                    (hkArrayBase<int> *)&array[v97],
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    v155,
                    (const int *)(*(_QWORD *)&array[8 * v154] + 4i64 * (signed int)v104));
                  hkArrayBase<hkClass *>::_insertAt(
                    (hkArrayBase<hkClass *> *)&v218[v97],
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    v155++,
                    (hkClass *const *)(*(_QWORD *)&v218[8 * v154] + 8i64 * (signed int)v104));
                  LODWORD(v104) = ((signed int)v104 + 1) % v96;
                }
                while ( (_DWORD)v104 != (_DWORD)v102 );
                v149 = v218;
                v88 = v233;
                v29 = v223;
              }
              v156 = *(_DWORD *)&v149[v88 + 8] - 1;
              v157 = v156;
              if ( v156 >= 0 )
              {
                v158 = v234;
                v159 = numIndices;
                do
                {
                  v160 = *(_QWORD *)&v149[v88];
                  v161 = *(_QWORD *)(v160 + 8 * v157) >> 32;
                  if ( (_DWORD)v161 == v158 || (_DWORD)v161 == v159 )
                  {
                    --*(_DWORD *)&v149[v88 + 8];
                    v162 = v160 + 8 * v157;
                    v163 = 8 * (*(_DWORD *)&v149[v88 + 8] - v156);
                    if ( v163 > 0 )
                    {
                      v164 = ((unsigned int)(v163 - 1) >> 3) + 1;
                      do
                      {
                        v165 = *(_QWORD *)(v162 + 8);
                        v162 += 8i64;
                        *(_QWORD *)(v162 - 8) = v165;
                        --v164;
                      }
                      while ( v164 );
                    }
                    v166 = array;
                    --*(_DWORD *)&v166[v88 + 8];
                    v167 = *(_QWORD *)&v166[v88] + 4 * v157;
                    v168 = 4 * (*(_DWORD *)&v166[v88 + 8] - v156);
                    if ( v168 > 0 )
                    {
                      v169 = ((unsigned int)(v168 - 1) >> 2) + 1;
                      do
                      {
                        v170 = *(_DWORD *)(v167 + 4);
                        v167 += 4i64;
                        *(_DWORD *)(v167 - 4) = v170;
                        --v169;
                      }
                      while ( v169 );
                    }
                    v149 = v218;
                  }
                  --v156;
                  --v157;
                }
                while ( v157 >= 0 );
              }
              if ( *(_DWORD *)&array[v88 + 8] == 2 )
              {
                *(_DWORD *)&array[v88 + 8] = 0;
                *(_DWORD *)&v218[v88 + 8] = 0;
                v149 = v218;
              }
              v171 = 0;
              if ( *(_DWORD *)&v149[v88 + 8] > 0 )
              {
                v172 = v235;
                v173 = 0i64;
                do
                {
                  v174 = *(_QWORD *)(v173 + *(_QWORD *)&v149[v88]);
                  if ( v174 != -1 )
                  {
                    *(_QWORD *)(*(_QWORD *)&v149[16 * SHIDWORD(v174)] + 8i64 * (signed int)v174) = v171 | (unsigned __int64)(v172 << 32);
                    v149 = v218;
                  }
                  ++v171;
                  v173 += 8i64;
                }
                while ( v171 < *(_DWORD *)&v149[v88 + 8] );
              }
              v175 = v228;
              v86 = v222;
              *(_DWORD *)&array[v228 + 8] = 0;
              *(_DWORD *)&v218[v175 + 8] = 0;
            }
            v87 = array;
LABEL_244:
            v85 = numIndices;
LABEL_245:
            ++v223;
            v89 = v218;
            v90 = v223;
            ++v224.m_enum;
          }
          while ( v224.m_enum < *(_DWORD *)&v218[v88 + 8] );
        }
        v34 = v218;
      }
      ++v85;
      ++v86;
      numIndices = v85;
      v222 = v86;
    }
    while ( v85 < (signed int)v86 );
  }
  while ( LOBYTE(resulta.m_enum) );
  v176 = v222;
  v177 = (int *)v253;
  v178 = 2147483648;
  v179 = v250;
  v180 = 0i64;
  v227 = 0i64;
  v228 = 0x8000000000000000i64;
  if ( (signed int)v222 > 0 )
  {
    v181 = v222;
    if ( (signed int)v222 < 0 )
      v181 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v227, v181, 4);
    if ( resulta.m_enum )
    {
      v105 = v244;
      v202 = HIDWORD(v228);
      *v244 = 1;
      LODWORD(v228) = 0;
      if ( v202 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v227,
          4 * v202);
      v227 = 0i64;
      HIDWORD(v228) = 2147483648;
      v203 = v219 - 1;
      if ( (signed int)(v219 - 1) >= 0 )
      {
        v204 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v218[16 * v203];
        do
        {
          hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v204, 0);
          --v204;
          --v203;
        }
        while ( v203 >= 0 );
      }
      v219 = 0;
      if ( v220 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v218,
          16 * v220);
      v218 = 0i64;
      v220 = 2147483648;
      v205 = v222 - 1;
      if ( (signed int)v222 - 1 >= 0 )
      {
        v206 = (hkArray<int,hkContainerHeapAllocator> *)&array[16 * v205];
        do
        {
          hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v206, 0);
          --v206;
          --v205;
        }
        while ( v205 >= 0 );
      }
      LODWORD(v222) = 0;
      goto LABEL_274;
    }
    v178 = HIDWORD(v228);
    v180 = v227;
    v34 = v218;
  }
  LODWORD(v228) = v176;
  v182 = 0;
  if ( (signed int)v222 <= 0 )
  {
    v187 = array;
  }
  else
  {
    v183 = v251;
    v184 = 0i64;
    v185 = 0i64;
    v186 = v246;
    do
    {
      v180[v184] = v179 - v250;
      v187 = array;
      v188 = *(signed int *)&array[v185 + 8];
      if ( (_DWORD)v188 )
      {
        v189 = *(hkResultEnum **)&array[v185];
        v190 = v179;
        if ( (signed int)v188 > 0 )
        {
          v191 = (unsigned int)v188;
          do
          {
            v192 = *v189;
            ++v190;
            ++v189;
            v190[-1].m_enum = v192;
            --v191;
          }
          while ( v191 );
          v187 = array;
        }
        *v177 = v188;
        ++v177;
        v183->m_quad.m128_i32[0] = *(_DWORD *)(v184 * 4 + v186);
        v183 = (hkVector4f *)((char *)v183 + 4);
        v179 += v188;
      }
      v180 = v227;
      ++v182;
      v185 += 16i64;
      ++v184;
    }
    while ( v182 < (signed int)v222 );
    v178 = HIDWORD(v228);
    v34 = v218;
  }
  v207 = v219;
  v208 = v252;
  if ( (signed int)v219 > 0 )
  {
    v209 = v34 + 2;
    v210 = v219;
    do
    {
      v211 = 0;
      if ( *v209 > 0 )
      {
        v212 = 0i64;
        do
        {
          v213 = *(_QWORD *)(v212 + *((_QWORD *)v209 - 1));
          if ( v213 == -1 )
            *v208 = -1;
          else
            *v208 = v213 + v180[SHIDWORD(v213)];
          ++v211;
          ++v208;
          v212 += 8i64;
        }
        while ( v211 < *v209 );
      }
      v209 += 4;
      --v210;
    }
    while ( v210 );
  }
  LODWORD(v228) = 0;
  *oppEdges = v177 - v253;
  v105 = v244;
  *v244 = 0;
  if ( v178 >= 0 )
  {
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v180,
      (unsigned int)(4 * v178),
      v34);
    v207 = v219;
    v187 = array;
    v34 = v218;
  }
  v214 = v207 - 1;
  v227 = 0i64;
  HIDWORD(v228) = 2147483648;
  if ( (signed int)(v207 - 1) >= 0 )
  {
    v215 = (hkArray<unsigned __int64,hkContainerHeapAllocator> *)&v34[4 * v214];
    do
    {
      hkArray<unsigned __int64,hkContainerHeapAllocator>::`scalar deleting destructor(v215, 0);
      --v215;
      --v214;
    }
    while ( v214 >= 0 );
    v187 = array;
    v34 = v218;
  }
  v219 = 0;
  if ( v220 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v34,
      16 * v220);
    v187 = array;
  }
  v218 = 0i64;
  v220 = 2147483648;
  v216 = v222 - 1;
  if ( (signed int)v222 - 1 >= 0 )
  {
    v217 = (hkArray<int,hkContainerHeapAllocator> *)&v187[16 * v216];
    do
    {
      hkArray<int,hkContainerHeapAllocator>::`scalar deleting destructor(v217, 0);
      --v217;
      --v216;
    }
    while ( v216 >= 0 );
    v187 = array;
  }
  v197 = HIDWORD(v222);
  LODWORD(v222) = 0;
  if ( v222 >= 0 )
LABEL_320:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v187,
      16 * v197);
  return (hkResult *)v105;
}LODWORD(v228) = 0;
  *oppEdges = v177 - v253;
  v105 = v244;
  *v244 = 0;
  if ( v178 >= 0 )
  {
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, _DWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v180,
      (unsigned int)(4 * v178),
      v34);
    v207 = v219;
    v187 = array;
    v34 = v218;
  }
  v214 = v207 - 1;
  v227 = 0i64;
  HIDWORD(v228) = 21474

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
hkResult *__fastcall hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn, hkArray<int,hkContainerHeapAllocator> *tris, hkArray<int,hkContainerHeapAllocator> *trisPerFace, hkArray<int,hkContainerHeapAllocator> *triConnectivity, hkArrayBase<int> *perTriangleData, hkaiNavMeshGenerationSettings *input)
{
  __m128 *v7; // r13
  hkResult *v8; // r12
  int v9; // ecx
  hkArray<int,hkContainerHeapAllocator> *v10; // rsi
  int v11; // er15
  int v12; // ebx
  __int32 v13; // eax
  _DWORD *v14; // rdi
  signed int v15; // er8
  int v16; // er9
  __int64 i; // rcx
  int v18; // er8
  float v19; // xmm9_4
  float v20; // xmm11_4
  char v21; // r11
  signed __int64 v22; // r10
  signed __int64 v23; // rdx
  __int64 v24; // rcx
  signed __int64 v25; // r9
  hkVector4f *v26; // rax
  signed __int64 v27; // rdx
  signed __int64 v28; // r9
  __m128 *v29; // rcx
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
  _DWORD *array; // [rsp+30h] [rbp-71h]
  int v53; // [rsp+38h] [rbp-69h]
  int v54; // [rsp+3Ch] [rbp-65h]
  int v55; // [rsp+40h] [rbp-61h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v56; // [rsp+F8h] [rbp+57h]
  hkResult resulta; // [rsp+100h] [rbp+5Fh]
  hkArray<int,hkContainerHeapAllocator> *trisPerFaceInOut; // [rsp+108h] [rbp+67h]

  trisPerFaceInOut = trisPerFace;
  v56 = vertsIn;
  v7 = (__m128 *)input;
  v8 = result;
  v9 = tris->m_size;
  v10 = tris;
  LOBYTE(input) = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  if ( v9 )
  {
    array = 0i64;
    v53 = 0;
    v54 = 2147483648;
    v11 = v9 / 3;
    v12 = (v9 / 3 + 31) >> 5;
    v13 = v12;
    if ( v12 )
    {
      resulta.m_enum = 4 * v12;
      v14 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                        (int *)&resulta);
      v13 = resulta.m_enum / 4;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = 2147483648;
    v55 = v11;
    if ( v13 )
      v15 = v13;
    array = v14;
    v53 = v12;
    v54 = v15;
    if ( (v15 & 0x3FFFFFFF) < v12 )
    {
      v16 = v12;
      if ( v12 < 2 * (v15 & 0x3FFFFFFF) )
        v16 = 2 * (v15 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v16, 4);
      v15 = v54;
      v14 = array;
    }
    v53 = v12;
    if ( v14 )
    {
      if ( v12 - 1 >= 0 )
      {
        for ( i = (unsigned int)v12; i; --i )
        {
          *v14 = 0;
          ++v14;
        }
        v14 = array;
      }
      v18 = 0;
      LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps((__m128)v7[3].m128_u32[0], (__m128)v7[3].m128_u32[0], 0);
      LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps((__m128)v7[2].m128_u32[3], (__m128)v7[2].m128_u32[3], 0);
      if ( v10->m_size > 0 )
      {
        v21 = (char)input;
        v22 = 2i64;
        do
        {
          v23 = v10->m_data[v22 - 1];
          v24 = v10->m_data[v22 - 2];
          if ( (_DWORD)v23 == (_DWORD)v24 )
            goto LABEL_39;
          v25 = v10->m_data[v22];
          if ( (_DWORD)v25 == (_DWORD)v24 )
            goto LABEL_39;
          if ( (_DWORD)v25 == (_DWORD)v23 )
            goto LABEL_39;
          v26 = v56->m_data;
          v27 = v23;
          v28 = v25;
          v29 = &v56->m_data[v24].m_quad;
          if ( v20 != 0.0 )
          {
            v30 = _mm_sub_ps(v26[v27].m_quad, *v29);
            v31 = _mm_sub_ps(v26[v28].m_quad, *v29);
            v32 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30),
                    _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v31));
            v33 = _mm_shuffle_ps(v32, v32, 201);
            v34 = _mm_mul_ps(v33, v33);
            v35 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                    _mm_shuffle_ps(v34, v34, 170));
            v36 = _mm_rsqrt_ps(v35);
            if ( COERCE_FLOAT(2
                            * (unsigned int)*(_OWORD *)&_mm_andnot_ps(
                                                          _mm_cmpleps(v35, (__m128)0i64),
                                                          _mm_mul_ps(
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                (__m128)_xmm,
                                                                _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                                                              _mm_mul_ps(*(__m128 *)_xmm, v36)),
                                                            v35)) >> 1) < v20 )
              goto LABEL_39;
          }
          v37 = _mm_sub_ps(v26[v28].m_quad, *v29);
          v38 = _mm_sub_ps(v26[v27].m_quad, *v29);
          v39 = _mm_sub_ps(v26[v27].m_quad, v26[v28].m_quad);
          v40 = _mm_mul_ps(v39, v39);
          v41 = _mm_mul_ps(v38, v38);
          v42 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v38),
                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v37));
          v43 = _mm_shuffle_ps(v42, v42, 201);
          v44 = _mm_mul_ps(v43, v43);
          v45 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170));
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
          LODWORD(v48) = (unsigned __int128)_mm_rcp_ps(v47);
          if ( v19 != 0.0
            && (float)((float)((float)(2.0 - (float)(v48 * v47.m128_f32[0])) * v48) * v45) < (float)(v19 * v19) )
          {
            goto LABEL_39;
          }
          if ( !v21 )
          {
            v49 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v38),
                    _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v37));
            v50 = _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v7[1]);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170))) < 0.0 )
            {
LABEL_39:
              v14[(signed __int64)(v18 / 3) >> 5] |= 1 << (v18 / 3 & 0x1F);
              v14 = array;
            }
          }
          v18 += 3;
          v22 += 3i64;
        }
        while ( v18 < v10->m_size );
      }
      hkaiNavMeshGenerationUtils::_removeTriangles(
        (hkBitField *)&array,
        v10,
        triConnectivity,
        trisPerFaceInOut,
        perTriangleData,
        0i64);
      v53 = 0;
      if ( v54 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v54);
      v8->m_enum = 0;
    }
    else
    {
      v8->m_enum = 1;
      v53 = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          0i64,
          4 * v15);
    }
  }
  else
  {
    v8->m_enum = 0;
  }
  return v8;
}

// File Line: 1328
// RVA: 0xB829C0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_createNavMesh(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn, hkArray<int,hkContainerHeapAllocator> *tris, hkArray<int,hkContainerHeapAllocator> *trisPerFace, hkArray<int,hkContainerHeapAllocator> *triConnectivity, hkArray<int,hkContainerHeapAllocator> *triangleMaterials, hkaiCarverTree *carverTree, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *navMeshOut)
{
  hkResult *v9; // rbx

  v9 = result;
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
  return v9;
}

// File Line: 1333
// RVA: 0xB82A30
hkResult *__fastcall hkaiNavMeshGenerationUtils::_createNavMesh(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn, hkArray<int,hkContainerHeapAllocator> *tris, hkArray<int,hkContainerHeapAllocator> *trisPerFace, hkArray<int,hkContainerHeapAllocator> *triConnectivity, hkArray<int,hkContainerHeapAllocator> *originalFaceIndices, hkGeometry *triMeshIn, hkaiCarverTree *carverTree, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *navMeshOut)
{
  hkResult *v10; // rbx

  v10 = result;
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
  return v10;
}

// File Line: 1338
// RVA: 0xB82AA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_createNavMeshImpl(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn, hkArray<int,hkContainerHeapAllocator> *tris, hkArray<int,hkContainerHeapAllocator> *trisPerFace, hkArray<int,hkContainerHeapAllocator> *triConnectivity, hkArray<int,hkContainerHeapAllocator> *allTriangleMaterials, hkArray<int,hkContainerHeapAllocator> *originalFaceIndices, hkGeometry *triMeshIn, hkaiCarverTree *carverTree, hkaiNavMeshGenerationSettings *settings, hkaiNavMesh *navMeshOut)
{
  int v11; // edi
  hkArray<int,hkContainerHeapAllocator> *v12; // r13
  hkArray<int,hkContainerHeapAllocator> *v13; // r15
  hkResult *v14; // r14
  int v16; // esi
  int v17; // er9
  int v18; // er8
  int v19; // er14
  __int64 v20; // r11
  int v21; // er9
  int v22; // er10
  int v23; // er8
  int v24; // edi
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // edx
  unsigned int v29; // eax
  int v30; // edx
  SortedTriangle *v31; // rax
  int v32; // edi
  int v33; // er14
  int v34; // ecx
  int v35; // er12
  unsigned int *v36; // rax
  unsigned int *v37; // r8
  signed int v38; // eax
  int v39; // edi
  int v40; // ecx
  int v41; // er9
  hkResult *v42; // rdi
  __int64 v43; // rcx
  unsigned int *v44; // rdi
  int v45; // er9
  __int64 v46; // rdi
  signed __int64 v47; // rdx
  hkArray<int,hkContainerHeapAllocator> *v48; // r14
  int v49; // edi
  int v50; // er9
  int v51; // er8
  int *v52; // rdx
  int *v53; // rsi
  int *v54; // r15
  int v55; // er12
  __int64 v56; // r14
  int v57; // edi
  int *v58; // rdx
  __int64 v59; // rax
  int v60; // ecx
  unsigned __int64 v61; // rcx
  hkaiNavMesh *v62; // rsi
  int *v63; // rdi
  hkResultEnum v64; // ecx
  SortedTriangle *v65; // r12
  int *v66; // rdx
  signed int *v67; // r14
  __m128 v68; // xmm0
  __m128 v69; // xmm2
  __m128 v70; // xmm1
  __m128 v71; // xmm1
  int v72; // edi
  __m128 v73; // xmm5
  __m128 v74; // xmm5
  __m128 v75; // xmm1
  __m128 v76; // xmm2
  __m128 v77; // xmm3
  int v78; // er9
  int v79; // edi
  int v80; // er9
  int v81; // edi
  int v82; // er9
  int v83; // edi
  int v84; // er9
  _DWORD *v85; // rdi
  int v86; // er9
  hkResultEnum v87; // eax
  int *v88; // rax
  __int64 v89; // r8
  int v90; // er15
  __m128 v91; // xmm0
  int v92; // er8
  int v93; // eax
  int v94; // ecx
  hkResult *v95; // rax
  int v96; // er14
  int *v97; // r15
  int *v98; // r12
  __int64 v99; // rdi
  hkaiNavMesh::Face *v100; // rax
  __int64 v101; // rcx
  signed __int64 v102; // r14
  __int64 v103; // r8
  __int64 v104; // r13
  int v105; // eax
  hkaiNavMesh::Edge *v106; // rdi
  __int64 v107; // r9
  __int64 v108; // r8
  signed __int64 v109; // r10
  __int64 v110; // r11
  signed __int64 v111; // rdx
  __int64 v112; // r14
  __int64 v113; // rax
  int v114; // eax
  signed __int64 v115; // rcx
  int v116; // edx
  signed __int64 v117; // rcx
  int v118; // er11
  __int64 v119; // r8
  hkaiNavMesh::Face *v120; // r10
  signed __int64 v121; // rdx
  signed __int64 v122; // rdi
  hkaiNavMesh::Edge *v123; // r9
  __int64 v124; // rax
  int *numIndicesPerPiece; // [rsp+70h] [rbp-90h]
  int v126; // [rsp+78h] [rbp-88h]
  int v127; // [rsp+7Ch] [rbp-84h]
  int *oppConvexEdges; // [rsp+80h] [rbp-80h]
  int v129; // [rsp+88h] [rbp-78h]
  int v130; // [rsp+8Ch] [rbp-74h]
  int *convexMaterials; // [rsp+90h] [rbp-70h]
  int v132; // [rsp+98h] [rbp-68h]
  int v133; // [rsp+9Ch] [rbp-64h]
  int *convexIndices; // [rsp+A0h] [rbp-60h]
  int v135; // [rsp+A8h] [rbp-58h]
  int v136; // [rsp+ACh] [rbp-54h]
  int *materials; // [rsp+B0h] [rbp-50h]
  int v138; // [rsp+B8h] [rbp-48h]
  int v139; // [rsp+BCh] [rbp-44h]
  int *oppositeEdgesOut; // [rsp+C0h] [rbp-40h]
  int v141; // [rsp+C8h] [rbp-38h]
  int v142; // [rsp+CCh] [rbp-34h]
  int v143; // [rsp+D0h] [rbp-30h]
  hkResult resulta; // [rsp+D4h] [rbp-2Ch]
  SortedTriangle *array; // [rsp+D8h] [rbp-28h]
  int v146; // [rsp+E0h] [rbp-20h]
  int v147; // [rsp+E4h] [rbp-1Ch]
  hkResult v148; // [rsp+E8h] [rbp-18h]
  hkResult v149; // [rsp+ECh] [rbp-14h]
  int *triangleIndices; // [rsp+F0h] [rbp-10h]
  hkResult v151; // [rsp+F8h] [rbp-8h]
  hkBitField trisToRemove; // [rsp+100h] [rbp+0h]
  hkResult v153; // [rsp+120h] [rbp+20h]
  int n; // [rsp+124h] [rbp+24h]
  int v155; // [rsp+128h] [rbp+28h]
  hkResult v156; // [rsp+12Ch] [rbp+2Ch]
  hkResult resultOut; // [rsp+130h] [rbp+30h]
  __int64 v158; // [rsp+138h] [rbp+38h]
  int *oppEdges; // [rsp+140h] [rbp+40h]
  int estimatedMaxNumEdges; // [rsp+148h] [rbp+48h]
  int estimatedMaxNumFaces; // [rsp+14Ch] [rbp+4Ch]
  int v162; // [rsp+150h] [rbp+50h]
  __int64 v163; // [rsp+158h] [rbp+58h]
  __int64 v164; // [rsp+160h] [rbp+60h]
  hkResult v165; // [rsp+168h] [rbp+68h]
  hkResult v166; // [rsp+16Ch] [rbp+6Ch]
  hkVector4f v167; // [rsp+170h] [rbp+70h]
  hkResult *v168; // [rsp+1E0h] [rbp+E0h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *a; // [rsp+1E8h] [rbp+E8h]
  hkArray<int,hkContainerHeapAllocator> *v170; // [rsp+1F0h] [rbp+F0h]
  hkArray<int,hkContainerHeapAllocator> *v171; // [rsp+1F8h] [rbp+F8h]

  v171 = trisPerFace;
  v170 = tris;
  a = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)vertsIn;
  v168 = result;
  v11 = tris->m_size;
  v12 = trisPerFace;
  v13 = tris;
  v14 = result;
  if ( !v11 )
  {
    result->m_enum = 0;
    return result;
  }
  array = 0i64;
  v146 = 0;
  v147 = 2147483648;
  v16 = v11 / 3;
  if ( v11 / 3 > 0 )
  {
    v17 = v11 / 3;
    if ( v16 < 0 )
      v17 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v17, 16);
    if ( resulta.m_enum )
    {
      v18 = v147;
      v14->m_enum = 1;
      v146 = 0;
      if ( v18 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          16 * v18);
      return v14;
    }
  }
  v146 = v11 / 3;
  v19 = 0;
  if ( v13->m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      v20 += 3i64;
      v21 = v13->m_data[v20 - 1];
      v22 = v13->m_data[v20 - 3];
      v23 = v13->m_data[v20 - 2];
      v24 = v13->m_data[v20 - 1];
      v25 = v13->m_data[v20 - 1];
      v26 = v13->m_data[v20 - 2];
      if ( v22 < v23 )
        v26 = v13->m_data[v20 - 3];
      if ( v26 < v21 )
        v24 = v26;
      v27 = v13->m_data[v20 - 2];
      if ( v22 > v23 )
        v27 = v13->m_data[v20 - 3];
      if ( v27 > v21 )
        v25 = v27;
      v28 = (unsigned __int64)(1431655766i64 * v19) >> 32;
      v29 = (unsigned __int64)(1431655766i64 * v19) >> 32;
      v19 += 3;
      v30 = (v29 >> 31) + v28;
      v31 = &array[v30];
      v31->i[0] = v24;
      v31->i[1] = v22 + v23 + v21 - v25 - v24;
      v31->i[2] = v25;
      v31->index = v30;
    }
    while ( v19 < v13->m_size );
    v16 = v146;
  }
  if ( v16 > 1 )
  {
    hkAlgorithm::quickSortRecursive<SortedTriangle,hkAlgorithm::less<SortedTriangle>>(array, 0, v16 - 1, 0);
    v16 = v146;
  }
  v32 = v16 + 31;
  v33 = v16;
  trisToRemove.m_storage.m_words.m_data = 0i64;
  trisToRemove.m_storage.m_words.m_size = 0;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v34 = (v16 + 31) >> 5;
  v35 = v34;
  if ( v34 )
  {
    v143 = 4 * v34;
    v36 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            &v143);
    v16 = v146;
    v37 = v36;
    v34 = v143 / 4;
  }
  else
  {
    v37 = 0i64;
  }
  v38 = 2147483648;
  trisToRemove.m_storage.m_words.m_data = v37;
  if ( v34 )
    v38 = v34;
  v39 = v32 >> 5;
  trisToRemove.m_storage.m_words.m_size = v35;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = v38;
  trisToRemove.m_storage.m_numBits = v33;
  v40 = v38 & 0x3FFFFFFF;
  if ( (v38 & 0x3FFFFFFF) < v39 )
  {
    v41 = v39;
    if ( v39 < 2 * v40 )
      v41 = 2 * v40;
    hkArrayUtil::_reserve(&v148, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &trisToRemove, v41, 4);
    v16 = v146;
    v38 = trisToRemove.m_storage.m_words.m_capacityAndFlags;
    v37 = trisToRemove.m_storage.m_words.m_data;
  }
  trisToRemove.m_storage.m_words.m_size = v39;
  if ( !v37 )
  {
    v42 = v168;
    trisToRemove.m_storage.m_words.m_size = 0;
    v168->m_enum = 1;
    if ( v38 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * v38);
    trisToRemove.m_storage.m_words.m_data = 0i64;
    trisToRemove.m_storage.m_words.m_capacityAndFlags = 2147483648;
    v146 = 0;
    if ( v147 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        16 * v147);
    return v42;
  }
  if ( v39 - 1 >= 0 )
  {
    v43 = (unsigned int)v39;
    v44 = v37;
    while ( v43 )
    {
      *v44 = 0;
      ++v44;
      --v43;
    }
    v16 = v146;
    v37 = trisToRemove.m_storage.m_words.m_data;
  }
  v45 = 0;
  if ( v16 - 1 > 0 )
  {
    v46 = 0i64;
    do
    {
      if ( array[v46].i[0] == array[v46 + 1].i[0]
        && array[v46].i[1] == array[v46 + 1].i[1]
        && array[v46].i[2] == array[v46 + 1].i[2] )
      {
        v47 = (signed __int64)array[v46].index >> 5;
        v37[v47] |= 1 << (array[v46].index & 0x1F);
        v16 = v146;
        v37 = trisToRemove.m_storage.m_words.m_data;
      }
      ++v45;
      ++v46;
    }
    while ( v45 < v16 - 1 );
  }
  v48 = triConnectivity;
  hkaiNavMeshGenerationUtils::_removeTriangles(
    &trisToRemove,
    v13,
    triConnectivity,
    v12,
    (hkArrayBase<int> *)&allTriangleMaterials->m_data,
    0i64);
  trisToRemove.m_storage.m_words.m_size = 0;
  if ( trisToRemove.m_storage.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      trisToRemove.m_storage.m_words.m_data,
      4 * trisToRemove.m_storage.m_words.m_capacityAndFlags);
  trisToRemove.m_storage.m_words.m_data = 0i64;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v146 = 0;
  if ( v147 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      16 * v147);
  v49 = v13->m_size;
  oppositeEdgesOut = 0i64;
  v141 = 0;
  v142 = 2147483648;
  estimatedMaxNumEdges = v49;
  estimatedMaxNumFaces = v49 / 3;
  if ( v49 > 0 )
  {
    v50 = v49;
    if ( v49 < 0 )
      v50 = 0;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &oppositeEdgesOut,
      v50,
      4);
    if ( resulta.m_enum )
    {
      v42 = v168;
      v51 = v142;
      v141 = 0;
      v168->m_enum = 1;
      if ( v51 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          oppositeEdgesOut,
          4 * v51);
      return v42;
    }
  }
  v52 = v13->m_data;
  v53 = oppositeEdgesOut;
  v54 = v48->m_data;
  triangleIndices = v52;
  v141 = v49;
  v55 = 0;
  if ( v12->m_size > 0 )
  {
    v56 = 0i64;
    do
    {
      hkaiNavMeshGenerationUtils::_findSharedEdges(&v148, v52, 3 * v12->m_data[v56], v53);
      v57 = 0;
      if ( 3 * v12->m_data[v56] > 0 )
      {
        v58 = v53;
        do
        {
          if ( *(int *)((char *)v58 + (char *)v54 - (char *)v53) == 1 )
          {
            v59 = *v58;
            *v58 = -1;
            if ( (_DWORD)v59 != -1 )
              v53[v59] = -1;
          }
          ++v57;
          ++v58;
        }
        while ( v57 < 3 * v12->m_data[v56] );
      }
      ++v55;
      v60 = v12->m_data[v56];
      ++v56;
      v61 = 12i64 * v60;
      v52 = &triangleIndices[v61 / 4];
      v53 = (int *)((char *)v53 + v61);
      v54 = (int *)((char *)v54 + v61);
      triangleIndices = (int *)((char *)triangleIndices + v61);
    }
    while ( v55 < v12->m_size );
  }
  v62 = navMeshOut;
  oppEdges = oppositeEdgesOut;
  v143 = 0;
  v63 = v170->m_data;
  convexIndices = 0i64;
  v135 = 0;
  v136 = 2147483648;
  materials = 0i64;
  v138 = 0;
  triangleIndices = v63;
  v139 = 2147483648;
  convexMaterials = 0i64;
  v132 = 0;
  v133 = 2147483648;
  oppConvexEdges = 0i64;
  v129 = 0;
  v130 = 2147483648;
  numIndicesPerPiece = 0i64;
  v126 = 0;
  v127 = 2147483648;
  v64 = 0;
  resulta.m_enum = 0;
  if ( v12->m_size <= 0 )
  {
LABEL_141:
    v118 = 0;
    if ( v62->m_faces.m_size > 0 )
    {
      v119 = 0i64;
      do
      {
        v120 = v62->m_faces.m_data;
        v121 = v120[v119].m_startEdgeIndex;
        if ( (signed int)v121 < (signed int)v121 + v120[v119].m_numEdges )
        {
          v122 = v121;
          do
          {
            v123 = v62->m_edges.m_data;
            v124 = (signed int)v123[v122].m_oppositeEdge;
            if ( (_DWORD)v124 != -1 )
              v123[v124].m_oppositeFace = v118;
            LODWORD(v121) = v121 + 1;
            ++v122;
          }
          while ( (signed int)v121 < v120[v119].m_startEdgeIndex + v120[v119].m_numEdges );
        }
        ++v118;
        ++v119;
      }
      while ( v118 < v62->m_faces.m_size );
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v62->m_vertices,
      a);
    v42 = v168;
    v168->m_enum = 0;
    goto LABEL_150;
  }
  v65 = 0i64;
  array = 0i64;
  while ( 1 )
  {
    v66 = v12->m_data;
    if ( !*(int *)((char *)v65->i + (unsigned __int64)v12->m_data) )
      goto LABEL_140;
    v67 = v63 + 2;
    v68 = (__m128)a->m_data[*v63];
    v69 = _mm_sub_ps((__m128)a->m_data[v63[1]], v68);
    v70 = (__m128)a->m_data[v63[2]];
    v135 = 0;
    v138 = 0;
    v132 = 0;
    v129 = 0;
    v126 = 0;
    v71 = _mm_sub_ps(v70, v68);
    v72 = 3 * *(int *)((char *)v66 + (_QWORD)v65);
    v73 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v69), _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v71));
    v74 = _mm_shuffle_ps(v73, v73, 201);
    v75 = _mm_mul_ps(v74, v74);
    v76 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
            _mm_shuffle_ps(v75, v75, 170));
    v77 = _mm_rsqrt_ps(v76);
    v167.m_quad = _mm_mul_ps(
                    v74,
                    _mm_andnot_ps(
                      _mm_cmpleps(v76, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v77, v76), v77)),
                        _mm_mul_ps(*(__m128 *)_xmm, v77))));
    if ( (v136 & 0x3FFFFFFF) >= v72 )
    {
      LODWORD(v170) = 0;
LABEL_78:
      v135 = v72;
      goto LABEL_79;
    }
    v78 = v72;
    if ( v72 < 2 * (v136 & 0x3FFFFFFF) )
      v78 = 2 * (v136 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&v170,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &convexIndices,
      v78,
      4);
    if ( !(_DWORD)v170 )
      goto LABEL_78;
LABEL_79:
    v79 = *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( (v139 & 0x3FFFFFFF) >= v79 )
    {
      v153.m_enum = 0;
LABEL_85:
      v138 = v79;
      goto LABEL_86;
    }
    v80 = *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( v79 < 2 * (v139 & 0x3FFFFFFF) )
      v80 = 2 * (v139 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v153, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &materials, v80, 4);
    if ( v153.m_enum == HK_SUCCESS )
      goto LABEL_85;
LABEL_86:
    v81 = *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( (v133 & 0x3FFFFFFF) >= v81 )
    {
      v151.m_enum = 0;
LABEL_92:
      v132 = v81;
      goto LABEL_93;
    }
    v82 = *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( v81 < 2 * (v133 & 0x3FFFFFFF) )
      v82 = 2 * (v133 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &v151,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &convexMaterials,
      v82,
      4);
    if ( v151.m_enum == HK_SUCCESS )
      goto LABEL_92;
LABEL_93:
    v83 = 3 * *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( (v130 & 0x3FFFFFFF) >= v83 )
    {
      v149.m_enum = 0;
LABEL_99:
      v129 = v83;
      goto LABEL_100;
    }
    v84 = 3 * *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( v83 < 2 * (v130 & 0x3FFFFFFF) )
      v84 = 2 * (v130 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v149, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &oppConvexEdges, v84, 4);
    if ( v149.m_enum == HK_SUCCESS )
      goto LABEL_99;
LABEL_100:
    v85 = (_DWORD *)*(unsigned int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( (v127 & 0x3FFFFFFF) >= (signed int)v85 )
    {
      v87 = 0;
      v156.m_enum = 0;
LABEL_106:
      v126 = (signed int)v85;
      goto LABEL_107;
    }
    v86 = *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( (signed int)v85 < 2 * (v127 & 0x3FFFFFFF) )
      v86 = 2 * (v127 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &v156,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &numIndicesPerPiece,
      v86,
      4);
    v87 = v156.m_enum;
    if ( v156.m_enum == HK_SUCCESS )
      goto LABEL_106;
LABEL_107:
    if ( (_DWORD)v170 || v153.m_enum || v151.m_enum || v149.m_enum || v87 )
      goto LABEL_164;
    v88 = v12->m_data;
    v89 = v143;
    v90 = 0;
    v158 = v143;
    if ( *(int *)((char *)v88 + (_QWORD)v65) > 0 )
      break;
LABEL_119:
    v94 = 3 * *(int *)((char *)v65->i + (unsigned __int64)v12->m_data);
    if ( settings->m_convexThreshold >= 0.0 )
      v95 = hkaiNavMeshGenerationUtils::_hertelMehlhorn(
              &v165,
              (hkVector4f *)a->m_data,
              triangleIndices,
              materials,
              v85,
              oppEdges,
              v94,
              settings,
              convexIndices,
              convexMaterials,
              oppConvexEdges,
              numIndicesPerPiece,
              &n,
              &v167);
    else
      v95 = hkaiNavMeshGenerationUtils::_nullHertelMehlhorn(
              &v166,
              (hkVector4f *)a->m_data,
              triangleIndices,
              materials,
              oppEdges,
              v94,
              convexIndices,
              convexMaterials,
              oppConvexEdges,
              numIndicesPerPiece,
              &n);
    if ( v95->m_enum )
      goto LABEL_164;
    v96 = n;
    v97 = convexIndices;
    v98 = oppConvexEdges;
    v99 = v62->m_faces.m_size;
    v148.m_enum = v62->m_edges.m_size;
    v100 = hkaiNavMesh::expandFacesBy(v62, n, estimatedMaxNumFaces);
    if ( !v100 )
      goto LABEL_164;
    v101 = v99;
    v155 = 0;
    v163 = v99;
    if ( v96 > 0 )
    {
      v102 = (signed __int64)&v100->m_numUserEdges;
      v103 = 0i64;
      v158 = 0i64;
      v164 = (__int64)&v100->m_numUserEdges;
      while ( 1 )
      {
        v104 = *(unsigned int *)((char *)numIndicesPerPiece + v103);
        *(_DWORD *)(v102 - 2) = 0;
        *(_DWORD *)(v102 - 10) = -1;
        *(_DWORD *)(v102 - 6) = -1;
        *(_WORD *)(v102 + 2) = -1;
        *(_WORD *)(v102 + 4) = -12851;
        v105 = v62->m_edges.m_size;
        *(_WORD *)(v102 - 2) = v104;
        *(_DWORD *)(v102 - 10) = v105;
        if ( v62->m_faceDataStriding )
          v62->m_faceData.m_data[v101 * v62->m_faceDataStriding] = *(int *)((char *)convexMaterials + v103);
        v162 = v62->m_edges.m_size;
        v106 = hkaiNavMesh::expandEdgesBy(v62, v104, estimatedMaxNumEdges);
        if ( !v106 )
          goto LABEL_164;
        v107 = 0i64;
        v108 = (signed int)v104 - 1;
        if ( (signed int)v104 > 0 )
        {
          v109 = 0i64;
          v110 = v104;
          v111 = 20i64 * ((signed int)v104 - 1);
          v112 = v162;
          do
          {
            *(int *)((char *)&v106->m_a + v111) = v97[v108];
            *(int *)((char *)&v106->m_b + v111) = v97[v107];
            *(_QWORD *)((char *)&v106->m_oppositeEdge + v111) = -1i64;
            *(_DWORD *)(&v106->m_flags.m_storage + v111) = 4;
            v113 = v62->m_edgeDataStriding;
            if ( (_DWORD)v113 )
              v62->m_edgeData.m_data[v113 * (v108 + v112)] = 0;
            v114 = v98[v108];
            if ( v114 != -1 )
              *(unsigned int *)((char *)&v106->m_oppositeEdge + v111) = v148.m_enum + v114;
            v108 = v107;
            v111 = v109;
            ++v107;
            v109 += 20i64;
            --v110;
          }
          while ( v110 );
          v102 = v164;
        }
        v102 += 16i64;
        v115 = 4i64 * *(int *)((char *)numIndicesPerPiece + v158);
        v103 = v158 + 4;
        ++v155;
        v97 = (int *)((char *)v97 + v115);
        v98 = (int *)((char *)v98 + v115);
        v101 = v163 + 1;
        v164 = v102;
        v158 += 4i64;
        ++v163;
        if ( v155 >= n )
        {
          v12 = v171;
          break;
        }
      }
    }
    v65 = array;
    v116 = *(int *)((char *)array->i + (unsigned __int64)v12->m_data);
    v117 = 3i64 * v116;
    oppEdges = (int *)((char *)oppEdges + v117 * 4);
    v63 = &triangleIndices[v117];
    v143 += v116;
    v64 = resulta.m_enum;
    triangleIndices = v63;
LABEL_140:
    ++v64;
    v65 = (SortedTriangle *)((char *)v65 + 4);
    resulta.m_enum = v64;
    array = v65;
    if ( v64 >= v12->m_size )
      goto LABEL_141;
  }
  v85 = 0i64;
  while ( 1 )
  {
    v91 = _mm_add_ps(_mm_add_ps((__m128)a->m_data[*(v67 - 2)], (__m128)a->m_data[*(v67 - 1)]), (__m128)a->m_data[*v67]);
    resultOut.m_enum = 0;
    trisToRemove.m_storage.m_words = (hkArray<unsigned int,hkContainerHeapAllocator>)_mm_mul_ps(
                                                                                       v91,
                                                                                       (__m128)xmmword_141A711C0);
    v92 = allTriangleMaterials ? *(int *)((char *)&allTriangleMaterials->m_data[v89] + (unsigned __int64)v85) : *((_DWORD *)&triMeshIn->m_triangles.m_data[*(int *)((char *)originalFaceIndices->m_data + (unsigned __int64)v65 + 4)] - 1);
    v93 = hkaiCarverTree::getPaintedMaterialForPoint(
            carverTree,
            (hkVector4f *)&trisToRemove,
            v92,
            settings->m_painterOverlapCallback,
            &resultOut);
    if ( resultOut.m_enum )
      break;
    v89 = v158;
    ++v90;
    *(_DWORD *)((char *)v85 + (_QWORD)materials) = v93;
    v67 += 3;
    ++v85;
    if ( v90 >= *(int *)((char *)v65->i + (unsigned __int64)v12->m_data) )
      goto LABEL_119;
  }
LABEL_164:
  v42 = v168;
  v168->m_enum = 1;
LABEL_150:
  v126 = 0;
  if ( v127 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      numIndicesPerPiece,
      4 * v127);
  v129 = 0;
  v127 = 2147483648;
  numIndicesPerPiece = 0i64;
  if ( v130 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      oppConvexEdges,
      4 * v130);
  v132 = 0;
  v130 = 2147483648;
  oppConvexEdges = 0i64;
  if ( v133 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      convexMaterials,
      4 * v133);
  v138 = 0;
  v133 = 2147483648;
  convexMaterials = 0i64;
  if ( v139 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      materials,
      4 * v139);
  v135 = 0;
  v139 = 2147483648;
  materials = 0i64;
  if ( v136 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      convexIndices,
      4 * v136);
  v141 = 0;
  v136 = 2147483648;
  convexIndices = 0i64;
  if ( v142 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      oppositeEdgesOut,
      4 * v142);
  return v42;
}ryAllocator *)&hkContainerHeapAllocator::s_alloc,
      convexMaterials,
      4 * v133);
  v138 = 0;
  v133 = 2147483648;
  convexMaterials = 0i64;
  if ( v139 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      materials,
      4 * v139);
  v135 = 0;
  v139 = 2147483648;
  materials = 0i64;
  if ( v136 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->buf

// File Line: 1698
// RVA: 0xB827A0
void __fastcall hkaiNavMeshGenerationUtils::_removeTriangles(hkBitField *trisToRemove, hkArray<int,hkContainerHeapAllocator> *trisInOut, hkArray<int,hkContainerHeapAllocator> *triConnectivityInOut, hkArray<int,hkContainerHeapAllocator> *trisPerFaceInOut, hkArrayBase<int> *perTriangleDataInOut, hkArrayBase<int> *perTriangleDataInOut2)
{
  hkArrayBase<int> *v6; // r11
  int *v7; // r10
  int *v8; // r13
  hkArray<int,hkContainerHeapAllocator> *v9; // rax
  hkArray<int,hkContainerHeapAllocator> *v10; // rsi
  hkArray<int,hkContainerHeapAllocator> *v11; // r12
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
  signed __int64 v24; // r10
  hkBitField *v25; // [rsp+50h] [rbp+8h]
  int v26; // [rsp+58h] [rbp+10h]
  hkArray<int,hkContainerHeapAllocator> *v27; // [rsp+60h] [rbp+18h]
  hkArray<int,hkContainerHeapAllocator> *v28; // [rsp+68h] [rbp+20h]

  v28 = trisPerFaceInOut;
  v27 = triConnectivityInOut;
  v25 = trisToRemove;
  v6 = perTriangleDataInOut;
  v7 = trisInOut->m_data;
  v8 = triConnectivityInOut->m_data;
  v9 = trisPerFaceInOut;
  v10 = triConnectivityInOut;
  v11 = trisInOut;
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
      if ( !((trisToRemove->m_storage.m_words.m_data[(signed __int64)(v16 / 3) >> 5] >> (v16 / 3 & 0x1F)) & 1) )
      {
        *v7 = v11->m_data[v18];
        v7[1] = v11->m_data[v18 + 1];
        v7[2] = v11->m_data[v18 + 2];
        *v8 = v27->m_data[v18];
        v8[1] = v27->m_data[v18 + 1];
        v8[2] = v27->m_data[v18 + 2];
        if ( v12 )
        {
          ++v12;
          *(v12 - 1) = perTriangleDataInOut->m_data[v22];
        }
        if ( v14 )
        {
          ++v14;
          *(v14 - 1) = perTriangleDataInOut2->m_data[v22];
        }
        v7 += 3;
        v8 += 3;
        ++v15;
      }
      v23 = v28->m_data[v17] + v26;
      if ( v22 >= v23 - 1 )
      {
        v28->m_data[v17] = v15;
        v15 = 0;
        v26 = v23;
        ++v17;
      }
      v9 = v28;
      trisToRemove = v25;
      v16 += 3;
      v18 += 3i64;
    }
    while ( v16 < v11->m_size );
    v13 = perTriangleDataInOut2;
    v6 = perTriangleDataInOut;
    v10 = v27;
  }
  v24 = v7 - v11->m_data;
  v11->m_size = v24;
  v10->m_size = v24;
  if ( v6 )
    v6->m_size = (signed int)v24 / 3;
  if ( v13 )
    v13->m_size = (signed int)v24 / 3;
}

