// File Line: 17
// RVA: 0xD190F0
void __fastcall hkpStorageMeshShape::SubpartStorage::SubpartStorage(
        hkpStorageMeshShape::SubpartStorage *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::SubpartStorage::`vftable;
}

// File Line: 22
// RVA: 0xD19040
void __fastcall hkpStorageMeshShape::hkpStorageMeshShape(hkpStorageMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  int v3; // r8d
  __int64 v4; // r9
  __int64 v5; // r10
  hkpMeshShape::Subpart *m_data; // rax
  bool v7; // zf
  hkpStorageMeshShape::SubpartStorage *v8; // rdx
  const void *v9; // rcx
  const void *v10; // rcx

  hkpMeshShape::hkpMeshShape(this, flag);
  this->hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  this->hkpMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    v3 = 0;
    if ( this->m_subparts.m_size > 0 )
    {
      v4 = 0i64;
      v5 = 0i64;
      do
      {
        m_data = this->m_subparts.m_data;
        v7 = m_data[v5].m_stridingType.m_storage == 1;
        v8 = this->m_storage.m_data[v4];
        m_data[v5].m_vertexBase = v8->m_vertices.m_data;
        if ( v7 )
          v9 = v8->m_indices16.m_data;
        else
          v9 = v8->m_indices32.m_data;
        v7 = m_data[v5].m_materialIndexStridingType.m_storage == 1;
        m_data[v5].m_indexBase = v9;
        if ( v7 )
          v10 = v8->m_materialIndices.m_data;
        else
          v10 = v8->m_materialIndices16.m_data;
        m_data[v5].m_materialIndexBase = v10;
        ++v3;
        m_data[v5++].m_materialBase = (hkpMeshMaterial *)v8->m_materials.m_data;
        ++v4;
      }
      while ( v3 < this->m_subparts.m_size );
    }
  }
}

// File Line: 46
// RVA: 0xD18760
void __fastcall hkpStorageMeshShape::hkpStorageMeshShape(hkpStorageMeshShape *this, float radius, int numbits)
{
  hkpMeshShape::hkpMeshShape(this, radius, numbits);
  this->hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  this->hkpMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  this->m_storage.m_capacityAndFlags = 0x80000000;
  this->m_storage.m_data = 0i64;
  this->m_storage.m_size = 0;
}

// File Line: 50
// RVA: 0xD18900
void __fastcall hkpStorageMeshShape::~hkpStorageMeshShape(hkpStorageMeshShape *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  this->hkpMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  if ( this->m_storage.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_storage.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_storage.m_size );
  }
  m_capacityAndFlags = this->m_storage.m_capacityAndFlags;
  this->m_storage.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_storage.m_data,
      8 * m_capacityAndFlags);
  this->m_storage.m_data = 0i64;
  this->m_storage.m_capacityAndFlags = 0x80000000;
  hkpMeshShape::~hkpMeshShape(this);
}

// File Line: 58
// RVA: 0xD19110
__int64 __fastcall storageMeshShape_numIndices(int stride, int numTri)
{
  int v2; // ecx

  v2 = stride - 1;
  if ( !v2 )
    return (unsigned int)(numTri + 2);
  if ( v2 == 1 )
    return (unsigned int)(2 * numTri + 1);
  return (unsigned int)(3 * numTri);
}

// File Line: 72
// RVA: 0xD187B0
void __fastcall hkpStorageMeshShape::hkpStorageMeshShape(hkpStorageMeshShape *this, hkpMeshShape *mesh)
{
  int v4; // ebx
  int v5; // r8d
  __int64 m_size; // rax
  unsigned __int16 *m_data; // rcx
  __int64 v8; // rdx
  char *v9; // r8
  unsigned __int16 v10; // ax
  int v11; // [rsp+30h] [rbp+8h] BYREF

  hkpMeshShape::hkpMeshShape(this, mesh->m_radius, mesh->m_numBitsForSubpartIndex);
  v4 = 0;
  this->hkpMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShape};
  this->hkpMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageMeshShape::`vftable{for `hkpShapeContainer};
  this->m_storage.m_data = 0i64;
  this->m_storage.m_size = 0;
  this->m_storage.m_capacityAndFlags = 0x80000000;
  this->m_scaling = mesh->m_scaling;
  this->m_userData = mesh->m_userData;
  for ( this->m_disableWelding.m_bool = mesh->m_disableWelding.m_bool; v4 < mesh->m_subparts.m_size; ++v4 )
    hkpStorageMeshShape::addSubpart(this, &mesh->m_subparts.m_data[v4]);
  v5 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < mesh->m_weldingInfo.m_size )
  {
    if ( this->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * v5);
    v11 = 2 * mesh->m_weldingInfo.m_size;
    this->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       &v11);
    this->m_weldingInfo.m_capacityAndFlags = v11 / 2;
  }
  m_size = mesh->m_weldingInfo.m_size;
  m_data = this->m_weldingInfo.m_data;
  this->m_weldingInfo.m_size = m_size;
  v8 = m_size;
  if ( (int)m_size > 0 )
  {
    v9 = (char *)((char *)mesh->m_weldingInfo.m_data - (char *)m_data);
    do
    {
      v10 = *(unsigned __int16 *)((char *)m_data++ + (_QWORD)v9);
      *(m_data - 1) = v10;
      --v8;
    }
    while ( v8 );
  }
  this->m_weldingType.hkpMeshShape::m_storage = mesh->m_weldingType.m_storage;
}

// File Line: 115
// RVA: 0xD189D0
void __fastcall hkpStorageMeshShape::addSubpart(hkpStorageMeshShape *this, hkpMeshShape::Subpart *partIn)
{
  int v4; // esi
  hkpMeshShape::Subpart *v5; // rcx
  __int64 m_size; // rcx
  hkpMeshShape::Subpart *v7; // rdi
  _QWORD **Value; // rax
  __int64 v9; // rax
  hkpStorageMeshShape::SubpartStorage *v10; // r14
  hkArray<hkpStorageMeshShape::SubpartStorage *,hkContainerHeapAllocator> *p_m_storage; // r15
  hkpStorageMeshShape::SubpartStorage *v12; // r13
  __int64 v13; // rbp
  int v14; // r15d
  int v15; // r9d
  int v16; // eax
  int v17; // eax
  const float *m_vertexBase; // rcx
  __int64 v19; // rdx
  int i; // r8d
  const float *m_data; // rax
  int v22; // ecx
  unsigned __int64 m_indexStriding; // rax
  unsigned __int64 v24; // rax
  int v25; // eax
  __int64 v26; // r15
  int v27; // r9d
  int v28; // ecx
  int v29; // ebp
  int v30; // ecx
  unsigned __int16 *m_indexBase; // rcx
  unsigned __int16 *v32; // rdx
  int v33; // r8d
  _WORD *j; // r9
  unsigned __int64 v35; // rax
  int v36; // eax
  __int64 v37; // r15
  int v38; // r9d
  int v39; // ecx
  int v40; // ebp
  int v41; // ecx
  unsigned int *v42; // rcx
  unsigned int *v43; // rdx
  int v44; // r8d
  int m_flipAlternateTriangles; // eax
  char *m_materialIndexBase; // r15
  int v47; // eax
  int m_numTriangles; // r14d
  __int64 v49; // r15
  int v50; // r9d
  int v51; // eax
  int v52; // r8d
  char *v53; // rcx
  char *k; // rdx
  int v55; // eax
  int v56; // r15d
  __int64 v57; // rbp
  int v58; // r9d
  int v59; // eax
  int v60; // r8d
  __int64 v61; // rdx
  _WORD *m; // rcx
  int m_materialIndexStriding; // eax
  hkVector4f **p_m_materials; // r14
  int v65; // eax
  hkpMeshMaterial *v66; // r15
  hkVector4f *v67; // rax
  int m_numMaterials; // r15d
  __int64 v69; // rbp
  int v70; // r9d
  int v71; // eax
  hkpMeshMaterial *m_materialBase; // rcx
  __int64 v73; // rdx
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  if ( this->m_subparts.m_size == (this->m_subparts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_subparts.m_data, 80);
  v4 = 0;
  v5 = &this->m_subparts.m_data[this->m_subparts.m_size];
  if ( v5 )
  {
    v5->m_materialIndexStridingType.m_storage = 1;
    v5->m_materialIndexStriding = 0;
    v5->m_materialStriding = 0;
    v5->m_numMaterials = 1;
    v5->m_materialBase = 0i64;
    v5->m_materialIndexBase = 0i64;
    v5->m_triangleOffset = -1;
    v5->m_flipAlternateTriangles = 0;
  }
  m_size = this->m_subparts.m_size;
  this->m_subparts.m_size = m_size + 1;
  v7 = &this->m_subparts.m_data[m_size];
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  v10 = (hkpStorageMeshShape::SubpartStorage *)v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 0x1FFFF;
    *(_QWORD *)v9 = &hkpStorageMeshShape::SubpartStorage::`vftable;
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = 0x80000000;
    *(_QWORD *)(v9 + 32) = 0i64;
    *(_DWORD *)(v9 + 40) = 0;
    *(_DWORD *)(v9 + 44) = 0x80000000;
    *(_QWORD *)(v9 + 48) = 0i64;
    *(_DWORD *)(v9 + 56) = 0;
    *(_DWORD *)(v9 + 60) = 0x80000000;
    *(_QWORD *)(v9 + 64) = 0i64;
    *(_DWORD *)(v9 + 72) = 0;
    *(_DWORD *)(v9 + 76) = 0x80000000;
    *(_QWORD *)(v9 + 80) = 0i64;
    *(_DWORD *)(v9 + 88) = 0;
    *(_DWORD *)(v9 + 92) = 0x80000000;
    *(_QWORD *)(v9 + 96) = 0i64;
    *(_DWORD *)(v9 + 104) = 0;
    *(_DWORD *)(v9 + 108) = 0x80000000;
  }
  else
  {
    v10 = 0i64;
  }
  p_m_storage = &this->m_storage;
  if ( p_m_storage->m_size == (p_m_storage->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_storage->m_data, 8);
  p_m_storage->m_data[p_m_storage->m_size++] = v10;
  v12 = p_m_storage->m_data[p_m_storage->m_size - 1];
  v13 = v12->m_vertices.m_size;
  v14 = 3 * partIn->m_numVertices;
  v15 = v14 + v13;
  v16 = v12->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v14 + (int)v13 )
  {
    v17 = 2 * v16;
    if ( v15 < v17 )
      v15 = v17;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v12->m_vertices.m_data, v15, 4);
  }
  v12->m_vertices.m_size += v14;
  m_vertexBase = partIn->m_vertexBase;
  v19 = (__int64)&v12->m_vertices.m_data[v13];
  for ( i = 0; i < partIn->m_numVertices; m_vertexBase = (const float *)((char *)m_vertexBase + partIn->m_vertexStriding) )
  {
    ++i;
    v19 += 12i64;
    *(float *)(v19 - 12) = *m_vertexBase;
    *(float *)(v19 - 8) = m_vertexBase[1];
    *(float *)(v19 - 4) = m_vertexBase[2];
  }
  m_data = v12->m_vertices.m_data;
  v7->m_vertexStriding = 12;
  v22 = 3;
  v7->m_vertexBase = m_data;
  v7->m_numVertices = partIn->m_numVertices;
  m_indexStriding = partIn->m_indexStriding;
  if ( partIn->m_stridingType.m_storage == 1 )
  {
    v24 = m_indexStriding >> 1;
    if ( (int)v24 <= 2 )
      v22 = v24;
    v7->m_indexStriding = 2 * v22;
    v25 = storageMeshShape_numIndices(v24, partIn->m_numTriangles);
    v26 = v12->m_indices16.m_size;
    v27 = v26 + v25;
    v28 = v12->m_indices16.m_capacityAndFlags & 0x3FFFFFFF;
    v29 = v25;
    if ( v28 < (int)v26 + v25 )
    {
      v30 = 2 * v28;
      if ( v27 < v30 )
        v27 = v30;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v12->m_indices16.m_data,
        v27,
        2);
    }
    v12->m_indices16.m_size += v29;
    m_indexBase = (unsigned __int16 *)partIn->m_indexBase;
    v32 = &v12->m_indices16.m_data[v26];
    v33 = 0;
    for ( j = v32;
          v33 < partIn->m_numTriangles;
          m_indexBase = (unsigned __int16 *)((char *)m_indexBase + partIn->m_indexStriding) )
    {
      ++v33;
      *v32 = *m_indexBase;
      v32[1] = m_indexBase[1];
      v32[2] = m_indexBase[2];
      v32 = (unsigned __int16 *)((char *)v32 + v7->m_indexStriding);
    }
  }
  else
  {
    v35 = m_indexStriding >> 2;
    if ( (int)v35 <= 2 )
      v22 = v35;
    v7->m_indexStriding = 4 * v22;
    v36 = storageMeshShape_numIndices(v35, partIn->m_numTriangles);
    v37 = v12->m_indices32.m_size;
    v38 = v37 + v36;
    v39 = v12->m_indices32.m_capacityAndFlags & 0x3FFFFFFF;
    v40 = v36;
    if ( v39 < (int)v37 + v36 )
    {
      v41 = 2 * v39;
      if ( v38 < v41 )
        v38 = v41;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v12->m_indices32.m_data,
        v38,
        4);
    }
    v12->m_indices32.m_size += v40;
    v42 = (unsigned int *)partIn->m_indexBase;
    v43 = &v12->m_indices32.m_data[v37];
    v44 = 0;
    for ( j = v43; v44 < partIn->m_numTriangles; v42 = (unsigned int *)((char *)v42 + partIn->m_indexStriding) )
    {
      ++v44;
      *v43 = *v42;
      v43[1] = v42[1];
      v43[2] = v42[2];
      v43 = (unsigned int *)((char *)v43 + v7->m_indexStriding);
    }
  }
  v7->m_stridingType.m_storage = partIn->m_stridingType.m_storage;
  v7->m_numTriangles = partIn->m_numTriangles;
  m_flipAlternateTriangles = partIn->m_flipAlternateTriangles;
  v7->m_indexBase = j;
  v7->m_flipAlternateTriangles = m_flipAlternateTriangles;
  v7->m_materialIndexStridingType.m_storage = partIn->m_materialIndexStridingType.m_storage;
  m_materialIndexBase = (char *)partIn->m_materialIndexBase;
  if ( m_materialIndexBase )
  {
    if ( partIn->m_materialIndexStridingType.m_storage == 1 )
    {
      v47 = v12->m_materialIndices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( partIn->m_materialIndexStriding )
      {
        m_numTriangles = partIn->m_numTriangles;
        v49 = v12->m_materialIndices.m_size;
        v50 = m_numTriangles + v49;
        if ( v47 < m_numTriangles + (int)v49 )
        {
          v51 = 2 * v47;
          if ( v50 < v51 )
            v50 = v51;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v12->m_materialIndices.m_data,
            v50,
            1);
        }
        v12->m_materialIndices.m_size += m_numTriangles;
        v52 = 0;
        v53 = &v12->m_materialIndices.m_data[v49];
        v7->m_materialIndexBase = v53;
        for ( k = (char *)partIn->m_materialIndexBase; v52 < partIn->m_numTriangles; k += partIn->m_materialIndexStriding )
        {
          ++v52;
          *v53++ = *k;
        }
      }
      else
      {
        if ( v12->m_materialIndices.m_size == v47 )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v12->m_materialIndices.m_data,
            1);
        v12->m_materialIndices.m_data[v12->m_materialIndices.m_size++] = *m_materialIndexBase;
        v7->m_materialIndexBase = &v12->m_materialIndices.m_data[v12->m_materialIndices.m_size - 1];
      }
    }
    else
    {
      v55 = v12->m_materialIndices16.m_capacityAndFlags & 0x3FFFFFFF;
      if ( partIn->m_materialIndexStriding )
      {
        v56 = partIn->m_numTriangles;
        v57 = v12->m_materialIndices16.m_size;
        v58 = v56 + v57;
        if ( v55 < v56 + (int)v57 )
        {
          v59 = 2 * v55;
          if ( v58 < v59 )
            v58 = v59;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v12->m_materialIndices16.m_data,
            v58,
            2);
        }
        v12->m_materialIndices16.m_size += v56;
        v60 = 0;
        v61 = (__int64)&v12->m_materialIndices16.m_data[v57];
        v7->m_materialIndexBase = (const void *)v61;
        for ( m = partIn->m_materialIndexBase;
              v60 < partIn->m_numTriangles;
              m = (_WORD *)((char *)m + partIn->m_materialIndexStriding) )
        {
          ++v60;
          v61 += 2i64;
          *(_WORD *)(v61 - 2) = *m;
        }
      }
      else
      {
        if ( v12->m_materialIndices16.m_size == v55 )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v12->m_materialIndices16.m_data,
            2);
        v12->m_materialIndices16.m_data[v12->m_materialIndices16.m_size++] = *(_WORD *)m_materialIndexBase;
        v7->m_materialIndexBase = &v12->m_materialIndices16.m_data[v12->m_materialIndices16.m_size - 1];
      }
    }
    m_materialIndexStriding = partIn->m_materialIndexStriding;
    v7->m_materialIndexStriding = m_materialIndexStriding;
    if ( m_materialIndexStriding )
    {
      if ( v7->m_materialIndexStridingType.m_storage == 1 )
      {
        v7->m_materialIndexStriding = 1;
      }
      else if ( v7->m_materialIndexStridingType.m_storage == 2 )
      {
        v7->m_materialIndexStriding = 2;
      }
    }
  }
  else
  {
    v7->m_materialIndexBase = 0i64;
    v7->m_materialIndexStriding = 0;
  }
  if ( v7->m_materialIndexBase )
  {
    p_m_materials = (hkVector4f **)&v12->m_materials;
    v65 = v12->m_materials.m_capacityAndFlags & 0x3FFFFFFF;
    if ( partIn->m_materialStriding )
    {
      m_numMaterials = partIn->m_numMaterials;
      v69 = v12->m_materials.m_size;
      v70 = m_numMaterials + v69;
      if ( v65 < m_numMaterials + (int)v69 )
      {
        v71 = 2 * v65;
        if ( v70 < v71 )
          v70 = v71;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v12->m_materials.m_data,
          v70,
          4);
      }
      v12->m_materials.m_size += m_numMaterials;
      m_materialBase = partIn->m_materialBase;
      v73 = (__int64)*p_m_materials + 4 * v69;
      if ( partIn->m_numMaterials > 0 )
      {
        do
        {
          ++v4;
          v73 += 4i64;
          *(hkpMeshMaterial *)(v73 - 4) = (hkpMeshMaterial)m_materialBase->m_filterInfo;
          m_materialBase = (hkpMeshMaterial *)((char *)m_materialBase + partIn->m_materialStriding);
        }
        while ( v4 < partIn->m_numMaterials );
      }
      v7->m_materialStriding = 8;
      v7->m_numMaterials = partIn->m_numMaterials;
      v67 = *p_m_materials;
    }
    else
    {
      v66 = partIn->m_materialBase;
      if ( v12->m_materials.m_size == v65 )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v12->m_materials.m_data, 4);
      LODWORD((*p_m_materials)->m_quad.m128_f32[v12->m_materials.m_size++]) = (hkpMeshMaterial)v66->m_filterInfo;
      v7->m_materialStriding = 0;
      v7->m_numMaterials = 1;
      v67 = *p_m_materials;
    }
  }
  else
  {
    v67 = &aabbOut;
    v7->m_numMaterials = 1;
    v7->m_materialStriding = 0;
    v7->m_materialIndexBase = &aabbOut;
  }
  v7->m_materialBase = (hkpMeshMaterial *)v67;
  v7->m_triangleOffset = partIn->m_triangleOffset;
}

