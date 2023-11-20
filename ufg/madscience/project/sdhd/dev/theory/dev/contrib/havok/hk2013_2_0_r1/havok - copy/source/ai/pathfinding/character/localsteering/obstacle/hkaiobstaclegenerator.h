// File Line: 27
// RVA: 0xBB75E0
void __fastcall hkaiObstacleGenerator::~hkaiObstacleGenerator(hkaiObstacleGenerator *this)
{
  hkaiObstacleGenerator *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiObstacleGenerator::`vftable';
  v2 = this->m_boundaries.m_capacityAndFlags;
  this->m_boundaries.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_boundaries.m_data,
      32 * v2);
  v1->m_boundaries.m_data = 0i64;
  v1->m_boundaries.m_capacityAndFlags = 2147483648;
  v3 = v1->m_spheres.m_capacityAndFlags;
  v1->m_spheres.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_spheres.m_data,
      32 * v3);
  v1->m_spheres.m_data = 0i64;
  v1->m_spheres.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

