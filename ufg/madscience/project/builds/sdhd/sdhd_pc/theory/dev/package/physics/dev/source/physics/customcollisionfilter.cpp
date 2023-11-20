// File Line: 30
// RVA: 0x98660
void __fastcall UFG::CustomCollisionFilter::CustomCollisionFilter(UFG::CustomCollisionFilter *this)
{
  UFG::CustomCollisionFilter *v1; // rbx
  char *v2; // rdi
  unsigned int v3; // eax
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // kr00_8
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  hkpGroupFilter::hkpGroupFilter((hkpGroupFilter *)&this->vfptr);
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkReferencedObject'};
  v1->vfptr = (hkpCollidableCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  v1->vfptr = (hkpShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
  v1->vfptr = (hkpRayShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  v1->vfptr = (hkpRayCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  v1->vfptr = (hkpEntityListenerVtbl *)&UFG::CustomCollisionFilter::`vftable';
  v6 = &v1->mNonCollidable;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v2 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
  if ( v2 )
  {
    v3 = stack_size;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = v3;
    v5 = v3;
    v4 = 4i64 * v3;
    if ( !is_mul_ok(v5, 4ui64) )
      v4 = -1i64;
    *((_QWORD *)v2 + 1) = UFG::qMalloc(v4, "Stack", 0i64);
  }
  else
  {
    v2 = 0i64;
  }
  v1->mAssignedSystemGroups = (UFG::Stack *)v2;
  UFG::CustomCollisionFilter::ResetState(v1);
}

// File Line: 39
// RVA: 0x9BFE0
void __fastcall UFG::CustomCollisionFilter::~CustomCollisionFilter(UFG::CustomCollisionFilter *this)
{
  UFG::CustomCollisionFilter *v1; // rdi
  UFG::Stack *v2; // rbx
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *v3; // rbx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v4; // rdx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v5; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v6; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v7; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v8; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v9; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v10; // rax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpCollidableCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
  this->vfptr = (hkpShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
  this->vfptr = (hkpRayShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
  this->vfptr = (hkpRayCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  this->vfptr = (hkpEntityListenerVtbl *)&UFG::CustomCollisionFilter::`vftable';
  v2 = this->mAssignedSystemGroups;
  if ( v2 )
  {
    operator delete[](v2->mBuffer);
    operator delete[](v2);
  }
  v3 = &v1->mNonCollidable;
  while ( (UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *)v1->mNonCollidable.mNode.mNext != &v1->mNonCollidable )
  {
    v4 = v1->mNonCollidable.mNode.mNext;
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    v4->mNext = v4;
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = v4;
    v4->mNext = v4;
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v4);
  }
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0>::DeleteNodes(&v1->mNonCollidable);
  v9 = v3->mNode.mPrev;
  v10 = v1->mNonCollidable.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v3->mNode.mPrev = &v3->mNode;
  v1->mNonCollidable.mNode.mNext = &v1->mNonCollidable.mNode;
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable';
  hkpGroupFilter::~hkpGroupFilter((hkpGroupFilter *)&v1->vfptr);
}

// File Line: 52
// RVA: 0xB0210
void __fastcall UFG::CustomCollisionFilter::ResetState(UFG::CustomCollisionFilter *this)
{
  UFG::CustomCollisionFilter *v1; // rbx
  signed __int16 v2; // r8
  int v3; // er10
  signed int v4; // er9
  UFG::Stack *v5; // rdx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v6; // rdx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v7; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v8; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v9; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v10; // rax

  v1 = this;
  this->mAssignedSystemGroups->mHead = 0;
  v2 = 1;
  v3 = stack_size + 1;
  if ( v3 > 1 )
  {
    v4 = 1;
    do
    {
      v5 = this->mAssignedSystemGroups;
      v5->mBuffer[v5->mHead++] = v4;
      v4 = ++v2;
    }
    while ( v2 < v3 );
  }
  if ( (UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *)this->mNonCollidable.mNode.mNext != &this->mNonCollidable )
  {
    do
    {
      v6 = v1->mNonCollidable.mNode.mNext;
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = v6;
      v6->mNext = v6;
      v9 = v6->mPrev;
      v10 = v6->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v6->mPrev = v6;
      v6->mNext = v6;
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v6);
    }
    while ( (UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *)v1->mNonCollidable.mNode.mNext != &v1->mNonCollidable );
  }
}

// File Line: 85
// RVA: 0xB81E0
hkBool *__fastcall UFG::CustomCollisionFilter::isCollisionEnabled(UFG::CustomCollisionFilter *this, hkBool *result, hkpCollidable *a, hkpCollidable *b)
{
  hkpEntityListenerVtbl *v4; // rax
  hkBool *v5; // rbx
  hkpCollidable *v6; // r11
  hkpCollidable *v7; // r10
  hkBool *v8; // rax
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v4 = this->vfptr;
  v5 = result;
  if ( v4 == (hkpEntityListenerVtbl *)&this->m_pad256[3].m_quad.m128_u16[4] )
  {
LABEL_8:
    result->m_bool = hkpGroupFilter::isCollisionEnabled((hkpGroupFilter *)&this->vfptr, &resulta, a, b)->m_bool != 0;
    v8 = v5;
  }
  else
  {
    v6 = (hkpCollidable *)((char *)a + a->m_ownerOffset);
    while ( 1 )
    {
      v7 = (hkpCollidable *)v4->entityRemovedCallback;
      if ( v6 == v7 && (char *)b + b->m_ownerOffset == (char *)v4->entityShapeSetCallback )
        break;
      if ( (hkpCollidable *)((char *)b + b->m_ownerOffset) == v7 && v6 == (hkpCollidable *)v4->entityShapeSetCallback )
        break;
      v4 = (hkpEntityListenerVtbl *)v4->entityAddedCallback;
      if ( v4 == (hkpEntityListenerVtbl *)&this->m_pad256[3].m_quad.m128_u16[4] )
        goto LABEL_8;
    }
    result->m_bool = 0;
    v8 = result;
  }
  return v8;
}

// File Line: 105
// RVA: 0xA7290
void __fastcall UFG::CustomCollisionFilter::DisableCollisionsBetween(UFG::CustomCollisionFilter *this, hkpEntity *entityA, hkpEntity *entityB)
{
  hkpEntity *v3; // rdi
  hkpEntity *v4; // rsi
  UFG::CustomCollisionFilter *v5; // r14
  bool v6; // r9
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v7; // rax
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *v8; // rbp
  char *v9; // rax
  char *v10; // rcx
  signed int v11; // ebx
  _QWORD *v12; // rax
  hkpEntityListener *v13; // rbp
  hkSmallArray<hkpEntityListener *> *v14; // rax
  signed int v15; // ecx
  signed int v16; // edx
  hkpEntityListener **v17; // rax
  bool v18; // r14
  hkSmallArray<hkpEntityListener *> *v19; // rax
  signed int v20; // ecx
  hkpEntityListener **v21; // rax
  bool v22; // bl
  hkpWorld *v23; // rcx
  hkpWorld *v24; // rcx

  if ( entityB )
  {
    v3 = entityB;
    v4 = entityA;
    v5 = this;
    v6 = 0;
    v7 = this->mNonCollidable.mNode.mNext;
    v8 = &this->mNonCollidable;
    if ( v7 == (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)&this->mNonCollidable )
    {
LABEL_10:
      v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "FilterNode", 0i64, 1u);
      v10 = v9;
      v11 = 0;
      if ( v9 )
      {
        *(_QWORD *)v9 = v9;
        *((_QWORD *)v9 + 1) = v9;
      }
      else
      {
        v10 = 0i64;
      }
      *((_QWORD *)v10 + 2) = v4;
      *((_QWORD *)v10 + 3) = v3;
      v12 = &v8->mNode.mNext->mPrev;
      v8->mNode.mNext = (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)v10;
      *(_QWORD *)v10 = v8;
      *((_QWORD *)v10 + 1) = v12;
      *v12 = v10;
      v13 = (hkpEntityListener *)&v5->vfptr;
      v14 = hkpEntity::getEntityListeners(v4);
      v15 = 0;
      v16 = v14->m_size;
      if ( v16 <= 0 )
      {
LABEL_17:
        v15 = -1;
      }
      else
      {
        v17 = v14->m_data;
        while ( *v17 != v13 )
        {
          ++v15;
          ++v17;
          if ( v15 >= v16 )
            goto LABEL_17;
        }
      }
      v18 = v15 >= 0;
      v19 = hkpEntity::getEntityListeners(v3);
      v20 = v19->m_size;
      if ( v20 <= 0 )
      {
LABEL_22:
        v11 = -1;
      }
      else
      {
        v21 = v19->m_data;
        while ( *v21 != v13 )
        {
          ++v11;
          ++v21;
          if ( v11 >= v20 )
            goto LABEL_22;
        }
      }
      v22 = v11 >= 0;
      v23 = v4->m_world;
      if ( v23 && !v18 )
        hkpWorld::updateCollisionFilterOnEntity(
          v23,
          v4,
          HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      v24 = v3->m_world;
      if ( v24 && !v22 )
        hkpWorld::updateCollisionFilterOnEntity(
          v24,
          v3,
          HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      if ( !v18 )
        hkpEntity::addEntityListener(v4, v13);
      if ( !v22 )
        hkpEntity::addEntityListener(v3, v13);
    }
    else
    {
      while ( !v6 )
      {
        v6 = *(_OWORD *)&v7[1] == __PAIR__((unsigned __int64)entityB, (unsigned __int64)entityA)
          || __PAIR__(v7[1].mPrev, (unsigned __int64)entityA) == __PAIR__((unsigned __int64)entityB, v7[1].mNext);
        v7 = v7->mNext;
        if ( v7 == (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)v8 )
        {
          if ( v6 )
            return;
          goto LABEL_10;
        }
      }
    }
  }
}

// File Line: 162
// RVA: 0xAE550
char __fastcall UFG::CustomCollisionFilter::ReenableCollisionsBetween(UFG::CustomCollisionFilter *this, hkpEntity *entityA, hkpEntity *entityB)
{
  hkpEntity *v3; // rdi
  hkpEntity *v4; // rsi
  UFG::CustomCollisionFilter *v5; // rbp
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v7; // rdx
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *v8; // rcx
  hkpEntity *v9; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v10; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v11; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v12; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v13; // rax
  hkpEntityListener *v14; // rbp
  hkSmallArray<hkpEntityListener *> *v15; // rax
  signed int v16; // ebx
  signed int v17; // ecx
  signed int v18; // edx
  hkpEntityListener **v19; // rax
  bool v20; // r14
  hkSmallArray<hkpEntityListener *> *v21; // rax
  signed int v22; // ecx
  hkpEntityListener **v23; // rax
  bool v24; // bl
  hkpWorld *v25; // rcx
  hkpWorld *v26; // rcx

  v3 = entityB;
  v4 = entityA;
  v5 = this;
  if ( !entityB )
    return 0;
  v7 = this->mNonCollidable.mNode.mNext;
  v8 = &this->mNonCollidable;
  while ( v7 != (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)v8 )
  {
    v9 = (hkpEntity *)v7[1].mPrev;
    if ( v9 == v4 && (hkpEntity *)v7[1].mNext == entityB || v9 == entityB && (hkpEntity *)v7[1].mNext == v4 )
    {
      v10 = v7->mPrev;
      v11 = v7->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v7->mPrev = v7;
      v7->mNext = v7;
      v12 = v7->mPrev;
      v13 = v7->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v7->mPrev = v7;
      v7->mNext = v7;
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v7);
      v14 = (hkpEntityListener *)&v5->vfptr;
      v15 = hkpEntity::getEntityListeners(v4);
      v16 = 0;
      v17 = 0;
      v18 = v15->m_size;
      if ( v18 <= 0 )
      {
LABEL_14:
        v17 = -1;
      }
      else
      {
        v19 = v15->m_data;
        while ( *v19 != v14 )
        {
          ++v17;
          ++v19;
          if ( v17 >= v18 )
            goto LABEL_14;
        }
      }
      v20 = v17 >= 0;
      v21 = hkpEntity::getEntityListeners(v3);
      v22 = v21->m_size;
      if ( v22 <= 0 )
      {
LABEL_19:
        v16 = -1;
      }
      else
      {
        v23 = v21->m_data;
        while ( *v23 != v14 )
        {
          ++v16;
          ++v23;
          if ( v16 >= v22 )
            goto LABEL_19;
        }
      }
      v24 = v16 >= 0;
      v25 = v4->m_world;
      if ( v25 && v20 )
        hkpWorld::updateCollisionFilterOnEntity(v25, v4, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      v26 = v3->m_world;
      if ( v26 && v24 )
        hkpWorld::updateCollisionFilterOnEntity(v26, v3, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      if ( v20 )
        hkpEntity::removeEntityListener(v4, v14);
      if ( v24 )
        hkpEntity::removeEntityListener(v3, v14);
      return 1;
    }
    v7 = v7->mNext;
  }
  return 1;
}

// File Line: 215
// RVA: 0xAE3D0
__int64 __fastcall UFG::CustomCollisionFilter::ReenableCollisions(UFG::CustomCollisionFilter *this, hkpEntity *entity)
{
  hkpEntity *v2; // rdi
  UFG::CustomCollisionFilter *v3; // r15
  unsigned __int8 v4; // si
  UFG::CustomCollisionFilter *v5; // rbx
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *v6; // r12
  UFG::CustomCollisionFilter *v7; // r14
  _QWORD **v8; // rax
  __int64 v9; // rax
  hkpEntity::ExtendedListeners *v10; // rcx
  signed int v11; // eax
  signed int v12; // edx
  UFG::CustomCollisionFilter **v13; // rcx
  bool v14; // si
  hkpWorld *v15; // rcx
  hkBaseObjectVtbl *v16; // r8
  hkBaseObjectVtbl **v17; // rcx

  v2 = entity;
  v3 = this;
  v4 = 0;
  v5 = (UFG::CustomCollisionFilter *)this->mNonCollidable.mNode.mNext;
  v6 = &this->mNonCollidable;
  if ( v5 != (UFG::CustomCollisionFilter *)&this->mNonCollidable )
  {
    while ( 1 )
    {
      v7 = *(UFG::CustomCollisionFilter **)&v5->m_memSizeAndFlags;
      if ( (hkpEntity *)v5->vfptr != v2 && (hkpEntity *)v5->vfptr != v2 )
        goto LABEL_21;
      if ( !v4 )
      {
        if ( !v2->m_extendedListeners )
        {
          v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 32i64);
          if ( v9 )
          {
            *(_QWORD *)v9 = 0i64;
            *(_DWORD *)(v9 + 8) = 2147483648;
            *(_QWORD *)(v9 + 16) = 0i64;
            *(_DWORD *)(v9 + 24) = 2147483648;
          }
          else
          {
            v9 = 0i64;
          }
          v2->m_extendedListeners = (hkpEntity::ExtendedListeners *)v9;
        }
        v10 = v2->m_extendedListeners;
        v11 = 0;
        v12 = v10->m_entityListeners.m_size;
        if ( v12 <= 0 )
        {
LABEL_14:
          v11 = -1;
        }
        else
        {
          v13 = (UFG::CustomCollisionFilter **)v10->m_entityListeners.m_data;
          while ( *v13 != (UFG::CustomCollisionFilter *)&v3->vfptr )
          {
            ++v11;
            ++v13;
            if ( v11 >= v12 )
              goto LABEL_14;
          }
        }
        v14 = v11 >= 0;
        v15 = v2->m_world;
        if ( !v15 )
          goto LABEL_18;
        if ( v11 >= 0 )
          break;
      }
LABEL_20:
      v4 = 1;
      v16 = v5->vfptr;
      v17 = *(hkBaseObjectVtbl ***)&v5->m_memSizeAndFlags;
      v16->__first_virtual_table_function__ = (void (__fastcall *)(hkBaseObject *))v17;
      *v17 = v16;
      v5->vfptr = (hkBaseObjectVtbl *)v5;
      *(_QWORD *)&v5->m_memSizeAndFlags = v5;
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v5);
LABEL_21:
      v5 = v7;
      if ( v7 == (UFG::CustomCollisionFilter *)v6 )
        return v4;
    }
    hkpWorld::updateCollisionFilterOnEntity(v15, v2, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
LABEL_18:
    if ( v14 )
      hkpEntity::removeEntityListener(v2, (hkpEntityListener *)&v3->vfptr);
    goto LABEL_20;
  }
  return v4;
}

// File Line: 253
// RVA: 0xAB780
__int64 __fastcall UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::CustomCollisionFilter *this)
{
  UFG::Stack *v1; // r8

  v1 = this->mAssignedSystemGroups;
  return v1->mBuffer[v1->mHead-- - 1];
}

// File Line: 263
// RVA: 0xAF3E0
void __fastcall UFG::CustomCollisionFilter::ReleaseSystemId(UFG::CustomCollisionFilter *this, unsigned __int16 systemId)
{
  UFG::Stack *v2; // r8

  v2 = this->mAssignedSystemGroups;
  v2->mBuffer[v2->mHead++] = systemId;
}

// File Line: 271
// RVA: 0xB7E00
void __fastcall UFG::CustomCollisionFilter::entityDeletedCallback(UFG::CustomCollisionFilter *this, hkpEntity *entity)
{
  hkpEntity *v2; // rdi
  UFG::CustomCollisionFilter *v3; // rbx
  hkpEntityListener *v4; // rdx
  hkpCollidableCollidableFilterVtbl *v5; // rdx
  signed __int64 v6; // rsi
  hkBool *(__fastcall *v7)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *); // rbx
  void *(__fastcall *v8)(hkpCollidableCollidableFilter *, unsigned int); // rcx
  hkBool *(__fastcall *v9)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *); // rax

  v2 = entity;
  v3 = this;
  v4 = 0i64;
  if ( this != (UFG::CustomCollisionFilter *)272 )
    v4 = (hkpEntityListener *)this;
  hkpEntity::removeEntityListener(v2, v4);
  v5 = v3->vfptr;
  v6 = (signed __int64)&v3->m_memSizeAndFlags;
  if ( v5 != (hkpCollidableCollidableFilterVtbl *)&v3->m_memSizeAndFlags )
  {
    do
    {
      v7 = v5->isCollisionEnabled;
      if ( (hkpEntity *)v5[1].__vecDelDtor == v2 || (hkpEntity *)v5[1].isCollisionEnabled == v2 )
      {
        v8 = v5->__vecDelDtor;
        v9 = v5->isCollisionEnabled;
        *((_QWORD *)v8 + 1) = v9;
        *(_QWORD *)v9 = v8;
        v5->__vecDelDtor = (void *(__fastcall *)(hkpCollidableCollidableFilter *, unsigned int))v5;
        v5->isCollisionEnabled = (hkBool *(__fastcall *)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *))v5;
        UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v5);
      }
      v5 = (hkpCollidableCollidableFilterVtbl *)v7;
    }
    while ( v7 != (hkBool *(__fastcall *)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *))v6 );
  }
}

