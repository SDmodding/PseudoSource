// File Line: 21
// RVA: 0xD15B50
void __fastcall hkpStorageExtendedMeshShape::MeshSubpartStorage::MeshSubpartStorage(hkpStorageExtendedMeshShape::MeshSubpartStorage *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::MeshSubpartStorage::`vftable';
}

// File Line: 27
// RVA: 0xD15B70
void __fastcall hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage(hkpStorageExtendedMeshShape::ShapeSubpartStorage *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::ShapeSubpartStorage::`vftable';
}

// File Line: 32
// RVA: 0xD15990
void __fastcall hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(hkpStorageExtendedMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpStorageExtendedMeshShape *v2; // rbx
  int v3; // ebp
  int v4; // er14
  __int64 v5; // rsi
  __int64 v6; // r15
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v7; // rcx
  hkpExtendedMeshShape::TrianglesSubpart *v8; // rdi
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v9; // rcx
  char v10; // al
  const void *v11; // rax
  const void *v12; // rax
  hkpMeshMaterial *v13; // rax
  __int64 v14; // rsi
  __int64 v15; // r14
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v16; // rcx
  hkpExtendedMeshShape::ShapesSubpart *v17; // rdi
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v18; // rcx
  const void *v19; // rax
  int flaga; // [rsp+58h] [rbp+10h]

  flaga = flag.m_finishing;
  v2 = this;
  hkpExtendedMeshShape::hkpExtendedMeshShape((hkpExtendedMeshShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  if ( flaga )
  {
    v3 = 0;
    v4 = 0;
    if ( v2->m_trianglesSubparts.m_size > 0 )
    {
      v5 = 0i64;
      v6 = 0i64;
      do
      {
        v7 = v2->m_meshstorage.m_data[v5];
        v8 = &v2->m_trianglesSubparts.m_data[v6];
        if ( v7 )
          hkpStorageExtendedMeshShape::MeshSubpartStorage::MeshSubpartStorage(v7, (hkFinishLoadedObjectFlag)flaga);
        v9 = v2->m_meshstorage.m_data[v5];
        v8->m_vertexBase = v9->m_vertices.m_data->m_quad.m128_f32;
        v10 = v8->m_stridingType.m_storage;
        if ( v10 == 1 )
        {
          v11 = v9->m_indices8.m_data;
        }
        else if ( v10 == 2 )
        {
          v11 = v9->m_indices16.m_data;
        }
        else
        {
          v11 = v9->m_indices32.m_data;
        }
        v8->m_indexBase = v11;
        if ( (v8->m_typeAndFlags & 6) == 2 )
          v12 = v9->m_materialIndices.m_data;
        else
          v12 = v9->m_materialIndices16.m_data;
        v8->m_materialIndexBase = v12;
        if ( v9->m_namedMaterials.m_size )
          v13 = (hkpMeshMaterial *)&v9->m_namedMaterials.m_data->m_filterInfo;
        else
          v13 = (hkpMeshMaterial *)&v9->m_materials.m_data->m_filterInfo;
        ++v4;
        v8->m_materialStriding = 16;
        v8->m_materialBase = v13;
        ++v6;
        ++v5;
      }
      while ( v4 < v2->m_trianglesSubparts.m_size );
    }
    if ( v2->m_shapesSubparts.m_size > 0 )
    {
      v14 = 0i64;
      v15 = 0i64;
      do
      {
        v16 = v2->m_shapestorage.m_data[v14];
        v17 = &v2->m_shapesSubparts.m_data[v15];
        if ( v16 )
          hkpStorageExtendedMeshShape::ShapeSubpartStorage::ShapeSubpartStorage(v16, (hkFinishLoadedObjectFlag)flaga);
        v18 = v2->m_shapestorage.m_data[v14];
        if ( (v17->m_typeAndFlags & 6) == 2 )
          v19 = v18->m_materialIndices.m_data;
        else
          v19 = v18->m_materialIndices16.m_data;
        v17->m_materialIndexBase = v19;
        ++v3;
        ++v15;
        ++v14;
        v17->m_materialBase = (hkpMeshMaterial *)&v18->m_materials.m_data->m_filterInfo;
      }
      while ( v3 < v2->m_shapesSubparts.m_size );
    }
  }
}

// File Line: 106
// RVA: 0xD146D0
void __fastcall hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(hkpStorageExtendedMeshShape *this, float radius, int numbits)
{
  hkpStorageExtendedMeshShape *v3; // rbx

  v3 = this;
  hkpExtendedMeshShape::hkpExtendedMeshShape((hkpExtendedMeshShape *)&this->vfptr, radius, numbits);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShape'};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  v3->m_meshstorage.m_capacityAndFlags = 2147483648;
  v3->m_meshstorage.m_data = 0i64;
  v3->m_meshstorage.m_size = 0;
  v3->m_shapestorage.m_data = 0i64;
  v3->m_shapestorage.m_size = 0;
  v3->m_shapestorage.m_capacityAndFlags = 2147483648;
}

// File Line: 110
// RVA: 0xD14910
void __fastcall hkpStorageExtendedMeshShape::~hkpStorageExtendedMeshShape(hkpStorageExtendedMeshShape *this)
{
  hkpStorageExtendedMeshShape *v1; // rbx
  int v2; // esi
  __int64 v3; // rdi
  int v4; // edi
  hkpExtendedMeshShape::ShapesSubpart *v5; // rsi
  int v6; // edi
  __int64 v7; // rsi
  int v8; // er8
  int v9; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShape'};
  v2 = 0;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  if ( this->m_meshstorage.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_meshstorage.m_data[v3]->vfptr);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_meshstorage.m_size );
  }
  v4 = v1->m_shapesSubparts.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v1->m_shapesSubparts.m_data[v4];
    do
    {
      hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart(v5);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v1->m_shapesSubparts.m_size = 0;
  v6 = 0;
  if ( v1->m_shapestorage.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_shapestorage.m_data[v7]->vfptr);
      ++v6;
      ++v7;
    }
    while ( v6 < v1->m_shapestorage.m_size );
  }
  v1->m_materialClass = &hkpStorageExtendedMeshShapeMaterialClass;
  v8 = v1->m_shapestorage.m_capacityAndFlags;
  v1->m_shapestorage.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_shapestorage.m_data,
      8 * v8);
  v1->m_shapestorage.m_data = 0i64;
  v1->m_shapestorage.m_capacityAndFlags = 2147483648;
  v9 = v1->m_meshstorage.m_capacityAndFlags;
  v1->m_meshstorage.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_meshstorage.m_data,
      8 * v9);
  v1->m_meshstorage.m_data = 0i64;
  v1->m_meshstorage.m_capacityAndFlags = 2147483648;
  hkpExtendedMeshShape::~hkpExtendedMeshShape((hkpExtendedMeshShape *)&v1->vfptr);
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
void __fastcall hkpStorageExtendedMeshShape::hkpStorageExtendedMeshShape(hkpStorageExtendedMeshShape *this, hkpExtendedMeshShape *mesh)
{
  hkpExtendedMeshShape *v2; // rbx
  hkpStorageExtendedMeshShape *v3; // rdi
  int v4; // esi
  int v5; // ebp
  int v6; // er8
  __int64 v7; // rax
  unsigned __int16 *v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  unsigned __int16 v11; // ax
  int v12; // [rsp+30h] [rbp+8h]

  v2 = mesh;
  v3 = this;
  hkpExtendedMeshShape::hkpExtendedMeshShape(
    (hkpExtendedMeshShape *)&this->vfptr,
    mesh->m_triangleRadius,
    mesh->m_numBitsForSubpartIndex);
  v4 = 0;
  v5 = 0;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShape'};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkpStorageExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  v3->m_meshstorage.m_data = 0i64;
  v3->m_meshstorage.m_size = 0;
  v3->m_meshstorage.m_capacityAndFlags = 2147483648;
  v3->m_shapestorage.m_data = 0i64;
  v3->m_shapestorage.m_size = 0;
  v3->m_shapestorage.m_capacityAndFlags = 2147483648;
  v3->m_userData = v2->m_userData;
  for ( v3->m_disableWelding.m_bool = v2->m_disableWelding.m_bool; v5 < v2->m_trianglesSubparts.m_size; ++v5 )
    hkpStorageExtendedMeshShape::addTrianglesSubpart(v3, &v2->m_trianglesSubparts.m_data[v5]);
  if ( v2->m_shapesSubparts.m_size > 0 )
  {
    do
      hkpStorageExtendedMeshShape::addShapesSubpart(v3, &v2->m_shapesSubparts.m_data[v4++]);
    while ( v4 < v2->m_shapesSubparts.m_size );
  }
  v6 = v3->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v2->m_weldingInfo.m_size )
  {
    if ( v3->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_weldingInfo.m_data,
        2 * v6);
    v12 = 2 * v2->m_weldingInfo.m_size;
    v3->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                     &v12);
    v3->m_weldingInfo.m_capacityAndFlags = v12 / 2;
  }
  v7 = v2->m_weldingInfo.m_size;
  v8 = v3->m_weldingInfo.m_data;
  v3->m_weldingInfo.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v2->m_weldingInfo.m_data - (char *)v8);
    do
    {
      v11 = *(unsigned __int16 *)((char *)v8 + (_QWORD)v10);
      ++v8;
      *(v8 - 1) = v11;
      --v9;
    }
    while ( v9 );
  }
  v3->m_weldingType.m_storage = v2->m_weldingType.m_storage;
  hkpExtendedMeshShape::recalcAabbExtents((hkpExtendedMeshShape *)&v3->vfptr);
}

// File Line: 197
// RVA: 0xD14AA0
void __fastcall hkpStorageExtendedMeshShape::addTrianglesSubpart(hkpStorageExtendedMeshShape *this, hkpExtendedMeshShape::TrianglesSubpart *partIn)
{
  hkpExtendedMeshShape::TrianglesSubpart *v2; // rbx
  hkpStorageExtendedMeshShape *v3; // r12
  hkpExtendedMeshShape::TrianglesSubpart *v4; // rax
  hkpExtendedMeshShape::TrianglesSubpart *v5; // rdi
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v8; // r14
  int v9; // er15
  signed int *v10; // r13
  __int64 v11; // rbp
  int v12; // er9
  int v13; // eax
  int v14; // eax
  const float *v15; // rcx
  int v16; // er8
  signed __int64 i; // rdx
  const float *v18; // rax
  char v19; // al
  signed __int16 v20; // ax
  signed __int16 v21; // r8
  int v22; // eax
  __int64 v23; // r14
  int v24; // er9
  int v25; // ecx
  int v26; // er15
  int v27; // ecx
  _BYTE *v28; // r14
  _BYTE *v29; // rcx
  _WORD *v30; // r8
  int j; // edx
  bool v32; // zf
  unsigned __int16 v33; // ax
  signed __int16 v34; // ax
  signed __int16 v35; // r8
  int v36; // eax
  __int64 v37; // r12
  int v38; // er9
  int v39; // ecx
  int v40; // er15
  int v41; // ecx
  __int64 v42; // rax
  _WORD *v43; // r14
  _WORD *v44; // rcx
  int k; // edx
  signed __int16 v46; // ax
  signed __int16 v47; // cx
  int v48; // eax
  int sizeElem; // er8
  __int64 v50; // r15
  int v51; // er9
  int v52; // ecx
  int v53; // ebp
  int v54; // ecx
  __int64 v55; // rax
  _DWORD *v56; // r14
  _DWORD *v57; // rcx
  int l; // edx
  char v59; // al
  _BYTE *v60; // r15
  int v61; // eax
  int v62; // er14
  __int64 v63; // r15
  int v64; // er9
  int v65; // eax
  int v66; // er8
  char *v67; // rcx
  char *m; // rdx
  _QWORD *v69; // r14
  int v70; // eax
  int v71; // er15
  __int64 v72; // rbp
  int v73; // er9
  int v74; // eax
  int v75; // er8
  signed __int64 v76; // rdx
  _WORD *n; // rcx
  unsigned __int16 v78; // ax
  unsigned int v79; // er15
  signed int v80; // eax
  signed int *v81; // r12
  __int64 v82; // r13
  int v83; // eax
  int v84; // er9
  int v85; // eax
  __int64 v86; // rbp
  signed __int64 v87; // r14
  hkpMeshMaterial *v88; // r15
  signed int v89; // ebp
  signed __int64 v90; // r14
  hkStringPtr *v91; // rcx
  hkStringPtr *v92; // rcx
  __int64 v93; // rbp
  _QWORD *v94; // r14
  int v95; // er9
  int v96; // eax
  int v97; // eax
  hkpMeshMaterial *v98; // rdx
  signed int v99; // er8
  signed __int64 v100; // r9
  signed __int64 v101; // rcx
  hkpStorageExtendedMeshShape *v102; // rbx
  __m128 v103; // xmm7
  __m128 v104; // xmm6
  __m128 v105; // xmm7
  int v106; // er8
  __m128 v107; // xmm0
  __m128 v108; // xmm7
  __m128 v109; // xmm6
  hkAabb out; // [rsp+30h] [rbp-78h]
  hkpStorageExtendedMeshShape *v111; // [rsp+B0h] [rbp+8h]
  hkResult result; // [rsp+B8h] [rbp+10h]

  v111 = this;
  v2 = partIn;
  v3 = this;
  v4 = hkpExtendedMeshShape::expandOneTriangleSubparts((hkpExtendedMeshShape *)&this->vfptr);
  *(_QWORD *)&v4->m_typeAndFlags = *(_QWORD *)&v2->m_typeAndFlags;
  v5 = v4;
  v4->m_materialIndexBase = v2->m_materialIndexBase;
  v4->m_materialBase = v2->m_materialBase;
  v4->m_userData = v2->m_userData;
  v4->m_numTriangleShapes = v2->m_numTriangleShapes;
  v4->m_vertexBase = v2->m_vertexBase;
  v4->m_numVertices = v2->m_numVertices;
  v4->m_indexBase = v2->m_indexBase;
  v4->m_vertexStriding = v2->m_vertexStriding;
  v4->m_triangleOffset = v2->m_triangleOffset;
  v4->m_indexStriding = v2->m_indexStriding;
  v4->m_stridingType.m_storage = v2->m_stridingType.m_storage;
  v4->m_flipAlternateTriangles = v2->m_flipAlternateTriangles;
  v4->m_extrusion = v2->m_extrusion;
  v4->m_transform.m_translation = v2->m_transform.m_translation;
  v4->m_transform.m_rotation = v2->m_transform.m_rotation;
  v4->m_transform.m_scale = v2->m_transform.m_scale;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 144i64);
  v8 = (hkpStorageExtendedMeshShape::MeshSubpartStorage *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkpStorageExtendedMeshShape::MeshSubpartStorage::`vftable';
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 2147483648;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 2147483648;
    *(_QWORD *)(v7 + 48) = 0i64;
    *(_DWORD *)(v7 + 56) = 0;
    *(_DWORD *)(v7 + 60) = 2147483648;
    *(_QWORD *)(v7 + 64) = 0i64;
    *(_DWORD *)(v7 + 72) = 0;
    *(_DWORD *)(v7 + 76) = 2147483648;
    *(_QWORD *)(v7 + 80) = 0i64;
    *(_DWORD *)(v7 + 88) = 0;
    *(_DWORD *)(v7 + 92) = 2147483648;
    *(_QWORD *)(v7 + 96) = 0i64;
    *(_DWORD *)(v7 + 104) = 0;
    *(_DWORD *)(v7 + 108) = 2147483648;
    *(_QWORD *)(v7 + 112) = 0i64;
    *(_DWORD *)(v7 + 120) = 0;
    *(_DWORD *)(v7 + 124) = 2147483648;
    *(_QWORD *)(v7 + 128) = 0i64;
    *(_DWORD *)(v7 + 136) = 0;
    *(_DWORD *)(v7 + 140) = 2147483648;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v3->m_meshstorage.m_size == (v3->m_meshstorage.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_meshstorage, 8);
  v3->m_meshstorage.m_data[v3->m_meshstorage.m_size++] = v8;
  v9 = v2->m_numVertices;
  v10 = (signed int *)v3->m_meshstorage.m_data[v3->m_meshstorage.m_size - 1];
  v11 = v10[6];
  v12 = v9 + v11;
  v13 = v10[7] & 0x3FFFFFFF;
  if ( v13 < v9 + (signed int)v11 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10 + 4, v12, 16);
  }
  v10[6] += v9;
  v15 = v2->m_vertexBase;
  v16 = 0;
  for ( i = *((_QWORD *)v10 + 2) + 16 * v11;
        v16 < v2->m_numVertices;
        v15 = (const float *)((char *)v15 + v2->m_vertexStriding) )
  {
    ++v16;
    i += 16i64;
    *(__m128 *)(i - 16) = _mm_unpacklo_ps(
                            _mm_unpacklo_ps((__m128)*(unsigned int *)v15, (__m128)*((unsigned int *)v15 + 2)),
                            _mm_unpacklo_ps((__m128)*((unsigned int *)v15 + 1), (__m128)0i64));
  }
  v18 = (const float *)*((_QWORD *)v10 + 2);
  v5->m_vertexStriding = 16;
  v5->m_vertexBase = v18;
  v5->m_numVertices = v2->m_numVertices;
  v19 = v2->m_stridingType.m_storage;
  if ( v19 == 1 )
  {
    v20 = v2->m_indexStriding;
    v21 = v20;
    if ( v20 > 2 )
      v21 = 4;
    v5->m_indexStriding = v21;
    v22 = numIndices(v20, v2->m_numTriangleShapes);
    v23 = v10[10];
    v24 = v23 + v22;
    v25 = v10[11] & 0x3FFFFFFF;
    v26 = v22;
    if ( v25 >= (signed int)v23 + v22 )
    {
      result.m_enum = 0;
    }
    else
    {
      v27 = 2 * v25;
      if ( v24 < v27 )
        v24 = v27;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10 + 8, v24, 1);
    }
    v28 = (_BYTE *)(*((_QWORD *)v10 + 4) + v23);
    v10[10] += v26;
    hkString::memSet(v28, 0, v26);
    v29 = v2->m_indexBase;
    v30 = v28;
    for ( j = 0; j < v2->m_numTriangleShapes; v29 += v2->m_indexStriding )
    {
      ++j;
      *v28 = *v29;
      v28[1] = v29[1];
      v28[2] = v29[2];
      v28 += v5->m_indexStriding;
    }
  }
  else
  {
    v32 = v19 == 2;
    v33 = v2->m_indexStriding;
    if ( v32 )
    {
      v34 = v33 >> 1;
      v35 = v34;
      if ( v34 > 2 )
        v35 = 4;
      v5->m_indexStriding = 2 * v35;
      v36 = numIndices(v34, v2->m_numTriangleShapes);
      v37 = v10[14];
      v38 = v37 + v36;
      v39 = v10[15] & 0x3FFFFFFF;
      v40 = v36;
      if ( v39 >= (signed int)v37 + v36 )
      {
        result.m_enum = 0;
      }
      else
      {
        v41 = 2 * v39;
        if ( v38 < v41 )
          v38 = v41;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10 + 12, v38, 2);
      }
      v42 = *((_QWORD *)v10 + 6);
      v10[14] += v40;
      v43 = (_WORD *)(v42 + 2 * v37);
      hkString::memSet((void *)(v42 + 2 * v37), 0, 2 * v40);
      v44 = v2->m_indexBase;
      v30 = v43;
      for ( k = 0; k < v2->m_numTriangleShapes; v44 = (_WORD *)((char *)v44 + v2->m_indexStriding) )
      {
        ++k;
        *v43 = *v44;
        v43[1] = v44[1];
        v43[2] = v44[2];
        v43 = (_WORD *)((char *)v43 + v5->m_indexStriding);
      }
      v3 = v111;
    }
    else
    {
      v46 = v33 >> 2;
      v47 = v46;
      if ( v46 > 2 )
        v47 = 4;
      v5->m_indexStriding = 4 * v47;
      v48 = numIndices(v46, v2->m_numTriangleShapes);
      v50 = v10[18];
      v51 = v50 + v48;
      v52 = v10[19] & 0x3FFFFFFF;
      v53 = v48;
      if ( v52 >= (signed int)v50 + v48 )
      {
        result.m_enum = 0;
      }
      else
      {
        v54 = 2 * v52;
        if ( v51 < v54 )
          v51 = v54;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v10 + 16,
          v51,
          sizeElem);
      }
      v55 = *((_QWORD *)v10 + 8);
      v10[18] += v53;
      v56 = (_DWORD *)(v55 + 4 * v50);
      hkString::memSet((void *)(v55 + 4 * v50), 0, 4 * v53);
      v57 = v2->m_indexBase;
      v30 = v56;
      for ( l = 0; l < v2->m_numTriangleShapes; v57 = (_DWORD *)((char *)v57 + v2->m_indexStriding) )
      {
        ++l;
        *v56 = *v57;
        v56[1] = v57[1];
        v56[2] = v57[2];
        v56 = (_DWORD *)((char *)v56 + v5->m_indexStriding);
      }
    }
  }
  v5->m_stridingType.m_storage = v2->m_stridingType.m_storage;
  v5->m_numTriangleShapes = v2->m_numTriangleShapes;
  v59 = v2->m_flipAlternateTriangles;
  v5->m_indexBase = v30;
  v5->m_flipAlternateTriangles = v59;
  v5->m_typeAndFlags ^= (v2->m_typeAndFlags ^ v5->m_typeAndFlags) & 6;
  v60 = v2->m_materialIndexBase;
  if ( v60 )
  {
    if ( (v2->m_typeAndFlags & 6) == 2 )
    {
      v61 = v10[23] & 0x3FFFFFFF;
      if ( v2->m_materialIndexStriding )
      {
        v62 = v2->m_numTriangleShapes;
        v63 = v10[22];
        v64 = v62 + v63;
        if ( v61 < v62 + (signed int)v63 )
        {
          v65 = 2 * v61;
          if ( v64 < v65 )
            v64 = v65;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v10 + 20,
            v64,
            1);
        }
        v10[22] += v62;
        v66 = 0;
        v67 = (char *)(*((_QWORD *)v10 + 10) + v63);
        v5->m_materialIndexBase = v67;
        for ( m = (char *)v2->m_materialIndexBase; v66 < v2->m_numTriangleShapes; m += v2->m_materialIndexStriding )
        {
          ++v66;
          *(++v67 - 1) = *m;
        }
      }
      else
      {
        if ( v10[22] == v61 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10 + 20, 1);
        *(_BYTE *)(*((_QWORD *)v10 + 10) + v10[22]++) = *v60;
        v5->m_materialIndexBase = (const void *)(*((_QWORD *)v10 + 10) + v10[22] - 1);
      }
    }
    else
    {
      v69 = v10 + 32;
      v70 = v10[35] & 0x3FFFFFFF;
      if ( v2->m_materialIndexStriding )
      {
        v71 = v2->m_numTriangleShapes;
        v72 = v10[34];
        v73 = v71 + v72;
        if ( v70 < v71 + (signed int)v72 )
        {
          v74 = 2 * v70;
          if ( v73 < v74 )
            v73 = v74;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v10 + 32,
            v73,
            2);
        }
        v10[34] += v71;
        v75 = 0;
        v76 = *v69 + 2 * v72;
        v5->m_materialIndexBase = (const void *)v76;
        for ( n = v2->m_materialIndexBase;
              v75 < v2->m_numTriangleShapes;
              n = (_WORD *)((char *)n + v2->m_materialIndexStriding) )
        {
          ++v75;
          v76 += 2i64;
          *(_WORD *)(v76 - 2) = *n;
        }
      }
      else
      {
        if ( v10[34] == v70 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10 + 32, 2);
        *(_WORD *)(*v69 + 2i64 * v10[34]++) = *(_WORD *)v60;
        v5->m_materialIndexBase = (const void *)(*v69 + 2i64 * (v10[34] - 1));
      }
    }
    v78 = v2->m_materialIndexStriding;
    v5->m_materialIndexStriding = v78;
    if ( v78 )
    {
      if ( (((unsigned int)v5->m_typeAndFlags >> 1) & 3) == 1 )
      {
        v5->m_materialIndexStriding = 1;
      }
      else if ( (((unsigned int)v5->m_typeAndFlags >> 1) & 3) == 2 )
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
    v79 = (unsigned int)v2->m_typeAndFlags >> 3;
    if ( v3->m_materialClass == &hkpNamedMeshMaterialClass )
    {
      v80 = v10[31];
      v81 = v10 + 28;
      v82 = v10[30];
      v83 = v80 & 0x3FFFFFFF;
      v84 = v79 + v82;
      if ( v83 >= (signed int)(v79 + v82) )
      {
        result.m_enum = 0;
      }
      else
      {
        v85 = 2 * v83;
        if ( v84 < v85 )
          v84 = v85;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v81, v84, 16);
      }
      v86 = v79;
      v87 = *(_QWORD *)v81 + 16i64 * v81[2];
      if ( (signed int)v79 > 0 )
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
      v81[2] += v79;
      v88 = v2->m_materialBase;
      v89 = 0;
      v90 = *(_QWORD *)v81 + 16 * v82;
      if ( (v2->m_typeAndFlags & 0xFFF8u) > 0 )
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
          LODWORD(v92[-1].m_stringAndFlag) = (hkpMeshMaterial)v88->m_filterInfo;
          hkStringPtr::operator=(v92, (hkStringPtr *)&v88[2]);
          v88 = (hkpMeshMaterial *)((char *)v88 + v2->m_materialStriding);
          ++v89;
          v90 += 16i64;
        }
        while ( v89 < (signed int)((unsigned int)v2->m_typeAndFlags >> 3) );
      }
      v5->m_materialBase = *(hkpMeshMaterial **)v81;
      if ( v2->m_materialStriding )
      {
        v5->m_materialStriding = 16;
LABEL_104:
        v5->m_typeAndFlags = v2->m_typeAndFlags ^ (v2->m_typeAndFlags ^ v5->m_typeAndFlags) & 7;
        goto LABEL_106;
      }
    }
    else
    {
      v93 = v10[26];
      v94 = v10 + 24;
      v95 = v79 + v93;
      v96 = v10[27] & 0x3FFFFFFF;
      if ( v96 < (signed int)(v79 + v93) )
      {
        v97 = 2 * v96;
        if ( v95 < v97 )
          v95 = v97;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v94, v95, 16);
      }
      v10[26] += v79;
      v98 = v2->m_materialBase;
      v99 = 0;
      v100 = *v94 + 16 * v93;
      if ( (v2->m_typeAndFlags & 0xFFF8u) > 0 )
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
          v98 = (hkpMeshMaterial *)((char *)v98 + v2->m_materialStriding);
        }
        while ( v99 < (signed int)((unsigned int)v2->m_typeAndFlags >> 3) );
      }
      v5->m_materialBase = (hkpMeshMaterial *)*v94;
      if ( v2->m_materialStriding )
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
  v102 = v111;
  v103 = v111->m_aabbHalfExtents.m_quad;
  v104 = _mm_sub_ps(v111->m_aabbCenter.m_quad, v103);
  v105 = _mm_add_ps(v103, v111->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v5, &out);
  v106 = v111->m_trianglesSubparts.m_size - 1;
  v107 = _mm_shuffle_ps((__m128)LODWORD(v102->m_triangleRadius), (__m128)LODWORD(v102->m_triangleRadius), 0);
  v108 = _mm_max_ps(v105, _mm_add_ps(out.m_max.m_quad, v107));
  v109 = _mm_min_ps(v104, _mm_sub_ps(out.m_min.m_quad, v107));
  v111->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v108, v109), (__m128)xmmword_141A711B0);
  v111->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v108, v109), (__m128)xmmword_141A711B0);
  v102->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(
                                    (hkpExtendedMeshShape *)&v111->vfptr,
                                    v5,
                                    v106);
}

// File Line: 470
// RVA: 0xD154C0
__int64 __fastcall hkpStorageExtendedMeshShape::addShapesSubpart(hkpStorageExtendedMeshShape *this, hkpExtendedMeshShape::ShapesSubpart *partIn)
{
  hkpExtendedMeshShape::ShapesSubpart *v2; // rbx
  hkpStorageExtendedMeshShape *v3; // r13
  hkpExtendedMeshShape::ShapesSubpart *v4; // rsi
  _QWORD **v5; // rax
  __int64 v6; // rax
  hkpStorageExtendedMeshShape::ShapeSubpartStorage *v7; // r14
  signed int *v8; // r15
  _BYTE *v9; // r12
  int v10; // eax
  __int64 v11; // r14
  __int64 v12; // r12
  int v13; // er9
  int v14; // eax
  __int64 v15; // rcx
  char *v16; // r8
  char *v17; // rdx
  int v18; // eax
  __int64 v19; // rbp
  __int64 v20; // r12
  int v21; // er9
  int v22; // eax
  __int64 v23; // rcx
  signed __int64 v24; // r8
  _WORD *v25; // rdx
  unsigned __int16 v26; // ax
  signed int v27; // eax
  _DWORD *v28; // r14
  __int64 v29; // r15
  unsigned int v30; // ebp
  int v31; // eax
  int v32; // er9
  int v33; // eax
  hkpMeshMaterial *v34; // rdx
  signed int v35; // er8
  signed __int64 v36; // r9
  signed __int64 v37; // rax
  bool v38; // zf
  unsigned __int16 v39; // ax
  __m128 v40; // xmm7
  __m128 v41; // xmm6
  __m128 v42; // xmm7
  __m128 v43; // xmm7
  __m128 v44; // xmm6
  hkAabb out; // [rsp+30h] [rbp-68h]
  hkResult result; // [rsp+A0h] [rbp+8h]

  v2 = partIn;
  v3 = this;
  v4 = hkpExtendedMeshShape::expandOneShapesSubparts((hkpExtendedMeshShape *)&this->vfptr);
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 64i64);
  v7 = (hkpStorageExtendedMeshShape::ShapeSubpartStorage *)v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 8) = 0x1FFFF;
    *(_QWORD *)v6 = &hkpStorageExtendedMeshShape::ShapeSubpartStorage::`vftable';
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_DWORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 28) = 2147483648;
    *(_QWORD *)(v6 + 32) = 0i64;
    *(_DWORD *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 44) = 2147483648;
    *(_QWORD *)(v6 + 48) = 0i64;
    *(_DWORD *)(v6 + 56) = 0;
    *(_DWORD *)(v6 + 60) = 2147483648;
  }
  else
  {
    v7 = 0i64;
  }
  if ( v3->m_shapestorage.m_size == (v3->m_shapestorage.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_shapestorage, 8);
  v3->m_shapestorage.m_data[v3->m_shapestorage.m_size++] = v7;
  v8 = (signed int *)v3->m_shapestorage.m_data[v3->m_shapestorage.m_size - 1];
  hkpExtendedMeshShape::ShapesSubpart::operator=(v4, v2);
  v4->m_typeAndFlags ^= (v2->m_typeAndFlags ^ v4->m_typeAndFlags) & 6;
  v9 = v2->m_materialIndexBase;
  if ( v9 )
  {
    if ( (v2->m_typeAndFlags & 6) == 2 )
    {
      v10 = v8[7] & 0x3FFFFFFF;
      if ( v2->m_materialIndexStriding )
      {
        v11 = v2->m_childShapes.m_size;
        v12 = v8[6];
        v13 = v12 + v11;
        if ( v10 < (signed int)v12 + (signed int)v11 )
        {
          v14 = 2 * v10;
          if ( v13 < v14 )
            v13 = v14;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8 + 4, v13, 1);
        }
        v8[6] += v11;
        v15 = 0i64;
        v16 = (char *)(*((_QWORD *)v8 + 2) + v12);
        v4->m_materialIndexBase = v16;
        v17 = (char *)v2->m_materialIndexBase;
        if ( (signed int)v11 > 0 )
        {
          do
          {
            v16[++v15 - 1] = *v17;
            v17 += v2->m_materialIndexStriding;
          }
          while ( v15 < v11 );
        }
      }
      else
      {
        if ( v8[6] == v10 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8 + 4, 1);
        *(_BYTE *)(*((_QWORD *)v8 + 2) + v8[6]++) = *v9;
        v4->m_materialIndexBase = (const void *)(*((_QWORD *)v8 + 2) + v8[6] - 1);
      }
    }
    else
    {
      v18 = v8[15] & 0x3FFFFFFF;
      if ( v2->m_materialIndexStriding )
      {
        v19 = v2->m_childShapes.m_size;
        v20 = v8[14];
        v21 = v20 + v19;
        if ( v18 < (signed int)v20 + (signed int)v19 )
        {
          v22 = 2 * v18;
          if ( v21 < v22 )
            v21 = v22;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8 + 12, v21, 2);
        }
        v8[14] += v19;
        v23 = 0i64;
        v24 = *((_QWORD *)v8 + 6) + 2 * v20;
        v4->m_materialIndexBase = (const void *)v24;
        v25 = v2->m_materialIndexBase;
        if ( (signed int)v19 > 0 )
        {
          do
          {
            *(_WORD *)(v24 + 2 * ++v23 - 2) = *v25;
            v25 = (_WORD *)((char *)v25 + v2->m_materialIndexStriding);
          }
          while ( v23 < v19 );
        }
      }
      else
      {
        if ( v8[14] == v18 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8 + 12, 2);
        *(_WORD *)(*((_QWORD *)v8 + 6) + 2i64 * v8[14]++) = *(_WORD *)v9;
        v4->m_materialIndexBase = (const void *)(*((_QWORD *)v8 + 6) + 2i64 * (v8[14] - 1));
      }
    }
    v26 = v2->m_materialIndexStriding;
    v4->m_materialIndexStriding = v26;
    if ( v26 )
    {
      if ( (((unsigned int)v4->m_typeAndFlags >> 1) & 3) == 1 )
      {
        v4->m_materialIndexStriding = 1;
      }
      else if ( (((unsigned int)v4->m_typeAndFlags >> 1) & 3) == 2 )
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
    v27 = v8[11];
    v28 = v8 + 8;
    v29 = v8[10];
    v30 = (unsigned int)v2->m_typeAndFlags >> 3;
    v31 = v27 & 0x3FFFFFFF;
    v32 = v29 + v30;
    if ( v31 < (signed int)(v29 + v30) )
    {
      v33 = 2 * v31;
      if ( v32 < v33 )
        v32 = v33;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v28, v32, 16);
    }
    v28[2] += v30;
    v34 = v2->m_materialBase;
    v35 = 0;
    v36 = *(_QWORD *)v28 + 16 * v29;
    if ( (v2->m_typeAndFlags & 0xFFF8u) > 0 )
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
        v38 = v3->m_materialClass == &hkpStorageExtendedMeshShapeMaterialClass;
        *(hkpMeshMaterial *)v37 = (hkpMeshMaterial)v34->m_filterInfo;
        if ( v38 )
        {
          *(_WORD *)(v37 + 4) = v34[1].m_filterInfo;
          *(_WORD *)(v37 + 6) = HIWORD(v34[1].m_filterInfo);
          *(_QWORD *)(v37 + 8) = *(_QWORD *)&v34[2].m_filterInfo;
        }
        else
        {
          *(_DWORD *)(v37 + 4) = 1065353216;
          *(_QWORD *)(v37 + 8) = 0i64;
        }
        ++v35;
        v34 = (hkpMeshMaterial *)((char *)v34 + v2->m_materialStriding);
      }
      while ( v35 < (signed int)((unsigned int)v2->m_typeAndFlags >> 3) );
    }
    if ( v2->m_materialStriding )
    {
      v39 = v4->m_typeAndFlags;
      v4->m_materialStriding = 16;
      v4->m_typeAndFlags = v2->m_typeAndFlags ^ (v2->m_typeAndFlags ^ v39) & 7;
    }
    else
    {
      v4->m_typeAndFlags &= 7u;
      v4->m_typeAndFlags |= 8u;
      v4->m_materialStriding = 0;
    }
    v4->m_materialBase = *(hkpMeshMaterial **)v28;
  }
  v40 = v3->m_aabbHalfExtents.m_quad;
  v41 = _mm_sub_ps(v3->m_aabbCenter.m_quad, v40);
  v42 = _mm_add_ps(v40, v3->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v4, &out);
  v43 = _mm_max_ps(v42, out.m_max.m_quad);
  v44 = _mm_min_ps(v41, out.m_min.m_quad);
  v3->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v43, v44), (__m128)xmmword_141A711B0);
  v3->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v43, v44), (__m128)xmmword_141A711B0);
  v3->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(
                                  (hkpExtendedMeshShape *)&v3->vfptr,
                                  v4);
  return (unsigned int)(v3->m_shapesSubparts.m_size - 1);
}cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(
                                  (hkpExtendedMeshShape *)&v3->v

