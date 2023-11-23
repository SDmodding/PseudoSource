// File Line: 62
// RVA: 0xDD0760
void __fastcall JacobianBuilder::_hkBallSocketConstraintComputeStabilizedRhs(
        hkpVelocityAccumulator *accuA,
        hkpVelocityAccumulator *accuB,
        hkVector4f *posA,
        hkVector4f *posB,
        float rhsFactor,
        float stabilizationFactor,
        hkVector4f *errorOut)
{
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm9
  hkVector4f v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm8
  __m128 v13; // xmm7
  hkVector4f v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm10
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  hkVector4f v21; // xmm3
  __m128 v22; // xmm6
  hkVector4f v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm0

  v7 = _mm_shuffle_ps(
         (__m128)COERCE_UNSIGNED_INT(rhsFactor * stabilizationFactor),
         (__m128)COERCE_UNSIGNED_INT(rhsFactor * stabilizationFactor),
         0);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(posB->m_quad, posA->m_quad);
  *errorOut = (hkVector4f)v9;
  v10.m_quad = (__m128)accuA->m_scratch2;
  v11 = _mm_mul_ps(v8, v7);
  v12 = _mm_sub_ps(posB->m_quad, accuB->m_scratch3.m_quad);
  v13 = _mm_sub_ps(posA->m_quad, accuA->m_scratch3.m_quad);
  v14.m_quad = (__m128)accuA->m_scratch0;
  v15 = _mm_unpackhi_ps(v14.m_quad, accuA->m_scratch1.m_quad);
  v16 = _mm_unpacklo_ps(v14.m_quad, accuA->m_scratch1.m_quad);
  v17 = _mm_shuffle_ps(v15, v10.m_quad, 228);
  v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v11), v8);
  v19 = _mm_movelh_ps(v16, v10.m_quad);
  v20 = _mm_shuffle_ps(_mm_movehl_ps(v19, v16), v10.m_quad, 212);
  v21.m_quad = (__m128)accuB->m_scratch2;
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(accuA->m_angularVel.m_quad, accuA->m_angularVel.m_quad, 85), v20),
            _mm_mul_ps(_mm_shuffle_ps(accuA->m_angularVel.m_quad, accuA->m_angularVel.m_quad, 0), v19)),
          _mm_mul_ps(_mm_shuffle_ps(accuA->m_angularVel.m_quad, accuA->m_angularVel.m_quad, 170), v17));
  v23.m_quad = (__m128)accuB->m_scratch0;
  v24 = _mm_unpackhi_ps(v23.m_quad, accuB->m_scratch1.m_quad);
  v25 = _mm_unpacklo_ps(v23.m_quad, accuB->m_scratch1.m_quad);
  v26 = _mm_movelh_ps(v25, v21.m_quad);
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(accuB->m_angularVel.m_quad, accuB->m_angularVel.m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v26, v25), v21.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(accuB->m_angularVel.m_quad, accuB->m_angularVel.m_quad, 0), v26)),
          _mm_mul_ps(
            _mm_shuffle_ps(v24, v21.m_quad, 228),
            _mm_shuffle_ps(accuB->m_angularVel.m_quad, accuB->m_angularVel.m_quad, 170)));
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v22));
  v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v27));
  errorOut->m_quad = _mm_sub_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v18), v9),
                       _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v18));
}

// File Line: 87
// RVA: 0xDD08E0
void __fastcall JacobianBuilder::_hkBallSocketConstraintBuildJacobian(
        hkVector4f *posA,
        hkVector4f *posB,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out,
        float maxImpulse,
        float stabilizationFactor)
{
  hkpVelocityAccumulator *m_storage; // r11
  hkpVelocityAccumulator *v7; // rbx
  __m128 *v8; // r10
  __m128 m_quad; // xmm3
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm8
  __m128 v15; // xmm11
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128 v30; // xmm9
  hkpViolatedConstraintArray *v31; // rcx
  __m128 v32; // xmm12
  __m128 v33; // xmm12
  __m128 v34; // xmm2
  unsigned __int32 v35; // eax
  hkVector4f *v36; // rcx
  __m128 *v37; // rax
  __m128 v38; // xmm7
  __m128 v39; // xmm8
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __m128 v43; // xmm4
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm3
  __m128 v51; // xmm3
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  __m128 m_storage_low; // xmm2
  __m128 v57; // xmm8
  __m128 v58; // xmm4
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // [rsp+0h] [rbp-98h]
  float v62; // [rsp+A0h] [rbp+8h]

  m_storage = in->m_bodyA.m_storage;
  v7 = in->m_bodyB.m_storage;
  v8 = (__m128 *)out->m_jacobianSchemas.m_storage;
  m_quad = m_storage->m_scratch2.m_quad;
  v11 = _mm_sub_ps(posA->m_quad, m_storage->m_scratch3.m_quad);
  v12 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(stabilizationFactor * in->m_rhsFactor.m_storage),
          (__m128)COERCE_UNSIGNED_INT(stabilizationFactor * in->m_rhsFactor.m_storage),
          0);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(posB->m_quad, v7->m_scratch3.m_quad);
  v15 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v13));
  v16 = m_storage->m_scratch0.m_quad;
  v17 = _mm_unpackhi_ps(v16, m_storage->m_scratch1.m_quad);
  v18 = _mm_unpacklo_ps(v16, m_storage->m_scratch1.m_quad);
  v19 = _mm_shuffle_ps(v17, m_quad, 228);
  v20 = _mm_movelh_ps(v18, m_quad);
  v61 = _mm_mul_ps(v15, v13);
  v21 = _mm_shuffle_ps(_mm_movehl_ps(v20, v18), m_quad, 212);
  v22 = v7->m_scratch2.m_quad;
  v23 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad, 85), v21),
            _mm_mul_ps(_mm_shuffle_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad, 0), v20)),
          _mm_mul_ps(v19, _mm_shuffle_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad, 170)));
  v24 = v7->m_scratch0.m_quad;
  v25 = _mm_unpackhi_ps(v24, v7->m_scratch1.m_quad);
  v26 = _mm_unpacklo_ps(v24, v7->m_scratch1.m_quad);
  v27 = _mm_movelh_ps(v26, v22);
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v7->m_angularVel.m_quad, v7->m_angularVel.m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v27, v26), v22, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v7->m_angularVel.m_quad, v7->m_angularVel.m_quad, 0), v27)),
          _mm_mul_ps(
            _mm_shuffle_ps(v25, v22, 228),
            _mm_shuffle_ps(v7->m_angularVel.m_quad, v7->m_angularVel.m_quad, 170)));
  v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v23));
  v30 = _mm_sub_ps(posB->m_quad, posA->m_quad);
  v31 = in->m_violatedConstraints.m_storage;
  v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v28));
  v33 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v61), v30),
          _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v61));
  if ( v31 )
  {
    v34 = _mm_mul_ps(v33, v33);
    if ( (float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
               + _mm_shuffle_ps(v34, v34, 170).m128_f32[0]) > in->m_maxConstraintViolationSqrd.m_real.m128_f32[0] )
    {
      v35 = _InterlockedExchangeAdd((volatile signed __int32 *)v31, 1u);
      if ( v35 < 0x80 )
        in->m_violatedConstraints.m_storage->m_constraints[v35] = in->m_constraintInstance.m_storage;
    }
  }
  v36 = &transform;
  v37 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
  do
  {
    v38 = v36->m_quad;
    v62 = in->m_virtMassFactor.m_storage;
    v39 = _mm_sub_ps(posB->m_quad, posA->m_quad);
    v40 = _mm_shuffle_ps(v38, v38, 201);
    v41 = _mm_sub_ps(posA->m_quad, m_storage->m_scratch3.m_quad);
    v42 = _mm_sub_ps(posB->m_quad, v7->m_scratch3.m_quad);
    *v8 = v36->m_quad;
    v43 = _mm_sub_ps(_mm_mul_ps(v41, v40), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v38));
    v44 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v38), _mm_mul_ps(v42, v40));
    v45 = v7->m_invMasses.m_quad;
    v46 = _mm_shuffle_ps(v44, v44, 201);
    v47 = _mm_shuffle_ps(v43, v43, 201);
    v48 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), m_storage->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), m_storage->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), m_storage->m_scratch2.m_quad));
    v49 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v7->m_scratch2.m_quad));
    v50 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v48, v48), m_storage->m_invMasses.m_quad),
            _mm_mul_ps(_mm_mul_ps(v49, v49), v45));
    v51 = _mm_shuffle_ps(
            v50,
            _mm_unpackhi_ps(v50, _mm_max_ps(_mm_add_ps(v45, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
    v53 = _mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52);
    v54 = _mm_rcp_ps(v53);
    v8[2] = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v53), 196);
    v55 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v54, v53)), v54);
    m_storage_low = (__m128)LODWORD(in->m_rhsFactor.m_storage);
    v8[1] = _mm_shuffle_ps(
              v48,
              _mm_unpackhi_ps(v48, _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v62), (__m128)LODWORD(v62), 0), v55)),
              196);
    v57 = _mm_mul_ps(v39, v38);
    v58 = _mm_shuffle_ps(
            *v8,
            _mm_unpackhi_ps(
              *v8,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                  _mm_shuffle_ps(v57, v57, 170)),
                _mm_shuffle_ps(m_storage_low, m_storage_low, 0))),
            196);
    v59 = _mm_and_ps(v33, *v37);
    v60 = _mm_or_ps(_mm_shuffle_ps(v59, v59, 78), v59);
    *v8 = _mm_shuffle_ps(
            v58,
            _mm_unpackhi_ps(
              v58,
              _mm_mul_ps(
                _mm_or_ps(_mm_shuffle_ps(v60, v60, 177), v60),
                _mm_shuffle_ps(
                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                  0))),
            196);
    if ( maxImpulse == 3.40282e38 )
    {
      v8->m128_f32[0] = v8->m128_f32[0] + 0.00000011920929;
      v8->m128_i8[0] = 5;
    }
    else
    {
      v8[2].m128_f32[3] = maxImpulse;
      v8->m128_f32[0] = v8->m128_f32[0] + 0.00000011920929;
      v8->m128_i8[0] = 6;
    }
    ++v37;
    v8 += 3;
    ++v36;
  }
  while ( (__int64)v37 < (__int64)&xmmword_141687F30 );
  out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v8;
}(__int64)&xmmword_141687F30 );
  out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v8;
}

// File Line: 150
// RVA: 0xDD0D40
void __fastcall JacobianBuilder::_hk1dAngularVelocityMotorBeginJacobian(
        hkVector4f *directionOfConstraint,
        hkpConstraintQueryIn *in,
        hkp2AngJacobian *jac,
        hkp1dBilateralConstraintStatus *statusOut)
{
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v5; // r10
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm2

  m_storage = in->m_bodyB.m_storage;
  v5 = in->m_bodyA.m_storage;
  v6 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
         directionOfConstraint->m_quad);
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(directionOfConstraint->m_quad, directionOfConstraint->m_quad, 85),
             v5->m_scratch1.m_quad),
           _mm_mul_ps(
             _mm_shuffle_ps(directionOfConstraint->m_quad, directionOfConstraint->m_quad, 0),
             v5->m_scratch0.m_quad)),
         _mm_mul_ps(
           _mm_shuffle_ps(directionOfConstraint->m_quad, directionOfConstraint->m_quad, 170),
           v5->m_scratch2.m_quad));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), m_storage->m_scratch1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), m_storage->m_scratch0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), m_storage->m_scratch2.m_quad));
  v9 = _mm_mul_ps(_mm_mul_ps(v7, v7), v5->m_invMasses.m_quad);
  jac->m_angular[1].m_quad = v8;
  v10 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v8, v8), m_storage->m_invMasses.m_quad), v9);
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)),
          *(__m128 *)&epsilon);
  v12 = _mm_rcp_ps(v11);
  jac->m_angular[0].m_quad = _mm_shuffle_ps(
                               v7,
                               _mm_unpackhi_ps(
                                 v7,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v11)), v12))),
                               196);
  LODWORD(statusOut->m_effMass.m_storage) = jac->m_angular[0].m_quad.m128_u32[3];
}

// File Line: 177
// RVA: 0xDD0E40
void __fastcall JacobianBuilder::hkSkipSolverResults(
        hkpJacobianSchema numSolverResultsToSkip,
        hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v2; // rax

  v2 = out->m_jacobianSchemas.m_storage + 16;
  v2[-12] = numSolverResultsToSkip;
  *(float *)&v2[-16] = *(float *)&v2[-16] + 0.00000011920929;
  v2[-16] = (hkpJacobianSchema)3;
  out->m_jacobianSchemas.m_storage = v2;
}

// File Line: 186
// RVA: 0xDD0E70
void __fastcall JacobianBuilder::hkSkipSolverResults_0(
        hkpJacobianSchema numSolverResultsToSkip,
        hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v2; // rax

  v2 = out->m_jacobianSchemas.m_storage + 16;
  v2[-12] = numSolverResultsToSkip;
  *(float *)&v2[-16] = *(float *)&v2[-16] + 0.00000011920929;
  v2[-16] = (hkpJacobianSchema)3;
  out->m_jacobianSchemas.m_storage = v2;
}

// File Line: 193
// RVA: 0xDD0EA0
void __fastcall JacobianBuilder::buildJacobianFromStiffSpringAtom(
        hkpStiffSpringConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkVector4f *vLocalArmA,
        hkVector4f *vLocalArmB,
        hkSimdFloat32 *maxAngularImpulse,
        hkSimdFloat32 *maxLinearImpulse,
        hkpConstraintQueryOut *out)
{
  __m128 *m_storage; // r8
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm7
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm11
  __m128 v25; // xmm12
  __m128 v26; // xmm8
  hkpJacobianSchema *v27; // rax
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 m_storage_low; // xmm0
  __m128 v31; // xmm3
  __m128 m_length_low; // xmm0
  __m128 v33; // xmm1

  m_storage = (__m128 *)out->m_jacobianSchemas.m_storage;
  v10 = _mm_mul_ps(vLocalArmA->m_quad, vLocalArmA->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = _mm_andnot_ps(
          _mm_cmple_ps(v11, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
              _mm_mul_ps(*(__m128 *)_xmm, v12)),
            v11));
  v14 = _mm_mul_ps(vLocalArmB->m_quad, vLocalArmB->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(*(__m128 *)_xmm, v16);
  v18 = _mm_cmplt_ps(*(__m128 *)&epsilon, v13);
  v19 = _mm_mul_ps(_mm_mul_ps(v16, v15), v16);
  v20 = _mm_rcp_ps(v13);
  v21 = _mm_andnot_ps(_mm_cmple_ps(v15, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v19), v17), v15));
  v22 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v13)), v20);
  v23 = _mm_rcp_ps(v21);
  v24 = _mm_cmplt_ps(*(__m128 *)&epsilon, v21);
  v25 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(vLocalArmA->m_quad, v22), v18), _mm_andnot_ps(v18, transform.m_quad));
  v26 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(vLocalArmB->m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v21)), v23)),
            v24),
          _mm_andnot_ps(v24, transform.m_quad));
  v27 = out->m_jacobianSchemas.m_storage + 48;
  v28 = _mm_shuffle_ps((__m128)LODWORD(atom->m_maxLength), (__m128)LODWORD(atom->m_maxLength), 0);
  v29 = _mm_shuffle_ps(
          (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
          (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
          0);
  m_storage[1] = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v13), 196);
  m_storage_low = (__m128)LODWORD(in->m_tau.m_storage);
  m_storage[2] = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, v21), 196);
  v31 = _mm_shuffle_ps(
          *m_storage,
          _mm_unpackhi_ps(*m_storage, _mm_mul_ps(v29, _mm_shuffle_ps(m_storage_low, m_storage_low, 0))),
          196);
  m_length_low = (__m128)LODWORD(atom->m_length);
  out->m_jacobianSchemas.m_storage = v27;
  v33 = _mm_shuffle_ps(_mm_unpacklo_ps(v31, _mm_shuffle_ps(m_length_low, m_length_low, 0)), v31, 228);
  *m_storage = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v28), 180);
  m_storage->m128_f32[0] = m_storage->m128_f32[0] + 0.00000011920929;
  m_storage->m128_i8[0] = 18;
}

// File Line: 233
// RVA: 0xDD10C0
void __fastcall JacobianBuilder::setLocalTransform(
        hkTransformf *baseIn,
        hkTransformf *transform,
        hkTransformf *baseOut)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm5
  __int64 v6; // r9
  hkVector4f *p_m_translation; // rax
  __m128 m_quad; // xmm1

  v3.m_quad = (__m128)transform->m_rotation.m_col0;
  v4.m_quad = (__m128)transform->m_rotation.m_col1;
  v5.m_quad = (__m128)transform->m_rotation.m_col2;
  v6 = 3i64;
  p_m_translation = &baseIn->m_translation;
  do
  {
    m_quad = p_m_translation->m_quad;
    --p_m_translation;
    --v6;
    *(__m128 *)((char *)&p_m_translation[1].m_quad + (char *)baseOut - (char *)baseIn) = _mm_add_ps(
                                                                                           _mm_add_ps(
                                                                                             _mm_mul_ps(
                                                                                               _mm_shuffle_ps(
                                                                                                 m_quad,
                                                                                                 m_quad,
                                                                                                 85),
                                                                                               v4.m_quad),
                                                                                             _mm_mul_ps(
                                                                                               _mm_shuffle_ps(
                                                                                                 m_quad,
                                                                                                 m_quad,
                                                                                                 0),
                                                                                               v3.m_quad)),
                                                                                           _mm_mul_ps(
                                                                                             _mm_shuffle_ps(
                                                                                               m_quad,
                                                                                               m_quad,
                                                                                               170),
                                                                                             v5.m_quad));
  }
  while ( v6 >= 0 );
  baseOut->m_translation.m_quad = _mm_add_ps(transform->m_translation.m_quad, baseOut->m_translation.m_quad);
}

// File Line: 240
// RVA: 0xDD1130
void __fastcall JacobianBuilder::setLocalTransformsFromAtom(
        hkpSetLocalTransformsConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB)
{
  hkTransformf *m_storage; // rbx
  __int64 v6; // r10
  __m128 m_quad; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __int64 v13; // r9
  hkVector4f *p_m_translation; // r8
  signed __int64 v15; // rax
  __m128 v16; // xmm1
  hkVector4f *v17; // rcx
  hkTransformf *v18; // rdx
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm1

  m_storage = in->m_transformA.m_storage;
  v6 = 3i64;
  m_quad = m_storage->m_rotation.m_col0.m_quad;
  v11 = m_storage->m_rotation.m_col1.m_quad;
  v12 = m_storage->m_rotation.m_col2.m_quad;
  v13 = 3i64;
  p_m_translation = &atom->m_transformA.m_translation;
  v15 = (char *)baseA - (char *)atom;
  do
  {
    v16 = p_m_translation->m_quad;
    --p_m_translation;
    --v13;
    *(__m128 *)((char *)&p_m_translation->m_quad + v15) = _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v11),
                                                              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), m_quad)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12));
  }
  while ( v13 >= 0 );
  v17 = &atom->m_transformB.m_translation;
  baseA->m_translation.m_quad = _mm_add_ps(m_storage->m_translation.m_quad, baseA->m_translation.m_quad);
  v18 = in->m_transformB.m_storage;
  v19 = v18->m_rotation.m_col0.m_quad;
  v20 = v18->m_rotation.m_col1.m_quad;
  v21 = v18->m_rotation.m_col2.m_quad;
  do
  {
    v22 = v17->m_quad;
    --v17;
    --v6;
    *(__m128 *)((char *)&v17[-4].m_quad + (char *)baseB - (char *)atom) = _mm_add_ps(
                                                                            _mm_add_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_shuffle_ps(v22, v22, 85),
                                                                                v20),
                                                                              _mm_mul_ps(
                                                                                _mm_shuffle_ps(v22, v22, 0),
                                                                                v19)),
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v22, v22, 170),
                                                                              v21));
  }
  while ( v6 >= 0 );
  baseB->m_translation.m_quad = _mm_add_ps(v18->m_translation.m_quad, baseB->m_translation.m_quad);
}

// File Line: 247
// RVA: 0xDD1230
void __fastcall JacobianBuilder::setLocalTranslationsFromAtom(
        hkpSetLocalTranslationsConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB)
{
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm1

  v4.m_quad = (__m128)atom->m_translationA;
  baseA->m_translation.m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v4.m_quad, v4.m_quad, 85),
                                        in->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v4.m_quad, v4.m_quad, 0),
                                        in->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170),
                                      in->m_transformA.m_storage->m_rotation.m_col2.m_quad)),
                                  in->m_transformA.m_storage->m_translation.m_quad);
  v5.m_quad = (__m128)atom->m_translationB;
  baseB->m_translation.m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v5.m_quad, v5.m_quad, 85),
                                        in->m_transformB.m_storage->m_rotation.m_col1.m_quad),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v5.m_quad, v5.m_quad, 0),
                                        in->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170),
                                      in->m_transformB.m_storage->m_rotation.m_col2.m_quad)),
                                  in->m_transformB.m_storage->m_translation.m_quad);
}

// File Line: 254
// RVA: 0xDD12A0
void __fastcall JacobianBuilder::setLocalRotationsFromAtom(
        hkpSetLocalRotationsConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB)
{
  hkTransformf *m_storage; // rax
  __int64 v5; // r10
  __int64 v7; // r9
  signed __int64 v8; // r8
  __m128 m_quad; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  hkRotationf *p_m_rotationB; // rax
  __m128 v13; // xmm1
  hkTransformf *v14; // rax
  signed __int64 v15; // r11
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  hkpSetLocalRotationsConstraintAtom *v19; // rax
  __m128 v20; // xmm1

  m_storage = in->m_transformA.m_storage;
  v5 = 3i64;
  v7 = 3i64;
  v8 = (char *)baseA - (char *)atom;
  m_quad = m_storage->m_rotation.m_col0.m_quad;
  v10 = m_storage->m_rotation.m_col1.m_quad;
  v11 = m_storage->m_rotation.m_col2.m_quad;
  p_m_rotationB = &atom->m_rotationB;
  do
  {
    v13 = p_m_rotationB->m_col0.m_quad;
    p_m_rotationB = (hkRotationf *)((char *)p_m_rotationB - 16);
    --v7;
    *(__m128 *)((char *)&p_m_rotationB->m_col0.m_quad + v8) = _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v10),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), m_quad)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v11));
  }
  while ( v7 >= 0 );
  v14 = in->m_transformB.m_storage;
  v15 = (char *)baseB - (char *)atom;
  v16 = v14->m_rotation.m_col0.m_quad;
  v17 = v14->m_rotation.m_col1.m_quad;
  v18 = v14->m_rotation.m_col2.m_quad;
  v19 = atom + 1;
  do
  {
    v20 = *(__m128 *)&v19->m_type.m_storage;
    v19 = (hkpSetLocalRotationsConstraintAtom *)((char *)v19 - 16);
    --v5;
    *(__m128 *)((char *)v19 + v15 - 48) = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v17),
                                              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v16)),
                                            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v18));
  }
  while ( v5 >= 0 );
}

// File Line: 261
// RVA: 0xDD1360
void __fastcall JacobianBuilder::buildJacobianFromLinAtom(
        hkpLinConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm1
  __int64 v6; // rax
  hkp1dLinearBilateralConstraintInfo info; // [rsp+20h] [rbp-38h] BYREF

  v5.m_quad = (__m128)baseB->m_translation;
  v6 = 2i64 * (unsigned __int8)atom->m_axisIndex;
  info.m_pivotA = baseA->m_translation;
  info.m_pivotB = (hkVector4f)v5.m_quad;
  info.m_constrainedDofW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + 8 * v6);
  hk1dLinearBilateralConstraintBuildJacobian(&info, in, out);
}

// File Line: 271
// RVA: 0xDD13B0
void __fastcall JacobianBuilder::buildJacobianFromLinSoftAtom(
        hkpLinSoftConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm1
  __int64 v6; // rax
  hkVector4f v7; // xmm0
  hkp1dLinearBilateralUserTauConstraintInfo info; // [rsp+20h] [rbp-48h] BYREF

  v5.m_quad = (__m128)baseB->m_translation;
  v6 = 2i64 * (unsigned __int8)atom->m_axisIndex;
  info.m_pivotA = baseA->m_translation;
  info.m_pivotB = (hkVector4f)v5.m_quad;
  v7.m_quad = *(__m128 *)((char *)&baseB->m_rotation.m_col0 + 8 * v6);
  info.m_tau.m_storage = atom->m_tau;
  info.m_constrainedDofW = (hkVector4f)v7.m_quad;
  info.m_damping.m_storage = atom->m_damping;
  hk1dLinearBilateralConstraintUserTauBuildJacobian(&info, in, out);
}

// File Line: 293
// RVA: 0xDD1410
void __fastcall JacobianBuilder::setupStabilizationFromAtom(
        hkpSetupStabilizationAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkVector4f *vLocalArmA,
        hkVector4f *vLocalArmB,
        hkSimdFloat32 *maxAngularImpulse,
        hkSimdFloat32 *maxLinearImpulse,
        hkpConstraintQueryOut *noOut)
{
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v10; // r10
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm9
  hkVector4f v14; // xmm7
  hkVector4f v15; // xmm8
  __m128 v16; // xmm7
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm11
  __m128 v22; // xmm10
  __m128 v23; // xmm9
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm5
  __m128 v31; // xmm11
  __m128 v32; // xmm2
  __m128 v33; // xmm1

  if ( atom->m_enabled.m_bool )
  {
    m_storage = in->m_bodyA.m_storage;
    v10 = in->m_bodyB.m_storage;
    v11 = _mm_sub_ps(baseA->m_translation.m_quad, m_storage->m_scratch3.m_quad);
    v12 = _mm_sub_ps(baseB->m_translation.m_quad, v10->m_scratch3.m_quad);
    vLocalArmA->m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), m_storage->m_scratch1.m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), m_storage->m_scratch0.m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), m_storage->m_scratch2.m_quad));
    v13 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v10->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v10->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v10->m_scratch2.m_quad));
    *vLocalArmB = (hkVector4f)v13;
    v14.m_quad = (__m128)in->m_bodyA.m_storage->m_invMasses;
    v15.m_quad = (__m128)in->m_bodyB.m_storage->m_invMasses;
    v16 = _mm_max_ps(
            _mm_shuffle_ps(v14.m_quad, v14.m_quad, 170),
            _mm_max_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 85), _mm_shuffle_ps(v14.m_quad, v14.m_quad, 0)));
    v17 = _mm_max_ps(
            _mm_shuffle_ps(v15.m_quad, v15.m_quad, 170),
            _mm_max_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 85), _mm_shuffle_ps(v15.m_quad, v15.m_quad, 0)));
    v18 = _mm_mul_ps(vLocalArmA->m_quad, vLocalArmA->m_quad);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v20 = _mm_rsqrt_ps(v19);
    v21 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))),
            v16);
    v22 = _mm_max_ps(_mm_max_ps(v16, v17), *(__m128 *)&epsilon);
    v23 = _mm_mul_ps(v13, v13);
    v24 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
            _mm_shuffle_ps(v23, v23, 170));
    v25 = _mm_rsqrt_ps(v24);
    v26 = _mm_mul_ps(*(__m128 *)_xmm, v25);
    v27 = _mm_mul_ps(_mm_mul_ps(v25, v24), v25);
    v28 = _mm_rcp_ps(v22);
    v29 = _mm_andnot_ps(_mm_cmple_ps(v24, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v27), v26));
    v30 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(atom->m_maxAngle), (__m128)LODWORD(atom->m_maxAngle), 0),
            _mm_shuffle_ps(
              (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
              (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
              0));
    v31 = _mm_max_ps(_mm_max_ps(v21, _mm_mul_ps(v29, v17)), *(__m128 *)&epsilon);
    v32 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v22)), v28);
    v33 = _mm_rcp_ps(v31);
    maxAngularImpulse->m_real = _mm_min_ps(
                                  _mm_mul_ps(v32, v30),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(atom->m_maxAngImpulse),
                                    (__m128)LODWORD(atom->m_maxAngImpulse),
                                    0));
    maxLinearImpulse->m_real = _mm_min_ps(
                                 _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v31)), v33), v30),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(atom->m_maxLinImpulse),
                                   (__m128)LODWORD(atom->m_maxLinImpulse),
                                   0));
  }
}

// File Line: 433
// RVA: 0xDD1670
void __fastcall JacobianBuilder::buildJacobianFromLinLimitAtom(
        hkpLinLimitConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm1
  __int64 v6; // rax
  hkp1dLinearLimitInfo info; // [rsp+20h] [rbp-48h] BYREF

  v5.m_quad = (__m128)baseB->m_translation;
  v6 = 2i64 * (unsigned __int8)atom->m_axisIndex;
  info.m_pivotA = baseA->m_translation;
  info.m_pivotB = (hkVector4f)v5.m_quad;
  v5.m_quad.m128_i32[0] = LODWORD(atom->m_max);
  info.m_min.m_storage = atom->m_min;
  LODWORD(info.m_max.m_storage) = v5.m_quad.m128_i32[0];
  info.m_constrainedDofW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + 8 * v6);
  hk1dLinearLimitBuildJacobian(&info, in, out);
}

// File Line: 454
// RVA: 0xDD16D0
void __fastcall JacobianBuilder::buildJacobianFrom2dAngAtom(
        hkp2dAngConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  __int64 m_freeRotationAxis; // r10
  __int64 v7; // rbx
  hkVector4f *v8; // rsi
  hkVector4f *v9; // rbx
  hkp1dAngularBilateralConstraintInfo info; // [rsp+20h] [rbp-38h] BYREF

  m_freeRotationAxis = (unsigned __int8)atom->m_freeRotationAxis;
  v7 = (unsigned __int8)modulo3Table[m_freeRotationAxis + 2];
  v8 = (hkVector4f *)((char *)&baseB->m_rotation.m_col0 + (unsigned __int8)modulo3Table[m_freeRotationAxis + 1]);
  info.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + m_freeRotationAxis);
  v9 = (hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v7);
  info.m_perpZeroErrorAxisBinW = (hkVector4f)v8->m_quad;
  info.m_constrainedDofW = (hkVector4f)v9->m_quad;
  hk1dAngularBilateralConstraintBuildJacobian(&info, in, out);
  info.m_perpZeroErrorAxisBinW = (hkVector4f)v9->m_quad;
  info.m_constrainedDofW.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    v8->m_quad);
  hk1dAngularBilateralConstraintBuildJacobian(&info, in, out);
}

// File Line: 485
// RVA: 0xDD1780
void __fastcall JacobianBuilder::buildJacobianFromAngAtom(
        hkpAngConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  unsigned __int8 m_numConstrainedAxes; // al
  __int64 m_firstConstrainedAxis; // rdi
  const char *v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rbx
  __int64 v18; // rsi
  hkp1dAngularBilateralConstraintInfo info; // [rsp+20h] [rbp-48h] BYREF

  m_numConstrainedAxes = atom->m_numConstrainedAxes;
  if ( m_numConstrainedAxes == 2 )
  {
    v14 = (unsigned __int8)modulo3Table[(unsigned __int8)atom->m_firstConstrainedAxis + 2] >> 4;
    v15 = (unsigned __int8)modulo3Table[v14 + 1];
    v16 = (unsigned __int8)modulo3Table[v14 + 2];
    v17 = v16;
    info.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + v14);
    v18 = (unsigned int)v15;
    info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v15);
    info.m_constrainedDofW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v16);
    hk1dAngularBilateralConstraintBuildJacobian(&info, in, out);
    info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v17);
    info.m_constrainedDofW.m_quad = _mm_xor_ps(
                                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                      *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + v18));
    hk1dAngularBilateralConstraintBuildJacobian(&info, in, out);
  }
  else
  {
    m_firstConstrainedAxis = (unsigned __int8)atom->m_firstConstrainedAxis;
    if ( (int)m_firstConstrainedAxis < (int)(m_firstConstrainedAxis + m_numConstrainedAxes) )
    {
      v11 = &modulo3Table[m_firstConstrainedAxis + 1];
      do
      {
        v12 = *((unsigned __int8 *)v11++ - 1);
        info.m_constrainedDofW = *(hkVector4f *)((char *)&baseA->m_rotation.m_col0 + v12);
        v13 = *(unsigned __int8 *)v11;
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&baseA->m_rotation.m_col0 + *((unsigned __int8 *)v11 - 1));
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v13);
        hk1dAngularBilateralConstraintBuildJacobian(&info, in, out);
        LODWORD(m_firstConstrainedAxis) = m_firstConstrainedAxis + 1;
      }
      while ( (int)m_firstConstrainedAxis < (unsigned __int8)atom->m_firstConstrainedAxis
                                          + (unsigned __int8)atom->m_numConstrainedAxes );
    }
  }
}

// File Line: 518
// RVA: 0xDD18F0
void __fastcall JacobianBuilder::buildJacobianFrom3dAngularAtom(
        hkp3dAngConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkVector4f *vLocalArmA,
        hkVector4f *vLocalArmB)
{
  hkpVelocityAccumulator *m_storage; // rbx
  unsigned __int64 v8; // r15
  int v11; // r11d
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  int v15; // edx
  __int64 v16; // r8
  __int64 v17; // r9
  float v18; // xmm0_4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm7
  float v24; // xmm0_4
  float v25; // xmm3_4
  __int64 v26; // r8
  __int64 v27; // r9
  float v28; // xmm0_4
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 m_storage_low; // xmm1
  __m128 v37; // xmm0
  float v38; // [rsp+1Ch] [rbp-7Dh]
  __m128 v39; // [rsp+20h] [rbp-79h]
  hkMatrix3f v40; // [rsp+30h] [rbp-69h] BYREF
  float v41; // [rsp+60h] [rbp-39h]
  float v42; // [rsp+68h] [rbp-31h]
  float v43; // [rsp+6Ch] [rbp-2Dh]
  float v44; // [rsp+70h] [rbp-29h]
  __m128 *v45; // [rsp+108h] [rbp+6Fh]
  float vLocalArmBa; // [rsp+118h] [rbp+7Fh]

  m_storage = in->m_bodyB.m_storage;
  v8 = vLocalArmB->m_quad.m128_u64[0];
  hkMatrix3f::setMul(&v40, (hkMatrix3f *)&in->m_bodyA.m_storage->m_scratch0, &baseA->m_rotation);
  hkMatrix3f::setMul(
    (hkMatrix3f *)&v40.m_col1.m_quad.m128_u16[4],
    (hkMatrix3f *)&m_storage->m_scratch0,
    &baseB->m_rotation);
  v11 = 0;
  v12 = (float)(v40.m_col0.m_quad.m128_f32[0] + v39.m128_f32[3]) + v40.m_col1.m_quad.m128_f32[0];
  if ( v12 <= 0.0 )
  {
    v39.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v39.m128_u64 + 4) = 2i64;
    v15 = v39.m128_f32[3] > v40.m_col0.m_quad.m128_f32[0];
    if ( v40.m_col1.m_quad.m128_f32[0] > v40.m_col0.m_quad.m128_f32[5
                                                                  * (v39.m128_f32[3] > v40.m_col0.m_quad.m128_f32[0])] )
      v15 = 2;
    v16 = v39.m128_i32[v15];
    v17 = v39.m128_i32[v16];
    v18 = fsqrt(
            (float)(v40.m_col0.m_quad.m128_f32[5 * v15]
                  - (float)(v40.m_col0.m_quad.m128_f32[5 * v17] + v40.m_col0.m_quad.m128_f32[5 * v16]))
          + 1.0);
    v39.m128_f32[v15] = v18 * 0.5;
    v39.m128_f32[3] = (float)(v40.m_col0.m_quad.m128_f32[4 * v16 + v17] - v40.m_col0.m_quad.m128_f32[4 * v17 + v16])
                    * (float)(0.5 / v18);
    v39.m128_f32[v16] = (float)(v40.m_col0.m_quad.m128_f32[4 * v15 + v16] + v40.m_col0.m_quad.m128_f32[4 * v16 + v15])
                      * (float)(0.5 / v18);
    v39.m128_f32[v17] = (float)(v40.m_col0.m_quad.m128_f32[4 * v17 + v15] + v40.m_col0.m_quad.m128_f32[4 * v15 + v17])
                      * (float)(0.5 / v18);
  }
  else
  {
    v13 = fsqrt(v12 + 1.0);
    v39.m128_f32[3] = v13 * 0.5;
    v14 = (float)(v40.m_col0.m_quad.m128_f32[2] - v39.m128_f32[0]) * (float)(0.5 / v13);
    v39.m128_f32[0] = (float)(v40.m_col0.m_quad.m128_f32[0] - v40.m_col0.m_quad.m128_f32[3]) * (float)(0.5 / v13);
    v39.m128_f32[1] = v14;
    v39.m128_f32[2] = (float)(v38 - v39.m128_f32[2]) * (float)(0.5 / v13);
  }
  v19 = _mm_mul_ps(v39, v39);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(
          v39,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(*(__m128 *)_xmm, v22)));
  v24 = (float)(v40.m_col1.m_quad.m128_f32[2] + v40.m_col2.m_quad.m128_f32[3]) + v44;
  if ( v24 <= 0.0 )
  {
    v39.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v39.m128_u64 + 4) = 2i64;
    if ( v40.m_col2.m_quad.m128_f32[3] > v40.m_col1.m_quad.m128_f32[2] )
      v11 = 1;
    if ( v44 > v40.m_col1.m_quad.m128_f32[5 * v11 + 2] )
      v11 = 2;
    v26 = v39.m128_i32[v11];
    v27 = v39.m128_i32[v26];
    v28 = fsqrt(
            (float)(v40.m_col1.m_quad.m128_f32[5 * v11 + 2]
                  - (float)(v40.m_col1.m_quad.m128_f32[5 * v27 + 2] + v40.m_col1.m_quad.m128_f32[5 * v26 + 2]))
          + 1.0);
    v39.m128_f32[v11] = v28 * 0.5;
    v39.m128_f32[3] = (float)(v40.m_col1.m_quad.m128_f32[4 * v26 + 2 + v27]
                            - v40.m_col1.m_quad.m128_f32[4 * v27 + 2 + v26])
                    * (float)(0.5 / v28);
    v39.m128_f32[v26] = (float)(v40.m_col1.m_quad.m128_f32[4 * v11 + 2 + v26]
                              + v40.m_col1.m_quad.m128_f32[4 * v26 + 2 + v11])
                      * (float)(0.5 / v28);
    v39.m128_f32[v27] = (float)(v40.m_col1.m_quad.m128_f32[4 * v27 + 2 + v11]
                              + v40.m_col1.m_quad.m128_f32[4 * v11 + 2 + v27])
                      * (float)(0.5 / v28);
  }
  else
  {
    v25 = fsqrt(v24 + 1.0);
    v39.m128_f32[3] = v25 * 0.5;
    v39.m128_f32[0] = (float)(v41 - v43) * (float)(0.5 / v25);
    v39.m128_f32[1] = (float)(v42 - v40.m_col2.m_quad.m128_f32[0]) * (float)(0.5 / v25);
    v39.m128_f32[2] = (float)(v40.m_col1.m_quad.m128_f32[3] - v40.m_col2.m_quad.m128_f32[2]) * (float)(0.5 / v25);
  }
  v29 = v39;
  v30 = v39;
  *(__m128 *)(v8 + 16) = v23;
  v31 = _mm_mul_ps(v30, v30);
  v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
  v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 177), v32);
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(
          v29,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)), _mm_mul_ps(v34, *(__m128 *)_xmm)));
  m_storage_low = (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage);
  vLocalArmBa = in->m_tau.m_storage;
  v37 = *v45;
  *(__m128 *)(v8 + 32) = v35;
  vLocalArmB->m_quad.m128_u64[0] = v8 + 48;
  *(__m128 *)v8 = _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      aabbOut.m_quad,
                      _mm_mul_ps(
                        _mm_shuffle_ps((__m128)LODWORD(vLocalArmBa), (__m128)LODWORD(vLocalArmBa), 0),
                        _mm_shuffle_ps(m_storage_low, m_storage_low, 0))),
                    _mm_unpacklo_ps(v37, aabbOut.m_quad));
  *(float *)v8 = *(float *)v8 + 0.00000011920929;
  *(_BYTE *)v8 = 32;
}

// File Line: 566
// RVA: 0xDD50E0
void __fastcall JacobianBuilder::buildJacobianFromLinDeformableAtom_hkpConstraintQueryIn_(
        hkpDeformableLinConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *m_storage; // r10
  hkpVelocityAccumulator *v6; // r11
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  hkpJacobianSchema *v10; // rbx
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  hkVector4f v21; // xmm9
  hkTransformf *v22; // rax
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm7
  __m128 v38; // xmm8
  __m128 v39; // xmm7
  __m128 v40; // xmm6
  __m128 v41; // xmm9
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // [rsp+0h] [rbp-88h]
  __m128 v47; // [rsp+10h] [rbp-78h]

  m_storage = in->m_bodyA.m_storage;
  v6 = in->m_bodyB.m_storage;
  v7 = _mm_shuffle_ps(
         (__m128)LODWORD(in->m_microStepDeltaTime.m_storage),
         (__m128)LODWORD(in->m_microStepDeltaTime.m_storage),
         0);
  v8 = _mm_mul_ps(atom->m_yieldStrengthOffDiag.m_quad, v7);
  v9 = _mm_mul_ps(atom->m_ultimateStrengthDiag.m_quad, v7);
  v10 = out->m_jacobianSchemas.m_storage;
  v11 = _mm_mul_ps(atom->m_yieldStrengthDiag.m_quad, v7);
  v12 = _mm_mul_ps(v7, atom->m_ultimateStrengthOffDiag.m_quad);
  *(__m128 *)&v10[16] = v8;
  v46 = v9;
  v13 = _mm_sub_ps(baseA->m_translation.m_quad, m_storage->m_scratch3.m_quad);
  *(__m128 *)v10 = v11;
  v47 = v12;
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), m_storage->m_scratch0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), m_storage->m_scratch1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), m_storage->m_scratch2.m_quad));
  v15 = _mm_sub_ps(baseB->m_translation.m_quad, v6->m_scratch3.m_quad);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v6->m_scratch0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v6->m_scratch1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v6->m_scratch2.m_quad));
  v17 = _mm_mul_ps(v14, v14);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_mul_ps(v16, v16);
  *(__m128 *)&v10[64] = _mm_shuffle_ps(
                          v14,
                          _mm_unpackhi_ps(
                            v14,
                            _mm_andnot_ps(
                              _mm_cmple_ps(v18, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v19)),
                                v18))),
                          196);
  v21.m_quad = (__m128)atom->m_offset;
  v22 = in->m_transformA.m_storage;
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_andnot_ps(
          _mm_cmple_ps(v23, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(v24, *(__m128 *)_xmm)),
            v23));
  v26 = _mm_shuffle_ps(m_storage->m_invMasses.m_quad, m_storage->m_invMasses.m_quad, 255);
  v27 = _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 170), v22->m_rotation.m_col2.m_quad);
  *(__m128 *)&v10[80] = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v25), 196);
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 85), v22->m_rotation.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 0), v22->m_rotation.m_col0.m_quad)),
          v27);
  v29 = _mm_shuffle_ps(v28, v28, 0);
  v30 = _mm_shuffle_ps(v28, v28, 85);
  v31 = _mm_shuffle_ps(v28, v28, 170);
  v32 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v29, m_storage->m_scratch0.m_quad), _mm_mul_ps(v30, m_storage->m_scratch1.m_quad)),
          _mm_mul_ps(v31, m_storage->m_scratch2.m_quad));
  v33 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v29, v6->m_scratch0.m_quad), _mm_mul_ps(v30, v6->m_scratch1.m_quad)),
          _mm_mul_ps(v31, v6->m_scratch2.m_quad));
  v34 = _mm_shuffle_ps(v6->m_invMasses.m_quad, v6->m_invMasses.m_quad, 255);
  v35 = _mm_add_ps(v34, v26);
  v36 = _mm_rcp_ps(v35);
  v37 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v35)), v36);
  v38 = _mm_mul_ps(_mm_mul_ps(v37, v26), v33);
  v39 = _mm_mul_ps(_mm_mul_ps(v37, v34), v32);
  v40 = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 255);
  v41 = _mm_mul_ps(v21.m_quad, v21.m_quad);
  v42 = _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0);
  v43 = _mm_mul_ps(
          _mm_shuffle_ps(
            (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
            (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
            0),
          v42);
  out->m_jacobianSchemas.m_storage = v10 + 128;
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)), _mm_shuffle_ps(v41, v41, 170));
  v45 = _mm_rsqrt_ps(v44);
  *(__m128 *)&v10[32] = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, v42), 196);
  *(__m128 *)&v10[48] = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v43), 196);
  *(__m128 *)&v10[96] = _mm_shuffle_ps(
                          v39,
                          _mm_unpackhi_ps(
                            v39,
                            _mm_andnot_ps(
                              _mm_cmple_ps(v44, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                                  _mm_mul_ps(v45, *(__m128 *)_xmm)),
                                v44))),
                          196);
  v11.m128_f32[0] = *(float *)v10 + 0.00000011920929;
  *(__m128 *)&v10[112] = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, v40), 196);
  *(_DWORD *)v10 = v11.m128_i32[0];
  *v10 = (hkpJacobianSchema)34;
}

// File Line: 642
// RVA: 0xDD5460
void __fastcall JacobianBuilder::buildJacobianFromAngDeformableAtom_hkpConstraintQueryIn_(
        hkpDeformableAngConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB)
{
  hkpVelocityAccumulator *m_storage; // r14
  _QWORD *v5; // r12
  __m128 *v6; // rbx
  hkpVelocityAccumulator *v7; // r15
  __m128 m_quad; // xmm4
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  hkVector4f v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  hkVector4f v18; // xmm10
  __m128 v19; // xmm8
  hkVector4f v20; // xmm1
  __m128 v21; // xmm6
  hkVector4f v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm7
  __m128 v25; // xmm1
  __m128 v26; // xmm7
  __m128 v27; // xmm0
  hkVector4f v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm7
  __m128 v32; // xmm0
  float v33; // xmm6_4
  float v34; // xmm7_4
  int v35; // r11d
  hkVector4f v36; // xmm1
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm3_4
  bool v40; // cf
  bool v41; // zf
  int v42; // edx
  __int64 v43; // r8
  __int64 v44; // r9
  float v45; // xmm0_4
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm0
  float v52; // xmm3_4
  __m128 v53; // xmm4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm3_4
  float v57; // xmm0_4
  __int64 v58; // r8
  __int64 v59; // r9
  float v60; // xmm0_4
  hkQuaternionf v61; // xmm6
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  __m128 v71; // xmm3
  __m128 v72; // xmm1
  __m128 v73; // xmm0
  __m128 v74; // xmm4
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  __m128 v79; // xmm3
  __m128 v80; // xmm0
  __m128 v81; // xmm2
  __m128 v82; // xmm3
  __m128 v83; // xmm1
  hkQuaternionf v84; // xmm5
  __m128 v85; // xmm5
  __m128 v86; // xmm6
  __m128 v87; // xmm0
  __m128 v88; // xmm2
  __m128 m_storage_low; // xmm4
  __m128 v90; // xmm4
  __m128 v91; // xmm3
  float v92; // [rsp+0h] [rbp-7Dh]
  float v93; // [rsp+4h] [rbp-79h]
  _BYTE v94[48]; // [rsp+Ch] [rbp-71h]
  __m128 v95; // [rsp+3Ch] [rbp-41h]
  __m128 v96; // [rsp+4Ch] [rbp-31h]
  _QWORD *retaddr; // [rsp+FCh] [rbp+7Fh]

  m_storage = in->m_bodyA.m_storage;
  v5 = retaddr;
  v6 = (__m128 *)*retaddr;
  v7 = in->m_bodyB.m_storage;
  m_quad = m_storage->m_scratch1.m_quad;
  v10 = _mm_shuffle_ps(
          (__m128)LODWORD(in->m_microStepDeltaTime.m_storage),
          (__m128)LODWORD(in->m_microStepDeltaTime.m_storage),
          0);
  v11 = _mm_mul_ps(atom->m_ultimateStrengthDiag.m_quad, v10);
  v12 = v7->m_scratch2.m_quad;
  v6[1] = _mm_mul_ps(atom->m_yieldStrengthOffDiag.m_quad, v10);
  v13.m_quad = (__m128)baseA->m_rotation.m_col0;
  v14 = v10;
  v15 = _mm_mul_ps(v10, atom->m_ultimateStrengthOffDiag.m_quad);
  v6[2] = v11;
  v16 = m_storage->m_scratch0.m_quad;
  v6[3] = v15;
  v17 = m_storage->m_scratch2.m_quad;
  v18.m_quad = (__m128)atom->m_yieldStrengthDiag;
  *v6 = _mm_mul_ps(v14, v18.m_quad);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), v16),
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 170), v17));
  v20.m_quad = (__m128)baseA->m_rotation.m_col1;
  *(__m128 *)&v94[32] = v19;
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 0), v16),
            _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 85), m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 170), v17));
  v22.m_quad = (__m128)baseA->m_rotation.m_col2;
  v95 = v21;
  v23 = _mm_shuffle_ps(v22.m_quad, v22.m_quad, 85);
  v24 = _mm_shuffle_ps(v22.m_quad, v22.m_quad, 0);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v22.m_quad, v22.m_quad, 170), v17);
  v26 = _mm_mul_ps(v24, v16);
  v27 = _mm_mul_ps(v23, m_quad);
  v28.m_quad = (__m128)baseB->m_rotation.m_col0;
  v29 = v7->m_scratch1.m_quad;
  v30 = v7->m_scratch0.m_quad;
  v31 = _mm_add_ps(_mm_add_ps(v26, v27), v25);
  v32 = _mm_shuffle_ps(baseB->m_rotation.m_col0.m_quad, baseB->m_rotation.m_col0.m_quad, 85);
  v96 = v31;
  *(__m128 *)&v94[24] = _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 0), v30), _mm_mul_ps(v32, v29)),
                          _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 170), v12));
  v33 = _mm_shuffle_ps(v21, v21, 85).m128_f32[0];
  v34 = _mm_shuffle_ps(v31, v31, 170).m128_f32[0];
  v35 = 0;
  v36.m_quad = (__m128)baseB->m_rotation.m_col2;
  *(__m128 *)v94 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB->m_rotation.m_col1.m_quad, baseB->m_rotation.m_col1.m_quad, 0),
                         v30),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB->m_rotation.m_col1.m_quad, baseB->m_rotation.m_col1.m_quad, 85),
                         v29)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB->m_rotation.m_col1.m_quad, baseB->m_rotation.m_col1.m_quad, 170),
                       v12));
  *(__m128 *)&v94[16] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v36.m_quad, v36.m_quad, 0), v30),
                            _mm_mul_ps(_mm_shuffle_ps(v36.m_quad, v36.m_quad, 85), v29)),
                          _mm_mul_ps(_mm_shuffle_ps(v36.m_quad, v36.m_quad, 170), v12));
  v37 = (float)(v19.m128_f32[0] + v33) + v34;
  if ( v37 <= 0.0 )
  {
    *(_QWORD *)&v94[12] = 2i64;
    *(_DWORD *)&v94[8] = 1;
    v40 = v33 < v19.m128_f32[0];
    v41 = v33 == v19.m128_f32[0];
    v38 = *(float *)&FLOAT_1_0;
    v42 = !v40 && !v41;
    if ( v34 > *(float *)&v94[20 * (!v40 && !v41) + 32] )
      v42 = 2;
    v43 = *(int *)&v94[4 * v42 + 8];
    v44 = *(int *)&v94[4 * v43 + 8];
    v45 = fsqrt(
            (float)(*(float *)&v94[20 * v42 + 32]
                  - (float)(*(float *)&v94[20 * v44 + 32] + *(float *)&v94[20 * v43 + 32]))
          + 1.0);
    *(float *)&v94[4 * v42 + 8] = v45 * 0.5;
    *(float *)&v94[20] = (float)(*(float *)&v94[16 * v43 + 32 + 4 * v44] - *(float *)&v94[16 * v44 + 32 + 4 * v43])
                       * (float)(0.5 / v45);
    *(float *)&v94[4 * v43 + 8] = (float)(*(float *)&v94[16 * v42 + 32 + 4 * v43]
                                        + *(float *)&v94[16 * v43 + 32 + 4 * v42])
                                * (float)(0.5 / v45);
    *(float *)&v94[4 * v44 + 8] = (float)(*(float *)&v94[16 * v44 + 32 + 4 * v42]
                                        + *(float *)&v94[16 * v42 + 32 + 4 * v44])
                                * (float)(0.5 / v45);
  }
  else
  {
    v38 = *(float *)&FLOAT_1_0;
    *(float *)&retaddr = v37 + 1.0;
    v39 = fsqrt(v37 + 1.0);
    *(float *)&v94[20] = v39 * 0.5;
    *(float *)&v94[8] = (float)(v95.m128_f32[2] - v96.m128_f32[1]) * (float)(0.5 / v39);
    *(float *)&v94[12] = (float)(v96.m128_f32[0] - *(float *)&v94[40]) * (float)(0.5 / v39);
    *(float *)&v94[16] = (float)(*(float *)&v94[36] - v95.m128_f32[0]) * (float)(0.5 / v39);
  }
  v46 = _mm_mul_ps(*(__m128 *)&v94[8], *(__m128 *)&v94[8]);
  v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 78), v46);
  v48 = _mm_add_ps(_mm_shuffle_ps(v47, v47, 177), v47);
  v49 = _mm_rsqrt_ps(v48);
  v50 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49));
  v51 = _mm_mul_ps(*(__m128 *)_xmm, v49);
  v52 = *(float *)&v94[24];
  v53 = _mm_mul_ps(*(__m128 *)&v94[8], _mm_mul_ps(v50, v51));
  v54 = *(float *)&v94[24];
  v51.m128_i32[0] = *(_DWORD *)&v94[24];
  v6[4] = v53;
  v55 = (float)(v51.m128_f32[0] + *(float *)&v94[4]) + v52;
  if ( v55 <= 0.0 )
  {
    *(_DWORD *)&v94[8] = 1;
    *(_QWORD *)&v94[12] = 2i64;
    if ( *(float *)&v94[4] > v54 )
      v35 = 1;
    if ( v52 > *(float *)&v94[20 * v35 + 24] )
      v35 = 2;
    v58 = *(int *)&v94[4 * v35 + 8];
    v59 = *(int *)&v94[4 * v58 + 8];
    *(float *)&retaddr = (float)(*(float *)&v94[20 * v35 + 24]
                               - (float)(*(float *)&v94[20 * v59 + 24] + *(float *)&v94[20 * v58 + 24]))
                       + v38;
    v60 = fsqrt(*(float *)&retaddr);
    *(float *)&v94[4 * v35 + 8] = v60 * 0.5;
    *(float *)&v94[20] = (float)(*(float *)&v94[16 * v58 + 24 + 4 * v59] - *(float *)&v94[16 * v59 + 24 + 4 * v58])
                       * (float)(0.5 / v60);
    *(float *)&v94[4 * v58 + 8] = (float)(*(float *)&v94[16 * v35 + 24 + 4 * v58]
                                        + *(float *)&v94[16 * v58 + 24 + 4 * v35])
                                * (float)(0.5 / v60);
    *(float *)&v94[4 * v59 + 8] = (float)(*(float *)&v94[16 * v59 + 24 + 4 * v35]
                                        + *(float *)&v94[16 * v35 + 24 + 4 * v59])
                                * (float)(0.5 / v60);
  }
  else
  {
    *(float *)&retaddr = v55 + v38;
    v56 = fsqrt(v55 + v38);
    v57 = *(float *)&v94[8] - *(float *)&v94[20];
    *(float *)&v94[20] = v56 * 0.5;
    *(float *)&v94[8] = v57 * (float)(0.5 / v56);
    *(float *)&v94[12] = (float)(*(float *)&v94[16] - v93) * (float)(0.5 / v56);
    *(float *)&v94[16] = (float)(v92 - *(float *)v94) * (float)(0.5 / v56);
  }
  v61.m_vec.m_quad = (__m128)atom->m_offset;
  v62 = _mm_shuffle_ps(v7->m_invMasses.m_quad, v7->m_invMasses.m_quad, 255);
  v63 = _mm_mul_ps(*(__m128 *)&v94[8], *(__m128 *)&v94[8]);
  v64 = _mm_add_ps(_mm_shuffle_ps(v63, v63, 78), v63);
  v65 = _mm_add_ps(_mm_shuffle_ps(v64, v64, 177), v64);
  v66 = _mm_rsqrt_ps(v65);
  v67 = _mm_mul_ps(
          *(__m128 *)&v94[8],
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v66, v65), v66)), _mm_mul_ps(v66, *(__m128 *)_xmm)));
  v68 = _mm_add_ps(_mm_shuffle_ps(m_storage->m_invMasses.m_quad, m_storage->m_invMasses.m_quad, 255), v62);
  v6[5] = v67;
  v69 = _mm_rcp_ps(v68);
  v70 = _mm_mul_ps(v61.m_vec.m_quad, qi.m_vec.m_quad);
  v71 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v68)), v69);
  v72 = _mm_add_ps(_mm_shuffle_ps(v70, v70, 78), v70);
  v73 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v72, v72, 177), v72), 0x1Fu), 0x1Fu),
          qi.m_vec.m_quad);
  v74 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v61.m_vec.m_quad, v73), _mm_mul_ps(v62, v71)), v73);
  v75 = _mm_mul_ps(v74, v74);
  v76 = _mm_add_ps(_mm_shuffle_ps(v75, v75, 78), v75);
  v77 = _mm_add_ps(_mm_shuffle_ps(v76, v76, 177), v76);
  v78 = _mm_rsqrt_ps(v77);
  v79 = _mm_cmple_ps(v77, (__m128)0i64);
  v80 = _mm_mul_ps(v78, v77);
  v81 = v61.m_vec.m_quad;
  v82 = _mm_mul_ps(
          _mm_andnot_ps(
            v79,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v80, v78)), _mm_mul_ps(*(__m128 *)_xmm, v78))),
          v74);
  v83 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v61.m_vec.m_quad, v61.m_vec.m_quad, 201), v82),
          _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v61.m_vec.m_quad));
  v84.m_vec.m_quad = (__m128)atom->m_offset;
  v6[6] = v82;
  v85 = _mm_mul_ps(v84.m_vec.m_quad, v84.m_vec.m_quad);
  v86 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v61.m_vec.m_quad, v61.m_vec.m_quad, 255), v82),
            _mm_shuffle_ps(v83, v83, 201)),
          _mm_mul_ps(_mm_shuffle_ps(v82, v82, 255), v61.m_vec.m_quad));
  v87 = _mm_mul_ps(v82, v81);
  v88 = _mm_add_ps(_mm_shuffle_ps(v87, v87, 78), v87);
  v87.m128_i32[0] = LODWORD(in->m_subStepInvDeltaTime.m_storage);
  m_storage_low = (__m128)LODWORD(in->m_tau.m_storage);
  v6[7] = _mm_shuffle_ps(v86, _mm_unpackhi_ps(v86, _mm_add_ps(_mm_shuffle_ps(v88, v88, 177), v88)), 196);
  v90 = _mm_shuffle_ps(m_storage_low, m_storage_low, 0);
  LODWORD(retaddr) = v87.m128_i32[0];
  *v6 = _mm_shuffle_ps(*v6, _mm_unpackhi_ps(*v6, v90), 196);
  v6[1] = _mm_shuffle_ps(
            v6[1],
            _mm_unpackhi_ps(v6[1], _mm_mul_ps(_mm_shuffle_ps((__m128)v87.m128_u32[0], (__m128)v87.m128_u32[0], 0), v90)),
            196);
  v91 = v6[2];
  *v5 = v6 + 8;
  v6[2] = _mm_shuffle_ps(
            v91,
            _mm_unpackhi_ps(
              v91,
              _mm_sub_ps(
                query.m_quad,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
                    _mm_shuffle_ps(v85, v85, 170)),
                  (__m128)xmmword_141A710D0))),
            196);
  v6[3] = _mm_shuffle_ps(v6[3], _mm_unpackhi_ps(v6[3], _mm_shuffle_ps(v18.m_quad, v18.m_quad, 255)), 196);
  v6->m128_f32[0] = v6->m128_f32[0] + 0.00000011920929;
  v6->m128_i8[0] = 35;
}

// File Line: 717
// RVA: 0xDD1D40
hkResult *__fastcall JacobianBuilder::buildJacobianFromAngLimitAtom(
        hkResult *result,
        hkpAngLimitConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkp1dAngularLimitInfo *ali,
        hkpConstraintQueryOut *out)
{
  __int64 m_limitAxis; // r10
  float m_storage; // xmm0_4
  __int64 v9; // r8
  __m128 v10; // xmm9
  __int64 v11; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm8
  __m128 v17; // xmm4
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm6
  __m128 v23; // xmm3
  __m128 v24; // xmm10
  __m128 v25; // xmm2
  __m128 v26; // xmm6
  __m128 v27; // xmm10
  __m128 v28; // xmm11
  __m128 v29; // xmm5
  __m128i v30; // xmm4
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  hkResult *v35; // rax
  unsigned int v36; // [rsp+88h] [rbp+10h]

  if ( atom->m_isEnabled )
  {
    m_limitAxis = (unsigned __int8)atom->m_limitAxis;
    m_storage = in->m_tau.m_storage;
    v9 = (unsigned __int8)modulo3Table[m_limitAxis + 2];
    v10 = 0i64;
    v11 = (unsigned __int8)modulo3Table[m_limitAxis + 1];
    ali->m_tau.m_storage = m_storage * atom->m_angularLimitsTauFactor;
    ali->m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + (int)m_limitAxis);
    v12 = *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + v9);
    v13 = *(__m128 *)((char *)&baseA->m_rotation.m_col0.m_quad + v11);
    v14 = *(&baseB->m_rotation.m_col0.m_quad + (int)m_limitAxis);
    ali->m_min.m_storage = atom->m_minAngle;
    ali->m_max.m_storage = atom->m_maxAngle;
    v15 = _mm_mul_ps(v12, v13);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v14));
    v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v13);
    v19 = _mm_rcp_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170)));
    v20 = _mm_mul_ps(v19, v16);
    v21 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v20), _mm_cmplt_ps(*(__m128 *)_xmm, v20));
    v22 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v20), v21), _mm_andnot_ps(v21, v20));
    v23 = _mm_mul_ps(v22, v22);
    v24 = _mm_cmple_ps((__m128)0i64, v19);
    v25 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v23, *(__m128 *)s0)), *(__m128 *)t0),
                            _mm_add_ps(v23, *(__m128 *)s1))),
                        *(__m128 *)t1),
                      _mm_add_ps(v23, *(__m128 *)s2))),
                  *(__m128 *)t2),
                _mm_add_ps(v23, *(__m128 *)s3))),
            _mm_mul_ps(v22, *(__m128 *)t3));
    *(float *)&v36 = *((float *)out->m_constraintRuntime.m_storage + 1) * -1.0;
    v26 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v22, *(__m128 *)_xmm), *(__m128 *)_xmm), v25), v21),
            _mm_andnot_ps(v21, v25));
    v27 = _mm_or_ps(
            _mm_andnot_ps(v24, _mm_add_ps(_mm_or_ps(_mm_and_ps(v16, *(__m128 *)_xmm), *(__m128 *)_xmm), v26)),
            _mm_and_ps(v26, v24));
    v28 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
    v29 = _mm_sub_ps(v27, _mm_shuffle_ps((__m128)v36, (__m128)v36, 0));
    do
    {
      v30 = (__m128i)_mm_mul_ps(_mm_add_ps(v29, (__m128)xmmword_141A713B0), v28);
      v31 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v30, 1u), 1u));
      v32 = _mm_sub_ps(
              _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v30, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
              *(__m128 *)two23);
      v33 = _mm_or_ps(
              _mm_andnot_ps(v31, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v30, v32)), v32)),
              _mm_and_ps((__m128)v30, v31));
      v10 = _mm_add_ps(v10, v33);
      v29 = _mm_sub_ps(v29, _mm_mul_ps(v33, (__m128)xmmword_141A713F0));
      v34 = _mm_cmplt_ps(v29, (__m128)xmmword_141A713B0);
    }
    while ( fmax(
              0.0 - 3.1415927,
              COERCE_FLOAT(v34.m128_i32[0] & v29.m128_i32[0] | _mm_andnot_ps(v34, (__m128)xmmword_141A713B0).m128_u32[0])) != v29.m128_f32[0] );
    result->m_enum = HK_SUCCESS;
    v35 = result;
    ali->m_computedAngle.m_storage = v27.m128_f32[0] - (float)(v10.m128_f32[0] * 6.2831855);
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  return v35;
}

// File Line: 772
// RVA: 0xDD2050
hkResult *__fastcall JacobianBuilder::bulidJacobianFromTwistLimitAtom(
        hkResult *result,
        hkpTwistLimitConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkp1dAngularLimitInfo *ali)
{
  __m128 v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  float v12; // xmm9_4
  hkVector4f v13; // xmm8
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm7
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm10
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  hkResult *v29; // rax

  ali->m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + (unsigned __int8)atom->m_twistAxis);
  ali->m_min.m_storage = atom->m_minAngle;
  ali->m_max.m_storage = atom->m_maxAngle;
  v6 = _mm_add_ps(
         *(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_twistAxis),
         *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_twistAxis));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_andnot_ps(
          _mm_cmple_ps(v8, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
            v8));
  if ( v10.m128_f32[0] <= _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN16), (__m128)LODWORD(FLOAT_1_0eN16), 0).m128_f32[0] )
  {
    v12 = 0.0;
    v13.m_quad = (__m128)*((_OWORD *)&baseB->m_rotation.m_col0 + (unsigned __int8)atom->m_twistAxis);
  }
  else
  {
    v11 = _mm_rcp_ps(v10);
    v12 = v10.m128_f32[0] * 0.5;
    v13.m_quad = _mm_mul_ps(v6, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v10)), v11));
  }
  v14 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 201);
  v15 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxis),
              *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxis),
              201),
            v13.m_quad),
          _mm_mul_ps(v14, *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxis)));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(*(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxis), v16);
  v18 = _mm_sub_ps(_mm_mul_ps(v14, v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v13.m_quad));
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v20 = _mm_mul_ps(
          *(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxis),
          _mm_shuffle_ps(v18, v18, 201));
  v21 = _mm_rcp_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170)));
  v22 = _mm_cmple_ps((__m128)0i64, v21);
  v23 = _mm_mul_ps(v21, v19);
  v24 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v23), _mm_cmplt_ps(*(__m128 *)_xmm, v23));
  v25 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v23), v24), _mm_andnot_ps(v24, v23));
  v26 = _mm_mul_ps(v25, v25);
  v27 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v26, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v26, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v26, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v26, *(__m128 *)s3))),
          _mm_mul_ps(v25, *(__m128 *)t3));
  v28 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v25, *(__m128 *)_xmm), *(__m128 *)_xmm), v27), v24),
          _mm_andnot_ps(v24, v27));
  result->m_enum = HK_SUCCESS;
  v29 = result;
  LODWORD(ali->m_computedAngle.m_storage) = _mm_andnot_ps(
                                              v22,
                                              _mm_add_ps(
                                                _mm_or_ps(_mm_and_ps(v19, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                v28)).m128_u32[0] | v28.m128_i32[0] & v22.m128_i32[0];
  ali->m_constrainedDofW = (hkVector4f)v13.m_quad;
  ali->m_tau.m_storage = (float)((float)(in->m_tau.m_storage * atom->m_angularLimitsTauFactor) * v12) * v12;
  return v29;
}

// File Line: 789
// RVA: 0xDD2320
hkResult *__fastcall JacobianBuilder::buildJacobianFromConeLimitAtom(
        hkResult *result,
        hkpConeLimitConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkp1dAngularLimitInfo *ali)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm12
  __m128 v9; // xmm12
  __m128 v10; // xmm1
  __m128 v11; // xmm13
  __m128 v13; // xmm2
  __m128 v14; // xmm10
  __m128 v15; // xmm8
  __m128 v16; // xmm0
  __m128 v17; // xmm7
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128i v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm0

  v6 = *(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_twistAxisInA);
  v7 = *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxisInB);
  v8 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  if ( v11.m128_f32[0] >= 0.00000011920929 )
  {
    v13 = _mm_mul_ps(v6, v7);
    v14 = _mm_rsqrt_ps(v11);
    v15 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v11), v14)),
              _mm_mul_ps(*(__m128 *)_xmm, v14)),
            v11);
    v16 = _mm_rcp_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)));
    v17 = _mm_cmple_ps((__m128)0i64, v16);
    v18 = _mm_mul_ps(v16, v15);
    v19 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v18), _mm_cmplt_ps(*(__m128 *)_xmm, v18));
    v20 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v18), v19), _mm_andnot_ps(v19, v18));
    v21 = _mm_mul_ps(v20, v20);
    v22 = *(__m128i *)&hkVector4fComparison_maskToComparison_465[4
                                                               * (atom->m_angleMeasurementMode.m_storage != 0 ? 0xF : 0)];
    v23 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v21, *(__m128 *)s0)), *(__m128 *)t0),
                            _mm_add_ps(v21, *(__m128 *)s1))),
                        *(__m128 *)t1),
                      _mm_add_ps(v21, *(__m128 *)s2))),
                  *(__m128 *)t2),
                _mm_add_ps(v21, *(__m128 *)s3))),
            _mm_mul_ps(v20, *(__m128 *)t3));
    v24 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v20, *(__m128 *)_xmm), *(__m128 *)_xmm), v23), v19),
            _mm_andnot_ps(v19, v23));
    v25 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v22, 0x1Fu), 0x1Fu);
    result->m_enum = HK_SUCCESS;
    v26 = _mm_xor_ps(
            _mm_or_ps(
              _mm_andnot_ps(v17, _mm_add_ps(_mm_or_ps(_mm_and_ps(v15, *(__m128 *)_xmm), *(__m128 *)_xmm), v24)),
              _mm_and_ps(v24, v17)),
            v25);
    ali->m_tau.m_storage = in->m_tau.m_storage * atom->m_angularLimitsTauFactor;
    ali->m_constrainedDofW.m_quad = _mm_mul_ps(
                                      _mm_mul_ps(
                                        v9,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v11), v14)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v14))),
                                      _mm_xor_ps(v25, g_vectorfConstants[0]));
    LODWORD(ali->m_computedAngle.m_storage) = COERCE_UNSIGNED_INT(v26.m128_f32[0] + 1.5707964) & v22.m128i_i32[0] | _mm_andnot_ps((__m128)v22, v26).m128_u32[0];
    ali->m_min.m_storage = atom->m_minAngle;
    ali->m_max.m_storage = atom->m_maxAngle;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 833
// RVA: 0xDD25F0
hkResult *__fastcall JacobianBuilder::buildJacobianFromStabilizedConeLimitAtom(
        hkResult *result,
        hkpConeLimitConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkp1dAngularLimitInfo *ali,
        hkpConstraintQueryOut *out)
{
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm12
  __m128 v11; // xmm12
  __m128 v12; // xmm1
  __m128 v13; // xmm13
  __m128 v15; // xmm2
  __m128 v16; // xmm10
  __m128 v17; // xmm8
  __m128 v18; // xmm0
  __m128 v19; // xmm7
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm6
  __m128 v23; // xmm3
  __m128i v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm6
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  unsigned __int8 m_memOffsetToAngleOffset; // r9
  struct hkpConstraintRuntime *m_storage; // rcx
  float v31; // xmm7_4
  int v32; // xmm9_4
  float v33; // xmm6_4
  float v34; // xmm8_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // [rsp+90h] [rbp+8h]

  v8 = *(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_twistAxisInA);
  v9 = *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxisInB);
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  if ( v13.m128_f32[0] >= 0.00000011920929 )
  {
    v15 = _mm_mul_ps(v9, v8);
    v16 = _mm_rsqrt_ps(v13);
    v17 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v13), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16)),
            v13);
    v18 = _mm_rcp_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170)));
    v19 = _mm_cmple_ps((__m128)0i64, v18);
    v20 = _mm_mul_ps(v18, v17);
    v21 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v20), _mm_cmplt_ps(*(__m128 *)_xmm, v20));
    v22 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v20), v21), _mm_andnot_ps(v21, v20));
    v23 = _mm_mul_ps(v22, v22);
    v24 = *(__m128i *)&hkVector4fComparison_maskToComparison_465[4
                                                               * (atom->m_angleMeasurementMode.m_storage != 0 ? 0xF : 0)];
    v25 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v23, *(__m128 *)s0)), *(__m128 *)t0),
                            _mm_add_ps(v23, *(__m128 *)s1))),
                        *(__m128 *)t1),
                      _mm_add_ps(v23, *(__m128 *)s2))),
                  *(__m128 *)t2),
                _mm_add_ps(v23, *(__m128 *)s3))),
            _mm_mul_ps(v22, *(__m128 *)t3));
    v26 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v22, *(__m128 *)_xmm), *(__m128 *)_xmm), v25), v21),
            _mm_andnot_ps(v21, v25));
    v27 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v24, 0x1Fu), 0x1Fu);
    result->m_enum = HK_SUCCESS;
    v28 = _mm_xor_ps(
            _mm_or_ps(
              _mm_andnot_ps(v19, _mm_add_ps(_mm_or_ps(_mm_and_ps(v17, *(__m128 *)_xmm), *(__m128 *)_xmm), v26)),
              _mm_and_ps(v26, v19)),
            v27);
    ali->m_tau.m_storage = in->m_tau.m_storage * atom->m_angularLimitsTauFactor;
    ali->m_constrainedDofW.m_quad = _mm_mul_ps(
                                      _mm_mul_ps(
                                        v11,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v13), v16)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v16))),
                                      _mm_xor_ps(v27, g_vectorfConstants[0]));
    LODWORD(ali->m_computedAngle.m_storage) = COERCE_UNSIGNED_INT(v28.m128_f32[0] + 1.5707964) & v24.m128i_i32[0] | _mm_andnot_ps((__m128)v24, v28).m128_u32[0];
    ali->m_min.m_storage = atom->m_minAngle;
    ali->m_max.m_storage = atom->m_maxAngle;
    m_memOffsetToAngleOffset = atom->m_memOffsetToAngleOffset;
    if ( m_memOffsetToAngleOffset > 1u )
    {
      m_storage = out->m_constraintRuntime.m_storage;
      v39 = in->m_frameDeltaTime.m_storage * 0.5;
      v31 = *(float *)((char *)m_storage + m_memOffsetToAngleOffset);
      v32 = *((_DWORD *)m_storage + 1) ^ _xmm[0];
      v33 = ali->m_computedAngle.m_storage - v31;
      v34 = *(float *)&v32 - v33;
      v35 = fmaxf(v31 * 0.050000001, v39);
      LODWORD(v36) = COERCE_UNSIGNED_INT(*(float *)&v32 - v33) ^ _xmm[0];
      v37 = v31 - v35;
      v38 = v33 + v35;
      if ( v36 > (float)((float)((float)(v35 * 2.0) + v39) * 0.5) && *(float *)&v32 != 0.0 )
      {
        v37 = v37 - v34;
        v38 = v38 + v34;
      }
      *(float *)((char *)m_storage + m_memOffsetToAngleOffset) = fmaxf(v37, 0.00000011920929);
      ali->m_computedAngle.m_storage = v38;
    }
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 894
// RVA: 0xDD4E70
void __fastcall JacobianBuilder::_1dAngularFrictionBuildJacobian_hkpConstraintQueryIn_(
        hkp1dAngularFrictionInfo *info,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  int m_storage; // edi
  hkVector4f *v4; // rbx
  hkpJacobianSchema *v5; // r10
  int v6; // esi
  hkpVelocityAccumulator *v7; // r9
  __m128 m_quad; // xmm9
  float v9; // xmm7_4
  __m128 v10; // xmm6
  __m128 v11; // xmm10
  __m128 v12; // xmm8
  __m128 v13; // xmm5
  __m128 v14; // xmm11
  hkpVelocityAccumulator *v15; // rax
  __m128 v16; // xmm12
  __m128 v17; // xmm13
  __m128 v18; // xmm14
  __m128 v19; // xmm15
  float *p_m_internalSolverData; // rax
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  float v30; // xmm0_4

  m_storage = info->m_numFriction.m_storage;
  v4 = info->m_constrainedDofW.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  v6 = 0;
  if ( m_storage > 0 )
  {
    v7 = in->m_bodyA.m_storage;
    m_quad = v7->m_scratch1.m_quad;
    v9 = info->m_maxFrictionTorque.m_storage * in->m_microStepDeltaTime.m_storage;
    v10 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
    v11 = v7->m_scratch0.m_quad;
    v12 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    v13 = _mm_shuffle_ps((__m128)LODWORD(in->m_rhsFactor.m_storage), (__m128)LODWORD(in->m_rhsFactor.m_storage), 0);
    v14 = v7->m_scratch2.m_quad;
    v15 = in->m_bodyB.m_storage;
    v16 = v15->m_scratch1.m_quad;
    v17 = v15->m_scratch0.m_quad;
    v18 = v15->m_scratch2.m_quad;
    v19 = v15->m_invMasses.m_quad;
    p_m_internalSolverData = &info->m_lastSolverResults.m_storage->m_internalSolverData;
    do
    {
      v21 = v4->m_quad;
      *(_DWORD *)&v5[36] = v6++;
      *(float *)&v5[32] = v9;
      v5 += 48;
      ++v4;
      p_m_internalSolverData += 4;
      v22 = _mm_xor_ps(v21, v12);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v11), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v14));
      v24 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v17), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v18));
      v25 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v24, v24), v19), _mm_mul_ps(_mm_mul_ps(v23, v23), v7->m_invMasses.m_quad));
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                _mm_shuffle_ps(v25, v25, 170)),
              *(__m128 *)&epsilon);
      v27 = _mm_rcp_ps(v26);
      v28 = _mm_shuffle_ps(
              v23,
              _mm_unpackhi_ps(v23, _mm_mul_ps(v10, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27))),
              196);
      v29 = _mm_shuffle_ps(
              (__m128)*((unsigned int *)p_m_internalSolverData - 4),
              (__m128)*((unsigned int *)p_m_internalSolverData - 4),
              0);
      *(__m128 *)&v5[-48] = v28;
      v30 = *(float *)&v5[-48] + 0.00000011920929;
      *(__m128 *)&v5[-32] = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_mul_ps(v29, v13)), 196);
      *(float *)&v5[-48] = v30;
      v5[-48] = (hkpJacobianSchema)14;
    }
    while ( v6 < m_storage );
  }
  out->m_jacobianSchemas.m_storage = v5;
}

// File Line: 922
// RVA: 0xDD5F50
void __fastcall JacobianBuilder::buildJacobianFromAngFrictionAtom_hkpConstraintQueryIn_(
        hkpAngFrictionConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  float m_maxFrictionTorque; // xmm5_4
  int m_numFrictionAxes; // r11d
  int v8; // edi
  struct hkpConstraintRuntime *v9; // r9
  hkpJacobianSchema *v10; // rdx
  char *v11; // r10
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  hkpVelocityAccumulator *v15; // rax
  hkpVelocityAccumulator *v16; // rcx
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  hkpJacobianSchema *m_storage; // rax

  if ( !atom->m_isEnabled || (m_maxFrictionTorque = atom->m_maxFrictionTorque, m_maxFrictionTorque == 0.0) )
  {
    m_storage = out->m_jacobianSchemas.m_storage;
    m_storage[4] = (hkpJacobianSchema)(2 * atom->m_numFrictionAxes);
    m_storage += 16;
    *(float *)&m_storage[-16] = *(float *)&m_storage[-16] + 0.00000011920929;
    m_storage[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = m_storage;
  }
  else
  {
    m_numFrictionAxes = (unsigned __int8)atom->m_numFrictionAxes;
    v8 = 0;
    v9 = (struct hkpConstraintRuntime *)(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_firstFrictionAxis);
    v10 = out->m_jacobianSchemas.m_storage;
    if ( atom->m_numFrictionAxes )
    {
      v11 = (char *)(out->m_constraintRuntime.m_storage - v9);
      v12 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
      v13 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
      do
      {
        v14 = *(__m128 *)v9;
        v15 = in->m_bodyA.m_storage;
        v16 = in->m_bodyB.m_storage;
        v17 = *(__m128 *)v9;
        v18 = *(__m128 *)v9;
        v10 += 48;
        v9 = (struct hkpConstraintRuntime *)((char *)v9 + 16);
        v19 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v15->m_scratch1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v14, 0), v15->m_scratch0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v15->m_scratch2.m_quad));
        *(__m128 *)&v10[-48] = v19;
        v20 = _mm_xor_ps(v18, v13);
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v16->m_scratch1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v16->m_scratch0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v16->m_scratch2.m_quad));
        v22 = v19;
        *(__m128 *)&v10[-32] = v21;
        v23 = _mm_add_ps(
                _mm_mul_ps(_mm_mul_ps(v19, v19), v15->m_invMasses.m_quad),
                _mm_mul_ps(_mm_mul_ps(v21, v21), v16->m_invMasses.m_quad));
        v24 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                  _mm_shuffle_ps(v23, v23, 170)),
                *(__m128 *)&epsilon);
        v25 = _mm_rcp_ps(v24);
        *(__m128 *)&v10[-48] = _mm_shuffle_ps(
                                 v22,
                                 _mm_unpackhi_ps(
                                   v22,
                                   _mm_mul_ps(v12, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v24)), v25))),
                                 196);
        v25.m128_f32[0] = *(float *)&v10[-48] + 0.00000011920929;
        *(__m128 *)&v10[-32] = _mm_shuffle_ps(
                                 *(__m128 *)&v10[-32],
                                 _mm_unpackhi_ps(
                                   *(__m128 *)&v10[-32],
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(
                                       (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                       (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                       0),
                                     _mm_shuffle_ps(
                                       (__m128)*(unsigned int *)((char *)v9 + (_QWORD)v11 - 12),
                                       (__m128)*(unsigned int *)((char *)v9 + (_QWORD)v11 - 12),
                                       0))),
                                 196);
        v17.m128_f32[0] = m_maxFrictionTorque * in->m_microStepDeltaTime.m_storage;
        *(_DWORD *)&v10[-12] = v8;
        *(_DWORD *)&v10[-48] = v25.m128_i32[0];
        ++v8;
        v10[-48] = (hkpJacobianSchema)14;
        *(_DWORD *)&v10[-16] = v17.m128_i32[0];
      }
      while ( v8 < m_numFrictionAxes );
    }
    out->m_jacobianSchemas.m_storage = v10;
  }
}

// File Line: 943
// RVA: 0xDD5D90
void __fastcall JacobianBuilder::buildJacobianFromLinMotorAtom_hkpConstraintQueryIn_(
        hkpLinMotorConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpConstraintMotor *m_motor; // rbp
  _BYTE *v8; // r14
  float *v9; // r15
  hkpJacobianSchema *m_storage; // rdi
  hkVector4f *p_m_translation; // rbx
  hkVector4f *v12; // rcx
  hkpJacobianSchema *v13; // r9
  float m_targetPosition; // xmm0_4
  __m128 v15; // xmm2
  hkpSolverResults v16; // rax
  __int64 v17; // rax
  __m128 v18; // xmm2
  float v19; // xmm0_4
  hkpJacobianSchema *v20; // rax
  hkpConstraintMotorOutput output; // [rsp+30h] [rbp-68h] BYREF
  hkpConstraintMotorInput statusOut; // [rsp+48h] [rbp-50h] BYREF

  if ( atom->m_isEnabled.m_bool && (m_motor = atom->m_motor) != 0i64 )
  {
    v8 = (char *)out->m_constraintRuntime.m_storage + atom->m_initializedOffset;
    v9 = (float *)((char *)out->m_constraintRuntime.m_storage + atom->m_previousTargetPositionOffset);
    if ( !*v8 )
      *v9 = atom->m_targetPosition;
    m_storage = out->m_jacobianSchemas.m_storage;
    p_m_translation = &baseA->m_translation;
    v12 = &baseB->m_rotation.m_col0 + (unsigned __int8)atom->m_motorAxis;
    v13 = out->m_jacobianSchemas.m_storage;
    statusOut.m_lastResults = 0i64;
    hk1dLinearVelocityMotorBeginJacobian(v12, &baseA->m_translation, in, (hkp1Lin2AngJacobian *)v13, &statusOut);
    m_targetPosition = atom->m_targetPosition;
    v15 = _mm_sub_ps(p_m_translation->m_quad, baseB->m_translation.m_quad);
    v16 = *(hkpSolverResults *)out->m_constraintRuntime.m_storage;
    statusOut.m_stepInfo.m_storage = in;
    statusOut.m_lastResults = v16;
    v17 = 2i64 * (unsigned __int8)atom->m_motorAxis;
    statusOut.m_deltaTarget.m_storage = m_targetPosition - *v9;
    v18 = _mm_mul_ps(v15, *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17));
    statusOut.m_positionError.m_storage = *v9
                                        - (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0]
                                                        + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                                                + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]);
    hkCalcMotorData(m_motor, &statusOut, &output);
    hk1dLinearVelocityMotorCommitJacobian(&output, in, (hkp1Lin2AngJacobian *)m_storage, out);
    v19 = atom->m_targetPosition;
    if ( v19 != *v9 || !*v8 )
    {
      *v9 = v19;
      *v8 = 1;
    }
  }
  else
  {
    v20 = out->m_jacobianSchemas.m_storage + 16;
    v20[-12] = (hkpJacobianSchema)2;
    *(float *)&v20[-16] = *(float *)&v20[-16] + 0.00000011920929;
    v20[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v20;
  }
}

// File Line: 1021
// RVA: 0xDD6170
void __fastcall JacobianBuilder::buildJacobianFromAngMotorAtom_hkpConstraintQueryIn_(
        hkpAngMotorConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpConstraintMotor *m_motor; // r10
  __int64 m_motorAxis; // rdx
  struct hkpConstraintRuntime *m_storage; // r11
  _BYTE *v10; // rsi
  float *v11; // rbp
  __m128 v12; // xmm9
  __int64 v13; // rcx
  __m128 *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm8
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm7
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __int16 m_correspondingAngLimitSolverResultOffset; // ax
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  __m128 v28; // xmm10
  __m128 v29; // xmm11
  __m128 v30; // xmm5
  __m128i v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  hkpVelocityAccumulator *v36; // rdx
  hkpVelocityAccumulator *v37; // rcx
  __int64 v38; // rax
  hkpJacobianSchema *v39; // rbx
  __m128 v40; // xmm2
  hkpSolverResults v41; // rax
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  hkpJacobianSchema *v50; // rax
  float m_targetAngle; // xmm0_4
  hkpJacobianSchema *v52; // rax
  hkpConstraintMotorOutput output; // [rsp+20h] [rbp-C8h] BYREF
  hkpConstraintMotorInput input; // [rsp+38h] [rbp-B0h] BYREF
  unsigned int v55; // [rsp+F0h] [rbp+8h]

  m_motor = atom->m_motor;
  if ( m_motor && atom->m_isEnabled.m_bool )
  {
    m_motorAxis = (unsigned __int8)atom->m_motorAxis;
    m_storage = out->m_constraintRuntime.m_storage;
    v10 = (char *)m_storage + atom->m_initializedOffset;
    v11 = (float *)((char *)m_storage + atom->m_previousTargetAngleOffset);
    v12 = 0i64;
    v13 = (unsigned __int8)modulo3Table[m_motorAxis + 1];
    v14 = (__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)modulo3Table[m_motorAxis + 2]);
    v15 = _mm_mul_ps(*(__m128 *)((char *)&baseA->m_rotation.m_col0.m_quad + v13), *v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(
                *(&baseB->m_rotation.m_col0.m_quad + m_motorAxis),
                *(&baseB->m_rotation.m_col0.m_quad + m_motorAxis),
                201),
              *v14),
            _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 201), *(&baseB->m_rotation.m_col0.m_quad + m_motorAxis)));
    v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), *(__m128 *)((char *)&baseA->m_rotation.m_col0.m_quad + v13));
    v19 = _mm_rcp_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170)));
    v20 = _mm_cmple_ps((__m128)0i64, v19);
    v21 = _mm_mul_ps(v19, v16);
    v22 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v21), _mm_cmplt_ps(*(__m128 *)_xmm, v21));
    v23 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v21), v22), _mm_andnot_ps(v22, v21));
    v24 = _mm_mul_ps(v23, v23);
    m_correspondingAngLimitSolverResultOffset = atom->m_correspondingAngLimitSolverResultOffset;
    v26 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v24, *(__m128 *)s0)), *(__m128 *)t0),
                            _mm_add_ps(v24, *(__m128 *)s1))),
                        *(__m128 *)t1),
                      _mm_add_ps(v24, *(__m128 *)s2))),
                  *(__m128 *)t2),
                _mm_add_ps(v24, *(__m128 *)s3))),
            _mm_mul_ps(v23, *(__m128 *)t3));
    v27 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v23, *(__m128 *)_xmm), *(__m128 *)_xmm), v26), v22),
            _mm_andnot_ps(v22, v26));
    v28 = _mm_or_ps(
            _mm_andnot_ps(v20, _mm_add_ps(_mm_or_ps(_mm_and_ps(v16, *(__m128 *)_xmm), *(__m128 *)_xmm), v27)),
            _mm_and_ps(v27, v20));
    if ( m_correspondingAngLimitSolverResultOffset )
    {
      *(float *)&v55 = *(float *)((char *)m_storage + m_correspondingAngLimitSolverResultOffset + 4) * -1.0;
      v29 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
      v30 = _mm_sub_ps(v28, _mm_shuffle_ps((__m128)v55, (__m128)v55, 0));
      do
      {
        v31 = (__m128i)_mm_mul_ps(_mm_add_ps(v30, (__m128)xmmword_141A713B0), v29);
        v32 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u));
        v33 = _mm_sub_ps(
                _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v31, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
                *(__m128 *)two23);
        v34 = _mm_or_ps(
                _mm_andnot_ps(v32, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v31, v33)), v33)),
                _mm_and_ps((__m128)v31, v32));
        v12 = _mm_add_ps(v12, v34);
        v30 = _mm_sub_ps(v30, _mm_mul_ps(v34, (__m128)xmmword_141A713F0));
        v35 = _mm_cmplt_ps(v30, (__m128)xmmword_141A713B0);
      }
      while ( fmax(
                0.0 - 3.1415927,
                COERCE_FLOAT(_mm_andnot_ps(v35, (__m128)xmmword_141A713B0).m128_u32[0] | v30.m128_i32[0] & v35.m128_i32[0])) != v30.m128_f32[0] );
      v28.m128_f32[0] = v28.m128_f32[0] - (float)(v12.m128_f32[0] * 6.2831855);
    }
    if ( !*v10 )
      *v11 = v28.m128_f32[0];
    v36 = in->m_bodyA.m_storage;
    v37 = in->m_bodyB.m_storage;
    v38 = (unsigned __int8)atom->m_motorAxis;
    v39 = out->m_jacobianSchemas.m_storage;
    input.m_lastResults = 0i64;
    v40 = *(&baseA->m_rotation.m_col0.m_quad + v38);
    v41 = *(hkpSolverResults *)m_storage;
    v42 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v40);
    v43 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v36->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v36->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v36->m_scratch2.m_quad));
    v44 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v37->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v37->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v37->m_scratch2.m_quad));
    v45 = _mm_mul_ps(_mm_mul_ps(v43, v43), v36->m_invMasses.m_quad);
    *(__m128 *)&v39[16] = v44;
    v46 = _mm_mul_ps(_mm_mul_ps(v44, v44), v37->m_invMasses.m_quad);
    input.m_stepInfo.m_storage = in;
    input.m_lastResults = v41;
    v47 = _mm_add_ps(v46, v45);
    v48 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
              _mm_shuffle_ps(v47, v47, 170)),
            *(__m128 *)&epsilon);
    v49 = _mm_rcp_ps(v48);
    *(__m128 *)v39 = _mm_shuffle_ps(
                       v43,
                       _mm_unpackhi_ps(
                         v43,
                         _mm_mul_ps(
                           _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v48)), v49))),
                       196);
    input.m_effMass.m_storage = *(float *)&v39[12];
    input.m_deltaTarget.m_storage = atom->m_targetAngle - *v11;
    input.m_positionError.m_storage = *v11 - v28.m128_f32[0];
    hkCalcMotorData(m_motor, &input, &output);
    v50 = out->m_jacobianSchemas.m_storage;
    *(float *)&v39[28] = output.m_targetPosition.m_storage * in->m_subStepInvDeltaTime.m_storage;
    v48.m128_i32[0] = *(_DWORD *)v50;
    v50 += 64;
    *(float *)&v50[-64] = v48.m128_f32[0] + 0.00000011920929;
    v50[-64] = (hkpJacobianSchema)15;
    *(float *)&v50[-32] = output.m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
    v48.m128_f32[0] = output.m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
    out->m_jacobianSchemas.m_storage = v50;
    *(_DWORD *)&v50[-28] = v48.m128_i32[0];
    *(float *)&v50[-24] = output.m_targetVelocity.m_storage;
    *(float *)&v50[-20] = output.m_tau.m_storage;
    *(float *)&v50[-16] = output.m_damping.m_storage;
    m_targetAngle = atom->m_targetAngle;
    if ( m_targetAngle != *v11 || !*v10 )
    {
      *v11 = m_targetAngle;
      *v10 = 1;
    }
  }
  else
  {
    v52 = out->m_jacobianSchemas.m_storage + 16;
    v52[-12] = (hkpJacobianSchema)2;
    *(float *)&v52[-16] = *(float *)&v52[-16] + 0.00000011920929;
    v52[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v52;
  }
}

// File Line: 1129
// RVA: 0xDD66C0
void __fastcall JacobianBuilder::buildJacobianFromRagdollMotorAtom_hkpConstraintQueryIn_(
        hkpRagdollMotorConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  _BYTE *v7; // r12
  __int64 v8; // r15
  hkpConstraintQueryStepInfo *v9; // rcx
  int v10; // esi
  __int64 v11; // r8
  hkpConstraintMotor **m_motors; // r13
  unsigned __int64 v13; // rdi
  hkpConstraintMotor *v14; // r9
  __int64 v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rdx
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128 v28; // xmm14
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm7
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm6
  __m128 v35; // xmm2
  __m128 v36; // xmm4
  __m128 v37; // xmm5
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm5
  __m128 v41; // xmm7
  __m128 v42; // xmm6
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm6
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm5
  __m128 v55; // xmm3
  __m128 v56; // xmm0
  __m128 v57; // xmm9
  __m128 v58; // xmm2
  __m128 v59; // xmm8
  __m128 v60; // xmm4
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  __m128 v63; // xmm4
  __m128 *v64; // rax
  __m128 *v65; // rcx
  __m128 *v66; // rbx
  __m128 v67; // xmm4
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm2
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  float *v76; // rax
  __int64 v77; // rax
  __int64 v78; // rax
  __int64 v79; // [rsp+20h] [rbp-C8h]
  float v80; // [rsp+38h] [rbp-B0h]
  float v81; // [rsp+3Ch] [rbp-ACh]
  __int64 v82; // [rsp+48h] [rbp-A0h]
  int v83; // [rsp+50h] [rbp-98h]
  int v84[4]; // [rsp+58h] [rbp-90h]
  hkpConstraintMotorInput output; // [rsp+68h] [rbp-80h] BYREF
  hkMatrix3f THIS; // [rsp+88h] [rbp-60h] BYREF
  int v87; // [rsp+1A8h] [rbp+C0h]
  hkpConstraintQueryStepInfo *vars0; // [rsp+1B0h] [rbp+C8h]
  char *retaddr; // [rsp+1B8h] [rbp+D0h]
  hkTransformf *v90; // [rsp+1C0h] [rbp+D8h]

  if ( atom->m_isEnabled.m_bool )
  {
    v7 = (_BYTE *)(*(_QWORD *)&in->m_subStepInvDeltaTime.m_storage + atom->m_initializedOffset);
    v8 = *(_QWORD *)&in->m_subStepInvDeltaTime.m_storage + atom->m_previousTargetAnglesOffset;
    hkMatrix3f_setMulMat3Mat3(&THIS, &in->m_transformB.m_storage->m_rotation, &atom->m_target_bRca);
    v9 = vars0;
    v10 = 0;
    output.m_lastResults = 0i64;
    v84[0] = 0;
    v84[1] = 1;
    output.m_stepInfo.m_storage = vars0;
    v84[2] = 2;
    v82 = 1i64;
    v83 = 0;
    v11 = 0i64;
    v79 = 0i64;
    m_motors = atom->m_motors;
    v13 = 0i64;
    do
    {
      v14 = *m_motors;
      if ( *m_motors )
      {
        v15 = *(int *)((char *)&v82 + v13);
        v16 = 2i64 * v84[v13 / 4];
        v87 = 619091349;
        v17 = 2 * v15;
        v18 = _mm_add_ps(*(__m128 *)&retaddr[8 * v16], *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v16));
        v19 = _mm_mul_ps(v18, v18);
        v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170));
        v21 = _mm_rsqrt_ps(v20);
        v22 = _mm_andnot_ps(
                _mm_cmple_ps(v20, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                    _mm_mul_ps(v21, *(__m128 *)_xmm)),
                  v20));
        if ( v22.m128_f32[0] <= _mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0).m128_f32[0] )
        {
          v24 = *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v16);
        }
        else
        {
          v23 = _mm_rcp_ps(v22);
          v24 = _mm_mul_ps(v18, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23));
        }
        v25 = _mm_shuffle_ps(v24, v24, 201);
        v26 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17),
                    *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17),
                    201),
                  v24),
                _mm_mul_ps(*(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17), v25));
        v27 = _mm_shuffle_ps(v26, v26, 201);
        v28 = _mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm);
        v29 = _mm_mul_ps(*(__m128 *)&retaddr[8 * v17], v27);
        v30 = _mm_sub_ps(_mm_mul_ps(v25, v27), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v24));
        v31 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                _mm_shuffle_ps(v29, v29, 170));
        v32 = _mm_mul_ps(*(__m128 *)&retaddr[8 * v17], _mm_shuffle_ps(v30, v30, 201));
        v33 = _mm_rcp_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                  _mm_shuffle_ps(v32, v32, 170)));
        v34 = _mm_cmple_ps((__m128)0i64, v33);
        v35 = _mm_mul_ps(v33, v31);
        v36 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)_xmm, v35), _mm_cmpnle_ps(v28, v35));
        v37 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v35), v36), _mm_andnot_ps(v36, v35));
        v38 = _mm_mul_ps(v37, v37);
        v39 = _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_rcp_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v38, *(__m128 *)s0)), *(__m128 *)t0),
                                _mm_add_ps(v38, *(__m128 *)s1))),
                            *(__m128 *)t1),
                          _mm_add_ps(v38, *(__m128 *)s2))),
                      *(__m128 *)t2),
                    _mm_add_ps(v38, *(__m128 *)s3))),
                _mm_mul_ps(v37, *(__m128 *)t3));
        v40 = _mm_or_ps(
                _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v37, *(__m128 *)_xmm), *(__m128 *)_xmm), v39), v36),
                _mm_andnot_ps(v36, v39));
        v41 = _mm_add_ps(_mm_or_ps(_mm_and_ps(v31, *(__m128 *)_xmm), *(__m128 *)_xmm), v40);
        v40.m128_i32[0] &= v34.m128_i32[0];
        v33.m128_f32[0] = _mm_andnot_ps(v34, v41).m128_f32[0];
        v42 = _mm_add_ps(
                *(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v16),
                *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v16));
        LODWORD(v81) = v33.m128_i32[0] | v40.m128_i32[0];
        v43 = _mm_mul_ps(v42, v42);
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                _mm_shuffle_ps(v43, v43, 170));
        v45 = _mm_rsqrt_ps(v44);
        v46 = _mm_andnot_ps(
                _mm_cmple_ps(v44, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                    _mm_mul_ps(v45, *(__m128 *)_xmm)),
                  v44));
        if ( v46.m128_f32[0] <= _mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0).m128_f32[0] )
        {
          v48 = *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v16);
        }
        else
        {
          v47 = _mm_rcp_ps(v46);
          v48 = _mm_mul_ps(v42, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v47, v46)), v47));
        }
        v49 = _mm_shuffle_ps(v48, v48, 201);
        v50 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17),
                    *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17),
                    201),
                  v48),
                _mm_mul_ps(v49, *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + 8 * v17)));
        v51 = _mm_shuffle_ps(v50, v50, 201);
        v52 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v17), v51);
        v53 = _mm_sub_ps(_mm_mul_ps(v49, v51), _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v48));
        v54 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170));
        v55 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v17), _mm_shuffle_ps(v53, v53, 201));
        v56 = _mm_rcp_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)));
        v57 = _mm_cmple_ps((__m128)0i64, v56);
        v58 = _mm_mul_ps(v56, v54);
        v59 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)_xmm, v58), _mm_cmpnle_ps(v28, v58));
        v60 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v58), v59), _mm_andnot_ps(v59, v58));
        v61 = _mm_mul_ps(v60, v60);
        v62 = _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_rcp_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v61, *(__m128 *)s0)), *(__m128 *)t0),
                                _mm_add_ps(v61, *(__m128 *)s1))),
                            *(__m128 *)t1),
                          _mm_add_ps(v61, *(__m128 *)s2))),
                      *(__m128 *)t2),
                    _mm_add_ps(v61, *(__m128 *)s3))),
                _mm_mul_ps(v60, *(__m128 *)t3));
        v63 = _mm_or_ps(
                _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v60, *(__m128 *)_xmm), *(__m128 *)_xmm), v62), v59),
                _mm_andnot_ps(v59, v62));
        LODWORD(v80) = _mm_andnot_ps(v57, _mm_add_ps(_mm_or_ps(_mm_and_ps(v54, *(__m128 *)_xmm), *(__m128 *)_xmm), v63)).m128_u32[0] | v63.m128_i32[0] & v57.m128_i32[0];
        if ( !*v7 )
        {
          *(float *)(v13 + v8) = v81;
          *v7 = 1;
        }
        v64 = *(__m128 **)&v9[1].m_subStepInvDeltaTime.m_storage;
        v65 = *(__m128 **)&v9[1].m_subStepDeltaTime.m_storage;
        v66 = *(__m128 **)&in->m_subStepDeltaTime.m_storage;
        v67 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v65[5]);
        v66[3].m128_i32[1] = v10;
        v68 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v48);
        v69 = _mm_add_ps(
                _mm_add_ps(v67, _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v65[4])),
                _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v65[6]));
        v70 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v68, v68, 85), v64[5]),
                  _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), v64[4])),
                _mm_mul_ps(_mm_shuffle_ps(v68, v68, 170), v64[6]));
        v71 = _mm_mul_ps(_mm_mul_ps(v69, v69), v65[3]);
        v66[1] = v70;
        v72 = _mm_mul_ps(_mm_mul_ps(v70, v70), v64[3]);
        output.m_lastResults = *(hkpSolverResults *)(*(_QWORD *)&in->m_subStepInvDeltaTime.m_storage + v11);
        v73 = _mm_add_ps(v72, v71);
        v74 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                  _mm_shuffle_ps(v73, v73, 170)),
                *(__m128 *)&epsilon);
        v75 = _mm_rcp_ps(v74);
        *v66 = _mm_shuffle_ps(
                 v69,
                 _mm_unpackhi_ps(
                   v69,
                   _mm_mul_ps(
                     _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v75, v74)), v75))),
                 196);
        LODWORD(output.m_effMass.m_storage) = v66->m128_i32[3];
        output.m_deltaTarget.m_storage = v80 - *(float *)(v13 + v8);
        output.m_positionError.m_storage = *(float *)(v13 + v8) - v81;
        hkCalcMotorData(v14, &output, (hkpConstraintMotorOutput *)&output);
        v76 = *(float **)&in->m_subStepDeltaTime.m_storage;
        v9 = vars0;
        v71.m128_f32[0] = output.m_effMass.m_storage * vars0->m_subStepInvDeltaTime.m_storage;
        *v76 = **(float **)&in->m_subStepDeltaTime.m_storage + 0.00000011920929;
        v66[1].m128_i32[3] = v71.m128_i32[0];
        baseB = v90;
        *(_BYTE *)v76 = 15;
        v76 += 16;
        *(v76 - 8) = *(float *)&output.m_stepInfo.m_storage * v9->m_microStepDeltaTime.m_storage;
        v74.m128_f32[0] = *((float *)&output.m_stepInfo.m_storage + 1) * v9->m_microStepDeltaTime.m_storage;
        *(_QWORD *)&in->m_subStepDeltaTime.m_storage = v76;
        *(v76 - 7) = v74.m128_f32[0];
        *(v76 - 6) = *((float *)&output.hkp1dBilateralConstraintStatus + 1);
        *(hkpSolverResults *)(v76 - 5) = output.m_lastResults;
        if ( v80 != *(float *)(v13 + v8) )
          *(float *)(v13 + v8) = v80;
      }
      else
      {
        v77 = *(_QWORD *)&in->m_subStepDeltaTime.m_storage + 16i64;
        *(_BYTE *)(v77 - 12) = 2;
        *(float *)(v77 - 16) = *(float *)(v77 - 16) + 0.00000011920929;
        *(_BYTE *)(v77 - 16) = 3;
        *(_QWORD *)&in->m_subStepDeltaTime.m_storage = v77;
      }
      v79 += 16i64;
      ++v10;
      ++m_motors;
      v11 = v79;
      ++v7;
      v13 += 4i64;
    }
    while ( v10 < 3 );
  }
  else
  {
    v78 = *(_QWORD *)&in->m_subStepDeltaTime.m_storage + 16i64;
    *(_BYTE *)(v78 - 12) = 6;
    *(float *)(v78 - 16) = *(float *)(v78 - 16) + 0.00000011920929;
    *(_BYTE *)(v78 - 16) = 3;
    *(_QWORD *)&in->m_subStepDeltaTime.m_storage = v78;
  }
}

// File Line: 1271
// RVA: 0xDD5B70
void __fastcall JacobianBuilder::buildJacobianFromLinFrictionAtom_hkpConstraintQueryIn_(
        hkpLinFrictionConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  float m_maxFrictionForce; // xmm7_4
  hkVector4f v7; // xmm4
  __int64 m_frictionAxis; // rax
  hkpVelocityAccumulator *m_storage; // rcx
  __m128 v10; // xmm3
  hkpVelocityAccumulator *v11; // rax
  hkpJacobianSchema *v12; // r8
  struct hkpConstraintRuntime *v13; // rdx
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm5
  __m128 v23; // xmm4
  __m128 m_quad; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  float *v30; // rcx
  float v31; // xmm7_4
  hkpJacobianSchema *v32; // rax
  float v33; // [rsp+30h] [rbp+8h]

  if ( atom->m_isEnabled && (m_maxFrictionForce = atom->m_maxFrictionForce, m_maxFrictionForce > 0.0) )
  {
    v7.m_quad = (__m128)baseA->m_translation;
    m_frictionAxis = (unsigned __int8)atom->m_frictionAxis;
    m_storage = in->m_bodyB.m_storage;
    v33 = in->m_virtMassFactor.m_storage;
    v10 = *(&baseB->m_rotation.m_col0.m_quad + m_frictionAxis);
    v11 = in->m_bodyA.m_storage;
    v12 = out->m_jacobianSchemas.m_storage;
    v13 = out->m_constraintRuntime.m_storage;
    v14 = _mm_shuffle_ps(v10, v10, 201);
    *(__m128 *)v12 = v10;
    v15 = _mm_sub_ps(v7.m_quad, v11->m_scratch3.m_quad);
    v16 = _mm_sub_ps(v7.m_quad, m_storage->m_scratch3.m_quad);
    v17 = _mm_sub_ps(_mm_mul_ps(v14, v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v10));
    v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v10), _mm_mul_ps(v14, v16));
    v19 = _mm_shuffle_ps(v17, v17, 201);
    v20 = _mm_shuffle_ps(v18, v18, 201);
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v11->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v11->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v11->m_scratch2.m_quad));
    *(__m128 *)&v12[16] = v21;
    v22 = v21;
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), m_storage->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), m_storage->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), m_storage->m_scratch2.m_quad));
    *(__m128 *)&v12[32] = v23;
    m_quad = m_storage->m_invMasses.m_quad;
    v25 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v23, v23), m_quad),
            _mm_mul_ps(_mm_mul_ps(v21, v21), v11->m_invMasses.m_quad));
    v26 = _mm_shuffle_ps(
            v25,
            _mm_unpackhi_ps(v25, _mm_max_ps(_mm_add_ps(m_quad, v11->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27);
    v29 = _mm_rcp_ps(v28);
    *(__m128 *)&v12[32] = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v28), 196);
    *(__m128 *)&v12[16] = _mm_shuffle_ps(
                            v22,
                            _mm_unpackhi_ps(
                              v22,
                              _mm_mul_ps(
                                _mm_shuffle_ps((__m128)LODWORD(v33), (__m128)LODWORD(v33), 0),
                                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v28)), v29))),
                            196);
    *(__m128 *)v12 = _mm_shuffle_ps(
                       *(__m128 *)v12,
                       _mm_unpackhi_ps(
                         *(__m128 *)v12,
                         _mm_mul_ps(
                           _mm_shuffle_ps(
                             (__m128)LODWORD(in->m_rhsFactor.m_storage),
                             (__m128)LODWORD(in->m_rhsFactor.m_storage),
                             0),
                           _mm_shuffle_ps((__m128)*((unsigned int *)v13 + 1), (__m128)*((unsigned int *)v13 + 1), 0))),
                       196);
    v30 = (float *)out->m_jacobianSchemas.m_storage;
    out->m_jacobianSchemas.m_storage += 64;
    v31 = m_maxFrictionForce * in->m_microStepDeltaTime.m_storage;
    *v30 = *v30 + 0.00000011920929;
    v30[12] = v31;
    *(_BYTE *)v30 = 9;
  }
  else
  {
    v32 = out->m_jacobianSchemas.m_storage + 16;
    v32[-12] = (hkpJacobianSchema)2;
    *(float *)&v32[-16] = *(float *)&v32[-16] + 0.00000011920929;
    v32[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v32;
  }
}

// File Line: 1292
// RVA: 0xDD6EC0
void __fastcall JacobianBuilder::buildJacobianFromWheelFrictionAtom_hkpConstraintQueryIn_(
        hkpWheelFrictionConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *m_storage; // r10
  hkpVelocityAccumulator *v7; // r9
  hkVector4f v8; // xmm5
  __m128 m_quad; // xmm7
  __m128 v10; // xmm9
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm15
  __m128 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm4
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  __m128 v41; // xmm4
  __m128 v42; // xmm7
  __m128 v43; // xmm4
  __m128 v44; // xmm7
  __m128 v45; // xmm5
  __m128 v46; // xmm6
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm8
  hkpJacobianSchema *v50; // rax
  __m128 v51; // [rsp+10h] [rbp-C8h]
  __m128 v52; // [rsp+20h] [rbp-B8h]
  float v53; // [rsp+E0h] [rbp+8h]
  float v54; // [rsp+E0h] [rbp+8h]

  if ( atom->m_isEnabled && atom->m_maxFrictionForce > 0.0 )
  {
    m_storage = in->m_bodyA.m_storage;
    v7 = in->m_bodyB.m_storage;
    v8.m_quad = (__m128)baseA->m_translation;
    v53 = in->m_virtMassFactor.m_storage;
    m_quad = v7->m_invMasses.m_quad;
    v10 = m_storage->m_invMasses.m_quad;
    v11 = *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_forwardAxis);
    v52 = _mm_sub_ps(v8.m_quad, v7->m_scratch3.m_quad);
    v51 = _mm_sub_ps(v8.m_quad, m_storage->m_scratch3.m_quad);
    v12 = _mm_shuffle_ps(v11, v11, 201);
    v13 = *(&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_sideAxis);
    v14 = (__m128 *)out->m_jacobianSchemas.m_storage;
    v15 = _mm_sub_ps(_mm_mul_ps(v51, v12), _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v11));
    v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v11), _mm_mul_ps(v12, v52));
    *v14 = v11;
    v17 = _mm_shuffle_ps(v15, v15, 201);
    v18 = _mm_shuffle_ps(v16, v16, 201);
    v19 = _mm_max_ps(_mm_add_ps(v10, m_quad), (__m128)xmmword_141A712D0);
    v20 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), m_storage->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), m_storage->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), m_storage->m_scratch2.m_quad));
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v7->m_scratch2.m_quad));
    v22 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v20, v20), v10), _mm_mul_ps(_mm_mul_ps(v21, v21), m_quad));
    v23 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, v19), 196);
    v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
    v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24);
    v14[2] = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v25), 196);
    v26 = _mm_rcp_ps(v25);
    v27 = _mm_unpackhi_ps(
            v20,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(v53), (__m128)LODWORD(v53), 0),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26)));
    v28 = _mm_shuffle_ps(v13, v13, 201);
    v14[1] = _mm_shuffle_ps(v20, v27, 196);
    v20.m128_f32[0] = in->m_frictionRhsFactor.m_storage * 0.0;
    v54 = in->m_virtMassFactor.m_storage;
    v14->m128_i32[3] = v20.m128_i32[0];
    v14[3] = v13;
    v29 = _mm_sub_ps(_mm_mul_ps(v51, v28), _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v13));
    v30 = _mm_shuffle_ps(v29, v29, 201);
    v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v13), _mm_mul_ps(v52, v28));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), m_storage->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), m_storage->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), m_storage->m_scratch2.m_quad));
    v34 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v7->m_scratch2.m_quad));
    v35 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v34, v34), m_quad), _mm_mul_ps(_mm_mul_ps(v33, v33), v10));
    v36 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v19), 196);
    v37 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 78), v36);
    v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37);
    v39 = _mm_rcp_ps(v38);
    v14[5] = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v38), 196);
    v37.m128_i32[0] = LODWORD(in->m_virtMassFactor.m_storage);
    v14[4] = _mm_shuffle_ps(
               v33,
               _mm_unpackhi_ps(
                 v33,
                 _mm_mul_ps(
                   _mm_shuffle_ps((__m128)LODWORD(v54), (__m128)LODWORD(v54), 0),
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39))),
               196);
    v14[3].m128_i32[3] = v20.m128_i32[0];
    v40 = _mm_mul_ps(v14[3], *v14);
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v14[5], v14[2]), m_quad), _mm_mul_ps(_mm_mul_ps(v14[4], v14[1]), v10)),
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), v40),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v40)));
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_shuffle_ps(v14[5], v14[5], 255);
    v44 = _mm_mul_ps(v42, _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0));
    v45 = v14[2];
    v46 = _mm_shuffle_ps(v45, v45, 255);
    v47 = _mm_sub_ps(_mm_mul_ps(v43, v46), _mm_mul_ps(v44, v44));
    v48 = _mm_rcp_ps(v47);
    v49 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v48, v47)), v48),
            _mm_shuffle_ps((__m128)v37.m128_u32[0], (__m128)v37.m128_u32[0], 0));
    v14[2] = _mm_shuffle_ps(v45, _mm_unpackhi_ps(v45, _mm_mul_ps(v49, v43)), 196);
    v14[5] = _mm_shuffle_ps(v14[5], _mm_unpackhi_ps(v14[5], _mm_mul_ps(v49, v46)), 196);
    v14[6].m128_u64[1] = (unsigned __int64)atom;
    v14 += 7;
    v14[-1].m128_f32[0] = (float)(0.0 - v44.m128_f32[0]) * v49.m128_f32[0];
    v37.m128_f32[0] = atom->m_maxFrictionForce * in->m_microStepDeltaTime.m_storage;
    out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v14;
    v14[-1].m128_i32[1] = v37.m128_i32[0];
    v14[-7].m128_f32[0] = v14[-7].m128_f32[0] + 0.00000011920929;
    v14[-7].m128_i8[0] = 43;
  }
  else
  {
    v50 = out->m_jacobianSchemas.m_storage + 16;
    v50[-12] = 0;
    *(float *)&v50[-16] = *(float *)&v50[-16] + 0.00000011920929;
    v50[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v50;
  }
}

// File Line: 1334
// RVA: 0xDD29B0
void __fastcall JacobianBuilder::hkPulleyConstraintBuildJacobian(
        hkpPulleyConstraintInfo *pulleyInput,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *m_storage; // r10
  hkpJacobianSchema *v4; // r9
  hkVector4f v5; // xmm7
  hkVector4f v6; // xmm10
  hkpVelocityAccumulator *v7; // rax
  hkVector4f v8; // xmm11
  __m128 v9; // xmm4
  __m128 v10; // xmm9
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 m_quad; // xmm9
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm8
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm7
  __m128 v37; // xmm10
  __m128 v38; // xmm7
  __m128 v39; // xmm10
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm7
  __m128 v45; // xmm1
  float v46; // xmm0_4
  float v47; // [rsp+70h] [rbp-78h]
  float v48; // [rsp+78h] [rbp-70h]
  float v49; // [rsp+7Ch] [rbp-6Ch]

  m_storage = in->m_bodyB.m_storage;
  v4 = out->m_jacobianSchemas.m_storage;
  v5.m_quad = (__m128)pulleyInput->m_positionB;
  v6.m_quad = (__m128)pulleyInput->m_pulleyPivotA;
  v7 = in->m_bodyA.m_storage;
  v8.m_quad = (__m128)pulleyInput->m_positionA;
  v9 = _mm_sub_ps(v5.m_quad, pulleyInput->m_pulleyPivotB.m_quad);
  v10 = _mm_sub_ps(v6.m_quad, pulleyInput->m_positionA.m_quad);
  v11 = _mm_mul_ps(v10, v10);
  if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
             + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) <= 0.00000011920929 )
  {
    m_quad = transform.m_quad;
  }
  else
  {
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    m_quad = _mm_mul_ps(
               v10,
               _mm_andnot_ps(
                 _mm_cmple_ps(v12, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                   _mm_mul_ps(*(__m128 *)_xmm, v13))));
  }
  v15 = _mm_mul_ps(v9, v9);
  if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
             + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) <= 0.00000011920929 )
  {
    v18 = _mm_xor_ps((__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), transform.m_quad);
  }
  else
  {
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rsqrt_ps(v16);
    v18 = _mm_mul_ps(
            v9,
            _mm_andnot_ps(
              _mm_cmple_ps(v16, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                _mm_mul_ps(*(__m128 *)_xmm, v17))));
  }
  v19 = _mm_sub_ps(v5.m_quad, m_storage->m_scratch3.m_quad);
  v49 = in->m_virtMassFactor.m_storage;
  v47 = pulleyInput->m_ropeLength.m_storage;
  v20 = _mm_shuffle_ps(
          (__m128)LODWORD(pulleyInput->m_leverageOnBodyB.m_storage),
          (__m128)LODWORD(pulleyInput->m_leverageOnBodyB.m_storage),
          0);
  v21 = _mm_sub_ps(v8.m_quad, v7->m_scratch3.m_quad);
  v22 = _mm_mul_ps(v20, v18);
  v48 = in->m_subStepInvDeltaTime.m_storage;
  *(__m128 *)&v4[16] = v22;
  v23 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v21),
          _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), m_quad));
  v24 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v22);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v19);
  v26 = _mm_shuffle_ps(v23, v23, 201);
  v27 = m_storage->m_invMasses.m_quad;
  v28 = _mm_sub_ps(v24, v25);
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v7->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v7->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v7->m_scratch2.m_quad));
  v30 = _mm_shuffle_ps(v28, v28, 201);
  v31 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), m_storage->m_scratch2.m_quad));
  v32 = v7->m_invMasses.m_quad;
  *(__m128 *)&v4[48] = v31;
  v33 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v31, v31), v27), _mm_mul_ps(_mm_mul_ps(v29, v29), v32));
  v34 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 255), _mm_mul_ps(v20, v20)), _mm_shuffle_ps(v32, v32, 255)),
            *(__m128 *)&epsilon),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170)));
  v35 = _mm_rcp_ps(v34);
  v36 = _mm_sub_ps(v5.m_quad, pulleyInput->m_pulleyPivotB.m_quad);
  out->m_jacobianSchemas.m_storage = v4 + 64;
  v37 = _mm_sub_ps(v6.m_quad, v8.m_quad);
  v38 = _mm_mul_ps(v36, v36);
  v39 = _mm_mul_ps(v37, v37);
  *(__m128 *)&v4[32] = _mm_shuffle_ps(
                         v29,
                         _mm_unpackhi_ps(
                           v29,
                           _mm_mul_ps(
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35),
                             _mm_shuffle_ps((__m128)LODWORD(v49), (__m128)LODWORD(v49), 0))),
                         196);
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v41 = _mm_rsqrt_ps(v40);
  v42 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)), _mm_mul_ps(v41, *(__m128 *)_xmm)),
          v40);
  v43 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v44 = _mm_andnot_ps(_mm_cmple_ps(v40, (__m128)0i64), v42);
  v45 = _mm_rsqrt_ps(v43);
  v46 = *(float *)v4 + 0.00000011920929;
  *(__m128 *)v4 = _mm_shuffle_ps(
                    m_quad,
                    _mm_unpackhi_ps(
                      m_quad,
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v43, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v43), v45)),
                                  _mm_mul_ps(v45, *(__m128 *)_xmm)),
                                v43)),
                            _mm_mul_ps(v20, v44)),
                          _mm_shuffle_ps((__m128)LODWORD(v47), (__m128)LODWORD(v47), 0)),
                        _mm_shuffle_ps((__m128)LODWORD(v48), (__m128)LODWORD(v48), 0))),
                    196);
  *(float *)v4 = v46;
  *v4 = (hkpJacobianSchema)11;
}

// File Line: 1384
// RVA: 0xDD2D90
void __fastcall JacobianBuilder::buildJacobianFromPulleyAtom(
        hkpPulleyConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm7
  hkVector4f v6; // xmm11
  hkpVelocityAccumulator *m_storage; // r9
  hkVector4f v8; // xmm12
  float m_ropeLength; // xmm13_4
  __m128 v10; // xmm9
  float m_leverageOnBodyB; // xmm14_4
  hkpJacobianSchema *v12; // rax
  hkpVelocityAccumulator *v13; // rcx
  __m128 v14; // xmm6
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 m_quad; // xmm10
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm0_4
  __m128 v25; // xmm8
  __m128 v26; // xmm1
  __m128 v27; // xmm7
  __m128 v28; // xmm11
  __m128 v29; // xmm2
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm5
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm4
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  __m128 v41; // xmm6
  __m128 v42; // xmm1
  __m128 v43; // xmm9
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm7
  __m128 v49; // xmm1
  hkpJacobianSchema *v50; // rcx
  float v51; // [rsp+7Ch] [rbp-9Ch]

  v5.m_quad = (__m128)baseA->m_translation;
  v6.m_quad = (__m128)baseB->m_translation;
  m_storage = in->m_bodyB.m_storage;
  v8.m_quad = (__m128)atom->m_fixedPivotBinWorld;
  m_ropeLength = atom->m_ropeLength;
  v10 = _mm_sub_ps(atom->m_fixedPivotAinWorld.m_quad, v5.m_quad);
  m_leverageOnBodyB = atom->m_leverageOnBodyB;
  v12 = out->m_jacobianSchemas.m_storage;
  v13 = in->m_bodyA.m_storage;
  v14 = _mm_sub_ps(v6.m_quad, v8.m_quad);
  v15 = _mm_mul_ps(v10, v10);
  if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
             + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) <= 0.00000011920929 )
  {
    m_quad = transform.m_quad;
  }
  else
  {
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rsqrt_ps(v16);
    m_quad = _mm_mul_ps(
               v10,
               _mm_andnot_ps(
                 _mm_cmple_ps(v16, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                   _mm_mul_ps(*(__m128 *)_xmm, v17))));
  }
  v19 = _mm_mul_ps(v14, v14);
  if ( (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
             + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) <= 0.00000011920929 )
  {
    v22 = _mm_xor_ps((__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), transform.m_quad);
  }
  else
  {
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_rsqrt_ps(v20);
    v22 = _mm_mul_ps(
            v14,
            _mm_andnot_ps(
              _mm_cmple_ps(v20, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                _mm_mul_ps(*(__m128 *)_xmm, v21))));
  }
  v23 = in->m_virtMassFactor.m_storage;
  v24 = in->m_subStepInvDeltaTime.m_storage;
  *(__m128 *)v12 = m_quad;
  v51 = v23;
  v25 = _mm_shuffle_ps((__m128)LODWORD(m_leverageOnBodyB), (__m128)LODWORD(m_leverageOnBodyB), 0);
  v26 = _mm_mul_ps(v25, v22);
  *(__m128 *)&v12[16] = v26;
  v27 = _mm_sub_ps(v5.m_quad, v13->m_scratch3.m_quad);
  v28 = _mm_sub_ps(v6.m_quad, m_storage->m_scratch3.m_quad);
  v29 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v27),
          _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), m_quad));
  v30 = _mm_shuffle_ps(v29, v29, 201);
  v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v28));
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v13->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v13->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v13->m_scratch2.m_quad));
  v33 = _mm_shuffle_ps(v31, v31, 201);
  *(__m128 *)&v12[32] = v32;
  v34 = v32;
  v35 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), m_storage->m_scratch2.m_quad));
  v36 = v32;
  *(__m128 *)&v12[48] = v35;
  v37 = m_storage->m_invMasses.m_quad;
  v38 = v13->m_invMasses.m_quad;
  v39 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v36, v36), v38), _mm_mul_ps(_mm_mul_ps(v35, v35), v37));
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), _mm_mul_ps(v25, v25)), _mm_shuffle_ps(v38, v38, 255)),
            *(__m128 *)&epsilon),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170)));
  v41 = _mm_mul_ps(v14, v14);
  v42 = _mm_rcp_ps(v40);
  v43 = _mm_mul_ps(v10, v10);
  *(__m128 *)&v12[32] = _mm_shuffle_ps(
                          v34,
                          _mm_unpackhi_ps(
                            v34,
                            _mm_mul_ps(
                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v40)), v42),
                              _mm_shuffle_ps((__m128)LODWORD(v51), (__m128)LODWORD(v51), 0))),
                          196);
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)), _mm_shuffle_ps(v41, v41, 170));
  v45 = _mm_rsqrt_ps(v44);
  v46 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)), _mm_mul_ps(v45, *(__m128 *)_xmm)),
          v44);
  v47 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)), _mm_shuffle_ps(v43, v43, 170));
  v48 = _mm_andnot_ps(_mm_cmple_ps(v44, (__m128)0i64), v46);
  v49 = _mm_rsqrt_ps(v47);
  *(__m128 *)v12 = _mm_shuffle_ps(
                     m_quad,
                     _mm_unpackhi_ps(
                       m_quad,
                       _mm_mul_ps(
                         _mm_sub_ps(
                           _mm_add_ps(
                             _mm_andnot_ps(
                               _mm_cmple_ps(v47, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v47), v49)),
                                   _mm_mul_ps(v49, *(__m128 *)_xmm)),
                                 v47)),
                             _mm_mul_ps(v25, v48)),
                           _mm_shuffle_ps((__m128)LODWORD(m_ropeLength), (__m128)LODWORD(m_ropeLength), 0)),
                         _mm_shuffle_ps((__m128)LODWORD(v24), (__m128)LODWORD(v24), 0))),
                     196);
  v50 = out->m_jacobianSchemas.m_storage;
  out->m_jacobianSchemas.m_storage += 64;
  *(float *)v50 = *(float *)v50 + 0.00000011920929;
  *v50 = (hkpJacobianSchema)11;
}

// File Line: 1398
// RVA: 0xDD31D0
void __fastcall JacobianBuilder::buildJacobianFromRackAndPinionAtom(
        hkpRackAndPinionConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *m_storage; // r8
  struct hkpConstraintRuntime *v7; // rax
  __m128 v8; // xmm8
  float *v9; // rbx
  float *v10; // r11
  unsigned int *v11; // r10
  hkVector4f v12; // xmm10
  hkVector4f v13; // xmm11
  hkVector4f v14; // xmm12
  hkVector4f v15; // xmm9
  __m128 v16; // xmm8
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  hkVector4f v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm7
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm6
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm6
  __m128 v35; // xmm13
  float v36; // xmm7_4
  float v37; // xmm2_4
  float m_pinionRadiusOrScrewPitch; // xmm0_4
  __m128i v39; // xmm6
  bool v40; // zf
  hkpVelocityAccumulator *v41; // rcx
  hkpVelocityAccumulator *v42; // rax
  __m128 v43; // xmm11
  __m128 v44; // xmm10
  __m128 v45; // xmm3
  float v46; // xmm6_4
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  float v49; // xmm6_4
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm5
  __m128 m_quad; // xmm2
  __m128 v57; // xmm4
  __m128 v58; // xmm3
  __m128 v59; // xmm3
  __m128 v60; // xmm0
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 m_storage_low; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm3
  __m128 v69; // xmm9
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm1
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm4
  __m128 v76; // xmm3
  __m128 v77; // xmm3
  __m128 v78; // xmm0
  __m128 v79; // xmm2
  __m128 v80; // xmm0
  __m128 v81; // xmm1
  __m128 v82; // xmm0
  float v83; // xmm7_4
  __m128 v84; // xmm3
  float v85; // xmm0_4
  float v86; // xmm0_4
  float v87; // [rsp+90h] [rbp+8h]
  float v88; // [rsp+A0h] [rbp+18h]
  float outa; // [rsp+B0h] [rbp+28h]

  m_storage = out->m_jacobianSchemas.m_storage;
  v7 = out->m_constraintRuntime.m_storage;
  v8 = 0i64;
  v9 = (float *)((char *)v7 + atom->m_memOffsetToInitialAngleOffset);
  v10 = (float *)((char *)v7 + atom->m_memOffsetToPrevAngle);
  v11 = (unsigned int *)((char *)v7 + atom->m_memOffsetToRevolutionCounter);
  out->m_jacobianSchemas.m_storage += 64;
  v12.m_quad = (__m128)baseA->m_translation;
  v13.m_quad = (__m128)baseB->m_translation;
  v14.m_quad = (__m128)baseA->m_rotation.m_col0;
  v15.m_quad = (__m128)baseB->m_rotation.m_col0;
  if ( atom->m_isScrew.m_bool )
  {
    v23 = _mm_mul_ps(v14.m_quad, v15.m_quad);
    if ( COERCE_FLOAT((unsigned int)(2
                                   * COERCE_INT(
                                       (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0]
                                             + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                                     + _mm_shuffle_ps(v23, v23, 170).m128_f32[0])) >> 1) < _mm_shuffle_ps(
                                                                                             (__m128)LODWORD(FLOAT_0_1),
                                                                                             (__m128)LODWORD(FLOAT_0_1),
                                                                                             0).m128_f32[0] )
      goto LABEL_3;
    v21.m_quad = (__m128)baseB->m_rotation.m_col1;
  }
  else
  {
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), v15.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 201), v14.m_quad));
    v17 = _mm_shuffle_ps(v16, v16, 201);
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    if ( v19.m128_f32[0] < 1.4210855e-14 )
    {
LABEL_3:
      out->m_jacobianSchemas.m_storage = m_storage;
      return;
    }
    v20 = _mm_rsqrt_ps(v19);
    v8 = _mm_mul_ps(
           v17,
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)), _mm_mul_ps(*(__m128 *)_xmm, v20)));
    v21.m_quad = v8;
    v22 = _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)LODWORD(atom->m_pinionRadiusOrScrewPitch),
              (__m128)LODWORD(atom->m_pinionRadiusOrScrewPitch),
              0),
            v8);
    v12.m_quad = _mm_add_ps(v12.m_quad, v22);
    v13.m_quad = _mm_add_ps(v13.m_quad, v22);
  }
  v24 = _mm_mul_ps(baseA->m_rotation.m_col1.m_quad, v21.m_quad);
  v25 = _mm_mul_ps(baseA->m_rotation.m_col2.m_quad, v21.m_quad);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v27 = _mm_rcp_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170)));
  v28 = _mm_mul_ps(v27, v26);
  v29 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v28), _mm_cmplt_ps(*(__m128 *)_xmm, v28));
  v30 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v28), v29), _mm_andnot_ps(v29, v28));
  v31 = _mm_mul_ps(v30, v30);
  v32 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v31, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v31, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v31, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v31, *(__m128 *)s3))),
          _mm_mul_ps(v30, *(__m128 *)t3));
  v33 = _mm_cmple_ps((__m128)0i64, v27);
  v34 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v30, *(__m128 *)_xmm), *(__m128 *)_xmm), v32), v29),
          _mm_andnot_ps(v29, v32));
  v35 = _mm_mul_ps(_mm_sub_ps(v13.m_quad, v12.m_quad), v15.m_quad);
  LODWORD(outa) = _mm_andnot_ps(v33, _mm_add_ps(_mm_or_ps(_mm_and_ps(v26, *(__m128 *)_xmm), *(__m128 *)_xmm), v34)).m128_u32[0] | v34.m128_i32[0] & v33.m128_i32[0];
  v36 = (float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
      + _mm_shuffle_ps(v35, v35, 170).m128_f32[0];
  if ( *v9 == 0.0 )
  {
    v37 = outa - (float)(v36 / atom->m_pinionRadiusOrScrewPitch);
    *v9 = v37;
    if ( v37 == 0.0 )
      v37 = FLOAT_1_1920929eN8;
    *v9 = v37;
    *v10 = outa;
  }
  if ( (float)(outa - *v10) > 3.1415927 )
    --*v11;
  if ( (float)(outa - *v10) < -3.1415927 )
    ++*v11;
  *v10 = outa;
  m_pinionRadiusOrScrewPitch = atom->m_pinionRadiusOrScrewPitch;
  v39 = _mm_cvtsi32_si128(*v11);
  v40 = atom->m_isScrew.m_bool == 0;
  v41 = in->m_bodyB.m_storage;
  v42 = in->m_bodyA.m_storage;
  *(hkVector4f *)m_storage = (hkVector4f)v15.m_quad;
  v43 = _mm_sub_ps(v13.m_quad, v41->m_scratch3.m_quad);
  v44 = _mm_sub_ps(v12.m_quad, v42->m_scratch3.m_quad);
  v45 = _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v15.m_quad);
  v46 = (float)((float)(_mm_cvtepi32_ps(v39).m128_f32[0] * 6.2831855) + (float)(outa - *v9))
      * m_pinionRadiusOrScrewPitch;
  if ( v40 )
  {
    v47 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v14.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), v8));
    v48 = _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v15.m_quad);
    v49 = v46
        * (float)((float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + _mm_shuffle_ps(v48, v48, 0).m128_f32[0])
                + _mm_shuffle_ps(v48, v48, 170).m128_f32[0]);
    v50 = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 201);
    v51 = _mm_sub_ps(v45, _mm_mul_ps(v50, v43));
    v52 = _mm_sub_ps(_mm_mul_ps(v50, v44), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v15.m_quad));
    v53 = _mm_shuffle_ps(v51, v51, 201);
    v54 = _mm_shuffle_ps(v52, v52, 201);
    v55 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v54, v54, 85), v42->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v42->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v54, v54, 170), v42->m_scratch2.m_quad));
    m_quad = v41->m_invMasses.m_quad;
    v57 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v53, v53, 85), v41->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v41->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v53, v53, 170), v41->m_scratch2.m_quad));
    v58 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v57, v57), m_quad),
            _mm_mul_ps(_mm_mul_ps(v55, v55), v42->m_invMasses.m_quad));
    v59 = _mm_shuffle_ps(
            v58,
            _mm_unpackhi_ps(v58, _mm_max_ps(_mm_add_ps(m_quad, v42->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v60 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 78), v59);
    v61 = _mm_shuffle_ps(
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            0);
    v62 = _mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60);
    v63 = _mm_rcp_ps(v62);
    *(__m128 *)&m_storage[32] = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, v62), 196);
    v64 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v63, v62)), v63);
    m_storage_low = (__m128)LODWORD(in->m_rhsFactor.m_storage);
    *(__m128 *)&m_storage[16] = _mm_shuffle_ps(v55, _mm_unpackhi_ps(v55, _mm_mul_ps(v61, v64)), 196);
  }
  else
  {
    v49 = v46 * 0.15915494;
    v87 = in->m_virtMassFactor.m_storage;
    v88 = in->m_rhsFactor.m_storage;
    v66 = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 201);
    v67 = _mm_sub_ps(_mm_mul_ps(v66, v44), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v15.m_quad));
    v68 = _mm_sub_ps(v45, _mm_mul_ps(v66, v43));
    v69 = _mm_mul_ps(
            v15.m_quad,
            _mm_shuffle_ps((__m128)LODWORD(m_pinionRadiusOrScrewPitch), (__m128)LODWORD(m_pinionRadiusOrScrewPitch), 0));
    v70 = _mm_add_ps(_mm_shuffle_ps(v67, v67, 201), v69);
    v71 = _mm_sub_ps(_mm_shuffle_ps(v68, v68, 201), v69);
    v72 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v70, v70, 85), v42->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), v42->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v70, v70, 170), v42->m_scratch2.m_quad));
    v73 = v41->m_invMasses.m_quad;
    *(__m128 *)&m_storage[16] = v72;
    v74 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v41->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), v41->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v71, v71, 170), v41->m_scratch2.m_quad));
    *(__m128 *)&m_storage[32] = v74;
    v75 = v74;
    v76 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v74, v74), v73),
            _mm_mul_ps(_mm_mul_ps(*(__m128 *)&m_storage[16], *(__m128 *)&m_storage[16]), v42->m_invMasses.m_quad));
    v77 = _mm_shuffle_ps(
            v76,
            _mm_unpackhi_ps(v76, _mm_max_ps(_mm_add_ps(v73, v42->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v78 = _mm_add_ps(_mm_shuffle_ps(v77, v77, 78), v77);
    v79 = _mm_add_ps(_mm_shuffle_ps(v78, v78, 177), v78);
    v80 = _mm_unpackhi_ps(v74, v79);
    v81 = _mm_rcp_ps(v79);
    *(__m128 *)&m_storage[32] = _mm_shuffle_ps(v75, v80, 196);
    v82 = _mm_unpackhi_ps(
            *(__m128 *)&m_storage[16],
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v81, v79)), v81),
              _mm_shuffle_ps((__m128)LODWORD(v87), (__m128)LODWORD(v87), 0)));
    m_storage_low = (__m128)LODWORD(v88);
    *(__m128 *)&m_storage[16] = _mm_shuffle_ps(*(__m128 *)&m_storage[16], v82, 196);
  }
  v83 = (float)(v36 - v49) * in->m_rhsFactor.m_storage;
  v84 = _mm_shuffle_ps(
          *(__m128 *)m_storage,
          _mm_unpackhi_ps(
            *(__m128 *)m_storage,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                _mm_shuffle_ps(v35, v35, 170)),
              _mm_shuffle_ps(m_storage_low, m_storage_low, 0))),
          196);
  v85 = in->m_damping.m_storage;
  *(float *)&m_storage[48] = in->m_tau.m_storage;
  *(float *)&m_storage[52] = v85;
  v86 = *(float *)m_storage;
  *(__m128 *)m_storage = v84;
  *(float *)&m_storage[12] = v83;
  *(float *)m_storage = v86 + 0.00000011920929;
  *m_storage = (hkpJacobianSchema)7;
}

// File Line: 1568
// RVA: 0xDD38B0
void __fastcall JacobianBuilder::buildJacobianFromCogWheelAtom(
        hkpCogWheelConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  struct hkpConstraintRuntime *m_storage; // rax
  hkpJacobianSchema *v7; // r8
  float *v8; // rbx
  float *v9; // r11
  int *v10; // r10
  hkVector4f v11; // xmm6
  hkVector4f v12; // xmm4
  hkVector4f v13; // xmm15
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm14
  __m128 v18; // xmm13
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm9
  __m128 v24; // xmm9
  __m128 v25; // xmm10
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm9
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm10
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm5
  __m128 v41; // xmm12
  __m128 v42; // xmm4
  __m128 v43; // xmm8
  __m128 v44; // xmm0
  __m128 v45; // xmm7
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm6
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm6
  float v52; // xmm0_4
  float v53; // xmm1_4
  __m128 v54; // xmm3
  float v55; // xmm8_4
  float v56; // xmm7_4
  __m128 v57; // xmm6
  __m128 v58; // xmm3
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm6
  hkpVelocityAccumulator *v62; // rax
  hkpVelocityAccumulator *v63; // rcx
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm11
  __m128 v68; // xmm1
  __m128 v69; // xmm6
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm4
  __m128 v74; // xmm5
  __m128 v75; // xmm1
  __m128 m_quad; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm4
  __m128 v79; // xmm3
  __m128 v80; // xmm3
  __m128 v81; // xmm0
  __m128 v82; // xmm12
  __m128 v83; // xmm1
  unsigned int v84; // xmm7_4
  __m128 v85; // xmm2
  __m128 v86; // xmm3
  __m128 v87; // xmm2
  hkVector4f v88; // [rsp+0h] [rbp-C8h]
  __m128 v89; // [rsp+10h] [rbp-B8h]
  hkpConstraintQueryOut *outa; // [rsp+F0h] [rbp+28h]
  float outb; // [rsp+F0h] [rbp+28h]

  m_storage = out->m_constraintRuntime.m_storage;
  v7 = out->m_jacobianSchemas.m_storage;
  v8 = (float *)((char *)m_storage + atom->m_memOffsetToInitialAngleOffset);
  v9 = (float *)((char *)m_storage + atom->m_memOffsetToPrevAngle);
  v10 = (int *)((char *)m_storage + atom->m_memOffsetToRevolutionCounter);
  out->m_jacobianSchemas.m_storage += 64;
  v11.m_quad = (__m128)baseA->m_translation;
  v12.m_quad = (__m128)baseB->m_rotation.m_col0;
  v13.m_quad = (__m128)baseA->m_rotation.m_col0;
  v14 = _mm_sub_ps(baseB->m_translation.m_quad, v11.m_quad);
  v88.m_quad = (__m128)baseB->m_rotation.m_col0;
  v15 = _mm_mul_ps(v14, v14);
  if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
             + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) >= 1.4210855e-14 )
  {
    v16 = _mm_shuffle_ps(v14, v14, 201);
    v17 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 201);
    v18 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 201);
    v19 = _mm_sub_ps(_mm_mul_ps(v14, v18), _mm_mul_ps(v16, v13.m_quad));
    v20 = _mm_sub_ps(_mm_mul_ps(v16, v12.m_quad), _mm_mul_ps(v14, v17));
    v21 = _mm_shuffle_ps(v19, v19, 201);
    v22 = _mm_shuffle_ps(v20, v20, 201);
    v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v13.m_quad), _mm_mul_ps(v21, v18));
    v24 = _mm_shuffle_ps(v23, v23, 201);
    v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v12.m_quad), _mm_mul_ps(v17, v22));
    v26 = _mm_shuffle_ps(v25, v25, 201);
    v27 = _mm_mul_ps(v24, v24);
    v28 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v29 = _mm_mul_ps(v26, v26);
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170));
    if ( v28.m128_f32[0] < 1.4210855e-14 || v30.m128_f32[0] < 1.4210855e-14 )
    {
      out->m_jacobianSchemas.m_storage = v7;
    }
    else
    {
      v31 = _mm_rsqrt_ps(v28);
      v32 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v28), v31)),
              _mm_mul_ps(v31, *(__m128 *)_xmm));
      v33 = _mm_rsqrt_ps(v30);
      v34 = _mm_mul_ps(v24, v32);
      v35 = _mm_mul_ps(_mm_mul_ps(v33, v30), v33);
      v36 = _mm_mul_ps(baseA->m_rotation.m_col2.m_quad, v34);
      v37 = _mm_mul_ps(v26, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v35), _mm_mul_ps(v33, *(__m128 *)_xmm)));
      v38 = _mm_mul_ps(baseA->m_rotation.m_col1.m_quad, v34);
      v39 = _mm_mul_ps(baseB->m_rotation.m_col1.m_quad, v37);
      v89 = _mm_add_ps(
              v11.m_quad,
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(atom->m_cogWheelRadiusA), (__m128)LODWORD(atom->m_cogWheelRadiusA), 0),
                v34));
      v40 = _mm_mul_ps(baseB->m_rotation.m_col2.m_quad, v37);
      v41 = _mm_add_ps(
              baseB->m_translation.m_quad,
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(atom->m_cogWheelRadiusB), (__m128)LODWORD(atom->m_cogWheelRadiusB), 0),
                v37));
      v42 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
      v43 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                  _mm_shuffle_ps(v38, v38, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                  _mm_shuffle_ps(v39, v39, 170))),
              v42);
      v44 = _mm_rcp_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                    _mm_shuffle_ps(v36, v36, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                    _mm_shuffle_ps(v40, v40, 170))),
                v42));
      v45 = _mm_cmple_ps((__m128)0i64, v44);
      v46 = _mm_mul_ps(v44, v43);
      v47 = _mm_or_ps(
              _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v46),
              _mm_cmplt_ps(*(__m128 *)_xmm, v46));
      v48 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v46), v47), _mm_andnot_ps(v47, v46));
      v49 = _mm_mul_ps(v48, v48);
      v50 = _mm_mul_ps(
              _mm_rcp_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_rcp_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_rcp_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v49, *(__m128 *)s0)), *(__m128 *)t0),
                              _mm_add_ps(v49, *(__m128 *)s1))),
                          *(__m128 *)t1),
                        _mm_add_ps(v49, *(__m128 *)s2))),
                    *(__m128 *)t2),
                  _mm_add_ps(v49, *(__m128 *)s3))),
              _mm_mul_ps(v48, *(__m128 *)t3));
      v51 = _mm_or_ps(
              _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v48, *(__m128 *)_xmm), *(__m128 *)_xmm), v50), v47),
              _mm_andnot_ps(v47, v50));
      outa = (hkpConstraintQueryOut *)(_mm_andnot_ps(
                                         v45,
                                         _mm_add_ps(_mm_or_ps(_mm_and_ps(v43, *(__m128 *)_xmm), *(__m128 *)_xmm), v51)).m128_u64[0] | v51.m128_u64[0] & v45.m128_u64[0]);
      if ( *v8 == 0.0 )
      {
        v52 = FLOAT_1_1920929eN8;
        if ( *(float *)&outa == 0.0 )
          v53 = FLOAT_1_1920929eN8;
        else
          v53 = *(float *)&outa;
        *v8 = v53;
        if ( *((float *)&outa + 1) != 0.0 )
          v52 = *((float *)&outa + 1);
        v8[1] = v52;
        *(_QWORD *)v9 = outa;
      }
      if ( (float)(*(float *)&outa - *v9) > 3.1415927 )
        --*v10;
      if ( (float)(*(float *)&outa - *v9) < -3.1415927 )
        ++*v10;
      if ( (float)(*((float *)&outa + 1) - v9[1]) > 3.1415927 )
        --v10[1];
      if ( (float)(*((float *)&outa + 1) - v9[1]) < -3.1415927 )
        ++v10[1];
      *(_QWORD *)v9 = outa;
      v54 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v88.m_quad), _mm_mul_ps(v17, v37));
      v55 = (float)((float)((float)*v10 * 6.2831855) + (float)(*(float *)&outa - *v8)) * atom->m_cogWheelRadiusA;
      v56 = (float)((float)(*((float *)&outa + 1) - v8[1]) + (float)((float)v10[1] * 6.2831855))
          * atom->m_cogWheelRadiusB;
      v57 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v13.m_quad), _mm_mul_ps(v18, v34));
      v58 = _mm_shuffle_ps(v54, v54, 201);
      v59 = _mm_shuffle_ps(v57, v57, 201);
      v60 = _mm_mul_ps(v58, v59);
      if ( (float)((float)(_mm_shuffle_ps(v60, v60, 85).m128_f32[0] + _mm_shuffle_ps(v60, v60, 0).m128_f32[0])
                 + _mm_shuffle_ps(v60, v60, 170).m128_f32[0]) > 0.0 )
      {
        v56 = v56 * -1.0;
        v61 = _mm_add_ps(v59, v58);
      }
      else
      {
        v61 = _mm_sub_ps(v59, v58);
      }
      v62 = in->m_bodyA.m_storage;
      v63 = in->m_bodyB.m_storage;
      v64 = _mm_mul_ps(v61, v61);
      v65 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
              _mm_shuffle_ps(v64, v64, 170));
      v66 = _mm_rsqrt_ps(v65);
      v67 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v66, v65), v66)),
              _mm_mul_ps(v66, *(__m128 *)_xmm));
      outb = in->m_virtMassFactor.m_storage;
      v68 = _mm_sub_ps(v89, v62->m_scratch3.m_quad);
      v69 = _mm_mul_ps(v61, _mm_andnot_ps(_mm_cmple_ps(v65, (__m128)0i64), v67));
      v70 = _mm_sub_ps(v41, v63->m_scratch3.m_quad);
      *(__m128 *)v7 = v69;
      v71 = _mm_shuffle_ps(v69, v69, 201);
      v72 = _mm_sub_ps(_mm_mul_ps(v71, v68), _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v69));
      v73 = _mm_shuffle_ps(v72, v72, 201);
      v74 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), v62->m_scratch1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), v62->m_scratch0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), v62->m_scratch2.m_quad));
      v75 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v69), _mm_mul_ps(v71, v70));
      m_quad = v63->m_invMasses.m_quad;
      v77 = _mm_shuffle_ps(v75, v75, 201);
      v78 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v77, v77, 85), v63->m_scratch1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v63->m_scratch0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v77, v77, 170), v63->m_scratch2.m_quad));
      v79 = _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(v78, v78), m_quad),
              _mm_mul_ps(_mm_mul_ps(v74, v74), v62->m_invMasses.m_quad));
      v80 = _mm_shuffle_ps(
              v79,
              _mm_unpackhi_ps(v79, _mm_max_ps(_mm_add_ps(m_quad, v62->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
              196);
      v81 = _mm_add_ps(_mm_shuffle_ps(v80, v80, 78), v80);
      *(float *)&v62 = in->m_tau.m_storage;
      v82 = _mm_mul_ps(_mm_sub_ps(v41, v89), v69);
      v83 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 177), v81);
      v84 = COERCE_UNSIGNED_INT((float)(v56 + v55) * in->m_rhsFactor.m_storage) ^ _xmm[0];
      v85 = _mm_rcp_ps(v83);
      *(__m128 *)&v7[32] = _mm_shuffle_ps(v78, _mm_unpackhi_ps(v78, v83), 196);
      v86 = _mm_shuffle_ps((__m128)LODWORD(in->m_rhsFactor.m_storage), (__m128)LODWORD(in->m_rhsFactor.m_storage), 0);
      *(__m128 *)&v7[16] = _mm_shuffle_ps(
                             v74,
                             _mm_unpackhi_ps(
                               v74,
                               _mm_mul_ps(
                                 _mm_shuffle_ps((__m128)LODWORD(outb), (__m128)LODWORD(outb), 0),
                                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v85, v83)), v85))),
                             196);
      v87 = _mm_shuffle_ps(
              *(__m128 *)v7,
              _mm_unpackhi_ps(
                *(__m128 *)v7,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                    _mm_shuffle_ps(v82, v82, 170)),
                  v86)),
              196);
      v81.m128_i32[0] = LODWORD(in->m_damping.m_storage);
      *(_DWORD *)&v7[48] = (_DWORD)v62;
      *(_DWORD *)&v7[52] = v81.m128_i32[0];
      v81.m128_i32[0] = *(_DWORD *)v7;
      *(__m128 *)v7 = v87;
      *(_DWORD *)&v7[12] = v84;
      *(float *)v7 = v81.m128_f32[0] + 0.00000011920929;
      *v7 = (hkpJacobianSchema)7;
    }
  }
  else
  {
    out->m_jacobianSchemas.m_storage = v7;
  }
}

// File Line: 1798
// RVA: 0xDD3FE0
void __fastcall JacobianBuilder::_hkpBeginConstraints(
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out,
        hkpSolverResults *sr,
        hkpJacobianSchema solverResultStriding)
{
  hkpJacobianSchema *m_storage; // rbx
  unsigned int v5; // r10d
  hkpConstraintInstance *v6; // r11
  float v7; // xmm0_4

  m_storage = out->m_jacobianSchemas.m_storage;
  v5 = in->m_accumulatorBIndex.m_storage;
  v6 = in->m_constraintInstance.m_storage;
  v7 = *(float *)out->m_jacobianSchemas.m_storage;
  *(_WORD *)&m_storage[4] = in->m_accumulatorAIndex.m_storage;
  *(float *)m_storage = v7 + 0.00000011920929;
  *(_WORD *)&m_storage[6] = v5;
  *(_QWORD *)&m_storage[8] = sr;
  *m_storage = (hkpJacobianSchema)1;
  m_storage[1] = solverResultStriding;
  *(_QWORD *)&m_storage[16] = v6;
  out->m_jacobianSchemas.m_storage = m_storage + 32;
}

