// File Line: 17
// RVA: 0x15DEFF0
__int64 dynamic_initializer_for__s_nullAllocator__()
{
  return atexit(dynamic_atexit_destructor_for__s_nullAllocator__);
}

// File Line: 19
// RVA: 0x12E9880
hkNullAllocator *__fastcall hkNullAllocator::getInstance()
{
  return &s_nullAllocator;
}

// File Line: 126
// RVA: 0x12E9DB0
__int64 __usercall hkaiFaceCutter::triangulatorAddLoop@<rax>(hkaiFaceCutter *this@<rcx>, hkVector4f *points@<rdx>, int loopSize@<r8d>, hkaiFaceCutter::LoopType loopType@<r9d>, __int64 a5@<rsi>, int materialIndex, hkArrayBase<int> *vertexRemap)
{
  int v7; // er13
  hkaiFaceCutter *v8; // rbx
  int v9; // edi
  int v10; // er14
  hkLifoAllocator *v11; // rax
  int *v12; // r15
  int v13; // edx
  char *v14; // rcx
  int *v15; // rax
  int v16; // edi
  int v17; // eax
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128i v23; // xmm1
  int v24; // esi
  int v25; // ecx
  __int64 v26; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v27; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v28; // r8
  __int64 v29; // r9
  unsigned int v30; // ebx
  signed __int64 v31; // rdx
  __int64 v32; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v33; // rdx
  int *v34; // rsi
  int v35; // er12
  int v36; // er8
  unsigned int v37; // eax
  int v38; // er9
  int v39; // eax
  int v40; // eax
  signed int v41; // er13
  hkLifoAllocator *v42; // rcx
  int v43; // er8
  int data; // [rsp+40h] [rbp-69h]
  hkaiRuntimeTriangulatorEdgeData v46; // [rsp+48h] [rbp-61h]
  int v47; // [rsp+50h] [rbp-59h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion icrossing; // [rsp+58h] [rbp-51h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Location result; // [rsp+70h] [rbp-39h]
  __int64 v50; // [rsp+A0h] [rbp-9h]
  hkVector4f *retaddr; // [rsp+108h] [rbp+5Fh]
  __int64 v52; // [rsp+110h] [rbp+67h]
  hkVector4f *v53; // [rsp+118h] [rbp+6Fh]
  char v54; // [rsp+120h] [rbp+77h]
  __int64 v55; // [rsp+128h] [rbp+7Fh]

  LODWORD(v55) = loopType;
  v53 = points;
  v7 = loopSize;
  v8 = this;
  if ( loopType && _mm_movemask_ps(_mm_cmpeqps(points[loopSize - 1].m_quad, points->m_quad)) == 15 )
    v7 = loopSize - 1;
  v9 = 0;
  v10 = 0;
  if ( v7 )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (int *)v11->m_cur;
    v13 = (32 * v7 + 127) & 0xFFFFFF80;
    v14 = (char *)v12 + v13;
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    {
      v15 = (int *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
      points = retaddr;
      v12 = v15;
    }
    else
    {
      points = retaddr;
      v11->m_cur = v14;
    }
  }
  else
  {
    v12 = 0i64;
  }
  v52 = a5;
  data = 0;
  v47 = v7 | 0x80000000;
  v46 = 0i64;
  if ( v7 > 0 )
  {
    do
    {
      v16 = v8->m_triangulator.m_margin;
      v17 = 0x7FFF - v16;
      v18 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(points->m_quad, points->m_quad, 0),
                    v8->m_triangulator.m_worldToLocal.m_col0.m_quad),
                  v8->m_triangulator.m_worldToLocal.m_col3.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(points->m_quad, points->m_quad, 85),
                  v8->m_triangulator.m_worldToLocal.m_col1.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(points->m_quad, points->m_quad, 170),
                v8->m_triangulator.m_worldToLocal.m_col2.m_quad));
      v19 = _mm_sub_ps(v18, (__m128)xmmword_141A711B0);
      v20 = _mm_add_ps(v18, (__m128)xmmword_141A711B0);
      v21 = _mm_cmpltps(v18, (__m128)0i64);
      v22 = _mm_or_ps(_mm_andnot_ps(v21, v20), _mm_and_ps(v19, v21));
      v23 = _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v22),
              _mm_cvttps_epi32(v22));
      v24 = _mm_cvtsi128_si32(v23);
      if ( v24 >= v16 )
      {
        if ( v24 > v17 )
          v24 = 0x7FFF - v16;
      }
      else
      {
        v24 = v8->m_triangulator.m_margin;
      }
      v25 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v23, 85));
      if ( v25 >= v16 )
      {
        v16 = v25;
        if ( v25 > v17 )
          v16 = v17;
      }
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::locateVertex(
        &v8->m_triangulator,
        &result,
        v24,
        v16);
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertVertex(
        &v8->m_triangulator,
        &icrossing,
        v24,
        v16,
        1,
        &result,
        0);
      LODWORD(v26) = icrossing.m_type.m_storage;
      if ( icrossing.m_type.m_storage == 2 )
      {
        result.m_edge.m_triangle = icrossing.m_edge.m_triangle;
        *(_QWORD *)&result.m_edge.m_index = *(_QWORD *)&icrossing.m_edge.m_index;
        result.m_type.m_storage = 1;
        v27 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertVertex(
                &v8->m_triangulator,
                &icrossing,
                v24,
                v16,
                1,
                &result,
                1);
        v26 = *(_QWORD *)&v27->m_type.m_storage;
        v28 = v27->m_edge.m_triangle;
        v29 = *(_QWORD *)&v27->m_edge.m_index;
      }
      else
      {
        LODWORD(v29) = icrossing.m_edge.m_index;
        v28 = icrossing.m_edge.m_triangle;
      }
      if ( (unsigned int)v26 <= 1 )
      {
        v31 = (signed __int64)&v12[8 * v10];
        if ( v31 )
        {
          v32 = v50;
          *(_DWORD *)(v31 + 16) = v24;
          *(_DWORD *)(v31 + 20) = v16;
          *(_QWORD *)(v31 + 24) = v32;
        }
        ++v10;
        if ( !(_DWORD)v26 )
        {
          v33 = v28->m_vertices[(signed int)v29];
          *((_QWORD *)v33 + 3) = *((_DWORD *)v33 + 6) & 3 | (unsigned __int64)(4i64
                                                                             * (v8->m_triangulator.m_mesh.m_vertices.m_numUsed
                                                                              - 1));
          if ( (_BYTE)v52 )
            *(_DWORD *)(*(_QWORD *)v55 + 4i64 * (signed int)(*(_DWORD *)(v55 + 8))++) = data;
        }
      }
      else if ( (_DWORD)v26 == 10 )
      {
LABEL_23:
        v30 = 0;
        goto LABEL_52;
      }
      ++data;
      points = retaddr + 1;
      ++*(_QWORD *)&v46;
      ++retaddr;
    }
    while ( *(signed __int64 *)&v46 < v7 );
    v9 = 0;
  }
  if ( v10 > 0 )
  {
    v34 = v12 + 4;
    do
    {
      v35 = v9 + 1;
      *(_QWORD *)&icrossing.m_type.m_storage = v8;
      LOBYTE(icrossing.m_edge.m_triangle) = 0;
      if ( (_DWORD)v53 )
      {
        if ( (_DWORD)v53 == 2 )
        {
          v36 = -1;
          v37 = 0x8000;
        }
        else
        {
          v36 = -2;
          v37 = 1 << (v54 + 1);
        }
      }
      else
      {
        v36 = v9;
        v37 = 1;
      }
      v38 = v34[1];
      v46.m_sets = v37;
      v46.m_tag = v36;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
        &v8->m_triangulator,
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *)&result,
        *v34,
        v38,
        v12[8 * ((v9 + 1) % v10) + 4],
        v12[8 * ((v9 + 1) % v10) + 5],
        1,
        (NavMeshCutterCutterEdgeCrossing *)&icrossing,
        &v46);
      if ( result.m_type.m_storage )
      {
        if ( result.m_type.m_storage == 10 )
          goto LABEL_23;
        if ( result.m_type.m_storage == 1 )
        {
          v40 = v8->m_firstDuplicateEdge;
          if ( v40 == -1 )
            v40 = v9;
          v8->m_firstDuplicateEdge = v40;
        }
      }
      else
      {
        v39 = v8->m_firstSuccessfulEdge;
        if ( v39 == -1 )
          v39 = v9;
        v8->m_firstSuccessfulEdge = v39;
      }
      if ( (_BYTE)v52 && LOBYTE(icrossing.m_edge.m_triangle) )
        v8->m_faceIsCrossing = 1;
      v34 += 8;
      ++v9;
    }
    while ( v35 < v10 );
  }
  v30 = 1;
LABEL_52:
  v41 = (32 * v7 + 127) & 0xFFFFFF80;
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v41 + 15) & 0xFFFFFFF0;
  if ( v41 > v42->m_slabSize || (char *)v12 + v43 != v42->m_cur || v42->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v42, v12, v43);
  else
    v42->m_cur = v12;
  if ( v47 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v12,
      32 * v47);
  return v30;
}

// File Line: 231
// RVA: 0x12EB3B0
signed __int64 __fastcall getConnectivity(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *triangulator, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *e)
{
  __int64 v2; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v3; // rbp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v4; // r12
  unsigned __int64 v5; // rbx
  char v6; // r15
  hkaiRuntimeTriangulatorEdgeData *v7; // rax
  hkaiRuntimeTriangulatorEdgeData *v8; // r14
  int v9; // eax
  hkaiRuntimeTriangulatorEdgeData *v11; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v12; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v13; // rdx
  int v14; // eax
  int v15; // ecx
  unsigned __int64 v16; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edge; // [rsp+20h] [rbp-38h]

  v2 = (signed int)e->m_index;
  v3 = e->m_triangle;
  v4 = triangulator;
  v5 = e->m_triangle->m_links[v2];
  v6 = 0;
  edge.m_index = e->m_triangle->m_links[v2] & 3;
  edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)(v5 & 0xFFFFFFFFFFFFFFFCui64);
  if ( !(*(_BYTE *)((v5 & 0xFFFFFFFFFFFFFFFCui64) + 100) & 0x20) )
    v6 = 1;
  v7 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
         triangulator,
         e);
  v8 = v7;
  if ( v7 )
  {
    v9 = v7->m_tag;
    if ( v9 == -1 || v8->m_sets & 0x8000 || v6 && v9 == -2 )
      return 0xFFFFFFFFi64;
  }
  v11 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
          v4,
          &edge);
  if ( v11 )
  {
    if ( v11->m_tag == -1 || v11->m_sets & 0x8000 || v6 && v11->m_tag == -2 )
      return 0xFFFFFFFFi64;
  }
  if ( v8 )
    return (unsigned int)v8->m_tag;
  if ( v11 )
    return (unsigned int)v11->m_tag;
  v12 = v3->m_vertices[v2];
  v13 = v3->m_vertices[(9i64 >> 2 * (unsigned __int8)v2) & 3];
  v14 = v12->m_x;
  v15 = v13->m_x;
  if ( v14 >= v15 && (v14 > v15 || v12->m_y > v13->m_y) && v5 & 0xFFFFFFFFFFFFFFFCui64 )
  {
    LOBYTE(v2) = v5 & 3;
    v16 = v5 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v16 = (unsigned __int64)v3;
  }
  return (unsigned int)((*(_BYTE *)(v16 + 100) & (unsigned __int8)(1 << v2) & 7) != 0) - 2;
}

// File Line: 322
// RVA: 0x12EB500
void __fastcall projectVertex(hkVector4f *up, hkVector4f *faceNormal, hkVector4f *vInOut)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1

  v3 = _mm_mul_ps(vInOut->m_quad, faceNormal->m_quad);
  v4 = _mm_mul_ps(faceNormal->m_quad, up->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, faceNormal->m_quad), 196);
  v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 78), v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 177), v7);
  v9 = _mm_rcp_ps(v5);
  vInOut->m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       up->m_quad,
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v5)), v9),
                         _mm_sub_ps((__m128)0i64, v8))),
                     vInOut->m_quad);
}

// File Line: 329
// RVA: 0x12EB590
void __fastcall finalizeCutResults(hkaiFaceCutResults *resultsInMainMem, hkaiFaceCutResults *resultsLocal)
{
  ;
}

// File Line: 337
// RVA: 0x12EB5A0
__int64 __fastcall leastSignificantBit(unsigned int x)
{
  unsigned int v1; // edx
  unsigned int v2; // er8
  __int64 result; // rax

  v1 = 32;
  v2 = x & -x;
  if ( x & -x )
    v1 = 31;
  if ( (_WORD)v2 )
    v1 -= 16;
  if ( v2 & 0xFF00FF )
    v1 -= 8;
  if ( v2 & 0xF0F0F0F )
    v1 -= 4;
  if ( v2 & 0x33333333 )
    v1 -= 2;
  result = v1 - 1;
  if ( !(v2 & 0x55555555) )
    result = v1;
  return result;
}

// File Line: 365
// RVA: 0x12EA230
signed __int64 __fastcall hkaiFaceCutter::computeConvexDecompositionOfCutFace(hkaiFaceCutter *this, hkArrayBase<hkVector4f> *faceVertices, hkArrayBase<int> *faceLoopVertexIndexRemap, hkaiFaceCutResults *resultsInMainMem)
{
  hkVector4f v4; // xmm0
  bool v5; // zf
  hkaiFaceCutResults *v6; // r13
  hkaiFaceCutter *v7; // rsi
  _QWORD *v9; // rdi
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *i; // rax
  unsigned int v13; // esi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *j; // rdi
  unsigned __int16 v15; // ax
  __int16 v16; // ax
  __int16 v17; // r9
  _QWORD *v18; // rdi
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  int v22; // edi
  int v23; // er14
  hkLifoAllocator *v24; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v25; // rbx
  int v26; // edx
  char *v27; // rcx
  unsigned int v28; // er15
  LPVOID v29; // rax
  hkLifoAllocator *v30; // rcx
  unsigned int *v31; // rax
  int v32; // edx
  char *v33; // r8
  int v34; // ebx
  _QWORD *v35; // rdi
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  signed __int64 v38; // rcx
  int v39; // eax
  hkLifoAllocator *v40; // rax
  char *v41; // rdx
  int v42; // ecx
  char *v43; // rdi
  signed int v44; // ecx
  int v45; // er9
  __int64 v46; // rcx
  char *v47; // rdi
  __int64 v48; // r12
  char *v49; // rax
  char *v50; // rbx
  int v51; // eax
  int v52; // ecx
  int v53; // ecx
  hkLifoAllocator *v54; // rax
  char *v55; // rdi
  int v56; // edx
  char *v57; // rcx
  char *v58; // rax
  signed int v59; // er15
  int v60; // er9
  int v61; // edx
  char *v62; // rdi
  __int64 v63; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v64; // r15
  __int64 v65; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v66; // rdi
  int v67; // er9
  signed int v68; // eax
  signed int v69; // er8
  __int64 v70; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v71; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v72; // rdx
  __int64 v73; // rcx
  __int64 v74; // r13
  unsigned int v75; // ecx
  __int64 v76; // rcx
  hkLifoAllocator *v77; // rax
  _DWORD *v78; // r15
  int v79; // edx
  char *v80; // rcx
  hkLifoAllocator *v81; // rax
  char *v82; // rdi
  int v83; // edx
  char *v84; // rcx
  hkLifoAllocator *v85; // rax
  _DWORD *v86; // r14
  int v87; // edx
  char *v88; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v89; // r10
  hkArrayBase<hkVector4f> *v90; // rbx
  __int64 v91; // r13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v92; // r14
  __int64 v93; // rdx
  const __m128i *v94; // r9
  unsigned __int64 v95; // rax
  signed int v96; // edi
  char *v97; // rcx
  signed __int64 v98; // r15
  __m128 v99; // xmm2
  __int64 v100; // rcx
  hkVector4f *v101; // rax
  __m128 v102; // xmm2
  __m128 v103; // xmm6
  __m128 v104; // xmm1
  __m128 v105; // xmm3
  __m128 v106; // xmm6
  __m128 v107; // xmm2
  __m128 v108; // xmm2
  __m128 v109; // xmm7
  __int64 v110; // rax
  __m128 v111; // xmm5
  __m128 v112; // xmm6
  __m128 v113; // xmm1
  __m128 v114; // xmm2
  __m128 v115; // xmm1
  __m128 v116; // xmm4
  __m128 v117; // xmm3
  __m128 v118; // xmm4
  __m128 v119; // xmm1
  __m128 v120; // xmm2
  __m128 v121; // xmm0
  __m128 v122; // xmm3
  __m128 v123; // xmm1
  __m128 v124; // xmm1
  __m128 v125; // xmm4
  __m128 v126; // xmm2
  __m128 v127; // xmm2
  __m128 v128; // xmm1
  __m128 v129; // xmm0
  __m128 v130; // xmm1
  __int64 v131; // rdx
  int v132; // ecx
  __int64 v133; // rdx
  int v134; // eax
  signed int v135; // er8
  signed int v136; // ecx
  int v137; // er11
  char v138; // di
  _BYTE *v139; // rdx
  signed int v140; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v141; // rcx
  signed int *v142; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v143; // r10
  int v144; // eax
  int *v145; // rcx
  __int64 v146; // rdx
  int v147; // eax
  int *v148; // rcx
  __int64 v149; // rdx
  int v150; // eax
  signed int v151; // er8
  int *v152; // rdx
  unsigned int v153; // eax
  __int64 v154; // rdi
  int v155; // ecx
  __int64 v156; // rcx
  char v157; // al
  char v158; // al
  char v159; // al
  int v160; // edi
  hkLifoAllocator *v161; // rax
  int v162; // er8
  int v163; // er13
  hkLifoAllocator *v164; // rax
  void *v165; // rdx
  int v166; // edi
  int v167; // er14
  hkLifoAllocator *v168; // rax
  __int64 v169; // rax
  int v170; // eax
  char *v171; // rbx
  signed int v172; // edi
  hkLifoAllocator *v173; // rax
  int v174; // er8
  int v175; // eax
  char *v176; // rbx
  signed int v177; // edi
  hkLifoAllocator *v178; // rax
  int v179; // er8
  signed int v180; // edi
  hkLifoAllocator *v181; // rax
  int v182; // er8
  signed int v183; // edi
  hkLifoAllocator *v184; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v185; // rdx
  int v186; // er8
  _QWORD *v187; // rdi
  _QWORD *v188; // rcx
  unsigned __int64 v189; // rax
  signed __int64 v190; // rcx
  int numEdges; // [rsp+30h] [rbp-D0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *e; // [rsp+38h] [rbp-C8h]
  int v193; // [rsp+40h] [rbp-C0h]
  char *v194; // [rsp+48h] [rbp-B8h]
  void *p; // [rsp+50h] [rbp-B0h]
  char *array; // [rsp+58h] [rbp-A8h]
  int v197; // [rsp+60h] [rbp-A0h]
  int v198; // [rsp+64h] [rbp-9Ch]
  void *v199; // [rsp+68h] [rbp-98h]
  int v200; // [rsp+70h] [rbp-90h]
  int v201; // [rsp+78h] [rbp-88h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v202; // [rsp+80h] [rbp-80h]
  char *v203; // [rsp+88h] [rbp-78h]
  int v204; // [rsp+90h] [rbp-70h]
  int v205; // [rsp+94h] [rbp-6Ch]
  void *v206; // [rsp+98h] [rbp-68h]
  int v207; // [rsp+A0h] [rbp-60h]
  hkResult v208; // [rsp+A8h] [rbp-58h]
  int v209; // [rsp+ACh] [rbp-54h]
  int v210; // [rsp+B0h] [rbp-50h]
  int v211; // [rsp+B4h] [rbp-4Ch]
  _DWORD *v212; // [rsp+B8h] [rbp-48h]
  hkVector4f closestPointOut; // [rsp+C0h] [rbp-40h]
  _DWORD *v214; // [rsp+D0h] [rbp-30h]
  int v215; // [rsp+D8h] [rbp-28h]
  unsigned int v216; // [rsp+DCh] [rbp-24h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v217; // [rsp+E0h] [rbp-20h]
  int v218; // [rsp+E8h] [rbp-18h]
  hkArrayBase<unsigned int> pieceSize; // [rsp+F0h] [rbp-10h]
  void *v220; // [rsp+100h] [rbp+0h]
  int v221; // [rsp+108h] [rbp+8h]
  __int64 k; // [rsp+110h] [rbp+10h]
  __int64 v223; // [rsp+118h] [rbp+18h]
  unsigned __int64 v224; // [rsp+120h] [rbp+20h]
  signed int *v225; // [rsp+128h] [rbp+28h]
  hkVector4f up; // [rsp+130h] [rbp+30h]
  hkVector4f pointInOut; // [rsp+140h] [rbp+40h]
  hkVector4f planeOut; // [rsp+150h] [rbp+50h]
  hkAabb aabbOut; // [rsp+160h] [rbp+60h]
  hkSimdFloat32 extraRadius; // [rsp+180h] [rbp+80h]
  hkVector4f position; // [rsp+190h] [rbp+90h]
  hkResult result; // [rsp+220h] [rbp+120h]
  hkArrayBase<hkVector4f> *facePoints; // [rsp+228h] [rbp+128h]
  hkArrayBase<int> *v234; // [rsp+230h] [rbp+130h]
  hkaiFaceCutResults *v235; // [rsp+238h] [rbp+138h]

  v235 = resultsInMainMem;
  v234 = faceLoopVertexIndexRemap;
  facePoints = faceVertices;
  v4.m_quad = (__m128)this->m_up;
  resultsInMainMem->m_originalFace = this->m_faceKey;
  v5 = HK_flyingcolors_ai_2.m_bool == 0;
  v6 = resultsInMainMem;
  _mm_store_si128((__m128i *)&up, (__m128i)v4.m_quad);
  v7 = this;
  if ( v5 )
  {
    hkaiCheckKeycode();
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_2);
    if ( !HK_flyingcolors_ai_2.m_bool )
      v7->m_numSilhouettesAdded = 0;
  }
  if ( !v7->m_numSilhouettesAdded )
  {
    v6->m_flags.m_storage |= 1u;
    return 1i64;
  }
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtcomputeCxDecompOfCutFace";
    *(_QWORD *)(v10 + 16) = "StRegionFlood";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  for ( i = v7->m_triangulator.m_mesh.m_triangles.m_used; i; i = i->m_next )
    i->m_sets = 0;
  if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::floodEdgeSets<FloodPolicyCell>(
         &v7->m_triangulator,
         (FloodPolicyCell *)&result) )
  {
    for ( j = v7->m_triangulator.m_mesh.m_triangles.m_used; j; j = j->m_next )
    {
      v15 = j->m_sets;
      if ( !(v15 & 0x8000) && v15 && v15 & 1 )
      {
        *((_WORD *)j + 50) &= 0x1Fu;
        if ( v15 == 1 )
        {
          *((_WORD *)j + 50) |= 0x20u;
        }
        else
        {
          v16 = leastSignificantBit((unsigned int)v15 >> 1);
          *((_WORD *)j + 50) |= v17 & ((v16 << 6) + 64) | 0x20;
        }
      }
      else
      {
        *((_WORD *)j + 50) &= 0x1Fu;
      }
    }
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = (_QWORD *)v18[1];
    if ( (unsigned __int64)v19 < v18[3] )
    {
      *v19 = "StTriangle merge to convex";
      v20 = __rdtsc();
      v21 = (signed __int64)(v19 + 2);
      *(_DWORD *)(v21 - 8) = v20;
      v18[1] = v21;
    }
    v22 = v7->m_triangulator.m_mesh.m_triangles.m_numUsed;
    v23 = v7->m_triangulator.m_mesh.m_vertices.m_numUsed;
    v215 = 3 * v22;
    if ( 3 * v22 )
    {
      v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)v24->m_cur;
      e = v25;
      v26 = (48 * v22 + 127) & 0xFFFFFF80;
      v27 = (char *)v25 + v26;
      if ( v26 > v24->m_slabSize || v27 > v24->m_end )
      {
        v25 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)hkLifoAllocator::allocateFromNewSlab(v24, v26);
        e = v25;
      }
      else
      {
        v24->m_cur = v27;
      }
    }
    else
    {
      v25 = 0i64;
      e = 0i64;
    }
    v28 = 3 * v22 | 0x80000000;
    pieceSize.m_size = 0;
    v221 = v22;
    v218 = 3 * v22 | 0x80000000;
    if ( v22 )
    {
      v29 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v30 = (hkLifoAllocator *)v29;
      v31 = (unsigned int *)*((_QWORD *)v29 + 3);
      v32 = (4 * v22 + 127) & 0xFFFFFF80;
      v33 = (char *)v31 + v32;
      if ( v32 > v30->m_slabSize || v33 > v30->m_end )
        v31 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v30, v32);
      else
        v30->m_cur = v33;
    }
    else
    {
      v31 = 0i64;
    }
    pieceSize.m_data = v31;
    v220 = v31;
    numEdges = 0;
    result.m_enum = -1;
    pieceSize.m_capacityAndFlags = v22 | 0x80000000;
    v216 = v28 & 0x3FFFFFFF;
    v34 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::decomposeFastFixedSize(
            &v7->m_triangulator,
            &pieceSize,
            v25,
            v28 & 0x3FFFFFFF,
            &numEdges,
            (int *)&result);
    v193 = v34;
    v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v36 = (_QWORD *)v35[1];
    if ( (unsigned __int64)v36 < v35[3] )
    {
      *v36 = "StConvex piece extract";
      v37 = __rdtsc();
      v38 = (signed __int64)(v36 + 2);
      *(_DWORD *)(v38 - 8) = v37;
      v35[1] = v38;
    }
    v39 = 0;
    array = 0i64;
    v198 = 2147483648;
    v200 = v23;
    v197 = 0;
    if ( v23 )
    {
      v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v41 = (char *)v40->m_cur;
      v42 = (4 * v23 + 127) & 0xFFFFFF80;
      v43 = &v41[v42];
      if ( v42 > v40->m_slabSize || v43 > v40->m_end )
      {
        v41 = (char *)hkLifoAllocator::allocateFromNewSlab(v40, v42);
        v39 = v197;
      }
      else
      {
        v40->m_cur = v43;
        v39 = v197;
      }
    }
    else
    {
      v41 = 0i64;
    }
    array = v41;
    v199 = v41;
    v198 = v23 | 0x80000000;
    v44 = (v23 | 0x80000000) & 0x3FFFFFFF;
    if ( v44 < v23 )
    {
      v45 = v23;
      if ( v23 < 2 * v44 )
        v45 = 2 * v44;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v45, 4);
      v39 = v197;
      v41 = array;
    }
    v46 = v23 - v39;
    v47 = &v41[4 * v39];
    if ( v46 > 0 )
    {
      while ( v46 )
      {
        *(_DWORD *)v47 = -1;
        v47 += 4;
        --v46;
      }
    }
    v48 = (unsigned int)numEdges;
    v197 = v23;
    v49 = hkaiFaceCutResults::init(v6, v34, numEdges);
    LOBYTE(result.m_enum) = 0;
    planeOut.m_quad = 0i64;
    aabbOut.m_min = (hkVector4f)xmmword_141A712A0;
    v50 = v49;
    v194 = v49;
    aabbOut.m_max.m_quad = _mm_xor_ps(
                             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                             (__m128)xmmword_141A712A0);
    if ( v193 )
    {
      if ( !v49 )
      {
        v13 = 0;
LABEL_192:
        v175 = v197;
        v176 = (char *)v199;
        if ( v199 == array )
          v175 = 0;
        v197 = v175;
        v177 = (4 * v200 + 127) & 0xFFFFFF80;
        v178 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v179 = (v177 + 15) & 0xFFFFFFF0;
        if ( v177 > v178->m_slabSize || &v176[v179] != v178->m_cur || v178->m_firstNonLifoEnd == v176 )
          hkLifoAllocator::slowBlockFree(v178, v176, v179);
        else
          v178->m_cur = v176;
        v197 = 0;
        if ( v198 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            4 * v198);
        array = 0i64;
        v198 = 2147483648;
        v180 = (4 * v221 + 127) & 0xFFFFFF80;
        v181 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v182 = (v180 + 15) & 0xFFFFFFF0;
        if ( v180 > v181->m_slabSize || (char *)v220 + v182 != v181->m_cur || v181->m_firstNonLifoEnd == v220 )
          hkLifoAllocator::slowBlockFree(v181, v220, v182);
        else
          v181->m_cur = v220;
        if ( pieceSize.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            pieceSize.m_data,
            4 * pieceSize.m_capacityAndFlags);
        v183 = (16 * v215 + 127) & 0xFFFFFF80;
        v184 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v185 = e;
        v186 = (v183 + 15) & 0xFFFFFFF0;
        if ( v183 > v184->m_slabSize || (char *)e + v186 != v184->m_cur || v184->m_firstNonLifoEnd == e )
        {
          hkLifoAllocator::slowBlockFree(v184, e, v186);
          v185 = e;
        }
        else
        {
          v184->m_cur = e;
        }
        if ( v218 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v185,
            16 * v216);
        goto LABEL_215;
      }
      v51 = v6->m_numEdges;
      v52 = v6->m_numPolys;
      v205 = 2147483648;
      v207 = v23;
      v224 = (unsigned __int64)&v6->m_data[(11 * v52 + 9 * v51 + 15i64) & 0xFFFFFFFFFFFFFFF0ui64];
      v203 = 0i64;
      v53 = 0;
      v204 = 0;
      if ( v23 )
      {
        v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v55 = (char *)v54->m_cur;
        v56 = (4 * v23 + 127) & 0xFFFFFF80;
        v57 = &v55[v56];
        if ( v56 > v54->m_slabSize || v57 > v54->m_end )
        {
          v58 = (char *)hkLifoAllocator::allocateFromNewSlab(v54, v56);
          v53 = v204;
          v203 = v58;
        }
        else
        {
          v54->m_cur = v57;
          v53 = v204;
          v203 = v55;
        }
      }
      else
      {
        v203 = 0i64;
      }
      v205 = v23 | 0x80000000;
      v59 = (v23 | 0x80000000) & 0x3FFFFFFF;
      v206 = v203;
      if ( v59 < v23 )
      {
        v60 = v23;
        if ( v23 < 2 * v59 )
          v60 = 2 * v59;
        hkArrayUtil::_reserve(&v208, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v203, v60, 4);
        v53 = v204;
      }
      v61 = v23 - v53;
      v62 = &v203[4 * v53];
      v63 = v23 - v53;
      if ( v61 > 0 )
      {
        while ( v63 )
        {
          *(_DWORD *)v62 = -1;
          v62 += 4;
          --v63;
        }
      }
      v64 = e;
      v204 = v23;
      if ( (signed int)v48 > 0 )
      {
        v65 = v48;
        v66 = e;
        do
        {
          v67 = getConnectivity(&v7->m_triangulator, v66);
          if ( v67 == -1 )
          {
            v68 = 1;
          }
          else
          {
            v68 = 0;
            if ( v67 == -2 )
              v68 = 2;
          }
          v69 = 0;
          v70 = v68;
          do
          {
            if ( v70 )
              break;
            v71 = v69++ ? v66->m_triangle->m_vertices[(9i64 >> 2 * LOBYTE(v66->m_index)) & 3] : v66->m_triangle->m_vertices[v66->m_index];
            *(_DWORD *)&v203[4 * (signed int)(*((_QWORD *)v71 + 3) >> 2)] = v67;
          }
          while ( v69 < 2 );
          ++v66;
          --v65;
        }
        while ( v65 );
        LODWORD(v48) = numEdges;
      }
      v72 = v64;
      v73 = 0i64;
      v217 = v64;
      for ( k = 0i64;
            v73 < v193;
            v217 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)((char *)v217 + v169 * 16) )
      {
        v74 = pieceSize.m_data[v73];
        v75 = *((unsigned __int16 *)v72->m_triangle + 50);
        v208.m_enum = (signed int)v74;
        v76 = v75 >> 5;
        if ( (_DWORD)v76 == 1 )
          v201 = -1;
        else
          v201 = v7->m_materialsUsed.m_data[(v76 >> 1) - 1];
        v209 = 0;
        if ( (_DWORD)v74 )
        {
          v77 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v78 = v77->m_cur;
          v79 = (4 * v74 + 127) & 0xFFFFFF80;
          v214 = v78;
          v80 = (char *)v78 + v79;
          if ( v79 > v77->m_slabSize || v80 > v77->m_end )
          {
            v78 = hkLifoAllocator::allocateFromNewSlab(v77, v79);
            v214 = v78;
          }
          else
          {
            v77->m_cur = v80;
          }
        }
        else
        {
          v78 = 0i64;
          v214 = 0i64;
        }
        v210 = v74 | 0x80000000;
        if ( (_DWORD)v74 )
        {
          v81 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v82 = (char *)v81->m_cur;
          v83 = (4 * v74 + 127) & 0xFFFFFF80;
          p = v82;
          v84 = &v82[v83];
          if ( v83 > v81->m_slabSize || v84 > v81->m_end )
          {
            v82 = (char *)hkLifoAllocator::allocateFromNewSlab(v81, v83);
            p = v82;
          }
          else
          {
            v81->m_cur = v84;
          }
        }
        else
        {
          v82 = 0i64;
          p = 0i64;
        }
        v211 = 0;
        if ( (_DWORD)v74 )
        {
          v85 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v86 = v85->m_cur;
          v87 = (v74 + 127) & 0xFFFFFF80;
          v212 = v86;
          v88 = (char *)v86 + v87;
          if ( v87 > v85->m_slabSize || v88 > v85->m_end )
          {
            v86 = hkLifoAllocator::allocateFromNewSlab(v85, v87);
            v212 = v86;
          }
          else
          {
            v85->m_cur = v88;
          }
        }
        else
        {
          v86 = 0i64;
          v212 = 0i64;
        }
        if ( (signed int)v74 > 0 )
        {
          v89 = v217;
          v90 = facePoints;
          v223 = v74;
          v91 = (__int64)v212;
          v92 = v217;
          v202 = v217;
          v225 = (signed int *)v82;
          do
          {
            v93 = v7->m_initialNumVertsT;
            v94 = (const __m128i *)v92->m_triangle->m_vertices[v92->m_index];
            v95 = (unsigned __int64)v94[1].m128i_i64[1] >> 2;
            if ( (signed int)v95 < (signed int)v93 || (v96 = 0, (signed int)v95 > v7->m_lastFaceVertIndexT) )
              v96 = 4;
            v97 = array;
            v98 = 4i64 * (signed int)v95;
            if ( *(_DWORD *)&array[4 * (signed int)v95] == -1 )
            {
              if ( v96 || (signed int)v95 - (signed int)v93 >= v234->m_size )
              {
                v107 = _mm_cvtepi32_ps(_mm_loadl_epi64(v94 + 1));
                v108 = (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_shuffle_ps(v107, _mm_unpackhi_ps(v107, (__m128)0i64), 180),
                                   4),
                                 4);
                v109 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v108, v108, 0), v7->m_triangulator.m_localToWorld.m_col0.m_quad),
                             v7->m_triangulator.m_localToWorld.m_col3.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v108, v108, 85), v7->m_triangulator.m_localToWorld.m_col1.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v108, v108, 170), v7->m_triangulator.m_localToWorld.m_col2.m_quad));
                closestPointOut.m_quad = v109;
                v110 = *(signed int *)&v203[v98];
                if ( (_DWORD)v110 == -1 )
                {
                  _mm_store_si128((__m128i *)&pointInOut, (__m128i)v109);
                  if ( (unsigned __int8)hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(
                                          v90,
                                          &up,
                                          &pointInOut) )
                  {
                    v106 = pointInOut.m_quad;
                    closestPointOut.m_quad = pointInOut.m_quad;
                  }
                  else
                  {
                    if ( !LOBYTE(result.m_enum) )
                    {
                      hkaiNavMeshUtils::calcFacePlane(v90, &planeOut);
                      extraRadius.m_real = ::aabbOut.m_quad;
                      hkaiNavMeshUtils::calcFaceAabb(v90, &extraRadius, &aabbOut);
                      LOBYTE(result.m_enum) = 1;
                    }
                    v124 = _mm_mul_ps(up.m_quad, planeOut.m_quad);
                    v125 = _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                             _mm_shuffle_ps(v124, v124, 170));
                    v126 = _mm_mul_ps(closestPointOut.m_quad, planeOut.m_quad);
                    v127 = _mm_shuffle_ps(v126, _mm_unpackhi_ps(v126, planeOut.m_quad), 196);
                    v128 = _mm_add_ps(_mm_shuffle_ps(v127, v127, 78), v127);
                    v129 = _mm_add_ps(_mm_shuffle_ps(v128, v128, 177), v128);
                    v130 = _mm_rcp_ps(v125);
                    v106 = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v130, v125)), v130),
                                 _mm_sub_ps((__m128)0i64, v129)),
                               up.m_quad),
                             closestPointOut.m_quad);
                    if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v106, aabbOut.m_max.m_quad), _mm_cmpleps(aabbOut.m_min.m_quad, v106))) & 7) == 7 )
                    {
                      closestPointOut.m_quad = v106;
                    }
                    else
                    {
                      _mm_store_si128((__m128i *)&position, (__m128i)closestPointOut.m_quad);
                      hkaiNavMeshUtils::getClosestPointOnFace(v90, &position, &closestPointOut);
                      v106 = closestPointOut.m_quad;
                    }
                  }
                  v89 = v202;
                }
                else
                {
                  v111 = v90->m_data[v110].m_quad;
                  v112 = v90->m_data[(signed int)v110 + 1].m_quad;
                  v113 = _mm_mul_ps(up.m_quad, v111);
                  v114 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                           _mm_shuffle_ps(v113, v113, 170));
                  v115 = _mm_mul_ps(up.m_quad, v112);
                  v116 = _mm_sub_ps(v111, _mm_mul_ps(v114, up.m_quad));
                  v117 = _mm_sub_ps(
                           v116,
                           _mm_sub_ps(
                             v112,
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                                 _mm_shuffle_ps(v115, v115, 170)),
                               up.m_quad)));
                  v118 = _mm_mul_ps(_mm_sub_ps(v116, v109), v117);
                  v119 = _mm_mul_ps(v117, v117);
                  v120 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                           _mm_shuffle_ps(v119, v119, 170));
                  v121 = _mm_rcp_ps(v120);
                  v122 = _mm_mul_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v120, v121)), v121),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
                             _mm_shuffle_ps(v118, v118, 170)));
                  v123 = _mm_cmpltps(v122, query.m_quad);
                  v106 = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_sub_ps(v112, v111),
                             _mm_max_ps(
                               (__m128)0i64,
                               _mm_or_ps(_mm_andnot_ps(v123, query.m_quad), _mm_and_ps(v122, v123)))),
                           v111);
                  closestPointOut.m_quad = v106;
                }
              }
              else
              {
                v99 = _mm_cvtepi32_ps(_mm_loadl_epi64(v94 + 1));
                v100 = v234->m_data[(signed int)v95 - v93];
                v101 = v90->m_data;
                v102 = (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_shuffle_ps(v99, _mm_unpackhi_ps(v99, (__m128)0i64), 180),
                                   4),
                                 4);
                v103 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v102, v102, 0), v7->m_triangulator.m_localToWorld.m_col0.m_quad),
                             v7->m_triangulator.m_localToWorld.m_col3.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v102, v102, 85), v7->m_triangulator.m_localToWorld.m_col1.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v102, v102, 170), v7->m_triangulator.m_localToWorld.m_col2.m_quad));
                v104 = _mm_mul_ps(up.m_quad, v103);
                closestPointOut.m_quad = v103;
                v105 = _mm_mul_ps(v101[v100].m_quad, up.m_quad);
                v106 = _mm_add_ps(
                         v103,
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                               _mm_shuffle_ps(v105, v105, 170)),
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                               _mm_shuffle_ps(v104, v104, 170))),
                           up.m_quad));
                closestPointOut.m_quad = v106;
              }
              v131 = (__int64)v235;
              v224 += 16i64;
              *(__m128 *)(v224 - 16) = v106;
              *(_DWORD *)&array[v98] = (signed __int16)(*(_WORD *)(v131 + 8))++;
              v97 = array;
            }
            v132 = *(_DWORD *)&v97[v98];
            v133 = v209;
            v78 = v214;
            v214[v133] = v132;
            v209 = v133 + 1;
            v134 = getConnectivity(&v7->m_triangulator, v89);
            v135 = v134;
            if ( v134 == -1 )
            {
              v136 = 1;
            }
            else
            {
              v136 = 0;
              if ( v134 == -2 )
                v136 = 2;
            }
            v137 = v211;
            v138 = v136 | v96;
            v139 = (_BYTE *)(v91 + v211);
            if ( v139 )
              *v139 = v138;
            v211 = v137 + 1;
            if ( v136 == 2 )
            {
              v135 = -1;
              v140 = 0;
              if ( (signed int)v48 > 0 )
              {
                v141 = e;
                while ( (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)((char *)v141->m_triangle + v141->m_index) != (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)((v92->m_triangle->m_links[v92->m_index] & 0xFFFFFFFFFFFFFFFCui64) + (v92->m_triangle->m_links[v92->m_index] & 3)) )
                {
                  ++v140;
                  ++v141;
                  if ( v140 >= (signed int)v48 )
                    goto LABEL_135;
                }
                v135 = v140;
              }
            }
LABEL_135:
            v142 = v225;
            v143 = v202;
            ++v92;
            *v225 = v135;
            v89 = v143 + 1;
            v5 = v223-- == 1;
            v225 = v142 + 1;
            v202 = v89;
          }
          while ( !v5 );
          v50 = v194;
          LODWORD(v74) = v208;
          v86 = v212;
          v82 = (char *)p;
        }
        v144 = v201;
        *(_DWORD *)v50 = v74;
        v50 += 8;
        *((_DWORD *)v50 - 1) = v144;
        v194 = v50;
        v145 = v78;
        if ( (signed int)v74 > 0 )
        {
          v146 = (unsigned int)v74;
          do
          {
            v147 = *v145;
            v50 += 4;
            ++v145;
            *((_DWORD *)v50 - 1) = v147;
            --v146;
          }
          while ( v146 );
          v194 = v50;
        }
        v148 = (int *)v82;
        if ( (signed int)v74 > 0 )
        {
          v149 = (unsigned int)v74;
          do
          {
            v150 = *v148;
            v50 += 4;
            ++v148;
            *((_DWORD *)v50 - 1) = v150;
            --v149;
          }
          while ( v149 );
          v194 = v50;
        }
        v151 = v74 & 3;
        v152 = v86;
        v153 = (signed int)v74 / 4;
        if ( (signed int)v74 / 4 > 0 )
        {
          v154 = v153;
          do
          {
            v155 = *v152;
            v50 += 4;
            ++v152;
            *((_DWORD *)v50 - 1) = v155;
            --v154;
          }
          while ( v154 );
          v194 = v50;
        }
        v156 = (signed int)(4 * v153);
        if ( v151 > 0 )
        {
          LOBYTE(numEdges) = *((_BYTE *)v86 + v156);
          if ( v151 <= 1 )
            v157 = -1;
          else
            v157 = *((_BYTE *)v86 + v156 + 1);
          BYTE1(numEdges) = v157;
          if ( v151 <= 2 )
            v158 = -1;
          else
            v158 = *((_BYTE *)v86 + v156 + 2);
          BYTE2(numEdges) = v158;
          if ( v151 <= 3 )
            v159 = -1;
          else
            v159 = *((_BYTE *)v86 + v156 + 3);
          HIBYTE(numEdges) = v159;
          v50 += 4;
          *((_DWORD *)v50 - 1) = numEdges;
          v194 = v50;
        }
        v160 = (v74 + 127) & 0xFFFFFF80;
        v161 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v162 = (v160 + 15) & 0xFFFFFFF0;
        if ( v160 > v161->m_slabSize || (char *)v86 + v162 != v161->m_cur || v161->m_firstNonLifoEnd == v86 )
          hkLifoAllocator::slowBlockFree(v161, v86, v162);
        else
          v161->m_cur = v86;
        if ( v210 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v86,
            v210 & 0x3FFFFFFF);
        v163 = (4 * v74 + 127) & 0xFFFFFF80;
        v164 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v165 = p;
        v166 = (v163 + 15) & 0xFFFFFFF0;
        if ( v163 > v164->m_slabSize || (char *)p + v166 != v164->m_cur || v164->m_firstNonLifoEnd == p )
        {
          hkLifoAllocator::slowBlockFree(v164, p, v166);
          v165 = p;
        }
        else
        {
          v164->m_cur = p;
        }
        v167 = v210;
        if ( v210 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v165,
            4 * v210);
        v168 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v163 > v168->m_slabSize || (char *)v78 + v166 != v168->m_cur || v168->m_firstNonLifoEnd == v78 )
          hkLifoAllocator::slowBlockFree(v168, v78, v166);
        else
          v168->m_cur = v78;
        if ( v167 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v78,
            4 * v167);
        v73 = k + 1;
        v169 = pieceSize.m_data[k];
        k = v73;
        v72 = &v217[v169];
      }
      v170 = v204;
      v171 = (char *)v206;
      if ( v206 == v203 )
        v170 = 0;
      v204 = v170;
      v172 = (4 * v207 + 127) & 0xFFFFFF80;
      v173 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v174 = (v172 + 15) & 0xFFFFFFF0;
      if ( v172 > v173->m_slabSize || &v171[v174] != v173->m_cur || v173->m_firstNonLifoEnd == v171 )
        hkLifoAllocator::slowBlockFree(v173, v171, v174);
      else
        v173->m_cur = v171;
      v204 = 0;
      if ( v205 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v203,
          4 * v205);
    }
    v13 = 1;
    goto LABEL_192;
  }
  v13 = 0;
LABEL_215:
  v187 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v188 = (_QWORD *)v187[1];
  if ( (unsigned __int64)v188 < v187[3] )
  {
    *v188 = "lt";
    v189 = __rdtsc();
    v190 = (signed __int64)(v188 + 2);
    *(_DWORD *)(v190 - 8) = v189;
    v187[1] = v190;
  }
  return v13;
}188 + 2);
    *(_DWORD *)(v190 - 8) = v189;
    v187[1] = v190;
  }
  return v13;
}

// File Line: 835
// RVA: 0x12E9B90
void __fastcall hkaiFaceCutter::initTriangulatorForFace(hkaiFaceCutter *this, hkaiNavMeshInstance *origMesh, bool isWallClimbing, __int64 faceIndex, hkSimdFloat32 *regionExpansion, hkArrayBase<hkVector4f> *faceVerticesOut, hkArrayBase<int> *faceLoopVertexIndexRemap)
{
  bool v7; // bl
  hkaiFaceCutter *v8; // rsi
  int *v9; // r10
  hkVector4f v10; // xmm3
  hkVector4f v11; // xmm4
  __m128 v12; // xmm2
  hkVector4f v13; // xmm1
  int v14; // er8
  int v15; // [rsp+30h] [rbp-81h]
  int v16; // [rsp+34h] [rbp-7Dh]
  int v17; // [rsp+38h] [rbp-79h]
  int v18; // [rsp+3Ch] [rbp-75h]
  hkStridedVertices points; // [rsp+40h] [rbp-71h]
  hkAabb aabbOut; // [rsp+50h] [rbp-61h]
  __int128 v21; // [rsp+70h] [rbp-41h]
  __int128 v22; // [rsp+80h] [rbp-31h]
  __int128 v23; // [rsp+90h] [rbp-21h]
  __int128 v24; // [rsp+A0h] [rbp-11h]
  __int128 v25; // [rsp+B0h] [rbp-1h]
  __int128 v26; // [rsp+C0h] [rbp+Fh]
  __int128 v27; // [rsp+D0h] [rbp+1Fh]
  __int128 v28; // [rsp+E0h] [rbp+2Fh]

  v7 = isWallClimbing;
  v8 = this;
  v9 = &origMesh->m_originalFaces[(signed int)faceIndex].m_startEdgeIndex;
  v15 = *v9;
  v16 = v9[1];
  v17 = v9[2];
  v18 = v9[3];
  faceVerticesOut->m_size = (signed __int16)v17 + 1;
  hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)origMesh,
    (hkaiNavMeshInstance *)&v15,
    (hkaiNavMesh::Face *)faceVerticesOut,
    (hkArrayBase<hkVector4f> *)faceIndex);
  if ( v7 )
    hkaiNavMeshUtils::calcFacePlane(faceVerticesOut, &v8->m_up);
  hkaiNavMeshUtils::calcFaceAabb(faceVerticesOut, regionExpansion, &aabbOut);
  v10.m_quad = (__m128)aabbOut.m_max;
  v11.m_quad = (__m128)aabbOut.m_min;
  v12 = _mm_andnot_ps((__m128)xmmword_141C1C0F0, aabbOut.m_max.m_quad);
  v13.m_quad = (__m128)aabbOut.m_max;
  points.m_vertices = (const float *)&v21;
  points.m_numVertices = 8;
  v13.m_quad.m128_f32[0] = aabbOut.m_min.m_quad.m128_f32[0];
  points.m_striding = 16;
  _mm_store_si128((__m128i *)&v21, _mm_srli_si128(_mm_slli_si128((__m128i)aabbOut.m_max.m_quad, 4), 4));
  _mm_store_si128((__m128i *)&v22, _mm_srli_si128(_mm_slli_si128((__m128i)v13.m_quad, 4), 4));
  _mm_store_si128(
    (__m128i *)&v23,
    _mm_srli_si128(_mm_slli_si128((__m128i)_mm_or_ps(v12, _mm_and_ps(v11.m_quad, (__m128)xmmword_141C1C0F0)), 4), 4));
  _mm_store_si128(
    (__m128i *)&v24,
    _mm_srli_si128(_mm_slli_si128((__m128i)_mm_shuffle_ps(v11.m_quad, v10.m_quad, 228), 4), 4));
  _mm_store_si128(
    (__m128i *)&v25,
    _mm_srli_si128(
      _mm_slli_si128(
        (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141C1C110, v10.m_quad),
                   _mm_and_ps(v11.m_quad, (__m128)xmmword_141C1C110)),
        4),
      4));
  _mm_store_si128(
    (__m128i *)&v26,
    _mm_srli_si128(
      _mm_slli_si128(
        (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141C1C120, v10.m_quad),
                   _mm_and_ps(v11.m_quad, (__m128)xmmword_141C1C120)),
        4),
      4));
  _mm_store_si128(
    (__m128i *)&v27,
    _mm_srli_si128(
      _mm_slli_si128(
        (__m128i)_mm_or_ps(
                   _mm_andnot_ps((__m128)xmmword_141C1C130, v10.m_quad),
                   _mm_and_ps(v11.m_quad, (__m128)xmmword_141C1C130)),
        4),
      4));
  _mm_store_si128(
    (__m128i *)&v28,
    _mm_srli_si128(
      _mm_slli_si128((__m128i)_mm_shuffle_ps(v11.m_quad, _mm_unpackhi_ps(v11.m_quad, v10.m_quad), 196), 4),
      4));
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::setDomainFromPlanarPoints(
    &v8->m_triangulator,
    &points,
    &v8->m_up,
    1,
    1,
    0);
  v14 = (signed __int16)v17;
  v8->m_initialNumVertsT = v8->m_triangulator.m_mesh.m_vertices.m_numUsed;
  hkaiFaceCutter::triangulatorAddLoop(v8, faceVerticesOut->m_data, v14, 0, 0, faceLoopVertexIndexRemap);
  v8->m_lastFaceVertIndexT = v8->m_triangulator.m_mesh.m_vertices.m_numUsed - 1;
}texIndexRem

// File Line: 876
// RVA: 0x12E9890
void __fastcall hkaiFaceCutter::setFace(hkaiFaceCutter *this, hkaiNavMeshInstance *origMesh, hkVector4f *worldUp, bool isWallClimbing, unsigned int faceKey, hkSimdFloat32 *regionExpansion, hkArrayBase<hkVector4f> *faceVertsOut, hkArrayBase<int> *faceLoopVertexIndexRemap)
{
  hkaiNavMeshInstance *v8; // rsi
  bool v9; // bp
  hkVector4f *v10; // rbx
  hkaiFaceCutter *v11; // r14
  hkVector4f *v12; // rdx
  __int64 v13; // r9
  int v14; // ST20_4
  hkVector4f segB; // [rsp+40h] [rbp-38h]
  hkVector4f segA; // [rsp+50h] [rbp-28h]

  v8 = origMesh;
  v9 = isWallClimbing;
  v10 = worldUp;
  v11 = this;
  hkaiFaceCutter::reset(this, faceKey);
  v11->m_up = (hkVector4f)v10->m_quad;
  hkaiFaceCutter::initTriangulatorForFace(
    v11,
    v8,
    v9,
    faceKey & 0x3FFFFF,
    regionExpansion,
    faceVertsOut,
    faceLoopVertexIndexRemap);
  if ( v11->m_lastFaceVertIndexT - v11->m_initialNumVertsT == 1 )
  {
    v12 = faceVertsOut->m_data;
    v13 = v11->m_firstSuccessfulEdge;
    _mm_store_si128((__m128i *)&segA, (__m128i)faceVertsOut->m_data[v13].m_quad);
    v14 = v11->m_firstDuplicateEdge;
    _mm_store_si128((__m128i *)&segB, (__m128i)v12[v13 + 1].m_quad);
    hkaiDegenerateFaceCutter::setSegment(&v11->m_degenerateFaceCutter, &segA, &segB, v13, v14, &v11->m_up);
  }
}

// File Line: 896
// RVA: 0x12E99A0
unsigned int __fastcall hkaiFaceCutter::addSilhouette(hkaiFaceCutter *this, hkVector4f *points, int loopSize, int material)
{
  int v4; // ebx
  hkVector4f *v5; // rdi
  hkaiFaceCutter *v6; // r10
  int materialIndex; // er8
  __int64 v8; // r11
  int v9; // edx
  __int64 v10; // rcx
  int *v11; // rax
  signed int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // eax
  unsigned int result; // eax

  v4 = loopSize;
  v5 = points;
  v6 = this;
  if ( this->m_faceIsCrossing )
    goto LABEL_18;
  materialIndex = -1;
  if ( material != -1 )
  {
    v8 = this->m_materialsUsed.m_size;
    v9 = 0;
    v10 = 0i64;
    if ( v8 <= 0 )
      goto LABEL_9;
    v11 = v6->m_materialsUsed.m_data;
    while ( *v11 != material )
    {
      ++v10;
      ++v9;
      ++v11;
      if ( v10 >= v8 )
        goto LABEL_9;
    }
    materialIndex = v9;
    if ( v9 == -1 )
    {
LABEL_9:
      v12 = v6->m_materialsUsed.m_size;
      if ( v12 < 14 )
      {
        materialIndex = v6->m_materialsUsed.m_size;
        v6->m_materialsUsed.m_data[v12] = material;
        ++v6->m_materialsUsed.m_size;
      }
    }
  }
  v13 = v6->m_lastFaceVertIndexT - v6->m_initialNumVertsT;
  ++v6->m_numSilhouettesAdded;
  v14 = (materialIndex == -1) + 1;
  v15 = v13 + 1;
  if ( v15 > 2 )
    return hkaiFaceCutter::triangulatorAddLoop(v6, v5, v4, (hkaiFaceCutter::LoopType)v14, materialIndex, 0i64);
  if ( v15 != 2 )
LABEL_18:
    result = 1;
  else
    result = hkaiDegenerateFaceCutter::addSilhouette(
               &v6->m_degenerateFaceCutter,
               v5,
               v4,
               (hkaiDegenerateFaceCutter::IntervalType)v14,
               materialIndex,
               &v6->m_up);
  return result;
}

// File Line: 934
// RVA: 0x12E9AC0
unsigned int __fastcall hkaiFaceCutter::computeConvexDecomposition(hkaiFaceCutter *this, hkaiFaceCutResults *results, hkArrayBase<hkVector4f> *faceVertices, hkArrayBase<int> *faceLoopVertexRemap)
{
  hkArrayBase<int> *v4; // r11
  int v5; // er9
  unsigned int result; // eax

  v4 = faceLoopVertexRemap;
  if ( this->m_numSilhouettesAdded && (v5 = this->m_lastFaceVertIndexT - this->m_initialNumVertsT + 1, v5 <= 2) )
    result = hkaiDegenerateFaceCutter::computeConvexDecomposition(
               &this->m_degenerateFaceCutter,
               results,
               this->m_faceKey,
               v5);
  else
    result = hkaiFaceCutter::computeConvexDecompositionOfCutFace(this, faceVertices, v4, results);
  return result;
}

// File Line: 946
// RVA: 0x12E9B20
void __fastcall hkaiFaceCutter::reset(hkaiFaceCutter *this, unsigned int faceKey)
{
  unsigned int v2; // ebx
  hkaiFaceCutter *v3; // rdi

  v2 = faceKey;
  v3 = this;
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::reset(
    &this->m_triangulator,
    1);
  hkaiDegenerateFaceCutter::reset(&v3->m_degenerateFaceCutter);
  v3->m_faceKey = v2;
  v3->m_materialsUsed.m_size = 0;
  v3->m_numSilhouettesAdded = 0;
  v3->m_faceIsCrossing = 0;
  *(_QWORD *)&v3->m_lastFaceVertIndexT = -1i64;
  *(_QWORD *)&v3->m_firstSuccessfulEdge = -1i64;
}

