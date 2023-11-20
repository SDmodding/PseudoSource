// File Line: 25
// RVA: 0xCF9FE0
void __fastcall hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(hkpTriSampledHeightFieldCollection *this, hkpSampledHeightFieldShape *shape, float radius)
{
  hkpSampledHeightFieldShape *v3; // rbx
  hkpTriSampledHeightFieldCollection *v4; // rdi

  v3 = shape;
  v4 = this;
  hkpShapeCollection::hkpShapeCollection(
    (hkpShapeCollection *)&this->vfptr,
    TRI_SAMPLED_HEIGHT_FIELD_COLLECTION,
    COLLECTION_TRISAMPLED_HEIGHTFIELD);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldCollection::`vftable'{for `hkpShape'};
  v4->vfptr = (hkpShapeContainerVtbl *)&hkpTriSampledHeightFieldCollection::`vftable'{for `hkpShapeContainer'};
  v4->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v4->m_weldingInfo.m_data = 0i64;
  v4->m_weldingInfo.m_size = 0;
  v4->m_heightfield = v3;
  v4->m_radius = radius;
  v4->m_triangleExtrusion = 0i64;
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 41
// RVA: 0xCFA060
void __fastcall hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(hkpTriSampledHeightFieldCollection *this, hkFinishLoadedObjectFlag flag)
{
  hkpTriSampledHeightFieldCollection *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldCollection::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpTriSampledHeightFieldCollection::`vftable'{for `hkpShapeContainer'};
  if ( v3 )
  {
    v2->m_type.m_storage = 6;
    v2->m_collectionType.m_storage = 2;
  }
}

// File Line: 50
// RVA: 0xCFA0B0
void __fastcall hkpTriSampledHeightFieldCollection::~hkpTriSampledHeightFieldCollection(hkpTriSampledHeightFieldCollection *this)
{
  hkpTriSampledHeightFieldCollection *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldCollection::`vftable'{for `hkpShape'};
  this->vfptr = (hkpShapeContainerVtbl *)&hkpTriSampledHeightFieldCollection::`vftable'{for `hkpShapeContainer'};
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_heightfield->vfptr);
  v2 = v1->m_weldingInfo.m_capacityAndFlags;
  v1->m_weldingInfo.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_weldingInfo.m_data,
      2 * (v2 & 0x3FFFFFFF));
  v1->m_weldingInfo.m_data = 0i64;
  v1->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 57
// RVA: 0xCFA140
__int64 __fastcall hkpTriSampledHeightFieldCollection::getFirstKey(hkpTriSampledHeightFieldCollection *this)
{
  return 0i64;
}

// File Line: 62
// RVA: 0xCFA150
signed __int64 __fastcall hkpTriSampledHeightFieldCollection::getNextKey(hkpTriSampledHeightFieldCollection *this, unsigned int oldKey)
{
  signed __int64 result; // rax
  __int64 v3; // r8
  unsigned int v4; // ecx
  int v5; // edx

  if ( !(oldKey & 1) )
    return oldKey | 1;
  v3 = *(_QWORD *)&this->m_type.m_storage;
  v4 = oldKey >> 16;
  v5 = ((unsigned __int16)oldKey >> 1) + 1;
  if ( v5 != *(_DWORD *)(v3 + 60) - 1 || (++v4, v5 = 0, v4 != *(_DWORD *)(v3 + 64) - 1) )
    result = 2 * (v5 + (v4 << 15));
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 87
// RVA: 0xCFA1A0
hkpShape *__usercall hkpTriSampledHeightFieldCollection::getChildShape@<rax>(hkpTriSampledHeightFieldCollection *this@<rcx>, unsigned int key@<edx>, char (*buffer)[512]@<r8>, __m128 a4@<xmm0>)
{
  hkpTriSampledHeightFieldCollection *v4; // r13
  char (*v5)[512]; // rdi
  unsigned __int16 v6; // bx
  __int16 v7; // si
  unsigned int v8; // er15
  hkpSampledHeightFieldShape *v9; // r12
  int v10; // ebp
  int v11; // xmm0_4
  signed int v12; // er14
  __int128 *v13; // r13
  int v14; // ebx
  __m128 v15; // xmm6
  int v16; // edx
  char v17; // r14
  __int64 v18; // r8
  float v19; // eax
  hkpShape *result; // rax
  __m128 v21; // xmm2
  __int128 v22; // [rsp+20h] [rbp-88h]
  __int128 v23; // [rsp+30h] [rbp-78h]
  __int128 v24[2]; // [rsp+40h] [rbp-68h]
  __m128 *v25; // [rsp+B0h] [rbp+8h]
  unsigned int v26; // [rsp+B8h] [rbp+10h]
  char v27; // [rsp+C0h] [rbp+18h]

  v26 = key;
  v25 = (__m128 *)this;
  v4 = this;
  v5 = buffer;
  v6 = key;
  v7 = 0;
  v8 = key >> 16;
  v9 = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)((char *)this - 32));
  v10 = v6 >> 1;
  if ( v5 )
  {
    v11 = HIDWORD(v4->m_userData);
    *(_DWORD *)&(*v5)[8] = 0x1FFFF;
    *(_DWORD *)&(*v5)[16] = 1026;
    *(_DWORD *)&(*v5)[32] = v11;
    *(_QWORD *)&(*v5)[24] = 0i64;
    a4 = 0i64;
    *(_QWORD *)v5 = &hkpTriangleShape::`vftable';
    *(_DWORD *)&(*v5)[40] = 393216;
    *(_OWORD *)&(*v5)[96] = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v12 = 0;
  v13 = &v22;
  do
  {
    v14 = v8 + (v12 & 1);
    v15 = (__m128)COERCE_UNSIGNED_INT((float)(v10 + (v12 >> 1)));
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v9->vfptr[10].__vecDelDtor)(
      v9,
      (unsigned int)(v10 + (v12++ >> 1)),
      (unsigned int)v14);
    ++v13;
    a4 = _mm_unpacklo_ps(a4, (__m128)0i64);
    *(v13 - 1) = (__int128)_mm_mul_ps(
                             _mm_unpacklo_ps(_mm_unpacklo_ps(v15, (__m128)COERCE_UNSIGNED_INT((float)v14)), a4),
                             v9->m_intToFloatScale.m_quad);
  }
  while ( v12 < 4 );
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, char *))v9->vfptr[10].__first_virtual_table_function__)(v9, &v27);
  v16 = v27 != 0;
  v17 = 0;
  v18 = v26 & 1;
  *(_OWORD *)&(*v5)[48] = *(&v22 + 3 * (v18 & ~v16));
  *(_OWORD *)&(*v5)[64] = *(&v23 + v18 * (v16 + 1i64));
  *(_OWORD *)&(*v5)[80] = v24[v16 - v18];
  v19 = v25[2].m128_f32[2];
  if ( v19 == 0.0 )
    v17 = 6;
  if ( v19 != 0.0 )
    v7 = *(_WORD *)(v25[2].m128_u64[0]
                  + 2
                  * (v26 & 1 | (unsigned __int64)(signed int)(2
                                                            * (v10
                                                             + v8
                                                             * (hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)&v25[-2])->m_xRes
                                                              - 1)))));
  (*v5)[42] = v17;
  *(_WORD *)&(*v5)[40] = v7;
  result = (hkpShape *)v5;
  v21 = _mm_mul_ps(v25[3], v25[3]);
  (*v5)[43] = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) > 0.0;
  *(__m128 *)&(*v5)[96] = v25[3];
  return result;
}

// File Line: 137
// RVA: 0xCFA540
void __fastcall hkpTriSampledHeightFieldCollection::getAabb(hkpTriSampledHeightFieldCollection *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkAabb *v4; // rsi
  hkTransformf *v5; // rbx
  hkpTriSampledHeightFieldCollection *v6; // rdi
  hkpSampledHeightFieldShape *v7; // rax
  float v8; // xmm6_4
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // [rsp+20h] [rbp-38h]
  __m128 v12; // [rsp+30h] [rbp-28h]

  v4 = out;
  v5 = localToWorld;
  v6 = this;
  v7 = hkpTriSampledHeightFieldCollection::getHeightFieldShape(this);
  v8 = tolerance + v6->m_radius;
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkTransformf *, hkBaseObjectVtbl *, __m128 *))v7->vfptr[2].__vecDelDtor)(
    v7,
    v5,
    v7->vfptr,
    &v11);
  v9 = v12;
  v10 = _mm_add_ps(v6->m_triangleExtrusion.m_quad, v12);
  v4->m_min.m_quad = _mm_min_ps(v11, _mm_add_ps(v6->m_triangleExtrusion.m_quad, v11));
  v4->m_max.m_quad = _mm_max_ps(v9, v10);
}

// File Line: 156
// RVA: 0xCFA5C0
signed __int64 __fastcall hkpTriSampledHeightFieldCollection::calcSizeForSpu(hkpTriSampledHeightFieldCollection *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpTriSampledHeightFieldCollection *v3; // rbx
  int v4; // edi
  __int64 v5; // rax
  signed __int64 result; // rax

  v3 = this;
  v4 = spuBufferSizeLeft - 96;
  v5 = ((__int64 (__fastcall *)(hkpSampledHeightFieldShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_heightfield->vfptr[8].__vecDelDtor)(
         this->m_heightfield,
         input,
         (unsigned int)(spuBufferSizeLeft - 96));
  if ( (signed int)v5 < 0 || (signed int)v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( (hkpTriSampledHeightFieldCollection *)v3->m_heightfield == &v3[1] )
  {
    v3->m_childSize = 0;
    result = v5 + 96;
  }
  else
  {
    v3->m_childSize = v5;
    result = 96i64;
  }
  return result;
}

// File Line: 184
// RVA: 0xCFA3A0
__int64 __fastcall hkpTriSampledHeightFieldCollection::getCollisionFilterInfo(hkpTriSampledHeightFieldCollection *this, unsigned int key)
{
  return 0i64;
}

// File Line: 189
// RVA: 0xCFA4D0
void __fastcall hkpTriSampledHeightFieldCollection::setWeldingInfo(hkpTriSampledHeightFieldCollection *this, unsigned int key, __int16 weldingInfo)
{
  this->m_weldingInfo.m_data[key & 1 | (unsigned __int64)(signed int)(2
                                                                    * (((unsigned __int16)key >> 1)
                                                                     + (key >> 16)
                                                                     * (hkpTriSampledHeightFieldCollection::getHeightFieldShape(this)->m_xRes
                                                                      - 1)))] = weldingInfo;
}

// File Line: 197
// RVA: 0xCFA3B0
void __fastcall hkpTriSampledHeightFieldCollection::initWeldingInfo(hkpTriSampledHeightFieldCollection *this, hkpWeldingUtility::WeldingType weldingType)
{
  hkpTriSampledHeightFieldCollection *v2; // rdi
  hkpSampledHeightFieldShape *v3; // rax
  signed __int64 v4; // rsi
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // er9
  int v9; // edx
  unsigned __int16 *v10; // rdi
  __int64 v11; // rcx
  int v12; // er8
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  if ( weldingType == 6 )
  {
    v12 = this->m_weldingInfo.m_capacityAndFlags;
    this->m_weldingInfo.m_size = 0;
    if ( v12 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * (v12 & 0x3FFFFFFF));
    v2->m_weldingInfo.m_data = 0i64;
    v2->m_weldingInfo.m_capacityAndFlags = 2147483648;
  }
  else
  {
    v3 = hkpTriSampledHeightFieldCollection::getHeightFieldShape(this);
    v4 = (signed __int64)&v2->m_weldingInfo;
    v5 = (v3->m_xRes - 1) * (2 * v3->m_zRes - 2);
    if ( (v2->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v5 )
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_weldingInfo,
        v5,
        2);
    v6 = v2->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 < v5 )
    {
      v7 = 2 * v6;
      v8 = v5;
      if ( v5 < v7 )
        v8 = v7;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_weldingInfo,
        v8,
        2);
    }
    v9 = v5 - v2->m_weldingInfo.m_size;
    v10 = &v2->m_weldingInfo.m_data[v2->m_weldingInfo.m_size];
    v11 = v9;
    if ( v9 > 0 )
    {
      while ( v11 )
      {
        *v10 = 0;
        ++v10;
        --v11;
      }
    }
    *(_DWORD *)(v4 + 8) = v5;
  }
}

// File Line: 214
// RVA: 0xCFA630
hkpSampledHeightFieldShape *__fastcall hkpTriSampledHeightFieldCollection::getHeightFieldShape(hkpTriSampledHeightFieldCollection *this)
{
  return this->m_heightfield;
}

