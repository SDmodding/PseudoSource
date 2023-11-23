// File Line: 61
// RVA: 0xD19130
void __fastcall hkpStorageMeshShape::SubpartStorage::~SubpartStorage(hkpStorageMeshShape::SubpartStorage *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::SubpartStorage::`vftable;
  m_capacityAndFlags = this->m_materialIndices16.m_capacityAndFlags;
  this->m_materialIndices16.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materialIndices16.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_materialIndices16.m_data = 0i64;
  this->m_materialIndices16.m_capacityAndFlags = 0x80000000;
  v3 = this->m_materials.m_capacityAndFlags;
  this->m_materials.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materials.m_data,
      4 * v3);
  this->m_materials.m_data = 0i64;
  this->m_materials.m_capacityAndFlags = 0x80000000;
  v4 = this->m_materialIndices.m_capacityAndFlags;
  this->m_materialIndices.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materialIndices.m_data,
      v4 & 0x3FFFFFFF);
  this->m_materialIndices.m_data = 0i64;
  this->m_materialIndices.m_capacityAndFlags = 0x80000000;
  v5 = this->m_indices32.m_capacityAndFlags;
  this->m_indices32.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_indices32.m_data,
      4 * v5);
  this->m_indices32.m_data = 0i64;
  this->m_indices32.m_capacityAndFlags = 0x80000000;
  v6 = this->m_indices16.m_capacityAndFlags;
  this->m_indices16.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_indices16.m_data,
      2 * (v6 & 0x3FFFFFFF));
  this->m_indices16.m_data = 0i64;
  this->m_indices16.m_capacityAndFlags = 0x80000000;
  v7 = this->m_vertices.m_capacityAndFlags;
  this->m_vertices.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_vertices.m_data,
      4 * v7);
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

