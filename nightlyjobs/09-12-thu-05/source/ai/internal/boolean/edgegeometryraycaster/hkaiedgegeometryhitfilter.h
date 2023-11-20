// File Line: 59
// RVA: 0xB7A5C0
void __fastcall hkaiRemoveUnreachableHitFilter::~hkaiRemoveUnreachableHitFilter(hkaiRemoveUnreachableHitFilter *this)
{
  hkaiRemoveUnreachableHitFilter *v1; // rdi
  int v2; // er8
  int v3; // er8
  hkReferencedObject *v4; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiRemoveUnreachableHitFilter::`vftable;
  v2 = this->m_triOffsets.m_capacityAndFlags;
  this->m_triOffsets.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_triOffsets.m_data,
      4 * v2);
  v1->m_triOffsets.m_data = 0i64;
  v1->m_triOffsets.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_origToWalkableFaceMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_origToWalkableFaceMap);
  v3 = v1->m_mapStorage.m_capacityAndFlags;
  v1->m_mapStorage.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_mapStorage.m_data,
      v3 & 0x3FFFFFFF);
  v1->m_mapStorage.m_data = 0i64;
  v1->m_mapStorage.m_capacityAndFlags = 2147483648;
  v4 = (hkReferencedObject *)&v1->m_walkableGeom.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_walkableGeom.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

