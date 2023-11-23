// File Line: 17
// RVA: 0x15DEFF0
__int64 dynamic_initializer_for__s_nullAllocator__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__s_nullAllocator__);
}

// File Line: 19
// RVA: 0x12E9880
hkNullAllocator *__fastcall hkNullAllocator::getInstance()
{
  return &s_nullAllocator;
}

// File Line: 126
// RVA: 0x12E9DB0
__int64 __fastcall hkaiFaceCutter::triangulatorAddLoop(
        hkaiFaceCutter *this,
        hkVector4f *points,
        int loopSize,
        hkaiFaceCutter::LoopType loopType,
        int materialIndex,
        hkArrayBase<int> *vertexRemap)
{
  char v6; // si
  int v7; // r13d
  int v9; // edi
  int v10; // r14d
  hkLifoAllocator *Value; // rax
  char *m_cur; // r15
  int v13; // edx
  char *v14; // rcx
  __int64 v15; // rax
  int m_margin; // edi
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
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *inserted; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_triangle; // r8
  __int64 v29; // r9
  unsigned int v30; // ebx
  char *v31; // rdx
  __int64 v32; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v33; // rdx
  int *v34; // rsi
  int v35; // r12d
  int v36; // r8d
  unsigned int v37; // eax
  int v38; // r9d
  int m_firstSuccessfulEdge; // eax
  int m_firstDuplicateEdge; // eax
  signed int v41; // r13d
  hkLifoAllocator *v42; // rcx
  int v43; // r8d
  int data; // [rsp+40h] [rbp-69h]
  hkaiRuntimeTriangulatorEdgeData v46; // [rsp+48h] [rbp-61h] BYREF
  int v47; // [rsp+50h] [rbp-59h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion icrossing; // [rsp+58h] [rbp-51h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Location result; // [rsp+70h] [rbp-39h] BYREF
  __int64 v50; // [rsp+A0h] [rbp-9h]
  hkVector4f *retaddr; // [rsp+108h] [rbp+5Fh]
  char v52; // [rsp+110h] [rbp+67h]
  int v53; // [rsp+118h] [rbp+6Fh]
  char v54; // [rsp+120h] [rbp+77h]
  __int64 v55; // [rsp+128h] [rbp+7Fh]

  LODWORD(v55) = loopType;
  v53 = (int)points;
  v7 = loopSize;
  if ( loopType && _mm_movemask_ps(_mm_cmpeq_ps(points[loopSize - 1].m_quad, points->m_quad)) == 15 )
    v7 = loopSize - 1;
  v9 = 0;
  v10 = 0;
  if ( v7 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v13 = (32 * v7 + 127) & 0xFFFFFF80;
    v14 = &m_cur[v13];
    if ( v13 > Value->m_slabSize || v14 > Value->m_end )
    {
      v15 = hkLifoAllocator::allocateFromNewSlab(Value, v13);
      points = retaddr;
      m_cur = (char *)v15;
    }
    else
    {
      points = retaddr;
      Value->m_cur = v14;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  v52 = v6;
  data = 0;
  v47 = v7 | 0x80000000;
  v46 = 0i64;
  if ( v7 > 0 )
  {
    do
    {
      m_margin = this->m_triangulator.m_margin;
      v17 = 0x7FFF - m_margin;
      v18 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(points->m_quad, points->m_quad, 0),
                    this->m_triangulator.m_worldToLocal.m_col0.m_quad),
                  this->m_triangulator.m_worldToLocal.m_col3.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(points->m_quad, points->m_quad, 85),
                  this->m_triangulator.m_worldToLocal.m_col1.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(points->m_quad, points->m_quad, 170),
                this->m_triangulator.m_worldToLocal.m_col2.m_quad));
      v19 = _mm_sub_ps(v18, (__m128)xmmword_141A711B0);
      v20 = _mm_add_ps(v18, (__m128)xmmword_141A711B0);
      v21 = _mm_cmplt_ps(v18, (__m128)0i64);
      v22 = _mm_or_ps(_mm_andnot_ps(v21, v20), _mm_and_ps(v19, v21));
      v23 = _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v22),
              _mm_cvttps_epi32(v22));
      v24 = _mm_cvtsi128_si32(v23);
      if ( v24 >= m_margin )
      {
        if ( v24 > v17 )
          v24 = 0x7FFF - m_margin;
      }
      else
      {
        v24 = this->m_triangulator.m_margin;
      }
      v25 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v23, 85));
      if ( v25 >= m_margin )
      {
        m_margin = v25;
        if ( v25 > v17 )
          m_margin = v17;
      }
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::locateVertex(
        &this->m_triangulator,
        &result,
        v24,
        m_margin);
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertVertex(
        &this->m_triangulator,
        &icrossing,
        v24,
        m_margin,
        1,
        &result,
        0);
      LODWORD(v26) = icrossing.m_type.m_storage;
      if ( icrossing.m_type.m_storage == 2 )
      {
        result.m_edge = icrossing.m_edge;
        result.m_type.m_storage = 1;
        inserted = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertVertex(
                     &this->m_triangulator,
                     &icrossing,
                     v24,
                     m_margin,
                     1,
                     &result,
                     1);
        v26 = *(_QWORD *)&inserted->m_type.m_storage;
        m_triangle = inserted->m_edge.m_triangle;
        v29 = *(_QWORD *)&inserted->m_edge.m_index;
      }
      else
      {
        LODWORD(v29) = icrossing.m_edge.m_index;
        m_triangle = icrossing.m_edge.m_triangle;
      }
      if ( (unsigned int)v26 <= 1 )
      {
        v31 = &m_cur[32 * v10];
        if ( v31 )
        {
          v32 = v50;
          *((_DWORD *)v31 + 4) = v24;
          *((_DWORD *)v31 + 5) = m_margin;
          *((_QWORD *)v31 + 3) = v32;
        }
        ++v10;
        if ( !(_DWORD)v26 )
        {
          v33 = m_triangle->m_vertices[(int)v29];
          *((_QWORD *)v33 + 3) = *((_DWORD *)v33 + 6) & 3 | (unsigned __int64)(4i64
                                                                             * (this->m_triangulator.m_mesh.m_vertices.m_numUsed
                                                                              - 1));
          if ( v52 )
            *(_DWORD *)(*(_QWORD *)v55 + 4i64 * (int)(*(_DWORD *)(v55 + 8))++) = data;
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
    while ( *(__int64 *)&v46 < v7 );
    v9 = 0;
  }
  if ( v10 > 0 )
  {
    v34 = (int *)(m_cur + 16);
    do
    {
      v35 = v9 + 1;
      *(_QWORD *)&icrossing.m_type.m_storage = this;
      LOBYTE(icrossing.m_edge.m_triangle) = 0;
      if ( v53 )
      {
        if ( v53 == 2 )
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
        &this->m_triangulator,
        (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *)&result,
        *v34,
        v38,
        *(_DWORD *)&m_cur[32 * ((v9 + 1) % v10) + 16],
        *(_DWORD *)&m_cur[32 * ((v9 + 1) % v10) + 20],
        1,
        (NavMeshCutterCutterEdgeCrossing *)&icrossing,
        &v46);
      if ( result.m_type.m_storage )
      {
        if ( result.m_type.m_storage == 10 )
          goto LABEL_23;
        if ( result.m_type.m_storage == 1 )
        {
          m_firstDuplicateEdge = this->m_firstDuplicateEdge;
          if ( m_firstDuplicateEdge == -1 )
            m_firstDuplicateEdge = v9;
          this->m_firstDuplicateEdge = m_firstDuplicateEdge;
        }
      }
      else
      {
        m_firstSuccessfulEdge = this->m_firstSuccessfulEdge;
        if ( m_firstSuccessfulEdge == -1 )
          m_firstSuccessfulEdge = v9;
        this->m_firstSuccessfulEdge = m_firstSuccessfulEdge;
      }
      if ( v52 && LOBYTE(icrossing.m_edge.m_triangle) )
        this->m_faceIsCrossing = 1;
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
  if ( v41 > v42->m_slabSize || &m_cur[v43] != v42->m_cur || v42->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v42, m_cur, v43);
  else
    v42->m_cur = m_cur;
  if ( v47 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 32 * v47);
  return v30;
}

// File Line: 231
// RVA: 0x12EB3B0
__int64 __fastcall getConnectivity(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *triangulator,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *e)
{
  __int64 m_index; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_triangle; // rbp
  unsigned __int64 v5; // rbx
  char v6; // r15
  hkaiRuntimeTriangulatorEdgeData *EdgeData; // rax
  hkaiRuntimeTriangulatorEdgeData *v8; // r14
  int m_tag; // eax
  hkaiRuntimeTriangulatorEdgeData *v11; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v12; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v13; // rdx
  int m_x; // eax
  int v15; // ecx
  unsigned __int64 v16; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edge; // [rsp+20h] [rbp-38h] BYREF

  m_index = (int)e->m_index;
  m_triangle = e->m_triangle;
  v5 = e->m_triangle->m_links[m_index];
  v6 = 0;
  edge.m_index = v5 & 3;
  edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)(v5 & 0xFFFFFFFFFFFFFFFCui64);
  if ( (*(_BYTE *)((v5 & 0xFFFFFFFFFFFFFFFCui64) + 100) & 0x20) == 0 )
    v6 = 1;
  EdgeData = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
               triangulator,
               e);
  v8 = EdgeData;
  if ( EdgeData )
  {
    m_tag = EdgeData->m_tag;
    if ( m_tag == -1 || (v8->m_sets & 0x8000) != 0 || v6 && m_tag == -2 )
      return 0xFFFFFFFFi64;
  }
  v11 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
          triangulator,
          &edge);
  if ( v11 )
  {
    if ( v11->m_tag == -1 || (v11->m_sets & 0x8000) != 0 || v6 && v11->m_tag == -2 )
      return 0xFFFFFFFFi64;
  }
  if ( v8 )
    return (unsigned int)v8->m_tag;
  if ( v11 )
    return (unsigned int)v11->m_tag;
  v12 = m_triangle->m_vertices[m_index];
  v13 = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
  m_x = v12->m_x;
  v15 = v13->m_x;
  if ( m_x >= v15 && (m_x > v15 || v12->m_y > v13->m_y) && (v5 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    LOBYTE(m_index) = v5 & 3;
    v16 = v5 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v16 = (unsigned __int64)m_triangle;
  }
  return (unsigned int)((*(_BYTE *)(v16 + 100) & (unsigned __int8)(1 << m_index) & 7) != 0) - 2;
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
  unsigned int v2; // r8d
  __int64 result; // rax

  v1 = 32;
  v2 = x & -x;
  if ( v2 )
    v1 = 31;
  if ( (_WORD)v2 )
    v1 -= 16;
  if ( (v2 & 0xFF00FF) != 0 )
    v1 -= 8;
  if ( (v2 & 0xF0F0F0F) != 0 )
    v1 -= 4;
  if ( (v2 & 0x33333333) != 0 )
    v1 -= 2;
  result = v1 - 1;
  if ( (v2 & 0x55555555) == 0 )
    return v1;
  return result;
}

// File Line: 365
// RVA: 0x12EA230
__int64 __fastcall hkaiFaceCutter::computeConvexDecompositionOfCutFace(
        hkaiFaceCutter *this,
        hkArrayBase<hkVector4f> *faceVertices,
        hkArrayBase<int> *faceLoopVertexIndexRemap,
        hkaiFaceCutResults *resultsInMainMem)
{
  __m128 m_quad; // xmm0
  _QWORD *Value; // rdi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *i; // rax
  unsigned int v12; // esi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *j; // rdi
  unsigned __int16 m_sets; // ax
  __int16 v15; // ax
  __int16 v16; // r9
  _QWORD *v17; // rdi
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  int m_numUsed; // edi
  int v22; // r14d
  hkLifoAllocator *v23; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *m_cur; // rbx
  int v25; // edx
  char *v26; // rcx
  hkLifoAllocator *v27; // rcx
  unsigned int *v28; // rax
  int v29; // edx
  char *v30; // r8
  int v31; // ebx
  _QWORD *v32; // rdi
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  int v36; // eax
  hkLifoAllocator *v37; // rax
  char *v38; // rdx
  int v39; // ecx
  char *v40; // rdi
  int v41; // ecx
  int v42; // r9d
  __int64 v43; // rcx
  char *v44; // rdi
  __int64 v45; // r12
  char *v46; // rax
  char *v47; // rbx
  int m_numEdges; // eax
  int m_numPolys; // ecx
  int v50; // ecx
  hkLifoAllocator *v51; // rax
  char *v52; // rdi
  int v53; // edx
  char *v54; // rcx
  char *v55; // rax
  int v56; // r15d
  int v57; // r9d
  int v58; // edx
  char *v59; // rdi
  __int64 v60; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v61; // r15
  __int64 v62; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v63; // rdi
  int Connectivity; // r9d
  int v65; // eax
  int v66; // r8d
  __int64 v67; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v68; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v69; // rdx
  __int64 v70; // rcx
  __int64 v71; // r13
  unsigned int v72; // ecx
  __int64 v73; // rcx
  hkLifoAllocator *v74; // rax
  char *v75; // r15
  int v76; // edx
  char *v77; // rcx
  hkLifoAllocator *v78; // rax
  char *v79; // rdi
  int v80; // edx
  char *v81; // rcx
  hkLifoAllocator *v82; // rax
  char *v83; // r14
  int v84; // edx
  char *v85; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v86; // r10
  hkArrayBase<hkVector4f> *v87; // rbx
  __int64 v88; // r13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v89; // r14
  __int64 m_initialNumVertsT; // rdx
  const __m128i *v91; // r9
  unsigned __int64 v92; // rax
  int v93; // edi
  char *v94; // rcx
  __int64 v95; // r15
  __m128 v96; // xmm2
  __int64 v97; // rcx
  hkVector4f *m_data; // rax
  __m128 v99; // xmm2
  __m128 v100; // xmm6
  __m128 v101; // xmm1
  __m128 v102; // xmm3
  __m128 v103; // xmm6
  __m128 v104; // xmm2
  __m128 v105; // xmm2
  __m128 v106; // xmm7
  __int64 v107; // rax
  __m128 v108; // xmm5
  __m128 v109; // xmm6
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm4
  __m128 v114; // xmm3
  __m128 v115; // xmm4
  __m128 v116; // xmm1
  __m128 v117; // xmm2
  __m128 v118; // xmm0
  __m128 v119; // xmm3
  __m128 v120; // xmm1
  __m128 v121; // xmm1
  __m128 v122; // xmm4
  __m128 v123; // xmm2
  __m128 v124; // xmm2
  __m128 v125; // xmm1
  __m128 v126; // xmm0
  __m128 v127; // xmm1
  __int64 v128; // rdx
  int v129; // ecx
  int v130; // edx
  int v131; // eax
  int v132; // r8d
  int v133; // ecx
  int v134; // r11d
  char v135; // di
  _BYTE *v136; // rdx
  int v137; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v138; // rcx
  int *v139; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v140; // r10
  bool v141; // zf
  int v142; // eax
  char *v143; // rcx
  __int64 v144; // rdx
  int v145; // eax
  int *v146; // rcx
  __int64 v147; // rdx
  int v148; // eax
  char *v149; // rdx
  unsigned int v150; // eax
  __int64 v151; // rdi
  int v152; // ecx
  __int64 v153; // rcx
  char v154; // al
  char v155; // al
  char v156; // al
  int v157; // edi
  hkLifoAllocator *v158; // rax
  int v159; // r8d
  int v160; // r13d
  hkLifoAllocator *v161; // rax
  void *v162; // rdx
  int v163; // edi
  int v164; // r14d
  hkLifoAllocator *v165; // rax
  __int64 v166; // rax
  int v167; // eax
  char *v168; // rbx
  signed int v169; // edi
  hkLifoAllocator *v170; // rax
  int v171; // r8d
  int v172; // eax
  char *v173; // rbx
  signed int v174; // edi
  hkLifoAllocator *v175; // rax
  int v176; // r8d
  signed int v177; // edi
  hkLifoAllocator *v178; // rax
  int v179; // r8d
  signed int v180; // edi
  hkLifoAllocator *v181; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v182; // rdx
  int v183; // r8d
  _QWORD *v184; // rdi
  _QWORD *v185; // rcx
  unsigned __int64 v186; // rax
  _QWORD *v187; // rcx
  int numEdges; // [rsp+30h] [rbp-D0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *e; // [rsp+38h] [rbp-C8h]
  int v190; // [rsp+40h] [rbp-C0h]
  char *v191; // [rsp+48h] [rbp-B8h]
  void *p; // [rsp+50h] [rbp-B0h]
  char *array; // [rsp+58h] [rbp-A8h] BYREF
  int v194; // [rsp+60h] [rbp-A0h]
  int v195; // [rsp+64h] [rbp-9Ch]
  void *v196; // [rsp+68h] [rbp-98h]
  int v197; // [rsp+70h] [rbp-90h]
  int v198; // [rsp+78h] [rbp-88h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v199; // [rsp+80h] [rbp-80h]
  char *v200; // [rsp+88h] [rbp-78h] BYREF
  int v201; // [rsp+90h] [rbp-70h]
  int v202; // [rsp+94h] [rbp-6Ch]
  void *v203; // [rsp+98h] [rbp-68h]
  int v204; // [rsp+A0h] [rbp-60h]
  hkResult v205; // [rsp+A8h] [rbp-58h] BYREF
  int v206; // [rsp+ACh] [rbp-54h]
  int v207; // [rsp+B0h] [rbp-50h]
  int v208; // [rsp+B4h] [rbp-4Ch]
  char *v209; // [rsp+B8h] [rbp-48h]
  hkVector4f closestPointOut; // [rsp+C0h] [rbp-40h] BYREF
  char *v211; // [rsp+D0h] [rbp-30h]
  int v212; // [rsp+D8h] [rbp-28h]
  int v213; // [rsp+DCh] [rbp-24h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v214; // [rsp+E0h] [rbp-20h]
  int v215; // [rsp+E8h] [rbp-18h]
  hkArrayBase<unsigned int> pieceSize; // [rsp+F0h] [rbp-10h] BYREF
  void *v217; // [rsp+100h] [rbp+0h]
  int v218; // [rsp+108h] [rbp+8h]
  __int64 k; // [rsp+110h] [rbp+10h]
  __int64 v220; // [rsp+118h] [rbp+18h]
  char *v221; // [rsp+120h] [rbp+20h]
  int *v222; // [rsp+128h] [rbp+28h]
  hkVector4f up; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f pointInOut; // [rsp+140h] [rbp+40h] BYREF
  hkVector4f planeOut; // [rsp+150h] [rbp+50h] BYREF
  hkAabb aabbOut; // [rsp+160h] [rbp+60h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+180h] [rbp+80h] BYREF
  hkVector4f position; // [rsp+190h] [rbp+90h] BYREF
  hkResult result; // [rsp+220h] [rbp+120h] BYREF
  hkArrayBase<hkVector4f> *facePoints; // [rsp+228h] [rbp+128h]
  hkArrayBase<int> *v231; // [rsp+230h] [rbp+130h]
  hkaiFaceCutResults *v232; // [rsp+238h] [rbp+138h]

  v232 = resultsInMainMem;
  v231 = faceLoopVertexIndexRemap;
  facePoints = faceVertices;
  m_quad = this->m_up.m_quad;
  resultsInMainMem->m_originalFace = this->m_faceKey;
  up.m_quad = m_quad;
  if ( !HK_flyingcolors_ai_2.m_bool )
  {
    hkaiCheckKeycode();
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_2);
    if ( !HK_flyingcolors_ai_2.m_bool )
      this->m_numSilhouettesAdded = 0;
  }
  if ( !this->m_numSilhouettesAdded )
  {
    resultsInMainMem->m_flags.m_storage |= 1u;
    return 1i64;
  }
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtcomputeCxDecompOfCutFace";
    *(_QWORD *)(v9 + 16) = "StRegionFlood";
    v10 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v10;
    Value[1] = v9 + 24;
  }
  for ( i = this->m_triangulator.m_mesh.m_triangles.m_used; i; i = i->m_next )
    i->m_sets = 0;
  if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::floodEdgeSets<FloodPolicyCell>(
         &this->m_triangulator,
         (FloodPolicyCell *)&result) )
  {
    for ( j = this->m_triangulator.m_mesh.m_triangles.m_used; j; j = j->m_next )
    {
      m_sets = j->m_sets;
      if ( (m_sets & 0x8000) == 0 && m_sets && (m_sets & 1) != 0 )
      {
        *((_WORD *)j + 50) &= 0x1Fu;
        if ( m_sets == 1 )
        {
          *((_WORD *)j + 50) |= 0x20u;
        }
        else
        {
          v15 = leastSignificantBit(m_sets >> 1);
          *((_WORD *)j + 50) |= v16 & ((v15 << 6) + 64) | 0x20;
        }
      }
      else
      {
        *((_WORD *)j + 50) &= 0x1Fu;
      }
    }
    v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v18 = (_QWORD *)v17[1];
    if ( (unsigned __int64)v18 < v17[3] )
    {
      *v18 = "StTriangle merge to convex";
      v19 = __rdtsc();
      v20 = v18 + 2;
      *((_DWORD *)v20 - 2) = v19;
      v17[1] = v20;
    }
    m_numUsed = this->m_triangulator.m_mesh.m_triangles.m_numUsed;
    v22 = this->m_triangulator.m_mesh.m_vertices.m_numUsed;
    v212 = 3 * m_numUsed;
    if ( 3 * m_numUsed )
    {
      v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)v23->m_cur;
      e = m_cur;
      v25 = (48 * m_numUsed + 127) & 0xFFFFFF80;
      v26 = (char *)m_cur + v25;
      if ( v25 > v23->m_slabSize || v26 > v23->m_end )
      {
        m_cur = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
        e = m_cur;
      }
      else
      {
        v23->m_cur = v26;
      }
    }
    else
    {
      m_cur = 0i64;
      e = 0i64;
    }
    pieceSize.m_size = 0;
    v218 = m_numUsed;
    v215 = (3 * m_numUsed) | 0x80000000;
    if ( m_numUsed )
    {
      v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v28 = (unsigned int *)v27->m_cur;
      v29 = (4 * m_numUsed + 127) & 0xFFFFFF80;
      v30 = (char *)v28 + v29;
      if ( v29 > v27->m_slabSize || v30 > v27->m_end )
        v28 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v27, v29);
      else
        v27->m_cur = v30;
    }
    else
    {
      v28 = 0i64;
    }
    pieceSize.m_data = v28;
    v217 = v28;
    numEdges = 0;
    result.m_enum = -1;
    pieceSize.m_capacityAndFlags = m_numUsed | 0x80000000;
    v213 = (3 * m_numUsed) & 0x3FFFFFFF;
    v31 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::decomposeFastFixedSize(
            &this->m_triangulator,
            &pieceSize,
            m_cur,
            v213,
            &numEdges,
            (int *)&result);
    v190 = v31;
    v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v33 = (_QWORD *)v32[1];
    if ( (unsigned __int64)v33 < v32[3] )
    {
      *v33 = "StConvex piece extract";
      v34 = __rdtsc();
      v35 = v33 + 2;
      *((_DWORD *)v35 - 2) = v34;
      v32[1] = v35;
    }
    v36 = 0;
    array = 0i64;
    v195 = 0x80000000;
    v197 = v22;
    v194 = 0;
    if ( v22 )
    {
      v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (char *)v37->m_cur;
      v39 = (4 * v22 + 127) & 0xFFFFFF80;
      v40 = &v38[v39];
      if ( v39 > v37->m_slabSize || v40 > v37->m_end )
      {
        v38 = (char *)hkLifoAllocator::allocateFromNewSlab(v37, v39);
        v36 = v194;
      }
      else
      {
        v37->m_cur = v40;
        v36 = v194;
      }
    }
    else
    {
      v38 = 0i64;
    }
    array = v38;
    v196 = v38;
    v195 = v22 | 0x80000000;
    v41 = v22 & 0x3FFFFFFF;
    if ( (v22 & 0x3FFFFFFF) < v22 )
    {
      v42 = v22;
      if ( v22 < 2 * v41 )
        v42 = 2 * v41;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v42, 4);
      v36 = v194;
      v38 = array;
    }
    v43 = v22 - v36;
    v44 = &v38[4 * v36];
    if ( v43 > 0 )
    {
      while ( v43 )
      {
        *(_DWORD *)v44 = -1;
        v44 += 4;
        --v43;
      }
    }
    v45 = (unsigned int)numEdges;
    v194 = v22;
    v46 = hkaiFaceCutResults::init(resultsInMainMem, v31, numEdges);
    LOBYTE(result.m_enum) = 0;
    planeOut.m_quad = 0i64;
    aabbOut.m_min = (hkVector4f)xmmword_141A712A0;
    v47 = v46;
    v191 = v46;
    aabbOut.m_max.m_quad = _mm_xor_ps(
                             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                             (__m128)xmmword_141A712A0);
    if ( v190 )
    {
      if ( !v46 )
      {
        v12 = 0;
LABEL_192:
        v172 = v194;
        v173 = (char *)v196;
        if ( v196 == array )
          v172 = 0;
        v194 = v172;
        v174 = (4 * v197 + 127) & 0xFFFFFF80;
        v175 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v176 = (v174 + 15) & 0xFFFFFFF0;
        if ( v174 > v175->m_slabSize || &v173[v176] != v175->m_cur || v175->m_firstNonLifoEnd == v173 )
          hkLifoAllocator::slowBlockFree(v175, v173, v176);
        else
          v175->m_cur = v173;
        v194 = 0;
        if ( v195 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v195);
        array = 0i64;
        v195 = 0x80000000;
        v177 = (4 * v218 + 127) & 0xFFFFFF80;
        v178 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v179 = (v177 + 15) & 0xFFFFFFF0;
        if ( v177 > v178->m_slabSize || (char *)v217 + v179 != v178->m_cur || v178->m_firstNonLifoEnd == v217 )
          hkLifoAllocator::slowBlockFree(v178, (char *)v217, v179);
        else
          v178->m_cur = v217;
        if ( pieceSize.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            pieceSize.m_data,
            4 * pieceSize.m_capacityAndFlags);
        v180 = (16 * v212 + 127) & 0xFFFFFF80;
        v181 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v182 = e;
        v183 = (v180 + 15) & 0xFFFFFFF0;
        if ( v180 > v181->m_slabSize || (char *)e + v183 != v181->m_cur || v181->m_firstNonLifoEnd == e )
        {
          hkLifoAllocator::slowBlockFree(v181, (char *)e, v183);
          v182 = e;
        }
        else
        {
          v181->m_cur = e;
        }
        if ( v215 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v182, 16 * v213);
        goto LABEL_215;
      }
      m_numEdges = resultsInMainMem->m_numEdges;
      m_numPolys = resultsInMainMem->m_numPolys;
      v202 = 0x80000000;
      v204 = v22;
      v221 = &resultsInMainMem->m_data[(11 * m_numPolys + 9 * m_numEdges + 15i64) & 0xFFFFFFFFFFFFFFF0ui64];
      v200 = 0i64;
      v50 = 0;
      v201 = 0;
      if ( v22 )
      {
        v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v52 = (char *)v51->m_cur;
        v53 = (4 * v22 + 127) & 0xFFFFFF80;
        v54 = &v52[v53];
        if ( v53 > v51->m_slabSize || v54 > v51->m_end )
        {
          v55 = (char *)hkLifoAllocator::allocateFromNewSlab(v51, v53);
          v50 = v201;
          v200 = v55;
        }
        else
        {
          v51->m_cur = v54;
          v50 = v201;
          v200 = v52;
        }
      }
      else
      {
        v200 = 0i64;
      }
      v202 = v22 | 0x80000000;
      v56 = v22 & 0x3FFFFFFF;
      v203 = v200;
      if ( (v22 & 0x3FFFFFFF) < v22 )
      {
        v57 = v22;
        if ( v22 < 2 * v56 )
          v57 = 2 * v56;
        hkArrayUtil::_reserve(&v205, &hkContainerHeapAllocator::s_alloc, (const void **)&v200, v57, 4);
        v50 = v201;
      }
      v58 = v22 - v50;
      v59 = &v200[4 * v50];
      v60 = v22 - v50;
      if ( v58 > 0 )
      {
        while ( v60 )
        {
          *(_DWORD *)v59 = -1;
          v59 += 4;
          --v60;
        }
      }
      v61 = e;
      v201 = v22;
      if ( (int)v45 > 0 )
      {
        v62 = v45;
        v63 = e;
        do
        {
          Connectivity = getConnectivity(&this->m_triangulator, v63);
          if ( Connectivity == -1 )
          {
            v65 = 1;
          }
          else
          {
            v65 = 0;
            if ( Connectivity == -2 )
              v65 = 2;
          }
          v66 = 0;
          v67 = v65;
          do
          {
            if ( v67 )
              break;
            v68 = v66++
                ? v63->m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(v63->m_index))) & 3]
                : v63->m_triangle->m_vertices[v63->m_index];
            *(_DWORD *)&v200[4 * (int)(*((_QWORD *)v68 + 3) >> 2)] = Connectivity;
          }
          while ( v66 < 2 );
          ++v63;
          --v62;
        }
        while ( v62 );
        LODWORD(v45) = numEdges;
      }
      v69 = v61;
      v70 = 0i64;
      v214 = v61;
      for ( k = 0i64;
            v70 < v190;
            v214 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)((char *)v214 + v166 * 16) )
      {
        v71 = pieceSize.m_data[v70];
        v72 = *((unsigned __int16 *)v69->m_triangle + 50);
        v205.m_enum = (int)v71;
        v73 = v72 >> 5;
        if ( (_DWORD)v73 == 1 )
          v198 = -1;
        else
          v198 = this->m_materialsUsed.m_data[(v73 >> 1) - 1];
        v206 = 0;
        if ( (_DWORD)v71 )
        {
          v74 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v75 = (char *)v74->m_cur;
          v76 = (4 * v71 + 127) & 0xFFFFFF80;
          v211 = v75;
          v77 = &v75[v76];
          if ( v76 > v74->m_slabSize || v77 > v74->m_end )
          {
            v75 = (char *)hkLifoAllocator::allocateFromNewSlab(v74, v76);
            v211 = v75;
          }
          else
          {
            v74->m_cur = v77;
          }
        }
        else
        {
          v75 = 0i64;
          v211 = 0i64;
        }
        v207 = v71 | 0x80000000;
        if ( (_DWORD)v71 )
        {
          v78 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v79 = (char *)v78->m_cur;
          v80 = (4 * v71 + 127) & 0xFFFFFF80;
          p = v79;
          v81 = &v79[v80];
          if ( v80 > v78->m_slabSize || v81 > v78->m_end )
          {
            v79 = (char *)hkLifoAllocator::allocateFromNewSlab(v78, v80);
            p = v79;
          }
          else
          {
            v78->m_cur = v81;
          }
        }
        else
        {
          v79 = 0i64;
          p = 0i64;
        }
        v208 = 0;
        if ( (_DWORD)v71 )
        {
          v82 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v83 = (char *)v82->m_cur;
          v84 = (v71 + 127) & 0xFFFFFF80;
          v209 = v83;
          v85 = &v83[v84];
          if ( v84 > v82->m_slabSize || v85 > v82->m_end )
          {
            v83 = (char *)hkLifoAllocator::allocateFromNewSlab(v82, v84);
            v209 = v83;
          }
          else
          {
            v82->m_cur = v85;
          }
        }
        else
        {
          v83 = 0i64;
          v209 = 0i64;
        }
        if ( (int)v71 > 0 )
        {
          v86 = v214;
          v87 = facePoints;
          v220 = v71;
          v88 = (__int64)v209;
          v89 = v214;
          v199 = v214;
          v222 = (int *)v79;
          do
          {
            m_initialNumVertsT = this->m_initialNumVertsT;
            v91 = (const __m128i *)v89->m_triangle->m_vertices[v89->m_index];
            v92 = (unsigned __int64)v91[1].m128i_i64[1] >> 2;
            if ( (int)v92 < (int)m_initialNumVertsT || (v93 = 0, (int)v92 > this->m_lastFaceVertIndexT) )
              v93 = 4;
            v94 = array;
            v95 = 4i64 * (int)v92;
            if ( *(_DWORD *)&array[v95] == -1 )
            {
              if ( v93 || (int)v92 - (int)m_initialNumVertsT >= v231->m_size )
              {
                v104 = _mm_cvtepi32_ps(_mm_loadl_epi64(v91 + 1));
                v105 = (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_shuffle_ps(v104, _mm_unpackhi_ps(v104, (__m128)0i64), 180),
                                   4),
                                 4);
                v106 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_shuffle_ps(v105, v105, 0),
                               this->m_triangulator.m_localToWorld.m_col0.m_quad),
                             this->m_triangulator.m_localToWorld.m_col3.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v105, v105, 85), this->m_triangulator.m_localToWorld.m_col1.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v105, v105, 170), this->m_triangulator.m_localToWorld.m_col2.m_quad));
                closestPointOut.m_quad = v106;
                v107 = *(int *)&v200[4 * (int)v92];
                if ( (_DWORD)v107 == -1 )
                {
                  pointInOut.m_quad = v106;
                  if ( (unsigned __int8)hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(
                                          v87,
                                          &up,
                                          &pointInOut) )
                  {
                    v103 = pointInOut.m_quad;
                    closestPointOut.m_quad = pointInOut.m_quad;
                  }
                  else
                  {
                    if ( !LOBYTE(result.m_enum) )
                    {
                      hkaiNavMeshUtils::calcFacePlane(v87, &planeOut);
                      extraRadius.m_real = ::aabbOut.m_quad;
                      hkaiNavMeshUtils::calcFaceAabb(v87, &extraRadius, &aabbOut);
                      LOBYTE(result.m_enum) = 1;
                    }
                    v121 = _mm_mul_ps(up.m_quad, planeOut.m_quad);
                    v122 = _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v121, v121, 85), _mm_shuffle_ps(v121, v121, 0)),
                             _mm_shuffle_ps(v121, v121, 170));
                    v123 = _mm_mul_ps(closestPointOut.m_quad, planeOut.m_quad);
                    v124 = _mm_shuffle_ps(v123, _mm_unpackhi_ps(v123, planeOut.m_quad), 196);
                    v125 = _mm_add_ps(_mm_shuffle_ps(v124, v124, 78), v124);
                    v126 = _mm_add_ps(_mm_shuffle_ps(v125, v125, 177), v125);
                    v127 = _mm_rcp_ps(v122);
                    v103 = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v127, v122)), v127),
                                 _mm_sub_ps((__m128)0i64, v126)),
                               up.m_quad),
                             closestPointOut.m_quad);
                    if ( (_mm_movemask_ps(
                            _mm_and_ps(
                              _mm_cmple_ps(v103, aabbOut.m_max.m_quad),
                              _mm_cmple_ps(aabbOut.m_min.m_quad, v103))) & 7) == 7 )
                    {
                      closestPointOut.m_quad = v103;
                    }
                    else
                    {
                      position.m_quad = closestPointOut.m_quad;
                      hkaiNavMeshUtils::getClosestPointOnFace(v87, &position, &closestPointOut);
                      v103 = closestPointOut.m_quad;
                    }
                  }
                  v86 = v199;
                }
                else
                {
                  v108 = v87->m_data[v107].m_quad;
                  v109 = v87->m_data[(int)v107 + 1].m_quad;
                  v110 = _mm_mul_ps(up.m_quad, v108);
                  v111 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                           _mm_shuffle_ps(v110, v110, 170));
                  v112 = _mm_mul_ps(up.m_quad, v109);
                  v113 = _mm_sub_ps(v108, _mm_mul_ps(v111, up.m_quad));
                  v114 = _mm_sub_ps(
                           v113,
                           _mm_sub_ps(
                             v109,
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                                 _mm_shuffle_ps(v112, v112, 170)),
                               up.m_quad)));
                  v115 = _mm_mul_ps(_mm_sub_ps(v113, v106), v114);
                  v116 = _mm_mul_ps(v114, v114);
                  v117 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                           _mm_shuffle_ps(v116, v116, 170));
                  v118 = _mm_rcp_ps(v117);
                  v119 = _mm_mul_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v117, v118)), v118),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                             _mm_shuffle_ps(v115, v115, 170)));
                  v120 = _mm_cmplt_ps(v119, query.m_quad);
                  v103 = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_sub_ps(v109, v108),
                             _mm_max_ps(
                               (__m128)0i64,
                               _mm_or_ps(_mm_andnot_ps(v120, query.m_quad), _mm_and_ps(v119, v120)))),
                           v108);
                  closestPointOut.m_quad = v103;
                }
              }
              else
              {
                v96 = _mm_cvtepi32_ps(_mm_loadl_epi64(v91 + 1));
                v97 = v231->m_data[(int)v92 - m_initialNumVertsT];
                m_data = v87->m_data;
                v99 = (__m128)_mm_srli_si128(
                                _mm_slli_si128((__m128i)_mm_shuffle_ps(v96, _mm_unpackhi_ps(v96, (__m128)0i64), 180), 4),
                                4);
                v100 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v99, v99, 0), this->m_triangulator.m_localToWorld.m_col0.m_quad),
                             this->m_triangulator.m_localToWorld.m_col3.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v99, v99, 85), this->m_triangulator.m_localToWorld.m_col1.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v99, v99, 170), this->m_triangulator.m_localToWorld.m_col2.m_quad));
                v101 = _mm_mul_ps(up.m_quad, v100);
                closestPointOut.m_quad = v100;
                v102 = _mm_mul_ps(m_data[v97].m_quad, up.m_quad);
                v103 = _mm_add_ps(
                         v100,
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                               _mm_shuffle_ps(v102, v102, 170)),
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                               _mm_shuffle_ps(v101, v101, 170))),
                           up.m_quad));
                closestPointOut.m_quad = v103;
              }
              v128 = (__int64)v232;
              v221 += 16;
              *((__m128 *)v221 - 1) = v103;
              *(_DWORD *)&array[v95] = (__int16)(*(_WORD *)(v128 + 8))++;
              v94 = array;
            }
            v129 = *(_DWORD *)&v94[v95];
            v130 = v206;
            v75 = v211;
            *(_DWORD *)&v211[4 * v206] = v129;
            v206 = v130 + 1;
            v131 = getConnectivity(&this->m_triangulator, v86);
            v132 = v131;
            if ( v131 == -1 )
            {
              v133 = 1;
            }
            else
            {
              v133 = 0;
              if ( v131 == -2 )
                v133 = 2;
            }
            v134 = v208;
            v135 = v133 | v93;
            v136 = (_BYTE *)(v88 + v208);
            if ( v136 )
              *v136 = v135;
            v208 = v134 + 1;
            if ( v133 == 2 )
            {
              v132 = -1;
              v137 = 0;
              if ( (int)v45 > 0 )
              {
                v138 = e;
                while ( (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)((char *)v138->m_triangle + v138->m_index) != (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)v89->m_triangle->m_links[v89->m_index] )
                {
                  ++v137;
                  ++v138;
                  if ( v137 >= (int)v45 )
                    goto LABEL_135;
                }
                v132 = v137;
              }
            }
LABEL_135:
            v139 = v222;
            v140 = v199;
            ++v89;
            *v222 = v132;
            v86 = v140 + 1;
            v141 = v220-- == 1;
            v222 = v139 + 1;
            v199 = v86;
          }
          while ( !v141 );
          v47 = v191;
          LODWORD(v71) = v205;
          v83 = v209;
          v79 = (char *)p;
        }
        v142 = v198;
        *(_DWORD *)v47 = v71;
        v47 += 8;
        *((_DWORD *)v47 - 1) = v142;
        v191 = v47;
        v143 = v75;
        if ( (int)v71 > 0 )
        {
          v144 = (unsigned int)v71;
          do
          {
            v145 = *(_DWORD *)v143;
            v47 += 4;
            v143 += 4;
            *((_DWORD *)v47 - 1) = v145;
            --v144;
          }
          while ( v144 );
          v191 = v47;
        }
        v146 = (int *)v79;
        if ( (int)v71 > 0 )
        {
          v147 = (unsigned int)v71;
          do
          {
            v148 = *v146;
            v47 += 4;
            ++v146;
            *((_DWORD *)v47 - 1) = v148;
            --v147;
          }
          while ( v147 );
          v191 = v47;
        }
        v149 = v83;
        v150 = (int)v71 / 4;
        if ( (int)v71 / 4 > 0 )
        {
          v151 = v150;
          do
          {
            v152 = *(_DWORD *)v149;
            v47 += 4;
            v149 += 4;
            *((_DWORD *)v47 - 1) = v152;
            --v151;
          }
          while ( v151 );
          v191 = v47;
        }
        v153 = (int)(4 * v150);
        if ( (v71 & 3) != 0 )
        {
          LOBYTE(numEdges) = v83[v153];
          if ( ((unsigned __int8)v71 & 3u) <= 1 )
            v154 = -1;
          else
            v154 = v83[v153 + 1];
          BYTE1(numEdges) = v154;
          if ( ((unsigned __int8)v71 & 3u) <= 2 )
            v155 = -1;
          else
            v155 = v83[v153 + 2];
          BYTE2(numEdges) = v155;
          if ( ((unsigned __int8)v71 & 3u) <= 3 )
            v156 = -1;
          else
            v156 = v83[v153 + 3];
          HIBYTE(numEdges) = v156;
          v47 += 4;
          *((_DWORD *)v47 - 1) = numEdges;
          v191 = v47;
        }
        v157 = (v71 + 127) & 0xFFFFFF80;
        v158 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v159 = (v157 + 15) & 0xFFFFFFF0;
        if ( v157 > v158->m_slabSize || &v83[v159] != v158->m_cur || v158->m_firstNonLifoEnd == v83 )
          hkLifoAllocator::slowBlockFree(v158, v83, v159);
        else
          v158->m_cur = v83;
        if ( v207 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v83, v207 & 0x3FFFFFFF);
        v160 = (4 * v71 + 127) & 0xFFFFFF80;
        v161 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v162 = p;
        v163 = (v160 + 15) & 0xFFFFFFF0;
        if ( v160 > v161->m_slabSize || (char *)p + v163 != v161->m_cur || v161->m_firstNonLifoEnd == p )
        {
          hkLifoAllocator::slowBlockFree(v161, (char *)p, v163);
          v162 = p;
        }
        else
        {
          v161->m_cur = p;
        }
        v164 = v207;
        if ( v207 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v162, 4 * v207);
        v165 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v160 > v165->m_slabSize || &v75[v163] != v165->m_cur || v165->m_firstNonLifoEnd == v75 )
          hkLifoAllocator::slowBlockFree(v165, v75, v163);
        else
          v165->m_cur = v75;
        if ( v164 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v75, 4 * v164);
        v70 = k + 1;
        v166 = pieceSize.m_data[k];
        k = v70;
        v69 = &v214[v166];
      }
      v167 = v201;
      v168 = (char *)v203;
      if ( v203 == v200 )
        v167 = 0;
      v201 = v167;
      v169 = (4 * v204 + 127) & 0xFFFFFF80;
      v170 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v171 = (v169 + 15) & 0xFFFFFFF0;
      if ( v169 > v170->m_slabSize || &v168[v171] != v170->m_cur || v170->m_firstNonLifoEnd == v168 )
        hkLifoAllocator::slowBlockFree(v170, v168, v171);
      else
        v170->m_cur = v168;
      v201 = 0;
      if ( v202 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v200, 4 * v202);
    }
    v12 = 1;
    goto LABEL_192;
  }
  v12 = 0;
LABEL_215:
  v184 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v185 = (_QWORD *)v184[1];
  if ( (unsigned __int64)v185 < v184[3] )
  {
    *v185 = "lt";
    v186 = __rdtsc();
    v187 = v185 + 2;
    *((_DWORD *)v187 - 2) = v186;
    v184[1] = v187;
  }
  return v12;
}

// File Line: 835
// RVA: 0x12E9B90
void __fastcall hkaiFaceCutter::initTriangulatorForFace(
        hkaiFaceCutter *this,
        hkaiNavMeshUtils *origMesh,
        bool isWallClimbing,
        hkArrayBase<hkVector4f> *faceIndex,
        hkSimdFloat32 *regionExpansion,
        hkArrayBase<hkVector4f> *faceVerticesOut,
        hkArrayBase<int> *faceLoopVertexIndexRemap)
{
  int *v9; // r10
  hkVector4f v10; // xmm1
  int v11; // r8d
  int v12[2]; // [rsp+30h] [rbp-81h] BYREF
  int v13; // [rsp+38h] [rbp-79h]
  int v14; // [rsp+3Ch] [rbp-75h]
  hkStridedVertices points; // [rsp+40h] [rbp-71h] BYREF
  hkAabb aabbOut; // [rsp+50h] [rbp-61h] BYREF
  __int128 v17[8]; // [rsp+70h] [rbp-41h] BYREF

  v9 = (int *)(*(_QWORD *)&origMesh[16] + 16i64 * (int)faceIndex);
  v12[0] = *v9;
  v12[1] = v9[1];
  v13 = v9[2];
  v14 = v9[3];
  faceVerticesOut->m_size = (__int16)v13 + 1;
  hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
    origMesh,
    (hkaiNavMeshInstance *)v12,
    (hkaiNavMesh::Face *)faceVerticesOut,
    faceIndex);
  if ( isWallClimbing )
    hkaiNavMeshUtils::calcFacePlane(faceVerticesOut, &this->m_up);
  hkaiNavMeshUtils::calcFaceAabb(faceVerticesOut, regionExpansion, &aabbOut);
  v10.m_quad = (__m128)aabbOut.m_max;
  points.m_vertices = (const float *)v17;
  points.m_numVertices = 8;
  v10.m_quad.m128_f32[0] = aabbOut.m_min.m_quad.m128_f32[0];
  points.m_striding = 16;
  v17[0] = (__int128)_mm_srli_si128(_mm_slli_si128((__m128i)aabbOut.m_max.m_quad, 4), 4);
  v17[1] = (__int128)_mm_srli_si128(_mm_slli_si128((__m128i)v10.m_quad, 4), 4);
  v17[2] = (__int128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_or_ps(
                                    _mm_andnot_ps((__m128)xmmword_141C1C0F0, aabbOut.m_max.m_quad),
                                    _mm_and_ps(aabbOut.m_min.m_quad, (__m128)xmmword_141C1C0F0)),
                         4),
                       4);
  v17[3] = (__int128)_mm_srli_si128(
                       _mm_slli_si128((__m128i)_mm_shuffle_ps(aabbOut.m_min.m_quad, aabbOut.m_max.m_quad, 228), 4),
                       4);
  v17[4] = (__int128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_or_ps(
                                    _mm_andnot_ps((__m128)xmmword_141C1C110, aabbOut.m_max.m_quad),
                                    _mm_and_ps(aabbOut.m_min.m_quad, (__m128)xmmword_141C1C110)),
                         4),
                       4);
  v17[5] = (__int128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_or_ps(
                                    _mm_andnot_ps((__m128)xmmword_141C1C120, aabbOut.m_max.m_quad),
                                    _mm_and_ps(aabbOut.m_min.m_quad, (__m128)xmmword_141C1C120)),
                         4),
                       4);
  v17[6] = (__int128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_or_ps(
                                    _mm_andnot_ps((__m128)xmmword_141C1C130, aabbOut.m_max.m_quad),
                                    _mm_and_ps(aabbOut.m_min.m_quad, (__m128)xmmword_141C1C130)),
                         4),
                       4);
  v17[7] = (__int128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_shuffle_ps(
                                    aabbOut.m_min.m_quad,
                                    _mm_unpackhi_ps(aabbOut.m_min.m_quad, aabbOut.m_max.m_quad),
                                    196),
                         4),
                       4);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::setDomainFromPlanarPoints(
    &this->m_triangulator,
    &points,
    &this->m_up,
    1,
    1,
    0);
  v11 = (__int16)v13;
  this->m_initialNumVertsT = this->m_triangulator.m_mesh.m_vertices.m_numUsed;
  hkaiFaceCutter::triangulatorAddLoop(this, faceVerticesOut->m_data, v11, LOOP_FACE, 0, faceLoopVertexIndexRemap);
  this->m_lastFaceVertIndexT = this->m_triangulator.m_mesh.m_vertices.m_numUsed - 1;
}

// File Line: 876
// RVA: 0x12E9890
void __fastcall hkaiFaceCutter::setFace(
        hkaiFaceCutter *this,
        hkaiNavMeshInstance *origMesh,
        hkVector4f *worldUp,
        bool isWallClimbing,
        unsigned int faceKey,
        hkSimdFloat32 *regionExpansion,
        hkArrayBase<hkVector4f> *faceVertsOut,
        hkArrayBase<int> *faceLoopVertexIndexRemap)
{
  hkVector4f *m_data; // rdx
  __int64 m_firstSuccessfulEdge; // r9
  int m_firstDuplicateEdge; // [rsp+20h] [rbp-58h]
  hkVector4f segB; // [rsp+40h] [rbp-38h] BYREF
  hkVector4f segA; // [rsp+50h] [rbp-28h] BYREF

  hkaiFaceCutter::reset(this, faceKey);
  this->m_up = (hkVector4f)worldUp->m_quad;
  hkaiFaceCutter::initTriangulatorForFace(
    this,
    origMesh,
    isWallClimbing,
    faceKey & 0x3FFFFF,
    regionExpansion,
    faceVertsOut,
    faceLoopVertexIndexRemap);
  if ( this->m_lastFaceVertIndexT - this->m_initialNumVertsT == 1 )
  {
    m_data = faceVertsOut->m_data;
    m_firstSuccessfulEdge = this->m_firstSuccessfulEdge;
    segA.m_quad = (__m128)faceVertsOut->m_data[m_firstSuccessfulEdge];
    m_firstDuplicateEdge = this->m_firstDuplicateEdge;
    segB.m_quad = (__m128)m_data[m_firstSuccessfulEdge + 1];
    hkaiDegenerateFaceCutter::setSegment(
      &this->m_degenerateFaceCutter,
      &segA,
      &segB,
      m_firstSuccessfulEdge,
      m_firstDuplicateEdge,
      &this->m_up);
  }
}

// File Line: 896
// RVA: 0x12E99A0
unsigned int __fastcall hkaiFaceCutter::addSilhouette(
        hkaiFaceCutter *this,
        hkVector4f *points,
        int loopSize,
        int material)
{
  int materialIndex; // r8d
  __int64 m_size; // r11
  int v9; // edx
  __int64 v10; // rcx
  int *m_data; // rax
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // eax

  if ( this->m_faceIsCrossing )
    return 1;
  materialIndex = -1;
  if ( material != -1 )
  {
    m_size = this->m_materialsUsed.m_size;
    v9 = 0;
    v10 = 0i64;
    if ( m_size <= 0 )
      goto LABEL_9;
    m_data = this->m_materialsUsed.m_data;
    while ( *m_data != material )
    {
      ++v10;
      ++v9;
      ++m_data;
      if ( v10 >= m_size )
        goto LABEL_9;
    }
    materialIndex = v9;
    if ( v9 == -1 )
    {
LABEL_9:
      v12 = this->m_materialsUsed.m_size;
      if ( v12 < 14 )
      {
        materialIndex = this->m_materialsUsed.m_size;
        this->m_materialsUsed.m_data[v12] = material;
        ++this->m_materialsUsed.m_size;
      }
    }
  }
  v13 = this->m_lastFaceVertIndexT - this->m_initialNumVertsT;
  ++this->m_numSilhouettesAdded;
  v14 = (materialIndex == -1) + 1;
  v15 = v13 + 1;
  if ( v15 > 2 )
    return hkaiFaceCutter::triangulatorAddLoop(
             this,
             points,
             loopSize,
             (hkaiFaceCutter::LoopType)v14,
             materialIndex,
             0i64);
  if ( v15 != 2 )
    return 1;
  else
    return hkaiDegenerateFaceCutter::addSilhouette(
             &this->m_degenerateFaceCutter,
             points,
             loopSize,
             (hkaiDegenerateFaceCutter::IntervalType)v14,
             materialIndex,
             &this->m_up);
}

// File Line: 934
// RVA: 0x12E9AC0
unsigned int __fastcall hkaiFaceCutter::computeConvexDecomposition(
        hkaiFaceCutter *this,
        hkaiFaceCutResults *results,
        hkArrayBase<hkVector4f> *faceVertices,
        hkArrayBase<int> *faceLoopVertexRemap)
{
  int v5; // r9d

  if ( this->m_numSilhouettesAdded && (v5 = this->m_lastFaceVertIndexT - this->m_initialNumVertsT + 1, v5 <= 2) )
    return hkaiDegenerateFaceCutter::computeConvexDecomposition(
             &this->m_degenerateFaceCutter,
             results,
             this->m_faceKey,
             v5);
  else
    return hkaiFaceCutter::computeConvexDecompositionOfCutFace(this, faceVertices, faceLoopVertexRemap, results);
}

// File Line: 946
// RVA: 0x12E9B20
void __fastcall hkaiFaceCutter::reset(hkaiFaceCutter *this, unsigned int faceKey)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::reset(
    &this->m_triangulator,
    1);
  hkaiDegenerateFaceCutter::reset(&this->m_degenerateFaceCutter);
  this->m_faceKey = faceKey;
  this->m_materialsUsed.m_size = 0;
  this->m_numSilhouettesAdded = 0;
  this->m_faceIsCrossing = 0;
  *(_QWORD *)&this->m_lastFaceVertIndexT = -1i64;
  *(_QWORD *)&this->m_firstSuccessfulEdge = -1i64;
}

