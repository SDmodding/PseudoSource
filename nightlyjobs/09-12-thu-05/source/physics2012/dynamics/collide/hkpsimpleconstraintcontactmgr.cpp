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
hkpConstraintInstance *__fastcall hkpSimpleConstraintContactMgr::getConstraintInstance(
        hkpSimpleConstraintContactMgr *this)
{
  return &this->m_constraint;
}

// File Line: 57
// RVA: 0xD83FE0
hkpConstraintInstance *__fastcall hkpSimpleConstraintContactMgr::getConstraintInstance(
        hkpSimpleConstraintContactMgr *this)
{
  return &this->m_constraint;
}

// File Line: 66
// RVA: 0xD833E0
void __fastcall hkpSimpleConstraintContactMgr::hkpSimpleConstraintContactMgr(
        hkpSimpleConstraintContactMgr *this,
        hkpWorld *sm,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB)
{
  hkpSimpleContactConstraintData *p_m_contactConstraintData; // rbx
  float v9; // [rsp+60h] [rbp+8h]

  p_m_contactConstraintData = &this->m_contactConstraintData;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleConstraintContactMgr::`vftable;
  this->m_type = TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR;
  hkpSimpleContactConstraintData::hkpSimpleContactConstraintData(
    &this->m_contactConstraintData,
    &this->m_constraint,
    bodyA,
    bodyB);
  hkpConstraintInstance::hkpConstraintInstance(&this->m_constraint, PRIORITY_PSI);
  this->m_constraint.m_data = p_m_contactConstraintData;
  this->m_constraint.m_entities[0] = bodyA;
  this->m_constraint.m_entities[1] = bodyB;
  this->m_constraint.m_uid = -1;
  this->m_world = sm;
  *(_DWORD *)&this->m_reservedContactPoints = 0;
  this->m_contactConstraintData.m_memSizeAndFlags = 0;
  this->m_constraint.m_memSizeAndFlags = 0;
  hkpConstraintInstance::setPriority(
    &this->m_constraint,
    (hkpConstraintInstance::ConstraintPriority)sm->m_collisionDispatcher->m_collisionQualityInfo[(__int64)sm->m_collisionDispatcher->m_collisionQualityTable[bodyA->m_collidable.m_broadPhaseHandle.m_objectQualityType][bodyB->m_collidable.m_broadPhaseHandle.m_objectQualityType]].m_constraintPriority);
  v9 = fmaxf(
         COERCE_FLOAT(bodyA->m_material.m_rollingFrictionMultiplier.m_value << 16),
         COERCE_FLOAT(bodyB->m_material.m_rollingFrictionMultiplier.m_value << 16))
     * 1.0039062;
  this->m_contactConstraintData.m_atom->m_info.m_rollingFrictionMultiplier.m_value = HIWORD(v9);
}

// File Line: 108
// RVA: 0xD83520
void __fastcall hkpSimpleConstraintContactMgr::~hkpSimpleConstraintContactMgr(hkpSimpleConstraintContactMgr *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleConstraintContactMgr::`vftable;
  if ( this->m_contactConstraintData.m_atom->m_numContactPoints )
    hkpWorldOperationUtil::removeConstraintImmediately(this->m_world, &this->m_constraint, DO_FIRE_CALLBACKS);
  this->m_constraint.m_entities[0] = 0i64;
  this->m_constraint.m_entities[1] = 0i64;
  this->m_constraint.m_data = 0i64;
  hkpConstraintInstance::~hkpConstraintInstance(&this->m_constraint);
  hkpSimpleContactConstraintData::~hkpSimpleContactConstraintData(&this->m_contactConstraintData);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 131
// RVA: 0xD83970
hkResult *__fastcall hkpSimpleConstraintContactMgr::reserveContactPointsImpl(
        hkpSimpleConstraintContactMgr *this,
        hkResult *result,
        int numPoints)
{
  char m_reservedContactPoints; // al

  if ( numPoints + this->m_contactConstraintData.m_atom->m_numContactPoints + this->m_reservedContactPoints <= this->m_contactConstraintData.m_atom->m_maxNumContactPoints - 2 )
  {
    m_reservedContactPoints = this->m_reservedContactPoints;
    result->m_enum = HK_SUCCESS;
    this->m_reservedContactPoints = (unsigned __int8)(numPoints + m_reservedContactPoints);
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 145
// RVA: 0xD83DE0
void __fastcall hkpSimpleConstraintContactMgr::removeToiImpl(
        hkpSimpleConstraintContactMgr *this,
        hkpConstraintOwner *constraintOwner,
        hkpContactPointProperties *properties)
{
  hkpEntity *v3; // rdi
  hkpEntity *v4; // rbx
  hkpWorld *m_world; // rcx
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-48h] BYREF

  v3 = this->m_constraint.m_entities[0];
  v4 = this->m_constraint.m_entities[1];
  event.m_contactPointId = -1;
  event.m_internalContactMgr = this;
  m_world = this->m_world;
  event.m_constraintOwner = constraintOwner;
  event.m_contactPointProperties = properties;
  event.m_entityA = v3;
  event.m_entityB = v4;
  hkpWorldCallbackUtil::fireContactPointRemoved(m_world, &event);
  if ( v3->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v3, &event);
  if ( v4->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v4, &event);
}

// File Line: 164
// RVA: 0xD83E70
hkBool *__fastcall hkpSimpleConstraintContactMgr::fireCallbacksForEarliestToi(
        hkpSimpleConstraintContactMgr *this,
        hkBool *result,
        hkpToiEvent *event,
        float *rotateNormal)
{
  hkpRigidBody *v4; // rax
  hkpEntity *v8; // rcx
  hkpEntity *v9; // rcx
  hkpModifierConstraintAtom *m_constraintModifiers; // rax
  hkpContactPointEvent eventa; // [rsp+20h] [rbp-78h] BYREF

  v4 = (hkpRigidBody *)event->m_entities[1];
  eventa.m_source = SOURCE_WORLD;
  eventa.m_contactMgr = this;
  eventa.m_bodies[1] = v4;
  eventa.m_bodies[0] = (hkpRigidBody *)event->m_entities[0];
  eventa.m_type = TYPE_TOI;
  eventa.m_contactPoint = &event->m_contactPoint;
  eventa.m_contactPointProperties = &event->m_properties;
  *(_WORD *)&eventa.m_firingCallbacksForFullManifold.m_bool = 0;
  eventa.m_lastCallbackForFullManifold.m_bool = 0;
  eventa.m_rotateNormal = rotateNormal;
  eventa.m_accumulators[0] = 0i64;
  eventa.m_separatingVelocity = &event->m_seperatingVelocity;
  eventa.m_accumulators[1] = 0i64;
  eventa.m_shapeKeyStorage = event->m_extendedUserDatas;
  hkpWorldCallbackUtil::fireContactPointCallback(eventa.m_bodies[0]->m_world, &eventa);
  v8 = event->m_entities[0];
  eventa.m_source = SOURCE_A;
  if ( v8->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v8, &eventa);
  v9 = event->m_entities[1];
  eventa.m_source = SOURCE_B;
  if ( v9->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v9, &eventa);
  m_constraintModifiers = this->m_constraint.m_constraintModifiers;
  result->m_bool = (!m_constraintModifiers || m_constraintModifiers->m_type.m_storage != 34)
                && (event->m_properties.m_flags & 8) == 0;
  return result;
}

// File Line: 187
// RVA: 0xD83F80
void __fastcall hkpSimpleConstraintContactMgr::confirmToi(
        hkpSimpleConstraintContactMgr *this,
        hkpToiEvent *event,
        float rotateNormal,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *outToBeActivated)
{
  hkpEntity *v4; // rax

  v4 = event->m_entities[0];
  if ( (event->m_properties.m_flags & 8) == 0
    && ((unsigned __int8)(v4->m_motion.m_type.m_storage - 4) > 1u
     || (unsigned __int8)(event->m_entities[1]->m_motion.m_type.m_storage - 4) > 1u) )
  {
    hkLs_doSimpleCollisionResponse(v4->m_world, event, rotateNormal, outToBeActivated);
  }
}

// File Line: 210
// RVA: 0xD843A0
hkpRigidBody *__fastcall hkpSimpleConstraintContactMgr::setContactPointProperties(
        hkpSimpleConstraintContactMgr *this,
        hkpCdBody *a,
        hkpCdBody *b,
        int maxNumExtraDataInEvent,
        hkpContactPointProperties *cpi)
{
  hkpEntity *v5; // r15
  hkpEntity *v6; // r14
  hkpContactPointProperties *v7; // rdi
  hkpCdBody *v12; // rcx
  float v13; // xmm0_4
  hkpCdBody *i; // rax
  hkpSimpleContactConstraintAtom *m_atom; // rax
  int m_numUserDatasForBodyA; // edx
  int m_numUserDatasForBodyB; // r8d
  hkpEntity *v18; // r9
  hkpCdBody *v19; // rcx
  int v20; // eax
  int v21; // esi
  __int64 v22; // rdx
  __int64 j; // r8
  float fv; // [rsp+50h] [rbp+8h] BYREF

  v5 = this->m_constraint.m_entities[1];
  v6 = this->m_constraint.m_entities[0];
  v7 = cpi;
  fv = fsqrt(v5->m_material.m_friction * v6->m_material.m_friction);
  hkUFloat8::operator=(&cpi->m_friction, &fv);
  v12 = a;
  v13 = v5->m_material.m_restitution * v6->m_material.m_restitution;
  v7->m_maxImpulse.m_value = 0;
  *(float *)&cpi = fsqrt(v13) * 128.0;
  v7->m_restitution = (int)*(float *)&cpi;
  for ( i = a->m_parent; i; i = i->m_parent )
    v12 = i;
  m_atom = this->m_contactConstraintData.m_atom;
  m_numUserDatasForBodyA = (unsigned __int8)m_atom->m_numUserDatasForBodyA;
  m_numUserDatasForBodyB = (unsigned __int8)m_atom->m_numUserDatasForBodyB;
  v18 = (hkpEntity *)((char *)v12 + SLOBYTE(v12[1].m_shape));
  if ( m_numUserDatasForBodyB + m_numUserDatasForBodyA )
  {
    if ( v18 == v6 )
    {
      v19 = a;
    }
    else
    {
      v19 = b;
      v18 = v5;
      b = a;
    }
    v20 = maxNumExtraDataInEvent;
    if ( m_numUserDatasForBodyA < maxNumExtraDataInEvent )
      v20 = m_numUserDatasForBodyA;
    v21 = maxNumExtraDataInEvent - v20;
    if ( m_numUserDatasForBodyB < v21 )
      v21 = m_numUserDatasForBodyB;
    if ( v19->m_shapeKey == -1 && v19->m_parent )
      v19 = v19->m_parent;
    v22 = 0i64;
    for ( j = 0i64; v19; v19 = v19->m_parent )
    {
      if ( j >= v20 )
        break;
      *((_DWORD *)&v7->m_internalDataA + ++j + 1) = v19->m_shapeKey;
    }
    if ( b->m_shapeKey == -1 && b->m_parent )
      b = b->m_parent;
    for ( ; b; b = b->m_parent )
    {
      if ( v22 >= v21 )
        break;
      ++v22;
      *((_DWORD *)&v7->m_internalDataA + v20 + v22 + 1) = b->m_shapeKey;
    }
  }
  return (hkpRigidBody *)v18;
}

// File Line: 295
// RVA: 0xD83C80
__int64 __fastcall hkpSimpleConstraintContactMgr::addToiImpl(
        hkpSimpleConstraintContactMgr *this,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        float toi,
        hkContactPoint *cp,
        hkpGskCache *gskCache,
        float *projectedVelocity,
        hkpContactPointProperties *properties)
{
  hkpRigidBody *v14; // rax
  unsigned __int64 v15; // rbp
  __int64 v16; // rbp
  hkpWorld *m_world; // rcx
  hkpEntity *v18; // r15
  hkpEntity *v19; // rbp
  __int64 result; // rax
  hkpContactPointAddedEvent event; // [rsp+30h] [rbp-78h] BYREF
  float v22; // [rsp+88h] [rbp-20h]

  v14 = hkpSimpleConstraintContactMgr::setContactPointProperties(this, a, b, 7, properties);
  v15 = (unsigned __int64)this->m_constraint.m_entities[1];
  event.m_contactPoint = cp;
  v16 = (unsigned __int64)this->m_constraint.m_entities[0] ^ v15;
  event.m_bodyA = a;
  event.m_bodyB = b;
  event.m_gskCache = gskCache;
  event.m_projectedVelocity = *projectedVelocity;
  v22 = toi;
  m_world = this->m_world;
  v18 = v14;
  v19 = (hkpEntity *)((unsigned __int64)v14 ^ v16);
  event.m_contactPointProperties = properties;
  event.m_internalContactMgr = this;
  event.m_collisionInput = input;
  event.m_collisionOutput = output;
  event.m_type.m_storage = 0;
  event.m_status = HK_CONTACT_POINT_ACCEPT;
  hkpWorldCallbackUtil::fireContactPointAdded(m_world, &event);
  if ( v18->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v18, &event);
  if ( v19->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v19, &event);
  result = (unsigned int)event.m_status;
  if ( event.m_status == HK_CONTACT_POINT_REJECT )
  {
    ((void (__fastcall *)(hkpSimpleConstraintContactMgr *, hkpConstraintOwner *, hkpContactPointProperties *))this->vfptr[4].__vecDelDtor)(
      this,
      output->m_constraintOwner.m_storage,
      properties);
    return (unsigned int)event.m_status;
  }
  else
  {
    *projectedVelocity = event.m_projectedVelocity;
  }
  return result;
}

// File Line: 322
// RVA: 0xD83610
__int64 __fastcall hkpSimpleConstraintContactMgr::addContactPointImpl(
        hkpSimpleConstraintContactMgr *this,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        hkpGskCache *contactCache,
        hkContactPoint *cp)
{
  hkpSimpleContactConstraintAtom *m_atom; // rax
  hkpProcessCollisionOutput *v13; // rsi
  unsigned __int16 v14; // ax
  hkContactPoint *v15; // rbx
  unsigned __int16 v16; // r12
  unsigned __int64 v17; // rax
  __m128 m_quad; // xmm2
  __m128 v19; // xmm1
  __int64 v20; // r14
  hkpRigidBody *v21; // r15
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  hkpEntity *v24; // r14
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  float v29; // xmm6_4
  __m128 v30; // xmm2
  __m128 v31; // xmm2
  float v32; // xmm1_4
  hkpContactPointProperties *cpPropsOut; // [rsp+30h] [rbp-71h] BYREF
  hkpContactPointAddedEvent event; // [rsp+40h] [rbp-61h] BYREF
  unsigned __int16 v35; // [rsp+98h] [rbp-9h]
  unsigned __int16 m_contactPointCallbackDelay; // [rsp+9Ah] [rbp-7h]
  hkContactPoint *cpOut; // [rsp+F0h] [rbp+4Fh] BYREF
  hkpCdBody *v38; // [rsp+F8h] [rbp+57h]
  hkpCdBody *v39; // [rsp+100h] [rbp+5Fh]

  v39 = b;
  v38 = a;
  m_atom = this->m_contactConstraintData.m_atom;
  if ( m_atom->m_numContactPoints + this->m_reservedContactPoints > m_atom->m_maxNumContactPoints - 2 )
    return 0xFFFFi64;
  v13 = output;
  if ( !m_atom->m_numContactPoints )
    ((void (__fastcall *)(hkpConstraintOwner *, hkpConstraintInstance *))output->m_constraintOwner.m_storage->vfptr[1].__first_virtual_table_function__)(
      output->m_constraintOwner.m_storage,
      &this->m_constraint);
  v14 = hkpSimpleContactConstraintData::allocateContactPoint(
          &this->m_contactConstraintData,
          v13->m_constraintOwner.m_storage,
          &cpOut,
          &cpPropsOut);
  v15 = cp;
  *cpOut = *cp;
  v16 = v14;
  v17 = (unsigned __int64)hkpSimpleConstraintContactMgr::setContactPointProperties(this, a, b, 10000, cpPropsOut);
  m_quad = v15->m_position.m_quad;
  v19 = v15->m_position.m_quad;
  v20 = (__int64)this->m_constraint.m_entities[0] ^ (__int64)this->m_constraint.m_entities[1];
  v21 = (hkpRigidBody *)v17;
  event.m_contactPoint = v15;
  v22 = *(__m128 *)(v17 + 576);
  v23 = _mm_sub_ps(v19, *(__m128 *)(v17 + 448));
  v24 = (hkpEntity *)(v17 ^ v20);
  event.m_type.m_storage = 1;
  event.m_internalContactMgr = this;
  event.m_collisionInput = input;
  event.m_collisionOutput = v13;
  event.m_status = HK_CONTACT_POINT_ACCEPT;
  v25 = _mm_sub_ps(m_quad, v24->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v35 = v16;
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23));
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(v24->m_motion.m_angularVelocity.m_quad, v24->m_motion.m_angularVelocity.m_quad, 201),
            v25));
  v28 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 201), *(__m128 *)(v17 + 560)),
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 201), v24->m_motion.m_linearVelocity.m_quad)),
          v15->m_separatingNormal.m_quad);
  cpPropsOut->m_impulseApplied = 0.0;
  cpPropsOut->m_userData = 0i64;
  event.m_bodyA = v38;
  v29 = (float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
      + _mm_shuffle_ps(v28, v28, 170).m128_f32[0];
  event.m_bodyB = v39;
  event.m_projectedVelocity = v29;
  event.m_gskCache = contactCache;
  event.m_contactPointProperties = cpPropsOut;
  if ( this->m_type )
    m_contactPointCallbackDelay = 0;
  else
    m_contactPointCallbackDelay = this->m_contactPointCallbackDelay;
  hkpWorldCallbackUtil::fireContactPointAdded(this->m_world, &event);
  if ( v21->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v21, &event);
  if ( v24->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(v24, &event);
  if ( event.m_status == HK_CONTACT_POINT_REJECT )
  {
    ((void (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD, hkpConstraintOwner *))this->vfptr[2].__first_virtual_table_function__)(
      this,
      v16,
      v13->m_constraintOwner.m_storage);
    return 0xFFFFi64;
  }
  else
  {
    this->m_contactPointCallbackDelay = m_contactPointCallbackDelay;
    if ( !input->m_allowToSkipConfirmedCallbacks.m_bool
      || (float)((float)(unsigned __int8)cpPropsOut->m_restitution * 0.0078125) != 0.0
      || v21->m_contactListeners.m_size
      || v24->m_contactListeners.m_size )
    {
      ((void (__fastcall *)(hkpConstraintOwner *, hkpConstraintInstance *, __int64))v13->m_constraintOwner.m_storage->vfptr[2].__first_virtual_table_function__)(
        v13->m_constraintOwner.m_storage,
        this->m_contactConstraintData.m_constraint,
        1i64);
    }
    else
    {
      v30 = v21->m_motion.m_inertiaAndMassInv.m_quad;
      *(float *)&cpOut = FLOAT_1_0eN10;
      v31 = _mm_add_ps(
              _mm_add_ps(
                _mm_shuffle_ps(v30, v30, 255),
                _mm_shuffle_ps(v24->m_motion.m_inertiaAndMassInv.m_quad, v24->m_motion.m_inertiaAndMassInv.m_quad, 255)),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0eN10), (__m128)LODWORD(FLOAT_1_0eN10), 0));
      v32 = _mm_rcp_ps(v31).m128_f32[0];
      *(float *)&cpOut = FLOAT_N0_2;
      cpPropsOut->m_impulseApplied = (float)(_mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_2), (__m128)LODWORD(FLOAT_N0_2), 0).m128_f32[0]
                                           * (float)((float)(2.0 - (float)(v32 * v31.m128_f32[0])) * v32))
                                   * v29;
      cpPropsOut->m_internalSolverData = 0.0;
      cpPropsOut->m_internalDataA = 0.0;
    }
    return v16;
  }
}

// File Line: 417
// RVA: 0xD842E0
void __fastcall hkpSimpleContactConstraintAtomUtil::removeAtAndCopy(hkpSimpleContactConstraintAtom *atom, int index)
{
  int m_contactPointPropertiesStriding; // ebx
  int v3; // r11d
  unsigned __int16 *v4; // r10
  char *v5; // r8
  __int64 v6; // rsi
  int v7; // ebx
  __int64 v8; // rdi
  char *v9; // rax
  __int64 v10; // rdx
  int v11; // ecx

  m_contactPointPropertiesStriding = (unsigned __int8)atom->m_contactPointPropertiesStriding;
  v3 = --atom->m_numContactPoints;
  v4 = &atom[1].m_type.m_storage + 16 * index;
  v5 = (char *)&atom[1] + 32 * atom->m_numReservedContactPoints + (__int16)index * m_contactPointPropertiesStriding;
  if ( index < v3 )
  {
    v6 = (unsigned int)m_contactPointPropertiesStriding;
    v7 = m_contactPointPropertiesStriding >> 2;
    v8 = (unsigned int)(v3 - index);
    do
    {
      *(_OWORD *)v4 = *((_OWORD *)v4 + 2);
      v9 = &v5[v6];
      *((_OWORD *)v4 + 1) = *((_OWORD *)v4 + 3);
      if ( v7 > 0 )
      {
        v10 = (unsigned int)v7;
        do
        {
          v11 = *(_DWORD *)v9;
          v9 += 4;
          *(_DWORD *)&v9[-v6 - 4] = v11;
          --v10;
        }
        while ( v10 );
      }
      v4 += 16;
      v5 += v6;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 438
// RVA: 0xD83260
__int64 __fastcall hkpSimpleContactConstraintData::freeContactPoint(
        hkpSimpleContactConstraintData *this,
        hkpConstraintOwner *constraintOwner,
        unsigned __int16 id)
{
  char *m_data; // rax
  hkpSimpleContactConstraintAtom *m_atom; // r12
  int v5; // edi
  int v6; // esi
  int v8; // r14d
  hkpSimpleContactConstraintAtom *v9; // rax
  int m_numContactPoints; // r13d
  int v12; // ebp
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
  hkpConstraintInstance *m_constraint; // rcx
  hkConstraintInternal *m_internal; // rcx
  hkpConstraintAtom *oldAtom; // [rsp+70h] [rbp+8h]
  hkPadSpu<bool> atomReallocated; // [rsp+80h] [rbp+18h] BYREF

  m_data = this->m_idMgrA.m_values.m_data;
  m_atom = this->m_atom;
  v5 = 0;
  v6 = 0;
  v8 = (unsigned __int8)m_data[id];
  m_data[id] = -1;
  v9 = this->m_atom;
  atomReallocated.m_storage = 0;
  m_numContactPoints = m_atom->m_numContactPoints;
  v12 = 0;
  oldAtom = v9;
  if ( m_numContactPoints == 2 )
  {
    v6 = 1;
    v5 = 48;
    v12 = 1;
  }
  v13 = v6 + 1;
  if ( (m_numContactPoints & 1) != 0 )
    v14 = v5 + 48;
  else
    v14 = v5 + 64;
  v15 = v12 + 1;
  hkpSimpleContactConstraintAtomUtil::removeAtAndCopy(m_atom, v8);
  v16 = (char *)m_atom + (unsigned __int8)m_atom->m_contactPointPropertiesStriding * (__int16)v8;
  v16[32 * m_atom->m_numReservedContactPoints + 67] &= ~2u;
  v17 = hkpSimpleContactConstraintAtomUtil::optimizeCapacity(this->m_atom, 1, &atomReallocated);
  this->m_atom = v17;
  v18 = v17;
  v19 = this->m_idMgrA.m_values.m_size - 1;
  for ( i = v19; i >= 0; --i )
  {
    v21 = this->m_idMgrA.m_values.m_data;
    v22 = v21[i];
    if ( v22 != 0xFF && v22 > v8 )
      v21[i] = v22 - 1;
  }
  m_constraint = this->m_constraint;
  if ( m_constraint->m_internal )
  {
    constraintOwner->m_constraintInfo.m_sizeOfSchemas -= v14;
    constraintOwner->m_constraintInfo.m_numSolverResults -= v13;
    constraintOwner->m_constraintInfo.m_numSolverElemTemps -= v15;
    m_internal = m_constraint->m_internal;
    m_internal->m_numSolverResults -= v13;
    m_internal->m_numSolverElemTemps -= v15;
    m_internal->m_sizeOfSchemas -= v14;
  }
  if ( atomReallocated.m_storage )
  {
    hkpWorldConstraintUtil::updateFatherOfMovedAtom(
      this->m_constraint,
      oldAtom,
      this->m_atom,
      this->m_atom->m_sizeOfAllAtoms);
    this->m_atomSize = this->m_atom->m_sizeOfAllAtoms;
  }
  v18->m_info.m_flags |= 5u;
  return (unsigned int)(m_numContactPoints - 1);
}

// File Line: 501
// RVA: 0xD839C0
void __fastcall hkpSimpleConstraintContactMgr::removeContactPointImpl(
        hkpSimpleConstraintContactMgr *this,
        unsigned __int16 cpId,
        hkpConstraintOwner *constraintOwner)
{
  hkpEntity *v3; // rbp
  hkpEntity *v4; // rsi
  hkpContactPointProperties *v8; // rax
  hkpWorld *m_world; // rcx
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-58h] BYREF

  v3 = this->m_constraint.m_entities[0];
  v4 = this->m_constraint.m_entities[1];
  if ( (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[cpId] == 255 )
    v8 = 0i64;
  else
    v8 = (hkpContactPointProperties *)((char *)&this->m_contactConstraintData.m_atom[1]
                                     + 32 * this->m_contactConstraintData.m_atom->m_numReservedContactPoints
                                     + (unsigned __int8)this->m_contactConstraintData.m_atom->m_contactPointPropertiesStriding
                                     * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[cpId]);
  m_world = this->m_world;
  event.m_contactPointId = cpId;
  event.m_contactPointProperties = v8;
  event.m_entityA = v3;
  event.m_entityB = v4;
  event.m_internalContactMgr = this;
  event.m_constraintOwner = constraintOwner;
  hkpWorldCallbackUtil::fireContactPointRemoved(m_world, &event);
  if ( v3->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v3, &event);
  if ( v4->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(v4, &event);
  if ( !(unsigned int)hkpSimpleContactConstraintData::freeContactPoint(
                        &this->m_contactConstraintData,
                        constraintOwner,
                        cpId) )
    constraintOwner->vfptr[2].__vecDelDtor(constraintOwner, (unsigned int)&this->m_constraint);
}

// File Line: 531
// RVA: 0xD83590
hkContactPoint *__fastcall hkpSimpleConstraintContactMgr::getContactPoint(
        hkpSimpleConstraintContactMgr *this,
        unsigned __int16 id)
{
  return (hkContactPoint *)((char *)&this->m_contactConstraintData.m_atom[1]
                          + 32 * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[id]);
}

// File Line: 537
// RVA: 0xD835C0
hkpContactPointProperties *__fastcall hkpSimpleConstraintContactMgr::getContactPointProperties(
        hkpSimpleConstraintContactMgr *this,
        unsigned __int16 id)
{
  if ( (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[id] == 255 )
    return 0i64;
  else
    return (hkpContactPointProperties *)((char *)&this->m_contactConstraintData.m_atom[1]
                                       + 32 * this->m_contactConstraintData.m_atom->m_numReservedContactPoints
                                       + (unsigned __int8)this->m_contactConstraintData.m_atom->m_contactPointPropertiesStriding
                                       * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[id]);
}

// File Line: 543
// RVA: 0xD83FC0
void __fastcall hkpSimpleConstraintContactMgr::getAllContactPointIds(
        hkpSimpleConstraintContactMgr *this,
        hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds)
{
  hkpDynamicsCpIdMgr::getAllUsedIds(&this->m_contactConstraintData.m_idMgrA, contactPointIds);
}

// File Line: 548
// RVA: 0xD83FF0
void __fastcall hkpSimpleConstraintContactMgr::toiCollisionResponseBeginCallback(
        hkpSimpleConstraintContactMgr *this,
        hkContactPoint *cp,
        hkpSimpleConstraintInfoInitInput *inA,
        hkpBodyVelocity *velA,
        hkpSimpleConstraintInfoInitInput *inB,
        hkpBodyVelocity *velB)
{
  ((void (__fastcall *)(hkpSimpleContactConstraintData *, hkContactPoint *, hkpSimpleConstraintInfoInitInput *, hkpBodyVelocity *))this->m_contactConstraintData.vfptr[11].__first_virtual_table_function__)(
    &this->m_contactConstraintData,
    cp,
    inA,
    velA);
}

// File Line: 555
// RVA: 0xD84010
void __fastcall hkpSimpleConstraintContactMgr::toiCollisionResponseEndCallback(
        hkpSimpleConstraintContactMgr *this,
        hkContactPoint *cp,
        float impulseApplied,
        hkpSimpleConstraintInfoInitInput *inA,
        hkpBodyVelocity *velA,
        hkpSimpleConstraintInfoInitInput *inB,
        hkpBodyVelocity *velB)
{
  ((void (__fastcall *)(hkpSimpleContactConstraintData *, hkContactPoint *, hkBaseObjectVtbl *, hkpSimpleConstraintInfoInitInput *))this->m_contactConstraintData.vfptr[12].__vecDelDtor)(
    &this->m_contactConstraintData,
    cp,
    this->m_contactConstraintData.vfptr,
    inA);
}

// File Line: 563
// RVA: 0xD83AD0
void __fastcall hkpSimpleConstraintContactMgr::processContactImpl(
        hkpSimpleConstraintContactMgr *this,
        hkpCollidable *a,
        hkpCollidable *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionData *collisionData)
{
  unsigned __int16 v5; // si
  __int64 m_ownerOffset; // r14
  hkpEntity *v8; // rbp
  unsigned __int16 m_contactPointCallbackDelay; // cx
  hkpEntity *v10; // r14
  unsigned __int16 v11; // ax
  hkpProcessCdPoint *m_storage; // r11
  hkpProcessCdPoint *m_contactPoints; // r8
  hkpContactPointProperties **m_contactPointProperties; // r9
  char *m_data; // r15
  hkpContactPointProperties *v16; // rax
  hkpProcessCdPoint *v17; // r9
  hkpProcessCdPoint *i; // rax
  __int64 m_contactPointId; // rdx
  __m128 m_quad; // xmm0
  hkpSimpleContactConstraintAtom *m_atom; // rcx
  __int64 v22; // r8
  hkpContactProcessEvent event; // [rsp+20h] [rbp-848h] BYREF

  v5 = this->m_contactPointCallbackDelay - 1;
  if ( !this->m_contactPointCallbackDelay )
  {
    m_ownerOffset = a->m_ownerOffset;
    v8 = (hkpEntity *)((char *)b + b->m_ownerOffset);
    event.m_collidableB = b;
    m_contactPointCallbackDelay = v8->m_contactPointCallbackDelay;
    v10 = (hkpEntity *)((char *)a + m_ownerOffset);
    event.m_collidableA = a;
    v11 = v10->m_contactPointCallbackDelay;
    event.m_collisionData = collisionData;
    event.m_internalContactMgr = this;
    m_storage = collisionData->m_firstFreeContactPoint.m_storage;
    m_contactPoints = collisionData->m_contactPoints;
    if ( v11 < m_contactPointCallbackDelay )
      m_contactPointCallbackDelay = v11;
    m_contactPointProperties = event.m_contactPointProperties;
    v5 = m_contactPointCallbackDelay;
    if ( m_contactPoints < m_storage )
    {
      m_data = this->m_contactConstraintData.m_idMgrA.m_values.m_data;
      do
      {
        if ( (unsigned __int8)m_data[m_contactPoints->m_contactPointId] == 255 )
          v16 = 0i64;
        else
          v16 = (hkpContactPointProperties *)((char *)&this->m_contactConstraintData.m_atom[1]
                                            + 32 * this->m_contactConstraintData.m_atom->m_numReservedContactPoints
                                            + (unsigned __int8)this->m_contactConstraintData.m_atom->m_contactPointPropertiesStriding
                                            * (unsigned __int8)m_data[m_contactPoints->m_contactPointId]);
        ++m_contactPoints;
        *m_contactPointProperties++ = v16;
      }
      while ( m_contactPoints < m_storage );
    }
    hkpWorldCallbackUtil::fireContactProcess(this->m_world, &event);
    if ( v10->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v10, &event);
    if ( v8->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v8, &event);
    ((void (__fastcall *)(hkpConstraintOwner *, hkpConstraintInstance *, __int64))collisionData->m_constraintOwner.m_storage->vfptr[2].__first_virtual_table_function__)(
      collisionData->m_constraintOwner.m_storage,
      this->m_contactConstraintData.m_constraint,
      8i64);
  }
  this->m_contactPointCallbackDelay = v5;
  v17 = collisionData->m_firstFreeContactPoint.m_storage;
  for ( i = collisionData->m_contactPoints;
        i < v17;
        _mm_stream_ps((float *)((char *)&m_atom[1].m_info.m_flags + v22), i[-1].m_contact.m_separatingNormal.m_quad) )
  {
    m_contactPointId = (int)i->m_contactPointId;
    m_quad = i->m_contact.m_position.m_quad;
    m_atom = this->m_contactConstraintData.m_atom;
    ++i;
    v22 = 32i64 * (unsigned __int8)this->m_contactConstraintData.m_idMgrA.m_values.m_data[m_contactPointId];
    _mm_stream_ps((float *)((char *)&m_atom[1].m_type.m_storage + v22), m_quad);
  }
}

// File Line: 644
// RVA: 0xD84030
void __fastcall hkpSimpleConstraintContactMgr::Factory::Factory(
        hkpSimpleConstraintContactMgr::Factory *this,
        hkpWorld *mgr)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleConstraintContactMgr::Factory::`vftable;
}

// File Line: 649
// RVA: 0xD84050
void __fastcall hkpSimpleConstraintContactMgr::Factory::createContactMgr(
        hkpSimpleConstraintContactMgr::Factory *this,
        hkpCollidable *a,
        hkpCollidable *b,
        hkpCollisionInput *input)
{
  hkpRigidBody *v5; // rbx
  hkpRigidBody *v6; // rdi
  _QWORD **Value; // rax
  hkpSimpleConstraintContactMgr *v8; // rax

  v5 = (hkpRigidBody *)((char *)a + a->m_ownerOffset);
  v6 = (hkpRigidBody *)((char *)b + b->m_ownerOffset);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpSimpleConstraintContactMgr *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          240i64);
  if ( v8 )
    hkpSimpleConstraintContactMgr::hkpSimpleConstraintContactMgr(v8, this->m_world, v5, v6);
}

