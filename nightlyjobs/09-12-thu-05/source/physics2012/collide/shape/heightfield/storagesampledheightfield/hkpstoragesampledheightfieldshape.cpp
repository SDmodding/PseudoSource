// File Line: 15
// RVA: 0xD175A0
void __fastcall hkpStorageSampledHeightFieldShape::hkpStorageSampledHeightFieldShape(
        hkpStorageSampledHeightFieldShape *this,
        hkpSampledHeightFieldBaseCinfo *info,
        hkArray<float,hkContainerHeapAllocator> *samples)
{
  __int64 v5; // rdi
  __int64 m_size; // rax
  float *m_data; // r11
  float *v8; // r10
  __int64 v9; // rdx
  float *v10; // rcx
  signed __int64 v11; // r8
  unsigned __int64 v12; // r9
  int v13; // eax
  signed __int64 v14; // r10
  float *v15; // rcx
  __int64 v16; // rdx
  int v17; // eax
  int v18; // [rsp+30h] [rbp+8h] BYREF

  hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(this, info, HEIGHTFIELD_STORAGE);
  v5 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageSampledHeightFieldShape::`vftable;
  this->m_storage.m_data = 0i64;
  this->m_storage.m_size = 0;
  this->m_storage.m_capacityAndFlags = 0x80000000;
  this->m_triangleFlip.m_bool = 0;
  if ( (this->m_storage.m_capacityAndFlags & 0x3FFFFFFF) < samples->m_size )
  {
    if ( this->m_storage.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * this->m_storage.m_capacityAndFlags);
    v18 = 4 * samples->m_size;
    this->m_storage.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                        &hkContainerHeapAllocator::s_alloc,
                                        &v18);
    this->m_storage.m_capacityAndFlags = v18 / 4;
  }
  m_size = samples->m_size;
  m_data = this->m_storage.m_data;
  this->m_storage.m_size = m_size;
  v8 = samples->m_data;
  v9 = m_size;
  if ( m_size >= 4 )
  {
    v10 = m_data + 1;
    v11 = (char *)v8 - (char *)m_data;
    v12 = ((unsigned __int64)(m_size - 4) >> 2) + 1;
    v5 = 4 * v12;
    do
    {
      v13 = *(_DWORD *)((char *)v10 + v11 - 4);
      v10 += 4;
      *((_DWORD *)v10 - 5) = v13;
      *(v10 - 4) = *(float *)((char *)v10 + v11 - 16);
      *(v10 - 3) = *(float *)((char *)v10 + v11 - 12);
      *(v10 - 2) = *(float *)((char *)v10 + v11 - 8);
      --v12;
    }
    while ( v12 );
  }
  if ( v5 < v9 )
  {
    v14 = (char *)v8 - (char *)m_data;
    v15 = &m_data[v5];
    v16 = v9 - v5;
    do
    {
      v17 = *(_DWORD *)((char *)v15++ + v14);
      *((_DWORD *)v15 - 1) = v17;
      --v16;
    }
    while ( v16 );
  }
}

// File Line: 20
// RVA: 0xD172E0
void __fastcall hkpStorageSampledHeightFieldShape::hkpStorageSampledHeightFieldShape(
        hkpStorageSampledHeightFieldShape *this,
        hkpSampledHeightFieldShape *hf)
{
  hkArray<float,hkContainerHeapAllocator> *p_m_storage; // r12
  __int64 m_size; // rsi
  int v6; // ebx
  int v7; // r13d
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // ebx
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v12; // rdx
  __int64 v13; // rsi
  int *v14; // rbx
  int v15; // r8d
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *m_data; // rbx
  char *v17; // r14
  __int64 v18; // rsi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v19; // rbx
  char *v20; // r14
  __int64 v21; // rsi
  int v22; // ebx
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  int v26; // ebp
  __int64 i; // r14
  int v28; // ebx
  __int64 j; // rsi
  float v30; // xmm0_4
  __int64 v31; // rcx
  hkResult v32; // [rsp+70h] [rbp+8h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.hkpSampledHeightFieldShape::hkpHeightFieldShape::hkpShape::hkpShapeBase::hkcdShape::m_storage = 1036;
  this->m_userData = 0i64;
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_size = 0;
  this->m_coarseTreeData.m_capacityAndFlags = 0x80000000;
  p_m_storage = &this->m_storage;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStorageSampledHeightFieldShape::`vftable;
  this->m_storage.m_data = 0i64;
  this->m_storage.m_size = 0;
  this->m_storage.m_capacityAndFlags = 0x80000000;
  this->m_heightfieldType.hkpSampledHeightFieldShape::m_storage = 0;
  this->m_xRes = hf->m_xRes;
  this->m_zRes = hf->m_zRes;
  this->m_coarseness = hf->m_coarseness;
  if ( hf->m_coarseness )
  {
    m_size = hf->m_coarseTreeData.m_size;
    v6 = this->m_coarseTreeData.m_size;
    v7 = m_size;
    if ( (int)m_size > v6 )
      v7 = this->m_coarseTreeData.m_size;
    v8 = this->m_coarseTreeData.m_capacityAndFlags & 0x3FFFFFFF;
    v32.m_enum = hf->m_coarseTreeData.m_size;
    if ( v8 < (int)m_size )
    {
      v9 = 2 * v8;
      v10 = m_size;
      if ( (int)m_size < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_coarseTreeData.m_data,
        v10,
        24);
    }
    v11 = v6 - m_size - 1;
    v12 = &this->m_coarseTreeData.m_data[m_size];
    v13 = v11;
    if ( v11 >= 0 )
    {
      v14 = &v12->m_minMaxData.m_capacityAndFlags + 6 * v11;
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
    if ( v7 > 0 )
    {
      v17 = (char *)((char *)hf->m_coarseTreeData.m_data - (char *)m_data);
      v18 = (unsigned int)v7;
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
    v19 = &this->m_coarseTreeData.m_data[v7];
    if ( v32.m_enum - v7 > 0 )
    {
      v20 = (char *)((char *)&hf->m_coarseTreeData.m_data[v7] - (char *)v19);
      v21 = (unsigned int)(v32.m_enum - v7);
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
    this->m_coarseTreeData.m_size = v32.m_enum;
  }
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkResult *))hf->vfptr[10].__first_virtual_table_function__)(
    hf,
    &v32);
  v22 = this->m_xRes * this->m_zRes;
  this->m_triangleFlip.m_bool = v32.m_enum;
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
    hkArrayUtil::_reserve(&v32, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_storage->m_data, v25, 4);
  }
  v26 = 0;
  p_m_storage->m_size = v22;
  for ( i = 0i64; v26 < this->m_zRes; ++i )
  {
    v28 = 0;
    for ( j = 0i64; v28 < this->m_xRes; p_m_storage->m_data[v31] = v30 )
    {
      v30 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))hf->vfptr[10].__vecDelDtor)(
              hf,
              (unsigned int)v28,
              (unsigned int)v26);
      v31 = j + i * this->m_xRes;
      ++v28;
      ++j;
    }
    ++v26;
  }
}

// File Line: 51
// RVA: 0xD17B80
__int64 __fastcall hkpStorageSampledHeightFieldShape::calcSizeForSpu(
        hkpStorageSampledHeightFieldShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  __int64 result; // rax

  result = 176i64;
  if ( spuBufferSizeLeft < 176 )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 67
// RVA: 0xD17700
void __fastcall hkpStorageSampledHeightFieldShape::collideSpheres(
        hkpStorageSampledHeightFieldShape *this,
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
      ((void (__fastcall *)(hkpStorageSampledHeightFieldShape *, char *))this->vfptr[10].__first_virtual_table_function__)(
        this,
        &v43);
      vfptr = this->vfptr;
      if ( !v43 )
        break;
      *(double *)v14.m128_u64 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
                                  this,
                                  v10.m128i_u16[0],
                                  v10.m128i_u16[2]);
      v19 = v14;
      v20 = v10.m128i_u16[0];
      v21 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
              this,
              (unsigned int)v10.m128i_u16[0] + 1,
              (unsigned int)v10.m128i_u16[2] + 1);
      v22 = this->vfptr;
      v23 = *(float *)&v21;
      if ( v16 > v17 )
      {
        v24 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v22[10].__vecDelDtor)(
                this,
                (unsigned int)v10.m128i_u16[0] + 1,
                v10.m128i_u16[2]);
        v4 = v45;
        v25 = v23 - *(float *)&v24;
        v26 = *(float *)&v24 - v19.m128_f32[0];
        v27 = (float)(v25 * v17) + v19.m128_f32[0];
        goto LABEL_16;
      }
      v28 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v22[10].__vecDelDtor)(
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
    *(double *)v14.m128_u64 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
                                this,
                                v20,
                                v10.m128i_u16[2]);
    v19 = v14;
    v30 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
            this,
            v10.m128i_u16[0],
            (unsigned int)v10.m128i_u16[2] + 1);
    v31 = this->vfptr;
    v32 = *(float *)&v30;
    if ( (float)(v17 + v16) <= 1.0 )
    {
      v35 = ((float (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v31[10].__vecDelDtor)(
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
      v33 = ((double (__fastcall *)(hkpStorageSampledHeightFieldShape *, _QWORD, _QWORD))v31[10].__vecDelDtor)(
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

