// File Line: 81
// RVA: 0xD15BB0
void __fastcall hkpStorageExtendedMeshShape::MeshSubpartStorage::~MeshSubpartStorage(
        hkpStorageExtendedMeshShape::MeshSubpartStorage *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // edi
  hkStringPtr *p_m_name; // rsi
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  int v8; // r8d
  int v9; // r8d
  int v10; // r8d
  int v11; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::MeshSubpartStorage::`vftable;
  m_capacityAndFlags = this->m_materialIndices16.m_capacityAndFlags;
  this->m_materialIndices16.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materialIndices16.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_materialIndices16.m_data = 0i64;
  this->m_materialIndices16.m_capacityAndFlags = 0x80000000;
  v3 = this->m_namedMaterials.m_size - 1;
  if ( v3 >= 0 )
  {
    p_m_name = &this->m_namedMaterials.m_data[v3].m_name;
    do
    {
      hkStringPtr::~hkStringPtr(p_m_name);
      p_m_name -= 2;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = this->m_namedMaterials.m_capacityAndFlags;
  this->m_namedMaterials.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_namedMaterials.m_data,
      16 * v5);
  this->m_namedMaterials.m_data = 0i64;
  this->m_namedMaterials.m_capacityAndFlags = 0x80000000;
  v6 = this->m_materials.m_capacityAndFlags;
  this->m_materials.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materials.m_data,
      16 * v6);
  this->m_materials.m_data = 0i64;
  this->m_materials.m_capacityAndFlags = 0x80000000;
  v7 = this->m_materialIndices.m_capacityAndFlags;
  this->m_materialIndices.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materialIndices.m_data,
      v7 & 0x3FFFFFFF);
  this->m_materialIndices.m_data = 0i64;
  this->m_materialIndices.m_capacityAndFlags = 0x80000000;
  v8 = this->m_indices32.m_capacityAndFlags;
  this->m_indices32.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_indices32.m_data,
      4 * v8);
  this->m_indices32.m_data = 0i64;
  this->m_indices32.m_capacityAndFlags = 0x80000000;
  v9 = this->m_indices16.m_capacityAndFlags;
  this->m_indices16.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_indices16.m_data,
      2 * (v9 & 0x3FFFFFFF));
  this->m_indices16.m_data = 0i64;
  this->m_indices16.m_capacityAndFlags = 0x80000000;
  v10 = this->m_indices8.m_capacityAndFlags;
  this->m_indices8.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_indices8.m_data,
      v10 & 0x3FFFFFFF);
  this->m_indices8.m_data = 0i64;
  this->m_indices8.m_capacityAndFlags = 0x80000000;
  v11 = this->m_vertices.m_capacityAndFlags;
  this->m_vertices.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_vertices.m_data,
      16 * v11);
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 108
// RVA: 0xD15DE0
void __fastcall hkpStorageExtendedMeshShape::ShapeSubpartStorage::~ShapeSubpartStorage(
        hkpStorageExtendedMeshShape::ShapeSubpartStorage *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::ShapeSubpartStorage::`vftable;
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
      16 * v3);
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
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

