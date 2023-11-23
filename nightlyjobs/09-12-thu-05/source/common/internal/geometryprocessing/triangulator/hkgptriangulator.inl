// File Line: 309
// RVA: 0xCDC050
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeDataOrientation(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_used; // r14
  unsigned int v2; // r15d
  int v4; // edi
  int v5; // esi
  signed int v6; // ebx
  unsigned __int64 v7; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge edge; // [rsp+20h] [rbp-38h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v10; // [rsp+30h] [rbp-28h] BYREF

  m_used = this->m_mesh.m_triangles.m_used;
  v2 = 0;
  v4 = 0;
  v5 = 0;
  if ( m_used )
  {
    while ( (*((_BYTE *)m_used + 66) & 0x20) == 0 )
    {
LABEL_10:
      m_used = m_used->m_next;
      if ( !m_used )
        goto LABEL_11;
    }
    v6 = 0;
    while ( 1 )
    {
      edge.m_triangle = m_used;
      edge.m_index = v6;
      v7 = m_used->m_links[v6];
      if ( (v7 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        break;
      v10.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v7 & 0xFFFFFFFFFFFFFFFCui64);
      v10.m_index = v7 & 3;
      if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
             this,
             (__m128i *)&edge) )
      {
        ++v4;
      }
      else if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
                  this,
                  (__m128i *)&v10) )
      {
        goto LABEL_8;
      }
LABEL_9:
      if ( ++v6 >= 3 )
        goto LABEL_10;
    }
    if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
           this,
           (__m128i *)&edge) )
    {
      ++v4;
      goto LABEL_9;
    }
LABEL_8:
    ++v5;
    goto LABEL_9;
  }
LABEL_11:
  LOBYTE(v2) = v4 > v5;
  return v2;
}

// File Line: 343
// RVA: 0xB87660
hkaiNavMeshGenTriangulatorEdgeData *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_triangle; // rcx
  __int64 m_index; // rax

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  if ( edge->m_triangle && m_triangle->m_edgeData[m_index].m_hasData )
    return &m_triangle->m_edgeData[m_index].m_data;
  else
    return 0i64;
}

// File Line: 361
// RVA: 0xB8B8E0
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setEdgeData(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge,
        hkaiNavMeshGenTriangulatorEdgeData *data)
{
  __int64 m_index; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_triangle; // rax

  m_index = (int)edge->m_index;
  m_triangle = edge->m_triangle;
  if ( !edge->m_triangle->m_edgeData[m_index].m_hasData )
  {
    m_triangle->m_edgeData[m_index].m_data.m_counter = 0;
    m_triangle->m_edgeData[m_index].m_hasData = 1;
  }
  ++m_triangle->m_edgeData[m_index].m_data.m_counter;
}

// File Line: 377
// RVA: 0xCD8B10
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::clearEdgeData(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this,
        __m128i *edge)
{
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::clearEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
    &this->m_edgeDataPolicy,
    edge);
}

// File Line: 392
// RVA: 0xB69050
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::canSplitEdge(
        int ix,
        int iy,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_triangle; // rbx
  __int64 m_index; // r11
  char v6; // r15
  int v7; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v8; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v9; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v11; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v12; // rcx
  unsigned __int64 v13; // rbx
  __int64 v14; // r8
  __int64 v15; // rcx
  char v16; // cl
  unsigned __int64 v17; // rbx
  int v18; // esi
  __int64 v19; // rcx
  __int64 v20; // r8

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  v6 = 2 * m_index;
  v7 = (9 >> (2 * m_index)) & 3;
  v8 = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v7)) & 3];
  v9 = m_triangle->m_vertices[v7];
  if ( (iy - v9->m_y) * (__int64)(v8->m_x - v9->m_x) - (ix - v9->m_x) * (__int64)(v8->m_y - v9->m_y) <= 0 )
    return 0i64;
  v11 = m_triangle->m_vertices[(9i64 >> (2 * ((18 >> v6) & 3u))) & 3];
  v12 = m_triangle->m_vertices[(18 >> v6) & 3];
  if ( (iy - v12->m_y) * (__int64)(v11->m_x - v12->m_x) - (ix - v12->m_x) * (__int64)(v11->m_y - v12->m_y) <= 0 )
    return 0i64;
  v13 = m_triangle->m_links[m_index];
  if ( (v13 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    v14 = *(_QWORD *)((v13 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((9i64 >> (2 * ((9 >> (2 * (v13 & 3))) & 3u))) & 3) + 16);
    v15 = *(_QWORD *)((v13 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((9 >> (2 * (v13 & 3))) & 3) + 16);
    if ( (iy - *(_DWORD *)(v15 + 20)) * (__int64)(*(_DWORD *)(v14 + 16) - *(_DWORD *)(v15 + 16))
       - (ix - *(_DWORD *)(v15 + 16)) * (__int64)(*(_DWORD *)(v14 + 20) - *(_DWORD *)(v15 + 20)) <= 0 )
      return 0i64;
  }
  if ( (v13 & 0xFFFFFFFFFFFFFFFCui64) != 0
    && (v16 = v13,
        v17 = v13 & 0xFFFFFFFFFFFFFFFCui64,
        v18 = (18 >> (2 * (v16 & 3))) & 3,
        v19 = *(_QWORD *)(v17 + 8i64 * v18 + 16),
        v20 = *(_QWORD *)(v17 + 8 * ((9i64 >> (2 * (unsigned __int8)v18)) & 3) + 16),
        (iy - *(_DWORD *)(v19 + 20)) * (__int64)(*(_DWORD *)(v20 + 16) - *(_DWORD *)(v19 + 16))
      - (ix - *(_DWORD *)(v19 + 16)) * (__int64)(*(_DWORD *)(v20 + 20) - *(_DWORD *)(v19 + 20)) <= 0) )
  {
    return 0i64;
  }
  else
  {
    return 1i64;
  }
}

// File Line: 490
// RVA: 0xCE0020
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::reset(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this,
        bool createDomainTriangulation)
{
  __int64 v4; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **m_roots; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item *m_free; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *m_used; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item *v10; // rbp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v11; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v12; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item *v13; // r15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v14; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v15; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item *v16; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v17; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v18; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v19; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v20; // rax

  this->m_mesh.vfptr[1].__first_virtual_table_function__(&this->m_mesh);
  v4 = 32i64;
  m_roots = this->m_roots;
  do
  {
    *m_roots = 0i64;
    m_roots[1] = 0i64;
    m_roots[2] = 0i64;
    m_roots += 8;
    *(m_roots - 5) = 0i64;
    *(m_roots - 4) = 0i64;
    *(m_roots - 3) = 0i64;
    *(m_roots - 2) = 0i64;
    *(m_roots - 1) = 0i64;
    --v4;
  }
  while ( v4 );
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::reset(&this->m_edgeDataPolicy);
  if ( createDomainTriangulation )
  {
    m_firstPool = this->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !m_firstPool || !m_firstPool->m_free )
      m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_mesh.m_vertices.m_allocator);
    if ( m_firstPool )
    {
      m_free = m_firstPool->m_free;
      m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
      m_free->m_pool = m_firstPool;
      ++m_firstPool->m_used;
      *(_QWORD *)&m_free->m_data[8] = 0i64;
      *(_QWORD *)m_free->m_data = this->m_mesh.m_vertices.m_used;
      m_used = this->m_mesh.m_vertices.m_used;
      if ( m_used )
        m_used->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)m_free;
      ++this->m_mesh.m_vertices.m_numUsed;
      this->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)m_free;
      *(_QWORD *)&m_free->m_data[16] = 0i64;
      *(_QWORD *)&m_free->m_data[24] = -4i64;
    }
    else
    {
      m_free = 0i64;
    }
    NewPool = this->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !NewPool || !NewPool->m_free )
      NewPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_mesh.m_vertices.m_allocator);
    if ( NewPool )
    {
      v10 = NewPool->m_free;
      NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v10->m_data;
      v10->m_pool = NewPool;
      ++NewPool->m_used;
      *(_QWORD *)&v10->m_data[8] = 0i64;
      *(_QWORD *)v10->m_data = this->m_mesh.m_vertices.m_used;
      v11 = this->m_mesh.m_vertices.m_used;
      if ( v11 )
        v11->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v10;
      ++this->m_mesh.m_vertices.m_numUsed;
      this->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v10;
      *(_DWORD *)&v10->m_data[16] = 0;
      *(_DWORD *)&v10->m_data[20] = 0x7FFF;
      *(_QWORD *)&v10->m_data[24] = -4i64;
    }
    else
    {
      v10 = 0i64;
    }
    v12 = this->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !v12 || !v12->m_free )
      v12 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_mesh.m_vertices.m_allocator);
    if ( v12 )
    {
      v13 = v12->m_free;
      v12->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v13->m_data;
      v13->m_pool = v12;
      ++v12->m_used;
      *(_QWORD *)&v13->m_data[8] = 0i64;
      *(_QWORD *)v13->m_data = this->m_mesh.m_vertices.m_used;
      v14 = this->m_mesh.m_vertices.m_used;
      if ( v14 )
        v14->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v13;
      ++this->m_mesh.m_vertices.m_numUsed;
      this->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v13;
      *(_QWORD *)&v13->m_data[16] = 0x7FFFi64;
      *(_QWORD *)&v13->m_data[24] = -4i64;
    }
    else
    {
      v13 = 0i64;
    }
    v15 = this->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !v15 || !v15->m_free )
      v15 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&this->m_mesh.m_vertices.m_allocator);
    if ( v15 )
    {
      v16 = v15->m_free;
      v15->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v16->m_data;
      v16->m_pool = v15;
      ++v15->m_used;
      *(_QWORD *)&v16->m_data[8] = 0i64;
      *(_QWORD *)v16->m_data = this->m_mesh.m_vertices.m_used;
      v17 = this->m_mesh.m_vertices.m_used;
      if ( v17 )
        v17->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v16;
      ++this->m_mesh.m_vertices.m_numUsed;
      this->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v16;
      *(_DWORD *)&v16->m_data[16] = 0x7FFF;
      *(_DWORD *)&v16->m_data[20] = 0x7FFF;
      *(_QWORD *)&v16->m_data[24] = -4i64;
    }
    else
    {
      v16 = 0i64;
    }
    if ( m_free && v10 && v13 && v16 )
    {
      v18 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_mesh.m_triangles);
      v19 = v18;
      if ( v18 )
      {
        *(_DWORD *)&v18->m_items[0].m_data[66] = 0;
        *(_QWORD *)&v18->m_items[0].m_data[16] = m_free;
        *(_QWORD *)&v18->m_items[0].m_data[24] = v13;
        *(_QWORD *)&v18->m_items[0].m_data[32] = v16;
        *((_QWORD *)&this->m_roots[(__int64)(*(_DWORD *)&v16->m_data[16]
                                           + *(_DWORD *)&v13->m_data[16]
                                           + 2 * *(_DWORD *)&m_free->m_data[16]) >> 13]
        + (((__int64)(*(_DWORD *)&v16->m_data[20] + *(_DWORD *)&v13->m_data[20] + 2 * *(_DWORD *)&m_free->m_data[20]) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)) = v18;
        *(_WORD *)&v18->m_items[0].m_data[66] |= 8u;
      }
      v20 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_mesh.m_triangles);
      if ( v20 )
      {
        *(_DWORD *)&v20->m_items[0].m_data[66] = 0;
        *(_QWORD *)&v20->m_items[0].m_data[16] = m_free;
        *(_QWORD *)&v20->m_items[0].m_data[24] = v16;
        *(_QWORD *)&v20->m_items[0].m_data[32] = v10;
        *((_QWORD *)&this->m_roots[(__int64)(*(_DWORD *)&v10->m_data[16]
                                           + *(_DWORD *)&v16->m_data[16]
                                           + 2 * *(_DWORD *)&m_free->m_data[16]) >> 13]
        + (((__int64)(*(_DWORD *)&v10->m_data[20] + *(_DWORD *)&v16->m_data[20] + 2 * *(_DWORD *)&m_free->m_data[20]) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)) = v20;
        *(_WORD *)&v20->m_items[0].m_data[66] |= 8u;
      }
      if ( v19 && v20 )
      {
        *(_QWORD *)&v19->m_items[0].m_data[48] = 0i64;
        *(_QWORD *)&v19->m_items[0].m_data[40] = 0i64;
        *(_QWORD *)&v20->m_items[0].m_data[56] = 0i64;
        *(_QWORD *)&v20->m_items[0].m_data[48] = 0i64;
        *(_QWORD *)&v19->m_items[0].m_data[56] = v20;
        *(_QWORD *)&v20->m_items[0].m_data[40] = &v19->m_items[0].m_data[2];
      }
      else
      {
        this->m_status.m_storage = 1;
      }
    }
    else
    {
      this->m_status.m_storage = 1;
    }
  }
}

// File Line: 542
// RVA: 0xB69270
hkResult *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::clone(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkResult *result,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *other)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v3; // r15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v4; // rdi
  hkResult *v5; // r12
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **m_roots; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **v7; // rax
  __int64 v8; // r9
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm0
  unsigned __int64 m_used; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  unsigned __int64 m_free; // r9
  __int64 v15; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v16; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_next; // r14
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> > *p_m_triangles; // r13
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v20; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **v21; // rax
  unsigned __int64 v22; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v23; // rax
  unsigned __int64 *v24; // rbx
  __int64 v25; // rsi
  unsigned __int64 v26; // rax
  _QWORD *v27; // rsi
  int i; // ebx
  __int64 v29; // r15
  unsigned __int64 v31; // r12
  unsigned __int64 v32; // rax
  unsigned int v33; // r9d
  unsigned __int64 v34; // rax
  signed __int64 v35; // r15
  __int64 v36; // rbx
  unsigned __int64 v37; // rdx
  hkResult v38; // [rsp+30h] [rbp-29h] BYREF
  hkResult resulta; // [rsp+34h] [rbp-25h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **v40; // [rsp+38h] [rbp-21h]
  AMD_HD3D v41; // [rsp+40h] [rbp-19h] BYREF
  AMD_HD3D v42; // [rsp+60h] [rbp+7h] BYREF
  hkResult res; // [rsp+D8h] [rbp+7Fh] BYREF

  v3 = this;
  v4 = other;
  v5 = result;
  other->m_mesh.vfptr[1].__first_virtual_table_function__(&other->m_mesh);
  m_roots = v4->m_roots;
  v40 = v4->m_roots;
  v7 = v4->m_roots;
  v8 = 32i64;
  do
  {
    *v7 = 0i64;
    v7[1] = 0i64;
    v7[2] = 0i64;
    v7 += 8;
    *(v7 - 5) = 0i64;
    *(v7 - 4) = 0i64;
    *(v7 - 3) = 0i64;
    *(v7 - 2) = 0i64;
    *(v7 - 1) = 0i64;
    --v8;
  }
  while ( v8 );
  v9.m_quad = (__m128)v3->m_localToWorld.m_col0;
  *(_QWORD *)&v42.mEnableStereo = 0i64;
  v42.mWidth = 0;
  v4->m_localToWorld.m_col0 = (hkVector4f)v9.m_quad;
  v10.m_quad = (__m128)v3->m_localToWorld.m_col1;
  v42.mHeight = -1;
  v41.mStereo = 0i64;
  v41.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  v4->m_localToWorld.m_col1 = (hkVector4f)v10.m_quad;
  v11.m_quad = (__m128)v3->m_localToWorld.m_col2;
  *(_QWORD *)&v41.mEnableStereo = 0i64;
  v41.mWidth = 0;
  v41.mHeight = -1;
  v4->m_localToWorld.m_col2 = (hkVector4f)v11.m_quad;
  v4->m_localToWorld.m_col3 = v3->m_localToWorld.m_col3;
  v4->m_worldToLocal.m_col0 = v3->m_worldToLocal.m_col0;
  v4->m_worldToLocal.m_col1 = v3->m_worldToLocal.m_col1;
  v4->m_worldToLocal.m_col2 = v3->m_worldToLocal.m_col2;
  v4->m_worldToLocal.m_col3 = v3->m_worldToLocal.m_col3;
  v4->m_margin = v3->m_margin;
  m_used = (unsigned __int64)v3->m_mesh.m_vertices.m_used;
  if ( m_used )
  {
    while ( 1 )
    {
      m_firstPool = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *)v4->m_mesh.m_vertices.m_allocator.m_firstPool;
      if ( !m_firstPool || !m_firstPool->m_free )
        m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&v4->m_mesh.m_vertices);
      if ( !m_firstPool )
        break;
      m_free = (unsigned __int64)m_firstPool->m_free;
      m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)m_free;
      *(_QWORD *)(m_free + 32) = m_firstPool;
      ++m_firstPool->m_used;
      *(_DWORD *)(m_free + 16) = *(_DWORD *)(m_used + 16);
      *(_DWORD *)(m_free + 20) = *(_DWORD *)(m_used + 20);
      *(_QWORD *)(m_free + 24) ^= (*(_DWORD *)(m_used + 24) ^ *(_DWORD *)(m_free + 24)) & 1;
      v15 = *(_QWORD *)(m_free + 24) ^ (*(_DWORD *)(m_used + 24) ^ (unsigned int)*(_QWORD *)(m_free + 24)) & 2;
      *(_QWORD *)(m_free + 24) = v15;
      *(_QWORD *)(m_free + 24) = *(_QWORD *)(m_used + 24) ^ ((unsigned __int8)v15 ^ (unsigned __int8)*(_QWORD *)(m_used + 24)) & 3;
      *(_QWORD *)(m_free + 8) = 0i64;
      *(_QWORD *)m_free = v4->m_mesh.m_vertices.m_used;
      v16 = v4->m_mesh.m_vertices.m_used;
      if ( v16 )
        v16->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)m_free;
      ++v4->m_mesh.m_vertices.m_numUsed;
      v4->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)m_free;
      res.m_enum = HK_FAILURE;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v42,
        &hkContainerHeapAllocator::s_alloc,
        m_used,
        m_free,
        &res);
      if ( res.m_enum )
        break;
      m_used = *(_QWORD *)m_used;
      if ( !m_used )
      {
        v4 = other;
        goto LABEL_13;
      }
    }
    v5->m_enum = HK_FAILURE;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41,
      &hkContainerHeapAllocator::s_alloc);
    _(&v41);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41.mStereo,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&v41.mStereo);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v42,
      &hkContainerHeapAllocator::s_alloc);
    _(&v42);
    return v5;
  }
  else
  {
LABEL_13:
    m_next = v3->m_mesh.m_triangles.m_used;
    if ( m_next )
    {
      p_m_triangles = &v4->m_mesh.m_triangles;
      while ( 1 )
      {
        NewPool = p_m_triangles->m_allocator.m_firstPool;
        if ( !p_m_triangles->m_allocator.m_firstPool || !NewPool->m_free )
          NewPool = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(&p_m_triangles->m_allocator);
        if ( !NewPool )
          break;
        v20 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)NewPool->m_free;
        NewPool->m_free = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Item *)v20->m_next;
        v20[1].m_next = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)NewPool;
        ++NewPool->m_used;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle::Triangle(
          v20,
          m_next);
        v22 = (unsigned __int64)v21;
        if ( !v21 )
          break;
        v21[1] = 0i64;
        *v21 = p_m_triangles->m_used;
        v23 = p_m_triangles->m_used;
        if ( v23 )
          v23->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v22;
        ++p_m_triangles->m_numUsed;
        p_m_triangles->m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v22;
        res.m_enum = HK_FAILURE;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41.mStereo,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)m_next,
          v22,
          &res);
        if ( res.m_enum )
          break;
        v24 = (unsigned __int64 *)(v22 + 16);
        v25 = 3i64;
        do
        {
          v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v42,
                  *v24++,
                  0i64);
          *(v24 - 1) = v26;
          --v25;
        }
        while ( v25 );
        v27 = (_QWORD *)(v22 + 40);
        for ( i = 0; i < 3; ++i )
        {
          v29 = 8i64 * i + 40;
          if ( (*(unsigned __int64 *)((_BYTE *)&m_next->m_next + v29) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            v31 = *(unsigned __int64 *)((char *)&m_next->m_next + v29);
            v32 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41,
                    v31,
                    0i64);
            v33 = v32 & 3;
            v34 = v32 & 0xFFFFFFFFFFFFFFFCui64;
            if ( v34 )
            {
              *(_QWORD *)(v22 + v29) = v34 + v33;
              *(_QWORD *)(v34 + 8i64 * (int)v33 + 40) = v22 + (unsigned int)i;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41,
                &resulta,
                v31);
            }
            else
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41,
                &hkContainerHeapAllocator::s_alloc,
                (unsigned __int64)m_next + (unsigned int)i,
                v22 + (unsigned int)i,
                &v38);
              if ( v38.m_enum )
                goto LABEL_38;
            }
          }
          else
          {
            *v27 = 0i64;
          }
          ++v27;
        }
        m_next = m_next->m_next;
        if ( !m_next )
        {
          m_roots = v40;
          v3 = this;
          v5 = result;
          goto LABEL_35;
        }
      }
LABEL_38:
      result->m_enum = HK_FAILURE;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41,
        &hkContainerHeapAllocator::s_alloc);
      _(&v41);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41.mStereo,
        &hkContainerHeapAllocator::s_alloc);
      _((AMD_HD3D *)&v41.mStereo);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v42,
        &hkContainerHeapAllocator::s_alloc);
      _(&v42);
      return result;
    }
    else
    {
LABEL_35:
      v35 = (char *)v3 - (char *)other;
      v36 = 256i64;
      do
      {
        v37 = *(unsigned __int64 *)((char *)m_roots + v35);
        if ( v37 )
          *m_roots = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41.mStereo, v37, 0i64);
        else
          *m_roots = 0i64;
        ++m_roots;
        --v36;
      }
      while ( v36 );
      v5->m_enum = HK_SUCCESS;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41,
        &hkContainerHeapAllocator::s_alloc);
      _(&v41);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v41.mStereo,
        &hkContainerHeapAllocator::s_alloc);
      _((AMD_HD3D *)&v41.mStereo);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v42,
        &hkContainerHeapAllocator::s_alloc);
      _(&v42);
      return v5;
    }
  }
}

// File Line: 634
// RVA: 0xB6D720
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkVector4f *dmin,
        hkVector4f *dmax,
        float angle,
        hkResult margin)
{
  int v5; // eax
  __m128i si128; // xmm6
  __m128 v8; // xmm9
  __m128 v9; // xmm2
  __m128i v10; // xmm8
  __m128 v11; // xmm0
  __m128i v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  hkSimdFloat32 v25; // [rsp+20h] [rbp-78h] BYREF

  v5 = LOBYTE(margin.m_enum) != 0;
  this->m_margin = v5;
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v8 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(angle), (__m128)LODWORD(angle), 0), *(__m128 *)offset_1);
  v9 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  v10 = _mm_add_epi32(si128, si128);
  v11 = 0i64;
  v11.m128_f32[0] = (float)(0x7FFFFF - 2 * v5);
  v12 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v9, *(__m128 *)_xmm)), si128));
  v13 = _mm_cvtepi32_ps(v12);
  v14 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v12, v10), (__m128i)0i64);
  v15 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v13, *(__m128 *)DP1_0), v9), _mm_mul_ps(v13, *(__m128 *)DP2)),
          _mm_mul_ps(v13, *(__m128 *)DP3));
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v14,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v16),
                        *(__m128 *)cosCoeff2_0),
                      v16),
                    v16),
                  _mm_mul_ps(v16, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v16),
                      *(__m128 *)sinCoeff2_0),
                    v16),
                  v15),
                v15),
              v14)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v10, v10), v12), 0x1Du),
            _mm_and_ps(v8, *(__m128 *)_xmm)));
  v18 = _mm_shuffle_ps(v17, v17, 0);
  v19 = _mm_shuffle_ps(v17, v17, 85);
  v20 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
  v21 = _mm_sub_ps(dmax->m_quad, dmin->m_quad);
  v25.m_real = 0i64;
  this->m_localToWorld.m_col0 = (hkVector4f)transform.m_quad;
  v22 = _mm_mul_ps(v21, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v11, v11, 0)));
  this->m_localToWorld.m_col1 = (hkVector4f)direction.m_quad;
  this->m_localToWorld.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_localToWorld.m_col3 = (hkVector4f)qi.m_vec.m_quad;
  v23 = _mm_shuffle_ps(v22, v22, 0);
  v24 = _mm_shuffle_ps(v22, v22, 85);
  this->m_localToWorld.m_col0.m_quad = _mm_movelh_ps(
                                         _mm_unpacklo_ps(
                                           _mm_mul_ps(v23, v19),
                                           _mm_mul_ps(_mm_sub_ps((__m128)0i64, v18), v23)),
                                         v20);
  this->m_localToWorld.m_col1.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(_mm_mul_ps(v24, v18), _mm_mul_ps(v24, v19)), v20);
  this->m_localToWorld.m_col3.m_quad = _mm_shuffle_ps(dmin->m_quad, qi.m_vec.m_quad, 228);
  __hkMatrix4UtilAlgo::setInverse(&margin, &this->m_localToWorld, &this->m_worldToLocal, &v25);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    this,
    1);
}

// File Line: 658
// RVA: 0xB8B520
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPoints(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkStridedVertices *points,
        hkMatrix4f *worldToXYPlane,
        bool margin,
        hkResult keepRatio)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __int64 m_numVertices; // r8
  const float *m_vertices; // rax
  __int64 m_striding; // rdx
  unsigned int *v12; // rcx
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  int v26; // edx
  hkVector4f v27; // xmm12
  hkVector4f v28; // xmm15
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm13
  hkVector4f v34; // xmm0
  hkVector4f v35; // xmm2
  __m128 v36; // [rsp+20h] [rbp-D8h]
  __m128 v37; // [rsp+30h] [rbp-C8h]
  hkSimdFloat32 epsilon; // [rsp+40h] [rbp-B8h] BYREF

  v5 = (__m128)xmmword_141A712A0;
  v6 = (__m128)xmmword_141A712F0;
  m_numVertices = (unsigned int)points->m_numVertices;
  if ( (int)m_numVertices > 0 )
  {
    m_vertices = points->m_vertices;
    m_striding = points->m_striding;
    v12 = (unsigned int *)(m_vertices + 2);
    do
    {
      v13 = (__m128)*v12;
      v14 = (__m128)*(unsigned __int64 *)m_vertices;
      m_vertices = (const float *)((char *)m_vertices + m_striding);
      v12 = (unsigned int *)((char *)v12 + m_striding);
      v15 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v14, v13), 4), 4);
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), worldToXYPlane->m_col0.m_quad),
                  worldToXYPlane->m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), worldToXYPlane->m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), worldToXYPlane->m_col2.m_quad));
      v5 = _mm_min_ps(v5, v16);
      v6 = _mm_max_ps(v6, v16);
      --m_numVertices;
    }
    while ( m_numVertices );
  }
  v17 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_100_0), (__m128)LODWORD(FLOAT_100_0), 0), *(__m128 *)&::epsilon);
  v18 = _mm_cmplt_ps(_mm_sub_ps(v6, v5), v17);
  v19 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v5, v17), v18), _mm_andnot_ps(v18, v5));
  v20 = _mm_sub_ps(_mm_or_ps(_mm_and_ps(_mm_add_ps(v6, v17), v18), _mm_andnot_ps(v18, v6)), v19);
  if ( LOBYTE(keepRatio.m_enum) )
  {
    v21 = _mm_shuffle_ps(v20, v20, 0);
    v22 = _mm_shuffle_ps(v20, v20, 85);
    v20 = v22;
    if ( v21.m128_f32[0] <= v22.m128_f32[0] )
    {
      v19.m128_f32[0] = _mm_shuffle_ps(v19, v19, 0).m128_f32[0]
                      - (float)((float)(v22.m128_f32[0] - v21.m128_f32[0]) * 0.5);
    }
    else
    {
      v20 = v21;
      v19 = _mm_shuffle_ps(
              _mm_unpacklo_ps(
                v19,
                _mm_sub_ps(_mm_shuffle_ps(v19, v19, 85), _mm_mul_ps(_mm_sub_ps(v21, v22), (__m128)xmmword_141A711B0))),
              v19,
              228);
    }
  }
  v23 = 0i64;
  v24 = 0i64;
  v25 = _mm_rcp_ps(v20);
  v26 = margin;
  this->m_margin = v26;
  v27.m_quad = (__m128)worldToXYPlane->m_col1;
  v28.m_quad = (__m128)worldToXYPlane->m_col2;
  v23.m128_f32[0] = (float)v26;
  v24.m128_f32[0] = (float)(0x7FFFFF - 2 * v26);
  v29 = _mm_andnot_ps(
          _mm_cmpeq_ps(v20, (__m128)0i64),
          _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v25)), v25), _mm_shuffle_ps(v24, v24, 0)));
  v30 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, query.m_quad), 180);
  v31 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, query.m_quad), 196);
  v32 = _mm_mul_ps(v31, direction.m_quad);
  v33 = _mm_mul_ps(v31, stru_141A71280.m_quad);
  v37 = _mm_mul_ps(v31, transform.m_quad);
  v34.m_quad = (__m128)worldToXYPlane->m_col3;
  v36 = _mm_shuffle_ps(
          _mm_sub_ps(_mm_shuffle_ps(v23, v23, 0), _mm_mul_ps(v31, v19)),
          _mm_mul_ps(v31, qi.m_vec.m_quad),
          228);
  v35.m_quad = (__m128)worldToXYPlane->m_col0;
  epsilon.m_real = _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 255), v36);
  this->m_worldToLocal.m_col0.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v35.m_quad, v35.m_quad, 85), v32),
                                             _mm_mul_ps(_mm_shuffle_ps(v35.m_quad, v35.m_quad, 0), v37)),
                                           _mm_mul_ps(_mm_shuffle_ps(v35.m_quad, v35.m_quad, 170), v33)),
                                         _mm_mul_ps(_mm_shuffle_ps(v35.m_quad, v35.m_quad, 255), v36));
  this->m_worldToLocal.m_col3.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(v37, _mm_shuffle_ps(v34.m_quad, v34.m_quad, 0)),
                                             _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 85), v32)),
                                           _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 170), v33)),
                                         epsilon.m_real);
  this->m_worldToLocal.m_col1.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(v37, _mm_shuffle_ps(v27.m_quad, v27.m_quad, 0)),
                                             _mm_mul_ps(_mm_shuffle_ps(v27.m_quad, v27.m_quad, 85), v32)),
                                           _mm_mul_ps(_mm_shuffle_ps(v27.m_quad, v27.m_quad, 170), v33)),
                                         _mm_mul_ps(_mm_shuffle_ps(v27.m_quad, v27.m_quad, 255), v36));
  this->m_worldToLocal.m_col2.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(v37, _mm_shuffle_ps(v28.m_quad, v28.m_quad, 0)),
                                             _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 85), v32)),
                                           _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 170), v33)),
                                         _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 255), v36));
  epsilon.m_real = aabbOut.m_quad;
  __hkMatrix4UtilAlgo::setInverse(&keepRatio, &this->m_worldToLocal, &this->m_localToWorld, &epsilon);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    this,
    1);
}

// File Line: 730
// RVA: 0xB8B150
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkStridedVertices *points,
        __m128i *planeNormal,
        bool margin,
        bool keepRatio,
        bool useMainAxis)
{
  __m128i si128; // xmm4
  __m128 v10; // xmm3
  __int64 v11; // rdx
  bool v12; // zf
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  float v20; // xmm1_4
  __m128 v21; // xmm7
  __m128 v22; // xmm2
  __m128 v23; // xmm9
  __m128 v24; // xmm2
  __m128 v25; // xmm6
  __m128 v26; // xmm6
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  hkMatrix4f worldToXYPlane; // [rsp+30h] [rbp-C8h] BYREF
  hkQuaternionf qi[5]; // [rsp+70h] [rbp-88h] BYREF
  bool v35; // [rsp+138h] [rbp+40h]

  worldToXYPlane.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  worldToXYPlane.m_col0 = (hkVector4f)transform.m_quad;
  worldToXYPlane.m_col1 = (hkVector4f)direction.m_quad;
  worldToXYPlane.m_col3 = (hkVector4f)::qi.m_vec.m_quad;
  if ( keepRatio )
  {
    si128 = _mm_load_si128(planeNormal);
    v10 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
    v11 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmple_ps(
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v10, v10, 170),
                                                                       _mm_max_ps(
                                                                         _mm_shuffle_ps(v10, v10, 85),
                                                                         _mm_shuffle_ps(v10, v10, 0))),
                                                                     v10),
                                                                   (__m128)xmmword_141A4D8E0))];
    worldToXYPlane.m_col2 = (hkVector4f)*((_OWORD *)&worldToXYPlane.m_col0 + v11);
    *(&worldToXYPlane.m_col0 + v11) = (hkVector4f)stru_141A71280.m_quad;
    v12 = (_DWORD)v11 == 2;
    if ( (int)v11 < 2 )
    {
      v13 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v11], (__m128)si128);
      v14 = _mm_or_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      if ( COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 177).m128_u32[0] | v14.m128_i32[0]) > 0.0 )
      {
        v15 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        worldToXYPlane.m_col0.m_quad = _mm_xor_ps(worldToXYPlane.m_col0.m_quad, v15);
        worldToXYPlane.m_col1.m_quad = _mm_xor_ps(worldToXYPlane.m_col1.m_quad, v15);
        goto LABEL_17;
      }
      v12 = (_DWORD)v11 == 2;
    }
    if ( v12 )
    {
      v16 = _mm_and_ps((__m128)si128, (__m128)xmmword_141687F20);
      v17 = _mm_or_ps(_mm_shuffle_ps(v16, v16, 78), v16);
      if ( COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 177).m128_u32[0] | v17.m128_i32[0]) < 0.0 )
        worldToXYPlane.m_col0.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         worldToXYPlane.m_col0.m_quad);
    }
  }
  else
  {
    v18 = _mm_mul_ps(*(__m128 *)planeNormal, stru_141A71280.m_quad);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v20 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
    if ( v19.m128_f32[0] <= v20 )
    {
      if ( v19.m128_f32[0] >= (float)(0.0 - v20) )
      {
        v21 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v19), (__m128)xmmword_141A711B0);
        v22 = _mm_rsqrt_ps(v21);
        v23 = _mm_andnot_ps(
                _mm_cmple_ps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)),
                  _mm_mul_ps(v22, *(__m128 *)_xmm)));
        v24 = _mm_mul_ps(v23, (__m128)xmmword_141A711B0);
        v25 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), *(__m128 *)planeNormal),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)planeNormal, *(__m128 *)planeNormal, 201), stru_141A71280.m_quad));
        v26 = _mm_shuffle_ps(v25, v25, 201);
        if ( v19.m128_f32[0] < _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0).m128_f32[0] )
        {
          v27 = _mm_mul_ps(v26, v26);
          v28 = _mm_sub_ps(v21, v19);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                  _mm_shuffle_ps(v27, v27, 170));
          v30 = _mm_rsqrt_ps(v29);
          v31 = _mm_rsqrt_ps(v28);
          v24 = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v28, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v28), v31)),
                        _mm_mul_ps(v31, *(__m128 *)_xmm))),
                    v28),
                  _mm_andnot_ps(
                    _mm_cmple_ps(v29, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                      _mm_mul_ps(v30, *(__m128 *)_xmm))));
        }
        v32 = _mm_mul_ps(v26, v24);
        qi[0].m_vec.m_quad = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, _mm_mul_ps(v21, v23)), 196);
      }
      else
      {
        hkQuaternionf::setFlippedRotation(qi, (hkVector4f *)planeNormal);
      }
    }
    else
    {
      qi[0] = (hkQuaternionf)::qi.m_vec.m_quad;
    }
    hkRotationf::set((hkRotationf *)&qi[0].m_vec.m_quad.m128_u16[4], qi);
    worldToXYPlane.m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(*(__m128i *)((char *)qi + 8), 4), 4);
    worldToXYPlane.m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(*(__m128i *)((char *)&qi[1] + 8), 4), 4);
    worldToXYPlane.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(*(__m128i *)((char *)&qi[2] + 8), 4), 4);
    worldToXYPlane.m_col3.m_quad = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, query.m_quad), 196);
  }
LABEL_17:
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPoints(
    this,
    points,
    &worldToXYPlane,
    margin,
    v35);
}

// File Line: 944
// RVA: 0xCDF260
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *result,
        int x,
        int y)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_used; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_next; // r12
  char v9; // al
  int m_numUsed; // edi
  int v11; // r10d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v12; // rbx
  __int64 v13; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v14; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v15; // rax
  int j; // eax
  unsigned __int64 v17; // rbx
  char v18; // cl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v19; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v20; // rax
  int v21; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v22; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v23; // rdx
  int v24; // r13d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v25; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v26; // rdx
  _BOOL8 v27; // rdx
  int v28; // r8d
  __int64 *v29; // rcx
  __int64 v30; // rdx
  hkBaseObjectVtbl *v31; // r8
  __int64 v32; // rcx
  char v33; // dl
  char v34; // cl
  __int64 v35; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v37; // [rsp+20h] [rbp-E0h]
  __int64 v38; // [rsp+28h] [rbp-D8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v39; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v40; // [rsp+38h] [rbp-C8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v41; // [rsp+40h] [rbp-C0h]
  __int64 v42; // [rsp+48h] [rbp-B8h]
  hkErrStream v43; // [rsp+50h] [rbp-B0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v44; // [rsp+70h] [rbp-90h]
  __int64 v45; // [rsp+78h] [rbp-88h]
  char buf[512]; // [rsp+80h] [rbp-80h] BYREF
  int v47; // [rsp+2C0h] [rbp+1C0h]
  int v48; // [rsp+2C4h] [rbp+1C4h]
  int i; // [rsp+2D0h] [rbp+1D0h]

  m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)*((_QWORD *)&this->m_roots[(__int64)x >> 11] + (((__int64)y >> 7) & 0xFFFFFFFFFFFFFFF0ui64));
  if ( !m_used )
    m_used = this->m_mesh.m_triangles.m_used;
  m_next = this->m_mesh.m_triangles.m_used;
  v37 = m_used;
  LODWORD(v38) = 0;
  v9 = 1;
  if ( m_next )
  {
    m_numUsed = this->m_mesh.m_triangles.m_numUsed;
    v11 = 0;
    v12 = v37;
    for ( i = m_numUsed; ; m_numUsed = i )
    {
      if ( !v9 )
      {
        v44 = m_next;
        m_next = m_next->m_next;
        LODWORD(v45) = 0;
        v38 = v45;
        v11 = 0;
        v12 = v44;
      }
      v13 = v11;
      v14 = v12->m_vertices[(9i64 >> (2 * (unsigned __int8)v11)) & 3];
      v15 = v12->m_vertices[v11];
      for ( j = (y - v15->m_y) * (v14->m_x - v15->m_x) - (x - v15->m_x) * (v14->m_y - v15->m_y);
            j < 0;
            j = (y - v20->m_y) * (v19->m_x - v20->m_x) - (x - v20->m_x) * (v19->m_y - v20->m_y) )
      {
        v17 = v12->m_links[v13];
        v18 = v17;
        v12 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v17 & 0xFFFFFFFFFFFFFFFCui64);
        v11 = (9 >> (2 * (v18 & 3))) & 3;
        v13 = v11;
        LODWORD(v38) = v11;
        v19 = v12->m_vertices[(9i64 >> (2 * ((9 >> (2 * (v18 & 3))) & 3u))) & 3];
        v20 = v12->m_vertices[v11];
      }
      if ( m_numUsed > 0 )
        break;
LABEL_12:
      v9 = 0;
      if ( !m_next )
        goto LABEL_29;
    }
    while ( 1 )
    {
      v21 = (9 >> (2 * v11)) & 3;
      v39 = v12;
      LODWORD(v40) = v21;
      LODWORD(v42) = (18 >> (2 * v11)) & 3;
      v41 = v12;
      v22 = v12->m_vertices[(9i64 >> (2 * (unsigned __int8)v21)) & 3];
      v23 = v12->m_vertices[v21];
      v24 = (y - v23->m_y) * (v22->m_x - v23->m_x) - (x - v23->m_x) * (v22->m_y - v23->m_y);
      v47 = v24;
      v25 = v12->m_vertices[(9i64 >> (2 * (unsigned __int8)v42)) & 3];
      v26 = v12->m_vertices[(int)v42];
      v48 = (y - v26->m_y) * (v25->m_x - v26->m_x) - (x - v26->m_x) * (v25->m_y - v26->m_y);
      v27 = v24 >= v48;
      v28 = *(&v47 + v27);
      v29 = (__int64 *)(&v39 + 2 * v27);
      if ( v28 >= 0 )
        break;
      v30 = *((int *)v29 + 2);
      --m_numUsed;
      j = -v28;
      v31 = (hkBaseObjectVtbl *)(*(_QWORD *)(*v29 + 8 * v30 + 40) & 0xFFFFFFFFFFFFFFFCui64);
      v32 = *(_QWORD *)(*v29 + 8 * v30 + 40) & 3i64;
      v43.vfptr = v31;
      *(_DWORD *)&v43.m_memSizeAndFlags = v32;
      v38 = *(_QWORD *)&v43.m_memSizeAndFlags;
      v11 = v32;
      v12 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v31;
      if ( m_numUsed <= 0 )
        goto LABEL_12;
    }
    v33 = 0;
    if ( !v48 )
      v33 = 4;
    v34 = 0;
    if ( !v24 )
      v34 = 2;
    switch ( ((j == 0) + v34 + v33) & 7 )
    {
      case 0:
        v35 = v38;
        result->m_type.m_storage = 0;
        result->m_edge.m_triangle = v12;
        break;
      case 1:
        v35 = v38;
        result->m_type.m_storage = 1;
        result->m_edge.m_triangle = v12;
        break;
      case 2:
        v35 = v40;
        result->m_type.m_storage = 1;
        result->m_edge.m_triangle = v12;
        break;
      case 3:
        v35 = v40;
        result->m_type.m_storage = 2;
        result->m_edge.m_triangle = v12;
        break;
      case 4:
        v35 = v42;
        result->m_type.m_storage = 1;
        result->m_edge.m_triangle = v12;
        break;
      case 5:
        v35 = v38;
        result->m_type.m_storage = 2;
        result->m_edge.m_triangle = v12;
        break;
      case 6:
        v35 = v42;
        result->m_type.m_storage = 2;
        result->m_edge.m_triangle = v12;
        break;
      default:
        if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
        {
          *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
          `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard |= 1u;
        }
        result->m_type.m_storage = 3;
        goto LABEL_34;
    }
  }
  else
  {
LABEL_29:
    hkErrStream::hkErrStream(&v43, buf, 512);
    hkOstream::operator<<(&v43, "Cycle detected during point location");
    if ( (unsigned int)hkError::messageError(
                         0xB8C66B5F,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
                         938) )
      __debugbreak();
    hkOstream::~hkOstream(&v43);
    if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
    {
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard |= 1u;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
    }
    result->m_type.m_storage = 4;
LABEL_34:
    result->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e;
    v35 = *((_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e
          + 1);
  }
  *(_QWORD *)&result->m_edge.m_index = v35;
  return result;
}

// File Line: 963
// RVA: 0xCDEE70
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *result,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *rootArg,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v)
{
  __int64 v4; // rbx
  __int64 v6; // rax
  __int128 v7; // xmm0
  int m_y; // esi
  int m_x; // r14d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_used; // r15
  char v11; // al
  int m_numUsed; // edi
  int v13; // r10d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v14; // rbx
  __int64 v15; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v16; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v17; // rax
  int i; // eax
  unsigned __int64 v19; // rbx
  char v20; // cl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v21; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v22; // rax
  int v23; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v24; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v25; // rdx
  int v26; // r12d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v27; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v28; // rdx
  _BOOL8 v29; // rdx
  int v30; // r8d
  __int64 *v31; // rcx
  __int64 v32; // rdx
  hkBaseObjectVtbl *v33; // r8
  __int64 v34; // rcx
  char v35; // dl
  char v36; // cl
  __int64 v37; // rax
  __int64 v39; // [rsp+28h] [rbp-C8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v40; // [rsp+30h] [rbp-C0h] BYREF
  __int64 v41; // [rsp+38h] [rbp-B8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v42; // [rsp+40h] [rbp-B0h]
  __int64 v43; // [rsp+48h] [rbp-A8h]
  hkErrStream v44; // [rsp+50h] [rbp-A0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *buf; // [rsp+70h] [rbp-80h] BYREF
  __int64 buf_8; // [rsp+78h] [rbp-78h]
  void *retaddr; // [rsp+2B8h] [rbp+1C8h]
  __int64 v48; // [rsp+2C0h] [rbp+1D0h]

  result->m_triangle = rootArg->m_triangle;
  v6 = *(_QWORD *)&rootArg->m_index;
  *(_QWORD *)&result->m_index = v6;
  if ( result->m_triangle->m_vertices[(int)v6] != v )
  {
    v7 = (__int128)*rootArg;
    v48 = v4;
    m_y = v->m_y;
    v39 = *((_QWORD *)&v7 + 1);
    m_x = v->m_x;
    m_used = this->m_mesh.m_triangles.m_used;
    v11 = 1;
    if ( m_used )
    {
      m_numUsed = this->m_mesh.m_triangles.m_numUsed;
      v13 = DWORD2(v7);
      v14 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v7;
      LODWORD(retaddr) = m_numUsed;
      while ( 1 )
      {
        if ( !v11 )
        {
          buf = m_used;
          m_used = m_used->m_next;
          LODWORD(buf_8) = 0;
          v39 = buf_8;
          v13 = 0;
          v14 = buf;
        }
        v15 = v13;
        v16 = v14->m_vertices[(9i64 >> (2 * (unsigned __int8)v13)) & 3];
        v17 = v14->m_vertices[v13];
        for ( i = (m_y - v17->m_y) * (v16->m_x - v17->m_x) - (m_x - v17->m_x) * (v16->m_y - v17->m_y);
              i < 0;
              i = (m_y - v22->m_y) * (v21->m_x - v22->m_x) - (m_x - v22->m_x) * (v21->m_y - v22->m_y) )
        {
          v19 = v14->m_links[v15];
          v20 = v19;
          v14 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v19 & 0xFFFFFFFFFFFFFFFCui64);
          v13 = (9 >> (2 * (v20 & 3))) & 3;
          v15 = v13;
          LODWORD(v39) = v13;
          v21 = v14->m_vertices[(9i64 >> (2 * ((9 >> (2 * (v20 & 3))) & 3u))) & 3];
          v22 = v14->m_vertices[v13];
        }
        if ( m_numUsed > 0 )
          break;
LABEL_11:
        v11 = 0;
        if ( !m_used )
          goto LABEL_21;
        m_numUsed = (int)retaddr;
      }
      while ( 1 )
      {
        v23 = (9 >> (2 * v13)) & 3;
        v40 = v14;
        LODWORD(v41) = v23;
        LODWORD(v43) = (18 >> (2 * v13)) & 3;
        v42 = v14;
        v24 = v14->m_vertices[(9i64 >> (2 * (unsigned __int8)v23)) & 3];
        v25 = v14->m_vertices[v23];
        v26 = (m_y - v25->m_y) * (v24->m_x - v25->m_x) - (m_x - v25->m_x) * (v24->m_y - v25->m_y);
        LODWORD(v48) = v26;
        v27 = v14->m_vertices[(9i64 >> (2 * (unsigned __int8)v43)) & 3];
        v28 = v14->m_vertices[(int)v43];
        HIDWORD(v48) = (m_y - v28->m_y) * (v27->m_x - v28->m_x) - (m_x - v28->m_x) * (v27->m_y - v28->m_y);
        v29 = v26 >= SHIDWORD(v48);
        v30 = *((_DWORD *)&v48 + v29);
        v31 = (__int64 *)(&v40 + 2 * v29);
        if ( v30 >= 0 )
          break;
        v32 = *((int *)v31 + 2);
        --m_numUsed;
        i = -v30;
        v33 = (hkBaseObjectVtbl *)(*(_QWORD *)(*v31 + 8 * v32 + 40) & 0xFFFFFFFFFFFFFFFCui64);
        v34 = *(_QWORD *)(*v31 + 8 * v32 + 40) & 3i64;
        v44.vfptr = v33;
        *(_DWORD *)&v44.m_memSizeAndFlags = v34;
        v39 = *(_QWORD *)&v44.m_memSizeAndFlags;
        v13 = v34;
        v14 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v33;
        if ( m_numUsed <= 0 )
          goto LABEL_11;
      }
      v35 = 0;
      if ( !HIDWORD(v48) )
        v35 = 4;
      v36 = 0;
      if ( !v26 )
        v36 = 2;
      switch ( ((i == 0) + v36 + v35) & 7 )
      {
        case 0:
        case 1:
        case 5:
          v37 = v39;
          break;
        case 2:
        case 3:
          v37 = v41;
          break;
        case 4:
        case 6:
          v37 = v43;
          break;
        default:
          goto LABEL_24;
      }
    }
    else
    {
LABEL_21:
      hkErrStream::hkErrStream(&v44, (char *)&buf, 512);
      hkOstream::operator<<(&v44, "Cycle detected during point location");
      if ( (unsigned int)hkError::messageError(
                           0xB8C66B5F,
                           (const char *)&buf,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
                           938) )
        __debugbreak();
      hkOstream::~hkOstream(&v44);
LABEL_24:
      if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) != 0 )
      {
        v14 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e;
      }
      else
      {
        v14 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
        `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard |= 1u;
      }
      v37 = *((_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e
            + 1);
    }
    result->m_triangle = v14;
    *(_QWORD *)&result->m_index = v37;
  }
  return result;
}

// File Line: 975
// RVA: 0xCDED40
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingEdge(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *result,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *rootArg,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v0,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v1)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v6; // rax
  __int64 v7; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_triangle; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v9; // rdx
  int m_x; // ecx
  int m_y; // ecx
  unsigned __int64 v12; // r8
  char v13; // cl
  unsigned int m_index; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *i; // rdx
  int v16; // eax
  unsigned __int64 v17; // rdx
  char v18; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge resulta; // [rsp+20h] [rbp-18h] BYREF

  *result = *rootArg;
  v6 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
         this,
         &resulta,
         result,
         v0);
  result->m_triangle = v6->m_triangle;
  v7 = *(_QWORD *)&v6->m_index;
  *(_QWORD *)&result->m_index = v7;
  m_triangle = result->m_triangle;
  if ( result->m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v7)) & 3] != v1 )
  {
    v9 = m_triangle->m_vertices[(int)v7];
    m_x = v9->m_x;
    if ( !m_x || m_x == 0x7FFF || (m_y = v9->m_y) == 0 || m_y == 0x7FFF )
    {
      for ( ; (m_triangle->m_links[(int)v7] & 0xFFFFFFFFFFFFFFFCui64) != 0; result->m_index = v7 )
      {
        v12 = m_triangle->m_links[(int)v7];
        v13 = 2 * (v12 & 3);
        m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v12 & 0xFFFFFFFFFFFFFFFCui64);
        result->m_triangle = m_triangle;
        LODWORD(v7) = (9 >> v13) & 3;
      }
    }
    m_index = result->m_index;
    for ( i = result->m_triangle;
          i->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3] != v1;
          result->m_index = m_index )
    {
      v16 = (18 >> (2 * m_index)) & 3;
      result->m_index = v16;
      v17 = i->m_links[v16];
      v18 = v17;
      i = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v17 & 0xFFFFFFFFFFFFFFFCui64);
      m_index = v18 & 3;
      result->m_triangle = i;
    }
  }
  return result;
}

// File Line: 1125
// RVA: 0xCDD970
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertVertex(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *result,
        int x,
        int y,
        bool conform,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *location,
        bool edgeSplit)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v7; // r12
  int m_storage; // ecx
  __m128i m_edge; // xmm6
  int v13; // ecx
  __int64 v14; // rdx
  __int64 v15; // rax
  signed int v16; // esi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v17; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v18; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v19; // rdx
  int v20; // eax
  int v21; // ecx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v25; // rax
  char v26; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v27; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v28; // r8
  int v29; // ecx
  int v30; // eax
  unsigned __int64 v31; // r8
  __int64 v32; // rcx
  unsigned __int64 v33; // r8
  __int16 v34; // dx
  unsigned __int64 v35; // r8
  char v36; // al
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v37; // r8
  int v38; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v39; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v40; // r11
  int v41; // ecx
  int v42; // eax
  unsigned __int64 v43; // r9
  __int64 v44; // rcx
  unsigned __int64 v45; // r9
  __int16 v46; // dx
  int v47; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v48; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v49; // r9
  int v50; // eax
  int v51; // ecx
  unsigned __int64 v52; // r9
  __int64 v53; // rcx
  unsigned __int64 v54; // r9
  __int16 v55; // dx
  int v56; // eax
  char v57; // cl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v58; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v59; // r12
  __int64 v60; // rax
  __int64 v61; // rax
  __int64 v62; // r8
  __int64 v63; // r11
  int v64; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v65; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v66; // r13
  __int64 v67; // rax
  __int64 v68; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v69; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v70; // rcx
  __int64 v71; // r9
  __int64 v72; // rdx
  __int64 v73; // rax
  unsigned __int64 v74; // rcx
  int v75; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v76; // r10
  unsigned __int64 v77; // rcx
  int v78; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v79; // rcx
  __int64 v80; // rax
  __int64 v81; // rdx
  __int64 v82; // r8
  int v83; // eax
  int v84; // ecx
  __int64 v85; // rdx
  __int64 v86; // rcx
  unsigned __int64 v87; // rdx
  __int64 v88; // rdx
  __int64 v89; // r8
  int v90; // eax
  int v91; // ecx
  __int64 v92; // rdx
  __int64 v93; // rcx
  unsigned __int64 v94; // rdx
  __int64 v95; // rdx
  __int64 v96; // r8
  int v97; // eax
  int v98; // ecx
  __int64 v99; // rdx
  __int64 v100; // rcx
  unsigned __int64 v101; // rdx
  __int64 v102; // rdx
  __int64 v103; // r8
  int v104; // eax
  int v105; // ecx
  __int64 v106; // r8
  __int64 v107; // rcx
  unsigned __int64 v108; // r8
  __int16 v109; // ax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v110; // r15
  char v111; // al
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *p_m_stack; // rcx
  int v113; // eax
  int v114; // r9d
  int v115; // eax
  int v116; // eax
  __int64 m_prev_low; // rdx
  __int64 v118; // r8
  char v119; // cl
  int v120; // r9d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v121; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v122; // rax
  int v123; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v124; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v125; // r9
  int v126; // eax
  int v127; // ecx
  unsigned __int64 v128; // r9
  __int64 v129; // rcx
  unsigned __int64 v130; // r9
  __int16 v131; // dx
  __int64 v132; // r8
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v133; // r13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v134; // rax
  __int64 v135; // rax
  __int64 v136; // rdx
  __int16 v137; // cx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v138; // rcx
  unsigned __int64 v139; // rcx
  int v140; // r8d
  __int64 v141; // rcx
  __int64 v142; // rax
  __int64 v143; // rdx
  __int64 v144; // r8
  int v145; // eax
  int v146; // ecx
  __int64 v147; // r8
  __int64 v148; // rcx
  unsigned __int64 v149; // r8
  __int64 v150; // rdx
  __int64 v151; // r8
  int v152; // eax
  int v153; // ecx
  __int64 v154; // rdx
  __int64 v155; // rcx
  unsigned __int64 v156; // rdx
  __int64 v157; // r9
  char v158; // cl
  unsigned __int64 v159; // r9
  __int64 v160; // r10
  __int64 v161; // r8
  int v162; // eax
  int v163; // ecx
  __int64 v164; // r8
  unsigned __int64 v165; // r8
  char v166; // al
  int v167; // r9d
  int v168; // eax
  int v169; // eax
  __int64 v170; // rcx
  int v171; // eax
  __int64 v172; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v173; // rax
  __int64 v174; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v175; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v176; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v177; // r14
  __int64 v178; // rax
  __int64 v179; // rax
  int v180; // eax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v181; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v182; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_triangle; // r13
  char m_index; // al
  char v185; // bl
  int v186; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v187; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v188; // r8
  int m_x; // eax
  int v190; // ecx
  unsigned __int64 v191; // r8
  __int64 v192; // rcx
  unsigned __int64 v193; // r8
  __int16 v194; // dx
  int v195; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v196; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v197; // r10
  int v198; // eax
  int v199; // ecx
  unsigned __int64 v200; // r10
  __int64 v201; // rcx
  unsigned __int64 v202; // r10
  __int16 v203; // dx
  __int64 v204; // r8
  __int64 v205; // r9
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v206; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v207; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v208; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v209; // rax
  __int64 v210; // rax
  __int64 v211; // rdx
  unsigned __int64 v212; // rcx
  int v213; // r8d
  __int64 m_enum; // r8
  unsigned __int64 v215; // rcx
  int v216; // r9d
  __int64 v217; // rdx
  __int64 v218; // r8
  int v219; // eax
  int v220; // ecx
  __int64 v221; // rdx
  __int64 v222; // rcx
  unsigned __int64 v223; // rdx
  __int64 v224; // rdx
  __int64 v225; // r8
  int v226; // eax
  int v227; // ecx
  __int64 v228; // rax
  __int64 v229; // rcx
  unsigned __int64 v230; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v231; // rax
  int v232; // r9d
  int v233; // eax
  int v234; // eax
  __int64 m_size; // rcx
  __int64 v236; // rax
  _QWORD *p_m_triangle; // rdx
  __int64 v238; // rax
  __int64 v239; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v240; // rax
  __int64 v241; // r14
  hkResult resulta; // [rsp+30h] [rbp-D0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v[2]; // [rsp+40h] [rbp-C0h] BYREF
  int v245; // [rsp+50h] [rbp-B0h]
  unsigned int v246; // [rsp+54h] [rbp-ACh]
  unsigned int v247; // [rsp+58h] [rbp-A8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v248; // [rsp+60h] [rbp-A0h]
  __int64 v249; // [rsp+68h] [rbp-98h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v250; // [rsp+70h] [rbp-90h]
  int v251; // [rsp+78h] [rbp-88h]
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v252; // [rsp+80h] [rbp-80h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge rootArg; // [rsp+90h] [rbp-70h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v254; // [rsp+A0h] [rbp-60h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v255; // [rsp+B0h] [rbp-50h]
  int v256; // [rsp+B8h] [rbp-48h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v257; // [rsp+C0h] [rbp-40h]
  __int64 v258; // [rsp+C8h] [rbp-38h]
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState v259; // [rsp+D0h] [rbp-30h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v260; // [rsp+120h] [rbp+20h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v261; // [rsp+130h] [rbp+30h] BYREF

  v7 = this;
  m_storage = location->m_type.m_storage;
  m_edge = (__m128i)location->m_edge;
  rootArg = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)m_edge;
  if ( !m_storage )
  {
    v181 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_vertices);
    v182 = v181;
    v249 = (__int64)v181;
    if ( !v181 )
    {
      if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
      {
        v180 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard | 1;
        goto LABEL_201;
      }
      goto LABEL_202;
    }
    *(_DWORD *)&v181->m_items[0].m_data[16] = x;
    *(_DWORD *)&v181->m_items[0].m_data[20] = y;
    m_triangle = rootArg.m_triangle;
    m_index = rootArg.m_index;
    *(_QWORD *)&v182->m_items[0].m_data[24] = -3i64;
    v185 = 2 * m_index;
    v186 = (9 >> (2 * m_index)) & 3;
    LODWORD(location) = v186;
    v187 = m_triangle->m_vertices[v186];
    v188 = m_triangle->m_vertices[(9i64 >> (2 * ((9 >> (2 * m_index)) & 3u))) & 3];
    m_x = v187->m_x;
    v190 = v188->m_x;
    if ( m_x >= v190
      && (m_x > v190 || v187->m_y > v188->m_y)
      && (v191 = m_triangle->m_links[v186], (v191 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
    {
      v192 = m_triangle->m_links[v186] & 3;
      v193 = v191 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v193 = (unsigned __int64)m_triangle;
      LOBYTE(v192) = v186;
    }
    v194 = *(_WORD *)(v193 + 66);
    v245 = (unsigned __int8)v194 & (1 << v192) & 7;
    *(_WORD *)(v193 + 66) = v194 & (~(_WORD)v245 | 0xFFF8);
    v195 = (18 >> v185) & 3;
    resulta.m_enum = v195;
    v196 = m_triangle->m_vertices[v195];
    v197 = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v195)) & 3];
    v198 = v196->m_x;
    v199 = v197->m_x;
    if ( v198 >= v199
      && (v198 > v199 || v196->m_y > v197->m_y)
      && (v200 = m_triangle->m_links[v195], (v200 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
    {
      v201 = m_triangle->m_links[v195] & 3;
      v202 = v200 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v202 = (unsigned __int64)m_triangle;
      LOBYTE(v201) = v195;
    }
    v203 = *(_WORD *)(v202 + 66);
    v247 = (unsigned __int8)v203 & (1 << v201) & 7;
    v204 = (18i64 >> (2 * LOBYTE(rootArg.m_index))) & 3;
    v205 = (9i64 >> (2 * LOBYTE(rootArg.m_index))) & 3;
    *(_WORD *)(v202 + 66) = v203 & (~(_WORD)v247 | 0xFFF8);
    v248 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)&m_triangle->m_vertices[v204];
    v254.m_triangle = *v248;
    v[0] = m_triangle->m_vertices[v205];
    v206 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
    if ( v206 )
    {
      v207 = v[0];
      *(_QWORD *)&v206->m_items[0].m_data[32] = v182;
      *(_DWORD *)&v206->m_items[0].m_data[66] = 0;
      *(_QWORD *)&v206->m_items[0].m_data[16] = v207;
      *(_QWORD *)&v206->m_items[0].m_data[24] = v254.m_triangle;
    }
    v254.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)m_triangle->m_vertices[rootArg.m_index];
    v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)*v248;
    v208 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
    if ( v208 )
    {
      v209 = v[0];
      *(_DWORD *)&v208->m_items[0].m_data[66] = 0;
      *(_QWORD *)&v208->m_items[0].m_data[16] = v209;
      *(_QWORD *)&v208->m_items[0].m_data[24] = v254.m_triangle;
      v210 = v249;
      *(_QWORD *)&v208->m_items[0].m_data[32] = v249;
    }
    else
    {
      v210 = v249;
    }
    if ( !v206 || !v208 )
    {
      if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
      {
        v180 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard | 1;
        goto LABEL_201;
      }
      goto LABEL_202;
    }
    v211 = (int)location;
    *v248 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v210;
    *(_WORD *)&v206->m_items[0].m_data[66] ^= (*((_WORD *)m_triangle + 33) ^ *(_WORD *)&v206->m_items[0].m_data[66]) & 0x10;
    *(_WORD *)&v206->m_items[0].m_data[66] = *((_WORD *)m_triangle + 33) ^ (*((_WORD *)m_triangle + 33) ^ *(_WORD *)&v206->m_items[0].m_data[66]) & 0x1F;
    *(_WORD *)&v206->m_items[0].m_data[68] = m_triangle->m_sets;
    *(_WORD *)&v208->m_items[0].m_data[66] ^= (*((_WORD *)m_triangle + 33) ^ *(_WORD *)&v208->m_items[0].m_data[66]) & 0x10;
    *(_WORD *)&v208->m_items[0].m_data[66] = *((_WORD *)m_triangle + 33) ^ (*((_WORD *)m_triangle + 33) ^ *(_WORD *)&v208->m_items[0].m_data[66]) & 0x1F;
    *(_WORD *)&v208->m_items[0].m_data[68] = m_triangle->m_sets;
    v212 = m_triangle->m_links[v211] & 0xFFFFFFFFFFFFFFFCui64;
    v213 = m_triangle->m_links[v211] & 3;
    *(_QWORD *)&v206->m_items[0].m_data[40] = m_triangle->m_links[v211];
    if ( v212 )
      *(_QWORD *)(v212 + 8i64 * v213 + 40) = v206;
    m_enum = resulta.m_enum;
    v215 = m_triangle->m_links[resulta.m_enum] & 0xFFFFFFFFFFFFFFFCui64;
    v216 = m_triangle->m_links[resulta.m_enum] & 3;
    *(_QWORD *)&v208->m_items[0].m_data[40] = m_triangle->m_links[resulta.m_enum];
    if ( v215 )
      *(_QWORD *)(v215 + 8i64 * v216 + 40) = v208;
    *(_QWORD *)&v206->m_items[0].m_data[48] = &v208->m_items[0].m_data[2];
    *(_QWORD *)&v208->m_items[0].m_data[56] = &v206->m_items[0].m_data[1];
    *(_QWORD *)&v206->m_items[0].m_data[56] = (char *)m_triangle + (unsigned int)v211;
    m_triangle->m_links[v211] = (unsigned __int64)&v206->m_items[0].m_data[2];
    *(_QWORD *)&v208->m_items[0].m_data[48] = (char *)m_triangle + (unsigned int)m_enum;
    m_triangle->m_links[m_enum] = (unsigned __int64)&v208->m_items[0].m_data[1];
    if ( v245 )
    {
      v217 = *(_QWORD *)&v206->m_items[0].m_data[24];
      v218 = *(_QWORD *)&v206->m_items[0].m_data[16];
      v219 = *(_DWORD *)(v218 + 16);
      v220 = *(_DWORD *)(v217 + 16);
      if ( v219 >= v220
        && (v219 > v220 || *(_DWORD *)(v218 + 20) > *(_DWORD *)(v217 + 20))
        && (v221 = *(_QWORD *)&v206->m_items[0].m_data[40], (v221 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
      {
        v222 = *(_QWORD *)&v206->m_items[0].m_data[40] & 3i64;
        v223 = v221 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v223 = (unsigned __int64)v206;
        LOBYTE(v222) = 0;
      }
      *(_WORD *)(v223 + 66) |= (1 << v222) & 7;
    }
    if ( v247 )
    {
      v224 = *(_QWORD *)&v208->m_items[0].m_data[24];
      v225 = *(_QWORD *)&v208->m_items[0].m_data[16];
      v226 = *(_DWORD *)(v224 + 16);
      v227 = *(_DWORD *)(v225 + 16);
      if ( v227 >= v226
        && (v227 > v226 || *(_DWORD *)(v225 + 20) > *(_DWORD *)(v224 + 20))
        && (v228 = *(_QWORD *)&v208->m_items[0].m_data[40], (v228 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
      {
        v229 = *(_QWORD *)&v208->m_items[0].m_data[40] & 3i64;
        v230 = v228 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v230 = (unsigned __int64)v208;
        LOBYTE(v229) = 0;
      }
      *(_WORD *)(v230 + 66) |= (1 << v229) & 7;
    }
    v231 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)&v206->m_items[0].m_data[32];
    v254.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v206;
    v254.m_index = 2;
    v[0] = v231;
    if ( conform )
    {
      v232 = v7->m_stack.m_size + 3;
      v233 = v7->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v233 >= v232 )
      {
        LODWORD(location) = 0;
      }
      else
      {
        v234 = 2 * v233;
        if ( v232 < v234 )
          v232 = v234;
        hkArrayUtil::_reserve(
          (hkResult *)&location,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v7->m_stack.m_data,
          v232,
          16);
        if ( (_DWORD)location == 1 )
        {
          v7->m_status.m_storage = 1;
          if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
          {
            v180 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard | 1;
            goto LABEL_201;
          }
LABEL_202:
          result->m_type.m_storage = 10;
          result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e;
          return result;
        }
      }
      m_size = v7->m_stack.m_size;
      LODWORD(v258) = 0;
      v7->m_stack.m_size = m_size + 3;
      v236 = v258;
      p_m_triangle = &v7->m_stack.m_data[m_size].m_triangle;
      LODWORD(v258) = 0;
      *p_m_triangle = v206;
      p_m_triangle[1] = v236;
      v238 = v258;
      p_m_triangle[2] = v208;
      p_m_triangle[3] = v238;
      v239 = *(_QWORD *)&rootArg.m_index;
      p_m_triangle[4] = m_triangle;
      p_m_triangle[5] = v239;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::flushConform(v7);
      v240 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
               v7,
               &v260,
               &v254,
               v[0]);
      v206 = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *)v240->m_triangle;
      v241 = *(_QWORD *)&v240->m_index;
    }
    else
    {
      v241 = *(_QWORD *)&v254.m_index;
    }
    *((_QWORD *)&v7->m_roots[(__int64)(*(_DWORD *)(*(_QWORD *)&v206->m_items[0].m_data[32] + 16i64)
                                     + *(_DWORD *)(*(_QWORD *)&v206->m_items[0].m_data[24] + 16i64)
                                     + 2 * *(_DWORD *)(*(_QWORD *)&v206->m_items[0].m_data[16] + 16i64)) >> 13]
    + (((__int64)(*(_DWORD *)(*(_QWORD *)&v206->m_items[0].m_data[32] + 20i64)
                + *(_DWORD *)(*(_QWORD *)&v206->m_items[0].m_data[24] + 20i64)
                + 2 * *(_DWORD *)(*(_QWORD *)&v206->m_items[0].m_data[16] + 20i64)) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)) = v206;
    *(_WORD *)&v206->m_items[0].m_data[66] |= 8u;
    result->m_type.m_storage = 0;
    result->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v206;
    *(_QWORD *)&result->m_edge.m_index = v241;
    return result;
  }
  v13 = m_storage - 1;
  if ( !v13 )
  {
    v16 = rootArg.m_index;
    v17 = rootArg.m_triangle;
    if ( !edgeSplit )
    {
      if ( (v18 = rootArg.m_triangle->m_vertices[rootArg.m_index],
            v19 = rootArg.m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(rootArg.m_index))) & 3],
            v20 = v18->m_x,
            v21 = v19->m_x,
            v20 >= v21)
        && (v20 > v21 || v18->m_y > v19->m_y)
        && (v22 = rootArg.m_triangle->m_links[rootArg.m_index], (v22 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
      {
        v23 = rootArg.m_triangle->m_links[rootArg.m_index] & 3;
        v24 = v22 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v24 = (unsigned __int64)rootArg.m_triangle;
        LOBYTE(v23) = rootArg.m_index;
      }
      if ( ((1 << v23) & 7 & *(_BYTE *)(v24 + 66)) != 0 )
      {
        result->m_type.m_storage = 2;
        result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)m_edge;
        return result;
      }
    }
    v25 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_vertices);
    v252 = v25;
    if ( v25 )
    {
      *(_DWORD *)&v25->m_items[0].m_data[20] = y;
      v26 = 2 * v16;
      *(_DWORD *)&v25->m_items[0].m_data[16] = x;
      LODWORD(location) = 2 * v16;
      *(_QWORD *)&v25->m_items[0].m_data[24] = -3i64;
      v27 = v17->m_vertices[(9i64 >> (2 * (unsigned __int8)v16)) & 3];
      v28 = v17->m_vertices[v16];
      v29 = v27->m_x;
      v250 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)&v17->m_vertices[v16];
      v30 = v28->m_x;
      if ( v30 >= v29
        && (v30 > v29 || v28->m_y > v27->m_y)
        && (v31 = v17->m_links[v16], (v31 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
      {
        v32 = v17->m_links[v16] & 3;
        v33 = v31 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v33 = (unsigned __int64)v17;
        LOBYTE(v32) = v16;
      }
      v34 = *(_WORD *)(v33 + 66);
      v251 = (unsigned __int8)v34 & (1 << v32) & 7;
      *(_WORD *)(v33 + 66) = v34 & (~((unsigned __int8)v34 & (1 << v32) & 7) | 0xFFF8);
      v259.m_values[0].m_hasData = 0;
      v259.m_values[0].m_data.m_tags.m_data = v259.m_values[0].m_data.m_tags.m_storage;
      v259.m_values[0].m_data.m_tags.m_size = 0;
      v259.m_values[0].m_data.m_tags.m_capacityAndFlags = -2147483646;
      v259.m_values[1].m_hasData = 0;
      v259.m_values[1].m_data.m_tags.m_size = 0;
      v259.m_values[1].m_data.m_tags.m_data = v259.m_values[1].m_data.m_tags.m_storage;
      v259.m_values[1].m_data.m_tags.m_capacityAndFlags = -2147483646;
      if ( ((unsigned __int8)v34 & (1 << v32) & 7) != 0 )
      {
        *(__m128i *)v = m_edge;
        hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::backupBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
          &v7->m_edgeDataPolicy,
          v7,
          (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
          &v259);
        v26 = (char)location;
      }
      v35 = v17->m_links[v16];
      v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v17->m_links[v16];
      if ( (v35 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v36 = v35;
        v37 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)(v35 & 0xFFFFFFFFFFFFFFFCui64);
        v248 = v37;
        v246 = v36 & 3;
        v38 = (18 >> v26) & 3;
        v256 = v38;
        v39 = v17->m_vertices[(9i64 >> (2 * ((18 >> v26) & 3u))) & 3];
        v40 = v17->m_vertices[v38];
        v41 = v39->m_x;
        v42 = v40->m_x;
        if ( v42 >= v41
          && (v42 > v41 || v40->m_y > v39->m_y)
          && (v43 = v17->m_links[v38], (v43 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
        {
          v44 = v17->m_links[v38] & 3;
          v45 = v43 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v45 = (unsigned __int64)v17;
          LOBYTE(v44) = v38;
        }
        v46 = *(_WORD *)(v45 + 66);
        v245 = (unsigned __int8)v46 & (1 << v44) & 7;
        *(_WORD *)(v45 + 66) = v46 & (~(_WORD)v245 | 0xFFF8);
        v249 = 2 * v246;
        v47 = (18 >> (2 * v246)) & 3;
        v247 = v47;
        v48 = v37[v47 + 2];
        v254.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v47;
        v49 = v37[((9i64 >> (2 * ((18 >> (2 * v246)) & 3u))) & 3) + 2];
        v50 = (int)v48->m_vertices[0];
        v51 = (int)v49->m_vertices[0];
        if ( v50 >= v51
          && (v50 > v51 || SHIDWORD(v48->m_vertices[0]) > SHIDWORD(v49->m_vertices[0]))
          && (v52 = (unsigned __int64)v37[v47 + 5], (v52 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
        {
          v53 = (unsigned __int64)v37[v47 + 5] & 3;
          v54 = v52 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v54 = (unsigned __int64)v37;
          LOBYTE(v53) = v47;
        }
        v55 = *(_WORD *)(v54 + 66);
        v56 = 1 << v53;
        v57 = (char)location;
        resulta.m_enum = (unsigned __int8)v55 & v56 & 7;
        *(_WORD *)(v54 + 66) = v55 & (~LOWORD(resulta.m_enum) | 0xFFF8);
        v58 = *v250;
        v255 = v17->m_vertices[(18i64 >> v57) & 3];
        v59 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
        if ( v59 )
        {
          v60 = (__int64)v255;
          *(_QWORD *)&v59->m_items[0].m_data[24] = v58;
          *(_DWORD *)&v59->m_items[0].m_data[66] = 0;
          *(_QWORD *)&v59->m_items[0].m_data[16] = v60;
          v61 = (__int64)v252;
          *(_QWORD *)&v59->m_items[0].m_data[32] = v252;
          v62 = *(_QWORD *)&v59->m_items[0].m_data[16];
          v63 = v61;
          LODWORD(v61) = v58->m_vertices[0];
          v64 = *(_DWORD *)(v63 + 20) + HIDWORD(v58->m_vertices[0]) + 2 * *(_DWORD *)(v62 + 20);
          v65 = this;
          *((_QWORD *)&this->m_roots[(__int64)(*(_DWORD *)(v63 + 16) + (int)v61 + 2 * *(_DWORD *)(v62 + 16)) >> 13]
          + (((__int64)v64 >> 9) & 0xFFFFFFFFFFFFFFF0ui64)) = v59;
          *(_WORD *)&v59->m_items[0].m_data[66] |= 8u;
        }
        else
        {
          v65 = this;
        }
        v257 = v248[(int)v246 + 2];
        v255 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v248[((18i64 >> v249) & 3) + 2];
        v66 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v65->m_mesh.m_triangles);
        if ( v66 )
        {
          v67 = (__int64)v255;
          *(_DWORD *)&v66->m_items[0].m_data[66] = 0;
          *(_QWORD *)&v66->m_items[0].m_data[16] = v67;
          *(_QWORD *)&v66->m_items[0].m_data[24] = v257;
          v68 = (__int64)v252;
          *(_QWORD *)&v66->m_items[0].m_data[32] = v252;
          *((_QWORD *)&v65->m_roots[(__int64)(*(_DWORD *)(v68 + 16)
                                            + *(_DWORD *)(*(_QWORD *)&v66->m_items[0].m_data[24] + 16i64)
                                            + 2 * *(_DWORD *)(*(_QWORD *)&v66->m_items[0].m_data[16] + 16i64)) >> 13]
          + (((__int64)(*(_DWORD *)(v68 + 20)
                      + *(_DWORD *)(*(_QWORD *)&v66->m_items[0].m_data[24] + 20i64)
                      + 2 * *(_DWORD *)(*(_QWORD *)&v66->m_items[0].m_data[16] + 20i64)) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)) = v66;
          *(_WORD *)&v66->m_items[0].m_data[66] |= 8u;
        }
        if ( v59 && v66 )
        {
          v69 = v248;
          v70 = v250;
          v71 = (int)v246;
          v72 = v256;
          *(_WORD *)&v59->m_items[0].m_data[66] ^= (*((_WORD *)v17 + 33) ^ *(_WORD *)&v59->m_items[0].m_data[66]) & 0x10;
          *(_WORD *)&v59->m_items[0].m_data[66] = *((_WORD *)v17 + 33) ^ (*(_WORD *)&v59->m_items[0].m_data[66] ^ *((_WORD *)v17 + 33)) & 0x1F;
          *(_WORD *)&v59->m_items[0].m_data[68] = v17->m_sets;
          *(_WORD *)&v66->m_items[0].m_data[66] ^= (*(_WORD *)&v66->m_items[0].m_data[66] ^ *((_WORD *)v69 + 33)) & 0x10;
          *(_WORD *)&v66->m_items[0].m_data[66] = *((_WORD *)v69 + 33) ^ (*(_WORD *)&v66->m_items[0].m_data[66] ^ *((_WORD *)v69 + 33)) & 0x1F;
          *(_WORD *)&v66->m_items[0].m_data[68] = *((_WORD *)v69 + 34);
          v73 = (__int64)v252;
          v69[v71 + 2] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v252;
          *v70 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v73;
          v74 = v17->m_links[v72] & 0xFFFFFFFFFFFFFFFCui64;
          v75 = v17->m_links[v72] & 3;
          *(_QWORD *)&v59->m_items[0].m_data[40] = v17->m_links[v72];
          if ( v74 )
            *(_QWORD *)(v74 + 8i64 * v75 + 40) = v59;
          v76 = v254.m_triangle;
          v77 = (unsigned __int64)v69[(__int64)v254.m_triangle + 5] & 0xFFFFFFFFFFFFFFFCui64;
          v78 = (__int64)v69[(__int64)v254.m_triangle + 5] & 3;
          *(_QWORD *)&v66->m_items[0].m_data[40] = v69[(__int64)v254.m_triangle + 5];
          if ( v77 )
            *(_QWORD *)(v77 + 8i64 * v78 + 40) = v66;
          v79 = v[0];
          *(_QWORD *)&v59->m_items[0].m_data[48] = (char *)v69 + v246;
          v69[v71 + 5] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)&v59->m_items[0].m_data[1];
          *(_QWORD *)&v66->m_items[0].m_data[48] = (char *)v17 + rootArg.m_index;
          v79->m_next = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v66->m_items[0].m_data[1];
          *(_QWORD *)&v59->m_items[0].m_data[56] = (char *)v17 + (unsigned int)v72;
          v80 = v247;
          v17->m_links[v72] = (unsigned __int64)&v59->m_items[0].m_data[2];
          *(_QWORD *)&v66->m_items[0].m_data[56] = (char *)v69 + v80;
          v69[(_QWORD)v76 + 5] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)&v66->m_items[0].m_data[2];
          if ( v245 )
          {
            v81 = *(_QWORD *)&v59->m_items[0].m_data[24];
            v82 = *(_QWORD *)&v59->m_items[0].m_data[16];
            v83 = *(_DWORD *)(v82 + 16);
            v84 = *(_DWORD *)(v81 + 16);
            if ( v83 >= v84
              && (v83 > v84 || *(_DWORD *)(v82 + 20) > *(_DWORD *)(v81 + 20))
              && (v85 = *(_QWORD *)&v59->m_items[0].m_data[40], (v85 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v86 = *(_QWORD *)&v59->m_items[0].m_data[40] & 3i64;
              v87 = v85 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v87 = (unsigned __int64)v59;
              LOBYTE(v86) = 0;
            }
            *(_WORD *)(v87 + 66) |= (1 << v86) & 7;
          }
          if ( resulta.m_enum )
          {
            v88 = *(_QWORD *)&v66->m_items[0].m_data[24];
            v89 = *(_QWORD *)&v66->m_items[0].m_data[16];
            v90 = *(_DWORD *)(v89 + 16);
            v91 = *(_DWORD *)(v88 + 16);
            if ( v90 >= v91
              && (v90 > v91 || *(_DWORD *)(v89 + 20) > *(_DWORD *)(v88 + 20))
              && (v92 = *(_QWORD *)&v66->m_items[0].m_data[40], (v92 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v93 = *(_QWORD *)&v66->m_items[0].m_data[40] & 3i64;
              v94 = v92 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v94 = (unsigned __int64)v66;
              LOBYTE(v93) = 0;
            }
            *(_WORD *)(v94 + 66) |= (1 << v93) & 7;
          }
          if ( edgeSplit && v251 )
          {
            v95 = *(_QWORD *)&v59->m_items[0].m_data[32];
            v96 = *(_QWORD *)&v59->m_items[0].m_data[24];
            v97 = *(_DWORD *)(v96 + 16);
            v98 = *(_DWORD *)(v95 + 16);
            if ( v97 >= v98
              && (v97 > v98 || *(_DWORD *)(v96 + 20) > *(_DWORD *)(v95 + 20))
              && (v99 = *(_QWORD *)&v59->m_items[0].m_data[48], (v99 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v100 = *(_QWORD *)&v59->m_items[0].m_data[48] & 3i64;
              v101 = v99 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v101 = (unsigned __int64)v59;
              LOBYTE(v100) = 1;
            }
            *(_WORD *)(v101 + 66) |= (1 << v100) & 7;
            v102 = *(_QWORD *)&v66->m_items[0].m_data[32];
            v103 = *(_QWORD *)&v66->m_items[0].m_data[24];
            v104 = *(_DWORD *)(v103 + 16);
            v105 = *(_DWORD *)(v102 + 16);
            if ( v104 >= v105
              && (v104 > v105 || *(_DWORD *)(v103 + 20) > *(_DWORD *)(v102 + 20))
              && (v106 = *(_QWORD *)&v66->m_items[0].m_data[48], (v106 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v107 = *(_QWORD *)&v66->m_items[0].m_data[48] & 3i64;
              v108 = v106 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v108 = (unsigned __int64)v66;
              LOBYTE(v107) = 1;
            }
            v109 = *(_WORD *)(v108 + 66);
            LODWORD(v[1]) = 1;
            v110 = this;
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v59;
            *(_WORD *)(v108 + 66) = v109 ^ ((unsigned __int8)v109 ^ (unsigned __int8)(v109 | (1 << v107))) & 7;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              &this->m_edgeDataPolicy,
              this,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v259);
            v111 = *(_QWORD *)&v66->m_items[0].m_data[48];
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)(*(_QWORD *)&v66->m_items[0].m_data[48] & 0xFFFFFFFFFFFFFFFCui64);
            LODWORD(v[1]) = v111 & 3;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              &v110->m_edgeDataPolicy,
              v110,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v259);
            v69 = v248;
          }
          else
          {
            v110 = this;
          }
          if ( conform )
          {
            p_m_stack = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v110->m_stack;
            v113 = v110->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
            v114 = v110->m_stack.m_size + 4;
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v110->m_stack;
            if ( v113 < v114 )
            {
              v115 = 2 * v113;
              if ( v114 < v115 )
                v114 = v115;
              hkArrayUtil::_reserve(
                &resulta,
                &hkContainerHeapAllocator::s_alloc,
                (const void **)&v110->m_stack.m_data,
                v114,
                16);
              if ( resulta.m_enum == HK_FAILURE )
              {
                v110->m_status.m_storage = 1;
                if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) != 0 )
                {
LABEL_93:
                  result->m_type.m_storage = 10;
                  result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e;
                  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::EdgeDataState::~EdgeDataState(&v259);
                  return result;
                }
                v116 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard | 1;
LABEL_92:
                `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard = v116;
                *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
                DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
                goto LABEL_93;
              }
              p_m_stack = v[0];
            }
            m_prev_low = SLODWORD(p_m_stack->m_prev);
            LODWORD(v[1]) = 0;
            LODWORD(p_m_stack->m_prev) = m_prev_low + 4;
            v118 = (__int64)p_m_stack->m_next + 16 * m_prev_low;
            v119 = (char)location;
            *(_QWORD *)v118 = v17;
            v120 = 9 >> v249;
            *(_DWORD *)(v118 + 8) = (9 >> v119) & 3;
            v121 = v[1];
            *(_QWORD *)(v118 + 16) = v69;
            LODWORD(v[1]) = 0;
            *(_DWORD *)(v118 + 24) = v120 & 3;
            *(_QWORD *)(v118 + 32) = v59;
            v7 = this;
            *(_QWORD *)(v118 + 40) = v121;
            v122 = v[1];
            *(_QWORD *)(v118 + 48) = v66;
            *(_QWORD *)(v118 + 56) = v122;
LABEL_142:
            v175 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)*v250;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::flushConform(v7);
            v176 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
                     v7,
                     &v261,
                     &rootArg,
                     v175);
            v177 = v176->m_triangle;
            v178 = *(_QWORD *)&v176->m_index;
            result->m_type.m_storage = 0;
            result->m_edge.m_triangle = v177;
            *(_QWORD *)&result->m_edge.m_index = v178;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::EdgeDataState::~EdgeDataState(&v259);
            return result;
          }
LABEL_143:
          v179 = *(_QWORD *)&rootArg.m_index;
          result->m_type.m_storage = 0;
          result->m_edge.m_triangle = v17;
          *(_QWORD *)&result->m_edge.m_index = v179;
          hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::EdgeDataState::~EdgeDataState(&v259);
          return result;
        }
      }
      else
      {
        v123 = (18 >> v26) & 3;
        resulta.m_enum = v123;
        v124 = v17->m_vertices[v123];
        v125 = v17->m_vertices[(9i64 >> (2 * ((18 >> v26) & 3u))) & 3];
        v126 = v124->m_x;
        v127 = v125->m_x;
        if ( v126 >= v127
          && (v126 > v127 || v124->m_y > v125->m_y)
          && (v128 = v17->m_links[v123], (v128 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
        {
          v129 = v17->m_links[v123] & 3;
          v130 = v128 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v130 = (unsigned __int64)v17;
          LOBYTE(v129) = v123;
        }
        v131 = *(_WORD *)(v130 + 66);
        v132 = (18i64 >> (char)location) & 3;
        v245 = (unsigned __int8)v131 & (1 << v129) & 7;
        *(_WORD *)(v130 + 66) = v131 & (~(_WORD)v245 | 0xFFF8);
        v254.m_triangle = *v250;
        v[0] = v17->m_vertices[v132];
        v133 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
        if ( v133 )
        {
          v134 = v[0];
          *(_DWORD *)&v133->m_items[0].m_data[66] = 0;
          *(_QWORD *)&v133->m_items[0].m_data[16] = v134;
          *(_QWORD *)&v133->m_items[0].m_data[24] = v254.m_triangle;
          v135 = (__int64)v252;
          *(_QWORD *)&v133->m_items[0].m_data[32] = v252;
          v136 = resulta.m_enum;
          *((_QWORD *)&v7->m_roots[(__int64)(*(_DWORD *)(v135 + 16)
                                           + *(_DWORD *)(*(_QWORD *)&v133->m_items[0].m_data[24] + 16i64)
                                           + 2 * *(_DWORD *)(*(_QWORD *)&v133->m_items[0].m_data[16] + 16i64)) >> 13]
          + (((__int64)(*(_DWORD *)(v135 + 20)
                      + *(_DWORD *)(*(_QWORD *)&v133->m_items[0].m_data[24] + 20i64)
                      + 2 * *(_DWORD *)(*(_QWORD *)&v133->m_items[0].m_data[16] + 20i64)) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)) = v133;
          *(_WORD *)&v133->m_items[0].m_data[66] |= 8u;
          v137 = *(_WORD *)&v133->m_items[0].m_data[66] ^ (*(_WORD *)&v133->m_items[0].m_data[66] ^ *((_WORD *)v17 + 33)) & 0x10;
          *(_WORD *)&v133->m_items[0].m_data[66] = v137;
          *(_WORD *)&v133->m_items[0].m_data[66] = *((_WORD *)v17 + 33) ^ (*((_WORD *)v17 + 33) ^ v137) & 0x1F;
          v138 = v250;
          *(_WORD *)&v133->m_items[0].m_data[68] = v17->m_sets;
          *v138 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v135;
          v139 = v17->m_links[v136] & 0xFFFFFFFFFFFFFFFCui64;
          v140 = v17->m_links[v136] & 3;
          *(_QWORD *)&v133->m_items[0].m_data[40] = v17->m_links[v136];
          if ( v139 )
            *(_QWORD *)(v139 + 8i64 * v140 + 40) = v133;
          if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) != 0 )
          {
            v142 = DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e);
            v141 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e;
          }
          else
          {
            v141 = 0i64;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard |= 1u;
            v142 = 0i64;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
          }
          *(_QWORD *)&v133->m_items[0].m_data[48] = v141 + v142;
          if ( (_QWORD)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e )
            *(_QWORD *)(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e
                      + 8i64
                      * SDWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e)
                      + 40) = &v133->m_items[0].m_data[1];
          *(_QWORD *)&v133->m_items[0].m_data[56] = (char *)v17 + (unsigned int)v136;
          v17->m_links[v136] = (unsigned __int64)&v133->m_items[0].m_data[2];
          if ( v245 )
          {
            v143 = *(_QWORD *)&v133->m_items[0].m_data[24];
            v144 = *(_QWORD *)&v133->m_items[0].m_data[16];
            v145 = *(_DWORD *)(v144 + 16);
            v146 = *(_DWORD *)(v143 + 16);
            if ( v145 >= v146
              && (v145 > v146 || *(_DWORD *)(v144 + 20) > *(_DWORD *)(v143 + 20))
              && (v147 = *(_QWORD *)&v133->m_items[0].m_data[40], (v147 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v148 = *(_QWORD *)&v133->m_items[0].m_data[40] & 3i64;
              v149 = v147 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v149 = (unsigned __int64)v133;
              LOBYTE(v148) = 0;
            }
            *(_WORD *)(v149 + 66) ^= ((unsigned __int8)*(_WORD *)(v149 + 66) ^ (unsigned __int8)(*(_WORD *)(v149 + 66) | (1 << v148))) & 7;
          }
          if ( edgeSplit && v251 )
          {
            v150 = *(_QWORD *)&v133->m_items[0].m_data[32];
            v151 = *(_QWORD *)&v133->m_items[0].m_data[24];
            v152 = *(_DWORD *)(v151 + 16);
            v153 = *(_DWORD *)(v150 + 16);
            if ( v152 >= v153
              && (v152 > v153 || *(_DWORD *)(v151 + 20) > *(_DWORD *)(v150 + 20))
              && (v154 = *(_QWORD *)&v133->m_items[0].m_data[48], (v154 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v155 = *(_QWORD *)&v133->m_items[0].m_data[48] & 3i64;
              v156 = v154 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v156 = (unsigned __int64)v133;
              LOBYTE(v155) = 1;
            }
            *(_WORD *)(v156 + 66) |= (1 << v155) & 7;
            v157 = *(_QWORD *)&v133->m_items[0].m_data[56];
            v158 = 2 * (v157 & 3);
            v159 = v157 & 0xFFFFFFFFFFFFFFFCui64;
            LODWORD(v156) = (9 >> v158) & 3;
            v160 = *(_QWORD *)(v159 + 8i64 * (int)v156 + 16);
            v161 = *(_QWORD *)(v159 + 8 * ((9i64 >> (2 * ((9 >> v158) & 3u))) & 3) + 16);
            v162 = *(_DWORD *)(v160 + 16);
            v163 = *(_DWORD *)(v161 + 16);
            if ( v162 >= v163
              && (v162 > v163 || *(_DWORD *)(v160 + 20) > *(_DWORD *)(v161 + 20))
              && (v164 = *(_QWORD *)(v159 + 8i64 * (int)v156 + 40), (v164 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v156 = *(_QWORD *)(v159 + 8i64 * (int)v156 + 40) & 3i64;
              v165 = v164 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v165 = v159;
            }
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v133;
            LODWORD(v[1]) = 1;
            *(_WORD *)(v165 + 66) |= (1 << v156) & 7;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              &v7->m_edgeDataPolicy,
              v7,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v259);
            v166 = *(_QWORD *)&v133->m_items[0].m_data[56];
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)(*(_QWORD *)&v133->m_items[0].m_data[56] & 0xFFFFFFFFFFFFFFFCui64);
            LODWORD(v[1]) = v166 & 3;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              &v7->m_edgeDataPolicy,
              v7,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v259);
          }
          if ( !conform )
            goto LABEL_143;
          v167 = v7->m_stack.m_size + 2;
          v168 = v7->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v168 >= v167 )
            goto LABEL_141;
          v169 = 2 * v168;
          if ( v167 < v169 )
            v167 = v169;
          hkArrayUtil::_reserve(
            &resulta,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v7->m_stack.m_data,
            v167,
            16);
          if ( resulta.m_enum != HK_FAILURE )
          {
LABEL_141:
            v170 = v7->m_stack.m_size;
            LODWORD(v[1]) = 0;
            v171 = v170 + 2;
            v172 = v170;
            LOBYTE(v170) = (_BYTE)location;
            v7->m_stack.m_size = v171;
            v173 = v[1];
            v174 = (__int64)&v7->m_stack.m_data[v172];
            *(_QWORD *)v174 = v17;
            *(_DWORD *)(v174 + 8) = (9 >> v170) & 3;
            *(_QWORD *)(v174 + 16) = v133;
            *(_QWORD *)(v174 + 24) = v173;
            goto LABEL_142;
          }
          v7->m_status.m_storage = 1;
        }
      }
      if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) != 0 )
        goto LABEL_93;
      v116 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard | 1;
      goto LABEL_92;
    }
    if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
    {
      v180 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard | 1;
LABEL_201:
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard = v180;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
      goto LABEL_202;
    }
    goto LABEL_202;
  }
  if ( v13 == 1 )
  {
    v14 = *(_QWORD *)(m_edge.m128i_i64[0] + 8i64 * _mm_srli_si128(m_edge, 8).m128i_i32[0] + 16);
    v15 = *(_QWORD *)(v14 + 24);
    if ( (v15 & 1) != 0 )
    {
      result->m_type.m_storage = 1;
    }
    else
    {
      *(_QWORD *)(v14 + 24) = v15 | 1;
      result->m_type.m_storage = 0;
    }
    result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)m_edge;
  }
  else
  {
    if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e) = 0;
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::`local static guard |= 1u;
    }
    result->m_type.m_storage = 11;
    result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null::`2::e;
  }
  return result;
}ult;
}

// File Line: 1315
// RVA: 0xB68180
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *result,
        int x,
        int y,
        bool conform)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Location resulta; // [rsp+40h] [rbp-38h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v11; // [rsp+58h] [rbp-20h] BYREF

  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
    this,
    &resulta,
    x,
    y);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
    this,
    result,
    x,
    y,
    conform,
    &resulta,
    0);
  if ( result->m_type.m_storage == 2 )
  {
    resulta.m_edge = result->m_edge;
    resulta.m_type.m_storage = 1;
    *result = *hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
                 this,
                 &v11,
                 x,
                 y,
                 conform,
                 &resulta,
                 1);
  }
  return result;
}

// File Line: 1386
// RVA: 0xB69D30
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertEdge(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *result,
        int x0,
        int y0,
        int x1,
        int y1,
        bool conform,
        hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *data)
{
  hkResultEnum v8; // r12d
  int v9; // r15d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v10; // rsi
  unsigned __int64 m_triangle; // rbx
  int v13; // ecx
  __int64 v14; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v15; // r9
  __int64 v16; // rax
  int m_x; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v18; // r8
  __int64 v19; // rbx
  char v20; // cl
  __int64 v21; // r11
  __int64 v22; // rdx
  __int64 v23; // rax
  int v24; // r13d
  __int64 v25; // r8
  __int64 v26; // rcx
  __int64 v27; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v28; // rax
  unsigned __int64 v29; // r10
  int v30; // edx
  __int64 v31; // rax
  signed int m_index; // r13d
  __int64 v33; // r9
  int v34; // ecx
  __int64 v35; // r15
  __int64 v36; // r8
  int v37; // eax
  __int64 v38; // rax
  __int64 v39; // rcx
  unsigned __int64 v40; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v41; // xmm0
  int v42; // eax
  int v43; // ecx
  __int64 v44; // rdx
  unsigned __int64 v45; // rdx
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v46; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v47; // r11
  int v48; // r9d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v49; // r10
  BOOL v50; // ecx
  int v51; // r15d
  int v52; // eax
  int v53; // r9d
  int v54; // eax
  __int128 v55; // xmm0
  char v56; // cl
  __int64 v57; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *v58; // r8
  int v59; // edi
  int v60; // r14d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v61; // xmm0
  bool v62; // zf
  __int64 v63; // r8
  int v64; // eax
  int v65; // ecx
  __int64 v66; // r8
  __int64 v67; // rax
  __int64 v68; // rcx
  unsigned __int64 v69; // rax
  __int64 v70; // r10
  char v71; // al
  char v72; // r13
  __int64 v73; // rcx
  __int64 v74; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v75; // xmm0
  __int64 v76; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v77; // r9
  __int64 v78; // rcx
  __int64 v79; // rax
  __int64 v80; // rdx
  int v81; // r9d
  int v82; // r12d
  int v83; // eax
  int m_y; // eax
  __int64 v85; // r15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *m_next; // r13
  int v87; // edx
  __int64 v88; // rdx
  char v89; // si
  int v90; // r10d
  int v91; // r11d
  __int64 v92; // rcx
  int v93; // r8d
  int v94; // r9d
  __int64 v95; // r15
  __int64 v96; // r10
  __int64 v97; // rbx
  char v98; // cl
  __int64 v99; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v100; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v101; // rsi
  __int64 v102; // r10
  int v103; // ebx
  unsigned __int64 v104; // r8
  __int64 v105; // rax
  __int64 v106; // r10
  __int64 v107; // r9
  char v108; // r15
  int v109; // ecx
  __int64 v110; // r11
  int v111; // edx
  unsigned __int64 v112; // rcx
  int v113; // edx
  __int64 v114; // r15
  __int64 v115; // r11
  int v116; // edx
  __int64 v117; // r8
  unsigned __int64 v118; // r8
  unsigned __int64 v119; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v120; // rdx
  __int64 v121; // rax
  char v122; // r10
  __int64 v123; // rcx
  int v124; // r11d
  int v125; // ebx
  unsigned __int64 v126; // r8
  __int64 v127; // r8
  char v128; // r9
  char v129; // r9
  __int64 v130; // rcx
  __int64 v131; // r15
  __int64 v132; // r8
  unsigned __int64 v133; // r12
  int v134; // eax
  __int64 v135; // rdx
  int v136; // ecx
  __int64 v137; // rdx
  unsigned __int64 v138; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v139; // r10
  int m_size; // r9d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v141; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v142; // r8
  BOOL v143; // r12d
  int v144; // r15d
  int m_capacityAndFlags; // eax
  int v146; // eax
  int v147; // r9d
  int v148; // eax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v149; // xmm0
  __int64 v150; // rdx
  char v151; // cl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *v152; // rdx
  int v153; // edi
  int v154; // r14d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge edge; // [rsp+30h] [rbp-B9h] BYREF
  __int64 v156; // [rsp+40h] [rbp-A9h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v0; // [rsp+48h] [rbp-A1h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v158; // [rsp+50h] [rbp-99h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Location resulta; // [rsp+60h] [rbp-89h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v160; // [rsp+80h] [rbp-69h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v1[2]; // [rsp+90h] [rbp-59h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v162; // [rsp+A0h] [rbp-49h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v163; // [rsp+B0h] [rbp-39h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v164; // [rsp+C0h] [rbp-29h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v165; // [rsp+D0h] [rbp-19h]
  hkResult v168; // [rsp+140h] [rbp+57h] BYREF
  int v169; // [rsp+148h] [rbp+5Fh]

  v169 = y0;
  v168.m_enum = x0;
  v8 = x1;
  v9 = y1;
  v10 = result;
  if ( x0 == x1 && y0 == y1 )
  {
    if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
    }
    result->m_type.m_storage = 9;
    result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e;
    return result;
  }
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
    this,
    &resulta,
    x0,
    y0);
  if ( resulta.m_type.m_storage != 2 )
  {
    if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
    }
    v10->m_type.m_storage = 6;
    v10->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e;
    return v10;
  }
  edge = resulta.m_edge;
  m_triangle = (unsigned __int64)resulta.m_edge.m_triangle;
  v13 = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)resulta.m_edge, 8));
  v14 = v13;
  v15 = resulta.m_edge.m_triangle->m_vertices[v13];
  v16 = 9i64 >> (2 * (unsigned __int8)v13);
  m_x = v15->m_x;
  v0 = v15;
  v18 = resulta.m_edge.m_triangle->m_vertices[v16 & 3];
  if ( (v9 - v15->m_y) * (__int64)(v18->m_x - m_x) - (v8 - m_x) * (__int64)(v18->m_y - v15->m_y) >= 0 )
  {
    LODWORD(v21) = edge.m_index;
  }
  else
  {
    do
    {
      v19 = *(_QWORD *)(m_triangle + 8 * v14 + 40);
      v20 = v19;
      m_triangle = v19 & 0xFFFFFFFFFFFFFFFCui64;
      LODWORD(v21) = (9 >> (2 * (v20 & 3))) & 3;
      v14 = (int)v21;
      edge.m_index = v21;
      v22 = *(_QWORD *)(m_triangle + 8 * ((9i64 >> (2 * ((9 >> (2 * (v20 & 3))) & 3u))) & 3) + 16);
      v23 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 16);
    }
    while ( (v9 - *(_DWORD *)(v23 + 20)) * (__int64)(*(_DWORD *)(v22 + 16) - *(_DWORD *)(v23 + 16))
          - (v8 - *(_DWORD *)(v23 + 16)) * (__int64)(*(_DWORD *)(v22 + 20) - *(_DWORD *)(v23 + 20)) < 0 );
    edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
  }
  if ( !m_triangle )
    goto LABEL_17;
  while ( 1 )
  {
    v24 = (18 >> (2 * v21)) & 3;
    v25 = *(_QWORD *)(m_triangle + 8 * ((9i64 >> (2 * ((18 >> (2 * v21)) & 3u))) & 3) + 16);
    v26 = *(_QWORD *)(m_triangle + 8i64 * v24 + 16);
    if ( (v9 - *(_DWORD *)(v26 + 20)) * (__int64)(*(_DWORD *)(v25 + 16) - *(_DWORD *)(v26 + 16))
       - (v8 - *(_DWORD *)(v26 + 16)) * (__int64)(*(_DWORD *)(v25 + 20) - *(_DWORD *)(v26 + 20)) > 0 )
      break;
    v27 = *(_QWORD *)(m_triangle + 8i64 * v24 + 40);
    LODWORD(v21) = v27 & 3;
    m_triangle = v27 & 0xFFFFFFFFFFFFFFFCui64;
    edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
    edge.m_index = v21;
    if ( !m_triangle )
      goto LABEL_17;
  }
  v29 = m_triangle;
  v162.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(unsigned int)(2 * v21);
  v30 = (9 >> (2 * v21)) & 3;
  v31 = ((9i64 >> (2 * (unsigned __int8)v21)) & 3) + 2;
  m_index = v30;
  x1 = v30;
  v33 = *(_QWORD *)(m_triangle + 8 * v31);
  v158.m_index = v30;
  v160.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(m_triangle + 8 * v31);
  if ( *(_DWORD *)(v33 + 16) != v8 || *(_DWORD *)(v33 + 20) != v9 )
  {
    if ( v8 == v168.m_enum )
    {
      if ( v8 == HK_SUCCESS )
      {
        v62 = v9 == v169;
        if ( v9 < v169 )
        {
LABEL_17:
          if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
          {
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
          }
          v10->m_type.m_storage = 8;
LABEL_20:
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e;
          v28 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)*((_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e + 1);
          goto LABEL_21;
        }
LABEL_64:
        if ( v62 )
        {
          if ( v9 )
          {
            if ( v9 == 0x7FFFFF && v8 < v168.m_enum )
              goto LABEL_17;
          }
          else if ( v8 > v168.m_enum )
          {
            goto LABEL_17;
          }
        }
        v156 = m_triangle + 8 * (((9i64 >> (2 * (unsigned __int8)v30)) & 3) + 2);
        v63 = *(_QWORD *)v156;
        v1[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)(m_triangle + 8 * (v30 + 2i64));
        if ( (v9 - v1[0]->m_next->m_y) * (__int64)(*(_DWORD *)(v63 + 16) - v1[0]->m_next->m_x)
           - (v8 - v1[0]->m_next->m_x) * (__int64)(*(_DWORD *)(v63 + 20) - v1[0]->m_next->m_y) < 0 )
        {
          do
          {
            v64 = v1[0]->m_next->m_x;
            v65 = *(_DWORD *)(*(_QWORD *)v156 + 16i64);
            if ( v64 < v65 || v64 <= v65 && v1[0]->m_next->m_y <= *(_DWORD *)(*(_QWORD *)v156 + 20i64) )
            {
              v66 = m_index;
            }
            else
            {
              v66 = m_index;
              v67 = *(_QWORD *)(v29 + 8i64 * m_index + 40);
              if ( (v67 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
              {
                v68 = *(_QWORD *)(v29 + 8i64 * m_index + 40) & 3i64;
                v69 = v67 & 0xFFFFFFFFFFFFFFFCui64;
                goto LABEL_78;
              }
            }
            v69 = v29;
            LOBYTE(v68) = m_index;
LABEL_78:
            if ( ((unsigned __int8)(1 << v68) & (unsigned __int8)*(_WORD *)(v69 + 184) & 7) != 0 )
            {
              v78 = *(_QWORD *)(v29 + 8i64 * m_index + 16);
              if ( (v9 - *(_DWORD *)(v78 + 20)) * (__int64)(v168.m_enum - *(_DWORD *)(v78 + 16)) == (v169 - *(_DWORD *)(v78 + 20)) * (__int64)(v8 - *(_DWORD *)(v78 + 16)) )
                goto LABEL_94;
              v79 = *(_QWORD *)(v29 + 8 * ((9i64 >> (2 * (unsigned __int8)m_index)) & 3) + 16);
              if ( (v9 - *(_DWORD *)(v79 + 20)) * (__int64)(v168.m_enum - *(_DWORD *)(v79 + 16)) == (v169 - *(_DWORD *)(v79 + 20)) * (__int64)(v8 - *(_DWORD *)(v79 + 16)) )
              {
                LODWORD(resulta.m_edge.m_triangle) = (9 >> (2 * m_index)) & 3;
                goto LABEL_92;
              }
              v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v158.m_index;
              v10->m_type.m_storage = 3;
              v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
LABEL_21:
              *(_QWORD *)&v10->m_edge.m_index = v28;
              return v10;
            }
            v70 = *(_QWORD *)(v29 + 8 * v66 + 40);
            v71 = v70;
            v29 = v70 & 0xFFFFFFFFFFFFFFFCui64;
            LODWORD(v156) = v71 & 3;
            v72 = 2 * (v71 & 3);
            v73 = *(_QWORD *)(v29 + 8 * ((18i64 >> v72) & 3) + 16);
            v74 = (v9 - v0->m_y) * (__int64)(*(_DWORD *)(v73 + 16) - v0->m_x)
                - (v8 - v0->m_x) * (__int64)(*(_DWORD *)(v73 + 20) - v0->m_y);
            if ( v74 >= 0 )
            {
              if ( v74 <= 0 )
              {
                if ( *(_DWORD *)(v73 + 16) != v8 || *(_DWORD *)(v73 + 20) != v9 )
                {
                  LODWORD(resulta.m_edge.m_triangle) = (18 >> (2 * v156)) & 3;
LABEL_92:
                  v28 = resulta.m_edge.m_triangle;
                  v10->m_type.m_storage = 4;
                  v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
                  goto LABEL_21;
                }
                v164.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
                v164.m_index = (18 >> v72) & 3;
                v75 = v164;
              }
              else
              {
                v165.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
                v165.m_index = (18 >> v72) & 3;
                v75 = v165;
              }
            }
            else
            {
              v163.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
              v163.m_index = (9 >> v72) & 3;
              v75 = v163;
            }
            v158 = v75;
            m_index = v75.m_index;
            v29 = (unsigned __int64)v75.m_triangle;
            v156 = (__int64)&v75.m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(v75.m_index))) & 3];
            v76 = *(_QWORD *)v156;
            v1[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)&v75.m_triangle->m_vertices[v75.m_index];
          }
          while ( (v9 - v1[0]->m_next->m_y) * (__int64)(*(_DWORD *)(v76 + 16) - v1[0]->m_next->m_x)
                - (v8 - v1[0]->m_next->m_x) * (__int64)(*(_DWORD *)(v76 + 20) - v1[0]->m_next->m_y) < 0 );
        }
        v77 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v29 + 8i64 * m_index + 16);
        v156 = (__int64)v77;
        if ( v0 == v77 )
        {
          if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
          {
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
          }
          v10->m_type.m_storage = 9;
          goto LABEL_20;
        }
        v80 = *(_QWORD *)(v29 + 8 * ((9i64 >> (2 * (unsigned __int8)m_index)) & 3) + 16);
        if ( (v9 - v77->m_y) * (__int64)(*(_DWORD *)(v80 + 16) - v77->m_x) != (v8 - v77->m_x)
                                                                            * (__int64)(*(_DWORD *)(v80 + 20) - v77->m_y) )
        {
          if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
          {
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
          }
          v10->m_type.m_storage = 7;
          goto LABEL_20;
        }
        v81 = *(_DWORD *)(v156 + 16);
        if ( v81 != v8 || (v82 = *(_DWORD *)(v156 + 20), v82 != v9) )
        {
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v158.m_index;
          v10->m_type.m_storage = 7;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
          goto LABEL_21;
        }
        v83 = v0->m_x;
        if ( v83 == v81 && (!v83 || v83 == 0x7FFFFF) || (m_y = v0->m_y, m_y == v82) && (!m_y || m_y == 0x7FFFFF) )
        {
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v158.m_index;
          v10->m_type.m_storage = 8;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
          goto LABEL_21;
        }
        v85 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 16);
        m_next = v160.m_triangle->m_next;
        v87 = *(_DWORD *)(v85 + 16);
        if ( (v82 - *(_DWORD *)(v85 + 20)) * (__int64)(LODWORD(v160.m_triangle->m_next->m_vertices[0]) - v87) == (v81 - v87) * (__int64)(HIDWORD(v160.m_triangle->m_next->m_vertices[0]) - *(_DWORD *)(v85 + 20)) )
        {
          LODWORD(resulta.m_edge.m_triangle) = x1;
          v28 = resulta.m_edge.m_triangle;
          v10->m_type.m_storage = 4;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
          goto LABEL_21;
        }
        if ( (v82 - *(_DWORD *)(v85 + 20)) * (__int64)(LODWORD(m_next->m_vertices[0]) - v87)
           - (v81 - v87) * (__int64)(HIDWORD(m_next->m_vertices[0]) - *(_DWORD *)(v85 + 20)) < 0 )
        {
LABEL_94:
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v158.m_index;
          v10->m_type.m_storage = 4;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
          goto LABEL_21;
        }
        v88 = v156;
        v168.m_enum = HK_SUCCESS;
        if ( m_next != (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v156 )
        {
          v89 = (char)v162.m_triangle;
          do
          {
            v90 = *(_DWORD *)(v88 + 16);
            v91 = *(_DWORD *)(v88 + 20);
            v164.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
            v165 = edge;
            v164.m_index = (9 >> v89) & 3;
            edge = v164;
            v92 = *(_QWORD *)(m_triangle + 8 * ((9i64 >> (2 * LOBYTE(v164.m_index))) & 3) + 16);
            v93 = v0->m_y;
            v94 = v0->m_x;
            if ( (v90 - v94) * (__int64)(*(_DWORD *)(v92 + 20) - v93)
               - (v91 - v93) * (__int64)(*(_DWORD *)(v92 + 16) - v94) <= 0 )
            {
              LODWORD(v21) = edge.m_index;
            }
            else
            {
              v95 = v91 - v93;
              LODWORD(v21) = edge.m_index;
              v96 = v90 - v94;
              do
              {
                v97 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40);
                v98 = v97;
                m_triangle = v97 & 0xFFFFFFFFFFFFFFFCui64;
                LODWORD(v21) = (9 >> (2 * (v98 & 3))) & 3;
                v99 = *(_QWORD *)(m_triangle + 8 * ((9i64 >> (2 * ((9 >> (2 * (v98 & 3))) & 3u))) & 3) + 16);
              }
              while ( v96 * (*(_DWORD *)(v99 + 20) - v93) - v95 * (*(_DWORD *)(v99 + 16) - v94) > 0 );
              edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
              edge.m_index = v21;
            }
            v100 = v165.m_triangle->m_vertices[v165.m_index];
            v101 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(m_triangle + 8 * ((9i64 >> (2 * (unsigned __int8)v21)) & 3) + 16);
            v102 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 16);
            if ( (v101->m_y - v100->m_y) * (__int64)(*(_DWORD *)(v102 + 16) - v100->m_x)
               - (v101->m_x - v100->m_x) * (__int64)(*(_DWORD *)(v102 + 20) - v100->m_y) <= 0 )
            {
              ++v168.m_enum;
            }
            else
            {
              v163.m_triangle = v165.m_triangle;
              v103 = 0;
              v163.m_index = (9 >> (2 * LOBYTE(v165.m_index))) & 3;
              edge = v163;
              v104 = (unsigned __int64)v165.m_triangle;
              LODWORD(v105) = v163.m_index;
              if ( v165.m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(v163.m_index))) & 3] != v101 )
              {
                do
                {
                  v106 = *(_QWORD *)(v104 + 8i64 * (int)v105 + 40);
                  if ( (v106 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
                    goto LABEL_135;
                  v107 = *(_QWORD *)(v104 + 8i64 * (int)v105 + 16);
                  v108 = 2 * v105;
                  v109 = *(_DWORD *)(v107 + 16);
                  v110 = *(_QWORD *)(v104 + 8 * ((9i64 >> (2 * (unsigned __int8)v105)) & 3) + 16);
                  v111 = *(_DWORD *)(v110 + 16);
                  if ( v109 < v111 || v109 <= v111 && *(_DWORD *)(v107 + 20) <= *(_DWORD *)(v110 + 20) )
                  {
                    v112 = v104;
                  }
                  else
                  {
                    v105 = *(_QWORD *)(v104 + 8i64 * (int)v105 + 40) & 3i64;
                    v112 = v106 & 0xFFFFFFFFFFFFFFFCui64;
                  }
                  if ( ((unsigned __int8)(1 << v105) & (unsigned __int8)*(_WORD *)(v112 + 184) & 7) != 0
                    || (v113 = (18 >> v108) & 3,
                        v114 = *(_QWORD *)((v106 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((18 >> (2 * (v106 & 3))) & 3) + 16),
                        v115 = *(_QWORD *)(v104 + 8i64 * v113 + 16),
                        v116 = *(_DWORD *)(v115 + 20),
                        (*(_DWORD *)(v107 + 16) - *(_DWORD *)(v115 + 16)) * (__int64)(*(_DWORD *)(v114 + 20) - v116)
                      - (*(_DWORD *)(v107 + 20) - v116) * (__int64)(*(_DWORD *)(v114 + 16) - *(_DWORD *)(v115 + 16)) <= 0)
                    || (v117 = *(_QWORD *)((v106 & 0xFFFFFFFFFFFFFFFCui64) + 8 * (v106 & 3) + 16),
                        (*(_DWORD *)(v117 + 16) - *(_DWORD *)(v114 + 16)) * (__int64)(v116 - *(_DWORD *)(v114 + 20))
                      - (*(_DWORD *)(v117 + 20) - *(_DWORD *)(v114 + 20))
                      * (__int64)(*(_DWORD *)(v115 + 16) - *(_DWORD *)(v114 + 16)) <= 0) )
                  {
LABEL_135:
                    v104 = v106 & 0xFFFFFFFFFFFFFFFCui64;
                    ++v103;
                    edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v106 & 0xFFFFFFFFFFFFFFFCui64);
                    LODWORD(v105) = (9 >> (2 * (v106 & 3))) & 3;
                    edge.m_index = v105;
                  }
                  else
                  {
                    hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::flipEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge>(
                      &this->m_edgeDataPolicy,
                      &v158,
                      &edge);
                    if ( v103 )
                    {
                      v118 = v158.m_triangle->m_links[v158.m_index];
                      LODWORD(v105) = *(_QWORD *)((v118 & 0xFFFFFFFFFFFFFFFCui64)
                                                + 8i64 * ((9 >> (2 * (v118 & 3))) & 3)
                                                + 40) & 3;
                      v162.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(*(_QWORD *)((v118 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((9 >> (2 * (v118 & 3))) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64);
                      --v103;
                      v162.m_index = v105;
                      edge = v162;
                      v104 = (unsigned __int64)v162.m_triangle;
                    }
                    else
                    {
                      v119 = v158.m_triangle->m_links[v158.m_index] & 3;
                      v160.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v158.m_triangle->m_links[v158.m_index] & 0xFFFFFFFFFFFFFFFCui64);
                      v160.m_index = (18 >> (2 * v119)) & 3;
                      edge = v160;
                      LODWORD(v105) = v160.m_index;
                      v104 = (unsigned __int64)v160.m_triangle;
                    }
                  }
                }
                while ( *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v104 + 8 * ((9i64 >> (2 * (unsigned __int8)v105)) & 3) + 16) != v101 );
              }
              v120 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)(*(_QWORD *)(v104 + 8i64 * ((9 >> (2 * v105)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64);
              v121 = *(_QWORD *)(v104 + 8i64 * ((9 >> (2 * v105)) & 3) + 40) & 3i64;
              v1[0] = v120;
              LODWORD(v1[1]) = v121;
              edge = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)v1;
              if ( v168.m_enum )
              {
                v122 = 2 * v121;
                v123 = *((_QWORD *)&v120->m_x + ((18i64 >> (2 * (unsigned __int8)v121)) & 3));
                v124 = v0->m_y;
                v125 = v0->m_x;
                if ( (*(_DWORD *)(v156 + 16) - v125) * (__int64)(*(_DWORD *)(v123 + 20) - v124)
                   - (*(_DWORD *)(v156 + 20) - v124) * (__int64)(*(_DWORD *)(v123 + 16) - v125) <= 0 )
                {
                  v129 = edge.m_index;
                  v126 = (unsigned __int64)edge.m_triangle;
                }
                else
                {
                  v126 = (unsigned __int64)edge.m_triangle;
                  do
                  {
                    v127 = *(_QWORD *)(v126 + 8i64 * ((18 >> v122) & 3) + 40);
                    v128 = v127;
                    v126 = v127 & 0xFFFFFFFFFFFFFFFCui64;
                    v129 = v128 & 3;
                    v122 = 2 * v129;
                    v130 = *(_QWORD *)(v126 + 8 * ((18i64 >> (2 * v129)) & 3) + 16);
                  }
                  while ( (*(_DWORD *)(v156 + 16) - v125) * (__int64)(*(_DWORD *)(v130 + 20) - v124)
                        - (*(_DWORD *)(v156 + 20) - v124) * (__int64)(*(_DWORD *)(v130 + 16) - v125) > 0 );
                }
                *(_QWORD *)&resulta.m_type.m_storage = v126;
                LODWORD(resulta.m_edge.m_triangle) = (18 >> (2 * v129)) & 3;
                --v168.m_enum;
                edge = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta.m_type.m_storage;
              }
              LODWORD(v21) = edge.m_index;
              m_triangle = (unsigned __int64)edge.m_triangle;
            }
            v88 = v156;
            v89 = 2 * v21;
          }
          while ( *(_QWORD *)(m_triangle + 8 * ((9i64 >> (2 * (unsigned __int8)v21)) & 3) + 16) != v156 );
          v10 = result;
        }
        v131 = (int)v21;
        v132 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 16);
        v160.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(unsigned int)(2 * v21);
        v133 = m_triangle + 8 * ((9i64 >> (2 * (unsigned __int8)v21)) & 3);
        v134 = *(_DWORD *)(v132 + 16);
        v135 = *(_QWORD *)(v133 + 16);
        v136 = *(_DWORD *)(v135 + 16);
        if ( v134 >= v136
          && (v134 > v136 || *(_DWORD *)(v132 + 20) > *(_DWORD *)(v135 + 20))
          && (v137 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40), (v137 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
        {
          v21 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40) & 3i64;
          v138 = v137 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v138 = m_triangle;
        }
        *(_WORD *)(v138 + 184) ^= ((unsigned __int8)*(_WORD *)(v138 + 184) ^ (unsigned __int8)(*(_WORD *)(v138 + 184) | (1 << v21))) & 7;
        if ( data )
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setEdgeData(
            this,
            &edge,
            data);
        if ( !conform )
        {
LABEL_172:
          *((_QWORD *)&this->m_roots[(__int64)(*(_DWORD *)(*(_QWORD *)(m_triangle + 32) + 16i64)
                                             + *(_DWORD *)(*(_QWORD *)(m_triangle + 24) + 16i64)
                                             + 2 * *(_DWORD *)(*(_QWORD *)(m_triangle + 16) + 16i64)) >> 21]
          + (((__int64)(*(_DWORD *)(*(_QWORD *)(m_triangle + 32) + 20i64)
                      + *(_DWORD *)(*(_QWORD *)(m_triangle + 24) + 20i64)
                      + 2 * *(_DWORD *)(*(_QWORD *)(m_triangle + 16) + 20i64)) >> 17) & 0xFFFFFFFFFFFFFFF0ui64)) = m_triangle;
          *(_WORD *)(m_triangle + 184) |= 8u;
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&edge.m_index;
          v10->m_type.m_storage = 0;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
          goto LABEL_21;
        }
        v139 = this;
        v62 = (*(_QWORD *)(m_triangle + 8 * (v131 + 5)) & 0xFFFFFFFFFFFFFFFCui64) == 0;
        m_size = this->m_stack.m_size;
        v0 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(m_triangle + 8 * v131 + 16);
        v141 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v133 + 16);
        v142 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(m_triangle + 8 * (v131 + 5));
        v143 = v62;
        v1[0] = v141;
        v144 = 4;
        if ( v62 )
          v144 = 2;
        m_capacityAndFlags = this->m_stack.m_capacityAndFlags;
        v162.m_triangle = v142;
        v146 = m_capacityAndFlags & 0x3FFFFFFF;
        v147 = v144 + m_size;
        if ( v146 >= v147 )
        {
          v168.m_enum = HK_SUCCESS;
        }
        else
        {
          v148 = 2 * v146;
          if ( v147 < v148 )
            v147 = v148;
          hkArrayUtil::_reserve(&v168, &hkContainerHeapAllocator::s_alloc, &this->m_stack, v147, 16);
          if ( v168.m_enum == HK_FAILURE )
          {
            this->m_status.m_storage = 1;
            if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
            {
              *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
              DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
              `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
            }
            v149 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e;
LABEL_171:
            edge = v149;
            m_triangle = (unsigned __int64)v149.m_triangle;
            goto LABEL_172;
          }
          v142 = v162.m_triangle;
          v139 = this;
        }
        v150 = this->m_stack.m_size;
        v151 = (char)v160.m_triangle;
        this->m_stack.m_size += v144;
        v152 = &this->m_stack.m_data[v150];
        v152->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
        v152->m_index = (9 >> v151) & 3;
        v152[1].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
        v152[1].m_index = (18 >> v151) & 3;
        if ( !v143 )
        {
          v153 = 9 >> (2 * ((__int64)v142->m_next & 3));
          v152[2].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)((unsigned __int64)v142->m_next & 0xFFFFFFFFFFFFFFFCui64);
          v152[2].m_index = v153 & 3;
          v154 = 18 >> (2 * ((__int64)v142->m_next & 3));
          v152[3].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)((unsigned __int64)v142->m_next & 0xFFFFFFFFFFFFFFFCui64);
          v152[3].m_index = v154 & 3;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::flushConform(v139);
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateExistingEdge(
          this,
          (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta,
          &edge,
          v0,
          v1[0]);
        v149 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta.m_type.m_storage;
        goto LABEL_171;
      }
      if ( v8 == 0x7FFFFF && v9 > v169 )
        goto LABEL_17;
    }
    v62 = v9 == v169;
    goto LABEL_64;
  }
  v34 = *(_DWORD *)(v33 + 16);
  v35 = (int)v21;
  v36 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 16);
  v37 = *(_DWORD *)(v36 + 16);
  if ( v37 >= v34
    && (v37 > v34 || *(_DWORD *)(v36 + 20) > *(_DWORD *)(v33 + 20))
    && (v38 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40), (v38 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
  {
    v39 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40) & 3i64;
    v40 = v38 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v40 = m_triangle;
    LOBYTE(v39) = v21;
  }
  if ( ((unsigned __int8)(1 << v39) & (unsigned __int8)*(_WORD *)(v40 + 184) & 7) != 0 )
  {
    v41 = edge;
    v10->m_type.m_storage = 1;
    v10->m_edge = v41;
    return v10;
  }
  v42 = *(_DWORD *)(v36 + 16);
  v43 = *(_DWORD *)(v33 + 16);
  if ( v42 >= v43
    && (v42 > v43 || *(_DWORD *)(v36 + 20) > *(_DWORD *)(v33 + 20))
    && (v44 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40), (v44 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
  {
    v21 = *(_QWORD *)(m_triangle + 8i64 * (int)v21 + 40) & 3i64;
    v45 = v44 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v45 = m_triangle;
  }
  v46 = data;
  *(_WORD *)(v45 + 184) ^= ((unsigned __int8)*(_WORD *)(v45 + 184) ^ (unsigned __int8)(*(_WORD *)(v45 + 184) | (1 << v21))) & 7;
  if ( v46 )
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setEdgeData(
      this,
      &edge,
      v46);
  if ( !conform )
  {
    v61 = edge;
    v10->m_type.m_storage = 0;
    v10->m_edge = v61;
    return v10;
  }
  v47 = this;
  v48 = this->m_stack.m_size;
  v0 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(m_triangle + 8 * v35 + 16);
  v1[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)v160.m_triangle->m_next;
  v49 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(m_triangle + 8 * (v35 + 5));
  v50 = ((unsigned __int64)v49->m_next & 0xFFFFFFFFFFFFFFFCui64) == 0;
  v51 = 4;
  v160.m_triangle = v49;
  LODWORD(v156) = v50;
  if ( v50 )
    v51 = 2;
  v52 = this->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
  v53 = v51 + v48;
  if ( v52 >= v53 )
  {
    v168.m_enum = HK_SUCCESS;
  }
  else
  {
    v54 = 2 * v52;
    if ( v53 < v54 )
      v53 = v54;
    hkArrayUtil::_reserve(&v168, &hkContainerHeapAllocator::s_alloc, &this->m_stack, v53, 16);
    if ( v168.m_enum == HK_FAILURE )
    {
      this->m_status.m_storage = 1;
      if ( (`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard & 1) == 0 )
      {
        *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e) = 0;
        `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::`local static guard |= 1u;
      }
      v55 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null::`2::e;
      v10->m_type.m_storage = 0;
      v10->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)v55;
      return v10;
    }
    v49 = v160.m_triangle;
    v47 = this;
  }
  v56 = (char)v162.m_triangle;
  v57 = this->m_stack.m_size;
  this->m_stack.m_size += v51;
  v58 = &this->m_stack.m_data[v57];
  v58->m_index = x1;
  v58->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
  v58[1].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)m_triangle;
  v58[1].m_index = (18 >> v56) & 3;
  if ( !(_DWORD)v156 )
  {
    v59 = 9 >> (2 * ((__int64)v49->m_next & 3));
    v58[2].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)((unsigned __int64)v49->m_next & 0xFFFFFFFFFFFFFFFCui64);
    v58[2].m_index = v59 & 3;
    v60 = 18 >> (2 * ((__int64)v49->m_next & 3));
    v58[3].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)((unsigned __int64)v49->m_next & 0xFFFFFFFFFFFFFFFCui64);
    v58[3].m_index = v60 & 3;
  }
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::flushConform(v47);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateExistingEdge(
    this,
    (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta,
    &edge,
    v0,
    v1[0]);
  v10->m_type.m_storage = 0;
  v10->m_edge = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta.m_type.m_storage;
  return v10;
}

// File Line: 1526
// RVA: 0x12EC030
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *result,
        int x0,
        int y0,
        hkaiRuntimeTriangulatorEdgeData *x1)
{
  int v5; // esi
  int v6; // eax
  __int64 v7; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_triangle; // rdi
  __int64 v9; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v10; // rcx
  int v11; // edi
  int v12; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v13; // rcx
  __int64 v14; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v15; // rdx
  int m_x; // r10d
  int m_y; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v18; // rcx
  int v19; // edx
  int v20; // r9d
  int v21; // ecx
  int v22; // esi
  int v23; // ecx
  int v24; // edx
  __m128i v25; // xmm1
  float v26; // xmm1_4
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  int v29; // edi
  int v30; // ebx
  unsigned int canSplitEdge; // eax
  unsigned int v32; // r8d
  int v33; // eax
  int v34; // ecx
  int v35; // esi
  int v36; // r9d
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  int v41; // r9d
  int v42; // r11d
  __m128 v43; // xmm8
  int v44; // r10d
  __m128 v45; // xmm3
  signed int v46; // ecx
  __m128 v47; // xmm4
  signed int v48; // eax
  int v49; // edx
  __m128i v50; // xmm2
  int v51; // eax
  __m128 v52; // xmm3
  __m128 v53; // xmm8
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  float v58; // xmm9_4
  __m128 v59; // xmm1
  __m128 v60; // xmm1
  __m128 v61; // xmm0
  __m128 v62; // xmm11
  __m128 v63; // xmm7
  __int64 v64; // rax
  __m128 *p_location; // rsi
  __m128 v66; // xmm7
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  float v70; // xmm6_4
  unsigned int v71; // eax
  int v72; // r9d
  int v73; // r10d
  int v74; // ebx
  bool v75; // zf
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *inserted; // rcx
  __int64 v77; // rax
  __int64 v78; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v79; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v80; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v81; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v82; // rdx
  __int64 v83; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v84; // rax
  bool v85; // zf
  __int64 v86; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v87; // rdx
  bool v88; // cc
  __int64 v89; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v90; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v91; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v92; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v93; // rdx
  __int64 v94; // rax
  int v95; // [rsp+50h] [rbp-90h]
  int v96; // [rsp+54h] [rbp-8Ch]
  int v97; // [rsp+58h] [rbp-88h]
  int v98; // [rsp+5Ch] [rbp-84h]
  int v99; // [rsp+60h] [rbp-80h]
  int v100; // [rsp+68h] [rbp-78h]
  int ix; // [rsp+6Ch] [rbp-74h]
  int v102; // [rsp+70h] [rbp-70h]
  int v103; // [rsp+74h] [rbp-6Ch]
  int v104; // [rsp+78h] [rbp-68h]
  int v105; // [rsp+7Ch] [rbp-64h]
  __m256 location; // [rsp+80h] [rbp-60h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edge; // [rsp+A0h] [rbp-40h] BYREF
  int v108; // [rsp+B0h] [rbp-30h]
  __int64 v109; // [rsp+B8h] [rbp-28h]
  __int64 v110; // [rsp+C0h] [rbp-20h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion resulta; // [rsp+C8h] [rbp-18h] BYREF
  int v112; // [rsp+E0h] [rbp+0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v113; // [rsp+E8h] [rbp+8h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v114; // [rsp+100h] [rbp+20h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v115; // [rsp+118h] [rbp+38h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v116; // [rsp+130h] [rbp+50h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v117; // [rsp+148h] [rbp+68h] BYREF
  char buf[664]; // [rsp+160h] [rbp+80h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v119; // [rsp+400h] [rbp+320h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v120; // [rsp+408h] [rbp+328h]
  int x0a; // [rsp+410h] [rbp+330h]
  void *retaddr; // [rsp+418h] [rbp+338h]
  int v123; // [rsp+420h] [rbp+340h]
  int v124; // [rsp+428h] [rbp+348h]
  char v125; // [rsp+430h] [rbp+350h]
  NavMeshCutterCutterEdgeCrossing *v126; // [rsp+438h] [rbp+358h]

  LODWORD(v126) = y0;
  v125 = x0;
  v124 = (int)result;
  v123 = (int)this;
  v5 = y0;
  v100 = y0;
  v6 = x0;
  ix = x0;
  while ( 1 )
  {
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertEdge(
      this,
      &resulta,
      v6,
      v5,
      v123,
      v124,
      v125,
      x1);
    v7 = *(_QWORD *)&resulta.m_type.m_storage;
    m_triangle = resulta.m_edge.m_triangle;
    v9 = *(_QWORD *)&resulta.m_edge.m_index;
    edge = resulta.m_edge;
    if ( resulta.m_type.m_storage == 1 )
      break;
    if ( resulta.m_type.m_storage == 3 )
    {
      v15 = resulta.m_edge.m_triangle->m_vertices[resulta.m_edge.m_index];
      m_x = v15->m_x;
      m_y = v15->m_y;
      v104 = m_x;
      v18 = resulta.m_edge.m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(resulta.m_edge.m_index))) & 3];
      v105 = m_y;
      v19 = v18->m_x;
      v20 = v18->m_y;
      v21 = v100;
      v103 = v19;
      LODWORD(v110) = m_y - v20;
      v22 = (m_y - v20) * (ix - v123) + (v100 - v124) * (v19 - m_x);
      if ( v22 )
      {
        v23 = v19 * (v100 - m_y);
        v24 = ix;
        v25 = _mm_cvtsi32_si128(ix * (m_y - v20) + m_x * (v20 - v100) + v23);
        v21 = v100;
        v26 = _mm_cvtepi32_ps(v25).m128_f32[0] / (float)v22;
      }
      else
      {
        v24 = ix;
        v26 = 0.0;
      }
      v27 = (__m128)COERCE_UNSIGNED_INT((float)(v123 - v24));
      v28 = (__m128)COERCE_UNSIGNED_INT((float)(v124 - v21));
      v27.m128_f32[0] = (float)(v27.m128_f32[0] * v26) + (float)v24;
      v28.m128_f32[0] = (float)(v28.m128_f32[0] * v26) + (float)v21;
      v29 = (int)v27.m128_f32[0];
      v99 = v28.m128_i32[0];
      v95 = (int)v27.m128_f32[0];
      v30 = (int)v28.m128_f32[0];
      v96 = (int)v28.m128_f32[0];
      canSplitEdge = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                       (int)v27.m128_f32[0],
                       (int)v28.m128_f32[0],
                       &edge);
      v32 = canSplitEdge;
      if ( !v22 )
      {
        if ( canSplitEdge )
          goto LABEL_72;
        goto LABEL_66;
      }
      if ( canSplitEdge )
        goto LABEL_72;
      v33 = 1;
      v34 = -1;
      v97 = 1;
      v98 = -1;
      while ( v34 > -63 )
      {
        v99 = v34;
        v108 = 1;
        if ( v33 >= 0 )
        {
          v30 += v97;
          v35 = v96 - v97;
          v36 = v95 - v96;
          v112 = -v96;
          v37 = v96 - v95;
          ix = v95;
          v100 = v95 - v96;
          LODWORD(v109) = -v95;
          v102 = v96 - v95;
          while ( 1 )
          {
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v36 + v30,
                    v29 + v37,
                    &edge);
            if ( v32 )
              break;
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v35 + v100,
                    v29 + v102,
                    &edge);
            if ( v32 )
            {
              v40 = v35 + v100;
              goto LABEL_40;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v35 + v100,
                    v102 + ix,
                    &edge);
            if ( v32 )
            {
              v95 = v35 + v100;
              v39 = v102 + ix;
              goto LABEL_41;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v30 + v100,
                    v102 + ix,
                    &edge);
            if ( v32 )
            {
              v95 = v30 + v100;
              v39 = v102 + ix;
              goto LABEL_41;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v29,
                    v30,
                    &edge);
            if ( v32 )
            {
              v95 = v29;
              v96 = v30;
              goto LABEL_43;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    ix,
                    v30,
                    &edge);
            if ( v32 )
            {
              v29 = ix;
              v96 = v30;
              v95 = ix;
              goto LABEL_43;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    ix,
                    v35,
                    &edge);
            if ( v32 )
            {
              v29 = ix;
LABEL_33:
              v30 = v35;
              v95 = v29;
              v96 = v35;
              goto LABEL_43;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v29,
                    v35,
                    &edge);
            if ( v32 )
              goto LABEL_33;
            --ix;
            v38 = v108 + v102;
            v108 += 2;
            ++v29;
            v102 = v38;
            if ( v99 + 2 * v38 > 0 )
            {
              --v30;
              ++v35;
              v102 = v99 + v38;
              v99 += 2;
            }
            v37 = v102;
            v36 = v95 - v96;
            if ( v30 + v112 < v29 + (int)v109 )
            {
              v30 = v96;
              goto LABEL_42;
            }
          }
          v40 = v30 + v100;
LABEL_40:
          v95 = v40;
          v39 = v29 + v102;
LABEL_41:
          v96 = v39;
          v30 = v39;
LABEL_42:
          v29 = v95;
LABEL_43:
          v33 = v97;
          v34 = v98;
        }
        ++v33;
        v34 -= 2;
        v97 = v33;
        v98 = v34;
        if ( v32 )
          goto LABEL_72;
      }
      if ( v32 )
      {
LABEL_72:
        *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)&location.m256_f32[2] = resulta.m_edge;
        LODWORD(location.m256_f32[0]) = 1;
        inserted = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertVertex(
                     v119,
                     &v115,
                     v29,
                     v30,
                     0,
                     (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Location *)&location,
                     1);
        v77 = *(_QWORD *)&inserted->m_type.m_storage;
        v78 = *(_QWORD *)&inserted->m_edge.m_index;
        v79 = inserted->m_edge.m_triangle;
        v110 = v78;
        if ( (_DWORD)v77 == 10 )
        {
          v93 = v120;
          *(_QWORD *)&v120->m_type.m_storage = v77;
          v94 = *(_QWORD *)&inserted->m_edge.m_index;
          v93->m_edge.m_triangle = v79;
          *(_QWORD *)&v93->m_edge.m_index = v94;
          return v93;
        }
        if ( (_DWORD)v77 )
        {
          hkErrStream::hkErrStream((hkErrStream *)&location, buf, 512);
          hkOstream::operator<<((hkOstream *)&location, "Cannot insert crossing edge");
          if ( (unsigned int)hkError::messageError(
                               0x9CABCB60,
                               buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hk"
                               "gpTriangulator.inl",
                               1658) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&location);
          LODWORD(v78) = v110;
        }
        v80 = v79->m_vertices[(int)v78];
        v81 = v119;
        *((_QWORD *)v80 + 3) = *((_DWORD *)v80 + 6) & 3 | (unsigned __int64)(4i64
                                                                           * (v126->m_triangulator->m_mesh.m_vertices.m_numUsed
                                                                            - 1));
        LODWORD(v80) = x0a;
        v126->m_addedNewVertex = 1;
        v82 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
                v81,
                &v117,
                (int)v80,
                (int)retaddr,
                v29,
                v30,
                v125,
                v126,
                x1);
        v83 = *(_QWORD *)&v82->m_type.m_storage;
        resulta.m_edge = v82->m_edge;
        if ( (_DWORD)v83 == 10 )
        {
          v92 = v120;
          *(_QWORD *)&v120->m_type.m_storage = v83;
          v92->m_edge.m_triangle = v82->m_edge.m_triangle;
          *(_QWORD *)&v92->m_edge.m_index = *(_QWORD *)&v82->m_edge.m_index;
          return v92;
        }
        if ( (unsigned int)v83 > 1 )
        {
          hkErrStream::hkErrStream((hkErrStream *)&location, buf, 512);
          hkOstream::operator<<((hkOstream *)&location, "Cannot insert crossing edge");
          if ( (unsigned int)hkError::messageError(
                               0x9CABCB60,
                               buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hk"
                               "gpTriangulator.inl",
                               1665) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&location);
        }
        this = v119;
        v6 = v29;
        v5 = v30;
        x0a = v29;
        LODWORD(retaddr) = v30;
      }
      else
      {
        v41 = v103;
        v42 = v99;
        v43 = _mm_unpacklo_ps(v27, (__m128)0i64);
        v44 = v105;
        v45 = _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v103), (__m128)0i64);
        v46 = abs32(abs32(v104 - v103));
        v47 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v104), (__m128)0i64),
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v105), (__m128)0i64));
        v48 = abs32(abs32(v110));
        v49 = 1;
        v50 = _mm_cvtsi32_si128(v99);
        v99 = 1;
        *(__m128 *)location.m256_f32 = v47;
        if ( v46 > v48 )
          v48 = v46;
        v51 = 8 * v48 + 4;
        v52 = _mm_unpacklo_ps(v45, _mm_unpacklo_ps(_mm_cvtepi32_ps(v50), (__m128)0i64));
        if ( v51 > 128 )
          v51 = 128;
        LODWORD(v110) = v51;
        v53 = _mm_unpacklo_ps(v43, _mm_unpacklo_ps(v28, (__m128)0i64));
        *(__m128 *)&location.m256_f32[4] = v52;
        v54 = _mm_sub_ps(v53, v52);
        v55 = _mm_sub_ps(v53, v47);
        v56 = _mm_mul_ps(v54, v54);
        v57 = _mm_mul_ps(v55, v55);
        v58 = fmin(
                (float)(_mm_shuffle_ps(v57, v57, 85).m128_f32[0] + _mm_shuffle_ps(v57, v57, 0).m128_f32[0])
              + _mm_shuffle_ps(v57, v57, 170).m128_f32[0],
                (float)(_mm_shuffle_ps(v56, v56, 85).m128_f32[0] + _mm_shuffle_ps(v56, v56, 0).m128_f32[0])
              + _mm_shuffle_ps(v56, v56, 170).m128_f32[0]);
        if ( v51 > 1 )
        {
          v59 = 0i64;
          v59.m128_f32[0] = (float)v51;
          v60 = _mm_shuffle_ps(v59, v59, 0);
          v61 = _mm_rcp_ps(v60);
          v62 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v60, v61)), v61);
          do
          {
            v63 = 0i64;
            v63.m128_f32[0] = (float)v49;
            v64 = 2i64;
            p_location = (__m128 *)&location;
            v109 = 2i64;
            v66 = _mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v62);
            do
            {
              v67 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*p_location, v53), v66), v53);
              v68 = _mm_sub_ps(v67, v53);
              v69 = _mm_mul_ps(v68, v68);
              v70 = (float)(_mm_shuffle_ps(v69, v69, 85).m128_f32[0] + _mm_shuffle_ps(v69, v69, 0).m128_f32[0])
                  + _mm_shuffle_ps(v69, v69, 170).m128_f32[0];
              if ( !v32 && v70 < v58 )
              {
                v29 = _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_shuffle_ps(v67, v67, 0), (__m128)xmmword_141A711B0)));
                v30 = _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_shuffle_ps(v67, v67, 85), (__m128)xmmword_141A711B0)));
                if ( v29 == v104 && v30 == v44
                  || v29 == v41 && v30 == v42
                  || (v71 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                              v29,
                              v30,
                              &edge),
                      v41 = v103,
                      v44 = v105,
                      v42 = v99,
                      v32 = v71,
                      v75 = v71 == 0,
                      v64 = v109,
                      v75) )
                {
                  v29 = v95;
                  v30 = v96;
                }
                else
                {
                  v58 = v70;
                  v95 = v29;
                  v96 = v30;
                }
              }
              ++p_location;
              v109 = --v64;
            }
            while ( v64 );
            if ( v32 )
              goto LABEL_72;
            v49 = v99 + 1;
            v99 = v49;
          }
          while ( v49 < (int)v110 );
        }
LABEL_66:
        v72 = (int)retaddr;
        v73 = x0a;
        v5 = v99;
        v74 = v103;
        if ( (v124 - (int)retaddr) * (v104 - x0a) - (v123 - x0a) * (v105 - (int)retaddr) < ((int)retaddr - v124)
                                                                                         * (v103 - v123)
                                                                                         - (x0a - v123) * (v99 - v124) )
        {
          v74 = v104;
          if ( v104 == x0a )
          {
            if ( !v104 )
            {
              v75 = v105 == (_DWORD)retaddr;
              if ( v105 < (int)retaddr )
                goto LABEL_92;
LABEL_86:
              if ( !v75 )
                goto LABEL_95;
              if ( !v105 )
              {
                if ( v104 > x0a )
                  goto LABEL_92;
LABEL_95:
                v84 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
                        v119,
                        &v114,
                        v73,
                        v72,
                        v104,
                        v105,
                        v125,
                        v126,
                        x1);
                v5 = v105;
                LODWORD(retaddr) = v105;
                goto LABEL_113;
              }
              if ( v105 != 0x7FFF || v104 >= x0a )
                goto LABEL_95;
LABEL_92:
              hkErrStream::hkErrStream((hkErrStream *)&location, buf, 512);
              hkOstream::operator<<((hkOstream *)&location, "Cannot insert crossing edge");
              if ( (unsigned int)hkError::messageError(
                                   0x9CABCB60,
                                   buf,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulato"
                                   "r/hkgpTriangulator.inl",
                                   1676) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&location);
              v72 = (int)retaddr;
              v73 = x0a;
              goto LABEL_95;
            }
            if ( v104 == 0x7FFF && v105 > (int)retaddr )
              goto LABEL_92;
          }
          v75 = v105 == (_DWORD)retaddr;
          goto LABEL_86;
        }
        if ( v103 != x0a )
          goto LABEL_102;
        if ( v103 )
        {
          if ( v103 == 0x7FFF && v99 > (int)retaddr )
          {
LABEL_109:
            hkErrStream::hkErrStream((hkErrStream *)&location, buf, 512);
            hkOstream::operator<<((hkOstream *)&location, "Cannot insert crossing edge");
            if ( (unsigned int)hkError::messageError(
                                 0x9CABCB60,
                                 buf,
                                 "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/"
                                 "hkgpTriangulator.inl",
                                 1682) )
              __debugbreak();
            hkOstream::~hkOstream((hkOstream *)&location);
            v72 = (int)retaddr;
            v73 = x0a;
            goto LABEL_112;
          }
LABEL_102:
          v85 = v99 == (_DWORD)retaddr;
          goto LABEL_103;
        }
        v85 = v99 == (_DWORD)retaddr;
        if ( v99 < (int)retaddr )
          goto LABEL_109;
LABEL_103:
        if ( v85 )
        {
          if ( v99 )
          {
            if ( v99 == 0x7FFF && v103 < x0a )
              goto LABEL_109;
          }
          else if ( v103 > x0a )
          {
            goto LABEL_109;
          }
        }
LABEL_112:
        v84 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
                v119,
                &v116,
                v73,
                v72,
                v103,
                v99,
                v125,
                v126,
                x1);
        LODWORD(retaddr) = v99;
LABEL_113:
        v86 = *(_QWORD *)&v84->m_type.m_storage;
        v87 = v84->m_edge.m_triangle;
        v9 = *(_QWORD *)&v84->m_edge.m_index;
        x0a = v74;
        v6 = v74;
        if ( (_DWORD)v86 == 10 )
        {
          v91 = v120;
          *(_QWORD *)&v120->m_type.m_storage = v86;
          v91->m_edge.m_triangle = v87;
          goto LABEL_125;
        }
        v88 = (unsigned int)v86 <= 1;
        this = v119;
        if ( !v88 )
        {
          hkErrStream::hkErrStream((hkErrStream *)&location, buf, 512);
          hkOstream::operator<<((hkOstream *)&location, "Cannot insert crossing edge");
          if ( (unsigned int)hkError::messageError(
                               0x9CABCB60,
                               buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hk"
                               "gpTriangulator.inl",
                               1690) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&location);
          v6 = x0a;
          this = v119;
        }
      }
    }
    else
    {
      if ( resulta.m_type.m_storage != 4 )
        goto LABEL_124;
      v10 = resulta.m_edge.m_triangle->m_vertices[resulta.m_edge.m_index];
      v11 = v10->m_y;
      v12 = v10->m_x;
      v13 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
              v119,
              &v113,
              x0a,
              v5,
              v12,
              v11,
              v125,
              v126,
              x1);
      v14 = *(_QWORD *)&v13->m_type.m_storage;
      resulta.m_edge = v13->m_edge;
      if ( (_DWORD)v14 == 10 )
      {
        v89 = v14;
        v90 = v120;
        *(_QWORD *)&v120->m_type.m_storage = v89;
        v90->m_edge.m_triangle = v13->m_edge.m_triangle;
        *(_QWORD *)&v90->m_edge.m_index = *(_QWORD *)&v13->m_edge.m_index;
        return v90;
      }
      if ( (unsigned int)v14 > 1 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&location, buf, 512);
        hkOstream::operator<<((hkOstream *)&location, "Cannot insert crossing edge");
        if ( (unsigned int)hkError::messageError(
                             0x9CABCB60,
                             buf,
                             "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgp"
                             "Triangulator.inl",
                             1708) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&location);
      }
      this = v119;
      v6 = v12;
      x0a = v12;
      v5 = v11;
      LODWORD(retaddr) = v11;
    }
  }
  if ( x1 )
  {
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::setEdgeData(
      v119,
      &resulta.m_edge,
      x1);
    v9 = *(_QWORD *)&resulta.m_edge.m_index;
  }
LABEL_124:
  v91 = v120;
  *(_QWORD *)&v120->m_type.m_storage = v7;
  v91->m_edge.m_triangle = m_triangle;
LABEL_125:
  *(_QWORD *)&v91->m_edge.m_index = v9;
  return v91;
}

// File Line: 1753
// RVA: 0xCDF8A0
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::partition(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *i; // r8
  unsigned int v2; // r12d
  hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,64,hkContainerHeapAllocator> *p_m_stack; // rsi
  unsigned int v4; // r12d
  char **p_array; // rdi
  int v6; // r13d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *v7; // rax
  int v8; // edx
  unsigned __int64 v9; // rbx
  unsigned __int64 *v10; // rcx
  hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,64,hkContainerHeapAllocator> *v11; // rbx
  int m_size; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_triangle; // r15
  unsigned __int16 v14; // cx
  int v15; // r14d
  __int64 v16; // rdx
  unsigned __int64 v17; // rsi
  __int64 v18; // r9
  __int64 v19; // r8
  int v20; // eax
  int v21; // ecx
  __int64 v22; // rax
  unsigned __int64 v23; // rax
  int v24; // r9d
  int v25; // eax
  int v26; // eax
  unsigned int v27; // ebx
  unsigned __int64 *v28; // rcx
  int v29; // r9d
  int v30; // eax
  int v31; // eax
  unsigned __int64 *v32; // rax
  unsigned __int64 v34; // [rsp+38h] [rbp-C8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location result; // [rsp+40h] [rbp-C0h] BYREF
  char *array; // [rsp+60h] [rbp-A0h] BYREF
  int v37; // [rsp+68h] [rbp-98h]
  int v38; // [rsp+6Ch] [rbp-94h]
  char v39; // [rsp+70h] [rbp-90h] BYREF
  hkResult v40; // [rsp+4B0h] [rbp+3B0h] BYREF
  hkResult v41; // [rsp+4B8h] [rbp+3B8h] BYREF

  for ( i = this->m_mesh.m_triangles.m_used; i; i = i->m_next )
    *((_WORD *)i + 33) = *((_WORD *)i + 33) & 0x1F | (32 * (((unsigned __int16)(*((_WORD *)i + 33) & 0x1F) >> 5) - 1));
  v2 = *((unsigned __int16 *)this->m_mesh.m_triangles.m_used + 33);
  v37 = 0;
  v38 = -2147483584;
  p_m_stack = &this->m_stack;
  v4 = v2 >> 5;
  array = &v39;
  p_array = &array;
  v6 = -1;
  v7 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
         this,
         &result,
         0,
         0);
  v8 = v37;
  v9 = ((unsigned __int64)v7->m_edge.m_triangle + v7->m_edge.m_index) & 0xFFFFFFFFFFFFFFFCui64;
  LODWORD(v34) = (LOBYTE(v7->m_edge.m_triangle) + (unsigned __int8)v7->m_edge.m_index) & 3;
  if ( v37 == (v38 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
    v8 = v37;
  }
  v10 = (unsigned __int64 *)&array[16 * v8];
  if ( v10 )
  {
    *v10 = v9;
    v10[1] = v34;
    v8 = v37;
  }
  v37 = v8 + 1;
  while ( 1 )
  {
    v11 = (hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,64,hkContainerHeapAllocator> *)p_array;
    p_m_stack->m_size = 0;
    ++v6;
    p_array = (char **)p_m_stack;
    do
    {
      m_size = v11->m_size;
      m_triangle = v11->m_data[m_size - 1].m_triangle;
      result.m_edge.m_triangle = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)&v11->m_data[m_size - 1].m_index;
      v11->m_size = m_size - 1;
      v14 = *((_WORD *)m_triangle + 33);
      if ( v14 >> 5 == v4 )
      {
        v15 = 0;
        *((_WORD *)m_triangle + 33) = (32 * v6) | v14 & 0x1F;
        do
        {
          v16 = m_triangle->m_links[v15] & 3;
          LODWORD(v34) = m_triangle->m_links[v15] & 3;
          v17 = m_triangle->m_links[v15] & 0xFFFFFFFFFFFFFFFCui64;
          if ( v17 && *(unsigned __int16 *)(v17 + 66) >> 5 == v4 )
          {
            v18 = *(_QWORD *)(v17 + 8i64 * (int)v16 + 16);
            v19 = *(_QWORD *)(v17 + 8 * ((9i64 >> (2 * (unsigned __int8)v16)) & 3) + 16);
            v20 = *(_DWORD *)(v18 + 16);
            v21 = *(_DWORD *)(v19 + 16);
            if ( v20 >= v21
              && (v20 > v21 || *(_DWORD *)(v18 + 20) > *(_DWORD *)(v19 + 20))
              && (v22 = *(_QWORD *)(v17 + 8i64 * (int)v16 + 40), (v22 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v16 = *(_QWORD *)(v17 + 8i64 * (int)v16 + 40) & 3i64;
              v23 = v22 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v23 = m_triangle->m_links[v15] & 0xFFFFFFFFFFFFFFFCui64;
            }
            if ( ((1 << v16) & 7 & *(_BYTE *)(v23 + 66)) != 0 )
            {
              v24 = *((_DWORD *)p_array + 2) + 1;
              v25 = *((_DWORD *)p_array + 3) & 0x3FFFFFFF;
              if ( v25 >= v24 )
              {
                v40.m_enum = HK_SUCCESS;
              }
              else
              {
                v26 = 2 * v25;
                if ( v24 < v26 )
                  v24 = v26;
                hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, (const void **)p_array, v24, 16);
                if ( v40.m_enum )
                  goto LABEL_24;
              }
              if ( *((_DWORD *)p_array + 2) == (*((_DWORD *)p_array + 3) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_array, 16);
              v28 = (unsigned __int64 *)&(*p_array)[16 * *((int *)p_array + 2)];
              if ( v28 )
              {
                *v28 = v17;
                v28[1] = v34;
              }
              ++*((_DWORD *)p_array + 2);
            }
            else
            {
              v29 = v11->m_size + 1;
              v30 = v11->m_capacityAndFlags & 0x3FFFFFFF;
              if ( v30 >= v29 )
              {
                v41.m_enum = HK_SUCCESS;
              }
              else
              {
                v31 = 2 * v30;
                if ( v29 < v31 )
                  v29 = v31;
                hkArrayUtil::_reserve(&v41, &hkContainerHeapAllocator::s_alloc, (const void **)&v11->m_data, v29, 16);
                if ( v41.m_enum )
                {
LABEL_24:
                  v27 = -1;
                  goto LABEL_47;
                }
              }
              if ( v11->m_size == (v11->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v11->m_data, 16);
              v32 = (unsigned __int64 *)&v11->m_data[v11->m_size];
              if ( v32 )
              {
                *v32 = v17;
                v32[1] = v34;
              }
              ++v11->m_size;
            }
          }
          ++v15;
        }
        while ( v15 < 3 );
      }
    }
    while ( v11->m_size > 0 );
    if ( *((int *)p_array + 2) <= 0 )
      break;
    p_m_stack = v11;
  }
  v27 = v6 + 1;
LABEL_47:
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v38);
  return v27;
}

// File Line: 1848
// RVA: 0x12EBB60
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::floodEdgeSets<FloodPolicyCell>(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this,
        FloodPolicyCell *policy)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v2; // rsi
  int v4; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_used; // r14
  signed int i; // r15d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v7; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v8; // rdx
  int m_x; // eax
  int v10; // ecx
  unsigned __int64 v11; // rax
  __int64 v12; // rcx
  unsigned __int64 v13; // rax
  hkaiRuntimeTriangulatorEdgeData *EdgeData; // rax
  unsigned __int16 m_sets; // dx
  __int64 v16; // r13
  int v17; // esi
  int v18; // edi
  int v19; // r12d
  int v20; // r9d
  char *v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // r12
  unsigned __int64 v25; // rsi
  __int64 v26; // r13
  unsigned __int16 v27; // ax
  int v28; // r15d
  char v29; // r8
  __int64 v30; // rdx
  unsigned __int64 v31; // rdi
  __int64 v32; // r10
  __int64 v33; // r9
  int v34; // eax
  int v35; // ecx
  unsigned __int64 v36; // rdx
  hkaiRuntimeTriangulatorEdgeData *v37; // rax
  int v38; // r9d
  __int64 v39; // rdi
  char v40; // al
  unsigned __int64 v41; // rdi
  __int64 v42; // r14
  unsigned __int64 *v43; // rdx
  __int64 v44; // rax
  unsigned int v45; // edi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edge; // [rsp+30h] [rbp-D0h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge v47; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v48; // [rsp+50h] [rbp-B0h]
  __int64 v49; // [rsp+60h] [rbp-A0h]
  __int64 v50; // [rsp+78h] [rbp-88h]
  char *array; // [rsp+80h] [rbp-80h] BYREF
  int v52; // [rsp+88h] [rbp-78h]
  int v53; // [rsp+8Ch] [rbp-74h]
  char v54; // [rsp+90h] [rbp-70h] BYREF
  hkResult result; // [rsp+6E0h] [rbp+5E0h] BYREF

  v2 = this;
  if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::partition(this) == -1 )
    return 0i64;
  v4 = 0;
  m_used = v2->m_mesh.m_triangles.m_used;
  array = &v54;
  v52 = 0;
  v53 = -2147483584;
  if ( m_used )
  {
    do
    {
      for ( i = 0; i < 3; ++i )
      {
        v7 = m_used->m_vertices[i];
        edge.m_triangle = m_used;
        edge.m_index = i;
        v8 = m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)i)) & 3];
        m_x = v7->m_x;
        v10 = v8->m_x;
        if ( m_x >= v10
          && (m_x > v10 || v7->m_y > v8->m_y)
          && (v11 = m_used->m_links[i], (v11 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
        {
          v12 = m_used->m_links[i] & 3;
          v13 = v11 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v13 = (unsigned __int64)m_used;
          LOBYTE(v12) = i;
        }
        if ( ((unsigned __int8)(1 << v12) & (unsigned __int8)*(_WORD *)(v13 + 100) & 7) != 0 )
        {
          EdgeData = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
                       v2,
                       &edge);
          if ( EdgeData )
          {
            m_sets = EdgeData->m_sets;
            if ( m_sets )
            {
              if ( (m_used->m_links[i] & 0xFFFFFFFFFFFFFFFCui64) == 0
                || (unsigned __int16)(*((_WORD *)m_used + 50) & 0xFFE0) > (unsigned __int16)(*(_WORD *)((m_used->m_links[i] & 0xFFFFFFFFFFFFFFFCui64) + 100) & 0xFFE0) )
              {
                v16 = *(_QWORD *)&edge.m_index;
                v17 = 0;
                v18 = 1;
                v19 = m_sets;
                while ( 1 )
                {
                  if ( (v19 & v18) != 0 )
                  {
                    v20 = v4 + 1;
                    if ( (v53 & 0x3FFFFFFF) >= v4 + 1 )
                    {
                      result.m_enum = HK_SUCCESS;
                    }
                    else
                    {
                      if ( v20 < 2 * (v53 & 0x3FFFFFFF) )
                        v20 = 2 * (v53 & 0x3FFFFFFF);
                      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v20, 24);
                      if ( result.m_enum )
                      {
LABEL_60:
                        v45 = 0;
                        goto LABEL_62;
                      }
                      v4 = v52;
                    }
                    LOWORD(v48) = v18;
                    if ( v4 == (v53 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 24);
                      v4 = v52;
                    }
                    v21 = &array[24 * v4];
                    if ( v21 )
                    {
                      v22 = v48;
                      *(_QWORD *)v21 = m_used;
                      *((_QWORD *)v21 + 1) = v16;
                      *((_QWORD *)v21 + 2) = v22;
                      v4 = v52;
                    }
                    v52 = ++v4;
                  }
                  ++v17;
                  v18 *= 2;
                  if ( v17 >= 16 )
                  {
                    v2 = this;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      m_used = m_used->m_next;
    }
    while ( m_used );
    while ( v4 )
    {
      v23 = v4--;
      v24 = *(_QWORD *)&array[24 * v23 - 8];
      v25 = *(_QWORD *)&array[24 * v23 - 24];
      v26 = *(_QWORD *)&array[24 * v23 - 16];
      v52 = v4;
      v27 = *(_WORD *)(v25 + 102);
      v48 = v24;
      if ( (v27 & (unsigned __int16)v24) == 0 )
      {
        v28 = 0;
        *(_WORD *)(v25 + 102) = v24 | v27;
        v4 = v52;
        do
        {
          v47.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)v25;
          LODWORD(v26) = (9 >> (2 * v26)) & 3;
          v29 = v26;
          edge.m_index = v26;
          v30 = *(_QWORD *)(v25 + 8i64 * (int)v26 + 40);
          *(_QWORD *)&v47.m_index = *(_QWORD *)&edge.m_index;
          v31 = v30 & 0xFFFFFFFFFFFFFFFCui64;
          if ( (v30 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            v32 = *(_QWORD *)(v25 + 8i64 * (int)v26 + 16);
            v33 = *(_QWORD *)(v25 + 8 * ((9i64 >> (2 * (unsigned __int8)v26)) & 3) + 16);
            v34 = *(_DWORD *)(v32 + 16);
            v35 = *(_DWORD *)(v33 + 16);
            if ( v34 < v35 || v34 <= v35 && *(_DWORD *)(v32 + 20) <= *(_DWORD *)(v33 + 20) )
            {
              v36 = v25;
            }
            else
            {
              v29 = v30 & 3;
              v36 = v30 & 0xFFFFFFFFFFFFFFFCui64;
            }
            if ( ((unsigned __int8)(1 << v29) & (unsigned __int8)*(_WORD *)(v36 + 100) & 7) == 0
              || ((v37 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
                           this,
                           &v47)) == 0i64
               || ((unsigned __int16)v24 & v37->m_sets) == 0)
              && (unsigned __int16)(*(_WORD *)(v25 + 100) & 0xFFE0) < (unsigned __int16)(*(_WORD *)(v31 + 100) & 0xFFE0) )
            {
              v38 = v4 + 1;
              if ( (v53 & 0x3FFFFFFF) >= v4 + 1 )
              {
                result.m_enum = HK_SUCCESS;
              }
              else
              {
                if ( v38 < 2 * (v53 & 0x3FFFFFFF) )
                  v38 = 2 * (v53 & 0x3FFFFFFF);
                hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v38, 24);
                if ( result.m_enum )
                  goto LABEL_60;
                v4 = v52;
              }
              v39 = *(_QWORD *)(v25 + 8i64 * (int)v26 + 40);
              LOWORD(v50) = v24;
              v40 = v39;
              v41 = v39 & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v49) = v40 & 3;
              v42 = v49;
              if ( v4 == (v53 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 24);
                v4 = v52;
              }
              v43 = (unsigned __int64 *)&array[24 * v4];
              if ( v43 )
              {
                v44 = v50;
                *v43 = v41;
                v43[1] = v42;
                v43[2] = v44;
                v4 = v52;
              }
              v52 = ++v4;
            }
          }
          ++v28;
        }
        while ( v28 < 2 );
      }
    }
  }
  v45 = 1;
LABEL_62:
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 24 * (v53 & 0x3FFFFFFF));
  return v45;
}

// File Line: 1935
// RVA: 0xB864C0
hkResult *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::partitionWithPolicy<hkaiNavMeshFloodPolicy>(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this,
        hkResult *result,
        hkaiNavMeshFloodPolicy *policy)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *i; // r9
  int v4; // r14d
  hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,64,hkContainerHeapAllocator> *p_m_stack; // r12
  char **p_array; // rsi
  int v7; // r15d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Location *v8; // rax
  int v9; // ecx
  unsigned __int64 v10; // rbx
  unsigned __int64 *v11; // rdx
  unsigned __int64 v12; // rax
  hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,64,hkContainerHeapAllocator> *v13; // rdi
  int m_size; // edx
  __int64 m_triangle; // r8
  unsigned __int16 v16; // cx
  int v17; // r13d
  __int64 v18; // rdx
  unsigned __int64 v19; // rbx
  __int64 v20; // r10
  __int64 v21; // r9
  __int64 v22; // r8
  int v23; // eax
  int v24; // ecx
  __int64 v25; // rax
  unsigned __int64 v26; // rax
  __int64 v27; // r12
  char v28; // cl
  unsigned __int64 v29; // r8
  int v30; // r15d
  __int64 v31; // r10
  __int64 v32; // r9
  int v33; // eax
  int v34; // ecx
  __int64 v35; // rax
  unsigned __int64 v36; // rax
  int v37; // r14d
  hkaiNavMeshGenTriangulatorEdgeData *EdgeData; // rax
  hkaiNavMeshGenTriangulatorEdgeData *v39; // r15
  hkaiNavMeshGenTriangulatorEdgeData *v40; // rax
  __int16 m_counter; // cx
  __int16 v42; // ax
  int v43; // r9d
  int v44; // eax
  int v45; // eax
  hkResult *v46; // rbx
  unsigned __int64 *v47; // rcx
  unsigned __int64 v48; // rax
  int v49; // r9d
  int v50; // eax
  int v51; // eax
  unsigned __int64 *v52; // rcx
  unsigned __int64 v53; // rax
  hkResult v55; // [rsp+30h] [rbp-D0h] BYREF
  int v56; // [rsp+34h] [rbp-CCh]
  int v57; // [rsp+38h] [rbp-C8h]
  __int64 v58; // [rsp+40h] [rbp-C0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge v59; // [rsp+48h] [rbp-B8h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge edge; // [rsp+58h] [rbp-A8h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Location resulta; // [rsp+70h] [rbp-90h] BYREF
  char *array; // [rsp+90h] [rbp-70h] BYREF
  int v63; // [rsp+98h] [rbp-68h]
  int v64; // [rsp+9Ch] [rbp-64h]
  char v65; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v68; // [rsp+4F8h] [rbp+3F8h] BYREF

  for ( i = this->m_mesh.m_triangles.m_used; i; i = i->m_next )
    *((_WORD *)i + 44) = *((_WORD *)i + 44) & 0x1F | (32 * (((unsigned __int16)(*((_WORD *)i + 44) & 0x1F) >> 5) - 1));
  v4 = *((unsigned __int16 *)this->m_mesh.m_triangles.m_used + 44) >> 5;
  v63 = 0;
  v64 = -2147483584;
  array = &v65;
  p_m_stack = &this->m_stack;
  p_array = &array;
  v56 = v4;
  v7 = -1;
  v8 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
         this,
         &resulta,
         0,
         0);
  v9 = v63;
  v10 = ((unsigned __int64)v8->m_edge.m_triangle + v8->m_edge.m_index) & 0xFFFFFFFFFFFFFFFCui64;
  v59.m_index = (LOBYTE(v8->m_edge.m_triangle) + (unsigned __int8)v8->m_edge.m_index) & 3;
  if ( v63 == (v64 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
    v9 = v63;
  }
  v11 = (unsigned __int64 *)&array[16 * v9];
  if ( v11 )
  {
    v12 = *(_QWORD *)&v59.m_index;
    *v11 = v10;
    v11[1] = v12;
    v9 = v63;
  }
  v63 = v9 + 1;
  while ( 1 )
  {
    v13 = (hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge,64,hkContainerHeapAllocator> *)p_array;
    p_array = (char **)p_m_stack;
    ++v7;
    p_m_stack->m_size = 0;
    v57 = v7;
    do
    {
      m_size = v13->m_size;
      m_triangle = (__int64)v13->m_data[m_size - 1].m_triangle;
      resulta.m_edge.m_triangle = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v13->m_data[m_size - 1].m_index;
      v58 = m_triangle;
      v13->m_size = m_size - 1;
      v16 = *(_WORD *)(m_triangle + 88);
      if ( v16 >> 5 == v4 )
      {
        v17 = 0;
        *(_WORD *)(m_triangle + 88) = (32 * v7) | v16 & 0x1F;
        do
        {
          v18 = *(_QWORD *)(m_triangle + 8i64 * v17 + 40) & 3i64;
          v19 = *(_QWORD *)(m_triangle + 8i64 * v17 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v19;
          edge.m_index = v18;
          if ( v19 && *(unsigned __int16 *)(v19 + 88) >> 5 == v4 )
          {
            v20 = (int)v18;
            v21 = *(_QWORD *)(v19 + 8i64 * (int)v18 + 16);
            v22 = *(_QWORD *)(v19 + 8 * ((9i64 >> (2 * (unsigned __int8)v18)) & 3) + 16);
            v23 = *(_DWORD *)(v21 + 16);
            v24 = *(_DWORD *)(v22 + 16);
            if ( v23 >= v24
              && (v23 > v24 || *(_DWORD *)(v21 + 20) > *(_DWORD *)(v22 + 20))
              && (v25 = *(_QWORD *)(v19 + 8i64 * (int)v18 + 40), (v25 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v18 = *(_QWORD *)(v19 + 8i64 * (int)v18 + 40) & 3i64;
              v26 = v25 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v26 = v19;
            }
            v27 = *(_QWORD *)(v19 + 8 * v20 + 40);
            v28 = v18;
            LOBYTE(v18) = v27 & 3;
            v29 = v27 & 0xFFFFFFFFFFFFFFFCui64;
            v30 = (unsigned __int8)(1 << v28) & (unsigned __int8)*(_WORD *)(v26 + 88) & 7;
            v31 = *(_QWORD *)((v27 & 0xFFFFFFFFFFFFFFFCui64) + 8 * (v27 & 3) + 16);
            v32 = *(_QWORD *)((v27 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((9i64 >> (2 * ((unsigned __int8)v27 & 3u))) & 3) + 16);
            v33 = *(_DWORD *)(v31 + 16);
            v34 = *(_DWORD *)(v32 + 16);
            if ( v33 >= v34
              && (v33 > v34 || *(_DWORD *)(v31 + 20) > *(_DWORD *)(v32 + 20))
              && (v35 = *(_QWORD *)(v29 + 8 * (v27 & 3) + 40), (v35 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v18 = *(_QWORD *)(v29 + 8 * (v27 & 3) + 40) & 3i64;
              v36 = v35 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v36 = v27 & 0xFFFFFFFFFFFFFFFCui64;
            }
            v37 = v30 | (unsigned __int8)(1 << v18) & (unsigned __int8)*(_WORD *)(v36 + 88) & 7;
            EdgeData = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                         this,
                         &edge);
            v59.m_index = v27 & 3;
            v39 = EdgeData;
            v59.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v27 & 0xFFFFFFFFFFFFFFFCui64);
            v40 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                    this,
                    &v59);
            if ( v39 )
              m_counter = v39->m_counter;
            else
              m_counter = 0;
            if ( v40 )
              v42 = v40->m_counter;
            else
              v42 = 0;
            if ( v37 && ((unsigned __int16)(m_counter + v42) & 0x80000001) != 0 )
            {
              v43 = *((_DWORD *)p_array + 2) + 1;
              v44 = *((_DWORD *)p_array + 3) & 0x3FFFFFFF;
              if ( v44 >= v43 )
              {
                v68.m_enum = HK_SUCCESS;
              }
              else
              {
                v45 = 2 * v44;
                if ( v43 < v45 )
                  v43 = v45;
                hkArrayUtil::_reserve(&v68, &hkContainerHeapAllocator::s_alloc, p_array, v43, 16);
                if ( v68.m_enum )
                  goto LABEL_37;
              }
              if ( *((_DWORD *)p_array + 2) == (*((_DWORD *)p_array + 3) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_array, 16);
              v47 = (unsigned __int64 *)&(*p_array)[16 * *((int *)p_array + 2)];
              if ( v47 )
              {
                v48 = *(_QWORD *)&edge.m_index;
                *v47 = v19;
                v47[1] = v48;
              }
              ++*((_DWORD *)p_array + 2);
            }
            else
            {
              v49 = v13->m_size + 1;
              v50 = v13->m_capacityAndFlags & 0x3FFFFFFF;
              if ( v50 >= v49 )
              {
                v55.m_enum = HK_SUCCESS;
              }
              else
              {
                v51 = 2 * v50;
                if ( v49 < v51 )
                  v49 = v51;
                hkArrayUtil::_reserve(&v55, &hkContainerHeapAllocator::s_alloc, v13, v49, 16);
                if ( v55.m_enum )
                {
LABEL_37:
                  v46 = result;
                  result->m_enum = HK_FAILURE;
                  goto LABEL_62;
                }
              }
              if ( v13->m_size == (v13->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v13, 16);
              v52 = (unsigned __int64 *)&v13->m_data[v13->m_size];
              if ( v52 )
              {
                v53 = *(_QWORD *)&edge.m_index;
                *v52 = v19;
                v52[1] = v53;
              }
              ++v13->m_size;
            }
            v4 = v56;
            m_triangle = v58;
          }
          ++v17;
        }
        while ( v17 < 3 );
        v7 = v57;
      }
    }
    while ( v13->m_size > 0 );
    if ( *((int *)p_array + 2) <= 0 )
      break;
    p_m_stack = v13;
  }
  v46 = result;
  result->m_enum = HK_SUCCESS;
LABEL_62:
  v63 = 0;
  if ( v64 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v64);
  return v46;
}

// File Line: 2013
// RVA: 0xCD8B20
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::conformEdges(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v1; // rdx
  int v2; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *m_used; // rax
  int i; // r15d
  __int64 v5; // rcx
  __int64 v6; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v7; // r13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v8; // r12
  int m_x; // ecx
  int v10; // edx
  char v11; // cl
  unsigned __int64 v12; // r8
  __int64 v13; // r9
  int v14; // r8d
  int v15; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v16; // rcx
  int v17; // edx
  int v18; // ebp
  int v19; // edi
  int v20; // esi
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  char v24; // cl
  unsigned __int64 v25; // rdx
  int v26; // esi
  unsigned __int64 v27; // r14
  int v28; // ebx
  __int64 v29; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v30; // rdi
  __int64 v31; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v32; // r9
  int v33; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v34; // r8
  int v35; // edx
  unsigned __int64 v36; // r8
  __int64 v37; // rcx
  unsigned __int64 v38; // r8
  __int16 v39; // dx
  int v40; // r11d
  unsigned __int64 v41; // r10
  __int64 v42; // rdi
  int v43; // ecx
  __int64 v44; // r9
  int v45; // edx
  __int64 v46; // r9
  unsigned __int64 v47; // r9
  __int16 v48; // dx
  int v49; // edi
  unsigned __int64 v50; // r8
  __int64 v51; // rsi
  int v52; // r10d
  unsigned __int64 v53; // r9
  int v54; // r12d
  unsigned __int64 v55; // r9
  int v56; // esi
  unsigned __int64 v57; // r8
  __int64 v58; // r9
  __int64 v59; // r11
  int v60; // ecx
  __int64 v61; // r10
  int v62; // edx
  __int64 v63; // r10
  unsigned __int64 v64; // r10
  __int64 v65; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v66; // r10
  int v67; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v68; // r8
  int v69; // edx
  unsigned __int64 v70; // r10
  unsigned __int64 v71; // r10
  int v72; // ecx
  bool v73; // zf
  char v74; // [rsp+20h] [rbp-278h]
  hkErrStream v75; // [rsp+30h] [rbp-268h] BYREF
  char buf[584]; // [rsp+50h] [rbp-248h] BYREF
  int v78; // [rsp+2A8h] [rbp+10h]
  int v79; // [rsp+2B0h] [rbp+18h]
  _QWORD *v80; // [rsp+2B8h] [rbp+20h]

  v1 = this;
  v2 = this->m_mesh.m_triangles.m_numUsed + 2 * this->m_mesh.m_triangles.m_numUsed + 1;
  v79 = v2;
  do
  {
    m_used = v1->m_mesh.m_triangles.m_used;
    v78 = 0;
    if ( !m_used )
      break;
    do
    {
      for ( i = 0; i < 3; ++i )
      {
        v5 = i + 5i64;
        v6 = *((_QWORD *)&m_used->m_next + v5);
        v80 = &m_used->m_next + v5;
        if ( (v6 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
          goto LABEL_55;
        v7 = m_used->m_vertices[i];
        v8 = m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)i)) & 3];
        m_x = v7->m_x;
        v10 = v8->m_x;
        if ( m_x < v10 || m_x <= v10 && v7->m_y <= v8->m_y )
        {
          v12 = (unsigned __int64)m_used;
          v11 = i;
        }
        else
        {
          v11 = v6 & 3;
          v12 = v6 & 0xFFFFFFFFFFFFFFFCui64;
        }
        if ( ((1 << v11) & 7 & *(_BYTE *)(v12 + 66)) != 0 )
          goto LABEL_55;
        v13 = *(_QWORD *)((v6 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((18i64 >> (2 * ((unsigned __int8)v6 & 3u))) & 3) + 16);
        v14 = *(_DWORD *)(v13 + 20);
        v15 = v8->m_y - v14;
        v16 = m_used->m_vertices[(18i64 >> (2 * (unsigned __int8)i)) & 3];
        v17 = *(_DWORD *)(v13 + 16);
        v18 = v16->m_x - v17;
        v19 = v8->m_x - v17;
        v20 = v16->m_y - v14;
        v21 = v7->m_x - v17;
        if ( (v15 * v15 + v19 * v19) * (__int64)((v7->m_y - v14) * v18 - v21 * v20)
           + (v19 * v20 - v15 * v18) * (__int64)((v7->m_y - v14) * (v7->m_y - v14) + v21 * v21)
           + (v15 * v21 - v19 * (v7->m_y - v14)) * (__int64)(v20 * v20 + v18 * v18) <= 0 )
          goto LABEL_55;
        v22 = v7->m_x;
        v23 = v8->m_x;
        if ( v22 < v23 || v22 <= v23 && v7->m_y <= v8->m_y )
        {
          v25 = (unsigned __int64)m_used;
          v24 = i;
        }
        else
        {
          v24 = v6 & 3;
          v25 = v6 & 0xFFFFFFFFFFFFFFFCui64;
        }
        if ( ((unsigned __int8)(1 << v24) & (unsigned __int8)*(_WORD *)(v25 + 66) & 7) != 0
          || (v26 = v6 & 3,
              v27 = v6 & 0xFFFFFFFFFFFFFFFCui64,
              v28 = (18 >> (2 * i)) & 3,
              v29 = *(_QWORD *)(v27 + 8i64 * ((18 >> (2 * v26)) & 3) + 16),
              v30 = m_used->m_vertices[v28],
              (v7->m_x - v30->m_x) * (*(_DWORD *)(v29 + 20) - v30->m_y)
            - (*(_DWORD *)(v29 + 16) - v30->m_x) * (v7->m_y - v30->m_y) <= 0)
          || (v31 = *(_QWORD *)(v27 + 8i64 * v26 + 16),
              (*(_DWORD *)(v31 + 16) - *(_DWORD *)(v29 + 16)) * (v30->m_y - *(_DWORD *)(v29 + 20))
            - (*(_DWORD *)(v31 + 20) - *(_DWORD *)(v29 + 20)) * (v30->m_x - *(_DWORD *)(v29 + 16)) <= 0) )
        {
LABEL_55:
          v72 = v78;
        }
        else
        {
          v32 = m_used->m_vertices[v28];
          v74 = 2 * v28;
          v33 = v32->m_x;
          v34 = m_used->m_vertices[(9i64 >> (2 * (unsigned __int8)v28)) & 3];
          v35 = v34->m_x;
          if ( v33 >= v35
            && (v33 > v35 || v32->m_y > v34->m_y)
            && (v36 = m_used->m_links[v28], (v36 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
          {
            v37 = m_used->m_links[v28] & 3;
            v38 = v36 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v38 = (unsigned __int64)m_used;
            LOBYTE(v37) = (18 >> (2 * i)) & 3;
          }
          v39 = *(_WORD *)(v38 + 66);
          v40 = (unsigned __int8)v39 & (1 << v37) & 7;
          *(_WORD *)(v38 + 66) = v39 & (~((unsigned __int8)v39 & (1 << v37) & 7) | 0xFFF8);
          v41 = *v80 & 0xFFFFFFFFFFFFFFFCui64;
          LODWORD(v38) = (18 >> (2 * (*v80 & 3))) & 3;
          v42 = *(_QWORD *)(v41 + 8i64 * (int)v38 + 16);
          v43 = *(_DWORD *)(v42 + 16);
          v44 = *(_QWORD *)(v41 + 8 * ((9i64 >> (2 * ((18 >> (2 * (*v80 & 3))) & 3u))) & 3) + 16);
          v45 = *(_DWORD *)(v44 + 16);
          if ( v43 >= v45
            && (v43 > v45 || *(_DWORD *)(v42 + 20) > *(_DWORD *)(v44 + 20))
            && (v46 = *(_QWORD *)(v41 + 8i64 * (int)v38 + 40), (v46 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
          {
            v38 = *(_QWORD *)(v41 + 8i64 * (int)v38 + 40) & 3i64;
            v47 = v46 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v47 = *v80 & 0xFFFFFFFFFFFFFFFCui64;
          }
          v48 = *(_WORD *)(v47 + 66);
          v49 = (unsigned __int8)v48 & (1 << v38) & 7;
          *(_WORD *)(v47 + 66) = v48 & (~((unsigned __int8)v48 & (1 << v38) & 7) | 0xFFF8);
          v50 = *v80 & 0xFFFFFFFFFFFFFFFCui64;
          v51 = *v80 & 3i64;
          v52 = (18 >> (2 * v51)) & 3;
          m_used->m_vertices[i] = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(v50 + 8i64 * v52 + 16);
          *(_QWORD *)(v50 + 8i64 * (int)v51 + 16) = m_used->m_vertices[v28];
          v53 = m_used->m_links[v28] & 0xFFFFFFFFFFFFFFFCui64;
          v54 = m_used->m_links[v28] & 3;
          *(_QWORD *)(v50 + 8i64 * (int)v51 + 40) = m_used->m_links[v28];
          if ( v53 )
            *(_QWORD *)(v53 + 8i64 * v54 + 40) = v50 + (unsigned int)v51;
          v55 = *(_QWORD *)(v50 + 8i64 * v52 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          v56 = *(_DWORD *)(v50 + 8i64 * v52 + 40) & 3;
          *v80 = *(_QWORD *)(v50 + 8i64 * v52 + 40);
          if ( v55 )
            *(_QWORD *)(v55 + 8i64 * v56 + 40) = (char *)m_used + (unsigned int)i;
          m_used->m_links[v28] = v50 + (unsigned int)v52;
          if ( v50 )
            *(_QWORD *)(v50 + 8i64 * v52 + 40) = (char *)m_used + (unsigned int)v28;
          if ( v40 )
          {
            v57 = m_used->m_links[v28] & 0xFFFFFFFFFFFFFFFCui64;
            LODWORD(v58) = (9 >> (2 * (m_used->m_links[v28] & 3))) & 3;
            v59 = *(_QWORD *)(v57 + 8i64 * (int)v58 + 16);
            v60 = *(_DWORD *)(v59 + 16);
            v61 = *(_QWORD *)(v57 + 8 * ((9i64 >> (2 * ((9 >> (2 * (m_used->m_links[v28] & 3))) & 3u))) & 3) + 16);
            v62 = *(_DWORD *)(v61 + 16);
            if ( v60 >= v62
              && (v60 > v62 || *(_DWORD *)(v59 + 20) > *(_DWORD *)(v61 + 20))
              && (v63 = *(_QWORD *)(v57 + 8i64 * (int)v58 + 40), (v63 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v58 = *(_QWORD *)(v57 + 8i64 * (int)v58 + 40) & 3i64;
              v64 = v63 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v64 = m_used->m_links[v28] & 0xFFFFFFFFFFFFFFFCui64;
            }
            *(_WORD *)(v64 + 66) ^= ((unsigned __int8)*(_WORD *)(v64 + 66) ^ (unsigned __int8)(*(_WORD *)(v64 + 66) | (1 << v58))) & 7;
          }
          if ( v49 )
          {
            LODWORD(v65) = (9 >> v74) & 3;
            v66 = m_used->m_vertices[(int)v65];
            v67 = v66->m_x;
            v68 = m_used->m_vertices[(9i64 >> (2 * ((9 >> v74) & 3u))) & 3];
            v69 = v68->m_x;
            if ( v67 >= v69
              && (v67 > v69 || v66->m_y > v68->m_y)
              && (v70 = m_used->m_links[(int)v65], (v70 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
            {
              v65 = m_used->m_links[(int)v65] & 3;
              v71 = v70 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v71 = (unsigned __int64)m_used;
            }
            *(_WORD *)(v71 + 66) ^= ((unsigned __int8)*(_WORD *)(v71 + 66) ^ (unsigned __int8)(*(_WORD *)(v71 + 66) | (1 << v65))) & 7;
          }
          v72 = ++v78;
        }
      }
      m_used = m_used->m_next;
    }
    while ( m_used );
    v73 = v72 == 0;
    v2 = v79;
    if ( v73 )
      break;
    v1 = this;
    v2 = v79 - 1;
    v79 = v2;
  }
  while ( v2 );
  if ( !v2 )
  {
    hkErrStream::hkErrStream(&v75, buf, 512);
    hkOstream::operator<<(&v75, "Infinite cycle detected during triangulation");
    hkError::messageWarning(
      0xD26E67Du,
      buf,
      "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
      2034);
    hkOstream::~hkOstream(&v75);
  }
}

// File Line: 2175
// RVA: 0x12ED100
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::decomposeFastFixedSize(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this,
        hkArrayBase<unsigned int> *pieceSize,
        _DWORD *_storage,
        int capacity,
        int *numEdgesOut,
        int *maxEdgesPerPieceOut)
{
  int *v6; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_used; // rax
  int *v10; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_next; // r8
  unsigned __int16 v12; // ax
  UidItem *v13; // r11
  int v14; // edx
  int v15; // r14d
  int v16; // r12d
  int v17; // esi
  int v18; // r15d
  int v19; // ebp
  UidItem *v20; // rbx
  __int64 patchIndex; // rcx
  __int64 v22; // r8
  unsigned __int64 v23; // rdi
  unsigned __int16 v24; // cx
  unsigned __int64 uid; // r10
  __int64 v26; // r9
  unsigned __int64 v27; // r12
  __int64 v28; // r13
  __int64 v29; // r11
  __int64 v30; // r8
  __int64 v31; // rcx
  __int64 v32; // r8
  __int64 v33; // rcx
  char *v35; // [rsp+20h] [rbp-88h]
  UidItem *v36; // [rsp+28h] [rbp-80h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v37; // [rsp+30h] [rbp-78h]
  char v38; // [rsp+38h] [rbp-70h]
  hkArrayBase<UidItem> v39; // [rsp+40h] [rbp-68h] BYREF
  UidItem t; // [rsp+50h] [rbp-58h] BYREF
  __int64 v41; // [rsp+68h] [rbp-40h]
  int v42; // [rsp+B0h] [rbp+8h] BYREF
  hkArrayBase<unsigned int> *v43; // [rsp+B8h] [rbp+10h]
  int v44; // [rsp+C0h] [rbp+18h]

  v43 = pieceSize;
  v6 = &v42;
  *maxEdgesPerPieceOut = -1;
  *numEdgesOut = 0;
  m_used = this->m_mesh.m_triangles.m_used;
  if ( !m_used )
    v6 = 0i64;
  if ( v6 )
  {
    do
    {
      *((_WORD *)m_used + 50) &= ~0x10u;
      m_used = m_used->m_next;
      v10 = &v42;
      if ( !m_used )
        v10 = 0i64;
    }
    while ( v10 );
  }
  m_next = this->m_mesh.m_triangles.m_used;
  v37 = m_next;
  if ( !m_next )
    return (unsigned int)pieceSize->m_size;
  do
  {
    v12 = *((_WORD *)m_next + 50);
    if ( (v12 & 0x10) != 0 || (v12 & 0x20) == 0 )
      goto LABEL_37;
    v13 = (UidItem *)_storage;
    v36 = (UidItem *)_storage;
    v14 = v12 >> 5;
    v44 = v14;
    if ( _storage )
    {
      *(_QWORD *)_storage = m_next;
      _storage[2] = 0;
    }
    if ( _storage != (_DWORD *)-16i64 )
    {
      *((_QWORD *)_storage + 2) = m_next;
      _storage[6] = 1;
    }
    if ( _storage != (_DWORD *)-32i64 )
    {
      *((_QWORD *)_storage + 4) = m_next;
      _storage[10] = 2;
    }
    *((_WORD *)m_next + 50) |= 0x10u;
    v15 = 3;
    v35 = (char *)(_storage + 12);
    do
    {
      v16 = 0;
      v42 = 0;
      v17 = 0;
      v18 = v15;
      if ( v15 <= 0 )
      {
        _storage = v35;
        break;
      }
      v19 = 1;
      v20 = v13;
      do
      {
        patchIndex = v20->patchIndex;
        v22 = *(_QWORD *)(v20->uid + 8 * patchIndex + 40) & 3i64;
        v23 = *(_QWORD *)(v20->uid + 8 * patchIndex + 40) & 0xFFFFFFFFFFFFFFFCui64;
        if ( !v23 )
          goto LABEL_29;
        v24 = *(_WORD *)(v23 + 100);
        if ( v24 >> 5 != v14 || (v24 & 0x10) != 0 )
          goto LABEL_29;
        uid = v13[(v18 + v17 - 1) % v18].uid;
        v26 = *(_QWORD *)&v13[(v18 + v17 - 1) % v18].patchIndex;
        v27 = v13[v19 % v18].uid;
        v28 = *(_QWORD *)&v13[v19 % v18].patchIndex;
        v38 = 2 * v22;
        v29 = *(_QWORD *)(v23 + 8 * ((18i64 >> (2 * (unsigned __int8)v22)) & 3) + 16);
        v30 = *(_QWORD *)(uid + 8 * ((9i64 >> (2 * (unsigned __int8)v26)) & 3) + 16);
        v31 = *(_QWORD *)(uid + 8i64 * (int)v26 + 16);
        if ( (*(_DWORD *)(v29 + 20) - *(_DWORD *)(v31 + 20)) * (*(_DWORD *)(v30 + 16) - *(_DWORD *)(v31 + 16))
           - (*(_DWORD *)(v29 + 16) - *(_DWORD *)(v31 + 16)) * (*(_DWORD *)(v30 + 20) - *(_DWORD *)(v31 + 20)) < 0 )
        {
          v16 = v42;
LABEL_28:
          v14 = v44;
          v13 = v36;
LABEL_29:
          _storage = v35;
          goto LABEL_30;
        }
        v32 = *(_QWORD *)(v27 + 8 * ((9i64 >> (2 * (unsigned __int8)v28)) & 3) + 16);
        v33 = *(_QWORD *)(v27 + 8i64 * (int)v28 + 16);
        v16 = v42;
        if ( (*(_DWORD *)(v29 + 20) - *(_DWORD *)(v33 + 20)) * (*(_DWORD *)(v32 + 16) - *(_DWORD *)(v33 + 16))
           - (*(_DWORD *)(v29 + 16) - *(_DWORD *)(v33 + 16)) * (*(_DWORD *)(v32 + 20) - *(_DWORD *)(v33 + 20)) < 0 )
          goto LABEL_28;
        v20->uid = v23;
        ++v16;
        v39.m_size = v15;
        ++v18;
        ++v15;
        LODWORD(v41) = (18 >> v38) & 3;
        *(_QWORD *)&v20->patchIndex = v41;
        v42 = v16;
        v39.m_data = v36;
        t.uid = v23;
        v39.m_capacityAndFlags = v15 | 0x80000000;
        t.patchIndex = (9 >> v38) & 3;
        hkArrayBase<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>::_insertAt(
          &v39,
          &hkContainerHeapAllocator::s_alloc,
          v17,
          &t);
        *(_WORD *)(v23 + 100) |= 0x10u;
        _storage = v35 + 16;
        --v17;
        --v19;
        --v20;
        v35 += 16;
        v39.m_size = 0;
        if ( v39.m_capacityAndFlags >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v39.m_data,
            16 * v39.m_capacityAndFlags);
          _storage = v35;
        }
        v13 = v36;
        v14 = v44;
        v39.m_data = 0i64;
        v39.m_capacityAndFlags = 0x80000000;
LABEL_30:
        ++v17;
        ++v19;
        ++v20;
      }
      while ( v17 < v18 );
    }
    while ( v16 );
    pieceSize = v43;
    m_next = v37;
    v43->m_data[v43->m_size] = v15;
    ++pieceSize->m_size;
    *numEdgesOut += v15;
    if ( *maxEdgesPerPieceOut > v15 )
      v15 = *maxEdgesPerPieceOut;
    *maxEdgesPerPieceOut = v15;
LABEL_37:
    m_next = m_next->m_next;
    v37 = m_next;
  }
  while ( m_next );
  return (unsigned int)pieceSize->m_size;
}

// File Line: 2243
// RVA: 0x12ED520
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::flushConform(
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this)
{
  int m_size; // ebp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *m_data; // r12
  __int64 v4; // r13
  int v5; // r15d
  __int64 m_index; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_triangle; // r9
  unsigned __int64 v8; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v9; // rbx
  char v10; // di
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v11; // r11
  int m_x; // eax
  int v13; // ecx
  unsigned __int64 v14; // rax
  __int64 v15; // rdx
  int v16; // r8d
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v17; // rcx
  int v18; // eax
  int m_y; // r9d
  int v20; // r10d
  int v21; // ebx
  int v22; // edi
  int v23; // r9d
  int v24; // r11d
  __int64 v25; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v26; // r9
  unsigned __int64 v27; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v28; // r11
  char v29; // bl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v30; // rdx
  int v31; // eax
  int v32; // ecx
  unsigned __int64 v33; // rax
  int v34; // esi
  unsigned __int64 v35; // r10
  __int64 v36; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v37; // rbx
  int v38; // r8d
  int v39; // edx
  __int64 v40; // r9
  int v41; // r9d
  int v42; // eax
  int v43; // eax
  __int64 v44; // rdx
  hkBaseObjectVtbl *vfptr; // r8
  __int64 v46; // r9
  char v47; // cl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v48; // r9
  __int64 v49; // rax
  int v50; // ecx
  hkOstream result; // [rsp+30h] [rbp-268h] BYREF
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edgeArg; // [rsp+48h] [rbp-250h] BYREF
  char buf[512]; // [rsp+60h] [rbp-238h] BYREF
  int v55; // [rsp+2A8h] [rbp+10h]
  hkResult v56; // [rsp+2B0h] [rbp+18h] BYREF

  m_size = this->m_stack.m_size;
  v55 = this->m_mesh.m_triangles.m_numUsed + 2 * this->m_mesh.m_triangles.m_numUsed + 1;
  do
  {
    m_data = this->m_stack.m_data;
    v4 = this->m_stack.m_size;
    v5 = v4 - 1;
    m_index = (int)m_data[(int)v4 - 1].m_index;
    m_triangle = m_data[(int)v4 - 1].m_triangle;
    v8 = m_triangle->m_links[m_index];
    if ( (v8 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
      goto LABEL_26;
    v9 = m_triangle->m_vertices[m_index];
    v10 = 2 * m_index;
    v11 = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
    m_x = v9->m_x;
    v13 = v11->m_x;
    if ( m_x < v13 || m_x <= v13 && v9->m_y <= v11->m_y )
    {
      v14 = (unsigned __int64)m_data[v5].m_triangle;
    }
    else
    {
      m_index = m_triangle->m_links[m_index] & 3;
      v14 = v8 & 0xFFFFFFFFFFFFFFFCui64;
    }
    if ( ((unsigned __int8)(1 << m_index) & (unsigned __int8)*(_WORD *)(v14 + 100) & 7) != 0 )
      goto LABEL_26;
    v15 = *(_QWORD *)((v8 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((18i64 >> (2 * ((unsigned __int8)v8 & 3u))) & 3) + 16);
    v16 = *(_DWORD *)(v15 + 20);
    v17 = m_triangle->m_vertices[(18i64 >> v10) & 3];
    v18 = *(_DWORD *)(v15 + 16);
    m_y = v9->m_y;
    v20 = v9->m_x - v18;
    v21 = v11->m_x - v18;
    v22 = v17->m_y - v16;
    v23 = m_y - v16;
    v24 = v11->m_y - v16;
    if ( (v24 * v24 + v21 * v21) * (__int64)(v23 * (v17->m_x - v18) - v20 * v22)
       + (v21 * v22 - v24 * (v17->m_x - v18)) * (__int64)(v23 * v23 + v20 * v20)
       + (v24 * v20 - v21 * v23) * (__int64)(v22 * v22 + (v17->m_x - v18) * (v17->m_x - v18)) <= 0 )
    {
LABEL_26:
      this->m_stack.m_size = v5;
      --m_size;
    }
    else
    {
      --m_size;
      v25 = *(_QWORD *)&m_data[v4 - 1].m_index;
      v26 = m_data[v4 - 1].m_triangle;
      this->m_stack.m_size = v5;
      edgeArg.m_triangle = v26;
      *(_QWORD *)&edgeArg.m_index = v25;
      v27 = v26->m_links[(int)v25];
      if ( (v27 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v28 = v26->m_vertices[(int)v25];
        v29 = 2 * v25;
        v30 = v26->m_vertices[(9i64 >> (2 * (unsigned __int8)v25)) & 3];
        v31 = v28->m_x;
        v32 = v30->m_x;
        if ( v31 < v32 || v31 <= v32 && v28->m_y <= v30->m_y )
        {
          v33 = (unsigned __int64)v26;
        }
        else
        {
          v25 = v26->m_links[(int)v25] & 3;
          v33 = v27 & 0xFFFFFFFFFFFFFFFCui64;
        }
        if ( ((unsigned __int8)(1 << v25) & (unsigned __int8)*(_WORD *)(v33 + 100) & 7) == 0 )
        {
          v34 = v27 & 3;
          v35 = v27 & 0xFFFFFFFFFFFFFFFCui64;
          v36 = *(_QWORD *)(v35 + 8i64 * ((18 >> (2 * v34)) & 3) + 16);
          v37 = v26->m_vertices[(18 >> v29) & 3];
          v38 = v37->m_y;
          v39 = v37->m_x;
          if ( (v28->m_x - v39) * (*(_DWORD *)(v36 + 20) - v38) - (v28->m_y - v38) * (*(_DWORD *)(v36 + 16) - v39) > 0 )
          {
            v40 = *(_QWORD *)(v35 + 8i64 * v34 + 16);
            if ( (*(_DWORD *)(v40 + 16) - *(_DWORD *)(v36 + 16)) * (v38 - *(_DWORD *)(v36 + 20))
               - (*(_DWORD *)(v40 + 20) - *(_DWORD *)(v36 + 20)) * (v39 - *(_DWORD *)(v36 + 16)) > 0 )
            {
              hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>::flipEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>(
                &this->m_edgeDataPolicy,
                (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *)&result,
                &edgeArg);
              v41 = this->m_stack.m_size + 2;
              v42 = this->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v42 >= v41 )
              {
                v56.m_enum = HK_SUCCESS;
              }
              else
              {
                v43 = 2 * v42;
                if ( v41 < v43 )
                  v41 = v43;
                hkArrayUtil::_reserve(
                  &v56,
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&this->m_stack.m_data,
                  v41,
                  16);
                if ( v56.m_enum == HK_FAILURE )
                {
                  this->m_status.m_storage = 1;
                  return;
                }
              }
              v44 = *(int *)&result.m_memSizeAndFlags;
              vfptr = result.vfptr;
              v46 = this->m_stack.m_size;
              v47 = 2 * LOBYTE(result.m_memSizeAndFlags);
              this->m_stack.m_size += 2;
              v48 = &this->m_stack.m_data[v46];
              m_size += 2;
              v48->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)vfptr;
              v48->m_index = (9 >> v47) & 3;
              v49 = *((_QWORD *)&vfptr[2].__first_virtual_table_function__ + v44);
              v48[1].m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)(v49 & 0xFFFFFFFFFFFFFFFCui64);
              v48[1].m_index = (18 >> (2 * (v49 & 3))) & 3;
            }
          }
        }
      }
    }
    v50 = v55;
    if ( m_size <= 0 )
      break;
    v50 = v55 - 1;
    v55 = v50;
  }
  while ( v50 );
  if ( !v50 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&result, buf, 512);
    hkOstream::operator<<(&result, "Infinite cycle detected during triangulation");
    hkError::messageWarning(
      0xD26E67Eu,
      buf,
      "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
      2284);
    hkOstream::~hkOstream(&result);
  }
}

// File Line: 2296
// RVA: 0xB66CD0
void __fastcall hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::backupBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge>(
        hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge,
        hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *state)
{
  int v7; // edi
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *v8; // rsi
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *EdgeData; // rax
  __int64 m_index; // rcx
  unsigned __int64 v11; // rdx
  char v12; // al
  __int64 v13; // [rsp+28h] [rbp-10h]

  state->m_values[0].m_hasData = 0;
  state->m_values[1].m_hasData = 0;
  v7 = 0;
  v8 = state;
  do
  {
    EdgeData = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                 triangulator,
                 edge);
    if ( EdgeData )
    {
      hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
        (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)((char *)&state->m_values[0].m_data
                                                                          + 32 * v7
                                                                          + 8 * v7),
        EdgeData);
      v8->m_values[0].m_hasData = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::clearEdgeData(
        triangulator,
        edge);
    }
    m_index = (int)edge->m_index;
    v11 = edge->m_triangle->m_links[m_index];
    if ( (v11 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
      break;
    v12 = edge->m_triangle->m_links[m_index];
    ++v7;
    v8 = (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *)((char *)v8 + 40);
    edge->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v11 & 0xFFFFFFFFFFFFFFFCui64);
    LODWORD(v13) = v12 & 3;
    *(_QWORD *)&edge->m_index = v13;
  }
  while ( v7 < 2 );
}

// File Line: 2316
// RVA: 0xCD6E40
void __fastcall hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
        hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *triangulator,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *edge,
        hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *state)
{
  int v7; // esi
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *v8; // rdi
  __int64 m_index; // rcx
  unsigned __int64 v10; // rdx
  char v11; // al
  __int64 v12; // [rsp+28h] [rbp-10h]

  v7 = 0;
  v8 = state;
  do
  {
    if ( v8->m_values[0].m_hasData )
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setEdgeData(
        triangulator,
        edge,
        (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)((char *)&state->m_values[0].m_data
                                                                          + 32 * v7
                                                                          + 8 * v7));
    m_index = (int)edge->m_index;
    v10 = edge->m_triangle->m_links[m_index];
    if ( (v10 & 0xFFFFFFFFFFFFFFFCui64) == 0 )
      break;
    v11 = edge->m_triangle->m_links[m_index];
    ++v7;
    v8 = (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *)((char *)v8 + 40);
    edge->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v10 & 0xFFFFFFFFFFFFFFFCui64);
    LODWORD(v12) = v11 & 3;
    *(_QWORD *)&edge->m_index = v12;
  }
  while ( v7 < 2 );
}

// File Line: 2331
// RVA: 0xCD7C40
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::~SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>(
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this)
{
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *m_edgeData; // rcx

  m_edgeData = this->m_edgeData;
  if ( m_edgeData )
  {
    hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator>::`scalar deleting destructor(
      m_edgeData,
      0);
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, this->m_edgeData, 24);
    this->m_edgeData = 0i64;
  }
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&this->m_edgeDataAllocator);
}

// File Line: 2345
// RVA: 0xCD9190
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::createEdgeDataHashTable(
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this)
{
  __int64 v2; // rax
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v3; // rsi
  int v4; // ecx
  __int64 v5; // rbp
  int *v6; // rdi
  int v7; // r8d
  int v8; // r9d
  int v9; // eax
  __int64 v10; // rbp
  int *v11; // rdi
  int v12; // r8d
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 i; // rcx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v2 = (*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, __int64))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor
        + 1))(
         &hkContainerHeapAllocator::s_alloc,
         24i64);
  v3 = (hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = 0i64;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 12) = 0x80000000;
    *(_DWORD *)(v2 + 16) = 0;
    v4 = *(_DWORD *)(v2 + 8) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = (int *)(16i64 * v4 + *(_QWORD *)v2 + 12i64);
      do
      {
        v7 = *v6;
        *(v6 - 1) = 0;
        if ( v7 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v6 - 3),
            32 * v7);
        *(_QWORD *)(v6 - 3) = 0i64;
        *v6 = 0x80000000;
        v6 -= 4;
        --v5;
      }
      while ( v5 >= 0 );
    }
    v3->m_buckets.m_size = 0;
    v3->m_numItems = 0;
    if ( (v3->m_buckets.m_capacityAndFlags & 0x3FFFFFFFu) >= 0x407 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v8 = 1031;
      if ( 2 * (v3->m_buckets.m_capacityAndFlags & 0x3FFFFFFF) > 1031 )
        v8 = 2 * (v3->m_buckets.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v3->m_buckets.m_data, v8, 16);
    }
    v9 = v3->m_buckets.m_size - 1032;
    v10 = v9;
    if ( v9 >= 0 )
    {
      v11 = &v3->m_buckets.m_data[1031].m_capacityAndFlags + 4 * v9;
      do
      {
        v12 = *v11;
        *(v11 - 1) = 0;
        if ( v12 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v11 - 3),
            32 * v12);
        *(_QWORD *)(v11 - 3) = 0i64;
        *v11 = 0x80000000;
        v11 -= 4;
        --v10;
      }
      while ( v10 >= 0 );
    }
    v13 = (__int64)&v3->m_buckets.m_data[v3->m_buckets.m_size];
    v14 = 1031 - v3->m_buckets.m_size;
    if ( 1031 - v3->m_buckets.m_size > 0 )
    {
      do
      {
        if ( v13 )
        {
          *(_QWORD *)v13 = 0i64;
          *(_DWORD *)(v13 + 8) = 0;
          *(_DWORD *)(v13 + 12) = 0x80000000;
        }
        v13 += 16i64;
        --v14;
      }
      while ( v14 );
    }
    v3->m_buckets.m_size = 1031;
    for ( i = 0i64; i < 1031; v3->m_buckets.m_data[i - 1].m_size = 0 )
      ++i;
    this->m_edgeData = v3;
  }
  else
  {
    this->m_edgeData = 0i64;
  }
}

// File Line: 2355
// RVA: 0xCD6780
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *__fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::getEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        __m128i *edge)
{
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *m_edgeData; // r11
  __int64 v3; // rbx
  int v4; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v5; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v6; // r9
  __int64 v7; // rcx
  int v8; // edx
  __int64 v9; // rax
  __int64 v10; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v11; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **i; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v14; // rax

  if ( !edge->m128i_i64[0] )
    return 0i64;
  m_edgeData = this->m_edgeData;
  if ( !this->m_edgeData )
    return 0i64;
  v3 = 0i64;
  v4 = _mm_cvtsi128_si32(_mm_srli_si128(*edge, 8));
  v5 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(edge->m128i_i64[0] + 8i64 * v4 + 16);
  v6 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(edge->m128i_i64[0] + 8 * ((9i64 >> (2 * (unsigned __int8)v4)) & 3) + 16);
  v7 = 0i64;
  v8 = 0;
  v9 = (__int64)&m_edgeData->m_buckets.m_data[(int)(((unsigned int)(3424933 * (v5->m_y + (v5->m_x << 15))) ^ (unsigned __int64)(unsigned int)(1661161 * (v6->m_y + (v6->m_x << 15))))
                                                  % (unsigned int)m_edgeData->m_buckets.m_size)];
  v10 = *(int *)(v9 + 8);
  if ( v10 > 0 )
  {
    v11 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex ***)v9;
    for ( i = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex ***)v9;
          *i != v5 || i[1] != v6;
          i += 4 )
    {
      ++v7;
      ++v8;
      if ( v7 >= v10 )
        return 0i64;
    }
    if ( v8 != -1 )
    {
      v14 = &v11[4 * v8];
      if ( v14 )
        return v14[3];
    }
  }
  return (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v3;
}

// File Line: 2369
// RVA: 0xCD6EF0
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::setEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        __m128i *edge,
        hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *data)
{
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *m_edgeData; // r9
  int v7; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v8; // rbp
  __int64 v9; // rax
  __int64 v10; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v11; // rsi
  __int64 v12; // r12
  int v13; // edx
  hkArray<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v14; // r10
  __int64 m_size; // r8
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox *m_data; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v17; // rax
  __int64 v18; // rbx
  signed int v19; // edx
  __int64 v20; // rdi
  _QWORD *v21; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v22; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Item *m_free; // rdx
  __int64 v25; // rbx
  int v26; // esi
  __int64 v27; // rdi
  __int64 v28; // r10
  int v29; // edx
  __int64 v30; // rcx
  _QWORD *v31; // rax
  unsigned __int64 *v32; // r15

  if ( !this->m_edgeData )
    hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::createEdgeDataHashTable(this);
  m_edgeData = this->m_edgeData;
  v7 = _mm_cvtsi128_si32(_mm_srli_si128(*edge, 8));
  v8 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(edge->m128i_i64[0] + 8i64 * v7 + 16);
  v9 = 9i64 >> (2 * (unsigned __int8)v7);
  v10 = 0i64;
  v11 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(edge->m128i_i64[0] + 8 * (v9 & 3) + 16);
  v12 = (3424933i64 * (v8->m_y + (v8->m_x << 15))) ^ (1661161i64 * (v11->m_y + (v11->m_x << 15)));
  v13 = 0;
  v14 = &this->m_edgeData->m_buckets.m_data[(int)(((unsigned int)(3424933 * (v8->m_y + (v8->m_x << 15))) ^ (unsigned __int64)(unsigned int)(1661161 * (v11->m_y + (v11->m_x << 15))))
                                                % (unsigned int)this->m_edgeData->m_buckets.m_size)];
  m_size = v14->m_size;
  if ( m_size <= 0 )
    goto LABEL_8;
  m_data = v14->m_data;
  v17 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)m_data;
  while ( *v17 != v8 || v17[1] != v11 )
  {
    ++v10;
    ++v13;
    v17 += 4;
    if ( v10 >= m_size )
      goto LABEL_8;
  }
  if ( v13 == -1 )
LABEL_8:
    v18 = 0i64;
  else
    v18 = (__int64)&m_data[v13];
  if ( !v18 )
  {
    ++m_edgeData->m_numItems;
    v19 = (unsigned int)v12 % m_edgeData->m_buckets.m_size;
    v20 = (__int64)&m_edgeData->m_buckets.m_data[v19];
    if ( *(_DWORD *)(v20 + 8) == (*(_DWORD *)(v20 + 12) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_edgeData->m_buckets.m_data[v19].m_data,
        32);
    v21 = (_QWORD *)(*(_QWORD *)v20 + 32i64 * *(int *)(v20 + 8));
    if ( v21 )
    {
      v21[3] = 0i64;
      v21[1] = 0i64;
      *v21 = 0i64;
    }
    v22 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(*(_QWORD *)v20 + 32i64 * (int)(*(_DWORD *)(v20 + 8))++);
    *v22 = v8;
    v22[1] = v11;
    v22[2] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v12;
    v22[3] = 0i64;
    m_firstPool = this->m_edgeDataAllocator.m_firstPool;
    v18 = *(_QWORD *)v20 + 32i64 * (*(_DWORD *)(v20 + 8) - 1);
    if ( !m_firstPool || !m_firstPool->m_free )
      m_firstPool = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *)hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&this->m_edgeDataAllocator);
    if ( m_firstPool )
    {
      m_free = m_firstPool->m_free;
      m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
      m_free->m_pool = m_firstPool;
      ++m_firstPool->m_used;
      *(_DWORD *)&m_free->m_data[8] = 0;
      *(_DWORD *)&m_free->m_data[12] = -2147483646;
      *(_QWORD *)m_free->m_data = &m_free->m_data[16];
    }
    else
    {
      m_free = 0i64;
    }
    *(_QWORD *)(v18 + 24) = m_free;
  }
  v25 = *(_QWORD *)(v18 + 24);
  v26 = 0;
  if ( data->m_tags.m_size > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = *(int *)(v25 + 8);
      v29 = 0;
      v30 = 0i64;
      if ( (int)v28 <= 0 )
        goto LABEL_31;
      v31 = *(_QWORD **)v25;
      while ( *v31 != data->m_tags.m_data[v27] )
      {
        ++v30;
        ++v29;
        ++v31;
        if ( v30 >= v28 )
          goto LABEL_31;
      }
      if ( v29 == -1 )
      {
LABEL_31:
        v32 = data->m_tags.m_data;
        if ( (_DWORD)v28 == (*(_DWORD *)(v25 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v25, 8);
        *(_QWORD *)(*(_QWORD *)v25 + 8i64 * (int)(*(_DWORD *)(v25 + 8))++) = v32[v27];
      }
      ++v26;
      ++v27;
    }
    while ( v26 < data->m_tags.m_size );
  }
}

// File Line: 2387
// RVA: 0xCD6440
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::clearEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        __m128i *edge)
{
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *m_edgeData; // r8
  int v4; // ebx
  int v5; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v6; // rsi
  __int64 v7; // rax
  __int64 v8; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v9; // rdi
  unsigned int v10; // ebp
  int v11; // edx
  __int64 v12; // r9
  __int64 v13; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v14; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **i; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v16; // rdx
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v17; // rcx
  int v18; // edx
  __int64 v19; // r9
  __int64 v20; // rcx
  __int64 v21; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v22; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **j; // rax
  __int64 v24; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v25; // rax
  __int64 v26; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **v27; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v28; // rcx

  m_edgeData = this->m_edgeData;
  if ( this->m_edgeData )
  {
    v4 = 0;
    v5 = _mm_cvtsi128_si32(_mm_srli_si128(*edge, 8));
    v6 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(edge->m128i_i64[0] + 8i64 * v5 + 16);
    v7 = 9i64 >> (2 * (unsigned __int8)v5);
    v8 = 0i64;
    v9 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(edge->m128i_i64[0] + 8 * (v7 & 3) + 16);
    v10 = (3424933 * (v6->m_y + (v6->m_x << 15))) ^ (1661161 * (v9->m_y + (v9->m_x << 15)));
    v11 = 0;
    v12 = (__int64)&m_edgeData->m_buckets.m_data[(int)(((unsigned int)(3424933 * (v6->m_y + (v6->m_x << 15))) ^ (unsigned __int64)(unsigned int)(1661161 * (v9->m_y + (v9->m_x << 15))))
                                                     % (unsigned int)m_edgeData->m_buckets.m_size)];
    v13 = *(int *)(v12 + 8);
    if ( v13 > 0 )
    {
      v14 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex ***)v12;
      for ( i = v14; *i != v6 || i[1] != v9; i += 4 )
      {
        ++v8;
        ++v11;
        if ( v8 >= v13 )
          return;
      }
      if ( v11 != -1 )
      {
        v16 = &v14[4 * v11];
        if ( v16 )
        {
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::release(
            &this->m_edgeDataAllocator,
            (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)v16[3]);
          v17 = this->m_edgeData;
          --v17->m_numItems;
          v18 = 0;
          v19 = (__int64)&v17->m_buckets.m_data[v10 % v17->m_buckets.m_size];
          v20 = 0i64;
          v21 = *(int *)(v19 + 8);
          if ( (int)v21 > 0 )
          {
            v22 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex ***)v19;
            for ( j = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex ***)v19;
                  *j != v6 || j[1] != v9;
                  j += 4 )
            {
              ++v20;
              ++v18;
              if ( v20 >= v21 )
                return;
            }
            if ( v18 >= 0 )
            {
              v24 = 0i64;
              v25 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex ***)v19;
              while ( *v25 != v6 || v25[1] != v9 )
              {
                ++v24;
                ++v4;
                v25 += 4;
                if ( v24 >= v21 )
                {
                  v4 = -1;
                  break;
                }
              }
              *(_DWORD *)(v19 + 8) = v21 - 1;
              if ( (_DWORD)v21 - 1 != v4 )
              {
                v26 = 4i64;
                v27 = &v22[4 * v4];
                do
                {
                  v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)((char *)v27++ + 32i64 * ((int)v21 - 1) - 32i64 * v4);
                  *(v27 - 1) = v28;
                  --v26;
                }
                while ( v26 );
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 2418
// RVA: 0xB68860
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::setEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge>(
        hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge,
        hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *data)
{
  char *v4; // rbx
  int v5; // ebp
  __int64 v6; // rsi
  __int64 v7; // r10
  int v8; // edx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  unsigned __int64 *m_data; // rdi
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> __that; // [rsp+20h] [rbp-28h] BYREF

  v4 = (char *)edge->m_triangle + 40 * (int)edge->m_index;
  if ( !v4[64] )
  {
    __that.m_tags.m_size = 0;
    __that.m_tags.m_capacityAndFlags = -2147483646;
    __that.m_tags.m_data = __that.m_tags.m_storage;
    hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
      (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v4 + 72),
      &__that);
    __that.m_tags.m_size = 0;
    if ( __that.m_tags.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        __that.m_tags.m_data,
        8 * __that.m_tags.m_capacityAndFlags);
    v4[64] = 1;
  }
  v5 = 0;
  if ( data->m_tags.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = *((int *)v4 + 20);
      v8 = 0;
      v9 = 0i64;
      if ( (int)v7 <= 0 )
        goto LABEL_13;
      v10 = (_QWORD *)*((_QWORD *)v4 + 9);
      while ( *v10 != data->m_tags.m_data[v6] )
      {
        ++v9;
        ++v8;
        ++v10;
        if ( v9 >= v7 )
          goto LABEL_13;
      }
      if ( v8 == -1 )
      {
LABEL_13:
        m_data = data->m_tags.m_data;
        if ( (_DWORD)v7 == (*((_DWORD *)v4 + 21) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v4 + 72, 8);
        *(_QWORD *)(*((_QWORD *)v4 + 9) + 8i64 * (int)(*((_DWORD *)v4 + 20))++) = m_data[v6];
      }
      ++v5;
      ++v6;
    }
    while ( v5 < data->m_tags.m_size );
  }
}

// File Line: 2440
// RVA: 0x12EB640
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *__fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>::flipEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>(
        hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *result,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *edgeArg)
{
  __int64 v3; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *m_triangle; // r10
  __int64 v5; // r12
  unsigned __int64 v6; // r9
  int v7; // edi
  char v8; // cl
  __int64 v9; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v10; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v11; // rdx
  int m_x; // eax
  int v13; // ecx
  unsigned __int64 v14; // r9
  char v15; // cl
  unsigned __int64 v16; // r9
  __int16 v17; // dx
  int v18; // ebx
  unsigned __int64 v19; // rdx
  __int64 v20; // rsi
  __int64 v21; // r11
  int v22; // eax
  int v23; // ecx
  __int64 v24; // r11
  unsigned __int64 v25; // r11
  __int16 v26; // dx
  int v27; // esi
  unsigned __int64 v28; // r9
  __int64 v29; // r14
  int v30; // ebp
  unsigned __int64 v31; // r11
  int v32; // r12d
  unsigned __int64 v33; // rdx
  int v34; // r11d
  unsigned __int64 v35; // rdx
  __int64 v36; // r9
  __int64 v37; // rbx
  __int64 v38; // r11
  int v39; // eax
  int v40; // ecx
  __int64 v41; // r11
  unsigned __int64 v42; // r11
  __int64 v43; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v44; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v45; // r9
  int v46; // eax
  int v47; // ecx
  unsigned __int64 v48; // r9
  unsigned __int64 v49; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v50; // r9
  __int64 v51; // rdx
  __int64 v52; // rcx
  _DWORD *v53; // rcx
  int v54; // eax
  unsigned __int64 v55; // r9
  char v56; // r8
  int v57; // r8d
  __int64 v58; // rdx
  __int64 v59; // rcx
  __int64 v60; // rcx
  int v62; // [rsp+0h] [rbp-88h]
  unsigned int v63; // [rsp+4h] [rbp-84h]
  int v64; // [rsp+8h] [rbp-80h]
  int v65; // [rsp+Ch] [rbp-7Ch]
  unsigned int m_sets; // [rsp+10h] [rbp-78h]
  int v67; // [rsp+14h] [rbp-74h]
  unsigned int v68; // [rsp+18h] [rbp-70h]
  int v69; // [rsp+1Ch] [rbp-6Ch]
  int v70; // [rsp+20h] [rbp-68h]
  unsigned __int64 *v71; // [rsp+28h] [rbp-60h]
  __int64 v72; // [rsp+30h] [rbp-58h]
  int m_tag; // [rsp+38h] [rbp-50h]
  __int64 v74; // [rsp+40h] [rbp-48h]
  int v76; // [rsp+A0h] [rbp+18h]
  int v77; // [rsp+A8h] [rbp+20h]

  result->m_triangle = edgeArg->m_triangle;
  v3 = *(_QWORD *)&edgeArg->m_index;
  *(_QWORD *)&result->m_index = v3;
  m_triangle = result->m_triangle;
  v5 = (int)v3;
  v74 = (int)v3;
  v6 = result->m_triangle->m_links[(int)v3] & 0xFFFFFFFFFFFFFFFCui64;
  v7 = (18 >> (2 * v3)) & 3;
  v64 = *(_DWORD *)&result->m_triangle->m_edgeData[(9 >> (2 * v3)) & 3].m_hasData;
  m_tag = result->m_triangle->m_edgeData[(9 >> (2 * v3)) & 3].m_data.m_tag;
  m_sets = result->m_triangle->m_edgeData[(9 >> (2 * v3)) & 3].m_data.m_sets;
  v70 = *(_DWORD *)&result->m_triangle->m_edgeData[v7].m_hasData;
  v62 = result->m_triangle->m_edgeData[v7].m_data.m_tag;
  v8 = 2 * (result->m_triangle->m_links[(int)v3] & 3);
  v63 = result->m_triangle->m_edgeData[v7].m_data.m_sets;
  v65 = *(_DWORD *)(v6 + 12i64 * ((9 >> v8) & 3) + 64);
  v67 = *(_DWORD *)(v6 + 12i64 * ((9 >> v8) & 3) + 68);
  v69 = *(_DWORD *)(v6 + 12i64 * ((9 >> v8) & 3) + 72);
  v9 = 3i64 * ((18 >> v8) & 3);
  v76 = *(_DWORD *)(v6 + 4 * v9 + 64);
  v77 = *(_DWORD *)(v6 + 4 * v9 + 68);
  v68 = *(_DWORD *)(v6 + 4 * v9 + 72);
  v10 = result->m_triangle->m_vertices[v7];
  v11 = result->m_triangle->m_vertices[(9i64 >> (2 * ((18 >> (2 * v3)) & 3u))) & 3];
  m_x = v10->m_x;
  v13 = v11->m_x;
  if ( m_x >= v13
    && (m_x > v13 || v10->m_y > v11->m_y)
    && (v14 = m_triangle->m_links[v7], (v14 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
  {
    v15 = v14 & 3;
    v16 = v14 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v16 = (unsigned __int64)m_triangle;
    v15 = v7;
  }
  v17 = *(_WORD *)(v16 + 100);
  v18 = (unsigned __int8)v17 & (1 << v15) & 7;
  *(_WORD *)(v16 + 100) = v17 & (~((unsigned __int8)v17 & (1 << v15) & 7) | 0xFFF8);
  v19 = m_triangle->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  LODWORD(v16) = (18 >> (2 * (m_triangle->m_links[v5] & 3))) & 3;
  v20 = *(_QWORD *)(v19 + 8i64 * (int)v16 + 16);
  v21 = *(_QWORD *)(v19 + 8 * ((9i64 >> (2 * ((18 >> (2 * (m_triangle->m_links[v5] & 3))) & 3u))) & 3) + 16);
  v22 = *(_DWORD *)(v20 + 16);
  v23 = *(_DWORD *)(v21 + 16);
  if ( v22 >= v23
    && (v22 > v23 || *(_DWORD *)(v20 + 20) > *(_DWORD *)(v21 + 20))
    && (v24 = *(_QWORD *)(v19 + 8i64 * (int)v16 + 40), (v24 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
  {
    v16 = *(_QWORD *)(v19 + 8i64 * (int)v16 + 40) & 3i64;
    v25 = v24 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v25 = m_triangle->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  }
  v26 = *(_WORD *)(v25 + 100);
  v27 = (unsigned __int8)v26 & (1 << v16) & 7;
  *(_WORD *)(v25 + 100) = v26 & (~((unsigned __int8)v26 & (1 << v16) & 7) | 0xFFF8);
  v28 = m_triangle->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  v29 = m_triangle->m_links[v5] & 3;
  v30 = (18 >> (2 * v29)) & 3;
  m_triangle->m_vertices[v5] = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex **)(v28 + 8i64 * v30 + 16);
  *(_QWORD *)(v28 + 8i64 * (int)v29 + 16) = m_triangle->m_vertices[v7];
  v71 = &m_triangle->m_links[v7];
  v31 = *v71 & 0xFFFFFFFFFFFFFFFCui64;
  v32 = *(_DWORD *)v71 & 3;
  *(_QWORD *)(v28 + 8i64 * (int)v29 + 40) = *v71;
  if ( v31 )
    *(_QWORD *)(v31 + 8i64 * v32 + 40) = v28 + (unsigned int)v29;
  v33 = *(_QWORD *)(v28 + 8i64 * v30 + 40) & 0xFFFFFFFFFFFFFFFCui64;
  v34 = *(_DWORD *)(v28 + 8i64 * v30 + 40) & 3;
  m_triangle->m_links[v74] = *(_QWORD *)(v28 + 8i64 * v30 + 40);
  if ( v33 )
    *(_QWORD *)(v33 + 8i64 * v34 + 40) = (char *)m_triangle + result->m_index;
  *v71 = v28 + (unsigned int)v30;
  if ( v28 )
    *(_QWORD *)(v28 + 8i64 * v30 + 40) = (char *)m_triangle + (unsigned int)v7;
  LODWORD(v72) = v7;
  if ( v18 )
  {
    v35 = m_triangle->m_links[v7] & 0xFFFFFFFFFFFFFFFCui64;
    LODWORD(v36) = (9 >> (2 * (m_triangle->m_links[v7] & 3))) & 3;
    v37 = *(_QWORD *)(v35 + 8i64 * (int)v36 + 16);
    v38 = *(_QWORD *)(v35 + 8 * ((9i64 >> (2 * ((9 >> (2 * (m_triangle->m_links[v7] & 3))) & 3u))) & 3) + 16);
    v39 = *(_DWORD *)(v37 + 16);
    v40 = *(_DWORD *)(v38 + 16);
    if ( v39 >= v40
      && (v39 > v40 || *(_DWORD *)(v37 + 20) > *(_DWORD *)(v38 + 20))
      && (v41 = *(_QWORD *)(v35 + 8i64 * (int)v36 + 40), (v41 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
    {
      v36 = *(_QWORD *)(v35 + 8i64 * (int)v36 + 40) & 3i64;
      v42 = v41 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v42 = m_triangle->m_links[v7] & 0xFFFFFFFFFFFFFFFCui64;
    }
    *(_WORD *)(v42 + 100) ^= ((unsigned __int8)*(_WORD *)(v42 + 100) ^ (unsigned __int8)(*(_WORD *)(v42 + 100) | (1 << v36))) & 7;
  }
  if ( v27 )
  {
    LODWORD(v43) = (9 >> (2 * v7)) & 3;
    v44 = m_triangle->m_vertices[(int)v43];
    v45 = m_triangle->m_vertices[(9i64 >> (2 * ((9 >> (2 * v7)) & 3u))) & 3];
    v46 = v44->m_x;
    v47 = v45->m_x;
    if ( v46 >= v47
      && (v46 > v47 || v44->m_y > v45->m_y)
      && (v48 = m_triangle->m_links[(int)v43], (v48 & 0xFFFFFFFFFFFFFFFCui64) != 0) )
    {
      v43 = m_triangle->m_links[(int)v43] & 3;
      v49 = v48 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v49 = (unsigned __int64)m_triangle;
    }
    *(_WORD *)(v49 + 100) ^= ((unsigned __int8)*(_WORD *)(v49 + 100) ^ (unsigned __int8)(*(_WORD *)(v49 + 100) | (1 << v43))) & 7;
  }
  result->m_triangle = m_triangle;
  *(_QWORD *)&result->m_index = v72;
  v50 = result->m_triangle;
  LOBYTE(v71) = 0;
  v51 = (9 >> (2 * v7)) & 3;
  *(_DWORD *)&v50->m_edgeData[v51].m_hasData = v76;
  v50->m_edgeData[v51].m_data.m_tag = v77;
  v50->m_edgeData[v51].m_data.m_sets = v68;
  v52 = (18 >> (2 * v7)) & 3;
  *(_DWORD *)&v50->m_edgeData[v52].m_hasData = v64;
  v50->m_edgeData[v52].m_data.m_tag = m_tag;
  v50->m_edgeData[v52].m_data.m_sets = m_sets;
  v53 = (_DWORD *)((char *)v50 + 12 * v7);
  v54 = (int)v71;
  LOBYTE(v71) = 0;
  v53[16] = v54;
  v53[17] = -842150451;
  v53[18] = 0;
  v55 = v50->m_links[v7];
  v56 = v55;
  v55 &= 0xFFFFFFFFFFFFFFFCui64;
  v57 = v56 & 3;
  v58 = 3i64 * ((9 >> (2 * v57)) & 3);
  *(_DWORD *)(v55 + 4 * v58 + 64) = v70;
  *(_DWORD *)(v55 + 4 * v58 + 68) = v62;
  *(_DWORD *)(v55 + 4 * v58 + 72) = v63;
  v59 = 3i64 * ((18 >> (2 * v57)) & 3);
  *(_DWORD *)(v55 + 4 * v59 + 64) = v65;
  *(_DWORD *)(v55 + 4 * v59 + 68) = v67;
  *(_DWORD *)(v55 + 4 * v59 + 72) = v69;
  v60 = 3i64 * v57;
  *(_DWORD *)(v55 + 4 * v60 + 64) = (_DWORD)v71;
  *(_DWORD *)(v55 + 4 * v60 + 68) = -842150451;
  *(_DWORD *)(v55 + 4 * v60 + 72) = 0;
  return result;
}

// File Line: 2463
// RVA: 0xB68340
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::propagateDataOnSplitTriangle<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle>(
        hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t0,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t1)
{
  char v5; // cl
  char *v6; // rdi
  char *v7; // rbx

  v5 = 2 * edge->m_index;
  v6 = (char *)edge->m_triangle + 40 * ((9 >> v5) & 3);
  v7 = (char *)edge->m_triangle + 40 * ((18 >> v5) & 3);
  t0->m_edgeData[0].m_hasData = v6[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t0->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v6 + 72));
  t1->m_edgeData[0].m_hasData = v7[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t1->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v7 + 72));
  v6[64] = 0;
  v7[64] = 0;
}

// File Line: 2476
// RVA: 0xB68260
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::propagateDataOnSplitBoundEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle>(
        hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *link,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t0,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t1)
{
  char *v5; // rdi
  char *v6; // rbx

  v5 = (char *)edge->m_triangle + 40 * ((18 >> (2 * edge->m_index)) & 3);
  v6 = (char *)link->m_triangle + 40 * ((18 >> (2 * link->m_index)) & 3);
  t0->m_edgeData[0].m_hasData = v5[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t0->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v5 + 72));
  v5[64] = 0;
  t1->m_edgeData[0].m_hasData = v6[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t1->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v6 + 72));
  v6[64] = 0;
}

// File Line: 2489
// RVA: 0xB682F0
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::propagateDataOnSplitNakedEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle>(
        hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge,
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t0)
{
  char *v3; // rbx

  v3 = (char *)edge->m_triangle + 40 * ((18 >> (2 * edge->m_index)) & 3);
  t0->m_edgeData[0].m_hasData = v3[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t0->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v3 + 72));
  v3[64] = 0;
}

