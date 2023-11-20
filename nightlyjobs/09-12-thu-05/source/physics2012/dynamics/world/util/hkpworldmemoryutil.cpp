// File Line: 24
// RVA: 0xD82ED0
void __fastcall hkpWorldMemoryUtil::watchHeapMemory(hkpWorld *world)
{
  hkpWorld *v1; // rdi
  hkWorldMemoryAvailableWatchDog *v2; // rax
  int v3; // ebx
  hkMemorySystem *v4; // rax
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkWorldMemoryAvailableWatchDog *v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v1 = world;
  if ( hkpWorld::getMemoryWatchDog(world) )
  {
    v2 = hkpWorld::getMemoryWatchDog(v1);
    v3 = ((__int64 (__fastcall *)(hkWorldMemoryAvailableWatchDog *))v2->vfptr[1].__first_virtual_table_function__)(v2);
    v4 = hkMemorySystem::getInstance();
    if ( !v4->vfptr->heapCanAllocTotal(v4, v3) )
    {
      v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v6 = (_QWORD *)v5[1];
      if ( (unsigned __int64)v6 < v5[3] )
      {
        *v6 = "TtWatchDog:FreeMem";
        v7 = __rdtsc();
        v8 = (signed __int64)(v6 + 2);
        *(_DWORD *)(v8 - 8) = v7;
        v5[1] = v8;
      }
      v9 = hkpWorld::getMemoryWatchDog(v1);
      v9->vfptr[2].__vecDelDtor((hkBaseObject *)&v9->vfptr, (unsigned int)v1);
      v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v11 = (_QWORD *)v10[1];
      if ( (unsigned __int64)v11 < v10[3] )
      {
        *v11 = "Et";
        v12 = __rdtsc();
        v13 = (signed __int64)(v11 + 2);
        *(_DWORD *)(v13 - 8) = v12;
        v10[1] = v13;
      }
    }
    if ( hkOutOfMemoryState )
      hkSetOutOfMemoryState(0);
  }
}

// File Line: 44
// RVA: 0xD82FD0
void __fastcall hkpWorldMemoryUtil::checkMemoryForIntegration(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  unsigned int v2; // er14
  unsigned int v3; // ebp
  hkMemorySystem *v4; // rax
  hkpSimulationIsland *v5; // rax
  char i; // cl
  int v7; // esi
  hkpSimulationIsland *v8; // rdi
  bool v9; // zf
  hkMemorySystem *v10; // rax
  hkpSimulationIsland *v11; // rdi
  hkWorldMemoryAvailableWatchDog *v12; // rax
  hkMemorySystem *v13; // rax
  hkWorldMemoryAvailableWatchDog::MemUsageInfo infoOut; // [rsp+20h] [rbp-18h]

  v1 = world;
  hkpWorld::lock(world);
  v2 = v1->m_minDesiredIslandSize;
  v3 = 0;
  hkpWorld::calcRequiredSolverBufferSize(v1, &infoOut);
  v4 = hkMemorySystem::getInstance();
  if ( !v4->vfptr->solverCanAllocSingleBlock(v4, infoOut.m_maxRuntimeBlockSize) )
  {
    do
    {
      v5 = infoOut.m_largestSimulationIsland;
      ++v3;
      for ( i = (*((_BYTE *)infoOut.m_largestSimulationIsland + 49) >> 2) & 3; i; i = (*((_BYTE *)v5 + 49) >> 2) & 3 )
      {
        v7 = infoOut.m_maxRuntimeBlockSize;
        v8 = v5;
        if ( i )
        {
          while ( 1 )
          {
            v9 = v1->m_minDesiredIslandSize == 0;
            if ( !v1->m_minDesiredIslandSize )
              break;
            hkpWorldOperationUtil::splitSimulationIsland(v1, v8);
            hkpWorld::calcRequiredSolverBufferSize(v1, &infoOut);
            v5 = infoOut.m_largestSimulationIsland;
            if ( infoOut.m_largestSimulationIsland == v8 && infoOut.m_maxRuntimeBlockSize == v7 )
            {
              v1->m_minDesiredIslandSize >>= 1;
              if ( *((_BYTE *)v5 + 49) & 0xC )
                continue;
            }
            goto LABEL_8;
          }
        }
        else
        {
LABEL_8:
          v9 = v1->m_minDesiredIslandSize == 0;
        }
        if ( v9 )
          break;
      }
      v10 = hkMemorySystem::getInstance();
      if ( !v10->vfptr->solverCanAllocSingleBlock(v10, infoOut.m_maxRuntimeBlockSize) )
      {
        v11 = infoOut.m_largestSimulationIsland;
        if ( (unsigned __int8)hkpSimulationIsland::isFullyConnected(infoOut.m_largestSimulationIsland)
          || !v1->m_minDesiredIslandSize )
        {
          v12 = hkpWorld::getMemoryWatchDog(v1);
          ((void (__fastcall *)(hkWorldMemoryAvailableWatchDog *, hkWorldMemoryAvailableWatchDog::MemUsageInfo *, _QWORD))v12->vfptr[2].__first_virtual_table_function__)(
            v12,
            &infoOut,
            v3);
          hkpWorld::calcRequiredSolverBufferSize(v1, &infoOut);
        }
        else
        {
          *((_BYTE *)v11 + 49) &= 0xF7u;
          *((_BYTE *)v11 + 49) |= 4u;
        }
      }
      v13 = hkMemorySystem::getInstance();
    }
    while ( !v13->vfptr->solverCanAllocSingleBlock(v13, infoOut.m_maxRuntimeBlockSize) );
  }
  v1->m_minDesiredIslandSize = v2;
  hkpWorld::unlock(v1);
}

// File Line: 108
// RVA: 0xD83150
void __fastcall hkpWorldMemoryUtil::tryToRecoverFromMemoryErrors(hkpWorld *world)
{
  hkpWorld *v1; // rdi
  signed int v2; // ebx
  signed int v3; // eax
  hkWorldMemoryAvailableWatchDog *v4; // rax

  v1 = world;
  if ( hkpWorld::getMemoryWatchDog(world) )
  {
    v2 = 10;
    while ( v1->m_simulation->m_previousStepResult )
    {
      v3 = v2--;
      if ( v3 <= 0 )
        break;
      v4 = hkpWorld::getMemoryWatchDog(v1);
      v4->vfptr[2].__vecDelDtor((hkBaseObject *)&v4->vfptr, (unsigned int)v1);
      hkSetOutOfMemoryState(0);
      hkpWorldMemoryUtil::repeatCollideAndToiHandling(v1);
    }
  }
}

// File Line: 136
// RVA: 0xD831C0
void __fastcall hkpWorldMemoryUtil::repeatCollideAndToiHandling(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  hkpSimulation *v2; // rcx
  hkpSimulation *v3; // rcx
  unsigned int v4; // eax

  v1 = world;
  v2 = world->m_simulation;
  if ( !(v2->m_previousStepResult & 0xFFFFFFFD) )
    ((void (*)(void))v2->vfptr[2].__first_virtual_table_function__)();
  v3 = v1->m_simulation;
  v4 = v3->m_previousStepResult;
  if ( !v4 || v4 == 3 )
    ((void (*)(void))v3->vfptr[3].__vecDelDtor)();
}

