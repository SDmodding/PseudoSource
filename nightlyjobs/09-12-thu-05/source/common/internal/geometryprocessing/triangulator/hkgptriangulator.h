// File Line: 162
// RVA: 0xCDFF30
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::reset(hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this)
{
  hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *v1; // rbx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v2; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v3; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v4; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v5; // rcx
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *v6; // rcx
  int v7; // er8
  __int64 v8; // rdx

  v1 = this;
  while ( v1->m_edgeDataAllocator.m_firstPool )
  {
    v2 = v1->m_edgeDataAllocator.m_firstPool;
    v3 = v2->m_links[0];
    v4 = v2->m_links[1];
    if ( v3 )
      v3->m_links[1] = v4;
    else
      v1->m_edgeDataAllocator.m_firstPool = v4;
    v5 = v2->m_links[1];
    if ( v5 )
      v5->m_links[0] = v2->m_links[0];
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2,
      1568);
  }
  v6 = v1->m_edgeData;
  if ( v1->m_edgeData )
  {
    v7 = 0;
    if ( v6->m_buckets.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        ++v7;
        ++v8;
        *((_DWORD *)&v6->m_buckets.m_data[v8] - 2) = 0;
      }
      while ( v7 < v6->m_buckets.m_size );
    }
    v6->m_numItems = 0;
  }
}

