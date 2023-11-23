// File Line: 24
// RVA: 0x1458EB0
__int64 UFG::_dynamic_initializer_for__gCollisionEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gCollisionEventChannel,
    "CollisionEvent",
    "This is an event that gets generated when collisions happen.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gCollisionEventChannel__);
}

// File Line: 25
// RVA: 0x1458E80
__int64 UFG::_dynamic_initializer_for__gBulletCollisionEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gBulletCollisionEventChannel,
    "BulletCollisionEvent",
    "This is an event that gets generated when bullets hit things");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gBulletCollisionEventChannel__);
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
    UFG::qMutex::qMutex((UFG::qMutex *)v0 + 1, &customCaption);
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
  unsigned int mUID; // edx

  mUID = UFG::gCollisionEventChannel.mUID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = mUID;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable;
  `eh vector constructor iterator(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  this->havokUserData[0] = 0i64;
  this->havokUserData[1] = 0i64;
  UFG::ThreadSafeQueue<hkpEntity>::AddHead(UFG::CollisionEvent::mQueue, this);
}

// File Line: 60
// RVA: 0x96FC0
void __fastcall UFG::BulletCollisionEvent::BulletCollisionEvent(UFG::BulletCollisionEvent *this)
{
  UFG::CollisionEvent::CollisionEvent(this);
  this->vfptr = (UFG::EventVtbl *)&UFG::BulletCollisionEvent::`vftable;
  this->m_EventUID = UFG::gBulletCollisionEventChannel.mUID;
}

// File Line: 82
// RVA: 0x97300
void __fastcall UFG::CollisionEvent::CollisionEvent(
        UFG::CollisionEvent *this,
        UFG::CollisionEvent::ContactType type,
        hkpRigidBody *rbA,
        hkpRigidBody *rbB,
        hkVector4f *_position,
        hkVector4f *_normal,
        float _speed,
        unsigned __int64 objectPropertiesHandleUIDA,
        unsigned __int64 objectPropertiesHandleUIDB,
        unsigned __int64 surfacePropertiesHandleUIDA,
        unsigned __int64 surfacePropertiesHandleUIDB)
{
  unsigned int mUID; // r10d
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4

  mUID = UFG::gCollisionEventChannel.mUID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = mUID;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::CollisionEvent::`vftable;
  this->mType = type;
  `eh vector constructor iterator(
    this->mSimObject,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v15 = _position->m_quad.m128_f32[1];
  v16 = _position->m_quad.m128_f32[2];
  LODWORD(this->position.x) = _position->m_quad.m128_i32[0];
  this->position.y = v15;
  this->position.z = v16;
  v17 = _normal->m_quad.m128_f32[1];
  v18 = _normal->m_quad.m128_f32[2];
  LODWORD(this->normal.x) = _normal->m_quad.m128_i32[0];
  this->normal.y = v17;
  this->normal.z = v18;
  this->speed = _speed;
  v19 = UFG::EstimateImpulseMagnitude(rbA, rbB, _position, _normal, _speed, 0.5);
  v20 = logf(v19);
  this->estimatedImpulseMagnitude = v20;
  if ( v20 < 0.0 )
    this->estimatedImpulseMagnitude = 0.0;
  v21 = rbA->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
  v22 = rbA->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
  LODWORD(this->preCollisionPosition[0].x) = rbA->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_i32[0];
  this->preCollisionPosition[0].y = v21;
  this->preCollisionPosition[0].z = v22;
  v23 = rbB->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
  v24 = rbB->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
  LODWORD(this->preCollisionPosition[1].x) = rbB->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_i32[0];
  this->preCollisionPosition[1].y = v23;
  this->preCollisionPosition[1].z = v24;
  v25 = rbA->m_motion.m_linearVelocity.m_quad.m128_f32[1];
  v26 = rbA->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  LODWORD(this->velocity[0].x) = rbA->m_motion.m_linearVelocity.m_quad.m128_i32[0];
  this->velocity[0].y = v25;
  this->velocity[0].z = v26;
  v27 = rbB->m_motion.m_linearVelocity.m_quad.m128_f32[1];
  v28 = rbB->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  LODWORD(this->velocity[1].x) = rbB->m_motion.m_linearVelocity.m_quad.m128_i32[0];
  this->velocity[1].y = v27;
  this->velocity[1].z = v28;
  this->havokUserData[0] = (UFG::HavokUserData *)rbA->m_userData;
  this->havokUserData[1] = (UFG::HavokUserData *)rbB->m_userData;
  this->objectPropertyHandleUID[0] = objectPropertiesHandleUIDA;
  this->objectPropertyHandleUID[1] = objectPropertiesHandleUIDB;
  this->surfacePropertyHandleUID[0] = surfacePropertiesHandleUIDA;
  this->surfacePropertyHandleUID[1] = surfacePropertiesHandleUIDB;
  UFG::ThreadSafeQueue<hkpEntity>::AddHead(UFG::CollisionEvent::mQueue, this);
}

// File Line: 121
// RVA: 0xA8720
void __fastcall UFG::CollisionEvent::FixupSimObjectPtrs(UFG::CollisionEvent *this)
{
  UFG::HavokUserData *v1; // rax
  UFG::SimObject *v2; // r8
  UFG::SimComponent *m_pPointer; // r10
  UFG::SimObject *m_pSimObject; // r10
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *mSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::HavokUserData *v10; // rax
  UFG::SimComponent *v11; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = this->havokUserData[0];
  v2 = 0i64;
  if ( v1 )
  {
    m_pPointer = v1->simComponent.m_pPointer;
    if ( m_pPointer )
      m_pSimObject = m_pPointer->m_pSimObject;
    else
      m_pSimObject = 0i64;
    mSimObject = this->mSimObject;
    if ( this->mSimObject[0].m_pPointer )
    {
      mPrev = mSimObject->mPrev;
      mNext = mSimObject->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      mSimObject->mPrev = mSimObject;
      mSimObject->mNext = mSimObject;
    }
    mSimObject->m_pPointer = m_pSimObject;
    if ( m_pSimObject )
    {
      v9 = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v9->mNext = mSimObject;
      mSimObject->mPrev = v9;
      mSimObject->mNext = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = mSimObject;
    }
  }
  v10 = this->havokUserData[1];
  if ( v10 )
  {
    v11 = v10->simComponent.m_pPointer;
    if ( v11 )
      v2 = v11->m_pSimObject;
    v12 = &this->mSimObject[1];
    if ( this->mSimObject[1].m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = this->mSimObject[1].mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = v12;
      this->mSimObject[1].mNext = &this->mSimObject[1];
    }
    this->mSimObject[1].m_pPointer = v2;
    if ( v2 )
    {
      v15 = v2->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v15->mNext = v12;
      v12->mPrev = v15;
      this->mSimObject[1].mNext = &v2->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v2->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v12;
    }
  }
}

// File Line: 136
// RVA: 0xAE280
void UFG::CollisionEvent::PostEvents(void)
{
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v0; // rbx
  _RTL_CRITICAL_SECTION *p_mutex; // rdi
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v2; // rdi
  _RTL_CRITICAL_SECTION *v3; // rbp
  UFG::CollisionEvent *data; // rsi
  UFG::QueueNode<UFG::CollisionEvent> *p_tail; // rbx
  UFG::QueueNode<UFG::CollisionEvent> *prev; // rcx
  UFG::QueueNode<UFG::CollisionEvent> *v7; // rax
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v8; // rbx
  _RTL_CRITICAL_SECTION *v9; // rdi

  v0 = UFG::CollisionEvent::mQueue;
  p_mutex = (_RTL_CRITICAL_SECTION *)&UFG::CollisionEvent::mQueue->mutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::CollisionEvent::mQueue->mutex);
  LOBYTE(v0) = v0->head.next == &v0->tail;
  UFG::qMutex::Unlock(p_mutex);
  if ( !(_BYTE)v0 )
  {
    do
    {
      v2 = UFG::CollisionEvent::mQueue;
      v3 = (_RTL_CRITICAL_SECTION *)&UFG::CollisionEvent::mQueue->mutex;
      data = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::CollisionEvent::mQueue->mutex);
      UFG::qMutex::Lock(v3);
      p_tail = &v2->tail;
      LOBYTE(v2) = v2->head.next == &v2->tail;
      UFG::qMutex::Unlock(v3);
      if ( !(_BYTE)v2 )
      {
        prev = p_tail->prev;
        v7 = p_tail->prev->prev;
        v7->next = p_tail;
        p_tail->prev = v7;
        data = prev->data;
        operator delete[](prev);
      }
      UFG::qMutex::Unlock(v3);
      UFG::CollisionEvent::FixupSimObjectPtrs(data);
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, data);
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
  char *v2; // rax

  v2 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x10ui64, "WorldCollisionListener", 0i64, 1u);
  if ( v2 )
  {
    *(_QWORD *)v2 = &hkpContactListener::`vftable;
    *(_QWORD *)v2 = &UFG::WorldCollisionListener::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
  }
  UFG::WorldCollisionListener::mInstance = (UFG::WorldCollisionListener *)v2;
  hkpWorld::addContactListener(world, (hkpContactListener *)v2);
}

// File Line: 181
// RVA: 0xA10E0
void __fastcall UFG::WorldCollisionListener::BeginFrame(UFG::WorldCollisionListener *this)
{
  *(_QWORD *)&this->mCollisionEventsThisFrame = 0i64;
}

// File Line: 189
// RVA: 0xA7DF0
// attributes: thunk
void __fastcall UFG::WorldCollisionListener::EndFrame(UFG::WorldCollisionListener *this, hkpWorld *world)
{
  UFG::CollisionEvent::PostEvents();
}

// File Line: 198
// RVA: 0xB7160
void __fastcall UFG::WorldCollisionListener::contactPointAddedCallback(
        UFG::WorldCollisionListener *this,
        hkpContactPointAddedEvent *evt)
{
  hkpCdBody *m_bodyA; // r9
  hkpCdBody *m_parent; // rax
  hkpCollidable *i; // r8
  hkpCdBody *m_bodyB; // r8
  hkpCollidable *v7; // rax
  hkpCollidable *j; // rcx
  unsigned int m_shapeKey; // eax
  hkContactPoint *m_contactPoint; // rax
  hkVector4f v11; // xmm1
  UFG::WorldCollisionListener::ContactPointAddedEvent evta; // [rsp+20h] [rbp-48h] BYREF

  m_bodyA = evt->m_bodyA;
  m_parent = evt->m_bodyA->m_parent;
  for ( i = (hkpCollidable *)evt->m_bodyA; m_parent; m_parent = m_parent->m_parent )
    i = (hkpCollidable *)m_parent;
  evta.collA = i;
  m_bodyB = evt->m_bodyB;
  v7 = (hkpCollidable *)m_bodyB->m_parent;
  for ( j = (hkpCollidable *)m_bodyB; v7; v7 = (hkpCollidable *)v7->m_parent )
    j = v7;
  m_shapeKey = m_bodyA->m_shapeKey;
  evta.collB = j;
  evta.shapeKeyA = m_shapeKey;
  evta.shapeKeyB = m_bodyB->m_shapeKey;
  m_contactPoint = evt->m_contactPoint;
  v11.m_quad = (__m128)m_contactPoint->m_separatingNormal;
  evta.position = m_contactPoint->m_position;
  evta.normal = (hkVector4f)v11.m_quad;
  evta.projectedVel = evt->m_projectedVelocity;
  UFG::WorldCollisionListener::ContactPointAddedCallback(this, &evta);
}

// File Line: 214
// RVA: 0xB7200
void __fastcall UFG::WorldCollisionListener::contactProcessCallback(
        UFG::WorldCollisionListener *this,
        hkpContactProcessEvent *evt)
{
  hkpProcessCollisionData *m_collisionData; // rbx
  int i; // edi
  UFG::WorldCollisionListener::ContactProcessEvent evta; // [rsp+20h] [rbp-28h] BYREF

  m_collisionData = evt->m_collisionData;
  for ( i = 0;
        i < (int)(((char *)m_collisionData->m_firstFreeContactPoint.m_storage - (char *)m_collisionData - 16) / 48);
        ++i )
  {
    evta.collA = evt->m_collidableA;
    evta.collB = evt->m_collidableB;
    evta.cp = &m_collisionData->m_contactPoints[i].m_contact;
    UFG::WorldCollisionListener::ContactProcessCallback(this, &evta);
  }
}

// File Line: 230
// RVA: 0xA3FE0
void __fastcall UFG::WorldCollisionListener::ContactPointAddedCallback(
        UFG::WorldCollisionListener *this,
        UFG::WorldCollisionListener::ContactPointAddedEvent *evt)
{
  hkpCollidable *collA; // r8
  hkpShape *m_shape; // rdx
  hkpCollidable *collB; // rax
  hkpShape *v7; // rdi
  unsigned __int64 surfacePropertiesHandleUIDB; // rbx
  hkpRigidBody *v9; // r15
  hkpRigidBody *v10; // rbp
  signed int shapeKeyA; // r9d
  __int64 v12; // rsi
  unsigned __int64 m_userData; // rdx
  char v14; // cl
  signed int v15; // r8d
  __int64 v16; // rcx
  signed int shapeKeyB; // r9d
  __int64 v18; // r10
  unsigned __int64 v19; // rdx
  char v20; // r8
  __int64 v21; // rax
  __int64 v22; // rcx
  unsigned __int64 objectPropertiesHandleUIDA; // r14
  int v24; // eax
  int m_size; // r8d
  hkSimpleProperty *m_data; // rcx
  unsigned __int64 objectPropertiesHandleUIDB; // rdi
  int v28; // eax
  int v29; // r8d
  hkSimpleProperty *v30; // rcx
  unsigned __int64 surfacePropertiesHandleUIDA; // rsi
  unsigned int mCollisionEventsThisFrame; // ecx
  char *v33; // rax

  collA = evt->collA;
  m_shape = collA->m_shape;
  collB = evt->collB;
  v7 = collB->m_shape;
  surfacePropertiesHandleUIDB = 0i64;
  if ( collA->m_broadPhaseHandle.m_type == 1 )
    v9 = (hkpRigidBody *)((char *)collA + collA->m_ownerOffset);
  else
    v9 = 0i64;
  if ( collB->m_broadPhaseHandle.m_type == 1 )
    v10 = (hkpRigidBody *)((char *)collB + collB->m_ownerOffset);
  else
    v10 = 0i64;
  shapeKeyA = evt->shapeKeyA;
  v12 = 0i64;
  if ( shapeKeyA != -1 && m_shape->m_type.m_storage == 9 )
  {
    m_userData = m_shape[2].m_userData;
    if ( m_userData )
    {
      v14 = *(_BYTE *)(m_userData + 41);
      if ( v14 == 1 || v14 == 3 )
      {
        v15 = (shapeKeyA & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(m_userData + 232));
        if ( shapeKeyA < 0 )
          v16 = *(_QWORD *)(m_userData + 256) + 80i64 * v15;
        else
          v16 = *(_QWORD *)(m_userData + 240) + 144i64 * v15;
        v12 = *(_QWORD *)(v16 + 16);
      }
    }
  }
  shapeKeyB = evt->shapeKeyB;
  v18 = 0i64;
  if ( shapeKeyB != -1 && v7->m_type.m_storage == 9 )
  {
    v19 = v7[2].m_userData;
    if ( v19 )
    {
      v20 = *(_BYTE *)(v19 + 41);
      if ( v20 == 1 || v20 == 3 )
      {
        v21 = (shapeKeyB & 0x7FFFFFFFu) >> (32 - *(_BYTE *)(v19 + 232));
        if ( shapeKeyB < 0 )
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
    m_size = v9->m_properties.m_size;
    if ( m_size <= 0 )
    {
LABEL_33:
      objectPropertiesHandleUIDA = 0i64;
    }
    else
    {
      m_data = v9->m_properties.m_data;
      while ( m_data->m_key != UFG::physicsObjectPropertyTypeUid )
      {
        ++v24;
        ++m_data;
        if ( v24 >= m_size )
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
      if ( COERCE_FLOAT(LODWORD(evt->projectedVel) & _xmm) >= 2.25 )
      {
        mCollisionEventsThisFrame = this->mCollisionEventsThisFrame;
        this->mCollisionEventsThisFrame = mCollisionEventsThisFrame + 1;
        if ( mCollisionEventsThisFrame < 0x10 )
        {
          v33 = UFG::qMalloc(0xF0ui64, "CollisionEvent", 0i64);
          if ( v33 )
            UFG::CollisionEvent::CollisionEvent(
              (UFG::CollisionEvent *)v33,
              UNSUPPORTED,
              v9,
              v10,
              &evt->position,
              &evt->normal,
              evt->projectedVel,
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
void __fastcall UFG::WorldCollisionListener::ContactProcessCallback(
        UFG::WorldCollisionListener *this,
        UFG::WorldCollisionListener::ContactProcessEvent *evt)
{
  hkpRigidBody *v3; // rsi
  hkpCollidable *collB; // rax
  hkpRigidBody *v5; // rbp
  int v6; // eax
  int m_size; // r8d
  hkSimpleProperty *m_data; // rcx
  unsigned __int64 objectPropertiesHandleUIDA; // rdi
  int v10; // eax
  int v11; // r8d
  hkSimpleProperty *v12; // rcx
  unsigned __int64 objectPropertiesHandleUIDB; // rbx
  hkContactPoint *_position; // r14
  __m128 m_quad; // xmm8
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
  unsigned int mContinuousEventsThisFrame; // ecx
  char *v41; // rax
  __m128 v42; // xmm6
  __m128 v43; // xmm1
  hkVector4f _normal; // [rsp+70h] [rbp-78h] BYREF

  if ( evt->collA->m_broadPhaseHandle.m_type == 1 )
    v3 = (hkpRigidBody *)((char *)evt->collA + evt->collA->m_ownerOffset);
  else
    v3 = 0i64;
  collB = evt->collB;
  if ( collB->m_broadPhaseHandle.m_type == 1 )
    v5 = (hkpRigidBody *)((char *)collB + collB->m_ownerOffset);
  else
    v5 = 0i64;
  v6 = 0;
  m_size = v3->m_properties.m_size;
  if ( m_size <= 0 )
  {
LABEL_13:
    objectPropertiesHandleUIDA = 0i64;
  }
  else
  {
    m_data = v3->m_properties.m_data;
    while ( m_data->m_key != UFG::physicsObjectPropertyTypeUid )
    {
      ++v6;
      ++m_data;
      if ( v6 >= m_size )
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
  m_quad = _position->m_separatingNormal.m_quad;
  _normal.m_quad = m_quad;
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
  v21 = _mm_mul_ps(v20, m_quad);
  v22 = _mm_shuffle_ps(v21, v21, 0);
  v22.m128_f32[0] = _mm_shuffle_ps(v21, v21, 170).m128_f32[0]
                  + (float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + v22.m128_f32[0]);
  v23 = _mm_sub_ps(v20, _mm_mul_ps(m_quad, _mm_shuffle_ps(v22, v22, 0)));
  v24 = _mm_mul_ps(v23, v23);
  v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 170), _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)));
  v26 = _mm_rsqrt_ps(v25);
  LODWORD(_speed) = _mm_andnot_ps(
                      _mm_cmple_ps(v25, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                          _mm_mul_ps(v26, *(__m128 *)_xmm)),
                        v25)).m128_u32[0];
  if ( COERCE_FLOAT((unsigned int)(2 * v22.m128_i32[0]) >> 1) >= 0.0099999998 || _speed <= 0.5 )
  {
    v30 = _mm_mul_ps(v20, v20);
    v31 = _mm_add_ps(
            _mm_shuffle_ps(v30, v30, 170),
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)));
    v32 = _mm_rsqrt_ps(v31);
    if ( _mm_andnot_ps(
           _mm_cmple_ps(v31, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
               _mm_mul_ps(v32, *(__m128 *)_xmm)),
             v31)).m128_f32[0] < 0.1 )
    {
      v33 = _mm_sub_ps(v5->m_motion.m_linearVelocity.m_quad, v3->m_motion.m_linearVelocity.m_quad);
      v34 = _mm_mul_ps(v33, m_quad);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 0), _mm_shuffle_ps(v34, v34, 85)),
              _mm_shuffle_ps(v34, v34, 170));
      v36 = _mm_sub_ps(v33, _mm_mul_ps(m_quad, _mm_shuffle_ps(v35, v35, 0)));
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_add_ps(
              _mm_shuffle_ps(v37, v37, 170),
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)));
      v39 = _mm_rsqrt_ps(v38);
      if ( _mm_andnot_ps(
             _mm_cmple_ps(v38, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                 _mm_mul_ps(v39, *(__m128 *)_xmm)),
               v38)).m128_f32[0] > 0.5 )
      {
        mContinuousEventsThisFrame = this->mContinuousEventsThisFrame;
        this->mContinuousEventsThisFrame = mContinuousEventsThisFrame + 1;
        if ( mContinuousEventsThisFrame < 4 )
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
              _mm_andnot_ps(
                _mm_cmple_ps(v42, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                    _mm_mul_ps(v43, *(__m128 *)_xmm)),
                  v42)).m128_f32[0],
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
    v28 = this->mContinuousEventsThisFrame;
    this->mContinuousEventsThisFrame = v28 + 1;
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

