// File Line: 59
// RVA: 0xB7A5C0
void __fastcall hkaiRemoveUnreachableHitFilter::~hkaiRemoveUnreachableHitFilter(hkaiRemoveUnreachableHitFilter *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  hkaiEdgeGeometry *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiRemoveUnreachableHitFilter::`vftable;
  m_capacityAndFlags = this->m_triOffsets.m_capacityAndFlags;
  this->m_triOffsets.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_triOffsets.m_data,
      4 * m_capacityAndFlags);
  this->m_triOffsets.m_data = 0i64;
  this->m_triOffsets.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_origToWalkableFaceMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_origToWalkableFaceMap);
  v3 = this->m_mapStorage.m_capacityAndFlags;
  this->m_mapStorage.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_mapStorage.m_data,
      v3 & 0x3FFFFFFF);
  this->m_mapStorage.m_data = 0i64;
  this->m_mapStorage.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_walkableGeom.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_walkableGeom.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

