// File Line: 49
// RVA: 0xCE1500
void __fastcall hkgpIndexedMesh::hkgpIndexedMesh(hkgpIndexedMesh *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_vertices.m_allocator.m_firstPool = 0i64;
  this->m_vertices.m_used = 0i64;
  this->m_vertices.m_numUsed = 0;
  this->m_triangles.m_allocator.m_firstPool = 0i64;
  this->m_triangles.m_used = 0i64;
  this->m_triangles.m_numUsed = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpIndexedMesh::`vftable;
  this->m_vMap.m_map.m_elem = 0i64;
  this->m_vMap.m_map.m_numElems = 0;
  this->m_vMap.m_map.m_hashMod = -1;
  this->m_eMap.m_buckets.m_data = 0i64;
  this->m_eMap.m_buckets.m_size = 0;
  this->m_eMap.m_buckets.m_capacityAndFlags = 0x80000000;
  this->m_eMap.m_numItems = 0;
  this->m_invalidTriangles.m_data = 0i64;
  this->m_invalidTriangles.m_size = 0;
  this->m_invalidTriangles.m_capacityAndFlags = 0x80000000;
  this->m_sets.m_data = 0i64;
  this->m_sets.m_size = 0;
  this->m_sets.m_capacityAndFlags = 0x80000000;
  hkgpIndexedMesh::reset(this);
}

// File Line: 55
// RVA: 0xCE1590
void __fastcall hkgpIndexedMesh::reset(hkgpIndexedMesh *this)
{
  int v2; // eax
  __int64 v3; // rdi
  int *v4; // rbx
  int v5; // r8d
  int v6; // eax
  __int64 v7; // rdi
  int *v8; // rbx
  int v9; // r8d
  int v10; // r9d
  int v11; // eax
  __int64 v12; // rdi
  int *v13; // rbx
  int v14; // r8d
  __int64 m_size; // rdx
  int v16; // ecx
  __int64 v17; // rax
  hkArray<hkgpIndexedMesh::EdgeMatch,hkContainerHeapAllocator> *v18; // rdx
  __int64 i; // rcx
  int v20; // eax
  __int64 v21; // rdi
  int *v22; // rbx
  int v23; // r8d
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&this->m_vertices);
  hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&this->m_triangles);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_vMap.m_map);
  v2 = this->m_eMap.m_buckets.m_size - 1;
  v3 = v2;
  if ( v2 >= 0 )
  {
    v4 = &this->m_eMap.m_buckets.m_data->m_capacityAndFlags + 4 * v2;
    do
    {
      v5 = *v4;
      *(v4 - 1) = 0;
      if ( v5 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v4 - 3),
          16 * v5);
      *(_QWORD *)(v4 - 3) = 0i64;
      *v4 = 0x80000000;
      v4 -= 4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  this->m_eMap.m_buckets.m_size = 0;
  this->m_eMap.m_numItems = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &this->m_vMap.m_map,
    &hkContainerHeapAllocator::s_alloc,
    1031);
  v6 = this->m_eMap.m_buckets.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = &this->m_eMap.m_buckets.m_data->m_capacityAndFlags + 4 * v6;
    do
    {
      v9 = *v8;
      *(v8 - 1) = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v8 - 3),
          16 * v9);
      *(_QWORD *)(v8 - 3) = 0i64;
      *v8 = 0x80000000;
      v8 -= 4;
      --v7;
    }
    while ( v7 >= 0 );
  }
  this->m_eMap.m_buckets.m_size = 0;
  this->m_eMap.m_numItems = 0;
  if ( (this->m_eMap.m_buckets.m_capacityAndFlags & 0x3FFFFFFFu) < 0x407 )
  {
    v10 = 1031;
    if ( 2 * (this->m_eMap.m_buckets.m_capacityAndFlags & 0x3FFFFFFF) > 1031 )
      v10 = 2 * (this->m_eMap.m_buckets.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_eMap.m_buckets.m_data,
      v10,
      16);
  }
  v11 = this->m_eMap.m_buckets.m_size - 1032;
  v12 = v11;
  if ( v11 >= 0 )
  {
    v13 = &this->m_eMap.m_buckets.m_data[1031].m_capacityAndFlags + 4 * v11;
    do
    {
      v14 = *v13;
      *(v13 - 1) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v13 - 3),
          16 * v14);
      *(_QWORD *)(v13 - 3) = 0i64;
      *v13 = 0x80000000;
      v13 -= 4;
      --v12;
    }
    while ( v12 >= 0 );
  }
  m_size = this->m_eMap.m_buckets.m_size;
  v16 = 1031 - m_size;
  v17 = 1031 - (int)m_size;
  v18 = &this->m_eMap.m_buckets.m_data[m_size];
  if ( v16 > 0 )
  {
    do
    {
      if ( v18 )
      {
        v18->m_data = 0i64;
        v18->m_size = 0;
        v18->m_capacityAndFlags = 0x80000000;
      }
      ++v18;
      --v17;
    }
    while ( v17 );
  }
  this->m_eMap.m_buckets.m_size = 1031;
  for ( i = 0i64; i < 1031; this->m_eMap.m_buckets.m_data[i - 1].m_size = 0 )
    ++i;
  this->m_nakedEdges = 0;
  this->m_invalidTriangles.m_size = 0;
  v20 = this->m_sets.m_size - 1;
  v21 = v20;
  if ( v20 >= 0 )
  {
    v22 = &this->m_sets.m_data->m_links.m_capacityAndFlags + 4 * v20;
    do
    {
      v23 = *v22;
      *(v22 - 1) = 0;
      if ( v23 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v22 - 3),
          4 * v23);
      *(_QWORD *)(v22 - 3) = 0i64;
      *v22 = 0x80000000;
      v22 -= 4;
      --v21;
    }
    while ( v21 >= 0 );
  }
  this->m_sets.m_size = 0;
}

// File Line: 68
// RVA: 0xCE1860
void __fastcall hkgpIndexedMesh::appendFromMesh(hkgpIndexedMesh *this, hkgpIndexedMesh *mesh)
{
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rbx
  char *v3; // rax
  int m_material; // r9d
  unsigned __int64 m_index; // r8
  hkgpIndexedMeshDefinitions::Vertex *v7; // rax
  unsigned __int64 v8; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v9; // rax
  char *v10; // rax
  unsigned __int64 indices[5]; // [rsp+30h] [rbp-28h] BYREF
  char v12; // [rsp+68h] [rbp+10h] BYREF

  m_used = mesh->m_triangles.m_used;
  v3 = &v12;
  if ( !m_used )
    v3 = 0i64;
  if ( v3 )
  {
    do
    {
      m_material = m_used->m_material;
      m_index = m_used->m_index;
      v7 = m_used->m_vertices[1];
      indices[0] = m_used->m_vertices[0]->m_index;
      v8 = v7->m_index;
      v9 = m_used->m_vertices[2];
      indices[1] = v8;
      indices[2] = v9->m_index;
      hkgpIndexedMesh::appendTriangle(this, indices, m_index, m_material, 0);
      m_used = m_used->m_next;
      v10 = &v12;
      if ( !m_used )
        v10 = 0i64;
    }
    while ( v10 );
  }
}

// File Line: 78
// RVA: 0xCE1900
void __fastcall hkgpIndexedMesh::appendFromGeometry(hkgpIndexedMesh *this, hkGeometry *geometry)
{
  int i; // ebx

  for ( i = 0; i < geometry->m_triangles.m_size; ++i )
    hkgpIndexedMesh::appendTriangle(this, &geometry->m_triangles.m_data[i], i);
}

// File Line: 87
// RVA: 0xCE1960
hkgpIndexedMeshDefinitions::Triangle *__fastcall hkgpIndexedMesh::appendTriangle(
        hkgpIndexedMesh *this,
        hkGeometry::Triangle *triangle,
        unsigned __int64 index)
{
  int m_material; // r9d
  unsigned __int64 indices[5]; // [rsp+30h] [rbp-28h] BYREF

  m_material = triangle->m_material;
  indices[0] = triangle->m_a;
  indices[1] = triangle->m_b;
  indices[2] = triangle->m_c;
  return hkgpIndexedMesh::appendTriangle(this, indices, index, m_material, 0);
}

// File Line: 94
// RVA: 0xCE19A0
hkgpIndexedMeshDefinitions::Triangle *__fastcall hkgpIndexedMesh::appendTriangle(
        hkgpIndexedMesh *this,
        char *indices,
        unsigned __int64 index,
        int material,
        int flags)
{
  int v5; // r12d
  unsigned __int64 v7; // rdx
  __int64 v8; // r10
  unsigned __int64 v12; // rax
  __int64 *v13; // rbx
  __int64 v14; // rsi
  signed __int64 v15; // rdi
  unsigned __int64 v16; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v17; // rax
  int v18; // ecx
  __int64 v19; // rax
  hkgpIndexedMeshDefinitions::Triangle *v20; // rax
  __int64 v21; // rcx
  __int64 v22; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v23; // rsi
  hkgpIndexedMeshDefinitions::Vertex *v24; // rdi
  char *v25; // r15
  unsigned __int64 m_index; // rdx
  __int64 v27; // rax
  hkgpIndexedMeshDefinitions::Vertex *v28; // rbx
  char *v29; // r14
  unsigned __int64 v30; // rax
  unsigned int v31; // eax
  int v32; // r10d
  __int64 v33; // r8
  hkArray<hkgpIndexedMesh::EdgeMatch,hkContainerHeapAllocator> *v34; // rax
  __int64 m_size; // r11
  hkgpIndexedMesh::EdgeMatch *m_data; // rsi
  hkgpIndexedMesh::EdgeMatch *v37; // rdx
  __int64 v38; // rcx
  __int64 v39; // rcx
  __int64 v40; // rax
  __int64 v41; // r8
  bool v42; // zf
  hkgpIndexedMesh::EdgeMatch *v43; // r8
  unsigned __int64 v44; // r8
  unsigned __int64 v45; // rdx
  unsigned int v46; // r8d
  int v47; // r11d
  __int64 v48; // r9
  hkArray<hkgpIndexedMesh::EdgeMatch,hkContainerHeapAllocator> *v49; // rdi
  __int64 v50; // rbp
  hkgpIndexedMesh::EdgeMatch *v51; // rsi
  hkgpIndexedMesh::EdgeMatch *v52; // r8
  __int64 v53; // rdx
  int v54; // r9d
  __int64 v55; // rax
  hkgpIndexedMesh::EdgeMatch *v56; // r8
  __int64 v57; // r10
  __int64 v58; // rdx
  hkgpIndexedMesh::EdgeMatch *v59; // rax
  char *v60; // r8
  __int64 v61; // rcx
  unsigned __int64 v62; // rdx
  unsigned __int64 v63; // rcx
  unsigned int v64; // ecx
  int v65; // edx
  unsigned int v66; // edx
  hkArray<hkgpIndexedMesh::EdgeMatch,hkContainerHeapAllocator> *v67; // rbx
  hkgpIndexedMesh::EdgeMatch *v68; // rcx
  __int64 v69; // rax
  hkgpIndexedMeshDefinitions::Vertex *v71; // [rsp+20h] [rbp-48h] BYREF
  __int64 v72; // [rsp+28h] [rbp-40h]
  __int64 v73; // [rsp+30h] [rbp-38h]
  hkgpIndexedMeshDefinitions::Triangle *v74; // [rsp+78h] [rbp+10h]

  v5 = 0;
  v7 = *((_QWORD *)indices + 1);
  v8 = *(_QWORD *)indices;
  v71 = 0i64;
  v72 = 0i64;
  v73 = 0i64;
  if ( v8 == v7 || (v12 = *((_QWORD *)indices + 2), v7 == v12) || v12 == v8 )
  {
    if ( this->m_invalidTriangles.m_size == (this->m_invalidTriangles.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_invalidTriangles.m_data, 8);
    this->m_invalidTriangles.m_data[this->m_invalidTriangles.m_size++] = index;
    return 0i64;
  }
  else
  {
    v13 = (__int64 *)&v71;
    v14 = 3i64;
    v15 = indices - (char *)&v71;
    do
    {
      v16 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &this->m_vMap.m_map,
              *(__int64 *)((char *)v13 + v15),
              0i64);
      *v13 = v16;
      if ( !v16 )
      {
        v17 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&this->m_vertices);
        v18 = this->m_vertices.m_numUsed - 1;
        *v13 = (__int64)v17;
        *(_DWORD *)&v17->m_items[0].m_data[24] = v18;
        *(_QWORD *)&v17->m_items[0].m_data[16] = *(__int64 *)((char *)v13 + v15);
        *(_DWORD *)&v17->m_items[0].m_data[28] = 0;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &this->m_vMap.m_map,
          &hkContainerHeapAllocator::s_alloc,
          *(__int64 *)((char *)v13 + v15),
          (unsigned __int64)v17);
      }
      v19 = *v13++;
      ++*(_DWORD *)(v19 + 28);
      --v14;
    }
    while ( v14 );
    v20 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
    v20->m_vertices[0] = v71;
    v21 = v72;
    v20->m_material = material;
    v20->m_vertices[1] = (hkgpIndexedMeshDefinitions::Vertex *)v21;
    v22 = v73;
    v20->m_index = index;
    v20->m_vertices[2] = (hkgpIndexedMeshDefinitions::Vertex *)v22;
    v23 = v20;
    v20->m_flags = flags;
    LODWORD(v22) = this->m_triangles.m_numUsed;
    v20->m_set = -1;
    v74 = v20;
    v20->m_lidx = v22 - 1;
    this->m_nakedEdges += 3;
    do
    {
      v24 = v23->m_vertices[v5];
      v25 = (char *)v23 + 8 * v5;
      m_index = v24->m_index;
      v27 = (9i64 >> (2 * (unsigned __int8)v5)) & 3;
      LODWORD(v72) = v5;
      v28 = v23->m_vertices[v27];
      v29 = (char *)v23 + 8 * v27;
      v30 = v28->m_index;
      if ( m_index >= v30 )
        v31 = (3424933 * v30) ^ (1661161 * m_index);
      else
        v31 = (3424933 * m_index) ^ (1661161 * v30);
      v32 = 0;
      v33 = 0i64;
      v34 = &this->m_eMap.m_buckets.m_data[v31 % this->m_eMap.m_buckets.m_size];
      m_size = v34->m_size;
      if ( m_size <= 0 )
        goto LABEL_18;
      m_data = v34->m_data;
      v37 = v34->m_data;
      while ( 1 )
      {
        v38 = (int)v37->m_edge.m_index;
        if ( v37->m_edge.m_triangle->m_vertices[v38] == v28
          && v37->m_edge.m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v38)) & 3] == v24 )
        {
          break;
        }
        ++v33;
        ++v32;
        ++v37;
        if ( v33 >= m_size )
          goto LABEL_17;
      }
      if ( v32 == -1 )
      {
LABEL_17:
        v23 = v74;
        goto LABEL_18;
      }
      v41 = v32;
      v42 = &m_data[v41] == 0i64;
      v43 = &m_data[v41];
      v23 = v74;
      if ( v42 )
      {
LABEL_18:
        if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v40 = DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e);
          v39 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
        }
        else
        {
          v39 = 0i64;
          `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
          v40 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
        }
        v23->m_links[v5] = v39 + v40;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e )
          *(_QWORD *)(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e)
                    + 40) = (char *)v23 + (unsigned int)v5;
        v62 = *(_QWORD *)(*((_QWORD *)v29 + 2) + 16i64);
        v63 = *(_QWORD *)(*((_QWORD *)v25 + 2) + 16i64);
        if ( v63 >= v62 )
        {
          v64 = 1661161 * v63;
          v65 = 3424933 * v62;
        }
        else
        {
          v64 = 3424933 * v63;
          v65 = 1661161 * v62;
        }
        ++this->m_eMap.m_numItems;
        v66 = (v65 ^ v64) % this->m_eMap.m_buckets.m_size;
        v67 = &this->m_eMap.m_buckets.m_data[v66];
        if ( v67->m_size == (v67->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_eMap.m_buckets.m_data[v66].m_data,
            16);
        v68 = &v67->m_data[v67->m_size++];
        v69 = v72;
        v68->m_edge.m_triangle = v23;
        *(_QWORD *)&v68->m_edge.m_index = v69;
      }
      else
      {
        v43->m_edge.m_triangle->m_links[v43->m_edge.m_index] = (unsigned __int64)v74 + (unsigned int)v5;
        v74->m_links[v5] = (unsigned __int64)v43->m_edge.m_triangle + v43->m_edge.m_index;
        v44 = *(_QWORD *)(*((_QWORD *)v29 + 2) + 16i64);
        v45 = *(_QWORD *)(*((_QWORD *)v25 + 2) + 16i64);
        if ( v45 >= v44 )
          v46 = (3424933 * v44) ^ (1661161 * v45);
        else
          v46 = (3424933 * v45) ^ (1661161 * v44);
        --this->m_eMap.m_numItems;
        v47 = 0;
        v48 = 0i64;
        v49 = &this->m_eMap.m_buckets.m_data[v46 % this->m_eMap.m_buckets.m_size];
        v50 = v49->m_size;
        if ( (int)v50 > 0 )
        {
          v51 = v49->m_data;
          v52 = v49->m_data;
          while ( 1 )
          {
            v53 = (int)v52->m_edge.m_index;
            if ( v52->m_edge.m_triangle->m_vertices[v53] == (hkgpIndexedMeshDefinitions::Vertex *)*((_QWORD *)v29 + 2)
              && v52->m_edge.m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v53)) & 3] == (hkgpIndexedMeshDefinitions::Vertex *)*((_QWORD *)v25 + 2) )
            {
              break;
            }
            ++v48;
            ++v47;
            ++v52;
            if ( v48 >= v50 )
            {
              v23 = v74;
              this->m_nakedEdges -= 2;
              goto LABEL_52;
            }
          }
          if ( v47 >= 0 )
          {
            v54 = 0;
            v55 = 0i64;
            v56 = v49->m_data;
            while ( 1 )
            {
              v57 = (int)v56->m_edge.m_index;
              if ( v56->m_edge.m_triangle->m_vertices[v57] == (hkgpIndexedMeshDefinitions::Vertex *)*((_QWORD *)v29 + 2)
                && v56->m_edge.m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v57)) & 3] == (hkgpIndexedMeshDefinitions::Vertex *)*((_QWORD *)v25 + 2) )
              {
                break;
              }
              ++v55;
              ++v54;
              ++v56;
              if ( v55 >= v50 )
              {
                v54 = -1;
                v55 = -1i64;
                break;
              }
            }
            v49->m_size = v50 - 1;
            if ( (_DWORD)v50 - 1 != v54 )
            {
              v58 = 2i64;
              v59 = &v51[v55];
              v60 = (char *)((char *)&v51[(int)v50 - 1] - (char *)v59);
              do
              {
                v61 = *(__int64 *)((char *)&v59->m_edge.m_triangle + (_QWORD)v60);
                v59 = (hkgpIndexedMesh::EdgeMatch *)((char *)v59 + 8);
                *(_QWORD *)&v59[-1].m_edge.m_index = v61;
                --v58;
              }
              while ( v58 );
            }
          }
          v23 = v74;
        }
        this->m_nakedEdges -= 2;
      }
LABEL_52:
      ++v5;
    }
    while ( v5 < 3 );
    return v23;
  }
}

// File Line: 146
// RVA: 0xCE1E90
void __fastcall hkgpIndexedMesh::collapseEdge(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Edge *edge,
        hkgpIndexedMeshDefinitions::Edge *edgeOut,
        hkgpIndexedMesh::IEdgeCollapse *itrf)
{
  hkgpIndexedMeshDefinitions::Edge v4; // xmm0
  hkgpIndexedMeshDefinitions::Edge v9; // [rsp+30h] [rbp-228h] BYREF
  hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> v10; // [rsp+40h] [rbp-218h] BYREF
  char v11; // [rsp+50h] [rbp-208h] BYREF

  v4 = *edge;
  v10.m_size = 0;
  v9 = v4;
  v10.m_data = (hkgpIndexedMeshDefinitions::Triangle **)&v11;
  v10.m_capacityAndFlags = -2147483584;
  hkgpIndexedMesh::getBothRings(this, &v9, &v10);
  v9 = *edge;
  hkgpIndexedMesh::collapseEdge(this, &v10, &v9, edgeOut, itrf);
  v10.m_size = 0;
  if ( v10.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v10.m_data,
      8 * v10.m_capacityAndFlags);
}

// File Line: 157
// RVA: 0xCE1F60
void __fastcall hkgpIndexedMesh::collapseEdge(
        hkgpIndexedMesh *this,
        hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *inRing,
        hkgpIndexedMeshDefinitions::Edge *edge,
        hkgpIndexedMesh::ITriangleRemoval *edgeOut,
        hkgpIndexedMesh::IEdgeCollapse *itrf)
{
  hkgpIndexedMeshDefinitions::Triangle **m_data; // r8
  hkgpIndexedMesh::ITriangleRemoval *v7; // r15
  int m_size; // r9d
  hkgpIndexedMesh::ITriangleRemoval *v10; // r13
  hkgpIndexedMesh::IVertexRemovalVtbl *v11; // rax
  __int64 m_index; // rcx
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v14; // rbx
  hkgpIndexedMeshDefinitions::Vertex *v15; // r12
  __int64 v16; // r8
  int v17; // edx
  __int64 v18; // rax
  char *v19; // rcx
  hkgpIndexedMeshDefinitions::Vertex *m_next; // rax
  hkgpIndexedMeshDefinitions::Vertex *m_prev; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v22; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v24; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *v25; // rax
  unsigned __int64 v26; // rcx
  int v27; // r11d
  char **v28; // r14
  int v29; // ebx
  __int64 v30; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v31; // rdx
  int v32; // eax
  __int64 v33; // rcx
  int i; // ebx
  __int64 v35; // rdi
  __int64 v36; // rsi
  int v37; // r10d
  int v38; // eax
  char *v39; // r8
  hkgpIndexedMesh::ITriangleRemoval v40; // rax
  __int128 v41; // [rsp+20h] [rbp-D8h]
  __int128 v42; // [rsp+30h] [rbp-C8h]
  __int128 v43; // [rsp+40h] [rbp-B8h] BYREF
  __int128 v44; // [rsp+50h] [rbp-A8h] BYREF
  hkArrayBase<char *> v45; // [rsp+60h] [rbp-98h] BYREF
  char v46; // [rsp+70h] [rbp-88h] BYREF
  __int64 v47; // [rsp+4C0h] [rbp+3C8h]
  void **v48; // [rsp+4C8h] [rbp+3D0h] BYREF
  hkgpIndexedMesh::ITriangleRemoval *v49; // [rsp+4D0h] [rbp+3D8h]
  hkgpIndexedMesh::ITriangleRemoval *itrfa; // [rsp+4D8h] [rbp+3E0h]

  itrfa = edgeOut;
  m_data = inRing->m_data;
  v7 = edgeOut;
  m_size = inRing->m_size;
  v45.m_size = 0;
  v45.m_capacityAndFlags = -2147483520;
  v45.m_data = (char **)&v46;
  hkArrayBase<unsigned __int64>::_append(&v45, &hkContainerHeapAllocator::s_alloc, (char *const *)m_data, m_size);
  v48 = &hkgpIndexedMeshInternals::DefaultEdgeCollapseInterface::`vftable;
  v10 = (hkgpIndexedMesh::ITriangleRemoval *)&v48;
  if ( itrfa )
    v10 = itrfa;
  if ( v7 )
  {
    if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v11 = (hkgpIndexedMesh::IVertexRemovalVtbl *)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
    }
    else
    {
      `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
      v11 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
    }
    v7->vfptr = v11;
    v7[1].vfptr = *(hkgpIndexedMesh::IVertexRemovalVtbl **)((char *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                                                          + 8);
  }
  m_index = (int)edge->m_index;
  m_triangle = edge->m_triangle;
  v14 = edge->m_triangle->m_vertices[m_index];
  v15 = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
  if ( ((unsigned __int8 (__fastcall *)(hkgpIndexedMesh::ITriangleRemoval *, hkArrayBase<char *> *, hkgpIndexedMeshDefinitions::Vertex *, hkgpIndexedMeshDefinitions::Vertex *))v10->vfptr[1].removeVertex)(
         v10,
         &v45,
         v14,
         v15) )
  {
    v17 = 0;
    if ( v45.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        v18 = 3i64;
        v19 = v45.m_data[v16] + 16;
        do
        {
          if ( *(hkgpIndexedMeshDefinitions::Vertex **)v19 == v14 )
          {
            *(_QWORD *)v19 = v15;
            --v14->m_numRefs;
            ++v15->m_numRefs;
          }
          v19 += 8;
          --v18;
        }
        while ( v18 );
        ++v17;
        ++v16;
      }
      while ( v17 < v45.m_size );
    }
    ((void (__fastcall *)(hkgpIndexedMesh::ITriangleRemoval *, hkgpIndexedMeshDefinitions::Vertex *, __int64))v10->vfptr->removeVertex)(
      v10,
      v14,
      v16 * 8);
    m_next = v14->m_next;
    m_prev = v14->m_prev;
    if ( v14->m_next )
      m_next->m_prev = m_prev;
    if ( m_prev )
      m_prev->m_next = m_next;
    else
      this->m_vertices.m_used = m_next;
    --this->m_vertices.m_numUsed;
    v22 = v14[1].m_next;
    if ( v22[48].m_lidx-- == 1 )
    {
      v24 = v22[48].m_prev;
      v25 = (hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *)v22[48].m_index;
      if ( v24 )
        v24[48].m_index = (unsigned __int64)v25;
      else
        this->m_vertices.m_allocator.m_firstPool = v25;
      v26 = v22[48].m_index;
      if ( v26 )
        *(_QWORD *)(v26 + 1544) = v22[48].m_prev;
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v22, 1568);
    }
    v27 = v45.m_size;
    v28 = v45.m_data;
    v29 = 0;
    if ( v45.m_size > 0 )
    {
      v30 = 0i64;
      do
      {
        v31 = (hkgpIndexedMeshDefinitions::Triangle *)v28[v30];
        v32 = v31->m_vertices[0] == v15;
        if ( v31->m_vertices[1] == v15 )
          ++v32;
        if ( v31->m_vertices[2] == v15 )
          ++v32;
        if ( v32 > 1 )
        {
          hkgpIndexedMesh::removeTriangle(this, v31, v10);
          v27 = v45.m_size - 1;
          v45.m_size = v27;
          if ( v27 != v29 )
          {
            v45.m_data[v30] = v45.m_data[v27];
            v27 = v45.m_size;
          }
          v28 = v45.m_data;
          --v29;
          --v30;
        }
        ++v29;
        ++v30;
      }
      while ( v29 < v27 );
    }
    LODWORD(itrfa) = 0;
    if ( v27 > 0 )
    {
      v33 = 0i64;
      v47 = 0i64;
      do
      {
        for ( i = 0; i < 3; ++i )
        {
          v35 = *(__int64 *)((char *)v28 + v33);
          DWORD2(v41) = i;
          v36 = v35 + 8i64 * i;
          *(_QWORD *)&v41 = v35;
          if ( *(hkgpIndexedMeshDefinitions::Vertex **)(v36 + 16) == v15 )
          {
            if ( v7 )
              *(_OWORD *)&v7->vfptr = v41;
            if ( (*(_QWORD *)(v35 + 8i64 * i + 40) & 0xFFFFFFFFFFFFFFFCui64) == 0 )
            {
              v37 = 0;
              if ( v27 > 0 )
              {
                do
                {
                  v38 = 0;
                  v39 = v28[v37];
                  while ( 1 )
                  {
                    *(_QWORD *)&v42 = v28[v37];
                    DWORD2(v42) = v38;
                    if ( (*(_QWORD *)&v39[8 * v38 + 40] & 0xFFFFFFFFFFFFFFFCui64) == 0
                      && (!v39
                       || *(_QWORD *)(v36 + 16) == *(_QWORD *)&v39[8 * ((9i64 >> (2 * (unsigned __int8)v38)) & 3) + 16]
                       && *(_QWORD *)(v35 + 8 * ((9i64 >> (2 * (unsigned __int8)i)) & 3) + 16) == *(_QWORD *)&v39[8 * v38 + 16]) )
                    {
                      break;
                    }
                    if ( ++v38 >= 3 )
                      goto LABEL_57;
                  }
                  *(_QWORD *)(v35 + 8i64 * i + 40) = &v39[v38];
                  if ( v39 )
                    *(_QWORD *)&v39[8 * v38 + 40] = v35 + (unsigned int)i;
                  v40.vfptr = v10->vfptr;
                  v44 = v41;
                  v43 = v42;
                  ((void (__fastcall *)(hkgpIndexedMesh::ITriangleRemoval *, __int128 *, __int128 *))v40.vfptr[2].__vecDelDtor)(
                    v10,
                    &v44,
                    &v43);
                  v27 = v45.m_size;
                  v28 = v45.m_data;
                  v37 = v45.m_size;
LABEL_57:
                  ++v37;
                }
                while ( v37 < v27 );
                v33 = v47;
              }
            }
            v7 = v49;
          }
        }
        v33 += 8i64;
        v47 = v33;
        LODWORD(itrfa) = (_DWORD)itrfa + 1;
      }
      while ( (int)itrfa < v27 );
    }
  }
  else
  {
    v28 = v45.m_data;
  }
  v45.m_size = 0;
  v48 = &hkgpIndexedMesh::IVertexRemoval::`vftable;
  if ( v45.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v28,
      8 * v45.m_capacityAndFlags);
}

// File Line: 237
// RVA: 0xCE23F0
hkBool *__fastcall hkgpIndexedMesh::canFlipEdge(
        hkgpIndexedMesh *this,
        hkBool *result,
        hkgpIndexedMeshDefinitions::Edge *edge)
{
  __int64 m_index; // rcx
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // r8
  __int64 v6; // rax
  unsigned __int64 v7; // r10
  char v9; // si
  char v10; // di
  unsigned __int64 v11; // r11
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r11

  m_index = (int)edge->m_index;
  m_triangle = edge->m_triangle;
  v6 = m_triangle->m_links[m_index] & 3;
  v7 = m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64;
  if ( v7 )
  {
    v9 = 2 * v6;
    v10 = 2 * m_index;
    result->m_bool = m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)m_index)) & 3] != *(hkgpIndexedMeshDefinitions::Vertex **)(v7 + 8 * ((18i64 >> (2 * (unsigned __int8)v6)) & 3) + 16)
                  && ((v11 = m_triangle->m_links[(9 >> v10) & 3],
                       v12 = m_triangle->m_links[(18 >> v10) & 3] & 0xFFFFFFFFFFFFFFFCui64,
                       v13 = *(_QWORD *)(v7 + 8i64 * ((9 >> v9) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64,
                       v14 = *(_QWORD *)(v7 + 8i64 * ((18 >> v9) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64,
                       (v15 = v11 & 0xFFFFFFFFFFFFFFFCui64) == 0)
                   || !v12
                   || v15 != v12)
                  && (!v13 || !v14 || v13 != v14)
                  && (!v15 || !v14 || v15 != v14)
                  && (!v12 || !v13 || v12 != v13);
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 255
// RVA: 0xCE2510
hkgpIndexedMeshDefinitions::Edge *__fastcall hkgpIndexedMesh::flipEdge(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Edge *result,
        hkgpIndexedMeshDefinitions::Edge *edge)
{
  __int64 m_index; // rax
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // rbp
  unsigned __int64 v6; // rsi
  char v7; // bl
  hkgpIndexedMeshDefinitions::Vertex *v8; // r8
  char v9; // r9
  _QWORD *v10; // rsi
  int v11; // r9d
  char v12; // r10
  unsigned __int64 v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // r13
  unsigned __int64 v16; // r12
  __int64 v17; // r9
  hkgpIndexedMeshDefinitions::Vertex *v18; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v19; // rax
  unsigned int v21; // [rsp+0h] [rbp-48h]
  unsigned __int64 v22; // [rsp+8h] [rbp-40h]
  unsigned int v23; // [rsp+58h] [rbp+10h]
  unsigned int v24; // [rsp+60h] [rbp+18h]
  unsigned int v25; // [rsp+68h] [rbp+20h]

  m_index = (int)edge->m_index;
  m_triangle = edge->m_triangle;
  v6 = edge->m_triangle->m_links[m_index];
  v7 = 2 * m_index;
  v8 = edge->m_triangle->m_vertices[m_index];
  v9 = v6;
  v10 = (_QWORD *)(v6 & 0xFFFFFFFFFFFFFFFCui64);
  v11 = v9 & 3;
  v12 = 2 * v11;
  v13 = m_triangle->m_links[(9 >> (2 * m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64;
  v21 = m_triangle->m_links[(9 >> (2 * m_index)) & 3] & 3;
  v14 = m_triangle->m_links[(18 >> (2 * m_index)) & 3];
  v22 = v14 & 0xFFFFFFFFFFFFFFFCui64;
  v23 = v14 & 3;
  v15 = v10[((9 >> (2 * v11)) & 3) + 5] & 0xFFFFFFFFFFFFFFFCui64;
  v24 = v10[((9 >> (2 * v11)) & 3) + 5] & 3;
  v16 = v10[((18 >> (2 * v11)) & 3) + 5] & 0xFFFFFFFFFFFFFFFCui64;
  v25 = v10[((18 >> (2 * v11)) & 3) + 5] & 3;
  v17 = v10[v11 + 2];
  v18 = m_triangle->m_vertices[(18i64 >> v7) & 3];
  v19 = (hkgpIndexedMeshDefinitions::Vertex *)v10[((18i64 >> v12) & 3) + 2];
  --v8->m_numRefs;
  --*(_DWORD *)(v17 + 28);
  ++v18->m_numRefs;
  ++v19->m_numRefs;
  m_triangle->m_vertices[0] = v19;
  m_triangle->m_vertices[2] = v8;
  m_triangle->m_vertices[1] = v18;
  v10[3] = v19;
  v10[2] = v18;
  v10[4] = v17;
  m_triangle->m_links[0] = (unsigned __int64)v10;
  v10[5] = m_triangle;
  m_triangle->m_links[1] = v22 + v23;
  if ( v22 )
    *(_QWORD *)(v22 + 8i64 * (int)v23 + 40) = (char *)&m_triangle->m_next + 1;
  m_triangle->m_links[2] = v15 + v24;
  if ( v15 )
    *(_QWORD *)(v15 + 8i64 * (int)v24 + 40) = (char *)&m_triangle->m_next + 2;
  v10[6] = v16 + v25;
  if ( v16 )
    *(_QWORD *)(v16 + 8i64 * (int)v25 + 40) = (char *)v10 + 1;
  v10[7] = v13 + v21;
  if ( v13 )
    *(_QWORD *)(v13 + 8i64 * (int)v21 + 40) = (char *)v10 + 2;
  result->m_triangle = m_triangle;
  result->m_index = 0;
  return result;
}

// File Line: 282
// RVA: 0xCE26D0
hkgpIndexedMeshDefinitions::Edge *__fastcall hkgpIndexedMesh::splitEdge(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Edge *result,
        hkgpIndexedMeshDefinitions::Edge *edge)
{
  __int64 m_index; // rax
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // r13
  unsigned __int64 v5; // r12
  hkgpIndexedMeshDefinitions::Vertex *v8; // r14
  char v9; // r8
  char v10; // r9
  unsigned __int64 v11; // r12
  int v12; // r9d
  unsigned __int64 v13; // rax
  hkgpIndexedMeshDefinitions::Vertex *v14; // r15
  hkgpIndexedMeshDefinitions::Vertex *v15; // rbp
  hkgpIndexedMeshDefinitions::Vertex *v16; // rsi
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v17; // rax
  hkgpIndexedMeshDefinitions::Vertex *v18; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v19; // rax
  hkgpIndexedMeshDefinitions::Edge *v20; // rax
  hkgpIndexedMeshDefinitions::Vertex *v21; // rbp
  unsigned __int64 v22; // r15
  unsigned __int64 v23; // r12
  hkgpIndexedMeshDefinitions::Vertex *v24; // rdi
  hkgpIndexedMeshDefinitions::Vertex *v25; // rsi
  unsigned int v26; // eax
  unsigned __int64 v27; // r12
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v28; // rax
  hkgpIndexedMeshDefinitions::Vertex *v29; // rbx
  hkgpIndexedMeshDefinitions::Triangle *v30; // rax
  hkgpIndexedMeshDefinitions::Triangle *v31; // rdx
  unsigned int v32; // r8d
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // r9
  unsigned int v36; // [rsp+20h] [rbp-78h]
  unsigned int v37; // [rsp+24h] [rbp-74h]
  hkgpIndexedMeshDefinitions::Triangle *v38; // [rsp+28h] [rbp-70h]
  unsigned __int64 v39; // [rsp+30h] [rbp-68h]
  unsigned __int64 v40; // [rsp+38h] [rbp-60h]
  unsigned __int64 v41; // [rsp+40h] [rbp-58h]
  unsigned __int64 v42; // [rsp+48h] [rbp-50h]
  unsigned int v45; // [rsp+B0h] [rbp+18h]
  unsigned int v46; // [rsp+B0h] [rbp+18h]
  unsigned int v47; // [rsp+B8h] [rbp+20h]
  unsigned int v48; // [rsp+B8h] [rbp+20h]

  m_index = (int)edge->m_index;
  m_triangle = edge->m_triangle;
  v5 = edge->m_triangle->m_links[m_index];
  if ( (v5 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    v8 = m_triangle->m_vertices[m_index];
    v9 = 2 * m_index;
    v10 = v5;
    v11 = v5 & 0xFFFFFFFFFFFFFFFCui64;
    v12 = v10 & 3;
    v13 = m_triangle->m_links[(9 >> (2 * m_index)) & 3];
    v41 = v13 & 0xFFFFFFFFFFFFFFFCui64;
    v36 = v13 & 3;
    v45 = m_triangle->m_links[(18 >> v9) & 3] & 3;
    v39 = m_triangle->m_links[(18 >> v9) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v47 = *(_QWORD *)(v11 + 8i64 * ((9 >> (2 * v12)) & 3) + 40) & 3;
    v40 = *(_QWORD *)(v11 + 8i64 * ((9 >> (2 * v12)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v42 = *(_QWORD *)(v11 + 8i64 * ((18 >> (2 * v12)) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v14 = *(hkgpIndexedMeshDefinitions::Vertex **)(v11 + 8i64 * v12 + 16);
    v37 = *(_QWORD *)(v11 + 8i64 * ((18 >> (2 * v12)) & 3) + 40) & 3;
    v15 = m_triangle->m_vertices[(18i64 >> v9) & 3];
    v16 = *(hkgpIndexedMeshDefinitions::Vertex **)(v11 + 8 * ((18i64 >> (2 * (unsigned __int8)v12)) & 3) + 16);
    ++v15->m_numRefs;
    ++v16->m_numRefs;
    v17 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&this->m_vertices);
    *(_DWORD *)&v17->m_items[0].m_data[28] = 4;
    v18 = (hkgpIndexedMeshDefinitions::Vertex *)v17;
    *(_QWORD *)&v17->m_items[0].m_data[16] = v8->m_index;
    v38 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
    v19 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
    v38->m_index = m_triangle->m_index;
    v38->m_material = m_triangle->m_material;
    v19->m_index = *(_QWORD *)(v11 + 64);
    v19->m_material = *(_DWORD *)(v11 + 76);
    m_triangle->m_vertices[0] = v18;
    m_triangle->m_vertices[1] = v15;
    m_triangle->m_vertices[2] = v8;
    *(_QWORD *)(v11 + 16) = v18;
    *(_QWORD *)(v11 + 24) = v8;
    *(_QWORD *)(v11 + 32) = v16;
    v38->m_vertices[0] = v18;
    v38->m_vertices[1] = v14;
    v38->m_vertices[2] = v15;
    v19->m_vertices[0] = v18;
    v19->m_vertices[1] = v16;
    v19->m_vertices[2] = v14;
    m_triangle->m_links[1] = v39 + v45;
    if ( v39 )
      *(_QWORD *)(v39 + 8i64 * (int)v45 + 40) = (char *)&m_triangle->m_next + 1;
    *(_QWORD *)(v11 + 48) = v40 + v47;
    if ( v40 )
      *(_QWORD *)(v40 + 8i64 * (int)v47 + 40) = v11 + 1;
    v38->m_links[1] = v41 + v36;
    if ( v41 )
      *(_QWORD *)(v41 + 8i64 * (int)v36 + 40) = (char *)&v38->m_next + 1;
    v19->m_links[1] = v42 + v37;
    if ( v42 )
      *(_QWORD *)(v42 + 8i64 * (int)v37 + 40) = (char *)&v19->m_next + 1;
    m_triangle->m_links[2] = v11;
    *(_QWORD *)(v11 + 40) = (char *)&m_triangle->m_next + 2;
    v38->m_links[0] = (unsigned __int64)&v19->m_next + 2;
    v19->m_links[2] = (unsigned __int64)v38;
    m_triangle->m_links[0] = (unsigned __int64)&v38->m_next + 2;
    v38->m_links[2] = (unsigned __int64)m_triangle;
    *(_QWORD *)(v11 + 56) = v19;
    v19->m_links[0] = v11 + 2;
    v20 = result;
    result->m_triangle = m_triangle;
    result->m_index = 2;
  }
  else
  {
    v21 = m_triangle->m_vertices[m_index];
    v22 = m_triangle->m_links[(9 >> (2 * m_index)) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v48 = m_triangle->m_links[(9 >> (2 * m_index)) & 3] & 3;
    v23 = m_triangle->m_links[(18 >> (2 * m_index)) & 3];
    v24 = m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)m_index)) & 3];
    v25 = m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
    ++v24->m_numRefs;
    v26 = v23 & 3;
    v27 = v23 & 0xFFFFFFFFFFFFFFFCui64;
    v46 = v26;
    v28 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> > *)&this->m_vertices);
    *(_DWORD *)&v28->m_items[0].m_data[28] = 2;
    v29 = (hkgpIndexedMeshDefinitions::Vertex *)v28;
    *(_QWORD *)&v28->m_items[0].m_data[16] = v21->m_index;
    v30 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&this->m_triangles);
    v30->m_index = m_triangle->m_index;
    v31 = v30;
    v30->m_material = m_triangle->m_material;
    m_triangle->m_vertices[0] = v29;
    m_triangle->m_vertices[1] = v24;
    m_triangle->m_vertices[2] = v21;
    v30->m_vertices[0] = v29;
    v30->m_vertices[1] = v25;
    v30->m_vertices[2] = v24;
    m_triangle->m_links[1] = v27 + v46;
    if ( v27 )
      *(_QWORD *)(v27 + 8i64 * (int)v46 + 40) = (char *)&m_triangle->m_next + 1;
    v30->m_links[1] = v22 + v48;
    if ( v22 )
      *(_QWORD *)(v22 + 8i64 * (int)v48 + 40) = (char *)&v30->m_next + 1;
    v32 = 0;
    m_triangle->m_links[0] = (unsigned __int64)&v30->m_next + 2;
    v30->m_links[2] = (unsigned __int64)m_triangle;
    if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v34 = DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e);
      v33 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
    }
    else
    {
      v33 = 0i64;
      `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
      v34 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
    }
    m_triangle->m_links[2] = v33 + v34;
    v35 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e )
    {
      *(_QWORD *)(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e)
                + 40) = (char *)&m_triangle->m_next + 2;
      v35 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
    }
    if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) != 0 )
    {
      v32 = DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e);
    }
    else
    {
      v35 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
      `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
      DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
    }
    v31->m_links[0] = v35 + v32;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e )
      *(_QWORD *)(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e)
                + 40) = v31;
    result->m_triangle = m_triangle;
    result->m_index = 2;
    return result;
  }
  return v20;
}

// File Line: 358
// RVA: 0xCE2B30
void __fastcall hkgpIndexedMesh::getBothRings(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Edge *edge,
        hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *ring)
{
  __int64 m_index; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v5; // rbp
  int v6; // esi
  hkgpIndexedMeshDefinitions::Vertex *v9; // r14
  int m_capacityAndFlags; // eax
  int v11; // eax
  int v12; // r9d
  int v13; // eax
  bool v14; // zf
  bool v15; // bl
  bool v16; // al
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rbx
  hkResult *p_result; // rax
  hkgpIndexedMeshDefinitions::Vertex *v19; // rax
  hkgpIndexedMeshDefinitions::Vertex *v20; // rax
  hkgpIndexedMeshDefinitions::Vertex *v21; // rax
  hkResult *v22; // rax
  int m_size; // r8d
  __int64 v24; // r9
  hkgpIndexedMeshDefinitions::Triangle **v25; // rax
  int v26; // ecx
  __int64 v27; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v28; // rcx
  hkgpIndexedMeshDefinitions::Edge v29; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  m_index = (int)edge->m_index;
  v5 = edge->m_triangle->m_vertices[m_index];
  v6 = 0;
  v9 = edge->m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3];
  m_capacityAndFlags = ring->m_capacityAndFlags;
  ring->m_size = 0;
  v11 = m_capacityAndFlags & 0x3FFFFFFF;
  v12 = v5->m_numRefs + v9->m_numRefs;
  if ( v11 < v12 )
  {
    v13 = 2 * v11;
    if ( v12 < v13 )
      v12 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&ring->m_data, v12, 8);
  }
  v29 = *edge;
  v14 = v5->m_numRefs == hkgpIndexedMesh::getReachableRing(this, &v29, ring);
  v29.m_triangle = edge->m_triangle;
  v15 = v14;
  v29.m_index = (9 >> (2 * edge->m_index)) & 3;
  v16 = v9->m_numRefs == hkgpIndexedMesh::getReachableRing(this, &v29, ring);
  if ( !v15 || !v16 )
  {
    m_used = this->m_triangles.m_used;
    p_result = &result;
    if ( !m_used )
      p_result = 0i64;
    if ( p_result )
    {
      do
      {
        v19 = m_used->m_vertices[0];
        if ( v19 == v5
          || v19 == v9
          || (v20 = m_used->m_vertices[1], v20 == v5)
          || v20 == v9
          || (v21 = m_used->m_vertices[2], v21 == v5)
          || v21 == v9 )
        {
          if ( ring->m_size == (ring->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&ring->m_data, 8);
          ring->m_data[ring->m_size++] = m_used;
        }
        m_used = m_used->m_next;
        v22 = &result;
        if ( !m_used )
          v22 = 0i64;
      }
      while ( v22 );
    }
  }
  m_size = ring->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkgpIndexedMeshDefinitions::Triangle *,hkgpIndexedMeshInternals::TriangleSortLess>(
      ring->m_data,
      0,
      m_size - 1,
      (hkgpIndexedMeshInternals::TriangleSortLess)result.m_enum);
  if ( ring->m_size - 1 > 0 )
  {
    v24 = 0i64;
    do
    {
      v25 = &ring->m_data[v24];
      if ( *v25 == v25[1] )
      {
        v26 = 8 * (--ring->m_size - v6);
        if ( v26 > 0 )
        {
          v27 = ((unsigned int)(v26 - 1) >> 3) + 1;
          do
          {
            v28 = v25[1];
            *v25++ = v28;
            --v27;
          }
          while ( v27 );
        }
        --v6;
        --v24;
      }
      ++v6;
      ++v24;
    }
    while ( v6 < ring->m_size - 1 );
  }
}

// File Line: 392
// RVA: 0xCE2D50
__int64 __fastcall hkgpIndexedMesh::getReachableRing(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Edge *edge,
        hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *ring)
{
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // rsi
  __int64 m_index; // rbp
  unsigned int v6; // edi
  int m_size; // r9d
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  hkgpIndexedMeshDefinitions::Edge v11; // [rsp+20h] [rbp-28h]
  hkgpIndexedMeshDefinitions::Edge i; // [rsp+20h] [rbp-28h]
  hkgpIndexedMeshDefinitions::Edge v13; // [rsp+30h] [rbp-18h]

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  v11 = *edge;
  v6 = 0;
  while ( 1 )
  {
    ++v6;
    if ( ring->m_size == (ring->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&ring->m_data, 8);
    ring->m_data[ring->m_size++] = v11.m_triangle;
    m_size = ring->m_size;
    v8 = v11.m_triangle->m_links[(18 >> (2 * LOBYTE(v11.m_index))) & 3] & 3;
    v9 = v11.m_triangle->m_links[(18 >> (2 * LOBYTE(v11.m_index))) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v13.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)v9;
    v13.m_index = v11.m_triangle->m_links[(18 >> (2 * LOBYTE(v11.m_index))) & 3] & 3;
    v11 = v13;
    if ( !v9 )
      break;
    if ( (hkgpIndexedMeshDefinitions::Triangle *)(v9 + (unsigned int)v8) == (hkgpIndexedMeshDefinitions::Triangle *)((char *)m_triangle + (unsigned int)m_index) )
      return v6;
  }
  v13.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)(m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64);
  v13.m_index = (9 >> (2 * (m_triangle->m_links[m_index] & 3))) & 3;
  for ( i = v13; v13.m_triangle; i = v13 )
  {
    ++v6;
    if ( m_size == (ring->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&ring->m_data, 8);
    ring->m_data[ring->m_size++] = i.m_triangle;
    m_size = ring->m_size;
    v13.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)(i.m_triangle->m_links[i.m_index] & 0xFFFFFFFFFFFFFFFCui64);
    v13.m_index = (9 >> (2 * (i.m_triangle->m_links[i.m_index] & 3))) & 3;
  }
  return v6;
}

// File Line: 399
// RVA: 0xCE2EE0
void __fastcall hkgpIndexedMesh::removeTriangle(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Triangle *triangle,
        hkgpIndexedMesh::ITriangleRemoval *itrf)
{
  hkgpIndexedMeshDefinitions::Vertex **m_vertices; // rbx
  unsigned __int64 *m_links; // rsi
  __int64 v8; // rbp
  hkgpIndexedMeshDefinitions::Vertex *v9; // rax
  hkgpIndexedMeshDefinitions::Vertex *v10; // rdx
  hkgpIndexedMeshDefinitions::Vertex *m_next; // rax
  hkgpIndexedMeshDefinitions::Vertex *m_prev; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v13; // rdx
  bool v14; // zf
  hkgpIndexedMeshDefinitions::Vertex *v15; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *m_index; // rax
  unsigned __int64 v17; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v18; // rax
  hkgpIndexedMeshDefinitions::Triangle *v19; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v20; // rdx
  __int64 v21; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>::Pool *v22; // rax
  __int64 v23; // r8

  if ( itrf )
    ((void (__fastcall *)(hkgpIndexedMesh::ITriangleRemoval *))itrf->vfptr[1].__vecDelDtor)(itrf);
  m_vertices = triangle->m_vertices;
  m_links = triangle->m_links;
  v8 = 3i64;
  do
  {
    if ( (*m_links & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      *(_QWORD *)((*m_links & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*m_links & 3) + 40) = 0i64;
    *m_links = 0i64;
    v9 = *m_vertices;
    if ( !--v9->m_numRefs )
    {
      if ( itrf )
        itrf->vfptr->removeVertex(itrf, *m_vertices);
      v10 = *m_vertices;
      m_next = (*m_vertices)->m_next;
      m_prev = (*m_vertices)->m_prev;
      if ( m_next )
        m_next->m_prev = m_prev;
      if ( m_prev )
        m_prev->m_next = m_next;
      else
        this->m_vertices.m_used = m_next;
      --this->m_vertices.m_numUsed;
      v13 = v10[1].m_next;
      v14 = v13[48].m_lidx-- == 1;
      if ( v14 )
      {
        v15 = v13[48].m_prev;
        m_index = (hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *)v13[48].m_index;
        if ( v15 )
          v15[48].m_index = (unsigned __int64)m_index;
        else
          this->m_vertices.m_allocator.m_firstPool = m_index;
        v17 = v13[48].m_index;
        if ( v17 )
          *(_QWORD *)(v17 + 1544) = v13[48].m_prev;
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v13, 1568);
      }
    }
    ++m_links;
    ++m_vertices;
    --v8;
  }
  while ( v8 );
  v18 = triangle->m_next;
  v19 = triangle->m_prev;
  if ( triangle->m_next )
    v18->m_prev = v19;
  if ( v19 )
    v19->m_next = v18;
  else
    this->m_triangles.m_used = v18;
  --this->m_triangles.m_numUsed;
  v20 = triangle[1].m_prev;
  v14 = LODWORD(v20[41].m_next)-- == 1;
  if ( v14 )
  {
    v21 = *(_QWORD *)&v20[40].m_set;
    v22 = *(hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>::Pool **)&v20[40].m_flags;
    if ( v21 )
      *(_QWORD *)(v21 + 3600) = v22;
    else
      this->m_triangles.m_allocator.m_firstPool = v22;
    v23 = *(_QWORD *)&v20[40].m_flags;
    if ( v23 )
      *(_QWORD *)(v23 + 3592) = *(_QWORD *)&v20[40].m_set;
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, v20, 3616);
  }
}

// File Line: 415
// RVA: 0xCE30B0
void __fastcall hkgpIndexedMesh::growStrip(
        hkgpIndexedMesh *this,
        hkgpIndexedMeshDefinitions::Edge *root,
        hkArray<hkgpIndexedMeshDefinitions::Edge,hkContainerHeapAllocator> *strip,
        hkgpIndexedMesh::StripConfig *config)
{
  bool v4; // zf
  int m_material; // ebp
  hkgpIndexedMeshDefinitions::Edge *v9; // rcx
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // r8
  unsigned int v11; // ecx
  unsigned __int64 v12; // rcx
  __int64 v13; // rax
  hkgpIndexedMeshDefinitions::Triangle *v14; // rax
  hkgpIndexedMeshDefinitions::Edge *v15; // rcx
  __int64 v16; // [rsp+28h] [rbp-20h]
  __int64 v17; // [rsp+38h] [rbp-10h]

  v4 = (strip->m_capacityAndFlags & 0x3FFFFFFF) == 0;
  m_material = root->m_triangle->m_material;
  strip->m_size = 0;
  if ( v4 )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&strip->m_data, 16);
  v9 = &strip->m_data[strip->m_size];
  if ( v9 )
  {
    v9->m_triangle = root->m_triangle;
    *(_QWORD *)&v9->m_index = *(_QWORD *)&root->m_index;
  }
  ++strip->m_size;
  for ( root->m_triangle->m_flags |= 0x10u; strip->m_size + 2 < config->m_maxLength; root->m_triangle->m_flags |= 0x10u )
  {
    m_triangle = root->m_triangle;
    v11 = 2 * root->m_index;
    if ( (strip->m_size & 1) != 0 )
    {
      v12 = m_triangle->m_links[(9 >> v11) & 3];
      LODWORD(v16) = v12 & 3;
      v13 = v16;
    }
    else
    {
      v12 = m_triangle->m_links[(18 >> v11) & 3];
      LODWORD(v17) = v12 & 3;
      v13 = v17;
    }
    root->m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)(v12 & 0xFFFFFFFFFFFFFFFCui64);
    *(_QWORD *)&root->m_index = v13;
    v14 = root->m_triangle;
    if ( !root->m_triangle || (v14->m_flags & 0x10) != 0 || v14->m_material != m_material )
      break;
    if ( strip->m_size == (strip->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&strip->m_data, 16);
    v15 = &strip->m_data[strip->m_size];
    if ( v15 )
    {
      v15->m_triangle = root->m_triangle;
      *(_QWORD *)&v15->m_index = *(_QWORD *)&root->m_index;
    }
    ++strip->m_size;
  }
}

// File Line: 435
// RVA: 0xCE3210
void __fastcall hkgpIndexedMesh::generateStrips(
        hkgpIndexedMesh *this,
        hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *strips,
        hkArray<int,hkContainerHeapAllocator> *leftOvers,
        hkArray<int,hkContainerHeapAllocator> *map,
        hkgpIndexedMesh::StripConfig *config)
{
  int v5; // eax
  hkArray<int,hkContainerHeapAllocator> *v6; // r12
  hkgpIndexedMesh *v9; // r15
  __int64 v10; // rdi
  int *v11; // rbx
  int v12; // r8d
  int m_capacityAndFlags; // r8d
  int v14; // r8d
  int m_numUsed; // r9d
  hkgpIndexedMeshDefinitions::Triangle *i; // rdx
  hkgpIndexedMesh::StripConfig *v17; // rsi
  int m_minLength; // edi
  __int128 v19; // xmm7
  int v20; // r14d
  __int64 v21; // r9
  __int64 v22; // r15
  hkgpIndexedMeshDefinitions::Triangle **v23; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v24; // rsi
  int j; // ebx
  __int128 v26; // xmm6
  int v27; // r8d
  int v28; // r9d
  __int64 v29; // rax
  hkResultEnum m_enum; // r13d
  int v31; // eax
  __int64 v32; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v33; // rax
  hkArray<int,hkContainerHeapAllocator> *v34; // rax
  __int64 m_size; // rax
  hkArray<int,hkContainerHeapAllocator> *v36; // rbx
  int m_index; // edi
  int v38; // esi
  int v39; // eax
  __int64 v40; // rdi
  hkgpIndexedMeshDefinitions::Vertex *v41; // rcx
  int v42; // r14d
  int v43; // r14d
  int v44; // edi
  int v45; // edi
  __int64 v46; // rbx
  int v47; // esi
  int v48; // esi
  int v49; // esi
  int v50; // esi
  hkResult result; // [rsp+30h] [rbp-81h] BYREF
  hkgpIndexedMeshDefinitions::Triangle **array; // [rsp+38h] [rbp-79h] BYREF
  int v53; // [rsp+40h] [rbp-71h]
  int v54; // [rsp+44h] [rbp-6Dh]
  hkArray<hkgpIndexedMeshDefinitions::Edge,hkContainerHeapAllocator> v55; // [rsp+48h] [rbp-69h] BYREF
  hkgpIndexedMeshDefinitions::Edge v56; // [rsp+60h] [rbp-51h]
  __int128 v57; // [rsp+70h] [rbp-41h]
  hkgpIndexedMeshDefinitions::Edge v58; // [rsp+80h] [rbp-31h] BYREF
  __int128 v59; // [rsp+90h] [rbp-21h] BYREF

  v5 = strips->m_size - 1;
  v6 = map;
  v9 = this;
  v10 = v5;
  if ( v5 >= 0 )
  {
    v11 = &strips->m_data->m_capacityAndFlags + 4 * v5;
    do
    {
      v12 = *v11;
      *(v11 - 1) = 0;
      if ( v12 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v11 - 3),
          4 * v12);
      *(_QWORD *)(v11 - 3) = 0i64;
      *v11 = 0x80000000;
      v11 -= 4;
      --v10;
    }
    while ( v10 >= 0 );
  }
  m_capacityAndFlags = strips->m_capacityAndFlags;
  strips->m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      strips->m_data,
      16 * m_capacityAndFlags);
  strips->m_data = 0i64;
  strips->m_capacityAndFlags = 0x80000000;
  v14 = leftOvers->m_capacityAndFlags;
  leftOvers->m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, leftOvers->m_data, 4 * v14);
  leftOvers->m_data = 0i64;
  leftOvers->m_capacityAndFlags = 0x80000000;
  m_numUsed = v9->m_triangles.m_numUsed;
  if ( m_numUsed )
  {
    array = 0i64;
    v53 = 0;
    v54 = 0x80000000;
    if ( m_numUsed > 0 )
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numUsed, 8);
    for ( i = v9->m_triangles.m_used; i; i = i->m_next )
    {
      i->m_flags &= ~0x10u;
      array[v53++] = i;
    }
    if ( v53 > 1 )
      hkAlgorithm::quickSortRecursive<hkgpIndexedMeshDefinitions::Triangle *,hkgpIndexedMesh::SortByAscendingReferences>(
        array,
        0,
        v53 - 1,
        0);
    v55.m_data = 0i64;
    v55.m_size = 0;
    v55.m_capacityAndFlags = 0x80000000;
    while ( 1 )
    {
      v17 = config;
      m_minLength = config->m_minLength;
      if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) == 0 )
      {
        *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
        `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
      }
      v19 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
      v20 = 0;
      result.m_enum = HK_SUCCESS;
      v57 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
      v21 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
      if ( v53 > 0 )
      {
        v22 = 0i64;
        while ( 1 )
        {
          v23 = &array[v22];
          v24 = array[v22];
          if ( (v24->m_flags & 0x10) != 0 )
          {
            v31 = 8 * (--v53 - v20);
            if ( v31 > 0 )
            {
              v32 = ((unsigned int)(v31 - 1) >> 3) + 1;
              do
              {
                v33 = v23[1];
                *v23++ = v33;
                --v32;
              }
              while ( v32 );
            }
            v17 = config;
            --v20;
            --v22;
          }
          else
          {
            for ( j = 0; j < 3; ++j )
            {
              v56.m_triangle = v24;
              v56.m_index = j;
              v26 = (__int128)v56;
              v58 = v56;
              hkgpIndexedMesh::growStrip(this, &v58, &v55, config);
              v27 = 0;
              v28 = v55.m_size + 2;
              if ( v55.m_size > 0 )
              {
                v29 = 0i64;
                do
                {
                  ++v27;
                  v55.m_data[v29++].m_triangle->m_flags &= ~0x10u;
                }
                while ( v27 < v55.m_size );
              }
              if ( v28 >= m_minLength )
              {
                m_minLength = v28;
                v19 = v26;
              }
            }
            v6 = map;
            m_enum = result.m_enum;
            v17 = config;
            v21 = v19;
            if ( (_QWORD)v19 )
            {
              ++result.m_enum;
              if ( m_enum + 1 > config->m_searchPasses )
              {
LABEL_38:
                v9 = this;
                break;
              }
            }
          }
          ++v20;
          ++v22;
          if ( v20 >= v53 )
            goto LABEL_38;
        }
      }
      if ( !v21 )
        break;
      if ( strips->m_size == (strips->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&strips->m_data, 16);
      v34 = &strips->m_data[strips->m_size];
      if ( v34 )
      {
        v34->m_data = 0i64;
        v34->m_size = 0;
        v34->m_capacityAndFlags = 0x80000000;
      }
      m_size = strips->m_size;
      v59 = v19;
      v36 = &strips->m_data[m_size];
      strips->m_size = m_size + 1;
      hkgpIndexedMesh::growStrip(v9, (hkgpIndexedMeshDefinitions::Edge *)&v59, &v55, v17);
      m_index = v55.m_data->m_triangle->m_vertices[v55.m_data->m_index]->m_index;
      if ( v36->m_size == (v36->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v36->m_data, 4);
      v38 = 0;
      v36->m_data[v36->m_size++] = m_index;
      v39 = v55.m_size;
      if ( v55.m_size > 0 )
      {
        v40 = 0i64;
        do
        {
          if ( (v38 & 1) != 0 )
            v41 = v55.m_data[v40].m_triangle->m_vertices[v55.m_data[v40].m_index];
          else
            v41 = v55.m_data[v40].m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)v55.m_data[v40].m_index)) & 3];
          v42 = v41->m_index;
          if ( v36->m_size == (v36->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v36->m_data, 4);
          v36->m_data[v36->m_size++] = v42;
          v43 = v55.m_data[v40].m_triangle->m_index;
          if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v6->m_data, 4);
          ++v38;
          v6->m_data[v6->m_size] = v43;
          v39 = v55.m_size;
          ++v6->m_size;
          ++v40;
        }
        while ( v38 < v39 );
      }
      v44 = v55.m_data[v39 - 1].m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)v55.m_data[v39 - 1].m_index)) & 3]->m_index;
      if ( v36->m_size == (v36->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v36->m_data, 4);
      v36->m_data[v36->m_size++] = v44;
    }
    v45 = 0;
    if ( v53 > 0 )
    {
      v46 = 0i64;
      do
      {
        v47 = array[v46]->m_vertices[0]->m_index;
        if ( leftOvers->m_size == (leftOvers->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&leftOvers->m_data, 4);
        leftOvers->m_data[leftOvers->m_size++] = v47;
        v48 = array[v46]->m_vertices[1]->m_index;
        if ( leftOvers->m_size == (leftOvers->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&leftOvers->m_data, 4);
        leftOvers->m_data[leftOvers->m_size++] = v48;
        v49 = array[v46]->m_vertices[2]->m_index;
        if ( leftOvers->m_size == (leftOvers->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&leftOvers->m_data, 4);
        leftOvers->m_data[leftOvers->m_size++] = v49;
        v50 = array[v46]->m_index;
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v6->m_data, 4);
        ++v45;
        v6->m_data[v6->m_size++] = v50;
        ++v46;
      }
      while ( v45 < v53 );
    }
    v55.m_size = 0;
    if ( v55.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v55.m_data,
        16 * v55.m_capacityAndFlags);
    v55.m_data = 0i64;
    v55.m_capacityAndFlags = 0x80000000;
    v53 = 0;
    if ( v54 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v54);
  }
}

// File Line: 514
// RVA: 0xCE38F0
void __fastcall hkgpIndexedMesh::computeSets(hkgpIndexedMesh *this, hkgpIndexedMesh::EdgeBarrier *barriers)
{
  hkArray<hkgpIndexedMesh::SetInfos,hkContainerHeapAllocator> *p_m_sets; // r15
  hkgpIndexedMesh::SetInfos *m_data; // r8
  hkgpIndexedMesh *v5; // rsi
  int v6; // eax
  __int64 v7; // rdi
  int *v8; // rbx
  int v9; // r8d
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rax
  char *v11; // rcx
  char *v12; // rcx
  hkgpIndexedMeshDefinitions::Triangle *m_next; // rbx
  char *v14; // rax
  int m_capacityAndFlags; // eax
  int m_size; // r13d
  __int64 v17; // rax
  hkgpIndexedMeshDefinitions::Triangle *v18; // rdx
  __int64 v19; // r15
  int v20; // esi
  int v21; // edi
  __int64 v22; // r14
  hkgpIndexedMesh::EdgeBarrierVtbl *vfptr; // rax
  signed int v24; // ecx
  unsigned __int64 v25; // r14
  char *v26; // rax
  hkgpIndexedMeshDefinitions::Triangle *v27; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v28; // rsi
  __int128 *p_array; // rax
  unsigned __int64 v30; // r14
  __int64 v31; // r8
  __int64 m_set; // rcx
  int v33; // edx
  __int64 v34; // rbx
  __int64 v35; // rcx
  hkgpIndexedMesh::SetInfos *v36; // rbx
  __int64 v37; // rdi
  __int64 v38; // r10
  int *v39; // rax
  __int64 v40; // r10
  int v41; // edx
  __int64 v42; // rcx
  _DWORD *v43; // rax
  __int128 *v44; // rax
  __int128 array; // [rsp+20h] [rbp-30h] BYREF
  __int128 v46; // [rsp+30h] [rbp-20h]
  __int128 v47; // [rsp+40h] [rbp-10h] BYREF
  char v49; // [rsp+A0h] [rbp+50h] BYREF
  hkArray<hkgpIndexedMesh::SetInfos,hkContainerHeapAllocator> *v50; // [rsp+A8h] [rbp+58h]

  p_m_sets = &this->m_sets;
  m_data = this->m_sets.m_data;
  v5 = this;
  v6 = this->m_sets.m_size - 1;
  v50 = &this->m_sets;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = &m_data->m_links.m_capacityAndFlags + 4 * v6;
    do
    {
      v9 = *v8;
      *(v8 - 1) = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v8 - 3), 4 * v9);
      *(_QWORD *)(v8 - 3) = 0i64;
      *v8 = 0x80000000;
      v8 -= 4;
      --v7;
    }
    while ( v7 >= 0 );
  }
  p_m_sets->m_size = 0;
  m_used = v5->m_triangles.m_used;
  v11 = &v49;
  if ( !m_used )
    v11 = 0i64;
  if ( v11 )
  {
    do
    {
      m_used->m_set = -1;
      m_used = m_used->m_next;
      v12 = &v49;
      if ( !m_used )
        v12 = 0i64;
    }
    while ( v12 );
  }
  m_next = v5->m_triangles.m_used;
  v14 = &v49;
  if ( !m_next )
    v14 = 0i64;
  if ( v14 )
  {
    do
    {
      if ( m_next->m_set == -1 )
      {
        *(_QWORD *)&array = 0i64;
        *((_QWORD *)&array + 1) = 0x8000000000000000ui64;
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        *(_QWORD *)(array + 8i64 * SDWORD2(array)) = m_next;
        m_capacityAndFlags = p_m_sets->m_capacityAndFlags;
        ++DWORD2(array);
        m_size = v5->m_sets.m_size;
        if ( p_m_sets->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_sets->m_data, 16);
        v17 = (__int64)&p_m_sets->m_data[p_m_sets->m_size];
        if ( v17 )
        {
          *(_QWORD *)v17 = 0i64;
          *(_DWORD *)(v17 + 8) = 0;
          *(_DWORD *)(v17 + 12) = 0x80000000;
        }
        ++p_m_sets->m_size;
        v18 = (hkgpIndexedMeshDefinitions::Triangle *)array;
        do
        {
          v19 = *((_QWORD *)v18 + SDWORD2(array) - 1);
          --DWORD2(array);
          if ( *(_DWORD *)(v19 + 72) == -1 )
          {
            *(_DWORD *)(v19 + 72) = m_size;
            v20 = 0;
            v21 = 1;
            do
            {
              if ( (v21 & *(_DWORD *)(v19 + 80)) == 0 )
              {
                v22 = v19 + 8i64 * v20;
                if ( (*(_QWORD *)(v22 + 40) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
                {
                  vfptr = barriers->vfptr;
                  *(_QWORD *)&v46 = v19;
                  DWORD2(v46) = v20;
                  v47 = v46;
                  if ( !((unsigned __int8 (__fastcall *)(hkgpIndexedMesh::EdgeBarrier *, __int128 *))vfptr->isBlocked)(
                          barriers,
                          &v47) )
                  {
                    v24 = DWORD2(array);
                    v25 = *(_QWORD *)(v22 + 40) & 0xFFFFFFFFFFFFFFFCui64;
                    if ( DWORD2(array) == (HIDWORD(array) & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
                      v24 = DWORD2(array);
                    }
                    *(_QWORD *)(array + 8i64 * v24) = v25;
                    ++DWORD2(array);
                  }
                }
              }
              v21 = __ROL4__(v21, 1);
              ++v20;
            }
            while ( v20 < 3 );
            v18 = (hkgpIndexedMeshDefinitions::Triangle *)array;
          }
        }
        while ( SDWORD2(array) > 0 );
        DWORD2(array) = 0;
        if ( array >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v18, 8 * HIDWORD(array));
        p_m_sets = v50;
        v5 = this;
        *(_QWORD *)&array = 0i64;
        HIDWORD(array) = 0x80000000;
      }
      m_next = m_next->m_next;
      v26 = &v49;
      if ( !m_next )
        v26 = 0i64;
    }
    while ( v26 );
  }
  v27 = v5->m_triangles.m_used;
  DWORD2(v46) = 0;
  *(_QWORD *)&v46 = v27;
  array = v46;
  if ( v27
    && v27->m_vertices[0]->m_index > v27->m_vertices[1]->m_index
    && (v27->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next((hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&array);
  }
  v28 = (hkgpIndexedMeshDefinitions::Triangle *)array;
  p_array = &array;
  if ( !(_QWORD)array )
    p_array = 0i64;
  if ( p_array )
  {
    do
    {
      v30 = v28->m_links[SDWORD2(array)] & 0xFFFFFFFFFFFFFFFCui64;
      if ( v30 )
      {
        v31 = *(int *)(v30 + 72);
        m_set = v28->m_set;
        if ( (_DWORD)m_set != (_DWORD)v31 && ((*(_BYTE *)(v30 + 80) | LOBYTE(v28->m_flags)) & 8) == 0 )
        {
          v33 = 0;
          v34 = m_set;
          v35 = 0i64;
          v36 = &p_m_sets->m_data[v34];
          v37 = (__int64)&p_m_sets->m_data[v31];
          v38 = v36->m_links.m_size;
          if ( (int)v38 <= 0 )
            goto LABEL_54;
          v39 = v36->m_links.m_data;
          while ( *v39 != (_DWORD)v31 )
          {
            ++v35;
            ++v33;
            ++v39;
            if ( v35 >= v38 )
              goto LABEL_54;
          }
          if ( v33 == -1 )
          {
LABEL_54:
            if ( (_DWORD)v38 == (v36->m_links.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v36->m_links.m_data, 4);
            v36->m_links.m_data[v36->m_links.m_size++] = *(_DWORD *)(v30 + 72);
          }
          v40 = *(int *)(v37 + 8);
          v41 = 0;
          v42 = 0i64;
          if ( (int)v40 <= 0 )
            goto LABEL_63;
          v43 = *(_DWORD **)v37;
          while ( *v43 != v28->m_set )
          {
            ++v42;
            ++v41;
            ++v43;
            if ( v42 >= v40 )
              goto LABEL_63;
          }
          if ( v41 == -1 )
          {
LABEL_63:
            if ( (_DWORD)v40 == (*(_DWORD *)(v37 + 12) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v37, 4);
            *(_DWORD *)(*(_QWORD *)v37 + 4i64 * (int)(*(_DWORD *)(v37 + 8))++) = v28->m_set;
          }
        }
      }
      if ( v28 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next((hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&array);
        v28 = (hkgpIndexedMeshDefinitions::Triangle *)array;
      }
      v44 = &array;
      if ( !v28 )
        v44 = 0i64;
    }
    while ( v44 );
  }
}

// File Line: 571
// RVA: 0xCE3D40
void __fastcall hkgpIndexedMesh::getSetVertices(
        hkgpIndexedMesh *this,
        int set,
        hkArray<hkgpIndexedMeshDefinitions::Vertex *,hkContainerHeapAllocator> *vertices)
{
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rbx
  char *v7; // rax
  unsigned __int64 *m_vertices; // rsi
  __int64 v9; // rbp
  hkgpIndexedMeshDefinitions::Vertex *v10; // r14
  char *v11; // rax
  AMD_HD3D v12; // [rsp+20h] [rbp-38h] BYREF
  char v13; // [rsp+60h] [rbp+8h] BYREF

  v12.mHeight = -1;
  *(_QWORD *)&v12.mEnableStereo = 0i64;
  v12.mWidth = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v12,
    &hkContainerHeapAllocator::s_alloc,
    1024);
  m_used = this->m_triangles.m_used;
  v7 = &v13;
  if ( !m_used )
    v7 = 0i64;
  if ( v7 )
  {
    do
    {
      if ( m_used->m_set == set )
      {
        m_vertices = (unsigned __int64 *)m_used->m_vertices;
        v9 = 3i64;
        do
        {
          v10 = (hkgpIndexedMeshDefinitions::Vertex *)*m_vertices;
          if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v12,
                                *m_vertices,
                                0i64) )
          {
            if ( vertices->m_size == (vertices->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&vertices->m_data, 8);
            vertices->m_data[vertices->m_size++] = v10;
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v12,
              &hkContainerHeapAllocator::s_alloc,
              (unsigned __int64)v10,
              1ui64);
          }
          ++m_vertices;
          --v9;
        }
        while ( v9 );
      }
      m_used = m_used->m_next;
      v11 = &v13;
      if ( !m_used )
        v11 = 0i64;
    }
    while ( v11 );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v12,
    &hkContainerHeapAllocator::s_alloc);
  _(&v12);
}

// File Line: 592
// RVA: 0xCE3E90
void __fastcall hkgpIndexedMesh::getSetTriangles(
        hkgpIndexedMesh *this,
        int set,
        hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *triangles)
{
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rbx
  char *v4; // rax
  char *v7; // rax
  char v8; // [rsp+30h] [rbp+8h] BYREF

  m_used = this->m_triangles.m_used;
  v4 = &v8;
  if ( !m_used )
    v4 = 0i64;
  if ( v4 )
  {
    do
    {
      if ( m_used->m_set == set )
      {
        if ( triangles->m_size == (triangles->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&triangles->m_data, 8);
        triangles->m_data[triangles->m_size++] = m_used;
      }
      m_used = m_used->m_next;
      v7 = &v8;
      if ( !m_used )
        v7 = 0i64;
    }
    while ( v7 );
  }
}

// File Line: 601
// RVA: 0xCE3F30
void __fastcall hkgpIndexedMesh::deleteSetTriangles(hkgpIndexedMesh *this, int set)
{
  int v3; // edi
  __int64 v4; // rbx
  hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> triangles; // [rsp+20h] [rbp-18h] BYREF

  triangles.m_data = 0i64;
  triangles.m_size = 0;
  triangles.m_capacityAndFlags = 0x80000000;
  hkgpIndexedMesh::getSetTriangles(this, set, &triangles);
  v3 = 0;
  if ( triangles.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      hkgpIndexedMesh::removeTriangle(this, triangles.m_data[v4], 0i64);
      ++v3;
      ++v4;
    }
    while ( v3 < triangles.m_size );
  }
  triangles.m_size = 0;
  if ( triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      triangles.m_data,
      8 * triangles.m_capacityAndFlags);
}

