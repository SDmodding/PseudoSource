// File Line: 38
// RVA: 0xD986C0
__int64 __fastcall hkpBroadPhaseJob::popJobTask(
        hkpBroadPhaseJob *this,
        hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *islands,
        hkpBroadPhaseJob *out)
{
  hkpBuildJacobianTaskHeader *m_taskHeader; // rdi
  int m_size; // r9d
  hkpWorld *m_world; // rbx
  __int64 v6; // r14
  __int64 v7; // rsi
  hkpSimulationIsland *v8; // rbp
  int m_capacityAndFlags; // r8d
  __int64 result; // rax
  unsigned __int16 m_numIslands; // ax

  m_taskHeader = this->m_taskHeader;
  if ( m_taskHeader && (m_size = m_taskHeader->m_newSplitIslands.m_size) != 0 )
  {
    m_taskHeader->m_referenceCount += m_size;
    m_taskHeader->m_numIslandsAfterSplit += m_size;
    this->m_islandIndex = islands->m_size;
    this->m_numIslands = m_size;
    m_world = out->m_island->m_world;
    if ( m_size > 0 )
    {
      v6 = (unsigned int)m_size;
      v7 = 0i64;
      do
      {
        v8 = m_taskHeader->m_newSplitIslands.m_data[v7];
        v8->m_storageIndex = m_world->m_activeSimulationIslands.m_size;
        if ( m_world->m_activeSimulationIslands.m_size == (m_world->m_activeSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&m_world->m_activeSimulationIslands.m_data,
            8);
        ++v7;
        m_world->m_activeSimulationIslands.m_data[m_world->m_activeSimulationIslands.m_size++] = v8;
        --v6;
      }
      while ( v6 );
    }
    m_capacityAndFlags = m_taskHeader->m_newSplitIslands.m_capacityAndFlags;
    m_taskHeader->m_newSplitIslands.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        m_taskHeader->m_newSplitIslands.m_data,
        8 * m_capacityAndFlags);
    m_taskHeader->m_newSplitIslands.m_data = 0i64;
    m_taskHeader->m_newSplitIslands.m_capacityAndFlags = 0x80000000;
    return 1i64;
  }
  else
  {
    m_numIslands = this->m_numIslands;
    if ( m_numIslands <= 1u )
    {
      return 0i64;
    }
    else
    {
      ++this->m_islandIndex;
      this->m_numIslands = m_numIslands - 1;
      result = 1i64;
      out->m_numIslands = 1;
    }
  }
  return result;
}

