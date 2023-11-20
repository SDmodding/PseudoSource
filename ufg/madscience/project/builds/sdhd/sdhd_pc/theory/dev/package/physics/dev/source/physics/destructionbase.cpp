// File Line: 38
// RVA: 0x1459000
__int64 UFG::_dynamic_initializer_for__gDestructionEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gDestructionEventChannel,
    "DestructionBaseEvent",
    "This is an event that gets generated when physics Destruction happens.");
  return atexit(UFG::_dynamic_atexit_destructor_for__gDestructionEventChannel__);
}

// File Line: 75
// RVA: 0xAC950
void __fastcall UFG::Destruction::Initialize(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  _QWORD **v2; // rax
  UFG::Destruction *v3; // rax

  v1 = world;
  if ( !UFG::Destruction::mInstance )
  {
    v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (UFG::Destruction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 488i64);
    if ( v3 )
      UFG::Destruction::Destruction(v3, v1);
    UFG::Destruction::mInstance = v3;
  }
}

// File Line: 96
// RVA: 0x987E0
void __fastcall UFG::Destruction::Destruction(UFG::Destruction *this, hkpWorld *world)
{
  hkpWorld *v2; // rsi
  UFG::Destruction *v3; // rdi
  hkReferencedObject *v4; // rax
  UFG::ThreadSafeQueue<UFG::BreakoffPart> *v5; // rbx
  signed __int64 v6; // rbx
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  _QWORD **v10; // rax
  hkpBreakOffPartsUtil *v11; // rax
  hkpBreakOffPartsUtil *v12; // rax
  char v13; // al

  v2 = world;
  v3 = this;
  this->vfptr = (hkpBreakOffPartsListenerVtbl *)&hkpBreakOffPartsListener::`vftable';
  v4 = (hkReferencedObject *)&this->vfptr;
  v4->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v4->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  *(_DWORD *)&v4->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkpBreakOffPartsListenerVtbl *)&UFG::Destruction::`vftable'{for `hkpBreakOffPartsListener'};
  v4->vfptr = (hkBaseObjectVtbl *)&UFG::Destruction::`vftable'{for `hkReferencedObject'};
  v5 = &this->mBreakOffPartsQueue;
  UFG::qMutex::qMutex(&this->mBreakOffPartsQueue.mutex, &customWorldMapCaption);
  v3->mBreakOffPartsQueue.head.next = &v3->mBreakOffPartsQueue.tail;
  v5->head.prev = 0i64;
  v3->mBreakOffPartsQueue.tail.prev = &v3->mBreakOffPartsQueue.head;
  v3->mBreakOffPartsQueue.tail.next = 0i64;
  `eh vector constructor iterator'(
    v3->mObjects,
    0x18ui64,
    15,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody>::qSafePointer<UFG::SimComponent,UFG::RigidBody>);
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  v8 = v7;
  *(_DWORD *)(v6 + 4 * v8) = 3;
  *(_QWORD *)(v6 + 8 * v8 + 16) = "hkpBreakOffPartsUtil";
  *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
  v9 = *(_BYTE *)(v6 + 81);
  if ( v7 > v9 )
    v9 = v7;
  *(_BYTE *)(v6 + 81) = v9;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkpBreakOffPartsUtil *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 80i64);
  if ( v11 )
    hkpBreakOffPartsUtil::hkpBreakOffPartsUtil(v11, (hkpBreakOffPartsListener *)&v3->vfptr);
  else
    v12 = 0i64;
  v3->mBreakOffPartsUtil = v12;
  v13 = *(_BYTE *)(v6 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  hkpWorld::addWorldExtension(v2, (hkpWorldExtension *)&v3->mBreakOffPartsUtil->vfptr);
}

// File Line: 108
// RVA: 0x9C1B0
void __fastcall UFG::Destruction::~Destruction(UFG::Destruction *this)
{
  UFG::Destruction *v1; // rbx
  hkReferencedObject *v2; // rdi
  hkpBreakOffPartsUtil *v3; // rdx
  hkpWorld *v4; // rcx

  v1 = this;
  this->vfptr = (hkpBreakOffPartsListenerVtbl *)&UFG::Destruction::`vftable'{for `hkpBreakOffPartsListener'};
  v2 = (hkReferencedObject *)&this->vfptr;
  this->vfptr = (hkBaseObjectVtbl *)&UFG::Destruction::`vftable'{for `hkReferencedObject'};
  v3 = this->mBreakOffPartsUtil;
  v4 = v3->m_world;
  if ( v4 )
    hkpWorld::removeWorldExtension(v4, (hkpWorldExtension *)&v3->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mBreakOffPartsUtil->vfptr);
  `eh vector destructor iterator'(
    v1->mObjects,
    0x18ui64,
    15,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
  UFG::ThreadSafeQueue<UFG::BreakoffPart>::~ThreadSafeQueue<UFG::BreakoffPart>(&v1->mBreakOffPartsQueue);
  v2->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v1->vfptr = (hkpBreakOffPartsListenerVtbl *)&hkpBreakOffPartsListener::`vftable';
}

// File Line: 125
// RVA: 0xB46E0
void __fastcall UFG::Destruction::Update(UFG::Destruction *this)
{
  UFG::Destruction *v1; // r15
  UFG::BasePhysicsSystem *v2; // r14
  signed __int64 v3; // rbp
  UFG::SimComponent **v4; // rbx
  __m128 *v5; // rdi
  signed __int64 v6; // rsi
  UFG::SimComponent *v7; // rdx
  __m128 *v8; // rax
  __m128 *v9; // rax
  __m128 v10; // xmm2
  __m128 *v11; // rax
  __int64 v12; // rcx
  _QWORD *v13; // rax
  unsigned int v14; // er9
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v15; // rdx
  unsigned int v16; // ecx
  hkpBreakOffPartsListenerVtbl **v17; // r8
  __int64 v18; // r10
  UFG::SimComponent *v19; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  hkpBreakOffPartsListenerVtbl **v23; // r8
  hkpBreakOffPartsListenerVtbl *v24; // rcx
  hkpBreakOffPartsListenerVtbl *v25; // rax

  v1 = this;
  UFG::Destruction::FixupBreakOffParts(this);
  v2 = UFG::BasePhysicsSystem::mInstance;
  v3 = 15i64;
  v4 = &v1->mObjects[0].m_pPointer;
  v5 = (__m128 *)&UFG::BasePhysicsSystem::mInstance->mActiveRegionManager;
  v6 = 15i64;
  do
  {
    v7 = *v4;
    if ( *v4 )
    {
      v8 = (__m128 *)v7[2].m_pSimObject;
      if ( v8 )
        v9 = v8 + 26;
      else
        v9 = (__m128 *)(*(_QWORD *)&v7[2].m_TypeUID + 32i64);
      v10 = *v9;
      v11 = (__m128 *)v5->m128_u64[1];
      if ( v11 == v5 )
      {
LABEL_9:
        v2->vfptr->OnCollisionInstanceRemovedFromWorld(v2, *(UFG::CollisionInstanceData **)&v7[2].m_TypeUID);
        if ( *v4 )
        {
          v12 = (__int64)*(v4 - 2);
          v13 = *(v4 - 1);
          *(_QWORD *)(v12 + 8) = v13;
          *v13 = v12;
          *(v4 - 2) = (UFG::SimComponent *)(v4 - 2);
          *(v4 - 1) = (UFG::SimComponent *)(v4 - 2);
        }
        *v4 = 0i64;
      }
      else
      {
        while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v10, v11[3]), _mm_cmpleps(v11[2], v10))) & 7) != 7 )
        {
          v11 = (__m128 *)v11->m128_u64[1];
          if ( v11 == v5 )
            goto LABEL_9;
        }
      }
    }
    v4 += 3;
    --v6;
  }
  while ( v6 );
  v14 = 1;
  v15 = v1->mObjects;
  do
  {
    if ( !v15->m_pPointer )
    {
      v16 = v14;
      if ( v14 < 0xF )
      {
        v17 = &v1->vfptr + v14 + 2i64 * v14 + 17;
        while ( !*v17 )
        {
          ++v16;
          v17 += 3;
          if ( v16 >= 0xF )
            goto LABEL_27;
        }
        v18 = v16;
        v19 = v1->mObjects[v16].m_pPointer;
        if ( v15->m_pPointer )
        {
          v20 = v15->mPrev;
          v21 = v15->mNext;
          v20->mNext = v21;
          v21->mPrev = v20;
          v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
          v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
        }
        v15->m_pPointer = v19;
        if ( v19 )
        {
          v22 = v19->m_SafePointerList.mNode.mPrev;
          v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
          v15->mPrev = v22;
          v15->mNext = &v19->m_SafePointerList.mNode;
          v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
        }
        v23 = &(&v1->vfptr)[3 * (v18 + 5)];
        if ( *((_QWORD *)&v1->m_memSizeAndFlags + 3 * (v18 + 5)) )
        {
          v24 = *v23;
          v25 = v23[1];
          v24->breakOffSubPart = (hkResult *(__fastcall *)(hkpBreakOffPartsListener *, hkResult *, hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent *, hkpPhysicsSystem *))v25;
          v25->__vecDelDtor = (void *(__fastcall *)(hkpBreakOffPartsListener *, unsigned int))v24;
          *v23 = (hkpBreakOffPartsListenerVtbl *)v23;
          v23[1] = (hkpBreakOffPartsListenerVtbl *)v23;
        }
        v23[2] = 0i64;
      }
    }
LABEL_27:
    ++v14;
    ++v15;
    --v3;
  }
  while ( v3 );
}

// File Line: 176
// RVA: 0xA8410
void __fastcall UFG::Destruction::FixupBreakOffParts(UFG::Destruction *this)
{
  UFG::Destruction *v1; // r14
  bool v2; // bl
  UFG::BreakoffPart *v3; // rax
  hkReferencedObject **v4; // rbx
  unsigned __int64 v5; // rdi
  __int64 v6; // rdi
  __int64 v7; // rsi
  hkpRemoveTerminalsMoppModifier *v8; // rdx
  __int64 v9; // r9
  __int64 v10; // r8
  __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // r8
  __int64 v14; // rcx
  unsigned int v15; // esi
  UFG::RigidBody *v16; // rbp
  __int64 v17; // rdx
  UFG::SimComponent *v18; // rdi
  char *v19; // rax
  __int64 v20; // rax
  UFG::SimComponent **v21; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v22; // rax
  UFG::SimComponent **v23; // r9
  signed __int64 v24; // r10
  UFG::SimComponent *v25; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  hkpEntity *v33; // r8
  hkpWorld *v34; // rcx
  hkReferencedObject *v35; // rcx
  bool v36; // bl
  hkBool result; // [rsp+80h] [rbp+8h]
  char *v38; // [rsp+88h] [rbp+10h]

  v1 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBreakOffPartsQueue.mutex);
  v2 = v1->mBreakOffPartsQueue.head.next == &v1->mBreakOffPartsQueue.tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
  if ( !v2 )
  {
    do
    {
      v3 = UFG::ThreadSafeQueue<UFG::BreakoffPart>::RemoveTail(&v1->mBreakOffPartsQueue);
      v4 = (hkReferencedObject **)v3;
      v5 = v3->breakingRigidBody->m_userData;
      if ( v5 )
      {
        v6 = *(_QWORD *)(v5 + 24);
        v7 = *(_QWORD *)(v6 + 160);
        v8 = v3->mRemoveTerminalsMoppModifier;
        if ( v7 && v8 )
        {
          UFG::CollisionMeshData::AddMoppTerminalModifier(*(UFG::CollisionMeshData **)(v6 + 160), v8);
          hkReferencedObject::removeReference(v4[4]);
          v4[4] = 0i64;
        }
        v9 = *((unsigned int *)v4 + 6);
        v10 = *(_QWORD *)(v6 + 240);
        if ( !v10 || !(*(_DWORD *)(v10 + 4i64 * ((unsigned int)v9 >> 5)) & (1 << (v9 & 0x1F))) )
        {
          v11 = *(_QWORD *)(v7 + 160);
          if ( v11 )
            v12 = v7 + v11 + 160;
          else
            v12 = 0i64;
          v13 = v12 + 96i64 * (signed int)v9;
          v14 = *(_QWORD *)(v6 + 152);
          if ( (unsigned int)v9 >= *(_DWORD *)(v14 + 76)
            || (v15 = *(_DWORD *)(32 * v9 + *(_QWORD *)(v14 + 80) + 28)) == 0 )
          {
            v15 = *(_DWORD *)(v14 + 92);
          }
          v16 = (UFG::RigidBody *)(*(__int64 (__fastcall **)(__int64, hkReferencedObject **, signed __int64, _QWORD))(*(_QWORD *)v6 + 112i64))(
                                    v6,
                                    v4,
                                    v13,
                                    v15);
          if ( v16 )
          {
            if ( *v4 && (v17 = *(_QWORD *)&(*v4)[1].m_memSizeAndFlags) != 0 )
              v18 = *(UFG::SimComponent **)(v17 + 24);
            else
              v18 = 0i64;
            v19 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x98ui64, "DestructionEvent", 0i64, 1u);
            v38 = v19;
            if ( v19 )
              UFG::DestructionEvent::DestructionEvent((UFG::DestructionEvent *)v19, v18, v16, v15);
            v20 = 0i64;
            v21 = &v1->mObjects[0].m_pPointer;
            do
            {
              if ( !*v21 )
              {
                v29 = (UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *)((char *)v1 + 24 * (v20 + 5));
                goto LABEL_32;
              }
              v20 = (unsigned int)(v20 + 1);
              v21 += 3;
            }
            while ( (unsigned int)v20 < 0xF );
            UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceRemovedFromWorld(
              UFG::BasePhysicsSystem::mInstance,
              *(UFG::CollisionInstanceData **)&v1->mObjects[0].m_pPointer[2].m_TypeUID);
            v22 = v1->mObjects;
            v23 = &v1->mObjects[1].m_pPointer;
            v24 = 14i64;
            do
            {
              v25 = *v23;
              if ( v22->m_pPointer )
              {
                v26 = v22->mPrev;
                v27 = v22->mNext;
                v26->mNext = v27;
                v27->mPrev = v26;
                v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
                v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
              }
              v22->m_pPointer = v25;
              if ( v25 )
              {
                v28 = v25->m_SafePointerList.mNode.mPrev;
                v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
                v22->mPrev = v28;
                v22->mNext = &v25->m_SafePointerList.mNode;
                v25->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
              }
              v23 += 3;
              ++v22;
              --v24;
            }
            while ( v24 );
            v29 = &v1->mObjects[14];
LABEL_32:
            if ( v29->m_pPointer )
            {
              v30 = v29->mPrev;
              v31 = v29->mNext;
              v30->mNext = v31;
              v31->mPrev = v30;
              v29->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
              v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
            }
            v29->m_pPointer = (UFG::SimComponent *)&v16->vfptr;
            v32 = v16->m_SafePointerList.mNode.mPrev;
            v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
            v29->mPrev = v32;
            v29->mNext = &v16->m_SafePointerList.mNode;
            v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
          }
        }
      }
      v33 = (hkpEntity *)v4[2];
      if ( v33 )
      {
        v34 = v33->m_world;
        if ( v34 )
          hkpWorld::removeEntity(v34, &result, v33);
      }
      hkReferencedObject::removeReference(v4[1]);
      if ( *v4 )
        hkReferencedObject::removeReference(*v4);
      v35 = v4[4];
      if ( v35 )
        hkReferencedObject::removeReference(v35);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v4);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
      v36 = v1->mBreakOffPartsQueue.head.next == &v1->mBreakOffPartsQueue.tail;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
    }
    while ( !v36 );
  }
}

// File Line: 286
// RVA: 0xB00A0
void __fastcall UFG::Destruction::ResetScene(UFG::Destruction *this)
{
  UFG::Destruction *v1; // r14
  UFG::SimComponent **v2; // rbx
  signed __int64 v3; // rdi
  UFG::QueueNode<UFG::BreakoffPart> *v4; // rsi
  bool v5; // bl
  UFG::BreakoffPart *v6; // rdi
  bool v7; // bl
  UFG::QueueNode<UFG::BreakoffPart> *v8; // rcx
  UFG::QueueNode<UFG::BreakoffPart> *v9; // rax
  hkpEntity *v10; // r8
  hkpWorld *v11; // rcx
  hkReferencedObject *v12; // rcx
  bool v13; // bl
  hkBool result; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = &this->mObjects[0].m_pPointer;
  v3 = 15i64;
  do
  {
    if ( *v2 )
      UFG::Simulation::DestroySimObject(&UFG::gSim, (*v2)->m_pSimObject);
    v2 += 3;
    --v3;
  }
  while ( v3 );
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
  v4 = &v1->mBreakOffPartsQueue.tail;
  v5 = v1->mBreakOffPartsQueue.head.next == &v1->mBreakOffPartsQueue.tail;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
  if ( !v5 )
  {
    do
    {
      v6 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
      v7 = v1->mBreakOffPartsQueue.head.next == v4;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
      if ( !v7 )
      {
        v8 = v4->prev;
        v9 = v4->prev->prev;
        v9->next = v4;
        v4->prev = v9;
        v6 = v8->data;
        operator delete[](v8);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
      v10 = (hkpEntity *)&v6->newRigidBody->vfptr;
      if ( v10 )
      {
        v11 = v10->m_world;
        if ( v11 )
          hkpWorld::removeEntity(v11, &result, v10);
      }
      hkReferencedObject::removeReference((hkReferencedObject *)&v6->breakingRigidBody->vfptr);
      if ( v6->collidingRigidBody )
        hkReferencedObject::removeReference((hkReferencedObject *)&v6->collidingRigidBody->vfptr);
      v12 = (hkReferencedObject *)&v6->mRemoveTerminalsMoppModifier->vfptr;
      if ( v12 )
        hkReferencedObject::removeReference(v12);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v6);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
      v13 = v1->mBreakOffPartsQueue.head.next == v4;
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBreakOffPartsQueue.mutex);
    }
    while ( !v13 );
  }
}

// File Line: 354
// RVA: 0xACD00
bool __fastcall UFG::Destruction::IsPartMarkedAsBreakable(UFG::Destruction *this, hkpEntity *entity, unsigned int shapeKey)
{
  char v3; // cl

  v3 = 0;
  if ( (_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
    v3 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(((_QWORD)entity->m_limitContactImpulseUtilAndFlag & 0xFFFFFFFFFFFFFFFEui64)
                                                                                             + 48),
           shapeKey,
           0i64);
  return v3 != 0;
}

// File Line: 372
// RVA: 0xB89E0
hkpRemoveTerminalsMoppModifier *__fastcall UFG::Destruction::removeKeysFromListShape(hkpEntity *entity, unsigned int *keysToRemove, int numKeys)
{
  unsigned int *v3; // r14
  hkpEntity *v4; // r15
  hkpRemoveTerminalsMoppModifier *v5; // r12
  hkAabbUint32 *v6; // r13
  hkpShape *v7; // rsi
  __int64 v8; // rdi
  unsigned __int64 v10; // rbx
  _QWORD **v11; // rax
  hkpRemoveTerminalsMoppModifier *v12; // rax
  hkpShapeContainer *v13; // r8
  hkpRemoveTerminalsMoppModifier *v14; // rax
  __int64 i; // rbx
  __int64 j; // rbx
  unsigned int *v17; // r14
  __int64 v18; // rdi
  __int64 v19; // rsi
  signed __int64 v20; // rbx
  hkArray<unsigned int,hkContainerHeapAllocator> shapesToRemove; // [rsp+28h] [rbp-18h]

  v3 = keysToRemove;
  v4 = entity;
  v5 = 0i64;
  v6 = entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
  v7 = entity->m_collidable.m_shape;
  v8 = numKeys;
  if ( v7->m_type.m_storage != 8 )
  {
    if ( v7->m_type.m_storage != 9 )
      return 0i64;
    v10 = v7[2].m_userData;
    shapesToRemove.m_data = keysToRemove;
    shapesToRemove.m_size = numKeys;
    shapesToRemove.m_capacityAndFlags = numKeys | 0x80000000;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkpRemoveTerminalsMoppModifier *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                              v11[11],
                                              48i64);
    if ( v12 )
    {
      if ( v10 )
        v13 = (hkpShapeContainer *)(v10 + 32);
      else
        v13 = 0i64;
      hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
        v12,
        *(hkpMoppCode **)&v7[1].m_memSizeAndFlags,
        v13,
        &shapesToRemove);
      v5 = v14;
    }
    else
    {
      v5 = 0i64;
    }
    hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(v5, *(hkpMoppCode **)&v7[1].m_memSizeAndFlags);
    if ( *(_BYTE *)(v10 + 16) != 8 )
    {
      shapesToRemove.m_size = 0;
      if ( shapesToRemove.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          shapesToRemove.m_data,
          4 * shapesToRemove.m_capacityAndFlags);
      shapesToRemove.m_data = 0i64;
      shapesToRemove.m_capacityAndFlags = 2147483648;
      goto LABEL_19;
    }
    v7 = (hkpShape *)v10;
    shapesToRemove.m_size = 0;
    if ( shapesToRemove.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        shapesToRemove.m_data,
        4 * shapesToRemove.m_capacityAndFlags);
    shapesToRemove.m_data = 0i64;
    shapesToRemove.m_capacityAndFlags = 2147483648;
  }
  for ( i = 0i64; i < v8; ++i )
    hkpListShape::disableChild((hkpListShape *)v7, v3[i]);
LABEL_19:
  if ( v6 )
  {
    shapesToRemove.m_data = 0i64;
    shapesToRemove.m_size = 0;
    shapesToRemove.m_capacityAndFlags = -1;
    for ( j = 0i64; j < v8; ++j )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v3[j],
        1ui64);
    v17 = v4->m_collidable.m_boundingVolumeData.m_childShapeKeys;
    v18 = 0i64;
    v19 = v4->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs;
    if ( (signed int)v4->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs > 0 )
    {
      v20 = (signed __int64)&v6->m_max[2];
      do
      {
        if ( (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
                             v17[v18],
                             0i64) )
        {
          *(_DWORD *)(v20 - 20) = 2147418112;
          *(_QWORD *)(v20 - 16) = 2147418112i64;
          *(_QWORD *)(v20 - 4) = 0i64;
        }
        ++v18;
        v20 += 32i64;
      }
      while ( v18 < v19 );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&shapesToRemove,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&shapesToRemove);
  }
  return v5;
}

// File Line: 442
// RVA: 0xB6920
void __fastcall UFG::Destruction::breakOffSubPart(UFG::Destruction *this, hkpRigidBody *collidingBody, hkpRigidBody *breakingBody, unsigned int brokenPieceKey)
{
  hkpRigidBody *v4; // r15
  hkpRigidBody *v5; // rdi
  UFG::Destruction *v6; // r12
  char *v7; // rbx
  unsigned int v8; // eax
  hkpShape *v9; // r14
  hkpShape *v10; // rsi
  char v11; // cl
  hkpRigidBody *v12; // rsi
  signed __int64 v13; // r14
  char v14; // dl
  __int64 v15; // rax
  char v16; // cl
  _QWORD **v17; // rax
  hkpRigidBody *v18; // rax
  hkpRigidBody *v19; // rax
  char v20; // al
  hkReferencedObject *v21; // rcx
  __m128 v22; // [rsp+30h] [rbp-A8h]
  __int64 v23; // [rsp+40h] [rbp-98h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+50h] [rbp-88h]
  void *v25; // [rsp+138h] [rbp+60h]
  unsigned int keysToRemove; // [rsp+150h] [rbp+78h]
  __m128 *v27; // [rsp+160h] [rbp+88h]
  __int64 v28; // [rsp+168h] [rbp+90h]
  _DWORD *array; // [rsp+170h] [rbp+98h]
  hkpPhysicsSystem *v30; // [rsp+178h] [rbp+A0h]

  LODWORD(v30) = brokenPieceKey;
  v23 = -2i64;
  v4 = breakingBody;
  v5 = collidingBody;
  v6 = this;
  v7 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x28ui64, "BreakoffPart", 0i64, 1u);
  v25 = v7;
  if ( v7 )
  {
    v8 = keysToRemove;
    *(_QWORD *)v7 = v5;
    *((_QWORD *)v7 + 1) = v4;
    *((_DWORD *)v7 + 6) = v8;
    *((_QWORD *)v7 + 4) = 0i64;
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
    if ( *(_QWORD *)v7 )
      hkReferencedObject::addReference(*(hkReferencedObject **)v7);
  }
  else
  {
    v7 = 0i64;
  }
  if ( !(unsigned __int8)UFG::ThreadSafeQueue<UFG::BreakoffPart>::IsAlreadyInQueue(
                           &v6->mBreakOffPartsQueue,
                           (UFG::BreakoffPart *)v7) )
  {
    v9 = 0i64;
    v10 = v4->m_collidable.m_shape;
    v11 = v10->m_type.m_storage;
    if ( v11 == 8 )
    {
      if ( ((signed int (*)(void))v10[1].vfptr->__first_virtual_table_function__)() > 1 )
      {
        v9 = *(hkpShape **)(32i64 * (signed int)keysToRemove + *(_QWORD *)&v10[1].m_type.m_storage);
        UFG::Destruction::removeKeysFromListShape((hkpEntity *)&v4->vfptr, &keysToRemove, 1);
LABEL_11:
        if ( array[2] == (array[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, 4);
        *(_DWORD *)(*(_QWORD *)array + 4i64 * (signed int)array[2]++) = keysToRemove;
        goto LABEL_14;
      }
    }
    else if ( v11 == 9 )
    {
      v9 = *(hkpShape **)(32i64 * (signed int)keysToRemove + *(_QWORD *)(v10[2].m_userData + 48));
      *((_QWORD *)v7 + 4) = UFG::Destruction::removeKeysFromListShape((hkpEntity *)&v4->vfptr, &keysToRemove, 1);
      goto LABEL_11;
    }
LABEL_14:
    v12 = 0i64;
    if ( v9 )
    {
      hkpRigidBodyCinfo::hkpRigidBodyCinfo(&bodyInfo);
      bodyInfo.m_shape = v9;
      bodyInfo.m_position = v4->m_motion.m_motionState.m_transform.m_translation;
      bodyInfo.m_rotation = v4->m_motion.m_motionState.m_sweptTransform.m_rotation1;
      *(hkVector4f *)&bodyInfo.m_shape = v4->m_motion.m_linearVelocity;
      *(hkVector4f *)((char *)&bodyInfo.m_position + 8) = v4->m_motion.m_angularVelocity;
      bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_i32[2] = 1092616192;
      LOBYTE(bodyInfo.m_rollingFrictionMultiplier) = 2;
      bodyInfo.m_collisionFilterInfo = 20;
      HIBYTE(bodyInfo.m_rollingFrictionMultiplier) = -1;
      hkpInertiaTensorComputer::setShapeVolumeMassProperties(v9, 10.0, &bodyInfo);
      hkReferencedObject::lockAll();
      v13 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v14 = ++*(_BYTE *)(v13 + 80);
      v15 = v14;
      *(_DWORD *)(v13 + 4 * v15) = 0;
      *(_QWORD *)(v13 + 8 * v15 + 16) = "hkpRigidBody";
      *(_QWORD *)(v13 + 8 * v15 + 48) = 0i64;
      v16 = *(_BYTE *)(v13 + 81);
      if ( v14 > v16 )
        v16 = v14;
      *(_BYTE *)(v13 + 81) = v16;
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 720i64);
      v25 = v18;
      if ( v18 )
      {
        hkpRigidBody::hkpRigidBody(v18, &bodyInfo);
        v12 = v19;
      }
      else
      {
        v12 = 0i64;
      }
      v20 = *(_BYTE *)(v13 + 80);
      if ( v20 > 0 )
      {
        *(_BYTE *)(v13 + 80) = v20 - 1;
      }
      else
      {
        *(_BYTE *)(v13 + 80) = 0;
        *(_DWORD *)v13 = 3;
        *(_QWORD *)(v13 + 16) = 0i64;
        *(_QWORD *)(v13 + 48) = 0i64;
      }
      hkpPhysicsSystem::addRigidBody(v30, v12);
      hkReferencedObject::removeReference((hkReferencedObject *)&v12->vfptr);
      hkReferencedObject::unlockAll();
      if ( (unsigned __int8)(v4->m_motion.m_type.m_storage - 4) <= 1u )
      {
        v22 = _mm_mul_ps((__m128)_xmm_c1200000c1200000c1200000c1200000, *v27);
        hkpEntity::activate((hkpEntity *)&v12->vfptr);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __int64))v12->m_motion.vfptr[11].__first_virtual_table_function__)(
          &v12->m_motion,
          &v22,
          v28);
      }
    }
    *((_QWORD *)v7 + 2) = v12;
    UFG::ThreadSafeQueue<hkpEntity>::AddHead(
      (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&v6->mBreakOffPartsQueue,
      (UFG::CollisionEvent *)v7);
    return;
  }
  if ( v7 )
  {
    hkReferencedObject::removeReference(*((hkReferencedObject **)v7 + 1));
    if ( *(_QWORD *)v7 )
      hkReferencedObject::removeReference(*(hkReferencedObject **)v7);
    v21 = (hkReferencedObject *)*((_QWORD *)v7 + 4);
    if ( v21 )
      hkReferencedObject::removeReference(v21);
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v7);
  }
}

// File Line: 534
// RVA: 0xB6800
hkResult *__fastcall UFG::Destruction::breakOffSubPart(UFG::Destruction *this, hkResult *result, hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent *event, hkArray<unsigned int,hkContainerHeapAllocator> *keysBrokenOffOut, hkpPhysicsSystem *bodiesOut)
{
  __int64 v5; // rbp
  hkArray<unsigned int,hkContainerHeapAllocator> *v6; // r13
  hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent *v7; // r15
  __int64 v8; // rbx
  UFG::Destruction *v9; // rsi
  hkpBreakOffPartsListener::ContactImpulseLimitBreachedEvent::PointInfo *v10; // rdi
  hkVector4f *position; // r14
  unsigned __int16 v12; // ax
  float maxImpulse; // xmm0_4
  hkResult *v14; // rax
  hkpRigidBody *breakingBody; // [rsp+50h] [rbp-48h]
  hkResult *v16; // [rsp+A8h] [rbp+10h]

  v16 = result;
  v5 = event->m_points.m_size;
  v6 = keysBrokenOffOut;
  v7 = event;
  breakingBody = event->m_breakingBody;
  if ( v5 <= 0 )
  {
    result->m_enum = 0;
    v14 = result;
  }
  else
  {
    v8 = 0i64;
    v9 = this;
    do
    {
      v10 = v7->m_points.m_data;
      position = &v10[v8].m_contactPoint->m_position;
      v12 = hkUFloat8::getEncodedFloat(v10[v8].m_properties->m_maxImpulse.m_value);
      if ( v12 )
        LODWORD(maxImpulse) = (v12 + 243712) << 12;
      else
        maxImpulse = 0.0;
      UFG::Destruction::breakOffSubPart(
        v9,
        v10[v8].m_collidingBody,
        breakingBody,
        v10[v8].m_brokenShapeKey,
        maxImpulse,
        position + 1,
        position,
        v6,
        bodiesOut);
      ++v8;
      --v5;
    }
    while ( v5 );
    v16->m_enum = 0;
    v14 = v16;
  }
  return v14;
}

// File Line: 551
// RVA: 0xA87E0
void __fastcall UFG::Destruction::ForceFracture(UFG::Destruction *this, UFG::RigidBody *rbc, hkpPhysicsSystem *bodiesOut, __int64 partIndex)
{
  UFG::CollisionMeshData *v4; // r12
  __int64 v5; // rax
  hkpRigidBody *v6; // rdi
  hkpRigidBody *v7; // r13
  hkpShape *v8; // rsi
  signed int v9; // er14
  int v10; // er15
  signed __int64 v11; // r8
  signed __int64 v12; // r9
  __int64 v13; // rax
  signed __int64 v14; // rcx
  BitArray256 *v15; // rdx
  hkpShape *v16; // rbx
  char v17; // cl
  char v18; // cl
  __int64 v19; // rax
  signed __int64 v20; // rbx
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  _QWORD **v24; // rax
  hkpRigidBody *v25; // rax
  hkpRigidBody *v26; // rax
  char v27; // al
  char v28; // dl
  __int64 v29; // rax
  char v30; // cl
  char v31; // al
  char *v32; // rbx
  unsigned int v33; // eax
  unsigned int keysToRemove; // [rsp+30h] [rbp-98h]
  __int64 v35; // [rsp+38h] [rbp-90h]
  __int64 v36; // [rsp+40h] [rbp-88h]
  hkQuaternionf v37; // [rsp+48h] [rbp-80h]
  hkpRigidBodyCinfo bodyInfo; // [rsp+58h] [rbp-70h]
  hkVector4f v39; // [rsp+138h] [rbp+70h]
  hkTransformf transformOut; // [rsp+148h] [rbp+80h]
  __int64 v41; // [rsp+1E8h] [rbp+120h]
  UFG::RigidBody *v42; // [rsp+1F0h] [rbp+128h]
  hkpPhysicsSystem *v43; // [rsp+1F8h] [rbp+130h]

  *(_QWORD *)&bodyInfo.m_collisionFilterInfo = -2i64;
  v4 = rbc->mCollisionMeshData;
  if ( v4 )
  {
    v5 = v4->mPartDetails.mOffset;
    if ( v5 )
    {
      if ( (UFG::qOffset64<UFG::CollisionMeshData::PartDetails *> *)((char *)&v4->mPartDetails + v5) )
      {
        v6 = 0i64;
        v37.m_vec.m_quad.m128_u64[0] = 0i64;
        v7 = rbc->mBody;
        v8 = v7->m_collidable.m_shape;
        v9 = partIndex;
        if ( (_DWORD)partIndex == -1 )
          v9 = 0;
        if ( (_DWORD)partIndex == -1 )
          LODWORD(partIndex) = v4->mNumParts - 1;
        partIndex = (signed int)partIndex;
        v10 = __ROL4__(1, v9);
        if ( v9 <= (signed __int64)(signed int)partIndex )
        {
          v11 = 96i64 * v9;
          v35 = 96i64 * v9;
          v12 = partIndex - v9 + 1;
          v36 = v12;
          while ( 1 )
          {
            v13 = v4->mPartDetails.mOffset;
            if ( v13 )
              v14 = (signed __int64)&v4->mPartDetails + v13;
            else
              v14 = 0i64;
            if ( *(float *)(v14 + v11 + 68) <= 0.0 )
              goto LABEL_47;
            v15 = rbc->mFractureState;
            if ( !v15 || !(v15->mBits[(unsigned int)v9 >> 5] & v10) )
              break;
LABEL_46:
            rbc = v42;
LABEL_47:
            ++v9;
            v10 = __ROL4__(v10, 1);
            v11 += 96i64;
            v35 = v11;
            v36 = --v12;
            if ( !v12 )
              return;
          }
          keysToRemove = v9;
          v16 = 0i64;
          v17 = v8->m_type.m_storage;
          if ( v17 == 8 )
          {
            if ( ((signed int (*)(void))v8[1].vfptr->__first_virtual_table_function__)() > 1 )
            {
              v16 = *(hkpShape **)(32i64 * (signed int)keysToRemove + *(_QWORD *)&v8[1].m_type.m_storage);
              UFG::Destruction::removeKeysFromListShape((hkpEntity *)&v7->vfptr, &keysToRemove, 1);
            }
          }
          else if ( v17 == 9 )
          {
            v16 = *(hkpShape **)(32i64 * v9 + *(_QWORD *)(v8[2].m_userData + 48));
            v37.m_vec.m_quad.m128_u64[0] = (unsigned __int64)UFG::Destruction::removeKeysFromListShape(
                                                               (hkpEntity *)&v7->vfptr,
                                                               &keysToRemove,
                                                               1);
          }
          if ( !v16 )
          {
LABEL_41:
            v32 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x28ui64, "BreakoffPart", 0i64, 1u);
            v37.m_vec.m_quad.m128_u64[1] = (unsigned __int64)v32;
            if ( v32 )
            {
              v33 = keysToRemove;
              *(_QWORD *)v32 = 0i64;
              *((_QWORD *)v32 + 1) = v7;
              *((_DWORD *)v32 + 6) = v33;
              *((_QWORD *)v32 + 4) = 0i64;
              hkReferencedObject::addReference((hkReferencedObject *)&v7->vfptr);
              if ( *(_QWORD *)v32 )
                hkReferencedObject::addReference(*(hkReferencedObject **)v32);
            }
            else
            {
              v32 = 0i64;
            }
            *((_QWORD *)v32 + 2) = v6;
            *((_QWORD *)v32 + 4) = v37.m_vec.m_quad.m128_u64[0];
            UFG::ThreadSafeQueue<hkpEntity>::AddHead(
              (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)(v41 + 24),
              (UFG::CollisionEvent *)v32);
            v11 = v35;
            v12 = v36;
            v6 = 0i64;
            goto LABEL_46;
          }
          hkpRigidBodyCinfo::hkpRigidBodyCinfo((hkpRigidBodyCinfo *)((char *)&bodyInfo + 8));
          v18 = v8->m_type.m_storage;
          if ( v18 == 9 )
          {
            v19 = *(_QWORD *)(v8[2].m_userData + 48);
          }
          else
          {
            if ( v18 != 8 )
            {
LABEL_27:
              hkTransformf::setMul(
                (hkTransformf *)&bodyInfo.m_maxAngularVelocity,
                &v7->m_motion.m_motionState.m_transform,
                &transformOut);
              hkQuaternionf::set(&v37, (hkRotationf *)&bodyInfo.m_maxAngularVelocity);
              *(hkVector4f *)((char *)&bodyInfo.m_position + 8) = (hkVector4f)v39.m_quad;
              bodyInfo.m_position.m_quad.m128_u64[0] = (unsigned __int64)v16;
              *(hkVector4f *)&bodyInfo.m_collisionFilterInfo = v7->m_motion.m_linearVelocity;
              bodyInfo.m_position = v7->m_motion.m_angularVelocity;
              bodyInfo.m_inertiaTensor.m_col1.m_quad.m128_i32[0] = 1092616192;
              LOBYTE(bodyInfo.m_gravityFactor) = 2;
              LODWORD(bodyInfo.m_shape) = 20;
              HIBYTE(bodyInfo.m_gravityFactor) = -1;
              hkpInertiaTensorComputer::setShapeVolumeMassProperties(
                v16,
                10.0,
                (hkpRigidBodyCinfo *)((char *)&bodyInfo + 8));
              v20 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
              v21 = ++*(_BYTE *)(v20 + 80);
              v22 = v21;
              *(_DWORD *)(v20 + 4 * v22) = 0;
              *(_QWORD *)(v20 + 8 * v22 + 16) = "hkpRigidBody";
              *(_QWORD *)(v20 + 8 * v22 + 48) = 0i64;
              v23 = *(_BYTE *)(v20 + 81);
              if ( v21 > v23 )
                v23 = v21;
              *(_BYTE *)(v20 + 81) = v23;
              v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v25 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(
                                      v24[11],
                                      720i64);
              v37.m_vec.m_quad.m128_u64[1] = (unsigned __int64)v25;
              if ( v25 )
              {
                hkpRigidBody::hkpRigidBody(v25, (hkpRigidBodyCinfo *)((char *)&bodyInfo + 8));
                v6 = v26;
              }
              else
              {
                v6 = 0i64;
              }
              v27 = *(_BYTE *)(v20 + 80);
              if ( v27 > 0 )
              {
                *(_BYTE *)(v20 + 80) = v27 - 1;
              }
              else
              {
                *(_BYTE *)(v20 + 80) = 0;
                *(_DWORD *)v20 = 3;
                *(_QWORD *)(v20 + 16) = 0i64;
                *(_QWORD *)(v20 + 48) = 0i64;
              }
              v28 = ++*(_BYTE *)(v20 + 80);
              v29 = v28;
              *(_DWORD *)(v20 + 4 * v29) = 3;
              *(_QWORD *)(v20 + 8 * v29 + 16) = "setName";
              *(_QWORD *)(v20 + 8 * v29 + 48) = 0i64;
              v30 = *(_BYTE *)(v20 + 81);
              if ( v28 > v30 )
                v30 = v28;
              *(_BYTE *)(v20 + 81) = v30;
              hkStringPtr::operator=(&v6->m_name, "tmpDestructionBase2");
              v31 = *(_BYTE *)(v20 + 80);
              if ( v31 > 0 )
              {
                *(_BYTE *)(v20 + 80) = v31 - 1;
              }
              else
              {
                *(_BYTE *)(v20 + 80) = 0;
                *(_DWORD *)v20 = 3;
                *(_QWORD *)(v20 + 16) = 0i64;
                *(_QWORD *)(v20 + 48) = 0i64;
              }
              hkpWorld::addEntity(
                UFG::BasePhysicsSystem::mInstance->mWorld,
                (hkpEntity *)&v6->vfptr,
                HK_ENTITY_ACTIVATION_DO_ACTIVATE);
              hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
              hkpPhysicsSystem::addRigidBody(v43, v6);
              goto LABEL_41;
            }
            v19 = *(_QWORD *)&v8[1].m_type.m_storage;
          }
          hkQsTransformf::copyToTransformNoScale(
            (hkQsTransformf *)(*(_QWORD *)(32i64 * (signed int)keysToRemove + v19) + 64i64),
            &transformOut);
          goto LABEL_27;
        }
      }
    }
  }
}

// File Line: 648
// RVA: 0xAFB90
void __fastcall UFG::Destruction::RemovePart(UFG::Destruction *this, UFG::RigidBody *rbc, int partIndex)
{
  unsigned int v3; // ebp
  UFG::RigidBody *v4; // rdi
  UFG::CollisionMeshData *v5; // rax
  __int64 v6; // rcx
  signed __int64 v7; // rdx
  hkpRemoveTerminalsMoppModifier *v8; // r14
  hkpEntity *v9; // rsi
  hkpShape *v10; // r9
  BitArray256 *v11; // r8
  __int64 v12; // rax
  char v13; // cl
  char *v14; // rbx
  unsigned int v15; // eax
  signed __int64 v16; // r10
  UFG::CollisionInstanceData *v17; // r8
  unsigned int v18; // ecx
  __int64 v19; // r9
  hkReferencedObject *v20; // rcx
  unsigned int keysToRemove; // [rsp+68h] [rbp+10h]
  char *v22; // [rsp+78h] [rbp+20h]

  v3 = partIndex;
  v4 = rbc;
  v5 = rbc->mCollisionMeshData;
  if ( v5 )
  {
    v6 = v5->mPartDetails.mOffset;
    if ( v6 )
    {
      v7 = (signed __int64)&v5->mPartDetails + v6;
      if ( v7 )
      {
        v8 = 0i64;
        v9 = (hkpEntity *)&v4->mBody->vfptr;
        v10 = v9->m_collidable.m_shape;
        if ( *(float *)(v7 + 96i64 * partIndex + 68) > 0.0 )
        {
          v11 = v4->mFractureState;
          if ( !v11 || (v12 = v3 >> 5, (v7 = v11->mBits[v12] & (1 << (v3 & 0x1F))) == 0) )
          {
            keysToRemove = v3;
            v13 = v10->m_type.m_storage;
            if ( v13 == 8 )
            {
              if ( ((signed int (__fastcall *)(hkpShape *, signed __int64))v10[1].vfptr->__first_virtual_table_function__)(
                     &v10[1],
                     v7) > 1 )
                UFG::Destruction::removeKeysFromListShape(v9, &keysToRemove, 1);
            }
            else if ( v13 == 9 )
            {
              v8 = UFG::Destruction::removeKeysFromListShape(v9, &keysToRemove, 1);
            }
            v14 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x28ui64, "BreakoffPart", 0i64, 1u);
            v22 = v14;
            if ( v14 )
            {
              v15 = keysToRemove;
              *(_QWORD *)v14 = 0i64;
              *((_QWORD *)v14 + 1) = v9;
              *((_DWORD *)v14 + 6) = v15;
              *((_QWORD *)v14 + 4) = 0i64;
              hkReferencedObject::addReference((hkReferencedObject *)&v9->vfptr);
              if ( *(_QWORD *)v14 )
                hkReferencedObject::addReference(*(hkReferencedObject **)v14);
            }
            else
            {
              v14 = 0i64;
            }
            *((_QWORD *)v14 + 2) = 0i64;
            *((_QWORD *)v14 + 4) = v8;
            v16 = UFG::CollisionMeshData::GetPartDetails(v4->mCollisionMeshData, v3);
            v17 = v4->mInstanceData;
            v18 = *((_DWORD *)v14 + 6);
            if ( v18 >= v17->mNumParts || (v19 = v17->mParts[v18].mInstanceUid, !(_DWORD)v19) )
              v19 = v17->mInstanceGuid;
            ((void (__fastcall *)(UFG::RigidBody *, char *, signed __int64, __int64))v4->vfptr[14].__vecDelDtor)(
              v4,
              v14,
              v16,
              v19);
            hkReferencedObject::removeReference(*((hkReferencedObject **)v14 + 1));
            if ( *(_QWORD *)v14 )
              hkReferencedObject::removeReference(*(hkReferencedObject **)v14);
            v20 = (hkReferencedObject *)*((_QWORD *)v14 + 4);
            if ( v20 )
              hkReferencedObject::removeReference(v20);
            UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v14);
          }
        }
      }
    }
  }
}

// File Line: 720
// RVA: 0x98960
void __fastcall UFG::DestructionEvent::DestructionEvent(UFG::DestructionEvent *this, UFG::SimComponent *collidingComponent, UFG::RigidBody *breakingBody, unsigned int instanceGuid)
{
  unsigned int v4; // ebx
  UFG::RigidBody *v5; // r15
  UFG::SimComponent *v6; // rbp
  UFG::DestructionEvent *v7; // r14
  unsigned int v8; // er10
  UFG::qNode<UFG::Event,UFG::Event> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v10; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v11; // rdi
  UFG::CollisionMeshData *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  v4 = instanceGuid;
  v5 = breakingBody;
  v6 = collidingComponent;
  v7 = this;
  v8 = UFG::gDestructionEventChannel.mUID;
  v9 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_EventUID = v8;
  this->m_NamePTR = 0i64;
  this->vfptr = (UFG::EventVtbl *)&UFG::DestructionEvent::`vftable';
  v10 = &this->mCollidingComponent;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  this->mCollidingComponent.m_pPointer = 0i64;
  v11 = &this->mBreakingBody;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  this->mBreakingBody.m_pPointer = 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->objectProperty.mPrev);
  v7->objectProperty.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v7->instanceUid = v4;
  v12 = v5->mCollisionMeshData;
  if ( v12 )
    UFG::qReflectHandleBase::operator=(
      (UFG::qReflectHandleBase *)&v7->objectProperty.mPrev,
      (UFG::qReflectHandleBase *)&v12->mObjectProperties.mPrev);
  if ( v7->mCollidingComponent.m_pPointer )
  {
    v13 = v10->mPrev;
    v14 = v7->mCollidingComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v7->mCollidingComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mCollidingComponent.mPrev;
  }
  v7->mCollidingComponent.m_pPointer = v6;
  if ( v6 )
  {
    v15 = v6->m_SafePointerList.mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v10->mPrev = v15;
    v7->mCollidingComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  }
  if ( v7->mBreakingBody.m_pPointer )
  {
    v16 = v11->mPrev;
    v17 = v7->mBreakingBody.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v7->mBreakingBody.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mBreakingBody.mPrev;
  }
  v7->mBreakingBody.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  v18 = v5->m_SafePointerList.mNode.mPrev;
  v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mPrev = v18;
  v7->mBreakingBody.mNext = &v5->m_SafePointerList.mNode;
  v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)&v7->vfptr);
}

// File Line: 784
// RVA: 0x9C490
void __fastcall UFG::FractureConnectivity::~FractureConnectivity(UFG::FractureConnectivity *this)
{
  UFG::FractureConnectivity *v1; // rbx
  UFG::FractureConnectivity::Node **v2; // rcx

  v1 = this;
  v2 = this->mNodes.p;
  if ( v2 )
    operator delete[](v2);
  v1->mNodes.p = 0i64;
  *(_QWORD *)&v1->mNodes.size = 0i64;
}

// File Line: 790
// RVA: 0xA1100
void __fastcall UFG::FractureConnectivity::Build(UFG::FractureConnectivity *this, UFG::CollisionMeshData *mesh)
{
  UFG::CollisionMeshData *v2; // r13
  UFG::FractureConnectivity *v3; // rdi
  unsigned int v4; // er12
  unsigned int v5; // er13
  char *v6; // rax
  char *v7; // r14
  __int64 v8; // r15
  unsigned int v9; // esi
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  char *v13; // rax
  char *v14; // rbp
  __int64 v15; // r9
  __int64 v16; // rax
  signed __int64 v17; // r14
  __int64 v18; // rbx
  __int64 v19; // rsi
  __int64 v20; // rbp
  char *v21; // rax
  char *v22; // r8
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *v23; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v24; // rax
  char *v25; // rax
  char *v26; // r8
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0> *v27; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v28; // rax
  UFG::CollisionMeshData *v29; // [rsp+78h] [rbp+10h]
  _QWORD *v30; // [rsp+88h] [rbp+20h]

  v29 = mesh;
  v2 = mesh;
  v3 = this;
  v4 = 0;
  if ( mesh->mNumParts )
  {
    v5 = mesh->mNumParts;
    do
    {
      v6 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v7 = v6;
      if ( v6 )
      {
        *(_DWORD *)v6 = v4;
        *((_DWORD *)v6 + 1) = -1;
        v30 = v6 + 8;
        *v30 = v30;
        v30[1] = v30;
      }
      else
      {
        v7 = 0i64;
      }
      v8 = v3->mNodes.size;
      v9 = v8 + 1;
      v10 = v3->mNodes.capacity;
      if ( (signed int)v8 + 1 > v10 )
      {
        if ( v10 )
          v11 = 2 * v10;
        else
          v11 = 1;
        for ( ; v11 < v9; v11 *= 2 )
          ;
        if ( v11 <= 2 )
          v11 = 2;
        if ( v11 - v9 > 0x10000 )
          v11 = v8 + 65537;
        if ( v11 != (_DWORD)v8 )
        {
          v12 = 8i64 * v11;
          if ( !is_mul_ok(v11, 8ui64) )
            v12 = -1i64;
          v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
          v14 = v13;
          if ( v3->mNodes.p )
          {
            v15 = 0i64;
            if ( v3->mNodes.size )
            {
              do
              {
                *(_QWORD *)&v13[8 * v15] = v3->mNodes.p[v15];
                v15 = (unsigned int)(v15 + 1);
              }
              while ( (unsigned int)v15 < v3->mNodes.size );
            }
            operator delete[](v3->mNodes.p);
          }
          v3->mNodes.p = (UFG::FractureConnectivity::Node **)v14;
          v3->mNodes.capacity = v11;
        }
      }
      v3->mNodes.size = v9;
      v3->mNodes.p[v8] = (UFG::FractureConnectivity::Node *)v7;
      ++v4;
    }
    while ( v4 < v5 );
    v2 = v29;
  }
  v16 = v2->mFractureConnections.mOffset;
  if ( v16 )
    v17 = (signed __int64)&v2->mFractureConnections + v16;
  else
    v17 = 0i64;
  v18 = 0i64;
  if ( v2->mNumFractureConnections )
  {
    do
    {
      v19 = *(unsigned int *)(v17 + 8 * v18);
      v20 = *(unsigned int *)(v17 + 8 * v18 + 4);
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
      v23 = &v3->mNodes.p[v20]->adjacencyList;
      v24 = v23->mNode.mPrev;
      v24->mNext = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v22;
      *(_QWORD *)v22 = v24;
      *((_QWORD *)v22 + 1) = v23;
      v23->mNode.mPrev = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v22;
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
      v27 = &v3->mNodes.p[v19]->adjacencyList;
      v28 = v27->mNode.mPrev;
      v28->mNext = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v26;
      *(_QWORD *)v26 = v28;
      *((_QWORD *)v26 + 1) = v27;
      v27->mNode.mPrev = (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v26;
      v18 = (unsigned int)(v18 + 1);
    }
    while ( (unsigned int)v18 < v2->mNumFractureConnections );
  }
  UFG::FractureConnectivity::ComputeNodeColors(v3);
}

// File Line: 883
// RVA: 0xA6C10
void __fastcall UFG::FractureConnectivity::DeleteNodeByPartIndex(UFG::FractureConnectivity *this, unsigned int partIndex)
{
  UFG::FractureConnectivity *v2; // r15
  __int64 v3; // rbp
  int v4; // ebx
  unsigned int v5; // er8
  UFG::FractureConnectivity::Node **v6; // r9
  int v7; // er14
  UFG::FractureConnectivity::Node **v8; // rdx
  UFG::FractureConnectivity::Node *v9; // r13
  signed __int64 v10; // rsi
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v11; // rax
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v12; // rdi
  int v13; // ecx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v14; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v15; // rcx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v16; // rdx
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v17; // rax

  v2 = this;
  this->mColorsDirty = 1;
  v3 = 0i64;
  v4 = 0;
  v5 = this->mNodes.size;
  if ( this->mNodes.size )
  {
    v6 = this->mNodes.p;
    while ( v6[v4]->partIdx != partIndex )
    {
      if ( ++v4 >= v5 )
        return;
    }
    if ( v4 != -1 )
    {
      v7 = v5 - 1;
      v8 = &v6[v4];
      v9 = *v8;
      *v8 = v6[v5 - 1];
      if ( this->mNodes.size > 1 )
        --this->mNodes.size;
      else
        this->mNodes.size = 0;
      if ( this->mNodes.size > 0 )
      {
        do
        {
          v10 = (signed __int64)&v2->mNodes.p[v3]->adjacencyList;
          v11 = v2->mNodes.p[v3]->adjacencyList.mNode.mNext;
          if ( v11 != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v10 )
          {
            do
            {
              v12 = v11->mNext;
              v13 = (int)v11[1].mPrev;
              if ( v13 == v4 )
              {
                v14 = v11->mPrev;
                v15 = v11->mNext;
                v14->mNext = v15;
                v15->mPrev = v14;
                v11->mPrev = v11;
                v11->mNext = v11;
                operator delete[](v11);
              }
              else if ( v13 == v7 )
              {
                LODWORD(v11[1].mPrev) = v4;
              }
              v11 = v12;
            }
            while ( v12 != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v10 );
          }
          v3 = (unsigned int)(v3 + 1);
        }
        while ( (unsigned int)v3 < v2->mNodes.size );
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
  UFG::FractureConnectivity *v2; // rbx
  unsigned int v3; // edx
  __int64 v4; // rcx
  UFG::FractureConnectivity::Node *v5; // rcx
  int v6; // er14
  UFG::FractureConnectivity::Node *v7; // rsi
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v8; // rdi
  signed __int64 i; // rsi
  __int64 result; // rax

  v1 = 0i64;
  v2 = this;
  this->mColorsDirty = 1;
  v3 = 0;
  if ( this->mNodes.size )
  {
    do
    {
      v4 = v3++;
      v2->mNodes.p[v4]->color = -1;
    }
    while ( v3 < v2->mNodes.size );
  }
  v2->mNumColors = 0;
  if ( v2->mNodes.size <= 0 )
  {
    v2->mColorsDirty = 0;
    result = 0i64;
  }
  else
  {
    do
    {
      v5 = v2->mNodes.p[v1];
      if ( v5->color == -1 )
      {
        v6 = v2->mNumColors;
        v5->color = v6;
        v7 = v2->mNodes.p[v1];
        v8 = v7->adjacencyList.mNode.mNext;
        for ( i = (signed __int64)&v7->adjacencyList;
              v8 != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)i;
              v8 = v8->mNext )
        {
          UFG::FractureConnectivity::ColorNodeAndAdjacent(v2, (unsigned int)v8[1].mPrev, v6);
        }
        ++v2->mNumColors;
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->mNodes.size );
    result = (unsigned int)v2->mNumColors;
    v2->mColorsDirty = 0;
  }
  return result;
}

// File Line: 968
// RVA: 0xA27B0
void __fastcall UFG::FractureConnectivity::ColorNodeAndAdjacent(UFG::FractureConnectivity *this, unsigned int nodeIdx, int color)
{
  UFG::FractureConnectivity *v3; // rsi
  int v4; // ebp
  __int64 v5; // rdi
  UFG::FractureConnectivity::Node *v6; // rcx
  UFG::FractureConnectivity::Node *v7; // rdi
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v8; // rbx
  signed __int64 i; // rdi

  v3 = this;
  v4 = color;
  v5 = nodeIdx;
  v6 = this->mNodes.p[v5];
  if ( v6->color == -1 )
  {
    v6->color = color;
    v7 = v3->mNodes.p[v5];
    v8 = v7->adjacencyList.mNode.mNext;
    for ( i = (signed __int64)&v7->adjacencyList;
          v8 != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)i;
          v8 = v8->mNext )
    {
      UFG::FractureConnectivity::ColorNodeAndAdjacent(v3, (unsigned int)v8[1].mPrev, v4);
    }
  }
}

// File Line: 987
// RVA: 0xA7FC0
void __fastcall UFG::FractureConnectivity::ExtractSubGraphs(UFG::FractureConnectivity *this, UFG::qArray<UFG::FractureConnectivity *,0> *subGraphs)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // r13
  UFG::FractureConnectivity *v3; // rbx
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // rax
  char *v6; // rsi
  int v7; // er14
  char *v8; // rax
  char *v9; // rdi
  __int64 v10; // rbp
  unsigned int v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // edx
  __int64 v14; // r12
  char *v15; // r15
  signed __int64 v16; // rdi
  char *v17; // rax
  char *v18; // r14
  UFG::FractureConnectivity::Node *v19; // rdx
  _QWORD *v20; // ST38_8
  UFG::qReflectInventoryBase *v21; // rdi
  __int64 v22; // r13
  unsigned int v23; // ebp
  unsigned int v24; // ebx
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  char *v27; // rax
  char *v28; // r15
  __int64 v29; // r9
  UFG::FractureConnectivity::Node **v30; // rax
  signed __int64 v31; // rbp
  UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *v32; // rbx
  char **v33; // rdi
  char *v34; // rax
  char *v35; // rdx
  int v36; // ecx
  char *v37; // rax
  bool v38; // zf
  __int64 v39; // r11
  UFG::qReflectInventoryBase *v40; // r10
  __int64 v41; // r9
  signed __int64 v42; // r8
  __int64 i; // rax
  UFG::FractureConnectivity *v44; // [rsp+90h] [rbp+8h]
  UFG::qArray<UFG::FractureConnectivity *,0> *v45; // [rsp+98h] [rbp+10h]
  char *v46; // [rsp+A0h] [rbp+18h]
  __int64 v47; // [rsp+A8h] [rbp+20h]

  v45 = subGraphs;
  v44 = this;
  v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)subGraphs;
  v3 = this;
  v4 = this->mNodes.size;
  if ( (unsigned int)v4 > 1 && this->mNumColors > 1 )
  {
    v47 = this->mNodes.size;
    v5 = 4 * v4;
    if ( !is_mul_ok(v4, 4ui64) )
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
        v12 = v2->capacity;
        if ( (signed int)v10 + 1 > v12 )
        {
          if ( v12 )
            v13 = 2 * v12;
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
        v3 = v44;
      }
      while ( v7 < v44->mNumColors );
    }
    if ( (_DWORD)v4 )
    {
      v14 = 0i64;
      v15 = v6;
      v46 = v6;
      do
      {
        v16 = (unsigned int)v3->mNodes.p[v14]->color;
        *(_DWORD *)v15 = v2->p[v16]->vfptr;
        v17 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
        v18 = v17;
        if ( v17 )
        {
          v19 = v3->mNodes.p[v14];
          *(_DWORD *)v17 = v19->partIdx;
          *((_DWORD *)v17 + 1) = v19->color;
          v20 = v17 + 8;
          *v20 = v20;
          v20[1] = v20;
        }
        else
        {
          v18 = 0i64;
        }
        v21 = v2->p[v16];
        v22 = LODWORD(v21->vfptr);
        v23 = v22 + 1;
        v24 = HIDWORD(v21->vfptr);
        if ( (signed int)v22 + 1 > v24 )
        {
          if ( v24 )
            v25 = 2 * v24;
          else
            v25 = 1;
          for ( ; v25 < v23; v25 *= 2 )
            ;
          if ( v25 <= 2 )
            v25 = 2;
          if ( v25 - v23 > 0x10000 )
            v25 = v22 + 65537;
          if ( v25 != (_DWORD)v22 )
          {
            v26 = 8i64 * v25;
            if ( !is_mul_ok(v25, 8ui64) )
              v26 = -1i64;
            v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
            v28 = v27;
            if ( v21->mBaseNode.mUID )
            {
              v29 = 0i64;
              if ( LODWORD(v21->vfptr) )
              {
                do
                {
                  *(_QWORD *)&v27[8 * v29] = *(_QWORD *)(8 * v29 + v21->mBaseNode.mUID);
                  v29 = (unsigned int)(v29 + 1);
                }
                while ( (unsigned int)v29 < LODWORD(v21->vfptr) );
              }
              operator delete[]((void *)v21->mBaseNode.mUID);
            }
            v21->mBaseNode.mUID = (unsigned __int64)v28;
            HIDWORD(v21->vfptr) = v25;
            v15 = v46;
          }
        }
        LODWORD(v21->vfptr) = v23;
        *(_QWORD *)(v21->mBaseNode.mUID + 8 * v22) = v18;
        v30 = v44->mNodes.p;
        v31 = (signed __int64)&v30[v14]->adjacencyList;
        v32 = v30[v14]->adjacencyList.mNode.mNext;
        if ( v32 != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v31 )
        {
          v33 = (char **)(v18 + 8);
          do
          {
            v34 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
            v35 = v34;
            if ( v34 )
            {
              v36 = (int)v32[1].mPrev;
              *(_QWORD *)v34 = v34;
              *((_QWORD *)v34 + 1) = v34;
              *((_DWORD *)v34 + 4) = v36;
            }
            else
            {
              v35 = 0i64;
            }
            v37 = *v33;
            *((_QWORD *)v37 + 1) = v35;
            *(_QWORD *)v35 = v37;
            *((_QWORD *)v35 + 1) = v33;
            *v33 = v35;
            v32 = v32->mNext;
          }
          while ( v32 != (UFG::qNode<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection> *)v31 );
        }
        v15 += 4;
        v46 = v15;
        ++v14;
        v38 = v47-- == 1;
        v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v45;
        v3 = v44;
      }
      while ( !v38 );
    }
    v39 = 0i64;
    if ( v2->size )
    {
      do
      {
        v40 = v2->p[v39];
        v41 = 0i64;
        if ( LODWORD(v40->vfptr) )
        {
          do
          {
            v42 = *(_QWORD *)(v40->mBaseNode.mUID + 8 * v41) + 8i64;
            for ( i = *(_QWORD *)(*(_QWORD *)(v40->mBaseNode.mUID + 8 * v41) + 16i64); i != v42; i = *(_QWORD *)(i + 8) )
              *(_DWORD *)(i + 16) = *(_DWORD *)&v6[4 * *(unsigned int *)(i + 16)];
            v41 = (unsigned int)(v41 + 1);
          }
          while ( (unsigned int)v41 < LODWORD(v40->vfptr) );
        }
        LODWORD(v40->mBaseNode.mParent) = 1;
        BYTE4(v40->mBaseNode.mParent) = 0;
        v39 = (unsigned int)(v39 + 1);
      }
      while ( (unsigned int)v39 < v2->size );
    }
    operator delete[](v6);
  }
}

