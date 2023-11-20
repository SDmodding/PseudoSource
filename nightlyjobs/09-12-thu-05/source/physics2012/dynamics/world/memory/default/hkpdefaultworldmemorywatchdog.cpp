// File Line: 22
// RVA: 0xD798E0
void __fastcall hkpDefaultWorldMemoryWatchDog::hkpDefaultWorldMemoryWatchDog(hkpDefaultWorldMemoryWatchDog *this, int minMemoryAvailable)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_freeHeapMemoryRequested = minMemoryAvailable;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDefaultWorldMemoryWatchDog::`vftable';
}

// File Line: 27
// RVA: 0xD79900
__int64 __fastcall hkpDefaultWorldMemoryWatchDog::getAmountOfFreeHeapMemoryRequested(hkpDefaultWorldMemoryWatchDog *this)
{
  return (unsigned int)this->m_freeHeapMemoryRequested;
}

// File Line: 35
// RVA: 0xD79910
void __fastcall hkpDefaultWorldMemoryWatchDog::freeHeapMemoryTillRequestedAmountIsAvailable(hkpDefaultWorldMemoryWatchDog *this, hkpWorld *world)
{
  unsigned int v2; // ebp
  hkpWorld *v3; // rdi
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  hkpSimulationIsland *v9; // rcx
  hkMemorySystem *v10; // rax
  int maxFoundAutoRemoveLevelOut; // [rsp+30h] [rbp+8h]

  v2 = this->m_freeHeapMemoryRequested;
  v3 = world;
  v4 = 127;
  while ( 1 )
  {
    v5 = 0;
    v6 = v3->m_activeSimulationIslands.m_size - 1;
    v7 = -v3->m_inactiveSimulationIslands.m_size;
    maxFoundAutoRemoveLevelOut = 0;
    if ( v6 >= v7 )
      break;
LABEL_11:
    v4 = v5;
    if ( v5 <= 0 )
      return;
  }
  while ( 1 )
  {
    v8 = v3->m_activeSimulationIslands.m_size;
    if ( v6 >= v8 )
    {
      v6 = v8 - 1;
      if ( v8 - 1 < v7 )
        break;
    }
    v9 = v6 < 0 ? v3->m_inactiveSimulationIslands.m_data[-v6 - 1] : v3->m_activeSimulationIslands.m_data[v6];
    hkpDefaultWorldMemoryWatchDog::removeObjectsFromIsland(v9, v4, v2, &maxFoundAutoRemoveLevelOut);
    v10 = hkMemorySystem::getInstance();
    if ( v10->vfptr->heapCanAllocTotal(v10, v2) )
      break;
    --v6;
    v7 = -v3->m_inactiveSimulationIslands.m_size;
    if ( v6 < v7 )
    {
      v5 = maxFoundAutoRemoveLevelOut;
      goto LABEL_11;
    }
  }
}

// File Line: 84
// RVA: 0xD799D0
void __fastcall hkpDefaultWorldMemoryWatchDog::reduceConstraintsInIsland(hkpDefaultWorldMemoryWatchDog *this, hkWorldMemoryAvailableWatchDog::MemUsageInfo *info, int numIterations)
{
  hkBool result; // [rsp+38h] [rbp+10h]

  hkpWorld::removeEntity(
    info->m_largestSimulationIsland->m_world,
    &result,
    *info->m_largestSimulationIsland->m_entities.m_data);
}

// File Line: 94
// RVA: 0xD79A00
void __fastcall hkpDefaultWorldMemoryWatchDog::removeObjectsFromIsland(hkpSimulationIsland *island, int currentAutoRemoveLevel, int freeHeapMemoryRequested, int *maxFoundAutoRemoveLevelOut)
{
  int *v4; // rsi
  unsigned int v5; // er14
  int v6; // eax
  int v7; // ebp
  hkpSimulationIsland *v8; // rdi
  __int64 i; // rbx
  hkpEntity *v10; // r8
  int v11; // eax
  hkMemorySystem *v12; // rax
  hkBool result; // [rsp+40h] [rbp+8h]

  v4 = maxFoundAutoRemoveLevelOut;
  v5 = freeHeapMemoryRequested;
  v6 = island->m_entities.m_size - 1;
  v7 = currentAutoRemoveLevel;
  v8 = island;
  for ( i = v6; i >= 0; --i )
  {
    v10 = v8->m_entities.m_data[i];
    v11 = v10->m_autoRemoveLevel;
    if ( v11 < v7 )
    {
      if ( *v4 > v11 )
        v11 = *v4;
      *v4 = v11;
    }
    else
    {
      hkpWorld::removeEntity(v8->m_world, &result, v10);
      v12 = hkMemorySystem::getInstance();
      if ( !v12->vfptr->heapCanAllocTotal(v12, v5) )
        return;
    }
  }
}

