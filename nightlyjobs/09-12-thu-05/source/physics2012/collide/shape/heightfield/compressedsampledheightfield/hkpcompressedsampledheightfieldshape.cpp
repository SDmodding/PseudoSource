// File Line: 15
// RVA: 0xCF8BC0
void __fastcall hkpCompressedSampledHeightFieldShape::hkpCompressedSampledHeightFieldShape(hkpCompressedSampledHeightFieldShape *this, hkpSampledHeightFieldBaseCinfo *info, hkArray<unsigned short,hkContainerHeapAllocator> *samples, float quantizationOffset, float quantizationScale)
{
  hkArray<unsigned short,hkContainerHeapAllocator> *v5; // rdi
  hkpCompressedSampledHeightFieldShape *v6; // rbx
  int v7; // er8
  __int64 v8; // rax
  unsigned __int16 *v9; // rcx
  __int64 v10; // rdx
  char *v11; // r8
  unsigned __int16 v12; // ax
  float v13; // xmm0_4
  int v14; // [rsp+58h] [rbp+20h]

  v5 = samples;
  v6 = this;
  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(
    (hkpSampledHeightFieldShape *)&this->vfptr,
    info,
    HEIGHTFIELD_COMPRESSED);
  v6->vfptr = (hkBaseObjectVtbl *)&hkpCompressedSampledHeightFieldShape::`vftable';
  v6->m_storage.m_capacityAndFlags = 2147483648;
  v6->m_storage.m_data = 0i64;
  v6->m_storage.m_size = 0;
  v6->m_triangleFlip.m_bool = 0;
  v7 = v6->m_storage.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v5->m_size )
  {
    if ( v6->m_storage.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_storage.m_data,
        2 * v7);
    v14 = 2 * v5->m_size;
    v6->m_storage.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                 &v14);
    v6->m_storage.m_capacityAndFlags = v14 / 2;
  }
  v8 = v5->m_size;
  v9 = v6->m_storage.m_data;
  v6->m_storage.m_size = v8;
  v10 = v8;
  if ( (signed int)v8 > 0 )
  {
    v11 = (char *)((char *)v5->m_data - (char *)v9);
    do
    {
      v12 = *(unsigned __int16 *)((char *)v9 + (_QWORD)v11);
      ++v9;
      *(v9 - 1) = v12;
      --v10;
    }
    while ( v10 );
  }
  v13 = quantizationScale;
  v6->m_offset = quantizationOffset;
  v6->m_scale = v13;
}

// File Line: 22
// RVA: 0xCF8820
void __fastcall hkpCompressedSampledHeightFieldShape::hkpCompressedSampledHeightFieldShape(hkpCompressedSampledHeightFieldShape *this, hkpSampledHeightFieldShape *hf)
{
  __int64 v2; // r15
  hkArray<unsigned short,hkContainerHeapAllocator> *v3; // r12
  hkpSampledHeightFieldShape *v4; // r14
  hkpCompressedSampledHeightFieldShape *v5; // rbx
  int v6; // edi
  __int64 v7; // r13
  int v8; // er12
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // edi
  __int64 v13; // rsi
  int *v14; // rdi
  int v15; // er8
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v16; // rdi
  signed __int64 v17; // r15
  __int64 v18; // rsi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v19; // rdi
  signed __int64 v20; // r15
  __int64 v21; // rsi
  int v22; // edi
  hkVector4f v23; // xmm0
  int v24; // eax
  int v25; // eax
  int v26; // er9
  float v27; // xmm7_4
  float v28; // xmm6_4
  int v29; // esi
  int v30; // edi
  bool v31; // zf
  bool v32; // sf
  int v33; // esi
  int v34; // edi
  __int64 i; // rbp
  unsigned __int16 *v36; // rax
  __int64 v37; // rcx
  hkResult result; // [rsp+90h] [rbp+8h]
  float v39; // [rsp+98h] [rbp+10h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1036;
  v2 = 0i64;
  this->m_userData = 0i64;
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_size = 0;
  this->m_coarseTreeData.m_capacityAndFlags = 2147483648;
  v3 = &this->m_storage;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCompressedSampledHeightFieldShape::`vftable';
  v3->m_data = 0i64;
  v3->m_size = 0;
  v3->m_capacityAndFlags = 2147483648;
  this->m_heightfieldType.m_storage = 1;
  this->m_xRes = hf->m_xRes;
  v4 = hf;
  this->m_zRes = hf->m_zRes;
  v5 = this;
  this->m_coarseness = hf->m_coarseness;
  if ( hf->m_coarseness )
  {
    v6 = this->m_coarseTreeData.m_size;
    v7 = hf->m_coarseTreeData.m_size;
    v8 = hf->m_coarseTreeData.m_size;
    if ( (signed int)v7 > v6 )
      v8 = this->m_coarseTreeData.m_size;
    v9 = this->m_coarseTreeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < (signed int)v7 )
    {
      v10 = 2 * v9;
      v11 = v7;
      if ( (signed int)v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_coarseTreeData,
        v11,
        24);
    }
    v12 = v6 - v7 - 1;
    v13 = v12;
    if ( v12 >= 0 )
    {
      v14 = &v5->m_coarseTreeData.m_data[v7].m_minMaxData.m_capacityAndFlags + 6 * v12;
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
    v16 = v5->m_coarseTreeData.m_data;
    if ( v8 > 0 )
    {
      v17 = (char *)v4->m_coarseTreeData.m_data - (char *)v16;
      v18 = (unsigned int)v8;
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
    v19 = &v5->m_coarseTreeData.m_data[v8];
    if ( (signed int)v7 - v8 > 0 )
    {
      v20 = (char *)&v4->m_coarseTreeData.m_data[v8] - (char *)v19;
      v21 = (unsigned int)(v7 - v8);
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
    v5->m_coarseTreeData.m_size = v7;
    v3 = &v5->m_storage;
    v2 = 0i64;
  }
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkResult *))v4->vfptr[10].__first_virtual_table_function__)(
    v4,
    &result);
  v22 = v5->m_xRes * v5->m_zRes;
  v5->m_triangleFlip.m_bool = result.m_enum;
  v5->m_heightCenter = v4->m_heightCenter;
  v5->m_intToFloatScale = v4->m_intToFloatScale;
  v5->m_floatToIntScale = v4->m_floatToIntScale;
  v23.m_quad = (__m128)v4->m_floatToIntOffsetFloorCorrected;
  v5->m_floatToIntOffsetFloorCorrected = (hkVector4f)v23.m_quad;
  v5->m_extents = v4->m_extents;
  v24 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < v22 )
  {
    v25 = 2 * v24;
    v26 = v22;
    if ( v22 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v26, 2);
  }
  v27 = FLOAT_3_40282e38;
  v28 = FLOAT_N3_40282e38;
  v3->m_size = v22;
  v29 = v2;
  if ( v5->m_zRes > 0 )
  {
    do
    {
      v30 = v2;
      if ( v5->m_xRes > 0 )
      {
        do
        {
          ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v4->vfptr[10].__vecDelDtor)(
            v4,
            (unsigned int)v30++,
            (unsigned int)v29);
          v39 = v28;
          v27 = fminf(v23.m_quad.m128_f32[0], v27);
          result.m_enum = (hkResultEnum)LODWORD(v23.m_quad.m128_f32[0]);
          v28 = fmaxf(v23.m_quad.m128_f32[0], v28);
        }
        while ( v30 < v5->m_xRes );
      }
      ++v29;
    }
    while ( v29 < v5->m_zRes );
  }
  v31 = v5->m_zRes == 0;
  v32 = v5->m_zRes < 0;
  v5->m_offset = v27;
  v33 = v2;
  v5->m_scale = (float)(v28 - v27) * 0.000015259022;
  if ( !v32 && !v31 )
  {
    do
    {
      v34 = 0;
      for ( i = 0i64; v34 < v5->m_xRes; v36[v37] = (signed int)*(float *)&result.m_enum )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v4->vfptr[10].__vecDelDtor)(
          v4,
          (unsigned int)v34,
          (unsigned int)v33);
        v36 = v3->m_data;
        v37 = i + v2 * v5->m_xRes;
        ++v34;
        ++i;
        *(float *)&result.m_enum = (float)(v23.m_quad.m128_f32[0] - v5->m_offset) / v5->m_scale;
        LODWORD(v23.m_quad.m128_f32[0]) = result;
      }
      ++v33;
      ++v2;
    }
    while ( v33 < v5->m_zRes );
  }
}

// File Line: 68
// RVA: 0xCF9170
signed __int64 __fastcall hkpCompressedSampledHeightFieldShape::calcSizeForSpu(hkpCompressedSampledHeightFieldShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  signed __int64 result; // rax

  result = 176i64;
  if ( spuBufferSizeLeft < 176 )
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 84
// RVA: 0xCF8CF0
void __fastcall hkpCompressedSampledHeightFieldShape::collideSpheres(hkpCompressedSampledHeightFieldShape *this, hkpHeightFieldShape::CollideSpheresInput *input, hkVector4f *outputArray)
{
  hkSphere *v3; // r14
  int v4; // er12
  hkVector4f *v5; // rdi
  hkpCompressedSampledHeightFieldShape *v6; // rbx
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
             (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v8),
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
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, char *))v6->vfptr[10].__first_virtual_table_function__)(
        v6,
        &v35);
      v18 = v6->vfptr;
      if ( !v35 )
        break;
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v18[10].__vecDelDtor)(
        v6,
        v10.m128i_u16[0],
        v10.m128i_u16[2]);
      v19 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[0]);
      v20 = v10.m128i_u16[0];
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(
        v6,
        (unsigned int)v10.m128i_u16[0] + 1,
        (unsigned int)v10.m128i_u16[2] + 1);
      v21 = v6->vfptr;
      if ( v16 > v17 )
      {
        ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v21[10].__vecDelDtor)(
          v6,
          (unsigned int)v10.m128i_u16[0] + 1,
          v10.m128i_u16[2]);
        v4 = v37;
        v22 = v14 - v14;
        v23 = v14 - v14;
        v24 = (float)((float)(v14 - v14) * v17) + v14;
        goto LABEL_16;
      }
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v21[10].__vecDelDtor)(
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
    ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v18[10].__vecDelDtor)(
      v6,
      v20,
      v10.m128i_u16[2]);
    v19 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[0]);
    ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(
      v6,
      v10.m128i_u16[0],
      (unsigned int)v10.m128i_u16[2] + 1);
    v26 = v6->vfptr;
    if ( (float)(v17 + v16) <= 1.0 )
    {
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v26[10].__vecDelDtor)(
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
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v26[10].__vecDelDtor)(
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

