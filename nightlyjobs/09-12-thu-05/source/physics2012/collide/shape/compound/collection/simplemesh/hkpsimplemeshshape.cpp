// File Line: 21
// RVA: 0xD19370
void __fastcall hkpSimpleMeshShape::hkpSimpleMeshShape(hkpSimpleMeshShape *this, float radius)
{
  hkpShapeCollection::hkpShapeCollection(this, TRIANGLE_COLLECTION, COLLECTION_SIMPLE_MESH);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpSimpleMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpSimpleMeshShape::`vftable{for `hkpShapeContainer};
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_materialIndices.m_data = 0i64;
  this->m_materialIndices.m_size = 0;
  this->m_materialIndices.m_capacityAndFlags = 0x80000000;
  this->m_weldingType.m_storage = 6;
  this->m_radius = radius;
}

// File Line: 32
// RVA: 0xD193F0
void __fastcall hkpSimpleMeshShape::hkpSimpleMeshShape(hkpSimpleMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShapeCollection::hkpShapeCollection(this, flag);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpSimpleMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpSimpleMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 27;
    this->m_collectionType.m_storage = 4;
  }
}

// File Line: 43
// RVA: 0xD19680
void __fastcall hkpSimpleMeshShape::setWeldingInfo(
        hkpSimpleMeshShape *this,
        unsigned int key,
        unsigned __int16 weldingInfo)
{
  this->m_triangles.m_data[key].m_weldingInfo = weldingInfo;
}

// File Line: 51
// RVA: 0xD196A0
void __fastcall hkpSimpleMeshShape::initWeldingInfo(
        hkpSimpleMeshShape *this,
        hkpWeldingUtility::WeldingType weldingType)
{
  int v2; // r8d
  __int64 v3; // rdx

  this->m_weldingType.m_storage = weldingType;
  v2 = 0;
  if ( this->m_triangles.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v2;
      this->m_triangles.m_data[v3++].m_weldingInfo = 0;
    }
    while ( v2 < this->m_triangles.m_size );
  }
}

// File Line: 61
// RVA: 0xD196E0
void __fastcall hkpSimpleMeshShape::getAabb(
        hkpSimpleMeshShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  int v4; // r8d
  hkVector4f v6; // xmm3
  __int64 v7; // r10
  __m128 m_quad; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  hkVector4f v11; // xmm1

  v4 = 0;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  if ( this->m_vertices.m_size > 0 )
  {
    v6.m_quad = (__m128)xmmword_141A712F0;
    v7 = 0i64;
    do
    {
      ++v4;
      m_quad = this->m_vertices.m_data[v7++].m_quad;
      v9 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), localToWorld->m_rotation.m_col1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), localToWorld->m_rotation.m_col0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), localToWorld->m_rotation.m_col2.m_quad)),
             localToWorld->m_translation.m_quad);
      v6.m_quad = _mm_max_ps(v6.m_quad, v9);
      out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v9);
      out->m_max = (hkVector4f)v6.m_quad;
    }
    while ( v4 < this->m_vertices.m_size );
  }
  v10 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
          (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
          0);
  v11.m_quad = _mm_add_ps(out->m_max.m_quad, v10);
  out->m_min.m_quad = _mm_sub_ps(out->m_min.m_quad, v10);
  out->m_max = (hkVector4f)v11.m_quad;
}

// File Line: 84
// RVA: 0xD195B0
hkpShape *__fastcall hkpSimpleMeshShape::getChildShape(hkpSimpleMeshShape *this, int key, char (*buffer)[512])
{
  char (*v3)[512]; // r11
  int m_data; // xmm0_4
  char v5; // r10
  __int16 v6; // r9
  hkpShape *result; // rax

  v3 = buffer;
  if ( buffer )
  {
    m_data = (int)this->m_triangles.m_data;
    v5 = BYTE4(this->m_triangles.m_data);
    v6 = *((_WORD *)&this->hkpShapeCollection::hkpShapeContainer::vfptr->getNumChildShapes + 8 * key + 2);
    *(_DWORD *)&(*buffer)[8] = 0x1FFFF;
    *(_DWORD *)&(*buffer)[16] = 1026;
    *(_DWORD *)&(*buffer)[32] = m_data;
    *(_QWORD *)&(*buffer)[24] = 0i64;
    (*buffer)[42] = v5;
    *(_OWORD *)&(*buffer)[96] = 0i64;
    *(_WORD *)&(*buffer)[40] = v6;
    (*buffer)[43] = 0;
    *(_QWORD *)buffer = &hkpTriangleShape::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  result = (hkpShape *)v3;
  *(_OWORD *)&(*v3)[48] = *(_OWORD *)(*(_QWORD *)&this->m_type.m_storage
                                    + 16i64
                                    * *((int *)&this->hkpShapeCollection::hkpShapeContainer::vfptr->__vecDelDtor
                                      + 4 * key));
  *(_OWORD *)&(*v3)[64] = *(_OWORD *)(*(_QWORD *)&this->m_type.m_storage
                                    + 16i64
                                    * *((int *)&this->hkpShapeCollection::hkpShapeContainer::vfptr->__vecDelDtor
                                      + 4 * key
                                      + 1));
  *(_OWORD *)&(*v3)[80] = *(_OWORD *)(*(_QWORD *)&this->m_type.m_storage
                                    + 16i64
                                    * *((int *)&this->hkpShapeCollection::hkpShapeContainer::vfptr->getNumChildShapes
                                      + 4 * key));
  return result;
}

// File Line: 108
// RVA: 0xD19440
__int64 __fastcall hkpSimpleMeshShape::getFirstKey(hkpSimpleMeshShape *this)
{
  unsigned int v1; // ebx
  __int64 i; // rdi
  __int64 v4; // r9
  hkpShapeContainerVtbl *vfptr; // rax
  __int64 v6; // r8
  __int64 v7; // rdx
  __int64 v8; // rcx
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-18h] BYREF

  v1 = 0;
  if ( *(int *)&this->m_disableWelding.m_bool <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = 0i64; ; i += 16i64 )
  {
    v4 = *(_QWORD *)&this->m_type.m_storage;
    vfptr = this->hkpShapeCollection::hkpShapeContainer::vfptr;
    v6 = *(int *)((char *)&vfptr->getNumChildShapes + i);
    v7 = *(int *)((char *)&vfptr->__vecDelDtor + i + 4);
    v8 = *(int *)((char *)&vfptr->__vecDelDtor + i);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(
            (hkVector4f *)(v4 + 16 * v8),
            (hkVector4f *)(v4 + 16 * v7),
            (hkVector4f *)(v4 + 16 * v6),
            &tolerance) )
      break;
    if ( (signed int)++v1 >= *(_DWORD *)&this->m_disableWelding.m_bool )
      return 0xFFFFFFFFi64;
  }
  return v1;
}

// File Line: 124
// RVA: 0xD194F0
__int64 __fastcall hkpSimpleMeshShape::getNextKey(hkpSimpleMeshShape *this, unsigned int oldKey)
{
  unsigned int v2; // ebx
  __int64 i; // rdi
  __int64 v5; // r9
  hkpShapeContainerVtbl *vfptr; // rax
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rcx
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-18h] BYREF

  v2 = oldKey + 1;
  if ( (signed int)(oldKey + 1) >= *(_DWORD *)&this->m_disableWelding.m_bool )
    return 0xFFFFFFFFi64;
  for ( i = 16i64 * (int)v2; ; i += 16i64 )
  {
    v5 = *(_QWORD *)&this->m_type.m_storage;
    vfptr = this->hkpShapeCollection::hkpShapeContainer::vfptr;
    v7 = *(int *)((char *)&vfptr->getNumChildShapes + i);
    v8 = *(int *)((char *)&vfptr->__vecDelDtor + i + 4);
    v9 = *(int *)((char *)&vfptr->__vecDelDtor + i);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(
            (hkVector4f *)(v5 + 16 * v9),
            (hkVector4f *)(v5 + 16 * v8),
            (hkVector4f *)(v5 + 16 * v7),
            &tolerance) )
      break;
    if ( (signed int)++v2 >= *(_DWORD *)&this->m_disableWelding.m_bool )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

