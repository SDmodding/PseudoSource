// File Line: 12
// RVA: 0xCC24F0
__int64 __fastcall hkgpConvexHullImpl::build(hkgpConvexHullImpl *this, hkVector4f *points, const int numPoints, bool forcePlanar, hkgpConvexHullImpl *domain)
{
  bool v5; // si
  hkgpConvexHullImpl *v6; // rdi
  hkVector4f *v7; // r9
  int v8; // er9
  __int64 v9; // rcx
  __int64 v10; // rdx
  __m128 v11; // xmm0
  int v12; // eax
  unsigned int v13; // edi
  signed int v15; // er10
  hkgpConvexHullImpl *v16; // rax
  int v17; // eax
  hkVector4f *v18; // r9
  bool v19; // zf
  signed __int64 v20; // rsi
  signed __int64 v21; // rbx
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // er9
  int v26; // eax
  __int64 v27; // rdx
  int *v28; // rcx
  signed int v29; // edx
  __m128 *v30; // r9
  __int64 v31; // r8
  hkgpConvexHullImpl::Vertex *v32; // rcx
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128i v38; // xmm1
  int v39; // eax
  signed int v40; // er8
  int v41; // ecx
  int v42; // ecx
  int v43; // ecx
  signed int v44; // edi
  __m128 v45; // xmm3
  __int64 v46; // rcx
  __int64 v47; // r9
  __int64 v48; // r8
  hkgpConvexHullImpl::Vertex *v49; // rdx
  int v50; // ecx
  __int64 v51; // r9
  __int64 v52; // r8
  hkgpConvexHullImpl::Vertex *v53; // rdx
  int v54; // ecx
  signed int v55; // er8
  int v56; // er10
  int v57; // er9
  __int64 v58; // r8
  __int64 v59; // r9
  _DWORD *v60; // rcx
  __int64 v61; // r8
  __int64 v62; // r11
  int v63; // eax
  int v64; // esi
  int *v65; // r10
  int v66; // ecx
  hkgpConvexHullImpl::Vertex *v67; // rcx
  signed __int64 v68; // rdx
  __int64 v69; // rdx
  __int128 v70; // xmm0
  signed __int64 v71; // rcx
  signed __int64 v72; // rax
  __int64 v73; // r11
  int v74; // eax
  int *v75; // r10
  hkgpConvexHullImpl::Vertex *v76; // rcx
  signed __int64 v77; // rdx
  __int128 v78; // xmm0
  __int64 v79; // rdx
  int v80; // eax
  __int64 v81; // rcx
  int v82; // edi
  int v83; // eax
  int v84; // eax
  int v85; // er9
  int v86; // eax
  __int64 v87; // rdx
  _DWORD *v88; // rcx
  __m128 v89; // xmm3
  __int64 v90; // rcx
  __int64 v91; // r9
  __int64 v92; // r8
  hkgpConvexHullImpl::Vertex *v93; // rdx
  int v94; // ecx
  __int64 v95; // r9
  __int64 v96; // r8
  hkgpConvexHullImpl::Vertex *v97; // rdx
  int v98; // ecx
  signed int v99; // er8
  __m128 v100; // xmm1
  __m128 v101; // xmm4
  __m128 v102; // xmm1
  __m128 v103; // xmm0
  __m128 v104; // xmm2
  __int64 v105; // rcx
  __m128 *v106; // rax
  __m128 v107; // xmm4
  __m128 v108; // xmm5
  hkgpConvexHullImpl::Vertex *v109; // r9
  __int64 v110; // rax
  signed __int64 v111; // rdx
  __int64 v112; // rcx
  __m128 v113; // xmm3
  __m128 v114; // xmm1
  __m128 v115; // xmm0
  __m128 v116; // xmm6
  __m128 v117; // xmm6
  __m128 v118; // xmm1
  __m128 v119; // xmm5
  int v120; // edi
  int v121; // er9
  int v122; // er9
  hkVector4f *v123; // rdx
  hkgpConvexHullImpl::Vertex *v124; // r8
  signed __int64 v125; // r10
  signed __int64 v126; // r11
  __int64 v127; // rcx
  signed __int64 v128; // rdx
  unsigned __int64 v129; // r9
  __int128 v130; // xmm0
  signed __int64 v131; // r8
  signed __int64 v132; // rcx
  signed __int64 v133; // rdx
  __int128 v134; // xmm0
  signed __int64 v135; // r10
  signed __int64 v136; // r8
  hkVector4f *v137; // r10
  int v138; // eax
  signed __int64 v139; // r11
  signed __int64 v140; // rcx
  __int64 v141; // rdx
  unsigned __int64 v142; // r10
  __int64 v143; // r8
  signed __int64 v144; // rcx
  signed __int64 v145; // r9
  int v146; // er9
  __int64 v147; // r8
  hkgpConvexHullImpl::Vertex *v148; // rcx
  int v149; // edi
  __int64 v150; // rdx
  signed __int64 v151; // r8
  __int64 v152; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v153; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v154; // rdx
  __int64 v155; // rax
  hkgpConvexHullImpl::Vertex *v156; // rcx
  int v157; // eax
  __m128 v158; // xmm3
  __int64 v159; // rcx
  __int64 v160; // r8
  hkgpConvexHullImpl::Vertex *v161; // rdx
  int v162; // ecx
  __int64 v163; // r8
  hkgpConvexHullImpl::Vertex *v164; // rdx
  int v165; // ecx
  signed __int64 v166; // rdx
  signed __int64 v167; // r9
  signed __int64 v168; // r8
  __m128 v169; // xmm4
  hkgpConvexHullImpl::Vertex *v170; // rax
  signed __int64 v171; // r11
  signed __int64 v172; // rdi
  signed __int64 v173; // rcx
  __int64 v174; // r10
  __m128 v175; // xmm1
  __m128 v176; // xmm2
  float v177; // xmm3_4
  __m128 v178; // xmm2
  signed __int64 v179; // r9
  signed __int64 v180; // r8
  int v181; // eax
  int v182; // ecx
  int v183; // xmm1_4
  __int128 v184; // xmm6
  __int128 v185; // xmm8
  int v186; // xmm7_4
  int v187; // xmm9_4
  int v188; // xmm0_4
  unsigned int v189; // xmm1_4
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v190; // rax
  signed __int64 v191; // r8
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v192; // rsi
  __int64 v193; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v194; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v195; // rdx
  __int64 v196; // rax
  int v197; // eax
  int v198; // eax
  int v199; // eax
  int v200; // eax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v201; // rax
  signed __int64 v202; // r8
  __int64 v203; // rax
  hkgpConvexHullImpl::Vertex *v204; // rcx
  char v205; // [rsp+30h] [rbp-D0h]
  int v206; // [rsp+34h] [rbp-CCh]
  int v207; // [rsp+34h] [rbp-CCh]
  int v208; // [rsp+34h] [rbp-CCh]
  int v209; // [rsp+34h] [rbp-CCh]
  char v210; // [rsp+38h] [rbp-C8h]
  hkVector4f *array; // [rsp+40h] [rbp-C0h]
  int v212; // [rsp+48h] [rbp-B8h]
  int v213; // [rsp+4Ch] [rbp-B4h]
  int v214; // [rsp+50h] [rbp-B0h]
  signed __int64 v215; // [rsp+58h] [rbp-A8h]
  hkResult result; // [rsp+60h] [rbp-A0h]
  __int64 v217; // [rsp+68h] [rbp-98h]
  __int64 v218; // [rsp+70h] [rbp-90h]
  hkResult v219; // [rsp+78h] [rbp-88h]
  hkResult v220; // [rsp+7Ch] [rbp-84h]
  __int64 v221; // [rsp+80h] [rbp-80h]
  hkArray<hkgpConvexHullImpl::Vertex,hkContainerHeapAllocator> *v222; // [rsp+88h] [rbp-78h]
  unsigned __int64 v223; // [rsp+B0h] [rbp-50h]
  int v224; // [rsp+B8h] [rbp-48h]
  int v225; // [rsp+C0h] [rbp-40h]
  __int64 v226; // [rsp+F0h] [rbp-10h]
  int v227; // [rsp+F8h] [rbp-8h]
  const __m128i *v228; // [rsp+190h] [rbp+90h]
  hkVector4f *pointsa; // [rsp+198h] [rbp+98h]
  int numPointsa; // [rsp+1A0h] [rbp+A0h]
  bool v231; // [rsp+1A8h] [rbp+A8h]

  v231 = forcePlanar;
  numPointsa = numPoints;
  pointsa = points;
  v228 = (const __m128i *)this;
  v5 = forcePlanar;
  v6 = this;
  v7 = points;
  if ( numPoints && (unsigned __int8)points & 0xF )
  {
    v213 = 2147483648;
    array = 0i64;
    v212 = 0;
    if ( numPoints > 0 )
    {
      v8 = numPoints;
      if ( numPoints < 0 )
        v8 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v8, 16);
      numPoints = numPointsa;
      v7 = pointsa;
    }
    v212 = numPoints;
    if ( numPoints > 0 )
    {
      v9 = 0i64;
      v10 = (unsigned int)numPoints;
      do
      {
        v11 = v7->m_quad;
        ++v9;
        ++v7;
        array[v9 - 1] = (hkVector4f)v11;
        --v10;
      }
      while ( v10 );
    }
    v12 = hkgpConvexHullImpl::build(v6, array, numPoints, v5, domain);
    v212 = 0;
    v13 = v12;
    if ( v213 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v213);
    return v13;
  }
  hkgpConvexHullImpl::reset(this, v5);
  v15 = numPointsa;
  if ( numPointsa > 0 )
  {
    v16 = domain;
    if ( domain )
    {
      v6->m_origin = domain->m_origin;
      v6->m_scale = v16->m_scale;
      v6->m_scaleInv = v16->m_scaleInv;
    }
    else if ( v6->m_config.m_internalInputs.m_bool )
    {
      v6->m_origin = 0i64;
      v6->m_scale = (hkVector4f)query.m_quad;
      _mm_store_si128((__m128i *)&v6->m_scale, _mm_srli_si128(_mm_slli_si128((__m128i)query.m_quad, 4), 4));
      v6->m_scaleInv = (hkVector4f)query.m_quad;
      _mm_store_si128((__m128i *)&v6->m_scaleInv, _mm_srli_si128(_mm_slli_si128((__m128i)query.m_quad, 4), 4));
    }
    else
    {
      hkgpConvexHullImpl::rebuildDomainParameters(v6, pointsa, numPointsa);
      v15 = numPointsa;
    }
    v17 = 3;
    v205 = 0;
    if ( v15 - 1 < 3 )
      v17 = v15 - 1;
    v6->m_projectionAxis = 0i64;
    v6->m_dimensions = v17;
    if ( v5 )
    {
      v6->m_dimensions = 2;
    }
    else
    {
      v18 = &v6->m_projectionPlane;
      v6->m_projectionPlane = 0i64;
      if ( v15 > 1 )
        v6->m_projectionAxis.m_quad = _mm_sub_ps(pointsa[1].m_quad, pointsa->m_quad);
      if ( v15 <= 2
        || (v19 = v6->m_config.m_alwaysComputeProjectionPlane.m_bool == 0,
            *v18 = (hkVector4f)transform.m_quad,
            v18->m_quad = _mm_shuffle_ps(
                            transform.m_quad,
                            _mm_unpackhi_ps(
                              transform.m_quad,
                              _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(pointsa->m_quad, pointsa->m_quad, 0))),
                            196),
            v19) )
      {
LABEL_29:
        v20 = (signed __int64)&v6->m_pendings;
        v21 = 0i64;
        v6->m_pendings.m_size = 0;
        v22 = v6->m_pendings.m_capacityAndFlags;
        v222 = &v6->m_pendings;
        v23 = v22 & 0x3FFFFFFF;
        if ( v23 < v15 )
        {
          v24 = 2 * v23;
          v25 = v15;
          if ( v15 < v24 )
            v25 = v24;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v6->m_pendings,
            v25,
            64);
          v15 = numPointsa;
        }
        v26 = v15 - v6->m_pendings.m_size;
        v27 = v26;
        if ( v26 > 0 )
        {
          v28 = &v6->m_pendings.m_data[(signed __int64)v6->m_pendings.m_size].m_index;
          do
          {
            if ( v28 != (int *)52 )
            {
              *(v28 - 2) = 0;
              *v28 = -1;
            }
            v28 += 16;
            --v27;
          }
          while ( v27 );
        }
        v6->m_pendings.m_size = v15;
        v29 = 0;
        if ( v15 > 0 )
        {
          v30 = &pointsa->m_quad;
          v31 = 0i64;
          do
          {
            v32 = *(hkgpConvexHullImpl::Vertex **)v20;
            v33 = _mm_mul_ps(_mm_sub_ps(*v30, v6->m_origin.m_quad), v6->m_scale.m_quad);
            v34 = _mm_cmpltps(v33, (__m128)_xmm);
            v35 = _mm_max_ps(
                    (__m128)_xmm_c6000000c6000000c6000000c6000000,
                    _mm_or_ps(_mm_andnot_ps(v34, (__m128)_xmm), _mm_and_ps(v34, v33)));
            v36 = _mm_cmpltps(v35, (__m128)0i64);
            v32[v31].m_source.m_quad = *v30;
            v37 = _mm_or_ps(
                    _mm_andnot_ps(v36, _mm_add_ps(v35, (__m128)xmmword_141A711B0)),
                    _mm_and_ps(_mm_sub_ps(v35, (__m128)xmmword_141A711B0), v36));
            v38 = _mm_xor_si128(
                    (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v37),
                    _mm_cvttps_epi32(v37));
            v223 = v38.m128i_i64[0];
            *(_QWORD *)v32[v31].m_x = v38.m128i_i64[0];
            v224 = (unsigned __int128)_mm_shuffle_epi32(v38, 170);
            v32[v31].m_x[2] = v224;
            v39 = v225;
            v32[v31].m_index = -1;
            v32[v31].m_scratch = 0.0;
            v32[v31].m_refs = v39;
            if ( v6->m_config.m_setSourceIndices.m_bool )
              *(_DWORD *)(*(_QWORD *)v20 + v31 * 64 + 28) = v29 | 0x3F000000;
            ++v29;
            ++v30;
            ++v31;
          }
          while ( v29 < v15 );
        }
        if ( !v231 )
        {
          if ( v6->m_config.m_sortInputs.m_bool )
          {
            v40 = v6->m_pendings.m_size;
            if ( v40 > 1 )
            {
              hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::Vertex,hkAlgorithm::less<hkgpConvexHullImpl::Vertex>>(
                *(hkgpConvexHullImpl::Vertex **)v20,
                0,
                v40 - 1,
                0);
              v15 = numPointsa;
            }
          }
        }
        v221 = v15;
        while ( 1 )
        {
          v41 = v6->m_dimensions;
          v210 = 0;
          if ( !v41 )
            break;
          v42 = v41 - 1;
          if ( v42 )
          {
            v43 = v42 - 1;
            if ( v43 )
            {
              if ( v43 != 1 || hkgpConvexHullImpl::flushPending(v6) )
                goto LABEL_223;
              if ( !v6->m_config.m_allowLowerDimensions.m_bool )
              {
                v6->m_dimensions = -1;
                goto LABEL_223;
              }
              v15 = numPointsa;
              v6->m_dimensions = 2;
            }
            else
            {
              if ( !v205 )
              {
                hkgpConvexHullImpl::computeProjectionPlane(v6, pointsa, v15, &v6->m_projectionPlane);
                v205 = 1;
              }
              array = 0i64;
              v212 = 0;
              v213 = 2147483648;
              v44 = 0;
              v45 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v228 + 16), 1u), 1u);
              v46 = _mm_movemask_ps(
                      _mm_and_ps(
                        _mm_cmpleps(
                          _mm_max_ps(
                            _mm_shuffle_ps(v45, v45, 170),
                            _mm_max_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0))),
                          v45),
                        *(__m128 *)&hkVector4fComparison_maskToComparison_326[28]));
              if ( hkVector4Comparison_maskToLastIndex[v46] )
              {
                if ( hkVector4Comparison_maskToLastIndex[v46] == 1 )
                {
                  v47 = v228[6].m128i_i32[0];
                  if ( v47 > 0 )
                  {
                    v48 = 0i64;
                    do
                    {
                      v49 = *(hkgpConvexHullImpl::Vertex **)v20;
                      ++v48;
                      v50 = *(_DWORD *)(*(_QWORD *)v20 + v48 * 64 - 28);
                      *((_DWORD *)&v49[v48] - 7) = *(_DWORD *)(*(_QWORD *)v20 + v48 * 64 - 24);
                      *((_DWORD *)&v49[v48] - 6) = v50;
                      --v47;
                    }
                    while ( v47 );
                  }
                }
              }
              else
              {
                v51 = v228[6].m128i_i32[0];
                if ( v51 > 0 )
                {
                  v52 = 0i64;
                  do
                  {
                    v53 = *(hkgpConvexHullImpl::Vertex **)v20;
                    ++v52;
                    v54 = *(_DWORD *)(*(_QWORD *)v20 + v52 * 64 - 32);
                    *((_DWORD *)&v53[v52] - 8) = *(_DWORD *)(*(_QWORD *)v20 + v52 * 64 - 24);
                    *((_DWORD *)&v53[v52] - 6) = v54;
                    --v51;
                  }
                  while ( v51 );
                }
              }
              v55 = v228[6].m128i_i32[0];
              if ( v55 > 1 )
                hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::Vertex,hkAlgorithm::less<hkgpConvexHullImpl::Vertex>>(
                  *(hkgpConvexHullImpl::Vertex **)v20,
                  0,
                  v55 - 1,
                  0);
              v56 = 2 * numPointsa;
              v206 = 2 * numPointsa;
              if ( (v213 & 0x3FFFFFFF) >= 2 * numPointsa )
              {
                v220.m_enum = 0;
              }
              else
              {
                v57 = 2 * numPointsa;
                if ( v56 < 2 * (v213 & 0x3FFFFFFF) )
                  v57 = 2 * (v213 & 0x3FFFFFFF);
                hkArrayUtil::_reserve(
                  &v220,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &array,
                  v57,
                  64);
                v56 = v206;
              }
              v58 = v56 - v212;
              v59 = (__int64)&array[4 * (signed __int64)v212];
              if ( v56 - v212 > 0 )
              {
                v60 = (_DWORD *)(v59 + 52);
                do
                {
                  if ( v60 != (_DWORD *)52 )
                  {
                    *(v60 - 2) = 0;
                    *v60 = -1;
                  }
                  v60 += 16;
                  --v58;
                }
                while ( v58 );
              }
              v61 = v221;
              v212 = v56;
              v217 = 0i64;
              if ( v221 > 0 )
              {
                v62 = 0i64;
                v218 = 0i64;
                do
                {
                  if ( v21 >= 2 )
                  {
                    v63 = *(_DWORD *)(v62 + *(_QWORD *)v20 + 36);
                    v64 = *(_DWORD *)(v62 + *(_QWORD *)v20 + 32);
                    v65 = &array[4 * v21 - 6].m_quad.m128_i32[1];
                    do
                    {
                      v66 = (v64 - *(v65 - 1)) * (v65[16] - *v65);
                      v59 = (unsigned int)((v63 - *v65) * (v65[15] - *(v65 - 1)) - v66);
                      if ( (v63 - *v65) * (v65[15] - *(v65 - 1)) - v66 > 0 )
                        break;
                      --v21;
                      --v44;
                      v65 -= 16;
                    }
                    while ( v21 >= 2 );
                    v62 = v218;
                    v20 = (signed __int64)v222;
                    v61 = v221;
                  }
                  v67 = *(hkgpConvexHullImpl::Vertex **)v20;
                  v62 += 64i64;
                  v68 = v21 << 6;
                  ++v44;
                  ++v21;
                  v69 = (__int64)array + v68;
                  v70 = *(_OWORD *)(v62 + *(_QWORD *)v20 - 48);
                  v218 = v62;
                  *(_OWORD *)(v69 + 16) = v70;
                  *(_DWORD *)(v69 + 32) = *(_DWORD *)((char *)v67 + v62 - 32);
                  *(_DWORD *)(v69 + 36) = *(_DWORD *)((char *)v67 + v62 - 28);
                  *(_DWORD *)(v69 + 40) = *(_DWORD *)((char *)v67 + v62 - 24);
                  *(_DWORD *)(v69 + 44) = *(_DWORD *)((char *)v67 + v62 - 20);
                  *(_DWORD *)(v69 + 48) = *(_DWORD *)((char *)v67 + v62 - 16);
                  *(_DWORD *)(v69 + 52) = *(_DWORD *)((char *)v67 + v62 - 12);
                  ++v217;
                }
                while ( v217 < v61 );
              }
              v71 = v61 - 2;
              v72 = v44 + 1;
              v218 = v61 - 2;
              v215 = v44 + 1;
              if ( v61 - 2 >= 0 )
              {
                v73 = v71 << 6;
                v217 = v71 << 6;
                do
                {
                  if ( v21 >= v72 )
                  {
                    v74 = *(_DWORD *)(v73 + *(_QWORD *)v20 + 36);
                    v214 = *(_DWORD *)(v73 + *(_QWORD *)v20 + 32);
                    v75 = &array[4 * v21 - 6].m_quad.m128_i32[1];
                    do
                    {
                      v59 = (unsigned int)((v214 - *(v75 - 1)) * (v75[16] - *v75));
                      if ( (v74 - *v75) * (v75[15] - *(v75 - 1)) - (signed int)v59 > 0 )
                        break;
                      --v21;
                      --v44;
                      v75 -= 16;
                    }
                    while ( v21 >= v215 );
                    v73 = v217;
                    v20 = (signed __int64)v222;
                  }
                  v76 = *(hkgpConvexHullImpl::Vertex **)v20;
                  v73 -= 64i64;
                  v77 = v21 << 6;
                  ++v44;
                  ++v21;
                  v78 = *(_OWORD *)(v73 + *(_QWORD *)v20 + 80);
                  v79 = (__int64)array + v77;
                  v217 = v73;
                  *(_OWORD *)(v79 + 16) = v78;
                  *(_DWORD *)(v79 + 32) = *(int *)((char *)v76[1].m_x + v73);
                  *(_DWORD *)(v79 + 36) = *(int *)((char *)&v76[1].m_x[1] + v73);
                  *(_DWORD *)(v79 + 40) = *(int *)((char *)&v76[1].m_x[2] + v73);
                  *(float *)(v79 + 44) = *(float *)((char *)&v76[1].m_scratch + v73);
                  *(_DWORD *)(v79 + 48) = *(int *)((char *)&v76[1].m_refs + v73);
                  v80 = *(int *)((char *)&v76[1].m_index + v73);
                  v81 = v218 - 1;
                  *(_DWORD *)(v79 + 52) = v80;
                  v72 = v215;
                  v218 = v81;
                }
                while ( v81 >= 0 );
              }
              if ( v44 <= 3 )
              {
                v6 = (hkgpConvexHullImpl *)v228;
                v21 = 0i64;
                v158 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v228 + 16), 1u), 1u);
                v159 = _mm_movemask_ps(
                         _mm_and_ps(
                           _mm_cmpleps(
                             _mm_max_ps(
                               _mm_shuffle_ps(v158, v158, 170),
                               _mm_max_ps(_mm_shuffle_ps(v158, v158, 85), _mm_shuffle_ps(v158, v158, 0))),
                             v158),
                           *(__m128 *)&hkVector4fComparison_maskToComparison_326[28]));
                if ( hkVector4Comparison_maskToLastIndex[v159] )
                {
                  if ( hkVector4Comparison_maskToLastIndex[v159] == 1 )
                  {
                    v59 = v228[6].m128i_i32[0];
                    if ( v59 > 0 )
                    {
                      v160 = 0i64;
                      do
                      {
                        v161 = *(hkgpConvexHullImpl::Vertex **)v20;
                        ++v160;
                        v162 = *(_DWORD *)(*(_QWORD *)v20 + v160 * 64 - 28);
                        *((_DWORD *)&v161[v160] - 7) = *(_DWORD *)(*(_QWORD *)v20 + v160 * 64 - 24);
                        *((_DWORD *)&v161[v160] - 6) = v162;
                        --v59;
                      }
                      while ( v59 );
                    }
                  }
                }
                else
                {
                  v59 = v228[6].m128i_i32[0];
                  if ( v59 > 0 )
                  {
                    v163 = 0i64;
                    do
                    {
                      v164 = *(hkgpConvexHullImpl::Vertex **)v20;
                      ++v163;
                      v165 = *(_DWORD *)(*(_QWORD *)v20 + v163 * 64 - 32);
                      *((_DWORD *)&v164[v163] - 8) = *(_DWORD *)(*(_QWORD *)v20 + v163 * 64 - 24);
                      *((_DWORD *)&v164[v163] - 6) = v165;
                      --v59;
                    }
                    while ( v59 );
                  }
                }
                v228[30].m128i_i32[0] = 1;
                v210 = 1;
              }
              else
              {
                hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
                  (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v20,
                  (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
                v82 = v44 - 1;
                v83 = *(_DWORD *)(v20 + 12) & 0x3FFFFFFF;
                if ( v83 >= v82 )
                {
                  v21 = 0i64;
                  v219.m_enum = 0;
                }
                else
                {
                  v84 = 2 * v83;
                  v85 = v82;
                  if ( v82 < v84 )
                    v85 = v84;
                  hkArrayUtil::_reserve(
                    &v219,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    (void *)v20,
                    v85,
                    64);
                  v21 = 0i64;
                }
                v86 = v82 - *(_DWORD *)(v20 + 8);
                v87 = v86;
                if ( v86 > 0 )
                {
                  v88 = (_DWORD *)(*(_QWORD *)v20 + ((signed __int64)*(signed int *)(v20 + 8) << 6) + 52);
                  do
                  {
                    if ( v88 != (_DWORD *)52 )
                    {
                      *(v88 - 2) = 0;
                      *v88 = -1;
                    }
                    v88 += 16;
                    --v87;
                  }
                  while ( v87 );
                }
                *(_DWORD *)(v20 + 8) = v82;
                v6 = (hkgpConvexHullImpl *)v228;
                v89 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v228 + 16), 1u), 1u);
                v90 = _mm_movemask_ps(
                        _mm_and_ps(
                          _mm_cmpleps(
                            _mm_max_ps(
                              _mm_shuffle_ps(v89, v89, 170),
                              _mm_max_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0))),
                            v89),
                          *(__m128 *)&hkVector4fComparison_maskToComparison_326[28]));
                if ( hkVector4Comparison_maskToLastIndex[v90] )
                {
                  if ( hkVector4Comparison_maskToLastIndex[v90] == 1 )
                  {
                    v91 = v228[6].m128i_i32[0];
                    if ( v91 > 0 )
                    {
                      v92 = 0i64;
                      do
                      {
                        v93 = *(hkgpConvexHullImpl::Vertex **)v20;
                        ++v92;
                        v94 = *(_DWORD *)(*(_QWORD *)v20 + v92 * 64 - 28);
                        *((_DWORD *)&v93[v92] - 7) = *(_DWORD *)(*(_QWORD *)v20 + v92 * 64 - 24);
                        *((_DWORD *)&v93[v92] - 6) = v94;
                        --v91;
                      }
                      while ( v91 );
                    }
                  }
                }
                else
                {
                  v95 = v228[6].m128i_i32[0];
                  if ( v95 > 0 )
                  {
                    v96 = 0i64;
                    do
                    {
                      v97 = *(hkgpConvexHullImpl::Vertex **)v20;
                      ++v96;
                      v98 = *(_DWORD *)(*(_QWORD *)v20 + v96 * 64 - 32);
                      *((_DWORD *)&v97[v96] - 8) = *(_DWORD *)(*(_QWORD *)v20 + v96 * 64 - 24);
                      *((_DWORD *)&v97[v96] - 6) = v98;
                      --v95;
                    }
                    while ( v95 );
                  }
                }
                v99 = v228[6].m128i_i32[0];
                v100 = 0i64;
                v101 = 0i64;
                v100.m128_f32[0] = (float)v99;
                v102 = _mm_shuffle_ps(v100, v100, 0);
                v103 = _mm_rcp_ps(v102);
                v104 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v102, v103)), v103);
                if ( v99 > 0 )
                {
                  v105 = (unsigned int)v99;
                  v106 = (__m128 *)(*(_QWORD *)v20 + 16i64);
                  do
                  {
                    v101 = _mm_add_ps(v101, *v106);
                    v106 += 4;
                    --v105;
                  }
                  while ( v105 );
                }
                v107 = _mm_mul_ps(v101, v104);
                v108 = 0i64;
                if ( v99 > 0 )
                {
                  v109 = *(hkgpConvexHullImpl::Vertex **)v20;
                  v110 = 0i64;
                  v111 = (signed __int64)(v99 - 1) << 6;
                  v112 = v228[6].m128i_u32[0];
                  do
                  {
                    v113 = _mm_mul_ps(v108, v108);
                    v114 = _mm_sub_ps(*(__m128 *)((char *)&v109->m_source.m_quad + v111), v107);
                    v115 = _mm_sub_ps(v109[v110].m_source.m_quad, v107);
                    v116 = _mm_sub_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v115, v115, 201), v114),
                             _mm_mul_ps(_mm_shuffle_ps(v114, v114, 201), v115));
                    v117 = _mm_shuffle_ps(v116, v116, 201);
                    v118 = _mm_mul_ps(v117, v117);
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 170))) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 85))
                                                                                                + COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 0)))
                                                                                        + COERCE_FLOAT(
                                                                                            _mm_shuffle_ps(
                                                                                              v113,
                                                                                              v113,
                                                                                              170))) )
                      v108 = v117;
                    v111 = v110 * 64;
                    ++v110;
                    --v112;
                  }
                  while ( v112 );
                }
                v119 = _mm_mul_ps(v108, (__m128)v228[16]);
                if ( _mm_movemask_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                         _mm_shuffle_ps(v119, v119, 170))) )
                {
                  v120 = *(_DWORD *)(v20 + 8);
                  v121 = *(_DWORD *)(v20 + 8);
                  if ( v120 > v212 )
                    v121 = v212;
                  v207 = v121;
                  if ( (v213 & 0x3FFFFFFF) >= v120 )
                  {
                    result.m_enum = 0;
                  }
                  else
                  {
                    v122 = *(_DWORD *)(v20 + 8);
                    if ( v120 < 2 * (v213 & 0x3FFFFFFF) )
                      v122 = 2 * (v213 & 0x3FFFFFFF);
                    hkArrayUtil::_reserve(
                      &result,
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      &array,
                      v122,
                      64);
                    v121 = v207;
                  }
                  v123 = array;
                  v124 = *(hkgpConvexHullImpl::Vertex **)v20;
                  v125 = v121;
                  v126 = 0i64;
                  v215 = (signed __int64)array;
                  if ( v121 >= 4i64 )
                  {
                    v127 = (__int64)&array[6];
                    v128 = (signed __int64)v124[1].m_x;
                    v129 = ((unsigned __int64)(v121 - 4i64) >> 2) + 1;
                    v126 = 4 * v129;
                    do
                    {
                      v130 = *(_OWORD *)(v128 - 80);
                      v127 += 256i64;
                      v128 += 256i64;
                      *(_OWORD *)(v127 - 336) = v130;
                      *(_DWORD *)(v127 - 320) = *(_DWORD *)(v128 - 320);
                      *(_DWORD *)(v127 - 316) = *(_DWORD *)(v128 - 316);
                      *(_DWORD *)(v127 - 312) = *(_DWORD *)(v128 - 312);
                      *(_DWORD *)(v127 - 308) = *(_DWORD *)(v128 - 308);
                      *(_DWORD *)(v127 - 304) = *(_DWORD *)(v128 - 304);
                      *(_DWORD *)(v127 - 300) = *(_DWORD *)(v128 - 300);
                      *(_OWORD *)(v127 - 272) = *(_OWORD *)(v128 - 272);
                      *(_DWORD *)(v127 - 256) = *(_DWORD *)(v128 - 256);
                      *(_DWORD *)(v127 - 252) = *(_DWORD *)(v128 - 252);
                      *(_DWORD *)(v127 - 248) = *(_DWORD *)(v128 - 248);
                      *(_DWORD *)(v127 - 244) = *(_DWORD *)(v128 - 244);
                      *(_DWORD *)(v127 - 240) = *(_DWORD *)(v128 - 240);
                      *(_DWORD *)(v127 - 236) = *(_DWORD *)(v128 - 236);
                      *(_OWORD *)(v127 - 208) = *(_OWORD *)(v128 - 208);
                      *(_DWORD *)(v127 - 192) = *(_DWORD *)(v128 - 192);
                      *(_DWORD *)(v127 - 188) = *(_DWORD *)(v128 - 188);
                      *(_DWORD *)(v127 - 184) = *(_DWORD *)(v128 - 184);
                      *(_DWORD *)(v127 - 180) = *(_DWORD *)(v128 - 180);
                      *(_DWORD *)(v127 - 176) = *(_DWORD *)(v128 - 176);
                      *(_DWORD *)(v127 - 172) = *(_DWORD *)(v128 - 172);
                      *(_OWORD *)(v127 - 144) = *(_OWORD *)(v128 - 144);
                      *(_DWORD *)(v127 - 128) = *(_DWORD *)(v128 - 128);
                      *(_DWORD *)(v127 - 124) = *(_DWORD *)(v128 - 124);
                      *(_DWORD *)(v127 - 120) = *(_DWORD *)(v128 - 120);
                      *(_DWORD *)(v127 - 116) = *(_DWORD *)(v128 - 116);
                      *(_DWORD *)(v127 - 112) = *(_DWORD *)(v128 - 112);
                      *(_DWORD *)(v127 - 108) = *(_DWORD *)(v128 - 108);
                      --v129;
                    }
                    while ( v129 );
                    v121 = v207;
                    v123 = (hkVector4f *)v215;
                  }
                  if ( v126 < v125 )
                  {
                    v131 = (char *)v124 - (char *)v123;
                    v132 = (signed __int64)&v123[4 * v126 + 1];
                    v133 = v125 - v126;
                    do
                    {
                      v134 = *(_OWORD *)(v132 + v131);
                      v132 += 64i64;
                      *(_OWORD *)(v132 - 64) = v134;
                      *(_DWORD *)(v132 - 48) = *(_DWORD *)(v132 + v131 - 48);
                      *(_DWORD *)(v132 - 44) = *(_DWORD *)(v132 + v131 - 44);
                      *(_DWORD *)(v132 - 40) = *(_DWORD *)(v132 + v131 - 40);
                      *(_DWORD *)(v132 - 36) = *(_DWORD *)(v132 + v131 - 36);
                      *(_DWORD *)(v132 - 32) = *(_DWORD *)(v132 + v131 - 32);
                      *(_DWORD *)(v132 - 28) = *(_DWORD *)(v132 + v131 - 28);
                      --v133;
                    }
                    while ( v133 );
                  }
                  v135 = v125 << 6;
                  v136 = v135 + *(_QWORD *)v20;
                  v137 = (hkVector4f *)((char *)array + v135);
                  v138 = v120 - v121;
                  v215 = (signed __int64)v137;
                  v139 = 0i64;
                  if ( v120 - v121 >= 4i64 )
                  {
                    v140 = (signed __int64)&v137[5];
                    v141 = v136 - (_QWORD)v137;
                    v142 = ((unsigned __int64)(v138 - 4i64) >> 2) + 1;
                    v139 = 4 * v142;
                    do
                    {
                      if ( v140 != 80 )
                      {
                        *(_OWORD *)(v140 - 64) = *(_OWORD *)(v141 + v140 - 64);
                        *(_DWORD *)(v140 - 48) = *(_DWORD *)(v141 + v140 - 48);
                        *(_DWORD *)(v140 - 44) = *(_DWORD *)(v141 + v140 - 44);
                        *(_DWORD *)(v140 - 40) = *(_DWORD *)(v141 + v140 - 40);
                        *(_DWORD *)(v140 - 36) = *(_DWORD *)(v141 + v140 - 36);
                        *(_DWORD *)(v140 - 32) = *(_DWORD *)(v141 + v140 - 32);
                        *(_DWORD *)(v140 - 28) = *(_DWORD *)(v141 + v140 - 28);
                      }
                      if ( v140 != 16 )
                      {
                        *(_OWORD *)v140 = *(_OWORD *)(v141 + v140);
                        *(_DWORD *)(v140 + 16) = *(_DWORD *)(v141 + v140 + 16);
                        *(_DWORD *)(v140 + 20) = *(_DWORD *)(v141 + v140 + 20);
                        *(_DWORD *)(v140 + 24) = *(_DWORD *)(v141 + v140 + 24);
                        *(_DWORD *)(v140 + 28) = *(_DWORD *)(v141 + v140 + 28);
                        *(_DWORD *)(v140 + 32) = *(_DWORD *)(v141 + v140 + 32);
                        *(_DWORD *)(v140 + 36) = *(_DWORD *)(v141 + v140 + 36);
                      }
                      if ( v140 != -48 )
                      {
                        *(_OWORD *)(v140 + 64) = *(_OWORD *)(v141 + v140 + 64);
                        *(_DWORD *)(v140 + 80) = *(_DWORD *)(v141 + v140 + 80);
                        *(_DWORD *)(v140 + 84) = *(_DWORD *)(v141 + v140 + 84);
                        *(_DWORD *)(v140 + 88) = *(_DWORD *)(v141 + v140 + 88);
                        *(_DWORD *)(v140 + 92) = *(_DWORD *)(v141 + v140 + 92);
                        *(_DWORD *)(v140 + 96) = *(_DWORD *)(v141 + v140 + 96);
                        *(_DWORD *)(v140 + 100) = *(_DWORD *)(v141 + v140 + 100);
                      }
                      if ( v140 != -112 )
                      {
                        *(_OWORD *)(v140 + 128) = *(_OWORD *)(v141 + v140 + 128);
                        *(_DWORD *)(v140 + 144) = *(_DWORD *)(v141 + v140 + 144);
                        *(_DWORD *)(v140 + 148) = *(_DWORD *)(v141 + v140 + 148);
                        *(_DWORD *)(v140 + 152) = *(_DWORD *)(v141 + v140 + 152);
                        *(_DWORD *)(v140 + 156) = *(_DWORD *)(v141 + v140 + 156);
                        *(_DWORD *)(v140 + 160) = *(_DWORD *)(v141 + v140 + 160);
                        *(_DWORD *)(v140 + 164) = *(_DWORD *)(v141 + v140 + 164);
                      }
                      v140 += 256i64;
                      --v142;
                    }
                    while ( v142 );
                    v137 = (hkVector4f *)v215;
                  }
                  if ( v139 < v138 )
                  {
                    v143 = v136 - (_QWORD)v137;
                    v144 = (signed __int64)&v137[4 * v139 + 1];
                    v145 = v138 - v139;
                    do
                    {
                      if ( v144 != 16 )
                      {
                        *(_OWORD *)v144 = *(_OWORD *)(v143 + v144);
                        *(_DWORD *)(v144 + 16) = *(_DWORD *)(v143 + v144 + 16);
                        *(_DWORD *)(v144 + 20) = *(_DWORD *)(v143 + v144 + 20);
                        *(_DWORD *)(v144 + 24) = *(_DWORD *)(v143 + v144 + 24);
                        *(_DWORD *)(v144 + 28) = *(_DWORD *)(v143 + v144 + 28);
                        *(_DWORD *)(v144 + 32) = *(_DWORD *)(v143 + v144 + 32);
                        *(_DWORD *)(v144 + 36) = *(_DWORD *)(v143 + v144 + 36);
                      }
                      v144 += 64i64;
                      --v145;
                    }
                    while ( v145 );
                  }
                  v212 = v120;
                  v146 = 0;
                  if ( v120 > 0 )
                  {
                    v147 = 0i64;
                    do
                    {
                      v148 = *(hkgpConvexHullImpl::Vertex **)v20;
                      v149 = v120 - v146++;
                      ++v147;
                      v150 = (__int64)&array[4 * (signed __int64)(v149 - 1)];
                      *((_OWORD *)&v148[v147] - 3) = *(_OWORD *)(v150 + 16);
                      *((_DWORD *)&v148[v147] - 8) = *(_DWORD *)(v150 + 32);
                      *((_DWORD *)&v148[v147] - 7) = *(_DWORD *)(v150 + 36);
                      *((_DWORD *)&v148[v147] - 6) = *(_DWORD *)(v150 + 40);
                      *((_DWORD *)&v148[v147] - 5) = *(_DWORD *)(v150 + 44);
                      *((_DWORD *)&v148[v147] - 4) = *(_DWORD *)(v150 + 48);
                      *((_DWORD *)&v148[v147] - 3) = *(_DWORD *)(v150 + 52);
                      v120 = v212;
                    }
                    while ( v146 < v212 );
                  }
                  v6 = (hkgpConvexHullImpl *)v228;
                }
                v59 = 0i64;
                v208 = 0;
                if ( v6->m_pendings.m_size > 0 )
                {
                  v151 = (signed __int64)&v6->m_mesh.m_vertices;
                  v152 = 0i64;
                  v215 = v151;
                  do
                  {
                    v153 = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool **)v151;
                    if ( !*(_QWORD *)v151 || !v153->m_free )
                    {
                      v153 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> *)v151);
                      v151 = v215;
                      LODWORD(v59) = v208;
                    }
                    if ( v153 )
                    {
                      v154 = v153->m_free;
                      v153->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v154->m_data;
                      v154->m_pool = v153;
                      ++v153->m_used;
                      *(_DWORD *)&v154->m_data[44] = 0;
                      *(_DWORD *)&v154->m_data[52] = -1;
                      *(_QWORD *)&v154->m_data[8] = 0i64;
                      *(_QWORD *)v154->m_data = *(_QWORD *)(v151 + 8);
                      v155 = *(_QWORD *)(v151 + 8);
                      if ( v155 )
                        *(_QWORD *)(v155 + 8) = v154;
                      ++*(_DWORD *)(v151 + 16);
                      *(_QWORD *)(v151 + 8) = v154;
                    }
                    else
                    {
                      v154 = 0i64;
                    }
                    v156 = *(hkgpConvexHullImpl::Vertex **)v20;
                    v59 = (unsigned int)(v59 + 1);
                    ++v152;
                    v208 = v59;
                    *(_OWORD *)&v154->m_data[16] = *(_OWORD *)(v152 * 64 + *(_QWORD *)v20 - 48);
                    *(_DWORD *)&v154->m_data[32] = *((_DWORD *)&v156[v152] - 8);
                    *(_DWORD *)&v154->m_data[36] = *((_DWORD *)&v156[v152] - 7);
                    *(_DWORD *)&v154->m_data[40] = *((_DWORD *)&v156[v152] - 6);
                    *(_DWORD *)&v154->m_data[44] = *((_DWORD *)&v156[v152] - 5);
                    *(_DWORD *)&v154->m_data[48] = *((_DWORD *)&v156[v152] - 4);
                    v157 = *((_DWORD *)&v156[v152] - 3);
                    *(_DWORD *)&v154->m_data[48] = 0;
                    *(_DWORD *)&v154->m_data[52] = v157;
                  }
                  while ( (signed int)v59 < v228[6].m128i_i32[0] );
                  v6 = (hkgpConvexHullImpl *)v228;
                }
                *(_DWORD *)(v20 + 8) = 0;
              }
              v212 = 0;
              if ( v213 >= 0 )
                ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkVector4f *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
                  &hkContainerHeapAllocator::s_alloc,
                  array,
                  (unsigned int)(v213 << 6),
                  v59);
              array = 0i64;
              v213 = 2147483648;
              if ( !v210 )
                goto LABEL_223;
              v15 = numPointsa;
            }
          }
          else
          {
            v166 = 1i64;
            v167 = 0i64;
            v168 = 0i64;
            if ( v15 > 1 )
            {
              v169 = v6->m_projectionAxis.m_quad;
              v170 = *(hkgpConvexHullImpl::Vertex **)v20;
              v171 = 0i64;
              v172 = 0i64;
              v173 = 1i64;
              v174 = (unsigned int)(v15 - 1);
              do
              {
                v175 = _mm_mul_ps(v170[v173].m_source.m_quad, v169);
                v176 = _mm_mul_ps(*(__m128 *)((char *)&v170->m_source.m_quad + v172), v169);
                v177 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v175, v175, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v175, v175, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v175, v175, 170));
                if ( v177 < (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v176, v176, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v176, v176, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v176, v176, 170))) )
                {
                  v167 = v166;
                  v172 = v173 * 64;
                }
                v178 = _mm_mul_ps(*(__m128 *)((char *)&v170->m_source.m_quad + v171), v169);
                if ( v177 > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v178, v178, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v178, v178, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v178, v178, 170))) )
                {
                  v168 = v166;
                  v171 = v173 * 64;
                }
                ++v166;
                ++v173;
                --v174;
              }
              while ( v174 );
              v6 = (hkgpConvexHullImpl *)v228;
              v15 = numPointsa;
            }
            v179 = *(_QWORD *)v20 + (v167 << 6);
            v180 = *(_QWORD *)v20 + (v168 << 6);
            v181 = *(_DWORD *)(v180 + 52);
            v182 = *(_DWORD *)(v179 + 52);
            v183 = *(_DWORD *)(v179 + 36);
            v184 = *(_OWORD *)(v179 + 16);
            v185 = *(_OWORD *)(v180 + 16);
            v186 = *(_DWORD *)(v179 + 44);
            v187 = *(_DWORD *)(v180 + 44);
            LODWORD(v226) = *(_DWORD *)(v179 + 32);
            v209 = v181;
            v214 = v182;
            v188 = *(_DWORD *)(v179 + 40);
            HIDWORD(v226) = v183;
            v189 = *(_DWORD *)(v180 + 36);
            v227 = v188;
            v223 = __PAIR__(v189, *(_DWORD *)(v180 + 32));
            v224 = *(_DWORD *)(v180 + 40);
            if ( v226 != v223 )
            {
              v190 = v6->m_mesh.m_vertices.m_allocator.m_firstPool;
              v191 = (signed __int64)&v6->m_mesh.m_vertices;
              if ( !v190 || !v190->m_free )
              {
                v190 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_mesh.m_vertices.m_allocator);
                v191 = (signed __int64)&v6->m_mesh.m_vertices;
              }
              if ( v190 )
              {
                v192 = v190->m_free;
                v190->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v192->m_data;
                v192->m_pool = v190;
                ++v190->m_used;
                *(_DWORD *)&v192->m_data[44] = 0;
                *(_DWORD *)&v192->m_data[52] = -1;
                *(_QWORD *)&v192->m_data[8] = 0i64;
                *(_QWORD *)v192->m_data = *(_QWORD *)(v191 + 8);
                v193 = *(_QWORD *)(v191 + 8);
                if ( v193 )
                  *(_QWORD *)(v193 + 8) = v192;
                ++*(_DWORD *)(v191 + 16);
                *(_QWORD *)(v191 + 8) = v192;
              }
              else
              {
                v192 = 0i64;
              }
              v194 = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool **)v191;
              if ( !*(_QWORD *)v191 || !v194->m_free )
              {
                v194 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> *)v191);
                v191 = (signed __int64)&v6->m_mesh.m_vertices;
              }
              if ( v194 )
              {
                v195 = v194->m_free;
                v194->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v195->m_data;
                v195->m_pool = v194;
                ++v194->m_used;
                *(_DWORD *)&v195->m_data[44] = 0;
                *(_DWORD *)&v195->m_data[52] = -1;
                *(_QWORD *)&v195->m_data[8] = 0i64;
                *(_QWORD *)v195->m_data = *(_QWORD *)(v191 + 8);
                v196 = *(_QWORD *)(v191 + 8);
                if ( v196 )
                  *(_QWORD *)(v196 + 8) = v195;
                ++*(_DWORD *)(v191 + 16);
                *(_QWORD *)(v191 + 8) = v195;
              }
              else
              {
                v195 = 0i64;
              }
              v197 = v226;
              *(_OWORD *)&v192->m_data[16] = v184;
              *(_DWORD *)&v192->m_data[32] = v197;
              *(_DWORD *)&v192->m_data[36] = HIDWORD(v226);
              *(_DWORD *)&v192->m_data[40] = v227;
              v198 = v214;
              *(_DWORD *)&v192->m_data[48] = 0;
              *(_DWORD *)&v192->m_data[44] = v186;
              *(_DWORD *)&v192->m_data[52] = v198;
              v199 = v223;
              *(_OWORD *)&v195->m_data[16] = v185;
              *(_DWORD *)&v195->m_data[32] = v199;
              *(_DWORD *)&v195->m_data[36] = HIDWORD(v223);
              *(_DWORD *)&v195->m_data[40] = v224;
              v200 = v209;
              *(_DWORD *)&v195->m_data[44] = v187;
              goto LABEL_222;
            }
            v6->m_dimensions = 0;
          }
        }
        v201 = v6->m_mesh.m_vertices.m_allocator.m_firstPool;
        v202 = (signed __int64)&v6->m_mesh.m_vertices;
        if ( !v201 || !v201->m_free )
        {
          v201 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_mesh.m_vertices.m_allocator);
          v202 = (signed __int64)&v6->m_mesh.m_vertices;
        }
        if ( v201 )
        {
          v195 = v201->m_free;
          v201->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v195->m_data;
          v195->m_pool = v201;
          ++v201->m_used;
          *(_DWORD *)&v195->m_data[44] = 0;
          *(_DWORD *)&v195->m_data[52] = -1;
          *(_QWORD *)&v195->m_data[8] = 0i64;
          *(_QWORD *)v195->m_data = *(_QWORD *)(v202 + 8);
          v203 = *(_QWORD *)(v202 + 8);
          if ( v203 )
            *(_QWORD *)(v203 + 8) = v195;
          ++*(_DWORD *)(v202 + 16);
          *(_QWORD *)(v202 + 8) = v195;
        }
        else
        {
          v195 = 0i64;
        }
        v204 = *(hkgpConvexHullImpl::Vertex **)v20;
        *(_OWORD *)&v195->m_data[16] = *(_OWORD *)(*(_QWORD *)v20 + 16i64);
        *(_DWORD *)&v195->m_data[32] = v204->m_x[0];
        *(_DWORD *)&v195->m_data[36] = v204->m_x[1];
        *(_DWORD *)&v195->m_data[40] = v204->m_x[2];
        *(float *)&v195->m_data[44] = v204->m_scratch;
        *(_DWORD *)&v195->m_data[48] = v204->m_refs;
        v200 = v204->m_index;
LABEL_222:
        *(_DWORD *)&v195->m_data[48] = 0;
        *(_DWORD *)&v195->m_data[52] = v200;
        goto LABEL_223;
      }
      hkgpConvexHullImpl::computeProjectionPlane(v6, pointsa, v15, v18);
      v15 = numPointsa;
    }
    v205 = 1;
    goto LABEL_29;
  }
LABEL_223:
  if ( v6->m_dimensions != -1 )
  {
    if ( v6->m_config.m_buildIndices.m_bool )
      hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v6);
    if ( v6->m_config.m_buildMassProperties.m_bool )
      hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v6, (hkResult *)&numPointsa);
  }
  return (unsigned int)v6->m_dimensions;
}sitionAsTransform>(v6, (hkResult *)&numPointsa);
  }
  return (unsigned int)v6->m_dimensions;
}

