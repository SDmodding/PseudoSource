// File Line: 62
// RVA: 0xDD0760
void __fastcall JacobianBuilder::_hkBallSocketConstraintComputeStabilizedRhs(hkpVelocityAccumulator *accuA, hkpVelocityAccumulator *accuB, hkVector4f *posA, hkVector4f *posB, float rhsFactor, float stabilizationFactor, hkVector4f *errorOut)
{
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  hkVector4f v9; // xmm9
  hkVector4f v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm8
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm10
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  hkVector4f v19; // xmm3
  __m128 v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  hkVector4f v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm0

  v7 = _mm_shuffle_ps(
         (__m128)COERCE_UNSIGNED_INT(rhsFactor * stabilizationFactor),
         (__m128)COERCE_UNSIGNED_INT(rhsFactor * stabilizationFactor),
         0);
  v8 = _mm_rcp_ps(v7);
  v9.m_quad = _mm_sub_ps(posB->m_quad, posA->m_quad);
  *errorOut = (hkVector4f)v9.m_quad;
  v10.m_quad = (__m128)accuA->m_scratch2;
  v11 = _mm_mul_ps(v8, v7);
  v12 = _mm_sub_ps(posB->m_quad, accuB->m_scratch3.m_quad);
  v13 = _mm_sub_ps(posA->m_quad, accuA->m_scratch3.m_quad);
  v14 = _mm_unpacklo_ps(accuA->m_scratch0.m_quad, accuA->m_scratch1.m_quad);
  v15 = _mm_shuffle_ps(_mm_unpackhi_ps(accuA->m_scratch0.m_quad, accuA->m_scratch1.m_quad), v10.m_quad, 228);
  v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v11), v8);
  v17 = _mm_movelh_ps(v14, v10.m_quad);
  v18 = _mm_shuffle_ps(_mm_movehl_ps(v17, v14), v10.m_quad, 212);
  v19.m_quad = (__m128)accuB->m_scratch2;
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(accuA->m_angularVel.m_quad, accuA->m_angularVel.m_quad, 85), v18),
            _mm_mul_ps(_mm_shuffle_ps(accuA->m_angularVel.m_quad, accuA->m_angularVel.m_quad, 0), v17)),
          _mm_mul_ps(_mm_shuffle_ps(accuA->m_angularVel.m_quad, accuA->m_angularVel.m_quad, 170), v15));
  v21 = _mm_unpacklo_ps(accuB->m_scratch0.m_quad, accuB->m_scratch1.m_quad);
  v22 = _mm_movelh_ps(v21, v19.m_quad);
  v23 = _mm_movehl_ps(v22, v21);
  v24.m_quad = (__m128)accuB->m_angularVel;
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v24.m_quad, v24.m_quad, 85), _mm_shuffle_ps(v23, v19.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(accuB->m_angularVel.m_quad, v24.m_quad, 0), v22)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(accuB->m_scratch0.m_quad, accuB->m_scratch1.m_quad), v19.m_quad, 228),
            _mm_shuffle_ps(v24.m_quad, v24.m_quad, 170)));
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v20));
  v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v25));
  errorOut->m_quad = _mm_sub_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v16), v9.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v16));
}

// File Line: 87
// RVA: 0xDD08E0
void __fastcall JacobianBuilder::_hkBallSocketConstraintBuildJacobian(hkVector4f *posA, hkVector4f *posB, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out, float maxImpulse, float stabilizationFactor)
{
  hkpVelocityAccumulator *v6; // r11
  hkpVelocityAccumulator *v7; // rbx
  __m128 *v8; // r10
  __m128 v9; // xmm3
  hkVector4f *v10; // rsi
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm8
  __m128 v15; // xmm11
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // ST00_16
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm5
  __m128 v28; // xmm0
  __m128 v29; // xmm9
  hkpViolatedConstraintArray *v30; // rcx
  __m128 v31; // xmm12
  __m128 v32; // xmm12
  __m128 v33; // xmm2
  unsigned __int32 v34; // eax
  hkVector4f *v35; // rcx
  __m128 *v36; // rax
  __m128 v37; // xmm7
  __m128 v38; // xmm8
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm3
  __m128 v50; // xmm3
  __m128 v51; // xmm0
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm2
  __m128 v56; // xmm8
  __m128 v57; // xmm4
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  float v60; // [rsp+A0h] [rbp+8h]

  v6 = in->m_bodyA.m_storage;
  v7 = in->m_bodyB.m_storage;
  v8 = (__m128 *)out->m_jacobianSchemas.m_storage;
  v9 = v6->m_scratch2.m_quad;
  v10 = posA;
  v11 = _mm_sub_ps(posA->m_quad, v6->m_scratch3.m_quad);
  v12 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(stabilizationFactor * in->m_rhsFactor.m_storage),
          (__m128)COERCE_UNSIGNED_INT(stabilizationFactor * in->m_rhsFactor.m_storage),
          0);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(posB->m_quad, v7->m_scratch3.m_quad);
  v15 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v13));
  v16 = _mm_unpacklo_ps(v6->m_scratch0.m_quad, v6->m_scratch1.m_quad);
  v17 = _mm_shuffle_ps(_mm_unpackhi_ps(v6->m_scratch0.m_quad, v6->m_scratch1.m_quad), v9, 228);
  v18 = _mm_movelh_ps(v16, v9);
  v19 = _mm_mul_ps(v15, v13);
  v20 = _mm_shuffle_ps(_mm_movehl_ps(v18, v16), v9, 212);
  v21 = v7->m_scratch2.m_quad;
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v6->m_angularVel.m_quad, v6->m_angularVel.m_quad, 85), v20),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_angularVel.m_quad, v6->m_angularVel.m_quad, 0), v18)),
          _mm_mul_ps(v17, _mm_shuffle_ps(v6->m_angularVel.m_quad, v6->m_angularVel.m_quad, 170)));
  v23 = _mm_unpacklo_ps(v7->m_scratch0.m_quad, v7->m_scratch1.m_quad);
  v24 = _mm_movelh_ps(v23, v21);
  v25 = _mm_movehl_ps(v24, v23);
  v26 = v7->m_angularVel.m_quad;
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v25, v21, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v7->m_angularVel.m_quad, v26, 0), v24)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(v7->m_scratch0.m_quad, v7->m_scratch1.m_quad), v21, 228),
            _mm_shuffle_ps(v26, v26, 170)));
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v22));
  v29 = _mm_sub_ps(posB->m_quad, posA->m_quad);
  v30 = in->m_violatedConstraints.m_storage;
  v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v27));
  v32 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v19), v29),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v19));
  if ( v30 )
  {
    v33 = _mm_mul_ps(v32, v32);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170))) > in->m_maxConstraintViolationSqrd.m_real.m128_f32[0] )
    {
      v34 = _InterlockedExchangeAdd((volatile signed __int32 *)v30, 1u);
      if ( v34 < 0x80 )
        in->m_violatedConstraints.m_storage->m_constraints[v34] = in->m_constraintInstance.m_storage;
    }
  }
  v35 = &transform;
  v36 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
  do
  {
    v37 = v35->m_quad;
    v60 = in->m_virtMassFactor.m_storage;
    v38 = _mm_sub_ps(posB->m_quad, v10->m_quad);
    v39 = _mm_shuffle_ps(v37, v37, 201);
    v40 = _mm_sub_ps(v10->m_quad, v6->m_scratch3.m_quad);
    v41 = _mm_sub_ps(posB->m_quad, v7->m_scratch3.m_quad);
    *v8 = v35->m_quad;
    v42 = _mm_sub_ps(_mm_mul_ps(v40, v39), _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v37));
    v43 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v37), _mm_mul_ps(v41, v39));
    v44 = v7->m_invMasses.m_quad;
    v45 = _mm_shuffle_ps(v43, v43, 201);
    v46 = _mm_shuffle_ps(v42, v42, 201);
    v47 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v6->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v6->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v6->m_scratch2.m_quad));
    v48 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v7->m_scratch2.m_quad));
    v49 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v47, v47), v6->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v48, v48), v44));
    v50 = _mm_shuffle_ps(
            v49,
            _mm_unpackhi_ps(v49, _mm_max_ps(_mm_add_ps(v44, v6->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 78), v50);
    v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 177), v51);
    v53 = _mm_rcp_ps(v52);
    v8[2] = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v52), 196);
    v54 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v53, v52)), v53);
    v55 = (__m128)LODWORD(in->m_rhsFactor.m_storage);
    v8[1] = _mm_shuffle_ps(
              v47,
              _mm_unpackhi_ps(v47, _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v60), (__m128)LODWORD(v60), 0), v54)),
              196);
    v56 = _mm_mul_ps(v38, v37);
    v57 = _mm_shuffle_ps(
            *v8,
            _mm_unpackhi_ps(
              *v8,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170)),
                _mm_shuffle_ps(v55, v55, 0))),
            196);
    v58 = _mm_and_ps(v32, *v36);
    v59 = _mm_or_ps(_mm_shuffle_ps(v58, v58, 78), v58);
    *v8 = _mm_shuffle_ps(
            v57,
            _mm_unpackhi_ps(
              v57,
              _mm_mul_ps(
                _mm_or_ps(_mm_shuffle_ps(v59, v59, 177), v59),
                _mm_shuffle_ps(
                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                  0))),
            196);
    if ( maxImpulse == 3.40282e38 )
    {
      *(float *)v8->m128_u64 = *(float *)v8->m128_u64 + 0.00000011920929;
      LOBYTE(v8->m128_u64[0]) = 5;
    }
    else
    {
      v8[2].m128_f32[3] = maxImpulse;
      *(float *)v8->m128_u64 = *(float *)v8->m128_u64 + 0.00000011920929;
      LOBYTE(v8->m128_u64[0]) = 6;
    }
    ++v36;
    v8 += 3;
    ++v35;
  }
  while ( (signed __int64)v36 < (signed __int64)&xmmword_141687F30 );
  out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v8;
}

// File Line: 150
// RVA: 0xDD0D40
void __fastcall JacobianBuilder::_hk1dAngularVelocityMotorBeginJacobian(hkVector4f *directionOfConstraint, hkpConstraintQueryIn *in, hkp2AngJacobian *jac, hkp1dBilateralConstraintStatus *statusOut)
{
  hkpVelocityAccumulator *v4; // rax
  hkpVelocityAccumulator *v5; // r10
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm2

  v4 = in->m_bodyB.m_storage;
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
           _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v4->m_scratch1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v4->m_scratch0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), v4->m_scratch2.m_quad));
  v9 = _mm_mul_ps(_mm_mul_ps(v7, v7), v5->m_invMasses.m_quad);
  jac->m_angular[1].m_quad = v8;
  v10 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v8, v8), v4->m_invMasses.m_quad), v9);
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
void __fastcall JacobianBuilder::hkSkipSolverResults(char numSolverResultsToSkip, hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v2; // rax

  v2 = out->m_jacobianSchemas.m_storage + 16;
  v2[-12] = (hkpJacobianSchema)numSolverResultsToSkip;
  *(float *)&v2[-16] = *(float *)&v2[-16] + 0.00000011920929;
  v2[-16] = (hkpJacobianSchema)3;
  out->m_jacobianSchemas.m_storage = v2;
}

// File Line: 186
// RVA: 0xDD0E70
void __fastcall JacobianBuilder::hkSkipSolverResults_0(int numSolverResultsToSkip, hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v2; // rax

  v2 = out->m_jacobianSchemas.m_storage + 16;
  v2[-12] = (hkpJacobianSchema)numSolverResultsToSkip;
  *(float *)&v2[-16] = *(float *)&v2[-16] + 0.00000011920929;
  v2[-16] = (hkpJacobianSchema)3;
  out->m_jacobianSchemas.m_storage = v2;
}

// File Line: 193
// RVA: 0xDD0EA0
void __fastcall JacobianBuilder::buildJacobianFromStiffSpringAtom(hkpStiffSpringConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkVector4f *vLocalArmA, hkVector4f *vLocalArmB, hkSimdFloat32 *maxAngularImpulse, hkSimdFloat32 *maxLinearImpulse, hkpConstraintQueryOut *out)
{
  __m128 *v9; // r8
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
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm1

  v9 = (__m128 *)out->m_jacobianSchemas.m_storage;
  v10 = _mm_mul_ps(vLocalArmA->m_quad, vLocalArmA->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = _mm_andnot_ps(
          _mm_cmpleps(v11, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
              _mm_mul_ps(*(__m128 *)_xmm, v12)),
            v11));
  v14 = _mm_mul_ps(vLocalArmB->m_quad, vLocalArmB->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(*(__m128 *)_xmm, v16);
  v18 = _mm_cmpltps(*(__m128 *)&epsilon, v13);
  v19 = _mm_mul_ps(_mm_mul_ps(v16, v15), v16);
  v20 = _mm_rcp_ps(v13);
  v21 = _mm_andnot_ps(_mm_cmpleps(v15, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v19), v17), v15));
  v22 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v13)), v20);
  v23 = _mm_rcp_ps(v21);
  v24 = _mm_cmpltps(*(__m128 *)&epsilon, v21);
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
  v9[1] = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v13), 196);
  v30 = (__m128)LODWORD(in->m_tau.m_storage);
  v9[2] = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, v21), 196);
  v31 = _mm_shuffle_ps(*v9, _mm_unpackhi_ps(*v9, _mm_mul_ps(v29, _mm_shuffle_ps(v30, v30, 0))), 196);
  v32 = (__m128)LODWORD(atom->m_length);
  out->m_jacobianSchemas.m_storage = v27;
  v33 = _mm_shuffle_ps(_mm_unpacklo_ps(v31, _mm_shuffle_ps(v32, v32, 0)), v31, 228);
  *v9 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v28), 180);
  *(float *)v9->m128_u64 = *(float *)v9->m128_u64 + 0.00000011920929;
  LOBYTE(v9->m128_u64[0]) = 18;
}

// File Line: 233
// RVA: 0xDD10C0
void __fastcall JacobianBuilder::setLocalTransform(hkTransformf *baseIn, hkTransformf *transform, hkTransformf *baseOut)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm5
  signed __int64 v6; // r9
  __m128 *v7; // rax
  __m128 v8; // xmm1

  v3.m_quad = (__m128)transform->m_rotation.m_col0;
  v4.m_quad = (__m128)transform->m_rotation.m_col1;
  v5.m_quad = (__m128)transform->m_rotation.m_col2;
  v6 = 3i64;
  v7 = &baseIn->m_translation.m_quad;
  do
  {
    v8 = *v7;
    --v7;
    --v6;
    *(__m128 *)((char *)v7 + (char *)baseOut - (char *)baseIn + 16) = _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_shuffle_ps(v8, v8, 85),
                                                                            v4.m_quad),
                                                                          _mm_mul_ps(
                                                                            _mm_shuffle_ps(v8, v8, 0),
                                                                            v3.m_quad)),
                                                                        _mm_mul_ps(
                                                                          _mm_shuffle_ps(v8, v8, 170),
                                                                          v5.m_quad));
  }
  while ( v6 >= 0 );
  baseOut->m_translation.m_quad = _mm_add_ps(transform->m_translation.m_quad, baseOut->m_translation.m_quad);
}

// File Line: 240
// RVA: 0xDD1130
void __fastcall JacobianBuilder::setLocalTransformsFromAtom(hkpSetLocalTransformsConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB)
{
  hkTransformf *v4; // rbx
  hkTransformf *v5; // rsi
  signed __int64 v6; // r10
  hkTransformf *v7; // rax
  hkTransformf *v8; // r11
  hkpSetLocalTransformsConstraintAtom *v9; // rdi
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  signed __int64 v13; // r9
  __m128 *v14; // r8
  signed __int64 v15; // rax
  __m128 v16; // xmm1
  __m128 *v17; // rcx
  hkTransformf *v18; // rdx
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm1

  v4 = in->m_transformA.m_storage;
  v5 = baseA;
  v6 = 3i64;
  v7 = baseA;
  v8 = baseB;
  v9 = atom;
  v10 = v4->m_rotation.m_col0.m_quad;
  v11 = v4->m_rotation.m_col1.m_quad;
  v12 = v4->m_rotation.m_col2.m_quad;
  v13 = 3i64;
  v14 = &atom->m_transformA.m_translation.m_quad;
  v15 = (char *)v7 - (char *)atom;
  do
  {
    v16 = *v14;
    --v14;
    --v13;
    *(__m128 *)((char *)v14 + v15) = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v11),
                                         _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v10)),
                                       _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12));
  }
  while ( v13 >= 0 );
  v17 = &atom->m_transformB.m_translation.m_quad;
  v5->m_translation.m_quad = _mm_add_ps(v4->m_translation.m_quad, v5->m_translation.m_quad);
  v18 = in->m_transformB.m_storage;
  v19 = v18->m_rotation.m_col0.m_quad;
  v20 = v18->m_rotation.m_col1.m_quad;
  v21 = v18->m_rotation.m_col2.m_quad;
  do
  {
    v22 = *v17;
    --v17;
    --v6;
    *(__m128 *)((char *)v17 + (char *)v8 - (char *)v9 - 64) = _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v20),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v19)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v21));
  }
  while ( v6 >= 0 );
  v8->m_translation.m_quad = _mm_add_ps(v18->m_translation.m_quad, v8->m_translation.m_quad);
}

// File Line: 247
// RVA: 0xDD1230
void __fastcall JacobianBuilder::setLocalTranslationsFromAtom(hkpSetLocalTranslationsConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB)
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
                                        _mm_shuffle_ps(atom->m_translationA.m_quad, v4.m_quad, 0),
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
                                        _mm_shuffle_ps(atom->m_translationB.m_quad, v5.m_quad, 0),
                                        in->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170),
                                      in->m_transformB.m_storage->m_rotation.m_col2.m_quad)),
                                  in->m_transformB.m_storage->m_translation.m_quad);
}

// File Line: 254
// RVA: 0xDD12A0
void __fastcall JacobianBuilder::setLocalRotationsFromAtom(hkpSetLocalRotationsConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB)
{
  hkTransformf *v4; // rax
  signed __int64 v5; // r10
  hkTransformf *v6; // r11
  signed __int64 v7; // r9
  signed __int64 v8; // r8
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 *v12; // rax
  __m128 v13; // xmm1
  hkTransformf *v14; // rax
  signed __int64 v15; // r11
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  hkpSetLocalRotationsConstraintAtom *v19; // rax
  __m128 v20; // xmm1

  v4 = in->m_transformA.m_storage;
  v5 = 3i64;
  v6 = baseB;
  v7 = 3i64;
  v8 = (char *)baseA - (char *)atom;
  v9 = v4->m_rotation.m_col0.m_quad;
  v10 = v4->m_rotation.m_col1.m_quad;
  v11 = v4->m_rotation.m_col2.m_quad;
  v12 = &atom->m_rotationB.m_col0.m_quad;
  do
  {
    v13 = *v12;
    --v12;
    --v7;
    *(__m128 *)((char *)v12 + v8) = _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v10),
                                        _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v9)),
                                      _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v11));
  }
  while ( v7 >= 0 );
  v14 = in->m_transformB.m_storage;
  v15 = (char *)v6 - (char *)atom;
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
void __fastcall JacobianBuilder::buildJacobianFromLinAtom(hkpLinConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm1
  signed __int64 v6; // rax
  hkp1dLinearBilateralConstraintInfo info; // [rsp+20h] [rbp-38h]

  v5.m_quad = (__m128)baseB->m_translation;
  v6 = 2i64 * (unsigned __int8)atom->m_axisIndex;
  info.m_pivotA = baseA->m_translation;
  info.m_pivotB = (hkVector4f)v5.m_quad;
  info.m_constrainedDofW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + 8 * v6);
  hk1dLinearBilateralConstraintBuildJacobian(&info, in, out);
}

// File Line: 271
// RVA: 0xDD13B0
void __fastcall JacobianBuilder::buildJacobianFromLinSoftAtom(hkpLinSoftConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm1
  signed __int64 v6; // rax
  hkVector4f v7; // xmm0
  hkp1dLinearBilateralUserTauConstraintInfo info; // [rsp+20h] [rbp-48h]

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
void __fastcall JacobianBuilder::setupStabilizationFromAtom(hkpSetupStabilizationAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkVector4f *vLocalArmA, hkVector4f *vLocalArmB, hkSimdFloat32 *maxAngularImpulse, hkSimdFloat32 *maxLinearImpulse, hkpConstraintQueryOut *noOut)
{
  hkpVelocityAccumulator *v9; // rax
  hkpVelocityAccumulator *v10; // r10
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // xmm9
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
    v9 = in->m_bodyA.m_storage;
    v10 = in->m_bodyB.m_storage;
    v11 = _mm_sub_ps(baseA->m_translation.m_quad, v9->m_scratch3.m_quad);
    v12 = _mm_sub_ps(baseB->m_translation.m_quad, v10->m_scratch3.m_quad);
    vLocalArmA->m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v9->m_scratch1.m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v9->m_scratch0.m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v9->m_scratch2.m_quad));
    v13.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v10->m_scratch1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v10->m_scratch0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v10->m_scratch2.m_quad));
    *vLocalArmB = (hkVector4f)v13.m_quad;
    v14.m_quad = (__m128)in->m_bodyA.m_storage->m_invMasses;
    v15.m_quad = (__m128)in->m_bodyB.m_storage->m_invMasses;
    v16 = _mm_max_ps(
            _mm_shuffle_ps(v14.m_quad, v14.m_quad, 170),
            _mm_max_ps(
              _mm_shuffle_ps(v14.m_quad, v14.m_quad, 85),
              _mm_shuffle_ps(in->m_bodyA.m_storage->m_invMasses.m_quad, v14.m_quad, 0)));
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
              _mm_cmpleps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))),
            v16);
    v22 = _mm_max_ps(_mm_max_ps(v16, v17), *(__m128 *)&epsilon);
    v23 = _mm_mul_ps(v13.m_quad, v13.m_quad);
    v24 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
            _mm_shuffle_ps(v23, v23, 170));
    v25 = _mm_rsqrt_ps(v24);
    v26 = _mm_mul_ps(*(__m128 *)_xmm, v25);
    v27 = _mm_mul_ps(_mm_mul_ps(v25, v24), v25);
    v28 = _mm_rcp_ps(v22);
    v29 = _mm_andnot_ps(_mm_cmpleps(v24, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v27), v26));
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
void __fastcall JacobianBuilder::buildJacobianFromLinLimitAtom(hkpLinLimitConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm1
  signed __int64 v6; // rax
  hkp1dLinearLimitInfo info; // [rsp+20h] [rbp-48h]

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
void __fastcall JacobianBuilder::buildJacobianFrom2dAngAtom(hkp2dAngConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  __int64 v5; // r10
  hkpConstraintQueryIn *v6; // rbp
  __int64 v7; // rbx
  hkVector4f *v8; // rsi
  hkVector4f *v9; // rbx
  hkp1dAngularBilateralConstraintInfo info; // [rsp+20h] [rbp-38h]

  v5 = (unsigned __int8)atom->m_freeRotationAxis;
  v6 = in;
  v7 = (unsigned __int8)modulo3Table[v5 + 2];
  v8 = (hkVector4f *)((char *)&baseB->m_rotation.m_col0 + (unsigned __int8)modulo3Table[v5 + 1]);
  info.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + v5);
  v9 = (hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v7);
  info.m_perpZeroErrorAxisBinW = (hkVector4f)v8->m_quad;
  info.m_constrainedDofW = (hkVector4f)v9->m_quad;
  hk1dAngularBilateralConstraintBuildJacobian(&info, in, out);
  info.m_perpZeroErrorAxisBinW = (hkVector4f)v9->m_quad;
  info.m_constrainedDofW.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    v8->m_quad);
  hk1dAngularBilateralConstraintBuildJacobian(&info, v6, out);
}

// File Line: 485
// RVA: 0xDD1780
void __fastcall JacobianBuilder::buildJacobianFromAngAtom(hkpAngConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  unsigned __int8 v5; // al
  hkTransformf *v6; // r14
  hkTransformf *v7; // rbp
  hkpConstraintQueryIn *v8; // r15
  hkpAngConstraintAtom *v9; // rsi
  __int64 v10; // rdi
  const char *v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rbx
  __int64 v18; // rsi
  hkp1dAngularBilateralConstraintInfo info; // [rsp+20h] [rbp-48h]

  v5 = atom->m_numConstrainedAxes;
  v6 = baseB;
  v7 = baseA;
  v8 = in;
  v9 = atom;
  if ( v5 == 2 )
  {
    v14 = (const unsigned __int8)modulo3Table[(unsigned __int8)atom->m_firstConstrainedAxis + 2] >> 4;
    v15 = (unsigned __int8)modulo3Table[v14 + 1];
    v16 = (unsigned __int8)modulo3Table[v14 + 2];
    v17 = (unsigned __int8)modulo3Table[v14 + 2];
    info.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + v14);
    v18 = (unsigned int)v15;
    info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v15);
    info.m_constrainedDofW = *(hkVector4f *)((char *)&baseB->m_rotation.m_col0 + v16);
    hk1dAngularBilateralConstraintBuildJacobian(&info, v8, out);
    info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&v6->m_rotation.m_col0 + v17);
    info.m_constrainedDofW.m_quad = _mm_xor_ps(
                                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                      *(__m128 *)((char *)&v6->m_rotation.m_col0.m_quad + v18));
    hk1dAngularBilateralConstraintBuildJacobian(&info, v8, out);
  }
  else
  {
    v10 = (unsigned __int8)atom->m_firstConstrainedAxis;
    if ( (signed int)v10 < (signed int)(v10 + v5) )
    {
      v11 = &modulo3Table[v10 + 1];
      do
      {
        v12 = *((unsigned __int8 *)v11++ - 1);
        info.m_constrainedDofW = *(hkVector4f *)((char *)&v7->m_rotation.m_col0 + v12);
        v13 = *(unsigned __int8 *)v11;
        info.m_zeroErrorAxisAinW = *(hkVector4f *)((char *)&v7->m_rotation.m_col0 + *((unsigned __int8 *)v11 - 1));
        info.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&v6->m_rotation.m_col0 + v13);
        hk1dAngularBilateralConstraintBuildJacobian(&info, v8, out);
        LODWORD(v10) = v10 + 1;
      }
      while ( (signed int)v10 < (unsigned __int8)v9->m_firstConstrainedAxis + (unsigned __int8)v9->m_numConstrainedAxes );
    }
  }
}

// File Line: 518
// RVA: 0xDD18F0
void __fastcall JacobianBuilder::buildJacobianFrom3dAngularAtom(hkp3dAngConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkVector4f *vLocalArmA, hkVector4f *vLocalArmB)
{
  hkpVelocityAccumulator *v6; // rbx
  hkVector4f *v7; // r14
  unsigned __int64 v8; // r15
  hkpConstraintQueryIn *v9; // rsi
  hkTransformf *v10; // rdi
  signed int v11; // er11
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  signed int v15; // edx
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r9
  float v19; // xmm0_4
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm7
  float v25; // xmm0_4
  float v26; // xmm3_4
  __int64 v27; // r8
  __int64 v28; // r9
  float v29; // xmm0_4
  __m128 v30; // xmm3
  __m128 v31; // xmm0
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  float v39; // [rsp+1Ch] [rbp-7Dh]
  __m128 v40; // [rsp+20h] [rbp-79h]
  hkMatrix3f v41; // [rsp+30h] [rbp-69h]
  float v42; // [rsp+60h] [rbp-39h]
  float v43; // [rsp+68h] [rbp-31h]
  float v44; // [rsp+6Ch] [rbp-2Dh]
  float v45; // [rsp+70h] [rbp-29h]
  __m128 *v46; // [rsp+108h] [rbp+6Fh]
  float vLocalArmBa; // [rsp+118h] [rbp+7Fh]

  v6 = in->m_bodyB.m_storage;
  v7 = vLocalArmB;
  v8 = vLocalArmB->m_quad.m128_u64[0];
  v9 = in;
  v10 = baseB;
  hkMatrix3f::setMul(&v41, (hkMatrix3f *)&in->m_bodyA.m_storage->m_scratch0, (hkMatrix3f *)&baseA->m_rotation.m_col0);
  hkMatrix3f::setMul(
    (hkMatrix3f *)((char *)&v41 + 24),
    (hkMatrix3f *)&v6->m_scratch0,
    (hkMatrix3f *)&v10->m_rotation.m_col0);
  v11 = 0;
  v12 = (float)(v41.m_col0.m_quad.m128_f32[0] + v40.m128_f32[3]) + v41.m_col1.m_quad.m128_f32[0];
  if ( v12 <= 0.0 )
  {
    v40.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v40.m128_u64 + 4) = 2i64;
    v15 = 0;
    if ( v40.m128_f32[3] > v41.m_col0.m_quad.m128_f32[0] )
      v15 = 1;
    if ( v41.m_col1.m_quad.m128_f32[0] > v41.m_col0.m_quad.m128_f32[5 * v15] )
      v15 = 2;
    v16 = v15;
    v17 = v40.m128_i32[v15];
    v18 = v40.m128_i32[v17];
    v19 = fsqrt(
            (float)(v41.m_col0.m_quad.m128_f32[5 * v15]
                  - (float)(v41.m_col0.m_quad.m128_f32[5 * v18] + v41.m_col0.m_quad.m128_f32[5 * v17]))
          + 1.0);
    v40.m128_f32[v16] = v19 * 0.5;
    v40.m128_f32[3] = (float)(v41.m_col0.m_quad.m128_f32[v18 + 4 * v17] - v41.m_col0.m_quad.m128_f32[v17 + 4 * v18])
                    * (float)(0.5 / v19);
    v40.m128_f32[v17] = (float)(v41.m_col0.m_quad.m128_f32[v17 + 4 * v16] + v41.m_col0.m_quad.m128_f32[v16 + 4 * v17])
                      * (float)(0.5 / v19);
    v40.m128_f32[v18] = (float)(v41.m_col0.m_quad.m128_f32[v15 + 4 * v18] + v41.m_col0.m_quad.m128_f32[v18 + 4i64 * v15])
                      * (float)(0.5 / v19);
  }
  else
  {
    v13 = fsqrt(v12 + 1.0);
    v40.m128_f32[3] = v13 * 0.5;
    v14 = (float)(v41.m_col0.m_quad.m128_f32[2] - v40.m128_f32[0]) * (float)(0.5 / v13);
    v40.m128_f32[0] = (float)(v41.m_col0.m_quad.m128_f32[0] - v41.m_col0.m_quad.m128_f32[3]) * (float)(0.5 / v13);
    v40.m128_f32[1] = v14;
    v40.m128_f32[2] = (float)(v39 - v40.m128_f32[2]) * (float)(0.5 / v13);
  }
  v20 = _mm_mul_ps(v40, v40);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(
          v40,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23)));
  v25 = (float)(v41.m_col1.m_quad.m128_f32[2] + v41.m_col2.m_quad.m128_f32[3]) + v45;
  if ( v25 <= 0.0 )
  {
    v40.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v40.m128_u64 + 4) = 2i64;
    if ( v41.m_col2.m_quad.m128_f32[3] > v41.m_col1.m_quad.m128_f32[2] )
      v11 = 1;
    if ( v45 > v41.m_col1.m_quad.m128_f32[5 * v11 + 2] )
      v11 = 2;
    v27 = v40.m128_i32[v11];
    v28 = v40.m128_i32[v27];
    v29 = fsqrt(
            (float)(v41.m_col1.m_quad.m128_f32[5 * v11 + 2]
                  - (float)(v41.m_col1.m_quad.m128_f32[5 * v28 + 2] + v41.m_col1.m_quad.m128_f32[5 * v27 + 2]))
          + 1.0);
    v40.m128_f32[v11] = v29 * 0.5;
    v40.m128_f32[3] = (float)(v41.m_col1.m_quad.m128_f32[v28 + 4 * v27 + 2]
                            - v41.m_col1.m_quad.m128_f32[v27 + 4 * v28 + 2])
                    * (float)(0.5 / v29);
    v40.m128_f32[v27] = (float)(v41.m_col1.m_quad.m128_f32[v27 + 4i64 * v11 + 2]
                              + v41.m_col1.m_quad.m128_f32[v11 + 4 * v27 + 2])
                      * (float)(0.5 / v29);
    v40.m128_f32[v28] = (float)(v41.m_col1.m_quad.m128_f32[v11 + 4 * v28 + 2]
                              + v41.m_col1.m_quad.m128_f32[v28 + 4i64 * v11 + 2])
                      * (float)(0.5 / v29);
  }
  else
  {
    v26 = fsqrt(v25 + 1.0);
    v40.m128_f32[3] = v26 * 0.5;
    v40.m128_f32[0] = (float)(v42 - v44) * (float)(0.5 / v26);
    v40.m128_f32[1] = (float)(v43 - v41.m_col2.m_quad.m128_f32[0]) * (float)(0.5 / v26);
    v40.m128_f32[2] = (float)(v41.m_col1.m_quad.m128_f32[3] - v41.m_col2.m_quad.m128_f32[2]) * (float)(0.5 / v26);
  }
  v30 = v40;
  v31 = v40;
  *(__m128 *)(v8 + 16) = v24;
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
  v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 177), v33);
  v35 = _mm_rsqrt_ps(v34);
  v36 = _mm_mul_ps(
          v30,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)), _mm_mul_ps(v35, *(__m128 *)_xmm)));
  v37 = (__m128)LODWORD(v9->m_subStepInvDeltaTime.m_storage);
  vLocalArmBa = v9->m_tau.m_storage;
  v38 = *v46;
  *(__m128 *)(v8 + 32) = v36;
  v7->m_quad.m128_u64[0] = v8 + 48;
  *(__m128 *)v8 = _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      aabbOut.m_quad,
                      _mm_mul_ps(
                        _mm_shuffle_ps((__m128)LODWORD(vLocalArmBa), (__m128)LODWORD(vLocalArmBa), 0),
                        _mm_shuffle_ps(v37, v37, 0))),
                    _mm_unpacklo_ps(v38, aabbOut.m_quad));
  *(float *)v8 = *(float *)v8 + 0.00000011920929;
  *(_BYTE *)v8 = 32;
}

// File Line: 566
// RVA: 0xDD50E0
void __fastcall JacobianBuilder::buildJacobianFromLinDeformableAtom_hkpConstraintQueryIn_(hkpDeformableLinConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v5; // r10
  hkpVelocityAccumulator *v6; // r11
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  hkpJacobianSchema *v10; // rbx
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // ST00_16
  __m128 v14; // xmm1
  __m128 v15; // ST10_16
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm6
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  hkVector4f v23; // xmm9
  hkTransformf *v24; // rax
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm6
  __m128 v31; // xmm3
  hkVector4f v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm6
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm8
  __m128 v43; // xmm7
  __m128 v44; // xmm8
  __m128 v45; // xmm7
  __m128 v46; // xmm6
  __m128 v47; // xmm9
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm1

  v5 = in->m_bodyA.m_storage;
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
  v13 = v9;
  v14 = _mm_sub_ps(baseA->m_translation.m_quad, v5->m_scratch3.m_quad);
  *(__m128 *)v10 = v11;
  v15 = v12;
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v5->m_scratch0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v5->m_scratch1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v5->m_scratch2.m_quad));
  v17 = _mm_sub_ps(baseB->m_translation.m_quad, v6->m_scratch3.m_quad);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v6->m_scratch0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v6->m_scratch1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v6->m_scratch2.m_quad));
  v19 = _mm_mul_ps(v16, v16);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_mul_ps(v18, v18);
  *(__m128 *)&v10[64] = _mm_shuffle_ps(
                          v16,
                          _mm_unpackhi_ps(
                            v16,
                            _mm_andnot_ps(
                              _mm_cmpleps(v20, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v21)),
                                v20))),
                          196);
  v23.m_quad = (__m128)atom->m_offset;
  v24 = in->m_transformA.m_storage;
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v26 = _mm_rsqrt_ps(v25);
  v27 = _mm_andnot_ps(
          _mm_cmpleps(v25, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm)),
            v25));
  v28 = _mm_shuffle_ps(v5->m_invMasses.m_quad, v5->m_invMasses.m_quad, 255);
  v29 = _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 170), v24->m_rotation.m_col2.m_quad);
  v30 = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, v27), 196);
  v31 = _mm_shuffle_ps(atom->m_offset.m_quad, v23.m_quad, 85);
  v32.m_quad = (__m128)atom->m_offset;
  *(__m128 *)&v10[80] = v30;
  v33 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(v31, v24->m_rotation.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v23.m_quad, 0), v24->m_rotation.m_col0.m_quad)),
          v29);
  v34 = _mm_shuffle_ps(v33, v33, 0);
  v35 = _mm_shuffle_ps(v33, v33, 85);
  v36 = _mm_shuffle_ps(v33, v33, 170);
  v37 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v34, v5->m_scratch0.m_quad), _mm_mul_ps(v35, v5->m_scratch1.m_quad)),
          _mm_mul_ps(v36, v5->m_scratch2.m_quad));
  v38 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v34, v6->m_scratch0.m_quad), _mm_mul_ps(v35, v6->m_scratch1.m_quad)),
          _mm_mul_ps(v36, v6->m_scratch2.m_quad));
  v39 = _mm_shuffle_ps(v6->m_invMasses.m_quad, v6->m_invMasses.m_quad, 255);
  v40 = _mm_add_ps(v39, v28);
  v41 = _mm_rcp_ps(v40);
  v42 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v40)), v41);
  v43 = v42;
  v44 = _mm_mul_ps(_mm_mul_ps(v42, v28), v38);
  v45 = _mm_mul_ps(_mm_mul_ps(v43, v39), v37);
  v46 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 255);
  v47 = _mm_mul_ps(v23.m_quad, v23.m_quad);
  v48 = _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0);
  v49 = _mm_mul_ps(
          _mm_shuffle_ps(
            (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
            (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
            0),
          v48);
  out->m_jacobianSchemas.m_storage = v10 + 128;
  v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v51 = _mm_rsqrt_ps(v50);
  *(__m128 *)&v10[32] = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, v48), 196);
  *(__m128 *)&v10[48] = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v49), 196);
  *(__m128 *)&v10[96] = _mm_shuffle_ps(
                          v45,
                          _mm_unpackhi_ps(
                            v45,
                            _mm_andnot_ps(
                              _mm_cmpleps(v50, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                                  _mm_mul_ps(v51, *(__m128 *)_xmm)),
                                v50))),
                          196);
  v32.m_quad.m128_f32[0] = *(float *)v10 + 0.00000011920929;
  *(__m128 *)&v10[112] = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, v46), 196);
  *(_DWORD *)v10 = v32.m_quad.m128_i32[0];
  *v10 = (hkpJacobianSchema)34;
}

// File Line: 642
// RVA: 0xDD5460
void __fastcall JacobianBuilder::buildJacobianFromAngDeformableAtom_hkpConstraintQueryIn_(hkpDeformableAngConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB)
{
  hkpVelocityAccumulator *v4; // r14
  _QWORD *v5; // r12
  __m128 *v6; // rbx
  hkpVelocityAccumulator *v7; // r15
  hkpConstraintQueryIn *v8; // rsi
  __m128 v9; // xmm4
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
  hkVector4f v21; // xmm0
  __m128 v22; // xmm6
  hkVector4f v23; // xmm1
  hkVector4f v24; // xmm0
  __m128 v25; // xmm0
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm7
  __m128 v29; // xmm0
  hkVector4f v30; // xmm2
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm7
  __m128 v34; // xmm0
  float v35; // xmm6_4
  float v36; // xmm7_4
  signed int v37; // er11
  hkVector4f v38; // xmm1
  float v39; // xmm0_4
  float v40; // xmm6_4
  float v41; // xmm3_4
  bool v42; // cf
  bool v43; // zf
  signed int v44; // edx
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r9
  float v48; // xmm0_4
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  float v55; // xmm3_4
  __m128 v56; // xmm4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  __int64 v61; // r8
  __int64 v62; // r9
  float v63; // xmm0_4
  hkQuaternionf v64; // xmm6
  __m128 v65; // xmm5
  __m128 v66; // xmm0
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm0
  __m128 v74; // xmm3
  __m128 v75; // xmm1
  __m128 v76; // xmm0
  __m128 v77; // xmm4
  __m128 v78; // xmm0
  __m128 v79; // xmm1
  __m128 v80; // xmm2
  __m128 v81; // xmm1
  __m128 v82; // xmm3
  __m128 v83; // xmm0
  __m128 v84; // xmm2
  __m128 v85; // xmm3
  __m128 v86; // xmm1
  hkQuaternionf v87; // xmm5
  __m128 v88; // xmm5
  __m128 v89; // xmm6
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  float v92; // et1
  __m128 v93; // xmm4
  __m128 v94; // xmm3
  float v95; // [rsp+0h] [rbp-7Dh]
  float v96; // [rsp+4h] [rbp-79h]
  __m128 v97; // [rsp+Ch] [rbp-71h]
  __m256i v98; // [rsp+1Ch] [rbp-61h]
  __m128 v99; // [rsp+3Ch] [rbp-41h]
  __m128 v100; // [rsp+4Ch] [rbp-31h]
  _QWORD *retaddr; // [rsp+FCh] [rbp+7Fh]

  v4 = in->m_bodyA.m_storage;
  v5 = retaddr;
  v6 = (__m128 *)*retaddr;
  v7 = in->m_bodyB.m_storage;
  v8 = in;
  v9 = v4->m_scratch1.m_quad;
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
  v16 = v4->m_scratch0.m_quad;
  v6[3] = v15;
  v17 = v4->m_scratch2.m_quad;
  v18.m_quad = (__m128)atom->m_yieldStrengthDiag;
  *v6 = _mm_mul_ps(v14, v18.m_quad);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), v16),
            _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), v9)),
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 170), v17));
  v20.m_quad = (__m128)baseA->m_rotation.m_col1;
  v21.m_quad = (__m128)baseA->m_rotation.m_col1;
  *(__m128 *)&v98.m256i_u64[2] = v19;
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 0), v16),
            _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v20.m_quad, 85), v9)),
          _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 170), v17));
  v23.m_quad = (__m128)baseA->m_rotation.m_col2;
  v24.m_quad = (__m128)baseA->m_rotation.m_col2;
  v99 = v22;
  v25 = _mm_shuffle_ps(v24.m_quad, v23.m_quad, 85);
  v26 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 0);
  v27 = _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 170), v17);
  v28 = _mm_mul_ps(v26, v16);
  v29 = _mm_mul_ps(v25, v9);
  v30.m_quad = (__m128)baseB->m_rotation.m_col0;
  v31 = v7->m_scratch1.m_quad;
  v32 = v7->m_scratch0.m_quad;
  v33 = _mm_add_ps(_mm_add_ps(v28, v29), v27);
  v34 = _mm_shuffle_ps(baseB->m_rotation.m_col0.m_quad, baseB->m_rotation.m_col0.m_quad, 85);
  v100 = v33;
  *(__m128 *)&v98.m256i_u64[1] = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v30.m_quad, v30.m_quad, 0), v32),
                                     _mm_mul_ps(v34, v31)),
                                   _mm_mul_ps(_mm_shuffle_ps(v30.m_quad, v30.m_quad, 170), v12));
  LODWORD(v35) = (unsigned __int128)_mm_shuffle_ps(v22, v22, 85);
  LODWORD(v36) = (unsigned __int128)_mm_shuffle_ps(v33, v33, 170);
  v37 = 0;
  v38.m_quad = (__m128)baseB->m_rotation.m_col2;
  v97 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(baseB->m_rotation.m_col1.m_quad, baseB->m_rotation.m_col1.m_quad, 0), v32),
            _mm_mul_ps(_mm_shuffle_ps(baseB->m_rotation.m_col1.m_quad, baseB->m_rotation.m_col1.m_quad, 85), v31)),
          _mm_mul_ps(_mm_shuffle_ps(baseB->m_rotation.m_col1.m_quad, baseB->m_rotation.m_col1.m_quad, 170), v12));
  *(__m128 *)v98.m256i_i8 = _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v38.m_quad, v38.m_quad, 0), v32),
                                _mm_mul_ps(_mm_shuffle_ps(v38.m_quad, v38.m_quad, 85), v31)),
                              _mm_mul_ps(_mm_shuffle_ps(v38.m_quad, v38.m_quad, 170), v12));
  v39 = (float)(v19.m128_f32[0] + v35) + v36;
  if ( v39 <= 0.0 )
  {
    *(unsigned __int64 *)((char *)&v97.m128_u64[1] + 4) = 2i64;
    v97.m128_i32[2] = 1;
    v42 = v35 < v19.m128_f32[0];
    v43 = v35 == v19.m128_f32[0];
    v40 = *(float *)&FLOAT_1_0;
    v44 = 0;
    if ( !v42 && !v43 )
      v44 = 1;
    if ( v36 > *(float *)&v98.m256i_i32[5 * v44 + 4] )
      v44 = 2;
    v45 = v44;
    v46 = v97.m128_i32[v44 + 2];
    v47 = v97.m128_i32[v46 + 2];
    v48 = fsqrt(
            (float)(*(float *)&v98.m256i_i32[5 * v44 + 4]
                  - (float)(*(float *)&v98.m256i_i32[5 * v47 + 4] + *(float *)&v98.m256i_i32[5 * v46 + 4]))
          + 1.0);
    v97.m128_f32[v45 + 2] = v48 * 0.5;
    *(float *)&v98.m256i_i32[1] = (float)(*(float *)&v98.m256i_i32[v47 + 4 * v46 + 4]
                                        - *(float *)&v98.m256i_i32[v46 + 4 * v47 + 4])
                                * (float)(0.5 / v48);
    v97.m128_f32[v46 + 2] = (float)(*(float *)&v98.m256i_i32[v46 + 4 * v45 + 4]
                                  + *(float *)&v98.m256i_i32[v45 + 4 * v46 + 4])
                          * (float)(0.5 / v48);
    v97.m128_f32[v47 + 2] = (float)(*(float *)&v98.m256i_i32[v44 + 4 * v47 + 4]
                                  + *(float *)&v98.m256i_i32[v47 + 4i64 * v44 + 4])
                          * (float)(0.5 / v48);
  }
  else
  {
    v40 = *(float *)&FLOAT_1_0;
    *(float *)&retaddr = v39 + 1.0;
    v41 = fsqrt(v39 + 1.0);
    *(float *)&v98.m256i_i32[1] = v41 * 0.5;
    v97.m128_f32[2] = (float)(v99.m128_f32[2] - v100.m128_f32[1]) * (float)(0.5 / v41);
    v97.m128_f32[3] = (float)(v100.m128_f32[0] - *(float *)&v98.m256i_i32[6]) * (float)(0.5 / v41);
    *(float *)v98.m256i_i32 = (float)(*(float *)&v98.m256i_i32[5] - v99.m128_f32[0]) * (float)(0.5 / v41);
  }
  v49 = _mm_mul_ps(*(__m128 *)((char *)&v97 + 8), *(__m128 *)((char *)&v97 + 8));
  v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
  v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50);
  v52 = _mm_rsqrt_ps(v51);
  v53 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52));
  v54 = _mm_mul_ps(*(__m128 *)_xmm, v52);
  v55 = *(float *)&v98.m256i_i32[2];
  v56 = _mm_mul_ps(*(__m128 *)((char *)&v97 + 8), _mm_mul_ps(v53, v54));
  v57 = *(float *)&v98.m256i_i32[2];
  v54.m128_i32[0] = v98.m256i_i32[2];
  v6[4] = v56;
  v58 = (float)(v54.m128_f32[0] + v97.m128_f32[1]) + v55;
  if ( v58 <= 0.0 )
  {
    v97.m128_i32[2] = 1;
    *(unsigned __int64 *)((char *)&v97.m128_u64[1] + 4) = 2i64;
    if ( v97.m128_f32[1] > v57 )
      v37 = 1;
    if ( v55 > *(float *)&v98.m256i_i32[5 * v37 + 2] )
      v37 = 2;
    v61 = v97.m128_i32[v37 + 2];
    v62 = v97.m128_i32[v61 + 2];
    *(float *)&retaddr = (float)(*(float *)&v98.m256i_i32[5 * v37 + 2]
                               - (float)(*(float *)&v98.m256i_i32[5 * v62 + 2] + *(float *)&v98.m256i_i32[5 * v61 + 2]))
                       + v40;
    v63 = fsqrt(*(float *)&retaddr);
    v97.m128_f32[v37 + 2] = v63 * 0.5;
    *(float *)&v98.m256i_i32[1] = (float)(*(float *)&v98.m256i_i32[v62 + 4 * v61 + 2]
                                        - *(float *)&v98.m256i_i32[v61 + 4 * v62 + 2])
                                * (float)(0.5 / v63);
    v97.m128_f32[v61 + 2] = (float)(*(float *)&v98.m256i_i32[v61 + 4i64 * v37 + 2]
                                  + *(float *)&v98.m256i_i32[v37 + 4 * v61 + 2])
                          * (float)(0.5 / v63);
    v97.m128_f32[v62 + 2] = (float)(*(float *)&v98.m256i_i32[v37 + 4 * v62 + 2]
                                  + *(float *)&v98.m256i_i32[v62 + 4i64 * v37 + 2])
                          * (float)(0.5 / v63);
  }
  else
  {
    *(float *)&retaddr = v58 + v40;
    v59 = fsqrt(v58 + v40);
    v60 = v97.m128_f32[2] - *(float *)&v98.m256i_i32[1];
    *(float *)&v98.m256i_i32[1] = v59 * 0.5;
    v97.m128_f32[2] = v60 * (float)(0.5 / v59);
    v97.m128_f32[3] = (float)(*(float *)v98.m256i_i32 - v96) * (float)(0.5 / v59);
    *(float *)v98.m256i_i32 = (float)(v95 - v97.m128_f32[0]) * (float)(0.5 / v59);
  }
  v64.m_vec.m_quad = (__m128)atom->m_offset;
  v65 = _mm_shuffle_ps(v7->m_invMasses.m_quad, v7->m_invMasses.m_quad, 255);
  v66 = _mm_mul_ps(*(__m128 *)((char *)&v97 + 8), *(__m128 *)((char *)&v97 + 8));
  v67 = _mm_add_ps(_mm_shuffle_ps(v66, v66, 78), v66);
  v68 = _mm_add_ps(_mm_shuffle_ps(v67, v67, 177), v67);
  v69 = _mm_rsqrt_ps(v68);
  v70 = _mm_mul_ps(
          *(__m128 *)((char *)&v97 + 8),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v69, v68), v69)), _mm_mul_ps(v69, *(__m128 *)_xmm)));
  v71 = _mm_add_ps(_mm_shuffle_ps(v4->m_invMasses.m_quad, v4->m_invMasses.m_quad, 255), v65);
  v6[5] = v70;
  v72 = _mm_rcp_ps(v71);
  v73 = _mm_mul_ps(v64.m_vec.m_quad, qi.m_vec.m_quad);
  v74 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v72, v71)), v72);
  v75 = _mm_add_ps(_mm_shuffle_ps(v73, v73, 78), v73);
  v76 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v75, v75, 177), v75), 0x1Fu), 0x1Fu),
          qi.m_vec.m_quad);
  v77 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v64.m_vec.m_quad, v76), _mm_mul_ps(v65, v74)), v76);
  v78 = _mm_mul_ps(v77, v77);
  v79 = _mm_add_ps(_mm_shuffle_ps(v78, v78, 78), v78);
  v80 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 177), v79);
  v81 = _mm_rsqrt_ps(v80);
  v82 = _mm_cmpleps(v80, (__m128)0i64);
  v83 = _mm_mul_ps(v81, v80);
  v84 = v64.m_vec.m_quad;
  v85 = _mm_mul_ps(
          _mm_andnot_ps(
            v82,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v83, v81)), _mm_mul_ps(*(__m128 *)_xmm, v81))),
          v77);
  v86 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v64.m_vec.m_quad, v64.m_vec.m_quad, 201), v85),
          _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v64.m_vec.m_quad));
  v87.m_vec.m_quad = (__m128)atom->m_offset;
  v6[6] = v85;
  v88 = _mm_mul_ps(v87.m_vec.m_quad, v87.m_vec.m_quad);
  v89 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v64.m_vec.m_quad, v64.m_vec.m_quad, 255), v85),
            _mm_shuffle_ps(v86, v86, 201)),
          _mm_mul_ps(_mm_shuffle_ps(v85, v85, 255), v64.m_vec.m_quad));
  v90 = _mm_mul_ps(v85, v84);
  v91 = _mm_add_ps(_mm_shuffle_ps(v90, v90, 78), v90);
  v90.m128_i32[0] = LODWORD(v8->m_subStepInvDeltaTime.m_storage);
  v92 = v8->m_tau.m_storage;
  v6[7] = _mm_shuffle_ps(v89, _mm_unpackhi_ps(v89, _mm_add_ps(_mm_shuffle_ps(v91, v91, 177), v91)), 196);
  v93 = _mm_shuffle_ps((__m128)LODWORD(v92), (__m128)LODWORD(v92), 0);
  LODWORD(retaddr) = v90.m128_i32[0];
  *v6 = _mm_shuffle_ps(*v6, _mm_unpackhi_ps(*v6, v93), 196);
  v6[1] = _mm_shuffle_ps(
            v6[1],
            _mm_unpackhi_ps(v6[1], _mm_mul_ps(_mm_shuffle_ps((__m128)v90.m128_u32[0], (__m128)v90.m128_u32[0], 0), v93)),
            196);
  v94 = v6[2];
  *v5 = v6 + 8;
  v6[2] = _mm_shuffle_ps(
            v94,
            _mm_unpackhi_ps(
              v94,
              _mm_sub_ps(
                query.m_quad,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                    _mm_shuffle_ps(v88, v88, 170)),
                  (__m128)xmmword_141A710D0))),
            196);
  v6[3] = _mm_shuffle_ps(v6[3], _mm_unpackhi_ps(v6[3], _mm_shuffle_ps(v18.m_quad, v18.m_quad, 255)), 196);
  *(float *)v6->m128_u64 = *(float *)v6->m128_u64 + 0.00000011920929;
  LOBYTE(v6->m128_u64[0]) = 35;
}

// File Line: 717
// RVA: 0xDD1D40
hkResult *__fastcall JacobianBuilder::buildJacobianFromAngLimitAtom(hkResult *result, hkpAngLimitConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkp1dAngularLimitInfo *ali, hkpConstraintQueryOut *out)
{
  __int64 v7; // r10
  float v8; // xmm0_4
  __int64 v9; // r8
  __m128 v10; // xmm9
  __int64 v11; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm8
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm10
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  __m128 v28; // xmm10
  __m128 v29; // xmm11
  __m128 v30; // xmm5
  __m128i v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  hkResult *v36; // rax
  unsigned int v37; // [rsp+88h] [rbp+10h]

  if ( atom->m_isEnabled )
  {
    v7 = (unsigned __int8)atom->m_limitAxis;
    v8 = in->m_tau.m_storage;
    v9 = (unsigned __int8)modulo3Table[v7 + 2];
    v10 = 0i64;
    v11 = (unsigned __int8)modulo3Table[v7 + 1];
    ali->m_tau.m_storage = v8 * atom->m_angularLimitsTauFactor;
    ali->m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseA->m_rotation.m_col0 + (signed int)v7);
    v12 = *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + v9);
    v13 = *(__m128 *)((char *)&baseA->m_rotation.m_col0.m_quad + v11);
    v14 = *(&baseB->m_rotation.m_col0.m_quad + (signed int)v7);
    v15 = *(__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + v9);
    ali->m_min.m_storage = atom->m_minAngle;
    ali->m_max.m_storage = atom->m_maxAngle;
    v16 = _mm_mul_ps(v15, v13);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v14));
    v19 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v13);
    v20 = _mm_rcp_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170)));
    v21 = _mm_mul_ps(v20, v17);
    v22 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v21), _mm_cmpltps(*(__m128 *)_xmm, v21));
    v23 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v21), v22), _mm_andnot_ps(v22, v21));
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_cmpleps((__m128)0i64, v20);
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
    *(float *)&v37 = *((float *)out->m_constraintRuntime.m_storage + 1) * -1.0;
    v27 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v23, *(__m128 *)_xmm), *(__m128 *)_xmm), v26), v22),
            _mm_andnot_ps(v22, v26));
    v28 = _mm_or_ps(
            _mm_andnot_ps(v25, _mm_add_ps(_mm_or_ps(_mm_and_ps(v17, *(__m128 *)_xmm), *(__m128 *)_xmm), v27)),
            _mm_and_ps(v27, v25));
    v29 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
    v30 = _mm_sub_ps(v28, _mm_shuffle_ps((__m128)v37, (__m128)v37, 0));
    do
    {
      v31 = (__m128i)_mm_mul_ps(_mm_add_ps(v30, (__m128)xmmword_141A713B0), v29);
      v32 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u));
      v33 = _mm_sub_ps(
              _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v31, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
              *(__m128 *)two23);
      v34 = _mm_or_ps(
              _mm_andnot_ps(v32, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v31, v33)), v33)),
              _mm_and_ps((__m128)v31, v32));
      v10 = _mm_add_ps(v10, v34);
      v30 = _mm_sub_ps(v30, _mm_mul_ps(v34, (__m128)xmmword_141A713F0));
      v35 = _mm_cmpltps(v30, (__m128)xmmword_141A713B0);
    }
    while ( fmax(
              0.0 - 3.1415927,
              COERCE_FLOAT(v35.m128_i32[0] & v30.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                        v35,
                                                                                        (__m128)xmmword_141A713B0))) != v30.m128_f32[0] );
    result->m_enum = 0;
    v36 = result;
    ali->m_computedAngle.m_storage = v28.m128_f32[0] - (float)(v10.m128_f32[0] * 6.2831855);
  }
  else
  {
    result->m_enum = 1;
    v36 = result;
  }
  return v36;
}

// File Line: 772
// RVA: 0xDD2050
hkResult *__fastcall JacobianBuilder::bulidJacobianFromTwistLimitAtom(hkResult *result, hkpTwistLimitConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkp1dAngularLimitInfo *ali)
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
          _mm_cmpleps(v8, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
            v8));
  if ( v10.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN16), (__m128)LODWORD(FLOAT_1_0eN16), 0)) )
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
  v18 = _mm_sub_ps(_mm_mul_ps(v14, v16), _mm_mul_ps(v16, v13.m_quad));
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v20 = _mm_mul_ps(
          *(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_refAxis),
          _mm_shuffle_ps(v18, v18, 201));
  v21 = _mm_rcp_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170)));
  v22 = _mm_cmpleps((__m128)0i64, v21);
  v23 = _mm_mul_ps(v21, v19);
  v24 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v23), _mm_cmpltps(*(__m128 *)_xmm, v23));
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
  result->m_enum = 0;
  v29 = result;
  LODWORD(ali->m_computedAngle.m_storage) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                                     v22,
                                                                     _mm_add_ps(
                                                                       _mm_or_ps(
                                                                         _mm_and_ps(v19, *(__m128 *)_xmm),
                                                                         *(__m128 *)_xmm),
                                                                       v28)) | v28.m128_i32[0] & v22.m128_i32[0];
  ali->m_constrainedDofW = (hkVector4f)v13.m_quad;
  ali->m_tau.m_storage = (float)((float)(in->m_tau.m_storage * atom->m_angularLimitsTauFactor) * v12) * v12;
  return v29;
}

// File Line: 789
// RVA: 0xDD2320
hkResult *__fastcall JacobianBuilder::buildJacobianFromConeLimitAtom(hkResult *result, hkpConeLimitConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkp1dAngularLimitInfo *ali)
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
    v17 = _mm_cmpleps((__m128)0i64, v16);
    v18 = _mm_mul_ps(v16, v15);
    v19 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v18), _mm_cmpltps(*(__m128 *)_xmm, v18));
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
    result->m_enum = 0;
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
    LODWORD(ali->m_computedAngle.m_storage) = COERCE_UNSIGNED_INT(v26.m128_f32[0] + 1.5707964) & v22.m128i_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps((__m128)v22, v26);
    ali->m_min.m_storage = atom->m_minAngle;
    ali->m_max.m_storage = atom->m_maxAngle;
  }
  else
  {
    result->m_enum = 1;
  }
  return result;
}age = ato

// File Line: 833
// RVA: 0xDD25F0
hkResult *__fastcall JacobianBuilder::buildJacobianFromStabilizedConeLimitAtom(hkResult *result, hkpConeLimitConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkp1dAngularLimitInfo *ali, hkpConstraintQueryOut *out)
{
  hkResult *v7; // r11
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm12
  __m128 v11; // xmm12
  __m128 v12; // xmm1
  __m128 v13; // xmm13
  hkResult *v14; // rax
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
  unsigned __int8 v29; // r9
  struct hkpConstraintRuntime *v30; // rcx
  float v31; // xmm7_4
  int v32; // xmm9_4
  float v33; // xmm6_4
  float v34; // xmm8_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // [rsp+90h] [rbp+8h]

  v7 = result;
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
    v19 = _mm_cmpleps((__m128)0i64, v18);
    v20 = _mm_mul_ps(v18, v17);
    v21 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v20), _mm_cmpltps(*(__m128 *)_xmm, v20));
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
    result->m_enum = 0;
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
    LODWORD(ali->m_computedAngle.m_storage) = COERCE_UNSIGNED_INT(v28.m128_f32[0] + 1.5707964) & v24.m128i_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps((__m128)v24, v28);
    ali->m_min.m_storage = atom->m_minAngle;
    ali->m_max.m_storage = atom->m_maxAngle;
    v29 = atom->m_memOffsetToAngleOffset;
    if ( v29 > 1u )
    {
      v30 = out->m_constraintRuntime.m_storage;
      v39 = in->m_frameDeltaTime.m_storage * 0.5;
      v31 = *(float *)((char *)v30 + v29);
      v32 = *((_DWORD *)v30 + 1) ^ _xmm[0];
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
      *(float *)((char *)v30 + v29) = fmaxf(v37, 0.00000011920929);
      ali->m_computedAngle.m_storage = v38;
    }
    v14 = v7;
  }
  else
  {
    result->m_enum = 1;
    v14 = result;
  }
  return v14;
}

// File Line: 894
// RVA: 0xDD4E70
void __fastcall JacobianBuilder::_1dAngularFrictionBuildJacobian_hkpConstraintQueryIn_(hkp1dAngularFrictionInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  int v3; // edi
  hkVector4f *v4; // rbx
  hkpJacobianSchema *v5; // r10
  int v6; // esi
  hkpVelocityAccumulator *v7; // r9
  __m128 v8; // xmm9
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
  char *v20; // rax
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

  v3 = info->m_numFriction.m_storage;
  v4 = info->m_constrainedDofW.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  v6 = 0;
  if ( v3 > 0 )
  {
    v7 = in->m_bodyA.m_storage;
    v8 = v7->m_scratch1.m_quad;
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
    v20 = (char *)&info->m_lastSolverResults.m_storage->m_internalSolverData;
    do
    {
      v21 = v4->m_quad;
      *(_DWORD *)&v5[36] = v6++;
      *(float *)&v5[32] = v9;
      v5 += 48;
      ++v4;
      v20 += 16;
      v22 = _mm_xor_ps(v21, v12);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v11), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v8)),
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
      v29 = _mm_shuffle_ps((__m128)*((unsigned int *)v20 - 4), (__m128)*((unsigned int *)v20 - 4), 0);
      *(__m128 *)&v5[-48] = v28;
      v30 = *(float *)&v5[-48] + 0.00000011920929;
      *(__m128 *)&v5[-32] = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_mul_ps(v29, v13)), 196);
      *(float *)&v5[-48] = v30;
      v5[-48] = (hkpJacobianSchema)14;
    }
    while ( v6 < v3 );
  }
  out->m_jacobianSchemas.m_storage = v5;
}

// File Line: 922
// RVA: 0xDD5F50
void __fastcall JacobianBuilder::buildJacobianFromAngFrictionAtom_hkpConstraintQueryIn_(hkpAngFrictionConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryIn *v5; // rbx
  float v6; // xmm5_4
  int v7; // er11
  int v8; // edi
  struct hkpConstraintRuntime *v9; // r9
  hkpJacobianSchema *v10; // rdx
  char *v11; // r10
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  __m128 *v15; // rax
  __m128 *v16; // rcx
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  hkpJacobianSchema *v26; // rax

  v5 = in;
  if ( atom->m_isEnabled && (v6 = atom->m_maxFrictionTorque, v6 != 0.0) )
  {
    v7 = (unsigned __int8)atom->m_numFrictionAxes;
    v8 = 0;
    v9 = (struct hkpConstraintRuntime *)(&baseA->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_firstFrictionAxis);
    v10 = out->m_jacobianSchemas.m_storage;
    if ( v7 > 0 )
    {
      v11 = (char *)(out->m_constraintRuntime.m_storage - v9);
      v12 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
      v13 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
      do
      {
        v14 = *(__m128 *)v9;
        v15 = (__m128 *)v5->m_bodyA.m_storage;
        v16 = (__m128 *)v5->m_bodyB.m_storage;
        v17 = *(__m128 *)v9;
        v18 = *(__m128 *)v9;
        v10 += 48;
        v9 = (struct hkpConstraintRuntime *)((char *)v9 + 16);
        v19 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v15[5]),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v14, 0), v15[4])),
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v15[6]));
        *(__m128 *)&v10[-48] = v19;
        v20 = _mm_xor_ps(v18, v13);
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v16[5]),
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v16[4])),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v16[6]));
        v22 = v19;
        *(__m128 *)&v10[-32] = v21;
        v23 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v19, v19), v15[3]), _mm_mul_ps(_mm_mul_ps(v21, v21), v16[3]));
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
                                       (__m128)LODWORD(v5->m_rhsFactor.m_storage),
                                       (__m128)LODWORD(v5->m_rhsFactor.m_storage),
                                       0),
                                     _mm_shuffle_ps(
                                       (__m128)*(unsigned int *)((char *)v9 + (_QWORD)v11 - 12),
                                       (__m128)*(unsigned int *)((char *)v9 + (_QWORD)v11 - 12),
                                       0))),
                                 196);
        v17.m128_f32[0] = v6 * v5->m_microStepDeltaTime.m_storage;
        *(_DWORD *)&v10[-12] = v8;
        *(_DWORD *)&v10[-48] = v25.m128_i32[0];
        ++v8;
        v10[-48] = (hkpJacobianSchema)14;
        *(_DWORD *)&v10[-16] = v17.m128_i32[0];
      }
      while ( v8 < v7 );
    }
    out->m_jacobianSchemas.m_storage = v10;
  }
  else
  {
    v26 = out->m_jacobianSchemas.m_storage;
    v26[4] = (hkpJacobianSchema)(2 * atom->m_numFrictionAxes);
    v26 += 16;
    *(float *)&v26[-16] = *(float *)&v26[-16] + 0.00000011920929;
    v26[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v26;
  }
}

// File Line: 943
// RVA: 0xDD5D90
void __fastcall JacobianBuilder::buildJacobianFromLinMotorAtom_hkpConstraintQueryIn_(hkpLinMotorConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkTransformf *v5; // r13
  hkpLinMotorConstraintAtom *v6; // rsi
  hkpConstraintMotor *v7; // rbp
  _BYTE *v8; // r14
  float *v9; // r15
  hkpJacobianSchema *v10; // rdi
  __m128 *v11; // rbx
  hkVector4f *v12; // rcx
  hkpJacobianSchema *v13; // r9
  float v14; // xmm0_4
  __m128 v15; // xmm2
  __int64 v16; // rax
  signed __int64 v17; // rax
  __m128 v18; // xmm2
  float v19; // xmm0_4
  hkpJacobianSchema *v20; // rax
  hkpConstraintMotorOutput output; // [rsp+30h] [rbp-68h]
  hkp1dBilateralConstraintStatus statusOut; // [rsp+48h] [rbp-50h]
  hkpConstraintQueryIn *v23; // [rsp+50h] [rbp-48h]
  __int64 v24; // [rsp+58h] [rbp-40h]
  float v25; // [rsp+60h] [rbp-38h]
  float v26; // [rsp+64h] [rbp-34h]
  hkpConstraintQueryIn *ina; // [rsp+A8h] [rbp+10h]

  ina = in;
  v5 = baseB;
  v6 = atom;
  if ( atom->m_isEnabled.m_bool && (v7 = atom->m_motor) != 0i64 )
  {
    v8 = (char *)out->m_constraintRuntime.m_storage + atom->m_initializedOffset;
    v9 = (float *)((char *)out->m_constraintRuntime.m_storage + atom->m_previousTargetPositionOffset);
    if ( !*v8 )
      *v9 = atom->m_targetPosition;
    v10 = out->m_jacobianSchemas.m_storage;
    v11 = &baseA->m_translation.m_quad;
    v12 = &baseB->m_rotation.m_col0 + (unsigned __int8)atom->m_motorAxis;
    v13 = out->m_jacobianSchemas.m_storage;
    v24 = 0i64;
    hk1dLinearVelocityMotorBeginJacobian(v12, &baseA->m_translation, in, (hkp1Lin2AngJacobian *)v13, &statusOut);
    v14 = v6->m_targetPosition;
    v15 = _mm_sub_ps(*v11, v5->m_translation.m_quad);
    v16 = *(_QWORD *)out->m_constraintRuntime.m_storage;
    v23 = ina;
    v24 = v16;
    v17 = 2i64 * (unsigned __int8)v6->m_motorAxis;
    v25 = v14 - *v9;
    v18 = _mm_mul_ps(v15, *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17));
    v26 = *v9
        - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170)));
    hkCalcMotorData(v7, (hkpConstraintMotorInput *)&statusOut, &output);
    hk1dLinearVelocityMotorCommitJacobian(
      (hkp1dConstraintMotorInfo *)&output.m_targetPosition,
      ina,
      (hkp1Lin2AngJacobian *)v10,
      out);
    v19 = v6->m_targetPosition;
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
void __fastcall JacobianBuilder::buildJacobianFromAngMotorAtom_hkpConstraintQueryIn_(hkpAngMotorConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkpConstraintMotor *v5; // r10
  hkpConstraintQueryIn *v6; // r14
  hkpAngMotorConstraintAtom *v7; // rdi
  __int64 v8; // rdx
  struct hkpConstraintRuntime *v9; // r11
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
  __int16 v25; // ax
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
  __m128 *v36; // rdx
  __m128 *v37; // rcx
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
  float v51; // xmm0_4
  hkpJacobianSchema *v52; // rax
  hkpConstraintMotorOutput output; // [rsp+20h] [rbp-C8h]
  hkpConstraintMotorInput input; // [rsp+38h] [rbp-B0h]
  unsigned int v55; // [rsp+F0h] [rbp+8h]

  v5 = atom->m_motor;
  v6 = in;
  v7 = atom;
  if ( v5 && atom->m_isEnabled.m_bool )
  {
    v8 = (unsigned __int8)atom->m_motorAxis;
    v9 = out->m_constraintRuntime.m_storage;
    v10 = (char *)v9 + atom->m_initializedOffset;
    v11 = (float *)((char *)v9 + atom->m_previousTargetAngleOffset);
    v12 = 0i64;
    v13 = (unsigned __int8)modulo3Table[v8 + 1];
    v14 = (__m128 *)((char *)&baseB->m_rotation.m_col0.m_quad + (unsigned __int8)modulo3Table[v8 + 2]);
    v15 = _mm_mul_ps(*(__m128 *)((char *)&baseA->m_rotation.m_col0.m_quad + v13), *v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(*(&baseB->m_rotation.m_col0.m_quad + v8), *(&baseB->m_rotation.m_col0.m_quad + v8), 201),
              *v14),
            _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 201), *(&baseB->m_rotation.m_col0.m_quad + v8)));
    v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), *(__m128 *)((char *)&baseA->m_rotation.m_col0.m_quad + v13));
    v19 = _mm_rcp_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170)));
    v20 = _mm_cmpleps((__m128)0i64, v19);
    v21 = _mm_mul_ps(v19, v16);
    v22 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v21), _mm_cmpltps(*(__m128 *)_xmm, v21));
    v23 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v21), v22), _mm_andnot_ps(v22, v21));
    v24 = _mm_mul_ps(v23, v23);
    v25 = v7->m_correspondingAngLimitSolverResultOffset;
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
    if ( v25 )
    {
      *(float *)&v55 = *(float *)((char *)v9 + v25 + 4) * -1.0;
      v29 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
      v30 = _mm_sub_ps(v28, _mm_shuffle_ps((__m128)v55, (__m128)v55, 0));
      do
      {
        v31 = (__m128i)_mm_mul_ps(_mm_add_ps(v30, (__m128)xmmword_141A713B0), v29);
        v32 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u));
        v33 = _mm_sub_ps(
                _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v31, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
                *(__m128 *)two23);
        v34 = _mm_or_ps(
                _mm_andnot_ps(v32, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v31, v33)), v33)),
                _mm_and_ps((__m128)v31, v32));
        v12 = _mm_add_ps(v12, v34);
        v30 = _mm_sub_ps(v30, _mm_mul_ps(v34, (__m128)xmmword_141A713F0));
        v35 = _mm_cmpltps(v30, (__m128)xmmword_141A713B0);
      }
      while ( fmax(
                0.0 - 3.1415927,
                COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(v35, (__m128)xmmword_141A713B0) | v30.m128_i32[0] & v35.m128_i32[0])) != v30.m128_f32[0] );
      v28.m128_f32[0] = v28.m128_f32[0] - (float)(v12.m128_f32[0] * 6.2831855);
    }
    if ( !*v10 )
      *v11 = v28.m128_f32[0];
    v36 = (__m128 *)v6->m_bodyA.m_storage;
    v37 = (__m128 *)v6->m_bodyB.m_storage;
    v38 = (unsigned __int8)v7->m_motorAxis;
    v39 = out->m_jacobianSchemas.m_storage;
    input.m_lastResults = 0i64;
    v40 = *(&baseA->m_rotation.m_col0.m_quad + v38);
    v41 = *(hkpSolverResults *)v9;
    v42 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v40);
    v43 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v36[5]),
              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v36[4])),
            _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v36[6]));
    v44 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v37[5]),
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v37[4])),
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v37[6]));
    v45 = _mm_mul_ps(_mm_mul_ps(v43, v43), v36[3]);
    *(__m128 *)&v39[16] = v44;
    v46 = _mm_mul_ps(_mm_mul_ps(v44, v44), v37[3]);
    input.m_stepInfo.m_storage = (hkpConstraintQueryStepInfo *)&v6->m_subStepDeltaTime;
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
    input.m_deltaTarget.m_storage = v7->m_targetAngle - *v11;
    input.m_positionError.m_storage = *v11 - v28.m128_f32[0];
    hkCalcMotorData(v5, &input, &output);
    v50 = out->m_jacobianSchemas.m_storage;
    *(float *)&v39[28] = output.m_targetPosition.m_storage * v6->m_subStepInvDeltaTime.m_storage;
    v48.m128_i32[0] = *(_DWORD *)v50;
    v50 += 64;
    *(float *)&v50[-64] = v48.m128_f32[0] + 0.00000011920929;
    v50[-64] = (hkpJacobianSchema)15;
    *(float *)&v50[-32] = output.m_maxForce.m_storage * v6->m_microStepDeltaTime.m_storage;
    v48.m128_f32[0] = output.m_minForce.m_storage * v6->m_microStepDeltaTime.m_storage;
    out->m_jacobianSchemas.m_storage = v50;
    *(_DWORD *)&v50[-28] = v48.m128_i32[0];
    *(float *)&v50[-24] = output.m_targetVelocity.m_storage;
    *(float *)&v50[-20] = output.m_tau.m_storage;
    *(float *)&v50[-16] = output.m_damping.m_storage;
    v51 = v7->m_targetAngle;
    if ( v51 != *v11 || !*v10 )
    {
      *v11 = v51;
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
void __fastcall JacobianBuilder::buildJacobianFromRagdollMotorAtom_hkpConstraintQueryIn_(hkpRagdollMotorConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkTransformf *v5; // rbx
  hkpRagdollMotorConstraintAtom *v6; // r13
  _BYTE *v7; // r12
  __int64 v8; // r15
  __int64 v9; // rcx
  signed int v10; // esi
  __int64 v11; // r8
  hkpConstraintMotor **v12; // r13
  __int64 v13; // rdi
  hkpConstraintMotor *v14; // r9
  __int64 v15; // rdx
  signed __int64 v16; // rax
  signed __int64 v17; // rdx
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
  float *v66; // rbx
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
  signed __int64 v77; // rax
  signed __int64 v78; // rax
  __int64 v79; // [rsp+20h] [rbp-C8h]
  float v80; // [rsp+38h] [rbp-B0h]
  float v81; // [rsp+3Ch] [rbp-ACh]
  __int64 v82; // [rsp+48h] [rbp-A0h]
  int v83; // [rsp+50h] [rbp-98h]
  int v84; // [rsp+58h] [rbp-90h]
  int v85; // [rsp+5Ch] [rbp-8Ch]
  int v86; // [rsp+60h] [rbp-88h]
  hkpConstraintMotorOutput output; // [rsp+68h] [rbp-80h]
  float v88; // [rsp+80h] [rbp-68h]
  float v89; // [rsp+84h] [rbp-64h]
  hkMatrix3f THIS; // [rsp+88h] [rbp-60h]
  int v91; // [rsp+1A8h] [rbp+C0h]
  __int64 vars0; // [rsp+1B0h] [rbp+C8h]
  char *retaddr; // [rsp+1B8h] [rbp+D0h]
  hkTransformf *v94; // [rsp+1C0h] [rbp+D8h]
  hkpConstraintQueryIn *v95; // [rsp+1C8h] [rbp+E0h]

  v95 = in;
  v5 = baseB;
  v6 = atom;
  if ( atom->m_isEnabled.m_bool )
  {
    v7 = (_BYTE *)(*(_QWORD *)&in->m_subStepInvDeltaTime.m_storage + atom->m_initializedOffset);
    v8 = *(_QWORD *)&in->m_subStepInvDeltaTime.m_storage + atom->m_previousTargetAnglesOffset;
    hkMatrix3f_setMulMat3Mat3(&THIS, (hkMatrix3f *)&in->m_transformB.m_storage->m_rotation.m_col0, &atom->m_target_bRca);
    v9 = vars0;
    v10 = 0;
    *(_QWORD *)&output.m_tau.m_storage = 0i64;
    v84 = 0;
    v85 = 1;
    *(_QWORD *)&output.m_maxForce.m_storage = vars0;
    v86 = 2;
    v82 = 1i64;
    v83 = 0;
    v11 = 0i64;
    v79 = 0i64;
    v12 = v6->m_motors;
    v13 = 0i64;
    do
    {
      v14 = *v12;
      if ( *v12 )
      {
        v15 = *(signed int *)((char *)&v82 + v13);
        v16 = 2i64 * *(int *)((char *)&v84 + v13);
        v91 = 619091349;
        v17 = 2 * v15;
        v18 = _mm_add_ps(*(__m128 *)&retaddr[8 * v16], *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v16));
        v19 = _mm_mul_ps(v18, v18);
        v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170));
        v21 = _mm_rsqrt_ps(v20);
        v22 = _mm_andnot_ps(
                _mm_cmpleps(v20, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                    _mm_mul_ps(v21, *(__m128 *)_xmm)),
                  v20));
        if ( v22.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0)) )
        {
          v24 = *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v16);
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
                    *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17),
                    *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17),
                    201),
                  v24),
                _mm_mul_ps(*(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17), v25));
        v27 = _mm_shuffle_ps(v26, v26, 201);
        v28 = _mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm);
        v29 = _mm_mul_ps(*(__m128 *)&retaddr[8 * v17], v27);
        v30 = _mm_sub_ps(_mm_mul_ps(v25, v27), _mm_mul_ps(v27, v24));
        v31 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                _mm_shuffle_ps(v29, v29, 170));
        v32 = _mm_mul_ps(*(__m128 *)&retaddr[8 * v17], _mm_shuffle_ps(v30, v30, 201));
        v33 = _mm_rcp_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                  _mm_shuffle_ps(v32, v32, 170)));
        v34 = _mm_cmpleps((__m128)0i64, v33);
        v35 = _mm_mul_ps(v33, v31);
        v36 = _mm_or_ps(_mm_cmpltps(*(__m128 *)_xmm, v35), _mm_cmpnleps(v28, v35));
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
        v33.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(v34, v41);
        v42 = _mm_add_ps(
                *(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v16),
                *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v16));
        LODWORD(v81) = v33.m128_i32[0] | v40.m128_i32[0];
        v43 = _mm_mul_ps(v42, v42);
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                _mm_shuffle_ps(v43, v43, 170));
        v45 = _mm_rsqrt_ps(v44);
        v46 = _mm_andnot_ps(
                _mm_cmpleps(v44, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                    _mm_mul_ps(v45, *(__m128 *)_xmm)),
                  v44));
        if ( v46.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0)) )
        {
          v48 = *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v16);
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
                    *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17),
                    *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17),
                    201),
                  v48),
                _mm_mul_ps(v49, *(__m128 *)((char *)&v5->m_rotation.m_col0.m_quad + 8 * v17)));
        v51 = _mm_shuffle_ps(v50, v50, 201);
        v52 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v17), v51);
        v53 = _mm_sub_ps(_mm_mul_ps(v49, v51), _mm_mul_ps(v51, v48));
        v54 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170));
        v55 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v17), _mm_shuffle_ps(v53, v53, 201));
        v56 = _mm_rcp_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)));
        v57 = _mm_cmpleps((__m128)0i64, v56);
        v58 = _mm_mul_ps(v56, v54);
        v59 = _mm_or_ps(_mm_cmpltps(*(__m128 *)_xmm, v58), _mm_cmpnleps(v28, v58));
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
        LODWORD(v80) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                v57,
                                                _mm_add_ps(
                                                  _mm_or_ps(_mm_and_ps(v54, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                  v63)) | v63.m128_i32[0] & v57.m128_i32[0];
        if ( !*v7 )
        {
          *(float *)(v13 + v8) = v81;
          *v7 = 1;
        }
        v64 = *(__m128 **)(v9 + 56);
        v65 = *(__m128 **)(v9 + 48);
        v66 = *(float **)&v95->m_subStepDeltaTime.m_storage;
        v67 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v65[5]);
        *((_DWORD *)v66 + 13) = v10;
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
        *((__m128 *)v66 + 1) = v70;
        v72 = _mm_mul_ps(_mm_mul_ps(v70, v70), v64[3]);
        *(_QWORD *)&output.m_tau.m_storage = *(_QWORD *)(*(_QWORD *)&v95->m_subStepInvDeltaTime.m_storage + v11);
        v73 = _mm_add_ps(v72, v71);
        v74 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                  _mm_shuffle_ps(v73, v73, 170)),
                *(__m128 *)&epsilon);
        v75 = _mm_rcp_ps(v74);
        *(__m128 *)v66 = _mm_shuffle_ps(
                           v69,
                           _mm_unpackhi_ps(
                             v69,
                             _mm_mul_ps(
                               _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0),
                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v75, v74)), v75))),
                           196);
        output.m_targetPosition.m_storage = v66[3];
        v88 = v80 - *(float *)(v13 + v8);
        v89 = *(float *)(v13 + v8) - v81;
        hkCalcMotorData(v14, (hkpConstraintMotorInput *)&output, &output);
        v76 = *(float **)&v95->m_subStepDeltaTime.m_storage;
        v9 = vars0;
        v71.m128_f32[0] = output.m_targetPosition.m_storage * *(float *)(vars0 + 8);
        *v76 = **(float **)&v95->m_subStepDeltaTime.m_storage + 0.00000011920929;
        v66[7] = v71.m128_f32[0];
        v5 = v94;
        *(_BYTE *)v76 = 15;
        v76 += 16;
        *(v76 - 8) = output.m_maxForce.m_storage * *(float *)(v9 + 4);
        v74.m128_f32[0] = output.m_minForce.m_storage * *(float *)(v9 + 4);
        *(_QWORD *)&v95->m_subStepDeltaTime.m_storage = v76;
        *(v76 - 7) = v74.m128_f32[0];
        *(v76 - 6) = output.m_targetVelocity.m_storage;
        *(_QWORD *)(v76 - 5) = *(_QWORD *)&output.m_tau.m_storage;
        if ( v80 != *(float *)(v13 + v8) )
          *(float *)(v13 + v8) = v80;
      }
      else
      {
        v77 = *(_QWORD *)&v95->m_subStepDeltaTime.m_storage + 16i64;
        *(_BYTE *)(v77 - 12) = 2;
        *(float *)(v77 - 16) = *(float *)(v77 - 16) + 0.00000011920929;
        *(_BYTE *)(v77 - 16) = 3;
        *(_QWORD *)&v95->m_subStepDeltaTime.m_storage = v77;
      }
      v79 += 16i64;
      ++v10;
      ++v12;
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
void __fastcall JacobianBuilder::buildJacobianFromLinFrictionAtom_hkpConstraintQueryIn_(hkpLinFrictionConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryIn *v5; // r10
  float v6; // xmm7_4
  hkVector4f v7; // xmm4
  __int64 v8; // rax
  hkpVelocityAccumulator *v9; // rcx
  hkVector4f v10; // xmm1
  __m128 v11; // xmm3
  hkpVelocityAccumulator *v12; // rax
  hkpJacobianSchema *v13; // r8
  struct hkpConstraintRuntime *v14; // rdx
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  float *v31; // rcx
  float v32; // xmm7_4
  hkpJacobianSchema *v33; // rax
  float v34; // [rsp+30h] [rbp+8h]

  v5 = in;
  if ( atom->m_isEnabled && (v6 = atom->m_maxFrictionForce, v6 > 0.0) )
  {
    v7.m_quad = (__m128)baseA->m_translation;
    v8 = (unsigned __int8)atom->m_frictionAxis;
    v9 = in->m_bodyB.m_storage;
    v10.m_quad = (__m128)baseA->m_translation;
    v34 = in->m_virtMassFactor.m_storage;
    v11 = *(&baseB->m_rotation.m_col0.m_quad + v8);
    v12 = in->m_bodyA.m_storage;
    v13 = out->m_jacobianSchemas.m_storage;
    v14 = out->m_constraintRuntime.m_storage;
    v15 = _mm_shuffle_ps(v11, v11, 201);
    *(__m128 *)v13 = v11;
    v16 = _mm_sub_ps(v10.m_quad, v12->m_scratch3.m_quad);
    v17 = _mm_sub_ps(v7.m_quad, v9->m_scratch3.m_quad);
    v18 = _mm_sub_ps(_mm_mul_ps(v15, v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v11));
    v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v11), _mm_mul_ps(v15, v17));
    v20 = _mm_shuffle_ps(v18, v18, 201);
    v21 = _mm_shuffle_ps(v19, v19, 201);
    v22 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v12->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v12->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v12->m_scratch2.m_quad));
    *(__m128 *)&v13[16] = v22;
    v23 = v22;
    v24 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v9->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v9->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v9->m_scratch2.m_quad));
    *(__m128 *)&v13[32] = v24;
    v25 = v9->m_invMasses.m_quad;
    v26 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v24, v24), v25), _mm_mul_ps(_mm_mul_ps(v22, v22), v12->m_invMasses.m_quad));
    v27 = _mm_shuffle_ps(
            v26,
            _mm_unpackhi_ps(v26, _mm_max_ps(_mm_add_ps(v25, v12->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
    v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28);
    v30 = _mm_rcp_ps(v29);
    *(__m128 *)&v13[32] = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, v29), 196);
    *(__m128 *)&v13[16] = _mm_shuffle_ps(
                            v23,
                            _mm_unpackhi_ps(
                              v23,
                              _mm_mul_ps(
                                _mm_shuffle_ps((__m128)LODWORD(v34), (__m128)LODWORD(v34), 0),
                                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v30, v29)), v30))),
                            196);
    *(__m128 *)v13 = _mm_shuffle_ps(
                       *(__m128 *)v13,
                       _mm_unpackhi_ps(
                         *(__m128 *)v13,
                         _mm_mul_ps(
                           _mm_shuffle_ps(
                             (__m128)LODWORD(v5->m_rhsFactor.m_storage),
                             (__m128)LODWORD(v5->m_rhsFactor.m_storage),
                             0),
                           _mm_shuffle_ps((__m128)*((unsigned int *)v14 + 1), (__m128)*((unsigned int *)v14 + 1), 0))),
                       196);
    v31 = (float *)out->m_jacobianSchemas.m_storage;
    out->m_jacobianSchemas.m_storage += 64;
    v32 = v6 * v5->m_microStepDeltaTime.m_storage;
    *v31 = *v31 + 0.00000011920929;
    v31[12] = v32;
    *(_BYTE *)v31 = 9;
  }
  else
  {
    v33 = out->m_jacobianSchemas.m_storage + 16;
    v33[-12] = (hkpJacobianSchema)2;
    *(float *)&v33[-16] = *(float *)&v33[-16] + 0.00000011920929;
    v33[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v33;
  }
}

// File Line: 1292
// RVA: 0xDD6EC0
void __fastcall JacobianBuilder::buildJacobianFromWheelFrictionAtom_hkpConstraintQueryIn_(hkpWheelFrictionConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkTransformf *v5; // rbx
  hkpVelocityAccumulator *v6; // r10
  hkpVelocityAccumulator *v7; // r9
  hkVector4f v8; // xmm5
  __m128 v9; // xmm7
  __m128 v10; // xmm9
  __m128 v11; // xmm2
  __m128 v12; // ST20_16
  __m128 v13; // ST10_16
  __m128 v14; // xmm1
  __m128 v15; // xmm15
  __m128 *v16; // rax
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm4
  __m128 v44; // xmm7
  __m128 v45; // xmm4
  __m128 v46; // xmm7
  __m128 v47; // xmm5
  __m128 v48; // xmm6
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm8
  hkpJacobianSchema *v52; // rax
  float v53; // [rsp+E0h] [rbp+8h]
  float v54; // [rsp+E0h] [rbp+8h]

  v5 = baseB;
  if ( atom->m_isEnabled && atom->m_maxFrictionForce > 0.0 )
  {
    v6 = in->m_bodyA.m_storage;
    v7 = in->m_bodyB.m_storage;
    v8.m_quad = (__m128)baseA->m_translation;
    v53 = in->m_virtMassFactor.m_storage;
    v9 = v7->m_invMasses.m_quad;
    v10 = v6->m_invMasses.m_quad;
    v11 = *(&v5->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_forwardAxis);
    v12 = _mm_sub_ps(v8.m_quad, v7->m_scratch3.m_quad);
    v13 = _mm_sub_ps(v8.m_quad, v6->m_scratch3.m_quad);
    v14 = _mm_shuffle_ps(v11, v11, 201);
    v15 = *(&v5->m_rotation.m_col0.m_quad + (unsigned __int8)atom->m_sideAxis);
    v16 = (__m128 *)out->m_jacobianSchemas.m_storage;
    v17 = _mm_sub_ps(_mm_mul_ps(v13, v14), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v11));
    v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11), _mm_mul_ps(v14, v12));
    *v16 = v11;
    v19 = _mm_shuffle_ps(v17, v17, 201);
    v20 = _mm_shuffle_ps(v18, v18, 201);
    v21 = _mm_max_ps(_mm_add_ps(v10, v9), (__m128)xmmword_141A712D0);
    v22 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v6->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v6->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v6->m_scratch2.m_quad));
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v7->m_scratch2.m_quad));
    v24 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v22, v22), v10), _mm_mul_ps(_mm_mul_ps(v23, v23), v9));
    v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, v21), 196);
    v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 177), v26);
    v16[2] = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v27), 196);
    v28 = _mm_rcp_ps(v27);
    v29 = _mm_unpackhi_ps(
            v22,
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(v53), (__m128)LODWORD(v53), 0),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v27)), v28)));
    v30 = _mm_shuffle_ps(v15, v15, 201);
    v16[1] = _mm_shuffle_ps(v22, v29, 196);
    v22.m128_f32[0] = in->m_frictionRhsFactor.m_storage * 0.0;
    v54 = in->m_virtMassFactor.m_storage;
    HIDWORD(v16->m128_u64[1]) = v22.m128_i32[0];
    v16[3] = v15;
    v31 = _mm_sub_ps(_mm_mul_ps(v13, v30), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v15));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v15), _mm_mul_ps(v12, v30));
    v34 = _mm_shuffle_ps(v33, v33, 201);
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v6->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v6->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v6->m_scratch2.m_quad));
    v36 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v7->m_scratch2.m_quad));
    v37 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v36, v36), v9), _mm_mul_ps(_mm_mul_ps(v35, v35), v10));
    v38 = _mm_shuffle_ps(v37, _mm_unpackhi_ps(v37, v21), 196);
    v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
    v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 177), v39);
    v41 = _mm_rcp_ps(v40);
    v16[5] = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v40), 196);
    v39.m128_i32[0] = LODWORD(in->m_virtMassFactor.m_storage);
    v16[4] = _mm_shuffle_ps(
               v35,
               _mm_unpackhi_ps(
                 v35,
                 _mm_mul_ps(
                   _mm_shuffle_ps((__m128)LODWORD(v54), (__m128)LODWORD(v54), 0),
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v40)), v41))),
               196);
    v16[3].m128_i32[3] = v22.m128_i32[0];
    v42 = _mm_mul_ps(v16[3], *v16);
    v43 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v16[5], v16[2]), v9), _mm_mul_ps(_mm_mul_ps(v16[4], v16[1]), v10)),
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), v42), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), v42)));
    v44 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
            _mm_shuffle_ps(v43, v43, 170));
    v45 = _mm_shuffle_ps(v16[5], v16[5], 255);
    v46 = _mm_mul_ps(v44, _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0));
    v47 = v16[2];
    v48 = _mm_shuffle_ps(v47, v47, 255);
    v49 = _mm_sub_ps(_mm_mul_ps(v45, v48), _mm_mul_ps(v46, v46));
    v50 = _mm_rcp_ps(v49);
    v51 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v50, v49)), v50),
            _mm_shuffle_ps((__m128)v39.m128_u32[0], (__m128)v39.m128_u32[0], 0));
    v16[2] = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v16[2], _mm_mul_ps(v51, v45)), 196);
    v16[5] = _mm_shuffle_ps(v16[5], _mm_unpackhi_ps(v16[5], _mm_mul_ps(v51, v48)), 196);
    v16[6].m128_u64[1] = (unsigned __int64)atom;
    v16 += 7;
    v16[-1].m128_f32[0] = (float)(0.0 - v46.m128_f32[0]) * v51.m128_f32[0];
    v39.m128_f32[0] = atom->m_maxFrictionForce * in->m_microStepDeltaTime.m_storage;
    out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v16;
    v16[-1].m128_i32[1] = v39.m128_i32[0];
    v16[-7].m128_f32[0] = v16[-7].m128_f32[0] + 0.00000011920929;
    v16[-7].m128_i8[0] = 43;
  }
  else
  {
    v52 = out->m_jacobianSchemas.m_storage + 16;
    v52[-12] = 0;
    *(float *)&v52[-16] = *(float *)&v52[-16] + 0.00000011920929;
    v52[-16] = (hkpJacobianSchema)3;
    out->m_jacobianSchemas.m_storage = v52;
  }
}

// File Line: 1334
// RVA: 0xDD29B0
void __fastcall JacobianBuilder::hkPulleyConstraintBuildJacobian(hkpPulleyConstraintInfo *pulleyInput, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v3; // r10
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
  __m128 v14; // xmm9
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  float v20; // ST7C_4
  float v21; // ST70_4
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  float v25; // ST78_4
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm10
  __m128 v41; // xmm7
  __m128 v42; // xmm10
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm7
  __m128 v48; // xmm1
  float v49; // xmm0_4

  v3 = in->m_bodyB.m_storage;
  v4 = out->m_jacobianSchemas.m_storage;
  v5.m_quad = (__m128)pulleyInput->m_positionB;
  v6.m_quad = (__m128)pulleyInput->m_pulleyPivotA;
  v7 = in->m_bodyA.m_storage;
  v8.m_quad = (__m128)pulleyInput->m_positionA;
  v9 = _mm_sub_ps(pulleyInput->m_positionB.m_quad, pulleyInput->m_pulleyPivotB.m_quad);
  v10 = _mm_sub_ps(pulleyInput->m_pulleyPivotA.m_quad, pulleyInput->m_positionA.m_quad);
  v11 = _mm_mul_ps(v10, v10);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) <= 0.00000011920929 )
  {
    v14 = transform.m_quad;
  }
  else
  {
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_rsqrt_ps(v12);
    v14 = _mm_mul_ps(
            v10,
            _mm_andnot_ps(
              _mm_cmpleps(v12, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                _mm_mul_ps(*(__m128 *)_xmm, v13))));
  }
  v15 = _mm_mul_ps(v9, v9);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170))) <= 0.00000011920929 )
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
              _mm_cmpleps(v16, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                _mm_mul_ps(*(__m128 *)_xmm, v17))));
  }
  v19 = _mm_sub_ps(v5.m_quad, v3->m_scratch3.m_quad);
  v20 = in->m_virtMassFactor.m_storage;
  v21 = pulleyInput->m_ropeLength.m_storage;
  v22 = _mm_shuffle_ps(
          (__m128)LODWORD(pulleyInput->m_leverageOnBodyB.m_storage),
          (__m128)LODWORD(pulleyInput->m_leverageOnBodyB.m_storage),
          0);
  v23 = _mm_sub_ps(v8.m_quad, v7->m_scratch3.m_quad);
  v24 = _mm_mul_ps(v22, v18);
  v25 = in->m_subStepInvDeltaTime.m_storage;
  *(__m128 *)&v4[16] = v24;
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v14));
  v27 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v24);
  v28 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v19);
  v29 = _mm_shuffle_ps(v26, v26, 201);
  v30 = v3->m_invMasses.m_quad;
  v31 = _mm_sub_ps(v27, v28);
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v7->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v7->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v7->m_scratch2.m_quad));
  v33 = _mm_shuffle_ps(v31, v31, 201);
  v34 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v3->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v3->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v3->m_scratch2.m_quad));
  v35 = v7->m_invMasses.m_quad;
  *(__m128 *)&v4[48] = v34;
  v36 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v34, v34), v30), _mm_mul_ps(_mm_mul_ps(v32, v32), v35));
  v37 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), _mm_mul_ps(v22, v22)), _mm_shuffle_ps(v35, v35, 255)),
            *(__m128 *)&epsilon),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
            _mm_shuffle_ps(v36, v36, 170)));
  v38 = _mm_rcp_ps(v37);
  v39 = _mm_sub_ps(v5.m_quad, pulleyInput->m_pulleyPivotB.m_quad);
  out->m_jacobianSchemas.m_storage = v4 + 64;
  v40 = _mm_sub_ps(v6.m_quad, v8.m_quad);
  v41 = _mm_mul_ps(v39, v39);
  v42 = _mm_mul_ps(v40, v40);
  *(__m128 *)&v4[32] = _mm_shuffle_ps(
                         v32,
                         _mm_unpackhi_ps(
                           v32,
                           _mm_mul_ps(
                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v37)), v38),
                             _mm_shuffle_ps((__m128)LODWORD(v20), (__m128)LODWORD(v20), 0))),
                         196);
  v43 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)), _mm_shuffle_ps(v41, v41, 170));
  v44 = _mm_rsqrt_ps(v43);
  v45 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)), _mm_mul_ps(v44, *(__m128 *)_xmm)),
          v43);
  v46 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)), _mm_shuffle_ps(v42, v42, 170));
  v47 = _mm_andnot_ps(_mm_cmpleps(v43, (__m128)0i64), v45);
  v48 = _mm_rsqrt_ps(v46);
  v49 = *(float *)v4 + 0.00000011920929;
  *(__m128 *)v4 = _mm_shuffle_ps(
                    v14,
                    _mm_unpackhi_ps(
                      v14,
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v46, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v46), v48)),
                                  _mm_mul_ps(v48, *(__m128 *)_xmm)),
                                v46)),
                            _mm_mul_ps(v22, v47)),
                          _mm_shuffle_ps((__m128)LODWORD(v21), (__m128)LODWORD(v21), 0)),
                        _mm_shuffle_ps((__m128)LODWORD(v25), (__m128)LODWORD(v25), 0))),
                    196);
  *(float *)v4 = v49;
  *v4 = (hkpJacobianSchema)11;
}

// File Line: 1384
// RVA: 0xDD2D90
void __fastcall JacobianBuilder::buildJacobianFromPulleyAtom(hkpPulleyConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkVector4f v5; // xmm7
  hkVector4f v6; // xmm11
  hkpVelocityAccumulator *v7; // r9
  hkVector4f v8; // xmm12
  float v9; // xmm13_4
  __m128 v10; // xmm9
  float v11; // xmm14_4
  hkpJacobianSchema *v12; // rax
  hkpVelocityAccumulator *v13; // rcx
  __m128 v14; // xmm6
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm10
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // ST7C_4
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm7
  __m128 v29; // xmm11
  __m128 v30; // xmm2
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm5
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  __m128 v43; // xmm1
  __m128 v44; // xmm9
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm1
  hkpJacobianSchema *v51; // rcx

  v5.m_quad = (__m128)baseA->m_translation;
  v6.m_quad = (__m128)baseB->m_translation;
  v7 = in->m_bodyB.m_storage;
  v8.m_quad = (__m128)atom->m_fixedPivotBinWorld;
  v9 = atom->m_ropeLength;
  v10 = _mm_sub_ps(atom->m_fixedPivotAinWorld.m_quad, v5.m_quad);
  v11 = atom->m_leverageOnBodyB;
  v12 = out->m_jacobianSchemas.m_storage;
  v13 = in->m_bodyA.m_storage;
  v14 = _mm_sub_ps(v6.m_quad, v8.m_quad);
  v15 = _mm_mul_ps(v10, v10);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170))) <= 0.00000011920929 )
  {
    v18 = transform.m_quad;
  }
  else
  {
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rsqrt_ps(v16);
    v18 = _mm_mul_ps(
            v10,
            _mm_andnot_ps(
              _mm_cmpleps(v16, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                _mm_mul_ps(*(__m128 *)_xmm, v17))));
  }
  v19 = _mm_mul_ps(v14, v14);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) <= 0.00000011920929 )
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
              _mm_cmpleps(v20, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                _mm_mul_ps(*(__m128 *)_xmm, v21))));
  }
  v23 = in->m_virtMassFactor.m_storage;
  v24 = in->m_subStepInvDeltaTime.m_storage;
  *(__m128 *)v12 = v18;
  v25 = v23;
  v26 = _mm_shuffle_ps((__m128)LODWORD(v11), (__m128)LODWORD(v11), 0);
  v27 = _mm_mul_ps(v26, v22);
  *(__m128 *)&v12[16] = v27;
  v28 = _mm_sub_ps(v5.m_quad, v13->m_scratch3.m_quad);
  v29 = _mm_sub_ps(v6.m_quad, v7->m_scratch3.m_quad);
  v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v18));
  v31 = _mm_shuffle_ps(v30, v30, 201);
  v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v27), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v29));
  v33 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v13->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v13->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v13->m_scratch2.m_quad));
  v34 = _mm_shuffle_ps(v32, v32, 201);
  *(__m128 *)&v12[32] = v33;
  v35 = v33;
  v36 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v7->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v7->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v7->m_scratch2.m_quad));
  v37 = v33;
  *(__m128 *)&v12[48] = v36;
  v38 = v7->m_invMasses.m_quad;
  v39 = v13->m_invMasses.m_quad;
  v40 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v37, v37), v39), _mm_mul_ps(_mm_mul_ps(v36, v36), v38));
  v41 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 255), _mm_mul_ps(v26, v26)), _mm_shuffle_ps(v39, v39, 255)),
            *(__m128 *)&epsilon),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170)));
  v42 = _mm_mul_ps(v14, v14);
  v43 = _mm_rcp_ps(v41);
  v44 = _mm_mul_ps(v10, v10);
  *(__m128 *)&v12[32] = _mm_shuffle_ps(
                          v35,
                          _mm_unpackhi_ps(
                            v35,
                            _mm_mul_ps(
                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v41)), v43),
                              _mm_shuffle_ps((__m128)LODWORD(v25), (__m128)LODWORD(v25), 0))),
                          196);
  v45 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)), _mm_shuffle_ps(v42, v42, 170));
  v46 = _mm_rsqrt_ps(v45);
  v47 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)), _mm_mul_ps(v46, *(__m128 *)_xmm)),
          v45);
  v48 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)), _mm_shuffle_ps(v44, v44, 170));
  v49 = _mm_andnot_ps(_mm_cmpleps(v45, (__m128)0i64), v47);
  v50 = _mm_rsqrt_ps(v48);
  *(__m128 *)v12 = _mm_shuffle_ps(
                     v18,
                     _mm_unpackhi_ps(
                       v18,
                       _mm_mul_ps(
                         _mm_sub_ps(
                           _mm_add_ps(
                             _mm_andnot_ps(
                               _mm_cmpleps(v48, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v48), v50)),
                                   _mm_mul_ps(v50, *(__m128 *)_xmm)),
                                 v48)),
                             _mm_mul_ps(v26, v49)),
                           _mm_shuffle_ps((__m128)LODWORD(v9), (__m128)LODWORD(v9), 0)),
                         _mm_shuffle_ps((__m128)LODWORD(v24), (__m128)LODWORD(v24), 0))),
                     196);
  v51 = out->m_jacobianSchemas.m_storage;
  out->m_jacobianSchemas.m_storage += 64;
  *(float *)v51 = *(float *)v51 + 0.00000011920929;
  *v51 = (hkpJacobianSchema)11;
}

// File Line: 1398
// RVA: 0xDD31D0
void __fastcall JacobianBuilder::buildJacobianFromRackAndPinionAtom(hkpRackAndPinionConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkTransformf *v5; // rsi
  hkpJacobianSchema *v6; // r8
  struct hkpConstraintRuntime *v7; // rax
  __m128 v8; // xmm8
  float *v9; // rbx
  float *v10; // r11
  unsigned int *v11; // r10
  __m128 v12; // xmm10
  hkVector4f v13; // xmm11
  __m128 v14; // xmm12
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
  __m128 v28; // xmm13
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm6
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm6
  __m128 v36; // xmm7
  __m128 v37; // xmm13
  float v38; // xmm7_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  __m128i v41; // xmm6
  bool v42; // zf
  hkpVelocityAccumulator *v43; // rcx
  hkpVelocityAccumulator *v44; // rax
  __m128 v45; // xmm11
  __m128 v46; // xmm10
  __m128 v47; // xmm3
  float v48; // xmm6_4
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  float v51; // xmm6_4
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm4
  __m128 v60; // xmm3
  __m128 v61; // xmm3
  __m128 v62; // xmm0
  __m128 v63; // xmm3
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm9
  __m128 v72; // xmm2
  __m128 v73; // xmm3
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm3
  __m128 v79; // xmm3
  __m128 v80; // xmm0
  __m128 v81; // xmm2
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm0
  float v85; // xmm7_4
  __m128 v86; // xmm3
  float v87; // xmm0_4
  float v88; // xmm0_4
  float v89; // [rsp+90h] [rbp+8h]
  float v90; // [rsp+A0h] [rbp+18h]
  float outa; // [rsp+B0h] [rbp+28h]

  v5 = baseA;
  v6 = out->m_jacobianSchemas.m_storage;
  v7 = out->m_constraintRuntime.m_storage;
  v8 = 0i64;
  v9 = (float *)((char *)v7 + atom->m_memOffsetToInitialAngleOffset);
  v10 = (float *)((char *)v7 + atom->m_memOffsetToPrevAngle);
  v11 = (unsigned int *)((char *)v7 + atom->m_memOffsetToRevolutionCounter);
  out->m_jacobianSchemas.m_storage += 64;
  v12 = v5->m_translation.m_quad;
  v13.m_quad = (__m128)baseB->m_translation;
  v14 = v5->m_rotation.m_col0.m_quad;
  v15.m_quad = (__m128)baseB->m_rotation.m_col0;
  if ( atom->m_isScrew.m_bool )
  {
    v23 = _mm_mul_ps(v14, v15.m_quad);
    if ( COERCE_FLOAT((unsigned int)(2
                                   * COERCE_SIGNED_INT(
                                       (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170)))) >> 1) < COERCE_FLOAT(
                                                                                               _mm_shuffle_ps(
                                                                                                 (__m128)LODWORD(FLOAT_0_1),
                                                                                                 (__m128)LODWORD(FLOAT_0_1),
                                                                                                 0)) )
      goto LABEL_3;
    v21.m_quad = (__m128)baseB->m_rotation.m_col1;
  }
  else
  {
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 201), v14));
    v17 = _mm_shuffle_ps(v16, v16, 201);
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    if ( v19.m128_f32[0] < 1.4210855e-14 )
    {
LABEL_3:
      out->m_jacobianSchemas.m_storage = v6;
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
    v12 = _mm_add_ps(v12, v22);
    v13.m_quad = _mm_add_ps(v13.m_quad, v22);
  }
  v24 = _mm_mul_ps(v5->m_rotation.m_col1.m_quad, v21.m_quad);
  v25 = _mm_mul_ps(v5->m_rotation.m_col2.m_quad, v21.m_quad);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v27 = _mm_rcp_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170)));
  v28 = _mm_cmpleps((__m128)0i64, v27);
  v29 = _mm_mul_ps(v27, v26);
  v30 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v29), _mm_cmpltps(*(__m128 *)_xmm, v29));
  v31 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v29), v30), _mm_andnot_ps(v30, v29));
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v32, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v32, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v32, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v32, *(__m128 *)s3))),
          _mm_mul_ps(v31, *(__m128 *)t3));
  v34 = v28;
  v35 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v31, *(__m128 *)_xmm), *(__m128 *)_xmm), v33), v30),
          _mm_andnot_ps(v30, v33));
  v36 = _mm_add_ps(_mm_or_ps(_mm_and_ps(v26, *(__m128 *)_xmm), *(__m128 *)_xmm), v35);
  v35.m128_i32[0] &= v28.m128_i32[0];
  v37 = _mm_mul_ps(_mm_sub_ps(v13.m_quad, v12), v15.m_quad);
  LODWORD(outa) = *(unsigned __int128 *)&_mm_andnot_ps(v34, v36) | v35.m128_i32[0];
  v38 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170));
  if ( *v9 == 0.0 )
  {
    v39 = outa - (float)(v38 / atom->m_pinionRadiusOrScrewPitch);
    *v9 = v39;
    if ( v39 == 0.0 )
      v39 = FLOAT_1_1920929eN8;
    *v9 = v39;
    *v10 = outa;
  }
  if ( (float)(outa - *v10) > 3.1415927 )
    --*v11;
  if ( (float)(outa - *v10) < -3.1415927 )
    ++*v11;
  *v10 = outa;
  v40 = atom->m_pinionRadiusOrScrewPitch;
  v41 = _mm_cvtsi32_si128(*v11);
  v42 = atom->m_isScrew.m_bool == 0;
  v43 = in->m_bodyB.m_storage;
  v44 = in->m_bodyA.m_storage;
  *(hkVector4f *)v6 = (hkVector4f)v15.m_quad;
  v45 = _mm_sub_ps(v13.m_quad, v43->m_scratch3.m_quad);
  v46 = _mm_sub_ps(v12, v44->m_scratch3.m_quad);
  v47 = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v15.m_quad);
  v48 = (float)((float)(COERCE_FLOAT(_mm_cvtepi32_ps(v41)) * 6.2831855) + (float)(outa - *v9)) * v40;
  if ( v42 )
  {
    v49 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v8));
    v50 = _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v15.m_quad);
    v51 = v48
        * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170)));
    v52 = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 201);
    v53 = _mm_sub_ps(v47, _mm_mul_ps(v52, v45));
    v54 = _mm_sub_ps(_mm_mul_ps(v52, v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v15.m_quad));
    v55 = _mm_shuffle_ps(v53, v53, 201);
    v56 = _mm_shuffle_ps(v54, v54, 201);
    v57 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v56, v56, 85), v44->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v44->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v56, v56, 170), v44->m_scratch2.m_quad));
    v58 = v43->m_invMasses.m_quad;
    v59 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v55, v55, 85), v43->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v43->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v55, v55, 170), v43->m_scratch2.m_quad));
    v60 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v59, v59), v58), _mm_mul_ps(_mm_mul_ps(v57, v57), v44->m_invMasses.m_quad));
    v61 = _mm_shuffle_ps(
            v60,
            _mm_unpackhi_ps(v60, _mm_max_ps(_mm_add_ps(v58, v44->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 78), v61);
    v63 = _mm_shuffle_ps(
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            0);
    v64 = _mm_add_ps(_mm_shuffle_ps(v62, v62, 177), v62);
    v65 = _mm_rcp_ps(v64);
    *(__m128 *)&v6[32] = _mm_shuffle_ps(v59, _mm_unpackhi_ps(v59, v64), 196);
    v66 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v65, v64)), v65);
    v67 = (__m128)LODWORD(in->m_rhsFactor.m_storage);
    *(__m128 *)&v6[16] = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, _mm_mul_ps(v63, v66)), 196);
  }
  else
  {
    v51 = v48 * 0.15915494;
    v89 = in->m_virtMassFactor.m_storage;
    v90 = in->m_rhsFactor.m_storage;
    v68 = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 201);
    v69 = _mm_sub_ps(_mm_mul_ps(v68, v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v15.m_quad));
    v70 = _mm_sub_ps(v47, _mm_mul_ps(v68, v45));
    v71 = _mm_mul_ps(v15.m_quad, _mm_shuffle_ps((__m128)LODWORD(v40), (__m128)LODWORD(v40), 0));
    v72 = _mm_add_ps(_mm_shuffle_ps(v69, v69, 201), v71);
    v73 = _mm_sub_ps(_mm_shuffle_ps(v70, v70, 201), v71);
    v74 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v72, v72, 85), v44->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), v44->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v72, v72, 170), v44->m_scratch2.m_quad));
    v75 = v43->m_invMasses.m_quad;
    *(__m128 *)&v6[16] = v74;
    v76 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), v43->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), v43->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), v43->m_scratch2.m_quad));
    *(__m128 *)&v6[32] = v76;
    v77 = v76;
    v78 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v76, v76), v75),
            _mm_mul_ps(_mm_mul_ps(*(__m128 *)&v6[16], *(__m128 *)&v6[16]), v44->m_invMasses.m_quad));
    v79 = _mm_shuffle_ps(
            v78,
            _mm_unpackhi_ps(v78, _mm_max_ps(_mm_add_ps(v75, v44->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v80 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 78), v79);
    v81 = _mm_add_ps(_mm_shuffle_ps(v80, v80, 177), v80);
    v82 = _mm_unpackhi_ps(v76, v81);
    v83 = _mm_rcp_ps(v81);
    *(__m128 *)&v6[32] = _mm_shuffle_ps(v77, v82, 196);
    v84 = _mm_unpackhi_ps(
            *(__m128 *)&v6[16],
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v83, v81)), v83),
              _mm_shuffle_ps((__m128)LODWORD(v89), (__m128)LODWORD(v89), 0)));
    v67 = (__m128)LODWORD(v90);
    *(__m128 *)&v6[16] = _mm_shuffle_ps(*(__m128 *)&v6[16], v84, 196);
  }
  v85 = (float)(v38 - v51) * in->m_rhsFactor.m_storage;
  v86 = _mm_shuffle_ps(
          *(__m128 *)v6,
          _mm_unpackhi_ps(
            *(__m128 *)v6,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                _mm_shuffle_ps(v37, v37, 170)),
              _mm_shuffle_ps(v67, v67, 0))),
          196);
  v87 = in->m_damping.m_storage;
  *(float *)&v6[48] = in->m_tau.m_storage;
  *(float *)&v6[52] = v87;
  v88 = *(float *)v6;
  *(__m128 *)v6 = v86;
  *(float *)&v6[12] = v85;
  *(float *)v6 = v88 + 0.00000011920929;
  *v6 = (hkpJacobianSchema)7;
}

// File Line: 1568
// RVA: 0xDD38B0
void __fastcall JacobianBuilder::buildJacobianFromCogWheelAtom(hkpCogWheelConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  struct hkpConstraintRuntime *v5; // rax
  hkTransformf *v6; // rsi
  hkpJacobianSchema *v7; // r8
  float *v8; // rbx
  float *v9; // r11
  signed int *v10; // r10
  __m128 v11; // xmm6
  hkVector4f v12; // xmm4
  __m128 v13; // xmm15
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm2
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
  __m128 v76; // xmm2
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

  v5 = out->m_constraintRuntime.m_storage;
  v6 = baseA;
  v7 = out->m_jacobianSchemas.m_storage;
  v8 = (float *)((char *)v5 + atom->m_memOffsetToInitialAngleOffset);
  v9 = (float *)((char *)v5 + atom->m_memOffsetToPrevAngle);
  v10 = (signed int *)((char *)v5 + atom->m_memOffsetToRevolutionCounter);
  out->m_jacobianSchemas.m_storage += 64;
  v11 = v6->m_translation.m_quad;
  v12.m_quad = (__m128)baseB->m_rotation.m_col0;
  v13 = v6->m_rotation.m_col0.m_quad;
  v14 = _mm_sub_ps(baseB->m_translation.m_quad, v11);
  v88.m_quad = (__m128)baseB->m_rotation.m_col0;
  v15 = _mm_mul_ps(v14, v14);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170))) >= 1.4210855e-14 )
  {
    v16 = _mm_shuffle_ps(v14, v14, 201);
    v17 = _mm_shuffle_ps(v12.m_quad, v12.m_quad, 201);
    v18 = _mm_shuffle_ps(v13, v13, 201);
    v19 = _mm_sub_ps(_mm_mul_ps(v14, v18), _mm_mul_ps(v16, v13));
    v20 = _mm_sub_ps(_mm_mul_ps(v16, v12.m_quad), _mm_mul_ps(v14, v17));
    v21 = _mm_shuffle_ps(v19, v19, 201);
    v22 = _mm_shuffle_ps(v20, v20, 201);
    v23 = _mm_sub_ps(_mm_mul_ps(v21, v13), _mm_mul_ps(v21, v18));
    v24 = _mm_shuffle_ps(v23, v23, 201);
    v25 = _mm_sub_ps(_mm_mul_ps(v22, v12.m_quad), _mm_mul_ps(v17, v22));
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
      v36 = _mm_mul_ps(v6->m_rotation.m_col2.m_quad, v34);
      v37 = _mm_mul_ps(v26, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v35), _mm_mul_ps(v33, *(__m128 *)_xmm)));
      v38 = _mm_mul_ps(v6->m_rotation.m_col1.m_quad, v34);
      v39 = _mm_mul_ps(baseB->m_rotation.m_col1.m_quad, v37);
      v89 = _mm_add_ps(
              v11,
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
      v45 = _mm_cmpleps((__m128)0i64, v44);
      v46 = _mm_mul_ps(v44, v43);
      v47 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v46), _mm_cmpltps(*(__m128 *)_xmm, v46));
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
      outa = (hkpConstraintQueryOut *)(*(unsigned __int128 *)&_mm_andnot_ps(
                                                                v45,
                                                                _mm_add_ps(
                                                                  _mm_or_ps(
                                                                    _mm_and_ps(v43, *(__m128 *)_xmm),
                                                                    *(__m128 *)_xmm),
                                                                  v51)) | v51.m128_u64[0] & v45.m128_u64[0]);
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
      v57 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v13), _mm_mul_ps(v18, v34));
      v58 = _mm_shuffle_ps(v54, v54, 201);
      v59 = _mm_shuffle_ps(v57, v57, 201);
      v60 = _mm_mul_ps(v58, v59);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 170))) > 0.0 )
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
      v69 = _mm_mul_ps(v61, _mm_andnot_ps(_mm_cmpleps(v65, (__m128)0i64), v67));
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
      v76 = v63->m_invMasses.m_quad;
      v77 = _mm_shuffle_ps(v75, v75, 201);
      v78 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v77, v77, 85), v63->m_scratch1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v63->m_scratch0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v77, v77, 170), v63->m_scratch2.m_quad));
      v79 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v78, v78), v76), _mm_mul_ps(_mm_mul_ps(v74, v74), v62->m_invMasses.m_quad));
      v80 = _mm_shuffle_ps(
              v79,
              _mm_unpackhi_ps(v79, _mm_max_ps(_mm_add_ps(v76, v62->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
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
void __fastcall JacobianBuilder::_hkpBeginConstraints(hkpConstraintQueryIn *in, hkpConstraintQueryOut *out, hkpSolverResults *sr, int solverResultStriding)
{
  hkpJacobianSchema *v4; // rbx
  unsigned int v5; // er10
  hkpConstraintInstance *v6; // r11
  float v7; // xmm0_4

  v4 = out->m_jacobianSchemas.m_storage;
  v5 = in->m_accumulatorBIndex.m_storage;
  v6 = in->m_constraintInstance.m_storage;
  v7 = *(float *)out->m_jacobianSchemas.m_storage;
  *(_WORD *)&v4[4] = in->m_accumulatorAIndex.m_storage;
  *(float *)v4 = v7 + 0.00000011920929;
  *(_WORD *)&v4[6] = v5;
  *(_QWORD *)&v4[8] = sr;
  *v4 = (hkpJacobianSchema)1;
  v4[1] = (hkpJacobianSchema)solverResultStriding;
  *(_QWORD *)&v4[16] = v6;
  out->m_jacobianSchemas.m_storage = v4 + 32;
}

