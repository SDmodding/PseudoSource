// File Line: 227
// RVA: 0xCC1EB0
void __fastcall hkgpCgoInternal::hkgpCgoInternal(hkgpCgoInternal *this)
{
  hkgpCgoInternal *v1; // rbx
  hkgpIndexedMesh *v2; // rcx
  signed __int64 v3; // rcx

  *(_QWORD *)&this->m_config.m_maxDistance = 2139095022i64;
  *(_QWORD *)&this->m_config.m_maxAngle = 2139095022i64;
  *(_QWORD *)&this->m_config.m_maxAngleDrift = 1078530011i64;
  v1 = this;
  v2 = &this->m_topology;
  *(_QWORD *)&v2[-1].m_triangles.m_numUsed = 0i64;
  *(_QWORD *)&v2[-1].m_eMap.m_buckets.m_size = 0i64;
  v2[-1].m_eMap.m_numItems = 0x1000000;
  *((_WORD *)&v2[-1].m_eMap.m_numItems + 2) = 0;
  *((_BYTE *)&v2[-1].m_eMap.m_numItems + 6) = 0;
  v2[-1].m_invalidTriangles.m_data = 0i64;
  v2[-1].m_invalidTriangles.m_size = 8;
  v2[-1].m_invalidTriangles.m_capacityAndFlags = -1194215657;
  v2[-1].m_nakedEdges = 925353388;
  *(&v2[-1].m_nakedEdges + 1) = 257;
  v2[-1].m_sets.m_data = 0i64;
  hkgpIndexedMesh::hkgpIndexedMesh(v2);
  v1->m_vertices.m_data = 0i64;
  v1->m_vertices.m_size = 0;
  v1->m_vertices.m_capacityAndFlags = 2147483648;
  v1->m_triangles.m_data = 0i64;
  v1->m_triangles.m_size = 0;
  v1->m_triangles.m_capacityAndFlags = 2147483648;
  v3 = (signed __int64)&v1->m_edgesTree;
  v1->m_edgesStorage.m_data = 0i64;
  v1->m_edgesStorage.m_size = 0;
  v1->m_edgesStorage.m_capacityAndFlags = 2147483648;
  *(_QWORD *)v3 = 0i64;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 2147483648;
  *(_DWORD *)(v3 + 28) = 123456789;
  *(_DWORD *)(v3 + 32) = 234567891;
  *(_DWORD *)(v3 + 36) = 345678912;
  *(_QWORD *)(v3 + 40) = 456789123i64;
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::clear(&v1->m_edgesTree, 0);
  v1->m_invalidEdges.m_data = 0i64;
  v1->m_invalidEdges.m_size = 0;
  v1->m_invalidEdges.m_capacityAndFlags = 2147483648;
  v1->m_sets.m_data = 0i64;
  v1->m_sets.m_size = 0;
  v1->m_sets.m_capacityAndFlags = 2147483648;
  hkgpJobQueue::hkgpJobQueue(&v1->m_jobQueue, -1);
  hkCriticalSection::hkCriticalSection(&v1->m_lock, 0);
}

// File Line: 230
// RVA: 0xCC20C0
void __fastcall hkgpCgoInternal::~hkgpCgoInternal(hkgpCgoInternal *this)
{
  hkgpCgoInternal *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // eax
  int v5; // eax
  int v6; // er8
  int v7; // edi
  hkgpCgoInternal::VertexInfo *v8; // rsi
  int v9; // er8

  v1 = this;
  hkgpCgoInternal::reset(this);
  DeleteCriticalSection(&v1->m_lock.m_section);
  hkgpJobQueue::~hkgpJobQueue(&v1->m_jobQueue);
  v2 = v1->m_sets.m_capacityAndFlags;
  v1->m_sets.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sets.m_data,
      8 * v2);
  v1->m_sets.m_data = 0i64;
  v1->m_sets.m_capacityAndFlags = 2147483648;
  v3 = v1->m_invalidEdges.m_capacityAndFlags;
  v1->m_invalidEdges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_invalidEdges.m_data,
      8 * v3);
  v1->m_invalidEdges.m_data = 0i64;
  v1->m_invalidEdges.m_capacityAndFlags = 2147483648;
  v4 = v1->m_edgesTree.m_nodes.m_capacityAndFlags;
  v1->m_edgesTree.m_nodes.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_edgesTree.m_nodes.m_data,
      24 * (v4 & 0x3FFFFFFF));
  v1->m_edgesTree.m_nodes.m_data = 0i64;
  v1->m_edgesTree.m_nodes.m_capacityAndFlags = 2147483648;
  v5 = v1->m_edgesStorage.m_capacityAndFlags;
  v1->m_edgesStorage.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_edgesStorage.m_data,
      48 * (v5 & 0x3FFFFFFF));
  v1->m_edgesStorage.m_data = 0i64;
  v1->m_edgesStorage.m_capacityAndFlags = 2147483648;
  v6 = v1->m_triangles.m_capacityAndFlags;
  v1->m_triangles.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_triangles.m_data,
      v6 << 6);
  v1->m_triangles.m_data = 0i64;
  v1->m_triangles.m_capacityAndFlags = 2147483648;
  v7 = v1->m_vertices.m_size - 1;
  if ( v7 >= 0 )
  {
    v8 = &v1->m_vertices.m_data[(signed __int64)v7];
    do
    {
      hkgpCgoInternal::VertexInfo::~VertexInfo(v8);
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
  v9 = v1->m_vertices.m_capacityAndFlags;
  v1->m_vertices.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_vertices.m_data,
      v9 << 6);
  v1->m_vertices.m_data = 0i64;
  v1->m_vertices.m_capacityAndFlags = 2147483648;
  hkgpIndexedMesh::~hkgpIndexedMesh(&v1->m_topology);
}

