// File Line: 15
// RVA: 0xD175A0
void __fastcall hkpStorageSampledHeightFieldShape::hkpStorageSampledHeightFieldShape(hkpStorageSampledHeightFieldShape *this, hkpSampledHeightFieldBaseCinfo *info, hkArray<float,hkContainerHeapAllocator> *samples)
{
  hkArray<float,hkContainerHeapAllocator> *v3; // rsi
  hkpStorageSampledHeightFieldShape *v4; // rbx
  signed __int64 v5; // rdi
  signed __int64 v6; // rax
  float *v7; // r11
  float *v8; // r10
  signed __int64 v9; // rdx
  signed __int64 v10; // rcx
  signed __int64 v11; // r8
  unsigned __int64 v12; // r9
  int v13; // eax
  signed __int64 v14; // r10
  signed __int64 v15; // rcx
  signed __int64 v16; // rdx
  int v17; // eax
  int v18; // [rsp+30h] [rbp+8h]

  v3 = samples;
  v4 = this;
  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape((hkpSampledHeightFieldShape *)&this->vfptr, info, 0);
  v5 = 0i64;
  v4->vfptr = (hkBaseObjectVtbl *)&hkpStorageSampledHeightFieldShape::`vftable;
  v4->m_storage.m_data = 0i64;
  v4->m_storage.m_size = 0;
  v4->m_storage.m_capacityAndFlags = 2147483648;
  v4->m_triangleFlip.m_bool = 0;
  if ( (v4->m_storage.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_size )
  {
    if ( v4->m_storage.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * v4->m_storage.m_capacityAndFlags);
    v18 = 4 * v3->m_size;
    v4->m_storage.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                      &v18);
    v4->m_storage.m_capacityAndFlags = v18 / 4;
  }
  v6 = v3->m_size;
  v7 = v4->m_storage.m_data;
  v4->m_storage.m_size = v6;
  v8 = v3->m_data;
  v9 = v6;
  if ( v6 >= 4 )
  {
    v10 = (signed __int64)(v7 + 1);
    v11 = (char *)v8 - (char *)v7;
    v12 = ((unsigned __int64)(v6 - 4) >> 2) + 1;
    v5 = 4 * v12;
    do
    {
      v13 = *(_DWORD *)(v11 + v10 - 4);
      v10 += 16i64;
      *(_DWORD *)(v10 - 20) = v13;
      *(_DWORD *)(v10 - 16) = *(_DWORD *)(v11 + v10 - 16);
      *(_DWORD *)(v10 - 12) = *(_DWORD *)(v11 + v10 - 12);
      *(_DWORD *)(v10 - 8) = *(_DWORD *)(v11 + v10 - 8);
      --v12;
    }
    while ( v12 );
  }
  if ( v5 < v9 )
  {
    v14 = (char *)v8 - (char *)v7;
    v15 = (signed __int64)&v7[v5];
    v16 = v9 - v5;
    do
    {
      v17 = *(_DWORD *)(v15 + v14);
      v15 += 4i64;
      *(_DWORD *)(v15 - 4) = v17;
      --v16;
    }
    while ( v16 );
  }
}

// File Line: 20
// RVA: 0xD172E0
void __fastcall hkpStorageSampledHeightFieldShape::hkpStorageSampledHeightFieldShape(hkpStorageSampledHeightFieldShape *this, hkpSampledHeightFieldShape *hf)
{
  hkArray<float,hkContainerHeapAllocator> *v2; // r12
  hkpSampledHeightFieldShape *v3; // r15
  hkpStorageSampledHeightFieldShape *v4; // rdi
  __int64 v5; // rsi
  int v6; // ebx
  int v7; // er13
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // ebx
  signed __int64 v12; // rdx
  __int64 v13; // rsi
  int *v14; // rbx
  int v15; // er8
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v16; // rbx
  signed __int64 v17; // r14
  __int64 v18; // rsi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v19; // rbx
  signed __int64 v20; // r14
  __int64 v21; // rsi
  int v22; // ebx
  hkVector4f v23; // xmm0
  int v24; // eax
  int v25; // eax
  int v26; // er9
  int v27; // ebp
  __int64 i; // r14
  int v29; // ebx
  __int64 j; // rsi
  __int64 v31; // rcx
  hkResult v32; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1036;
  this->m_userData = 0i64;
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_size = 0;
  this->m_coarseTreeData.m_capacityAndFlags = 2147483648;
  v2 = &this->m_storage;
  v3 = hf;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageSampledHeightFieldShape::`vftable;
  v2->m_data = 0i64;
  v2->m_size = 0;
  v2->m_capacityAndFlags = 2147483648;
  this->m_heightfieldType.m_storage = 0;
  this->m_xRes = hf->m_xRes;
  v4 = this;
  this->m_zRes = hf->m_zRes;
  this->m_coarseness = hf->m_coarseness;
  if ( hf->m_coarseness )
  {
    v5 = hf->m_coarseTreeData.m_size;
    v6 = this->m_coarseTreeData.m_size;
    v7 = v5;
    if ( (signed int)v5 > v6 )
      v7 = this->m_coarseTreeData.m_size;
    v8 = this->m_coarseTreeData.m_capacityAndFlags & 0x3FFFFFFF;
    v32.m_enum = (signed int)v5;
    if ( v8 < (signed int)v5 )
    {
      v9 = 2 * v8;
      v10 = v5;
      if ( (signed int)v5 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_coarseTreeData,
        v10,
        24);
    }
    v11 = v6 - v5 - 1;
    v12 = (signed __int64)&v4->m_coarseTreeData.m_data[v5];
    v13 = v11;
    if ( v11 >= 0 )
    {
      v14 = (int *)(v12 + 12 + 24i64 * v11);
      do
      {
        v15 = *v14;
        *(v14 - 1) = 0;
        if ( v15 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v14 - 3),
            16 * v15);
        *(_QWORD *)(v14 - 3) = 0i64;
        *v14 = 2147483648;
        v14 -= 6;
        --v13;
      }
      while ( v13 >= 0 );
    }
    v16 = v4->m_coarseTreeData.m_data;
    if ( v7 > 0 )
    {
      v17 = (char *)v3->m_coarseTreeData.m_data - (char *)v16;
      v18 = (unsigned int)v7;
      do
      {
        hkpSampledHeightFieldShape::CoarseMinMaxLevel::operator=(
          v16,
          (hkpSampledHeightFieldShape::CoarseMinMaxLevel *)((char *)v16 + v17));
        ++v16;
        --v18;
      }
      while ( v18 );
    }
    v19 = &v4->m_coarseTreeData.m_data[v7];
    if ( v32.m_enum - v7 > 0 )
    {
      v20 = (char *)&v3->m_coarseTreeData.m_data[v7] - (char *)v19;
      v21 = (unsigned int)(v32.m_enum - v7);
      do
      {
        if ( v19 )
          hkpSampledHeightFieldShape::CoarseMinMaxLevel::CoarseMinMaxLevel(
            v19,
            (hkpSampledHeightFieldShape::CoarseMinMaxLevel *)((char *)v19 + v20));
        ++v19;
        --v21;
      }
      while ( v21 );
    }
    v4->m_coarseTreeData.m_size = v32.m_enum;
  }
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkResult *))v3->vfptr[10].__first_virtual_table_function__)(
    v3,
    &v32);
  v22 = v4->m_xRes * v4->m_zRes;
  v4->m_triangleFlip.m_bool = v32.m_enum;
  v4->m_heightCenter = v3->m_heightCenter;
  v4->m_intToFloatScale = v3->m_intToFloatScale;
  v4->m_floatToIntScale = v3->m_floatToIntScale;
  v23.m_quad = (__m128)v3->m_floatToIntOffsetFloorCorrected;
  v4->m_floatToIntOffsetFloorCorrected = (hkVector4f)v23.m_quad;
  v4->m_extents = v3->m_extents;
  v24 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < v22 )
  {
    v25 = 2 * v24;
    v26 = v22;
    if ( v22 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&v32, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v26, 4);
  }
  v27 = 0;
  v2->m_size = v22;
  for ( i = 0i64; v27 < v4->m_zRes; ++i )
  {
    v29 = 0;
    for ( j = 0i64; v29 < v4->m_xRes; LODWORD(v2->m_data[v31]) = v23.m_quad.m128_i32[0] )
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v3->vfptr[10].__vecDelDtor)(
        v3,
        (unsigned int)v29,
        (unsigned int)v27);
      v31 = j + i * v4->m_xRes;
      ++v29;
      ++j;
    }
    ++v27;
  }
}

// File Line: 51
// RVA: 0xD17B80
signed __int64 __fastcall hkpStorageSampledHeightFieldShape::calcSizeForSpu(hkpStorageSampledHeightFieldShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  signed __int64 result; // rax

  result = 176i64;
  if ( spuBufferSizeLeft < 176 )
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 67
// RVA: 0xD17700
void __fastcall hkpStorageSampledHeightFieldShape::collideSpheres(hkpStorageSampledHeightFieldShape *this, hkpHeightFieldShape::CollideSpheresInput *input, hkVector4f *outputArray)
{
  hkSphere *v3; // r14
  int v4; // er12
  hkVector4f *v5; // rdi
  hkpStorageSampledHeightFieldShape *v6; // rbx
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128i v9; // xmm1
  __m128i v10; // xmm1
  signed int v11; // ecx
  signed int v12; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  __m128 v15; // xmm13
  float v16; // xmm7_4
  float v17; // xmm8_4
  hkBaseObjectVtbl *v18; // rax
  __m128 v19; // xmm10
  unsigned int v20; // er15
  hkBaseObjectVtbl *v21; // rax
  float v22; // xmm9_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  hkBaseObjectVtbl *v26; // rax
  float v27; // xmm0_4
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  char v35; // [rsp+118h] [rbp+10h]
  float v36; // [rsp+120h] [rbp+18h]
  int v37; // [rsp+128h] [rbp+20h]

  v3 = input->m_spheres;
  v4 = input->m_numSpheres - 1;
  v5 = outputArray;
  v37 = v4;
  v6 = this;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      *v5 = (hkVector4f)_xmm;
      v7 = _mm_mul_ps(v3->m_pos.m_quad, v6->m_floatToIntScale.m_quad);
      v8 = _mm_mul_ps(
             _mm_add_ps(v3->m_pos.m_quad, v6->m_floatToIntOffsetFloorCorrected.m_quad),
             v6->m_floatToIntScale.m_quad);
      v9 = _mm_xor_si128(
             (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v8),
             _mm_cvttps_epi32(v8));
      v10 = _mm_packs_epi32(v9, v9);
      if ( v10.m128i_u16[0] >= v6->m_xRes - 1 || v10.m128i_u16[2] >= v6->m_zRes - 1 )
        goto LABEL_22;
      v11 = 0;
      v12 = 0;
      LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(v7, v7, 0);
      if ( COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170)) < 0.0 )
        v11 = 1;
      if ( v13 < 0.0 )
        v12 = 1;
      if ( v12 | v11 )
        goto LABEL_22;
      v14 = (float)v10.m128i_u16[0];
      v15 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[2]);
      v16 = v7.m128_f32[0] - v14;
      v17 = COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170)) - v15.m128_f32[0];
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, char *))v6->vfptr[10].__first_virtual_table_function__)(
        v6,
        &v35);
      v18 = v6->vfptr;
      if ( !v35 )
        break;
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v18[10].__vecDelDtor)(
        v6,
        v10.m128i_u16[0],
        v10.m128i_u16[2]);
      v19 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[0]);
      v20 = v10.m128i_u16[0];
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(
        v6,
        (unsigned int)v10.m128i_u16[0] + 1,
        (unsigned int)v10.m128i_u16[2] + 1);
      v21 = v6->vfptr;
      if ( v16 > v17 )
      {
        ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v21[10].__vecDelDtor)(
          v6,
          (unsigned int)v10.m128i_u16[0] + 1,
          v10.m128i_u16[2]);
        v4 = v37;
        v22 = v14 - v14;
        v23 = v14 - v14;
        v24 = (float)((float)(v14 - v14) * v17) + v14;
        goto LABEL_16;
      }
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v21[10].__vecDelDtor)(
        v6,
        v10.m128i_u16[0],
        (unsigned int)v10.m128i_u16[2] + 1);
      v4 = v37;
      v25 = v14 - v14;
      v5->m_quad.m128_i32[0] = LODWORD(v25) ^ _xmm[0];
      v5->m_quad.m128_i32[2] = LODWORD(v25) ^ _xmm[0];
      v36 = (float)((float)(v25 * v17) + v19.m128_f32[0]) + (float)(v25 * v16);
LABEL_18:
      v28 = _mm_mul_ps(v6->m_floatToIntScale.m_quad, v5->m_quad);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v32 = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v30, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                  _mm_mul_ps(*(__m128 *)_xmm, v31))),
              v28);
      *v5 = (hkVector4f)v32;
      if ( v6->m_useProjectionBasedHeight.m_bool )
      {
        v34 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    v7,
                    _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)(signed int)v20), v15),
                      _mm_unpacklo_ps(v19, (__m128)0i64))),
                  v6->m_intToFloatScale.m_quad),
                v32);
        v33 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                _mm_shuffle_ps(v34, v34, 170));
      }
      else
      {
        v33 = _mm_mul_ps(
                _mm_sub_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps((__m128)LODWORD(v36), (__m128)LODWORD(v36), 0)),
                _mm_shuffle_ps(v6->m_intToFloatScale.m_quad, v6->m_intToFloatScale.m_quad, 85));
      }
      v5->m_quad = _mm_shuffle_ps(
                     v32,
                     _mm_unpackhi_ps(v32, _mm_sub_ps(v33, _mm_shuffle_ps(v3->m_pos.m_quad, v3->m_pos.m_quad, 255))),
                     196);
LABEL_22:
      ++v5;
      ++v3;
      v37 = --v4;
      if ( v4 < 0 )
        return;
    }
    v20 = v10.m128i_u16[0] + 1;
    ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v18[10].__vecDelDtor)(
      v6,
      v20,
      v10.m128i_u16[2]);
    v19 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[0]);
    ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(
      v6,
      v10.m128i_u16[0],
      (unsigned int)v10.m128i_u16[2] + 1);
    v26 = v6->vfptr;
    if ( (float)(v17 + v16) <= 1.0 )
    {
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v26[10].__vecDelDtor)(
        v6,
        v10.m128i_u16[0],
        v10.m128i_u16[2]);
      v22 = v14 - v14;
      v23 = v14 - v14;
      v24 = (float)((float)(v14 - v14) * v17) + v14;
LABEL_16:
      v5->m_quad.m128_i32[2] = LODWORD(v22) ^ _xmm[0];
      v36 = v24 + (float)(v23 * v16);
    }
    else
    {
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v26[10].__vecDelDtor)(
        v6,
        v20,
        (unsigned int)v10.m128i_u16[2] + 1);
      v27 = v14 - v14;
      v23 = (float)v10.m128i_u16[0] - (float)v10.m128i_u16[0];
      v5->m_quad.m128_i32[2] = LODWORD(v27) ^ _xmm[0];
      v36 = (float)((float)(v16 - 1.0) * v23) + (float)((float)(v27 * v17) + v19.m128_f32[0]);
    }
    v5->m_quad.m128_i32[0] = LODWORD(v23) ^ _xmm[0];
    goto LABEL_18;
  }
}

