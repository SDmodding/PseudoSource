// File Line: 18
// RVA: 0x51A3A0
void __fastcall hkpAllRayHitCollector::hkpAllRayHitCollector(hkpAllRayHitCollector *this)
{
  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpRayHitCollector::`vftable;
  this->m_earlyOutHitFraction = 1.0;
  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpAllRayHitCollector::`vftable;
  this->m_hits.m_data = this->m_hits.m_storage;
  this->m_hits.m_size = 0;
  this->m_hits.m_capacityAndFlags = -2147483640;
  this->m_hits.m_storage[0].m_hitFraction = 1.0;
  this->m_hits.m_storage[0].m_extraInfo = -1;
  this->m_hits.m_storage[0].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[0].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[0].m_rootCollidable = 0i64;
  this->m_hits.m_storage[1].m_hitFraction = 1.0;
  this->m_hits.m_storage[1].m_extraInfo = -1;
  this->m_hits.m_storage[1].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[1].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[1].m_rootCollidable = 0i64;
  this->m_hits.m_storage[2].m_hitFraction = 1.0;
  this->m_hits.m_storage[2].m_extraInfo = -1;
  this->m_hits.m_storage[2].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[2].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[2].m_rootCollidable = 0i64;
  this->m_hits.m_storage[3].m_hitFraction = 1.0;
  this->m_hits.m_storage[3].m_extraInfo = -1;
  this->m_hits.m_storage[3].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[3].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[3].m_rootCollidable = 0i64;
  this->m_hits.m_storage[4].m_hitFraction = 1.0;
  this->m_hits.m_storage[4].m_extraInfo = -1;
  this->m_hits.m_storage[4].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[4].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[4].m_rootCollidable = 0i64;
  this->m_hits.m_storage[5].m_hitFraction = 1.0;
  this->m_hits.m_storage[5].m_extraInfo = -1;
  this->m_hits.m_storage[5].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[5].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[5].m_rootCollidable = 0i64;
  this->m_hits.m_storage[6].m_hitFraction = 1.0;
  this->m_hits.m_storage[6].m_extraInfo = -1;
  this->m_hits.m_storage[6].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[6].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[6].m_rootCollidable = 0i64;
  this->m_hits.m_storage[7].m_hitFraction = 1.0;
  this->m_hits.m_storage[7].m_extraInfo = -1;
  this->m_hits.m_storage[7].m_shapeKeyIndex = 0;
  this->m_hits.m_storage[7].m_shapeKeys[0] = -1;
  this->m_hits.m_storage[7].m_rootCollidable = 0i64;
  this->m_hits.m_size = 0;
  this->m_earlyOutHitFraction = 1.0;
}

// File Line: 23
// RVA: 0x51D790
void __fastcall hkpAllRayHitCollector::~hkpAllRayHitCollector(hkpAllRayHitCollector *this)
{
  hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *p_m_hits; // rbx
  int m_capacityAndFlags; // eax

  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpAllRayHitCollector::`vftable;
  p_m_hits = &this->m_hits;
  this->m_hits.m_size = 0;
  m_capacityAndFlags = this->m_hits.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_hits->m_data,
      96 * (m_capacityAndFlags & 0x3FFFFFFF));
  p_m_hits->m_data = 0i64;
  p_m_hits->m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpRayHitCollector::`vftable;
}

