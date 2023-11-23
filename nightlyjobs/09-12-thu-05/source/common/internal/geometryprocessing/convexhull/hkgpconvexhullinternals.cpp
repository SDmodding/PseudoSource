// File Line: 12
// RVA: 0xCC24F0
__int64 __fastcall hkgpConvexHullImpl::build(
        hkgpConvexHullImpl *this,
        hkVector4f *points,
        signed int numPoints,
        bool forcePlanar,
        hkgpConvexHullImpl *domain)
{
  hkgpConvexHullImpl *v6; // rdi
  hkVector4f *v7; // r9
  __int64 v8; // rcx
  __int64 v9; // rdx
  hkRelocationInfo::Import m_quad; // xmm0
  int v11; // eax
  unsigned int v12; // edi
  int v14; // r10d
  hkgpConvexHullImpl *v15; // rax
  int v16; // eax
  hkVector4f *p_m_projectionPlane; // r9
  bool v18; // zf
  __int64 p_m_pendings; // rsi
  __int64 v20; // rbx
  int m_capacityAndFlags; // eax
  int v22; // eax
  int v23; // eax
  int v24; // r9d
  int v25; // eax
  __int64 v26; // rdx
  int *p_m_index; // rcx
  int v28; // edx
  hkVector4f *v29; // r9
  __int64 v30; // r8
  hkgpConvexHullImpl::Vertex *v31; // rcx
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128i v39; // xmm1
  int v40; // eax
  int m_size; // r8d
  int m_dimensions; // ecx
  int v43; // ecx
  int v44; // ecx
  int v45; // edi
  __m128 v46; // xmm3
  __int64 v47; // rcx
  __int64 v48; // r9
  __int64 v49; // r8
  hkgpConvexHullImpl::Vertex *v50; // rdx
  int v51; // ecx
  __int64 v52; // r9
  __int64 v53; // r8
  hkgpConvexHullImpl::Vertex *v54; // rdx
  int v55; // ecx
  int v56; // r8d
  int v57; // r10d
  int v58; // r9d
  __int64 v59; // r8
  __int64 v60; // r9
  _DWORD *v61; // rcx
  __int64 v62; // r8
  __int64 v63; // r11
  int v64; // eax
  int v65; // esi
  int *v66; // r10
  int v67; // ecx
  hkgpConvexHullImpl::Vertex *v68; // rcx
  __int64 v69; // rdx
  char *v70; // rdx
  __int128 v71; // xmm0
  __int64 v72; // rcx
  hkRelocationInfo::Import *v73; // rax
  __int64 v74; // r11
  int v75; // eax
  int *v76; // r10
  hkgpConvexHullImpl::Vertex *v77; // rcx
  __int64 v78; // rdx
  __int128 v79; // xmm0
  char *v80; // rdx
  int v81; // eax
  __int64 v82; // rcx
  int v83; // edi
  int v84; // eax
  int v85; // eax
  int v86; // r9d
  int v87; // eax
  __int64 v88; // rdx
  _DWORD *v89; // rcx
  __m128 v90; // xmm3
  __int64 v91; // rcx
  __int64 v92; // r9
  __int64 v93; // r8
  hkgpConvexHullImpl::Vertex *v94; // rdx
  int v95; // ecx
  __int64 v96; // r9
  __int64 v97; // r8
  hkgpConvexHullImpl::Vertex *v98; // rdx
  int v99; // ecx
  int v100; // r8d
  __m128 v101; // xmm1
  __m128 v102; // xmm4
  __m128 v103; // xmm1
  __m128 v104; // xmm0
  __m128 v105; // xmm2
  __int64 v106; // rcx
  __m128 *v107; // rax
  __m128 v108; // xmm4
  __m128 v109; // xmm5
  hkgpConvexHullImpl::Vertex *v110; // r9
  __int64 v111; // rax
  __int64 v112; // rdx
  __int64 v113; // rcx
  __m128 v114; // xmm3
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm6
  __m128 v118; // xmm6
  __m128 v119; // xmm1
  __m128 v120; // xmm5
  int v121; // edi
  int v122; // r9d
  int v123; // r9d
  hkRelocationInfo::Import *m_data; // rdx
  hkgpConvexHullImpl::Vertex *v125; // r8
  __int64 v126; // r10
  __int64 v127; // r11
  hkRelocationInfo::Import *v128; // rcx
  int *m_x; // rdx
  unsigned __int64 v130; // r9
  hkRelocationInfo::Import v131; // xmm0
  signed __int64 v132; // r8
  __int64 v133; // rcx
  __int64 v134; // rdx
  __int128 v135; // xmm0
  __int64 v136; // r10
  __int64 v137; // r8
  hkRelocationInfo::Import *v138; // r10
  int v139; // eax
  __int64 v140; // r11
  hkRelocationInfo::Import *v141; // rcx
  __int64 v142; // rdx
  unsigned __int64 v143; // r10
  __int64 v144; // r8
  __int64 v145; // rcx
  __int64 v146; // r9
  int v147; // r9d
  __int64 v148; // r8
  hkgpConvexHullImpl::Vertex *v149; // rcx
  int v150; // edi
  hkRelocationInfo::Import *v151; // rdx
  __int64 p_m_vertices; // r8
  __int64 v153; // rdi
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *NewPool; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *m_free; // rdx
  __int64 v156; // rax
  hkgpConvexHullImpl::Vertex *v157; // rcx
  int m_index; // eax
  __m128 v159; // xmm3
  __int64 v160; // rcx
  __int64 v161; // r8
  hkgpConvexHullImpl::Vertex *v162; // rdx
  int v163; // ecx
  __int64 v164; // r8
  hkgpConvexHullImpl::Vertex *v165; // rdx
  int v166; // ecx
  __int64 v167; // rdx
  __int64 v168; // r9
  __int64 v169; // r8
  __m128 v170; // xmm4
  hkgpConvexHullImpl::Vertex *v171; // rax
  __int64 v172; // r11
  __int64 v173; // rdi
  __int64 v174; // rcx
  __int64 v175; // r10
  __m128 v176; // xmm1
  __m128 v177; // xmm2
  float v178; // xmm3_4
  __m128 v179; // xmm2
  __int64 v180; // r9
  __int64 v181; // r8
  int v182; // eax
  int v183; // ecx
  int v184; // xmm1_4
  __int128 v185; // xmm6
  __int128 v186; // xmm8
  int v187; // xmm7_4
  int v188; // xmm9_4
  int v189; // xmm0_4
  unsigned int v190; // xmm1_4
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *m_firstPool; // rax
  hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> > *v192; // r8
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v193; // rsi
  hkgpConvexHullImpl::Vertex *m_used; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v195; // rax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item *v196; // rdx
  hkgpConvexHullImpl::Vertex *v197; // rax
  unsigned int v198; // eax
  int v199; // eax
  unsigned int v200; // eax
  int v201; // eax
  hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool *v202; // rax
  hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpAbstractMeshDefinitions::List<hkgpConvexHullImpl::Vertex,hkgpConvexHull::Vertex,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> >::Item,hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> > *v203; // r8
  hkgpConvexHullImpl::Vertex *v204; // rax
  hkgpConvexHullImpl::Vertex *v205; // rcx
  char v206; // [rsp+30h] [rbp-D0h]
  int v207; // [rsp+34h] [rbp-CCh]
  int v208; // [rsp+34h] [rbp-CCh]
  int v209; // [rsp+34h] [rbp-CCh]
  int v210; // [rsp+34h] [rbp-CCh]
  char v211; // [rsp+38h] [rbp-C8h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+40h] [rbp-C0h] BYREF
  int v213; // [rsp+50h] [rbp-B0h]
  hkRelocationInfo::Import *v214; // [rsp+58h] [rbp-A8h]
  hkResult result; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v216; // [rsp+68h] [rbp-98h]
  __int64 v217; // [rsp+70h] [rbp-90h]
  hkResult v218; // [rsp+78h] [rbp-88h] BYREF
  hkResult v219; // [rsp+7Ch] [rbp-84h] BYREF
  __int64 v220; // [rsp+80h] [rbp-80h]
  hkArray<hkgpConvexHullImpl::Vertex,hkContainerHeapAllocator> *v221; // [rsp+88h] [rbp-78h]
  unsigned __int64 v222; // [rsp+B0h] [rbp-50h]
  unsigned int v223; // [rsp+B8h] [rbp-48h]
  int v224; // [rsp+C0h] [rbp-40h]
  __int64 v225; // [rsp+F0h] [rbp-10h]
  int v226; // [rsp+F8h] [rbp-8h]
  int numPointsa; // [rsp+1A0h] [rbp+A0h] BYREF
  bool v230; // [rsp+1A8h] [rbp+A8h]

  v230 = forcePlanar;
  numPointsa = numPoints;
  v6 = this;
  v7 = points;
  if ( numPoints && ((unsigned __int8)points & 0xF) != 0 )
  {
    array.m_capacityAndFlags = 0x80000000;
    array.m_data = 0i64;
    array.m_size = 0;
    if ( numPoints > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, numPoints, 16);
      numPoints = numPointsa;
      v7 = points;
    }
    array.m_size = numPoints;
    if ( numPoints > 0 )
    {
      v8 = 0i64;
      v9 = (unsigned int)numPoints;
      do
      {
        m_quad = (hkRelocationInfo::Import)v7->m_quad;
        ++v8;
        ++v7;
        array.m_data[v8 - 1] = m_quad;
        --v9;
      }
      while ( v9 );
    }
    v11 = hkgpConvexHullImpl::build(v6, (hkVector4f *)array.m_data, numPoints, forcePlanar, domain);
    array.m_size = 0;
    v12 = v11;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        16 * array.m_capacityAndFlags);
    return v12;
  }
  hkgpConvexHullImpl::reset(this, forcePlanar);
  v14 = numPointsa;
  if ( numPointsa > 0 )
  {
    v15 = domain;
    if ( domain )
    {
      v6->m_origin = domain->m_origin;
      v6->m_scale = v15->m_scale;
      v6->m_scaleInv = v15->m_scaleInv;
    }
    else if ( v6->m_config.m_internalInputs.m_bool )
    {
      v6->m_origin = 0i64;
      v6->m_scale = (hkVector4f)query.m_quad;
      v6->m_scale = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)query.m_quad, 4), 4);
      v6->m_scaleInv = (hkVector4f)query.m_quad;
      v6->m_scaleInv = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)query.m_quad, 4), 4);
    }
    else
    {
      hkgpConvexHullImpl::rebuildDomainParameters(v6, points, numPointsa);
      v14 = numPointsa;
    }
    v16 = 3;
    v206 = 0;
    if ( v14 - 1 < 3 )
      v16 = v14 - 1;
    v6->m_projectionAxis = 0i64;
    v6->m_dimensions = v16;
    if ( forcePlanar )
    {
      v6->m_dimensions = 2;
    }
    else
    {
      p_m_projectionPlane = &v6->m_projectionPlane;
      v6->m_projectionPlane = 0i64;
      if ( v14 > 1 )
        v6->m_projectionAxis.m_quad = _mm_sub_ps(points[1].m_quad, points->m_quad);
      if ( v14 <= 2
        || (v18 = v6->m_config.m_alwaysComputeProjectionPlane.m_bool == 0,
            *p_m_projectionPlane = (hkVector4f)transform.m_quad,
            p_m_projectionPlane->m_quad = _mm_shuffle_ps(
                                            transform.m_quad,
                                            _mm_unpackhi_ps(
                                              transform.m_quad,
                                              _mm_sub_ps(
                                                (__m128)0i64,
                                                _mm_shuffle_ps(points->m_quad, points->m_quad, 0))),
                                            196),
            v18) )
      {
LABEL_27:
        p_m_pendings = (__int64)&v6->m_pendings;
        v20 = 0i64;
        v6->m_pendings.m_size = 0;
        m_capacityAndFlags = v6->m_pendings.m_capacityAndFlags;
        v221 = &v6->m_pendings;
        v22 = m_capacityAndFlags & 0x3FFFFFFF;
        if ( v22 < v14 )
        {
          v23 = 2 * v22;
          v24 = v14;
          if ( v14 < v23 )
            v24 = v23;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v6->m_pendings.m_data,
            v24,
            64);
          v14 = numPointsa;
        }
        v25 = v14 - v6->m_pendings.m_size;
        v26 = v25;
        if ( v25 > 0 )
        {
          p_m_index = &v6->m_pendings.m_data[(__int64)v6->m_pendings.m_size].m_index;
          do
          {
            if ( p_m_index != (int *)52 )
            {
              *(p_m_index - 2) = 0;
              *p_m_index = -1;
            }
            p_m_index += 16;
            --v26;
          }
          while ( v26 );
        }
        v6->m_pendings.m_size = v14;
        v28 = 0;
        if ( v14 > 0 )
        {
          v29 = points;
          v30 = 0i64;
          do
          {
            v31 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
            v32 = _mm_mul_ps(_mm_sub_ps(v29->m_quad, v6->m_origin.m_quad), v6->m_scale.m_quad);
            v33 = _mm_cmplt_ps(v32, (__m128)_xmm);
            v34 = _mm_max_ps(
                    (__m128)_xmm_c6000000c6000000c6000000c6000000,
                    _mm_or_ps(_mm_andnot_ps(v33, (__m128)_xmm), _mm_and_ps(v33, v32)));
            v35 = _mm_sub_ps(v34, (__m128)xmmword_141A711B0);
            v36 = _mm_add_ps(v34, (__m128)xmmword_141A711B0);
            v37 = _mm_cmplt_ps(v34, (__m128)0i64);
            v31[v30].m_source = (hkVector4f)v29->m_quad;
            v38 = _mm_or_ps(_mm_andnot_ps(v37, v36), _mm_and_ps(v35, v37));
            v39 = _mm_xor_si128(
                    (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v38),
                    _mm_cvttps_epi32(v38));
            v222 = v39.m128i_i64[0];
            v31[v30].m_x[0] = v39.m128i_i32[0];
            v31[v30].m_x[1] = HIDWORD(v222);
            v223 = _mm_shuffle_epi32(v39, 170).m128i_u32[0];
            v31[v30].m_x[2] = v223;
            v40 = v224;
            v31[v30].m_index = -1;
            v31[v30].m_scratch = 0.0;
            v31[v30].m_refs = v40;
            if ( v6->m_config.m_setSourceIndices.m_bool )
              *(_DWORD *)(*(_QWORD *)p_m_pendings + v30 * 64 + 28) = v28 | 0x3F000000;
            ++v28;
            ++v29;
            ++v30;
          }
          while ( v28 < v14 );
        }
        if ( !v230 )
        {
          if ( v6->m_config.m_sortInputs.m_bool )
          {
            m_size = v6->m_pendings.m_size;
            if ( m_size > 1 )
            {
              hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::Vertex,hkAlgorithm::less<hkgpConvexHullImpl::Vertex>>(
                *(hkgpConvexHullImpl::Vertex **)p_m_pendings,
                0,
                m_size - 1,
                0);
              v14 = numPointsa;
            }
          }
        }
        v220 = v14;
        while ( 1 )
        {
          m_dimensions = v6->m_dimensions;
          v211 = 0;
          if ( !m_dimensions )
            break;
          v43 = m_dimensions - 1;
          if ( v43 )
          {
            v44 = v43 - 1;
            if ( v44 )
            {
              if ( v44 != 1 || hkgpConvexHullImpl::flushPending(v6) )
                goto LABEL_221;
              if ( !v6->m_config.m_allowLowerDimensions.m_bool )
              {
                v6->m_dimensions = -1;
                goto LABEL_221;
              }
              v14 = numPointsa;
              v6->m_dimensions = 2;
            }
            else
            {
              if ( !v206 )
              {
                hkgpConvexHullImpl::computeProjectionPlane(v6, points, v14, &v6->m_projectionPlane);
                v206 = 1;
              }
              array.m_data = 0i64;
              array.m_size = 0;
              array.m_capacityAndFlags = 0x80000000;
              v45 = 0;
              v46 = (__m128)_mm_srli_epi32(
                              _mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_projectionPlane), 1u),
                              1u);
              v47 = _mm_movemask_ps(
                      _mm_and_ps(
                        _mm_cmple_ps(
                          _mm_max_ps(
                            _mm_shuffle_ps(v46, v46, 170),
                            _mm_max_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0))),
                          v46),
                        *(__m128 *)&hkVector4fComparison_maskToComparison_326[28]));
              if ( hkVector4Comparison_maskToLastIndex[v47] )
              {
                if ( hkVector4Comparison_maskToLastIndex[v47] == 1 )
                {
                  v48 = this->m_pendings.m_size;
                  if ( v48 > 0 )
                  {
                    v49 = 0i64;
                    do
                    {
                      v50 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                      v51 = *(_DWORD *)(*(_QWORD *)p_m_pendings + ++v49 * 64 - 28);
                      v50[v49 - 1].m_x[1] = *(_DWORD *)(*(_QWORD *)p_m_pendings + v49 * 64 - 24);
                      v50[v49 - 1].m_x[2] = v51;
                      --v48;
                    }
                    while ( v48 );
                  }
                }
              }
              else
              {
                v52 = this->m_pendings.m_size;
                if ( v52 > 0 )
                {
                  v53 = 0i64;
                  do
                  {
                    v54 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                    v55 = *(_DWORD *)(*(_QWORD *)p_m_pendings + ++v53 * 64 - 32);
                    v54[v53 - 1].m_x[0] = *(_DWORD *)(*(_QWORD *)p_m_pendings + v53 * 64 - 24);
                    v54[v53 - 1].m_x[2] = v55;
                    --v52;
                  }
                  while ( v52 );
                }
              }
              v56 = this->m_pendings.m_size;
              if ( v56 > 1 )
                hkAlgorithm::quickSortRecursive<hkgpConvexHullImpl::Vertex,hkAlgorithm::less<hkgpConvexHullImpl::Vertex>>(
                  *(hkgpConvexHullImpl::Vertex **)p_m_pendings,
                  0,
                  v56 - 1,
                  0);
              v57 = 2 * numPointsa;
              v207 = 2 * numPointsa;
              if ( (array.m_capacityAndFlags & 0x3FFFFFFF) >= 2 * numPointsa )
              {
                v219.m_enum = HK_SUCCESS;
              }
              else
              {
                v58 = 2 * numPointsa;
                if ( v57 < 2 * (array.m_capacityAndFlags & 0x3FFFFFFF) )
                  v58 = 2 * (array.m_capacityAndFlags & 0x3FFFFFFF);
                hkArrayUtil::_reserve(&v219, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v58, 64);
                v57 = v207;
              }
              v59 = v57 - array.m_size;
              v60 = (__int64)&array.m_data[4 * (__int64)array.m_size];
              if ( v57 - array.m_size > 0 )
              {
                v61 = (_DWORD *)(v60 + 52);
                do
                {
                  if ( v61 != (_DWORD *)52 )
                  {
                    *(v61 - 2) = 0;
                    *v61 = -1;
                  }
                  v61 += 16;
                  --v59;
                }
                while ( v59 );
              }
              v62 = v220;
              array.m_size = v57;
              v216 = 0i64;
              if ( v220 > 0 )
              {
                v63 = 0i64;
                v217 = 0i64;
                do
                {
                  if ( v20 >= 2 )
                  {
                    v64 = *(_DWORD *)(v63 + *(_QWORD *)p_m_pendings + 36);
                    v65 = *(_DWORD *)(v63 + *(_QWORD *)p_m_pendings + 32);
                    v66 = &array.m_data[4 * v20 - 6].m_fromOffset + 1;
                    do
                    {
                      v67 = (v65 - *(v66 - 1)) * (v66[16] - *v66);
                      v60 = (unsigned int)((v64 - *v66) * (v66[15] - *(v66 - 1)) - v67);
                      if ( (v64 - *v66) * (v66[15] - *(v66 - 1)) - v67 > 0 )
                        break;
                      --v20;
                      --v45;
                      v66 -= 16;
                    }
                    while ( v20 >= 2 );
                    v63 = v217;
                    p_m_pendings = (__int64)v221;
                    v62 = v220;
                  }
                  v68 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                  v63 += 64i64;
                  v69 = v20 << 6;
                  ++v45;
                  ++v20;
                  v70 = (char *)array.m_data + v69;
                  v71 = *(_OWORD *)(v63 + *(_QWORD *)p_m_pendings - 48);
                  v217 = v63;
                  *((_OWORD *)v70 + 1) = v71;
                  *((_DWORD *)v70 + 8) = *(_DWORD *)((char *)v68 + v63 - 32);
                  *((_DWORD *)v70 + 9) = *(_DWORD *)((char *)v68 + v63 - 28);
                  *((_DWORD *)v70 + 10) = *(_DWORD *)((char *)v68 + v63 - 24);
                  *((_DWORD *)v70 + 11) = *(_DWORD *)((char *)v68 + v63 - 20);
                  *((_DWORD *)v70 + 12) = *(_DWORD *)((char *)v68 + v63 - 16);
                  *((_DWORD *)v70 + 13) = *(_DWORD *)((char *)v68 + v63 - 12);
                  ++v216;
                }
                while ( v216 < v62 );
              }
              v72 = v62 - 2;
              v73 = (hkRelocationInfo::Import *)(v45 + 1);
              v217 = v62 - 2;
              v214 = v73;
              if ( v62 - 2 >= 0 )
              {
                v74 = v72 << 6;
                v216 = v72 << 6;
                do
                {
                  if ( v20 >= (__int64)v73 )
                  {
                    v75 = *(_DWORD *)(v74 + *(_QWORD *)p_m_pendings + 36);
                    v213 = *(_DWORD *)(v74 + *(_QWORD *)p_m_pendings + 32);
                    v76 = &array.m_data[4 * v20 - 6].m_fromOffset + 1;
                    do
                    {
                      v60 = (unsigned int)((v213 - *(v76 - 1)) * (v76[16] - *v76));
                      if ( (v75 - *v76) * (v76[15] - *(v76 - 1)) - (int)v60 > 0 )
                        break;
                      --v20;
                      --v45;
                      v76 -= 16;
                    }
                    while ( v20 >= (__int64)v214 );
                    v74 = v216;
                    p_m_pendings = (__int64)v221;
                  }
                  v77 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                  v74 -= 64i64;
                  v78 = v20 << 6;
                  ++v45;
                  ++v20;
                  v79 = *(_OWORD *)(v74 + *(_QWORD *)p_m_pendings + 80);
                  v80 = (char *)array.m_data + v78;
                  v216 = v74;
                  *((_OWORD *)v80 + 1) = v79;
                  *((_DWORD *)v80 + 8) = *(int *)((char *)v77[1].m_x + v74);
                  *((_DWORD *)v80 + 9) = *(int *)((char *)&v77[1].m_x[1] + v74);
                  *((_DWORD *)v80 + 10) = *(int *)((char *)&v77[1].m_x[2] + v74);
                  *((_DWORD *)v80 + 11) = *(int *)((char *)&v77[1].m_x[3] + v74);
                  *((_DWORD *)v80 + 12) = *(int *)((char *)&v77[1].m_refs + v74);
                  v81 = *(int *)((char *)&v77[1].m_index + v74);
                  v82 = v217 - 1;
                  *((_DWORD *)v80 + 13) = v81;
                  v73 = v214;
                  v217 = v82;
                }
                while ( v82 >= 0 );
              }
              if ( v45 <= 3 )
              {
                v6 = this;
                v20 = 0i64;
                v159 = (__m128)_mm_srli_epi32(
                                 _mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_projectionPlane), 1u),
                                 1u);
                v160 = _mm_movemask_ps(
                         _mm_and_ps(
                           _mm_cmple_ps(
                             _mm_max_ps(
                               _mm_shuffle_ps(v159, v159, 170),
                               _mm_max_ps(_mm_shuffle_ps(v159, v159, 85), _mm_shuffle_ps(v159, v159, 0))),
                             v159),
                           *(__m128 *)&hkVector4fComparison_maskToComparison_326[28]));
                if ( hkVector4Comparison_maskToLastIndex[v160] )
                {
                  if ( hkVector4Comparison_maskToLastIndex[v160] == 1 )
                  {
                    v60 = this->m_pendings.m_size;
                    if ( v60 > 0 )
                    {
                      v161 = 0i64;
                      do
                      {
                        v162 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                        v163 = *(_DWORD *)(*(_QWORD *)p_m_pendings + ++v161 * 64 - 28);
                        v162[v161 - 1].m_x[1] = *(_DWORD *)(*(_QWORD *)p_m_pendings + v161 * 64 - 24);
                        v162[v161 - 1].m_x[2] = v163;
                        --v60;
                      }
                      while ( v60 );
                    }
                  }
                }
                else
                {
                  v60 = this->m_pendings.m_size;
                  if ( v60 > 0 )
                  {
                    v164 = 0i64;
                    do
                    {
                      v165 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                      v166 = *(_DWORD *)(*(_QWORD *)p_m_pendings + ++v164 * 64 - 32);
                      v165[v164 - 1].m_x[0] = *(_DWORD *)(*(_QWORD *)p_m_pendings + v164 * 64 - 24);
                      v165[v164 - 1].m_x[2] = v166;
                      --v60;
                    }
                    while ( v60 );
                  }
                }
                this->m_dimensions = 1;
                v211 = 1;
              }
              else
              {
                hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
                  (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_pendings,
                  &array);
                v83 = v45 - 1;
                v84 = *(_DWORD *)(p_m_pendings + 12) & 0x3FFFFFFF;
                if ( v84 >= v83 )
                {
                  v20 = 0i64;
                  v218.m_enum = HK_SUCCESS;
                }
                else
                {
                  v85 = 2 * v84;
                  v86 = v83;
                  if ( v83 < v85 )
                    v86 = v85;
                  hkArrayUtil::_reserve(&v218, &hkContainerHeapAllocator::s_alloc, (const void **)p_m_pendings, v86, 64);
                  v20 = 0i64;
                }
                v87 = v83 - *(_DWORD *)(p_m_pendings + 8);
                v88 = v87;
                if ( v87 > 0 )
                {
                  v89 = (_DWORD *)(*(_QWORD *)p_m_pendings + ((__int64)*(int *)(p_m_pendings + 8) << 6) + 52);
                  do
                  {
                    if ( v89 != (_DWORD *)52 )
                    {
                      *(v89 - 2) = 0;
                      *v89 = -1;
                    }
                    v89 += 16;
                    --v88;
                  }
                  while ( v88 );
                }
                *(_DWORD *)(p_m_pendings + 8) = v83;
                v6 = this;
                v90 = (__m128)_mm_srli_epi32(
                                _mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_projectionPlane), 1u),
                                1u);
                v91 = _mm_movemask_ps(
                        _mm_and_ps(
                          _mm_cmple_ps(
                            _mm_max_ps(
                              _mm_shuffle_ps(v90, v90, 170),
                              _mm_max_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0))),
                            v90),
                          *(__m128 *)&hkVector4fComparison_maskToComparison_326[28]));
                if ( hkVector4Comparison_maskToLastIndex[v91] )
                {
                  if ( hkVector4Comparison_maskToLastIndex[v91] == 1 )
                  {
                    v92 = this->m_pendings.m_size;
                    if ( v92 > 0 )
                    {
                      v93 = 0i64;
                      do
                      {
                        v94 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                        v95 = *(_DWORD *)(*(_QWORD *)p_m_pendings + ++v93 * 64 - 28);
                        v94[v93 - 1].m_x[1] = *(_DWORD *)(*(_QWORD *)p_m_pendings + v93 * 64 - 24);
                        v94[v93 - 1].m_x[2] = v95;
                        --v92;
                      }
                      while ( v92 );
                    }
                  }
                }
                else
                {
                  v96 = this->m_pendings.m_size;
                  if ( v96 > 0 )
                  {
                    v97 = 0i64;
                    do
                    {
                      v98 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                      v99 = *(_DWORD *)(*(_QWORD *)p_m_pendings + ++v97 * 64 - 32);
                      v98[v97 - 1].m_x[0] = *(_DWORD *)(*(_QWORD *)p_m_pendings + v97 * 64 - 24);
                      v98[v97 - 1].m_x[2] = v99;
                      --v96;
                    }
                    while ( v96 );
                  }
                }
                v100 = this->m_pendings.m_size;
                v101 = 0i64;
                v102 = 0i64;
                v101.m128_f32[0] = (float)v100;
                v103 = _mm_shuffle_ps(v101, v101, 0);
                v104 = _mm_rcp_ps(v103);
                v105 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v103, v104)), v104);
                if ( v100 > 0 )
                {
                  v106 = (unsigned int)v100;
                  v107 = (__m128 *)(*(_QWORD *)p_m_pendings + 16i64);
                  do
                  {
                    v102 = _mm_add_ps(v102, *v107);
                    v107 += 4;
                    --v106;
                  }
                  while ( v106 );
                }
                v108 = _mm_mul_ps(v102, v105);
                v109 = 0i64;
                if ( v100 > 0 )
                {
                  v110 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                  v111 = 0i64;
                  v112 = (__int64)(v100 - 1) << 6;
                  v113 = (unsigned int)this->m_pendings.m_size;
                  do
                  {
                    v114 = _mm_mul_ps(v109, v109);
                    v115 = _mm_sub_ps(*(__m128 *)((char *)&v110->m_source.m_quad + v112), v108);
                    v116 = _mm_sub_ps(v110[v111].m_source.m_quad, v108);
                    v117 = _mm_sub_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v116, v116, 201), v115),
                             _mm_mul_ps(_mm_shuffle_ps(v115, v115, 201), v116));
                    v118 = _mm_shuffle_ps(v117, v117, 201);
                    v119 = _mm_mul_ps(v118, v118);
                    if ( (float)((float)(_mm_shuffle_ps(v119, v119, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v119, v119, 0).m128_f32[0])
                               + _mm_shuffle_ps(v119, v119, 170).m128_f32[0]) > (float)((float)(_mm_shuffle_ps(
                                                                                                  v114,
                                                                                                  v114,
                                                                                                  85).m128_f32[0]
                                                                                              + _mm_shuffle_ps(
                                                                                                  v114,
                                                                                                  v114,
                                                                                                  0).m128_f32[0])
                                                                                      + _mm_shuffle_ps(v114, v114, 170).m128_f32[0]) )
                      v109 = v118;
                    v112 = v111 * 64;
                    ++v111;
                    --v113;
                  }
                  while ( v113 );
                }
                v120 = _mm_mul_ps(v109, this->m_projectionPlane.m_quad);
                if ( _mm_movemask_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v120, v120, 85), _mm_shuffle_ps(v120, v120, 0)),
                         _mm_shuffle_ps(v120, v120, 170))) )
                {
                  v121 = *(_DWORD *)(p_m_pendings + 8);
                  v122 = v121;
                  if ( v121 > array.m_size )
                    v122 = array.m_size;
                  v208 = v122;
                  if ( (array.m_capacityAndFlags & 0x3FFFFFFF) >= v121 )
                  {
                    result.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v123 = *(_DWORD *)(p_m_pendings + 8);
                    if ( v121 < 2 * (array.m_capacityAndFlags & 0x3FFFFFFF) )
                      v123 = 2 * (array.m_capacityAndFlags & 0x3FFFFFFF);
                    hkArrayUtil::_reserve(
                      &result,
                      &hkContainerHeapAllocator::s_alloc,
                      (const void **)&array.m_data,
                      v123,
                      64);
                    v122 = v208;
                  }
                  m_data = array.m_data;
                  v125 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                  v126 = v122;
                  v127 = 0i64;
                  v214 = array.m_data;
                  if ( v122 >= 4i64 )
                  {
                    v128 = array.m_data + 6;
                    m_x = v125[1].m_x;
                    v130 = ((unsigned __int64)(v122 - 4i64) >> 2) + 1;
                    v127 = 4 * v130;
                    do
                    {
                      v131 = (hkRelocationInfo::Import)*((_OWORD *)m_x - 5);
                      v128 += 16;
                      m_x += 64;
                      v128[-21] = v131;
                      v128[-20].m_fromOffset = *(m_x - 80);
                      *(&v128[-20].m_fromOffset + 1) = *(m_x - 79);
                      LODWORD(v128[-20].m_identifier) = *(m_x - 78);
                      HIDWORD(v128[-20].m_identifier) = *(m_x - 77);
                      v128[-19].m_fromOffset = *(m_x - 76);
                      *(&v128[-19].m_fromOffset + 1) = *(m_x - 75);
                      v128[-17] = *((hkRelocationInfo::Import *)m_x - 17);
                      v128[-16].m_fromOffset = *(m_x - 64);
                      *(&v128[-16].m_fromOffset + 1) = *(m_x - 63);
                      LODWORD(v128[-16].m_identifier) = *(m_x - 62);
                      HIDWORD(v128[-16].m_identifier) = *(m_x - 61);
                      v128[-15].m_fromOffset = *(m_x - 60);
                      *(&v128[-15].m_fromOffset + 1) = *(m_x - 59);
                      v128[-13] = *((hkRelocationInfo::Import *)m_x - 13);
                      v128[-12].m_fromOffset = *(m_x - 48);
                      *(&v128[-12].m_fromOffset + 1) = *(m_x - 47);
                      LODWORD(v128[-12].m_identifier) = *(m_x - 46);
                      HIDWORD(v128[-12].m_identifier) = *(m_x - 45);
                      v128[-11].m_fromOffset = *(m_x - 44);
                      *(&v128[-11].m_fromOffset + 1) = *(m_x - 43);
                      v128[-9] = *((hkRelocationInfo::Import *)m_x - 9);
                      v128[-8].m_fromOffset = *(m_x - 32);
                      *(&v128[-8].m_fromOffset + 1) = *(m_x - 31);
                      LODWORD(v128[-8].m_identifier) = *(m_x - 30);
                      HIDWORD(v128[-8].m_identifier) = *(m_x - 29);
                      v128[-7].m_fromOffset = *(m_x - 28);
                      *(&v128[-7].m_fromOffset + 1) = *(m_x - 27);
                      --v130;
                    }
                    while ( v130 );
                    v122 = v208;
                    m_data = v214;
                  }
                  if ( v127 < v126 )
                  {
                    v132 = (char *)v125 - (char *)m_data;
                    v133 = (__int64)&m_data[4 * v127 + 1];
                    v134 = v126 - v127;
                    do
                    {
                      v135 = *(_OWORD *)(v133 + v132);
                      v133 += 64i64;
                      *(_OWORD *)(v133 - 64) = v135;
                      *(_DWORD *)(v133 - 48) = *(_DWORD *)(v133 + v132 - 48);
                      *(_DWORD *)(v133 - 44) = *(_DWORD *)(v133 + v132 - 44);
                      *(_DWORD *)(v133 - 40) = *(_DWORD *)(v133 + v132 - 40);
                      *(_DWORD *)(v133 - 36) = *(_DWORD *)(v133 + v132 - 36);
                      *(_DWORD *)(v133 - 32) = *(_DWORD *)(v133 + v132 - 32);
                      *(_DWORD *)(v133 - 28) = *(_DWORD *)(v133 + v132 - 28);
                      --v134;
                    }
                    while ( v134 );
                  }
                  v136 = v126 << 6;
                  v137 = v136 + *(_QWORD *)p_m_pendings;
                  v138 = (hkRelocationInfo::Import *)((char *)array.m_data + v136);
                  v139 = v121 - v122;
                  v214 = v138;
                  v140 = 0i64;
                  if ( v121 - v122 >= 4i64 )
                  {
                    v141 = v138 + 5;
                    v142 = v137 - (_QWORD)v138;
                    v143 = ((unsigned __int64)(v139 - 4i64) >> 2) + 1;
                    v140 = 4 * v143;
                    do
                    {
                      if ( v141 != (hkRelocationInfo::Import *)80 )
                      {
                        v141[-4] = *(hkRelocationInfo::Import *)((char *)v141 + v142 - 64);
                        v141[-3].m_fromOffset = *(int *)((char *)&v141[-3].m_fromOffset + v142);
                        *(&v141[-3].m_fromOffset + 1) = *(_DWORD *)((char *)&v141[-2] + v142 - 12);
                        LODWORD(v141[-3].m_identifier) = *(_DWORD *)((char *)&v141[-2] + v142 - 8);
                        HIDWORD(v141[-3].m_identifier) = *(_DWORD *)((char *)&v141[-2] + v142 - 4);
                        v141[-2].m_fromOffset = *(int *)((char *)&v141[-2].m_fromOffset + v142);
                        *(&v141[-2].m_fromOffset + 1) = *(_DWORD *)((char *)&v141[-1] + v142 - 12);
                      }
                      if ( v141 != (hkRelocationInfo::Import *)16 )
                      {
                        *v141 = *(hkRelocationInfo::Import *)((char *)v141 + v142);
                        v141[1].m_fromOffset = *(int *)((char *)&v141[1].m_fromOffset + v142);
                        *(&v141[1].m_fromOffset + 1) = *(int *)((char *)&v141[1].m_fromOffset + v142 + 4);
                        LODWORD(v141[1].m_identifier) = *(_DWORD *)((char *)&v141[1].m_identifier + v142);
                        HIDWORD(v141[1].m_identifier) = *(_DWORD *)((char *)&v141[1].m_identifier + v142 + 4);
                        v141[2].m_fromOffset = *(int *)((char *)&v141[2].m_fromOffset + v142);
                        *(&v141[2].m_fromOffset + 1) = *(int *)((char *)&v141[2].m_fromOffset + v142 + 4);
                      }
                      if ( v141 != (hkRelocationInfo::Import *)-48i64 )
                      {
                        v141[4] = *(hkRelocationInfo::Import *)((char *)v141 + v142 + 64);
                        v141[5].m_fromOffset = *(int *)((char *)&v141[5].m_fromOffset + v142);
                        *(&v141[5].m_fromOffset + 1) = *(int *)((char *)&v141[5].m_fromOffset + v142 + 4);
                        LODWORD(v141[5].m_identifier) = *(_DWORD *)((char *)&v141[5].m_identifier + v142);
                        HIDWORD(v141[5].m_identifier) = *(_DWORD *)((char *)&v141[5].m_identifier + v142 + 4);
                        v141[6].m_fromOffset = *(int *)((char *)&v141[6].m_fromOffset + v142);
                        *(&v141[6].m_fromOffset + 1) = *(int *)((char *)&v141[6].m_fromOffset + v142 + 4);
                      }
                      if ( v141 != (hkRelocationInfo::Import *)-112i64 )
                      {
                        v141[8] = *(hkRelocationInfo::Import *)((char *)v141 + v142 + 128);
                        v141[9].m_fromOffset = *(int *)((char *)&v141[9].m_fromOffset + v142);
                        *(&v141[9].m_fromOffset + 1) = *(int *)((char *)&v141[9].m_fromOffset + v142 + 4);
                        LODWORD(v141[9].m_identifier) = *(_DWORD *)((char *)&v141[9].m_identifier + v142);
                        HIDWORD(v141[9].m_identifier) = *(_DWORD *)((char *)&v141[9].m_identifier + v142 + 4);
                        v141[10].m_fromOffset = *(int *)((char *)&v141[10].m_fromOffset + v142);
                        *(&v141[10].m_fromOffset + 1) = *(int *)((char *)&v141[10].m_fromOffset + v142 + 4);
                      }
                      v141 += 16;
                      --v143;
                    }
                    while ( v143 );
                    v138 = v214;
                  }
                  if ( v140 < v139 )
                  {
                    v144 = v137 - (_QWORD)v138;
                    v145 = (__int64)&v138[4 * v140 + 1];
                    v146 = v139 - v140;
                    do
                    {
                      if ( v145 != 16 )
                      {
                        *(_OWORD *)v145 = *(_OWORD *)(v144 + v145);
                        *(_DWORD *)(v145 + 16) = *(_DWORD *)(v144 + v145 + 16);
                        *(_DWORD *)(v145 + 20) = *(_DWORD *)(v144 + v145 + 20);
                        *(_DWORD *)(v145 + 24) = *(_DWORD *)(v144 + v145 + 24);
                        *(_DWORD *)(v145 + 28) = *(_DWORD *)(v144 + v145 + 28);
                        *(_DWORD *)(v145 + 32) = *(_DWORD *)(v144 + v145 + 32);
                        *(_DWORD *)(v145 + 36) = *(_DWORD *)(v144 + v145 + 36);
                      }
                      v145 += 64i64;
                      --v146;
                    }
                    while ( v146 );
                  }
                  array.m_size = v121;
                  v147 = 0;
                  if ( v121 > 0 )
                  {
                    v148 = 0i64;
                    do
                    {
                      v149 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                      v150 = v121 - v147++;
                      ++v148;
                      v151 = &array.m_data[4 * (__int64)(v150 - 1)];
                      v149[v148 - 1].m_source = (hkVector4f)v151[1];
                      v149[v148 - 1].m_x[0] = v151[2].m_fromOffset;
                      v149[v148 - 1].m_x[1] = *(&v151[2].m_fromOffset + 1);
                      v149[v148 - 1].m_x[2] = (int)v151[2].m_identifier;
                      v149[v148 - 1].m_scratch = *((float *)&v151[2].m_identifier + 1);
                      v149[v148 - 1].m_refs = v151[3].m_fromOffset;
                      v149[v148 - 1].m_index = *(&v151[3].m_fromOffset + 1);
                      v121 = array.m_size;
                    }
                    while ( v147 < array.m_size );
                  }
                  v6 = this;
                }
                v60 = 0i64;
                v209 = 0;
                if ( v6->m_pendings.m_size > 0 )
                {
                  p_m_vertices = (__int64)&v6->m_mesh.m_vertices;
                  v153 = 0i64;
                  v214 = (hkRelocationInfo::Import *)p_m_vertices;
                  do
                  {
                    NewPool = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Pool **)p_m_vertices;
                    if ( !*(_QWORD *)p_m_vertices || !NewPool->m_free )
                    {
                      NewPool = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool((hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator> *)p_m_vertices);
                      p_m_vertices = (__int64)v214;
                      LODWORD(v60) = v209;
                    }
                    if ( NewPool )
                    {
                      m_free = NewPool->m_free;
                      NewPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)m_free->m_data;
                      m_free->m_pool = NewPool;
                      ++NewPool->m_used;
                      *(_DWORD *)&m_free->m_data[44] = 0;
                      *(_DWORD *)&m_free->m_data[52] = -1;
                      *(_QWORD *)&m_free->m_data[8] = 0i64;
                      *(_QWORD *)m_free->m_data = *(_QWORD *)(p_m_vertices + 8);
                      v156 = *(_QWORD *)(p_m_vertices + 8);
                      if ( v156 )
                        *(_QWORD *)(v156 + 8) = m_free;
                      ++*(_DWORD *)(p_m_vertices + 16);
                      *(_QWORD *)(p_m_vertices + 8) = m_free;
                    }
                    else
                    {
                      m_free = 0i64;
                    }
                    v157 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
                    v60 = (unsigned int)(v60 + 1);
                    ++v153;
                    v209 = v60;
                    *(_OWORD *)&m_free->m_data[16] = *(_OWORD *)(v153 * 64 + *(_QWORD *)p_m_pendings - 48);
                    *(_DWORD *)&m_free->m_data[32] = v157[v153 - 1].m_x[0];
                    *(_DWORD *)&m_free->m_data[36] = v157[v153 - 1].m_x[1];
                    *(_DWORD *)&m_free->m_data[40] = v157[v153 - 1].m_x[2];
                    *(float *)&m_free->m_data[44] = v157[v153 - 1].m_scratch;
                    *(_DWORD *)&m_free->m_data[48] = v157[v153 - 1].m_refs;
                    m_index = v157[v153 - 1].m_index;
                    *(_DWORD *)&m_free->m_data[48] = 0;
                    *(_DWORD *)&m_free->m_data[52] = m_index;
                  }
                  while ( (int)v60 < this->m_pendings.m_size );
                  v6 = this;
                }
                *(_DWORD *)(p_m_pendings + 8) = 0;
              }
              array.m_size = 0;
              if ( array.m_capacityAndFlags >= 0 )
                ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkRelocationInfo::Import *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
                  &hkContainerHeapAllocator::s_alloc,
                  array.m_data,
                  (unsigned int)(array.m_capacityAndFlags << 6),
                  v60);
              array.m_data = 0i64;
              array.m_capacityAndFlags = 0x80000000;
              if ( !v211 )
                goto LABEL_221;
              v14 = numPointsa;
            }
          }
          else
          {
            v167 = 1i64;
            v168 = 0i64;
            v169 = 0i64;
            if ( v14 > 1 )
            {
              v170 = v6->m_projectionAxis.m_quad;
              v171 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
              v172 = 0i64;
              v173 = 0i64;
              v174 = 1i64;
              v175 = (unsigned int)(v14 - 1);
              do
              {
                v176 = _mm_mul_ps(v171[v174].m_source.m_quad, v170);
                v177 = _mm_mul_ps(*(__m128 *)((char *)&v171->m_source.m_quad + v173), v170);
                v178 = (float)(_mm_shuffle_ps(v176, v176, 85).m128_f32[0] + _mm_shuffle_ps(v176, v176, 0).m128_f32[0])
                     + _mm_shuffle_ps(v176, v176, 170).m128_f32[0];
                if ( v178 < (float)((float)(_mm_shuffle_ps(v177, v177, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v177, v177, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v177, v177, 170).m128_f32[0]) )
                {
                  v168 = v167;
                  v173 = v174 * 64;
                }
                v179 = _mm_mul_ps(*(__m128 *)((char *)&v171->m_source.m_quad + v172), v170);
                if ( v178 > (float)((float)(_mm_shuffle_ps(v179, v179, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v179, v179, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v179, v179, 170).m128_f32[0]) )
                {
                  v169 = v167;
                  v172 = v174 * 64;
                }
                ++v167;
                ++v174;
                --v175;
              }
              while ( v175 );
              v6 = this;
              v14 = numPointsa;
            }
            v180 = *(_QWORD *)p_m_pendings + (v168 << 6);
            v181 = *(_QWORD *)p_m_pendings + (v169 << 6);
            v182 = *(_DWORD *)(v181 + 52);
            v183 = *(_DWORD *)(v180 + 52);
            v184 = *(_DWORD *)(v180 + 36);
            v185 = *(_OWORD *)(v180 + 16);
            v186 = *(_OWORD *)(v181 + 16);
            v187 = *(_DWORD *)(v180 + 44);
            v188 = *(_DWORD *)(v181 + 44);
            LODWORD(v225) = *(_DWORD *)(v180 + 32);
            v210 = v182;
            v213 = v183;
            v189 = *(_DWORD *)(v180 + 40);
            HIDWORD(v225) = v184;
            v190 = *(_DWORD *)(v181 + 36);
            v226 = v189;
            v222 = __PAIR64__(v190, *(_DWORD *)(v181 + 32));
            v223 = *(_DWORD *)(v181 + 40);
            if ( v225 != v222 )
            {
              m_firstPool = v6->m_mesh.m_vertices.m_allocator.m_firstPool;
              v192 = &v6->m_mesh.m_vertices;
              if ( !m_firstPool || !m_firstPool->m_free )
              {
                m_firstPool = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_mesh.m_vertices.m_allocator);
                v192 = &v6->m_mesh.m_vertices;
              }
              if ( m_firstPool )
              {
                v193 = m_firstPool->m_free;
                m_firstPool->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v193->m_data;
                v193->m_pool = m_firstPool;
                ++m_firstPool->m_used;
                *(_DWORD *)&v193->m_data[44] = 0;
                *(_DWORD *)&v193->m_data[52] = -1;
                *(_QWORD *)&v193->m_data[8] = 0i64;
                *(_QWORD *)v193->m_data = v192->m_used;
                m_used = v192->m_used;
                if ( m_used )
                  m_used->m_prev = (hkgpConvexHullImpl::Vertex *)v193;
                ++v192->m_numUsed;
                v192->m_used = (hkgpConvexHullImpl::Vertex *)v193;
              }
              else
              {
                v193 = 0i64;
              }
              v195 = v192->m_allocator.m_firstPool;
              if ( !v192->m_allocator.m_firstPool || !v195->m_free )
              {
                v195 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v192->m_allocator);
                v192 = &v6->m_mesh.m_vertices;
              }
              if ( v195 )
              {
                v196 = v195->m_free;
                v195->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v196->m_data;
                v196->m_pool = v195;
                ++v195->m_used;
                *(_DWORD *)&v196->m_data[44] = 0;
                *(_DWORD *)&v196->m_data[52] = -1;
                *(_QWORD *)&v196->m_data[8] = 0i64;
                *(_QWORD *)v196->m_data = v192->m_used;
                v197 = v192->m_used;
                if ( v197 )
                  v197->m_prev = (hkgpConvexHullImpl::Vertex *)v196;
                ++v192->m_numUsed;
                v192->m_used = (hkgpConvexHullImpl::Vertex *)v196;
              }
              else
              {
                v196 = 0i64;
              }
              v198 = v225;
              *(_OWORD *)&v193->m_data[16] = v185;
              *(_QWORD *)&v193->m_data[32] = __PAIR64__(HIDWORD(v225), v198);
              *(_DWORD *)&v193->m_data[40] = v226;
              v199 = v213;
              *(_DWORD *)&v193->m_data[48] = 0;
              *(_DWORD *)&v193->m_data[44] = v187;
              *(_DWORD *)&v193->m_data[52] = v199;
              v200 = v222;
              *(_OWORD *)&v196->m_data[16] = v186;
              *(_QWORD *)&v196->m_data[32] = __PAIR64__(HIDWORD(v222), v200);
              *(_DWORD *)&v196->m_data[40] = v223;
              v201 = v210;
              *(_DWORD *)&v196->m_data[44] = v188;
              goto LABEL_220;
            }
            v6->m_dimensions = 0;
          }
        }
        v202 = v6->m_mesh.m_vertices.m_allocator.m_firstPool;
        v203 = &v6->m_mesh.m_vertices;
        if ( !v202 || !v202->m_free )
        {
          v202 = hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::allocateNewPool(&v6->m_mesh.m_vertices.m_allocator);
          v203 = &v6->m_mesh.m_vertices;
        }
        if ( v202 )
        {
          v196 = v202->m_free;
          v202->m_free = *(hkGeometryProcessing::PoolAllocator<hkgpConvexHullImpl::Vertex,32,hkContainerHeapAllocator>::Item **)v196->m_data;
          v196->m_pool = v202;
          ++v202->m_used;
          *(_DWORD *)&v196->m_data[44] = 0;
          *(_DWORD *)&v196->m_data[52] = -1;
          *(_QWORD *)&v196->m_data[8] = 0i64;
          *(_QWORD *)v196->m_data = v203->m_used;
          v204 = v203->m_used;
          if ( v204 )
            v204->m_prev = (hkgpConvexHullImpl::Vertex *)v196;
          ++v203->m_numUsed;
          v203->m_used = (hkgpConvexHullImpl::Vertex *)v196;
        }
        else
        {
          v196 = 0i64;
        }
        v205 = *(hkgpConvexHullImpl::Vertex **)p_m_pendings;
        *(_OWORD *)&v196->m_data[16] = *(_OWORD *)(*(_QWORD *)p_m_pendings + 16i64);
        *(_DWORD *)&v196->m_data[32] = v205->m_x[0];
        *(_DWORD *)&v196->m_data[36] = v205->m_x[1];
        *(_DWORD *)&v196->m_data[40] = v205->m_x[2];
        *(float *)&v196->m_data[44] = v205->m_scratch;
        *(_DWORD *)&v196->m_data[48] = v205->m_refs;
        v201 = v205->m_index;
LABEL_220:
        *(_DWORD *)&v196->m_data[48] = 0;
        *(_DWORD *)&v196->m_data[52] = v201;
        goto LABEL_221;
      }
      hkgpConvexHullImpl::computeProjectionPlane(v6, points, v14, p_m_projectionPlane);
      v14 = numPointsa;
    }
    v206 = 1;
    goto LABEL_27;
  }
LABEL_221:
  if ( v6->m_dimensions != -1 )
  {
    if ( v6->m_config.m_buildIndices.m_bool )
      hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(v6);
    if ( v6->m_config.m_buildMassProperties.m_bool )
      hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(v6, (hkResult *)&numPointsa);
  }
  return (unsigned int)v6->m_dimensions;
}

