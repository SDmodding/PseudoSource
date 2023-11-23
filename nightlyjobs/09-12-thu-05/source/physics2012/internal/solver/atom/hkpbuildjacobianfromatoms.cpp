// File Line: 49
// RVA: 0xDD4040
void __fastcall hkUndoBeginConstraints(hkpConstraintQueryOut *out)
{
  out->m_jacobianSchemas.m_storage -= 32;
}

// File Line: 56
// RVA: 0xDD4050
void __fastcall callBridgeFromAtom(
        hkpBridgeConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  out->m_jacobianSchemas.m_storage -= 32;
  ((void (__fastcall *)(hkpConstraintData *, hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkTransformf *))atom->m_buildJacobianFunc)(
    atom->m_constraintData,
    in,
    out,
    baseB);
}

// File Line: 71
// RVA: 0xDD4070
void __fastcall hkInitHeader(
        hkpConstraintQueryIn *in,
        hkpSolverResults *results,
        hkpJacobianSchema resultStriding,
        hkpConstraintQueryOut *out)
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
  *(_QWORD *)&m_storage[8] = results;
  *m_storage = (hkpJacobianSchema)1;
  m_storage[1] = resultStriding;
  *(_QWORD *)&m_storage[16] = v6;
  out->m_jacobianSchemas.m_storage = m_storage + 32;
}

// File Line: 92
// RVA: 0xDD40D0
hkpModifierConstraintAtom *__fastcall getContactAtom(hkpModifierConstraintAtom *atom)
{
  do
    atom = (hkpModifierConstraintAtom *)atom->m_child;
  while ( atom->m_type.m_storage >= 0x1Eu );
  return atom;
}

// File Line: 154
// RVA: 0xDD40F0
void __fastcall buildJacobianFromSoftContactModifier(
        hkpSoftContactModifierConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *m_storage; // rax
  int m_childSize; // r14d
  __int128 v8; // xmm1
  float m_tau; // xmm2_4
  __int128 v10; // xmm0
  hkpSoftContactModifierConstraintAtom *m_child; // r9
  hkSimdFloat32 v12; // xmm0
  hkTransformf *v13; // rax
  float v14; // xmm2_4
  unsigned __int64 v15; // r11
  __int64 v16; // rsi
  __int64 v17; // rdi
  __int64 v18; // rcx
  float *v19; // rax
  unsigned __int64 v20; // rbx
  float v21; // xmm0_4
  __int64 v22; // rcx
  float v23; // xmm0_4
  __int64 v24; // rcx
  float v25; // xmm0_4
  __int64 v26; // rcx
  float v27; // xmm0_4
  float *v28; // rcx
  float *v29; // r10
  unsigned __int64 v30; // r11
  float v31; // xmm0_4
  hkpSimpleContactConstraintAtom *v32; // rcx
  hkpConstraintQueryIn ina; // [rsp+20h] [rbp-98h] BYREF

  out->m_jacobianSchemas.m_storage -= 32;
  m_storage = in->m_bodyA.m_storage;
  m_childSize = atom->m_childSize;
  v8 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  m_tau = atom->m_tau;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v10 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v8;
  m_child = atom;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = v10;
  v12.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  ina.m_bodyA.m_storage = m_storage;
  ina.m_bodyB.m_storage = in->m_bodyB.m_storage;
  v13 = in->m_transformA.m_storage;
  *(float *)&v8 = m_tau * in->m_tau.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v12.m_real;
  v12.m_real.m128_f32[0] = m_tau;
  ina.m_transformA.m_storage = v13;
  v14 = m_tau * in->m_damping.m_storage;
  v12.m_real.m128_f32[0] = v12.m_real.m128_f32[0] * in->m_virtMassFactor.m_storage;
  ina.m_transformB.m_storage = in->m_transformB.m_storage;
  ina.m_constraintInstance.m_storage = in->m_constraintInstance.m_storage;
  ina.m_violatedConstraints.m_storage = in->m_violatedConstraints.m_storage;
  ina.m_accumulatorAIndex.m_storage = in->m_accumulatorAIndex.m_storage;
  ina.m_accumulatorBIndex.m_storage = in->m_accumulatorBIndex.m_storage;
  ina.m_beginConstraints = in->m_beginConstraints;
  LODWORD(ina.m_virtMassFactor.m_storage) = v12.m_real.m128_i32[0];
  LODWORD(ina.m_tau.m_storage) = v8;
  ina.m_damping.m_storage = v14;
  do
    m_child = (hkpSoftContactModifierConstraintAtom *)m_child->m_child;
  while ( m_child->m_type.m_storage >= 0x1Eu );
  v15 = *((unsigned __int16 *)&m_child->hkpConstraintAtom + 2);
  v16 = *((unsigned __int8 *)&m_child->hkpConstraintAtom + 10);
  v17 = 0i64;
  v18 = (__int64)(&m_child->m_tau + 8 * *((unsigned __int16 *)&m_child->hkpConstraintAtom + 3));
  if ( v15 >= 4 )
  {
    v19 = (float *)&m_child[1].m_pad[3];
    v20 = ((v15 - 4) >> 2) + 1;
    v17 = 4 * v20;
    do
    {
      v21 = (float)((float)((float)(atom->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / atom->m_tau)
          + *(v19 - 8);
      if ( v21 < *(float *)(v18 + 24) )
        *(float *)(v18 + 24) = v21;
      v22 = (int)v16 + v18;
      v23 = (float)((float)((float)(atom->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / atom->m_tau)
          + *v19;
      if ( v23 < *(float *)(v22 + 24) )
        *(float *)(v22 + 24) = v23;
      v24 = (int)v16 + v22;
      v25 = (float)((float)((float)(atom->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / atom->m_tau)
          + v19[8];
      if ( v25 < *(float *)(v24 + 24) )
        *(float *)(v24 + 24) = v25;
      v26 = (int)v16 + v24;
      v27 = (float)((float)((float)(atom->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / atom->m_tau)
          + v19[16];
      if ( v27 < *(float *)(v26 + 24) )
        *(float *)(v26 + 24) = v27;
      v18 = (int)v16 + v26;
      v19 += 32;
      --v20;
    }
    while ( v20 );
  }
  if ( v17 < (__int64)v15 )
  {
    v28 = (float *)(v18 + 24);
    v29 = (float *)(&m_child[1].hkpConstraintAtom + 16 * v17 + 6);
    v30 = v15 - v17;
    do
    {
      v31 = (float)((float)((float)(atom->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / atom->m_tau)
          + *v29;
      if ( v31 < *v28 )
        *v28 = v31;
      v28 = (float *)((char *)v28 + v16);
      v29 += 8;
      --v30;
    }
    while ( v30 );
  }
  v32 = (hkpSimpleContactConstraintAtom *)atom->m_child;
  if ( v32->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(v32, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact(v32, m_childSize, &ina, out);
}

// File Line: 224
// RVA: 0xDD4380
void __fastcall buildJacobianFromIgnoreModifier(
        hkpIgnoreModifierConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  out->m_jacobianSchemas.m_storage -= 32;
}

// File Line: 231
// RVA: 0xDD4390
void __fastcall buildJacobianFromMassChangerModifier(
        hkpMassChangerModifierConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *m_storage; // rax
  __int128 v6; // xmm1
  hkpSimpleContactConstraintAtom *m_child; // rsi
  int m_childSize; // r14d
  __int128 v9; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  hkSimdFloat32 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __m128 v17; // xmm3
  __int128 m_scratch3; // xmm1
  hkpVelocityAccumulator *v19; // rax
  __m128 v20; // xmm2
  __int128 v21; // xmm1
  hkpConstraintQueryIn ina; // [rsp+20h] [rbp-E0h] BYREF
  __int128 v23[3]; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f invMassA; // [rsp+E0h] [rbp-20h] BYREF
  hkVector4f v25; // [rsp+F0h] [rbp-10h]
  hkVector4f v26; // [rsp+100h] [rbp+0h]
  hkVector4f v27; // [rsp+110h] [rbp+10h]
  __int128 v28; // [rsp+120h] [rbp+20h]
  __int128 v29[3]; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f invMassB; // [rsp+160h] [rbp+60h] BYREF
  hkVector4f v31; // [rsp+170h] [rbp+70h]
  hkVector4f v32; // [rsp+180h] [rbp+80h]
  hkVector4f v33; // [rsp+190h] [rbp+90h]
  __int128 v34; // [rsp+1A0h] [rbp+A0h]

  m_storage = in->m_bodyA.m_storage;
  v6 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  m_child = (hkpSimpleContactConstraintAtom *)atom->m_child;
  m_childSize = atom->m_childSize;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v9 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v6;
  v11 = *(_OWORD *)&in->m_bodyA.m_storage;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = v9;
  v12 = *(_OWORD *)&in->m_transformA.m_storage;
  *(_OWORD *)&ina.m_bodyA.m_storage = v11;
  v13 = *(_OWORD *)&in->m_tau.m_storage;
  *(_OWORD *)&ina.m_transformA.m_storage = v12;
  v14.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  *(_OWORD *)&ina.m_tau.m_storage = v13;
  v15 = *(_OWORD *)&in->m_constraintInstance.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v14.m_real;
  v16 = *(_OWORD *)&in->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&ina.m_constraintInstance.m_storage = v15;
  *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = v16;
  v23[0] = *(_OWORD *)&m_storage->m_type.m_storage;
  v23[1] = (__int128)m_storage->m_linearVel;
  v23[2] = (__int128)m_storage->m_angularVel;
  invMassA.m_quad = (__m128)m_storage->m_invMasses;
  v17 = _mm_mul_ps(invMassA.m_quad, atom->m_factorA.m_quad);
  v25.m_quad = (__m128)m_storage->m_scratch0;
  v26.m_quad = (__m128)m_storage->m_scratch1;
  v27.m_quad = (__m128)m_storage->m_scratch2;
  m_scratch3 = (__int128)m_storage->m_scratch3;
  v19 = in->m_bodyB.m_storage;
  v28 = m_scratch3;
  v29[0] = *(_OWORD *)&v19->m_type.m_storage;
  v29[1] = (__int128)v19->m_linearVel;
  v29[2] = (__int128)v19->m_angularVel;
  invMassB.m_quad = (__m128)v19->m_invMasses;
  v20 = _mm_mul_ps(invMassB.m_quad, atom->m_factorB.m_quad);
  v31.m_quad = (__m128)v19->m_scratch0;
  v32.m_quad = (__m128)v19->m_scratch1;
  v33.m_quad = (__m128)v19->m_scratch2;
  v21 = (__int128)v19->m_scratch3;
  invMassA.m_quad = v17;
  ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)v23;
  ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)v29;
  v34 = v21;
  invMassB.m_quad = v20;
  hkSetInvMassBuildJacobian(&invMassA, &invMassB, out);
  if ( m_child->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(m_child, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact(m_child, m_childSize, &ina, out);
  hkSetInvMassBuildJacobian(&in->m_bodyA.m_storage->m_invMasses, &in->m_bodyB.m_storage->m_invMasses, out);
}

// File Line: 295
// RVA: 0xDD4540
void __fastcall buildJacobianFromCenterOfMassChangerModifier(
        hkpCenterOfMassChangerModifierConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkTransformf *m_storage; // rax
  __int128 v6; // xmm1
  hkpSimpleContactConstraintAtom *m_child; // rdi
  int m_childSize; // esi
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  __int128 v12; // xmm1
  hkSimdFloat32 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  hkVector4f v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  hkTransformf *v21; // rax
  __m128 v22; // xmm4
  hkVector4f v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  hkpVelocityAccumulator *v28; // rax
  __m128 v29; // xmm2
  hkpVelocityAccumulator *v30; // rax
  __m128 v31; // xmm1
  hkMatrix3f v32; // [rsp+20h] [rbp-E0h] BYREF
  hkSimdFloat32 scale; // [rsp+50h] [rbp-B0h] BYREF
  hkMatrix3f v34; // [rsp+60h] [rbp-A0h] BYREF
  hkMatrix3f aTb; // [rsp+90h] [rbp-70h] BYREF
  hkMatrix3f angToLinVelA; // [rsp+C0h] [rbp-40h] BYREF
  hkMatrix3f angToLinVelB; // [rsp+F0h] [rbp-10h] BYREF
  hkVector4f v38; // [rsp+120h] [rbp+20h] BYREF
  hkVector4f r; // [rsp+130h] [rbp+30h] BYREF
  __int128 v40; // [rsp+140h] [rbp+40h] BYREF
  __m128 m_quad; // [rsp+150h] [rbp+50h]
  __m128 v42; // [rsp+160h] [rbp+60h]
  hkVector4f v43; // [rsp+170h] [rbp+70h]
  hkRotationf cTb; // [rsp+180h] [rbp+80h] BYREF
  __m128 v45; // [rsp+1B0h] [rbp+B0h]
  __int128 v46; // [rsp+1C0h] [rbp+C0h] BYREF
  __m128 v47; // [rsp+1D0h] [rbp+D0h]
  __m128 v48; // [rsp+1E0h] [rbp+E0h]
  hkVector4f v49; // [rsp+1F0h] [rbp+F0h]
  hkRotationf v50; // [rsp+200h] [rbp+100h] BYREF
  __m128 v51; // [rsp+230h] [rbp+130h]
  hkpConstraintQueryIn ina; // [rsp+240h] [rbp+140h] BYREF

  m_storage = in->m_transformA.m_storage;
  v6 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  m_child = (hkpSimpleContactConstraintAtom *)atom->m_child;
  m_childSize = atom->m_childSize;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v9 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v6;
  v10 = *(_OWORD *)&in->m_bodyA.m_storage;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = v9;
  v11 = *(_OWORD *)&in->m_transformA.m_storage;
  *(_OWORD *)&ina.m_bodyA.m_storage = v10;
  v12 = *(_OWORD *)&in->m_tau.m_storage;
  *(_OWORD *)&ina.m_transformA.m_storage = v11;
  v13.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  *(_OWORD *)&ina.m_tau.m_storage = v12;
  v14 = *(_OWORD *)&in->m_constraintInstance.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v13.m_real;
  v15 = *(_OWORD *)&in->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&ina.m_constraintInstance.m_storage = v14;
  v16.m_quad = (__m128)atom->m_displacementA;
  *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = v15;
  v17 = _mm_shuffle_ps(v16.m_quad, v16.m_quad, 85);
  v18 = _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 0), m_storage->m_rotation.m_col0.m_quad);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 170), m_storage->m_rotation.m_col2.m_quad);
  v20 = _mm_mul_ps(v17, m_storage->m_rotation.m_col1.m_quad);
  v21 = in->m_transformB.m_storage;
  v22 = _mm_add_ps(_mm_add_ps(v20, v18), v19);
  v23.m_quad = (__m128)atom->m_displacementB;
  v24 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 85);
  r.m_quad = v22;
  v25 = _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 0), v21->m_rotation.m_col0.m_quad);
  v26 = _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 170), v21->m_rotation.m_col2.m_quad);
  v27 = _mm_mul_ps(v24, v21->m_rotation.m_col1.m_quad);
  v28 = in->m_bodyA.m_storage;
  v38.m_quad = _mm_add_ps(_mm_add_ps(v27, v25), v26);
  v40 = *(_OWORD *)&v28->m_type.m_storage;
  m_quad = v28->m_linearVel.m_quad;
  v42 = v28->m_angularVel.m_quad;
  v43.m_quad = (__m128)v28->m_invMasses;
  cTb.m_col0 = v28->m_scratch0;
  cTb.m_col1 = v28->m_scratch1;
  cTb.m_col2 = v28->m_scratch2;
  v29 = v28->m_scratch3.m_quad;
  v30 = in->m_bodyB.m_storage;
  v45 = v29;
  v46 = *(_OWORD *)&v30->m_type.m_storage;
  v47 = v30->m_linearVel.m_quad;
  v48 = v30->m_angularVel.m_quad;
  v49.m_quad = (__m128)v30->m_invMasses;
  v50.m_col0 = v30->m_scratch0;
  v50.m_col1 = v30->m_scratch1;
  v50.m_col2 = v30->m_scratch2;
  v31 = v30->m_scratch3.m_quad;
  v45 = _mm_add_ps(v29, v22);
  ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v40;
  v51 = _mm_add_ps(v31, v38.m_quad);
  ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v46;
  hkMatrix3f::setCrossSkewSymmetric(&v34, &r);
  hkMatrix3f::setCrossSkewSymmetric(&v32, &v38);
  aTb = v34;
  hkMatrix3f::setMulInverse(&v34, &aTb, &cTb);
  aTb = v32;
  hkMatrix3f::setMulInverse(&v32, &aTb, &v50);
  scale.m_real = g_vectorfConstants[0];
  angToLinVelA = v34;
  hkMatrix3f::mul(&angToLinVelA, &scale);
  angToLinVelB = v32;
  hkMatrix3f::mul(&angToLinVelB, &scale);
  m_quad = _mm_add_ps(
             m_quad,
             _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), angToLinVelA.m_col1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), angToLinVelA.m_col0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), angToLinVelA.m_col2.m_quad)));
  v47 = _mm_add_ps(
          v47,
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), angToLinVelB.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), angToLinVelB.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), angToLinVelB.m_col2.m_quad)));
  hkSetCenterOfMassBuildJacobian(&angToLinVelA, &angToLinVelB, out);
  if ( m_child->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(m_child, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact(m_child, m_childSize, &ina, out);
  hkSetCenterOfMassBuildJacobian(&v34, &v32, out);
}

// File Line: 386
// RVA: 0xDD48C0
void __fastcall buildJacobianFromViscousSurfaceModifier(
        hkpViscousSurfaceModifierConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkpConstraintQueryOut *out)
{
  hkpViscousSurfaceModifierConstraintAtom *v5; // rdi
  int m_childSize; // esi
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  hkSimdFloat32 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  hkpSimpleContactConstraintAtom *m_child; // rcx
  hkpConstraintQueryIn ina; // [rsp+20h] [rbp-98h] BYREF

  v5 = atom;
  out->m_jacobianSchemas.m_storage -= 32;
  m_childSize = atom->m_childSize;
  v7 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v8 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v7;
  v9 = *(_OWORD *)&in->m_bodyA.m_storage;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = v8;
  *(_OWORD *)&ina.m_transformA.m_storage = *(_OWORD *)&in->m_transformA.m_storage;
  v10.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  *(_OWORD *)&ina.m_bodyA.m_storage = v9;
  v11 = *(_OWORD *)&in->m_tau.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v10.m_real;
  v12 = *(_OWORD *)&in->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&ina.m_tau.m_storage = v11;
  v13 = *(_OWORD *)&in->m_constraintInstance.m_storage;
  *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = v12;
  *(_OWORD *)&ina.m_constraintInstance.m_storage = v13;
  do
    atom = (hkpViscousSurfaceModifierConstraintAtom *)atom->m_child;
  while ( atom->m_type.m_storage >= 0x1Eu );
  hkSimpleContactConstraintDataAddALittleSurfaceViscosity((hkpSimpleContactConstraintDataInfo *)&atom->m_modifierAtomSize);
  m_child = (hkpSimpleContactConstraintAtom *)v5->m_child;
  if ( m_child->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(m_child, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact(m_child, m_childSize, &ina, out);
}

// File Line: 425
// RVA: 0xDD4990
void __fastcall buildJacobianFromMovingSurfaceModifier(
        hkpMovingSurfaceModifierConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB)
{
  __int128 v4; // xmm1
  hkpConstraintAtom *m_child; // rsi
  hkVector4f v7; // xmm4
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  hkSimdFloat32 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  hkpJacobianSchema *m_storage; // r10
  unsigned int v15; // edx
  hkpConstraintInstance *v16; // rcx
  hkpJacobianSchema v17; // r9
  __int64 v18; // r8
  unsigned int v19; // eax
  bool v20; // dl
  hkpVelocityAccumulator *v21; // rcx
  __int128 m_scratch3; // xmm1
  hkpVelocityAccumulator *v23; // rcx
  __m128 v24; // xmm2
  int v25; // ebx
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  hkVector4f deltaVel; // [rsp+20h] [rbp-D8h] BYREF
  char v29; // [rsp+30h] [rbp-C8h] BYREF
  char v30; // [rsp+31h] [rbp-C7h]
  unsigned int m_deactivationClass; // [rsp+34h] [rbp-C4h]
  float m_gravityFactor; // [rsp+38h] [rbp-C0h]
  __m128 m_quad; // [rsp+40h] [rbp-B8h]
  hkVector4f v34; // [rsp+50h] [rbp-A8h]
  hkVector4f v35; // [rsp+60h] [rbp-98h]
  char v36[24]; // [rsp+70h] [rbp-88h]
  hkVector4f v37; // [rsp+88h] [rbp-70h]
  __int128 v38; // [rsp+98h] [rbp-60h]
  hkpConstraintQueryIn ina; // [rsp+A8h] [rbp-50h] BYREF
  hkpConstraintQueryOut *v40; // [rsp+178h] [rbp+80h]

  v4 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  m_child = atom->m_child;
  v7.m_quad = (__m128)atom->m_velocity;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = *(_OWORD *)&in->m_rhsFactor.m_storage;
  v8 = *(_OWORD *)&in->m_transformA.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v4;
  v9 = *(_OWORD *)&in->m_bodyA.m_storage;
  *(_OWORD *)&ina.m_transformA.m_storage = v8;
  v10.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  *(_OWORD *)&ina.m_bodyA.m_storage = v9;
  v11 = *(_OWORD *)&in->m_tau.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v10.m_real;
  v12 = *(_OWORD *)&in->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&ina.m_tau.m_storage = v11;
  v13 = *(_OWORD *)&in->m_constraintInstance.m_storage;
  v40->m_jacobianSchemas.m_storage -= 32;
  m_storage = v40->m_jacobianSchemas.m_storage;
  v15 = in->m_accumulatorBIndex.m_storage;
  v16 = in->m_constraintInstance.m_storage;
  *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = v12;
  *(_OWORD *)&ina.m_constraintInstance.m_storage = v13;
  v17 = (hkpJacobianSchema)m_child[5].m_type.m_storage;
  *(float *)&v12 = *(float *)m_storage + 0.00000011920929;
  v18 = (__int64)&m_child[16 * m_child[3].m_type.m_storage + 24];
  v19 = in->m_accumulatorAIndex.m_storage;
  *(_WORD *)&m_storage[6] = v15;
  *(_DWORD *)m_storage = v12;
  *(_WORD *)&m_storage[4] = v19;
  *(_QWORD *)&m_storage[8] = v18;
  *m_storage = (hkpJacobianSchema)1;
  *(_QWORD *)&m_storage[16] = v16;
  m_storage[1] = v17;
  v40->m_jacobianSchemas.m_storage = m_storage + 32;
  v20 = in->m_accumulatorAIndex.m_storage == 0;
  if ( in->m_accumulatorAIndex.m_storage )
  {
    v21 = in->m_bodyA.m_storage;
    v29 = v21->m_type.m_storage;
    v30 = v21->m_context.m_storage;
    m_deactivationClass = v21->m_deactivationClass;
    m_gravityFactor = v21->m_gravityFactor;
    m_quad = v21->m_linearVel.m_quad;
    v34.m_quad = (__m128)v21->m_angularVel;
    v35.m_quad = (__m128)v21->m_invMasses;
    *(hkVector4f *)v36 = v21->m_scratch0;
    *(hkVector4f *)&v36[8] = v21->m_scratch1;
    v37.m_quad = (__m128)v21->m_scratch2;
    m_scratch3 = (__int128)v21->m_scratch3;
    ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v29;
  }
  else
  {
    v23 = in->m_bodyB.m_storage;
    v29 = v23->m_type.m_storage;
    v30 = v23->m_context.m_storage;
    m_deactivationClass = v23->m_deactivationClass;
    m_gravityFactor = v23->m_gravityFactor;
    m_quad = v23->m_linearVel.m_quad;
    v34.m_quad = (__m128)v23->m_angularVel;
    v35.m_quad = (__m128)v23->m_invMasses;
    *(hkVector4f *)v36 = v23->m_scratch0;
    *(hkVector4f *)&v36[8] = v23->m_scratch1;
    v37.m_quad = (__m128)v23->m_scratch2;
    m_scratch3 = (__int128)v23->m_scratch3;
    ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v29;
    v7.m_quad = _mm_xor_ps(v7.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
  }
  v24 = *(__m128 *)&m_child[32].m_type.m_storage;
  v38 = m_scratch3;
  v25 = v20;
  v26 = _mm_mul_ps(v24, v7.m_quad);
  v27 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  deltaVel.m_quad = _mm_xor_ps(
                      _mm_sub_ps(
                        v7.m_quad,
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                            _mm_shuffle_ps(v26, v26, 170)),
                          *(__m128 *)&m_child[32].m_type.m_storage)),
                      v27);
  hkAddVelocityBuildJacobian(&deltaVel, v20, v40);
  m_quad = _mm_add_ps(m_quad, deltaVel.m_quad);
  hkSimpleContactConstraintDataBuildJacobian((hkpSimpleContactConstraintAtom *)m_child, &ina, 0, v40);
  deltaVel.m_quad = _mm_xor_ps(v27, deltaVel.m_quad);
  hkAddVelocityBuildJacobian(&deltaVel, v25, v40);
}

// File Line: 535
// RVA: 0xDD4C10
void __fastcall setupStabilizationFromAtom_outOfLine(
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

// File Line: 546
// RVA: 0xDCFF90
void __fastcall buildSchemaFromBallSocketAtom(
        hkpBallSocketConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkTransformf *baseA,
        hkTransformf *baseB,
        hkVector4f *vLocalArmA,
        hkVector4f *vLocalArmB,
        hkSimdFloat32 *maxAngularImpulse,
        hkSimdFloat32 *maxLinearImpulse,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v13; // rcx
  hkpJacobianSchema *v14; // r10
  __m128 v15; // xmm1
  hkpVelocityAccumulator *v16; // rax
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm10
  __m128 v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm13
  __m128 v26; // xmm13
  __m128 v27; // xmm2
  __m128 v28; // xmm12
  __m128 v29; // xmm13
  __m128 v30; // xmm12
  __m128 v31; // xmm12
  __m128 m_inertiaStabilizationFactor_low; // xmm4
  __m128 v33; // xmm12
  __m128 v34; // xmm4
  __m128 v35; // xmm8
  __m128 v36; // xmm6
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm9
  __m128 v40; // xmm3
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm5
  __m128 v45; // xmm2
  __m128 v46; // xmm9
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm8
  __m128 v50; // xmm5
  __m128 v51; // xmm4
  hkpViolatedConstraintArray *v52; // rcx
  __m128 v53; // xmm2
  __m128 v54; // xmm7
  __m128 v55; // xmm2
  unsigned __int32 v56; // eax
  float v57; // xmm0_4
  unsigned __int16 EncodedFloat; // ax
  float v59; // xmm0_4
  hkpVelocityAccumulator *m_storage; // r9
  hkpVelocityAccumulator *v61; // r10
  float m_breachImpulse; // xmm12_4
  __m128 v63; // xmm7
  __m128 m_quad; // xmm3
  hkpJacobianSchema *v65; // r8
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  hkVector4f v68; // xmm8
  __m128 v69; // xmm9
  __m128 v70; // xmm0
  __m128 v71; // xmm8
  __m128 v72; // xmm1
  __m128 v73; // xmm4
  __m128 v74; // xmm11
  __m128 v75; // xmm2
  __m128 v76; // xmm0
  __m128 v77; // xmm3
  __m128 v78; // xmm6
  __m128 v79; // xmm1
  __m128 v80; // xmm4
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm5
  __m128 v84; // xmm0
  __m128 v85; // xmm6
  hkpViolatedConstraintArray *v86; // rcx
  __m128 v87; // xmm6
  __m128 v88; // xmm2
  unsigned __int32 v89; // eax
  hkVector4f *v90; // rcx
  __m128 *v91; // rax
  float v92; // xmm0_4
  __m128 v93; // xmm2
  __m128 v94; // xmm4
  __m128 v95; // xmm5
  __m128 v96; // xmm3
  __m128 v97; // xmm5
  __m128 v98; // xmm5
  __m128 v99; // xmm2
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm5
  __m128 v103; // xmm4
  __m128 v104; // xmm2
  __m128 v105; // xmm3
  __m128 v106; // xmm3
  __m128 v107; // xmm0
  __m128 v108; // xmm1
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm4
  __m128 v112; // xmm0
  __m128 v113; // xmm1
  float v114; // [rsp+28h] [rbp-F0h]

  if ( atom->m_solvingMethod.m_storage == 1 )
  {
    EncodedFloat = hkUFloat8::getEncodedFloat(atom->m_velocityStabilizationFactor.m_value);
    if ( EncodedFloat )
      LODWORD(v59) = (EncodedFloat + 243712) << 12;
    else
      v59 = 0.0;
    m_storage = in->m_bodyA.m_storage;
    v61 = in->m_bodyB.m_storage;
    m_breachImpulse = atom->m_breachImpulse;
    v63 = _mm_sub_ps(baseA->m_translation.m_quad, m_storage->m_scratch3.m_quad);
    m_quad = m_storage->m_scratch2.m_quad;
    v65 = out->m_jacobianSchemas.m_storage;
    v66 = _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(v59 * in->m_rhsFactor.m_storage),
            (__m128)COERCE_UNSIGNED_INT(v59 * in->m_rhsFactor.m_storage),
            0);
    v67 = _mm_rcp_ps(v66);
    v68.m_quad = (__m128)baseB->m_translation;
    v69 = _mm_sub_ps(v68.m_quad, baseA->m_translation.m_quad);
    v70 = _mm_mul_ps(v67, v66);
    v71 = _mm_sub_ps(v68.m_quad, v61->m_scratch3.m_quad);
    v72 = _mm_unpacklo_ps(m_storage->m_scratch0.m_quad, m_storage->m_scratch1.m_quad);
    v73 = _mm_shuffle_ps(_mm_unpackhi_ps(m_storage->m_scratch0.m_quad, m_storage->m_scratch1.m_quad), m_quad, 228);
    v74 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v70), v67);
    v75 = _mm_movelh_ps(v72, m_quad);
    v76 = _mm_shuffle_ps(_mm_movehl_ps(v75, v72), m_quad, 212);
    v77 = v61->m_scratch2.m_quad;
    v78 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad, 85), v76),
              _mm_mul_ps(_mm_shuffle_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad, 0), v75)),
            _mm_mul_ps(_mm_shuffle_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad, 170), v73));
    v79 = v61->m_scratch0.m_quad;
    v80 = _mm_unpackhi_ps(v79, v61->m_scratch1.m_quad);
    v81 = _mm_unpacklo_ps(v79, v61->m_scratch1.m_quad);
    v82 = _mm_movelh_ps(v81, v77);
    v83 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v61->m_angularVel.m_quad, v61->m_angularVel.m_quad, 85),
                _mm_shuffle_ps(_mm_movehl_ps(v82, v81), v77, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v61->m_angularVel.m_quad, v61->m_angularVel.m_quad, 0), v82)),
            _mm_mul_ps(
              _mm_shuffle_ps(v61->m_angularVel.m_quad, v61->m_angularVel.m_quad, 170),
              _mm_shuffle_ps(v80, v77, 228)));
    v84 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v63), _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v78));
    v85 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v71), _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v83));
    v86 = in->m_violatedConstraints.m_storage;
    v87 = _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v74), v69),
            _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v74));
    if ( v86 )
    {
      v88 = _mm_mul_ps(v87, v87);
      if ( (float)((float)(_mm_shuffle_ps(v88, v88, 85).m128_f32[0] + _mm_shuffle_ps(v88, v88, 0).m128_f32[0])
                 + _mm_shuffle_ps(v88, v88, 170).m128_f32[0]) > in->m_maxConstraintViolationSqrd.m_real.m128_f32[0] )
      {
        v89 = _InterlockedExchangeAdd((volatile signed __int32 *)v86, 1u);
        if ( v89 < 0x80 )
          in->m_violatedConstraints.m_storage->m_constraints[v89] = in->m_constraintInstance.m_storage;
      }
    }
    v90 = &transform;
    v91 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
    do
    {
      v92 = in->m_virtMassFactor.m_storage;
      *(hkVector4f *)v65 = (hkVector4f)v90->m_quad;
      v114 = v92;
      v93 = _mm_sub_ps(baseA->m_translation.m_quad, m_storage->m_scratch3.m_quad);
      v94 = _mm_sub_ps(baseB->m_translation.m_quad, v61->m_scratch3.m_quad);
      v95 = _mm_shuffle_ps(v90->m_quad, v90->m_quad, 201);
      v96 = _mm_mul_ps(v95, v94);
      v97 = _mm_sub_ps(_mm_mul_ps(v95, v93), _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v90->m_quad));
      v98 = _mm_shuffle_ps(v97, v97, 201);
      v99 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v90->m_quad), v96);
      v100 = _mm_shuffle_ps(v99, v99, 201);
      v101 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), m_storage->m_scratch1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), m_storage->m_scratch0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), m_storage->m_scratch2.m_quad));
      *(__m128 *)&v65[16] = v101;
      v102 = v101;
      v103 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v100, v100, 85), v61->m_scratch1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v100, v100, 0), v61->m_scratch0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v100, v100, 170), v61->m_scratch2.m_quad));
      *(__m128 *)&v65[32] = v103;
      v104 = v61->m_invMasses.m_quad;
      v105 = _mm_add_ps(
               _mm_mul_ps(_mm_mul_ps(v101, v101), m_storage->m_invMasses.m_quad),
               _mm_mul_ps(_mm_mul_ps(v103, v103), v104));
      v106 = _mm_shuffle_ps(
               v105,
               _mm_unpackhi_ps(
                 v105,
                 _mm_max_ps(_mm_add_ps(v104, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
               196);
      v107 = _mm_add_ps(_mm_shuffle_ps(v106, v106, 78), v106);
      v108 = _mm_add_ps(_mm_shuffle_ps(v107, v107, 177), v107);
      v109 = _mm_rcp_ps(v108);
      *(__m128 *)&v65[32] = _mm_shuffle_ps(v103, _mm_unpackhi_ps(v103, v108), 196);
      *(__m128 *)&v65[16] = _mm_shuffle_ps(
                              v102,
                              _mm_unpackhi_ps(
                                v102,
                                _mm_mul_ps(
                                  _mm_shuffle_ps((__m128)LODWORD(v114), (__m128)LODWORD(v114), 0),
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v109, v108)), v109))),
                              196);
      v110 = _mm_mul_ps(_mm_sub_ps(baseB->m_translation.m_quad, baseA->m_translation.m_quad), v90->m_quad);
      v111 = _mm_shuffle_ps(
               *(__m128 *)v65,
               _mm_unpackhi_ps(
                 *(__m128 *)v65,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                     _mm_shuffle_ps(v110, v110, 170)),
                   _mm_shuffle_ps(
                     (__m128)LODWORD(in->m_rhsFactor.m_storage),
                     (__m128)LODWORD(in->m_rhsFactor.m_storage),
                     0))),
               196);
      *(__m128 *)v65 = v111;
      v112 = _mm_and_ps(*v91, v87);
      v113 = _mm_or_ps(_mm_shuffle_ps(v112, v112, 78), v112);
      *(__m128 *)v65 = _mm_shuffle_ps(
                         v111,
                         _mm_unpackhi_ps(
                           v111,
                           _mm_mul_ps(
                             _mm_or_ps(_mm_shuffle_ps(v113, v113, 177), v113),
                             _mm_shuffle_ps(
                               (__m128)LODWORD(in->m_rhsFactor.m_storage),
                               (__m128)LODWORD(in->m_rhsFactor.m_storage),
                               0))),
                         196);
      if ( m_breachImpulse == 3.40282e38 )
      {
        *(float *)v65 = *(float *)v65 + 0.00000011920929;
        *v65 = (hkpJacobianSchema)5;
      }
      else
      {
        *(float *)&v65[44] = m_breachImpulse;
        *(float *)v65 = *(float *)v65 + 0.00000011920929;
        *v65 = (hkpJacobianSchema)6;
      }
      ++v91;
      v65 += 48;
      ++v90;
    }
    while ( (__int64)v91 < (__int64)&xmmword_141687F30 );
    out->m_jacobianSchemas.m_storage = v65;
  }
  else
  {
    v13 = in->m_bodyB.m_storage;
    v14 = out->m_jacobianSchemas.m_storage;
    v15 = _mm_mul_ps(vLocalArmA->m_quad, vLocalArmA->m_quad);
    v16 = in->m_bodyA.m_storage;
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v18 = _mm_mul_ps(vLocalArmB->m_quad, vLocalArmB->m_quad);
    v19 = _mm_cmplt_ps((__m128)xmmword_141A712D0, v17);
    v20 = _mm_rsqrt_ps(v17);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v22 = _mm_cmplt_ps((__m128)xmmword_141A712D0, v21);
    v23 = _mm_andnot_ps(
            _mm_cmple_ps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v17), v20)),
              _mm_mul_ps(*(__m128 *)_xmm, v20)));
    v24 = _mm_rsqrt_ps(v21);
    v25 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(vLocalArmA->m_quad, v23), v19), _mm_andnot_ps(v19, transform.m_quad));
    v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, _mm_mul_ps(v23, v17)), 196);
    v27 = _mm_andnot_ps(
            _mm_cmple_ps(v21, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v21), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24)));
    v28 = _mm_mul_ps(vLocalArmB->m_quad, v27);
    *(__m128 *)&v14[16] = v26;
    v29 = _mm_shuffle_ps(v26, v26, 255);
    v30 = _mm_or_ps(_mm_and_ps(v28, v22), _mm_andnot_ps(v22, transform.m_quad));
    v31 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, _mm_mul_ps(v27, v21)), 196);
    m_inertiaStabilizationFactor_low = (__m128)LODWORD(atom->m_inertiaStabilizationFactor);
    *(__m128 *)&v14[32] = v31;
    v33 = _mm_shuffle_ps(v31, v31, 255);
    v34 = _mm_shuffle_ps(m_inertiaStabilizationFactor_low, m_inertiaStabilizationFactor_low, 0);
    v35 = v16->m_invMasses.m_quad;
    v36 = v13->m_invMasses.m_quad;
    v37 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_max_ps(
                _mm_shuffle_ps(v35, v35, 170),
                _mm_max_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0))),
              v29),
            v34);
    v38 = _mm_rcp_ps(v37);
    v39 = _mm_cmplt_ps(*(__m128 *)&epsilon, v37);
    v40 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_max_ps(
                _mm_shuffle_ps(v36, v36, 170),
                _mm_max_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0))),
              v33),
            v34);
    v41 = _mm_cmplt_ps(*(__m128 *)&epsilon, v40);
    v42 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v37)), v38);
    v43 = _mm_rcp_ps(v40);
    v44 = _mm_and_ps(v39, _mm_mul_ps(v42, _mm_shuffle_ps(v35, v35, 255)));
    v45 = _mm_shuffle_ps((__m128)LODWORD(atom->m_breachImpulse), (__m128)LODWORD(atom->m_breachImpulse), 0);
    v46 = _mm_or_ps(_mm_andnot_ps(v39, query.m_quad), v44);
    v47 = 0i64;
    v47.m128_f32[0] = (float)(atom->m_enableLinearImpulseLimit.m_bool != 0);
    v48 = _mm_cmple_ps((__m128)xmmword_141A712B0, v45);
    v49 = _mm_or_ps(
            _mm_andnot_ps(v41, query.m_quad),
            _mm_and_ps(
              v41,
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v40)), v43), _mm_shuffle_ps(v36, v36, 255))));
    v50 = _mm_cmpneq_ps(_mm_shuffle_ps(v47, v47, 0), (__m128)0i64);
    v51 = _mm_or_ps(_mm_andnot_ps(v48, _mm_mul_ps(v45, v45)), _mm_and_ps(v48, v45));
    v52 = in->m_violatedConstraints.m_storage;
    v53 = _mm_sub_ps(baseA->m_translation.m_quad, baseB->m_translation.m_quad);
    v54 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0),
            _mm_shuffle_ps(
              (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
              (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
              0));
    *(__m128 *)v14 = _mm_shuffle_ps(
                       v51,
                       _mm_unpackhi_ps(
                         v51,
                         _mm_or_ps(
                           _mm_andnot_ps(v50, (__m128)xmmword_141A712A0),
                           _mm_and_ps(maxLinearImpulse->m_real, v50))),
                       180);
    *(__m128 *)&v14[48] = _mm_movelh_ps(
                            _mm_unpacklo_ps(v54, maxLinearImpulse->m_real),
                            _mm_unpacklo_ps(
                              _mm_mul_ps(_mm_min_ps(v46, query.m_quad), v29),
                              _mm_mul_ps(_mm_min_ps(v49, query.m_quad), v33)));
    if ( v52 )
    {
      v55 = _mm_mul_ps(v53, v53);
      if ( (float)((float)(_mm_shuffle_ps(v55, v55, 85).m128_f32[0] + _mm_shuffle_ps(v55, v55, 0).m128_f32[0])
                 + _mm_shuffle_ps(v55, v55, 170).m128_f32[0]) > in->m_maxConstraintViolationSqrd.m_real.m128_f32[0] )
      {
        v56 = _InterlockedExchangeAdd((volatile signed __int32 *)v52, 1u);
        if ( v56 < 0x80 )
          in->m_violatedConstraints.m_storage->m_constraints[v56] = in->m_constraintInstance.m_storage;
      }
    }
    v57 = *(float *)v14 + 0.00000011920929;
    out->m_jacobianSchemas.m_storage = v14 + 64;
    *(float *)v14 = v57;
    *v14 = (hkpJacobianSchema)16;
  }
}= v14 + 64;
    *(float *)v14 = v57;
    *v14 = (hkpJacobianSchema)16;
  }
}

// File Line: 622
// RVA: 0xDCFA90
void __fastcall hkpBeginConstraints(
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

// File Line: 629
// RVA: 0xDCFAF0
void __fastcall hk1dAngularLimitBuildJacobian(
        hkp1dAngularLimitInfo *info,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v4; // r9
  hkpJacobianSchema *v5; // r10
  __m128 m_storage_low; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  float v14; // xmm0_4

  m_storage = in->m_bodyA.m_storage;
  v4 = in->m_bodyB.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  m_storage_low = (__m128)LODWORD(info->m_tau.m_storage);
  v7 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
         info->m_constrainedDofW.m_quad);
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(info->m_constrainedDofW.m_quad, info->m_constrainedDofW.m_quad, 85),
             m_storage->m_scratch1.m_quad),
           _mm_mul_ps(
             _mm_shuffle_ps(info->m_constrainedDofW.m_quad, info->m_constrainedDofW.m_quad, 0),
             m_storage->m_scratch0.m_quad)),
         _mm_mul_ps(
           _mm_shuffle_ps(info->m_constrainedDofW.m_quad, info->m_constrainedDofW.m_quad, 170),
           m_storage->m_scratch2.m_quad));
  *(__m128 *)v5 = v8;
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v4->m_scratch1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v4->m_scratch0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v4->m_scratch2.m_quad));
  v10 = v8;
  *(__m128 *)&v5[16] = v9;
  v11 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v8, v8), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v9, v9), v4->m_invMasses.m_quad));
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)),
          *(__m128 *)&epsilon);
  v13 = _mm_rcp_ps(v12);
  *(__m128 *)v5 = _mm_shuffle_ps(
                    v10,
                    _mm_unpackhi_ps(
                      v10,
                      _mm_mul_ps(
                        _mm_shuffle_ps(m_storage_low, m_storage_low, 0),
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v12)), v13))),
                    196);
  v13.m128_i32[0] = LODWORD(info->m_max.m_storage);
  v9.m128_i32[0] = LODWORD(in->m_subStepInvDeltaTime.m_storage) ^ _xmm[0];
  v12.m128_f32[0] = (float)(info->m_min.m_storage * v9.m128_f32[0]) * m_storage_low.m128_f32[0];
  *(float *)&v5[28] = v9.m128_f32[0] * info->m_computedAngle.m_storage;
  out->m_jacobianSchemas.m_storage = v5 + 48;
  v14 = *(float *)v5 + 0.00000011920929;
  *(_DWORD *)&v5[32] = v12.m128_i32[0];
  *(_DWORD *)&v5[40] = m_storage_low.m128_i32[0];
  *(float *)v5 = v14;
  *(float *)&v5[36] = (float)(v13.m128_f32[0] * v9.m128_f32[0]) * m_storage_low.m128_f32[0];
  *v5 = (hkpJacobianSchema)13;
}

// File Line: 634
// RVA: 0xDCFE20
void __fastcall hk1dAngularVelocityMotorBeginJacobian(
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

// File Line: 639
// RVA: 0xDCFF20
void __fastcall hk1dAngularVelocityMotorCommitJacobian(
        hkp1dConstraintMotorInfo *info,
        hkpConstraintQueryIn *in,
        hkp2AngJacobian *jac,
        hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *m_storage; // r8

  jac->m_angular[1].m_quad.m128_f32[3] = in->m_subStepInvDeltaTime.m_storage * info->m_targetPosition.m_storage;
  m_storage = out->m_jacobianSchemas.m_storage;
  *(float *)m_storage = *(float *)out->m_jacobianSchemas.m_storage + 0.00000011920929;
  *m_storage = (hkpJacobianSchema)15;
  *(float *)&m_storage[32] = info->m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(float *)&m_storage[36] = info->m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(float *)&m_storage[40] = info->m_targetVelocity.m_storage;
  *(float *)&m_storage[44] = info->m_tau.m_storage;
  *(float *)&m_storage[48] = info->m_damping.m_storage;
  out->m_jacobianSchemas.m_storage = m_storage + 64;
}

// File Line: 644
// RVA: 0xDCFC50
void __fastcall hk1dAngularFrictionBuildJacobian(
        hkp1dAngularFrictionInfo *info,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkVector4f *m_storage; // rbx
  hkpJacobianSchema *v4; // r9
  int v5; // r11d
  __m128 v7; // xmm4
  float *p_m_internalSolverData; // rdi
  __m128 v9; // xmm5
  __m128 m_quad; // xmm2
  hkpVelocityAccumulator *v11; // rax
  hkpVelocityAccumulator *v12; // rcx
  __m128 v13; // xmm0
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1

  m_storage = info->m_constrainedDofW.m_storage;
  v4 = out->m_jacobianSchemas.m_storage;
  v5 = 0;
  if ( info->m_numFriction.m_storage > 0 )
  {
    v7 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
    p_m_internalSolverData = &info->m_lastSolverResults.m_storage->m_internalSolverData;
    v9 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      m_quad = m_storage->m_quad;
      v11 = in->m_bodyA.m_storage;
      v12 = in->m_bodyB.m_storage;
      v13 = m_storage->m_quad;
      v14 = m_storage->m_quad;
      v4 += 48;
      ++m_storage;
      p_m_internalSolverData += 4;
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v11->m_scratch1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v13, m_quad, 0), v11->m_scratch0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v11->m_scratch2.m_quad));
      *(__m128 *)&v4[-48] = v15;
      v16 = _mm_xor_ps(v14, v9);
      v17 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v12->m_scratch1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v12->m_scratch0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12->m_scratch2.m_quad));
      v18 = v15;
      *(__m128 *)&v4[-32] = v17;
      v19 = _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(v15, v15), v11->m_invMasses.m_quad),
              _mm_mul_ps(_mm_mul_ps(v17, v17), v12->m_invMasses.m_quad));
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170)),
              *(__m128 *)&epsilon);
      v21 = _mm_rcp_ps(v20);
      *(__m128 *)&v4[-48] = _mm_shuffle_ps(
                              v18,
                              _mm_unpackhi_ps(
                                v18,
                                _mm_mul_ps(v7, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v20)), v21))),
                              196);
      v21.m128_f32[0] = *(float *)&v4[-48] + 0.00000011920929;
      *(__m128 *)&v4[-32] = _mm_shuffle_ps(
                              *(__m128 *)&v4[-32],
                              _mm_unpackhi_ps(
                                *(__m128 *)&v4[-32],
                                _mm_mul_ps(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    0),
                                  _mm_shuffle_ps(
                                    (__m128)*((unsigned int *)p_m_internalSolverData - 4),
                                    (__m128)*((unsigned int *)p_m_internalSolverData - 4),
                                    0))),
                              196);
      v13.m128_f32[0] = in->m_microStepDeltaTime.m_storage * info->m_maxFrictionTorque.m_storage;
      *(_DWORD *)&v4[-12] = v5;
      *(_DWORD *)&v4[-48] = v21.m128_i32[0];
      v4[-48] = (hkpJacobianSchema)14;
      ++v5;
      *(_DWORD *)&v4[-16] = v13.m128_i32[0];
    }
    while ( v5 < info->m_numFriction.m_storage );
  }
  out->m_jacobianSchemas.m_storage = v4;
}

// File Line: 652
// RVA: 0xDC9FE0
void __fastcall hkSolverBuildJacobianFromAtomsNotContact(
        hkpConstraintAtom *atoms,
        int sizeOfAllAtoms,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkTransformf *m_storage; // rax
  __m128 v5; // xmm7
  hkpConstraintQueryOut *v7; // rbx
  hkpConstraintAtom *v8; // r10
  hkpConstraintAtom *v9; // rdi
  hkVector4f v10; // xmm1
  __m128 v11; // xmm11
  hkTransformf *v12; // rax
  hkVector4f v13; // xmm0
  __m128 v14; // xmm13
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  struct hkpConstraintRuntime *v17; // r8
  hkpJacobianSchema *v18; // r9
  unsigned int v19; // edx
  hkpConstraintInstance *v20; // rcx
  int v21; // xmm9_4
  float v22; // xmm15_4
  float v23; // xmm10_4
  unsigned int v24; // eax
  hkTransformf *v25; // r8
  __int64 v26; // rcx
  hkpConstraintAtom *v27; // rax
  __m128 m_quad; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm1
  __int64 v32; // rcx
  hkpConstraintAtom *v33; // rax
  hkTransformf *v34; // r8
  __m128 v35; // xmm3
  __m128 v36; // xmm4
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  hkpVelocityAccumulator *v39; // rax
  hkpVelocityAccumulator *v40; // rcx
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm7
  __m128 v44; // xmm6
  __m128 v45; // xmm13
  __m128 v46; // xmm7
  __m128 v47; // xmm6
  __m128 v48; // xmm1
  __m128 v49; // xmm9
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm1
  __m128 v56; // xmm3
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm7
  __m128 v60; // xmm0
  __m128 v61; // xmm7
  __m128 v62; // xmm1
  hkpSimpleContactConstraintAtom *v63; // rax
  hkpVelocityAccumulator *v64; // rbx
  float v65; // xmm0_4
  float v66; // xmm3_4
  __int64 v67; // r10
  __int64 v68; // r8
  __int64 v69; // r9
  float v70; // xmm0_4
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  __m128 v73; // xmm2
  __m128 v74; // xmm3
  __m128 v75; // xmm4
  float v76; // xmm0_4
  float v77; // xmm3_4
  __int64 v78; // r10
  __int64 v79; // r8
  __int64 v80; // r9
  float v81; // xmm0_4
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm1
  hkpVelocityAccumulator *v85; // rcx
  hkpVelocityAccumulator *v86; // rdx
  __m128 *v87; // r8
  __m128 v88; // xmm4
  __m128 v89; // xmm3
  __m128 v90; // xmm2
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm1
  __m128 v95; // xmm6
  __m128 v96; // xmm1
  __m128 v97; // xmm4
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm5
  __m128 v103; // xmm4
  __m128 v104; // xmm3
  __m128 v105; // xmm2
  __m128 v106; // xmm4
  __m128 v107; // xmm6
  __m128 v108; // xmm7
  __m128 v109; // xmm4
  __m128 v110; // xmm2
  __m128 v111; // xmm0
  __m128 v112; // xmm1
  __m128 v113; // xmm5
  __m128 v114; // xmm6
  __m128 v115; // xmm1
  __m128 v116; // xmm2
  __m128 v117; // xmm1
  __m128 *v118; // rax
  hkpVelocityAccumulator *v119; // rcx
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  __m128 v122; // xmm3
  hkpJacobianSchema *v123; // r11
  __m128 v124; // xmm4
  __m128 v125; // xmm4
  __m128 v126; // xmm2
  __m128 v127; // xmm3
  __m128 v128; // xmm5
  __m128 v129; // xmm6
  __m128 v130; // xmm9
  __m128 v131; // xmm0
  __m128 v132; // xmm4
  float v133; // xmm7_4
  float v134; // xmm8_4
  float v135; // xmm0_4
  float v136; // xmm3_4
  __int64 v137; // r10
  __int64 v138; // r8
  __int64 v139; // r9
  float v140; // xmm0_4
  __m128 v141; // xmm0
  __m128 v142; // xmm0
  __m128 v143; // xmm1
  __m128 v144; // xmm2
  __m128 v145; // xmm3
  __m128 v146; // xmm0
  float v147; // xmm2_4
  __m128 v148; // xmm1
  __m128 v149; // xmm1
  float v150; // xmm3_4
  float v151; // xmm0_4
  float v152; // xmm3_4
  __int64 v153; // r10
  __int64 v154; // r8
  __int64 v155; // r9
  float v156; // xmm0_4
  __m128 v157; // xmm0
  __m128 v158; // xmm0
  __m128 v159; // xmm1
  __m128 v160; // xmm2
  __m128 v161; // xmm1
  __m128 v162; // xmm5
  __m128 v163; // xmm2
  __m128 v164; // xmm1
  __m128 v165; // xmm6
  __m128 v166; // xmm0
  __m128 v167; // xmm1
  __m128 v168; // xmm4
  __m128 v169; // xmm0
  __m128 v170; // xmm1
  __m128 v171; // xmm2
  __m128 v172; // xmm1
  __m128 v173; // xmm8
  __m128 v174; // xmm0
  __m128 v175; // xmm1
  __m128 v176; // xmm5
  __m128 v177; // xmm0
  __m128 v178; // xmm1
  __m128 v179; // xmm3
  __m128 v180; // xmm0
  __m128 v181; // xmm2
  __m128 v182; // xmm1
  __m128 v183; // xmm4
  __m128 v184; // xmm6
  __m128 v185; // xmm1
  __m128 v186; // xmm1
  hkTransformf *v187; // rax
  __int64 v188; // rcx
  __m128 v189; // xmm3
  __m128 v190; // xmm4
  __m128 v191; // xmm5
  hkpConstraintAtom *v192; // rax
  __m128 v193; // xmm1
  hkTransformf *v194; // rax
  hkpConstraintAtom *v195; // r8
  __int64 v196; // rcx
  __m128 v197; // xmm3
  __m128 v198; // xmm4
  __m128 v199; // xmm5
  hkpConstraintAtom *v200; // rax
  __m128 v201; // xmm1
  __m128 *v202; // rax
  __m128 v203; // xmm1
  __m128 v204; // xmm3
  __m128 v205; // xmm2
  __m128 v206; // xmm1
  __m128 v207; // xmm2
  __m128 v208; // xmm1
  __m128 v209; // xmm3
  __m128 v210; // xmm5
  __m128 v211; // xmm1
  __m128 v212; // xmm5
  __m128 v213; // xmm2
  __m128 v214; // xmm8
  __m128 v215; // xmm4
  __m128 v216; // xmm1
  __m128 v217; // xmm4
  __m128 v218; // xmm5
  __m128 v219; // xmm3
  __m128 v220; // xmm3
  __m128 v221; // xmm1
  hkpVelocityAccumulator *v222; // rax
  hkpVelocityAccumulator *v223; // rcx
  __m128 *v224; // rdx
  __m128 v225; // xmm3
  __m128 v226; // xmm2
  __m128 v227; // xmm5
  __m128 v228; // xmm4
  __m128 v229; // xmm4
  __m128 v230; // xmm5
  __m128 v231; // xmm5
  __m128 v232; // xmm3
  __m128 v233; // xmm1
  __m128 v234; // xmm2
  __m128 v235; // xmm2
  __m128 v236; // xmm0
  __m128 v237; // xmm3
  float *v238; // rcx
  __int64 v239; // rax
  _BYTE *v240; // rdx
  hkpSimpleContactConstraintAtom *v241; // rcx
  bool v242; // zf
  hkp1Lin2AngJacobian *v243; // rbx
  hkpSolverResults *v244; // rax
  __m128 v245; // xmm2
  _BYTE *v246; // rcx
  float v247; // xmm0_4
  __int64 v248; // rax
  __int64 m_storage_low; // rdx
  __int64 v250; // rcx
  __int64 v251; // rax
  __int64 v252; // rbx
  __int64 v253; // rdi
  hkVector4f v254; // xmm0
  unsigned __int8 m_storage_high; // dl
  const char *v256; // rcx
  __int64 v257; // rax
  hkVector4f v258; // xmm0
  __int64 v259; // rax
  hkVector4f v260; // xmm1
  __int64 v261; // rax
  __int64 v262; // rcx
  __int64 v263; // rax
  __int64 v264; // rbx
  __int64 v265; // rdi
  hkVector4f v266; // xmm0
  __int64 v267; // rax
  __int64 v268; // rcx
  __int64 v269; // rdx
  __int64 v270; // rax
  __m128 v271; // xmm4
  __m128 v272; // xmm5
  __m128 v273; // xmm3
  __m128 v274; // xmm2
  __m128 v275; // xmm2
  __m128 v276; // xmm2
  __m128 v277; // xmm0
  __m128 v278; // xmm7
  __m128 v279; // xmm2
  __m128 v280; // xmm4
  __m128 v281; // xmm6
  __m128 v282; // xmm3
  __m128 v283; // xmm2
  __m128 v284; // xmm10
  __m128 v285; // xmm6
  __m128 v286; // xmm8
  __m128 v287; // xmm6
  __m128 v288; // xmm13
  __m128 v289; // xmm7
  __m128 v290; // xmm13
  __m128 v291; // xmm5
  __m128i v292; // xmm4
  __m128 v293; // xmm3
  __m128 v294; // xmm1
  __m128 v295; // xmm3
  __m128 v296; // xmm1
  int v297; // eax
  __int64 v298; // rax
  __int64 v299; // rcx
  __m128 v300; // xmm0
  __m128 v301; // xmm13
  __m128 v302; // xmm13
  __m128 v303; // xmm13
  __m128 v304; // xmm1
  __m128 v305; // xmm15
  __m128 v306; // xmm10
  __m128 v307; // xmm2
  __m128 v308; // xmm0
  __m128 v309; // xmm7
  __m128 v310; // xmm2
  __m128 v311; // xmm4
  __m128 v312; // xmm6
  __m128 v313; // xmm3
  __m128i v314; // xmm1
  __m128 v315; // xmm2
  __m128 v316; // xmm3
  __m128 v317; // xmm6
  __m128 v318; // xmm0
  __int64 v319; // rdx
  struct hkpConstraintRuntime *v320; // rcx
  float v321; // xmm5_4
  float v322; // xmm4_4
  int v323; // xmm7_4
  float v324; // xmm6_4
  float v325; // xmm2_4
  float v326; // xmm5_4
  float v327; // xmm4_4
  __int64 v328; // rax
  __int64 v329; // rax
  __int64 v330; // rax
  __int64 v331; // rcx
  __m128 v332; // xmm9
  __m128 v333; // xmm1
  __m128 v334; // xmm3
  __m128 v335; // xmm2
  __m128 v336; // xmm4
  __m128 v337; // xmm1
  float v338; // xmm10_4
  __m128 v339; // xmm2
  __m128 v340; // xmm9
  __m128 v341; // xmm2
  __m128 v342; // xmm4
  __m128 v343; // xmm3
  __m128 v344; // xmm4
  __m128 v345; // xmm3
  __m128 v346; // xmm0
  __m128 v347; // xmm7
  __m128 v348; // xmm2
  __m128 v349; // xmm4
  __m128 v350; // xmm6
  __m128 v351; // xmm3
  __m128 v352; // xmm2
  __m128 v353; // xmm6
  hkpJacobianSchema *v354; // rdx
  float v355; // xmm5_4
  hkpVelocityAccumulator *v356; // rax
  hkpVelocityAccumulator *v357; // rcx
  __m128 v358; // xmm4
  __m128 v359; // xmm3
  __m128 v360; // xmm2
  __m128 v361; // xmm2
  float v362; // xmm0_4
  float v363; // xmm1_4
  float v364; // xmm6_4
  int v365; // r11d
  struct hkpConstraintRuntime *v366; // r10
  hkpJacobianSchema *v367; // rdx
  __m128 *v368; // r8
  int v369; // r9d
  signed __int64 v370; // r10
  __m128 v371; // xmm5
  __m128 v372; // xmm7
  __m128 v373; // xmm2
  hkpVelocityAccumulator *v374; // rax
  hkpVelocityAccumulator *v375; // rcx
  __m128 v376; // xmm0
  __m128 v377; // xmm4
  __m128 v378; // xmm4
  __m128 v379; // xmm3
  __m128 v380; // xmm2
  __m128 v381; // xmm2
  char v382; // cl
  __int64 v383; // rax
  __int64 v384; // rcx
  __int64 v385; // rax
  __int64 v386; // rdx
  __int64 v387; // rcx
  hkpSimpleContactConstraintAtom *v388; // r9
  float *v389; // r8
  hkpConstraintMotor *v390; // r10
  __m128 v391; // xmm1
  __m128 v392; // xmm2
  __m128 v393; // xmm2
  __m128 v394; // xmm0
  __m128 v395; // xmm2
  __m128 v396; // xmm7
  __m128 v397; // xmm4
  __m128 v398; // xmm6
  __m128 v399; // xmm3
  __m128 v400; // xmm2
  signed __int16 v401; // ax
  __m128 v402; // xmm6
  __m128 v403; // xmm13
  __m128 v404; // xmm10
  float v405; // xmm0_4
  __m128 v406; // xmm7
  __m128 v407; // xmm5
  __m128i v408; // xmm4
  __m128 v409; // xmm2
  __m128 v410; // xmm3
  __m128 v411; // xmm1
  hkpVelocityAccumulator *v412; // rdx
  hkpVelocityAccumulator *v413; // rcx
  __m128 *v414; // rbx
  __int64 v415; // rax
  __m128 v416; // xmm2
  __m128 v417; // xmm3
  __m128 v418; // xmm2
  __m128 v419; // xmm3
  __m128 v420; // xmm2
  __m128 v421; // xmm2
  hkpSolverResults *v422; // rax
  hkpJacobianSchema *v423; // rax
  float v424; // xmm0_4
  float v425; // xmm0_4
  __int64 v426; // rax
  hkTransformf *v427; // rdx
  _BYTE *v428; // rdx
  hkpConstraintMotor **v429; // rax
  int v430; // r8d
  unsigned __int64 v431; // r9
  unsigned __int64 v432; // rdi
  hkpConstraintMotor *v433; // r10
  __int64 v434; // rcx
  __int64 v435; // rax
  __int64 v436; // rcx
  __m128 v437; // xmm5
  __m128 v438; // xmm1
  __m128 v439; // xmm3
  __m128 v440; // xmm2
  __m128 v441; // xmm4
  __m128 v442; // xmm1
  __m128 v443; // xmm2
  __m128 v444; // xmm5
  __m128 v445; // xmm2
  __m128 v446; // xmm8
  __m128 v447; // xmm4
  __m128 v448; // xmm3
  __m128 v449; // xmm4
  __m128 v450; // xmm3
  __m128 v451; // xmm0
  __m128 v452; // xmm6
  __m128 v453; // xmm2
  __m128 v454; // xmm4
  __m128 v455; // xmm5
  __m128 v456; // xmm3
  __m128 v457; // xmm2
  __m128 v458; // xmm5
  __m128 v459; // xmm7
  __m128 v460; // xmm1
  __m128 v461; // xmm2
  __m128 v462; // xmm1
  __m128 v463; // xmm3
  __m128 v464; // xmm1
  __m128 v465; // xmm2
  __m128 v466; // xmm7
  __m128 v467; // xmm2
  __m128 v468; // xmm4
  __m128 v469; // xmm3
  __m128 v470; // xmm1
  __m128 v471; // xmm2
  __m128 v472; // xmm0
  __m128 v473; // xmm5
  __m128 v474; // xmm2
  __m128 v475; // xmm8
  __m128 v476; // xmm4
  __m128 v477; // xmm3
  __m128 v478; // xmm2
  __m128 v479; // xmm4
  float v480; // xmm4_4
  hkpVelocityAccumulator *v481; // rax
  hkpVelocityAccumulator *v482; // rcx
  __m128 *v483; // rbx
  float v484; // xmm6_4
  __m128 v485; // xmm1
  __m128 v486; // xmm2
  __m128 v487; // xmm3
  __m128 v488; // xmm2
  __m128 v489; // xmm2
  hkpJacobianSchema *v490; // rax
  float v491; // xmm0_4
  __int64 v492; // rax
  __int64 v493; // rax
  __m128 v494; // xmm7
  __m128 v495; // xmm8
  unsigned int v496; // xmm9_4
  unsigned int v497; // xmm10_4
  hkpVelocityAccumulator *v498; // rax
  hkpVelocityAccumulator *v499; // rcx
  __m128 *v500; // rdx
  __m128 v501; // xmm4
  __m128 v502; // xmm5
  __m128 v503; // xmm3
  __m128 v504; // xmm1
  __m128 v505; // xmm2
  __m128 v506; // xmm5
  __m128 v507; // xmm3
  __m128 v508; // xmm1
  __m128 v509; // xmm2
  __m128 v510; // xmm4
  __m128 v511; // xmm11
  __m128 v512; // xmm3
  __m128 v513; // xmm1
  __m128 v514; // xmm2
  __m128 v515; // xmm5
  __m128 v516; // xmm5
  __m128 v517; // xmm4
  __m128 v518; // xmm4
  __m128 v519; // xmm3
  __m128 v520; // xmm3
  __m128 v521; // xmm1
  __m128 v522; // xmm1
  __m128 v523; // xmm3
  __m128 v524; // xmm1
  __m128 v525; // xmm3
  __m128 v526; // xmm10
  __m128 v527; // xmm1
  __m128 v528; // xmm8
  __m128 v529; // xmm1
  float *v530; // rcx
  float v531; // xmm0_4
  struct hkpConstraintRuntime *v532; // rax
  __m128 v533; // xmm9
  __m128 *v534; // rdx
  float *v535; // r9
  float *v536; // r8
  unsigned int *v537; // rcx
  hkVector4f v538; // xmm11
  hkVector4f v539; // xmm13
  hkVector4f v540; // xmm15
  hkVector4f v541; // xmm10
  __m128 v542; // xmm9
  __m128 v543; // xmm9
  __m128 v544; // xmm1
  __m128 v545; // xmm3
  __m128 v546; // xmm2
  hkVector4f v547; // xmm3
  __m128 v548; // xmm0
  __m128 v549; // xmm1
  __m128 v550; // xmm1
  __m128 v551; // xmm2
  __m128 v552; // xmm0
  __m128 v553; // xmm7
  __m128 v554; // xmm2
  __m128 v555; // xmm4
  __m128 v556; // xmm6
  __m128 v557; // xmm3
  __m128 v558; // xmm5
  __m128 v559; // xmm2
  __m128 v560; // xmm1
  __m128 v561; // xmm6
  float v562; // xmm6_4
  float v563; // xmm1_4
  float v564; // xmm0_4
  float v565; // xmm2_4
  hkpVelocityAccumulator *v566; // rax
  __m128i v567; // xmm7
  hkpVelocityAccumulator *v568; // rcx
  float v569; // xmm7_4
  __m128 v570; // xmm9
  __m128 v571; // xmm9
  float v572; // xmm0_4
  __m128 v573; // xmm11
  __m128 v574; // xmm13
  float v575; // xmm7_4
  __m128 v576; // xmm2
  __m128 v577; // xmm4
  __m128 v578; // xmm2
  __m128 v579; // xmm4
  __m128 v580; // xmm2
  __m128 v581; // xmm3
  __m128 v582; // xmm1
  __m128 v583; // xmm2
  __m128 v584; // xmm2
  __m128 v585; // xmm0
  __m128 v586; // xmm3
  __m128 v587; // xmm5
  __m128 v588; // xmm0
  __m128 v589; // xmm2
  __m128 v590; // xmm1
  float v591; // xmm0_4
  __m128 v592; // xmm11
  __m128 v593; // xmm13
  __m128 v594; // xmm2
  __m128 v595; // xmm1
  __m128 v596; // xmm2
  __m128 v597; // xmm3
  __m128 v598; // xmm0
  __m128 v599; // xmm2
  __m128 v600; // xmm3
  __m128 v601; // xmm1
  __m128 v602; // xmm2
  __m128 v603; // xmm3
  __m128 v604; // xmm3
  __m128 v605; // xmm0
  __m128 v606; // xmm1
  float v607; // xmm0_4
  struct hkpConstraintRuntime *v608; // rax
  __m128 *v609; // rdx
  float *v610; // r9
  float *v611; // r8
  int *v612; // rcx
  hkVector4f v613; // xmm15
  __m128 v614; // xmm6
  __m128 v615; // xmm2
  __m128 v616; // xmm1
  __m128 v617; // xmm4
  __m128 v618; // xmm3
  __m128 v619; // xmm2
  __m128 v620; // xmm2
  __m128 v621; // xmm0
  __m128 v622; // xmm0
  __m128 v623; // xmm9
  __m128 v624; // xmm9
  __m128 v625; // xmm10
  __m128 v626; // xmm1
  __m128 v627; // xmm10
  __m128 v628; // xmm4
  __m128 v629; // xmm1
  __m128 v630; // xmm3
  __m128 v631; // xmm2
  __m128 v632; // xmm5
  __m128 v633; // xmm1
  __m128 v634; // xmm0
  __m128 v635; // xmm2
  __m128 v636; // xmm9
  __m128 v637; // xmm0
  __m128 v638; // xmm3
  __m128 v639; // xmm10
  __m128 v640; // xmm1
  __m128 v641; // xmm2
  __m128 v642; // xmm11
  __m128 v643; // xmm4
  __m128 v644; // xmm11
  __m128 v645; // xmm0
  __m128 v646; // xmm7
  __m128 v647; // xmm1
  __m128 v648; // xmm4
  __m128 v649; // xmm6
  __m128 v650; // xmm3
  __m128 v651; // xmm2
  __m128 v652; // xmm6
  float v653; // xmm0_4
  float v654; // xmm1_4
  float v655; // xmm1_4
  __m128 v656; // xmm5
  float v657; // xmm7_4
  __m128 v658; // xmm5
  float v659; // xmm6_4
  __m128 v660; // xmm3
  __m128 v661; // xmm3
  __m128 v662; // xmm2
  __m128 v663; // xmm5
  __m128 v664; // xmm1
  __m128 v665; // xmm3
  __m128 v666; // xmm1
  hkpVelocityAccumulator *v667; // rax
  hkpVelocityAccumulator *v668; // rcx
  __m128 v669; // xmm1
  __m128 v670; // xmm2
  __m128 v671; // xmm0
  __m128 v672; // xmm3
  __m128 v673; // xmm5
  __m128 v674; // xmm3
  __m128 v675; // xmm2
  __m128 v676; // xmm1
  __m128 v677; // xmm3
  __m128 v678; // xmm3
  __m128 v679; // xmm4
  __m128 v680; // xmm4
  __m128 v681; // xmm3
  __m128 v682; // xmm1
  __m128 v683; // xmm2
  __m128 v684; // xmm2
  __m128 v685; // xmm0
  __m128 v686; // xmm3
  __m128 v687; // xmm11
  hkpVelocityAccumulator *v688; // rcx
  hkpVelocityAccumulator *v689; // rdx
  hkVector4f v690; // xmm7
  hkVector4f v691; // xmm5
  hkVector4f v692; // xmm2
  __m128 v693; // xmm3
  __m128 v694; // xmm6
  __m128 *v695; // rax
  __m128 v696; // xmm1
  __m128 v697; // xmm2
  __m128 v698; // xmm5
  __m128 v699; // xmm5
  __m128 v700; // xmm4
  __m128 v701; // xmm4
  __m128 v702; // xmm5
  __m128 v703; // xmm3
  __m128 v704; // xmm1
  __m128 v705; // xmm2
  __m128 v706; // xmm2
  __m128 v707; // xmm0
  __m128 v708; // xmm3
  __m128 v709; // xmm2
  __m128 v710; // xmm1
  __m128 v711; // xmm7
  __m128 v712; // xmm3
  __m128 v713; // xmm4
  __m128 v714; // xmm3
  __m128 v715; // xmm4
  __m128 v716; // xmm3
  __m128 v717; // xmm1
  __m128 v718; // xmm2
  __m128 v719; // xmm2
  __m128 v720; // xmm0
  __m128 v721; // xmm3
  __m128 v722; // xmm1
  __m128 v723; // xmm4
  __m128 v724; // xmm6
  __m128 v725; // xmm4
  __m128 v726; // xmm6
  __m128 v727; // xmm5
  __m128 v728; // xmm2
  __m128 v729; // xmm1
  __int64 v730; // rax
  __m128 v731; // xmm1
  __m128 v732; // xmm1
  hkpVelocityAccumulator *v733; // rax
  hkpVelocityAccumulator *v734; // rax
  __m128 v735; // xmm1
  float v736; // xmm6_4
  hkpConstraintAtom *v737; // r8
  unsigned __int64 v738; // r10
  int v739; // eax
  __int64 v740; // r11
  hkpConstraintAtom *v741; // rcx
  __int64 v742; // rdx
  float *p_m_storage; // rax
  unsigned __int64 v744; // r9
  float v745; // xmm0_4
  __int64 v746; // rcx
  float v747; // xmm0_4
  __int64 v748; // rcx
  float v749; // xmm0_4
  __int64 v750; // rcx
  float v751; // xmm0_4
  float *v752; // rcx
  float *v753; // rdx
  unsigned __int64 v754; // r10
  float v755; // xmm0_4
  hkpSimpleContactConstraintAtom *v756; // rcx
  hkpConstraintAtom *v757; // rcx
  hkpSimpleContactConstraintAtom *v758; // rcx
  __m128 v759; // xmm4
  __m128 v760; // xmm5
  hkpVelocityAccumulator *v761; // rax
  hkpVelocityAccumulator *v762; // rax
  __int128 m_scratch3; // xmm1
  __m128 v764; // xmm7
  hkpSimpleContactConstraintAtom *v765; // rcx
  bool v766; // bl
  __m128 v767; // xmm2
  __m128 v768; // xmm6
  hkpConstraintAtom *v769; // [rsp+50h] [rbp-B0h]
  float v770; // [rsp+50h] [rbp-B0h]
  hkpConstraintAtom *v771; // [rsp+58h] [rbp-A8h]
  unsigned __int64 v772; // [rsp+60h] [rbp-A0h]
  hkTransformf baseB; // [rsp+70h] [rbp-90h] BYREF
  hkSimdFloat32 maxAngularImpulse; // [rsp+B0h] [rbp-50h] BYREF
  hkTransformf baseA; // [rsp+C0h] [rbp-40h] BYREF
  __m128 v776; // [rsp+100h] [rbp+0h]
  float v777; // [rsp+110h] [rbp+10h]
  int v778; // [rsp+114h] [rbp+14h]
  float v779; // [rsp+118h] [rbp+18h]
  float v780; // [rsp+11Ch] [rbp+1Ch]
  _BYTE *v781; // [rsp+120h] [rbp+20h]
  __m128 v782; // [rsp+130h] [rbp+30h]
  __m128 v783; // [rsp+140h] [rbp+40h]
  __m128 v784; // [rsp+150h] [rbp+50h]
  __m128 v785; // [rsp+160h] [rbp+60h]
  __m128 v786; // [rsp+170h] [rbp+70h]
  unsigned int v787; // [rsp+180h] [rbp+80h]
  int v788; // [rsp+188h] [rbp+88h]
  int v789; // [rsp+190h] [rbp+90h]
  int v790; // [rsp+198h] [rbp+98h]
  unsigned int v791; // [rsp+1A0h] [rbp+A0h]
  float v792; // [rsp+1A8h] [rbp+A8h]
  int v793; // [rsp+1ACh] [rbp+ACh]
  __int64 v794; // [rsp+1B0h] [rbp+B0h]
  float v795; // [rsp+1B8h] [rbp+B8h]
  int v796; // [rsp+1BCh] [rbp+BCh]
  float v797; // [rsp+1C0h] [rbp+C0h]
  float v798; // [rsp+1C4h] [rbp+C4h]
  int v799; // [rsp+1C8h] [rbp+C8h]
  int v800; // [rsp+1CCh] [rbp+CCh]
  __m128 v801; // [rsp+1D0h] [rbp+D0h]
  __m128 v802; // [rsp+1E0h] [rbp+E0h]
  __m128 v803; // [rsp+1F0h] [rbp+F0h]
  hkMatrix3f v804; // [rsp+200h] [rbp+100h] BYREF
  int v805; // [rsp+230h] [rbp+130h]
  __int64 v806; // [rsp+234h] [rbp+134h]
  int v807; // [rsp+240h] [rbp+140h]
  __int64 v808; // [rsp+244h] [rbp+144h]
  int v809; // [rsp+250h] [rbp+150h]
  __int64 v810; // [rsp+254h] [rbp+154h]
  int v811; // [rsp+260h] [rbp+160h]
  __int64 v812; // [rsp+264h] [rbp+164h]
  hkMatrix3f v813; // [rsp+270h] [rbp+170h] BYREF
  __m128 v814; // [rsp+2A0h] [rbp+1A0h]
  __m128 v815; // [rsp+2B0h] [rbp+1B0h]
  __m128 v816; // [rsp+2C0h] [rbp+1C0h]
  hkVector4f deltaVel; // [rsp+2D0h] [rbp+1D0h] BYREF
  __int64 v818; // [rsp+2E0h] [rbp+1E0h]
  int v819; // [rsp+2E8h] [rbp+1E8h]
  int v820[4]; // [rsp+2F0h] [rbp+1F0h]
  hkpConstraintMotorOutput v821; // [rsp+300h] [rbp+200h] BYREF
  hkpConstraintMotorOutput v822; // [rsp+318h] [rbp+218h] BYREF
  hkpConstraintMotorInput statusOut; // [rsp+330h] [rbp+230h] BYREF
  hkpConstraintMotorInput input; // [rsp+350h] [rbp+250h] BYREF
  hkpConstraintMotorInput v825; // [rsp+370h] [rbp+270h] BYREF
  __m128 *v826; // [rsp+390h] [rbp+290h]
  __m128 *v827; // [rsp+398h] [rbp+298h]
  __m128 v828; // [rsp+3A0h] [rbp+2A0h]
  __m128 v829; // [rsp+3B0h] [rbp+2B0h]
  __m128 v830; // [rsp+3C0h] [rbp+2C0h]
  __m128 v831; // [rsp+3D0h] [rbp+2D0h]
  __m128 v832; // [rsp+3E0h] [rbp+2E0h]
  __m128 v833; // [rsp+3F0h] [rbp+2F0h]
  unsigned int v834; // [rsp+400h] [rbp+300h]
  unsigned int v835; // [rsp+404h] [rbp+304h]
  float v836; // [rsp+408h] [rbp+308h]
  float v837; // [rsp+40Ch] [rbp+30Ch]
  __m128 v838; // [rsp+410h] [rbp+310h]
  hkSimdFloat32 scale; // [rsp+420h] [rbp+320h] BYREF
  __m128 v840; // [rsp+430h] [rbp+330h]
  hkMatrix3f v841; // [rsp+440h] [rbp+340h] BYREF
  hkVector4f vLocalArmA; // [rsp+470h] [rbp+370h] BYREF
  hkMatrix3f v843; // [rsp+480h] [rbp+380h] BYREF
  hkVector4f vLocalArmB; // [rsp+4B0h] [rbp+3B0h] BYREF
  __int128 v845; // [rsp+4C0h] [rbp+3C0h]
  hkSimdFloat32 maxLinearImpulse; // [rsp+4D0h] [rbp+3D0h] BYREF
  __m128 v847; // [rsp+4E0h] [rbp+3E0h]
  __m128 v848; // [rsp+4F0h] [rbp+3F0h]
  __m128 v849; // [rsp+500h] [rbp+400h]
  float v850; // [rsp+510h] [rbp+410h]
  struct hkpConstraintRuntime *v851; // [rsp+518h] [rbp+418h]
  hkMatrix3f angToLinVelA; // [rsp+520h] [rbp+420h] BYREF
  hkMatrix3f angToLinVelB; // [rsp+550h] [rbp+450h] BYREF
  hkMatrix3f aTb; // [rsp+580h] [rbp+480h] BYREF
  hkp1dAngularBilateralConstraintInfo v855; // [rsp+5B0h] [rbp+4B0h] BYREF
  hkp1dAngularBilateralConstraintInfo v856; // [rsp+5E0h] [rbp+4E0h] BYREF
  __int16 v857; // [rsp+610h] [rbp+510h]
  unsigned __int8 v858; // [rsp+612h] [rbp+512h]
  __m128 v859; // [rsp+620h] [rbp+520h]
  __m128 v860; // [rsp+630h] [rbp+530h]
  __m128 v861; // [rsp+640h] [rbp+540h]
  hkVector4f v862; // [rsp+650h] [rbp+550h] BYREF
  __m128 v863; // [rsp+660h] [rbp+560h]
  __m128 v864; // [rsp+670h] [rbp+570h]
  hkVector4f r; // [rsp+680h] [rbp+580h] BYREF
  __m128 v866; // [rsp+690h] [rbp+590h]
  __m128 v867; // [rsp+6A0h] [rbp+5A0h]
  __m128 v868; // [rsp+6B0h] [rbp+5B0h]
  __int128 v869; // [rsp+6C0h] [rbp+5C0h] BYREF
  __m128 v870; // [rsp+6D0h] [rbp+5D0h]
  __m128 v871; // [rsp+6E0h] [rbp+5E0h]
  hkVector4f v872; // [rsp+6F0h] [rbp+5F0h]
  hkRotationf cTb; // [rsp+700h] [rbp+600h] BYREF
  __m128 v874; // [rsp+730h] [rbp+630h]
  __int128 v875; // [rsp+740h] [rbp+640h] BYREF
  __m128 v876; // [rsp+750h] [rbp+650h]
  __m128 v877; // [rsp+760h] [rbp+660h]
  hkVector4f v878; // [rsp+770h] [rbp+670h]
  hkRotationf v879; // [rsp+780h] [rbp+680h] BYREF
  __m128 v880; // [rsp+7B0h] [rbp+6B0h]
  hkp1dLinearBilateralUserTauConstraintInfo v881; // [rsp+7C0h] [rbp+6C0h] BYREF
  hkp1dLinearLimitInfo v882; // [rsp+800h] [rbp+700h] BYREF
  hkpConstraintQueryIn v883; // [rsp+840h] [rbp+740h] BYREF
  hkpConstraintQueryIn ina; // [rsp+8D0h] [rbp+7D0h] BYREF
  __int128 v885[3]; // [rsp+960h] [rbp+860h] BYREF
  hkVector4f invMassB; // [rsp+990h] [rbp+890h] BYREF
  hkVector4f v887; // [rsp+9A0h] [rbp+8A0h]
  hkVector4f v888; // [rsp+9B0h] [rbp+8B0h]
  hkVector4f v889; // [rsp+9C0h] [rbp+8C0h]
  __int128 v890; // [rsp+9D0h] [rbp+8D0h]
  __int128 v891[3]; // [rsp+9E0h] [rbp+8E0h] BYREF
  hkVector4f invMassA; // [rsp+A10h] [rbp+910h] BYREF
  hkVector4f v893; // [rsp+A20h] [rbp+920h]
  hkVector4f v894; // [rsp+A30h] [rbp+930h]
  hkVector4f v895; // [rsp+A40h] [rbp+940h]
  hkVector4f v896; // [rsp+A50h] [rbp+950h]
  hkMatrix3f THIS; // [rsp+A60h] [rbp+960h] BYREF
  hkp1dLinearBilateralConstraintInfo info; // [rsp+A90h] [rbp+990h] BYREF
  hkpConstraintMotorOutput output; // [rsp+AC0h] [rbp+9C0h] BYREF
  hkpConstraintQueryIn v900; // [rsp+AE0h] [rbp+9E0h] BYREF
  hkp1dAngularBilateralConstraintInfo v901; // [rsp+B70h] [rbp+A70h] BYREF
  hkpConstraintQueryIn v902; // [rsp+BA0h] [rbp+AA0h] BYREF
  __m128 v903; // [rsp+C30h] [rbp+B30h]
  __m128 v904; // [rsp+C40h] [rbp+B40h]
  __m128 v905; // [rsp+C50h] [rbp+B50h]
  __m128 v906; // [rsp+C60h] [rbp+B60h]
  __m128 v907; // [rsp+C70h] [rbp+B70h]
  __m128 v908; // [rsp+C80h] [rbp+B80h]
  __m128 v909; // [rsp+C90h] [rbp+B90h]
  __m128 v910; // [rsp+CA0h] [rbp+BA0h]
  __m128 v911; // [rsp+CB0h] [rbp+BB0h]
  __int128 v912; // [rsp+CC0h] [rbp+BC0h]
  __m128 v913; // [rsp+CD0h] [rbp+BD0h]
  __m128 v914; // [rsp+CE0h] [rbp+BE0h]
  __m128 v915; // [rsp+CF0h] [rbp+BF0h]
  __m128 v916; // [rsp+D00h] [rbp+C00h]
  __m128 v917; // [rsp+D10h] [rbp+C10h]
  __m128 v918; // [rsp+D20h] [rbp+C20h]
  __m128 v919; // [rsp+D30h] [rbp+C30h]
  __m128 v920; // [rsp+D40h] [rbp+C40h]
  __m128 v921; // [rsp+D50h] [rbp+C50h]
  __m128 v922; // [rsp+D60h] [rbp+C60h]
  __m128 v923; // [rsp+D70h] [rbp+C70h]
  __m128 v924; // [rsp+D80h] [rbp+C80h]
  __m128 v925; // [rsp+D90h] [rbp+C90h]
  __m128 v926; // [rsp+DA0h] [rbp+CA0h]
  __m128 v927; // [rsp+DB0h] [rbp+CB0h]
  __m128 v928; // [rsp+DC0h] [rbp+CC0h]
  __m128 v929; // [rsp+DD0h] [rbp+CD0h]
  __m128 v930; // [rsp+DE0h] [rbp+CE0h]
  __m128 v931; // [rsp+DF0h] [rbp+CF0h]
  __m128 v932; // [rsp+E00h] [rbp+D00h]
  __m128 v933; // [rsp+E10h] [rbp+D10h]
  __m128 v934; // [rsp+E20h] [rbp+D20h]
  __m128 v935; // [rsp+E30h] [rbp+D30h]
  __m128 v936; // [rsp+E40h] [rbp+D40h]
  __m128 v937; // [rsp+E50h] [rbp+D50h]
  __m128 v938; // [rsp+E60h] [rbp+D60h]
  __m128 v939; // [rsp+E70h] [rbp+D70h]
  __m128 v940; // [rsp+E80h] [rbp+D80h]
  __m128 v941; // [rsp+E90h] [rbp+D90h]
  __m128 v942; // [rsp+EA0h] [rbp+DA0h]
  __m128 v943; // [rsp+EB0h] [rbp+DB0h]
  __m128 v944; // [rsp+EC0h] [rbp+DC0h]
  __m128 v945; // [rsp+ED0h] [rbp+DD0h]
  __m128 v946; // [rsp+EE0h] [rbp+DE0h]
  __m128 v947; // [rsp+EF0h] [rbp+DF0h]
  __m128 v948; // [rsp+F00h] [rbp+E00h]
  __m128 v949; // [rsp+F10h] [rbp+E10h]
  __m128 v950; // [rsp+F20h] [rbp+E20h]
  __m128 v951; // [rsp+F30h] [rbp+E30h]
  __m128 v952; // [rsp+F40h] [rbp+E40h]
  __m128 v953; // [rsp+F50h] [rbp+E50h]
  __m128 v954; // [rsp+F60h] [rbp+E60h]
  __m128 v955; // [rsp+F70h] [rbp+E70h]
  __m128 v956; // [rsp+F80h] [rbp+E80h]
  __m128 v957; // [rsp+F90h] [rbp+E90h]
  __m128 v958; // [rsp+FA0h] [rbp+EA0h]
  __m128 v959; // [rsp+FB0h] [rbp+EB0h]
  __m128 v960; // [rsp+FC0h] [rbp+EC0h]
  __m128 v961; // [rsp+FD0h] [rbp+ED0h]
  __m128 v962; // [rsp+FE0h] [rbp+EE0h]
  __m128 v963; // [rsp+FF0h] [rbp+EF0h]
  __m128 v964; // [rsp+1000h] [rbp+F00h]
  __m128 v965; // [rsp+1010h] [rbp+F10h]
  __m128 v966; // [rsp+1020h] [rbp+F20h]
  __m128 v967; // [rsp+1030h] [rbp+F30h]
  __m128 v968; // [rsp+1040h] [rbp+F40h]
  __m128 v969; // [rsp+1050h] [rbp+F50h]
  __m128 v970; // [rsp+1060h] [rbp+F60h]
  __m128 v971; // [rsp+1070h] [rbp+F70h]
  __m128 v972; // [rsp+1080h] [rbp+F80h]
  __m128 v973; // [rsp+1090h] [rbp+F90h]
  __m128 v974; // [rsp+10A0h] [rbp+FA0h]
  __int128 v975; // [rsp+10B0h] [rbp+FB0h]
  __m128 v976; // [rsp+10C0h] [rbp+FC0h]
  __m128 v977; // [rsp+10D0h] [rbp+FD0h]
  __m128 v978; // [rsp+10E0h] [rbp+FE0h]
  __m128 v979; // [rsp+10F0h] [rbp+FF0h]
  __m128 v980; // [rsp+1100h] [rbp+1000h]
  __m128 v981; // [rsp+1110h] [rbp+1010h]
  __m128 v982; // [rsp+1120h] [rbp+1020h]
  __m128 v983; // [rsp+1130h] [rbp+1030h]
  __m128 v984; // [rsp+1140h] [rbp+1040h]
  __m128 v985; // [rsp+1150h] [rbp+1050h]
  __m128 v986; // [rsp+1160h] [rbp+1060h]
  __m128 v987; // [rsp+1170h] [rbp+1070h]
  __m128 v988; // [rsp+1180h] [rbp+1080h]
  __m128 v989; // [rsp+1190h] [rbp+1090h]
  hkpConstraintQueryIn v990; // [rsp+11A0h] [rbp+10A0h] BYREF
  hkpVelocityAccumulator v991; // [rsp+1230h] [rbp+1130h] BYREF
  hkpSimpleContactConstraintAtom *atom; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atoma; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomb; // [rsp+1380h] [rbp+1280h]
  float atomi; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomc; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomd; // [rsp+1380h] [rbp+1280h]
  float atomj; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atome; // [rsp+1380h] [rbp+1280h]
  int atomf; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomg; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomh; // [rsp+1380h] [rbp+1280h]
  unsigned int sizeOfAllAtomsf; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsg; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsh; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsi; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsa; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsj; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsb; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsk; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsl; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsm; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsn; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomso; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsp; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsc; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsd; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomse; // [rsp+1388h] [rbp+1288h]

  m_storage = in->m_transformA.m_storage;
  v5 = (__m128)xmmword_141A712A0;
  v7 = out;
  v8 = (hkpConstraintAtom *)((char *)atoms + sizeOfAllAtoms);
  v9 = atoms;
  v769 = atoms;
  v771 = v8;
  baseA.m_rotation.m_col0 = m_storage->m_rotation.m_col0;
  baseA.m_rotation.m_col1 = m_storage->m_rotation.m_col1;
  baseA.m_rotation.m_col2 = m_storage->m_rotation.m_col2;
  v10.m_quad = (__m128)m_storage->m_translation;
  v845 = xmmword_141A712A0;
  baseA.m_translation = (hkVector4f)v10.m_quad;
  maxLinearImpulse.m_real = (__m128)xmmword_141A712A0;
  v11 = 0i64;
  v12 = in->m_transformB.m_storage;
  v13.m_quad = (__m128)v12->m_rotation.m_col0;
  v847 = 0i64;
  vLocalArmA.m_quad = 0i64;
  baseB.m_rotation.m_col0 = (hkVector4f)v13.m_quad;
  v14 = 0i64;
  baseB.m_rotation.m_col1 = v12->m_rotation.m_col1;
  v15.m_quad = (__m128)v12->m_rotation.m_col2;
  v840 = 0i64;
  baseB.m_rotation.m_col2 = (hkVector4f)v15.m_quad;
  v16.m_quad = (__m128)v12->m_translation;
  vLocalArmB.m_quad = 0i64;
  baseB.m_translation = (hkVector4f)v16.m_quad;
  LODWORD(v12) = in->m_accumulatorAIndex.m_storage;
  v17 = out->m_constraintRuntime.m_storage;
  v18 = out->m_jacobianSchemas.m_storage;
  v19 = in->m_accumulatorBIndex.m_storage;
  v20 = in->m_constraintInstance.m_storage;
  *(float *)v18 = *(float *)v18 + 0.00000011920929;
  *(_WORD *)v18 = 2049;
  *(_WORD *)&v18[4] = (_WORD)v12;
  *(_WORD *)&v18[6] = v19;
  *(_QWORD *)&v18[8] = v17;
  *(_QWORD *)&v18[16] = v20;
  v7->m_jacobianSchemas.m_storage = v18 + 32;
  if ( v9 < v8 )
  {
    v21 = _xmm[0];
    v22 = *(float *)&FLOAT_1_0;
    v23 = FLOAT_0_5;
LABEL_3:
    v24 = v9->m_type.m_storage;
    while ( 2 )
    {
      switch ( v24 )
      {
        case 0u:
          v9 = (hkpConstraintAtom *)(((unsigned __int64)&v9[7].m_type.m_storage + 1) & 0xFFFFFFFFFFFFFFF0ui64);
          v769 = v9;
          v24 = v9->m_type.m_storage;
          if ( v24 <= 0x23 )
            continue;
          goto LABEL_233;
        case 1u:
          v7->m_jacobianSchemas.m_storage -= 32;
          (*(void (__fastcall **)(_QWORD, hkpConstraintQueryIn *, hkpConstraintQueryOut *, __int64))&v9[4].m_type.m_storage)(
            *(_QWORD *)&v9[8].m_type.m_storage,
            in,
            v7,
            2i64);
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 800000);
          v8 = v771;
          v9 += 16;
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 800000;
          goto LABEL_232;
        case 2u:
          v25 = in->m_transformA.m_storage;
          v26 = 3i64;
          v27 = v9 + 32;
          m_quad = v25->m_rotation.m_col0.m_quad;
          v29 = v25->m_rotation.m_col1.m_quad;
          v30 = v25->m_rotation.m_col2.m_quad;
          do
          {
            v31 = *(__m128 *)&v27->m_type.m_storage;
            v27 -= 8;
            --v26;
            *(__m128 *)((char *)&v27[-24].m_type.m_storage + (char *)&baseA.m_translation - (char *)v9) = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v29), _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), m_quad)), _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v30));
          }
          while ( v26 >= 0 );
          v32 = 3i64;
          v33 = v9 + 64;
          baseA.m_translation.m_quad = _mm_add_ps(baseA.m_translation.m_quad, v25->m_translation.m_quad);
          v34 = in->m_transformB.m_storage;
          v35 = v34->m_rotation.m_col0.m_quad;
          v36 = v34->m_rotation.m_col1.m_quad;
          v37 = v34->m_rotation.m_col2.m_quad;
          do
          {
            v38 = *(__m128 *)&v33->m_type.m_storage;
            v33 -= 8;
            --v32;
            *(__m128 *)((char *)&v33[-56].m_type.m_storage + (char *)&baseB.m_translation - (char *)v9) = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v36), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v35)), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v37));
          }
          while ( v32 >= 0 );
          v9 += 72;
          baseB.m_translation.m_quad = _mm_add_ps(baseB.m_translation.m_quad, v34->m_translation.m_quad);
          goto LABEL_232;
        case 3u:
          v185 = *(__m128 *)&v9[8].m_type.m_storage;
          baseA.m_translation.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v185, v185, 85),
                                               in->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v185, v185, 0),
                                               in->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v185, v185, 170),
                                             in->m_transformA.m_storage->m_rotation.m_col2.m_quad)),
                                         in->m_transformA.m_storage->m_translation.m_quad);
          v186 = *(__m128 *)&v9[16].m_type.m_storage;
          baseB.m_translation.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v186, v186, 85),
                                               in->m_transformB.m_storage->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v186, v186, 0),
                                               in->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v186, v186, 170),
                                             in->m_transformB.m_storage->m_rotation.m_col2.m_quad)),
                                         in->m_transformB.m_storage->m_translation.m_quad);
          goto LABEL_231;
        case 4u:
          v187 = in->m_transformA.m_storage;
          v188 = 3i64;
          v189 = v187->m_rotation.m_col0.m_quad;
          v190 = v187->m_rotation.m_col1.m_quad;
          v191 = v187->m_rotation.m_col2.m_quad;
          v192 = v9 + 32;
          do
          {
            v193 = *(__m128 *)&v192->m_type.m_storage;
            v192 -= 8;
            --v188;
            *(__m128 *)((char *)&v192[-24].m_type.m_storage + (char *)&baseA.m_translation - (char *)v9) = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v193, v193, 85), v190), _mm_mul_ps(_mm_shuffle_ps(v193, v193, 0), v189)), _mm_mul_ps(_mm_shuffle_ps(v193, v193, 170), v191));
          }
          while ( v188 >= 0 );
          v194 = in->m_transformB.m_storage;
          v195 = v9 + 56;
          v196 = 3i64;
          v197 = v194->m_rotation.m_col0.m_quad;
          v198 = v194->m_rotation.m_col1.m_quad;
          v199 = v194->m_rotation.m_col2.m_quad;
          v200 = v9 + 56;
          do
          {
            v201 = *(__m128 *)&v200->m_type.m_storage;
            v200 -= 8;
            --v196;
            *(__m128 *)((char *)&v200[-48].m_type.m_storage + (char *)&baseB.m_translation - (char *)v9) = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v201, v201, 85), v198), _mm_mul_ps(_mm_shuffle_ps(v201, v201, 0), v197)), _mm_mul_ps(_mm_shuffle_ps(v201, v201, 170), v199));
          }
          while ( v196 >= 0 );
          v9 += 56;
          v769 = v195;
          goto LABEL_233;
        case 5u:
          buildSchemaFromBallSocketAtom(
            (hkpBallSocketConstraintAtom *)v9,
            in,
            &baseA,
            &baseB,
            &vLocalArmA,
            &vLocalArmB,
            &maxAngularImpulse,
            &maxLinearImpulse,
            v7);
          goto LABEL_16;
        case 6u:
          v202 = (__m128 *)v7->m_jacobianSchemas.m_storage;
          v203 = _mm_mul_ps(v11, v11);
          v204 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v203, v203, 85), _mm_shuffle_ps(v203, v203, 0)),
                   _mm_shuffle_ps(v203, v203, 170));
          v205 = _mm_rsqrt_ps(v204);
          v949 = v204;
          v206 = _mm_mul_ps(v14, v14);
          v963 = _mm_andnot_ps(
                   _mm_cmple_ps(v204, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v205, v204), v205)),
                       _mm_mul_ps(v205, *(__m128 *)_xmm)),
                     v204));
          v207 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v206, v206, 85), _mm_shuffle_ps(v206, v206, 0)),
                   _mm_shuffle_ps(v206, v206, 170));
          v208 = _mm_rsqrt_ps(v207);
          v965 = v207;
          v209 = _mm_cmple_ps(v207, (__m128)0i64);
          v210 = _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v208, v207), v208)),
                   _mm_mul_ps(v208, *(__m128 *)_xmm));
          v211 = _mm_rcp_ps(v963);
          v212 = _mm_mul_ps(v210, v207);
          v213 = _mm_cmplt_ps(*(__m128 *)&epsilon, v963);
          v866 = _mm_andnot_ps(v209, v212);
          v214 = _mm_cmplt_ps(*(__m128 *)&epsilon, v866);
          v215 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v211, v963)), v211);
          v216 = _mm_rcp_ps(v866);
          v967 = v215;
          v969 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v216, v866)), v216);
          v217 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v215, v11), v213), _mm_andnot_ps(v213, transform.m_quad));
          v218 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v969, v14), v214), _mm_andnot_ps(v214, transform.m_quad));
          v202[1] = _mm_shuffle_ps(v217, _mm_unpackhi_ps(v217, v963), 196);
          v202[2] = _mm_shuffle_ps(v218, _mm_unpackhi_ps(v218, v866), 196);
          v219 = *v202;
          v202 += 3;
          v9 += 6;
          v220 = _mm_shuffle_ps(
                   v219,
                   _mm_unpackhi_ps(
                     v219,
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
                         (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
                         0),
                       _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0))),
                   196);
          v202[-3] = v220;
          v221 = _mm_shuffle_ps(
                   _mm_unpacklo_ps(
                     v220,
                     _mm_shuffle_ps(
                       (__m128)*(unsigned int *)&v9[-4].m_type.m_storage,
                       (__m128)*(unsigned int *)&v9[-4].m_type.m_storage,
                       0)),
                   v220,
                   228);
          v202[-3] = _mm_shuffle_ps(
                       v221,
                       _mm_unpackhi_ps(
                         v221,
                         _mm_shuffle_ps(
                           (__m128)*(unsigned int *)&v9[-2].m_type.m_storage,
                           (__m128)*(unsigned int *)&v9[-2].m_type.m_storage,
                           0)),
                       180);
          v202[-3].m128_f32[0] = v202[-3].m128_f32[0] + 0.00000011920929;
          v202[-3].m128_i8[0] = 18;
          v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v202;
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          goto LABEL_232;
        case 7u:
          info.m_pivotA = baseA.m_translation;
          info.m_pivotB = baseB.m_translation;
          info.m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseB.m_rotation.m_col0 + LOBYTE(v9[1].m_type.m_storage));
          hk1dLinearBilateralConstraintBuildJacobian(&info, in, v7);
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v8 = v771;
          v9 += 8;
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          goto LABEL_232;
        case 8u:
          v881.m_pivotA = baseA.m_translation;
          v881.m_pivotB = baseB.m_translation;
          v881.m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseB.m_rotation.m_col0 + LOBYTE(v9[1].m_type.m_storage));
          v881.m_tau.m_storage = *(float *)&v9[2].m_type.m_storage;
          v881.m_damping.m_storage = *(float *)&v9[4].m_type.m_storage;
          hk1dLinearBilateralConstraintUserTauBuildJacobian(&v881, in, v7);
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v8 = v771;
          v9 += 8;
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          goto LABEL_232;
        case 9u:
          v882.m_pivotA = baseA.m_translation;
          v882.m_pivotB = baseB.m_translation;
          v882.m_min.m_storage = *(float *)&v9[2].m_type.m_storage;
          v882.m_max.m_storage = *(float *)&v9[4].m_type.m_storage;
          v882.m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseB.m_rotation.m_col0 + LOBYTE(v9[1].m_type.m_storage));
          hk1dLinearLimitBuildJacobian(&v882, in, v7);
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v8 = v771;
          v9 += 8;
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          goto LABEL_232;
        case 0xAu:
          if ( LOBYTE(v9[1].m_type.m_storage) && *(float *)&v9[2].m_type.m_storage > 0.0 )
          {
            v848 = baseA.m_translation.m_quad;
            v849 = *(&baseB.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage));
            v850 = *(float *)&v9[2].m_type.m_storage;
            v851 = v7->m_constraintRuntime.m_storage;
            v222 = in->m_bodyB.m_storage;
            v223 = in->m_bodyA.m_storage;
            sizeOfAllAtomsi = LODWORD(in->m_virtMassFactor.m_storage);
            v224 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            *v224 = v849;
            v225 = _mm_sub_ps(v848, v222->m_scratch3.m_quad);
            v226 = _mm_shuffle_ps(v849, v849, 201);
            v227 = _mm_sub_ps(v848, v223->m_scratch3.m_quad);
            v228 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v225, v225, 201), v849), _mm_mul_ps(v225, v226));
            v229 = _mm_shuffle_ps(v228, v228, 201);
            v230 = _mm_sub_ps(_mm_mul_ps(v227, v226), _mm_mul_ps(_mm_shuffle_ps(v227, v227, 201), v849));
            v231 = _mm_shuffle_ps(v230, v230, 201);
            v224[1] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v231, v231, 85), v223->m_scratch1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v231, v231, 0), v223->m_scratch0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v231, v231, 170), v223->m_scratch2.m_quad));
            v232 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v229, v229, 85), v222->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v229, v229, 0), v222->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v229, v229, 170), v222->m_scratch2.m_quad));
            v224[2] = v232;
            v233 = v223->m_invMasses.m_quad;
            v234 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v224[1], v224[1]), v233),
                     _mm_mul_ps(_mm_mul_ps(v232, v232), v222->m_invMasses.m_quad));
            v235 = _mm_shuffle_ps(
                     v234,
                     _mm_unpackhi_ps(
                       v234,
                       _mm_max_ps(_mm_add_ps(v233, v222->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
                     196);
            v236 = _mm_add_ps(_mm_shuffle_ps(v235, v235, 78), v235);
            v868 = _mm_add_ps(_mm_shuffle_ps(v236, v236, 177), v236);
            v224[2] = _mm_shuffle_ps(v224[2], _mm_unpackhi_ps(v224[2], v868), 196);
            v237 = _mm_rcp_ps(v868);
            v9 += 8;
            v971 = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)sizeOfAllAtomsi, (__m128)sizeOfAllAtomsi, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v237, v868)), v237));
            v224[1] = _mm_shuffle_ps(v224[1], _mm_unpackhi_ps(v224[1], v971), 196);
            *v224 = _mm_shuffle_ps(
                      *v224,
                      _mm_unpackhi_ps(
                        *v224,
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(in->m_rhsFactor.m_storage),
                            (__m128)LODWORD(in->m_rhsFactor.m_storage),
                            0),
                          _mm_shuffle_ps((__m128)*((unsigned int *)v851 + 1), (__m128)*((unsigned int *)v851 + 1), 0))),
                      196);
            v238 = (float *)v7->m_jacobianSchemas.m_storage;
            v7->m_jacobianSchemas.m_storage += 64;
            v238[12] = v850 * in->m_microStepDeltaTime.m_storage;
            *v238 = *v238 + 0.00000011920929;
            *(_BYTE *)v238 = 9;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 16);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
          }
          else
          {
            v9 += 8;
            v239 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v239 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v239 - 16) = 3;
            *(_BYTE *)(v239 - 12) = 2;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v239;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 16);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
          }
          goto LABEL_232;
        case 0xBu:
          if ( LOBYTE(v9[1].m_type.m_storage) && *(_QWORD *)&v9[8].m_type.m_storage )
          {
            v240 = (char *)v7->m_constraintRuntime.m_storage + (__int16)v9[2].m_type.m_storage;
            v241 = (hkpSimpleContactConstraintAtom *)((char *)v7->m_constraintRuntime.m_storage
                                                    + (__int16)v9[3].m_type.m_storage);
            maxAngularImpulse.m_real.m128_u64[0] = *(_QWORD *)&v9[8].m_type.m_storage;
            v242 = *v240 == 0;
            v784.m128_u64[0] = (unsigned __int64)v240;
            atoma = v241;
            if ( v242 )
              *(_DWORD *)&v241->m_type.m_storage = *(_DWORD *)&v9[4].m_type.m_storage;
            v243 = (hkp1Lin2AngJacobian *)v7->m_jacobianSchemas.m_storage;
            statusOut.m_lastResults = 0i64;
            hk1dLinearVelocityMotorBeginJacobian(
              &baseB.m_rotation.m_col0 + HIBYTE(v9[1].m_type.m_storage),
              &baseA.m_translation,
              in,
              v243,
              &statusOut);
            v244 = (hkpSolverResults *)out->m_constraintRuntime.m_storage;
            statusOut.m_stepInfo.m_storage = in;
            statusOut.m_lastResults = *v244;
            statusOut.m_deltaTarget.m_storage = *(float *)&v9[4].m_type.m_storage - *(float *)&atoma->m_type.m_storage;
            v245 = _mm_mul_ps(
                     _mm_sub_ps(baseA.m_translation.m_quad, baseB.m_translation.m_quad),
                     *(&baseB.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage)));
            statusOut.m_positionError.m_storage = *(float *)&atoma->m_type.m_storage
                                                - (float)((float)(_mm_shuffle_ps(v245, v245, 85).m128_f32[0]
                                                                + _mm_shuffle_ps(v245, v245, 0).m128_f32[0])
                                                        + _mm_shuffle_ps(v245, v245, 170).m128_f32[0]);
            hkCalcMotorData((hkpConstraintMotor *)maxAngularImpulse.m_real.m128_u64[0], &statusOut, &output);
            hk1dLinearVelocityMotorCommitJacobian(&output, in, v243, out);
            v246 = (_BYTE *)v784.m128_u64[0];
            v247 = *(float *)&v9[4].m_type.m_storage;
            if ( v247 != *(float *)&atoma->m_type.m_storage || !*(_BYTE *)v784.m128_u64[0] )
            {
              *(float *)&atoma->m_type.m_storage = v247;
              *v246 = 1;
            }
            v7 = out;
            v8 = v771;
            v9 += 12;
            out->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)out->m_constraintRuntime.m_storage
                                                                               + 16);
            out->m_constraintRuntimeInMainMemory.m_storage = (char *)out->m_constraintRuntimeInMainMemory.m_storage + 16;
          }
          else
          {
            v9 += 12;
            v248 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v248 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v248 - 16) = 3;
            *(_BYTE *)(v248 - 12) = 2;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v248;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 16);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
          }
          goto LABEL_232;
        case 0xCu:
          m_storage_low = LOBYTE(v9[1].m_type.m_storage);
          v250 = (unsigned __int8)modulo3Table[m_storage_low + 2];
          v251 = (unsigned __int8)modulo3Table[m_storage_low + 1];
          v252 = v250;
          v856.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA.m_rotation.m_col0 + m_storage_low);
          v253 = (unsigned int)v251;
          v856.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v251);
          v856.m_constrainedDofW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v250);
          hk1dAngularBilateralConstraintBuildJacobian(&v856, in, out);
          v254.m_quad = *(__m128 *)((char *)&baseB.m_rotation.m_col0 + v252);
          v7 = out;
          v856.m_perpZeroErrorAxisBinW = (hkVector4f)v254.m_quad;
          v856.m_constrainedDofW.m_quad = _mm_xor_ps(
                                            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                            *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v253));
          hk1dAngularBilateralConstraintBuildJacobian(&v856, in, out);
          out->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)out->m_constraintRuntime.m_storage
                                                                             + 16);
          v8 = v771;
          v9 = v769 + 8;
          out->m_constraintRuntimeInMainMemory.m_storage = (char *)out->m_constraintRuntimeInMainMemory.m_storage + 16;
          goto LABEL_232;
        case 0xDu:
          m_storage_high = HIBYTE(v9[1].m_type.m_storage);
          atomb = (hkpSimpleContactConstraintAtom *)((char *)&v9[1].m_type.m_storage + 1);
          if ( m_storage_high == 2 )
          {
            v857 = 12;
            v858 = (unsigned __int8)modulo3Table[LOBYTE(v9[1].m_type.m_storage) + 2] >> 4;
            v262 = (unsigned __int8)modulo3Table[v858 + 2];
            v263 = (unsigned __int8)modulo3Table[v858 + 1];
            v264 = v262;
            v855.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA.m_rotation.m_col0 + v858);
            v265 = (unsigned int)v263;
            v855.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v263);
            v855.m_constrainedDofW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v262);
            hk1dAngularBilateralConstraintBuildJacobian(&v855, in, out);
            v266.m_quad = *(__m128 *)((char *)&baseB.m_rotation.m_col0 + v264);
            v7 = out;
            v855.m_perpZeroErrorAxisBinW = (hkVector4f)v266.m_quad;
            v855.m_constrainedDofW.m_quad = _mm_xor_ps(
                                              (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                              *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v265));
            hk1dAngularBilateralConstraintBuildJacobian(&v855, in, out);
            v9 = v769;
          }
          else
          {
            sizeOfAllAtomsa = LOBYTE(v9[1].m_type.m_storage);
            if ( sizeOfAllAtomsa >= sizeOfAllAtomsa + m_storage_high )
              goto LABEL_76;
            v256 = &modulo3Table[LOBYTE(v9[1].m_type.m_storage) + 1];
            do
            {
              v257 = *((unsigned __int8 *)v256 - 1);
              maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)(v256 + 1);
              v258.m_quad = *(__m128 *)((char *)&baseA.m_rotation.m_col0 + v257);
              v259 = *(unsigned __int8 *)v256;
              v901.m_constrainedDofW = (hkVector4f)v258.m_quad;
              v260.m_quad = *(__m128 *)((char *)&baseA.m_rotation.m_col0 + v259);
              v261 = *((unsigned __int8 *)v256 + 1);
              v901.m_zeroErrorAxisAinW = (hkVector4f)v260.m_quad;
              v901.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v261);
              hk1dAngularBilateralConstraintBuildJacobian(&v901, in, v7);
              ++sizeOfAllAtomsa;
              v256 = (const char *)maxAngularImpulse.m_real.m128_u64[0];
            }
            while ( sizeOfAllAtomsa < LOBYTE(v9[1].m_type.m_storage) + LOBYTE(atomb->m_type.m_storage) );
          }
          v8 = v771;
LABEL_76:
          v9 += 8;
          v267 = 8i64 * LOBYTE(atomb->m_type.m_storage);
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + v267);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + v267;
          goto LABEL_232;
        case 0xEu:
          if ( LOBYTE(v9[1].m_type.m_storage) )
          {
            v268 = HIBYTE(v9[1].m_type.m_storage);
            v269 = (unsigned __int8)modulo3Table[v268 + 2];
            v270 = (unsigned __int8)modulo3Table[v268 + 1];
            v268 *= 2i64;
            v780 = in->m_tau.m_storage * *(float *)&v9[6].m_type.m_storage;
            v271 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v269);
            v272 = *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + v270);
            v273 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v268);
            v274 = _mm_mul_ps(v271, v272);
            v776 = *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v268);
            v777 = *(float *)&v9[2].m_type.m_storage;
            v778 = *(_DWORD *)&v9[4].m_type.m_storage;
            v973 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v274, v274, 85), _mm_shuffle_ps(v274, v274, 0)),
                     _mm_shuffle_ps(v274, v274, 170));
            v275 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v273, v273, 201), v271),
                     _mm_mul_ps(_mm_shuffle_ps(v271, v271, 201), v273));
            v276 = _mm_mul_ps(_mm_shuffle_ps(v275, v275, 201), v272);
            v277 = _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v276, v276, 85), _mm_shuffle_ps(v276, v276, 0)),
                       _mm_shuffle_ps(v276, v276, 170)));
            v278 = _mm_cmple_ps((__m128)0i64, v277);
            v279 = _mm_mul_ps(v277, v973);
            v280 = _mm_or_ps(
                     _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v279),
                     _mm_cmplt_ps(*(__m128 *)_xmm, v279));
            v281 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v279), v280), _mm_andnot_ps(v280, v279));
            v282 = _mm_mul_ps(v281, v281);
            v283 = _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v282, *(__m128 *)s0)), *(__m128 *)t0),
                                     _mm_add_ps(v282, *(__m128 *)s1))),
                                 *(__m128 *)t1),
                               _mm_add_ps(v282, *(__m128 *)s2))),
                           *(__m128 *)t2),
                         _mm_add_ps(v282, *(__m128 *)s3))),
                     _mm_mul_ps(v281, *(__m128 *)t3));
            v284 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
            v277.m128_i32[0] = *((_DWORD *)v7->m_constraintRuntime.m_storage + 1);
            v975 = xmmword_141A713F0;
            v977 = v284;
            v285 = _mm_or_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v281, *(__m128 *)_xmm), *(__m128 *)_xmm), v283), v280),
                     _mm_andnot_ps(v280, v283));
            v286 = _mm_add_ps(_mm_or_ps(_mm_and_ps(v973, *(__m128 *)_xmm), *(__m128 *)_xmm), v285);
            v287 = _mm_and_ps(v285, v278);
            v288 = _mm_andnot_ps(v278, v286);
            v289 = 0i64;
            v290 = _mm_or_ps(v288, v287);
            v291 = _mm_sub_ps(
                     v290,
                     _mm_shuffle_ps(
                       (__m128)COERCE_UNSIGNED_INT(v277.m128_f32[0] * -1.0),
                       (__m128)COERCE_UNSIGNED_INT(v277.m128_f32[0] * -1.0),
                       0));
            do
            {
              v292 = (__m128i)_mm_mul_ps(_mm_add_ps(v291, (__m128)xmmword_141A713B0), v284);
              v293 = _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_sub_ps((__m128)v292, *(__m128 *)two23), *(__m128 *)two23),
                         *(__m128 *)two23),
                       *(__m128 *)two23);
              v294 = _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v292, v293)), v293);
              v295 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v292, 1u), 1u));
              v979 = _mm_or_ps(_mm_andnot_ps(v295, v294), _mm_and_ps(v295, (__m128)v292));
              v289 = _mm_add_ps(v289, v979);
              v291 = _mm_sub_ps(v291, _mm_mul_ps(v979, (__m128)xmmword_141A713F0));
              v296 = _mm_cmplt_ps(v291, (__m128)xmmword_141A713B0);
            }
            while ( fmax(
                      0.0 - 3.1415927,
                      COERCE_FLOAT(v296.m128_i32[0] & v291.m128_i32[0] | _mm_andnot_ps(v296, (__m128)xmmword_141A713B0).m128_u32[0])) != v291.m128_f32[0] );
            v21 = _xmm[0];
            v297 = 0;
            v9 += 8;
            v779 = v290.m128_f32[0] - (float)(v289.m128_f32[0] * 6.2831855);
          }
          else
          {
            v297 = 1;
            v9 += 8;
          }
          goto LABEL_90;
        case 0xFu:
          v329 = HIBYTE(v9[1].m_type.m_storage);
          v800 = 619091349;
          v776 = *(&baseA.m_rotation.m_col0.m_quad + v329);
          v777 = *(float *)&v9[4].m_type.m_storage;
          v778 = *(_DWORD *)&v9[6].m_type.m_storage;
          v330 = 2i64 * HIBYTE(v9[1].m_type.m_storage);
          v331 = 2i64 * LOBYTE(v9[2].m_type.m_storage);
          v332 = _mm_add_ps(
                   *(&baseA.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage)),
                   *(&baseB.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage)));
          v333 = _mm_mul_ps(v332, v332);
          v334 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v333, v333, 85), _mm_shuffle_ps(v333, v333, 0)),
                   _mm_shuffle_ps(v333, v333, 170));
          v335 = _mm_rsqrt_ps(v334);
          v988 = v334;
          v336 = _mm_andnot_ps(
                   _mm_cmple_ps(v334, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v335, v334), v335)),
                       _mm_mul_ps(*(__m128 *)_xmm, v335)),
                     v334));
          v989 = v336;
          if ( v336.m128_f32[0] <= _mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0).m128_f32[0] )
          {
            v340 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v330);
            v338 = 0.0;
          }
          else
          {
            v337 = _mm_rcp_ps(v336);
            v798 = 0.5 * v336.m128_f32[0];
            v338 = 0.5 * v336.m128_f32[0];
            v339 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v337, v336)), v337);
            v340 = _mm_mul_ps(v332, v339);
            v981 = v339;
          }
          v951 = v340;
          v341 = _mm_shuffle_ps(v340, v340, 201);
          v342 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v331),
                       *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v331),
                       201),
                     v340),
                   _mm_mul_ps(v341, *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v331)));
          v952 = _mm_shuffle_ps(v342, v342, 201);
          v343 = _mm_sub_ps(_mm_mul_ps(v952, v341), _mm_mul_ps(_mm_shuffle_ps(v952, v952, 201), v340));
          v953 = _mm_shuffle_ps(v343, v343, 201);
          v344 = _mm_mul_ps(v952, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v331));
          v906 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v344, v344, 85), _mm_shuffle_ps(v344, v344, 0)),
                   _mm_shuffle_ps(v344, v344, 170));
          v345 = _mm_mul_ps(v953, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v331));
          v346 = _mm_rcp_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v345, v345, 85), _mm_shuffle_ps(v345, v345, 0)),
                     _mm_shuffle_ps(v345, v345, 170)));
          v347 = _mm_cmple_ps((__m128)0i64, v346);
          v348 = _mm_mul_ps(v346, v906);
          v349 = _mm_or_ps(
                   _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v348),
                   _mm_cmplt_ps(*(__m128 *)_xmm, v348));
          v350 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v348), v349), _mm_andnot_ps(v349, v348));
          v351 = _mm_mul_ps(v350, v350);
          v352 = _mm_mul_ps(
                   _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_rcp_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_rcp_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v351, *(__m128 *)s0)), *(__m128 *)t0),
                                   _mm_add_ps(v351, *(__m128 *)s1))),
                               *(__m128 *)t1),
                             _mm_add_ps(v351, *(__m128 *)s2))),
                         *(__m128 *)t2),
                       _mm_add_ps(v351, *(__m128 *)s3))),
                   _mm_mul_ps(v350, *(__m128 *)t3));
          v776 = v340;
          v21 = _xmm[0];
          v353 = _mm_or_ps(
                   _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v350, *(__m128 *)_xmm), *(__m128 *)_xmm), v352), v349),
                   _mm_andnot_ps(v349, v352));
          v9 += 16;
          v769 = v9;
          LODWORD(v779) = _mm_andnot_ps(
                            v347,
                            _mm_add_ps(_mm_or_ps(_mm_and_ps(v906, *(__m128 *)_xmm), *(__m128 *)_xmm), v353)).m128_u32[0] | v353.m128_i32[0] & v347.m128_i32[0];
          v780 = (float)((float)(in->m_tau.m_storage * *(float *)&v9[-8].m_type.m_storage) * v338) * v338;
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          goto $doAngularLimit;
        case 0x10u:
          v298 = 2i64 * HIBYTE(v9[1].m_type.m_storage);
          v299 = 2i64 * LOBYTE(v9[2].m_type.m_storage);
          v300 = *(&baseA.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage));
          v301 = *(&baseB.m_rotation.m_col0.m_quad + LOBYTE(v9[2].m_type.m_storage));
          v302 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v301, v301, 201), v300),
                   _mm_mul_ps(_mm_shuffle_ps(v300, v300, 201), v301));
          v303 = _mm_shuffle_ps(v302, v302, 201);
          v304 = _mm_mul_ps(v303, v303);
          v305 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v304, v304, 85), _mm_shuffle_ps(v304, v304, 0)),
                   _mm_shuffle_ps(v304, v304, 170));
          v984 = v305;
          if ( v305.m128_f32[0] >= 0.00000011920929 )
          {
            v306 = _mm_rsqrt_ps(v305);
            v903 = _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v306, v305), v306)),
                       _mm_mul_ps(*(__m128 *)_xmm, v306)),
                     v305);
            v307 = _mm_mul_ps(
                     *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v299),
                     *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v298));
            v308 = _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v307, v307, 85), _mm_shuffle_ps(v307, v307, 0)),
                       _mm_shuffle_ps(v307, v307, 170)));
            v309 = _mm_cmple_ps((__m128)0i64, v308);
            v310 = _mm_mul_ps(v308, v903);
            v311 = _mm_or_ps(
                     _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v310),
                     _mm_cmplt_ps(*(__m128 *)_xmm, v310));
            v312 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v310), v311), _mm_andnot_ps(v311, v310));
            v313 = _mm_mul_ps(v312, v312);
            v314 = *(__m128i *)&hkVector4fComparison_maskToComparison_465[4
                                                                        * (HIBYTE(v9[2].m_type.m_storage) != 0 ? 0xF : 0)];
            v315 = _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v313, *(__m128 *)s0)), *(__m128 *)t0),
                                     _mm_add_ps(v313, *(__m128 *)s1))),
                                 *(__m128 *)t1),
                               _mm_add_ps(v313, *(__m128 *)s2))),
                           *(__m128 *)t2),
                         _mm_add_ps(v313, *(__m128 *)s3))),
                     _mm_mul_ps(v312, *(__m128 *)t3));
            v316 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v314, 0x1Fu), 0x1Fu);
            v317 = _mm_or_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v312, *(__m128 *)_xmm), *(__m128 *)_xmm), v315), v311),
                     _mm_andnot_ps(v311, v315));
            v297 = 0;
            v318 = _mm_xor_ps(
                     _mm_or_ps(
                       _mm_andnot_ps(
                         v309,
                         _mm_add_ps(_mm_or_ps(_mm_and_ps(v903, *(__m128 *)_xmm), *(__m128 *)_xmm), v317)),
                       _mm_and_ps(v317, v309)),
                     v316);
            v315.m128_i32[0] = COERCE_UNSIGNED_INT(v318.m128_f32[0] + 1.5707964) & v314.m128i_i32[0];
            *(float *)v314.m128i_i32 = _mm_andnot_ps((__m128)v314, v318).m128_f32[0];
            v318.m128_f32[0] = in->m_tau.m_storage * *(float *)&v9[8].m_type.m_storage;
            LODWORD(v779) = v315.m128_i32[0] | v314.m128i_i32[0];
            v780 = v318.m128_f32[0];
            v21 = _xmm[0];
            v776 = _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v306, v305), v306)),
                         _mm_mul_ps(*(__m128 *)_xmm, v306)),
                       v303),
                     _mm_xor_ps(v316, g_vectorfConstants[0]));
            v777 = *(float *)&v9[4].m_type.m_storage;
            v778 = *(_DWORD *)&v9[6].m_type.m_storage;
            LOBYTE(v319) = v9[3].m_type.m_storage;
            if ( (unsigned __int8)v319 > 1u )
            {
              v320 = v7->m_constraintRuntime.m_storage;
              v319 = (unsigned __int8)v319;
              v321 = *(float *)((char *)v320 + (unsigned __int8)v319);
              v322 = v779 - v321;
              v323 = *((_DWORD *)v320 + 1) ^ _xmm[0];
              v324 = *(float *)&v323 - (float)(v779 - v321);
              atomi = in->m_frameDeltaTime.m_storage * 0.5;
              v325 = fmaxf(v321 * 0.050000001, atomi);
              v326 = v321 - v325;
              v327 = v322 + v325;
              if ( COERCE_FLOAT(LODWORD(v324) ^ _xmm[0]) > (float)((float)((float)(v325 * 2.0) + atomi) * 0.5)
                && *(float *)&v323 != 0.0 )
              {
                v326 = v326 - v324;
                v327 = v327 + v324;
              }
              *(float *)((char *)v320 + v319) = fmaxf(v326, 0.00000011920929);
              v779 = v327;
            }
          }
          else
          {
            v297 = 1;
          }
          v9 += 16;
LABEL_90:
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          v769 = v9;
          if ( v297 )
          {
            v328 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v328 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v328 - 16) = 3;
            *(_BYTE *)(v328 - 12) = 1;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v328;
          }
          else
          {
$doAngularLimit:
            v354 = v7->m_jacobianSchemas.m_storage;
            v355 = v780;
            v356 = in->m_bodyA.m_storage;
            v357 = in->m_bodyB.m_storage;
            sizeOfAllAtomsj = LODWORD(v780);
            v358 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v776);
            *(__m128 *)v354 = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v776, v776, 85), v356->m_scratch1.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v776, v776, 0), v356->m_scratch0.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v776, v776, 170), v356->m_scratch2.m_quad));
            v359 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v358, v358, 85), v357->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v358, v358, 0), v357->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v358, v358, 170), v357->m_scratch2.m_quad));
            *(__m128 *)&v354[16] = v359;
            v360 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(*(__m128 *)v354, *(__m128 *)v354), v356->m_invMasses.m_quad),
                     _mm_mul_ps(_mm_mul_ps(v359, v359), v357->m_invMasses.m_quad));
            v946 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v360, v360, 85), _mm_shuffle_ps(v360, v360, 0)),
                       _mm_shuffle_ps(v360, v360, 170)),
                     *(__m128 *)&epsilon);
            v361 = _mm_rcp_ps(v946);
            v908 = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)sizeOfAllAtomsj, (__m128)sizeOfAllAtomsj, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v361, v946)), v361));
            *(__m128 *)v354 = _mm_shuffle_ps(*(__m128 *)v354, _mm_unpackhi_ps(*(__m128 *)v354, v908), 196);
            v362 = v779;
            v363 = v777;
            v361.m128_i32[0] = v778;
            v359.m128_i32[0] = LODWORD(in->m_subStepInvDeltaTime.m_storage);
            v7->m_jacobianSchemas.m_storage = v354 + 48;
            v359.m128_i32[0] ^= v21;
            *(float *)&v354[28] = v362 * v359.m128_f32[0];
            *(float *)&v354[32] = (float)(v363 * v359.m128_f32[0]) * v355;
            *(float *)&v354[36] = (float)(v361.m128_f32[0] * v359.m128_f32[0]) * v355;
            *(float *)&v354[40] = v355;
            *(float *)v354 = *(float *)v354 + 0.00000011920929;
            *v354 = (hkpJacobianSchema)13;
          }
          goto LABEL_233;
        case 0x11u:
          if ( !LOBYTE(v9[1].m_type.m_storage) || (v364 = *(float *)&v9[4].m_type.m_storage, v364 == 0.0) )
          {
            atomc = (hkpSimpleContactConstraintAtom *)&v9[2];
            v382 = 2 * LOBYTE(v9[2].m_type.m_storage);
            v383 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v383 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v383 - 16) = 3;
            *(_BYTE *)(v383 - 12) = v382;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v383;
          }
          else
          {
            v365 = LOBYTE(v9[2].m_type.m_storage);
            v366 = v7->m_constraintRuntime.m_storage;
            v367 = v7->m_jacobianSchemas.m_storage;
            v368 = &baseA.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage);
            v369 = 0;
            atomc = (hkpSimpleContactConstraintAtom *)&v9[2];
            if ( LOBYTE(v9[2].m_type.m_storage) )
            {
              v789 = 1065353216;
              v370 = v366 - (struct hkpConstraintRuntime *)v368;
              v371 = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
              v372 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
              do
              {
                v373 = *v368;
                v374 = in->m_bodyA.m_storage;
                v375 = in->m_bodyB.m_storage;
                v376 = *v368;
                v377 = *v368;
                v367 += 48;
                ++v368;
                *(__m128 *)&v367[-48] = _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v373, v373, 85), v374->m_scratch1.m_quad),
                                            _mm_mul_ps(_mm_shuffle_ps(v376, v373, 0), v374->m_scratch0.m_quad)),
                                          _mm_mul_ps(_mm_shuffle_ps(v373, v373, 170), v374->m_scratch2.m_quad));
                v378 = _mm_xor_ps(v377, v372);
                v379 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v378, v378, 85), v375->m_scratch1.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v378, v378, 0), v375->m_scratch0.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v378, v378, 170), v375->m_scratch2.m_quad));
                *(__m128 *)&v367[-32] = v379;
                v380 = _mm_add_ps(
                         _mm_mul_ps(_mm_mul_ps(*(__m128 *)&v367[-48], *(__m128 *)&v367[-48]), v374->m_invMasses.m_quad),
                         _mm_mul_ps(_mm_mul_ps(v379, v379), v375->m_invMasses.m_quad));
                v972 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v380, v380, 85), _mm_shuffle_ps(v380, v380, 0)),
                           _mm_shuffle_ps(v380, v380, 170)),
                         *(__m128 *)&epsilon);
                v381 = _mm_rcp_ps(v972);
                v910 = _mm_mul_ps(v371, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v381, v972)), v381));
                *(__m128 *)&v367[-48] = _mm_shuffle_ps(
                                          *(__m128 *)&v367[-48],
                                          _mm_unpackhi_ps(*(__m128 *)&v367[-48], v910),
                                          196);
                *(__m128 *)&v367[-32] = _mm_shuffle_ps(
                                          *(__m128 *)&v367[-32],
                                          _mm_unpackhi_ps(
                                            *(__m128 *)&v367[-32],
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(
                                                (__m128)*(unsigned int *)((char *)&v368->m128_u32[-3] + v370),
                                                (__m128)*(unsigned int *)((char *)&v368->m128_u32[-3] + v370),
                                                0),
                                              _mm_shuffle_ps(
                                                (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                                (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                                0))),
                                          196);
                *(float *)&v367[-16] = v364 * in->m_microStepDeltaTime.m_storage;
                *(float *)&v367[-48] = *(float *)&v367[-48] + 0.00000011920929;
                v367[-48] = (hkpJacobianSchema)14;
                *(_DWORD *)&v367[-12] = v369++;
              }
              while ( v369 < v365 );
            }
            v8 = v771;
            v7->m_jacobianSchemas.m_storage = v367;
          }
          v9 += 8;
          v384 = 16i64 * LOBYTE(atomc->m_type.m_storage);
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + v384);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + v384;
          goto LABEL_232;
        case 0x12u:
          if ( *(_QWORD *)&v9[8].m_type.m_storage && LOBYTE(v9[1].m_type.m_storage) )
          {
            v385 = HIBYTE(v9[1].m_type.m_storage);
            v386 = (unsigned __int8)modulo3Table[v385 + 1];
            v387 = (unsigned __int8)modulo3Table[v385 + 2];
            v388 = (hkpSimpleContactConstraintAtom *)((char *)v7->m_constraintRuntime.m_storage
                                                    + (__int16)v9[2].m_type.m_storage);
            v389 = (float *)((char *)v7->m_constraintRuntime.m_storage + (__int16)v9[3].m_type.m_storage);
            v390 = *(hkpConstraintMotor **)&v9[8].m_type.m_storage;
            v391 = _mm_mul_ps(
                     *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + v386),
                     *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v387));
            atomd = v388;
            maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)v389;
            v948 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v391, v391, 85), _mm_shuffle_ps(v391, v391, 0)),
                     _mm_shuffle_ps(v391, v391, 170));
            v392 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         *(&baseB.m_rotation.m_col0.m_quad + v385),
                         *(&baseB.m_rotation.m_col0.m_quad + v385),
                         201),
                       *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v387)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v387),
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v387),
                         201),
                       *(&baseB.m_rotation.m_col0.m_quad + v385)));
            v393 = _mm_mul_ps(
                     _mm_shuffle_ps(v392, v392, 201),
                     *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + v386));
            v394 = _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v393, v393, 85), _mm_shuffle_ps(v393, v393, 0)),
                       _mm_shuffle_ps(v393, v393, 170)));
            v395 = _mm_mul_ps(v948, v394);
            v396 = _mm_cmple_ps((__m128)0i64, v394);
            v397 = _mm_or_ps(
                     _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v395),
                     _mm_cmplt_ps(*(__m128 *)_xmm, v395));
            v398 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v395), v397), _mm_andnot_ps(v397, v395));
            v399 = _mm_mul_ps(v398, v398);
            v400 = _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v399, *(__m128 *)s0)), *(__m128 *)t0),
                                     _mm_add_ps(v399, *(__m128 *)s1))),
                                 *(__m128 *)t1),
                               _mm_add_ps(v399, *(__m128 *)s2))),
                           *(__m128 *)t2),
                         _mm_add_ps(v399, *(__m128 *)s3))),
                     _mm_mul_ps(v398, *(__m128 *)t3));
            v401 = v9[4].m_type.m_storage;
            v402 = _mm_or_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v398, *(__m128 *)_xmm), *(__m128 *)_xmm), v400), v397),
                     _mm_andnot_ps(v397, v400));
            v403 = _mm_or_ps(
                     _mm_andnot_ps(
                       v396,
                       _mm_add_ps(_mm_or_ps(_mm_and_ps(v948, *(__m128 *)_xmm), *(__m128 *)_xmm), v402)),
                     _mm_and_ps(v402, v396));
            if ( v401 )
            {
              v404 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
              v405 = *(float *)((char *)v7->m_constraintRuntime.m_storage + v401 + 4);
              v912 = xmmword_141A713F0;
              v406 = 0i64;
              v982 = v404;
              v407 = _mm_sub_ps(
                       v403,
                       _mm_shuffle_ps(
                         (__m128)COERCE_UNSIGNED_INT(v405 * -1.0),
                         (__m128)COERCE_UNSIGNED_INT(v405 * -1.0),
                         0));
              do
              {
                v408 = (__m128i)_mm_mul_ps(_mm_add_ps(v407, (__m128)xmmword_141A713B0), v404);
                v409 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v408, 1u), 1u));
                v410 = _mm_sub_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_sub_ps((__m128)v408, *(__m128 *)two23), *(__m128 *)two23),
                           *(__m128 *)two23),
                         *(__m128 *)two23);
                v914 = _mm_or_ps(
                         _mm_andnot_ps(
                           v409,
                           _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v408, v410)), v410)),
                         _mm_and_ps((__m128)v408, v409));
                v406 = _mm_add_ps(v406, v914);
                v407 = _mm_sub_ps(v407, _mm_mul_ps(v914, (__m128)xmmword_141A713F0));
                v411 = _mm_cmplt_ps(v407, (__m128)xmmword_141A713B0);
              }
              while ( fmax(
                        0.0 - 3.1415927,
                        COERCE_FLOAT(_mm_andnot_ps(v411, (__m128)xmmword_141A713B0).m128_u32[0] | v407.m128_i32[0] & v411.m128_i32[0])) != v407.m128_f32[0] );
              v21 = _xmm[0];
              v403.m128_f32[0] = v403.m128_f32[0] - (float)(v406.m128_f32[0] * 6.2831855);
            }
            v242 = LOBYTE(v388->m_type.m_storage) == 0;
            v790 = v403.m128_i32[0];
            if ( v242 )
              *v389 = v403.m128_f32[0];
            input.m_lastResults = 0i64;
            v412 = in->m_bodyA.m_storage;
            v413 = in->m_bodyB.m_storage;
            v414 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v415 = HIBYTE(v9[1].m_type.m_storage);
            v791 = 1065353216;
            v416 = *(&baseA.m_rotation.m_col0.m_quad + v415);
            v417 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v416);
            *v414 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v416, v416, 85), v412->m_scratch1.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v416, v416, 0), v412->m_scratch0.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v416, v416, 170), v412->m_scratch2.m_quad));
            v418 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v417, v417, 85), v413->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v417, v417, 0), v413->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v417, v417, 170), v413->m_scratch2.m_quad));
            v419 = (__m128)v791;
            v414[1] = v418;
            v420 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v418, v418), v413->m_invMasses.m_quad),
                     _mm_mul_ps(_mm_mul_ps(*v414, *v414), v412->m_invMasses.m_quad));
            v950 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v420, v420, 85), _mm_shuffle_ps(v420, v420, 0)),
                       _mm_shuffle_ps(v420, v420, 170)),
                     *(__m128 *)&epsilon);
            v421 = _mm_rcp_ps(v950);
            v916 = _mm_mul_ps(
                     _mm_shuffle_ps(v419, v419, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v421, v950)), v421));
            *v414 = _mm_shuffle_ps(*v414, _mm_unpackhi_ps(*v414, v916), 196);
            LODWORD(input.m_effMass.m_storage) = v414->m128_i32[3];
            v422 = (hkpSolverResults *)out->m_constraintRuntime.m_storage;
            input.m_stepInfo.m_storage = in;
            input.m_lastResults = *v422;
            input.m_deltaTarget.m_storage = *(float *)&v9[6].m_type.m_storage - *v389;
            input.m_positionError.m_storage = *v389 - v403.m128_f32[0];
            hkCalcMotorData(v390, &input, &v821);
            v414[1].m128_f32[3] = v821.m_targetPosition.m_storage * in->m_subStepInvDeltaTime.m_storage;
            v7 = out;
            v423 = out->m_jacobianSchemas.m_storage + 64;
            *(float *)&v423[-64] = *(float *)out->m_jacobianSchemas.m_storage + 0.00000011920929;
            v423[-64] = (hkpJacobianSchema)15;
            *(float *)&v423[-32] = v821.m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
            *(float *)&v423[-28] = v821.m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
            *(float *)&v423[-24] = v821.m_targetVelocity.m_storage;
            *(float *)&v423[-20] = v821.m_tau.m_storage;
            v424 = v821.m_damping.m_storage;
            out->m_jacobianSchemas.m_storage = v423;
            *(float *)&v423[-16] = v424;
            v425 = *(float *)&v9[6].m_type.m_storage;
            if ( v425 != *(float *)maxAngularImpulse.m_real.m128_u64[0] || !LOBYTE(atomd->m_type.m_storage) )
            {
              *(float *)maxAngularImpulse.m_real.m128_u64[0] = v425;
              LOBYTE(atomd->m_type.m_storage) = 1;
            }
            out->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)out->m_constraintRuntime.m_storage
                                                                               + 16);
            v8 = v771;
            v9 += 20;
            out->m_constraintRuntimeInMainMemory.m_storage = (char *)out->m_constraintRuntimeInMainMemory.m_storage + 16;
          }
          else
          {
            v9 += 20;
            v426 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v426 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v426 - 16) = 3;
            *(_BYTE *)(v426 - 12) = 2;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v426;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 16);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
          }
          goto LABEL_232;
        case 0x13u:
          if ( LOBYTE(v9[1].m_type.m_storage) )
          {
            v427 = in->m_transformB.m_storage;
            v781 = (char *)v7->m_constraintRuntime.m_storage + (__int16)v9[2].m_type.m_storage;
            v794 = (__int64)v7->m_constraintRuntime.m_storage + (__int16)v9[3].m_type.m_storage;
            hkMatrix3f_setMulMat3Mat3(&THIS, &v427->m_rotation, (hkMatrix3f *)&v9[8]);
            v428 = v781;
            v429 = (hkpConstraintMotor **)&v9[32];
            v825.m_lastResults = 0i64;
            v825.m_stepInfo.m_storage = in;
            v820[0] = 0;
            v820[1] = 1;
            maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)&v9[32];
            v820[2] = 2;
            v818 = 1i64;
            v819 = 0;
            v430 = 0;
            sizeOfAllAtomsb = 0;
            v431 = 0i64;
            v784.m128_u64[0] = 0i64;
            v432 = 0i64;
            do
            {
              if ( *v429 )
              {
                v433 = *v429;
                v434 = *(int *)((char *)&v818 + v432);
                v435 = 2i64 * v820[v432 / 4];
                v793 = 619091349;
                v436 = 2 * v434;
                v437 = _mm_add_ps(
                         *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v435),
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v435));
                v438 = _mm_mul_ps(v437, v437);
                v439 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v438, v438, 85), _mm_shuffle_ps(v438, v438, 0)),
                         _mm_shuffle_ps(v438, v438, 170));
                v440 = _mm_rsqrt_ps(v439);
                v974 = v439;
                v441 = _mm_andnot_ps(
                         _mm_cmple_ps(v439, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v440, v439), v440)),
                             _mm_mul_ps(*(__m128 *)_xmm, v440)),
                           v439));
                v918 = v441;
                if ( v441.m128_f32[0] <= _mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0).m128_f32[0] )
                {
                  v444 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v435);
                }
                else
                {
                  v442 = _mm_rcp_ps(v441);
                  v443 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v442, v441)), v442);
                  v444 = _mm_mul_ps(v437, v443);
                  v954 = v443;
                }
                v955 = v444;
                v445 = _mm_shuffle_ps(v444, v444, 201);
                v446 = _mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm);
                v447 = _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(
                             *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v436),
                             *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v436),
                             201),
                           v444),
                         _mm_mul_ps(v445, *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v436)));
                v956 = _mm_shuffle_ps(v447, v447, 201);
                v448 = _mm_sub_ps(_mm_mul_ps(v956, v445), _mm_mul_ps(_mm_shuffle_ps(v956, v956, 201), v444));
                v957 = _mm_shuffle_ps(v448, v448, 201);
                v449 = _mm_mul_ps(v956, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v436));
                v920 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v449, v449, 85), _mm_shuffle_ps(v449, v449, 0)),
                         _mm_shuffle_ps(v449, v449, 170));
                v450 = _mm_mul_ps(v957, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v436));
                v451 = _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v450, v450, 85), _mm_shuffle_ps(v450, v450, 0)),
                           _mm_shuffle_ps(v450, v450, 170)));
                v452 = _mm_cmple_ps((__m128)0i64, v451);
                v453 = _mm_mul_ps(v451, v920);
                v454 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)_xmm, v453), _mm_cmpnle_ps(v446, v453));
                v455 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v453), v454), _mm_andnot_ps(v454, v453));
                v456 = _mm_mul_ps(v455, v455);
                v457 = _mm_mul_ps(
                         _mm_rcp_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_rcp_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_rcp_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v456, *(__m128 *)s0)), *(__m128 *)t0),
                                         _mm_add_ps(v456, *(__m128 *)s1))),
                                     *(__m128 *)t1),
                                   _mm_add_ps(v456, *(__m128 *)s2))),
                               *(__m128 *)t2),
                             _mm_add_ps(v456, *(__m128 *)s3))),
                         _mm_mul_ps(v455, *(__m128 *)t3));
                v799 = 619091349;
                v458 = _mm_or_ps(
                         _mm_and_ps(
                           _mm_sub_ps(_mm_or_ps(_mm_and_ps(v455, *(__m128 *)_xmm), *(__m128 *)_xmm), v457),
                           v454),
                         _mm_andnot_ps(v454, v457));
                v459 = _mm_add_ps(
                         *(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v435),
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v435));
                LODWORD(v792) = _mm_andnot_ps(
                                  v452,
                                  _mm_add_ps(_mm_or_ps(_mm_and_ps(v920, *(__m128 *)_xmm), *(__m128 *)_xmm), v458)).m128_u32[0] | v458.m128_i32[0] & v452.m128_i32[0];
                v460 = _mm_mul_ps(v459, v459);
                v461 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v460, v460, 85), _mm_shuffle_ps(v460, v460, 0)),
                         _mm_shuffle_ps(v460, v460, 170));
                v462 = _mm_rsqrt_ps(v461);
                v983 = v461;
                v463 = _mm_andnot_ps(
                         _mm_cmple_ps(v461, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v462, v461), v462)),
                             _mm_mul_ps(v462, *(__m128 *)_xmm)),
                           v461));
                v922 = v463;
                if ( v463.m128_f32[0] <= _mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0).m128_f32[0] )
                {
                  v466 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v435);
                }
                else
                {
                  v464 = _mm_rcp_ps(v463);
                  v465 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v464, v463)), v464);
                  v466 = _mm_mul_ps(v459, v465);
                  v958 = v465;
                }
                v959 = v466;
                v467 = _mm_shuffle_ps(v466, v466, 201);
                v468 = _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(
                             *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v436),
                             *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v436),
                             201),
                           v466),
                         _mm_mul_ps(v467, *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v436)));
                v960 = _mm_shuffle_ps(v468, v468, 201);
                v469 = _mm_sub_ps(_mm_mul_ps(v960, v467), _mm_mul_ps(_mm_shuffle_ps(v960, v960, 201), v466));
                v961 = _mm_shuffle_ps(v469, v469, 201);
                v470 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v436), v960);
                v924 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v470, v470, 85), _mm_shuffle_ps(v470, v470, 0)),
                         _mm_shuffle_ps(v470, v470, 170));
                v471 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v436), v961);
                v472 = _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v471, v471, 85), _mm_shuffle_ps(v471, v471, 0)),
                           _mm_shuffle_ps(v471, v471, 170)));
                v473 = _mm_cmple_ps((__m128)0i64, v472);
                v474 = _mm_mul_ps(v472, v924);
                v475 = _mm_or_ps(_mm_cmpnle_ps(v446, v474), _mm_cmplt_ps(*(__m128 *)_xmm, v474));
                v476 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v474), v475), _mm_andnot_ps(v475, v474));
                v477 = _mm_mul_ps(v476, v476);
                v478 = _mm_mul_ps(
                         _mm_rcp_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_rcp_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_rcp_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v477, *(__m128 *)s0)), *(__m128 *)t0),
                                         _mm_add_ps(v477, *(__m128 *)s1))),
                                     *(__m128 *)t1),
                                   _mm_add_ps(v477, *(__m128 *)s2))),
                               *(__m128 *)t2),
                             _mm_add_ps(v477, *(__m128 *)s3))),
                         _mm_mul_ps(v476, *(__m128 *)t3));
                v479 = _mm_or_ps(
                         _mm_and_ps(
                           _mm_sub_ps(_mm_or_ps(_mm_and_ps(v476, *(__m128 *)_xmm), *(__m128 *)_xmm), v478),
                           v475),
                         _mm_andnot_ps(v475, v478));
                v242 = *v428 == 0;
                v472.m128_i32[0] = _mm_andnot_ps(
                                     v473,
                                     _mm_add_ps(_mm_or_ps(_mm_and_ps(v924, *(__m128 *)_xmm), *(__m128 *)_xmm), v479)).m128_u32[0] | v479.m128_i32[0] & v473.m128_i32[0];
                v480 = v792;
                v797 = v472.m128_f32[0];
                if ( v242 )
                {
                  *(float *)(v794 + v432) = v792;
                  *v428 = 1;
                }
                v481 = in->m_bodyA.m_storage;
                v482 = in->m_bodyB.m_storage;
                v483 = (__m128 *)v7->m_jacobianSchemas.m_storage;
                v484 = v797;
                v485 = _mm_mul_ps(_mm_shuffle_ps(v466, v466, 85), v481->m_scratch1.m_quad);
                v787 = 1065353216;
                v486 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v466);
                *v483 = _mm_add_ps(
                          _mm_add_ps(v485, _mm_mul_ps(_mm_shuffle_ps(v466, v466, 0), v481->m_scratch0.m_quad)),
                          _mm_mul_ps(_mm_shuffle_ps(v466, v466, 170), v481->m_scratch2.m_quad));
                v487 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v486, v486, 85), v482->m_scratch1.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v486, v486, 0), v482->m_scratch0.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v486, v486, 170), v482->m_scratch2.m_quad));
                v483[1] = v487;
                v488 = _mm_add_ps(
                         _mm_mul_ps(_mm_mul_ps(*v483, *v483), v481->m_invMasses.m_quad),
                         _mm_mul_ps(_mm_mul_ps(v487, v487), v482->m_invMasses.m_quad));
                v976 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v488, v488, 85), _mm_shuffle_ps(v488, v488, 0)),
                           _mm_shuffle_ps(v488, v488, 170)),
                         *(__m128 *)&epsilon);
                v489 = _mm_rcp_ps(v976);
                v926 = _mm_mul_ps(
                         _mm_shuffle_ps((__m128)v787, (__m128)v787, 0),
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v489, v976)), v489));
                *v483 = _mm_shuffle_ps(*v483, _mm_unpackhi_ps(*v483, v926), 196);
                LODWORD(v825.m_effMass.m_storage) = v483->m128_i32[3];
                v483[3].m128_i32[1] = v430;
                v825.m_lastResults = *(hkpSolverResults *)((char *)out->m_constraintRuntime.m_storage + v431);
                v825.m_deltaTarget.m_storage = v484 - *(float *)(v794 + v432);
                v825.m_positionError.m_storage = *(float *)(v794 + v432) - v480;
                hkCalcMotorData(v433, &v825, &v822);
                v428 = v781;
                v430 = sizeOfAllAtomsb;
                v431 = v784.m128_u64[0];
                v483[1].m128_f32[3] = v822.m_targetPosition.m_storage * in->m_subStepInvDeltaTime.m_storage;
                v7 = out;
                v490 = out->m_jacobianSchemas.m_storage + 64;
                *(float *)&v490[-64] = *(float *)out->m_jacobianSchemas.m_storage + 0.00000011920929;
                v490[-64] = (hkpJacobianSchema)15;
                *(float *)&v490[-32] = v822.m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
                *(float *)&v490[-28] = v822.m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
                *(float *)&v490[-24] = v822.m_targetVelocity.m_storage;
                *(float *)&v490[-20] = v822.m_tau.m_storage;
                v491 = v822.m_damping.m_storage;
                out->m_jacobianSchemas.m_storage = v490;
                *(float *)&v490[-16] = v491;
                if ( v484 != *(float *)(v794 + v432) )
                  *(float *)(v794 + v432) = v484;
              }
              else
              {
                v492 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
                *(float *)(v492 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
                *(_BYTE *)(v492 - 16) = 3;
                *(_BYTE *)(v492 - 12) = 2;
                v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v492;
              }
              ++v430;
              ++v428;
              v431 += 16i64;
              v429 = (hkpConstraintMotor **)(maxAngularImpulse.m_real.m128_u64[0] + 8);
              v432 += 4i64;
              sizeOfAllAtomsb = v430;
              v781 = v428;
              maxAngularImpulse.m_real.m128_u64[0] += 8i64;
              v784.m128_u64[0] = v431;
            }
            while ( v430 < 3 );
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 48);
            v21 = _xmm[0];
            v8 = v771;
            v9 = v769 + 48;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 48;
          }
          else
          {
            v9 += 48;
            v493 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v493 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v493 - 16) = 3;
            *(_BYTE *)(v493 - 12) = 6;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v493;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 48);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 48;
          }
          goto LABEL_232;
        case 0x14u:
          v494 = *(__m128 *)&v9[8].m_type.m_storage;
          v495 = *(__m128 *)&v9[16].m_type.m_storage;
          v496 = *(_DWORD *)&v9[24].m_type.m_storage;
          v497 = *(_DWORD *)&v9[26].m_type.m_storage;
          v498 = in->m_bodyA.m_storage;
          v499 = in->m_bodyB.m_storage;
          v500 = (__m128 *)v7->m_jacobianSchemas.m_storage;
          v501 = _mm_sub_ps(baseB.m_translation.m_quad, v495);
          v502 = _mm_sub_ps(v494, baseA.m_translation.m_quad);
          v503 = _mm_mul_ps(v502, v502);
          if ( (float)((float)(_mm_shuffle_ps(v503, v503, 85).m128_f32[0] + _mm_shuffle_ps(v503, v503, 0).m128_f32[0])
                     + _mm_shuffle_ps(v503, v503, 170).m128_f32[0]) <= 0.00000011920929 )
          {
            v506 = transform.m_quad;
          }
          else
          {
            v504 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v503, v503, 85), _mm_shuffle_ps(v503, v503, 0)),
                     _mm_shuffle_ps(v503, v503, 170));
            v505 = _mm_rsqrt_ps(v504);
            v962 = v504;
            v506 = _mm_mul_ps(
                     v502,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v504, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v505, v504), v505)),
                         _mm_mul_ps(*(__m128 *)_xmm, v505))));
          }
          v830 = v506;
          v507 = _mm_mul_ps(v501, v501);
          if ( (float)((float)(_mm_shuffle_ps(v507, v507, 85).m128_f32[0] + _mm_shuffle_ps(v507, v507, 0).m128_f32[0])
                     + _mm_shuffle_ps(v507, v507, 170).m128_f32[0]) <= 0.00000011920929 )
          {
            v510 = _mm_xor_ps((__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), transform.m_quad);
          }
          else
          {
            v508 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v507, v507, 85), _mm_shuffle_ps(v507, v507, 0)),
                     _mm_shuffle_ps(v507, v507, 170));
            v509 = _mm_rsqrt_ps(v508);
            v928 = v508;
            v510 = _mm_mul_ps(
                     v501,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v508, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v509, v508), v509)),
                         _mm_mul_ps(*(__m128 *)_xmm, v509))));
          }
          v831 = v510;
          v826 = (__m128 *)v498;
          v827 = (__m128 *)v499;
          v835 = v497;
          v834 = v496;
          v511 = _mm_shuffle_ps((__m128)v497, (__m128)v497, 0);
          v828 = baseA.m_translation.m_quad;
          v829 = baseB.m_translation.m_quad;
          v832 = v494;
          v833 = v495;
          v836 = in->m_subStepInvDeltaTime.m_storage;
          v512 = _mm_mul_ps(v511, v510);
          v837 = in->m_virtMassFactor.m_storage;
          *v500 = v506;
          v500[1] = v512;
          v513 = _mm_sub_ps(v828, v826[7]);
          v514 = _mm_sub_ps(v829, v827[7]);
          v515 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v514, v514, 201), v512),
                   _mm_mul_ps(_mm_shuffle_ps(v512, v512, 201), v514));
          v516 = _mm_shuffle_ps(v515, v515, 201);
          v517 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v830, v830, 201), v513),
                   _mm_mul_ps(_mm_shuffle_ps(v513, v513, 201), v830));
          v518 = _mm_shuffle_ps(v517, v517, 201);
          v500[2] = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v518, v518, 85), v826[5]),
                        _mm_mul_ps(_mm_shuffle_ps(v518, v518, 0), v826[4])),
                      _mm_mul_ps(_mm_shuffle_ps(v518, v518, 170), v826[6]));
          v519 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v516, v516, 85), v827[5]),
                     _mm_mul_ps(_mm_shuffle_ps(v516, v516, 0), v827[4])),
                   _mm_mul_ps(_mm_shuffle_ps(v516, v516, 170), v827[6]));
          v500[3] = v519;
          v520 = _mm_add_ps(
                   _mm_mul_ps(_mm_mul_ps(v519, v519), v827[3]),
                   _mm_mul_ps(_mm_mul_ps(v500[2], v500[2]), v826[3]));
          v987 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v827[3], v827[3], 255), _mm_mul_ps(v511, v511)),
                       _mm_shuffle_ps(v826[3], v826[3], 255)),
                     *(__m128 *)&epsilon),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v520, v520, 85), _mm_shuffle_ps(v520, v520, 0)),
                     _mm_shuffle_ps(v520, v520, 170)));
          v521 = _mm_rcp_ps(v987);
          v930 = _mm_mul_ps(
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v521, v987)), v521),
                   _mm_shuffle_ps((__m128)LODWORD(v837), (__m128)LODWORD(v837), 0));
          v500[2] = _mm_shuffle_ps(v500[2], _mm_unpackhi_ps(v500[2], v930), 196);
          v522 = _mm_sub_ps(v829, v833);
          v523 = _mm_sub_ps(v832, v828);
          v524 = _mm_mul_ps(v522, v522);
          v525 = _mm_mul_ps(v523, v523);
          v526 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v524, v524, 85), _mm_shuffle_ps(v524, v524, 0)),
                   _mm_shuffle_ps(v524, v524, 170));
          v527 = _mm_rsqrt_ps(v526);
          v964 = v526;
          v528 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v527, v526), v527)),
                     _mm_mul_ps(v527, *(__m128 *)_xmm)),
                   v526);
          v932 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v525, v525, 85), _mm_shuffle_ps(v525, v525, 0)),
                   _mm_shuffle_ps(v525, v525, 170));
          v529 = _mm_rsqrt_ps(v932);
          v9 += 32;
          *v500 = _mm_shuffle_ps(
                    *v500,
                    _mm_unpackhi_ps(
                      *v500,
                      _mm_mul_ps(
                        _mm_sub_ps(
                          _mm_add_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v932, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v529, v932), v529)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v529)),
                                v932)),
                            _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v526, (__m128)0i64), v528), v511)),
                          _mm_shuffle_ps((__m128)v834, (__m128)v834, 0)),
                        _mm_shuffle_ps((__m128)LODWORD(v836), (__m128)LODWORD(v836), 0))),
                    196);
          v530 = (float *)v7->m_jacobianSchemas.m_storage;
          v531 = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
          v7->m_jacobianSchemas.m_storage += 64;
          *v530 = v531;
          *(_BYTE *)v530 = 11;
          goto LABEL_142;
        case 0x15u:
          v532 = v7->m_constraintRuntime.m_storage;
          v533 = 0i64;
          v534 = (__m128 *)v7->m_jacobianSchemas.m_storage;
          v535 = (float *)((char *)v532 + SHIBYTE(v9[4].m_type.m_storage));
          v536 = (float *)((char *)v532 + SLOBYTE(v9[5].m_type.m_storage));
          v537 = (unsigned int *)((char *)v532 + SHIBYTE(v9[5].m_type.m_storage));
          v7->m_jacobianSchemas.m_storage += 64;
          v538.m_quad = (__m128)baseA.m_translation;
          v539.m_quad = (__m128)baseB.m_translation;
          v540.m_quad = (__m128)baseA.m_rotation.m_col0;
          v541.m_quad = (__m128)baseB.m_rotation.m_col0;
          if ( LOBYTE(v9[4].m_type.m_storage) )
          {
            v796 = 1036831949;
            v549 = _mm_mul_ps(baseB.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad);
            if ( COERCE_FLOAT((unsigned int)(2
                                           * COERCE_INT(
                                               (float)(_mm_shuffle_ps(v549, v549, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v549, v549, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v549, v549, 170).m128_f32[0])) >> 1) < _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0).m128_f32[0] )
            {
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v534;
              v9 += 8;
              goto LABEL_142;
            }
            v547.m_quad = (__m128)baseB.m_rotation.m_col1;
          }
          else
          {
            v542 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 201),
                       baseB.m_rotation.m_col0.m_quad),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 201),
                       baseA.m_rotation.m_col0.m_quad));
            v543 = _mm_shuffle_ps(v542, v542, 201);
            v544 = _mm_mul_ps(v543, v543);
            v545 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v544, v544, 85), _mm_shuffle_ps(v544, v544, 0)),
                     _mm_shuffle_ps(v544, v544, 170));
            v978 = v545;
            if ( v545.m128_f32[0] < 1.4210855e-14 )
            {
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v534;
              v9 += 8;
              goto LABEL_142;
            }
            v546 = _mm_rsqrt_ps(v545);
            v533 = _mm_mul_ps(
                     v543,
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v546, v545), v546)),
                       _mm_mul_ps(*(__m128 *)_xmm, v546)));
            v547.m_quad = v533;
            v548 = _mm_mul_ps(
                     _mm_shuffle_ps(
                       (__m128)*(unsigned int *)&v9[2].m_type.m_storage,
                       (__m128)*(unsigned int *)&v9[2].m_type.m_storage,
                       0),
                     v533);
            v538.m_quad = _mm_add_ps(baseA.m_translation.m_quad, v548);
            v539.m_quad = _mm_add_ps(baseB.m_translation.m_quad, v548);
          }
          v550 = _mm_mul_ps(baseA.m_rotation.m_col1.m_quad, v547.m_quad);
          v551 = _mm_mul_ps(baseA.m_rotation.m_col2.m_quad, v547.m_quad);
          v934 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v550, v550, 0), _mm_shuffle_ps(v550, v550, 85)),
                   _mm_shuffle_ps(v550, v550, 170));
          v552 = _mm_rcp_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v551, v551, 85), _mm_shuffle_ps(v551, v551, 0)),
                     _mm_shuffle_ps(v551, v551, 170)));
          v553 = _mm_cmple_ps((__m128)0i64, v552);
          v554 = _mm_mul_ps(v552, v934);
          v555 = _mm_or_ps(
                   _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v554),
                   _mm_cmplt_ps(*(__m128 *)_xmm, v554));
          v556 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v554), v555), _mm_andnot_ps(v555, v554));
          v557 = _mm_mul_ps(v556, v556);
          v558 = _mm_sub_ps(v539.m_quad, v538.m_quad);
          v559 = _mm_mul_ps(
                   _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_rcp_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_rcp_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v557, *(__m128 *)s0)), *(__m128 *)t0),
                                   _mm_add_ps(v557, *(__m128 *)s1))),
                               *(__m128 *)t1),
                             _mm_add_ps(v557, *(__m128 *)s2))),
                         *(__m128 *)t2),
                       _mm_add_ps(v557, *(__m128 *)s3))),
                   _mm_mul_ps(v556, *(__m128 *)t3));
          v560 = _mm_mul_ps(v558, baseB.m_rotation.m_col0.m_quad);
          v561 = _mm_or_ps(
                   _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v556, *(__m128 *)_xmm), *(__m128 *)_xmm), v559), v555),
                   _mm_andnot_ps(v555, v559));
          LODWORD(v795) = _mm_andnot_ps(
                            v553,
                            _mm_add_ps(_mm_or_ps(_mm_and_ps(v934, *(__m128 *)_xmm), *(__m128 *)_xmm), v561)).m128_u32[0] | v561.m128_i32[0] & v553.m128_i32[0];
          v562 = (float)(_mm_shuffle_ps(v560, v560, 85).m128_f32[0] + _mm_shuffle_ps(v560, v560, 0).m128_f32[0])
               + _mm_shuffle_ps(v560, v560, 170).m128_f32[0];
          v563 = v795;
          if ( *v535 == 0.0 )
          {
            v564 = v562 / *(float *)&v9[2].m_type.m_storage;
            v565 = v795 - v564;
            *v535 = v795 - v564;
            if ( (float)(v563 - v564) == 0.0 )
              v565 = FLOAT_1_1920929eN8;
            *v535 = v565;
            *v536 = v563;
          }
          if ( (float)(v563 - *v536) > 3.1415927 )
            --*v537;
          if ( (float)(v563 - *v536) < -3.1415927 )
            ++*v537;
          v566 = in->m_bodyA.m_storage;
          *v536 = v563;
          v567 = _mm_cvtsi32_si128(*v537);
          v568 = in->m_bodyB.m_storage;
          v569 = (float)((float)(_mm_cvtepi32_ps(v567).m128_f32[0] * 6.2831855) + (float)(v563 - *v535))
               * *(float *)&v9[2].m_type.m_storage;
          if ( LOBYTE(v9[4].m_type.m_storage) )
          {
            v575 = v569 * 0.15915494;
            sizeOfAllAtomsl = *(_DWORD *)&v9[2].m_type.m_storage;
            v591 = in->m_virtMassFactor.m_storage;
            v770 = in->m_rhsFactor.m_storage;
            *(hkVector4f *)v534 = (hkVector4f)v541.m_quad;
            v592 = _mm_sub_ps(v538.m_quad, v566->m_scratch3.m_quad);
            v593 = _mm_sub_ps(v539.m_quad, v568->m_scratch3.m_quad);
            atomj = v591;
            v594 = _mm_shuffle_ps(v541.m_quad, v541.m_quad, 201);
            v595 = _mm_mul_ps(v594, v593);
            v596 = _mm_sub_ps(_mm_mul_ps(v594, v592), _mm_mul_ps(_mm_shuffle_ps(v592, v592, 201), v541.m_quad));
            v597 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v593, v593, 201), v541.m_quad), v595);
            v598 = _mm_mul_ps(_mm_shuffle_ps((__m128)sizeOfAllAtomsl, (__m128)sizeOfAllAtomsl, 0), v541.m_quad);
            v599 = _mm_add_ps(_mm_shuffle_ps(v596, v596, 201), v598);
            v600 = _mm_sub_ps(_mm_shuffle_ps(v597, v597, 201), v598);
            v534[1] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v599, v599, 85), v566->m_scratch1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v599, v599, 0), v566->m_scratch0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v599, v599, 170), v566->m_scratch2.m_quad));
            v601 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v600, v600, 85), v568->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v600, v600, 0), v568->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v600, v600, 170), v568->m_scratch2.m_quad));
            v534[2] = v601;
            v602 = v568->m_invMasses.m_quad;
            v603 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v534[1], v534[1]), v566->m_invMasses.m_quad),
                     _mm_mul_ps(_mm_mul_ps(v601, v601), v602));
            v604 = _mm_shuffle_ps(
                     v603,
                     _mm_unpackhi_ps(
                       v603,
                       _mm_max_ps(_mm_add_ps(v602, v566->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
                     196);
            v605 = _mm_add_ps(_mm_shuffle_ps(v604, v604, 78), v604);
            v864 = _mm_add_ps(_mm_shuffle_ps(v605, v605, 177), v605);
            v534[2] = _mm_shuffle_ps(v534[2], _mm_unpackhi_ps(v534[2], v864), 196);
            v606 = _mm_rcp_ps(v864);
            v587 = _mm_mul_ps(v558, v541.m_quad);
            v936 = _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v864, v606)), v606),
                     _mm_shuffle_ps((__m128)LODWORD(atomj), (__m128)LODWORD(atomj), 0));
            v589 = (__m128)LODWORD(v770);
            v588 = _mm_shuffle_ps(v587, v587, 85);
            v534[1] = _mm_shuffle_ps(v534[1], _mm_unpackhi_ps(v534[1], v936), 196);
            v590 = _mm_shuffle_ps(v587, v587, 0);
          }
          else
          {
            v570 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v533, v533, 201), v540.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v540.m_quad, v540.m_quad, 201), v533));
            v571 = _mm_mul_ps(_mm_shuffle_ps(v570, v570, 201), v541.m_quad);
            v572 = in->m_virtMassFactor.m_storage;
            *(hkVector4f *)v534 = (hkVector4f)v541.m_quad;
            v573 = _mm_sub_ps(v538.m_quad, v566->m_scratch3.m_quad);
            v574 = _mm_sub_ps(v539.m_quad, v568->m_scratch3.m_quad);
            sizeOfAllAtomsk = LODWORD(v572);
            v575 = v569
                 * (float)((float)(_mm_shuffle_ps(v571, v571, 85).m128_f32[0] + _mm_shuffle_ps(v571, v571, 0).m128_f32[0])
                         + _mm_shuffle_ps(v571, v571, 170).m128_f32[0]);
            v576 = _mm_shuffle_ps(v541.m_quad, v541.m_quad, 201);
            v577 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v574, v574, 201), v541.m_quad), _mm_mul_ps(v576, v574));
            v578 = _mm_sub_ps(_mm_mul_ps(v576, v573), _mm_mul_ps(_mm_shuffle_ps(v573, v573, 201), v541.m_quad));
            v579 = _mm_shuffle_ps(v577, v577, 201);
            v580 = _mm_shuffle_ps(v578, v578, 201);
            v534[1] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v580, v580, 85), v566->m_scratch1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v580, v580, 0), v566->m_scratch0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v580, v580, 170), v566->m_scratch2.m_quad));
            v581 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v579, v579, 85), v568->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v579, v579, 0), v568->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v579, v579, 170), v568->m_scratch2.m_quad));
            v534[2] = v581;
            v582 = v568->m_invMasses.m_quad;
            v583 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v534[1], v534[1]), v566->m_invMasses.m_quad),
                     _mm_mul_ps(_mm_mul_ps(v581, v581), v582));
            v584 = _mm_shuffle_ps(
                     v583,
                     _mm_unpackhi_ps(
                       v583,
                       _mm_max_ps(_mm_add_ps(v582, v566->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
                     196);
            v585 = _mm_add_ps(_mm_shuffle_ps(v584, v584, 78), v584);
            v863 = _mm_add_ps(_mm_shuffle_ps(v585, v585, 177), v585);
            v534[2] = _mm_shuffle_ps(v534[2], _mm_unpackhi_ps(v534[2], v863), 196);
            v586 = _mm_rcp_ps(v863);
            v587 = _mm_mul_ps(v558, v541.m_quad);
            v966 = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)sizeOfAllAtomsk, (__m128)sizeOfAllAtomsk, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v586, v863)), v586));
            v588 = _mm_shuffle_ps(v587, v587, 0);
            v534[1] = _mm_shuffle_ps(v534[1], _mm_unpackhi_ps(v534[1], v966), 196);
            v589 = (__m128)LODWORD(in->m_rhsFactor.m_storage);
            v590 = _mm_shuffle_ps(v587, v587, 85);
          }
          v9 += 8;
          *v534 = _mm_shuffle_ps(
                    *v534,
                    _mm_unpackhi_ps(
                      *v534,
                      _mm_mul_ps(
                        _mm_add_ps(_mm_add_ps(v590, v588), _mm_shuffle_ps(v587, v587, 170)),
                        _mm_shuffle_ps(v589, v589, 0))),
                    196);
          v534->m128_f32[3] = (float)(v562 - v575) * in->m_rhsFactor.m_storage;
          v607 = in->m_damping.m_storage;
          v534[3].m128_i32[0] = LODWORD(in->m_tau.m_storage);
          v534[3].m128_f32[1] = v607;
          v534->m128_f32[0] = v534->m128_f32[0] + 0.00000011920929;
          v534->m128_i8[0] = 7;
LABEL_142:
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 8);
          v21 = _xmm[0];
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
LABEL_232:
          v769 = v9;
LABEL_233:
          v23 = FLOAT_0_5;
          v11 = v847;
          v14 = v840;
          v22 = *(float *)&FLOAT_1_0;
          v5 = (__m128)v845;
          if ( v9 >= v8 )
            return;
          goto LABEL_3;
        case 0x16u:
          v608 = v7->m_constraintRuntime.m_storage;
          v609 = (__m128 *)v7->m_jacobianSchemas.m_storage;
          v610 = (float *)((char *)v608 + SHIBYTE(v9[6].m_type.m_storage));
          v611 = (float *)((char *)v608 + SLOBYTE(v9[7].m_type.m_storage));
          v612 = (int *)((char *)v608 + SHIBYTE(v9[7].m_type.m_storage));
          v7->m_jacobianSchemas.m_storage += 64;
          v613.m_quad = (__m128)baseA.m_rotation.m_col0;
          v614 = _mm_sub_ps(baseB.m_translation.m_quad, baseA.m_translation.m_quad);
          maxAngularImpulse.m_real = (__m128)baseB.m_rotation.m_col0;
          v615 = _mm_mul_ps(v614, v614);
          if ( (float)((float)(_mm_shuffle_ps(v615, v615, 85).m128_f32[0] + _mm_shuffle_ps(v615, v615, 0).m128_f32[0])
                     + _mm_shuffle_ps(v615, v615, 170).m128_f32[0]) < 1.4210855e-14 )
            goto LABEL_184;
          v616 = _mm_shuffle_ps(v614, v614, 201);
          v617 = _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 201);
          v618 = _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 201);
          v619 = _mm_sub_ps(_mm_mul_ps(v614, v617), _mm_mul_ps(baseA.m_rotation.m_col0.m_quad, v616));
          v620 = _mm_shuffle_ps(v619, v619, 201);
          v621 = _mm_sub_ps(_mm_mul_ps(baseB.m_rotation.m_col0.m_quad, v616), _mm_mul_ps(v614, v618));
          v622 = _mm_shuffle_ps(v621, v621, 201);
          v623 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v620, v620, 201), baseA.m_rotation.m_col0.m_quad),
                   _mm_mul_ps(v620, v617));
          v624 = _mm_shuffle_ps(v623, v623, 201);
          v625 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v622, v622, 201), baseB.m_rotation.m_col0.m_quad),
                   _mm_mul_ps(v622, v618));
          v626 = _mm_mul_ps(v624, v624);
          v627 = _mm_shuffle_ps(v625, v625, 201);
          v628 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v626, v626, 85), _mm_shuffle_ps(v626, v626, 0)),
                   _mm_shuffle_ps(v626, v626, 170));
          v629 = _mm_mul_ps(v627, v627);
          v985 = v628;
          v630 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v629, v629, 85), _mm_shuffle_ps(v629, v629, 0)),
                   _mm_shuffle_ps(v629, v629, 170));
          v938 = v630;
          if ( v628.m128_f32[0] < 1.4210855e-14 || v630.m128_f32[0] < 1.4210855e-14 )
          {
            v21 = _xmm[0];
LABEL_184:
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v609;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v9 += 8;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          }
          else
          {
            v631 = _mm_rsqrt_ps(v628);
            v632 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
            v633 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v631, v628), v631));
            v634 = _mm_mul_ps(*(__m128 *)_xmm, v631);
            v635 = _mm_rsqrt_ps(v630);
            v636 = _mm_mul_ps(v624, _mm_mul_ps(v633, v634));
            v637 = _mm_mul_ps(_mm_mul_ps(v635, v630), v635);
            v638 = _mm_mul_ps(baseA.m_rotation.m_col2.m_quad, v636);
            v639 = _mm_mul_ps(v627, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v637), _mm_mul_ps(*(__m128 *)_xmm, v635)));
            v640 = _mm_mul_ps(baseA.m_rotation.m_col1.m_quad, v636);
            v641 = _mm_mul_ps(baseB.m_rotation.m_col1.m_quad, v639);
            v642 = (__m128)*(unsigned int *)&v9[4].m_type.m_storage;
            v784 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         (__m128)*(unsigned int *)&v9[2].m_type.m_storage,
                         (__m128)*(unsigned int *)&v9[2].m_type.m_storage,
                         0),
                       v636),
                     baseA.m_translation.m_quad);
            v643 = _mm_mul_ps(baseB.m_rotation.m_col2.m_quad, v639);
            v644 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v642, v642, 0), v639), baseB.m_translation.m_quad);
            v968 = _mm_movelh_ps(
                     _mm_unpacklo_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v640, v640, 85), _mm_shuffle_ps(v640, v640, 0)),
                         _mm_shuffle_ps(v640, v640, 170)),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v641, v641, 85), _mm_shuffle_ps(v641, v641, 0)),
                         _mm_shuffle_ps(v641, v641, 170))),
                     v632);
            v645 = _mm_rcp_ps(
                     _mm_movelh_ps(
                       _mm_unpacklo_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v638, v638, 85), _mm_shuffle_ps(v638, v638, 0)),
                           _mm_shuffle_ps(v638, v638, 170)),
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v643, v643, 85), _mm_shuffle_ps(v643, v643, 0)),
                           _mm_shuffle_ps(v643, v643, 170))),
                       v632));
            v646 = _mm_cmple_ps((__m128)0i64, v645);
            v647 = _mm_mul_ps(v968, v645);
            v648 = _mm_or_ps(
                     _mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v647),
                     _mm_cmplt_ps(*(__m128 *)_xmm, v647));
            v649 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v647), v648), _mm_andnot_ps(v648, v647));
            v650 = _mm_mul_ps(v649, v649);
            v651 = _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v650, *(__m128 *)s0)), *(__m128 *)t0),
                                     _mm_add_ps(v650, *(__m128 *)s1))),
                                 *(__m128 *)t1),
                               _mm_add_ps(v650, *(__m128 *)s2))),
                           *(__m128 *)t2),
                         _mm_add_ps(v650, *(__m128 *)s3))),
                     _mm_mul_ps(v649, *(__m128 *)t3));
            v652 = _mm_or_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v649, *(__m128 *)_xmm), *(__m128 *)_xmm), v651), v648),
                     _mm_andnot_ps(v648, v651));
            v940 = _mm_or_ps(
                     _mm_andnot_ps(
                       v646,
                       _mm_add_ps(_mm_or_ps(_mm_and_ps(v968, *(__m128 *)_xmm), *(__m128 *)_xmm), v652)),
                     _mm_and_ps(v652, v646));
            v772 = v940.m128_u64[0];
            if ( *v610 == 0.0 )
            {
              v653 = v940.m128_f32[0];
              if ( v940.m128_f32[0] == 0.0 )
                v653 = FLOAT_1_1920929eN8;
              *v610 = v653;
              v654 = *((float *)&v772 + 1);
              if ( *((float *)&v772 + 1) == 0.0 )
                v654 = FLOAT_1_1920929eN8;
              v610[1] = v654;
              *(_QWORD *)v611 = v772;
            }
            if ( (float)(*(float *)&v772 - *v611) > 3.1415927 )
              --*v612;
            if ( (float)(*(float *)&v772 - *v611) < -3.1415927 )
              ++*v612;
            v655 = *((float *)&v772 + 1);
            if ( (float)(*((float *)&v772 + 1) - v611[1]) > 3.1415927 )
            {
              --v612[1];
              v655 = *((float *)&v772 + 1);
            }
            if ( (float)(v655 - v611[1]) < -3.1415927 )
              ++v612[1];
            *(_QWORD *)v611 = v772;
            v656 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v636, v636, 201), v613.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v613.m_quad, v613.m_quad, 201), v636));
            v657 = (float)((float)((float)*v612 * 6.2831855) + (float)(*(float *)&v772 - *v610))
                 * *(float *)&v9[2].m_type.m_storage;
            v658 = _mm_shuffle_ps(v656, v656, 201);
            v659 = (float)((float)(*((float *)&v772 + 1) - v610[1]) + (float)((float)v612[1] * 6.2831855))
                 * *(float *)&v9[4].m_type.m_storage;
            v660 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v639, v639, 201), maxAngularImpulse.m_real),
                     _mm_mul_ps(_mm_shuffle_ps(maxAngularImpulse.m_real, maxAngularImpulse.m_real, 201), v639));
            v661 = _mm_shuffle_ps(v660, v660, 201);
            v662 = _mm_mul_ps(v661, v658);
            if ( (float)((float)(_mm_shuffle_ps(v662, v662, 85).m128_f32[0] + _mm_shuffle_ps(v662, v662, 0).m128_f32[0])
                       + _mm_shuffle_ps(v662, v662, 170).m128_f32[0]) > 0.0 )
            {
              v659 = v659 * -1.0;
              v663 = _mm_add_ps(v658, v661);
              v666 = _mm_mul_ps(v663, v663);
              v665 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v666, v666, 85), _mm_shuffle_ps(v666, v666, 0)),
                       _mm_shuffle_ps(v666, v666, 170));
              v942 = v665;
            }
            else
            {
              v663 = _mm_sub_ps(v658, v661);
              v664 = _mm_mul_ps(v663, v663);
              v665 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v664, v664, 85), _mm_shuffle_ps(v664, v664, 0)),
                       _mm_shuffle_ps(v664, v664, 170));
              v980 = v665;
            }
            v667 = in->m_bodyB.m_storage;
            v668 = in->m_bodyA.m_storage;
            v669 = _mm_rsqrt_ps(v665);
            v670 = _mm_cmple_ps(v665, (__m128)0i64);
            v671 = _mm_mul_ps(v669, v665);
            v672 = v784;
            sizeOfAllAtomsm = LODWORD(in->m_virtMassFactor.m_storage);
            v673 = _mm_mul_ps(
                     v663,
                     _mm_andnot_ps(
                       v670,
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v671, v669)), _mm_mul_ps(v669, *(__m128 *)_xmm))));
            *v609 = v673;
            v674 = _mm_sub_ps(v672, v668->m_scratch3.m_quad);
            v675 = _mm_sub_ps(v644, v667->m_scratch3.m_quad);
            v676 = _mm_shuffle_ps(v673, v673, 201);
            v677 = _mm_sub_ps(_mm_mul_ps(v674, v676), _mm_mul_ps(_mm_shuffle_ps(v674, v674, 201), v673));
            v678 = _mm_shuffle_ps(v677, v677, 201);
            v679 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v675, v675, 201), v673), _mm_mul_ps(v675, v676));
            v609[1] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v678, v678, 85), v668->m_scratch1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v678, v678, 0), v668->m_scratch0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v678, v678, 170), v668->m_scratch2.m_quad));
            v680 = _mm_shuffle_ps(v679, v679, 201);
            v681 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v680, v680, 85), v667->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v680, v680, 0), v667->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v680, v680, 170), v667->m_scratch2.m_quad));
            v609[2] = v681;
            v682 = v668->m_invMasses.m_quad;
            v683 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v609[1], v609[1]), v682),
                     _mm_mul_ps(_mm_mul_ps(v681, v681), v667->m_invMasses.m_quad));
            v684 = _mm_shuffle_ps(
                     v683,
                     _mm_unpackhi_ps(
                       v683,
                       _mm_max_ps(_mm_add_ps(v682, v667->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
                     196);
            v685 = _mm_add_ps(_mm_shuffle_ps(v684, v684, 78), v684);
            v867 = _mm_add_ps(_mm_shuffle_ps(v685, v685, 177), v685);
            v609[2] = _mm_shuffle_ps(v609[2], _mm_unpackhi_ps(v609[2], v867), 196);
            v686 = _mm_rcp_ps(v867);
            v9 += 8;
            v21 = _xmm[0];
            v687 = _mm_mul_ps(_mm_sub_ps(v644, v784), v673);
            v970 = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)sizeOfAllAtomsm, (__m128)sizeOfAllAtomsm, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v686, v867)), v686));
            v609[1] = _mm_shuffle_ps(v609[1], _mm_unpackhi_ps(v609[1], v970), 196);
            *v609 = _mm_shuffle_ps(
                      *v609,
                      _mm_unpackhi_ps(
                        *v609,
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v687, v687, 85), _mm_shuffle_ps(v687, v687, 0)),
                            _mm_shuffle_ps(v687, v687, 170)),
                          _mm_shuffle_ps(
                            (__m128)LODWORD(in->m_rhsFactor.m_storage),
                            (__m128)LODWORD(in->m_rhsFactor.m_storage),
                            0))),
                      196);
            v609->m128_i32[3] = COERCE_UNSIGNED_INT((float)(v659 + v657) * in->m_rhsFactor.m_storage) ^ _xmm[0];
            v685.m128_i32[0] = LODWORD(in->m_damping.m_storage);
            v609[3].m128_i32[0] = LODWORD(in->m_tau.m_storage);
            v609[3].m128_i32[1] = v685.m128_i32[0];
            v609->m128_f32[0] = v609->m128_f32[0] + 0.00000011920929;
            v609->m128_i8[0] = 7;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
          }
          goto LABEL_232;
        case 0x17u:
          if ( LOBYTE(v9[1].m_type.m_storage) )
          {
            v39 = in->m_bodyA.m_storage;
            v40 = in->m_bodyB.m_storage;
            v41 = _mm_sub_ps(baseA.m_translation.m_quad, v39->m_scratch3.m_quad);
            v42 = _mm_sub_ps(baseB.m_translation.m_quad, v40->m_scratch3.m_quad);
            v43 = v39->m_invMasses.m_quad;
            v44 = v40->m_invMasses.m_quad;
            v45 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v40->m_scratch1.m_quad);
            v847 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v39->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v39->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v39->m_scratch2.m_quad));
            vLocalArmA.m_quad = v847;
            v840 = _mm_add_ps(
                     _mm_add_ps(v45, _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v40->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v40->m_scratch2.m_quad));
            vLocalArmB.m_quad = v840;
            v46 = _mm_max_ps(
                    _mm_shuffle_ps(v43, v43, 170),
                    _mm_max_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)));
            v47 = _mm_max_ps(
                    _mm_shuffle_ps(v44, v44, 170),
                    _mm_max_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)));
            v48 = _mm_mul_ps(v847, v847);
            v49 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v48, v48, 0), _mm_shuffle_ps(v48, v48, 85)),
                    _mm_shuffle_ps(v48, v48, 170));
            v50 = _mm_rsqrt_ps(v49);
            v986 = v49;
            v51 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50));
            v52 = _mm_mul_ps(*(__m128 *)_xmm, v50);
            v53 = _mm_mul_ps(v840, v840);
            v54 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                    _mm_shuffle_ps(v53, v53, 170));
            v55 = _mm_rsqrt_ps(v54);
            v907 = v54;
            v909 = _mm_max_ps(_mm_max_ps(v46, v47), *(__m128 *)&epsilon);
            v911 = _mm_max_ps(
                     _mm_max_ps(
                       _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v49, (__m128)0i64), _mm_mul_ps(v51, v52)), v46),
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v54, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                             _mm_mul_ps(*(__m128 *)_xmm, v55))),
                         v47)),
                     *(__m128 *)&epsilon);
            v56 = _mm_mul_ps(
                    _mm_shuffle_ps(
                      (__m128)*(unsigned int *)&v9[6].m_type.m_storage,
                      (__m128)*(unsigned int *)&v9[6].m_type.m_storage,
                      0),
                    _mm_shuffle_ps(
                      (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
                      (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
                      0));
            v57 = _mm_rcp_ps(v909);
            v58 = _mm_shuffle_ps(
                    (__m128)*(unsigned int *)&v9[4].m_type.m_storage,
                    (__m128)*(unsigned int *)&v9[4].m_type.m_storage,
                    0);
            v59 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v909, v57)), v57);
            v60 = _mm_rcp_ps(v911);
            v21 = _xmm[0];
            v913 = _mm_mul_ps(v59, v56);
            v61 = _mm_min_ps(v913, v58);
            v62 = _mm_shuffle_ps(
                    (__m128)*(unsigned int *)&v9[2].m_type.m_storage,
                    (__m128)*(unsigned int *)&v9[2].m_type.m_storage,
                    0);
            v845 = (__int128)v61;
            v915 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v911, v60)), v60), v56);
            maxLinearImpulse.m_real = _mm_min_ps(v915, v62);
          }
          v9 += 8;
          goto LABEL_232;
        case 0x18u:
          v63 = (hkpSimpleContactConstraintAtom *)v7->m_jacobianSchemas.m_storage;
          v64 = in->m_bodyB.m_storage;
          atom = v63;
          hkMatrix3f::setMul(&v813, (hkMatrix3f *)&in->m_bodyA.m_storage->m_scratch0, &baseA.m_rotation);
          hkMatrix3f::setMul(&v804, (hkMatrix3f *)&v64->m_scratch0, &baseB.m_rotation);
          v65 = (float)(v813.m_col1.m_quad.m128_f32[1] + v813.m_col0.m_quad.m128_f32[0])
              + v813.m_col2.m_quad.m128_f32[2];
          if ( v65 <= 0.0 )
          {
            v811 = 1;
            v812 = 2i64;
            v67 = v813.m_col1.m_quad.m128_f32[1] > v813.m_col0.m_quad.m128_f32[0];
            if ( v813.m_col2.m_quad.m128_f32[2] > v813.m_col0.m_quad.m128_f32[5 * v67] )
              v67 = 2i64;
            v68 = *(&v811 + v67);
            v69 = *(&v811 + v68);
            v70 = fsqrt(
                    (float)(v813.m_col0.m_quad.m128_f32[5 * v67]
                          - (float)(v813.m_col0.m_quad.m128_f32[5 * v69] + v813.m_col0.m_quad.m128_f32[5 * v68]))
                  + v22);
            v783.m128_f32[v67] = v70 * v23;
            v783.m128_f32[3] = (float)(v813.m_col0.m_quad.m128_f32[4 * v68 + v69]
                                     - v813.m_col0.m_quad.m128_f32[4 * v69 + v68])
                             * (float)(v23 / v70);
            v783.m128_f32[v68] = (float)(v813.m_col0.m_quad.m128_f32[4 * v68 + v67]
                                       + v813.m_col0.m_quad.m128_f32[4 * v67 + v68])
                               * (float)(v23 / v70);
            v783.m128_f32[v69] = (float)(v813.m_col0.m_quad.m128_f32[4 * v69 + v67]
                                       + v813.m_col0.m_quad.m128_f32[4 * v67 + v69])
                               * (float)(v23 / v70);
          }
          else
          {
            v66 = fsqrt(v65 + v22);
            v783.m128_f32[3] = v66 * v23;
            v783.m128_f32[0] = (float)(v813.m_col1.m_quad.m128_f32[2] - v813.m_col2.m_quad.m128_f32[1])
                             * (float)(v23 / v66);
            v783.m128_f32[1] = (float)(v813.m_col2.m_quad.m128_f32[0] - v813.m_col0.m_quad.m128_f32[2])
                             * (float)(v23 / v66);
            v783.m128_f32[2] = (float)(v813.m_col0.m_quad.m128_f32[1] - v813.m_col1.m_quad.m128_f32[0])
                             * (float)(v23 / v66);
          }
          v71 = _mm_mul_ps(v783, v783);
          v72 = _mm_add_ps(_mm_shuffle_ps(v71, v71, 78), v71);
          v73 = _mm_add_ps(_mm_shuffle_ps(v72, v72, 177), v72);
          v74 = _mm_rsqrt_ps(v73);
          v917 = v73;
          v75 = _mm_mul_ps(
                  v783,
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v74, v73), v74)),
                    _mm_mul_ps(*(__m128 *)_xmm, v74)));
          v919 = v75;
          v76 = (float)(v804.m_col1.m_quad.m128_f32[1] + v804.m_col0.m_quad.m128_f32[0])
              + v804.m_col2.m_quad.m128_f32[2];
          if ( v76 <= 0.0 )
          {
            v809 = 1;
            v810 = 2i64;
            v78 = v804.m_col1.m_quad.m128_f32[1] > v804.m_col0.m_quad.m128_f32[0];
            if ( v804.m_col2.m_quad.m128_f32[2] > v804.m_col0.m_quad.m128_f32[5 * v78] )
              v78 = 2i64;
            v79 = *(&v809 + v78);
            v80 = *(&v809 + v79);
            v81 = fsqrt(
                    (float)(v804.m_col0.m_quad.m128_f32[5 * v78]
                          - (float)(v804.m_col0.m_quad.m128_f32[5 * v80] + v804.m_col0.m_quad.m128_f32[5 * v79]))
                  + v22);
            v786.m128_f32[v78] = v81 * v23;
            v786.m128_f32[3] = (float)(v804.m_col0.m_quad.m128_f32[4 * v79 + v80]
                                     - v804.m_col0.m_quad.m128_f32[4 * v80 + v79])
                             * (float)(v23 / v81);
            v786.m128_f32[v79] = (float)(v804.m_col0.m_quad.m128_f32[4 * v78 + v79]
                                       + v804.m_col0.m_quad.m128_f32[4 * v79 + v78])
                               * (float)(v23 / v81);
            v786.m128_f32[v80] = (float)(v804.m_col0.m_quad.m128_f32[4 * v78 + v80]
                                       + v804.m_col0.m_quad.m128_f32[4 * v80 + v78])
                               * (float)(v23 / v81);
          }
          else
          {
            v77 = fsqrt(v76 + v22);
            v786.m128_f32[3] = v77 * v23;
            v786.m128_f32[0] = (float)(v804.m_col1.m_quad.m128_f32[2] - v804.m_col2.m_quad.m128_f32[1])
                             * (float)(v23 / v77);
            v786.m128_f32[1] = (float)(v804.m_col2.m_quad.m128_f32[0] - v804.m_col0.m_quad.m128_f32[2])
                             * (float)(v23 / v77);
            v786.m128_f32[2] = (float)(v804.m_col0.m_quad.m128_f32[1] - v804.m_col1.m_quad.m128_f32[0])
                             * (float)(v23 / v77);
          }
          v7 = out;
          v82 = _mm_mul_ps(v786, v786);
          v83 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 78), v82);
          v921 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 177), v83);
          v84 = _mm_rsqrt_ps(v921);
          v861 = _mm_mul_ps(
                   v786,
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v84, v921), v84)),
                     _mm_mul_ps(v84, *(__m128 *)_xmm)));
          *(__m128 *)&atom->m_info.m_flags = v75;
          *(__m128 *)atom->m_info.m_data = v861;
          *(__m128 *)&atom->m_type.m_storage = _mm_movelh_ps(
                                                 _mm_unpacklo_ps(
                                                   aabbOut.m_quad,
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       (__m128)LODWORD(in->m_tau.m_storage),
                                                       (__m128)LODWORD(in->m_tau.m_storage),
                                                       0),
                                                     _mm_shuffle_ps(
                                                       (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
                                                       (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
                                                       0))),
                                                 _mm_unpacklo_ps(v5, aabbOut.m_quad));
          *(float *)&atom->m_type.m_storage = *(float *)&atom->m_type.m_storage + 0.00000011920929;
          LOBYTE(atom->m_type.m_storage) = 32;
          out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)&atom[1];
LABEL_16:
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 24);
          v8 = v771;
          v9 += 8;
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 24;
          goto LABEL_232;
        case 0x19u:
          v85 = in->m_bodyA.m_storage;
          v86 = in->m_bodyB.m_storage;
          v87 = (__m128 *)v7->m_jacobianSchemas.m_storage;
          v88 = _mm_shuffle_ps(
                  (__m128)LODWORD(in->m_microStepDeltaTime.m_storage),
                  (__m128)LODWORD(in->m_microStepDeltaTime.m_storage),
                  0);
          v89 = _mm_mul_ps(*(__m128 *)&v9[40].m_type.m_storage, v88);
          v90 = _mm_mul_ps(*(__m128 *)&v9[32].m_type.m_storage, v88);
          v91 = *(__m128 *)&v9[24].m_type.m_storage;
          *v87 = _mm_mul_ps(*(__m128 *)&v9[16].m_type.m_storage, v88);
          v87[1] = _mm_mul_ps(v91, v88);
          v87[2] = v90;
          v87[3] = v89;
          v92 = _mm_sub_ps(baseA.m_translation.m_quad, v85->m_scratch3.m_quad);
          v93 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v92, v92, 85), v85->m_scratch1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v92, v92, 0), v85->m_scratch0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v92, v92, 170), v85->m_scratch2.m_quad));
          v94 = _mm_sub_ps(baseB.m_translation.m_quad, v86->m_scratch3.m_quad);
          v95 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v94, v94, 85), v86->m_scratch1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v94, v94, 0), v86->m_scratch0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v94, v94, 170), v86->m_scratch2.m_quad));
          v96 = _mm_mul_ps(v93, v93);
          v97 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                  _mm_shuffle_ps(v96, v96, 170));
          v98 = _mm_rsqrt_ps(v97);
          v923 = v97;
          v99 = _mm_mul_ps(v95, v95);
          v87[4] = _mm_shuffle_ps(
                     v93,
                     _mm_unpackhi_ps(
                       v93,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v97, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v98, v97), v98)),
                             _mm_mul_ps(*(__m128 *)_xmm, v98)),
                           v97))),
                     196);
          v925 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                   _mm_shuffle_ps(v99, v99, 170));
          v100 = _mm_rsqrt_ps(v925);
          v87[5] = _mm_shuffle_ps(
                     v95,
                     _mm_unpackhi_ps(
                       v95,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v925, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v100, v925), v100)),
                             _mm_mul_ps(*(__m128 *)_xmm, v100)),
                           v925))),
                     196);
          v101 = *(__m128 *)&v9[8].m_type.m_storage;
          v102 = _mm_shuffle_ps(v85->m_invMasses.m_quad, v85->m_invMasses.m_quad, 255);
          v103 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v101, v101, 85), in->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v101, v101, 0), in->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v101, v101, 170), in->m_transformA.m_storage->m_rotation.m_col2.m_quad));
          v104 = _mm_shuffle_ps(v103, v103, 85);
          v105 = _mm_shuffle_ps(v103, v103, 0);
          v106 = _mm_shuffle_ps(v103, v103, 170);
          v107 = _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(v86->m_scratch0.m_quad, v105), _mm_mul_ps(v104, v86->m_scratch1.m_quad)),
                   _mm_mul_ps(v86->m_scratch2.m_quad, v106));
          v108 = _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(v85->m_scratch0.m_quad, v105), _mm_mul_ps(v104, v85->m_scratch1.m_quad)),
                   _mm_mul_ps(v85->m_scratch2.m_quad, v106));
          v109 = _mm_shuffle_ps(v86->m_invMasses.m_quad, v86->m_invMasses.m_quad, 255);
          v927 = _mm_add_ps(v109, v102);
          v110 = _mm_rcp_ps(v927);
          v929 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v110, v927)), v110);
          v111 = _mm_mul_ps(v929, v102);
          v87[6] = _mm_mul_ps(_mm_mul_ps(v929, v109), v108);
          v87[7] = _mm_mul_ps(v107, v111);
          v112 = *(__m128 *)&v9[8].m_type.m_storage;
          v113 = _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0);
          v114 = _mm_shuffle_ps(v112, v112, 255);
          sizeOfAllAtomsf = LODWORD(in->m_subStepInvDeltaTime.m_storage);
          v115 = _mm_mul_ps(v112, v112);
          v9 += 48;
          v116 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                   _mm_shuffle_ps(v115, v115, 170));
          v931 = v116;
          v117 = _mm_rsqrt_ps(v116);
          v87[2] = _mm_shuffle_ps(v87[2], _mm_unpackhi_ps(v87[2], v113), 196);
          v21 = _xmm[0];
          v87[3] = _mm_shuffle_ps(
                     v87[3],
                     _mm_unpackhi_ps(
                       v87[3],
                       _mm_mul_ps(_mm_shuffle_ps((__m128)sizeOfAllAtomsf, (__m128)sizeOfAllAtomsf, 0), v113)),
                     196);
          v87[6] = _mm_shuffle_ps(
                     v87[6],
                     _mm_unpackhi_ps(
                       v87[6],
                       _mm_andnot_ps(
                         _mm_cmple_ps(v116, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v117, v116), v117)),
                             _mm_mul_ps(*(__m128 *)_xmm, v117)),
                           v116))),
                     196);
          v87[7] = _mm_shuffle_ps(v87[7], _mm_unpackhi_ps(v87[7], v114), 196);
          v87->m128_f32[0] = v87->m128_f32[0] + 0.00000011920929;
          v87->m128_i8[0] = 34;
          v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)&v87[8];
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 24);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 24;
          goto LABEL_232;
        case 0x1Au:
          v119 = in->m_bodyB.m_storage;
          v120 = *(__m128 *)&v9[24].m_type.m_storage;
          v121 = *(__m128 *)&v9[32].m_type.m_storage;
          v122 = *(__m128 *)&v9[40].m_type.m_storage;
          v123 = v7->m_jacobianSchemas.m_storage;
          sizeOfAllAtomsg = LODWORD(in->m_microStepDeltaTime.m_storage);
          maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)in->m_bodyA.m_storage;
          v118 = (__m128 *)maxAngularImpulse.m_real.m128_u64[0];
          v124 = _mm_shuffle_ps((__m128)sizeOfAllAtomsg, (__m128)sizeOfAllAtomsg, 0);
          *(__m128 *)v123 = _mm_mul_ps(*(__m128 *)&v9[16].m_type.m_storage, v124);
          *(__m128 *)&v123[16] = _mm_mul_ps(v120, v124);
          *(__m128 *)&v123[32] = _mm_mul_ps(v121, v124);
          *(__m128 *)&v123[48] = _mm_mul_ps(v122, v124);
          v125 = v118[5];
          v126 = v118[4];
          v127 = v118[6];
          v128 = v119->m_scratch1.m_quad;
          v129 = v119->m_scratch2.m_quad;
          v130 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 0), v126),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 85),
                       v125)),
                   _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 170), v127));
          v814 = v130;
          v815 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col1.m_quad, baseA.m_rotation.m_col1.m_quad, 0), v126),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseA.m_rotation.m_col1.m_quad, baseA.m_rotation.m_col1.m_quad, 85),
                       v125)),
                   _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col1.m_quad, baseA.m_rotation.m_col1.m_quad, 170), v127));
          v131 = _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col2.m_quad, baseA.m_rotation.m_col2.m_quad, 85), v125);
          v132 = v119->m_scratch0.m_quad;
          v816 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col2.m_quad, baseA.m_rotation.m_col2.m_quad, 0), v126),
                     v131),
                   _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col2.m_quad, baseA.m_rotation.m_col2.m_quad, 170), v127));
          v801 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 0), v132),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 85),
                       v128)),
                   _mm_mul_ps(_mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 170), v129));
          v133 = _mm_shuffle_ps(v815, v815, 85).m128_f32[0];
          v134 = _mm_shuffle_ps(v816, v816, 170).m128_f32[0];
          v802 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(baseB.m_rotation.m_col1.m_quad, baseB.m_rotation.m_col1.m_quad, 0), v132),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col1.m_quad, baseB.m_rotation.m_col1.m_quad, 85),
                       v128)),
                   _mm_mul_ps(_mm_shuffle_ps(baseB.m_rotation.m_col1.m_quad, baseB.m_rotation.m_col1.m_quad, 170), v129));
          v803 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(baseB.m_rotation.m_col2.m_quad, baseB.m_rotation.m_col2.m_quad, 0), v132),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col2.m_quad, baseB.m_rotation.m_col2.m_quad, 85),
                       v128)),
                   _mm_mul_ps(_mm_shuffle_ps(baseB.m_rotation.m_col2.m_quad, baseB.m_rotation.m_col2.m_quad, 170), v129));
          v135 = (float)(v133 + v130.m128_f32[0]) + v134;
          if ( v135 <= 0.0 )
          {
            v137 = 0i64;
            v807 = 1;
            if ( v133 > v130.m128_f32[0] )
              v137 = 1i64;
            v808 = 2i64;
            if ( v134 > v814.m128_f32[5 * v137] )
              v137 = 2i64;
            v138 = *(&v807 + v137);
            v139 = *(&v807 + v138);
            v140 = fsqrt((float)(v814.m128_f32[5 * v137] - (float)(v814.m128_f32[5 * v139] + v814.m128_f32[5 * v138])) + v22);
            v785.m128_f32[v137] = v140 * v23;
            v785.m128_f32[3] = (float)(v814.m128_f32[4 * v138 + v139] - v814.m128_f32[4 * v139 + v138])
                             * (float)(v23 / v140);
            v785.m128_f32[v138] = (float)(v814.m128_f32[4 * v138 + v137] + v814.m128_f32[4 * v137 + v138])
                                * (float)(v23 / v140);
            v785.m128_f32[v139] = (float)(v814.m128_f32[4 * v139 + v137] + v814.m128_f32[4 * v137 + v139])
                                * (float)(v23 / v140);
          }
          else
          {
            v136 = fsqrt(v135 + v22);
            v785.m128_f32[3] = v136 * v23;
            v785.m128_f32[0] = (float)(v815.m128_f32[2] - v816.m128_f32[1]) * (float)(v23 / v136);
            v785.m128_f32[1] = (float)(v816.m128_f32[0] - v814.m128_f32[2]) * (float)(v23 / v136);
            v785.m128_f32[2] = (float)(v814.m128_f32[1] - v815.m128_f32[0]) * (float)(v23 / v136);
          }
          v141 = v785;
          *(__m128 *)&v123[64] = v785;
          v142 = _mm_mul_ps(v141, v141);
          v143 = _mm_add_ps(_mm_shuffle_ps(v142, v142, 78), v142);
          v144 = _mm_add_ps(_mm_shuffle_ps(v143, v143, 177), v143);
          v145 = _mm_rsqrt_ps(v144);
          v933 = v144;
          v146 = _mm_mul_ps(v145, v144);
          v147 = v802.m128_f32[1];
          v148 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v146, v145));
          v146.m128_i32[0] = v802.m128_i32[1];
          v149 = _mm_mul_ps(v148, _mm_mul_ps(v145, *(__m128 *)_xmm));
          v150 = v803.m128_f32[2];
          *(__m128 *)&v123[64] = _mm_mul_ps(v149, *(__m128 *)&v123[64]);
          v151 = (float)(v146.m128_f32[0] + v801.m128_f32[0]) + v150;
          if ( v151 <= 0.0 )
          {
            v153 = 0i64;
            v805 = 1;
            if ( v147 > v801.m128_f32[0] )
              v153 = 1i64;
            v806 = 2i64;
            if ( v150 > v801.m128_f32[5 * v153] )
              v153 = 2i64;
            v154 = *(&v805 + v153);
            v155 = *(&v805 + v154);
            v156 = fsqrt((float)(v801.m128_f32[5 * v153] - (float)(v801.m128_f32[5 * v155] + v801.m128_f32[5 * v154])) + v22);
            v782.m128_f32[v153] = v156 * v23;
            v782.m128_f32[3] = (float)(v801.m128_f32[4 * v154 + v155] - v801.m128_f32[4 * v155 + v154])
                             * (float)(v23 / v156);
            v782.m128_f32[v154] = (float)(v801.m128_f32[4 * v154 + v153] + v801.m128_f32[4 * v153 + v154])
                                * (float)(v23 / v156);
            v782.m128_f32[v155] = (float)(v801.m128_f32[4 * v155 + v153] + v801.m128_f32[4 * v153 + v155])
                                * (float)(v23 / v156);
          }
          else
          {
            v152 = fsqrt(v151 + v22);
            v782.m128_f32[3] = v152 * v23;
            v782.m128_f32[0] = (float)(v802.m128_f32[2] - v803.m128_f32[1]) * (float)(v23 / v152);
            v782.m128_f32[1] = (float)(v803.m128_f32[0] - v801.m128_f32[2]) * (float)(v23 / v152);
            v782.m128_f32[2] = (float)(v801.m128_f32[1] - v802.m128_f32[0]) * (float)(v23 / v152);
          }
          v157 = v782;
          *(__m128 *)&v123[80] = v782;
          v158 = _mm_mul_ps(v157, v157);
          v159 = _mm_add_ps(_mm_shuffle_ps(v158, v158, 78), v158);
          v160 = _mm_add_ps(_mm_shuffle_ps(v159, v159, 177), v159);
          v161 = _mm_rsqrt_ps(v160);
          v935 = v160;
          *(__m128 *)&v123[80] = _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v161, v160), v161)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v161)),
                                   *(__m128 *)&v123[80]);
          v162 = _mm_shuffle_ps(v119->m_invMasses.m_quad, v119->m_invMasses.m_quad, 255);
          v163 = _mm_add_ps(
                   _mm_shuffle_ps(
                     *(__m128 *)(maxAngularImpulse.m_real.m128_u64[0] + 48),
                     *(__m128 *)(maxAngularImpulse.m_real.m128_u64[0] + 48),
                     255),
                   v162);
          v164 = _mm_rcp_ps(v163);
          v937 = v163;
          v939 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v164, v163)), v164);
          v941 = *(__m128 *)&v9[8].m_type.m_storage;
          v165 = v941;
          v166 = _mm_mul_ps(v941, qi.m_vec.m_quad);
          v167 = _mm_add_ps(_mm_shuffle_ps(v166, v166, 78), v166);
          v943 = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v167, v167, 177), v167), 0x1Fu),
                             0x1Fu),
                   qi.m_vec.m_quad);
          v168 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v941, v943), _mm_mul_ps(v939, v162)), v943);
          v169 = _mm_mul_ps(v168, v168);
          v170 = _mm_add_ps(_mm_shuffle_ps(v169, v169, 78), v169);
          v171 = _mm_add_ps(_mm_shuffle_ps(v170, v170, 177), v170);
          v172 = _mm_rsqrt_ps(v171);
          v945 = v171;
          v173 = _mm_mul_ps(*(__m128 *)_xmm, v172);
          v174 = _mm_mul_ps(_mm_mul_ps(v172, v171), v172);
          v175 = _mm_shuffle_ps(v941, v941, 201);
          v176 = _mm_mul_ps(
                   _mm_andnot_ps(_mm_cmple_ps(v171, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v174), v173)),
                   v168);
          v947 = v176;
          v177 = _mm_mul_ps(_mm_shuffle_ps(v176, v176, 201), v941);
          v21 = _xmm[0];
          v8 = v771;
          *(__m128 *)&v123[96] = v176;
          v9 += 48;
          v178 = _mm_sub_ps(_mm_mul_ps(v175, v176), v177);
          v179 = _mm_sub_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v165, v165, 255), v176), _mm_shuffle_ps(v178, v178, 201)),
                   _mm_mul_ps(_mm_shuffle_ps(v176, v176, 255), v165));
          v180 = _mm_mul_ps(v176, v165);
          v181 = _mm_add_ps(_mm_shuffle_ps(v180, v180, 78), v180);
          *(__m128 *)&v123[112] = _mm_shuffle_ps(
                                    v179,
                                    _mm_unpackhi_ps(v179, _mm_add_ps(_mm_shuffle_ps(v181, v181, 177), v181)),
                                    196);
          v182 = _mm_mul_ps(*(__m128 *)&v9[-40].m_type.m_storage, *(__m128 *)&v9[-40].m_type.m_storage);
          v183 = _mm_shuffle_ps(*(__m128 *)&v9[-32].m_type.m_storage, *(__m128 *)&v9[-32].m_type.m_storage, 255);
          sizeOfAllAtomsh = LODWORD(in->m_subStepInvDeltaTime.m_storage);
          v184 = _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0);
          *(__m128 *)v123 = _mm_shuffle_ps(*(__m128 *)v123, _mm_unpackhi_ps(*(__m128 *)v123, v184), 196);
          *(__m128 *)&v123[16] = _mm_shuffle_ps(
                                   *(__m128 *)&v123[16],
                                   _mm_unpackhi_ps(
                                     *(__m128 *)&v123[16],
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)sizeOfAllAtomsh, (__m128)sizeOfAllAtomsh, 0),
                                       v184)),
                                   196);
          *(__m128 *)&v123[32] = _mm_shuffle_ps(
                                   *(__m128 *)&v123[32],
                                   _mm_unpackhi_ps(
                                     *(__m128 *)&v123[32],
                                     _mm_sub_ps(
                                       query.m_quad,
                                       _mm_mul_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(_mm_shuffle_ps(v182, v182, 85), _mm_shuffle_ps(v182, v182, 0)),
                                           _mm_shuffle_ps(v182, v182, 170)),
                                         (__m128)xmmword_141A710D0))),
                                   196);
          *(__m128 *)&v123[48] = _mm_shuffle_ps(*(__m128 *)&v123[48], _mm_unpackhi_ps(*(__m128 *)&v123[48], v183), 196);
          *(float *)v123 = *(float *)v123 + 0.00000011920929;
          *v123 = (hkpJacobianSchema)35;
          v7->m_jacobianSchemas.m_storage = v123 + 128;
          v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                            + 24);
          v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 24;
          goto LABEL_232;
        case 0x1Cu:
          if ( LOBYTE(v9[1].m_type.m_storage) && *(float *)&v9[4].m_type.m_storage > 0.0 )
          {
            v688 = in->m_bodyB.m_storage;
            v689 = in->m_bodyA.m_storage;
            v690.m_quad = (__m128)baseA.m_translation;
            sizeOfAllAtomsn = LODWORD(in->m_virtMassFactor.m_storage);
            v691.m_quad = (__m128)baseA.m_translation;
            v692.m_quad = (__m128)baseA.m_translation;
            v693 = *(&baseB.m_rotation.m_col0.m_quad + HIBYTE(v9[1].m_type.m_storage));
            v694 = *(&baseB.m_rotation.m_col0.m_quad + LOBYTE(v9[2].m_type.m_storage));
            v695 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v696 = _mm_shuffle_ps(v693, v693, 201);
            *v695 = v693;
            v697 = _mm_sub_ps(v692.m_quad, v688->m_scratch3.m_quad);
            v698 = _mm_sub_ps(v691.m_quad, v689->m_scratch3.m_quad);
            v699 = _mm_sub_ps(_mm_mul_ps(v698, v696), _mm_mul_ps(_mm_shuffle_ps(v698, v698, 201), v693));
            v700 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v697, v697, 201), v693), _mm_mul_ps(v697, v696));
            v701 = _mm_shuffle_ps(v700, v700, 201);
            v702 = _mm_shuffle_ps(v699, v699, 201);
            v695[1] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v702, v702, 0), v689->m_scratch0.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v702, v702, 85), v689->m_scratch1.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v702, v702, 170), v689->m_scratch2.m_quad));
            v703 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v701, v701, 85), v688->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v701, v701, 0), v688->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v701, v701, 170), v688->m_scratch2.m_quad));
            v695[2] = v703;
            v704 = v689->m_invMasses.m_quad;
            v705 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v695[1], v695[1]), v704),
                     _mm_mul_ps(_mm_mul_ps(v703, v703), v688->m_invMasses.m_quad));
            v706 = _mm_shuffle_ps(
                     v705,
                     _mm_unpackhi_ps(
                       v705,
                       _mm_max_ps(_mm_add_ps(v704, v688->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
                     196);
            v707 = _mm_add_ps(_mm_shuffle_ps(v706, v706, 78), v706);
            v859 = _mm_add_ps(_mm_shuffle_ps(v707, v707, 177), v707);
            v695[2] = _mm_shuffle_ps(v695[2], _mm_unpackhi_ps(v695[2], v859), 196);
            v708 = _mm_rcp_ps(v859);
            v709 = _mm_shuffle_ps(v694, v694, 201);
            v944 = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)sizeOfAllAtomsn, (__m128)sizeOfAllAtomsn, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v708, v859)), v708));
            v695[1] = _mm_shuffle_ps(v695[1], _mm_unpackhi_ps(v695[1], v944), 196);
            v695->m128_f32[3] = in->m_frictionRhsFactor.m_storage * 0.0;
            v707.m128_i32[0] = LODWORD(in->m_virtMassFactor.m_storage);
            v695[3] = v694;
            v710 = _mm_sub_ps(v690.m_quad, v689->m_scratch3.m_quad);
            v711 = _mm_sub_ps(v690.m_quad, v688->m_scratch3.m_quad);
            sizeOfAllAtomso = v707.m128_i32[0];
            v712 = _mm_sub_ps(_mm_mul_ps(v709, v710), _mm_mul_ps(_mm_shuffle_ps(v710, v710, 201), v694));
            v713 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v711, v711, 201), v694), _mm_mul_ps(v709, v711));
            v714 = _mm_shuffle_ps(v712, v712, 201);
            v715 = _mm_shuffle_ps(v713, v713, 201);
            v695[4] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v714, v714, 0), v689->m_scratch0.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v714, v714, 85), v689->m_scratch1.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v714, v714, 170), v689->m_scratch2.m_quad));
            v716 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v715, v715, 85), v688->m_scratch1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v715, v715, 0), v688->m_scratch0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v715, v715, 170), v688->m_scratch2.m_quad));
            v695[5] = v716;
            v717 = v689->m_invMasses.m_quad;
            v718 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v695[4], v695[4]), v717),
                     _mm_mul_ps(_mm_mul_ps(v716, v716), v688->m_invMasses.m_quad));
            v719 = _mm_shuffle_ps(
                     v718,
                     _mm_unpackhi_ps(
                       v718,
                       _mm_max_ps(_mm_add_ps(v717, v688->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
                     196);
            v720 = _mm_add_ps(_mm_shuffle_ps(v719, v719, 78), v719);
            v860 = _mm_add_ps(_mm_shuffle_ps(v720, v720, 177), v720);
            v695[5] = _mm_shuffle_ps(v695[5], _mm_unpackhi_ps(v695[5], v860), 196);
            v721 = _mm_rcp_ps(v860);
            v788 = 1065353216;
            v904 = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)sizeOfAllAtomso, (__m128)sizeOfAllAtomso, 0),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v721, v860)), v721));
            v695[4] = _mm_shuffle_ps(v695[4], _mm_unpackhi_ps(v695[4], v904), 196);
            v695[3].m128_f32[3] = in->m_frictionRhsFactor.m_storage * 0.0;
            sizeOfAllAtomsp = LODWORD(in->m_virtMassFactor.m_storage);
            v722 = _mm_mul_ps(*v695, v695[3]);
            v723 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v689->m_invMasses.m_quad, v689->m_invMasses.m_quad, 255), v722),
                       _mm_mul_ps(_mm_shuffle_ps(v688->m_invMasses.m_quad, v688->m_invMasses.m_quad, 255), v722)),
                     _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v695[5], v695[2]), v688->m_invMasses.m_quad),
                       _mm_mul_ps(_mm_mul_ps(v695[4], v695[1]), v689->m_invMasses.m_quad)));
            v724 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v723, v723, 85), _mm_shuffle_ps(v723, v723, 0)),
                     _mm_shuffle_ps(v723, v723, 170));
            v725 = _mm_shuffle_ps(v695[5], v695[5], 255);
            v726 = _mm_mul_ps(v724, _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0));
            v727 = _mm_shuffle_ps(v695[2], v695[2], 255);
            v728 = _mm_sub_ps(_mm_mul_ps(v725, v727), _mm_mul_ps(v726, v726));
            v729 = _mm_rcp_ps(v728);
            v905 = v728;
            v838 = _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v729, v728)), v729),
                     _mm_shuffle_ps((__m128)sizeOfAllAtomsp, (__m128)sizeOfAllAtomsp, 0));
            v695[2] = _mm_shuffle_ps(v695[2], _mm_unpackhi_ps(v695[2], _mm_mul_ps(v725, v838)), 196);
            v695[5] = _mm_shuffle_ps(v695[5], _mm_unpackhi_ps(v695[5], _mm_mul_ps(v727, v838)), 196);
            v695 += 7;
            v720.m128_f32[0] = in->m_microStepDeltaTime.m_storage * *(float *)&v9[4].m_type.m_storage;
            v729.m128_f32[0] = (float)(0.0 - v726.m128_f32[0]) * v838.m128_f32[0];
            v695[-1].m128_u64[1] = (unsigned __int64)v9;
            v695[-1].m128_i32[0] = v729.m128_i32[0];
            v695[-1].m128_i32[1] = v720.m128_i32[0];
            v695[-7].m128_f32[0] = v695[-7].m128_f32[0] + 0.00000011920929;
            v695[-7].m128_i8[0] = 43;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v695;
          }
          else
          {
            v730 = (__int64)&v7->m_jacobianSchemas.m_storage[16];
            *(float *)(v730 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            *(_BYTE *)(v730 - 16) = 3;
            *(_BYTE *)(v730 - 12) = 0;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v730;
          }
          goto LABEL_231;
        case 0x1Eu:
          v7->m_jacobianSchemas.m_storage -= 32;
          v990.m_beginConstraints = hkpBeginConstraints;
          v736 = *(float *)&v9[24].m_type.m_storage;
          hkpConstraintQueryIn::operator=(&v990, in);
          v737 = v9;
          v990.m_virtMassFactor.m_storage = v736 * in->m_virtMassFactor.m_storage;
          v990.m_tau.m_storage = v736 * in->m_tau.m_storage;
          v990.m_damping.m_storage = v736 * in->m_damping.m_storage;
          atomf = v9[9].m_type.m_storage;
          do
            v737 = *(hkpConstraintAtom **)&v737[12].m_type.m_storage;
          while ( v737->m_type.m_storage >= 0x1Eu );
          v738 = v737[2].m_type.m_storage;
          v739 = LOBYTE(v737[5].m_type.m_storage);
          v740 = 0i64;
          v741 = &v737[16 * v737[3].m_type.m_storage + 24];
          if ( v738 >= 4 )
          {
            v742 = LOBYTE(v737[5].m_type.m_storage);
            p_m_storage = (float *)&v737[54].m_type.m_storage;
            v744 = ((v738 - 4) >> 2) + 1;
            v740 = 4 * v744;
            do
            {
              v745 = (float)((float)((float)(in->m_microStepDeltaTime.m_storage * *(float *)&v9[26].m_type.m_storage)
                                   * in->m_subStepDeltaTime.m_storage)
                           / *(float *)&v9[24].m_type.m_storage)
                   + *(p_m_storage - 8);
              if ( v745 < *(float *)&v741[12].m_type.m_storage )
                *(float *)&v741[12].m_type.m_storage = v745;
              v746 = (__int64)v741 + v742;
              v747 = (float)((float)((float)(in->m_microStepDeltaTime.m_storage * *(float *)&v9[26].m_type.m_storage)
                                   * in->m_subStepDeltaTime.m_storage)
                           / *(float *)&v9[24].m_type.m_storage)
                   + *p_m_storage;
              if ( v747 < *(float *)(v746 + 24) )
                *(float *)(v746 + 24) = v747;
              v748 = v742 + v746;
              v749 = (float)((float)((float)(in->m_microStepDeltaTime.m_storage * *(float *)&v9[26].m_type.m_storage)
                                   * in->m_subStepDeltaTime.m_storage)
                           / *(float *)&v9[24].m_type.m_storage)
                   + p_m_storage[8];
              if ( v749 < *(float *)(v748 + 24) )
                *(float *)(v748 + 24) = v749;
              v750 = v742 + v748;
              v751 = (float)((float)((float)(in->m_microStepDeltaTime.m_storage * *(float *)&v9[26].m_type.m_storage)
                                   * in->m_subStepDeltaTime.m_storage)
                           / *(float *)&v9[24].m_type.m_storage)
                   + p_m_storage[16];
              if ( v751 < *(float *)(v750 + 24) )
                *(float *)(v750 + 24) = v751;
              v741 = (hkpConstraintAtom *)(v742 + v750);
              p_m_storage += 32;
              --v744;
            }
            while ( v744 );
            v739 = v742;
          }
          if ( v740 < (__int64)v738 )
          {
            v752 = (float *)&v741[12].m_type.m_storage;
            v753 = (float *)&v737[16 * v740 + 38].m_type.m_storage;
            v754 = v738 - v740;
            do
            {
              v755 = (float)((float)((float)(in->m_microStepDeltaTime.m_storage * *(float *)&v9[26].m_type.m_storage)
                                   * in->m_subStepDeltaTime.m_storage)
                           / *(float *)&v9[24].m_type.m_storage)
                   + *v753;
              if ( v755 < *v752 )
                *v752 = v755;
              v752 = (float *)((char *)v752 + v739);
              v753 += 8;
              --v754;
            }
            while ( v754 );
          }
          v756 = *(hkpSimpleContactConstraintAtom **)&v9[12].m_type.m_storage;
          if ( v756->m_type.m_storage == 29 )
            hkSimpleContactConstraintDataBuildJacobian(v756, &v990, (hkBool)1, v7);
          else
            hkSolverBuildJacobianFromAtomsNotContact(v756, atomf, &v990, v7);
          v8 = v771;
          v9 += 32;
          goto LABEL_232;
        case 0x1Fu:
          v883 = *in;
          v759 = *(__m128 *)&v9[24].m_type.m_storage;
          v760 = *(__m128 *)&v9[32].m_type.m_storage;
          atomg = *(hkpSimpleContactConstraintAtom **)&v9[12].m_type.m_storage;
          sizeOfAllAtomse = v9[9].m_type.m_storage;
          v761 = in->m_bodyA.m_storage;
          v891[0] = *(_OWORD *)&v761->m_type.m_storage;
          v891[1] = (__int128)v761->m_linearVel;
          v891[2] = (__int128)v761->m_angularVel;
          invMassA.m_quad = (__m128)v761->m_invMasses;
          v893.m_quad = (__m128)v761->m_scratch0;
          v894.m_quad = (__m128)v761->m_scratch1;
          v895.m_quad = (__m128)v761->m_scratch2;
          v896.m_quad = (__m128)v761->m_scratch3;
          v762 = in->m_bodyB.m_storage;
          v885[0] = *(_OWORD *)&v762->m_type.m_storage;
          v885[1] = (__int128)v762->m_linearVel;
          v885[2] = (__int128)v762->m_angularVel;
          invMassB.m_quad = (__m128)v762->m_invMasses;
          v887.m_quad = (__m128)v762->m_scratch0;
          v888.m_quad = (__m128)v762->m_scratch1;
          v889.m_quad = (__m128)v762->m_scratch2;
          m_scratch3 = (__int128)v762->m_scratch3;
          invMassA.m_quad = _mm_mul_ps(invMassA.m_quad, v759);
          v883.m_bodyA.m_storage = (hkpVelocityAccumulator *)v891;
          v883.m_bodyB.m_storage = (hkpVelocityAccumulator *)v885;
          v890 = m_scratch3;
          invMassB.m_quad = _mm_mul_ps(invMassB.m_quad, v760);
          hkSetInvMassBuildJacobian(&invMassA, &invMassB, v7);
          if ( atomg->m_type.m_storage == 29 )
            hkSimpleContactConstraintDataBuildJacobian(atomg, &v883, (hkBool)1, v7);
          else
            hkSolverBuildJacobianFromAtomsNotContact(atomg, sizeOfAllAtomse, &v883, v7);
          hkSetInvMassBuildJacobian(&in->m_bodyA.m_storage->m_invMasses, &in->m_bodyB.m_storage->m_invMasses, v7);
          v8 = v771;
          v9 += 40;
          goto LABEL_232;
        case 0x20u:
          v7->m_jacobianSchemas.m_storage -= 32;
          v757 = v9;
          v902 = *in;
          sizeOfAllAtomsd = v9[9].m_type.m_storage;
          do
            v757 = *(hkpConstraintAtom **)&v757[12].m_type.m_storage;
          while ( v757->m_type.m_storage >= 0x1Eu );
          hkSimpleContactConstraintDataAddALittleSurfaceViscosity((hkpSimpleContactConstraintDataInfo *)&v757[8]);
          v758 = *(hkpSimpleContactConstraintAtom **)&v9[12].m_type.m_storage;
          if ( v758->m_type.m_storage == 29 )
            hkSimpleContactConstraintDataBuildJacobian(v758, &v902, (hkBool)1, v7);
          else
            hkSolverBuildJacobianFromAtomsNotContact(v758, sizeOfAllAtomsd, &v902, v7);
          v8 = v771;
          goto LABEL_231;
        case 0x21u:
          v764 = *(__m128 *)&v9[24].m_type.m_storage;
          v900 = *in;
          v765 = *(hkpSimpleContactConstraintAtom **)&v9[12].m_type.m_storage;
          v7->m_jacobianSchemas.m_storage -= 32;
          atomh = v765;
          hkInitHeader(
            in,
            (hkpSolverResults *)&v765[1] + 4 * v765->m_numReservedContactPoints,
            (unsigned __int8)v765->m_contactPointPropertiesStriding,
            v7);
          v766 = in->m_accumulatorAIndex.m_storage == 0;
          if ( in->m_accumulatorAIndex.m_storage )
          {
            hkpVelocityAccumulator::operator=(&v991, in->m_bodyA.m_storage);
            v900.m_bodyA.m_storage = &v991;
          }
          else
          {
            hkpVelocityAccumulator::operator=(&v991, in->m_bodyB.m_storage);
            v900.m_bodyB.m_storage = &v991;
            v764 = _mm_xor_ps(v764, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
          }
          v767 = _mm_mul_ps(*(__m128 *)&atomh[1].m_info.m_flags, v764);
          v768 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          deltaVel.m_quad = _mm_xor_ps(
                              _mm_sub_ps(
                                v764,
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v767, v767, 85), _mm_shuffle_ps(v767, v767, 0)),
                                    _mm_shuffle_ps(v767, v767, 170)),
                                  *(__m128 *)&atomh[1].m_info.m_flags)),
                              v768);
          hkAddVelocityBuildJacobian(&deltaVel, v766, out);
          v991.m_linearVel.m_quad = _mm_add_ps(v991.m_linearVel.m_quad, deltaVel.m_quad);
          hkSimpleContactConstraintDataBuildJacobian(atomh, &v900, 0, out);
          deltaVel.m_quad = _mm_xor_ps(deltaVel.m_quad, v768);
          hkAddVelocityBuildJacobian(&deltaVel, v766, out);
          v7 = out;
          v8 = v771;
          v9 += 32;
          goto LABEL_232;
        case 0x22u:
          v7->m_jacobianSchemas.m_storage -= 32;
LABEL_231:
          v9 += 24;
          goto LABEL_232;
        case 0x23u:
          ina = *in;
          v731 = *(__m128 *)&v9[24].m_type.m_storage;
          atome = *(hkpSimpleContactConstraintAtom **)&v9[12].m_type.m_storage;
          sizeOfAllAtomsc = v9[9].m_type.m_storage;
          r.m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v731, v731, 85),
                           in->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v731, v731, 0), in->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v731, v731, 170), in->m_transformA.m_storage->m_rotation.m_col2.m_quad));
          v732 = *(__m128 *)&v9[32].m_type.m_storage;
          v862.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v732, v732, 85),
                              in->m_transformB.m_storage->m_rotation.m_col1.m_quad),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v732, v732, 0),
                              in->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v732, v732, 170),
                            in->m_transformB.m_storage->m_rotation.m_col2.m_quad));
          v733 = in->m_bodyA.m_storage;
          v869 = *(_OWORD *)&v733->m_type.m_storage;
          v870 = v733->m_linearVel.m_quad;
          v871 = v733->m_angularVel.m_quad;
          v872.m_quad = (__m128)v733->m_invMasses;
          cTb = *(hkRotationf *)v733->m_scratch0.m_quad.m128_i8;
          v874 = v733->m_scratch3.m_quad;
          v734 = in->m_bodyB.m_storage;
          v875 = *(_OWORD *)&v734->m_type.m_storage;
          v876 = v734->m_linearVel.m_quad;
          v877 = v734->m_angularVel.m_quad;
          v878.m_quad = (__m128)v734->m_invMasses;
          v879 = *(hkRotationf *)v734->m_scratch0.m_quad.m128_i8;
          v735 = _mm_add_ps(v734->m_scratch3.m_quad, v862.m_quad);
          ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v869;
          v874 = _mm_add_ps(v874, r.m_quad);
          v880 = v735;
          ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v875;
          hkMatrix3f::setCrossSkewSymmetric(&v843, &r);
          hkMatrix3f::setCrossSkewSymmetric(&v841, &v862);
          aTb = v843;
          hkMatrix3f::setMulInverse(&v843, &aTb, &cTb);
          aTb = v841;
          hkMatrix3f::setMulInverse(&v841, &aTb, &v879);
          scale.m_real = g_vectorfConstants[0];
          angToLinVelA = v843;
          hkMatrix3f::mul(&angToLinVelA, &scale);
          angToLinVelB = v841;
          hkMatrix3f::mul(&angToLinVelB, &scale);
          v870 = _mm_add_ps(
                   v870,
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v871, v871, 85), angToLinVelA.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v871, v871, 0), angToLinVelA.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v871, v871, 170), angToLinVelA.m_col2.m_quad)));
          v876 = _mm_add_ps(
                   v876,
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v877, v877, 85), angToLinVelB.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v877, v877, 0), angToLinVelB.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v877, v877, 170), angToLinVelB.m_col2.m_quad)));
          hkSetCenterOfMassBuildJacobian(&angToLinVelA, &angToLinVelB, v7);
          if ( atome->m_type.m_storage == 29 )
            hkSimpleContactConstraintDataBuildJacobian(atome, &ina, (hkBool)1, v7);
          else
            hkSolverBuildJacobianFromAtomsNotContact(atome, sizeOfAllAtomsc, &ina, v7);
          hkSetCenterOfMassBuildJacobian(&v843, &v841, v7);
          v8 = v771;
          v9 += 40;
          goto LABEL_232;
        default:
          goto LABEL_233;
      }
    }
  }
}
        default:
          goto LABEL_233;
      }
    }
  }
} **)&v9[12].m_type.m_storage;
          sizeOfAllAtomsc = v9[9].m_type.m_storage;
          r.m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v731, v731, 85),
                           in->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v731, v731, 0), in->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v731, v731, 170), in->m_transformA.m_storage->m_rotation.m_col2.m_quad));
          v732 

