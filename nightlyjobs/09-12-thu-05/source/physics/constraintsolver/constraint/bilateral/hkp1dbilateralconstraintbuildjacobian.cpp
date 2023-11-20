// File Line: 34
// RVA: 0xD4ED90
void __fastcall hk1dAngularBilateralConstraintBuildJacobian(hkp1dAngularBilateralConstraintInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkVector4f v3; // xmm1
  hkpVelocityAccumulator *v4; // rax
  hkpVelocityAccumulator *v5; // r9
  __m128 *v6; // r10
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  float v15; // xmm0_4

  v3.m_quad = (__m128)info->m_constrainedDofW;
  v4 = in->m_bodyB.m_storage;
  v5 = in->m_bodyA.m_storage;
  v6 = (__m128 *)out->m_jacobianSchemas.m_storage;
  v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v3.m_quad);
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), v5->m_scratch1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 0), v5->m_scratch0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 170), v5->m_scratch2.m_quad));
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v4->m_scratch1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v4->m_scratch0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v4->m_scratch2.m_quad));
  v10 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v9, v9), v4->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v8, v8), v5->m_invMasses.m_quad));
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)),
          *(__m128 *)&epsilon);
  v12 = _mm_rcp_ps(v11);
  v13 = _mm_mul_ps(
          _mm_shuffle_ps(
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            0),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v11)), v12));
  v14 = _mm_mul_ps(info->m_perpZeroErrorAxisBinW.m_quad, info->m_zeroErrorAxisAinW.m_quad);
  v15 = in->m_rhsFactor.m_storage;
  out->m_jacobianSchemas.m_storage += 32;
  *v6 = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, v13), 196);
  v6[1] = _mm_shuffle_ps(
            v9,
            _mm_unpackhi_ps(
              v9,
              _mm_mul_ps(
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170))),
                _mm_shuffle_ps((__m128)LODWORD(v15), (__m128)LODWORD(v15), 0))),
            196);
  *(float *)v6->m128_u64 = *(float *)v6->m128_u64 + 0.00000011920929;
  LOBYTE(v6->m128_u64[0]) = 12;
}

// File Line: 54
// RVA: 0xD4F0E0
void __fastcall hk1dLinearFrictionBuildJacobian(hkp1dLinearFrictionInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkVector4f v3; // xmm3
  hkpVelocityAccumulator *v4; // rax
  hkpVelocityAccumulator *v5; // r9
  hkpJacobianSchema *v6; // r10
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkpSolverResults *v22; // rax
  float v23; // [rsp+20h] [rbp+8h]

  v3.m_quad = (__m128)info->m_constrainedDofW;
  v4 = in->m_bodyB.m_storage;
  v5 = in->m_bodyA.m_storage;
  v6 = out->m_jacobianSchemas.m_storage;
  v23 = in->m_virtMassFactor.m_storage;
  v7 = _mm_sub_ps(info->m_pivot.m_quad, v4->m_scratch3.m_quad);
  v8 = _mm_shuffle_ps(v3.m_quad, v3.m_quad, 201);
  v9 = _mm_sub_ps(info->m_pivot.m_quad, v5->m_scratch3.m_quad);
  *(hkVector4f *)v6 = (hkVector4f)v3.m_quad;
  v10 = _mm_sub_ps(_mm_mul_ps(v8, v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v3.m_quad));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v3.m_quad), _mm_mul_ps(v8, v7));
  v13 = v5->m_invMasses.m_quad;
  v14 = _mm_shuffle_ps(v12, v12, 201);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v4->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v4->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v4->m_scratch2.m_quad));
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v5->m_scratch2.m_quad));
  v17 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v15, v15), v4->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v16, v16), v13));
  v18 = _mm_shuffle_ps(
          v17,
          _mm_unpackhi_ps(v17, _mm_max_ps(_mm_add_ps(v13, v4->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = _mm_rcp_ps(v20);
  *(__m128 *)&v6[32] = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v20), 196);
  v22 = info->m_lastSolverResults.m_storage;
  *(__m128 *)&v6[16] = _mm_shuffle_ps(
                         v16,
                         _mm_unpackhi_ps(
                           v16,
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(v23), (__m128)LODWORD(v23), 0),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v20)), v21))),
                         196);
  v19.m128_f32[0] = v22->m_internalSolverData * in->m_rhsFactor.m_storage;
  out->m_jacobianSchemas.m_storage = v6 + 64;
  *(_DWORD *)&v6[12] = v19.m128_i32[0];
  v20.m128_f32[0] = *(float *)v6 + 0.00000011920929;
  *(float *)&v6[48] = info->m_maxFrictionForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(_DWORD *)v6 = v20.m128_i32[0];
  *v6 = (hkpJacobianSchema)9;
}

// File Line: 72
// RVA: 0xD4E6E0
void __fastcall hk1dLinearBilateralConstraintBuildJacobian(hkp1dLinearBilateralConstraintInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v3; // rax
  hkpVelocityAccumulator *v4; // r9
  hkpJacobianSchema *v5; // r10
  hkVector4f v6; // xmm6
  hkVector4f v7; // xmm7
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  float v32; // [rsp+30h] [rbp+8h]

  v3 = in->m_bodyA.m_storage;
  v4 = in->m_bodyB.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  v32 = in->m_virtMassFactor.m_storage;
  v6.m_quad = (__m128)info->m_pivotA;
  v7.m_quad = (__m128)info->m_constrainedDofW;
  v8 = _mm_sub_ps(info->m_pivotA.m_quad, v3->m_scratch3.m_quad);
  v9 = _mm_sub_ps(info->m_pivotA.m_quad, v4->m_scratch3.m_quad);
  v10 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 201);
  *(hkVector4f *)v5 = (hkVector4f)v7.m_quad;
  v11 = _mm_shuffle_ps(v8, v8, 201);
  v12 = _mm_mul_ps(v8, v10);
  v13 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v7.m_quad);
  v14 = _mm_mul_ps(v10, v9);
  v15 = v4->m_invMasses.m_quad;
  v16 = _mm_sub_ps(v12, _mm_mul_ps(v11, v7.m_quad));
  v17 = _mm_sub_ps(v13, v14);
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v19 = _mm_shuffle_ps(v16, v16, 201);
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v3->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v3->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v3->m_scratch2.m_quad));
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v4->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v4->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v4->m_scratch2.m_quad));
  v22 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v21, v21), v15), _mm_mul_ps(_mm_mul_ps(v20, v20), v3->m_invMasses.m_quad));
  v23 = _mm_shuffle_ps(
          v22,
          _mm_unpackhi_ps(v22, _mm_max_ps(_mm_add_ps(v15, v3->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
  v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24);
  v26 = _mm_rcp_ps(v25);
  *(__m128 *)&v5[32] = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v25), 196);
  v27 = _mm_shuffle_ps((__m128)LODWORD(in->m_rhsFactor.m_storage), (__m128)LODWORD(in->m_rhsFactor.m_storage), 0);
  *(__m128 *)&v5[16] = _mm_shuffle_ps(
                         v20,
                         _mm_unpackhi_ps(
                           v20,
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(v32), (__m128)LODWORD(v32), 0),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26))),
                         196);
  v28 = _mm_mul_ps(_mm_sub_ps(v6.m_quad, v6.m_quad), v7.m_quad);
  v29 = _mm_shuffle_ps(
          *(__m128 *)v5,
          _mm_unpackhi_ps(
            *(__m128 *)v5,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170)),
              v27)),
          196);
  v30 = (__m128)LODWORD(in->m_rhsFactor.m_storage);
  v31 = _mm_mul_ps(_mm_sub_ps(info->m_pivotB.m_quad, v6.m_quad), v7.m_quad);
  out->m_jacobianSchemas.m_storage = v5 + 48;
  *(__m128 *)v5 = _mm_shuffle_ps(
                    v29,
                    _mm_unpackhi_ps(
                      v29,
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                          _mm_shuffle_ps(v31, v31, 170)),
                        _mm_shuffle_ps(v30, v30, 0))),
                    196);
  *(float *)v5 = *(float *)v5 + 0.00000011920929;
  *v5 = (hkpJacobianSchema)5;
}

// File Line: 98
// RVA: 0xD4F340
void __fastcall hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema_inline(hkp1dLinearBilateralConstraintInfo *info, hkpConstraintQueryIn *in, hkp1Lin2AngJacobian *jac, float customRhs)
{
  __m128 v4; // xmm4
  hkpVelocityAccumulator *v5; // rax
  hkpVelocityAccumulator *v6; // r9
  hkVector4f v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  float v12; // xmm6_4
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  float v25; // xmm6_4
  float v26; // [rsp+38h] [rbp+20h]

  v4 = info->m_constrainedDofW.m_quad;
  v5 = in->m_bodyB.m_storage;
  v6 = in->m_bodyA.m_storage;
  v7.m_quad = (__m128)info->m_pivotA;
  v26 = in->m_virtMassFactor.m_storage;
  v8 = _mm_shuffle_ps(v4, v4, 201);
  v9 = v7.m_quad;
  jac->m_linear0.m_quad = v4;
  v10 = _mm_sub_ps(v7.m_quad, v5->m_scratch3.m_quad);
  v11 = _mm_sub_ps(v9, v6->m_scratch3.m_quad);
  v12 = customRhs;
  v13 = _mm_sub_ps(_mm_mul_ps(v8, v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v4));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v4), _mm_mul_ps(v8, v10));
  v16 = v6->m_invMasses.m_quad;
  v17 = _mm_shuffle_ps(v15, v15, 201);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v6->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v6->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v6->m_scratch2.m_quad));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v5->m_scratch2.m_quad));
  v20 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v19, v19), v5->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v18, v18), v16));
  v21 = _mm_shuffle_ps(
          v20,
          _mm_unpackhi_ps(v20, _mm_max_ps(_mm_add_ps(v16, v5->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
  v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22);
  v24 = _mm_rcp_ps(v23);
  jac->m_angular[1].m_quad = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v23), 196);
  v25 = v12 * in->m_rhsFactor.m_storage;
  jac->m_angular[0].m_quad = _mm_shuffle_ps(
                               v18,
                               _mm_unpackhi_ps(
                                 v18,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)LODWORD(v26), (__m128)LODWORD(v26), 0),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v23)), v24))),
                               196);
  jac->m_linear0.m_quad.m128_f32[3] = v25;
}

// File Line: 110
// RVA: 0xD4E8D0
void __fastcall hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs(hkp1dLinearBilateralConstraintInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out, float customRhs)
{
  hkpVelocityAccumulator *v4; // rax
  hkVector4f v5; // xmm4
  hkpVelocityAccumulator *v6; // r9
  hkpJacobianSchema *v7; // r10
  __m128 v8; // xmm5
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  float v11; // xmm6_4
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  float v24; // xmm6_4
  float v25; // [rsp+38h] [rbp+20h]

  v4 = in->m_bodyA.m_storage;
  v5.m_quad = (__m128)info->m_constrainedDofW;
  v6 = in->m_bodyB.m_storage;
  v7 = out->m_jacobianSchemas.m_storage;
  v25 = in->m_virtMassFactor.m_storage;
  v8 = _mm_sub_ps(info->m_pivotA.m_quad, v6->m_scratch3.m_quad);
  v9 = _mm_shuffle_ps(v5.m_quad, v5.m_quad, 201);
  v10 = _mm_sub_ps(info->m_pivotA.m_quad, v4->m_scratch3.m_quad);
  v11 = customRhs;
  *(hkVector4f *)v7 = (hkVector4f)v5.m_quad;
  v12 = _mm_sub_ps(_mm_mul_ps(v9, v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v5.m_quad));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v5.m_quad), _mm_mul_ps(v9, v8));
  v15 = v6->m_invMasses.m_quad;
  v16 = _mm_shuffle_ps(v14, v14, 201);
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v4->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v4->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v4->m_scratch2.m_quad));
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v6->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v6->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v6->m_scratch2.m_quad));
  v19 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v18, v18), v15), _mm_mul_ps(_mm_mul_ps(v17, v17), v4->m_invMasses.m_quad));
  v20 = _mm_shuffle_ps(
          v19,
          _mm_unpackhi_ps(v19, _mm_max_ps(_mm_add_ps(v15, v4->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rcp_ps(v22);
  *(__m128 *)&v7[32] = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, v22), 196);
  v24 = v11 * in->m_rhsFactor.m_storage;
  out->m_jacobianSchemas.m_storage = v7 + 48;
  *(__m128 *)&v7[16] = _mm_shuffle_ps(
                         v17,
                         _mm_unpackhi_ps(
                           v17,
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(v25), (__m128)LODWORD(v25), 0),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23))),
                         196);
  *(float *)&v7[12] = v24;
  *(float *)v7 = *(float *)v7 + 0.00000011920929;
  *v7 = (hkpJacobianSchema)5;
}

// File Line: 122
// RVA: 0xD4EA50
void __fastcall hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(hkp1dLinearBilateralConstraintInfo *info, hkpConstraintQueryIn *in, hkp1Lin2AngJacobian *jac, float customRhs)
{
  hkpVelocityAccumulator *v4; // rax
  __m128 v5; // xmm4
  hkpVelocityAccumulator *v6; // r9
  hkVector4f v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  float v12; // xmm6_4
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  float v25; // xmm6_4
  float v26; // [rsp+38h] [rbp+20h]

  v4 = in->m_bodyA.m_storage;
  v5 = info->m_constrainedDofW.m_quad;
  v6 = in->m_bodyB.m_storage;
  v7.m_quad = (__m128)info->m_pivotA;
  v26 = in->m_virtMassFactor.m_storage;
  v8 = _mm_shuffle_ps(v5, v5, 201);
  v9 = v7.m_quad;
  jac->m_linear0.m_quad = v5;
  v10 = _mm_sub_ps(v7.m_quad, v6->m_scratch3.m_quad);
  v11 = _mm_sub_ps(v9, v4->m_scratch3.m_quad);
  v12 = customRhs;
  v13 = _mm_sub_ps(_mm_mul_ps(v8, v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v5));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v5), _mm_mul_ps(v8, v10));
  v16 = v6->m_invMasses.m_quad;
  v17 = _mm_shuffle_ps(v15, v15, 201);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v4->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v4->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v4->m_scratch2.m_quad));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v6->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v6->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v6->m_scratch2.m_quad));
  v20 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v19, v19), v16), _mm_mul_ps(_mm_mul_ps(v18, v18), v4->m_invMasses.m_quad));
  v21 = _mm_shuffle_ps(
          v20,
          _mm_unpackhi_ps(v20, _mm_max_ps(_mm_add_ps(v16, v4->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
  v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22);
  v24 = _mm_rcp_ps(v23);
  jac->m_angular[1].m_quad = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v23), 196);
  v25 = v12 * in->m_rhsFactor.m_storage;
  jac->m_angular[0].m_quad = _mm_shuffle_ps(
                               v18,
                               _mm_unpackhi_ps(
                                 v18,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)LODWORD(v26), (__m128)LODWORD(v26), 0),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v23)), v24))),
                               196);
  jac->m_linear0.m_quad.m128_f32[3] = v25;
}

// File Line: 128
// RVA: 0xD4EBB0
void __fastcall hk1dLinearBilateralConstraintUserTauBuildJacobian(hkp1dLinearBilateralUserTauConstraintInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v3; // rax
  hkpVelocityAccumulator *v4; // r9
  hkpJacobianSchema *v5; // r10
  hkVector4f v6; // xmm7
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  hkVector4f v9; // xmm8
  __m128 v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm8
  __m128 v24; // xmm3

  v3 = in->m_bodyA.m_storage;
  v4 = in->m_bodyB.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  v6.m_quad = (__m128)info->m_constrainedDofW;
  v7 = _mm_sub_ps(info->m_pivotA.m_quad, v3->m_scratch3.m_quad);
  v8 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 201);
  v9.m_quad = (__m128)info->m_pivotB;
  *(hkVector4f *)v5 = (hkVector4f)v6.m_quad;
  v10 = _mm_sub_ps(_mm_mul_ps(v8, v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6.m_quad));
  v11 = _mm_sub_ps(v9.m_quad, v4->m_scratch3.m_quad);
  v12 = _mm_shuffle_ps(v10, v10, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v6.m_quad), _mm_mul_ps(v8, v11));
  v14 = v4->m_invMasses.m_quad;
  v15 = _mm_shuffle_ps(v13, v13, 201);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v3->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v3->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v3->m_scratch2.m_quad));
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v4->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v4->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v4->m_scratch2.m_quad));
  v18 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v16, v16), v3->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v17, v17), v14));
  v19 = _mm_shuffle_ps(
          v18,
          _mm_unpackhi_ps(v18, _mm_max_ps(_mm_add_ps(v14, v3->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rcp_ps(v21);
  *(__m128 *)&v5[32] = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v21), 196);
  *(float *)&v3 = info->m_tau.m_storage;
  v23 = _mm_mul_ps(_mm_sub_ps(v9.m_quad, info->m_pivotA.m_quad), v6.m_quad);
  v24 = _mm_shuffle_ps((__m128)LODWORD(in->m_rhsFactor.m_storage), (__m128)LODWORD(in->m_rhsFactor.m_storage), 0);
  *(__m128 *)&v5[16] = _mm_shuffle_ps(
                         v16,
                         _mm_unpackhi_ps(
                           v16,
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22))),
                         196);
  *(__m128 *)v5 = _mm_shuffle_ps(
                    *(__m128 *)v5,
                    _mm_unpackhi_ps(
                      *(__m128 *)v5,
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                          _mm_shuffle_ps(v23, v23, 170)),
                        v24)),
                    196);
  v20.m128_i32[0] = *(_DWORD *)v5;
  *(_DWORD *)&v5[48] = (_DWORD)v3;
  *(float *)&v5[52] = info->m_damping.m_storage;
  *(float *)v5 = v20.m128_f32[0] + 0.00000011920929;
  *v5 = (hkpJacobianSchema)7;
  out->m_jacobianSchemas.m_storage = v5 + 64;
}

// File Line: 143
// RVA: 0xD4EEF0
void __fastcall hk1dLinearLimitBuildJacobian(hkp1dLinearLimitInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v3; // rax
  hkpVelocityAccumulator *v4; // r9
  hkpJacobianSchema *v5; // r10
  hkVector4f v6; // xmm7
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  hkVector4f v9; // xmm8
  __m128 v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm8
  __m128 v24; // xmm3
  float v25; // [rsp+40h] [rbp+8h]

  v3 = in->m_bodyB.m_storage;
  v4 = in->m_bodyA.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  v25 = in->m_virtMassFactor.m_storage;
  v6.m_quad = (__m128)info->m_constrainedDofW;
  v7 = _mm_sub_ps(info->m_pivotA.m_quad, v4->m_scratch3.m_quad);
  v8 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 201);
  v9.m_quad = (__m128)info->m_pivotB;
  *(hkVector4f *)v5 = (hkVector4f)v6.m_quad;
  v10 = _mm_sub_ps(_mm_mul_ps(v8, v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6.m_quad));
  v11 = _mm_sub_ps(v9.m_quad, v3->m_scratch3.m_quad);
  v12 = _mm_shuffle_ps(v10, v10, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v6.m_quad), _mm_mul_ps(v8, v11));
  v14 = v4->m_invMasses.m_quad;
  v15 = _mm_shuffle_ps(v13, v13, 201);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v4->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v4->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v4->m_scratch2.m_quad));
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v3->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v3->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v3->m_scratch2.m_quad));
  v18 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v17, v17), v3->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v16, v16), v14));
  v19 = _mm_shuffle_ps(
          v18,
          _mm_unpackhi_ps(v18, _mm_max_ps(_mm_add_ps(v14, v3->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rcp_ps(v21);
  *(__m128 *)&v5[32] = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v21), 196);
  v23 = _mm_mul_ps(_mm_sub_ps(v9.m_quad, info->m_pivotA.m_quad), v6.m_quad);
  v24 = _mm_shuffle_ps((__m128)LODWORD(in->m_rhsFactor.m_storage), (__m128)LODWORD(in->m_rhsFactor.m_storage), 0);
  *(__m128 *)&v5[16] = _mm_shuffle_ps(
                         v16,
                         _mm_unpackhi_ps(
                           v16,
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(v25), (__m128)LODWORD(v25), 0),
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22))),
                         196);
  v21.m128_i32[0] = LODWORD(info->m_max.m_storage);
  v20.m128_i32[0] = LODWORD(info->m_min.m_storage);
  *(__m128 *)v5 = _mm_shuffle_ps(
                    *(__m128 *)v5,
                    _mm_unpackhi_ps(
                      *(__m128 *)v5,
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                          _mm_shuffle_ps(v23, v23, 170)),
                        v24)),
                    196);
  v22.m128_i32[0] = LODWORD(in->m_rhsFactor.m_storage);
  out->m_jacobianSchemas.m_storage = v5 + 64;
  v22.m128_i32[0] ^= _xmm[0];
  *(float *)&v5[48] = v20.m128_f32[0] * v22.m128_f32[0];
  v20.m128_i32[0] = *(_DWORD *)v5;
  *(float *)&v5[52] = v21.m128_f32[0] * v22.m128_f32[0];
  *(float *)v5 = v20.m128_f32[0] + 0.00000011920929;
  *v5 = (hkpJacobianSchema)8;
}

// File Line: 165
// RVA: 0xD4F270
void __fastcall hkSetInvMassBuildJacobian(hkVector4f *invMassA, hkVector4f *invMassB, hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v3; // rax
  __m128 v4; // xmm1

  v3 = out->m_jacobianSchemas.m_storage + 32;
  *(hkVector4f *)&v3[-32] = (hkVector4f)invMassA->m_quad;
  v4 = invMassB->m_quad;
  v3[-32] = (hkpJacobianSchema)29;
  *(__m128 *)&v3[-16] = v4;
  out->m_jacobianSchemas.m_storage = v3;
}

// File Line: 173
// RVA: 0xD4F2A0
void __fastcall hkAddVelocityBuildJacobian(hkVector4f *deltaVel, int bodyIndex, hkpConstraintQueryOut *out)
{
  __m128 v3; // xmm0
  hkpJacobianSchema *v4; // rax

  v3 = deltaVel->m_quad;
  v4 = out->m_jacobianSchemas.m_storage + 32;
  *(_DWORD *)&v4[-16] = bodyIndex;
  *(__m128 *)&v4[-32] = v3;
  *(float *)&v4[-32] = *(float *)&v4[-32] + 0.00000011920929;
  v4[-32] = (hkpJacobianSchema)30;
  out->m_jacobianSchemas.m_storage = v4;
}

// File Line: 181
// RVA: 0xD4F2E0
void __fastcall hkSetCenterOfMassBuildJacobian(hkMatrix3f *angToLinVelA, hkMatrix3f *angToLinVelB, hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v3; // rax

  v3 = out->m_jacobianSchemas.m_storage + 96;
  *(hkVector4f *)&v3[-96] = angToLinVelA->m_col0;
  *(hkVector4f *)&v3[-80] = angToLinVelA->m_col1;
  *(hkVector4f *)&v3[-64] = angToLinVelA->m_col2;
  *(hkVector4f *)&v3[-48] = angToLinVelB->m_col0;
  *(hkVector4f *)&v3[-32] = angToLinVelB->m_col1;
  *(hkVector4f *)&v3[-16] = angToLinVelB->m_col2;
  *(float *)&v3[-96] = *(float *)&v3[-96] + 0.00000011920929;
  v3[-96] = (hkpJacobianSchema)31;
  out->m_jacobianSchemas.m_storage = v3;
}

