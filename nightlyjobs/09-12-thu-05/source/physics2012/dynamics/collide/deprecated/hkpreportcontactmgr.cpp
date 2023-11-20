// File Line: 30
// RVA: 0xD85520
void __fastcall hkpReportContactMgr::hkpReportContactMgr(hkpReportContactMgr *this, hkpWorld *sm, hkpRigidBody *bodyA, hkpRigidBody *bodyB)
{
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // r10

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkpReportContactMgr::`vftable';
  v4 = bodyA->m_contactPointCallbackDelay;
  v5 = bodyB->m_contactPointCallbackDelay;
  this->m_world = sm;
  this->m_bodyA = bodyA;
  if ( v4 < v5 )
    v5 = v4;
  this->m_bodyB = bodyB;
  this->m_skipNextNprocessCallbacks = v5;
}

// File Line: 38
// RVA: 0xD85570
void __fastcall hkpReportContactMgr::~hkpReportContactMgr(hkpReportContactMgr *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 43
// RVA: 0xD85590
signed __int64 __fastcall hkpReportContactMgr::addContactPointImpl(hkpReportContactMgr *this, hkpCdBody *a, hkpCdBody *b, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, hkpGskCache *contactCache, hkContactPoint *pcp)
{
  hkpRigidBody *v7; // rsi
  hkpRigidBody *v8; // rdi
  hkpReportContactMgr *v9; // rbx
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm4
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  signed __int64 result; // rax
  hkpContactPointAddedEvent event; // [rsp+20h] [rbp-68h]
  __int16 v19; // [rsp+78h] [rbp-10h]
  __int16 v20; // [rsp+7Ah] [rbp-Eh]

  v7 = this->m_bodyA;
  v8 = this->m_bodyB;
  v9 = this;
  v10 = _mm_sub_ps(pcp->m_position.m_quad, v8->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v11 = _mm_sub_ps(pcp->m_position.m_quad, v7->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v7->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(v7->m_motion.m_angularVelocity.m_quad, v7->m_motion.m_angularVelocity.m_quad, 201),
            v11));
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 201), v7->m_motion.m_linearVelocity.m_quad);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8->m_motion.m_angularVelocity.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(v8->m_motion.m_angularVelocity.m_quad, v8->m_motion.m_angularVelocity.m_quad, 201),
            v10));
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 201), v8->m_motion.m_linearVelocity.m_quad);
  event.m_bodyA = a;
  event.m_bodyB = b;
  event.m_type.m_storage = 1;
  event.m_contactPoint = pcp;
  event.m_contactPointProperties = 0i64;
  v16 = _mm_mul_ps(_mm_sub_ps(v15, v13), pcp->m_separatingNormal.m_quad);
  event.m_gskCache = contactCache;
  event.m_projectedVelocity = (float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170));
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&this->vfptr;
  event.m_collisionInput = input;
  event.m_collisionOutput = output;
  event.m_status = 0;
  v19 = 0;
  if ( this->m_type )
    v20 = 0;
  else
    v20 = WORD1(this->m_bodyA);
  hkpWorldCallbackUtil::fireContactPointAdded(this->m_world, &event);
  if ( v7->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal((hkpEntity *)&v7->vfptr, &event);
  if ( v8->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal((hkpEntity *)&v8->vfptr, &event);
  if ( event.m_status == 1 )
  {
    ((void (__fastcall *)(hkpReportContactMgr *, _QWORD, hkpConstraintOwner *))v9->vfptr[2].__first_virtual_table_function__)(
      v9,
      0i64,
      output->m_constraintOwner.m_storage);
    result = 0xFFFFi64;
  }
  else
  {
    result = 0i64;
    v9->m_skipNextNprocessCallbacks = v20;
  }
  return result;
}

// File Line: 80
// RVA: 0xD858C0
__int64 __fastcall hkpReportContactMgr::addToiImpl(hkpReportContactMgr *this, hkpCdBody *a, hkpCdBody *b, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *output, float toi, hkContactPoint *cp, hkpGskCache *gskCache, float *projectedVelocity, hkpContactPointProperties *properties)
{
  hkpReportContactMgr *v10; // rbx
  hkpRigidBody *v11; // rdi
  float v12; // xmm0_4
  hkpRigidBody *v13; // r14
  __int64 result; // rax
  hkpContactPointAddedEvent event; // [rsp+20h] [rbp-78h]
  float v16; // [rsp+78h] [rbp-20h]

  v10 = this;
  event.m_bodyA = a;
  event.m_bodyB = b;
  *(_DWORD *)&properties->m_friction.m_value = 0x1000000;
  v11 = this->m_bodyB;
  v12 = *projectedVelocity;
  v13 = this->m_bodyA;
  event.m_type.m_storage = 0;
  event.m_contactPoint = cp;
  event.m_gskCache = gskCache;
  event.m_contactPointProperties = properties;
  event.m_projectedVelocity = v12;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&this->vfptr;
  event.m_collisionInput = input;
  event.m_collisionOutput = output;
  event.m_status = 0;
  v16 = toi;
  hkpWorldCallbackUtil::fireContactPointAdded(this->m_world, &event);
  if ( v13->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal((hkpEntity *)&v13->vfptr, &event);
  if ( v11->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointAddedInternal((hkpEntity *)&v11->vfptr, &event);
  result = (unsigned int)event.m_status;
  if ( event.m_status == 1 )
  {
    ((void (__fastcall *)(hkpReportContactMgr *, hkpConstraintOwner *, hkpContactPointProperties *))v10->vfptr[4].__vecDelDtor)(
      v10,
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

// File Line: 98
// RVA: 0xD859F0
void __fastcall hkpReportContactMgr::removeToiImpl(hkpReportContactMgr *this, hkpConstraintOwner *constraintOwner, hkpContactPointProperties *properties)
{
  hkpRigidBody *v3; // rdi
  hkpRigidBody *v4; // rbx
  hkpWorld *v5; // rax
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-48h]

  v3 = this->m_bodyA;
  v4 = this->m_bodyB;
  v5 = v3->m_world;
  event.m_constraintOwner = constraintOwner;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&this->vfptr;
  event.m_contactPointId = -1;
  event.m_contactPointProperties = properties;
  event.m_entityA = (hkpEntity *)&v3->vfptr;
  event.m_entityB = (hkpEntity *)&v4->vfptr;
  hkpWorldCallbackUtil::fireContactPointRemoved(v5, &event);
  if ( v3->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal((hkpEntity *)&v3->vfptr, &event);
  if ( v4->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal((hkpEntity *)&v4->vfptr, &event);
}

// File Line: 109
// RVA: 0xD85730
void __fastcall hkpReportContactMgr::removeContactPointImpl(hkpReportContactMgr *this, unsigned __int16 cpId, hkpConstraintOwner *info)
{
  hkpRigidBody *v3; // rdi
  hkpRigidBody *v4; // rbx
  hkpWorld *v5; // rcx
  hkpContactPointRemovedEvent event; // [rsp+20h] [rbp-48h]

  v3 = this->m_bodyA;
  v4 = this->m_bodyB;
  event.m_internalContactMgr = (hkpDynamicsContactMgr *)&this->vfptr;
  v5 = this->m_world;
  event.m_contactPointId = cpId;
  event.m_entityA = (hkpEntity *)&v3->vfptr;
  event.m_entityB = (hkpEntity *)&v4->vfptr;
  event.m_contactPointProperties = 0i64;
  event.m_constraintOwner = info;
  hkpWorldCallbackUtil::fireContactPointRemoved(v5, &event);
  if ( v3->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal((hkpEntity *)&v3->vfptr, &event);
  if ( v4->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointRemovedInternal((hkpEntity *)&v4->vfptr, &event);
}

// File Line: 118
// RVA: 0xD857B0
void __fastcall hkpReportContactMgr::processContactImpl(hkpReportContactMgr *this, hkpCollidable *a, hkpCollidable *b, hkpProcessCollisionInput *input, hkpProcessCollisionData *collisionData)
{
  __int16 v5; // r9
  hkpReportContactMgr *v6; // r10
  __int64 v7; // rdi
  hkpEntity *v8; // rbx
  unsigned __int16 v9; // cx
  hkpEntity *v10; // rdi
  signed __int64 v11; // rcx
  __int64 v12; // rax
  hkpContactProcessEvent event; // [rsp+20h] [rbp-838h]

  v5 = this->m_skipNextNprocessCallbacks;
  v6 = this;
  this->m_skipNextNprocessCallbacks = v5 - 1;
  if ( !v5 )
  {
    v7 = a->m_ownerOffset;
    v8 = (hkpEntity *)((char *)b + b->m_ownerOffset);
    event.m_collidableA = a;
    v9 = v8->m_contactPointCallbackDelay;
    v10 = (hkpEntity *)((char *)a + v7);
    event.m_collidableB = b;
    if ( v10->m_contactPointCallbackDelay < v9 )
      v9 = v10->m_contactPointCallbackDelay;
    event.m_collisionData = collisionData;
    v6->m_skipNextNprocessCallbacks = v9;
    v11 = (char *)collisionData->m_firstFreeContactPoint.m_storage - (char *)collisionData;
    event.m_internalContactMgr = (hkpDynamicsContactMgr *)&v6->vfptr;
    v12 = (signed int)(((signed __int64)((unsigned __int128)((v11 - 16) * (signed __int128)3074457345618258603i64) >> 64) >> 3)
                     + ((unsigned __int64)((unsigned __int128)((v11 - 16) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                     - 1);
    if ( (signed int)v12 >= 0 )
    {
      do
        event.m_contactPointProperties[v12--] = 0i64;
      while ( v12 >= 0 );
    }
    hkpWorldCallbackUtil::fireContactProcess(v6->m_world, &event);
    if ( v10->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v10, &event);
    if ( v8->m_contactListeners.m_size )
      hkpEntityCallbackUtil::fireContactProcessInternal(v8, &event);
  }
}

// File Line: 153
// RVA: 0xD85A80
void __fastcall hkpReportContactMgr::confirmToi(hkpReportContactMgr *this, hkpToiEvent *event, float rotateNormal, hkArray<hkpEntity *,hkContainerHeapAllocator> *outToBeActivated)
{
  hkpSimpleConstraintContactMgr *v4; // rax
  hkpRigidBody *v5; // rcx
  hkpToiEvent *v6; // rbx
  hkpEntity *v7; // rcx
  hkpEntity *v8; // rcx
  hkpContactPointEvent eventa; // [rsp+20h] [rbp-78h]
  float v10; // [rsp+B0h] [rbp+18h]

  v10 = rotateNormal;
  v4 = (hkpSimpleConstraintContactMgr *)event->m_contactMgr;
  v5 = (hkpRigidBody *)event->m_entities[0];
  eventa.m_source = 2;
  eventa.m_contactMgr = v4;
  eventa.m_bodies[1] = (hkpRigidBody *)event->m_entities[1];
  eventa.m_bodies[0] = v5;
  eventa.m_type = 0;
  v6 = event;
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
  v7 = v6->m_entities[0];
  eventa.m_source = 0;
  if ( v7->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v7, &eventa);
  v8 = v6->m_entities[1];
  eventa.m_source = 1;
  if ( v8->m_contactListeners.m_size )
    hkpEntityCallbackUtil::fireContactPointCallbackInternal(v8, &eventa);
}

// File Line: 175
// RVA: 0xD85B60
void __fastcall hkpReportContactMgr::Factory::Factory(hkpReportContactMgr::Factory *this, hkpWorld *mgr)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = mgr;
  this->vfptr = (hkBaseObjectVtbl *)&hkpReportContactMgr::Factory::`vftable';
}

// File Line: 180
// RVA: 0xD85B80
void __fastcall hkpReportContactMgr::Factory::createContactMgr(hkpReportContactMgr::Factory *this, hkpCollidable *a, hkpCollidable *b, hkpCollisionInput *env)
{
  hkpReportContactMgr::Factory *v4; // rsi
  hkpRigidBody *v5; // rbx
  hkpRigidBody *v6; // rdi
  _QWORD **v7; // rax
  hkpReportContactMgr *v8; // rax

  v4 = this;
  v5 = (hkpRigidBody *)((char *)a + a->m_ownerOffset);
  v6 = (hkpRigidBody *)((char *)b + b->m_ownerOffset);
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpReportContactMgr *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 56i64);
  if ( v8 )
    hkpReportContactMgr::hkpReportContactMgr(v8, v4->m_world, v5, v6);
}

