// File Line: 26
// RVA: 0xD90B40
hkSimdFloat32 *__fastcall calcVelocityForDeactivation(hkSimdFloat32 *result, hkpMotion *motion, hkSimdFloat32 *objectRadius)
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
char __fastcall hkRigidMotionUtilCanDeactivateFinal(hkStepInfo *info, hkpMotion *const *motions, int numMotions, int motionOffset)
{
  int v4; // er10
  __int64 v5; // r8
  float v6; // xmm5_4
  float v7; // xmm5_4
  hkpMotion *v8; // r9
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  float v12; // xmm4_4
  __m128 v13; // xmm0

  v4 = numMotions - 1;
  if ( numMotions - 1 < 0 )
    return 1;
  v5 = motionOffset;
  LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0);
  v7 = v6 * v6;
  while ( 1 )
  {
    v8 = *motions;
    v9 = _mm_mul_ps(
           *(__m128 *)((char *)&(*motions)->m_angularVelocity.m_quad + v5),
           *(__m128 *)((char *)&(*motions)->m_angularVelocity.m_quad + v5));
    v10 = (__m128)COERCE_UNSIGNED_INT(fminf(1.0, *(float *)((char *)&(*motions)->m_motionState.m_objectRadius + v5)));
    v11 = _mm_mul_ps(
            *(__m128 *)((char *)&v8->m_linearVelocity.m_quad + v5),
            *(__m128 *)((char *)&v8->m_linearVelocity.m_quad + v5));
    v10.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v10, v10, 0);
    v12 = (float)((float)((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85))
                                                + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
                                        + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170)))
                                * (float)(v10.m128_f32[0] * v10.m128_f32[0]))
                        + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85))
                                        + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                                + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))))
                * 0.25)
        - v7;
    v13 = (__m128)((unsigned __int8)(*((_BYTE *)(*motions)->m_deactivationNumInactiveFrames + v5) & 0x7F) <= (unsigned __int8)(*((_BYTE *)&(*motions)->m_deactivationNumInactiveFrames[1] + v5) & 0x7F) ? *(_OWORD *)((char *)&v8->m_deactivationRefPosition[1].m_quad + v5) : *(_OWORD *)((char *)&v8->m_deactivationRefPosition[0].m_quad + v5));
    if ( v12 > COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 255)) )
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
  int v4; // er12
  hkpMotion *const *v5; // r14
  hkStepInfo *v6; // r15
  __int64 v7; // rdi
  hkpMotion *v8; // rbx
  __m128i v9; // xmm2
  __m128i v10; // xmm3
  char *v11; // rsi
  unsigned int v12; // ST04_4
  __m128 v13; // xmm11
  char v14; // cl
  unsigned __int16 v15; // ax
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm2
  __m128 v21; // xmm9
  __m128 v22; // xmm10
  __m128 v23; // xmm6
  char v24; // cl
  __m128 v25; // xmm12
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm7
  unsigned __int16 v29; // ax
  __m128 v30; // xmm2
  __m128 v31; // xmm4
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  __m128 v38; // xmm3
  __m128 v39; // xmm8
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm0
  __m128 v44; // xmm12
  __m128 v45; // xmm8
  __m128 v46; // xmm6
  __m128 v47; // xmm6
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm1
  unsigned int v54; // [rsp+0h] [rbp-59h]
  unsigned int vars0; // [rsp+D0h] [rbp+77h]

  v4 = numMotions - 1;
  v5 = motions;
  v6 = info;
  if ( numMotions - 1 >= 0 )
  {
    v7 = motionOffset;
    do
    {
      v8 = *v5;
      if ( *(&(*v5)->m_type.m_storage + v7) != 5 )
      {
        v9 = _mm_load_si128((const __m128i *)((char *)&v8->m_linearVelocity + v7));
        v10 = _mm_load_si128((const __m128i *)((char *)&v8->m_angularVelocity + v7));
        v11 = (char *)v8 + v7;
        *(float *)&v12 = COERCE_FLOAT(*(__int16 *)((char *)&v8->m_motionState.m_timeFactor.m_value + v7) << 16)
                       * v6->m_deltaTime.m_storage;
        v13 = _mm_shuffle_ps((__m128)v12, (__m128)v12, 0);
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_and_ps(
                      _mm_cmpltps(
                        (__m128)_mm_srli_epi32(_mm_slli_epi32(v10, 1u), 1u),
                        hkSweptTransformUtil::_stepMotionStateMaxVelf),
                      _mm_cmpltps(
                        (__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u),
                        hkSweptTransformUtil::_stepMotionStateMaxVelf)),
                    _mm_cmpeqps((__m128)v9, (__m128)v9)),
                  _mm_cmpeqps((__m128)v10, (__m128)v10))) & 7) != 7 )
        {
          *(hkVector4f *)((char *)&v8->m_linearVelocity + v7) = (hkVector4f)transform.m_quad;
          *(hkVector4f *)((char *)&v8->m_angularVelocity + v7) = (hkVector4f)transform.m_quad;
        }
        v14 = v11[202];
        *((__m128 *)v11 + 6) = _mm_shuffle_ps(
                                 *((__m128 *)v11 + 7),
                                 _mm_unpackhi_ps(
                                   *((__m128 *)v11 + 7),
                                   _mm_shuffle_ps(
                                     (__m128)LODWORD(v6->m_startTime.m_storage),
                                     (__m128)LODWORD(v6->m_startTime.m_storage),
                                     0)),
                                 196);
        v15 = hkUFloat8::getEncodedFloat(v14);
        if ( v15 )
          vars0 = (v15 + 243712) << 12;
        else
          vars0 = 0;
        v16 = *(__m128 *)((char *)&v8->m_linearVelocity.m_quad + v7);
        v17 = _mm_shuffle_ps((__m128)vars0, (__m128)vars0, 0);
        v18 = _mm_mul_ps(v16, v16);
        v19 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        if ( v19.m128_f32[0] > (float)(v17.m128_f32[0] * v17.m128_f32[0]) )
        {
          v20 = _mm_rsqrt_ps(v19);
          *(__m128 *)((char *)&v8->m_linearVelocity.m_quad + v7) = _mm_mul_ps(
                                                                     _mm_mul_ps(
                                                                       v17,
                                                                       _mm_mul_ps(
                                                                         _mm_sub_ps(
                                                                           (__m128)_xmm,
                                                                           _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                                                         _mm_mul_ps(*(__m128 *)_xmm, v20))),
                                                                     v16);
        }
        v21 = _mm_shuffle_ps((__m128)0x3F52ACB8u, (__m128)0x3F52ACB8u, 0);
        v22 = _mm_shuffle_ps((__m128)0x3E05A965u, (__m128)0x3E05A965u, 0);
        v23 = _mm_shuffle_ps((__m128)0x3D35E52Au, (__m128)0x3D35E52Au, 0);
        *((__m128 *)v11 + 7) = _mm_add_ps(
                                 _mm_mul_ps(v13, *(__m128 *)((char *)&v8->m_linearVelocity.m_quad + v7)),
                                 *((__m128 *)v11 + 7));
        *((_DWORD *)v11 + 31) = LODWORD(v6->m_invDeltaTime.m_storage);
        v24 = v11[203];
        v25 = *((__m128 *)v11 + 9);
        *((__m128 *)v11 + 8) = v25;
        v26 = _mm_mul_ps(
                _mm_mul_ps((__m128)xmmword_141A711B0, v13),
                *(__m128 *)((char *)&v8->m_angularVelocity.m_quad + v7));
        v27 = _mm_mul_ps(v26, v26);
        v28 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                  _mm_shuffle_ps(v27, v27, 170)),
                _mm_shuffle_ps((__m128)0x3ECF817Au, (__m128)0x3ECF817Au, 0));
        v29 = hkUFloat8::getEncodedFloat(v24);
        if ( v29 )
          v54 = (v29 + 243712) << 12;
        else
          v54 = 0;
        v30 = _mm_rcp_ps((__m128)xmmword_141A713B0);
        v31 = _mm_min_ps(
                _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0),
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v30, (__m128)xmmword_141A713B0)), v30),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)v54, (__m128)v54, 0), v13)));
        v32 = _mm_mul_ps(v31, v31);
        if ( v28.m128_f32[0] > v32.m128_f32[0] )
        {
          v33 = _mm_rsqrt_ps(v28);
          v34 = _mm_cmpleps(v28, (__m128)0i64);
          v35 = _mm_mul_ps(v33, v28);
          v28 = v32;
          v36 = _mm_mul_ps(
                  _mm_andnot_ps(
                    v34,
                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v33)), _mm_mul_ps(*(__m128 *)_xmm, v33))),
                  v31);
          v26 = _mm_mul_ps(v26, v36);
          *(__m128 *)((char *)&v8->m_angularVelocity.m_quad + v7) = _mm_mul_ps(
                                                                      *(__m128 *)((char *)&v8->m_angularVelocity.m_quad
                                                                                + v7),
                                                                      v36);
        }
        v37 = _mm_mul_ps(v28, v28);
        v38 = _mm_shuffle_ps(v25, v25, 255);
        v39 = _mm_shuffle_ps(
                v26,
                _mm_unpackhi_ps(
                  v26,
                  _mm_sub_ps(
                    _mm_sub_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v21, v28)), _mm_mul_ps(v22, v37)),
                    _mm_mul_ps(_mm_mul_ps(v23, v28), v37))),
                196);
        v40 = _mm_mul_ps(v39, v38);
        v41 = _mm_shuffle_ps(v39, v39, 255);
        v42 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v39), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v25));
        v43 = _mm_mul_ps(v25, v41);
        v44 = _mm_mul_ps(v25, v39);
        v45 = _mm_add_ps(v39, v39);
        *((__m128 *)v11 + 11) = v45;
        v46 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 201), v43), v40);
        v47 = _mm_shuffle_ps(
                v46,
                _mm_unpackhi_ps(
                  v46,
                  _mm_sub_ps(
                    _mm_mul_ps(v38, v41),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                      _mm_shuffle_ps(v44, v44, 170)))),
                196);
        v48 = _mm_mul_ps(v47, v47);
        v49 = _mm_add_ps(_mm_shuffle_ps(v48, v48, 78), v48);
        v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 177), v49);
        v51 = _mm_rsqrt_ps(v50);
        v52 = _mm_rsqrt_ps(v28);
        *((__m128 *)v11 + 11) = _mm_shuffle_ps(
                                  v45,
                                  _mm_unpackhi_ps(
                                    v45,
                                    _mm_mul_ps(
                                      _mm_andnot_ps(
                                        _mm_cmpleps(v28, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v28), v52)),
                                            _mm_mul_ps(v52, *(__m128 *)_xmm)),
                                          v28)),
                                      (__m128)xmmword_141A713B0)),
                                  196);
        *((__m128 *)v11 + 9) = _mm_mul_ps(
                                 v47,
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v51)));
        hkRotationf::set((hkRotationf *)(v11 + 32), (hkQuaternionf *)v11 + 9);
        v53 = *((__m128 *)v11 + 10);
        *((__m128 *)v11 + 5) = _mm_sub_ps(
                                 *((__m128 *)v11 + 7),
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v53, v53, 85), *((__m128 *)v11 + 3)),
                                     _mm_mul_ps(_mm_shuffle_ps(*((__m128 *)v11 + 10), v53, 0), *((__m128 *)v11 + 2))),
                                   _mm_mul_ps(_mm_shuffle_ps(v53, v53, 170), *((__m128 *)v11 + 4))));
      }
      ++v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
}

// File Line: 206
// RVA: 0xD8E830
__int64 __fastcall hkRigidMotionUtilApplyForcesAndStep(hkpSolverInfo *solverInfo, hkStepInfo *info, hkVector4f *deltaVel, hkpMotion *const *motions, int numMotions, int motionOffset)
{
  hkStepInfo *v6; // r14
  hkpMotion *const *v7; // r12
  int v8; // edx
  hkpSolverInfo *v9; // r13
  unsigned int v10; // er15
  __int64 v11; // rcx
  char *v12; // rbx
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128i v15; // xmm2
  __m128 *v16; // rdi
  __m128i v17; // xmm3
  unsigned int v18; // ST20_4
  __m128 v19; // xmm6
  char v20; // cl
  unsigned __int16 v21; // ax
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128i v26; // xmm2
  __m128i v27; // xmm3
  unsigned int v28; // ST20_4
  __m128 v29; // xmm12
  char v30; // cl
  unsigned __int16 v31; // ax
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm9
  __m128 v38; // xmm10
  char v39; // cl
  __m128 v40; // xmm11
  __m128 v41; // xmm13
  __m128 v42; // xmm7
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  unsigned __int16 v45; // ax
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  __m128 v52; // xmm0
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm0
  __m128 v58; // xmm3
  __m128 v59; // xmm7
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm4
  __m128 v63; // xmm0
  __m128 v64; // xmm13
  __m128 v65; // xmm7
  __m128 v66; // xmm4
  __m128 v67; // xmm4
  __m128 v68; // xmm0
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm0
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm1
  __m128 v76; // xmm7
  __m128 v77; // xmm1
  __m128 v78; // xmm6
  unsigned __int16 v79; // ax
  __m128 v80; // xmm8
  unsigned __int16 v81; // ax
  __m128 v82; // xmm4
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  __m128 v85; // xmm4
  __m128 v86; // xmm3
  __m128 v87; // xmm1
  __m128 v88; // xmm2
  __m128 v89; // xmm1
  __m128 v90; // xmm10
  __m128 v91; // xmm11
  char v92; // cl
  __m128 v93; // xmm12
  __m128 v94; // xmm9
  __m128 v95; // xmm8
  __m128 v96; // xmm1
  __m128 v97; // xmm7
  unsigned __int16 v98; // ax
  __m128 v99; // xmm2
  __m128 v100; // xmm4
  __m128 v101; // xmm3
  __m128 v102; // xmm5
  __m128 v103; // xmm2
  __m128 v104; // xmm3
  __m128 v105; // xmm0
  __m128 v106; // xmm3
  __m128 v107; // xmm0
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  __m128 v110; // xmm0
  __m128 v111; // xmm3
  __m128 v112; // xmm8
  __m128 v113; // xmm1
  __m128 v114; // xmm2
  __m128 v115; // xmm6
  __m128 v116; // xmm0
  __m128 v117; // xmm9
  __m128 v118; // xmm8
  __m128 v119; // xmm6
  __m128 v120; // xmm6
  __m128 v121; // xmm0
  __m128 v122; // xmm1
  __m128 v123; // xmm2
  __m128 v124; // xmm3
  __m128 v125; // xmm1
  __m128 v126; // xmm1
  int v127; // eax
  signed int v128; // ecx
  signed __int64 v129; // rsi
  __m128 v130; // xmm4
  __m128 v131; // xmm5
  float v132; // ST20_4
  __m128 v133; // xmm2
  __m128 v134; // xmm1
  __m128 v135; // xmm5
  signed __int64 v136; // rdx
  __m128 v137; // xmm2
  __m128 v138; // xmm3
  __m128 v139; // xmm2
  __m128 v140; // xmm3
  __m128i v141; // ST90_16
  __m128 v142; // xmm2
  __m128 v143; // xmm2
  __m128 v144; // xmm1
  __int64 v145; // rax
  int v146; // edx
  unsigned int v148; // [rsp+28h] [rbp-D8h]
  unsigned int v149; // [rsp+2Ch] [rbp-D4h]
  unsigned int v150; // [rsp+30h] [rbp-D0h]
  int v151; // [rsp+34h] [rbp-CCh]
  unsigned int v152; // [rsp+38h] [rbp-C8h]
  unsigned int v153; // [rsp+3Ch] [rbp-C4h]
  hkVector4f v154; // [rsp+A0h] [rbp-60h]
  hkVector4f b; // [rsp+B0h] [rbp-50h]
  hkVector4f v156; // [rsp+C0h] [rbp-40h]
  hkVector4f *v157; // [rsp+1A0h] [rbp+A0h]
  unsigned int numMotionsa; // [rsp+1B0h] [rbp+B0h]

  v157 = deltaVel;
  v6 = info;
  v7 = motions;
  v8 = numMotions - 1;
  v9 = solverInfo;
  v10 = 0x7FFFFFFF;
  v151 = numMotions - 1;
  if ( numMotions - 1 >= 0 )
  {
    v11 = motionOffset;
    while ( 1 )
    {
      v12 = (char *)*v7 + v11;
      v13 = _mm_shuffle_ps(
              (__m128)(unsigned int)(*((signed __int16 *)v12 + 153) << 16),
              (__m128)(unsigned int)(*((signed __int16 *)v12 + 153) << 16),
              0);
      if ( v12[16] == 4 )
        goto LABEL_9;
      if ( v12[16] != 5 )
        break;
LABEL_59:
      v11 = motionOffset;
      ++v7;
      v151 = --v8;
      if ( v8 < 0 )
        return v10;
    }
    if ( v12[16] == 6 )
    {
      v16 = (__m128 *)(v12 + 240);
      v22 = _mm_add_ps(_mm_mul_ps(v13, deltaVel->m_quad), *((__m128 *)v12 + 14));
      *((__m128 *)v12 + 14) = v22;
      v23 = _mm_shuffle_ps((__m128)LODWORD(v6->m_deltaTime.m_storage), (__m128)LODWORD(v6->m_deltaTime.m_storage), 0);
      *((__m128 *)v12 + 14) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 98) << 16),
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 98) << 16),
                                        0),
                                      v23))),
                                v22);
      *((__m128 *)v12 + 15) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 99) << 16),
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 99) << 16),
                                        0),
                                      v23))),
                                *((__m128 *)v12 + 15));
      hkVector4f::setRotatedInverseDir(&b, (hkMatrix3f *)(v12 + 32), (hkVector4f *)v12 + 15);
      v24 = *((__m128 *)v12 + 13);
      v25 = _mm_rcp_ps(v24);
      b.m_quad = _mm_mul_ps(b.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v25)), v25));
      hkVector4f::setRotatedDir(&v156, (hkMatrix3f *)(v12 + 32), &b);
      v26 = _mm_load_si128((const __m128i *)v12 + 14);
      v27 = _mm_load_si128((const __m128i *)v12 + 15);
      *(float *)&v28 = COERCE_FLOAT(*((signed __int16 *)v12 + 100) << 16) * v6->m_deltaTime.m_storage;
      v29 = _mm_shuffle_ps((__m128)v28, (__m128)v28, 0);
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_cmpltps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf),
                    _mm_cmpltps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v26, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf)),
                  _mm_cmpeqps((__m128)v26, (__m128)v26)),
                _mm_cmpeqps((__m128)v27, (__m128)v27))) & 7) != 7 )
      {
        *((hkVector4f *)v12 + 14) = (hkVector4f)transform.m_quad;
        *(hkVector4f *)v16 = (hkVector4f)transform.m_quad;
      }
      v30 = v12[202];
      *((__m128 *)v12 + 6) = _mm_shuffle_ps(
                               *((__m128 *)v12 + 7),
                               _mm_unpackhi_ps(
                                 *((__m128 *)v12 + 7),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(v6->m_startTime.m_storage),
                                   (__m128)LODWORD(v6->m_startTime.m_storage),
                                   0)),
                               196);
      v31 = hkUFloat8::getEncodedFloat(v30);
      if ( v31 )
        numMotionsa = (v31 + 243712) << 12;
      else
        numMotionsa = 0;
      v32 = *((__m128 *)v12 + 14);
      v33 = _mm_shuffle_ps((__m128)numMotionsa, (__m128)numMotionsa, 0);
      v34 = _mm_mul_ps(v32, v32);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170));
      if ( v35.m128_f32[0] > (float)(v33.m128_f32[0] * v33.m128_f32[0]) )
      {
        v36 = _mm_rsqrt_ps(v35);
        *((__m128 *)v12 + 14) = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v36)),
                                    v33),
                                  v32);
      }
      v37 = _mm_shuffle_ps((__m128)0x3F52ACB8u, (__m128)0x3F52ACB8u, 0);
      v38 = _mm_shuffle_ps((__m128)0x3E05A965u, (__m128)0x3E05A965u, 0);
      *((__m128 *)v12 + 7) = _mm_add_ps(_mm_mul_ps(*((__m128 *)v12 + 14), v29), *((__m128 *)v12 + 7));
      *((_DWORD *)v12 + 31) = LODWORD(v6->m_invDeltaTime.m_storage);
      v39 = v12[203];
      v40 = _mm_shuffle_ps((__m128)0x3D35E52Au, (__m128)0x3D35E52Au, 0);
      v41 = *((__m128 *)v12 + 9);
      *((__m128 *)v12 + 8) = v41;
      v42 = _mm_mul_ps(_mm_mul_ps(v29, (__m128)xmmword_141A711B0), *v16);
      v43 = _mm_mul_ps(v42, v42);
      v44 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                _mm_shuffle_ps(v43, v43, 170)),
              _mm_shuffle_ps((__m128)0x3ECF817Au, (__m128)0x3ECF817Au, 0));
      v45 = hkUFloat8::getEncodedFloat(v39);
      if ( v45 )
        v152 = (v45 + 243712) << 12;
      else
        v152 = 0;
      v46 = _mm_rcp_ps((__m128)xmmword_141A713B0);
      v47 = v44;
      v48 = _mm_min_ps(
              _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0),
              _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v46, (__m128)xmmword_141A713B0)), v46),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v152, (__m128)v152, 0), v29)));
      v49 = _mm_mul_ps(v48, v48);
      if ( v44.m128_f32[0] > v49.m128_f32[0] )
      {
        v50 = _mm_rsqrt_ps(v44);
        v51 = _mm_cmpleps(v44, (__m128)0i64);
        v52 = _mm_mul_ps(v50, v44);
        v44 = v49;
        v53 = _mm_mul_ps(
                _mm_andnot_ps(
                  v51,
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v52, v50)), _mm_mul_ps(*(__m128 *)_xmm, v50))),
                v48);
        v42 = _mm_mul_ps(v42, v53);
        v54 = v53;
        v47 = v49;
        *v16 = _mm_mul_ps(v54, *v16);
      }
      v55 = _mm_mul_ps(v47, v44);
      v56 = _mm_sub_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v44, v37)), _mm_mul_ps(v55, v38));
      v57 = _mm_mul_ps(_mm_mul_ps(v44, v40), v55);
      v58 = _mm_shuffle_ps(v41, v41, 255);
      v59 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, _mm_sub_ps(v56, v57)), 196);
      v60 = _mm_mul_ps(v58, v59);
      v61 = _mm_shuffle_ps(v59, v59, 255);
      v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v59), _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v41));
      v63 = _mm_mul_ps(v61, v41);
      v64 = _mm_mul_ps(v41, v59);
      v65 = _mm_add_ps(v59, v59);
      *((__m128 *)v12 + 11) = v65;
      v66 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v62, v62, 201), v63), v60);
      v67 = _mm_shuffle_ps(
              v66,
              _mm_unpackhi_ps(
                v66,
                _mm_sub_ps(
                  _mm_mul_ps(v58, v61),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                    _mm_shuffle_ps(v64, v64, 170)))),
              196);
      v68 = _mm_mul_ps(v67, v67);
      v69 = _mm_add_ps(_mm_shuffle_ps(v68, v68, 78), v68);
      v70 = _mm_add_ps(_mm_shuffle_ps(v69, v69, 177), v69);
      v71 = _mm_rsqrt_ps(v70);
      v72 = _mm_mul_ps(v71, v70);
      v73 = _mm_rsqrt_ps(v44);
      *((__m128 *)v12 + 9) = _mm_mul_ps(
                               v67,
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v72, v71)),
                                 _mm_mul_ps(v71, *(__m128 *)_xmm)));
      *((__m128 *)v12 + 11) = _mm_shuffle_ps(
                                v65,
                                _mm_unpackhi_ps(
                                  v65,
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v44, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v73, v44), v73)),
                                          _mm_mul_ps(v73, *(__m128 *)_xmm)),
                                        v44)),
                                    (__m128)xmmword_141A713B0)),
                                196);
      hkRotationf::set((hkRotationf *)(v12 + 32), (hkQuaternionf *)v12 + 9);
      v74 = *((__m128 *)v12 + 10);
      *((__m128 *)v12 + 5) = _mm_sub_ps(
                               *((__m128 *)v12 + 7),
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v74, v74, 85), *((__m128 *)v12 + 3)),
                                   _mm_mul_ps(_mm_shuffle_ps(*((__m128 *)v12 + 10), v74, 0), *((__m128 *)v12 + 2))),
                                 _mm_mul_ps(_mm_shuffle_ps(v74, v74, 170), *((__m128 *)v12 + 4))));
      hkVector4f::setRotatedInverseDir(&v154, (hkMatrix3f *)(v12 + 32), &v156);
      v154.m_quad = _mm_mul_ps(v154.m_quad, *((__m128 *)v12 + 13));
      hkVector4f::setRotatedDir((hkVector4f *)v12 + 15, (hkMatrix3f *)(v12 + 32), &v154);
      v75 = _mm_mul_ps(*((__m128 *)v12 + 14), *((__m128 *)v12 + 14));
      v76 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
              _mm_shuffle_ps(v75, v75, 170));
      v77 = _mm_mul_ps(*v16, *v16);
      v78 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
              _mm_shuffle_ps(v77, v77, 170));
      v79 = hkUFloat8::getEncodedFloat(v12[202]);
      if ( v79 )
        v153 = (v79 + 243712) << 12;
      else
        v153 = 0;
      v80 = _mm_shuffle_ps((__m128)v153, (__m128)v153, 0);
      v81 = hkUFloat8::getEncodedFloat(v12[203]);
      if ( v81 )
        v150 = (v81 + 243712) << 12;
      else
        v150 = 0;
      v82 = _mm_shuffle_ps((__m128)v150, (__m128)v150, 0);
      if ( v76.m128_f32[0] > (float)(v80.m128_f32[0] * v80.m128_f32[0]) )
      {
        v83 = _mm_rsqrt_ps(v76);
        *((__m128 *)v12 + 14) = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v76, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v83, v76), v83)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v83))),
                                    v80),
                                  *((__m128 *)v12 + 14));
      }
      if ( v78.m128_f32[0] > (float)(v82.m128_f32[0] * v82.m128_f32[0]) )
      {
        v84 = _mm_rsqrt_ps(v78);
        *v16 = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v78, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v84, v78), v84)),
                       _mm_mul_ps(*(__m128 *)_xmm, v84))),
                   v82),
                 *v16);
      }
    }
    else
    {
      if ( v12[16] != 7 )
        *((__m128 *)v12 + 14) = _mm_add_ps(_mm_mul_ps(v13, deltaVel->m_quad), *((__m128 *)v12 + 14));
      v14 = _mm_shuffle_ps((__m128)LODWORD(v6->m_deltaTime.m_storage), (__m128)LODWORD(v6->m_deltaTime.m_storage), 0);
      *((__m128 *)v12 + 14) = _mm_mul_ps(
                                _mm_max_ps(
                                  aabbOut.m_quad,
                                  _mm_sub_ps(
                                    query.m_quad,
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 98) << 16),
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 98) << 16),
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
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 99) << 16),
                                        (__m128)(unsigned int)(*((signed __int16 *)v12 + 99) << 16),
                                        0),
                                      v14))),
                                *((__m128 *)v12 + 15));
LABEL_9:
      v15 = _mm_load_si128((const __m128i *)v12 + 14);
      v16 = (__m128 *)(v12 + 240);
      v17 = _mm_load_si128((const __m128i *)v12 + 15);
      *(float *)&v18 = COERCE_FLOAT(*((signed __int16 *)v12 + 100) << 16) * v6->m_deltaTime.m_storage;
      v19 = _mm_shuffle_ps((__m128)v18, (__m128)v18, 0);
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_cmpltps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v17, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf),
                    _mm_cmpltps(
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v15, 1u), 1u),
                      hkSweptTransformUtil::_stepMotionStateMaxVelf)),
                  _mm_cmpeqps((__m128)v15, (__m128)v15)),
                _mm_cmpeqps((__m128)v17, (__m128)v17))) & 7) != 7 )
      {
        *((hkVector4f *)v12 + 14) = (hkVector4f)transform.m_quad;
        *(hkVector4f *)v16 = (hkVector4f)transform.m_quad;
      }
      v20 = v12[202];
      *((__m128 *)v12 + 6) = _mm_shuffle_ps(
                               *((__m128 *)v12 + 7),
                               _mm_unpackhi_ps(
                                 *((__m128 *)v12 + 7),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(v6->m_startTime.m_storage),
                                   (__m128)LODWORD(v6->m_startTime.m_storage),
                                   0)),
                               196);
      v21 = hkUFloat8::getEncodedFloat(v20);
      if ( v21 )
        v148 = (v21 + 243712) << 12;
      else
        v148 = 0;
      v85 = *((__m128 *)v12 + 14);
      v86 = _mm_shuffle_ps((__m128)v148, (__m128)v148, 0);
      v87 = _mm_mul_ps(v85, v85);
      v88 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
              _mm_shuffle_ps(v87, v87, 170));
      if ( v88.m128_f32[0] > (float)(v86.m128_f32[0] * v86.m128_f32[0]) )
      {
        v89 = _mm_rsqrt_ps(v88);
        *((__m128 *)v12 + 14) = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v89, v88), v89)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v89)),
                                    v86),
                                  v85);
      }
      v90 = _mm_shuffle_ps((__m128)0x3F52ACB8u, (__m128)0x3F52ACB8u, 0);
      v91 = _mm_shuffle_ps((__m128)0x3E05A965u, (__m128)0x3E05A965u, 0);
      *((__m128 *)v12 + 7) = _mm_add_ps(_mm_mul_ps(v19, *((__m128 *)v12 + 14)), *((__m128 *)v12 + 7));
      *((_DWORD *)v12 + 31) = LODWORD(v6->m_invDeltaTime.m_storage);
      v92 = v12[203];
      v93 = _mm_shuffle_ps((__m128)0x3D35E52Au, (__m128)0x3D35E52Au, 0);
      v94 = *((__m128 *)v12 + 9);
      *((__m128 *)v12 + 8) = v94;
      v95 = _mm_mul_ps(_mm_mul_ps(v19, (__m128)xmmword_141A711B0), *v16);
      v96 = _mm_mul_ps(v95, v95);
      v97 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                _mm_shuffle_ps(v96, v96, 170)),
              _mm_shuffle_ps((__m128)0x3ECF817Au, (__m128)0x3ECF817Au, 0));
      v98 = hkUFloat8::getEncodedFloat(v92);
      if ( v98 )
        v149 = (v98 + 243712) << 12;
      else
        v149 = 0;
      v99 = _mm_rcp_ps((__m128)xmmword_141A713B0);
      v100 = _mm_min_ps(
               _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0),
               _mm_mul_ps(
                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v99, (__m128)xmmword_141A713B0)), v99),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)v149, (__m128)v149, 0), v19)));
      v101 = v97;
      v102 = _mm_mul_ps(v100, v100);
      if ( v97.m128_f32[0] > v102.m128_f32[0] )
      {
        v103 = _mm_rsqrt_ps(v97);
        v104 = _mm_cmpleps(v97, (__m128)0i64);
        v105 = _mm_mul_ps(v103, v97);
        v97 = v102;
        v106 = _mm_mul_ps(
                 _mm_andnot_ps(
                   v104,
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v105, v103)), _mm_mul_ps(*(__m128 *)_xmm, v103))),
                 v100);
        v95 = _mm_mul_ps(v95, v106);
        v107 = v106;
        v101 = v102;
        *v16 = _mm_mul_ps(v107, *v16);
      }
      v108 = _mm_mul_ps(v101, v97);
      v109 = _mm_sub_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v97, v90)), _mm_mul_ps(v108, v91));
      v110 = _mm_mul_ps(_mm_mul_ps(v97, v93), v108);
      v111 = _mm_shuffle_ps(v94, v94, 255);
      v112 = _mm_shuffle_ps(v95, _mm_unpackhi_ps(v95, _mm_sub_ps(v109, v110)), 196);
      v113 = _mm_mul_ps(v111, v112);
      v114 = _mm_shuffle_ps(v112, v112, 255);
      v115 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v112),
               _mm_mul_ps(_mm_shuffle_ps(v112, v112, 201), v94));
      v116 = _mm_mul_ps(v114, v94);
      v117 = _mm_mul_ps(v94, v112);
      v118 = _mm_add_ps(v112, v112);
      *((__m128 *)v12 + 11) = v118;
      v119 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v115, v115, 201), v116), v113);
      v120 = _mm_shuffle_ps(
               v119,
               _mm_unpackhi_ps(
                 v119,
                 _mm_sub_ps(
                   _mm_mul_ps(v111, v114),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                     _mm_shuffle_ps(v117, v117, 170)))),
               196);
      v121 = _mm_mul_ps(v120, v120);
      v122 = _mm_add_ps(_mm_shuffle_ps(v121, v121, 78), v121);
      v123 = _mm_add_ps(_mm_shuffle_ps(v122, v122, 177), v122);
      v124 = _mm_rsqrt_ps(v123);
      v125 = _mm_rsqrt_ps(v97);
      *((__m128 *)v12 + 11) = _mm_shuffle_ps(
                                v118,
                                _mm_unpackhi_ps(
                                  v118,
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v97, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v125, v97), v125)),
                                          _mm_mul_ps(v125, *(__m128 *)_xmm)),
                                        v97)),
                                    (__m128)xmmword_141A713B0)),
                                196);
      *((__m128 *)v12 + 9) = _mm_mul_ps(
                               v120,
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v124, v123), v124)),
                                 _mm_mul_ps(v124, *(__m128 *)_xmm)));
      hkRotationf::set((hkRotationf *)(v12 + 32), (hkQuaternionf *)v12 + 9);
      v126 = *((__m128 *)v12 + 10);
      *((__m128 *)v12 + 5) = _mm_sub_ps(
                               *((__m128 *)v12 + 7),
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v126, v126, 85), *((__m128 *)v12 + 3)),
                                   _mm_mul_ps(_mm_shuffle_ps(*((__m128 *)v12 + 10), v126, 0), *((__m128 *)v12 + 2))),
                                 _mm_mul_ps(_mm_shuffle_ps(v126, v126, 170), *((__m128 *)v12 + 4))));
    }
    v127 = (unsigned __int8)v12[17]++ + 1;
    if ( !(v127 & 3) )
    {
      if ( v127 & 0xF )
      {
        v128 = 0;
        v129 = 0i64;
LABEL_50:
        v130 = _mm_mul_ps(*((__m128 *)v12 + 14), *((__m128 *)v12 + 14));
        v131 = *(__m128 *)&v12[16 * (v129 + 16)];
        v132 = fminf(1.0, *((float *)v12 + 48));
        v133 = _mm_shuffle_ps((__m128)LODWORD(v132), (__m128)LODWORD(v132), 0);
        v134 = _mm_mul_ps(*v16, *v16);
        v135 = _mm_shuffle_ps(
                 v131,
                 _mm_unpackhi_ps(
                   v131,
                   _mm_max_ps(
                     _mm_shuffle_ps(v131, v131, 255),
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
                           _mm_shuffle_ps(v134, v134, 170)),
                         _mm_mul_ps(v133, v133)),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                         _mm_shuffle_ps(v130, v130, 170))))),
                 196);
        *(__m128 *)&v12[16 * (v129 + 16)] = v135;
        v136 = (signed __int64)v9 + 32 * (unsigned __int8)v12[204];
        v137 = _mm_sub_ps(v135, *((__m128 *)v12 + 7));
        v138 = (__m128)*(unsigned int *)(v136 + 4i64 * v128 + 116);
        v139 = _mm_mul_ps(v137, v137);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v139, v139, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v139, v139, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v139, v139, 170))) > COERCE_FLOAT(_mm_shuffle_ps(v138, v138, 0)) )
          goto LABEL_63;
        v140 = (__m128)*(unsigned int *)(v136 + 4i64 * v128 + 124);
        v141.m128i_i32[0] = *(_DWORD *)&v12[4 * v129 + 288];
        v141.m128i_i32[1] = (unsigned int)v141.m128i_i32[0] >> 8;
        v141.m128i_i32[3] = (unsigned int)v141.m128i_i32[0] >> 24;
        v141.m128i_i32[2] = (unsigned int)v141.m128i_i32[0] >> 16;
        v142 = _mm_sub_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_sub_epi32(_mm_and_si128(_mm_load_si128((const __m128i *)&_xmm), v141), (__m128i)_xmm)),
                   _mm_shuffle_ps((__m128)0x3C0CCCCDu, (__m128)0x3C0CCCCDu, 0)),
                 *((__m128 *)v12 + 9));
        v143 = _mm_mul_ps(v142, v142);
        v144 = _mm_add_ps(_mm_shuffle_ps(v143, v143, 78), v143);
        if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v144, v144, 177)) + v144.m128_f32[0]) > COERCE_FLOAT(_mm_shuffle_ps(v140, v140, 0)) )
        {
LABEL_63:
          v145 = *(unsigned __int16 *)&v12[2 * v129 + 18];
          *(_WORD *)&v12[2 * v129 + 18] = (*(_WORD *)&v12[2 * v129 + 18] & 0x7F | (unsigned __int16)((unsigned __int8)v9->m_deactivationNumInactiveFramesSelectFlag[v129] << 7)) << 7;
          _mm_store_si128(
            (__m128i *)&v12[16 * (v129 + 16)],
            _mm_srli_si128(_mm_slli_si128(*((__m128i *)v12 + 7), 4), 4));
          *(_DWORD *)&v12[4 * v129 + 288] = hkVector4UtilImpl<float>::packQuaternionIntoInt32((hkVector4f *)v12 + 9);
        }
        else
        {
          *(_WORD *)&v12[2 * v129 + 18] = ((*(_WORD *)&v12[2 * v129 + 18] & 0x7F | (unsigned __int16)((unsigned __int8)v9->m_deactivationNumInactiveFramesSelectFlag[v129] << 7)) << 7) | ((*(_WORD *)&v12[2 * v129 + 18] & 0x7F) - ((*(_WORD *)&v12[2 * v129 + 18] & 0x7F) >> 6) + 1);
        }
        goto LABEL_54;
      }
      if ( v127 != 256 )
      {
        v128 = 1;
        v12[17] = 0;
        v129 = 1i64;
        goto LABEL_50;
      }
      v12[17] = -1;
    }
LABEL_54:
    deltaVel = v157;
    v146 = *((_WORD *)v12 + 10) & 0x7F;
    if ( (*((_WORD *)v12 + 9) & 0x7F) > v146 )
      v146 = *((_WORD *)v12 + 9) & 0x7F;
    if ( (signed int)v10 < v146 )
      v146 = v10;
    v10 = v146;
    v8 = v151;
    goto LABEL_59;
  }
  return v10;
}

// File Line: 290
// RVA: 0xD8F7B0
hkpVelocityAccumulator *__fastcall hkRigidMotionUtilBuildAccumulators(hkStepInfo *info, hkpMotion *const *motions, int numMotions, __int64 motionOffset, hkpVelocityAccumulator *accumulatorsOut)
{
  int v5; // er11
  hkpMotion *const *v6; // r10
  hkpVelocityAccumulator *v7; // r8
  hkpMotion *v8; // rdx
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  unsigned int v18; // ST00_4
  unsigned int accumulatorsOuta; // [rsp+40h] [rbp+28h]

  v5 = numMotions - 1;
  v6 = motions;
  if ( numMotions - 1 < 0 )
    return accumulatorsOut;
  v7 = accumulatorsOut;
  motionOffset = (signed int)motionOffset;
  do
  {
    v8 = *v6;
    switch ( *((unsigned __int8 *)&(*v6)->m_type.m_storage + motionOffset) )
    {
      case 0u:
      case 3u:
      case 6u:
        *(_WORD *)&v7->m_type.m_storage = 0;
        v9 = *(__m128 *)((char *)&v8->m_motionState.m_transform.m_rotation.m_col2.m_quad + motionOffset);
        v10 = _mm_unpacklo_ps(
                *(__m128 *)((char *)&v8->m_motionState.m_transform.m_rotation.m_col0.m_quad + motionOffset),
                *(__m128 *)((char *)&v8->m_motionState.m_transform.m_rotation.m_col1.m_quad + motionOffset));
        v7->m_scratch2.m_quad = _mm_shuffle_ps(
                                  _mm_unpackhi_ps(
                                    *(__m128 *)((char *)&v8->m_motionState.m_transform.m_rotation.m_col0.m_quad
                                              + motionOffset),
                                    *(__m128 *)((char *)&v8->m_motionState.m_transform.m_rotation.m_col1.m_quad
                                              + motionOffset)),
                                  v9,
                                  228);
        v11 = _mm_movelh_ps(v10, v9);
        v7->m_scratch0.m_quad = v11;
        v7->m_scratch1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v11, v10), v9, 212);
        v7->m_invMasses = *(hkVector4f *)((char *)&v8->m_inertiaAndMassInv + motionOffset);
        v7->m_linearVel = *(hkVector4f *)((char *)&v8->m_linearVelocity + motionOffset);
        v12 = *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass0.m_quad + motionOffset);
        v7->m_scratch3.m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps(
                                        _mm_shuffle_ps(
                                          (__m128)LODWORD(info->m_startTime.m_storage),
                                          (__m128)LODWORD(info->m_startTime.m_storage),
                                          0),
                                        _mm_shuffle_ps(v12, v12, 255)),
                                      _mm_shuffle_ps(
                                        *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad
                                                  + motionOffset),
                                        *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad
                                                  + motionOffset),
                                        255)),
                                    _mm_sub_ps(
                                      *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad
                                                + motionOffset),
                                      v12)),
                                  v12);
        v7->m_angularVel = *(hkVector4f *)((char *)&v8->m_angularVelocity + motionOffset);
        goto LABEL_5;
      case 2u:
        v7->m_type.m_storage = 0;
        goto $buildRigidBodyAccumulator;
      case 4u:
        *(_WORD *)&v7->m_type.m_storage = 1;
        v7->m_invMasses = 0i64;
        v7->m_scratch3 = *(hkVector4f *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1 + motionOffset);
        v7->m_angularVel = *(hkVector4f *)((char *)&v8->m_angularVelocity + motionOffset);
        v7->m_linearVel = *(hkVector4f *)((char *)&v8->m_linearVelocity + motionOffset);
        v7->m_scratch0 = (hkVector4f)transform.m_quad;
        v7->m_scratch1 = (hkVector4f)direction.m_quad;
        v7->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
        LODWORD(v7->m_gravityFactor) = *(__int16 *)((char *)&v8->m_gravityFactor.m_value + motionOffset) << 16;
        break;
      case 5u:
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
      case 7u:
        v7->m_type.m_storage = 2;
$buildRigidBodyAccumulator:
        v7->m_context.m_storage = 0;
        v13 = (__m128)LODWORD(info->m_deltaTime.m_storage);
        v7->m_invMasses = *(hkVector4f *)((char *)&v8->m_inertiaAndMassInv + motionOffset);
        v14 = *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass0.m_quad + motionOffset);
        v15 = _mm_shuffle_ps(v13, v13, 0);
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
                                        *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad
                                                  + motionOffset),
                                        *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad
                                                  + motionOffset),
                                        255)),
                                    _mm_sub_ps(
                                      *(__m128 *)((char *)&v8->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad
                                                + motionOffset),
                                      v14)),
                                  v14);
        v16 = _mm_shuffle_ps(
                *(__m128 *)((char *)&v8->m_angularVelocity.m_quad + motionOffset),
                _mm_unpackhi_ps(*(__m128 *)((char *)&v8->m_angularVelocity.m_quad + motionOffset), (__m128)0i64),
                196);
        v7->m_angularVel.m_quad = v16;
        accumulatorsOuta = *(__int16 *)((char *)&v8->m_motionState.m_angularDamping.m_value + motionOffset) << 16;
        v7->m_angularVel.m_quad = _mm_mul_ps(
                                    _mm_max_ps(
                                      aabbOut.m_quad,
                                      _mm_sub_ps(
                                        query.m_quad,
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)accumulatorsOuta, (__m128)accumulatorsOuta, 0),
                                          v15))),
                                    v16);
        v17 = _mm_shuffle_ps(
                *(__m128 *)((char *)&v8->m_linearVelocity.m_quad + motionOffset),
                _mm_unpackhi_ps(*(__m128 *)((char *)&v8->m_linearVelocity.m_quad + motionOffset), (__m128)0i64),
                196);
        v7->m_linearVel.m_quad = v17;
        v18 = *(__int16 *)((char *)&v8->m_motionState.m_linearDamping.m_value + motionOffset) << 16;
        v7->m_linearVel.m_quad = _mm_mul_ps(
                                   _mm_max_ps(
                                     aabbOut.m_quad,
                                     _mm_sub_ps(
                                       query.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps((__m128)v18, (__m128)v18, 0), v15))),
                                   v17);
        v7->m_scratch0 = (hkVector4f)transform.m_quad;
        v7->m_scratch1 = (hkVector4f)direction.m_quad;
        v7->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
LABEL_5:
        v7->m_deactivationClass = *((unsigned __int8 *)&v8->m_motionState.m_deactivationClass + motionOffset);
        LODWORD(v7->m_gravityFactor) = *(__int16 *)((char *)&v8->m_gravityFactor.m_value + motionOffset) << 16;
        break;
      default:
        break;
    }
    ++v6;
    ++v7;
    --v5;
  }
  while ( v5 >= 0 );
  return v7;
}

// File Line: 425
// RVA: 0xD8FB20
hkpVelocityAccumulator *__fastcall hkRigidMotionUtilApplyForcesAndBuildAccumulators(hkStepInfo *info, hkpMotion *const *motions, int numMotions, int motionOffset, hkpVelocityAccumulator *accumulatorsOut)
{
  int v5; // ebx
  hkpMotion *const *v6; // r11
  __int64 v7; // r10
  hkpVelocityAccumulator *v8; // r9
  __m128 *v9; // r8
  hkpMotion *v10; // rdx
  __m128 v11; // xmm2
  unsigned int v12; // ST00_4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  unsigned int v18; // ST04_4
  __m128 v19; // xmm2
  unsigned int v20; // ST08_4
  __m128 v21; // xmm2
  unsigned int accumulatorsOuta; // [rsp+40h] [rbp+28h]

  v5 = numMotions - 1;
  v6 = motions;
  if ( numMotions - 1 < 0 )
    return accumulatorsOut;
  v7 = motionOffset;
  v8 = accumulatorsOut;
  v9 = &accumulatorsOut->m_scratch2.m_quad;
  do
  {
    v10 = *v6;
    switch ( *((unsigned __int8 *)&(*v6)->m_type.m_storage + v7) )
    {
      case 0u:
      case 3u:
      case 6u:
        accumulatorsOuta = *(__int16 *)((char *)&v10->m_motionState.m_angularDamping.m_value + v7) << 16;
        v11 = _mm_shuffle_ps(
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                0);
        *(__m128 *)((char *)&v10->m_angularVelocity.m_quad + v7) = _mm_mul_ps(
                                                                     _mm_max_ps(
                                                                       aabbOut.m_quad,
                                                                       _mm_sub_ps(
                                                                         query.m_quad,
                                                                         _mm_mul_ps(
                                                                           _mm_shuffle_ps(
                                                                             (__m128)accumulatorsOuta,
                                                                             (__m128)accumulatorsOuta,
                                                                             0),
                                                                           v11))),
                                                                     *(__m128 *)((char *)&v10->m_angularVelocity.m_quad
                                                                               + v7));
        v12 = *(__int16 *)((char *)&v10->m_motionState.m_linearDamping.m_value + v7) << 16;
        *(__m128 *)((char *)&v10->m_linearVelocity.m_quad + v7) = _mm_mul_ps(
                                                                    _mm_max_ps(
                                                                      aabbOut.m_quad,
                                                                      _mm_sub_ps(
                                                                        query.m_quad,
                                                                        _mm_mul_ps(
                                                                          _mm_shuffle_ps((__m128)v12, (__m128)v12, 0),
                                                                          v11))),
                                                                    *(__m128 *)((char *)&v10->m_linearVelocity.m_quad
                                                                              + v7));
        v8->m_type.m_storage = 0;
        v9[-6].m128_i8[1] = 0;
        v13 = *(__m128 *)((char *)&v10->m_motionState.m_transform.m_rotation.m_col2.m_quad + v7);
        v14 = _mm_unpacklo_ps(
                *(__m128 *)((char *)&v10->m_motionState.m_transform.m_rotation.m_col0.m_quad + v7),
                *(__m128 *)((char *)&v10->m_motionState.m_transform.m_rotation.m_col1.m_quad + v7));
        *v9 = _mm_shuffle_ps(
                _mm_unpackhi_ps(
                  *(__m128 *)((char *)&v10->m_motionState.m_transform.m_rotation.m_col0.m_quad + v7),
                  *(__m128 *)((char *)&v10->m_motionState.m_transform.m_rotation.m_col1.m_quad + v7)),
                v13,
                228);
        v15 = _mm_movelh_ps(v14, v13);
        v9[-2] = v15;
        v9[-1] = _mm_shuffle_ps(_mm_movehl_ps(v15, v14), v13, 212);
        v9[-3] = *(__m128 *)((char *)&v10->m_inertiaAndMassInv.m_quad + v7);
        v9[-5] = *(__m128 *)((char *)&v10->m_linearVelocity.m_quad + v7);
        v16 = *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass0.m_quad + v7);
        v9[1] = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_shuffle_ps(
                          (__m128)LODWORD(info->m_startTime.m_storage),
                          (__m128)LODWORD(info->m_startTime.m_storage),
                          0),
                        _mm_shuffle_ps(v16, v16, 255)),
                      _mm_shuffle_ps(
                        *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7),
                        *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7),
                        255)),
                    _mm_sub_ps(
                      *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7),
                      v16)),
                  v16);
        v17 = *(__m128 *)((char *)&v10->m_angularVelocity.m_quad + v7);
        v9[-4] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v9[-1]),
                     _mm_mul_ps(
                       _mm_shuffle_ps(*(__m128 *)((char *)&v10->m_angularVelocity.m_quad + v7), v17, 0),
                       v9[-2])),
                   _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), *v9));
        goto LABEL_5;
      case 2u:
        v8->m_type.m_storage = 0;
        goto $buildRigidBodyAccumulator_0;
      case 4u:
        v8->m_type.m_storage = 1;
        v9[-6].m128_i8[1] = 0;
        v9[-3] = 0i64;
        v9[1] = *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7);
        v9[-4] = *(__m128 *)((char *)&v10->m_angularVelocity.m_quad + v7);
        v9[-5] = *(__m128 *)((char *)&v10->m_linearVelocity.m_quad + v7);
        v9[-2] = transform.m_quad;
        v9[-1] = direction.m_quad;
        *(hkVector4f *)v9 = (hkVector4f)stru_141A71280.m_quad;
        v9[-6].m128_i32[2] = *(__int16 *)((char *)&v10->m_gravityFactor.m_value + v7) << 16;
        break;
      case 5u:
        v9[-6].m128_i8[1] = 0;
        v8->m_type.m_storage = 1;
        v9[-6].m128_i32[2] = 0;
        v9[-3] = 0i64;
        v9[-5] = 0i64;
        v9[-4] = 0i64;
        v9[1] = 0i64;
        v9[-2] = transform.m_quad;
        v9[-1] = direction.m_quad;
        *(hkVector4f *)v9 = (hkVector4f)stru_141A71280.m_quad;
        break;
      case 7u:
        v8->m_type.m_storage = 2;
$buildRigidBodyAccumulator_0:
        v9[-6].m128_i8[1] = 0;
        v18 = *(__int16 *)((char *)&v10->m_motionState.m_angularDamping.m_value + v7) << 16;
        v19 = _mm_shuffle_ps(
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                (__m128)LODWORD(info->m_deltaTime.m_storage),
                0);
        *(__m128 *)((char *)&v10->m_angularVelocity.m_quad + v7) = _mm_mul_ps(
                                                                     _mm_max_ps(
                                                                       aabbOut.m_quad,
                                                                       _mm_sub_ps(
                                                                         query.m_quad,
                                                                         _mm_mul_ps(
                                                                           _mm_shuffle_ps((__m128)v18, (__m128)v18, 0),
                                                                           v19))),
                                                                     *(__m128 *)((char *)&v10->m_angularVelocity.m_quad
                                                                               + v7));
        v20 = *(__int16 *)((char *)&v10->m_motionState.m_linearDamping.m_value + v7) << 16;
        *(__m128 *)((char *)&v10->m_linearVelocity.m_quad + v7) = _mm_mul_ps(
                                                                    _mm_max_ps(
                                                                      aabbOut.m_quad,
                                                                      _mm_sub_ps(
                                                                        query.m_quad,
                                                                        _mm_mul_ps(
                                                                          _mm_shuffle_ps((__m128)v20, (__m128)v20, 0),
                                                                          v19))),
                                                                    *(__m128 *)((char *)&v10->m_linearVelocity.m_quad
                                                                              + v7));
        v9[-3] = *(__m128 *)((char *)&v10->m_inertiaAndMassInv.m_quad + v7);
        v21 = *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass0.m_quad + v7);
        v9[1] = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_shuffle_ps(
                          (__m128)LODWORD(info->m_startTime.m_storage),
                          (__m128)LODWORD(info->m_startTime.m_storage),
                          0),
                        _mm_shuffle_ps(v21, v21, 255)),
                      _mm_shuffle_ps(
                        *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7),
                        *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7),
                        255)),
                    _mm_sub_ps(
                      *(__m128 *)((char *)&v10->m_motionState.m_sweptTransform.m_centerOfMass1.m_quad + v7),
                      v21)),
                  v21);
        v9[-4] = *(__m128 *)((char *)&v10->m_angularVelocity.m_quad + v7);
        v9[-5] = *(__m128 *)((char *)&v10->m_linearVelocity.m_quad + v7);
        v9[-2] = transform.m_quad;
        v9[-1] = direction.m_quad;
        *(hkVector4f *)v9 = (hkVector4f)stru_141A71280.m_quad;
LABEL_5:
        v9[-6].m128_i32[1] = *((unsigned __int8 *)&v10->m_motionState.m_deactivationClass + v7);
        v9[-6].m128_i32[2] = *(__int16 *)((char *)&v10->m_gravityFactor.m_value + v7) << 16;
        break;
      default:
        break;
    }
    ++v6;
    ++v8;
    v9 += 8;
    --v5;
  }
  while ( v5 >= 0 );
  return v8;
}

// File Line: 569
// RVA: 0xD8FF60
hkRigidMotionUtilApplyAccumulators

