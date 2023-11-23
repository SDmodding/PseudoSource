// File Line: 18
// RVA: 0xD34C40
void hkpSampledHeightField_registerCoarseTreeRayCastFunction(void)
{
  hkpSampledHeightFieldShape::s_rayCastFunc = hkpSampledHeightFieldShape::castRayCoarseTree;
  hkpSampledHeightFieldShape::s_sphereCastFunc = hkpSampledHeightFieldShape::castSphereCoarseTree;
}

// File Line: 26
// RVA: 0x15CC9A0
void dynamic_initializer_for__hkOptionalComponent_hkpSampledHeightFieldShape_CoarseCast__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpSampledHeightFieldShape_CoarseCast,
    "hkpSampledHeightFieldShape_CoarseCast",
    hkpSampledHeightField_registerCoarseTreeRayCastFunction);
}

// File Line: 34
// RVA: 0xD33910
void __fastcall hkpSampledHeightFieldShape::castRayCoarseTree(
        hkpSampledHeightFieldShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  __m128 v4; // xmm1
  hkVector4f to; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f from; // [rsp+40h] [rbp-18h] BYREF

  hkOptionalComponent_hkpSampledHeightFieldShape_CoarseCast.m_isUsed.m_bool = 1;
  v4 = _mm_mul_ps(input->m_to.m_quad, this->m_floatToIntScale.m_quad);
  from.m_quad = _mm_mul_ps(input->m_from.m_quad, this->m_floatToIntScale.m_quad);
  to.m_quad = v4;
  hkpSampledHeightFieldShape::castRayCoarseTreeInternal(this, &from, &to, cdBody, collector);
}

// File Line: 44
// RVA: 0xD33960
void __fastcall hkpSampledHeightFieldShape::castSphereCoarseTree(
        hkpSampledHeightFieldShape *this,
        hkpHeightFieldShape::hkpSphereCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  float v8; // xmm6_4
  __m128 v9; // xmm7
  __m128 v10; // xmm13
  __m128i v11; // xmm1
  unsigned int v12; // esi
  unsigned int v13; // edi
  float v14; // xmm8_4
  float v15; // xmm9_4
  hkBaseObjectVtbl *vfptr; // rax
  double v17; // xmm0_8
  float v18; // xmm10_4
  double v19; // xmm0_8
  hkBaseObjectVtbl *v20; // rax
  float v21; // xmm6_4
  double v22; // xmm0_8
  float v23; // xmm6_4
  float v24; // xmm1_4
  double v25; // xmm0_8
  float v26; // xmm6_4
  double v27; // xmm0_8
  float v28; // xmm10_4
  double v29; // xmm0_8
  hkBaseObjectVtbl *v30; // rax
  float v31; // xmm12_4
  double v32; // xmm0_8
  float v33; // xmm0_4
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  hkVector4f to; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f from; // [rsp+40h] [rbp-B8h] BYREF
  int v38; // [rsp+100h] [rbp+8h] BYREF
  float v39; // [rsp+108h] [rbp+10h]

  hkOptionalComponent_hkpSampledHeightFieldShape_CoarseCast.m_isUsed.m_bool = 1;
  v8 = 0.0;
  v9 = _mm_mul_ps(input->m_from.m_quad, this->m_floatToIntScale.m_quad);
  v10 = _mm_mul_ps(input->m_to.m_quad, this->m_floatToIntScale.m_quad);
  v11 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
          _mm_cvttps_epi32(v9));
  v12 = _mm_cvtsi128_si32(v11);
  v13 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v11, 170));
  if ( v12 < this->m_xRes && v13 < this->m_zRes )
  {
    v14 = _mm_shuffle_ps(v9, v9, 170).m128_f32[0] - (float)(int)v13;
    v15 = v9.m128_f32[0] - (float)(int)v12;
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, int *))this->vfptr[10].__first_virtual_table_function__)(
      this,
      &v38);
    vfptr = this->vfptr;
    if ( (_BYTE)v38 )
    {
      v17 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
              this,
              v12,
              v13);
      v18 = *(float *)&v17;
      v19 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
              this,
              v12 + 1,
              v13 + 1);
      v20 = this->vfptr;
      v21 = *(float *)&v19;
      if ( v15 <= v14 )
      {
        v25 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v20[10].__vecDelDtor)(
                this,
                v12,
                v13 + 1);
        v24 = v21 - *(float *)&v25;
        v23 = *(float *)&v25 - v18;
      }
      else
      {
        v22 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v20[10].__vecDelDtor)(
                this,
                v12 + 1,
                v13);
        v23 = v21 - *(float *)&v22;
        v24 = *(float *)&v22 - v18;
      }
      v26 = (float)((float)(v23 * v14) + v18) + (float)(v24 * v15);
    }
    else
    {
      v27 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
              this,
              v12 + 1,
              v13);
      v28 = *(float *)&v27;
      v29 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
              this,
              v12,
              v13 + 1);
      v30 = this->vfptr;
      v31 = *(float *)&v29;
      if ( (float)(v15 + v14) <= 1.0 )
      {
        v33 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v30[10].__vecDelDtor)(this, v12, v13);
        v26 = (float)((float)((float)(v31 - v33) * v14) + v33) + (float)((float)(v28 - v33) * v15);
      }
      else
      {
        v32 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v30[10].__vecDelDtor)(
                this,
                v12 + 1,
                v13 + 1);
        v26 = (float)((float)((float)(*(float *)&v32 - v28) * v14) + v28)
            + (float)((float)(v15 - 1.0) * (float)(*(float *)&v32 - v31));
      }
    }
    v8 = v26 - _mm_shuffle_ps(v9, v9, 85).m128_f32[0];
  }
  v39 = v8;
  v34 = (__m128)LODWORD(v8);
  v38 = 0;
  v34.m128_f32[0] = fmaxf(v8, 0.0) + input->m_maxExtraPenetration;
  v35 = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(v34, (__m128)0i64));
  from.m_quad = _mm_add_ps(v9, v35);
  to.m_quad = _mm_add_ps(v10, v35);
  hkpSampledHeightFieldShape::castRayCoarseTreeInternal(this, &from, &to, cdBody, collector);
}

// File Line: 76
// RVA: 0xD34C70
hkSimdFloat32 *__fastcall calcNextMinHeight(
        hkSimdFloat32 *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *v,
        int xRes,
        int zRes,
        int x,
        int z)
{
  __m128 m_quad; // xmm0
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm1

  if ( x >= xRes || z >= zRes )
  {
    v7 = result;
    *result = (hkSimdFloat32)xmmword_141A712A0;
  }
  else
  {
    m_quad = v->m_data[2 * z + 2 * x * zRes].m_quad;
    v7 = result;
    v8 = _mm_min_ps(_mm_shuffle_ps(m_quad, m_quad, 78), m_quad);
    result->m_real = _mm_min_ps(v8, _mm_shuffle_ps(v8, v8, 177));
  }
  return v7;
}

// File Line: 85
// RVA: 0xD34CD0
hkSimdFloat32 *__fastcall calcNextMaxHeight(
        hkSimdFloat32 *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *v,
        int xRes,
        int zRes,
        int x,
        int z)
{
  hkSimdFloat32 *v6; // rax
  __m128 v7; // xmm1

  if ( x >= xRes || z >= zRes )
  {
    v6 = result;
    *result = (hkSimdFloat32)xmmword_141A712F0;
  }
  else
  {
    v6 = result;
    v7 = _mm_max_ps(
           _mm_shuffle_ps(v->m_data[2 * z + 1 + 2 * x * zRes].m_quad, v->m_data[2 * z + 1 + 2 * x * zRes].m_quad, 78),
           v->m_data[2 * z + 1 + 2 * x * zRes].m_quad);
    result->m_real = _mm_max_ps(v7, _mm_shuffle_ps(v7, v7, 177));
  }
  return v6;
}

// File Line: 111
// RVA: 0xD32F10
void __fastcall hkpSampledHeightFieldShape::buildCoarseMinMaxTree(hkpSampledHeightFieldShape *this, int coarseness)
{
  hkArray<hkpSampledHeightFieldShape::CoarseMinMaxLevel,hkContainerHeapAllocator> *p_m_coarseTreeData; // r13
  int m_size; // eax
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *m_data; // rcx
  int v6; // eax
  __int64 v8; // rsi
  int *v9; // rdi
  int v10; // r8d
  int m_capacityAndFlags; // eax
  int m_zRes; // ecx
  int v13; // eax
  unsigned int i; // ecx
  int v15; // eax
  int v16; // r12d
  int v17; // eax
  int v18; // ecx
  int v19; // edi
  int v20; // esi
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // r14
  int v24; // r9d
  int v25; // eax
  int v26; // edx
  bool v27; // cc
  hkResultEnum m_enum; // ecx
  int m_xRes; // r15d
  __m128 v30; // xmm12
  __m128 v31; // xmm13
  int v32; // r14d
  int v33; // r13d
  int v34; // r12d
  int v35; // esi
  int v36; // edi
  float v37; // xmm0_4
  int v38; // r15d
  __m128 v39; // xmm10
  __m128 v40; // xmm11
  int v41; // r14d
  int v42; // r13d
  int v43; // r12d
  int v44; // esi
  int v45; // edi
  float v46; // xmm0_4
  int v47; // r15d
  int v48; // ecx
  __m128 v49; // xmm8
  __m128 v50; // xmm9
  int v51; // r14d
  __int32 v52; // r13d
  __int32 v53; // r12d
  int v54; // esi
  __int32 v55; // edi
  float v56; // xmm0_4
  int v57; // r15d
  __m128 v58; // xmm6
  __m128 v59; // xmm7
  int v60; // r14d
  __int32 v61; // r13d
  __int32 v62; // r12d
  int v63; // esi
  __int32 v64; // edi
  float v65; // xmm0_4
  int v66; // r8d
  __m128 *v67; // rax
  __int64 v68; // rsi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v69; // r14
  int v70; // edi
  int v71; // ebx
  __int64 v72; // rdx
  __int64 v73; // rdx
  __int64 v74; // r15
  int v75; // ecx
  int v76; // r9d
  int v77; // r9d
  int v78; // r13d
  int v79; // r9d
  int v80; // eax
  int v81; // r10d
  int v82; // r12d
  int v83; // r11d
  int v84; // edx
  __m128 v85; // xmm2
  __m128 v86; // xmm4
  __m128 v87; // xmm4
  int v88; // r8d
  __m128 v89; // xmm1
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm3
  __m128 v93; // xmm2
  __m128 v94; // xmm2
  __m128 v95; // xmm1
  __int64 v96; // rcx
  __m128 v97; // xmm5
  __m128 v98; // xmm5
  __int64 v99; // rcx
  __m128 v100; // xmm3
  __m128 v101; // xmm3
  __int64 v102; // rcx
  __m128 v103; // xmm4
  __m128 v104; // xmm4
  __int64 v105; // rcx
  __m128 v106; // xmm1
  int v107; // [rsp+30h] [rbp-D0h]
  int v108; // [rsp+48h] [rbp-B8h]
  int v109; // [rsp+4Ch] [rbp-B4h]
  hkArray<hkpSampledHeightFieldShape::CoarseMinMaxLevel,hkContainerHeapAllocator> *v110; // [rsp+50h] [rbp-B0h]
  __int64 v111; // [rsp+58h] [rbp-A8h]
  int v112; // [rsp+150h] [rbp+50h]
  __int64 v113; // [rsp+150h] [rbp+50h]
  hkResult result; // [rsp+158h] [rbp+58h] BYREF
  int v115; // [rsp+160h] [rbp+60h]
  int v116; // [rsp+168h] [rbp+68h]

  p_m_coarseTreeData = &this->m_coarseTreeData;
  this->m_coarseness = coarseness;
  m_size = this->m_coarseTreeData.m_size;
  m_data = this->m_coarseTreeData.m_data;
  v6 = m_size - 1;
  v110 = p_m_coarseTreeData;
  v8 = v6;
  if ( v6 >= 0 )
  {
    v9 = &m_data->m_minMaxData.m_capacityAndFlags + 6 * v6;
    do
    {
      v10 = *v9;
      *(v9 - 1) = 0;
      if ( v10 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v9 - 3),
          16 * v10);
      *(_QWORD *)(v9 - 3) = 0i64;
      *v9 = 0x80000000;
      v9 -= 6;
      --v8;
    }
    while ( v8 >= 0 );
  }
  m_capacityAndFlags = p_m_coarseTreeData->m_capacityAndFlags;
  p_m_coarseTreeData->m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_coarseTreeData->m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  p_m_coarseTreeData->m_data = 0i64;
  p_m_coarseTreeData->m_capacityAndFlags = 0x80000000;
  if ( this->m_coarseness > 0 )
  {
    m_zRes = this->m_zRes;
    v13 = 1;
    if ( this->m_xRes > m_zRes )
      m_zRes = this->m_xRes;
    for ( i = m_zRes - 1; i > 1; ++v13 )
      i >>= 1;
    v15 = v13 - coarseness;
    v109 = v15;
    if ( v15 > 0 )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_coarseTreeData->m_data,
        v15,
        24);
    v16 = 1 << coarseness;
    v17 = (1 << coarseness) + this->m_xRes - 1;
    v18 = p_m_coarseTreeData->m_capacityAndFlags & 0x3FFFFFFF;
    v115 = 1 << coarseness;
    v19 = v17 / (1 << coarseness);
    v20 = (v16 + this->m_zRes - 1) / v16;
    if ( p_m_coarseTreeData->m_size == v18 )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_coarseTreeData->m_data, 24);
    v21 = (__int64)&p_m_coarseTreeData->m_data[p_m_coarseTreeData->m_size];
    if ( v21 )
    {
      *(_QWORD *)v21 = 0i64;
      *(_DWORD *)(v21 + 8) = 0;
      *(_DWORD *)(v21 + 12) = 0x80000000;
    }
    v22 = p_m_coarseTreeData->m_size;
    v23 = (__int64)&p_m_coarseTreeData->m_data[v22];
    p_m_coarseTreeData->m_size = v22 + 1;
    v111 = v23;
    *(_DWORD *)(v23 + 16) = (v19 + 1) / 2;
    *(_DWORD *)(v23 + 20) = (v20 + 1) / 2;
    v24 = 2 * p_m_coarseTreeData->m_data->m_xRes * p_m_coarseTreeData->m_data->m_zRes;
    if ( (*(_DWORD *)(v23 + 12) & 0x3FFFFFFF) < v24 )
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v23, v24, 16);
    v25 = 0;
    v107 = 0;
    if ( *(int *)(v23 + 16) > 0 )
    {
      v26 = 1;
      v112 = 1;
      do
      {
        v27 = *(_DWORD *)(v23 + 20) <= 0;
        v116 = 0;
        if ( !v27 )
        {
          m_enum = HK_FAILURE;
          v108 = v26 + 1;
          result.m_enum = HK_FAILURE;
          do
          {
            m_xRes = this->m_xRes;
            v30 = (__m128)LODWORD(FLOAT_3_40282e38);
            v31 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v32 = (v26 - 1) * v16;
            if ( v26 * v16 + 1 < m_xRes )
              m_xRes = v26 * v16 + 1;
            if ( v32 < m_xRes )
            {
              v33 = v16 * (m_enum - 1);
              v34 = m_enum * v16 + 1;
              do
              {
                v35 = this->m_zRes;
                v36 = v33;
                if ( v34 < v35 )
                  v35 = v34;
                if ( v33 < v35 )
                {
                  do
                  {
                    v37 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                            this,
                            (unsigned int)v32,
                            (unsigned int)v36++);
                    v30 = (__m128)v30.m128_u32[0];
                    v30.m128_f32[0] = fminf(v30.m128_f32[0], v37);
                    v31 = (__m128)v31.m128_u32[0];
                    v31.m128_f32[0] = fmaxf(v31.m128_f32[0], v37);
                  }
                  while ( v36 < v35 );
                }
                ++v32;
              }
              while ( v32 < m_xRes );
              v16 = v115;
              m_enum = result.m_enum;
              v26 = v112;
            }
            v38 = this->m_xRes;
            v39 = (__m128)LODWORD(FLOAT_3_40282e38);
            v40 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v41 = (v26 - 1) * v16;
            if ( v26 * v16 + 1 < v38 )
              v38 = v26 * v16 + 1;
            if ( v41 < v38 )
            {
              v42 = m_enum * v16;
              v43 = (m_enum + 1) * v16 + 1;
              do
              {
                v44 = this->m_zRes;
                v45 = v42;
                if ( v43 < v44 )
                  v44 = v43;
                if ( v42 < v44 )
                {
                  do
                  {
                    v46 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                            this,
                            (unsigned int)v41,
                            (unsigned int)v45++);
                    v39 = (__m128)v39.m128_u32[0];
                    v40 = (__m128)v40.m128_u32[0];
                    v39.m128_f32[0] = fminf(v39.m128_f32[0], v46);
                    v40.m128_f32[0] = fmaxf(v40.m128_f32[0], v46);
                  }
                  while ( v45 < v44 );
                }
                ++v41;
              }
              while ( v41 < v38 );
              v16 = v115;
              v26 = v112;
            }
            v47 = this->m_xRes;
            v48 = v26 + 1;
            v49 = (__m128)LODWORD(FLOAT_3_40282e38);
            v50 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v51 = v26 * v16;
            if ( (v26 + 1) * v16 + 1 < v47 )
              v47 = (v26 + 1) * v16 + 1;
            if ( v51 < v47 )
            {
              v52 = v16 * (result.m_enum - 1);
              v53 = result.m_enum * v16 + 1;
              do
              {
                v54 = this->m_zRes;
                v55 = v52;
                if ( v53 < v54 )
                  v54 = v53;
                if ( v52 < v54 )
                {
                  do
                  {
                    v56 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                            this,
                            (unsigned int)v51,
                            (unsigned int)v55++);
                    v49 = (__m128)v49.m128_u32[0];
                    v50 = (__m128)v50.m128_u32[0];
                    v49.m128_f32[0] = fminf(v49.m128_f32[0], v56);
                    v50.m128_f32[0] = fmaxf(v50.m128_f32[0], v56);
                  }
                  while ( v55 < v54 );
                }
                ++v51;
              }
              while ( v51 < v47 );
              v16 = v115;
              v26 = v112;
              v48 = v108;
            }
            v57 = this->m_xRes;
            v58 = (__m128)LODWORD(FLOAT_3_40282e38);
            v59 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v60 = v26 * v16;
            if ( v48 * v16 + 1 < v57 )
              v57 = v48 * v16 + 1;
            if ( v60 < v57 )
            {
              v61 = result.m_enum * v16;
              v62 = (result.m_enum + 1) * v16 + 1;
              do
              {
                v63 = this->m_zRes;
                v64 = v61;
                if ( v62 < v63 )
                  v63 = v62;
                if ( v61 < v63 )
                {
                  do
                  {
                    v65 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                            this,
                            (unsigned int)v60,
                            (unsigned int)v64++);
                    v58 = (__m128)v58.m128_u32[0];
                    v59 = (__m128)v59.m128_u32[0];
                    v58.m128_f32[0] = fminf(v58.m128_f32[0], v65);
                    v59.m128_f32[0] = fmaxf(v59.m128_f32[0], v65);
                  }
                  while ( v64 < v63 );
                }
                ++v60;
              }
              while ( v60 < v57 );
              v16 = v115;
              v26 = v112;
            }
            v23 = v111;
            m_enum = result.m_enum + 2;
            v67 = (__m128 *)(*(_QWORD *)v111 + 16i64 * *(int *)(v111 + 8));
            v66 = ++v116;
            result.m_enum += 2;
            *v67 = _mm_unpacklo_ps(_mm_unpacklo_ps(v30, v58), _mm_unpacklo_ps(v49, v39));
            ++*(_DWORD *)(v111 + 8);
            *(__m128 *)(*(_QWORD *)v111 + 16i64 * (int)(*(_DWORD *)(v111 + 8))++) = _mm_unpacklo_ps(
                                                                                      _mm_unpacklo_ps(v31, v59),
                                                                                      _mm_unpacklo_ps(v50, v40));
          }
          while ( v66 < *(_DWORD *)(v111 + 20) );
          v25 = v107;
        }
        ++v25;
        v26 += 2;
        v107 = v25;
        v112 = v26;
      }
      while ( v25 < *(_DWORD *)(v23 + 16) );
      p_m_coarseTreeData = v110;
    }
    if ( v109 > 1i64 )
    {
      v68 = 1i64;
      v113 = v109 - 1i64;
      do
      {
        v69 = p_m_coarseTreeData->m_data;
        v70 = p_m_coarseTreeData->m_data[v68 - 1].m_xRes;
        v71 = p_m_coarseTreeData->m_data[v68 - 1].m_zRes;
        if ( p_m_coarseTreeData->m_size == (p_m_coarseTreeData->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_coarseTreeData->m_data, 24);
        v72 = (__int64)&p_m_coarseTreeData->m_data[p_m_coarseTreeData->m_size];
        if ( v72 )
        {
          *(_QWORD *)v72 = 0i64;
          *(_DWORD *)(v72 + 8) = 0;
          *(_DWORD *)(v72 + 12) = 0x80000000;
        }
        v73 = p_m_coarseTreeData->m_size;
        v74 = (__int64)&p_m_coarseTreeData->m_data[v73];
        p_m_coarseTreeData->m_size = v73 + 1;
        v75 = (v70 + 1) / 2;
        *(_DWORD *)(v74 + 16) = v75;
        v76 = (v71 + 1) / 2;
        *(_DWORD *)(v74 + 20) = v76;
        v77 = 2 * v75 * v76;
        if ( (*(_DWORD *)(v74 + 12) & 0x3FFFFFFF) >= v77 )
          result.m_enum = HK_SUCCESS;
        else
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v74, v77, 16);
        v78 = 0;
        if ( v110->m_data[v68].m_xRes > 0 )
        {
          v79 = 0;
          v80 = 2 * v71;
          v81 = 0;
          do
          {
            v82 = 0;
            if ( *(int *)(v74 + 20) > 0 )
            {
              v83 = v81 + v71;
              v84 = 0;
              do
              {
                v85 = (__m128)xmmword_141A712A0;
                if ( v79 >= v70 || v84 + 1 >= v71 )
                {
                  v87 = (__m128)xmmword_141A712A0;
                }
                else
                {
                  v86 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v69[v68 - 1].m_minMaxData.m_data[2 * v81 + 2 + 2 * v84].m_quad,
                            v69[v68 - 1].m_minMaxData.m_data[2 * v81 + 2 + 2 * v84].m_quad,
                            78),
                          v69[v68 - 1].m_minMaxData.m_data[2 * v81 + 2 + 2 * v84].m_quad);
                  v87 = _mm_min_ps(v86, _mm_shuffle_ps(v86, v86, 177));
                }
                v88 = v79 + 1;
                if ( v79 + 1 >= v70 || v84 + 1 >= v71 )
                {
                  v90 = (__m128)xmmword_141A712A0;
                }
                else
                {
                  v89 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v69[v68 - 1].m_minMaxData.m_data[2 * v83 + 2 + 2 * v84].m_quad,
                            v69[v68 - 1].m_minMaxData.m_data[2 * v83 + 2 + 2 * v84].m_quad,
                            78),
                          v69[v68 - 1].m_minMaxData.m_data[2 * v83 + 2 + 2 * v84].m_quad);
                  v90 = _mm_min_ps(v89, _mm_shuffle_ps(v89, v89, 177));
                }
                if ( v88 >= v70 || v84 >= v71 )
                {
                  v92 = (__m128)xmmword_141A712A0;
                }
                else
                {
                  v91 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v69[v68 - 1].m_minMaxData.m_data[2 * v83 + 2 * v84].m_quad,
                            v69[v68 - 1].m_minMaxData.m_data[2 * v83 + 2 * v84].m_quad,
                            78),
                          v69[v68 - 1].m_minMaxData.m_data[2 * v83 + 2 * v84].m_quad);
                  v92 = _mm_min_ps(v91, _mm_shuffle_ps(v91, v91, 177));
                }
                if ( v79 < v70 && v84 < v71 )
                {
                  v93 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v69[v68 - 1].m_minMaxData.m_data[2 * v81 + 2 * v84].m_quad,
                            v69[v68 - 1].m_minMaxData.m_data[2 * v81 + 2 * v84].m_quad,
                            78),
                          v69[v68 - 1].m_minMaxData.m_data[2 * v81 + 2 * v84].m_quad);
                  v85 = _mm_min_ps(v93, _mm_shuffle_ps(v93, v93, 177));
                }
                v94 = _mm_movelh_ps(_mm_unpacklo_ps(v85, v92), _mm_unpacklo_ps(v90, v87));
                v95 = (__m128)xmmword_141A712F0;
                if ( v79 >= v70 || v84 + 1 >= v71 )
                {
                  v98 = (__m128)xmmword_141A712F0;
                }
                else
                {
                  v96 = 2 * (v81 + v84 + 1) + 1;
                  v97 = _mm_max_ps(
                          _mm_shuffle_ps(
                            v69[v68 - 1].m_minMaxData.m_data[v96].m_quad,
                            v69[v68 - 1].m_minMaxData.m_data[v96].m_quad,
                            78),
                          v69[v68 - 1].m_minMaxData.m_data[v96].m_quad);
                  v98 = _mm_max_ps(v97, _mm_shuffle_ps(v97, v97, 177));
                }
                if ( v88 >= v70 || v84 + 1 >= v71 )
                {
                  v101 = (__m128)xmmword_141A712F0;
                }
                else
                {
                  v99 = 2 * (v83 + v84 + 1) + 1;
                  v100 = _mm_max_ps(
                           _mm_shuffle_ps(
                             v69[v68 - 1].m_minMaxData.m_data[v99].m_quad,
                             v69[v68 - 1].m_minMaxData.m_data[v99].m_quad,
                             78),
                           v69[v68 - 1].m_minMaxData.m_data[v99].m_quad);
                  v101 = _mm_max_ps(v100, _mm_shuffle_ps(v100, v100, 177));
                }
                if ( v88 >= v70 || v84 >= v71 )
                {
                  v104 = (__m128)xmmword_141A712F0;
                }
                else
                {
                  v102 = 2 * (v83 + v84) + 1;
                  v103 = _mm_max_ps(
                           _mm_shuffle_ps(
                             v69[v68 - 1].m_minMaxData.m_data[v102].m_quad,
                             v69[v68 - 1].m_minMaxData.m_data[v102].m_quad,
                             78),
                           v69[v68 - 1].m_minMaxData.m_data[v102].m_quad);
                  v104 = _mm_max_ps(v103, _mm_shuffle_ps(v103, v103, 177));
                }
                if ( v79 < v70 && v84 < v71 )
                {
                  v105 = 2 * (v81 + v84) + 1;
                  v106 = _mm_max_ps(
                           _mm_shuffle_ps(
                             v69[v68 - 1].m_minMaxData.m_data[v105].m_quad,
                             v69[v68 - 1].m_minMaxData.m_data[v105].m_quad,
                             78),
                           v69[v68 - 1].m_minMaxData.m_data[v105].m_quad);
                  v95 = _mm_max_ps(v106, _mm_shuffle_ps(v106, v106, 177));
                }
                ++v82;
                v84 += 2;
                *(__m128 *)(*(_QWORD *)v74 + 16i64 * (int)(*(_DWORD *)(v74 + 8))++) = v94;
                *(__m128 *)(*(_QWORD *)v74 + 16i64 * (int)(*(_DWORD *)(v74 + 8))++) = _mm_movelh_ps(
                                                                                        _mm_unpacklo_ps(v95, v104),
                                                                                        _mm_unpacklo_ps(v101, v98));
              }
              while ( v82 < *(_DWORD *)(v74 + 20) );
              v80 = 2 * v71;
            }
            v81 += v80;
            ++v78;
            v79 += 2;
            v80 = 2 * v71;
          }
          while ( v78 < v110->m_data[v68].m_xRes );
        }
        p_m_coarseTreeData = v110;
        ++v68;
        --v113;
      }
      while ( v113 );
    }
  }
} = v110;
        ++v68;
        --v113;
      }
      while ( v113 );
    }
  }
}

// File Line: 189
// RVA: 0xD33900
void __fastcall hkpSampledHeightFieldShape::setMinMaxTreeCoarseness(hkpSampledHeightFieldShape *this, int coarseness)
{
  this->m_coarseness = coarseness;
}

// File Line: 196
// RVA: 0xD34D50
void __fastcall createRotationMasks(
        hkcdRay *ray,
        int *rotOffsetOut,
        hkVector4fComparison *mask0Out,
        hkVector4fComparison *mask1Out,
        hkVector4fComparison *mask2Out,
        hkVector4fComparison *mask3Out)
{
  hkVector4f v6; // xmm1
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10[6]; // [rsp+0h] [rbp-18h]

  v6.m_quad = (__m128)ray->m_direction;
  v10[1] = 1;
  v10[2] = 5;
  v10[3] = 4;
  v10[0] = 0;
  *rotOffsetOut = 0;
  v7 = _mm_movemask_ps(_mm_cmplt_ps(v6.m_quad, (__m128)0i64)) & 5;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 3;
      if ( v9 )
      {
        if ( v9 == 1 )
          *rotOffsetOut = 2;
      }
      else
      {
        *rotOffsetOut = 3;
      }
    }
    else
    {
      *rotOffsetOut = 1;
    }
  }
  else
  {
    *rotOffsetOut = 0;
  }
  *mask0Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4 * v10[*rotOffsetOut]];
  *mask1Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4
                                                                                * v10[((unsigned __int8)*rotOffsetOut + 1) & 3]];
  *mask2Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4
                                                                                * v10[((unsigned __int8)*rotOffsetOut - 2) & 3]];
  *mask3Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4
                                                                                * v10[((unsigned __int8)*rotOffsetOut - 1) & 3]];
}

// File Line: 324
// RVA: 0xD33C30
void __fastcall hkpSampledHeightFieldShape::castRayCoarseTreeInternal(
        hkpSampledHeightFieldShape *this,
        hkVector4f *from,
        hkVector4f *to,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkpSampledHeightFieldShape *v5; // rbx
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __m128 m_quad; // xmm15
  int v13; // r10d
  int v14; // edx
  __m128i v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm14
  int v19; // r9d
  int v20; // eax
  int v21; // ecx
  int v22; // r11d
  __m128i si128; // xmm4
  __m128i v24; // xmm5
  unsigned int v25; // r11d
  unsigned int v26; // ecx
  unsigned int v27; // ecx
  __m128i v28; // xmm1
  __m128i v29; // xmm0
  __m128i v30; // xmm0
  __m128i v31; // xmm1
  unsigned int v32; // edx
  __m128i v33; // xmm1
  __m128i v34; // xmm0
  __m128i v35; // xmm0
  __m128i v36; // xmm1
  unsigned int v37; // ecx
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v42; // xmm13
  __m128 v43; // xmm0
  int v44; // r8d
  unsigned __int64 v45; // rdx
  int v46; // ecx
  int v47; // ecx
  int v48; // ecx
  const int *v49; // r9
  int v50; // r10d
  int v51; // r11d
  char *v52; // rsi
  char *v53; // r14
  char *v54; // r15
  char *v55; // r12
  __m128 v56; // xmm8
  __m128 v57; // xmm9
  __m128 v58; // xmm11
  __m128 v59; // xmm12
  int v60; // ecx
  unsigned int v61; // edi
  unsigned int v62; // r13d
  __m128 v63; // xmm7
  __m128 v64; // xmm6
  float v65; // xmm0_4
  hkBaseObjectVtbl *v66; // rax
  __m128 v67; // xmm8
  float v68; // xmm0_4
  unsigned __int64 v69; // rax
  __m128 v70; // xmm11
  __m128 v71; // xmm12
  __m128 v72; // xmm5
  __m128 v73; // xmm4
  __m128 v74; // xmm3
  __m128 v75; // xmm0
  __m128 v76; // xmm2
  __m128 v77; // xmm3
  __m128 v78; // xmm9
  __m128 v79; // xmm10
  __m128 v80; // xmm11
  __m128 v81; // xmm8
  __m128 v82; // xmm8
  __m128 v83; // xmm12
  __m128 v84; // xmm4
  __m128 v85; // xmm7
  __m128 v86; // xmm7
  __m128 v87; // xmm1
  __m128 v88; // xmm3
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __m128 v92; // xmm5
  __m128 v93; // xmm2
  __m128 v94; // xmm1
  __m128 v95; // xmm2
  __m128 v96; // xmm6
  __m128 v97; // xmm1
  __m128 v98; // xmm6
  __m128 v99; // xmm3
  __m128 v100; // xmm5
  __m128 v101; // xmm3
  __m128 v102; // xmm5
  __m128 v103; // xmm4
  __m128 v104; // xmm5
  hkpShape *m_shape; // rax
  __m128 v106; // xmm1
  __m128 v107; // xmm3
  __m128 v108; // xmm2
  __m128 v109; // xmm4
  __m128 v110; // xmm8
  __m128 v111; // xmm9
  __m128 v112; // xmm12
  __m128 v113; // xmm7
  __m128 v114; // xmm7
  __m128 v115; // xmm1
  __m128 v116; // xmm3
  __m128 v117; // xmm1
  __m128 v118; // xmm2
  __m128 v119; // xmm1
  __m128 v120; // xmm6
  __m128 v121; // xmm2
  __m128 v122; // xmm0
  __m128 v123; // xmm1
  __m128 v124; // xmm10
  __m128 v125; // xmm2
  __m128 v126; // xmm10
  __m128 v127; // xmm5
  __m128 v128; // xmm3
  __m128 v129; // xmm5
  __m128 v130; // xmm6
  __m128 v131; // xmm3
  __m128 v132; // xmm6
  __m128 v133; // xmm4
  __m128 v134; // xmm5
  __m128 v135; // xmm1
  hkpShape *v136; // rax
  __m128 v137; // xmm3
  __m128 v138; // xmm2
  float v139; // ecx
  __m128 v140; // xmm4
  __m128 v141; // xmm5
  __m128 v142; // xmm3
  __m128 v143; // xmm1
  __m128 v144; // xmm2
  __m128 v145; // xmm1
  __m128 v146; // xmm2
  __m128 v147; // xmm1
  __m128 v148; // xmm2
  __m128 v149; // xmm1
  __m128 v150; // xmm0
  __m128 v151; // xmm3
  __m128 v152; // xmm2
  __m128 v153; // xmm11
  __m128 v154; // xmm12
  __m128 v155; // xmm11
  __m128 v156; // xmm1
  __m128 v157; // xmm6
  __m128 v158; // xmm10
  __m128 v159; // xmm0
  __m128 v160; // xmm4
  __m128 v161; // xmm6
  __m128 v162; // xmm8
  __m128 v163; // xmm5
  __m128 v164; // xmm9
  __m128 v165; // xmm5
  __m128 v166; // xmm2
  __m128 v167; // xmm7
  __m128 v168; // xmm2
  __m128 v169; // xmm1
  __m128 v170; // xmm3
  __m128 v171; // xmm0
  __m128 v172; // xmm1
  __m128 v173; // xmm0
  __m128 v174; // xmm0
  __m128 v175; // xmm1
  __m128 v176; // xmm0
  _QWORD *v177; // rax
  _QWORD *v178; // rcx
  _QWORD *v179; // r8
  unsigned __int64 v180; // rax
  _QWORD *v181; // rcx
  __m128 v182; // [rsp+30h] [rbp-C8h] BYREF
  __m128 v183; // [rsp+40h] [rbp-B8h]
  __m128 v184[2]; // [rsp+50h] [rbp-A8h] BYREF
  _BYTE v185[24]; // [rsp+70h] [rbp-88h]
  __m128 v186; // [rsp+88h] [rbp-70h]
  __m128 v187; // [rsp+98h] [rbp-60h]
  __m128 v188; // [rsp+A8h] [rbp-50h]
  __m128 v189; // [rsp+B8h] [rbp-40h]
  __m128 v190; // [rsp+C8h] [rbp-30h]
  __m128 v191; // [rsp+D8h] [rbp-20h] BYREF
  int v192; // [rsp+E8h] [rbp-10h]
  unsigned int v193; // [rsp+ECh] [rbp-Ch]
  int v194; // [rsp+F8h] [rbp+0h]
  int v195; // [rsp+118h] [rbp+20h]
  __m128 v196; // [rsp+128h] [rbp+30h]
  __m128 v197; // [rsp+138h] [rbp+40h]
  __m128 v198; // [rsp+148h] [rbp+50h]
  __m128 v199; // [rsp+158h] [rbp+60h]
  __m128 v200; // [rsp+168h] [rbp+70h]
  __m128 v201; // [rsp+198h] [rbp+A0h]
  __m128 v202; // [rsp+1A8h] [rbp+B0h]
  __m128 v203; // [rsp+1B8h] [rbp+C0h]
  unsigned int v204; // [rsp+1C8h] [rbp+D0h]
  int v205; // [rsp+1CCh] [rbp+D4h]
  int v206; // [rsp+1D0h] [rbp+D8h]
  char v207; // [rsp+1D8h] [rbp+E0h] BYREF
  char v208; // [rsp+1F8h] [rbp+100h] BYREF
  char v209; // [rsp+1FCh] [rbp+104h] BYREF
  char v210; // [rsp+200h] [rbp+108h] BYREF
  __m128 *retaddr; // [rsp+898h] [rbp+7A0h]
  hkpSampledHeightFieldShape *v212; // [rsp+8A0h] [rbp+7A8h] BYREF
  float v213; // [rsp+8A8h] [rbp+7B0h]
  __int64 v214; // [rsp+8B0h] [rbp+7B8h]
  hkpCdBody *v215; // [rsp+8B8h] [rbp+7C0h]

  v215 = cdBody;
  v212 = this;
  v5 = this;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcHeightFieldCoarse";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_quad = from->m_quad;
  v13 = (int)from->m_quad.m128_f32[0];
  v14 = v5->m_xRes - 2;
  v15 = (__m128i)_mm_sub_ps(to->m_quad, from->m_quad);
  v16 = _mm_cmpeq_ps((__m128)0i64, (__m128)v15);
  v17 = _mm_rcp_ps((__m128)v15);
  v18 = _mm_shuffle_ps((__m128)v15, _mm_unpackhi_ps((__m128)v15, query.m_quad), 196);
  v201 = _mm_or_ps(
           _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v15, 0x1Fu), 0x1Fu), (__m128)_xmm), v16),
           _mm_andnot_ps(v16, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v15, v17)), v17)));
  v201.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v18)) & 7 | 0x3F000000;
  if ( v13 >= 0 )
  {
    if ( v13 > v14 )
      v13 = v14;
  }
  else
  {
    v13 = 0;
  }
  v19 = (int)from->m_quad.m128_f32[2];
  v20 = v5->m_zRes - 2;
  if ( v19 >= 0 )
  {
    if ( v19 > v20 )
      v19 = v5->m_zRes - 2;
  }
  else
  {
    v19 = 0;
  }
  v21 = (int)to->m_quad.m128_f32[0];
  if ( v21 >= 0 )
  {
    if ( v21 > v14 )
      v21 = v14;
  }
  else
  {
    v21 = 0;
  }
  v22 = (int)to->m_quad.m128_f32[2];
  if ( v22 >= 0 )
  {
    if ( v22 > v20 )
      v22 = v5->m_zRes - 2;
  }
  else
  {
    v22 = 0;
  }
  si128 = _mm_load_si128((const __m128i *)&_xmm);
  v24 = _mm_load_si128((const __m128i *)&_xmm);
  v25 = v19 ^ v22;
  v26 = v13 ^ v21 | ((v13 ^ (unsigned int)v21) >> 1) | ((v13 ^ v21 | ((v13 ^ (unsigned int)v21) >> 1)) >> 2);
  v27 = v26 | (v26 >> 4) | ((v26 | (v26 >> 4)) >> 8);
  v28 = _mm_cvtsi32_si128(v27 | HIWORD(v27));
  v29 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v28, 1u), si128), _mm_and_si128(v28, si128));
  v30 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v29, 2u), v24), _mm_and_si128(v29, v24));
  v31 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v30, 4u), v30), (__m128i)_xmm), (__m128i)0i64);
  v32 = 32 - _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v31, 78), v31));
  v33 = _mm_cvtsi32_si128(v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4)) >> 8) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4)) >> 8)) >> 16));
  v34 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v33, 1u), si128), _mm_and_si128(v33, si128));
  v35 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v34, 2u), v24), _mm_and_si128(v34, v24));
  v36 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v35, 4u), v35), (__m128i)_xmm), (__m128i)0i64);
  v37 = 32 - _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v36, 78), v36));
  if ( v32 < v37 )
    v37 = v32;
  v38 = _mm_unpacklo_ps((__m128)LODWORD(v5->m_raycastMinY), (__m128)0i64);
  v204 = 32 - v37;
  v205 = v13 >> (32 - v37);
  v206 = v19 >> (32 - v37);
  v39 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            (__m128)COERCE_UNSIGNED_INT((float)(v205 * (1 << v204))),
            (__m128)COERCE_UNSIGNED_INT((float)(v206 * (1 << v204)))),
          v38);
  v40 = _mm_unpacklo_ps((__m128)LODWORD(v5->m_raycastMaxY), (__m128)0i64);
  v202 = v39;
  vfptr = v5->vfptr;
  v42 = _mm_shuffle_ps((__m128)v215->m_shapeKey, (__m128)v215->m_shapeKey, 0);
  v203 = _mm_unpacklo_ps(
           _mm_unpacklo_ps(
             (__m128)COERCE_UNSIGNED_INT((float)((1 << v204) * (v205 + 1))),
             (__m128)COERCE_UNSIGNED_INT((float)((1 << v204) * (v206 + 1)))),
           v40);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkpSampledHeightFieldShape **))vfptr[10].__first_virtual_table_function__)(
    v5,
    &v212);
  if ( (_BYTE)v212 )
    v43 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[60];
  else
    v43 = 0i64;
  v190 = v43;
  v44 = 0;
  v45 = 1i64;
  v182.m128_i32[0] = 0;
  v182.m128_i32[3] = 4;
  *(unsigned __int64 *)((char *)v182.m128_u64 + 4) = 0x500000001i64;
  LODWORD(v212) = 0;
  v46 = _mm_movemask_ps(_mm_cmplt_ps(v18, (__m128)0i64)) & 5;
  if ( !v46 )
    goto LABEL_29;
  v47 = v46 - 1;
  if ( !v47 )
  {
    v44 = 1;
    LODWORD(v212) = 1;
    goto LABEL_30;
  }
  v48 = v47 - 3;
  if ( !v48 )
  {
    v44 = 3;
    goto LABEL_29;
  }
  if ( v48 == 1 )
  {
    v44 = 2;
LABEL_29:
    LODWORD(v212) = v44;
  }
LABEL_30:
  v49 = hkVector4fComparison_maskToComparison_372;
  v50 = v44 + 1;
  v51 = v44 - 2;
  v52 = &v207;
  v53 = &v210;
  v54 = &v209;
  v55 = &v208;
  v56 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[v44]];
  *(__m128 *)&v185[8] = v56;
  v57 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 + 1) & 3]];
  v197 = v57;
  v58 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 - 2) & 3]];
  v187 = v58;
  v59 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 - 1) & 3]];
  v186 = v59;
  do
  {
    v60 = *((_DWORD *)v55 - 12);
    v61 = *((_DWORD *)v54 - 12);
    v62 = *((_DWORD *)v53 - 12);
    v63 = *((__m128 *)v52 - 3);
    v64 = *((__m128 *)v52 - 2);
    v52 -= 48;
    v55 -= 48;
    v54 -= 48;
    v53 -= 48;
    v183.m128_u64[0] = --v45;
    if ( v60 )
    {
      LODWORD(v139) = v60 - 1;
      v213 = v139;
      v140 = _mm_shuffle_ps(v63, v63, 85);
      v141 = _mm_shuffle_ps(v64, v64, 85);
      v184[0] = v140;
      v182 = v141;
      if ( SLODWORD(v139) < v5->m_coarseness )
        goto LABEL_53;
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD, _QWORD, __m128 *, __m128 *))v5->vfptr[9].__first_virtual_table_function__)(
        v5,
        LODWORD(v139),
        v61,
        v62,
        v184,
        &v182);
      v44 = (int)v212;
      v45 = v183.m128_u64[0];
      v140 = v184[0];
      v141 = v182;
      v50 = (_DWORD)v212 + 1;
      v51 = (_DWORD)v212 - 2;
      if ( (_DWORD)v212 == 1 )
      {
        v140 = _mm_shuffle_ps(v184[0], v184[0], 57);
        v141 = _mm_shuffle_ps(v182, v182, 57);
      }
      else
      {
        if ( (_DWORD)v212 != 2 )
        {
          v139 = v213;
          if ( (_DWORD)v212 != 3 )
            goto LABEL_53;
          v140 = _mm_shuffle_ps(v184[0], v184[0], 147);
          v141 = _mm_shuffle_ps(v182, v182, 147);
LABEL_52:
          v184[0] = v140;
          v182 = v141;
LABEL_53:
          v142 = _mm_mul_ps(_mm_add_ps(v64, v63), (__m128)xmmword_141A711B0);
          v143 = _mm_or_ps(_mm_andnot_ps(v56, v63), _mm_and_ps(v142, v56));
          v144 = _mm_or_ps(_mm_andnot_ps(v56, v142), _mm_and_ps(v64, v56));
          v200 = _mm_shuffle_ps(_mm_unpacklo_ps(v143, _mm_shuffle_ps(v140, v140, 0)), v143, 228);
          *(__m128 *)v185 = _mm_shuffle_ps(_mm_unpacklo_ps(v144, _mm_shuffle_ps(v141, v141, 0)), v144, 228);
          v145 = _mm_or_ps(_mm_andnot_ps(v57, v63), _mm_and_ps(v142, v57));
          v146 = _mm_or_ps(_mm_andnot_ps(v57, v142), _mm_and_ps(v64, v57));
          v198 = _mm_shuffle_ps(_mm_unpacklo_ps(v145, _mm_shuffle_ps(v140, v140, 85)), v145, 228);
          v183 = _mm_shuffle_ps(_mm_unpacklo_ps(v146, _mm_shuffle_ps(v141, v141, 85)), v146, 228);
          v147 = _mm_or_ps(_mm_andnot_ps(v58, v63), _mm_and_ps(v142, v58));
          v148 = _mm_or_ps(_mm_andnot_ps(v58, v142), _mm_and_ps(v64, v58));
          v189 = _mm_shuffle_ps(_mm_unpacklo_ps(v147, _mm_shuffle_ps(v140, v140, 170)), v147, 228);
          v149 = _mm_or_ps(_mm_andnot_ps(v59, v63), _mm_and_ps(v142, v59));
          v188 = _mm_shuffle_ps(_mm_unpacklo_ps(v148, _mm_shuffle_ps(v141, v141, 170)), v148, 228);
          v150 = _mm_or_ps(_mm_andnot_ps(v59, v142), _mm_and_ps(v64, v59));
          v151 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)v185, m_quad), v201);
          v152 = _mm_mul_ps(_mm_sub_ps(v183, m_quad), v201);
          v153 = _mm_mul_ps(_mm_sub_ps(v200, m_quad), v201);
          v196 = _mm_shuffle_ps(_mm_unpacklo_ps(v150, _mm_shuffle_ps(v141, v141, 255)), v150, 228);
          v199 = _mm_shuffle_ps(_mm_unpacklo_ps(v149, _mm_shuffle_ps(v140, v140, 255)), v149, 228);
          v154 = _mm_max_ps(v153, v151);
          v155 = _mm_min_ps(v153, v151);
          v156 = _mm_mul_ps(_mm_sub_ps(v188, m_quad), v201);
          v157 = _mm_mul_ps(_mm_sub_ps(v198, m_quad), v201);
          v158 = _mm_max_ps(v157, v152);
          v159 = _mm_mul_ps(_mm_sub_ps(v196, m_quad), v201);
          v160 = _mm_shuffle_ps(v154, v158, 68);
          v161 = _mm_min_ps(v157, v152);
          v162 = _mm_shuffle_ps(v155, v161, 68);
          v163 = _mm_mul_ps(_mm_sub_ps(v189, m_quad), v201);
          v164 = _mm_max_ps(v163, v156);
          v165 = _mm_min_ps(v163, v156);
          v166 = _mm_mul_ps(_mm_sub_ps(v199, m_quad), v201);
          v167 = _mm_max_ps(v166, v159);
          v168 = _mm_min_ps(v166, v159);
          v169 = _mm_shuffle_ps(v164, v167, 68);
          v170 = _mm_shuffle_ps(v165, v168, 68);
          v49 = (const int *)(unsigned int)_mm_movemask_ps(
                                             _mm_cmple_ps(
                                               _mm_max_ps(
                                                 _mm_max_ps(
                                                   _mm_shuffle_ps(v162, v170, 136),
                                                   _mm_shuffle_ps(v162, v170, 221)),
                                                 _mm_max_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_shuffle_ps(v155, v161, 238),
                                                     _mm_shuffle_ps(v165, v168, 238),
                                                     136),
                                                   aabbOut.m_quad)),
                                               _mm_min_ps(
                                                 _mm_min_ps(
                                                   _mm_shuffle_ps(v160, v169, 136),
                                                   _mm_shuffle_ps(v160, v169, 221)),
                                                 _mm_min_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_shuffle_ps(v154, v158, 238),
                                                     _mm_shuffle_ps(v164, v167, 238),
                                                     136),
                                                   v42))));
          if ( ((unsigned __int8)v49 & 4) != 0 )
          {
            v171 = v189;
            v172 = v188;
            *(float *)v55 = v139;
            v53 += 48;
            ++v45;
            v55 += 48;
            v54 += 48;
            *((_DWORD *)v54 - 12) = (((v44 - 1) >> 1) & 1) + 2 * v61;
            v52 += 48;
            *((_DWORD *)v53 - 12) = ((v51 >> 1) & 1) + 2 * v62;
            *((__m128 *)v52 - 3) = v171;
            *((__m128 *)v52 - 2) = v172;
          }
          if ( ((unsigned __int8)v49 & 2) != 0 )
          {
            v173 = v198;
            *(float *)v55 = v139;
            *(_DWORD *)v54 = ((v51 >> 1) & 1) + 2 * v61;
            *(_DWORD *)v53 = ((v50 >> 1) & 1) + 2 * v62;
            *(__m128 *)v52 = v173;
            *((__m128 *)v52 + 1) = v183;
          }
          else
          {
            if ( ((unsigned __int8)v49 & 8) == 0 )
              goto LABEL_60;
            v174 = v199;
            v175 = v196;
            *(float *)v55 = v139;
            *(_DWORD *)v54 = ((v44 >> 1) & 1) + 2 * v61;
            *(_DWORD *)v53 = (((v44 - 1) >> 1) & 1) + 2 * v62;
            *(__m128 *)v52 = v174;
            *((__m128 *)v52 + 1) = v175;
          }
          ++v45;
          v55 += 48;
          v54 += 48;
          v53 += 48;
          v52 += 48;
LABEL_60:
          if ( ((unsigned __int8)v49 & 1) != 0 )
          {
            v176 = v200;
            *(float *)v55 = v139;
            ++v45;
            v55 += 48;
            v54 += 48;
            v53 += 48;
            *((_DWORD *)v54 - 12) = ((v50 >> 1) & 1) + 2 * v61;
            v52 += 48;
            *((_DWORD *)v53 - 12) = ((v44 >> 1) & 1) + 2 * v62;
            *((__m128 *)v52 - 3) = v176;
            *((_OWORD *)v52 - 2) = *(_OWORD *)v185;
          }
          goto LABEL_62;
        }
        v140 = _mm_shuffle_ps(v184[0], v184[0], 78);
        v141 = _mm_shuffle_ps(v182, v182, 78);
      }
      v139 = v213;
      goto LABEL_52;
    }
    if ( (int)v61 < v5->m_xRes - 1 && (int)v62 < v5->m_zRes - 1 )
    {
      v65 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD, const int *))v5->vfptr[10].__vecDelDtor)(
              v5,
              v61,
              v62,
              v49);
      v66 = v5->vfptr;
      v213 = v65;
      v67 = _mm_shuffle_ps((__m128)LODWORD(v65), (__m128)LODWORD(v65), 0);
      v68 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v66[10].__vecDelDtor)(v5, v61 + 1, v62);
      v69 = retaddr->m128_u64[0];
      v213 = v68;
      v70 = _mm_shuffle_ps((__m128)LODWORD(v68), (__m128)LODWORD(v68), 0);
      v5 = (hkpSampledHeightFieldShape *)retaddr;
      v213 = (*(float (__fastcall **)(__m128 *, _QWORD, _QWORD))(v69 + 160))(retaddr, v61 + 1, v62 + 1);
      v71 = _mm_shuffle_ps((__m128)LODWORD(v213), (__m128)LODWORD(v213), 0);
      v213 = (*(float (__fastcall **)(__m128 *, _QWORD, _QWORD))(retaddr->m128_u64[0] + 160))(retaddr, v61, v62 + 1);
      *(__m128 *)v185 = _mm_shuffle_ps((__m128)LODWORD(v213), (__m128)LODWORD(v213), 0);
      v72 = _mm_shuffle_ps(
              _mm_unpacklo_ps(v63, _mm_min_ps(_mm_min_ps(v67, v70), _mm_min_ps(v71, *(__m128 *)v185))),
              v63,
              228);
      v73 = _mm_shuffle_ps(
              _mm_unpacklo_ps(v64, _mm_max_ps(_mm_max_ps(v67, v70), _mm_max_ps(v71, *(__m128 *)v185))),
              v64,
              228);
      v74 = _mm_mul_ps(v201, _mm_sub_ps(v72, m_quad));
      v75 = _mm_mul_ps(v201, _mm_sub_ps(v73, m_quad));
      v76 = _mm_min_ps(v74, v75);
      v77 = _mm_max_ps(v74, v75);
      if ( fmax(
             fmax(
               _mm_shuffle_ps(v76, v76, 170).m128_f32[0],
               fmax(_mm_shuffle_ps(v76, v76, 85).m128_f32[0], _mm_shuffle_ps(v76, v76, 0).m128_f32[0])),
             0.0) <= fmin(
                       fmin(
                         _mm_shuffle_ps(v77, v77, 170).m128_f32[0],
                         fmin(_mm_shuffle_ps(v77, v77, 85).m128_f32[0], _mm_shuffle_ps(v77, v77, 0).m128_f32[0])),
                       v42.m128_f32[0]) )
      {
        v192 = 1065353216;
        v193 = -1;
        v195 = 0;
        v194 = -1;
        v79 = _mm_shuffle_ps(_mm_unpacklo_ps(v72, v70), v72, 228);
        v78 = _mm_shuffle_ps(_mm_unpacklo_ps(v72, v67), v72, 228);
        v79.m128_f32[0] = v73.m128_f32[0];
        v80 = _mm_shuffle_ps(_mm_unpacklo_ps(v73, v71), v73, 228);
        v81 = _mm_shuffle_ps(_mm_unpacklo_ps(v72, *(__m128 *)v185), v72, 228);
        v82 = _mm_shuffle_ps(v81, _mm_unpackhi_ps(v81, _mm_shuffle_ps(v73, v73, 170)), 180);
        v83 = _mm_sub_ps(m_quad, v82);
        *(__m128 *)v185 = _mm_sub_ps(v78, v82);
        v84 = _mm_or_ps(_mm_andnot_ps(v190, v79), _mm_and_ps(v80, v190));
        v188 = _mm_sub_ps(v82, v84);
        v85 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v188, v188, 201), *(__m128 *)v185),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v185, *(__m128 *)v185, 201), v188));
        v86 = _mm_shuffle_ps(v85, v85, 201);
        v87 = _mm_mul_ps(v83, v86);
        v88 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                _mm_shuffle_ps(v87, v87, 170));
        v89 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, v42), v83), v86);
        v90 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
                _mm_shuffle_ps(v89, v89, 170));
        if ( _mm_movemask_ps(_mm_mul_ps(v90, v88)) )
        {
          v91 = _mm_sub_ps(v88, v90);
          v92 = _mm_shuffle_ps(v18, v18, 201);
          v93 = _mm_rcp_ps(v91);
          v94 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v93, v91)), v93);
          v95 = _mm_sub_ps(m_quad, v84);
          v96 = _mm_sub_ps(_mm_mul_ps(v92, v83), _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v18));
          v189 = _mm_mul_ps(v94, v88);
          v97 = _mm_sub_ps(m_quad, v78);
          v98 = _mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), *(__m128 *)v185);
          v99 = _mm_sub_ps(_mm_mul_ps(v92, v97), _mm_mul_ps(_mm_shuffle_ps(v97, v97, 201), v18));
          v100 = _mm_sub_ps(_mm_mul_ps(v92, v95), _mm_mul_ps(_mm_shuffle_ps(v95, v95, 201), v18));
          v101 = _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), _mm_sub_ps(v84, v78));
          v102 = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 201), v188);
          v103 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                   _mm_shuffle_ps(v101, v101, 170));
          if ( !(_mm_movemask_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)),
                       _mm_shuffle_ps(v98, v98, 170)),
                     v103)) | _mm_movemask_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                                    _mm_shuffle_ps(v102, v102, 170)),
                                  v103))) )
          {
            v42 = _mm_mul_ps(v42, v189);
            v104 = _mm_mul_ps(retaddr[6], v86);
            v192 = v42.m128_i32[0];
            v193 = 2 * (v61 + (v62 << 15));
            m_shape = v215->m_shape;
            v106 = _mm_mul_ps(v104, v104);
            v107 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                     _mm_shuffle_ps(v106, v106, 170));
            v108 = _mm_rsqrt_ps(v107);
            v191 = _mm_mul_ps(
                     v104,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v107, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v108, v107), v108)),
                         _mm_mul_ps(*(__m128 *)_xmm, v108))));
            ((void (__fastcall *)(hkpCdBody *, __int64, __m128 *))m_shape->vfptr)(v215, v214, &v191);
          }
        }
        v109 = _mm_or_ps(_mm_andnot_ps(v190, v82), _mm_and_ps(v78, v190));
        v110 = _mm_sub_ps(m_quad, v79);
        v111 = _mm_sub_ps(v80, v79);
        v112 = _mm_sub_ps(v79, v109);
        v113 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v112, v112, 201), v111),
                 _mm_mul_ps(_mm_shuffle_ps(v111, v111, 201), v112));
        v114 = _mm_shuffle_ps(v113, v113, 201);
        v115 = _mm_mul_ps(v110, v114);
        v116 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                 _mm_shuffle_ps(v115, v115, 170));
        v117 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, v42), v110), v114);
        v118 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                 _mm_shuffle_ps(v117, v117, 170));
        if ( _mm_movemask_ps(_mm_mul_ps(v118, v116)) )
        {
          v119 = _mm_sub_ps(v116, v118);
          v120 = _mm_shuffle_ps(v18, v18, 201);
          v121 = _mm_rcp_ps(v119);
          v122 = _mm_mul_ps(v121, v119);
          v123 = _mm_sub_ps(m_quad, v80);
          v124 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v122), v121);
          v125 = _mm_sub_ps(m_quad, v109);
          v126 = _mm_mul_ps(v124, v116);
          v127 = _mm_sub_ps(_mm_mul_ps(v120, v110), _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v18));
          v128 = _mm_sub_ps(_mm_mul_ps(v120, v123), _mm_mul_ps(_mm_shuffle_ps(v123, v123, 201), v18));
          v129 = _mm_mul_ps(_mm_shuffle_ps(v127, v127, 201), v111);
          v130 = _mm_sub_ps(_mm_mul_ps(v120, v125), _mm_mul_ps(_mm_shuffle_ps(v125, v125, 201), v18));
          v131 = _mm_mul_ps(_mm_shuffle_ps(v128, v128, 201), _mm_sub_ps(v109, v80));
          v132 = _mm_mul_ps(_mm_shuffle_ps(v130, v130, 201), v112);
          v133 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v131, v131, 85), _mm_shuffle_ps(v131, v131, 0)),
                   _mm_shuffle_ps(v131, v131, 170));
          if ( !(_mm_movemask_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                       _mm_shuffle_ps(v132, v132, 170)),
                     v133)) | _mm_movemask_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
                                    _mm_shuffle_ps(v129, v129, 170)),
                                  v133))) )
          {
            v42 = _mm_mul_ps(v42, v126);
            v134 = _mm_mul_ps(retaddr[6], v114);
            v192 = v42.m128_i32[0];
            v135 = _mm_mul_ps(v134, v134);
            v193 = 2 * (v61 + (v62 << 15)) + 1;
            v136 = v215->m_shape;
            v137 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
                     _mm_shuffle_ps(v135, v135, 170));
            v138 = _mm_rsqrt_ps(v137);
            v191 = _mm_mul_ps(
                     v134,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v137, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v138, v137), v138)),
                         _mm_mul_ps(*(__m128 *)_xmm, v138))));
            ((void (__fastcall *)(hkpCdBody *, __int64, __m128 *))v136->vfptr)(v215, v214, &v191);
          }
        }
      }
      v45 = v183.m128_u64[0];
LABEL_62:
      v59 = v186;
      v58 = v187;
      v56 = *(__m128 *)&v185[8];
    }
    v44 = (int)v212;
    v57 = v197;
    v50 = (_DWORD)v212 + 1;
    v51 = (_DWORD)v212 - 2;
  }
  while ( v45 );
  v177 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v178 = (_QWORD *)v177[1];
  v179 = v177;
  if ( (unsigned __int64)v178 < v177[3] )
  {
    *v178 = "Et";
    v180 = __rdtsc();
    v181 = v178 + 2;
    *((_DWORD *)v181 - 2) = v180;
    v179[1] = v181;
  }
}(_mm_mul_ps(v138, v137), v138)),
                         _mm_mul_ps(*(__m128 *)_xmm, v138))));
            ((void (__fastcall *)(hkpCdBody *, __int64, __m128 *))v136->vfptr)(v215, v214, &v191);
          }
        }
      }


