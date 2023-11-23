// File Line: 15
// RVA: 0xCF8BC0
void __fastcall hkpCompressedSampledHeightFieldShape::hkpCompressedSampledHeightFieldShape(
        hkpCompressedSampledHeightFieldShape *this,
        hkpSampledHeightFieldBaseCinfo *info,
        hkArray<unsigned short,hkContainerHeapAllocator> *samples,
        float quantizationOffset,
        float quantizationScale)
{
  int v7; // r8d
  __int64 m_size; // rax
  unsigned __int16 *m_data; // rcx
  __int64 v10; // rdx
  char *v11; // r8
  unsigned __int16 v12; // ax
  float v13; // xmm0_4
  int v14; // [rsp+58h] [rbp+20h] BYREF

  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(this, info, HEIGHTFIELD_COMPRESSED);
  this->vfptr = (hkBaseObjectVtbl *)&hkpCompressedSampledHeightFieldShape::`vftable;
  this->m_storage.m_capacityAndFlags = 0x80000000;
  this->m_storage.m_data = 0i64;
  this->m_storage.m_size = 0;
  this->m_triangleFlip.m_bool = 0;
  v7 = this->m_storage.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < samples->m_size )
  {
    if ( this->m_storage.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_storage.m_data,
        2 * v7);
    v14 = 2 * samples->m_size;
    this->m_storage.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerHeapAllocator::s_alloc,
                                                   &v14);
    this->m_storage.m_capacityAndFlags = v14 / 2;
  }
  m_size = samples->m_size;
  m_data = this->m_storage.m_data;
  this->m_storage.m_size = m_size;
  v10 = m_size;
  if ( (int)m_size > 0 )
  {
    v11 = (char *)((char *)samples->m_data - (char *)m_data);
    do
    {
      v12 = *(unsigned __int16 *)((char *)m_data++ + (_QWORD)v11);
      *(m_data - 1) = v12;
      --v10;
    }
    while ( v10 );
  }
  v13 = quantizationScale;
  this->m_offset = quantizationOffset;
  this->m_scale = v13;
}

// File Line: 22
// RVA: 0xCF8820
void __fastcall hkpCompressedSampledHeightFieldShape::hkpCompressedSampledHeightFieldShape(
        hkpCompressedSampledHeightFieldShape *this,
        hkpSampledHeightFieldShape *hf)
{
  __int64 v2; // r15
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_storage; // r12
  int m_size; // edi
  __int64 v7; // r13
  int v8; // r12d
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // edi
  __int64 v13; // rsi
  int *v14; // rdi
  int v15; // r8d
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *m_data; // rdi
  char *v17; // r15
  __int64 v18; // rsi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v19; // rdi
  char *v20; // r15
  __int64 v21; // rsi
  int v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  float v26; // xmm7_4
  float v27; // xmm6_4
  int i; // esi
  int j; // edi
  float v30; // xmm0_4
  bool v31; // cc
  int v32; // esi
  int v33; // edi
  __int64 k; // rbp
  float v35; // xmm0_4
  unsigned __int16 *v36; // rax
  __int64 v37; // rcx
  hkResult result; // [rsp+90h] [rbp+8h] BYREF
  float v39; // [rsp+98h] [rbp+10h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.hkpSampledHeightFieldShape::hkpHeightFieldShape::hkpShape::hkpShapeBase::hkcdShape::m_storage = 1036;
  v2 = 0i64;
  this->m_userData = 0i64;
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_size = 0;
  this->m_coarseTreeData.m_capacityAndFlags = 0x80000000;
  p_m_storage = &this->m_storage;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCompressedSampledHeightFieldShape::`vftable;
  this->m_storage.m_data = 0i64;
  this->m_storage.m_size = 0;
  this->m_storage.m_capacityAndFlags = 0x80000000;
  this->m_heightfieldType.hkpSampledHeightFieldShape::m_storage = 1;
  this->m_xRes = hf->m_xRes;
  this->m_zRes = hf->m_zRes;
  this->m_coarseness = hf->m_coarseness;
  if ( hf->m_coarseness )
  {
    m_size = this->m_coarseTreeData.m_size;
    v7 = hf->m_coarseTreeData.m_size;
    v8 = hf->m_coarseTreeData.m_size;
    if ( (int)v7 > m_size )
      v8 = this->m_coarseTreeData.m_size;
    v9 = this->m_coarseTreeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < (int)v7 )
    {
      v10 = 2 * v9;
      v11 = hf->m_coarseTreeData.m_size;
      if ( (int)v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_coarseTreeData.m_data,
        v11,
        24);
    }
    v12 = m_size - v7 - 1;
    v13 = v12;
    if ( v12 >= 0 )
    {
      v14 = &this->m_coarseTreeData.m_data[v7].m_minMaxData.m_capacityAndFlags + 6 * v12;
      do
      {
        v15 = *v14;
        *(v14 - 1) = 0;
        if ( v15 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v14 - 3),
            16 * v15);
        *(_QWORD *)(v14 - 3) = 0i64;
        *v14 = 0x80000000;
        v14 -= 6;
        --v13;
      }
      while ( v13 >= 0 );
    }
    m_data = this->m_coarseTreeData.m_data;
    if ( v8 > 0 )
    {
      v17 = (char *)((char *)hf->m_coarseTreeData.m_data - (char *)m_data);
      v18 = (unsigned int)v8;
      do
      {
        hkpSampledHeightFieldShape::CoarseMinMaxLevel::operator=(
          m_data,
          (hkpSampledHeightFieldShape::CoarseMinMaxLevel *)((char *)m_data + (_QWORD)v17));
        ++m_data;
        --v18;
      }
      while ( v18 );
    }
    v19 = &this->m_coarseTreeData.m_data[v8];
    if ( (int)v7 - v8 > 0 )
    {
      v20 = (char *)((char *)&hf->m_coarseTreeData.m_data[v8] - (char *)v19);
      v21 = (unsigned int)(v7 - v8);
      do
      {
        if ( v19 )
          hkpSampledHeightFieldShape::CoarseMinMaxLevel::CoarseMinMaxLevel(
            v19,
            (hkpSampledHeightFieldShape::CoarseMinMaxLevel *)((char *)v19 + (_QWORD)v20));
        ++v19;
        --v21;
      }
      while ( v21 );
    }
    this->m_coarseTreeData.m_size = v7;
    p_m_storage = &this->m_storage;
    v2 = 0i64;
  }
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkResult *))hf->vfptr[10].__first_virtual_table_function__)(
    hf,
    &result);
  v22 = this->m_xRes * this->m_zRes;
  this->m_triangleFlip.m_bool = result.m_enum;
  this->m_heightCenter = hf->m_heightCenter;
  this->m_intToFloatScale = hf->m_intToFloatScale;
  this->m_floatToIntScale = hf->m_floatToIntScale;
  this->m_floatToIntOffsetFloorCorrected = hf->m_floatToIntOffsetFloorCorrected;
  this->m_extents = hf->m_extents;
  v23 = p_m_storage->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    v25 = v22;
    if ( v22 < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_storage->m_data, v25, 2);
  }
  v26 = FLOAT_3_40282e38;
  v27 = FLOAT_N3_40282e38;
  p_m_storage->m_size = v22;
  for ( i = 0; i < this->m_zRes; ++i )
  {
    for ( j = 0; j < this->m_xRes; v27 = fmaxf(v30, v27) )
    {
      v30 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))hf->vfptr[10].__vecDelDtor)(
              hf,
              (unsigned int)j++,
              (unsigned int)i);
      v39 = v27;
      v26 = fminf(v30, v26);
      *(float *)&result.m_enum = v30;
    }
  }
  v31 = this->m_zRes <= 0;
  this->m_offset = v26;
  v32 = 0;
  this->m_scale = (float)(v27 - v26) * 0.000015259022;
  if ( !v31 )
  {
    do
    {
      v33 = 0;
      for ( k = 0i64; v33 < this->m_xRes; v36[v37] = (int)*(float *)&result.m_enum )
      {
        v35 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))hf->vfptr[10].__vecDelDtor)(
                hf,
                (unsigned int)v33,
                (unsigned int)v32);
        v36 = p_m_storage->m_data;
        v37 = k + v2 * this->m_xRes;
        ++v33;
        ++k;
        *(float *)&result.m_enum = (float)(v35 - this->m_offset) / this->m_scale;
      }
      ++v32;
      ++v2;
    }
    while ( v32 < this->m_zRes );
  }
}

// File Line: 68
// RVA: 0xCF9170
__int64 __fastcall hkpCompressedSampledHeightFieldShape::calcSizeForSpu(
        hkpCompressedSampledHeightFieldShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  __int64 result; // rax

  result = 176i64;
  if ( spuBufferSizeLeft < 176 )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 84
// RVA: 0xCF8CF0
void __fastcall hkpCompressedSampledHeightFieldShape::collideSpheres(
        hkpCompressedSampledHeightFieldShape *this,
        hkpHeightFieldShape::CollideSpheresInput *input,
        hkVector4f *outputArray)
{
  hkSphere *m_spheres; // r14
  int v4; // r12d
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128i v9; // xmm1
  __m128i v10; // xmm1
  int v11; // ecx
  int v12; // eax
  float v13; // xmm0_4
  __m128 v14; // xmm0
  __m128 v15; // xmm13
  float v16; // xmm7_4
  float v17; // xmm8_4
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v19; // xmm10
  unsigned int v20; // r15d
  double v21; // xmm0_8
  hkBaseObjectVtbl *v22; // rax
  float v23; // xmm9_4
  double v24; // xmm0_8
  float v25; // xmm9_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  double v28; // xmm0_8
  float v29; // xmm9_4
  double v30; // xmm0_8
  hkBaseObjectVtbl *v31; // rax
  float v32; // xmm9_4
  double v33; // xmm0_8
  float v34; // xmm2_4
  float v35; // xmm0_4
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm5
  __m128 v41; // xmm6
  __m128 v42; // xmm1
  char v43; // [rsp+118h] [rbp+10h] BYREF
  float v44; // [rsp+120h] [rbp+18h]
  int v45; // [rsp+128h] [rbp+20h]

  m_spheres = input->m_spheres;
  v4 = input->m_numSpheres - 1;
  v45 = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      *outputArray = (hkVector4f)_xmm;
      v7 = _mm_mul_ps(m_spheres->m_pos.m_quad, this->m_floatToIntScale.m_quad);
      v8 = _mm_mul_ps(
             _mm_add_ps(m_spheres->m_pos.m_quad, this->m_floatToIntOffsetFloorCorrected.m_quad),
             this->m_floatToIntScale.m_quad);
      v9 = _mm_xor_si128(
             (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v8),
             _mm_cvttps_epi32(v8));
      v10 = _mm_packs_epi32(v9, v9);
      if ( v10.m128i_u16[0] >= this->m_xRes - 1 || v10.m128i_u16[2] >= this->m_zRes - 1 )
        goto LABEL_22;
      v11 = 0;
      v12 = 0;
      LODWORD(v13) = _mm_shuffle_ps(v7, v7, 0).m128_u32[0];
      if ( _mm_shuffle_ps(v7, v7, 170).m128_f32[0] < 0.0 )
        v11 = 1;
      if ( v13 < 0.0 )
        v12 = 1;
      if ( v12 | v11 )
        goto LABEL_22;
      v14 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[0]);
      v15 = (__m128)COERCE_UNSIGNED_INT((float)v10.m128i_u16[2]);
      v16 = v7.m128_f32[0] - v14.m128_f32[0];
      v17 = _mm_shuffle_ps(v7, v7, 170).m128_f32[0] - v15.m128_f32[0];
      ((void (__fastcall *)(hkpCompressedSampledHeightFieldShape *, char *))this->vfptr[10].__first_virtual_table_function__)(
        this,
        &v43);
      vfptr = this->vfptr;
      if ( !v43 )
        break;
      *(double *)v14.m128_u64 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
                                  this,
                                  v10.m128i_u16[0],
                                  v10.m128i_u16[2]);
      v19 = v14;
      v20 = v10.m128i_u16[0];
      v21 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
              this,
              (unsigned int)v10.m128i_u16[0] + 1,
              (unsigned int)v10.m128i_u16[2] + 1);
      v22 = this->vfptr;
      v23 = *(float *)&v21;
      if ( v16 > v17 )
      {
        v24 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v22[10].__vecDelDtor)(
                this,
                (unsigned int)v10.m128i_u16[0] + 1,
                v10.m128i_u16[2]);
        v4 = v45;
        v25 = v23 - *(float *)&v24;
        v26 = *(float *)&v24 - v19.m128_f32[0];
        v27 = (float)(v25 * v17) + v19.m128_f32[0];
        goto LABEL_16;
      }
      v28 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v22[10].__vecDelDtor)(
              this,
              v10.m128i_u16[0],
              (unsigned int)v10.m128i_u16[2] + 1);
      v4 = v45;
      v29 = v23 - *(float *)&v28;
      *(float *)&v28 = *(float *)&v28 - v19.m128_f32[0];
      outputArray->m_quad.m128_i32[0] = LODWORD(v29) ^ _xmm[0];
      outputArray->m_quad.m128_i32[2] = LODWORD(v28) ^ _xmm[0];
      v44 = (float)((float)(*(float *)&v28 * v17) + v19.m128_f32[0]) + (float)(v29 * v16);
LABEL_18:
      v36 = _mm_mul_ps(this->m_floatToIntScale.m_quad, outputArray->m_quad);
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
              _mm_shuffle_ps(v37, v37, 170));
      v39 = _mm_rsqrt_ps(v38);
      v40 = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v38, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                  _mm_mul_ps(*(__m128 *)_xmm, v39))),
              v36);
      *outputArray = (hkVector4f)v40;
      if ( this->m_useProjectionBasedHeight.m_bool )
      {
        v42 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    v7,
                    _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)(int)v20), v15),
                      _mm_unpacklo_ps(v19, (__m128)0i64))),
                  this->m_intToFloatScale.m_quad),
                v40);
        v41 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                _mm_shuffle_ps(v42, v42, 170));
      }
      else
      {
        v41 = _mm_mul_ps(
                _mm_sub_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps((__m128)LODWORD(v44), (__m128)LODWORD(v44), 0)),
                _mm_shuffle_ps(this->m_intToFloatScale.m_quad, this->m_intToFloatScale.m_quad, 85));
      }
      outputArray->m_quad = _mm_shuffle_ps(
                              v40,
                              _mm_unpackhi_ps(
                                v40,
                                _mm_sub_ps(v41, _mm_shuffle_ps(m_spheres->m_pos.m_quad, m_spheres->m_pos.m_quad, 255))),
                              196);
LABEL_22:
      ++outputArray;
      ++m_spheres;
      v45 = --v4;
      if ( v4 < 0 )
        return;
    }
    v20 = v10.m128i_u16[0] + 1;
    *(double *)v14.m128_u64 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
                                this,
                                v20,
                                v10.m128i_u16[2]);
    v19 = v14;
    v30 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
            this,
            v10.m128i_u16[0],
            (unsigned int)v10.m128i_u16[2] + 1);
    v31 = this->vfptr;
    v32 = *(float *)&v30;
    if ( (float)(v17 + v16) <= 1.0 )
    {
      v35 = ((float (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v31[10].__vecDelDtor)(
              this,
              v10.m128i_u16[0],
              v10.m128i_u16[2]);
      v25 = v32 - v35;
      v26 = v19.m128_f32[0] - v35;
      v27 = (float)(v25 * v17) + v35;
LABEL_16:
      outputArray->m_quad.m128_i32[2] = LODWORD(v25) ^ _xmm[0];
      v44 = v27 + (float)(v26 * v16);
    }
    else
    {
      v33 = ((double (__fastcall *)(hkpCompressedSampledHeightFieldShape *, _QWORD, _QWORD))v31[10].__vecDelDtor)(
              this,
              v20,
              (unsigned int)v10.m128i_u16[2] + 1);
      v34 = *(float *)&v33;
      *(float *)&v33 = *(float *)&v33 - v19.m128_f32[0];
      v26 = v34 - v32;
      outputArray->m_quad.m128_i32[2] = LODWORD(v33) ^ _xmm[0];
      v44 = (float)((float)(v16 - 1.0) * v26) + (float)((float)(*(float *)&v33 * v17) + v19.m128_f32[0]);
    }
    outputArray->m_quad.m128_i32[0] = LODWORD(v26) ^ _xmm[0];
    goto LABEL_18;
  }
}

