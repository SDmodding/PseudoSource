// File Line: 30
// RVA: 0xD85520
void __fastcall hkpReportContactMgr::hkpReportContactMgr(
        hkpReportContactMgr *this,
        hkpWorld *sm,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB)
{
  unsigned __int16 m_contactPointCallbackDelay; // ax
  unsigned __int16 v5; // r10

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = TYPE_REPORT_CONTACT_MGR;
  this->vfptr = (hkBaseObjectVtbl *)&hkpReportContactMgr::`vftable;
  m_contactPointCallbackDelay = bodyA->m_contactPointCallbackDelay;
  v5 = bodyB->m_contactPointCallbackDelay;
  this->m_world = sm;
  this->m_bodyA = bodyA;
  if ( m_contactPointCallbackDelay < v5 )
    v5 = m_contactPointCallbackDelay;
  this->m_bodyB = bodyB;
  this->m_skipNextNprocessCallbacks = v5;
}

// File Line: 38
// RVA: 0xD85570
void __fastcall hkpReportContactMgr::~hkpReportContactMgr(hkpReportContactMgr *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 43
// RVA: 0xD85590
__int64 __fastcall hkpReportContactMgr::addContactPointImpl(
        hkpReportContactMgr *this,
        hkpCdBody *a,
        hkpCdBody *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *output,
        hkpGskCache *contactCache,
        hkContactPoint *pcp)
{
  hkpRigidBody *m_bodyA; // rsi
  hkpRigidBody *m_bodyB; // rdi
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm4
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __int64 result; // rax
  hkpContactPointAddedEvent event; // [rsp+20h] [rbp-68h] BYREF
  __int16 v19; // [rsp+78h] [rbp-10h]
  __int16 v20; // [rsp+7Ah] [rbp-Eh]

  m_bodyA = this->m_bodyA;
  m_bodyB = this->m_bodyB;
  v10 = _mm_sub_ps(pcp->m_position.m_quad, m_bodyB->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v11 = _mm_sub_ps(pcp->m_position.m_quad, m_bodyA->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), m_bodyA->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(m_bodyA->m_motion.m_angularVelocity.m_quad, m_bodyA->m_motion.m_angularVelocity.m_quad, 201),
            v11));
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 201), m_bodyA->m_motion.m_linearVelocity.m_quad);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), m_bodyB->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(m_bodyB->m_motion.m_angularVelocity.m_quad, m_bodyB->m_motion.m_angularVelocity.m_quad, 201),
            v10));
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 201), m_bodyB->m_motion.m_linearVelocity.m_quad);
  event.m_bodyA = a;
  event.m_bodyB = b;
  event.m_type.m_storage = 1;
  event.m_contactPoint = pcp;
  event.m_contactPointProperties = 0i64;
  v16 = _mm_mul_ps(_mm_sub_ps(v15, v13), pcp->m_separatingNormal.m_quad);
  event.m_gskCache = contactCache;
  event.m_projectedVelocity = (float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
                            + _mm_shuffle_ps(v16, v16, 170).m128_f32[0];
  event.m_internalContactMgr = this;
  event.m_collisionInput = input;
  event.m_collisionOutput = output;
  event.m_status = HK_CONTACT_POINT_ACCEPT;
  v19 = 0;
  if ( this->m_type )
    v20 = 0;
  else
    v20 = WORD1(this->m_bodyA);
  hkpWorldCallbackUtil::fireContactPointAdded(this->m_world, &event);
  if ( m_bodyA->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(m_bodyA, &event);
  if ( m_bodyB->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(m_bodyB, &event);
  if ( event.m_status == HK_CONTACT_POINT_REJECT )
  {
    ((void (__fastcall *)(hkpReportContactMgr *, _QWORD, hkpConstraintOwner *))this->vfptr[2].__first_virtual_table_function__)(
      this,
      0i64,
      output->m_constraintOwner.m_storage);
    return 0xFFFFi64;
  }
  else
  {
    result = 0i64;
    this->m_skipNextNprocessCallbacks = v20;
  }
  return result;
}

// File Line: 80
// RVA: 0xD858C0
__int64 __fastcall hkpReportContactMgr::addToiImpl(
        hkpReportContactMgr *this,
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
  hkpRigidBody *m_bodyB; // rdi
  float v12; // xmm0_4
  hkpRigidBody *m_bodyA; // r14
  __int64 result; // rax
  hkpContactPointAddedEvent event; // [rsp+20h] [rbp-78h] BYREF
  float v16; // [rsp+78h] [rbp-20h]

  event.m_bodyA = a;
  event.m_bodyB = b;
  *(_DWORD *)&properties->m_friction.m_value = 0x1000000;
  m_bodyB = this->m_bodyB;
  v12 = *projectedVelocity;
  m_bodyA = this->m_bodyA;
  event.m_type.m_storage = 0;
  event.m_contactPoint = cp;
  event.m_gskCache = gskCache;
  event.m_contactPointProperties = properties;
  event.m_projectedVelocity = v12;
  event.m_internalContactMgr = this;
  event.m_collisionInput = input;
  event.m_collisionOutput = output;
  event.m_status = HK_CONTACT_POINT_ACCEPT;
  v16 = toi;
  hkpWorldCallbackUtil::fireContactPointAdded(this->m_world, &event);
  if ( m_bodyA->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(m_bodyA, &event);
  if ( m_bodyB->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal(m_bodyB, &event);
  result = (unsigned int)event.m_status;
  if ( event.m_status == HK_CONTACT_POINT_REJECT )
  {
    ((void (__fastcall *)(hkpReportContactMgr *, hkpConstraintOwner *, hkpContactPointProperties *))this->vfptr[4].__vecDelDtor)(
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

// File Line: 98
// RVA: 0xD859F0
void __fastcall hkpReportContactMgr::removeToiImpl(
        hkpReportContactMgr *this,
        hkpConstraintOwner *constraintOwner,
        hkpContactPointProperties *properties)
{
  hkpRigidBody *m_bodyA; // rdi
  hkpRigidBody *m_bodyB; // rbx
  hkpWorld *m_world; // rax
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-48h] BYREF

  m_bodyA = this->m_bodyA;
  m_bodyB = this->m_bodyB;
  m_world = m_bodyA->m_world;
  event.m_constraintOwner = constraintOwner;
  event.m_internalContactMgr = this;
  event.m_contactPointId = -1;
  event.m_contactPointProperties = properties;
  event.m_entityA = m_bodyA;
  event.m_entityB = m_bodyB;
  hkpWorldCallbackUtil::fireContactPointRemoved(m_world, &event);
  if ( m_bodyA->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(m_bodyA, &event);
  if ( m_bodyB->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(m_bodyB, &event);
}

// File Line: 109
// RVA: 0xD85730
void __fastcall hkpReportContactMgr::removeContactPointImpl(
        hkpReportContactMgr *this,
        unsigned __int16 cpId,
        hkpConstraintOwner *info)
{
  hkpRigidBody *m_bodyA; // rdi
  hkpRigidBody *m_bodyB; // rbx
  hkpWorld *m_world; // rcx
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-48h] BYREF

  m_bodyA = this->m_bodyA;
  m_bodyB = this->m_bodyB;
  event.m_internalContactMgr = this;
  m_world = this->m_world;
  event.m_contactPointId = cpId;
  event.m_entityA = m_bodyA;
  event.m_entityB = m_bodyB;
  event.m_contactPointProperties = 0i64;
  event.m_constraintOwner = info;
  hkpWorldCallbackUtil::fireContactPointRemoved(m_world, &event);
  if ( m_bodyA->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(m_bodyA, &event);
  if ( m_bodyB->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal(m_bodyB, &event);
}

// File Line: 118
// RVA: 0xD857B0
void __fastcall hkpReportContactMgr::processContactImpl(
        hkpReportContactMgr *this,
        hkpCollidable *a,
        hkpCollidable *b,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionData *collisionData)
{
  __int16 m_skipNextNprocessCallbacks; // r9
  __int64 m_ownerOffset; // rdi
  hkpEntity *v8; // rbx
  unsigned __int16 m_contactPointCallbackDelay; // cx
  hkpEntity *v10; // rdi
  signed __int64 v11; // rcx
  __int64 i; // rax
  hkpContactProcessEvent event; // [rsp+20h] [rbp-838h] BYREF

  m_skipNextNprocessCallbacks = this->m_skipNextNprocessCallbacks;
  this->m_skipNextNprocessCallbacks = m_skipNextNprocessCallbacks - 1;
  if ( !m_skipNextNprocessCallbacks )
  {
    m_ownerOffset = a->m_ownerOffset;
    v8 = (hkpEntity *)((char *)b + b->m_ownerOffset);
    event.m_collidableA = a;
    m_contactPointCallbackDelay = v8->m_contactPointCallbackDelay;
    v10 = (hkpEntity *)((char *)a + m_ownerOffset);
    event.m_collidableB = b;
    if ( v10->m_contactPointCallbackDelay < m_contactPointCallbackDelay )
      m_contactPointCallbackDelay = v10->m_contactPointCallbackDelay;
    event.m_collisionData = collisionData;
    this->m_skipNextNprocessCallbacks = m_contactPointCallbackDelay;
    v11 = (char *)collisionData->m_firstFreeContactPoint.m_storage - (char *)collisionData;
    event.m_internalContactMgr = this;
    LODWORD(v11) = v11 - 16;
    for ( i = (int)v11 / 48 - 1; i >= 0; event.m_contactPointProperties[i--] = 0i64 )
      ;
    hkpWorldCallbackUtil::fireContactProcess(this->m_world, &event);
    if ( v10->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v10, &event);
    if ( v8->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v8, &event);
  }
}

// File Line: 153
// RVA: 0xD85A80
void __fastcall hkpReportContactMgr::confirmToi(
        hkpReportContactMgr *this,
        hkpToiEvent *event,
        float rotateNormal,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *outToBeActivated)
{
  hkpSimpleConstraintContactMgr *m_contactMgr; // rax
  hkpRigidBody *v5; // rcx
  hkpEntity *v7; // rcx
  hkpEntity *v8; // rcx
  hkpContactPointEvent eventa; // [rsp+20h] [rbp-78h] BYREF
  float v10; // [rsp+B0h] [rbp+18h] BYREF

  v10 = rotateNormal;
  m_contactMgr = (hkpSimpleConstraintContactMgr *)event->m_contactMgr;
  v5 = (hkpRigidBody *)event->m_entities[0];
  eventa.m_source = SOURCE_WORLD;
  eventa.m_contactMgr = m_contactMgr;
  eventa.m_bodies[1] = (hkpRigidBody *)event->m_entities[1];
  eventa.m_bodies[0] = v5;
  eventa.m_type = TYPE_TOI;
  eventa.m_contactPoint = &event->m_contactPoint;
  eventa.m_contactPointProperties = &event->m_properties;
  *(_WORD *)&eventa.m_firingCallbacksForFullManifold.m_bool = 0;
  eventa.m_lastCallbackForFullManifold.m_bool = 0;
  eventa.m_accumulators[0] = 0i64;
  eventa.m_accumulators[1] = 0i64;
  eventa.m_separatingVelocity = &event->m_seperatingVelocity;
  eventa.m_rotateNormal = &v10;
  eventa.m_shapeKeyStorage = event->m_extendedUserDatas;
  hkpWorldCallbackUtil::fireContactPointCallback(v5->m_world, &eventa);
  v7 = event->m_entities[0];
  eventa.m_source = SOURCE_A;
  if ( v7->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v7, &eventa);
  v8 = event->m_entities[1];
  eventa.m_source = SOURCE_B;
  if ( v8->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v8, &eventa);
}

// File Line: 175
// RVA: 0xD85B60
void __fastcall hkpReportContactMgr::Factory::Factory(hkpReportContactMgr::Factory *this, hkpWorld *mgr)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpReportContactMgr::Factory::`vftable;
}

// File Line: 180
// RVA: 0xD85B80
void __fastcall hkpReportContactMgr::Factory::createContactMgr(
        hkpReportContactMgr::Factory *this,
        hkpCollidable *a,
        hkpCollidable *b,
        hkpCollisionInput *env)
{
  hkpRigidBody *v5; // rbx
  hkpRigidBody *v6; // rdi
  _QWORD **Value; // rax
  hkpReportContactMgr *v8; // rax

  v5 = (hkpRigidBody *)((char *)a + a->m_ownerOffset);
  v6 = (hkpRigidBody *)((char *)b + b->m_ownerOffset);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpReportContactMgr *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v8 )
    hkpReportContactMgr::hkpReportContactMgr(v8, this->m_world, v5, v6);
}

