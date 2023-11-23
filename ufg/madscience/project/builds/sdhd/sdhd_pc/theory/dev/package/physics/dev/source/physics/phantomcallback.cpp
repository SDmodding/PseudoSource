// File Line: 43
// RVA: 0xB8880
void __fastcall UFG::PhantomCallbackShape::phantomEnterEvent(
        UFG::PhantomCallbackShape *this,
        hkpCollidable *phantomColl,
        hkpCollidable *otherColl,
        hkpCollisionInput *env)
{
  hkReferencedObject *v5; // rdi
  char *v6; // rax
  UFG::CollisionEvent *v7; // rbx

  if ( otherColl->m_broadPhaseHandle.m_type == 1 )
  {
    v5 = (hkReferencedObject *)((char *)otherColl + otherColl->m_ownerOffset);
    if ( v5 )
    {
      v6 = UFG::qMalloc(0x18ui64, "PhantomCallbackData", 0i64);
      *(_DWORD *)v6 = 0;
      *((_QWORD *)v6 + 2) = v5;
      v7 = (UFG::CollisionEvent *)v6;
      hkReferencedObject::addReference(v5);
      v7->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)this;
      hkReferencedObject::addReference(this);
      UFG::ThreadSafeQueue<hkpEntity>::AddHead(
        (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&UFG::PhantomCallback::mInstance->mPhantomCallbackQueue,
        v7);
    }
  }
}

// File Line: 66
// RVA: 0xB8900
void __fastcall UFG::PhantomCallbackShape::phantomLeaveEvent(
        UFG::PhantomCallbackShape *this,
        hkpCollidable *phantomColl,
        hkpCollidable *otherColl)
{
  hkReferencedObject *v4; // rdi
  char *v5; // rax
  UFG::CollisionEvent *v6; // rbx

  if ( otherColl->m_broadPhaseHandle.m_type == 1 )
  {
    v4 = (hkReferencedObject *)((char *)otherColl + otherColl->m_ownerOffset);
    if ( v4 )
    {
      v5 = UFG::qMalloc(0x18ui64, "PhantomCallbackData", 0i64);
      *(_DWORD *)v5 = 1;
      *((_QWORD *)v5 + 2) = v4;
      v6 = (UFG::CollisionEvent *)v5;
      hkReferencedObject::addReference(v4);
      v6->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)this;
      hkReferencedObject::addReference(this);
      UFG::ThreadSafeQueue<hkpEntity>::AddHead(
        (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&UFG::PhantomCallback::mInstance->mPhantomCallbackQueue,
        v6);
    }
  }
}

// File Line: 92
// RVA: 0xAC9B0
void UFG::PhantomCallback::Initialize(void)
{
  char *v0; // rax
  UFG::PhantomCallback *v1; // rax

  v0 = UFG::qMalloc(0x68ui64, "PhantomCallback", 0i64);
  if ( v0 )
  {
    UFG::PhantomCallback::PhantomCallback((UFG::PhantomCallback *)v0);
    UFG::PhantomCallback::mInstance = v1;
  }
  else
  {
    UFG::PhantomCallback::mInstance = 0i64;
  }
}

// File Line: 97
// RVA: 0xB2A60
void UFG::PhantomCallback::Shutdown(void)
{
  if ( UFG::PhantomCallback::mInstance )
    UFG::PhantomCallback::mInstance->vfptr->__vecDelDtor(UFG::PhantomCallback::mInstance, 1i64);
  UFG::PhantomCallback::mInstance = 0i64;
}

// File Line: 103
// RVA: 0x98F50
void __fastcall UFG::PhantomCallback::PhantomCallback(UFG::PhantomCallback *this)
{
  UFG::ThreadSafeQueue<UFG::PhantomCallbackData> *p_mPhantomCallbackQueue; // rbx

  this->vfptr = (UFG::PhantomCallbackVtbl *)&UFG::PhantomCallback::`vftable;
  p_mPhantomCallbackQueue = &this->mPhantomCallbackQueue;
  UFG::qMutex::qMutex(&this->mPhantomCallbackQueue.mutex, &customCaption);
  p_mPhantomCallbackQueue->head.next = &p_mPhantomCallbackQueue->tail;
  p_mPhantomCallbackQueue->head.prev = 0i64;
  p_mPhantomCallbackQueue->tail.prev = &p_mPhantomCallbackQueue->head;
  p_mPhantomCallbackQueue->tail.next = 0i64;
}

// File Line: 107
// RVA: 0x9C920
void __fastcall UFG::PhantomCallback::~PhantomCallback(UFG::PhantomCallback *this)
{
  UFG::ThreadSafeQueue<UFG::PhantomCallbackData> *p_mPhantomCallbackQueue; // rsi
  bool v2; // bl
  hkReferencedObject **data; // rbx
  UFG::QueueNode<UFG::PhantomCallbackData> *p_tail; // r14
  bool v5; // di
  UFG::QueueNode<UFG::PhantomCallbackData> *prev; // rcx
  UFG::QueueNode<UFG::PhantomCallbackData> *v7; // rax
  bool v8; // bl

  this->vfptr = (UFG::PhantomCallbackVtbl *)&UFG::PhantomCallback::`vftable;
  p_mPhantomCallbackQueue = &this->mPhantomCallbackQueue;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
  v2 = p_mPhantomCallbackQueue->head.next == &p_mPhantomCallbackQueue->tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
  if ( !v2 )
  {
    do
    {
      data = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
      p_tail = &p_mPhantomCallbackQueue->tail;
      v5 = p_mPhantomCallbackQueue->head.next == &p_mPhantomCallbackQueue->tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
      if ( !v5 )
      {
        prev = p_tail->prev;
        v7 = p_tail->prev->prev;
        v7->next = p_tail;
        p_tail->prev = v7;
        data = (hkReferencedObject **)prev->data;
        operator delete[](prev);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
      if ( data )
      {
        hkReferencedObject::removeReference(data[2]);
        hkReferencedObject::removeReference(data[1]);
        operator delete[](data);
      }
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
      v8 = p_mPhantomCallbackQueue->head.next == &p_mPhantomCallbackQueue->tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&p_mPhantomCallbackQueue->mutex);
    }
    while ( !v8 );
  }
  UFG::ThreadSafeQueue<UFG::PhantomCallbackData>::~ThreadSafeQueue<UFG::PhantomCallbackData>(p_mPhantomCallbackQueue);
}

// File Line: 118
// RVA: 0xA5700
hkpEntity *__fastcall UFG::PhantomCallback::CreatePhantom(
        UFG::qVector3 *halfExtents,
        UFG::qMatrix44 *transform,
        unsigned int volumePropertyKey)
{
  __int64 v5; // rbx
  char v6; // dl
  char v7; // cl
  _QWORD **Value; // rax
  hkpBoxShape *v9; // rax
  hkpShape *v10; // rax
  hkpShape *v11; // rcx
  char v12; // al
  hkVector4f halfExtentsa; // [rsp+30h] [rbp-18h] BYREF

  halfExtentsa.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(halfExtents->x), (__m128)LODWORD(halfExtents->z)),
                          _mm_unpacklo_ps((__m128)LODWORD(halfExtents->y), (__m128)(unsigned int)FLOAT_1_0));
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v6) = 3;
  *(_QWORD *)(v5 + 8i64 * v6 + 16) = "hkpBoxShape";
  *(_QWORD *)(v5 + 8i64 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v5 + 81);
  if ( v6 > v7 )
    v7 = v6;
  *(_BYTE *)(v5 + 81) = v7;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpBoxShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  if ( v9 )
  {
    hkpBoxShape::hkpBoxShape(v9, &halfExtentsa, 0.0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *(_BYTE *)(v5 + 80);
  if ( v12 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v12 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  return UFG::PhantomCallback::CreatePhantom(v11, transform, volumePropertyKey);
}

// File Line: 133
// RVA: 0xA5820
hkpEntity *__fastcall UFG::PhantomCallback::CreatePhantom(
        hkpShape *phantomShape,
        UFG::qMatrix44 *transform,
        unsigned int volumePropertyKey)
{
  UFG::qReflectObject *v5; // rsi
  __int64 v6; // rbx
  char v7; // dl
  char v8; // cl
  _QWORD **Value; // rax
  __int64 v10; // rdi
  char v11; // al
  char v12; // dl
  char v13; // cl
  _QWORD **v14; // rax
  hkpBvShape *v15; // rax
  hkpShape *v16; // rax
  hkpShape *v17; // rsi
  char v18; // al
  char v19; // dl
  char v20; // cl
  _QWORD **v21; // rax
  hkpRigidBody *v22; // rax
  hkpEntity *v23; // rax
  hkpEntity *v24; // rdi
  char v25; // al
  hkArray<hkpEntity *,hkContainerHeapAllocator> *p_mEntitiesToAdd; // rbx
  hkQsTransformf v28; // [rsp+30h] [rbp-168h] BYREF
  hkTransformf transforma; // [rsp+60h] [rbp-138h] BYREF
  hkpRigidBodyCinfo info; // [rsp+A0h] [rbp-F8h] BYREF

  hkTransformf::set4x4ColumnMajor(&transforma, &transform->v0.x);
  hkQsTransformf::setFromTransformNoScale(&v28, &transforma);
  v5 = UFG::PhysicsVolumePropertyManager::Find(volumePropertyKey, 1);
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  *(_DWORD *)(v6 + 4i64 * v7) = 3;
  *(_QWORD *)(v6 + 8i64 * v7 + 16) = "PhantomCallbackShape";
  *(_QWORD *)(v6 + 8i64 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v6 + 81);
  if ( v7 > v8 )
    v8 = v7;
  *(_BYTE *)(v6 + 81) = v8;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v10 )
  {
    *(_QWORD *)v10 = &hkBaseObject::`vftable;
    *(_QWORD *)v10 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v10 + 8) = 0x1FFFF;
    *(_QWORD *)v10 = &hkcdShape::`vftable;
    *(_DWORD *)(v10 + 16) = 1056;
    *(_QWORD *)v10 = &hkpShapeBase::`vftable;
    *(_QWORD *)v10 = &hkpShape::`vftable;
    *(_QWORD *)(v10 + 24) = 0i64;
    *(_QWORD *)v10 = &hkpPhantomCallbackShape::`vftable;
    *(_QWORD *)v10 = &UFG::PhantomCallbackShape::`vftable;
    *(_QWORD *)(v10 + 32) = v5;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = *(_BYTE *)(v6 + 80);
  if ( v11 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v11 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v12 = ++*(_BYTE *)(v6 + 80);
  *(_DWORD *)(v6 + 4i64 * v12) = 3;
  *(_QWORD *)(v6 + 8i64 * v12 + 16) = "hkpBvShape";
  *(_QWORD *)(v6 + 8i64 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v6 + 81);
  if ( v12 > v13 )
    v13 = v12;
  *(_BYTE *)(v6 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkpBvShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 56i64);
  if ( v15 )
  {
    hkpBvShape::hkpBvShape(v15, phantomShape, (hkpShape *)v10);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = *(_BYTE *)(v6 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(phantomShape);
  hkReferencedObject::removeReference((hkReferencedObject *)v10);
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  info.m_motionType.m_storage = 5;
  info.m_position = v28.m_translation;
  info.m_rotation = v28.m_rotation;
  info.m_collisionFilterInfo = 19;
  info.m_shape = v17;
  v19 = ++*(_BYTE *)(v6 + 80);
  *(_DWORD *)(v6 + 4i64 * v19) = 0;
  *(_QWORD *)(v6 + 8i64 * v19 + 16) = "hkpRigidBody";
  *(_QWORD *)(v6 + 8i64 * v19 + 48) = 0i64;
  v20 = *(_BYTE *)(v6 + 81);
  if ( v19 > v20 )
    v20 = v19;
  *(_BYTE *)(v6 + 81) = v20;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 720i64);
  if ( v22 )
  {
    hkpRigidBody::hkpRigidBody(v22, &info);
    v24 = v23;
  }
  else
  {
    v24 = 0i64;
  }
  v25 = *(_BYTE *)(v6 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  hkReferencedObject::removeReference(v17);
  p_mEntitiesToAdd = &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd;
  if ( UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size == (UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd, 8);
  p_mEntitiesToAdd->m_data[p_mEntitiesToAdd->m_size++] = v24;
  return v24;
}

// File Line: 182
// RVA: 0xA6F50
void __fastcall UFG::PhantomCallback::DestroyPhantom(hkpRigidBody *phantomRigidBody)
{
  UFG::BasePhysicsSystem *v1; // rdi
  int v2; // r8d
  __int64 m_size; // rcx
  __int64 v5; // rdx
  hkpEntity **m_data; // rax
  __int64 v7; // rax
  hkpWorld *m_world; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *p_mEntitiesToRemove; // rdi
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  v1 = UFG::BasePhysicsSystem::mInstance;
  v2 = 0;
  m_size = UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size;
  v5 = 0i64;
  if ( m_size > 0 )
  {
    m_data = UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_data;
    while ( *m_data != phantomRigidBody )
    {
      ++v5;
      ++v2;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_8;
    }
    --UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size;
    v7 = v1->mEntitiesToAdd.m_size;
    if ( (_DWORD)v7 != v2 )
      v1->mEntitiesToAdd.m_data[v2] = v1->mEntitiesToAdd.m_data[v7];
  }
LABEL_8:
  m_world = phantomRigidBody->m_world;
  if ( m_world )
  {
    if ( !v1->mForceRemoveEntitiesToBeBatched )
    {
      hkpWorld::removeEntity(m_world, &result, phantomRigidBody);
      hkReferencedObject::removeReference(phantomRigidBody);
      return;
    }
    p_mEntitiesToRemove = &v1->mEntitiesToRemove;
    if ( p_mEntitiesToRemove->m_size == (p_mEntitiesToRemove->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mEntitiesToRemove, 8);
    p_mEntitiesToRemove->m_data[p_mEntitiesToRemove->m_size++] = phantomRigidBody;
    hkReferencedObject::addReference(phantomRigidBody);
  }
  hkReferencedObject::removeReference(phantomRigidBody);
}

// File Line: 193
// RVA: 0xB48C0
void __fastcall UFG::PhantomCallback::Update(UFG::PhantomCallback *this, float delta_sec)
{
  UFG::BasePhysicsSystem *v2; // r15
  UFG::QueueNode<UFG::PhantomCallbackData> *p_tail; // rsi
  bool v5; // bl
  hkReferencedObject **data; // rdi
  bool v7; // bl
  UFG::QueueNode<UFG::PhantomCallbackData> *prev; // rcx
  UFG::QueueNode<UFG::PhantomCallbackData> *v9; // rax
  __int64 v10; // r8
  UFG::SimObject *mParent; // r8
  bool v12; // bl

  v2 = UFG::BasePhysicsSystem::mInstance;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
  p_tail = &this->mPhantomCallbackQueue.tail;
  v5 = this->mPhantomCallbackQueue.head.next == &this->mPhantomCallbackQueue.tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
  if ( !v5 )
  {
    do
    {
      data = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
      v7 = this->mPhantomCallbackQueue.head.next == p_tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
      if ( !v7 )
      {
        prev = p_tail->prev;
        v9 = p_tail->prev->prev;
        v9->next = p_tail;
        p_tail->prev = v9;
        data = (hkReferencedObject **)prev->data;
        operator delete[](prev);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
      v10 = *(_QWORD *)&data[2][1].m_memSizeAndFlags;
      if ( v10 )
      {
        mParent = *(UFG::SimObject **)(v10 + 24);
        if ( mParent )
          mParent = (UFG::SimObject *)mParent->mNode.mParent;
        if ( mParent )
          v2->vfptr->PhysicsVolumeHandler(v2, this, mParent, (UFG::PhantomCallbackData *)data);
      }
      hkReferencedObject::removeReference(data[2]);
      hkReferencedObject::removeReference(data[1]);
      operator delete[](data);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
      v12 = this->mPhantomCallbackQueue.head.next == p_tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
    }
    while ( !v12 );
  }
}

