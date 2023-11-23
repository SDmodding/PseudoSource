// File Line: 21
// RVA: 0xD15B50
void __fastcall hkpStorageExtendedMeshShape::MeshSubpartStorage::MeshSubpartStorage(
        hkpStorageExtendedMeshShape::MeshSubpartStorage *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::MeshSubpartStorage::`vftable;
}

// File Line: 27
// RVA: 0xD15B70
void __fastcall hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage(
        hkpStorageExtendedMeshShape::ShapeSubpartStorage *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::ShapeSubpartStorage::`vftable;
}

// File Line: 32
// RVA: 0xD15990
void __fastcall hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(
        hkpStorageExtendedMeshShape *this,
        hkFinishLoadedObjectFlag flag)
{
  int v3; // ebp
  int v4; // r14d
  __int64 v5; // rsi
  __int64 v6; // r15
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v7; // rcx
  hkpExtendedMeshShape::TrianglesSubpart *v8; // rdi
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v9; // rcx
  char m_storage; // al
  const void *m_data; // rax
  const void *v12; // rax
  hkpMeshMaterial *v13; // rax
  __int64 v14; // rsi
  __int64 v15; // r14
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v16; // rcx
  hkpExtendedMeshShape::ShapesSubpart *v17; // rdi
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v18; // rcx
  const void *v19; // rax

  hkpExtendedMeshShape::hkpExtendedMeshShape(this, flag);
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    v3 = 0;
    v4 = 0;
    if ( this->m_trianglesSubparts.m_size > 0 )
    {
      v5 = 0i64;
      v6 = 0i64;
      do
      {
        v7 = this->m_meshstorage.m_data[v5];
        v8 = &this->m_trianglesSubparts.m_data[v6];
        if ( v7 )
          hkpStorageExtendedMeshShape::MeshSubpartStorage::MeshSubpartStorage(v7, flag);
        v9 = this->m_meshstorage.m_data[v5];
        v8->m_vertexBase = v9->m_vertices.m_data->m_quad.m128_f32;
        m_storage = v8->m_stridingType.m_storage;
        if ( m_storage == 1 )
        {
          m_data = v9->m_indices8.m_data;
        }
        else if ( m_storage == 2 )
        {
          m_data = v9->m_indices16.m_data;
        }
        else
        {
          m_data = v9->m_indices32.m_data;
        }
        v8->m_indexBase = m_data;
        if ( (v8->m_typeAndFlags & 6) == 2 )
          v12 = v9->m_materialIndices.m_data;
        else
          v12 = v9->m_materialIndices16.m_data;
        v8->m_materialIndexBase = v12;
        if ( v9->m_namedMaterials.m_size )
          v13 = v9->m_namedMaterials.m_data;
        else
          v13 = v9->m_materials.m_data;
        ++v4;
        v8->m_materialStriding = 16;
        v8->m_materialBase = v13;
        ++v6;
        ++v5;
      }
      while ( v4 < this->m_trianglesSubparts.m_size );
    }
    if ( this->m_shapesSubparts.m_size > 0 )
    {
      v14 = 0i64;
      v15 = 0i64;
      do
      {
        v16 = this->m_shapestorage.m_data[v14];
        v17 = &this->m_shapesSubparts.m_data[v15];
        if ( v16 )
          hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage(v16, flag);
        v18 = this->m_shapestorage.m_data[v14];
        if ( (v17->m_typeAndFlags & 6) == 2 )
          v19 = v18->m_materialIndices.m_data;
        else
          v19 = v18->m_materialIndices16.m_data;
        v17->m_materialIndexBase = v19;
        ++v3;
        ++v15;
        ++v14;
        v17->m_materialBase = v18->m_materials.m_data;
      }
      while ( v3 < this->m_shapesSubparts.m_size );
    }
  }
}

// File Line: 106
// RVA: 0xD146D0
void __fastcall hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(
        hkpStorageExtendedMeshShape *this,
        float radius,
        int numbits)
{
  hkpExtendedMeshShape::hkpExtendedMeshShape(this, radius, numbits);
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShapeContainer};
  this->m_meshstorage.m_capacityAndFlags = 0x80000000;
  this->m_meshstorage.m_data = 0i64;
  this->m_meshstorage.m_size = 0;
  this->m_shapestorage.m_data = 0i64;
  this->m_shapestorage.m_size = 0;
  this->m_shapestorage.m_capacityAndFlags = 0x80000000;
}

// File Line: 110
// RVA: 0xD14910
void __fastcall hkpStorageExtendedMeshShape::~hkpStorageExtendedMeshShape(hkpStorageExtendedMeshShape *this)
{
  int v2; // esi
  __int64 v3; // rdi
  int v4; // edi
  hkpExtendedMeshShape::ShapesSubpart *v5; // rsi
  int v6; // edi
  __int64 v7; // rsi
  int m_capacityAndFlags; // r8d
  int v9; // r8d

  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShape};
  v2 = 0;
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShapeContainer};
  if ( this->m_meshstorage.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_meshstorage.m_data[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_meshstorage.m_size );
  }
  v4 = this->m_shapesSubparts.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->m_shapesSubparts.m_data[v4];
    do
    {
      hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart(v5--);
      --v4;
    }
    while ( v4 >= 0 );
  }
  this->m_shapesSubparts.m_size = 0;
  v6 = 0;
  if ( this->m_shapestorage.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_shapestorage.m_data[v7]);
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_shapestorage.m_size );
  }
  this->m_materialClass = &hkpStorageExtendedMeshShapeMaterialClass;
  m_capacityAndFlags = this->m_shapestorage.m_capacityAndFlags;
  this->m_shapestorage.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_shapestorage.m_data,
      8 * m_capacityAndFlags);
  this->m_shapestorage.m_data = 0i64;
  this->m_shapestorage.m_capacityAndFlags = 0x80000000;
  v9 = this->m_meshstorage.m_capacityAndFlags;
  this->m_meshstorage.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_meshstorage.m_data,
      8 * v9);
  this->m_meshstorage.m_data = 0i64;
  this->m_meshstorage.m_capacityAndFlags = 0x80000000;
  hkpExtendedMeshShape::~hkpExtendedMeshShape(this);
}

// File Line: 130
// RVA: 0xD15B90
__int64 __fastcall numIndices(int stride, int numTri)
{
  int v2; // ecx

  v2 = stride - 1;
  if ( !v2 )
    return (unsigned int)(numTri + 2);
  if ( v2 == 1 )
    return (unsigned int)(2 * numTri + 1);
  return (unsigned int)(4 * numTri);
}

// File Line: 144
// RVA: 0xD14740
void __fastcall hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(
        hkpStorageExtendedMeshShape *this,
        hkpExtendedMeshShape *mesh)
{
  int v4; // esi
  int v5; // ebp
  int v6; // r8d
  __int64 m_size; // rax
  unsigned __int16 *m_data; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  unsigned __int16 v11; // ax
  int v12; // [rsp+30h] [rbp+8h] BYREF

  hkpExtendedMeshShape::hkpExtendedMeshShape(this, mesh->m_triangleRadius, mesh->m_numBitsForSubpartIndex);
  v4 = 0;
  v5 = 0;
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpExtendedMeshShape::hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable{for `hkpShapeContainer};
  this->m_meshstorage.m_data = 0i64;
  this->m_meshstorage.m_size = 0;
  this->m_meshstorage.m_capacityAndFlags = 0x80000000;
  this->m_shapestorage.m_data = 0i64;
  this->m_shapestorage.m_size = 0;
  this->m_shapestorage.m_capacityAndFlags = 0x80000000;
  this->m_userData = mesh->m_userData;
  for ( this->m_disableWelding.m_bool = mesh->m_disableWelding.m_bool; v5 < mesh->m_trianglesSubparts.m_size; ++v5 )
    hkpStorageExtendedMeshShape::addTrianglesSubpart(this, &mesh->m_trianglesSubparts.m_data[v5]);
  if ( mesh->m_shapesSubparts.m_size > 0 )
  {
    do
      hkpStorageExtendedMeshShape::addShapesSubpart(this, &mesh->m_shapesSubparts.m_data[v4++]);
    while ( v4 < mesh->m_shapesSubparts.m_size );
  }
  v6 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < mesh->m_weldingInfo.m_size )
  {
    if ( this->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * v6);
    v12 = 2 * mesh->m_weldingInfo.m_size;
    this->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       &v12);
    this->m_weldingInfo.m_capacityAndFlags = v12 / 2;
  }
  m_size = mesh->m_weldingInfo.m_size;
  m_data = this->m_weldingInfo.m_data;
  this->m_weldingInfo.m_size = m_size;
  v9 = m_size;
  if ( (int)m_size > 0 )
  {
    v10 = (char *)((char *)mesh->m_weldingInfo.m_data - (char *)m_data);
    do
    {
      v11 = *(unsigned __int16 *)((char *)m_data++ + (_QWORD)v10);
      *(m_data - 1) = v11;
      --v9;
    }
    while ( v9 );
  }
  this->m_weldingType.m_storage = mesh->m_weldingType.m_storage;
  hkpExtendedMeshShape::recalcAabbExtents(this);
}

// File Line: 197
// RVA: 0xD14AA0
void __fastcall hkpStorageExtendedMeshShape::addTrianglesSubpart(
        hkpStorageExtendedMeshShape *this,
        hkpExtendedMeshShape::TrianglesSubpart *partIn)
{
  hkpStorageExtendedMeshShape *v3; // r12
  hkQsTransformf *v4; // rax
  hkpExtendedMeshShape::TrianglesSubpart *v5; // rdi
  _QWORD **Value; // rax
  __int64 v7; // rax
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v8; // r14
  int m_numVertices; // r15d
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v10; // r13
  __int64 m_size; // rbp
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  const float *m_vertexBase; // rcx
  int v16; // r8d
  __int64 i; // rdx
  const float *m128_f32; // rax
  char m_storage; // al
  signed __int16 m_indexStriding; // ax
  __int16 v21; // r8
  int v22; // eax
  __int64 v23; // r14
  int v24; // r9d
  int v25; // ecx
  unsigned int v26; // r15d
  int v27; // ecx
  char *v28; // r14
  char *m_indexBase; // rcx
  char *v30; // r8
  int j; // edx
  bool v32; // zf
  unsigned __int16 v33; // ax
  __int16 v34; // ax
  __int16 v35; // r8
  int v36; // eax
  __int64 v37; // r12
  int v38; // r9d
  int v39; // ecx
  int v40; // r15d
  int v41; // ecx
  unsigned __int16 *m_data; // rax
  unsigned __int16 *v43; // r14
  unsigned __int16 *v44; // rcx
  int k; // edx
  __int16 v46; // ax
  __int16 v47; // cx
  int v48; // eax
  int sizeElem; // r8d
  __int64 v50; // r15
  int v51; // r9d
  int v52; // ecx
  int v53; // ebp
  int v54; // ecx
  unsigned int *v55; // rax
  unsigned int *v56; // r14
  unsigned int *v57; // rcx
  int m; // edx
  char m_flipAlternateTriangles; // al
  char *m_materialIndexBase; // r15
  int v61; // eax
  int m_numTriangleShapes; // r14d
  __int64 v63; // r15
  int v64; // r9d
  int v65; // eax
  int v66; // r8d
  char *v67; // rcx
  char *n; // rdx
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_materialIndices16; // r14
  int v70; // eax
  int v71; // r15d
  __int64 v72; // rbp
  int v73; // r9d
  int v74; // eax
  int v75; // r8d
  __int64 v76; // rdx
  _WORD *ii; // rcx
  unsigned __int16 m_materialIndexStriding; // ax
  int v79; // r15d
  int m_capacityAndFlags; // eax
  hkArray<hkpNamedMeshMaterial,hkContainerHeapAllocator> *p_m_namedMaterials; // r12
  __int64 v82; // r13
  int v83; // eax
  int v84; // r9d
  int v85; // eax
  __int64 v86; // rbp
  __int64 v87; // r14
  hkpMeshMaterial *m_materialBase; // r15
  int v89; // ebp
  __int64 v90; // r14
  hkStringPtr *v91; // rcx
  hkStringPtr *v92; // rcx
  __int64 v93; // rbp
  const void **p_m_data; // r14
  int v95; // r9d
  int v96; // eax
  int v97; // eax
  hkpMeshMaterial *v98; // rdx
  int v99; // r8d
  __int64 v100; // r9
  __int64 v101; // rcx
  hkVector4f v102; // xmm7
  __m128 v103; // xmm6
  __m128 v104; // xmm7
  int v105; // r8d
  __m128 v106; // xmm0
  __m128 v107; // xmm7
  __m128 v108; // xmm6
  hkAabb out; // [rsp+30h] [rbp-78h] BYREF
  hkResult result; // [rsp+B8h] [rbp+10h] BYREF

  v3 = this;
  v4 = (hkQsTransformf *)hkpExtendedMeshShape::expandOneTriangleSubparts(this);
  v4->m_translation.m_quad.m128_u64[0] = *(_QWORD *)&partIn->m_typeAndFlags;
  v5 = (hkpExtendedMeshShape::TrianglesSubpart *)v4;
  v4->m_translation.m_quad.m128_u64[1] = (unsigned __int64)partIn->m_materialIndexBase;
  v4->m_rotation.m_vec.m_quad.m128_u64[0] = (unsigned __int64)partIn->m_materialBase;
  v4->m_rotation.m_vec.m_quad.m128_u64[1] = partIn->m_userData;
  v4->m_scale.m_quad.m128_i32[0] = partIn->m_numTriangleShapes;
  v4->m_scale.m_quad.m128_u64[1] = (unsigned __int64)partIn->m_vertexBase;
  v4[1].m_translation.m_quad.m128_i32[0] = partIn->m_numVertices;
  v4[1].m_translation.m_quad.m128_u64[1] = (unsigned __int64)partIn->m_indexBase;
  v4[1].m_rotation.m_vec.m_quad.m128_i16[0] = partIn->m_vertexStriding;
  v4[1].m_rotation.m_vec.m_quad.m128_i32[1] = partIn->m_triangleOffset;
  v4[1].m_rotation.m_vec.m_quad.m128_i16[4] = partIn->m_indexStriding;
  v4[1].m_rotation.m_vec.m_quad.m128_i8[10] = partIn->m_stridingType.m_storage;
  v4[1].m_rotation.m_vec.m_quad.m128_i8[11] = partIn->m_flipAlternateTriangles;
  v4[1].m_scale = partIn->m_extrusion;
  v4[2] = partIn->m_transform;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
  v8 = (hkpStorageExtendedMeshShape::MeshSubpartStorage *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkpStorageExtendedMeshShape::MeshSubpartStorage::`vftable;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 0x80000000;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 0x80000000;
    *(_QWORD *)(v7 + 48) = 0i64;
    *(_DWORD *)(v7 + 56) = 0;
    *(_DWORD *)(v7 + 60) = 0x80000000;
    *(_QWORD *)(v7 + 64) = 0i64;
    *(_DWORD *)(v7 + 72) = 0;
    *(_DWORD *)(v7 + 76) = 0x80000000;
    *(_QWORD *)(v7 + 80) = 0i64;
    *(_DWORD *)(v7 + 88) = 0;
    *(_DWORD *)(v7 + 92) = 0x80000000;
    *(_QWORD *)(v7 + 96) = 0i64;
    *(_DWORD *)(v7 + 104) = 0;
    *(_DWORD *)(v7 + 108) = 0x80000000;
    *(_QWORD *)(v7 + 112) = 0i64;
    *(_DWORD *)(v7 + 120) = 0;
    *(_DWORD *)(v7 + 124) = 0x80000000;
    *(_QWORD *)(v7 + 128) = 0i64;
    *(_DWORD *)(v7 + 136) = 0;
    *(_DWORD *)(v7 + 140) = 0x80000000;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v3->m_meshstorage.m_size == (v3->m_meshstorage.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v3->m_meshstorage.m_data, 8);
  v3->m_meshstorage.m_data[v3->m_meshstorage.m_size++] = v8;
  m_numVertices = partIn->m_numVertices;
  v10 = v3->m_meshstorage.m_data[v3->m_meshstorage.m_size - 1];
  m_size = v10->m_vertices.m_size;
  v12 = m_numVertices + m_size;
  v13 = v10->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < m_numVertices + (int)m_size )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v10->m_vertices.m_data, v12, 16);
  }
  v10->m_vertices.m_size += m_numVertices;
  m_vertexBase = partIn->m_vertexBase;
  v16 = 0;
  for ( i = (__int64)&v10->m_vertices.m_data[m_size];
        v16 < partIn->m_numVertices;
        m_vertexBase = (const float *)((char *)m_vertexBase + partIn->m_vertexStriding) )
  {
    ++v16;
    i += 16i64;
    *(__m128 *)(i - 16) = _mm_unpacklo_ps(
                            _mm_unpacklo_ps(
                              (__m128)*(unsigned int *)m_vertexBase,
                              (__m128)*((unsigned int *)m_vertexBase + 2)),
                            _mm_unpacklo_ps((__m128)*((unsigned int *)m_vertexBase + 1), (__m128)0i64));
  }
  m128_f32 = v10->m_vertices.m_data->m_quad.m128_f32;
  v5->m_vertexStriding = 16;
  v5->m_vertexBase = m128_f32;
  v5->m_numVertices = partIn->m_numVertices;
  m_storage = partIn->m_stridingType.m_storage;
  if ( m_storage == 1 )
  {
    m_indexStriding = partIn->m_indexStriding;
    v21 = m_indexStriding;
    if ( m_indexStriding > 2 )
      v21 = 4;
    v5->m_indexStriding = v21;
    v22 = numIndices(m_indexStriding, partIn->m_numTriangleShapes);
    v23 = v10->m_indices8.m_size;
    v24 = v23 + v22;
    v25 = v10->m_indices8.m_capacityAndFlags & 0x3FFFFFFF;
    v26 = v22;
    if ( v25 >= (int)v23 + v22 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v27 = 2 * v25;
      if ( v24 < v27 )
        v24 = v27;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v10->m_indices8.m_data, v24, 1);
    }
    v28 = &v10->m_indices8.m_data[v23];
    v10->m_indices8.m_size += v26;
    hkString::memSet(v28, 0, v26);
    m_indexBase = (char *)partIn->m_indexBase;
    v30 = v28;
    for ( j = 0; j < partIn->m_numTriangleShapes; m_indexBase += partIn->m_indexStriding )
    {
      ++j;
      *v28 = *m_indexBase;
      v28[1] = m_indexBase[1];
      v28[2] = m_indexBase[2];
      v28 += v5->m_indexStriding;
    }
  }
  else
  {
    v32 = m_storage == 2;
    v33 = partIn->m_indexStriding;
    if ( v32 )
    {
      v34 = v33 >> 1;
      v35 = v34;
      if ( v34 > 2 )
        v35 = 4;
      v5->m_indexStriding = 2 * v35;
      v36 = numIndices(v34, partIn->m_numTriangleShapes);
      v37 = v10->m_indices16.m_size;
      v38 = v37 + v36;
      v39 = v10->m_indices16.m_capacityAndFlags & 0x3FFFFFFF;
      v40 = v36;
      if ( v39 >= (int)v37 + v36 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v41 = 2 * v39;
        if ( v38 < v41 )
          v38 = v41;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v10->m_indices16.m_data,
          v38,
          2);
      }
      m_data = v10->m_indices16.m_data;
      v10->m_indices16.m_size += v40;
      v43 = &m_data[v37];
      hkString::memSet(v43, 0, 2 * v40);
      v44 = (unsigned __int16 *)partIn->m_indexBase;
      v30 = (char *)v43;
      for ( k = 0; k < partIn->m_numTriangleShapes; v44 = (unsigned __int16 *)((char *)v44 + partIn->m_indexStriding) )
      {
        ++k;
        *v43 = *v44;
        v43[1] = v44[1];
        v43[2] = v44[2];
        v43 = (unsigned __int16 *)((char *)v43 + v5->m_indexStriding);
      }
      v3 = this;
    }
    else
    {
      v46 = v33 >> 2;
      v47 = v46;
      if ( v46 > 2 )
        v47 = 4;
      v5->m_indexStriding = 4 * v47;
      v48 = numIndices(v46, partIn->m_numTriangleShapes);
      v50 = v10->m_indices32.m_size;
      v51 = v50 + v48;
      v52 = v10->m_indices32.m_capacityAndFlags & 0x3FFFFFFF;
      v53 = v48;
      if ( v52 >= (int)v50 + v48 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v54 = 2 * v52;
        if ( v51 < v54 )
          v51 = v54;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v10->m_indices32.m_data,
          v51,
          sizeElem);
      }
      v55 = v10->m_indices32.m_data;
      v10->m_indices32.m_size += v53;
      v56 = &v55[v50];
      hkString::memSet(v56, 0, 4 * v53);
      v57 = (unsigned int *)partIn->m_indexBase;
      v30 = (char *)v56;
      for ( m = 0; m < partIn->m_numTriangleShapes; v57 = (unsigned int *)((char *)v57 + partIn->m_indexStriding) )
      {
        ++m;
        *v56 = *v57;
        v56[1] = v57[1];
        v56[2] = v57[2];
        v56 = (unsigned int *)((char *)v56 + v5->m_indexStriding);
      }
    }
  }
  v5->m_stridingType.m_storage = partIn->m_stridingType.m_storage;
  v5->m_numTriangleShapes = partIn->m_numTriangleShapes;
  m_flipAlternateTriangles = partIn->m_flipAlternateTriangles;
  v5->m_indexBase = v30;
  v5->m_flipAlternateTriangles = m_flipAlternateTriangles;
  v5->m_typeAndFlags ^= (partIn->m_typeAndFlags ^ v5->m_typeAndFlags) & 6;
  m_materialIndexBase = (char *)partIn->m_materialIndexBase;
  if ( m_materialIndexBase )
  {
    if ( (partIn->m_typeAndFlags & 6) == 2 )
    {
      v61 = v10->m_materialIndices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( partIn->m_materialIndexStriding )
      {
        m_numTriangleShapes = partIn->m_numTriangleShapes;
        v63 = v10->m_materialIndices.m_size;
        v64 = m_numTriangleShapes + v63;
        if ( v61 < m_numTriangleShapes + (int)v63 )
        {
          v65 = 2 * v61;
          if ( v64 < v65 )
            v64 = v65;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v10->m_materialIndices.m_data,
            v64,
            1);
        }
        v10->m_materialIndices.m_size += m_numTriangleShapes;
        v66 = 0;
        v67 = &v10->m_materialIndices.m_data[v63];
        v5->m_materialIndexBase = v67;
        for ( n = (char *)partIn->m_materialIndexBase;
              v66 < partIn->m_numTriangleShapes;
              n += partIn->m_materialIndexStriding )
        {
          ++v66;
          *v67++ = *n;
        }
      }
      else
      {
        if ( v10->m_materialIndices.m_size == v61 )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v10->m_materialIndices.m_data,
            1);
        v10->m_materialIndices.m_data[v10->m_materialIndices.m_size++] = *m_materialIndexBase;
        v5->m_materialIndexBase = &v10->m_materialIndices.m_data[v10->m_materialIndices.m_size - 1];
      }
    }
    else
    {
      p_m_materialIndices16 = &v10->m_materialIndices16;
      v70 = v10->m_materialIndices16.m_capacityAndFlags & 0x3FFFFFFF;
      if ( partIn->m_materialIndexStriding )
      {
        v71 = partIn->m_numTriangleShapes;
        v72 = v10->m_materialIndices16.m_size;
        v73 = v71 + v72;
        if ( v70 < v71 + (int)v72 )
        {
          v74 = 2 * v70;
          if ( v73 < v74 )
            v73 = v74;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v10->m_materialIndices16.m_data,
            v73,
            2);
        }
        v10->m_materialIndices16.m_size += v71;
        v75 = 0;
        v76 = (__int64)&p_m_materialIndices16->m_data[v72];
        v5->m_materialIndexBase = (const void *)v76;
        for ( ii = partIn->m_materialIndexBase;
              v75 < partIn->m_numTriangleShapes;
              ii = (_WORD *)((char *)ii + partIn->m_materialIndexStriding) )
        {
          ++v75;
          v76 += 2i64;
          *(_WORD *)(v76 - 2) = *ii;
        }
      }
      else
      {
        if ( v10->m_materialIndices16.m_size == v70 )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v10->m_materialIndices16.m_data,
            2);
        p_m_materialIndices16->m_data[v10->m_materialIndices16.m_size++] = *(_WORD *)m_materialIndexBase;
        v5->m_materialIndexBase = &p_m_materialIndices16->m_data[v10->m_materialIndices16.m_size - 1];
      }
    }
    m_materialIndexStriding = partIn->m_materialIndexStriding;
    v5->m_materialIndexStriding = m_materialIndexStriding;
    if ( m_materialIndexStriding )
    {
      if ( ((v5->m_typeAndFlags >> 1) & 3) == 1 )
      {
        v5->m_materialIndexStriding = 1;
      }
      else if ( ((v5->m_typeAndFlags >> 1) & 3) == 2 )
      {
        v5->m_materialIndexStriding = 2;
      }
    }
  }
  else
  {
    v5->m_materialIndexBase = 0i64;
    v5->m_materialIndexStriding = 0;
  }
  if ( v5->m_materialIndexBase )
  {
    v79 = partIn->m_typeAndFlags >> 3;
    if ( v3->m_materialClass == &hkpNamedMeshMaterialClass )
    {
      m_capacityAndFlags = v10->m_namedMaterials.m_capacityAndFlags;
      p_m_namedMaterials = &v10->m_namedMaterials;
      v82 = v10->m_namedMaterials.m_size;
      v83 = m_capacityAndFlags & 0x3FFFFFFF;
      v84 = v79 + v82;
      if ( v83 >= v79 + (int)v82 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v85 = 2 * v83;
        if ( v84 < v85 )
          v84 = v85;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_namedMaterials->m_data,
          v84,
          16);
      }
      v86 = (unsigned int)v79;
      v87 = (__int64)&p_m_namedMaterials->m_data[p_m_namedMaterials->m_size];
      if ( v79 > 0 )
      {
        do
        {
          if ( v87 )
          {
            hkStringPtr::hkStringPtr((hkStringPtr *)(v87 + 8), "Default");
            *(_DWORD *)v87 = 0;
          }
          v87 += 16i64;
          --v86;
        }
        while ( v86 );
      }
      p_m_namedMaterials->m_size += v79;
      m_materialBase = partIn->m_materialBase;
      v89 = 0;
      v90 = (__int64)&p_m_namedMaterials->m_data[v82];
      if ( (partIn->m_typeAndFlags & 0xFFF8) != 0 )
      {
        do
        {
          if ( v90 )
          {
            hkStringPtr::hkStringPtr((hkStringPtr *)(v90 + 8), "Default");
            *(_DWORD *)v90 = 0;
            v91 = (hkStringPtr *)v90;
          }
          else
          {
            v91 = 0i64;
          }
          v92 = v91 + 1;
          LODWORD(v92[-1].m_stringAndFlag) = (hkpMeshMaterial)m_materialBase->m_filterInfo;
          hkStringPtr::operator=(v92, (hkStringPtr *)&m_materialBase[2]);
          m_materialBase = (hkpMeshMaterial *)((char *)m_materialBase + partIn->m_materialStriding);
          ++v89;
          v90 += 16i64;
        }
        while ( v89 < partIn->m_typeAndFlags >> 3 );
      }
      v5->m_materialBase = p_m_namedMaterials->m_data;
      if ( partIn->m_materialStriding )
      {
        v5->m_materialStriding = 16;
LABEL_104:
        v5->m_typeAndFlags = partIn->m_typeAndFlags ^ (partIn->m_typeAndFlags ^ v5->m_typeAndFlags) & 7;
        goto LABEL_106;
      }
    }
    else
    {
      v93 = v10->m_materials.m_size;
      p_m_data = (const void **)&v10->m_materials.m_data;
      v95 = v79 + v93;
      v96 = v10->m_materials.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v96 < v79 + (int)v93 )
      {
        v97 = 2 * v96;
        if ( v95 < v97 )
          v95 = v97;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_data, v95, 16);
      }
      v10->m_materials.m_size += v79;
      v98 = partIn->m_materialBase;
      v99 = 0;
      v100 = (__int64)*p_m_data + 16 * v93;
      if ( (partIn->m_typeAndFlags & 0xFFF8) != 0 )
      {
        do
        {
          v101 = v100 + 16i64 * v99;
          if ( v101 )
          {
            *(_QWORD *)v101 = 0i64;
            *(_QWORD *)(v101 + 8) = 0i64;
          }
          else
          {
            v101 = 0i64;
          }
          v32 = v3->m_materialClass == &hkpStorageExtendedMeshShapeMaterialClass;
          *(hkpMeshMaterial *)v101 = (hkpMeshMaterial)v98->m_filterInfo;
          if ( v32 )
          {
            *(_WORD *)(v101 + 4) = v98[1].m_filterInfo;
            *(_WORD *)(v101 + 6) = HIWORD(v98[1].m_filterInfo);
            *(_QWORD *)(v101 + 8) = *(_QWORD *)&v98[2].m_filterInfo;
          }
          else
          {
            *(_DWORD *)(v101 + 4) = 1065353216;
            *(_QWORD *)(v101 + 8) = 0i64;
          }
          ++v99;
          v98 = (hkpMeshMaterial *)((char *)v98 + partIn->m_materialStriding);
        }
        while ( v99 < partIn->m_typeAndFlags >> 3 );
      }
      v5->m_materialBase = (hkpMeshMaterial *)*p_m_data;
      if ( partIn->m_materialStriding )
      {
        v5->m_materialStriding = 16;
        goto LABEL_104;
      }
    }
    v5->m_typeAndFlags &= 7u;
    v5->m_typeAndFlags |= 8u;
    v5->m_materialStriding = 0;
  }
LABEL_106:
  v102.m_quad = (__m128)this->m_aabbHalfExtents;
  v103 = _mm_sub_ps(this->m_aabbCenter.m_quad, v102.m_quad);
  v104 = _mm_add_ps(v102.m_quad, this->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v5, &out);
  v105 = this->m_trianglesSubparts.m_size - 1;
  v106 = _mm_shuffle_ps((__m128)LODWORD(this->m_triangleRadius), (__m128)LODWORD(this->m_triangleRadius), 0);
  v107 = _mm_max_ps(v104, _mm_add_ps(out.m_max.m_quad, v106));
  v108 = _mm_min_ps(v103, _mm_sub_ps(out.m_min.m_quad, v106));
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v107, v108), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v107, v108), (__m128)xmmword_141A711B0);
  this->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(this, v5, v105);
}edNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(this, v5, v105);
}

// File Line: 470
// RVA: 0xD154C0
__int64 __fastcall hkpStorageExtendedMeshShape::addShapesSubpart(
        hkpStorageExtendedMeshShape *this,
        hkpExtendedMeshShape::ShapesSubpart *partIn)
{
  hkpExtendedMeshShape::ShapesSubpart *v4; // rsi
  _QWORD **Value; // rax
  __int64 v6; // rax
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v7; // r14
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v8; // r15
  char *m_materialIndexBase; // r12
  int v10; // eax
  __int64 m_size; // r14
  __int64 v12; // r12
  int v13; // r9d
  int v14; // eax
  __int64 v15; // rcx
  char *v16; // r8
  char *v17; // rdx
  int v18; // eax
  __int64 v19; // rbp
  __int64 v20; // r12
  int v21; // r9d
  int v22; // eax
  __int64 v23; // rcx
  __int64 v24; // r8
  _WORD *v25; // rdx
  unsigned __int16 m_materialIndexStriding; // ax
  int m_capacityAndFlags; // eax
  hkArray<hkpStorageExtendedMeshShape::Material,hkContainerHeapAllocator> *p_m_materials; // r14
  __int64 v29; // r15
  int v30; // ebp
  int v31; // eax
  int v32; // r9d
  int v33; // eax
  hkpMeshMaterial *m_materialBase; // rdx
  int v35; // r8d
  __int64 v36; // r9
  __int64 v37; // rax
  bool v38; // zf
  unsigned __int16 m_typeAndFlags; // ax
  hkVector4f v40; // xmm7
  __m128 v41; // xmm6
  __m128 v42; // xmm7
  __m128 v43; // xmm7
  __m128 v44; // xmm6
  hkAabb out; // [rsp+30h] [rbp-68h] BYREF
  hkResult result; // [rsp+A0h] [rbp+8h] BYREF

  v4 = hkpExtendedMeshShape::expandOneShapesSubparts(this);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  v7 = (hkpStorageExtendedMeshShape::ShapeSubpartStorage *)v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 8) = 0x1FFFF;
    *(_QWORD *)v6 = &hkpStorageExtendedMeshShape::ShapeSubpartStorage::`vftable;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_DWORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 28) = 0x80000000;
    *(_QWORD *)(v6 + 32) = 0i64;
    *(_DWORD *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 44) = 0x80000000;
    *(_QWORD *)(v6 + 48) = 0i64;
    *(_DWORD *)(v6 + 56) = 0;
    *(_DWORD *)(v6 + 60) = 0x80000000;
  }
  else
  {
    v7 = 0i64;
  }
  if ( this->m_shapestorage.m_size == (this->m_shapestorage.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_shapestorage.m_data, 8);
  this->m_shapestorage.m_data[this->m_shapestorage.m_size++] = v7;
  v8 = this->m_shapestorage.m_data[this->m_shapestorage.m_size - 1];
  hkpExtendedMeshShape::ShapesSubpart::operator=(v4, partIn);
  v4->m_typeAndFlags ^= (partIn->m_typeAndFlags ^ v4->m_typeAndFlags) & 6;
  m_materialIndexBase = (char *)partIn->m_materialIndexBase;
  if ( m_materialIndexBase )
  {
    if ( (partIn->m_typeAndFlags & 6) == 2 )
    {
      v10 = v8->m_materialIndices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( partIn->m_materialIndexStriding )
      {
        m_size = partIn->m_childShapes.m_size;
        v12 = v8->m_materialIndices.m_size;
        v13 = v12 + m_size;
        if ( v10 < (int)v12 + (int)m_size )
        {
          v14 = 2 * v10;
          if ( v13 < v14 )
            v13 = v14;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v8->m_materialIndices.m_data,
            v13,
            1);
        }
        v8->m_materialIndices.m_size += m_size;
        v15 = 0i64;
        v16 = &v8->m_materialIndices.m_data[v12];
        v4->m_materialIndexBase = v16;
        v17 = (char *)partIn->m_materialIndexBase;
        if ( (int)m_size > 0 )
        {
          do
          {
            v16[v15++] = *v17;
            v17 += partIn->m_materialIndexStriding;
          }
          while ( v15 < m_size );
        }
      }
      else
      {
        if ( v8->m_materialIndices.m_size == v10 )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v8->m_materialIndices.m_data, 1);
        v8->m_materialIndices.m_data[v8->m_materialIndices.m_size++] = *m_materialIndexBase;
        v4->m_materialIndexBase = &v8->m_materialIndices.m_data[v8->m_materialIndices.m_size - 1];
      }
    }
    else
    {
      v18 = v8->m_materialIndices16.m_capacityAndFlags & 0x3FFFFFFF;
      if ( partIn->m_materialIndexStriding )
      {
        v19 = partIn->m_childShapes.m_size;
        v20 = v8->m_materialIndices16.m_size;
        v21 = v20 + v19;
        if ( v18 < (int)v20 + (int)v19 )
        {
          v22 = 2 * v18;
          if ( v21 < v22 )
            v21 = v22;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v8->m_materialIndices16.m_data,
            v21,
            2);
        }
        v8->m_materialIndices16.m_size += v19;
        v23 = 0i64;
        v24 = (__int64)&v8->m_materialIndices16.m_data[v20];
        v4->m_materialIndexBase = (const void *)v24;
        v25 = partIn->m_materialIndexBase;
        if ( (int)v19 > 0 )
        {
          do
          {
            ++v23;
            *(_WORD *)(v24 + 2 * v23 - 2) = *v25;
            v25 = (_WORD *)((char *)v25 + partIn->m_materialIndexStriding);
          }
          while ( v23 < v19 );
        }
      }
      else
      {
        if ( v8->m_materialIndices16.m_size == v18 )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v8->m_materialIndices16.m_data,
            2);
        v8->m_materialIndices16.m_data[v8->m_materialIndices16.m_size++] = *(_WORD *)m_materialIndexBase;
        v4->m_materialIndexBase = &v8->m_materialIndices16.m_data[v8->m_materialIndices16.m_size - 1];
      }
    }
    m_materialIndexStriding = partIn->m_materialIndexStriding;
    v4->m_materialIndexStriding = m_materialIndexStriding;
    if ( m_materialIndexStriding )
    {
      if ( ((v4->m_typeAndFlags >> 1) & 3) == 1 )
      {
        v4->m_materialIndexStriding = 1;
      }
      else if ( ((v4->m_typeAndFlags >> 1) & 3) == 2 )
      {
        v4->m_materialIndexStriding = 2;
      }
    }
  }
  else
  {
    v4->m_materialIndexBase = 0i64;
    v4->m_materialIndexStriding = 0;
  }
  if ( v4->m_materialIndexBase )
  {
    m_capacityAndFlags = v8->m_materials.m_capacityAndFlags;
    p_m_materials = &v8->m_materials;
    v29 = v8->m_materials.m_size;
    v30 = partIn->m_typeAndFlags >> 3;
    v31 = m_capacityAndFlags & 0x3FFFFFFF;
    v32 = v29 + v30;
    if ( v31 < (int)v29 + v30 )
    {
      v33 = 2 * v31;
      if ( v32 < v33 )
        v32 = v33;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_materials->m_data, v32, 16);
    }
    p_m_materials->m_size += v30;
    m_materialBase = partIn->m_materialBase;
    v35 = 0;
    v36 = (__int64)&p_m_materials->m_data[v29];
    if ( (partIn->m_typeAndFlags & 0xFFF8) != 0 )
    {
      do
      {
        v37 = v36 + 16i64 * v35;
        if ( v37 )
        {
          *(_QWORD *)v37 = 0i64;
          *(_QWORD *)(v37 + 8) = 0i64;
        }
        else
        {
          v37 = 0i64;
        }
        v38 = this->m_materialClass == &hkpStorageExtendedMeshShapeMaterialClass;
        *(hkpMeshMaterial *)v37 = (hkpMeshMaterial)m_materialBase->m_filterInfo;
        if ( v38 )
        {
          *(_WORD *)(v37 + 4) = m_materialBase[1].m_filterInfo;
          *(_WORD *)(v37 + 6) = HIWORD(m_materialBase[1].m_filterInfo);
          *(_QWORD *)(v37 + 8) = *(_QWORD *)&m_materialBase[2].m_filterInfo;
        }
        else
        {
          *(_DWORD *)(v37 + 4) = 1065353216;
          *(_QWORD *)(v37 + 8) = 0i64;
        }
        ++v35;
        m_materialBase = (hkpMeshMaterial *)((char *)m_materialBase + partIn->m_materialStriding);
      }
      while ( v35 < partIn->m_typeAndFlags >> 3 );
    }
    if ( partIn->m_materialStriding )
    {
      m_typeAndFlags = v4->m_typeAndFlags;
      v4->m_materialStriding = 16;
      v4->m_typeAndFlags = partIn->m_typeAndFlags ^ (partIn->m_typeAndFlags ^ m_typeAndFlags) & 7;
    }
    else
    {
      v4->m_typeAndFlags &= 7u;
      v4->m_typeAndFlags |= 8u;
      v4->m_materialStriding = 0;
    }
    v4->m_materialBase = p_m_materials->m_data;
  }
  v40.m_quad = (__m128)this->m_aabbHalfExtents;
  v41 = _mm_sub_ps(this->m_aabbCenter.m_quad, v40.m_quad);
  v42 = _mm_add_ps(v40.m_quad, this->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v4, &out);
  v43 = _mm_max_ps(v42, out.m_max.m_quad);
  v44 = _mm_min_ps(v41, out.m_min.m_quad);
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v43, v44), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v43, v44), (__m128)xmmword_141A711B0);
  this->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(this, v4);
  return (unsigned int)(this->m_shapesSubparts.m_size - 1);
}

