// File Line: 24
// RVA: 0xCF9390
void __fastcall hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkpTriSampledHeightFieldCollection *c,
        hkBool doAabbRejection)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1031;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldBvTreeShape::`vftable;
  this->m_childContainer.m_childShape = c;
  this->m_childContainer.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  hkReferencedObject::addReference(c);
  this->m_wantAabbRejectionTest = doAabbRejection;
}

// File Line: 31
// RVA: 0xCF9CF0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpBvTreeShape::hkpBvTreeShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldBvTreeShape::`vftable;
  this->m_childContainer.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 7;
    this->m_bvTreeType.m_storage = 1;
  }
}

// File Line: 43
// RVA: 0xCF93F0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::queryObb(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkTransformf *obbTransform,
        hkVector4f *obbExtent,
        float tolerance,
        hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  __m128 m_quad; // xmm2
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v7; // xmm3
  __int128 v8[2]; // [rsp+20h] [rbp-28h] BYREF

  m_quad = obbExtent->m_quad;
  vfptr = this->vfptr;
  v7 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), obbTransform->m_rotation.m_col1.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), obbTransform->m_rotation.m_col0.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), obbTransform->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0)));
  v8[1] = (__int128)_mm_add_ps(obbTransform->m_translation.m_quad, v7);
  v8[0] = (__int128)_mm_add_ps(
                      _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v7),
                      obbTransform->m_translation.m_quad);
  ((void (__fastcall *)(hkpTriSampledHeightFieldBvTreeShape *, __int128 *, hkArray<unsigned int,hkContainerHeapAllocator> *))vfptr[8].__first_virtual_table_function__)(
    this,
    v8,
    hits);
}

// File Line: 60
// RVA: 0xCF9D80
hkBool *__fastcall hkpTriSampledHeightFieldBvTreeShape::getExtentsForQueryAabb(
        hkBool *result,
        hkAabb *aabb,
        hkpTriSampledHeightFieldCollection *collection,
        unsigned int *minX,
        unsigned int *maxX,
        unsigned int *minZ,
        unsigned int *maxZ)
{
  __int128 v7; // xmm8
  hkpSampledHeightFieldShape *HeightFieldShape; // r14
  __m128 v13; // xmm2
  hkVector4f v14; // xmm1
  __int64 v15; // r8
  __m128 v16; // xmm0
  hkVector4f v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  hkVector4f v21; // xmm9
  int m_xRes; // eax
  __m128 m_quad; // xmm5
  __m128i v24; // xmm6
  int m_zRes; // eax
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128i v30; // xmm1
  __m128i v31; // xmm7
  unsigned __int64 v32; // xmm1_8
  unsigned __int16 v33; // cx
  unsigned __int16 v34; // r9
  unsigned __int64 v35; // rax
  unsigned __int16 v36; // dx
  unsigned __int16 v37; // ax
  __m128 v39; // [rsp+30h] [rbp-78h] BYREF
  __m128 v40; // [rsp+40h] [rbp-68h]
  __int128 v41; // [rsp+60h] [rbp-48h]

  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape(collection);
  v13 = _mm_shuffle_ps((__m128)LODWORD(collection->m_radius), (__m128)LODWORD(collection->m_radius), 0);
  v14.m_quad = _mm_sub_ps(aabb->m_min.m_quad, v13);
  aabb->m_max.m_quad = _mm_add_ps(aabb->m_max.m_quad, v13);
  aabb->m_min = (hkVector4f)v14.m_quad;
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkVector4f *, __int64, __m128 *))HeightFieldShape->vfptr[2].__vecDelDtor)(
    HeightFieldShape,
    &transform,
    v15,
    &v39);
  v16 = _mm_and_ps(_mm_cmplt_ps(aabb->m_min.m_quad, v39), *(__m128 *)&hkVector4fComparison_maskToComparison_344[20]);
  v17.m_quad = _mm_or_ps(_mm_andnot_ps(v16, aabb->m_min.m_quad), _mm_and_ps(v39, v16));
  v18 = v40;
  v19 = v40;
  aabb->m_min = (hkVector4f)v17.m_quad;
  v20 = _mm_and_ps(_mm_cmplt_ps(v19, aabb->m_max.m_quad), *(__m128 *)&hkVector4fComparison_maskToComparison_344[20]);
  v21.m_quad = _mm_or_ps(_mm_andnot_ps(v20, aabb->m_max.m_quad), _mm_and_ps(v18, v20));
  aabb->m_max = (hkVector4f)v21.m_quad;
  if ( (_mm_movemask_ps(_mm_cmple_ps(v21.m_quad, v17.m_quad)) & 7) != 0 )
  {
    result->m_bool = 0;
  }
  else
  {
    m_xRes = HeightFieldShape->m_xRes;
    m_quad = HeightFieldShape->m_floatToIntOffsetFloorCorrected.m_quad;
    result->m_bool = 1;
    v24 = _mm_cvtsi32_si128(m_xRes - 2);
    m_zRes = HeightFieldShape->m_zRes;
    v41 = v7;
    v26 = m_quad;
    v27 = _mm_unpacklo_ps(
            _mm_unpacklo_ps(_mm_cvtepi32_ps(v24), (__m128)COERCE_UNSIGNED_INT((float)(m_zRes - 2))),
            (__m128)0i64);
    v28 = _mm_max_ps(
            _mm_min_ps(_mm_mul_ps(_mm_add_ps(m_quad, v21.m_quad), HeightFieldShape->m_floatToIntScale.m_quad), v27),
            (__m128)0i64);
    v29 = _mm_max_ps(
            _mm_min_ps(_mm_mul_ps(_mm_add_ps(v26, v17.m_quad), HeightFieldShape->m_floatToIntScale.m_quad), v27),
            (__m128)0i64);
    v30 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v29),
              _mm_cvttps_epi32(v29)),
            (__m128i)_xmm);
    v31 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v28),
              _mm_cvttps_epi32(v28)),
            (__m128i)_xmm);
    v32 = _mm_add_epi16(_mm_packs_epi32(v30, v30), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
    v33 = v32;
    v34 = WORD2(v32);
    v35 = _mm_add_epi16(_mm_packs_epi32(v31, v31), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
    v36 = v35;
    if ( (unsigned __int16)v32 < (unsigned __int16)v35 )
      v36 = v32;
    if ( (unsigned __int16)v32 < (unsigned __int16)v35 )
      v33 = v35;
    *minX = v36;
    *maxX = v33;
    LOWORD(v35) = WORD2(v35);
    if ( WORD2(v32) < WORD2(v35) )
      v37 = WORD2(v32);
    if ( WORD2(v32) < WORD2(v35) )
      v34 = WORD2(v35);
    *minZ = v37;
    *maxZ = v34;
  }
  return result;
}

// File Line: 129
// RVA: 0xCF98C0
__int64 __fastcall hkpTriSampledHeightFieldBvTreeShape::queryAabbImpl(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkAabb *aabbIn,
        unsigned int *hits,
        int maxNumKeys)
{
  hkpTriSampledHeightFieldCollection *m_childShape; // rbx
  __int64 v5; // rbp
  hkVector4f v8; // xmm2
  unsigned int v10; // edi
  hkpSampledHeightFieldShape *HeightFieldShape; // rax
  __int64 v12; // rbx
  __int64 v13; // r9
  float v14; // xmm6_4
  unsigned int v15; // r8d
  float v16; // xmm7_4
  float v17; // xmm8_4
  unsigned int v18; // r15d
  unsigned int v19; // edx
  char v20; // r13
  unsigned int v21; // ecx
  char v22; // r12
  unsigned int v23; // esi
  float v24; // xmm0_4
  float v25; // xmm0_4
  unsigned int v26; // ebp
  unsigned int v27; // ebx
  unsigned int v28; // esi
  float v29; // xmm0_4
  float v30; // xmm0_4
  unsigned int v31; // esi
  __int64 v32; // r14
  float v33; // xmm0_4
  unsigned int v34; // r8d
  unsigned int v35; // r11d
  unsigned int v36; // r10d
  unsigned int v37; // r9d
  int v38; // ecx
  __int64 v39; // rdx
  unsigned int maxZ; // [rsp+40h] [rbp-A8h] BYREF
  unsigned int minX; // [rsp+44h] [rbp-A4h] BYREF
  unsigned int maxX; // [rsp+48h] [rbp-A0h] BYREF
  unsigned int v43; // [rsp+4Ch] [rbp-9Ch]
  hkpSampledHeightFieldShape *v44; // [rsp+50h] [rbp-98h]
  hkAabb aabb; // [rsp+60h] [rbp-88h] BYREF
  unsigned int v46; // [rsp+F0h] [rbp+8h] BYREF
  unsigned int minZ; // [rsp+F8h] [rbp+10h] BYREF

  m_childShape = (hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape;
  v5 = maxNumKeys;
  v8.m_quad = _mm_max_ps(
                _mm_sub_ps(aabbIn->m_max.m_quad, m_childShape->m_triangleExtrusion.m_quad),
                aabbIn->m_max.m_quad);
  aabb.m_min.m_quad = _mm_min_ps(
                        _mm_sub_ps(aabbIn->m_min.m_quad, m_childShape->m_triangleExtrusion.m_quad),
                        aabbIn->m_min.m_quad);
  aabb.m_max = (hkVector4f)v8.m_quad;
  hkpTriSampledHeightFieldBvTreeShape::getExtentsForQueryAabb(
    (hkBool *)&v46,
    &aabb,
    m_childShape,
    &minX,
    &maxX,
    &minZ,
    &maxZ);
  if ( !(_BYTE)v46 )
    return 0i64;
  v10 = 0;
  v46 = 0;
  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape(m_childShape);
  v12 = 0i64;
  v13 = (__int64)HeightFieldShape;
  v44 = HeightFieldShape;
  if ( !this->m_wantAabbRejectionTest.m_bool )
  {
    v34 = minX;
    v35 = maxX;
    if ( minX <= maxX )
    {
      v36 = maxZ;
      v37 = minZ;
      do
      {
        if ( v37 <= v36 )
        {
          v38 = 2 * (v34 + (v37 << 15));
          v39 = v36 - v37 + 1;
          do
          {
            if ( v12 < v5 )
            {
              hits[v12++] = v38;
              ++v10;
              if ( v12 < v5 )
              {
                ++v10;
                hits[v12++] = v38 | 1;
              }
            }
            v38 += 0x10000;
            --v39;
          }
          while ( v39 );
        }
        ++v34;
      }
      while ( v34 <= v35 );
    }
    return v10;
  }
  v14 = HeightFieldShape->m_intToFloatScale.m_quad.m128_f32[1];
  v15 = maxX;
  v16 = aabb.m_max.m_quad.m128_f32[1];
  v17 = aabb.m_min.m_quad.m128_f32[1];
  v18 = minZ;
  v19 = maxZ;
  v20 = 1;
  v21 = minX;
  v43 = minX;
  v22 = 1;
  if ( minX <= maxX )
  {
    do
    {
      if ( minZ <= v19 )
      {
        v23 = 2 * (v21 + (minZ << 15));
        do
        {
          if ( v12 < v5 )
          {
            hits[v12++] = v23;
            ++v10;
            if ( v12 < v5 )
            {
              ++v10;
              hits[v12++] = v23 | 1;
            }
          }
          if ( v20 || v22 )
          {
            v24 = (*(float (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v13 + 160i64))(v13, v21, v18);
            v21 = v43;
            v19 = maxZ;
            v25 = v24 * v14;
            v13 = (__int64)v44;
            if ( v25 > v17 )
              v20 = 0;
            if ( v16 > v25 )
              v22 = 0;
          }
          ++v18;
          v23 += 0x10000;
        }
        while ( v18 <= v19 );
        v15 = maxX;
        v46 = v10;
      }
      v18 = minZ;
      v43 = ++v21;
    }
    while ( v21 <= v15 );
    if ( !v20 && !v22 )
      return v10;
    v18 = minZ;
  }
  v26 = minX;
  v27 = v15 + 1;
  if ( minX <= v15 + 1 )
  {
    v28 = v19 + 1;
    do
    {
      v29 = (*(float (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v13 + 160i64))(v13, v26, v28);
      v13 = (__int64)v44;
      v30 = v29 * v14;
      if ( v30 > v17 )
        v20 = 0;
      if ( v16 > v30 )
        v22 = 0;
      ++v26;
    }
    while ( v26 <= v27 );
    v10 = v46;
  }
  v31 = maxZ + 1;
  if ( v18 <= maxZ + 1 )
  {
    v32 = (__int64)v44;
    do
    {
      v33 = (*(float (__fastcall **)(__int64, _QWORD, _QWORD, __int64))(*(_QWORD *)v32 + 160i64))(v32, v27, v18, v13)
          * v14;
      if ( v33 > v17 )
        v20 = 0;
      if ( v16 > v33 )
        v22 = 0;
      ++v18;
    }
    while ( v18 <= v31 );
    v10 = v46;
  }
  if ( v20 || v22 )
    return 0i64;
  return v10;
}

// File Line: 248
// RVA: 0xCF94A0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::queryAabb(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkAabb *aabbIn,
        hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  hkVector4f v3; // xmm1
  hkArray<unsigned int,hkContainerHeapAllocator> *v4; // rbx
  hkpTriSampledHeightFieldCollection *m_childShape; // r8
  hkpSampledHeightFieldShape *HeightFieldShape; // rax
  bool v8; // zf
  hkpSampledHeightFieldShape *v9; // rsi
  unsigned int v10; // r12d
  unsigned int v11; // eax
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  unsigned int v15; // r13d
  unsigned int v16; // ebp
  char v17; // r15
  char v18; // r14
  unsigned int v19; // edi
  int v20; // eax
  float v21; // xmm0_4
  __int64 v22; // r12
  unsigned int v23; // edi
  unsigned int v24; // esi
  unsigned int v25; // r13d
  float v26; // xmm0_4
  float v27; // xmm0_4
  hkResultEnum m_enum; // edi
  int v29; // eax
  hkResultEnum v30; // eax
  int v31; // r9d
  unsigned int v32; // r14d
  unsigned int v33; // r13d
  unsigned int v34; // r12d
  unsigned int v35; // r15d
  int v36; // edi
  __int64 v37; // rbp
  int m_capacityAndFlags; // eax
  int v39; // esi
  unsigned int maxX; // [rsp+40h] [rbp-A8h] BYREF
  unsigned int maxZ; // [rsp+44h] [rbp-A4h] BYREF
  hkpSampledHeightFieldShape *v42; // [rsp+48h] [rbp-A0h]
  hkAabb aabb; // [rsp+50h] [rbp-98h] BYREF
  hkResult result; // [rsp+F0h] [rbp+8h] BYREF
  unsigned int minZ; // [rsp+F8h] [rbp+10h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> *v46; // [rsp+100h] [rbp+18h]
  unsigned int v47; // [rsp+108h] [rbp+20h] BYREF

  v46 = hits;
  v3.m_quad = (__m128)aabbIn->m_max;
  v4 = hits;
  m_childShape = (hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape;
  aabb.m_min = aabbIn->m_min;
  aabb.m_max = (hkVector4f)v3.m_quad;
  hkpTriSampledHeightFieldBvTreeShape::getExtentsForQueryAabb(
    (hkBool *)&result,
    &aabb,
    m_childShape,
    &v47,
    &maxX,
    &minZ,
    &maxZ);
  if ( !LOBYTE(result.m_enum) )
    return;
  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape);
  v8 = this->m_wantAabbRejectionTest.m_bool == 0;
  v9 = HeightFieldShape;
  v42 = HeightFieldShape;
  result.m_enum = v4->m_size;
  if ( v8 )
  {
    v32 = v47;
    v33 = maxX;
    if ( v47 <= maxX )
    {
      v34 = maxZ;
      v35 = minZ;
      do
      {
        if ( v35 <= v34 )
        {
          v36 = 2 * (v32 + (v35 << 15));
          v37 = v34 - v35 + 1;
          do
          {
            if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 4);
            v4->m_data[v4->m_size] = v36;
            m_capacityAndFlags = v4->m_capacityAndFlags;
            ++v4->m_size;
            v39 = v36 | 1;
            if ( v4->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 4);
            v36 += 0x10000;
            v4->m_data[v4->m_size++] = v39;
            --v37;
          }
          while ( v37 );
        }
        ++v32;
      }
      while ( v32 <= v33 );
    }
  }
  else
  {
    v10 = v47;
    v11 = maxX;
    v12 = v9->m_intToFloatScale.m_quad.m128_f32[1];
    v13 = aabb.m_max.m_quad.m128_f32[1];
    v14 = aabb.m_min.m_quad.m128_f32[1];
    v15 = maxZ;
    v16 = minZ;
    v17 = 1;
    v18 = 1;
    if ( v47 > maxX )
    {
LABEL_22:
      v22 = (__int64)v42;
      v23 = v11 + 1;
      if ( v47 <= v11 + 1 )
      {
        v24 = v15 + 1;
        v25 = v47;
        do
        {
          v26 = (*(float (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v22 + 160i64))(v22, v25, v24) * v12;
          if ( v26 > v14 )
            v17 = 0;
          if ( v13 > v26 )
            v18 = 0;
          ++v25;
        }
        while ( v25 <= v23 );
        v4 = v46;
        v15 = maxZ;
      }
      if ( v16 <= v15 + 1 )
      {
        do
        {
          v27 = (*(float (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v22 + 160i64))(v22, v23, v16) * v12;
          if ( v27 > v14 )
            v17 = 0;
          if ( v13 > v27 )
            v18 = 0;
          ++v16;
        }
        while ( v16 <= v15 + 1 );
        v4 = v46;
      }
      if ( v17 || v18 )
      {
        m_enum = result.m_enum;
        v29 = v4->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v29 < result.m_enum )
        {
          v30 = 2 * v29;
          v31 = result.m_enum;
          if ( result.m_enum < v30 )
            v31 = v30;
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, v31, 4);
        }
        v4->m_size = m_enum;
      }
      return;
    }
    do
    {
      if ( minZ <= v15 )
      {
        v19 = 2 * (v10 + (minZ << 15));
        do
        {
          if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 4);
          v4->m_data[v4->m_size] = v19;
          v20 = v4->m_capacityAndFlags;
          if ( ++v4->m_size == (v20 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 4);
          v4->m_data[v4->m_size++] = v19 | 1;
          if ( v17 || v18 )
          {
            v21 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v42->vfptr[10].__vecDelDtor)(
                    v42,
                    v10,
                    v16)
                * v12;
            if ( v21 > v14 )
              v17 = 0;
            if ( v13 > v21 )
              v18 = 0;
          }
          ++v16;
          v19 += 0x10000;
        }
        while ( v16 <= v15 );
        v11 = maxX;
      }
      v16 = minZ;
      ++v10;
    }
    while ( v10 <= v11 );
    if ( v17 || v18 )
    {
      v16 = minZ;
      goto LABEL_22;
    }
  }
}

// File Line: 353
// RVA: 0xCF9C30
void __fastcall hkpTriSampledHeightFieldBvTreeShape::getAabb(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  __int64 v4; // r8

  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_childContainer.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_childContainer.m_childShape,
    localToWorld,
    v4,
    out);
}

// File Line: 363
// RVA: 0xCF9C50
hkBool *__fastcall hkpTriSampledHeightFieldBvTreeShape::castRay(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *output)
{
  hkpSampledHeightFieldShape *HeightFieldShape; // rax

  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkBool *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))HeightFieldShape->vfptr[2].__first_virtual_table_function__)(
    HeightFieldShape,
    result,
    input,
    output);
  return result;
}

// File Line: 372
// RVA: 0xCF9CA0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::castRayWithCollector(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkpSampledHeightFieldShape *HeightFieldShape; // rax

  HeightFieldShape = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkpShapeRayCastInput *, hkpCdBody *, hkpRayHitCollector *))HeightFieldShape->vfptr[3].__vecDelDtor)(
    HeightFieldShape,
    input,
    cdBody,
    collector);
}

// File Line: 385
// RVA: 0xCF9D40
__int64 __fastcall hkpTriSampledHeightFieldBvTreeShape::calcSizeForSpu(
        hkpTriSampledHeightFieldBvTreeShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  unsigned int v4; // eax

  v4 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, __int64))this->m_childContainer.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childContainer.m_childShape,
         input,
         256i64);
  if ( v4 > 0x100 )
    return 0xFFFFFFFFi64;
  this->m_childSize = v4;
  return 80i64;
}

