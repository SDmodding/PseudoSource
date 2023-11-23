// File Line: 27
// RVA: 0xBB75E0
void __fastcall hkaiObstacleGenerator::~hkaiObstacleGenerator(hkaiObstacleGenerator *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiObstacleGenerator::`vftable;
  m_capacityAndFlags = this->m_boundaries.m_capacityAndFlags;
  this->m_boundaries.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_boundaries.m_data,
      32 * m_capacityAndFlags);
  this->m_boundaries.m_data = 0i64;
  this->m_boundaries.m_capacityAndFlags = 0x80000000;
  v3 = this->m_spheres.m_capacityAndFlags;
  this->m_spheres.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_spheres.m_data,
      32 * v3);
  this->m_spheres.m_data = 0i64;
  this->m_spheres.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

