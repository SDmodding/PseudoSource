// File Line: 39
// RVA: 0xDE7E40
void __fastcall hkSimpleConstraintUtil_invertSymmetric(hkMatrix3f *in, hkSimdFloat32 *eps3, hkMatrix3f *out)
{
  hkVector4f v3; // xmm1
  hkVector4f v4; // xmm3
  __m128 v5; // xmm2
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  __m128 v8; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm7
  __m128i v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2

  v3.m_quad = (__m128)in->m_col2;
  v4.m_quad = (__m128)in->m_col1;
  v5 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 201);
  v6 = _mm_shuffle_ps(v4.m_quad, v4.m_quad, 201);
  v7 = _mm_sub_ps(_mm_mul_ps(v5, v4.m_quad), _mm_mul_ps(in->m_col2.m_quad, v6));
  v8 = _mm_shuffle_ps(in->m_col0.m_quad, in->m_col0.m_quad, 201);
  v9 = _mm_shuffle_ps(v7, v7, 201);
  v10 = _mm_mul_ps(in->m_col0.m_quad, v9);
  v11 = _mm_sub_ps(_mm_mul_ps(v8, v3.m_quad), _mm_mul_ps(v5, in->m_col0.m_quad));
  v12 = _mm_sub_ps(_mm_mul_ps(v6, in->m_col0.m_quad), _mm_mul_ps(v8, v4.m_quad));
  v13 = (__m128i)_mm_max_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                     _mm_shuffle_ps(v10, v10, 170)),
                   eps3->m_real);
  v14 = _mm_cmpeqps((__m128)v13, (__m128)0i64);
  v15 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v13, 0x1Fu), 0x1Fu), (__m128)_xmm), v14),
          _mm_andnot_ps(v14, _mm_div_ps(query.m_quad, (__m128)v13)));
  out->m_col2.m_quad = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v15);
  out->m_col1.m_quad = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v15);
  out->m_col0.m_quad = _mm_mul_ps(v15, v9);
}

// File Line: 64
// RVA: 0xDE73D0
void __fastcall hkSimpleConstraintUtil_InitInfo(hkpSimpleConstraintInfoInitInput *bodyA, hkpSimpleConstraintInfoInitInput *bodyB, hkMatrix3f *directions, hkpSimpleConstraintInfo *out)
{
  hkMatrix3f *v4; // r15
  hkpSimpleConstraintInfoInitInput *v5; // r12
  hkpSimpleConstraintInfoInitInput *v6; // rbp
  hkMatrix3f *v7; // rdi
  signed __int64 v8; // r14
  hkMatrix3f *v9; // r13
  signed __int64 v10; // rbx
  __m128 v11; // xmm1
  signed __int64 v12; // rax
  signed __int64 v13; // rcx
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  signed __int64 v21; // rcx
  __m128 *v22; // rax
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  float v28; // xmm0_4
  hkTransformf *v29; // rax
  __m128 *v30; // r13
  __m128 v31; // xmm6
  __m128 v32; // xmm7
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm6
  __m128 v37; // xmm0
  hkSimdFloat32 eps3; // [rsp+20h] [rbp-A8h]
  hkMatrix3f a; // [rsp+30h] [rbp-98h]
  hkpSimpleConstraintInfo *v40; // [rsp+E8h] [rbp+20h]

  v40 = out;
  v4 = &out->m_invMassMatrix;
  v5 = bodyB;
  v6 = bodyA;
  v7 = (hkMatrix3f *)&out->m_bodyInfo[0].m_invMasses;
  v8 = 2i64;
  v9 = directions;
  v10 = (char *)&a.m_col2 - (char *)out - 80;
  v11 = _mm_add_ps(
          _mm_shuffle_ps(bodyA->m_invMasses.m_quad, bodyA->m_invMasses.m_quad, 255),
          _mm_shuffle_ps(bodyB->m_invMasses.m_quad, bodyB->m_invMasses.m_quad, 255));
  v4->m_col0.m_quad = _mm_mul_ps(v11, transform.m_quad);
  v4->m_col1.m_quad = _mm_mul_ps(v11, direction.m_quad);
  v4->m_col2.m_quad = _mm_mul_ps(v11, stru_141A71280.m_quad);
  out->m_base.m_col0 = directions->m_col0;
  out->m_base.m_col1 = directions->m_col1;
  out->m_base.m_col2 = directions->m_col2;
  do
  {
    v12 = (signed __int64)&v7[-2].m_col2;
    v13 = 2i64;
    v14 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9->m_col0.m_quad, v9->m_col0.m_quad, 201), v6->m_massRelPos.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_massRelPos.m_quad, v6->m_massRelPos.m_quad, 201), v9->m_col0.m_quad));
    v7[-2].m_col0.m_quad = _mm_shuffle_ps(v14, v14, 201);
    v15 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9->m_col1.m_quad, v9->m_col1.m_quad, 201), v6->m_massRelPos.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_massRelPos.m_quad, v6->m_massRelPos.m_quad, 201), v9->m_col1.m_quad));
    v7[-2].m_col1.m_quad = _mm_shuffle_ps(v15, v15, 201);
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9->m_col2.m_quad, v9->m_col2.m_quad, 201), v6->m_massRelPos.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_massRelPos.m_quad, v6->m_massRelPos.m_quad, 201), v9->m_col2.m_quad));
    v7[-2].m_col2.m_quad = _mm_shuffle_ps(v16, v16, 201);
    v17 = v6->m_invInertia.m_col0.m_quad;
    v18 = v6->m_invInertia.m_col1.m_quad;
    v19 = v6->m_invInertia.m_col2.m_quad;
    do
    {
      v20 = *(__m128 *)v12;
      v12 -= 16i64;
      --v13;
      *(__m128 *)(v12 + 64) = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v18),
                                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v17)),
                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v19));
    }
    while ( v13 >= 0 );
    hkMatrix3f::transpose(v7 - 2);
    v21 = 2i64;
    v22 = &v7[-1].m_col2.m_quad;
    v23 = v7[-2].m_col0.m_quad;
    v24 = v7[-2].m_col1.m_quad;
    v25 = v7[-2].m_col2.m_quad;
    do
    {
      v26 = *v22;
      --v22;
      --v21;
      *(__m128 *)((char *)v22 + v10 + 16) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v24),
                                                _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v23)),
                                              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v25));
    }
    while ( v21 >= 0 );
    hkMatrix3f::add(v4, &a);
    v7 = (hkMatrix3f *)((char *)v7 + 128);
    v10 -= 128i64;
    v7[-3].m_col1 = v6->m_invMasses;
    v27 = _mm_max_ps(_mm_shuffle_ps(v6->m_invMasses.m_quad, v6->m_invMasses.m_quad, 255), (__m128)xmmword_141A712D0);
    LODWORD(v28) = (unsigned __int128)_mm_rcp_ps(v27);
    v7[-3].m_col2.m_quad.m128_f32[0] = (float)(2.0 - (float)(v27.m128_f32[0] * v28)) * v28;
    v29 = v6->m_transform;
    v6 = v5;
    v7[-3].m_col2.m_quad.m128_u64[1] = (unsigned __int64)v29;
    --v8;
  }
  while ( v8 );
  v30 = (__m128 *)v40;
  v31 = _mm_mul_ps((__m128)xmmword_141A712D0, (__m128)xmmword_141A712D0);
  eps3.m_real = _mm_mul_ps((__m128)xmmword_141A712D0, v31);
  hkSimpleConstraintUtil_invertSymmetric(v4, &eps3, &v40->m_massMatrix);
  v32 = _mm_max_ps((__m128)xmmword_141A712D0, _mm_shuffle_ps(v4->m_col0.m_quad, v4->m_col0.m_quad, 0));
  v33 = _mm_rcp_ps(v32);
  v4->m_col0.m_quad = _mm_shuffle_ps(
                        v4->m_col0.m_quad,
                        _mm_unpackhi_ps(
                          v4->m_col0.m_quad,
                          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v33)), v33)),
                        196);
  v34 = v40->m_invMassMatrix.m_col1.m_quad;
  v35 = _mm_mul_ps(_mm_shuffle_ps(v30[21], v30[21], 216), v34);
  v36 = _mm_max_ps(v31, _mm_sub_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 170)));
  v37 = _mm_rcp_ps(v36);
  v30[20] = _mm_shuffle_ps(
              v34,
              _mm_unpackhi_ps(v30[20], _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v37)), v37)),
              196);
}

// File Line: 131
// RVA: 0xDE77F0
void __fastcall hkSimpleConstraintUtil_applyImpulse(hkpSimpleConstraintInfo *info, hkVector4f *impulse, hkpBodyVelocity *velA, hkpBodyVelocity *velB)
{
  __m128 v4; // xmm2

  v4 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 85), info->m_base.m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 0), info->m_base.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(impulse->m_quad, impulse->m_quad, 170), info->m_base.m_col2.m_quad));
  velA->m_linear.m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(
                                info->m_bodyInfo[0].m_invMasses.m_quad,
                                info->m_bodyInfo[0].m_invMasses.m_quad,
                                255),
                              v4),
                            velA->m_linear.m_quad);
  velB->m_linear.m_quad = _mm_sub_ps(
                            velB->m_linear.m_quad,
                            _mm_mul_ps(
                              _mm_shuffle_ps(
                                info->m_bodyInfo[1].m_invMasses.m_quad,
                                info->m_bodyInfo[1].m_invMasses.m_quad,
                                255),
                              v4));
  velA->m_angular.m_quad = _mm_add_ps(
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
                             velA->m_angular.m_quad);
  velB->m_angular.m_quad = _mm_sub_ps(
                             velB->m_angular.m_quad,
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
  _mm_store_si128(
    (__m128i *)&velA->m_angular,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&velA->m_angular), 4), 4));
  _mm_store_si128(
    (__m128i *)&velB->m_angular,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&velB->m_angular), 4), 4));
  _mm_store_si128((__m128i *)velA, _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)velA), 4), 4));
  _mm_store_si128((__m128i *)velB, _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)velB), 4), 4));
}

// File Line: 151
// RVA: 0xDE76E0
void __fastcall hkSimpleConstraintUtil_getPointVelocity(hkpSimpleConstraintInfo *info, hkpBodyVelocity *velA, hkpBodyVelocity *velB, hkVector4f *out)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm7
  __m128 v7; // xmm9
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  hkVector4f v11; // xmm1

  v4.m_quad = (__m128)velB->m_angular;
  v5.m_quad = (__m128)info->m_base.m_col1;
  v6.m_quad = (__m128)info->m_base.m_col2;
  v7 = _mm_sub_ps(velA->m_linear.m_quad, velB->m_linear.m_quad);
  v8 = _mm_unpacklo_ps(info->m_base.m_col0.m_quad, v5.m_quad);
  v9 = _mm_movelh_ps(v8, v6.m_quad);
  v10 = _mm_movehl_ps(v9, v8);
  v11.m_quad = (__m128)velA->m_angular;
  out->m_quad = _mm_add_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 85), info->m_bodyInfo[0].m_jacT.m_col1.m_quad),
                        _mm_mul_ps(
                          _mm_shuffle_ps(velA->m_angular.m_quad, v11.m_quad, 0),
                          info->m_bodyInfo[0].m_jacT.m_col0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 170), info->m_bodyInfo[0].m_jacT.m_col2.m_quad)),
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), info->m_bodyInfo[1].m_jacT.m_col1.m_quad),
                        _mm_mul_ps(
                          _mm_shuffle_ps(velB->m_angular.m_quad, v4.m_quad, 0),
                          info->m_bodyInfo[1].m_jacT.m_col0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170), info->m_bodyInfo[1].m_jacT.m_col2.m_quad))),
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v10, v6.m_quad, 212)),
                      _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v9)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(_mm_unpackhi_ps(info->m_base.m_col0.m_quad, v5.m_quad), v6.m_quad, 228),
                      _mm_shuffle_ps(v7, v7, 170))));
}

// File Line: 175
// RVA: 0xDE7920
float __fastcall hkSimpleConstraintUtil_Collide(hkpSimpleConstraintInfo *info, hkpSimpleConstraintUtilCollideParams *params, hkpBodyVelocity *velA, hkpBodyVelocity *velB)
{
  hkpBodyVelocity *v4; // rsi
  hkpBodyVelocity *v5; // rbp
  hkpSimpleConstraintUtilCollideParams *v6; // rbx
  hkpSimpleConstraintInfo *v7; // rdi
  float v9; // xmm1_4
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
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm8
  __m128 v25; // xmm1
  __m128 v26; // xmm11
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm10
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm13
  __m128 v35; // xmm3
  __m128 v36; // xmm5
  __m128 v37; // xmm6
  __m128 v38; // xmm7
  __m128 v39; // xmm1
  __m128 v40; // xmm5
  __m128 v41; // xmm3
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm4
  __m128 v47; // xmm7
  __m128 v48; // xmm13
  __m128 v49; // xmm4
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm5
  __m128 v54; // xmm13
  __m128 v55; // xmm13
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  __m128 v58; // xmm5
  hkVector4f out; // [rsp+30h] [rbp-C8h]
  __m128 v60; // [rsp+40h] [rbp-B8h]

  v4 = velB;
  v5 = velA;
  v6 = params;
  v7 = info;
  if ( !HK_flyingcolors_constraintutil.m_bool )
  {
    hkpCheckKeycode();
    hkpProcessFlyingColors(&HK_flyingcolors_constraintutil);
    if ( !HK_flyingcolors_constraintutil.m_bool )
      return 0.0;
  }
  hkSimpleConstraintUtil_getPointVelocity(v7, v5, v4, &out);
  v9 = v6->m_externalSeperatingVelocity;
  if ( out.m_quad.m128_f32[0] > v9 )
  {
    v10 = v9 < v6->m_extraSeparatingVelocity;
    out.m_quad.m128_i32[0] = LODWORD(v6->m_externalSeperatingVelocity);
    if ( !v10 )
      return 0.0;
  }
  v11 = _mm_shuffle_ps((__m128)LODWORD(v6->m_maxImpulse), (__m128)LODWORD(v6->m_maxImpulse), 0);
  v14 = (__m128i)_mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), out.m_quad);
  v12 = _mm_shuffle_ps((__m128)v14, (__m128)v14, 0);
  v13 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v6->m_restitution), (__m128)LODWORD(v6->m_restitution), 0), v12);
  *(float *)v14.m128i_i32 = COERCE_FLOAT(
                              _mm_shuffle_ps(
                                (__m128)LODWORD(v6->m_extraSeparatingVelocity),
                                (__m128)LODWORD(v6->m_extraSeparatingVelocity),
                                0))
                          + (float)(v13.m128_f32[0] + v12.m128_f32[0]);
  v15 = _mm_shuffle_ps((__m128)v14, (__m128)v14, 0);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 85), v7->m_massMatrix.m_col1.m_quad),
            _mm_mul_ps(v15, v7->m_massMatrix.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 170), v7->m_massMatrix.m_col2.m_quad));
  v17 = _mm_shuffle_ps(v16, v16, 0);
  v18 = _mm_rcp_ps(v17);
  v19 = _mm_cmpltps(v11, v17);
  v6->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(v19) != 0;
  v20 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18), v11);
  v18.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                         (__m128)COERCE_UNSIGNED_INT(v6->m_friction * v6->m_friction),
                                         (__m128)COERCE_UNSIGNED_INT(v6->m_friction * v6->m_friction),
                                         0);
  v21 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v20, v16), v19), _mm_andnot_ps(v19, v16));
  out.m_quad = v21;
  v22 = _mm_mul_ps(v21, v21);
  if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85))) > (float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)) * v18.m128_f32[0])
    || COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)) < 0.0 )
  {
    v23 = (__m128)_mm_slli_si128(_mm_srli_si128(v14, 4), 4);
    v24 = 0i64;
    v25 = _mm_mul_ps(v23, v23);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_mul_ps(_mm_shuffle_ps(v7->m_invMassMatrix.m_col0.m_quad, v7->m_invMassMatrix.m_col0.m_quad, 255), v15);
    v28 = _mm_cmpltps(v11, v27);
    v29 = _mm_min_ps(v27, v11);
    v24.m128_f32[0] = v29.m128_f32[0];
    v6->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(v28) != 0;
    v30 = v7->m_invMassMatrix.m_col0.m_quad;
    v31 = _mm_shuffle_ps(v7->m_invMassMatrix.m_col1.m_quad, v7->m_invMassMatrix.m_col1.m_quad, 255);
    v32 = _mm_mul_ps(v7->m_invMassMatrix.m_col0.m_quad, v29);
    v33 = v7->m_invMassMatrix.m_col2.m_quad;
    v34 = _mm_sub_ps((__m128)v14, v32);
    v35 = _mm_shuffle_ps(v33, v33, 85);
    v36 = _mm_shuffle_ps(v34, v34, 170);
    v37 = _mm_shuffle_ps(v34, v34, 85);
    v38 = _mm_movelh_ps(
            _mm_unpacklo_ps(
              (__m128)0i64,
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v37), _mm_mul_ps(v35, v36)), v31)),
            _mm_unpacklo_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v7->m_invMassMatrix.m_col1.m_quad, v7->m_invMassMatrix.m_col1.m_quad, 85),
                    v36),
                  _mm_mul_ps(v35, v37)),
                v31),
              (__m128)0i64));
    v39 = _mm_mul_ps(v38, v38);
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v41 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(v6->m_friction), (__m128)LODWORD(v6->m_friction), 0),
            _mm_shuffle_ps(v24, v24, 0));
    v42 = _mm_rcp_ps(v40);
    v43 = _mm_mul_ps(v41, v41);
    v60 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v40)), v42), v43);
    v44 = _mm_cmpltps(v43, v40);
    v45 = _mm_rsqrt_ps(v60);
    v46 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v60, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v45), v45)),
                      _mm_mul_ps(*(__m128 *)_xmm, v45)),
                    v60)),
                v38),
              v44),
            _mm_andnot_ps(v44, v38));
    v47 = _mm_or_ps(
            _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_468[24], v46),
            _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_468[24], v24));
    v48 = _mm_sub_ps(
            _mm_sub_ps(v34, _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v7->m_invMassMatrix.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v7->m_invMassMatrix.m_col2.m_quad));
    v49 = _mm_shuffle_ps(v47, v47, 0);
    v50 = _mm_max_ps(
            _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v48, v48, 0), v13), _mm_shuffle_ps(v30, v30, 255)),
            (__m128)0i64);
    v51 = _mm_cmpltps(v11, _mm_add_ps(v49, v50));
    v52 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v11, v49), v51), _mm_andnot_ps(v51, v50));
    v6->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(v51) != 0;
    v53 = v7->m_invMassMatrix.m_col0.m_quad;
    v47.m128_f32[0] = v49.m128_f32[0] + v52.m128_f32[0];
    v54 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)_mm_sub_ps(v48, _mm_mul_ps(v53, v52)), 4), 4);
    v55 = _mm_mul_ps(v54, v54);
    v56 = _mm_min_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170)),
            v26);
    v57 = _mm_rsqrt_ps(v56);
    v58 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v53, v53, 255),
                _mm_andnot_ps(
                  _mm_cmpleps(v56, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v57), v57)),
                      _mm_mul_ps(*(__m128 *)_xmm, v57)),
                    v56))),
              _mm_shuffle_ps((__m128)LODWORD(v6->m_extraSlope), (__m128)LODWORD(v6->m_extraSlope), 0)),
            _mm_shuffle_ps(v47, v47, 0));
    v47.m128_f32[0] = fmin(v11.m128_f32[0], v58.m128_f32[0]);
    v6->m_contactImpulseLimitBreached.m_bool = _mm_movemask_ps(_mm_cmpltps(v11, v58)) != 0;
    out.m_quad = v47;
  }
  hkSimpleConstraintUtil_applyImpulse(v7, &out, v5, v4);
  return out.m_quad.m128_f32[0];
}

// File Line: 417
// RVA: 0xDE7320
float __fastcall hkpSimpleConstraintInfo::BodyInfo::getEnergy(hkpSimpleConstraintInfo::BodyInfo *this, hkpBodyVelocity *vel)
{
  hkTransformf *v2; // rax
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  hkVector4f v7; // xmm1
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v12; // xmm3

  v2 = this->m_transform;
  v3 = v2->m_rotation.m_col2.m_quad;
  v4 = _mm_unpacklo_ps(v2->m_rotation.m_col0.m_quad, v2->m_rotation.m_col1.m_quad);
  v5 = _mm_movelh_ps(v4, v3);
  v6 = _mm_movehl_ps(v5, v4);
  v7.m_quad = (__m128)vel->m_angular;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 85), _mm_shuffle_ps(v6, v3, 212)),
           _mm_mul_ps(_mm_shuffle_ps(vel->m_angular.m_quad, v7.m_quad, 0), v5)),
         _mm_mul_ps(
           _mm_shuffle_ps(v7.m_quad, v7.m_quad, 170),
           _mm_shuffle_ps(_mm_unpackhi_ps(v2->m_rotation.m_col0.m_quad, v2->m_rotation.m_col1.m_quad), v3, 228)));
  v9 = _mm_max_ps(this->m_invMasses.m_quad, *(__m128 *)&epsilon);
  v10 = _mm_rcp_ps(v9);
  v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v10)), v10);
  v12 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), _mm_mul_ps(vel->m_linear.m_quad, vel->m_linear.m_quad)),
          _mm_mul_ps(_mm_mul_ps(v8, v8), v11));
  return (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
       + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
}

