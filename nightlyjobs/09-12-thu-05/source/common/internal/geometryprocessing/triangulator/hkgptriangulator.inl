// File Line: 309
// RVA: 0xCDC050
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeDataOrientation(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v1; // r14
  unsigned int v2; // er15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v3; // rbp
  int v4; // edi
  int v5; // esi
  signed int v6; // ebx
  unsigned __int64 v7; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge edge; // [rsp+20h] [rbp-38h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v10; // [rsp+30h] [rbp-28h]

  v1 = this->m_mesh.m_triangles.m_used;
  v2 = 0;
  v3 = this;
  v4 = 0;
  v5 = 0;
  if ( v1 )
  {
    while ( !(*((_BYTE *)v1 + 66) & 0x20) )
    {
LABEL_10:
      v1 = v1->m_next;
      if ( !v1 )
        goto LABEL_11;
    }
    v6 = 0;
    while ( 1 )
    {
      edge.m_triangle = v1;
      edge.m_index = v6;
      v7 = v1->m_links[v6];
      if ( !(v7 & 0xFFFFFFFFFFFFFFFCui64) )
        break;
      v10.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v7 & 0xFFFFFFFFFFFFFFFCui64);
      v10.m_index = v7 & 3;
      if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
             v3,
             &edge) )
      {
        ++v4;
      }
      else if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
                  v3,
                  &v10) )
      {
        goto LABEL_8;
      }
LABEL_9:
      if ( ++v6 >= 3 )
        goto LABEL_10;
    }
    if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::getEdgeData(
           v3,
           &edge) )
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
hkaiNavMeshGenTriangulatorEdgeData *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v2; // rcx
  __int64 v3; // rax
  hkaiNavMeshGenTriangulatorEdgeData *result; // rax

  v2 = edge->m_triangle;
  v3 = (signed int)edge->m_index;
  if ( edge->m_triangle && v2->m_edgeData[v3].m_hasData )
    result = &v2->m_edgeData[v3].m_data;
  else
    result = 0i64;
  return result;
}

// File Line: 361
// RVA: 0xB8B8E0
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setEdgeData(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge, hkaiNavMeshGenTriangulatorEdgeData *data)
{
  __int64 v3; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v4; // rax

  v3 = (signed int)edge->m_index;
  v4 = edge->m_triangle;
  if ( !edge->m_triangle->m_edgeData[v3].m_hasData )
  {
    v4->m_edgeData[v3].m_data.m_counter = 0;
    v4->m_edgeData[v3].m_hasData = 1;
  }
  ++v4->m_edgeData[v3].m_data.m_counter;
}

// File Line: 377
// RVA: 0xCD8B10
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::clearEdgeData(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *edge)
{
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::clearEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
    &this->m_edgeDataPolicy,
    edge);
}

// File Line: 392
// RVA: 0xB69050
signed __int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::canSplitEdge(int ix, int iy, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v3; // rbx
  __int64 v4; // r11
  int v5; // er14
  char v6; // r15
  int v7; // er8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v8; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v9; // rcx
  signed __int64 result; // rax
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

  v3 = edge->m_triangle;
  v4 = (signed int)edge->m_index;
  v5 = ix;
  v6 = 2 * v4;
  v7 = (9 >> 2 * v4) & 3;
  v8 = v3->m_vertices[(9i64 >> 2 * (unsigned __int8)v7) & 3];
  v9 = v3->m_vertices[v7];
  if ( (iy - v9->m_y) * (signed __int64)(v8->m_x - v9->m_x) - (v5 - v9->m_x) * (signed __int64)(v8->m_y - v9->m_y) <= 0 )
    return 0i64;
  v11 = v3->m_vertices[(9i64 >> 2 * ((18 >> v6) & 3u)) & 3];
  v12 = v3->m_vertices[(18 >> v6) & 3];
  if ( (iy - v12->m_y) * (signed __int64)(v11->m_x - v12->m_x) - (v5 - v12->m_x) * (signed __int64)(v11->m_y - v12->m_y) <= 0 )
    goto LABEL_12;
  v13 = v3->m_links[v4];
  if ( v13 & 0xFFFFFFFFFFFFFFFCui64 )
  {
    v14 = *(_QWORD *)((v13 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((9i64 >> 2 * ((9 >> 2 * (v13 & 3)) & 3u)) & 3) + 16);
    v15 = *(_QWORD *)((v13 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((9 >> 2 * (v13 & 3)) & 3) + 16);
    if ( (iy - *(_DWORD *)(v15 + 20)) * (signed __int64)(*(_DWORD *)(v14 + 16) - *(_DWORD *)(v15 + 16))
       - (v5 - *(_DWORD *)(v15 + 16)) * (signed __int64)(*(_DWORD *)(v14 + 20) - *(_DWORD *)(v15 + 20)) <= 0 )
      goto LABEL_12;
  }
  if ( v13 & 0xFFFFFFFFFFFFFFFCui64
    && (v16 = v13,
        v17 = v13 & 0xFFFFFFFFFFFFFFFCui64,
        v18 = (18 >> 2 * (v16 & 3)) & 3,
        v19 = *(_QWORD *)(v17 + 8i64 * v18 + 16),
        v20 = *(_QWORD *)(v17 + 8 * ((9i64 >> 2 * (unsigned __int8)v18) & 3) + 16),
        (iy - *(_DWORD *)(v19 + 20)) * (signed __int64)(*(_DWORD *)(v20 + 16) - *(_DWORD *)(v19 + 16))
      - (v5 - *(_DWORD *)(v19 + 16)) * (signed __int64)(*(_DWORD *)(v20 + 20) - *(_DWORD *)(v19 + 20)) <= 0) )
  {
LABEL_12:
    result = 0i64;
  }
  else
  {
    result = 1i64;
  }
  return result;
}}
  else
  {
    result = 1i64;
  }
 

// File Line: 490
// RVA: 0xCE0020
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::reset(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this, bool createDomainTriangulation)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v2; // r13
  bool v3; // bl
  signed __int64 v4; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v5; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v6; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item *v7; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v8; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v9; // rax
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

  v2 = this;
  v3 = createDomainTriangulation;
  this->m_mesh.vfptr[1].__first_virtual_table_function__((hkBaseObject *)&this->m_mesh);
  v4 = 32i64;
  v5 = v2->m_roots;
  do
  {
    *v5 = 0i64;
    v5[1] = 0i64;
    v5[2] = 0i64;
    v5 += 8;
    *(v5 - 5) = 0i64;
    *(v5 - 4) = 0i64;
    *(v5 - 3) = 0i64;
    *(v5 - 2) = 0i64;
    *(v5 - 1) = 0i64;
    --v4;
  }
  while ( v4 );
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::reset(&v2->m_edgeDataPolicy);
  if ( v3 )
  {
    v6 = v2->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !v6 || !v6->m_free )
      v6 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v2->m_mesh.m_vertices.m_allocator);
    if ( v6 )
    {
      v7 = v6->m_free;
      v6->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v7->m_data;
      v7->m_pool = v6;
      ++v6->m_used;
      *(_QWORD *)&v7->m_data[8] = 0i64;
      *(_QWORD *)v7->m_data = v2->m_mesh.m_vertices.m_used;
      v8 = v2->m_mesh.m_vertices.m_used;
      if ( v8 )
        v8->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v7;
      ++v2->m_mesh.m_vertices.m_numUsed;
      v2->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v7;
      *(_QWORD *)&v7->m_data[16] = 0i64;
      *(_QWORD *)&v7->m_data[24] = -4i64;
    }
    else
    {
      v7 = 0i64;
    }
    v9 = v2->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !v9 || !v9->m_free )
      v9 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v2->m_mesh.m_vertices.m_allocator);
    if ( v9 )
    {
      v10 = v9->m_free;
      v9->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v10->m_data;
      v10->m_pool = v9;
      ++v9->m_used;
      *(_QWORD *)&v10->m_data[8] = 0i64;
      *(_QWORD *)v10->m_data = v2->m_mesh.m_vertices.m_used;
      v11 = v2->m_mesh.m_vertices.m_used;
      if ( v11 )
        v11->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v10;
      ++v2->m_mesh.m_vertices.m_numUsed;
      v2->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v10;
      *(_DWORD *)&v10->m_data[16] = 0;
      *(_DWORD *)&v10->m_data[20] = 0x7FFF;
      *(_QWORD *)&v10->m_data[24] = -4i64;
    }
    else
    {
      v10 = 0i64;
    }
    v12 = v2->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !v12 || !v12->m_free )
      v12 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v2->m_mesh.m_vertices.m_allocator);
    if ( v12 )
    {
      v13 = v12->m_free;
      v12->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v13->m_data;
      v13->m_pool = v12;
      ++v12->m_used;
      *(_QWORD *)&v13->m_data[8] = 0i64;
      *(_QWORD *)v13->m_data = v2->m_mesh.m_vertices.m_used;
      v14 = v2->m_mesh.m_vertices.m_used;
      if ( v14 )
        v14->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v13;
      ++v2->m_mesh.m_vertices.m_numUsed;
      v2->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v13;
      *(_QWORD *)&v13->m_data[16] = 0x7FFFi64;
      *(_QWORD *)&v13->m_data[24] = -4i64;
    }
    else
    {
      v13 = 0i64;
    }
    v15 = v2->m_mesh.m_vertices.m_allocator.m_firstPool;
    if ( !v15 || !v15->m_free )
      v15 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v2->m_mesh.m_vertices.m_allocator);
    if ( v15 )
    {
      v16 = v15->m_free;
      v15->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v16->m_data;
      v16->m_pool = v15;
      ++v15->m_used;
      *(_QWORD *)&v16->m_data[8] = 0i64;
      *(_QWORD *)v16->m_data = v2->m_mesh.m_vertices.m_used;
      v17 = v2->m_mesh.m_vertices.m_used;
      if ( v17 )
        v17->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v16;
      ++v2->m_mesh.m_vertices.m_numUsed;
      v2->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v16;
      *(_DWORD *)&v16->m_data[16] = 0x7FFF;
      *(_DWORD *)&v16->m_data[20] = 0x7FFF;
      *(_QWORD *)&v16->m_data[24] = -4i64;
    }
    else
    {
      v16 = 0i64;
    }
    if ( v7 && v10 && v13 && v16 )
    {
      v18 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v2->m_mesh.m_triangles);
      v19 = v18;
      if ( v18 )
      {
        *(_DWORD *)&v18->m_items[0].m_data[66] = 0;
        *(_QWORD *)&v18->m_items[0].m_data[16] = v7;
        *(_QWORD *)&v18->m_items[0].m_data[24] = v13;
        *(_QWORD *)&v18->m_items[0].m_data[32] = v16;
        v2->m_roots[((signed __int64)(*(_DWORD *)&v16->m_data[16]
                                    + *(_DWORD *)&v13->m_data[16]
                                    + 2 * *(_DWORD *)&v7->m_data[16]) >> 13)
                  + (((signed __int64)(*(_DWORD *)&v16->m_data[20]
                                     + *(_DWORD *)&v13->m_data[20]
                                     + 2 * *(_DWORD *)&v7->m_data[20]) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v18;
        *(_WORD *)&v18->m_items[0].m_data[66] |= 8u;
      }
      v20 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v2->m_mesh.m_triangles);
      if ( v20 )
      {
        *(_DWORD *)&v20->m_items[0].m_data[66] = 0;
        *(_QWORD *)&v20->m_items[0].m_data[16] = v7;
        *(_QWORD *)&v20->m_items[0].m_data[24] = v16;
        *(_QWORD *)&v20->m_items[0].m_data[32] = v10;
        v2->m_roots[((signed __int64)(*(_DWORD *)&v10->m_data[16]
                                    + *(_DWORD *)&v16->m_data[16]
                                    + 2 * *(_DWORD *)&v7->m_data[16]) >> 13)
                  + (((signed __int64)(*(_DWORD *)&v10->m_data[20]
                                     + *(_DWORD *)&v16->m_data[20]
                                     + 2 * *(_DWORD *)&v7->m_data[20]) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v20;
        *(_WORD *)&v20->m_items[0].m_data[66] |= 8u;
      }
      if ( v19 && v20 )
      {
        *(_QWORD *)&v19->m_items[0].m_data[48] = 0i64;
        *(_QWORD *)&v19->m_items[0].m_data[40] = 0i64;
        *(_QWORD *)&v20->m_items[0].m_data[56] = 0i64;
        *(_QWORD *)&v20->m_items[0].m_data[48] = 0i64;
        *(_QWORD *)&v19->m_items[0].m_data[56] = v20;
        *(_QWORD *)&v20->m_items[0].m_data[40] = (char *)v19 + 2;
      }
      else
      {
        v2->m_status.m_storage = 1;
      }
    }
    else
    {
      v2->m_status.m_storage = 1;
    }
  }
}

// File Line: 542
// RVA: 0xB69270
hkResult *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::clone(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this, hkResult *result, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *other)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v3; // r15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v4; // rdi
  hkResult *v5; // r12
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **v6; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **v7; // rax
  signed __int64 v8; // r9
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm0
  unsigned __int64 v12; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v13; // rax
  unsigned __int64 v14; // r9
  __int64 v15; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v16; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v17; // r14
  signed __int64 v18; // r13
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v19; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v20; // rcx
  _QWORD *v21; // rax
  unsigned __int64 v22; // rdi
  __int64 v23; // rax
  unsigned __int64 *v24; // rbx
  signed __int64 v25; // rsi
  unsigned __int64 v26; // rax
  _QWORD *v27; // rsi
  unsigned int v28; // ebx
  signed __int64 v29; // r15
  __int64 v30; // rcx
  hkResult *v31; // rax
  unsigned __int64 v32; // r12
  unsigned __int64 v33; // rax
  unsigned int v34; // er9
  unsigned __int64 v35; // rax
  signed __int64 v36; // r15
  signed __int64 v37; // rbx
  unsigned __int64 v38; // rdx
  hkResult v39; // [rsp+30h] [rbp-29h]
  hkResult resulta; // [rsp+34h] [rbp-25h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **v41; // [rsp+38h] [rbp-21h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v42; // [rsp+40h] [rbp-19h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v43; // [rsp+50h] [rbp-9h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v44; // [rsp+60h] [rbp+7h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v45; // [rsp+C0h] [rbp+67h]
  hkResult *v46; // [rsp+C8h] [rbp+6Fh]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v47; // [rsp+D0h] [rbp+77h]
  hkResult res; // [rsp+D8h] [rbp+7Fh]

  v47 = other;
  v46 = result;
  v45 = this;
  v3 = this;
  v4 = other;
  v5 = result;
  other->m_mesh.vfptr[1].__first_virtual_table_function__((hkBaseObject *)&other->m_mesh);
  v6 = v4->m_roots;
  v41 = v4->m_roots;
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
  v44.m_elem = 0i64;
  v44.m_numElems = 0;
  v4->m_localToWorld.m_col0 = (hkVector4f)v9.m_quad;
  v10.m_quad = (__m128)v3->m_localToWorld.m_col1;
  v44.m_hashMod = -1;
  v43.m_elem = 0i64;
  v43.m_numElems = 0;
  v43.m_hashMod = -1;
  v4->m_localToWorld.m_col1 = (hkVector4f)v10.m_quad;
  v11.m_quad = (__m128)v3->m_localToWorld.m_col2;
  v42.m_elem = 0i64;
  v42.m_numElems = 0;
  v42.m_hashMod = -1;
  v4->m_localToWorld.m_col2 = (hkVector4f)v11.m_quad;
  v4->m_localToWorld.m_col3 = v3->m_localToWorld.m_col3;
  v4->m_worldToLocal.m_col0 = v3->m_worldToLocal.m_col0;
  v4->m_worldToLocal.m_col1 = v3->m_worldToLocal.m_col1;
  v4->m_worldToLocal.m_col2 = v3->m_worldToLocal.m_col2;
  v4->m_worldToLocal.m_col3 = v3->m_worldToLocal.m_col3;
  v4->m_margin = v3->m_margin;
  v12 = (unsigned __int64)v3->m_mesh.m_vertices.m_used;
  if ( v12 )
  {
    while ( 1 )
    {
      v13 = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *)v4->m_mesh.m_vertices.m_allocator.m_firstPool;
      if ( !v13 || !v13->m_free )
        v13 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)&v4->m_mesh.m_vertices);
      if ( !v13 )
        break;
      v14 = (unsigned __int64)v13->m_free;
      v13->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v14;
      *(_QWORD *)(v14 + 32) = v13;
      ++v13->m_used;
      *(_DWORD *)(v14 + 16) = *(_DWORD *)(v12 + 16);
      *(_DWORD *)(v14 + 20) = *(_DWORD *)(v12 + 20);
      *(_QWORD *)(v14 + 24) ^= (*(_DWORD *)(v12 + 24) ^ *(_DWORD *)(v14 + 24)) & 1;
      v15 = *(_QWORD *)(v14 + 24) ^ (*(_DWORD *)(v12 + 24) ^ (unsigned int)*(_QWORD *)(v14 + 24)) & 2;
      *(_QWORD *)(v14 + 24) = v15;
      *(_QWORD *)(v14 + 24) = *(_QWORD *)(v12 + 24) ^ ((unsigned __int8)v15 ^ (unsigned __int8)*(_QWORD *)(v12 + 24)) & 3;
      *(_QWORD *)(v14 + 8) = 0i64;
      *(_QWORD *)v14 = v4->m_mesh.m_vertices.m_used;
      v16 = v4->m_mesh.m_vertices.m_used;
      if ( v16 )
        v16->m_prev = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)v14;
      ++v4->m_mesh.m_vertices.m_numUsed;
      v4->m_mesh.m_vertices.m_used = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)v14;
      res.m_enum = 1;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        &v44,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v12,
        v14,
        &res);
      if ( res.m_enum )
        break;
      v12 = *(_QWORD *)v12;
      if ( !v12 )
      {
        v4 = v47;
        goto LABEL_13;
      }
    }
    v5->m_enum = 1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v42,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v42);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v43,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v43);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v44,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v44);
    v31 = v5;
  }
  else
  {
LABEL_13:
    v17 = v3->m_mesh.m_triangles.m_used;
    if ( v17 )
    {
      v18 = (signed __int64)&v4->m_mesh.m_triangles;
      while ( 1 )
      {
        v19 = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Pool **)v18;
        if ( !*(_QWORD *)v18 || !v19->m_free )
          v19 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator> *)v18);
        if ( !v19 )
          break;
        v20 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v19->m_free;
        v19->m_free = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::Item *)v20->m_next;
        v20[1].m_next = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v19;
        ++v19->m_used;
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle::Triangle(
          v20,
          v17);
        v22 = (unsigned __int64)v21;
        if ( !v21 )
          break;
        v21[1] = 0i64;
        *v21 = *(_QWORD *)(v18 + 8);
        v23 = *(_QWORD *)(v18 + 8);
        if ( v23 )
          *(_QWORD *)(v23 + 8) = v22;
        ++*(_DWORD *)(v18 + 16);
        *(_QWORD *)(v18 + 8) = v22;
        res.m_enum = 1;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
          &v43,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (unsigned __int64)v17,
          v22,
          &res);
        if ( res.m_enum )
          break;
        v24 = (unsigned __int64 *)(v22 + 16);
        v25 = 3i64;
        do
        {
          v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v44,
                  *v24,
                  0i64);
          ++v24;
          *(v24 - 1) = v26;
          --v25;
        }
        while ( v25 );
        v27 = (_QWORD *)(v22 + 40);
        v28 = 0;
        do
        {
          v29 = 8i64 * (signed int)v28 + 40;
          v30 = *(__int64 *)((char *)&v17->m_next + v29);
          if ( v30 & 0xFFFFFFFFFFFFFFFCui64 )
          {
            v32 = (v30 & 0xFFFFFFFFFFFFFFFCui64) + (*(_QWORD *)((_BYTE *)&v17->m_next + v29) & 3i64);
            v33 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                    &v42,
                    v32,
                    0i64);
            v34 = v33 & 3;
            v35 = v33 & 0xFFFFFFFFFFFFFFFCui64;
            if ( v35 )
            {
              *(_QWORD *)(v22 + v29) = v35 + v34;
              *(_QWORD *)(v35 + 8i64 * (signed int)v34 + 40) = v22 + v28;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
                &v42,
                &resulta,
                v32);
            }
            else
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
                &v42,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (unsigned __int64)v17 + v28,
                v22 + v28,
                &v39);
              if ( v39.m_enum )
                goto LABEL_38;
            }
          }
          else
          {
            *v27 = 0i64;
          }
          ++v28;
          ++v27;
        }
        while ( (signed int)v28 < 3 );
        v17 = v17->m_next;
        if ( !v17 )
        {
          v6 = v41;
          v3 = v45;
          v5 = v46;
          goto LABEL_35;
        }
      }
LABEL_38:
      v46->m_enum = 1;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v42,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v42);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v43,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v43);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v44,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v44);
      v31 = v46;
    }
    else
    {
LABEL_35:
      v36 = (char *)v3 - (char *)v47;
      v37 = 256i64;
      do
      {
        v38 = *(unsigned __int64 *)((char *)v6 + v36);
        if ( v38 )
          *v6 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(&v43, v38, 0i64);
        else
          *v6 = 0i64;
        ++v6;
        --v37;
      }
      while ( v37 );
      v5->m_enum = 0;
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v42,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v42);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v43,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v43);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v44,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v44);
      v31 = v5;
    }
  }
  return v31;
}oc.vfptr);
      _((AMD_HD3D *)&v43);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
        &v44,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      _((AMD_HD3D *)&v44);
      v31 = v5;
    }
  }
  return 

// File Line: 634
// RVA: 0xB6D720
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setDomain(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this, hkVector4f *dmin, hkVector4f *dmax, float angle, bool margin)
{
  hkVector4f *v5; // r10
  int v6; // eax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v7; // rbx
  __m128i v8; // xmm6
  __m128 v9; // xmm9
  __m128 v10; // xmm2
  __m128i v11; // xmm8
  __m128 v12; // xmm0
  __m128i v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  hkQuaternionf *v23; // rdx
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __int128 v27; // [rsp+20h] [rbp-78h]

  v5 = dmin;
  v6 = margin != 0;
  v7 = this;
  this->m_margin = v6;
  v8 = _mm_load_si128((const __m128i *)_xmm);
  v9 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(angle), (__m128)LODWORD(angle), 0), *(__m128 *)offset_1);
  v10 = _mm_andnot_ps(*(__m128 *)_xmm, v9);
  v11 = _mm_add_epi32(v8, v8);
  v12 = 0i64;
  v12.m128_f32[0] = (float)(0x7FFFFF - 2 * v6);
  v13 = _mm_andnot_si128(v8, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v10, *(__m128 *)_xmm)), v8));
  v14 = _mm_cvtepi32_ps(v13);
  v15 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v13, v11), (__m128i)0i64);
  v16 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v14, *(__m128 *)DP1_0), v10), _mm_mul_ps(v14, *(__m128 *)DP2)),
          _mm_mul_ps(v14, *(__m128 *)DP3));
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v15,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v17, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v17),
                        *(__m128 *)cosCoeff2_0),
                      v17),
                    v17),
                  _mm_mul_ps(v17, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v17, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v17),
                      *(__m128 *)sinCoeff2_0),
                    v17),
                  v16),
                v16),
              v15)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v11, v11), v13), 0x1Du),
            _mm_and_ps(v9, *(__m128 *)_xmm)));
  v19 = _mm_shuffle_ps(v18, v18, 0);
  v20 = _mm_shuffle_ps(v18, v18, 85);
  v21 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
  v22 = _mm_sub_ps(dmax->m_quad, dmin->m_quad);
  v23 = (hkQuaternionf *)&this->m_localToWorld;
  v27 = 0i64;
  v23->m_vec = (hkVector4f)transform.m_quad;
  v24 = _mm_mul_ps(v22, _mm_div_ps(query.m_quad, _mm_shuffle_ps(v12, v12, 0)));
  v23[1].m_vec = (hkVector4f)direction.m_quad;
  v23[2].m_vec = (hkVector4f)stru_141A71280.m_quad;
  v25 = _mm_shuffle_ps(v24, v24, 0);
  v26 = _mm_shuffle_ps(v24, v24, 85);
  v23[3] = (hkQuaternionf)qi.m_vec.m_quad;
  v23->m_vec.m_quad = _mm_movelh_ps(
                        _mm_unpacklo_ps(_mm_mul_ps(v25, v20), _mm_mul_ps(_mm_sub_ps((__m128)0i64, v19), v25)),
                        v21);
  this->m_localToWorld.m_col1.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(_mm_mul_ps(v26, v19), _mm_mul_ps(v26, v20)), v21);
  this->m_localToWorld.m_col3.m_quad = _mm_shuffle_ps(v5->m_quad, qi.m_vec.m_quad, 228);
  __hkMatrix4UtilAlgo::setInverse(
    (hkResult *)&margin,
    &this->m_localToWorld,
    &this->m_worldToLocal,
    (hkSimdFloat32 *)&v27);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    v7,
    1);
}

// File Line: 658
// RVA: 0xB8B520
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPoints(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this, hkStridedVertices *points, hkMatrix4f *worldToXYPlane, bool margin, bool keepRatio)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  hkMatrix4f *v7; // r10
  __int64 v8; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *v9; // rbx
  const float *v10; // rax
  __int64 v11; // rdx
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
  __m128 v26; // xmm3
  BOOL v27; // edx
  int v28; // eax
  __m128 v29; // xmm12
  __m128 v30; // xmm15
  __m128 *v31; // rdx
  __m128 v32; // xmm8
  __m128 v33; // xmm1
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm3
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm13
  __m128 v40; // ST30_16
  __m128 v41; // xmm7
  __m128 v42; // xmm0
  __m128 v43; // ST20_16
  __m128 v44; // xmm2
  hkSimdFloat32 epsilon; // [rsp+40h] [rbp-B8h]

  v5 = (__m128)xmmword_141A712A0;
  v6 = (__m128)xmmword_141A712F0;
  v7 = worldToXYPlane;
  v8 = (unsigned int)points->m_numVertices;
  v9 = this;
  if ( (signed int)v8 > 0 )
  {
    v10 = points->m_vertices;
    v11 = points->m_striding;
    v12 = (unsigned int *)(v10 + 2);
    do
    {
      v13 = (__m128)*v12;
      v14 = (__m128)*(unsigned __int64 *)v10;
      v10 = (const float *)((char *)v10 + v11);
      v12 = (unsigned int *)((char *)v12 + v11);
      v15 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v14, v13), 4), 4);
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v7->m_col0.m_quad), v7->m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v7->m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v7->m_col2.m_quad));
      v5 = _mm_min_ps(v5, v16);
      v6 = _mm_max_ps(v6, v16);
      --v8;
    }
    while ( v8 );
  }
  v17 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_100_0), (__m128)LODWORD(FLOAT_100_0), 0), *(__m128 *)&::epsilon);
  v18 = _mm_cmpltps(_mm_sub_ps(v6, v5), v17);
  v19 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v5, v17), v18), _mm_andnot_ps(v18, v5));
  v20 = _mm_sub_ps(_mm_or_ps(_mm_and_ps(_mm_add_ps(v6, v17), v18), _mm_andnot_ps(v18, v6)), v19);
  if ( keepRatio )
  {
    v21 = _mm_shuffle_ps(v20, v20, 0);
    v22 = _mm_shuffle_ps(v20, v20, 85);
    v20 = v22;
    if ( v21.m128_f32[0] <= v22.m128_f32[0] )
    {
      v19.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0))
                      - (float)((float)(v20.m128_f32[0] - v21.m128_f32[0]) * 0.5);
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
  v26 = v20;
  v27 = margin != 0;
  v9->m_margin = v27;
  v28 = 2 * v27;
  v29 = v7->m_col1.m_quad;
  v30 = v7->m_col2.m_quad;
  v23.m128_f32[0] = (float)v27;
  v31 = &v9->m_worldToLocal.m_col0.m_quad;
  v24.m128_f32[0] = (float)(0x7FFFFF - v28);
  v32 = _mm_shuffle_ps(v7->m_col2.m_quad, v30, 85);
  v33 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v25)), v25), _mm_shuffle_ps(v24, v24, 0));
  v34 = _mm_shuffle_ps(v7->m_col2.m_quad, v30, 170);
  v35 = _mm_andnot_ps(_mm_cmpeqps(v26, (__m128)0i64), v33);
  v36 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, query.m_quad), 180);
  v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, query.m_quad), 196);
  v38 = _mm_mul_ps(v37, direction.m_quad);
  v39 = _mm_mul_ps(v37, stru_141A71280.m_quad);
  v40 = _mm_mul_ps(v37, transform.m_quad);
  v41 = _mm_mul_ps(_mm_shuffle_ps(v7->m_col1.m_quad, v29, 85), v38);
  v42 = v7->m_col3.m_quad;
  v43 = _mm_shuffle_ps(
          _mm_sub_ps(_mm_shuffle_ps(v23, v23, 0), _mm_mul_ps(v37, v19)),
          _mm_mul_ps(v37, qi.m_vec.m_quad),
          228);
  v44 = v7->m_col0.m_quad;
  epsilon.m_real = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 255), v43);
  *v31 = _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v38), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v40)),
             _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v39)),
           _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), v43));
  v31[3] = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_mul_ps(v40, _mm_shuffle_ps(v42, v42, 0)), _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v38)),
               _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v39)),
             epsilon.m_real);
  v31[1] = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_mul_ps(v40, _mm_shuffle_ps(v29, v29, 0)), v41),
               _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v39)),
             _mm_mul_ps(_mm_shuffle_ps(v29, v29, 255), v43));
  v31[2] = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_mul_ps(v40, _mm_shuffle_ps(v30, v30, 0)), _mm_mul_ps(v32, v38)),
               _mm_mul_ps(v34, v39)),
             _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v43));
  epsilon.m_real = aabbOut.m_quad;
  __hkMatrix4UtilAlgo::setInverse((hkResult *)&keepRatio, &v9->m_worldToLocal, &v9->m_localToWorld, &epsilon);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::reset(
    v9,
    1);
}

// File Line: 730
// RVA: 0xB8B150
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPlanarPoints(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this, hkStridedVertices *points, hkVector4f *planeNormal, bool margin, bool keepRatio, bool useMainAxis)
{
  bool v6; // bl
  hkStridedVertices *v7; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *v8; // rsi
  __m128i v9; // xmm4
  __m128 v10; // xmm3
  int v11; // eax
  signed int v12; // edx
  __int64 v13; // rax
  bool v14; // zf
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  float v22; // xmm1_4
  __m128 v23; // xmm7
  __m128 v24; // xmm2
  __m128 v25; // xmm9
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm6
  __m128i v35; // xmm1
  __m128i v36; // xmm2
  hkMatrix4f worldToXYPlane; // [rsp+30h] [rbp-C8h]
  hkQuaternionf qi; // [rsp+70h] [rbp-88h]
  __m128i v39; // [rsp+88h] [rbp-70h]
  __m128i v40; // [rsp+98h] [rbp-60h]
  bool v41; // [rsp+138h] [rbp+40h]

  v6 = margin;
  v7 = points;
  v8 = this;
  worldToXYPlane.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  worldToXYPlane.m_col0 = (hkVector4f)transform.m_quad;
  worldToXYPlane.m_col1 = (hkVector4f)direction.m_quad;
  worldToXYPlane.m_col3 = (hkVector4f)::qi.m_vec.m_quad;
  if ( keepRatio )
  {
    v9 = _mm_load_si128((const __m128i *)planeNormal);
    v10 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u);
    v11 = _mm_movemask_ps(
            _mm_and_ps(
              _mm_cmpleps(
                _mm_max_ps(
                  _mm_shuffle_ps(v10, v10, 170),
                  _mm_max_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0))),
                v10),
              (__m128)xmmword_141A4D8E0));
    v12 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v11];
    v13 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v11];
    worldToXYPlane.m_col2 = *(hkVector4f *)((char *)&worldToXYPlane.m_col0 + 4 * v13);
    *(hkVector4f *)((char *)&worldToXYPlane.m_col0 + 4 * v13) = (hkVector4f)stru_141A71280.m_quad;
    v14 = v12 == 2;
    if ( v12 < 2 )
    {
      v15 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v13], (__m128)v9);
      v16 = _mm_or_ps(_mm_shuffle_ps(v15, v15, 78), v15);
      if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v16, v16, 177) | v16.m128_i32[0]) > 0.0 )
      {
        v17 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        worldToXYPlane.m_col0.m_quad = _mm_xor_ps(worldToXYPlane.m_col0.m_quad, v17);
        worldToXYPlane.m_col1.m_quad = _mm_xor_ps(worldToXYPlane.m_col1.m_quad, v17);
        goto LABEL_17;
      }
      v14 = v12 == 2;
    }
    if ( v14 )
    {
      v18 = _mm_and_ps((__m128)v9, (__m128)xmmword_141687F20);
      v19 = _mm_or_ps(_mm_shuffle_ps(v18, v18, 78), v18);
      if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v19, v19, 177) | v19.m128_i32[0]) < 0.0 )
        worldToXYPlane.m_col0.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         worldToXYPlane.m_col0.m_quad);
    }
  }
  else
  {
    v20 = _mm_mul_ps(planeNormal->m_quad, stru_141A71280.m_quad);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    LODWORD(v22) = (unsigned __int128)_mm_shuffle_ps(
                                        (__m128)LODWORD(FLOAT_0_99998999),
                                        (__m128)LODWORD(FLOAT_0_99998999),
                                        0);
    if ( v21.m128_f32[0] <= v22 )
    {
      if ( v21.m128_f32[0] >= (float)(0.0 - v22) )
      {
        v23 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v21), (__m128)xmmword_141A711B0);
        v24 = _mm_rsqrt_ps(v23);
        v25 = _mm_andnot_ps(
                _mm_cmpleps(v23, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v24), v24)),
                  _mm_mul_ps(v24, *(__m128 *)_xmm)));
        v26 = _mm_mul_ps(v25, (__m128)xmmword_141A711B0);
        v27 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), planeNormal->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(planeNormal->m_quad, planeNormal->m_quad, 201), stru_141A71280.m_quad));
        v28 = _mm_shuffle_ps(v27, v27, 201);
        if ( v21.m128_f32[0] < COERCE_FLOAT(
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(FLOAT_N0_99900001),
                                   (__m128)LODWORD(FLOAT_N0_99900001),
                                   0)) )
        {
          v29 = _mm_mul_ps(v28, v28);
          v30 = _mm_sub_ps(v23, v21);
          v31 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          v32 = _mm_rsqrt_ps(v31);
          v33 = _mm_rsqrt_ps(v30);
          v26 = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps(v30, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v30), v33)),
                        _mm_mul_ps(v33, *(__m128 *)_xmm))),
                    v30),
                  _mm_andnot_ps(
                    _mm_cmpleps(v31, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                      _mm_mul_ps(v32, *(__m128 *)_xmm))));
        }
        v34 = _mm_mul_ps(v28, v26);
        qi.m_vec.m_quad = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, _mm_mul_ps(v23, v25)), 196);
      }
      else
      {
        hkQuaternionf::setFlippedRotation(&qi, planeNormal);
      }
    }
    else
    {
      qi.m_vec.m_quad = ::qi.m_vec.m_quad;
    }
    hkRotationf::set((hkRotationf *)&qi.m_vec.m_quad.m128_u16[4], &qi);
    v35 = _mm_srli_si128(_mm_slli_si128(v39, 4), 4);
    v36 = v40;
    _mm_store_si128((__m128i *)&worldToXYPlane, _mm_srli_si128(_mm_slli_si128(*(__m128i *)((char *)&qi + 8), 4), 4));
    _mm_store_si128((__m128i *)&worldToXYPlane.m_col1, v35);
    _mm_store_si128((__m128i *)&worldToXYPlane.m_col2, _mm_srli_si128(_mm_slli_si128(v36, 4), 4));
    worldToXYPlane.m_col3.m_quad = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, query.m_quad), 196);
  }
LABEL_17:
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::setDomainFromPoints(
    v8,
    v7,
    &worldToXYPlane,
    v6,
    v41);
}

// File Line: 944
// RVA: 0xCDF260
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *result, int x, int y)
{
  int v4; // er14
  int v5; // er15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *v6; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v7; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v8; // r12
  char v9; // al
  int v10; // edi
  int v11; // er10
  unsigned __int64 v12; // rbx
  __int64 v13; // r11
  __int64 v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rbx
  char v17; // cl
  __int64 v18; // rdx
  __int64 v19; // rax
  int v20; // er8
  __int64 v21; // r9
  __int64 v22; // rdx
  int v23; // er13
  __int64 v24; // r9
  __int64 v25; // rdx
  _BOOL8 v26; // rdx
  __int64 *v27; // rcx
  __int64 v28; // rdx
  hkBaseObjectVtbl *v29; // r8
  signed __int64 v30; // rcx
  __int64 v31; // rax
  __m128i v33; // [rsp+20h] [rbp-E0h]
  unsigned __int64 v34; // [rsp+30h] [rbp-D0h]
  __int64 v35; // [rsp+38h] [rbp-C8h]
  unsigned __int64 v36; // [rsp+40h] [rbp-C0h]
  __int64 v37; // [rsp+48h] [rbp-B8h]
  hkErrStream v38; // [rsp+50h] [rbp-B0h]
  __m128i v39; // [rsp+70h] [rbp-90h]
  char buf; // [rsp+80h] [rbp-80h]
  int v41; // [rsp+2C0h] [rbp+1C0h]
  int v42; // [rsp+2C4h] [rbp+1C4h]
  int i; // [rsp+2D0h] [rbp+1D0h]

  v4 = y;
  v5 = x;
  v6 = result;
  v7 = this->m_roots[((signed __int64)x >> 11) + (((signed __int64)y >> 7) & 0xFFFFFFFFFFFFFFF0ui64)];
  if ( !v7 )
    v7 = this->m_mesh.m_triangles.m_used;
  v8 = this->m_mesh.m_triangles.m_used;
  v33.m128i_i64[0] = (__int64)v7;
  v33.m128i_i32[2] = 0;
  _mm_store_si128(&v33, v33);
  v9 = 1;
  if ( v8 )
  {
    v10 = this->m_mesh.m_triangles.m_numUsed;
    v11 = v33.m128i_i32[2];
    v12 = v33.m128i_i64[0];
    for ( i = this->m_mesh.m_triangles.m_numUsed; ; v10 = i )
    {
      if ( !v9 )
      {
        v39.m128i_i64[0] = (__int64)v8;
        v8 = v8->m_next;
        v39.m128i_i32[2] = 0;
        _mm_store_si128(&v33, v39);
        v11 = v33.m128i_i32[2];
        v12 = v33.m128i_i64[0];
      }
      v13 = v11;
      v14 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * (unsigned __int8)v11) & 3) + 16);
      v15 = *(_QWORD *)(v12 + 8i64 * v11 + 16);
      if ( (v4 - *(_DWORD *)(v15 + 20)) * (*(_DWORD *)(v14 + 16) - *(_DWORD *)(v15 + 16))
         - (v5 - *(_DWORD *)(v15 + 16)) * (*(_DWORD *)(v14 + 20) - *(_DWORD *)(v15 + 20)) < 0 )
      {
        do
        {
          v16 = *(_QWORD *)(v12 + 8 * v13 + 40);
          v17 = v16;
          v12 = v16 & 0xFFFFFFFFFFFFFFFCui64;
          v11 = (9 >> 2 * (v17 & 3)) & 3;
          v13 = v11;
          v33.m128i_i32[2] = (9 >> 2 * (v17 & 3)) & 3;
          v18 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v17 & 3)) & 3u)) & 3) + 16);
          v19 = *(_QWORD *)(v12 + 8i64 * v11 + 16);
        }
        while ( (v4 - *(_DWORD *)(v19 + 20)) * (*(_DWORD *)(v18 + 16) - *(_DWORD *)(v19 + 16))
              - (v5 - *(_DWORD *)(v19 + 16)) * (*(_DWORD *)(v18 + 20) - *(_DWORD *)(v19 + 20)) < 0 );
      }
      if ( v10 > 0 )
        break;
LABEL_12:
      v9 = 0;
      if ( !v8 )
        goto LABEL_25;
    }
    while ( 1 )
    {
      v20 = (9 >> 2 * v11) & 3;
      v34 = v12;
      LODWORD(v35) = (9 >> 2 * v11) & 3;
      LODWORD(v37) = (18 >> 2 * v11) & 3;
      v36 = v12;
      v21 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * (unsigned __int8)v20) & 3) + 16);
      v22 = *(_QWORD *)(v12 + 8i64 * v20 + 16);
      v23 = (v4 - *(_DWORD *)(v22 + 20)) * (*(_DWORD *)(v21 + 16) - *(_DWORD *)(v22 + 16))
          - (v5 - *(_DWORD *)(v22 + 16)) * (*(_DWORD *)(v21 + 20) - *(_DWORD *)(v22 + 20));
      v41 = v23;
      v24 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * (unsigned __int8)v37) & 3) + 16);
      v25 = *(_QWORD *)(v12 + 8i64 * (signed int)v37 + 16);
      v42 = (v4 - *(_DWORD *)(v25 + 20)) * (*(_DWORD *)(v24 + 16) - *(_DWORD *)(v25 + 16))
          - (v5 - *(_DWORD *)(v25 + 16)) * (*(_DWORD *)(v24 + 20) - *(_DWORD *)(v25 + 20));
      v26 = v23 >= v42;
      v27 = (__int64 *)(&v34 + 2 * v26);
      if ( *(&v41 + v26) >= 0 )
        break;
      v28 = *((signed int *)v27 + 2);
      --v10;
      v29 = (hkBaseObjectVtbl *)(*(_QWORD *)(*v27 + 8 * v28 + 40) & 0xFFFFFFFFFFFFFFFCui64);
      v30 = *(_QWORD *)(*v27 + 8 * v28 + 40) & 3i64;
      v38.vfptr = v29;
      *(_DWORD *)&v38.m_memSizeAndFlags = v30;
      _mm_store_si128(&v33, *(__m128i *)&v38.vfptr);
      v11 = v33.m128i_i32[2];
      v12 = v33.m128i_i64[0];
      if ( v10 <= 0 )
        goto LABEL_12;
    }
    switch ( 0x40000000 )
    {
      case 0:
        v31 = v33.m128i_i64[1];
        v6->m_type.m_storage = 0;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      case 1:
        v31 = v33.m128i_i64[1];
        v6->m_type.m_storage = 1;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      case 2:
        v31 = v35;
        v6->m_type.m_storage = 1;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      case 3:
        v31 = v35;
        v6->m_type.m_storage = 2;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      case 4:
        v31 = v37;
        v6->m_type.m_storage = 1;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      case 5:
        v31 = v33.m128i_i64[1];
        v6->m_type.m_storage = 2;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      case 6:
        v31 = v37;
        v6->m_type.m_storage = 2;
        v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v12;
        break;
      default:
        if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
        {
          *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
          `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
        }
        v6->m_type.m_storage = 3;
        goto LABEL_30;
    }
  }
  else
  {
LABEL_25:
    hkErrStream::hkErrStream(&v38, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v38.vfptr, "Cycle detected during point location");
    if ( (unsigned int)hkError::messageError(
                         -1194955937,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
                         938) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v38.vfptr);
    if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
    {
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
    }
    v6->m_type.m_storage = 4;
LABEL_30:
    v6->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e;
    v31 = *((_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e
          + 1);
  }
  *(_QWORD *)&v6->m_edge.m_index = v31;
  return v6;
}

// File Line: 963
// RVA: 0xCDEE70
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *__usercall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex@<rax>(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this@<rcx>, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *result@<rdx>, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *rootArg@<r8>, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v@<r9>, __int64 a5@<rbx>)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v5; // r13
  __int64 v6; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v7; // xmm0
  int v8; // esi
  int v9; // er14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v10; // r15
  char v11; // al
  int v12; // edi
  int v13; // er10
  unsigned __int64 v14; // rbx
  __int64 v15; // r11
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rbx
  char v19; // cl
  __int64 v20; // rdx
  __int64 v21; // rax
  int v22; // er8
  __int64 v23; // r9
  __int64 v24; // rdx
  int v25; // er12
  __int64 v26; // r9
  __int64 v27; // rdx
  _BOOL8 v28; // rdx
  __int64 *v29; // rcx
  __int64 v30; // rdx
  hkBaseObjectVtbl *v31; // r8
  signed __int64 v32; // rcx
  __int64 v33; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v35; // [rsp+20h] [rbp-D0h]
  unsigned __int64 v36; // [rsp+30h] [rbp-C0h]
  __int64 v37; // [rsp+38h] [rbp-B8h]
  unsigned __int64 v38; // [rsp+40h] [rbp-B0h]
  __int64 v39; // [rsp+48h] [rbp-A8h]
  hkErrStream v40; // [rsp+50h] [rbp-A0h]
  __m128i buf; // [rsp+70h] [rbp-80h]
  int i; // [rsp+2B8h] [rbp+1C8h]
  __int64 v43; // [rsp+2C0h] [rbp+1D0h]

  v5 = result;
  result->m_triangle = rootArg->m_triangle;
  v6 = *(_QWORD *)&rootArg->m_index;
  *(_QWORD *)&result->m_index = v6;
  if ( result->m_triangle->m_vertices[(signed int)v6] != v )
  {
    v7 = *rootArg;
    v43 = a5;
    v8 = v->m_y;
    v35 = v7;
    v9 = v->m_x;
    v10 = this->m_mesh.m_triangles.m_used;
    v11 = 1;
    if ( v10 )
    {
      v12 = this->m_mesh.m_triangles.m_numUsed;
      v13 = v35.m_index;
      v14 = (unsigned __int64)v35.m_triangle;
      for ( i = this->m_mesh.m_triangles.m_numUsed; ; v12 = i )
      {
        if ( !v11 )
        {
          buf.m128i_i64[0] = (__int64)v10;
          v10 = v10->m_next;
          buf.m128i_i32[2] = 0;
          _mm_store_si128((__m128i *)&v35, buf);
          v13 = v35.m_index;
          v14 = (unsigned __int64)v35.m_triangle;
        }
        v15 = v13;
        v16 = *(_QWORD *)(v14 + 8 * ((9i64 >> 2 * (unsigned __int8)v13) & 3) + 16);
        v17 = *(_QWORD *)(v14 + 8i64 * v13 + 16);
        if ( (v8 - *(_DWORD *)(v17 + 20)) * (*(_DWORD *)(v16 + 16) - *(_DWORD *)(v17 + 16))
           - (v9 - *(_DWORD *)(v17 + 16)) * (*(_DWORD *)(v16 + 20) - *(_DWORD *)(v17 + 20)) < 0 )
        {
          do
          {
            v18 = *(_QWORD *)(v14 + 8 * v15 + 40);
            v19 = v18;
            v14 = v18 & 0xFFFFFFFFFFFFFFFCui64;
            v13 = (9 >> 2 * (v19 & 3)) & 3;
            v15 = v13;
            v35.m_index = (9 >> 2 * (v19 & 3)) & 3;
            v20 = *(_QWORD *)(v14 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v19 & 3)) & 3u)) & 3) + 16);
            v21 = *(_QWORD *)(v14 + 8i64 * v13 + 16);
          }
          while ( (v8 - *(_DWORD *)(v21 + 20)) * (*(_DWORD *)(v20 + 16) - *(_DWORD *)(v21 + 16))
                - (v9 - *(_DWORD *)(v21 + 16)) * (*(_DWORD *)(v20 + 20) - *(_DWORD *)(v21 + 20)) < 0 );
        }
        if ( v12 > 0 )
          break;
LABEL_11:
        v11 = 0;
        if ( !v10 )
          goto LABEL_17;
      }
      while ( 1 )
      {
        v22 = (9 >> 2 * v13) & 3;
        v36 = v14;
        LODWORD(v37) = (9 >> 2 * v13) & 3;
        LODWORD(v39) = (18 >> 2 * v13) & 3;
        v38 = v14;
        v23 = *(_QWORD *)(v14 + 8 * ((9i64 >> 2 * (unsigned __int8)v22) & 3) + 16);
        v24 = *(_QWORD *)(v14 + 8i64 * v22 + 16);
        v25 = (v8 - *(_DWORD *)(v24 + 20)) * (*(_DWORD *)(v23 + 16) - *(_DWORD *)(v24 + 16))
            - (v9 - *(_DWORD *)(v24 + 16)) * (*(_DWORD *)(v23 + 20) - *(_DWORD *)(v24 + 20));
        LODWORD(v43) = v25;
        v26 = *(_QWORD *)(v14 + 8 * ((9i64 >> 2 * (unsigned __int8)v39) & 3) + 16);
        v27 = *(_QWORD *)(v14 + 8i64 * (signed int)v39 + 16);
        HIDWORD(v43) = (v8 - *(_DWORD *)(v27 + 20)) * (*(_DWORD *)(v26 + 16) - *(_DWORD *)(v27 + 16))
                     - (v9 - *(_DWORD *)(v27 + 16)) * (*(_DWORD *)(v26 + 20) - *(_DWORD *)(v27 + 20));
        v28 = v25 >= SHIDWORD(v43);
        v29 = (__int64 *)(&v36 + 2 * v28);
        if ( *((_DWORD *)&v43 + v28) >= 0 )
          break;
        v30 = *((signed int *)v29 + 2);
        --v12;
        v31 = (hkBaseObjectVtbl *)(*(_QWORD *)(*v29 + 8 * v30 + 40) & 0xFFFFFFFFFFFFFFFCui64);
        v32 = *(_QWORD *)(*v29 + 8 * v30 + 40) & 3i64;
        v40.vfptr = v31;
        *(_DWORD *)&v40.m_memSizeAndFlags = v32;
        _mm_store_si128((__m128i *)&v35, *(__m128i *)&v40.vfptr);
        v13 = v35.m_index;
        v14 = (unsigned __int64)v35.m_triangle;
        if ( v12 <= 0 )
          goto LABEL_11;
      }
      switch ( 0x40000000 )
      {
        case 0:
        case 1:
        case 5:
          v33 = *(_QWORD *)&v35.m_index;
          break;
        case 2:
        case 3:
          v33 = v37;
          break;
        case 4:
        case 6:
          v33 = v39;
          break;
        default:
          goto LABEL_20;
      }
    }
    else
    {
LABEL_17:
      hkErrStream::hkErrStream(&v40, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v40.vfptr, "Cycle detected during point location");
      if ( (unsigned int)hkError::messageError(
                           -1194955937,
                           buf.m128i_i8,
                           "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
                           938) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v40.vfptr);
LABEL_20:
      if ( `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1 )
      {
        v14 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e;
      }
      else
      {
        v14 = 0i64;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
      }
      v33 = *((_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e
            + 1);
    }
    v5->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v14;
    *(_QWORD *)&v5->m_index = v33;
  }
  return v5;
}

// File Line: 975
// RVA: 0xCDED40
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingEdge(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *result, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *rootArg, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v0, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v1)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v5; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v6; // rax
  __int64 v7; // rax
  unsigned __int64 v8; // r8
  __int64 v9; // rdx
  int v10; // ecx
  int v11; // ecx
  __int64 v12; // rdx
  int v13; // er8
  unsigned __int64 i; // rdx
  int v15; // eax
  __int64 v16; // rdx
  char v17; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge resulta; // [rsp+20h] [rbp-18h]

  v5 = result;
  *result = *rootArg;
  v6 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
         this,
         &resulta,
         result,
         v0);
  v5->m_triangle = v6->m_triangle;
  v7 = *(_QWORD *)&v6->m_index;
  *(_QWORD *)&v5->m_index = v7;
  v8 = (unsigned __int64)v5->m_triangle;
  if ( v5->m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v7) & 3] != v1 )
  {
    v9 = *(_QWORD *)(v8 + 8i64 * (signed int)v7 + 16);
    v10 = *(_DWORD *)(v9 + 16);
    if ( !v10 || v10 == 0x7FFF || (v11 = *(_DWORD *)(v9 + 20)) == 0 || v11 == 0x7FFF )
    {
      for ( ; *(_QWORD *)(v8 + 8i64 * (signed int)v7 + 40) & 0xFFFFFFFFFFFFFFFCui64; v5->m_index = v7 )
      {
        v12 = *(_QWORD *)(v8 + 8i64 * (signed int)v7 + 40);
        v8 = *(_QWORD *)(v8 + 8i64 * (signed int)v7 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        v5->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v8;
        LODWORD(v7) = (9 >> 2 * (v12 & 3)) & 3;
      }
    }
    v13 = v5->m_index;
    for ( i = (unsigned __int64)v5->m_triangle;
          *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)(i + 8 * ((9i64 >> 2 * (unsigned __int8)v13) & 3) + 16) != v1;
          v5->m_index = v13 )
    {
      v15 = (18 >> 2 * v13) & 3;
      v5->m_index = v15;
      v16 = *(_QWORD *)(i + 8i64 * v15 + 40);
      v17 = v16;
      i = v16 & 0xFFFFFFFFFFFFFFFCui64;
      v13 = v17 & 3;
      v5->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)i;
    }
  }
  return v5;
}

// File Line: 1125
// RVA: 0xCDD970
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::insertVertex(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *result, int x, int y, bool conform, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *location, bool edgeSplit)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v7; // r12
  int v8; // ecx
  int v9; // er13
  int v10; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v11; // xmm6
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Insertion *v12; // rdi
  int v13; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v14; // rdx
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
  signed __int64 v32; // rcx
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
  signed __int64 v44; // rcx
  unsigned __int64 v45; // r9
  __int16 v46; // dx
  int v47; // eax
  int v48; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v49; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v50; // r9
  int v51; // eax
  int v52; // ecx
  unsigned __int64 v53; // r9
  signed __int64 v54; // rcx
  unsigned __int64 v55; // r9
  __int16 v56; // dx
  signed int v57; // eax
  char v58; // cl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v59; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v60; // r12
  __int64 v61; // rax
  __int64 v62; // rax
  __int64 v63; // r8
  __int64 v64; // r11
  int v65; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v66; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v67; // r13
  __int64 v68; // rax
  __int64 v69; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v70; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v71; // rcx
  __int64 v72; // r9
  __int64 v73; // rdx
  __int64 v74; // rax
  unsigned __int64 v75; // rcx
  int v76; // er8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v77; // r10
  unsigned __int64 v78; // rcx
  int v79; // er8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v80; // rcx
  __int64 v81; // rax
  __int64 v82; // rdx
  __int64 v83; // r8
  int v84; // eax
  int v85; // ecx
  __int64 v86; // rdx
  signed __int64 v87; // rcx
  unsigned __int64 v88; // rdx
  __int64 v89; // rdx
  __int64 v90; // r8
  int v91; // eax
  int v92; // ecx
  __int64 v93; // rdx
  signed __int64 v94; // rcx
  unsigned __int64 v95; // rdx
  __int64 v96; // rdx
  __int64 v97; // r8
  int v98; // eax
  int v99; // ecx
  __int64 v100; // rdx
  signed __int64 v101; // rcx
  unsigned __int64 v102; // rdx
  __int64 v103; // rdx
  __int64 v104; // r8
  int v105; // eax
  int v106; // ecx
  __int64 v107; // r8
  signed __int64 v108; // rcx
  unsigned __int64 v109; // r8
  __int16 v110; // ax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v111; // r15
  char v112; // al
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v113; // rcx
  int v114; // eax
  int v115; // er9
  int v116; // eax
  int v117; // eax
  __int64 v118; // rdx
  signed __int64 v119; // r8
  char v120; // cl
  signed int v121; // er9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v122; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v123; // rax
  int v124; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v125; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v126; // r9
  int v127; // eax
  int v128; // ecx
  unsigned __int64 v129; // r9
  signed __int64 v130; // rcx
  unsigned __int64 v131; // r9
  __int16 v132; // dx
  signed __int64 v133; // r8
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v134; // r13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v135; // rax
  __int64 v136; // rax
  __int64 v137; // rdx
  __int16 v138; // cx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v139; // rcx
  unsigned __int64 v140; // rcx
  int v141; // er8
  __int64 v142; // rcx
  __int64 v143; // rax
  __int64 v144; // rdx
  __int64 v145; // r8
  int v146; // eax
  int v147; // ecx
  __int64 v148; // r8
  signed __int64 v149; // rcx
  unsigned __int64 v150; // r8
  __int64 v151; // rdx
  __int64 v152; // r8
  int v153; // eax
  int v154; // ecx
  __int64 v155; // rdx
  signed __int64 v156; // rcx
  unsigned __int64 v157; // rdx
  __int64 v158; // rax
  char v159; // cl
  unsigned __int64 v160; // r9
  __int64 v161; // r10
  __int64 v162; // r8
  int v163; // eax
  int v164; // ecx
  __int64 v165; // r8
  unsigned __int64 v166; // r8
  char v167; // al
  int v168; // er9
  int v169; // eax
  int v170; // eax
  __int64 v171; // rcx
  int v172; // eax
  __int64 v173; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v174; // rax
  signed __int64 v175; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v176; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v177; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v178; // r14
  __int64 v179; // rax
  __int64 v180; // rax
  int v181; // eax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v182; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v183; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v184; // r13
  char v185; // al
  char v186; // bl
  int v187; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v188; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v189; // r8
  int v190; // eax
  int v191; // ecx
  unsigned __int64 v192; // r8
  signed __int64 v193; // rcx
  unsigned __int64 v194; // r8
  __int16 v195; // dx
  int v196; // eax
  int v197; // edx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v198; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v199; // r10
  int v200; // eax
  int v201; // ecx
  unsigned __int64 v202; // r10
  signed __int64 v203; // rcx
  unsigned __int64 v204; // r10
  __int16 v205; // dx
  signed __int64 v206; // r8
  signed __int64 v207; // r9
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v208; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v209; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *v210; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v211; // rax
  __int64 v212; // rax
  __int64 v213; // rdx
  unsigned __int64 v214; // rcx
  int v215; // er8
  __int64 v216; // r8
  unsigned __int64 v217; // rcx
  int v218; // er9
  __int64 v219; // rdx
  __int64 v220; // r8
  int v221; // eax
  int v222; // ecx
  __int64 v223; // rdx
  signed __int64 v224; // rcx
  unsigned __int64 v225; // rdx
  __int64 v226; // rdx
  __int64 v227; // r8
  int v228; // eax
  int v229; // ecx
  __int64 v230; // rax
  signed __int64 v231; // rcx
  unsigned __int64 v232; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v233; // rax
  int v234; // er9
  int v235; // eax
  int v236; // eax
  __int64 v237; // rcx
  __int64 v238; // rax
  _QWORD *v239; // rdx
  __int64 v240; // rax
  __int64 v241; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v242; // rax
  __int64 v243; // r14
  hkResult resulta; // [rsp+30h] [rbp-D0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v[2]; // [rsp+40h] [rbp-C0h]
  int v247; // [rsp+50h] [rbp-B0h]
  unsigned int v248; // [rsp+54h] [rbp-ACh]
  unsigned int v249; // [rsp+58h] [rbp-A8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v250; // [rsp+60h] [rbp-A0h]
  __int64 v251; // [rsp+68h] [rbp-98h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v252; // [rsp+70h] [rbp-90h]
  int v253; // [rsp+78h] [rbp-88h]
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v254; // [rsp+80h] [rbp-80h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge rootArg; // [rsp+90h] [rbp-70h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v256; // [rsp+A0h] [rbp-60h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v257; // [rsp+B0h] [rbp-50h]
  int v258; // [rsp+B8h] [rbp-48h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v259; // [rsp+C0h] [rbp-40h]
  __int64 v260; // [rsp+C8h] [rbp-38h]
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState v261; // [rsp+D0h] [rbp-30h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v262; // [rsp+120h] [rbp+20h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge v263; // [rsp+130h] [rbp+30h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v264; // [rsp+190h] [rbp+90h]
  int v265; // [rsp+1A0h] [rbp+A0h]

  v265 = x;
  v264 = this;
  v7 = this;
  v8 = location->m_type.m_storage;
  v9 = y;
  v10 = x;
  v11 = location->m_edge;
  v12 = result;
  rootArg = location->m_edge;
  if ( !v8 )
  {
    v182 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_vertices);
    v183 = v182;
    v251 = (__int64)v182;
    if ( !v182 )
    {
      if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
      {
        v181 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' | 1;
        goto LABEL_201;
      }
      goto LABEL_202;
    }
    *(_DWORD *)&v182->m_items[0].m_data[16] = v10;
    *(_DWORD *)&v182->m_items[0].m_data[20] = v9;
    v184 = rootArg.m_triangle;
    v185 = rootArg.m_index;
    *(_QWORD *)&v183->m_items[0].m_data[24] = -3i64;
    v186 = 2 * v185;
    v187 = (9 >> 2 * v185) & 3;
    LODWORD(location) = (9 >> 2 * v185) & 3;
    v188 = v184->m_vertices[v187];
    v189 = v184->m_vertices[(9i64 >> 2 * ((9 >> 2 * v185) & 3u)) & 3];
    v190 = v188->m_x;
    v191 = v189->m_x;
    if ( v190 >= v191
      && (v190 > v191 || v188->m_y > v189->m_y)
      && (v192 = v184->m_links[v187], v192 & 0xFFFFFFFFFFFFFFFCui64) )
    {
      v193 = v184->m_links[v187] & 3;
      v194 = v192 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v194 = (unsigned __int64)v184;
      LOBYTE(v193) = v187;
    }
    v195 = *(_WORD *)(v194 + 66);
    v196 = (unsigned __int8)v195 & (1 << v193) & 7;
    v247 = v196;
    *(_WORD *)(v194 + 66) = v195 & (~(_WORD)v196 | 0xFFF8);
    v197 = (18 >> v186) & 3;
    resulta.m_enum = (18 >> v186) & 3;
    v198 = v184->m_vertices[v197];
    v199 = v184->m_vertices[(9i64 >> 2 * (unsigned __int8)v197) & 3];
    v200 = v198->m_x;
    v201 = v199->m_x;
    if ( v200 >= v201
      && (v200 > v201 || v198->m_y > v199->m_y)
      && (v202 = v184->m_links[v197], v202 & 0xFFFFFFFFFFFFFFFCui64) )
    {
      v203 = v184->m_links[v197] & 3;
      v204 = v202 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v204 = (unsigned __int64)v184;
      LOBYTE(v203) = v197;
    }
    v205 = *(_WORD *)(v204 + 66);
    v249 = (unsigned __int8)v205 & (1 << v203) & 7;
    v206 = (18i64 >> 2 * LOBYTE(rootArg.m_index)) & 3;
    v207 = (9i64 >> 2 * LOBYTE(rootArg.m_index)) & 3;
    *(_WORD *)(v204 + 66) = v205 & (~(_WORD)v249 | 0xFFF8);
    v250 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)&v184->m_vertices[v206];
    v256.m_triangle = *v250;
    v[0] = v184->m_vertices[v207];
    v208 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
    if ( v208 )
    {
      v209 = v[0];
      *(_QWORD *)&v208->m_items[0].m_data[32] = v183;
      *(_DWORD *)&v208->m_items[0].m_data[66] = 0;
      *(_QWORD *)&v208->m_items[0].m_data[16] = v209;
      *(_QWORD *)&v208->m_items[0].m_data[24] = v256.m_triangle;
    }
    v256.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v184->m_vertices[rootArg.m_index];
    v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)*v250;
    v210 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
    if ( v210 )
    {
      v211 = v[0];
      *(_DWORD *)&v210->m_items[0].m_data[66] = 0;
      *(_QWORD *)&v210->m_items[0].m_data[16] = v211;
      *(_QWORD *)&v210->m_items[0].m_data[24] = v256.m_triangle;
      v212 = v251;
      *(_QWORD *)&v210->m_items[0].m_data[32] = v251;
    }
    else
    {
      v212 = v251;
    }
    if ( !v208 || !v210 )
    {
      if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
      {
        v181 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' | 1;
        goto LABEL_201;
      }
      goto LABEL_202;
    }
    v213 = (signed int)location;
    *v250 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v212;
    *(_WORD *)&v208->m_items[0].m_data[66] ^= (*((_WORD *)v184 + 33) ^ *(_WORD *)&v208->m_items[0].m_data[66]) & 0x10;
    *(_WORD *)&v208->m_items[0].m_data[66] = *((_WORD *)v184 + 33) ^ (*((_WORD *)v184 + 33) ^ *(_WORD *)&v208->m_items[0].m_data[66]) & 0x1F;
    *(_WORD *)&v208->m_items[0].m_data[68] = v184->m_sets;
    *(_WORD *)&v210->m_items[0].m_data[66] ^= (*((_WORD *)v184 + 33) ^ *(_WORD *)&v210->m_items[0].m_data[66]) & 0x10;
    *(_WORD *)&v210->m_items[0].m_data[66] = *((_WORD *)v184 + 33) ^ (*((_WORD *)v184 + 33) ^ *(_WORD *)&v210->m_items[0].m_data[66]) & 0x1F;
    *(_WORD *)&v210->m_items[0].m_data[68] = v184->m_sets;
    v214 = v184->m_links[v213] & 0xFFFFFFFFFFFFFFFCui64;
    v215 = v184->m_links[v213] & 3;
    *(_QWORD *)&v208->m_items[0].m_data[40] = v214 + (v184->m_links[v213] & 3);
    if ( v214 )
      *(_QWORD *)(v214 + 8i64 * v215 + 40) = v208;
    v216 = resulta.m_enum;
    v217 = v184->m_links[resulta.m_enum] & 0xFFFFFFFFFFFFFFFCui64;
    v218 = v184->m_links[resulta.m_enum] & 3;
    *(_QWORD *)&v210->m_items[0].m_data[40] = v217 + (v184->m_links[resulta.m_enum] & 3);
    if ( v217 )
      *(_QWORD *)(v217 + 8i64 * v218 + 40) = v210;
    *(_QWORD *)&v208->m_items[0].m_data[48] = (char *)v210 + 2;
    *(_QWORD *)&v210->m_items[0].m_data[56] = (char *)v208 + 1;
    *(_QWORD *)&v208->m_items[0].m_data[56] = (char *)v184 + (unsigned int)v213;
    v184->m_links[v213] = (unsigned __int64)&v208->m_items[0].m_data[2];
    *(_QWORD *)&v210->m_items[0].m_data[48] = (char *)v184 + (unsigned int)v216;
    v184->m_links[v216] = (unsigned __int64)&v210->m_items[0].m_data[1];
    if ( v247 )
    {
      v219 = *(_QWORD *)&v208->m_items[0].m_data[24];
      v220 = *(_QWORD *)&v208->m_items[0].m_data[16];
      v221 = *(_DWORD *)(v220 + 16);
      v222 = *(_DWORD *)(v219 + 16);
      if ( v221 >= v222
        && (v221 > v222 || *(_DWORD *)(v220 + 20) > *(_DWORD *)(v219 + 20))
        && (v223 = *(_QWORD *)&v208->m_items[0].m_data[40], v223 & 0xFFFFFFFFFFFFFFFCui64) )
      {
        v224 = *(_QWORD *)&v208->m_items[0].m_data[40] & 3i64;
        v225 = v223 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v225 = (unsigned __int64)v208;
        LOBYTE(v224) = 0;
      }
      *(_WORD *)(v225 + 66) |= (1 << v224) & 7;
    }
    if ( v249 )
    {
      v226 = *(_QWORD *)&v210->m_items[0].m_data[24];
      v227 = *(_QWORD *)&v210->m_items[0].m_data[16];
      v228 = *(_DWORD *)(v226 + 16);
      v229 = *(_DWORD *)(v227 + 16);
      if ( v229 >= v228
        && (v229 > v228 || *(_DWORD *)(v227 + 20) > *(_DWORD *)(v226 + 20))
        && (v230 = *(_QWORD *)&v210->m_items[0].m_data[40], v230 & 0xFFFFFFFFFFFFFFFCui64) )
      {
        v231 = *(_QWORD *)&v210->m_items[0].m_data[40] & 3i64;
        v232 = v230 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v232 = (unsigned __int64)v210;
        LOBYTE(v231) = 0;
      }
      *(_WORD *)(v232 + 66) |= (1 << v231) & 7;
    }
    v233 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex **)&v208->m_items[0].m_data[32];
    v256.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v208;
    v256.m_index = 2;
    v[0] = v233;
    if ( conform )
    {
      v234 = v7->m_stack.m_size + 3;
      v235 = v7->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v235 >= v234 )
      {
        LODWORD(location) = 0;
      }
      else
      {
        v236 = 2 * v235;
        if ( v234 < v236 )
          v234 = v236;
        hkArrayUtil::_reserve(
          (hkResult *)&location,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v7->m_stack,
          v234,
          16);
        if ( (_DWORD)location == 1 )
        {
          v7->m_status.m_storage = 1;
          if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
          {
            v181 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' | 1;
            goto LABEL_201;
          }
LABEL_202:
          v12->m_type.m_storage = 10;
          v12->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e;
          return v12;
        }
      }
      v237 = v7->m_stack.m_size;
      LODWORD(v260) = 0;
      v7->m_stack.m_size = v237 + 3;
      v238 = v260;
      v239 = &v7->m_stack.m_data[v237].m_triangle;
      LODWORD(v260) = 0;
      *v239 = v208;
      v239[1] = v238;
      v240 = v260;
      v239[2] = v210;
      v239[3] = v240;
      v241 = *(_QWORD *)&rootArg.m_index;
      v239[4] = v184;
      v239[5] = v241;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::flushConform(v7);
      v242 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
               v7,
               &v262,
               &v256,
               v[0]);
      v208 = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>::Pool *)v242->m_triangle;
      v243 = *(_QWORD *)&v242->m_index;
    }
    else
    {
      v243 = *(_QWORD *)&v256.m_index;
    }
    v7->m_roots[((signed __int64)(*(_DWORD *)(*(_QWORD *)&v208->m_items[0].m_data[32] + 16i64)
                                + *(_DWORD *)(*(_QWORD *)&v208->m_items[0].m_data[24] + 16i64)
                                + 2 * *(_DWORD *)(*(_QWORD *)&v208->m_items[0].m_data[16] + 16i64)) >> 13)
              + (((signed __int64)(*(_DWORD *)(*(_QWORD *)&v208->m_items[0].m_data[32] + 20i64)
                                 + *(_DWORD *)(*(_QWORD *)&v208->m_items[0].m_data[24] + 20i64)
                                 + 2 * *(_DWORD *)(*(_QWORD *)&v208->m_items[0].m_data[16] + 20i64)) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v208;
    *(_WORD *)&v208->m_items[0].m_data[66] |= 8u;
    v12->m_type.m_storage = 0;
    v12->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v208;
    *(_QWORD *)&v12->m_edge.m_index = v243;
    return v12;
  }
  v13 = v8 - 1;
  if ( !v13 )
  {
    v16 = rootArg.m_index;
    v17 = rootArg.m_triangle;
    if ( !edgeSplit )
    {
      if ( (v18 = rootArg.m_triangle->m_vertices[rootArg.m_index],
            v19 = rootArg.m_triangle->m_vertices[(9i64 >> 2 * LOBYTE(rootArg.m_index)) & 3],
            v20 = v18->m_x,
            v21 = v19->m_x,
            v20 >= v21)
        && (v20 > v21 || v18->m_y > v19->m_y)
        && (v22 = rootArg.m_triangle->m_links[rootArg.m_index], v22 & 0xFFFFFFFFFFFFFFFCui64) )
      {
        v23 = rootArg.m_triangle->m_links[rootArg.m_index] & 3;
        v24 = v22 & 0xFFFFFFFFFFFFFFFCui64;
      }
      else
      {
        v24 = (unsigned __int64)rootArg.m_triangle;
        LOBYTE(v23) = rootArg.m_index;
      }
      if ( (1 << v23) & 7 & *(_BYTE *)(v24 + 66) )
      {
        v12->m_type.m_storage = 2;
        v12->m_edge = v11;
        return v12;
      }
    }
    v25 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_vertices);
    v254 = v25;
    if ( v25 )
    {
      *(_DWORD *)&v25->m_items[0].m_data[20] = v9;
      v26 = 2 * v16;
      *(_DWORD *)&v25->m_items[0].m_data[16] = v265;
      LODWORD(location) = 2 * v16;
      *(_QWORD *)&v25->m_items[0].m_data[24] = -3i64;
      v27 = v17->m_vertices[(9i64 >> 2 * (unsigned __int8)v16) & 3];
      v28 = v17->m_vertices[v16];
      v29 = v27->m_x;
      v252 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)&v17->m_vertices[v16];
      v30 = v28->m_x;
      if ( v30 >= v29 && (v30 > v29 || v28->m_y > v27->m_y) && (v31 = v17->m_links[v16], v31 & 0xFFFFFFFFFFFFFFFCui64) )
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
      v253 = (unsigned __int8)v34 & (1 << v32) & 7;
      *(_WORD *)(v33 + 66) = v34 & (~((unsigned __int8)v34 & (1 << v32) & 7) | 0xFFF8);
      v261.m_values[0].m_hasData = 0;
      v261.m_values[0].m_data.m_tags.m_data = v261.m_values[0].m_data.m_tags.m_storage;
      v261.m_values[0].m_data.m_tags.m_size = 0;
      v261.m_values[0].m_data.m_tags.m_capacityAndFlags = -2147483646;
      v261.m_values[1].m_hasData = 0;
      v261.m_values[1].m_data.m_tags.m_size = 0;
      v261.m_values[1].m_data.m_tags.m_data = v261.m_values[1].m_data.m_tags.m_storage;
      v261.m_values[1].m_data.m_tags.m_capacityAndFlags = -2147483646;
      if ( (unsigned __int8)v34 & (1 << v32) & 7 )
      {
        _mm_store_si128((__m128i *)v, (__m128i)v11);
        hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::backupBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
          (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *)&v7->m_edgeDataPolicy,
          v7,
          (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
          &v261);
        v26 = (char)location;
      }
      v35 = v17->m_links[v16];
      v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v17->m_links[v16];
      if ( v35 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        v36 = v35;
        v37 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)(v35 & 0xFFFFFFFFFFFFFFFCui64);
        v250 = v37;
        v248 = v36 & 3;
        v38 = (18 >> v26) & 3;
        v258 = v38;
        v39 = v17->m_vertices[(9i64 >> 2 * ((18 >> v26) & 3u)) & 3];
        v40 = v17->m_vertices[v38];
        v41 = v39->m_x;
        v42 = v40->m_x;
        if ( v42 >= v41 && (v42 > v41 || v40->m_y > v39->m_y) && (v43 = v17->m_links[v38], v43 & 0xFFFFFFFFFFFFFFFCui64) )
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
        v47 = (unsigned __int8)v46 & (1 << v44) & 7;
        v247 = v47;
        *(_WORD *)(v45 + 66) = v46 & (~(_WORD)v47 | 0xFFF8);
        v251 = 2 * v248;
        v48 = (18 >> 2 * v248) & 3;
        v249 = (18 >> 2 * v248) & 3;
        v49 = v37[v48 + 2];
        v256.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v48;
        v50 = v37[((9i64 >> 2 * ((18 >> 2 * v248) & 3u)) & 3) + 2];
        v51 = (int)v49->m_vertices[0];
        v52 = (int)v50->m_vertices[0];
        if ( v51 >= v52
          && (v51 > v52 || SHIDWORD(v49->m_vertices[0]) > SHIDWORD(v50->m_vertices[0]))
          && (v53 = (unsigned __int64)v37[v48 + 5], v53 & 0xFFFFFFFFFFFFFFFCui64) )
        {
          v54 = (unsigned __int64)v37[v48 + 5] & 3;
          v55 = v53 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v55 = (unsigned __int64)v37;
          LOBYTE(v54) = (18 >> 2 * v248) & 3;
        }
        v56 = *(_WORD *)(v55 + 66);
        v57 = 1 << v54;
        v58 = (char)location;
        resulta.m_enum = (unsigned __int8)v56 & v57 & 7;
        *(_WORD *)(v55 + 66) = v56 & (~LOWORD(resulta.m_enum) | 0xFFF8);
        v59 = *v252;
        v257 = v17->m_vertices[(18i64 >> v58) & 3];
        v60 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
        if ( v60 )
        {
          v61 = (__int64)v257;
          *(_QWORD *)&v60->m_items[0].m_data[24] = v59;
          *(_DWORD *)&v60->m_items[0].m_data[66] = 0;
          *(_QWORD *)&v60->m_items[0].m_data[16] = v61;
          v62 = (__int64)v254;
          *(_QWORD *)&v60->m_items[0].m_data[32] = v254;
          v63 = *(_QWORD *)&v60->m_items[0].m_data[16];
          v64 = v62;
          LODWORD(v62) = v59->m_vertices[0];
          v65 = *(_DWORD *)(v64 + 20) + HIDWORD(v59->m_vertices[0]) + 2 * *(_DWORD *)(v63 + 20);
          v66 = v264;
          v264->m_roots[((signed __int64)(*(_DWORD *)(v64 + 16) + (signed int)v62 + 2 * *(_DWORD *)(v63 + 16)) >> 13)
                      + (((signed __int64)v65 >> 9) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v60;
          *(_WORD *)&v60->m_items[0].m_data[66] |= 8u;
        }
        else
        {
          v66 = v264;
        }
        v259 = v250[(signed int)v248 + 2];
        v257 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v250[((18i64 >> v251) & 3) + 2];
        v67 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v66->m_mesh.m_triangles);
        if ( v67 )
        {
          v68 = (__int64)v257;
          *(_DWORD *)&v67->m_items[0].m_data[66] = 0;
          *(_QWORD *)&v67->m_items[0].m_data[16] = v68;
          *(_QWORD *)&v67->m_items[0].m_data[24] = v259;
          v69 = (__int64)v254;
          *(_QWORD *)&v67->m_items[0].m_data[32] = v254;
          v66->m_roots[((signed __int64)(*(_DWORD *)(v69 + 16)
                                       + *(_DWORD *)(*(_QWORD *)&v67->m_items[0].m_data[24] + 16i64)
                                       + 2 * *(_DWORD *)(*(_QWORD *)&v67->m_items[0].m_data[16] + 16i64)) >> 13)
                     + (((signed __int64)(*(_DWORD *)(v69 + 20)
                                        + *(_DWORD *)(*(_QWORD *)&v67->m_items[0].m_data[24] + 20i64)
                                        + 2 * *(_DWORD *)(*(_QWORD *)&v67->m_items[0].m_data[16] + 20i64)) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v67;
          *(_WORD *)&v67->m_items[0].m_data[66] |= 8u;
        }
        if ( v60 && v67 )
        {
          v70 = v250;
          v71 = v252;
          v72 = (signed int)v248;
          v73 = v258;
          *(_WORD *)&v60->m_items[0].m_data[66] ^= (*((_WORD *)v17 + 33) ^ *(_WORD *)&v60->m_items[0].m_data[66]) & 0x10;
          *(_WORD *)&v60->m_items[0].m_data[66] = *((_WORD *)v17 + 33) ^ (*(_WORD *)&v60->m_items[0].m_data[66] ^ *((_WORD *)v17 + 33)) & 0x1F;
          *(_WORD *)&v60->m_items[0].m_data[68] = v17->m_sets;
          *(_WORD *)&v67->m_items[0].m_data[66] ^= (*(_WORD *)&v67->m_items[0].m_data[66] ^ *((_WORD *)v70 + 33)) & 0x10;
          *(_WORD *)&v67->m_items[0].m_data[66] = *((_WORD *)v70 + 33) ^ (*(_WORD *)&v67->m_items[0].m_data[66] ^ *((_WORD *)v70 + 33)) & 0x1F;
          *(_WORD *)&v67->m_items[0].m_data[68] = *((_WORD *)v70 + 34);
          v74 = (__int64)v254;
          v70[v72 + 2] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v254;
          *v71 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v74;
          v75 = v17->m_links[v73] & 0xFFFFFFFFFFFFFFFCui64;
          v76 = v17->m_links[v73] & 3;
          *(_QWORD *)&v60->m_items[0].m_data[40] = v75 + (v17->m_links[v73] & 3);
          if ( v75 )
            *(_QWORD *)(v75 + 8i64 * v76 + 40) = v60;
          v77 = v256.m_triangle;
          v78 = (unsigned __int64)v70[(_QWORD)v256.m_triangle + 5] & 0xFFFFFFFFFFFFFFFCui64;
          v79 = (_QWORD)v70[(_QWORD)v256.m_triangle + 5] & 3;
          *(_QWORD *)&v67->m_items[0].m_data[40] = v78 + ((unsigned __int64)v70[(_QWORD)v256.m_triangle + 5] & 3);
          if ( v78 )
            *(_QWORD *)(v78 + 8i64 * v79 + 40) = v67;
          v80 = v[0];
          *(_QWORD *)&v60->m_items[0].m_data[48] = (char *)v70 + v248;
          v70[v72 + 5] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)&v60->m_items[0].m_data[1];
          *(_QWORD *)&v67->m_items[0].m_data[48] = (char *)v17 + rootArg.m_index;
          v80->m_next = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v67->m_items[0].m_data[1];
          *(_QWORD *)&v60->m_items[0].m_data[56] = (char *)v17 + (unsigned int)v73;
          v81 = v249;
          v17->m_links[v73] = (unsigned __int64)&v60->m_items[0].m_data[2];
          *(_QWORD *)&v67->m_items[0].m_data[56] = (char *)v70 + v81;
          v70[(_QWORD)v77 + 5] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)&v67->m_items[0].m_data[2];
          if ( v247 )
          {
            v82 = *(_QWORD *)&v60->m_items[0].m_data[24];
            v83 = *(_QWORD *)&v60->m_items[0].m_data[16];
            v84 = *(_DWORD *)(v83 + 16);
            v85 = *(_DWORD *)(v82 + 16);
            if ( v84 >= v85
              && (v84 > v85 || *(_DWORD *)(v83 + 20) > *(_DWORD *)(v82 + 20))
              && (v86 = *(_QWORD *)&v60->m_items[0].m_data[40], v86 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v87 = *(_QWORD *)&v60->m_items[0].m_data[40] & 3i64;
              v88 = v86 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v88 = (unsigned __int64)v60;
              LOBYTE(v87) = 0;
            }
            *(_WORD *)(v88 + 66) |= (1 << v87) & 7;
          }
          if ( resulta.m_enum )
          {
            v89 = *(_QWORD *)&v67->m_items[0].m_data[24];
            v90 = *(_QWORD *)&v67->m_items[0].m_data[16];
            v91 = *(_DWORD *)(v90 + 16);
            v92 = *(_DWORD *)(v89 + 16);
            if ( v91 >= v92
              && (v91 > v92 || *(_DWORD *)(v90 + 20) > *(_DWORD *)(v89 + 20))
              && (v93 = *(_QWORD *)&v67->m_items[0].m_data[40], v93 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v94 = *(_QWORD *)&v67->m_items[0].m_data[40] & 3i64;
              v95 = v93 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v95 = (unsigned __int64)v67;
              LOBYTE(v94) = 0;
            }
            *(_WORD *)(v95 + 66) |= (1 << v94) & 7;
          }
          if ( edgeSplit && v253 )
          {
            v96 = *(_QWORD *)&v60->m_items[0].m_data[32];
            v97 = *(_QWORD *)&v60->m_items[0].m_data[24];
            v98 = *(_DWORD *)(v97 + 16);
            v99 = *(_DWORD *)(v96 + 16);
            if ( v98 >= v99
              && (v98 > v99 || *(_DWORD *)(v97 + 20) > *(_DWORD *)(v96 + 20))
              && (v100 = *(_QWORD *)&v60->m_items[0].m_data[48], v100 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v101 = *(_QWORD *)&v60->m_items[0].m_data[48] & 3i64;
              v102 = v100 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v102 = (unsigned __int64)v60;
              LOBYTE(v101) = 1;
            }
            *(_WORD *)(v102 + 66) |= (1 << v101) & 7;
            v103 = *(_QWORD *)&v67->m_items[0].m_data[32];
            v104 = *(_QWORD *)&v67->m_items[0].m_data[24];
            v105 = *(_DWORD *)(v104 + 16);
            v106 = *(_DWORD *)(v103 + 16);
            if ( v105 >= v106
              && (v105 > v106 || *(_DWORD *)(v104 + 20) > *(_DWORD *)(v103 + 20))
              && (v107 = *(_QWORD *)&v67->m_items[0].m_data[48], v107 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v108 = *(_QWORD *)&v67->m_items[0].m_data[48] & 3i64;
              v109 = v107 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v109 = (unsigned __int64)v67;
              LOBYTE(v108) = 1;
            }
            v110 = *(_WORD *)(v109 + 66);
            LODWORD(v[1]) = 1;
            v111 = v264;
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v60;
            _mm_store_si128((__m128i *)v, *(__m128i *)v);
            *(_WORD *)(v109 + 66) = v110 ^ ((unsigned __int8)v110 ^ (unsigned __int8)(v110 | (1 << v108))) & 7;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *)&v264->m_edgeDataPolicy,
              v264,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v261);
            v112 = *(_QWORD *)&v67->m_items[0].m_data[48];
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)(*(_QWORD *)&v67->m_items[0].m_data[48] & 0xFFFFFFFFFFFFFFFCui64);
            LODWORD(v[1]) = v112 & 3;
            _mm_store_si128((__m128i *)v, *(__m128i *)v);
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *)&v111->m_edgeDataPolicy,
              v111,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v261);
            v70 = v250;
          }
          else
          {
            v111 = v264;
          }
          if ( conform )
          {
            v113 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v111->m_stack;
            v114 = v111->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
            v115 = v111->m_stack.m_size + 4;
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)&v111->m_stack;
            if ( v114 < v115 )
            {
              v116 = 2 * v114;
              if ( v115 < v116 )
                v115 = v116;
              hkArrayUtil::_reserve(
                &resulta,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v111->m_stack,
                v115,
                16);
              if ( resulta.m_enum == 1 )
              {
                v111->m_status.m_storage = 1;
                if ( `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1 )
                {
LABEL_93:
                  v12->m_type.m_storage = 10;
                  v12->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e;
                  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::EdgeDataState::~EdgeDataState(&v261);
                  return v12;
                }
                v117 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' | 1;
LABEL_92:
                `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' = v117;
                *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
                DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
                goto LABEL_93;
              }
              v113 = v[0];
            }
            v118 = SLODWORD(v113->m_prev);
            LODWORD(v[1]) = 0;
            LODWORD(v113->m_prev) = v118 + 4;
            v119 = (signed __int64)v113->m_next + 16 * v118;
            v120 = (char)location;
            *(_QWORD *)v119 = v17;
            v121 = 9 >> v251;
            *(_DWORD *)(v119 + 8) = (9 >> v120) & 3;
            v122 = v[1];
            *(_QWORD *)(v119 + 16) = v70;
            LODWORD(v[1]) = 0;
            *(_DWORD *)(v119 + 24) = v121 & 3;
            *(_QWORD *)(v119 + 32) = v60;
            v7 = v264;
            *(_QWORD *)(v119 + 40) = v122;
            v123 = v[1];
            *(_QWORD *)(v119 + 48) = v67;
            *(_QWORD *)(v119 + 56) = v123;
LABEL_142:
            v176 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)*v252;
            hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::flushConform(v7);
            v177 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateExistingVertex(
                     v7,
                     &v263,
                     &rootArg,
                     v176);
            v178 = v177->m_triangle;
            v179 = *(_QWORD *)&v177->m_index;
            v12->m_type.m_storage = 0;
            v12->m_edge.m_triangle = v178;
            *(_QWORD *)&v12->m_edge.m_index = v179;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::EdgeDataState::~EdgeDataState(&v261);
            return v12;
          }
LABEL_143:
          v180 = *(_QWORD *)&rootArg.m_index;
          v12->m_type.m_storage = 0;
          v12->m_edge.m_triangle = v17;
          *(_QWORD *)&v12->m_edge.m_index = v180;
          hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::EdgeDataState::~EdgeDataState(&v261);
          return v12;
        }
      }
      else
      {
        v124 = (18 >> v26) & 3;
        resulta.m_enum = (18 >> v26) & 3;
        v125 = v17->m_vertices[v124];
        v126 = v17->m_vertices[(9i64 >> 2 * ((18 >> v26) & 3u)) & 3];
        v127 = v125->m_x;
        v128 = v126->m_x;
        if ( v127 >= v128
          && (v127 > v128 || v125->m_y > v126->m_y)
          && (v129 = v17->m_links[v124], v129 & 0xFFFFFFFFFFFFFFFCui64) )
        {
          v130 = v17->m_links[v124] & 3;
          v131 = v129 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v131 = (unsigned __int64)v17;
          LOBYTE(v130) = (18 >> v26) & 3;
        }
        v132 = *(_WORD *)(v131 + 66);
        v133 = (18i64 >> (char)location) & 3;
        v247 = (unsigned __int8)v132 & (1 << v130) & 7;
        *(_WORD *)(v131 + 66) = v132 & (~(_WORD)v247 | 0xFFF8);
        v256.m_triangle = *v252;
        v[0] = v17->m_vertices[v133];
        v134 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_mesh.m_triangles);
        if ( v134 )
        {
          v135 = v[0];
          *(_DWORD *)&v134->m_items[0].m_data[66] = 0;
          *(_QWORD *)&v134->m_items[0].m_data[16] = v135;
          *(_QWORD *)&v134->m_items[0].m_data[24] = v256.m_triangle;
          v136 = (__int64)v254;
          *(_QWORD *)&v134->m_items[0].m_data[32] = v254;
          v137 = resulta.m_enum;
          v7->m_roots[((signed __int64)(*(_DWORD *)(v136 + 16)
                                      + *(_DWORD *)(*(_QWORD *)&v134->m_items[0].m_data[24] + 16i64)
                                      + 2 * *(_DWORD *)(*(_QWORD *)&v134->m_items[0].m_data[16] + 16i64)) >> 13)
                    + (((signed __int64)(*(_DWORD *)(v136 + 20)
                                       + *(_DWORD *)(*(_QWORD *)&v134->m_items[0].m_data[24] + 20i64)
                                       + 2 * *(_DWORD *)(*(_QWORD *)&v134->m_items[0].m_data[16] + 20i64)) >> 9) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v134;
          *(_WORD *)&v134->m_items[0].m_data[66] |= 8u;
          v138 = *(_WORD *)&v134->m_items[0].m_data[66] ^ (*(_WORD *)&v134->m_items[0].m_data[66] ^ *((_WORD *)v17 + 33)) & 0x10;
          *(_WORD *)&v134->m_items[0].m_data[66] = v138;
          *(_WORD *)&v134->m_items[0].m_data[66] = *((_WORD *)v17 + 33) ^ (*((_WORD *)v17 + 33) ^ v138) & 0x1F;
          v139 = v252;
          *(_WORD *)&v134->m_items[0].m_data[68] = v17->m_sets;
          *v139 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)v136;
          v140 = v17->m_links[v137] & 0xFFFFFFFFFFFFFFFCui64;
          v141 = v17->m_links[v137] & 3;
          *(_QWORD *)&v134->m_items[0].m_data[40] = v140 + (v17->m_links[v137] & 3);
          if ( v140 )
            *(_QWORD *)(v140 + 8i64 * v141 + 40) = v134;
          if ( `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1 )
          {
            v143 = DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e);
            v142 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e;
          }
          else
          {
            v142 = 0i64;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
            v143 = 0i64;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
          }
          *(_QWORD *)&v134->m_items[0].m_data[48] = v142 + v143;
          if ( (_QWORD)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e )
            *(_QWORD *)(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e
                      + 8i64
                      * SDWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e)
                      + 40) = (char *)v134 + 1;
          *(_QWORD *)&v134->m_items[0].m_data[56] = (char *)v17 + (unsigned int)v137;
          v17->m_links[v137] = (unsigned __int64)&v134->m_items[0].m_data[2];
          if ( v247 )
          {
            v144 = *(_QWORD *)&v134->m_items[0].m_data[24];
            v145 = *(_QWORD *)&v134->m_items[0].m_data[16];
            v146 = *(_DWORD *)(v145 + 16);
            v147 = *(_DWORD *)(v144 + 16);
            if ( v146 >= v147
              && (v146 > v147 || *(_DWORD *)(v145 + 20) > *(_DWORD *)(v144 + 20))
              && (v148 = *(_QWORD *)&v134->m_items[0].m_data[40], v148 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v149 = *(_QWORD *)&v134->m_items[0].m_data[40] & 3i64;
              v150 = v148 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v150 = (unsigned __int64)v134;
              LOBYTE(v149) = 0;
            }
            *(_WORD *)(v150 + 66) ^= ((unsigned __int8)*(_WORD *)(v150 + 66) ^ (unsigned __int8)(*(unsigned __int16 *)(v150 + 66) | (1 << v149))) & 7;
          }
          if ( edgeSplit && v253 )
          {
            v151 = *(_QWORD *)&v134->m_items[0].m_data[32];
            v152 = *(_QWORD *)&v134->m_items[0].m_data[24];
            v153 = *(_DWORD *)(v152 + 16);
            v154 = *(_DWORD *)(v151 + 16);
            if ( v153 >= v154
              && (v153 > v154 || *(_DWORD *)(v152 + 20) > *(_DWORD *)(v151 + 20))
              && (v155 = *(_QWORD *)&v134->m_items[0].m_data[48], v155 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v156 = *(_QWORD *)&v134->m_items[0].m_data[48] & 3i64;
              v157 = v155 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v157 = (unsigned __int64)v134;
              LOBYTE(v156) = 1;
            }
            *(_WORD *)(v157 + 66) |= (1 << v156) & 7;
            v158 = *(_QWORD *)&v134->m_items[0].m_data[56];
            v159 = 2 * (v158 & 3);
            v160 = v158 & 0xFFFFFFFFFFFFFFFCui64;
            LODWORD(v157) = (9 >> v159) & 3;
            v161 = *(_QWORD *)((v158 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v157 + 16);
            v162 = *(_QWORD *)((v158 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((9i64 >> 2 * ((9 >> v159) & 3u)) & 3) + 16);
            v163 = *(_DWORD *)(v161 + 16);
            v164 = *(_DWORD *)(v162 + 16);
            if ( v163 >= v164
              && (v163 > v164 || *(_DWORD *)(v161 + 20) > *(_DWORD *)(v162 + 20))
              && (v165 = *(_QWORD *)(v160 + 8i64 * (signed int)v157 + 40), v165 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v157 = *(_QWORD *)(v160 + 8i64 * (signed int)v157 + 40) & 3i64;
              v166 = v165 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v166 = v160;
            }
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)v134;
            LODWORD(v[1]) = 1;
            _mm_store_si128((__m128i *)v, *(__m128i *)v);
            *(_WORD *)(v166 + 66) |= (1 << v157) & 7;
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *)&v7->m_edgeDataPolicy,
              v7,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v261);
            v167 = *(_QWORD *)&v134->m_items[0].m_data[56];
            v[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *)(*(_QWORD *)&v134->m_items[0].m_data[56] & 0xFFFFFFFFFFFFFFFCui64);
            LODWORD(v[1]) = v167 & 3;
            _mm_store_si128((__m128i *)v, *(__m128i *)v);
            hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(
              (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *)&v7->m_edgeDataPolicy,
              v7,
              (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *)v,
              &v261);
          }
          if ( !conform )
            goto LABEL_143;
          v168 = v7->m_stack.m_size + 2;
          v169 = v7->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v169 >= v168 )
            goto LABEL_206;
          v170 = 2 * v169;
          if ( v168 < v170 )
            v168 = v170;
          hkArrayUtil::_reserve(
            &resulta,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v7->m_stack,
            v168,
            16);
          if ( resulta.m_enum != 1 )
          {
LABEL_206:
            v171 = v7->m_stack.m_size;
            LODWORD(v[1]) = 0;
            v172 = v171 + 2;
            v173 = v171;
            LOBYTE(v171) = (_BYTE)location;
            v7->m_stack.m_size = v172;
            v174 = v[1];
            v175 = (signed __int64)&v7->m_stack.m_data[v173];
            *(_QWORD *)v175 = v17;
            *(_DWORD *)(v175 + 8) = (9 >> v171) & 3;
            *(_QWORD *)(v175 + 16) = v134;
            *(_QWORD *)(v175 + 24) = v174;
            goto LABEL_142;
          }
          v7->m_status.m_storage = 1;
        }
      }
      if ( `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1 )
        goto LABEL_93;
      v117 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' | 1;
      goto LABEL_92;
    }
    if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
    {
      v181 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' | 1;
LABEL_201:
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' = v181;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
      goto LABEL_202;
    }
    goto LABEL_202;
  }
  if ( v13 == 1 )
  {
    v14 = v11.m_triangle->m_vertices[(signed int)*(_OWORD *)&_mm_srli_si128((__m128i)v11, 8)];
    v15 = *((_QWORD *)v14 + 3);
    if ( v15 & 1 )
    {
      v12->m_type.m_storage = 1;
    }
    else
    {
      *((_QWORD *)v14 + 3) = v15 | 1;
      v12->m_type.m_storage = 0;
    }
    v12->m_edge = v11;
  }
  else
  {
    if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e) = 0;
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
    }
    result->m_type.m_storage = 11;
    result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *>::null'::`2'::e;
  }
  return v12;
}

// File Line: 1315
// RVA: 0xB68180
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex<hkaiSnapToOriginalEdgeCrossing<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>>>(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *result, int x, int y, bool conform)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v5; // rbx
  int v6; // edi
  int v7; // esi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v8; // rbp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v9; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Location resulta; // [rsp+40h] [rbp-38h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion v12; // [rsp+58h] [rbp-20h]

  v5 = result;
  v6 = y;
  v7 = x;
  v8 = this;
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
    this,
    &resulta,
    x,
    y);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
    v8,
    v5,
    v7,
    v6,
    conform,
    &resulta,
    0);
  if ( v5->m_type.m_storage == 2 )
  {
    resulta.m_edge.m_triangle = v5->m_edge.m_triangle;
    *(_QWORD *)&resulta.m_edge.m_index = *(_QWORD *)&v5->m_edge.m_index;
    resulta.m_type.m_storage = 1;
    v9 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertVertex(
           v8,
           &v12,
           v7,
           v6,
           conform,
           &resulta,
           1);
    *(_QWORD *)&v5->m_type.m_storage = *(_QWORD *)&v9->m_type.m_storage;
    v5->m_edge.m_triangle = v9->m_edge.m_triangle;
    *(_QWORD *)&v5->m_edge.m_index = *(_QWORD *)&v9->m_edge.m_index;
  }
  return v5;
}

// File Line: 1386
// RVA: 0xB69D30
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::insertEdge(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *result, int x0, int y0, int x1, int y1, bool conform, hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *data)
{
  int v8; // er12
  int v9; // er15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v10; // rsi
  unsigned __int64 v12; // rbx
  int v13; // ecx
  __int64 v14; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v15; // r9
  signed __int64 v16; // rax
  int v17; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v18; // r8
  __int64 v19; // rbx
  char v20; // cl
  signed __int64 v21; // r11
  __int64 v22; // rdx
  __int64 v23; // rax
  int v24; // er13
  __int64 v25; // r8
  __int64 v26; // rcx
  __int64 v27; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v28; // rax
  unsigned __int64 v29; // r10
  int v30; // edx
  signed __int64 v31; // rax
  signed int v32; // er13
  __int64 v33; // r9
  int v34; // ecx
  __int64 v35; // r15
  __int64 v36; // r8
  int v37; // eax
  __int64 v38; // rax
  signed __int64 v39; // rcx
  unsigned __int64 v40; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v41; // xmm0
  int v42; // eax
  int v43; // ecx
  __int64 v44; // rdx
  unsigned __int64 v45; // rdx
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v46; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v47; // r11
  int v48; // er9
  _QWORD *v49; // r10
  BOOL v50; // ecx
  signed int v51; // er15
  int v52; // eax
  int v53; // er9
  int v54; // eax
  __int128 v55; // xmm0
  char v56; // cl
  __int64 v57; // r8
  signed __int64 v58; // r8
  signed int v59; // edi
  signed int v60; // er14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v61; // xmm0
  bool v62; // zf
  __int64 v63; // r8
  int v64; // eax
  int v65; // ecx
  __int64 v66; // r8
  __int64 v67; // rax
  signed __int64 v68; // rcx
  unsigned __int64 v69; // rax
  __int64 v70; // r10
  char v71; // al
  char v72; // r13
  __int64 v73; // rcx
  signed __int64 v74; // rdx
  __m128i v75; // xmm0
  __int64 v76; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v77; // r9
  __int64 v78; // rcx
  __int64 v79; // rax
  __int64 v80; // rdx
  int v81; // er9
  int v82; // er12
  int v83; // eax
  int v84; // eax
  __int64 v85; // r15
  __int64 v86; // r13
  int v87; // edx
  __int64 v88; // rdx
  char v89; // si
  int v90; // er10
  int v91; // er11
  __int64 v92; // rcx
  int v93; // er8
  int v94; // er9
  __int64 v95; // r15
  __int64 v96; // r10
  __int64 v97; // rbx
  char v98; // cl
  __int64 v99; // rcx
  char v100; // r12
  __int64 v101; // r15
  __int64 v102; // rcx
  __int64 v103; // rsi
  __int64 v104; // r10
  int v105; // ebx
  unsigned __int64 v106; // r8
  signed __int64 v107; // rax
  __int64 v108; // r10
  __int64 v109; // r9
  char v110; // r15
  int v111; // ecx
  __int64 v112; // r11
  int v113; // edx
  unsigned __int64 v114; // rcx
  int v115; // edx
  __int64 v116; // r15
  __int64 v117; // r11
  int v118; // edx
  __int64 v119; // r8
  unsigned __int64 v120; // r8
  unsigned __int64 v121; // rdx
  int v122; // eax
  unsigned __int64 v123; // rdx
  hkResultEnum v124; // er13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v125; // rdx
  signed __int64 v126; // rax
  char v127; // r10
  __int64 v128; // rcx
  int v129; // er11
  int v130; // ebx
  unsigned __int64 v131; // r8
  __int64 v132; // r8
  char v133; // r9
  char v134; // r9
  __int64 v135; // rcx
  __int64 v136; // r15
  __int64 v137; // r8
  signed __int64 v138; // r12
  int v139; // eax
  __int64 v140; // rdx
  int v141; // ecx
  __int64 v142; // rdx
  unsigned __int64 v143; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v144; // r10
  int v145; // er9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v146; // rax
  _QWORD *v147; // r8
  BOOL v148; // er12
  signed int v149; // er15
  int v150; // eax
  int v151; // eax
  int v152; // er9
  int v153; // eax
  __m128i v154; // xmm0
  __int64 v155; // rdx
  char v156; // cl
  signed __int64 v157; // rdx
  signed int v158; // edi
  signed int v159; // er14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge edge; // [rsp+30h] [rbp-B9h]
  __int64 v161; // [rsp+40h] [rbp-A9h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v0; // [rsp+48h] [rbp-A1h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge v163; // [rsp+50h] [rbp-99h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Location resulta; // [rsp+60h] [rbp-89h]
  __m128i v165; // [rsp+80h] [rbp-69h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *v1[2]; // [rsp+90h] [rbp-59h]
  __m128i v167; // [rsp+A0h] [rbp-49h]
  __m128i v168; // [rsp+B0h] [rbp-39h]
  __m128i v169; // [rsp+C0h] [rbp-29h]
  __m128i v170; // [rsp+D0h] [rbp-19h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v171; // [rsp+130h] [rbp+47h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Insertion *v172; // [rsp+138h] [rbp+4Fh]
  hkResult v173; // [rsp+140h] [rbp+57h]
  int v174; // [rsp+148h] [rbp+5Fh]

  v174 = y0;
  v173.m_enum = x0;
  v172 = result;
  v171 = this;
  v8 = x1;
  v9 = y1;
  v10 = result;
  if ( x0 == x1 && y0 == y1 )
  {
    if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
    }
    result->m_type.m_storage = 9;
    result->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e;
    return result;
  }
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
    this,
    &resulta,
    x0,
    y0);
  if ( resulta.m_type.m_storage != 2 )
  {
    if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
    {
      *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
      `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
    }
    v10->m_type.m_storage = 6;
    v10->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e;
    return v10;
  }
  edge = resulta.m_edge;
  v12 = (unsigned __int64)resulta.m_edge.m_triangle;
  v13 = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)resulta.m_edge, 8));
  v14 = v13;
  v15 = resulta.m_edge.m_triangle->m_vertices[v13];
  v16 = 9i64 >> 2 * (unsigned __int8)v13;
  v17 = v15->m_x;
  v0 = resulta.m_edge.m_triangle->m_vertices[v14];
  v18 = resulta.m_edge.m_triangle->m_vertices[v16 & 3];
  if ( (v9 - v15->m_y) * (signed __int64)(v18->m_x - v17) - (v8 - v17) * (signed __int64)(v18->m_y - v15->m_y) >= 0 )
  {
    LODWORD(v21) = edge.m_index;
  }
  else
  {
    do
    {
      v19 = *(_QWORD *)(v12 + 8 * v14 + 40);
      v20 = v19;
      v12 = v19 & 0xFFFFFFFFFFFFFFFCui64;
      LODWORD(v21) = (9 >> 2 * (v20 & 3)) & 3;
      v14 = (signed int)v21;
      edge.m_index = (9 >> 2 * (v20 & 3)) & 3;
      v22 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v20 & 3)) & 3u)) & 3) + 16);
      v23 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 16);
    }
    while ( (v9 - *(_DWORD *)(v23 + 20)) * (signed __int64)(*(_DWORD *)(v22 + 16) - *(_DWORD *)(v23 + 16))
          - (v8 - *(_DWORD *)(v23 + 16)) * (signed __int64)(*(_DWORD *)(v22 + 20) - *(_DWORD *)(v23 + 20)) < 0 );
    edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v12;
  }
  if ( !v12 )
    goto LABEL_17;
  while ( 1 )
  {
    v24 = (18 >> 2 * v21) & 3;
    v25 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * ((18 >> 2 * v21) & 3u)) & 3) + 16);
    v26 = *(_QWORD *)(v12 + 8i64 * v24 + 16);
    if ( (v9 - *(_DWORD *)(v26 + 20)) * (signed __int64)(*(_DWORD *)(v25 + 16) - *(_DWORD *)(v26 + 16))
       - (v8 - *(_DWORD *)(v26 + 16)) * (signed __int64)(*(_DWORD *)(v25 + 20) - *(_DWORD *)(v26 + 20)) > 0 )
      break;
    v27 = *(_QWORD *)(v12 + 8i64 * v24 + 40);
    LODWORD(v21) = v27 & 3;
    v12 = v27 & 0xFFFFFFFFFFFFFFFCui64;
    edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v12;
    edge.m_index = v21;
    if ( !v12 )
      goto LABEL_17;
  }
  if ( !v12 )
    goto LABEL_17;
  v29 = v12;
  v167.m128i_i64[0] = (unsigned int)(2 * v21);
  v30 = (9 >> 2 * v21) & 3;
  v31 = ((9i64 >> 2 * (unsigned __int8)v21) & 3) + 2;
  v32 = (9 >> 2 * v21) & 3;
  x1 = (9 >> 2 * v21) & 3;
  v33 = *(_QWORD *)(v12 + 8 * v31);
  v163.m_index = (9 >> 2 * v21) & 3;
  v165.m128i_i64[0] = v12 + 8 * v31;
  if ( *(_DWORD *)(v33 + 16) != v8 || *(_DWORD *)(v33 + 20) != v9 )
  {
    if ( v8 == v173.m_enum )
    {
      if ( !v8 )
      {
        v62 = v9 == v174;
        if ( v9 < v174 )
        {
LABEL_17:
          if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
          {
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
          }
          v10->m_type.m_storage = 8;
LABEL_20:
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e;
          v28 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)*((_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e + 1);
          goto LABEL_21;
        }
LABEL_65:
        if ( v62 )
        {
          if ( v9 )
          {
            if ( v9 == 0x7FFFFF && v8 < v173.m_enum )
              goto LABEL_17;
          }
          else if ( v8 > v173.m_enum )
          {
            goto LABEL_17;
          }
        }
        v161 = v12 + 8 * (((9i64 >> 2 * (unsigned __int8)v30) & 3) + 2);
        v63 = *(_QWORD *)v161;
        v1[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)(v12 + 8 * (v30 + 2i64));
        if ( (v9 - v1[0]->m_next->m_y) * (signed __int64)(*(_DWORD *)(v63 + 16) - v1[0]->m_next->m_x)
           - (v8 - v1[0]->m_next->m_x) * (signed __int64)(*(_DWORD *)(v63 + 20) - v1[0]->m_next->m_y) < 0 )
        {
          do
          {
            v64 = v1[0]->m_next->m_x;
            v65 = *(_DWORD *)(*(_QWORD *)v161 + 16i64);
            if ( v64 < v65 || v64 <= v65 && v1[0]->m_next->m_y <= *(_DWORD *)(*(_QWORD *)v161 + 20i64) )
            {
              v66 = v32;
            }
            else
            {
              v66 = v32;
              v67 = *(_QWORD *)(v29 + 8i64 * v32 + 40);
              if ( v67 & 0xFFFFFFFFFFFFFFFCui64 )
              {
                v68 = *(_QWORD *)(v29 + 8i64 * v32 + 40) & 3i64;
                v69 = v67 & 0xFFFFFFFFFFFFFFFCui64;
                goto LABEL_79;
              }
            }
            v69 = v29;
            LOBYTE(v68) = v32;
LABEL_79:
            if ( (unsigned __int8)(1 << v68) & (unsigned __int8)*(_WORD *)(v69 + 184) & 7 )
            {
              v78 = *(_QWORD *)(v29 + 8i64 * v32 + 16);
              if ( (v9 - *(_DWORD *)(v78 + 20)) * (signed __int64)(v173.m_enum - *(_DWORD *)(v78 + 16)) == (v174 - *(_DWORD *)(v78 + 20)) * (signed __int64)(v8 - *(_DWORD *)(v78 + 16)) )
                goto LABEL_95;
              v79 = *(_QWORD *)(v29 + 8 * ((9i64 >> 2 * (unsigned __int8)v32) & 3) + 16);
              if ( (v9 - *(_DWORD *)(v79 + 20)) * (signed __int64)(v173.m_enum - *(_DWORD *)(v79 + 16)) == (v174 - *(_DWORD *)(v79 + 20)) * (signed __int64)(v8 - *(_DWORD *)(v79 + 16)) )
              {
                LODWORD(resulta.m_edge.m_triangle) = (9 >> 2 * v32) & 3;
                goto LABEL_93;
              }
              v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v163.m_index;
              v10->m_type.m_storage = 3;
              v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
LABEL_21:
              *(_QWORD *)&v10->m_edge.m_index = v28;
              return v10;
            }
            v70 = *(_QWORD *)(v29 + 8 * v66 + 40);
            v71 = v70;
            v29 = v70 & 0xFFFFFFFFFFFFFFFCui64;
            LODWORD(v161) = v71 & 3;
            v72 = 2 * (v71 & 3);
            v73 = *(_QWORD *)(v29 + 8 * ((18i64 >> 2 * (v71 & 3u)) & 3) + 16);
            v74 = (v9 - v0->m_y) * (signed __int64)(*(_DWORD *)(v73 + 16) - v0->m_x)
                - (v8 - v0->m_x) * (signed __int64)(*(_DWORD *)(v73 + 20) - v0->m_y);
            if ( v74 >= 0 )
            {
              if ( v74 <= 0 )
              {
                if ( *(_DWORD *)(v73 + 16) != v8 || *(_DWORD *)(v73 + 20) != v9 )
                {
                  LODWORD(resulta.m_edge.m_triangle) = (18 >> 2 * v161) & 3;
LABEL_93:
                  v28 = resulta.m_edge.m_triangle;
                  v10->m_type.m_storage = 4;
                  v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
                  goto LABEL_21;
                }
                v169.m128i_i64[0] = v29;
                v169.m128i_i32[2] = (18 >> v72) & 3;
                v75 = v169;
              }
              else
              {
                v170.m128i_i64[0] = v29;
                v170.m128i_i32[2] = (18 >> v72) & 3;
                v75 = v170;
              }
            }
            else
            {
              v168.m128i_i64[0] = v29;
              v168.m128i_i32[2] = (9 >> v72) & 3;
              v75 = v168;
            }
            _mm_store_si128((__m128i *)&v163, v75);
            v32 = v163.m_index;
            v29 = (unsigned __int64)v163.m_triangle;
            v161 = (__int64)v163.m_triangle + 8 * (((9i64 >> 2 * LOBYTE(v163.m_index)) & 3) + 2);
            v76 = *(_QWORD *)v161;
            v1[0] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)((char *)v163.m_triangle + 8 * ((signed int)v163.m_index + 2i64));
          }
          while ( (v9 - v1[0]->m_next->m_y) * (signed __int64)(*(_DWORD *)(v76 + 16) - v1[0]->m_next->m_x)
                - (v8 - v1[0]->m_next->m_x) * (signed __int64)(*(_DWORD *)(v76 + 20) - v1[0]->m_next->m_y) < 0 );
        }
        v77 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v29 + 8i64 * v32 + 16);
        v161 = (__int64)v77;
        if ( v0 == v77 )
        {
          if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
          {
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
          }
          v10->m_type.m_storage = 9;
          goto LABEL_20;
        }
        v80 = *(_QWORD *)(v29 + 8 * ((9i64 >> 2 * (unsigned __int8)v32) & 3) + 16);
        if ( (v9 - v77->m_y) * (signed __int64)(*(_DWORD *)(v80 + 16) - v77->m_x) != (v8 - v77->m_x)
                                                                                   * (signed __int64)(*(_DWORD *)(v80 + 20) - v77->m_y) )
        {
          if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
          {
            *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
            DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
            `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
          }
          v10->m_type.m_storage = 7;
          goto LABEL_20;
        }
        v81 = *(_DWORD *)(v161 + 16);
        if ( v81 != v8 || (v82 = *(_DWORD *)(v161 + 20), v82 != v9) )
        {
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v163.m_index;
          v10->m_type.m_storage = 7;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
          goto LABEL_21;
        }
        v83 = v0->m_x;
        if ( v83 == v81 && (!v83 || v83 == 0x7FFFFF) || (v84 = v0->m_y, v84 == v82) && (!v84 || v84 == 0x7FFFFF) )
        {
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v163.m_index;
          v10->m_type.m_storage = 8;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
          goto LABEL_21;
        }
        v85 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 16);
        v86 = *(_QWORD *)v165.m128i_i64[0];
        v87 = *(_DWORD *)(v85 + 16);
        if ( (v82 - *(_DWORD *)(v85 + 20)) * (signed __int64)(*(_DWORD *)(*(_QWORD *)v165.m128i_i64[0] + 16i64) - v87) == (v81 - v87) * (signed __int64)(*(_DWORD *)(*(_QWORD *)v165.m128i_i64[0] + 20i64) - *(_DWORD *)(v85 + 20)) )
        {
          LODWORD(resulta.m_edge.m_triangle) = x1;
          v28 = resulta.m_edge.m_triangle;
          v10->m_type.m_storage = 4;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v12;
          goto LABEL_21;
        }
        if ( (v82 - *(_DWORD *)(v85 + 20)) * (signed __int64)(*(_DWORD *)(v86 + 16) - v87)
           - (v81 - v87) * (signed __int64)(*(_DWORD *)(v86 + 20) - *(_DWORD *)(v85 + 20)) < 0 )
        {
LABEL_95:
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&v163.m_index;
          v10->m_type.m_storage = 4;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v29;
          goto LABEL_21;
        }
        v88 = v161;
        v173.m_enum = 0;
        if ( v86 != v161 )
        {
          v89 = v167.m128i_i8[0];
          do
          {
            v90 = *(_DWORD *)(v88 + 16);
            v91 = *(_DWORD *)(v88 + 20);
            v169.m128i_i64[0] = v12;
            _mm_store_si128(&v170, (__m128i)edge);
            v169.m128i_i32[2] = (9 >> v89) & 3;
            _mm_store_si128((__m128i *)&edge, v169);
            v92 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * ((9 >> v89) & 3u)) & 3) + 16);
            v12 = (unsigned __int64)edge.m_triangle;
            v93 = v0->m_y;
            v94 = v0->m_x;
            if ( (v90 - v94) * (signed __int64)(*(_DWORD *)(v92 + 20) - v93)
               - (v91 - v93) * (signed __int64)(*(_DWORD *)(v92 + 16) - v94) <= 0 )
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
                v97 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40);
                v98 = v97;
                v12 = v97 & 0xFFFFFFFFFFFFFFFCui64;
                LODWORD(v21) = (9 >> 2 * (v98 & 3)) & 3;
                v99 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v98 & 3)) & 3u)) & 3) + 16);
              }
              while ( v96 * (*(_DWORD *)(v99 + 20) - v93) - v95 * (*(_DWORD *)(v99 + 16) - v94) > 0 );
              edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v12;
              edge.m_index = v21;
            }
            v100 = v170.m128i_i8[8];
            v101 = v170.m128i_i64[0];
            v102 = *(_QWORD *)(v170.m128i_i64[0] + 8i64 * v170.m128i_i32[2] + 16);
            v103 = *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * (unsigned __int8)v21) & 3) + 16);
            v104 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 16);
            if ( (*(_DWORD *)(v103 + 20) - *(_DWORD *)(v102 + 20))
               * (signed __int64)(*(_DWORD *)(v104 + 16) - *(_DWORD *)(v102 + 16))
               - (*(_DWORD *)(v103 + 16) - *(_DWORD *)(v102 + 16))
               * (signed __int64)(*(_DWORD *)(v104 + 20) - *(_DWORD *)(v102 + 20)) <= 0 )
            {
              ++v173.m_enum;
            }
            else
            {
              v168.m128i_i64[0] = v170.m128i_i64[0];
              v105 = 0;
              v168.m128i_i32[2] = (9 >> 2 * v170.m128i_i8[8]) & 3;
              _mm_store_si128((__m128i *)&edge, v168);
              v106 = (unsigned __int64)edge.m_triangle;
              LODWORD(v107) = edge.m_index;
              if ( *(_QWORD *)(v101 + 8 * ((9i64 >> 2 * ((9 >> 2 * v100) & 3u)) & 3) + 16) != v103 )
              {
                do
                {
                  v108 = *(_QWORD *)(v106 + 8i64 * (signed int)v107 + 40);
                  if ( !(v108 & 0xFFFFFFFFFFFFFFFCui64) )
                    goto LABEL_178;
                  v109 = *(_QWORD *)(v106 + 8i64 * (signed int)v107 + 16);
                  v110 = 2 * v107;
                  v111 = *(_DWORD *)(v109 + 16);
                  v112 = *(_QWORD *)(v106 + 8 * ((9i64 >> 2 * (unsigned __int8)v107) & 3) + 16);
                  v113 = *(_DWORD *)(v112 + 16);
                  if ( v111 < v113 || v111 <= v113 && *(_DWORD *)(v109 + 20) <= *(_DWORD *)(v112 + 20) )
                  {
                    v114 = v106;
                  }
                  else
                  {
                    v107 = *(_QWORD *)(v106 + 8i64 * (signed int)v107 + 40) & 3i64;
                    v114 = v108 & 0xFFFFFFFFFFFFFFFCui64;
                  }
                  if ( (unsigned __int8)(1 << v107) & (unsigned __int8)*(_WORD *)(v114 + 184) & 7
                    || (v115 = (18 >> v110) & 3,
                        v116 = *(_QWORD *)((v108 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((18 >> 2 * (v108 & 3)) & 3) + 16),
                        v117 = *(_QWORD *)(v106 + 8i64 * v115 + 16),
                        v118 = *(_DWORD *)(v117 + 20),
                        (*(_DWORD *)(v109 + 16) - *(_DWORD *)(v117 + 16))
                      * (signed __int64)(*(_DWORD *)(v116 + 20) - v118)
                      - (*(_DWORD *)(v109 + 20) - v118)
                      * (signed __int64)(*(_DWORD *)(v116 + 16) - *(_DWORD *)(v117 + 16)) <= 0)
                    || (v119 = *(_QWORD *)((v108 & 0xFFFFFFFFFFFFFFFCui64) + 8 * (v108 & 3) + 16),
                        (*(_DWORD *)(v119 + 16) - *(_DWORD *)(v116 + 16))
                      * (signed __int64)(v118 - *(_DWORD *)(v116 + 20))
                      - (*(_DWORD *)(v119 + 20) - *(_DWORD *)(v116 + 20))
                      * (signed __int64)(*(_DWORD *)(v117 + 16) - *(_DWORD *)(v116 + 16)) <= 0) )
                  {
LABEL_178:
                    v106 = v108 & 0xFFFFFFFFFFFFFFFCui64;
                    ++v105;
                    edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v108 & 0xFFFFFFFFFFFFFFFCui64);
                    LODWORD(v107) = (9 >> 2 * (v108 & 3)) & 3;
                    edge.m_index = (9 >> 2 * (v108 & 3)) & 3;
                  }
                  else
                  {
                    hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::flipEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge>(
                      &v171->m_edgeDataPolicy,
                      &v163,
                      &edge);
                    if ( v105 )
                    {
                      v120 = v163.m_triangle->m_links[v163.m_index];
                      v121 = v163.m_triangle->m_links[v163.m_index] & 3;
                      v122 = *(_QWORD *)((v120 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((9 >> 2 * v121) & 3) + 40) & 3;
                      v167.m128i_i64[0] = *(_QWORD *)((v120 & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * ((9 >> 2 * v121) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
                      --v105;
                      v167.m128i_i32[2] = v122;
                      _mm_store_si128((__m128i *)&edge, v167);
                    }
                    else
                    {
                      v123 = v163.m_triangle->m_links[v163.m_index] & 3;
                      v165.m128i_i64[0] = v163.m_triangle->m_links[v163.m_index] & 0xFFFFFFFFFFFFFFFCui64;
                      v165.m128i_i32[2] = (18 >> 2 * v123) & 3;
                      _mm_store_si128((__m128i *)&edge, v165);
                    }
                    LODWORD(v107) = edge.m_index;
                    v106 = (unsigned __int64)edge.m_triangle;
                  }
                }
                while ( *(_QWORD *)(v106 + 8 * ((9i64 >> 2 * (unsigned __int8)v107) & 3) + 16) != v103 );
              }
              v124 = v173.m_enum;
              v125 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *)(*(_QWORD *)(v106 + 8i64 * ((9 >> 2 * v107) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64);
              v126 = *(_QWORD *)(v106 + 8i64 * ((9 >> 2 * v107) & 3) + 40) & 3i64;
              v1[0] = v125;
              LODWORD(v1[1]) = v126;
              _mm_store_si128((__m128i *)&edge, *(__m128i *)v1);
              if ( v124 )
              {
                v127 = 2 * v126;
                v128 = *((_QWORD *)&v125->m_x + ((18i64 >> 2 * (unsigned __int8)v126) & 3));
                v129 = v0->m_y;
                v130 = v0->m_x;
                if ( (*(_DWORD *)(v161 + 16) - v130) * (signed __int64)(*(_DWORD *)(v128 + 20) - v129)
                   - (*(_DWORD *)(v161 + 20) - v129) * (signed __int64)(*(_DWORD *)(v128 + 16) - v130) <= 0 )
                {
                  v134 = edge.m_index;
                  v131 = (unsigned __int64)edge.m_triangle;
                }
                else
                {
                  v131 = (unsigned __int64)edge.m_triangle;
                  do
                  {
                    v132 = *(_QWORD *)(v131 + 8i64 * ((18 >> v127) & 3) + 40);
                    v133 = v132;
                    v131 = v132 & 0xFFFFFFFFFFFFFFFCui64;
                    v134 = v133 & 3;
                    v127 = 2 * v134;
                    v135 = *(_QWORD *)(v131 + 8 * ((18i64 >> 2 * v134) & 3) + 16);
                  }
                  while ( (*(_DWORD *)(v161 + 16) - v130) * (signed __int64)(*(_DWORD *)(v135 + 20) - v129)
                        - (*(_DWORD *)(v161 + 20) - v129) * (signed __int64)(*(_DWORD *)(v135 + 16) - v130) > 0 );
                }
                *(_QWORD *)&resulta.m_type.m_storage = v131;
                LODWORD(resulta.m_edge.m_triangle) = (18 >> 2 * v134) & 3;
                v173.m_enum = v124 - 1;
                _mm_store_si128((__m128i *)&edge, *(__m128i *)&resulta.m_type.m_storage);
              }
              LODWORD(v21) = edge.m_index;
              v12 = (unsigned __int64)edge.m_triangle;
            }
            v88 = v161;
            v89 = 2 * v21;
          }
          while ( *(_QWORD *)(v12 + 8 * ((9i64 >> 2 * (unsigned __int8)v21) & 3) + 16) != v161 );
          v10 = v172;
        }
        v136 = (signed int)v21;
        v137 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 16);
        v165.m128i_i64[0] = (unsigned int)(2 * v21);
        v138 = v12 + 8 * ((9i64 >> 2 * (unsigned __int8)v21) & 3);
        v139 = *(_DWORD *)(v137 + 16);
        v140 = *(_QWORD *)(v138 + 16);
        v141 = *(_DWORD *)(v140 + 16);
        if ( v139 >= v141
          && (v139 > v141 || *(_DWORD *)(v137 + 20) > *(_DWORD *)(v140 + 20))
          && (v142 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40), v142 & 0xFFFFFFFFFFFFFFFCui64) )
        {
          v21 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40) & 3i64;
          v143 = v142 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v143 = v12;
        }
        *(_WORD *)(v143 + 184) ^= ((unsigned __int8)*(_WORD *)(v143 + 184) ^ (unsigned __int8)(*(unsigned __int16 *)(v143 + 184) | (1 << v21))) & 7;
        if ( data )
          hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setEdgeData(
            v171,
            &edge,
            data);
        if ( !conform )
        {
LABEL_174:
          v171->m_roots[((signed __int64)(*(_DWORD *)(*(_QWORD *)(v12 + 32) + 16i64)
                                        + *(_DWORD *)(*(_QWORD *)(v12 + 24) + 16i64)
                                        + 2 * *(_DWORD *)(*(_QWORD *)(v12 + 16) + 16i64)) >> 21)
                      + (((signed __int64)(*(_DWORD *)(*(_QWORD *)(v12 + 32) + 20i64)
                                         + *(_DWORD *)(*(_QWORD *)(v12 + 24) + 20i64)
                                         + 2 * *(_DWORD *)(*(_QWORD *)(v12 + 16) + 20i64)) >> 17) & 0xFFFFFFFFFFFFFFF0ui64)] = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v12;
          *(_WORD *)(v12 + 184) |= 8u;
          v28 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&edge.m_index;
          v10->m_type.m_storage = 0;
          v10->m_edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)v12;
          goto LABEL_21;
        }
        v144 = v171;
        v62 = (*(_QWORD *)(v12 + 8 * (v136 + 5)) & 0xFFFFFFFFFFFFFFFCui64) == 0;
        v145 = v171->m_stack.m_size;
        v0 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v12 + 8 * v136 + 16);
        v146 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v138 + 16);
        v147 = (_QWORD *)(v12 + 8 * (v136 + 5));
        v148 = v62;
        v1[0] = v146;
        v149 = 4;
        if ( v62 )
          v149 = 2;
        v150 = v171->m_stack.m_capacityAndFlags;
        v167.m128i_i64[0] = (__int64)v147;
        v151 = v150 & 0x3FFFFFFF;
        v152 = v149 + v145;
        if ( v151 >= v152 )
        {
          v173.m_enum = 0;
        }
        else
        {
          v153 = 2 * v151;
          if ( v152 < v153 )
            v152 = v153;
          hkArrayUtil::_reserve(
            &v173,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v171->m_stack,
            v152,
            16);
          if ( v173.m_enum == 1 )
          {
            v171->m_status.m_storage = 1;
            if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
            {
              *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
              DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
              `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
            }
            v154 = (__m128i)`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e;
LABEL_173:
            _mm_store_si128((__m128i *)&edge, v154);
            v12 = (unsigned __int64)edge.m_triangle;
            goto LABEL_174;
          }
          v147 = (_QWORD *)v167.m128i_i64[0];
          v144 = v171;
        }
        v155 = v171->m_stack.m_size;
        v156 = v165.m128i_i8[0];
        v171->m_stack.m_size += v149;
        v157 = (signed __int64)&v171->m_stack.m_data[v155];
        *(_QWORD *)v157 = v12;
        *(_DWORD *)(v157 + 8) = (9 >> v156) & 3;
        *(_QWORD *)(v157 + 16) = v12;
        *(_DWORD *)(v157 + 24) = (18 >> v156) & 3;
        if ( !v148 )
        {
          v158 = 9 >> 2 * (*v147 & 3);
          *(_QWORD *)(v157 + 32) = *v147 & 0xFFFFFFFFFFFFFFFCui64;
          *(_DWORD *)(v157 + 40) = v158 & 3;
          v159 = 18 >> 2 * (*v147 & 3);
          *(_QWORD *)(v157 + 48) = *v147 & 0xFFFFFFFFFFFFFFFCui64;
          *(_DWORD *)(v157 + 56) = v159 & 3;
        }
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::flushConform(v144);
        hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateExistingEdge(
          v171,
          (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta,
          &edge,
          v0,
          v1[0]);
        v154 = *(__m128i *)&resulta.m_type.m_storage;
        goto LABEL_173;
      }
      if ( v8 == 0x7FFFFF && v9 > v174 )
        goto LABEL_17;
    }
    v62 = v9 == v174;
    goto LABEL_65;
  }
  v34 = *(_DWORD *)(v33 + 16);
  v35 = (signed int)v21;
  v36 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 16);
  v37 = *(_DWORD *)(v36 + 16);
  if ( v37 >= v34
    && (v37 > v34 || *(_DWORD *)(v36 + 20) > *(_DWORD *)(v33 + 20))
    && (v38 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40), v38 & 0xFFFFFFFFFFFFFFFCui64) )
  {
    v39 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40) & 3i64;
    v40 = v38 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v40 = v12;
    LOBYTE(v39) = v21;
  }
  if ( (unsigned __int8)(1 << v39) & (unsigned __int8)*(_WORD *)(v40 + 184) & 7 )
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
    && (v44 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40), v44 & 0xFFFFFFFFFFFFFFFCui64) )
  {
    v21 = *(_QWORD *)(v12 + 8i64 * (signed int)v21 + 40) & 3i64;
    v45 = v44 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v45 = v12;
  }
  v46 = data;
  *(_WORD *)(v45 + 184) ^= ((unsigned __int8)*(_WORD *)(v45 + 184) ^ (unsigned __int8)(*(unsigned __int16 *)(v45 + 184) | (1 << v21))) & 7;
  if ( v46 )
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::setEdgeData(
      v171,
      &edge,
      v46);
  if ( !conform )
  {
    v61 = edge;
    v10->m_type.m_storage = 0;
    v10->m_edge = v61;
    return v10;
  }
  v47 = v171;
  v48 = v171->m_stack.m_size;
  v0 = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)(v12 + 8 * v35 + 16);
  v1[0] = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex **)v165.m128i_i64[0];
  v49 = (_QWORD *)(v12 + 8 * (v35 + 5));
  v50 = (*(_QWORD *)(v12 + 8 * (v35 + 5)) & 0xFFFFFFFFFFFFFFFCui64) == 0;
  v51 = 4;
  v165.m128i_i64[0] = (__int64)v49;
  LODWORD(v161) = v50;
  if ( v50 )
    v51 = 2;
  v52 = v171->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
  v53 = v51 + v48;
  if ( v52 >= v53 )
  {
    v173.m_enum = 0;
  }
  else
  {
    v54 = 2 * v52;
    if ( v53 < v54 )
      v53 = v54;
    hkArrayUtil::_reserve(&v173, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v171->m_stack, v53, 16);
    if ( v173.m_enum == 1 )
    {
      v171->m_status.m_storage = 1;
      if ( !(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' & 1) )
      {
        *(_QWORD *)&`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::`local static guard' |= 1u;
      }
      v55 = `hkgpTopology::Edge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex *>::null'::`2'::e;
      v10->m_type.m_storage = 0;
      v10->m_edge = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge)v55;
      return v10;
    }
    v49 = (_QWORD *)v165.m128i_i64[0];
    v47 = v171;
  }
  v56 = v167.m128i_i8[0];
  v57 = v171->m_stack.m_size;
  v171->m_stack.m_size += v51;
  v58 = (signed __int64)&v171->m_stack.m_data[v57];
  *(_DWORD *)(v58 + 8) = x1;
  *(_QWORD *)v58 = v12;
  *(_QWORD *)(v58 + 16) = v12;
  *(_DWORD *)(v58 + 24) = (18 >> v56) & 3;
  if ( !(_DWORD)v161 )
  {
    v59 = 9 >> 2 * (*v49 & 3);
    *(_QWORD *)(v58 + 32) = *v49 & 0xFFFFFFFFFFFFFFFCui64;
    *(_DWORD *)(v58 + 40) = v59 & 3;
    v60 = 18 >> 2 * (*v49 & 3);
    *(_QWORD *)(v58 + 48) = *v49 & 0xFFFFFFFFFFFFFFFCui64;
    *(_DWORD *)(v58 + 56) = v60 & 3;
  }
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::flushConform(v47);
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::locateExistingEdge(
    v171,
    (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta,
    &edge,
    v0,
    v1[0]);
  v10->m_type.m_storage = 0;
  v10->m_edge = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *)&resulta.m_type.m_storage;
  return v10;
}m_type.m_storage;
  return v10;
}

// File Line: 1526
// RVA: 0x12EC030
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *result, int x0, int y0, __int64 x1)
{
  int v5; // esi
  int v6; // eax
  __int64 v7; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v8; // rdi
  __int64 v9; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v10; // rcx
  int v11; // edi
  int v12; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v13; // rcx
  __int64 v14; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v15; // rdx
  int v16; // er10
  int v17; // er8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v18; // rcx
  int v19; // edx
  int v20; // er9
  signed int v21; // ecx
  signed int v22; // esi
  int v23; // ecx
  signed int v24; // edx
  __m128i v25; // xmm1
  float v26; // xmm1_4
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  int v29; // edi
  int v30; // ebx
  unsigned int v31; // eax
  unsigned int v32; // er8
  signed int v33; // eax
  signed int v34; // ecx
  int v35; // esi
  int v36; // er9
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  signed int v41; // er9
  int v42; // er11
  __m128 v43; // xmm8
  signed int v44; // er10
  __m128 v45; // xmm3
  int v46; // ecx
  __m128 v47; // xmm4
  int v48; // eax
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
  signed __int64 v64; // rax
  __m128 *v65; // rsi
  __m128 v66; // xmm7
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  float v70; // xmm6_4
  unsigned int v71; // eax
  int v72; // er9
  int v73; // er10
  int v74; // ebx
  bool v75; // zf
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v76; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v77; // rcx
  __int64 v78; // rax
  __int64 v79; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v80; // rsi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v81; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v82; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v83; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v84; // rdx
  __int64 v85; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v86; // rax
  bool v87; // zf
  __int64 v88; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v89; // rdx
  bool v90; // cf
  __int64 v91; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v92; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v93; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v94; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v95; // rdx
  __int64 v96; // rax
  int v97; // [rsp+50h] [rbp-90h]
  signed int v98; // [rsp+54h] [rbp-8Ch]
  signed int v99; // [rsp+58h] [rbp-88h]
  signed int v100; // [rsp+5Ch] [rbp-84h]
  int v101; // [rsp+60h] [rbp-80h]
  int v102; // [rsp+68h] [rbp-78h]
  int ix; // [rsp+6Ch] [rbp-74h]
  int v104; // [rsp+70h] [rbp-70h]
  signed int v105; // [rsp+74h] [rbp-6Ch]
  signed int v106; // [rsp+78h] [rbp-68h]
  signed int v107; // [rsp+7Ch] [rbp-64h]
  hkErrStream location; // [rsp+80h] [rbp-60h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edge; // [rsp+A0h] [rbp-40h]
  int v110; // [rsp+B0h] [rbp-30h]
  __int64 v111; // [rsp+B8h] [rbp-28h]
  __int64 v112; // [rsp+C0h] [rbp-20h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion resulta; // [rsp+C8h] [rbp-18h]
  int v114; // [rsp+E0h] [rbp+0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v115; // [rsp+E8h] [rbp+8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v116; // [rsp+100h] [rbp+20h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v117; // [rsp+118h] [rbp+38h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v118; // [rsp+130h] [rbp+50h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion v119; // [rsp+148h] [rbp+68h]
  char buf; // [rsp+160h] [rbp+80h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v121; // [rsp+400h] [rbp+320h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v122; // [rsp+408h] [rbp+328h]
  int x0a; // [rsp+410h] [rbp+330h]
  int retaddr; // [rsp+418h] [rbp+338h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v125; // [rsp+420h] [rbp+340h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Insertion *v126; // [rsp+428h] [rbp+348h]
  int v127; // [rsp+430h] [rbp+350h]
  NavMeshCutterCutterEdgeCrossing *v128; // [rsp+438h] [rbp+358h]

  LODWORD(v128) = y0;
  v127 = x0;
  v126 = result;
  v125 = this;
  v5 = y0;
  v102 = y0;
  v6 = x0;
  ix = x0;
  while ( 1 )
  {
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertEdge(
      this,
      &resulta,
      v6,
      v5,
      (int)v125,
      (int)v126,
      v127,
      (hkaiRuntimeTriangulatorEdgeData *)x1);
    v7 = *(_QWORD *)&resulta.m_type.m_storage;
    v8 = resulta.m_edge.m_triangle;
    v9 = *(_QWORD *)&resulta.m_edge.m_index;
    edge = resulta.m_edge;
    if ( resulta.m_type.m_storage == 1 )
      break;
    if ( resulta.m_type.m_storage == 3 )
    {
      v15 = resulta.m_edge.m_triangle->m_vertices[resulta.m_edge.m_index];
      v16 = v15->m_x;
      v17 = v15->m_y;
      v106 = v16;
      v18 = resulta.m_edge.m_triangle->m_vertices[(9i64 >> 2 * LOBYTE(resulta.m_edge.m_index)) & 3];
      v107 = v17;
      v19 = v18->m_x;
      v20 = v18->m_y;
      v21 = v102;
      v105 = v19;
      LODWORD(v112) = v17 - v20;
      v22 = (v17 - v20) * (ix - (_DWORD)v125) + (v102 - (_DWORD)v126) * (v19 - v16);
      if ( v22 )
      {
        v23 = v19 * (v102 - v17);
        v24 = ix;
        v25 = _mm_cvtsi32_si128(ix * (v17 - v20) + v16 * (v20 - v102) + v23);
        v21 = v102;
        v26 = COERCE_FLOAT(_mm_cvtepi32_ps(v25)) / (float)v22;
      }
      else
      {
        v24 = ix;
        v26 = 0.0;
      }
      v27 = (__m128)COERCE_UNSIGNED_INT((float)((signed int)v125 - v24));
      v28 = (__m128)COERCE_UNSIGNED_INT((float)((signed int)v126 - v21));
      v27.m128_f32[0] = (float)(v27.m128_f32[0] * v26) + (float)v24;
      v28.m128_f32[0] = (float)(v28.m128_f32[0] * v26) + (float)v21;
      v29 = (signed int)v27.m128_f32[0];
      v101 = v28.m128_i32[0];
      v97 = (signed int)v27.m128_f32[0];
      v30 = (signed int)v28.m128_f32[0];
      v98 = (signed int)v28.m128_f32[0];
      v31 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
              (signed int)v27.m128_f32[0],
              (signed int)v28.m128_f32[0],
              &edge);
      v32 = v31;
      if ( !v22 )
      {
        if ( v31 )
          goto LABEL_72;
        goto LABEL_66;
      }
      if ( v31 )
        goto LABEL_72;
      v33 = 1;
      v34 = -1;
      v99 = 1;
      v100 = -1;
      while ( v34 > -63 )
      {
        v101 = v34;
        v110 = 1;
        if ( v33 >= 0 )
        {
          v30 += v99;
          v35 = v98 - v99;
          v36 = v97 - v98;
          v114 = -v98;
          v37 = v98 - v97;
          ix = v97;
          v102 = v97 - v98;
          LODWORD(v111) = -v97;
          v104 = v98 - v97;
          while ( 1 )
          {
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v36 + v30,
                    v29 + v37,
                    &edge);
            if ( v32 )
              break;
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v35 + v102,
                    v29 + v104,
                    &edge);
            if ( v32 )
            {
              v40 = v35 + v102;
              goto LABEL_40;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v35 + v102,
                    v104 + ix,
                    &edge);
            if ( v32 )
            {
              v97 = v35 + v102;
              v39 = v104 + ix;
              goto LABEL_41;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v30 + v102,
                    v104 + ix,
                    &edge);
            if ( v32 )
            {
              v97 = v30 + v102;
              v39 = v104 + ix;
              goto LABEL_41;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v29,
                    v30,
                    &edge);
            if ( v32 )
            {
              v97 = v29;
              v98 = v30;
              goto LABEL_43;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    ix,
                    v30,
                    &edge);
            if ( v32 )
            {
              v29 = ix;
              v98 = v30;
              v97 = ix;
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
              v97 = v29;
              v98 = v35;
              goto LABEL_43;
            }
            v32 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                    v29,
                    v35,
                    &edge);
            if ( v32 )
              goto LABEL_33;
            --ix;
            v38 = v110 + v104;
            v110 += 2;
            ++v29;
            v104 = v38;
            if ( v101 + 2 * v38 > 0 )
            {
              --v30;
              ++v35;
              v104 = v101 + v38;
              v101 += 2;
            }
            v37 = v104;
            v36 = v97 - v98;
            if ( v30 + v114 < v29 + (signed int)v111 )
            {
              v30 = v98;
              goto LABEL_42;
            }
          }
          v40 = v30 + v102;
LABEL_40:
          v97 = v40;
          v39 = v29 + v104;
LABEL_41:
          v98 = v39;
          v30 = v39;
LABEL_42:
          v29 = v97;
LABEL_43:
          v33 = v99;
          v34 = v100;
        }
        ++v33;
        v34 -= 2;
        v99 = v33;
        v100 = v34;
        if ( v32 )
          goto LABEL_72;
      }
      if ( v32 )
      {
LABEL_72:
        *(_QWORD *)&location.m_memSizeAndFlags = resulta.m_edge.m_triangle;
        location.m_writer.m_pntr = *(hkStreamWriter **)&resulta.m_edge.m_index;
        LODWORD(location.vfptr) = 1;
        v76 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertVertex(
                v121,
                &v117,
                v29,
                v30,
                0,
                (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Location *)&location,
                1);
        v77 = v76;
        v78 = *(_QWORD *)&v76->m_type.m_storage;
        v79 = *(_QWORD *)&v77->m_edge.m_index;
        v80 = v77->m_edge.m_triangle;
        v112 = *(_QWORD *)&v77->m_edge.m_index;
        if ( (_DWORD)v78 == 10 )
        {
          v95 = v122;
          *(_QWORD *)&v122->m_type.m_storage = v78;
          v96 = *(_QWORD *)&v77->m_edge.m_index;
          v95->m_edge.m_triangle = v80;
          *(_QWORD *)&v95->m_edge.m_index = v96;
          return v95;
        }
        if ( (_DWORD)v78 )
        {
          hkErrStream::hkErrStream(&location, &buf, 512);
          hkOstream::operator<<((hkOstream *)&location.vfptr, "Cannot insert crossing edge");
          if ( (unsigned int)hkError::messageError(
                               -1666462880,
                               &buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hk"
                               "gpTriangulator.inl",
                               1658) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&location.vfptr);
          LODWORD(v79) = v112;
        }
        v81 = v80->m_vertices[(signed int)v79];
        v82 = v121;
        *((_QWORD *)v81 + 3) = *((_DWORD *)v81 + 6) & 3 | (unsigned __int64)(4i64
                                                                           * (v128->m_triangulator->m_mesh.m_vertices.m_numUsed
                                                                            - 1));
        LODWORD(v81) = x0a;
        v128->m_addedNewVertex = 1;
        v83 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
                v82,
                &v119,
                (int)v81,
                retaddr,
                v29,
                v30,
                v127,
                v128,
                (hkaiRuntimeTriangulatorEdgeData *)x1);
        v84 = v83;
        v85 = *(_QWORD *)&v83->m_type.m_storage;
        resulta.m_edge.m_triangle = v84->m_edge.m_triangle;
        *(_QWORD *)&resulta.m_edge.m_index = *(_QWORD *)&v84->m_edge.m_index;
        if ( (_DWORD)v85 == 10 )
        {
          v94 = v122;
          *(_QWORD *)&v122->m_type.m_storage = v85;
          v94->m_edge.m_triangle = v84->m_edge.m_triangle;
          *(_QWORD *)&v94->m_edge.m_index = *(_QWORD *)&v84->m_edge.m_index;
          return v94;
        }
        if ( (unsigned int)v85 > 1 )
        {
          hkErrStream::hkErrStream(&location, &buf, 512);
          hkOstream::operator<<((hkOstream *)&location.vfptr, "Cannot insert crossing edge");
          if ( (unsigned int)hkError::messageError(
                               -1666462880,
                               &buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hk"
                               "gpTriangulator.inl",
                               1665) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&location.vfptr);
        }
        this = v121;
        v6 = v29;
        v5 = v30;
        x0a = v29;
        retaddr = v30;
      }
      else
      {
        v41 = v105;
        v42 = v101;
        v43 = _mm_unpacklo_ps(v27, (__m128)0i64);
        v44 = v107;
        v45 = _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v105), (__m128)0i64);
        v46 = abs(abs(v106 - v105));
        v47 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v106), (__m128)0i64),
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v107), (__m128)0i64));
        v48 = abs(abs((_DWORD)v112));
        v49 = 1;
        v50 = _mm_cvtsi32_si128(v101);
        v101 = 1;
        *(__m128 *)&location.vfptr = v47;
        if ( v46 > v48 )
          v48 = v46;
        v51 = 8 * v48 + 4;
        v52 = _mm_unpacklo_ps(v45, _mm_unpacklo_ps(_mm_cvtepi32_ps(v50), (__m128)0i64));
        if ( v51 > 128 )
          v51 = 128;
        LODWORD(v112) = v51;
        v53 = _mm_unpacklo_ps(v43, _mm_unpacklo_ps(v28, (__m128)0i64));
        *(__m128 *)&location.m_writer.m_pntr = v52;
        v54 = _mm_sub_ps(v53, v52);
        v55 = _mm_sub_ps(v53, v47);
        v56 = _mm_mul_ps(v54, v54);
        v57 = _mm_mul_ps(v55, v55);
        v58 = fmin(
                (float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170)),
                (float)(COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 170)));
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
            v65 = (__m128 *)&location;
            v111 = 2i64;
            v66 = _mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v62);
            do
            {
              v67 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*v65, v53), v66), v53);
              v68 = _mm_sub_ps(v67, v53);
              v69 = _mm_mul_ps(v68, v68);
              v70 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170));
              if ( !v32 && v70 < v58 )
              {
                v29 = _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_shuffle_ps(v67, v67, 0), (__m128)xmmword_141A711B0)));
                v30 = _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_shuffle_ps(v67, v67, 85), (__m128)xmmword_141A711B0)));
                if ( v29 == v106 && v30 == v44
                  || v29 == v41 && v30 == v42
                  || (v71 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::canSplitEdge(
                              v29,
                              v30,
                              &edge),
                      v41 = v105,
                      v44 = v107,
                      v42 = v101,
                      v32 = v71,
                      v75 = v71 == 0,
                      v64 = v111,
                      v75) )
                {
                  v29 = v97;
                  v30 = v98;
                }
                else
                {
                  v58 = v70;
                  v97 = v29;
                  v98 = v30;
                }
              }
              ++v65;
              v111 = --v64;
            }
            while ( v64 );
            if ( v32 )
              goto LABEL_72;
            v49 = v101 + 1;
            v101 = v49;
          }
          while ( v49 < (signed int)v112 );
        }
LABEL_66:
        v72 = retaddr;
        v73 = x0a;
        v5 = v101;
        v74 = v105;
        if ( ((signed int)v126 - retaddr) * (v106 - x0a) - ((signed int)v125 - x0a) * (v107 - retaddr) < (retaddr - (signed int)v126) * (v105 - (signed int)v125) - (x0a - (signed int)v125) * (v101 - (signed int)v126) )
        {
          v74 = v106;
          if ( v106 == x0a )
          {
            if ( !v106 )
            {
              v75 = v107 == retaddr;
              if ( v107 < retaddr )
                goto LABEL_92;
LABEL_86:
              if ( !v75 )
                goto LABEL_95;
              if ( !v107 )
              {
                if ( v106 > x0a )
                  goto LABEL_92;
LABEL_95:
                v86 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
                        v121,
                        &v116,
                        v73,
                        v72,
                        v106,
                        v107,
                        v127,
                        v128,
                        (hkaiRuntimeTriangulatorEdgeData *)x1);
                v5 = v107;
                retaddr = v107;
                goto LABEL_113;
              }
              if ( v107 != 0x7FFF || v106 >= x0a )
                goto LABEL_95;
LABEL_92:
              hkErrStream::hkErrStream(&location, &buf, 512);
              hkOstream::operator<<((hkOstream *)&location.vfptr, "Cannot insert crossing edge");
              if ( (unsigned int)hkError::messageError(
                                   -1666462880,
                                   &buf,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulato"
                                   "r/hkgpTriangulator.inl",
                                   1676) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&location.vfptr);
              v72 = retaddr;
              v73 = x0a;
              goto LABEL_95;
            }
            if ( v106 == 0x7FFF && v107 > retaddr )
              goto LABEL_92;
          }
          v75 = v107 == retaddr;
          goto LABEL_86;
        }
        if ( v105 != x0a )
          goto LABEL_102;
        if ( v105 )
        {
          if ( v105 == 0x7FFF && v101 > retaddr )
          {
LABEL_109:
            hkErrStream::hkErrStream(&location, &buf, 512);
            hkOstream::operator<<((hkOstream *)&location.vfptr, "Cannot insert crossing edge");
            if ( (unsigned int)hkError::messageError(
                                 -1666462880,
                                 &buf,
                                 "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/"
                                 "hkgpTriangulator.inl",
                                 1682) )
              __debugbreak();
            hkOstream::~hkOstream((hkOstream *)&location.vfptr);
            v72 = retaddr;
            v73 = x0a;
            goto LABEL_112;
          }
LABEL_102:
          v87 = v101 == retaddr;
          goto LABEL_103;
        }
        v87 = v101 == retaddr;
        if ( v101 < retaddr )
          goto LABEL_109;
LABEL_103:
        if ( v87 )
        {
          if ( v101 )
          {
            if ( v101 == 0x7FFF && v105 < x0a )
              goto LABEL_109;
          }
          else if ( v105 > x0a )
          {
            goto LABEL_109;
          }
        }
LABEL_112:
        v86 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::insertCrossingEdge<NavMeshCutterCutterEdgeCrossing>(
                v121,
                &v118,
                v73,
                v72,
                v105,
                v101,
                v127,
                v128,
                (hkaiRuntimeTriangulatorEdgeData *)x1);
        retaddr = v101;
LABEL_113:
        v88 = *(_QWORD *)&v86->m_type.m_storage;
        v89 = v86->m_edge.m_triangle;
        v9 = *(_QWORD *)&v86->m_edge.m_index;
        x0a = v74;
        v6 = v74;
        if ( (_DWORD)v88 == 10 )
        {
          v93 = v122;
          *(_QWORD *)&v122->m_type.m_storage = v88;
          v93->m_edge.m_triangle = v89;
          goto LABEL_125;
        }
        v90 = (unsigned int)v88 < 1;
        v75 = (_DWORD)v88 == 1;
        this = v121;
        if ( !v90 && !v75 )
        {
          hkErrStream::hkErrStream(&location, &buf, 512);
          hkOstream::operator<<((hkOstream *)&location.vfptr, "Cannot insert crossing edge");
          if ( (unsigned int)hkError::messageError(
                               -1666462880,
                               &buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hk"
                               "gpTriangulator.inl",
                               1690) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&location.vfptr);
          v6 = x0a;
          this = v121;
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
              v121,
              &v115,
              x0a,
              v5,
              v12,
              v11,
              v127,
              v128,
              (hkaiRuntimeTriangulatorEdgeData *)x1);
      v14 = *(_QWORD *)&v13->m_type.m_storage;
      resulta.m_edge.m_triangle = v13->m_edge.m_triangle;
      *(_QWORD *)&resulta.m_edge.m_index = *(_QWORD *)&v13->m_edge.m_index;
      if ( (_DWORD)v14 == 10 )
      {
        v91 = v14;
        v92 = v122;
        *(_QWORD *)&v122->m_type.m_storage = v91;
        v92->m_edge.m_triangle = v13->m_edge.m_triangle;
        *(_QWORD *)&v92->m_edge.m_index = *(_QWORD *)&v13->m_edge.m_index;
        return v92;
      }
      if ( (unsigned int)v14 > 1 )
      {
        hkErrStream::hkErrStream(&location, &buf, 512);
        hkOstream::operator<<((hkOstream *)&location.vfptr, "Cannot insert crossing edge");
        if ( (unsigned int)hkError::messageError(
                             -1666462880,
                             &buf,
                             "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgp"
                             "Triangulator.inl",
                             1708) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&location.vfptr);
      }
      this = v121;
      v6 = v12;
      x0a = v12;
      v5 = v11;
      retaddr = v11;
    }
  }
  if ( x1 )
  {
    hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::setEdgeData(
      v121,
      &resulta.m_edge,
      (hkaiRuntimeTriangulatorEdgeData *)x1);
    v9 = *(_QWORD *)&resulta.m_edge.m_index;
  }
LABEL_124:
  v93 = v122;
  *(_QWORD *)&v122->m_type.m_storage = v7;
  v93->m_edge.m_triangle = v8;
LABEL_125:
  *(_QWORD *)&v93->m_edge.m_index = v9;
  return v93;
}
  v93->m_edge.m_triangle = v8;
LABEL_125:
  *(_QWORD *)&v93->m_edge.m_index = v9;
  return v93;
}

// File Line: 1753
// RVA: 0xCDF8A0
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::partition(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *i; // r8
  unsigned int v2; // er12
  hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,64,hkContainerHeapAllocator> *v3; // rsi
  unsigned int v4; // er12
  char **v5; // rdi
  signed int v6; // er13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location *v7; // rax
  int v8; // edx
  unsigned __int64 v9; // rbx
  unsigned __int64 *v10; // rcx
  char **v11; // rbx
  int v12; // edx
  __int64 v13; // r15
  signed int v14; // er14
  signed __int64 v15; // rdx
  unsigned __int64 v16; // rsi
  __int64 v17; // r9
  __int64 v18; // r8
  int v19; // eax
  int v20; // ecx
  __int64 v21; // rax
  unsigned __int64 v22; // rax
  int v23; // er9
  int v24; // eax
  int v25; // eax
  unsigned int v26; // ebx
  unsigned __int64 *v27; // rcx
  int v28; // er9
  int v29; // eax
  int v30; // eax
  unsigned __int64 *v31; // rax
  unsigned __int64 v33; // [rsp+38h] [rbp-C8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Location result; // [rsp+40h] [rbp-C0h]
  char *array; // [rsp+60h] [rbp-A0h]
  int v36; // [rsp+68h] [rbp-98h]
  int v37; // [rsp+6Ch] [rbp-94h]
  char v38; // [rsp+70h] [rbp-90h]
  hkResult v39; // [rsp+4B0h] [rbp+3B0h]
  hkResult v40; // [rsp+4B8h] [rbp+3B8h]

  for ( i = this->m_mesh.m_triangles.m_used; i; i = i->m_next )
    *((_WORD *)i + 33) = *((_WORD *)i + 33) & 0x1F | 32 * (((unsigned __int16)(*((_WORD *)i + 33) & 0x1F) >> 5) - 1);
  v2 = *((unsigned __int16 *)this->m_mesh.m_triangles.m_used + 33);
  v36 = 0;
  v37 = -2147483584;
  v3 = &this->m_stack;
  v4 = v2 >> 5;
  array = &v38;
  v5 = &array;
  v6 = -1;
  v7 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::locateVertex(
         this,
         &result,
         0,
         0);
  v8 = v36;
  v9 = ((_QWORD)v7->m_edge.m_triangle + v7->m_edge.m_index) & 0xFFFFFFFFFFFFFFFCui64;
  LODWORD(v33) = (LOBYTE(v7->m_edge.m_triangle) + (unsigned __int8)v7->m_edge.m_index) & 3;
  if ( v36 == (v37 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v8 = v36;
  }
  v10 = (unsigned __int64 *)&array[16 * v8];
  if ( v10 )
  {
    *v10 = v9;
    v10[1] = v33;
    v8 = v36;
  }
  v36 = v8 + 1;
  while ( 1 )
  {
    v11 = v5;
    v3->m_size = 0;
    ++v6;
    v5 = (char **)v3;
    do
    {
      v12 = *((_DWORD *)v11 + 2);
      v13 = *(_QWORD *)&(*v11)[16 * *((signed int *)v11 + 2) - 16];
      result.m_edge.m_triangle = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **)&(*v11)[16 * *((signed int *)v11 + 2) - 8];
      *((_DWORD *)v11 + 2) = v12 - 1;
      if ( (unsigned int)*(unsigned __int16 *)(v13 + 66) >> 5 == v4 )
      {
        v14 = 0;
        *(_WORD *)(v13 + 66) = 32 * v6 | *(_WORD *)(v13 + 66) & 0x1F;
        do
        {
          v15 = *(_QWORD *)(v13 + 8i64 * v14 + 40) & 3i64;
          LODWORD(v33) = *(_DWORD *)(v13 + 8i64 * v14 + 40) & 3;
          v16 = *(_QWORD *)(v13 + 8i64 * v14 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          if ( v16 && (unsigned int)*(unsigned __int16 *)(v16 + 66) >> 5 == v4 )
          {
            v17 = *(_QWORD *)(v16 + 8i64 * (signed int)v15 + 16);
            v18 = *(_QWORD *)(v16 + 8 * ((9i64 >> 2 * (unsigned __int8)v15) & 3) + 16);
            v19 = *(_DWORD *)(v17 + 16);
            v20 = *(_DWORD *)(v18 + 16);
            if ( v19 >= v20
              && (v19 > v20 || *(_DWORD *)(v17 + 20) > *(_DWORD *)(v18 + 20))
              && (v21 = *(_QWORD *)(v16 + 8i64 * (signed int)v15 + 40), v21 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v15 = *(_QWORD *)(v16 + 8i64 * (signed int)v15 + 40) & 3i64;
              v22 = v21 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v22 = *(_QWORD *)(v13 + 8i64 * v14 + 40) & 0xFFFFFFFFFFFFFFFCui64;
            }
            if ( (1 << v15) & 7 & *(_BYTE *)(v22 + 66) )
            {
              v23 = *((_DWORD *)v5 + 2) + 1;
              v24 = *((_DWORD *)v5 + 3) & 0x3FFFFFFF;
              if ( v24 >= v23 )
              {
                v39.m_enum = 0;
              }
              else
              {
                v25 = 2 * v24;
                if ( v23 < v25 )
                  v23 = v25;
                hkArrayUtil::_reserve(&v39, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v23, 16);
                if ( v39.m_enum )
                  goto LABEL_24;
              }
              if ( *((_DWORD *)v5 + 2) == (*((_DWORD *)v5 + 3) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
              v27 = (unsigned __int64 *)&(*v5)[16 * *((signed int *)v5 + 2)];
              if ( v27 )
              {
                *v27 = v16;
                v27[1] = v33;
              }
              ++*((_DWORD *)v5 + 2);
            }
            else
            {
              v28 = *((_DWORD *)v11 + 2) + 1;
              v29 = *((_DWORD *)v11 + 3) & 0x3FFFFFFF;
              if ( v29 >= v28 )
              {
                v40.m_enum = 0;
              }
              else
              {
                v30 = 2 * v29;
                if ( v28 < v30 )
                  v28 = v30;
                hkArrayUtil::_reserve(&v40, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, v28, 16);
                if ( v40.m_enum )
                {
LABEL_24:
                  v26 = -1;
                  goto LABEL_47;
                }
              }
              if ( *((_DWORD *)v11 + 2) == (*((_DWORD *)v11 + 3) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 16);
              v31 = (unsigned __int64 *)&(*v11)[16 * *((signed int *)v11 + 2)];
              if ( v31 )
              {
                *v31 = v16;
                v31[1] = v33;
              }
              ++*((_DWORD *)v11 + 2);
            }
          }
          ++v14;
        }
        while ( v14 < 3 );
      }
    }
    while ( *((_DWORD *)v11 + 2) > 0 );
    if ( *((_DWORD *)v5 + 2) <= 0 )
      break;
    v3 = (hkInplaceArray<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge,64,hkContainerHeapAllocator> *)v11;
  }
  v26 = v6 + 1;
LABEL_47:
  v36 = 0;
  if ( v37 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v37);
  return v26;
}

// File Line: 1848
// RVA: 0x12EBB60
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::floodEdgeSets<FloodPolicyCell>(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this, FloodPolicyCell *policy)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v2; // rsi
  int v4; // ebx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v5; // r14
  signed int v6; // er15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v7; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v8; // rdx
  int v9; // eax
  int v10; // ecx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  unsigned __int64 v13; // rax
  hkaiRuntimeTriangulatorEdgeData *v14; // rax
  unsigned __int16 v15; // dx
  __int64 v16; // r13
  signed int v17; // esi
  signed int v18; // edi
  int v19; // er12
  int v20; // er9
  char *v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // r12
  unsigned __int64 v25; // rsi
  __int64 v26; // r13
  unsigned __int16 v27; // ax
  signed int v28; // er15
  char v29; // r8
  __int64 v30; // rdx
  unsigned __int64 v31; // rdi
  __int64 v32; // r10
  __int64 v33; // r9
  int v34; // eax
  int v35; // ecx
  unsigned __int64 v36; // rdx
  hkaiRuntimeTriangulatorEdgeData *v37; // rax
  int v38; // er9
  __int64 v39; // rdi
  char v40; // al
  unsigned __int64 v41; // rdi
  __int64 v42; // r14
  unsigned __int64 *v43; // rdx
  __int64 v44; // rax
  unsigned int v45; // edi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edge; // [rsp+30h] [rbp-D0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge v47; // [rsp+40h] [rbp-C0h]
  __int64 v48; // [rsp+50h] [rbp-B0h]
  __int64 v49; // [rsp+60h] [rbp-A0h]
  __int64 v50; // [rsp+78h] [rbp-88h]
  char *array; // [rsp+80h] [rbp-80h]
  int v52; // [rsp+88h] [rbp-78h]
  int v53; // [rsp+8Ch] [rbp-74h]
  char v54; // [rsp+90h] [rbp-70h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v55; // [rsp+6D0h] [rbp+5D0h]
  hkResult result; // [rsp+6E0h] [rbp+5E0h]

  v55 = this;
  v2 = this;
  if ( hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::partition(this) == -1 )
    return 0i64;
  v4 = 0;
  v5 = v2->m_mesh.m_triangles.m_used;
  array = &v54;
  v52 = 0;
  v53 = -2147483584;
  if ( v5 )
  {
    do
    {
      v6 = 0;
      do
      {
        v7 = v5->m_vertices[v6];
        edge.m_triangle = v5;
        edge.m_index = v6;
        v8 = v5->m_vertices[(9i64 >> 2 * (unsigned __int8)v6) & 3];
        v9 = v7->m_x;
        v10 = v8->m_x;
        if ( v9 >= v10 && (v9 > v10 || v7->m_y > v8->m_y) && (v11 = v5->m_links[v6], v11 & 0xFFFFFFFFFFFFFFFCui64) )
        {
          v12 = v5->m_links[v6] & 3;
          v13 = v11 & 0xFFFFFFFFFFFFFFFCui64;
        }
        else
        {
          v13 = (unsigned __int64)v5;
          LOBYTE(v12) = v6;
        }
        if ( (unsigned __int8)(1 << v12) & (unsigned __int8)*(_WORD *)(v13 + 100) & 7 )
        {
          v14 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
                  v2,
                  &edge);
          if ( v14 )
          {
            v15 = v14->m_sets;
            if ( v15 )
            {
              if ( !(v5->m_links[v6] & 0xFFFFFFFFFFFFFFFCui64)
                || (unsigned __int16)(*((_WORD *)v5 + 50) & 0xFFE0) > (unsigned __int16)(*(_WORD *)((v5->m_links[v6] & 0xFFFFFFFFFFFFFFFCui64)
                                                                                                  + 100) & 0xFFE0) )
              {
                v16 = *(_QWORD *)&edge.m_index;
                v17 = 0;
                v18 = 1;
                v19 = v15;
                while ( 1 )
                {
                  if ( v19 & v18 )
                  {
                    v20 = v4 + 1;
                    if ( (v53 & 0x3FFFFFFF) >= v4 + 1 )
                    {
                      result.m_enum = 0;
                    }
                    else
                    {
                      if ( v20 < 2 * (v53 & 0x3FFFFFFF) )
                        v20 = 2 * (v53 & 0x3FFFFFFF);
                      hkArrayUtil::_reserve(
                        &result,
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        v20,
                        24);
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
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        24);
                      v4 = v52;
                    }
                    v21 = &array[24 * v4];
                    if ( v21 )
                    {
                      v22 = v48;
                      *(_QWORD *)v21 = v5;
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
                    v2 = v55;
                    break;
                  }
                }
              }
            }
          }
        }
        ++v6;
      }
      while ( v6 < 3 );
      v5 = v5->m_next;
    }
    while ( v5 );
    while ( v4 )
    {
      v23 = v4--;
      v24 = *(_QWORD *)&array[24 * v23 - 8];
      v25 = *(_QWORD *)&array[24 * v23 - 24];
      v26 = *(_QWORD *)&array[24 * v23 - 16];
      v52 = v4;
      v27 = *(_WORD *)(v25 + 102);
      v48 = v24;
      if ( !(v27 & (unsigned __int16)v24) )
      {
        v28 = 0;
        *(_WORD *)(v25 + 102) = v24 | v27;
        v4 = v52;
        do
        {
          v47.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *)v25;
          LODWORD(v26) = (9 >> 2 * v26) & 3;
          v29 = v26;
          edge.m_index = v26;
          v30 = *(_QWORD *)(v25 + 8i64 * (signed int)v26 + 40);
          *(_QWORD *)&v47.m_index = *(_QWORD *)&edge.m_index;
          v31 = v30 & 0xFFFFFFFFFFFFFFFCui64;
          if ( v30 & 0xFFFFFFFFFFFFFFFCui64 )
          {
            v32 = *(_QWORD *)(v25 + 8i64 * (signed int)v26 + 16);
            v33 = *(_QWORD *)(v25 + 8 * ((9i64 >> 2 * (unsigned __int8)v26) & 3) + 16);
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
            if ( !((unsigned __int8)(1 << v29) & (unsigned __int8)*(_WORD *)(v36 + 100) & 7)
              || ((v37 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::getEdgeData(
                           v55,
                           &v47)) == 0i64
               || !((unsigned __int16)v24 & v37->m_sets))
              && (unsigned __int16)(*(_WORD *)(v25 + 100) & 0xFFE0) < (unsigned __int16)(*(_WORD *)(v31 + 100) & 0xFFE0) )
            {
              v38 = v4 + 1;
              if ( (v53 & 0x3FFFFFFF) >= v4 + 1 )
              {
                result.m_enum = 0;
              }
              else
              {
                if ( v38 < 2 * (v53 & 0x3FFFFFFF) )
                  v38 = 2 * (v53 & 0x3FFFFFFF);
                hkArrayUtil::_reserve(
                  &result,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &array,
                  v38,
                  24);
                if ( result.m_enum )
                  goto LABEL_60;
                v4 = v52;
              }
              v39 = *(_QWORD *)(v25 + 8i64 * (signed int)v26 + 40);
              LOWORD(v50) = v24;
              v40 = v39;
              v41 = v39 & 0xFFFFFFFFFFFFFFFCui64;
              LODWORD(v49) = v40 & 3;
              v42 = v49;
              if ( v4 == (v53 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 24);
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      24 * (v53 & 0x3FFFFFFF));
  return v45;
}

// File Line: 1935
// RVA: 0xB864C0
hkResult *__fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::partitionWithPolicy<hkaiNavMeshFloodPolicy>(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *this, hkResult *result, hkaiNavMeshFloodPolicy *policy)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *i; // r9
  unsigned int v4; // er14
  char **v5; // r12
  char **v6; // rsi
  signed int v7; // er15
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Location *v8; // rax
  int v9; // ecx
  unsigned __int64 v10; // rbx
  unsigned __int64 *v11; // rdx
  unsigned __int64 v12; // rax
  char **v13; // rdi
  int v14; // edx
  __int64 v15; // r8
  signed int v16; // er13
  signed __int64 v17; // rdx
  unsigned __int64 v18; // rbx
  __int64 v19; // r10
  __int64 v20; // r9
  __int64 v21; // r8
  int v22; // eax
  int v23; // ecx
  __int64 v24; // rax
  unsigned __int64 v25; // rax
  __int64 v26; // r12
  char v27; // cl
  signed __int64 v28; // rdx
  unsigned __int64 v29; // r8
  int v30; // er15
  __int64 v31; // r10
  __int64 v32; // r9
  int v33; // eax
  int v34; // ecx
  __int64 v35; // rax
  unsigned __int64 v36; // rax
  int v37; // er14
  hkaiNavMeshGenTriangulatorEdgeData *v38; // rax
  hkaiNavMeshGenTriangulatorEdgeData *v39; // r15
  hkaiNavMeshGenTriangulatorEdgeData *v40; // rax
  __int16 v41; // cx
  __int16 v42; // ax
  int v43; // er9
  int v44; // eax
  int v45; // eax
  hkResult *v46; // rbx
  unsigned __int64 *v47; // rcx
  unsigned __int64 v48; // rax
  int v49; // er9
  int v50; // eax
  int v51; // eax
  unsigned __int64 *v52; // rcx
  unsigned __int64 v53; // rax
  hkResult v55; // [rsp+30h] [rbp-D0h]
  unsigned int v56; // [rsp+34h] [rbp-CCh]
  int v57; // [rsp+38h] [rbp-C8h]
  __int64 v58; // [rsp+40h] [rbp-C0h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge v59; // [rsp+48h] [rbp-B8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Edge edge; // [rsp+58h] [rbp-A8h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Location resulta; // [rsp+70h] [rbp-90h]
  char *array; // [rsp+90h] [rbp-70h]
  int v63; // [rsp+98h] [rbp-68h]
  int v64; // [rsp+9Ch] [rbp-64h]
  char v65; // [rsp+A0h] [rbp-60h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0> *v66; // [rsp+4E0h] [rbp+3E0h]
  hkResult *v67; // [rsp+4E8h] [rbp+3E8h]
  hkResult v68; // [rsp+4F8h] [rbp+3F8h]

  v67 = result;
  v66 = this;
  for ( i = this->m_mesh.m_triangles.m_used; i; i = i->m_next )
    *((_WORD *)i + 44) = *((_WORD *)i + 44) & 0x1F | 32 * (((unsigned __int16)(*((_WORD *)i + 44) & 0x1F) >> 5) - 1);
  v4 = (unsigned int)*((unsigned __int16 *)this->m_mesh.m_triangles.m_used + 44) >> 5;
  v63 = 0;
  v64 = -2147483584;
  array = &v65;
  v5 = (char **)&this->m_stack;
  v6 = &array;
  v56 = v4;
  v7 = -1;
  v8 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::locateVertex(
         this,
         &resulta,
         0,
         0);
  v9 = v63;
  v10 = ((_QWORD)v8->m_edge.m_triangle + v8->m_edge.m_index) & 0xFFFFFFFFFFFFFFFCui64;
  v59.m_index = (LOBYTE(v8->m_edge.m_triangle) + (unsigned __int8)v8->m_edge.m_index) & 3;
  if ( v63 == (v64 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
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
    v13 = v6;
    v6 = v5;
    ++v7;
    *((_DWORD *)v5 + 2) = 0;
    v57 = v7;
    do
    {
      v14 = *((_DWORD *)v13 + 2);
      v15 = *(_QWORD *)&(*v13)[16 * *((signed int *)v13 + 2) - 16];
      resulta.m_edge.m_triangle = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle **)&(*v13)[16 * *((signed int *)v13 + 2) - 8];
      v58 = v15;
      *((_DWORD *)v13 + 2) = v14 - 1;
      if ( (unsigned int)*(unsigned __int16 *)(v15 + 88) >> 5 == v4 )
      {
        v16 = 0;
        *(_WORD *)(v15 + 88) = 32 * v7 | *(_WORD *)(v15 + 88) & 0x1F;
        do
        {
          v17 = *(_QWORD *)(v15 + 8i64 * v16 + 40) & 3i64;
          v18 = *(_QWORD *)(v15 + 8i64 * v16 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          edge.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(*(_QWORD *)(v15 + 8i64 * v16 + 40) & 0xFFFFFFFFFFFFFFFCui64);
          edge.m_index = v17;
          if ( v18 && (unsigned int)*(unsigned __int16 *)(v18 + 88) >> 5 == v4 )
          {
            v19 = (signed int)v17;
            v20 = *(_QWORD *)(v18 + 8i64 * (signed int)v17 + 16);
            v21 = *(_QWORD *)(v18 + 8 * ((9i64 >> 2 * (unsigned __int8)v17) & 3) + 16);
            v22 = *(_DWORD *)(v20 + 16);
            v23 = *(_DWORD *)(v21 + 16);
            if ( v22 >= v23
              && (v22 > v23 || *(_DWORD *)(v20 + 20) > *(_DWORD *)(v21 + 20))
              && (v24 = *(_QWORD *)(v18 + 8i64 * (signed int)v17 + 40), v24 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v17 = *(_QWORD *)(v18 + 8i64 * (signed int)v17 + 40) & 3i64;
              v25 = v24 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v25 = v18;
            }
            v26 = *(_QWORD *)(v18 + 8 * v19 + 40);
            v27 = v17;
            v28 = *(_QWORD *)(v18 + 8 * v19 + 40) & 3i64;
            v29 = *(_QWORD *)(v18 + 8 * v19 + 40) & 0xFFFFFFFFFFFFFFFCui64;
            v30 = (unsigned __int8)(1 << v27) & (unsigned __int8)*(_WORD *)(v25 + 88) & 7;
            v31 = *(_QWORD *)(v29 + 8i64 * (signed int)v28 + 16);
            v32 = *(_QWORD *)(v29 + 8 * ((9i64 >> 2 * (unsigned __int8)v28) & 3) + 16);
            v33 = *(_DWORD *)(v31 + 16);
            v34 = *(_DWORD *)(v32 + 16);
            if ( v33 >= v34
              && (v33 > v34 || *(_DWORD *)(v31 + 20) > *(_DWORD *)(v32 + 20))
              && (v35 = *(_QWORD *)(v29 + 8i64 * (signed int)v28 + 40), v35 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v28 = *(_QWORD *)(v29 + 8i64 * (signed int)v28 + 40) & 3i64;
              v36 = v35 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v36 = v29;
            }
            v37 = v30 | (unsigned __int8)(1 << v28) & (unsigned __int8)*(_WORD *)(v36 + 88) & 7;
            v38 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                    v66,
                    &edge);
            v59.m_index = v26 & 3;
            v39 = v38;
            v59.m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v26 & 0xFFFFFFFFFFFFFFFCui64);
            v40 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
                    v66,
                    &v59);
            if ( v39 )
              v41 = v39->m_counter;
            else
              v41 = 0;
            if ( v40 )
              v42 = v40->m_counter;
            else
              v42 = 0;
            if ( v37 && (unsigned __int16)(v41 + v42) % 2 )
            {
              v43 = *((_DWORD *)v6 + 2) + 1;
              v44 = *((_DWORD *)v6 + 3) & 0x3FFFFFFF;
              if ( v44 >= v43 )
              {
                v68.m_enum = 0;
              }
              else
              {
                v45 = 2 * v44;
                if ( v43 < v45 )
                  v43 = v45;
                hkArrayUtil::_reserve(&v68, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v43, 16);
                if ( v68.m_enum )
                  goto LABEL_37;
              }
              if ( *((_DWORD *)v6 + 2) == (*((_DWORD *)v6 + 3) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
              v47 = (unsigned __int64 *)&(*v6)[16 * *((signed int *)v6 + 2)];
              if ( v47 )
              {
                v48 = *(_QWORD *)&edge.m_index;
                *v47 = v18;
                v47[1] = v48;
              }
              ++*((_DWORD *)v6 + 2);
            }
            else
            {
              v49 = *((_DWORD *)v13 + 2) + 1;
              v50 = *((_DWORD *)v13 + 3) & 0x3FFFFFFF;
              if ( v50 >= v49 )
              {
                v55.m_enum = 0;
              }
              else
              {
                v51 = 2 * v50;
                if ( v49 < v51 )
                  v49 = v51;
                hkArrayUtil::_reserve(&v55, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, v49, 16);
                if ( v55.m_enum )
                {
LABEL_37:
                  v46 = v67;
                  v67->m_enum = 1;
                  goto LABEL_62;
                }
              }
              if ( *((_DWORD *)v13 + 2) == (*((_DWORD *)v13 + 3) & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 16);
              v52 = (unsigned __int64 *)&(*v13)[16 * *((signed int *)v13 + 2)];
              if ( v52 )
              {
                v53 = *(_QWORD *)&edge.m_index;
                *v52 = v18;
                v52[1] = v53;
              }
              ++*((_DWORD *)v13 + 2);
            }
            v4 = v56;
            v15 = v58;
          }
          ++v16;
        }
        while ( v16 < 3 );
        v7 = v57;
      }
    }
    while ( *((_DWORD *)v13 + 2) > 0 );
    if ( *((_DWORD *)v6 + 2) <= 0 )
      break;
    v5 = v13;
  }
  v46 = v67;
  v67->m_enum = 0;
LABEL_62:
  v63 = 0;
  if ( v64 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v64);
  return v46;
}

// File Line: 2013
// RVA: 0xCD8B20
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::conformEdges(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *this)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v1; // rdx
  int v2; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *v3; // rax
  signed int v4; // er15
  signed __int64 v5; // rcx
  __int64 v6; // r14
  __int64 v7; // r13
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v8; // r12
  int v9; // ecx
  int v10; // edx
  char v11; // cl
  unsigned __int64 v12; // r8
  __int64 v13; // r9
  int v14; // er8
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
  signed __int64 v37; // rcx
  unsigned __int64 v38; // r8
  __int16 v39; // dx
  int v40; // er11
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
  signed __int64 v51; // rsi
  int v52; // er10
  __int64 v53; // rdx
  unsigned __int64 v54; // r9
  int v55; // er12
  unsigned __int64 v56; // r9
  int v57; // esi
  unsigned __int64 v58; // r8
  signed __int64 v59; // r9
  __int64 v60; // r11
  int v61; // ecx
  __int64 v62; // r10
  int v63; // edx
  __int64 v64; // r10
  unsigned __int64 v65; // r10
  signed __int64 v66; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v67; // r10
  int v68; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex *v69; // r8
  int v70; // edx
  unsigned __int64 v71; // r10
  unsigned __int64 v72; // r10
  int v73; // ecx
  bool v74; // zf
  char v75; // [rsp+20h] [rbp-278h]
  hkErrStream v76; // [rsp+30h] [rbp-268h]
  char buf; // [rsp+50h] [rbp-248h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v78; // [rsp+2A0h] [rbp+8h]
  int v79; // [rsp+2A8h] [rbp+10h]
  int v80; // [rsp+2B0h] [rbp+18h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle **v81; // [rsp+2B8h] [rbp+20h]

  v78 = this;
  v1 = this;
  v2 = this->m_mesh.m_triangles.m_numUsed + 2 * this->m_mesh.m_triangles.m_numUsed + 1;
  v80 = v2;
  do
  {
    v3 = v1->m_mesh.m_triangles.m_used;
    v79 = 0;
    if ( !v3 )
      break;
    do
    {
      v4 = 0;
      do
      {
        v5 = v4 + 5i64;
        v6 = *((_QWORD *)&v3->m_next + v5);
        v81 = &v3->m_next + v5;
        if ( !(v6 & 0xFFFFFFFFFFFFFFFCui64) )
          goto LABEL_64;
        v7 = *((_QWORD *)&v3->m_next + v4 + 2i64);
        v8 = v3->m_vertices[(9i64 >> 2 * (unsigned __int8)v4) & 3];
        v9 = *(_DWORD *)(v7 + 16);
        v10 = v8->m_x;
        if ( v9 < v10 || v9 <= v10 && *(_DWORD *)(v7 + 20) <= v8->m_y )
        {
          v12 = (unsigned __int64)v3;
          v11 = v4;
        }
        else
        {
          v11 = v6 & 3;
          v12 = v6 & 0xFFFFFFFFFFFFFFFCui64;
        }
        if ( (1 << v11) & 7 & *(_BYTE *)(v12 + 66) )
          goto LABEL_64;
        v13 = *(_QWORD *)((v6 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((18i64 >> 2 * ((unsigned __int8)v6 & 3u)) & 3) + 16);
        v14 = *(_DWORD *)(v13 + 20);
        v15 = v8->m_y - v14;
        v16 = v3->m_vertices[(18i64 >> 2 * (unsigned __int8)v4) & 3];
        v17 = *(_DWORD *)(v13 + 16);
        v18 = v16->m_x - v17;
        v19 = v8->m_x - v17;
        v20 = v16->m_y - v14;
        v21 = *(_DWORD *)(v7 + 16) - v17;
        if ( -((v15 * v15 + v19 * v19) * (signed __int64)((*(_DWORD *)(v7 + 20) - v14) * v18 - v21 * v20)
             + (v19 * v20 - v15 * v18)
             * (signed __int64)((*(_DWORD *)(v7 + 20) - v14) * (*(_DWORD *)(v7 + 20) - v14) + v21 * v21)
             + (v15 * v21 - v19 * (*(_DWORD *)(v7 + 20) - v14)) * (signed __int64)(v20 * v20 + v18 * v18)) >= 0 )
          goto LABEL_64;
        v22 = *(_DWORD *)(v7 + 16);
        v23 = v8->m_x;
        if ( v22 < v23 || v22 <= v23 && *(_DWORD *)(v7 + 20) <= v8->m_y )
        {
          v25 = (unsigned __int64)v3;
          v24 = v4;
        }
        else
        {
          v24 = v6 & 3;
          v25 = v6 & 0xFFFFFFFFFFFFFFFCui64;
        }
        if ( (unsigned __int8)(1 << v24) & (unsigned __int8)*(_WORD *)(v25 + 66) & 7
          || (v26 = v6 & 3,
              v27 = v6 & 0xFFFFFFFFFFFFFFFCui64,
              v28 = (18 >> 2 * v4) & 3,
              v29 = *(_QWORD *)(v27 + 8i64 * ((18 >> 2 * v26) & 3) + 16),
              v30 = v3->m_vertices[v28],
              (*(_DWORD *)(v7 + 16) - v30->m_x) * (*(_DWORD *)(v29 + 20) - v30->m_y)
            - (*(_DWORD *)(v29 + 16) - v30->m_x) * (*(_DWORD *)(v7 + 20) - v30->m_y) <= 0)
          || (v31 = *(_QWORD *)(v27 + 8i64 * v26 + 16),
              (*(_DWORD *)(v31 + 16) - *(_DWORD *)(v29 + 16)) * (v30->m_y - *(_DWORD *)(v29 + 20))
            - (*(_DWORD *)(v31 + 20) - *(_DWORD *)(v29 + 20)) * (v30->m_x - *(_DWORD *)(v29 + 16)) <= 0) )
        {
LABEL_64:
          v73 = v79;
        }
        else
        {
          v32 = v3->m_vertices[v28];
          v75 = 2 * v28;
          v33 = v32->m_x;
          v34 = v3->m_vertices[(9i64 >> 2 * (unsigned __int8)v28) & 3];
          v35 = v34->m_x;
          if ( v33 >= v35
            && (v33 > v35 || v32->m_y > v34->m_y)
            && (v36 = v3->m_links[v28], v36 & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v37 = v3->m_links[v28] & 3;
            v38 = v36 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v38 = (unsigned __int64)v3;
            LOBYTE(v37) = (18 >> 2 * v4) & 3;
          }
          v39 = *(_WORD *)(v38 + 66);
          v40 = (unsigned __int8)v39 & (1 << v37) & 7;
          *(_WORD *)(v38 + 66) = v39 & (~((unsigned __int8)v39 & (1 << v37) & 7) | 0xFFF8);
          v41 = (unsigned __int64)*v81 & 0xFFFFFFFFFFFFFFFCui64;
          LODWORD(v38) = (18 >> 2 * ((unsigned __int64)*v81 & 3)) & 3;
          v42 = *(_QWORD *)(v41 + 8i64 * (signed int)v38 + 16);
          v43 = *(_DWORD *)(v42 + 16);
          v44 = *(_QWORD *)(v41 + 8 * ((9i64 >> 2 * ((18 >> 2 * ((unsigned __int64)*v81 & 3)) & 3u)) & 3) + 16);
          v45 = *(_DWORD *)(v44 + 16);
          if ( v43 >= v45
            && (v43 > v45 || *(_DWORD *)(v42 + 20) > *(_DWORD *)(v44 + 20))
            && (v46 = *(_QWORD *)(v41 + 8i64 * (signed int)v38 + 40), v46 & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v38 = *(_QWORD *)(v41 + 8i64 * (signed int)v38 + 40) & 3i64;
            v47 = v46 & 0xFFFFFFFFFFFFFFFCui64;
          }
          else
          {
            v47 = (unsigned __int64)*v81 & 0xFFFFFFFFFFFFFFFCui64;
          }
          v48 = *(_WORD *)(v47 + 66);
          v49 = (unsigned __int8)v48 & (1 << v38) & 7;
          *(_WORD *)(v47 + 66) = v48 & (~((unsigned __int8)v48 & (1 << v38) & 7) | 0xFFF8);
          v50 = (unsigned __int64)*v81 & 0xFFFFFFFFFFFFFFFCui64;
          v51 = (unsigned __int64)*v81 & 3;
          v52 = (18 >> 2 * v51) & 3;
          *((_QWORD *)&v3->m_next + v4 + 2i64) = *(_QWORD *)(v50 + 8i64 * v52 + 16);
          v53 = (signed int)v51;
          *(_QWORD *)(v50 + 8 * v53 + 16) = v3->m_vertices[v28];
          v54 = v3->m_links[v28] & 0xFFFFFFFFFFFFFFFCui64;
          v55 = v3->m_links[v28] & 3;
          *(_QWORD *)(v50 + 8 * v53 + 40) = v54 + (v3->m_links[v28] & 3);
          if ( v54 )
            *(_QWORD *)(v54 + 8i64 * v55 + 40) = v50 + (unsigned int)v51;
          v56 = *(_QWORD *)(v50 + 8i64 * v52 + 40) & 0xFFFFFFFFFFFFFFFCui64;
          v57 = *(_DWORD *)(v50 + 8i64 * v52 + 40) & 3;
          *v81 = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v56 + (*(_QWORD *)(v50 + 8i64 * v52 + 40) & 3i64));
          if ( v56 )
            *(_QWORD *)(v56 + 8i64 * v57 + 40) = (char *)v3 + (unsigned int)v4;
          v3->m_links[v28] = v50 + (unsigned int)v52;
          if ( v50 )
            *(_QWORD *)(v50 + 8i64 * v52 + 40) = (char *)v3 + (unsigned int)v28;
          if ( v40 )
          {
            v58 = v3->m_links[v28] & 0xFFFFFFFFFFFFFFFCui64;
            LODWORD(v59) = (9 >> 2 * (v3->m_links[v28] & 3)) & 3;
            v60 = *(_QWORD *)(v58 + 8i64 * (signed int)v59 + 16);
            v61 = *(_DWORD *)(v60 + 16);
            v62 = *(_QWORD *)(v58 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v3->m_links[v28] & 3)) & 3u)) & 3) + 16);
            v63 = *(_DWORD *)(v62 + 16);
            if ( v61 >= v63
              && (v61 > v63 || *(_DWORD *)(v60 + 20) > *(_DWORD *)(v62 + 20))
              && (v64 = *(_QWORD *)(v58 + 8i64 * (signed int)v59 + 40), v64 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v59 = *(_QWORD *)(v58 + 8i64 * (signed int)v59 + 40) & 3i64;
              v65 = v64 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v65 = v3->m_links[v28] & 0xFFFFFFFFFFFFFFFCui64;
            }
            *(_WORD *)(v65 + 66) ^= ((unsigned __int8)*(_WORD *)(v65 + 66) ^ (unsigned __int8)(*(unsigned __int16 *)(v65 + 66) | (1 << v59))) & 7;
          }
          if ( v49 )
          {
            LODWORD(v66) = (9 >> v75) & 3;
            v67 = v3->m_vertices[(signed int)v66];
            v68 = v67->m_x;
            v69 = v3->m_vertices[(9i64 >> 2 * ((9 >> v75) & 3u)) & 3];
            v70 = v69->m_x;
            if ( v68 >= v70
              && (v68 > v70 || v67->m_y > v69->m_y)
              && (v71 = v3->m_links[(signed int)v66], v71 & 0xFFFFFFFFFFFFFFFCui64) )
            {
              v66 = v3->m_links[(signed int)v66] & 3;
              v72 = v71 & 0xFFFFFFFFFFFFFFFCui64;
            }
            else
            {
              v72 = (unsigned __int64)v3;
            }
            *(_WORD *)(v72 + 66) ^= ((unsigned __int8)*(_WORD *)(v72 + 66) ^ (unsigned __int8)(*(unsigned __int16 *)(v72 + 66) | (1 << v66))) & 7;
          }
          v73 = v79++ + 1;
        }
        ++v4;
      }
      while ( v4 < 3 );
      v3 = v3->m_next;
    }
    while ( v3 );
    v74 = v73 == 0;
    v2 = v80;
    if ( v74 )
      break;
    v1 = v78;
    v2 = v80 - 1;
    v80 = v2;
  }
  while ( v2 );
  if ( !v2 )
  {
    hkErrStream::hkErrStream(&v76, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v76.vfptr, "Infinite cycle detected during triangulation");
    hkError::messageWarning(
      220653181,
      &buf,
      "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
      2034);
    hkOstream::~hkOstream((hkOstream *)&v76.vfptr);
  }
}

// File Line: 2175
// RVA: 0x12ED100
__int64 __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::decomposeFastFixedSize(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this, hkArrayBase<unsigned int> *pieceSize, void *_storage, int capacity, int *numEdgesOut, int *maxEdgesPerPieceOut)
{
  int *v6; // r9
  UidItem *v7; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v8; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v9; // r8
  int *v10; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v11; // r8
  unsigned __int16 v12; // ax
  UidItem *v13; // r11
  unsigned int v14; // edx
  signed int v15; // er14
  int v16; // er12
  int v17; // esi
  int v18; // er15
  signed int v19; // ebp
  UidItem *v20; // rbx
  __int64 v21; // rcx
  signed __int64 v22; // r8
  unsigned __int64 v23; // rdi
  __int16 v24; // cx
  unsigned __int64 v25; // r10
  __int64 v26; // r9
  unsigned __int64 v27; // r12
  __int64 v28; // r13
  __int64 v29; // r11
  __int64 v30; // r8
  __int64 v31; // rcx
  __int64 v32; // r8
  __int64 v33; // rcx
  signed __int64 v35; // [rsp+20h] [rbp-88h]
  UidItem *v36; // [rsp+28h] [rbp-80h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v37; // [rsp+30h] [rbp-78h]
  char v38; // [rsp+38h] [rbp-70h]
  hkArrayBase<UidItem> v39; // [rsp+40h] [rbp-68h]
  UidItem t; // [rsp+50h] [rbp-58h]
  __int64 v41; // [rsp+68h] [rbp-40h]
  int v42; // [rsp+B0h] [rbp+8h]
  hkArrayBase<unsigned int> *v43; // [rsp+B8h] [rbp+10h]
  unsigned int v44; // [rsp+C0h] [rbp+18h]

  v43 = pieceSize;
  v6 = &v42;
  *maxEdgesPerPieceOut = -1;
  v7 = (UidItem *)_storage;
  *numEdgesOut = 0;
  v8 = this->m_mesh.m_triangles.m_used;
  v9 = this;
  if ( !v8 )
    v6 = 0i64;
  if ( v6 )
  {
    do
    {
      *((_WORD *)v8 + 50) &= 0xFFEFu;
      v8 = v8->m_next;
      v10 = &v42;
      if ( !v8 )
        v10 = 0i64;
    }
    while ( v10 );
  }
  v11 = v9->m_mesh.m_triangles.m_used;
  v37 = v11;
  if ( !v11 )
    return (unsigned int)pieceSize->m_size;
  do
  {
    v12 = *((_WORD *)v11 + 50);
    if ( v12 & 0x10 || !(v12 & 0x20) )
      goto LABEL_37;
    v13 = v7;
    v36 = v7;
    v14 = (unsigned int)v12 >> 5;
    v44 = (unsigned int)v12 >> 5;
    if ( v7 )
    {
      v7->uid = (unsigned __int64)v11;
      v7->patchIndex = 0;
    }
    if ( v7 != (UidItem *)-16i64 )
    {
      v7[1].uid = (unsigned __int64)v11;
      v7[1].patchIndex = 1;
    }
    if ( v7 != (UidItem *)-32i64 )
    {
      v7[2].uid = (unsigned __int64)v11;
      v7[2].patchIndex = 2;
    }
    *((_WORD *)v11 + 50) |= 0x10u;
    v15 = 3;
    v35 = (signed __int64)&v7[3];
    do
    {
      v16 = 0;
      v42 = 0;
      v17 = 0;
      v18 = v15;
      if ( v15 <= 0 )
      {
        v7 = (UidItem *)v35;
        break;
      }
      v19 = 1;
      v20 = v13;
      do
      {
        v21 = v20->patchIndex;
        v22 = *(_QWORD *)(v20->uid + 8 * v21 + 40) & 3i64;
        v23 = *(_QWORD *)(v20->uid + 8 * v21 + 40) & 0xFFFFFFFFFFFFFFFCui64;
        if ( !v23 )
          goto LABEL_29;
        v24 = *(_WORD *)(v23 + 100);
        if ( (unsigned int)*(unsigned __int16 *)(v23 + 100) >> 5 != v14 || v24 & 0x10 )
          goto LABEL_29;
        v25 = v13[(v18 + v17 - 1) % v18].uid;
        v26 = *(_QWORD *)&v13[(v18 + v17 - 1) % v18].patchIndex;
        v27 = v13[v19 % v18].uid;
        v28 = *(_QWORD *)&v13[v19 % v18].patchIndex;
        v38 = 2 * v22;
        v29 = *(_QWORD *)(v23 + 8 * ((18i64 >> 2 * (unsigned __int8)v22) & 3) + 16);
        v30 = *(_QWORD *)(v25 + 8 * ((9i64 >> 2 * (unsigned __int8)v26) & 3) + 16);
        v31 = *(_QWORD *)(v25 + 8i64 * (signed int)v26 + 16);
        if ( (*(_DWORD *)(v29 + 20) - *(_DWORD *)(v31 + 20)) * (*(_DWORD *)(v30 + 16) - *(_DWORD *)(v31 + 16))
           - (*(_DWORD *)(v29 + 16) - *(_DWORD *)(v31 + 16)) * (*(_DWORD *)(v30 + 20) - *(_DWORD *)(v31 + 20)) < 0 )
        {
          v16 = v42;
LABEL_28:
          v14 = v44;
          v13 = v36;
LABEL_29:
          v7 = (UidItem *)v35;
          goto LABEL_30;
        }
        v32 = *(_QWORD *)(v27 + 8 * ((9i64 >> 2 * (unsigned __int8)v28) & 3) + 16);
        v33 = *(_QWORD *)(v27 + 8i64 * (signed int)v28 + 16);
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v17,
          &t);
        *(_WORD *)(v23 + 100) |= 0x10u;
        v7 = (UidItem *)(v35 + 16);
        --v17;
        --v19;
        --v20;
        v35 += 16i64;
        v39.m_size = 0;
        if ( v39.m_capacityAndFlags >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v39.m_data,
            16 * v39.m_capacityAndFlags);
          v7 = (UidItem *)v35;
        }
        v13 = v36;
        v14 = v44;
        v39.m_data = 0i64;
        v39.m_capacityAndFlags = 2147483648;
LABEL_30:
        ++v17;
        ++v19;
        ++v20;
      }
      while ( v17 < v18 );
    }
    while ( v16 );
    pieceSize = v43;
    v11 = v37;
    v43->m_data[v43->m_size] = v15;
    ++pieceSize->m_size;
    *numEdgesOut += v15;
    if ( *maxEdgesPerPieceOut > v15 )
      v15 = *maxEdgesPerPieceOut;
    *maxEdgesPerPieceOut = v15;
LABEL_37:
    v11 = v11->m_next;
    v37 = v11;
  }
  while ( v11 );
  return (unsigned int)pieceSize->m_size;
}

// File Line: 2243
// RVA: 0x12ED520
void __fastcall hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::flushConform(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *this)
{
  int v1; // ebp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v2; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v3; // r12
  __int64 v4; // r13
  int v5; // er15
  signed __int64 v6; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v7; // r9
  unsigned __int64 v8; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v9; // rbx
  char v10; // di
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v11; // r11
  int v12; // eax
  int v13; // ecx
  unsigned __int64 v14; // rax
  __int64 v15; // rdx
  int v16; // er8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v17; // rcx
  int v18; // eax
  int v19; // er9
  int v20; // esi
  int v21; // er10
  int v22; // ebx
  int v23; // edi
  int v24; // er9
  int v25; // er11
  signed __int64 v26; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v27; // r9
  unsigned __int64 v28; // r10
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v29; // r11
  char v30; // bl
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v31; // rdx
  int v32; // eax
  int v33; // ecx
  unsigned __int64 v34; // rax
  int v35; // esi
  unsigned __int64 v36; // r10
  __int64 v37; // rdi
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v38; // rbx
  int v39; // er8
  int v40; // edx
  __int64 v41; // r9
  int v42; // er9
  int v43; // eax
  int v44; // eax
  __int64 v45; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v46; // r8
  __int64 v47; // r9
  char v48; // cl
  signed __int64 v49; // r9
  unsigned __int64 v50; // rax
  int v51; // ecx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge result; // [rsp+30h] [rbp-268h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge edgeArg; // [rsp+48h] [rbp-250h]
  char buf; // [rsp+60h] [rbp-238h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0> *v55; // [rsp+2A0h] [rbp+8h]
  int v56; // [rsp+2A8h] [rbp+10h]
  hkResult v57; // [rsp+2B0h] [rbp+18h]

  v55 = this;
  v1 = this->m_stack.m_size;
  v2 = this;
  v56 = this->m_mesh.m_triangles.m_numUsed + 2 * this->m_mesh.m_triangles.m_numUsed + 1;
  do
  {
    v3 = v2->m_stack.m_data;
    v4 = v2->m_stack.m_size;
    v5 = v4 - 1;
    v6 = (signed int)v3[(signed int)v4 - 1].m_index;
    v7 = v3[(signed int)v4 - 1].m_triangle;
    v8 = v7->m_links[v6];
    if ( !(v8 & 0xFFFFFFFFFFFFFFFCui64) )
      goto LABEL_33;
    v9 = v7->m_vertices[v6];
    v10 = 2 * v6;
    v11 = v7->m_vertices[(9i64 >> 2 * (unsigned __int8)v6) & 3];
    v12 = v9->m_x;
    v13 = v11->m_x;
    if ( v12 < v13 || v12 <= v13 && v9->m_y <= v11->m_y )
    {
      v14 = (unsigned __int64)v3[v5].m_triangle;
    }
    else
    {
      v6 = v7->m_links[v6] & 3;
      v14 = v8 & 0xFFFFFFFFFFFFFFFCui64;
    }
    if ( (unsigned __int8)(1 << v6) & (unsigned __int8)*(_WORD *)(v14 + 100) & 7 )
      goto LABEL_33;
    v15 = *(_QWORD *)((v8 & 0xFFFFFFFFFFFFFFFCui64) + 8 * ((18i64 >> 2 * ((unsigned __int8)v8 & 3u)) & 3) + 16);
    v16 = *(_DWORD *)(v15 + 20);
    v17 = v7->m_vertices[(18i64 >> v10) & 3];
    v18 = *(_DWORD *)(v15 + 16);
    v19 = v9->m_y;
    v20 = v17->m_x - v18;
    v21 = v9->m_x - v18;
    v22 = v11->m_x - v18;
    v23 = v17->m_y - v16;
    v24 = v19 - v16;
    v25 = v11->m_y - v16;
    if ( -((v25 * v25 + v22 * v22) * (signed __int64)(v24 * v20 - v21 * v23)
         + (v22 * v23 - v25 * v20) * (signed __int64)(v24 * v24 + v21 * v21)
         + (v25 * v21 - v22 * v24) * (signed __int64)(v23 * v23 + v20 * v20)) >= 0 )
    {
LABEL_33:
      v2->m_stack.m_size = v5;
      --v1;
    }
    else
    {
      --v1;
      v26 = *((_QWORD *)&v3[v4] - 1);
      v27 = v3[v4 - 1].m_triangle;
      v2->m_stack.m_size = v5;
      edgeArg.m_triangle = v27;
      *(_QWORD *)&edgeArg.m_index = v26;
      v28 = v27->m_links[(signed int)v26];
      if ( v28 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        v29 = v27->m_vertices[(signed int)v26];
        v30 = 2 * v26;
        v31 = v27->m_vertices[(9i64 >> 2 * (unsigned __int8)v26) & 3];
        v32 = v29->m_x;
        v33 = v31->m_x;
        if ( v32 < v33 || v32 <= v33 && v29->m_y <= v31->m_y )
        {
          v34 = (unsigned __int64)v27;
        }
        else
        {
          v26 = v27->m_links[(signed int)v26] & 3;
          v34 = v28 & 0xFFFFFFFFFFFFFFFCui64;
        }
        if ( !((unsigned __int8)(1 << v26) & (unsigned __int8)*(_WORD *)(v34 + 100) & 7) )
        {
          v35 = v28 & 3;
          v36 = v28 & 0xFFFFFFFFFFFFFFFCui64;
          v37 = *(_QWORD *)(v36 + 8i64 * ((18 >> 2 * v35) & 3) + 16);
          v38 = v27->m_vertices[(18 >> v30) & 3];
          v39 = v38->m_y;
          v40 = v38->m_x;
          if ( (v29->m_x - v40) * (*(_DWORD *)(v37 + 20) - v39) - (v29->m_y - v39) * (*(_DWORD *)(v37 + 16) - v40) > 0 )
          {
            v41 = *(_QWORD *)(v36 + 8i64 * v35 + 16);
            if ( (*(_DWORD *)(v41 + 16) - *(_DWORD *)(v37 + 16)) * (v39 - *(_DWORD *)(v37 + 20))
               - (*(_DWORD *)(v41 + 20) - *(_DWORD *)(v37 + 20)) * (v40 - *(_DWORD *)(v37 + 16)) > 0 )
            {
              hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>::flipEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>(
                &v55->m_edgeDataPolicy,
                &result,
                &edgeArg);
              v42 = v55->m_stack.m_size + 2;
              v43 = v2->m_stack.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v43 >= v42 )
              {
                v57.m_enum = 0;
              }
              else
              {
                v44 = 2 * v43;
                if ( v42 < v44 )
                  v42 = v44;
                hkArrayUtil::_reserve(
                  &v57,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v2->m_stack,
                  v42,
                  16);
                if ( v57.m_enum == 1 )
                {
                  v55->m_status.m_storage = 1;
                  return;
                }
              }
              v45 = (signed int)result.m_index;
              v46 = result.m_triangle;
              v47 = v2->m_stack.m_size;
              v48 = 2 * LOBYTE(result.m_index);
              v2->m_stack.m_size += 2;
              v49 = (signed __int64)&v2->m_stack.m_data[v47];
              v1 += 2;
              *(_QWORD *)v49 = v46;
              *(_DWORD *)(v49 + 8) = (9 >> v48) & 3;
              v50 = v46->m_links[v45];
              *(_QWORD *)(v49 + 16) = v50 & 0xFFFFFFFFFFFFFFFCui64;
              *(_DWORD *)(v49 + 24) = (18 >> 2 * (v50 & 3)) & 3;
            }
          }
        }
      }
    }
    v51 = v56;
    if ( v1 <= 0 )
      break;
    v51 = v56 - 1;
    v56 = v51;
  }
  while ( v51 );
  if ( !v51 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&result, &buf, 512);
    hkOstream::operator<<((hkOstream *)&result, "Infinite cycle detected during triangulation");
    hkError::messageWarning(
      220653182,
      &buf,
      "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/Triangulator/hkgpTriangulator.inl",
      2284);
    hkOstream::~hkOstream((hkOstream *)&result);
  }
}

// File Line: 2296
// RVA: 0xB66CD0
void __fastcall hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::backupBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge>(hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *triangulator, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge, hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *state)
{
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *v4; // r14
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *v5; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0> *v6; // rbp
  signed int v7; // edi
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *v8; // rsi
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v9; // rax
  __int64 v10; // rcx
  unsigned __int64 v11; // rdx
  char v12; // al
  __int64 v13; // [rsp+28h] [rbp-10h]

  v4 = state;
  v5 = edge;
  v6 = triangulator;
  state->m_values[0].m_hasData = 0;
  state->m_values[1].m_hasData = 0;
  v7 = 0;
  v8 = state;
  do
  {
    v9 = hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::getEdgeData(
           v6,
           v5);
    if ( v9 )
    {
      hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
        (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)((char *)v4 + 8 * (v7 + 4i64 * v7 + 1)),
        v9);
      v8->m_values[0].m_hasData = 1;
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::clearEdgeData(
        v6,
        v5);
    }
    v10 = (signed int)v5->m_index;
    v11 = v5->m_triangle->m_links[v10];
    if ( !(v11 & 0xFFFFFFFFFFFFFFFCui64) )
      break;
    v12 = v5->m_triangle->m_links[v10];
    ++v7;
    v8 = (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *)((char *)v8 + 40);
    v5->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *)(v11 & 0xFFFFFFFFFFFFFFFCui64);
    LODWORD(v13) = v12 & 3;
    *(_QWORD *)&v5->m_index = v13;
  }
  while ( v7 < 2 );
}

// File Line: 2316
// RVA: 0xCD6E40
void __fastcall hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>>::restoreBothEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> > *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *triangulator, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *edge, hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *state)
{
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *v4; // rbp
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *v5; // rbx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0> *v6; // r14
  signed int v7; // esi
  hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *v8; // rdi
  __int64 v9; // rcx
  unsigned __int64 v10; // rdx
  char v11; // al
  __int64 v12; // [rsp+28h] [rbp-10h]

  v4 = state;
  v5 = edge;
  v6 = triangulator;
  v7 = 0;
  v8 = state;
  do
  {
    if ( v8->m_values[0].m_hasData )
      hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::setEdgeData(
        v6,
        v5,
        (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)((char *)v4 + 8 * (v7 + 4i64 * v7 + 1)));
    v9 = (signed int)v5->m_index;
    v10 = v5->m_triangle->m_links[v9];
    if ( !(v10 & 0xFFFFFFFFFFFFFFFCui64) )
      break;
    v11 = v5->m_triangle->m_links[v9];
    ++v7;
    v8 = (hkgpTriangulatorBase::EdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> >::EdgeDataState *)((char *)v8 + 40);
    v5->m_triangle = (hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Triangle *)(v10 & 0xFFFFFFFFFFFFFFFCui64);
    LODWORD(v12) = v11 & 3;
    *(_QWORD *)&v5->m_index = v12;
  }
  while ( v7 < 2 );
}

// File Line: 2331
// RVA: 0xCD7C40
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::~SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>(hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this)
{
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *v1; // rbx
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v2; // rcx

  v1 = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)this;
  v2 = this->m_edgeData;
  if ( v2 )
  {
    hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator>::`scalar deleting destructor'(
      v2,
      0);
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_firstPool,
      24);
    v1->m_firstPool = 0i64;
  }
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>(v1 + 1);
}

// File Line: 2345
// RVA: 0xCD9190
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::createEdgeDataHashTable(hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this)
{
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *v1; // r14
  __int64 v2; // rax
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v3; // rsi
  int v4; // ecx
  __int64 v5; // rbp
  int *v6; // rdi
  int v7; // er8
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  __int64 v12; // rbp
  int *v13; // rdi
  int v14; // er8
  signed __int64 v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // rcx
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = (*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, signed __int64))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor
        + 1))(
         &hkContainerHeapAllocator::s_alloc,
         24i64);
  v3 = (hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = 0i64;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 12) = 2147483648;
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
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v6 - 3),
            32 * v7);
        *(_QWORD *)(v6 - 3) = 0i64;
        *v6 = 2147483648;
        v6 -= 4;
        --v5;
      }
      while ( v5 >= 0 );
    }
    v3->m_buckets.m_size = 0;
    v3->m_numItems = 0;
    v8 = v3->m_buckets.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 >= 1031 )
    {
      result.m_enum = 0;
    }
    else
    {
      v9 = 2 * v8;
      v10 = 1031;
      if ( v9 > 1031 )
        v10 = v9;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v10, 16);
    }
    v11 = v3->m_buckets.m_size - 1032;
    v12 = v11;
    if ( v11 >= 0 )
    {
      v13 = &v3->m_buckets.m_data[1031].m_capacityAndFlags + 4 * v11;
      do
      {
        v14 = *v13;
        *(v13 - 1) = 0;
        if ( v14 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v13 - 3),
            32 * v14);
        *(_QWORD *)(v13 - 3) = 0i64;
        *v13 = 2147483648;
        v13 -= 4;
        --v12;
      }
      while ( v12 >= 0 );
    }
    v15 = (signed __int64)&v3->m_buckets.m_data[v3->m_buckets.m_size];
    v16 = 1031 - v3->m_buckets.m_size;
    if ( 1031 - v3->m_buckets.m_size > 0 )
    {
      do
      {
        if ( v15 )
        {
          *(_QWORD *)v15 = 0i64;
          *(_DWORD *)(v15 + 8) = 0;
          *(_DWORD *)(v15 + 12) = 2147483648;
        }
        v15 += 16i64;
        --v16;
      }
      while ( v16 );
    }
    v3->m_buckets.m_size = 1031;
    v17 = 0i64;
    do
    {
      ++v17;
      *((_DWORD *)&v3->m_buckets.m_data[v17] - 2) = 0;
    }
    while ( v17 < 1031 );
    v1->m_edgeData = v3;
  }
  else
  {
    v1->m_edgeData = 0i64;
  }
}

// File Line: 2355
// RVA: 0xCD6780
hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *__fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::getEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *edge)
{
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v2; // r11
  __int64 v3; // rbx
  int v4; // ecx
  __int64 v5; // r10
  __int64 v6; // r9
  __int64 v7; // rcx
  int v8; // edx
  unsigned __int64 v9; // rax
  __int64 v10; // r8
  _QWORD *v11; // r11
  _QWORD *v12; // rax
  signed __int64 v14; // rax

  if ( !edge->m_triangle )
    return 0i64;
  v2 = this->m_edgeData;
  if ( !this->m_edgeData )
    return 0i64;
  v3 = 0i64;
  v4 = _mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)edge, 8));
  v5 = *(_QWORD *)(*(unsigned __int128 *)edge + 8i64 * v4 + 16);
  v6 = *(_QWORD *)(*(unsigned __int128 *)edge + 8 * ((9i64 >> 2 * (unsigned __int8)v4) & 3) + 16);
  v7 = 0i64;
  v8 = 0;
  v9 = (unsigned __int64)&v2->m_buckets.m_data[((unsigned int)(3424933
                                                             * (*(_DWORD *)(v5 + 20) + (*(_DWORD *)(v5 + 16) << 15))) ^ (unsigned __int64)(unsigned int)(1661161 * (*(_DWORD *)(v6 + 20) + (*(_DWORD *)(v6 + 16) << 15))))
                                             % (unsigned int)v2->m_buckets.m_size];
  v10 = *(signed int *)(v9 + 8);
  if ( v10 > 0 )
  {
    v11 = *(_QWORD **)v9;
    v12 = *(_QWORD **)v9;
    while ( *v12 != v5 || v12[1] != v6 )
    {
      ++v7;
      ++v8;
      v12 += 4;
      if ( v7 >= v10 )
        return 0i64;
    }
    if ( v8 != -1 )
    {
      v14 = (signed __int64)&v11[4 * v8];
      if ( v14 )
        v3 = *(_QWORD *)(v14 + 24);
    }
  }
  return (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)v3;
}

// File Line: 2369
// RVA: 0xCD6EF0
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::setEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *edge, hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *data)
{
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v3; // r14
  __m128i *v4; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *v5; // r15
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v6; // r9
  __int64 v7; // rdx
  int v8; // ecx
  __int64 v9; // rbp
  signed __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rsi
  signed __int64 v13; // r12
  int v14; // edx
  unsigned __int64 v15; // r10
  __int64 v16; // r8
  _QWORD *v17; // r10
  _QWORD *v18; // rax
  signed __int64 v19; // rbx
  signed int v20; // edx
  signed __int64 v21; // rdi
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v24; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item *v25; // rdx
  _DWORD *v26; // rbx
  int v27; // esi
  __int64 v28; // rdi
  __int64 v29; // r10
  int v30; // edx
  __int64 v31; // rcx
  _QWORD *v32; // rax
  unsigned __int64 *v33; // r15

  v3 = data;
  v4 = (__m128i *)edge;
  v5 = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *)this;
  if ( !this->m_edgeData )
    hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::createEdgeDataHashTable(this);
  v6 = v5->m_firstPool;
  v7 = (__int64)*v4;
  v8 = _mm_cvtsi128_si32(_mm_srli_si128(*v4, 8));
  v9 = *(_QWORD *)(v7 + 8i64 * v8 + 16);
  v10 = 9i64 >> 2 * (unsigned __int8)v8;
  v11 = 0i64;
  v12 = *(_QWORD *)(v7 + 8 * (v10 & 3) + 16);
  v13 = 3424933i64 * (*(_DWORD *)(v9 + 20) + (*(_DWORD *)(v9 + 16) << 15)) ^ 1661161i64
                                                                           * (*(_DWORD *)(v12 + 20)
                                                                            + (*(_DWORD *)(v12 + 16) << 15));
  v14 = 0;
  v15 = *(_QWORD *)v5->m_firstPool->m_items[0].m_data
      + 16
      * (((unsigned int)(3424933 * (*(_DWORD *)(v9 + 20) + (*(_DWORD *)(v9 + 16) << 15))) ^ (unsigned __int64)(unsigned int)(1661161 * (*(_DWORD *)(v12 + 20) + (*(_DWORD *)(v12 + 16) << 15))))
       % *(unsigned int *)&v5->m_firstPool->m_items[0].m_data[8]);
  v16 = *(signed int *)(v15 + 8);
  if ( v16 <= 0 )
    goto LABEL_8;
  v17 = *(_QWORD **)v15;
  v18 = v17;
  while ( *v18 != v9 || v18[1] != v12 )
  {
    ++v11;
    ++v14;
    v18 += 4;
    if ( v11 >= v16 )
      goto LABEL_8;
  }
  if ( v14 == -1 )
LABEL_8:
    v19 = 0i64;
  else
    v19 = (signed __int64)&v17[4 * v14];
  if ( !v19 )
  {
    ++*(_DWORD *)&v6->m_items[0].m_data[16];
    v20 = (unsigned int)v13 % *(_DWORD *)&v6->m_items[0].m_data[8];
    v21 = *(_QWORD *)v6->m_items[0].m_data + 16i64 * v20;
    if ( *(_DWORD *)(v21 + 8) == (*(_DWORD *)(v21 + 12) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (void *)(*(_QWORD *)v6->m_items[0].m_data + 16i64 * v20),
        32);
    v22 = (_QWORD *)(*(_QWORD *)v21 + 32i64 * *(signed int *)(v21 + 8));
    if ( v22 )
    {
      v22[3] = 0i64;
      v22[1] = 0i64;
      *v22 = 0i64;
    }
    v23 = (_QWORD *)(*(_QWORD *)v21 + 32i64 * (signed int)(*(_DWORD *)(v21 + 8))++);
    *v23 = v9;
    v23[1] = v12;
    v23[2] = v13;
    v23[3] = 0i64;
    v24 = v5[1].m_firstPool;
    v19 = *(_QWORD *)v21 + 32i64 * (*(_DWORD *)(v21 + 8) - 1);
    if ( !v24 || !v24->m_free )
      v24 = hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(v5 + 1);
    if ( v24 )
    {
      v25 = v24->m_free;
      v24->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Item **)v25->m_data;
      v25->m_pool = v24;
      ++v24->m_used;
      *(_DWORD *)&v25->m_data[8] = 0;
      *(_DWORD *)&v25->m_data[12] = -2147483646;
      *(_QWORD *)v25->m_data = (char *)v25 + 16;
    }
    else
    {
      v25 = 0i64;
    }
    *(_QWORD *)(v19 + 24) = v25;
  }
  v26 = *(_DWORD **)(v19 + 24);
  v27 = 0;
  if ( v3->m_tags.m_size > 0 )
  {
    v28 = 0i64;
    do
    {
      v29 = (signed int)v26[2];
      v30 = 0;
      v31 = 0i64;
      if ( (signed int)v29 <= 0 )
        goto LABEL_31;
      v32 = *(_QWORD **)v26;
      while ( *v32 != v3->m_tags.m_data[v28] )
      {
        ++v31;
        ++v30;
        ++v32;
        if ( v31 >= v29 )
          goto LABEL_31;
      }
      if ( v30 == -1 )
      {
LABEL_31:
        v33 = v3->m_tags.m_data;
        if ( (_DWORD)v29 == (v26[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v26, 8);
        *(_QWORD *)(*(_QWORD *)v26 + 8i64 * (signed int)v26[2]++) = v33[v28];
      }
      ++v27;
      ++v28;
    }
    while ( v27 < v3->m_tags.m_size );
  }
}(_QWORD *)v26 + 8i64 * (signed int)v26[2]++) = v33[v28];
      }
      ++v27;
      ++v28;
   

// File Line: 2387
// RVA: 0xCD6440
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::clearEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge>(hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Edge *edge)
{
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v2; // r8
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *v3; // r14
  signed int v4; // ebx
  int v5; // ecx
  __int64 v6; // rsi
  signed __int64 v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rdi
  signed __int64 v10; // rbp
  int v11; // edx
  unsigned __int64 v12; // r9
  __int64 v13; // r8
  _QWORD *v14; // r9
  _QWORD *v15; // rax
  signed __int64 v16; // rdx
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v17; // rcx
  int v18; // edx
  signed __int64 v19; // r9
  __int64 v20; // rcx
  __int64 v21; // r11
  _QWORD *v22; // r10
  _QWORD *v23; // rax
  __int64 v24; // rcx
  _QWORD *v25; // rax
  signed __int64 v26; // r8
  signed __int64 v27; // rax
  __int64 v28; // rcx

  v2 = this->m_edgeData;
  v3 = this;
  if ( this->m_edgeData )
  {
    v4 = 0;
    v5 = _mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)edge, 8));
    v6 = *(_QWORD *)(*(unsigned __int128 *)edge + 8i64 * v5 + 16);
    v7 = 9i64 >> 2 * (unsigned __int8)v5;
    v8 = 0i64;
    v9 = *(_QWORD *)(*(unsigned __int128 *)edge + 8 * (v7 & 3) + 16);
    v10 = 3424933i64 * (*(_DWORD *)(v6 + 20) + (*(_DWORD *)(v6 + 16) << 15)) ^ 1661161i64
                                                                             * (*(_DWORD *)(v9 + 20)
                                                                              + (*(_DWORD *)(v9 + 16) << 15));
    v11 = 0;
    v12 = (unsigned __int64)&v2->m_buckets.m_data[((unsigned int)(3424933
                                                                * (*(_DWORD *)(v6 + 20) + (*(_DWORD *)(v6 + 16) << 15))) ^ (unsigned __int64)(unsigned int)(1661161 * (*(_DWORD *)(v9 + 20) + (*(_DWORD *)(v9 + 16) << 15))))
                                                % (unsigned int)v2->m_buckets.m_size];
    v13 = *(signed int *)(v12 + 8);
    if ( v13 > 0 )
    {
      v14 = *(_QWORD **)v12;
      v15 = v14;
      while ( *v15 != v6 || v15[1] != v9 )
      {
        ++v8;
        ++v11;
        v15 += 4;
        if ( v8 >= v13 )
          return;
      }
      if ( v11 != -1 )
      {
        v16 = (signed __int64)&v14[4 * v11];
        if ( v16 )
        {
          hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::release(
            &v3->m_edgeDataAllocator,
            *(hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> **)(v16 + 24));
          v17 = v3->m_edgeData;
          --v17->m_numItems;
          v18 = 0;
          v19 = (signed __int64)&v17->m_buckets.m_data[(unsigned int)v10 % v17->m_buckets.m_size];
          v20 = 0i64;
          v21 = *(signed int *)(v19 + 8);
          if ( (signed int)v21 > 0 )
          {
            v22 = *(_QWORD **)v19;
            v23 = *(_QWORD **)v19;
            while ( *v23 != v6 || v23[1] != v9 )
            {
              ++v20;
              ++v18;
              v23 += 4;
              if ( v20 >= v21 )
                return;
            }
            if ( v18 >= 0 )
            {
              v24 = 0i64;
              if ( (signed int)v21 <= 0 )
              {
LABEL_22:
                v4 = -1;
              }
              else
              {
                v25 = *(_QWORD **)v19;
                while ( *v25 != v6 || v25[1] != v9 )
                {
                  ++v24;
                  ++v4;
                  v25 += 4;
                  if ( v24 >= v21 )
                    goto LABEL_22;
                }
              }
              *(_DWORD *)(v19 + 8) = v21 - 1;
              if ( (_DWORD)v21 - 1 != v4 )
              {
                v26 = 4i64;
                v27 = (signed __int64)&v22[4 * v4];
                do
                {
                  v28 = *(_QWORD *)(32i64 * ((signed int)v21 - 1) - 32i64 * v4 + v27);
                  v27 += 8i64;
                  *(_QWORD *)(v27 - 8) = v28;
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
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::setEdgeData<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge>(hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge, hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *data)
{
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v3; // r14
  char *v4; // rbx
  int v5; // ebp
  __int64 v6; // rsi
  __int64 v7; // r10
  int v8; // edx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  unsigned __int64 *v11; // rdi
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> __that; // [rsp+20h] [rbp-28h]

  v3 = data;
  v4 = (char *)edge->m_triangle + 40 * (signed int)edge->m_index;
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
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        __that.m_tags.m_data,
        8 * __that.m_tags.m_capacityAndFlags);
    v4[64] = 1;
  }
  v5 = 0;
  if ( v3->m_tags.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = *((signed int *)v4 + 20);
      v8 = 0;
      v9 = 0i64;
      if ( (signed int)v7 <= 0 )
        goto LABEL_13;
      v10 = (_QWORD *)*((_QWORD *)v4 + 9);
      while ( *v10 != v3->m_tags.m_data[v6] )
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
        v11 = v3->m_tags.m_data;
        if ( (_DWORD)v7 == (*((_DWORD *)v4 + 21) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4 + 72, 8);
        *(_QWORD *)(*((_QWORD *)v4 + 9) + 8i64 * (signed int)(*((_DWORD *)v4 + 20))++) = v11[v6];
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v3->m_tags.m_size );
  }
}

// File Line: 2440
// RVA: 0x12EB640
hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *__fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>::flipEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>(hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *result, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *edgeArg)
{
  __int64 v3; // rax
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v4; // r10
  __int64 v5; // r12
  unsigned __int64 v6; // r9
  int v7; // edi
  char v8; // cl
  signed __int64 v9; // rcx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v10; // r8
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v11; // rdx
  int v12; // eax
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
  signed __int64 v29; // r14
  __int64 v30; // rdx
  int v31; // ebp
  unsigned __int64 v32; // r11
  int v33; // er12
  unsigned __int64 v34; // rdx
  int v35; // er11
  unsigned __int64 v36; // rdx
  signed __int64 v37; // r9
  __int64 v38; // rbx
  __int64 v39; // r11
  int v40; // eax
  int v41; // ecx
  __int64 v42; // r11
  unsigned __int64 v43; // r11
  signed __int64 v44; // rdx
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v45; // r11
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex *v46; // r9
  int v47; // eax
  int v48; // ecx
  unsigned __int64 v49; // r9
  unsigned __int64 v50; // r9
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Triangle *v51; // r9
  signed __int64 v52; // rdx
  signed __int64 v53; // rcx
  _DWORD *v54; // rcx
  int v55; // eax
  unsigned __int64 v56; // r9
  char v57; // r8
  int v58; // er8
  signed __int64 v59; // rdx
  signed __int64 v60; // rcx
  signed __int64 v61; // rcx
  int v63; // [rsp+0h] [rbp-88h]
  unsigned int v64; // [rsp+4h] [rbp-84h]
  int v65; // [rsp+8h] [rbp-80h]
  int v66; // [rsp+Ch] [rbp-7Ch]
  unsigned int v67; // [rsp+10h] [rbp-78h]
  int v68; // [rsp+14h] [rbp-74h]
  unsigned int v69; // [rsp+18h] [rbp-70h]
  int v70; // [rsp+1Ch] [rbp-6Ch]
  int v71; // [rsp+20h] [rbp-68h]
  unsigned __int64 *v72; // [rsp+28h] [rbp-60h]
  __int64 v73; // [rsp+30h] [rbp-58h]
  int v74; // [rsp+38h] [rbp-50h]
  __int64 v75; // [rsp+40h] [rbp-48h]
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge *v76; // [rsp+98h] [rbp+10h]
  int v77; // [rsp+A0h] [rbp+18h]
  int v78; // [rsp+A8h] [rbp+20h]

  v76 = result;
  result->m_triangle = edgeArg->m_triangle;
  v3 = *(_QWORD *)&edgeArg->m_index;
  *(_QWORD *)&result->m_index = v3;
  v4 = result->m_triangle;
  v5 = (signed int)v3;
  v75 = (signed int)v3;
  v6 = result->m_triangle->m_links[(signed int)v3] & 0xFFFFFFFFFFFFFFFCui64;
  v7 = (18 >> 2 * v3) & 3;
  v65 = *(_DWORD *)&result->m_triangle->m_edgeData[(9 >> 2 * v3) & 3].m_hasData;
  v74 = result->m_triangle->m_edgeData[(9 >> 2 * v3) & 3].m_data.m_tag;
  v67 = result->m_triangle->m_edgeData[(9 >> 2 * v3) & 3].m_data.m_sets;
  v71 = *(_DWORD *)&result->m_triangle->m_edgeData[v7].m_hasData;
  v63 = result->m_triangle->m_edgeData[v7].m_data.m_tag;
  v8 = 2 * (result->m_triangle->m_links[(signed int)v3] & 3);
  v64 = result->m_triangle->m_edgeData[v7].m_data.m_sets;
  v66 = *(_DWORD *)(v6 + 12i64 * ((9 >> v8) & 3) + 64);
  v68 = *(_DWORD *)(v6 + 12i64 * ((9 >> v8) & 3) + 68);
  v70 = *(_DWORD *)(v6 + 12i64 * ((9 >> v8) & 3) + 72);
  v9 = 3i64 * ((18 >> v8) & 3);
  v77 = *(_DWORD *)(v6 + 4 * v9 + 64);
  v78 = *(_DWORD *)(v6 + 4 * v9 + 68);
  v69 = *(_DWORD *)(v6 + 4 * v9 + 72);
  v10 = result->m_triangle->m_vertices[v7];
  v11 = result->m_triangle->m_vertices[(9i64 >> 2 * ((18 >> 2 * v3) & 3u)) & 3];
  v12 = v10->m_x;
  v13 = v11->m_x;
  if ( v12 >= v13 && (v12 > v13 || v10->m_y > v11->m_y) && (v14 = v4->m_links[v7], v14 & 0xFFFFFFFFFFFFFFFCui64) )
  {
    v15 = v14 & 3;
    v16 = v14 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v16 = (unsigned __int64)v4;
    v15 = v7;
  }
  v17 = *(_WORD *)(v16 + 100);
  v18 = (unsigned __int8)v17 & (1 << v15) & 7;
  *(_WORD *)(v16 + 100) = v17 & (~((unsigned __int8)v17 & (1 << v15) & 7) | 0xFFF8);
  v19 = v4->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  LODWORD(v16) = (18 >> 2 * (v4->m_links[v5] & 3)) & 3;
  v20 = *(_QWORD *)(v19 + 8i64 * (signed int)v16 + 16);
  v21 = *(_QWORD *)(v19 + 8 * ((9i64 >> 2 * ((18 >> 2 * (v4->m_links[v5] & 3)) & 3u)) & 3) + 16);
  v22 = *(_DWORD *)(v20 + 16);
  v23 = *(_DWORD *)(v21 + 16);
  if ( v22 >= v23
    && (v22 > v23 || *(_DWORD *)(v20 + 20) > *(_DWORD *)(v21 + 20))
    && (v24 = *(_QWORD *)(v19 + 8i64 * (signed int)v16 + 40), v24 & 0xFFFFFFFFFFFFFFFCui64) )
  {
    v16 = *(_QWORD *)(v19 + 8i64 * (signed int)v16 + 40) & 3i64;
    v25 = v24 & 0xFFFFFFFFFFFFFFFCui64;
  }
  else
  {
    v25 = v4->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  }
  v26 = *(_WORD *)(v25 + 100);
  v27 = (unsigned __int8)v26 & (1 << v16) & 7;
  *(_WORD *)(v25 + 100) = v26 & (~((unsigned __int8)v26 & (1 << v16) & 7) | 0xFFF8);
  v28 = v4->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64;
  v29 = v4->m_links[v5] & 3;
  v30 = (signed int)v29;
  v31 = (18 >> 2 * v29) & 3;
  v4->m_vertices[v5] = *(hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Vertex **)(v28 + 8i64 * v31 + 16);
  *(_QWORD *)(v28 + 8 * v30 + 16) = v4->m_vertices[v7];
  v72 = &v4->m_links[v7];
  v32 = *v72 & 0xFFFFFFFFFFFFFFFCui64;
  v33 = *(_DWORD *)v72 & 3;
  *(_QWORD *)(v28 + 8 * v30 + 40) = v32 + (*v72 & 3);
  if ( v32 )
    *(_QWORD *)(v32 + 8i64 * v33 + 40) = v28 + (unsigned int)v29;
  v34 = *(_QWORD *)(v28 + 8i64 * v31 + 40) & 0xFFFFFFFFFFFFFFFCui64;
  v35 = *(_DWORD *)(v28 + 8i64 * v31 + 40) & 3;
  v4->m_links[v75] = v34 + (*(_QWORD *)(v28 + 8i64 * v31 + 40) & 3i64);
  if ( v34 )
    *(_QWORD *)(v34 + 8i64 * v35 + 40) = (char *)v4 + v76->m_index;
  *v72 = v28 + (unsigned int)v31;
  if ( v28 )
    *(_QWORD *)(v28 + 8i64 * v31 + 40) = (char *)v4 + (unsigned int)v7;
  LODWORD(v73) = v7;
  if ( v18 )
  {
    v36 = v4->m_links[v7] & 0xFFFFFFFFFFFFFFFCui64;
    LODWORD(v37) = (9 >> 2 * (v4->m_links[v7] & 3)) & 3;
    v38 = *(_QWORD *)(v36 + 8i64 * (signed int)v37 + 16);
    v39 = *(_QWORD *)(v36 + 8 * ((9i64 >> 2 * ((9 >> 2 * (v4->m_links[v7] & 3)) & 3u)) & 3) + 16);
    v40 = *(_DWORD *)(v38 + 16);
    v41 = *(_DWORD *)(v39 + 16);
    if ( v40 >= v41
      && (v40 > v41 || *(_DWORD *)(v38 + 20) > *(_DWORD *)(v39 + 20))
      && (v42 = *(_QWORD *)(v36 + 8i64 * (signed int)v37 + 40), v42 & 0xFFFFFFFFFFFFFFFCui64) )
    {
      v37 = *(_QWORD *)(v36 + 8i64 * (signed int)v37 + 40) & 3i64;
      v43 = v42 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v43 = v4->m_links[v7] & 0xFFFFFFFFFFFFFFFCui64;
    }
    *(_WORD *)(v43 + 100) ^= ((unsigned __int8)*(_WORD *)(v43 + 100) ^ (unsigned __int8)(*(unsigned __int16 *)(v43 + 100) | (1 << v37))) & 7;
  }
  if ( v27 )
  {
    LODWORD(v44) = (9 >> 2 * v7) & 3;
    v45 = v4->m_vertices[(signed int)v44];
    v46 = v4->m_vertices[(9i64 >> 2 * ((9 >> 2 * v7) & 3u)) & 3];
    v47 = v45->m_x;
    v48 = v46->m_x;
    if ( v47 >= v48
      && (v47 > v48 || v45->m_y > v46->m_y)
      && (v49 = v4->m_links[(signed int)v44], v49 & 0xFFFFFFFFFFFFFFFCui64) )
    {
      v44 = v4->m_links[(signed int)v44] & 3;
      v50 = v49 & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      v50 = (unsigned __int64)v4;
    }
    *(_WORD *)(v50 + 100) ^= ((unsigned __int8)*(_WORD *)(v50 + 100) ^ (unsigned __int8)(*(unsigned __int16 *)(v50 + 100) | (1 << v44))) & 7;
  }
  v76->m_triangle = v4;
  *(_QWORD *)&v76->m_index = v73;
  v51 = v76->m_triangle;
  LOBYTE(v72) = 0;
  v52 = (9 >> 2 * v7) & 3;
  *(_DWORD *)&v51->m_edgeData[v52].m_hasData = v77;
  v51->m_edgeData[v52].m_data.m_tag = v78;
  v51->m_edgeData[v52].m_data.m_sets = v69;
  v53 = (18 >> 2 * v7) & 3;
  *(_DWORD *)&v51->m_edgeData[v53].m_hasData = v65;
  v51->m_edgeData[v53].m_data.m_tag = v74;
  v51->m_edgeData[v53].m_data.m_sets = v67;
  v54 = (_DWORD *)((char *)v51 + 12 * v7);
  v55 = (signed int)v72;
  LOBYTE(v72) = 0;
  v54[16] = v55;
  v54[17] = -842150451;
  v54[18] = 0;
  v56 = v51->m_links[v7];
  v57 = v56;
  v56 &= 0xFFFFFFFFFFFFFFFCui64;
  v58 = v57 & 3;
  v59 = 3i64 * ((9 >> 2 * v58) & 3);
  *(_DWORD *)(v56 + 4 * v59 + 64) = v71;
  *(_DWORD *)(v56 + 4 * v59 + 68) = v63;
  *(_DWORD *)(v56 + 4 * v59 + 72) = v64;
  v60 = 3i64 * ((18 >> 2 * v58) & 3);
  *(_DWORD *)(v56 + 4 * v60 + 64) = v66;
  *(_DWORD *)(v56 + 4 * v60 + 68) = v68;
  *(_DWORD *)(v56 + 4 * v60 + 72) = v70;
  v61 = 3i64 * v58;
  *(_DWORD *)(v56 + 4 * v61 + 64) = (_DWORD)v72;
  *(_DWORD *)(v56 + 4 * v61 + 68) = -842150451;
  *(_DWORD *)(v56 + 4 * v61 + 72) = 0;
  return v76;
}

// File Line: 2463
// RVA: 0xB68340
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::propagateDataOnSplitTriangle<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle>(hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t0, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t1)
{
  hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *v4; // rsi
  char v5; // cl
  char *v6; // rdi
  char *v7; // rbx

  v4 = t1;
  v5 = 2 * edge->m_index;
  v6 = (char *)edge->m_triangle + 40 * ((9 >> v5) & 3);
  v7 = (char *)edge->m_triangle + 40 * ((18 >> v5) & 3);
  t0->m_edgeData[0].m_hasData = v6[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t0->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v6 + 72));
  v4->m_edgeData[0].m_hasData = v7[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &v4->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v7 + 72));
  v6[64] = 0;
  v7[64] = 0;
}

// File Line: 2476
// RVA: 0xB68260
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::propagateDataOnSplitBoundEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle>(hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *link, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t0, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t1)
{
  char *v5; // rdi
  char *v6; // rbx

  v5 = (char *)edge->m_triangle + 40 * ((18 >> 2 * edge->m_index) & 3);
  v6 = (char *)link->m_triangle + 40 * ((18 >> 2 * link->m_index) & 3);
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
void __fastcall hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::propagateDataOnSplitNakedEdge<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge,hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle>(hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Edge *edge, hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Triangle *t0)
{
  char *v3; // rbx

  v3 = (char *)edge->m_triangle + 40 * ((18 >> 2 * edge->m_index) & 3);
  t0->m_edgeData[0].m_hasData = v3[64];
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>::operator=(
    &t0->m_edgeData[0].m_data,
    (hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *)(v3 + 72));
  v3[64] = 0;
}

