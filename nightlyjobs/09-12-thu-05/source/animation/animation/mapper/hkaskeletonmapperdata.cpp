// File Line: 14
// RVA: 0xB32E00
void __fastcall hkaSkeletonMapperData::hkaSkeletonMapperData(hkaSkeletonMapperData *this)
{
  this->m_skeletonA.m_pntr = 0i64;
  this->m_skeletonB.m_pntr = 0i64;
  this->m_partitionMap.m_data = 0i64;
  this->m_partitionMap.m_size = 0;
  this->m_partitionMap.m_capacityAndFlags = 0x80000000;
  this->m_simpleMappingPartitionRanges.m_data = 0i64;
  this->m_simpleMappingPartitionRanges.m_size = 0;
  this->m_simpleMappingPartitionRanges.m_capacityAndFlags = 0x80000000;
  this->m_chainMappingPartitionRanges.m_data = 0i64;
  this->m_chainMappingPartitionRanges.m_size = 0;
  this->m_chainMappingPartitionRanges.m_capacityAndFlags = 0x80000000;
  this->m_simpleMappings.m_data = 0i64;
  this->m_simpleMappings.m_size = 0;
  this->m_simpleMappings.m_capacityAndFlags = 0x80000000;
  this->m_chainMappings.m_data = 0i64;
  this->m_chainMappings.m_size = 0;
  this->m_chainMappings.m_capacityAndFlags = 0x80000000;
  this->m_unmappedBones.m_data = 0i64;
  this->m_unmappedBones.m_size = 0;
  this->m_unmappedBones.m_capacityAndFlags = 0x80000000;
  this->m_keepUnmappedLocal.m_bool = 1;
  this->m_extractedMotionMapping.m_translation = 0i64;
  this->m_extractedMotionMapping.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->m_extractedMotionMapping.m_scale = (hkVector4f)query.m_quad;
}

// File Line: 28
// RVA: 0xB32EA0
void __fastcall hkaSkeletonMapperData::hkaSkeletonMapperData(hkaSkeletonMapperData *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 32
// RVA: 0xB32EB0
void __fastcall hkaSkeletonMapperData::~hkaSkeletonMapperData(hkaSkeletonMapperData *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  hkaSkeleton *m_pntr; // rcx

  m_capacityAndFlags = this->m_unmappedBones.m_capacityAndFlags;
  this->m_unmappedBones.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_unmappedBones.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_unmappedBones.m_data = 0i64;
  this->m_unmappedBones.m_capacityAndFlags = 0x80000000;
  v3 = this->m_chainMappings.m_capacityAndFlags;
  this->m_chainMappings.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_chainMappings.m_data,
      112 * (v3 & 0x3FFFFFFF));
  this->m_chainMappings.m_data = 0i64;
  this->m_chainMappings.m_capacityAndFlags = 0x80000000;
  v4 = this->m_simpleMappings.m_capacityAndFlags;
  this->m_simpleMappings.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_simpleMappings.m_data,
      v4 << 6);
  this->m_simpleMappings.m_data = 0i64;
  this->m_simpleMappings.m_capacityAndFlags = 0x80000000;
  v5 = this->m_chainMappingPartitionRanges.m_capacityAndFlags;
  this->m_chainMappingPartitionRanges.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_chainMappingPartitionRanges.m_data,
      8 * v5);
  this->m_chainMappingPartitionRanges.m_data = 0i64;
  this->m_chainMappingPartitionRanges.m_capacityAndFlags = 0x80000000;
  v6 = this->m_simpleMappingPartitionRanges.m_capacityAndFlags;
  this->m_simpleMappingPartitionRanges.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_simpleMappingPartitionRanges.m_data,
      8 * v6);
  this->m_simpleMappingPartitionRanges.m_data = 0i64;
  this->m_simpleMappingPartitionRanges.m_capacityAndFlags = 0x80000000;
  v7 = this->m_partitionMap.m_capacityAndFlags;
  this->m_partitionMap.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_partitionMap.m_data,
      2 * (v7 & 0x3FFFFFFF));
  this->m_partitionMap.m_data = 0i64;
  this->m_partitionMap.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_skeletonB.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_skeletonB.m_pntr = 0i64;
  if ( this->m_skeletonA.m_pntr )
    hkReferencedObject::removeReference(this->m_skeletonA.m_pntr);
  this->m_skeletonA.m_pntr = 0i64;
}

