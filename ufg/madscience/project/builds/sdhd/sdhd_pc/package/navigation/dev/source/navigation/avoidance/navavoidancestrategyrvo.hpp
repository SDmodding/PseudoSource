// File Line: 23
// RVA: 0xE3960
void __fastcall UFG::AgentInfo::AgentInfo(UFG::AgentInfo *this)
{
  __int32 v2; // ebx
  hkaiCharacter **v3; // r8
  __int32 v4; // ecx
  hkaiObstacleGenerator **v5; // rcx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  this->m_characters.m_data = 0i64;
  this->m_characters.m_size = 0;
  v2 = 0x80000000;
  this->m_characters.m_capacityAndFlags = 0x80000000;
  result.m_enum = 400;
  v3 = (hkaiCharacter **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &result);
  v4 = 0x80000000;
  if ( result.m_enum / 8 )
    v4 = result.m_enum / 8;
  this->m_characters.m_data = v3;
  this->m_characters.m_size = 50;
  this->m_characters.m_capacityAndFlags = v4;
  this->m_obstacles.m_data = 0i64;
  this->m_obstacles.m_size = 0;
  this->m_obstacles.m_capacityAndFlags = 0x80000000;
  result.m_enum = 400;
  v5 = (hkaiObstacleGenerator **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                   &hkContainerHeapAllocator::s_alloc,
                                   &result);
  if ( result.m_enum / 8 )
    v2 = result.m_enum / 8;
  this->m_obstacles.m_data = v5;
  this->m_obstacles.m_size = 50;
  this->m_obstacles.m_capacityAndFlags = v2;
  this->m_characters.m_size = 0;
  this->m_obstacles.m_size = 0;
}

