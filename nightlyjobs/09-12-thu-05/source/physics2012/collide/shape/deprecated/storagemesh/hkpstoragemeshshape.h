// File Line: 61
// RVA: 0xD19130
void __fastcall hkpStorageMeshShape::SubpartStorage::~SubpartStorage(hkpStorageMeshShape::SubpartStorage *this)
{
  hkpStorageMeshShape::SubpartStorage *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::SubpartStorage::`vftable;
  v2 = this->m_materialIndices16.m_capacityAndFlags;
  this->m_materialIndices16.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_materialIndices16.m_data,
      2 * (v2 & 0x3FFFFFFF));
  v1->m_materialIndices16.m_data = 0i64;
  v1->m_materialIndices16.m_capacityAndFlags = 2147483648;
  v3 = v1->m_materials.m_capacityAndFlags;
  v1->m_materials.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_materials.m_data,
      4 * v3);
  v1->m_materials.m_data = 0i64;
  v1->m_materials.m_capacityAndFlags = 2147483648;
  v4 = v1->m_materialIndices.m_capacityAndFlags;
  v1->m_materialIndices.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_materialIndices.m_data,
      v4 & 0x3FFFFFFF);
  v1->m_materialIndices.m_data = 0i64;
  v1->m_materialIndices.m_capacityAndFlags = 2147483648;
  v5 = v1->m_indices32.m_capacityAndFlags;
  v1->m_indices32.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_indices32.m_data,
      4 * v5);
  v1->m_indices32.m_data = 0i64;
  v1->m_indices32.m_capacityAndFlags = 2147483648;
  v6 = v1->m_indices16.m_capacityAndFlags;
  v1->m_indices16.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_indices16.m_data,
      2 * (v6 & 0x3FFFFFFF));
  v1->m_indices16.m_data = 0i64;
  v1->m_indices16.m_capacityAndFlags = 2147483648;
  v7 = v1->m_vertices.m_capacityAndFlags;
  v1->m_vertices.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_vertices.m_data,
      4 * v7);
  v1->m_vertices.m_data = 0i64;
  v1->m_vertices.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

