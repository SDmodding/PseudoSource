// File Line: 19
// RVA: 0xD0D6B0
void __fastcall hkpConvexListShape::hkpConvexListShape(
        hkpConvexListShape *this,
        hkpConvexShape *const *shapeArray,
        int numShapes)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1050;
  this->hkpConvexShape::hkpSphereRepShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexListShape::`vftable{for `hkpConvexShape};
  this->m_userData = 0i64;
  this->m_radius = 0.0;
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexListShape::`vftable{for `hkpShapeContainer};
  this->m_childShapes.m_data = 0i64;
  this->m_childShapes.m_size = 0;
  this->m_childShapes.m_capacityAndFlags = 0x80000000;
  this->m_minDistanceToUseConvexHullForGetClosestPoints = 1.0;
  hkpConvexListShape::setShapesAndRadius(this, shapeArray, numShapes);
  hkpConvexListShape::setUseCachedAabb(this, 1);
}

// File Line: 47
// RVA: 0xD0E010
void __fastcall hkpConvexListShape::hkpConvexListShape(hkpConvexListShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->hkpConvexShape::hkpSphereRepShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexListShape::`vftable{for `hkpConvexShape};
  this->m_type.m_storage = 26;
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexListShape::`vftable{for `hkpShapeContainer};
}

// File Line: 54
// RVA: 0xD0D720
void __fastcall hkpConvexListShape::~hkpConvexListShape(hkpConvexListShape *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->hkpConvexShape::hkpSphereRepShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexListShape::`vftable{for `hkpConvexShape};
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexListShape::`vftable{for `hkpShapeContainer};
  if ( this->m_childShapes.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_childShapes.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_childShapes.m_size );
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
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpConvexShape::hkpSphereRepShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 65
// RVA: 0xD0D8B0
void __fastcall hkpConvexListShape::getSupportingVertex(
        hkpConvexListShape *this,
        hkVector4f *dir,
        hkcdVertex *supportingVertexOut)
{
  int v3; // ebx
  __m128i v4; // xmm7
  __m128 v8; // xmm8
  __m128i v9; // xmm6
  __int64 v10; // r14
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128i v13; // xmm3
  __m128 v14; // [rsp+20h] [rbp-68h] BYREF

  v3 = 0;
  v4 = 0i64;
  v8 = (__m128)xmmword_141A712F0;
  v9 = 0i64;
  if ( this->m_childShapes.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, __m128 *))this->m_childShapes.m_data[v10]->vfptr[4].__vecDelDtor)(
        this->m_childShapes.m_data[v10],
        dir,
        &v14);
      ++v3;
      ++v10;
      v11 = _mm_mul_ps(dir->m_quad, v14);
      v12 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170));
      v13 = (__m128i)_mm_cmplt_ps(v8, v12);
      v8 = _mm_or_ps(_mm_and_ps((__m128)v13, v12), _mm_andnot_ps((__m128)v13, v8));
      supportingVertexOut->m_quad = _mm_or_ps(
                                      _mm_andnot_ps((__m128)v13, supportingVertexOut->m_quad),
                                      _mm_and_ps(v14, (__m128)v13));
      v9 = _mm_or_si128(_mm_andnot_si128(v13, v9), _mm_and_si128(v13, v4));
      v4 = _mm_add_epi32((__m128i)xmmword_141A72090, v4);
    }
    while ( v3 < this->m_childShapes.m_size );
  }
  supportingVertexOut->m_quad.m128_i32[3] = ((v9.m128i_i32[0] << 8) + supportingVertexOut->m_quad.m128_u16[6]) | 0x3F000000;
}

// File Line: 108
// RVA: 0xD0DA00
void __fastcall hkpConvexListShape::convertVertexIdsToVertices(
        hkpConvexListShape *this,
        const unsigned __int16 *ids,
        unsigned int numIds,
        hkcdVertex *verticesOut)
{
  unsigned __int16 *v6; // rdi
  __int64 v7; // rbp
  unsigned int v8; // ebx
  hkpConvexShape *v9; // rcx
  int v10; // eax
  __int16 v11; // [rsp+50h] [rbp+18h] BYREF

  if ( (int)numIds > 0 )
  {
    v6 = &verticesOut->m_quad.m128_u16[6];
    v7 = numIds;
    do
    {
      v8 = *ids;
      v11 = (unsigned __int8)*ids;
      v8 >>= 8;
      v9 = this->m_childShapes.m_data[v8];
      ((void (__fastcall *)(hkpConvexShape *, __int16 *, __int64, unsigned __int16 *))v9->vfptr[4].__first_virtual_table_function__)(
        v9,
        &v11,
        1i64,
        v6 - 6);
      v10 = *v6;
      v6 += 8;
      ++ids;
      *((_DWORD *)v6 - 4) = (v10 + (v8 << 8)) | 0x3F000000;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 131
// RVA: 0xD0DAB0
void __fastcall hkpConvexListShape::getFirstVertex(hkpConvexListShape *this, hkVector4f *v)
{
  (*(void (__fastcall **)(hkpConvexShape *, hkVector4f *))(**(_QWORD **)this->m_childShapes.m_data + 136i64))(
    *this->m_childShapes.m_data,
    v);
}

// File Line: 138
// RVA: 0xD0DAD0
__int64 __fastcall hkpConvexListShape::getNumCollisionSpheres(hkpConvexListShape *this)
{
  unsigned int v1; // ebx
  int v3; // edi
  __int64 v4; // rsi
  int v5; // eax

  v1 = 0;
  v3 = 0;
  if ( this->m_childShapes.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = ((__int64 (__fastcall *)(hkpConvexShape *))this->m_childShapes.m_data[v4]->vfptr[5].__first_virtual_table_function__)(this->m_childShapes.m_data[v4]);
      ++v3;
      ++v4;
      v1 += v5;
    }
    while ( v3 < this->m_childShapes.m_size );
  }
  return v1;
}

// File Line: 150
// RVA: 0xD0DB30
hkSphere *__fastcall hkpConvexListShape::getCollisionSpheres(hkpConvexListShape *this, hkSphere *sphereBuffer)
{
  int v2; // edi
  hkSphere *v5; // rbp
  __int64 v6; // rsi
  hkpConvexShape *v7; // rbx

  v2 = 0;
  v5 = sphereBuffer;
  if ( this->m_childShapes.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = this->m_childShapes.m_data[v6];
      v7->vfptr[6].__vecDelDtor(v7, (unsigned int)v5);
      ++v2;
      ++v6;
      v5 += ((int (__fastcall *)(hkpConvexShape *))v7->vfptr[5].__first_virtual_table_function__)(v7);
    }
    while ( v2 < this->m_childShapes.m_size );
  }
  return sphereBuffer;
}

// File Line: 166
// RVA: 0xD0E070
void __fastcall hkpConvexListShape::setShapesAndRadius(
        hkpConvexListShape *this,
        hkReferencedObject **shapeArray,
        int numShapes)
{
  hkArray<hkpConvexShape const *,hkContainerHeapAllocator> *p_m_childShapes; // r14
  __int64 v4; // rdi
  int v5; // eax
  int v8; // eax
  int v9; // r9d
  __int64 v10; // rsi
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  p_m_childShapes = &this->m_childShapes;
  v4 = numShapes;
  v5 = this->m_childShapes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < numShapes )
  {
    v8 = 2 * v5;
    v9 = numShapes;
    if ( numShapes < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_childShapes->m_data, v9, 8);
  }
  p_m_childShapes->m_size = v4;
  this->m_radius = *(float *)&(*shapeArray)[2].vfptr;
  if ( v4 > 0 )
  {
    v10 = -(__int64)shapeArray;
    do
    {
      *(hkReferencedObject **)((char *)shapeArray + v10 + (unsigned __int64)p_m_childShapes->m_data) = *shapeArray;
      hkReferencedObject::addReference(*shapeArray++);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 184
// RVA: 0xD0D7E0
void __fastcall hkpConvexListShape::setUseCachedAabb(hkpConvexListShape *this, char useCachedAabb, __int64 a3)
{
  __m128 v4; // xmm6
  int v5; // edi
  __m128 v6; // xmm7
  __int64 v7; // rsi
  __m128 v8[2]; // [rsp+20h] [rbp-48h] BYREF

  this->m_useCachedAabb.m_bool = useCachedAabb;
  if ( useCachedAabb )
  {
    v4 = (__m128)xmmword_141A712F0;
    v5 = 0;
    v6 = (__m128)xmmword_141A712A0;
    if ( this->m_childShapes.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, __int64, __m128 *))this->m_childShapes.m_data[v7]->vfptr[2].__vecDelDtor)(
          this->m_childShapes.m_data[v7],
          &transform,
          a3,
          v8);
        v6 = _mm_min_ps(v6, v8[0]);
        v4 = _mm_max_ps(v4, v8[1]);
        ++v5;
        ++v7;
      }
      while ( v5 < this->m_childShapes.m_size );
    }
    this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v6, v4), (__m128)xmmword_141A711B0);
    this->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v4, v6), (__m128)xmmword_141A711B0);
  }
}

// File Line: 207
// RVA: 0xD0D8A0
_BOOL8 __fastcall hkpConvexListShape::getUseCachedAabb(hkpConvexListShape *this)
{
  return this->m_useCachedAabb.m_bool != 0;
}

// File Line: 212
// RVA: 0xD0DC30
void __fastcall hkpConvexListShape::getAabb(
        hkpConvexListShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkVector4f v7; // xmm1
  __m128 v8; // xmm6
  hkVector4f v9; // xmm1
  __m128 v10; // xmm2
  __int64 v11; // r8
  int v12; // esi
  __int64 v13; // rdi
  hkVector4f v14; // xmm1
  __m128 v15[2]; // [rsp+20h] [rbp-48h] BYREF

  if ( this->m_useCachedAabb.m_bool )
  {
    v7.m_quad = (__m128)this->m_aabbHalfExtents;
    v8 = _mm_add_ps(
           _mm_add_ps(
             (__m128)_mm_srli_epi32(
                       _mm_slli_epi32(
                         (__m128i)_mm_mul_ps(
                                    _mm_shuffle_ps(v7.m_quad, v7.m_quad, 0),
                                    localToWorld->m_rotation.m_col0.m_quad),
                         1u),
                       1u),
             (__m128)_mm_srli_epi32(
                       _mm_slli_epi32(
                         (__m128i)_mm_mul_ps(
                                    _mm_shuffle_ps(v7.m_quad, v7.m_quad, 85),
                                    localToWorld->m_rotation.m_col1.m_quad),
                         1u),
                       1u)),
           _mm_add_ps(
             (__m128)_mm_srli_epi32(
                       _mm_slli_epi32(
                         (__m128i)_mm_mul_ps(
                                    _mm_shuffle_ps(v7.m_quad, v7.m_quad, 170),
                                    localToWorld->m_rotation.m_col2.m_quad),
                         1u),
                       1u),
             _mm_shuffle_ps(
               (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
               (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
               0)));
    v9.m_quad = (__m128)this->m_aabbCenter;
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 0), localToWorld->m_rotation.m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 85), localToWorld->m_rotation.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 170), localToWorld->m_rotation.m_col2.m_quad)),
            localToWorld->m_translation.m_quad);
    out->m_max.m_quad = _mm_add_ps(v10, v8);
    out->m_min.m_quad = _mm_add_ps(
                          _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v8),
                          v10);
  }
  else
  {
    (*(void (__fastcall **)(hkpConvexShape *))(**(_QWORD **)this->m_childShapes.m_data + 32i64))(*this->m_childShapes.m_data);
    v12 = 1;
    if ( this->m_childShapes.m_size > 1 )
    {
      v13 = 1i64;
      do
      {
        ((void (__fastcall *)(hkpConvexShape *, hkTransformf *, __int64, __m128 *))this->m_childShapes.m_data[v13]->vfptr[2].__vecDelDtor)(
          this->m_childShapes.m_data[v13],
          localToWorld,
          v11,
          v15);
        ++v12;
        ++v13;
        v14.m_quad = _mm_max_ps(out->m_max.m_quad, v15[1]);
        out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v15[0]);
        out->m_max = (hkVector4f)v14.m_quad;
      }
      while ( v12 < this->m_childShapes.m_size );
    }
  }
}

// File Line: 233
// RVA: 0xD0DBC0
__int64 __fastcall hkpConvexListShape::getNumChildShapes(hkpConvexListShape *this)
{
  return this->m_aabbHalfExtents.m_quad.m128_u32[2];
}

// File Line: 239
// RVA: 0xD0DBD0
__int64 __fastcall hkpConvexListShape::getFirstKey(hkpConvexListShape *this)
{
  return 0i64;
}

// File Line: 244
// RVA: 0xD0DBE0
__int64 __fastcall hkpConvexListShape::getNextKey(hkpConvexListShape *this, unsigned int oldKey)
{
  int v2; // edx
  __int64 result; // rax

  v2 = oldKey + 1;
  result = 0xFFFFFFFFi64;
  if ( v2 < this->m_aabbHalfExtents.m_quad.m128_i32[2] )
    return (unsigned int)v2;
  return result;
}

// File Line: 257
// RVA: 0xD0DC10
hkpShape *__fastcall hkpConvexListShape::getChildShape(hkpConvexListShape *this, int key, char (*buffer)[512])
{
  return *(hkpShape **)(this->m_aabbHalfExtents.m_quad.m128_u64[0] + 8i64 * key);
}

// File Line: 263
// RVA: 0xD0DC00
__int64 __fastcall hkpConvexListShape::getCollisionFilterInfo(hkpConvexListShape *this, unsigned int key)
{
  return 0i64;
}

// File Line: 273
// RVA: 0xD0DDA0
hkBool *__fastcall hkpConvexListShape::castRay(
        hkpConvexListShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // rdx
  __int64 v10; // r8
  _QWORD *v11; // rcx
  _QWORD *v12; // r9
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  hkpShapeContainerVtbl *vfptr; // rax
  hkpShapeContainer *v16; // rsi
  unsigned int v17; // edi
  unsigned int i; // ebp
  __int64 v19; // rax
  unsigned int m_slotID; // ecx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  char v27[512]; // [rsp+20h] [rbp-218h] BYREF
  char v28; // [rsp+240h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtrcCxList";
    v13 = __rdtsc();
    v9 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  ++results->m_shapeKeyIndex;
  vfptr = this->hkpShapeContainer::vfptr;
  v16 = &this->hkpShapeContainer;
  v17 = -1;
  for ( i = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, __int64, _QWORD *))vfptr->getFirstKey)(
              v16,
              v9,
              v10,
              v12); i != -1; i = v16->vfptr->getNextKey(v16, i) )
  {
    v19 = (__int64)v16->vfptr->getChildShape(v16, i, (char (*)[512])v27);
    if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v19 + 40i64))(
                     v19,
                     &v28,
                     input,
                     results) )
      v17 = i;
  }
  --results->m_shapeKeyIndex;
  if ( v17 != -1 )
    results->m_shapeKeys[results->m_shapeKeyIndex] = v17;
  m_slotID = hkMonitorStream__m_instance.m_slotID;
  result->m_bool = v17 != -1;
  v21 = TlsGetValue(m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = v22 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v23[1] = v25;
  }
  return result;
}

// File Line: 302
// RVA: 0xD0DEE0
void __fastcall hkpConvexListShape::castRayWithCollector(
        hkpConvexListShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpShapeContainerVtbl *vfptr; // rax
  hkpShapeContainer *v14; // rbx
  unsigned int i; // edi
  __int64 v16; // rax
  const void *m_motion; // rcx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  __int64 v22; // [rsp+20h] [rbp-228h] BYREF
  unsigned int v23; // [rsp+28h] [rbp-220h]
  const void *v24; // [rsp+30h] [rbp-218h]
  hkpCdBody *v25; // [rsp+38h] [rbp-210h]
  char v26[512]; // [rsp+40h] [rbp-208h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcShpCollect";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  vfptr = this->hkpShapeContainer::vfptr;
  v14 = &this->hkpShapeContainer;
  for ( i = vfptr->getFirstKey(v14); i != -1; i = v14->vfptr->getNextKey(v14, i) )
  {
    v16 = (__int64)v14->vfptr->getChildShape(v14, i, (char (*)[512])v26);
    m_motion = cdBody->m_motion;
    v25 = cdBody;
    v24 = m_motion;
    v22 = v16;
    v23 = i;
    (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v16 + 48i64))(
      v16,
      input,
      &v22,
      collector);
  }
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
}

// File Line: 320
// RVA: 0xD0E050
hkpShapeContainer *__fastcall hkpConvexListShape::getContainer(hkpConvexListShape *this)
{
  if ( this )
    return &this->hkpShapeContainer;
  else
    return 0i64;
}

