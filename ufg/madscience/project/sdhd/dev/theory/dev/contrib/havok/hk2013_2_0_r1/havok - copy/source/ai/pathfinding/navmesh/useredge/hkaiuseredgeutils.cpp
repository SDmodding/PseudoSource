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
hkSimdFloat32 *__fastcall getMidpointDistance(
        hkSimdFloat32 *result,
        hkVector4f *A1,
        hkVector4f *A2,
        hkVector4f *B1,
        hkVector4f *B2)
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
                     _mm_cmple_ps(v8, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v9), v9)),
                         _mm_mul_ps(*(__m128 *)_xmm, v9)),
                       v8));
  return v5;
}

// File Line: 92
// RVA: 0xBCF3E0
void __fastcall hkaiUserEdgeUtils::Obb::getUpAndHorizontalSegments(
        hkaiUserEdgeUtils::Obb *this,
        hkVector4f *up,
        hkVector4f *upOutStart,
        hkVector4f *upOutEnd,
        hkVector4f *horizOutStart,
        hkVector4f *horizOutEnd)
{
  __m128 si128; // xmm4
  __m128 v11; // xmm3
  __int64 v12; // rdx
  __m128 v13; // xmm3
  int v14; // ebx
  __m128 m_quad; // xmm6
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
  hkVector4f v27; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f v28; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f segOutA; // [rsp+40h] [rbp-68h] BYREF
  hkVector4f segOutB; // [rsp+50h] [rbp-58h] BYREF

  si128 = (__m128)_mm_load_si128((const __m128i *)&this->m_halfExtents);
  v11 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)si128, 1u), 1u);
  v27.m_quad = si128;
  v12 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
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
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v13, v13, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v13, v13, 85),
                                                                       _mm_shuffle_ps(v13, v13, 0))),
                                                                   v13),
                                                                 (__m128)xmmword_141A5C410))];
  hkaiUserEdgeUtils::Obb::_getSegmentForAxis(this, v12, &segOutA, &segOutB);
  hkaiUserEdgeUtils::Obb::_getSegmentForAxis(this, v14, &v27, &v28);
  m_quad = v27.m_quad;
  v16 = v28.m_quad;
  v17 = segOutB.m_quad;
  v18 = _mm_sub_ps(v27.m_quad, v28.m_quad);
  v19 = _mm_mul_ps(up->m_quad, v18);
  v20 = _mm_sub_ps(segOutA.m_quad, segOutB.m_quad);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v22 = _mm_mul_ps(up->m_quad, v20);
  v23 = _mm_sub_ps(v18, _mm_mul_ps(v21, up->m_quad));
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_sub_ps(
          v20,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170)),
            up->m_quad));
  v26 = _mm_mul_ps(v25, v25);
  if ( (float)((float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0] + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
             + _mm_shuffle_ps(v24, v24, 170).m128_f32[0]) <= (float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0]
                                                                           + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
                                                                   + _mm_shuffle_ps(v26, v26, 170).m128_f32[0]) )
  {
    *horizOutStart = (hkVector4f)segOutA.m_quad;
    *horizOutEnd = (hkVector4f)v17;
    *upOutStart = (hkVector4f)m_quad;
    *upOutEnd = (hkVector4f)v16;
  }
  else
  {
    *upOutStart = (hkVector4f)segOutA.m_quad;
    *upOutEnd = (hkVector4f)v17;
    *horizOutStart = (hkVector4f)m_quad;
    *horizOutEnd = (hkVector4f)v16;
  }
}

// File Line: 137
// RVA: 0xBCF600
void __fastcall hkaiUserEdgeUtils::Obb::_getSegmentForAxis(
        hkaiUserEdgeUtils::Obb *this,
        int i,
        hkVector4f *segOutA,
        hkVector4f *segOutB)
{
  int v5; // xmm1_4
  hkVector4f b; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f v8; // [rsp+30h] [rbp-18h] BYREF

  v5 = this->m_halfExtents.m_quad.m128_i32[i];
  b.m_quad = 0i64;
  v8.m_quad = 0i64;
  v8.m_quad.m128_i32[i] = v5;
  b.m_quad.m128_i32[i] = v5 ^ _xmm[0];
  hkVector4f::setTransformedPos(segOutA, &this->m_transform, &b);
  hkVector4f::setTransformedPos(segOutB, &this->m_transform, &v8);
}

// File Line: 146
// RVA: 0xBCF220
void __fastcall hkaiUserEdgeUtils::Obb::setFromLineSegment(
        hkaiUserEdgeUtils::Obb *this,
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *verticalHalfExtent)
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
         _mm_cmple_ps(v7, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)));
  v10.m_quad = _mm_mul_ps(v4, v9);
  v11 = _mm_mul_ps(v9, v7);
  v12 = _mm_mul_ps(verticalHalfExtent->m_quad, verticalHalfExtent->m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_andnot_ps(
          _mm_cmple_ps(v13, (__m128)0i64),
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
                                                   _mm_cmple_ps(v20, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v21))),
                                                 v18);
  this->m_transform.m_translation = (hkVector4f)v6.m_quad;
  this->m_halfExtents.m_quad = _mm_unpacklo_ps(
                                 _mm_unpacklo_ps(_mm_mul_ps(v11, (__m128)xmmword_141A711B0), (__m128)0x34000000u),
                                 _mm_unpacklo_ps(_mm_mul_ps(v15, v13), (__m128)0i64));
}

// File Line: 164
// RVA: 0xBCF710
void __fastcall hkaiUserEdgeUtils::UserEdgeSetup::setFromLineSegments(
        hkaiUserEdgeUtils::UserEdgeSetup *this,
        hkVector4f *A1,
        hkVector4f *A2,
        hkVector4f *B1,
        hkVector4f *B2,
        hkVector4f *verticalHalfExtent)
{
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  hkVector4f v11; // xmm5

  hkaiUserEdgeUtils::Obb::setFromLineSegment(&this->m_obbA, A1, A2, verticalHalfExtent);
  hkaiUserEdgeUtils::Obb::setFromLineSegment(&this->m_obbB, B1, B2, verticalHalfExtent);
  v8 = _mm_mul_ps(verticalHalfExtent->m_quad, verticalHalfExtent->m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11.m_quad = _mm_mul_ps(
                 verticalHalfExtent->m_quad,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v9, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                     _mm_mul_ps(*(__m128 *)_xmm, v10))));
  this->m_worldUpA = (hkVector4f)v11.m_quad;
  this->m_worldUpB = (hkVector4f)v11.m_quad;
}

// File Line: 173
// RVA: 0xBCF7F0
void __fastcall hkaiUserEdgeUtils::createUserEdgePairs(
        hkaiUserEdgeUtils::UserEdgeSetup *input,
        hkaiNavMeshInstance *meshInstance,
        hkaiNavMeshQueryMediator *mediator,
        hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *userEdgePairsOut,
        float minEdgeLength)
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
void __fastcall hkaiUserEdgeUtils::createUserEdgePairs(
        hkaiUserEdgeUtils::UserEdgeSetup *input,
        hkaiNavMeshInstance *meshA,
        hkaiNavMeshInstance *meshB,
        hkaiNavMeshInstance *mediatorA,
        hkaiNavMeshQueryMediator *mediatorB,
        hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *userEdgePairsOut,
        float minEdgeLength)
{
  hkVector4f v7; // xmm1
  hkaiNavMeshInstance *v8; // r13
  hkaiNavMeshInstance *v9; // r12
  __m128 v11; // xmm8
  __m128 v12; // xmm11
  int v13; // esi
  hkVector4f *horizOutStart; // r14
  hkVector4f *p_upOutStart; // r15
  hkaiUserEdgeUtils::UserEdgeSetup *p_m_obbB; // rax
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
  int v45; // edi
  hkaiNavMeshInstance *v46; // rcx
  hkVector4f *p_A1; // rax
  void **v48; // rbx
  unsigned __int64 v49; // r14
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  hkVector4f *p_A2; // rax
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 *v55; // rax
  hkVector4f *v56; // rax
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  hkBaseObjectVtbl *vfptr; // rax
  int v60; // r12d
  hkArray<int,hkContainerHeapAllocator> *v61; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v62; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v63; // r8
  __int64 v64; // r15
  int v65; // esi
  hkaiNavMesh::Face *v66; // rax
  hkArrayBase<hkVector4f> *v67; // r9
  hkVector4f *v68; // r11
  hkaiNavMeshInstance *v69; // r13
  int v70; // edi
  __m128 v71; // xmm8
  __m128 v72; // xmm9
  __m128 v73; // xmm6
  __m128 v74; // xmm1
  __m128 v75; // xmm5
  float v76; // xmm7_4
  __m128 v77; // xmm3
  __m128 v78; // xmm1
  float v79; // xmm2_4
  float v80; // xmm4_4
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __int64 v83; // rax
  __int128 v84; // xmm0
  __m128 m_real; // xmm15
  int v86; // ecx
  __int64 v87; // rdi
  int v88; // edx
  int v89; // eax
  __m128 v90; // xmm2
  __int64 v91; // r12
  int v92; // esi
  __m128 v93; // xmm3
  char *v94; // r15
  char *v95; // r14
  __m128 v96; // xmm6
  __m128 v97; // xmm14
  __m128 v98; // xmm8
  __m128 v99; // xmm7
  __m128 v100; // xmm10
  __m128 v101; // xmm9
  __m128 v102; // xmm3
  __m128 v103; // xmm8
  __m128 v104; // xmm6
  __m128 v105; // xmm4
  __m128 v106; // xmm13
  __m128 v107; // xmm2
  __m128 v108; // xmm4
  __m128 v109; // xmm1
  __m128 v110; // xmm12
  __m128 v111; // xmm13
  __m128 v112; // xmm3
  __m128 v113; // xmm2
  __m128 v114; // xmm11
  __m128 v115; // xmm5
  __m128 v116; // xmm10
  __m128 v117; // xmm14
  __m128 v118; // xmm5
  __m128 v119; // xmm6
  __m128 v120; // xmm0
  __m128 v121; // xmm1
  __m128 v122; // xmm0
  __m128 v123; // xmm14
  float v124; // xmm1_4
  __m128 v125; // xmm7
  __m128 v126; // xmm6
  float v127; // xmm0_4
  hkBaseObjectVtbl *v128; // rcx
  hkBaseObjectVtbl v129; // xmm0
  hkBaseObjectVtbl v130; // xmm1
  int v131; // [rsp+40h] [rbp-B8h]
  float v132; // [rsp+40h] [rbp-B8h]
  hkResult result; // [rsp+44h] [rbp-B4h] BYREF
  char *v134; // [rsp+48h] [rbp-B0h] BYREF
  int v135; // [rsp+50h] [rbp-A8h]
  int v136; // [rsp+54h] [rbp-A4h]
  hkArrayBase<hkVector4f> array; // [rsp+58h] [rbp-A0h] BYREF
  void *v138; // [rsp+68h] [rbp-90h] BYREF
  int v139; // [rsp+70h] [rbp-88h]
  int v140; // [rsp+74h] [rbp-84h]
  char *v141; // [rsp+78h] [rbp-80h] BYREF
  hkVector4f Bout; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f B1; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f B2; // [rsp+A8h] [rbp-50h] BYREF
  hkVector4f A1; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f A2; // [rsp+C8h] [rbp-30h] BYREF
  hkaiUserEdgeUtils::UserEdgePair v147; // [rsp+D8h] [rbp-20h] BYREF
  float *v148; // [rsp+128h] [rbp+30h]
  __m128 v149; // [rsp+138h] [rbp+40h] BYREF
  __m128 v150; // [rsp+148h] [rbp+50h] BYREF
  hkVector4f *up; // [rsp+158h] [rbp+60h]
  hkaiUserEdgeUtils::Obb bTc; // [rsp+168h] [rbp+70h] BYREF
  hkVector4f A; // [rsp+1B8h] [rbp+C0h] BYREF
  hkVector4f B; // [rsp+1C8h] [rbp+D0h] BYREF
  __m128 m_quad; // [rsp+1D8h] [rbp+E0h] BYREF
  __m128 v156; // [rsp+1E8h] [rbp+F0h]
  hkVector4f Aout; // [rsp+1F8h] [rbp+100h] BYREF
  hkTransformf v158; // [rsp+208h] [rbp+110h] BYREF
  hkTransformf v159; // [rsp+248h] [rbp+150h] BYREF
  char v160[32]; // [rsp+288h] [rbp+190h] BYREF
  hkVector4f upOutStart; // [rsp+2A8h] [rbp+1B0h] BYREF
  void *retaddr; // [rsp+3B8h] [rbp+2C0h]
  int v165; // [rsp+3C8h] [rbp+2D0h]

  v7.m_quad = (__m128)input->m_worldUpB;
  m_quad = input->m_worldUpA.m_quad;
  v156 = v7.m_quad;
  v8 = meshB;
  v9 = meshA;
  v136 = 0x80000000;
  v11 = _mm_shuffle_ps((__m128)(unsigned int)userEdgePairsOut, (__m128)(unsigned int)userEdgePairsOut, 0);
  v12 = (__m128)_xmm;
  v149 = 0i64;
  v150 = 0i64;
  v141 = 0i64;
  v134 = 0i64;
  v135 = 0;
  v13 = 0;
  do
  {
    horizOutStart = &A1;
    if ( v13 )
      horizOutStart = &B1;
    p_upOutStart = (hkVector4f *)v160;
    if ( v13 )
      p_upOutStart = &upOutStart;
    p_m_obbB = input;
    if ( v13 )
      p_m_obbB = (hkaiUserEdgeUtils::UserEdgeSetup *)&input->m_obbB;
    v17 = input->m_space.m_storage == 1;
    v18.m_quad = (__m128)p_m_obbB->m_obbA.m_transform.m_rotation.m_col1;
    bTc.m_transform.m_rotation.m_col0 = p_m_obbB->m_obbA.m_transform.m_rotation.m_col0;
    v19.m_quad = (__m128)p_m_obbB->m_obbA.m_transform.m_rotation.m_col2;
    bTc.m_transform.m_rotation.m_col1 = (hkVector4f)v18.m_quad;
    v20.m_quad = (__m128)p_m_obbB->m_obbA.m_transform.m_translation;
    bTc.m_transform.m_rotation.m_col2 = (hkVector4f)v19.m_quad;
    bTc.m_halfExtents = p_m_obbB->m_obbA.m_halfExtents;
    bTc.m_transform.m_translation = (hkVector4f)v20.m_quad;
    if ( v17 )
    {
      v21 = v8;
      if ( !v13 )
        v21 = v9;
      hkTransformf::setMul((hkTransformf *)&v147, &v21->m_referenceFrame.m_transform, &bTc.m_transform);
      bTc.m_transform.m_rotation.m_col0 = v147.m_x;
      bTc.m_transform.m_rotation.m_col1 = v147.m_y;
      bTc.m_transform.m_rotation.m_col2 = v147.m_z;
      bTc.m_transform.m_translation = *(hkVector4f *)&v147.m_instanceUidA;
    }
    hkaiUserEdgeUtils::Obb::getUpAndHorizontalSegments(
      &bTc,
      (hkVector4f *)&m_quad + v13,
      p_upOutStart,
      p_upOutStart + 1,
      horizOutStart,
      horizOutStart + 1);
    v22 = &v149;
    v23 = _mm_sub_ps(horizOutStart->m_quad, horizOutStart[1].m_quad);
    if ( v13 )
      v22 = &v150;
    ++v13;
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_rsqrt_ps(v25);
    v27 = _mm_andnot_ps(
            _mm_cmple_ps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(v26, *(__m128 *)_xmm)),
              v25));
    v28 = _mm_rcp_ps(v27);
    *v22 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v27)), v28), v11);
  }
  while ( v13 < 2 );
  if ( input->m_forceAlign.m_bool )
  {
    v29 = _mm_mul_ps(v156, m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
               + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) >= 0.0 )
      v30 = *(float *)&FLOAT_1_0;
    else
      v30 = FLOAT_N1_0;
    v31 = A2.m_quad;
    v32 = B2.m_quad;
    v25.m128_f32[0] = v30;
    v33 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v156), m_quad);
    v34 = _mm_mul_ps(v33, v33);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v36 = _mm_rsqrt_ps(v35);
    v37 = _mm_mul_ps(
            v33,
            _mm_andnot_ps(
              _mm_cmple_ps(v35, (__m128)0i64),
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
    if ( (float)((float)(_mm_shuffle_ps(v43, v43, 85).m128_f32[0] + _mm_shuffle_ps(v43, v43, 0).m128_f32[0])
               + _mm_shuffle_ps(v43, v43, 170).m128_f32[0]) < 0.0 )
    {
      A2.m_quad = A1.m_quad;
      A1.m_quad = v31;
    }
    v44 = _mm_mul_ps(v42, v38);
    if ( (float)((float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0] + _mm_shuffle_ps(v44, v44, 0).m128_f32[0])
               + _mm_shuffle_ps(v44, v44, 170).m128_f32[0]) > 0.0 )
    {
      B2.m_quad = B1.m_quad;
      B1.m_quad = v32;
    }
  }
  v45 = 0;
  v131 = 0;
  do
  {
    v46 = mediatorA;
    if ( !v45 )
      v46 = meshB;
    p_A1 = &A1;
    v48 = (void **)&v141;
    if ( v45 )
      p_A1 = &B1;
    v49 = (unsigned __int64)v8;
    if ( !v45 )
      v49 = (unsigned __int64)v9;
    v138 = 0i64;
    v50 = p_A1->m_quad;
    v51 = p_A1->m_quad;
    A.m_quad = p_A1->m_quad;
    p_A2 = &A2;
    v139 = 0;
    v140 = 0x80000000;
    if ( v45 )
      p_A2 = &B2;
    bTc.m_transform.m_rotation.m_col0.m_quad.m128_i32[0] = 0;
    bTc.m_transform.m_rotation.m_col0.m_quad.m128_u64[1] = 0i64;
    bTc.m_transform.m_rotation.m_col1.m_quad.m128_u64[0] = 0i64;
    bTc.m_transform.m_rotation.m_col1.m_quad.m128_u64[1] = v49;
    B.m_quad = p_A2->m_quad;
    v53 = _mm_min_ps(v51, B.m_quad);
    v54 = _mm_max_ps(v50, B.m_quad);
    v55 = &v149;
    if ( v45 )
      v55 = &v150;
    v148 = (float *)v55;
    if ( v45 )
      v48 = (void **)&v134;
    v56 = (hkVector4f *)v160;
    if ( v45 )
      v56 = &upOutStart;
    v57 = _mm_min_ps(_mm_min_ps(v53, v56->m_quad), v56[1].m_quad);
    v58 = _mm_max_ps(_mm_max_ps(v54, v56->m_quad), v56[1].m_quad);
    bTc.m_transform.m_rotation.m_col2.m_quad.m128_u64[0] = v49 + 112;
    vfptr = v46->vfptr;
    bTc.m_transform.m_translation.m_quad = _mm_sub_ps(v57, (__m128)_xmm);
    bTc.m_halfExtents.m_quad = _mm_add_ps(v58, (__m128)_xmm);
    ((void (__fastcall *)(hkaiNavMeshInstance *, hkaiUserEdgeUtils::Obb *, void **))vfptr[3].__first_virtual_table_function__)(
      v46,
      &bTc,
      &v138);
    v60 = 0;
    if ( v139 > 0 )
    {
      v61 = (hkArray<int,hkContainerHeapAllocator> *)(v49 + 224);
      v62 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v49 + 272);
      v63 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v49 + 240);
      v64 = 0i64;
      up = (hkVector4f *)(&m_quad + v45);
      do
      {
        v65 = *(_DWORD *)((_BYTE *)v138 + v64) & 0x3FFFFF;
        v66 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
                *(hkaiNavMesh::Face **)(v49 + 16),
                *(_DWORD *)(v49 + 24),
                v63,
                v62,
                v61,
                v65);
        array.m_data = v68;
        array.m_size = (int)v68;
        array.m_capacityAndFlags = 0x80000000;
        v69 = (hkaiNavMeshInstance *)v66;
        v70 = v66->m_numEdges + 1;
        if ( v70 <= 0 )
          result.m_enum = (hkResultEnum)v68;
        else
          hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v66->m_numEdges + 1, 16);
        array.m_size = v70;
        hkaiNavMeshUtils::getFaceVertices((hkaiNavMeshUtils *)v49, v69, (hkaiNavMesh::Face *)&array, v67);
        if ( hkaiPathProjectionUtil::projectSegmentOntoFaceAndClipEdgesWorldUp(&array, v65, &A, &B, up, &Aout, &Bout) )
        {
          v71 = Aout.m_quad;
          v72 = Bout.m_quad;
          v147.m_instanceUidA = v65;
          v73 = _mm_sub_ps(B.m_quad, A.m_quad);
          v74 = _mm_mul_ps(v73, A.m_quad);
          v75 = _mm_mul_ps(v73, v73);
          v76 = (float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0] + _mm_shuffle_ps(v74, v74, 0).m128_f32[0])
              + _mm_shuffle_ps(v74, v74, 170).m128_f32[0];
          v77 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                  _mm_shuffle_ps(v75, v75, 170));
          v78 = _mm_mul_ps(Aout.m_quad, v73);
          v79 = (float)(_mm_shuffle_ps(v78, v78, 85).m128_f32[0] + _mm_shuffle_ps(v78, v78, 0).m128_f32[0])
              + _mm_shuffle_ps(v78, v78, 170).m128_f32[0];
          v78.m128_f32[0] = _mm_rcp_ps(v77).m128_f32[0];
          v80 = (float)((float)(2.0 - (float)(v78.m128_f32[0] * v77.m128_f32[0])) * v78.m128_f32[0])
              * (float)(v79 - v76);
          v81 = _mm_mul_ps(Bout.m_quad, v73);
          v147.m_x.m_quad.m128_f32[0] = v80;
          v82 = v77;
          v77.m128_f32[0] = (float)(_mm_shuffle_ps(v81, v81, 85).m128_f32[0] + _mm_shuffle_ps(v81, v81, 0).m128_f32[0])
                          + _mm_shuffle_ps(v81, v81, 170).m128_f32[0];
          v81.m128_f32[0] = _mm_rcp_ps(v82).m128_f32[0];
          v147.m_x.m_quad.m128_f32[1] = (float)((float)(2.0 - (float)(v81.m128_f32[0] * v82.m128_f32[0]))
                                              * v81.m128_f32[0])
                                      * (float)(v77.m128_f32[0] - v76);
          if ( (float)(v147.m_x.m_quad.m128_f32[1] - v80) > *v148 )
          {
            if ( *((_DWORD *)v48 + 2) == (*((_DWORD *)v48 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v48, 64);
            v83 = (__int64)*v48 + 64 * (__int64)*((int *)v48 + 2);
            if ( v83 )
            {
              *(hkVector4f *)v83 = v147.m_x;
              v84 = *(_OWORD *)&v147.m_instanceUidA;
              *(__m128 *)(v83 + 16) = v71;
              *(__m128 *)(v83 + 32) = v72;
              *(_OWORD *)(v83 + 48) = v84;
            }
            ++*((_DWORD *)v48 + 2);
          }
        }
        array.m_size = 0;
        if ( array.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            array.m_data,
            16 * array.m_capacityAndFlags);
        ++v60;
        v64 += 4i64;
        array.m_data = 0i64;
        array.m_capacityAndFlags = 0x80000000;
        v61 = (hkArray<int,hkContainerHeapAllocator> *)(v49 + 224);
        v62 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v49 + 272);
        v63 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v49 + 240);
      }
      while ( v60 < v139 );
      v45 = v131;
      v8 = meshA;
    }
    v139 = 0;
    if ( v140 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v138, 4 * v140);
    v9 = (hkaiNavMeshInstance *)input;
    ++v45;
    v138 = 0i64;
    v140 = 0x80000000;
    v131 = v45;
  }
  while ( v45 < 2 );
  m_real = getMidpointDistance((hkSimdFloat32 *)&Bout, &A1, &A2, &B1, &B2)->m_real;
  hkTransformf::setInverse(&v159, (hkTransformf *)&input->m_obbB.m_transform.m_rotation.m_col2);
  hkTransformf::setInverse(&v158, &v8->m_referenceFrame.m_transform);
  v86 = (int)v141;
  v87 = 0i64;
  v88 = 0;
  v165 = 0;
  if ( (int)v141 > 0 )
  {
    v89 = v135;
    v90 = query.m_quad;
    v91 = 0i64;
    do
    {
      v92 = 0;
      if ( v89 > 0 )
      {
        v93 = _mm_max_ps(v149, v150);
        Bout.m_quad = v93;
        do
        {
          v94 = v134;
          v95 = v141;
          v96 = _mm_shuffle_ps((__m128)*(unsigned int *)&v141[v91 + 4], (__m128)*(unsigned int *)&v141[v91 + 4], 0);
          v97 = _mm_sub_ps(
                  v90,
                  _mm_shuffle_ps((__m128)*(unsigned int *)&v134[v87 + 4], (__m128)*(unsigned int *)&v134[v87 + 4], 0));
          v98 = _mm_sub_ps(
                  v90,
                  _mm_shuffle_ps((__m128)*(unsigned int *)&v134[v87], (__m128)*(unsigned int *)&v134[v87], 0));
          v99 = _mm_shuffle_ps((__m128)*(unsigned int *)&v141[v91], (__m128)*(unsigned int *)&v141[v91], 0);
          v100 = _mm_min_ps(v96, v98);
          v101 = _mm_max_ps(v99, v97);
          if ( (float)(v100.m128_f32[0] - v101.m128_f32[0]) > v93.m128_f32[0] )
          {
            hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&v147);
            v102 = *(__m128 *)&v95[v91 + 16];
            v103 = _mm_sub_ps(v98, v97);
            v104 = _mm_sub_ps(v96, v99);
            v147.m_userDataA = *((_DWORD *)retaddr + 40);
            v105 = _mm_rcp_ps(v104);
            v147.m_userDataB = *((_DWORD *)retaddr + 41);
            v106 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v12, _mm_mul_ps(v104, v105)), v105), _mm_sub_ps(v100, v99));
            v107 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v12, _mm_mul_ps(v104, v105)), v105), _mm_sub_ps(v101, v99));
            v108 = _mm_rcp_ps(v103);
            v109 = _mm_sub_ps(*(__m128 *)&v95[v91 + 32], v102);
            v110 = _mm_add_ps(_mm_mul_ps(v109, v107), v102);
            v111 = _mm_add_ps(_mm_mul_ps(v106, v109), v102);
            v112 = *(__m128 *)&v94[v87 + 16];
            v113 = _mm_sub_ps(*(__m128 *)&v94[v87 + 32], v112);
            v114 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         query.m_quad,
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v12, _mm_mul_ps(v103, v108)), v108), _mm_sub_ps(v100, v97))),
                       v113),
                     v112);
            v115 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         query.m_quad,
                         _mm_mul_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v103, v108)), v108),
                           _mm_sub_ps(v101, v97))),
                       v113),
                     v112);
            v116 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v115, v115, 85), v158.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v115, v115, 0), v158.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v115, v115, 170), v158.m_rotation.m_col2.m_quad)),
                     v158.m_translation.m_quad);
            v117 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v110, v110, 85), v159.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v110, v110, 0), v159.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v110, v110, 170), v159.m_rotation.m_col2.m_quad)),
                     v159.m_translation.m_quad);
            v147.m_faceA = *(_DWORD *)&v141[v91 + 48];
            v147.m_faceB = *(_DWORD *)&v134[v87 + 48];
            v118 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v111, v111, 85), v159.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v111, v111, 0), v159.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v111, v111, 170), v159.m_rotation.m_col2.m_quad)),
                     v159.m_translation.m_quad);
            v119 = _mm_shuffle_ps(v117, v118, 68);
            v120 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v114, v114, 85), v158.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v114, v114, 0), v158.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v114, v114, 170), v158.m_rotation.m_col2.m_quad)),
                     v158.m_translation.m_quad);
            v121 = _mm_shuffle_ps(v120, v116, 238);
            v122 = _mm_shuffle_ps(v120, v116, 68);
            v123 = _mm_shuffle_ps(_mm_shuffle_ps(v117, v118, 238), v121, 136);
            v124 = *((float *)retaddr + 42);
            v125 = _mm_shuffle_ps(v119, v122, 136);
            v126 = _mm_shuffle_ps(v119, v122, 221);
            if ( v124 < 0.0 )
              v124 = m_real.m128_f32[0];
            v127 = *((float *)retaddr + 43);
            if ( v127 < 0.0 )
              v127 = m_real.m128_f32[0];
            *(float *)&result.m_enum = v124 * 1.0039062;
            v132 = v127 * 1.0039062;
            v147.m_costAtoB.m_value = HIWORD(result.m_enum);
            v147.m_costBtoA.m_value = HIWORD(v132);
            v147.m_direction.m_storage = *((_BYTE *)retaddr + 208);
            v147.m_instanceUidA = input[2].m_obbA.m_transform.m_rotation.m_col1.m_quad.m128_u32[1];
            v147.m_instanceUidB = v8->m_sectionUid;
            if ( *(_DWORD *)&mediatorB->m_memSizeAndFlags == (*(_DWORD *)(&mediatorB->m_referenceCount + 1) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, mediatorB, 80);
            v128 = &mediatorB->vfptr[5 * *(int *)&mediatorB->m_memSizeAndFlags];
            if ( v128 )
            {
              v129 = *(hkBaseObjectVtbl *)&v147.m_instanceUidA;
              v130 = *(hkBaseObjectVtbl *)&v147.m_userDataA;
              *v128 = (hkBaseObjectVtbl)v125;
              v128[1] = (hkBaseObjectVtbl)v126;
              v128[2] = (hkBaseObjectVtbl)v123;
              v128[3] = v129;
              v128[4] = v130;
            }
            ++*(_DWORD *)&mediatorB->m_memSizeAndFlags;
            v89 = v135;
            v93.m128_i32[0] = Bout.m_quad.m128_i32[0];
            v90 = query.m_quad;
            v12 = (__m128)_xmm;
          }
          ++v92;
          v87 += 64i64;
        }
        while ( v92 < v89 );
        v86 = (int)v141;
        v88 = v165;
        v87 = 0i64;
      }
      ++v88;
      v91 += 64i64;
      v165 = v88;
    }
    while ( v88 < v86 );
  }
  v135 = 0;
  if ( v136 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v134, v136 << 6);
  v134 = 0i64;
  LODWORD(v141) = 0;
  v136 = 0x80000000;
  if ( SHIDWORD(v141) >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v141, HIDWORD(v141) << 6);
}

// File Line: 407
// RVA: 0xBD0770
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(
        hkaiNavMeshInstance *meshInstance,
        unsigned int faceIndexA,
        unsigned int faceIndexB,
        hkVector4f *edgeAStart,
        hkVector4f *edgeAEnd,
        hkVector4f *edgeBStart,
        hkVector4f *edgeBEnd,
        bool allowAtoB,
        bool allowBtoA,
        float costAtoB,
        float costBtoA)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v16; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  int m_runtimeId; // ebx
  bool v21; // al
  bool v22; // [rsp+40h] [rbp-68h]
  hkaiStreamingCollection array; // [rsp+60h] [rbp-48h] BYREF
  hkResult result; // [rsp+B0h] [rbp+8h] BYREF

  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v16 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v16;
    }
    while ( v16 );
    m_data = array.m_instances.m_data;
  }
  v18 = costBtoA;
  v19 = costAtoB;
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = meshInstance;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  m_runtimeId = meshInstance->m_runtimeId;
  v22 = allowBtoA;
  v21 = allowAtoB;
  meshInstance->m_runtimeId = 0;
  hkaiUserEdgeUtils::addUserEdgePair(
    &array,
    faceIndexA,
    faceIndexB,
    edgeAStart,
    edgeAEnd,
    edgeBStart,
    edgeBEnd,
    v21,
    v22,
    v19,
    v18);
  meshInstance->m_runtimeId = m_runtimeId;
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 420
// RVA: 0xBD0640
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(
        hkaiNavMeshInstance *meshInstance,
        hkaiUserEdgeUtils::UserEdgePair *pair,
        hkaiUserEdgeUtils::UpdateParameters *params)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v7; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  int m_runtimeId; // ebx
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v7 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v7;
    }
    while ( v7 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = meshInstance;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  m_runtimeId = meshInstance->m_runtimeId;
  meshInstance->m_runtimeId = 0;
  hkaiUserEdgeUtils::addUserEdgePair(&array, pair, params);
  meshInstance->m_runtimeId = m_runtimeId;
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 433
// RVA: 0xBD0920
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(
        hkaiStreamingCollection *collection,
        unsigned int faceKeyA,
        unsigned int faceKeyB,
        hkVector4f *edgeAStart,
        hkVector4f *edgeAEnd,
        hkVector4f *edgeBStart,
        hkVector4f *edgeBEnd,
        bool allowAtoB,
        float allowBtoA,
        float costAtoB,
        float costBtoA)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // rdx
  __m128 m_quad; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  hkaiUserEdgeUtils::UserEdgePair pair; // [rsp+20h] [rbp-58h] BYREF

  hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&pair);
  m_data = collection->m_instances.m_data;
  m_quad = edgeAStart->m_quad;
  v17 = edgeAStart->m_quad;
  pair.m_faceA = faceKeyA & 0x3FFFFF;
  pair.m_instanceUidA = m_data[faceKeyA >> 22].m_instancePtr->m_sectionUid;
  pair.m_faceB = faceKeyB & 0x3FFFFF;
  pair.m_instanceUidB = m_data[faceKeyB >> 22].m_instancePtr->m_sectionUid;
  pair.m_direction.m_storage = (LOBYTE(allowBtoA) != 0 ? 2 : 0) | allowAtoB;
  allowBtoA = costBtoA * 1.0039062;
  pair.m_costAtoB.m_value = COERCE_INT(costAtoB * 1.0039062) >> 16;
  LOWORD(allowBtoA) = 256;
  BYTE2(allowBtoA) = 0;
  pair.m_costBtoA.m_value = COERCE_INT(costBtoA * 1.0039062) >> 16;
  v18 = _mm_shuffle_ps(v17, edgeAEnd->m_quad, 68);
  v19 = _mm_shuffle_ps(edgeBStart->m_quad, edgeBEnd->m_quad, 68);
  pair.m_z.m_quad = _mm_shuffle_ps(
                      _mm_shuffle_ps(m_quad, edgeAEnd->m_quad, 238),
                      _mm_shuffle_ps(edgeBStart->m_quad, edgeBEnd->m_quad, 238),
                      136);
  pair.m_x.m_quad = _mm_shuffle_ps(v18, v19, 136);
  pair.m_y.m_quad = _mm_shuffle_ps(v18, v19, 221);
  hkaiUserEdgeUtils::addUserEdgePair(collection, &pair, (hkaiUserEdgeUtils::UpdateParameters *)&allowBtoA);
}

// File Line: 451
// RVA: 0xBD1FA0
void __fastcall reindexOpposite(
        hkaiStreamingCollection *collection,
        hkaiNavMeshInstance *instance,
        hkaiNavMesh::Edge *edge,
        int secIdx,
        int newEdgeIdx,
        unsigned int faceKey)
{
  char v7; // r11
  unsigned int v8; // eax
  unsigned int v9; // r8d
  hkaiNavMeshInstance *m_instancePtr; // rdx
  int m_numOriginalEdges; // ecx
  signed int v12; // eax
  __int64 v13; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  hkaiNavMesh::Edge *v15; // rdx
  char m_storage; // [rsp+8h] [rbp+8h]

  v7 = edge->m_flags.m_storage & 0x40;
  if ( v7 )
    v8 = edge->m_oppositeFace & 0xFFC00000;
  else
    v8 = instance->m_runtimeId << 22;
  v9 = v8 | edge->m_oppositeFace & 0x3FFFFF;
  if ( edge->m_oppositeFace == -1 )
    v9 = -1;
  m_instancePtr = collection->m_instances.m_data[v9 >> 22].m_instancePtr;
  if ( m_instancePtr->m_faceFlags.m_size )
    m_storage = m_instancePtr->m_faceFlags.m_data[v9 & 0x3FFFFF].m_storage;
  else
    m_storage = 0;
  if ( (m_storage & 1) == 0 )
  {
    m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
    v12 = edge->m_oppositeEdge & 0x3FFFFF;
    if ( v12 < m_numOriginalEdges )
    {
      if ( m_instancePtr->m_edgeMap.m_size )
        v12 = m_instancePtr->m_edgeMap.m_data[v12];
      if ( v12 == -1 )
      {
        v15 = 0i64;
        goto LABEL_18;
      }
      v13 = v12;
      m_data = m_instancePtr->m_instancedEdges.m_data;
    }
    else
    {
      v13 = v12 - m_numOriginalEdges;
      m_data = m_instancePtr->m_ownedEdges.m_data;
    }
    v15 = &m_data[v13];
LABEL_18:
    if ( v7 )
    {
      v15->m_oppositeFace = faceKey;
      v15->m_oppositeEdge = newEdgeIdx | (secIdx << 22);
    }
    else
    {
      v15->m_oppositeEdge = newEdgeIdx;
      v15->m_oppositeFace = faceKey & 0x3FFFFF;
    }
  }
}

// File Line: 478
// RVA: 0xBD20C0
void __fastcall setupEdges(
        hkaiNavMeshInstance *instanceA,
        hkaiNavMeshInstance *instanceB,
        unsigned int faceKeyA,
        unsigned int faceKeyB,
        unsigned int edgeKeyA,
        unsigned int edgeKeyB,
        hkaiUserEdgeUtils::UserEdgePair *pair)
{
  int m_numOriginalEdges; // ecx
  int v9; // ebp
  int v10; // esi
  __int64 v12; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  signed int v14; // edx
  hkaiNavMesh::Edge *v15; // rdi
  int v16; // ecx
  __int64 v17; // rcx
  hkaiNavMesh::Edge *v18; // rax
  signed int v19; // edx
  hkaiNavMesh::Edge *v20; // rbx
  int v22; // r12d
  hkVector4f v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  bool v28; // zf
  unsigned int v29; // eax
  __m128 m_real; // xmm6
  __m128 v31; // xmm5
  hkSimdFloat32 *MidpointDistance; // rax
  float v33; // xmm6_4
  bool v34; // cl
  hkSimdFloat32 result; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f B1; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f B2; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f v; // [rsp+60h] [rbp-78h] BYREF
  hkVector4f A2; // [rsp+70h] [rbp-68h] BYREF
  int v40; // [rsp+E0h] [rbp+8h]
  float edgeKeyBa; // [rsp+108h] [rbp+30h]
  bool paira; // [rsp+110h] [rbp+38h]

  m_numOriginalEdges = instanceA->m_numOriginalEdges;
  v9 = edgeKeyA & 0x3FFFFF;
  v10 = edgeKeyB & 0x3FFFFF;
  if ( (int)(edgeKeyA & 0x3FFFFF) < m_numOriginalEdges )
  {
    if ( instanceA->m_edgeMap.m_size )
      v14 = instanceA->m_edgeMap.m_data[v9];
    else
      v14 = edgeKeyA & 0x3FFFFF;
    if ( v14 == -1 )
    {
      v15 = 0i64;
      goto LABEL_10;
    }
    v12 = v14;
    m_data = instanceA->m_instancedEdges.m_data;
  }
  else
  {
    v12 = v9 - m_numOriginalEdges;
    m_data = instanceA->m_ownedEdges.m_data;
  }
  v15 = &m_data[v12];
LABEL_10:
  v16 = instanceB->m_numOriginalEdges;
  if ( v10 < v16 )
  {
    if ( instanceB->m_edgeMap.m_size )
      v19 = instanceB->m_edgeMap.m_data[v10];
    else
      v19 = edgeKeyB & 0x3FFFFF;
    if ( v19 == -1 )
    {
      v20 = 0i64;
      goto LABEL_19;
    }
    v17 = v19;
    v18 = instanceB->m_instancedEdges.m_data;
  }
  else
  {
    v17 = v10 - v16;
    v18 = instanceB->m_ownedEdges.m_data;
  }
  v20 = &v18[v17];
LABEL_19:
  v22 = instanceA->m_numOriginalVertices + instanceA->m_ownedVertices.m_size;
  v23.m_quad = (__m128)pair->m_z;
  v24 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 238);
  v25 = _mm_shuffle_ps(v23.m_quad, (__m128)0i64, 238);
  v26 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 68);
  v27 = _mm_shuffle_ps(v23.m_quad, (__m128)0i64, 68);
  v.m_quad = _mm_shuffle_ps(v26, v27, 136);
  A2.m_quad = _mm_shuffle_ps(v26, v27, 221);
  B1.m_quad = _mm_shuffle_ps(v24, v25, 136);
  B2.m_quad = _mm_shuffle_ps(v24, v25, 221);
  hkaiNavMeshInstance::appendVertices(instanceA, &v, 2);
  v40 = instanceB->m_numOriginalVertices + instanceB->m_ownedVertices.m_size;
  hkaiNavMeshInstance::appendVertices(instanceB, &B1, 2);
  v28 = instanceA->m_sectionUid == instanceB->m_sectionUid;
  v15->m_a = v22;
  *(_DWORD *)&v15->m_flags.m_storage = 4;
  paira = !v28;
  v15->m_b = v22 + 1;
  if ( v28 )
  {
    v15->m_oppositeEdge = v10;
    v15->m_oppositeFace = faceKeyB & 0x3FFFFF;
    v20->m_oppositeEdge = v9;
    v20->m_a = v40;
    v20->m_b = v40 + 1;
    v29 = faceKeyA & 0x3FFFFF;
  }
  else
  {
    v15->m_oppositeEdge = edgeKeyB;
    v15->m_oppositeFace = faceKeyB;
    v20->m_a = v40;
    v20->m_b = v40 + 1;
    v20->m_oppositeEdge = edgeKeyA;
    v29 = faceKeyA;
  }
  v20->m_oppositeFace = v29;
  *(_DWORD *)&v20->m_flags.m_storage = 4;
  v15->m_flags.m_storage = 16;
  v20->m_flags.m_storage = 16;
  m_real.m128_i32[0] = pair->m_costAtoB.m_value << 16;
  v31.m128_i32[0] = pair->m_costBtoA.m_value << 16;
  if ( m_real.m128_f32[0] < 0.0 || v31.m128_f32[0] < 0.0 )
  {
    MidpointDistance = getMidpointDistance(&result, &v, &A2, &B1, &B2);
    if ( m_real.m128_f32[0] < 0.0 )
      m_real = MidpointDistance->m_real;
    if ( v31.m128_f32[0] < 0.0 )
      v31 = MidpointDistance->m_real;
  }
  v33 = m_real.m128_f32[0] * 1.0039062;
  edgeKeyBa = v31.m128_f32[0] * 1.0039062;
  v15->m_userEdgeCost.m_value = HIWORD(v33);
  v20->m_userEdgeCost.m_value = HIWORD(edgeKeyBa);
  hkaiNavMeshInstance::setEdgeData(instanceA, v9, pair->m_userDataA);
  hkaiNavMeshInstance::setEdgeData(instanceB, v10, pair->m_userDataB);
  v34 = (pair->m_direction.m_storage & 2) != 0;
  if ( (pair->m_direction.m_storage & 1) == 0 )
    v15->m_flags.m_storage |= 0x20u;
  if ( !v34 )
    v20->m_flags.m_storage |= 0x20u;
  if ( paira )
  {
    v15->m_flags.m_storage |= 0x40u;
    v20->m_flags.m_storage |= 0x40u;
  }
}

// File Line: 554
// RVA: 0xBD0520
void __fastcall hkaiUserEdgeUtils::addUserEdgePair(
        hkaiStreamingCollection *collection,
        hkaiUserEdgeUtils::UserEdgePair *pair,
        hkaiUserEdgeUtils::UpdateParameters *params)
{
  int m_size; // r8d
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> array; // [rsp+20h] [rbp-68h] BYREF
  hkaiUserEdgeUtils::UserEdgePair v8; // [rsp+30h] [rbp-58h] BYREF

  array.m_size = 0;
  array.m_data = &v8;
  array.m_capacityAndFlags = -2147483647;
  hkaiUserEdgeUtils::UserEdgePair::UserEdgePair(&v8);
  m_size = 0;
  if ( &v8 )
  {
    v8 = *pair;
    m_size = array.m_size;
  }
  array.m_size = m_size + 1;
  hkaiUserEdgeUtils::addUserEdgePairsBatch(collection, &array, params);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      80 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 562
// RVA: 0xBD0AA0
void __fastcall hkaiUserEdgeUtils::addUserEdgePairsBatch(
        hkaiStreamingCollection *collection,
        hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *pairs,
        hkaiUserEdgeUtils::UpdateParameters *params)
{
  hkaiStreamingCollection *v4; // r13
  int m_size; // ebx
  int v6; // edi
  int v7; // r14d
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rdx
  int v10; // ecx
  char *v11; // r8
  int v12; // r9d
  __int64 v13; // rcx
  unsigned int *v14; // rdi
  unsigned int mWidth; // r8d
  int v16; // esi
  __int64 v17; // r15
  __int64 v18; // r14
  unsigned int *v19; // rbx
  __int64 SectionIdByUid; // r12
  int v21; // eax
  int v22; // r8d
  unsigned int v23; // eax
  unsigned int v24; // ebx
  unsigned int v25; // edi
  int v26; // eax
  int v27; // eax
  __int64 v28; // r8
  int v29; // edx
  __int64 v30; // rcx
  _QWORD *v31; // rax
  int v32; // eax
  __int64 v33; // rax
  int v34; // ecx
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  __int64 v36; // r15
  int v37; // edx
  hkaiNavMeshInstance *m_instancePtr; // rsi
  signed int m_numOriginalFaces; // eax
  hkaiNavMesh::Face *v40; // r13
  int v41; // eax
  int v42; // edi
  int v43; // r12d
  unsigned __int64 v44; // rbx
  Dummy *Key; // rax
  unsigned int val; // edx
  int v47; // edi
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v49; // rax
  __int16 m_numUserEdges; // ax
  int v51; // edi
  __int64 v52; // rbx
  int m_numOriginalEdges; // ecx
  __int64 v54; // rcx
  hkaiNavMesh::Edge *v55; // rax
  int v56; // ecx
  hkaiNavMesh::Edge *v57; // r8
  unsigned int v58; // edx
  int v59; // edx
  __int64 v60; // rcx
  _QWORD *v61; // rax
  int v62; // r12d
  hkaiStreamingCollection *v63; // rbx
  __int64 v64; // r13
  __int64 v65; // r14
  hkaiUserEdgeUtils::UserEdgePair *v66; // r15
  int v67; // eax
  unsigned int m_instanceUidB; // edx
  int v69; // edi
  int v70; // eax
  int m_faceB; // ebx
  int v72; // eax
  unsigned __int64 v73; // rdx
  unsigned int v74; // ebx
  unsigned int v75; // edi
  int v76; // esi
  int v77; // eax
  unsigned __int64 v78; // r8
  int v79; // ebx
  hkaiStreamingCollection::InstanceInfo *v80; // rdi
  unsigned int v81; // r8d
  int v82; // esi
  unsigned int v83; // ebx
  hkaiNavMeshInstance *v84; // rdx
  bool v85; // di
  hkaiStreamingCollection *v86; // rsi
  int v87; // edi
  __int64 v88; // rbx
  hkaiNavMeshInstance *v89; // rcx
  __int64 v90; // rdi
  __int64 v91; // rbx
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rcx
  __int64 index; // [rsp+28h] [rbp-59h]
  int indexa; // [rsp+28h] [rbp-59h]
  int secIdx; // [rsp+2Ch] [rbp-55h]
  AMD_HD3D v96; // [rsp+30h] [rbp-51h] BYREF
  unsigned int faceKeyA[2]; // [rsp+50h] [rbp-31h]
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> v98; // [rsp+58h] [rbp-29h] BYREF
  int v99; // [rsp+68h] [rbp-19h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+70h] [rbp-11h] BYREF
  hkaiStreamingCollection *collectiona; // [rsp+E8h] [rbp+67h]
  unsigned int userEdgeKey[2]; // [rsp+F0h] [rbp+6Fh]
  _BYTE *retaddr; // [rsp+F8h] [rbp+77h]
  hkaiStreamingCollection *result; // [rsp+100h] [rbp+7Fh] BYREF
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v105; // [rsp+108h] [rbp+87h]
  hkaiUserEdgeUtils::UpdateParameters *v106; // [rsp+110h] [rbp+8Fh]

  v106 = params;
  v105 = pairs;
  result = collection;
  v4 = collection;
  if ( pairs->m_size )
  {
    m_size = collection->m_instances.m_size;
    v6 = (m_size + 31) >> 5;
    v7 = 0;
    array.m_words.m_data = 0i64;
    array.m_words.m_size = 0;
    array.m_words.m_capacityAndFlags = 0x80000000;
    array.m_words.m_initialCapacity = v6;
    if ( v6 )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned int *)Value->m_cur;
      v10 = (4 * v6 + 127) & 0xFFFFFF80;
      v11 = (char *)m_cur + v10;
      if ( v10 > Value->m_slabSize || v11 > Value->m_end )
        m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
      else
        Value->m_cur = v11;
    }
    else
    {
      m_cur = 0i64;
    }
    array.m_words.m_data = m_cur;
    array.m_words.m_localMemory = m_cur;
    array.m_numBits = m_size;
    array.m_words.m_capacityAndFlags = v6 | 0x80000000;
    if ( (v6 & 0x3FFFFFFF) < v6 )
    {
      v12 = (m_size + 31) >> 5;
      if ( v6 < 2 * (v6 & 0x3FFFFFFF) )
        v12 = 2 * (v6 & 0x3FFFFFFF);
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &array, v12, 4);
      m_cur = array.m_words.m_data;
    }
    array.m_words.m_size = (m_size + 31) >> 5;
    if ( v6 - 1 >= 0 )
    {
      v13 = (unsigned int)v6;
      v14 = m_cur;
      while ( v13 )
      {
        *v14++ = 0;
        --v13;
      }
    }
    *(_QWORD *)&v96.mEnableStereo = 0i64;
    mWidth = 0;
    v96.mWidth = 0;
    v96.mHeight = -1;
    v16 = 0;
    if ( pairs->m_size > 0 )
    {
      v17 = 0i64;
      v18 = *(_QWORD *)userEdgeKey;
      do
      {
        v19 = (unsigned int *)(v17 + *(_QWORD *)v18);
        SectionIdByUid = (int)hkaiStreamingCollection::findSectionIdByUid(v4, v19[12]);
        v21 = hkaiStreamingCollection::findSectionIdByUid(v4, v19[13]);
        v22 = v21;
        if ( (_DWORD)SectionIdByUid != -1 && v21 != -1 )
        {
          array.m_words.m_data[SectionIdByUid >> 5] |= 1 << (SectionIdByUid & 0x1F);
          array.m_words.m_data[(__int64)v21 >> 5] |= 1 << (v21 & 0x1F);
          v23 = ((_DWORD)SectionIdByUid << 22) | v19[14];
          v24 = (v22 << 22) | v19[15];
          v25 = v23;
          v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96,
                  v23,
                  0i64);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96,
            &hkContainerHeapAllocator::s_alloc,
            v25,
            v26 + 1);
          v27 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96,
                  v24,
                  0i64);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96,
            &hkContainerHeapAllocator::s_alloc,
            v24,
            v27 + 1);
        }
        ++v16;
        v17 += 80i64;
      }
      while ( v16 < *(_DWORD *)(v18 + 8) );
      mWidth = v96.mWidth;
      v7 = 0;
    }
    v96.mStereo = 0i64;
    v96.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
      &hkContainerHeapAllocator::s_alloc,
      mWidth & 0x7FFFFFFF);
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v98);
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::reserve(
      &v98,
      v96.mWidth & 0x7FFFFFFF);
    v28 = *(_QWORD *)&v96.mEnableStereo;
    v29 = 0;
    v30 = 0i64;
    if ( (v96.mHeight & 0x80000000) == 0 )
    {
      v31 = *(_QWORD **)&v96.mEnableStereo;
      do
      {
        if ( *v31 != -1i64 )
          break;
        ++v30;
        ++v29;
        v31 += 2;
      }
      while ( v30 <= (int)v96.mHeight );
    }
    v32 = v29;
    *(_QWORD *)faceKeyA = v29;
    if ( v29 <= (int)v96.mHeight )
    {
      while ( 1 )
      {
        v33 = 2i64 * v32;
        LODWORD(index) = *(_DWORD *)(v28 + 8 * v33);
        v34 = *(_DWORD *)(v28 + 8 * v33 + 8);
        m_data = v4->m_instances.m_data;
        v36 = (unsigned int)index >> 22;
        LODWORD(result) = v34;
        v37 = index & 0x3FFFFF;
        HIDWORD(index) = (unsigned int)index >> 22;
        m_instancePtr = m_data[v36].m_instancePtr;
        m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
        if ( (index & 0x3FFFFF) < m_numOriginalFaces )
        {
          if ( m_instancePtr->m_faceMap.m_size )
            v41 = m_instancePtr->m_faceMap.m_data[v37];
          else
            v41 = index & 0x3FFFFF;
          if ( v41 == -1 )
            v40 = hkaiNavMeshInstance_instance_hkaiNavMesh::Face_int__0(
                    m_instancePtr->m_originalFaces,
                    &m_instancePtr->m_instancedFaces,
                    m_instancePtr->m_originalFaceData,
                    &m_instancePtr->m_instancedFaceData,
                    &m_instancePtr->m_faceMap,
                    v37,
                    m_instancePtr->m_faceDataStriding);
          else
            v40 = &m_instancePtr->m_instancedFaces.m_data[v41];
        }
        else
        {
          v40 = &m_instancePtr->m_ownedFaces.m_data[v37 - m_numOriginalFaces];
        }
        v42 = (int)result;
        v43 = -1;
        v44 = (int)result + v40->m_numUserEdges;
        Key = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                &v98,
                v44);
        if ( (int)Key <= v98.m_hashMod )
        {
          while ( 1 )
          {
            val = v98.m_elem[(int)Key].val;
            if ( val >> 22 == (_DWORD)v36 )
              break;
            v47 = (_DWORD)Key + 1;
            for ( i = (int)Key + 1; i > v98.m_hashMod; i = 0i64 )
LABEL_46:
              v47 = 0;
            v49 = &v98.m_elem[i];
            while ( v49->key != -1i64 )
            {
              if ( v49->key == v44 )
              {
                Key = (Dummy *)v47;
                goto LABEL_49;
              }
              ++i;
              ++v47;
              ++v49;
              if ( i > v98.m_hashMod )
                goto LABEL_46;
            }
            Key = (Dummy *)(v98.m_hashMod + 1);
LABEL_49:
            if ( (int)Key > v98.m_hashMod )
              goto LABEL_52;
          }
          v43 = val & 0x3FFFFF;
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v98,
            Key);
LABEL_52:
          v42 = (int)result;
        }
        m_numUserEdges = v40->m_numUserEdges;
        if ( !m_numUserEdges )
        {
          if ( v43 == -1 )
          {
            v43 = m_instancePtr->m_numOriginalEdges + m_instancePtr->m_ownedEdges.m_size;
            hkaiNavMeshInstance::expandEdgesBy(m_instancePtr, v42);
          }
          goto LABEL_72;
        }
        if ( v43 == -1 )
        {
          v43 = m_instancePtr->m_numOriginalEdges + m_instancePtr->m_ownedEdges.m_size;
          hkaiNavMeshInstance::expandEdgesBy(m_instancePtr, v42 + m_numUserEdges);
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
            &v98,
            v40->m_numUserEdges,
            (unsigned int)((_DWORD)v36 << 22) | (unsigned __int64)(unsigned int)v40->m_startUserEdgeIndex);
        }
        if ( v40->m_numUserEdges > 0 )
          break;
LABEL_72:
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned int)index,
          v43 + v40->m_numUserEdges);
        v58 = faceKeyA[0];
        v40->m_numUserEdges += (__int16)result;
        v40->m_startUserEdgeIndex = v43;
        v28 = *(_QWORD *)&v96.mEnableStereo;
        v59 = v58 + 1;
        v60 = v59;
        if ( v59 <= (__int64)(int)v96.mHeight )
        {
          v61 = (_QWORD *)(*(_QWORD *)&v96.mEnableStereo + 16i64 * v59);
          do
          {
            if ( *v61 != -1i64 )
              break;
            ++v60;
            ++v59;
            v61 += 2;
          }
          while ( v60 <= (int)v96.mHeight );
        }
        v32 = v59;
        *(_QWORD *)faceKeyA = v59;
        if ( v59 > (int)v96.mHeight )
          goto LABEL_77;
        v4 = collectiona;
      }
      v51 = v43;
      v52 = v43;
      while ( 1 )
      {
        hkaiNavMeshInstance::copyOwnedEdge(
          m_instancePtr,
          v51 - m_instancePtr->m_numOriginalEdges,
          v40->m_startUserEdgeIndex + v51 - v43 - m_instancePtr->m_numOriginalEdges);
        m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
        if ( v51 >= m_numOriginalEdges )
          break;
        if ( m_instancePtr->m_edgeMap.m_size )
          v56 = m_instancePtr->m_edgeMap.m_data[v52];
        else
          v56 = v51;
        if ( v56 != -1 )
        {
          v54 = v56;
          v55 = m_instancePtr->m_instancedEdges.m_data;
          goto LABEL_68;
        }
        v57 = 0i64;
LABEL_69:
        if ( v57->m_oppositeEdge != -1 )
          reindexOpposite(collectiona, m_instancePtr, v57, SHIDWORD(index), v51, index);
        ++v51;
        ++v52;
        if ( v51 - v43 >= v40->m_numUserEdges )
          goto LABEL_72;
      }
      v54 = v51 - m_numOriginalEdges;
      v55 = m_instancePtr->m_ownedEdges.m_data;
LABEL_68:
      v57 = &v55[v54];
      goto LABEL_69;
    }
LABEL_77:
    v62 = 0;
    if ( *(int *)(*(_QWORD *)userEdgeKey + 8i64) > 0 )
    {
      v63 = collectiona;
      v64 = 0i64;
      v65 = *(_QWORD *)userEdgeKey;
      do
      {
        v66 = (hkaiUserEdgeUtils::UserEdgePair *)(v64 + *(_QWORD *)v65);
        v67 = hkaiStreamingCollection::findSectionIdByUid(v63, v66->m_instanceUidA);
        m_instanceUidB = v66->m_instanceUidB;
        v69 = v67;
        v99 = v67;
        v70 = hkaiStreamingCollection::findSectionIdByUid(v63, m_instanceUidB);
        indexa = v70;
        if ( v69 != -1 && v70 != -1 )
        {
          m_faceB = v66->m_faceB;
          v72 = v70 << 22;
          v73 = (unsigned int)(v69 << 22) | v66->m_faceA;
          userEdgeKey[0] = v69 << 22;
          v74 = v72 | m_faceB;
          faceKeyA[0] = v73;
          secIdx = v72;
          LODWORD(result) = v74;
          v75 = v73;
          v76 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
                  v73,
                  0xFFFFFFFFFFFFFFFFui64);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
            &hkContainerHeapAllocator::s_alloc,
            v75,
            v76 + 1);
          v77 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
                  v74,
                  0xFFFFFFFFFFFFFFFFui64);
          v78 = v74;
          v79 = v77;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
            &hkContainerHeapAllocator::s_alloc,
            v78,
            v77 + 1);
          v80 = collectiona->m_instances.m_data;
          v81 = v76 | userEdgeKey[0];
          v82 = v79 | secIdx;
          v83 = faceKeyA[0];
          *(_QWORD *)&v96.mEnableStereo = v66;
          v84 = v80[indexa].m_instancePtr;
          userEdgeKey[0] = v81;
          setupEdges(v80[v99].m_instancePtr, v84, faceKeyA[0], (unsigned int)result, v81, v82, v66);
          if ( retaddr[1] )
          {
            v85 = (v66->m_direction.m_storage & 2) != 0;
            if ( (v66->m_direction.m_storage & 1) != 0 )
              hkaiGraphUtils::addDirectedGraphEdgeForUserEdge(v83, userEdgeKey[0], collectiona);
            v63 = collectiona;
            if ( v85 )
              hkaiGraphUtils::addDirectedGraphEdgeForUserEdge((unsigned int)result, v82, collectiona);
          }
          else
          {
            v63 = collectiona;
          }
        }
        ++v62;
        v64 += 80i64;
      }
      while ( v62 < *(_DWORD *)(v65 + 8) );
      v7 = 0;
    }
    v86 = collectiona;
    if ( !*retaddr )
    {
      v87 = 0;
      if ( collectiona->m_instances.m_size > 0 )
      {
        v88 = 0i64;
        do
        {
          if ( ((array.m_words.m_data[(__int64)v87 >> 5] >> (v87 & 0x1F)) & 1) != 0 )
          {
            v89 = v86->m_instances.m_data[v88].m_instancePtr;
            if ( v89 )
              hkaiNavMeshInstance::initGlobalClearanceCache(v89);
          }
          ++v87;
          ++v88;
        }
        while ( v87 < v86->m_instances.m_size );
      }
    }
    if ( retaddr[2] )
    {
      v90 = 0i64;
      if ( v86->m_instances.m_size > 0 )
      {
        v91 = 0i64;
        do
        {
          if ( v90 >= 0 )
          {
            m_clusterGraphInstance = v86->m_instances.m_data[v91].m_clusterGraphInstance;
            if ( m_clusterGraphInstance )
              hkaiGraphUtils::compactOwnedEdges(m_clusterGraphInstance);
          }
          ++v7;
          ++v90;
          ++v91;
        }
        while ( v7 < v86->m_instances.m_size );
      }
    }
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v98);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96.mStereo,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&v96.mStereo);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v96,
      &hkContainerHeapAllocator::s_alloc);
    _(&v96);
    hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
  }
}

// File Line: 818
// RVA: 0xBD2420
void __fastcall projectPair(
        hkaiNavMeshUtils *meshInstance,
        hkVector4f *up,
        hkArrayBase<int> *magic,
        hkaiUserEdgeUtils::UserEdgePair *pair,
        int idx,
        hkArray<EdgeSplitInfo,hkContainerTempAllocator> *splitsOut,
        float minOverlap)
{
  hkVector4f v10; // xmm1
  hkVector4f *p_A; // rax
  __m128 v12; // xmm5
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 m_quad; // xmm9
  hkSimdFloat32 *p_array; // rax
  __m128 m_real; // xmm0
  int m_faceB; // edx
  int *m_data; // rax
  __int64 index; // rsi
  __m128 v22; // xmm10
  __m128 v23; // xmm9
  __m128 v24; // xmm10
  __m128 v25; // xmm0
  __m128 v26; // xmm9
  __m128 v27; // xmm10
  hkArray<EdgeSplitInfo,hkContainerTempAllocator> *v28; // rbx
  float v29; // xmm13_4
  __int64 v30; // r15
  hkaiNavMesh::Face *v31; // rax
  hkArrayBase<hkVector4f> *v32; // r9
  hkVector4f *v33; // r11
  int v34; // edi
  hkaiNavMeshInstance *v35; // r12
  __m128 v36; // xmm11
  __m128 v37; // xmm7
  __m128 v38; // xmm12
  __m128 v39; // xmm1
  __m128 v40; // xmm6
  float v41; // xmm8_4
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  float v44; // xmm2_4
  float v45; // xmm4_4
  __m128 v46; // xmm1
  float v47; // xmm2_4
  __int64 v48; // rax
  __int128 v49; // xmm0
  __m128 array; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f B; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f A; // [rsp+60h] [rbp-A0h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f Bout; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f Aout; // [rsp+90h] [rbp-70h] BYREF
  hkAabb aabbOut; // [rsp+A0h] [rbp-60h] BYREF
  __int128 v57; // [rsp+D0h] [rbp-30h]
  hkResult result; // [rsp+1B0h] [rbp+B0h] BYREF

  v10.m_quad = (__m128)pair->m_z;
  p_A = &A;
  v12 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 238);
  v13 = _mm_shuffle_ps(v10.m_quad, (__m128)0i64, 238);
  if ( idx )
    p_A = &B;
  v14 = _mm_shuffle_ps(pair->m_x.m_quad, pair->m_y.m_quad, 68);
  v15 = _mm_shuffle_ps(v10.m_quad, (__m128)0i64, 68);
  A.m_quad = _mm_shuffle_ps(v14, v15, 136);
  array = _mm_shuffle_ps(v14, v15, 221);
  B.m_quad = _mm_shuffle_ps(v12, v13, 136);
  m_quad = p_A->m_quad;
  extraRadius.m_real = _mm_shuffle_ps(v12, v13, 221);
  p_array = (hkSimdFloat32 *)&array;
  if ( idx )
    p_array = &extraRadius;
  m_real = p_array->m_real;
  A.m_quad = m_quad;
  B.m_quad = m_real;
  if ( idx )
    m_faceB = pair->m_faceB;
  else
    m_faceB = pair->m_faceA;
  m_data = magic->m_data;
  idx = m_faceB;
  index = m_data[m_faceB];
  if ( (_DWORD)index != -2 )
  {
    v22 = m_quad;
    v23 = _mm_max_ps(m_quad, m_real);
    v24 = _mm_min_ps(v22, m_real);
    v25 = _mm_mul_ps((__m128)_xmm, up->m_quad);
    v26 = _mm_add_ps(v23, v25);
    v27 = _mm_sub_ps(v24, v25);
    if ( (int)index < magic->m_size )
    {
      v28 = splitsOut;
      v29 = minOverlap;
      v30 = index;
      do
      {
        if ( magic->m_data[v30] != m_faceB )
          break;
        v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
                *(hkaiNavMesh::Face **)&meshInstance[16],
                *(_DWORD *)&meshInstance[24],
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&meshInstance[240],
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&meshInstance[272],
                (hkArray<int,hkContainerHeapAllocator> *)&meshInstance[224],
                index);
        array.m128_u64[0] = (unsigned __int64)v33;
        array.m128_i32[2] = (int)v33;
        array.m128_i32[3] = 0x80000000;
        v34 = v31->m_numEdges + 1;
        v35 = (hkaiNavMeshInstance *)v31;
        if ( v34 <= 0 )
          result.m_enum = (int)v33;
        else
          hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v31->m_numEdges + 1, 16);
        array.m128_i32[2] = v34;
        hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(meshInstance, v35, (hkaiNavMesh::Face *)&array, v32);
        extraRadius.m_real = 0i64;
        hkaiNavMeshUtils::calcFaceAabb((hkArrayBase<hkVector4f> *)&array, &extraRadius, &aabbOut);
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v27, aabbOut.m_max.m_quad), _mm_cmple_ps(aabbOut.m_min.m_quad, v26))) & 7) == 7
          && hkaiPathProjectionUtil::projectSegmentOntoFaceAndClipEdgesWorldUp(
               (hkArrayBase<hkVector4f> *)&array,
               index,
               &A,
               &B,
               up,
               &Aout,
               &Bout) )
        {
          v36 = Aout.m_quad;
          LODWORD(v57) = index;
          v37 = _mm_sub_ps(B.m_quad, A.m_quad);
          v38 = Bout.m_quad;
          v39 = _mm_mul_ps(v37, A.m_quad);
          v40 = _mm_mul_ps(v37, v37);
          v41 = (float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
              + _mm_shuffle_ps(v39, v39, 170).m128_f32[0];
          v42 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                  _mm_shuffle_ps(v40, v40, 170));
          v43 = _mm_mul_ps(Aout.m_quad, v37);
          v44 = (float)(_mm_shuffle_ps(v43, v43, 85).m128_f32[0] + _mm_shuffle_ps(v43, v43, 0).m128_f32[0])
              + _mm_shuffle_ps(v43, v43, 170).m128_f32[0];
          v43.m128_f32[0] = _mm_rcp_ps(v42).m128_f32[0];
          v45 = (float)((float)(2.0 - (float)(v43.m128_f32[0] * v42.m128_f32[0])) * v43.m128_f32[0])
              * (float)(v44 - v41);
          v46 = _mm_mul_ps(Bout.m_quad, v37);
          aabbOut.m_min.m_quad.m128_f32[0] = v45;
          v47 = (float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + _mm_shuffle_ps(v46, v46, 0).m128_f32[0])
              + _mm_shuffle_ps(v46, v46, 170).m128_f32[0];
          v46.m128_f32[0] = _mm_rcp_ps(v42).m128_f32[0];
          aabbOut.m_min.m_quad.m128_f32[1] = (float)((float)(2.0 - (float)(v46.m128_f32[0] * v42.m128_f32[0]))
                                                   * v46.m128_f32[0])
                                           * (float)(v47 - v41);
          if ( (float)(aabbOut.m_min.m_quad.m128_f32[1] - v45) > v29 )
          {
            if ( v28->m_size == (v28->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v28, 64);
            v48 = (__int64)&v28->m_data[(__int64)v28->m_size];
            if ( v48 )
            {
              *(hkVector4f *)v48 = aabbOut.m_min;
              v49 = v57;
              *(__m128 *)(v48 + 16) = v36;
              *(__m128 *)(v48 + 32) = v38;
              *(_OWORD *)(v48 + 48) = v49;
            }
            ++v28->m_size;
          }
        }
        array.m128_i32[2] = 0;
        if ( array.m128_i32[3] >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            (void *)array.m128_u64[0],
            16 * array.m128_i32[3]);
        m_faceB = idx;
        LODWORD(index) = index + 1;
        ++v30;
        array.m128_i32[3] = 0x80000000;
        array.m128_u64[0] = 0i64;
      }
      while ( (int)index < magic->m_size );
    }
  }
}

// File Line: 872
// RVA: 0xBD28D0
void __fastcall splitPair1(
        hkaiStreamingCollection *collection,
        hkVector4f *up,
        hkaiNavMeshUtils *cutMesh,
        hkArrayBase<int> *magic,
        hkaiUserEdgeUtils::UserEdgePair *pair,
        int idx,
        _DWORD *minOverlap,
        hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs)
{
  __int64 v8; // r15
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  int v18; // r14d
  int v19; // edi
  _DWORD *v20; // rbx
  __m128 *v21; // rax
  __m128 *v22; // r12
  __m128 *v23; // r13
  __m128 *v24; // rcx
  __m128 v25; // xmm10
  __m128 v26; // xmm9
  __int64 v27; // rsi
  EdgeSplitInfo *m_data; // rax
  __int128 v29; // xmm0
  __m128 v30; // xmm1
  __int128 v31; // xmm0
  __m128 v32; // xmm1
  hkVector4f v33; // xmm0
  __m128 v34; // xmm1
  hkVector4f v35; // xmm1
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm8
  __m128 v39; // xmm6
  __m128 v40; // xmm7
  __m128 *v41; // rcx
  __m128 v42; // xmm0
  __int128 v43; // xmm1
  hkArray<EdgeSplitInfo,hkContainerTempAllocator> array; // [rsp+40h] [rbp-B8h] BYREF
  __m128 v45; // [rsp+50h] [rbp-A8h] BYREF
  __m128 v46; // [rsp+60h] [rbp-98h]
  _QWORD v47[9]; // [rsp+70h] [rbp-88h] BYREF
  __m128 v48; // [rsp+B8h] [rbp-40h] BYREF
  __int128 v49; // [rsp+C8h] [rbp-30h]
  __int128 v50[2]; // [rsp+D8h] [rbp-20h] BYREF
  __int128 v51[2]; // [rsp+F8h] [rbp+0h] BYREF
  __m128 *result; // [rsp+1C8h] [rbp+D0h] BYREF

  v8 = (__int64)result;
  v12 = *result;
  v13 = result[2];
  v14 = _mm_shuffle_ps(*result, result[1], 238);
  v15 = _mm_shuffle_ps(v13, (__m128)0i64, 238);
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v16 = _mm_shuffle_ps(v12, result[1], 68);
  v17 = _mm_shuffle_ps(v13, (__m128)0i64, 68);
  v51[0] = (__int128)_mm_shuffle_ps(v16, v17, 136);
  v51[1] = (__int128)_mm_shuffle_ps(v16, v17, 221);
  v50[0] = (__int128)_mm_shuffle_ps(v14, v15, 136);
  v50[1] = (__int128)_mm_shuffle_ps(v14, v15, 221);
  hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, &array, 16, 64);
  v18 = (int)pair;
  projectPair(cutMesh, up, magic, (hkaiUserEdgeUtils::UserEdgePair *)v8, (int)pair, &array, *(float *)&idx);
  v19 = 0;
  if ( array.m_size > 0 )
  {
    v20 = minOverlap;
    v21 = (__m128 *)v50;
    v22 = &v45;
    if ( v18 )
      v21 = (__m128 *)v51;
    v23 = (__m128 *)v47;
    if ( v18 )
      v22 = (__m128 *)v47;
    v24 = (__m128 *)&v48.m128_f32[2];
    v25 = *v21;
    v26 = _mm_sub_ps(v21[1], *v21);
    if ( v18 )
      v23 = &v45;
    if ( v18 )
      v24 = (__m128 *)&v48.m128_f32[3];
    v27 = 0i64;
    result = v24;
    do
    {
      m_data = array.m_data;
      v29 = *(_OWORD *)v8;
      *(_OWORD *)&v47[5] = *(_OWORD *)(v8 + 16);
      v30 = *(__m128 *)(v8 + 48);
      *(_OWORD *)&v47[3] = v29;
      v31 = *(_OWORD *)(v8 + 32);
      v48 = v30;
      v32 = (__m128)(unsigned int)FLOAT_1_0;
      v32.m128_f32[0] = 1.0 - array.m_data[v27].m_t1;
      *(_OWORD *)&v47[7] = v31;
      v49 = *(_OWORD *)(v8 + 64);
      v33.m_quad = (__m128)array.m_data[v27].m_start;
      *v22 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v26), v25);
      v34 = (__m128)(unsigned int)FLOAT_1_0;
      v34.m128_f32[0] = 1.0 - m_data[v27].m_t0;
      v22[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v26), v25);
      v35.m_quad = (__m128)m_data[v27].m_end;
      v24->m128_i32[0] = m_data[v27].m_faceIndex;
      LODWORD(m_data) = v20[3];
      v23[1] = v35.m_quad;
      *(hkVector4f *)v23 = (hkVector4f)v33.m_quad;
      v36 = _mm_shuffle_ps(*(__m128 *)v47, *(__m128 *)&v47[1], 68);
      v37 = _mm_shuffle_ps(v45, v46, 68);
      v38 = _mm_shuffle_ps(v36, v37, 136);
      v39 = _mm_shuffle_ps(v36, v37, 221);
      v40 = _mm_shuffle_ps(_mm_shuffle_ps(*(__m128 *)v47, *(__m128 *)&v47[1], 238), _mm_shuffle_ps(v45, v46, 238), 136);
      if ( v20[2] == ((unsigned int)m_data & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v20, 80);
      v41 = (__m128 *)(*(_QWORD *)v20 + 80i64 * (int)v20[2]);
      if ( v41 )
      {
        v42 = v48;
        v43 = v49;
        *v41 = v38;
        v41[1] = v39;
        v41[2] = v40;
        v41[3] = v42;
        v41[4] = (__m128)v43;
      }
      ++v20[2];
      v24 = result;
      ++v19;
      ++v27;
    }
    while ( v19 < array.m_size );
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      array.m_capacityAndFlags << 6);
}

// File Line: 905
// RVA: 0xBD2C40
void __fastcall splitPair2(
        hkaiStreamingCollection *collection,
        hkVector4f *up,
        hkaiNavMeshUtils *meshInstanceA,
        hkaiNavMeshUtils *meshInstanceB,
        hkArrayBase<int> *magicA,
        hkArrayBase<int> *magicB,
        hkaiUserEdgeUtils::UserEdgePair *pair,
        float minOverlapA,
        _DWORD *minOverlapB,
        hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs)
{
  hkArrayBase<int> *v10; // r12
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v17; // xmm13
  __m128 v18; // xmm7
  __m128 v19; // xmm13
  __m128 v20; // xmm15
  __m128 v21; // xmm13
  __m128 v22; // xmm14
  __m128 v23; // xmm7
  __m128 v24; // xmm15
  __m128 v25; // xmm14
  float v26; // xmm12_4
  float v27; // xmm11_4
  int m_size; // eax
  int v29; // r15d
  _DWORD *v30; // rdi
  EdgeSplitInfo *m_data; // rdx
  __int64 v32; // rsi
  int v33; // r14d
  __int64 v34; // rbx
  float v35; // xmm5_4
  float v36; // xmm6_4
  hkArrayBase<int> v37; // xmm1
  int m_faceIndex; // eax
  hkArrayBase<int> v39; // xmm10
  hkArrayBase<int> v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm0
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm4
  __m128 v50; // xmm6
  __m128 v51; // xmm0
  __m128 v52; // xmm9
  __m128 v53; // xmm6
  __m128 v54; // xmm7
  __m128 *v55; // rcx
  __int128 v56; // xmm0
  hkArray<EdgeSplitInfo,hkContainerTempAllocator> array; // [rsp+48h] [rbp-B0h] BYREF
  hkArray<EdgeSplitInfo,hkContainerTempAllocator> splitsOut; // [rsp+58h] [rbp-A0h] BYREF
  _QWORD v59[7]; // [rsp+70h] [rbp-88h]
  __int128 v60; // [rsp+A8h] [rbp-50h]
  hkArrayBase<int> *magic; // [rsp+1B8h] [rbp+C0h]

  v10 = magicB;
  v12 = (__m128)magicB[2];
  v13 = _mm_shuffle_ps(v12, (__m128)0i64, 238);
  v14 = _mm_shuffle_ps(v12, (__m128)0i64, 68);
  v17 = *(__m128 *)magicB;
  array.m_data = 0i64;
  array.m_size = 0;
  v18 = v17;
  v19 = _mm_shuffle_ps(v17, (__m128)magicB[1], 238);
  array.m_capacityAndFlags = 0x80000000;
  v20 = v19;
  v21 = _mm_shuffle_ps(v19, v13, 221);
  v22 = _mm_shuffle_ps(v18, (__m128)magicB[1], 68);
  v23 = _mm_shuffle_ps(v22, v14, 221);
  v24 = _mm_shuffle_ps(v20, v13, 136);
  v25 = _mm_shuffle_ps(v22, v14, 136);
  *(__m128 *)v59 = v23;
  hkArrayUtil::_reserve((hkResult *)&magicB, &hkContainerTempAllocator::s_alloc, &array, 16, 64);
  splitsOut.m_data = 0i64;
  splitsOut.m_size = 0;
  splitsOut.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve((hkResult *)&magicB, &hkContainerTempAllocator::s_alloc, &splitsOut, 16, 64);
  v26 = *(float *)&pair;
  projectPair(meshInstanceA, up, magic, (hkaiUserEdgeUtils::UserEdgePair *)v10, 0, &array, *(float *)&pair);
  if ( array.m_size
    && (v27 = minOverlapA,
        projectPair(meshInstanceB, up, magicA, (hkaiUserEdgeUtils::UserEdgePair *)v10, 1, &splitsOut, minOverlapA),
        m_size = array.m_size,
        v29 = 0,
        array.m_size > 0) )
  {
    v30 = minOverlapB;
    m_data = array.m_data;
    v32 = 0i64;
    do
    {
      v33 = 0;
      if ( splitsOut.m_size > 0 )
      {
        v34 = 0i64;
        do
        {
          if ( m_data[v32].m_t1 > m_data[v32].m_t0 && splitsOut.m_data[v34].m_t1 > splitsOut.m_data[v34].m_t0 )
          {
            *(float *)&magicB = 1.0 - splitsOut.m_data[v34].m_t1;
            v35 = fmaxf(m_data[v32].m_t0, *(float *)&magicB);
            *(float *)&magicB = 1.0 - splitsOut.m_data[v34].m_t0;
            v36 = fminf(m_data[v32].m_t1, *(float *)&magicB);
            *(float *)&magicB = v26;
            if ( (float)(v36 - v35) > fmaxf(v26, v27) )
            {
              v37 = v10[1];
              m_faceIndex = m_data[v32].m_faceIndex;
              v39 = v10[4];
              *(hkArrayBase<int> *)&v59[1] = *v10;
              v40 = v10[2];
              *(hkArrayBase<int> *)&v59[3] = v37;
              v41 = (__m128)v10[3];
              *(hkArrayBase<int> *)&v59[5] = v40;
              v60 = (__int128)v41;
              v42 = (__m128)(unsigned int)FLOAT_1_0;
              v41.m128_f32[0] = v36;
              DWORD2(v60) = m_faceIndex;
              v42.m128_f32[0] = 1.0 - v36;
              v43 = _mm_sub_ps(v23, v25);
              HIDWORD(v60) = splitsOut.m_data[v34].m_faceIndex;
              v44 = (__m128)(unsigned int)FLOAT_1_0;
              v44.m128_f32[0] = 1.0 - v35;
              v45 = _mm_sub_ps(v21, v24);
              v23.m128_f32[0] = v35;
              v46 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v43), v25);
              v47 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v43), v25);
              v48 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v45), v24);
              v49 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v45), v24);
              v50 = _mm_shuffle_ps(v47, v46, 68);
              v51 = _mm_shuffle_ps(v48, v49, 68);
              v52 = _mm_shuffle_ps(v50, v51, 136);
              v53 = _mm_shuffle_ps(v50, v51, 221);
              v54 = _mm_shuffle_ps(_mm_shuffle_ps(v47, v46, 238), _mm_shuffle_ps(v48, v49, 238), 136);
              if ( v30[2] == (v30[3] & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v30, 80);
                m_data = array.m_data;
              }
              v55 = (__m128 *)(*(_QWORD *)v30 + 80i64 * (int)v30[2]);
              if ( v55 )
              {
                v56 = v60;
                *v55 = v52;
                v55[1] = v53;
                v55[2] = v54;
                v55[3] = (__m128)v56;
                v55[4] = (__m128)v39;
                m_data = array.m_data;
              }
              ++v30[2];
              v23 = *(__m128 *)v59;
            }
          }
          ++v33;
          ++v34;
        }
        while ( v33 < splitsOut.m_size );
        m_size = array.m_size;
      }
      ++v29;
      ++v32;
    }
    while ( v29 < m_size );
  }
  else
  {
    m_data = array.m_data;
  }
  splitsOut.m_size = 0;
  if ( splitsOut.m_capacityAndFlags >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      splitsOut.m_data,
      splitsOut.m_capacityAndFlags << 6);
    m_data = array.m_data;
  }
  splitsOut.m_data = 0i64;
  array.m_size = 0;
  splitsOut.m_capacityAndFlags = 0x80000000;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      m_data,
      array.m_capacityAndFlags << 6);
}

// File Line: 960
// RVA: 0xBD3150
void __fastcall splitPairsOnCutMesh(
        hkaiStreamingCollection *collection,
        hkaiUserEdgeUtils::UserEdgePair *pair,
        hkaiNavMeshCutter *cutter,
        int secIdxA,
        int secIdxB,
        float minEdgeLength,
        hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *newPairs)
{
  __int128 v7; // xmm8
  __int64 v10; // rdx
  hkaiStreamingCollection::InstanceInfo *m_data; // r9
  hkaiNavMeshUtils *m_instancePtr; // rdi
  hkaiNavMeshUtils *v13; // r11
  hkaiNavMeshCutter::MeshInfo *v14; // rax
  hkArrayBase<int> *magicA; // r9
  hkArrayBase<int> *magicB; // rdx
  int v17; // ebp
  int v18; // r8d
  hkVector4f v19; // xmm1
  hkVector4f v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm9
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm9
  __m128 v37; // xmm0
  __m128 minOverlapA; // xmm0
  unsigned int v39; // xmm1_4
  hkaiUserEdgeUtils::UserEdgePair *v40; // rcx
  hkaiUserEdgeUtils::UserEdgePair *paira; // [rsp+30h] [rbp-78h]
  _DWORD *minOverlapB; // [rsp+40h] [rbp-68h]
  hkVector4f up; // [rsp+50h] [rbp-58h] BYREF
  __int128 v44; // [rsp+70h] [rbp-38h]

  if ( secIdxA != -1 && secIdxB != -1 )
  {
    v10 = secIdxA;
    m_data = collection->m_instances.m_data;
    m_instancePtr = (hkaiNavMeshUtils *)m_data[v10].m_instancePtr;
    v13 = (hkaiNavMeshUtils *)m_data[secIdxB].m_instancePtr;
    if ( m_instancePtr )
    {
      if ( v13 )
      {
        v14 = cutter->m_meshInfos.m_data;
        magicA = &v14[v10].m_magic;
        magicB = &v14[secIdxB].m_magic;
        v17 = magicA->m_data[pair->m_faceA];
        if ( v17 != -2 )
        {
          v18 = magicB->m_data[pair->m_faceB];
          if ( v18 != -2 )
          {
            up.m_quad = (__m128)cutter->m_up;
            v19.m_quad = (__m128)pair->m_z;
            v20.m_quad = (__m128)pair->m_x;
            v44 = v7;
            v21 = _mm_shuffle_ps(v20.m_quad, pair->m_y.m_quad, 238);
            v22 = _mm_shuffle_ps(v20.m_quad, pair->m_y.m_quad, 68);
            v23 = _mm_shuffle_ps(v19.m_quad, (__m128)0i64, 238);
            v24 = _mm_shuffle_ps(v19.m_quad, (__m128)0i64, 68);
            v25 = _mm_sub_ps(_mm_shuffle_ps(v21, v23, 136), _mm_shuffle_ps(v21, v23, 221));
            v26 = _mm_sub_ps(_mm_shuffle_ps(v22, v24, 136), _mm_shuffle_ps(v22, v24, 221));
            v27 = _mm_mul_ps(v25, v25);
            v28 = _mm_mul_ps(v26, v26);
            v29 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                    _mm_shuffle_ps(v28, v28, 170));
            v30 = _mm_rsqrt_ps(v29);
            v31 = _mm_andnot_ps(
                    _mm_cmple_ps(v29, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v30), v30)),
                        _mm_mul_ps(*(__m128 *)_xmm, v30)),
                      v29));
            v32 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                    _mm_shuffle_ps(v27, v27, 170));
            v33 = _mm_rsqrt_ps(v32);
            v34 = _mm_andnot_ps(
                    _mm_cmple_ps(v32, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v33), v33)),
                        _mm_mul_ps(*(__m128 *)_xmm, v33)),
                      v32));
            v35 = _mm_shuffle_ps((__m128)LODWORD(minEdgeLength), (__m128)LODWORD(minEdgeLength), 0);
            v36 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v34), 196);
            if ( !_mm_movemask_ps(_mm_cmplt_ps(v36, v35)) )
            {
              v37 = _mm_rcp_ps(v36);
              minOverlapA = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v37)), v37), v35);
              v39 = _mm_shuffle_ps(minOverlapA, minOverlapA, 255).m128_u32[0];
              if ( v17 == -1 )
              {
                if ( v18 == -1 )
                {
                  if ( newPairs->m_size == (newPairs->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, newPairs, 80);
                  v40 = &newPairs->m_data[newPairs->m_size];
                  if ( v40 )
                  {
                    v40->m_x = pair->m_x;
                    v40->m_y = pair->m_y;
                    v40->m_z = pair->m_z;
                    *(_OWORD *)&v40->m_instanceUidA = *(_OWORD *)&pair->m_instanceUidA;
                    *(_OWORD *)&v40->m_userDataA = *(_OWORD *)&pair->m_userDataA;
                  }
                  ++newPairs->m_size;
                }
                else
                {
                  LODWORD(paira) = v39;
                  splitPair1(collection, &up, v13, magicB, pair, 1, paira, newPairs);
                }
              }
              else if ( v18 == -1 )
              {
                LODWORD(paira) = minOverlapA.m128_i32[0];
                splitPair1(collection, &up, m_instancePtr, magicA, pair, 0, paira, newPairs);
              }
              else
              {
                LODWORD(minOverlapB) = v39;
                splitPair2(
                  collection,
                  &up,
                  m_instancePtr,
                  v13,
                  magicA,
                  magicB,
                  pair,
                  minOverlapA.m128_f32[0],
                  minOverlapB,
                  newPairs);
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
void __fastcall hkaiUserEdgeUtils::selectiveAddUserEdgePairsToCutMesh(
        hkaiStreamingCollection *collection,
        hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *pairs,
        hkaiNavMeshCutter *cutter,
        hkArrayBase<unsigned int> *cutFaceKeys,
        hkArrayBase<unsigned int> *uncutFaceKeys,
        hkaiUserEdgeUtils::CutMeshUpdateParameters *params)
{
  hkArrayBase<unsigned int> *v6; // rsi
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *v7; // r13
  hkaiStreamingCollection *v8; // r15
  __int64 v9; // r12
  int v10; // r8d
  int v12; // ebx
  __int64 v13; // rdi
  int v14; // ebx
  __int64 v15; // rdi
  int m_size; // ebx
  int v17; // edi
  hkLifoAllocator *Value; // rax
  IAmdDxExtQuadBufferStereo *m_cur; // rdx
  int v20; // ecx
  char *v21; // r8
  int v22; // r9d
  __int64 v23; // rcx
  IAmdDxExtQuadBufferStereo *v24; // rdi
  int v25; // r14d
  hkaiUserEdgeUtils::UserEdgePair *v26; // rsi
  __int64 SectionIdByUid; // r13
  int v28; // eax
  int v29; // r15d
  unsigned int v30; // ebx
  int v31; // edi
  int v32; // eax
  int sizeElem; // [rsp+20h] [rbp-59h]
  hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> newPairs; // [rsp+40h] [rbp-39h] BYREF
  AMD_HD3D v35; // [rsp+50h] [rbp-29h] BYREF
  IAmdDxExtQuadBufferStereo *v36; // [rsp+70h] [rbp-9h]
  int v37; // [rsp+78h] [rbp-1h]
  int v38; // [rsp+80h] [rbp+7h]

  v6 = uncutFaceKeys;
  v7 = pairs;
  v8 = collection;
  v9 = 0i64;
  v10 = cutFaceKeys->m_size + uncutFaceKeys->m_size;
  *(_QWORD *)&v35.mEnableStereo = 0i64;
  v35.mWidth = 0;
  v35.mHeight = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
    &hkContainerHeapAllocator::s_alloc,
    v10);
  v12 = 0;
  if ( cutFaceKeys->m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
        &hkContainerHeapAllocator::s_alloc,
        cutFaceKeys->m_data[v13],
        1ui64);
      ++v12;
      ++v13;
    }
    while ( v12 < cutFaceKeys->m_size );
  }
  v14 = 0;
  if ( v6->m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
        &hkContainerHeapAllocator::s_alloc,
        v6->m_data[v15],
        1ui64);
      ++v14;
      ++v15;
    }
    while ( v14 < v6->m_size );
  }
  m_size = v8->m_instances.m_size;
  v35.mStereo = 0i64;
  v35.mExtension = (IAmdDxExt *)0x8000000000000000i64;
  v17 = (m_size + 31) >> 5;
  v37 = v17;
  if ( v17 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (IAmdDxExtQuadBufferStereo *)Value->m_cur;
    v20 = (4 * v17 + 127) & 0xFFFFFF80;
    v21 = (char *)m_cur + v20;
    if ( v20 > Value->m_slabSize || v21 > Value->m_end )
      m_cur = (IAmdDxExtQuadBufferStereo *)hkLifoAllocator::allocateFromNewSlab(Value, v20);
    else
      Value->m_cur = v21;
  }
  else
  {
    m_cur = 0i64;
  }
  v35.mStereo = m_cur;
  v36 = m_cur;
  v38 = m_size;
  HIDWORD(v35.mExtension) = v17 | 0x80000000;
  if ( (v17 & 0x3FFFFFFF) < v17 )
  {
    v22 = (m_size + 31) >> 5;
    if ( v17 < 2 * (v17 & 0x3FFFFFFF) )
      v22 = 2 * (v17 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&uncutFaceKeys, &hkContainerHeapAllocator::s_alloc, &v35.mStereo, v22, 4);
    m_cur = v35.mStereo;
  }
  LODWORD(v35.mExtension) = (m_size + 31) >> 5;
  if ( v17 - 1 >= 0 )
  {
    v23 = (unsigned int)v17;
    v24 = m_cur;
    while ( v23 )
    {
      LODWORD(v24->vfptr) = 0;
      v24 = (IAmdDxExtQuadBufferStereo *)((char *)v24 + 4);
      --v23;
    }
  }
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  newPairs.m_capacityAndFlags = 0x80000000;
  v25 = 0;
  if ( v7->m_size > 0 )
  {
    do
    {
      v26 = &v7->m_data[v9];
      SectionIdByUid = (int)hkaiStreamingCollection::findSectionIdByUid(v8, v26->m_instanceUidA);
      v28 = hkaiStreamingCollection::findSectionIdByUid(v8, v26->m_instanceUidB);
      v29 = v28;
      if ( (_DWORD)SectionIdByUid == -1
        || v28 == -1
        || (*((_DWORD *)&v35.mStereo->vfptr + (SectionIdByUid >> 5)) |= 1 << (SectionIdByUid & 0x1F),
            *((_DWORD *)&v35.mStereo->vfptr + ((__int64)v28 >> 5)) |= 1 << (v28 & 0x1F),
            v30 = (v28 << 22) | v26->m_faceB,
            v31 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
                    (unsigned int)(((_DWORD)SectionIdByUid << 22) | v26->m_faceA),
                    0i64),
            v32 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
                    v30,
                    0i64),
            !v31)
        && !v32 )
      {
        v8 = collection;
      }
      else
      {
        sizeElem = v29;
        v8 = collection;
        splitPairsOnCutMesh(collection, v26, cutter, SectionIdByUid, sizeElem, params->m_minEdgeLength, &newPairs);
      }
      v7 = pairs;
      ++v25;
      ++v9;
    }
    while ( v25 < pairs->m_size );
  }
  hkaiUserEdgeUtils::addUserEdgePairsBatch(v8, &newPairs, params);
  newPairs.m_size = 0;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      80 * (newPairs.m_capacityAndFlags & 0x3FFFFFFF));
  newPairs.m_data = 0i64;
  newPairs.m_capacityAndFlags = 0x80000000;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&v35.mStereo);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
    &hkContainerHeapAllocator::s_alloc);
  _(&v35);
}

// File Line: 1108
// RVA: 0xBD12D0
void __fastcall hkaiUserEdgeUtils::addUserEdgePairsToCutMesh(
        hkaiStreamingCollection *collection,
        hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *pairs,
        hkaiNavMeshCutter *cutter,
        hkaiUserEdgeUtils::CutMeshUpdateParameters *params)
{
  hkaiUserEdgeUtils::UpdateParameters *v4; // rbx
  int m_size; // ebx
  __int64 v6; // rsi
  int v7; // edi
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rdx
  int v12; // ecx
  char *v13; // r8
  int v14; // r9d
  __int64 v15; // rcx
  unsigned int *v16; // rdi
  int v17; // ebx
  hkaiUserEdgeUtils::UserEdgePair *v18; // r14
  __int64 SectionIdByUid; // r13
  __int64 v20; // r10
  hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> newPairs; // [rsp+30h] [rbp-19h] BYREF
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+40h] [rbp-9h] BYREF
  hkResult result; // [rsp+B0h] [rbp+67h] BYREF
  hkaiNavMeshCutter *cuttera; // [rsp+C0h] [rbp+77h]
  hkaiUserEdgeUtils::UpdateParameters *paramsa; // [rsp+C8h] [rbp+7Fh]

  paramsa = v4;
  m_size = collection->m_instances.m_size;
  v6 = 0i64;
  v7 = (m_size + 31) >> 5;
  array.m_words.m_data = 0i64;
  array.m_words.m_size = 0;
  array.m_words.m_capacityAndFlags = 0x80000000;
  array.m_words.m_initialCapacity = v7;
  if ( v7 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (unsigned int *)Value->m_cur;
    v12 = (4 * v7 + 127) & 0xFFFFFF80;
    v13 = (char *)m_cur + v12;
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
      m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
    else
      Value->m_cur = v13;
  }
  else
  {
    m_cur = 0i64;
  }
  array.m_words.m_data = m_cur;
  array.m_words.m_localMemory = m_cur;
  array.m_numBits = m_size;
  array.m_words.m_capacityAndFlags = v7 | 0x80000000;
  if ( (v7 & 0x3FFFFFFF) < v7 )
  {
    v14 = (m_size + 31) >> 5;
    if ( v7 < 2 * (v7 & 0x3FFFFFFF) )
      v14 = 2 * (v7 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v14, 4);
    m_cur = array.m_words.m_data;
  }
  array.m_words.m_size = (m_size + 31) >> 5;
  if ( v7 - 1 >= 0 )
  {
    v15 = (unsigned int)v7;
    v16 = m_cur;
    while ( v15 )
    {
      *v16++ = 0;
      --v15;
    }
  }
  v17 = 0;
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  for ( newPairs.m_capacityAndFlags = 0x80000000; v17 < pairs->m_size; ++v6 )
  {
    v18 = &pairs->m_data[v6];
    SectionIdByUid = (int)hkaiStreamingCollection::findSectionIdByUid(collection, v18->m_instanceUidA);
    v20 = (int)hkaiStreamingCollection::findSectionIdByUid(collection, v18->m_instanceUidB);
    if ( (_DWORD)SectionIdByUid != -1 && (_DWORD)v20 != -1 )
    {
      newPairs.m_data = (hkaiUserEdgeUtils::UserEdgePair *)&newPairs;
      array.m_words.m_data[SectionIdByUid >> 5] |= 1 << (SectionIdByUid & 0x1F);
      array.m_words.m_data[v20 >> 5] |= 1 << (v20 & 0x1F);
      splitPairsOnCutMesh(
        collection,
        v18,
        cuttera,
        SectionIdByUid,
        v20,
        *(float *)&paramsa[1].m_updateHierarchyGraphs.m_bool,
        (hkArray<hkaiUserEdgeUtils::UserEdgePair,hkContainerHeapAllocator> *)newPairs.m_data);
    }
    ++v17;
  }
  hkaiUserEdgeUtils::addUserEdgePairsBatch(collection, &newPairs, paramsa);
  newPairs.m_size = 0;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      80 * (newPairs.m_capacityAndFlags & 0x3FFFFFFF));
  newPairs.m_data = 0i64;
  newPairs.m_capacityAndFlags = 0x80000000;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
}

// File Line: 1143
// RVA: 0xBD1880
void __fastcall hkaiUserEdgeUtils::removeUserEdges(
        hkaiNavMeshInstance *meshInstance,
        hkaiStreamingCollection *collection)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  int m_numOriginalFaces; // ebx
  int v10; // ebp
  int index; // r11d
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r8
  __int64 v13; // r14
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r9
  int v15; // r11d
  __int64 v16; // rax
  int v17; // ecx
  int v18; // ecx
  _QWORD *v19; // rax
  _QWORD *v20; // rcx
  _QWORD *v21; // r8
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+30h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtremoveUserEdges";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  m_numOriginalFaces = meshInstance->m_numOriginalFaces;
  v10 = 0;
  index = 0;
  if ( m_numOriginalFaces + meshInstance->m_ownedFaces.m_size > 0 )
  {
    p_m_instancedFaces = &meshInstance->m_instancedFaces;
    v13 = 0i64;
    p_m_ownedFaces = &meshInstance->m_ownedFaces;
    do
    {
      if ( hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
             meshInstance->m_originalFaces,
             m_numOriginalFaces,
             p_m_instancedFaces,
             p_m_ownedFaces,
             &meshInstance->m_faceMap,
             index)->m_numUserEdges > 0 )
      {
        if ( v15 < m_numOriginalFaces )
        {
          if ( meshInstance->m_faceMap.m_size )
            v17 = meshInstance->m_faceMap.m_data[v13];
          else
            v17 = v15;
          if ( v17 == -1 )
            v16 = 0i64;
          else
            v16 = (__int64)&p_m_instancedFaces->m_data[v17];
        }
        else
        {
          v16 = (__int64)&p_m_ownedFaces->m_data[v15 - m_numOriginalFaces];
        }
        v18 = *(__int16 *)(v16 + 10);
        *(_DWORD *)(v16 + 4) = -1;
        *(_WORD *)(v16 + 10) = 0;
        v10 += v18;
      }
      m_numOriginalFaces = meshInstance->m_numOriginalFaces;
      index = v15 + 1;
      ++v13;
    }
    while ( index < m_numOriginalFaces + meshInstance->m_ownedFaces.m_size );
    if ( v10 > 0 )
    {
      facesToRemove.m_data = 0i64;
      facesToRemove.m_size = 0;
      facesToRemove.m_capacityAndFlags = 0x80000000;
      hkaiNavMeshUtils::removeOwnedFaces(meshInstance, collection, &facesToRemove, ALWAYS_COMPACT);
      facesToRemove.m_size = 0;
      if ( facesToRemove.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
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
    v23 = v20 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v21[1] = v23;
  }
}

// File Line: 1169
// RVA: 0xBD1B50
__int64 __fastcall hkaiUserEdgeUtils::removeUserEdgesFromFace(
        hkaiStreamingCollection *collection,
        unsigned int faceKey,
        hkaiUserEdgeUtils::RemoveParameters *params)
{
  hkaiNavMeshInstance *m_instancePtr; // r14
  int m_numOriginalFaces; // edi
  hkaiNavMesh::Face *v6; // rax
  _QWORD *v7; // r8
  _QWORD *v8; // r9
  int v9; // r11d
  int m_numUserEdges; // edx
  __int64 v11; // r13
  int v12; // r12d
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r10
  unsigned int v16; // ebx
  int v17; // r15d
  hkaiNavMesh::Edge *v18; // rsi
  unsigned int m_oppositeFace; // eax
  char v20; // dl
  unsigned int v21; // ecx
  int v22; // ebp
  bool v23; // zf
  unsigned int m_oppositeEdge; // eax
  int v25; // edi
  hkaiUserEdgeUtils::RemoveParameters *v26; // rax
  unsigned int v27; // edx
  int m_runtimeId; // eax
  int v29; // edx
  hkaiNavMeshInstance *v30; // r8
  int m_numOriginalEdges; // eax
  __int64 v32; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  hkaiNavMesh::Edge *v34; // rdx
  int index; // [rsp+28h] [rbp-60h]
  hkaiNavMesh::Face *v36; // [rsp+38h] [rbp-50h]
  int v40; // [rsp+A8h] [rbp+20h]

  m_instancePtr = collection->m_instances.m_data[faceKey >> 22].m_instancePtr;
  if ( !m_instancePtr )
    return 0i64;
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__4(
         m_instancePtr->m_originalFaces,
         m_numOriginalFaces,
         &m_instancePtr->m_instancedFaces,
         &m_instancePtr->m_ownedFaces,
         &m_instancePtr->m_faceMap,
         faceKey & 0x3FFFFF);
  v36 = v6;
  m_numUserEdges = v6->m_numUserEdges;
  v40 = m_numUserEdges;
  if ( v6->m_numUserEdges > 0 )
  {
    if ( v9 < m_numOriginalFaces )
    {
      if ( m_instancePtr->m_faceMap.m_size )
        v9 = m_instancePtr->m_faceMap.m_data[v9];
      if ( v9 == -1 )
        v11 = 0i64;
      else
        v11 = *v7 + 16i64 * v9;
    }
    else
    {
      v11 = *v8 + 16i64 * (v9 - m_numOriginalFaces);
    }
    v12 = 0;
    if ( m_numUserEdges > 0 )
    {
      instanceMap = &m_instancePtr->m_edgeMap;
      p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
      p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
      while ( 1 )
      {
        v16 = m_instancePtr->m_runtimeId << 22;
        index = v12 + v6->m_startUserEdgeIndex;
        v17 = index | v16;
        v18 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__4(
                m_instancePtr->m_originalEdges,
                m_instancePtr->m_numOriginalEdges,
                p_m_instancedEdges,
                p_m_ownedEdges,
                instanceMap,
                index);
        m_oppositeFace = v18->m_oppositeFace;
        v20 = v18->m_flags.m_storage & 0x40;
        if ( v20 )
          v21 = m_oppositeFace & 0xFFC00000;
        else
          v21 = v16;
        v22 = v21 | m_oppositeFace & 0x3FFFFF;
        v23 = m_oppositeFace == -1;
        m_oppositeEdge = v18->m_oppositeEdge;
        if ( v23 )
          v22 = -1;
        if ( v20 )
          v16 = m_oppositeEdge & 0xFFC00000;
        v25 = v16 | m_oppositeEdge & 0x3FFFFF;
        v23 = m_oppositeEdge == -1;
        v26 = params;
        if ( v23 )
          v25 = -1;
        if ( params->m_updateHierarchyGraphs.m_bool )
        {
          hkaiGraphUtils::removeDirectedGraphEdgeForUserEdge(faceKey, v17, collection);
          v26 = params;
        }
        if ( v18->m_oppositeEdge == -1 )
          goto LABEL_41;
        if ( v26->m_updateHierarchyGraphs.m_bool )
          hkaiGraphUtils::removeDirectedGraphEdgeForUserEdge(v22, v25, collection);
        v27 = v18->m_oppositeEdge;
        if ( (v18->m_flags.m_storage & 0x40) != 0 )
          m_runtimeId = v27 >> 22;
        else
          m_runtimeId = m_instancePtr->m_runtimeId;
        if ( v27 == -1 )
          m_runtimeId = -1;
        v29 = v27 & 0x3FFFFF;
        v30 = collection->m_instances.m_data[m_runtimeId].m_instancePtr;
        m_numOriginalEdges = v30->m_numOriginalEdges;
        if ( v29 >= m_numOriginalEdges )
          break;
        if ( v30->m_edgeMap.m_size )
          v29 = v30->m_edgeMap.m_data[v29];
        if ( v29 != -1 )
        {
          v32 = v29;
          m_data = v30->m_instancedEdges.m_data;
          goto LABEL_39;
        }
        v34 = 0i64;
LABEL_40:
        v34->m_oppositeFace = -1;
        v34->m_oppositeEdge = -1;
LABEL_41:
        v6 = v36;
        ++v12;
        instanceMap = &m_instancePtr->m_edgeMap;
        p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
        p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
        if ( v12 >= v36->m_numUserEdges )
        {
          m_numUserEdges = v40;
          goto LABEL_43;
        }
      }
      v32 = v29 - m_numOriginalEdges;
      m_data = v30->m_ownedEdges.m_data;
LABEL_39:
      v34 = &m_data[v32];
      goto LABEL_40;
    }
LABEL_43:
    *(_DWORD *)(v11 + 4) = -1;
    *(_WORD *)(v11 + 10) = 0;
  }
  return (unsigned int)m_numUserEdges;
}

// File Line: 1224
// RVA: 0xBD1A60
__int64 __fastcall hkaiUserEdgeUtils::removeUserEdgesFromFaces(
        hkaiStreamingCollection *collection,
        hkArrayBase<unsigned int> *faceKeys,
        hkaiUserEdgeUtils::RemoveParameters *params)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  unsigned int v11; // ebx
  int v12; // edi
  __int64 v13; // rsi
  int v14; // eax
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtremoveUserEdgesFromFaces";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  v11 = 0;
  v12 = 0;
  if ( faceKeys->m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = hkaiUserEdgeUtils::removeUserEdgesFromFace(collection, faceKeys->m_data[v13], params);
      ++v12;
      ++v13;
      v11 += v14;
    }
    while ( v12 < faceKeys->m_size );
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = v16 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v17[1] = v19;
  }
  return v11;
}

