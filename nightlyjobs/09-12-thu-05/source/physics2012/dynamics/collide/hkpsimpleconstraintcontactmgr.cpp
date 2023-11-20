// File Line: 47
// RVA: 0x15D2240
void dynamic_initializer_for__hkpSimpleConstraintContactMgrClass__()
{
  hkClass::hkClass(
    &hkpSimpleConstraintContactMgrClass,
    "hkpSimpleConstraintContactMgr",
    &hkReferencedObjectClass,
    240,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 52
// RVA: 0xD83FD0
hkpConstraintInstance *__fastcall hkpSimpleConstraintContactMgr::getConstraintInstance(hkpSimpleConstraintContactMgr *this)
{
  return &this->m_constraint;
}

// File Line: 57
// RVA: 0xD83FE0
hkpConstraintInstance *__fastcall hkpSimpleConstraintContactMgr::getConstraintInstance(hkpSimpleConstraintContactMgr *this)
{
  return &this->m_constraint;
}

// File Line: 66
// RVA: 0xD833E0
void __fastcall hkpSimpleConstraintContactMgr::hkpSimpleConstraintContactMgr(hkpSimpleConstraintContactMgr *this, hkpWorld *sm, hkpRigidBody *bodyA, hkpRigidBody *bodyB)
{
  hkpSimpleContactConstraintData *v4; // rbx
  hkpWorld *v5; // rsi
  hkpSimpleConstraintContactMgr *v6; // r15
  hkpRigidBody *v7; // r14
  hkpRigidBody *v8; // rbp
  float v9; // [rsp+60h] [rbp+8h]

  v4 = &this->m_contactConstraintData;
  v5 = sm;
  v6 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleConstraintContactMgr::`vftable;
  v7 = bodyB;
  this->m_type = 0;
  v8 = bodyA;
  hkpSimpleContactConstraintData::hkpSimpleContactConstraintData(
    &this->m_contactConstraintData,
    &this->m_constraint,
    bodyA,
    bodyB);
  hkpConstraintInstance::hkpConstraintInstance(&v6->m_constraint, PRIORITY_PSI);
  v6->m_constraint.m_data = (hkpConstraintData *)&v4->vfptr;
  v6->m_constraint.m_entities[0] = (hkpEntity *)&v8->vfptr;
  v6->m_constraint.m_entities[1] = (hkpEntity *)&v7->vfptr;
  v6->m_constraint.m_uid = -1;
  v6->m_world = v5;
  *(_DWORD *)&v6->m_reservedContactPoints = 0;
  v6->m_contactConstraintData.m_memSizeAndFlags = 0;
  v6->m_constraint.m_memSizeAndFlags = 0;
  hkpConstraintInstance::setPriority(
    &v6->m_constraint,
    (hkpConstraintInstance::ConstraintPriority)v5->m_collisionDispatcher->m_collisionQualityInfo[(signed __int64)v5->m_collisionDispatcher->m_collisionQualityTable[v8->m_collidable.m_broadPhaseHandle.m_objectQualityType][v7->m_collidable.m_broadPhaseHandle.m_objectQualityType]].m_constraintPriority);
  v9 = fmaxf(
         COERCE_FLOAT(v8->m_material.m_rollingFrictionMultiplier.m_value << 16),
         COERCE_FLOAT(v7->m_material.m_rollingFrictionMultiplier.m_value << 16))
     * 1.0039062;
  v6->m_contactConstraintData.m_atom->m_info.m_rollingFrictionMultiplier.m_value = HIWORD(v9);
}

// File Line: 108
// RVA: 0xD83520
void __fastcall hkpSimpleConstraintContactMgr::~hkpSimpleConstraintContactMgr(hkpSimpleConstraintContactMgr *this)
{
  hkpSimpleConstraintContactMgr *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleConstraintContactMgr::`vftable;
  if ( this->m_contactConstraintData.m_atom->m_numContactPoints )
    hkpWorldOperationUtil::removeConstraintImmediately(this->m_world, &this->m_constraint, DO_FIRE_CALLBACKS);
  v1->m_constraint.m_entities[0] = 0i64;
  v1->m_constraint.m_entities[1] = 0i64;
  v1->m_constraint.m_data = 0i64;
  hkpConstraintInstance::~hkpConstraintInstance(&v1->m_constraint);
  hkpSimpleContactConstraintData::~hkpSimpleContactConstraintData(&v1->m_contactConstraintData);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 131
// RVA: 0xD83970
hkResult *__fastcall hkpSimpleConstraintContactMgr::reserveContactPointsImpl(hkpSimpleConstraintContactMgr *this, hkResult *result, int numPoints)
{
  char v4; // al

  if ( numPoints + this->m_contactConstraintData.m_atom->m_numContactPoints + this->m_reservedContactPoints <= this->m_contactConstraintData.m_atom->m_maxNumContactPoints - 2 )
  {
    v4 = this->m_reservedContactPoints;
    result->m_enum = 0;
    this->m_reservedContactPoints = (unsigned __int8)(numPoints + v4);
  }
  else
  {
    result->m_enum = 1;
  }
  return result;
}

// File Line: 145
// RVA: 0xD83DE0
void __fastcall hkpSimpleConstraintContactMgr::removeToiImpl(hkpSimpleConstraintContactMgr *this, hkpConstraintOwner *constraintOwner, hkpContactPointProperties *properties)
{
  hkpEntity *v3; // rdi
  hkpEntity *v4; // rbx
  hkpWorld *v5; // rcx
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-48h]

  v3 = this->m_constraint.m_entities[0];
  v4 = this->m_constraint.m_entities[1];
  event.m_contactPointId = -1;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&this->vfptr;
  v5 = this->m_world;
  event.m_constraintOwner = constraintOwner;
  event.m_contactPointProperties = properties;
  event.m_entityA = v3;
  event.m_entityB = v4;
  hkpWorldCallbackUtil::fireContactPointRemoved(v5, &event);
  if ( v3->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v3, &event);
  if ( v4->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v4, &event);
}

// File Line: 164
// RVA: 0xD83E70
hkBool *__fastcall hkpSimpleConstraintContactMgr::fireCallbacksForEarliestToi(hkpSimpleConstraintContactMgr *this, hkBool *result, hkpToiEvent *event, float *rotateNormal)
{
  hkpRigidBody *v4; // rax
  hkpSimpleConstraintContactMgr *v5; // rsi
  hkBool *v6; // rbx
  hkpToiEvent *v7; // rdi
  hkpEntity *v8; // rcx
  hkpEntity *v9; // rcx
  hkpModifierConstraintAtom *v10; // rax
  hkpContactPointEvent eventa; // [rsp+20h] [rbp-78h]

  v4 = (hkpRigidBody *)event->m_entities[1];
  eventa.m_source = 2;
  eventa.m_contactMgr = this;
  eventa.m_bodies[1] = v4;
  v5 = this;
  v6 = result;
  eventa.m_bodies[0] = (hkpRigidBody *)event->m_entities[0];
  eventa.m_type = 0;
  eventa.m_contactPoint = &event->m_contactPoint;
  v7 = event;
  eventa.m_contactPointProperties = &event->m_properties;
  *(_WORD *)&eventa.m_firingCallbacksForFullManifold.m_bool = 0;
  eventa.m_lastCallbackForFullManifold.m_bool = 0;
  eventa.m_rotateNormal = rotateNormal;
  eventa.m_accumulators[0] = 0i64;
  eventa.m_separatingVelocity = &event->m_seperatingVelocity;
  eventa.m_accumulators[1] = 0i64;
  eventa.m_shapeKeyStorage = event->m_extendedUserDatas;
  hkpWorldCallbackUtil::fireContactPointCallback(eventa.m_bodies[0]->m_world, &eventa);
  v8 = v7->m_entities[0];
  eventa.m_source = 0;
  if ( v8->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v8, &eventa);
  v9 = v7->m_entities[1];
  eventa.m_source = 1;
  if ( v9->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v9, &eventa);
  v10 = v5->m_constraint.m_constraintModifiers;
  v6->m_bool = (!v10 || v10->m_type.m_storage != 34) && !(v7->m_properties.m_flags & 8);
  return v6;
}

// File Line: 187
// RVA: 0xD83F80
void __fastcall hkpSimpleConstraintContactMgr::confirmToi(hkpSimpleConstraintContactMgr *this, hkpToiEvent *event, float rotateNormal, hkArray<hkpEntity *,hkContainerHeapAllocator> *outToBeActivated)
{
  hkpEntity *v4; // rax

  v4 = event->m_entities[0];
  if ( !(event->m_properties.m_flags & 8)
    && ((unsigned __int8)(v4->m_motion.m_type.m_storage - 4) > 1u
     || (unsigned __int8)(event->m_entities[1]->m_motion.m_type.m_storage - 4) > 1u) )
  {
    hkLs_doSimpleCollisionResponse(v4->m_world, event, rotateNormal, outToBeActivated);
  }
}

// File Line: 210
// RVA: 0xD843A0
hkpEntity *__fastcall hkpSimpleConstraintContactMgr::setContactPointProperties(hkpSimpleConstraintContactMgr *this, hkpCdBody *a, hkpCdBody *b, int maxNumExtraDataInEvent, hkpContactPointProperties *cpi)
{
  hkpEntity *v5; // r15
  hkpEntity *v6; // r14
  hkpContactPointProperties *v7; // rdi
  hkpCdBody *v8; // rbp
  hkpSimpleConstraintContactMgr *v9; // r13
  int v10; // esi
  hkpCdBody *v11; // rbx
  hkpCdBody *v12; // rcx
  float v13; // xmm0_4
  hkpCdBody *i; // rax
  hkpSimpleContactConstraintAtom *v15; // rax
  int v16; // edx
  int v17; // er8
  hkpEntity *v18; // r9
  hkpCdBody *v19; // rcx
  int v20; // eax
  int v21; // esi
  signed __int64 v22; // rdx
  signed __int64 j; // r8
  float fv; // [rsp+50h] [rbp+8h]

  v5 = this->m_constraint.m_entities[1];
  v6 = this->m_constraint.m_entities[0];
  v7 = cpi;
  v8 = a;
  v9 = this;
  v10 = maxNumExtraDataInEvent;
  v11 = b;
  fv = fsqrt(v5->m_material.m_friction * v6->m_material.m_friction);
  hkUFloat8::operator=(&cpi->m_friction, &fv);
  v12 = v8;
  v13 = v5->m_material.m_restitution * v6->m_material.m_restitution;
  v7->m_maxImpulse.m_value = 0;
  *(float *)&cpi = fsqrt(v13) * 128.0;
  v7->m_restitution = (signed int)*(float *)&cpi;
  for ( i = v8->m_parent; i; i = i->m_parent )
    v12 = i;
  v15 = v9->m_contactConstraintData.m_atom;
  v16 = (unsigned __int8)v15->m_numUserDatasForBodyA;
  v17 = (unsigned __int8)v15->m_numUserDatasForBodyB;
  v18 = (hkpEntity *)((char *)v12 + SLOBYTE(v12[1].m_shape));
  if ( v17 + v16 )
  {
    if ( v18 == v6 )
    {
      v19 = v8;
    }
    else
    {
      v19 = v11;
      v18 = v5;
      v11 = v8;
    }
    v20 = v10;
    if ( v16 < v10 )
      v20 = v16;
    v21 = v10 - v20;
    if ( v17 < v21 )
      v21 = v17;
    if ( v19->m_shapeKey == -1 && v19->m_parent )
      v19 = v19->m_parent;
    v22 = 0i64;
    for ( j = 0i64; v19; v19 = v19->m_parent )
    {
      if ( j >= v20 )
        break;
      *((_DWORD *)&v7->m_internalDataA + ++j + 1) = v19->m_shapeKey;
    }
    if ( v11->m_shapeKey == -1 && v11->m_parent )
      v11 = v11->m_parent;
    for ( ; v11; v11 = v11->m_parent )
    {
      if ( v22 >= v21 )
        break;
      *((_DWORD *)&v7->m_internalDataA + v20 + ++v22 + 1) = v11->m_shapeKey;
    }
  }
  return v18;
}

// File Line: 295
// RVA: 0xD83C80
__int64 __fastcall hkpSimpleConstraintContactMgr::addToiImpl(hkpSimpleConstraintContactMgr *this, hkpCdBody *a, hkpCdBody *b, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, float toi, hkContactPoint *cp, hkpGskCache *gskCache, float *projectedVelocity, hkpContactPointProperties *properties)
{
  hkpProcessCollisionInput *v10; // rsi
  hkpCdBody *v11; // rdi
  hkpCdBody *v12; // rbx
  hkpSimpleConstraintContactMgr *v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rbp
  unsigned __int64 v16; // rbp
  hkpWorld *v17; // rcx
  hkpEntity *v18; // r15
  hkpEntity *v19; // rbp
  __int64 result; // rax
  hkpContactPointAddedEvent event; // [rsp+30h] [rbp-78h]
  float v22; // [rsp+88h] [rbp-20h]

  v10 = input;
  v11 = b;
  v12 = a;
  v13 = this;
  v14 = (unsigned __int64)hkpSimpleConstraintContactMgr::setContactPointProperties(this, a, b, 7, properties);
  v15 = (unsigned __int64)v13->m_constraint.m_entities[1];
  event.m_contactPoint = cp;
  v16 = (_QWORD)v13->m_constraint.m_entities[0] ^ v15;
  event.m_bodyA = v12;
  event.m_bodyB = v11;
  event.m_gskCache = gskCache;
  event.m_projectedVelocity = *projectedVelocity;
  v22 = toi;
  v17 = v13->m_world;
  v18 = (hkpEntity *)v14;
  v19 = (hkpEntity *)(v14 ^ v16);
  event.m_contactPointProperties = properties;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&v13->vfptr;
  event.m_collisionInput = v10;
  event.m_collisionOutput = output;
  event.m_type.m_storage = 0;
  event.m_status = 0;
  hkpWorldCallbackUtil::fireContactPointAdded(v17, &event);
  if ( v18->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v18, &event);
  if ( v19->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v19, &event);
  result = (unsigned int)event.m_status;
  if ( event.m_status == 1 )
  {
    ((void (__fastcall *)(hkpSimpleConstraintContactMgr *, hkpConstraintOwner *, hkpContactPointProperties *))v13->vfptr[4].__vecDelDtor)(
      v13,
      output->m_constraintOwner.m_storage,
      properties);
    result = (unsigned int)event.m_status;
  }
  else
  {
    *projectedVelocity = event.m_projectedVelocity;
  }
  return result;
}

// File Line: 322
// RVA: 0xD83610
signed __int64 __fastcall hkpSimpleConstraintContactMgr::addContactPointImpl(hkpSimpleConstraintContactMgr *this, hkpCdBody *a, hkpCdBody *b, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, hkpGskCache *contactCache, hkContactPoint *cp)
{
  hkpSimpleContactConstraintAtom *v7; // rax
  hkpSimpleConstraintContactMgr *v8; // rdi
  hkpProcessCollisionInput *v9; // r13
  hkpCdBody *v10; // r14
  hkpCdBody *v11; // r15
  signed __int64 result; // rax
  hkpProcessCollisionOutput *v13; // rsi
  unsigned __int16 v14; // ax
  hkContactPoint *v15; // rcx
  hkContactPoint *v16; // rbx
  unsigned __int16 v17; // r12
  unsigned __int64 v18; // rax
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __int64 v21; // r14
  hkpRigidBody *v22; // r15
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  hkpEntity *v25; // r14
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  float v30; // xmm6_4
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  float v33; // xmm1_4
  hkpContactPointProperties *cpPropsOut; // [rsp+30h] [rbp-71h]
  hkpContactPointAddedEvent event; // [rsp+40h] [rbp-61h]
  unsigned __int16 v36; // [rsp+98h] [rbp-9h]
  unsigned __int16 v37; // [rsp+9Ah] [rbp-7h]
  hkContactPoint *cpOut; // [rsp+F0h] [rbp+4Fh]
  hkpCdBody *v39; // [rsp+F8h] [rbp+57h]
  hkpCdBody *v40; // [rsp+100h] [rbp+5Fh]

  v40 = b;
  v39 = a;
  v7 = this->m_contactConstraintData.m_atom;
  v8 = this;
  v9 = input;
  v10 = b;
  v11 = a;
  if ( v7->m_numContactPoints + this->m_reservedContactPoints > v7->m_maxNumContactPoints - 2 )
    return 0xFFFFi64;
  v13 = output;
  if ( !v7->m_numContactPoints )
    ((void (__fastcall *)(hkpConstraintOwner *, hkpConstraintInstance *))output->m_constraintOwner.m_storage->vfptr[1].__first_virtual_table_function__)(
      output->m_constraintOwner.m_storage,
      &this->m_constraint);
  v14 = hkpSimpleContactConstraintData::allocateContactPoint(
          &v8->m_contactConstraintData,
          v13->m_constraintOwner.m_storage,
          &cpOut,
          &cpPropsOut);
  v15 = cpOut;
  v16 = cp;
  cpOut->m_position = cp->m_position;
  v17 = v14;
  v15->m_separatingNormal = v16->m_separatingNormal;
  v18 = (unsigned __int64)hkpSimpleConstraintContactMgr::setContactPointProperties(v8, v11, v10, 10000, cpPropsOut);
  v19 = v16->m_position.m_quad;
  v20 = v16->m_position.m_quad;
  v21 = (_QWORD)v8->m_constraint.m_entities[0] ^ (_QWORD)v8->m_constraint.m_entities[1];
  v22 = (hkpRigidBody *)v18;
  event.m_contactPoint = v16;
  v23 = *(__m128 *)(v18 + 576);
  v24 = _mm_sub_ps(v20, *(__m128 *)(v18 + 448));
  v25 = (hkpEntity *)(v18 ^ v21);
  event.m_type.m_storage = 1;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&v8->vfptr;
  event.m_collisionInput = v9;
  event.m_collisionOutput = v13;
  event.m_status = 0;
  v26 = _mm_sub_ps(v19, v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v36 = v17;
  v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v24));
  v28 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(v25->m_motion.m_angularVelocity.m_quad, v25->m_motion.m_angularVelocity.m_quad, 201),
            v26));
  v29 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 201), *(__m128 *)(v18 + 560)),
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 201), v25->m_motion.m_linearVelocity.m_quad)),
          v16->m_separatingNormal.m_quad);
  cpPropsOut->m_impulseApplied = 0.0;
  cpPropsOut->m_userData = 0i64;
  event.m_bodyA = v39;
  v30 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170));
  event.m_bodyB = v40;
  event.m_projectedVelocity = v30;
  event.m_gskCache = contactCache;
  event.m_contactPointProperties = cpPropsOut;
  if ( v8->m_type )
    v37 = 0;
  else
    v37 = v8->m_contactPointCallbackDelay;
  hkpWorldCallbackUtil::fireContactPointAdded(v8->m_world, &event);
  if ( v22->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal((hkpEntity *)&v22->vfptr, &event);
  if ( v25->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v25, &event);
  if ( event.m_status == 1 )
  {
    ((void (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD, hkpConstraintOwner *))v8->vfptr[2].__first_virtual_table_function__)(
      v8,
      v17,
      v13->m_constraintOwner.m_storage);
    result = 0xFFFFi64;
  }
  else
  {
    v8->m_contactPointCallbackDelay = v37;
    if ( !v9->m_allowToSkipConfirmedCallbacks.m_bool
      || (float)((float)(unsigned __int8)cpPropsOut->m_restitution * 0.0078125) != 0.0
      || v22->m_contactListeners.m_size
      || v25->m_contactListeners.m_size )
    {
      ((void (__fastcall *)(hkpConstraintOwner *, hkpConstraintInstance *, signed __int64))v13->m_constraintOwner.m_storage->vfptr[2].__first_virtual_table_function__)(
        v13->m_constraintOwner.m_storage,
        v8->m_contactConstraintData.m_constraint,
        1i64);
    }
    else
    {
      v31 = v22->m_motion.m_inertiaAndMassInv.m_quad;
      *(float *)&cpOut = FLOAT_1_0eN10;
      v32 = _mm_add_ps(
              _mm_add_ps(
                _mm_shuffle_ps(v31, v31, 255),
                _mm_shuffle_ps(v25->m_motion.m_inertiaAndMassInv.m_quad, v25->m_motion.m_inertiaAndMassInv.m_quad, 255)),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN10), (__m128)LODWORD(FLOAT_1_0eN10), 0));
      LODWORD(v33) = (unsigned __int128)_mm_rcp_ps(v32);
      *(float *)&cpOut = FLOAT_N0_2;
      cpPropsOut->m_impulseApplied = (float)(COERCE_FLOAT(
                                               _mm_shuffle_ps(
                                                 (__m128)LODWORD(FLOAT_N0_2),
                                                 (__m128)LODWORD(FLOAT_N0_2),
                                                 0))
                                           * (float)((float)(2.0 - (float)(v33 * v32.m128_f32[0])) * v33))
                                   * v30;
      cpPropsOut->m_internalSolverData = 0.0;
      cpPropsOut->m_internalDataA = 0.0;
    }
    result = v17;
  }
  return result;
}

// File Line: 417
// RVA: 0xD842E0
void __fastcall hkpSimpleContactConstraintAtomUtil::removeAtAndCopy(hkpSimpleContactConstraintAtom *atom, int index)
{
  unsigned int v2; // ebx
  int v3; // er11
  int v4; // er8
  unsigned __int16 *v5; // r10
  char *v6; // r8
  __int64 v7; // rsi
  int v8; // ebx
  __int64 v9; // rdi
  char *v10; // rax
  __int64 v11; // rdx
  int v12; // ecx

  v2 = (unsigned __int8)atom->m_contactPointPropertiesStriding;
  v3 = atom->m_numContactPoints - 1;
  v4 = (unsigned __int8)atom->m_contactPointPropertiesStriding;
  --atom->m_numContactPoints;
  v5 = &atom[1].m_type.m_storage + 16 * index;
  v6 = (char *)&atom[1] + 32 * atom->m_numReservedContactPoints + (signed __int16)index * v4;
  if ( index < v3 )
  {
    v7 = v2;
    v8 = (signed int)v2 >> 2;
    v9 = (unsigned int)(v3 - index);
    do
    {
      *(_OWORD *)v5 = *((_OWORD *)v5 + 2);
      v10 = &v6[v7];
      *((_OWORD *)v5 + 1) = *((_OWORD *)v5 + 3);
      if ( v8 > 0 )
      {
        v11 = (unsigned int)v8;
        do
        {
          v12 = *(_DWORD *)v10;
          v10 += 4;
          *(_DWORD *)&v10[-v7 - 4] = v12;
          --v11;
        }
        while ( v11 );
      }
      v5 += 16;
      v6 += v7;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 438
// RVA: 0xD83260
__int64 __fastcall hkpSimpleContactConstraintData::freeContactPoint(hkpSimpleContactConstraintData *this, hkpConstraintOwner *constraintOwner, __int64 id)
{
  char *v3; // rax
  hkpSimpleContactConstraintAtom *v4; // r12
  signed int v5; // edi
  signed int v6; // esi
  hkpConstraintOwner *v7; // r15
  int v8; // er14
  hkpSimpleContactConstraintAtom *v9; // rax
  int v10; // er13
  hkpSimpleContactConstraintData *v11; // rbx
  signed int v12; // ebp
  int v13; // esi
  int v14; // edi
  int v15; // ebp
  char *v16; // rax
  hkpSimpleContactConstraintAtom *v17; // rax
  hkpSimpleContactConstraintAtom *v18; // r12
  int v19; // ecx
  __int64 i; // rdx
  char *v21; // r8
  unsigned __int8 v22; // al
  hkpConstraintInstance *v23; // rcx
  hkConstraintInternal *v24; // rcx
  hkpConstraintAtom *oldAtom; // [rsp+70h] [rbp+8h]
  hkPadSpu<bool> atomReallocated; // [rsp+80h] [rbp+18h]

  v3 = this->m_idMgrA.m_values.m_data;
  v4 = this->m_atom;
  v5 = 0;
  id = (unsigned __int16)id;
  v6 = 0;
  v7 = constraintOwner;
  v8 = (unsigned __int8)v3[(unsigned __int16)id];
  v3[id] = -1;
  v9 = this->m_atom;
  atomReallocated.m_storage = 0;
  v10 = v4->m_numContactPoints;
  v11 = this;
  v12 = 0;
  oldAtom = (hkpConstraintAtom *)&v9->m_type;
  if ( v10 == 2 )
  {
    v6 = 1;
    v5 = 48;
    v12 = 1;
  }
  v13 = v6 + 1;
  if ( v10 & 1 )
    v14 = v5 + 48;
  else
    v14 = v5 + 64;
  v15 = v12 + 1;
  hkpSimpleContactConstraintAtomUtil::removeAtAndCopy(v4, v8);
  v16 = (char *)v4 + (unsigned __int8)v4->m_contactPointPropertiesStriding * (signed int)(signed __int16)v8;
  v16[32 * v4->m_numReservedContactPoints + 67] &= 0xFDu;
  v17 = hkpSimpleContactConstraintAtomUtil::optimizeCapacity(v11->m_atom, 1, &atomReallocated);
  v11->m_atom = v17;
  v18 = v17;
  v19 = v11->m_idMgrA.m_values.m_size - 1;
  for ( i = v19; i >= 0; --i )
  {
    v21 = v11->m_idMgrA.m_values.m_data;
    v22 = v21[i];
    if ( v22 != -1 && v22 > v8 )
      v21[i] = v22 - 1;
  }
  v23 = v11->m_constraint;
  if ( v23->m_internal )
  {
    v7->m_constraintInfo.m_sizeOfSchemas -= v14;
    v7->m_constraintInfo.m_numSolverResults -= v13;
    v7->m_constraintInfo.m_numSolverElemTemps -= v15;
    v24 = v23->m_internal;
    v24->m_numSolverResults -= v13;
    v24->m_numSolverElemTemps -= v15;
    v24->m_sizeOfSchemas -= v14;
  }
  if ( atomReallocated.m_storage )
  {
    hkpWorldConstraintUtil::updateFatherOfMovedAtom(
      v11->m_constraint,
      oldAtom,
      (hkpConstraintAtom *)&v11->m_atom->m_type,
      v11->m_atom->m_sizeOfAllAtoms);
    v11->m_atomSize = v11->m_atom->m_sizeOfAllAtoms;
  }
  v18->m_info.m_flags |= 5u;
  return (unsigned int)(v10 - 1);
}

// File Line: 501
// RVA: 0xD839C0
void __fastcall hkpSimpleConstraintContactMgr::removeContactPointImpl(hkpSimpleConstraintContactMgr *this, unsigned __int16 cpId, hkpConstraintOwner *constraintOwner)
{
  hkpEntity *v3; // rbp
  hkpEntity *v4; // rsi
  unsigned __int16 v5; // r14
  hkpConstraintOwner *v6; // rdi
  hkpSimpleConstraintContactMgr *v7; // rbx
  int v8; // er8
  hkpContactPointProperties *v9; // rax
  hkpWorld *v10; // rcx
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-58h]

  v3 = this->m_constraint.m_entities[0];
  v4 = this->m_constraint.m_entities[1];
  v5 = cpId;
  v6 = constraintOwner;
  v7 = this;
  v8 = (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[cpId];
  if ( v8 == 255 )
    v9 = 0i64;
  else
    v9 = (hkpContactPointProperties *)((char *)&this->m_contactConstraintData.m_atom[1]
                                     + 32 * this->m_contactConstraintData.m_atom->m_numReservedContactPoints
                                     + (unsigned __int8)this->m_contactConstraintData.m_atom->m_contactPointPropertiesStriding
                                     * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[cpId]);
  v10 = this->m_world;
  event.m_contactPointId = cpId;
  event.m_contactPointProperties = v9;
  event.m_entityA = v3;
  event.m_entityB = v4;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&v7->vfptr;
  event.m_constraintOwner = v6;
  hkpWorldCallbackUtil::fireContactPointRemoved(v10, &event);
  if ( v3->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v3, &event);
  if ( v4->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v4, &event);
  if ( !(unsigned int)hkpSimpleContactConstraintData::freeContactPoint(&v7->m_contactConstraintData, v6, v5) )
    v6->vfptr[2].__vecDelDtor((hkBaseObject *)&v6->vfptr, (unsigned int)&v7->m_constraint);
}

// File Line: 531
// RVA: 0xD83590
hkContactPoint *__fastcall hkpSimpleConstraintContactMgr::getContactPoint(hkpSimpleConstraintContactMgr *this, unsigned __int16 id)
{
  return (hkContactPoint *)((char *)&this->m_contactConstraintData.m_atom[1]
                          + 32 * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[id]);
}

// File Line: 537
// RVA: 0xD835C0
hkpContactPointProperties *__fastcall hkpSimpleConstraintContactMgr::getContactPointProperties(hkpSimpleConstraintContactMgr *this, unsigned __int16 id)
{
  int v2; // er8
  hkpContactPointProperties *result; // rax

  v2 = (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[id];
  if ( v2 == 255 )
    result = 0i64;
  else
    result = (hkpContactPointProperties *)((char *)&this->m_contactConstraintData.m_atom[1]
                                         + 32 * this->m_contactConstraintData.m_atom->m_numReservedContactPoints
                                         + (unsigned __int8)this->m_contactConstraintData.m_atom->m_contactPointPropertiesStriding
                                         * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[id]);
  return result;
}

// File Line: 543
// RVA: 0xD83FC0
void __fastcall hkpSimpleConstraintContactMgr::getAllContactPointIds(hkpSimpleConstraintContactMgr *this, hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds)
{
  hkpDynamicsCpIdMgr::getAllUsedIds(&this->m_contactConstraintData.m_idMgrA, contactPointIds);
}

// File Line: 548
// RVA: 0xD83FF0
void __fastcall hkpSimpleConstraintContactMgr::toiCollisionResponseBeginCallback(hkpSimpleConstraintContactMgr *this, hkContactPoint *cp, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  ((void (__fastcall *)(hkpSimpleContactConstraintData *, hkContactPoint *, hkpSimpleConstraintInfoInitInput *, hkpBodyVelocity *))this->m_contactConstraintData.vfptr[11].__first_virtual_table_function__)(
    &this->m_contactConstraintData,
    cp,
    inA,
    velA);
}

// File Line: 555
// RVA: 0xD84010
void __fastcall hkpSimpleConstraintContactMgr::toiCollisionResponseEndCallback(hkpSimpleConstraintContactMgr *this, hkContactPoint *cp, float impulseApplied, hkpSimpleConstraintInfoInitInput *inA, hkpBodyVelocity *velA, hkpSimpleConstraintInfoInitInput *inB, hkpBodyVelocity *velB)
{
  ((void (__fastcall *)(hkpSimpleContactConstraintData *, hkContactPoint *, hkBaseObjectVtbl *, hkpSimpleConstraintInfoInitInput *))this->m_contactConstraintData.vfptr[12].__vecDelDtor)(
    &this->m_contactConstraintData,
    cp,
    this->m_contactConstraintData.vfptr,
    inA);
}

// File Line: 563
// RVA: 0xD83AD0
void __fastcall hkpSimpleConstraintContactMgr::processContactImpl(hkpSimpleConstraintContactMgr *this, hkpCollidable *a, hkpCollidable *b, hkpProcessCollisionInput *input, hkpProcessCollisionData *collisionData)
{
  unsigned __int16 v5; // si
  hkpSimpleConstraintContactMgr *v6; // rbx
  __int64 v7; // r14
  hkpEntity *v8; // rbp
  unsigned __int16 v9; // cx
  hkpEntity *v10; // r14
  unsigned __int16 v11; // ax
  hkpProcessCdPoint *v12; // r11
  hkpProcessCdPoint *v13; // r8
  _QWORD *v14; // r9
  char *v15; // r15
  int v16; // er10
  signed __int64 v17; // rax
  hkpProcessCdPoint *v18; // r9
  hkpProcessCdPoint *v19; // rax
  __int64 v20; // rdx
  __m128 v21; // xmm0
  hkpSimpleContactConstraintAtom *v22; // rcx
  signed __int64 v23; // r8
  hkpContactProcessEvent event; // [rsp+20h] [rbp-848h]

  v5 = this->m_contactPointCallbackDelay - 1;
  v6 = this;
  if ( !this->m_contactPointCallbackDelay )
  {
    v7 = a->m_ownerOffset;
    v8 = (hkpEntity *)((char *)b + b->m_ownerOffset);
    event.m_collidableB = b;
    v9 = v8->m_contactPointCallbackDelay;
    v10 = (hkpEntity *)((char *)a + v7);
    event.m_collidableA = a;
    v11 = v10->m_contactPointCallbackDelay;
    event.m_collisionData = collisionData;
    event.m_internalContactMgr = (hkpDynamicsContactMgr *)&v6->vfptr;
    v12 = collisionData->m_firstFreeContactPoint.m_storage;
    v13 = collisionData->m_contactPoints;
    if ( v11 < v9 )
      v9 = v11;
    v14 = event.m_contactPointProperties;
    v5 = v9;
    if ( v13 < v12 )
    {
      v15 = v6->m_contactConstraintData.m_idMgrA.m_values.m_data;
      do
      {
        v16 = (unsigned __int8)v15[v13->m_contactPointId];
        if ( v16 == 255 )
          v17 = 0i64;
        else
          v17 = (signed __int64)&v6->m_contactConstraintData.m_atom[1]
              + 32 * v6->m_contactConstraintData.m_atom->m_numReservedContactPoints
              + (unsigned __int8)v6->m_contactConstraintData.m_atom->m_contactPointPropertiesStriding
              * (unsigned __int8)v15[v13->m_contactPointId];
        ++v13;
        *v14 = v17;
        ++v14;
      }
      while ( v13 < v12 );
    }
    hkpWorldCallbackUtil::fireContactProcess(v6->m_world, &event);
    if ( v10->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v10, &event);
    if ( v8->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v8, &event);
    ((void (__fastcall *)(hkpConstraintOwner *, hkpConstraintInstance *, signed __int64))collisionData->m_constraintOwner.m_storage->vfptr[2].__first_virtual_table_function__)(
      collisionData->m_constraintOwner.m_storage,
      v6->m_contactConstraintData.m_constraint,
      8i64);
  }
  v6->m_contactPointCallbackDelay = v5;
  v18 = collisionData->m_firstFreeContactPoint.m_storage;
  v19 = collisionData->m_contactPoints;
  if ( collisionData->m_contactPoints < collisionData->m_firstFreeContactPoint.m_storage )
  {
    do
    {
      v20 = (signed int)v19->m_contactPointId;
      v21 = v19->m_contact.m_position.m_quad;
      v22 = v6->m_contactConstraintData.m_atom;
      ++v19;
      v23 = 32i64 * (unsigned __int8)v6->m_contactConstraintData.m_idMgrA.m_values.m_data[v20];
      _mm_stream_ps((float *)((char *)&v22[1].m_type.m_storage + v23), v21);
      _mm_stream_ps((float *)((char *)&v22[1].m_info.m_flags + v23), v19[-1].m_contact.m_separatingNormal.m_quad);
    }
    while ( v19 < v18 );
  }
}

// File Line: 644
// RVA: 0xD84030
void __fastcall hkpSimpleConstraintContactMgr::Factory::Factory(hkpSimpleConstraintContactMgr::Factory *this, hkpWorld *mgr)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleConstraintContactMgr::Factory::`vftable;
}

// File Line: 649
// RVA: 0xD84050
void __fastcall hkpSimpleConstraintContactMgr::Factory::createContactMgr(hkpSimpleConstraintContactMgr::Factory *this, hkpCollidable *a, hkpCollidable *b, hkpCollisionInput *input)
{
  hkpSimpleConstraintContactMgr::Factory *v4; // rsi
  hkpRigidBody *v5; // rbx
  hkpRigidBody *v6; // rdi
  _QWORD **v7; // rax
  hkpSimpleConstraintContactMgr *v8; // rax

  v4 = this;
  v5 = (hkpRigidBody *)((char *)a + a->m_ownerOffset);
  v6 = (hkpRigidBody *)((char *)b + b->m_ownerOffset);
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpSimpleConstraintContactMgr *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                          v7[11],
                                          240i64);
  if ( v8 )
    hkpSimpleConstraintContactMgr::hkpSimpleConstraintContactMgr(v8, v4->m_world, v5, v6);
}

