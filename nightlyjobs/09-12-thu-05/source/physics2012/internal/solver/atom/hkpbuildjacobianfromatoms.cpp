// File Line: 49
// RVA: 0xDD4040
void __fastcall hkUndoBeginConstraints(hkpConstraintQueryOut *out)
{
  out->m_jacobianSchemas.m_storage -= 32;
}

// File Line: 56
// RVA: 0xDD4050
void __fastcall callBridgeFromAtom(hkpBridgeConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
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
void __fastcall hkInitHeader(hkpConstraintQueryIn *in, hkpSolverResults *results, int resultStriding, hkpConstraintQueryOut *out)
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
  *(_QWORD *)&v4[8] = results;
  *v4 = (hkpJacobianSchema)1;
  v4[1] = (hkpJacobianSchema)resultStriding;
  *(_QWORD *)&v4[16] = v6;
  out->m_jacobianSchemas.m_storage = v4 + 32;
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
void __fastcall buildJacobianFromSoftContactModifier(hkpSoftContactModifierConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkpSoftContactModifierConstraintAtom *v5; // r8
  hkpVelocityAccumulator *v6; // rax
  int v7; // er14
  __int128 v8; // xmm1
  float v9; // xmm2_4
  __int128 v10; // xmm0
  hkpSoftContactModifierConstraintAtom *v11; // r9
  hkSimdFloat32 v12; // xmm0
  hkTransformf *v13; // rax
  float v14; // xmm2_4
  signed __int64 v15; // r11
  __int64 v16; // rsi
  signed __int64 v17; // rdi
  signed __int64 v18; // rcx
  float *v19; // rax
  unsigned __int64 v20; // rbx
  float v21; // xmm0_4
  signed __int64 v22; // rcx
  float v23; // xmm0_4
  signed __int64 v24; // rcx
  float v25; // xmm0_4
  signed __int64 v26; // rcx
  float v27; // xmm0_4
  float *v28; // rcx
  float *v29; // r10
  signed __int64 v30; // r11
  float v31; // xmm0_4
  hkpSimpleContactConstraintAtom *v32; // rcx
  hkpConstraintQueryIn ina; // [rsp+20h] [rbp-98h]

  v5 = atom;
  out->m_jacobianSchemas.m_storage -= 32;
  v6 = in->m_bodyA.m_storage;
  v7 = atom->m_childSize;
  v8 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  v9 = atom->m_tau;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v10 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v8;
  v11 = atom;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = v10;
  v12.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  ina.m_bodyA.m_storage = v6;
  ina.m_bodyB.m_storage = in->m_bodyB.m_storage;
  v13 = in->m_transformA.m_storage;
  *(float *)&v8 = v9 * in->m_tau.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v12.m_real;
  v12.m_real.m128_f32[0] = v9;
  ina.m_transformA.m_storage = v13;
  v14 = v9 * in->m_damping.m_storage;
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
    v11 = (hkpSoftContactModifierConstraintAtom *)v11->m_child;
  while ( v11->m_type.m_storage >= 0x1Eu );
  v15 = *((unsigned __int16 *)&v11->0 + 2);
  v16 = *((unsigned __int8 *)&v11->0 + 10);
  v17 = 0i64;
  v18 = (signed __int64)(&v11->m_tau + 8 * *((unsigned __int16 *)&v11->0 + 3));
  if ( v15 >= 4 )
  {
    v19 = (float *)&v11[1].m_pad[3];
    v20 = ((unsigned __int64)(v15 - 4) >> 2) + 1;
    v17 = 4 * v20;
    do
    {
      v21 = (float)((float)((float)(v5->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / v5->m_tau)
          + *(v19 - 8);
      if ( v21 < *(float *)(v18 + 24) )
        *(float *)(v18 + 24) = v21;
      v22 = (signed int)v16 + v18;
      v23 = (float)((float)((float)(v5->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / v5->m_tau)
          + *v19;
      if ( v23 < *(float *)(v22 + 24) )
        *(float *)(v22 + 24) = v23;
      v24 = (signed int)v16 + v22;
      v25 = (float)((float)((float)(v5->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / v5->m_tau)
          + v19[8];
      if ( v25 < *(float *)(v24 + 24) )
        *(float *)(v24 + 24) = v25;
      v26 = (signed int)v16 + v24;
      v27 = (float)((float)((float)(v5->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / v5->m_tau)
          + v19[16];
      if ( v27 < *(float *)(v26 + 24) )
        *(float *)(v26 + 24) = v27;
      v18 = (signed int)v16 + v26;
      v19 += 32;
      --v20;
    }
    while ( v20 );
  }
  if ( v17 < v15 )
  {
    v28 = (float *)(v18 + 24);
    v29 = (float *)(&v11[1].0 + 16 * v17 + 6);
    v30 = v15 - v17;
    do
    {
      v31 = (float)((float)((float)(v5->m_maxAcceleration * in->m_microStepDeltaTime.m_storage)
                          * in->m_subStepDeltaTime.m_storage)
                  / v5->m_tau)
          + *v29;
      if ( v31 < *v28 )
        *v28 = v31;
      v28 = (float *)((char *)v28 + v16);
      v29 += 8;
      --v30;
    }
    while ( v30 );
  }
  v32 = (hkpSimpleContactConstraintAtom *)v5->m_child;
  if ( v32->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(v32, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v32->m_type, v7, &ina, out);
}

// File Line: 224
// RVA: 0xDD4380
void __fastcall buildJacobianFromIgnoreModifier(hkpIgnoreModifierConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  out->m_jacobianSchemas.m_storage -= 32;
}

// File Line: 231
// RVA: 0xDD4390
void __fastcall buildJacobianFromMassChangerModifier(hkpMassChangerModifierConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  __int128 *v5; // rax
  __int128 v6; // xmm1
  hkpSimpleContactConstraintAtom *v7; // rsi
  int v8; // er14
  __int128 v9; // xmm0
  hkpConstraintQueryIn *v10; // rdi
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  hkSimdFloat32 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __int128 v19; // xmm1
  __int128 *v20; // rax
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __int128 v23; // xmm1
  hkpConstraintQueryIn ina; // [rsp+20h] [rbp-E0h]
  __int128 v25; // [rsp+B0h] [rbp-50h]
  __int128 v26; // [rsp+C0h] [rbp-40h]
  __int128 v27; // [rsp+D0h] [rbp-30h]
  hkVector4f invMassA; // [rsp+E0h] [rbp-20h]
  __int128 v29; // [rsp+F0h] [rbp-10h]
  __int128 v30; // [rsp+100h] [rbp+0h]
  __int128 v31; // [rsp+110h] [rbp+10h]
  __int128 v32; // [rsp+120h] [rbp+20h]
  __int128 v33; // [rsp+130h] [rbp+30h]
  __int128 v34; // [rsp+140h] [rbp+40h]
  __int128 v35; // [rsp+150h] [rbp+50h]
  hkVector4f invMassB; // [rsp+160h] [rbp+60h]
  __int128 v37; // [rsp+170h] [rbp+70h]
  __int128 v38; // [rsp+180h] [rbp+80h]
  __int128 v39; // [rsp+190h] [rbp+90h]
  __int128 v40; // [rsp+1A0h] [rbp+A0h]

  v5 = (__int128 *)&in->m_bodyA.m_storage->m_type.m_storage;
  v6 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  v7 = (hkpSimpleContactConstraintAtom *)atom->m_child;
  v8 = atom->m_childSize;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v9 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v6;
  v10 = in;
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
  v25 = *v5;
  v26 = v5[1];
  v27 = v5[2];
  v17 = (__m128)v5[3];
  invMassA.m_quad = v17;
  v18 = _mm_mul_ps(v17, atom->m_factorA.m_quad);
  v29 = v5[4];
  v30 = v5[5];
  v31 = v5[6];
  v19 = v5[7];
  v20 = (__int128 *)&in->m_bodyB.m_storage->m_type.m_storage;
  v32 = v19;
  v33 = *v20;
  v34 = v20[1];
  v35 = v20[2];
  v21 = (__m128)v20[3];
  invMassB.m_quad = v21;
  v22 = _mm_mul_ps(v21, atom->m_factorB.m_quad);
  v37 = v20[4];
  v38 = v20[5];
  v39 = v20[6];
  v23 = v20[7];
  invMassA.m_quad = v18;
  ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v25;
  ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v33;
  v40 = v23;
  invMassB.m_quad = v22;
  hkSetInvMassBuildJacobian(&invMassA, &invMassB, out);
  if ( v7->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(v7, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v7->m_type, v8, &ina, out);
  hkSetInvMassBuildJacobian(&v10->m_bodyA.m_storage->m_invMasses, &v10->m_bodyB.m_storage->m_invMasses, out);
}

// File Line: 295
// RVA: 0xDD4540
void __fastcall buildJacobianFromCenterOfMassChangerModifier(hkpCenterOfMassChangerModifierConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkTransformf *v5; // rax
  __int128 v6; // xmm1
  hkpSimpleContactConstraintAtom *v7; // rdi
  int v8; // esi
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
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  hkpVelocityAccumulator *v29; // rax
  __m128 v30; // xmm2
  hkpVelocityAccumulator *v31; // rax
  __m128 v32; // xmm1
  hkMatrix3f v33; // [rsp+20h] [rbp-E0h]
  hkSimdFloat32 scale; // [rsp+50h] [rbp-B0h]
  hkMatrix3f v35; // [rsp+60h] [rbp-A0h]
  hkMatrix3f aTb; // [rsp+90h] [rbp-70h]
  hkMatrix3f angToLinVelA; // [rsp+C0h] [rbp-40h]
  hkMatrix3f angToLinVelB; // [rsp+F0h] [rbp-10h]
  hkVector4f v39; // [rsp+120h] [rbp+20h]
  hkVector4f r; // [rsp+130h] [rbp+30h]
  __int128 v41; // [rsp+140h] [rbp+40h]
  __m128 v42; // [rsp+150h] [rbp+50h]
  __m128 v43; // [rsp+160h] [rbp+60h]
  hkVector4f v44; // [rsp+170h] [rbp+70h]
  hkRotationf cTb; // [rsp+180h] [rbp+80h]
  __m128 v46; // [rsp+1B0h] [rbp+B0h]
  __int128 v47; // [rsp+1C0h] [rbp+C0h]
  __m128 v48; // [rsp+1D0h] [rbp+D0h]
  __m128 v49; // [rsp+1E0h] [rbp+E0h]
  hkVector4f v50; // [rsp+1F0h] [rbp+F0h]
  hkRotationf v51; // [rsp+200h] [rbp+100h]
  __m128 v52; // [rsp+230h] [rbp+130h]
  hkpConstraintQueryIn ina; // [rsp+240h] [rbp+140h]

  v5 = in->m_transformA.m_storage;
  v6 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  v7 = (hkpSimpleContactConstraintAtom *)atom->m_child;
  v8 = atom->m_childSize;
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
  v18 = _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 0), v5->m_rotation.m_col0.m_quad);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 170), v5->m_rotation.m_col2.m_quad);
  v20 = _mm_mul_ps(v17, v5->m_rotation.m_col1.m_quad);
  v21 = in->m_transformB.m_storage;
  v22 = _mm_add_ps(_mm_add_ps(v20, v18), v19);
  v23.m_quad = (__m128)atom->m_displacementB;
  v24 = _mm_shuffle_ps(atom->m_displacementB.m_quad, v23.m_quad, 0);
  v25 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 85);
  r.m_quad = v22;
  v26 = _mm_mul_ps(v24, v21->m_rotation.m_col0.m_quad);
  v27 = _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 170), v21->m_rotation.m_col2.m_quad);
  v28 = _mm_mul_ps(v25, v21->m_rotation.m_col1.m_quad);
  v29 = in->m_bodyA.m_storage;
  v39.m_quad = _mm_add_ps(_mm_add_ps(v28, v26), v27);
  v41 = *(_OWORD *)&v29->m_type.m_storage;
  v42 = v29->m_linearVel.m_quad;
  v43 = v29->m_angularVel.m_quad;
  v44.m_quad = (__m128)v29->m_invMasses;
  cTb.m_col0 = v29->m_scratch0;
  cTb.m_col1 = v29->m_scratch1;
  cTb.m_col2 = v29->m_scratch2;
  v30 = v29->m_scratch3.m_quad;
  v31 = in->m_bodyB.m_storage;
  v46 = v30;
  v47 = *(_OWORD *)&v31->m_type.m_storage;
  v48 = v31->m_linearVel.m_quad;
  v49 = v31->m_angularVel.m_quad;
  v50.m_quad = (__m128)v31->m_invMasses;
  v51.m_col0 = v31->m_scratch0;
  v51.m_col1 = v31->m_scratch1;
  v51.m_col2 = v31->m_scratch2;
  v32 = v31->m_scratch3.m_quad;
  v46 = _mm_add_ps(v30, v22);
  ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v41;
  v52 = _mm_add_ps(v32, v39.m_quad);
  ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v47;
  hkMatrix3f::setCrossSkewSymmetric(&v35, &r);
  hkMatrix3f::setCrossSkewSymmetric(&v33, &v39);
  aTb = v35;
  hkMatrix3f::setMulInverse(&v35, &aTb, &cTb);
  aTb = v33;
  hkMatrix3f::setMulInverse(&v33, &aTb, &v51);
  scale.m_real = g_vectorfConstants[0];
  angToLinVelA.m_col1 = v35.m_col1;
  angToLinVelA.m_col0 = v35.m_col0;
  angToLinVelA.m_col2 = v35.m_col2;
  hkMatrix3f::mul(&angToLinVelA, &scale);
  angToLinVelB = v33;
  hkMatrix3f::mul(&angToLinVelB, &scale);
  v42 = _mm_add_ps(
          v42,
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), angToLinVelA.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), angToLinVelA.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), angToLinVelA.m_col2.m_quad)));
  v48 = _mm_add_ps(
          v48,
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), angToLinVelB.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), angToLinVelB.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), angToLinVelB.m_col2.m_quad)));
  hkSetCenterOfMassBuildJacobian(&angToLinVelA, &angToLinVelB, out);
  if ( v7->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(v7, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v7->m_type, v8, &ina, out);
  hkSetCenterOfMassBuildJacobian(&v35, &v33, out);
}

// File Line: 386
// RVA: 0xDD48C0
void __fastcall buildJacobianFromViscousSurfaceModifier(hkpViscousSurfaceModifierConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkpConstraintQueryOut *out)
{
  hkpViscousSurfaceModifierConstraintAtom *v5; // rdi
  int v6; // esi
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  hkSimdFloat32 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  hkpSimpleContactConstraintAtom *v14; // rcx
  hkpConstraintQueryIn ina; // [rsp+20h] [rbp-98h]

  v5 = atom;
  out->m_jacobianSchemas.m_storage -= 32;
  v6 = atom->m_childSize;
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
  v14 = (hkpSimpleContactConstraintAtom *)v5->m_child;
  if ( v14->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(v14, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v14->m_type, v6, &ina, out);
}

// File Line: 425
// RVA: 0xDD4990
void __fastcall buildJacobianFromMovingSurfaceModifier(hkpMovingSurfaceModifierConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB)
{
  __int128 v4; // xmm1
  hkpConstraintAtom *v5; // rsi
  hkpConstraintQueryIn *v6; // r11
  hkVector4f v7; // xmm4
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  hkSimdFloat32 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  hkpJacobianSchema *v14; // r10
  unsigned int v15; // edx
  hkpConstraintInstance *v16; // rcx
  hkpJacobianSchema v17; // r9
  signed __int64 v18; // r8
  unsigned int v19; // eax
  bool v20; // dl
  hkpVelocityAccumulator *v21; // rcx
  __int128 v22; // xmm1
  hkpVelocityAccumulator *v23; // rcx
  __m128 v24; // xmm2
  int v25; // ebx
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  hkVector4f deltaVel; // [rsp+20h] [rbp-D8h]
  char v29; // [rsp+30h] [rbp-C8h]
  char v30; // [rsp+31h] [rbp-C7h]
  unsigned int v31; // [rsp+34h] [rbp-C4h]
  float v32; // [rsp+38h] [rbp-C0h]
  __m128 v33; // [rsp+40h] [rbp-B8h]
  hkVector4f v34; // [rsp+50h] [rbp-A8h]
  hkVector4f v35; // [rsp+60h] [rbp-98h]
  hkVector4f v36; // [rsp+70h] [rbp-88h]
  hkVector4f v37; // [rsp+88h] [rbp-70h]
  __int128 v38; // [rsp+98h] [rbp-60h]
  hkpConstraintQueryIn ina; // [rsp+A8h] [rbp-50h]
  hkpConstraintQueryOut *v40; // [rsp+178h] [rbp+80h]

  v4 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  v5 = atom->m_child;
  v6 = in;
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
  v14 = v40->m_jacobianSchemas.m_storage;
  v15 = in->m_accumulatorBIndex.m_storage;
  v16 = v6->m_constraintInstance.m_storage;
  *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = v12;
  *(_OWORD *)&ina.m_constraintInstance.m_storage = v13;
  v17 = (hkpJacobianSchema)v5[5].m_type.m_storage;
  *(float *)&v12 = *(float *)v14 + 0.00000011920929;
  v18 = (signed __int64)&v5[16 * v5[3].m_type.m_storage + 24];
  v19 = v6->m_accumulatorAIndex.m_storage;
  *(_WORD *)&v14[6] = v15;
  *(_DWORD *)v14 = v12;
  *(_WORD *)&v14[4] = v19;
  *(_QWORD *)&v14[8] = v18;
  *v14 = (hkpJacobianSchema)1;
  *(_QWORD *)&v14[16] = v16;
  v14[1] = v17;
  v40->m_jacobianSchemas.m_storage = v14 + 32;
  v20 = v6->m_accumulatorAIndex.m_storage == 0;
  if ( v6->m_accumulatorAIndex.m_storage )
  {
    v21 = v6->m_bodyA.m_storage;
    v29 = v21->m_type.m_storage;
    v30 = v21->m_context.m_storage;
    v31 = v21->m_deactivationClass;
    v32 = v21->m_gravityFactor;
    v33 = v21->m_linearVel.m_quad;
    v34.m_quad = (__m128)v21->m_angularVel;
    v35.m_quad = (__m128)v21->m_invMasses;
    v36.m_quad = (__m128)v21->m_scratch0;
    *(hkVector4f *)((char *)&v36 + 8) = v21->m_scratch1;
    v37.m_quad = (__m128)v21->m_scratch2;
    v22 = (__int128)v21->m_scratch3;
    ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v29;
  }
  else
  {
    v23 = v6->m_bodyB.m_storage;
    v29 = v23->m_type.m_storage;
    v30 = v23->m_context.m_storage;
    v31 = v23->m_deactivationClass;
    v32 = v23->m_gravityFactor;
    v33 = v23->m_linearVel.m_quad;
    v34.m_quad = (__m128)v23->m_angularVel;
    v35.m_quad = (__m128)v23->m_invMasses;
    v36.m_quad = (__m128)v23->m_scratch0;
    *(hkVector4f *)((char *)&v36 + 8) = v23->m_scratch1;
    v37.m_quad = (__m128)v23->m_scratch2;
    v22 = (__int128)v23->m_scratch3;
    ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v29;
    v7.m_quad = _mm_xor_ps(v7.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
  }
  v24 = *(__m128 *)&v5[32].m_type.m_storage;
  v38 = v22;
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
                          *(__m128 *)&v5[32].m_type.m_storage)),
                      v27);
  hkAddVelocityBuildJacobian(&deltaVel, v20, v40);
  v33 = _mm_add_ps(v33, deltaVel.m_quad);
  hkSimpleContactConstraintDataBuildJacobian((hkpSimpleContactConstraintAtom *)v5, &ina, 0, v40);
  deltaVel.m_quad = _mm_xor_ps(v27, deltaVel.m_quad);
  hkAddVelocityBuildJacobian(&deltaVel, v25, v40);
}

// File Line: 535
// RVA: 0xDD4C10
void __fastcall setupStabilizationFromAtom_outOfLine(hkpSetupStabilizationAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkVector4f *vLocalArmA, hkVector4f *vLocalArmB, hkSimdFloat32 *maxAngularImpulse, hkSimdFloat32 *maxLinearImpulse, hkpConstraintQueryOut *noOut)
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

// File Line: 546
// RVA: 0xDCFF90
void __fastcall buildSchemaFromBallSocketAtom(hkpBallSocketConstraintAtom *atom, hkpConstraintQueryIn *in, hkTransformf *baseA, hkTransformf *baseB, hkVector4f *vLocalArmA, hkVector4f *vLocalArmB, hkSimdFloat32 *maxAngularImpulse, hkSimdFloat32 *maxLinearImpulse, hkpConstraintQueryOut *out)
{
  hkTransformf *v9; // rdi
  hkTransformf *v10; // rsi
  hkpConstraintQueryIn *v11; // rbx
  hkpBallSocketConstraintAtom *v12; // rbp
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
  __m128 v32; // xmm4
  __m128 v33; // xmm12
  __m128 v34; // xmm4
  __m128 v35; // xmm8
  __m128 v36; // xmm6
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm9
  __m128 v41; // xmm3
  __m128 v42; // xmm7
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm5
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm9
  __m128 v50; // xmm5
  __m128 v51; // ST60_16
  __m128 v52; // xmm5
  __m128 v53; // xmm4
  hkpViolatedConstraintArray *v54; // rcx
  __m128 v55; // xmm2
  __m128 v56; // xmm7
  __m128 v57; // xmm2
  unsigned __int32 v58; // eax
  float v59; // xmm0_4
  unsigned __int16 v60; // ax
  float v61; // xmm0_4
  __m128 *v62; // r9
  hkpVelocityAccumulator *v63; // r10
  float v64; // xmm12_4
  __m128 v65; // xmm7
  __m128 v66; // xmm3
  hkpJacobianSchema *v67; // r8
  __m128 v68; // xmm1
  __m128 v69; // xmm2
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
  __m128 v80; // xmm2
  __m128 v81; // xmm0
  __m128 v82; // xmm1
  __m128 v83; // xmm5
  __m128 v84; // xmm0
  __m128 v85; // xmm6
  volatile signed __int32 *v86; // rcx
  __m128 v87; // xmm6
  __m128 v88; // xmm2
  unsigned __int32 v89; // eax
  hkVector4f *v90; // rcx
  __m128 *v91; // rax
  float v92; // xmm0_4
  float v93; // ST28_4
  __m128 v94; // xmm2
  __m128 v95; // xmm3
  __m128 v96; // xmm4
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

  v9 = baseB;
  v10 = baseA;
  v11 = in;
  v12 = atom;
  if ( atom->m_solvingMethod.m_storage == 1 )
  {
    v60 = hkUFloat8::getEncodedFloat(atom->m_velocityStabilizationFactor.m_value);
    if ( v60 )
      LODWORD(v61) = (v60 + 243712) << 12;
    else
      v61 = 0.0;
    v62 = (__m128 *)v11->m_bodyA.m_storage;
    v63 = v11->m_bodyB.m_storage;
    v64 = v12->m_breachImpulse;
    v65 = _mm_sub_ps(v10->m_translation.m_quad, v62[7]);
    v66 = v62[6];
    v67 = out->m_jacobianSchemas.m_storage;
    v68 = _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(v61 * v11->m_rhsFactor.m_storage),
            (__m128)COERCE_UNSIGNED_INT(v61 * v11->m_rhsFactor.m_storage),
            0);
    v69 = _mm_rcp_ps(v68);
    v70 = _mm_mul_ps(v69, v68);
    v71 = _mm_sub_ps(v9->m_translation.m_quad, v63->m_scratch3.m_quad);
    v72 = _mm_unpacklo_ps(v62[4], v62[5]);
    v73 = _mm_shuffle_ps(_mm_unpackhi_ps(v62[4], v62[5]), v66, 228);
    v74 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v70), v69);
    v75 = _mm_movelh_ps(v72, v66);
    v76 = _mm_shuffle_ps(_mm_movehl_ps(v75, v72), v66, 212);
    v77 = v63->m_scratch2.m_quad;
    v78 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v62[2], v62[2], 85), v76),
              _mm_mul_ps(_mm_shuffle_ps(v62[2], v62[2], 0), v75)),
            _mm_mul_ps(_mm_shuffle_ps(v62[2], v62[2], 170), v73));
    v79 = _mm_unpacklo_ps(v63->m_scratch0.m_quad, v63->m_scratch1.m_quad);
    v80 = _mm_movelh_ps(v79, v77);
    v81 = _mm_movehl_ps(v80, v79);
    v82 = v63->m_angularVel.m_quad;
    v83 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v81, v77, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v63->m_angularVel.m_quad, v82, 0), v80)),
            _mm_mul_ps(
              _mm_shuffle_ps(v82, v82, 170),
              _mm_shuffle_ps(_mm_unpackhi_ps(v63->m_scratch0.m_quad, v63->m_scratch1.m_quad), v77, 228)));
    v84 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v65), _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v78));
    v85 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v71), _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v83));
    v86 = (volatile signed __int32 *)v11->m_violatedConstraints.m_storage;
    v87 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v74),
              _mm_sub_ps(v9->m_translation.m_quad, v10->m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v74));
    if ( v86 )
    {
      v88 = _mm_mul_ps(v87, v87);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 170))) > v11->m_maxConstraintViolationSqrd.m_real.m128_f32[0] )
      {
        v89 = _InterlockedExchangeAdd(v86, 1u);
        if ( v89 < 0x80 )
          v11->m_violatedConstraints.m_storage->m_constraints[v89] = v11->m_constraintInstance.m_storage;
      }
    }
    v90 = &transform;
    v91 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
    do
    {
      v92 = v11->m_virtMassFactor.m_storage;
      *(hkVector4f *)v67 = (hkVector4f)v90->m_quad;
      v93 = v92;
      v94 = _mm_sub_ps(v10->m_translation.m_quad, v62[7]);
      v95 = _mm_shuffle_ps(v90->m_quad, v90->m_quad, 201);
      v96 = _mm_sub_ps(v9->m_translation.m_quad, v63->m_scratch3.m_quad);
      v97 = _mm_sub_ps(_mm_mul_ps(v95, v94), _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v90->m_quad));
      v98 = _mm_shuffle_ps(v97, v97, 201);
      v99 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), v90->m_quad), _mm_mul_ps(v95, v96));
      v100 = _mm_shuffle_ps(v99, v99, 201);
      v101 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), v62[5]),
                 _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), v62[4])),
               _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), v62[6]));
      *(__m128 *)&v67[16] = v101;
      v102 = v101;
      v103 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v100, v100, 85), v63->m_scratch1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v100, v100, 0), v63->m_scratch0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v100, v100, 170), v63->m_scratch2.m_quad));
      *(__m128 *)&v67[32] = v103;
      v104 = v63->m_invMasses.m_quad;
      v105 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v101, v101), v62[3]), _mm_mul_ps(_mm_mul_ps(v103, v103), v104));
      v106 = _mm_shuffle_ps(
               v105,
               _mm_unpackhi_ps(v105, _mm_max_ps(_mm_add_ps(v104, v62[3]), (__m128)xmmword_141A712D0)),
               196);
      v107 = _mm_add_ps(_mm_shuffle_ps(v106, v106, 78), v106);
      v108 = _mm_add_ps(_mm_shuffle_ps(v107, v107, 177), v107);
      v109 = _mm_rcp_ps(v108);
      *(__m128 *)&v67[32] = _mm_shuffle_ps(v103, _mm_unpackhi_ps(v103, v108), 196);
      *(__m128 *)&v67[16] = _mm_shuffle_ps(
                              v102,
                              _mm_unpackhi_ps(
                                v102,
                                _mm_mul_ps(
                                  _mm_shuffle_ps((__m128)LODWORD(v93), (__m128)LODWORD(v93), 0),
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v109, v108)), v109))),
                              196);
      v110 = _mm_mul_ps(_mm_sub_ps(v9->m_translation.m_quad, v10->m_translation.m_quad), v90->m_quad);
      v111 = _mm_shuffle_ps(
               *(__m128 *)v67,
               _mm_unpackhi_ps(
                 *(__m128 *)v67,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                     _mm_shuffle_ps(v110, v110, 170)),
                   _mm_shuffle_ps(
                     (__m128)LODWORD(v11->m_rhsFactor.m_storage),
                     (__m128)LODWORD(v11->m_rhsFactor.m_storage),
                     0))),
               196);
      *(__m128 *)v67 = v111;
      v112 = _mm_and_ps(*v91, v87);
      v113 = _mm_or_ps(_mm_shuffle_ps(v112, v112, 78), v112);
      *(__m128 *)v67 = _mm_shuffle_ps(
                         v111,
                         _mm_unpackhi_ps(
                           v111,
                           _mm_mul_ps(
                             _mm_or_ps(_mm_shuffle_ps(v113, v113, 177), v113),
                             _mm_shuffle_ps(
                               (__m128)LODWORD(v11->m_rhsFactor.m_storage),
                               (__m128)LODWORD(v11->m_rhsFactor.m_storage),
                               0))),
                         196);
      if ( v64 == 3.40282e38 )
      {
        *(float *)v67 = *(float *)v67 + 0.00000011920929;
        *v67 = (hkpJacobianSchema)5;
      }
      else
      {
        *(float *)&v67[44] = v64;
        *(float *)v67 = *(float *)v67 + 0.00000011920929;
        *v67 = (hkpJacobianSchema)6;
      }
      ++v91;
      v67 += 48;
      ++v90;
    }
    while ( (signed __int64)v91 < (signed __int64)&xmmword_141687F30 );
    out->m_jacobianSchemas.m_storage = v67;
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
    v19 = _mm_cmpltps((__m128)xmmword_141A712D0, v17);
    v20 = _mm_rsqrt_ps(v17);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v22 = _mm_cmpltps((__m128)xmmword_141A712D0, v21);
    v23 = _mm_andnot_ps(
            _mm_cmpleps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v17), v20)),
              _mm_mul_ps(*(__m128 *)_xmm, v20)));
    v24 = _mm_rsqrt_ps(v21);
    v25 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(vLocalArmA->m_quad, v23), v19), _mm_andnot_ps(v19, transform.m_quad));
    v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, _mm_mul_ps(v23, v17)), 196);
    v27 = _mm_andnot_ps(
            _mm_cmpleps(v21, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v21), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24)));
    v28 = _mm_mul_ps(vLocalArmB->m_quad, v27);
    *(__m128 *)&v14[16] = v26;
    v29 = _mm_shuffle_ps(v26, v26, 255);
    v30 = _mm_or_ps(_mm_and_ps(v28, v22), _mm_andnot_ps(v22, transform.m_quad));
    v31 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, _mm_mul_ps(v27, v21)), 196);
    v32 = (__m128)LODWORD(v12->m_inertiaStabilizationFactor);
    *(__m128 *)&v14[32] = v31;
    v33 = _mm_shuffle_ps(v31, v31, 255);
    v34 = _mm_shuffle_ps(v32, v32, 0);
    v35 = v16->m_invMasses.m_quad;
    v36 = v13->m_invMasses.m_quad;
    v37 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_max_ps(
                _mm_shuffle_ps(v35, v35, 170),
                _mm_max_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0))),
              v29),
            v34);
    v38 = _mm_cmpltps(*(__m128 *)&epsilon, v37);
    v39 = _mm_rcp_ps(v37);
    v40 = v38;
    v41 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_max_ps(
                _mm_shuffle_ps(v36, v36, 170),
                _mm_max_ps(
                  _mm_shuffle_ps(v13->m_invMasses.m_quad, v36, 85),
                  _mm_shuffle_ps(v13->m_invMasses.m_quad, v36, 0))),
              v33),
            v34);
    v42 = _mm_cmpltps(*(__m128 *)&epsilon, v41);
    v43 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v37)), v39);
    v44 = _mm_rcp_ps(v41);
    v45 = _mm_and_ps(v38, _mm_mul_ps(v43, _mm_shuffle_ps(v35, v35, 255)));
    v46 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v41)), v44);
    v47 = _mm_shuffle_ps((__m128)LODWORD(v12->m_breachImpulse), (__m128)LODWORD(v12->m_breachImpulse), 0);
    v48 = _mm_cmpleps((__m128)xmmword_141A712B0, v47);
    v49 = _mm_or_ps(_mm_andnot_ps(v40, query.m_quad), v45);
    v50 = 0i64;
    v50.m128_f32[0] = (float)(v12->m_enableLinearImpulseLimit.m_bool != 0);
    v51 = _mm_min_ps(
            _mm_or_ps(_mm_andnot_ps(v42, query.m_quad), _mm_and_ps(v42, _mm_mul_ps(v46, _mm_shuffle_ps(v36, v36, 255)))),
            query.m_quad);
    v52 = _mm_cmpneqps(_mm_shuffle_ps(v50, v50, 0), (__m128)0i64);
    v53 = _mm_or_ps(_mm_andnot_ps(v48, _mm_mul_ps(v47, v47)), _mm_and_ps(v48, v47));
    v54 = in->m_violatedConstraints.m_storage;
    v55 = _mm_sub_ps(baseA->m_translation.m_quad, baseB->m_translation.m_quad);
    v56 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(in->m_tau.m_storage), (__m128)LODWORD(in->m_tau.m_storage), 0),
            _mm_shuffle_ps(
              (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
              (__m128)LODWORD(in->m_subStepInvDeltaTime.m_storage),
              0));
    *(__m128 *)v14 = _mm_shuffle_ps(
                       v53,
                       _mm_unpackhi_ps(
                         v53,
                         _mm_or_ps(
                           _mm_andnot_ps(v52, (__m128)xmmword_141A712A0),
                           _mm_and_ps(maxLinearImpulse->m_real, v52))),
                       180);
    *(__m128 *)&v14[48] = _mm_movelh_ps(
                            _mm_unpacklo_ps(v56, maxLinearImpulse->m_real),
                            _mm_unpacklo_ps(_mm_mul_ps(_mm_min_ps(v49, query.m_quad), v29), _mm_mul_ps(v51, v33)));
    if ( v54 )
    {
      v57 = _mm_mul_ps(v55, v55);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170))) > in->m_maxConstraintViolationSqrd.m_real.m128_f32[0] )
      {
        v58 = _InterlockedExchangeAdd((volatile signed __int32 *)v54, 1u);
        if ( v58 < 0x80 )
          in->m_violatedConstraints.m_storage->m_constraints[v58] = in->m_constraintInstance.m_storage;
      }
    }
    v59 = *(float *)v14 + 0.00000011920929;
    out->m_jacobianSchemas.m_storage = v14 + 64;
    *(float *)v14 = v59;
    *v14 = (hkpJacobianSchema)16;
  }
}

// File Line: 622
// RVA: 0xDCFA90
void __fastcall hkpBeginConstraints(hkpConstraintQueryIn *in, hkpConstraintQueryOut *out, hkpSolverResults *sr, int solverResultStriding)
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

// File Line: 629
// RVA: 0xDCFAF0
void __fastcall hk1dAngularLimitBuildJacobian(hkp1dAngularLimitInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulator *v3; // rax
  hkpVelocityAccumulator *v4; // r9
  hkpJacobianSchema *v5; // r10
  __m128 v6; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  float v14; // xmm0_4

  v3 = in->m_bodyA.m_storage;
  v4 = in->m_bodyB.m_storage;
  v5 = out->m_jacobianSchemas.m_storage;
  v6 = (__m128)LODWORD(info->m_tau.m_storage);
  v7 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
         info->m_constrainedDofW.m_quad);
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(info->m_constrainedDofW.m_quad, info->m_constrainedDofW.m_quad, 85),
             v3->m_scratch1.m_quad),
           _mm_mul_ps(
             _mm_shuffle_ps(info->m_constrainedDofW.m_quad, info->m_constrainedDofW.m_quad, 0),
             v3->m_scratch0.m_quad)),
         _mm_mul_ps(
           _mm_shuffle_ps(info->m_constrainedDofW.m_quad, info->m_constrainedDofW.m_quad, 170),
           v3->m_scratch2.m_quad));
  *(__m128 *)v5 = v8;
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v4->m_scratch1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v4->m_scratch0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v4->m_scratch2.m_quad));
  v10 = v8;
  *(__m128 *)&v5[16] = v9;
  v11 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v8, v8), v3->m_invMasses.m_quad),
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
                        _mm_shuffle_ps(v6, v6, 0),
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v12)), v13))),
                    196);
  v13.m128_i32[0] = LODWORD(info->m_max.m_storage);
  v9.m128_i32[0] = LODWORD(in->m_subStepInvDeltaTime.m_storage) ^ _xmm[0];
  v12.m128_f32[0] = (float)(info->m_min.m_storage * v9.m128_f32[0]) * v6.m128_f32[0];
  *(float *)&v5[28] = v9.m128_f32[0] * info->m_computedAngle.m_storage;
  out->m_jacobianSchemas.m_storage = v5 + 48;
  v14 = *(float *)v5 + 0.00000011920929;
  *(_DWORD *)&v5[32] = v12.m128_i32[0];
  *(_DWORD *)&v5[40] = v6.m128_i32[0];
  *(float *)v5 = v14;
  *(float *)&v5[36] = (float)(v13.m128_f32[0] * v9.m128_f32[0]) * v6.m128_f32[0];
  *v5 = (hkpJacobianSchema)13;
}

// File Line: 634
// RVA: 0xDCFE20
void __fastcall hk1dAngularVelocityMotorBeginJacobian(hkVector4f *directionOfConstraint, hkpConstraintQueryIn *in, hkp2AngJacobian *jac, hkp1dBilateralConstraintStatus *statusOut)
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

// File Line: 639
// RVA: 0xDCFF20
void __fastcall hk1dAngularVelocityMotorCommitJacobian(hkp1dConstraintMotorInfo *info, hkpConstraintQueryIn *in, hkp2AngJacobian *jac, hkpConstraintQueryOut *out)
{
  hkpJacobianSchema *v4; // r8

  jac->m_angular[1].m_quad.m128_f32[3] = in->m_subStepInvDeltaTime.m_storage * info->m_targetPosition.m_storage;
  v4 = out->m_jacobianSchemas.m_storage;
  *(float *)v4 = *(float *)out->m_jacobianSchemas.m_storage + 0.00000011920929;
  *v4 = (hkpJacobianSchema)15;
  *(float *)&v4[32] = info->m_maxForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(float *)&v4[36] = info->m_minForce.m_storage * in->m_microStepDeltaTime.m_storage;
  *(float *)&v4[40] = info->m_targetVelocity.m_storage;
  *(float *)&v4[44] = info->m_tau.m_storage;
  *(float *)&v4[48] = info->m_damping.m_storage;
  out->m_jacobianSchemas.m_storage = v4 + 64;
}

// File Line: 644
// RVA: 0xDCFC50
void __fastcall hk1dAngularFrictionBuildJacobian(hkp1dAngularFrictionInfo *info, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkVector4f *v3; // rbx
  hkpJacobianSchema *v4; // r9
  int v5; // er11
  hkp1dAngularFrictionInfo *v6; // r10
  __m128 v7; // xmm4
  char *v8; // rdi
  __m128 v9; // xmm5
  __m128 v10; // xmm2
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

  v3 = info->m_constrainedDofW.m_storage;
  v4 = out->m_jacobianSchemas.m_storage;
  v5 = 0;
  v6 = info;
  if ( info->m_numFriction.m_storage > 0 )
  {
    v7 = _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0);
    v8 = (char *)&info->m_lastSolverResults.m_storage->m_internalSolverData;
    v9 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v10 = v3->m_quad;
      v11 = in->m_bodyA.m_storage;
      v12 = in->m_bodyB.m_storage;
      v13 = v3->m_quad;
      v14 = v3->m_quad;
      v4 += 48;
      ++v3;
      v8 += 16;
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v11->m_scratch1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v13, v10, 0), v11->m_scratch0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v11->m_scratch2.m_quad));
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
                                    (__m128)*((unsigned int *)v8 - 4),
                                    (__m128)*((unsigned int *)v8 - 4),
                                    0))),
                              196);
      v13.m128_f32[0] = in->m_microStepDeltaTime.m_storage * v6->m_maxFrictionTorque.m_storage;
      *(_DWORD *)&v4[-12] = v5;
      *(_DWORD *)&v4[-48] = v21.m128_i32[0];
      v4[-48] = (hkpJacobianSchema)14;
      ++v5;
      *(_DWORD *)&v4[-16] = v13.m128_i32[0];
    }
    while ( v5 < v6->m_numFriction.m_storage );
  }
  out->m_jacobianSchemas.m_storage = v4;
}

// File Line: 652
// RVA: 0xDC9FE0
void __fastcall hkSolverBuildJacobianFromAtomsNotContact(hkpConstraintAtom *atoms, int sizeOfAllAtoms, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkTransformf *v4; // rax
  __m128 v5; // xmm7
  hkpConstraintQueryIn *v6; // rsi
  hkpConstraintQueryOut *v7; // rbx
  unsigned __int16 *v8; // r10
  unsigned __int16 *v9; // rdi
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
  signed __int64 v26; // rcx
  __m128 *v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm1
  signed __int64 v32; // rcx
  __m128 *v33; // rax
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
  __m128 v56; // xmm9
  __m128 v57; // xmm3
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  __m128 v60; // xmm7
  __m128 v61; // xmm0
  __m128 v62; // xmm7
  __m128 v63; // xmm2
  __m128 v64; // xmm7
  __m128 v65; // xmm1
  hkpSimpleContactConstraintAtom *v66; // rax
  hkpVelocityAccumulator *v67; // rbx
  float v68; // xmm0_4
  float v69; // xmm3_4
  signed __int64 v70; // r10
  __int64 v71; // r8
  __int64 v72; // r9
  float v73; // xmm0_4
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  __m128 v76; // xmm2
  __m128 v77; // xmm3
  __m128 v78; // xmm4
  float v79; // xmm0_4
  float v80; // xmm3_4
  signed __int64 v81; // r10
  __int64 v82; // r8
  __int64 v83; // r9
  float v84; // xmm0_4
  signed __int64 v85; // rax
  __m128 v86; // xmm0
  __m128 v87; // xmm1
  __m128 v88; // xmm1
  __m128 *v89; // rcx
  __m128 *v90; // rdx
  __m128 *v91; // r8
  __m128 v92; // xmm4
  __m128 v93; // xmm3
  __m128 v94; // xmm2
  __m128 v95; // xmm0
  __m128 v96; // xmm1
  __m128 v97; // xmm5
  __m128 v98; // xmm1
  __m128 v99; // xmm6
  __m128 v100; // xmm1
  __m128 v101; // xmm4
  __m128 v102; // xmm2
  __m128 v103; // xmm1
  __m128 v104; // xmm2
  __m128 v105; // xmm1
  __m128 v106; // xmm5
  __m128 v107; // xmm4
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  __m128 v110; // xmm4
  __m128 v111; // xmm6
  __m128 v112; // xmm7
  __m128 v113; // xmm4
  __m128 v114; // xmm2
  __m128 v115; // xmm3
  __m128 v116; // xmm1
  __m128 v117; // xmm5
  __m128 v118; // xmm6
  __m128 v119; // xmm1
  __m128 v120; // xmm2
  __m128 v121; // xmm1
  __m128 *v122; // rax
  hkpVelocityAccumulator *v123; // rcx
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  hkpJacobianSchema *v127; // r11
  __m128 v128; // xmm4
  __m128 v129; // xmm4
  __m128 v130; // xmm2
  __m128 v131; // xmm3
  __m128 v132; // xmm5
  __m128 v133; // xmm6
  __m128 v134; // xmm9
  __m128 v135; // xmm7
  __m128 v136; // xmm0
  __m128 v137; // xmm4
  __m128 v138; // xmm8
  float v139; // xmm7_4
  float v140; // xmm8_4
  float v141; // xmm0_4
  float v142; // xmm3_4
  signed __int64 v143; // r10
  __int64 v144; // r8
  __int64 v145; // r9
  float v146; // xmm0_4
  __m128 v147; // xmm0
  __m128 v148; // xmm0
  __m128 v149; // xmm1
  __m128 v150; // xmm2
  __m128 v151; // xmm3
  __m128 v152; // xmm0
  float v153; // xmm2_4
  __m128 v154; // xmm1
  __m128 v155; // xmm1
  float v156; // xmm3_4
  float v157; // xmm0_4
  float v158; // xmm3_4
  signed __int64 v159; // r10
  __int64 v160; // r8
  __int64 v161; // r9
  float v162; // xmm0_4
  __m128 v163; // xmm0
  __m128 v164; // xmm0
  __m128 v165; // xmm1
  __m128 v166; // xmm2
  __m128 v167; // xmm1
  __m128 v168; // xmm5
  __m128 v169; // xmm2
  __m128 v170; // xmm1
  __m128 v171; // xmm6
  __m128 v172; // xmm0
  __m128 v173; // xmm1
  __m128 v174; // xmm4
  __m128 v175; // xmm0
  __m128 v176; // xmm1
  __m128 v177; // xmm2
  __m128 v178; // xmm1
  __m128 v179; // xmm8
  __m128 v180; // xmm0
  __m128 v181; // xmm1
  __m128 v182; // xmm5
  __m128 v183; // xmm0
  __m128 v184; // xmm1
  __m128 v185; // xmm3
  __m128 v186; // xmm0
  __m128 v187; // xmm2
  __m128 v188; // xmm1
  __m128 v189; // xmm4
  __m128 v190; // xmm6
  __m128 v191; // xmm1
  __m128 v192; // xmm1
  __m128 *v193; // rax
  signed __int64 v194; // rcx
  __m128 v195; // xmm3
  __m128 v196; // xmm4
  __m128 v197; // xmm5
  __m128 *v198; // rax
  __m128 v199; // xmm1
  __m128 *v200; // rax
  signed __int64 v201; // r8
  signed __int64 v202; // rcx
  __m128 v203; // xmm3
  __m128 v204; // xmm4
  __m128 v205; // xmm5
  __m128 *v206; // rax
  __m128 v207; // xmm1
  __m128 *v208; // rax
  __m128 v209; // xmm1
  __m128 v210; // xmm3
  __m128 v211; // xmm2
  __m128 v212; // xmm1
  __m128 v213; // xmm2
  __m128 v214; // xmm1
  __m128 v215; // xmm3
  __m128 v216; // xmm5
  __m128 v217; // xmm1
  __m128 v218; // xmm5
  __m128 v219; // xmm2
  __m128 v220; // xmm8
  __m128 v221; // xmm4
  __m128 v222; // xmm1
  __m128 v223; // xmm5
  __m128 v224; // xmm4
  __m128 v225; // xmm5
  __m128 v226; // xmm3
  __m128 v227; // xmm3
  __m128 v228; // xmm1
  __m128 *v229; // rax
  hkpVelocityAccumulator *v230; // rcx
  __m128 *v231; // rdx
  __m128 v232; // xmm3
  __m128 v233; // xmm2
  __m128 v234; // xmm5
  __m128 v235; // xmm4
  __m128 v236; // xmm4
  __m128 v237; // xmm5
  __m128 v238; // xmm5
  __m128 v239; // xmm3
  __m128 v240; // xmm1
  __m128 v241; // xmm2
  __m128 v242; // xmm2
  __m128 v243; // xmm0
  __m128 v244; // xmm3
  float *v245; // rcx
  signed __int64 v246; // rax
  _BYTE *v247; // rdx
  hkpSimpleContactConstraintAtom *v248; // rcx
  bool v249; // zf
  hkp1Lin2AngJacobian *v250; // rbx
  __int64 *v251; // rax
  __m128 v252; // xmm2
  _BYTE *v253; // rcx
  float v254; // xmm0_4
  signed __int64 v255; // rax
  __int64 v256; // rdx
  __int64 v257; // rcx
  __int64 v258; // rax
  __int64 v259; // rbx
  __int64 v260; // rdi
  hkVector4f v261; // xmm0
  unsigned __int8 v262; // dl
  const char *v263; // rcx
  __int64 v264; // rax
  hkVector4f v265; // xmm0
  __int64 v266; // rax
  hkVector4f v267; // xmm1
  __int64 v268; // rax
  int v269; // ecx
  bool v270; // sf
  unsigned __int8 v271; // of
  unsigned __int8 v272; // cl
  __int64 v273; // rdx
  __int64 v274; // rcx
  __int64 v275; // rax
  __int64 v276; // rbx
  __int64 v277; // rdi
  hkVector4f v278; // xmm0
  signed __int64 v279; // rax
  __int64 v280; // rdx
  __int64 v281; // rax
  signed __int64 v282; // rcx
  __m128 v283; // xmm4
  __m128 v284; // xmm5
  __m128 v285; // xmm3
  __m128 v286; // xmm2
  __m128 v287; // xmm2
  __m128 v288; // xmm2
  __m128 v289; // xmm0
  __m128 v290; // xmm7
  __m128 v291; // xmm2
  __m128 v292; // xmm4
  __m128 v293; // xmm6
  __m128 v294; // xmm3
  __m128 v295; // xmm2
  __m128 v296; // xmm10
  __m128 v297; // xmm6
  __m128 v298; // xmm8
  __m128 v299; // xmm6
  __m128 v300; // xmm13
  __m128 v301; // xmm7
  __m128 v302; // xmm13
  __m128 v303; // xmm5
  __m128i v304; // xmm4
  __m128 v305; // xmm2
  __m128 v306; // xmm3
  __m128 v307; // xmm0
  signed int v308; // eax
  signed __int64 v309; // rax
  signed __int64 v310; // rcx
  __m128 v311; // xmm0
  __m128 v312; // xmm13
  __m128 v313; // xmm13
  __m128 v314; // xmm13
  __m128 v315; // xmm1
  __m128 v316; // xmm15
  __m128 v317; // xmm10
  __m128 v318; // xmm2
  __m128 v319; // xmm0
  __m128 v320; // xmm7
  __m128 v321; // xmm2
  __m128 v322; // xmm4
  __m128 v323; // xmm6
  __m128 v324; // xmm3
  __m128i v325; // xmm1
  __m128 v326; // xmm2
  __m128 v327; // xmm3
  __m128 v328; // xmm6
  __m128 v329; // xmm0
  __int64 v330; // rdx
  struct hkpConstraintRuntime *v331; // rcx
  float v332; // xmm5_4
  float v333; // xmm4_4
  int v334; // xmm7_4
  float v335; // xmm6_4
  float v336; // xmm2_4
  float v337; // xmm5_4
  float v338; // xmm4_4
  signed __int64 v339; // rax
  __int64 v340; // rax
  signed __int64 v341; // rax
  signed __int64 v342; // rcx
  __m128 v343; // xmm9
  __m128 v344; // xmm1
  __m128 v345; // xmm3
  __m128 v346; // xmm2
  __m128 v347; // xmm4
  __m128 v348; // xmm1
  float v349; // xmm10_4
  __m128 v350; // xmm2
  __m128 v351; // xmm9
  __m128 v352; // xmm2
  __m128 v353; // xmm4
  __m128 v354; // xmm3
  __m128 v355; // xmm3
  __m128 v356; // xmm4
  __m128 v357; // xmm3
  __m128 v358; // xmm0
  __m128 v359; // xmm7
  __m128 v360; // xmm2
  __m128 v361; // xmm4
  __m128 v362; // xmm6
  __m128 v363; // xmm3
  __m128 v364; // xmm2
  __m128 v365; // xmm6
  hkpJacobianSchema *v366; // rdx
  float v367; // xmm5_4
  __m128 *v368; // rax
  __m128 *v369; // rcx
  __m128 v370; // xmm4
  __m128 v371; // xmm3
  __m128 v372; // xmm2
  __m128 v373; // xmm2
  float v374; // xmm0_4
  float v375; // xmm1_4
  float v376; // xmm6_4
  int v377; // er11
  struct hkpConstraintRuntime *v378; // r10
  hkpJacobianSchema *v379; // rdx
  __m128 *v380; // r8
  int v381; // er9
  signed __int64 v382; // r10
  __m128 v383; // xmm5
  __m128 v384; // xmm7
  __m128 v385; // xmm2
  __m128 *v386; // rax
  __m128 *v387; // rcx
  __m128 v388; // xmm0
  __m128 v389; // xmm4
  __m128 v390; // xmm4
  __m128 v391; // xmm3
  __m128 v392; // xmm2
  __m128 v393; // xmm2
  char v394; // cl
  signed __int64 v395; // rax
  signed __int64 v396; // rcx
  __int64 v397; // rdx
  __int64 v398; // rcx
  _BYTE *v399; // r9
  float *v400; // r8
  hkpConstraintMotor *v401; // r10
  __m128 v402; // xmm1
  __int64 v403; // rax
  __m128 v404; // xmm2
  __m128 v405; // xmm2
  __m128 v406; // xmm0
  __m128 v407; // xmm2
  __m128 v408; // xmm7
  __m128 v409; // xmm4
  __m128 v410; // xmm6
  __m128 v411; // xmm3
  __m128 v412; // xmm2
  signed __int16 v413; // ax
  __m128 v414; // xmm6
  __m128 v415; // xmm13
  __m128 v416; // xmm10
  float v417; // xmm0_4
  __m128 v418; // xmm7
  __m128 v419; // xmm5
  __m128i v420; // xmm4
  __m128 v421; // xmm2
  __m128 v422; // xmm3
  __m128 v423; // xmm1
  __m128 *v424; // rdx
  __m128 *v425; // rcx
  __m128 *v426; // rbx
  __int64 v427; // rax
  __m128 v428; // xmm2
  __m128 v429; // xmm3
  __m128 v430; // xmm2
  __m128 v431; // xmm3
  __m128 v432; // xmm2
  __m128 v433; // xmm2
  hkpSolverResults *v434; // rax
  signed __int64 v435; // rax
  float v436; // xmm0_4
  float v437; // xmm0_4
  signed __int64 v438; // rax
  hkMatrix3f *v439; // rdx
  _BYTE *v440; // rdx
  hkpConstraintMotor **v441; // rax
  signed int v442; // er8
  unsigned __int64 v443; // r9
  __int64 v444; // rdi
  hkpConstraintMotor *v445; // r10
  __int64 v446; // rcx
  signed __int64 v447; // rax
  signed __int64 v448; // rcx
  __m128 v449; // xmm5
  __m128 v450; // xmm1
  __m128 v451; // xmm3
  __m128 v452; // xmm2
  __m128 v453; // xmm4
  __m128 v454; // xmm1
  __m128 v455; // xmm2
  __m128 v456; // xmm5
  __m128 v457; // xmm2
  __m128 v458; // xmm8
  __m128 v459; // xmm4
  __m128 v460; // xmm3
  __m128 v461; // xmm3
  __m128 v462; // xmm4
  __m128 v463; // xmm7
  __m128 v464; // xmm3
  __m128 v465; // xmm0
  __m128 v466; // xmm6
  __m128 v467; // xmm2
  __m128 v468; // xmm4
  __m128 v469; // xmm5
  __m128 v470; // xmm3
  __m128 v471; // xmm2
  __m128 v472; // xmm5
  __m128 v473; // xmm7
  __m128 v474; // xmm1
  __m128 v475; // xmm2
  __m128 v476; // xmm1
  __m128 v477; // xmm3
  __m128 v478; // xmm1
  __m128 v479; // xmm2
  __m128 v480; // xmm7
  __m128 v481; // xmm2
  __m128 v482; // xmm4
  __m128 v483; // xmm4
  __m128 v484; // xmm3
  __m128 v485; // xmm1
  __m128 v486; // xmm2
  __m128 v487; // xmm0
  __m128 v488; // xmm5
  __m128 v489; // xmm2
  __m128 v490; // xmm8
  __m128 v491; // xmm4
  __m128 v492; // xmm3
  __m128 v493; // xmm2
  __m128 v494; // xmm4
  float v495; // xmm4_4
  __m128 *v496; // rax
  __m128 *v497; // rcx
  __m128 *v498; // rbx
  float v499; // xmm6_4
  __m128 v500; // xmm1
  __m128 v501; // xmm2
  __m128 v502; // xmm3
  __m128 v503; // xmm2
  __m128 v504; // xmm2
  signed __int64 v505; // rax
  float v506; // xmm0_4
  signed __int64 v507; // rax
  signed __int64 v508; // rax
  __m128 v509; // xmm7
  __m128 v510; // xmm8
  unsigned int v511; // xmm9_4
  unsigned int v512; // xmm10_4
  __m128 *v513; // rax
  __m128 *v514; // rcx
  __m128 *v515; // rdx
  __m128 v516; // xmm4
  __m128 v517; // xmm5
  __m128 v518; // xmm3
  __m128 v519; // xmm1
  __m128 v520; // xmm2
  __m128 v521; // xmm5
  __m128 v522; // xmm3
  __m128 v523; // xmm1
  __m128 v524; // xmm2
  __m128 v525; // xmm4
  __m128 v526; // xmm11
  __m128 v527; // xmm3
  __m128 v528; // xmm1
  __m128 v529; // xmm2
  __m128 v530; // xmm5
  __m128 v531; // xmm5
  __m128 v532; // xmm4
  __m128 v533; // xmm4
  __m128 v534; // xmm3
  __m128 v535; // xmm3
  __m128 v536; // xmm1
  __m128 v537; // xmm1
  __m128 v538; // xmm3
  __m128 v539; // xmm1
  __m128 v540; // xmm3
  __m128 v541; // xmm10
  __m128 v542; // xmm1
  __m128 v543; // xmm8
  __m128 v544; // xmm1
  float *v545; // rcx
  float v546; // xmm0_4
  struct hkpConstraintRuntime *v547; // rax
  __m128 v548; // xmm9
  __m128 *v549; // rdx
  float *v550; // r9
  float *v551; // r8
  unsigned int *v552; // rcx
  hkVector4f v553; // xmm11
  hkVector4f v554; // xmm13
  hkVector4f v555; // xmm15
  hkVector4f v556; // xmm10
  __m128 v557; // xmm9
  __m128 v558; // xmm9
  __m128 v559; // xmm1
  __m128 v560; // xmm3
  __m128 v561; // xmm2
  hkVector4f v562; // xmm3
  __m128 v563; // xmm0
  __m128 v564; // xmm1
  __m128 v565; // xmm1
  __m128 v566; // xmm2
  __m128 v567; // xmm0
  __m128 v568; // xmm7
  __m128 v569; // xmm2
  __m128 v570; // xmm4
  __m128 v571; // xmm6
  __m128 v572; // xmm3
  __m128 v573; // xmm5
  __m128 v574; // xmm2
  __m128 v575; // xmm1
  __m128 v576; // xmm6
  float v577; // xmm6_4
  float v578; // xmm1_4
  float v579; // xmm0_4
  float v580; // xmm2_4
  __m128 *v581; // rax
  __m128i v582; // xmm7
  hkpVelocityAccumulator *v583; // rcx
  float v584; // xmm7_4
  __m128 v585; // xmm9
  __m128 v586; // xmm9
  float v587; // xmm0_4
  __m128 v588; // xmm11
  __m128 v589; // xmm13
  float v590; // xmm7_4
  __m128 v591; // xmm1
  __m128 v592; // xmm4
  __m128 v593; // xmm2
  __m128 v594; // xmm4
  __m128 v595; // xmm2
  __m128 v596; // xmm3
  __m128 v597; // xmm1
  __m128 v598; // xmm2
  __m128 v599; // xmm2
  __m128 v600; // xmm0
  __m128 v601; // xmm2
  __m128 v602; // xmm3
  __m128 v603; // xmm5
  __m128 v604; // xmm0
  __m128 v605; // xmm2
  __m128 v606; // xmm1
  float v607; // xmm0_4
  float v608; // ST50_4
  __m128 v609; // xmm11
  __m128 v610; // xmm13
  __m128 v611; // xmm1
  __m128 v612; // xmm2
  __m128 v613; // xmm3
  __m128 v614; // xmm0
  __m128 v615; // xmm2
  __m128 v616; // xmm3
  __m128 v617; // xmm1
  __m128 v618; // xmm2
  __m128 v619; // xmm3
  __m128 v620; // xmm3
  __m128 v621; // xmm0
  __m128 v622; // xmm2
  __m128 v623; // xmm1
  __m128 v624; // xmm2
  __m128 v625; // xmm0
  __m128 v626; // xmm1
  float v627; // xmm0_4
  struct hkpConstraintRuntime *v628; // rax
  __m128 *v629; // rdx
  float *v630; // r9
  float *v631; // r8
  signed int *v632; // rcx
  hkVector4f v633; // xmm15
  __m128 v634; // xmm6
  __m128 v635; // xmm2
  __m128 v636; // xmm1
  __m128 v637; // xmm4
  __m128 v638; // xmm3
  __m128 v639; // xmm2
  __m128 v640; // xmm2
  __m128 v641; // xmm0
  __m128 v642; // xmm0
  __m128 v643; // xmm9
  __m128 v644; // xmm9
  __m128 v645; // xmm10
  __m128 v646; // xmm1
  __m128 v647; // xmm10
  __m128 v648; // xmm4
  __m128 v649; // xmm1
  __m128 v650; // xmm3
  __m128 v651; // xmm2
  __m128 v652; // xmm5
  __m128 v653; // xmm1
  __m128 v654; // xmm0
  __m128 v655; // xmm2
  __m128 v656; // xmm9
  __m128 v657; // xmm0
  __m128 v658; // xmm3
  __m128 v659; // xmm10
  __m128 v660; // xmm1
  __m128 v661; // xmm2
  __m128 v662; // xmm11
  __m128 v663; // xmm4
  __m128 v664; // xmm11
  __m128 v665; // xmm0
  __m128 v666; // xmm7
  __m128 v667; // xmm1
  __m128 v668; // xmm4
  __m128 v669; // xmm6
  __m128 v670; // xmm3
  __m128 v671; // xmm2
  __m128 v672; // xmm6
  float v673; // xmm0_4
  float v674; // xmm1_4
  float v675; // xmm1_4
  __m128 v676; // xmm5
  float v677; // xmm7_4
  __m128 v678; // xmm5
  float v679; // xmm6_4
  __m128 v680; // xmm3
  __m128 v681; // xmm3
  __m128 v682; // xmm2
  __m128 v683; // xmm5
  __m128 v684; // xmm1
  __m128 v685; // xmm3
  __m128 v686; // xmm1
  __m128 *v687; // rax
  hkpVelocityAccumulator *v688; // rcx
  __m128 v689; // xmm1
  __m128 v690; // xmm2
  __m128 v691; // xmm0
  __m128 v692; // xmm3
  __m128 v693; // xmm5
  __m128 v694; // xmm3
  __m128 v695; // xmm2
  __m128 v696; // xmm1
  __m128 v697; // xmm3
  __m128 v698; // xmm3
  __m128 v699; // xmm4
  __m128 v700; // xmm4
  __m128 v701; // xmm3
  __m128 v702; // xmm1
  __m128 v703; // xmm2
  __m128 v704; // xmm2
  __m128 v705; // xmm0
  __m128 v706; // xmm3
  __m128 v707; // xmm11
  __m128 *v708; // rcx
  __m128 *v709; // rdx
  hkVector4f v710; // xmm7
  hkVector4f v711; // xmm5
  hkVector4f v712; // xmm2
  __m128 v713; // xmm3
  __m128 v714; // xmm6
  __m128 *v715; // rax
  __m128 v716; // xmm1
  __m128 v717; // xmm2
  __m128 v718; // xmm5
  __m128 v719; // xmm5
  __m128 v720; // xmm4
  __m128 v721; // xmm4
  __m128 v722; // xmm5
  __m128 v723; // xmm3
  __m128 v724; // xmm1
  __m128 v725; // xmm2
  __m128 v726; // xmm2
  __m128 v727; // xmm0
  __m128 v728; // xmm3
  __m128 v729; // xmm2
  __m128 v730; // xmm1
  __m128 v731; // xmm7
  __m128 v732; // xmm3
  __m128 v733; // xmm4
  __m128 v734; // xmm3
  __m128 v735; // xmm4
  __m128 v736; // xmm3
  __m128 v737; // xmm1
  __m128 v738; // xmm2
  __m128 v739; // xmm2
  __m128 v740; // xmm0
  __m128 v741; // xmm3
  __m128 v742; // xmm1
  __m128 v743; // xmm4
  __m128 v744; // xmm6
  __m128 v745; // xmm4
  __m128 v746; // xmm6
  __m128 v747; // xmm5
  __m128 v748; // xmm2
  __m128 v749; // xmm1
  signed __int64 v750; // rax
  __m128 v751; // xmm1
  __m128 v752; // xmm1
  hkpVelocityAccumulator *v753; // rax
  hkpVelocityAccumulator *v754; // rax
  __m128 v755; // xmm1
  float v756; // xmm6_4
  unsigned __int16 *v757; // r8
  signed __int64 v758; // r10
  int v759; // eax
  signed __int64 v760; // r11
  signed __int64 v761; // rcx
  __int64 v762; // rdx
  float *v763; // rax
  unsigned __int64 v764; // r9
  float v765; // xmm0_4
  signed __int64 v766; // rcx
  float v767; // xmm0_4
  signed __int64 v768; // rcx
  float v769; // xmm0_4
  __int64 v770; // rcx
  float v771; // xmm0_4
  float *v772; // rcx
  float *v773; // rdx
  signed __int64 v774; // r10
  float v775; // xmm0_4
  hkpSimpleContactConstraintAtom *v776; // rcx
  unsigned __int16 *v777; // rcx
  hkpSimpleContactConstraintAtom *v778; // rcx
  __m128 v779; // xmm4
  __m128 v780; // xmm5
  hkpVelocityAccumulator *v781; // rax
  hkpVelocityAccumulator *v782; // rax
  __int128 v783; // xmm1
  __m128 v784; // xmm7
  hkpSimpleContactConstraintAtom *v785; // rcx
  bool v786; // bl
  __m128 v787; // xmm2
  __m128 v788; // xmm6
  hkpConstraintAtom *v789; // [rsp+50h] [rbp-B0h]
  unsigned __int16 *v790; // [rsp+58h] [rbp-A8h]
  unsigned __int64 v791; // [rsp+60h] [rbp-A0h]
  hkTransformf baseB; // [rsp+70h] [rbp-90h]
  hkSimdFloat32 maxAngularImpulse; // [rsp+B0h] [rbp-50h]
  hkTransformf baseA; // [rsp+C0h] [rbp-40h]
  __m128 v795; // [rsp+100h] [rbp+0h]
  float v796; // [rsp+110h] [rbp+10h]
  int v797; // [rsp+114h] [rbp+14h]
  float v798; // [rsp+118h] [rbp+18h]
  float v799; // [rsp+11Ch] [rbp+1Ch]
  _BYTE *v800; // [rsp+120h] [rbp+20h]
  __m128 v801; // [rsp+130h] [rbp+30h]
  __m128 v802; // [rsp+140h] [rbp+40h]
  __m128 v803; // [rsp+150h] [rbp+50h]
  __m128 v804; // [rsp+160h] [rbp+60h]
  __m128 v805; // [rsp+170h] [rbp+70h]
  unsigned int v806; // [rsp+180h] [rbp+80h]
  int v807; // [rsp+188h] [rbp+88h]
  int v808; // [rsp+190h] [rbp+90h]
  int v809; // [rsp+198h] [rbp+98h]
  unsigned int v810; // [rsp+1A0h] [rbp+A0h]
  float v811; // [rsp+1A8h] [rbp+A8h]
  int v812; // [rsp+1ACh] [rbp+ACh]
  struct hkpConstraintRuntime *v813; // [rsp+1B0h] [rbp+B0h]
  float v814; // [rsp+1B8h] [rbp+B8h]
  int v815; // [rsp+1BCh] [rbp+BCh]
  float v816; // [rsp+1C0h] [rbp+C0h]
  float v817; // [rsp+1C4h] [rbp+C4h]
  int v818; // [rsp+1C8h] [rbp+C8h]
  int v819; // [rsp+1CCh] [rbp+CCh]
  __m128 v820; // [rsp+1D0h] [rbp+D0h]
  __m128 v821; // [rsp+1E0h] [rbp+E0h]
  __m128 v822; // [rsp+1F0h] [rbp+F0h]
  hkMatrix3f v823; // [rsp+200h] [rbp+100h]
  int v824; // [rsp+230h] [rbp+130h]
  __int64 v825; // [rsp+234h] [rbp+134h]
  int v826; // [rsp+240h] [rbp+140h]
  __int64 v827; // [rsp+244h] [rbp+144h]
  int v828; // [rsp+250h] [rbp+150h]
  __int64 v829; // [rsp+254h] [rbp+154h]
  int v830; // [rsp+260h] [rbp+160h]
  __int64 v831; // [rsp+264h] [rbp+164h]
  hkMatrix3f v832; // [rsp+270h] [rbp+170h]
  __m128 v833; // [rsp+2A0h] [rbp+1A0h]
  __m128 v834; // [rsp+2B0h] [rbp+1B0h]
  __m128 v835; // [rsp+2C0h] [rbp+1C0h]
  hkVector4f deltaVel; // [rsp+2D0h] [rbp+1D0h]
  __int64 v837; // [rsp+2E0h] [rbp+1E0h]
  int v838; // [rsp+2E8h] [rbp+1E8h]
  int v839; // [rsp+2F0h] [rbp+1F0h]
  int v840; // [rsp+2F4h] [rbp+1F4h]
  int v841; // [rsp+2F8h] [rbp+1F8h]
  hkpConstraintMotorOutput v842; // [rsp+300h] [rbp+200h]
  hkpConstraintMotorOutput v843; // [rsp+318h] [rbp+218h]
  hkp1dBilateralConstraintStatus statusOut; // [rsp+330h] [rbp+230h]
  hkpConstraintQueryIn *v845; // [rsp+338h] [rbp+238h]
  __int64 v846; // [rsp+340h] [rbp+240h]
  float v847; // [rsp+348h] [rbp+248h]
  float v848; // [rsp+34Ch] [rbp+24Ch]
  hkpConstraintMotorInput input; // [rsp+350h] [rbp+250h]
  hkpConstraintMotorInput v850; // [rsp+370h] [rbp+270h]
  __m128 *v851; // [rsp+390h] [rbp+290h]
  __m128 *v852; // [rsp+398h] [rbp+298h]
  hkVector4f v853; // [rsp+3A0h] [rbp+2A0h]
  hkVector4f v854; // [rsp+3B0h] [rbp+2B0h]
  __m128 v855; // [rsp+3C0h] [rbp+2C0h]
  __m128 v856; // [rsp+3D0h] [rbp+2D0h]
  __m128 v857; // [rsp+3E0h] [rbp+2E0h]
  __m128 v858; // [rsp+3F0h] [rbp+2F0h]
  unsigned int v859; // [rsp+400h] [rbp+300h]
  unsigned int v860; // [rsp+404h] [rbp+304h]
  unsigned int v861; // [rsp+408h] [rbp+308h]
  unsigned int v862; // [rsp+40Ch] [rbp+30Ch]
  __m128 v863; // [rsp+410h] [rbp+310h]
  hkSimdFloat32 scale; // [rsp+420h] [rbp+320h]
  __m128 v865; // [rsp+430h] [rbp+330h]
  hkMatrix3f v866; // [rsp+440h] [rbp+340h]
  hkVector4f vLocalArmA; // [rsp+470h] [rbp+370h]
  hkMatrix3f v868; // [rsp+480h] [rbp+380h]
  hkVector4f vLocalArmB; // [rsp+4B0h] [rbp+3B0h]
  __int128 v870; // [rsp+4C0h] [rbp+3C0h]
  hkSimdFloat32 maxLinearImpulse; // [rsp+4D0h] [rbp+3D0h]
  __m128 v872; // [rsp+4E0h] [rbp+3E0h]
  hkVector4f v873; // [rsp+4F0h] [rbp+3F0h]
  __m128 v874; // [rsp+500h] [rbp+400h]
  float v875; // [rsp+510h] [rbp+410h]
  struct hkpConstraintRuntime *v876; // [rsp+518h] [rbp+418h]
  hkMatrix3f angToLinVelA; // [rsp+520h] [rbp+420h]
  hkMatrix3f angToLinVelB; // [rsp+550h] [rbp+450h]
  hkMatrix3f aTb; // [rsp+580h] [rbp+480h]
  hkp1dAngularBilateralConstraintInfo v880; // [rsp+5B0h] [rbp+4B0h]
  hkp1dAngularBilateralConstraintInfo v881; // [rsp+5E0h] [rbp+4E0h]
  __int16 v882; // [rsp+610h] [rbp+510h]
  char v883; // [rsp+612h] [rbp+512h]
  __m128 v884; // [rsp+620h] [rbp+520h]
  __m128 v885; // [rsp+630h] [rbp+530h]
  __m128 v886; // [rsp+640h] [rbp+540h]
  hkVector4f v887; // [rsp+650h] [rbp+550h]
  __m128 v888; // [rsp+660h] [rbp+560h]
  __m128 v889; // [rsp+670h] [rbp+570h]
  hkVector4f r; // [rsp+680h] [rbp+580h]
  __m128 v891; // [rsp+690h] [rbp+590h]
  __m128 v892; // [rsp+6A0h] [rbp+5A0h]
  __m128 v893; // [rsp+6B0h] [rbp+5B0h]
  __int128 v894; // [rsp+6C0h] [rbp+5C0h]
  __m128 v895; // [rsp+6D0h] [rbp+5D0h]
  __m128 v896; // [rsp+6E0h] [rbp+5E0h]
  hkVector4f v897; // [rsp+6F0h] [rbp+5F0h]
  hkRotationf cTb; // [rsp+700h] [rbp+600h]
  __m128 v899; // [rsp+730h] [rbp+630h]
  __int128 v900; // [rsp+740h] [rbp+640h]
  __m128 v901; // [rsp+750h] [rbp+650h]
  __m128 v902; // [rsp+760h] [rbp+660h]
  hkVector4f v903; // [rsp+770h] [rbp+670h]
  hkRotationf v904; // [rsp+780h] [rbp+680h]
  __m128 v905; // [rsp+7B0h] [rbp+6B0h]
  hkp1dLinearBilateralUserTauConstraintInfo v906; // [rsp+7C0h] [rbp+6C0h]
  hkp1dLinearLimitInfo v907; // [rsp+800h] [rbp+700h]
  hkpConstraintQueryIn v908; // [rsp+840h] [rbp+740h]
  hkpConstraintQueryIn ina; // [rsp+8D0h] [rbp+7D0h]
  __int128 v910; // [rsp+960h] [rbp+860h]
  hkVector4f v911; // [rsp+970h] [rbp+870h]
  hkVector4f v912; // [rsp+980h] [rbp+880h]
  hkVector4f invMassB; // [rsp+990h] [rbp+890h]
  hkVector4f v914; // [rsp+9A0h] [rbp+8A0h]
  hkVector4f v915; // [rsp+9B0h] [rbp+8B0h]
  hkVector4f v916; // [rsp+9C0h] [rbp+8C0h]
  __int128 v917; // [rsp+9D0h] [rbp+8D0h]
  __int128 v918; // [rsp+9E0h] [rbp+8E0h]
  hkVector4f v919; // [rsp+9F0h] [rbp+8F0h]
  hkVector4f v920; // [rsp+A00h] [rbp+900h]
  hkVector4f invMassA; // [rsp+A10h] [rbp+910h]
  hkVector4f v922; // [rsp+A20h] [rbp+920h]
  hkVector4f v923; // [rsp+A30h] [rbp+930h]
  hkVector4f v924; // [rsp+A40h] [rbp+940h]
  hkVector4f v925; // [rsp+A50h] [rbp+950h]
  hkMatrix3f THIS; // [rsp+A60h] [rbp+960h]
  hkp1dLinearBilateralConstraintInfo info; // [rsp+A90h] [rbp+990h]
  hkpConstraintMotorOutput output; // [rsp+AC0h] [rbp+9C0h]
  hkpConstraintQueryIn v929; // [rsp+AE0h] [rbp+9E0h]
  hkp1dAngularBilateralConstraintInfo v930; // [rsp+B70h] [rbp+A70h]
  hkpConstraintQueryIn v931; // [rsp+BA0h] [rbp+AA0h]
  __m128 v932; // [rsp+C30h] [rbp+B30h]
  __m128 v933; // [rsp+C40h] [rbp+B40h]
  __m128 v934; // [rsp+C50h] [rbp+B50h]
  __m128 v935; // [rsp+C60h] [rbp+B60h]
  __m128 v936; // [rsp+C70h] [rbp+B70h]
  __m128 v937; // [rsp+C80h] [rbp+B80h]
  __m128 v938; // [rsp+C90h] [rbp+B90h]
  __m128 v939; // [rsp+CA0h] [rbp+BA0h]
  __m128 v940; // [rsp+CB0h] [rbp+BB0h]
  __int128 v941; // [rsp+CC0h] [rbp+BC0h]
  __m128 v942; // [rsp+CD0h] [rbp+BD0h]
  __m128 v943; // [rsp+CE0h] [rbp+BE0h]
  __m128 v944; // [rsp+CF0h] [rbp+BF0h]
  __m128 v945; // [rsp+D00h] [rbp+C00h]
  __m128 v946; // [rsp+D10h] [rbp+C10h]
  __m128 v947; // [rsp+D20h] [rbp+C20h]
  __m128 v948; // [rsp+D30h] [rbp+C30h]
  __m128 v949; // [rsp+D40h] [rbp+C40h]
  __m128 v950; // [rsp+D50h] [rbp+C50h]
  __m128 v951; // [rsp+D60h] [rbp+C60h]
  __m128 v952; // [rsp+D70h] [rbp+C70h]
  __m128 v953; // [rsp+D80h] [rbp+C80h]
  __m128 v954; // [rsp+D90h] [rbp+C90h]
  __m128 v955; // [rsp+DA0h] [rbp+CA0h]
  __m128 v956; // [rsp+DB0h] [rbp+CB0h]
  __m128 v957; // [rsp+DC0h] [rbp+CC0h]
  __m128 v958; // [rsp+DD0h] [rbp+CD0h]
  __m128 v959; // [rsp+DE0h] [rbp+CE0h]
  __m128 v960; // [rsp+DF0h] [rbp+CF0h]
  __m128 v961; // [rsp+E00h] [rbp+D00h]
  __m128 v962; // [rsp+E10h] [rbp+D10h]
  __m128 v963; // [rsp+E20h] [rbp+D20h]
  __m128 v964; // [rsp+E30h] [rbp+D30h]
  __m128 v965; // [rsp+E40h] [rbp+D40h]
  __m128 v966; // [rsp+E50h] [rbp+D50h]
  __m128 v967; // [rsp+E60h] [rbp+D60h]
  __m128 v968; // [rsp+E70h] [rbp+D70h]
  __m128 v969; // [rsp+E80h] [rbp+D80h]
  __m128 v970; // [rsp+E90h] [rbp+D90h]
  __m128 v971; // [rsp+EA0h] [rbp+DA0h]
  __m128 v972; // [rsp+EB0h] [rbp+DB0h]
  __m128 v973; // [rsp+EC0h] [rbp+DC0h]
  __m128 v974; // [rsp+ED0h] [rbp+DD0h]
  __m128 v975; // [rsp+EE0h] [rbp+DE0h]
  __m128 v976; // [rsp+EF0h] [rbp+DF0h]
  __m128 v977; // [rsp+F00h] [rbp+E00h]
  __m128 v978; // [rsp+F10h] [rbp+E10h]
  __m128 v979; // [rsp+F20h] [rbp+E20h]
  __m128 v980; // [rsp+F30h] [rbp+E30h]
  __m128 v981; // [rsp+F40h] [rbp+E40h]
  __m128 v982; // [rsp+F50h] [rbp+E50h]
  __m128 v983; // [rsp+F60h] [rbp+E60h]
  __m128 v984; // [rsp+F70h] [rbp+E70h]
  __m128 v985; // [rsp+F80h] [rbp+E80h]
  __m128 v986; // [rsp+F90h] [rbp+E90h]
  __m128 v987; // [rsp+FA0h] [rbp+EA0h]
  __m128 v988; // [rsp+FB0h] [rbp+EB0h]
  __m128 v989; // [rsp+FC0h] [rbp+EC0h]
  __m128 v990; // [rsp+FD0h] [rbp+ED0h]
  __m128 v991; // [rsp+FE0h] [rbp+EE0h]
  __m128 v992; // [rsp+FF0h] [rbp+EF0h]
  __m128 v993; // [rsp+1000h] [rbp+F00h]
  __m128 v994; // [rsp+1010h] [rbp+F10h]
  __m128 v995; // [rsp+1020h] [rbp+F20h]
  __m128 v996; // [rsp+1030h] [rbp+F30h]
  __m128 v997; // [rsp+1040h] [rbp+F40h]
  __m128 v998; // [rsp+1050h] [rbp+F50h]
  __m128 v999; // [rsp+1060h] [rbp+F60h]
  __m128 v1000; // [rsp+1070h] [rbp+F70h]
  __m128 v1001; // [rsp+1080h] [rbp+F80h]
  __m128 v1002; // [rsp+1090h] [rbp+F90h]
  __m128 v1003; // [rsp+10A0h] [rbp+FA0h]
  __int128 v1004; // [rsp+10B0h] [rbp+FB0h]
  __m128 v1005; // [rsp+10C0h] [rbp+FC0h]
  __m128 v1006; // [rsp+10D0h] [rbp+FD0h]
  __m128 v1007; // [rsp+10E0h] [rbp+FE0h]
  __m128 v1008; // [rsp+10F0h] [rbp+FF0h]
  __m128 v1009; // [rsp+1100h] [rbp+1000h]
  __m128 v1010; // [rsp+1110h] [rbp+1010h]
  __m128 v1011; // [rsp+1120h] [rbp+1020h]
  __m128 v1012; // [rsp+1130h] [rbp+1030h]
  __m128 v1013; // [rsp+1140h] [rbp+1040h]
  __m128 v1014; // [rsp+1150h] [rbp+1050h]
  __m128 v1015; // [rsp+1160h] [rbp+1060h]
  __m128 v1016; // [rsp+1170h] [rbp+1070h]
  __m128 v1017; // [rsp+1180h] [rbp+1080h]
  __m128 v1018; // [rsp+1190h] [rbp+1090h]
  hkpConstraintQueryIn v1019; // [rsp+11A0h] [rbp+10A0h]
  hkpVelocityAccumulator v1020; // [rsp+1230h] [rbp+1130h]
  hkpSimpleContactConstraintAtom *atom; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomi; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atoma; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomb; // [rsp+1380h] [rbp+1280h]
  float atomj; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomc; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomd; // [rsp+1380h] [rbp+1280h]
  float atomk; // [rsp+1380h] [rbp+1280h]
  float atoml; // [rsp+1380h] [rbp+1280h]
  float atomm; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atome; // [rsp+1380h] [rbp+1280h]
  int atomf; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomg; // [rsp+1380h] [rbp+1280h]
  hkpSimpleContactConstraintAtom *atomh; // [rsp+1380h] [rbp+1280h]
  float sizeOfAllAtomsf; // [rsp+1388h] [rbp+1288h]
  float sizeOfAllAtomsg; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsh; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsi; // [rsp+1388h] [rbp+1288h]
  float sizeOfAllAtomsj; // [rsp+1388h] [rbp+1288h]
  float sizeOfAllAtomsk; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsl; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsm; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsa; // [rsp+1388h] [rbp+1288h]
  float sizeOfAllAtomsn; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomso; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsp; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsb; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsq; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsr; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomss; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomst; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsu; // [rsp+1388h] [rbp+1288h]
  unsigned int sizeOfAllAtomsv; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsc; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomsd; // [rsp+1388h] [rbp+1288h]
  int sizeOfAllAtomse; // [rsp+1388h] [rbp+1288h]
  signed int v1057; // [rsp+1390h] [rbp+1290h]
  hkpConstraintQueryOut *v1058; // [rsp+1398h] [rbp+1298h]

  v1058 = out;
  v4 = in->m_transformA.m_storage;
  v5 = (__m128)xmmword_141A712A0;
  v6 = in;
  v7 = out;
  v8 = (unsigned __int16 *)((char *)&atoms->m_type.m_storage + sizeOfAllAtoms);
  v9 = &atoms->m_type.m_storage;
  v789 = atoms;
  v790 = (unsigned __int16 *)((char *)&atoms->m_type.m_storage + sizeOfAllAtoms);
  baseA.m_rotation.m_col0 = v4->m_rotation.m_col0;
  baseA.m_rotation.m_col1 = v4->m_rotation.m_col1;
  baseA.m_rotation.m_col2 = v4->m_rotation.m_col2;
  v10.m_quad = (__m128)v4->m_translation;
  v870 = xmmword_141A712A0;
  baseA.m_translation = (hkVector4f)v10.m_quad;
  _mm_store_si128((__m128i *)&maxLinearImpulse, (__m128i)xmmword_141A712A0);
  v11 = 0i64;
  v12 = in->m_transformB.m_storage;
  v13.m_quad = (__m128)v12->m_rotation.m_col0;
  v872 = 0i64;
  vLocalArmA.m_quad = 0i64;
  baseB.m_rotation.m_col0 = (hkVector4f)v13.m_quad;
  v14 = 0i64;
  baseB.m_rotation.m_col1 = v12->m_rotation.m_col1;
  v15.m_quad = (__m128)v12->m_rotation.m_col2;
  v865 = 0i64;
  baseB.m_rotation.m_col2 = (hkVector4f)v15.m_quad;
  v16.m_quad = (__m128)v12->m_translation;
  vLocalArmB.m_quad = 0i64;
  baseB.m_translation = (hkVector4f)v16.m_quad;
  LODWORD(v12) = in->m_accumulatorAIndex.m_storage;
  v17 = out->m_constraintRuntime.m_storage;
  v18 = out->m_jacobianSchemas.m_storage;
  v19 = v6->m_accumulatorBIndex.m_storage;
  v20 = v6->m_constraintInstance.m_storage;
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
    while ( 1 )
    {
      v24 = *v9;
      while ( 2 )
      {
        switch ( v24 )
        {
          case 0u:
            v9 = (unsigned __int16 *)(((unsigned __int64)v9 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
            v789 = (hkpConstraintAtom *)v9;
            v24 = *v9;
            if ( v24 <= 0x23 )
              continue;
            goto LABEL_237;
          case 1u:
            v7->m_jacobianSchemas.m_storage -= 32;
            (*((void (__fastcall **)(_QWORD, hkpConstraintQueryIn *, hkpConstraintQueryOut *, signed __int64))v9 + 1))(
              *((_QWORD *)v9 + 2),
              v6,
              v7,
              2i64);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 800000);
            v8 = v790;
            v9 += 16;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage
                                                          + 800000;
            goto LABEL_236;
          case 2u:
            v25 = v6->m_transformA.m_storage;
            v26 = 3i64;
            v27 = (__m128 *)(v9 + 32);
            v28 = v25->m_rotation.m_col0.m_quad;
            v29 = v25->m_rotation.m_col1.m_quad;
            v30 = v25->m_rotation.m_col2.m_quad;
            do
            {
              v31 = *v27;
              --v27;
              --v26;
              *(__m128 *)((char *)v27 + (char *)&baseA.m_translation - (char *)v9 - 48) = _mm_add_ps(
                                                                                            _mm_add_ps(
                                                                                              _mm_mul_ps(
                                                                                                _mm_shuffle_ps(
                                                                                                  v31,
                                                                                                  v31,
                                                                                                  85),
                                                                                                v29),
                                                                                              _mm_mul_ps(
                                                                                                _mm_shuffle_ps(
                                                                                                  v31,
                                                                                                  v31,
                                                                                                  0),
                                                                                                v28)),
                                                                                            _mm_mul_ps(
                                                                                              _mm_shuffle_ps(
                                                                                                v31,
                                                                                                v31,
                                                                                                170),
                                                                                              v30));
            }
            while ( v26 >= 0 );
            v32 = 3i64;
            v33 = (__m128 *)(v9 + 64);
            baseA.m_translation.m_quad = _mm_add_ps(baseA.m_translation.m_quad, v25->m_translation.m_quad);
            v34 = v6->m_transformB.m_storage;
            v35 = v34->m_rotation.m_col0.m_quad;
            v36 = v34->m_rotation.m_col1.m_quad;
            v37 = v34->m_rotation.m_col2.m_quad;
            do
            {
              v38 = *v33;
              --v33;
              --v32;
              *(__m128 *)((char *)v33 + (char *)&baseB.m_translation - (char *)v9 - 112) = _mm_add_ps(
                                                                                             _mm_add_ps(
                                                                                               _mm_mul_ps(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v38,
                                                                                                   v38,
                                                                                                   85),
                                                                                                 v36),
                                                                                               _mm_mul_ps(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v38,
                                                                                                   v38,
                                                                                                   0),
                                                                                                 v35)),
                                                                                             _mm_mul_ps(
                                                                                               _mm_shuffle_ps(
                                                                                                 v38,
                                                                                                 v38,
                                                                                                 170),
                                                                                               v37));
            }
            while ( v32 >= 0 );
            v9 += 72;
            baseB.m_translation.m_quad = _mm_add_ps(baseB.m_translation.m_quad, v34->m_translation.m_quad);
            goto LABEL_236;
          case 3u:
            v191 = *((__m128 *)v9 + 1);
            baseA.m_translation.m_quad = _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(v191, v191, 85),
                                                 v6->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(*((__m128 *)v9 + 1), v191, 0),
                                                 v6->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v191, v191, 170),
                                               v6->m_transformA.m_storage->m_rotation.m_col2.m_quad)),
                                           v6->m_transformA.m_storage->m_translation.m_quad);
            v192 = *((__m128 *)v9 + 2);
            baseB.m_translation.m_quad = _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(v192, v192, 85),
                                                 v6->m_transformB.m_storage->m_rotation.m_col1.m_quad),
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(*((__m128 *)v9 + 2), v192, 0),
                                                 v6->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v192, v192, 170),
                                               v6->m_transformB.m_storage->m_rotation.m_col2.m_quad)),
                                           v6->m_transformB.m_storage->m_translation.m_quad);
            goto LABEL_235;
          case 4u:
            v193 = &v6->m_transformA.m_storage->m_rotation.m_col0.m_quad;
            v194 = 3i64;
            v195 = *v193;
            v196 = v193[1];
            v197 = v193[2];
            v198 = (__m128 *)(v9 + 32);
            do
            {
              v199 = *v198;
              --v198;
              --v194;
              *(__m128 *)((char *)v198 + (char *)&baseA.m_translation - (char *)v9 - 48) = _mm_add_ps(
                                                                                             _mm_add_ps(
                                                                                               _mm_mul_ps(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v199,
                                                                                                   v199,
                                                                                                   85),
                                                                                                 v196),
                                                                                               _mm_mul_ps(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v199,
                                                                                                   v199,
                                                                                                   0),
                                                                                                 v195)),
                                                                                             _mm_mul_ps(
                                                                                               _mm_shuffle_ps(
                                                                                                 v199,
                                                                                                 v199,
                                                                                                 170),
                                                                                               v197));
            }
            while ( v194 >= 0 );
            v200 = &v6->m_transformB.m_storage->m_rotation.m_col0.m_quad;
            v201 = (signed __int64)(v9 + 56);
            v202 = 3i64;
            v203 = *v200;
            v204 = v200[1];
            v205 = v200[2];
            v206 = (__m128 *)(v9 + 56);
            do
            {
              v207 = *v206;
              --v206;
              --v202;
              *(__m128 *)((char *)v206 + (char *)&baseB.m_translation - (char *)v9 - 96) = _mm_add_ps(
                                                                                             _mm_add_ps(
                                                                                               _mm_mul_ps(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v207,
                                                                                                   v207,
                                                                                                   85),
                                                                                                 v204),
                                                                                               _mm_mul_ps(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v207,
                                                                                                   v207,
                                                                                                   0),
                                                                                                 v203)),
                                                                                             _mm_mul_ps(
                                                                                               _mm_shuffle_ps(
                                                                                                 v207,
                                                                                                 v207,
                                                                                                 170),
                                                                                               v205));
            }
            while ( v202 >= 0 );
            v9 += 56;
            v789 = (hkpConstraintAtom *)v201;
            goto LABEL_237;
          case 5u:
            buildSchemaFromBallSocketAtom(
              (hkpBallSocketConstraintAtom *)v9,
              v6,
              &baseA,
              &baseB,
              &vLocalArmA,
              &vLocalArmB,
              &maxAngularImpulse,
              &maxLinearImpulse,
              v7);
            goto LABEL_16;
          case 6u:
            v208 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v209 = _mm_mul_ps(v11, v11);
            v210 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v209, v209, 85), _mm_shuffle_ps(v209, v209, 0)),
                     _mm_shuffle_ps(v209, v209, 170));
            v211 = _mm_rsqrt_ps(v210);
            v978 = v210;
            v212 = _mm_mul_ps(v14, v14);
            v992 = _mm_andnot_ps(
                     _mm_cmpleps(v210, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v211, v210), v211)),
                         _mm_mul_ps(v211, *(__m128 *)_xmm)),
                       v210));
            v213 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v212, v212, 85), _mm_shuffle_ps(v212, v212, 0)),
                     _mm_shuffle_ps(v212, v212, 170));
            v214 = _mm_rsqrt_ps(v213);
            v994 = v213;
            v215 = _mm_cmpleps(v213, (__m128)0i64);
            v216 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v214, v213), v214)),
                     _mm_mul_ps(v214, *(__m128 *)_xmm));
            v217 = _mm_rcp_ps(v992);
            v218 = _mm_mul_ps(v216, v213);
            v219 = _mm_cmpltps(*(__m128 *)&epsilon, v992);
            v891 = _mm_andnot_ps(v215, v218);
            v220 = _mm_cmpltps(*(__m128 *)&epsilon, v891);
            v221 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v217, v992)), v217);
            v222 = _mm_rcp_ps(v891);
            v996 = v221;
            v223 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v222, v891)), v222);
            v998 = v223;
            v224 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v221, v11), v219), _mm_andnot_ps(v219, transform.m_quad));
            v225 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v223, v14), v220), _mm_andnot_ps(v220, transform.m_quad));
            v208[1] = _mm_shuffle_ps(v224, _mm_unpackhi_ps(v224, v992), 196);
            v208[2] = _mm_shuffle_ps(v225, _mm_unpackhi_ps(v225, v891), 196);
            v226 = *v208;
            v208 += 3;
            v9 += 6;
            v227 = _mm_shuffle_ps(
                     v226,
                     _mm_unpackhi_ps(
                       v226,
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           (__m128)LODWORD(v6->m_subStepInvDeltaTime.m_storage),
                           (__m128)LODWORD(v6->m_subStepInvDeltaTime.m_storage),
                           0),
                         _mm_shuffle_ps((__m128)LODWORD(v6->m_tau.m_storage), (__m128)LODWORD(v6->m_tau.m_storage), 0))),
                     196);
            v208[-3] = v227;
            v228 = _mm_shuffle_ps(
                     _mm_unpacklo_ps(
                       v227,
                       _mm_shuffle_ps((__m128)*((unsigned int *)v9 - 2), (__m128)*((unsigned int *)v9 - 2), 0)),
                     v227,
                     228);
            v208[-3] = _mm_shuffle_ps(
                         v228,
                         _mm_unpackhi_ps(
                           v228,
                           _mm_shuffle_ps((__m128)*((unsigned int *)v9 - 1), (__m128)*((unsigned int *)v9 - 1), 0)),
                         180);
            v208[-3].m128_f32[0] = v208[-3].m128_f32[0] + 0.00000011920929;
            v208[-3].m128_i8[0] = 18;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v208;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            goto LABEL_236;
          case 7u:
            info.m_pivotA = baseA.m_translation;
            info.m_pivotB = baseB.m_translation;
            info.m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseB.m_rotation.m_col0 + *((unsigned __int8 *)v9 + 2));
            hk1dLinearBilateralConstraintBuildJacobian(&info, v6, v7);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v8 = v790;
            v9 += 8;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            goto LABEL_236;
          case 8u:
            v906.m_pivotA = baseA.m_translation;
            v906.m_pivotB = baseB.m_translation;
            v906.m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseB.m_rotation.m_col0 + *((unsigned __int8 *)v9 + 2));
            v906.m_tau.m_storage = *((float *)v9 + 1);
            v906.m_damping.m_storage = *((float *)v9 + 2);
            hk1dLinearBilateralConstraintUserTauBuildJacobian(&v906, v6, v7);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v8 = v790;
            v9 += 8;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            goto LABEL_236;
          case 9u:
            v907.m_pivotA = baseA.m_translation;
            v907.m_pivotB = baseB.m_translation;
            v907.m_min.m_storage = *((float *)v9 + 1);
            v907.m_max.m_storage = *((float *)v9 + 2);
            v907.m_constrainedDofW = (hkVector4f)*((_OWORD *)&baseB.m_rotation.m_col0 + *((unsigned __int8 *)v9 + 2));
            hk1dLinearLimitBuildJacobian(&v907, v6, v7);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v8 = v790;
            v9 += 8;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            goto LABEL_236;
          case 0xAu:
            if ( *((_BYTE *)v9 + 2) && *((float *)v9 + 1) > 0.0 )
            {
              v873.m_quad = (__m128)baseA.m_translation;
              v874 = *(&baseB.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3));
              v875 = *((float *)v9 + 1);
              v876 = v7->m_constraintRuntime.m_storage;
              v229 = (__m128 *)v6->m_bodyB.m_storage;
              v230 = v6->m_bodyA.m_storage;
              sizeOfAllAtomsm = LODWORD(v6->m_virtMassFactor.m_storage);
              v231 = (__m128 *)v7->m_jacobianSchemas.m_storage;
              *v231 = v874;
              v232 = _mm_sub_ps(v873.m_quad, v229[7]);
              v233 = _mm_shuffle_ps(v874, v874, 201);
              v234 = _mm_sub_ps(v873.m_quad, v230->m_scratch3.m_quad);
              v235 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v232, v232, 201), v874), _mm_mul_ps(v232, v233));
              v236 = _mm_shuffle_ps(v235, v235, 201);
              v237 = _mm_sub_ps(_mm_mul_ps(v234, v233), _mm_mul_ps(_mm_shuffle_ps(v234, v234, 201), v874));
              v238 = _mm_shuffle_ps(v237, v237, 201);
              v231[1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v238, v238, 85), v230->m_scratch1.m_quad),
                            _mm_mul_ps(_mm_shuffle_ps(v238, v238, 0), v230->m_scratch0.m_quad)),
                          _mm_mul_ps(_mm_shuffle_ps(v238, v238, 170), v230->m_scratch2.m_quad));
              v239 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v236, v236, 85), v229[5]),
                         _mm_mul_ps(_mm_shuffle_ps(v236, v236, 0), v229[4])),
                       _mm_mul_ps(_mm_shuffle_ps(v236, v236, 170), v229[6]));
              v231[2] = v239;
              v240 = v230->m_invMasses.m_quad;
              v241 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v231[1], v231[1]), v240),
                       _mm_mul_ps(_mm_mul_ps(v239, v239), v229[3]));
              v242 = _mm_shuffle_ps(
                       v241,
                       _mm_unpackhi_ps(v241, _mm_max_ps(_mm_add_ps(v240, v229[3]), (__m128)xmmword_141A712D0)),
                       196);
              v243 = _mm_add_ps(_mm_shuffle_ps(v242, v242, 78), v242);
              v893 = _mm_add_ps(_mm_shuffle_ps(v243, v243, 177), v243);
              v231[2] = _mm_shuffle_ps(v231[2], _mm_unpackhi_ps(v231[2], v893), 196);
              v244 = _mm_rcp_ps(v893);
              v9 += 8;
              v1000 = _mm_mul_ps(
                        _mm_shuffle_ps((__m128)sizeOfAllAtomsm, (__m128)sizeOfAllAtomsm, 0),
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v244, v893)), v244));
              v231[1] = _mm_shuffle_ps(v231[1], _mm_unpackhi_ps(v231[1], v1000), 196);
              *v231 = _mm_shuffle_ps(
                        *v231,
                        _mm_unpackhi_ps(
                          *v231,
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(v6->m_rhsFactor.m_storage),
                              (__m128)LODWORD(v6->m_rhsFactor.m_storage),
                              0),
                            _mm_shuffle_ps((__m128)*((unsigned int *)v876 + 1), (__m128)*((unsigned int *)v876 + 1), 0))),
                        196);
              v245 = (float *)v7->m_jacobianSchemas.m_storage;
              v7->m_jacobianSchemas.m_storage += 64;
              v245[12] = v875 * v6->m_microStepDeltaTime.m_storage;
              *v245 = *v245 + 0.00000011920929;
              *(_BYTE *)v245 = 9;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 16);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
            }
            else
            {
              v9 += 8;
              v246 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v246 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v246 - 16) = 3;
              *(_BYTE *)(v246 - 12) = 2;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v246;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 16);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
            }
            goto LABEL_236;
          case 0xBu:
            if ( *((_BYTE *)v9 + 2) && *((_QWORD *)v9 + 2) )
            {
              v247 = (char *)v7->m_constraintRuntime.m_storage + (signed __int16)v9[2];
              v248 = (hkpSimpleContactConstraintAtom *)((char *)v7->m_constraintRuntime.m_storage + (signed __int16)v9[3]);
              maxAngularImpulse.m_real.m128_u64[0] = *((_QWORD *)v9 + 2);
              v249 = *v247 == 0;
              v803.m128_u64[0] = (unsigned __int64)v247;
              atoma = v248;
              if ( v249 )
                *(_DWORD *)&v248->m_type.m_storage = *((_DWORD *)v9 + 2);
              v250 = (hkp1Lin2AngJacobian *)v7->m_jacobianSchemas.m_storage;
              v846 = 0i64;
              hk1dLinearVelocityMotorBeginJacobian(
                &baseB.m_rotation.m_col0 + *((unsigned __int8 *)v9 + 3),
                &baseA.m_translation,
                v6,
                v250,
                &statusOut);
              v251 = (__int64 *)v1058->m_constraintRuntime.m_storage;
              v845 = v6;
              v846 = *v251;
              v847 = *((float *)v9 + 2) - *(float *)&atoma->m_type.m_storage;
              v252 = _mm_mul_ps(
                       _mm_sub_ps(baseA.m_translation.m_quad, baseB.m_translation.m_quad),
                       *(&baseB.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3)));
              v848 = *(float *)&atoma->m_type.m_storage
                   - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v252, v252, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v252, v252, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v252, v252, 170)));
              hkCalcMotorData(
                (hkpConstraintMotor *)maxAngularImpulse.m_real.m128_u64[0],
                (hkpConstraintMotorInput *)&statusOut,
                &output);
              hk1dLinearVelocityMotorCommitJacobian(
                (hkp1dConstraintMotorInfo *)&output.m_targetPosition,
                v6,
                v250,
                v1058);
              v253 = (_BYTE *)v803.m128_u64[0];
              v254 = *((float *)v9 + 2);
              if ( v254 != *(float *)&atoma->m_type.m_storage || !*(_BYTE *)v803.m128_u64[0] )
              {
                *(float *)&atoma->m_type.m_storage = v254;
                *v253 = 1;
              }
              v7 = v1058;
              v8 = v790;
              v9 += 12;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 16);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
            }
            else
            {
              v9 += 12;
              v255 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v255 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v255 - 16) = 3;
              *(_BYTE *)(v255 - 12) = 2;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v255;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 16);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
            }
            goto LABEL_236;
          case 0xCu:
            v256 = *((unsigned __int8 *)v9 + 2);
            v257 = (unsigned __int8)modulo3Table[v256 + 2];
            v258 = (unsigned __int8)modulo3Table[v256 + 1];
            v259 = (unsigned __int8)modulo3Table[v256 + 2];
            v881.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA.m_rotation.m_col0 + v256);
            v260 = (unsigned int)v258;
            v881.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v258);
            v881.m_constrainedDofW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v257);
            hk1dAngularBilateralConstraintBuildJacobian(&v881, v6, v1058);
            v261.m_quad = *(__m128 *)((char *)&baseB.m_rotation.m_col0 + v259);
            v7 = v1058;
            v881.m_perpZeroErrorAxisBinW = (hkVector4f)v261.m_quad;
            v881.m_constrainedDofW.m_quad = _mm_xor_ps(
                                              (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                              *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v260));
            hk1dAngularBilateralConstraintBuildJacobian(&v881, v6, v1058);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 16);
            v8 = v790;
            v9 = &v789[8].m_type.m_storage;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
            goto LABEL_236;
          case 0xDu:
            v262 = *((_BYTE *)v9 + 3);
            atomb = (hkpSimpleContactConstraintAtom *)((char *)v9 + 3);
            if ( v262 == 2 )
            {
              v882 = 12;
              v272 = (const unsigned __int8)modulo3Table[*((unsigned __int8 *)v9 + 2) + 2] >> 4;
              v273 = v272;
              v883 = (const unsigned __int8)modulo3Table[*((unsigned __int8 *)v9 + 2) + 2] >> 4;
              v274 = (unsigned __int8)modulo3Table[v272 + 2];
              v275 = (unsigned __int8)modulo3Table[v273 + 1];
              v276 = (unsigned int)v274;
              v880.m_zeroErrorAxisAinW = (hkVector4f)*((_OWORD *)&baseA.m_rotation.m_col0 + v273);
              v277 = (unsigned int)v275;
              v880.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v275);
              v880.m_constrainedDofW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v274);
              hk1dAngularBilateralConstraintBuildJacobian(&v880, v6, v1058);
              v278.m_quad = *(__m128 *)((char *)&baseB.m_rotation.m_col0 + v276);
              v7 = v1058;
              v880.m_perpZeroErrorAxisBinW = (hkVector4f)v278.m_quad;
              v880.m_constrainedDofW.m_quad = _mm_xor_ps(
                                                (__m128)_mm_shuffle_epi32(
                                                          _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                          0),
                                                *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v277));
              hk1dAngularBilateralConstraintBuildJacobian(&v880, v6, v1058);
              v9 = &v789->m_type.m_storage;
            }
            else
            {
              sizeOfAllAtomsa = *((unsigned __int8 *)v9 + 2);
              if ( sizeOfAllAtomsa >= sizeOfAllAtomsa + v262 )
                goto LABEL_80;
              v263 = &modulo3Table[*((unsigned __int8 *)v9 + 2) + 1];
              do
              {
                v264 = *((unsigned __int8 *)v263 - 1);
                maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)(v263 + 1);
                v265.m_quad = *(__m128 *)((char *)&baseA.m_rotation.m_col0 + v264);
                v266 = *(unsigned __int8 *)v263;
                v930.m_constrainedDofW = (hkVector4f)v265.m_quad;
                v267.m_quad = *(__m128 *)((char *)&baseA.m_rotation.m_col0 + v266);
                v268 = *((unsigned __int8 *)v263 + 1);
                v930.m_zeroErrorAxisAinW = (hkVector4f)v267.m_quad;
                v930.m_perpZeroErrorAxisBinW = *(hkVector4f *)((char *)&baseB.m_rotation.m_col0 + v268);
                hk1dAngularBilateralConstraintBuildJacobian(&v930, v6, v7);
                v269 = *((unsigned __int8 *)v9 + 2) + LOBYTE(atomb->m_type.m_storage);
                v271 = __OFSUB__(++sizeOfAllAtomsa, v269);
                v270 = sizeOfAllAtomsa - v269 < 0;
                v263 = (const char *)maxAngularImpulse.m_real.m128_u64[0];
              }
              while ( v270 ^ v271 );
            }
            v8 = v790;
LABEL_80:
            v9 += 8;
            v279 = 8i64 * LOBYTE(atomb->m_type.m_storage);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + v279);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + v279;
            goto LABEL_236;
          case 0xEu:
            if ( *((_BYTE *)v9 + 2) )
            {
              v280 = (unsigned __int8)modulo3Table[*((unsigned __int8 *)v9 + 3) + 2];
              v281 = (unsigned __int8)modulo3Table[*((unsigned __int8 *)v9 + 3) + 1];
              v282 = 2i64 * *((unsigned __int8 *)v9 + 3);
              v799 = v6->m_tau.m_storage * *((float *)v9 + 3);
              v283 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v280);
              v284 = *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + v281);
              v285 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v282);
              v286 = _mm_mul_ps(*(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v280), v284);
              v795 = *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v282);
              v796 = *((float *)v9 + 1);
              v797 = *((_DWORD *)v9 + 2);
              v1002 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v286, v286, 85), _mm_shuffle_ps(v286, v286, 0)),
                        _mm_shuffle_ps(v286, v286, 170));
              v287 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v285, v285, 201), v283),
                       _mm_mul_ps(_mm_shuffle_ps(v283, v283, 201), v285));
              v288 = _mm_mul_ps(_mm_shuffle_ps(v287, v287, 201), v284);
              v289 = _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v288, v288, 85), _mm_shuffle_ps(v288, v288, 0)),
                         _mm_shuffle_ps(v288, v288, 170)));
              v290 = _mm_cmpleps((__m128)0i64, v289);
              v291 = _mm_mul_ps(v289, v1002);
              v292 = _mm_or_ps(
                       _mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v291),
                       _mm_cmpltps(*(__m128 *)_xmm, v291));
              v293 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v291), v292), _mm_andnot_ps(v292, v291));
              v294 = _mm_mul_ps(v293, v293);
              v295 = _mm_mul_ps(
                       _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_rcp_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_rcp_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v294, *(__m128 *)s0)), *(__m128 *)t0),
                                       _mm_add_ps(v294, *(__m128 *)s1))),
                                   *(__m128 *)t1),
                                 _mm_add_ps(v294, *(__m128 *)s2))),
                             *(__m128 *)t2),
                           _mm_add_ps(v294, *(__m128 *)s3))),
                       _mm_mul_ps(v293, *(__m128 *)t3));
              v296 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
              v289.m128_i32[0] = *((_DWORD *)v7->m_constraintRuntime.m_storage + 1);
              v1004 = xmmword_141A713F0;
              v1006 = v296;
              v297 = _mm_or_ps(
                       _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v293, *(__m128 *)_xmm), *(__m128 *)_xmm), v295), v292),
                       _mm_andnot_ps(v292, v295));
              v298 = _mm_add_ps(_mm_or_ps(_mm_and_ps(v1002, *(__m128 *)_xmm), *(__m128 *)_xmm), v297);
              v299 = _mm_and_ps(v297, v290);
              v300 = _mm_andnot_ps(v290, v298);
              v301 = 0i64;
              v302 = _mm_or_ps(v300, v299);
              v303 = _mm_sub_ps(
                       v302,
                       _mm_shuffle_ps(
                         (__m128)COERCE_UNSIGNED_INT(v289.m128_f32[0] * -1.0),
                         (__m128)COERCE_UNSIGNED_INT(v289.m128_f32[0] * -1.0),
                         0));
              do
              {
                v304 = (__m128i)_mm_mul_ps(_mm_add_ps(v303, (__m128)xmmword_141A713B0), v296);
                v305 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v304, 1u), 1u));
                v306 = _mm_sub_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_sub_ps((__m128)v304, *(__m128 *)two23), *(__m128 *)two23),
                           *(__m128 *)two23),
                         *(__m128 *)two23);
                v1008 = _mm_or_ps(
                          _mm_andnot_ps(
                            v305,
                            _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v304, v306)), v306)),
                          _mm_and_ps(v305, (__m128)v304));
                v301 = _mm_add_ps(v301, v1008);
                v303 = _mm_sub_ps(v303, _mm_mul_ps(v1008, (__m128)xmmword_141A713F0));
                v307 = _mm_cmpltps(v303, (__m128)xmmword_141A713B0);
              }
              while ( fmax(
                        0.0 - 3.1415927,
                        COERCE_FLOAT(v307.m128_i32[0] & v303.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                                    v307,
                                                                                                    (__m128)xmmword_141A713B0))) != v303.m128_f32[0] );
              v21 = _xmm[0];
              v308 = 0;
              v9 += 8;
              v798 = v302.m128_f32[0] - (float)(v301.m128_f32[0] * 6.2831855);
            }
            else
            {
              v308 = 1;
              v9 += 8;
            }
            goto LABEL_94;
          case 0xFu:
            v340 = *((unsigned __int8 *)v9 + 3);
            v819 = 619091349;
            v795 = *(&baseA.m_rotation.m_col0.m_quad + v340);
            v796 = *((float *)v9 + 2);
            v797 = *((_DWORD *)v9 + 3);
            v341 = 2i64 * *((unsigned __int8 *)v9 + 3);
            v342 = 2i64 * *((unsigned __int8 *)v9 + 4);
            v343 = _mm_add_ps(
                     *(&baseA.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3)),
                     *(&baseB.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3)));
            v344 = _mm_mul_ps(v343, v343);
            v345 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v344, v344, 85), _mm_shuffle_ps(v344, v344, 0)),
                     _mm_shuffle_ps(v344, v344, 170));
            v346 = _mm_rsqrt_ps(v345);
            v1017 = v345;
            v347 = _mm_andnot_ps(
                     _mm_cmpleps(v345, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v346, v345), v346)),
                         _mm_mul_ps(*(__m128 *)_xmm, v346)),
                       v345));
            v1018 = v347;
            if ( v347.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0)) )
            {
              v351 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v341);
              v349 = 0.0;
            }
            else
            {
              v348 = _mm_rcp_ps(v347);
              v817 = 0.5 * v347.m128_f32[0];
              v349 = 0.5 * v347.m128_f32[0];
              v350 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v348, v347)), v348);
              v351 = _mm_mul_ps(v343, v350);
              v1010 = v350;
            }
            v980 = v351;
            v352 = _mm_shuffle_ps(v351, v351, 201);
            v353 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v342),
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v342),
                         201),
                       v351),
                     _mm_mul_ps(v352, *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v342)));
            v981 = _mm_shuffle_ps(v353, v353, 201);
            v354 = _mm_sub_ps(_mm_mul_ps(v981, v352), _mm_mul_ps(_mm_shuffle_ps(v981, v981, 201), v351));
            v355 = _mm_shuffle_ps(v354, v354, 201);
            v982 = v355;
            v356 = _mm_mul_ps(v981, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v342));
            v935 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v356, v356, 85), _mm_shuffle_ps(v356, v356, 0)),
                     _mm_shuffle_ps(v356, v356, 170));
            v357 = _mm_mul_ps(v355, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v342));
            v358 = _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v357, v357, 85), _mm_shuffle_ps(v357, v357, 0)),
                       _mm_shuffle_ps(v357, v357, 170)));
            v359 = _mm_cmpleps((__m128)0i64, v358);
            v360 = _mm_mul_ps(v358, v935);
            v361 = _mm_or_ps(
                     _mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v360),
                     _mm_cmpltps(*(__m128 *)_xmm, v360));
            v362 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v360), v361), _mm_andnot_ps(v361, v360));
            v363 = _mm_mul_ps(v362, v362);
            v364 = _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v363, *(__m128 *)s0)), *(__m128 *)t0),
                                     _mm_add_ps(v363, *(__m128 *)s1))),
                                 *(__m128 *)t1),
                               _mm_add_ps(v363, *(__m128 *)s2))),
                           *(__m128 *)t2),
                         _mm_add_ps(v363, *(__m128 *)s3))),
                     _mm_mul_ps(v362, *(__m128 *)t3));
            v795 = v351;
            v21 = _xmm[0];
            v365 = _mm_or_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v362, *(__m128 *)_xmm), *(__m128 *)_xmm), v364), v361),
                     _mm_andnot_ps(v361, v364));
            v9 += 16;
            v789 = (hkpConstraintAtom *)v9;
            LODWORD(v798) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                     v359,
                                                     _mm_add_ps(
                                                       _mm_or_ps(_mm_and_ps(v935, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                       v365)) | v365.m128_i32[0] & v359.m128_i32[0];
            v799 = (float)((float)(v6->m_tau.m_storage * *((float *)v9 - 4)) * v349) * v349;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            goto $doAngularLimit;
          case 0x10u:
            v309 = 2i64 * *((unsigned __int8 *)v9 + 3);
            v310 = 2i64 * *((unsigned __int8 *)v9 + 4);
            v311 = *(&baseA.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3));
            v312 = *(&baseB.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 4));
            v313 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v312, v312, 201), v311),
                     _mm_mul_ps(_mm_shuffle_ps(v311, v311, 201), v312));
            v314 = _mm_shuffle_ps(v313, v313, 201);
            v315 = _mm_mul_ps(v314, v314);
            v316 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v315, v315, 85), _mm_shuffle_ps(v315, v315, 0)),
                     _mm_shuffle_ps(v315, v315, 170));
            v1013 = v316;
            if ( v316.m128_f32[0] >= 0.00000011920929 )
            {
              v317 = _mm_rsqrt_ps(v316);
              v932 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v317, v316), v317)),
                         _mm_mul_ps(*(__m128 *)_xmm, v317)),
                       v316);
              v318 = _mm_mul_ps(
                       *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v310),
                       *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v309));
              v319 = _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v318, v318, 85), _mm_shuffle_ps(v318, v318, 0)),
                         _mm_shuffle_ps(v318, v318, 170)));
              v320 = _mm_cmpleps((__m128)0i64, v319);
              v321 = _mm_mul_ps(v319, v932);
              v322 = _mm_or_ps(
                       _mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v321),
                       _mm_cmpltps(*(__m128 *)_xmm, v321));
              v323 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v321), v322), _mm_andnot_ps(v322, v321));
              v324 = _mm_mul_ps(v323, v323);
              v325 = *(__m128i *)&hkVector4fComparison_maskToComparison_465[4 * (*((_BYTE *)v9 + 5) != 0 ? 0xF : 0)];
              v326 = _mm_mul_ps(
                       _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_rcp_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_rcp_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v324, *(__m128 *)s0)), *(__m128 *)t0),
                                       _mm_add_ps(v324, *(__m128 *)s1))),
                                   *(__m128 *)t1),
                                 _mm_add_ps(v324, *(__m128 *)s2))),
                             *(__m128 *)t2),
                           _mm_add_ps(v324, *(__m128 *)s3))),
                       _mm_mul_ps(v323, *(__m128 *)t3));
              v327 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v325, 0x1Fu), 0x1Fu);
              v328 = _mm_or_ps(
                       _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v323, *(__m128 *)_xmm), *(__m128 *)_xmm), v326), v322),
                       _mm_andnot_ps(v322, v326));
              v308 = 0;
              v329 = _mm_xor_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v320,
                           _mm_add_ps(_mm_or_ps(_mm_and_ps(v932, *(__m128 *)_xmm), *(__m128 *)_xmm), v328)),
                         _mm_and_ps(v328, v320)),
                       v327);
              v326.m128_i32[0] = COERCE_UNSIGNED_INT(v329.m128_f32[0] + 1.5707964) & v325.m128i_i32[0];
              v325.m128i_i32[0] = (unsigned __int128)_mm_andnot_ps((__m128)v325, v329);
              v329.m128_f32[0] = v6->m_tau.m_storage * *((float *)v9 + 4);
              LODWORD(v798) = v326.m128_i32[0] | v325.m128i_i32[0];
              v799 = v329.m128_f32[0];
              v21 = _xmm[0];
              v795 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v317, v316), v317)),
                           _mm_mul_ps(*(__m128 *)_xmm, v317)),
                         v314),
                       _mm_xor_ps(v327, g_vectorfConstants[0]));
              v796 = *((float *)v9 + 2);
              v797 = *((_DWORD *)v9 + 3);
              LOBYTE(v330) = *((_BYTE *)v9 + 6);
              if ( (unsigned __int8)v330 > 1u )
              {
                v331 = v7->m_constraintRuntime.m_storage;
                v330 = (unsigned __int8)v330;
                v332 = *(float *)((char *)v331 + (unsigned __int8)v330);
                v333 = v798 - v332;
                v334 = *((_DWORD *)v331 + 1) ^ _xmm[0];
                v335 = *(float *)&v334 - (float)(v798 - v332);
                atomj = v6->m_frameDeltaTime.m_storage * 0.5;
                sizeOfAllAtomsn = v332 * 0.050000001;
                v336 = fmaxf(v332 * 0.050000001, atomj);
                v337 = v332 - v336;
                v338 = v333 + v336;
                if ( COERCE_FLOAT(LODWORD(v335) ^ _xmm[0]) > (float)((float)((float)(v336 * 2.0) + atomj) * 0.5)
                  && *(float *)&v334 != 0.0 )
                {
                  v337 = v337 - v335;
                  v338 = v338 + v335;
                }
                sizeOfAllAtomso = LODWORD(v337);
                v1057 = 872415232;
                *(float *)((char *)v331 + v330) = fmaxf(v337, 0.00000011920929);
                v798 = v338;
              }
            }
            else
            {
              v308 = 1;
            }
            v9 += 16;
LABEL_94:
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            v789 = (hkpConstraintAtom *)v9;
            if ( v308 )
            {
              v339 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v339 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v339 - 16) = 3;
              *(_BYTE *)(v339 - 12) = 1;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v339;
            }
            else
            {
$doAngularLimit:
              v366 = v7->m_jacobianSchemas.m_storage;
              v367 = v799;
              v368 = (__m128 *)v6->m_bodyA.m_storage;
              v369 = (__m128 *)v6->m_bodyB.m_storage;
              sizeOfAllAtomsp = LODWORD(v799);
              v370 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v795);
              *(__m128 *)v366 = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v795, v795, 85), v368[5]),
                                    _mm_mul_ps(_mm_shuffle_ps(v795, v795, 0), v368[4])),
                                  _mm_mul_ps(_mm_shuffle_ps(v795, v795, 170), v368[6]));
              v371 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v370, v370, 85), v369[5]),
                         _mm_mul_ps(_mm_shuffle_ps(v370, v370, 0), v369[4])),
                       _mm_mul_ps(_mm_shuffle_ps(v370, v370, 170), v369[6]));
              *(__m128 *)&v366[16] = v371;
              v372 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(*(__m128 *)v366, *(__m128 *)v366), v368[3]),
                       _mm_mul_ps(_mm_mul_ps(v371, v371), v369[3]));
              v975 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v372, v372, 85), _mm_shuffle_ps(v372, v372, 0)),
                         _mm_shuffle_ps(v372, v372, 170)),
                       *(__m128 *)&epsilon);
              v373 = _mm_rcp_ps(v975);
              v937 = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)sizeOfAllAtomsp, (__m128)sizeOfAllAtomsp, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v373, v975)), v373));
              *(__m128 *)v366 = _mm_shuffle_ps(*(__m128 *)v366, _mm_unpackhi_ps(*(__m128 *)v366, v937), 196);
              v374 = v798;
              v375 = v796;
              v373.m128_i32[0] = v797;
              v371.m128_i32[0] = LODWORD(v6->m_subStepInvDeltaTime.m_storage);
              v7->m_jacobianSchemas.m_storage = v366 + 48;
              v371.m128_i32[0] ^= v21;
              *(float *)&v366[28] = v374 * v371.m128_f32[0];
              *(float *)&v366[32] = (float)(v375 * v371.m128_f32[0]) * v367;
              *(float *)&v366[36] = (float)(v373.m128_f32[0] * v371.m128_f32[0]) * v367;
              *(float *)&v366[40] = v367;
              *(float *)v366 = *(float *)v366 + 0.00000011920929;
              *v366 = (hkpJacobianSchema)13;
            }
            goto LABEL_237;
          case 0x11u:
            if ( *((_BYTE *)v9 + 2) && (v376 = *((float *)v9 + 2), v376 != 0.0) )
            {
              v377 = *((unsigned __int8 *)v9 + 4);
              v378 = v7->m_constraintRuntime.m_storage;
              v379 = v7->m_jacobianSchemas.m_storage;
              v380 = &baseA.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3);
              v381 = 0;
              atomc = (hkpSimpleContactConstraintAtom *)(v9 + 2);
              if ( v377 > 0 )
              {
                v808 = 1065353216;
                v382 = v378 - (struct hkpConstraintRuntime *)v380;
                v383 = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
                v384 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
                do
                {
                  v385 = *v380;
                  v386 = (__m128 *)v6->m_bodyA.m_storage;
                  v387 = (__m128 *)v6->m_bodyB.m_storage;
                  v388 = *v380;
                  v389 = *v380;
                  v379 += 48;
                  ++v380;
                  *(__m128 *)&v379[-48] = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v385, v385, 85), v386[5]),
                                              _mm_mul_ps(_mm_shuffle_ps(v388, v385, 0), v386[4])),
                                            _mm_mul_ps(_mm_shuffle_ps(v385, v385, 170), v386[6]));
                  v390 = _mm_xor_ps(v389, v384);
                  v391 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v390, v390, 85), v387[5]),
                             _mm_mul_ps(_mm_shuffle_ps(v390, v390, 0), v387[4])),
                           _mm_mul_ps(_mm_shuffle_ps(v390, v390, 170), v387[6]));
                  *(__m128 *)&v379[-32] = v391;
                  v392 = _mm_add_ps(
                           _mm_mul_ps(_mm_mul_ps(*(__m128 *)&v379[-48], *(__m128 *)&v379[-48]), v386[3]),
                           _mm_mul_ps(_mm_mul_ps(v391, v391), v387[3]));
                  v1001 = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v392, v392, 85), _mm_shuffle_ps(v392, v392, 0)),
                              _mm_shuffle_ps(v392, v392, 170)),
                            *(__m128 *)&epsilon);
                  v393 = _mm_rcp_ps(v1001);
                  v939 = _mm_mul_ps(v383, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v393, v1001)), v393));
                  *(__m128 *)&v379[-48] = _mm_shuffle_ps(
                                            *(__m128 *)&v379[-48],
                                            _mm_unpackhi_ps(*(__m128 *)&v379[-48], v939),
                                            196);
                  *(__m128 *)&v379[-32] = _mm_shuffle_ps(
                                            *(__m128 *)&v379[-32],
                                            _mm_unpackhi_ps(
                                              *(__m128 *)&v379[-32],
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  (__m128)*(unsigned int *)((char *)&v380->m128_u64[-1] + v382 - 4),
                                                  (__m128)*(unsigned int *)((char *)&v380->m128_u64[-1] + v382 - 4),
                                                  0),
                                                _mm_shuffle_ps(
                                                  (__m128)LODWORD(v6->m_rhsFactor.m_storage),
                                                  (__m128)LODWORD(v6->m_rhsFactor.m_storage),
                                                  0))),
                                            196);
                  *(float *)&v379[-16] = v376 * v6->m_microStepDeltaTime.m_storage;
                  *(float *)&v379[-48] = *(float *)&v379[-48] + 0.00000011920929;
                  v379[-48] = (hkpJacobianSchema)14;
                  *(_DWORD *)&v379[-12] = v381++;
                }
                while ( v381 < v377 );
              }
              v8 = v790;
              v7->m_jacobianSchemas.m_storage = v379;
            }
            else
            {
              atomc = (hkpSimpleContactConstraintAtom *)(v9 + 2);
              v394 = 2 * *((_BYTE *)v9 + 4);
              v395 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v395 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v395 - 16) = 3;
              *(_BYTE *)(v395 - 12) = v394;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v395;
            }
            v9 += 8;
            v396 = 16i64 * LOBYTE(atomc->m_type.m_storage);
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + v396);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + v396;
            goto LABEL_236;
          case 0x12u:
            if ( *((_QWORD *)v9 + 2) && *((_BYTE *)v9 + 2) )
            {
              v397 = (unsigned __int8)modulo3Table[*((unsigned __int8 *)v9 + 3) + 1];
              v398 = (unsigned __int8)modulo3Table[*((unsigned __int8 *)v9 + 3) + 2];
              v399 = (char *)v7->m_constraintRuntime.m_storage + (signed __int16)v9[2];
              v400 = (float *)((char *)v7->m_constraintRuntime.m_storage + (signed __int16)v9[3]);
              v401 = (hkpConstraintMotor *)*((_QWORD *)v9 + 2);
              v402 = _mm_mul_ps(
                       *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + v397),
                       *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v398));
              v403 = *((unsigned __int8 *)v9 + 3);
              atomd = (hkpSimpleContactConstraintAtom *)((char *)v7->m_constraintRuntime.m_storage
                                                       + (signed __int16)v9[2]);
              maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)v7->m_constraintRuntime.m_storage
                                                   + (signed __int16)v9[3];
              v977 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v402, v402, 85), _mm_shuffle_ps(v402, v402, 0)),
                       _mm_shuffle_ps(v402, v402, 170));
              v404 = _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           *(&baseB.m_rotation.m_col0.m_quad + v403),
                           *(&baseB.m_rotation.m_col0.m_quad + v403),
                           201),
                         *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v398)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v398),
                           *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + v398),
                           201),
                         *(&baseB.m_rotation.m_col0.m_quad + v403)));
              v405 = _mm_mul_ps(
                       _mm_shuffle_ps(v404, v404, 201),
                       *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + v397));
              v406 = _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v405, v405, 85), _mm_shuffle_ps(v405, v405, 0)),
                         _mm_shuffle_ps(v405, v405, 170)));
              v407 = _mm_mul_ps(v977, v406);
              v408 = _mm_cmpleps((__m128)0i64, v406);
              v409 = _mm_or_ps(
                       _mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v407),
                       _mm_cmpltps(*(__m128 *)_xmm, v407));
              v410 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v407), v409), _mm_andnot_ps(v409, v407));
              v411 = _mm_mul_ps(v410, v410);
              v412 = _mm_mul_ps(
                       _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_rcp_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_rcp_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v411, *(__m128 *)s0)), *(__m128 *)t0),
                                       _mm_add_ps(v411, *(__m128 *)s1))),
                                   *(__m128 *)t1),
                                 _mm_add_ps(v411, *(__m128 *)s2))),
                             *(__m128 *)t2),
                           _mm_add_ps(v411, *(__m128 *)s3))),
                       _mm_mul_ps(v410, *(__m128 *)t3));
              v413 = v9[4];
              v414 = _mm_or_ps(
                       _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v410, *(__m128 *)_xmm), *(__m128 *)_xmm), v412), v409),
                       _mm_andnot_ps(v409, v412));
              v415 = _mm_or_ps(
                       _mm_andnot_ps(
                         v408,
                         _mm_add_ps(_mm_or_ps(_mm_and_ps(v977, *(__m128 *)_xmm), *(__m128 *)_xmm), v414)),
                       _mm_and_ps(v414, v408));
              if ( v413 )
              {
                v416 = _mm_div_ps(query.m_quad, (__m128)xmmword_141A713F0);
                v417 = *(float *)((char *)v7->m_constraintRuntime.m_storage + v413 + 4);
                v941 = xmmword_141A713F0;
                v418 = 0i64;
                v1011 = v416;
                v419 = _mm_sub_ps(
                         v415,
                         _mm_shuffle_ps(
                           (__m128)COERCE_UNSIGNED_INT(v417 * -1.0),
                           (__m128)COERCE_UNSIGNED_INT(v417 * -1.0),
                           0));
                do
                {
                  v420 = (__m128i)_mm_mul_ps(_mm_add_ps(v419, (__m128)xmmword_141A713B0), v416);
                  v421 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v420, 1u), 1u));
                  v422 = _mm_sub_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_sub_ps((__m128)v420, *(__m128 *)two23), *(__m128 *)two23),
                             *(__m128 *)two23),
                           *(__m128 *)two23);
                  v943 = _mm_or_ps(
                           _mm_andnot_ps(
                             v421,
                             _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v420, v422)), v422)),
                           _mm_and_ps((__m128)v420, v421));
                  v418 = _mm_add_ps(v418, v943);
                  v419 = _mm_sub_ps(v419, _mm_mul_ps(v943, (__m128)xmmword_141A713F0));
                  v423 = _mm_cmpltps(v419, (__m128)xmmword_141A713B0);
                }
                while ( fmax(
                          0.0 - 3.1415927,
                          COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(v423, (__m128)xmmword_141A713B0) | v419.m128_i32[0] & v423.m128_i32[0])) != v419.m128_f32[0] );
                v21 = _xmm[0];
                v415.m128_f32[0] = v415.m128_f32[0] - (float)(v418.m128_f32[0] * 6.2831855);
              }
              v249 = *v399 == 0;
              v809 = v415.m128_i32[0];
              if ( v249 )
                *v400 = v415.m128_f32[0];
              input.m_lastResults = 0i64;
              v424 = (__m128 *)v6->m_bodyA.m_storage;
              v425 = (__m128 *)v6->m_bodyB.m_storage;
              v426 = (__m128 *)v7->m_jacobianSchemas.m_storage;
              v427 = *((unsigned __int8 *)v9 + 3);
              v810 = 1065353216;
              v428 = *(&baseA.m_rotation.m_col0.m_quad + v427);
              v429 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v428);
              *v426 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v428, v428, 85), v424[5]),
                          _mm_mul_ps(_mm_shuffle_ps(v428, v428, 0), v424[4])),
                        _mm_mul_ps(_mm_shuffle_ps(v428, v428, 170), v424[6]));
              v430 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v429, v429, 85), v425[5]),
                         _mm_mul_ps(_mm_shuffle_ps(v429, v429, 0), v425[4])),
                       _mm_mul_ps(_mm_shuffle_ps(v429, v429, 170), v425[6]));
              v431 = (__m128)v810;
              v426[1] = v430;
              v432 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v430, v430), v425[3]),
                       _mm_mul_ps(_mm_mul_ps(*v426, *v426), v424[3]));
              v979 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v432, v432, 85), _mm_shuffle_ps(v432, v432, 0)),
                         _mm_shuffle_ps(v432, v432, 170)),
                       *(__m128 *)&epsilon);
              v433 = _mm_rcp_ps(v979);
              v945 = _mm_mul_ps(
                       _mm_shuffle_ps(v431, v431, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v433, v979)), v433));
              *v426 = _mm_shuffle_ps(*v426, _mm_unpackhi_ps(*v426, v945), 196);
              input.m_effMass.m_storage = *((float *)&v426->m128_u64[1] + 1);
              v434 = (hkpSolverResults *)v1058->m_constraintRuntime.m_storage;
              input.m_stepInfo.m_storage = (hkpConstraintQueryStepInfo *)&v6->m_subStepDeltaTime;
              input.m_lastResults = *v434;
              input.m_deltaTarget.m_storage = *((float *)v9 + 3) - *v400;
              input.m_positionError.m_storage = *v400 - v415.m128_f32[0];
              hkCalcMotorData(v401, &input, &v842);
              v426[1].m128_f32[3] = v842.m_targetPosition.m_storage * v6->m_subStepInvDeltaTime.m_storage;
              v7 = v1058;
              v435 = (signed __int64)&v1058->m_jacobianSchemas.m_storage[64];
              *(float *)(v435 - 64) = *(float *)v1058->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v435 - 64) = 15;
              *(float *)(v435 - 32) = v842.m_maxForce.m_storage * v6->m_microStepDeltaTime.m_storage;
              *(float *)(v435 - 28) = v842.m_minForce.m_storage * v6->m_microStepDeltaTime.m_storage;
              *(float *)(v435 - 24) = v842.m_targetVelocity.m_storage;
              *(float *)(v435 - 20) = v842.m_tau.m_storage;
              v436 = v842.m_damping.m_storage;
              v1058->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v435;
              *(float *)(v435 - 16) = v436;
              v437 = *((float *)v9 + 3);
              if ( v437 != *(float *)maxAngularImpulse.m_real.m128_u64[0] || !LOBYTE(atomd->m_type.m_storage) )
              {
                *(float *)maxAngularImpulse.m_real.m128_u64[0] = v437;
                LOBYTE(atomd->m_type.m_storage) = 1;
              }
              v1058->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v1058->m_constraintRuntime.m_storage
                                                                                   + 16);
              v8 = v790;
              v9 += 20;
              v1058->m_constraintRuntimeInMainMemory.m_storage = (char *)v1058->m_constraintRuntimeInMainMemory.m_storage
                                                               + 16;
            }
            else
            {
              v9 += 20;
              v438 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v438 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v438 - 16) = 3;
              *(_BYTE *)(v438 - 12) = 2;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v438;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 16);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 16;
            }
            goto LABEL_236;
          case 0x13u:
            if ( *((_BYTE *)v9 + 2) )
            {
              v439 = (hkMatrix3f *)&v6->m_transformB.m_storage->m_rotation.m_col0;
              v800 = (char *)v7->m_constraintRuntime.m_storage + (signed __int16)v9[2];
              v813 = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage + (signed __int16)v9[3]);
              hkMatrix3f_setMulMat3Mat3(&THIS, v439, (hkMatrix3f *)(v9 + 8));
              v440 = v800;
              v441 = (hkpConstraintMotor **)(v9 + 32);
              v850.m_lastResults = 0i64;
              v850.m_stepInfo.m_storage = (hkpConstraintQueryStepInfo *)&v6->m_subStepDeltaTime;
              v839 = 0;
              v840 = 1;
              maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)(v9 + 32);
              v841 = 2;
              v837 = 1i64;
              v838 = 0;
              v442 = 0;
              sizeOfAllAtomsb = 0;
              v443 = 0i64;
              v803.m128_u64[0] = 0i64;
              v444 = 0i64;
              do
              {
                if ( *v441 )
                {
                  v445 = *v441;
                  v446 = *(signed int *)((char *)&v837 + v444);
                  v447 = 2i64 * *(int *)((char *)&v839 + v444);
                  v812 = 619091349;
                  v448 = 2 * v446;
                  v449 = _mm_add_ps(
                           *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v447),
                           *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v447));
                  v450 = _mm_mul_ps(v449, v449);
                  v451 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v450, v450, 85), _mm_shuffle_ps(v450, v450, 0)),
                           _mm_shuffle_ps(v450, v450, 170));
                  v452 = _mm_rsqrt_ps(v451);
                  v1003 = v451;
                  v453 = _mm_andnot_ps(
                           _mm_cmpleps(v451, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v452, v451), v452)),
                               _mm_mul_ps(*(__m128 *)_xmm, v452)),
                             v451));
                  v947 = v453;
                  if ( v453.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0)) )
                  {
                    v456 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v447);
                  }
                  else
                  {
                    v454 = _mm_rcp_ps(v453);
                    atomk = v453.m128_f32[0] * 0.5;
                    v455 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v454, v453)), v454);
                    v456 = _mm_mul_ps(v449, v455);
                    v983 = v455;
                  }
                  v984 = v456;
                  v457 = _mm_shuffle_ps(v456, v456, 201);
                  v458 = _mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm);
                  v459 = _mm_sub_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(
                               *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v448),
                               *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v448),
                               201),
                             v456),
                           _mm_mul_ps(v457, *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v448)));
                  v985 = _mm_shuffle_ps(v459, v459, 201);
                  v460 = _mm_sub_ps(_mm_mul_ps(v985, v457), _mm_mul_ps(_mm_shuffle_ps(v985, v985, 201), v456));
                  v461 = _mm_shuffle_ps(v460, v460, 201);
                  v986 = v461;
                  v462 = _mm_mul_ps(v985, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v448));
                  v463 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v462, v462, 85), _mm_shuffle_ps(v462, v462, 0)),
                           _mm_shuffle_ps(v462, v462, 170));
                  v949 = v463;
                  v464 = _mm_mul_ps(v461, *(__m128 *)((char *)&baseA.m_rotation.m_col0.m_quad + 8 * v448));
                  v465 = _mm_rcp_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v464, v464, 85), _mm_shuffle_ps(v464, v464, 0)),
                             _mm_shuffle_ps(v464, v464, 170)));
                  v466 = _mm_cmpleps((__m128)0i64, v465);
                  v467 = _mm_mul_ps(v465, v463);
                  v468 = _mm_or_ps(_mm_cmpltps(*(__m128 *)_xmm, v467), _mm_cmpnleps(v458, v467));
                  v469 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v467), v468), _mm_andnot_ps(v468, v467));
                  v470 = _mm_mul_ps(v469, v469);
                  v471 = _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_rcp_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v470, *(__m128 *)s0)), *(__m128 *)t0),
                                           _mm_add_ps(v470, *(__m128 *)s1))),
                                       *(__m128 *)t1),
                                     _mm_add_ps(v470, *(__m128 *)s2))),
                                 *(__m128 *)t2),
                               _mm_add_ps(v470, *(__m128 *)s3))),
                           _mm_mul_ps(v469, *(__m128 *)t3));
                  v818 = 619091349;
                  v472 = _mm_or_ps(
                           _mm_and_ps(
                             _mm_sub_ps(_mm_or_ps(_mm_and_ps(v469, *(__m128 *)_xmm), *(__m128 *)_xmm), v471),
                             v468),
                           _mm_andnot_ps(v468, v471));
                  v465.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                                          v466,
                                                          _mm_add_ps(
                                                            _mm_or_ps(
                                                              _mm_and_ps(v463, *(__m128 *)_xmm),
                                                              *(__m128 *)_xmm),
                                                            v472));
                  v473 = _mm_add_ps(
                           *(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v447),
                           *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v447));
                  LODWORD(v811) = v465.m128_i32[0] | v472.m128_i32[0] & v466.m128_i32[0];
                  v474 = _mm_mul_ps(v473, v473);
                  v475 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v474, v474, 85), _mm_shuffle_ps(v474, v474, 0)),
                           _mm_shuffle_ps(v474, v474, 170));
                  v476 = _mm_rsqrt_ps(v475);
                  v1012 = v475;
                  v477 = _mm_andnot_ps(
                           _mm_cmpleps(v475, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v476, v475), v476)),
                               _mm_mul_ps(v476, *(__m128 *)_xmm)),
                             v475));
                  v951 = v477;
                  if ( v477.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x24E69595u, (__m128)0x24E69595u, 0)) )
                  {
                    v480 = *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v447);
                  }
                  else
                  {
                    v478 = _mm_rcp_ps(v477);
                    atoml = v477.m128_f32[0] * 0.5;
                    v479 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v478, v477)), v478);
                    v480 = _mm_mul_ps(v473, v479);
                    v987 = v479;
                  }
                  v988 = v480;
                  v481 = _mm_shuffle_ps(v480, v480, 201);
                  v482 = _mm_sub_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(
                               *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v448),
                               *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v448),
                               201),
                             v480),
                           _mm_mul_ps(v481, *(__m128 *)((char *)&baseB.m_rotation.m_col0.m_quad + 8 * v448)));
                  v483 = _mm_shuffle_ps(v482, v482, 201);
                  v989 = v483;
                  v484 = _mm_sub_ps(_mm_mul_ps(v483, v481), _mm_mul_ps(v483, v480));
                  v990 = _mm_shuffle_ps(v484, v484, 201);
                  v485 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v448), v483);
                  v953 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v485, v485, 85), _mm_shuffle_ps(v485, v485, 0)),
                           _mm_shuffle_ps(v485, v485, 170));
                  v486 = _mm_mul_ps(*(__m128 *)((char *)&THIS.m_col0.m_quad + 8 * v448), v990);
                  v487 = _mm_rcp_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v486, v486, 85), _mm_shuffle_ps(v486, v486, 0)),
                             _mm_shuffle_ps(v486, v486, 170)));
                  v488 = _mm_cmpleps((__m128)0i64, v487);
                  v489 = _mm_mul_ps(v487, v953);
                  v490 = _mm_or_ps(_mm_cmpnleps(v458, v489), _mm_cmpltps(*(__m128 *)_xmm, v489));
                  v491 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v489), v490), _mm_andnot_ps(v490, v489));
                  v492 = _mm_mul_ps(v491, v491);
                  v493 = _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_rcp_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v492, *(__m128 *)s0)), *(__m128 *)t0),
                                           _mm_add_ps(v492, *(__m128 *)s1))),
                                       *(__m128 *)t1),
                                     _mm_add_ps(v492, *(__m128 *)s2))),
                                 *(__m128 *)t2),
                               _mm_add_ps(v492, *(__m128 *)s3))),
                           _mm_mul_ps(v491, *(__m128 *)t3));
                  v494 = _mm_or_ps(
                           _mm_and_ps(
                             _mm_sub_ps(_mm_or_ps(_mm_and_ps(v491, *(__m128 *)_xmm), *(__m128 *)_xmm), v493),
                             v490),
                           _mm_andnot_ps(v490, v493));
                  v249 = *v440 == 0;
                  v487.m128_i32[0] = *(unsigned __int128 *)&_mm_andnot_ps(
                                                              v488,
                                                              _mm_add_ps(
                                                                _mm_or_ps(
                                                                  _mm_and_ps(v953, *(__m128 *)_xmm),
                                                                  *(__m128 *)_xmm),
                                                                v494)) | v494.m128_i32[0] & v488.m128_i32[0];
                  v495 = v811;
                  v816 = v487.m128_f32[0];
                  if ( v249 )
                  {
                    *(float *)((char *)v813 + v444) = v811;
                    *v440 = 1;
                  }
                  v496 = (__m128 *)v6->m_bodyA.m_storage;
                  v497 = (__m128 *)v6->m_bodyB.m_storage;
                  v498 = (__m128 *)v7->m_jacobianSchemas.m_storage;
                  v499 = v816;
                  v500 = _mm_mul_ps(_mm_shuffle_ps(v480, v480, 85), v496[5]);
                  v806 = 1065353216;
                  v501 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v480);
                  *v498 = _mm_add_ps(
                            _mm_add_ps(v500, _mm_mul_ps(_mm_shuffle_ps(v480, v480, 0), v496[4])),
                            _mm_mul_ps(_mm_shuffle_ps(v480, v480, 170), v496[6]));
                  v502 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v501, v501, 85), v497[5]),
                             _mm_mul_ps(_mm_shuffle_ps(v501, v501, 0), v497[4])),
                           _mm_mul_ps(_mm_shuffle_ps(v501, v501, 170), v497[6]));
                  v498[1] = v502;
                  v503 = _mm_add_ps(
                           _mm_mul_ps(_mm_mul_ps(*v498, *v498), v496[3]),
                           _mm_mul_ps(_mm_mul_ps(v502, v502), v497[3]));
                  v1005 = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v503, v503, 85), _mm_shuffle_ps(v503, v503, 0)),
                              _mm_shuffle_ps(v503, v503, 170)),
                            *(__m128 *)&epsilon);
                  v504 = _mm_rcp_ps(v1005);
                  v955 = _mm_mul_ps(
                           _mm_shuffle_ps((__m128)v806, (__m128)v806, 0),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v504, v1005)), v504));
                  *v498 = _mm_shuffle_ps(*v498, _mm_unpackhi_ps(*v498, v955), 196);
                  v850.m_effMass.m_storage = *((float *)&v498->m128_u64[1] + 1);
                  v498[3].m128_i32[1] = v442;
                  v850.m_lastResults = *(hkpSolverResults *)((char *)v1058->m_constraintRuntime.m_storage + v443);
                  v850.m_deltaTarget.m_storage = v499 - *(float *)((char *)v813 + v444);
                  v850.m_positionError.m_storage = *(float *)((char *)v813 + v444) - v495;
                  hkCalcMotorData(v445, &v850, &v843);
                  v440 = v800;
                  v442 = sizeOfAllAtomsb;
                  v443 = v803.m128_u64[0];
                  v498[1].m128_f32[3] = v843.m_targetPosition.m_storage * v6->m_subStepInvDeltaTime.m_storage;
                  v7 = v1058;
                  v505 = (signed __int64)&v1058->m_jacobianSchemas.m_storage[64];
                  *(float *)(v505 - 64) = *(float *)v1058->m_jacobianSchemas.m_storage + 0.00000011920929;
                  *(_BYTE *)(v505 - 64) = 15;
                  *(float *)(v505 - 32) = v843.m_maxForce.m_storage * v6->m_microStepDeltaTime.m_storage;
                  *(float *)(v505 - 28) = v843.m_minForce.m_storage * v6->m_microStepDeltaTime.m_storage;
                  *(float *)(v505 - 24) = v843.m_targetVelocity.m_storage;
                  *(float *)(v505 - 20) = v843.m_tau.m_storage;
                  v506 = v843.m_damping.m_storage;
                  v1058->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v505;
                  *(float *)(v505 - 16) = v506;
                  if ( v499 != *(float *)((char *)v813 + v444) )
                    *(float *)((char *)v813 + v444) = v499;
                }
                else
                {
                  v507 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
                  *(float *)(v507 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
                  *(_BYTE *)(v507 - 16) = 3;
                  *(_BYTE *)(v507 - 12) = 2;
                  v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v507;
                }
                ++v442;
                ++v440;
                v443 += 16i64;
                v441 = (hkpConstraintMotor **)(maxAngularImpulse.m_real.m128_u64[0] + 8);
                v444 += 4i64;
                sizeOfAllAtomsb = v442;
                v800 = v440;
                maxAngularImpulse.m_real.m128_u64[0] += 8i64;
                v803.m128_u64[0] = v443;
              }
              while ( v442 < 3 );
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 48);
              v21 = _xmm[0];
              v8 = v790;
              v9 = &v789[48].m_type.m_storage;
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 48;
            }
            else
            {
              v9 += 48;
              v508 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v508 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v508 - 16) = 3;
              *(_BYTE *)(v508 - 12) = 6;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v508;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 48);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 48;
            }
            goto LABEL_236;
          case 0x14u:
            v509 = *((__m128 *)v9 + 1);
            v510 = *((__m128 *)v9 + 2);
            v511 = *((_DWORD *)v9 + 12);
            v512 = *((_DWORD *)v9 + 13);
            v513 = (__m128 *)v6->m_bodyA.m_storage;
            v514 = (__m128 *)v6->m_bodyB.m_storage;
            v515 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v516 = _mm_sub_ps(baseB.m_translation.m_quad, v510);
            v517 = _mm_sub_ps(*((__m128 *)v9 + 1), baseA.m_translation.m_quad);
            v518 = _mm_mul_ps(v517, v517);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v518, v518, 85))
                               + COERCE_FLOAT(_mm_shuffle_ps(v518, v518, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v518, v518, 170))) <= 0.00000011920929 )
            {
              v521 = transform.m_quad;
            }
            else
            {
              v519 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v518, v518, 85), _mm_shuffle_ps(v518, v518, 0)),
                       _mm_shuffle_ps(v518, v518, 170));
              v520 = _mm_rsqrt_ps(v519);
              v991 = v519;
              v521 = _mm_mul_ps(
                       v517,
                       _mm_andnot_ps(
                         _mm_cmpleps(v519, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v520, v519), v520)),
                           _mm_mul_ps(*(__m128 *)_xmm, v520))));
            }
            v855 = v521;
            v522 = _mm_mul_ps(v516, v516);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v522, v522, 85))
                               + COERCE_FLOAT(_mm_shuffle_ps(v522, v522, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v522, v522, 170))) <= 0.00000011920929 )
            {
              v525 = _mm_xor_ps((__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), transform.m_quad);
            }
            else
            {
              v523 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v522, v522, 85), _mm_shuffle_ps(v522, v522, 0)),
                       _mm_shuffle_ps(v522, v522, 170));
              v524 = _mm_rsqrt_ps(v523);
              v957 = v523;
              v525 = _mm_mul_ps(
                       v516,
                       _mm_andnot_ps(
                         _mm_cmpleps(v523, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v524, v523), v524)),
                           _mm_mul_ps(*(__m128 *)_xmm, v524))));
            }
            v856 = v525;
            v851 = v513;
            v852 = v514;
            v860 = v512;
            v859 = v511;
            v526 = _mm_shuffle_ps((__m128)v512, (__m128)v512, 0);
            v853.m_quad = (__m128)baseA.m_translation;
            v854.m_quad = (__m128)baseB.m_translation;
            v857 = v509;
            v858 = v510;
            v861 = LODWORD(v6->m_subStepInvDeltaTime.m_storage);
            v527 = _mm_mul_ps(v526, v525);
            v862 = LODWORD(v6->m_virtMassFactor.m_storage);
            *v515 = v521;
            v515[1] = v527;
            v528 = _mm_sub_ps(v853.m_quad, v851[7]);
            v529 = _mm_sub_ps(v854.m_quad, v852[7]);
            v530 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v529, v529, 201), v527),
                     _mm_mul_ps(_mm_shuffle_ps(v527, v527, 201), v529));
            v531 = _mm_shuffle_ps(v530, v530, 201);
            v532 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v855, v855, 201), v528),
                     _mm_mul_ps(_mm_shuffle_ps(v528, v528, 201), v855));
            v533 = _mm_shuffle_ps(v532, v532, 201);
            v515[2] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v533, v533, 85), v851[5]),
                          _mm_mul_ps(_mm_shuffle_ps(v533, v533, 0), v851[4])),
                        _mm_mul_ps(_mm_shuffle_ps(v533, v533, 170), v851[6]));
            v534 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v531, v531, 85), v852[5]),
                       _mm_mul_ps(_mm_shuffle_ps(v531, v531, 0), v852[4])),
                     _mm_mul_ps(_mm_shuffle_ps(v531, v531, 170), v852[6]));
            v515[3] = v534;
            v535 = _mm_add_ps(
                     _mm_mul_ps(_mm_mul_ps(v534, v534), v852[3]),
                     _mm_mul_ps(_mm_mul_ps(v515[2], v515[2]), v851[3]));
            v1016 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v852[3], v852[3], 255), _mm_mul_ps(v526, v526)),
                          _mm_shuffle_ps(v851[3], v851[3], 255)),
                        *(__m128 *)&epsilon),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v535, v535, 85), _mm_shuffle_ps(v535, v535, 0)),
                        _mm_shuffle_ps(v535, v535, 170)));
            v536 = _mm_rcp_ps(v1016);
            v959 = _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v536, v1016)), v536),
                     _mm_shuffle_ps((__m128)v862, (__m128)v862, 0));
            v515[2] = _mm_shuffle_ps(v515[2], _mm_unpackhi_ps(v515[2], v959), 196);
            v537 = _mm_sub_ps(v854.m_quad, v858);
            v538 = _mm_sub_ps(v857, v853.m_quad);
            v539 = _mm_mul_ps(v537, v537);
            v540 = _mm_mul_ps(v538, v538);
            v541 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v539, v539, 85), _mm_shuffle_ps(v539, v539, 0)),
                     _mm_shuffle_ps(v539, v539, 170));
            v542 = _mm_rsqrt_ps(v541);
            v993 = v541;
            v543 = _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v542, v541), v542)),
                       _mm_mul_ps(v542, *(__m128 *)_xmm)),
                     v541);
            v961 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v540, v540, 85), _mm_shuffle_ps(v540, v540, 0)),
                     _mm_shuffle_ps(v540, v540, 170));
            v544 = _mm_rsqrt_ps(v961);
            v9 += 32;
            *v515 = _mm_shuffle_ps(
                      *v515,
                      _mm_unpackhi_ps(
                        *v515,
                        _mm_mul_ps(
                          _mm_sub_ps(
                            _mm_add_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v961, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v544, v961), v544)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v544)),
                                  v961)),
                              _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v541, (__m128)0i64), v543), v526)),
                            _mm_shuffle_ps((__m128)v859, (__m128)v859, 0)),
                          _mm_shuffle_ps((__m128)v861, (__m128)v861, 0))),
                      196);
            v545 = (float *)v7->m_jacobianSchemas.m_storage;
            v546 = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
            v7->m_jacobianSchemas.m_storage += 64;
            *v545 = v546;
            *(_BYTE *)v545 = 11;
            goto LABEL_146;
          case 0x15u:
            v547 = v7->m_constraintRuntime.m_storage;
            v548 = 0i64;
            v549 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v550 = (float *)((char *)v547 + *((char *)v9 + 9));
            v551 = (float *)((char *)v547 + *((char *)v9 + 10));
            v552 = (unsigned int *)((char *)v547 + *((char *)v9 + 11));
            v7->m_jacobianSchemas.m_storage += 64;
            v553.m_quad = (__m128)baseA.m_translation;
            v554.m_quad = (__m128)baseB.m_translation;
            v555.m_quad = (__m128)baseA.m_rotation.m_col0;
            v556.m_quad = (__m128)baseB.m_rotation.m_col0;
            if ( *((_BYTE *)v9 + 8) )
            {
              v815 = 1036831949;
              v564 = _mm_mul_ps(baseB.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad);
              if ( COERCE_FLOAT((unsigned int)(2
                                             * COERCE_SIGNED_INT(
                                                 (float)(COERCE_FLOAT(_mm_shuffle_ps(v564, v564, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v564, v564, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v564, v564, 170)))) >> 1) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0)) )
              {
                v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v549;
                v9 += 8;
                goto LABEL_146;
              }
              v562.m_quad = (__m128)baseB.m_rotation.m_col1;
            }
            else
            {
              v557 = _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 201),
                         baseB.m_rotation.m_col0.m_quad),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 201),
                         baseA.m_rotation.m_col0.m_quad));
              v558 = _mm_shuffle_ps(v557, v557, 201);
              v559 = _mm_mul_ps(v558, v558);
              v560 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v559, v559, 85), _mm_shuffle_ps(v559, v559, 0)),
                       _mm_shuffle_ps(v559, v559, 170));
              v1007 = v560;
              if ( v560.m128_f32[0] < 1.4210855e-14 )
              {
                v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v549;
                v9 += 8;
                goto LABEL_146;
              }
              v561 = _mm_rsqrt_ps(v560);
              v548 = _mm_mul_ps(
                       v558,
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v561, v560), v561)),
                         _mm_mul_ps(*(__m128 *)_xmm, v561)));
              v562.m_quad = v548;
              v563 = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)*((unsigned int *)v9 + 1), (__m128)*((unsigned int *)v9 + 1), 0),
                       v548);
              v553.m_quad = _mm_add_ps(baseA.m_translation.m_quad, v563);
              v554.m_quad = _mm_add_ps(baseB.m_translation.m_quad, v563);
            }
            v565 = _mm_mul_ps(baseA.m_rotation.m_col1.m_quad, v562.m_quad);
            v566 = _mm_mul_ps(baseA.m_rotation.m_col2.m_quad, v562.m_quad);
            v963 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v565, v565, 0), _mm_shuffle_ps(v565, v565, 85)),
                     _mm_shuffle_ps(v565, v565, 170));
            v567 = _mm_rcp_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v566, v566, 85), _mm_shuffle_ps(v566, v566, 0)),
                       _mm_shuffle_ps(v566, v566, 170)));
            v568 = _mm_cmpleps((__m128)0i64, v567);
            v569 = _mm_mul_ps(v567, v963);
            v570 = _mm_or_ps(
                     _mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v569),
                     _mm_cmpltps(*(__m128 *)_xmm, v569));
            v571 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v569), v570), _mm_andnot_ps(v570, v569));
            v572 = _mm_mul_ps(v571, v571);
            v573 = _mm_sub_ps(v554.m_quad, v553.m_quad);
            v574 = _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_rcp_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_rcp_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v572, *(__m128 *)s0)), *(__m128 *)t0),
                                     _mm_add_ps(v572, *(__m128 *)s1))),
                                 *(__m128 *)t1),
                               _mm_add_ps(v572, *(__m128 *)s2))),
                           *(__m128 *)t2),
                         _mm_add_ps(v572, *(__m128 *)s3))),
                     _mm_mul_ps(v571, *(__m128 *)t3));
            v575 = _mm_mul_ps(v573, baseB.m_rotation.m_col0.m_quad);
            v576 = _mm_or_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v571, *(__m128 *)_xmm), *(__m128 *)_xmm), v574), v570),
                     _mm_andnot_ps(v570, v574));
            LODWORD(v814) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                     v568,
                                                     _mm_add_ps(
                                                       _mm_or_ps(_mm_and_ps(v963, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                       v576)) | v576.m128_i32[0] & v568.m128_i32[0];
            v577 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v575, v575, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v575, v575, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v575, v575, 170));
            v578 = v814;
            if ( *v550 == 0.0 )
            {
              v579 = v577 / *((float *)v9 + 1);
              v580 = v814 - v579;
              *v550 = v814 - v579;
              if ( (float)(v578 - v579) == 0.0 )
                v580 = FLOAT_1_1920929eN8;
              *v550 = v580;
              *v551 = v578;
            }
            if ( (float)(v578 - *v551) > 3.1415927 )
              --*v552;
            if ( (float)(v578 - *v551) < -3.1415927 )
              ++*v552;
            v581 = (__m128 *)v6->m_bodyA.m_storage;
            *v551 = v578;
            v582 = _mm_cvtsi32_si128(*v552);
            v583 = v6->m_bodyB.m_storage;
            v584 = (float)((float)(COERCE_FLOAT(_mm_cvtepi32_ps(v582)) * 6.2831855) + (float)(v578 - *v550))
                 * *((float *)v9 + 1);
            if ( *((_BYTE *)v9 + 8) )
            {
              v590 = v584 * 0.15915494;
              sizeOfAllAtomsr = *((_DWORD *)v9 + 1);
              v607 = v6->m_virtMassFactor.m_storage;
              v608 = v6->m_rhsFactor.m_storage;
              *(hkVector4f *)v549 = (hkVector4f)v556.m_quad;
              v609 = _mm_sub_ps(v553.m_quad, v581[7]);
              v610 = _mm_sub_ps(v554.m_quad, v583->m_scratch3.m_quad);
              atomm = v607;
              v611 = _mm_shuffle_ps(v556.m_quad, v556.m_quad, 201);
              v612 = _mm_sub_ps(_mm_mul_ps(v611, v609), _mm_mul_ps(_mm_shuffle_ps(v609, v609, 201), v556.m_quad));
              v613 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v610, v610, 201), v556.m_quad), _mm_mul_ps(v611, v610));
              v614 = _mm_mul_ps(_mm_shuffle_ps((__m128)sizeOfAllAtomsr, (__m128)sizeOfAllAtomsr, 0), v556.m_quad);
              v615 = _mm_add_ps(_mm_shuffle_ps(v612, v612, 201), v614);
              v616 = _mm_sub_ps(_mm_shuffle_ps(v613, v613, 201), v614);
              v549[1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v615, v615, 85), v581[5]),
                            _mm_mul_ps(_mm_shuffle_ps(v615, v615, 0), v581[4])),
                          _mm_mul_ps(_mm_shuffle_ps(v615, v615, 170), v581[6]));
              v617 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v616, v616, 85), v583->m_scratch1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v616, v616, 0), v583->m_scratch0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v616, v616, 170), v583->m_scratch2.m_quad));
              v549[2] = v617;
              v618 = v583->m_invMasses.m_quad;
              v619 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v549[1], v549[1]), v581[3]),
                       _mm_mul_ps(_mm_mul_ps(v617, v617), v618));
              v620 = _mm_shuffle_ps(
                       v619,
                       _mm_unpackhi_ps(v619, _mm_max_ps(_mm_add_ps(v618, v581[3]), (__m128)xmmword_141A712D0)),
                       196);
              v621 = _mm_add_ps(_mm_shuffle_ps(v620, v620, 78), v620);
              v622 = _mm_add_ps(_mm_shuffle_ps(v621, v621, 177), v621);
              v889 = v622;
              v549[2] = _mm_shuffle_ps(v549[2], _mm_unpackhi_ps(v549[2], v622), 196);
              v623 = _mm_rcp_ps(v889);
              v603 = _mm_mul_ps(v573, v556.m_quad);
              v624 = _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v889, v623)), v623),
                       _mm_shuffle_ps((__m128)LODWORD(atomm), (__m128)LODWORD(atomm), 0));
              v965 = v624;
              v625 = _mm_unpackhi_ps(v549[1], v624);
              v605 = (__m128)LODWORD(v608);
              v626 = _mm_shuffle_ps(v549[1], v625, 196);
              v604 = _mm_shuffle_ps(v603, v603, 85);
              v549[1] = v626;
              v606 = _mm_shuffle_ps(v603, v603, 0);
            }
            else
            {
              v585 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v548, v548, 201), v555.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v555.m_quad, v555.m_quad, 201), v548));
              v586 = _mm_mul_ps(_mm_shuffle_ps(v585, v585, 201), v556.m_quad);
              v587 = v6->m_virtMassFactor.m_storage;
              *(hkVector4f *)v549 = (hkVector4f)v556.m_quad;
              v588 = _mm_sub_ps(v553.m_quad, v581[7]);
              v589 = _mm_sub_ps(v554.m_quad, v583->m_scratch3.m_quad);
              sizeOfAllAtomsq = LODWORD(v587);
              v590 = v584
                   * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v586, v586, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v586, v586, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v586, v586, 170)));
              v591 = _mm_shuffle_ps(v556.m_quad, v556.m_quad, 201);
              v592 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v589, v589, 201), v556.m_quad), _mm_mul_ps(v591, v589));
              v593 = _mm_sub_ps(_mm_mul_ps(v591, v588), _mm_mul_ps(_mm_shuffle_ps(v588, v588, 201), v556.m_quad));
              v594 = _mm_shuffle_ps(v592, v592, 201);
              v595 = _mm_shuffle_ps(v593, v593, 201);
              v549[1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v595, v595, 85), v581[5]),
                            _mm_mul_ps(_mm_shuffle_ps(v595, v595, 0), v581[4])),
                          _mm_mul_ps(_mm_shuffle_ps(v595, v595, 170), v581[6]));
              v596 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v594, v594, 85), v583->m_scratch1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v594, v594, 0), v583->m_scratch0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v594, v594, 170), v583->m_scratch2.m_quad));
              v549[2] = v596;
              v597 = v583->m_invMasses.m_quad;
              v598 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v549[1], v549[1]), v581[3]),
                       _mm_mul_ps(_mm_mul_ps(v596, v596), v597));
              v599 = _mm_shuffle_ps(
                       v598,
                       _mm_unpackhi_ps(v598, _mm_max_ps(_mm_add_ps(v597, v581[3]), (__m128)xmmword_141A712D0)),
                       196);
              v600 = _mm_add_ps(_mm_shuffle_ps(v599, v599, 78), v599);
              v601 = _mm_add_ps(_mm_shuffle_ps(v600, v600, 177), v600);
              v888 = v601;
              v549[2] = _mm_shuffle_ps(v549[2], _mm_unpackhi_ps(v549[2], v601), 196);
              v602 = _mm_rcp_ps(v888);
              v603 = _mm_mul_ps(v573, v556.m_quad);
              v995 = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)sizeOfAllAtomsq, (__m128)sizeOfAllAtomsq, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v602, v888)), v602));
              v604 = _mm_shuffle_ps(v603, v603, 0);
              v549[1] = _mm_shuffle_ps(v549[1], _mm_unpackhi_ps(v549[1], v995), 196);
              v605 = (__m128)LODWORD(v6->m_rhsFactor.m_storage);
              v606 = _mm_shuffle_ps(v603, v603, 85);
            }
            v9 += 8;
            *v549 = _mm_shuffle_ps(
                      *v549,
                      _mm_unpackhi_ps(
                        *v549,
                        _mm_mul_ps(
                          _mm_add_ps(_mm_add_ps(v606, v604), _mm_shuffle_ps(v603, v603, 170)),
                          _mm_shuffle_ps(v605, v605, 0))),
                      196);
            *((float *)&v549->m128_u64[1] + 1) = (float)(v577 - v590) * v6->m_rhsFactor.m_storage;
            v627 = v6->m_damping.m_storage;
            v549[3].m128_i32[0] = LODWORD(v6->m_tau.m_storage);
            v549[3].m128_f32[1] = v627;
            *(float *)v549->m128_u64 = *(float *)v549->m128_u64 + 0.00000011920929;
            LOBYTE(v549->m128_u64[0]) = 7;
LABEL_146:
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 8);
            v21 = _xmm[0];
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
LABEL_236:
            v789 = (hkpConstraintAtom *)v9;
LABEL_237:
            v23 = FLOAT_0_5;
            v11 = v872;
            v14 = v865;
            v22 = *(float *)&FLOAT_1_0;
            v5 = (__m128)v870;
            if ( v9 >= v8 )
              return;
            break;
          case 0x16u:
            v628 = v7->m_constraintRuntime.m_storage;
            v629 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v630 = (float *)((char *)v628 + *((char *)v9 + 13));
            v631 = (float *)((char *)v628 + *((char *)v9 + 14));
            v632 = (signed int *)((char *)v628 + *((char *)v9 + 15));
            v7->m_jacobianSchemas.m_storage += 64;
            v633.m_quad = (__m128)baseA.m_rotation.m_col0;
            v634 = _mm_sub_ps(baseB.m_translation.m_quad, baseA.m_translation.m_quad);
            maxAngularImpulse.m_real = (__m128)baseB.m_rotation.m_col0;
            v635 = _mm_mul_ps(v634, v634);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v635, v635, 85))
                               + COERCE_FLOAT(_mm_shuffle_ps(v635, v635, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v635, v635, 170))) < 1.4210855e-14 )
              goto LABEL_188;
            v636 = _mm_shuffle_ps(v634, v634, 201);
            v637 = _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 201);
            v638 = _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 201);
            v639 = _mm_sub_ps(_mm_mul_ps(v634, v637), _mm_mul_ps(baseA.m_rotation.m_col0.m_quad, v636));
            v640 = _mm_shuffle_ps(v639, v639, 201);
            v641 = _mm_sub_ps(_mm_mul_ps(baseB.m_rotation.m_col0.m_quad, v636), _mm_mul_ps(v634, v638));
            v642 = _mm_shuffle_ps(v641, v641, 201);
            v643 = _mm_sub_ps(_mm_mul_ps(v640, baseA.m_rotation.m_col0.m_quad), _mm_mul_ps(v640, v637));
            v644 = _mm_shuffle_ps(v643, v643, 201);
            v645 = _mm_sub_ps(_mm_mul_ps(v642, baseB.m_rotation.m_col0.m_quad), _mm_mul_ps(v642, v638));
            v646 = _mm_mul_ps(v644, v644);
            v647 = _mm_shuffle_ps(v645, v645, 201);
            v648 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v646, v646, 85), _mm_shuffle_ps(v646, v646, 0)),
                     _mm_shuffle_ps(v646, v646, 170));
            v649 = _mm_mul_ps(v647, v647);
            v1014 = v648;
            v650 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v649, v649, 85), _mm_shuffle_ps(v649, v649, 0)),
                     _mm_shuffle_ps(v649, v649, 170));
            v967 = v650;
            if ( v648.m128_f32[0] < 1.4210855e-14 || v650.m128_f32[0] < 1.4210855e-14 )
            {
              v21 = _xmm[0];
LABEL_188:
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v629;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 8);
              v9 += 8;
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            }
            else
            {
              v651 = _mm_rsqrt_ps(v648);
              v652 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
              v653 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v651, v648), v651));
              v654 = _mm_mul_ps(*(__m128 *)_xmm, v651);
              v655 = _mm_rsqrt_ps(v650);
              v656 = _mm_mul_ps(v644, _mm_mul_ps(v653, v654));
              v657 = _mm_mul_ps(_mm_mul_ps(v655, v650), v655);
              v658 = _mm_mul_ps(baseA.m_rotation.m_col2.m_quad, v656);
              v659 = _mm_mul_ps(v647, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v657), _mm_mul_ps(*(__m128 *)_xmm, v655)));
              v660 = _mm_mul_ps(baseA.m_rotation.m_col1.m_quad, v656);
              v661 = _mm_mul_ps(baseB.m_rotation.m_col1.m_quad, v659);
              v662 = (__m128)*((unsigned int *)v9 + 2);
              v803 = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps((__m128)*((unsigned int *)v9 + 1), (__m128)*((unsigned int *)v9 + 1), 0),
                         v656),
                       baseA.m_translation.m_quad);
              v663 = _mm_mul_ps(baseB.m_rotation.m_col2.m_quad, v659);
              v664 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v662, v662, 0), v659), baseB.m_translation.m_quad);
              v997 = _mm_movelh_ps(
                       _mm_unpacklo_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v660, v660, 85), _mm_shuffle_ps(v660, v660, 0)),
                           _mm_shuffle_ps(v660, v660, 170)),
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v661, v661, 85), _mm_shuffle_ps(v661, v661, 0)),
                           _mm_shuffle_ps(v661, v661, 170))),
                       v652);
              v665 = _mm_rcp_ps(
                       _mm_movelh_ps(
                         _mm_unpacklo_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v658, v658, 85), _mm_shuffle_ps(v658, v658, 0)),
                             _mm_shuffle_ps(v658, v658, 170)),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v663, v663, 85), _mm_shuffle_ps(v663, v663, 0)),
                             _mm_shuffle_ps(v663, v663, 170))),
                         v652));
              v666 = _mm_cmpleps((__m128)0i64, v665);
              v667 = _mm_mul_ps(v997, v665);
              v668 = _mm_or_ps(
                       _mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v667),
                       _mm_cmpltps(*(__m128 *)_xmm, v667));
              v669 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v667), v668), _mm_andnot_ps(v668, v667));
              v670 = _mm_mul_ps(v669, v669);
              v671 = _mm_mul_ps(
                       _mm_rcp_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_rcp_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_rcp_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v670, *(__m128 *)s0)), *(__m128 *)t0),
                                       _mm_add_ps(v670, *(__m128 *)s1))),
                                   *(__m128 *)t1),
                                 _mm_add_ps(v670, *(__m128 *)s2))),
                             *(__m128 *)t2),
                           _mm_add_ps(v670, *(__m128 *)s3))),
                       _mm_mul_ps(v669, *(__m128 *)t3));
              v672 = _mm_or_ps(
                       _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v669, *(__m128 *)_xmm), *(__m128 *)_xmm), v671), v668),
                       _mm_andnot_ps(v668, v671));
              v969 = _mm_or_ps(
                       _mm_andnot_ps(
                         v666,
                         _mm_add_ps(_mm_or_ps(_mm_and_ps(v997, *(__m128 *)_xmm), *(__m128 *)_xmm), v672)),
                       _mm_and_ps(v672, v666));
              v791 = v969.m128_u64[0];
              if ( *v630 == 0.0 )
              {
                v673 = v969.m128_f32[0];
                if ( v969.m128_f32[0] == 0.0 )
                  v673 = FLOAT_1_1920929eN8;
                *v630 = v673;
                v674 = *((float *)&v791 + 1);
                if ( *((float *)&v791 + 1) == 0.0 )
                  v674 = FLOAT_1_1920929eN8;
                v630[1] = v674;
                *(_QWORD *)v631 = v791;
              }
              if ( (float)(*(float *)&v791 - *v631) > 3.1415927 )
                --*v632;
              if ( (float)(*(float *)&v791 - *v631) < -3.1415927 )
                ++*v632;
              v675 = *((float *)&v791 + 1);
              if ( (float)(*((float *)&v791 + 1) - v631[1]) > 3.1415927 )
              {
                --v632[1];
                v675 = *((float *)&v791 + 1);
              }
              if ( (float)(v675 - v631[1]) < -3.1415927 )
                ++v632[1];
              *(_QWORD *)v631 = v791;
              v676 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v656, v656, 201), v633.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v633.m_quad, v633.m_quad, 201), v656));
              v677 = (float)((float)((float)*v632 * 6.2831855) + (float)(*(float *)&v791 - *v630)) * *((float *)v9 + 1);
              v678 = _mm_shuffle_ps(v676, v676, 201);
              v679 = (float)((float)(*((float *)&v791 + 1) - v630[1]) + (float)((float)v632[1] * 6.2831855))
                   * *((float *)v9 + 2);
              v680 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v659, v659, 201), maxAngularImpulse.m_real),
                       _mm_mul_ps(_mm_shuffle_ps(maxAngularImpulse.m_real, maxAngularImpulse.m_real, 201), v659));
              v681 = _mm_shuffle_ps(v680, v680, 201);
              v682 = _mm_mul_ps(v681, v678);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v682, v682, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v682, v682, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v682, v682, 170))) > 0.0 )
              {
                v679 = v679 * -1.0;
                v683 = _mm_add_ps(v678, v681);
                v686 = _mm_mul_ps(v683, v683);
                v685 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v686, v686, 85), _mm_shuffle_ps(v686, v686, 0)),
                         _mm_shuffle_ps(v686, v686, 170));
                v971 = v685;
              }
              else
              {
                v683 = _mm_sub_ps(v678, v681);
                v684 = _mm_mul_ps(v683, v683);
                v685 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v684, v684, 85), _mm_shuffle_ps(v684, v684, 0)),
                         _mm_shuffle_ps(v684, v684, 170));
                v1009 = v685;
              }
              v687 = (__m128 *)v6->m_bodyB.m_storage;
              v688 = v6->m_bodyA.m_storage;
              v689 = _mm_rsqrt_ps(v685);
              v690 = _mm_cmpleps(v685, (__m128)0i64);
              v691 = _mm_mul_ps(v689, v685);
              v692 = v803;
              sizeOfAllAtomss = LODWORD(v6->m_virtMassFactor.m_storage);
              v693 = _mm_mul_ps(
                       v683,
                       _mm_andnot_ps(
                         v690,
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v691, v689)), _mm_mul_ps(v689, *(__m128 *)_xmm))));
              *v629 = v693;
              v694 = _mm_sub_ps(v692, v688->m_scratch3.m_quad);
              v695 = _mm_sub_ps(v664, v687[7]);
              v696 = _mm_shuffle_ps(v693, v693, 201);
              v697 = _mm_sub_ps(_mm_mul_ps(v694, v696), _mm_mul_ps(_mm_shuffle_ps(v694, v694, 201), v693));
              v698 = _mm_shuffle_ps(v697, v697, 201);
              v699 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v695, v695, 201), v693), _mm_mul_ps(v695, v696));
              v629[1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v698, v698, 85), v688->m_scratch1.m_quad),
                            _mm_mul_ps(_mm_shuffle_ps(v698, v698, 0), v688->m_scratch0.m_quad)),
                          _mm_mul_ps(_mm_shuffle_ps(v698, v698, 170), v688->m_scratch2.m_quad));
              v700 = _mm_shuffle_ps(v699, v699, 201);
              v701 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v700, v700, 85), v687[5]),
                         _mm_mul_ps(_mm_shuffle_ps(v700, v700, 0), v687[4])),
                       _mm_mul_ps(_mm_shuffle_ps(v700, v700, 170), v687[6]));
              v629[2] = v701;
              v702 = v688->m_invMasses.m_quad;
              v703 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v629[1], v629[1]), v702),
                       _mm_mul_ps(_mm_mul_ps(v701, v701), v687[3]));
              v704 = _mm_shuffle_ps(
                       v703,
                       _mm_unpackhi_ps(v703, _mm_max_ps(_mm_add_ps(v702, v687[3]), (__m128)xmmword_141A712D0)),
                       196);
              v705 = _mm_add_ps(_mm_shuffle_ps(v704, v704, 78), v704);
              v892 = _mm_add_ps(_mm_shuffle_ps(v705, v705, 177), v705);
              v629[2] = _mm_shuffle_ps(v629[2], _mm_unpackhi_ps(v629[2], v892), 196);
              v706 = _mm_rcp_ps(v892);
              v9 += 8;
              v21 = _xmm[0];
              v707 = _mm_mul_ps(_mm_sub_ps(v664, v803), v693);
              v999 = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)sizeOfAllAtomss, (__m128)sizeOfAllAtomss, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v706, v892)), v706));
              v629[1] = _mm_shuffle_ps(v629[1], _mm_unpackhi_ps(v629[1], v999), 196);
              *v629 = _mm_shuffle_ps(
                        *v629,
                        _mm_unpackhi_ps(
                          *v629,
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v707, v707, 85), _mm_shuffle_ps(v707, v707, 0)),
                              _mm_shuffle_ps(v707, v707, 170)),
                            _mm_shuffle_ps(
                              (__m128)LODWORD(v6->m_rhsFactor.m_storage),
                              (__m128)LODWORD(v6->m_rhsFactor.m_storage),
                              0))),
                        196);
              HIDWORD(v629->m128_u64[1]) = COERCE_UNSIGNED_INT((float)(v679 + v677) * v6->m_rhsFactor.m_storage) ^ _xmm[0];
              v705.m128_i32[0] = LODWORD(v6->m_damping.m_storage);
              v629[3].m128_i32[0] = LODWORD(v6->m_tau.m_storage);
              v629[3].m128_i32[1] = v705.m128_i32[0];
              *(float *)v629->m128_u64 = *(float *)v629->m128_u64 + 0.00000011920929;
              LOBYTE(v629->m128_u64[0]) = 7;
              v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                                + 8);
              v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 8;
            }
            goto LABEL_236;
          case 0x17u:
            if ( *((_BYTE *)v9 + 2) )
            {
              v39 = v6->m_bodyA.m_storage;
              v40 = v6->m_bodyB.m_storage;
              v41 = _mm_sub_ps(baseA.m_translation.m_quad, v39->m_scratch3.m_quad);
              v42 = _mm_sub_ps(baseB.m_translation.m_quad, v40->m_scratch3.m_quad);
              v43 = v39->m_invMasses.m_quad;
              v44 = v40->m_invMasses.m_quad;
              v45 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v40->m_scratch1.m_quad);
              v872 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v39->m_scratch1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v39->m_scratch0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v39->m_scratch2.m_quad));
              vLocalArmA.m_quad = v872;
              v865 = _mm_add_ps(
                       _mm_add_ps(v45, _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v40->m_scratch0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v40->m_scratch2.m_quad));
              vLocalArmB.m_quad = v865;
              v46 = _mm_max_ps(
                      _mm_shuffle_ps(v43, v43, 170),
                      _mm_max_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)));
              v47 = _mm_max_ps(
                      _mm_shuffle_ps(v44, v44, 170),
                      _mm_max_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)));
              v48 = _mm_mul_ps(v872, v872);
              v49 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v48, v48, 0), _mm_shuffle_ps(v48, v48, 85)),
                      _mm_shuffle_ps(v48, v48, 170));
              v50 = _mm_rsqrt_ps(v49);
              v1015 = v49;
              v51 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50));
              v52 = _mm_mul_ps(*(__m128 *)_xmm, v50);
              v53 = _mm_mul_ps(v865, v865);
              v54 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                      _mm_shuffle_ps(v53, v53, 170));
              v55 = _mm_rsqrt_ps(v54);
              v936 = v54;
              v938 = _mm_max_ps(_mm_max_ps(v46, v47), *(__m128 *)&epsilon);
              v56 = _mm_max_ps(
                      _mm_max_ps(
                        _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v49, (__m128)0i64), _mm_mul_ps(v51, v52)), v46),
                        _mm_mul_ps(
                          _mm_andnot_ps(
                            _mm_cmpleps(v54, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                              _mm_mul_ps(*(__m128 *)_xmm, v55))),
                          v47)),
                      *(__m128 *)&epsilon);
              v940 = v56;
              v57 = _mm_mul_ps(
                      _mm_shuffle_ps((__m128)*((unsigned int *)v9 + 3), (__m128)*((unsigned int *)v9 + 3), 0),
                      _mm_shuffle_ps(
                        (__m128)LODWORD(v6->m_subStepInvDeltaTime.m_storage),
                        (__m128)LODWORD(v6->m_subStepInvDeltaTime.m_storage),
                        0));
              v58 = _mm_rcp_ps(v938);
              v59 = _mm_shuffle_ps((__m128)*((unsigned int *)v9 + 2), (__m128)*((unsigned int *)v9 + 2), 0);
              v60 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v938, v58)), v58);
              v61 = _mm_rcp_ps(v56);
              v62 = _mm_mul_ps(v60, v57);
              v63 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v56, v61));
              v21 = _xmm[0];
              v942 = v62;
              v64 = _mm_min_ps(v62, v59);
              v65 = _mm_shuffle_ps((__m128)*((unsigned int *)v9 + 1), (__m128)*((unsigned int *)v9 + 1), 0);
              v870 = (__int128)v64;
              v944 = _mm_mul_ps(_mm_mul_ps(v63, v61), v57);
              maxLinearImpulse.m_real = _mm_min_ps(v944, v65);
            }
            v9 += 8;
            goto LABEL_236;
          case 0x18u:
            v66 = (hkpSimpleContactConstraintAtom *)v7->m_jacobianSchemas.m_storage;
            v67 = v6->m_bodyB.m_storage;
            atom = v66;
            hkMatrix3f::setMul(
              &v832,
              (hkMatrix3f *)&v6->m_bodyA.m_storage->m_scratch0,
              (hkMatrix3f *)&baseA.m_rotation.m_col0);
            hkMatrix3f::setMul(&v823, (hkMatrix3f *)&v67->m_scratch0, (hkMatrix3f *)&baseB.m_rotation.m_col0);
            v68 = (float)(v832.m_col1.m_quad.m128_f32[1] + v832.m_col0.m_quad.m128_f32[0])
                + v832.m_col2.m_quad.m128_f32[2];
            if ( v68 <= 0.0 )
            {
              v830 = 1;
              v831 = 2i64;
              v70 = 0i64;
              if ( v832.m_col1.m_quad.m128_f32[1] > v832.m_col0.m_quad.m128_f32[0] )
                v70 = 1i64;
              if ( v832.m_col2.m_quad.m128_f32[2] > v832.m_col0.m_quad.m128_f32[5 * v70] )
                v70 = 2i64;
              v71 = *(&v830 + v70);
              v72 = *(&v830 + v71);
              v73 = fsqrt(
                      (float)(v832.m_col0.m_quad.m128_f32[5 * v70]
                            - (float)(v832.m_col0.m_quad.m128_f32[5 * v72] + v832.m_col0.m_quad.m128_f32[5 * v71]))
                    + v22);
              v802.m128_f32[v70] = v73 * v23;
              v802.m128_f32[3] = (float)(v832.m_col0.m_quad.m128_f32[v72 + 4 * v71]
                                       - v832.m_col0.m_quad.m128_f32[v71 + 4 * v72])
                               * (float)(v23 / v73);
              v802.m128_f32[v71] = (float)(v832.m_col0.m_quad.m128_f32[v70 + 4 * v71]
                                         + v832.m_col0.m_quad.m128_f32[v71 + 4 * v70])
                                 * (float)(v23 / v73);
              v802.m128_f32[v72] = (float)(v832.m_col0.m_quad.m128_f32[v70 + 4 * v72]
                                         + v832.m_col0.m_quad.m128_f32[v72 + 4 * v70])
                                 * (float)(v23 / v73);
            }
            else
            {
              sizeOfAllAtomsf = v68 + v22;
              v69 = fsqrt(v68 + v22);
              v802.m128_f32[3] = v69 * v23;
              v802.m128_f32[0] = (float)(v832.m_col1.m_quad.m128_f32[2] - v832.m_col2.m_quad.m128_f32[1])
                               * (float)(v23 / v69);
              v802.m128_f32[1] = (float)(v832.m_col2.m_quad.m128_f32[0] - v832.m_col0.m_quad.m128_f32[2])
                               * (float)(v23 / v69);
              v802.m128_f32[2] = (float)(v832.m_col0.m_quad.m128_f32[1] - v832.m_col1.m_quad.m128_f32[0])
                               * (float)(v23 / v69);
            }
            v74 = _mm_mul_ps(v802, v802);
            v75 = _mm_add_ps(_mm_shuffle_ps(v74, v74, 78), v74);
            v76 = _mm_add_ps(_mm_shuffle_ps(v75, v75, 177), v75);
            v77 = _mm_rsqrt_ps(v76);
            v946 = v76;
            v78 = _mm_mul_ps(
                    v802,
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v77, v76), v77)),
                      _mm_mul_ps(*(__m128 *)_xmm, v77)));
            v948 = v78;
            v79 = (float)(v823.m_col1.m_quad.m128_f32[1] + v823.m_col0.m_quad.m128_f32[0])
                + v823.m_col2.m_quad.m128_f32[2];
            if ( v79 <= 0.0 )
            {
              v828 = 1;
              v829 = 2i64;
              v81 = 0i64;
              if ( v823.m_col1.m_quad.m128_f32[1] > v823.m_col0.m_quad.m128_f32[0] )
                v81 = 1i64;
              if ( v823.m_col2.m_quad.m128_f32[2] > v823.m_col0.m_quad.m128_f32[5 * v81] )
                v81 = 2i64;
              v82 = *(&v828 + v81);
              v83 = *(&v828 + v82);
              v84 = fsqrt(
                      (float)(v823.m_col0.m_quad.m128_f32[5 * v81]
                            - (float)(v823.m_col0.m_quad.m128_f32[5 * v83] + v823.m_col0.m_quad.m128_f32[5 * v82]))
                    + v22);
              v805.m128_f32[v81] = v84 * v23;
              v805.m128_f32[3] = (float)(v823.m_col0.m_quad.m128_f32[v83 + 4 * v82]
                                       - v823.m_col0.m_quad.m128_f32[v82 + 4 * v83])
                               * (float)(v23 / v84);
              v805.m128_f32[v82] = (float)(v823.m_col0.m_quad.m128_f32[v82 + 4 * v81]
                                         + v823.m_col0.m_quad.m128_f32[v81 + 4 * v82])
                                 * (float)(v23 / v84);
              v805.m128_f32[v83] = (float)(v823.m_col0.m_quad.m128_f32[v83 + 4 * v81]
                                         + v823.m_col0.m_quad.m128_f32[v81 + 4 * v83])
                                 * (float)(v23 / v84);
            }
            else
            {
              sizeOfAllAtomsg = v79 + v22;
              v80 = fsqrt(v79 + v22);
              v805.m128_f32[3] = v80 * v23;
              v805.m128_f32[0] = (float)(v823.m_col1.m_quad.m128_f32[2] - v823.m_col2.m_quad.m128_f32[1])
                               * (float)(v23 / v80);
              v805.m128_f32[1] = (float)(v823.m_col2.m_quad.m128_f32[0] - v823.m_col0.m_quad.m128_f32[2])
                               * (float)(v23 / v80);
              v805.m128_f32[2] = (float)(v823.m_col0.m_quad.m128_f32[1] - v823.m_col1.m_quad.m128_f32[0])
                               * (float)(v23 / v80);
            }
            v7 = v1058;
            v85 = (signed __int64)&atom[1];
            v86 = _mm_mul_ps(v805, v805);
            v87 = _mm_add_ps(_mm_shuffle_ps(v86, v86, 78), v86);
            v950 = _mm_add_ps(_mm_shuffle_ps(v87, v87, 177), v87);
            v88 = _mm_rsqrt_ps(v950);
            v886 = _mm_mul_ps(
                     v805,
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v88, v950), v88)),
                       _mm_mul_ps(v88, *(__m128 *)_xmm)));
            *(__m128 *)(v85 - 32) = v78;
            *(__m128 *)(v85 - 16) = v886;
            *(__m128 *)(v85 - 48) = _mm_movelh_ps(
                                      _mm_unpacklo_ps(
                                        aabbOut.m_quad,
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(
                                            (__m128)LODWORD(v6->m_tau.m_storage),
                                            (__m128)LODWORD(v6->m_tau.m_storage),
                                            0),
                                          _mm_shuffle_ps(
                                            (__m128)LODWORD(v6->m_subStepInvDeltaTime.m_storage),
                                            (__m128)LODWORD(v6->m_subStepInvDeltaTime.m_storage),
                                            0))),
                                      _mm_unpacklo_ps(v5, aabbOut.m_quad));
            *(float *)(v85 - 48) = *(float *)&atom->m_type.m_storage + 0.00000011920929;
            *(_BYTE *)(v85 - 48) = 32;
            v1058->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)&atom[1];
LABEL_16:
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 24);
            v8 = v790;
            v9 += 8;
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 24;
            goto LABEL_236;
          case 0x19u:
            v89 = (__m128 *)v6->m_bodyA.m_storage;
            v90 = (__m128 *)v6->m_bodyB.m_storage;
            v91 = (__m128 *)v7->m_jacobianSchemas.m_storage;
            v92 = _mm_shuffle_ps(
                    (__m128)LODWORD(v6->m_microStepDeltaTime.m_storage),
                    (__m128)LODWORD(v6->m_microStepDeltaTime.m_storage),
                    0);
            v93 = _mm_mul_ps(*((__m128 *)v9 + 5), v92);
            v94 = _mm_mul_ps(*((__m128 *)v9 + 4), v92);
            v95 = *((__m128 *)v9 + 3);
            *v91 = _mm_mul_ps(*((__m128 *)v9 + 2), v92);
            v91[1] = _mm_mul_ps(v95, v92);
            v91[2] = v94;
            v91[3] = v93;
            v96 = _mm_sub_ps(baseA.m_translation.m_quad, v89[7]);
            v97 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v96, v96, 85), v89[5]),
                      _mm_mul_ps(_mm_shuffle_ps(v96, v96, 0), v89[4])),
                    _mm_mul_ps(_mm_shuffle_ps(v96, v96, 170), v89[6]));
            v98 = _mm_sub_ps(baseB.m_translation.m_quad, v90[7]);
            v99 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), v90[5]),
                      _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), v90[4])),
                    _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), v90[6]));
            v100 = _mm_mul_ps(v97, v97);
            v101 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                     _mm_shuffle_ps(v100, v100, 170));
            v102 = _mm_rsqrt_ps(v101);
            v952 = v101;
            v103 = _mm_mul_ps(v99, v99);
            v91[4] = _mm_shuffle_ps(
                       v97,
                       _mm_unpackhi_ps(
                         v97,
                         _mm_andnot_ps(
                           _mm_cmpleps(v101, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v102, v101), v102)),
                               _mm_mul_ps(*(__m128 *)_xmm, v102)),
                             v101))),
                       196);
            v954 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
                     _mm_shuffle_ps(v103, v103, 170));
            v104 = _mm_rsqrt_ps(v954);
            v91[5] = _mm_shuffle_ps(
                       v99,
                       _mm_unpackhi_ps(
                         v99,
                         _mm_andnot_ps(
                           _mm_cmpleps(v954, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v104, v954), v104)),
                               _mm_mul_ps(*(__m128 *)_xmm, v104)),
                             v954))),
                       196);
            v105 = *((__m128 *)v9 + 1);
            v106 = _mm_shuffle_ps(v89[3], v89[3], 255);
            v107 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v105, v105, 85), v6->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                       _mm_mul_ps(
                         _mm_shuffle_ps(*((__m128 *)v9 + 1), v105, 0),
                         v6->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v105, v105, 170), v6->m_transformA.m_storage->m_rotation.m_col2.m_quad));
            v108 = _mm_shuffle_ps(v107, v107, 85);
            v109 = _mm_shuffle_ps(v107, v107, 0);
            v110 = _mm_shuffle_ps(v107, v107, 170);
            v111 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v90[4], v109), _mm_mul_ps(v108, v90[5])), _mm_mul_ps(v90[6], v110));
            v112 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v89[4], v109), _mm_mul_ps(v108, v89[5])), _mm_mul_ps(v89[6], v110));
            v113 = _mm_shuffle_ps(v90[3], v90[3], 255);
            v956 = _mm_add_ps(v113, v106);
            v114 = _mm_rcp_ps(v956);
            v115 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v114, v956)), v114);
            v958 = v115;
            v91[6] = _mm_mul_ps(_mm_mul_ps(v115, v113), v112);
            v91[7] = _mm_mul_ps(v111, _mm_mul_ps(v115, v106));
            v116 = *((__m128 *)v9 + 1);
            v117 = _mm_shuffle_ps((__m128)LODWORD(v6->m_tau.m_storage), (__m128)LODWORD(v6->m_tau.m_storage), 0);
            v118 = _mm_shuffle_ps(v116, v116, 255);
            sizeOfAllAtomsh = LODWORD(v6->m_subStepInvDeltaTime.m_storage);
            v119 = _mm_mul_ps(v116, v116);
            v9 += 48;
            v120 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                     _mm_shuffle_ps(v119, v119, 170));
            v960 = v120;
            v121 = _mm_rsqrt_ps(v120);
            v91[2] = _mm_shuffle_ps(v91[2], _mm_unpackhi_ps(v91[2], v117), 196);
            v21 = _xmm[0];
            v91[3] = _mm_shuffle_ps(
                       v91[3],
                       _mm_unpackhi_ps(
                         v91[3],
                         _mm_mul_ps(_mm_shuffle_ps((__m128)sizeOfAllAtomsh, (__m128)sizeOfAllAtomsh, 0), v117)),
                       196);
            v91[6] = _mm_shuffle_ps(
                       v91[6],
                       _mm_unpackhi_ps(
                         v91[6],
                         _mm_andnot_ps(
                           _mm_cmpleps(v120, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v121, v120), v121)),
                               _mm_mul_ps(*(__m128 *)_xmm, v121)),
                             v120))),
                       196);
            v91[7] = _mm_shuffle_ps(v91[7], _mm_unpackhi_ps(v91[7], v118), 196);
            *(float *)v91->m128_u64 = *(float *)v91->m128_u64 + 0.00000011920929;
            LOBYTE(v91->m128_u64[0]) = 34;
            v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)&v91[8];
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 24);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 24;
            goto LABEL_236;
          case 0x1Au:
            v123 = v6->m_bodyB.m_storage;
            v124 = *((__m128 *)v9 + 3);
            v125 = *((__m128 *)v9 + 4);
            v126 = *((__m128 *)v9 + 5);
            v127 = v7->m_jacobianSchemas.m_storage;
            sizeOfAllAtomsi = LODWORD(v6->m_microStepDeltaTime.m_storage);
            maxAngularImpulse.m_real.m128_u64[0] = (unsigned __int64)v6->m_bodyA.m_storage;
            v122 = (__m128 *)maxAngularImpulse.m_real.m128_u64[0];
            atomi = (hkpSimpleContactConstraintAtom *)v123;
            v128 = _mm_shuffle_ps((__m128)sizeOfAllAtomsi, (__m128)sizeOfAllAtomsi, 0);
            *(__m128 *)v127 = _mm_mul_ps(*((__m128 *)v9 + 2), v128);
            *(__m128 *)&v127[16] = _mm_mul_ps(v124, v128);
            *(__m128 *)&v127[32] = _mm_mul_ps(v125, v128);
            *(__m128 *)&v127[48] = _mm_mul_ps(v126, v128);
            v129 = v122[5];
            v130 = v122[4];
            v131 = v122[6];
            v132 = v123->m_scratch1.m_quad;
            v133 = v123->m_scratch2.m_quad;
            v134 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 0),
                         v130),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 85),
                         v129)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseA.m_rotation.m_col0.m_quad, baseA.m_rotation.m_col0.m_quad, 170),
                       v131));
            v833 = v134;
            v135 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseA.m_rotation.m_col1.m_quad, baseA.m_rotation.m_col1.m_quad, 0),
                         v130),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseA.m_rotation.m_col1.m_quad, baseA.m_rotation.m_col1.m_quad, 85),
                         v129)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseA.m_rotation.m_col1.m_quad, baseA.m_rotation.m_col1.m_quad, 170),
                       v131));
            v834 = v135;
            v136 = _mm_mul_ps(_mm_shuffle_ps(baseA.m_rotation.m_col2.m_quad, baseA.m_rotation.m_col2.m_quad, 85), v129);
            v137 = v123->m_scratch0.m_quad;
            v138 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseA.m_rotation.m_col2.m_quad, baseA.m_rotation.m_col2.m_quad, 0),
                         v130),
                       v136),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseA.m_rotation.m_col2.m_quad, baseA.m_rotation.m_col2.m_quad, 170),
                       v131));
            v835 = v138;
            v820 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 0),
                         v137),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 85),
                         v132)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col0.m_quad, baseB.m_rotation.m_col0.m_quad, 170),
                       v133));
            LODWORD(v139) = (unsigned __int128)_mm_shuffle_ps(v135, v135, 85);
            LODWORD(v140) = (unsigned __int128)_mm_shuffle_ps(v138, v138, 170);
            v821 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col1.m_quad, baseB.m_rotation.m_col1.m_quad, 0),
                         v137),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col1.m_quad, baseB.m_rotation.m_col1.m_quad, 85),
                         v132)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col1.m_quad, baseB.m_rotation.m_col1.m_quad, 170),
                       v133));
            v822 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col2.m_quad, baseB.m_rotation.m_col2.m_quad, 0),
                         v137),
                       _mm_mul_ps(
                         _mm_shuffle_ps(baseB.m_rotation.m_col2.m_quad, baseB.m_rotation.m_col2.m_quad, 85),
                         v132)),
                     _mm_mul_ps(
                       _mm_shuffle_ps(baseB.m_rotation.m_col2.m_quad, baseB.m_rotation.m_col2.m_quad, 170),
                       v133));
            v141 = (float)(v139 + v134.m128_f32[0]) + v140;
            if ( v141 <= 0.0 )
            {
              v143 = 0i64;
              v826 = 1;
              if ( v139 > v134.m128_f32[0] )
                v143 = 1i64;
              v827 = 2i64;
              if ( v140 > v833.m128_f32[5 * v143] )
                v143 = 2i64;
              v144 = *(&v826 + v143);
              v145 = *(&v826 + v144);
              v146 = fsqrt(
                       (float)(v833.m128_f32[5 * v143] - (float)(v833.m128_f32[5 * v145] + v833.m128_f32[5 * v144]))
                     + v22);
              v804.m128_f32[v143] = v146 * v23;
              v804.m128_f32[3] = (float)(v833.m128_f32[v145 + 4 * v144] - v833.m128_f32[v144 + 4 * v145])
                               * (float)(v23 / v146);
              v804.m128_f32[v144] = (float)(v833.m128_f32[v143 + 4 * v144] + v833.m128_f32[v144 + 4 * v143])
                                  * (float)(v23 / v146);
              v804.m128_f32[v145] = (float)(v833.m128_f32[v143 + 4 * v145] + v833.m128_f32[v145 + 4 * v143])
                                  * (float)(v23 / v146);
            }
            else
            {
              sizeOfAllAtomsj = v141 + v22;
              v142 = fsqrt(v141 + v22);
              v804.m128_f32[3] = v142 * v23;
              v804.m128_f32[0] = (float)(v834.m128_f32[2] - v835.m128_f32[1]) * (float)(v23 / v142);
              v804.m128_f32[1] = (float)(v835.m128_f32[0] - v833.m128_f32[2]) * (float)(v23 / v142);
              v804.m128_f32[2] = (float)(v833.m128_f32[1] - v834.m128_f32[0]) * (float)(v23 / v142);
            }
            v147 = v804;
            *(__m128 *)&v127[64] = v804;
            v148 = _mm_mul_ps(v147, v147);
            v149 = _mm_add_ps(_mm_shuffle_ps(v148, v148, 78), v148);
            v150 = _mm_add_ps(_mm_shuffle_ps(v149, v149, 177), v149);
            v151 = _mm_rsqrt_ps(v150);
            v962 = v150;
            v152 = _mm_mul_ps(v151, v150);
            v153 = v821.m128_f32[1];
            v154 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v152, v151));
            v152.m128_i32[0] = v821.m128_i32[1];
            v155 = _mm_mul_ps(v154, _mm_mul_ps(v151, *(__m128 *)_xmm));
            v156 = v822.m128_f32[2];
            *(__m128 *)&v127[64] = _mm_mul_ps(v155, *(__m128 *)&v127[64]);
            v157 = (float)(v152.m128_f32[0] + v820.m128_f32[0]) + v156;
            if ( v157 <= 0.0 )
            {
              v159 = 0i64;
              v824 = 1;
              if ( v153 > v820.m128_f32[0] )
                v159 = 1i64;
              v825 = 2i64;
              if ( v156 > v820.m128_f32[5 * v159] )
                v159 = 2i64;
              v160 = *(&v824 + v159);
              v161 = *(&v824 + v160);
              v162 = fsqrt(
                       (float)(v820.m128_f32[5 * v159] - (float)(v820.m128_f32[5 * v161] + v820.m128_f32[5 * v160]))
                     + v22);
              v801.m128_f32[v159] = v162 * v23;
              v801.m128_f32[3] = (float)(v820.m128_f32[v161 + 4 * v160] - v820.m128_f32[v160 + 4 * v161])
                               * (float)(v23 / v162);
              v801.m128_f32[v160] = (float)(v820.m128_f32[v159 + 4 * v160] + v820.m128_f32[v160 + 4 * v159])
                                  * (float)(v23 / v162);
              v801.m128_f32[v161] = (float)(v820.m128_f32[v159 + 4 * v161] + v820.m128_f32[v161 + 4 * v159])
                                  * (float)(v23 / v162);
            }
            else
            {
              sizeOfAllAtomsk = v157 + v22;
              v158 = fsqrt(v157 + v22);
              v801.m128_f32[3] = v158 * v23;
              v801.m128_f32[0] = (float)(v821.m128_f32[2] - v822.m128_f32[1]) * (float)(v23 / v158);
              v801.m128_f32[1] = (float)(v822.m128_f32[0] - v820.m128_f32[2]) * (float)(v23 / v158);
              v801.m128_f32[2] = (float)(v820.m128_f32[1] - v821.m128_f32[0]) * (float)(v23 / v158);
            }
            v163 = v801;
            *(__m128 *)&v127[80] = v801;
            v164 = _mm_mul_ps(v163, v163);
            v165 = _mm_add_ps(_mm_shuffle_ps(v164, v164, 78), v164);
            v166 = _mm_add_ps(_mm_shuffle_ps(v165, v165, 177), v165);
            v167 = _mm_rsqrt_ps(v166);
            v964 = v166;
            *(__m128 *)&v127[80] = _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v167, v166), v167)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v167)),
                                     *(__m128 *)&v127[80]);
            v168 = _mm_shuffle_ps(v123->m_invMasses.m_quad, v123->m_invMasses.m_quad, 255);
            v169 = _mm_add_ps(
                     _mm_shuffle_ps(
                       *(__m128 *)(maxAngularImpulse.m_real.m128_u64[0] + 48),
                       *(__m128 *)(maxAngularImpulse.m_real.m128_u64[0] + 48),
                       255),
                     v168);
            v170 = _mm_rcp_ps(v169);
            v966 = v169;
            v968 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v170, v169)), v170);
            v970 = *((__m128 *)v9 + 1);
            v171 = v970;
            v172 = _mm_mul_ps(v970, qi.m_vec.m_quad);
            v173 = _mm_add_ps(_mm_shuffle_ps(v172, v172, 78), v172);
            v972 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v173, v173, 177), v173), 0x1Fu),
                               0x1Fu),
                     qi.m_vec.m_quad);
            v174 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v970, v972), _mm_mul_ps(v968, v168)), v972);
            v175 = _mm_mul_ps(v174, v174);
            v176 = _mm_add_ps(_mm_shuffle_ps(v175, v175, 78), v175);
            v177 = _mm_add_ps(_mm_shuffle_ps(v176, v176, 177), v176);
            v178 = _mm_rsqrt_ps(v177);
            v974 = v177;
            v179 = _mm_mul_ps(*(__m128 *)_xmm, v178);
            v180 = _mm_mul_ps(_mm_mul_ps(v178, v177), v178);
            v181 = _mm_shuffle_ps(v970, v970, 201);
            v182 = _mm_mul_ps(
                     _mm_andnot_ps(_mm_cmpleps(v177, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v180), v179)),
                     v174);
            v976 = v182;
            v183 = _mm_mul_ps(_mm_shuffle_ps(v182, v182, 201), v970);
            v21 = _xmm[0];
            v8 = v790;
            *(__m128 *)&v127[96] = v182;
            v9 += 48;
            v184 = _mm_sub_ps(_mm_mul_ps(v181, v182), v183);
            v185 = _mm_sub_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v171, v171, 255), v182), _mm_shuffle_ps(v184, v184, 201)),
                     _mm_mul_ps(_mm_shuffle_ps(v182, v182, 255), v171));
            v186 = _mm_mul_ps(v182, v171);
            v187 = _mm_add_ps(_mm_shuffle_ps(v186, v186, 78), v186);
            *(__m128 *)&v127[112] = _mm_shuffle_ps(
                                      v185,
                                      _mm_unpackhi_ps(v185, _mm_add_ps(_mm_shuffle_ps(v187, v187, 177), v187)),
                                      196);
            v188 = _mm_mul_ps(*((__m128 *)v9 - 5), *((__m128 *)v9 - 5));
            v189 = _mm_shuffle_ps(*((__m128 *)v9 - 4), *((__m128 *)v9 - 4), 255);
            sizeOfAllAtomsl = LODWORD(v6->m_subStepInvDeltaTime.m_storage);
            v190 = _mm_shuffle_ps((__m128)LODWORD(v6->m_tau.m_storage), (__m128)LODWORD(v6->m_tau.m_storage), 0);
            *(__m128 *)v127 = _mm_shuffle_ps(*(__m128 *)v127, _mm_unpackhi_ps(*(__m128 *)v127, v190), 196);
            *(__m128 *)&v127[16] = _mm_shuffle_ps(
                                     *(__m128 *)&v127[16],
                                     _mm_unpackhi_ps(
                                       *(__m128 *)&v127[16],
                                       _mm_mul_ps(
                                         _mm_shuffle_ps((__m128)sizeOfAllAtomsl, (__m128)sizeOfAllAtomsl, 0),
                                         v190)),
                                     196);
            *(__m128 *)&v127[32] = _mm_shuffle_ps(
                                     *(__m128 *)&v127[32],
                                     _mm_unpackhi_ps(
                                       *(__m128 *)&v127[32],
                                       _mm_sub_ps(
                                         query.m_quad,
                                         _mm_mul_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(_mm_shuffle_ps(v188, v188, 85), _mm_shuffle_ps(v188, v188, 0)),
                                             _mm_shuffle_ps(v188, v188, 170)),
                                           (__m128)xmmword_141A710D0))),
                                     196);
            *(__m128 *)&v127[48] = _mm_shuffle_ps(
                                     *(__m128 *)&v127[48],
                                     _mm_unpackhi_ps(*(__m128 *)&v127[48], v189),
                                     196);
            *(float *)v127 = *(float *)v127 + 0.00000011920929;
            *v127 = (hkpJacobianSchema)35;
            v7->m_jacobianSchemas.m_storage = v127 + 128;
            v7->m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)((char *)v7->m_constraintRuntime.m_storage
                                                                              + 24);
            v7->m_constraintRuntimeInMainMemory.m_storage = (char *)v7->m_constraintRuntimeInMainMemory.m_storage + 24;
            goto LABEL_236;
          case 0x1Cu:
            if ( *((_BYTE *)v9 + 2) && *((float *)v9 + 2) > 0.0 )
            {
              v708 = (__m128 *)v6->m_bodyB.m_storage;
              v709 = (__m128 *)v6->m_bodyA.m_storage;
              v710.m_quad = (__m128)baseA.m_translation;
              sizeOfAllAtomst = LODWORD(v6->m_virtMassFactor.m_storage);
              v711.m_quad = (__m128)baseA.m_translation;
              v712.m_quad = (__m128)baseA.m_translation;
              v713 = *(&baseB.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 3));
              v714 = *(&baseB.m_rotation.m_col0.m_quad + *((unsigned __int8 *)v9 + 4));
              v715 = (__m128 *)v7->m_jacobianSchemas.m_storage;
              v716 = _mm_shuffle_ps(v713, v713, 201);
              *v715 = v713;
              v717 = _mm_sub_ps(v712.m_quad, v708[7]);
              v718 = _mm_sub_ps(v711.m_quad, v709[7]);
              v719 = _mm_sub_ps(_mm_mul_ps(v718, v716), _mm_mul_ps(_mm_shuffle_ps(v718, v718, 201), v713));
              v720 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v717, v717, 201), v713), _mm_mul_ps(v717, v716));
              v721 = _mm_shuffle_ps(v720, v720, 201);
              v722 = _mm_shuffle_ps(v719, v719, 201);
              v715[1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v722, v722, 0), v709[4]),
                            _mm_mul_ps(_mm_shuffle_ps(v722, v722, 85), v709[5])),
                          _mm_mul_ps(_mm_shuffle_ps(v722, v722, 170), v709[6]));
              v723 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v721, v721, 85), v708[5]),
                         _mm_mul_ps(_mm_shuffle_ps(v721, v721, 0), v708[4])),
                       _mm_mul_ps(_mm_shuffle_ps(v721, v721, 170), v708[6]));
              v715[2] = v723;
              v724 = v709[3];
              v725 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v715[1], v715[1]), v724),
                       _mm_mul_ps(_mm_mul_ps(v723, v723), v708[3]));
              v726 = _mm_shuffle_ps(
                       v725,
                       _mm_unpackhi_ps(v725, _mm_max_ps(_mm_add_ps(v724, v708[3]), (__m128)xmmword_141A712D0)),
                       196);
              v727 = _mm_add_ps(_mm_shuffle_ps(v726, v726, 78), v726);
              v884 = _mm_add_ps(_mm_shuffle_ps(v727, v727, 177), v727);
              v715[2] = _mm_shuffle_ps(v715[2], _mm_unpackhi_ps(v715[2], v884), 196);
              v728 = _mm_rcp_ps(v884);
              v729 = _mm_shuffle_ps(v714, v714, 201);
              v973 = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)sizeOfAllAtomst, (__m128)sizeOfAllAtomst, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v728, v884)), v728));
              v715[1] = _mm_shuffle_ps(v715[1], _mm_unpackhi_ps(v715[1], v973), 196);
              *((float *)&v715->m128_u64[1] + 1) = v6->m_frictionRhsFactor.m_storage * 0.0;
              v727.m128_i32[0] = LODWORD(v6->m_virtMassFactor.m_storage);
              v715[3] = v714;
              v730 = _mm_sub_ps(v710.m_quad, v709[7]);
              v731 = _mm_sub_ps(v710.m_quad, v708[7]);
              sizeOfAllAtomsu = v727.m128_i32[0];
              v732 = _mm_sub_ps(_mm_mul_ps(v729, v730), _mm_mul_ps(_mm_shuffle_ps(v730, v730, 201), v714));
              v733 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v731, v731, 201), v714), _mm_mul_ps(v729, v731));
              v734 = _mm_shuffle_ps(v732, v732, 201);
              v735 = _mm_shuffle_ps(v733, v733, 201);
              v715[4] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v734, v734, 0), v709[4]),
                            _mm_mul_ps(_mm_shuffle_ps(v734, v734, 85), v709[5])),
                          _mm_mul_ps(_mm_shuffle_ps(v734, v734, 170), v709[6]));
              v736 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v735, v735, 85), v708[5]),
                         _mm_mul_ps(_mm_shuffle_ps(v735, v735, 0), v708[4])),
                       _mm_mul_ps(_mm_shuffle_ps(v735, v735, 170), v708[6]));
              v715[5] = v736;
              v737 = v709[3];
              v738 = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(v715[4], v715[4]), v737),
                       _mm_mul_ps(_mm_mul_ps(v736, v736), v708[3]));
              v739 = _mm_shuffle_ps(
                       v738,
                       _mm_unpackhi_ps(v738, _mm_max_ps(_mm_add_ps(v737, v708[3]), (__m128)xmmword_141A712D0)),
                       196);
              v740 = _mm_add_ps(_mm_shuffle_ps(v739, v739, 78), v739);
              v885 = _mm_add_ps(_mm_shuffle_ps(v740, v740, 177), v740);
              v715[5] = _mm_shuffle_ps(v715[5], _mm_unpackhi_ps(v715[5], v885), 196);
              v741 = _mm_rcp_ps(v885);
              v807 = 1065353216;
              v933 = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)sizeOfAllAtomsu, (__m128)sizeOfAllAtomsu, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v741, v885)), v741));
              v715[4] = _mm_shuffle_ps(v715[4], _mm_unpackhi_ps(v715[4], v933), 196);
              v715[3].m128_f32[3] = v6->m_frictionRhsFactor.m_storage * 0.0;
              sizeOfAllAtomsv = LODWORD(v6->m_virtMassFactor.m_storage);
              v742 = _mm_mul_ps(*v715, v715[3]);
              v743 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v709[3], v709[3], 255), v742),
                         _mm_mul_ps(_mm_shuffle_ps(v708[3], v708[3], 255), v742)),
                       _mm_add_ps(
                         _mm_mul_ps(_mm_mul_ps(v715[5], v715[2]), v708[3]),
                         _mm_mul_ps(_mm_mul_ps(v715[4], v715[1]), v709[3])));
              v744 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v743, v743, 85), _mm_shuffle_ps(v743, v743, 0)),
                       _mm_shuffle_ps(v743, v743, 170));
              v745 = _mm_shuffle_ps(v715[5], v715[5], 255);
              v746 = _mm_mul_ps(v744, _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0));
              v747 = _mm_shuffle_ps(v715[2], v715[2], 255);
              v748 = _mm_sub_ps(_mm_mul_ps(v745, v747), _mm_mul_ps(v746, v746));
              v749 = _mm_rcp_ps(v748);
              v934 = v748;
              v863 = _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v749, v748)), v749),
                       _mm_shuffle_ps((__m128)sizeOfAllAtomsv, (__m128)sizeOfAllAtomsv, 0));
              v715[2] = _mm_shuffle_ps(v715[2], _mm_unpackhi_ps(v715[2], _mm_mul_ps(v745, v863)), 196);
              v715[5] = _mm_shuffle_ps(v715[5], _mm_unpackhi_ps(v715[5], _mm_mul_ps(v747, v863)), 196);
              v715 += 7;
              v740.m128_f32[0] = v6->m_microStepDeltaTime.m_storage * *((float *)v9 + 2);
              v749.m128_f32[0] = (float)(0.0 - v746.m128_f32[0]) * v863.m128_f32[0];
              v715[-1].m128_u64[1] = (unsigned __int64)v9;
              v715[-1].m128_i32[0] = v749.m128_i32[0];
              v715[-1].m128_i32[1] = v740.m128_i32[0];
              v715[-7].m128_f32[0] = v715[-7].m128_f32[0] + 0.00000011920929;
              v715[-7].m128_i8[0] = 43;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v715;
            }
            else
            {
              v750 = (signed __int64)&v7->m_jacobianSchemas.m_storage[16];
              *(float *)(v750 - 16) = *(float *)v7->m_jacobianSchemas.m_storage + 0.00000011920929;
              *(_BYTE *)(v750 - 16) = 3;
              *(_BYTE *)(v750 - 12) = 0;
              v7->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v750;
            }
            goto LABEL_235;
          case 0x1Eu:
            v7->m_jacobianSchemas.m_storage -= 32;
            v1019.m_beginConstraints = hkpBeginConstraints;
            v756 = *((float *)v9 + 12);
            hkpConstraintQueryIn::operator=(&v1019, v6);
            v757 = v9;
            v1019.m_virtMassFactor.m_storage = v756 * v6->m_virtMassFactor.m_storage;
            v1019.m_tau.m_storage = v756 * v6->m_tau.m_storage;
            v1019.m_damping.m_storage = v756 * v6->m_damping.m_storage;
            atomf = v9[9];
            do
              v757 = (unsigned __int16 *)*((_QWORD *)v757 + 3);
            while ( *v757 >= 0x1Eu );
            v758 = v757[2];
            v759 = *((unsigned __int8 *)v757 + 10);
            v760 = 0i64;
            v761 = (signed __int64)&v757[16 * v757[3] + 24];
            if ( v758 >= 4 )
            {
              v762 = *((unsigned __int8 *)v757 + 10);
              v763 = (float *)(v757 + 54);
              v764 = ((unsigned __int64)(v758 - 4) >> 2) + 1;
              v760 = 4 * v764;
              do
              {
                v765 = (float)((float)((float)(v6->m_microStepDeltaTime.m_storage * *((float *)v9 + 13))
                                     * v6->m_subStepDeltaTime.m_storage)
                             / *((float *)v9 + 12))
                     + *(v763 - 8);
                if ( v765 < *(float *)(v761 + 24) )
                  *(float *)(v761 + 24) = v765;
                v766 = v762 + v761;
                v767 = (float)((float)((float)(v6->m_microStepDeltaTime.m_storage * *((float *)v9 + 13))
                                     * v6->m_subStepDeltaTime.m_storage)
                             / *((float *)v9 + 12))
                     + *v763;
                if ( v767 < *(float *)(v766 + 24) )
                  *(float *)(v766 + 24) = v767;
                v768 = v762 + v766;
                v769 = (float)((float)((float)(v6->m_microStepDeltaTime.m_storage * *((float *)v9 + 13))
                                     * v6->m_subStepDeltaTime.m_storage)
                             / *((float *)v9 + 12))
                     + v763[8];
                if ( v769 < *(float *)(v768 + 24) )
                  *(float *)(v768 + 24) = v769;
                v770 = v762 + v768;
                v771 = (float)((float)((float)(v6->m_microStepDeltaTime.m_storage * *((float *)v9 + 13))
                                     * v6->m_subStepDeltaTime.m_storage)
                             / *((float *)v9 + 12))
                     + v763[16];
                if ( v771 < *(float *)(v770 + 24) )
                  *(float *)(v770 + 24) = v771;
                v761 = v762 + v770;
                v763 += 32;
                --v764;
              }
              while ( v764 );
              v759 = v762;
            }
            if ( v760 < v758 )
            {
              v772 = (float *)(v761 + 24);
              v773 = (float *)&v757[16 * v760 + 38];
              v774 = v758 - v760;
              do
              {
                v775 = (float)((float)((float)(v6->m_microStepDeltaTime.m_storage * *((float *)v9 + 13))
                                     * v6->m_subStepDeltaTime.m_storage)
                             / *((float *)v9 + 12))
                     + *v773;
                if ( v775 < *v772 )
                  *v772 = v775;
                v772 = (float *)((char *)v772 + v759);
                v773 += 8;
                --v774;
              }
              while ( v774 );
            }
            v776 = (hkpSimpleContactConstraintAtom *)*((_QWORD *)v9 + 3);
            if ( v776->m_type.m_storage == 29 )
              hkSimpleContactConstraintDataBuildJacobian(v776, &v1019, (hkBool)1, v7);
            else
              hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v776->m_type, atomf, &v1019, v7);
            v8 = v790;
            v9 += 32;
            goto LABEL_236;
          case 0x1Fu:
            *(_OWORD *)&v908.m_subStepDeltaTime.m_storage = *(_OWORD *)&v6->m_subStepDeltaTime.m_storage;
            *(_OWORD *)&v908.m_frameInvDeltaTime.m_storage = *(_OWORD *)&v6->m_frameInvDeltaTime.m_storage;
            *(_OWORD *)&v908.m_rhsFactor.m_storage = *(_OWORD *)&v6->m_rhsFactor.m_storage;
            *(_OWORD *)&v908.m_bodyA.m_storage = *(_OWORD *)&v6->m_bodyA.m_storage;
            *(_OWORD *)&v908.m_transformA.m_storage = *(_OWORD *)&v6->m_transformA.m_storage;
            *(_OWORD *)&v908.m_tau.m_storage = *(_OWORD *)&v6->m_tau.m_storage;
            v908.m_maxConstraintViolationSqrd = v6->m_maxConstraintViolationSqrd;
            *(_OWORD *)&v908.m_constraintInstance.m_storage = *(_OWORD *)&v6->m_constraintInstance.m_storage;
            *(_OWORD *)&v908.m_accumulatorAIndex.m_storage = *(_OWORD *)&v6->m_accumulatorAIndex.m_storage;
            v779 = *((__m128 *)v9 + 3);
            v780 = *((__m128 *)v9 + 4);
            atomg = (hkpSimpleContactConstraintAtom *)*((_QWORD *)v9 + 3);
            sizeOfAllAtomse = v9[9];
            v781 = v6->m_bodyA.m_storage;
            v918 = *(_OWORD *)&v781->m_type.m_storage;
            v919.m_quad = (__m128)v781->m_linearVel;
            v920.m_quad = (__m128)v781->m_angularVel;
            invMassA.m_quad = (__m128)v781->m_invMasses;
            v922.m_quad = (__m128)v781->m_scratch0;
            v923.m_quad = (__m128)v781->m_scratch1;
            v924.m_quad = (__m128)v781->m_scratch2;
            v925.m_quad = (__m128)v781->m_scratch3;
            v782 = v6->m_bodyB.m_storage;
            v910 = *(_OWORD *)&v782->m_type.m_storage;
            v911.m_quad = (__m128)v782->m_linearVel;
            v912.m_quad = (__m128)v782->m_angularVel;
            invMassB.m_quad = (__m128)v782->m_invMasses;
            v914.m_quad = (__m128)v782->m_scratch0;
            v915.m_quad = (__m128)v782->m_scratch1;
            v916.m_quad = (__m128)v782->m_scratch2;
            v783 = (__int128)v782->m_scratch3;
            invMassA.m_quad = _mm_mul_ps(invMassA.m_quad, v779);
            v908.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v918;
            v908.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v910;
            v917 = v783;
            invMassB.m_quad = _mm_mul_ps(invMassB.m_quad, v780);
            hkSetInvMassBuildJacobian(&invMassA, &invMassB, v7);
            if ( atomg->m_type.m_storage == 29 )
              hkSimpleContactConstraintDataBuildJacobian(atomg, &v908, (hkBool)1, v7);
            else
              hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&atomg->m_type, sizeOfAllAtomse, &v908, v7);
            hkSetInvMassBuildJacobian(&v6->m_bodyA.m_storage->m_invMasses, &v6->m_bodyB.m_storage->m_invMasses, v7);
            v8 = v790;
            v9 += 40;
            goto LABEL_236;
          case 0x20u:
            v7->m_jacobianSchemas.m_storage -= 32;
            v777 = v9;
            *(_OWORD *)&v931.m_subStepDeltaTime.m_storage = *(_OWORD *)&v6->m_subStepDeltaTime.m_storage;
            *(_OWORD *)&v931.m_frameInvDeltaTime.m_storage = *(_OWORD *)&v6->m_frameInvDeltaTime.m_storage;
            *(_OWORD *)&v931.m_rhsFactor.m_storage = *(_OWORD *)&v6->m_rhsFactor.m_storage;
            *(_OWORD *)&v931.m_bodyA.m_storage = *(_OWORD *)&v6->m_bodyA.m_storage;
            *(_OWORD *)&v931.m_transformA.m_storage = *(_OWORD *)&v6->m_transformA.m_storage;
            *(_OWORD *)&v931.m_tau.m_storage = *(_OWORD *)&v6->m_tau.m_storage;
            v931.m_maxConstraintViolationSqrd = v6->m_maxConstraintViolationSqrd;
            *(_OWORD *)&v931.m_constraintInstance.m_storage = *(_OWORD *)&v6->m_constraintInstance.m_storage;
            *(_OWORD *)&v931.m_accumulatorAIndex.m_storage = *(_OWORD *)&v6->m_accumulatorAIndex.m_storage;
            sizeOfAllAtomsd = v9[9];
            do
              v777 = (unsigned __int16 *)*((_QWORD *)v777 + 3);
            while ( *v777 >= 0x1Eu );
            hkSimpleContactConstraintDataAddALittleSurfaceViscosity((hkpSimpleContactConstraintDataInfo *)(v777 + 8));
            v778 = (hkpSimpleContactConstraintAtom *)*((_QWORD *)v9 + 3);
            if ( v778->m_type.m_storage == 29 )
              hkSimpleContactConstraintDataBuildJacobian(v778, &v931, (hkBool)1, v7);
            else
              hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v778->m_type, sizeOfAllAtomsd, &v931, v7);
            v8 = v790;
            goto LABEL_235;
          case 0x21u:
            v784 = *((__m128 *)v9 + 3);
            *(_OWORD *)&v929.m_subStepDeltaTime.m_storage = *(_OWORD *)&v6->m_subStepDeltaTime.m_storage;
            *(_OWORD *)&v929.m_frameInvDeltaTime.m_storage = *(_OWORD *)&v6->m_frameInvDeltaTime.m_storage;
            *(_OWORD *)&v929.m_rhsFactor.m_storage = *(_OWORD *)&v6->m_rhsFactor.m_storage;
            *(_OWORD *)&v929.m_bodyA.m_storage = *(_OWORD *)&v6->m_bodyA.m_storage;
            *(_OWORD *)&v929.m_transformA.m_storage = *(_OWORD *)&v6->m_transformA.m_storage;
            *(_OWORD *)&v929.m_tau.m_storage = *(_OWORD *)&v6->m_tau.m_storage;
            v929.m_maxConstraintViolationSqrd = v6->m_maxConstraintViolationSqrd;
            *(_OWORD *)&v929.m_constraintInstance.m_storage = *(_OWORD *)&v6->m_constraintInstance.m_storage;
            *(_OWORD *)&v929.m_accumulatorAIndex.m_storage = *(_OWORD *)&v6->m_accumulatorAIndex.m_storage;
            v785 = (hkpSimpleContactConstraintAtom *)*((_QWORD *)v9 + 3);
            v7->m_jacobianSchemas.m_storage -= 32;
            atomh = v785;
            hkInitHeader(
              v6,
              (hkpSolverResults *)&v785[1] + 4 * v785->m_numReservedContactPoints,
              (unsigned __int8)v785->m_contactPointPropertiesStriding,
              v7);
            v786 = v6->m_accumulatorAIndex.m_storage == 0;
            if ( v6->m_accumulatorAIndex.m_storage )
            {
              hkpVelocityAccumulator::operator=(&v1020, v6->m_bodyA.m_storage);
              v929.m_bodyA.m_storage = &v1020;
            }
            else
            {
              hkpVelocityAccumulator::operator=(&v1020, v6->m_bodyB.m_storage);
              v929.m_bodyB.m_storage = &v1020;
              v784 = _mm_xor_ps(v784, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
            }
            v787 = _mm_mul_ps(*(__m128 *)&atomh[1].m_info.m_flags, v784);
            v788 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
            deltaVel.m_quad = _mm_xor_ps(
                                _mm_sub_ps(
                                  v784,
                                  _mm_mul_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v787, v787, 85), _mm_shuffle_ps(v787, v787, 0)),
                                      _mm_shuffle_ps(v787, v787, 170)),
                                    *(__m128 *)&atomh[1].m_info.m_flags)),
                                v788);
            hkAddVelocityBuildJacobian(&deltaVel, v786, v1058);
            v1020.m_linearVel.m_quad = _mm_add_ps(v1020.m_linearVel.m_quad, deltaVel.m_quad);
            hkSimpleContactConstraintDataBuildJacobian(atomh, &v929, 0, v1058);
            deltaVel.m_quad = _mm_xor_ps(deltaVel.m_quad, v788);
            hkAddVelocityBuildJacobian(&deltaVel, v786, v1058);
            v7 = v1058;
            v8 = v790;
            v9 += 32;
            goto LABEL_236;
          case 0x22u:
            v7->m_jacobianSchemas.m_storage -= 32;
LABEL_235:
            v9 += 24;
            goto LABEL_236;
          case 0x23u:
            *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = *(_OWORD *)&v6->m_subStepDeltaTime.m_storage;
            *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = *(_OWORD *)&v6->m_frameInvDeltaTime.m_storage;
            *(_OWORD *)&ina.m_rhsFactor.m_storage = *(_OWORD *)&v6->m_rhsFactor.m_storage;
            *(_OWORD *)&ina.m_bodyA.m_storage = *(_OWORD *)&v6->m_bodyA.m_storage;
            *(_OWORD *)&ina.m_transformA.m_storage = *(_OWORD *)&v6->m_transformA.m_storage;
            *(_OWORD *)&ina.m_tau.m_storage = *(_OWORD *)&v6->m_tau.m_storage;
            ina.m_maxConstraintViolationSqrd = v6->m_maxConstraintViolationSqrd;
            *(_OWORD *)&ina.m_constraintInstance.m_storage = *(_OWORD *)&v6->m_constraintInstance.m_storage;
            *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = *(_OWORD *)&v6->m_accumulatorAIndex.m_storage;
            v751 = *((__m128 *)v9 + 3);
            atome = (hkpSimpleContactConstraintAtom *)*((_QWORD *)v9 + 3);
            sizeOfAllAtomsc = v9[9];
            r.m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(v751, v751, 85),
                             v6->m_transformA.m_storage->m_rotation.m_col1.m_quad),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v751, v751, 0),
                             v6->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(v751, v751, 170),
                           v6->m_transformA.m_storage->m_rotation.m_col2.m_quad));
            v752 = *((__m128 *)v9 + 4);
            v887.m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_shuffle_ps(v752, v752, 85),
                                v6->m_transformB.m_storage->m_rotation.m_col1.m_quad),
                              _mm_mul_ps(
                                _mm_shuffle_ps(*((__m128 *)v9 + 4), v752, 0),
                                v6->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v752, v752, 170),
                              v6->m_transformB.m_storage->m_rotation.m_col2.m_quad));
            v753 = v6->m_bodyA.m_storage;
            v894 = *(_OWORD *)&v753->m_type.m_storage;
            v895 = v753->m_linearVel.m_quad;
            v896 = v753->m_angularVel.m_quad;
            v897.m_quad = (__m128)v753->m_invMasses;
            cTb.m_col0 = v753->m_scratch0;
            cTb.m_col1 = v753->m_scratch1;
            cTb.m_col2 = v753->m_scratch2;
            v899 = v753->m_scratch3.m_quad;
            v754 = v6->m_bodyB.m_storage;
            v900 = *(_OWORD *)&v754->m_type.m_storage;
            v901 = v754->m_linearVel.m_quad;
            v902 = v754->m_angularVel.m_quad;
            v903.m_quad = (__m128)v754->m_invMasses;
            v904.m_col0 = v754->m_scratch0;
            v904.m_col1 = v754->m_scratch1;
            v904.m_col2 = v754->m_scratch2;
            v755 = _mm_add_ps(v754->m_scratch3.m_quad, v887.m_quad);
            ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v894;
            v899 = _mm_add_ps(v899, r.m_quad);
            v905 = v755;
            ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v900;
            hkMatrix3f::setCrossSkewSymmetric(&v868, &r);
            hkMatrix3f::setCrossSkewSymmetric(&v866, &v887);
            aTb = v868;
            hkMatrix3f::setMulInverse(&v868, &aTb, &cTb);
            aTb = v866;
            hkMatrix3f::setMulInverse(&v866, &aTb, &v904);
            scale.m_real = g_vectorfConstants[0];
            angToLinVelA.m_col1 = v868.m_col1;
            angToLinVelA.m_col0 = v868.m_col0;
            angToLinVelA.m_col2 = v868.m_col2;
            hkMatrix3f::mul(&angToLinVelA, &scale);
            angToLinVelB = v866;
            hkMatrix3f::mul(&angToLinVelB, &scale);
            v895 = _mm_add_ps(
                     v895,
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v896, v896, 85), angToLinVelA.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v896, v896, 0), angToLinVelA.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v896, v896, 170), angToLinVelA.m_col2.m_quad)));
            v901 = _mm_add_ps(
                     v901,
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v902, v902, 85), angToLinVelB.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v902, v902, 0), angToLinVelB.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v902, v902, 170), angToLinVelB.m_col2.m_quad)));
            hkSetCenterOfMassBuildJacobian(&angToLinVelA, &angToLinVelB, v7);
            if ( atome->m_type.m_storage == 29 )
              hkSimpleContactConstraintDataBuildJacobian(atome, &ina, (hkBool)1, v7);
            else
              hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&atome->m_type, sizeOfAllAtomsc, &ina, v7);
            hkSetCenterOfMassBuildJacobian(&v868, &v866, v7);
            v8 = v790;
            v9 += 40;
            goto LABEL_236;
          default:
            goto LABEL_237;
        }
        break;
      }
    }
  }
}k;
      }
    }
  }
}nsformA.m_storage->m_rotation.m_col1.m_quad),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v751, v751, 0),
                             v6->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(v751, v751, 170),
                           v6->m_transformA.m_storage->m_rotation.m_col2.m_quad));
            v752 = *((__m128 *)v9 + 4);
            v887.m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_shuffle_ps(v752, v752, 85),
                                v6->m_transformB.m_storage->m_rotation.m_col1.m_quad),
                              _mm_mul_ps(
                                _mm_shuffle_ps(*((__m128 *)v9 + 4), v752, 0),
                                v6->m_transformB.m_storage->m_rotation.m_col0.m_quad)),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v752, v752, 170),
                              v6->m_transformB.m_storage->m_rotation.m_col2.m_quad));
            v753 = v6->m_bodyA.m_storage;
            v894 = *(_OWORD *)&v753->m_type.m_storage;
            v895 = v753->m_linearVel.m_quad;
            v896 = v753->m_angularVel.m_quad;
            v897.m_quad = (__m128)v753->m_invMasses;
            cTb.m_col0 = v753->m_scratch0;
            cTb.m_col1 = v753->m_scratch1;
            cTb.m_col2 = v753->m_scratch2;
            v899 = v753->m_scratch3.m_quad;
            v754 = v6->m_bodyB.m_storage;
            v900 = *(_OWORD *)&v754->m_type.m_storage;
            v901 = v754->m_linearVel.m_quad;
            v902 = v754->m_angularVel.m_quad;
            v903.m_quad = (__m128)v754->m_invMasses;
            v904.m_col0 = v754->m_scratch0;
            v904.m_col1 = v754->m_scratch1;
            v904.m_col2 = v754->m_scratch2;
            v755 = _mm_add_ps(v754->m_scratch3.m_quad, v887.m_quad);
            ina.m_bodyA.m_storage = (hkpVelocityAccumulator *)&v894;
            v899 = _mm_add_ps(v899, r.m_quad);
            v905 = v755;
            ina.m_bodyB.m_storage = (hkpVelocityAccumulator *)&v900;
            hkMatrix3f::setCrossSkewSymmetric(&v868, &r);
            hkMatrix3f::setCrossSkewSymmetric(&v866, &v887);
            aTb = v868;
            hkMatrix3f::setMulInverse(&v868, &aTb, &cTb);
            aTb = v866;
            hkMatrix3f::setMulInverse(&v866, &aTb, &v904);
            scale.m_real = g_vectorfConstants[0];
            angToLinVelA.m_col1 = v868.m_col1;
            angToLinVelA.m_col0 = v868.m_col0;
            angToLinVelA.m_col2 = v868.m_col2;
            hkMatrix3f::mul(&angToLinVelA, &scale);
            angToLinVelB = v866;
            hkMatrix3f::mul(&angToLinVelB, &scale);
            v895 = _mm_add_ps(
                     v895,
                     _mm_add_ps(
                       _mm_add_ps(
                    

