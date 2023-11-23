// File Line: 30
// RVA: 0x98660
void __fastcall UFG::CustomCollisionFilter::CustomCollisionFilter(UFG::CustomCollisionFilter *this)
{
  UFG::Stack *v2; // rdi
  unsigned int v3; // eax
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // kr00_8

  hkpGroupFilter::hkpGroupFilter(this);
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpGroupFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpGroupFilter::hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpGroupFilter::hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpGroupFilter::hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpGroupFilter::hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&UFG::CustomCollisionFilter::`vftable;
  this->mNonCollidable.mNode.mPrev = &this->mNonCollidable.mNode;
  this->mNonCollidable.mNode.mNext = &this->mNonCollidable.mNode;
  v2 = (UFG::Stack *)UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
  if ( v2 )
  {
    v3 = stack_size;
    v2->mHead = 0;
    v2->mCapacity = v3;
    v5 = v3;
    v4 = 4i64 * v3;
    if ( !is_mul_ok(v5, 4ui64) )
      v4 = -1i64;
    v2->mBuffer = (unsigned int *)UFG::qMalloc(v4, "Stack", 0i64);
  }
  else
  {
    v2 = 0i64;
  }
  this->mAssignedSystemGroups = v2;
  UFG::CustomCollisionFilter::ResetState(this);
}

// File Line: 39
// RVA: 0x9BFE0
void __fastcall UFG::CustomCollisionFilter::~CustomCollisionFilter(UFG::CustomCollisionFilter *this)
{
  UFG::Stack *mAssignedSystemGroups; // rbx
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *p_mNonCollidable; // rbx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *mNext; // rdx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *mPrev; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v6; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v7; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v8; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v9; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v10; // rax

  this->hkpGroupFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkReferencedObject};
  this->hkpGroupFilter::hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  this->hkpGroupFilter::hkpCollisionFilter::hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  this->hkpGroupFilter::hkpCollisionFilter::hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  this->hkpGroupFilter::hkpCollisionFilter::hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&UFG::CustomCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&UFG::CustomCollisionFilter::`vftable;
  mAssignedSystemGroups = this->mAssignedSystemGroups;
  if ( mAssignedSystemGroups )
  {
    operator delete[](mAssignedSystemGroups->mBuffer);
    operator delete[](mAssignedSystemGroups);
  }
  p_mNonCollidable = &this->mNonCollidable;
  while ( (UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *)this->mNonCollidable.mNode.mNext != &this->mNonCollidable )
  {
    mNext = this->mNonCollidable.mNode.mNext;
    mPrev = mNext->mPrev;
    v6 = mNext->mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v7 = mNext->mPrev;
    v8 = mNext->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mNext);
  }
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0>::DeleteNodes(&this->mNonCollidable);
  v9 = p_mNonCollidable->mNode.mPrev;
  v10 = this->mNonCollidable.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mNonCollidable->mNode.mPrev = &p_mNonCollidable->mNode;
  this->mNonCollidable.mNode.mNext = &this->mNonCollidable.mNode;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  hkpGroupFilter::~hkpGroupFilter(this);
}

// File Line: 52
// RVA: 0xB0210
void __fastcall UFG::CustomCollisionFilter::ResetState(UFG::CustomCollisionFilter *this)
{
  __int16 v2; // r8
  int v3; // r10d
  int v4; // r9d
  UFG::Stack *mAssignedSystemGroups; // rdx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *mNext; // rdx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *mPrev; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v8; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v9; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v10; // rax

  this->mAssignedSystemGroups->mHead = 0;
  v2 = 1;
  v3 = stack_size + 1;
  if ( v3 > 1 )
  {
    v4 = 1;
    do
    {
      mAssignedSystemGroups = this->mAssignedSystemGroups;
      mAssignedSystemGroups->mBuffer[mAssignedSystemGroups->mHead++] = v4;
      v4 = ++v2;
    }
    while ( v2 < v3 );
  }
  while ( (UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *)this->mNonCollidable.mNode.mNext != &this->mNonCollidable )
  {
    mNext = this->mNonCollidable.mNode.mNext;
    mPrev = mNext->mPrev;
    v8 = mNext->mNext;
    mPrev->mNext = v8;
    v8->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v9 = mNext->mPrev;
    v10 = mNext->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mNext);
  }
}

// File Line: 85
// RVA: 0xB81E0
hkBool *__fastcall UFG::CustomCollisionFilter::isCollisionEnabled(
        UFG::CustomCollisionFilter *this,
        hkBool *result,
        hkpCollidable *a,
        hkpCollidable *b)
{
  hkpEntityListenerVtbl *vfptr; // rax
  hkpCollidable *v6; // r11
  hkpCollidable *entityRemovedCallback; // r10
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  vfptr = this->hkpEntityListener::vfptr;
  if ( vfptr == (hkpEntityListenerVtbl *)&this->m_pad256[3].m_quad.m128_u16[4] )
  {
LABEL_8:
    result->m_bool = hkpGroupFilter::isCollisionEnabled(this, &resulta, a, b)->m_bool != 0;
    return result;
  }
  else
  {
    v6 = (hkpCollidable *)((char *)a + a->m_ownerOffset);
    while ( 1 )
    {
      entityRemovedCallback = (hkpCollidable *)vfptr->entityRemovedCallback;
      if ( v6 == entityRemovedCallback && (char *)b + b->m_ownerOffset == (char *)vfptr->entityShapeSetCallback )
        break;
      if ( (hkpCollidable *)((char *)b + b->m_ownerOffset) == entityRemovedCallback
        && v6 == (hkpCollidable *)vfptr->entityShapeSetCallback )
      {
        break;
      }
      vfptr = (hkpEntityListenerVtbl *)vfptr->entityAddedCallback;
      if ( vfptr == (hkpEntityListenerVtbl *)&this->m_pad256[3].m_quad.m128_u16[4] )
        goto LABEL_8;
    }
    result->m_bool = 0;
    return result;
  }
}

// File Line: 105
// RVA: 0xA7290
void __fastcall UFG::CustomCollisionFilter::DisableCollisionsBetween(
        UFG::CustomCollisionFilter *this,
        hkpEntity *entityA,
        hkpEntity *entityB)
{
  bool v6; // r9
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *mNext; // rax
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *p_mNonCollidable; // rbp
  hkpEntity *mPrev; // rcx
  char *v10; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v11; // rcx
  int v12; // ebx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v13; // rax
  hkpEntityListener *v14; // rbp
  hkSmallArray<hkpEntityListener *> *EntityListeners; // rax
  int v16; // ecx
  int m_size; // edx
  hkpEntityListener **m_data; // rax
  bool v19; // r14
  hkSmallArray<hkpEntityListener *> *v20; // rax
  int v21; // ecx
  hkpEntityListener **v22; // rax
  bool v23; // bl
  hkpWorld *m_world; // rcx
  hkpWorld *v25; // rcx

  if ( entityB )
  {
    v6 = 0;
    mNext = this->mNonCollidable.mNode.mNext;
    p_mNonCollidable = &this->mNonCollidable;
    if ( mNext == (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)&this->mNonCollidable )
    {
LABEL_12:
      v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "FilterNode", 0i64, 1u);
      v11 = (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)v10;
      v12 = 0;
      if ( v10 )
      {
        *(_QWORD *)v10 = v10;
        *((_QWORD *)v10 + 1) = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v11[1].mPrev = (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)entityA;
      v11[1].mNext = (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)entityB;
      v13 = p_mNonCollidable->mNode.mNext;
      p_mNonCollidable->mNode.mNext = v11;
      v11->mPrev = &p_mNonCollidable->mNode;
      v11->mNext = v13;
      v13->mPrev = v11;
      v14 = &this->hkpEntityListener;
      EntityListeners = hkpEntity::getEntityListeners(entityA);
      v16 = 0;
      m_size = EntityListeners->m_size;
      if ( EntityListeners->m_size )
      {
        m_data = EntityListeners->m_data;
        while ( *m_data != v14 )
        {
          ++v16;
          ++m_data;
          if ( v16 >= m_size )
            goto LABEL_19;
        }
      }
      else
      {
LABEL_19:
        v16 = -1;
      }
      v19 = v16 >= 0;
      v20 = hkpEntity::getEntityListeners(entityB);
      v21 = v20->m_size;
      if ( v20->m_size )
      {
        v22 = v20->m_data;
        while ( *v22 != v14 )
        {
          ++v12;
          ++v22;
          if ( v12 >= v21 )
            goto LABEL_24;
        }
      }
      else
      {
LABEL_24:
        v12 = -1;
      }
      v23 = v12 >= 0;
      m_world = entityA->m_world;
      if ( m_world && !v19 )
        hkpWorld::updateCollisionFilterOnEntity(
          m_world,
          entityA,
          HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      v25 = entityB->m_world;
      if ( v25 && !v23 )
        hkpWorld::updateCollisionFilterOnEntity(
          v25,
          entityB,
          HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      if ( !v19 )
        hkpEntity::addEntityListener(entityA, v14);
      if ( !v23 )
        hkpEntity::addEntityListener(entityB, v14);
    }
    else
    {
      while ( !v6 )
      {
        mPrev = (hkpEntity *)mNext[1].mPrev;
        v6 = mPrev == entityA && (hkpEntity *)mNext[1].mNext == entityB
          || mPrev == entityB && (hkpEntity *)mNext[1].mNext == entityA;
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)p_mNonCollidable )
        {
          if ( v6 )
            return;
          goto LABEL_12;
        }
      }
    }
  }
}

// File Line: 162
// RVA: 0xAE550
char __fastcall UFG::CustomCollisionFilter::ReenableCollisionsBetween(
        UFG::CustomCollisionFilter *this,
        hkpEntity *entityA,
        hkpEntity *entityB)
{
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *mNext; // rdx
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *p_mNonCollidable; // rcx
  hkpEntity *mPrev; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v10; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v11; // rax
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v12; // rcx
  UFG::qNode<UFG::FilterNode,UFG::FilterNode> *v13; // rax
  hkpEntityListener *v14; // rbp
  hkSmallArray<hkpEntityListener *> *EntityListeners; // rax
  int v16; // ebx
  int v17; // ecx
  int m_size; // edx
  hkpEntityListener **m_data; // rax
  bool v20; // r14
  hkSmallArray<hkpEntityListener *> *v21; // rax
  int v22; // ecx
  hkpEntityListener **v23; // rax
  bool v24; // bl
  hkpWorld *m_world; // rcx
  hkpWorld *v26; // rcx

  if ( !entityB )
    return 0;
  mNext = this->mNonCollidable.mNode.mNext;
  p_mNonCollidable = &this->mNonCollidable;
  while ( mNext != (UFG::qNode<UFG::FilterNode,UFG::FilterNode> *)p_mNonCollidable )
  {
    mPrev = (hkpEntity *)mNext[1].mPrev;
    if ( mPrev == entityA && (hkpEntity *)mNext[1].mNext == entityB
      || mPrev == entityB && (hkpEntity *)mNext[1].mNext == entityA )
    {
      v10 = mNext->mPrev;
      v11 = mNext->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v12 = mNext->mPrev;
      v13 = mNext->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mNext);
      v14 = &this->hkpEntityListener;
      EntityListeners = hkpEntity::getEntityListeners(entityA);
      v16 = 0;
      v17 = 0;
      m_size = EntityListeners->m_size;
      if ( EntityListeners->m_size )
      {
        m_data = EntityListeners->m_data;
        while ( *m_data != v14 )
        {
          ++v17;
          ++m_data;
          if ( v17 >= m_size )
            goto LABEL_14;
        }
      }
      else
      {
LABEL_14:
        v17 = -1;
      }
      v20 = v17 >= 0;
      v21 = hkpEntity::getEntityListeners(entityB);
      v22 = v21->m_size;
      if ( v21->m_size )
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
      else
      {
LABEL_19:
        v16 = -1;
      }
      v24 = v16 >= 0;
      m_world = entityA->m_world;
      if ( m_world && v20 )
        hkpWorld::updateCollisionFilterOnEntity(
          m_world,
          entityA,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      v26 = entityB->m_world;
      if ( v26 && v24 )
        hkpWorld::updateCollisionFilterOnEntity(
          v26,
          entityB,
          HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      if ( v20 )
        hkpEntity::removeEntityListener(entityA, v14);
      if ( v24 )
        hkpEntity::removeEntityListener(entityB, v14);
      return 1;
    }
    mNext = mNext->mNext;
  }
  return 1;
}

// File Line: 215
// RVA: 0xAE3D0
__int64 __fastcall UFG::CustomCollisionFilter::ReenableCollisions(UFG::CustomCollisionFilter *this, hkpEntity *entity)
{
  unsigned __int8 v4; // si
  UFG::CustomCollisionFilter *mNext; // rbx
  UFG::qList<UFG::FilterNode,UFG::FilterNode,1,0> *p_mNonCollidable; // r12
  UFG::CustomCollisionFilter *v7; // r14
  _QWORD **Value; // rax
  __int64 v9; // rax
  hkpEntity::ExtendedListeners *m_extendedListeners; // rcx
  int v11; // eax
  int m_size; // edx
  UFG::CustomCollisionFilter **m_data; // rcx
  bool v14; // si
  hkpWorld *m_world; // rcx
  hkBaseObjectVtbl *vfptr; // r8
  hkBaseObjectVtbl **v17; // rcx

  v4 = 0;
  mNext = (UFG::CustomCollisionFilter *)this->mNonCollidable.mNode.mNext;
  p_mNonCollidable = &this->mNonCollidable;
  if ( mNext != (UFG::CustomCollisionFilter *)&this->mNonCollidable )
  {
    while ( 1 )
    {
      v7 = *(UFG::CustomCollisionFilter **)&mNext->m_memSizeAndFlags;
      if ( (hkpEntity *)mNext->hkpGroupFilter::hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr != entity
        && (hkpEntity *)mNext->hkpGroupFilter::hkpCollisionFilter::hkpShapeCollectionFilter::vfptr != entity )
      {
        goto LABEL_21;
      }
      if ( !v4 )
      {
        if ( !entity->m_extendedListeners )
        {
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
          if ( v9 )
          {
            *(_QWORD *)v9 = 0i64;
            *(_DWORD *)(v9 + 8) = 0x80000000;
            *(_QWORD *)(v9 + 16) = 0i64;
            *(_DWORD *)(v9 + 24) = 0x80000000;
          }
          else
          {
            v9 = 0i64;
          }
          entity->m_extendedListeners = (hkpEntity::ExtendedListeners *)v9;
        }
        m_extendedListeners = entity->m_extendedListeners;
        v11 = 0;
        m_size = m_extendedListeners->m_entityListeners.m_size;
        if ( m_extendedListeners->m_entityListeners.m_size )
        {
          m_data = (UFG::CustomCollisionFilter **)m_extendedListeners->m_entityListeners.m_data;
          while ( *m_data != (UFG::CustomCollisionFilter *)&this->hkpEntityListener )
          {
            ++v11;
            ++m_data;
            if ( v11 >= m_size )
              goto LABEL_14;
          }
        }
        else
        {
LABEL_14:
          v11 = -1;
        }
        v14 = v11 >= 0;
        m_world = entity->m_world;
        if ( !m_world )
          goto LABEL_18;
        if ( v11 >= 0 )
          break;
      }
LABEL_20:
      v4 = 1;
      vfptr = mNext->hkpGroupFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr;
      v17 = *(hkBaseObjectVtbl ***)&mNext->m_memSizeAndFlags;
      vfptr->__first_virtual_table_function__ = (void (__fastcall *)(hkBaseObject *))v17;
      *v17 = vfptr;
      mNext->hkpGroupFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)mNext;
      *(_QWORD *)&mNext->m_memSizeAndFlags = mNext;
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, mNext);
LABEL_21:
      mNext = v7;
      if ( v7 == (UFG::CustomCollisionFilter *)p_mNonCollidable )
        return v4;
    }
    hkpWorld::updateCollisionFilterOnEntity(
      m_world,
      entity,
      HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
      HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
LABEL_18:
    if ( v14 )
      hkpEntity::removeEntityListener(entity, &this->hkpEntityListener);
    goto LABEL_20;
  }
  return v4;
}

// File Line: 253
// RVA: 0xAB780
__int64 __fastcall UFG::CustomCollisionFilter::GetUnusedSystemId(UFG::CustomCollisionFilter *this)
{
  UFG::Stack *mAssignedSystemGroups; // r8

  mAssignedSystemGroups = this->mAssignedSystemGroups;
  return mAssignedSystemGroups->mBuffer[--mAssignedSystemGroups->mHead];
}

// File Line: 263
// RVA: 0xAF3E0
void __fastcall UFG::CustomCollisionFilter::ReleaseSystemId(
        UFG::CustomCollisionFilter *this,
        unsigned __int16 systemId)
{
  UFG::Stack *mAssignedSystemGroups; // r8

  mAssignedSystemGroups = this->mAssignedSystemGroups;
  mAssignedSystemGroups->mBuffer[mAssignedSystemGroups->mHead++] = systemId;
}

// File Line: 271
// RVA: 0xB7E00
void __fastcall UFG::CustomCollisionFilter::entityDeletedCallback(UFG::CustomCollisionFilter *this, hkpEntity *entity)
{
  hkpEntityListener *v4; // rdx
  hkpCollidableCollidableFilterVtbl *vfptr; // rdx
  unsigned __int16 *p_m_memSizeAndFlags; // rsi
  hkBool *(__fastcall *isCollisionEnabled)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *); // rbx
  void *(__fastcall *vecDelDtor)(hkpCollidableCollidableFilter *, unsigned int); // rcx
  hkBool *(__fastcall *v9)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *); // rax

  v4 = 0i64;
  if ( this != (UFG::CustomCollisionFilter *)272 )
    v4 = (hkpEntityListener *)this;
  hkpEntity::removeEntityListener(entity, v4);
  vfptr = this->hkpGroupFilter::hkpCollisionFilter::hkpCollidableCollidableFilter::vfptr;
  p_m_memSizeAndFlags = &this->m_memSizeAndFlags;
  if ( vfptr != (hkpCollidableCollidableFilterVtbl *)&this->m_memSizeAndFlags )
  {
    do
    {
      isCollisionEnabled = vfptr->isCollisionEnabled;
      if ( (hkpEntity *)vfptr[1].__vecDelDtor == entity || (hkpEntity *)vfptr[1].isCollisionEnabled == entity )
      {
        vecDelDtor = vfptr->__vecDelDtor;
        v9 = vfptr->isCollisionEnabled;
        *((_QWORD *)vecDelDtor + 1) = v9;
        *(_QWORD *)v9 = vecDelDtor;
        vfptr->__vecDelDtor = (void *(__fastcall *)(hkpCollidableCollidableFilter *, unsigned int))vfptr;
        vfptr->isCollisionEnabled = (hkBool *(__fastcall *)(hkpCollidableCollidableFilter *, hkBool *, hkpCollidable *, hkpCollidable *))vfptr;
        UFG::qMemoryPool::Free(&gPhysicsMemoryPool, vfptr);
      }
      vfptr = (hkpCollidableCollidableFilterVtbl *)isCollisionEnabled;
    }
    while ( (char *)isCollisionEnabled != (char *)p_m_memSizeAndFlags );
  }
}

