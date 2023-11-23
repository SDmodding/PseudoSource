// File Line: 24
// RVA: 0xD82ED0
void __fastcall hkpWorldMemoryUtil::watchHeapMemory(hkpWorld *world)
{
  hkWorldMemoryAvailableWatchDog *MemoryWatchDog; // rax
  int v3; // ebx
  hkMemorySystem *Instance; // rax
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkWorldMemoryAvailableWatchDog *v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  if ( hkpWorld::getMemoryWatchDog(world) )
  {
    MemoryWatchDog = hkpWorld::getMemoryWatchDog(world);
    v3 = ((__int64 (__fastcall *)(hkWorldMemoryAvailableWatchDog *))MemoryWatchDog->vfptr[1].__first_virtual_table_function__)(MemoryWatchDog);
    Instance = hkMemorySystem::getInstance();
    if ( !Instance->vfptr->heapCanAllocTotal(Instance, v3) )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v6 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v6 < Value[3] )
      {
        *v6 = "TtWatchDog:FreeMem";
        v7 = __rdtsc();
        v8 = v6 + 2;
        *((_DWORD *)v8 - 2) = v7;
        Value[1] = v8;
      }
      v9 = hkpWorld::getMemoryWatchDog(world);
      v9->vfptr[2].__vecDelDtor(v9, (unsigned int)world);
      v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v11 = (_QWORD *)v10[1];
      if ( (unsigned __int64)v11 < v10[3] )
      {
        *v11 = "Et";
        v12 = __rdtsc();
        v13 = v11 + 2;
        *((_DWORD *)v13 - 2) = v12;
        v10[1] = v13;
      }
    }
    if ( hkOutOfMemoryState )
      hkSetOutOfMemoryState(MEMORY_STATE_OK);
  }
}

// File Line: 44
// RVA: 0xD82FD0
void __fastcall hkpWorldMemoryUtil::checkMemoryForIntegration(hkpWorld *world)
{
  unsigned int m_minDesiredIslandSize; // r14d
  unsigned int v3; // ebp
  hkMemorySystem *Instance; // rax
  hkpSimulationIsland *m_largestSimulationIsland; // rax
  int m_maxRuntimeBlockSize; // esi
  hkpSimulationIsland *v7; // rdi
  bool v8; // zf
  hkMemorySystem *v9; // rax
  hkpSimulationIsland *v10; // rdi
  hkWorldMemoryAvailableWatchDog *MemoryWatchDog; // rax
  hkMemorySystem *v12; // rax
  hkWorldMemoryAvailableWatchDog::MemUsageInfo infoOut; // [rsp+20h] [rbp-18h] BYREF

  hkpWorld::lock(world);
  m_minDesiredIslandSize = world->m_minDesiredIslandSize;
  v3 = 0;
  hkpWorld::calcRequiredSolverBufferSize(world, &infoOut);
  Instance = hkMemorySystem::getInstance();
  if ( !Instance->vfptr->solverCanAllocSingleBlock(Instance, infoOut.m_maxRuntimeBlockSize) )
  {
    do
    {
      m_largestSimulationIsland = infoOut.m_largestSimulationIsland;
      ++v3;
      if ( ((*((_BYTE *)infoOut.m_largestSimulationIsland + 49) >> 2) & 3) != 0 )
      {
        do
        {
          m_maxRuntimeBlockSize = infoOut.m_maxRuntimeBlockSize;
          v7 = m_largestSimulationIsland;
          while ( 1 )
          {
            v8 = world->m_minDesiredIslandSize == 0;
            if ( !world->m_minDesiredIslandSize )
              break;
            hkpWorldOperationUtil::splitSimulationIsland((hkArray<hkpEntity *,hkContainerHeapAllocator> *)world, v7);
            hkpWorld::calcRequiredSolverBufferSize(world, &infoOut);
            m_largestSimulationIsland = infoOut.m_largestSimulationIsland;
            if ( infoOut.m_largestSimulationIsland == v7 && infoOut.m_maxRuntimeBlockSize == m_maxRuntimeBlockSize )
            {
              world->m_minDesiredIslandSize >>= 1;
              if ( (*((_BYTE *)m_largestSimulationIsland + 49) & 0xC) != 0 )
                continue;
            }
            v8 = world->m_minDesiredIslandSize == 0;
            break;
          }
        }
        while ( !v8 && ((*((_BYTE *)m_largestSimulationIsland + 49) >> 2) & 3) != 0 );
      }
      v9 = hkMemorySystem::getInstance();
      if ( !v9->vfptr->solverCanAllocSingleBlock(v9, infoOut.m_maxRuntimeBlockSize) )
      {
        v10 = infoOut.m_largestSimulationIsland;
        if ( hkpSimulationIsland::isFullyConnected(infoOut.m_largestSimulationIsland) || !world->m_minDesiredIslandSize )
        {
          MemoryWatchDog = hkpWorld::getMemoryWatchDog(world);
          ((void (__fastcall *)(hkWorldMemoryAvailableWatchDog *, hkWorldMemoryAvailableWatchDog::MemUsageInfo *, _QWORD))MemoryWatchDog->vfptr[2].__first_virtual_table_function__)(
            MemoryWatchDog,
            &infoOut,
            v3);
          hkpWorld::calcRequiredSolverBufferSize(world, &infoOut);
        }
        else
        {
          *((_BYTE *)v10 + 49) &= ~8u;
          *((_BYTE *)v10 + 49) |= 4u;
        }
      }
      v12 = hkMemorySystem::getInstance();
    }
    while ( !v12->vfptr->solverCanAllocSingleBlock(v12, infoOut.m_maxRuntimeBlockSize) );
  }
  world->m_minDesiredIslandSize = m_minDesiredIslandSize;
  hkpWorld::unlock(world);
}

// File Line: 108
// RVA: 0xD83150
void __fastcall hkpWorldMemoryUtil::tryToRecoverFromMemoryErrors(hkpWorld *world)
{
  int v2; // ebx
  int v3; // eax
  hkWorldMemoryAvailableWatchDog *MemoryWatchDog; // rax

  if ( hkpWorld::getMemoryWatchDog(world) )
  {
    v2 = 10;
    while ( world->m_simulation->m_previousStepResult )
    {
      v3 = v2--;
      if ( v3 <= 0 )
        break;
      MemoryWatchDog = hkpWorld::getMemoryWatchDog(world);
      MemoryWatchDog->vfptr[2].__vecDelDtor(MemoryWatchDog, (unsigned int)world);
      hkSetOutOfMemoryState(MEMORY_STATE_OK);
      hkpWorldMemoryUtil::repeatCollideAndToiHandling(world);
    }
  }
}

// File Line: 136
// RVA: 0xD831C0
void __fastcall hkpWorldMemoryUtil::repeatCollideAndToiHandling(hkpWorld *world)
{
  hkpSimulation *m_simulation; // rcx
  hkpSimulation *v3; // rcx
  unsigned int m_previousStepResult; // eax

  m_simulation = world->m_simulation;
  if ( (m_simulation->m_previousStepResult & 0xFFFFFFFD) == 0 )
    m_simulation->vfptr[2].__first_virtual_table_function__(m_simulation);
  v3 = world->m_simulation;
  m_previousStepResult = v3->m_previousStepResult;
  if ( !m_previousStepResult || m_previousStepResult == 3 )
    ((void (__fastcall *)(hkpSimulation *))v3->vfptr[3].__vecDelDtor)(v3);
}

