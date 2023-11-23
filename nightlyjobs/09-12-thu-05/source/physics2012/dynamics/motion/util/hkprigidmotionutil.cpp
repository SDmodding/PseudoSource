// File Line: 26
// RVA: 0xD90B40
hkSimdFloat32 *__fastcall calcVelocityForDeactivation(
        hkSimdFloat32 *result,
        hkpMotion *motion,
        hkSimdFloat32 *objectRadius)
{
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm4

  v3 = result;
  v4 = _mm_mul_ps(motion->m_angularVelocity.m_quad, motion->m_angularVelocity.m_quad);
  v5 = _mm_mul_ps(motion->m_linearVelocity.m_quad, motion->m_linearVelocity.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                         _mm_shuffle_ps(v4, v4, 170)),
                       _mm_mul_ps(objectRadius->m_real, objectRadius->m_real)),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)),
                       _mm_shuffle_ps(v5, v5, 170)));
  return v3;
}

// File Line: 153
// RVA: 0xD909F0
char __fastcall hkRigidMotionUtilCanDeactivateFinal(
        hkStepInfo *info,
        hkpMotion *const *motions,
        int numMotions,
        int motionOffset)
{
  int v4; // r10d
  __int64 v5; // r8
  float v6; // xmm5_4
  float v7; // xmm5_4
  __int64 v8; // r9
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  float v12; // xmm4_4
  __m128 v13; // xmm0

  v4 = numMotions - 1;
  if ( numMotions - 1 < 0 )
    return 1;
  v5 = motionOffset;
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0).m128_f32[0];
  v7 = v6 * v6;
  while ( 1 )
  {
    v8 = (__int64)*motions;
    v9 = _mm_mul_ps(
           *(__m128 *)((char *)&(*motions)->m_angularVelocity.m_quad + v5),
           *(__m128 *)((char *)&(*motions)->m_angularVelocity.m_quad + v5));
    v10 = (__m128)COERCE_UNSIGNED_INT(fminf(1.0, *(float *)((char *)&(*motions)->m_motionState.m_objectRadius + v5)));
    v11 = _mm_mul_ps(*(__m128 *)(v5 + v8 + 224), *(__m128 *)(v5 + v8 + 224));
    v10.m128_f32[0] = _mm_shuffle_ps(v10, v10, 0).m128_f32[0];
    v12 = (float)((float)((float)((float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0]
                                                + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
                                        + _mm_shuffle_ps(v9, v9, 170).m128_f32[0])
                                * (float)(v10.m128_f32[0] * v10.m128_f32[0]))
                        + (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0]
                                        + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                                + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]))
                * 0.25)
        - v7;
    v13 = (unsigned __int8)(*((_BYTE *)(*motions)->m_deactivationNumInactiveFrames + v5) & 0x7F) <= (unsigned __int8)(*((_BYTE *)&(*motions)->m_deactivationNumInactiveFrames[1] + v5) & 0x7F)
        ? *(__m128 *)(v5 + v8 + 272)
        : *(__m128 *)(v5 + v8 + 256);
    if ( v12 > _mm_shuffle_ps(v13, v13, 255).m128_f32[0] )
      break;
    ++motions;
    if ( --v4 < 0 )
      return 1;
  }
  return 0;
}

// File Line: 192
// RVA: 0xD8E2F0
void __fastcall hkRigidMotionUtilStep(hkStepInfo *info, hkpMotion *const *motions, int numMotions, int motionOffset)
{
  int v4; // r12d
  __int64 v7; // rdi
  __int64 v8; // rbx
  __m128i si128; // xmm2
  __int64 v10; // rsi
  __m128i v11; // xmm4
  __m128 v12; // xmm11
  unsigned __int8 v13; // cl
  unsigned __int16 EncodedFloat; // ax
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm9
  __m128 v21; // xmm10
  __m128 v22; // xmm6
  unsigned __int8 v23; // cl
  __m128 v24; // xmm12
  __m128 v25; // xmm8
  __m128 v26; // xmm1
  __m128 v27; // xmm7
  unsigned __int16 v28; // ax
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm5
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm8
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm6
  __m128 v42; // xmm0
  __m128 v43; // xmm12
  __m128 v44; // xmm8
  __m128 v45; // xmm6
  __m128 v46; // xmm6
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm1
  unsigned int v53; // [rsp+0h] [rbp-59h]
  unsigned int v54; // [rsp+4h] [rbp-55h]
  unsigned int vars0; // [rsp+D0h] [rbp+77h]

  v4 = numMotions - 1;
  if ( numMotions - 1 >= 0 )
  {
    v7 = motionOffset;
    do
    {
      v8 = (__int64)*motions;
      if ( *(&(*motions)->m_type.m_storage + v7) != 5 )
      {
        si128 = _mm_load_si128((const __m128i *)(v7 + v8 + 224));
        v10 = v7 + v8;
        v11 = _mm_load_si128((const __m128i *)(v7 + v8 + 240));
        *(float *)&v54 = COERCE_FLOAT(*(__int16 *)(v7 + v8 + 200) << 16) * info->m_deltaTime.m_storage;
        v12 = _mm_shuffle_ps((__m128)v54, (__m128)v54, 0);
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_and_ps(
                      _mm_cmplt_ps(
                        (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u),
                        hkSweptTransformUtil::_stepMotionStateMaxVelf),
                      _mm_cmplt_ps(
                        (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u),
                        hkSweptTransformUtil::_stepMotionStateMaxVelf)),
                    _mm_cmpeq_ps((__m128)si128, (__m128)si128)),
                  _mm_cmpeq_ps((__m128)v11, (__m128)v11))) & 7) != 7 )
        {
          *(hkVector4f *)(v7 + v8 + 224) = (hkVector4f)transform.m_quad;
          *(hkVector4f *)(v7 + v8 + 240) = (hkVector4f)transform.m_quad;
        }
        v13 = *(_BYTE *)(v10 + 202);
        *(__m128 *)(v10 + 96) = _mm_shuffle_ps(
                                  *(__m128 *)(v10 + 112),
                                  _mm_unpackhi_ps(
                                    *(__m128 *)(v10 + 112),
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(info->m_startTime.m_storage),
                                      (__m128)LODWORD(info->m_startTime.m_storage),
                                      0)),
                                  196);
        EncodedFloat = hkUFloat8::getEncodedFloat(v13);
        if ( EncodedFloat )
          vars0 = (EncodedFloat + 243712) << 12;
        else
          vars0 = 0;
        v15 = *(__m128 *)(v7 + v8 + 224);
        v16 = _mm_shuffle_ps((__m128)vars0, (__m128)vars0, 0);
        v17 = _mm_mul_ps(v15, v15);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170));
        if ( v18.m128_f32[0] > (float)(v16.m128_f32[0] * v16.m128_f32[0]) )
        {
          v19 = _mm_rsqrt_ps(v18);
          *(__m128 *)(v7 + v8 + 224) = _mm_mul_ps(
                                         _mm_mul_ps(
                                           v16,
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v19))),
                                         v15);
        }
        v20 = _mm_shuffle_ps((__m128)0x3F52ACB8u, (__m128)0x3F52ACB8u, 0);
        v21 = _mm_shuffle_ps((__m128)0x3E05A965u, (__m128)0x3E05A965u, 0);
        v22 = _mm_shuffle_ps((__m128)0x3D35E52Au, (__m128)0x3D35E52Au, 0);
        *(__m128 *)(v10 + 112) = _mm_add_ps(_mm_mul_ps(v12, *(__m128 *)(v7 + v8 + 224)), *(__m128 *)(v10 + 112));
        *(float *)(v10 + 124) = info->m_invDeltaTime.m_storage;
        v23 = *(_BYTE *)(v10 + 203);
        v24 = *(__m128 *)(v10 + 144);
        *(__m128 *)(v10 + 128) = v24;
        v25 = _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v12), *(__m128 *)(v7 + v8 + 240));
        v26 = _mm_mul_ps(v25, v25);
        v27 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                  _mm_shuffle_ps(v26, v26, 170)),
                _mm_shuffle_ps((__m128)0x3ECF817Au, (__m128)0x3ECF817Au, 0));
        v28 = hkUFloat8::getEncodedFloat(v23);
        if ( v28 )
          v53 = (v28 + 243712) << 12;
        else
          v53 = 0;
        v29 = _mm_rcp_ps((__m128)xmmword_141A713B0);
        v30 = _mm_min_ps(
                _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0),
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, (__m128)xmmword_141A713B0)), v29),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)v53, (__m128)v53, 0), v12)));
        v31 = _mm_mul_ps(v30, v30);
        if ( v27.m128_f32[0] > v31.m128_f32[0] )
        {
          v32 = _mm_rsqrt_ps(v27);
          v33 = _mm_cmple_ps(v27, (__m128)0i64);
          v34 = _mm_mul_ps(v32, v27);
          v27 = v31;
          v35 = _mm_mul_ps(
                  _mm_andnot_ps(
                    v33,
                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v32)), _mm_mul_ps(*(__m128 *)_xmm, v32))),
                  v30);
          v25 = _mm_mul_ps(v25, v35);
          *(__m128 *)(v7 + v8 + 240) = _mm_mul_ps(*(__m128 *)(v7 + v8 + 240), v35);
        }
        v36 = _mm_mul_ps(v27, v27);
        v37 = _mm_shuffle_ps(v24, v24, 255);
        v38 = _mm_shuffle_ps(
                v25,
                _mm_unpackhi_ps(
                  v25,
                  _mm_sub_ps(
                    _mm_sub_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v20, v27)), _mm_mul_ps(v21, v36)),
                    _mm_mul_ps(_mm_mul_ps(v22, v27), v36))),
                196);
        v39 = _mm_mul_ps(v38, v37);
        v40 = _mm_shuffle_ps(v38, v38, 255);
        v41 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v38), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v24));
        v42 = _mm_mul_ps(v24, v40);
        v43 = _mm_mul_ps(v24, v38);
        v44 = _mm_add_ps(v38, v38);
        *(__m128 *)(v10 + 176) = v44;
        v45 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 201), v42), v39);
        v46 = _mm_shuffle_ps(
                v45,
                _mm_unpackhi_ps(
                  v45,
                  _mm_sub_ps(
                    _mm_mul_ps(v37, v40),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                      _mm_shuffle_ps(v43, v43, 170)))),
                196);
        v47 = _mm_mul_ps(v46, v46);
        v48 = _mm_add_ps(_mm_shuffle_ps(v47, v47, 78), v47);
        v49 = _mm_add_ps(_mm_shuffle_ps(v48, v48, 177), v48);
        v50 = _mm_rsqrt_ps(v49);
        v51 = _mm_rsqrt_ps(v27);
        *(__m128 *)(v10 + 176) = _mm_shuffle_ps(
                                   v44,
                                   _mm_unpackhi_ps(
                                     v44,
                                     _mm_mul_ps(
                                       _mm_andnot_ps(
                                         _mm_cmple_ps(v27, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v27), v51)),
                                             _mm_mul_ps(v51, *(__m128 *)_xmm)),
                                           v27)),
                                       (__m128)xmmword_141A713B0)),
                                   196);
        *(__m128 *)(v10 + 144) = _mm_mul_ps(
                                   v46,
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v50)));
        hkRotationf::set((hkRotationf *)(v10 + 32), (hkQuaternionf *)(v10 + 144));
        v52 = *(__m128 *)(v10 + 160);
        *(__m128 *)(v10 + 80) = _mm_sub_ps(
                                  *(__m128 *)(v10 + 112),
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), *(__m128 *)(v10 + 48)),
                                      _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), *(__m128 *)(v10 + 32))),
                                    _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), *(__m128 *)(v10 + 64))));
      }
      ++motions;
      --v4;
    }
    while ( v4 >= 0 );
  }
}

// File Line: 206
// RVA: 0xD8E830
__int64 __fastcall hkRigidMotionUtilApplyForcesAndStep(
        hkpSolverInfo *solverInfo,
        hkStepInfo *info,
        hkVector4f *deltaVel,
        hkpMotion *const *motions,
        int numMotions,
        int motionOffset)
{
  int v8; // edx
  unsigned int v10; // r15d
  __int64 v11; // rcx
  char *v12; // rbx
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128i v15; // xmm2
  __m128 *v16; // rdi
  __m128i v17; // xmm4
  __m128 v18; // xmm6
  unsigned __int8 v19; // cl
  unsigned __int16 v20; // ax
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128i si128; // xmm2
  __m128i v26; // xmm4
  __m128 v27; // xmm12
  unsigned __int8 v28; // cl
  unsigned __int16 EncodedFloat; // ax
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm9
  __m128 v36; // xmm10
  unsigned __int8 v37; // cl
  __m128 v38; // xmm11
  __m128 v39; // xmm13
  __m128 v40; // xmm7
  __m128 v41; // xmm1
  __m128 v42; // xmm6
  unsigned __int16 v43; // ax
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  __m128 v52; // xmm0
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  __m128 v56; // xmm3
  __m128 v57; // xmm7
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm4
  __m128 v61; // xmm0
  __m128 v62; // xmm13
  __m128 v63; // xmm7
  __m128 v64; // xmm4
  __m128 v65; // xmm4
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm0
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm1
  __m128 v74; // xmm7
  __m128 v75; // xmm1
  __m128 v76; // xmm6
  unsigned __int16 v77; // ax
  __m128 v78; // xmm8
  unsigned __int16 v79; // ax
  __m128 v80; // xmm4
  __m128 v81; // xmm2
  __m128 v82; // xmm1
  __m128 v83; // xmm4
  __m128 v84; // xmm3
  __m128 v85; // xmm1
  __m128 v86; // xmm2
  __m128 v87; // xmm1
  __m128 v88; // xmm10
  __m128 v89; // xmm11
  unsigned __int8 v90; // cl
  __m128 v91; // xmm12
  __m128 v92; // xmm9
  __m128 v93; // xmm8
  __m128 v94; // xmm1
  __m128 v95; // xmm7
  unsigned __int16 v96; // ax
  __m128 v97; // xmm2
  __m128 v98; // xmm4
  __m128 v99; // xmm3
  __m128 v100; // xmm5
  __m128 v101; // xmm2
  __m128 v102; // xmm3
  __m128 v103; // xmm0
  __m128 v104; // xmm3
  __m128 v105; // xmm0
  __m128 v106; // xmm3
  __m128 v107; // xmm2
  __m128 v108; // xmm0
  __m128 v109; // xmm3
  __m128 v110; // xmm8
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  __m128 v113; // xmm6
  __m128 v114; // xmm0
  __m128 v115; // xmm9
  __m128 v116; // xmm8
  __m128 v117; // xmm6
  __m128 v118; // xmm6
  __m128 v119; // xmm0
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  __m128 v122; // xmm3
  __m128 v123; // xmm1
  __m128 v124; // xmm1
  int v125; // eax
  int v126; // ecx
  __int64 v127; // rsi
  __m128 v128; // xmm4
  __m128 v129; // xmm5
  __m128 v130; // xmm2
  __m128 v131; // xmm1
  __m128 v132; // xmm5
  char *v133; // rdx
  __m128 v134; // xmm2
  __m128 v135; // xmm3
  __m128 v136; // xmm2
  __m128 v137; // xmm3
  __m128 v138; // xmm2
  __m128 v139; // xmm2
  __m128 v140; // xmm1
  int v141; // edx
  unsigned int v143; // [rsp+20h] [rbp-E0h]
  unsigned int v144; // [rsp+20h] [rbp-E0h]
  float v145; // [rsp+20h] [rbp-E0h]
  unsigned int v146; // [rsp+28h] [rbp-D8h]
  unsigned int v147; // [rsp+2Ch] [rbp-D4h]
  unsigned int v148; // [rsp+30h] [rbp-D0h]
  int v149; // [rsp+34h] [rbp-CCh]
  unsigned int v150; // [rsp+38h] [rbp-C8h]
  unsigned int v151; // [rsp+3Ch] [rbp-C4h]
  __m128i v152; // [rsp+90h] [rbp-70h]
  hkVector4f v153; // [rsp+A0h] [rbp-60h] BYREF
  hkVector4f b; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f v155; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f *v156; // [rsp+1A0h] [rbp+A0h]
  unsigned int numMotionsa; // [rsp+1B0h] [rbp+B0h]

  v156 = deltaVel;
  v8 = numMotions - 1;
  v10 = 0x7FFFFFFF;
  v149 = numMotions - 1;
  if ( numMotions - 1 >= 0 )
  {
    v11 = motionOffset;
    while ( 1 )
    {
      v12 = (char *)*motions + v11;
      v13 = _mm_shuffle_ps(
              (__m128)(unsigned int)(*((__int16 *)v12 + 153) << 16),
              (__m128)(unsigned int)(*((__int16 *)v12 + 153) << 16),
              0);
      if ( v12[16] == 4 )
        goto LABEL_9;
      if ( v12[16] != 5 )
        break;
LABEL_59:
      v11 = motionOffset;
      ++motions;
      v149 = --v8;
      if ( v8 < 0 )
        return v10;
    }
    if ( v12[16] == 6 )
    {
      v16 = (__m128 *)(v12 + 240);
      v21 = _mm_add_ps(_mm_mul_ps(v13, deltaVel->m_quad), *((__m128 *)v12 + 14));
      *((__m128 *)v12 + 14) = v21;
      v22 = _mm_shuffle_ps(
              (__m128)LODWORD(info->m_deltaTime.m_storage),
              (__m128)LODWORD(info->m_deltaTime.m_storage),
              0);
      *((__m128 *)v12 + 14) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 98) << 16),
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 98) << 16),
                                        0),
                                      v22))),
                                v21);
      *((__m128 *)v12 + 15) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 99) << 16),
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 99) << 16),
                                        0),
                                      v22))),
                                *((__m128 *)v12 + 15));
      hkVector4f::setRotatedInverseDir(&b, (hkMatrix3f *)(v12 + 32), (hkVector4f *)v12 + 15);
      v23 = *((__m128 *)v12 + 13);
      v24 = _mm_rcp_ps(v23);
      b.m_quad = _mm_mul_ps(b.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v24)), v24));
      hkVector4f::setRotatedDir(&v155, (hkMatrix3f *)(v12 + 32), &b);
      si128 = _mm_load_si128((const __m128i *)v12 + 14);
      v26 = _mm_load_si128((const __m128i *)v12 + 15);
      *(float *)&v144 = COERCE_FLOAT(*((__int16 *)v12 + 100) << 16) * info->m_deltaTime.m_storage;
      v27 = _mm_shuffle_ps((__m128)v144, (__m128)v144, 0);
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_cmplt_ps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v26, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf),
                    _mm_cmplt_ps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf)),
                  _mm_cmpeq_ps((__m128)si128, (__m128)si128)),
                _mm_cmpeq_ps((__m128)v26, (__m128)v26))) & 7) != 7 )
      {
        *((hkVector4f *)v12 + 14) = (hkVector4f)transform.m_quad;
        *(hkVector4f *)v16 = (hkVector4f)transform.m_quad;
      }
      v28 = v12[202];
      *((__m128 *)v12 + 6) = _mm_shuffle_ps(
                               *((__m128 *)v12 + 7),
                               _mm_unpackhi_ps(
                                 *((__m128 *)v12 + 7),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(info->m_startTime.m_storage),
                                   (__m128)LODWORD(info->m_startTime.m_storage),
                                   0)),
                               196);
      EncodedFloat = hkUFloat8::getEncodedFloat(v28);
      if ( EncodedFloat )
        numMotionsa = (EncodedFloat + 243712) << 12;
      else
        numMotionsa = 0;
      v30 = *((__m128 *)v12 + 14);
      v31 = _mm_shuffle_ps((__m128)numMotionsa, (__m128)numMotionsa, 0);
      v32 = _mm_mul_ps(v30, v30);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      if ( v33.m128_f32[0] > (float)(v31.m128_f32[0] * v31.m128_f32[0]) )
      {
        v34 = _mm_rsqrt_ps(v33);
        *((__m128 *)v12 + 14) = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v34)),
                                    v31),
                                  v30);
      }
      v35 = _mm_shuffle_ps((__m128)0x3F52ACB8u, (__m128)0x3F52ACB8u, 0);
      v36 = _mm_shuffle_ps((__m128)0x3E05A965u, (__m128)0x3E05A965u, 0);
      *((__m128 *)v12 + 7) = _mm_add_ps(_mm_mul_ps(*((__m128 *)v12 + 14), v27), *((__m128 *)v12 + 7));
      *((_DWORD *)v12 + 31) = LODWORD(info->m_invDeltaTime.m_storage);
      v37 = v12[203];
      v38 = _mm_shuffle_ps((__m128)0x3D35E52Au, (__m128)0x3D35E52Au, 0);
      v39 = *((__m128 *)v12 + 9);
      *((__m128 *)v12 + 8) = v39;
      v40 = _mm_mul_ps(_mm_mul_ps(v27, (__m128)xmmword_141A711B0), *v16);
      v41 = _mm_mul_ps(v40, v40);
      v42 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170)),
              _mm_shuffle_ps((__m128)0x3ECF817Au, (__m128)0x3ECF817Au, 0));
      v43 = hkUFloat8::getEncodedFloat(v37);
      if ( v43 )
        v150 = (v43 + 243712) << 12;
      else
        v150 = 0;
      v44 = _mm_rcp_ps((__m128)xmmword_141A713B0);
      v45 = v42;
      v46 = _mm_min_ps(
              _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0),
              _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, (__m128)xmmword_141A713B0)), v44),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v150, (__m128)v150, 0), v27)));
      v47 = _mm_mul_ps(v46, v46);
      if ( v42.m128_f32[0] > v47.m128_f32[0] )
      {
        v48 = _mm_rsqrt_ps(v42);
        v49 = _mm_cmple_ps(v42, (__m128)0i64);
        v50 = _mm_mul_ps(v48, v42);
        v42 = v47;
        v51 = _mm_mul_ps(
                _mm_andnot_ps(
                  v49,
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v50, v48)), _mm_mul_ps(*(__m128 *)_xmm, v48))),
                v46);
        v40 = _mm_mul_ps(v40, v51);
        v52 = v51;
        v45 = v47;
        *v16 = _mm_mul_ps(v52, *v16);
      }
      v53 = _mm_mul_ps(v45, v42);
      v54 = _mm_sub_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v42, v35)), _mm_mul_ps(v53, v36));
      v55 = _mm_mul_ps(_mm_mul_ps(v42, v38), v53);
      v56 = _mm_shuffle_ps(v39, v39, 255);
      v57 = _mm_shuffle_ps(v40, _mm_unpackhi_ps(v40, _mm_sub_ps(v54, v55)), 196);
      v58 = _mm_mul_ps(v56, v57);
      v59 = _mm_shuffle_ps(v57, v57, 255);
      v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v57), _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v39));
      v61 = _mm_mul_ps(v59, v39);
      v62 = _mm_mul_ps(v39, v57);
      v63 = _mm_add_ps(v57, v57);
      *((__m128 *)v12 + 11) = v63;
      v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 201), v61), v58);
      v65 = _mm_shuffle_ps(
              v64,
              _mm_unpackhi_ps(
                v64,
                _mm_sub_ps(
                  _mm_mul_ps(v56, v59),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                    _mm_shuffle_ps(v62, v62, 170)))),
              196);
      v66 = _mm_mul_ps(v65, v65);
      v67 = _mm_add_ps(_mm_shuffle_ps(v66, v66, 78), v66);
      v68 = _mm_add_ps(_mm_shuffle_ps(v67, v67, 177), v67);
      v69 = _mm_rsqrt_ps(v68);
      v70 = _mm_mul_ps(v69, v68);
      v71 = _mm_rsqrt_ps(v42);
      *((__m128 *)v12 + 9) = _mm_mul_ps(
                               v65,
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v70, v69)),
                                 _mm_mul_ps(v69, *(__m128 *)_xmm)));
      *((__m128 *)v12 + 11) = _mm_shuffle_ps(
                                v63,
                                _mm_unpackhi_ps(
                                  v63,
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmple_ps(v42, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v42), v71)),
                                          _mm_mul_ps(v71, *(__m128 *)_xmm)),
                                        v42)),
                                    (__m128)xmmword_141A713B0)),
                                196);
      hkRotationf::set((hkRotationf *)(v12 + 32), (hkQuaternionf *)v12 + 9);
      v72 = *((__m128 *)v12 + 10);
      *((__m128 *)v12 + 5) = _mm_sub_ps(
                               *((__m128 *)v12 + 7),
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v72, v72, 85), *((__m128 *)v12 + 3)),
                                   _mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), *((__m128 *)v12 + 2))),
                                 _mm_mul_ps(_mm_shuffle_ps(v72, v72, 170), *((__m128 *)v12 + 4))));
      hkVector4f::setRotatedInverseDir(&v153, (hkMatrix3f *)(v12 + 32), &v155);
      v153.m_quad = _mm_mul_ps(v153.m_quad, *((__m128 *)v12 + 13));
      hkVector4f::setRotatedDir((hkVector4f *)v12 + 15, (hkMatrix3f *)(v12 + 32), &v153);
      v73 = _mm_mul_ps(*((__m128 *)v12 + 14), *((__m128 *)v12 + 14));
      v74 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
              _mm_shuffle_ps(v73, v73, 170));
      v75 = _mm_mul_ps(*v16, *v16);
      v76 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
              _mm_shuffle_ps(v75, v75, 170));
      v77 = hkUFloat8::getEncodedFloat(v12[202]);
      if ( v77 )
        v151 = (v77 + 243712) << 12;
      else
        v151 = 0;
      v78 = _mm_shuffle_ps((__m128)v151, (__m128)v151, 0);
      v79 = hkUFloat8::getEncodedFloat(v12[203]);
      if ( v79 )
        v148 = (v79 + 243712) << 12;
      else
        v148 = 0;
      v80 = _mm_shuffle_ps((__m128)v148, (__m128)v148, 0);
      if ( v74.m128_f32[0] > (float)(v78.m128_f32[0] * v78.m128_f32[0]) )
      {
        v81 = _mm_rsqrt_ps(v74);
        *((__m128 *)v12 + 14) = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmple_ps(v74, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v81, v74), v81)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v81))),
                                    v78),
                                  *((__m128 *)v12 + 14));
      }
      if ( v76.m128_f32[0] > (float)(v80.m128_f32[0] * v80.m128_f32[0]) )
      {
        v82 = _mm_rsqrt_ps(v76);
        *v16 = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmple_ps(v76, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v82, v76), v82)),
                       _mm_mul_ps(*(__m128 *)_xmm, v82))),
                   v80),
                 *v16);
      }
    }
    else
    {
      if ( v12[16] != 7 )
        *((__m128 *)v12 + 14) = _mm_add_ps(_mm_mul_ps(v13, deltaVel->m_quad), *((__m128 *)v12 + 14));
      v14 = _mm_shuffle_ps(
              (__m128)LODWORD(info->m_deltaTime.m_storage),
              (__m128)LODWORD(info->m_deltaTime.m_storage),
              0);
      *((__m128 *)v12 + 14) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 98) << 16),
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 98) << 16),
                                        0),
                                      v14))),
                                *((__m128 *)v12 + 14));
      *((__m128 *)v12 + 15) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 99) << 16),
                                        (__m128)(unsigned int)(*((__int16 *)v12 + 99) << 16),
                                        0),
                                      v14))),
                                *((__m128 *)v12 + 15));
LABEL_9:
      v15 = _mm_load_si128((const __m128i *)v12 + 14);
      v16 = (__m128 *)(v12 + 240);
      v17 = _mm_load_si128((const __m128i *)v12 + 15);
      *(float *)&v143 = COERCE_FLOAT(*((__int16 *)v12 + 100) << 16) * info->m_deltaTime.m_storage;
      v18 = _mm_shuffle_ps((__m128)v143, (__m128)v143, 0);
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_cmplt_ps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v17, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf),
                    _mm_cmplt_ps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v15, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf)),
                  _mm_cmpeq_ps((__m128)v15, (__m128)v15)),
                _mm_cmpeq_ps((__m128)v17, (__m128)v17))) & 7) != 7 )
      {
        *((hkVector4f *)v12 + 14) = (hkVector4f)transform.m_quad;
        *(hkVector4f *)v16 = (hkVector4f)transform.m_quad;
      }
      v19 = v12[202];
      *((__m128 *)v12 + 6) = _mm_shuffle_ps(
                               *((__m128 *)v12 + 7),
                               _mm_unpackhi_ps(
                                 *((__m128 *)v12 + 7),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(info->m_startTime.m_storage),
                                   (__m128)LODWORD(info->m_startTime.m_storage),
                                   0)),
                               196);
      v20 = hkUFloat8::getEncodedFloat(v19);
      if ( v20 )
        v146 = (v20 + 243712) << 12;
      else
        v146 = 0;
      v83 = *((__m128 *)v12 + 14);
      v84 = _mm_shuffle_ps((__m128)v146, (__m128)v146, 0);
      v85 = _mm_mul_ps(v83, v83);
      v86 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
              _mm_shuffle_ps(v85, v85, 170));
      if ( v86.m128_f32[0] > (float)(v84.m128_f32[0] * v84.m128_f32[0]) )
      {
        v87 = _mm_rsqrt_ps(v86);
        *((__m128 *)v12 + 14) = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v87, v86), v87)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v87)),
                                    v84),
                                  v83);
      }
      v88 = _mm_shuffle_ps((__m128)0x3F52ACB8u, (__m128)0x3F52ACB8u, 0);
      v89 = _mm_shuffle_ps((__m128)0x3E05A965u, (__m128)0x3E05A965u, 0);
      *((__m128 *)v12 + 7) = _mm_add_ps(_mm_mul_ps(v18, *((__m128 *)v12 + 14)), *((__m128 *)v12 + 7));
      *((_DWORD *)v12 + 31) = LODWORD(info->m_invDeltaTime.m_storage);
      v90 = v12[203];
      v91 = _mm_shuffle_ps((__m128)0x3D35E52Au, (__m128)0x3D35E52Au, 0);
      v92 = *((__m128 *)v12 + 9);
      *((__m128 *)v12 + 8) = v92;
      v93 = _mm_mul_ps(_mm_mul_ps(v18, (__m128)xmmword_141A711B0), *v16);
      v94 = _mm_mul_ps(v93, v93);
      v95 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                _mm_shuffle_ps(v94, v94, 170)),
              _mm_shuffle_ps((__m128)0x3ECF817Au, (__m128)0x3ECF817Au, 0));
      v96 = hkUFloat8::getEncodedFloat(v90);
      if ( v96 )
        v147 = (v96 + 243712) << 12;
      else
        v147 = 0;
      v97 = _mm_rcp_ps((__m128)xmmword_141A713B0);
      v98 = _mm_min_ps(
              _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0),
              _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v97, (__m128)xmmword_141A713B0)), v97),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v147, (__m128)v147, 0), v18)));
      v99 = v95;
      v100 = _mm_mul_ps(v98, v98);
      if ( v95.m128_f32[0] > v100.m128_f32[0] )
      {
        v101 = _mm_rsqrt_ps(v95);
        v102 = _mm_cmple_ps(v95, (__m128)0i64);
        v103 = _mm_mul_ps(v101, v95);
        v95 = v100;
        v104 = _mm_mul_ps(
                 _mm_andnot_ps(
                   v102,
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v103, v101)), _mm_mul_ps(*(__m128 *)_xmm, v101))),
                 v98);
        v93 = _mm_mul_ps(v93, v104);
        v105 = v104;
        v99 = v100;
        *v16 = _mm_mul_ps(v105, *v16);
      }
      v106 = _mm_mul_ps(v99, v95);
      v107 = _mm_sub_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v95, v88)), _mm_mul_ps(v106, v89));
      v108 = _mm_mul_ps(_mm_mul_ps(v95, v91), v106);
      v109 = _mm_shuffle_ps(v92, v92, 255);
      v110 = _mm_shuffle_ps(v93, _mm_unpackhi_ps(v93, _mm_sub_ps(v107, v108)), 196);
      v111 = _mm_mul_ps(v109, v110);
      v112 = _mm_shuffle_ps(v110, v110, 255);
      v113 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v92, v92, 201), v110),
               _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v92));
      v114 = _mm_mul_ps(v112, v92);
      v115 = _mm_mul_ps(v92, v110);
      v116 = _mm_add_ps(v110, v110);
      *((__m128 *)v12 + 11) = v116;
      v117 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v113, v113, 201), v114), v111);
      v118 = _mm_shuffle_ps(
               v117,
               _mm_unpackhi_ps(
                 v117,
                 _mm_sub_ps(
                   _mm_mul_ps(v109, v112),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                     _mm_shuffle_ps(v115, v115, 170)))),
               196);
      v119 = _mm_mul_ps(v118, v118);
      v120 = _mm_add_ps(_mm_shuffle_ps(v119, v119, 78), v119);
      v121 = _mm_add_ps(_mm_shuffle_ps(v120, v120, 177), v120);
      v122 = _mm_rsqrt_ps(v121);
      v123 = _mm_rsqrt_ps(v95);
      *((__m128 *)v12 + 11) = _mm_shuffle_ps(
                                v116,
                                _mm_unpackhi_ps(
                                  v116,
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmple_ps(v95, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v123, v95), v123)),
                                          _mm_mul_ps(v123, *(__m128 *)_xmm)),
                                        v95)),
                                    (__m128)xmmword_141A713B0)),
                                196);
      *((__m128 *)v12 + 9) = _mm_mul_ps(
                               v118,
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v122, v121), v122)),
                                 _mm_mul_ps(v122, *(__m128 *)_xmm)));
      hkRotationf::set((hkRotationf *)(v12 + 32), (hkQuaternionf *)v12 + 9);
      v124 = *((__m128 *)v12 + 10);
      *((__m128 *)v12 + 5) = _mm_sub_ps(
                               *((__m128 *)v12 + 7),
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v124, v124, 85), *((__m128 *)v12 + 3)),
                                   _mm_mul_ps(_mm_shuffle_ps(v124, v124, 0), *((__m128 *)v12 + 2))),
                                 _mm_mul_ps(_mm_shuffle_ps(v124, v124, 170), *((__m128 *)v12 + 4))));
    }
    v125 = (unsigned __int8)v12[17]++ + 1;
    if ( (v125 & 3) == 0 )
    {
      if ( (v125 & 0xF) != 0 )
      {
        v126 = 0;
        v127 = 0i64;
LABEL_50:
        v128 = _mm_mul_ps(*((__m128 *)v12 + 14), *((__m128 *)v12 + 14));
        v129 = *(__m128 *)&v12[16 * v127 + 256];
        v145 = fminf(1.0, *((float *)v12 + 48));
        v130 = _mm_shuffle_ps((__m128)LODWORD(v145), (__m128)LODWORD(v145), 0);
        v131 = _mm_mul_ps(*v16, *v16);
        v132 = _mm_shuffle_ps(
                 v129,
                 _mm_unpackhi_ps(
                   v129,
                   _mm_max_ps(
                     _mm_shuffle_ps(v129, v129, 255),
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v131, v131, 85), _mm_shuffle_ps(v131, v131, 0)),
                           _mm_shuffle_ps(v131, v131, 170)),
                         _mm_mul_ps(v130, v130)),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                         _mm_shuffle_ps(v128, v128, 170))))),
                 196);
        *(__m128 *)&v12[16 * v127 + 256] = v132;
        v133 = (char *)solverInfo + 32 * (unsigned __int8)v12[204];
        v134 = _mm_sub_ps(v132, *((__m128 *)v12 + 7));
        v135 = (__m128)*(unsigned int *)&v133[4 * v126 + 116];
        v136 = _mm_mul_ps(v134, v134);
        if ( (float)((float)(_mm_shuffle_ps(v136, v136, 85).m128_f32[0] + _mm_shuffle_ps(v136, v136, 0).m128_f32[0])
                   + _mm_shuffle_ps(v136, v136, 170).m128_f32[0]) > _mm_shuffle_ps(v135, v135, 0).m128_f32[0] )
          goto LABEL_53;
        v137 = (__m128)*(unsigned int *)&v133[4 * v126 + 124];
        v152.m128i_i32[0] = *(_DWORD *)&v12[4 * v127 + 288];
        v152.m128i_i32[1] = (unsigned int)v152.m128i_i32[0] >> 8;
        v152.m128i_i32[3] = HIBYTE(v152.m128i_i32[0]);
        v152.m128i_i32[2] = HIWORD(v152.m128i_i32[0]);
        v138 = _mm_sub_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_sub_epi32(_mm_and_si128(_mm_load_si128((const __m128i *)&_xmm), v152), (__m128i)_xmm)),
                   _mm_shuffle_ps((__m128)0x3C0CCCCDu, (__m128)0x3C0CCCCDu, 0)),
                 *((__m128 *)v12 + 9));
        v139 = _mm_mul_ps(v138, v138);
        v140 = _mm_add_ps(_mm_shuffle_ps(v139, v139, 78), v139);
        if ( (float)(_mm_shuffle_ps(v140, v140, 177).m128_f32[0] + v140.m128_f32[0]) > _mm_shuffle_ps(v137, v137, 0).m128_f32[0] )
        {
LABEL_53:
          *(_WORD *)&v12[2 * v127 + 18] = (*(_WORD *)&v12[2 * v127 + 18] & 0x7F | ((unsigned __int8)solverInfo->m_deactivationNumInactiveFramesSelectFlag[v127] << 7)) << 7;
          *(__m128i *)&v12[16 * v127 + 256] = _mm_srli_si128(_mm_slli_si128(*((__m128i *)v12 + 7), 4), 4);
          *(_DWORD *)&v12[4 * v127 + 288] = hkVector4UtilImpl<float>::packQuaternionIntoInt32((hkVector4f *)v12 + 9);
        }
        else
        {
          *(_WORD *)&v12[2 * v127 + 18] = ((*(_WORD *)&v12[2 * v127 + 18] & 0x7F | ((unsigned __int8)solverInfo->m_deactivationNumInactiveFramesSelectFlag[v127] << 7)) << 7) | ((*(_WORD *)&v12[2 * v127 + 18] & 0x7F) - ((*(_WORD *)&v12[2 * v127 + 18] & 0x7F) >> 6) + 1);
        }
        goto LABEL_54;
      }
      if ( v125 != 256 )
      {
        v126 = 1;
        v12[17] = 0;
        v127 = 1i64;
        goto LABEL_50;
      }
      v12[17] = -1;
    }
LABEL_54:
    deltaVel = v156;
    v141 = *((_WORD *)v12 + 10) & 0x7F;
    if ( (*((_WORD *)v12 + 9) & 0x7F) > v141 )
      v141 = *((_WORD *)v12 + 9) & 0x7F;
    if ( (int)v10 < v141 )
      v141 = v10;
    v10 = v141;
    v8 = v149;
    goto LABEL_59;
  }
  return v10;
}

// File Line: 290
// RVA: 0xD8F7B0
hkpVelocityAccumulator *__fastcall hkRigidMotionUtilBuildAccumulators(
        hkStepInfo *info,
        hkpMotion *const *motions,
        int numMotions,
        int motionOffset,
        hkpVelocityAccumulator *accumulatorsOut)
{
  int v5; // r11d
  hkpVelocityAccumulator *v7; // r8
  __int64 v8; // rdx
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 m_storage_low; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  unsigned int v21; // [rsp+0h] [rbp-18h]
  unsigned int accumulatorsOuta; // [rsp+40h] [rbp+28h]

  v5 = numMotions - 1;
  if ( numMotions - 1 < 0 )
    return accumulatorsOut;
  v7 = accumulatorsOut;
  do
  {
    v8 = (__int64)*motions;
    switch ( *(&(*motions)->m_type.m_storage + motionOffset) )
    {
      case 0:
      case 3:
      case 6:
        *(_WORD *)&v7->m_type.m_storage = 0;
        v9 = *(__m128 *)(motionOffset + v8 + 64);
        v10 = *(__m128 *)(motionOffset + v8 + 32);
        v11 = _mm_unpackhi_ps(v10, *(__m128 *)(motionOffset + v8 + 48));
        v12 = _mm_unpacklo_ps(v10, *(__m128 *)(motionOffset + v8 + 48));
        v7->m_scratch2.m_quad = _mm_shuffle_ps(v11, v9, 228);
        v13 = _mm_movelh_ps(v12, v9);
        v7->m_scratch0.m_quad = v13;
        v7->m_scratch1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v9, 212);
        v7->m_invMasses = *(hkVector4f *)(motionOffset + v8 + 208);
        v7->m_linearVel = *(hkVector4f *)(motionOffset + v8 + 224);
        v14 = *(__m128 *)(motionOffset + v8 + 96);
        v7->m_scratch3.m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps(
                                        _mm_shuffle_ps(
                                          (__m128)LODWORD(info->m_startTime.m_storage),
                                          (__m128)LODWORD(info->m_startTime.m_storage),
                                          0),
                                        _mm_shuffle_ps(v14, v14, 255)),
                                      _mm_shuffle_ps(
                                        *(__m128 *)(motionOffset + v8 + 112),
                                        *(__m128 *)(motionOffset + v8 + 112),
                                        255)),
                                    _mm_sub_ps(*(__m128 *)(motionOffset + v8 + 112), v14)),
                                  v14);
        v7->m_angularVel = *(hkVector4f *)(motionOffset + v8 + 240);
        goto LABEL_5;
      case 2:
        v7->m_type.m_storage = 0;
        goto $buildRigidBodyAccumulator;
      case 4:
        *(_WORD *)&v7->m_type.m_storage = 1;
        v7->m_invMasses = 0i64;
        v7->m_scratch3 = *(hkVector4f *)(motionOffset + v8 + 112);
        v7->m_angularVel = *(hkVector4f *)(motionOffset + v8 + 240);
        v7->m_linearVel = *(hkVector4f *)(motionOffset + v8 + 224);
        v7->m_scratch0 = (hkVector4f)transform.m_quad;
        v7->m_scratch1 = (hkVector4f)direction.m_quad;
        v7->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
        LODWORD(v7->m_gravityFactor) = *(__int16 *)(motionOffset + v8 + 306) << 16;
        break;
      case 5:
        *(_WORD *)&v7->m_type.m_storage = 1;
        v7->m_gravityFactor = 0.0;
        v7->m_invMasses = 0i64;
        v7->m_linearVel = 0i64;
        v7->m_angularVel = 0i64;
        v7->m_scratch3 = 0i64;
        v7->m_scratch0 = (hkVector4f)transform.m_quad;
        v7->m_scratch1 = (hkVector4f)direction.m_quad;
        v7->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
        break;
      case 7:
        v7->m_type.m_storage = 2;
$buildRigidBodyAccumulator:
        v7->m_context.m_storage = 0;
        m_storage_low = (__m128)LODWORD(info->m_deltaTime.m_storage);
        v7->m_invMasses = *(hkVector4f *)(motionOffset + v8 + 208);
        v16 = *(__m128 *)(motionOffset + v8 + 96);
        v17 = _mm_shuffle_ps(m_storage_low, m_storage_low, 0);
        v7->m_scratch3.m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps(
                                        _mm_shuffle_ps(
                                          (__m128)LODWORD(info->m_startTime.m_storage),
                                          (__m128)LODWORD(info->m_startTime.m_storage),
                                          0),
                                        _mm_shuffle_ps(v16, v16, 255)),
                                      _mm_shuffle_ps(
                                        *(__m128 *)(motionOffset + v8 + 112),
                                        *(__m128 *)(motionOffset + v8 + 112),
                                        255)),
                                    _mm_sub_ps(*(__m128 *)(motionOffset + v8 + 112), v16)),
                                  v16);
        v18 = _mm_shuffle_ps(
                *(__m128 *)(motionOffset + v8 + 240),
                _mm_unpackhi_ps(*(__m128 *)(motionOffset + v8 + 240), (__m128)0i64),
                196);
        v7->m_angularVel.m_quad = v18;
        accumulatorsOuta = *(__int16 *)(motionOffset + v8 + 198) << 16;
        v7->m_angularVel.m_quad = _mm_mul_ps(
                                    _mm_max_ps(
                                      aabbOut.m_quad,
                                      _mm_sub_ps(
                                        query.m_quad,
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)accumulatorsOuta, (__m128)accumulatorsOuta, 0),
                                          v17))),
                                    v18);
        v19 = _mm_shuffle_ps(
                *(__m128 *)(motionOffset + v8 + 224),
                _mm_unpackhi_ps(*(__m128 *)(motionOffset + v8 + 224), (__m128)0i64),
                196);
        v7->m_linearVel.m_quad = v19;
        v21 = *(__int16 *)(motionOffset + v8 + 196) << 16;
        v7->m_linearVel.m_quad = _mm_mul_ps(
                                   _mm_max_ps(
                                     aabbOut.m_quad,
                                     _mm_sub_ps(
                                       query.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps((__m128)v21, (__m128)v21, 0), v17))),
                                   v19);
        v7->m_scratch0 = (hkVector4f)transform.m_quad;
        v7->m_scratch1 = (hkVector4f)direction.m_quad;
        v7->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
LABEL_5:
        v7->m_deactivationClass = *(unsigned __int8 *)(motionOffset + v8 + 204);
        LODWORD(v7->m_gravityFactor) = *(__int16 *)(motionOffset + v8 + 306) << 16;
        break;
      default:
        break;
    }
    ++motions;
    ++v7;
    --v5;
  }
  while ( v5 >= 0 );
  return v7;
}

// File Line: 425
// RVA: 0xD8FB20
hkpVelocityAccumulator *__fastcall hkRigidMotionUtilApplyForcesAndBuildAccumulators(
        hkStepInfo *info,
        hkpMotion *const *motions,
        int numMotions,
        int motionOffset,
        hkpVelocityAccumulator *accumulatorsOut)
{
  int v5; // ebx
  __int64 v7; // r10
  hkpVelocityAccumulator *v8; // r9
  hkVector4f *p_m_scratch2; // r8
  __int64 v10; // rdx
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm2
  unsigned int v22; // [rsp+0h] [rbp-18h]
  unsigned int v23; // [rsp+4h] [rbp-14h]
  unsigned int v24; // [rsp+8h] [rbp-10h]
  unsigned int accumulatorsOuta; // [rsp+40h] [rbp+28h]

  v5 = numMotions - 1;
  if ( numMotions - 1 < 0 )
    return accumulatorsOut;
  v7 = motionOffset;
  v8 = accumulatorsOut;
  p_m_scratch2 = &accumulatorsOut->m_scratch2;
  do
  {
    v10 = (__int64)*motions;
    switch ( *(&(*motions)->m_type.m_storage + v7) )
    {
      case 0:
      case 3:
      case 6:
        accumulatorsOuta = *(__int16 *)(v7 + v10 + 198) << 16;
        v11 = _mm_shuffle_ps(
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                0);
        *(__m128 *)(v7 + v10 + 240) = _mm_mul_ps(
                                        _mm_max_ps(
                                          aabbOut.m_quad,
                                          _mm_sub_ps(
                                            query.m_quad,
                                            _mm_mul_ps(
                                              _mm_shuffle_ps((__m128)accumulatorsOuta, (__m128)accumulatorsOuta, 0),
                                              v11))),
                                        *(__m128 *)(v7 + v10 + 240));
        v22 = *(__int16 *)(v7 + v10 + 196) << 16;
        *(__m128 *)(v7 + v10 + 224) = _mm_mul_ps(
                                        _mm_max_ps(
                                          aabbOut.m_quad,
                                          _mm_sub_ps(
                                            query.m_quad,
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v22, (__m128)v22, 0), v11))),
                                        *(__m128 *)(v7 + v10 + 224));
        v8->m_type.m_storage = 0;
        p_m_scratch2[-6].m_quad.m128_i8[1] = 0;
        v12 = *(__m128 *)(v7 + v10 + 64);
        v13 = *(__m128 *)(v7 + v10 + 32);
        v14 = _mm_unpackhi_ps(v13, *(__m128 *)(v7 + v10 + 48));
        v15 = _mm_unpacklo_ps(v13, *(__m128 *)(v7 + v10 + 48));
        p_m_scratch2->m_quad = _mm_shuffle_ps(v14, v12, 228);
        v16 = _mm_movelh_ps(v15, v12);
        p_m_scratch2[-2] = (hkVector4f)v16;
        p_m_scratch2[-1].m_quad = _mm_shuffle_ps(_mm_movehl_ps(v16, v15), v12, 212);
        p_m_scratch2[-3] = *(hkVector4f *)(v7 + v10 + 208);
        p_m_scratch2[-5] = *(hkVector4f *)(v7 + v10 + 224);
        v17 = *(__m128 *)(v7 + v10 + 96);
        p_m_scratch2[1].m_quad = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(
                                         _mm_shuffle_ps(
                                           (__m128)LODWORD(info->m_startTime.m_storage),
                                           (__m128)LODWORD(info->m_startTime.m_storage),
                                           0),
                                         _mm_shuffle_ps(v17, v17, 255)),
                                       _mm_shuffle_ps(*(__m128 *)(v7 + v10 + 112), *(__m128 *)(v7 + v10 + 112), 255)),
                                     _mm_sub_ps(*(__m128 *)(v7 + v10 + 112), v17)),
                                   v17);
        v18 = *(__m128 *)(v7 + v10 + 240);
        p_m_scratch2[-4].m_quad = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), p_m_scratch2[-1].m_quad),
                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), p_m_scratch2[-2].m_quad)),
                                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), p_m_scratch2->m_quad));
        goto LABEL_5;
      case 2:
        v8->m_type.m_storage = 0;
        goto $buildRigidBodyAccumulator_0;
      case 4:
        v8->m_type.m_storage = 1;
        p_m_scratch2[-6].m_quad.m128_i8[1] = 0;
        p_m_scratch2[-3] = 0i64;
        p_m_scratch2[1] = *(hkVector4f *)(v7 + v10 + 112);
        p_m_scratch2[-4] = *(hkVector4f *)(v7 + v10 + 240);
        p_m_scratch2[-5] = *(hkVector4f *)(v7 + v10 + 224);
        p_m_scratch2[-2] = (hkVector4f)transform.m_quad;
        p_m_scratch2[-1] = (hkVector4f)direction.m_quad;
        *p_m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
        p_m_scratch2[-6].m_quad.m128_i32[2] = *(__int16 *)(v7 + v10 + 306) << 16;
        break;
      case 5:
        p_m_scratch2[-6].m_quad.m128_i8[1] = 0;
        v8->m_type.m_storage = 1;
        p_m_scratch2[-6].m_quad.m128_i32[2] = 0;
        p_m_scratch2[-3] = 0i64;
        p_m_scratch2[-5] = 0i64;
        p_m_scratch2[-4] = 0i64;
        p_m_scratch2[1] = 0i64;
        p_m_scratch2[-2] = (hkVector4f)transform.m_quad;
        p_m_scratch2[-1] = (hkVector4f)direction.m_quad;
        *p_m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
        break;
      case 7:
        v8->m_type.m_storage = 2;
$buildRigidBodyAccumulator_0:
        p_m_scratch2[-6].m_quad.m128_i8[1] = 0;
        v23 = *(__int16 *)(v7 + v10 + 198) << 16;
        v19 = _mm_shuffle_ps(
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                0);
        *(__m128 *)(v7 + v10 + 240) = _mm_mul_ps(
                                        _mm_max_ps(
                                          aabbOut.m_quad,
                                          _mm_sub_ps(
                                            query.m_quad,
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v23, (__m128)v23, 0), v19))),
                                        *(__m128 *)(v7 + v10 + 240));
        v24 = *(__int16 *)(v7 + v10 + 196) << 16;
        *(__m128 *)(v7 + v10 + 224) = _mm_mul_ps(
                                        _mm_max_ps(
                                          aabbOut.m_quad,
                                          _mm_sub_ps(
                                            query.m_quad,
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v24, (__m128)v24, 0), v19))),
                                        *(__m128 *)(v7 + v10 + 224));
        p_m_scratch2[-3] = *(hkVector4f *)(v7 + v10 + 208);
        v20 = *(__m128 *)(v7 + v10 + 96);
        p_m_scratch2[1].m_quad = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(
                                         _mm_shuffle_ps(
                                           (__m128)LODWORD(info->m_startTime.m_storage),
                                           (__m128)LODWORD(info->m_startTime.m_storage),
                                           0),
                                         _mm_shuffle_ps(v20, v20, 255)),
                                       _mm_shuffle_ps(*(__m128 *)(v7 + v10 + 112), *(__m128 *)(v7 + v10 + 112), 255)),
                                     _mm_sub_ps(*(__m128 *)(v7 + v10 + 112), v20)),
                                   v20);
        p_m_scratch2[-4] = *(hkVector4f *)(v7 + v10 + 240);
        p_m_scratch2[-5] = *(hkVector4f *)(v7 + v10 + 224);
        p_m_scratch2[-2] = (hkVector4f)transform.m_quad;
        p_m_scratch2[-1] = (hkVector4f)direction.m_quad;
        *p_m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
LABEL_5:
        p_m_scratch2[-6].m_quad.m128_i32[1] = *(unsigned __int8 *)(v7 + v10 + 204);
        p_m_scratch2[-6].m_quad.m128_i32[2] = *(__int16 *)(v7 + v10 + 306) << 16;
        break;
      default:
        break;
    }
    ++motions;
    ++v8;
    p_m_scratch2 += 8;
    --v5;
  }
  while ( v5 >= 0 );
  return v8;
}

// File Line: 569
// RVA: 0xD8FF60
hkRigidMotionUtilApplyAccumulators

