// File Line: 50
// RVA: 0xD12630
void __fastcall hkpExtendedMeshShape::hkpExtendedMeshShape(
        hkpExtendedMeshShape *this,
        float radius,
        int numBitsForSubpartIndex)
{
  hkpShapeCollection::hkpShapeCollection(this, EXTENDED_MESH, COLLECTION_EXTENDED_MESH);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShapeContainer};
  *(_QWORD *)&this->m_embeddedTrianglesSubpart.m_typeAndFlags = 10i64;
  this->m_embeddedTrianglesSubpart.m_extrusion = 0i64;
  this->m_embeddedTrianglesSubpart.m_materialBase = 0i64;
  this->m_embeddedTrianglesSubpart.m_materialIndexBase = 0i64;
  this->m_embeddedTrianglesSubpart.m_userData = 0i64;
  this->m_embeddedTrianglesSubpart.m_flipAlternateTriangles = 0;
  this->m_embeddedTrianglesSubpart.m_transform.m_translation = 0i64;
  this->m_embeddedTrianglesSubpart.m_transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->m_embeddedTrianglesSubpart.m_transform.m_scale = (hkVector4f)query.m_quad;
  this->m_trianglesSubparts.m_data = 0i64;
  this->m_trianglesSubparts.m_size = 0;
  this->m_trianglesSubparts.m_capacityAndFlags = 0x80000000;
  this->m_shapesSubparts.m_data = 0i64;
  this->m_shapesSubparts.m_size = 0;
  this->m_shapesSubparts.m_capacityAndFlags = 0x80000000;
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_size = 0;
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  this->m_triangleRadius = radius;
  this->m_defaultCollisionFilterInfo = 0;
  this->m_numBitsForSubpartIndex = numBitsForSubpartIndex;
  this->m_weldingType.m_storage = 6;
  this->m_cachedNumChildShapes = 0;
  this->m_materialClass = 0i64;
  this->m_aabbHalfExtents = (hkVector4f)xmmword_141A712F0;
  this->m_aabbCenter = 0i64;
}

// File Line: 72
// RVA: 0xD12750
void __fastcall hkpExtendedMeshShape::hkpExtendedMeshShape(hkpExtendedMeshShape *this, hkpMeshShape *meshShape)
{
  int v4; // ebp
  hkArray<hkpExtendedMeshShape::TrianglesSubpart,hkContainerHeapAllocator> *p_m_trianglesSubparts; // rdi
  int v6; // r8d
  __int64 m_size; // rax
  unsigned __int16 *m_data; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  unsigned __int16 v11; // ax
  int v12; // r15d
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  __int64 v16; // r9
  __int64 v17; // r10
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  hkpShapeCollection::hkpShapeCollection(this, EXTENDED_MESH, COLLECTION_EXTENDED_MESH);
  v4 = 0;
  p_m_trianglesSubparts = &this->m_trianglesSubparts;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShapeContainer};
  *(_QWORD *)&this->m_embeddedTrianglesSubpart.m_typeAndFlags = 10i64;
  this->m_embeddedTrianglesSubpart.m_materialBase = 0i64;
  this->m_embeddedTrianglesSubpart.m_extrusion = 0i64;
  this->m_embeddedTrianglesSubpart.m_materialIndexBase = 0i64;
  this->m_embeddedTrianglesSubpart.m_userData = 0i64;
  this->m_embeddedTrianglesSubpart.m_flipAlternateTriangles = 0;
  this->m_embeddedTrianglesSubpart.m_transform.m_translation = 0i64;
  this->m_embeddedTrianglesSubpart.m_transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->m_embeddedTrianglesSubpart.m_transform.m_scale = (hkVector4f)query.m_quad;
  this->m_trianglesSubparts.m_data = 0i64;
  this->m_trianglesSubparts.m_size = 0;
  this->m_trianglesSubparts.m_capacityAndFlags = 0x80000000;
  this->m_shapesSubparts.m_data = 0i64;
  this->m_shapesSubparts.m_size = 0;
  this->m_shapesSubparts.m_capacityAndFlags = 0x80000000;
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_size = 0;
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  this->m_triangleRadius = meshShape->m_radius;
  this->m_numBitsForSubpartIndex = meshShape->m_numBitsForSubpartIndex;
  this->m_weldingType.m_storage = meshShape->m_weldingType.m_storage;
  v6 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < meshShape->m_weldingInfo.m_size )
  {
    if ( this->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 2 * v6);
    result.m_enum = 2 * meshShape->m_weldingInfo.m_size;
    this->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       &result);
    this->m_weldingInfo.m_capacityAndFlags = result.m_enum / 2;
  }
  m_size = meshShape->m_weldingInfo.m_size;
  m_data = this->m_weldingInfo.m_data;
  this->m_weldingInfo.m_size = m_size;
  v9 = m_size;
  if ( (int)m_size > 0 )
  {
    v10 = (char *)((char *)meshShape->m_weldingInfo.m_data - (char *)m_data);
    do
    {
      v11 = *(unsigned __int16 *)((char *)m_data++ + (_QWORD)v10);
      *(m_data - 1) = v11;
      --v9;
    }
    while ( v9 );
  }
  v12 = meshShape->m_subparts.m_size;
  if ( v12 == 1 )
  {
    p_m_trianglesSubparts->m_data = &this->m_embeddedTrianglesSubpart;
    this->m_trianglesSubparts.m_size = 1;
    this->m_trianglesSubparts.m_capacityAndFlags = -2147483647;
  }
  else
  {
    v13 = this->m_trianglesSubparts.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 < v12 )
    {
      v14 = 2 * v13;
      v15 = meshShape->m_subparts.m_size;
      if ( v12 < v14 )
        v15 = v14;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_trianglesSubparts.m_data,
        v15,
        144);
    }
    this->m_trianglesSubparts.m_size = v12;
  }
  this->m_defaultCollisionFilterInfo = 0;
  if ( meshShape->m_subparts.m_size > 0 )
  {
    v16 = 0i64;
    v17 = 0i64;
    do
    {
      p_m_trianglesSubparts->m_data[v16].m_numTriangleShapes = meshShape->m_subparts.m_data[v17++].m_numTriangles;
      p_m_trianglesSubparts->m_data[v16].m_materialIndexBase = meshShape->m_subparts.m_data[v17 - 1].m_materialIndexBase;
      p_m_trianglesSubparts->m_data[v16].m_materialIndexStriding = LOBYTE(meshShape->m_subparts.m_data[v17 - 1].m_materialIndexStriding);
      p_m_trianglesSubparts->m_data[v16].m_typeAndFlags = p_m_trianglesSubparts->m_data[v16].m_typeAndFlags & 0xFFF9 | (2 * (meshShape->m_subparts.m_data[v17 - 1].m_materialIndexStridingType.m_storage & 3));
      p_m_trianglesSubparts->m_data[v16].m_materialBase = meshShape->m_subparts.m_data[v17 - 1].m_materialBase;
      p_m_trianglesSubparts->m_data[v16].m_materialStriding = meshShape->m_subparts.m_data[v17 - 1].m_materialStriding;
      ++v4;
      p_m_trianglesSubparts->m_data[v16].m_typeAndFlags = p_m_trianglesSubparts->m_data[v16].m_typeAndFlags & 7 | (8 * LOWORD(meshShape->m_subparts.m_data[v17 - 1].m_numMaterials));
      p_m_trianglesSubparts->m_data[v16].m_vertexBase = meshShape->m_subparts.m_data[v17 - 1].m_vertexBase;
      p_m_trianglesSubparts->m_data[v16].m_vertexStriding = meshShape->m_subparts.m_data[v17 - 1].m_vertexStriding;
      p_m_trianglesSubparts->m_data[v16].m_numVertices = meshShape->m_subparts.m_data[v17 - 1].m_numVertices;
      p_m_trianglesSubparts->m_data[v16].m_indexBase = meshShape->m_subparts.m_data[v17 - 1].m_indexBase;
      p_m_trianglesSubparts->m_data[v16].m_stridingType.m_storage = meshShape->m_subparts.m_data[v17 - 1].m_stridingType.m_storage;
      p_m_trianglesSubparts->m_data[v16].m_indexStriding = meshShape->m_subparts.m_data[v17 - 1].m_indexStriding;
      p_m_trianglesSubparts->m_data[v16].m_triangleOffset = meshShape->m_subparts.m_data[v17 - 1].m_triangleOffset;
      p_m_trianglesSubparts->m_data[v16].m_extrusion = 0i64;
      p_m_trianglesSubparts->m_data[v16].m_flipAlternateTriangles = meshShape->m_subparts.m_data[v17 - 1].m_flipAlternateTriangles;
      p_m_trianglesSubparts->m_data[v16++].m_transform = hkQsTransformf_identityStorage;
    }
    while ( v4 < meshShape->m_subparts.m_size );
  }
  hkpExtendedMeshShape::recalcAabbExtents(this);
  this->m_cachedNumChildShapes = hkpShapeContainer::getNumChildShapes(&this->hkpShapeContainer);
}

// File Line: 118
// RVA: 0xD12CB0
void __fastcall hkpExtendedMeshShape::~hkpExtendedMeshShape(hkpExtendedMeshShape *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // edi
  hkpExtendedMeshShape::ShapesSubpart *v4; // rsi
  int v5; // eax
  int v6; // eax

  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShapeContainer};
  m_capacityAndFlags = this->m_weldingInfo.m_capacityAndFlags;
  this->m_weldingInfo.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_weldingInfo.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  v3 = this->m_shapesSubparts.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &this->m_shapesSubparts.m_data[v3];
    do
    {
      hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart(v4--);
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = this->m_shapesSubparts.m_capacityAndFlags;
  this->m_shapesSubparts.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_shapesSubparts.m_data,
      80 * (v5 & 0x3FFFFFFF));
  this->m_shapesSubparts.m_data = 0i64;
  this->m_shapesSubparts.m_capacityAndFlags = 0x80000000;
  v6 = this->m_trianglesSubparts.m_capacityAndFlags;
  this->m_trianglesSubparts.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_trianglesSubparts.m_data,
      144 * (v6 & 0x3FFFFFFF));
  this->m_trianglesSubparts.m_data = 0i64;
  this->m_trianglesSubparts.m_capacityAndFlags = 0x80000000;
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 127
// RVA: 0xD12B00
void __fastcall hkpExtendedMeshShape::hkpExtendedMeshShape(hkpExtendedMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  int v3; // ecx
  __int64 v4; // rdx
  hkpExtendedMeshShape::TrianglesSubpart *m_data; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkpExtendedMeshShape::ShapesSubpart *v8; // rcx
  hkpExtendedMeshShape::ShapesSubpart *v9; // rax
  hkpExtendedMeshShape::TrianglesSubpart *v10; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  const float *v13; // rax
  int m_capacityAndFlags; // eax
  bool v15; // zf

  hkpShapeCollection::hkpShapeCollection(this, flag);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpExtendedMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    v3 = 0;
    this->m_collectionType.m_storage = 1;
    if ( this->m_trianglesSubparts.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        m_data = this->m_trianglesSubparts.m_data;
        if ( (m_data[v4].m_typeAndFlags & 6) == 0 )
        {
          m_data[v4].m_typeAndFlags &= ~4u;
          m_data[v4].m_typeAndFlags |= 2u;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < this->m_trianglesSubparts.m_size );
    }
    v6 = 0;
    if ( this->m_shapesSubparts.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = &this->m_shapesSubparts.m_data[v6];
        if ( v8 )
          hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(v8, flag);
        v9 = this->m_shapesSubparts.m_data;
        if ( (v9[v7].m_typeAndFlags & 6) == 0 )
        {
          v9[v7].m_typeAndFlags &= ~4u;
          v9[v7].m_typeAndFlags |= 2u;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_shapesSubparts.m_size );
    }
    if ( this->m_trianglesSubparts.m_size == 1 )
    {
      v10 = this->m_trianglesSubparts.m_data;
      v11 = 18i64;
      v12 = (char *)((char *)this - (char *)v10);
      do
      {
        v13 = *(const float **)&v10->m_typeAndFlags;
        v10 = (hkpExtendedMeshShape::TrianglesSubpart *)((char *)v10 + 8);
        *(const float **)((char *)&v10->m_vertexBase + (_QWORD)v12) = v13;
        --v11;
      }
      while ( v11 );
      m_capacityAndFlags = this->m_trianglesSubparts.m_capacityAndFlags;
      this->m_trianglesSubparts.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          this->m_trianglesSubparts.m_data,
          144 * (m_capacityAndFlags & 0x3FFFFFFF));
      this->m_trianglesSubparts.m_capacityAndFlags = 0x80000000;
      this->m_trianglesSubparts.m_data = &this->m_embeddedTrianglesSubpart;
      this->m_trianglesSubparts.m_size = 1;
      this->m_trianglesSubparts.m_capacityAndFlags = -2147483647;
    }
    v15 = this->m_cachedNumChildShapes == -1;
    this->m_type.m_storage = 13;
    if ( v15 )
      this->m_cachedNumChildShapes = 0x80000000;
  }
  else
  {
    this->m_type.m_storage = 13;
  }
}

// File Line: 177
// RVA: 0xD13360
void __fastcall hkpExtendedMeshShape::setWeldingInfo(hkpExtendedMeshShape *this, int key, unsigned __int16 weldingInfo)
{
  int v6; // ecx
  int v7; // ebx
  hkpExtendedMeshShape::TrianglesSubpart *m_data; // rdi
  __int64 v9; // rax
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  __int64 m_size; // rdx
  unsigned __int16 *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  if ( !this->m_weldingInfo.m_size )
  {
    v6 = 0;
    v7 = 0;
    if ( this->m_trianglesSubparts.m_size > 0 )
    {
      m_data = this->m_trianglesSubparts.m_data;
      v9 = 0i64;
      do
      {
        m_data[v9].m_triangleOffset = v7;
        m_data = this->m_trianglesSubparts.m_data;
        ++v6;
        v7 += m_data[v9++].m_numTriangleShapes;
      }
      while ( v6 < this->m_trianglesSubparts.m_size );
    }
    if ( (this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v7 )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v7,
        2);
    v10 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v10 < v7 )
    {
      v11 = 2 * v10;
      v12 = v7;
      if ( v7 < v11 )
        v12 = v11;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v12,
        2);
    }
    m_size = this->m_weldingInfo.m_size;
    v14 = &this->m_weldingInfo.m_data[m_size];
    v15 = v7 - (int)m_size;
    if ( v7 - (int)m_size > 0 )
    {
      while ( v15 )
      {
        *v14++ = 0;
        --v15;
      }
    }
    this->m_weldingInfo.m_size = v7;
  }
  if ( key >= 0 )
    this->m_weldingInfo.m_data[(key & (0xFFFFFFFF >> this->m_numBitsForSubpartIndex))
                             + this->m_trianglesSubparts.m_data[(key & 0x7FFFFFFFu) >> (32
                                                                                      - this->m_numBitsForSubpartIndex)].m_triangleOffset] = weldingInfo;
}

// File Line: 207
// RVA: 0xD134D0
void __fastcall hkpExtendedMeshShape::initWeldingInfo(
        hkpExtendedMeshShape *this,
        hkpWeldingUtility::WeldingType weldingType)
{
  int v3; // ecx
  int v4; // ebx
  hkpExtendedMeshShape::TrianglesSubpart *m_data; // rdx
  __int64 v6; // rax
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_weldingInfo; // r14
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  __int64 m_size; // rdx
  unsigned __int16 *v12; // rdi
  __int64 v13; // rcx
  int m_capacityAndFlags; // r8d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_weldingType.m_storage = weldingType;
  if ( weldingType == WELDING_TYPE_NONE )
  {
    m_capacityAndFlags = this->m_weldingInfo.m_capacityAndFlags;
    this->m_weldingInfo.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * (m_capacityAndFlags & 0x3FFFFFFF));
    this->m_weldingInfo.m_data = 0i64;
    this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    v3 = 0;
    v4 = 0;
    if ( this->m_trianglesSubparts.m_size > 0 )
    {
      m_data = this->m_trianglesSubparts.m_data;
      v6 = 0i64;
      do
      {
        m_data[v6].m_triangleOffset = v4;
        m_data = this->m_trianglesSubparts.m_data;
        ++v3;
        v4 += m_data[v6++].m_numTriangleShapes;
      }
      while ( v3 < this->m_trianglesSubparts.m_size );
    }
    p_m_weldingInfo = &this->m_weldingInfo;
    if ( (this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v4 )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v4,
        2);
    v8 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v4 )
    {
      v9 = 2 * v8;
      v10 = v4;
      if ( v4 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v10,
        2);
    }
    m_size = this->m_weldingInfo.m_size;
    v12 = &p_m_weldingInfo->m_data[m_size];
    v13 = v4 - (int)m_size;
    if ( v4 - (int)m_size > 0 )
    {
      while ( v13 )
      {
        *v12++ = 0;
        --v13;
      }
    }
    p_m_weldingInfo->m_size = v4;
  }
}

// File Line: 232
// RVA: 0xD130F0
__int64 __fastcall hkpExtendedMeshShape::getNumChildShapes(hkpExtendedMeshShape *this)
{
  __int64 result; // rax

  if ( this->m_shapesSubparts.m_size >= 0 )
    return (unsigned int)this->m_shapesSubparts.m_size;
  result = hkpShapeContainer::getNumChildShapes((hkpShapeContainer *)this);
  this->m_shapesSubparts.m_size = result;
  return result;
}

// File Line: 246
// RVA: 0xD13130
__int64 __fastcall hkpExtendedMeshShape::getFirstKey(hkpExtendedMeshShape *this)
{
  int v2; // ecx
  unsigned int v4; // edi
  hkVector4f *v5; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-218h] BYREF
  char v7[520]; // [rsp+30h] [rbp-208h] BYREF

  v2 = this->m_aabbCenter.m_quad.m128_i32[2];
  if ( !(v2 + this->m_numBitsForSubpartIndex) )
    return 0xFFFFFFFFi64;
  v4 = 0x80000000;
  if ( v2 )
    v4 = 0;
  v5 = (hkVector4f *)((__int64 (__fastcall *)(hkpExtendedMeshShape *, _QWORD, char *))this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[2].__first_virtual_table_function__)(
                       this,
                       v4,
                       v7);
  if ( v5[1].m_quad.m128_i8[0] == 2
    && (tolerance.m_real = _mm_shuffle_ps(
                             (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                             (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                             0),
        hkcdTriangleUtil::isDegenerate(v5 + 3, v5 + 4, v5 + 5, &tolerance)) )
  {
    return ((__int64 (__fastcall *)(hkpExtendedMeshShape *, _QWORD))this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[1].__first_virtual_table_function__)(
             this,
             v4);
  }
  else
  {
    return v4;
  }
}

// File Line: 273
// RVA: 0xD13200
__int64 __fastcall hkpExtendedMeshShape::getNextKey(hkpExtendedMeshShape *this, unsigned int initialKey)
{
  unsigned int v3; // esi
  __int64 v4; // rdi
  signed int v5; // ebx
  unsigned int v6; // r15d
  unsigned int v7; // ebp
  hkVector4f *v8; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-228h] BYREF
  char v11[512]; // [rsp+30h] [rbp-218h] BYREF

  v3 = (initialKey & 0x7FFFFFFF) >> (32 - this->m_aabbHalfExtents.m_quad.m128_i32[2]);
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
      if ( v5 < *(_DWORD *)(this->m_aabbCenter.m_quad.m128_u64[0] + 144 * v4 + 32) )
        goto LABEL_10;
      ++v3;
      v5 = 0;
      ++v4;
      if ( v3 < this->m_aabbCenter.m_quad.m128_i32[2] )
        goto LABEL_10;
      if ( !this->m_numBitsForSubpartIndex )
        return 0xFFFFFFFFi64;
      v3 = 0;
      v4 = 0i64;
      v6 = 0x80000000;
      v5 = -1;
    }
    if ( v5 >= SLODWORD(this->m_materialClass[v4].m_declaredMembers) )
      break;
LABEL_10:
    v7 = v5 | v6 | (v3 << (32 - this->m_aabbHalfExtents.m_quad.m128_i8[8]));
    v8 = (hkVector4f *)((__int64 (__fastcall *)(hkpExtendedMeshShape *, _QWORD, char *))this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[2].__first_virtual_table_function__)(
                         this,
                         v7,
                         v11);
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
  if ( v3 < this->m_numBitsForSubpartIndex )
  {
    v5 = 0;
    goto LABEL_10;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 338
// RVA: 0xD14350
__int64 __fastcall hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(
        hkpExtendedMeshShape *this,
        hkpExtendedMeshShape::TrianglesSubpart *subpart,
        int subpartIndex)
{
  unsigned int v3; // edi
  int i; // ebx
  hkVector4f *ChildShape; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-228h] BYREF
  char buffer[512]; // [rsp+30h] [rbp-218h] BYREF

  v3 = 0;
  for ( i = 0; i < subpart->m_numTriangleShapes; ++i )
  {
    ChildShape = (hkVector4f *)hkpExtendedMeshShape::getChildShape(
                                 (hkpExtendedMeshShape *)&this->hkpShapeContainer,
                                 i | (unsigned int)(subpartIndex << (32 - LOBYTE(this->m_numBitsForSubpartIndex))),
                                 (hkpConvexTransformShape *)buffer);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(ChildShape + 3, ChildShape + 4, ChildShape + 5, &tolerance) )
      ++v3;
  }
  return v3;
}

// File Line: 358
// RVA: 0xD14410
__int64 __fastcall hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(
        hkpExtendedMeshShape *this,
        hkpExtendedMeshShape::ShapesSubpart *subpart)
{
  return (unsigned int)subpart->m_childShapes.m_size;
}

// File Line: 438
// RVA: 0xD13630
hkpConvexTransformShape *__fastcall hkpExtendedMeshShape::getChildShape(
        hkpExtendedMeshShape *this,
        int key,
        hkpConvexTransformShape *buffer)
{
  unsigned int v5; // r10d
  signed int v6; // r11d
  unsigned __int64 p_m_type; // r8
  int v8; // eax
  _QWORD *v9; // rdx
  __int64 v10; // r10
  __int64 *v11; // rcx
  __int64 v12; // rax
  __int16 v13; // cx
  __int16 v14; // di
  unsigned __int8 *v15; // rdx
  int v16; // r10d
  int v17; // esi
  int v18; // edx
  __int64 v19; // rbp
  int v20; // r14d
  float v21; // xmm0_4
  __m128 v22; // xmm3
  __int64 v23; // rax
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
  __int64 v43; // r8
  unsigned __int64 v44; // rcx
  char *v45; // rdx
  __int64 v46; // rax
  hkpConvexShape *v47; // rbp
  __m128 v49; // xmm2
  __int64 v50; // rax
  hkTransformf v51[2]; // [rsp+30h] [rbp-1C8h] BYREF
  char v52[64]; // [rsp+BFh] [rbp-139h] BYREF
  _BYTE v53[145]; // [rsp+FFh] [rbp-F9h] BYREF

  v5 = (key & 0x7FFFFFFFu) >> (32 - this->m_aabbHalfExtents.m_quad.m128_i32[2]);
  v6 = key & (0xFFFFFFFF >> this->m_aabbHalfExtents.m_quad.m128_i32[2]);
  if ( key >= 0 )
  {
    p_m_type = (unsigned __int64)v53 & 0xFFFFFFFFFFFFFF70ui64;
    if ( this->m_aabbCenter.m_quad.m128_i32[2] == 1 )
    {
      p_m_type = (unsigned __int64)&this->m_type;
    }
    else
    {
      v8 = 9 * v5;
      v9 = (_QWORD *)((unsigned __int64)v53 & 0xFFFFFFFFFFFFFF70ui64);
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
    v13 = v6 & *(char *)(p_m_type + 75);
    v14 = 0;
    v15 = (unsigned __int8 *)(*(_QWORD *)(p_m_type + 56) + v6 * *(unsigned __int16 *)(p_m_type + 72));
    switch ( *(_BYTE *)(p_m_type + 74) )
    {
      case 1:
        v16 = *v15;
        v17 = v15[(__int16)(v13 + 1)];
        v18 = v15[(__int16)((v13 ^ 1) + 1)];
        break;
      case 2:
        v16 = *(unsigned __int16 *)v15;
        v17 = *(unsigned __int16 *)&v15[2 * (__int16)(v13 + 1)];
        v18 = *(unsigned __int16 *)&v15[2 * (__int16)((v13 ^ 1) + 1)];
        break;
      case 3:
        v16 = *(_DWORD *)v15;
        v17 = *(_DWORD *)&v15[4 * (__int16)(v13 + 1)];
        v18 = *(_DWORD *)&v15[4 * (__int16)((v13 ^ 1) + 1)];
        break;
      default:
        v16 = 0;
        v17 = 0;
        v18 = 0;
        break;
    }
    v19 = *(_QWORD *)(p_m_type + 40);
    v20 = *(unsigned __int16 *)(p_m_type + 64);
    if ( buffer )
    {
      v21 = hkConvexShapeDefaultRadius;
      *(_DWORD *)&buffer->m_memSizeAndFlags = 0x1FFFF;
      *(_DWORD *)&buffer->m_type.m_storage = 1026;
      buffer->m_radius = v21;
      buffer->m_userData = 0i64;
      buffer->vfptr = (hkBaseObjectVtbl *)&hkpTriangleShape::`vftable;
      LODWORD(buffer->m_childShape.hkpConvexTransformShapeBase::vfptr) = 393216;
      buffer->m_transform.m_scale = 0i64;
    }
    else
    {
      buffer = 0i64;
    }
    v22 = *(__m128 *)(p_m_type + 80);
    v23 = *(_QWORD *)(p_m_type + 24);
    buffer->m_type.m_storage = 2;
    buffer->m_userData = v23;
    LODWORD(v23) = this->m_shapesSubparts.m_capacityAndFlags;
    buffer->m_transform.m_scale.m_quad = v22;
    v24 = _mm_mul_ps(v22, v22);
    LODWORD(buffer->m_radius) = v23;
    BYTE2(buffer->m_childShape.hkpConvexTransformShapeBase::vfptr) = this->m_shapesSubparts.m_data;
    BYTE3(buffer->m_childShape.hkpConvexTransformShapeBase::vfptr) = (float)((float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0]
                                                                                   + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
                                                                           + _mm_shuffle_ps(v24, v24, 170).m128_f32[0]) > 0.0;
    if ( this->m_trianglesSubparts.m_size )
      v14 = *(&this->m_trianglesSubparts.m_data->m_typeAndFlags + v6 + (__int64)*(int *)(p_m_type + 68));
    v25 = *(__m128 *)(p_m_type + 112);
    LOWORD(buffer->m_childShape.hkpConvexTransformShapeBase::vfptr) = v14;
    v26 = _mm_shuffle_ps(v25, v25, 255);
    v27 = _mm_shuffle_ps(v25, v25, 201);
    v28 = _mm_mul_ps(
            _mm_movelh_ps(
              (__m128)*(unsigned __int64 *)(v20 * v16 + v19),
              (__m128)*(unsigned int *)(v20 * v16 + v19 + 8)),
            *(__m128 *)(p_m_type + 128));
    v29 = _mm_mul_ps(
            _mm_movelh_ps(
              (__m128)*(unsigned __int64 *)(v20 * v17 + v19),
              (__m128)*(unsigned int *)(v20 * v17 + v19 + 8)),
            *(__m128 *)(p_m_type + 128));
    v30 = _mm_mul_ps(v28, v25);
    v31 = _mm_mul_ps(
            _mm_movelh_ps(
              (__m128)*(unsigned __int64 *)(v20 * v18 + v19),
              (__m128)*(unsigned int *)(v20 * v18 + v19 + 8)),
            *(__m128 *)(p_m_type + 128));
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
    v41 = *(__m128 *)(p_m_type + 96);
    v42 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                  _mm_shuffle_ps(v38, v38, 170)),
                v25),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v31)),
            _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v26));
    *(__m128 *)&buffer->m_childShape.m_childShape = _mm_add_ps(_mm_add_ps(v35, v35), v41);
    buffer->m_transform.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v39, v39), v41);
    buffer->m_transform.m_rotation.m_vec.m_quad = _mm_add_ps(_mm_add_ps(v42, v42), v41);
    return buffer;
  }
  v43 = 10i64;
  v44 = (unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64;
  v45 = (char *)&this->m_materialClass[v5] - ((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64);
  do
  {
    v46 = *(_QWORD *)&v45[v44];
    v44 += 8i64;
    *(_QWORD *)(v44 - 8) = v46;
    --v43;
  }
  while ( v43 );
  v47 = *(hkpConvexShape **)(*(_QWORD *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x20) + 8i64 * v6);
  if ( (*(_DWORD *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x4C) & 0xC0FFFFFF) == 0 )
    return *(hkpConvexTransformShape **)(*(_QWORD *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x20) + 8i64 * v6);
  if ( (*(_DWORD *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x4C) & 0xC0FFFFFF) != 1 )
  {
    hkRotationf::set(&v51[0].m_rotation, (hkQuaternionf *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 48));
    v51[0].m_translation = *(hkVector4f *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x40);
    if ( buffer )
    {
      hkpConvexTransformShape::hkpConvexTransformShape(buffer, v47, v51, REFERENCE_POLICY_IGNORE);
      return (hkpConvexTransformShape *)v50;
    }
    return 0i64;
  }
  if ( !buffer )
    return 0i64;
  hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
    buffer,
    CONVEX_TRANSLATE,
    v47->m_radius,
    *(hkpConvexShape **)(*(_QWORD *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x20) + 8i64 * v6),
    REFERENCE_POLICY_IGNORE);
  buffer->m_childShapeSizeForSpu = 0;
  v49 = *(__m128 *)(((unsigned __int64)v52 & 0xFFFFFFFFFFFFFFB0ui64) + 0x40);
  buffer->vfptr = (hkBaseObjectVtbl *)&hkpConvexTranslateShape::`vftable;
  buffer->m_transform.m_translation.m_quad = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, (__m128)0i64), 196);
  return buffer;
}

// File Line: 670
// RVA: 0xD13030
hkpMeshMaterial *__fastcall hkpExtendedMeshShape::getMeshMaterial(hkpExtendedMeshShape *this, int key)
{
  unsigned int v2; // r10d
  unsigned int v3; // r11d
  hkpExtendedMeshShape::TrianglesSubpart *p_m_embeddedTrianglesSubpart; // rcx
  unsigned __int8 *m_materialIndexBase; // r9
  int m_materialStriding; // r8d
  __int64 v7; // rdx
  __int64 v8; // rax

  v2 = (key & 0x7FFFFFFFu) >> (32 - this->m_numBitsForSubpartIndex);
  v3 = key & (0xFFFFFFFF >> this->m_numBitsForSubpartIndex);
  if ( key < 0 )
  {
    p_m_embeddedTrianglesSubpart = (hkpExtendedMeshShape::TrianglesSubpart *)&this->m_shapesSubparts.m_data[v2];
  }
  else if ( this->m_trianglesSubparts.m_size == 1 )
  {
    p_m_embeddedTrianglesSubpart = &this->m_embeddedTrianglesSubpart;
  }
  else
  {
    p_m_embeddedTrianglesSubpart = &this->m_trianglesSubparts.m_data[v2];
  }
  m_materialIndexBase = (unsigned __int8 *)p_m_embeddedTrianglesSubpart->m_materialIndexBase;
  m_materialStriding = p_m_embeddedTrianglesSubpart->m_materialStriding;
  if ( !m_materialIndexBase || m_materialStriding <= 0 )
    return 0i64;
  v7 = (int)(v3 * p_m_embeddedTrianglesSubpart->m_materialIndexStriding);
  if ( (p_m_embeddedTrianglesSubpart->m_typeAndFlags & 6) == 2 )
    v8 = m_materialStriding * m_materialIndexBase[v7];
  else
    v8 = m_materialStriding * *(unsigned __int16 *)&m_materialIndexBase[v7];
  return (hkpMeshMaterial *)((char *)p_m_embeddedTrianglesSubpart->m_materialBase + v8);
}

// File Line: 737
// RVA: 0xD13B50
__int64 __fastcall hkpExtendedMeshShape::getCollisionFilterInfo(hkpExtendedMeshShape *this, int key)
{
  hkpMeshMaterial *MeshMaterial; // rax

  MeshMaterial = hkpExtendedMeshShape::getMeshMaterial((hkpExtendedMeshShape *)((char *)this - 32), key);
  if ( MeshMaterial )
    return MeshMaterial->m_filterInfo;
  else
    return HIDWORD(this->m_shapesSubparts.m_data);
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
  v5 = _mm_mul_ps(v3.m_vec.m_quad, v4);
  v6 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
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
void __fastcall hkpExtendedMeshShape::getAabb(
        hkpExtendedMeshShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
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
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 85),
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
             _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), localToWorld->m_rotation.m_col1.m_quad)),
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
  hkVector4f v4; // xmm8
  const float *m_vertexBase; // r8
  unsigned __int16 *v6; // r9
  int m_vertexStriding; // edx
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
  hkVector4f v19; // xmm7
  hkVector4f v20; // xmm8
  hkQuaternionf v21; // xmm2
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm4
  hkVector4f v28; // xmm7
  hkVector4f v29; // xmm8
  hkQuaternionf v30; // xmm2
  __m128 v31; // xmm6
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 v36; // xmm4

  v2 = 0;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  if ( part->m_numTriangleShapes > 0 )
  {
    v4.m_quad = (__m128)xmmword_141A712F0;
    while ( 1 )
    {
      m_vertexBase = part->m_vertexBase;
      v6 = (unsigned __int16 *)((char *)part->m_indexBase + v2 * part->m_indexStriding);
      if ( part->m_stridingType.m_storage == 1 )
        break;
      m_vertexStriding = part->m_vertexStriding;
      if ( part->m_stridingType.m_storage == 2 )
      {
        v8 = m_vertexStriding * *v6;
        v9 = m_vertexStriding * v6[1];
        v11 = v6[2];
LABEL_8:
        v10 = m_vertexStriding * v11;
        goto LABEL_9;
      }
      v8 = (unsigned int)(m_vertexStriding * *(_DWORD *)v6);
      v9 = (unsigned int)(m_vertexStriding * *((_DWORD *)v6 + 1));
      v10 = (unsigned int)(*((_DWORD *)v6 + 2) * m_vertexStriding);
LABEL_9:
      v12.m_vec.m_quad = (__m128)part->m_transform.m_rotation;
      v13 = _mm_shuffle_ps(v12.m_vec.m_quad, v12.m_vec.m_quad, 255);
      v14 = _mm_mul_ps(
              part->m_transform.m_scale.m_quad,
              (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_movelh_ps(
                                     (__m128)*(unsigned __int64 *)((char *)m_vertexBase + v8),
                                     (__m128)*(unsigned int *)((char *)m_vertexBase + v8 + 8)),
                          4),
                        4));
      v15 = _mm_mul_ps(v12.m_vec.m_quad, v14);
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
      v19.m_quad = _mm_min_ps(out->m_min.m_quad, v18);
      v20.m_quad = _mm_max_ps(v4.m_quad, v18);
      out->m_min = (hkVector4f)v19.m_quad;
      out->m_max = (hkVector4f)v20.m_quad;
      v21.m_vec.m_quad = (__m128)part->m_transform.m_rotation;
      v22 = _mm_mul_ps(
              (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_movelh_ps(
                                     (__m128)*(unsigned __int64 *)((char *)m_vertexBase + v9),
                                     (__m128)*(unsigned int *)((char *)m_vertexBase + v9 + 8)),
                          4),
                        4),
              part->m_transform.m_scale.m_quad);
      v23 = _mm_mul_ps(v21.m_vec.m_quad, v22);
      v24 = _mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 255);
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
      v28.m_quad = _mm_min_ps(v19.m_quad, v27);
      v29.m_quad = _mm_max_ps(v20.m_quad, v27);
      ++v2;
      out->m_min = (hkVector4f)v28.m_quad;
      out->m_max = (hkVector4f)v29.m_quad;
      v30.m_vec.m_quad = (__m128)part->m_transform.m_rotation;
      v31 = _mm_mul_ps(
              (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_movelh_ps(
                                     (__m128)*(unsigned __int64 *)((char *)m_vertexBase + v10),
                                     (__m128)*(unsigned int *)((char *)m_vertexBase + v10 + 8)),
                          4),
                        4),
              part->m_transform.m_scale.m_quad);
      v32 = _mm_mul_ps(v30.m_vec.m_quad, v31);
      v33 = _mm_shuffle_ps(v30.m_vec.m_quad, v30.m_vec.m_quad, 255);
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
      v4.m_quad = _mm_max_ps(v29.m_quad, v36);
      out->m_min.m_quad = _mm_min_ps(v28.m_quad, v36);
      out->m_max = (hkVector4f)v4.m_quad;
      if ( v2 >= part->m_numTriangleShapes )
        return;
    }
    m_vertexStriding = part->m_vertexStriding;
    v8 = m_vertexStriding * *(unsigned __int8 *)v6;
    v9 = m_vertexStriding * *((unsigned __int8 *)v6 + 1);
    v11 = *((unsigned __int8 *)v6 + 2);
    goto LABEL_8;
  }
}

// File Line: 830
// RVA: 0xD13FF0
void __fastcall hkpExtendedMeshShape::calcAabbExtents(hkpExtendedMeshShape::ShapesSubpart *part, hkAabb *out)
{
  __int64 v4; // r8
  int v5; // esi
  __int64 v6; // r14
  hkVector4f v7; // xmm1
  __m128 v8[2]; // [rsp+20h] [rbp-68h] BYREF
  hkRotationf v9; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f v10; // [rsp+70h] [rbp-18h]

  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  hkRotationf::set(&v9, &part->m_rotation);
  v5 = 0;
  v10.m_quad = (__m128)part->m_translation;
  if ( part->m_childShapes.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpConvexShape *, hkRotationf *, __int64, __m128 *))part->m_childShapes.m_data[v6].m_pntr->vfptr[2].__vecDelDtor)(
        part->m_childShapes.m_data[v6].m_pntr,
        &v9,
        v4,
        v8);
      ++v5;
      ++v6;
      v7.m_quad = _mm_max_ps(out->m_max.m_quad, v8[1]);
      out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v8[0]);
      out->m_max = (hkVector4f)v7.m_quad;
    }
    while ( v5 < part->m_childShapes.m_size );
  }
}

// File Line: 846
// RVA: 0xD140C0
void __fastcall hkpExtendedMeshShape::recalcAabbExtents(hkpExtendedMeshShape *this)
{
  __m128 v1; // xmm6
  int v2; // edi
  int v4; // esi
  __m128 v5; // xmm7
  __m128 i; // xmm8
  hkAabb out; // [rsp+20h] [rbp-58h] BYREF

  v1 = (__m128)xmmword_141A712F0;
  v2 = 0;
  v4 = 0;
  v5 = (__m128)xmmword_141A712A0;
  for ( i = _mm_shuffle_ps((__m128)LODWORD(this->m_triangleRadius), (__m128)LODWORD(this->m_triangleRadius), 0);
        v4 < this->m_trianglesSubparts.m_size;
        v1 = _mm_max_ps(v1, _mm_add_ps(out.m_max.m_quad, i)) )
  {
    hkpExtendedMeshShape::calcAabbExtents(&this->m_trianglesSubparts.m_data[v4++], &out);
    v5 = _mm_min_ps(v5, _mm_sub_ps(out.m_min.m_quad, i));
  }
  if ( this->m_shapesSubparts.m_size > 0 )
  {
    do
    {
      hkpExtendedMeshShape::calcAabbExtents(&this->m_shapesSubparts.m_data[v2++], &out);
      v5 = _mm_min_ps(v5, out.m_min.m_quad);
      v1 = _mm_max_ps(v1, out.m_max.m_quad);
    }
    while ( v2 < this->m_shapesSubparts.m_size );
  }
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v5, v1), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v1, v5), (__m128)xmmword_141A711B0);
}

// File Line: 881
// RVA: 0xD14420
void __fastcall hkpExtendedMeshShape::assertTrianglesSubpartValidity(
        hkpExtendedMeshShape *this,
        hkpExtendedMeshShape::TrianglesSubpart *part)
{
  ;
}

// File Line: 905
// RVA: 0xD14430
void __fastcall hkpExtendedMeshShape::assertShapesSubpartValidity(
        hkpExtendedMeshShape *this,
        hkpExtendedMeshShape::ShapesSubpart *part)
{
  ;
}

// File Line: 919
// RVA: 0xD12E10
void __fastcall hkpExtendedMeshShape::addTrianglesSubpart(
        hkpExtendedMeshShape *this,
        hkpExtendedMeshShape::TrianglesSubpart *part)
{
  hkpExtendedMeshShape::TrianglesSubpart *v4; // rax
  hkVector4f v5; // xmm7
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  int v8; // r8d
  __m128 v9; // xmm0
  __m128 v10; // xmm7
  __m128 v11; // xmm6
  hkAabb out; // [rsp+20h] [rbp-48h] BYREF

  v4 = hkpExtendedMeshShape::expandOneTriangleSubparts(this);
  *(_QWORD *)&v4->m_typeAndFlags = *(_QWORD *)&part->m_typeAndFlags;
  v4->m_materialIndexBase = part->m_materialIndexBase;
  v4->m_materialBase = part->m_materialBase;
  v4->m_userData = part->m_userData;
  v4->m_numTriangleShapes = part->m_numTriangleShapes;
  v4->m_vertexBase = part->m_vertexBase;
  v4->m_numVertices = part->m_numVertices;
  v4->m_indexBase = part->m_indexBase;
  v4->m_vertexStriding = part->m_vertexStriding;
  v4->m_triangleOffset = part->m_triangleOffset;
  v4->m_indexStriding = part->m_indexStriding;
  v4->m_stridingType.m_storage = part->m_stridingType.m_storage;
  v4->m_flipAlternateTriangles = part->m_flipAlternateTriangles;
  v4->m_extrusion = part->m_extrusion;
  v4->m_transform = part->m_transform;
  v5.m_quad = (__m128)this->m_aabbHalfExtents;
  v6 = _mm_sub_ps(this->m_aabbCenter.m_quad, v5.m_quad);
  v7 = _mm_add_ps(v5.m_quad, this->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v4, &out);
  v8 = this->m_trianglesSubparts.m_size - 1;
  v9 = _mm_shuffle_ps((__m128)LODWORD(this->m_triangleRadius), (__m128)LODWORD(this->m_triangleRadius), 0);
  v10 = _mm_max_ps(v7, _mm_add_ps(out.m_max.m_quad, v9));
  v11 = _mm_min_ps(v6, _mm_sub_ps(out.m_min.m_quad, v9));
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v10, v11), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v10, v11), (__m128)xmmword_141A711B0);
  this->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInTrianglesSubpart(this, part, v8);
}

// File Line: 954
// RVA: 0xD12F70
__int64 __fastcall hkpExtendedMeshShape::addShapesSubpart(
        hkpExtendedMeshShape *this,
        hkpExtendedMeshShape::ShapesSubpart *part)
{
  hkpExtendedMeshShape::ShapesSubpart *v4; // rbx
  hkVector4f v5; // xmm7
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  hkAabb out; // [rsp+20h] [rbp-48h] BYREF

  v4 = hkpExtendedMeshShape::expandOneShapesSubparts(this);
  hkpExtendedMeshShape::ShapesSubpart::operator=(v4, part);
  v5.m_quad = (__m128)this->m_aabbHalfExtents;
  v6 = _mm_sub_ps(this->m_aabbCenter.m_quad, v5.m_quad);
  v7 = _mm_add_ps(v5.m_quad, this->m_aabbCenter.m_quad);
  hkpExtendedMeshShape::calcAabbExtents(v4, &out);
  v8 = _mm_max_ps(v7, out.m_max.m_quad);
  v9 = _mm_min_ps(v6, out.m_min.m_quad);
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v8, v9), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v8, v9), (__m128)xmmword_141A711B0);
  this->m_cachedNumChildShapes += hkpExtendedMeshShape::_getNumChildShapesInShapesSubpart(this, part);
  return (unsigned int)(this->m_shapesSubparts.m_size - 1);
}

// File Line: 987
// RVA: 0xD12410
void __fastcall hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(
        hkpExtendedMeshShape::ShapesSubpart *this,
        hkFinishLoadedObjectFlag flag)
{
  int v3; // edx
  hkQuaternionf v4; // xmm9
  int v5; // ecx
  __m128 v6; // xmm9
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  char v16; // al

  if ( flag.m_finishing )
  {
    v3 = 2;
    v4.m_vec.m_quad = (__m128)this->m_rotation;
    v5 = 0;
    v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v4.m_vec.m_quad, v4.m_vec.m_quad, 255), 1u), 1u);
    v7 = _mm_andnot_ps(*(__m128 *)_xmm, v6);
    v8 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v7), *(__m128 *)_xmm);
    v9 = _mm_cmplt_ps(*(__m128 *)_xmm, v7);
    v10 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v8), v9), _mm_andnot_ps(v9, v7));
    v11 = _mm_or_ps(_mm_andnot_ps(v9, _mm_mul_ps(v7, v7)), _mm_and_ps(v9, v8));
    v12 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v11, *(__m128 *)coeff4), *(__m128 *)coeff3), v11),
                          *(__m128 *)coeff2),
                        v11),
                      *(__m128 *)coeff1),
                    v11),
                  *(__m128 *)coeff0),
                v11),
              v10),
            v10);
    v13 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v12, v12)), v9);
    v14 = _mm_andnot_ps(v9, v12);
    v15 = _mm_cmplt_ps(v7, *(__m128 *)_xmm);
    v16 = _mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_translation), 1u), 1u),
              _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0)));
    if ( (float)((float)(1.5707964
                       - COERCE_FLOAT((_mm_andnot_ps(v15, _mm_or_ps(v13, v14)).m128_u32[0] | v15.m128_i32[0] & v7.m128_i32[0]) ^ v6.m128_i32[0] & _xmm[0]))
               * 2.0) < 0.001 )
      v3 = 0;
    LOBYTE(v5) = (v16 & 7) != 7;
    this->m_translation.m_quad.m128_i32[3] = v5 | v3 | 0x3F000000;
  }
}

// File Line: 1000
// RVA: 0xD120F0
void __fastcall hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(
        hkpExtendedMeshShape::ShapesSubpart *this,
        hkpConvexShape *const *childShapes,
        int numChildShapes,
        const __m128i *offset)
{
  int v4; // ebp
  __int64 v5; // rdi
  __int64 m_size; // r12
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  __int64 v13; // rsi
  hkRefPtr<hkpConvexShape> *v14; // rdx
  __int64 v15; // rax
  hkRefPtr<hkpConvexShape> *m_data; // rax
  hkReferencedObject **p_m_pntr; // rbx
  char *v18; // r14
  hkReferencedObject *v19; // rdi
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  v4 = 0;
  *(_QWORD *)&this->m_typeAndFlags = 11i64;
  v5 = numChildShapes;
  this->m_materialBase = 0i64;
  this->m_materialIndexBase = 0i64;
  this->m_userData = 0i64;
  this->m_childShapes.m_data = 0i64;
  this->m_childShapes.m_size = 0;
  this->m_childShapes.m_capacityAndFlags = 0x80000000;
  this->m_translation = (hkVector4f)*offset;
  m_size = this->m_childShapes.m_size;
  v10 = m_size + numChildShapes;
  v11 = this->m_childShapes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 >= (int)m_size + numChildShapes )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v12 = 2 * v11;
    if ( v10 < v12 )
      v10 = v12;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_childShapes.m_data,
      v10,
      8);
  }
  v13 = v5;
  v14 = &this->m_childShapes.m_data[this->m_childShapes.m_size];
  if ( (int)v5 > 0 )
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
  m_data = this->m_childShapes.m_data;
  this->m_childShapes.m_size += v5;
  p_m_pntr = &m_data[m_size].m_pntr;
  if ( (int)v5 > 0 )
  {
    v18 = (char *)((char *)childShapes - (char *)p_m_pntr);
    do
    {
      v19 = *(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v18);
      if ( v19 )
        hkReferencedObject::addReference(*(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v18));
      if ( *p_m_pntr )
        hkReferencedObject::removeReference(*p_m_pntr);
      *p_m_pntr++ = v19;
      --v13;
    }
    while ( v13 );
  }
  result.m_enum = LODWORD(FLOAT_0_001);
  this->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  LOBYTE(v4) = (_mm_movemask_ps(
                  _mm_cmplt_ps(
                    (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(offset), 1u), 1u),
                    _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0))) & 7) != 7;
  this->m_translation.m_quad.m128_i32[3] = v4 | 0x3F000000;
}

// File Line: 1016
// RVA: 0xD12270
void __fastcall hkpExtendedMeshShape::ShapesSubpart::ShapesSubpart(
        hkpExtendedMeshShape::ShapesSubpart *this,
        hkpConvexShape *const *childShapes,
        int numChildShapes,
        hkTransformf *transform)
{
  hkQuaternionf *p_m_rotation; // rcx
  __int64 v8; // rdi
  __int64 m_size; // r12
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  __int64 v13; // rsi
  hkRefPtr<hkpConvexShape> *v14; // rdx
  __int64 v15; // rax
  hkRefPtr<hkpConvexShape> *m_data; // rax
  hkReferencedObject **p_m_pntr; // rbx
  char *v18; // r14
  hkReferencedObject *v19; // rdi
  __m128i si128; // xmm1
  BOOL v21; // ebx
  bool isApproximatelyEqual; // al
  int v23; // ecx
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  *(_QWORD *)&this->m_typeAndFlags = 11i64;
  this->m_materialBase = 0i64;
  this->m_materialIndexBase = 0i64;
  this->m_userData = 0i64;
  this->m_childShapes.m_data = 0i64;
  this->m_childShapes.m_size = 0;
  this->m_childShapes.m_capacityAndFlags = 0x80000000;
  p_m_rotation = &this->m_rotation;
  p_m_rotation[1] = (hkQuaternionf)transform->m_translation;
  v8 = numChildShapes;
  hkQuaternionf::set(p_m_rotation, &transform->m_rotation);
  m_size = this->m_childShapes.m_size;
  v10 = m_size + v8;
  v11 = this->m_childShapes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 >= (int)m_size + (int)v8 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v12 = 2 * v11;
    if ( v10 < v12 )
      v10 = v12;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_childShapes.m_data,
      v10,
      8);
  }
  v13 = v8;
  v14 = &this->m_childShapes.m_data[this->m_childShapes.m_size];
  if ( (int)v8 > 0 )
  {
    v15 = v8;
    do
    {
      if ( v14 )
        v14->m_pntr = 0i64;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  m_data = this->m_childShapes.m_data;
  this->m_childShapes.m_size += v8;
  p_m_pntr = &m_data[m_size].m_pntr;
  if ( (int)v8 > 0 )
  {
    v18 = (char *)((char *)childShapes - (char *)p_m_pntr);
    do
    {
      v19 = *(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v18);
      if ( v19 )
        hkReferencedObject::addReference(*(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v18));
      if ( *p_m_pntr )
        hkReferencedObject::removeReference(*p_m_pntr);
      *p_m_pntr++ = v19;
      --v13;
    }
    while ( v13 );
  }
  si128 = _mm_load_si128((const __m128i *)&this->m_translation);
  result.m_enum = 981668463;
  v21 = (_mm_movemask_ps(
           _mm_cmplt_ps(
             (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u),
             _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0))) & 7) != 7;
  isApproximatelyEqual = hkMatrix3f::isApproximatelyEqual(&transform->m_rotation, (hkMatrix3f *)&::transform, 0.001);
  v23 = 2;
  if ( isApproximatelyEqual )
    v23 = 0;
  this->m_translation.m_quad.m128_i32[3] = v23 | v21 | 0x3F000000;
}

// File Line: 1029
// RVA: 0xD125A0
void __fastcall hkpExtendedMeshShape::ShapesSubpart::~ShapesSubpart(hkpExtendedMeshShape::ShapesSubpart *this)
{
  hkRefPtr<hkpConvexShape> *m_data; // rsi
  int v2; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  int m_capacityAndFlags; // r8d

  m_data = this->m_childShapes.m_data;
  v2 = this->m_childShapes.m_size - 1;
  for ( i = v2; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  m_capacityAndFlags = this->m_childShapes.m_capacityAndFlags;
  this->m_childShapes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_childShapes.m_data,
      8 * m_capacityAndFlags);
  this->m_childShapes.m_data = 0i64;
  this->m_childShapes.m_capacityAndFlags = 0x80000000;
}

// File Line: 1035
// RVA: 0xD13C60
__int64 __fastcall hkpExtendedMeshShape::calcSizeForSpu(
        hkpExtendedMeshShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int v3; // ebp
  __int64 i; // r14
  int v7; // ebx
  hkpExtendedMeshShape::ShapesSubpart *v8; // rsi
  __int64 v9; // rdi
  int v10; // eax
  int v11; // ecx

  v3 = 0;
  if ( this->m_shapesSubparts.m_size <= 0 )
    return 320i64;
  for ( i = 0i64; ; ++i )
  {
    v7 = 0;
    v8 = &this->m_shapesSubparts.m_data[i];
    if ( v8->m_childShapes.m_size > 0 )
      break;
LABEL_12:
    if ( ++v3 >= this->m_shapesSubparts.m_size )
      return 320i64;
  }
  v9 = 0i64;
  while ( 1 )
  {
    v10 = ((__int64 (__fastcall *)(hkpConvexShape *, hkpShape::CalcSizeForSpuInput *, __int64))v8->m_childShapes.m_data[v9].m_pntr->vfptr[8].__vecDelDtor)(
            v8->m_childShapes.m_data[v9].m_pntr,
            input,
            256i64);
    if ( (v8->m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF) != 0 )
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
hkpExtendedMeshShape::TrianglesSubpart *__fastcall hkpExtendedMeshShape::expandOneTriangleSubparts(
        hkpExtendedMeshShape *this)
{
  hkpExtendedMeshShape::TrianglesSubpart *p_m_embeddedTrianglesSubpart; // rax
  hkArray<hkpExtendedMeshShape::TrianglesSubpart,hkContainerHeapAllocator> *p_m_trianglesSubparts; // rbx
  __int64 m_size; // rdi
  int v4; // r9d
  int v5; // eax
  int v6; // eax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  if ( this->m_trianglesSubparts.m_size )
  {
    p_m_trianglesSubparts = &this->m_trianglesSubparts;
    m_size = this->m_trianglesSubparts.m_size;
    v4 = m_size + 1;
    v5 = this->m_trianglesSubparts.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < (int)m_size + 1 )
    {
      v6 = 2 * v5;
      if ( v4 < v6 )
        v4 = v6;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_trianglesSubparts->m_data,
        v4,
        144);
    }
    ++p_m_trianglesSubparts->m_size;
    return &p_m_trianglesSubparts->m_data[m_size];
  }
  else
  {
    p_m_embeddedTrianglesSubpart = &this->m_embeddedTrianglesSubpart;
    this->m_trianglesSubparts.m_size = 1;
    this->m_trianglesSubparts.m_capacityAndFlags = -2147483647;
    this->m_trianglesSubparts.m_data = &this->m_embeddedTrianglesSubpart;
  }
  return p_m_embeddedTrianglesSubpart;
}

// File Line: 1112
// RVA: 0xD14280
hkpExtendedMeshShape::ShapesSubpart *__fastcall hkpExtendedMeshShape::expandOneShapesSubparts(
        hkpExtendedMeshShape *this)
{
  hkArray<hkpExtendedMeshShape::ShapesSubpart,hkContainerHeapAllocator> *p_m_shapesSubparts; // rbx
  __int64 m_size; // rdi
  int v3; // r9d
  int v4; // eax
  int v5; // eax
  __int64 v6; // rcx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  p_m_shapesSubparts = &this->m_shapesSubparts;
  m_size = this->m_shapesSubparts.m_size;
  v3 = m_size + 1;
  v4 = this->m_shapesSubparts.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 >= (int)m_size + 1 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v5 = 2 * v4;
    if ( v3 < v5 )
      v3 = v5;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_shapesSubparts->m_data,
      v3,
      80);
  }
  v6 = (__int64)&p_m_shapesSubparts->m_data[p_m_shapesSubparts->m_size];
  if ( v6 )
  {
    *(_QWORD *)v6 = 11i64;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 8) = 0i64;
    *(_QWORD *)(v6 + 24) = 0i64;
    *(_QWORD *)(v6 + 32) = 0i64;
    *(_DWORD *)(v6 + 40) = 0;
    *(_DWORD *)(v6 + 44) = 0x80000000;
  }
  ++p_m_shapesSubparts->m_size;
  return &p_m_shapesSubparts->m_data[m_size];
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

