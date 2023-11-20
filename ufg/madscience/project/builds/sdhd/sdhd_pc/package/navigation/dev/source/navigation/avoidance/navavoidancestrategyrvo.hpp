// File Line: 23
// RVA: 0xE3960
void __fastcall UFG::AgentInfo::AgentInfo(UFG::AgentInfo *this)
{
  UFG::AgentInfo *v1; // rbp
  __int32 v2; // ebx
  hkaiCharacter **v3; // r8
  __int32 v4; // ecx
  hkaiObstacleGenerator **v5; // rcx
  int v6; // er9
  int v7; // er9
  hkResult result; // [rsp+68h] [rbp+10h]

  v1 = this;
  this->m_characters.m_data = 0i64;
  this->m_characters.m_size = 0;
  v2 = 2147483648;
  this->m_characters.m_capacityAndFlags = 2147483648;
  result.m_enum = 400;
  v3 = (hkaiCharacter **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                           (int *)&result);
  v4 = 2147483648;
  if ( result.m_enum / 8 )
    v4 = result.m_enum / 8;
  v1->m_characters.m_data = v3;
  v1->m_characters.m_size = 50;
  v1->m_characters.m_capacityAndFlags = v4;
  v1->m_obstacles.m_data = 0i64;
  v1->m_obstacles.m_size = 0;
  v1->m_obstacles.m_capacityAndFlags = 2147483648;
  result.m_enum = 400;
  v5 = (hkaiObstacleGenerator **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                   (int *)&result);
  if ( result.m_enum / 8 )
    v2 = result.m_enum / 8;
  v1->m_obstacles.m_data = v5;
  v1->m_obstacles.m_size = 50;
  v1->m_obstacles.m_capacityAndFlags = v2;
  if ( (v1->m_characters.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v6 = 0;
    if ( 2 * (v1->m_characters.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v6 = 2 * (v1->m_characters.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_characters,
      v6,
      8);
  }
  v1->m_characters.m_size = 0;
  if ( (v1->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v7 = 0;
    if ( 2 * (v1->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v7 = 2 * (v1->m_obstacles.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_obstacles,
      v7,
      8);
  }
  v1->m_obstacles.m_size = 0;
}

