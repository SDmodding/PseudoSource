// File Line: 24
// RVA: 0xCF9390
void __fastcall hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(hkpTriSampledHeightFieldBvTreeShape *this, hkpTriSampledHeightFieldCollection *c, hkBool doAabbRejection)
{
  hkpTriSampledHeightFieldBvTreeShape *v3; // rbx
  char v4; // [rsp+40h] [rbp+18h]

  v4 = doAabbRejection.m_bool;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1031;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 1;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldBvTreeShape::`vftable;
  this->m_childContainer.m_childShape = (hkpShape *)&c->vfptr;
  this->m_childContainer.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  hkReferencedObject::addReference((hkReferencedObject *)&c->vfptr);
  v3->m_wantAabbRejectionTest.m_bool = v4;
}

// File Line: 31
// RVA: 0xCF9CF0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape(hkpTriSampledHeightFieldBvTreeShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpTriSampledHeightFieldBvTreeShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpBvTreeShape::hkpBvTreeShape((hkpBvTreeShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpTriSampledHeightFieldBvTreeShape::`vftable;
  v2->m_childContainer.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( v3 )
  {
    v2->m_type.m_storage = 7;
    v2->m_bvTreeType.m_storage = 1;
  }
}

// File Line: 43
// RVA: 0xCF93F0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::queryObb(hkpTriSampledHeightFieldBvTreeShape *this, hkTransformf *obbTransform, hkVector4f *obbExtent, float tolerance, hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  __m128 v5; // xmm2
  hkBaseObjectVtbl *v6; // rax
  __m128 v7; // xmm3
  __m128 v8; // [rsp+20h] [rbp-28h]
  __m128 v9; // [rsp+30h] [rbp-18h]

  v5 = obbExtent->m_quad;
  v6 = this->vfptr;
  v7 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), obbTransform->m_rotation.m_col1.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), obbTransform->m_rotation.m_col0.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), obbTransform->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0)));
  v9 = _mm_add_ps(obbTransform->m_translation.m_quad, v7);
  v8 = _mm_add_ps(
         _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v7),
         obbTransform->m_translation.m_quad);
  ((void (__fastcall *)(hkpTriSampledHeightFieldBvTreeShape *, __m128 *, hkArray<unsigned int,hkContainerHeapAllocator> *))v6[8].__first_virtual_table_function__)(
    this,
    &v8,
    hits);
}

// File Line: 60
// RVA: 0xCF9D80
hkBool *__usercall hkpTriSampledHeightFieldBvTreeShape::getExtentsForQueryAabb@<rax>(hkBool *result@<rcx>, hkAabb *aabb@<rdx>, hkpTriSampledHeightFieldCollection *collection@<r8>, unsigned int *minX@<r9>, __int128 a5@<xmm8>, unsigned int *maxX, unsigned int *minZ, unsigned int *maxZ)
{
  hkBool *v8; // rsi
  unsigned int *v9; // r15
  hkAabb *v10; // rdi
  hkpTriSampledHeightFieldCollection *v11; // rbx
  hkpSampledHeightFieldShape *v12; // r14
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __int64 v15; // r8
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  __m128 v21; // xmm9
  int v22; // eax
  __m128 v23; // xmm5
  __m128i v24; // xmm6
  int v25; // eax
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128i v30; // xmm1
  __m128i v31; // xmm7
  __int64 v32; // xmm1_8
  unsigned __int16 v33; // cx
  unsigned __int16 v34; // r9
  unsigned __int16 v35; // dx
  unsigned __int16 v36; // ax
  __int64 v38; // [rsp+20h] [rbp-88h]
  __m128 v39; // [rsp+30h] [rbp-78h]
  __m128 v40; // [rsp+40h] [rbp-68h]
  __int128 v41; // [rsp+60h] [rbp-48h]

  v8 = result;
  v9 = minX;
  v10 = aabb;
  v11 = collection;
  v12 = hkpTriSampledHeightFieldCollection::getHeightFieldShape(collection);
  v13 = _mm_shuffle_ps((__m128)LODWORD(v11->m_radius), (__m128)LODWORD(v11->m_radius), 0);
  v14 = _mm_sub_ps(v10->m_min.m_quad, v13);
  v10->m_max.m_quad = _mm_add_ps(v10->m_max.m_quad, v13);
  v10->m_min.m_quad = v14;
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkVector4f *, __int64, __m128 *))v12->vfptr[2].__vecDelDtor)(
    v12,
    &transform,
    v15,
    &v39);
  v16 = _mm_and_ps(_mm_cmpltps(v10->m_min.m_quad, v39), *(__m128 *)&hkVector4fComparison_maskToComparison_344[20]);
  v17 = _mm_or_ps(_mm_andnot_ps(v16, v10->m_min.m_quad), _mm_and_ps(v39, v16));
  v18 = v40;
  v19 = v40;
  v10->m_min.m_quad = v17;
  v20 = _mm_and_ps(_mm_cmpltps(v19, v10->m_max.m_quad), *(__m128 *)&hkVector4fComparison_maskToComparison_344[20]);
  v21 = _mm_or_ps(_mm_andnot_ps(v20, v10->m_max.m_quad), _mm_and_ps(v18, v20));
  v10->m_max.m_quad = v21;
  if ( _mm_movemask_ps(_mm_cmpleps(v21, v17)) & 7 )
  {
    v8->m_bool = 0;
  }
  else
  {
    v22 = v12->m_xRes;
    v23 = v12->m_floatToIntOffsetFloorCorrected.m_quad;
    v8->m_bool = 1;
    v24 = _mm_cvtsi32_si128(v22 - 2);
    v25 = v12->m_zRes;
    v41 = a5;
    v26 = v23;
    v27 = _mm_unpacklo_ps(
            _mm_unpacklo_ps(_mm_cvtepi32_ps(v24), (__m128)COERCE_UNSIGNED_INT((float)(v25 - 2))),
            (__m128)0i64);
    v28 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(v23, v21), v12->m_floatToIntScale.m_quad), v27), (__m128)0i64);
    v29 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(v26, v17), v12->m_floatToIntScale.m_quad), v27), (__m128)0i64);
    v30 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v29),
              _mm_cvttps_epi32(v29)),
            (__m128i)_xmm);
    v31 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v28),
              _mm_cvttps_epi32(v28)),
            (__m128i)_xmm);
    v32 = (unsigned __int128)_mm_add_epi16(
                               _mm_packs_epi32(v30, v30),
                               (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2);
    v33 = v32;
    v34 = WORD2(v32);
    v38 = (unsigned __int128)_mm_add_epi16(
                               _mm_packs_epi32(v31, v31),
                               (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2);
    v35 = v38;
    if ( (unsigned __int16)v32 < (unsigned __int16)v38 )
      v35 = v32;
    if ( (unsigned __int16)v32 < (unsigned __int16)v38 )
      v33 = v38;
    *v9 = v35;
    *maxX = v33;
    v36 = WORD2(v38);
    if ( WORD2(v32) < WORD2(v38) )
      v36 = WORD2(v32);
    if ( WORD2(v32) < WORD2(v38) )
      v34 = WORD2(v38);
    *minZ = v36;
    *maxZ = v34;
  }
  return v8;
}( WORD2(v32) < WORD2

// File Line: 129
// RVA: 0xCF98C0
__int64 __usercall hkpTriSampledHeightFieldBvTreeShape::queryAabbImpl@<rax>(hkpTriSampledHeightFieldBvTreeShape *this@<rcx>, hkAabb *aabbIn@<rdx>, unsigned int *hits@<r8>, int maxNumKeys@<r9d>, float a5@<xmm0>)
{
  hkpTriSampledHeightFieldCollection *v5; // rbx
  __int64 v6; // rbp
  hkpTriSampledHeightFieldBvTreeShape *v7; // rsi
  unsigned int *v8; // r14
  hkVector4f v9; // xmm2
  unsigned int v11; // edi
  hkpSampledHeightFieldShape *v12; // rax
  __int64 v13; // rbx
  __int64 v14; // r9
  float v15; // xmm6_4
  unsigned int v16; // er8
  float v17; // xmm7_4
  float v18; // xmm8_4
  unsigned int v19; // er15
  unsigned int v20; // edx
  char v21; // r13
  unsigned int v22; // ecx
  char v23; // r12
  int v24; // esi
  unsigned int v25; // ebp
  unsigned int v26; // ebx
  unsigned int v27; // esi
  unsigned int v28; // esi
  __int64 v29; // r14
  unsigned int v30; // er8
  unsigned int v31; // er11
  unsigned int v32; // er10
  unsigned int v33; // er9
  int v34; // ecx
  __int64 v35; // rdx
  unsigned int maxZ; // [rsp+40h] [rbp-A8h]
  unsigned int minX; // [rsp+44h] [rbp-A4h]
  unsigned int maxX; // [rsp+48h] [rbp-A0h]
  unsigned int v39; // [rsp+4Ch] [rbp-9Ch]
  hkpSampledHeightFieldShape *v40; // [rsp+50h] [rbp-98h]
  hkAabb aabb; // [rsp+60h] [rbp-88h]
  unsigned int v42; // [rsp+F0h] [rbp+8h]
  unsigned int minZ; // [rsp+F8h] [rbp+10h]

  v5 = (hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape;
  v6 = maxNumKeys;
  v7 = this;
  v8 = hits;
  v9.m_quad = _mm_max_ps(_mm_sub_ps(aabbIn->m_max.m_quad, v5->m_triangleExtrusion.m_quad), aabbIn->m_max.m_quad);
  aabb.m_min.m_quad = _mm_min_ps(_mm_sub_ps(aabbIn->m_min.m_quad, v5->m_triangleExtrusion.m_quad), aabbIn->m_min.m_quad);
  aabb.m_max = (hkVector4f)v9.m_quad;
  hkpTriSampledHeightFieldBvTreeShape::getExtentsForQueryAabb((hkBool *)&v42, &aabb, v5, &minX, &maxX, &minZ, &maxZ);
  if ( !(_BYTE)v42 )
    return 0i64;
  v11 = 0;
  v42 = 0;
  v12 = hkpTriSampledHeightFieldCollection::getHeightFieldShape(v5);
  v13 = 0i64;
  v14 = (__int64)v12;
  v40 = v12;
  if ( !v7->m_wantAabbRejectionTest.m_bool )
  {
    v30 = minX;
    v31 = maxX;
    if ( minX <= maxX )
    {
      v32 = maxZ;
      v33 = minZ;
      do
      {
        if ( v33 <= v32 )
        {
          v34 = 2 * (v30 + (v33 << 15));
          v35 = v32 - v33 + 1;
          do
          {
            if ( v13 < v6 )
            {
              v8[v13++] = v34;
              ++v11;
              if ( v13 < v6 )
              {
                ++v11;
                v8[++v13 - 1] = v34 | 1;
              }
            }
            v34 += 0x10000;
            --v35;
          }
          while ( v35 );
        }
        ++v30;
      }
      while ( v30 <= v31 );
    }
    return v11;
  }
  v15 = v12->m_intToFloatScale.m_quad.m128_f32[1];
  v16 = maxX;
  v17 = aabb.m_max.m_quad.m128_f32[1];
  v18 = aabb.m_min.m_quad.m128_f32[1];
  v19 = minZ;
  v20 = maxZ;
  v21 = 1;
  v22 = minX;
  v39 = minX;
  v23 = 1;
  if ( minX <= maxX )
  {
    do
    {
      if ( minZ <= v20 )
      {
        v24 = 2 * (v22 + (minZ << 15));
        do
        {
          if ( v13 < v6 )
          {
            v8[v13++] = v24;
            ++v11;
            if ( v13 < v6 )
            {
              ++v11;
              v8[++v13 - 1] = v24 | 1;
            }
          }
          if ( v21 || v23 )
          {
            (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v14 + 160i64))(v14, v22, v19);
            v22 = v39;
            v20 = maxZ;
            a5 = a5 * v15;
            v14 = (__int64)v40;
            if ( a5 > v18 )
              v21 = 0;
            if ( v17 > a5 )
              v23 = 0;
          }
          ++v19;
          v24 += 0x10000;
        }
        while ( v19 <= v20 );
        v16 = maxX;
        v42 = v11;
      }
      v19 = minZ;
      v39 = ++v22;
    }
    while ( v22 <= v16 );
    if ( !v21 && !v23 )
      return v11;
    v19 = minZ;
  }
  v25 = minX;
  v26 = v16 + 1;
  if ( minX <= v16 + 1 )
  {
    v27 = v20 + 1;
    do
    {
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v14 + 160i64))(v14, v25, v27);
      v14 = (__int64)v40;
      a5 = a5 * v15;
      if ( a5 > v18 )
        v21 = 0;
      if ( v17 > a5 )
        v23 = 0;
      ++v25;
    }
    while ( v25 <= v26 );
    v11 = v42;
  }
  v28 = maxZ + 1;
  if ( v19 <= maxZ + 1 )
  {
    v29 = (__int64)v40;
    do
    {
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64))(*(_QWORD *)v29 + 160i64))(v29, v26, v19, v14);
      a5 = a5 * v15;
      if ( a5 > v18 )
        v21 = 0;
      if ( v17 > a5 )
        v23 = 0;
      ++v19;
    }
    while ( v19 <= v28 );
    v11 = v42;
  }
  if ( v21 || v23 )
    return 0i64;
  return v11;
}

// File Line: 248
// RVA: 0xCF94A0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::queryAabb(hkpTriSampledHeightFieldBvTreeShape *this, hkAabb *aabbIn, hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  hkArray<unsigned int,hkContainerHeapAllocator> *v5; // rbx
  hkpTriSampledHeightFieldCollection *v6; // r8
  hkpTriSampledHeightFieldBvTreeShape *v7; // rdi
  hkpSampledHeightFieldShape *v8; // rax
  bool v9; // zf
  hkpSampledHeightFieldShape *v10; // rsi
  unsigned int v11; // er12
  unsigned int v12; // eax
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  unsigned int v16; // er13
  unsigned int v17; // ebp
  char v18; // r15
  char v19; // r14
  int v20; // edi
  int v21; // eax
  __int64 v22; // r12
  unsigned int v23; // edi
  unsigned int v24; // esi
  unsigned int v25; // er13
  hkResultEnum v26; // edi
  int v27; // eax
  hkResultEnum v28; // eax
  int v29; // er9
  unsigned int v30; // er14
  unsigned int v31; // er13
  unsigned int v32; // er12
  unsigned int v33; // er15
  int v34; // edi
  __int64 v35; // rbp
  int v36; // eax
  int v37; // esi
  unsigned int maxX; // [rsp+40h] [rbp-A8h]
  unsigned int maxZ; // [rsp+44h] [rbp-A4h]
  hkpSampledHeightFieldShape *v40; // [rsp+48h] [rbp-A0h]
  hkAabb aabb; // [rsp+50h] [rbp-98h]
  hkResult result; // [rsp+F0h] [rbp+8h]
  unsigned int minZ; // [rsp+F8h] [rbp+10h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v44; // [rsp+100h] [rbp+18h]
  unsigned int v45; // [rsp+108h] [rbp+20h]

  v44 = hits;
  v3.m_quad = (__m128)aabbIn->m_min;
  v4.m_quad = (__m128)aabbIn->m_max;
  v5 = hits;
  v6 = (hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape;
  v7 = this;
  aabb.m_min = aabbIn->m_min;
  aabb.m_max = (hkVector4f)v4.m_quad;
  hkpTriSampledHeightFieldBvTreeShape::getExtentsForQueryAabb((hkBool *)&result, &aabb, v6, &v45, &maxX, &minZ, &maxZ);
  if ( !LOBYTE(result.m_enum) )
    return;
  v8 = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)v7->m_childContainer.m_childShape);
  v9 = v7->m_wantAabbRejectionTest.m_bool == 0;
  v10 = v8;
  v40 = v8;
  result.m_enum = v5->m_size;
  if ( v9 )
  {
    v30 = v45;
    v31 = maxX;
    if ( v45 <= maxX )
    {
      v32 = maxZ;
      v33 = minZ;
      do
      {
        if ( v33 <= v32 )
        {
          v34 = 2 * (v30 + (v33 << 15));
          v35 = v32 - v33 + 1;
          do
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
            v5->m_data[v5->m_size] = v34;
            v36 = v5->m_capacityAndFlags;
            ++v5->m_size;
            v37 = v34 | 1;
            if ( v5->m_size == (v36 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
            v34 += 0x10000;
            v5->m_data[v5->m_size++] = v37;
            --v35;
          }
          while ( v35 );
        }
        ++v30;
      }
      while ( v30 <= v31 );
    }
  }
  else
  {
    v11 = v45;
    v12 = maxX;
    v13 = v10->m_intToFloatScale.m_quad.m128_f32[1];
    v14 = aabb.m_max.m_quad.m128_f32[1];
    v15 = aabb.m_min.m_quad.m128_f32[1];
    v16 = maxZ;
    v17 = minZ;
    v18 = 1;
    v19 = 1;
    if ( v45 > maxX )
    {
LABEL_22:
      v22 = (__int64)v40;
      v23 = v12 + 1;
      if ( v45 <= v12 + 1 )
      {
        v24 = v16 + 1;
        v25 = v45;
        do
        {
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v22 + 160i64))(v22, v25, v24);
          v3.m_quad.m128_f32[0] = v3.m_quad.m128_f32[0] * v13;
          if ( v3.m_quad.m128_f32[0] > v15 )
            v18 = 0;
          if ( v14 > v3.m_quad.m128_f32[0] )
            v19 = 0;
          ++v25;
        }
        while ( v25 <= v23 );
        v5 = v44;
        v16 = maxZ;
      }
      if ( v17 <= v16 + 1 )
      {
        do
        {
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v22 + 160i64))(v22, v23, v17);
          v3.m_quad.m128_f32[0] = v3.m_quad.m128_f32[0] * v13;
          if ( v3.m_quad.m128_f32[0] > v15 )
            v18 = 0;
          if ( v14 > v3.m_quad.m128_f32[0] )
            v19 = 0;
          ++v17;
        }
        while ( v17 <= v16 + 1 );
        v5 = v44;
      }
      if ( v18 || v19 )
      {
        v26 = result.m_enum;
        v27 = v5->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v27 < result.m_enum )
        {
          v28 = 2 * v27;
          v29 = result.m_enum;
          if ( result.m_enum < v28 )
            v29 = v28;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v29, 4);
        }
        v5->m_size = v26;
      }
      return;
    }
    do
    {
      if ( minZ <= v16 )
      {
        v20 = 2 * (v11 + (minZ << 15));
        do
        {
          if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
          v5->m_data[v5->m_size] = v20;
          v21 = v5->m_capacityAndFlags;
          if ( ++v5->m_size == (v21 & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
          v5->m_data[v5->m_size++] = v20 | 1;
          if ( v18 || v19 )
          {
            ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v40->vfptr[10].__vecDelDtor)(
              v40,
              v11,
              v17);
            v3.m_quad.m128_f32[0] = v3.m_quad.m128_f32[0] * v13;
            if ( v3.m_quad.m128_f32[0] > v15 )
              v18 = 0;
            if ( v14 > v3.m_quad.m128_f32[0] )
              v19 = 0;
          }
          ++v17;
          v20 += 0x10000;
        }
        while ( v17 <= v16 );
        v12 = maxX;
      }
      v17 = minZ;
      ++v11;
    }
    while ( v11 <= v12 );
    if ( v18 || v19 )
    {
      v17 = minZ;
      goto LABEL_22;
    }
  }
}

// File Line: 353
// RVA: 0xCF9C30
void __usercall hkpTriSampledHeightFieldBvTreeShape::getAabb(hkpTriSampledHeightFieldBvTreeShape *this@<rcx>, hkTransformf *localToWorld@<rdx>, float tolerance@<xmm2>, hkAabb *out@<r9>, __int64 a5@<r8>)
{
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_childContainer.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_childContainer.m_childShape,
    localToWorld,
    a5,
    out);
}

// File Line: 363
// RVA: 0xCF9C50
hkBool *__fastcall hkpTriSampledHeightFieldBvTreeShape::castRay(hkpTriSampledHeightFieldBvTreeShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *output)
{
  hkpShapeRayCastOutput *v4; // rbx
  hkpShapeRayCastInput *v5; // rdi
  hkBool *v6; // rsi
  hkpSampledHeightFieldShape *v7; // rax

  v4 = output;
  v5 = input;
  v6 = result;
  v7 = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkBool *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v7->vfptr[2].__first_virtual_table_function__)(
    v7,
    v6,
    v5,
    v4);
  return v6;
}

// File Line: 372
// RVA: 0xCF9CA0
void __fastcall hkpTriSampledHeightFieldBvTreeShape::castRayWithCollector(hkpTriSampledHeightFieldBvTreeShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpRayHitCollector *v4; // rbx
  hkpCdBody *v5; // rdi
  hkpShapeRayCastInput *v6; // rsi
  hkpSampledHeightFieldShape *v7; // rax

  v4 = collector;
  v5 = cdBody;
  v6 = input;
  v7 = hkpTriSampledHeightFieldCollection::getHeightFieldShape((hkpTriSampledHeightFieldCollection *)this->m_childContainer.m_childShape);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkpShapeRayCastInput *, hkpCdBody *, hkpRayHitCollector *))v7->vfptr[3].__vecDelDtor)(
    v7,
    v6,
    v5,
    v4);
}

// File Line: 385
// RVA: 0xCF9D40
signed __int64 __fastcall hkpTriSampledHeightFieldBvTreeShape::calcSizeForSpu(hkpTriSampledHeightFieldBvTreeShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpTriSampledHeightFieldBvTreeShape *v3; // rbx
  unsigned int v4; // eax

  v3 = this;
  v4 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, signed __int64))this->m_childContainer.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childContainer.m_childShape,
         input,
         256i64);
  if ( v4 > 0x100 )
    return 0xFFFFFFFFi64;
  v3->m_childSize = v4;
  return 80i64;
}

