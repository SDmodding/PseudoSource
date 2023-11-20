// File Line: 101
// RVA: 0xCBF920
void __fastcall hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>::~PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,23,0>::Vertex,32,hkContainerHeapAllocator>(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *this)
{
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator> *v1; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v2; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v3; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v4; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>,-1,4,15,0>::Vertex,32,hkContainerHeapAllocator>::Pool *v5; // rcx

  v1 = this;
  while ( v1->m_firstPool )
  {
    v2 = v1->m_firstPool;
    v3 = v1->m_firstPool->m_links[0];
    v4 = v1->m_firstPool->m_links[1];
    if ( v3 )
      v3->m_links[1] = v4;
    else
      v1->m_firstPool = v4;
    v5 = v2->m_links[1];
    if ( v5 )
      v5->m_links[0] = v2->m_links[0];
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2,
      1568);
  }
}

// File Line: 127
// RVA: 0xCD87F0
hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *__fastcall hkGeometryProcessing::PoolAllocator<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiNavMeshGenTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiNavMeshGenTriangulatorEdgeData,hkContainerHeapAllocator>,-1,4,23,0>::Triangle,32,hkContainerHeapAllocator>::allocateNewPool(hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *this)
{
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator> *v1; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v2; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *result; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v4; // r8
  signed __int64 v5; // rax
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Item *v6; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *v7; // rax

  v1 = this;
  v2 = 0i64;
  result = (hkGeometryProcessing::PoolAllocator<hkgpMeshBase::Vertex,32,hkContainerHeapAllocator>::Pool *)(*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, signed __int64))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor + 1))(&hkContainerHeapAllocator::s_alloc, 3616i64);
  v4 = result;
  if ( result )
  {
    v5 = 31i64;
    v6 = &v4->m_items[31];
    do
    {
      *(_QWORD *)v6->m_data = v2;
      v2 = v6;
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
    v4->m_used = 0;
    v4->m_free = v2;
    v4->m_links[0] = 0i64;
    v4->m_links[1] = v1->m_firstPool;
    v1->m_firstPool = v4;
    v7 = v4->m_links[1];
    if ( v7 )
      v7->m_links[0] = v4;
    result = v4;
  }
  return result;
}

// File Line: 169
// RVA: 0xCDFD50
void __fastcall hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::release(hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator> *this, hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *object)
{
  int v2; // er8
  hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator> *v3; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator> *v4; // rdi
  unsigned __int64 *v5; // rdx
  bool v6; // zf
  unsigned __int64 v7; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v8; // rax
  unsigned __int64 v9; // r8

  if ( object )
  {
    v2 = object->m_tags.m_capacityAndFlags;
    v3 = object;
    v4 = this;
    object->m_tags.m_size = 0;
    if ( v2 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        object->m_tags.m_data,
        8 * v2);
    v3->m_tags.m_data = 0i64;
    v3->m_tags.m_capacityAndFlags = 2147483648;
    v5 = v3[1].m_tags.m_data;
    v6 = (*((_DWORD *)v5 + 390))-- == 1;
    if ( v6 )
    {
      v7 = v5[193];
      v8 = (hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *)v5[194];
      if ( v7 )
        *(_QWORD *)(v7 + 1552) = v8;
      else
        v4->m_firstPool = v8;
      v9 = v5[194];
      if ( v9 )
        *(_QWORD *)(v9 + 1544) = v5[193];
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v5,
        1568);
    }
  }
}

