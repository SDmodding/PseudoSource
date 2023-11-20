// File Line: 44
// RVA: 0xCEF8D0
void __fastcall hkpListShape::hkpListShape(hkpListShape *this, hkpShape *const *shapeArray, int numShapes, hkpShapeContainer::ReferencePolicy ref)
{
  int v4; // edi
  hkpShape *const *v5; // rsi
  hkpShapeContainer::ReferencePolicy v6; // ebx
  hkpListShape *v7; // r14
  signed __int64 v8; // r8
  hkResult result; // [rsp+50h] [rbp+8h]

  v4 = numShapes;
  v5 = shapeArray;
  v6 = ref;
  v7 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, LIST, 0);
  v8 = (signed __int64)&v7->m_childInfo;
  v7->vfptr = (hkBaseObjectVtbl *)&hkpListShape::`vftable{for `hkpShape};
  v7->vfptr = (hkpShapeContainerVtbl *)&hkpListShape::`vftable{for `hkpShapeContainer};
  *(_QWORD *)v8 = 0i64;
  *(_DWORD *)(v8 + 8) = 0;
  *(_DWORD *)(v8 + 12) = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_childInfo, 4, 32);
  hkpListShape::setShapes(v7, v5, v4, 0i64, v6);
  *(_QWORD *)v7->m_enabledChildren = -1i64;
  *(_QWORD *)&v7->m_enabledChildren[2] = -1i64;
  *(_QWORD *)&v7->m_enabledChildren[4] = -1i64;
  *(_QWORD *)&v7->m_enabledChildren[6] = -1i64;
  *(_DWORD *)&v7->m_flags = 0;
}

// File Line: 61
// RVA: 0xCEF9A0
void __fastcall hkpListShape::hkpListShape(hkpListShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpListShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpListShape::`vftable{for `hkpShape};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpListShape::`vftable{for `hkpShapeContainer};
  if ( v3 )
  {
    v2->m_type.m_storage = 8;
    v2->m_collectionType.m_storage = 0;
  }
}

// File Line: 73
// RVA: 0xCEF9F0
void __fastcall hkpListShape::~hkpListShape(hkpListShape *this)
{
  int v1; // esi
  hkpListShape *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpListShape::`vftable{for `hkpShape};
  v2 = this;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpListShape::`vftable{for `hkpShapeContainer};
  if ( this->m_childInfo.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_childInfo.m_data[v3].m_shape->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_childInfo.m_size );
  }
  v4 = v2->m_childInfo.m_capacityAndFlags;
  v2->m_childInfo.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_childInfo.m_data,
      32 * v4);
  v2->m_childInfo.m_data = 0i64;
  v2->m_childInfo.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 81
// RVA: 0xCF03B0
void __fastcall hkpListShape::setShapes(hkpListShape *this, hkpShape *const *shapeArray, int numShapes, const unsigned int *filterInfo, hkpShapeContainer::ReferencePolicy ref)
{
  const unsigned int *v5; // rbp
  __int64 v6; // rsi
  int v7; // eax
  hkpShape *const *v8; // rdi
  hkpListShape *v9; // r14
  int v10; // eax
  int v11; // er9
  const unsigned int *v12; // r8
  __int64 v13; // r9
  __int64 v14; // rcx
  unsigned int v15; // edx
  hkResult result; // [rsp+60h] [rbp+18h]

  v5 = filterInfo;
  v6 = (unsigned int)numShapes;
  v7 = this->m_childInfo.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = shapeArray;
  v9 = this;
  if ( v7 < numShapes )
  {
    v10 = 2 * v7;
    v11 = numShapes;
    if ( numShapes < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_childInfo,
      v11,
      32);
  }
  v9->m_childInfo.m_size = v6;
  if ( (signed int)v6 > 0 )
  {
    v12 = v5;
    v13 = v6;
    v14 = 0i64;
    do
    {
      if ( *v8 )
      {
        v9->m_childInfo.m_data[v14].m_shape = *v8;
        if ( v5 )
          v15 = *v12;
        else
          v15 = 0;
        v9->m_childInfo.m_data[v14].m_collisionFilterInfo = v15;
        v9->m_childInfo.m_data[v14].m_numChildShapes = v6;
        v9->m_childInfo.m_data[v14].m_shapeSize = 0;
        v9->m_childInfo.m_data[v14].m_shapeInfo = 0;
      }
      ++v8;
      ++v12;
      ++v14;
      --v13;
    }
    while ( v13 );
  }
  if ( ref == 1 )
    hkReferencedObject::addReferences((hkReferencedObject *const *)v9->m_childInfo.m_data, v9->m_childInfo.m_size, 32);
  hkpListShape::recalcAabbExtents(v9);
}

// File Line: 108
// RVA: 0xCF0140
void __fastcall hkpListShape::disableChild(hkpListShape *this, unsigned int index)
{
  char *v2; // r10
  int v3; // er8

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
  int v3; // er8

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
  unsigned int *v2; // rax
  int v3; // er10
  hkpListShape *v4; // r11
  int v5; // er9
  char *v6; // r8
  unsigned int v7; // ecx
  int v8; // er9
  int v9; // er8
  int v10; // eax
  __int64 v11; // rcx
  __m128i v12; // xmm2
  __m128i v13; // xmm3
  __m128i v14; // xmm4
  unsigned int v15; // eax
  __m128i v16; // xmm0
  __m128i v17; // xmm1
  __m128i v18; // xmm0
  __m128i v19; // xmm1

  v2 = enabledChildren->m_storage.m_words.m_data;
  v3 = 0;
  v4 = this;
  v5 = 0;
  if ( enabledChildren->m_storage.m_words.m_size > 0 )
  {
    v6 = (char *)((char *)this - (char *)v2);
    do
    {
      v7 = *v2;
      ++v5;
      ++v2;
      *(unsigned int *)((char *)v2 + (_QWORD)v6 + 108) = v7;
    }
    while ( v5 < enabledChildren->m_storage.m_words.m_size );
  }
  v8 = v4->m_childInfo.m_size;
  v9 = 2 * ~(-1 << ((enabledChildren->m_storage.m_numBits - 1) & 0x1F)) | 1;
  v10 = enabledChildren->m_storage.m_words.m_size - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = _mm_load_si128((const __m128i *)&_xmm);
    v13 = _mm_load_si128((const __m128i *)&_xmm);
    v14 = _mm_load_si128((const __m128i *)&_xmm);
    do
    {
      v15 = v9 & enabledChildren->m_storage.m_words.m_data[v11];
      v9 = -1;
      v16 = _mm_cvtsi32_si128(v15);
      v17 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v16, 1u), v12), _mm_and_si128(v16, v12));
      v18 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v17, 2u), v13), _mm_and_si128(v17, v13));
      v19 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v18, 4u), v18), v14), (__m128i)0i64);
      v3 += _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v19, 78), v19));
      --v11;
    }
    while ( v11 >= 0 );
  }
  v4->m_numDisabledChildren = v8 - v3;
}

// File Line: 153
// RVA: 0xCEFBE0
hkBool *__fastcall hkpListShape::castRay(hkpListShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpListShape *v4; // rbp
  hkpShapeRayCastOutput *v5; // rsi
  hkpShapeRayCastInput *v6; // r13
  hkBool *v7; // r12
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkVector4f v13; // xmm6
  unsigned int v14; // ebx
  signed int v15; // er14
  signed int v16; // edi
  __int64 v17; // r15
  hkpShape *v18; // rcx
  __int64 v19; // r15
  hkpShape *v20; // rcx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  _QWORD v27[4]; // [rsp+20h] [rbp-A8h]
  __int128 v28; // [rsp+40h] [rbp-88h]
  __int128 v29; // [rsp+50h] [rbp-78h]
  __int128 v30; // [rsp+60h] [rbp-68h]
  __int128 v31; // [rsp+70h] [rbp-58h]
  char v32; // [rsp+D8h] [rbp+10h]
  char v33; // [rsp+E0h] [rbp+18h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcList";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)v5->m_normal;
  v14 = 0;
  v15 = -1;
  v16 = 1;
  v28 = *(_OWORD *)&v5->m_hitFraction;
  v29 = *(_OWORD *)v5->m_shapeKeys;
  v30 = *(_OWORD *)&v5->m_shapeKeys[4];
  v31 = *(_OWORD *)&v5->m_shapeKeyIndex;
  if ( v6->m_rayShapeCollectionFilter )
  {
    if ( v4->m_childInfo.m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        if ( v14 >= 0x100 || v16 & v4->m_enabledChildren[(unsigned __int64)v14 >> 5] )
        {
          LODWORD(v27[0]) = v14;
          if ( *(_BYTE *)v6->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                           v6->m_rayShapeCollectionFilter,
                           (hkBool *)&v32,
                           v6,
                           (hkpShapeContainer *)&v4->vfptr,
                           v27[0]) )
          {
            v20 = v4->m_childInfo.m_data[v19].m_shape;
            v5->m_shapeKeys[v5->m_shapeKeyIndex++] = v14;
            if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v20->vfptr[2].__first_virtual_table_function__)(
                             v20,
                             &v33,
                             v6,
                             v5) )
              v15 = v14;
            --v5->m_shapeKeyIndex;
          }
        }
        v16 = __ROL4__(v16, 1);
        ++v14;
        ++v19;
      }
      while ( (signed int)v14 < v4->m_childInfo.m_size );
    }
  }
  else if ( v4->m_childInfo.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      if ( v14 >= 0x100 || v16 & v4->m_enabledChildren[(unsigned __int64)v14 >> 5] )
      {
        v18 = v4->m_childInfo.m_data[v17].m_shape;
        v5->m_shapeKeys[v5->m_shapeKeyIndex++] = v14;
        if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v18->vfptr[2].__first_virtual_table_function__)(
                         v18,
                         &v32,
                         v6,
                         v5) )
          v15 = v14;
        --v5->m_shapeKeyIndex;
      }
      v16 = __ROL4__(v16, 1);
      ++v14;
      ++v17;
    }
    while ( (signed int)v14 < v4->m_childInfo.m_size );
  }
  v5->m_shapeKeys[v5->m_shapeKeyIndex] = v15;
  if ( v15 == -1 )
  {
    v5->m_normal = (hkVector4f)v13.m_quad;
    *(_OWORD *)&v5->m_hitFraction = v28;
    *(_OWORD *)v5->m_shapeKeys = v29;
    *(_OWORD *)&v5->m_shapeKeys[4] = v30;
    v5->m_shapeKeyIndex = v31;
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
  v7->m_bool = v15 != -1;
  return v7;
}  v25 = (signed __int64)(v22 + 2)

// File Line: 221
// RVA: 0xCEFE80
void __fastcall hkpListShape::castRayWithCollector(hkpListShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpListShape *v4; // rsi
  hkpRayHitCollector *v5; // r12
  hkpCdBody *v6; // r15
  hkpShapeRayCastInput *v7; // rbp
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  unsigned int v12; // ebx
  signed int v13; // edi
  __int64 v14; // r14
  __int64 v15; // rcx
  __int64 v16; // rax
  __int64 v17; // r14
  __int64 v18; // rcx
  __int64 v19; // rax
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // [rsp+30h] [rbp-48h]
  unsigned int v26; // [rsp+38h] [rbp-40h]
  __int64 v27; // [rsp+40h] [rbp-38h]
  hkpCdBody *v28; // [rsp+48h] [rbp-30h]
  char v29; // [rsp+88h] [rbp+10h]

  v4 = this;
  v5 = collector;
  v6 = cdBody;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcList";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = 0;
  v13 = 1;
  if ( v7->m_rayShapeCollectionFilter )
  {
    if ( v4->m_childInfo.m_size > 0 )
    {
      v17 = 0i64;
      do
      {
        if ( (v12 >= 0x100 || v13 & v4->m_enabledChildren[(unsigned __int64)v12 >> 5])
          && *(_BYTE *)((__int64 (__fastcall *)(hkpRayShapeCollectionFilter *, char *, hkpShapeRayCastInput *, hkpShapeContainerVtbl **))v7->m_rayShapeCollectionFilter->vfptr->isCollisionEnabled)(
                         v7->m_rayShapeCollectionFilter,
                         &v29,
                         v7,
                         &v4->vfptr) )
        {
          v18 = (__int64)v4->m_childInfo.m_data[v17].m_shape;
          v19 = (__int64)v6->m_motion;
          v28 = v6;
          v27 = v19;
          v25 = v18;
          v26 = v12;
          (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v18 + 48i64))(
            v18,
            v7,
            &v25,
            v5);
        }
        v13 = __ROL4__(v13, 1);
        ++v12;
        ++v17;
      }
      while ( (signed int)v12 < v4->m_childInfo.m_size );
    }
  }
  else if ( v4->m_childInfo.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      if ( v12 >= 0x100 || v13 & v4->m_enabledChildren[(unsigned __int64)v12 >> 5] )
      {
        v15 = (__int64)v4->m_childInfo.m_data[v14].m_shape;
        v16 = (__int64)v6->m_motion;
        v28 = v6;
        v27 = v16;
        v25 = v15;
        v26 = v12;
        (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v15 + 48i64))(
          v15,
          v7,
          &v25,
          v5);
      }
      v13 = __ROL4__(v13, 1);
      ++v12;
      ++v14;
    }
    while ( (signed int)v12 < v4->m_childInfo.m_size );
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v22[1] = v24;
  }
}

// File Line: 271
// RVA: 0xCEFAF0
void __usercall hkpListShape::getAabb(hkpListShape *this@<rcx>, hkTransformf *localToWorld@<rdx>, float tolerance@<xmm2>, hkAabb *out@<r9>, __int64 a5@<r8>)
{
  hkAabb *v5; // rbx
  hkTransformf *v6; // rbp
  hkpListShape *v7; // rdi
  int v8; // esi
  __m128 v9; // xmm1
  __int64 v10; // r14
  __m128 v11; // xmm1
  __m128 v12; // [rsp+20h] [rbp-38h]
  __m128 v13; // [rsp+30h] [rbp-28h]

  v5 = out;
  v6 = localToWorld;
  v7 = this;
  if ( _mm_movemask_ps(_mm_cmpleps(this->m_aabbHalfExtents.m_quad, (__m128)0i64)) == 15 )
    hkpListShape::recalcAabbExtents(this);
  v8 = 0;
  v9 = _mm_mul_ps((__m128)xmmword_141A712A0, (__m128)xmmword_141A711B0);
  v5->m_min.m_quad = v9;
  v5->m_max.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9);
  if ( v7->m_childInfo.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, __m128 *))v7->m_childInfo.m_data[v10].m_shape->vfptr[2].__vecDelDtor)(
        v7->m_childInfo.m_data[v10].m_shape,
        v6,
        a5,
        &v12);
      ++v8;
      ++v10;
      v11 = _mm_max_ps(v5->m_max.m_quad, v13);
      v5->m_min.m_quad = _mm_min_ps(v5->m_min.m_quad, v12);
      v5->m_max.m_quad = v11;
    }
    while ( v8 < v7->m_childInfo.m_size );
  }
}

// File Line: 650
// RVA: 0xCF0050
void __fastcall hkpListShape::recalcAabbExtents(hkpListShape *this)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  hkpListShape::recalcAabbExtents(this, &aabb);
}

// File Line: 656
// RVA: 0xCF0070
void __fastcall hkpListShape::recalcAabbExtents(hkpListShape *this, hkAabb *aabb, __int64 a3)
{
  hkpListShape *v3; // rdi
  hkAabb *v4; // rbx
  __int64 v5; // r8
  signed int v6; // ebp
  signed __int64 v7; // rsi
  __m128 v8; // xmm1
  __m128 v9; // [rsp+20h] [rbp-28h]
  __m128 v10; // [rsp+30h] [rbp-18h]

  v3 = this;
  v4 = aabb;
  ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, hkAabb *))this->m_childInfo.m_data->m_shape->vfptr[2].__vecDelDtor)(
    this->m_childInfo.m_data->m_shape,
    &transform,
    a3,
    aabb);
  v6 = 1;
  if ( v3->m_childInfo.m_size > 1 )
  {
    v7 = 1i64;
    do
    {
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))v3->m_childInfo.m_data[v7].m_shape->vfptr[2].__vecDelDtor)(
        v3->m_childInfo.m_data[v7].m_shape,
        &transform,
        v5,
        &v9);
      ++v6;
      ++v7;
      v8 = _mm_max_ps(v4->m_max.m_quad, v10);
      v4->m_min.m_quad = _mm_min_ps(v4->m_min.m_quad, v9);
      v4->m_max.m_quad = v8;
    }
    while ( v6 < v3->m_childInfo.m_size );
  }
  v3->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(v4->m_max.m_quad, v4->m_min.m_quad), (__m128)xmmword_141A711B0);
  v3->m_aabbHalfExtents.m_quad = _mm_mul_ps(_mm_sub_ps(v4->m_max.m_quad, v4->m_min.m_quad), (__m128)xmmword_141A711B0);
}

// File Line: 678
// RVA: 0xCEFAB0
hkpShape *__fastcall hkpListShape::getChildShape(hkpListShape *this, unsigned int key, char (*buffer)[512])
{
  return *(hkpShape **)(32i64 * (signed int)key + *(_QWORD *)&this->m_type.m_storage);
}

// File Line: 720
// RVA: 0xCEFAD0
__int64 __fastcall hkpListShape::getCollisionFilterInfo(hkpListShape *this, unsigned int key)
{
  return *(unsigned int *)(32i64 * (signed int)key + *(_QWORD *)&this->m_type.m_storage + 8);
}

// File Line: 744
// RVA: 0xCF02C0
void __fastcall hkpListShape::setCollisionFilterInfo(hkpListShape *this, unsigned int index, unsigned int filterInfo)
{
  this->m_childInfo.m_data[index].m_collisionFilterInfo = filterInfo;
}

// File Line: 749
// RVA: 0xCF02E0
signed __int64 __fastcall hkpListShape::calcSizeForSpu(hkpListShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpShape::CalcSizeForSpuInput *v3; // r14
  hkpListShape *v4; // rbp
  int v6; // eax
  int v7; // ebx
  __int64 v8; // rsi
  hkpListShape::ChildInfo *v9; // rdi

  v3 = input;
  v4 = this;
  if ( input->m_midphaseAgent3Registered && !input->m_isFixedOrKeyframed && this->m_childInfo.m_size > 252 )
    return 0xFFFFFFFFi64;
  v6 = this->m_childInfo.m_size;
  if ( v6 >= 2047 )
    return 0xFFFFFFFFi64;
  v7 = 0;
  if ( v6 <= 0 )
    return 144i64;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v4->m_childInfo.m_data;
    v9[v8].m_shapeSize = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, signed __int64))v9[v8].m_shape->vfptr[8].__vecDelDtor)(
                           v9[v8].m_shape,
                           v3,
                           256i64);
    v4->m_childInfo.m_data[v8].m_numChildShapes = v4->m_childInfo.m_size;
    if ( v4->m_childInfo.m_data[v8].m_shapeSize == -1 )
      break;
    ++v7;
    ++v8;
    if ( v7 >= v4->m_childInfo.m_size )
      return 144i64;
  }
  return 0xFFFFFFFFi64;
}

