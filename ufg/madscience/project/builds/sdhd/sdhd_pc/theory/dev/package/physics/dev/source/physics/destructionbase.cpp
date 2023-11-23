// File Line: 38
// RVA: 0x1459000
__int64 UFG::_dynamic_initializer_for__gDestructionEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gDestructionEventChannel,
    "DestructionBaseEvent",
    "This is an event that gets generated when physics Destruction happens.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gDestructionEventChannel__);
}

// File Line: 75
// RVA: 0xAC950
void __fastcall UFG::Destruction::Initialize(hkpWorld *world)
{
  _QWORD **Value; // rax
  UFG::Destruction *v3; // rax

  if ( !UFG::Destruction::mInstance )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (UFG::Destruction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 488i64);
    if ( v3 )
      UFG::Destruction::Destruction(v3, world);
    UFG::Destruction::mInstance = v3;
  }
}

// File Line: 96
// RVA: 0x987E0
void __fastcall UFG::Destruction::Destruction(UFG::Destruction *this, hkpWorld *world)
{
  __int64 v4; // rbx
  char v5; // dl
  char v6; // cl
  _QWORD **Value; // rax
  hkpBreakOffPartsUtil *v8; // rax
  hkpBreakOffPartsUtil *v9; // rax
  char v10; // al
  UFG::ThreadSafeQueue<UFG::BreakoffPart> *p_mBreakOffPartsQueue; // [rsp+70h] [rbp+18h]

  this->hkpBreakOffPartsListener::vfptr = (hkpBreakOffPartsListenerVtbl *)&hkpBreakOffPartsListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkpBreakOffPartsListener::vfptr = (hkpBreakOffPartsListenerVtbl *)&UFG::Destruction::`vftable{for `hkpBreakOffPartsListener};
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::Destruction::`vftable{for `hkReferencedObject};
  p_mBreakOffPartsQueue = &this->mBreakOffPartsQueue;
  UFG::qMutex::qMutex(&this->mBreakOffPartsQueue.mutex, &customCaption);
  this->mBreakOffPartsQueue.head.next = &this->mBreakOffPartsQueue.tail;
  p_mBreakOffPartsQueue->head.prev = 0i64;
  this->mBreakOffPartsQueue.tail.prev = &this->mBreakOffPartsQueue.head;
  this->mBreakOffPartsQueue.tail.next = 0i64;
  `eh vector constructor iterator(
    this->mObjects,
    0x18ui64,
    15,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v5) = 3;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "hkpBreakOffPartsUtil";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v4 + 81);
  if ( v5 > v6 )
    v6 = v5;
  *(_BYTE *)(v4 + 81) = v6;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpBreakOffPartsUtil *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v8 )
    hkpBreakOffPartsUtil::hkpBreakOffPartsUtil(v8, this);
  else
    v9 = 0i64;
  this->mBreakOffPartsUtil = v9;
  v10 = *(_BYTE *)(v4 + 80);
  if ( v10 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v10 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  hkpWorld::addWorldExtension(world, this->mBreakOffPartsUtil);
}

// File Line: 108
// RVA: 0x9C1B0
void __fastcall UFG::Destruction::~Destruction(UFG::Destruction *this)
{
  hkReferencedObject *v2; // rdi
  hkpBreakOffPartsUtil *mBreakOffPartsUtil; // rdx
  hkpWorld *m_world; // rcx

  this->hkpBreakOffPartsListener::vfptr = (hkpBreakOffPartsListenerVtbl *)&UFG::Destruction::`vftable{for `hkpBreakOffPartsListener};
  v2 = &this->hkReferencedObject;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::Destruction::`vftable{for `hkReferencedObject};
  mBreakOffPartsUtil = this->mBreakOffPartsUtil;
  m_world = mBreakOffPartsUtil->m_world;
  if ( m_world )
    hkpWorld::removeWorldExtension(m_world, mBreakOffPartsUtil);
  hkReferencedObject::removeReference(this->mBreakOffPartsUtil);
  `eh vector destructor iterator(
    this->mObjects,
    0x18ui64,
    15,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
  UFG::ThreadSafeQueue<UFG::BreakoffPart>::~ThreadSafeQueue<UFG::BreakoffPart>(&this->mBreakOffPartsQueue);
  v2->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->hkpBreakOffPartsListener::vfptr = (hkpBreakOffPartsListenerVtbl *)&hkpBreakOffPartsListener::`vftable;
}

// File Line: 125
// RVA: 0xB46E0
void __fastcall UFG::Destruction::Update(UFG::Destruction *this)
{
  UFG::BasePhysicsSystem *v2; // r14
  __int64 v3; // rbp
  UFG::SimComponent **p_m_pPointer; // rbx
  UFG::ActiveRegionManager *p_mActiveRegionManager; // rdi
  __int64 v6; // rsi
  UFG::SimComponent *v7; // rdx
  UFG::SimObject *m_pSimObject; // rax
  __m128 *p_mNext; // rax
  __m128 v10; // xmm2
  __m128 *mNext; // rax
  __int64 v12; // rcx
  _QWORD *v13; // rax
  unsigned int v14; // r9d
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *mObjects; // rdx
  unsigned int v16; // ecx
  UFG::SimComponent **v17; // r8
  __int64 v18; // r10
  UFG::SimComponent *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v23; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax

  UFG::Destruction::FixupBreakOffParts(this);
  v2 = UFG::BasePhysicsSystem::mInstance;
  v3 = 15i64;
  p_m_pPointer = &this->mObjects[0].m_pPointer;
  p_mActiveRegionManager = &UFG::BasePhysicsSystem::mInstance->mActiveRegionManager;
  v6 = 15i64;
  do
  {
    v7 = *p_m_pPointer;
    if ( *p_m_pPointer )
    {
      m_pSimObject = v7[2].m_pSimObject;
      if ( m_pSimObject )
        p_mNext = (__m128 *)&m_pSimObject[3].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
      else
        p_mNext = (__m128 *)(*(_QWORD *)&v7[2].m_TypeUID + 32i64);
      v10 = *p_mNext;
      mNext = (__m128 *)p_mActiveRegionManager->mRegions.mNode.mNext;
      if ( mNext == (__m128 *)p_mActiveRegionManager )
      {
LABEL_9:
        v2->vfptr->OnCollisionInstanceRemovedFromWorld(v2, *(UFG::CollisionInstanceData **)&v7[2].m_TypeUID);
        if ( *p_m_pPointer )
        {
          v12 = (__int64)*(p_m_pPointer - 2);
          v13 = *(p_m_pPointer - 1);
          *(_QWORD *)(v12 + 8) = v13;
          *v13 = v12;
          *(p_m_pPointer - 2) = (UFG::SimComponent *)(p_m_pPointer - 2);
          *(p_m_pPointer - 1) = (UFG::SimComponent *)(p_m_pPointer - 2);
        }
        *p_m_pPointer = 0i64;
      }
      else
      {
        while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v10, mNext[3]), _mm_cmple_ps(mNext[2], v10))) & 7) != 7 )
        {
          mNext = (__m128 *)mNext->m128_u64[1];
          if ( mNext == (__m128 *)p_mActiveRegionManager )
            goto LABEL_9;
        }
      }
    }
    p_m_pPointer += 3;
    --v6;
  }
  while ( v6 );
  v14 = 1;
  mObjects = this->mObjects;
  do
  {
    if ( !mObjects->m_pPointer )
    {
      v16 = v14;
      if ( v14 < 0xF )
      {
        v17 = &this->mObjects[0].m_pPointer + 2 * v14 + v14;
        while ( !*v17 )
        {
          ++v16;
          v17 += 3;
          if ( v16 >= 0xF )
            goto LABEL_27;
        }
        v18 = v16;
        m_pPointer = this->mObjects[v16].m_pPointer;
        if ( mObjects->m_pPointer )
        {
          mPrev = mObjects->mPrev;
          v21 = mObjects->mNext;
          mPrev->mNext = v21;
          v21->mPrev = mPrev;
          mObjects->mPrev = mObjects;
          mObjects->mNext = mObjects;
        }
        mObjects->m_pPointer = m_pPointer;
        if ( m_pPointer )
        {
          v22 = m_pPointer->m_SafePointerList.mNode.mPrev;
          v22->mNext = mObjects;
          mObjects->mPrev = v22;
          mObjects->mNext = &m_pPointer->m_SafePointerList.mNode;
          m_pPointer->m_SafePointerList.mNode.mPrev = mObjects;
        }
        v23 = &this->mObjects[v18];
        if ( v23->m_pPointer )
        {
          v24 = v23->mPrev;
          v25 = v23->mNext;
          v24->mNext = v25;
          v25->mPrev = v24;
          v23->mPrev = v23;
          v23->mNext = v23;
        }
        v23->m_pPointer = 0i64;
      }
    }
LABEL_27:
    ++v14;
    ++mObjects;
    --v3;
  }
  while ( v3 );
}

// File Line: 176
// RVA: 0xA8410
void __fastcall UFG::Destruction::FixupBreakOffParts(UFG::Destruction *this)
{
  bool v2; // bl
  UFG::BreakoffPart *v3; // rax
  UFG::BreakoffPart *v4; // rbx
  unsigned __int64 m_userData; // rdi
  __int64 v6; // rdi
  __int64 v7; // rsi
  hkpRemoveTerminalsMoppModifier *mRemoveTerminalsMoppModifier; // rdx
  __int64 shapeKey; // r9
  __int64 v10; // r8
  __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // rcx
  unsigned int v15; // esi
  UFG::RigidBody *v16; // rbp
  unsigned __int64 v17; // rdx
  UFG::SimComponent *v18; // rdi
  char *v19; // rax
  __int64 v20; // rax
  UFG::SimComponent **p_m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *mObjects; // rax
  UFG::SimComponent **v23; // r9
  __int64 v24; // r10
  UFG::SimComponent *v25; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  hkpEntity *newRigidBody; // r8
  hkpWorld *m_world; // rcx
  hkReferencedObject *v35; // rcx
  bool v36; // bl
  hkBool result; // [rsp+80h] [rbp+8h] BYREF
  char *v38; // [rsp+88h] [rbp+10h]

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
  v2 = this->mBreakOffPartsQueue.head.next == &this->mBreakOffPartsQueue.tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
  if ( !v2 )
  {
    do
    {
      v3 = UFG::ThreadSafeQueue<UFG::BreakoffPart>::RemoveTail(&this->mBreakOffPartsQueue);
      v4 = v3;
      m_userData = v3->breakingRigidBody->m_userData;
      if ( m_userData )
      {
        v6 = *(_QWORD *)(m_userData + 24);
        v7 = *(_QWORD *)(v6 + 160);
        mRemoveTerminalsMoppModifier = v3->mRemoveTerminalsMoppModifier;
        if ( v7 && mRemoveTerminalsMoppModifier )
        {
          UFG::CollisionMeshData::AddMoppTerminalModifier(
            *(UFG::CollisionMeshData **)(v6 + 160),
            mRemoveTerminalsMoppModifier);
          hkReferencedObject::removeReference(v4->mRemoveTerminalsMoppModifier);
          v4->mRemoveTerminalsMoppModifier = 0i64;
        }
        shapeKey = v4->shapeKey;
        v10 = *(_QWORD *)(v6 + 240);
        if ( !v10 || (*(_DWORD *)(v10 + 4i64 * ((unsigned int)shapeKey >> 5)) & (1 << (shapeKey & 0x1F))) == 0 )
        {
          v11 = *(_QWORD *)(v7 + 160);
          if ( v11 )
            v12 = v7 + v11 + 160;
          else
            v12 = 0i64;
          v13 = v12 + 96i64 * (int)shapeKey;
          v14 = *(_QWORD *)(v6 + 152);
          if ( (unsigned int)shapeKey >= *(_DWORD *)(v14 + 76)
            || (v15 = *(_DWORD *)(32 * shapeKey + *(_QWORD *)(v14 + 80) + 28)) == 0 )
          {
            v15 = *(_DWORD *)(v14 + 92);
          }
          v16 = (UFG::RigidBody *)(*(__int64 (__fastcall **)(__int64, UFG::BreakoffPart *, __int64, _QWORD))(*(_QWORD *)v6 + 112i64))(
                                    v6,
                                    v4,
                                    v13,
                                    v15);
          if ( v16 )
          {
            if ( v4->collidingRigidBody && (v17 = v4->collidingRigidBody->m_userData) != 0 )
              v18 = *(UFG::SimComponent **)(v17 + 24);
            else
              v18 = 0i64;
            v19 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x98ui64, "DestructionEvent", 0i64, 1u);
            v38 = v19;
            if ( v19 )
              UFG::DestructionEvent::DestructionEvent((UFG::DestructionEvent *)v19, v18, v16, v15);
            v20 = 0i64;
            p_m_pPointer = &this->mObjects[0].m_pPointer;
            do
            {
              if ( !*p_m_pPointer )
              {
                v29 = &this->mObjects[v20];
                goto LABEL_32;
              }
              v20 = (unsigned int)(v20 + 1);
              p_m_pPointer += 3;
            }
            while ( (unsigned int)v20 < 0xF );
            UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceRemovedFromWorld(
              UFG::BasePhysicsSystem::mInstance,
              *(UFG::CollisionInstanceData **)&this->mObjects[0].m_pPointer[2].m_TypeUID);
            mObjects = this->mObjects;
            v23 = &this->mObjects[1].m_pPointer;
            v24 = 14i64;
            do
            {
              v25 = *v23;
              if ( mObjects->m_pPointer )
              {
                mPrev = mObjects->mPrev;
                mNext = mObjects->mNext;
                mPrev->mNext = mNext;
                mNext->mPrev = mPrev;
                mObjects->mPrev = mObjects;
                mObjects->mNext = mObjects;
              }
              mObjects->m_pPointer = v25;
              if ( v25 )
              {
                v28 = v25->m_SafePointerList.mNode.mPrev;
                v28->mNext = mObjects;
                mObjects->mPrev = v28;
                mObjects->mNext = &v25->m_SafePointerList.mNode;
                v25->m_SafePointerList.mNode.mPrev = mObjects;
              }
              v23 += 3;
              ++mObjects;
              --v24;
            }
            while ( v24 );
            v29 = &this->mObjects[14];
LABEL_32:
            if ( v29->m_pPointer )
            {
              v30 = v29->mPrev;
              v31 = v29->mNext;
              v30->mNext = v31;
              v31->mPrev = v30;
              v29->mPrev = v29;
              v29->mNext = v29;
            }
            v29->m_pPointer = v16;
            v32 = v16->m_SafePointerList.mNode.mPrev;
            v32->mNext = v29;
            v29->mPrev = v32;
            v29->mNext = &v16->m_SafePointerList.mNode;
            v16->m_SafePointerList.mNode.mPrev = v29;
          }
        }
      }
      newRigidBody = v4->newRigidBody;
      if ( newRigidBody )
      {
        m_world = newRigidBody->m_world;
        if ( m_world )
          hkpWorld::removeEntity(m_world, &result, newRigidBody);
      }
      hkReferencedObject::removeReference(v4->breakingRigidBody);
      if ( v4->collidingRigidBody )
        hkReferencedObject::removeReference(v4->collidingRigidBody);
      v35 = v4->mRemoveTerminalsMoppModifier;
      if ( v35 )
        hkReferencedObject::removeReference(v35);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v4);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
      v36 = this->mBreakOffPartsQueue.head.next == &this->mBreakOffPartsQueue.tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
    }
    while ( !v36 );
  }
}

// File Line: 286
// RVA: 0xB00A0
void __fastcall UFG::Destruction::ResetScene(UFG::Destruction *this)
{
  UFG::SimComponent **p_m_pPointer; // rbx
  __int64 v3; // rdi
  UFG::QueueNode<UFG::BreakoffPart> *p_tail; // rsi
  bool v5; // bl
  UFG::BreakoffPart *data; // rdi
  bool v7; // bl
  UFG::QueueNode<UFG::BreakoffPart> *prev; // rcx
  UFG::QueueNode<UFG::BreakoffPart> *v9; // rax
  hkpEntity *newRigidBody; // r8
  hkpWorld *m_world; // rcx
  hkReferencedObject *mRemoveTerminalsMoppModifier; // rcx
  bool v13; // bl
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  p_m_pPointer = &this->mObjects[0].m_pPointer;
  v3 = 15i64;
  do
  {
    if ( *p_m_pPointer )
      UFG::Simulation::DestroySimObject(&UFG::gSim, (*p_m_pPointer)->m_pSimObject);
    p_m_pPointer += 3;
    --v3;
  }
  while ( v3 );
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
  p_tail = &this->mBreakOffPartsQueue.tail;
  v5 = this->mBreakOffPartsQueue.head.next == &this->mBreakOffPartsQueue.tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
  if ( !v5 )
  {
    do
    {
      data = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
      v7 = this->mBreakOffPartsQueue.head.next == p_tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
      if ( !v7 )
      {
        prev = p_tail->prev;
        v9 = p_tail->prev->prev;
        v9->next = p_tail;
        p_tail->prev = v9;
        data = prev->data;
        operator delete[](prev);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
      newRigidBody = data->newRigidBody;
      if ( newRigidBody )
      {
        m_world = newRigidBody->m_world;
        if ( m_world )
          hkpWorld::removeEntity(m_world, &result, newRigidBody);
      }
      hkReferencedObject::removeReference(data->breakingRigidBody);
      if ( data->collidingRigidBody )
        hkReferencedObject::removeReference(data->collidingRigidBody);
      mRemoveTerminalsMoppModifier = data->mRemoveTerminalsMoppModifier;
      if ( mRemoveTerminalsMoppModifier )
        hkReferencedObject::removeReference(mRemoveTerminalsMoppModifier);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, data);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
      v13 = this->mBreakOffPartsQueue.head.next == p_tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
    }
    while ( !v13 );
  }
}

// File Line: 354
// RVA: 0xACD00
bool __fastcall UFG::Destruction::IsPartMarkedAsBreakable(
        UFG::Destruction *this,
        hkpEntity *entity,
        unsigned int shapeKey)
{
  char v3; // cl

  v3 = 0;
  if ( ((unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v3 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(((unsigned __int64)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64)
                                                                                             + 48),
           shapeKey,
           0i64);
  return v3 != 0;
}

// File Line: 372
// RVA: 0xB89E0
hkpRemoveTerminalsMoppModifier *__fastcall UFG::Destruction::removeKeysFromListShape(
        hkpEntity *entity,
        unsigned int *keysToRemove,
        unsigned int numKeys)
{
  hkpRemoveTerminalsMoppModifier *v5; // r12
  hkAabbUint32 *m_childShapeAabbs; // r13
  hkpShape *m_shape; // rsi
  __int64 v8; // rdi
  unsigned __int64 m_userData; // rbx
  _QWORD **Value; // rax
  hkpRemoveTerminalsMoppModifier *v12; // rax
  hkpShapeContainer *v13; // r8
  hkpRemoveTerminalsMoppModifier *v14; // rax
  __int64 i; // rbx
  __int64 j; // rbx
  unsigned int *m_childShapeKeys; // r14
  __int64 v18; // rdi
  __int64 m_numChildShapeAabbs; // rsi
  unsigned int *v20; // rbx
  AMD_HD3D shapesToRemove[2]; // [rsp+28h] [rbp-18h] BYREF

  v5 = 0i64;
  m_childShapeAabbs = entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
  m_shape = entity->m_collidable.m_shape;
  v8 = (int)numKeys;
  if ( m_shape->m_type.m_storage != 8 )
  {
    if ( m_shape->m_type.m_storage != 9 )
      return 0i64;
    m_userData = m_shape[2].m_userData;
    *(_QWORD *)&shapesToRemove[0].mEnableStereo = keysToRemove;
    shapesToRemove[0].mWidth = numKeys;
    shapesToRemove[0].mHeight = numKeys | 0x80000000;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkpRemoveTerminalsMoppModifier *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                              Value[11],
                                              48i64);
    if ( v12 )
    {
      if ( m_userData )
        v13 = (hkpShapeContainer *)(m_userData + 32);
      else
        v13 = 0i64;
      hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
        v12,
        *(hkpMoppCode **)&m_shape[1].m_memSizeAndFlags,
        v13,
        (hkArray<unsigned int,hkContainerHeapAllocator> *)shapesToRemove);
      v5 = v14;
    }
    else
    {
      v5 = 0i64;
    }
    hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(v5, *(hkpMoppCode **)&m_shape[1].m_memSizeAndFlags);
    if ( *(_BYTE *)(m_userData + 16) != 8 )
    {
      shapesToRemove[0].mWidth = 0;
      if ( (shapesToRemove[0].mHeight & 0x80000000) == 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)&shapesToRemove[0].mEnableStereo,
          4 * shapesToRemove[0].mHeight);
      *(_QWORD *)&shapesToRemove[0].mEnableStereo = 0i64;
      shapesToRemove[0].mHeight = 0x80000000;
      goto LABEL_19;
    }
    m_shape = (hkpShape *)m_userData;
    shapesToRemove[0].mWidth = 0;
    if ( (shapesToRemove[0].mHeight & 0x80000000) == 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&shapesToRemove[0].mEnableStereo,
        4 * shapesToRemove[0].mHeight);
    *(_QWORD *)&shapesToRemove[0].mEnableStereo = 0i64;
    shapesToRemove[0].mHeight = 0x80000000;
  }
  for ( i = 0i64; i < v8; ++i )
    hkpListShape::disableChild((hkpListShape *)m_shape, keysToRemove[i]);
LABEL_19:
  if ( m_childShapeAabbs )
  {
    *(_QWORD *)&shapesToRemove[0].mEnableStereo = 0i64;
    shapesToRemove[0].mWidth = 0;
    shapesToRemove[0].mHeight = -1;
    for ( j = 0i64; j < v8; ++j )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)shapesToRemove,
        &hkContainerHeapAllocator::s_alloc,
        keysToRemove[j],
        1ui64);
    m_childShapeKeys = entity->m_collidable.m_boundingVolumeData.m_childShapeKeys;
    v18 = 0i64;
    m_numChildShapeAabbs = entity->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs;
    if ( entity->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs )
    {
      v20 = &m_childShapeAabbs->m_max[2];
      do
      {
        if ( (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)shapesToRemove,
                             m_childShapeKeys[v18],
                             0i64) )
        {
          *(v20 - 5) = 2147418112;
          *((_QWORD *)v20 - 2) = 2147418112i64;
          *(_QWORD *)(v20 - 1) = 0i64;
        }
        ++v18;
        v20 += 8;
      }
      while ( v18 < m_numChildShapeAabbs );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)shapesToRemove,
      &hkContainerHeapAllocator::s_alloc);
    _(shapesToRemove);
  }
  return v5;
}

// File Line: 442
// RVA: 0xB6920
void __fastcall UFG::Destruction::breakOffSubPart(
        UFG::Destruction *this,
        hkpRigidBody *collidingBody,
        hkpRigidBody *breakingBody,
        unsigned int brokenPieceKey)
{
  UFG::BreakoffPart *v7; // rbx
  unsigned int v8; // eax
  hkpShape *v9; // r14
  hkpShape *m_shape; // rsi
  char m_storage; // cl
  hkpRigidBody *v12; // rsi
  __int64 v13; // r14
  char v14; // dl
  char v15; // cl
  _QWORD **Value; // rax
  hkpRigidBody *v17; // rax
  hkpRigidBody *v18; // rax
  char v19; // al
  hkReferencedObject *mRemoveTerminalsMoppModifier; // rcx
  __m128 v21; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v22; // [rsp+40h] [rbp-98h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+50h] [rbp-88h] BYREF
  void *v24; // [rsp+138h] [rbp+60h]
  unsigned int keysToRemove; // [rsp+150h] [rbp+78h] BYREF
  __m128 *v26; // [rsp+160h] [rbp+88h]
  __int64 v27; // [rsp+168h] [rbp+90h]
  _DWORD *array; // [rsp+170h] [rbp+98h]
  hkpPhysicsSystem *v29; // [rsp+178h] [rbp+A0h]

  LODWORD(v29) = brokenPieceKey;
  v22 = -2i64;
  v7 = (UFG::BreakoffPart *)UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x28ui64, "BreakoffPart", 0i64, 1u);
  v24 = v7;
  if ( v7 )
  {
    v8 = keysToRemove;
    v7->collidingRigidBody = collidingBody;
    v7->breakingRigidBody = breakingBody;
    v7->shapeKey = v8;
    v7->mRemoveTerminalsMoppModifier = 0i64;
    hkReferencedObject::addReference(breakingBody);
    if ( v7->collidingRigidBody )
      hkReferencedObject::addReference(v7->collidingRigidBody);
  }
  else
  {
    v7 = 0i64;
  }
  if ( !UFG::ThreadSafeQueue<UFG::BreakoffPart>::IsAlreadyInQueue(&this->mBreakOffPartsQueue, v7) )
  {
    v9 = 0i64;
    m_shape = breakingBody->m_collidable.m_shape;
    m_storage = m_shape->m_type.m_storage;
    if ( m_storage == 8 )
    {
      if ( ((int (__fastcall *)(hkpShape *))m_shape[1].vfptr->__first_virtual_table_function__)(&m_shape[1]) > 1 )
      {
        v9 = *(hkpShape **)(32i64 * (int)keysToRemove + *(_QWORD *)&m_shape[1].m_type.m_storage);
        UFG::Destruction::removeKeysFromListShape(breakingBody, &keysToRemove, 1);
LABEL_11:
        if ( array[2] == (array[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, array, 4);
        *(_DWORD *)(*(_QWORD *)array + 4i64 * (int)array[2]++) = keysToRemove;
      }
    }
    else if ( m_storage == 9 )
    {
      v9 = *(hkpShape **)(32i64 * (int)keysToRemove + *(_QWORD *)(m_shape[2].m_userData + 48));
      v7->mRemoveTerminalsMoppModifier = UFG::Destruction::removeKeysFromListShape(breakingBody, &keysToRemove, 1);
      goto LABEL_11;
    }
    v12 = 0i64;
    if ( v9 )
    {
      hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
      bodyInfo.m_shape = v9;
      bodyInfo.m_position = breakingBody->m_motion.m_motionState.m_transform.m_translation;
      bodyInfo.m_rotation = breakingBody->m_motion.m_motionState.m_sweptTransform.m_rotation1;
      *(hkVector4f *)&bodyInfo.m_shape = breakingBody->m_motion.m_linearVelocity;
      *(hkVector4f *)((char *)&bodyInfo.m_position + 8) = breakingBody->m_motion.m_angularVelocity;
      bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_i32[2] = 1092616192;
      LOBYTE(bodyInfo.m_rollingFrictionMultiplier) = 2;
      bodyInfo.m_collisionFilterInfo = 20;
      HIBYTE(bodyInfo.m_rollingFrictionMultiplier) = -1;
      hkpInertiaTensorComputer::setShapeVolumeMassProperties(v9, 10.0, &bodyInfo);
      hkReferencedObject::lockAll();
      v13 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v14 = ++*(_BYTE *)(v13 + 80);
      *(_DWORD *)(v13 + 4i64 * v14) = 0;
      *(_QWORD *)(v13 + 8i64 * v14 + 16) = "hkpRigidBody";
      *(_QWORD *)(v13 + 8i64 * v14 + 48) = 0i64;
      v15 = *(_BYTE *)(v13 + 81);
      if ( v14 > v15 )
        v15 = v14;
      *(_BYTE *)(v13 + 81) = v15;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v17 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 720i64);
      v24 = v17;
      if ( v17 )
      {
        hkpRigidBody::hkpRigidBody(v17, &bodyInfo);
        v12 = v18;
      }
      else
      {
        v12 = 0i64;
      }
      v19 = *(_BYTE *)(v13 + 80);
      if ( v19 > 0 )
      {
        *(_BYTE *)(v13 + 80) = v19 - 1;
      }
      else
      {
        *(_BYTE *)(v13 + 80) = 0;
        *(_DWORD *)v13 = 3;
        *(_QWORD *)(v13 + 16) = 0i64;
        *(_QWORD *)(v13 + 48) = 0i64;
      }
      hkpPhysicsSystem::addRigidBody(v29, v12);
      hkReferencedObject::removeReference(v12);
      hkReferencedObject::unlockAll();
      if ( (unsigned __int8)(breakingBody->m_motion.m_type.m_storage - 4) <= 1u )
      {
        v21 = _mm_mul_ps((__m128)_xmm_c1200000c1200000c1200000c1200000, *v26);
        hkpEntity::activate(v12);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __int64))v12->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
          &v12->m_motion,
          &v21,
          v27);
      }
    }
    v7->newRigidBody = v12;
    UFG::ThreadSafeQueue<hkpEntity>::AddHead(
      (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&this->mBreakOffPartsQueue,
      (UFG::CollisionEvent *)v7);
    return;
  }
  if ( v7 )
  {
    hkReferencedObject::removeReference(v7->breakingRigidBody);
    if ( v7->collidingRigidBody )
      hkReferencedObject::removeReference(v7->collidingRigidBody);
    mRemoveTerminalsMoppModifier = v7->mRemoveTerminalsMoppModifier;
    if ( mRemoveTerminalsMoppModifier )
      hkReferencedObject::removeReference(mRemoveTerminalsMoppModifier);
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v7);
  }
}

// File Line: 534
// RVA: 0xB6800
hkResult *__fastcall UFG::Destruction::breakOffSubPart(
        UFG::Destruction *this,
        hkResult *result,
        hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent *event,
        hkArray<unsigned int,hkContainerHeapAllocator> *keysBrokenOffOut,
        hkpPhysicsSystem *bodiesOut)
{
  __int64 m_size; // rbp
  __int64 v8; // rbx
  hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent::PointInfo *m_data; // rdi
  hkVector4f *position; // r14
  unsigned __int16 EncodedFloat; // ax
  float maxImpulse; // xmm0_4
  hkpRigidBody *breakingBody; // [rsp+50h] [rbp-48h]

  m_size = event->m_points.m_size;
  breakingBody = event->m_breakingBody;
  if ( m_size <= 0 )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    v8 = 0i64;
    do
    {
      m_data = event->m_points.m_data;
      position = &m_data[v8].m_contactPoint->m_position;
      EncodedFloat = hkUFloat8::getEncodedFloat(m_data[v8].m_properties->m_maxImpulse.m_value);
      if ( EncodedFloat )
        LODWORD(maxImpulse) = (EncodedFloat + 243712) << 12;
      else
        maxImpulse = 0.0;
      UFG::Destruction::breakOffSubPart(
        this,
        m_data[v8].m_collidingBody,
        breakingBody,
        m_data[v8].m_brokenShapeKey,
        maxImpulse,
        position + 1,
        position,
        keysBrokenOffOut,
        bodiesOut);
      ++v8;
      --m_size;
    }
    while ( m_size );
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 551
// RVA: 0xA87E0
void __fastcall UFG::Destruction::ForceFracture(
        UFG::Destruction *this,
        UFG::RigidBody *rbc,
        hkpPhysicsSystem *bodiesOut,
        int partIndex)
{
  UFG::CollisionMeshData *mCollisionMeshData; // r12
  __int64 mOffset; // rax
  hkpRigidBody *v6; // rdi
  hkpRigidBody *mBody; // r13
  hkpShape *m_shape; // rsi
  int v9; // r14d
  int v10; // r15d
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 v13; // rax
  char *v14; // rcx
  BitArray256 *mFractureState; // rdx
  hkpShape *v16; // rbx
  char m_storage; // cl
  char v18; // cl
  __int64 v19; // rax
  __int64 v20; // rbx
  char v21; // dl
  char v22; // cl
  _QWORD **Value; // rax
  hkpRigidBody *v24; // rax
  hkpRigidBody *v25; // rax
  char v26; // al
  char v27; // dl
  char v28; // cl
  char v29; // al
  char *v30; // rbx
  unsigned int v31; // eax
  unsigned int keysToRemove; // [rsp+30h] [rbp-98h] BYREF
  __int64 v33; // [rsp+38h] [rbp-90h]
  __int64 v34; // [rsp+40h] [rbp-88h]
  hkQuaternionf v35; // [rsp+48h] [rbp-80h] BYREF
  hkpRigidBodyCinfo bodyInfo; // [rsp+58h] [rbp-70h] BYREF
  hkVector4f v37; // [rsp+138h] [rbp+70h]
  hkTransformf transformOut; // [rsp+148h] [rbp+80h] BYREF
  __int64 v39; // [rsp+1E8h] [rbp+120h]
  UFG::RigidBody *v40; // [rsp+1F0h] [rbp+128h]
  hkpPhysicsSystem *v41; // [rsp+1F8h] [rbp+130h]

  *(_QWORD *)&bodyInfo.m_collisionFilterInfo = -2i64;
  mCollisionMeshData = rbc->mCollisionMeshData;
  if ( mCollisionMeshData )
  {
    mOffset = mCollisionMeshData->mPartDetails.mOffset;
    if ( mOffset )
    {
      if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&mCollisionMeshData->mPartDetails + mOffset) )
      {
        v6 = 0i64;
        v35.m_vec.m_quad.m128_u64[0] = 0i64;
        mBody = rbc->mBody;
        m_shape = mBody->m_collidable.m_shape;
        v9 = partIndex;
        if ( partIndex == -1 )
          v9 = 0;
        if ( partIndex == -1 )
          partIndex = mCollisionMeshData->mNumParts - 1;
        v10 = __ROL4__(1, v9);
        if ( v9 <= (__int64)partIndex )
        {
          v11 = 96i64 * v9;
          v33 = v11;
          v12 = partIndex - (__int64)v9 + 1;
          v34 = v12;
          while ( 1 )
          {
            v13 = mCollisionMeshData->mPartDetails.mOffset;
            if ( v13 )
              v14 = (char *)&mCollisionMeshData->mPartDetails + v13;
            else
              v14 = 0i64;
            if ( *(float *)&v14[v11 + 68] <= 0.0 )
              goto LABEL_47;
            mFractureState = rbc->mFractureState;
            if ( !mFractureState || (mFractureState->mBits[(unsigned int)v9 >> 5] & v10) == 0 )
              break;
LABEL_46:
            rbc = v40;
LABEL_47:
            ++v9;
            v10 = __ROL4__(v10, 1);
            v11 += 96i64;
            v33 = v11;
            v34 = --v12;
            if ( !v12 )
              return;
          }
          keysToRemove = v9;
          v16 = 0i64;
          m_storage = m_shape->m_type.m_storage;
          if ( m_storage == 8 )
          {
            if ( ((int (__fastcall *)(hkpShape *))m_shape[1].vfptr->__first_virtual_table_function__)(&m_shape[1]) > 1 )
            {
              v16 = *(hkpShape **)(32i64 * (int)keysToRemove + *(_QWORD *)&m_shape[1].m_type.m_storage);
              UFG::Destruction::removeKeysFromListShape(mBody, &keysToRemove, 1);
            }
          }
          else if ( m_storage == 9 )
          {
            v16 = *(hkpShape **)(32i64 * v9 + *(_QWORD *)(m_shape[2].m_userData + 48));
            v35.m_vec.m_quad.m128_u64[0] = (unsigned __int64)UFG::Destruction::removeKeysFromListShape(
                                                               mBody,
                                                               &keysToRemove,
                                                               1);
          }
          if ( !v16 )
          {
LABEL_41:
            v30 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x28ui64, "BreakoffPart", 0i64, 1u);
            v35.m_vec.m_quad.m128_u64[1] = (unsigned __int64)v30;
            if ( v30 )
            {
              v31 = keysToRemove;
              *(_QWORD *)v30 = 0i64;
              *((_QWORD *)v30 + 1) = mBody;
              *((_DWORD *)v30 + 6) = v31;
              *((_QWORD *)v30 + 4) = 0i64;
              hkReferencedObject::addReference(mBody);
              if ( *(_QWORD *)v30 )
                hkReferencedObject::addReference(*(hkReferencedObject **)v30);
            }
            else
            {
              v30 = 0i64;
            }
            *((_QWORD *)v30 + 2) = v6;
            *((_QWORD *)v30 + 4) = v35.m_vec.m_quad.m128_u64[0];
            UFG::ThreadSafeQueue<hkpEntity>::AddHead(
              (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)(v39 + 24),
              (UFG::CollisionEvent *)v30);
            v11 = v33;
            v12 = v34;
            v6 = 0i64;
            goto LABEL_46;
          }
          hkpRigidBodyCinfo::hkpRigidBodyCinfo((hkpRigidBodyCinfo *)&bodyInfo.m_shape);
          v18 = m_shape->m_type.m_storage;
          if ( v18 == 9 )
          {
            v19 = *(_QWORD *)(m_shape[2].m_userData + 48);
          }
          else
          {
            if ( v18 != 8 )
            {
LABEL_27:
              hkTransformf::setMul(
                (hkTransformf *)&bodyInfo.m_maxAngularVelocity,
                &mBody->m_motion.m_motionState.m_transform,
                &transformOut);
              hkQuaternionf::set(&v35, (hkRotationf *)&bodyInfo.m_maxAngularVelocity);
              *(hkVector4f *)((char *)&bodyInfo.m_position + 8) = (hkVector4f)v37.m_quad;
              bodyInfo.m_position.m_quad.m128_u64[0] = (unsigned __int64)v16;
              *(hkVector4f *)&bodyInfo.m_collisionFilterInfo = mBody->m_motion.m_linearVelocity;
              bodyInfo.m_position = mBody->m_motion.m_angularVelocity;
              bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_i32[0] = 1092616192;
              LOBYTE(bodyInfo.m_gravityFactor) = 2;
              LODWORD(bodyInfo.m_shape) = 20;
              HIBYTE(bodyInfo.m_gravityFactor) = -1;
              hkpInertiaTensorComputer::setShapeVolumeMassProperties(v16, 10.0, (hkpRigidBodyCinfo *)&bodyInfo.m_shape);
              v20 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
              v21 = ++*(_BYTE *)(v20 + 80);
              *(_DWORD *)(v20 + 4i64 * v21) = 0;
              *(_QWORD *)(v20 + 8i64 * v21 + 16) = "hkpRigidBody";
              *(_QWORD *)(v20 + 8i64 * v21 + 48) = 0i64;
              v22 = *(_BYTE *)(v20 + 81);
              if ( v21 > v22 )
                v22 = v21;
              *(_BYTE *)(v20 + 81) = v22;
              Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v24 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                      Value[11],
                                      720i64);
              v35.m_vec.m_quad.m128_u64[1] = (unsigned __int64)v24;
              if ( v24 )
              {
                hkpRigidBody::hkpRigidBody(v24, (hkpRigidBodyCinfo *)&bodyInfo.m_shape);
                v6 = v25;
              }
              else
              {
                v6 = 0i64;
              }
              v26 = *(_BYTE *)(v20 + 80);
              if ( v26 > 0 )
              {
                *(_BYTE *)(v20 + 80) = v26 - 1;
              }
              else
              {
                *(_BYTE *)(v20 + 80) = 0;
                *(_DWORD *)v20 = 3;
                *(_QWORD *)(v20 + 16) = 0i64;
                *(_QWORD *)(v20 + 48) = 0i64;
              }
              v27 = ++*(_BYTE *)(v20 + 80);
              *(_DWORD *)(v20 + 4i64 * v27) = 3;
              *(_QWORD *)(v20 + 8i64 * v27 + 16) = "setName";
              *(_QWORD *)(v20 + 8i64 * v27 + 48) = 0i64;
              v28 = *(_BYTE *)(v20 + 81);
              if ( v27 > v28 )
                v28 = v27;
              *(_BYTE *)(v20 + 81) = v28;
              hkStringPtr::operator=(&v6->m_name, "tmpDestructionBase2");
              v29 = *(_BYTE *)(v20 + 80);
              if ( v29 > 0 )
              {
                *(_BYTE *)(v20 + 80) = v29 - 1;
              }
              else
              {
                *(_BYTE *)(v20 + 80) = 0;
                *(_DWORD *)v20 = 3;
                *(_QWORD *)(v20 + 16) = 0i64;
                *(_QWORD *)(v20 + 48) = 0i64;
              }
              hkpWorld::addEntity(UFG::BasePhysicsSystem::mInstance->mWorld, v6, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
              hkReferencedObject::removeReference(v6);
              hkpPhysicsSystem::addRigidBody(v41, v6);
              goto LABEL_41;
            }
            v19 = *(_QWORD *)&m_shape[1].m_type.m_storage;
          }
          hkQsTransformf::copyToTransformNoScale(
            (hkQsTransformf *)(*(_QWORD *)(32i64 * (int)keysToRemove + v19) + 64i64),
            &transformOut);
          goto LABEL_27;
        }
      }
    }
  }
}

// File Line: 648
// RVA: 0xAFB90
void __fastcall UFG::Destruction::RemovePart(UFG::Destruction *this, UFG::RigidBody *rbc, unsigned int partIndex)
{
  UFG::CollisionMeshData *mCollisionMeshData; // rax
  __int64 mOffset; // rcx
  char *v7; // rdx
  hkpRemoveTerminalsMoppModifier *v8; // r14
  hkpRigidBody *mBody; // rsi
  hkpShape *m_shape; // r9
  BitArray256 *mFractureState; // r8
  char m_storage; // cl
  char *v13; // rbx
  unsigned int v14; // eax
  UFG::CollisionMeshData::PartDetails *PartDetails; // r10
  UFG::CollisionInstanceData *mInstanceData; // r8
  unsigned int v17; // ecx
  __int64 mInstanceGuid; // r9
  hkReferencedObject *v19; // rcx
  unsigned int keysToRemove; // [rsp+68h] [rbp+10h] BYREF
  char *v21; // [rsp+78h] [rbp+20h]

  mCollisionMeshData = rbc->mCollisionMeshData;
  if ( mCollisionMeshData )
  {
    mOffset = mCollisionMeshData->mPartDetails.mOffset;
    if ( mOffset )
    {
      v7 = (char *)&mCollisionMeshData->mPartDetails + mOffset;
      if ( v7 )
      {
        v8 = 0i64;
        mBody = rbc->mBody;
        m_shape = mBody->m_collidable.m_shape;
        if ( *(float *)&v7[96 * partIndex + 68] > 0.0 )
        {
          mFractureState = rbc->mFractureState;
          if ( !mFractureState || (mFractureState->mBits[partIndex >> 5] & (1 << (partIndex & 0x1F))) == 0 )
          {
            keysToRemove = partIndex;
            m_storage = m_shape->m_type.m_storage;
            if ( m_storage == 8 )
            {
              if ( ((int (__fastcall *)(hkpShape *))m_shape[1].vfptr->__first_virtual_table_function__)(&m_shape[1]) > 1 )
                UFG::Destruction::removeKeysFromListShape(mBody, &keysToRemove, 1);
            }
            else if ( m_storage == 9 )
            {
              v8 = UFG::Destruction::removeKeysFromListShape(mBody, &keysToRemove, 1);
            }
            v13 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x28ui64, "BreakoffPart", 0i64, 1u);
            v21 = v13;
            if ( v13 )
            {
              v14 = keysToRemove;
              *(_QWORD *)v13 = 0i64;
              *((_QWORD *)v13 + 1) = mBody;
              *((_DWORD *)v13 + 6) = v14;
              *((_QWORD *)v13 + 4) = 0i64;
              hkReferencedObject::addReference(mBody);
              if ( *(_QWORD *)v13 )
                hkReferencedObject::addReference(*(hkReferencedObject **)v13);
            }
            else
            {
              v13 = 0i64;
            }
            *((_QWORD *)v13 + 2) = 0i64;
            *((_QWORD *)v13 + 4) = v8;
            PartDetails = UFG::CollisionMeshData::GetPartDetails(rbc->mCollisionMeshData, partIndex);
            mInstanceData = rbc->mInstanceData;
            v17 = *((_DWORD *)v13 + 6);
            if ( v17 >= mInstanceData->mNumParts
              || (mInstanceGuid = mInstanceData->mParts[v17].mInstanceUid, !(_DWORD)mInstanceGuid) )
            {
              mInstanceGuid = mInstanceData->mInstanceGuid;
            }
            ((void (__fastcall *)(UFG::RigidBody *, char *, UFG::CollisionMeshData::PartDetails *, __int64))rbc->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
              rbc,
              v13,
              PartDetails,
              mInstanceGuid);
            hkReferencedObject::removeReference(*((hkReferencedObject **)v13 + 1));
            if ( *(_QWORD *)v13 )
              hkReferencedObject::removeReference(*(hkReferencedObject **)v13);
            v19 = (hkReferencedObject *)*((_QWORD *)v13 + 4);
            if ( v19 )
              hkReferencedObject::removeReference(v19);
            UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v13);
          }
        }
      }
    }
  }
}

// File Line: 720
// RVA: 0x98960
void __fastcall UFG::DestructionEvent::DestructionEvent(
        UFG::DestructionEvent *this,
        UFG::SimComponent *collidingComponent,
        UFG::RigidBody *breakingBody,
        unsigned int instanceGuid)
{
  unsigned int mUID; // r10d
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mCollidingComponent; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *p_mBreakingBody; // rdi
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax

  mUID = UFG::gDestructionEventChannel.mUID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = mUID;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::DestructionEvent::`vftable;
  p_mCollidingComponent = &this->mCollidingComponent;
  this->mCollidingComponent.mPrev = &this->mCollidingComponent;
  this->mCollidingComponent.mNext = &this->mCollidingComponent;
  this->mCollidingComponent.m_pPointer = 0i64;
  p_mBreakingBody = &this->mBreakingBody;
  this->mBreakingBody.mPrev = &this->mBreakingBody;
  this->mBreakingBody.mNext = &this->mBreakingBody;
  this->mBreakingBody.m_pPointer = 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->objectProperty);
  this->objectProperty.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  this->instanceUid = instanceGuid;
  mCollisionMeshData = breakingBody->mCollisionMeshData;
  if ( mCollisionMeshData )
    UFG::qReflectHandleBase::operator=(&this->objectProperty, &mCollisionMeshData->mObjectProperties);
  if ( this->mCollidingComponent.m_pPointer )
  {
    mPrev = p_mCollidingComponent->mPrev;
    mNext = this->mCollidingComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCollidingComponent->mPrev = p_mCollidingComponent;
    this->mCollidingComponent.mNext = &this->mCollidingComponent;
  }
  this->mCollidingComponent.m_pPointer = collidingComponent;
  if ( collidingComponent )
  {
    v14 = collidingComponent->m_SafePointerList.mNode.mPrev;
    v14->mNext = p_mCollidingComponent;
    p_mCollidingComponent->mPrev = v14;
    this->mCollidingComponent.mNext = &collidingComponent->m_SafePointerList.mNode;
    collidingComponent->m_SafePointerList.mNode.mPrev = p_mCollidingComponent;
  }
  if ( this->mBreakingBody.m_pPointer )
  {
    v15 = p_mBreakingBody->mPrev;
    v16 = this->mBreakingBody.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    p_mBreakingBody->mPrev = p_mBreakingBody;
    this->mBreakingBody.mNext = &this->mBreakingBody;
  }
  this->mBreakingBody.m_pPointer = breakingBody;
  v17 = breakingBody->m_SafePointerList.mNode.mPrev;
  v17->mNext = p_mBreakingBody;
  p_mBreakingBody->mPrev = v17;
  this->mBreakingBody.mNext = &breakingBody->m_SafePointerList.mNode;
  breakingBody->m_SafePointerList.mNode.mPrev = p_mBreakingBody;
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, this);
}

// File Line: 784
// RVA: 0x9C490
void __fastcall UFG::FractureConnectivity::~FractureConnectivity(UFG::FractureConnectivity *this)
{
  UFG::FractureConnectivity::Node **p; // rcx

  p = this->mNodes.p;
  if ( p )
    operator delete[](p);
  this->mNodes.p = 0i64;
  *(_QWORD *)&this->mNodes.size = 0i64;
}

// File Line: 790
// RVA: 0xA1100
void __fastcall UFG::FractureConnectivity::Build(UFG::FractureConnectivity *this, UFG::CollisionMeshData *mesh)
{
  UFG::CollisionMeshData *v2; // r13
  unsigned int v4; // r12d
  unsigned int mNumParts; // r13d
  char *v6; // rax
  UFG::FractureConnectivity::Node *v7; // r14
  __int64 size; // r15
  unsigned int v9; // esi
  unsigned int capacity; // ebx
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  char *v13; // rax
  UFG::FractureConnectivity::Node **v14; // rbp
  __int64 i; // r9
  __int64 mOffset; // rax
  char *v17; // r14
  __int64 j; // rbx
  __int64 v19; // rsi
  __int64 v20; // rbp
  char *v21; // rax
  char *v22; // r8
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *p_adjacencyList; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *mPrev; // rax
  char *v25; // rax
  char *v26; // r8
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *v27; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v28; // rax

  v2 = mesh;
  v4 = 0;
  if ( mesh->mNumParts )
  {
    mNumParts = mesh->mNumParts;
    do
    {
      v6 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v7 = (UFG::FractureConnectivity::Node *)v6;
      if ( v6 )
      {
        *(_DWORD *)v6 = v4;
        *((_DWORD *)v6 + 1) = -1;
        *((_QWORD *)v6 + 1) = v6 + 8;
        *((_QWORD *)v6 + 2) = v6 + 8;
      }
      else
      {
        v7 = 0i64;
      }
      size = this->mNodes.size;
      v9 = size + 1;
      capacity = this->mNodes.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v11 = 2 * capacity;
        else
          v11 = 1;
        for ( ; v11 < v9; v11 *= 2 )
          ;
        if ( v11 <= 2 )
          v11 = 2;
        if ( v11 - v9 > 0x10000 )
          v11 = size + 65537;
        if ( v11 != (_DWORD)size )
        {
          v12 = 8i64 * v11;
          if ( !is_mul_ok(v11, 8ui64) )
            v12 = -1i64;
          v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
          v14 = (UFG::FractureConnectivity::Node **)v13;
          if ( this->mNodes.p )
          {
            for ( i = 0i64; (unsigned int)i < this->mNodes.size; i = (unsigned int)(i + 1) )
              *(_QWORD *)&v13[8 * i] = this->mNodes.p[i];
            operator delete[](this->mNodes.p);
          }
          this->mNodes.p = v14;
          this->mNodes.capacity = v11;
        }
      }
      this->mNodes.size = v9;
      this->mNodes.p[size] = v7;
      ++v4;
    }
    while ( v4 < mNumParts );
    v2 = mesh;
  }
  mOffset = v2->mFractureConnections.mOffset;
  if ( mOffset )
    v17 = (char *)&v2->mFractureConnections + mOffset;
  else
    v17 = 0i64;
  for ( j = 0i64; (unsigned int)j < v2->mNumFractureConnections; j = (unsigned int)(j + 1) )
  {
    v19 = *(unsigned int *)&v17[8 * j];
    v20 = *(unsigned int *)&v17[8 * j + 4];
    v21 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v22 = v21;
    if ( v21 )
    {
      *(_QWORD *)v21 = v21;
      *((_QWORD *)v21 + 1) = v21;
      *((_DWORD *)v21 + 4) = v19;
    }
    else
    {
      v22 = 0i64;
    }
    p_adjacencyList = &this->mNodes.p[v20]->adjacencyList;
    mPrev = p_adjacencyList->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v22;
    *(_QWORD *)v22 = mPrev;
    *((_QWORD *)v22 + 1) = p_adjacencyList;
    p_adjacencyList->mNode.mPrev = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v22;
    v25 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v26 = v25;
    if ( v25 )
    {
      *(_QWORD *)v25 = v25;
      *((_QWORD *)v25 + 1) = v25;
      *((_DWORD *)v25 + 4) = v20;
    }
    else
    {
      v26 = 0i64;
    }
    v27 = &this->mNodes.p[v19]->adjacencyList;
    v28 = v27->mNode.mPrev;
    v28->mNext = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v26;
    *(_QWORD *)v26 = v28;
    *((_QWORD *)v26 + 1) = v27;
    v27->mNode.mPrev = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v26;
  }
  UFG::FractureConnectivity::ComputeNodeColors(this);
}

// File Line: 883
// RVA: 0xA6C10
void __fastcall UFG::FractureConnectivity::DeleteNodeByPartIndex(
        UFG::FractureConnectivity *this,
        unsigned int partIndex)
{
  __int64 v3; // rbp
  int v4; // ebx
  unsigned int size; // r8d
  UFG::FractureConnectivity::Node **p; // r9
  unsigned int v7; // r14d
  UFG::FractureConnectivity::Node **v8; // rdx
  UFG::FractureConnectivity::Node *v9; // r13
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *p_adjacencyList; // rsi
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *mNext; // rax
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *v12; // rdi
  int mPrev; // ecx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v14; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v15; // rcx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v16; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v17; // rax

  this->mColorsDirty = 1;
  v3 = 0i64;
  v4 = 0;
  size = this->mNodes.size;
  if ( this->mNodes.size )
  {
    p = this->mNodes.p;
    while ( p[v4]->partIdx != partIndex )
    {
      if ( ++v4 >= size )
        return;
    }
    if ( v4 != -1 )
    {
      v7 = size - 1;
      v8 = &p[v4];
      v9 = *v8;
      *v8 = p[size - 1];
      if ( this->mNodes.size > 1 )
        --this->mNodes.size;
      else
        this->mNodes.size = 0;
      if ( this->mNodes.size )
      {
        do
        {
          p_adjacencyList = &this->mNodes.p[v3]->adjacencyList;
          mNext = this->mNodes.p[v3]->adjacencyList.mNode.mNext;
          if ( mNext != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)p_adjacencyList )
          {
            do
            {
              v12 = (UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *)mNext->mNext;
              mPrev = (int)mNext[1].mPrev;
              if ( mPrev == v4 )
              {
                v14 = mNext->mPrev;
                v15 = mNext->mNext;
                v14->mNext = v15;
                v15->mPrev = v14;
                mNext->mPrev = mNext;
                mNext->mNext = mNext;
                operator delete[](mNext);
              }
              else if ( mPrev == v7 )
              {
                LODWORD(mNext[1].mPrev) = v4;
              }
              mNext = &v12->mNode;
            }
            while ( v12 != p_adjacencyList );
          }
          v3 = (unsigned int)(v3 + 1);
        }
        while ( (unsigned int)v3 < this->mNodes.size );
      }
      if ( v9 )
      {
        UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v9->adjacencyList);
        v16 = v9->adjacencyList.mNode.mPrev;
        v17 = v9->adjacencyList.mNode.mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        v9->adjacencyList.mNode.mPrev = &v9->adjacencyList.mNode;
        v9->adjacencyList.mNode.mNext = &v9->adjacencyList.mNode;
        operator delete[](v9);
      }
    }
  }
}

// File Line: 946
// RVA: 0xA3EE0
__int64 __fastcall UFG::FractureConnectivity::ComputeNodeColors(UFG::FractureConnectivity *this)
{
  __int64 v1; // rbp
  unsigned int i; // edx
  __int64 v4; // rcx
  UFG::FractureConnectivity::Node *v5; // rcx
  int mNumColors; // r14d
  UFG::FractureConnectivity::Node *v7; // rsi
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *mNext; // rdi
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *j; // rsi
  __int64 result; // rax

  v1 = 0i64;
  this->mColorsDirty = 1;
  for ( i = 0; i < this->mNodes.size; this->mNodes.p[v4]->color = -1 )
    v4 = i++;
  this->mNumColors = 0;
  if ( this->mNodes.size )
  {
    do
    {
      v5 = this->mNodes.p[v1];
      if ( v5->color == -1 )
      {
        mNumColors = this->mNumColors;
        v5->color = mNumColors;
        v7 = this->mNodes.p[v1];
        mNext = v7->adjacencyList.mNode.mNext;
        for ( j = &v7->adjacencyList;
              mNext != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)j;
              mNext = mNext->mNext )
        {
          UFG::FractureConnectivity::ColorNodeAndAdjacent(this, (unsigned int)mNext[1].mPrev, mNumColors);
        }
        ++this->mNumColors;
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < this->mNodes.size );
    result = (unsigned int)this->mNumColors;
    this->mColorsDirty = 0;
  }
  else
  {
    this->mColorsDirty = 0;
    return 0i64;
  }
  return result;
}

// File Line: 968
// RVA: 0xA27B0
void __fastcall UFG::FractureConnectivity::ColorNodeAndAdjacent(
        UFG::FractureConnectivity *this,
        unsigned int nodeIdx,
        int color)
{
  UFG::FractureConnectivity::Node *v5; // rcx
  UFG::FractureConnectivity::Node *v6; // rdi
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *mNext; // rbx
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *i; // rdi

  v5 = this->mNodes.p[nodeIdx];
  if ( v5->color == -1 )
  {
    v5->color = color;
    v6 = this->mNodes.p[nodeIdx];
    mNext = v6->adjacencyList.mNode.mNext;
    for ( i = &v6->adjacencyList;
          mNext != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)i;
          mNext = mNext->mNext )
    {
      UFG::FractureConnectivity::ColorNodeAndAdjacent(this, (unsigned int)mNext[1].mPrev, color);
    }
  }
}

// File Line: 987
// RVA: 0xA7FC0
void __fastcall UFG::FractureConnectivity::ExtractSubGraphs(
        UFG::FractureConnectivity *this,
        UFG::qArray<UFG::qReflectInventoryBase *,0> *subGraphs)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // r13
  UFG::FractureConnectivity *v3; // rbx
  unsigned __int64 size; // r15
  unsigned __int64 v5; // rax
  char *v6; // rsi
  int v7; // r14d
  char *v8; // rax
  char *v9; // rdi
  __int64 v10; // rbp
  unsigned int v11; // ebx
  unsigned int capacity; // edx
  unsigned int v13; // edx
  __int64 v14; // r12
  char *v15; // r15
  __int64 color; // rdi
  char *v17; // rax
  char *v18; // r14
  UFG::FractureConnectivity::Node *v19; // rdx
  UFG::qReflectInventoryBase *v20; // rdi
  __int64 vfptr_low; // r13
  unsigned int v22; // ebp
  unsigned int vfptr_high; // ebx
  unsigned int v24; // ebx
  unsigned __int64 v25; // rax
  char *v26; // rax
  char *v27; // r15
  __int64 i; // r9
  UFG::FractureConnectivity::Node **p; // rax
  __int64 p_adjacencyList; // rbp
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *mNext; // rbx
  char **v32; // rdi
  char *v33; // rax
  char *v34; // rdx
  int mPrev; // ecx
  char *v36; // rax
  bool v37; // zf
  __int64 j; // r11
  UFG::FractureConnectivity *v39; // r10
  __int64 k; // r9
  __int64 v41; // r8
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *m; // rax
  char *v45; // [rsp+A0h] [rbp+18h]
  __int64 v46; // [rsp+A8h] [rbp+20h]

  v2 = subGraphs;
  v3 = this;
  size = this->mNodes.size;
  if ( (unsigned int)size > 1 && this->mNumColors > 1 )
  {
    v46 = this->mNodes.size;
    v5 = 4 * size;
    if ( !is_mul_ok(size, 4ui64) )
      v5 = -1i64;
    v6 = UFG::qMalloc(v5, UFG::gGlobalNewName, 0i64);
    v7 = 0;
    if ( v3->mNumColors > 0 )
    {
      do
      {
        v8 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
        v9 = v8;
        if ( v8 )
        {
          *((_QWORD *)v8 + 1) = 0i64;
          *(_QWORD *)v8 = 0i64;
          *((_DWORD *)v8 + 4) = 0;
          v8[20] = 0;
        }
        else
        {
          v9 = 0i64;
        }
        v10 = v2->size;
        v11 = v10 + 1;
        capacity = v2->capacity;
        if ( (int)v10 + 1 > capacity )
        {
          if ( capacity )
            v13 = 2 * capacity;
          else
            v13 = 1;
          for ( ; v13 < v11; v13 *= 2 )
            ;
          if ( v13 <= 2 )
            v13 = 2;
          if ( v13 - v11 > 0x10000 )
            v13 = v10 + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v13, "qArray.Add");
        }
        v2->size = v11;
        v2->p[v10] = (UFG::qReflectInventoryBase *)v9;
        ++v7;
        v3 = this;
      }
      while ( v7 < this->mNumColors );
    }
    v14 = 0i64;
    v15 = v6;
    v45 = v6;
    do
    {
      color = (unsigned int)v3->mNodes.p[v14]->color;
      *(_DWORD *)v15 = v2->p[color]->vfptr;
      v17 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v18 = v17;
      if ( v17 )
      {
        v19 = v3->mNodes.p[v14];
        *(_DWORD *)v17 = v19->partIdx;
        *((_DWORD *)v17 + 1) = v19->color;
        *((_QWORD *)v17 + 1) = v17 + 8;
        *((_QWORD *)v17 + 2) = v17 + 8;
      }
      else
      {
        v18 = 0i64;
      }
      v20 = v2->p[color];
      vfptr_low = LODWORD(v20->vfptr);
      v22 = vfptr_low + 1;
      vfptr_high = HIDWORD(v20->vfptr);
      if ( (int)vfptr_low + 1 > vfptr_high )
      {
        if ( vfptr_high )
          v24 = 2 * vfptr_high;
        else
          v24 = 1;
        for ( ; v24 < v22; v24 *= 2 )
          ;
        if ( v24 <= 2 )
          v24 = 2;
        if ( v24 - v22 > 0x10000 )
          v24 = vfptr_low + 65537;
        if ( v24 != (_DWORD)vfptr_low )
        {
          v25 = 8i64 * v24;
          if ( !is_mul_ok(v24, 8ui64) )
            v25 = -1i64;
          v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
          v27 = v26;
          if ( v20->mBaseNode.mUID )
          {
            for ( i = 0i64; (unsigned int)i < LODWORD(v20->vfptr); i = (unsigned int)(i + 1) )
              *(_QWORD *)&v26[8 * i] = *(_QWORD *)(8 * i + v20->mBaseNode.mUID);
            operator delete[]((void *)v20->mBaseNode.mUID);
          }
          v20->mBaseNode.mUID = (unsigned __int64)v27;
          HIDWORD(v20->vfptr) = v24;
          v15 = v45;
        }
      }
      LODWORD(v20->vfptr) = v22;
      *(_QWORD *)(v20->mBaseNode.mUID + 8 * vfptr_low) = v18;
      p = this->mNodes.p;
      p_adjacencyList = (__int64)&p[v14]->adjacencyList;
      mNext = p[v14]->adjacencyList.mNode.mNext;
      if ( mNext != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)p_adjacencyList )
      {
        v32 = (char **)(v18 + 8);
        do
        {
          v33 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
          v34 = v33;
          if ( v33 )
          {
            mPrev = (int)mNext[1].mPrev;
            *(_QWORD *)v33 = v33;
            *((_QWORD *)v33 + 1) = v33;
            *((_DWORD *)v33 + 4) = mPrev;
          }
          else
          {
            v34 = 0i64;
          }
          v36 = *v32;
          *((_QWORD *)v36 + 1) = v34;
          *(_QWORD *)v34 = v36;
          *((_QWORD *)v34 + 1) = v32;
          *v32 = v34;
          mNext = mNext->mNext;
        }
        while ( mNext != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)p_adjacencyList );
      }
      v15 += 4;
      v45 = v15;
      ++v14;
      v37 = v46-- == 1;
      v2 = subGraphs;
      v3 = this;
    }
    while ( !v37 );
    for ( j = 0i64; (unsigned int)j < subGraphs->size; j = (unsigned int)(j + 1) )
    {
      v39 = (UFG::FractureConnectivity *)subGraphs->p[j];
      for ( k = 0i64; (unsigned int)k < v39->mNodes.size; k = (unsigned int)(k + 1) )
      {
        v41 = (__int64)&v39->mNodes.p[k]->adjacencyList;
        for ( m = v39->mNodes.p[k]->adjacencyList.mNode.mNext;
              m != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v41;
              m = m->mNext )
        {
          LODWORD(m[1].mPrev) = *(_DWORD *)&v6[4 * LODWORD(m[1].mPrev)];
        }
      }
      v39->mNumColors = 1;
      v39->mColorsDirty = 0;
    }
    operator delete[](v6);
  }
}

