// File Line: 42
// RVA: 0xD97A40
int __fastcall hkpSimpleContactConstraintData::allocateContactPoint(
        hkpSimpleContactConstraintData *this,
        hkpConstraintOwner *constraintOwner,
        hkContactPoint **cpOut,
        hkpContactPointProperties **cpPropsOut)
{
  hkpSimpleContactConstraintAtom *m_atom; // rax
  hkpSimpleContactConstraintAtom *v7; // r14
  int m_numContactPoints; // esi
  hkpSimpleContactConstraintAtom *v11; // rax
  hkpSimpleContactConstraintAtom *v12; // rdi
  int v13; // edx
  __int64 v14; // r8
  hkContactPoint *v15; // r10
  int v16; // r9d
  hkpContactPointProperties *v17; // rax
  int v18; // r8d
  int v19; // r9d
  int m_maxSizeOfSchema; // r10d
  int v21; // r8d
  int v22; // edx
  hkpConstraintInstance *m_constraint; // r11
  int v24; // r9d
  int v25; // eax
  hkConstraintInternal *m_internal; // rcx
  int m_sizeOfSchemas; // ecx
  hkPadSpu<bool> atomReallocated; // [rsp+60h] [rbp+8h] BYREF

  m_atom = this->m_atom;
  m_atom->m_info.m_flags |= 4u;
  v7 = this->m_atom;
  m_numContactPoints = m_atom->m_numContactPoints;
  atomReallocated.m_storage = 0;
  v11 = hkpSimpleContactConstraintAtomUtil::expandOne(v7, &atomReallocated);
  this->m_atom = v11;
  v12 = v11;
  v13 = 0;
  v14 = 32i64 * v11->m_numReservedContactPoints;
  v15 = (hkContactPoint *)((char *)&v11[1] + 32 * (unsigned int)m_numContactPoints);
  LODWORD(v11) = (unsigned __int8)v11->m_contactPointPropertiesStriding;
  v16 = -(int)v11;
  v17 = (hkpContactPointProperties *)((char *)&v12[1] + m_numContactPoints * (int)v11 + v14);
  v17->hkpSolverResults = 0i64;
  v17->m_flags = 1;
  if ( m_numContactPoints > 0 && (*(&v17->m_flags + v16) & 2) == 0 && !*(&v17->m_maxImpulse.m_value + v16) )
    v17->m_flags = 3;
  *cpOut = v15;
  *cpPropsOut = v17;
  v18 = 0;
  v19 = 0;
  m_maxSizeOfSchema = 112 * ((m_numContactPoints + 1) >> 1) + 48 * ((((_BYTE)m_numContactPoints + 1) & 1) + 4);
  if ( m_numContactPoints == 1 )
  {
    v13 = 48;
    v18 = 1;
    v19 = 1;
  }
  v21 = v18 + 1;
  if ( (((_BYTE)m_numContactPoints + 1) & 1) != 0 )
    v22 = v13 + 48;
  else
    v22 = v13 + 64;
  m_constraint = this->m_constraint;
  v24 = v19 + 1;
  if ( m_constraint->m_internal )
  {
    v25 = v22;
    if ( constraintOwner->m_constraintInfo.m_maxSizeOfSchema > m_maxSizeOfSchema )
      m_maxSizeOfSchema = constraintOwner->m_constraintInfo.m_maxSizeOfSchema;
    if ( m_maxSizeOfSchema > v22 )
      v25 = m_maxSizeOfSchema;
    constraintOwner->m_constraintInfo.m_sizeOfSchemas += v22;
    constraintOwner->m_constraintInfo.m_numSolverResults += v21;
    constraintOwner->m_constraintInfo.m_numSolverElemTemps += v24;
    constraintOwner->m_constraintInfo.m_maxSizeOfSchema = v25;
    m_internal = m_constraint->m_internal;
    m_internal->m_sizeOfSchemas += v22;
    m_internal->m_numSolverResults += v21;
    m_internal->m_numSolverElemTemps += v24;
    m_sizeOfSchemas = m_constraint->m_internal->m_sizeOfSchemas;
    if ( constraintOwner->m_constraintInfo.m_maxSizeOfSchema > m_sizeOfSchemas )
      m_sizeOfSchemas = constraintOwner->m_constraintInfo.m_maxSizeOfSchema;
    constraintOwner->m_constraintInfo.m_maxSizeOfSchema = m_sizeOfSchemas;
  }
  if ( atomReallocated.m_storage )
  {
    hkpWorldConstraintUtil::updateFatherOfMovedAtom(
      this->m_constraint,
      (hkpModifierConstraintAtom *)v7,
      (hkpModifierConstraintAtom *)this->m_atom,
      v12->m_sizeOfAllAtoms);
    this->m_atomSize = v12->m_sizeOfAllAtoms;
  }
  return hkpDynamicsCpIdMgr::newId(&this->m_idMgrA, m_numContactPoints);
}

// File Line: 113
// RVA: 0xD97FE0
void __fastcall hkpSimpleContactConstraintData::hkpSimpleContactConstraintData(
        hkpSimpleContactConstraintData *this,
        hkpConstraintInstance *constraint,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB)
{
  hkpSimpleContactConstraintAtom *Atom; // rax

  this->m_memSizeAndFlags = -1;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleContactConstraintData::`vftable;
  this->m_referenceCount = 1;
  this->m_idMgrA.m_values.m_data = this->m_idMgrA.m_values.m_storage;
  this->m_idMgrA.m_values.m_size = 0;
  this->m_idMgrA.m_values.m_capacityAndFlags = -2147483640;
  this->m_constraint = constraint;
  Atom = hkpSimpleContactConstraintAtomUtil::allocateAtom(
           1,
           (unsigned __int8)bodyA->m_numShapeKeysInContactPointProperties,
           (unsigned __int8)bodyB->m_numShapeKeysInContactPointProperties,
           0x4000
         / (int)(((4
                 * ((unsigned __int8)bodyB->m_numShapeKeysInContactPointProperties
                  + (unsigned __int8)bodyA->m_numShapeKeysInContactPointProperties)
                 + 35) & 0xFFFFFFFC)
               + 32));
  this->m_atom = Atom;
  *(_DWORD *)&Atom->m_info.m_flags = 196608;
  Atom->m_info.m_contactRadius = 0.0;
  *(_DWORD *)&Atom->m_info.m_internalData1.m_value = 0;
  Atom->m_info.m_rhsRolling[1].m_value = 0;
  Atom->m_info.m_rollingFrictionMultiplier.m_value = 0;
  *(_QWORD *)Atom->m_info.m_data = 0i64;
  *(_QWORD *)&Atom->m_info.m_data[2] = 0i64;
  this->m_atomSize = this->m_atom->m_sizeOfAllAtoms;
}

// File Line: 135
// RVA: 0xD97BF0
void __fastcall hkpSimpleContactConstraintData::getConstraintInfo(
        hkpSimpleContactConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  unsigned int m_sizeOfAllAtoms; // r8d
  hkpSimpleContactConstraintAtom *m_atom; // r10
  int m_numContactPoints; // edx
  int v6; // eax
  int v7; // eax

  infoOut->m_atoms = this->m_atom;
  m_sizeOfAllAtoms = this->m_atom->m_sizeOfAllAtoms;
  *(_QWORD *)&infoOut->m_maxSizeOfSchema = 0i64;
  *(_QWORD *)&infoOut->m_numSolverResults = 0i64;
  infoOut->m_sizeOfAllAtoms = m_sizeOfAllAtoms;
  m_atom = this->m_atom;
  m_numContactPoints = m_atom->m_numContactPoints;
  v6 = (m_atom->m_numContactPoints & 1) + 3;
  infoOut->m_numSolverElemTemps = m_numContactPoints + 3;
  v7 = 48 * v6 + 112 * (m_numContactPoints >> 1);
  infoOut->m_sizeOfSchemas = v7;
  infoOut->m_numSolverResults = m_numContactPoints + 2;
  infoOut->m_maxSizeOfSchema = v7 + 48;
  if ( m_numContactPoints >= 2 )
  {
    infoOut->m_sizeOfSchemas = v7 + 48;
    infoOut->m_numSolverResults = m_numContactPoints + 3;
    infoOut->m_numSolverElemTemps = m_numContactPoints + 4;
  }
  if ( COERCE_FLOAT(m_atom->m_info.m_rollingFrictionMultiplier.m_value << 16) != 0.0 )
  {
    infoOut->m_sizeOfSchemas += 96;
    infoOut->m_numSolverResults += 2;
    infoOut->m_numSolverElemTemps += 3;
    infoOut->m_maxSizeOfSchema = v7 + 144;
  }
}

// File Line: 144
// RVA: 0xD97CA0
void __fastcall hkpSimpleContactConstraintData::getRuntimeInfo(
        hkpSimpleContactConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  *infoOut = 0i64;
}

// File Line: 151
// RVA: 0xD97CB0
hkpSolverResults *__fastcall hkpSimpleContactConstraintData::getSolverResults(
        hkpSimpleContactConstraintData *this,
        struct hkpConstraintRuntime *runtime)
{
  return 0i64;
}

// File Line: 157
// RVA: 0xD97FD0
hkpSimpleConstraintContactMgr *__fastcall hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(
        hkpSimpleContactConstraintData *this)
{
  return (hkpSimpleConstraintContactMgr *)this[-1].m_idMgrA.m_values.m_storage;
}

// File Line: 192
// RVA: 0xD980A0
void __fastcall hkSimpleContactConstraintData_fireCallbacks(
        hkpSimpleContactConstraintData *constraintData,
        hkpConstraintQueryIn *in,
        hkpSimpleContactConstraintAtom *atom,
        hkpContactPointEvent::Type type)
{
  hkpSimpleConstraintContactMgr *SimpleConstraintContactMgr; // rax
  hkpRigidBody *v7; // r15
  hkpRigidBody *v8; // r14
  hkpWorld *m_world; // r8
  hkpVelocityAccumulator *v10; // r9
  hkpVelocityAccumulator *v11; // r10
  bool v12; // bl
  hkpSimpleConstraintContactMgr *v13; // rdx
  hkContactPoint *cp; // r12
  char *v15; // rsi
  __int64 m_contactPointPropertiesStriding; // rcx
  int v17; // eax
  int v18; // edi
  bool v19; // zf
  __m128 v20; // xmm3
  hkpModifierConstraintAtom *m_constraintModifiers; // rax
  __m128 v22; // xmm6
  float Friction; // xmm0_4
  hkpConstraintInstance *v24; // rax
  __m128 v25; // xmm2
  float v26; // xmm1_4
  hkpWorld *world; // [rsp+40h] [rbp-C0h]
  hkpSimpleConstraintContactMgr *v28; // [rsp+48h] [rbp-B8h]
  hkpVelocityAccumulator *v29; // [rsp+50h] [rbp-B0h]
  hkpVelocityAccumulator *v30; // [rsp+58h] [rbp-A8h]
  char *v31; // [rsp+60h] [rbp-A0h]
  unsigned int v32; // [rsp+60h] [rbp-A0h]
  __int64 v33; // [rsp+68h] [rbp-98h]
  hkpContactPointEvent event; // [rsp+80h] [rbp-80h] BYREF
  hkpSimpleConstraintUtilCollideParams params; // [rsp+F0h] [rbp-10h] BYREF
  hkpConstraintInstance *m_storage; // [rsp+110h] [rbp+10h]
  hkSimdFloat32 result; // [rsp+120h] [rbp+20h] BYREF
  hkpContactImpulseLimitBreachedListenerInfo breachedContacts; // [rsp+140h] [rbp+40h] BYREF
  int v40; // [rsp+1D8h] [rbp+D8h]
  unsigned int v41; // [rsp+1E0h] [rbp+E0h] BYREF
  hkpContactPointEvent::Type v42; // [rsp+1E8h] [rbp+E8h]

  v42 = type;
  m_storage = in->m_constraintInstance.m_storage;
  SimpleConstraintContactMgr = hkpSimpleContactConstraintData::getSimpleConstraintContactMgr(constraintData);
  v7 = (hkpRigidBody *)m_storage->m_entities[0];
  v8 = (hkpRigidBody *)m_storage->m_entities[1];
  m_world = v7->m_world;
  v10 = in->m_bodyA.m_storage;
  v11 = in->m_bodyB.m_storage;
  v12 = (m_storage->m_internal->m_callbackRequest & 8) != 0;
  v13 = SimpleConstraintContactMgr;
  v28 = SimpleConstraintContactMgr;
  cp = (hkContactPoint *)&atom[1];
  world = m_world;
  v15 = (char *)&atom[1] + 32 * atom->m_numReservedContactPoints;
  m_contactPointPropertiesStriding = (unsigned __int8)atom->m_contactPointPropertiesStriding;
  v17 = atom->m_numContactPoints - 1;
  v29 = v10;
  v30 = v11;
  v31 = 0i64;
  v40 = v17;
  v18 = v17;
  if ( v17 >= 0 )
  {
    v33 = m_contactPointPropertiesStriding;
    while ( (v15[19] & 1) == 0 )
    {
      if ( !v12 )
        goto LABEL_27;
      event.m_contactMgr = v13;
      event.m_type = v42;
      *(_OWORD *)&event.m_separatingVelocity = 0i64;
      event.m_lastCallbackForFullManifold.m_bool = v18 == 0;
      event.m_firstCallbackForFullManifold.m_bool = v18 == v17;
      event.m_source = SOURCE_WORLD;
      event.m_bodies[0] = v7;
      event.m_bodies[1] = v8;
      event.m_shapeKeyStorage = (unsigned int *)(v15 + 32);
      event.m_contactPoint = cp;
      event.m_contactPointProperties = (hkpContactPointProperties *)v15;
      event.m_firingCallbacksForFullManifold.m_bool = 1;
      event.m_accumulators[0] = v10;
      event.m_accumulators[1] = v11;
      hkpWorldCallbackUtil::fireContactPointCallback(m_world, &event);
      v19 = v7->m_contactListeners.m_size == 0;
      event.m_source = SOURCE_A;
      if ( !v19 )
        hkpEntityCallbackUtil::fireContactPointCallbackInternal(v7, &event);
      v19 = v8->m_contactListeners.m_size == 0;
      event.m_source = SOURCE_B;
      if ( !v19 )
        hkpEntityCallbackUtil::fireContactPointCallbackInternal(v8, &event);
      v17 = v40;
      m_world = world;
      v10 = v29;
      v11 = v30;
      if ( v18 < v40 )
      {
        v13 = v28;
        m_contactPointPropertiesStriding = v33;
        if ( v31[18] )
          v15[19] &= ~2u;
        goto LABEL_27;
      }
LABEL_26:
      m_contactPointPropertiesStriding = v33;
      v13 = v28;
LABEL_27:
      v31 = v15;
      ++cp;
      v15 += m_contactPointPropertiesStriding;
      if ( --v18 < 0 )
        goto LABEL_28;
    }
    hkpSimpleContactConstraintUtil::calculateSeparatingVelocity(
      &result,
      v7,
      v8,
      &in->m_bodyA.m_storage->m_scratch3,
      &in->m_bodyB.m_storage->m_scratch3,
      cp);
    event.m_contactMgr = v28;
    v41 = result.m_real.m128_i32[0];
    event.m_lastCallbackForFullManifold.m_bool = v18 == 0;
    event.m_firstCallbackForFullManifold.m_bool = v18 == v40;
    event.m_separatingVelocity = (float *)&v41;
    event.m_type = v42;
    event.m_shapeKeyStorage = (unsigned int *)(v15 + 32);
    event.m_accumulators[0] = v29;
    event.m_source = SOURCE_WORLD;
    event.m_bodies[0] = v7;
    event.m_bodies[1] = v8;
    event.m_contactPoint = cp;
    event.m_accumulators[1] = v30;
    event.m_contactPointProperties = (hkpContactPointProperties *)v15;
    event.m_firingCallbacksForFullManifold.m_bool = v12;
    event.m_rotateNormal = 0i64;
    hkpWorldCallbackUtil::fireContactPointCallback(world, &event);
    v19 = v7->m_contactListeners.m_size == 0;
    event.m_source = SOURCE_A;
    if ( !v19 )
      hkpEntityCallbackUtil::fireContactPointCallbackInternal(v7, &event);
    v19 = v8->m_contactListeners.m_size == 0;
    event.m_source = SOURCE_B;
    if ( !v19 )
      hkpEntityCallbackUtil::fireContactPointCallbackInternal(v8, &event);
    v20 = _mm_shuffle_ps((__m128)v41, (__m128)v41, 0);
    result.m_real = v20;
    if ( v18 < v40 && v31[18] )
      v15[19] &= ~2u;
    v11 = v30;
    v10 = v29;
    if ( !(_mm_movemask_ps(_mm_cmpneq_ps(v29->m_invMasses.m_quad, (__m128)0i64)) | _mm_movemask_ps(
                                                                                     _mm_cmpneq_ps(
                                                                                       v30->m_invMasses.m_quad,
                                                                                       (__m128)0i64)))
      || (v15[19] & 8) != 0
      || (m_constraintModifiers = v28->m_constraint.m_constraintModifiers) != 0i64
      && m_constraintModifiers->m_type.m_storage == 34 )
    {
      *(_QWORD *)v15 = 0i64;
    }
    else
    {
      m_world = world;
      *(float *)&v32 = (float)(unsigned __int8)v15[17] * 0.0078125;
      v22 = _mm_shuffle_ps((__m128)v32, (__m128)v32, 0);
      if ( v20.m128_f32[0] >= (float)(0.0
                                    - _mm_shuffle_ps(
                                        (__m128)*((unsigned int *)world->m_collisionInput->m_dynamicsInfo + 28),
                                        (__m128)*((unsigned int *)world->m_collisionInput->m_dynamicsInfo + 28),
                                        0).m128_f32[0])
        || v22.m128_f32[0] <= _mm_shuffle_ps((__m128)0x3E99999Au, (__m128)0x3E99999Au, 0).m128_f32[0] )
      {
        v25 = _mm_add_ps(
                _mm_add_ps(
                  _mm_shuffle_ps(v8->m_motion.m_inertiaAndMassInv.m_quad, v8->m_motion.m_inertiaAndMassInv.m_quad, 255),
                  _mm_shuffle_ps(v7->m_motion.m_inertiaAndMassInv.m_quad, v7->m_motion.m_inertiaAndMassInv.m_quad, 255)),
                _mm_shuffle_ps((__m128)0x2EDBE6FFu, (__m128)0x2EDBE6FFu, 0));
        v26 = _mm_rcp_ps(v25).m128_f32[0];
        *(float *)v15 = (float)((float)(_mm_shuffle_ps((__m128)0xBE4CCCCD, (__m128)0xBE4CCCCD, 0).m128_f32[0]
                                      * (float)((float)(2.0 - (float)(v26 * v25.m128_f32[0])) * v26))
                              * v20.m128_f32[0])
                      * (float)(v22.m128_f32[0] + 1.0);
        v25.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v20.m128_f32[0])
                                * _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_subStepDeltaTime.m_storage),
                                    (__m128)LODWORD(in->m_subStepDeltaTime.m_storage),
                                    0).m128_f32[0])
                        * _mm_shuffle_ps((__m128)0xBFA66666, (__m128)0xBFA66666, 0).m128_f32[0];
        *((_DWORD *)v15 + 1) = v25.m128_i32[0];
        *((_DWORD *)v15 + 6) = COERCE_UNSIGNED_INT(
                                 _mm_shuffle_ps(cp->m_separatingNormal.m_quad, cp->m_separatingNormal.m_quad, 255).m128_f32[0]
                               - v25.m128_f32[0]) & _mm_cmplt_ps((__m128)0i64, v22).m128_u32[0];
LABEL_25:
        v15[19] &= ~1u;
        v17 = v40;
        goto LABEL_26;
      }
      Friction = hkContactPointMaterial::getFriction((hkContactPointMaterial *)(v15 + 8));
      v19 = v15[18] == 0;
      *(_QWORD *)&params.m_extraSeparatingVelocity = 0i64;
      LODWORD(params.m_restitution) = v22.m128_i32[0];
      params.m_friction = Friction;
      params.m_maxImpulse = 3.40282e38;
      LODWORD(params.m_externalSeperatingVelocity) = result.m_real.m128_i32[0];
      if ( !v19 )
        params.m_maxImpulse = hkContactPointMaterial::getMaxImpulsePerStep((hkContactPointMaterial *)(v15 + 8));
      hkpSimpleCollisionResponse::solveSingleContact2(constraintData, cp, &params, v7);
      if ( params.m_contactImpulseLimitBreached.m_bool )
      {
        v24 = in->m_constraintInstance.m_storage;
        *(_DWORD *)&breachedContacts.m_data.m_solver.m_type = 65537;
        breachedContacts.m_data.m_solver.m_constraintInstance = v24;
        breachedContacts.m_data.m_single.m_contactPoint = cp;
        breachedContacts.m_data.m_solver.m_solverResult = (hkpSolverResults *)v15;
        hkpWorldCallbackUtil::fireContactImpulseLimitBreached(world, &breachedContacts, 1u);
      }
      v10 = v29;
      v11 = v30;
      *(_DWORD *)v15 = 0;
    }
    m_world = world;
    *((_DWORD *)v15 + 6) = 0;
    goto LABEL_25;
  }
LABEL_28:
  m_storage->m_internal->m_callbackRequest &= 0xF6u;
}

// File Line: 379
// RVA: 0xD97CD0
void __fastcall hkpSimpleContactConstraintData::collisionResponseBeginCallback(
        hkpSimpleContactConstraintData *this,
        hkContactPoint *cp,
        hkpSimpleConstraintInfoInitInput *inA,
        hkpBodyVelocity *velA,
        hkpSimpleConstraintInfoInitInput *inB,
        hkpBodyVelocity *velB)
{
  hkpCenterOfMassChangerModifierConstraintAtom *m_constraintModifiers; // rbx
  unsigned __int16 i; // ax
  int v11; // eax
  int v12; // eax
  int v13; // eax

  m_constraintModifiers = (hkpCenterOfMassChangerModifierConstraintAtom *)this->m_constraint->m_constraintModifiers;
  if ( m_constraintModifiers )
  {
    for ( i = m_constraintModifiers->m_type.m_storage;
          m_constraintModifiers->m_type.m_storage >= 0x1Eu;
          i = m_constraintModifiers->m_type.m_storage )
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
              hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseBeginCallback(
                m_constraintModifiers,
                cp,
                inA,
                velA,
                inB,
                velB);
          }
          else
          {
            hkpMovingSurfaceModifierConstraintAtom::collisionResponseBeginCallback(
              (hkpMovingSurfaceModifierConstraintAtom *)m_constraintModifiers,
              cp,
              inA,
              velA,
              inB,
              velB);
          }
        }
        else
        {
          hkpMassChangerModifierConstraintAtom::collisionResponseBeginCallback(
            (hkpMassChangerModifierConstraintAtom *)m_constraintModifiers,
            cp,
            inA,
            velA,
            inB,
            velB);
        }
      }
      else
      {
        hkpSoftContactModifierConstraintAtom::collisionResponseBeginCallback(
          (hkpSoftContactModifierConstraintAtom *)m_constraintModifiers,
          cp,
          inA,
          velA,
          inB,
          velB);
      }
      m_constraintModifiers = (hkpCenterOfMassChangerModifierConstraintAtom *)m_constraintModifiers->m_child;
    }
  }
}

// File Line: 429
// RVA: 0xD97DE0
void __fastcall hkpSimpleContactConstraintData::collisionResponseEndCallback(
        hkpSimpleContactConstraintData *this,
        hkContactPoint *cp,
        float impulseApplied,
        hkpSimpleConstraintInfoInitInput *inA,
        hkpBodyVelocity *velA,
        hkpSimpleConstraintInfoInitInput *inB,
        hkpBodyVelocity *velB)
{
  hkpConstraintInstance *m_constraint; // rbx
  int v10; // r8d
  int v11; // eax
  hkpModifierConstraintAtom *i; // rbx
  int v13; // eax
  __int64 v14; // rbx
  hkpSoftContactModifierConstraintAtom *v15; // rcx
  char *array; // [rsp+40h] [rbp-B8h] BYREF
  int v17; // [rsp+48h] [rbp-B0h]
  int v18; // [rsp+4Ch] [rbp-ACh]
  char v19; // [rsp+50h] [rbp-A8h] BYREF

  m_constraint = this->m_constraint;
  if ( m_constraint->m_constraintModifiers )
  {
    v10 = -2147483632;
    array = &v19;
    v11 = 0;
    v18 = -2147483632;
    v17 = 0;
    for ( i = m_constraint->m_constraintModifiers; i->m_type.m_storage >= 0x1Eu; i = (hkpModifierConstraintAtom *)i->m_child )
    {
      if ( v11 == (v10 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        v11 = v17;
      }
      *(_QWORD *)&array[8 * v11] = i;
      v10 = v18;
      v11 = ++v17;
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
              cp,
              impulseApplied,
              inA,
              velA,
              inB,
              velB);
            break;
          case 0x1Fu:
            hkpMassChangerModifierConstraintAtom::collisionResponseEndCallback(
              (hkpMassChangerModifierConstraintAtom *)v15,
              cp,
              impulseApplied,
              inA,
              velA,
              inB,
              velB);
            break;
          case 0x21u:
            hkpMovingSurfaceModifierConstraintAtom::collisionResponseEndCallback(
              (hkpMovingSurfaceModifierConstraintAtom *)v15,
              cp,
              impulseApplied,
              inA,
              velA,
              inB,
              velB);
            break;
          case 0x23u:
            hkpCenterOfMassChangerModifierConstraintAtom::collisionResponseEndCallback(
              (hkpCenterOfMassChangerModifierConstraintAtom *)v15,
              cp,
              impulseApplied,
              inA,
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v10);
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
__int64 __fastcall hkpSimpleContactConstraintData::getType(hkpSimpleContactConstraintData *this)
{
  return 11i64;
}

