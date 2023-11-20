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
    (void (__fastcall *)())hkpSampledHeightField_registerCoarseTreeRayCastFunction);
}

// File Line: 34
// RVA: 0xD33910
void __fastcall hkpSampledHeightFieldShape::castRayCoarseTree(hkpSampledHeightFieldShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  __m128 v4; // xmm1
  hkVector4f to; // [rsp+30h] [rbp-28h]
  hkVector4f from; // [rsp+40h] [rbp-18h]

  hkOptionalComponent_hkpSampledHeightFieldShape_CoarseCast.m_isUsed.m_bool = 1;
  v4 = _mm_mul_ps(input->m_to.m_quad, this->m_floatToIntScale.m_quad);
  from.m_quad = _mm_mul_ps(input->m_from.m_quad, this->m_floatToIntScale.m_quad);
  to.m_quad = v4;
  hkpSampledHeightFieldShape::castRayCoarseTreeInternal(this, &from, &to, cdBody, collector);
}

// File Line: 44
// RVA: 0xD33960
void __fastcall hkpSampledHeightFieldShape::castSphereCoarseTree(hkpSampledHeightFieldShape *this, hkpHeightFieldShape::hkpSphereCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpRayHitCollector *v4; // r12
  hkpCdBody *v5; // r13
  hkpHeightFieldShape::hkpSphereCastInput *v6; // r15
  hkpSampledHeightFieldShape *v7; // rbx
  float v8; // xmm6_4
  __m128 v9; // xmm7
  __m128 v10; // xmm13
  __m128i v11; // xmm1
  unsigned int v12; // esi
  unsigned int v13; // edi
  float v14; // xmm8_4
  float v15; // xmm0_4
  float v16; // xmm9_4
  hkBaseObjectVtbl *v17; // rax
  hkBaseObjectVtbl *v18; // rax
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  hkBaseObjectVtbl *v22; // rax
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  hkVector4f to; // [rsp+30h] [rbp-C8h]
  hkVector4f from; // [rsp+40h] [rbp-B8h]
  int v27; // [rsp+100h] [rbp+8h]
  float v28; // [rsp+108h] [rbp+10h]

  hkOptionalComponent_hkpSampledHeightFieldShape_CoarseCast.m_isUsed.m_bool = 1;
  v4 = collector;
  v5 = cdBody;
  v6 = input;
  v7 = this;
  v8 = 0.0;
  v9 = _mm_mul_ps(input->m_from.m_quad, this->m_floatToIntScale.m_quad);
  v10 = _mm_mul_ps(input->m_to.m_quad, this->m_floatToIntScale.m_quad);
  v11 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
          _mm_cvttps_epi32(v9));
  v12 = _mm_cvtsi128_si32(v11);
  v13 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v11, 170));
  if ( v12 < this->m_xRes && v13 < this->m_zRes )
  {
    v14 = COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170)) - (float)(signed int)v13;
    v15 = (float)(signed int)v12;
    v16 = v9.m128_f32[0] - (float)(signed int)v12;
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, int *))this->vfptr[10].__first_virtual_table_function__)(
      this,
      &v27);
    v17 = v7->vfptr;
    if ( (_BYTE)v27 )
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v17[10].__vecDelDtor)(v7, v12, v13);
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v7->vfptr[10].__vecDelDtor)(
        v7,
        v12 + 1,
        v13 + 1);
      v18 = v7->vfptr;
      if ( v16 <= v14 )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v18[10].__vecDelDtor)(v7, v12, v13 + 1);
        v20 = v15 - v15;
        v19 = v15 - v15;
      }
      else
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v18[10].__vecDelDtor)(v7, v12 + 1, v13);
        v19 = v15 - v15;
        v20 = v15 - v15;
      }
      v21 = (float)((float)(v19 * v14) + v15) + (float)(v20 * v16);
    }
    else
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v17[10].__vecDelDtor)(v7, v12 + 1, v13);
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v7->vfptr[10].__vecDelDtor)(v7, v12, v13 + 1);
      v22 = v7->vfptr;
      if ( (float)(v16 + v14) <= 1.0 )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v22[10].__vecDelDtor)(v7, v12, v13);
        v21 = (float)((float)((float)(v15 - v15) * v14) + v15) + (float)((float)(v15 - v15) * v16);
      }
      else
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v22[10].__vecDelDtor)(v7, v12 + 1, v13 + 1);
        v21 = (float)((float)((float)(v15 - v15) * v14) + v15) + (float)((float)(v16 - 1.0) * (float)(v15 - v15));
      }
    }
    v8 = v21 - COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85));
  }
  v28 = v8;
  v23 = (__m128)LODWORD(v8);
  v27 = 0;
  v23.m128_f32[0] = fmaxf(v8, 0.0) + v6->m_maxExtraPenetration;
  v24 = _mm_unpacklo_ps((__m128)0i64, _mm_unpacklo_ps(v23, (__m128)0i64));
  from.m_quad = _mm_add_ps(v9, v24);
  to.m_quad = _mm_add_ps(v10, v24);
  hkpSampledHeightFieldShape::castRayCoarseTreeInternal(v7, &from, &to, v5, v4);
}

// File Line: 76
// RVA: 0xD34C70
hkSimdFloat32 *__fastcall calcNextMinHeight(hkSimdFloat32 *result, hkArray<hkVector4f,hkContainerHeapAllocator> *v, int xRes, int zRes, int x, int z)
{
  __m128 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm1

  if ( x >= xRes || z >= zRes )
  {
    v7 = result;
    *result = (hkSimdFloat32)xmmword_141A712A0;
  }
  else
  {
    v6 = v->m_data[2 * (z + x * zRes)].m_quad;
    v7 = result;
    v8 = _mm_min_ps(_mm_shuffle_ps(v6, v6, 78), v6);
    result->m_real = _mm_min_ps(v8, _mm_shuffle_ps(v8, v8, 177));
  }
  return v7;
}

// File Line: 85
// RVA: 0xD34CD0
hkSimdFloat32 *__fastcall calcNextMaxHeight(hkSimdFloat32 *result, hkArray<hkVector4f,hkContainerHeapAllocator> *v, int xRes, int zRes, int x, int z)
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
           _mm_shuffle_ps(v->m_data[2 * (z + x * zRes) + 1].m_quad, v->m_data[2 * (z + x * zRes) + 1].m_quad, 78),
           v->m_data[2 * (z + x * zRes) + 1].m_quad);
    result->m_real = _mm_max_ps(v7, _mm_shuffle_ps(v7, v7, 177));
  }
  return v6;
}

// File Line: 111
// RVA: 0xD32F10
void __usercall hkpSampledHeightFieldShape::buildCoarseMinMaxTree(hkpSampledHeightFieldShape *this@<rcx>, int coarseness@<edx>, float a3@<xmm0>)
{
  hkArray<hkpSampledHeightFieldShape::CoarseMinMaxLevel,hkContainerHeapAllocator> *v3; // r13
  int v4; // eax
  hkpSampledHeightFieldShape *v5; // rbx
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v6; // rcx
  int v7; // eax
  int v8; // er14
  __int64 v9; // rsi
  int *v10; // rdi
  int v11; // er8
  int v12; // eax
  int v13; // ecx
  signed int v14; // eax
  unsigned int i; // ecx
  int v16; // eax
  signed int v17; // er12
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  int v21; // esi
  signed __int64 v22; // rax
  __int64 v23; // rdx
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v24; // r14
  int v25; // er9
  int v26; // eax
  signed int v27; // edx
  bool v28; // zf
  bool v29; // sf
  hkResultEnum v30; // ecx
  int v31; // er15
  __m128 v32; // xmm12
  __m128 v33; // xmm13
  int v34; // er14
  int v35; // er13
  int v36; // er12
  int v37; // esi
  int v38; // edi
  int v39; // er15
  __m128 v40; // xmm10
  __m128 v41; // xmm11
  int v42; // er14
  int v43; // er13
  int v44; // er12
  int v45; // esi
  int v46; // edi
  int v47; // er15
  int v48; // ecx
  __m128 v49; // xmm8
  __m128 v50; // xmm9
  int v51; // er14
  __int32 v52; // er13
  __int32 v53; // er12
  __int32 v54; // esi
  __int32 v55; // edi
  int v56; // er15
  __m128 v57; // xmm6
  __m128 v58; // xmm7
  int v59; // er14
  __int32 v60; // er13
  __int32 v61; // er12
  __int32 v62; // esi
  __int32 v63; // edi
  int v64; // er8
  __m128 *v65; // rax
  signed __int64 v66; // rsi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v67; // r14
  int v68; // edi
  int v69; // ebx
  signed __int64 v70; // rdx
  __int64 v71; // rdx
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v72; // r15
  int v73; // ecx
  int v74; // eax
  int v75; // er9
  int v76; // er13
  int v77; // er9
  int v78; // eax
  int v79; // er10
  int v80; // er12
  int v81; // er11
  int v82; // edx
  __m128 v83; // xmm2
  __m128 v84; // xmm4
  __m128 v85; // xmm4
  int v86; // er8
  __m128 v87; // xmm1
  __m128 v88; // xmm1
  __m128 v89; // xmm3
  __m128 v90; // xmm3
  __m128 v91; // xmm2
  __m128 v92; // xmm2
  __m128 v93; // xmm1
  signed __int64 v94; // rcx
  __m128 v95; // xmm5
  __m128 v96; // xmm5
  signed __int64 v97; // rcx
  __m128 v98; // xmm3
  __m128 v99; // xmm3
  signed __int64 v100; // rcx
  __m128 v101; // xmm4
  __m128 v102; // xmm4
  signed __int64 v103; // rcx
  __m128 v104; // xmm1
  int v105; // [rsp+30h] [rbp-D0h]
  int v106; // [rsp+48h] [rbp-B8h]
  int v107; // [rsp+4Ch] [rbp-B4h]
  hkArray<hkpSampledHeightFieldShape::CoarseMinMaxLevel,hkContainerHeapAllocator> *v108; // [rsp+50h] [rbp-B0h]
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v109; // [rsp+58h] [rbp-A8h]
  signed int v110; // [rsp+150h] [rbp+50h]
  signed __int64 v111; // [rsp+150h] [rbp+50h]
  hkResult result; // [rsp+158h] [rbp+58h]
  int v113; // [rsp+160h] [rbp+60h]
  int v114; // [rsp+168h] [rbp+68h]

  v3 = &this->m_coarseTreeData;
  this->m_coarseness = coarseness;
  v4 = this->m_coarseTreeData.m_size;
  v5 = this;
  v6 = this->m_coarseTreeData.m_data;
  v7 = v4 - 1;
  v8 = coarseness;
  v108 = v3;
  v9 = v7;
  if ( v7 >= 0 )
  {
    v10 = &v6->m_minMaxData.m_capacityAndFlags + 6 * v7;
    do
    {
      v11 = *v10;
      *(v10 - 1) = 0;
      if ( v11 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v10 - 3),
          16 * v11);
      *(_QWORD *)(v10 - 3) = 0i64;
      *v10 = 2147483648;
      v10 -= 6;
      --v9;
    }
    while ( v9 >= 0 );
  }
  v12 = v3->m_capacityAndFlags;
  v3->m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_data,
      24 * (v12 & 0x3FFFFFFF));
  v3->m_data = 0i64;
  v3->m_capacityAndFlags = 2147483648;
  if ( v5->m_coarseness > 0 )
  {
    v13 = v5->m_zRes;
    v14 = 1;
    if ( v5->m_xRes > v13 )
      v13 = v5->m_xRes;
    for ( i = v13 - 1; i > 1; ++v14 )
      i >>= 1;
    v16 = v14 - v8;
    v107 = v16;
    if ( v16 > 0 )
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v16, 24);
    v17 = 1 << v8;
    v18 = (1 << v8) + v5->m_xRes - 1;
    v19 = v3->m_capacityAndFlags & 0x3FFFFFFF;
    v113 = 1 << v8;
    v20 = v18 / (1 << v8);
    v21 = (v17 + v5->m_zRes - 1) / v17;
    if ( v3->m_size == v19 )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 24);
    v22 = (signed __int64)&v3->m_data[v3->m_size];
    if ( v22 )
    {
      *(_QWORD *)v22 = 0i64;
      *(_DWORD *)(v22 + 8) = 0;
      *(_DWORD *)(v22 + 12) = 2147483648;
    }
    v23 = v3->m_size;
    v24 = &v3->m_data[v23];
    v3->m_size = v23 + 1;
    v109 = v24;
    v24->m_xRes = (v20 + 1) / 2;
    v24->m_zRes = (v21 + 1) / 2;
    v25 = 2 * v3->m_data->m_xRes * v3->m_data->m_zRes;
    if ( (v24->m_minMaxData.m_capacityAndFlags & 0x3FFFFFFF) < v25 )
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v24, v25, 16);
    v26 = 0;
    v105 = 0;
    if ( v24->m_xRes > 0 )
    {
      v27 = 1;
      v110 = 1;
      do
      {
        v28 = v24->m_zRes == 0;
        v29 = v24->m_zRes < 0;
        v114 = 0;
        if ( !v29 && !v28 )
        {
          v30 = 1;
          v106 = v27 + 1;
          result.m_enum = 1;
          do
          {
            v31 = v5->m_xRes;
            v32 = (__m128)LODWORD(FLOAT_3_40282e38);
            v33 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v34 = (v27 - 1) * v17;
            if ( v27 * v17 + 1 < v31 )
              v31 = v27 * v17 + 1;
            if ( v34 < v31 )
            {
              v35 = v17 * (v30 - 1);
              v36 = v30 * v17 + 1;
              do
              {
                v37 = v5->m_zRes;
                v38 = v35;
                if ( v36 < v37 )
                  v37 = v36;
                if ( v35 < v37 )
                {
                  do
                  {
                    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v5->vfptr[10].__vecDelDtor)(
                      v5,
                      (unsigned int)v34,
                      (unsigned int)v38++);
                    v32 = (__m128)v32.m128_u32[0];
                    v32.m128_f32[0] = fminf(v32.m128_f32[0], a3);
                    v33 = (__m128)v33.m128_u32[0];
                    v33.m128_f32[0] = fmaxf(v33.m128_f32[0], a3);
                  }
                  while ( v38 < v37 );
                }
                ++v34;
              }
              while ( v34 < v31 );
              v17 = v113;
              v30 = result.m_enum;
              v27 = v110;
            }
            v39 = v5->m_xRes;
            v40 = (__m128)LODWORD(FLOAT_3_40282e38);
            v41 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v42 = (v27 - 1) * v17;
            if ( v27 * v17 + 1 < v39 )
              v39 = v27 * v17 + 1;
            if ( v42 < v39 )
            {
              v43 = v30 * v17;
              v44 = (v30 + 1) * v17 + 1;
              do
              {
                v45 = v5->m_zRes;
                v46 = v43;
                if ( v44 < v45 )
                  v45 = v44;
                if ( v43 < v45 )
                {
                  do
                  {
                    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v5->vfptr[10].__vecDelDtor)(
                      v5,
                      (unsigned int)v42,
                      (unsigned int)v46++);
                    v40 = (__m128)v40.m128_u32[0];
                    v41 = (__m128)v41.m128_u32[0];
                    v40.m128_f32[0] = fminf(v40.m128_f32[0], a3);
                    v41.m128_f32[0] = fmaxf(v41.m128_f32[0], a3);
                  }
                  while ( v46 < v45 );
                }
                ++v42;
              }
              while ( v42 < v39 );
              v17 = v113;
              v27 = v110;
            }
            v47 = v5->m_xRes;
            v48 = v27 + 1;
            v49 = (__m128)LODWORD(FLOAT_3_40282e38);
            v50 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v51 = v27 * v17;
            if ( (v27 + 1) * v17 + 1 < v47 )
              v47 = (v27 + 1) * v17 + 1;
            if ( v51 < v47 )
            {
              v52 = v17 * (result.m_enum - 1);
              v53 = result.m_enum * v17 + 1;
              do
              {
                v54 = v5->m_zRes;
                v55 = v52;
                if ( v53 < v54 )
                  v54 = v53;
                if ( v52 < v54 )
                {
                  do
                  {
                    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v5->vfptr[10].__vecDelDtor)(
                      v5,
                      (unsigned int)v51,
                      (unsigned int)v55++);
                    v49 = (__m128)v49.m128_u32[0];
                    v50 = (__m128)v50.m128_u32[0];
                    v49.m128_f32[0] = fminf(v49.m128_f32[0], a3);
                    v50.m128_f32[0] = fmaxf(v50.m128_f32[0], a3);
                  }
                  while ( v55 < v54 );
                }
                ++v51;
              }
              while ( v51 < v47 );
              v17 = v113;
              v27 = v110;
              v48 = v106;
            }
            v56 = v5->m_xRes;
            v57 = (__m128)LODWORD(FLOAT_3_40282e38);
            v58 = (__m128)LODWORD(FLOAT_N3_40282e38);
            v59 = v27 * v17;
            if ( v48 * v17 + 1 < v56 )
              v56 = v48 * v17 + 1;
            if ( v59 < v56 )
            {
              v60 = result.m_enum * v17;
              v61 = (result.m_enum + 1) * v17 + 1;
              do
              {
                v62 = v5->m_zRes;
                v63 = v60;
                if ( v61 < v62 )
                  v62 = v61;
                if ( v60 < v62 )
                {
                  do
                  {
                    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v5->vfptr[10].__vecDelDtor)(
                      v5,
                      (unsigned int)v59,
                      (unsigned int)v63++);
                    v57 = (__m128)v57.m128_u32[0];
                    v58 = (__m128)v58.m128_u32[0];
                    v57.m128_f32[0] = fminf(v57.m128_f32[0], a3);
                    v58.m128_f32[0] = fmaxf(v58.m128_f32[0], a3);
                  }
                  while ( v63 < v62 );
                }
                ++v59;
              }
              while ( v59 < v56 );
              v17 = v113;
              v27 = v110;
            }
            v24 = v109;
            v30 = result.m_enum + 2;
            a3 = v58.m128_f32[0];
            v65 = &v109->m_minMaxData.m_data[v109->m_minMaxData.m_size].m_quad;
            v64 = ++v114;
            result.m_enum += 2;
            *v65 = _mm_unpacklo_ps(_mm_unpacklo_ps(v32, v57), _mm_unpacklo_ps(v49, v40));
            v24->m_minMaxData.m_data[++v24->m_minMaxData.m_size].m_quad = _mm_unpacklo_ps(
                                                                            _mm_unpacklo_ps(v33, v58),
                                                                            _mm_unpacklo_ps(v50, v41));
            ++v24->m_minMaxData.m_size;
          }
          while ( v64 < v109->m_zRes );
          v26 = v105;
        }
        ++v26;
        v27 += 2;
        v105 = v26;
        v110 = v27;
      }
      while ( v26 < v24->m_xRes );
      v3 = v108;
    }
    if ( v107 > 1i64 )
    {
      v66 = 1i64;
      v111 = v107 - 1i64;
      do
      {
        v67 = v3->m_data;
        v68 = *((_DWORD *)&v3->m_data[v66] - 2);
        v69 = *((_DWORD *)&v3->m_data[v66] - 1);
        if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 24);
        v70 = (signed __int64)&v3->m_data[v3->m_size];
        if ( v70 )
        {
          *(_QWORD *)v70 = 0i64;
          *(_DWORD *)(v70 + 8) = 0;
          *(_DWORD *)(v70 + 12) = 2147483648;
        }
        v71 = v3->m_size;
        v72 = &v3->m_data[v71];
        v3->m_size = v71 + 1;
        v73 = (v68 + 1) / 2;
        v72->m_xRes = v73;
        v74 = (v69 + 1) / 2;
        v72->m_zRes = v74;
        v75 = 2 * v73 * v74;
        if ( (v72->m_minMaxData.m_capacityAndFlags & 0x3FFFFFFF) >= v75 )
          result.m_enum = 0;
        else
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v72, v75, 16);
        v76 = 0;
        if ( v108->m_data[v66].m_xRes > 0 )
        {
          v77 = 0;
          v78 = 2 * v69;
          v79 = 0;
          do
          {
            v80 = 0;
            if ( v72->m_zRes > 0 )
            {
              v81 = v79 + v69;
              v82 = 0;
              do
              {
                v83 = (__m128)xmmword_141A712A0;
                if ( v77 >= v68 || v82 + 1 >= v69 )
                {
                  v85 = (__m128)xmmword_141A712A0;
                }
                else
                {
                  v84 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v79 + v82 + 1)].m_quad,
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v79 + v82 + 1)].m_quad,
                            78),
                          v67[v66 - 1].m_minMaxData.m_data[2 * (v79 + v82 + 1)].m_quad);
                  v85 = _mm_min_ps(v84, _mm_shuffle_ps(v84, v84, 177));
                }
                v86 = v77 + 1;
                if ( v77 + 1 >= v68 || v82 + 1 >= v69 )
                {
                  v88 = (__m128)xmmword_141A712A0;
                }
                else
                {
                  v87 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v81 + v82 + 1)].m_quad,
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v81 + v82 + 1)].m_quad,
                            78),
                          v67[v66 - 1].m_minMaxData.m_data[2 * (v81 + v82 + 1)].m_quad);
                  v88 = _mm_min_ps(v87, _mm_shuffle_ps(v87, v87, 177));
                }
                if ( v86 >= v68 || v82 >= v69 )
                {
                  v90 = (__m128)xmmword_141A712A0;
                }
                else
                {
                  v89 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v81 + v82)].m_quad,
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v81 + v82)].m_quad,
                            78),
                          v67[v66 - 1].m_minMaxData.m_data[2 * (v81 + v82)].m_quad);
                  v90 = _mm_min_ps(v89, _mm_shuffle_ps(v89, v89, 177));
                }
                if ( v77 < v68 && v82 < v69 )
                {
                  v91 = _mm_min_ps(
                          _mm_shuffle_ps(
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v79 + v82)].m_quad,
                            v67[v66 - 1].m_minMaxData.m_data[2 * (v79 + v82)].m_quad,
                            78),
                          v67[v66 - 1].m_minMaxData.m_data[2 * (v79 + v82)].m_quad);
                  v83 = _mm_min_ps(v91, _mm_shuffle_ps(v91, v91, 177));
                }
                v92 = _mm_movelh_ps(_mm_unpacklo_ps(v83, v90), _mm_unpacklo_ps(v88, v85));
                v93 = (__m128)xmmword_141A712F0;
                if ( v77 >= v68 || v82 + 1 >= v69 )
                {
                  v96 = (__m128)xmmword_141A712F0;
                }
                else
                {
                  v94 = 2 * (v79 + v82 + 1) + 1;
                  v95 = _mm_max_ps(
                          _mm_shuffle_ps(
                            v67[v66 - 1].m_minMaxData.m_data[v94].m_quad,
                            v67[v66 - 1].m_minMaxData.m_data[v94].m_quad,
                            78),
                          v67[v66 - 1].m_minMaxData.m_data[v94].m_quad);
                  v96 = _mm_max_ps(v95, _mm_shuffle_ps(v95, v95, 177));
                }
                if ( v86 >= v68 || v82 + 1 >= v69 )
                {
                  v99 = (__m128)xmmword_141A712F0;
                }
                else
                {
                  v97 = 2 * (v81 + v82 + 1) + 1;
                  v98 = _mm_max_ps(
                          _mm_shuffle_ps(
                            v67[v66 - 1].m_minMaxData.m_data[v97].m_quad,
                            v67[v66 - 1].m_minMaxData.m_data[v97].m_quad,
                            78),
                          v67[v66 - 1].m_minMaxData.m_data[v97].m_quad);
                  v99 = _mm_max_ps(v98, _mm_shuffle_ps(v98, v98, 177));
                }
                if ( v86 >= v68 || v82 >= v69 )
                {
                  v102 = (__m128)xmmword_141A712F0;
                }
                else
                {
                  v100 = 2 * (v81 + v82) + 1;
                  v101 = _mm_max_ps(
                           _mm_shuffle_ps(
                             v67[v66 - 1].m_minMaxData.m_data[v100].m_quad,
                             v67[v66 - 1].m_minMaxData.m_data[v100].m_quad,
                             78),
                           v67[v66 - 1].m_minMaxData.m_data[v100].m_quad);
                  v102 = _mm_max_ps(v101, _mm_shuffle_ps(v101, v101, 177));
                }
                if ( v77 < v68 && v82 < v69 )
                {
                  v103 = 2 * (v79 + v82) + 1;
                  v104 = _mm_max_ps(
                           _mm_shuffle_ps(
                             v67[v66 - 1].m_minMaxData.m_data[v103].m_quad,
                             v67[v66 - 1].m_minMaxData.m_data[v103].m_quad,
                             78),
                           v67[v66 - 1].m_minMaxData.m_data[v103].m_quad);
                  v93 = _mm_max_ps(v104, _mm_shuffle_ps(v104, v104, 177));
                }
                ++v80;
                v82 += 2;
                v72->m_minMaxData.m_data[v72->m_minMaxData.m_size++].m_quad = v92;
                v72->m_minMaxData.m_data[v72->m_minMaxData.m_size++].m_quad = _mm_movelh_ps(
                                                                                _mm_unpacklo_ps(v93, v102),
                                                                                _mm_unpacklo_ps(v99, v96));
              }
              while ( v80 < v72->m_zRes );
              v78 = 2 * v69;
            }
            v79 += v78;
            ++v76;
            v77 += 2;
            v78 = 2 * v69;
          }
          while ( v76 < v108->m_data[v66].m_xRes );
        }
        v3 = v108;
        ++v66;
        --v111;
      }
      while ( v111 );
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
void __fastcall createRotationMasks(hkcdRay *ray, int *rotOffsetOut, hkVector4fComparison *mask0Out, hkVector4fComparison *mask1Out, hkVector4fComparison *mask2Out, hkVector4fComparison *mask3Out)
{
  hkVector4f v6; // xmm1
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // [rsp+0h] [rbp-18h]
  int v11; // [rsp+4h] [rbp-14h]
  int v12; // [rsp+8h] [rbp-10h]
  int v13; // [rsp+Ch] [rbp-Ch]

  v6.m_quad = (__m128)ray->m_direction;
  v11 = 1;
  v12 = 5;
  v13 = 4;
  v10 = 0;
  *rotOffsetOut = 0;
  v7 = _mm_movemask_ps(_mm_cmpltps(v6.m_quad, (__m128)0i64)) & 5;
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
  *mask0Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4 * *(&v10 + *rotOffsetOut)];
  *mask1Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4
                                                                                * *(&v10
                                                                                  + (((unsigned __int8)*rotOffsetOut + 1) & 3))];
  *mask2Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4
                                                                                * *(&v10
                                                                                  + (((unsigned __int8)*rotOffsetOut - 2) & 3))];
  *mask3Out = *(hkVector4fComparison *)&hkVector4fComparison_maskToComparison_372[4
                                                                                * *(&v10
                                                                                  + (((unsigned __int8)*rotOffsetOut - 1) & 3))];
}

// File Line: 324
// RVA: 0xD33C30
void __fastcall hkpSampledHeightFieldShape::castRayCoarseTreeInternal(hkpSampledHeightFieldShape *this, hkVector4f *from, hkVector4f *to, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpSampledHeightFieldShape *v5; // rbx
  hkVector4f *v6; // rdi
  hkVector4f *v7; // rsi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm15
  signed int v13; // er10
  int v14; // edx
  __m128i v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm14
  int v19; // er9
  int v20; // eax
  signed int v21; // ecx
  int v22; // er11
  __m128i v23; // xmm4
  __m128i v24; // xmm5
  unsigned int v25; // er11
  unsigned int v26; // ecx
  unsigned int v27; // ecx
  __m128i v28; // xmm0
  __m128i v29; // xmm1
  __m128i v30; // xmm0
  __m128i v31; // xmm1
  unsigned int v32; // edx
  __m128i v33; // xmm0
  __m128i v34; // xmm1
  __m128i v35; // xmm0
  __m128i v36; // xmm1
  unsigned int v37; // ecx
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  hkBaseObjectVtbl *v41; // rax
  __m128 v42; // xmm13
  __m128 v43; // xmm0
  signed int v44; // er8
  signed __int64 v45; // rdx
  __m128 v46; // xmm0
  int v47; // ecx
  int v48; // ecx
  int v49; // ecx
  const int *v50; // r9
  int v51; // er10
  float v52; // eax
  int v53; // er11
  char *v54; // rsi
  char *v55; // r14
  char *v56; // r15
  char *v57; // r12
  __m128 v58; // xmm8
  __m128 v59; // xmm9
  __m128 v60; // xmm11
  int v61; // eax
  __m128 v62; // xmm12
  int v63; // ecx
  unsigned int v64; // edi
  unsigned int v65; // er13
  __m128 v66; // xmm7
  __m128 v67; // xmm6
  hkBaseObjectVtbl *v68; // rax
  __m128 v69; // xmm8
  unsigned __int64 v70; // rax
  __m128 v71; // xmm5
  __m128 v72; // xmm4
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm3
  __m128 v76; // xmm9
  __m128 v77; // xmm10
  __m128 v78; // xmm11
  __m128 v79; // xmm8
  __m128 v80; // xmm8
  __m128 v81; // xmm12
  __m128 v82; // xmm4
  __m128 v83; // xmm2
  __m128 v84; // xmm7
  __m128 v85; // xmm7
  __m128 v86; // xmm1
  __m128 v87; // xmm3
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm1
  __m128 v91; // xmm5
  __m128 v92; // xmm2
  __m128 v93; // xmm1
  __m128 v94; // xmm2
  __m128 v95; // xmm6
  __m128 v96; // xmm1
  __m128 v97; // xmm6
  __m128 v98; // xmm3
  __m128 v99; // xmm5
  __m128 v100; // xmm3
  __m128 v101; // xmm5
  __m128 v102; // xmm4
  __m128 v103; // xmm5
  hkpShape *v104; // rax
  __m128 v105; // xmm1
  __m128 v106; // xmm3
  __m128 v107; // xmm2
  __m128 v108; // xmm4
  __m128 v109; // xmm8
  __m128 v110; // xmm9
  __m128 v111; // xmm12
  __m128 v112; // xmm7
  __m128 v113; // xmm7
  __m128 v114; // xmm1
  __m128 v115; // xmm3
  __m128 v116; // xmm1
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  __m128 v119; // xmm6
  __m128 v120; // xmm2
  __m128 v121; // xmm0
  __m128 v122; // xmm1
  __m128 v123; // xmm10
  __m128 v124; // xmm2
  __m128 v125; // xmm10
  __m128 v126; // xmm5
  __m128 v127; // xmm3
  __m128 v128; // xmm5
  __m128 v129; // xmm6
  __m128 v130; // xmm3
  __m128 v131; // xmm6
  __m128 v132; // xmm4
  __m128 v133; // xmm5
  __m128 v134; // xmm1
  hkpShape *v135; // rax
  __m128 v136; // xmm3
  __m128 v137; // xmm2
  int v138; // ecx
  __m128 v139; // xmm4
  __m128 v140; // xmm5
  __m128 v141; // xmm3
  __m128 v142; // xmm1
  __m128 v143; // xmm2
  __m128 v144; // xmm1
  __m128 v145; // xmm2
  __m128 v146; // xmm1
  __m128 v147; // xmm2
  __m128 v148; // xmm1
  __m128 v149; // xmm0
  __m128 v150; // xmm12
  __m128 v151; // xmm3
  __m128 v152; // xmm2
  __m128 v153; // xmm11
  __m128 v154; // xmm7
  __m128 v155; // xmm12
  __m128 v156; // xmm11
  __m128 v157; // xmm1
  __m128 v158; // xmm10
  __m128 v159; // xmm9
  __m128 v160; // xmm6
  __m128 v161; // xmm10
  __m128 v162; // xmm0
  __m128 v163; // xmm4
  __m128 v164; // xmm6
  __m128 v165; // xmm7
  __m128 v166; // xmm8
  __m128 v167; // xmm5
  __m128 v168; // xmm9
  __m128 v169; // xmm5
  __m128 v170; // xmm2
  __m128 v171; // xmm7
  __m128 v172; // xmm2
  __m128 v173; // xmm1
  __m128 v174; // xmm3
  __m128 v175; // xmm1
  __m128 v176; // xmm1
  _QWORD *v177; // rax
  _QWORD *v178; // rcx
  _QWORD *v179; // r8
  unsigned __int64 v180; // rax
  signed __int64 v181; // rcx
  __m128 v182; // [rsp+30h] [rbp-C8h]
  __m128 v183; // [rsp+40h] [rbp-B8h]
  __m128 v184; // [rsp+50h] [rbp-A8h]
  char v185[24]; // [rsp+70h] [rbp-88h]
  __m128 v186; // [rsp+88h] [rbp-70h]
  __m128 v187; // [rsp+98h] [rbp-60h]
  __m128 v188; // [rsp+A8h] [rbp-50h]
  __m128 v189; // [rsp+B8h] [rbp-40h]
  __m128 v190; // [rsp+C8h] [rbp-30h]
  __m128 v191; // [rsp+D8h] [rbp-20h]
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
  char v207; // [rsp+1D8h] [rbp+E0h]
  char v208; // [rsp+1F8h] [rbp+100h]
  char v209; // [rsp+1FCh] [rbp+104h]
  char v210; // [rsp+200h] [rbp+108h]
  __m128 *retaddr; // [rsp+898h] [rbp+7A0h]
  hkpSampledHeightFieldShape *v212; // [rsp+8A0h] [rbp+7A8h]
  int v213; // [rsp+8A8h] [rbp+7B0h]
  __int64 v214; // [rsp+8B0h] [rbp+7B8h]
  hkpCdBody *v215; // [rsp+8B8h] [rbp+7C0h]

  v215 = cdBody;
  v212 = this;
  v5 = this;
  v6 = to;
  v7 = from;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcHeightFieldCoarse";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v7->m_quad;
  v13 = (signed int)v7->m_quad.m128_f32[0];
  v14 = v5->m_xRes - 2;
  v15 = (__m128i)_mm_sub_ps(v6->m_quad, v7->m_quad);
  v16 = _mm_cmpeqps((__m128)0i64, (__m128)v15);
  v17 = _mm_rcp_ps((__m128)v15);
  v18 = _mm_shuffle_ps((__m128)v15, _mm_unpackhi_ps((__m128)v15, query.m_quad), 196);
  v201 = _mm_or_ps(
           _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v15, 0x1Fu), 0x1Fu), (__m128)_xmm), v16),
           _mm_andnot_ps(v16, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v15, v17)), v17)));
  v201.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v18)) & 7 | 0x3F000000;
  if ( v13 >= 0 )
  {
    if ( v13 > v14 )
      v13 = v14;
  }
  else
  {
    v13 = 0;
  }
  v19 = (signed int)v7->m_quad.m128_f32[2];
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
  v21 = (signed int)v6->m_quad.m128_f32[0];
  if ( v21 >= 0 )
  {
    if ( v21 > v14 )
      v21 = v14;
  }
  else
  {
    v21 = 0;
  }
  v22 = (signed int)v6->m_quad.m128_f32[2];
  if ( v22 >= 0 )
  {
    if ( v22 > v20 )
      v22 = v5->m_zRes - 2;
  }
  else
  {
    v22 = 0;
  }
  v23 = _mm_load_si128((const __m128i *)&_xmm);
  v24 = _mm_load_si128((const __m128i *)&_xmm);
  v25 = v19 ^ v22;
  v26 = v13 ^ v21 | ((v13 ^ (unsigned int)v21) >> 1) | ((v13 ^ v21 | ((v13 ^ (unsigned int)v21) >> 1)) >> 2);
  v27 = v26 | (v26 >> 4) | ((v26 | (v26 >> 4)) >> 8);
  v28 = _mm_cvtsi32_si128(v27 | (v27 >> 16));
  v29 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v28, 1u), v23), _mm_and_si128(v28, v23));
  v30 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v29, 2u), v24), _mm_and_si128(v29, v24));
  v31 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v30, 4u), v30), (__m128i)_xmm), (__m128i)0i64);
  v32 = 32 - _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v31, 78), v31));
  v33 = _mm_cvtsi32_si128(v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4)) >> 8) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2) | ((v25 | (v25 >> 1) | ((v25 | (v25 >> 1)) >> 2)) >> 4)) >> 8)) >> 16));
  v34 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v33, 1u), v23), _mm_and_si128(v33, v23));
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
  v41 = v5->vfptr;
  v42 = _mm_shuffle_ps((__m128)v215->m_shapeKey, (__m128)v215->m_shapeKey, 0);
  v203 = _mm_unpacklo_ps(
           _mm_unpacklo_ps(
             (__m128)COERCE_UNSIGNED_INT((float)((1 << v204) * (v205 + 1))),
             (__m128)COERCE_UNSIGNED_INT((float)((1 << v204) * (v206 + 1)))),
           v40);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkpSampledHeightFieldShape **))v41[10].__first_virtual_table_function__)(
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
  v46 = _mm_cmpltps(v18, (__m128)0i64);
  v182.m128_i32[3] = 4;
  *(unsigned __int64 *)((char *)v182.m128_u64 + 4) = 21474836481i64;
  LODWORD(v212) = 0;
  v47 = _mm_movemask_ps(v46) & 5;
  if ( !v47 )
    goto LABEL_29;
  v48 = v47 - 1;
  if ( !v48 )
  {
    v44 = 1;
    LODWORD(v212) = 1;
    goto LABEL_30;
  }
  v49 = v48 - 3;
  if ( !v49 )
  {
    v44 = 3;
    goto LABEL_29;
  }
  if ( v49 == 1 )
  {
    v44 = 2;
LABEL_29:
    LODWORD(v212) = v44;
  }
LABEL_30:
  v50 = hkVector4fComparison_maskToComparison_372;
  v51 = v44 + 1;
  v52 = v182.m128_f32[v44];
  v53 = v44 - 2;
  v54 = &v207;
  v55 = &v210;
  v56 = &v209;
  v57 = &v208;
  v58 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * LODWORD(v52)];
  *(_OWORD *)&v185[8] = *(_OWORD *)&hkVector4fComparison_maskToComparison_372[4 * LODWORD(v52)];
  v59 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 + 1) & 3]];
  v197 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 + 1) & 3]];
  v60 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 - 2) & 3]];
  v187 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[4 * v182.m128_i32[((_BYTE)v44 - 2) & 3]];
  v61 = 4 * v182.m128_i32[((_BYTE)v44 - 1) & 3];
  v62 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[v61];
  v186 = *(__m128 *)&hkVector4fComparison_maskToComparison_372[v61];
  do
  {
    v63 = *((_DWORD *)v57 - 12);
    v64 = *((_DWORD *)v56 - 12);
    v65 = *((_DWORD *)v55 - 12);
    v66 = *((__m128 *)v54 - 3);
    v67 = *((__m128 *)v54 - 2);
    v54 -= 48;
    v57 -= 48;
    v56 -= 48;
    v55 -= 48;
    v183.m128_u64[0] = --v45;
    if ( v63 )
    {
      v138 = v63 - 1;
      v213 = v138;
      v139 = _mm_shuffle_ps(v66, v66, 85);
      v140 = _mm_shuffle_ps(v67, v67, 85);
      v184 = v139;
      v182 = v140;
      if ( v138 < v5->m_coarseness )
        goto LABEL_53;
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD, _QWORD, __m128 *, __m128 *))v5->vfptr[9].__first_virtual_table_function__)(
        v5,
        (unsigned int)v138,
        v64,
        v65,
        &v184,
        &v182);
      v44 = (signed int)v212;
      v45 = v183.m128_u64[0];
      v139 = v184;
      v140 = v182;
      v51 = (_DWORD)v212 + 1;
      v53 = (_DWORD)v212 - 2;
      if ( (_DWORD)v212 == 1 )
      {
        v139 = _mm_shuffle_ps(v184, v184, 57);
        v140 = _mm_shuffle_ps(v182, v182, 57);
      }
      else
      {
        if ( (_DWORD)v212 != 2 )
        {
          v138 = v213;
          if ( (_DWORD)v212 != 3 )
            goto LABEL_53;
          v139 = _mm_shuffle_ps(v184, v184, 147);
          v140 = _mm_shuffle_ps(v182, v182, 147);
LABEL_52:
          v184 = v139;
          v182 = v140;
LABEL_53:
          v141 = _mm_mul_ps(_mm_add_ps(v67, v66), (__m128)xmmword_141A711B0);
          v142 = _mm_or_ps(_mm_andnot_ps(v58, v66), _mm_and_ps(v141, v58));
          v143 = _mm_or_ps(_mm_andnot_ps(v58, v141), _mm_and_ps(v67, v58));
          v200 = _mm_shuffle_ps(_mm_unpacklo_ps(v142, _mm_shuffle_ps(v139, v139, 0)), v142, 228);
          *(__m128 *)v185 = _mm_shuffle_ps(_mm_unpacklo_ps(v143, _mm_shuffle_ps(v140, v140, 0)), v143, 228);
          v144 = _mm_or_ps(_mm_andnot_ps(v59, v66), _mm_and_ps(v141, v59));
          v145 = _mm_or_ps(_mm_andnot_ps(v59, v141), _mm_and_ps(v67, v59));
          v198 = _mm_shuffle_ps(_mm_unpacklo_ps(v144, _mm_shuffle_ps(v139, v139, 85)), v144, 228);
          v183 = _mm_shuffle_ps(_mm_unpacklo_ps(v145, _mm_shuffle_ps(v140, v140, 85)), v145, 228);
          v146 = _mm_or_ps(_mm_andnot_ps(v60, v66), _mm_and_ps(v141, v60));
          v147 = _mm_or_ps(_mm_andnot_ps(v60, v141), _mm_and_ps(v67, v60));
          v189 = _mm_shuffle_ps(_mm_unpacklo_ps(v146, _mm_shuffle_ps(v139, v139, 170)), v146, 228);
          v148 = _mm_or_ps(_mm_andnot_ps(v62, v66), _mm_and_ps(v141, v62));
          v188 = _mm_shuffle_ps(_mm_unpacklo_ps(v147, _mm_shuffle_ps(v140, v140, 170)), v147, 228);
          v149 = _mm_or_ps(_mm_andnot_ps(v62, v141), _mm_and_ps(v67, v62));
          v150 = _mm_mul_ps(_mm_sub_ps(v200, v12), v201);
          v151 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)v185, v12), v201);
          v152 = _mm_mul_ps(_mm_sub_ps(v183, v12), v201);
          v153 = v150;
          v196 = _mm_shuffle_ps(_mm_unpacklo_ps(v149, _mm_shuffle_ps(v140, v140, 255)), v149, 228);
          v154 = _mm_shuffle_ps(_mm_unpacklo_ps(v148, _mm_shuffle_ps(v139, v139, 255)), v148, 228);
          v199 = v154;
          v155 = _mm_max_ps(v150, v151);
          v156 = _mm_min_ps(v153, v151);
          v157 = _mm_mul_ps(_mm_sub_ps(v188, v12), v201);
          v158 = _mm_mul_ps(_mm_sub_ps(v198, v12), v201);
          v159 = _mm_mul_ps(_mm_sub_ps(v189, v12), v201);
          v160 = v158;
          v161 = _mm_max_ps(v158, v152);
          v162 = _mm_mul_ps(_mm_sub_ps(v196, v12), v201);
          v163 = _mm_shuffle_ps(v155, v161, 68);
          v164 = _mm_min_ps(v160, v152);
          v165 = _mm_mul_ps(_mm_sub_ps(v154, v12), v201);
          v166 = _mm_shuffle_ps(v156, v164, 68);
          v167 = v159;
          v168 = _mm_max_ps(v159, v157);
          v169 = _mm_min_ps(v167, v157);
          v170 = v165;
          v171 = _mm_max_ps(v165, v162);
          v172 = _mm_min_ps(v170, v162);
          v173 = _mm_shuffle_ps(v168, v171, 68);
          v174 = _mm_shuffle_ps(v169, v172, 68);
          v46 = _mm_shuffle_ps(v166, v174, 221);
          v50 = (const int *)(unsigned int)_mm_movemask_ps(
                                             _mm_cmpleps(
                                               _mm_max_ps(
                                                 _mm_max_ps(_mm_shuffle_ps(v166, v174, 136), v46),
                                                 _mm_max_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_shuffle_ps(v156, v164, 238),
                                                     _mm_shuffle_ps(v169, v172, 238),
                                                     136),
                                                   aabbOut.m_quad)),
                                               _mm_min_ps(
                                                 _mm_min_ps(
                                                   _mm_shuffle_ps(v163, v173, 136),
                                                   _mm_shuffle_ps(v163, v173, 221)),
                                                 _mm_min_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_shuffle_ps(v155, v161, 238),
                                                     _mm_shuffle_ps(v168, v171, 238),
                                                     136),
                                                   v42))));
          if ( (unsigned __int8)v50 & 4 )
          {
            v46 = v189;
            v175 = v188;
            *(_DWORD *)v57 = v138;
            v55 += 48;
            ++v45;
            v57 += 48;
            v56 += 48;
            *((_DWORD *)v56 - 12) = (((v44 - 1) >> 1) & 1) + 2 * v64;
            v54 += 48;
            *((_DWORD *)v55 - 12) = ((v53 >> 1) & 1) + 2 * v65;
            *((__m128 *)v54 - 3) = v46;
            *((__m128 *)v54 - 2) = v175;
          }
          if ( (unsigned __int8)v50 & 2 )
          {
            v46 = v198;
            *(_DWORD *)v57 = v138;
            *(_DWORD *)v56 = ((v53 >> 1) & 1) + 2 * v64;
            *(_DWORD *)v55 = ((v51 >> 1) & 1) + 2 * v65;
            *(__m128 *)v54 = v46;
            v46.m128_i32[0] = v183.m128_i32[0];
            *((__m128 *)v54 + 1) = v183;
          }
          else
          {
            if ( !((unsigned __int8)v50 & 8) )
              goto LABEL_60;
            v46 = v199;
            v176 = v196;
            *(_DWORD *)v57 = v138;
            *(_DWORD *)v56 = ((v44 >> 1) & 1) + 2 * v64;
            *(_DWORD *)v55 = (((v44 - 1) >> 1) & 1) + 2 * v65;
            *(__m128 *)v54 = v46;
            *((__m128 *)v54 + 1) = v176;
          }
          ++v45;
          v57 += 48;
          v56 += 48;
          v55 += 48;
          v54 += 48;
LABEL_60:
          if ( (unsigned __int8)v50 & 1 )
          {
            v46 = v200;
            *(_DWORD *)v57 = v138;
            ++v45;
            v57 += 48;
            v56 += 48;
            v55 += 48;
            *((_DWORD *)v56 - 12) = ((v51 >> 1) & 1) + 2 * v64;
            v54 += 48;
            *((_DWORD *)v55 - 12) = ((v44 >> 1) & 1) + 2 * v65;
            *((__m128 *)v54 - 3) = v46;
            v46.m128_i32[0] = *(_DWORD *)v185;
            *((_OWORD *)v54 - 2) = *(_OWORD *)v185;
          }
          goto LABEL_62;
        }
        v139 = _mm_shuffle_ps(v184, v184, 78);
        v140 = _mm_shuffle_ps(v182, v182, 78);
      }
      v138 = v213;
      goto LABEL_52;
    }
    if ( (signed int)v64 < v5->m_xRes - 1 && (signed int)v65 < v5->m_zRes - 1 )
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD, const int *))v5->vfptr[10].__vecDelDtor)(
        v5,
        v64,
        v65,
        v50);
      v68 = v5->vfptr;
      v213 = v46.m128_i32[0];
      v69 = _mm_shuffle_ps((__m128)v46.m128_u32[0], (__m128)v46.m128_u32[0], 0);
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v68[10].__vecDelDtor)(v5, v64 + 1, v65);
      v70 = retaddr->m128_u64[0];
      v213 = v46.m128_i32[0];
      (*(void (__fastcall **)(__m128 *, _QWORD, _QWORD))(v70 + 160))(retaddr, v64 + 1, v65 + 1);
      v5 = (hkpSampledHeightFieldShape *)retaddr;
      v213 = v46.m128_i32[0];
      (*(void (__fastcall **)(__m128 *, _QWORD, _QWORD))(retaddr->m128_u64[0] + 160))(retaddr, v64, v65 + 1);
      v213 = v46.m128_i32[0];
      *(__m128 *)v185 = v69;
      v71 = _mm_shuffle_ps(_mm_unpacklo_ps(v66, _mm_min_ps(_mm_min_ps(v69, v69), _mm_min_ps(v69, v69))), v66, 228);
      v72 = _mm_shuffle_ps(_mm_unpacklo_ps(v67, _mm_max_ps(_mm_max_ps(v69, v69), _mm_max_ps(v69, v69))), v67, 228);
      v73 = _mm_mul_ps(v201, _mm_sub_ps(v71, v12));
      v46 = _mm_mul_ps(v201, _mm_sub_ps(v72, v12));
      v74 = _mm_min_ps(v73, v46);
      v75 = _mm_max_ps(v73, v46);
      v46.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v75, v75, 0);
      if ( fmax(
             fmax(
               COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 170)),
               fmax(COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 85)), COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 0)))),
             0.0) <= fmin(
                       fmin(
                         COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 170)),
                         fmin(COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 85)), v46.m128_f32[0])),
                       v42.m128_f32[0]) )
      {
        v192 = 1065353216;
        v193 = -1;
        v195 = 0;
        v194 = -1;
        v77 = _mm_shuffle_ps(_mm_unpacklo_ps(v71, v69), v71, 228);
        v76 = v77;
        v77.m128_f32[0] = v72.m128_f32[0];
        v78 = _mm_shuffle_ps(_mm_unpacklo_ps(v72, v69), v72, 228);
        v79 = _mm_shuffle_ps(_mm_unpacklo_ps(v71, *(__m128 *)v185), v71, 228);
        v80 = _mm_shuffle_ps(v79, _mm_unpackhi_ps(v79, _mm_shuffle_ps(v72, v72, 170)), 180);
        v81 = _mm_sub_ps(v12, v80);
        *(__m128 *)v185 = _mm_sub_ps(v76, v80);
        v82 = _mm_or_ps(_mm_andnot_ps(v190, v77), _mm_and_ps(v78, v190));
        v83 = _mm_sub_ps(v80, v82);
        v188 = v83;
        v84 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), *(__m128 *)v185),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v185, *(__m128 *)v185, 201), v83));
        v85 = _mm_shuffle_ps(v84, v84, 201);
        v86 = _mm_mul_ps(v81, v85);
        v87 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
                _mm_shuffle_ps(v86, v86, 170));
        v88 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, v42), v81), v85);
        v89 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                _mm_shuffle_ps(v88, v88, 170));
        if ( _mm_movemask_ps(_mm_mul_ps(v89, v87)) )
        {
          v90 = _mm_sub_ps(v87, v89);
          v91 = _mm_shuffle_ps(v18, v18, 201);
          v92 = _mm_rcp_ps(v90);
          v93 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v92, v90)), v92);
          v94 = _mm_sub_ps(v12, v82);
          v95 = _mm_sub_ps(_mm_mul_ps(v91, v81), _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v18));
          v189 = _mm_mul_ps(v93, v87);
          v96 = _mm_sub_ps(v12, v76);
          v97 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 201), *(__m128 *)v185);
          v98 = _mm_sub_ps(_mm_mul_ps(v91, v96), _mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), v18));
          v99 = _mm_sub_ps(_mm_mul_ps(v91, v94), _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v18));
          v100 = _mm_mul_ps(_mm_shuffle_ps(v98, v98, 201), _mm_sub_ps(v82, v76));
          v101 = _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), v188);
          v102 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                   _mm_shuffle_ps(v100, v100, 170));
          if ( !(_mm_movemask_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                       _mm_shuffle_ps(v97, v97, 170)),
                     v102)) | _mm_movemask_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                                    _mm_shuffle_ps(v101, v101, 170)),
                                  v102))) )
          {
            v42 = _mm_mul_ps(v42, v189);
            v103 = _mm_mul_ps(retaddr[6], v85);
            v192 = v42.m128_i32[0];
            v193 = 2 * (v64 + (v65 << 15));
            v104 = v215->m_shape;
            v105 = _mm_mul_ps(v103, v103);
            v106 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                     _mm_shuffle_ps(v105, v105, 170));
            v107 = _mm_rsqrt_ps(v106);
            v191 = _mm_mul_ps(
                     v103,
                     _mm_andnot_ps(
                       _mm_cmpleps(v106, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v107, v106), v107)),
                         _mm_mul_ps(*(__m128 *)_xmm, v107))));
            ((void (__fastcall *)(hkpCdBody *, __int64, __m128 *))v104->vfptr)(v215, v214, &v191);
          }
        }
        v108 = _mm_or_ps(_mm_andnot_ps(v190, v80), _mm_and_ps(v76, v190));
        v109 = _mm_sub_ps(v12, v77);
        v110 = _mm_sub_ps(v78, v77);
        v111 = _mm_sub_ps(v77, v108);
        v112 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v111, v111, 201), v110),
                 _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v111));
        v113 = _mm_shuffle_ps(v112, v112, 201);
        v114 = _mm_mul_ps(v109, v113);
        v115 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                 _mm_shuffle_ps(v114, v114, 170));
        v116 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, v42), v109), v113);
        v117 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                 _mm_shuffle_ps(v116, v116, 170));
        v46 = _mm_mul_ps(v117, v115);
        if ( _mm_movemask_ps(v46) )
        {
          v118 = _mm_sub_ps(v115, v117);
          v119 = _mm_shuffle_ps(v18, v18, 201);
          v120 = _mm_rcp_ps(v118);
          v121 = _mm_mul_ps(v120, v118);
          v122 = _mm_sub_ps(v12, v78);
          v123 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v121), v120);
          v124 = _mm_sub_ps(v12, v108);
          v125 = _mm_mul_ps(v123, v115);
          v126 = _mm_sub_ps(_mm_mul_ps(v119, v109), _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v18));
          v127 = _mm_sub_ps(_mm_mul_ps(v119, v122), _mm_mul_ps(_mm_shuffle_ps(v122, v122, 201), v18));
          v128 = _mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v110);
          v129 = _mm_sub_ps(_mm_mul_ps(v119, v124), _mm_mul_ps(_mm_shuffle_ps(v124, v124, 201), v18));
          v130 = _mm_mul_ps(_mm_shuffle_ps(v127, v127, 201), _mm_sub_ps(v108, v78));
          v131 = _mm_mul_ps(_mm_shuffle_ps(v129, v129, 201), v111);
          v132 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                   _mm_shuffle_ps(v130, v130, 170));
          v46 = _mm_shuffle_ps(v131, v131, 0);
          if ( !(_mm_movemask_ps(
                   _mm_mul_ps(
                     _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v131, v131, 85), v46), _mm_shuffle_ps(v131, v131, 170)),
                     v132)) | _mm_movemask_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                                    _mm_shuffle_ps(v128, v128, 170)),
                                  v132))) )
          {
            v42 = _mm_mul_ps(v42, v125);
            v133 = _mm_mul_ps(retaddr[6], v113);
            v192 = v42.m128_i32[0];
            v134 = _mm_mul_ps(v133, v133);
            v193 = 2 * (v64 + (v65 << 15)) + 1;
            v135 = v215->m_shape;
            v136 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
                     _mm_shuffle_ps(v134, v134, 170));
            v137 = _mm_rsqrt_ps(v136);
            v46 = _mm_mul_ps(*(__m128 *)_xmm, v137);
            v191 = _mm_mul_ps(
                     v133,
                     _mm_andnot_ps(
                       _mm_cmpleps(v136, (__m128)0i64),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v137, v136), v137)), v46)));
            ((void (__fastcall *)(hkpCdBody *, __int64, __m128 *))v135->vfptr)(v215, v214, &v191);
          }
        }
      }
      v45 = v183.m128_u64[0];
LABEL_62:
      v62 = v186;
      v60 = v187;
      v58 = *(__m128 *)&v185[8];
    }
    v44 = (signed int)v212;
    v59 = v197;
    v51 = (_DWORD)v212 + 1;
    v53 = (_DWORD)v212 - 2;
  }
  while ( v45 );
  v177 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v178 = (_QWORD *)v177[1];
  v179 = v177;
  if ( (unsigned __int64)v178 < v177[3] )
  {
    *v178 = "Et";
    v180 = __rdtsc();
    v181 = (signed __int64)(v178 + 2);
    *(_DWORD *)(v181 - 8) = v180;
    v179[1] = v181;
  }
}mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v137, v136), v137)), v46)));
            ((void (__fastcall *)(hkpCdBody *, __int64, _

