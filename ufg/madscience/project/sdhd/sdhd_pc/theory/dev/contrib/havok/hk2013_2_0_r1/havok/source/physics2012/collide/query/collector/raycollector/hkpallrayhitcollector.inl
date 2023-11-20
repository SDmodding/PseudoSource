// File Line: 18
// RVA: 0x51A3A0
void __fastcall hkpAllRayHitCollector::hkpAllRayHitCollector(hkpAllRayHitCollector *this)
{
  hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *v1; // [rsp+28h] [rbp+10h]

  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpRayHitCollector::`vftable;
  this->m_earlyOutHitFraction = 1.0;
  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpAllRayHitCollector::`vftable;
  v1 = &this->m_hits;
  v1->m_data = this->m_hits.m_storage;
  v1->m_size = 0;
  v1->m_capacityAndFlags = -2147483640;
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
  hkpAllRayHitCollector *v1; // rdi
  hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *v2; // rbx
  int v3; // eax

  v1 = this;
  this->vfptr = (hkpRayHitCollectorVtbl *)&hkpAllRayHitCollector::`vftable;
  v2 = &this->m_hits;
  this->m_hits.m_size = 0;
  v3 = this->m_hits.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_data,
      96 * (v3 & 0x3FFFFFFF));
  v2->m_data = 0i64;
  v2->m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpRayHitCollectorVtbl *)&hkpRayHitCollector::`vftable;
}

