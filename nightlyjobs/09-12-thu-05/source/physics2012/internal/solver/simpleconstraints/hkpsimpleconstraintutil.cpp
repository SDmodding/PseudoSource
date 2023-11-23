// File Line: 39
// RVA: 0xDE7E40
void __fastcall hkSimpleConstraintUtil_invertSymmetric(hkMatrix3f *in, hkSimdFloat32 *eps3, hkMatrix3f *out)
{
  hkVector4f v3; // xmm1
  hkVector4f v4; // xmm3
  __m128 v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm7
  __m128i v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm2

  v3.m_quad = (__m128)in->m_col2;
  v4.m_quad = (__m128)in->m_col1;
  v5 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 201);
  v6 = _mm_mul_ps(v5, in->m_col0.m_quad);
  v7 = _mm_shuffle_ps(v4.m_quad, v4.m_quad, 201);
  v8 = _mm_sub_ps(_mm_mul_ps(v5, v4.m_quad), _mm_mul_ps(v3.m_quad, v7));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_shuffle_ps(in->m_col0.m_quad, in->m_col0.m_quad, 201);
  v11 = _mm_mul_ps(v10, v4.m_quad);
  v12 = _mm_mul_ps(in->m_col0.m_quad, v9);
  v13 = _mm_sub_ps(_mm_mul_ps(v10, v3.m_quad), v6);
  v14 = _mm_sub_ps(_mm_mul_ps(v7, in->m_col0.m_quad), v11);
  v15 = (__m128i)_mm_max_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                     _mm_shuffle_ps(v12, v12, 170)),
                   eps3->m_real);
  v16 = _mm_cmpeq_ps((__m128)v15, (__m128)0i64);
  v17 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v15, 0x1Fu), 0x1Fu), (__m128)_xmm), v16),
          _mm_andnot_ps(v16, _mm_div_ps(query.m_quad, (__m128)v15)));
  out->m_col2.m_quad = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v17);
  out->m_col1.m_quad = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v17);
  out->m_col0.m_quad = _mm_mul_ps(v17, v9);
}

// File Line: 64
// RVA: 0xDE73D0
void __fastcall hkSimpleConstraintUtil_InitInfo(
        hkpSimpleConstraintInfoInitInput *bodyA,
        hkpSimpleConstraintInfoInitInput *bodyB,
        hkRotationf *directions,
        hkpSimpleConstraintInfo *out)
{
  hkMatrix3f *p_m_invMassMatrix; // r15
  hkpSimpleConstraintInfoInitInput *v6; // rbp
  hkVector4f *p_m_invMasses; // rdi
  __int64 v8; // r14
  signed __int64 v10; // rbx
  __m128 v11; // xmm1
  hkVector4f *v12; // rax
  __int64 v13; // rcx
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 m_quad; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __int64 v21; // rcx
  __m128 *p_m_quad; // rax
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  float v28; // xmm0_4
  hkTransformf *m_transform; // rax
  __m128 v30; // xmm6
  __m128 v31; // xmm7
  __m128 v32; // xmm0
  hkVector4f v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm6
  __m128 v36; // xmm0
  hkSimdFloat32 eps3; // [rsp+20h] [rbp-A8h] BYREF
  hkMatrix3f a; // [rsp+30h] [rbp-98h] BYREF

  p_m_invMassMatrix = &out->m_invMassMatrix;
  v6 = bodyA;
  p_m_invMasses = &out->m_bodyInfo[0].m_invMasses;
  v8 = 2i64;
  v10 = (char *)&a.m_col2 - (char *)out - 80;
  v11 = _mm_add_ps(
          _mm_shuffle_ps(bodyA->m_invMasses.m_quad, bodyA->m_invMasses.m_quad, 255),
          _mm_shuffle_ps(bodyB->m_invMasses.m_quad, bodyB->m_invMasses.m_quad, 255));
  out->m_invMassMatrix.m_col0.m_quad = _mm_mul_ps(v11, transform.m_quad);
  out->m_invMassMatrix.m_col1.m_quad = _mm_mul_ps(v11, direction.m_quad);
  out->m_invMassMatrix.m_col2.m_quad = _mm_mul_ps(v11, stru_141A71280.m_quad);
  out->m_base = *directions;
  do
  {
    v12 = p_m_invMasses - 4;
    v13 = 2i64;
    v14 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(directions->m_col0.m_quad, directions->m_col0.m_quad, 201),
              v6->m_massRelPos.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_massRelPos.m_quad, v6->m_massRelPos.m_quad, 201), directions->m_col0.m_quad));
    p_m_invMasses[-6].m_quad = _mm_shuffle_ps(v14, v14, 201);
    v15 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(directions->m_col1.m_quad, directions->m_col1.m_quad, 201),
              v6->m_massRelPos.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_massRelPos.m_quad, v6->m_massRelPos.m_quad, 201), directions->m_col1.m_quad));
    p_m_invMasses[-5].m_quad = _mm_shuffle_ps(v15, v15, 201);
    v16 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(directions->m_col2.m_quad, directions->m_col2.m_quad, 201),
              v6->m_massRelPos.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_massRelPos.m_quad, v6->m_massRelPos.m_quad, 201), directions->m_col2.m_quad));
    p_m_invMasses[-4].m_quad = _mm_shuffle_ps(v16, v16, 201);
    m_quad = v6->m_invInertia.m_col0.m_quad;
    v18 = v6->m_invInertia.m_col1.m_quad;
    v19 = v6->m_invInertia.m_col2.m_quad;
    do
    {
      v20 = v12->m_quad;
      --v12;
      --v13;
      v12[4].m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v18),
                          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v19));
    }
    while ( v13 >= 0 );
    hkMatrix3f::transpose((hkMatrix3f *)&p_m_invMasses[-6]);
    v21 = 2i64;
    p_m_quad = &p_m_invMasses[-1].m_quad;
    v23 = p_m_invMasses[-6].m_quad;
    v24 = p_m_invMasses[-5].m_quad;
    v25 = p_m_invMasses[-4].m_quad;
    do
    {
      v26 = *p_m_quad--;
      --v21;
      *(__m128 *)((char *)p_m_quad + v10 + 16) = _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v24),
                                                     _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v23)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v25));
    }
    while ( v21 >= 0 );
    hkMatrix3f::add(p_m_invMassMatrix, &a);
    p_m_invMasses += 8;
    v10 -= 128i64;
    p_m_invMasses[-8] = v6->m_invMasses;
    v27 = _mm_max_ps(_mm_shuffle_ps(v6->m_invMasses.m_quad, v6->m_invMasses.m_quad, 255), (__m128)xmmword_141A712D0);
    v28 = _mm_rcp_ps(v27).m128_f32[0];
    p_m_invMasses[-7].m_quad.m128_f32[0] = (float)(2.0 - (float)(v27.m128_f32[0] * v28)) * v28;
    m_transform = v6->m_transform;
    v6 = bodyB;
    p_m_invMasses[-7].m_quad.m128_u64[1] = (unsigned __int64)m_transform;
    --v8;
  }
  while ( v8 );
  v30 = _mm_mul_ps((__m128)xmmword_141A712D0, (__m128)xmmword_141A712D0);
  eps3.m_real = _mm_mul_ps((__m128)xmmword_141A712D0, v30);
  hkSimpleConstraintUtil_invertSymmetric(p_m_invMassMatrix, &eps3, &out->m_massMatrix);
  v31 = _mm_max_ps(
          (__m128)xmmword_141A712D0,
          _mm_shuffle_ps(p_m_invMassMatrix->m_col0.m_quad, p_m_invMassMatrix->m_col0.m_quad, 0));
  v32 = _mm_rcp_ps(v31);
  p_m_invMassMatrix->m_col0.m_quad = _mm_shuffle_ps(
                                       p_m_invMassMatrix->m_col0.m_quad,
                                       _mm_unpackhi_ps(
                                         p_m_invMassMatrix->m_col0.m_quad,
                                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v32)), v32)),
                                       196);
  v33.m_quad = (__m128)out->m_invMassMatrix.m_col1;
  v34 = _mm_mul_ps(
          _mm_shuffle_ps(out->m_invMassMatrix.m_col2.m_quad, out->m_invMassMatrix.m_col2.m_quad, 216),
          v33.m_quad);
  v35 = _mm_max_ps(v30, _mm_sub_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 170)));
  v36 = _mm_rcp_ps(v35);
  out->m_invMassMatrix.m_col1.m_quad = _mm_shuffle_ps(
                                         v33.m_quad,
                                         _mm_unpackhi_ps(
                                           v33.m_quad,
                                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v36)), v36)),
                                         196);
}

// File Line: 131
// RVA: 0xDE77F0
void __fastcall hkSimpleConstraintUtil_applyImpulse(
        hkpSimpleConstraintInfo *info,
        hkVector4f *impulse,
        const __m128i *velA,
        const __m128i *velB)
{
  __m128 v4; // xmm2

  v4 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 85), info->m_base.m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 0), info->m_base.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 170), info->m_base.m_col2.m_quad));
  *(__m128 *)velA = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          info->m_bodyInfo[0].m_invMasses.m_quad,
                          info->m_bodyInfo[0].m_invMasses.m_quad,
                          255),
                        v4),
                      *(__m128 *)velA);
  *(__m128 *)velB = _mm_sub_ps(
                      *(__m128 *)velB,
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          info->m_bodyInfo[1].m_invMasses.m_quad,
                          info->m_bodyInfo[1].m_invMasses.m_quad,
                          255),
                        v4));
  velA[1] = (const __m128i)_mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 85),
                                   info->m_bodyInfo[0].m_invIjac.m_col1.m_quad),
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 0),
                                   info->m_bodyInfo[0].m_invIjac.m_col0.m_quad)),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 170),
                                 info->m_bodyInfo[0].m_invIjac.m_col2.m_quad)),
                             (__m128)velA[1]);
  velB[1] = (const __m128i)_mm_sub_ps(
                             (__m128)velB[1],
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 85),
                                   info->m_bodyInfo[1].m_invIjac.m_col1.m_quad),
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 0),
                                   info->m_bodyInfo[1].m_invIjac.m_col0.m_quad)),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 170),
                                 info->m_bodyInfo[1].m_invIjac.m_col2.m_quad)));
  velA[1] = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(velA + 1), 4), 4);
  velB[1] = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(velB + 1), 4), 4);
  *velA = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(velA), 4), 4);
  *velB = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(velB), 4), 4);
}

// File Line: 151
// RVA: 0xDE76E0
void __fastcall hkSimpleConstraintUtil_getPointVelocity(
        hkpSimpleConstraintInfo *info,
        hkpBodyVelocity *velA,
        hkpBodyVelocity *velB,
        hkVector4f *out)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm7
  __m128 v7; // xmm9
  hkVector4f v8; // xmm1
  __m128 v9; // xmm8
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  hkVector4f v13; // xmm1

  v4.m_quad = (__m128)velB->m_angular;
  v5.m_quad = (__m128)info->m_base.m_col1;
  v6.m_quad = (__m128)info->m_base.m_col2;
  v7 = _mm_sub_ps(velA->m_linear.m_quad, velB->m_linear.m_quad);
  v8.m_quad = (__m128)info->m_base.m_col0;
  v9 = _mm_unpackhi_ps(v8.m_quad, v5.m_quad);
  v10 = _mm_unpacklo_ps(v8.m_quad, v5.m_quad);
  v11 = _mm_movelh_ps(v10, v6.m_quad);
  v12 = _mm_movehl_ps(v11, v10);
  v13.m_quad = (__m128)velA->m_angular;
  out->m_quad = _mm_add_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), info->m_bodyInfo[0].m_jacT.m_col1.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), info->m_bodyInfo[0].m_jacT.m_col0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 170), info->m_bodyInfo[0].m_jacT.m_col2.m_quad)),
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), info->m_bodyInfo[1].m_jacT.m_col1.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 0), info->m_bodyInfo[1].m_jacT.m_col0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170), info->m_bodyInfo[1].m_jacT.m_col2.m_quad))),
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v12, v6.m_quad, 212)),
                      _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v11)),
                    _mm_mul_ps(_mm_shuffle_ps(v9, v6.m_quad, 228), _mm_shuffle_ps(v7, v7, 170))));
}

// File Line: 175
// RVA: 0xDE7920
float __fastcall hkSimpleConstraintUtil_Collide(
        hkpSimpleConstraintInfo *info,
        hkpSimpleConstraintUtilCollideParams *params,
        hkpBodyVelocity *velA,
        hkpBodyVelocity *velB)
{
  float m_externalSeperatingVelocity; // xmm1_4
  bool v10; // cf
  __m128 v11; // xmm15
  __m128 v12; // xmm2
  __m128 v13; // xmm14
  __m128i v14; // xmm13
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm8
  __m128 v24; // xmm1
  __m128 v25; // xmm11
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  hkVector4f v29; // xmm10
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  hkVector4f v32; // xmm1
  __m128 v33; // xmm13
  __m128 v34; // xmm3
  __m128 v35; // xmm5
  __m128 v36; // xmm6
  __m128 v37; // xmm7
  __m128 v38; // xmm1
  __m128 v39; // xmm5
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm7
  __m128 v47; // xmm13
  __m128 v48; // xmm4
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  hkVector4f v52; // xmm0
  __m128 v53; // xmm13
  __m128 v54; // xmm13
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm5
  unsigned int v58; // [rsp+20h] [rbp-D8h]
  hkVector4f out; // [rsp+30h] [rbp-C8h] BYREF
  __m128 v60; // [rsp+40h] [rbp-B8h]

  if ( !HK_flyingcolors_constraintutil.m_bool )
  {
    hkpCheckKeycode();
    hkpProcessFlyingColors(&HK_flyingcolors_constraintutil);
    if ( !HK_flyingcolors_constraintutil.m_bool )
      return 0.0;
  }
  hkSimpleConstraintUtil_getPointVelocity(info, velA, velB, &out);
  m_externalSeperatingVelocity = params->m_externalSeperatingVelocity;
  if ( out.m_quad.m128_f32[0] > m_externalSeperatingVelocity )
  {
    v10 = m_externalSeperatingVelocity < params->m_extraSeparatingVelocity;
    out.m_quad.m128_i32[0] = LODWORD(params->m_externalSeperatingVelocity);
    if ( !v10 )
      return 0.0;
  }
  v11 = _mm_shuffle_ps((__m128)LODWORD(params->m_maxImpulse), (__m128)LODWORD(params->m_maxImpulse), 0);
  v14 = (__m128i)_mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), out.m_quad);
  v12 = _mm_shuffle_ps((__m128)v14, (__m128)v14, 0);
  v13 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(params->m_restitution), (__m128)LODWORD(params->m_restitution), 0),
          v12);
  *(float *)v14.m128i_i32 = _mm_shuffle_ps(
                              (__m128)LODWORD(params->m_extraSeparatingVelocity),
                              (__m128)LODWORD(params->m_extraSeparatingVelocity),
                              0).m128_f32[0]
                          + (float)(v13.m128_f32[0] + v12.m128_f32[0]);
  v15 = _mm_shuffle_ps((__m128)v14, (__m128)v14, 0);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 85), info->m_massMatrix.m_col1.m_quad),
            _mm_mul_ps(v15, info->m_massMatrix.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 170), info->m_massMatrix.m_col2.m_quad));
  v17 = _mm_shuffle_ps(v16, v16, 0);
  v18 = _mm_rcp_ps(v17);
  v19 = _mm_cmplt_ps(v11, v17);
  params->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(v19) != 0;
  *(float *)&v58 = params->m_friction * params->m_friction;
  v20 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18), v11), v16),
            v19),
          _mm_andnot_ps(v19, v16));
  out.m_quad = v20;
  v21 = _mm_mul_ps(v20, v20);
  if ( (float)(_mm_shuffle_ps(v21, v21, 170).m128_f32[0] + _mm_shuffle_ps(v21, v21, 85).m128_f32[0]) > (float)(_mm_shuffle_ps(v21, v21, 0).m128_f32[0] * _mm_shuffle_ps((__m128)v58, (__m128)v58, 0).m128_f32[0])
    || _mm_shuffle_ps(v20, v20, 0).m128_f32[0] < 0.0 )
  {
    v22 = (__m128)_mm_slli_si128(_mm_srli_si128(v14, 4), 4);
    v23 = 0i64;
    v24 = _mm_mul_ps(v22, v22);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_mul_ps(_mm_shuffle_ps(info->m_invMassMatrix.m_col0.m_quad, info->m_invMassMatrix.m_col0.m_quad, 255), v15);
    v27 = _mm_cmplt_ps(v11, v26);
    v28 = _mm_min_ps(v26, v11);
    v23.m128_f32[0] = v28.m128_f32[0];
    params->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(v27) != 0;
    v29.m_quad = (__m128)info->m_invMassMatrix.m_col0;
    v30 = _mm_shuffle_ps(info->m_invMassMatrix.m_col1.m_quad, info->m_invMassMatrix.m_col1.m_quad, 255);
    v31 = _mm_mul_ps(v29.m_quad, v28);
    v32.m_quad = (__m128)info->m_invMassMatrix.m_col2;
    v33 = _mm_sub_ps((__m128)v14, v31);
    v34 = _mm_shuffle_ps(v32.m_quad, v32.m_quad, 85);
    v35 = _mm_shuffle_ps(v33, v33, 170);
    v36 = _mm_shuffle_ps(v33, v33, 85);
    v37 = _mm_movelh_ps(
            _mm_unpacklo_ps(
              (__m128)0i64,
              _mm_mul_ps(
                _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 170), v36), _mm_mul_ps(v34, v35)),
                v30)),
            _mm_unpacklo_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(info->m_invMassMatrix.m_col1.m_quad, info->m_invMassMatrix.m_col1.m_quad, 85),
                    v35),
                  _mm_mul_ps(v34, v36)),
                v30),
              (__m128)0i64));
    v38 = _mm_mul_ps(v37, v37);
    v39 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
            _mm_shuffle_ps(v38, v38, 170));
    v40 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(params->m_friction), (__m128)LODWORD(params->m_friction), 0),
            _mm_shuffle_ps(v23, v23, 0));
    v41 = _mm_rcp_ps(v39);
    v42 = _mm_mul_ps(v40, v40);
    v60 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v39)), v41), v42);
    v43 = _mm_cmplt_ps(v42, v39);
    v44 = _mm_rsqrt_ps(v60);
    v45 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v60, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v44), v44)),
                      _mm_mul_ps(*(__m128 *)_xmm, v44)),
                    v60)),
                v37),
              v43),
            _mm_andnot_ps(v43, v37));
    v46 = _mm_or_ps(
            _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_468[24], v45),
            _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_468[24], v23));
    v47 = _mm_sub_ps(
            _mm_sub_ps(v33, _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), info->m_invMassMatrix.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), info->m_invMassMatrix.m_col2.m_quad));
    v48 = _mm_shuffle_ps(v46, v46, 0);
    v49 = _mm_max_ps(
            _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v47, v47, 0), v13), _mm_shuffle_ps(v29.m_quad, v29.m_quad, 255)),
            (__m128)0i64);
    v50 = _mm_cmplt_ps(v11, _mm_add_ps(v48, v49));
    v51 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v11, v48), v50), _mm_andnot_ps(v50, v49));
    params->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(v50) != 0;
    v52.m_quad = (__m128)info->m_invMassMatrix.m_col0;
    v46.m128_f32[0] = v48.m128_f32[0] + v51.m128_f32[0];
    v53 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)_mm_sub_ps(v47, _mm_mul_ps(v52.m_quad, v51)), 4), 4);
    v54 = _mm_mul_ps(v53, v53);
    v55 = _mm_min_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
              _mm_shuffle_ps(v54, v54, 170)),
            v25);
    v56 = _mm_rsqrt_ps(v55);
    v57 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v52.m_quad, v52.m_quad, 255),
                _mm_andnot_ps(
                  _mm_cmple_ps(v55, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v56), v56)),
                      _mm_mul_ps(*(__m128 *)_xmm, v56)),
                    v55))),
              _mm_shuffle_ps((__m128)LODWORD(params->m_extraSlope), (__m128)LODWORD(params->m_extraSlope), 0)),
            _mm_shuffle_ps(v46, v46, 0));
    v46.m128_f32[0] = fmin(v11.m128_f32[0], v57.m128_f32[0]);
    params->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(_mm_cmplt_ps(v11, v57)) != 0;
    out.m_quad = v46;
  }
  hkSimpleConstraintUtil_applyImpulse(info, &out, (const __m128i *)velA, (const __m128i *)velB);
  return out.m_quad.m128_f32[0];
}

// File Line: 417
// RVA: 0xDE7320
float __fastcall hkpSimpleConstraintInfo::BodyInfo::getEnergy(
        hkpSimpleConstraintInfo::BodyInfo *this,
        hkpBodyVelocity *vel)
{
  hkTransformf *m_transform; // rax
  __m128 m_quad; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  hkVector4f v7; // xmm1
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v12; // xmm3

  m_transform = this->m_transform;
  m_quad = m_transform->m_rotation.m_col2.m_quad;
  v4 = _mm_unpacklo_ps(m_transform->m_rotation.m_col0.m_quad, m_transform->m_rotation.m_col1.m_quad);
  v5 = _mm_movelh_ps(v4, m_quad);
  v6 = _mm_movehl_ps(v5, v4);
  v7.m_quad = (__m128)vel->m_angular;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 85), _mm_shuffle_ps(v6, m_quad, 212)),
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 0), v5)),
         _mm_mul_ps(
           _mm_shuffle_ps(v7.m_quad, v7.m_quad, 170),
           _mm_shuffle_ps(
             _mm_unpackhi_ps(m_transform->m_rotation.m_col0.m_quad, m_transform->m_rotation.m_col1.m_quad),
             m_quad,
             228)));
  v9 = _mm_max_ps(this->m_invMasses.m_quad, *(__m128 *)&epsilon);
  v10 = _mm_rcp_ps(v9);
  v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v10)), v10);
  v12 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), _mm_mul_ps(vel->m_linear.m_quad, vel->m_linear.m_quad)),
          _mm_mul_ps(_mm_mul_ps(v8, v8), v11));
  return (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
       + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
}

