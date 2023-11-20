// File Line: 42
// RVA: 0xD97A40
int __fastcall hkpSimpleContactConstraintData::allocateContactPoint(hkpSimpleContactConstraintData *this, hkpConstraintOwner *constraintOwner, hkContactPoint **cpOut, hkpContactPointProperties **cpPropsOut)
{
  hkpSimpleContactConstraintAtom *v4; // rax
  hkpConstraintOwner *v5; // rbp
  hkpSimpleContactConstraintData *v6; // rbx
  hkpSimpleContactConstraintAtom *v7; // r14
  int v8; // esi
  hkpSimpleContactConstraintAtom *v9; // rcx
  hkpContactPointProperties **v10; // r15
  hkContactPoint **v11; // r12
  hkpSimpleContactConstraintAtom *v12; // rax
  hkpSimpleContactConstraintAtom *v13; // rdi
  signed int v14; // edx
  signed __int64 v15; // r8
  signed __int64 v16; // r10
  int v17; // er9
  signed __int64 v18; // rax
  signed int v19; // er8
  signed int v20; // er9
  int v21; // er10
  int v22; // er8
  int v23; // edx
  hkpConstraintInstance *v24; // r11
  int v25; // er9
  int v26; // eax
  hkConstraintInternal *v27; // rcx
  int v28; // ecx
  hkPadSpu<bool> atomReallocated; // [rsp+60h] [rbp+8h]

  v4 = this->m_atom;
  v5 = constraintOwner;
  v6 = this;
  v4->m_info.m_flags |= 4u;
  v7 = this->m_atom;
  v8 = v4->m_numContactPoints;
  v9 = this->m_atom;
  v10 = cpPropsOut;
  v11 = cpOut;
  atomReallocated.m_storage = 0;
  v12 = hkpSimpleContactConstraintAtomUtil::expandOne(v9, &atomReallocated);
  v6->m_atom = v12;
  v13 = v12;
  v14 = 0;
  v15 = 32i64 * v12->m_numReservedContactPoints;
  v16 = (signed __int64)&v12[1] + 32 * (unsigned int)v8;
  LODWORD(v12) = (unsigned __int8)v12->m_contactPointPropertiesStriding;
  v17 = -(signed int)v12;
  v18 = (signed __int64)&v13[1] + v8 * (signed int)v12 + v15;
  *(_QWORD *)v18 = 0i64;
  *(_BYTE *)(v18 + 19) = 1;
  if ( v8 > 0 && !(*(_BYTE *)(v17 + v18 + 19) & 2) && !*(_BYTE *)(v17 + v18 + 18) )
    *(_BYTE *)(v18 + 19) = 3;
  *v11 = (hkContactPoint *)v16;
  *v10 = (hkpContactPointProperties *)v18;
  v19 = 0;
  v20 = 0;
  v21 = 112 * ((v8 + 1) >> 1) + 48 * ((((_BYTE)v8 + 1) & 1) + 4);
  if ( v8 == 1 )
  {
    v14 = 48;
    v19 = 1;
    v20 = 1;
  }
  v22 = v19 + 1;
  if ( ((_BYTE)v8 + 1) & 1 )
    v23 = v14 + 48;
  else
    v23 = v14 + 64;
  v24 = v6->m_constraint;
  v25 = v20 + 1;
  if ( v24->m_internal )
  {
    v26 = v23;
    if ( v5->m_constraintInfo.m_maxSizeOfSchema > v21 )
      v21 = v5->m_constraintInfo.m_maxSizeOfSchema;
    if ( v21 > v23 )
      v26 = v21;
    v5->m_constraintInfo.m_sizeOfSchemas += v23;
    v5->m_constraintInfo.m_numSolverResults += v22;
    v5->m_constraintInfo.m_numSolverElemTemps += v25;
    v5->m_constraintInfo.m_maxSizeOfSchema = v26;
    v27 = v24->m_internal;
    v27->m_sizeOfSchemas += v23;
    v27->m_numSolverResults += v22;
    v27->m_numSolverElemTemps += v25;
    v28 = v24->m_internal->m_sizeOfSchemas;
    if ( v5->m_constraintInfo.m_maxSizeOfSchema > v28 )
      v28 = v5->m_constraintInfo.m_maxSizeOfSchema;
    v5->m_constraintInfo.m_maxSizeOfSchema = v28;
  }
  if ( atomReallocated.m_storage )
  {
    hkpWorldConstraintUtil::updateFatherOfMovedAtom(
      v6->m_constraint,
      (hkpConstraintAtom *)&v7->m_type,
      (hkpConstraintAtom *)&v6->m_atom->m_type,
      v13->m_sizeOfAllAtoms);
    v6->m_atomSize = v13->m_sizeOfAllAtoms;
  }
  return hkpDynamicsCpIdMgr::newId(&v6->m_idMgrA, v8);
}

// File Line: 113
// RVA: 0xD97FE0
void __fastcall hkpSimpleContactConstraintData::hkpSimpleContactConstraintData(hkpSimpleContactConstraintData *this, hkpConstraintInstance *constraint, hkpRigidBody *bodyA, hkpRigidBody *bodyB)
{
  hkpSimpleContactConstraintData *v4; // rbx
  hkpSimpleContactConstraintAtom *v5; // rax

  v4 = this;
  this->m_memSizeAndFlags = -1;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleContactConstraintData::`vftable;
  this->m_referenceCount = 1;
  this->m_idMgrA.m_values.m_data = this->m_idMgrA.m_values.m_storage;
  this->m_idMgrA.m_values.m_size = 0;
  this->m_idMgrA.m_values.m_capacityAndFlags = -2147483640;
  this->m_constraint = constraint;
  v5 = hkpSimpleContactConstraintAtomUtil::allocateAtom(
         1,
         (unsigned __int8)bodyA->m_numShapeKeysInContactPointProperties,
         (unsigned __int8)bodyB->m_numShapeKeysInContactPointProperties,
         (unsigned __int16)(0x4000
                          / (signed int)(((4
                                         * ((unsigned __int8)bodyB->m_numShapeKeysInContactPointProperties
                                          + (unsigned __int8)bodyA->m_numShapeKeysInContactPointProperties)
                                         + 35) & 0xFFFFFFFC)
                                       + 32)));
  v4->m_atom = v5;
  *(_DWORD *)&v5->m_info.m_flags = 196608;
  v5->m_info.m_contactRadius = 0.0;
  *(_DWORD *)&v5->m_info.m_internalData1.m_value = 0;
  v5->m_info.m_rhsRolling[1].m_value = 0;
  v5->m_info.m_rollingFrictionMultiplier.m_value = 0;
  *(_QWORD *)v5->m_info.m_data = 0i64;
  *(_QWORD *)&v5->m_info.m_data[2] = 0i64;
  v4->m_atomSize = v4->m_atom->m_sizeOfAllAtoms;
}

// File Line: 135
// RVA: 0xD97BF0
void __fastcall hkpSimpleContactConstraintData::getConstraintInfo(hkpSimpleContactConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::ConstraintInfo *v2; // r9
  unsigned int v3; // er8
  hkpSimpleContactConstraintAtom *v4; // r10
  signed int v5; // edx
  int v6; // eax
  int v7; // eax

  v2 = infoOut;
  infoOut->m_atoms = (hkpConstraintAtom *)&this->m_atom->m_type;
  v3 = this->m_atom->m_sizeOfAllAtoms;
  *(_QWORD *)&infoOut->m_maxSizeOfSchema = 0i64;
  *(_QWORD *)&infoOut->m_numSolverResults = 0i64;
  infoOut->m_sizeOfAllAtoms = v3;
  v4 = this->m_atom;
  v5 = v4->m_numContactPoints;
  v6 = (v4->m_numContactPoints & 1) + 3;
  v2->m_numSolverElemTemps = v5 + 3;
  v7 = 48 * v6 + 112 * (v5 >> 1);
  v2->m_sizeOfSchemas = v7;
  v2->m_numSolverResults = v5 + 2;
  v2->m_maxSizeOfSchema = v7 + 48;
  if ( v5 >= 2 )
  {
    v2->m_sizeOfSchemas = v7 + 48;
    v2->m_numSolverResults = v5 + 3;
    v2->m_numSolverElemTemps = v5 + 4;
  }
  if ( COERCE_FLOAT(v4->m_info.m_rollingFrictionMultiplier.m_value << 16) != 0.0 )
  {
    v2->m_sizeOfSchemas += 96;
    v2->m_numSolverResults += 2;
    v2->m_numSolverElemTemps += 3;
    v2->m_maxSizeOfSchema = v7 + 144;
  }
}

// File Line: 144
// RVA: 0xD97CA0
void __fastcall hkpSimpleContactConstraintData::getRuntimeInfo(hkpSimpleContactConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  *infoOut = 0i64;
}

// File Line: 151
// RVA: 0xD97CB0
hkpSolverResults *__fastcall hkpSimpleContactConstraintData::getSolverResults(hkpSimpleContactConstraintData *this, struct hkpConstraintRuntime *runtime)
{
  return 0i64;
}

// File Line: 157
// RVA: 0xD97FD0
hkpSimpleConstraintContactMgr *__fastcall hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(hkpSimpleContactConstraintData *this)
{
  return (hkpSimpleConstraintContactMgr *)this[-1].m_idMgrA.m_values.m_storage;
}

// File Line: 192
// RVA: 0xD980A0
void __fastcall hkSimpleContactConstraintData_fireCallbacks(hkpSimpleContactConstraintData *constraintData, hkpConstraintQueryIn *in, hkpSimpleContactConstraintAtom *atom, hkpContactPointEvent::Type type)
{
  hkpSimpleContactConstraintAtom *v4; // rdi
  hkpConstraintQueryIn *v5; // r13
  hkpSimpleConstraintContactMgr *v6; // rax
  hkpRigidBody *v7; // r15
  hkpRigidBody *v8; // r14
  hkpWorld *v9; // r8
  hkpVelocityAccumulator *v10; // r9
  hkpVelocityAccumulator *v11; // r10
  bool v12; // bl
  hkpSimpleConstraintContactMgr *v13; // rdx
  hkContactPoint *v14; // r12
  signed __int64 v15; // rsi
  __int64 v16; // rcx
  int v17; // eax
  int v18; // edi
  bool v19; // zf
  __m128 v20; // xmm3
  hkpModifierConstraintAtom *v21; // rax
  unsigned int v22; // ST60_4
  __m128 v23; // xmm6
  float v24; // xmm0_4
  hkpVelocityAccumulator *bodyB; // ST30_8
  hkContactPoint *cp; // ST28_8
  hkpConstraintInstance *v27; // rax
  __m128 v28; // xmm2
  float v29; // xmm1_4
  hkpWorld *world; // [rsp+40h] [rbp-C0h]
  hkpSimpleConstraintContactMgr *v31; // [rsp+48h] [rbp-B8h]
  hkpVelocityAccumulator *v32; // [rsp+50h] [rbp-B0h]
  hkpVelocityAccumulator *v33; // [rsp+58h] [rbp-A8h]
  signed __int64 v34; // [rsp+60h] [rbp-A0h]
  __int64 v35; // [rsp+68h] [rbp-98h]
  hkpContactPointEvent event; // [rsp+80h] [rbp-80h]
  hkpSimpleConstraintUtilCollideParams params; // [rsp+F0h] [rbp-10h]
  hkpConstraintInstance *v38; // [rsp+110h] [rbp+10h]
  hkSimdFloat32 result; // [rsp+120h] [rbp+20h]
  hkpContactImpulseLimitBreachedListenerInfo breachedContacts; // [rsp+140h] [rbp+40h]
  hkpSimpleContactConstraintData *constraintDataa; // [rsp+1D0h] [rbp+D0h]
  int v42; // [rsp+1D8h] [rbp+D8h]
  unsigned int v43; // [rsp+1E0h] [rbp+E0h]
  hkpContactPointEvent::Type v44; // [rsp+1E8h] [rbp+E8h]

  v44 = type;
  constraintDataa = constraintData;
  v4 = atom;
  v5 = in;
  v38 = in->m_constraintInstance.m_storage;
  v6 = hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(constraintData);
  v7 = (hkpRigidBody *)v38->m_entities[0];
  v8 = (hkpRigidBody *)v38->m_entities[1];
  v9 = v7->m_world;
  v10 = v5->m_bodyA.m_storage;
  v11 = v5->m_bodyB.m_storage;
  v12 = (v38->m_internal->m_callbackRequest & 8) != 0;
  v13 = v6;
  v31 = v6;
  v14 = (hkContactPoint *)&v4[1];
  world = v7->m_world;
  v15 = (signed __int64)&v4[1] + 32 * v4->m_numReservedContactPoints;
  v16 = (unsigned __int8)v4->m_contactPointPropertiesStriding;
  v17 = v4->m_numContactPoints - 1;
  v32 = v5->m_bodyA.m_storage;
  v33 = v5->m_bodyB.m_storage;
  v34 = 0i64;
  v42 = v17;
  v18 = v4->m_numContactPoints - 1;
  if ( v17 >= 0 )
  {
    v35 = v16;
    while ( !(*(_BYTE *)(v15 + 19) & 1) )
    {
      if ( !v12 )
        goto LABEL_27;
      event.m_contactMgr = v13;
      event.m_type = v44;
      _mm_store_si128((__m128i *)&event.m_separatingVelocity, (__m128i)0i64);
      event.m_lastCallbackForFullManifold.m_bool = v18 == 0;
      event.m_firstCallbackForFullManifold.m_bool = v18 == v17;
      event.m_source = 2;
      event.m_bodies[0] = v7;
      event.m_bodies[1] = v8;
      event.m_shapeKeyStorage = (unsigned int *)(v15 + 32);
      event.m_contactPoint = v14;
      event.m_contactPointProperties = (hkpContactPointProperties *)v15;
      event.m_firingCallbacksForFullManifold.m_bool = 1;
      event.m_accumulators[0] = v10;
      event.m_accumulators[1] = v11;
      hkpWorldCallbackUtil::fireContactPointCallback(v9, &event);
      v19 = v7->m_contactListeners.m_size == 0;
      event.m_source = 0;
      if ( !v19 )
        hkpEntityCallbackUtil::fireContactPointCallbackInternal((hkpEntity *)&v7->vfptr, &event);
      v19 = v8->m_contactListeners.m_size == 0;
      event.m_source = 1;
      if ( !v19 )
        hkpEntityCallbackUtil::fireContactPointCallbackInternal((hkpEntity *)&v8->vfptr, &event);
      v17 = v42;
      v9 = world;
      v10 = v32;
      v11 = v33;
      if ( v18 < v42 )
      {
        v13 = v31;
        v16 = v35;
        if ( *(_BYTE *)(v34 + 18) )
          *(_BYTE *)(v15 + 19) &= 0xFDu;
        goto LABEL_27;
      }
LABEL_26:
      v16 = v35;
      v13 = v31;
LABEL_27:
      v34 = v15;
      ++v14;
      v15 += v16;
      if ( --v18 < 0 )
        goto LABEL_28;
    }
    hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
      &result,
      v7,
      v8,
      &v5->m_bodyA.m_storage->m_scratch3,
      &v5->m_bodyB.m_storage->m_scratch3,
      v14);
    event.m_contactMgr = v31;
    v43 = result.m_real.m128_i32[0];
    event.m_lastCallbackForFullManifold.m_bool = v18 == 0;
    event.m_firstCallbackForFullManifold.m_bool = v18 == v42;
    event.m_separatingVelocity = (float *)&v43;
    event.m_type = v44;
    event.m_shapeKeyStorage = (unsigned int *)(v15 + 32);
    event.m_accumulators[0] = v32;
    event.m_source = 2;
    event.m_bodies[0] = v7;
    event.m_bodies[1] = v8;
    event.m_contactPoint = v14;
    event.m_accumulators[1] = v33;
    event.m_contactPointProperties = (hkpContactPointProperties *)v15;
    event.m_firingCallbacksForFullManifold.m_bool = v12;
    event.m_rotateNormal = 0i64;
    hkpWorldCallbackUtil::fireContactPointCallback(world, &event);
    v19 = v7->m_contactListeners.m_size == 0;
    event.m_source = 0;
    if ( !v19 )
      hkpEntityCallbackUtil::fireContactPointCallbackInternal((hkpEntity *)&v7->vfptr, &event);
    v19 = v8->m_contactListeners.m_size == 0;
    event.m_source = 1;
    if ( !v19 )
      hkpEntityCallbackUtil::fireContactPointCallbackInternal((hkpEntity *)&v8->vfptr, &event);
    v20 = _mm_shuffle_ps((__m128)v43, (__m128)v43, 0);
    result.m_real = v20;
    if ( v18 < v42 && *(_BYTE *)(v34 + 18) )
      *(_BYTE *)(v15 + 19) &= 0xFDu;
    v11 = v33;
    v10 = v32;
    if ( !(_mm_movemask_ps(_mm_cmpneqps(v32->m_invMasses.m_quad, (__m128)0i64)) | _mm_movemask_ps(
                                                                                    _mm_cmpneqps(
                                                                                      v33->m_invMasses.m_quad,
                                                                                      (__m128)0i64)))
      || *(_BYTE *)(v15 + 19) & 8
      || (v21 = v31->m_constraint.m_constraintModifiers) != 0i64 && v21->m_type.m_storage == 34 )
    {
      *(_QWORD *)v15 = 0i64;
    }
    else
    {
      v9 = world;
      *(float *)&v22 = (float)*(unsigned __int8 *)(v15 + 17) * 0.0078125;
      v23 = _mm_shuffle_ps((__m128)v22, (__m128)v22, 0);
      if ( v20.m128_f32[0] >= (float)(0.0
                                    - COERCE_FLOAT(
                                        _mm_shuffle_ps(
                                          (__m128)*((unsigned int *)world->m_collisionInput->m_dynamicsInfo + 28),
                                          (__m128)*((unsigned int *)world->m_collisionInput->m_dynamicsInfo + 28),
                                          0)))
        || v23.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3E99999Au, (__m128)0x3E99999Au, 0)) )
      {
        v28 = _mm_add_ps(
                _mm_add_ps(
                  _mm_shuffle_ps(v8->m_motion.m_inertiaAndMassInv.m_quad, v8->m_motion.m_inertiaAndMassInv.m_quad, 255),
                  _mm_shuffle_ps(v7->m_motion.m_inertiaAndMassInv.m_quad, v7->m_motion.m_inertiaAndMassInv.m_quad, 255)),
                _mm_shuffle_ps((__m128)0x2EDBE6FFu, (__m128)0x2EDBE6FFu, 0));
        LODWORD(v29) = (unsigned __int128)_mm_rcp_ps(v28);
        *(float *)v15 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBE4CCCCD, (__m128)0xBE4CCCCD, 0))
                                      * (float)((float)(2.0 - (float)(v29 * v28.m128_f32[0])) * v29))
                              * v20.m128_f32[0])
                      * (float)(v23.m128_f32[0] + 1.0);
        v28.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v20.m128_f32[0])
                                * COERCE_FLOAT(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(v5->m_subStepDeltaTime.m_storage),
                                      (__m128)LODWORD(v5->m_subStepDeltaTime.m_storage),
                                      0)))
                        * COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBFA66666, (__m128)0xBFA66666, 0));
        *(_DWORD *)(v15 + 4) = v28.m128_i32[0];
        *(_DWORD *)(v15 + 24) = COERCE_UNSIGNED_INT(
                                  COERCE_FLOAT(_mm_shuffle_ps(v14->m_separatingNormal.m_quad, v14->m_separatingNormal.m_quad, 255))
                                - v28.m128_f32[0]) & *(unsigned __int128 *)&_mm_cmpltps((__m128)0i64, v23);
LABEL_25:
        *(_BYTE *)(v15 + 19) &= 0xFEu;
        v17 = v42;
        goto LABEL_26;
      }
      v24 = hkContactPointMaterial::getFriction((hkContactPointMaterial *)(v15 + 8));
      v19 = *(_BYTE *)(v15 + 18) == 0;
      *(_QWORD *)&params.m_extraSeparatingVelocity = 0i64;
      LODWORD(params.m_restitution) = v23.m128_i32[0];
      params.m_friction = v24;
      params.m_maxImpulse = 3.40282e38;
      LODWORD(params.m_externalSeperatingVelocity) = result.m_real.m128_i32[0];
      if ( !v19 )
        params.m_maxImpulse = hkContactPointMaterial::getMaxImpulsePerStep((hkContactPointMaterial *)(v15 + 8));
      bodyB = v5->m_bodyB.m_storage;
      cp = (hkContactPoint *)v5->m_bodyA.m_storage;
      hkpSimpleCollisionResponse::solveSingleContact2(constraintDataa, v14, &params, v7);
      if ( params.m_contactImpulseLimitBreached.m_bool )
      {
        v27 = v5->m_constraintInstance.m_storage;
        *(_DWORD *)&breachedContacts.m_data.m_solver.m_type = 65537;
        breachedContacts.m_data.m_solver.m_constraintInstance = v27;
        breachedContacts.m_data.m_single.m_contactPoint = v14;
        breachedContacts.m_data.m_solver.m_solverResult = (hkpSolverResults *)v15;
        hkpWorldCallbackUtil::fireContactImpulseLimitBreached(world, &breachedContacts, 1);
      }
      v10 = v32;
      v11 = v33;
      *(_DWORD *)v15 = 0;
    }
    v9 = world;
    *(_DWORD *)(v15 + 24) = 0;
    goto LABEL_25;
  }
LABEL_28:
  v38->m_internal->m_callbackRequest &= 0xF6u;
}

// File Line: 379
// RVA: 0xD97CD0
void __fastcall hkpSimpleContactConstraintData::collisionResponseBeginCallback(hkpSimpleContactConstraintData *this, hkContactPoint *cp, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  hkpBodyVelocity *v6; // rbp
  hkpSimpleConstraintInfoInitInput *v7; // r14
  hkpCenterOfMassChangerModifierConstraintAtom *v8; // rbx
  hkContactPoint *v9; // r15
  unsigned __int16 i; // ax
  int v11; // eax
  int v12; // eax
  int v13; // eax

  v6 = velA;
  v7 = inA;
  v8 = (hkpCenterOfMassChangerModifierConstraintAtom *)this->m_constraint->m_constraintModifiers;
  v9 = cp;
  if ( v8 )
  {
    for ( i = v8->m_type.m_storage; v8->m_type.m_storage >= 0x1Eu; i = v8->m_type.m_storage )
    {
      v11 = i - 30;
      if ( v11 )
      {
        v12 = v11 - 1;
        if ( v12 )
        {
          v13 = v12 - 2;
          if ( v13 )
          {
            if ( v13 == 2 )
              hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseBeginCallback(v8, v9, v7, v6, inB, velB);
          }
          else
          {
            hkpMovingSurfaceModifierConstraintAtom::collisionResponseBeginCallback(
              (hkpMovingSurfaceModifierConstraintAtom *)v8,
              v9,
              v7,
              v6,
              inB,
              velB);
          }
        }
        else
        {
          hkpMassChangerModifierConstraintAtom::collisionResponseBeginCallback(
            (hkpMassChangerModifierConstraintAtom *)v8,
            v9,
            v7,
            v6,
            inB,
            velB);
        }
      }
      else
      {
        hkpSoftContactModifierConstraintAtom::collisionResponseBeginCallback(
          (hkpSoftContactModifierConstraintAtom *)v8,
          v9,
          v7,
          v6,
          inB,
          velB);
      }
      v8 = (hkpCenterOfMassChangerModifierConstraintAtom *)v8->m_child;
    }
  }
}

// File Line: 429
// RVA: 0xD97DE0
void __fastcall hkpSimpleContactConstraintData::collisionResponseEndCallback(hkpSimpleContactConstraintData *this, hkContactPoint *cp, float impulseApplied, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  hkpConstraintInstance *v7; // rbx
  hkpSimpleConstraintInfoInitInput *v8; // r14
  hkContactPoint *v9; // r15
  signed int v10; // er8
  int v11; // eax
  hkpModifierConstraintAtom *i; // rbx
  int v13; // eax
  __int64 v14; // rbx
  hkpSoftContactModifierConstraintAtom *v15; // rcx
  char *array; // [rsp+40h] [rbp-B8h]
  int v17; // [rsp+48h] [rbp-B0h]
  int v18; // [rsp+4Ch] [rbp-ACh]
  char v19; // [rsp+50h] [rbp-A8h]

  v7 = this->m_constraint;
  v8 = inA;
  v9 = cp;
  if ( v7->m_constraintModifiers )
  {
    v10 = -2147483632;
    array = &v19;
    v11 = 0;
    v18 = -2147483632;
    v17 = 0;
    for ( i = v7->m_constraintModifiers; i->m_type.m_storage >= 0x1Eu; i = (hkpModifierConstraintAtom *)i->m_child )
    {
      if ( v11 == (v10 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v11 = v17;
      }
      *(_QWORD *)&array[8 * v11] = i;
      v10 = v18;
      v11 = v17++ + 1;
    }
    v13 = v11 - 1;
    v14 = v13;
    if ( v13 >= 0 )
    {
      do
      {
        v15 = *(hkpSoftContactModifierConstraintAtom **)&array[8 * v14];
        switch ( v15->m_type.m_storage )
        {
          case 0x1Eu:
            hkpSoftContactModifierConstraintAtom::collisionResponseEndCallback(
              v15,
              v9,
              impulseApplied,
              v8,
              velA,
              inB,
              velB);
            break;
          case 0x1Fu:
            hkpMassChangerModifierConstraintAtom::collisionResponseEndCallback(
              (hkpMassChangerModifierConstraintAtom *)v15,
              v9,
              impulseApplied,
              v8,
              velA,
              inB,
              velB);
            break;
          case 0x21u:
            hkpMovingSurfaceModifierConstraintAtom::collisionResponseEndCallback(
              (hkpMovingSurfaceModifierConstraintAtom *)v15,
              v9,
              impulseApplied,
              v8,
              velA,
              inB,
              velB);
            break;
          case 0x23u:
            hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseEndCallback(
              (hkpCenterOfMassChangerModifierConstraintAtom *)v15,
              v9,
              impulseApplied,
              v8,
              velA,
              inB,
              velB);
            break;
        }
        --v14;
      }
      while ( v14 >= 0 );
      v10 = v18;
    }
    v17 = 0;
    if ( v10 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v10);
  }
}

// File Line: 490
// RVA: 0xD97BE0
hkBool *__fastcall hkpSimpleContactConstraintData::isValid(hkpSimpleContactConstraintData *this, hkBool *result)
{
  result->m_bool = 1;
  return result;
}

// File Line: 495
// RVA: 0xD97CC0
signed __int64 __fastcall hkpSimpleContactConstraintData::getType(hkpSimpleContactConstraintData *this)
{
  return 11i64;
}

