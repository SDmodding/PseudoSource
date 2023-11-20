// File Line: 14
// RVA: 0xB32E00
void __fastcall hkaSkeletonMapperData::hkaSkeletonMapperData(hkaSkeletonMapperData *this)
{
  this->m_skeletonA.m_pntr = 0i64;
  this->m_skeletonB.m_pntr = 0i64;
  this->m_partitionMap.m_data = 0i64;
  this->m_partitionMap.m_size = 0;
  this->m_partitionMap.m_capacityAndFlags = 2147483648;
  this->m_simpleMappingPartitionRanges.m_data = 0i64;
  this->m_simpleMappingPartitionRanges.m_size = 0;
  this->m_simpleMappingPartitionRanges.m_capacityAndFlags = 2147483648;
  this->m_chainMappingPartitionRanges.m_data = 0i64;
  this->m_chainMappingPartitionRanges.m_size = 0;
  this->m_chainMappingPartitionRanges.m_capacityAndFlags = 2147483648;
  this->m_simpleMappings.m_data = 0i64;
  this->m_simpleMappings.m_size = 0;
  this->m_simpleMappings.m_capacityAndFlags = 2147483648;
  this->m_chainMappings.m_data = 0i64;
  this->m_chainMappings.m_size = 0;
  this->m_chainMappings.m_capacityAndFlags = 2147483648;
  this->m_unmappedBones.m_data = 0i64;
  this->m_unmappedBones.m_size = 0;
  this->m_unmappedBones.m_capacityAndFlags = 2147483648;
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
  int v1; // er8
  hkaSkeletonMapperData *v2; // rbx
  int v3; // er8
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8
  hkReferencedObject *v8; // rcx

  v1 = this->m_unmappedBones.m_capacityAndFlags;
  v2 = this;
  this->m_unmappedBones.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_unmappedBones.m_data,
      2 * (v1 & 0x3FFFFFFF));
  v2->m_unmappedBones.m_data = 0i64;
  v2->m_unmappedBones.m_capacityAndFlags = 2147483648;
  v3 = v2->m_chainMappings.m_capacityAndFlags;
  v2->m_chainMappings.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_chainMappings.m_data,
      112 * (v3 & 0x3FFFFFFF));
  v2->m_chainMappings.m_data = 0i64;
  v2->m_chainMappings.m_capacityAndFlags = 2147483648;
  v4 = v2->m_simpleMappings.m_capacityAndFlags;
  v2->m_simpleMappings.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_simpleMappings.m_data,
      v4 << 6);
  v2->m_simpleMappings.m_data = 0i64;
  v2->m_simpleMappings.m_capacityAndFlags = 2147483648;
  v5 = v2->m_chainMappingPartitionRanges.m_capacityAndFlags;
  v2->m_chainMappingPartitionRanges.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_chainMappingPartitionRanges.m_data,
      8 * v5);
  v2->m_chainMappingPartitionRanges.m_data = 0i64;
  v2->m_chainMappingPartitionRanges.m_capacityAndFlags = 2147483648;
  v6 = v2->m_simpleMappingPartitionRanges.m_capacityAndFlags;
  v2->m_simpleMappingPartitionRanges.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_simpleMappingPartitionRanges.m_data,
      8 * v6);
  v2->m_simpleMappingPartitionRanges.m_data = 0i64;
  v2->m_simpleMappingPartitionRanges.m_capacityAndFlags = 2147483648;
  v7 = v2->m_partitionMap.m_capacityAndFlags;
  v2->m_partitionMap.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_partitionMap.m_data,
      2 * (v7 & 0x3FFFFFFF));
  v2->m_partitionMap.m_data = 0i64;
  v2->m_partitionMap.m_capacityAndFlags = 2147483648;
  v8 = (hkReferencedObject *)&v2->m_skeletonB.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v2->m_skeletonB.m_pntr = 0i64;
  if ( v2->m_skeletonA.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_skeletonA.m_pntr->vfptr);
  v2->m_skeletonA.m_pntr = 0i64;
}

