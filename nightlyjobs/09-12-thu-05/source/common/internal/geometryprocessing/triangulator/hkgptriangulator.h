// File Line: 162
// RVA: 0xCDFF30
void __fastcall hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::reset(
        hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator> *this)
{
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rdx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v3; // rcx
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v4; // rax
  hkGeometryProcessing::PoolAllocator<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,32,hkContainerHeapAllocator>::Pool *v5; // rcx
  hkGeometryProcessing::HashTable<hkgpTriangulatorBase::SparseEdgeDataPolicy<hkgpTriangulatorBase::DefaultEdgeData<hkContainerHeapAllocator>,hkContainerHeapAllocator>::EdgeDataBox,hkContainerHeapAllocator> *m_edgeData; // rcx
  int v7; // r8d
  __int64 v8; // rdx

  while ( this->m_edgeDataAllocator.m_firstPool )
  {
    m_firstPool = this->m_edgeDataAllocator.m_firstPool;
    v3 = m_firstPool->m_links[0];
    v4 = m_firstPool->m_links[1];
    if ( v3 )
      v3->m_links[1] = v4;
    else
      this->m_edgeDataAllocator.m_firstPool = v4;
    v5 = m_firstPool->m_links[1];
    if ( v5 )
      v5->m_links[0] = m_firstPool->m_links[0];
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m_firstPool, 1568);
  }
  m_edgeData = this->m_edgeData;
  if ( this->m_edgeData )
  {
    v7 = 0;
    if ( m_edgeData->m_buckets.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        ++v7;
        m_edgeData->m_buckets.m_data[v8++].m_size = 0;
      }
      while ( v7 < m_edgeData->m_buckets.m_size );
    }
    m_edgeData->m_numItems = 0;
  }
}

