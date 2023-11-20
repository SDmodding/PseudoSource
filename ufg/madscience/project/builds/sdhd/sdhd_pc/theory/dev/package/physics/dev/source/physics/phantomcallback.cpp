// File Line: 43
// RVA: 0xB8880
void __fastcall UFG::PhantomCallbackShape::phantomEnterEvent(UFG::PhantomCallbackShape *this, hkpCollidable *phantomColl, hkpCollidable *otherColl, hkpCollisionInput *env)
{
  UFG::PhantomCallbackShape *v4; // rsi
  hkReferencedObject *v5; // rdi
  char *v6; // rax
  UFG::CollisionEvent *v7; // rbx

  v4 = this;
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
      v7->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v4;
      hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
      UFG::ThreadSafeQueue<hkpEntity>::AddHead(
        (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&UFG::PhantomCallback::mInstance->mPhantomCallbackQueue,
        v7);
    }
  }
}

// File Line: 66
// RVA: 0xB8900
void __fastcall UFG::PhantomCallbackShape::phantomLeaveEvent(UFG::PhantomCallbackShape *this, hkpCollidable *phantomColl, hkpCollidable *otherColl)
{
  UFG::PhantomCallbackShape *v3; // rsi
  hkReferencedObject *v4; // rdi
  char *v5; // rax
  UFG::CollisionEvent *v6; // rbx

  v3 = this;
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
      v6->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v3;
      hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
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
    UFG::PhantomCallback::mInstance->vfptr->__vecDelDtor(UFG::PhantomCallback::mInstance, 1u);
  UFG::PhantomCallback::mInstance = 0i64;
}

// File Line: 103
// RVA: 0x98F50
void __fastcall UFG::PhantomCallback::PhantomCallback(UFG::PhantomCallback *this)
{
  UFG::ThreadSafeQueue<UFG::PhantomCallbackData> *v1; // rbx

  this->vfptr = (UFG::PhantomCallbackVtbl *)&UFG::PhantomCallback::`vftable';
  v1 = &this->mPhantomCallbackQueue;
  UFG::qMutex::qMutex(&this->mPhantomCallbackQueue.mutex, &customWorldMapCaption);
  v1->head.next = &v1->tail;
  v1->head.prev = 0i64;
  v1->tail.prev = &v1->head;
  v1->tail.next = 0i64;
}

// File Line: 107
// RVA: 0x9C920
void __fastcall UFG::PhantomCallback::~PhantomCallback(UFG::PhantomCallback *this)
{
  UFG::ThreadSafeQueue<UFG::PhantomCallbackData> *v1; // rsi
  bool v2; // bl
  hkReferencedObject **v3; // rbx
  UFG::QueueNode<UFG::PhantomCallbackData> *v4; // r14
  bool v5; // di
  UFG::QueueNode<UFG::PhantomCallbackData> *v6; // rcx
  UFG::QueueNode<UFG::PhantomCallbackData> *v7; // rax
  bool v8; // bl

  this->vfptr = (UFG::PhantomCallbackVtbl *)&UFG::PhantomCallback::`vftable';
  v1 = &this->mPhantomCallbackQueue;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
  v2 = v1->head.next == &v1->tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
  if ( !v2 )
  {
    do
    {
      v3 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mutex);
      v4 = &v1->tail;
      v5 = v1->head.next == &v1->tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
      if ( !v5 )
      {
        v6 = v4->prev;
        v7 = v4->prev->prev;
        v7->next = v4;
        v4->prev = v7;
        v3 = (hkReferencedObject **)v6->data;
        operator delete[](v6);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
      if ( v3 )
      {
        hkReferencedObject::removeReference(v3[2]);
        hkReferencedObject::removeReference(v3[1]);
        operator delete[](v3);
      }
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mutex);
      v8 = v1->head.next == &v1->tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mutex);
    }
    while ( !v8 );
  }
  UFG::ThreadSafeQueue<UFG::PhantomCallbackData>::~ThreadSafeQueue<UFG::PhantomCallbackData>(v1);
}

// File Line: 118
// RVA: 0xA5700
hkpEntity *__fastcall UFG::PhantomCallback::CreatePhantom(UFG::qVector3 *halfExtents, UFG::qMatrix44 *transform, unsigned int volumePropertyKey)
{
  unsigned int v3; // edi
  UFG::qMatrix44 *v4; // rsi
  signed __int64 v5; // rbx
  char v6; // dl
  __int64 v7; // rax
  char v8; // cl
  _QWORD **v9; // rax
  hkpBoxShape *v10; // rax
  hkpShape *v11; // rax
  hkpShape *v12; // rcx
  char v13; // al
  hkVector4f halfExtentsa; // [rsp+30h] [rbp-18h]

  v3 = volumePropertyKey;
  v4 = transform;
  halfExtentsa.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(halfExtents->x), (__m128)LODWORD(halfExtents->z)),
                          _mm_unpacklo_ps((__m128)LODWORD(halfExtents->y), (__m128)(unsigned int)FLOAT_1_0));
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  v7 = v6;
  *(_DWORD *)(v5 + 4 * v7) = 3;
  *(_QWORD *)(v5 + 8 * v7 + 16) = "hkpBoxShape";
  *(_QWORD *)(v5 + 8 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v5 + 81);
  if ( v6 > v8 )
    v8 = v6;
  *(_BYTE *)(v5 + 81) = v8;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpBoxShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 64i64);
  if ( v10 )
  {
    hkpBoxShape::hkpBoxShape(v10, &halfExtentsa, 0.0);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = *(_BYTE *)(v5 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  return UFG::PhantomCallback::CreatePhantom(v12, v4, v3);
}

// File Line: 133
// RVA: 0xA5820
hkpEntity *__fastcall UFG::PhantomCallback::CreatePhantom(hkpShape *phantomShape, UFG::qMatrix44 *transform, unsigned int volumePropertyKey)
{
  unsigned int v3; // ebx
  hkpShape *v4; // rbp
  UFG::PhysicsVolumeProperties *v5; // rsi
  signed __int64 v6; // rbx
  char v7; // dl
  __int64 v8; // rcx
  char v9; // cl
  _QWORD **v10; // rax
  __int64 v11; // rdi
  char v12; // al
  char v13; // dl
  __int64 v14; // rax
  char v15; // cl
  _QWORD **v16; // rax
  hkpBvShape *v17; // rax
  hkpShape *v18; // rax
  hkpShape *v19; // rsi
  char v20; // al
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  _QWORD **v24; // rax
  hkpRigidBody *v25; // rax
  hkpEntity *v26; // rax
  hkpEntity *v27; // rdi
  char v28; // al
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v29; // rbx
  hkQsTransformf v31; // [rsp+30h] [rbp-168h]
  hkTransformf transforma; // [rsp+60h] [rbp-138h]
  hkpRigidBodyCinfo info; // [rsp+A0h] [rbp-F8h]

  v3 = volumePropertyKey;
  v4 = phantomShape;
  hkTransformf::set4x4ColumnMajor(&transforma, &transform->v0.x);
  hkQsTransformf::setFromTransformNoScale(&v31, &transforma);
  v5 = UFG::PhysicsVolumePropertyManager::Find(v3, 1);
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  v8 = v7;
  *(_DWORD *)(v6 + 4 * v8) = 3;
  *(_QWORD *)(v6 + 8 * v8 + 16) = "PhantomCallbackShape";
  *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
  v9 = *(_BYTE *)(v6 + 81);
  if ( v7 > v9 )
    v9 = v7;
  *(_BYTE *)(v6 + 81) = v9;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 40i64);
  if ( v11 )
  {
    *(_QWORD *)v11 = &hkBaseObject::`vftable';
    *(_QWORD *)v11 = &hkReferencedObject::`vftable';
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v11 = &hkcdShape::`vftable';
    *(_DWORD *)(v11 + 16) = 1056;
    *(_QWORD *)v11 = &hkpShapeBase::`vftable';
    *(_QWORD *)v11 = &hkpShape::`vftable';
    *(_QWORD *)(v11 + 24) = 0i64;
    *(_QWORD *)v11 = &hkpPhantomCallbackShape::`vftable';
    *(_QWORD *)v11 = &UFG::PhantomCallbackShape::`vftable';
    *(_QWORD *)(v11 + 32) = v5;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *(_BYTE *)(v6 + 80);
  if ( v12 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v12 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v13 = ++*(_BYTE *)(v6 + 80);
  v14 = v13;
  *(_DWORD *)(v6 + 4 * v14) = 3;
  *(_QWORD *)(v6 + 8 * v14 + 16) = "hkpBvShape";
  *(_QWORD *)(v6 + 8 * v14 + 48) = 0i64;
  v15 = *(_BYTE *)(v6 + 81);
  if ( v13 > v15 )
    v15 = v13;
  *(_BYTE *)(v6 + 81) = v15;
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpBvShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 56i64);
  if ( v17 )
  {
    hkpBvShape::hkpBvShape(v17, v4, (hkpShape *)v11);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v20 = *(_BYTE *)(v6 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)v11);
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  info.m_motionType.m_storage = 5;
  info.m_position = v31.m_translation;
  info.m_rotation = v31.m_rotation;
  info.m_collisionFilterInfo = 19;
  info.m_shape = v19;
  v21 = ++*(_BYTE *)(v6 + 80);
  v22 = v21;
  *(_DWORD *)(v6 + 4 * v22) = 0;
  *(_QWORD *)(v6 + 8 * v22 + 16) = "hkpRigidBody";
  *(_QWORD *)(v6 + 8 * v22 + 48) = 0i64;
  v23 = *(_BYTE *)(v6 + 81);
  if ( v21 > v23 )
    v23 = v21;
  *(_BYTE *)(v6 + 81) = v23;
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 720i64);
  if ( v25 )
  {
    hkpRigidBody::hkpRigidBody(v25, &info);
    v27 = v26;
  }
  else
  {
    v27 = 0i64;
  }
  v28 = *(_BYTE *)(v6 + 80);
  if ( v28 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v28 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v19->vfptr);
  v29 = &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd;
  if ( UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size == (UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd,
      8);
  v29->m_data[v29->m_size++] = v27;
  return v27;
}

// File Line: 182
// RVA: 0xA6F50
void __fastcall UFG::PhantomCallback::DestroyPhantom(hkpRigidBody *phantomRigidBody)
{
  UFG::BasePhysicsSystem *v1; // rdi
  int v2; // er8
  hkpRigidBody *v3; // rbx
  __int64 v4; // rcx
  __int64 v5; // rdx
  hkpEntity **v6; // rax
  __int64 v7; // rax
  hkpWorld *v8; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v9; // rdi
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = UFG::BasePhysicsSystem::mInstance;
  v2 = 0;
  v3 = phantomRigidBody;
  v4 = UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size;
  v5 = 0i64;
  if ( v4 > 0 )
  {
    v6 = UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_data;
    while ( *v6 != (hkpEntity *)v3 )
    {
      ++v5;
      ++v2;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_8;
    }
    --UFG::BasePhysicsSystem::mInstance->mEntitiesToAdd.m_size;
    v7 = v1->mEntitiesToAdd.m_size;
    if ( (_DWORD)v7 != v2 )
      v1->mEntitiesToAdd.m_data[v2] = v1->mEntitiesToAdd.m_data[v7];
  }
LABEL_8:
  v8 = v3->m_world;
  if ( v8 )
  {
    if ( !v1->mForceRemoveEntitiesToBeBatched )
    {
      hkpWorld::removeEntity(v8, &result, (hkpEntity *)&v3->vfptr);
      hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
      return;
    }
    v9 = &v1->mEntitiesToRemove;
    if ( v9->m_size == (v9->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, 8);
    v9->m_data[v9->m_size++] = (hkpEntity *)&v3->vfptr;
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 193
// RVA: 0xB48C0
void __fastcall UFG::PhantomCallback::Update(UFG::PhantomCallback *this, float delta_sec)
{
  UFG::BasePhysicsSystem *v2; // r15
  UFG::PhantomCallback *v3; // r14
  UFG::QueueNode<UFG::PhantomCallbackData> *v4; // rsi
  bool v5; // bl
  hkReferencedObject **v6; // rdi
  bool v7; // bl
  UFG::QueueNode<UFG::PhantomCallbackData> *v8; // rcx
  UFG::QueueNode<UFG::PhantomCallbackData> *v9; // rax
  __int64 v10; // r8
  UFG::SimObject *v11; // r8
  bool v12; // bl

  v2 = UFG::BasePhysicsSystem::mInstance;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPhantomCallbackQueue.mutex);
  v4 = &v3->mPhantomCallbackQueue.tail;
  v5 = v3->mPhantomCallbackQueue.head.next == &v3->mPhantomCallbackQueue.tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
  if ( !v5 )
  {
    do
    {
      v6 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
      v7 = v3->mPhantomCallbackQueue.head.next == v4;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
      if ( !v7 )
      {
        v8 = v4->prev;
        v9 = v4->prev->prev;
        v9->next = v4;
        v4->prev = v9;
        v6 = (hkReferencedObject **)v8->data;
        operator delete[](v8);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
      v10 = *(_QWORD *)&v6[2][1].m_memSizeAndFlags;
      if ( v10 )
      {
        v11 = *(UFG::SimObject **)(v10 + 24);
        if ( v11 )
          v11 = (UFG::SimObject *)v11->mNode.mParent;
        if ( v11 )
          v2->vfptr->PhysicsVolumeHandler(v2, v3, v11, (UFG::PhantomCallbackData *)v6);
      }
      hkReferencedObject::removeReference(v6[2]);
      hkReferencedObject::removeReference(v6[1]);
      operator delete[](v6);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
      v12 = v3->mPhantomCallbackQueue.head.next == v4;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPhantomCallbackQueue.mutex);
    }
    while ( !v12 );
  }
}

