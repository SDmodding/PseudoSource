// File Line: 25
// RVA: 0xCF9FE0
void __fastcall hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(
        hkpTriSampledHeightFieldCollection *this,
        hkpSampledHeightFieldShape *shape,
        float radius)
{
  hkpShapeCollection::hkpShapeCollection(this, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION, COLLECTION_TRISAMPLED_HEIGHTFIELD);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldCollection::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpTriSampledHeightFieldCollection::`vftable{for `hkpShapeContainer};
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_size = 0;
  this->m_heightfield = shape;
  this->m_radius = radius;
  this->m_triangleExtrusion = 0i64;
  hkReferencedObject::addReference(shape);
}

// File Line: 41
// RVA: 0xCFA060
void __fastcall hkpTriSampledHeightFieldCollection::hkpTriSampledHeightFieldCollection(
        hkpTriSampledHeightFieldCollection *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpShapeCollection::hkpShapeCollection(this, flag);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldCollection::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpTriSampledHeightFieldCollection::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 6;
    this->m_collectionType.m_storage = 2;
  }
}

// File Line: 50
// RVA: 0xCFA0B0
void __fastcall hkpTriSampledHeightFieldCollection::~hkpTriSampledHeightFieldCollection(
        hkpTriSampledHeightFieldCollection *this)
{
  int m_capacityAndFlags; // r8d

  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldCollection::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpTriSampledHeightFieldCollection::`vftable{for `hkpShapeContainer};
  hkReferencedObject::removeReference(this->m_heightfield);
  m_capacityAndFlags = this->m_weldingInfo.m_capacityAndFlags;
  this->m_weldingInfo.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_weldingInfo.m_data,
      2 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 57
// RVA: 0xCFA140
__int64 __fastcall hkpTriSampledHeightFieldCollection::getFirstKey(hkpTriSampledHeightFieldCollection *this)
{
  return 0i64;
}

// File Line: 62
// RVA: 0xCFA150
__int64 __fastcall hkpTriSampledHeightFieldCollection::getNextKey(
        hkpTriSampledHeightFieldCollection *this,
        unsigned int oldKey)
{
  __int64 v3; // r8
  unsigned int v4; // ecx
  int v5; // edx

  if ( (oldKey & 1) == 0 )
    return oldKey | 1;
  v3 = *(_QWORD *)&this->m_type.m_storage;
  v4 = HIWORD(oldKey);
  v5 = ((unsigned __int16)oldKey >> 1) + 1;
  if ( v5 == *(_DWORD *)(v3 + 60) - 1 && (++v4, v5 = 0, v4 == *(_DWORD *)(v3 + 64) - 1) )
    return 0xFFFFFFFFi64;
  else
    return 2 * (v5 + (v4 << 15));
}

// File Line: 87
// RVA: 0xCFA1A0
hkpShape *__fastcall hkpTriSampledHeightFieldCollection::getChildShape(
        hkpTriSampledHeightFieldCollection *this,
        unsigned int key,
        hkpShape *buffer)
{
  __m128 v3; // xmm0
  unsigned __int16 v6; // bx
  unsigned __int16 v7; // si
  unsigned int v8; // r15d
  hkpSampledHeightFieldShape *HeightFieldShape; // r12
  int v10; // ebp
  int m_userData_high; // xmm0_4
  int v12; // r14d
  __int128 *v13; // r13
  int v14; // ebx
  __m128 v15; // xmm6
  int v16; // edx
  char v17; // r14
  __int64 v18; // r8
  int v19; // eax
  hkpShape *result; // rax
  __m128 v21; // xmm2
  __int128 v22[4]; // [rsp+20h] [rbp-88h] BYREF
  char v24; // [rsp+B8h] [rbp+10h]
  char v25; // [rsp+C0h] [rbp+18h] BYREF

  v24 = key;
  v6 = key;
  v7 = 0;
  v8 = HIWORD(key);
  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)((char *)this - 32));
  v10 = v6 >> 1;
  if ( buffer )
  {
    m_userData_high = HIDWORD(this->m_userData);
    *(_DWORD *)&buffer->m_memSizeAndFlags = 0x1FFFF;
    *(_DWORD *)&buffer->m_type.m_storage = 1026;
    LODWORD(buffer[1].vfptr) = m_userData_high;
    buffer->m_userData = 0i64;
    v3 = 0i64;
    buffer->vfptr = (hkBaseObjectVtbl *)&hkpTriangleShape::`vftable;
    *(_DWORD *)&buffer[1].m_memSizeAndFlags = 393216;
    buffer[3].hkReferencedObject = 0i64;
  }
  else
  {
    buffer = 0i64;
  }
  v12 = 0;
  v13 = v22;
  do
  {
    v14 = v8 + (v12 & 1);
    v15 = (__m128)COERCE_UNSIGNED_INT((float)(v10 + (v12 >> 1)));
    *(double *)v3.m128_u64 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))HeightFieldShape->vfptr[10].__vecDelDtor)(
                               HeightFieldShape,
                               (unsigned int)(v10 + (v12++ >> 1)),
                               (unsigned int)v14);
    ++v13;
    v3 = _mm_unpacklo_ps(v3, (__m128)0i64);
    *(v13 - 1) = (__int128)_mm_mul_ps(
                             _mm_unpacklo_ps(_mm_unpacklo_ps(v15, (__m128)COERCE_UNSIGNED_INT((float)v14)), v3),
                             HeightFieldShape->m_intToFloatScale.m_quad);
  }
  while ( v12 < 4 );
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, char *))HeightFieldShape->vfptr[10].__first_virtual_table_function__)(
    HeightFieldShape,
    &v25);
  v16 = v25 != 0;
  v17 = 0;
  v18 = v24 & 1;
  *(_OWORD *)&buffer[1].m_type.m_storage = v22[3 * (v18 & ~v16)];
  buffer[2].hkReferencedObject = (hkReferencedObject)v22[v18 * (v16 + 1i64) + 1];
  *(_OWORD *)&buffer[2].m_type.m_storage = v22[v16 - v18 + 2];
  v19 = *(_DWORD *)&this->m_disableWelding.m_bool;
  if ( !v19 )
    v17 = 6;
  if ( v19 )
    v7 = *((_WORD *)&this->hkpShapeCollection::hkpShapeContainer::vfptr->__vecDelDtor
         + (v24 & 1 | (unsigned __int64)(int)(2
                                            * (v10
                                             + v8
                                             * (hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)((char *)this - 32))->m_xRes
                                              - 1)))));
  LOBYTE(buffer[1].m_referenceCount) = v17;
  buffer[1].m_memSizeAndFlags = v7;
  result = buffer;
  v21 = _mm_mul_ps(*(__m128 *)&this->m_heightfield, *(__m128 *)&this->m_heightfield);
  HIBYTE(buffer[1].m_referenceCount) = (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) > 0.0;
  buffer[3].hkReferencedObject = *(hkReferencedObject *)&this->m_heightfield;
  return result;
}

// File Line: 137
// RVA: 0xCFA540
void __fastcall hkpTriSampledHeightFieldCollection::getAabb(
        hkpTriSampledHeightFieldCollection *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkpSampledHeightFieldShape *HeightFieldShape; // rax
  __m128 v8; // xmm3
  hkVector4f v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // [rsp+20h] [rbp-38h] BYREF
  __m128 v13; // [rsp+30h] [rbp-28h]

  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape(this);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkTransformf *, hkBaseObjectVtbl *, __m128 *))HeightFieldShape->vfptr[2].__vecDelDtor)(
    HeightFieldShape,
    localToWorld,
    HeightFieldShape->vfptr,
    &v12);
  v8 = v13;
  v9.m_quad = (__m128)this->m_triangleExtrusion;
  v10 = _mm_add_ps(v9.m_quad, v12);
  v11 = _mm_add_ps(v9.m_quad, v13);
  out->m_min.m_quad = _mm_min_ps(v12, v10);
  out->m_max.m_quad = _mm_max_ps(v8, v11);
}

// File Line: 156
// RVA: 0xCFA5C0
__int64 __fastcall hkpTriSampledHeightFieldCollection::calcSizeForSpu(
        hkpTriSampledHeightFieldCollection *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int v4; // edi
  __int64 v5; // rax

  v4 = spuBufferSizeLeft - 96;
  v5 = ((__int64 (__fastcall *)(hkpSampledHeightFieldShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_heightfield->vfptr[8].__vecDelDtor)(
         this->m_heightfield,
         input,
         (unsigned int)(spuBufferSizeLeft - 96));
  if ( (int)v5 < 0 || (int)v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( (hkpTriSampledHeightFieldCollection *)this->m_heightfield == &this[1] )
  {
    this->m_childSize = 0;
    return v5 + 96;
  }
  else
  {
    this->m_childSize = v5;
    return 96i64;
  }
}

// File Line: 184
// RVA: 0xCFA3A0
__int64 __fastcall hkpTriSampledHeightFieldCollection::getCollisionFilterInfo(
        hkpTriSampledHeightFieldCollection *this,
        unsigned int key)
{
  return 0i64;
}

// File Line: 189
// RVA: 0xCFA4D0
void __fastcall hkpTriSampledHeightFieldCollection::setWeldingInfo(
        hkpTriSampledHeightFieldCollection *this,
        unsigned int key,
        unsigned __int16 weldingInfo)
{
  this->m_weldingInfo.m_data[key & 1 | (unsigned __int64)(int)(2
                                                             * (((unsigned __int16)key >> 1)
                                                              + HIWORD(key)
                                                              * (hkpTriSampledHeightFieldCollection::getHeightFieldShape(this)->m_xRes
                                                               - 1)))] = weldingInfo;
}

// File Line: 197
// RVA: 0xCFA3B0
void __fastcall hkpTriSampledHeightFieldCollection::initWeldingInfo(
        hkpTriSampledHeightFieldCollection *this,
        hkpWeldingUtility::WeldingType weldingType)
{
  hkpSampledHeightFieldShape *HeightFieldShape; // rax
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_weldingInfo; // rsi
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  int v9; // edx
  unsigned __int16 *v10; // rdi
  __int64 v11; // rcx
  int m_capacityAndFlags; // r8d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

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
    HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape(this);
    p_m_weldingInfo = &this->m_weldingInfo;
    v5 = (HeightFieldShape->m_xRes - 1) * (2 * HeightFieldShape->m_zRes - 2);
    if ( (this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v5 )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v5,
        2);
    v6 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 < v5 )
    {
      v7 = 2 * v6;
      v8 = v5;
      if ( v5 < v7 )
        v8 = v7;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v8,
        2);
    }
    v9 = v5 - this->m_weldingInfo.m_size;
    v10 = &this->m_weldingInfo.m_data[this->m_weldingInfo.m_size];
    v11 = v9;
    if ( v9 > 0 )
    {
      while ( v11 )
      {
        *v10++ = 0;
        --v11;
      }
    }
    p_m_weldingInfo->m_size = v5;
  }
}

// File Line: 214
// RVA: 0xCFA630
hkpSampledHeightFieldShape *__fastcall hkpTriSampledHeightFieldCollection::getHeightFieldShape(
        hkpTriSampledHeightFieldCollection *this)
{
  return this->m_heightfield;
}

