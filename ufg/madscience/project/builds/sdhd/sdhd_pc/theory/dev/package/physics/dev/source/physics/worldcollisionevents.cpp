// File Line: 24
// RVA: 0x1458EB0
__int64 UFG::_dynamic_initializer_for__gCollisionEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gCollisionEventChannel,
    "CollisionEvent",
    "This is an event that gets generated when collisions happen.");
  return atexit(UFG::_dynamic_atexit_destructor_for__gCollisionEventChannel__);
}

// File Line: 25
// RVA: 0x1458E80
__int64 UFG::_dynamic_initializer_for__gBulletCollisionEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gBulletCollisionEventChannel,
    "BulletCollisionEvent",
    "This is an event that gets generated when bullets hit things");
  return atexit(UFG::_dynamic_atexit_destructor_for__gBulletCollisionEventChannel__);
}

// File Line: 34
// RVA: 0xAC8E0
void UFG::CollisionEvent::Initialize(void)
{
  char *v0; // rax
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v1; // rbx

  v0 = UFG::qMalloc(0x60ui64, "ThreadSafeQueue<CollisionEvent>", 0i64);
  v1 = (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)v0;
  if ( v0 )
  {
    UFG::qMutex::qMutex((UFG::qMutex *)v0 + 1, &customWorldMapCaption);
    v1->head.next = &v1->tail;
    v1->head.prev = 0i64;
    v1->tail.prev = &v1->head;
    v1->tail.next = 0i64;
    UFG::CollisionEvent::mQueue = v1;
  }
  else
  {
    UFG::CollisionEvent::mQueue = 0i64;
  }
}

// File Line: 50
// RVA: 0x97550
void __fastcall UFG::CollisionEvent::CollisionEvent(UFG::CollisionEvent *this)
{
  UFG::CollisionEvent *v1; // rbx
  unsigned int v2; // edx
  UFG::qNode<UFG::Event,UFG::Event> *v3; // rax

  v1 = this;
  v2 = UFG::gCollisionEventChannel.mUID;
  v3 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_EventUID = v2;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable';
  `eh vector constructor iterator'(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v1->havokUserData[0] = 0i64;
  v1->havokUserData[1] = 0i64;
  UFG::ThreadSafeQueue<hkpEntity>::AddHead(UFG::CollisionEvent::mQueue, v1);
}

// File Line: 60
// RVA: 0x96FC0
void __fastcall UFG::BulletCollisionEvent::BulletCollisionEvent(UFG::BulletCollisionEvent *this)
{
  UFG::BulletCollisionEvent *v1; // rbx

  v1 = this;
  UFG::CollisionEvent::CollisionEvent((UFG::CollisionEvent *)&this->vfptr);
  v1->vfptr = (UFG::EventVtbl *)&UFG::BulletCollisionEvent::`vftable';
  v1->m_EventUID = UFG::gBulletCollisionEventChannel.mUID;
}

// File Line: 82
// RVA: 0x97300
void __fastcall UFG::CollisionEvent::CollisionEvent(UFG::CollisionEvent *this, UFG::CollisionEvent::ContactType type, hkpRigidBody *rbA, hkpRigidBody *rbB, hkVector4f *_position, hkVector4f *_normal, float _speed, unsigned __int64 objectPropertiesHandleUIDA, unsigned __int64 objectPropertiesHandleUIDB, unsigned __int64 surfacePropertiesHandleUIDA, unsigned __int64 surfacePropertiesHandleUIDB)
{
  hkpRigidBody *v11; // rdi
  hkpRigidBody *v12; // rsi
  UFG::CollisionEvent *v13; // rbx
  unsigned int v14; // er10
  UFG::qNode<UFG::Event,UFG::Event> *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4

  v11 = rbB;
  v12 = rbA;
  v13 = this;
  v14 = UFG::gCollisionEventChannel.mUID;
  v15 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v15->mPrev = v15;
  v15->mNext = v15;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_EventUID = v14;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable';
  this->mType = type;
  `eh vector constructor iterator'(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v16 = _position->m_quad.m128_f32[1];
  v17 = _position->m_quad.m128_f32[2];
  LODWORD(v13->position.x) = _position->m_quad.m128_i32[0];
  v13->position.y = v16;
  v13->position.z = v17;
  v18 = _normal->m_quad.m128_f32[1];
  v19 = _normal->m_quad.m128_f32[2];
  LODWORD(v13->normal.x) = _normal->m_quad.m128_i32[0];
  v13->normal.y = v18;
  v13->normal.z = v19;
  v13->speed = _speed;
  v20 = UFG::EstimateImpulseMagnitude(v12, v11, _position, _normal, _speed, 0.5);
  v21 = logf(v20);
  v13->estimatedImpulseMagnitude = v21;
  if ( v21 < 0.0 )
    v13->estimatedImpulseMagnitude = 0.0;
  v22 = v12->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
  v23 = v12->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
  v13->preCollisionPosition[0].x = v12->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0];
  v13->preCollisionPosition[0].y = v22;
  v13->preCollisionPosition[0].z = v23;
  v24 = v11->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
  v25 = v11->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
  v13->preCollisionPosition[1].x = v11->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0];
  v13->preCollisionPosition[1].y = v24;
  v13->preCollisionPosition[1].z = v25;
  v26 = v12->m_motion.m_linearVelocity.m_quad.m128_f32[1];
  v27 = v12->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  v13->velocity[0].x = v12->m_motion.m_linearVelocity.m_quad.m128_f32[0];
  v13->velocity[0].y = v26;
  v13->velocity[0].z = v27;
  v28 = v11->m_motion.m_linearVelocity.m_quad.m128_f32[1];
  v29 = v11->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  v13->velocity[1].x = v11->m_motion.m_linearVelocity.m_quad.m128_f32[0];
  v13->velocity[1].y = v28;
  v13->velocity[1].z = v29;
  v13->havokUserData[0] = (UFG::HavokUserData *)v12->m_userData;
  v13->havokUserData[1] = (UFG::HavokUserData *)v11->m_userData;
  v13->objectPropertyHandleUID[0] = objectPropertiesHandleUIDA;
  v13->objectPropertyHandleUID[1] = objectPropertiesHandleUIDB;
  v13->surfacePropertyHandleUID[0] = surfacePropertiesHandleUIDA;
  v13->surfacePropertyHandleUID[1] = surfacePropertiesHandleUIDB;
  UFG::ThreadSafeQueue<hkpEntity>::AddHead(UFG::CollisionEvent::mQueue, v13);
}

// File Line: 121
// RVA: 0xA8720
void __fastcall UFG::CollisionEvent::FixupSimObjectPtrs(UFG::CollisionEvent *this)
{
  UFG::HavokUserData *v1; // rax
  UFG::SimObject *v2; // r8
  UFG::CollisionEvent *v3; // r9
  UFG::SimComponent *v4; // r10
  UFG::SimObject *v5; // r10
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::HavokUserData *v10; // rax
  UFG::SimComponent *v11; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = this->havokUserData[0];
  v2 = 0i64;
  v3 = this;
  if ( v1 )
  {
    v4 = v1->simComponent.m_pPointer;
    if ( v4 )
      v5 = v4->m_pSimObject;
    else
      v5 = 0i64;
    v6 = this->mSimObject;
    if ( this->mSimObject[0].m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v6->m_pPointer = v5;
    if ( v5 )
    {
      v9 = v5->m_SafePointerList.mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v9;
      v6->mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
  }
  v10 = v3->havokUserData[1];
  if ( v10 )
  {
    v11 = v10->simComponent.m_pPointer;
    if ( v11 )
      v2 = v11->m_pSimObject;
    v12 = &v3->mSimObject[1];
    if ( v3->mSimObject[1].m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v3->mSimObject[1].mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v3->mSimObject[1].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mSimObject[1].mPrev;
    }
    v3->mSimObject[1].m_pPointer = v2;
    if ( v2 )
    {
      v15 = v2->m_SafePointerList.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v12->mPrev = v15;
      v3->mSimObject[1].mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    }
  }
}

// File Line: 136
// RVA: 0xAE280
void UFG::CollisionEvent::PostEvents(void)
{
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v0; // rbx
  _RTL_CRITICAL_SECTION *v1; // rdi
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v2; // rdi
  _RTL_CRITICAL_SECTION *v3; // rbp
  UFG::CollisionEvent *v4; // rsi
  UFG::QueueNode<UFG::CollisionEvent> *v5; // rbx
  UFG::QueueNode<UFG::CollisionEvent> *v6; // rcx
  UFG::QueueNode<UFG::CollisionEvent> *v7; // rax
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v8; // rbx
  _RTL_CRITICAL_SECTION *v9; // rdi

  v0 = UFG::CollisionEvent::mQueue;
  v1 = (_RTL_CRITICAL_SECTION *)&UFG::CollisionEvent::mQueue->mutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::CollisionEvent::mQueue->mutex);
  LOBYTE(v0) = v0->head.next == &v0->tail;
  UFG::qMutex::Unlock(v1);
  if ( !(_BYTE)v0 )
  {
    do
    {
      v2 = UFG::CollisionEvent::mQueue;
      v3 = (_RTL_CRITICAL_SECTION *)&UFG::CollisionEvent::mQueue->mutex;
      v4 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::CollisionEvent::mQueue->mutex);
      UFG::qMutex::Lock(v3);
      v5 = &v2->tail;
      LOBYTE(v2) = v2->head.next == &v2->tail;
      UFG::qMutex::Unlock(v3);
      if ( !(_BYTE)v2 )
      {
        v6 = v5->prev;
        v7 = v5->prev->prev;
        v7->next = v5;
        v5->prev = v7;
        v4 = v6->data;
        operator delete[](v6);
      }
      UFG::qMutex::Unlock(v3);
      UFG::CollisionEvent::FixupSimObjectPtrs(v4);
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)&v4->vfptr);
      v8 = UFG::CollisionEvent::mQueue;
      v9 = (_RTL_CRITICAL_SECTION *)&UFG::CollisionEvent::mQueue->mutex;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::CollisionEvent::mQueue->mutex);
      LOBYTE(v8) = v8->head.next == &v8->tail;
      UFG::qMutex::Unlock(v9);
    }
    while ( !(_BYTE)v8 );
  }
}

// File Line: 148
// RVA: 0xACAD0
void __fastcall UFG::WorldCollisionListener::Initialize(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  char *v2; // rax

  v1 = world;
  v2 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x10ui64, "WorldCollisionListener", 0i64, 1u);
  if ( v2 )
  {
    *(_QWORD *)v2 = &hkpContactListener::`vftable';
    *(_QWORD *)v2 = &UFG::WorldCollisionListener::`vftable';
    *((_QWORD *)v2 + 1) = 0i64;
  }
  UFG::WorldCollisionListener::mInstance = (UFG::WorldCollisionListener *)v2;
  hkpWorld::addContactListener(v1, (hkpContactListener *)v2);
}

// File Line: 181
// RVA: 0xA10E0
void __fastcall UFG::WorldCollisionListener::BeginFrame(UFG::WorldCollisionListener *this)
{
  *(_QWORD *)&this->mCollisionEventsThisFrame = 0i64;
}

// File Line: 189
// RVA: 0xA7DF0
void __fastcall UFG::WorldCollisionListener::EndFrame(UFG::WorldCollisionListener *this, hkpWorld *world)
{
  UFG::CollisionEvent::PostEvents();
}

// File Line: 198
// RVA: 0xB7160
void __fastcall UFG::WorldCollisionListener::contactPointAddedCallback(UFG::WorldCollisionListener *this, hkpContactPointAddedEvent *evt)
{
  hkpCdBody *v2; // r9
  UFG::WorldCollisionListener *v3; // r10
  hkpCdBody *v4; // rax
  hkpCollidable *i; // r8
  hkpCdBody *v6; // r8
  hkpCollidable *v7; // rax
  hkpCollidable *j; // rcx
  unsigned int v9; // eax
  hkContactPoint *v10; // rax
  hkVector4f v11; // xmm1
  UFG::WorldCollisionListener::ContactPointAddedEvent evta; // [rsp+20h] [rbp-48h]

  v2 = evt->m_bodyA;
  v3 = this;
  v4 = evt->m_bodyA->m_parent;
  for ( i = (hkpCollidable *)evt->m_bodyA; v4; v4 = v4->m_parent )
    i = (hkpCollidable *)v4;
  evta.collA = i;
  v6 = evt->m_bodyB;
  v7 = (hkpCollidable *)v6->m_parent;
  for ( j = (hkpCollidable *)evt->m_bodyB; v7; v7 = (hkpCollidable *)v7->m_parent )
    j = v7;
  v9 = v2->m_shapeKey;
  evta.collB = j;
  evta.shapeKeyA = v9;
  evta.shapeKeyB = v6->m_shapeKey;
  v10 = evt->m_contactPoint;
  v11.m_quad = (__m128)v10->m_separatingNormal;
  evta.position = v10->m_position;
  evta.normal = (hkVector4f)v11.m_quad;
  evta.projectedVel = evt->m_projectedVelocity;
  UFG::WorldCollisionListener::ContactPointAddedCallback(v3, &evta);
}

// File Line: 214
// RVA: 0xB7200
void __fastcall UFG::WorldCollisionListener::contactProcessCallback(UFG::WorldCollisionListener *this, hkpContactProcessEvent *evt)
{
  hkpProcessCollisionData *v2; // rbx
  hkpContactProcessEvent *v3; // rsi
  signed int v4; // edi
  UFG::WorldCollisionListener *i; // rbp
  UFG::WorldCollisionListener::ContactProcessEvent evta; // [rsp+20h] [rbp-28h]

  v2 = evt->m_collisionData;
  v3 = evt;
  v4 = 0;
  for ( i = this;
        v4 < (signed int)(((unsigned __int64)((unsigned __int128)((_QWORD)((char *)v2->m_firstFreeContactPoint.m_storage
                                                                         - (char *)v2
                                                                         - 16)
                                                                * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                        + ((signed __int64)((unsigned __int128)((_QWORD)((char *)v2->m_firstFreeContactPoint.m_storage
                                                                       - (char *)v2
                                                                       - 16)
                                                              * (signed __int128)3074457345618258603i64) >> 64) >> 3));
        ++v4 )
  {
    evta.collA = v3->m_collidableA;
    evta.collB = v3->m_collidableB;
    evta.cp = &v2->m_contactPoints[v4].m_contact;
    UFG::WorldCollisionListener::ContactProcessCallback(i, &evta);
  }
}

// File Line: 230
// RVA: 0xA3FE0
void __fastcall UFG::WorldCollisionListener::ContactPointAddedCallback(UFG::WorldCollisionListener *this, UFG::WorldCollisionListener::ContactPointAddedEvent *evt)
{
  UFG::WorldCollisionListener::ContactPointAddedEvent *_position; // r13
  UFG::WorldCollisionListener *v3; // r12
  hkpCollidable *v4; // r8
  hkpShape *v5; // rdx
  hkpCollidable *v6; // rax
  hkpShape *v7; // rdi
  unsigned __int64 surfacePropertiesHandleUIDB; // rbx
  hkpRigidBody *v9; // r15
  hkpRigidBody *v10; // rbp
  signed int v11; // er9
  __int64 v12; // rsi
  unsigned __int64 v13; // rdx
  char v14; // cl
  signed int v15; // er8
  signed __int64 v16; // rcx
  signed int v17; // er9
  __int64 v18; // r10
  unsigned __int64 v19; // rdx
  char v20; // r8
  __int64 v21; // rax
  signed __int64 v22; // rcx
  unsigned __int64 objectPropertiesHandleUIDA; // r14
  int v24; // eax
  int v25; // er8
  hkSimpleProperty *v26; // rcx
  unsigned __int64 objectPropertiesHandleUIDB; // rdi
  int v28; // eax
  int v29; // er8
  hkSimpleProperty *v30; // rcx
  unsigned __int64 surfacePropertiesHandleUIDA; // rsi
  unsigned int v32; // ecx
  char *v33; // rax

  _position = evt;
  v3 = this;
  v4 = evt->collA;
  v5 = v4->m_shape;
  v6 = _position->collB;
  v7 = v6->m_shape;
  surfacePropertiesHandleUIDB = 0i64;
  if ( v4->m_broadPhaseHandle.m_type == 1 )
    v9 = (hkpRigidBody *)((char *)v4 + v4->m_ownerOffset);
  else
    v9 = 0i64;
  if ( v6->m_broadPhaseHandle.m_type == 1 )
    v10 = (hkpRigidBody *)((char *)v6 + v6->m_ownerOffset);
  else
    v10 = 0i64;
  v11 = _position->shapeKeyA;
  v12 = 0i64;
  if ( v11 != -1 && v5->m_type.m_storage == 9 )
  {
    v13 = v5[2].m_userData;
    if ( v13 )
    {
      v14 = *(_BYTE *)(v13 + 41);
      if ( v14 == 1 || v14 == 3 )
      {
        v15 = (v11 & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(v13 + 232));
        if ( v11 < 0 )
          v16 = *(_QWORD *)(v13 + 256) + 80i64 * v15;
        else
          v16 = *(_QWORD *)(v13 + 240) + 144i64 * v15;
        v12 = *(_QWORD *)(v16 + 16);
      }
    }
  }
  v17 = _position->shapeKeyB;
  v18 = 0i64;
  if ( v17 != -1 && v7->m_type.m_storage == 9 )
  {
    v19 = v7[2].m_userData;
    if ( v19 )
    {
      v20 = *(_BYTE *)(v19 + 41);
      if ( v20 == 1 || v20 == 3 )
      {
        v21 = (signed int)((v17 & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(v19 + 232)));
        if ( v17 < 0 )
          v22 = *(_QWORD *)(v19 + 256) + 80 * v21;
        else
          v22 = *(_QWORD *)(v19 + 240) + 144 * v21;
        v18 = *(_QWORD *)(v22 + 16);
      }
    }
  }
  if ( v12 )
  {
    objectPropertiesHandleUIDA = *(_QWORD *)(v12 + 16);
  }
  else
  {
    v24 = 0;
    v25 = v9->m_properties.m_size;
    if ( v25 <= 0 )
    {
LABEL_33:
      objectPropertiesHandleUIDA = 0i64;
    }
    else
    {
      v26 = v9->m_properties.m_data;
      while ( v26->m_key != UFG::physicsObjectPropertyTypeUid )
      {
        ++v24;
        ++v26;
        if ( v24 >= v25 )
          goto LABEL_33;
      }
      objectPropertiesHandleUIDA = v9->m_properties.m_data[v24].m_value.m_data;
    }
  }
  if ( v18 )
  {
    objectPropertiesHandleUIDB = *(_QWORD *)(v18 + 16);
  }
  else
  {
    v28 = 0;
    v29 = v10->m_properties.m_size;
    if ( v29 <= 0 )
    {
LABEL_42:
      objectPropertiesHandleUIDB = 0i64;
    }
    else
    {
      v30 = v10->m_properties.m_data;
      while ( v30->m_key != UFG::physicsObjectPropertyTypeUid )
      {
        ++v28;
        ++v30;
        if ( v28 >= v29 )
          goto LABEL_42;
      }
      objectPropertiesHandleUIDB = v10->m_properties.m_data[v28].m_value.m_data;
    }
  }
  if ( v12 )
    surfacePropertiesHandleUIDA = *(_QWORD *)(v12 + 8);
  else
    surfacePropertiesHandleUIDA = 0i64;
  if ( v18 )
    surfacePropertiesHandleUIDB = *(_QWORD *)(v18 + 8);
  if ( v9 )
  {
    if ( v10 )
    {
      if ( COERCE_FLOAT(LODWORD(_position->projectedVel) & _xmm) >= 2.25 )
      {
        v32 = v3->mCollisionEventsThisFrame;
        v3->mCollisionEventsThisFrame = v32 + 1;
        if ( v32 < 0x10 )
        {
          v33 = UFG::qMalloc(0xF0ui64, "CollisionEvent", 0i64);
          if ( v33 )
            UFG::CollisionEvent::CollisionEvent(
              (UFG::CollisionEvent *)v33,
              0,
              v9,
              v10,
              &_position->position,
              &_position->normal,
              _position->projectedVel,
              objectPropertiesHandleUIDA,
              objectPropertiesHandleUIDB,
              surfacePropertiesHandleUIDA,
              surfacePropertiesHandleUIDB);
        }
      }
    }
  }
}

// File Line: 275
// RVA: 0xA42A0
void __fastcall UFG::WorldCollisionListener::ContactProcessCallback(UFG::WorldCollisionListener *this, UFG::WorldCollisionListener::ContactProcessEvent *evt)
{
  UFG::WorldCollisionListener *v2; // r9
  hkpRigidBody *v3; // rsi
  hkpCollidable *v4; // rax
  hkpRigidBody *v5; // rbp
  int v6; // eax
  int v7; // er8
  hkSimpleProperty *v8; // rcx
  unsigned __int64 objectPropertiesHandleUIDA; // rdi
  int v10; // eax
  int v11; // er8
  hkSimpleProperty *v12; // rcx
  unsigned __int64 objectPropertiesHandleUIDB; // rbx
  hkContactPoint *_position; // r14
  __m128 v15; // xmm8
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm3
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  float _speed; // xmm6_4
  unsigned int v28; // ecx
  char *v29; // rax
  __m128 v30; // xmm5
  __m128 v31; // xmm5
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm6
  __m128 v37; // xmm6
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  unsigned int v40; // ecx
  char *v41; // rax
  __m128 v42; // xmm6
  __m128 v43; // xmm1
  hkVector4f _normal; // [rsp+70h] [rbp-78h]

  v2 = this;
  if ( evt->collA->m_broadPhaseHandle.m_type == 1 )
    v3 = (hkpRigidBody *)((char *)evt->collA + evt->collA->m_ownerOffset);
  else
    v3 = 0i64;
  v4 = evt->collB;
  if ( v4->m_broadPhaseHandle.m_type == 1 )
    v5 = (hkpRigidBody *)((char *)v4 + v4->m_ownerOffset);
  else
    v5 = 0i64;
  v6 = 0;
  v7 = v3->m_properties.m_size;
  if ( v7 <= 0 )
  {
LABEL_13:
    objectPropertiesHandleUIDA = 0i64;
  }
  else
  {
    v8 = v3->m_properties.m_data;
    while ( v8->m_key != UFG::physicsObjectPropertyTypeUid )
    {
      ++v6;
      ++v8;
      if ( v6 >= v7 )
        goto LABEL_13;
    }
    objectPropertiesHandleUIDA = v3->m_properties.m_data[v6].m_value.m_data;
  }
  v10 = 0;
  v11 = v5->m_properties.m_size;
  if ( v11 <= 0 )
  {
LABEL_20:
    objectPropertiesHandleUIDB = 0i64;
  }
  else
  {
    v12 = v5->m_properties.m_data;
    while ( v12->m_key != UFG::physicsObjectPropertyTypeUid )
    {
      ++v10;
      ++v12;
      if ( v10 >= v11 )
        goto LABEL_20;
    }
    objectPropertiesHandleUIDB = v5->m_properties.m_data[v10].m_value.m_data;
  }
  _position = evt->cp;
  v15 = _position->m_separatingNormal.m_quad;
  _normal.m_quad = v15;
  v16 = _mm_sub_ps(_position->m_position.m_quad, v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v17 = _mm_sub_ps(
          _mm_mul_ps(v3->m_motion.m_angularVelocity.m_quad, _mm_shuffle_ps(v16, v16, 201)),
          _mm_mul_ps(
            v16,
            _mm_shuffle_ps(v3->m_motion.m_angularVelocity.m_quad, v3->m_motion.m_angularVelocity.m_quad, 201)));
  v18 = _mm_sub_ps(_position->m_position.m_quad, v5->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
  v19 = _mm_sub_ps(
          _mm_mul_ps(v5->m_motion.m_angularVelocity.m_quad, _mm_shuffle_ps(v18, v18, 201)),
          _mm_mul_ps(
            v18,
            _mm_shuffle_ps(v5->m_motion.m_angularVelocity.m_quad, v5->m_motion.m_angularVelocity.m_quad, 201)));
  v20 = _mm_sub_ps(
          _mm_add_ps(_mm_shuffle_ps(v19, v19, 201), v5->m_motion.m_linearVelocity.m_quad),
          _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v3->m_motion.m_linearVelocity.m_quad));
  v21 = _mm_mul_ps(v20, v15);
  v22 = _mm_shuffle_ps(v21, v21, 0);
  v22.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))
                  + (float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + v22.m128_f32[0]);
  v23 = _mm_sub_ps(v20, _mm_mul_ps(v15, _mm_shuffle_ps(v22, v22, 0)));
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 170), _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)));
  v26 = _mm_rsqrt_ps(v25);
  LODWORD(_speed) = (unsigned __int128)_mm_andnot_ps(
                                         _mm_cmpleps(v25, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                                             _mm_mul_ps(v26, *(__m128 *)_xmm)),
                                           v25));
  if ( COERCE_FLOAT((unsigned int)(2 * v22.m128_i32[0]) >> 1) >= 0.0099999998 || _speed <= 0.5 )
  {
    v30 = _mm_mul_ps(v20, v20);
    v31 = _mm_add_ps(
            _mm_shuffle_ps(v30, v30, 170),
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)));
    v32 = _mm_rsqrt_ps(v31);
    if ( COERCE_FLOAT(
           _mm_andnot_ps(
             _mm_cmpleps(v31, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                 _mm_mul_ps(v32, *(__m128 *)_xmm)),
               v31))) < 0.1 )
    {
      v33 = _mm_sub_ps(v5->m_motion.m_linearVelocity.m_quad, v3->m_motion.m_linearVelocity.m_quad);
      v34 = _mm_mul_ps(v33, v15);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 0), _mm_shuffle_ps(v34, v34, 85)),
              _mm_shuffle_ps(v34, v34, 170));
      v36 = _mm_sub_ps(v33, _mm_mul_ps(v15, _mm_shuffle_ps(v35, v35, 0)));
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_add_ps(
              _mm_shuffle_ps(v37, v37, 170),
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
      v39 = _mm_rsqrt_ps(v38);
      if ( COERCE_FLOAT(
             _mm_andnot_ps(
               _mm_cmpleps(v38, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                   _mm_mul_ps(v39, *(__m128 *)_xmm)),
                 v38))) > 0.5 )
      {
        v40 = v2->mContinuousEventsThisFrame;
        v2->mContinuousEventsThisFrame = v40 + 1;
        if ( v40 < 4 )
        {
          v41 = UFG::qMalloc(0xF0ui64, "CollisionEvent", 0i64);
          if ( v41 )
          {
            v42 = _mm_add_ps(
                    _mm_shuffle_ps(v37, v37, 170),
                    _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
            v43 = _mm_rsqrt_ps(v42);
            UFG::CollisionEvent::CollisionEvent(
              (UFG::CollisionEvent *)v41,
              SUPPORTED,
              v3,
              v5,
              &_position->m_position,
              &_normal,
              COERCE_FLOAT(
                _mm_andnot_ps(
                  _mm_cmpleps(v42, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                      _mm_mul_ps(v43, *(__m128 *)_xmm)),
                    v42))),
              objectPropertiesHandleUIDA,
              objectPropertiesHandleUIDB,
              0i64,
              0i64);
          }
        }
      }
    }
  }
  else
  {
    v28 = v2->mContinuousEventsThisFrame;
    v2->mContinuousEventsThisFrame = v28 + 1;
    if ( v28 < 4 )
    {
      v29 = UFG::qMalloc(0xF0ui64, "CollisionEvent", 0i64);
      if ( v29 )
        UFG::CollisionEvent::CollisionEvent(
          (UFG::CollisionEvent *)v29,
          SLIDING,
          v3,
          v5,
          &_position->m_position,
          &_normal,
          _speed,
          objectPropertiesHandleUIDA,
          objectPropertiesHandleUIDB,
          0i64,
          0i64);
    }
  }
}

