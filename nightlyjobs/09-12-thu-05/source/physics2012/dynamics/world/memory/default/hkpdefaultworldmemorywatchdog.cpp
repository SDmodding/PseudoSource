// File Line: 22
// RVA: 0xD798E0
void __fastcall hkpDefaultWorldMemoryWatchDog::hkpDefaultWorldMemoryWatchDog(
        hkpDefaultWorldMemoryWatchDog *this,
        int minMemoryAvailable)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_freeHeapMemoryRequested = minMemoryAvailable;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDefaultWorldMemoryWatchDog::`vftable;
}

// File Line: 27
// RVA: 0xD79900
__int64 __fastcall hkpDefaultWorldMemoryWatchDog::getAmountOfFreeHeapMemoryRequested(
        hkpDefaultWorldMemoryWatchDog *this)
{
  return (unsigned int)this->m_freeHeapMemoryRequested;
}

// File Line: 35
// RVA: 0xD79910
void __fastcall hkpDefaultWorldMemoryWatchDog::freeHeapMemoryTillRequestedAmountIsAvailable(
        hkpDefaultWorldMemoryWatchDog *this,
        hkpWorld *world)
{
  unsigned int m_freeHeapMemoryRequested; // ebp
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  int m_size; // ecx
  hkpSimulationIsland *v9; // rcx
  hkMemorySystem *Instance; // rax
  int maxFoundAutoRemoveLevelOut; // [rsp+30h] [rbp+8h] BYREF

  m_freeHeapMemoryRequested = this->m_freeHeapMemoryRequested;
  v4 = 127;
  while ( 1 )
  {
    v5 = 0;
    v6 = world->m_activeSimulationIslands.m_size - 1;
    v7 = -world->m_inactiveSimulationIslands.m_size;
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
    m_size = world->m_activeSimulationIslands.m_size;
    if ( v6 >= m_size )
    {
      v6 = m_size - 1;
      if ( m_size - 1 < v7 )
        break;
    }
    v9 = v6 < 0 ? world->m_inactiveSimulationIslands.m_data[-v6 - 1] : world->m_activeSimulationIslands.m_data[v6];
    hkpDefaultWorldMemoryWatchDog::removeObjectsFromIsland(
      v9,
      v4,
      m_freeHeapMemoryRequested,
      &maxFoundAutoRemoveLevelOut);
    Instance = hkMemorySystem::getInstance();
    if ( Instance->vfptr->heapCanAllocTotal(Instance, m_freeHeapMemoryRequested) )
      break;
    --v6;
    v7 = -world->m_inactiveSimulationIslands.m_size;
    if ( v6 < v7 )
    {
      v5 = maxFoundAutoRemoveLevelOut;
      goto LABEL_11;
    }
  }
}

// File Line: 84
// RVA: 0xD799D0
void __fastcall hkpDefaultWorldMemoryWatchDog::reduceConstraintsInIsland(
        hkpDefaultWorldMemoryWatchDog *this,
        hkWorldMemoryAvailableWatchDog::MemUsageInfo *info,
        int numIterations)
{
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  hkpWorld::removeEntity(
    info->m_largestSimulationIsland->m_world,
    &result,
    *info->m_largestSimulationIsland->m_entities.m_data);
}

// File Line: 94
// RVA: 0xD79A00
void __fastcall hkpDefaultWorldMemoryWatchDog::removeObjectsFromIsland(
        hkpSimulationIsland *island,
        int currentAutoRemoveLevel,
        unsigned int freeHeapMemoryRequested,
        int *maxFoundAutoRemoveLevelOut)
{
  int v6; // eax
  __int64 i; // rbx
  hkpEntity *v10; // r8
  int m_autoRemoveLevel; // eax
  hkMemorySystem *Instance; // rax
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  v6 = island->m_entities.m_size - 1;
  for ( i = v6; i >= 0; --i )
  {
    v10 = island->m_entities.m_data[i];
    m_autoRemoveLevel = v10->m_autoRemoveLevel;
    if ( m_autoRemoveLevel < currentAutoRemoveLevel )
    {
      if ( *maxFoundAutoRemoveLevelOut > m_autoRemoveLevel )
        m_autoRemoveLevel = *maxFoundAutoRemoveLevelOut;
      *maxFoundAutoRemoveLevelOut = m_autoRemoveLevel;
    }
    else
    {
      hkpWorld::removeEntity(island->m_world, &result, v10);
      Instance = hkMemorySystem::getInstance();
      if ( !Instance->vfptr->heapCanAllocTotal(Instance, freeHeapMemoryRequested) )
        return;
    }
  }
}

