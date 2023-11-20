// File Line: 34
// RVA: 0xC30300
char __fastcall isContainerOk(hkpShapeContainer *container)
{
  hkpShapeContainer *v1; // rdi
  unsigned int v2; // ebx
  hkpShape *v3; // rax
  __int64 v4; // rdx
  char v6; // [rsp+20h] [rbp-208h]

  v1 = container;
  v2 = ((__int64 (*)(void))container->vfptr->getFirstKey)();
  if ( v2 == -1 )
    return 1;
  while ( 1 )
  {
    v3 = v1->vfptr->getChildShape(v1, v2, (char (*)[512])&v6);
    if ( !isShapeOk(v3, v4) )
      break;
    v2 = v1->vfptr->getNextKey(v1, v2);
    if ( v2 == -1 )
      return 1;
  }
  return 0;
}

// File Line: 53
// RVA: 0xC30240
bool __fastcall isShapeOk(hkpShape *shape, __int64 a2)
{
  unsigned int v2; // eax
  hkpShapeContainer *v4; // rax

  v2 = (unsigned __int8)shape->m_type.m_storage;
  while ( 1 )
  {
    switch ( v2 )
    {
      case 0u:
      case 1u:
      case 3u:
      case 4u:
      case 5u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Du:
        return 1;
      case 6u:
      case 7u:
      case 8u:
      case 9u:
      case 0x12u:
      case 0x16u:
      case 0x1Au:
      case 0x1Eu:
        v4 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *, __int64, signed __int64))shape->vfptr[7].__vecDelDtor)(
                                    shape,
                                    a2,
                                    5368709120i64);
        return isContainerOk(v4);
      case 0xAu:
      case 0xBu:
        shape = *(hkpShape **)&shape[1].m_type.m_storage;
        goto LABEL_5;
      case 0xDu:
        return LODWORD(shape[7].m_userData) == 0;
      case 0xEu:
        shape = *(hkpShape **)&shape[1].m_memSizeAndFlags;
LABEL_5:
        v2 = (unsigned __int8)shape->m_type.m_storage;
        if ( v2 > 0x21 )
          return 0;
        break;
      default:
        return 0;
    }
  }
}

// File Line: 127
// RVA: 0xC2FAD0
void __fastcall hkaiPhysics2012ShapeVolume::hkaiPhysics2012ShapeVolume(hkaiPhysics2012ShapeVolume *this, hkpCollisionDispatcher *dispatcher, hkTransformf *transform, hkpShape *shape)
{
  hkpShape *v4; // rsi
  hkTransformf *v5; // r14
  hkpCollisionDispatcher *v6; // rbx
  hkaiPhysics2012ShapeVolume *v7; // rdi
  __int64 v8; // rbx
  hkGeometry *v9; // rsi
  int v10; // eax
  __int64 v11; // rsi
  hkErrStream v12; // [rsp+20h] [rbp-238h]
  char buf; // [rsp+40h] [rbp-218h]

  v4 = shape;
  v5 = transform;
  v6 = dispatcher;
  v7 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012ShapeVolume::`vftable;
  if ( dispatcher )
    hkReferencedObject::addReference((hkReferencedObject *)&dispatcher->vfptr);
  v7->m_dispatcher.m_pntr = v6;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v7->m_shape.m_pntr = v4;
  v8 = 0i64;
  v7->m_shapeTransform.m_rotation.m_col0 = v5->m_rotation.m_col0;
  v7->m_shapeTransform.m_rotation.m_col1 = v5->m_rotation.m_col1;
  v7->m_shapeTransform.m_rotation.m_col2 = v5->m_rotation.m_col2;
  v7->m_shapeTransform.m_translation = v5->m_translation;
  *(_DWORD *)&v7->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  v7->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  v7->m_geometry.m_vertices.m_data = 0i64;
  v7->m_geometry.m_vertices.m_size = 0;
  v7->m_geometry.m_vertices.m_capacityAndFlags = 2147483648;
  v7->m_geometry.m_triangles.m_data = 0i64;
  v7->m_geometry.m_triangles.m_size = 0;
  v7->m_geometry.m_triangles.m_capacityAndFlags = 2147483648;
  if ( !isShapeOk(v4) )
  {
    hkErrStream::hkErrStream(&v12, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v12.vfptr,
      "Trying to use a shape in hkaiPhysics2012ShapeVolume that contains triangles. This might not give the expected resu"
      "lts, as the inside of a triangle or triangle mesh isnt well-defined.");
    hkError::messageWarning(415712427, &buf, "Collide\\hkaiPhysics2012ShapeVolume.cpp", 130);
    hkOstream::~hkOstream((hkOstream *)&v12.vfptr);
  }
  v9 = hkpShapeConverter::toSingleGeometry(v7->m_shape.m_pntr);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v7->m_geometry.m_triangles,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v9->m_triangles);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v7->m_geometry.m_vertices,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v9->m_vertices);
  if ( v9 )
    v9->vfptr->__vecDelDtor((hkBaseObject *)&v9->vfptr, 1u);
  v10 = v7->m_geometry.m_vertices.m_size;
  if ( v10 > 0 )
  {
    v11 = (unsigned int)v10;
    do
    {
      hkVector4f::setTransformedPos(
        &v7->m_geometry.m_vertices.m_data[v8],
        &v7->m_shapeTransform,
        &v7->m_geometry.m_vertices.m_data[v8]);
      ++v8;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 152
// RVA: 0xC2FC80
void __fastcall hkaiPhysics2012ShapeVolume::hkaiPhysics2012ShapeVolume(hkaiPhysics2012ShapeVolume *this, hkFinishLoadedObjectFlag f)
{
  hkGeometry *v2; // rcx

  v2 = &this->m_geometry;
  v2[-2].vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012ShapeVolume::`vftable;
  hkGeometry::hkGeometry(v2, f);
}

// File Line: 156
// RVA: 0xC2FCB0
void __fastcall hkaiPhysics2012ShapeVolume::~hkaiPhysics2012ShapeVolume(hkaiPhysics2012ShapeVolume *this)
{
  hkaiPhysics2012ShapeVolume *v1; // rbx
  hkGeometry *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx

  v1 = this;
  v2 = &this->m_geometry;
  v2[-2].vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012ShapeVolume::`vftable;
  hkGeometry::~hkGeometry(v2);
  v3 = (hkReferencedObject *)&v1->m_shape.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_shape.m_pntr = 0i64;
  v4 = (hkReferencedObject *)&v1->m_dispatcher.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_dispatcher.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 160
// RVA: 0xC2FD10
void __fastcall hkaiPhysics2012ShapeVolume::calcPointsInside(hkaiPhysics2012ShapeVolume *this, hkVector4f *points, int numPoints, hkBitField *pointsInside)
{
  __int64 v4; // rdi
  hkBitField *v5; // r15
  __int64 v6; // r13
  hkVector4f *v7; // rsi
  hkaiPhysics2012ShapeVolume *v8; // r14
  _QWORD **v9; // rax
  hkpCollisionDispatcher *v10; // rax
  hkpCollisionDispatcher *v11; // rax
  hkpCollisionDispatcher *v12; // rbx
  hkReferencedObject *v13; // rcx
  hkpShape *v14; // rcx
  signed int v15; // ebx
  __int64 v16; // r8
  hkpCollisionDispatcher *v17; // rdx
  __int64 v18; // r8
  void (__fastcall *v19)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *); // r12
  __int64 v20; // r14
  void **v21; // [rsp+20h] [rbp-E0h]
  char v22; // [rsp+28h] [rbp-D8h]
  hkpSphereShape *v23; // [rsp+30h] [rbp-D0h]
  int v24; // [rsp+38h] [rbp-C8h]
  __m128 *v25; // [rsp+40h] [rbp-C0h]
  __int64 v26; // [rsp+48h] [rbp-B8h]
  __int64 v27; // [rsp+50h] [rbp-B0h]
  int v28; // [rsp+58h] [rbp-A8h]
  hkTransformf *v29; // [rsp+60h] [rbp-A0h]
  __int64 v30; // [rsp+68h] [rbp-98h]
  hkpCollisionFilter v31; // [rsp+70h] [rbp-90h]
  __m128 v32; // [rsp+C0h] [rbp-40h]
  __m128 v33; // [rsp+D0h] [rbp-30h]
  __m128 v34; // [rsp+E0h] [rbp-20h]
  __m128 v35; // [rsp+F0h] [rbp-10h]
  __m128 v36; // [rsp+100h] [rbp+0h]
  __m128 v37; // [rsp+110h] [rbp+10h]
  hkpSphereShape v38; // [rsp+120h] [rbp+20h]
  hkpCollisionDispatcher *v39; // [rsp+160h] [rbp+60h]
  int v40; // [rsp+16Ch] [rbp+6Ch]
  float v41; // [rsp+170h] [rbp+70h]
  hkpCollisionFilter *v42; // [rsp+178h] [rbp+78h]

  v4 = 0i64;
  v5 = pointsInside;
  v6 = (unsigned int)numPoints;
  v7 = points;
  v8 = this;
  if ( !this->m_dispatcher.m_pntr )
  {
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpCollisionDispatcher *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(
                                      v9[11],
                                      10880i64);
    if ( v10 )
    {
      hkpCollisionDispatcher::hkpCollisionDispatcher(v10, hkpNullAgent::createNullAgent, 0i64);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    hkpAgentRegisterUtil::registerAllAgents(v12);
    v13 = (hkReferencedObject *)&v8->m_dispatcher.m_pntr->vfptr;
    if ( v13 && v13 != (hkReferencedObject *)v12 )
      hkReferencedObject::removeReference(v13);
    v8->m_dispatcher.m_pntr = v12;
  }
  hkpSphereShape::hkpSphereShape(&v38, 0.0);
  v38.m_radius = 0.0;
  hkpCollisionFilter::hkpCollisionFilter(&v31);
  v14 = v8->m_shape.m_pntr;
  v41 = FLOAT_0_001;
  v31.vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
  v40 = 0;
  v31.vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v15 = 1;
  v31.vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v31.m_type.m_storage = 1;
  v31.vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v31.vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  v42 = &v31;
  v39 = v8->m_dispatcher.m_pntr;
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v14->vfptr[2].__vecDelDtor)(
    v14,
    &v8->m_shapeTransform,
    v16,
    &v32);
  v17 = v8->m_dispatcher.m_pntr;
  v18 = (__int64)v8->m_shape.m_pntr;
  v34 = transform.m_quad;
  v35 = direction.m_quad;
  v36 = stru_141A71280.m_quad;
  v37 = 0i64;
  v19 = v17->m_agent2Func[(unsigned __int8)v17->m_agent2Types[*(unsigned __int8 *)(v18 + 16)][(unsigned __int8)v38.m_type.m_storage]].m_getPenetrationsFunc;
  if ( v19 )
  {
    v27 = v18;
    v30 = 0i64;
    v29 = &v8->m_shapeTransform;
    v28 = -1;
    v23 = &v38;
    v26 = 0i64;
    v24 = -1;
    v25 = &v34;
    if ( (signed int)v6 > 0 )
    {
      v20 = v6;
      do
      {
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v7->m_quad, v33), _mm_cmpleps(v32, v7->m_quad))) & 7) == 7 )
        {
          v37 = v7->m_quad;
          v22 = 0;
          ((void (__fastcall *)(__int64 *, hkpSphereShape **, hkpCollisionDispatcher **, void ***, void **))v19)(
            &v27,
            &v23,
            &v39,
            &v21,
            &hkpFlagCdBodyPairCollector::`vftable);
          if ( v22 )
            v5->m_storage.m_words.m_data[v4 >> 5] |= v15;
          v21 = &hkpCdBodyPairCollector::`vftable;
        }
        v15 = __ROL4__(v15, 1);
        ++v4;
        ++v7;
        --v20;
      }
      while ( v20 );
    }
  }
  hkpNullCollisionFilter::~hkpNullCollisionFilter((hkpNullCollisionFilter *)&v31);
}

// File Line: 218
// RVA: 0xC2FFA0
hkResult *__fastcall hkaiPhysics2012ShapeVolume::calcGeometry(hkaiPhysics2012ShapeVolume *this, hkResult *result, hkGeometry *geom)
{
  int v3; // er9
  hkGeometry *v4; // rbp
  hkResult *v5; // rsi
  hkaiPhysics2012ShapeVolume *v6; // rdi
  __int64 v7; // rax
  hkVector4f *v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  hkVector4f v11; // xmm0
  int v13; // er9
  __int64 v14; // rcx
  hkGeometry::Triangle *v15; // rax
  __int64 v16; // rdx
  char *v17; // r8
  int v18; // ecx
  hkResult resulta; // [rsp+50h] [rbp+8h]
  int v20; // [rsp+60h] [rbp+18h]

  v3 = this->m_geometry.m_vertices.m_size;
  v4 = geom;
  v5 = result;
  v6 = this;
  if ( (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &geom->m_vertices,
      v3,
      16);
    if ( resulta.m_enum )
    {
LABEL_13:
      v5->m_enum = 1;
      return v5;
    }
  }
  if ( (v4->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_geometry.m_vertices.m_size )
  {
    if ( v4->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v4->m_vertices.m_data,
        16 * v4->m_vertices.m_capacityAndFlags);
    v20 = 16 * v6->m_geometry.m_vertices.m_size;
    v4->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v20);
    v4->m_vertices.m_capacityAndFlags = v20 / 16;
  }
  v7 = v6->m_geometry.m_vertices.m_size;
  v8 = v4->m_vertices.m_data;
  v4->m_vertices.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v6->m_geometry.m_vertices.m_data - (char *)v8);
    do
    {
      v11.m_quad = *(__m128 *)((char *)v8 + (_QWORD)v10);
      ++v8;
      v8[-1] = (hkVector4f)v11.m_quad;
      --v9;
    }
    while ( v9 );
  }
  if ( resulta.m_enum )
    goto LABEL_13;
  v13 = v6->m_geometry.m_triangles.m_size;
  if ( (v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v13 )
  {
    v5->m_enum = 0;
LABEL_18:
    if ( (v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_geometry.m_triangles.m_size )
    {
      if ( v4->m_triangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v4->m_triangles.m_data,
          16 * v4->m_triangles.m_capacityAndFlags);
      v20 = 16 * v6->m_geometry.m_triangles.m_size;
      v4->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                         &v20);
      v4->m_triangles.m_capacityAndFlags = v20 / 16;
    }
    v14 = v6->m_geometry.m_triangles.m_size;
    v15 = v4->m_triangles.m_data;
    v4->m_triangles.m_size = v14;
    v16 = v14;
    if ( (signed int)v14 > 0 )
    {
      v17 = (char *)((char *)v6->m_geometry.m_triangles.m_data - (char *)v15);
      do
      {
        v18 = *(int *)((char *)&v15->m_a + (_QWORD)v17);
        ++v15;
        v15[-1].m_a = v18;
        v15[-1].m_b = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 12);
        v15[-1].m_c = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 8);
        v15[-1].m_material = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 4);
        --v16;
      }
      while ( v16 );
    }
    return v5;
  }
  hkArrayUtil::_reserve(v5, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_triangles, v13, 16);
  if ( v5->m_enum == HK_SUCCESS )
    goto LABEL_18;
  return v5;
}

// File Line: 228
// RVA: 0xC301C0
__int64 __fastcall hkaiPhysics2012ShapeVolume::containsTriangle(hkaiPhysics2012ShapeVolume *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  return 0i64;
}

// File Line: 273
// RVA: 0xC301D0
__int64 __fastcall hkaiPhysics2012ShapeVolume::containsAabb(hkaiPhysics2012ShapeVolume *this, hkAabb *aabbIn)
{
  return 0i64;
}

// File Line: 279
// RVA: 0xC30200
void __fastcall hkaiPhysics2012ShapeVolume::setCollisionDispatcher(hkaiPhysics2012ShapeVolume *this, hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v2; // rbx
  hkaiPhysics2012ShapeVolume *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = dispatcher;
  v3 = this;
  if ( dispatcher )
    hkReferencedObject::addReference((hkReferencedObject *)&dispatcher->vfptr);
  v4 = (hkReferencedObject *)&v3->m_dispatcher.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_dispatcher.m_pntr = v2;
}

// File Line: 284
// RVA: 0xC301E0
void __fastcall hkaiPhysics2012ShapeVolume::getAabb(hkaiPhysics2012ShapeVolume *this, hkAabb *aabbOut)
{
  ((void (__fastcall *)(hkpShape *, hkTransformf *, hkBaseObjectVtbl *, hkAabb *))this->m_shape.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_shape.m_pntr,
    &this->m_shapeTransform,
    this->m_shape.m_pntr->vfptr,
    aabbOut);
}

