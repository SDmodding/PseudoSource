// File Line: 36
// RVA: 0x13279B0
void __fastcall hkCalcMotorData(
        hkpConstraintMotor *someMotor,
        hkpConstraintMotorInput *input,
        hkpConstraintMotorOutput *output)
{
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  hkpConstraintQueryStepInfo *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm3_4
  float m_internalSolverData; // xmm6_4
  int vfptr; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  hkpConstraintQueryStepInfo *m_storage; // rax
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm4_4

  v4 = someMotor->m_type.m_storage - 1;
  if ( !v4 )
  {
    m_storage = input->m_stepInfo.m_storage;
    v16 = m_storage->m_frameDeltaTime.m_storage;
    v17 = (float)(input->m_positionError.m_storage * *(float *)&someMotor[1].m_type.m_storage) * v16;
    v18 = v16 * *((float *)&someMotor[1].m_type + 1);
    v19 = input->m_positionError.m_storage - v17;
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v19)) >> 1) <= v18 )
    {
      v20 = input->m_positionError.m_storage;
    }
    else
    {
      if ( v19 <= 0.0 )
        LODWORD(v18) ^= _xmm[0];
      v20 = v17 + v18;
    }
    m_internalSolverData = input->m_lastResults.m_internalSolverData;
    v14 = *(float *)(&someMotor[1].m_referenceCount + 1);
    v21 = v20;
    v13 = *((float *)&someMotor[1].vfptr + 1);
    vfptr = LODWORD(v13) ^ _xmm[0];
    v12 = *(float *)&someMotor[1].m_memSizeAndFlags;
    v8 = (float)(fminf(
                   fmaxf(
                     v21,
                     COERCE_FLOAT(((unsigned int)(2 * LODWORD(input->m_positionError.m_storage)) >> 1) ^ _xmm[0])
                   - m_internalSolverData),
                   COERCE_FLOAT((unsigned int)(2 * LODWORD(input->m_positionError.m_storage)) >> 1)
                 - m_internalSolverData)
               + input->m_deltaTarget.m_storage)
       * m_storage->m_frameInvDeltaTime.m_storage;
    goto LABEL_17;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    if ( someMotor[1].m_type.m_storage )
      v8 = (float)(input->m_positionError.m_storage + input->m_deltaTarget.m_storage)
         * input->m_stepInfo.m_storage->m_frameInvDeltaTime.m_storage;
    else
      v8 = *(float *)(&someMotor[1].m_referenceCount + 1);
    m_internalSolverData = input->m_lastResults.m_internalSolverData;
    v13 = *((float *)&someMotor[1].vfptr + 1);
    v12 = *(float *)&someMotor[1].m_memSizeAndFlags;
    v14 = v12;
    vfptr = (int)someMotor[1].vfptr;
    goto LABEL_17;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    v7 = input->m_stepInfo.m_storage;
    v8 = 0.0;
    v9 = 1.0 / input->m_effMass.m_storage;
    m_internalSolverData = input->m_positionError.m_storage + input->m_deltaTarget.m_storage;
    vfptr = (int)someMotor[1].vfptr;
    v12 = fminf(
            fmaxf(
              (float)((float)(v7->m_subStepDeltaTime.m_storage * *(float *)&someMotor[1].m_memSizeAndFlags)
                    * v7->m_subStepDeltaTime.m_storage)
            * v9,
              0.0),
            1.0);
    v13 = *((float *)&someMotor[1].vfptr + 1);
    v14 = fminf(
            fmaxf((float)(v7->m_subStepDeltaTime.m_storage * *(float *)(&someMotor[1].m_referenceCount + 1)) * v9, 0.0),
            1.0);
LABEL_17:
    output->m_targetVelocity.m_storage = v8;
    output->m_targetPosition.m_storage = m_internalSolverData;
    output->m_maxForce.m_storage = v13;
    LODWORD(output->m_minForce.m_storage) = vfptr;
    output->m_tau.m_storage = v12;
    output->m_damping.m_storage = v14;
    return;
  }
  if ( v6 == 1 )
    (*(void (__fastcall **)(hkpConstraintMotor *, hkpConstraintMotorInput *, hkpConstraintMotorOutput *))&someMotor[1].m_memSizeAndFlags)(
      someMotor,
      input,
      output);
}

// File Line: 166
// RVA: 0x1327BD0
void __fastcall hk1dLinearVelocityMotorBeginJacobian(
        hkVector4f *directionOfConstraint,
        hkVector4f *pivot,
        hkpConstraintQueryIn *in,
        hkp1Lin2AngJacobian *jac,
        hkp1dBilateralConstraintStatus *statusOut)
{
  __m128 m_quad; // xmm3
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v7; // r10
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2

  m_quad = directionOfConstraint->m_quad;
  m_storage = in->m_bodyB.m_storage;
  v7 = in->m_bodyA.m_storage;
  v8 = pivot->m_quad;
  jac->m_linear0 = (hkVector4f)directionOfConstraint->m_quad;
  v9 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v10 = _mm_sub_ps(v8, m_storage->m_scratch3.m_quad);
  v11 = _mm_sub_ps(v8, v7->m_scratch3.m_quad);
  v12 = _mm_mul_ps(v9, v10);
  v13 = _mm_sub_ps(_mm_mul_ps(v9, v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), m_quad));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), m_quad), v12);
  v16 = v7->m_invMasses.m_quad;
  v17 = _mm_shuffle_ps(v15, v15, 201);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), m_storage->m_scratch2.m_quad));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v7->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v7->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v7->m_scratch2.m_quad));
  v20 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v18, v18), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v19, v19), v16));
  v21 = _mm_shuffle_ps(
          v20,
          _mm_unpackhi_ps(v20, _mm_max_ps(_mm_add_ps(v16, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
  v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22);
  v24 = _mm_rcp_ps(v23);
  jac->m_angular[1].m_quad = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, v23), 196);
  jac->m_angular[0].m_quad = _mm_shuffle_ps(
                               v19,
                               _mm_unpackhi_ps(
                                 v19,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v23)), v24))),
                               196);
  LODWORD(statusOut->m_effMass.m_storage) = jac->m_angular[0].m_quad.m128_u32[3];
}

// File Line: 178
// RVA: 0x1327D20
void __fastcall hk1dLinearVelocityMotorCommitJacobian(
        hkp1dConstraintMotorInfo *info,
        hkpConstraintQueryIn *in,
        hkp1Lin2AngJacobian *jac,
        hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *m_storage; // r8

  jac->m_linear0.m_quad.m128_f32[3] = in->m_subStepInvDeltaTime.m_storage * info->m_targetPosition.m_storage;
  m_storage = out->m_jacobianSchemas.m_storage;
  *(float *)m_storage = *(float *)out->m_jacobianSchemas.m_storage + 0.00000011920929;
  *m_storage = (hkpJacobianSchema)10;
  *(float *)&m_storage[48] = info->m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(float *)&m_storage[52] = info->m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(float *)&m_storage[56] = info->m_targetVelocity.m_storage;
  *(float *)&m_storage[60] = info->m_tau.m_storage;
  *(float *)&m_storage[64] = info->m_damping.m_storage;
  out->m_jacobianSchemas.m_storage = m_storage + 80;
}

