// File Line: 44
// RVA: 0xCEF8D0
void __fastcall hkpListShape::hkpListShape(
        hkpListShape *this,
        hkpShape *const *shapeArray,
        int numShapes,
        hkpShapeContainer::ReferencePolicy ref)
{
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  hkpShapeCollection::hkpShapeCollection(this, LIST, COLLECTION_LIST);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpListShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpListShape::`vftable{for `hkpShapeContainer};
  this->m_childInfo.m_data = 0i64;
  this->m_childInfo.m_size = 0;
  this->m_childInfo.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_childInfo.m_data, 4, 32);
  hkpListShape::setShapes(this, shapeArray, numShapes, 0i64, ref);
  *(_QWORD *)this->m_enabledChildren = -1i64;
  *(_QWORD *)&this->m_enabledChildren[2] = -1i64;
  *(_QWORD *)&this->m_enabledChildren[4] = -1i64;
  *(_QWORD *)&this->m_enabledChildren[6] = -1i64;
  *(_DWORD *)&this->m_flags = 0;
}

// File Line: 61
// RVA: 0xCEF9A0
void __fastcall hkpListShape::hkpListShape(hkpListShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShapeCollection::hkpShapeCollection(this, flag);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpListShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpListShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 8;
    this->m_collectionType.m_storage = 0;
  }
}

// File Line: 73
// RVA: 0xCEF9F0
void __fastcall hkpListShape::~hkpListShape(hkpListShape *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpListShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpListShape::`vftable{for `hkpShapeContainer};
  if ( this->m_childInfo.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_childInfo.m_data[v3].m_shape);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_childInfo.m_size );
  }
  m_capacityAndFlags = this->m_childInfo.m_capacityAndFlags;
  this->m_childInfo.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_childInfo.m_data,
      32 * m_capacityAndFlags);
  this->m_childInfo.m_data = 0i64;
  this->m_childInfo.m_capacityAndFlags = 0x80000000;
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 81
// RVA: 0xCF03B0
void __fastcall hkpListShape::setShapes(
        hkpListShape *this,
        hkpShape **shapeArray,
        int numShapes,
        unsigned int *filterInfo,
        hkpShapeContainer::ReferencePolicy ref)
{
  __int64 v6; // rsi
  int v7; // eax
  int v10; // eax
  int v11; // r9d
  unsigned int *v12; // r8
  __int64 v13; // r9
  __int64 v14; // rcx
  unsigned int v15; // edx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  v6 = (unsigned int)numShapes;
  v7 = this->m_childInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < numShapes )
  {
    v10 = 2 * v7;
    v11 = numShapes;
    if ( numShapes < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_childInfo.m_data,
      v11,
      32);
  }
  this->m_childInfo.m_size = v6;
  if ( (int)v6 > 0 )
  {
    v12 = filterInfo;
    v13 = v6;
    v14 = 0i64;
    do
    {
      if ( *shapeArray )
      {
        this->m_childInfo.m_data[v14].m_shape = *shapeArray;
        if ( filterInfo )
          v15 = *v12;
        else
          v15 = 0;
        this->m_childInfo.m_data[v14].m_collisionFilterInfo = v15;
        this->m_childInfo.m_data[v14].m_numChildShapes = v6;
        this->m_childInfo.m_data[v14].m_shapeSize = 0;
        this->m_childInfo.m_data[v14].m_shapeInfo = 0;
      }
      ++shapeArray;
      ++v12;
      ++v14;
      --v13;
    }
    while ( v13 );
  }
  if ( ref == REFERENCE_POLICY_INCREMENT )
    hkReferencedObject::addReferences(&this->m_childInfo.m_data->m_shape, this->m_childInfo.m_size, 32);
  hkpListShape::recalcAabbExtents(this);
}

// File Line: 108
// RVA: 0xCF0140
void __fastcall hkpListShape::disableChild(hkpListShape *this, unsigned int index)
{
  char *v2; // r10
  int v3; // r8d

  v2 = (char *)this + 4 * (index >> 5);
  v3 = *((_DWORD *)v2 + 28) & ~(1 << (index & 0x1F));
  if ( *((_DWORD *)v2 + 28) != v3 )
  {
    *((_DWORD *)v2 + 28) = v3;
    ++this->m_numDisabledChildren;
  }
}

// File Line: 123
// RVA: 0xCF0180
void __fastcall hkpListShape::enableChild(hkpListShape *this, unsigned int index)
{
  char *v2; // r10
  int v3; // r8d

  v2 = (char *)this + 4 * (index >> 5);
  v3 = *((_DWORD *)v2 + 28) | (1 << (index & 0x1F));
  if ( *((_DWORD *)v2 + 28) != v3 )
  {
    *((_DWORD *)v2 + 28) = v3;
    --this->m_numDisabledChildren;
  }
}

// File Line: 138
// RVA: 0xCF01C0
void __fastcall hkpListShape::setEnabledChildren(hkpListShape *this, hkBitField *enabledChildren)
{
  unsigned int *m_data; // rax
  int v3; // r10d
  int v5; // r9d
  char *v6; // r8
  unsigned int v7; // ecx
  int v8; // r8d
  int v9; // eax
  __int64 v10; // rcx
  __m128i si128; // xmm2
  __m128i v12; // xmm3
  __m128i v13; // xmm4
  unsigned int v14; // eax
  __m128i v15; // xmm1
  __m128i v16; // xmm0
  __m128i v17; // xmm0
  __m128i v18; // xmm1

  m_data = enabledChildren->m_storage.m_words.m_data;
  v3 = 0;
  v5 = 0;
  if ( enabledChildren->m_storage.m_words.m_size > 0 )
  {
    v6 = (char *)((char *)this - (char *)m_data);
    do
    {
      v7 = *m_data;
      ++v5;
      *(unsigned int *)((char *)++m_data + (_QWORD)v6 + 108) = v7;
    }
    while ( v5 < enabledChildren->m_storage.m_words.m_size );
  }
  v8 = (2 * ~(-1 << ((enabledChildren->m_storage.m_numBits - 1) & 0x1F))) | 1;
  v9 = enabledChildren->m_storage.m_words.m_size - 1;
  v10 = v9;
  if ( v9 >= 0 )
  {
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v12 = _mm_load_si128((const __m128i *)&_xmm);
    v13 = _mm_load_si128((const __m128i *)&_xmm);
    do
    {
      v14 = v8 & enabledChildren->m_storage.m_words.m_data[v10];
      v8 = -1;
      v15 = _mm_cvtsi32_si128(v14);
      v16 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v15, 1u), si128), _mm_and_si128(v15, si128));
      v17 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v16, 2u), v12), _mm_and_si128(v16, v12));
      v18 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v17, 4u), v17), v13), (__m128i)0i64);
      v3 += _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v18, 78), v18));
      --v10;
    }
    while ( v10 >= 0 );
  }
  this->m_numDisabledChildren = this->m_childInfo.m_size - v3;
}

// File Line: 153
// RVA: 0xCEFBE0
hkBool *__fastcall hkpListShape::castRay(
        hkpListShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm6
  unsigned int v14; // ebx
  unsigned int v15; // r14d
  int v16; // edi
  __int64 v17; // r15
  hkpShape *v18; // rcx
  __int64 v19; // r15
  hkpShape *m_shape; // rcx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  __int128 v27; // [rsp+40h] [rbp-88h]
  __int128 v28; // [rsp+50h] [rbp-78h]
  __int128 v29; // [rsp+60h] [rbp-68h]
  __int128 v30; // [rsp+70h] [rbp-58h]
  char v31; // [rsp+D8h] [rbp+10h] BYREF
  char v32; // [rsp+E0h] [rbp+18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcList";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)results->m_normal;
  v14 = 0;
  v15 = -1;
  v16 = 1;
  v27 = *(_OWORD *)&results->m_hitFraction;
  v28 = *(_OWORD *)results->m_shapeKeys;
  v29 = *(_OWORD *)&results->m_shapeKeys[4];
  v30 = *(_OWORD *)&results->m_shapeKeyIndex;
  if ( input->m_rayShapeCollectionFilter )
  {
    if ( this->m_childInfo.m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        if ( (v14 >= 0x100 || (v16 & this->m_enabledChildren[(unsigned __int64)v14 >> 5]) != 0)
          && *(_BYTE *)input->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                         input->m_rayShapeCollectionFilter,
                         (hkBool *)&v31,
                         input,
                         &this->hkpShapeContainer,
                         v14) )
        {
          m_shape = this->m_childInfo.m_data[v19].m_shape;
          results->m_shapeKeys[results->m_shapeKeyIndex++] = v14;
          if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))m_shape->vfptr[2].__first_virtual_table_function__)(
                           m_shape,
                           &v32,
                           input,
                           results) )
            v15 = v14;
          --results->m_shapeKeyIndex;
        }
        v16 = __ROL4__(v16, 1);
        ++v14;
        ++v19;
      }
      while ( (signed int)v14 < this->m_childInfo.m_size );
    }
  }
  else if ( this->m_childInfo.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      if ( v14 >= 0x100 || (v16 & this->m_enabledChildren[(unsigned __int64)v14 >> 5]) != 0 )
      {
        v18 = this->m_childInfo.m_data[v17].m_shape;
        results->m_shapeKeys[results->m_shapeKeyIndex++] = v14;
        if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v18->vfptr[2].__first_virtual_table_function__)(
                         v18,
                         &v31,
                         input,
                         results) )
          v15 = v14;
        --results->m_shapeKeyIndex;
      }
      v16 = __ROL4__(v16, 1);
      ++v14;
      ++v17;
    }
    while ( (signed int)v14 < this->m_childInfo.m_size );
  }
  results->m_shapeKeys[results->m_shapeKeyIndex] = v15;
  if ( v15 == -1 )
  {
    results->m_normal = (hkVector4f)v13.m_quad;
    *(_OWORD *)&results->m_hitFraction = v27;
    *(_OWORD *)results->m_shapeKeys = v28;
    *(_OWORD *)&results->m_shapeKeys[4] = v29;
    results->m_shapeKeyIndex = v30;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
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
  result->m_bool = v15 != -1;
  return result;
}

// File Line: 221
// RVA: 0xCEFE80
void __fastcall hkpListShape::castRayWithCollector(
        hkpListShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  unsigned int v12; // ebx
  int v13; // edi
  __int64 v14; // r14
  hkpShape *v15; // rcx
  const void *v16; // rax
  __int64 v17; // r14
  hkpShape *m_shape; // rcx
  const void *m_motion; // rax
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  hkpShape *v25; // [rsp+30h] [rbp-48h] BYREF
  unsigned int v26; // [rsp+38h] [rbp-40h]
  const void *v27; // [rsp+40h] [rbp-38h]
  hkpCdBody *v28; // [rsp+48h] [rbp-30h]
  char v29; // [rsp+88h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcList";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  v12 = 0;
  v13 = 1;
  if ( input->m_rayShapeCollectionFilter )
  {
    if ( this->m_childInfo.m_size > 0 )
    {
      v17 = 0i64;
      do
      {
        if ( (v12 >= 0x100 || (v13 & this->m_enabledChildren[(unsigned __int64)v12 >> 5]) != 0)
          && *(_BYTE *)input->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                         input->m_rayShapeCollectionFilter,
                         (hkBool *)&v29,
                         input,
                         &this->hkpShapeContainer,
                         v12) )
        {
          m_shape = this->m_childInfo.m_data[v17].m_shape;
          m_motion = cdBody->m_motion;
          v28 = cdBody;
          v27 = m_motion;
          v25 = m_shape;
          v26 = v12;
          ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpShape **, hkpRayHitCollector *))m_shape->vfptr[3].__vecDelDtor)(
            m_shape,
            input,
            &v25,
            collector);
        }
        v13 = __ROL4__(v13, 1);
        ++v12;
        ++v17;
      }
      while ( (signed int)v12 < this->m_childInfo.m_size );
    }
  }
  else if ( this->m_childInfo.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      if ( v12 >= 0x100 || (v13 & this->m_enabledChildren[(unsigned __int64)v12 >> 5]) != 0 )
      {
        v15 = this->m_childInfo.m_data[v14].m_shape;
        v16 = cdBody->m_motion;
        v28 = cdBody;
        v27 = v16;
        v25 = v15;
        v26 = v12;
        ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpShape **, hkpRayHitCollector *))v15->vfptr[3].__vecDelDtor)(
          v15,
          input,
          &v25,
          collector);
      }
      v13 = __ROL4__(v13, 1);
      ++v12;
      ++v14;
    }
    while ( (signed int)v12 < this->m_childInfo.m_size );
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
}

// File Line: 271
// RVA: 0xCEFAF0
void __fastcall hkpListShape::getAabb(hkpListShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  __int64 v4; // r8
  int v8; // esi
  hkVector4f v9; // xmm1
  __int64 v10; // r14
  hkVector4f v11; // xmm1
  __m128 v12[2]; // [rsp+20h] [rbp-38h] BYREF

  if ( _mm_movemask_ps(_mm_cmple_ps(this->m_aabbHalfExtents.m_quad, (__m128)0i64)) == 15 )
    hkpListShape::recalcAabbExtents(this);
  v8 = 0;
  v9.m_quad = _mm_mul_ps((__m128)xmmword_141A712A0, (__m128)xmmword_141A711B0);
  out->m_min = (hkVector4f)v9.m_quad;
  out->m_max.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9.m_quad);
  if ( this->m_childInfo.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))this->m_childInfo.m_data[v10].m_shape->vfptr[2].__vecDelDtor)(
        this->m_childInfo.m_data[v10].m_shape,
        localToWorld,
        v4,
        v12);
      ++v8;
      ++v10;
      v11.m_quad = _mm_max_ps(out->m_max.m_quad, v12[1]);
      out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v12[0]);
      out->m_max = (hkVector4f)v11.m_quad;
    }
    while ( v8 < this->m_childInfo.m_size );
  }
}

// File Line: 650
// RVA: 0xCF0050
void __fastcall hkpListShape::recalcAabbExtents(hkpListShape *this)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  hkpListShape::recalcAabbExtents(this, &aabb);
}

// File Line: 656
// RVA: 0xCF0070
void __fastcall hkpListShape::recalcAabbExtents(hkpListShape *this, hkAabb *aabb, __int64 a3)
{
  __int64 v5; // r8
  int v6; // ebp
  __int64 v7; // rsi
  hkVector4f v8; // xmm1
  __m128 v9[2]; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, hkAabb *))this->m_childInfo.m_data->m_shape->vfptr[2].__vecDelDtor)(
    this->m_childInfo.m_data->m_shape,
    &transform,
    a3,
    aabb);
  v6 = 1;
  if ( this->m_childInfo.m_size > 1 )
  {
    v7 = 1i64;
    do
    {
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))this->m_childInfo.m_data[v7].m_shape->vfptr[2].__vecDelDtor)(
        this->m_childInfo.m_data[v7].m_shape,
        &transform,
        v5,
        v9);
      ++v6;
      ++v7;
      v8.m_quad = _mm_max_ps(aabb->m_max.m_quad, v9[1]);
      aabb->m_min.m_quad = _mm_min_ps(aabb->m_min.m_quad, v9[0]);
      aabb->m_max = (hkVector4f)v8.m_quad;
    }
    while ( v6 < this->m_childInfo.m_size );
  }
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(aabb->m_max.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(
                                     _mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad),
                                     (__m128)xmmword_141A711B0);
}

// File Line: 678
// RVA: 0xCEFAB0
hkpShape *__fastcall hkpListShape::getChildShape(hkpListShape *this, int key, char (*buffer)[512])
{
  return *(hkpShape **)(32i64 * key + *(_QWORD *)&this->m_type.m_storage);
}

// File Line: 720
// RVA: 0xCEFAD0
__int64 __fastcall hkpListShape::getCollisionFilterInfo(hkpListShape *this, int key)
{
  return *(unsigned int *)(32i64 * key + *(_QWORD *)&this->m_type.m_storage + 8);
}

// File Line: 744
// RVA: 0xCF02C0
void __fastcall hkpListShape::setCollisionFilterInfo(hkpListShape *this, unsigned int index, unsigned int filterInfo)
{
  this->m_childInfo.m_data[index].m_collisionFilterInfo = filterInfo;
}

// File Line: 749
// RVA: 0xCF02E0
__int64 __fastcall hkpListShape::calcSizeForSpu(
        hkpListShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int m_size; // eax
  int v7; // ebx
  __int64 i; // rsi
  hkpListShape::ChildInfo *m_data; // rdi

  if ( input->m_midphaseAgent3Registered && !input->m_isFixedOrKeyframed && this->m_childInfo.m_size > 252 )
    return 0xFFFFFFFFi64;
  m_size = this->m_childInfo.m_size;
  if ( m_size >= 2047 )
    return 0xFFFFFFFFi64;
  v7 = 0;
  if ( m_size <= 0 )
    return 144i64;
  for ( i = 0i64; ; ++i )
  {
    m_data = this->m_childInfo.m_data;
    m_data[i].m_shapeSize = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, __int64))m_data[i].m_shape->vfptr[8].__vecDelDtor)(
                              m_data[i].m_shape,
                              input,
                              256i64);
    this->m_childInfo.m_data[i].m_numChildShapes = this->m_childInfo.m_size;
    if ( this->m_childInfo.m_data[i].m_shapeSize == -1 )
      break;
    if ( ++v7 >= this->m_childInfo.m_size )
      return 144i64;
  }
  return 0xFFFFFFFFi64;
}

