// File Line: 35
// RVA: 0xBCF670
void __fastcall hkaiUserEdgeUtils::UserEdgeSetup::UserEdgeSetup(hkaiUserEdgeUtils::UserEdgeSetup *this)
{
  this->m_obbA.m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_obbA.m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_obbA.m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_obbA.m_transform.m_translation = 0i64;
  this->m_obbA.m_halfExtents = 0i64;
  this->m_obbB.m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_obbB.m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_obbB.m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_obbB.m_transform.m_translation = 0i64;
  this->m_obbB.m_halfExtents = 0i64;
  *(_QWORD *)&this->m_userDataA = 0i64;
  this->m_costAtoB = -1.0;
  this->m_costBtoA = -1.0;
  *(_WORD *)&this->m_direction.m_storage = 3;
  this->m_forceAlign.m_bool = 1;
  this->m_worldUpA = 0i64;
  this->m_worldUpB = 0i64;
}

// File Line: 48
// RVA: 0xBCF7C0
void __fastcall hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(hkaiUserEdgeUtils::UserEdgePair *this)
{
  *(_QWORD *)&this->m_instanceUidA = -1i64;
  *(_QWORD *)&this->m_faceA = -1i64;
  *(_QWORD *)&this->m_userDataA = 0i64;
  this->m_direction.m_storage = 3;
  *(_DWORD *)&this->m_costAtoB.m_value = -1082081408;
}

// File Line: 54
// RVA: 0xBD1F10
hkSimdFloat32 *__fastcall getMidpointDistance(hkSimdFloat32 *result, hkVector4f *A1, hkVector4f *A2, hkVector4f *B1, hkVector4f *B2)
{
  hkSimdFloat32 *v5; // rax
  __m128 v6; // xmm3
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm1

  v5 = result;
  v6 = _mm_sub_ps(
         _mm_add_ps(_mm_mul_ps(_mm_sub_ps(A2->m_quad, A1->m_quad), (__m128)xmmword_141A711B0), A1->m_quad),
         _mm_add_ps(_mm_mul_ps(_mm_sub_ps(B2->m_quad, B1->m_quad), (__m128)xmmword_141A711B0), B1->m_quad));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  result->m_real = _mm_andnot_ps(
                     _mm_cmpleps(v8, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v9), v9)),
                         _mm_mul_ps(*(__m128 *)_xmm, v9)),
                       v8));
  return v5;
}

// File Line: 92
// RVA: 0xBCF3E0
void __fastcall hkaiUserEdgeUtils::Obb::getUpAndHorizontalSegments(hkaiUserEdgeUtils::Obb *this, hkVector4f *up, hkVector4f *upOutStart, hkVector4f *upOutEnd, hkVector4f *horizOutStart, hkVector4f *horizOutEnd)
{
  __m128 v6; // xmm4
  hkaiUserEdgeUtils::Obb *v7; // rdi
  hkVector4f *v8; // r14
  hkVector4f *v9; // rsi
  hkVector4f *v10; // rbp
  __m128 v11; // xmm3
  __int64 v12; // rdx
  __m128 v13; // xmm3
  int v14; // ebx
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm9
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm5
  hkVector4f v27; // [rsp+20h] [rbp-88h]
  hkVector4f v28; // [rsp+30h] [rbp-78h]
  hkVector4f segOutA; // [rsp+40h] [rbp-68h]
  hkVector4f segOutB; // [rsp+50h] [rbp-58h]

  v6 = (__m128)_mm_load_si128((const __m128i *)&this->m_halfExtents);
  v7 = this;
  v8 = upOutStart;
  v9 = up;
  v10 = upOutEnd;
  v11 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v6, 1u), 1u);
  v27.m_quad = v6;
  v12 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v11, v11, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v11, v11, 85),
                                                                       _mm_shuffle_ps(v11, v11, 0))),
                                                                   v11),
                                                                 (__m128)xmmword_141A5C410))];
  v27.m_quad.m128_i32[v12] = 0;
  v13 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v27), 1u), 1u);
  v14 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v13, v13, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v13, v13, 85),
                                                                       _mm_shuffle_ps(v13, v13, 0))),
                                                                   v13),
                                                                 (__m128)xmmword_141A5C410))];
  hkaiUserEdgeUtils::Obb::_getSegmentForAxis(this, v12, &segOutA, &segOutB);
  hkaiUserEdgeUtils::Obb::_getSegmentForAxis(v7, v14, &v27, &v28);
  v15 = v27.m_quad;
  v16 = v28.m_quad;
  v17 = segOutB.m_quad;
  v18 = _mm_sub_ps(v27.m_quad, v28.m_quad);
  v19 = _mm_mul_ps(v9->m_quad, v18);
  v20 = _mm_sub_ps(segOutA.m_quad, segOutB.m_quad);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v22 = _mm_mul_ps(v9->m_quad, v20);
  v23 = _mm_sub_ps(v18, _mm_mul_ps(v21, v9->m_quad));
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_sub_ps(
          v20,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170)),
            v9->m_quad));
  v26 = _mm_mul_ps(v25, v25);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85))
                                                                             + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                                                                     + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))) )
  {
    *horizOutStart = (hkVector4f)segOutA.m_quad;
    *horizOutEnd = (hkVector4f)v17;
    *v8 = (hkVector4f)v15;
    *v10 = (hkVector4f)v16;
  }
  else
  {
    *v8 = (hkVector4f)segOutA.m_quad;
    *v10 = (hkVector4f)v17;
    *horizOutStart = (hkVector4f)v15;
    *horizOutEnd = (hkVector4f)v16;
  }
}

// File Line: 137
// RVA: 0xBCF600
void __fastcall hkaiUserEdgeUtils::Obb::_getSegmentForAxis(hkaiUserEdgeUtils::Obb *this, int i, hkVector4f *segOutA, hkVector4f *segOutB)
{
  __int64 v4; // rax
  hkaiUserEdgeUtils::Obb *v5; // rbx
  int v6; // xmm1_4
  hkVector4f *v7; // rdi
  hkVector4f b; // [rsp+20h] [rbp-28h]
  hkVector4f v9; // [rsp+30h] [rbp-18h]

  v4 = i;
  v5 = this;
  v6 = this->m_halfExtents.m_quad.m128_i32[i];
  v7 = segOutB;
  b.m_quad = 0i64;
  v9.m_quad = 0i64;
  v9.m_quad.m128_i32[v4] = v6;
  b.m_quad.m128_i32[v4] = v6 ^ _xmm[0];
  hkVector4f::setTransformedPos(segOutA, &this->m_transform, &b);
  hkVector4f::setTransformedPos(v7, &v5->m_transform, &v9);
}

// File Line: 146
// RVA: 0xBCF220
void __fastcall hkaiUserEdgeUtils::Obb::setFromLineSegment(hkaiUserEdgeUtils::Obb *this, hkVector4f *p0, hkVector4f *p1, hkVector4f *verticalHalfExtent)
{
  __m128 v4; // xmm12
  __m128 v5; // xmm1
  hkVector4f v6; // xmm11
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm10
  hkVector4f v10; // xmm12
  __m128 v11; // xmm10
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm5
  hkVector4f v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1

  v4 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6.m_quad = _mm_add_ps(_mm_mul_ps(v4, (__m128)xmmword_141A711B0), p0->m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmpleps(v7, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)));
  v10.m_quad = _mm_mul_ps(v4, v9);
  v11 = _mm_mul_ps(v9, v7);
  v12 = _mm_mul_ps(verticalHalfExtent->m_quad, verticalHalfExtent->m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_andnot_ps(
          _mm_cmpleps(v13, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)), _mm_mul_ps(*(__m128 *)_xmm, v14)));
  v16.m_quad = _mm_mul_ps(verticalHalfExtent->m_quad, v15);
  v17 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 201), v10.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 201), v16.m_quad));
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  this->m_transform.m_rotation.m_col0 = (hkVector4f)v10.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)v16.m_quad;
  this->m_transform.m_rotation.m_col2.m_quad = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmpleps(v20, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v21))),
                                                 v18);
  this->m_transform.m_translation = (hkVector4f)v6.m_quad;
  this->m_halfExtents.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps(_mm_mul_ps(v11, (__m128)xmmword_141A711B0), (__m128)LODWORD(epsilon)),
                                 _mm_unpacklo_ps(_mm_mul_ps(v15, v13), (__m128)0i64));
}

// File Line: 164
// RVA: 0xBCF710
void __fastcall hkaiUserEdgeUtils::UserEdgeSetup::setFromLineSegments(hkaiUserEdgeUtils::UserEdgeSetup *this, hkVector4f *A1, hkVector4f *A2, hkVector4f *B1, hkVector4f *B2, hkVector4f *verticalHalfExtent)
{
  hkVector4f *v6; // rdi
  hkaiUserEdgeUtils::UserEdgeSetup *v7; // rsi
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm5

  v6 = B1;
  v7 = this;
  hkaiUserEdgeUtils::Obb::setFromLineSegment(&this->m_obbA, A1, A2, verticalHalfExtent);
  hkaiUserEdgeUtils::Obb::setFromLineSegment(&v7->m_obbB, v6, B2, verticalHalfExtent);
  v8 = _mm_mul_ps(verticalHalfExtent->m_quad, verticalHalfExtent->m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          verticalHalfExtent->m_quad,
          _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v7->m_worldUpA.m_quad = v11;
  v7->m_worldUpB.m_quad = v11;
}

// File Line: 173
// RVA: 0xBCF7F0
void __fastcall hkaiUserEdgeUtils::createUserEdgePairs(hkaiUserEdgeUtils::UserEdgeSetup *input, hkaiNavMeshInstance *meshInstance, hkaiNavMeshQueryMediator *mediator, hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *userEdgePairsOut, float minEdgeLength)
{
  hkaiUserEdgeUtils::createUserEdgePairs(
    input,
    meshInstance,
    meshInstance,
    mediator,
    mediator,
    userEdgePairsOut,
    minEdgeLength);
}

// File Line: 178
// RVA: 0xBCF820
void __fastcall hkaiUserEdgeUtils::createUserEdgePairs(hkaiUserEdgeUtils::UserEdgeSetup *input, hkaiNavMeshInstance *meshA, hkaiNavMeshInstance *meshB, hkaiNavMeshQueryMediator *mediatorA, hkaiNavMeshQueryMediator *mediatorB, hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *userEdgePairsOut, float minEdgeLength)
{
  hkVector4f v7; // xmm1
  hkaiNavMeshInstance *v8; // r13
  hkaiNavMeshInstance *v9; // r12
  hkaiUserEdgeUtils::UserEdgeSetup *v10; // rdi
  __m128 v11; // xmm8
  __m128 v12; // xmm11
  signed int v13; // esi
  hkVector4f *horizOutStart; // r14
  hkVector4f *v15; // r15
  signed __int64 v16; // rax
  bool v17; // zf
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  hkaiNavMeshInstance *v21; // rdx
  __m128 *v22; // rax
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  float v30; // xmm0_4
  __m128 v31; // xmm10
  __m128 v32; // xmm12
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm4
  __m128 v38; // xmm7
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm5
  __m128 v43; // xmm2
  __m128 v44; // xmm5
  signed int v45; // edi
  __int64 *v46; // rcx
  hkVector4f *v47; // rax
  void **v48; // rbx
  hkaiNavMeshInstance *v49; // r14
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  hkVector4f *v52; // rax
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 *v55; // rax
  hkVector4f *v56; // rax
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __int64 v59; // rax
  int v60; // er12
  hkArray<int,hkContainerHeapAllocator> *v61; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v62; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v63; // r8
  __int64 v64; // r15
  int v65; // esi
  hkaiNavMesh::Face *v66; // rax
  hkArrayBase<hkVector4f> *v67; // r9
  void *v68; // r11
  hkaiNavMesh::Face *v69; // r13
  int v70; // edi
  int v71; // er9
  __m128 v72; // xmm8
  __m128 v73; // xmm9
  __m128 v74; // xmm6
  __m128 v75; // xmm1
  __m128 v76; // xmm5
  float v77; // xmm7_4
  __m128 v78; // xmm3
  __m128 v79; // xmm1
  float v80; // xmm2_4
  float v81; // xmm4_4
  __m128 v82; // xmm1
  __m128 v83; // xmm2
  signed __int64 v84; // rax
  hkVector4f v85; // xmm0
  __m128 v86; // xmm15
  int v87; // ecx
  __int64 v88; // rdi
  int v89; // edx
  int v90; // eax
  __m128 v91; // xmm2
  __int64 v92; // r12
  int v93; // esi
  __m128 v94; // xmm3
  char *v95; // r15
  char *v96; // r14
  __m128 v97; // xmm6
  __m128 v98; // xmm14
  __m128 v99; // xmm8
  __m128 v100; // xmm7
  __m128 v101; // xmm10
  __m128 v102; // xmm9
  __m128 v103; // xmm3
  __m128 v104; // xmm8
  __m128 v105; // xmm6
  __m128 v106; // xmm4
  __m128 v107; // xmm13
  __m128 v108; // xmm2
  __m128 v109; // xmm4
  __m128 v110; // xmm1
  __m128 v111; // xmm12
  __m128 v112; // xmm13
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm11
  __m128 v116; // xmm5
  __m128 v117; // xmm10
  __m128 v118; // xmm14
  __m128 v119; // xmm5
  __m128 v120; // xmm6
  __m128 v121; // xmm1
  __m128 v122; // xmm0
  __m128 v123; // xmm14
  float v124; // xmm1_4
  __m128 v125; // xmm7
  __m128 v126; // xmm6
  float v127; // xmm0_4
  float v128; // ST40_4
  hkBaseObjectVtbl *v129; // rcx
  hkVector4f v130; // xmm0
  __int128 v131; // xmm1
  signed int v132; // [rsp+40h] [rbp-B8h]
  hkResult result; // [rsp+44h] [rbp-B4h]
  char *v134; // [rsp+48h] [rbp-B0h]
  int v135; // [rsp+50h] [rbp-A8h]
  int v136; // [rsp+54h] [rbp-A4h]
  void *array; // [rsp+58h] [rbp-A0h]
  int v138; // [rsp+60h] [rbp-98h]
  int v139; // [rsp+64h] [rbp-94h]
  void *v140; // [rsp+68h] [rbp-90h]
  int v141; // [rsp+70h] [rbp-88h]
  int v142; // [rsp+74h] [rbp-84h]
  char *v143; // [rsp+78h] [rbp-80h]
  hkVector4f Bout; // [rsp+88h] [rbp-70h]
  hkVector4f B1; // [rsp+98h] [rbp-60h]
  hkVector4f B2; // [rsp+A8h] [rbp-50h]
  hkVector4f A1; // [rsp+B8h] [rbp-40h]
  hkVector4f A2; // [rsp+C8h] [rbp-30h]
  hkTransformf v149; // [rsp+D8h] [rbp-20h]
  __int128 v150; // [rsp+118h] [rbp+20h]
  float *v151; // [rsp+128h] [rbp+30h]
  __m128 v152; // [rsp+138h] [rbp+40h]
  __m128 v153; // [rsp+148h] [rbp+50h]
  hkVector4f *up; // [rsp+158h] [rbp+60h]
  hkTransformf bTc; // [rsp+168h] [rbp+70h]
  __m128 v156; // [rsp+1A8h] [rbp+B0h]
  hkVector4f A; // [rsp+1B8h] [rbp+C0h]
  hkVector4f B; // [rsp+1C8h] [rbp+D0h]
  __m128 v159; // [rsp+1D8h] [rbp+E0h]
  __m128 v160; // [rsp+1E8h] [rbp+F0h]
  hkVector4f Aout; // [rsp+1F8h] [rbp+100h]
  hkTransformf v162; // [rsp+208h] [rbp+110h]
  hkTransformf v163; // [rsp+248h] [rbp+150h]
  char v164; // [rsp+288h] [rbp+190h]
  hkVector4f upOutStart; // [rsp+2A8h] [rbp+1B0h]
  float *retaddr; // [rsp+3B8h] [rbp+2C0h]
  hkaiUserEdgeUtils::UserEdgeSetup *v167; // [rsp+3C0h] [rbp+2C8h]
  hkaiNavMeshInstance *v168; // [rsp+3C8h] [rbp+2D0h]
  int v169; // [rsp+3C8h] [rbp+2D0h]
  hkaiNavMeshInstance *v170; // [rsp+3D0h] [rbp+2D8h]
  hkaiNavMeshQueryMediator *v171; // [rsp+3D8h] [rbp+2E0h]

  v171 = mediatorA;
  v170 = meshB;
  v168 = meshA;
  v167 = input;
  v7.m_quad = (__m128)input->m_worldUpB;
  _mm_store_si128((__m128i *)&v159, (__m128i)input->m_worldUpA.m_quad);
  _mm_store_si128((__m128i *)&v160, (__m128i)v7.m_quad);
  v8 = meshB;
  v9 = meshA;
  v10 = input;
  v136 = 2147483648;
  v11 = _mm_shuffle_ps((__m128)(unsigned int)userEdgePairsOut, (__m128)(unsigned int)userEdgePairsOut, 0);
  v12 = (__m128)_xmm;
  v152 = 0i64;
  v153 = 0i64;
  v143 = 0i64;
  v134 = 0i64;
  v135 = 0;
  v13 = 0;
  do
  {
    horizOutStart = &A1;
    if ( v13 )
      horizOutStart = &B1;
    v15 = (hkVector4f *)&v164;
    if ( v13 )
      v15 = &upOutStart;
    v16 = (signed __int64)v10;
    if ( v13 )
      v16 = (signed __int64)&v10->m_obbB;
    v17 = v10->m_space.m_storage == 1;
    v18.m_quad = *(__m128 *)(v16 + 16);
    bTc.m_rotation.m_col0 = *(hkVector4f *)v16;
    v19.m_quad = *(__m128 *)(v16 + 32);
    bTc.m_rotation.m_col1 = (hkVector4f)v18.m_quad;
    v20.m_quad = *(__m128 *)(v16 + 48);
    bTc.m_rotation.m_col2 = (hkVector4f)v19.m_quad;
    v156 = *(__m128 *)(v16 + 64);
    bTc.m_translation = (hkVector4f)v20.m_quad;
    if ( v17 )
    {
      v21 = v8;
      if ( !v13 )
        v21 = v9;
      hkTransformf::setMul(&v149, &v21->m_referenceFrame.m_transform, &bTc);
      bTc = v149;
    }
    hkaiUserEdgeUtils::Obb::getUpAndHorizontalSegments(
      (hkaiUserEdgeUtils::Obb *)&bTc,
      (hkVector4f *)&v159 + v13,
      v15,
      v15 + 1,
      horizOutStart,
      horizOutStart + 1);
    v22 = &v152;
    v23 = _mm_sub_ps(horizOutStart->m_quad, horizOutStart[1].m_quad);
    if ( v13 )
      v22 = &v153;
    ++v13;
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_rsqrt_ps(v25);
    v27 = _mm_andnot_ps(
            _mm_cmpleps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(v26, *(__m128 *)_xmm)),
              v25));
    v28 = _mm_rcp_ps(v27);
    *v22 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v27)), v28), v11);
  }
  while ( v13 < 2 );
  if ( v10->m_forceAlign.m_bool )
  {
    v29 = _mm_mul_ps(v160, v159);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170))) >= 0.0 )
      v30 = *(float *)&FLOAT_1_0;
    else
      v30 = FLOAT_N1_0;
    v31 = A2.m_quad;
    v32 = B2.m_quad;
    v25.m128_f32[0] = v30;
    v33 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v160), v159);
    v34 = _mm_mul_ps(v33, v33);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v36 = _mm_rsqrt_ps(v35);
    v37 = _mm_mul_ps(
            v33,
            _mm_andnot_ps(
              _mm_cmpleps(v35, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                _mm_mul_ps(v36, *(__m128 *)_xmm))));
    v38 = _mm_sub_ps(B2.m_quad, B1.m_quad);
    v39 = _mm_sub_ps(A2.m_quad, A1.m_quad);
    v40 = _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(v38, (__m128)xmmword_141A711B0), B1.m_quad),
            _mm_add_ps(_mm_mul_ps(v39, (__m128)xmmword_141A711B0), A1.m_quad));
    v41 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v37), _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v40));
    v42 = _mm_shuffle_ps(v41, v41, 201);
    v43 = _mm_mul_ps(v42, v39);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 170))) < 0.0 )
    {
      A2.m_quad = A1.m_quad;
      A1.m_quad = v31;
    }
    v44 = _mm_mul_ps(v42, v38);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170))) > 0.0 )
    {
      B2.m_quad = B1.m_quad;
      B1.m_quad = v32;
    }
  }
  v45 = 0;
  v132 = 0;
  do
  {
    v46 = (__int64 *)v171;
    if ( !v45 )
      v46 = (__int64 *)v170;
    v47 = &A1;
    v48 = (void **)&v143;
    if ( v45 )
      v47 = &B1;
    v49 = v8;
    if ( !v45 )
      v49 = v9;
    v140 = 0i64;
    v50 = v47->m_quad;
    v51 = v47->m_quad;
    A.m_quad = v47->m_quad;
    v52 = &A2;
    v141 = 0;
    v142 = 2147483648;
    if ( v45 )
      v52 = &B2;
    bTc.m_rotation.m_col0.m_quad.m128_i32[0] = 0;
    bTc.m_rotation.m_col0.m_quad.m128_u64[1] = 0i64;
    bTc.m_rotation.m_col1.m_quad.m128_u64[0] = 0i64;
    bTc.m_rotation.m_col1.m_quad.m128_u64[1] = (unsigned __int64)v49;
    B.m_quad = v52->m_quad;
    v53 = _mm_min_ps(v51, B.m_quad);
    v54 = _mm_max_ps(v50, B.m_quad);
    v55 = &v152;
    if ( v45 )
      v55 = &v153;
    v151 = (float *)v55;
    if ( v45 )
      v48 = (void **)&v134;
    v56 = (hkVector4f *)&v164;
    if ( v45 )
      v56 = &upOutStart;
    v57 = _mm_min_ps(_mm_min_ps(v53, v56->m_quad), v56[1].m_quad);
    v58 = _mm_max_ps(_mm_max_ps(v54, v56->m_quad), v56[1].m_quad);
    bTc.m_rotation.m_col2.m_quad.m128_u64[0] = (unsigned __int64)&v49->m_referenceFrame;
    v59 = *v46;
    bTc.m_translation.m_quad = _mm_sub_ps(v57, (__m128)_xmm);
    v156 = _mm_add_ps(v58, (__m128)_xmm);
    (*(void (__fastcall **)(__int64 *, hkTransformf *, void **))(v59 + 56))(v46, &bTc, &v140);
    v60 = 0;
    if ( v141 > 0 )
    {
      v61 = &v49->m_faceMap;
      v62 = &v49->m_ownedFaces;
      v63 = &v49->m_instancedFaces;
      v64 = 0i64;
      up = (hkVector4f *)(&v159 + v45);
      do
      {
        v65 = *(_DWORD *)((_BYTE *)v140 + v64) & 0x3FFFFF;
        v66 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
                v49->m_originalFaces,
                v49->m_numOriginalFaces,
                v63,
                v62,
                v61,
                v65);
        array = v68;
        v138 = (signed int)v68;
        v139 = 2147483648;
        v69 = v66;
        v70 = v66->m_numEdges + 1;
        if ( v70 <= 0 )
        {
          result.m_enum = (hkResultEnum)v68;
        }
        else
        {
          v71 = v66->m_numEdges + 1;
          if ( v70 < 0 )
            v71 = (signed int)v68;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v71, 16);
        }
        v138 = v70;
        hkaiNavMeshUtils::getFaceVertices(v49, v69, (hkArrayBase<hkVector4f> *)&array, v67);
        if ( hkaiPathProjectionUtil::projectSegmentOntoFaceAndClipEdgesWorldUp(
               (hkArrayBase<hkVector4f> *)&array,
               v65,
               &A,
               &B,
               up,
               &Aout,
               &Bout) )
        {
          v72 = Aout.m_quad;
          v73 = Bout.m_quad;
          v149.m_translation.m_quad.m128_i32[0] = v65;
          v74 = _mm_sub_ps(B.m_quad, A.m_quad);
          v75 = _mm_mul_ps(v74, A.m_quad);
          v76 = _mm_mul_ps(v74, v74);
          v77 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 170));
          v78 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                  _mm_shuffle_ps(v76, v76, 170));
          v79 = _mm_mul_ps(Aout.m_quad, v74);
          v80 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 170));
          v79.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v78);
          v81 = (float)((float)(2.0 - (float)(v79.m128_f32[0] * v78.m128_f32[0])) * v79.m128_f32[0])
              * (float)(v80 - v77);
          v82 = _mm_mul_ps(Bout.m_quad, v74);
          v149.m_rotation.m_col0.m_quad.m128_f32[0] = v81;
          v83 = v78;
          v78.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 85))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 170));
          v82.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v83);
          v149.m_rotation.m_col0.m_quad.m128_f32[1] = (float)((float)(2.0 - (float)(v82.m128_f32[0] * v83.m128_f32[0]))
                                                            * v82.m128_f32[0])
                                                    * (float)(v78.m128_f32[0] - v77);
          if ( (float)(v149.m_rotation.m_col0.m_quad.m128_f32[1] - v81) > *v151 )
          {
            if ( *((_DWORD *)v48 + 2) == (*((_DWORD *)v48 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v48, 64);
            v84 = (signed __int64)*v48 + 64 * (signed __int64)*((signed int *)v48 + 2);
            if ( v84 )
            {
              *(hkVector4f *)v84 = v149.m_rotation.m_col0;
              v85.m_quad = (__m128)v149.m_translation;
              *(__m128 *)(v84 + 16) = v72;
              *(__m128 *)(v84 + 32) = v73;
              *(hkVector4f *)(v84 + 48) = (hkVector4f)v85.m_quad;
            }
            ++*((_DWORD *)v48 + 2);
          }
        }
        v138 = 0;
        if ( v139 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            16 * v139);
        ++v60;
        v64 += 4i64;
        array = 0i64;
        v139 = 2147483648;
        v61 = &v49->m_faceMap;
        v62 = &v49->m_ownedFaces;
        v63 = &v49->m_instancedFaces;
      }
      while ( v60 < v141 );
      v45 = v132;
      v8 = v168;
    }
    v141 = 0;
    if ( v142 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v140,
        4 * v142);
    v9 = (hkaiNavMeshInstance *)v167;
    ++v45;
    v140 = 0i64;
    v142 = 2147483648;
    v132 = v45;
  }
  while ( v45 < 2 );
  v86 = getMidpointDistance((hkSimdFloat32 *)&Bout, &A1, &A2, &B1, &B2)->m_real;
  hkTransformf::setInverse(&v163, (hkTransformf *)((char *)&v167->m_obbB.m_transform + 32));
  hkTransformf::setInverse(&v162, &v8->m_referenceFrame.m_transform);
  v87 = (signed int)v143;
  v88 = 0i64;
  v89 = 0;
  v169 = 0;
  if ( (signed int)v143 > 0 )
  {
    v90 = v135;
    v91 = query.m_quad;
    v92 = 0i64;
    do
    {
      v93 = 0;
      if ( v90 > 0 )
      {
        v94 = _mm_max_ps(v152, v153);
        Bout.m_quad = v94;
        do
        {
          v95 = v134;
          v96 = v143;
          v97 = _mm_shuffle_ps((__m128)*(unsigned int *)&v143[v92 + 4], (__m128)*(unsigned int *)&v143[v92 + 4], 0);
          v98 = _mm_sub_ps(
                  v91,
                  _mm_shuffle_ps((__m128)*(unsigned int *)&v134[v88 + 4], (__m128)*(unsigned int *)&v134[v88 + 4], 0));
          v99 = _mm_sub_ps(
                  v91,
                  _mm_shuffle_ps((__m128)*(unsigned int *)&v134[v88], (__m128)*(unsigned int *)&v134[v88], 0));
          v100 = _mm_shuffle_ps((__m128)*(unsigned int *)&v143[v92], (__m128)*(unsigned int *)&v143[v92], 0);
          v101 = _mm_min_ps(v97, v99);
          v102 = _mm_max_ps(v100, v98);
          if ( (float)(v101.m128_f32[0] - v102.m128_f32[0]) > v94.m128_f32[0] )
          {
            hkaiUserEdgeUtils::UserEdgePair::UserEdgePair((hkaiUserEdgeUtils::UserEdgePair *)&v149);
            v103 = *(__m128 *)&v96[v92 + 16];
            v104 = _mm_sub_ps(v99, v98);
            v105 = _mm_sub_ps(v97, v100);
            *(float *)&v150 = retaddr[40];
            v106 = _mm_rcp_ps(v105);
            *((float *)&v150 + 1) = retaddr[41];
            v107 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v12, _mm_mul_ps(v105, v106)), v106), _mm_sub_ps(v101, v100));
            v108 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v12, _mm_mul_ps(v105, v106)), v106), _mm_sub_ps(v102, v100));
            v109 = _mm_rcp_ps(v104);
            v110 = _mm_sub_ps(*(__m128 *)&v96[v92 + 32], v103);
            v111 = _mm_add_ps(_mm_mul_ps(v110, v108), v103);
            v112 = _mm_add_ps(_mm_mul_ps(v107, v110), v103);
            v113 = *(__m128 *)&v95[v88 + 16];
            v114 = _mm_sub_ps(*(__m128 *)&v95[v88 + 32], v113);
            v115 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         query.m_quad,
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v12, _mm_mul_ps(v104, v109)), v109), _mm_sub_ps(v101, v98))),
                       v114),
                     v113);
            v116 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         query.m_quad,
                         _mm_mul_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v104, v109)), v109),
                           _mm_sub_ps(v102, v98))),
                       v114),
                     v113);
            v117 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v116, v116, 85), v162.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v116, v116, 0), v162.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 170), v162.m_rotation.m_col2.m_quad)),
                     v162.m_translation.m_quad);
            v118 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v111, v111, 85), v163.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v111, v111, 0), v163.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v111, v111, 170), v163.m_rotation.m_col2.m_quad)),
                     v163.m_translation.m_quad);
            v149.m_translation.m_quad.m128_i32[2] = *(_DWORD *)&v143[v92 + 48];
            v149.m_translation.m_quad.m128_i32[3] = *(_DWORD *)&v134[v88 + 48];
            v119 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v112, v112, 85), v163.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v112, v112, 0), v163.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v112, v112, 170), v163.m_rotation.m_col2.m_quad)),
                     v163.m_translation.m_quad);
            v120 = _mm_shuffle_ps(v118, v119, 68);
            v121 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v115, v115, 85), v162.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v115, v115, 0), v162.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v115, v115, 170), v162.m_rotation.m_col2.m_quad)),
                     v162.m_translation.m_quad);
            v122 = _mm_shuffle_ps(v121, v117, 68);
            v123 = _mm_shuffle_ps(_mm_shuffle_ps(v118, v119, 238), _mm_shuffle_ps(v121, v117, 238), 136);
            v124 = retaddr[42];
            v125 = _mm_shuffle_ps(v120, v122, 136);
            v126 = _mm_shuffle_ps(v120, v122, 221);
            if ( v124 < 0.0 )
              v124 = v86.m128_f32[0];
            v127 = retaddr[43];
            if ( v127 < 0.0 )
              v127 = v86.m128_f32[0];
            *(float *)&result.m_enum = v124 * 1.0039062;
            v128 = v127 * 1.0039062;
            WORD4(v150) = HIWORD(result.m_enum);
            WORD5(v150) = HIWORD(v128);
            BYTE12(v150) = *((_BYTE *)retaddr + 208);
            v149.m_translation.m_quad.m128_i32[0] = v167[2].m_obbA.m_transform.m_rotation.m_col1.m_quad.m128_i32[1];
            v149.m_translation.m_quad.m128_i32[1] = v8->m_sectionUid;
            if ( *(_DWORD *)&mediatorB->m_memSizeAndFlags == (*(_DWORD *)(&mediatorB->m_referenceCount + 1) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, mediatorB, 80);
            v129 = &mediatorB->vfptr[5 * *(signed int *)&mediatorB->m_memSizeAndFlags];
            if ( v129 )
            {
              v130.m_quad = (__m128)v149.m_translation;
              v131 = v150;
              *v129 = (hkBaseObjectVtbl)v125;
              v129[1] = (hkBaseObjectVtbl)v126;
              v129[2] = (hkBaseObjectVtbl)v123;
              v129[3] = (hkBaseObjectVtbl)v130.m_quad;
              v129[4] = (hkBaseObjectVtbl)v131;
            }
            ++*(_DWORD *)&mediatorB->m_memSizeAndFlags;
            v90 = v135;
            v94.m128_i32[0] = Bout.m_quad.m128_i32[0];
            v91 = query.m_quad;
            v12 = (__m128)_xmm;
          }
          ++v93;
          v88 += 64i64;
        }
        while ( v93 < v90 );
        v87 = (signed int)v143;
        v89 = v169;
        v88 = 0i64;
      }
      ++v89;
      v92 += 64i64;
      v169 = v89;
    }
    while ( v89 < v87 );
  }
  v135 = 0;
  if ( v136 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v134,
      v136 << 6);
  v134 = 0i64;
  LODWORD(v143) = 0;
  v136 = 2147483648;
  if ( SHIDWORD(v143) >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v143,
      HIDWORD(v143) << 6);
}

// File Line: 407
// RVA: 0xBD0770
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(hkaiNavMeshInstance *meshInstance, int faceIndexA, int faceIndexB, hkVector4f *edgeAStart, hkVector4f *edgeAEnd, hkVector4f *edgeBStart, hkVector4f *edgeBEnd, bool allowAtoB, bool allowBtoA, float costAtoB, float costBtoA)
{
  hkaiNavMeshInstance *v11; // rdi
  hkVector4f *v12; // rsi
  int v13; // ebp
  int v14; // er14
  int v15; // er9
  hkaiStreamingCollection::InstanceInfo *v16; // r8
  __int64 v17; // rdx
  hkaiDirectedGraphInstance **v18; // rax
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // ebx
  bool v22; // ST40_1
  bool v23; // al
  hkaiStreamingCollection array; // [rsp+60h] [rbp-48h]
  hkResult result; // [rsp+B0h] [rbp+8h]

  v11 = meshInstance;
  v12 = edgeAStart;
  v13 = faceIndexB;
  v14 = faceIndexA;
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v15 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v15 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v15,
      48);
  }
  v16 = array.m_instances.m_data;
  v17 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v18 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v18 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v18 - 2) = 0i64;
        *(v18 - 1) = 0i64;
        *v18 = 0i64;
        v18[1] = 0i64;
        v18[2] = 0i64;
        *((_DWORD *)v18 + 6) = -1;
      }
      v18 += 6;
      --v17;
    }
    while ( v17 );
    v16 = array.m_instances.m_data;
  }
  v19 = costBtoA;
  v20 = costAtoB;
  array.m_instances.m_size = 1;
  v16->m_instancePtr = v11;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  v21 = v11->m_runtimeId;
  v22 = allowBtoA;
  v23 = allowAtoB;
  v11->m_runtimeId = 0;
  hkaiUserEdgeUtils::addUserEdgePair(&array, v14, v13, v12, edgeAEnd, edgeBStart, edgeBEnd, v23, v22, v20, v19);
  v11->m_runtimeId = v21;
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 420
// RVA: 0xBD0640
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(hkaiNavMeshInstance *meshInstance, hkaiUserEdgeUtils::UserEdgePair *pair, hkaiUserEdgeUtils::UpdateParameters *params)
{
  hkaiNavMeshInstance *v3; // rdi
  hkaiUserEdgeUtils::UpdateParameters *v4; // rsi
  hkaiUserEdgeUtils::UserEdgePair *v5; // rbp
  int v6; // er9
  hkaiStreamingCollection::InstanceInfo *v7; // r8
  __int64 v8; // rdx
  hkaiDirectedGraphInstance **v9; // rax
  int v10; // ebx
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v3 = meshInstance;
  v4 = params;
  v5 = pair;
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v6 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v6 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v6,
      48);
  }
  v7 = array.m_instances.m_data;
  v8 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v9 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v9 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v9 - 2) = 0i64;
        *(v9 - 1) = 0i64;
        *v9 = 0i64;
        v9[1] = 0i64;
        v9[2] = 0i64;
        *((_DWORD *)v9 + 6) = -1;
      }
      v9 += 6;
      --v8;
    }
    while ( v8 );
    v7 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v7->m_instancePtr = v3;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  v10 = v3->m_runtimeId;
  v3->m_runtimeId = 0;
  hkaiUserEdgeUtils::addUserEdgePair(&array, v5, v4);
  v3->m_runtimeId = v10;
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 433
// RVA: 0xBD0920
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(hkaiStreamingCollection *collection, unsigned int faceKeyA, unsigned int faceKeyB, hkVector4f *edgeAStart, hkVector4f *edgeAEnd, hkVector4f *edgeBStart, hkVector4f *edgeBEnd, bool allowAtoB, int allowBtoA, float costAtoB, float costBtoA)
{
  hkaiStreamingCollection *v11; // rbp
  hkVector4f *v12; // rsi
  unsigned int v13; // edi
  unsigned int v14; // ebx
  hkaiStreamingCollection::InstanceInfo *v15; // rdx
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  hkaiUserEdgeUtils::UserEdgePair pair; // [rsp+20h] [rbp-58h]

  v11 = collection;
  v12 = edgeAStart;
  v13 = faceKeyB;
  v14 = faceKeyA;
  hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&pair);
  v15 = v11->m_instances.m_data;
  v16 = v12->m_quad;
  v17 = v12->m_quad;
  pair.m_faceA = v14 & 0x3FFFFF;
  pair.m_instanceUidA = v15[v14 >> 22].m_instancePtr->m_sectionUid;
  pair.m_faceB = v13 & 0x3FFFFF;
  pair.m_instanceUidB = v15[v13 >> 22].m_instancePtr->m_sectionUid;
  pair.m_direction.m_storage = ((_BYTE)allowBtoA != 0 ? 2 : 0) | (allowAtoB != 0);
  *(float *)&allowBtoA = costBtoA * 1.0039062;
  pair.m_costAtoB.m_value = COERCE_UNSIGNED_INT(costAtoB * 1.0039062) >> 16;
  LOWORD(allowBtoA) = 256;
  BYTE2(allowBtoA) = 0;
  pair.m_costBtoA.m_value = COERCE_UNSIGNED_INT(costBtoA * 1.0039062) >> 16;
  v18 = _mm_shuffle_ps(v17, edgeAEnd->m_quad, 68);
  v19 = _mm_shuffle_ps(edgeBStart->m_quad, edgeBEnd->m_quad, 68);
  pair.m_z.m_quad = _mm_shuffle_ps(
                      _mm_shuffle_ps(v16, edgeAEnd->m_quad, 238),
                      _mm_shuffle_ps(edgeBStart->m_quad, edgeBEnd->m_quad, 238),
                      136);
  pair.m_x.m_quad = _mm_shuffle_ps(v18, v19, 136);
  pair.m_y.m_quad = _mm_shuffle_ps(v18, v19, 221);
  hkaiUserEdgeUtils::addUserEdgePair(v11, &pair, (hkaiUserEdgeUtils::UpdateParameters *)&allowBtoA);
}

// File Line: 451
// RVA: 0xBD1FA0
void __fastcall reindexOpposite(hkaiStreamingCollection *collection, hkaiNavMeshInstance *instance, hkaiNavMesh::Edge *edge, int secIdx, int newEdgeIdx, unsigned int faceKey)
{
  hkaiNavMesh::Edge *v6; // r10
  char v7; // r11
  unsigned int v8; // eax
  unsigned int v9; // er8
  hkaiNavMeshInstance *v10; // rdx
  int v11; // ecx
  int v12; // eax
  signed __int64 v13; // rcx
  hkaiNavMesh::Edge *v14; // rax
  signed __int64 v15; // rdx
  int v16; // er9
  char v17; // [rsp+8h] [rbp+8h]

  v6 = edge;
  v7 = edge->m_flags.m_storage & 0x40;
  if ( v7 )
    v8 = edge->m_oppositeFace & 0xFFC00000;
  else
    v8 = instance->m_runtimeId << 22;
  v9 = v8 | edge->m_oppositeFace & 0x3FFFFF;
  if ( v6->m_oppositeFace == -1 )
    v9 = -1;
  v10 = collection->m_instances.m_data[v9 >> 22].m_instancePtr;
  if ( v10->m_faceFlags.m_size )
    v17 = v10->m_faceFlags.m_data[v9 & 0x3FFFFF].m_storage;
  else
    v17 = 0;
  if ( !(v17 & 1) )
  {
    v11 = v10->m_numOriginalEdges;
    v12 = v6->m_oppositeEdge & 0x3FFFFF;
    if ( v12 < v11 )
    {
      if ( v10->m_edgeMap.m_size )
        v12 = v10->m_edgeMap.m_data[v12];
      if ( v12 == -1 )
      {
        v15 = 0i64;
        goto LABEL_18;
      }
      v13 = v12;
      v14 = v10->m_instancedEdges.m_data;
    }
    else
    {
      v13 = v12 - v11;
      v14 = v10->m_ownedEdges.m_data;
    }
    v15 = (signed __int64)&v14[v13];
LABEL_18:
    if ( v7 )
    {
      v16 = newEdgeIdx | (secIdx << 22);
      *(_DWORD *)(v15 + 12) = faceKey;
      *(_DWORD *)(v15 + 8) = v16;
    }
    else
    {
      *(_DWORD *)(v15 + 8) = newEdgeIdx;
      *(_DWORD *)(v15 + 12) = faceKey & 0x3FFFFF;
    }
  }
}

// File Line: 478
// RVA: 0xBD20C0
void __fastcall setupEdges(hkaiNavMeshInstance *instanceA, hkaiNavMeshInstance *instanceB, unsigned int faceKeyA, unsigned int faceKeyB, unsigned int edgeKeyA, unsigned int edgeKeyB, hkaiUserEdgeUtils::UserEdgePair *pair)
{
  hkaiNavMeshInstance *v7; // r15
  int v8; // ecx
  int v9; // ebp
  int v10; // esi
  hkaiNavMeshInstance *v11; // r14
  signed __int64 v12; // rcx
  hkaiNavMesh::Edge *v13; // rax
  signed int v14; // edx
  signed __int64 v15; // rdi
  int v16; // ecx
  signed __int64 v17; // rcx
  hkaiNavMesh::Edge *v18; // rax
  signed int v19; // edx
  signed __int64 v20; // rbx
  hkaiUserEdgeUtils::UserEdgePair *v21; // r13
  int v22; // er12
  hkVector4f v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  bool v29; // zf
  int v30; // eax
  __m128 v31; // xmm6
  __m128 v32; // xmm5
  hkSimdFloat32 *v33; // rax
  float v34; // xmm6_4
  char v35; // cl
  hkSimdFloat32 result; // [rsp+30h] [rbp-A8h]
  hkVector4f B1; // [rsp+40h] [rbp-98h]
  hkVector4f B2; // [rsp+50h] [rbp-88h]
  hkVector4f v; // [rsp+60h] [rbp-78h]
  hkVector4f A2; // [rsp+70h] [rbp-68h]
  int v41; // [rsp+E0h] [rbp+8h]
  unsigned int v42; // [rsp+F0h] [rbp+18h]
  unsigned int v43; // [rsp+F8h] [rbp+20h]
  float edgeKeyBa; // [rsp+108h] [rbp+30h]
  bool paira; // [rsp+110h] [rbp+38h]

  v43 = faceKeyB;
  v42 = faceKeyA;
  v7 = instanceA;
  v8 = instanceA->m_numOriginalEdges;
  v9 = edgeKeyA & 0x3FFFFF;
  v10 = edgeKeyB & 0x3FFFFF;
  v11 = instanceB;
  if ( (signed int)(edgeKeyA & 0x3FFFFF) < v8 )
  {
    if ( v7->m_edgeMap.m_size )
      v14 = v7->m_edgeMap.m_data[v9];
    else
      v14 = edgeKeyA & 0x3FFFFF;
    if ( v14 == -1 )
    {
      v15 = 0i64;
      goto LABEL_10;
    }
    v12 = v14;
    v13 = v7->m_instancedEdges.m_data;
  }
  else
  {
    v12 = v9 - v8;
    v13 = v7->m_ownedEdges.m_data;
  }
  v15 = (signed __int64)&v13[v12];
LABEL_10:
  v16 = v11->m_numOriginalEdges;
  if ( v10 < v16 )
  {
    if ( v11->m_edgeMap.m_size )
      v19 = v11->m_edgeMap.m_data[v10];
    else
      v19 = edgeKeyB & 0x3FFFFF;
    if ( v19 == -1 )
    {
      v20 = 0i64;
      goto LABEL_19;
    }
    v17 = v19;
    v18 = v11->m_instancedEdges.m_data;
  }
  else
  {
    v17 = v10 - v16;
    v18 = v11->m_ownedEdges.m_data;
  }
  v20 = (signed __int64)&v18[v17];
LABEL_19:
  v21 = pair;
  v22 = v7->m_numOriginalVertices + v7->m_ownedVertices.m_size;
  v23.m_quad = (__m128)pair->m_z;
  v24 = v23.m_quad;
  v25 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 238);
  v26 = _mm_shuffle_ps(v23.m_quad, (__m128)0i64, 238);
  v27 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 68);
  v28 = _mm_shuffle_ps(v24, (__m128)0i64, 68);
  v.m_quad = _mm_shuffle_ps(v27, v28, 136);
  A2.m_quad = _mm_shuffle_ps(v27, v28, 221);
  B1.m_quad = _mm_shuffle_ps(v25, v26, 136);
  B2.m_quad = _mm_shuffle_ps(v25, v26, 221);
  hkaiNavMeshInstance::appendVertices(v7, &v, 2);
  v41 = v11->m_numOriginalVertices + v11->m_ownedVertices.m_size;
  hkaiNavMeshInstance::appendVertices(v11, &B1, 2);
  v29 = v7->m_sectionUid == v11->m_sectionUid;
  *(_DWORD *)v15 = v22;
  *(_DWORD *)(v15 + 16) = 4;
  paira = !v29;
  *(_DWORD *)(v15 + 4) = v22 + 1;
  if ( v29 )
  {
    *(_DWORD *)(v15 + 8) = v10;
    *(_DWORD *)(v15 + 12) = v43 & 0x3FFFFF;
    *(_DWORD *)(v20 + 8) = v9;
    *(_DWORD *)v20 = v41;
    *(_DWORD *)(v20 + 4) = v41 + 1;
    v30 = v42 & 0x3FFFFF;
  }
  else
  {
    *(_DWORD *)(v15 + 8) = edgeKeyB;
    *(_DWORD *)(v15 + 12) = v43;
    *(_DWORD *)v20 = v41;
    *(_DWORD *)(v20 + 4) = v41 + 1;
    *(_DWORD *)(v20 + 8) = edgeKeyA;
    v30 = v42;
  }
  *(_DWORD *)(v20 + 12) = v30;
  *(_DWORD *)(v20 + 16) = 4;
  *(_BYTE *)(v15 + 16) = 16;
  *(_BYTE *)(v20 + 16) = 16;
  v31.m128_i32[0] = v21->m_costAtoB.m_value << 16;
  v32.m128_i32[0] = v21->m_costBtoA.m_value << 16;
  if ( v31.m128_f32[0] < 0.0 || v32.m128_f32[0] < 0.0 )
  {
    v33 = getMidpointDistance(&result, &v, &A2, &B1, &B2);
    if ( v31.m128_f32[0] < 0.0 )
      v31 = v33->m_real;
    if ( v32.m128_f32[0] < 0.0 )
      v32 = v33->m_real;
  }
  v34 = v31.m128_f32[0] * 1.0039062;
  edgeKeyBa = v32.m128_f32[0] * 1.0039062;
  *(_WORD *)(v15 + 18) = HIWORD(v34);
  *(_WORD *)(v20 + 18) = HIWORD(edgeKeyBa);
  hkaiNavMeshInstance::setEdgeData(v7, v9, v21->m_userDataA);
  hkaiNavMeshInstance::setEdgeData(v11, v10, v21->m_userDataB);
  v35 = ((unsigned __int8)v21->m_direction.m_storage >> 1) & 1;
  if ( !(v21->m_direction.m_storage & 1) )
    *(_BYTE *)(v15 + 16) |= 0x20u;
  if ( !v35 )
    *(_BYTE *)(v20 + 16) |= 0x20u;
  if ( paira )
  {
    *(_BYTE *)(v15 + 16) |= 0x40u;
    *(_BYTE *)(v20 + 16) |= 0x40u;
  }
}

// File Line: 554
// RVA: 0xBD0520
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(hkaiStreamingCollection *collection, hkaiUserEdgeUtils::UserEdgePair *pair, hkaiUserEdgeUtils::UpdateParameters *params)
{
  hkaiStreamingCollection *v3; // rsi
  hkaiUserEdgeUtils::UpdateParameters *v4; // rdi
  hkaiUserEdgeUtils::UserEdgePair *v5; // rbx
  int v6; // er8
  hkVector4f *v7; // rcx
  hkaiUserEdgeUtils::UserEdgePair *array; // [rsp+20h] [rbp-68h]
  int v9; // [rsp+28h] [rbp-60h]
  int v10; // [rsp+2Ch] [rbp-5Ch]
  hkaiUserEdgeUtils::UserEdgePair v11; // [rsp+30h] [rbp-58h]

  v3 = collection;
  v4 = params;
  v5 = pair;
  v9 = 0;
  array = &v11;
  v10 = -2147483647;
  hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&v11);
  v6 = 0;
  v7 = &array[v6].m_x;
  if ( v7 )
  {
    *v7 = v5->m_x;
    v7[1] = v5->m_y;
    v7[2] = v5->m_z;
    v7[3] = *(hkVector4f *)&v5->m_instanceUidA;
    v7[4] = *(hkVector4f *)&v5->m_userDataA;
    v6 = v9;
  }
  v9 = v6 + 1;
  hkaiUserEdgeUtils::addUserEdgePairsBatch(v3, (hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *)&array, v4);
  v9 = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      80 * (v10 & 0x3FFFFFFF));
}

// File Line: 562
// RVA: 0xBD0AA0
void __fastcall hkaiUserEdgeUtils::addUserEdgePairsBatch(hkaiStreamingCollection *collection, hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *pairs, hkaiUserEdgeUtils::UpdateParameters *params)
{
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v3; // r15
  hkaiStreamingCollection *v4; // r13
  int v5; // ebx
  int v6; // edi
  int v7; // er14
  hkLifoAllocator *v8; // rax
  _DWORD *v9; // rdx
  int v10; // ecx
  char *v11; // r8
  signed int v12; // eax
  int v13; // eax
  int v14; // er9
  __int64 v15; // rcx
  _DWORD *v16; // rdi
  int v17; // er8
  int v18; // esi
  __int64 v19; // r15
  __int64 v20; // r14
  unsigned int *v21; // rbx
  __int64 v22; // r12
  int v23; // eax
  int v24; // er8
  unsigned int v25; // eax
  unsigned int v26; // ebx
  unsigned int v27; // edi
  int v28; // eax
  int v29; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v30; // r8
  int v31; // edx
  signed __int64 v32; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v33; // rax
  int v34; // eax
  signed __int64 v35; // rax
  int v36; // ecx
  hkaiStreamingCollection::InstanceInfo *v37; // rax
  __int64 v38; // r15
  int v39; // edx
  hkaiNavMeshInstance *v40; // rsi
  signed int v41; // eax
  int v42; // er8
  hkaiNavMesh::Face *v43; // r13
  int v44; // eax
  hkaiNavMesh::Face *v45; // rcx
  int v46; // edi
  int v47; // er12
  unsigned __int64 v48; // rbx
  Dummy *v49; // rax
  int v50; // edi
  signed __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v52; // rax
  __int16 v53; // ax
  int v54; // edi
  signed __int64 v55; // rbx
  int v56; // ecx
  signed __int64 v57; // rcx
  hkaiNavMesh::Edge *v58; // rax
  int v59; // ecx
  hkaiNavMesh::Edge *v60; // r8
  unsigned int v61; // edx
  int v62; // edx
  signed __int64 v63; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v64; // rax
  int v65; // er12
  hkaiStreamingCollection *v66; // rbx
  __int64 v67; // r13
  __int64 v68; // r14
  __int64 v69; // r15
  int v70; // eax
  unsigned int v71; // edx
  int v72; // edi
  int v73; // eax
  int v74; // ebx
  int v75; // eax
  unsigned __int64 v76; // rdx
  unsigned int v77; // ebx
  int secIdx; // ST2C_4
  unsigned int v79; // edi
  int v80; // esi
  int v81; // eax
  unsigned __int64 v82; // r8
  int v83; // ebx
  hkaiStreamingCollection::InstanceInfo *v84; // rdi
  unsigned int v85; // er8
  int v86; // esi
  unsigned int v87; // ebx
  hkaiNavMeshInstance *v88; // rdx
  char v89; // di
  hkaiStreamingCollection *v90; // rsi
  int v91; // edi
  __int64 v92; // rbx
  hkaiNavMeshInstance *v93; // rcx
  __int64 v94; // rdi
  __int64 v95; // rbx
  hkaiDirectedGraphInstance *v96; // rcx
  __int64 index; // [rsp+28h] [rbp-59h]
  int indexa; // [rsp+28h] [rbp-59h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v99; // [rsp+30h] [rbp-51h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v100; // [rsp+40h] [rbp-41h]
  unsigned int faceKeyA[2]; // [rsp+50h] [rbp-31h]
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> v102; // [rsp+58h] [rbp-29h]
  int v103; // [rsp+68h] [rbp-19h]
  _DWORD *array; // [rsp+70h] [rbp-11h]
  int v105; // [rsp+78h] [rbp-9h]
  unsigned int v106; // [rsp+7Ch] [rbp-5h]
  _DWORD *v107; // [rsp+80h] [rbp-1h]
  int v108; // [rsp+88h] [rbp+7h]
  int v109; // [rsp+90h] [rbp+Fh]
  hkaiStreamingCollection *collectiona; // [rsp+E8h] [rbp+67h]
  unsigned int userEdgeKey[2]; // [rsp+F0h] [rbp+6Fh]
  _BYTE *retaddr; // [rsp+F8h] [rbp+77h]
  hkaiStreamingCollection *result; // [rsp+100h] [rbp+7Fh]
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v114; // [rsp+108h] [rbp+87h]
  hkaiUserEdgeUtils::UpdateParameters *v115; // [rsp+110h] [rbp+8Fh]

  v115 = params;
  v114 = pairs;
  result = collection;
  v3 = pairs;
  v4 = collection;
  if ( pairs->m_size )
  {
    v5 = collection->m_instances.m_size;
    v6 = (v5 + 31) >> 5;
    v7 = 0;
    array = 0i64;
    v105 = 0;
    v106 = 2147483648;
    v108 = v6;
    if ( v6 )
    {
      v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = v8->m_cur;
      v10 = (4 * v6 + 127) & 0xFFFFFF80;
      v11 = (char *)v9 + v10;
      if ( v10 > v8->m_slabSize || v11 > v8->m_end )
        v9 = hkLifoAllocator::allocateFromNewSlab(v8, v10);
      else
        v8->m_cur = v11;
    }
    else
    {
      v9 = 0i64;
    }
    array = v9;
    v107 = v9;
    v109 = v5;
    v106 = v6 | 0x80000000;
    v12 = (v6 | 0x80000000) & 0x3FFFFFFF;
    if ( v12 < v6 )
    {
      v13 = 2 * v12;
      v14 = (v5 + 31) >> 5;
      if ( v6 < v13 )
        v14 = v13;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v14,
        4);
      v9 = array;
    }
    v105 = (v5 + 31) >> 5;
    if ( v6 - 1 >= 0 )
    {
      v15 = (unsigned int)v6;
      v16 = v9;
      while ( v15 )
      {
        *v16 = 0;
        ++v16;
        --v15;
      }
    }
    v99.m_elem = 0i64;
    v17 = 0;
    v99.m_numElems = 0;
    v99.m_hashMod = -1;
    v18 = 0;
    if ( v3->m_size > 0 )
    {
      v19 = 0i64;
      v20 = *(_QWORD *)userEdgeKey;
      do
      {
        v21 = (unsigned int *)(v19 + *(_QWORD *)v20);
        v22 = (signed int)hkaiStreamingCollection::findSectionIdByUid(v4, v21[12]);
        v23 = hkaiStreamingCollection::findSectionIdByUid(v4, v21[13]);
        v24 = v23;
        if ( (_DWORD)v22 != -1 && v23 != -1 )
        {
          array[v22 >> 5] |= 1 << (v22 & 0x1F);
          array[(signed __int64)v23 >> 5] |= 1 << (v23 & 0x1F);
          v25 = ((_DWORD)v22 << 22) | v21[14];
          v26 = (v24 << 22) | v21[15];
          v27 = v25;
          v28 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v99,
                  v25,
                  0i64);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v99,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v27,
            v28 + 1);
          v29 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v99,
                  v26,
                  0i64);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v99,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v26,
            v29 + 1);
        }
        ++v18;
        v19 += 80i64;
      }
      while ( v18 < *(_DWORD *)(v20 + 8) );
      v17 = v99.m_numElems;
      v7 = 0;
    }
    v100.m_elem = 0i64;
    v100.m_numElems = 0;
    v100.m_hashMod = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &v100,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v17 & 0x7FFFFFFF);
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v102);
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::reserve(
      &v102,
      v99.m_numElems & 0x7FFFFFFF);
    v30 = v99.m_elem;
    v31 = 0;
    v32 = 0i64;
    if ( v99.m_hashMod >= 0 )
    {
      v33 = v99.m_elem;
      do
      {
        if ( v33->key != -1i64 )
          break;
        ++v32;
        ++v31;
        ++v33;
      }
      while ( v32 <= v99.m_hashMod );
    }
    v34 = v31;
    *(_QWORD *)faceKeyA = v31;
    if ( v31 <= v99.m_hashMod )
    {
      while ( 1 )
      {
        v35 = v34;
        LODWORD(index) = v30[v35].key;
        v36 = v30[v35].val;
        v37 = v4->m_instances.m_data;
        v38 = (unsigned int)index >> 22;
        LODWORD(result) = v36;
        v39 = index & 0x3FFFFF;
        HIDWORD(index) = (unsigned int)index >> 22;
        v40 = v37[v38].m_instancePtr;
        v41 = v40->m_numOriginalFaces;
        v42 = v40->m_faceDataStriding;
        if ( (index & 0x3FFFFF) < v41 )
        {
          if ( v40->m_faceMap.m_size )
            v44 = v40->m_faceMap.m_data[v39];
          else
            v44 = index & 0x3FFFFF;
          if ( v44 == -1 )
          {
            v45 = v40->m_originalFaces;
            LODWORD(v99.m_elem) = v40->m_faceDataStriding;
            v43 = hkaiNavMeshInstance_instance_hkaiNavMesh::Face_int__0(
                    v45,
                    &v40->m_instancedFaces,
                    v40->m_originalFaceData,
                    &v40->m_instancedFaceData,
                    &v40->m_faceMap,
                    v39,
                    v42);
          }
          else
          {
            v43 = &v40->m_instancedFaces.m_data[v44];
          }
        }
        else
        {
          v43 = &v40->m_ownedFaces.m_data[v39 - v41];
        }
        v46 = (signed int)result;
        v47 = -1;
        v48 = (signed int)result + v43->m_numUserEdges;
        v49 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                &v102,
                v48);
        if ( (signed int)v49 <= v102.m_hashMod )
        {
          while ( LODWORD(v102.m_elem[(signed int)v49].val) >> 22 != (_DWORD)v38 )
          {
            v50 = (_DWORD)v49 + 1;
            for ( i = (signed int)v49 + 1; i > v102.m_hashMod; i = 0i64 )
LABEL_46:
              v50 = 0;
            v52 = &v102.m_elem[i];
            while ( v52->key != -1i64 )
            {
              if ( v52->key == v48 )
              {
                v49 = (Dummy *)v50;
                goto LABEL_49;
              }
              ++i;
              ++v50;
              ++v52;
              if ( i > v102.m_hashMod )
                goto LABEL_46;
            }
            v49 = (Dummy *)(v102.m_hashMod + 1);
LABEL_49:
            if ( (signed int)v49 > v102.m_hashMod )
              goto LABEL_52;
          }
          v47 = v102.m_elem[(signed int)v49].val & 0x3FFFFF;
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v102,
            v49);
LABEL_52:
          v46 = (signed int)result;
        }
        v53 = v43->m_numUserEdges;
        if ( !v53 )
        {
          if ( v47 == -1 )
          {
            v47 = v40->m_numOriginalEdges + v40->m_ownedEdges.m_size;
            hkaiNavMeshInstance::expandEdgesBy(v40, v46);
          }
          goto LABEL_72;
        }
        if ( v47 == -1 )
        {
          v47 = v40->m_numOriginalEdges + v40->m_ownedEdges.m_size;
          hkaiNavMeshInstance::expandEdgesBy(v40, v46 + v53);
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
            &v102,
            v43->m_numUserEdges,
            (unsigned int)((_DWORD)v38 << 22) | (unsigned __int64)(unsigned int)v43->m_startUserEdgeIndex);
        }
        if ( v43->m_numUserEdges > 0 )
          break;
LABEL_72:
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v100,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (unsigned int)index,
          v47 + v43->m_numUserEdges);
        v61 = faceKeyA[0];
        v43->m_numUserEdges += (signed __int16)result;
        v43->m_startUserEdgeIndex = v47;
        v30 = v99.m_elem;
        v62 = v61 + 1;
        v63 = v62;
        if ( v62 <= (signed __int64)v99.m_hashMod )
        {
          v64 = &v99.m_elem[v62];
          do
          {
            if ( v64->key != -1i64 )
              break;
            ++v63;
            ++v62;
            ++v64;
          }
          while ( v63 <= v99.m_hashMod );
        }
        v34 = v62;
        *(_QWORD *)faceKeyA = v62;
        if ( v62 > v99.m_hashMod )
          goto LABEL_77;
        v4 = collectiona;
      }
      v54 = v47;
      v55 = v47;
      while ( 1 )
      {
        hkaiNavMeshInstance::copyOwnedEdge(
          v40,
          v54 - v40->m_numOriginalEdges,
          v43->m_startUserEdgeIndex + v54 - v47 - v40->m_numOriginalEdges);
        v56 = v40->m_numOriginalEdges;
        if ( v54 >= v56 )
          break;
        if ( v40->m_edgeMap.m_size )
          v59 = v40->m_edgeMap.m_data[v55];
        else
          v59 = v54;
        if ( v59 != -1 )
        {
          v57 = v59;
          v58 = v40->m_instancedEdges.m_data;
          goto LABEL_68;
        }
        v60 = 0i64;
LABEL_69:
        if ( v60->m_oppositeEdge != -1 )
          reindexOpposite(collectiona, v40, v60, SHIDWORD(index), v54, index);
        ++v54;
        ++v55;
        if ( v54 - v47 >= v43->m_numUserEdges )
          goto LABEL_72;
      }
      v57 = v54 - v56;
      v58 = v40->m_ownedEdges.m_data;
LABEL_68:
      v60 = &v58[v57];
      goto LABEL_69;
    }
LABEL_77:
    v65 = 0;
    if ( *(_DWORD *)(*(_QWORD *)userEdgeKey + 8i64) > 0 )
    {
      v66 = collectiona;
      v67 = 0i64;
      v68 = *(_QWORD *)userEdgeKey;
      do
      {
        v69 = v67 + *(_QWORD *)v68;
        v70 = hkaiStreamingCollection::findSectionIdByUid(v66, *(_DWORD *)(v69 + 48));
        v71 = *(_DWORD *)(v69 + 52);
        v72 = v70;
        v103 = v70;
        v73 = hkaiStreamingCollection::findSectionIdByUid(v66, v71);
        indexa = v73;
        if ( v72 != -1 && v73 != -1 )
        {
          v74 = *(_DWORD *)(v69 + 60);
          v75 = v73 << 22;
          v76 = (unsigned int)(v72 << 22) | *(_DWORD *)(v69 + 56);
          userEdgeKey[0] = v72 << 22;
          v77 = v75 | v74;
          faceKeyA[0] = v76;
          secIdx = v75;
          LODWORD(result) = v77;
          v79 = v76;
          v80 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v100,
                  v76,
                  0xFFFFFFFFFFFFFFFFui64);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v100,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v79,
            v80 + 1);
          v81 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v100,
                  v77,
                  0xFFFFFFFFFFFFFFFFui64);
          v82 = v77;
          v83 = v81;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v100,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v82,
            v81 + 1);
          v84 = collectiona->m_instances.m_data;
          v85 = v80 | userEdgeKey[0];
          v86 = v83 | secIdx;
          v87 = faceKeyA[0];
          v99.m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)v69;
          v88 = v84[indexa].m_instancePtr;
          userEdgeKey[0] = v85;
          setupEdges(
            v84[v103].m_instancePtr,
            v88,
            faceKeyA[0],
            (unsigned int)result,
            v85,
            v86,
            (hkaiUserEdgeUtils::UserEdgePair *)v69);
          if ( retaddr[1] )
          {
            v89 = (*(_BYTE *)(v69 + 76) >> 1) & 1;
            if ( *(_BYTE *)(v69 + 76) & 1 )
              hkaiGraphUtils::addDirectedGraphEdgeForUserEdge(v87, userEdgeKey[0], collectiona);
            v66 = collectiona;
            if ( v89 )
              hkaiGraphUtils::addDirectedGraphEdgeForUserEdge((unsigned int)result, v86, collectiona);
          }
          else
          {
            v66 = collectiona;
          }
        }
        ++v65;
        v67 += 80i64;
      }
      while ( v65 < *(_DWORD *)(v68 + 8) );
      v7 = 0;
    }
    v90 = collectiona;
    if ( !*retaddr )
    {
      v91 = 0;
      if ( collectiona->m_instances.m_size > 0 )
      {
        v92 = 0i64;
        do
        {
          if ( (array[(signed __int64)v91 >> 5] >> (v91 & 0x1F)) & 1 )
          {
            v93 = v90->m_instances.m_data[v92].m_instancePtr;
            if ( v93 )
              hkaiNavMeshInstance::initGlobalClearanceCache(v93);
          }
          ++v91;
          ++v92;
        }
        while ( v91 < v90->m_instances.m_size );
      }
    }
    if ( retaddr[2] )
    {
      v94 = 0i64;
      if ( v90->m_instances.m_size > 0 )
      {
        v95 = 0i64;
        do
        {
          if ( v94 >= 0 )
          {
            v96 = v90->m_instances.m_data[v95].m_clusterGraphInstance;
            if ( v96 )
              hkaiGraphUtils::compactOwnedEdges(v96);
          }
          ++v7;
          ++v94;
          ++v95;
        }
        while ( v7 < v90->m_instances.m_size );
      }
    }
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v102);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v100,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v100);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v99,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v99);
    hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
  }
}

// File Line: 818
// RVA: 0xBD2420
void __fastcall projectPair(hkaiNavMeshInstance *meshInstance, hkVector4f *up, hkArrayBase<int> *magic, hkaiUserEdgeUtils::UserEdgePair *pair, int idx, hkArray<EdgeSplitInfo,hkContainerTempAllocator> *splitsOut, float minOverlap)
{
  hkaiNavMeshInstance *v7; // r14
  hkArrayBase<int> *v8; // r13
  hkVector4f *v9; // r8
  hkVector4f v10; // xmm1
  hkVector4f *v11; // rax
  __m128 v12; // xmm5
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm9
  hkSimdFloat32 *v17; // rax
  __m128 v18; // xmm0
  int v19; // edx
  int *v20; // rax
  signed __int64 index; // rsi
  __m128 v22; // xmm10
  __m128 v23; // xmm9
  __m128 v24; // xmm10
  __m128 v25; // xmm0
  __m128 v26; // xmm9
  __m128 v27; // xmm10
  hkArray<EdgeSplitInfo,hkContainerTempAllocator> *v28; // rbx
  float v29; // xmm13_4
  signed __int64 v30; // r15
  hkaiNavMesh::Face *v31; // rax
  hkArrayBase<hkVector4f> *v32; // r9
  unsigned __int64 v33; // r11
  int v34; // edi
  hkaiNavMeshInstance *v35; // r12
  int v36; // er9
  __m128 v37; // xmm11
  __m128 v38; // xmm7
  __m128 v39; // xmm12
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  float v42; // xmm8_4
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  float v45; // xmm2_4
  float v46; // xmm4_4
  __m128 v47; // xmm1
  float v48; // xmm2_4
  signed __int64 v49; // rax
  __int128 v50; // xmm0
  __m128 array; // [rsp+40h] [rbp-C0h]
  hkVector4f B; // [rsp+50h] [rbp-B0h]
  hkVector4f A; // [rsp+60h] [rbp-A0h]
  hkSimdFloat32 extraRadius; // [rsp+70h] [rbp-90h]
  hkVector4f Bout; // [rsp+80h] [rbp-80h]
  hkVector4f Aout; // [rsp+90h] [rbp-70h]
  hkAabb aabbOut; // [rsp+A0h] [rbp-60h]
  __int128 v58; // [rsp+D0h] [rbp-30h]
  hkVector4f *upa; // [rsp+1A8h] [rbp+A8h]
  hkResult result; // [rsp+1B0h] [rbp+B0h]

  upa = up;
  v7 = meshInstance;
  v8 = magic;
  v9 = up;
  v10.m_quad = (__m128)pair->m_z;
  v11 = &A;
  v12 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 238);
  v13 = _mm_shuffle_ps(v10.m_quad, (__m128)0i64, 238);
  if ( idx )
    v11 = &B;
  v14 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 68);
  v15 = _mm_shuffle_ps(v10.m_quad, (__m128)0i64, 68);
  A.m_quad = _mm_shuffle_ps(v14, v15, 136);
  array = _mm_shuffle_ps(v14, v15, 221);
  B.m_quad = _mm_shuffle_ps(v12, v13, 136);
  v16 = v11->m_quad;
  extraRadius.m_real = _mm_shuffle_ps(v12, v13, 221);
  v17 = (hkSimdFloat32 *)&array;
  if ( idx )
    v17 = &extraRadius;
  v18 = v17->m_real;
  A.m_quad = v16;
  B.m_quad = v18;
  if ( idx )
    v19 = pair->m_faceB;
  else
    v19 = pair->m_faceA;
  v20 = v8->m_data;
  idx = v19;
  index = v20[v19];
  if ( (_DWORD)index != -2 )
  {
    v22 = v16;
    v23 = _mm_max_ps(v16, v18);
    v24 = _mm_min_ps(v22, v18);
    v25 = _mm_mul_ps((__m128)_xmm, v9->m_quad);
    v26 = _mm_add_ps(v23, v25);
    v27 = _mm_sub_ps(v24, v25);
    if ( (signed int)index < v8->m_size )
    {
      v28 = splitsOut;
      v29 = minOverlap;
      v30 = index;
      do
      {
        if ( v8->m_data[v30] != v19 )
          break;
        v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
                v7->m_originalFaces,
                v7->m_numOriginalFaces,
                &v7->m_instancedFaces,
                &v7->m_ownedFaces,
                &v7->m_faceMap,
                index);
        array.m128_u64[0] = v33;
        array.m128_u64[1] = __PAIR__(2147483648, (unsigned int)v33);
        v34 = v31->m_numEdges + 1;
        v35 = (hkaiNavMeshInstance *)v31;
        if ( v34 <= 0 )
        {
          result.m_enum = (signed int)v33;
        }
        else
        {
          v36 = v31->m_numEdges + 1;
          if ( v34 < 0 )
            v36 = v33;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v36, 16);
        }
        array.m128_i32[2] = v34;
        hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v7,
          v35,
          (hkaiNavMesh::Face *)&array,
          v32);
        extraRadius.m_real = 0i64;
        hkaiNavMeshUtils::calcFaceAabb((hkArrayBase<hkVector4f> *)&array, &extraRadius, &aabbOut);
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v27, aabbOut.m_max.m_quad), _mm_cmpleps(aabbOut.m_min.m_quad, v26))) & 7) == 7
          && hkaiPathProjectionUtil::projectSegmentOntoFaceAndClipEdgesWorldUp(
               (hkArrayBase<hkVector4f> *)&array,
               index,
               &A,
               &B,
               upa,
               &Aout,
               &Bout) )
        {
          v37 = Aout.m_quad;
          LODWORD(v58) = index;
          v38 = _mm_sub_ps(B.m_quad, A.m_quad);
          v39 = Bout.m_quad;
          v40 = _mm_mul_ps(v38, A.m_quad);
          v41 = _mm_mul_ps(v38, v38);
          v42 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170));
          v43 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                  _mm_shuffle_ps(v41, v41, 170));
          v44 = _mm_mul_ps(Aout.m_quad, v38);
          v45 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170));
          v44.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v43);
          v46 = (float)((float)(2.0 - (float)(v44.m128_f32[0] * v43.m128_f32[0])) * v44.m128_f32[0])
              * (float)(v45 - v42);
          v47 = _mm_mul_ps(Bout.m_quad, v38);
          aabbOut.m_min.m_quad.m128_f32[0] = v46;
          v48 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170));
          v47.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v43);
          aabbOut.m_min.m_quad.m128_f32[1] = (float)((float)(2.0 - (float)(v47.m128_f32[0] * v43.m128_f32[0]))
                                                   * v47.m128_f32[0])
                                           * (float)(v48 - v42);
          if ( (float)(aabbOut.m_min.m_quad.m128_f32[1] - v46) > v29 )
          {
            if ( v28->m_size == (v28->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v28, 64);
            v49 = (signed __int64)&v28->m_data[(signed __int64)v28->m_size];
            if ( v49 )
            {
              *(hkVector4f *)v49 = aabbOut.m_min;
              v50 = v58;
              *(__m128 *)(v49 + 16) = v37;
              *(__m128 *)(v49 + 32) = v39;
              *(_OWORD *)(v49 + 48) = v50;
            }
            ++v28->m_size;
          }
        }
        array.m128_i32[2] = 0;
        if ( array.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            (void *)array.m128_u64[0],
            16 * array.m128_i32[3]);
        v19 = idx;
        LODWORD(index) = index + 1;
        ++v30;
        array.m128_i32[3] = 2147483648;
        array.m128_u64[0] = 0i64;
      }
      while ( (signed int)index < v8->m_size );
    }
  }
}

// File Line: 872
// RVA: 0xBD28D0
void __fastcall splitPair1(hkaiStreamingCollection *collection, hkVector4f *up, hkaiNavMeshInstance *cutMesh, hkArrayBase<int> *magic, hkaiUserEdgeUtils::UserEdgePair *pair, int idx, float minOverlap, hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs)
{
  __int64 v8; // r15
  hkArrayBase<int> *v9; // rdi
  hkaiNavMeshInstance *v10; // rsi
  hkVector4f *v11; // rbx
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  int v19; // er14
  int v20; // edi
  _DWORD *v21; // rbx
  __m128 *v22; // rax
  __m128 *v23; // r12
  __m128 *v24; // r13
  __m128 *v25; // rcx
  __m128 v26; // xmm10
  __m128 v27; // xmm9
  __int64 v28; // rsi
  char *v29; // rax
  __int128 v30; // xmm0
  __int128 v31; // xmm1
  __int128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm6
  __m128 v38; // xmm1
  __m128 v39; // xmm8
  __m128 v40; // xmm6
  __m128 v41; // xmm7
  __m128 *v42; // rcx
  __int128 v43; // xmm0
  __int128 v44; // xmm1
  char *array; // [rsp+40h] [rbp-B8h]
  int v46; // [rsp+48h] [rbp-B0h]
  int v47; // [rsp+4Ch] [rbp-ACh]
  __m128 v48; // [rsp+50h] [rbp-A8h]
  __m128 v49; // [rsp+60h] [rbp-98h]
  __m128 v50; // [rsp+70h] [rbp-88h]
  __int128 v51; // [rsp+88h] [rbp-70h]
  __int128 v52; // [rsp+98h] [rbp-60h]
  __int128 v53; // [rsp+A8h] [rbp-50h]
  __int128 v54; // [rsp+B8h] [rbp-40h]
  __int128 v55; // [rsp+C8h] [rbp-30h]
  __m128 v56; // [rsp+D8h] [rbp-20h]
  __m128 v57; // [rsp+E8h] [rbp-10h]
  __m128 v58; // [rsp+F8h] [rbp+0h]
  __m128 v59; // [rsp+108h] [rbp+10h]
  __m128 *result; // [rsp+1C8h] [rbp+D0h]

  v8 = (__int64)result;
  v9 = magic;
  v10 = cutMesh;
  v11 = up;
  v12 = result[2];
  v13 = *result;
  v14 = v12;
  v15 = _mm_shuffle_ps(*result, result[1], 238);
  v16 = _mm_shuffle_ps(v12, (__m128)0i64, 238);
  array = 0i64;
  v46 = 0;
  v47 = 2147483648;
  v17 = _mm_shuffle_ps(v13, result[1], 68);
  v18 = _mm_shuffle_ps(v14, (__m128)0i64, 68);
  v58 = _mm_shuffle_ps(v17, v18, 136);
  v59 = _mm_shuffle_ps(v17, v18, 221);
  v56 = _mm_shuffle_ps(v15, v16, 136);
  v57 = _mm_shuffle_ps(v15, v16, 221);
  hkArrayUtil::_reserve(
    (hkResult *)&result,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    &array,
    16,
    64);
  v19 = (signed int)pair;
  projectPair(
    v10,
    v11,
    v9,
    (hkaiUserEdgeUtils::UserEdgePair *)v8,
    (int)pair,
    (hkArray<EdgeSplitInfo,hkContainerTempAllocator> *)&array,
    *(float *)&idx);
  v20 = 0;
  if ( v46 > 0 )
  {
    v21 = *(_DWORD **)&minOverlap;
    v22 = &v56;
    v23 = &v48;
    if ( v19 )
      v22 = &v58;
    v24 = &v50;
    if ( v19 )
      v23 = &v50;
    v25 = (__m128 *)((char *)&v54 + 8);
    v26 = *v22;
    v27 = _mm_sub_ps(v22[1], *v22);
    if ( v19 )
      v24 = &v48;
    if ( v19 )
      v25 = (__m128 *)((char *)&v54 + 12);
    v28 = 0i64;
    result = v25;
    do
    {
      v29 = array;
      v30 = *(_OWORD *)v8;
      v52 = *(_OWORD *)(v8 + 16);
      v31 = *(_OWORD *)(v8 + 48);
      v51 = v30;
      v32 = *(_OWORD *)(v8 + 32);
      v54 = v31;
      v33 = (__m128)(unsigned int)FLOAT_1_0;
      v33.m128_f32[0] = 1.0 - *(float *)&array[v28 + 4];
      v53 = v32;
      v55 = *(_OWORD *)(v8 + 64);
      v34 = *(__m128 *)&array[v28 + 16];
      *v23 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v27), v26);
      v35 = (__m128)(unsigned int)FLOAT_1_0;
      v35.m128_f32[0] = 1.0 - *(float *)&v29[v28];
      v23[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v27), v26);
      v36 = *(__m128 *)&v29[v28 + 32];
      LODWORD(v25->m128_u64[0]) = *(_DWORD *)&v29[v28 + 48];
      LODWORD(v29) = v21[3];
      v24[1] = v36;
      *v24 = v34;
      v37 = _mm_shuffle_ps(v50, *(__m128 *)((char *)&v50 + 8), 68);
      v38 = _mm_shuffle_ps(v48, v49, 68);
      v39 = _mm_shuffle_ps(v37, v38, 136);
      v40 = _mm_shuffle_ps(v37, v38, 221);
      v41 = _mm_shuffle_ps(_mm_shuffle_ps(v50, *(__m128 *)((char *)&v50 + 8), 238), _mm_shuffle_ps(v48, v49, 238), 136);
      if ( v21[2] == ((unsigned int)v29 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v21, 80);
      v42 = (__m128 *)(*(_QWORD *)v21 + 80i64 * (signed int)v21[2]);
      if ( v42 )
      {
        v43 = v54;
        v44 = v55;
        *v42 = v39;
        v42[1] = v40;
        v42[2] = v41;
        v42[3] = (__m128)v43;
        v42[4] = (__m128)v44;
      }
      ++v21[2];
      v25 = result;
      ++v20;
      v28 += 64i64;
    }
    while ( v20 < v46 );
  }
  v46 = 0;
  if ( v47 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      v47 << 6);
}

// File Line: 905
// RVA: 0xBD2C40
void __fastcall splitPair2(hkaiStreamingCollection *collection, hkVector4f *up, hkaiNavMeshInstance *meshInstanceA, hkaiNavMeshInstance *meshInstanceB, hkArrayBase<int> *magicA, hkArrayBase<int> *magicB, hkaiUserEdgeUtils::UserEdgePair *pair, float minOverlapA, float minOverlapB, hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs)
{
  hkArrayBase<int> *v10; // r12
  hkaiNavMeshInstance *v11; // rsi
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  hkaiNavMeshInstance *v16; // rbx
  hkVector4f *v17; // rdi
  hkArrayBase<int> v18; // xmm13
  __m128 v19; // xmm7
  __m128 v20; // xmm13
  __m128 v21; // xmm7
  __m128 v22; // xmm15
  __m128 v23; // xmm13
  __m128 v24; // xmm14
  __m128 v25; // xmm7
  __m128 v26; // xmm15
  __m128 v27; // xmm14
  float v28; // xmm12_4
  float v29; // xmm11_4
  int v30; // eax
  int v31; // er15
  _DWORD *v32; // rdi
  char *v33; // rdx
  __int64 v34; // rsi
  int v35; // er14
  __int64 v36; // rbx
  float v37; // xmm5_4
  float v38; // xmm6_4
  __int128 v39; // xmm1
  int v40; // eax
  hkArrayBase<int> v41; // xmm10
  __int128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm4
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm7
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  __m128 v52; // xmm6
  __m128 v53; // xmm0
  __m128 v54; // xmm9
  __m128 v55; // xmm6
  __m128 v56; // xmm7
  __m128 *v57; // rcx
  __int128 v58; // xmm0
  char *array; // [rsp+48h] [rbp-B0h]
  int v60; // [rsp+50h] [rbp-A8h]
  int v61; // [rsp+54h] [rbp-A4h]
  hkArray<EdgeSplitInfo,hkContainerTempAllocator> splitsOut; // [rsp+58h] [rbp-A0h]
  __m128 v63; // [rsp+70h] [rbp-88h]
  __int128 v64; // [rsp+88h] [rbp-70h]
  __int128 v65; // [rsp+98h] [rbp-60h]
  __int128 v66; // [rsp+A8h] [rbp-50h]
  hkArrayBase<int> *magic; // [rsp+1B8h] [rbp+C0h]

  v10 = magicB;
  v11 = meshInstanceB;
  v12 = (__m128)magicB[2];
  v13 = v12;
  v14 = _mm_shuffle_ps(v12, (__m128)0i64, 238);
  v15 = _mm_shuffle_ps(v13, (__m128)0i64, 68);
  v16 = meshInstanceA;
  v17 = up;
  v18 = *magicB;
  array = 0i64;
  v60 = 0;
  v19 = (__m128)v18;
  v20 = _mm_shuffle_ps((__m128)v18, (__m128)magicB[1], 238);
  v61 = 2147483648;
  v21 = _mm_shuffle_ps(v19, (__m128)magicB[1], 68);
  v22 = v20;
  v23 = _mm_shuffle_ps(v20, v14, 221);
  v24 = v21;
  v25 = _mm_shuffle_ps(v21, v15, 221);
  v26 = _mm_shuffle_ps(v22, v14, 136);
  v27 = _mm_shuffle_ps(v24, v15, 136);
  v63 = v25;
  hkArrayUtil::_reserve(
    (hkResult *)&magicB,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    &array,
    16,
    64);
  splitsOut.m_data = 0i64;
  splitsOut.m_size = 0;
  splitsOut.m_capacityAndFlags = 2147483648;
  hkArrayUtil::_reserve(
    (hkResult *)&magicB,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    &splitsOut,
    16,
    64);
  v28 = *(float *)&pair;
  projectPair(
    v16,
    v17,
    magic,
    (hkaiUserEdgeUtils::UserEdgePair *)v10,
    0,
    (hkArray<EdgeSplitInfo,hkContainerTempAllocator> *)&array,
    *(float *)&pair);
  if ( v60
    && (v29 = minOverlapA,
        projectPair(v11, v17, magicA, (hkaiUserEdgeUtils::UserEdgePair *)v10, 1, &splitsOut, minOverlapA),
        v30 = v60,
        v31 = 0,
        v60 > 0) )
  {
    v32 = *(_DWORD **)&minOverlapB;
    v33 = array;
    v34 = 0i64;
    do
    {
      v35 = 0;
      if ( splitsOut.m_size > 0 )
      {
        v36 = 0i64;
        do
        {
          if ( *(float *)&v33[v34 + 4] > *(float *)&v33[v34] && splitsOut.m_data[v36].m_t1 > splitsOut.m_data[v36].m_t0 )
          {
            *(float *)&magicB = 1.0 - splitsOut.m_data[v36].m_t1;
            v37 = fmaxf(*(float *)&v33[v34], *(float *)&magicB);
            *(float *)&magicB = 1.0 - splitsOut.m_data[v36].m_t0;
            v38 = fminf(*(float *)&v33[v34 + 4], *(float *)&magicB);
            *(float *)&magicB = v28;
            if ( (float)(v38 - v37) > fmaxf(v28, v29) )
            {
              v39 = (__int128)v10[1];
              v40 = *(_DWORD *)&v33[v34 + 48];
              v41 = v10[4];
              *(__m128 *)((char *)&v63 + 8) = *(__m128 *)v10;
              v42 = (__int128)v10[2];
              v64 = v39;
              v43 = (__m128)v10[3];
              v65 = v42;
              v66 = (__int128)v43;
              v44 = (__m128)(unsigned int)FLOAT_1_0;
              v43.m128_f32[0] = v38;
              DWORD2(v66) = v40;
              v44.m128_f32[0] = 1.0 - v38;
              v45 = _mm_sub_ps(v25, v27);
              HIDWORD(v66) = splitsOut.m_data[v36].m_faceIndex;
              v46 = (__m128)(unsigned int)FLOAT_1_0;
              v46.m128_f32[0] = 1.0 - v37;
              v47 = _mm_sub_ps(v23, v26);
              v25.m128_f32[0] = v37;
              v48 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v45), v27);
              v49 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v45), v27);
              v50 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v47), v26);
              v51 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v47), v26);
              v52 = _mm_shuffle_ps(v49, v48, 68);
              v53 = _mm_shuffle_ps(v50, v51, 68);
              v54 = _mm_shuffle_ps(v52, v53, 136);
              v55 = _mm_shuffle_ps(v52, v53, 221);
              v56 = _mm_shuffle_ps(_mm_shuffle_ps(v49, v48, 238), _mm_shuffle_ps(v50, v51, 238), 136);
              if ( v32[2] == (v32[3] & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v32, 80);
                v33 = array;
              }
              v57 = (__m128 *)(*(_QWORD *)v32 + 80i64 * (signed int)v32[2]);
              if ( v57 )
              {
                v58 = v66;
                *v57 = v54;
                v57[1] = v55;
                v57[2] = v56;
                v57[3] = (__m128)v58;
                v57[4] = (__m128)v41;
                v33 = array;
              }
              ++v32[2];
              v25 = v63;
            }
          }
          ++v35;
          ++v36;
        }
        while ( v35 < splitsOut.m_size );
        v30 = v60;
      }
      ++v31;
      v34 += 64i64;
    }
    while ( v31 < v30 );
  }
  else
  {
    v33 = array;
  }
  splitsOut.m_size = 0;
  if ( splitsOut.m_capacityAndFlags >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      splitsOut.m_data,
      splitsOut.m_capacityAndFlags << 6);
    v33 = array;
  }
  splitsOut.m_data = 0i64;
  v60 = 0;
  splitsOut.m_capacityAndFlags = 2147483648;
  if ( v61 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v33,
      v61 << 6);
}

// File Line: 960
// RVA: 0xBD3150
void __usercall splitPairsOnCutMesh(hkaiStreamingCollection *collection@<rcx>, hkaiUserEdgeUtils::UserEdgePair *pair@<rdx>, hkaiNavMeshCutter *cutter@<r8>, int secIdxA@<r9d>, __int128 a5@<xmm8>, int secIdxB, float minEdgeLength, hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs)
{
  hkaiNavMeshCutter *v8; // rsi
  hkaiUserEdgeUtils::UserEdgePair *v9; // rbx
  __int64 v10; // rdx
  hkaiStreamingCollection::InstanceInfo *v11; // r9
  hkaiNavMeshInstance *v12; // rdi
  hkaiNavMeshInstance *v13; // r11
  hkaiNavMeshCutter::MeshInfo *v14; // rax
  hkArrayBase<int> *magicA; // r9
  hkArrayBase<int> *magicB; // rdx
  int v17; // ebp
  int v18; // er8
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm7
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm9
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm9
  __m128 v39; // xmm0
  __m128 minOverlapA; // xmm0
  float minOverlapB; // xmm1_4
  hkaiUserEdgeUtils::UserEdgePair *v42; // rcx
  hkVector4f up; // [rsp+50h] [rbp-58h]
  __int128 v44; // [rsp+70h] [rbp-38h]

  if ( secIdxA != -1 )
  {
    v8 = cutter;
    v9 = pair;
    if ( secIdxB != -1 )
    {
      v10 = secIdxA;
      v11 = collection->m_instances.m_data;
      v12 = v11[v10].m_instancePtr;
      v13 = v11[secIdxB].m_instancePtr;
      if ( v12 )
      {
        if ( v13 )
        {
          v14 = cutter->m_meshInfos.m_data;
          magicA = (hkArrayBase<int> *)&v14[v10].m_magic.m_data;
          magicB = (hkArrayBase<int> *)&v14[secIdxB].m_magic.m_data;
          v17 = magicA->m_data[v9->m_faceA];
          if ( v17 != -2 )
          {
            v18 = magicB->m_data[v9->m_faceB];
            if ( v18 != -2 )
            {
              _mm_store_si128((__m128i *)&up, (__m128i)v8->m_up.m_quad);
              v19 = v9->m_z.m_quad;
              v20 = v19;
              v21 = v9->m_x.m_quad;
              v22 = v21;
              v44 = a5;
              v23 = _mm_shuffle_ps(v21, v9->m_y.m_quad, 238);
              v24 = _mm_shuffle_ps(v22, v9->m_y.m_quad, 68);
              v25 = _mm_shuffle_ps(v19, (__m128)0i64, 238);
              v26 = _mm_shuffle_ps(v20, (__m128)0i64, 68);
              v27 = _mm_sub_ps(_mm_shuffle_ps(v23, v25, 136), _mm_shuffle_ps(v23, v25, 221));
              v28 = _mm_sub_ps(_mm_shuffle_ps(v24, v26, 136), _mm_shuffle_ps(v24, v26, 221));
              v29 = _mm_mul_ps(v27, v27);
              v30 = _mm_mul_ps(v28, v28);
              v31 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                      _mm_shuffle_ps(v30, v30, 170));
              v32 = _mm_rsqrt_ps(v31);
              v33 = _mm_andnot_ps(
                      _mm_cmpleps(v31, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v32), v32)),
                          _mm_mul_ps(*(__m128 *)_xmm, v32)),
                        v31));
              v34 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                      _mm_shuffle_ps(v29, v29, 170));
              v35 = _mm_rsqrt_ps(v34);
              v36 = _mm_andnot_ps(
                      _mm_cmpleps(v34, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v35), v35)),
                          _mm_mul_ps(*(__m128 *)_xmm, v35)),
                        v34));
              v37 = _mm_shuffle_ps((__m128)LODWORD(minEdgeLength), (__m128)LODWORD(minEdgeLength), 0);
              v38 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v36), 196);
              if ( !_mm_movemask_ps(_mm_cmpltps(v38, v37)) )
              {
                v39 = _mm_rcp_ps(v38);
                minOverlapA = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v39)), v39), v37);
                LODWORD(minOverlapB) = (unsigned __int128)_mm_shuffle_ps(minOverlapA, minOverlapA, 255);
                if ( v17 != -1 )
                {
                  if ( v18 != -1 )
                    splitPair2(
                      collection,
                      &up,
                      v12,
                      v13,
                      magicA,
                      magicB,
                      v9,
                      minOverlapA.m128_f32[0],
                      minOverlapB,
                      newPairs);
                  else
                    splitPair1(collection, &up, v12, magicA, v9, 0, minOverlapA.m128_f32[0], newPairs);
                }
                else if ( v18 != -1 )
                {
                  splitPair1(collection, &up, v13, magicB, v9, 1, minOverlapB, newPairs);
                }
                else
                {
                  if ( newPairs->m_size == (newPairs->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      newPairs,
                      80);
                  v42 = &newPairs->m_data[newPairs->m_size];
                  if ( v42 )
                  {
                    v42->m_x = v9->m_x;
                    v42->m_y = v9->m_y;
                    v42->m_z = v9->m_z;
                    *(_OWORD *)&v42->m_instanceUidA = *(_OWORD *)&v9->m_instanceUidA;
                    *(_OWORD *)&v42->m_userDataA = *(_OWORD *)&v9->m_userDataA;
                  }
                  ++newPairs->m_size;
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1053
// RVA: 0xBD1530
void __fastcall hkaiUserEdgeUtils::selectiveAddUserEdgePairsToCutMesh(hkaiStreamingCollection *collection, hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *pairs, hkaiNavMeshCutter *cutter, hkArrayBase<unsigned int> *cutFaceKeys, hkArrayBase<unsigned int> *uncutFaceKeys, hkaiUserEdgeUtils::CutMeshUpdateParameters *params)
{
  hkArrayBase<unsigned int> *v6; // rsi
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v7; // r13
  hkaiStreamingCollection *v8; // r15
  __int64 v9; // r12
  int v10; // er8
  hkArrayBase<unsigned int> *v11; // r14
  int v12; // ebx
  __int64 v13; // rdi
  int v14; // ebx
  __int64 v15; // rdi
  int v16; // ebx
  int v17; // edi
  hkLifoAllocator *v18; // rax
  _DWORD *v19; // rdx
  int v20; // ecx
  char *v21; // r8
  signed int v22; // eax
  int v23; // eax
  int v24; // er9
  __int64 v25; // rcx
  _DWORD *v26; // rdi
  int v27; // er14
  hkaiUserEdgeUtils::UserEdgePair *v28; // rsi
  __int64 v29; // r13
  int v30; // eax
  int v31; // er15
  unsigned int v32; // ebx
  int v33; // edi
  int v34; // eax
  int sizeElem; // ST20_4
  hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> newPairs; // [rsp+40h] [rbp-39h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v37; // [rsp+50h] [rbp-29h]
  _DWORD *array; // [rsp+60h] [rbp-19h]
  int v39; // [rsp+68h] [rbp-11h]
  unsigned int v40; // [rsp+6Ch] [rbp-Dh]
  _DWORD *v41; // [rsp+70h] [rbp-9h]
  int v42; // [rsp+78h] [rbp-1h]
  int v43; // [rsp+80h] [rbp+7h]
  hkaiStreamingCollection *collectiona; // [rsp+D0h] [rbp+57h]
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v45; // [rsp+D8h] [rbp+5Fh]
  hkaiNavMeshCutter *cuttera; // [rsp+E0h] [rbp+67h]

  cuttera = cutter;
  v45 = pairs;
  collectiona = collection;
  v6 = uncutFaceKeys;
  v7 = pairs;
  v8 = collection;
  v9 = 0i64;
  v10 = cutFaceKeys->m_size + uncutFaceKeys->m_size;
  v11 = cutFaceKeys;
  v37.m_elem = 0i64;
  v37.m_numElems = 0;
  v37.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v37,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v10);
  v12 = 0;
  if ( v11->m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v37,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v11->m_data[v13],
        1ui64);
      ++v12;
      ++v13;
    }
    while ( v12 < v11->m_size );
  }
  v14 = 0;
  if ( v6->m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v37,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v6->m_data[v15],
        1ui64);
      ++v14;
      ++v15;
    }
    while ( v14 < v6->m_size );
  }
  v16 = v8->m_instances.m_size;
  array = 0i64;
  v39 = 0;
  v40 = 2147483648;
  v17 = (v16 + 31) >> 5;
  v42 = v17;
  if ( v17 )
  {
    v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = v18->m_cur;
    v20 = (4 * v17 + 127) & 0xFFFFFF80;
    v21 = (char *)v19 + v20;
    if ( v20 > v18->m_slabSize || v21 > v18->m_end )
      v19 = hkLifoAllocator::allocateFromNewSlab(v18, v20);
    else
      v18->m_cur = v21;
  }
  else
  {
    v19 = 0i64;
  }
  array = v19;
  v41 = v19;
  v43 = v16;
  v40 = v17 | 0x80000000;
  v22 = (v17 | 0x80000000) & 0x3FFFFFFF;
  if ( v22 < v17 )
  {
    v23 = 2 * v22;
    v24 = (v16 + 31) >> 5;
    if ( v17 < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(
      (hkResult *)&uncutFaceKeys,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v24,
      4);
    v19 = array;
  }
  v39 = (v16 + 31) >> 5;
  if ( v17 - 1 >= 0 )
  {
    v25 = (unsigned int)v17;
    v26 = v19;
    while ( v25 )
    {
      *v26 = 0;
      ++v26;
      --v25;
    }
  }
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  newPairs.m_capacityAndFlags = 2147483648;
  v27 = 0;
  if ( v7->m_size > 0 )
  {
    do
    {
      v28 = (hkaiUserEdgeUtils::UserEdgePair *)((char *)v7->m_data + v9);
      v29 = (signed int)hkaiStreamingCollection::findSectionIdByUid(v8, v28->m_instanceUidA);
      v30 = hkaiStreamingCollection::findSectionIdByUid(v8, v28->m_instanceUidB);
      v31 = v30;
      if ( (_DWORD)v29 != -1
        && v30 != -1
        && ((array[v29 >> 5] |= 1 << (v29 & 0x1F),
             array[(signed __int64)v30 >> 5] |= 1 << (v30 & 0x1F),
             v32 = (v30 << 22) | v28->m_faceB,
             v33 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                     &v37,
                     (unsigned int)(((_DWORD)v29 << 22) | v28->m_faceA),
                     0i64),
             v34 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                     &v37,
                     v32,
                     0i64),
             v33)
         || v34) )
      {
        sizeElem = v31;
        v8 = collectiona;
        splitPairsOnCutMesh(collectiona, v28, cuttera, v29, sizeElem, params->m_minEdgeLength, &newPairs);
      }
      else
      {
        v8 = collectiona;
      }
      v7 = v45;
      ++v27;
      v9 += 80i64;
    }
    while ( v27 < v45->m_size );
    LODWORD(v9) = 0;
  }
  hkaiUserEdgeUtils::addUserEdgePairsBatch(
    v8,
    (hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *)&newPairs.m_data,
    (hkaiUserEdgeUtils::UpdateParameters *)&params->m_clearanceResetMode);
  newPairs.m_size = v9;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      80 * (newPairs.m_capacityAndFlags & 0x3FFFFFFF));
  newPairs.m_data = 0i64;
  newPairs.m_capacityAndFlags = 2147483648;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v37,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v37);
}

// File Line: 1108
// RVA: 0xBD12D0
void __usercall hkaiUserEdgeUtils::addUserEdgePairsToCutMesh(hkaiStreamingCollection *collection@<rcx>, hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *pairs@<rdx>, hkaiNavMeshCutter *cutter@<r8>, hkaiUserEdgeUtils::CutMeshUpdateParameters *params@<r9>, hkaiUserEdgeUtils::UpdateParameters *a5@<rbx>)
{
  int v5; // ebx
  __int64 v6; // rsi
  int v7; // edi
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v8; // r12
  hkaiStreamingCollection *v9; // r15
  hkLifoAllocator *v10; // rax
  _DWORD *v11; // rdx
  int v12; // ecx
  char *v13; // r8
  signed int v14; // eax
  int v15; // eax
  int v16; // er9
  __int64 v17; // rcx
  _DWORD *v18; // rdi
  int v19; // ebx
  hkaiUserEdgeUtils::UserEdgePair *v20; // r14
  __int64 v21; // r13
  __int64 v22; // r10
  hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs; // [rsp+30h] [rbp-19h]
  int v24; // [rsp+38h] [rbp-11h]
  int v25; // [rsp+3Ch] [rbp-Dh]
  _DWORD *array; // [rsp+40h] [rbp-9h]
  int v27; // [rsp+48h] [rbp-1h]
  unsigned int v28; // [rsp+4Ch] [rbp+3h]
  _DWORD *v29; // [rsp+50h] [rbp+7h]
  int v30; // [rsp+58h] [rbp+Fh]
  int v31; // [rsp+60h] [rbp+17h]
  hkResult result; // [rsp+B0h] [rbp+67h]
  hkaiNavMeshCutter *cuttera; // [rsp+C0h] [rbp+77h]
  hkaiUserEdgeUtils::UpdateParameters *paramsa; // [rsp+C8h] [rbp+7Fh]

  paramsa = a5;
  v5 = collection->m_instances.m_size;
  v6 = 0i64;
  v7 = (v5 + 31) >> 5;
  v8 = pairs;
  array = 0i64;
  v27 = 0;
  v28 = 2147483648;
  v9 = collection;
  v30 = v7;
  if ( v7 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = v10->m_cur;
    v12 = (4 * v7 + 127) & 0xFFFFFF80;
    v13 = (char *)v11 + v12;
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
      v11 = hkLifoAllocator::allocateFromNewSlab(v10, v12);
    else
      v10->m_cur = v13;
  }
  else
  {
    v11 = 0i64;
  }
  array = v11;
  v29 = v11;
  v31 = v5;
  v28 = v7 | 0x80000000;
  v14 = (v7 | 0x80000000) & 0x3FFFFFFF;
  if ( v14 < v7 )
  {
    v15 = 2 * v14;
    v16 = (v5 + 31) >> 5;
    if ( v7 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v16, 4);
    v11 = array;
  }
  v27 = (v5 + 31) >> 5;
  if ( v7 - 1 >= 0 )
  {
    v17 = (unsigned int)v7;
    v18 = v11;
    while ( v17 )
    {
      *v18 = 0;
      ++v18;
      --v17;
    }
  }
  v19 = 0;
  newPairs = 0i64;
  v24 = 0;
  v25 = 2147483648;
  if ( v8->m_size > 0 )
  {
    do
    {
      v20 = (hkaiUserEdgeUtils::UserEdgePair *)((char *)v8->m_data + v6);
      v21 = (signed int)hkaiStreamingCollection::findSectionIdByUid(v9, v20->m_instanceUidA);
      v22 = (signed int)hkaiStreamingCollection::findSectionIdByUid(v9, v20->m_instanceUidB);
      if ( (_DWORD)v21 != -1 && (_DWORD)v22 != -1 )
      {
        newPairs = (hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *)&newPairs;
        array[v21 >> 5] |= 1 << (v21 & 0x1F);
        array[v22 >> 5] |= 1 << (v22 & 0x1F);
        splitPairsOnCutMesh(v9, v20, cuttera, v21, v22, *(float *)&paramsa[1].m_updateHierarchyGraphs.m_bool, newPairs);
      }
      ++v19;
      v6 += 80i64;
    }
    while ( v19 < v8->m_size );
    LODWORD(v6) = 0;
  }
  hkaiUserEdgeUtils::addUserEdgePairsBatch(v9, (hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *)&newPairs, paramsa);
  v24 = v6;
  if ( v25 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newPairs,
      80 * (v25 & 0x3FFFFFFF));
  newPairs = 0i64;
  v25 = 2147483648;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
}

// File Line: 1143
// RVA: 0xBD1880
void __fastcall hkaiUserEdgeUtils::removeUserEdges(hkaiNavMeshInstance *meshInstance, hkaiStreamingCollection *collection)
{
  hkaiNavMeshInstance *v2; // rdi
  hkaiStreamingCollection *v3; // r15
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  int v9; // ebx
  int v10; // ebp
  int index; // er11
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v12; // r8
  __int64 v13; // r14
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v14; // r9
  int v15; // er11
  signed __int64 v16; // rax
  int v17; // ecx
  int v18; // ecx
  _QWORD *v19; // rax
  _QWORD *v20; // rcx
  _QWORD *v21; // r8
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+30h] [rbp-28h]

  v2 = meshInstance;
  v3 = collection;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtremoveUserEdges";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = v2->m_numOriginalFaces;
  v10 = 0;
  index = 0;
  if ( v9 + v2->m_ownedFaces.m_size > 0 )
  {
    v12 = &v2->m_instancedFaces;
    v13 = 0i64;
    v14 = &v2->m_ownedFaces;
    do
    {
      if ( hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(v2->m_originalFaces, v9, v12, v14, &v2->m_faceMap, index)->m_numUserEdges > 0 )
      {
        if ( v15 < v9 )
        {
          if ( v2->m_faceMap.m_size )
            v17 = v2->m_faceMap.m_data[v13];
          else
            v17 = v15;
          if ( v17 == -1 )
            v16 = 0i64;
          else
            v16 = (signed __int64)&v12->m_data[v17];
        }
        else
        {
          v16 = (signed __int64)&v14->m_data[v15 - v9];
        }
        v18 = *(signed __int16 *)(v16 + 10);
        *(_DWORD *)(v16 + 4) = -1;
        *(_WORD *)(v16 + 10) = 0;
        v10 += v18;
      }
      v9 = v2->m_numOriginalFaces;
      index = v15 + 1;
      ++v13;
    }
    while ( index < v9 + v2->m_ownedFaces.m_size );
    if ( v10 > 0 )
    {
      facesToRemove.m_data = 0i64;
      facesToRemove.m_size = 0;
      facesToRemove.m_capacityAndFlags = 2147483648;
      hkaiNavMeshUtils::removeOwnedFaces(v2, v3, &facesToRemove, 0);
      facesToRemove.m_size = 0;
      if ( facesToRemove.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          facesToRemove.m_data,
          4 * facesToRemove.m_capacityAndFlags);
    }
  }
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  v21 = v19;
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v22 = __rdtsc();
    v23 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v21[1] = v23;
  }
}

// File Line: 1169
// RVA: 0xBD1B50
__int64 __fastcall hkaiUserEdgeUtils::removeUserEdgesFromFace(hkaiStreamingCollection *collection, unsigned int faceKey, hkaiUserEdgeUtils::RemoveParameters *params)
{
  hkaiNavMeshInstance *v3; // r14
  int v5; // edi
  hkaiNavMesh::Face *v6; // rax
  _QWORD *v7; // r8
  _QWORD *v8; // r9
  int v9; // er11
  unsigned int v10; // edx
  signed __int64 v11; // r13
  signed int v12; // er12
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v14; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r10
  unsigned int v16; // ebx
  int index; // ST28_4
  int v18; // er15
  hkaiNavMesh::Edge *v19; // rsi
  unsigned int v20; // eax
  char v21; // dl
  unsigned int v22; // ecx
  int v23; // ebp
  bool v24; // zf
  unsigned int v25; // eax
  int v26; // edi
  hkaiUserEdgeUtils::RemoveParameters *v27; // rax
  unsigned int v28; // edx
  signed int v29; // eax
  int v30; // edx
  hkaiNavMeshInstance *v31; // r8
  int v32; // eax
  signed __int64 v33; // rcx
  hkaiNavMesh::Edge *v34; // rax
  signed __int64 v35; // rdx
  hkaiNavMesh::Face *v36; // [rsp+38h] [rbp-50h]
  hkaiStreamingCollection *collectiona; // [rsp+90h] [rbp+8h]
  unsigned int startFaceKey; // [rsp+98h] [rbp+10h]
  hkaiUserEdgeUtils::RemoveParameters *v39; // [rsp+A0h] [rbp+18h]
  unsigned int v40; // [rsp+A8h] [rbp+20h]

  v39 = params;
  startFaceKey = faceKey;
  collectiona = collection;
  v3 = collection->m_instances.m_data[faceKey >> 22].m_instancePtr;
  if ( !v3 )
    return 0i64;
  v5 = v3->m_numOriginalFaces;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
         v3->m_originalFaces,
         v3->m_numOriginalFaces,
         &v3->m_instancedFaces,
         &v3->m_ownedFaces,
         &v3->m_faceMap,
         faceKey & 0x3FFFFF);
  v36 = v6;
  v10 = v6->m_numUserEdges;
  v40 = v6->m_numUserEdges;
  if ( v6->m_numUserEdges > 0 )
  {
    if ( v9 < v5 )
    {
      if ( v3->m_faceMap.m_size )
        v9 = v3->m_faceMap.m_data[v9];
      if ( v9 == -1 )
        v11 = 0i64;
      else
        v11 = *v7 + 16i64 * v9;
    }
    else
    {
      v11 = *v8 + 16i64 * (v9 - v5);
    }
    v12 = 0;
    if ( (signed int)v10 > 0 )
    {
      instanceMap = &v3->m_edgeMap;
      v14 = &v3->m_ownedEdges;
      v15 = &v3->m_instancedEdges;
      while ( 1 )
      {
        v16 = v3->m_runtimeId << 22;
        index = v12 + v6->m_startUserEdgeIndex;
        v18 = index | v16;
        v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__4(
                v3->m_originalEdges,
                v3->m_numOriginalEdges,
                v15,
                v14,
                instanceMap,
                index);
        v20 = v19->m_oppositeFace;
        v21 = v19->m_flags.m_storage & 0x40;
        if ( v21 )
          v22 = v20 & 0xFFC00000;
        else
          v22 = v16;
        v23 = v22 | v20 & 0x3FFFFF;
        v24 = v20 == -1;
        v25 = v19->m_oppositeEdge;
        if ( v24 )
          v23 = -1;
        if ( v21 )
          v16 = v25 & 0xFFC00000;
        v26 = v16 | v25 & 0x3FFFFF;
        v24 = v25 == -1;
        v27 = v39;
        if ( v24 )
          v26 = -1;
        if ( v39->m_updateHierarchyGraphs.m_bool )
        {
          hkaiGraphUtils::removeDirectedGraphEdgeForUserEdge(startFaceKey, v18, collectiona);
          v27 = v39;
        }
        if ( v19->m_oppositeEdge == -1 )
          goto LABEL_41;
        if ( v27->m_updateHierarchyGraphs.m_bool )
          hkaiGraphUtils::removeDirectedGraphEdgeForUserEdge(v23, v26, collectiona);
        v28 = v19->m_oppositeEdge;
        if ( v19->m_flags.m_storage & 0x40 )
          v29 = v28 >> 22;
        else
          v29 = v3->m_runtimeId;
        if ( v28 == -1 )
          v29 = -1;
        v30 = v28 & 0x3FFFFF;
        v31 = collectiona->m_instances.m_data[v29].m_instancePtr;
        v32 = v31->m_numOriginalEdges;
        if ( v30 >= v32 )
          break;
        if ( v31->m_edgeMap.m_size )
          v30 = v31->m_edgeMap.m_data[v30];
        if ( v30 != -1 )
        {
          v33 = v30;
          v34 = v31->m_instancedEdges.m_data;
          goto LABEL_39;
        }
        v35 = 0i64;
LABEL_40:
        *(_DWORD *)(v35 + 12) = -1;
        *(_DWORD *)(v35 + 8) = -1;
LABEL_41:
        v6 = v36;
        ++v12;
        instanceMap = &v3->m_edgeMap;
        v14 = &v3->m_ownedEdges;
        v15 = &v3->m_instancedEdges;
        if ( v12 >= v36->m_numUserEdges )
        {
          v10 = v40;
          goto LABEL_43;
        }
      }
      v33 = v30 - v32;
      v34 = v31->m_ownedEdges.m_data;
LABEL_39:
      v35 = (signed __int64)&v34[v33];
      goto LABEL_40;
    }
LABEL_43:
    *(_DWORD *)(v11 + 4) = -1;
    *(_WORD *)(v11 + 10) = 0;
  }
  return v10;
}

// File Line: 1224
// RVA: 0xBD1A60
__int64 __fastcall hkaiUserEdgeUtils::removeUserEdgesFromFaces(hkaiStreamingCollection *collection, hkArrayBase<unsigned int> *faceKeys, hkaiUserEdgeUtils::RemoveParameters *params)
{
  hkaiStreamingCollection *v3; // r15
  hkaiUserEdgeUtils::RemoveParameters *v4; // rbp
  hkArrayBase<unsigned int> *v5; // r14
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  unsigned int v11; // ebx
  int v12; // edi
  __int64 v13; // rsi
  int v14; // eax
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx

  v3 = collection;
  v4 = params;
  v5 = faceKeys;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtremoveUserEdgesFromFaces";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = 0;
  v12 = 0;
  if ( v5->m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = hkaiUserEdgeUtils::removeUserEdgesFromFace(v3, v5->m_data[v13], v4);
      ++v12;
      ++v13;
      v11 += v14;
    }
    while ( v12 < v5->m_size );
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v17[1] = v19;
  }
  return v11;
}

