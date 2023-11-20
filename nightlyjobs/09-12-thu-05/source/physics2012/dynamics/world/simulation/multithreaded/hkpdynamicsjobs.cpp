// File Line: 38
// RVA: 0xD986C0
signed __int64 __fastcall hkpBroadPhaseJob::popJobTask(hkpBroadPhaseJob *this, hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *islands, hkpBroadPhaseJob *out)
{
  hkpBuildJacobianTaskHeader *v3; // rdi
  int v4; // er9
  hkpWorld *v5; // rbx
  __int64 v6; // r14
  __int64 v7; // rsi
  hkpSimulationIsland *v8; // rbp
  int v9; // er8
  signed __int64 result; // rax
  unsigned __int16 v11; // ax

  v3 = this->m_taskHeader;
  if ( v3 && (v4 = v3->m_newSplitIslands.m_size) != 0 )
  {
    v3->m_referenceCount += v4;
    v3->m_numIslandsAfterSplit += v4;
    this->m_islandIndex = islands->m_size;
    this->m_numIslands = v4;
    v5 = out->m_island->m_world;
    if ( v4 > 0 )
    {
      v6 = (unsigned int)v4;
      v7 = 0i64;
      do
      {
        v8 = v3->m_newSplitIslands.m_data[v7];
        v8->m_storageIndex = v5->m_activeSimulationIslands.m_size;
        if ( v5->m_activeSimulationIslands.m_size == (v5->m_activeSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v5->m_activeSimulationIslands,
            8);
        ++v7;
        v5->m_activeSimulationIslands.m_data[v5->m_activeSimulationIslands.m_size++] = v8;
        --v6;
      }
      while ( v6 );
    }
    v9 = v3->m_newSplitIslands.m_capacityAndFlags;
    v3->m_newSplitIslands.m_size = 0;
    if ( v9 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_newSplitIslands.m_data,
        8 * v9);
    v3->m_newSplitIslands.m_data = 0i64;
    v3->m_newSplitIslands.m_capacityAndFlags = 2147483648;
    result = 1i64;
  }
  else
  {
    v11 = this->m_numIslands;
    if ( v11 <= 1u )
    {
      result = 0i64;
    }
    else
    {
      ++this->m_islandIndex;
      this->m_numIslands = v11 - 1;
      result = 1i64;
      out->m_numIslands = 1;
    }
  }
  return result;
}

