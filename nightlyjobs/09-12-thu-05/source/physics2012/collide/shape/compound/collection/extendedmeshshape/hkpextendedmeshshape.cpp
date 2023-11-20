// File Line: 50
// RVA: 0xD12630
void __fastcall hkpExtendedMeshShape::hkpExtendedMeshShape(hkpExtendedMeshShape *this, float radius, int numBitsForSubpartIndex)
{
  int v3; // ebx
  hkpExtendedMeshShape *v4; // rdi

  v3 = numBitsForSubpartIndex;
  v4 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, EXTENDED_MESH, COLLECTION_EXTENDED_MESH);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShape'};
  v4->vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  *(_QWORD *)&v4->m_embeddedTrianglesSubpart.m_typeAndFlags = 10i64;
  v4->m_embeddedTrianglesSubpart.m_extrusion = 0i64;
  v4->m_embeddedTrianglesSubpart.m_materialBase = 0i64;
  v4->m_embeddedTrianglesSubpart.m_materialIndexBase = 0i64;
  v4->m_embeddedTrianglesSubpart.m_userData = 0i64;
  v4->m_embeddedTrianglesSubpart.m_flipAlternateTriangles = 0;
  v4->m_embeddedTrianglesSubpart.m_transform.m_translation = 0i64;
  v4->m_embeddedTrianglesSubpart.m_transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  v4->m_embeddedTrianglesSubpart.m_transform.m_scale = (hkVector4f)query.m_quad;
  v4->m_trianglesSubparts.m_data = 0i64;
  v4->m_trianglesSubparts.m_size = 0;
  v4->m_trianglesSubparts.m_capacityAndFlags = 2147483648;
  v4->m_shapesSubparts.m_data = 0i64;
  v4->m_shapesSubparts.m_size = 0;
  v4->m_shapesSubparts.m_capacityAndFlags = 2147483648;
  v4->m_weldingInfo.m_data = 0i64;
  v4->m_weldingInfo.m_size = 0;
  v4->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v4->m_triangleRadius = radius;
  v4->m_defaultCollisionFilterInfo = 0;
  v4->m_numBitsForSubpartIndex = v3;
  v4->m_weldingType.m_storage = 6;
  v4->m_cachedNumChildShapes = 0;
  v4->m_materialClass = 0i64;
  v4->m_aabbHalfExtents = (hkVector4f)xmmword_141A712F0;
  v4->m_aabbCenter = 0i64;
}

// File Line: 72
// RVA: 0xD12750
void __fastcall hkpExtendedMeshShape::hkpExtendedMeshShape(hkpExtendedMeshShape *this, hkpMeshShape *meshShape)
{
  hkpMeshShape *v2; // rsi
  hkpExtendedMeshShape *v3; // rbx
  int v4; // ebp
  signed __int64 v5; // r14
  signed __int64 v6; // rdi
  int v7; // er8
  __int64 v8; // rax
  unsigned __int16 *v9; // rcx
  __int64 v10; // rdx
  char *v11; // r8
  unsigned __int16 v12; // ax
  int v13; // er15
  int v14; // eax
  int v15; // eax
  int v16; // er9
  __int64 v17; // r9
  __int64 v18; // r10
  __int64 v19; // rax
  hkResult result; // [rsp+70h] [rbp+8h]

  v2 = meshShape;
  v3 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, EXTENDED_MESH, COLLECTION_EXTENDED_MESH);
  v4 = 0;
  v5 = (signed __int64)&v3->m_embeddedTrianglesSubpart;
  v6 = (signed __int64)&v3->m_trianglesSubparts;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShape'};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  *(_QWORD *)v5 = 10i64;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_OWORD *)(v5 + 80) = 0i64;
  *(_QWORD *)(v5 + 8) = 0i64;
  *(_QWORD *)(v5 + 24) = 0i64;
  *(_BYTE *)(v5 + 75) = 0;
  *(_OWORD *)(v5 + 96) = 0i64;
  *(hkQuaternionf *)(v5 + 112) = (hkQuaternionf)qi.m_vec.m_quad;
  *(hkVector4f *)(v5 + 128) = (hkVector4f)query.m_quad;
  *(_QWORD *)v6 = 0i64;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 2147483648;
  v3->m_shapesSubparts.m_data = 0i64;
  v3->m_shapesSubparts.m_size = 0;
  v3->m_shapesSubparts.m_capacityAndFlags = 2147483648;
  v3->m_weldingInfo.m_data = 0i64;
  v3->m_weldingInfo.m_size = 0;
  v3->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v3->m_triangleRadius = v2->m_radius;
  v3->m_numBitsForSubpartIndex = v2->m_numBitsForSubpartIndex;
  v3->m_weldingType.m_storage = v2->m_weldingType.m_storage;
  v7 = v3->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v2->m_weldingInfo.m_size )
  {
    if ( v3->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        2 * v7);
    result.m_enum = 2 * v2->m_weldingInfo.m_size;
    v3->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                     (int *)&result);
    v3->m_weldingInfo.m_capacityAndFlags = result.m_enum / 2;
  }
  v8 = v2->m_weldingInfo.m_size;
  v9 = v3->m_weldingInfo.m_data;
  v3->m_weldingInfo.m_size = v8;
  v10 = v8;
  if ( (signed int)v8 > 0 )
  {
    v11 = (char *)((char *)v2->m_weldingInfo.m_data - (char *)v9);
    do
    {
      v12 = *(unsigned __int16 *)((char *)v9 + (_QWORD)v11);
      ++v9;
      *(v9 - 1) = v12;
      --v10;
    }
    while ( v10 );
  }
  v13 = v2->m_subparts.m_size;
  if ( v13 == 1 )
  {
    *(_QWORD *)v6 = v5;
    v3->m_trianglesSubparts.m_size = 1;
    v3->m_trianglesSubparts.m_capacityAndFlags = -2147483647;
  }
  else
  {
    v14 = v3->m_trianglesSubparts.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      v16 = v2->m_subparts.m_size;
      if ( v13 < v15 )
        v16 = v15;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_trianglesSubparts,
        v16,
        144);
    }
    v3->m_trianglesSubparts.m_size = v13;
  }
  v3->m_defaultCollisionFilterInfo = 0;
  if ( v2->m_subparts.m_size > 0 )
  {
    v17 = 0i64;
    v18 = 0i64;
    do
    {
      ++v18;
      *(_DWORD *)(*(_QWORD *)v6 + v17 + 32) = *((_DWORD *)&v2->m_subparts.m_data[v18] - 11);
      *(_QWORD *)(*(_QWORD *)v6 + v17 + 8) = *((_QWORD *)&v2->m_subparts.m_data[v18] - 5);
      *(_WORD *)(*(_QWORD *)v6 + v17 + 6) = *((unsigned __int8 *)&v2->m_subparts.m_data[v18] - 32);
      *(_WORD *)(v17 + *(_QWORD *)v6) = *(_WORD *)(v17 + *(_QWORD *)v6) & 0xFFF9 | 2
                                                                                 * (*((_BYTE *)&v2->m_subparts.m_data[v18]
                                                                                    - 55) & 3);
      *(_QWORD *)(*(_QWORD *)v6 + v17 + 16) = *((_QWORD *)&v2->m_subparts.m_data[v18] - 3);
      *(_WORD *)(*(_QWORD *)v6 + v17 + 4) = *((_WORD *)&v2->m_subparts.m_data[v18] - 8);
      ++v4;
      *(_WORD *)(v17 + *(_QWORD *)v6) = *(_WORD *)(v17 + *(_QWORD *)v6) & 7 | 8
                                                                            * *((_WORD *)&v2->m_subparts.m_data[v18] - 6);
      *(_QWORD *)(*(_QWORD *)v6 + v17 + 40) = v2->m_subparts.m_data[v18 - 1].m_vertexBase;
      *(_WORD *)(*(_QWORD *)v6 + v17 + 64) = *((_WORD *)&v2->m_subparts.m_data[v18] - 36);
      *(_DWORD *)(*(_QWORD *)v6 + v17 + 48) = *((_DWORD *)&v2->m_subparts.m_data[v18] - 17);
      *(_QWORD *)(*(_QWORD *)v6 + v17 + 56) = *((_QWORD *)&v2->m_subparts.m_data[v18] - 8);
      *(_BYTE *)(*(_QWORD *)v6 + v17 + 74) = *((_BYTE *)&v2->m_subparts.m_data[v18] - 56);
      *(_WORD *)(*(_QWORD *)v6 + v17 + 72) = *((_WORD *)&v2->m_subparts.m_data[v18] - 26);
      *(_DWORD *)(*(_QWORD *)v6 + v17 + 68) = *((_DWORD *)&v2->m_subparts.m_data[v18] - 2);
      *(_OWORD *)(*(_QWORD *)v6 + v17 + 80) = 0i64;
      *(_BYTE *)(*(_QWORD *)v6 + v17 + 75) = *((_BYTE *)&v2->m_subparts.m_data[v18] - 48);
      v19 = *(_QWORD *)v6;
      *(hkVector4f *)(v19 + v17 + 96) = hkQsTransformf_identityStorage.m_translation;
      *(hkQuaternionf *)(v19 + v17 + 112) = hkQsTransformf_identityStorage.m_rotation;
      *(hkVector4f *)(v19 + v17 + 128) = hkQsTransformf_identityStorage.m_scale;
      v17 += 144i64;
    }
    while ( v4 < v2->m_subparts.m_size );
  }
  hkpExtendedMeshShape::recalcAabbExtents(v3);
  v3->m_cachedNumChildShapes = hkpShapeContainer::getNumChildShapes((hkpShapeContainer *)&v3->vfptr);
}

// File Line: 118
// RVA: 0xD12CB0
void __fastcall hkpExtendedMeshShape::~hkpExtendedMeshShape(hkpExtendedMeshShape *this)
{
  hkpExtendedMeshShape *v1; // rbx
  int v2; // er8
  int v3; // edi
  hkpExtendedMeshShape::ShapesSubpart *v4; // rsi
  int v5; // eax
  int v6; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShape'};
  v1 = this;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  v2 = this->m_weldingInfo.m_capacityAndFlags;
  this->m_weldingInfo.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_weldingInfo.m_data,
      2 * (v2 & 0x3FFFFFFF));
  v1->m_weldingInfo.m_data = 0i64;
  v1->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v3 = v1->m_shapesSubparts.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v1->m_shapesSubparts.m_data[v3];
    do
    {
      hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart(v4);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v1->m_shapesSubparts.m_capacityAndFlags;
  v1->m_shapesSubparts.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_shapesSubparts.m_data,
      80 * (v5 & 0x3FFFFFFF));
  v1->m_shapesSubparts.m_data = 0i64;
  v1->m_shapesSubparts.m_capacityAndFlags = 2147483648;
  v6 = v1->m_trianglesSubparts.m_capacityAndFlags;
  v1->m_trianglesSubparts.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_trianglesSubparts.m_data,
      144 * (v6 & 0x3FFFFFFF));
  v1->m_trianglesSubparts.m_data = 0i64;
  v1->m_trianglesSubparts.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 127
// RVA: 0xD12B00
void __fastcall hkpExtendedMeshShape::hkpExtendedMeshShape(hkpExtendedMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpExtendedMeshShape *v2; // rbx
  int v3; // ecx
  __int64 v4; // rdx
  hkpExtendedMeshShape::TrianglesSubpart *v5; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkpExtendedMeshShape::ShapesSubpart *v8; // rcx
  hkpExtendedMeshShape::ShapesSubpart *v9; // rax
  hkpExtendedMeshShape::TrianglesSubpart *v10; // rcx
  signed __int64 v11; // rdx
  signed __int64 v12; // r8
  const float *v13; // rax
  int v14; // eax
  bool v15; // zf
  int flaga; // [rsp+38h] [rbp+10h]

  flaga = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable'{for `hkpShapeContainer'};
  if ( flaga )
  {
    v3 = 0;
    v2->m_collectionType.m_storage = 1;
    if ( v2->m_trianglesSubparts.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = v2->m_trianglesSubparts.m_data;
        if ( !(v5[v4].m_typeAndFlags & 6) )
        {
          v5[v4].m_typeAndFlags &= 0xFFFBu;
          v5[v4].m_typeAndFlags |= 2u;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < v2->m_trianglesSubparts.m_size );
    }
    v6 = 0;
    if ( v2->m_shapesSubparts.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = &v2->m_shapesSubparts.m_data[v6];
        if ( v8 )
          hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(v8, (hkFinishLoadedObjectFlag)flaga);
        v9 = v2->m_shapesSubparts.m_data;
        if ( !(v9[v7].m_typeAndFlags & 6) )
        {
          v9[v7].m_typeAndFlags &= 0xFFFBu;
          v9[v7].m_typeAndFlags |= 2u;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v2->m_shapesSubparts.m_size );
    }
    if ( v2->m_trianglesSubparts.m_size == 1 )
    {
      v10 = v2->m_trianglesSubparts.m_data;
      v11 = 18i64;
      v12 = (char *)v2 - (char *)v10;
      do
      {
        v13 = *(const float **)&v10->m_typeAndFlags;
        v10 = (hkpExtendedMeshShape::TrianglesSubpart *)((char *)v10 + 8);
        *(const float **)((char *)&v10->m_vertexBase + v12) = v13;
        --v11;
      }
      while ( v11 );
      v14 = v2->m_trianglesSubparts.m_capacityAndFlags;
      v2->m_trianglesSubparts.m_size = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v2->m_trianglesSubparts.m_data,
          144 * (v14 & 0x3FFFFFFF));
      v2->m_trianglesSubparts.m_capacityAndFlags = 2147483648;
      v2->m_trianglesSubparts.m_data = &v2->m_embeddedTrianglesSubpart;
      v2->m_trianglesSubparts.m_size = 1;
      v2->m_trianglesSubparts.m_capacityAndFlags = -2147483647;
    }
    v15 = v2->m_cachedNumChildShapes == -1;
    v2->m_type.m_storage = 13;
    if ( v15 )
      v2->m_cachedNumChildShapes = 2147483648;
  }
  else
  {
    v2->m_type.m_storage = 13;
  }
}

// File Line: 177
// RVA: 0xD13360
void __fastcall hkpExtendedMeshShape::setWeldingInfo(hkpExtendedMeshShape *this, unsigned int key, __int16 weldingInfo)
{
  __int16 v3; // r15
  signed int v4; // ebp
  hkpExtendedMeshShape *v5; // rsi
  int v6; // ecx
  int v7; // ebx
  hkpExtendedMeshShape::TrianglesSubpart *v8; // rdi
  __int64 v9; // rax
  int v10; // eax
  int v11; // eax
  int v12; // er9
  __int64 v13; // rdx
  unsigned __int16 *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+68h] [rbp+10h]

  v3 = weldingInfo;
  v4 = key;
  v5 = this;
  if ( !this->m_weldingInfo.m_size )
  {
    v6 = 0;
    v7 = 0;
    if ( v5->m_trianglesSubparts.m_size > 0 )
    {
      v8 = v5->m_trianglesSubparts.m_data;
      v9 = 0i64;
      do
      {
        v8[v9].m_triangleOffset = v7;
        v8 = v5->m_trianglesSubparts.m_data;
        ++v6;
        v7 += v8[v9].m_numTriangleShapes;
        ++v9;
      }
      while ( v6 < v5->m_trianglesSubparts.m_size );
    }
    if ( (v5->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v7 )
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_weldingInfo,
        v7,
        2);
    v10 = v5->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v10 < v7 )
    {
      v11 = 2 * v10;
      v12 = v7;
      if ( v7 < v11 )
        v12 = v11;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_weldingInfo,
        v12,
        2);
    }
    v13 = v5->m_weldingInfo.m_size;
    v14 = &v5->m_weldingInfo.m_data[v13];
    v15 = v7 - (signed int)v13;
    if ( v7 - (signed int)v13 > 0 )
    {
      while ( v15 )
      {
        *v14 = 0;
        ++v14;
        --v15;
      }
    }
    v5->m_weldingInfo.m_size = v7;
  }
  if ( v4 >= 0 )
    v5->m_weldingInfo.m_data[(v4 & (0xFFFFFFFF >> v5->m_numBitsForSubpartIndex))
                           + v5->m_trianglesSubparts.m_data[(v4 & 0x7FFFFFFFu) >> (32 - v5->m_numBitsForSubpartIndex)].m_triangleOffset] = v3;
}

// File Line: 207
// RVA: 0xD134D0
void __fastcall hkpExtendedMeshShape::initWeldingInfo(hkpExtendedMeshShape *this, hkpWeldingUtility::WeldingType weldingType)
{
  hkpExtendedMeshShape *v2; // rdi
  int v3; // ecx
  int v4; // ebx
  hkpExtendedMeshShape::TrianglesSubpart *v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // r14
  int v8; // eax
  int v9; // eax
  int v10; // er9
  __int64 v11; // rdx
  _WORD *v12; // rdi
  __int64 v13; // rcx
  int v14; // er8
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  this->m_weldingType.m_storage = weldingType;
  if ( weldingType == 6 )
  {
    v14 = this->m_weldingInfo.m_capacityAndFlags;
    this->m_weldingInfo.m_size = 0;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * (v14 & 0x3FFFFFFF));
    v2->m_weldingInfo.m_data = 0i64;
    v2->m_weldingInfo.m_capacityAndFlags = 2147483648;
  }
  else
  {
    v3 = 0;
    v4 = 0;
    if ( v2->m_trianglesSubparts.m_size > 0 )
    {
      v5 = v2->m_trianglesSubparts.m_data;
      v6 = 0i64;
      do
      {
        v5[v6].m_triangleOffset = v4;
        v5 = v2->m_trianglesSubparts.m_data;
        ++v3;
        v4 += v5[v6].m_numTriangleShapes;
        ++v6;
      }
      while ( v3 < v2->m_trianglesSubparts.m_size );
    }
    v7 = (signed __int64)&v2->m_weldingInfo;
    if ( (v2->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v4 )
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_weldingInfo,
        v4,
        2);
    v8 = v2->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v4 )
    {
      v9 = 2 * v8;
      v10 = v4;
      if ( v4 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_weldingInfo,
        v10,
        2);
    }
    v11 = v2->m_weldingInfo.m_size;
    v12 = (_WORD *)(*(_QWORD *)v7 + 2 * v11);
    v13 = v4 - (signed int)v11;
    if ( v4 - (signed int)v11 > 0 )
    {
      while ( v13 )
      {
        *v12 = 0;
        ++v12;
        --v13;
      }
    }
    *(_DWORD *)(v7 + 8) = v4;
  }
}

// File Line: 232
// RVA: 0xD130F0
__int64 __fastcall hkpExtendedMeshShape::getNumChildShapes(hkpExtendedMeshShape *this)
{
  hkpExtendedMeshShape *v1; // rbx
  __int64 result; // rax

  v1 = this;
  if ( this->m_shapesSubparts.m_size >= 0 )
    return (unsigned int)this->m_shapesSubparts.m_size;
  result = hkpShapeContainer::getNumChildShapes((hkpShapeContainer *)this);
  v1->m_shapesSubparts.m_size = result;
  return result;
}

// File Line: 246
// RVA: 0xD13130
__int64 __fastcall hkpExtendedMeshShape::getFirstKey(hkpExtendedMeshShape *this)
{
  hkpExtendedMeshShape *v1; // rbx
  float v2; // ecx
  __int64 result; // rax
  unsigned int v4; // edi
  hkVector4f *v5; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-218h]
  char v7; // [rsp+30h] [rbp-208h]

  v1 = this;
  v2 = this->m_aabbCenter.m_quad.m128_f32[2];
  if ( !(LODWORD(v2) + v1->m_numBitsForSubpartIndex) )
    return 0xFFFFFFFFi64;
  v4 = 2147483648;
  if ( v2 != 0.0 )
    v4 = 0;
  v5 = (hkVector4f *)((__int64 (__fastcall *)(hkpExtendedMeshShape *, _QWORD, char *))v1->vfptr[2].__first_virtual_table_function__)(
                       v1,
                       v4,
                       &v7);
  if ( v5[1].m_quad.m128_i8[0] == 2
    && (tolerance.m_real = _mm_shuffle_ps(
                             (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                             (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                             0),
        hkcdTriangleUtil::isDegenerate(v5 + 3, v5 + 4, v5 + 5, &tolerance)) )
  {
    result = ((__int64 (__fastcall *)(hkpExtendedMeshShape *, _QWORD))v1->vfptr[1].__first_virtual_table_function__)(
               v1,
               v4);
  }
  else
  {
    result = v4;
  }
  return result;
}

// File Line: 273
// RVA: 0xD13200
signed __int64 __fastcall hkpExtendedMeshShape::getNextKey(hkpExtendedMeshShape *this, unsigned int initialKey)
{
  hkpExtendedMeshShape *v2; // r14
  unsigned int v3; // esi
  __int64 v4; // rdi
  signed int v5; // ebx
  unsigned int v6; // er15
  unsigned int v7; // ebp
  hkVector4f *v8; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-228h]
  char v11; // [rsp+30h] [rbp-218h]

  v2 = this;
  v3 = (initialKey & 0x7FFFFFFF) >> (32 - this->m_aabbHalfExtents.m_quad.m128_u32[2]);
  v4 = v3;
  v5 = initialKey & (0xFFFFFFFF >> this->m_aabbHalfExtents.m_quad.m128_i32[2]);
  v6 = initialKey & 0x80000000;
  while ( 1 )
  {
    while ( 1 )
    {
      ++v5;
      if ( v6 )
        break;
      if ( v5 < *(_DWORD *)(v2->m_aabbCenter.m_quad.m128_u64[0] + 144 * v4 + 32) )
        goto LABEL_10;
      ++v3;
      v5 = 0;
      ++v4;
      if ( v3 < v2->m_aabbCenter.m_quad.m128_i32[2] )
        goto LABEL_10;
      if ( !v2->m_numBitsForSubpartIndex )
        return 0xFFFFFFFFi64;
      v3 = 0;
      v4 = 0i64;
      v6 = 2147483648;
      v5 = -1;
    }
    if ( v5 >= SLODWORD(v2->m_materialClass[v4].m_declaredMembers) )
      break;
LABEL_10:
    v7 = v5 | v6 | (v3 << (32 - v2->m_aabbHalfExtents.m_quad.m128_i8[8]));
    v8 = (hkVector4f *)((__int64 (__fastcall *)(hkpExtendedMeshShape *, _QWORD, char *))v2->vfptr[2].__first_virtual_table_function__)(
                         v2,
                         v5 | v6 | (v3 << (32 - v2->m_aabbHalfExtents.m_quad.m128_i8[8])),
                         &v11);
    if ( v8[1].m_quad.m128_i8[0] == 2 )
    {
      tolerance.m_real = _mm_shuffle_ps(
                           (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                           (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                           0);
      if ( hkcdTriangleUtil::isDegenerate(v8 + 3, v8 + 4, v8 + 5, &tolerance) )
        continue;
    }
    return v7;
  }
  ++v3;
  ++v4;
  if ( v3 < v2->m_numBitsForSubpartIndex )
  {
    v5 = 0;
    goto LABEL_10;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 338
// RVA: 0xD14350
__int64 __fastcall hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(hkpExtendedMeshShape *this, hkpExtendedMeshShape::TrianglesSubpart *subpart, int subpartIndex)
{
  unsigned int v3; // edi
  int v4; // er15
  hkpExtendedMeshShape::TrianglesSubpart *v5; // rsi
  int v6; // ebx
  hkpExtendedMeshShape *i; // rbp
  hkVector4f *v8; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-228h]
  char buffer[512]; // [rsp+30h] [rbp-218h]

  v3 = 0;
  v4 = subpartIndex;
  v5 = subpart;
  v6 = 0;
  for ( i = this; v6 < v5->m_numTriangleShapes; ++v6 )
  {
    v8 = (hkVector4f *)hkpExtendedMeshShape::getChildShape(
                         (hkpExtendedMeshShape *)((char *)i + 32),
                         v6 | (unsigned int)(v4 << (32 - LOBYTE(i->m_numBitsForSubpartIndex))),
                         (char (*)[512])buffer);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(v8 + 3, v8 + 4, v8 + 5, &tolerance) )
      ++v3;
  }
  return v3;
}

// File Line: 358
// RVA: 0xD14410
__int64 __fastcall hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(hkpExtendedMeshShape *this, hkpExtendedMeshShape::ShapesSubpart *subpart)
{
  return (unsigned int)subpart->m_childShapes.m_size;
}

// File Line: 438
// RVA: 0xD13630
hkpShape *__fastcall hkpExtendedMeshShape::getChildShape(hkpExtendedMeshShape *this, unsigned int key, char (*buffer)[512])
{
  hkpExtendedMeshShape *v3; // r9
  char (*v4)[512]; // rbx
  signed int v5; // er10
  signed int v6; // er11
  __m128 *v7; // r8
  int v8; // eax
  _QWORD *v9; // rdx
  signed __int64 v10; // r10
  __int64 *v11; // rcx
  __int64 v12; // rax
  __int16 v13; // cx
  __int16 v14; // di
  unsigned __int8 *v15; // rdx
  int v16; // er10
  int v17; // esi
  int v18; // edx
  unsigned __int64 v19; // rbp
  int v20; // er14
  float v21; // xmm0_4
  __m128 v22; // xmm3
  unsigned __int64 v23; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm9
  __m128 v26; // xmm11
  __m128 v27; // xmm6
  __m128 v28; // xmm3
  __m128 v29; // xmm8
  __m128 v30; // xmm1
  __m128 v31; // xmm12
  __m128 v32; // xmm2
  __m128 v33; // xmm10
  __m128 v34; // xmm1
  __m128 v35; // xmm10
  __m128 v36; // xmm2
  __m128 v37; // xmm4
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm3
  signed __int64 v43; // r8
  unsigned __int64 v44; // rcx
  unsigned __int64 v45; // rdx
  __int64 v46; // rax
  hkpConvexShape *v47; // rbp
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __int64 v51; // rax
  hkRotationf v52; // [rsp+30h] [rbp-1C8h]
  __int128 v53; // [rsp+60h] [rbp-198h]
  char v54; // [rsp+BFh] [rbp-139h]
  char v55; // [rsp+FFh] [rbp-F9h]

  v3 = this;
  v4 = buffer;
  v5 = (key & 0x7FFFFFFF) >> (32 - this->m_aabbHalfExtents.m_quad.m128_u32[2]);
  v6 = key & (0xFFFFFFFF >> this->m_aabbHalfExtents.m_quad.m128_i32[2]);
  if ( (key & 0x80000000) == 0 )
  {
    v7 = (__m128 *)((unsigned __int64)&v55 & 0xFFFFFFFFFFFFFF70ui64);
    if ( this->m_aabbCenter.m_quad.m128_i32[2] == 1 )
    {
      v7 = (__m128 *)&this->m_type;
    }
    else
    {
      v8 = 9 * v5;
      v9 = (_QWORD *)((unsigned __int64)&v55 & 0xFFFFFFFFFFFFFF70ui64);
      v10 = 4i64;
      v11 = (__int64 *)(this->m_aabbCenter.m_quad.m128_u64[0] + 16 * v8);
      do
      {
        v12 = *v11;
        v9 += 4;
        v11 += 4;
        *(v9 - 4) = v12;
        *(v9 - 3) = *(v11 - 3);
        *(v9 - 2) = *(v11 - 2);
        *(v9 - 1) = *(v11 - 1);
        --v10;
      }
      while ( v10 );
      *v9 = *v11;
      v9[1] = v11[1];
    }
    v13 = v6 & v7[4].m128_i8[11];
    v14 = 0;
    v15 = (unsigned __int8 *)(v7[3].m128_u64[1] + v6 * v7[4].m128_u16[4]);
    switch ( v7[4].m128_i8[10] )
    {
      case 1:
        v16 = *v15;
        v17 = v15[(signed __int16)(v13 + 1)];
        v18 = v15[(signed __int16)((v13 ^ 1) + 1)];
        break;
      case 2:
        v16 = *(unsigned __int16 *)v15;
        v17 = *(unsigned __int16 *)&v15[2 * (signed __int16)(v13 + 1)];
        v18 = *(unsigned __int16 *)&v15[2 * (signed __int16)((v13 ^ 1) + 1)];
        break;
      case 3:
        v16 = *(_DWORD *)v15;
        v17 = *(_DWORD *)&v15[4 * (signed __int16)(v13 + 1)];
        v18 = *(_DWORD *)&v15[4 * (signed __int16)((v13 ^ 1) + 1)];
        break;
      default:
        v16 = 0;
        v17 = 0;
        v18 = 0;
        break;
    }
    v19 = v7[2].m128_u64[1];
    v20 = v7[4].m128_u16[0];
    if ( v4 )
    {
      v21 = hkConvexShapeDefaultRadius;
      *(_DWORD *)&(*v4)[8] = 0x1FFFF;
      *(_DWORD *)&(*v4)[16] = 1026;
      *(float *)&(*v4)[32] = v21;
      *(_QWORD *)&(*v4)[24] = 0i64;
      *(_QWORD *)v4 = &hkpTriangleShape::`vftable';
      *(_DWORD *)&(*v4)[40] = 393216;
      *(_OWORD *)&(*v4)[96] = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    v22 = v7[5];
    v23 = v7[1].m128_u64[1];
    (*v4)[16] = 2;
    *(_QWORD *)&(*v4)[24] = v23;
    LODWORD(v23) = v3->m_shapesSubparts.m_capacityAndFlags;
    *(__m128 *)&(*v4)[96] = v22;
    v24 = _mm_mul_ps(v22, v22);
    *(_DWORD *)&(*v4)[32] = v23;
    (*v4)[42] = (char)v3->m_shapesSubparts.m_data;
    (*v4)[43] = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) > 0.0;
    if ( v3->m_trianglesSubparts.m_size )
      v14 = *(&v3->m_trianglesSubparts.m_data->m_typeAndFlags + v6 + (signed __int64)v7[4].m128_i32[1]);
    v25 = v7[7];
    *(_WORD *)&(*v4)[40] = v14;
    v26 = _mm_shuffle_ps(v25, v25, 255);
    v27 = _mm_shuffle_ps(v25, v25, 201);
    v28 = _mm_mul_ps(
            _mm_movelh_ps(
              (__m128)*(unsigned __int64 *)(v20 * v16 + v19),
              (__m128)*(unsigned int *)(v20 * v16 + v19 + 8)),
            v7[8]);
    v29 = _mm_mul_ps(
            _mm_movelh_ps(
              (__m128)*(unsigned __int64 *)(v20 * v17 + v19),
              (__m128)*(unsigned int *)(v20 * v17 + v19 + 8)),
            v7[8]);
    v30 = _mm_mul_ps(v28, v25);
    v31 = _mm_mul_ps(
            _mm_movelh_ps(
              (__m128)*(unsigned __int64 *)(v20 * v18 + v19),
              (__m128)*(unsigned int *)(v20 * v18 + v19 + 8)),
            v7[8]);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v25), _mm_mul_ps(v28, v27));
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v34 = _mm_mul_ps(v29, v25);
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v33, v25),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v28)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v26));
    v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v25), _mm_mul_ps(v29, v27));
    v37 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170)),
            v25);
    v38 = _mm_mul_ps(v31, v25);
    v39 = _mm_add_ps(
            _mm_add_ps(v37, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v29)),
            _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v26));
    v40 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v25), _mm_mul_ps(v31, v27));
    v41 = v7[6];
    v42 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                  _mm_shuffle_ps(v38, v38, 170)),
                v25),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v31)),
            _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v26));
    *(__m128 *)&(*v4)[48] = _mm_add_ps(_mm_add_ps(v35, v35), v41);
    *(__m128 *)&(*v4)[64] = _mm_add_ps(_mm_add_ps(v39, v39), v41);
    *(__m128 *)&(*v4)[80] = _mm_add_ps(_mm_add_ps(v42, v42), v41);
    return (hkpShape *)v4;
  }
  v43 = 10i64;
  v44 = (unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64;
  v45 = (unsigned __int64)&v3->m_materialClass[v5] - ((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64);
  do
  {
    v46 = *(_QWORD *)(v45 + v44);
    v44 += 8i64;
    *(_QWORD *)(v44 - 8) = v46;
    --v43;
  }
  while ( v43 );
  v47 = *(hkpConvexShape **)(*(_QWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x20) + 8i64 * v6);
  if ( !(*(_DWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x4C) & 0xC0FFFFFF) )
    return *(hkpShape **)(*(_QWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x20) + 8i64 * v6);
  if ( (*(_DWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x4C) & 0xC0FFFFFF) != 1 )
  {
    hkRotationf::set(&v52, (hkQuaternionf *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 48));
    v53 = *(_OWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x40);
    if ( v4 )
    {
      hkpConvexTransformShape::hkpConvexTransformShape((hkpConvexTransformShape *)v4, v47, (hkTransformf *)&v52, 0);
      return (hkpShape *)v51;
    }
    return 0i64;
  }
  if ( !v4 )
    return 0i64;
  hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
    (hkpConvexTransformShapeBase *)v4,
    CONVEX_TRANSLATE,
    v47->m_radius,
    *(hkpConvexShape **)(*(_QWORD *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x20) + 8i64 * v6),
    0);
  *(_DWORD *)&(*v4)[56] = 0;
  v49 = *(__m128 *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x40);
  v50 = *(__m128 *)(((unsigned __int64)&v54 & 0xFFFFFFFFFFFFFFB0ui64) + 0x40);
  *(_QWORD *)v4 = &hkpConvexTranslateShape::`vftable';
  *(__m128 *)&(*v4)[64] = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v50, (__m128)0i64), 196);
  return (hkpShape *)v4;
}

// File Line: 670
// RVA: 0xD13030
hkpMeshMaterial *__fastcall hkpExtendedMeshShape::getMeshMaterial(hkpExtendedMeshShape *this, unsigned int key)
{
  unsigned int v2; // er10
  unsigned int v3; // er11
  hkpExtendedMeshShape::TrianglesSubpart *v4; // rcx
  unsigned __int8 *v5; // r9
  int v6; // er8
  __int64 v7; // rdx
  __int64 v8; // rax

  v2 = (key & 0x7FFFFFFF) >> (32 - this->m_numBitsForSubpartIndex);
  v3 = key & (0xFFFFFFFF >> this->m_numBitsForSubpartIndex);
  if ( (key & 0x80000000) != 0 )
  {
    v4 = (hkpExtendedMeshShape::TrianglesSubpart *)&this->m_shapesSubparts.m_data[v2];
  }
  else if ( this->m_trianglesSubparts.m_size == 1 )
  {
    v4 = &this->m_embeddedTrianglesSubpart;
  }
  else
  {
    v4 = &this->m_trianglesSubparts.m_data[v2];
  }
  v5 = (unsigned __int8 *)v4->m_materialIndexBase;
  v6 = v4->m_materialStriding;
  if ( !v5 || v6 <= 0 )
    return 0i64;
  v7 = (signed int)(v3 * v4->m_materialIndexStriding);
  if ( (v4->m_typeAndFlags & 6) == 2 )
    v8 = v6 * v5[v7];
  else
    v8 = v6 * *(unsigned __int16 *)&v5[v7];
  return (hkpMeshMaterial *)((char *)v4->m_materialBase + v8);
}

// File Line: 737
// RVA: 0xD13B50
__int64 __fastcall hkpExtendedMeshShape::getCollisionFilterInfo(hkpExtendedMeshShape *this, unsigned int key)
{
  hkpExtendedMeshShape *v2; // rbx
  hkpMeshMaterial *v3; // rax
  __int64 result; // rax

  v2 = this;
  v3 = hkpExtendedMeshShape::getMeshMaterial((hkpExtendedMeshShape *)((char *)this - 32), key);
  if ( v3 )
    result = v3->m_filterInfo;
  else
    result = HIDWORD(v2->m_shapesSubparts.m_data);
  return result;
}

// File Line: 752
// RVA: 0xD14440
void __fastcall addToAabb(hkAabb *aabb, hkQsTransformf *localToWorld, const float *v)
{
  hkQuaternionf v3; // xmm2
  __m128 v4; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm4
  hkVector4f v10; // xmm1

  v3.m_vec.m_quad = (__m128)localToWorld->m_rotation;
  v4 = _mm_mul_ps(
         (__m128)_mm_srli_si128(
                   _mm_slli_si128(
                     (__m128i)_mm_movelh_ps((__m128)*(unsigned __int64 *)v, (__m128)*((unsigned int *)v + 2)),
                     4),
                   4),
         localToWorld->m_scale.m_quad);
  v5 = _mm_mul_ps(localToWorld->m_rotation.m_vec.m_quad, v4);
  v6 = _mm_shuffle_ps(localToWorld->m_rotation.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), v4));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v6, v6), (__m128)xmmword_141A711B0), v4)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6));
  v9 = _mm_add_ps(_mm_add_ps(v8, v8), localToWorld->m_translation.m_quad);
  v10.m_quad = _mm_max_ps(aabb->m_max.m_quad, v9);
  aabb->m_min.m_quad = _mm_min_ps(aabb->m_min.m_quad, v9);
  aabb->m_max = (hkVector4f)v10.m_quad;
}

// File Line: 765
// RVA: 0xD13B90
void __fastcall hkpExtendedMeshShape::getAabb(hkpExtendedMeshShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkVector4f v4; // xmm1
  __m128 v5; // xmm6
  hkVector4f v6; // xmm1
  __m128 v7; // xmm2

  v4.m_quad = (__m128)this->m_aabbHalfExtents;
  v5 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 0),
                                  localToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(this->m_aabbHalfExtents.m_quad, v4.m_quad, 85),
                                  localToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170),
                                  localToWorld->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0)));
  v6.m_quad = (__m128)this->m_aabbCenter;
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), localToWorld->m_rotation.m_col0.m_quad),
             _mm_mul_ps(
               _mm_shuffle_ps(this->m_aabbCenter.m_quad, v6.m_quad, 85),
               localToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), localToWorld->m_rotation.m_col2.m_quad)),
         localToWorld->m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v7, v5);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5),
                        v7);
}

// File Line: 777
// RVA: 0xD13D40
void __fastcall hkpExtendedMeshShape::calcAabbExtents(hkpExtendedMeshShape::TrianglesSubpart *part, hkAabb *out)
{
  int v2; // ebx
  hkAabb *v3; // rdi
  __m128 v4; // xmm8
  const float *v5; // r8
  unsigned __int16 *v6; // r9
  int v7; // edx
  __int64 v8; // r10
  __int64 v9; // r11
  __int64 v10; // rdx
  int v11; // eax
  hkQuaternionf v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm4
  __m128 v19; // xmm7
  __m128 v20; // xmm8
  hkQuaternionf v21; // xmm2
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm4
  __m128 v28; // xmm7
  __m128 v29; // xmm8
  hkQuaternionf v30; // xmm2
  __m128 v31; // xmm6
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 v36; // xmm4

  v2 = 0;
  v3 = out;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  if ( part->m_numTriangleShapes > 0 )
  {
    v4 = (__m128)xmmword_141A712F0;
    while ( 1 )
    {
      v5 = part->m_vertexBase;
      v6 = (unsigned __int16 *)((char *)part->m_indexBase + v2 * part->m_indexStriding);
      if ( part->m_stridingType.m_storage == 1 )
        break;
      v7 = part->m_vertexStriding;
      if ( part->m_stridingType.m_storage == 2 )
      {
        v8 = v7 * *v6;
        v9 = v7 * v6[1];
        v11 = v6[2];
LABEL_8:
        v10 = v7 * v11;
        goto LABEL_9;
      }
      v8 = (unsigned int)(v7 * *(_DWORD *)v6);
      v9 = (unsigned int)(v7 * *((_DWORD *)v6 + 1));
      v10 = (unsigned int)(*((_DWORD *)v6 + 2) * v7);
LABEL_9:
      v12.m_vec.m_quad = (__m128)part->m_transform.m_rotation;
      v13 = _mm_shuffle_ps(part->m_transform.m_rotation.m_vec.m_quad, v12.m_vec.m_quad, 255);
      v14 = _mm_mul_ps(
              part->m_transform.m_scale.m_quad,
              (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_movelh_ps(
                                     (__m128)*(unsigned __int64 *)((char *)v5 + v8),
                                     (__m128)*(unsigned int *)((char *)v5 + v8 + 8)),
                          4),
                        4));
      v15 = _mm_mul_ps(part->m_transform.m_rotation.m_vec.m_quad, v14);
      v16 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v12.m_vec.m_quad, v12.m_vec.m_quad, 201), v14));
      v17 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  v12.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v14)),
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v13));
      v18 = _mm_add_ps(_mm_add_ps(v17, v17), part->m_transform.m_translation.m_quad);
      v19 = _mm_min_ps(v3->m_min.m_quad, v18);
      v20 = _mm_max_ps(v4, v18);
      v3->m_min.m_quad = v19;
      v3->m_max.m_quad = v20;
      v21.m_vec.m_quad = (__m128)part->m_transform.m_rotation;
      v22 = _mm_mul_ps(
              (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_movelh_ps(
                                     (__m128)*(unsigned __int64 *)((char *)v5 + v9),
                                     (__m128)*(unsigned int *)((char *)v5 + v9 + 8)),
                          4),
                        4),
              part->m_transform.m_scale.m_quad);
      v23 = _mm_mul_ps(part->m_transform.m_rotation.m_vec.m_quad, v22);
      v24 = _mm_shuffle_ps(part->m_transform.m_rotation.m_vec.m_quad, v21.m_vec.m_quad, 255);
      v25 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 201), v22));
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v21.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v24, v24), (__m128)xmmword_141A711B0), v22)),
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24));
      v27 = _mm_add_ps(_mm_add_ps(v26, v26), part->m_transform.m_translation.m_quad);
      v28 = _mm_min_ps(v19, v27);
      v29 = _mm_max_ps(v20, v27);
      ++v2;
      v3->m_min.m_quad = v28;
      v3->m_max.m_quad = v29;
      v30.m_vec.m_quad = (__m128)part->m_transform.m_rotation;
      v31 = _mm_mul_ps(
              (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_movelh_ps(
                                     (__m128)*(unsigned __int64 *)((char *)v5 + v10),
                                     (__m128)*(unsigned int *)((char *)v5 + v10 + 8)),
                          4),
                        4),
              part->m_transform.m_scale.m_quad);
      v32 = _mm_mul_ps(part->m_transform.m_rotation.m_vec.m_quad, v31);
      v33 = _mm_shuffle_ps(part->m_transform.m_rotation.m_vec.m_quad, v30.m_vec.m_quad, 255);
      v34 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v30.m_vec.m_quad, v30.m_vec.m_quad, 201), v31));
      v35 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                    _mm_shuffle_ps(v32, v32, 170)),
                  v30.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v33, v33), (__m128)xmmword_141A711B0), v31)),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v33));
      v36 = _mm_add_ps(_mm_add_ps(v35, v35), part->m_transform.m_translation.m_quad);
      v4 = _mm_max_ps(v29, v36);
      v3->m_min.m_quad = _mm_min_ps(v28, v36);
      v3->m_max.m_quad = v4;
      if ( v2 >= part->m_numTriangleShapes )
        return;
    }
    v7 = part->m_vertexStriding;
    v8 = v7 * *(unsigned __int8 *)v6;
    v9 = v7 * *((unsigned __int8 *)v6 + 1);
    v11 = *((unsigned __int8 *)v6 + 2);
    goto LABEL_8;
  }
}

// File Line: 830
// RVA: 0xD13FF0
void __fastcall hkpExtendedMeshShape::calcAabbExtents(hkpExtendedMeshShape::ShapesSubpart *part, hkAabb *out)
{
  hkAabb *v2; // rbx
  hkpExtendedMeshShape::ShapesSubpart *v3; // rdi
  __int64 v4; // r8
  int v5; // esi
  __int64 v6; // r14
  __m128 v7; // xmm1
  __m128 v8; // [rsp+20h] [rbp-68h]
  __m128 v9; // [rsp+30h] [rbp-58h]
  hkRotationf v10; // [rsp+40h] [rbp-48h]
  hkVector4f v11; // [rsp+70h] [rbp-18h]

  v2 = out;
  v3 = part;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  hkRotationf::set(&v10, &part->m_rotation);
  v5 = 0;
  v11.m_quad = (__m128)v3->m_translation;
  if ( v3->m_childShapes.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpConvexShape *, hkRotationf *, __int64, __m128 *))v3->m_childShapes.m_data[v6].m_pntr->vfptr[2].__vecDelDtor)(
        v3->m_childShapes.m_data[v6].m_pntr,
        &v10,
        v4,
        &v8);
      ++v5;
      ++v6;
      v7 = _mm_max_ps(v2->m_max.m_quad, v9);
      v2->m_min.m_quad = _mm_min_ps(v2->m_min.m_quad, v8);
      v2->m_max.m_quad = v7;
    }
    while ( v5 < v3->m_childShapes.m_size );
  }
}

// File Line: 846
// RVA: 0xD140C0
void __fastcall hkpExtendedMeshShape::recalcAabbExtents(hkpExtendedMeshShape *this)
{
  __m128 v1; // xmm6
  int v2; // edi
  hkpExtendedMeshShape *v3; // rbx
  int v4; // esi
  __m128 v5; // xmm7
  __m128 i; // xmm8
  hkAabb out; // [rsp+20h] [rbp-58h]

  v1 = (__m128)xmmword_141A712F0;
  v2 = 0;
  v3 = this;
  v4 = 0;
  v5 = (__m128)xmmword_141A712A0;
  for ( i = _mm_shuffle_ps((__m128)LODWORD(this->m_triangleRadius), (__m128)LODWORD(this->m_triangleRadius), 0);
        v4 < v3->m_trianglesSubparts.m_size;
        v1 = _mm_max_ps(v1, _mm_add_ps(out.m_max.m_quad, i)) )
  {
    hkpExtendedMeshShape::calcAabbExtents(&v3->m_trianglesSubparts.m_data[v4++], &out);
    v5 = _mm_min_ps(v5, _mm_sub_ps(out.m_min.m_quad, i));
  }
  if ( v3->m_shapesSubparts.m_size > 0 )
  {
    do
    {
      hkpExtendedMeshShape::calcAabbExtents(&v3->m_shapesSubparts.m_data[v2++], &out);
      v5 = _mm_min_ps(v5, out.m_min.m_quad);
      v1 = _mm_max_ps(v1, out.m_max.m_quad);
    }
    while ( v2 < v3->m_shapesSubparts.m_size );
  }
  v3->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v5, v1), (__m128)xmmword_141A711B0);
  v3->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v1, v5), (__m128)xmmword_141A711B0);
}

// File Line: 881
// RVA: 0xD14420
void __fastcall hkpExtendedMeshShape::assertTrianglesSubpartValidity(hkpExtendedMeshShape *this, hkpExtendedMeshShape::TrianglesSubpart *part)
{
  ;
}

// File Line: 905
// RVA: 0xD14430
void __fastcall hkpExtendedMeshShape::assertShapesSubpartValidity(hkpExtendedMeshShape *this, hkpExtendedMeshShape::ShapesSubpart *part)
{
  ;
}

// File Line: 919
// RVA: 0xD12E10
void __fastcall hkpExtendedMeshShape::addTrianglesSubpart(hkpExtendedMeshShape *this, hkpExtendedMeshShape::TrianglesSubpart *part)
{
  hkpExtendedMeshShape::TrianglesSubpart *v2; // rbx
  hkpExtendedMeshShape *v3; // rdi
  hkpExtendedMeshShape::TrianglesSubpart *v4; // rax
  __m128 v5; // xmm7
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  int v8; // er8
  __m128 v9; // xmm0
  __m128 v10; // xmm7
  __m128 v11; // xmm6
  hkAabb out; // [rsp+20h] [rbp-48h]

  v2 = part;
  v3 = this;
  v4 = hkpExtendedMeshShape::expandOneTriangleSubparts(this);
  *(_QWORD *)&v4->m_typeAndFlags = *(_QWORD *)&v2->m_typeAndFlags;
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
  v5 = v3->m_aabbHalfExtents.m_quad;
  v6 = _mm_sub_ps(v3->m_aabbCenter.m_quad, v5);
  v7 = _mm_add_ps(v5, v3->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v4, &out);
  v8 = v3->m_trianglesSubparts.m_size - 1;
  v9 = _mm_shuffle_ps((__m128)LODWORD(v3->m_triangleRadius), (__m128)LODWORD(v3->m_triangleRadius), 0);
  v10 = _mm_max_ps(v7, _mm_add_ps(out.m_max.m_quad, v9));
  v11 = _mm_min_ps(v6, _mm_sub_ps(out.m_min.m_quad, v9));
  v3->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v10, v11), (__m128)xmmword_141A711B0);
  v3->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v10, v11), (__m128)xmmword_141A711B0);
  v3->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(v3, v2, v8);
}

// File Line: 954
// RVA: 0xD12F70
__int64 __fastcall hkpExtendedMeshShape::addShapesSubpart(hkpExtendedMeshShape *this, hkpExtendedMeshShape::ShapesSubpart *part)
{
  hkpExtendedMeshShape::ShapesSubpart *v2; // rdi
  hkpExtendedMeshShape *v3; // rsi
  hkpExtendedMeshShape::ShapesSubpart *v4; // rbx
  __m128 v5; // xmm7
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  hkAabb out; // [rsp+20h] [rbp-48h]

  v2 = part;
  v3 = this;
  v4 = hkpExtendedMeshShape::expandOneShapesSubparts(this);
  hkpExtendedMeshShape::ShapesSubpart::operator=(v4, v2);
  v5 = v3->m_aabbHalfExtents.m_quad;
  v6 = _mm_sub_ps(v3->m_aabbCenter.m_quad, v5);
  v7 = _mm_add_ps(v5, v3->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v4, &out);
  v8 = _mm_max_ps(v7, out.m_max.m_quad);
  v9 = _mm_min_ps(v6, out.m_min.m_quad);
  v3->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v8, v9), (__m128)xmmword_141A711B0);
  v3->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v8, v9), (__m128)xmmword_141A711B0);
  v3->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(v3, v2);
  return (unsigned int)(v3->m_shapesSubparts.m_size - 1);
}

// File Line: 987
// RVA: 0xD12410
void __fastcall hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(hkpExtendedMeshShape::ShapesSubpart *this, hkFinishLoadedObjectFlag flag)
{
  const __m128i *v2; // r8
  signed int v3; // edx
  hkQuaternionf v4; // xmm9
  int v5; // ecx
  __m128 v6; // xmm9
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  char v14; // al

  v2 = (const __m128i *)this;
  if ( flag.m_finishing )
  {
    v3 = 2;
    v4.m_vec.m_quad = (__m128)this->m_rotation;
    v5 = 0;
    v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v4.m_vec.m_quad, v4.m_vec.m_quad, 255), 1u), 1u);
    v7 = _mm_andnot_ps(*(__m128 *)_xmm, v6);
    v8 = _mm_cmpltps(v7, *(__m128 *)_xmm);
    v9 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v7), *(__m128 *)_xmm);
    v10 = _mm_cmpltps(*(__m128 *)_xmm, v7);
    v11 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v9), v10), _mm_andnot_ps(v10, v7));
    v12 = _mm_or_ps(_mm_andnot_ps(v10, _mm_mul_ps(v7, v7)), _mm_and_ps(v10, v9));
    v13 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v12, *(__m128 *)coeff4), *(__m128 *)coeff3), v12),
                          *(__m128 *)coeff2),
                        v12),
                      *(__m128 *)coeff1),
                    v12),
                  *(__m128 *)coeff0),
                v12),
              v11),
            v11);
    v14 = _mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v2 + 4), 1u), 1u),
              _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0)));
    if ( (float)((float)(1.5707964
                       - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                v8,
                                                                _mm_or_ps(
                                                                  _mm_and_ps(
                                                                    _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v13, v13)),
                                                                    v10),
                                                                  _mm_andnot_ps(v10, v13))) | v8.m128_i32[0] & v7.m128_i32[0]) ^ v6.m128_i32[0] & _xmm[0]))
               * 2.0) < 0.001 )
      v3 = 0;
    LOBYTE(v5) = (v14 & 7) != 7;
    v2[4].m128i_i32[3] = v5 | v3 | 0x3F000000;
  }
}

// File Line: 1000
// RVA: 0xD120F0
void __fastcall hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(hkpExtendedMeshShape::ShapesSubpart *this, hkpConvexShape *const *childShapes, int numChildShapes, hkVector4f *offset)
{
  int v4; // ebp
  __int64 v5; // rdi
  hkVector4f *v6; // r13
  hkpConvexShape *const *v7; // r14
  hkpExtendedMeshShape::ShapesSubpart *v8; // r15
  __int64 v9; // r12
  int v10; // er9
  int v11; // eax
  int v12; // eax
  __int64 v13; // rsi
  hkRefPtr<hkpConvexShape> *v14; // rdx
  __int64 v15; // rax
  hkRefPtr<hkpConvexShape> *v16; // rax
  hkReferencedObject **v17; // rbx
  signed __int64 v18; // r14
  hkReferencedObject *v19; // rdi
  hkResult result; // [rsp+70h] [rbp+18h]

  v4 = 0;
  *(_QWORD *)&this->m_typeAndFlags = 11i64;
  v5 = numChildShapes;
  this->m_materialBase = 0i64;
  this->m_materialIndexBase = 0i64;
  this->m_userData = 0i64;
  this->m_childShapes.m_data = 0i64;
  this->m_childShapes.m_size = 0;
  this->m_childShapes.m_capacityAndFlags = 2147483648;
  v6 = offset;
  v7 = childShapes;
  v8 = this;
  this->m_translation = (hkVector4f)offset->m_quad;
  v9 = this->m_childShapes.m_size;
  v10 = v9 + numChildShapes;
  v11 = this->m_childShapes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 >= (signed int)v9 + numChildShapes )
  {
    result.m_enum = 0;
  }
  else
  {
    v12 = 2 * v11;
    if ( v10 < v12 )
      v10 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_childShapes,
      v10,
      8);
  }
  v13 = v5;
  v14 = &v8->m_childShapes.m_data[v8->m_childShapes.m_size];
  if ( (signed int)v5 > 0 )
  {
    v15 = v5;
    do
    {
      if ( v14 )
        v14->m_pntr = 0i64;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v16 = v8->m_childShapes.m_data;
  v8->m_childShapes.m_size += v5;
  v17 = (hkReferencedObject **)&v16[v9];
  if ( (signed int)v5 > 0 )
  {
    v18 = (char *)v7 - (char *)v17;
    do
    {
      v19 = *(hkReferencedObject **)((char *)v17 + v18);
      if ( v19 )
        hkReferencedObject::addReference(*(hkReferencedObject **)((char *)v17 + v18));
      if ( *v17 )
        hkReferencedObject::removeReference(*v17);
      *v17 = v19;
      ++v17;
      --v13;
    }
    while ( v13 );
  }
  result.m_enum = LODWORD(FLOAT_0_001);
  v8->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  LOBYTE(v4) = (_mm_movemask_ps(
                  _mm_cmpltps(
                    (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v6), 1u), 1u),
                    _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0))) & 7) != 7;
  v8->m_translation.m_quad.m128_i32[3] = v4 | 0x3F000000;
}

// File Line: 1016
// RVA: 0xD12270
void __fastcall hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(hkpExtendedMeshShape::ShapesSubpart *this, hkpConvexShape *const *childShapes, int numChildShapes, hkTransformf *transform)
{
  hkpConvexShape *const *v4; // r14
  const __m128i *v5; // r15
  hkQuaternionf *v6; // rcx
  hkTransformf *v7; // rbp
  __int64 v8; // rdi
  __int64 v9; // r12
  int v10; // er9
  int v11; // eax
  int v12; // eax
  __int64 v13; // rsi
  _QWORD *v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rax
  hkReferencedObject **v17; // rbx
  signed __int64 v18; // r14
  hkReferencedObject *v19; // rdi
  __m128i v20; // xmm1
  BOOL v21; // ebx
  bool v22; // al
  signed int v23; // ecx
  hkResult result; // [rsp+70h] [rbp+18h]

  *(_QWORD *)&this->m_typeAndFlags = 11i64;
  v4 = childShapes;
  this->m_materialBase = 0i64;
  this->m_materialIndexBase = 0i64;
  this->m_userData = 0i64;
  this->m_childShapes.m_data = 0i64;
  this->m_childShapes.m_size = 0;
  this->m_childShapes.m_capacityAndFlags = 2147483648;
  v5 = (const __m128i *)this;
  v6 = &this->m_rotation;
  v6[1] = (hkQuaternionf)transform->m_translation;
  v7 = transform;
  v8 = numChildShapes;
  hkQuaternionf::set(v6, &transform->m_rotation);
  v9 = v5[2].m128i_i32[2];
  v10 = v9 + v8;
  v11 = v5[2].m128i_i32[3] & 0x3FFFFFFF;
  if ( v11 >= (signed int)v9 + (signed int)v8 )
  {
    result.m_enum = 0;
  }
  else
  {
    v12 = 2 * v11;
    if ( v10 < v12 )
      v10 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)&v5[2],
      v10,
      8);
  }
  v13 = v8;
  v14 = (_QWORD *)(v5[2].m128i_i64[0] + 8i64 * v5[2].m128i_i32[2]);
  if ( (signed int)v8 > 0 )
  {
    v15 = v8;
    do
    {
      if ( v14 )
        *v14 = 0i64;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v16 = v5[2].m128i_i64[0];
  v5[2].m128i_i32[2] += v8;
  v17 = (hkReferencedObject **)(v16 + 8 * v9);
  if ( (signed int)v8 > 0 )
  {
    v18 = (char *)v4 - (char *)v17;
    do
    {
      v19 = *(hkReferencedObject **)((char *)v17 + v18);
      if ( v19 )
        hkReferencedObject::addReference(*(hkReferencedObject **)((char *)v17 + v18));
      if ( *v17 )
        hkReferencedObject::removeReference(*v17);
      *v17 = v19;
      ++v17;
      --v13;
    }
    while ( v13 );
  }
  v20 = _mm_load_si128(v5 + 4);
  result.m_enum = 981668463;
  v21 = (_mm_movemask_ps(
           _mm_cmpltps(
             (__m128)_mm_srli_epi32(_mm_slli_epi32(v20, 1u), 1u),
             _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0))) & 7) != 7;
  v22 = hkMatrix3f::isApproximatelyEqual((hkMatrix3f *)&v7->m_rotation.m_col0, (hkMatrix3f *)&::transform, 0.001);
  v23 = 2;
  if ( v22 )
    v23 = 0;
  v5[4].m128i_i32[3] = v23 | v21 | 0x3F000000;
}

// File Line: 1029
// RVA: 0xD125A0
void __fastcall hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart(hkpExtendedMeshShape::ShapesSubpart *this)
{
  hkRefPtr<hkpConvexShape> *v1; // rsi
  int v2; // eax
  hkpExtendedMeshShape::ShapesSubpart *v3; // rdi
  __int64 i; // rbx
  hkReferencedObject *v5; // rcx
  int v6; // er8

  v1 = this->m_childShapes.m_data;
  v2 = this->m_childShapes.m_size - 1;
  v3 = this;
  for ( i = v2; i >= 0; v1[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v1[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v3->m_childShapes.m_capacityAndFlags;
  v3->m_childShapes.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_childShapes.m_data,
      8 * v6);
  v3->m_childShapes.m_data = 0i64;
  v3->m_childShapes.m_capacityAndFlags = 2147483648;
}

// File Line: 1035
// RVA: 0xD13C60
signed __int64 __fastcall hkpExtendedMeshShape::calcSizeForSpu(hkpExtendedMeshShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  int v3; // ebp
  hkpShape::CalcSizeForSpuInput *v4; // r12
  hkpExtendedMeshShape *v5; // r15
  __int64 v6; // r14
  int v7; // ebx
  hkpExtendedMeshShape::ShapesSubpart *v8; // rsi
  __int64 v9; // rdi
  signed int v10; // eax
  signed int v11; // ecx

  v3 = 0;
  v4 = input;
  v5 = this;
  if ( this->m_shapesSubparts.m_size <= 0 )
    return 320i64;
  v6 = 0i64;
  while ( 1 )
  {
    v7 = 0;
    v8 = &v5->m_shapesSubparts.m_data[v6];
    if ( v8->m_childShapes.m_size > 0 )
      break;
LABEL_12:
    ++v3;
    ++v6;
    if ( v3 >= v5->m_shapesSubparts.m_size )
      return 320i64;
  }
  v9 = 0i64;
  while ( 1 )
  {
    v10 = ((__int64 (__fastcall *)(hkpConvexShape *, hkpShape::CalcSizeForSpuInput *, signed __int64))v8->m_childShapes.m_data[v9].m_pntr->vfptr[8].__vecDelDtor)(
            v8->m_childShapes.m_data[v9].m_pntr,
            v4,
            256i64);
    if ( v8->m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF )
    {
      v11 = 384;
      if ( (v8->m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF) == 1 )
        v11 = 432;
    }
    else
    {
      v11 = 512;
    }
    if ( v10 < 0 || v10 > v11 )
      return 0xFFFFFFFFi64;
    ++v7;
    ++v9;
    if ( v7 >= v8->m_childShapes.m_size )
      goto LABEL_12;
  }
}

// File Line: 1097
// RVA: 0xD141E0
hkpExtendedMeshShape::TrianglesSubpart *__fastcall hkpExtendedMeshShape::expandOneTriangleSubparts(hkpExtendedMeshShape *this)
{
  hkpExtendedMeshShape::TrianglesSubpart *v1; // rax
  hkArray<hkpExtendedMeshShape::TrianglesSubpart,hkContainerHeapAllocator> *v2; // rbx
  __int64 v3; // rdi
  int v4; // er9
  int v5; // eax
  int v6; // eax
  hkResult result; // [rsp+40h] [rbp+8h]

  if ( this->m_trianglesSubparts.m_size )
  {
    v2 = &this->m_trianglesSubparts;
    v3 = this->m_trianglesSubparts.m_size;
    v4 = v3 + 1;
    v5 = this->m_trianglesSubparts.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < (signed int)v3 + 1 )
    {
      v6 = 2 * v5;
      if ( v4 < v6 )
        v4 = v6;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v4, 144);
    }
    ++v2->m_size;
    v1 = &v2->m_data[v3];
  }
  else
  {
    v1 = &this->m_embeddedTrianglesSubpart;
    this->m_trianglesSubparts.m_size = 1;
    this->m_trianglesSubparts.m_capacityAndFlags = -2147483647;
    this->m_trianglesSubparts.m_data = &this->m_embeddedTrianglesSubpart;
  }
  return v1;
}

// File Line: 1112
// RVA: 0xD14280
hkpExtendedMeshShape::ShapesSubpart *__fastcall hkpExtendedMeshShape::expandOneShapesSubparts(hkpExtendedMeshShape *this)
{
  signed int *v1; // rbx
  __int64 v2; // rdi
  int v3; // er9
  int v4; // eax
  int v5; // eax
  signed __int64 v6; // rcx
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = (signed int *)&this->m_shapesSubparts;
  v2 = this->m_shapesSubparts.m_size;
  v3 = v2 + 1;
  v4 = this->m_shapesSubparts.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 >= (signed int)v2 + 1 )
  {
    result.m_enum = 0;
  }
  else
  {
    v5 = 2 * v4;
    if ( v3 < v5 )
      v3 = v5;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, v3, 80);
  }
  v6 = *(_QWORD *)v1 + 80i64 * v1[2];
  if ( v6 )
  {
    *(_QWORD *)v6 = 11i64;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 8) = 0i64;
    *(_QWORD *)(v6 + 24) = 0i64;
    *(_QWORD *)(v6 + 32) = 0i64;
    *(_DWORD *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 44) = 2147483648;
  }
  ++v1[2];
  return (hkpExtendedMeshShape::ShapesSubpart *)(*(_QWORD *)v1 + 80 * v2);
}

// File Line: 1118
// RVA: 0xD14330
void __fastcall hkpExtendedMeshShape::freeTriangleSubparts(hkpExtendedMeshShape *this)
{
  ;
}

// File Line: 1122
// RVA: 0xD14340
void __fastcall hkpExtendedMeshShape::freeShapesSubparts(hkpExtendedMeshShape *this)
{
  ;
}

