// File Line: 81
// RVA: 0xD15BB0
void __fastcall hkpStorageExtendedMeshShape::MeshSubpartStorage::~MeshSubpartStorage(hkpStorageExtendedMeshShape::MeshSubpartStorage *this)
{
  int v1; // er8
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v2; // rbx
  int v3; // edi
  hkStringPtr *v4; // rsi
  int v5; // er8
  int v6; // er8
  int v7; // er8
  int v8; // er8
  int v9; // er8
  int v10; // er8
  int v11; // er8

  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::MeshSubpartStorage::`vftable';
  v1 = this->m_materialIndices16.m_capacityAndFlags;
  v2 = this;
  this->m_materialIndices16.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_materialIndices16.m_data,
      2 * (v1 & 0x3FFFFFFF));
  v2->m_materialIndices16.m_data = 0i64;
  v2->m_materialIndices16.m_capacityAndFlags = 2147483648;
  v3 = v2->m_namedMaterials.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v2->m_namedMaterials.m_data[v3].m_name;
    do
    {
      hkStringPtr::~hkStringPtr(v4);
      v4 -= 2;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v2->m_namedMaterials.m_capacityAndFlags;
  v2->m_namedMaterials.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_namedMaterials.m_data,
      16 * v5);
  v2->m_namedMaterials.m_data = 0i64;
  v2->m_namedMaterials.m_capacityAndFlags = 2147483648;
  v6 = v2->m_materials.m_capacityAndFlags;
  v2->m_materials.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_materials.m_data,
      16 * v6);
  v2->m_materials.m_data = 0i64;
  v2->m_materials.m_capacityAndFlags = 2147483648;
  v7 = v2->m_materialIndices.m_capacityAndFlags;
  v2->m_materialIndices.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_materialIndices.m_data,
      v7 & 0x3FFFFFFF);
  v2->m_materialIndices.m_data = 0i64;
  v2->m_materialIndices.m_capacityAndFlags = 2147483648;
  v8 = v2->m_indices32.m_capacityAndFlags;
  v2->m_indices32.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_indices32.m_data,
      4 * v8);
  v2->m_indices32.m_data = 0i64;
  v2->m_indices32.m_capacityAndFlags = 2147483648;
  v9 = v2->m_indices16.m_capacityAndFlags;
  v2->m_indices16.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_indices16.m_data,
      2 * (v9 & 0x3FFFFFFF));
  v2->m_indices16.m_data = 0i64;
  v2->m_indices16.m_capacityAndFlags = 2147483648;
  v10 = v2->m_indices8.m_capacityAndFlags;
  v2->m_indices8.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_indices8.m_data,
      v10 & 0x3FFFFFFF);
  v2->m_indices8.m_data = 0i64;
  v2->m_indices8.m_capacityAndFlags = 2147483648;
  v11 = v2->m_vertices.m_capacityAndFlags;
  v2->m_vertices.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_vertices.m_data,
      16 * v11);
  v2->m_vertices.m_data = 0i64;
  v2->m_vertices.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 108
// RVA: 0xD15DE0
void __fastcall hkpStorageExtendedMeshShape::ShapeSubpartStorage::~ShapeSubpartStorage(hkpStorageExtendedMeshShape::ShapeSubpartStorage *this)
{
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::ShapeSubpartStorage::`vftable';
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
      16 * v3);
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
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

