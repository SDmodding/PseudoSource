// File Line: 227
// RVA: 0xCC1EB0
void __fastcall hkgpCgoInternal::hkgpCgoInternal(hkgpCgoInternal *this)
{
  hkgpIndexedMesh *p_m_topology; // rcx

  *(_QWORD *)&this->m_config.m_maxDistance = 2139095022i64;
  *(_QWORD *)&this->m_config.m_maxAngle = 2139095022i64;
  *(_QWORD *)&this->m_config.m_maxAngleDrift = 1078530011i64;
  p_m_topology = &this->m_topology;
  *(_QWORD *)&p_m_topology[-1].m_triangles.m_numUsed = 0i64;
  *(_QWORD *)&p_m_topology[-1].m_eMap.m_buckets.m_size = 0i64;
  p_m_topology[-1].m_eMap.m_numItems = 0x1000000;
  *((_WORD *)&p_m_topology[-1].m_eMap.m_numItems + 2) = 0;
  *((_BYTE *)&p_m_topology[-1].m_eMap.m_numItems + 6) = 0;
  p_m_topology[-1].m_invalidTriangles.m_data = 0i64;
  p_m_topology[-1].m_invalidTriangles.m_size = 8;
  p_m_topology[-1].m_invalidTriangles.m_capacityAndFlags = -1194215657;
  p_m_topology[-1].m_nakedEdges = 925353388;
  *(&p_m_topology[-1].m_nakedEdges + 1) = 257;
  p_m_topology[-1].m_sets.m_data = 0i64;
  hkgpIndexedMesh::hkgpIndexedMesh(p_m_topology);
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_edgesStorage.m_data = 0i64;
  this->m_edgesStorage.m_size = 0;
  this->m_edgesStorage.m_capacityAndFlags = 0x80000000;
  this->m_edgesTree.m_nodes.m_data = 0i64;
  this->m_edgesTree.m_nodes.m_size = 0;
  this->m_edgesTree.m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_edgesTree.m_prng.m_x = 123456789;
  this->m_edgesTree.m_prng.m_y = 234567891;
  this->m_edgesTree.m_prng.m_z = 345678912;
  *(_QWORD *)&this->m_edgesTree.m_prng.m_w = 456789123i64;
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::clear(&this->m_edgesTree, 0);
  this->m_invalidEdges.m_data = 0i64;
  this->m_invalidEdges.m_size = 0;
  this->m_invalidEdges.m_capacityAndFlags = 0x80000000;
  this->m_sets.m_data = 0i64;
  this->m_sets.m_size = 0;
  this->m_sets.m_capacityAndFlags = 0x80000000;
  hkgpJobQueue::hkgpJobQueue(&this->m_jobQueue, -1);
  hkCriticalSection::hkCriticalSection(&this->m_lock, 0);
}

// File Line: 230
// RVA: 0xCC20C0
void __fastcall hkgpCgoInternal::~hkgpCgoInternal(hkgpCgoInternal *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // eax
  int v5; // eax
  int v6; // r8d
  int v7; // edi
  hkgpCgoInternal::VertexInfo *v8; // rsi
  int v9; // r8d

  hkgpCgoInternal::reset(this);
  DeleteCriticalSection(&this->m_lock.m_section);
  hkgpJobQueue::~hkgpJobQueue(&this->m_jobQueue);
  m_capacityAndFlags = this->m_sets.m_capacityAndFlags;
  this->m_sets.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sets.m_data,
      8 * m_capacityAndFlags);
  this->m_sets.m_data = 0i64;
  this->m_sets.m_capacityAndFlags = 0x80000000;
  v3 = this->m_invalidEdges.m_capacityAndFlags;
  this->m_invalidEdges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_invalidEdges.m_data,
      8 * v3);
  this->m_invalidEdges.m_data = 0i64;
  this->m_invalidEdges.m_capacityAndFlags = 0x80000000;
  v4 = this->m_edgesTree.m_nodes.m_capacityAndFlags;
  this->m_edgesTree.m_nodes.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edgesTree.m_nodes.m_data,
      24 * (v4 & 0x3FFFFFFF));
  this->m_edgesTree.m_nodes.m_data = 0i64;
  this->m_edgesTree.m_nodes.m_capacityAndFlags = 0x80000000;
  v5 = this->m_edgesStorage.m_capacityAndFlags;
  this->m_edgesStorage.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edgesStorage.m_data,
      48 * (v5 & 0x3FFFFFFF));
  this->m_edgesStorage.m_data = 0i64;
  this->m_edgesStorage.m_capacityAndFlags = 0x80000000;
  v6 = this->m_triangles.m_capacityAndFlags;
  this->m_triangles.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_triangles.m_data,
      v6 << 6);
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  v7 = this->m_vertices.m_size - 1;
  if ( v7 >= 0 )
  {
    v8 = &this->m_vertices.m_data[(__int64)v7];
    do
    {
      hkgpCgoInternal::VertexInfo::~VertexInfo(v8--);
      --v7;
    }
    while ( v7 >= 0 );
  }
  v9 = this->m_vertices.m_capacityAndFlags;
  this->m_vertices.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_vertices.m_data,
      v9 << 6);
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  hkgpIndexedMesh::~hkgpIndexedMesh(&this->m_topology);
}

