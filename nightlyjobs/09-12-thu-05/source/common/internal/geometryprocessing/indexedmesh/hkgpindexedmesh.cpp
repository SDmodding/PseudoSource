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
  this->vfptr = (hkBaseObjectVtbl *)&hkgpIndexedMesh::`vftable';
  this->m_vMap.m_map.m_elem = 0i64;
  this->m_vMap.m_map.m_numElems = 0;
  this->m_vMap.m_map.m_hashMod = -1;
  this->m_eMap.m_buckets.m_data = 0i64;
  this->m_eMap.m_buckets.m_size = 0;
  this->m_eMap.m_buckets.m_capacityAndFlags = 2147483648;
  this->m_eMap.m_numItems = 0;
  this->m_invalidTriangles.m_data = 0i64;
  this->m_invalidTriangles.m_size = 0;
  this->m_invalidTriangles.m_capacityAndFlags = 2147483648;
  this->m_sets.m_data = 0i64;
  this->m_sets.m_size = 0;
  this->m_sets.m_capacityAndFlags = 2147483648;
  hkgpIndexedMesh::reset(this);
}

// File Line: 55
// RVA: 0xCE1590
void __fastcall hkgpIndexedMesh::reset(hkgpIndexedMesh *this)
{
  hkgpIndexedMesh *v1; // r14
  int v2; // eax
  __int64 v3; // rdi
  int *v4; // rbx
  int v5; // er8
  int v6; // eax
  __int64 v7; // rdi
  int *v8; // rbx
  int v9; // er8
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // eax
  __int64 v14; // rdi
  int *v15; // rbx
  int v16; // er8
  signed __int64 v17; // rax
  int v18; // ecx
  signed __int64 v19; // rdx
  __int64 v20; // rax
  hkArray<hkgpIndexedMesh::EdgeMatch,hkContainerHeapAllocator> *v21; // rdx
  signed __int64 v22; // rcx
  int v23; // eax
  __int64 v24; // rdi
  int *v25; // rbx
  int v26; // er8
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&this->m_vertices);
  hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::reset((hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpAbstractMeshDefinitions::List<hkgpMeshBase::Vertex,hkgpMeshBase::BaseVertex,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> > *)&v1->m_triangles);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_vMap.m_map.m_elem);
  v2 = v1->m_eMap.m_buckets.m_size - 1;
  v3 = v2;
  if ( v2 >= 0 )
  {
    v4 = &v1->m_eMap.m_buckets.m_data->m_capacityAndFlags + 4 * v2;
    do
    {
      v5 = *v4;
      *(v4 - 1) = 0;
      if ( v5 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v4 - 3),
          16 * v5);
      *(_QWORD *)(v4 - 3) = 0i64;
      *v4 = 2147483648;
      v4 -= 4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v1->m_eMap.m_buckets.m_size = 0;
  v1->m_eMap.m_numItems = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_vMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    1031);
  v6 = v1->m_eMap.m_buckets.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = &v1->m_eMap.m_buckets.m_data->m_capacityAndFlags + 4 * v6;
    do
    {
      v9 = *v8;
      *(v8 - 1) = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v8 - 3),
          16 * v9);
      *(_QWORD *)(v8 - 3) = 0i64;
      *v8 = 2147483648;
      v8 -= 4;
      --v7;
    }
    while ( v7 >= 0 );
  }
  v1->m_eMap.m_buckets.m_size = 0;
  v1->m_eMap.m_numItems = 0;
  v10 = v1->m_eMap.m_buckets.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < 1031 )
  {
    v11 = 2 * v10;
    v12 = 1031;
    if ( v11 > 1031 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_eMap, v12, 16);
  }
  v13 = v1->m_eMap.m_buckets.m_size - 1032;
  v14 = v13;
  if ( v13 >= 0 )
  {
    v15 = &v1->m_eMap.m_buckets.m_data[1031].m_capacityAndFlags + 4 * v13;
    do
    {
      v16 = *v15;
      *(v15 - 1) = 0;
      if ( v16 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v15 - 3),
          16 * v16);
      *(_QWORD *)(v15 - 3) = 0i64;
      *v15 = 2147483648;
      v15 -= 4;
      --v14;
    }
    while ( v14 >= 0 );
  }
  v17 = v1->m_eMap.m_buckets.m_size;
  v18 = 1031 - v17;
  v19 = v17;
  v20 = 1031 - (signed int)v17;
  v21 = &v1->m_eMap.m_buckets.m_data[v19];
  if ( v18 > 0 )
  {
    do
    {
      if ( v21 )
      {
        v21->m_data = 0i64;
        v21->m_size = 0;
        v21->m_capacityAndFlags = 2147483648;
      }
      ++v21;
      --v20;
    }
    while ( v20 );
  }
  v1->m_eMap.m_buckets.m_size = 1031;
  v22 = 0i64;
  do
  {
    ++v22;
    *((_DWORD *)&v1->m_eMap.m_buckets.m_data[v22] - 2) = 0;
  }
  while ( v22 < 1031 );
  v1->m_nakedEdges = 0;
  v1->m_invalidTriangles.m_size = 0;
  v23 = v1->m_sets.m_size - 1;
  v24 = v23;
  if ( v23 >= 0 )
  {
    v25 = &v1->m_sets.m_data->m_links.m_capacityAndFlags + 4 * v23;
    do
    {
      v26 = *v25;
      *(v25 - 1) = 0;
      if ( v26 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v25 - 3),
          4 * v26);
      *(_QWORD *)(v25 - 3) = 0i64;
      *v25 = 2147483648;
      v25 -= 4;
      --v24;
    }
    while ( v24 >= 0 );
  }
  v1->m_sets.m_size = 0;
}

// File Line: 68
// RVA: 0xCE1860
void __fastcall hkgpIndexedMesh::appendFromMesh(hkgpIndexedMesh *this, hkgpIndexedMesh *mesh)
{
  hkgpIndexedMeshDefinitions::Triangle *v2; // rbx
  char *v3; // rax
  hkgpIndexedMesh *v4; // rdi
  int v5; // er9
  unsigned __int64 v6; // r8
  hkgpIndexedMeshDefinitions::Vertex *v7; // rax
  __int64 v8; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v9; // rax
  char *v10; // rax
  unsigned __int64 indices; // [rsp+30h] [rbp-28h]
  __int64 v12; // [rsp+38h] [rbp-20h]
  unsigned __int64 v13; // [rsp+40h] [rbp-18h]
  char v14; // [rsp+68h] [rbp+10h]

  v2 = mesh->m_triangles.m_used;
  v3 = &v14;
  v4 = this;
  if ( !v2 )
    v3 = 0i64;
  if ( v3 )
  {
    do
    {
      v5 = v2->m_material;
      v6 = v2->m_index;
      v7 = v2->m_vertices[1];
      indices = v2->m_vertices[0]->m_index;
      v8 = v7->m_index;
      v9 = v2->m_vertices[2];
      v12 = v8;
      v13 = v9->m_index;
      hkgpIndexedMesh::appendTriangle(v4, &indices, v6, v5, 0);
      v2 = v2->m_next;
      v10 = &v14;
      if ( !v2 )
        v10 = 0i64;
    }
    while ( v10 );
  }
}

// File Line: 78
// RVA: 0xCE1900
void __fastcall hkgpIndexedMesh::appendFromGeometry(hkgpIndexedMesh *this, hkGeometry *geometry)
{
  int v2; // ebx
  hkGeometry *v3; // rdi
  hkgpIndexedMesh *i; // rsi

  v2 = 0;
  v3 = geometry;
  for ( i = this; v2 < v3->m_triangles.m_size; ++v2 )
    hkgpIndexedMesh::appendTriangle(i, &v3->m_triangles.m_data[v2], v2);
}

// File Line: 87
// RVA: 0xCE1960
hkgpIndexedMeshDefinitions::Triangle *__fastcall hkgpIndexedMesh::appendTriangle(hkgpIndexedMesh *this, hkGeometry::Triangle *triangle, unsigned __int64 index)
{
  int v3; // er9
  unsigned __int64 indices; // [rsp+30h] [rbp-28h]
  __int64 v6; // [rsp+38h] [rbp-20h]
  __int64 v7; // [rsp+40h] [rbp-18h]

  v3 = triangle->m_material;
  indices = triangle->m_a;
  v6 = triangle->m_b;
  v7 = triangle->m_c;
  return hkgpIndexedMesh::appendTriangle(this, &indices, index, v3, 0);
}

// File Line: 94
// RVA: 0xCE19A0
hkgpIndexedMeshDefinitions::Triangle *__fastcall hkgpIndexedMesh::appendTriangle(hkgpIndexedMesh *this, const unsigned __int64 *indices, unsigned __int64 index, int material, int flags)
{
  signed int v5; // er12
  const unsigned __int64 *v6; // rdi
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r10
  int v9; // er15
  unsigned __int64 v10; // r14
  hkgpIndexedMesh *v11; // r13
  unsigned __int64 v12; // rax
  __int64 *v13; // rbx
  signed __int64 v14; // rsi
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
  signed __int64 v25; // r15
  unsigned __int64 v26; // rdx
  signed __int64 v27; // rax
  hkgpIndexedMeshDefinitions::Vertex *v28; // rbx
  signed __int64 v29; // r14
  unsigned __int64 v30; // rax
  signed __int64 v31; // rax
  int v32; // er10
  __int64 v33; // r8
  signed __int64 v34; // rax
  __int64 v35; // r11
  __int64 v36; // rsi
  __int64 v37; // rdx
  __int64 v38; // rcx
  __int64 v39; // rcx
  __int64 v40; // rax
  signed __int64 v41; // r8
  bool v42; // zf
  signed __int64 v43; // r8
  unsigned __int64 v44; // r8
  unsigned __int64 v45; // rdx
  signed __int64 v46; // r8
  int v47; // er11
  signed __int64 v48; // r9
  signed __int64 v49; // rdi
  signed __int64 v50; // rbp
  __int64 v51; // rsi
  __int64 v52; // r8
  __int64 v53; // rdx
  signed int v54; // er9
  signed __int64 v55; // rax
  __int64 v56; // r8
  __int64 v57; // r10
  signed __int64 v58; // rdx
  signed __int64 v59; // rax
  signed __int64 v60; // r8
  __int64 v61; // rcx
  unsigned __int64 v62; // rdx
  unsigned __int64 v63; // rcx
  unsigned int v64; // ecx
  int v65; // edx
  signed int v66; // edx
  signed __int64 v67; // rbx
  hkgpIndexedMeshDefinitions::Triangle **v68; // rcx
  __int64 v69; // rax
  hkgpIndexedMeshDefinitions::Triangle *result; // rax
  hkgpIndexedMeshDefinitions::Vertex *v71; // [rsp+20h] [rbp-48h]
  __int64 v72; // [rsp+28h] [rbp-40h]
  __int64 v73; // [rsp+30h] [rbp-38h]
  hkgpIndexedMeshDefinitions::Triangle *v74; // [rsp+78h] [rbp+10h]

  v5 = 0;
  v6 = indices;
  v7 = indices[1];
  v8 = *v6;
  v9 = material;
  v10 = index;
  v11 = this;
  v71 = 0i64;
  v72 = 0i64;
  v73 = 0i64;
  if ( v8 == v7 || (v12 = v6[2], v7 == v12) || v12 == v8 )
  {
    if ( this->m_invalidTriangles.m_size == (this->m_invalidTriangles.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_invalidTriangles,
        8);
    v11->m_invalidTriangles.m_data[v11->m_invalidTriangles.m_size++] = v10;
    result = 0i64;
  }
  else
  {
    v13 = (__int64 *)&v71;
    v14 = 3i64;
    v15 = (char *)v6 - (char *)&v71;
    do
    {
      v16 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11->m_vMap.m_map.m_elem,
              *(__int64 *)((char *)v13 + v15),
              0i64);
      *v13 = v16;
      if ( !v16 )
      {
        v17 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&v11->m_vertices);
        v18 = v11->m_vertices.m_numUsed - 1;
        *v13 = (__int64)v17;
        *(_DWORD *)&v17->m_items[0].m_data[24] = v18;
        *(_QWORD *)&v17->m_items[0].m_data[16] = *(__int64 *)((char *)v13 + v15);
        *(_DWORD *)&v17->m_items[0].m_data[28] = 0;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v11->m_vMap.m_map.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          *(__int64 *)((char *)v13 + v15),
          (unsigned __int64)v17);
      }
      v19 = *v13;
      ++v13;
      ++*(_DWORD *)(v19 + 28);
      --v14;
    }
    while ( v14 );
    v20 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&v11->m_triangles);
    v20->m_vertices[0] = v71;
    v21 = v72;
    v20->m_material = v9;
    v20->m_vertices[1] = (hkgpIndexedMeshDefinitions::Vertex *)v21;
    v22 = v73;
    v20->m_index = v10;
    v20->m_vertices[2] = (hkgpIndexedMeshDefinitions::Vertex *)v22;
    v23 = v20;
    v20->m_flags = flags;
    LODWORD(v22) = v11->m_triangles.m_numUsed;
    v20->m_set = -1;
    v74 = v20;
    v20->m_lidx = v22 - 1;
    v11->m_nakedEdges += 3;
    do
    {
      v24 = v23->m_vertices[v5];
      v25 = (signed __int64)v23 + 8 * v5;
      v26 = v24->m_index;
      v27 = (9i64 >> 2 * (unsigned __int8)v5) & 3;
      LODWORD(v72) = v5;
      v28 = v23->m_vertices[v27];
      v29 = (signed __int64)v23 + 8 * v27;
      v30 = v28->m_index;
      if ( v26 >= v30 )
        v31 = 3424933 * v30 ^ 1661161 * v26;
      else
        v31 = 3424933 * v26 ^ 1661161 * v30;
      v32 = 0;
      v33 = 0i64;
      v34 = (signed __int64)&v11->m_eMap.m_buckets.m_data[(unsigned int)v31 % v11->m_eMap.m_buckets.m_size];
      v35 = *(signed int *)(v34 + 8);
      if ( v35 <= 0 )
        goto LABEL_18;
      v36 = *(_QWORD *)v34;
      v37 = *(_QWORD *)v34;
      while ( 1 )
      {
        v38 = *(signed int *)(v37 + 8);
        if ( *(hkgpIndexedMeshDefinitions::Vertex **)(*(_QWORD *)v37 + 8 * v38 + 16) == v28
          && *(hkgpIndexedMeshDefinitions::Vertex **)(*(_QWORD *)v37 + 8 * ((9i64 >> 2 * (unsigned __int8)v38) & 3) + 16) == v24 )
        {
          break;
        }
        ++v33;
        ++v32;
        v37 += 16i64;
        if ( v33 >= v35 )
          goto LABEL_17;
      }
      if ( v32 == -1 )
      {
LABEL_17:
        v23 = v74;
        goto LABEL_18;
      }
      v41 = 16i64 * v32;
      v42 = v36 + v41 == 0;
      v43 = v36 + v41;
      v23 = v74;
      if ( v42 )
      {
LABEL_18:
        if ( `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' & 1 )
        {
          v40 = DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e);
          v39 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
        }
        else
        {
          v39 = 0i64;
          `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' |= 1u;
          v40 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e = 0i64;
          DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e) = 0;
        }
        v23->m_links[v5] = v39 + v40;
        if ( (_QWORD)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e )
          *(_QWORD *)(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e
                    + 8i64
                    * SDWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e)
                    + 40) = (char *)v23 + (unsigned int)v5;
        v62 = *(_QWORD *)(*(_QWORD *)(v29 + 16) + 16i64);
        v63 = *(_QWORD *)(*(_QWORD *)(v25 + 16) + 16i64);
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
        ++v11->m_eMap.m_numItems;
        v66 = (v65 ^ v64) % v11->m_eMap.m_buckets.m_size;
        v67 = (signed __int64)&v11->m_eMap.m_buckets.m_data[v66];
        if ( *(_DWORD *)(v67 + 8) == (*(_DWORD *)(v67 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v11->m_eMap.m_buckets.m_data[v66],
            16);
        v68 = (hkgpIndexedMeshDefinitions::Triangle **)(*(_QWORD *)v67 + 16i64 * (signed int)(*(_DWORD *)(v67 + 8))++);
        v69 = v72;
        *v68 = v23;
        v68[1] = (hkgpIndexedMeshDefinitions::Triangle *)v69;
      }
      else
      {
        *(_QWORD *)(*(_QWORD *)v43 + 8i64 * *(signed int *)(v43 + 8) + 40) = (char *)v74 + (unsigned int)v5;
        v74->m_links[v5] = *(_QWORD *)v43 + *(unsigned int *)(v43 + 8);
        v44 = *(_QWORD *)(*(_QWORD *)(v29 + 16) + 16i64);
        v45 = *(_QWORD *)(*(_QWORD *)(v25 + 16) + 16i64);
        if ( v45 >= v44 )
          v46 = 3424933 * v44 ^ 1661161 * v45;
        else
          v46 = 3424933 * v45 ^ 1661161 * v44;
        --v11->m_eMap.m_numItems;
        v47 = 0;
        v48 = 0i64;
        v49 = (signed __int64)&v11->m_eMap.m_buckets.m_data[(unsigned int)v46 % v11->m_eMap.m_buckets.m_size];
        v50 = *(signed int *)(v49 + 8);
        if ( (signed int)v50 > 0 )
        {
          v51 = *(_QWORD *)v49;
          v52 = *(_QWORD *)v49;
          while ( 1 )
          {
            v53 = *(signed int *)(v52 + 8);
            if ( *(_QWORD *)(*(_QWORD *)v52 + 8 * v53 + 16) == *(_QWORD *)(v29 + 16)
              && *(_QWORD *)(*(_QWORD *)v52 + 8 * ((9i64 >> 2 * (unsigned __int8)v53) & 3) + 16) == *(_QWORD *)(v25 + 16) )
            {
              break;
            }
            ++v48;
            ++v47;
            v52 += 16i64;
            if ( v48 >= v50 )
            {
              v23 = v74;
              v11->m_nakedEdges -= 2;
              goto LABEL_52;
            }
          }
          if ( v47 >= 0 )
          {
            v54 = 0;
            v55 = 0i64;
            if ( (signed int)v50 <= 0 )
            {
LABEL_37:
              v54 = -1;
              v55 = -1i64;
            }
            else
            {
              v56 = *(_QWORD *)v49;
              while ( 1 )
              {
                v57 = *(signed int *)(v56 + 8);
                if ( *(_QWORD *)(*(_QWORD *)v56 + 8 * v57 + 16) == *(_QWORD *)(v29 + 16)
                  && *(_QWORD *)(*(_QWORD *)v56 + 8 * ((9i64 >> 2 * (unsigned __int8)v57) & 3) + 16) == *(_QWORD *)(v25 + 16) )
                {
                  break;
                }
                ++v55;
                ++v54;
                v56 += 16i64;
                if ( v55 >= v50 )
                  goto LABEL_37;
              }
            }
            *(_DWORD *)(v49 + 8) = v50 - 1;
            if ( (_DWORD)v50 - 1 != v54 )
            {
              v58 = 2i64;
              v59 = v51 + 16 * v55;
              v60 = v51 + 16i64 * ((signed int)v50 - 1) - v59;
              do
              {
                v61 = *(_QWORD *)(v60 + v59);
                v59 += 8i64;
                *(_QWORD *)(v59 - 8) = v61;
                --v58;
              }
              while ( v58 );
            }
          }
          v23 = v74;
        }
        v11->m_nakedEdges -= 2;
      }
LABEL_52:
      ++v5;
    }
    while ( v5 < 3 );
    result = v23;
  }
  return result;
}

// File Line: 146
// RVA: 0xCE1E90
void __fastcall hkgpIndexedMesh::collapseEdge(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Edge *edge, hkgpIndexedMeshDefinitions::Edge *edgeOut, hkgpIndexedMesh::IEdgeCollapse *itrf)
{
  hkgpIndexedMeshDefinitions::Edge v4; // xmm0
  hkgpIndexedMeshDefinitions::Edge *v5; // rsi
  hkgpIndexedMeshDefinitions::Edge *v6; // rbx
  hkgpIndexedMesh::IEdgeCollapse *v7; // rdi
  hkgpIndexedMesh *v8; // rbp
  hkgpIndexedMeshDefinitions::Edge v9; // [rsp+30h] [rbp-228h]
  char *v10; // [rsp+40h] [rbp-218h]
  int v11; // [rsp+48h] [rbp-210h]
  int v12; // [rsp+4Ch] [rbp-20Ch]
  char v13; // [rsp+50h] [rbp-208h]

  v4 = *edge;
  v5 = edgeOut;
  v6 = edge;
  v7 = itrf;
  v8 = this;
  v11 = 0;
  v9 = v4;
  v10 = &v13;
  v12 = -2147483584;
  hkgpIndexedMesh::getBothRings(
    this,
    &v9,
    (hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *)&v10);
  v9 = *v6;
  hkgpIndexedMesh::collapseEdge(
    v8,
    (hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *)&v10,
    &v9,
    v5,
    v7);
  v11 = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v10,
      8 * v12);
}

// File Line: 157
// RVA: 0xCE1F60
void __fastcall hkgpIndexedMesh::collapseEdge(hkgpIndexedMesh *this, hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *inRing, hkgpIndexedMeshDefinitions::Edge *edge, hkgpIndexedMeshDefinitions::Edge *edgeOut, hkgpIndexedMesh::IEdgeCollapse *itrf)
{
  hkgpIndexedMeshDefinitions::Edge *v5; // rbx
  hkgpIndexedMeshDefinitions::Triangle **v6; // r8
  hkgpIndexedMeshDefinitions::Edge *v7; // r15
  int v8; // er9
  hkgpIndexedMesh *v9; // rsi
  hkgpIndexedMesh::ITriangleRemoval *v10; // r13
  hkgpIndexedMeshDefinitions::Triangle *v11; // rax
  __int64 v12; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v13; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v14; // rbx
  hkgpIndexedMeshDefinitions::Vertex *v15; // r12
  __int64 v16; // r8
  int v17; // edx
  signed __int64 v18; // rax
  char *v19; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v20; // rax
  hkgpIndexedMeshDefinitions::Vertex *v21; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v22; // rdx
  bool v23; // zf
  hkgpIndexedMeshDefinitions::Vertex *v24; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *v25; // rax
  unsigned __int64 v26; // rcx
  int v27; // er11
  char **v28; // r14
  int v29; // ebx
  __int64 v30; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v31; // rdx
  signed int v32; // eax
  __int64 v33; // rcx
  signed int v34; // ebx
  __int64 v35; // rdi
  signed __int64 v36; // rsi
  int v37; // er10
  int v38; // eax
  char *v39; // r8
  hkgpIndexedMesh::ITriangleRemoval v40; // rax
  __m128i v41; // [rsp+20h] [rbp-D8h]
  __m128i v42; // [rsp+30h] [rbp-C8h]
  __int128 v43; // [rsp+40h] [rbp-B8h]
  __int128 v44; // [rsp+50h] [rbp-A8h]
  hkArrayBase<char *> v45; // [rsp+60h] [rbp-98h]
  char v46; // [rsp+70h] [rbp-88h]
  __int64 v47; // [rsp+4C0h] [rbp+3C8h]
  void **v48; // [rsp+4C8h] [rbp+3D0h]
  hkgpIndexedMeshDefinitions::Edge *v49; // [rsp+4D0h] [rbp+3D8h]
  hkgpIndexedMesh::ITriangleRemoval *itrfa; // [rsp+4D8h] [rbp+3E0h]

  itrfa = (hkgpIndexedMesh::ITriangleRemoval *)edgeOut;
  v5 = edge;
  v6 = inRing->m_data;
  v7 = edgeOut;
  v8 = inRing->m_size;
  v9 = this;
  v45.m_size = 0;
  v45.m_capacityAndFlags = -2147483520;
  v45.m_data = (char **)&v46;
  hkArrayBase<unsigned __int64>::_append(
    &v45,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (char *const *)v6,
    v8);
  v48 = &hkgpIndexedMeshInternals::DefaultEdgeCollapseInterface::`vftable';
  v10 = (hkgpIndexedMesh::ITriangleRemoval *)&v48;
  if ( itrfa )
    v10 = itrfa;
  if ( v7 )
  {
    if ( `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v11 = (hkgpIndexedMeshDefinitions::Triangle *)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
    }
    else
    {
      `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' |= 1u;
      v11 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e) = 0;
    }
    v7->m_triangle = v11;
    *(_QWORD *)&v7->m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e
                              + 1);
  }
  v12 = (signed int)v5->m_index;
  v13 = v5->m_triangle;
  v14 = v5->m_triangle->m_vertices[v12];
  v15 = v13->m_vertices[(9i64 >> 2 * (unsigned __int8)v12) & 3];
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
    v20 = v14->m_next;
    v21 = v14->m_prev;
    if ( v14->m_next )
      v20->m_prev = v21;
    if ( v21 )
      v21->m_next = v20;
    else
      v9->m_vertices.m_used = v20;
    --v9->m_vertices.m_numUsed;
    v22 = v14[1].m_next;
    v23 = v22[48].m_lidx-- == 1;
    if ( v23 )
    {
      v24 = v22[48].m_prev;
      v25 = (hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *)v22[48].m_index;
      if ( v24 )
        v24[48].m_index = (unsigned __int64)v25;
      else
        v9->m_vertices.m_allocator.m_firstPool = v25;
      v26 = v22[48].m_index;
      if ( v26 )
        *(_QWORD *)(v26 + 1544) = v22[48].m_prev;
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v22,
        1568);
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
        v32 = 0;
        if ( v31->m_vertices[0] == v15 )
          v32 = 1;
        if ( v31->m_vertices[1] == v15 )
          ++v32;
        if ( v31->m_vertices[2] == v15 )
          ++v32;
        if ( v32 > 1 )
        {
          hkgpIndexedMesh::removeTriangle(v9, v31, v10);
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
        v34 = 0;
        do
        {
          v35 = *(__int64 *)((char *)v28 + v33);
          v41.m128i_i32[2] = v34;
          v36 = v35 + 8i64 * v34;
          v41.m128i_i64[0] = *(__int64 *)((char *)v28 + v33);
          if ( *(hkgpIndexedMeshDefinitions::Vertex **)(v36 + 16) == v15 )
          {
            if ( v7 )
              *v7 = (hkgpIndexedMeshDefinitions::Edge)v41;
            if ( !(*(_QWORD *)(v35 + 8i64 * v34 + 40) & 0xFFFFFFFFFFFFFFFCui64) )
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
                    v42.m128i_i64[0] = (__int64)v28[v37];
                    v42.m128i_i32[2] = v38;
                    if ( !(*(_QWORD *)&v39[8 * v38 + 40] & 0xFFFFFFFFFFFFFFFCui64)
                      && (!v39
                       || *(_QWORD *)(v36 + 16) == *(_QWORD *)&v39[8 * ((9i64 >> 2 * (unsigned __int8)v38) & 3) + 16]
                       && *(_QWORD *)(v35 + 8 * ((9i64 >> 2 * (unsigned __int8)v34) & 3) + 16) == *(_QWORD *)&v39[8 * v38 + 16]) )
                    {
                      break;
                    }
                    if ( ++v38 >= 3 )
                      goto LABEL_59;
                  }
                  *(_QWORD *)(v35 + 8i64 * v34 + 40) = &v39[v38];
                  if ( v39 )
                    *(_QWORD *)&v39[8 * v38 + 40] = v35 + (unsigned int)v34;
                  v40.vfptr = v10->vfptr;
                  _mm_store_si128((__m128i *)&v44, v41);
                  _mm_store_si128((__m128i *)&v43, v42);
                  ((void (__fastcall *)(hkgpIndexedMesh::ITriangleRemoval *, __int128 *, __int128 *))v40.vfptr[2].__vecDelDtor)(
                    v10,
                    &v44,
                    &v43);
                  v27 = v45.m_size;
                  v28 = v45.m_data;
                  v37 = v45.m_size;
LABEL_59:
                  ++v37;
                }
                while ( v37 < v27 );
                v33 = v47;
              }
            }
            v7 = v49;
          }
          ++v34;
        }
        while ( v34 < 3 );
        v33 += 8i64;
        v47 = v33;
        LODWORD(itrfa) = (_DWORD)itrfa + 1;
      }
      while ( (signed int)itrfa < v27 );
    }
  }
  else
  {
    v28 = v45.m_data;
  }
  v45.m_size = 0;
  v48 = &hkgpIndexedMesh::IVertexRemoval::`vftable';
  if ( v45.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v28,
      8 * v45.m_capacityAndFlags);
}

// File Line: 237
// RVA: 0xCE23F0
hkBool *__fastcall hkgpIndexedMesh::canFlipEdge(hkgpIndexedMesh *this, hkBool *result, hkgpIndexedMeshDefinitions::Edge *edge)
{
  __int64 v3; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v4; // r8
  hkBool *v5; // r9
  signed __int64 v6; // rax
  unsigned __int64 v7; // r10
  hkBool *v8; // rax
  char v9; // si
  char v10; // di
  unsigned __int64 v11; // r11
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r11

  v3 = (signed int)edge->m_index;
  v4 = edge->m_triangle;
  v5 = result;
  v6 = v4->m_links[v3] & 3;
  v7 = v4->m_links[v3] & 0xFFFFFFFFFFFFFFFCui64;
  if ( v7 )
  {
    v9 = 2 * v6;
    v10 = 2 * v3;
    v5->m_bool = v4->m_vertices[(18i64 >> 2 * (unsigned __int8)v3) & 3] != *(hkgpIndexedMeshDefinitions::Vertex **)(v7 + 8 * ((18i64 >> 2 * (unsigned __int8)v6) & 3) + 16)
              && ((v11 = v4->m_links[(9 >> v10) & 3],
                   v12 = v4->m_links[(18 >> v10) & 3] & 0xFFFFFFFFFFFFFFFCui64,
                   v13 = *(_QWORD *)(v7 + 8i64 * ((9 >> v9) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64,
                   v14 = *(_QWORD *)(v7 + 8i64 * ((18 >> v9) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64,
                   (v15 = v11 & 0xFFFFFFFFFFFFFFFCui64) == 0)
               || !v12
               || v15 != v12)
              && (!v13 || !v14 || v13 != v14)
              && (!v15 || !v14 || v15 != v14)
              && (!v12 || !v13 || v12 != v13);
    v8 = v5;
  }
  else
  {
    result->m_bool = 0;
    v8 = result;
  }
  return v8;
}

// File Line: 255
// RVA: 0xCE2510
hkgpIndexedMeshDefinitions::Edge *__fastcall hkgpIndexedMesh::flipEdge(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Edge *result, hkgpIndexedMeshDefinitions::Edge *edge)
{
  __int64 v3; // rax
  hkgpIndexedMeshDefinitions::Triangle *v4; // rbp
  hkgpIndexedMeshDefinitions::Edge *v5; // r15
  unsigned __int64 v6; // rsi
  char v7; // bl
  hkgpIndexedMeshDefinitions::Vertex *v8; // r8
  char v9; // r9
  _QWORD *v10; // rsi
  int v11; // er9
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

  v3 = (signed int)edge->m_index;
  v4 = edge->m_triangle;
  v5 = result;
  v6 = edge->m_triangle->m_links[v3];
  v7 = 2 * v3;
  v8 = edge->m_triangle->m_vertices[v3];
  v9 = v6;
  v10 = (_QWORD *)(v6 & 0xFFFFFFFFFFFFFFFCui64);
  v11 = v9 & 3;
  v12 = 2 * v11;
  v13 = v4->m_links[(9 >> 2 * v3) & 3] & 0xFFFFFFFFFFFFFFFCui64;
  v21 = v4->m_links[(9 >> 2 * v3) & 3] & 3;
  v14 = v4->m_links[(18 >> 2 * v3) & 3];
  v22 = v14 & 0xFFFFFFFFFFFFFFFCui64;
  v23 = v14 & 3;
  v15 = v10[((9 >> 2 * v11) & 3) + 5] & 0xFFFFFFFFFFFFFFFCui64;
  v24 = v10[((9 >> 2 * v11) & 3) + 5] & 3;
  v16 = v10[((18 >> 2 * v11) & 3) + 5] & 0xFFFFFFFFFFFFFFFCui64;
  v25 = v10[((18 >> 2 * v11) & 3) + 5] & 3;
  v17 = v10[v11 + 2];
  v18 = v4->m_vertices[(18i64 >> v7) & 3];
  v19 = (hkgpIndexedMeshDefinitions::Vertex *)v10[((18i64 >> v12) & 3) + 2];
  --v8->m_numRefs;
  --*(_DWORD *)(v17 + 28);
  ++v18->m_numRefs;
  ++v19->m_numRefs;
  v4->m_vertices[0] = v19;
  v4->m_vertices[2] = v8;
  v4->m_vertices[1] = v18;
  v10[3] = v19;
  v10[2] = v18;
  v10[4] = v17;
  v4->m_links[0] = (unsigned __int64)v10;
  v10[5] = v4;
  v4->m_links[1] = v22 + v23;
  if ( v22 )
    *(_QWORD *)(v22 + 8i64 * (signed int)v23 + 40) = (char *)v4 + 1;
  v4->m_links[2] = v15 + v24;
  if ( v15 )
    *(_QWORD *)(v15 + 8i64 * (signed int)v24 + 40) = (char *)v4 + 2;
  v10[6] = v16 + v25;
  if ( v16 )
    *(_QWORD *)(v16 + 8i64 * (signed int)v25 + 40) = (char *)v10 + 1;
  v10[7] = v13 + v21;
  if ( v13 )
    *(_QWORD *)(v13 + 8i64 * (signed int)v21 + 40) = (char *)v10 + 2;
  v5->m_triangle = v4;
  v5->m_index = 0;
  return v5;
}

// File Line: 282
// RVA: 0xCE26D0
hkgpIndexedMeshDefinitions::Edge *__fastcall hkgpIndexedMesh::splitEdge(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Edge *result, hkgpIndexedMeshDefinitions::Edge *edge)
{
  __int64 v3; // rax
  hkgpIndexedMeshDefinitions::Triangle *v4; // r13
  unsigned __int64 v5; // r12
  hkgpIndexedMeshDefinitions::Edge *v6; // r14
  hkgpIndexedMesh *v7; // rbx
  __int64 v8; // rbp
  hkgpIndexedMeshDefinitions::Vertex *v9; // r14
  char v10; // r8
  char v11; // r9
  unsigned __int64 v12; // r12
  int v13; // er9
  unsigned __int64 v14; // rax
  hkgpIndexedMeshDefinitions::Vertex *v15; // r15
  hkgpIndexedMeshDefinitions::Vertex *v16; // rbp
  hkgpIndexedMeshDefinitions::Vertex *v17; // rsi
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v18; // rax
  hkgpIndexedMeshDefinitions::Vertex *v19; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v20; // rax
  hkgpIndexedMeshDefinitions::Edge *v21; // rax
  hkgpIndexedMeshDefinitions::Vertex *v22; // rbp
  unsigned __int64 v23; // r15
  unsigned __int64 v24; // r12
  hkgpIndexedMeshDefinitions::Vertex *v25; // rdi
  hkgpIndexedMeshDefinitions::Vertex *v26; // rsi
  unsigned int v27; // eax
  unsigned __int64 v28; // r12
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v29; // rax
  hkgpIndexedMeshDefinitions::Vertex *v30; // rbx
  hkgpIndexedMeshDefinitions::Triangle *v31; // rax
  hkgpIndexedMeshDefinitions::Triangle *v32; // rdx
  unsigned int v33; // er8
  __int64 v34; // rcx
  __int64 v35; // rax
  __int64 v36; // r9
  unsigned int v37; // [rsp+20h] [rbp-78h]
  unsigned int v38; // [rsp+24h] [rbp-74h]
  hkgpIndexedMeshDefinitions::Triangle *v39; // [rsp+28h] [rbp-70h]
  unsigned __int64 v40; // [rsp+30h] [rbp-68h]
  unsigned __int64 v41; // [rsp+38h] [rbp-60h]
  unsigned __int64 v42; // [rsp+40h] [rbp-58h]
  unsigned __int64 v43; // [rsp+48h] [rbp-50h]
  hkgpIndexedMesh *v44; // [rsp+A0h] [rbp+8h]
  hkgpIndexedMeshDefinitions::Edge *v45; // [rsp+A8h] [rbp+10h]
  unsigned int v46; // [rsp+B0h] [rbp+18h]
  unsigned int v47; // [rsp+B0h] [rbp+18h]
  unsigned int v48; // [rsp+B8h] [rbp+20h]
  unsigned int v49; // [rsp+B8h] [rbp+20h]

  v45 = result;
  v44 = this;
  v3 = (signed int)edge->m_index;
  v4 = edge->m_triangle;
  v5 = edge->m_triangle->m_links[v3];
  v6 = result;
  v7 = this;
  v8 = (signed int)edge->m_index;
  if ( v5 & 0xFFFFFFFFFFFFFFFCui64 )
  {
    v9 = v4->m_vertices[v8];
    v10 = 2 * v3;
    v11 = v5;
    v12 = v5 & 0xFFFFFFFFFFFFFFFCui64;
    v13 = v11 & 3;
    v14 = v4->m_links[(9 >> 2 * v3) & 3];
    v42 = v14 & 0xFFFFFFFFFFFFFFFCui64;
    v37 = v14 & 3;
    v46 = v4->m_links[(18 >> v10) & 3] & 3;
    v40 = v4->m_links[(18 >> v10) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v48 = *(_QWORD *)(v12 + 8i64 * ((9 >> 2 * v13) & 3) + 40) & 3;
    v41 = *(_QWORD *)(v12 + 8i64 * ((9 >> 2 * v13) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v43 = *(_QWORD *)(v12 + 8i64 * ((18 >> 2 * v13) & 3) + 40) & 0xFFFFFFFFFFFFFFFCui64;
    v15 = *(hkgpIndexedMeshDefinitions::Vertex **)(v12 + 8i64 * v13 + 16);
    v38 = *(_QWORD *)(v12 + 8i64 * ((18 >> 2 * v13) & 3) + 40) & 3;
    v16 = v4->m_vertices[(18i64 >> v10) & 3];
    v17 = *(hkgpIndexedMeshDefinitions::Vertex **)(v12 + 8 * ((18i64 >> 2 * (unsigned __int8)v13) & 3) + 16);
    ++v16->m_numRefs;
    ++v17->m_numRefs;
    v18 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&this->m_vertices);
    *(_DWORD *)&v18->m_items[0].m_data[28] = 4;
    v19 = (hkgpIndexedMeshDefinitions::Vertex *)v18;
    *(_QWORD *)&v18->m_items[0].m_data[16] = v9->m_index;
    v39 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_triangles);
    v20 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&v7->m_triangles);
    v39->m_index = v4->m_index;
    v39->m_material = v4->m_material;
    v20->m_index = *(_QWORD *)(v12 + 64);
    v20->m_material = *(_DWORD *)(v12 + 76);
    v4->m_vertices[0] = v19;
    v4->m_vertices[1] = v16;
    v4->m_vertices[2] = v9;
    *(_QWORD *)(v12 + 16) = v19;
    *(_QWORD *)(v12 + 24) = v9;
    *(_QWORD *)(v12 + 32) = v17;
    v39->m_vertices[0] = v19;
    v39->m_vertices[1] = v15;
    v39->m_vertices[2] = v16;
    v20->m_vertices[0] = v19;
    v20->m_vertices[1] = v17;
    v20->m_vertices[2] = v15;
    v4->m_links[1] = v40 + v46;
    if ( v40 )
      *(_QWORD *)(v40 + 8i64 * (signed int)v46 + 40) = (char *)v4 + 1;
    *(_QWORD *)(v12 + 48) = v41 + v48;
    if ( v41 )
      *(_QWORD *)(v41 + 8i64 * (signed int)v48 + 40) = v12 + 1;
    v39->m_links[1] = v42 + v37;
    if ( v42 )
      *(_QWORD *)(v42 + 8i64 * (signed int)v37 + 40) = (char *)v39 + 1;
    v20->m_links[1] = v43 + v38;
    if ( v43 )
      *(_QWORD *)(v43 + 8i64 * (signed int)v38 + 40) = (char *)v20 + 1;
    v4->m_links[2] = v12;
    *(_QWORD *)(v12 + 40) = (char *)v4 + 2;
    v39->m_links[0] = (unsigned __int64)&v20->m_next + 2;
    v20->m_links[2] = (unsigned __int64)v39;
    v4->m_links[0] = (unsigned __int64)&v39->m_next + 2;
    v39->m_links[2] = (unsigned __int64)v4;
    *(_QWORD *)(v12 + 56) = v20;
    v20->m_links[0] = v12 + 2;
    v21 = v45;
    v45->m_triangle = v4;
    v45->m_index = 2;
  }
  else
  {
    v22 = v4->m_vertices[v8];
    v23 = v4->m_links[(9 >> 2 * v3) & 3] & 0xFFFFFFFFFFFFFFFCui64;
    v49 = v4->m_links[(9 >> 2 * v3) & 3] & 3;
    v24 = v4->m_links[(18 >> 2 * v3) & 3];
    v25 = v4->m_vertices[(18i64 >> 2 * (unsigned __int8)v3) & 3];
    v26 = v4->m_vertices[(9i64 >> 2 * (unsigned __int8)v3) & 3];
    ++v25->m_numRefs;
    v27 = v24 & 3;
    v28 = v24 & 0xFFFFFFFFFFFFFFFCui64;
    v47 = v27;
    v29 = hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>>::allocate((hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpAbstractMeshDefinitions::List<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,hkgpTriangulatorBase::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkg)&this->m_vertices);
    *(_DWORD *)&v29->m_items[0].m_data[28] = 2;
    v30 = (hkgpIndexedMeshDefinitions::Vertex *)v29;
    *(_QWORD *)&v29->m_items[0].m_data[16] = v22->m_index;
    v31 = hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Triangle,hkgpAbstractMeshDefinitions::List<hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::VertexBase,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>>::Item,hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>>::allocate(&v44->m_triangles);
    v31->m_index = v4->m_index;
    v32 = v31;
    v31->m_material = v4->m_material;
    v4->m_vertices[0] = v30;
    v4->m_vertices[1] = v25;
    v4->m_vertices[2] = v22;
    v31->m_vertices[0] = v30;
    v31->m_vertices[1] = v26;
    v31->m_vertices[2] = v25;
    v4->m_links[1] = v28 + v47;
    if ( v28 )
      *(_QWORD *)(v28 + 8i64 * (signed int)v47 + 40) = (char *)v4 + 1;
    v31->m_links[1] = v23 + v49;
    if ( v23 )
      *(_QWORD *)(v23 + 8i64 * (signed int)v49 + 40) = (char *)v31 + 1;
    v33 = 0;
    v4->m_links[0] = (unsigned __int64)&v31->m_next + 2;
    v31->m_links[2] = (unsigned __int64)v4;
    if ( `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v35 = DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e);
      v34 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
    }
    else
    {
      v34 = 0i64;
      `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' |= 1u;
      v35 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e = 0i64;
      DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e) = 0;
    }
    v4->m_links[2] = v34 + v35;
    v36 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e )
    {
      *(_QWORD *)(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e)
                + 40) = (char *)v4 + 2;
      v36 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
    }
    if ( `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' & 1 )
    {
      v33 = DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e);
    }
    else
    {
      v36 = 0i64;
      *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e = 0i64;
      `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' |= 1u;
      DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e) = 0;
    }
    v32->m_links[0] = v36 + v33;
    if ( (_QWORD)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e )
      *(_QWORD *)(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e
                + 8i64
                * SDWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e)
                + 40) = v32;
    v6->m_triangle = v4;
    v6->m_index = 2;
    v21 = v6;
  }
  return v21;
}

// File Line: 358
// RVA: 0xCE2B30
void __fastcall hkgpIndexedMesh::getBothRings(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Edge *edge, hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *ring)
{
  hkgpIndexedMesh *v3; // r13
  __int64 v4; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v5; // rbp
  int v6; // esi
  hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *v7; // rdi
  hkgpIndexedMeshDefinitions::Edge *v8; // r15
  hkgpIndexedMeshDefinitions::Vertex *v9; // r14
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // eax
  bool v14; // zf
  bool v15; // bl
  bool v16; // al
  hkgpIndexedMeshDefinitions::Triangle *v17; // rbx
  hkResult *v18; // rax
  hkgpIndexedMeshDefinitions::Vertex *v19; // rax
  hkgpIndexedMeshDefinitions::Vertex *v20; // rax
  hkgpIndexedMeshDefinitions::Vertex *v21; // rax
  hkResult *v22; // rax
  signed int v23; // er8
  __int64 v24; // r9
  hkgpIndexedMeshDefinitions::Triangle **v25; // rax
  int v26; // ecx
  __int64 v27; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v28; // rcx
  __m128i v29; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v3 = this;
  v4 = (signed int)edge->m_index;
  v5 = edge->m_triangle->m_vertices[v4];
  v6 = 0;
  v7 = ring;
  v8 = edge;
  v9 = edge->m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v4) & 3];
  v10 = ring->m_capacityAndFlags;
  ring->m_size = 0;
  v11 = v10 & 0x3FFFFFFF;
  v12 = v5->m_numRefs + v9->m_numRefs;
  if ( v11 < v12 )
  {
    v13 = 2 * v11;
    if ( v12 < v13 )
      v12 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, ring, v12, 8);
  }
  v29 = *(__m128i *)v8;
  v14 = v5->m_numRefs == hkgpIndexedMesh::getReachableRing(v3, (hkgpIndexedMeshDefinitions::Edge *)&v29, v7);
  v29.m128i_i64[0] = (__int64)v8->m_triangle;
  v15 = v14;
  v29.m128i_i32[2] = (9 >> 2 * v8->m_index) & 3;
  _mm_store_si128(&v29, v29);
  v16 = v9->m_numRefs == hkgpIndexedMesh::getReachableRing(v3, (hkgpIndexedMeshDefinitions::Edge *)&v29, v7);
  if ( !v15 || !v16 )
  {
    v17 = v3->m_triangles.m_used;
    v18 = &result;
    if ( !v17 )
      v18 = 0i64;
    if ( v18 )
    {
      do
      {
        v19 = v17->m_vertices[0];
        if ( v19 == v5
          || v19 == v9
          || (v20 = v17->m_vertices[1], v20 == v5)
          || v20 == v9
          || (v21 = v17->m_vertices[2], v21 == v5)
          || v21 == v9 )
        {
          if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8);
          v7->m_data[v7->m_size++] = v17;
        }
        v17 = v17->m_next;
        v22 = &result;
        if ( !v17 )
          v22 = 0i64;
      }
      while ( v22 );
    }
  }
  v23 = v7->m_size;
  if ( v23 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpIndexedMeshDefinitions::Triangle *,hkgpIndexedMeshInternals::TriangleSortLess>(
      v7->m_data,
      0,
      v23 - 1,
      (hkgpIndexedMeshInternals::TriangleSortLess)result.m_enum);
  if ( v7->m_size - 1 > 0 )
  {
    v24 = 0i64;
    do
    {
      v25 = &v7->m_data[v24];
      if ( *v25 == v25[1] )
      {
        v26 = 8 * (--v7->m_size - v6);
        if ( v26 > 0 )
        {
          v27 = ((unsigned int)(v26 - 1) >> 3) + 1;
          do
          {
            v28 = v25[1];
            ++v25;
            *(v25 - 1) = v28;
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
    while ( v6 < v7->m_size - 1 );
  }
}

// File Line: 392
// RVA: 0xCE2D50
__int64 __fastcall hkgpIndexedMesh::getReachableRing(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Edge *edge, hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *ring)
{
  hkgpIndexedMeshDefinitions::Triangle *v3; // rsi
  __int64 v4; // rbp
  hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *v5; // rbx
  unsigned int v6; // edi
  __int64 v7; // rdx
  char v8; // cl
  int v9; // er9
  __int64 v10; // rcx
  unsigned int v11; // eax
  unsigned __int64 v12; // rcx
  __int64 v13; // rdx
  signed __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rax
  char v17; // cl
  __int64 v18; // r8
  __m128i v20; // [rsp+20h] [rbp-28h]
  __m128i v21; // [rsp+30h] [rbp-18h]

  v3 = edge->m_triangle;
  v4 = (signed int)edge->m_index;
  v5 = ring;
  v20.m128i_i64[0] = (__int64)edge->m_triangle;
  v20.m128i_i32[2] = v4;
  v6 = 0;
  _mm_store_si128(&v20, v20);
  while ( 1 )
  {
    ++v6;
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    v7 = v20.m128i_i64[0];
    v5->m_data[v5->m_size] = (hkgpIndexedMeshDefinitions::Triangle *)v20.m128i_i64[0];
    v8 = v20.m128i_i8[8];
    v9 = ++v5->m_size;
    v10 = *(_QWORD *)(v7 + 8i64 * ((18 >> 2 * v8) & 3) + 40);
    v11 = v10 & 3;
    v12 = v10 & 0xFFFFFFFFFFFFFFFCui64;
    v21.m128i_i64[0] = v12;
    v21.m128i_i32[2] = v11;
    _mm_store_si128(&v20, v21);
    if ( !v12 )
      break;
    if ( (hkgpIndexedMeshDefinitions::Triangle *)(v12 + v11) == (hkgpIndexedMeshDefinitions::Triangle *)((char *)v3 + (unsigned int)v4) )
      return v6;
  }
  v14 = v3->m_links[v4] & 3;
  v21.m128i_i64[0] = v3->m_links[v4] & 0xFFFFFFFFFFFFFFFCui64;
  v13 = v21.m128i_i64[0];
  v21.m128i_i32[2] = (9 >> 2 * v14) & 3;
  _mm_store_si128(&v20, v21);
  if ( v13 )
  {
    do
    {
      ++v6;
      if ( v9 == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
      v15 = v20.m128i_i64[0];
      v5->m_data[v5->m_size] = (hkgpIndexedMeshDefinitions::Triangle *)v20.m128i_i64[0];
      v16 = v20.m128i_i32[2];
      v9 = ++v5->m_size;
      v17 = *(_QWORD *)(v15 + 8 * v16 + 40);
      v21.m128i_i64[0] = *(_QWORD *)(v15 + 8 * v16 + 40) & 0xFFFFFFFFFFFFFFFCui64;
      v18 = v21.m128i_i64[0];
      v21.m128i_i32[2] = (9 >> 2 * (v17 & 3)) & 3;
      _mm_store_si128(&v20, v21);
    }
    while ( v18 );
  }
  return v6;
}

// File Line: 399
// RVA: 0xCE2EE0
void __fastcall hkgpIndexedMesh::removeTriangle(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Triangle *triangle, hkgpIndexedMesh::ITriangleRemoval *itrf)
{
  hkgpIndexedMesh::ITriangleRemoval *v3; // r14
  hkgpIndexedMeshDefinitions::Triangle *v4; // r15
  hkgpIndexedMesh *v5; // rdi
  hkgpIndexedMeshDefinitions::Vertex ***v6; // rbx
  unsigned __int64 *v7; // rsi
  signed __int64 v8; // rbp
  hkgpIndexedMeshDefinitions::Vertex *v9; // rax
  hkgpIndexedMeshDefinitions::Vertex **v10; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v11; // rax
  hkgpIndexedMeshDefinitions::Vertex *v12; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v13; // rdx
  bool v14; // zf
  hkgpIndexedMeshDefinitions::Vertex *v15; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *v16; // rax
  unsigned __int64 v17; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v18; // rax
  hkgpIndexedMeshDefinitions::Triangle *v19; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v20; // rdx
  __int64 v21; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>::Pool *v22; // rax
  __int64 v23; // r8

  v3 = itrf;
  v4 = triangle;
  v5 = this;
  if ( itrf )
    ((void (__fastcall *)(hkgpIndexedMesh::ITriangleRemoval *))itrf->vfptr[1].__vecDelDtor)(itrf);
  v6 = (hkgpIndexedMeshDefinitions::Vertex ***)v4->m_vertices;
  v7 = v4->m_links;
  v8 = 3i64;
  do
  {
    if ( *v7 & 0xFFFFFFFFFFFFFFFCui64 )
      *(_QWORD *)((*v7 & 0xFFFFFFFFFFFFFFFCui64) + 8 * (*v7 & 3) + 40) = 0i64;
    *v7 = 0i64;
    v9 = (hkgpIndexedMeshDefinitions::Vertex *)*v6;
    if ( !--v9->m_numRefs )
    {
      if ( v3 )
        v3->vfptr->removeVertex(
          (hkgpIndexedMesh::IVertexRemoval *)&v3->vfptr,
          (hkgpIndexedMeshDefinitions::Vertex *)*v6);
      v10 = *v6;
      v11 = **v6;
      v12 = (*v6)[1];
      if ( v11 )
        v11->m_prev = v12;
      if ( v12 )
        v12->m_next = v11;
      else
        v5->m_vertices.m_used = v11;
      --v5->m_vertices.m_numUsed;
      v13 = v10[4];
      v14 = v13[48].m_lidx-- == 1;
      if ( v14 )
      {
        v15 = v13[48].m_prev;
        v16 = (hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Vertex,32,hkContainerHeapAllocator>::Pool *)v13[48].m_index;
        if ( v15 )
          v15[48].m_index = (unsigned __int64)v16;
        else
          v5->m_vertices.m_allocator.m_firstPool = v16;
        v17 = v13[48].m_index;
        if ( v17 )
          *(_QWORD *)(v17 + 1544) = v13[48].m_prev;
        hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v13,
          1568);
      }
    }
    ++v7;
    ++v6;
    --v8;
  }
  while ( v8 );
  v18 = v4->m_next;
  v19 = v4->m_prev;
  if ( v4->m_next )
    v18->m_prev = v19;
  if ( v19 )
    v19->m_next = v18;
  else
    v5->m_triangles.m_used = v18;
  --v5->m_triangles.m_numUsed;
  v20 = v4[1].m_prev;
  v14 = LODWORD(v20[41].m_next)-- == 1;
  if ( v14 )
  {
    v21 = *(_QWORD *)&v20[40].m_set;
    v22 = *(hkGeometryProcessing::PoolAllocator<hkgpIndexedMeshDefinitions::Triangle,32,hkContainerHeapAllocator>::Pool **)&v20[40].m_flags;
    if ( v21 )
      *(_QWORD *)(v21 + 3600) = v22;
    else
      v5->m_triangles.m_allocator.m_firstPool = v22;
    v23 = *(_QWORD *)&v20[40].m_flags;
    if ( v23 )
      *(_QWORD *)(v23 + 3592) = *(_QWORD *)&v20[40].m_set;
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v20,
      3616);
  }
}

// File Line: 415
// RVA: 0xCE30B0
void __fastcall hkgpIndexedMesh::growStrip(hkgpIndexedMesh *this, hkgpIndexedMeshDefinitions::Edge *root, hkArray<hkgpIndexedMeshDefinitions::Edge,hkContainerHeapAllocator> *strip, hkgpIndexedMesh::StripConfig *config)
{
  bool v4; // zf
  hkgpIndexedMesh::StripConfig *v5; // rsi
  int v6; // ebp
  hkArray<hkgpIndexedMeshDefinitions::Edge,hkContainerHeapAllocator> *v7; // rbx
  hkgpIndexedMeshDefinitions::Edge *v8; // rdi
  hkgpIndexedMeshDefinitions::Edge *v9; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v10; // r8
  int v11; // ecx
  unsigned __int64 v12; // rcx
  __int64 v13; // rax
  hkgpIndexedMeshDefinitions::Triangle *v14; // rax
  hkgpIndexedMeshDefinitions::Edge *v15; // rcx
  __int64 v16; // [rsp+28h] [rbp-20h]
  __int64 v17; // [rsp+38h] [rbp-10h]

  v4 = (strip->m_capacityAndFlags & 0x3FFFFFFF) == 0;
  v5 = config;
  v6 = root->m_triangle->m_material;
  v7 = strip;
  v8 = root;
  strip->m_size = 0;
  if ( v4 )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, strip, 16);
  v9 = &v7->m_data[v7->m_size];
  if ( v9 )
  {
    v9->m_triangle = v8->m_triangle;
    *(_QWORD *)&v9->m_index = *(_QWORD *)&v8->m_index;
  }
  ++v7->m_size;
  for ( v8->m_triangle->m_flags |= 0x10u; v7->m_size + 2 < v5->m_maxLength; v8->m_triangle->m_flags |= 0x10u )
  {
    v10 = v8->m_triangle;
    v11 = 2 * v8->m_index;
    if ( v7->m_size & 1 )
    {
      v12 = v10->m_links[(9 >> v11) & 3];
      LODWORD(v16) = v12 & 3;
      v13 = v16;
    }
    else
    {
      v12 = v10->m_links[(18 >> v11) & 3];
      LODWORD(v17) = v12 & 3;
      v13 = v17;
    }
    v8->m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)(v12 & 0xFFFFFFFFFFFFFFFCui64);
    *(_QWORD *)&v8->m_index = v13;
    v14 = v8->m_triangle;
    if ( !v8->m_triangle || v14->m_flags & 0x10 || v14->m_material != v6 )
      break;
    if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
    v15 = &v7->m_data[v7->m_size];
    if ( v15 )
    {
      v15->m_triangle = v8->m_triangle;
      *(_QWORD *)&v15->m_index = *(_QWORD *)&v8->m_index;
    }
    ++v7->m_size;
  }
}

// File Line: 435
// RVA: 0xCE3210
void __fastcall hkgpIndexedMesh::generateStrips(hkgpIndexedMesh *this, hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *strips, hkArray<int,hkContainerHeapAllocator> *leftOvers, hkArray<int,hkContainerHeapAllocator> *map, hkgpIndexedMesh::StripConfig *config)
{
  int v5; // eax
  hkArray<int,hkContainerHeapAllocator> *v6; // r12
  hkArray<int,hkContainerHeapAllocator> *v7; // rsi
  hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v8; // r14
  hkgpIndexedMesh *v9; // r15
  __int64 v10; // rdi
  int *v11; // rbx
  int v12; // er8
  int v13; // er8
  int v14; // er8
  int v15; // er9
  hkgpIndexedMeshDefinitions::Triangle *i; // rdx
  hkgpIndexedMesh::StripConfig *v17; // rsi
  int v18; // edi
  __m128i v19; // xmm7
  int v20; // er14
  __int64 v21; // r9
  __int64 v22; // r15
  __int64 v23; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v24; // rsi
  signed int v25; // ebx
  __m128i v26; // xmm6
  int v27; // er8
  int v28; // er9
  __int64 v29; // rax
  hkResultEnum v30; // er13
  int v31; // eax
  int v32; // eax
  __int64 v33; // rdx
  __int64 v34; // rax
  signed __int64 v35; // rax
  __int64 v36; // rax
  hkArray<int,hkContainerHeapAllocator> *v37; // rbx
  int v38; // edi
  int v39; // esi
  int v40; // eax
  __int64 v41; // rdi
  __int64 v42; // rcx
  int v43; // er14
  int v44; // er14
  int v45; // edi
  int v46; // edi
  __int64 v47; // rbx
  int v48; // esi
  int v49; // esi
  int v50; // esi
  int v51; // esi
  hkResult result; // [rsp+30h] [rbp-81h]
  hkgpIndexedMeshDefinitions::Triangle **array; // [rsp+38h] [rbp-79h]
  int v54; // [rsp+40h] [rbp-71h]
  int v55; // [rsp+44h] [rbp-6Dh]
  _QWORD *v56; // [rsp+48h] [rbp-69h]
  int v57; // [rsp+50h] [rbp-61h]
  int v58; // [rsp+54h] [rbp-5Dh]
  __m128i v59; // [rsp+60h] [rbp-51h]
  __int128 v60; // [rsp+70h] [rbp-41h]
  __int128 v61; // [rsp+80h] [rbp-31h]
  __int128 v62; // [rsp+90h] [rbp-21h]
  hkgpIndexedMesh *v63; // [rsp+110h] [rbp+5Fh]
  hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v64; // [rsp+118h] [rbp+67h]
  hkArray<int,hkContainerHeapAllocator> *v65; // [rsp+120h] [rbp+6Fh]
  hkArray<int,hkContainerHeapAllocator> *v66; // [rsp+128h] [rbp+77h]

  v66 = map;
  v65 = leftOvers;
  v64 = strips;
  v63 = this;
  v5 = strips->m_size - 1;
  v6 = map;
  v7 = leftOvers;
  v8 = strips;
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v11 - 3),
          4 * v12);
      *(_QWORD *)(v11 - 3) = 0i64;
      *v11 = 2147483648;
      v11 -= 4;
      --v10;
    }
    while ( v10 >= 0 );
  }
  v13 = v8->m_capacityAndFlags;
  v8->m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v8->m_data,
      16 * v13);
  v8->m_data = 0i64;
  v8->m_capacityAndFlags = 2147483648;
  v14 = v7->m_capacityAndFlags;
  v7->m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v7->m_data,
      4 * v14);
  v7->m_data = 0i64;
  v7->m_capacityAndFlags = 2147483648;
  v15 = v9->m_triangles.m_numUsed;
  if ( v15 )
  {
    array = 0i64;
    v54 = 0;
    v55 = 2147483648;
    if ( v15 > 0 )
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 8);
    for ( i = v9->m_triangles.m_used; i; i = i->m_next )
    {
      i->m_flags &= 0xFFFFFFEF;
      array[v54++] = i;
    }
    if ( v54 > 1 )
      hkAlgorithm::quickSortRecursive<hkgpIndexedMeshDefinitions::Triangle *,hkgpIndexedMesh::SortByAscendingReferences>(
        array,
        0,
        v54 - 1,
        0);
    v56 = 0i64;
    v57 = 0;
    v58 = 2147483648;
    while ( 1 )
    {
      v17 = config;
      v18 = config->m_minLength;
      if ( !(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' & 1) )
      {
        *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e = 0i64;
        DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e) = 0;
        `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::`local static guard' |= 1u;
      }
      v19 = (__m128i)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
      v20 = 0;
      result.m_enum = 0;
      v60 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
      v21 = `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null'::`2'::e;
      if ( v54 > 0 )
      {
        v22 = 0i64;
        while ( 1 )
        {
          v23 = (__int64)&array[v22];
          v24 = array[v22];
          if ( v24->m_flags & 0x10 )
          {
            v31 = v54 - 1;
            v54 = v31;
            v32 = 8 * (v31 - v20);
            if ( v32 > 0 )
            {
              v33 = ((unsigned int)(v32 - 1) >> 3) + 1;
              do
              {
                v34 = *(_QWORD *)(v23 + 8);
                v23 += 8i64;
                *(_QWORD *)(v23 - 8) = v34;
                --v33;
              }
              while ( v33 );
            }
            v17 = config;
            --v20;
            --v22;
          }
          else
          {
            v25 = 0;
            do
            {
              v59.m128i_i64[0] = (__int64)v24;
              v59.m128i_i32[2] = v25;
              v26 = v59;
              _mm_store_si128((__m128i *)&v61, v59);
              hkgpIndexedMesh::growStrip(
                v63,
                (hkgpIndexedMeshDefinitions::Edge *)&v61,
                (hkArray<hkgpIndexedMeshDefinitions::Edge,hkContainerHeapAllocator> *)&v56,
                config);
              v27 = 0;
              v28 = v57 + 2;
              if ( v57 > 0 )
              {
                v29 = 0i64;
                do
                {
                  ++v27;
                  v29 += 2i64;
                  *(_DWORD *)(v56[v29 - 2] + 80i64) &= 0xFFFFFFEF;
                }
                while ( v27 < v57 );
              }
              if ( v28 >= v18 )
              {
                v18 = v28;
                v19 = v26;
              }
              ++v25;
            }
            while ( v25 < 3 );
            v6 = v66;
            v30 = result.m_enum;
            v17 = config;
            v21 = v19.m128i_i64[0];
            if ( v19.m128i_i64[0] )
            {
              ++result.m_enum;
              if ( v30 + 1 > config->m_searchPasses )
              {
LABEL_38:
                v9 = v63;
                break;
              }
            }
          }
          ++v20;
          ++v22;
          if ( v20 >= v54 )
            goto LABEL_38;
        }
      }
      if ( !v21 )
        break;
      if ( v64->m_size == (v64->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v64, 16);
      v35 = (signed __int64)&v64->m_data[v64->m_size];
      if ( v35 )
      {
        *(_QWORD *)v35 = 0i64;
        *(_DWORD *)(v35 + 8) = 0;
        *(_DWORD *)(v35 + 12) = 2147483648;
      }
      v36 = v64->m_size;
      _mm_store_si128((__m128i *)&v62, v19);
      v37 = &v64->m_data[v36];
      v64->m_size = v36 + 1;
      hkgpIndexedMesh::growStrip(
        v9,
        (hkgpIndexedMeshDefinitions::Edge *)&v62,
        (hkArray<hkgpIndexedMeshDefinitions::Edge,hkContainerHeapAllocator> *)&v56,
        v17);
      v38 = *(_DWORD *)(*(_QWORD *)(*v56 + 8i64 * *((signed int *)v56 + 2) + 16) + 16i64);
      if ( v37->m_size == (v37->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v37, 4);
      v39 = 0;
      v37->m_data[v37->m_size++] = v38;
      v40 = v57;
      if ( v57 > 0 )
      {
        v41 = 0i64;
        do
        {
          if ( v39 & 1 )
            v42 = *(_QWORD *)(v56[v41] + 8i64 * SLODWORD(v56[v41 + 1]) + 16);
          else
            v42 = *(_QWORD *)(v56[v41] + 8 * ((9i64 >> 2 * (unsigned __int8)LODWORD(v56[v41 + 1])) & 3) + 16);
          v43 = *(_DWORD *)(v42 + 16);
          if ( v37->m_size == (v37->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v37, 4);
          v37->m_data[v37->m_size++] = v43;
          v44 = *(_DWORD *)(v56[v41] + 64i64);
          if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
          ++v39;
          v6->m_data[v6->m_size] = v44;
          v40 = v57;
          ++v6->m_size;
          v41 += 2i64;
        }
        while ( v39 < v40 );
      }
      v45 = *(_DWORD *)(*(_QWORD *)(v56[2 * (v40 - 1)]
                                  + 8 * ((18i64 >> 2 * (unsigned __int8)LODWORD(v56[2 * (v40 - 1) + 1])) & 3)
                                  + 16)
                      + 16i64);
      if ( v37->m_size == (v37->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v37, 4);
      v37->m_data[v37->m_size++] = v45;
    }
    v46 = 0;
    if ( v54 > 0 )
    {
      v47 = 0i64;
      do
      {
        v48 = array[v47]->m_vertices[0]->m_index;
        if ( v65->m_size == (v65->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v65, 4);
        v65->m_data[v65->m_size++] = v48;
        v49 = array[v47]->m_vertices[1]->m_index;
        if ( v65->m_size == (v65->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v65, 4);
        v65->m_data[v65->m_size++] = v49;
        v50 = array[v47]->m_vertices[2]->m_index;
        if ( v65->m_size == (v65->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v65, 4);
        v65->m_data[v65->m_size++] = v50;
        v51 = array[v47]->m_index;
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
        ++v46;
        v6->m_data[v6->m_size++] = v51;
        ++v47;
      }
      while ( v46 < v54 );
    }
    v57 = 0;
    if ( v58 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v56,
        16 * v58);
    v56 = 0i64;
    v58 = 2147483648;
    v54 = 0;
    if ( v55 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v55);
  }
}MemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v55);
  }
}

// File Line: 514
// RVA: 0xCE38F0
void __fastcall hkgpIndexedMesh::computeSets(hkgpIndexedMesh *this, hkgpIndexedMesh::EdgeBarrier *barriers)
{
  hkArray<hkgpIndexedMesh::SetInfos,hkContainerHeapAllocator> *v2; // r15
  hkgpIndexedMesh::EdgeBarrier *v3; // r12
  hkgpIndexedMesh::SetInfos *v4; // r8
  hkgpIndexedMesh *v5; // rsi
  int v6; // eax
  __int64 v7; // rdi
  int *v8; // rbx
  int v9; // er8
  hkgpIndexedMeshDefinitions::Triangle *v10; // rax
  char *v11; // rcx
  char *v12; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v13; // rbx
  char *v14; // rax
  int v15; // eax
  int v16; // er13
  signed __int64 v17; // rax
  _QWORD *v18; // rdx
  __int64 v19; // r15
  signed int v20; // esi
  signed int v21; // edi
  signed __int64 v22; // r14
  hkgpIndexedMesh::EdgeBarrierVtbl *v23; // rax
  int v24; // ecx
  unsigned __int64 v25; // r14
  char *v26; // rax
  hkgpIndexedMeshDefinitions::Triangle *v27; // rdx
  unsigned __int64 v28; // r8
  unsigned __int64 v29; // r9
  __int64 v30; // rsi
  __int128 *v31; // rax
  unsigned __int64 v32; // r14
  __int64 v33; // r8
  signed __int64 v34; // rcx
  int v35; // edx
  signed __int64 v36; // rbx
  __int64 v37; // rcx
  hkgpIndexedMesh::SetInfos *v38; // rbx
  hkgpIndexedMesh::SetInfos *v39; // rdi
  __int64 v40; // r10
  int *v41; // rax
  __int64 v42; // r10
  int v43; // edx
  __int64 v44; // rcx
  int *v45; // rax
  __int128 *v46; // rax
  __int128 array; // [rsp+20h] [rbp-30h]
  __m128i v48; // [rsp+30h] [rbp-20h]
  __int128 v49; // [rsp+40h] [rbp-10h]
  hkgpIndexedMesh *v50; // [rsp+90h] [rbp+40h]
  char v51; // [rsp+A0h] [rbp+50h]
  hkArray<hkgpIndexedMesh::SetInfos,hkContainerHeapAllocator> *v52; // [rsp+A8h] [rbp+58h]

  v50 = this;
  v2 = &this->m_sets;
  v3 = barriers;
  v4 = this->m_sets.m_data;
  v5 = this;
  v6 = this->m_sets.m_size - 1;
  v52 = &this->m_sets;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = &v4->m_links.m_capacityAndFlags + 4 * v6;
    do
    {
      v9 = *v8;
      *(v8 - 1) = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v8 - 3),
          4 * v9);
      *(_QWORD *)(v8 - 3) = 0i64;
      *v8 = 2147483648;
      v8 -= 4;
      --v7;
    }
    while ( v7 >= 0 );
  }
  v2->m_size = 0;
  v10 = v5->m_triangles.m_used;
  v11 = &v51;
  if ( !v10 )
    v11 = 0i64;
  if ( v11 )
  {
    do
    {
      v10->m_set = -1;
      v10 = v10->m_next;
      v12 = &v51;
      if ( !v10 )
        v12 = 0i64;
    }
    while ( v12 );
  }
  v13 = v5->m_triangles.m_used;
  v14 = &v51;
  if ( !v13 )
    v14 = 0i64;
  if ( v14 )
  {
    do
    {
      if ( v13->m_set == -1 )
      {
        *(_QWORD *)&array = 0i64;
        *((_QWORD *)&array + 1) = 0x8000000000000000i64;
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        *(_QWORD *)(array + 8i64 * SDWORD2(array)) = v13;
        v15 = v2->m_capacityAndFlags;
        ++DWORD2(array);
        v16 = v5->m_sets.m_size;
        if ( v2->m_size == (v15 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 16);
        v17 = (signed __int64)&v2->m_data[v2->m_size];
        if ( v17 )
        {
          *(_QWORD *)v17 = 0i64;
          *(_DWORD *)(v17 + 8) = 0;
          *(_DWORD *)(v17 + 12) = 2147483648;
        }
        ++v2->m_size;
        v18 = (_QWORD *)array;
        do
        {
          v19 = v18[SDWORD2(array) - 1];
          --DWORD2(array);
          if ( *(_DWORD *)(v19 + 72) == -1 )
          {
            *(_DWORD *)(v19 + 72) = v16;
            v20 = 0;
            v21 = 1;
            do
            {
              if ( !(v21 & *(_DWORD *)(v19 + 80)) )
              {
                v22 = v19 + 8i64 * v20;
                if ( *(_QWORD *)(v22 + 40) & 0xFFFFFFFFFFFFFFFCui64 )
                {
                  v23 = v3->vfptr;
                  v48.m128i_i64[0] = v19;
                  v48.m128i_i32[2] = v20;
                  _mm_store_si128((__m128i *)&v49, v48);
                  if ( !((unsigned __int8 (__fastcall *)(hkgpIndexedMesh::EdgeBarrier *, __int128 *))v23->isBlocked)(
                          v3,
                          &v49) )
                  {
                    v24 = DWORD2(array);
                    v25 = *(_QWORD *)(v22 + 40) & 0xFFFFFFFFFFFFFFFCui64;
                    if ( DWORD2(array) == (HIDWORD(array) & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        8);
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
            v18 = (_QWORD *)array;
          }
        }
        while ( SDWORD2(array) > 0 );
        DWORD2(array) = 0;
        if ( array >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v18,
            8 * HIDWORD(array));
        v2 = v52;
        v5 = v50;
        *(_QWORD *)&array = 0i64;
        HIDWORD(array) = 2147483648;
      }
      v13 = v13->m_next;
      v26 = &v51;
      if ( !v13 )
        v26 = 0i64;
    }
    while ( v26 );
  }
  v27 = v5->m_triangles.m_used;
  v48.m128i_i32[2] = 0;
  v48.m128i_i64[0] = (__int64)v27;
  _mm_store_si128((__m128i *)&array, v48);
  if ( v27 )
  {
    v28 = v27->m_vertices[1]->m_index;
    v29 = v27->m_vertices[0]->m_index;
    if ( v29 >= v28 && (v29 > v28) > 0 && v27->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
      hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next((hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&array);
  }
  v30 = array;
  v31 = &array;
  if ( !(_QWORD)array )
    v31 = 0i64;
  if ( v31 )
  {
    do
    {
      v32 = *(_QWORD *)(v30 + 8i64 * SDWORD2(array) + 40) & 0xFFFFFFFFFFFFFFFCui64;
      if ( v32 )
      {
        v33 = *(signed int *)(v32 + 72);
        v34 = *(signed int *)(v30 + 72);
        if ( (_DWORD)v34 != (_DWORD)v33 && !((*(_BYTE *)(v32 + 80) | *(_BYTE *)(v30 + 80)) & 8) )
        {
          v35 = 0;
          v36 = v34;
          v37 = 0i64;
          v38 = &v2->m_data[v36];
          v39 = &v2->m_data[v33];
          v40 = v38->m_links.m_size;
          if ( (signed int)v40 <= 0 )
            goto LABEL_55;
          v41 = v38->m_links.m_data;
          while ( *v41 != (_DWORD)v33 )
          {
            ++v37;
            ++v35;
            ++v41;
            if ( v37 >= v40 )
              goto LABEL_55;
          }
          if ( v35 == -1 )
          {
LABEL_55:
            if ( (_DWORD)v40 == (v38->m_links.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v38, 4);
            v38->m_links.m_data[v38->m_links.m_size++] = *(_DWORD *)(v32 + 72);
          }
          v42 = v39->m_links.m_size;
          v43 = 0;
          v44 = 0i64;
          if ( (signed int)v42 <= 0 )
            goto LABEL_64;
          v45 = v39->m_links.m_data;
          while ( *v45 != *(_DWORD *)(v30 + 72) )
          {
            ++v44;
            ++v43;
            ++v45;
            if ( v44 >= v42 )
              goto LABEL_64;
          }
          if ( v43 == -1 )
          {
LABEL_64:
            if ( (_DWORD)v42 == (v39->m_links.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v39, 4);
            v39->m_links.m_data[v39->m_links.m_size++] = *(_DWORD *)(v30 + 72);
          }
        }
      }
      if ( v30 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next((hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *)&array);
        v30 = array;
      }
      v46 = &array;
      if ( !v30 )
        v46 = 0i64;
    }
    while ( v46 );
  }
}

// File Line: 571
// RVA: 0xCE3D40
void __fastcall hkgpIndexedMesh::getSetVertices(hkgpIndexedMesh *this, int set, hkArray<hkgpIndexedMeshDefinitions::Vertex *,hkContainerHeapAllocator> *vertices)
{
  int v3; // er15
  hkgpIndexedMesh *v4; // rbx
  hkArray<hkgpIndexedMeshDefinitions::Vertex *,hkContainerHeapAllocator> *v5; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v6; // rbx
  char *v7; // rax
  unsigned __int64 *v8; // rsi
  signed __int64 v9; // rbp
  unsigned __int64 v10; // r14
  char *v11; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v12; // [rsp+20h] [rbp-38h]
  char v13; // [rsp+60h] [rbp+8h]

  v3 = set;
  v4 = this;
  v5 = vertices;
  v12.m_hashMod = -1;
  v12.m_elem = 0i64;
  v12.m_numElems = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v12,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    1024);
  v6 = v4->m_triangles.m_used;
  v7 = &v13;
  if ( !v6 )
    v7 = 0i64;
  if ( v7 )
  {
    do
    {
      if ( v6->m_set == v3 )
      {
        v8 = (unsigned __int64 *)v6->m_vertices;
        v9 = 3i64;
        do
        {
          v10 = *v8;
          if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                &v12,
                                *v8,
                                0i64) )
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
            v5->m_data[v5->m_size++] = (hkgpIndexedMeshDefinitions::Vertex *)v10;
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &v12,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v10,
              1ui64);
          }
          ++v8;
          --v9;
        }
        while ( v9 );
      }
      v6 = v6->m_next;
      v11 = &v13;
      if ( !v6 )
        v11 = 0i64;
    }
    while ( v11 );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v12,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v12);
}

// File Line: 592
// RVA: 0xCE3E90
void __fastcall hkgpIndexedMesh::getSetTriangles(hkgpIndexedMesh *this, int set, hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *triangles)
{
  hkgpIndexedMeshDefinitions::Triangle *v3; // rbx
  char *v4; // rax
  hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> *v5; // rdi
  int v6; // esi
  char *v7; // rax
  char v8; // [rsp+30h] [rbp+8h]

  v3 = this->m_triangles.m_used;
  v4 = &v8;
  v5 = triangles;
  v6 = set;
  if ( !v3 )
    v4 = 0i64;
  if ( v4 )
  {
    do
    {
      if ( v3->m_set == v6 )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
        v5->m_data[v5->m_size++] = v3;
      }
      v3 = v3->m_next;
      v7 = &v8;
      if ( !v3 )
        v7 = 0i64;
    }
    while ( v7 );
  }
}

// File Line: 601
// RVA: 0xCE3F30
void __fastcall hkgpIndexedMesh::deleteSetTriangles(hkgpIndexedMesh *this, int set)
{
  hkgpIndexedMesh *v2; // rsi
  int v3; // edi
  __int64 v4; // rbx
  hkArray<hkgpIndexedMeshDefinitions::Triangle *,hkContainerHeapAllocator> triangles; // [rsp+20h] [rbp-18h]

  triangles.m_data = 0i64;
  v2 = this;
  triangles.m_size = 0;
  triangles.m_capacityAndFlags = 2147483648;
  hkgpIndexedMesh::getSetTriangles(this, set, &triangles);
  v3 = 0;
  if ( triangles.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      hkgpIndexedMesh::removeTriangle(v2, triangles.m_data[v4], 0i64);
      ++v3;
      ++v4;
    }
    while ( v3 < triangles.m_size );
  }
  triangles.m_size = 0;
  if ( triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      triangles.m_data,
      8 * triangles.m_capacityAndFlags);
}

