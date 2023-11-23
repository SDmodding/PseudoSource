// File Line: 34
// RVA: 0xC30300
char __fastcall isContainerOk(hkpShapeContainer *container)
{
  unsigned int v2; // ebx
  hkpShape *v3; // rax
  __int64 v4; // rdx
  char v6[520]; // [rsp+20h] [rbp-208h] BYREF

  v2 = container->vfptr->getFirstKey(container);
  if ( v2 == -1 )
    return 1;
  while ( 1 )
  {
    v3 = container->vfptr->getChildShape(container, v2, v6);
    if ( !isShapeOk(v3, v4) )
      break;
    v2 = container->vfptr->getNextKey(container, v2);
    if ( v2 == -1 )
      return 1;
  }
  return 0;
}

// File Line: 53
// RVA: 0xC30240
bool __fastcall isShapeOk(hkpShape *shape, __int64 a2)
{
  unsigned int m_storage; // eax
  hkpShapeContainer *v4; // rax

  m_storage = (unsigned __int8)shape->m_type.m_storage;
  while ( 2 )
  {
    switch ( m_storage )
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
        v4 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *, __int64, unsigned __int64))shape->vfptr[7].__vecDelDtor)(
                                    shape,
                                    a2,
                                    0x140000000ui64);
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
        m_storage = (unsigned __int8)shape->m_type.m_storage;
        if ( m_storage > 0x21 )
          return 0;
        continue;
      default:
        return 0;
    }
  }
}

// File Line: 127
// RVA: 0xC2FAD0
void __fastcall hkaiPhysics2012ShapeVolume::hkaiPhysics2012ShapeVolume(
        hkaiPhysics2012ShapeVolume *this,
        hkpCollisionDispatcher *dispatcher,
        hkTransformf *transform,
        hkpShape *shape)
{
  __int64 v8; // rbx
  hkGeometry *v9; // rsi
  int m_size; // eax
  __int64 v11; // rsi
  hkErrStream v12; // [rsp+20h] [rbp-238h] BYREF
  char buf[512]; // [rsp+40h] [rbp-218h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012ShapeVolume::`vftable;
  if ( dispatcher )
    hkReferencedObject::addReference(dispatcher);
  this->m_dispatcher.m_pntr = dispatcher;
  if ( shape )
    hkReferencedObject::addReference(shape);
  this->m_shape.m_pntr = shape;
  v8 = 0i64;
  this->m_shapeTransform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  this->m_shapeTransform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  this->m_shapeTransform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  this->m_shapeTransform.m_translation = transform->m_translation;
  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 0x80000000;
  if ( !isShapeOk(shape) )
  {
    hkErrStream::hkErrStream(&v12, buf, 512);
    hkOstream::operator<<(
      &v12,
      "Trying to use a shape in hkaiPhysics2012ShapeVolume that contains triangles. This might not give the expected resu"
      "lts, as the inside of a triangle or triangle mesh isnt well-defined.");
    hkError::messageWarning(415712427, buf, "Collide\\hkaiPhysics2012ShapeVolume.cpp", 130);
    hkOstream::~hkOstream(&v12);
  }
  v9 = hkpShapeConverter::toSingleGeometry(this->m_shape.m_pntr);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_geometry.m_triangles,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v9->m_triangles);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_geometry.m_vertices,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v9->m_vertices);
  if ( v9 )
    v9->vfptr->__vecDelDtor(v9, 1u);
  m_size = this->m_geometry.m_vertices.m_size;
  if ( m_size > 0 )
  {
    v11 = (unsigned int)m_size;
    do
    {
      hkVector4f::setTransformedPos(
        &this->m_geometry.m_vertices.m_data[v8],
        &this->m_shapeTransform,
        &this->m_geometry.m_vertices.m_data[v8]);
      ++v8;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 152
// RVA: 0xC2FC80
void __fastcall hkaiPhysics2012ShapeVolume::hkaiPhysics2012ShapeVolume(
        hkaiPhysics2012ShapeVolume *this,
        hkFinishLoadedObjectFlag f)
{
  hkGeometry *p_m_geometry; // rcx

  p_m_geometry = &this->m_geometry;
  p_m_geometry[-2].vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012ShapeVolume::`vftable;
  hkGeometry::hkGeometry(p_m_geometry, f);
}

// File Line: 156
// RVA: 0xC2FCB0
void __fastcall hkaiPhysics2012ShapeVolume::~hkaiPhysics2012ShapeVolume(hkaiPhysics2012ShapeVolume *this)
{
  hkGeometry *p_m_geometry; // rcx
  hkpShape *m_pntr; // rcx
  hkpCollisionDispatcher *v4; // rcx

  p_m_geometry = &this->m_geometry;
  p_m_geometry[-2].vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012ShapeVolume::`vftable;
  hkGeometry::~hkGeometry(p_m_geometry);
  m_pntr = this->m_shape.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_shape.m_pntr = 0i64;
  v4 = this->m_dispatcher.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_dispatcher.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 160
// RVA: 0xC2FD10
void __fastcall hkaiPhysics2012ShapeVolume::calcPointsInside(
        hkaiPhysics2012ShapeVolume *this,
        hkVector4f *points,
        unsigned int numPoints,
        hkBitField *pointsInside)
{
  __int64 v4; // rdi
  __int64 v6; // r13
  _QWORD **Value; // rax
  hkpCollisionDispatcher *v10; // rax
  hkpCollisionDispatcher *v11; // rax
  hkpCollisionDispatcher *v12; // rbx
  hkpCollisionDispatcher *m_pntr; // rcx
  hkpShape *v14; // rcx
  int v15; // ebx
  __int64 v16; // r8
  hkpCollisionDispatcher *v17; // rdx
  hkpShape *v18; // r8
  void (__fastcall *m_getPenetrationsFunc)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdBodyPairCollector *); // r12
  __int64 v20; // r14
  __m128 m_quad; // xmm2
  void **v22; // [rsp+20h] [rbp-E0h] BYREF
  char v23; // [rsp+28h] [rbp-D8h]
  hkpSphereShape *v24; // [rsp+30h] [rbp-D0h] BYREF
  int v25; // [rsp+38h] [rbp-C8h]
  __int128 *v26; // [rsp+40h] [rbp-C0h]
  __int64 v27; // [rsp+48h] [rbp-B8h]
  hkpShape *v28; // [rsp+50h] [rbp-B0h] BYREF
  int v29; // [rsp+58h] [rbp-A8h]
  hkTransformf *p_m_shapeTransform; // [rsp+60h] [rbp-A0h]
  __int64 v31; // [rsp+68h] [rbp-98h]
  hkpCollisionFilter v32; // [rsp+70h] [rbp-90h] BYREF
  __m128 v33[2]; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v34[3]; // [rsp+E0h] [rbp-20h] BYREF
  __m128 v35; // [rsp+110h] [rbp+10h]
  hkpSphereShape v36; // [rsp+120h] [rbp+20h] BYREF
  hkpCollisionDispatcher *v37; // [rsp+160h] [rbp+60h] BYREF
  int v38; // [rsp+16Ch] [rbp+6Ch]
  float v39; // [rsp+170h] [rbp+70h]
  hkpCollisionFilter *v40; // [rsp+178h] [rbp+78h]

  v4 = 0i64;
  v6 = numPoints;
  if ( !this->m_dispatcher.m_pntr )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpCollisionDispatcher *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
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
    m_pntr = this->m_dispatcher.m_pntr;
    if ( m_pntr && m_pntr != v12 )
      hkReferencedObject::removeReference(m_pntr);
    this->m_dispatcher.m_pntr = v12;
  }
  hkpSphereShape::hkpSphereShape(&v36, 0.0);
  v36.m_radius = 0.0;
  hkpCollisionFilter::hkpCollisionFilter(&v32);
  v14 = this->m_shape.m_pntr;
  v39 = FLOAT_0_001;
  v32.hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
  v38 = 0;
  v32.hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v15 = 1;
  v32.hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v32.m_type.m_storage = 1;
  v32.hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v32.hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  v40 = &v32;
  v37 = this->m_dispatcher.m_pntr;
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v14->vfptr[2].__vecDelDtor)(
    v14,
    &this->m_shapeTransform,
    v16,
    v33);
  v17 = this->m_dispatcher.m_pntr;
  v18 = this->m_shape.m_pntr;
  v34[0] = (__int128)transform.m_quad;
  v34[1] = (__int128)direction.m_quad;
  v34[2] = (__int128)stru_141A71280.m_quad;
  v35 = 0i64;
  m_getPenetrationsFunc = v17->m_agent2Func[(unsigned __int8)v17->m_agent2Types[(unsigned __int8)v18->m_type.m_storage][(unsigned __int8)v36.m_type.m_storage]].m_getPenetrationsFunc;
  if ( m_getPenetrationsFunc )
  {
    v28 = v18;
    v31 = 0i64;
    p_m_shapeTransform = &this->m_shapeTransform;
    v29 = -1;
    v24 = &v36;
    v27 = 0i64;
    v25 = -1;
    v26 = v34;
    if ( (int)v6 > 0 )
    {
      v20 = v6;
      do
      {
        m_quad = points->m_quad;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(points->m_quad, v33[1]), _mm_cmple_ps(v33[0], points->m_quad))) & 7) == 7 )
        {
          v22 = &hkpFlagCdBodyPairCollector::`vftable;
          v35 = m_quad;
          v23 = 0;
          m_getPenetrationsFunc(
            (hkpCdBody *)&v28,
            (hkpCdBody *)&v24,
            (hkpCollisionInput *)&v37,
            (hkpCdBodyPairCollector *)&v22);
          if ( v23 )
            pointsInside->m_storage.m_words.m_data[v4 >> 5] |= v15;
          v22 = &hkpCdBodyPairCollector::`vftable;
        }
        v15 = __ROL4__(v15, 1);
        ++v4;
        ++points;
        --v20;
      }
      while ( v20 );
    }
  }
  hkpNullCollisionFilter::~hkpNullCollisionFilter((hkpNullCollisionFilter *)&v32);
}

// File Line: 218
// RVA: 0xC2FFA0
hkResult *__fastcall hkaiPhysics2012ShapeVolume::calcGeometry(
        hkaiPhysics2012ShapeVolume *this,
        hkResult *result,
        hkGeometry *geom)
{
  int m_size; // r9d
  __int64 v7; // rax
  hkVector4f *m_data; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  hkVector4f v11; // xmm0
  int v13; // r9d
  __int64 v14; // rcx
  hkGeometry::Triangle *v15; // rax
  __int64 v16; // rdx
  char *v17; // r8
  int v18; // ecx
  hkResult resulta; // [rsp+50h] [rbp+8h] BYREF
  int v20; // [rsp+60h] [rbp+18h] BYREF

  m_size = this->m_geometry.m_vertices.m_size;
  if ( (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &geom->m_vertices, m_size, 16);
    if ( resulta.m_enum )
    {
LABEL_13:
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  if ( (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < this->m_geometry.m_vertices.m_size )
  {
    if ( geom->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geom->m_vertices.m_data,
        16 * geom->m_vertices.m_capacityAndFlags);
    v20 = 16 * this->m_geometry.m_vertices.m_size;
    geom->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v20);
    geom->m_vertices.m_capacityAndFlags = v20 / 16;
  }
  v7 = this->m_geometry.m_vertices.m_size;
  m_data = geom->m_vertices.m_data;
  geom->m_vertices.m_size = v7;
  v9 = v7;
  if ( (int)v7 > 0 )
  {
    v10 = (char *)((char *)this->m_geometry.m_vertices.m_data - (char *)m_data);
    do
    {
      v11.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v10);
      m_data[-1] = (hkVector4f)v11.m_quad;
      --v9;
    }
    while ( v9 );
  }
  if ( resulta.m_enum )
    goto LABEL_13;
  v13 = this->m_geometry.m_triangles.m_size;
  if ( (geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v13 )
  {
    result->m_enum = HK_SUCCESS;
LABEL_18:
    if ( (geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < this->m_geometry.m_triangles.m_size )
    {
      if ( geom->m_triangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          geom->m_triangles.m_data,
          16 * geom->m_triangles.m_capacityAndFlags);
      v20 = 16 * this->m_geometry.m_triangles.m_size;
      geom->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                           &hkContainerHeapAllocator::s_alloc,
                                                           &v20);
      geom->m_triangles.m_capacityAndFlags = v20 / 16;
    }
    v14 = this->m_geometry.m_triangles.m_size;
    v15 = geom->m_triangles.m_data;
    geom->m_triangles.m_size = v14;
    v16 = v14;
    if ( (int)v14 > 0 )
    {
      v17 = (char *)((char *)this->m_geometry.m_triangles.m_data - (char *)v15);
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
    return result;
  }
  hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &geom->m_triangles, v13, 16);
  if ( result->m_enum == HK_SUCCESS )
    goto LABEL_18;
  return result;
}

// File Line: 228
// RVA: 0xC301C0
__int64 __fastcall hkaiPhysics2012ShapeVolume::containsTriangle(
        hkaiPhysics2012ShapeVolume *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c)
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
void __fastcall hkaiPhysics2012ShapeVolume::setCollisionDispatcher(
        hkaiPhysics2012ShapeVolume *this,
        hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *m_pntr; // rcx

  if ( dispatcher )
    hkReferencedObject::addReference(dispatcher);
  m_pntr = this->m_dispatcher.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_dispatcher.m_pntr = dispatcher;
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

