// File Line: 22
// RVA: 0xE1A680
void __fastcall hkpTriggerVolume::hkpTriggerVolume(hkpTriggerVolume *this, hkpRigidBody *triggerBody)
{
  hkpRigidBody *v2; // rdi
  hkpTriggerVolume *v3; // rsi
  hkpWorld *v4; // rdx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = triggerBody;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriggerVolume::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpContactListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpContactListener};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpWorldPostSimulationListener};
  this->vfptr = (hkpEntityListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpEntityListener};
  this->m_overlappingBodies.m_capacityAndFlags = 2147483648;
  this->m_overlappingBodies.m_data = 0i64;
  this->m_overlappingBodies.m_size = 0;
  this->m_eventQueue.m_data = 0i64;
  this->m_eventQueue.m_size = 0;
  this->m_eventQueue.m_capacityAndFlags = 2147483648;
  this->m_triggerBody = triggerBody;
  this->m_sequenceNumber = 0;
  this->m_isProcessingBodyOverlaps.m_bool = 0;
  this->m_newOverlappingBodies.m_data = 0i64;
  this->m_newOverlappingBodies.m_size = 0;
  this->m_newOverlappingBodies.m_capacityAndFlags = 2147483648;
  hkpEntity::addContactListener((hkpEntity *)&triggerBody->vfptr, (hkpContactListener *)&this->vfptr);
  hkpEntity::addEntityListener((hkpEntity *)&v2->vfptr, (hkpEntityListener *)&v3->vfptr);
  hkpWorldObject::addProperty((hkpWorldObject *)&v2->vfptr, 0x1310u, (hkSimplePropertyValue)v3);
  hkpWorldObject::addProperty(
    (hkpWorldObject *)&v2->vfptr,
    0x1130u,
    (hkSimplePropertyValue)(signed int)HK_TRIGGER_VOLUME_DEBUG_COLOR_0);
  v4 = v2->m_world;
  if ( v4 )
    hkpTriggerVolume::triggerBodyEnteredWorld(v3, v4);
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 38
// RVA: 0xE1A770
void __fastcall hkpTriggerVolume::hkpTriggerVolume(hkpTriggerVolume *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriggerVolume::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpContactListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpContactListener};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpWorldPostSimulationListener};
  this->vfptr = (hkpEntityListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpEntityListener};
}

// File Line: 43
// RVA: 0xE1B250
void __fastcall hkpTriggerVolume::entityAddedCallback(hkpTriggerVolume *this, hkpEntity *entity)
{
  hkpTriggerVolume::triggerBodyEnteredWorld((hkpTriggerVolume *)((char *)this - 32), entity->m_world);
}

// File Line: 76
// RVA: 0xE1B740
void __fastcall hkpTriggerVolume::triggerBodyEnteredWorld(hkpTriggerVolume *this, hkpWorld *world)
{
  hkpWorld *v2; // rbx
  hkpWorldPostSimulationListener *v3; // rdx
  hkpWorld *v4; // rdx

  v2 = world;
  if ( this )
    v3 = (hkpWorldPostSimulationListener *)&this->vfptr;
  else
    v3 = 0i64;
  hkpWorld::addWorldPostSimulationListener(v2, v3);
  hkpWorldExtension::requireExtension<hkpCollisionCallbackUtil>((hkpWorldExtension *)v2, v4);
}

// File Line: 102
// RVA: 0xE1B780
void __fastcall hkpTriggerVolume::triggerBodyLeftWorld(hkpTriggerVolume *this)
{
  hkpTriggerVolume *v1; // rbx
  hkpWorld *v2; // rdi
  hkpWorld *v3; // rdx
  __int64 v4; // rsi
  __int64 i; // rdi
  __int64 v6; // rsi
  __int64 v7; // rdi

  v1 = this;
  v2 = this->m_triggerBody->m_world;
  hkpWorld::removeWorldPostSimulationListener(v2, (hkpWorldPostSimulationListener *)&this->vfptr);
  hkpWorldExtension::releaseExtension<hkpCollisionCallbackUtil>((hkpWorldExtension *)v2, v3);
  v4 = v1->m_overlappingBodies.m_size;
  for ( i = 0i64; i < v4; ++i )
  {
    hkpEntity::removeEntityListener(
      (hkpEntity *)&v1->m_overlappingBodies.m_data[i]->vfptr,
      (hkpEntityListener *)&v1->vfptr);
    ((void (__fastcall *)(hkpTriggerVolume *, hkpRigidBody *, signed __int64))v1->vfptr[2].__vecDelDtor)(
      v1,
      v1->m_overlappingBodies.m_data[i],
      6i64);
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_overlappingBodies.m_data[i]->vfptr);
  }
  v6 = v1->m_eventQueue.m_size;
  if ( v6 > 0 )
  {
    v7 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_eventQueue.m_data[v7].m_body->vfptr);
      ++v7;
      --v6;
    }
    while ( v6 );
  }
  v1->m_eventQueue.m_size = 0;
  v1->m_overlappingBodies.m_size = 0;
}

// File Line: 123
// RVA: 0xE1B710
void __fastcall hkpTriggerVolume::entityShapeSetCallback(hkpTriggerVolume *this, hkpEntity *entity)
{
  __int64 v2; // rax

  v2 = SLODWORD(this->vfptr);
  if ( (_DWORD)v2 )
  {
    if ( *((_DWORD *)&this->vfptr[v2] - 2) == 1 )
      this->vfptr[1].__vecDelDtor((hkBaseObject *)this, (unsigned int)entity);
  }
}

// File Line: 137
// RVA: 0xE1B270
void __fastcall hkpTriggerVolume::entityRemovedCallback(hkpTriggerVolume *this, hkpEntity *entity)
{
  hkpRigidBody *v2; // rsi
  hkpTriggerVolume *v3; // rdi
  hkpEntityListener *v4; // r13
  int v5; // er15
  hkpTriggerVolume::EventInfo *v6; // r12
  int v7; // ebp
  int v8; // er14
  int v9; // ebx
  hkpRigidBody *v10; // rbx
  signed __int64 v11; // rcx
  int v12; // edx
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // r12
  int v16; // ebx
  int v17; // er14
  int v18; // ebp
  hkpRigidBody *v19; // rbp
  signed __int64 v20; // rdx
  int v21; // er9
  __int64 v22; // rcx
  __int64 v23; // rax
  int v24; // ebx
  __int64 v25; // rdx
  hkpRigidBody **v26; // r8
  int v27; // ebp
  __int64 v28; // rdx
  hkpRigidBody **v29; // r8
  int v30; // ebx
  __int64 v31; // r14
  int v32; // er9
  signed __int64 v33; // rcx
  __int64 v34; // rdx
  __int64 v35; // rax
  signed __int64 v36; // rbx
  hkpWorldPostSimulationListenerVtbl *v37; // rcx
  int v38; // edx
  __int64 v39; // rdx
  void (__fastcall *v40)(hkpWorldPostSimulationListener *, hkpEntity *); // rax
  __int64 v41; // r12
  int v42; // ebx
  int v43; // er14
  int v44; // ebp
  hkpRigidBody *v45; // rbp
  signed __int64 v46; // rdx
  int v47; // er9
  __int64 v48; // rcx
  __int64 v49; // rax
  __int64 v50; // r14
  signed __int64 v51; // rbx
  hkReferencedObject *v52; // rcx
  __int64 v53; // rax
  hkpWorldPostSimulationListenerVtbl *v54; // rdx
  signed __int64 v55; // r8
  signed __int64 v56; // rcx
  signed __int64 v57; // rdx
  signed __int64 v58; // r8
  __int64 v59; // rax
  hkBool result; // [rsp+50h] [rbp+8h]

  v2 = (hkpRigidBody *)entity;
  v3 = this;
  if ( entity == (hkpEntity *)this->m_overlappingBodies.m_data )
  {
    hkpTriggerVolume::triggerBodyLeftWorld((hkpTriggerVolume *)((char *)this - 32));
  }
  else
  {
    v4 = 0i64;
    v5 = LODWORD(this->vfptr) - 1;
    if ( LOBYTE(this->m_overlappingBodies.m_capacityAndFlags) )
    {
      v6 = this->m_eventQueue.m_data;
      v7 = 0;
      v8 = this->m_eventQueue.m_size - 1;
      if ( v8 > 0 )
      {
        do
        {
          v9 = (v8 + v7) >> 1;
          if ( hkpTriggerVolume::bodyOrderForArrays(&result, *((hkpRigidBody **)&v6->m_sortValue + v9), v2)->m_bool )
            v7 = v9 + 1;
          else
            v8 = (v8 + v7) >> 1;
        }
        while ( v8 > v7 );
      }
      if ( v7 != v8
        || (v10 = (hkpRigidBody *)*(&v6->m_sortValue + v7),
            hkpTriggerVolume::bodyOrderForArrays(&result, *((hkpRigidBody **)&v6->m_sortValue + v7), v2)->m_bool)
        || hkpTriggerVolume::bodyOrderForArrays(&result, v2, v10)->m_bool
        || v7 < 0 )
      {
        v15 = *(_QWORD *)&v3->m_memSizeAndFlags;
        v16 = 0;
        v17 = LODWORD(v3->vfptr) - 1;
        if ( v17 > 0 )
        {
          do
          {
            v18 = (v17 + v16) >> 1;
            if ( hkpTriggerVolume::bodyOrderForArrays(&result, *(hkpRigidBody **)(v15 + 8i64 * v18), v2)->m_bool )
              v16 = v18 + 1;
            else
              v17 = (v17 + v16) >> 1;
          }
          while ( v17 > v16 );
        }
        if ( v16 != v17
          || (v19 = *(hkpRigidBody **)(v15 + 8i64 * v16),
              hkpTriggerVolume::bodyOrderForArrays(&result, *(hkpRigidBody **)(v15 + 8i64 * v16), v2)->m_bool)
          || hkpTriggerVolume::bodyOrderForArrays(&result, v2, v19)->m_bool )
        {
          v16 = -1;
        }
        --LODWORD(v3->vfptr);
        v20 = v15 + 8i64 * v16;
        v21 = 8 * (LODWORD(v3->vfptr) - v16);
        if ( v21 > 0 )
        {
          v22 = ((unsigned int)(v21 - 1) >> 3) + 1;
          do
          {
            v23 = *(_QWORD *)(v20 + 8);
            v20 += 8i64;
            *(_QWORD *)(v20 - 8) = v23;
            --v22;
          }
          while ( v22 );
        }
        v24 = v5 - 1;
        v25 = v5 - 1;
        if ( v5 - 1 >= 0 )
        {
          v26 = (hkpRigidBody **)(&v3->vfptr->__vecDelDtor + v24 + 2i64 * v24 + 1);
          do
          {
            if ( *v26 == v2 )
              break;
            --v24;
            v26 -= 3;
            --v25;
          }
          while ( v25 >= 0 );
          if ( v24 >= 0 )
          {
            v27 = v24;
            v28 = v24;
            if ( v24 > 0 )
            {
              v29 = (hkpRigidBody **)(&v3->vfptr->__vecDelDtor + v24 + 2 * (v24 - 1i64));
              do
              {
                if ( *v29 != v2 )
                  break;
                --v28;
                --v27;
                v29 -= 3;
              }
              while ( v28 > 0 );
            }
            v30 = v24 - v27 + 1;
            if ( v30 > 0 )
            {
              v31 = (unsigned int)v30;
              do
              {
                hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
                --v31;
              }
              while ( v31 );
            }
            LODWORD(v3->vfptr) -= v30;
            v32 = 24 * (LODWORD(v3->vfptr) - v27);
            v33 = (signed __int64)&v3->vfptr[v27];
            if ( v32 > 0 )
            {
              v34 = ((unsigned int)(v32 - 1) >> 3) + 1;
              do
              {
                v35 = *(_QWORD *)(24 * (v27 + (signed __int64)v30) - 24i64 * v27 + v33);
                v33 += 8i64;
                *(_QWORD *)(v33 - 8) = v35;
                --v34;
              }
              while ( v34 );
            }
          }
        }
      }
      else
      {
        --v3->m_eventQueue.m_size;
        v11 = (signed __int64)v6 + 8 * v7;
        v12 = 8 * (v3->m_eventQueue.m_size - v7);
        if ( v12 > 0 )
        {
          v13 = ((unsigned int)(v12 - 1) >> 3) + 1;
          do
          {
            v14 = *(_QWORD *)(v11 + 8);
            v11 += 8i64;
            *(_QWORD *)(v11 - 8) = v14;
            --v13;
          }
          while ( v13 );
        }
      }
      v36 = v5;
      hkReferencedObject::removeReference((hkReferencedObject *)v3->vfptr[v36].postSimulationCallback);
      --LODWORD(v3->vfptr);
      v37 = &v3->vfptr[v36];
      v38 = 24 * (LODWORD(v3->vfptr) - v5);
      if ( v38 > 0 )
      {
        v39 = ((unsigned int)(v38 - 1) >> 3) + 1;
        do
        {
          v40 = (void (__fastcall *)(hkpWorldPostSimulationListener *, hkpEntity *))v37[1].__vecDelDtor;
          v37 = (hkpWorldPostSimulationListenerVtbl *)((char *)v37 + 8);
          v37[-1].inactiveEntityMovedCallback = v40;
          --v39;
        }
        while ( v39 );
      }
    }
    else
    {
      v41 = *(_QWORD *)&this->m_memSizeAndFlags;
      v42 = 0;
      v43 = LODWORD(this->vfptr) - 1;
      if ( v43 > 0 )
      {
        do
        {
          v44 = (v43 + v42) >> 1;
          if ( hkpTriggerVolume::bodyOrderForArrays(&result, *(hkpRigidBody **)(v41 + 8i64 * v44), v2)->m_bool )
            v42 = v44 + 1;
          else
            v43 = (v43 + v42) >> 1;
        }
        while ( v43 > v42 );
      }
      if ( v42 != v43
        || (v45 = *(hkpRigidBody **)(v41 + 8i64 * v42),
            hkpTriggerVolume::bodyOrderForArrays(&result, *(hkpRigidBody **)(v41 + 8i64 * v42), v2)->m_bool)
        || hkpTriggerVolume::bodyOrderForArrays(&result, v2, v45)->m_bool )
      {
        v42 = -1;
      }
      --LODWORD(v3->vfptr);
      v46 = v41 + 8i64 * v42;
      v47 = 8 * (LODWORD(v3->vfptr) - v42);
      if ( v47 > 0 )
      {
        v48 = ((unsigned int)(v47 - 1) >> 3) + 1;
        do
        {
          v49 = *(_QWORD *)(v46 + 8);
          v46 += 8i64;
          *(_QWORD *)(v46 - 8) = v49;
          --v48;
        }
        while ( v48 );
      }
      v50 = v5;
      if ( v5 >= 0 )
      {
        v51 = v5;
        do
        {
          v52 = (hkReferencedObject *)v3->vfptr[v51].postSimulationCallback;
          if ( v52 == (hkReferencedObject *)v2 )
          {
            hkReferencedObject::removeReference(v52);
            v53 = (signed int)--LODWORD(v3->vfptr);
            if ( (_DWORD)v53 != v5 )
            {
              v54 = v3->vfptr;
              v55 = (signed __int64)&v54[v53];
              v56 = (signed __int64)&v54[v51];
              v57 = 3i64;
              v58 = v55 - v56;
              do
              {
                v59 = *(_QWORD *)(v58 + v56);
                v56 += 8i64;
                *(_QWORD *)(v56 - 8) = v59;
                --v57;
              }
              while ( v57 );
            }
          }
          --v5;
          --v51;
          --v50;
        }
        while ( v50 >= 0 );
      }
    }
    ((void (__fastcall *)(hkpRigidBody **, hkpRigidBody *, signed __int64))v3[-1].m_triggerBody->m_collidable.m_shape)(
      &v3[-1].m_triggerBody,
      v2,
      2i64);
    if ( v3 != (hkpTriggerVolume *)32 )
      v4 = (hkpEntityListener *)v3;
    hkpEntity::removeEntityListener((hkpEntity *)&v2->vfptr, v4);
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  }
}

// File Line: 255
// RVA: 0xE1B1D0
void __fastcall hkpTriggerVolume::entityDeletedCallback(hkpTriggerVolume *this, hkpEntity *entity)
{
  hkpEntity *v2; // rsi
  hkpTriggerVolume *v3; // rbx
  hkpEntityListener *v4; // rdx
  hkpContactListener *v5; // rdx

  v2 = entity;
  v3 = this;
  if ( *((_QWORD *)this->m_overlappingBodies.m_data + 2) )
    hkpTriggerVolume::triggerBodyLeftWorld((hkpTriggerVolume *)((char *)this - 32));
  v4 = 0i64;
  if ( v3 != (hkpTriggerVolume *)32 )
    v4 = (hkpEntityListener *)v3;
  hkpEntity::removeEntityListener(v2, v4);
  if ( v3 == (hkpTriggerVolume *)32 )
    v5 = 0i64;
  else
    v5 = (hkpContactListener *)&v3[-1].m_newOverlappingBodies;
  hkpEntity::removeContactListener(v2, v5);
  v3->m_overlappingBodies.m_data = 0i64;
  hkReferencedObject::removeReference((hkReferencedObject *)&v3[-1].m_triggerBody);
}

// File Line: 269
// RVA: 0xE1ABA0
void __fastcall hkpTriggerVolume::~hkpTriggerVolume(hkpTriggerVolume *this)
{
  hkpTriggerVolume *v1; // rbx
  hkpRigidBody *v2; // rcx
  hkpEntity **v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // rdi
  int v6; // er8
  int v7; // eax
  int v8; // er8
  hkSimplePropertyValue result; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTriggerVolume::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpContactListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpContactListener};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpWorldPostSimulationListener};
  this->vfptr = (hkpEntityListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpEntityListener};
  v2 = this->m_triggerBody;
  if ( v2 )
  {
    hkpWorldObject::removeProperty((hkpWorldObject *)&v2->vfptr, &result, 0x1130u);
    hkpWorldObject::removeProperty((hkpWorldObject *)&v1->m_triggerBody->vfptr, &result, 0x1310u);
    hkpEntity::removeEntityListener((hkpEntity *)&v1->m_triggerBody->vfptr, (hkpEntityListener *)&v1->vfptr);
    hkpEntity::removeContactListener((hkpEntity *)&v1->m_triggerBody->vfptr, (hkpContactListener *)&v1->vfptr);
  }
  v3 = (hkpEntity **)v1->m_overlappingBodies.m_data;
  if ( v3 < &v3[v1->m_overlappingBodies.m_size] )
  {
    do
    {
      hkpEntity::removeEntityListener(*v3, (hkpEntityListener *)&v1->vfptr);
      ++v3;
    }
    while ( (hkpRigidBody **)v3 < &v1->m_overlappingBodies.m_data[v1->m_overlappingBodies.m_size] );
  }
  hkReferencedObject::removeReferences(
    (hkReferencedObject *const *)v1->m_overlappingBodies.m_data,
    v1->m_overlappingBodies.m_size,
    8);
  v4 = v1->m_eventQueue.m_size;
  if ( v4 > 0 )
  {
    v5 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_eventQueue.m_data[v5].m_body->vfptr);
      ++v5;
      --v4;
    }
    while ( v4 );
  }
  v1->m_eventQueue.m_size = 0;
  v6 = v1->m_newOverlappingBodies.m_capacityAndFlags;
  v1->m_newOverlappingBodies.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_newOverlappingBodies.m_data,
      8 * v6);
  v1->m_newOverlappingBodies.m_data = 0i64;
  v1->m_newOverlappingBodies.m_capacityAndFlags = 2147483648;
  v7 = v1->m_eventQueue.m_capacityAndFlags;
  v1->m_eventQueue.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_eventQueue.m_data,
      24 * (v7 & 0x3FFFFFFF));
  v1->m_eventQueue.m_data = 0i64;
  v1->m_eventQueue.m_capacityAndFlags = 2147483648;
  v8 = v1->m_overlappingBodies.m_capacityAndFlags;
  v1->m_overlappingBodies.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_overlappingBodies.m_data,
      8 * v8);
  v1->m_overlappingBodies.m_data = 0i64;
  v1->m_overlappingBodies.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  v1->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  v1->vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 290
// RVA: 0xE1AD90
void __fastcall hkpTriggerVolume::contactPointCallback(hkpTriggerVolume *this, hkpContactPointEvent *event)
{
  hkpRigidBody *v2; // r9
  hkpContactPointEvent::Type v3; // eax

  event->m_contactPointProperties->m_flags |= 8u;
  v2 = (hkpRigidBody *)*((_QWORD *)&event->m_source + 2i64 - (signed int)event->m_source);
  v3 = event->m_type;
  if ( v3 )
  {
    if ( v3 == 1 )
      hkpTriggerVolume::addEvent((hkpTriggerVolume *)((char *)this - 16), v2, CONTACT_OP);
  }
  else
  {
    hkpTriggerVolume::addEvent((hkpTriggerVolume *)((char *)this - 16), v2, TOI_OP);
  }
}

// File Line: 310
// RVA: 0xE1ADE0
void __fastcall hkpTriggerVolume::collisionAddedCallback(hkpTriggerVolume *this, hkpCollisionEvent *event)
{
  hkpTriggerVolume *v2; // rbx
  hkpCollisionEvent *v3; // rdi
  hkpConstraintInstance *v4; // rax

  v2 = this;
  v3 = event;
  v4 = (hkpConstraintInstance *)((__int64 (*)(void))event->m_contactMgr->vfptr[8].__vecDelDtor)();
  hkpResponseModifier::disableConstraint(v4, v4->m_owner);
  hkpTriggerVolume::addEvent(
    (hkpTriggerVolume *)((char *)v2 - 16),
    *((hkpRigidBody **)&v3->m_source + 2i64 - (signed int)v3->m_source),
    0);
}

// File Line: 326
// RVA: 0xE1AE40
void __fastcall hkpTriggerVolume::collisionRemovedCallback(hkpTriggerVolume *this, hkpCollisionEvent *event)
{
  hkpTriggerVolume::addEvent(
    (hkpTriggerVolume *)((char *)this - 16),
    *((hkpRigidBody **)&event->m_source + 2i64 - (signed int)event->m_source),
    REMOVED_OP);
}

// File Line: 332
// RVA: 0xE1B850
hkBool *__fastcall hkpTriggerVolume::bodyOrderForQueues(hkBool *result, hkpTriggerVolume::EventInfo *infoA, hkpTriggerVolume::EventInfo *infoB)
{
  result->m_bool = infoA->m_sortValue < infoB->m_sortValue;
  return result;
}

// File Line: 337
// RVA: 0xE1B870
hkBool *__fastcall hkpTriggerVolume::bodyOrderForArrays(hkBool *result, hkpRigidBody *bodyA, hkpRigidBody *bodyB)
{
  result->m_bool = bodyA->m_uid < bodyB->m_uid;
  return result;
}

// File Line: 342
// RVA: 0xE1AE70
void __fastcall hkpTriggerVolume::postSimulationCallback(hkpTriggerVolume *this, hkpWorld *world)
{
  int v2; // er9
  int v3; // eax
  hkpTriggerVolume *v4; // rbp
  int v5; // eax
  signed int v6; // er8
  unsigned __int64 v7; // r14
  hkpRigidBody **v8; // rdi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v9; // r13
  unsigned __int64 v10; // r12
  hkpRigidBody *v11; // rsi
  bool v12; // zf
  hkpTriggerVolume::postSimulationCallback::__l2::States v13; // er15
  hkpEntityListener *v14; // rdx
  __int64 v15; // rax
  signed __int64 v16; // rcx
  signed __int64 v17; // r8
  hkpEntityListener *v18; // rdx
  hkResult result; // [rsp+70h] [rbp+8h]
  hkBool v20; // [rsp+80h] [rbp+18h]

  BYTE4(this->m_eventQueue.m_data) = 1;
  v2 = (int)this->vfptr;
  v3 = HIDWORD(this->m_triggerBody) & 0x3FFFFFFF;
  v4 = this;
  if ( v3 < v2 )
  {
    v5 = 2 * v3;
    if ( v2 < v5 )
      v2 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_eventQueue.m_size,
      v2,
      8);
  }
  v6 = (signed int)v4->m_overlappingBodies.m_data;
  if ( v6 > 1 )
    hkAlgorithm::quickSortRecursive<hkpTriggerVolume::EventInfo,hkBool (*)(hkpTriggerVolume::EventInfo const &,hkpTriggerVolume::EventInfo const &)>(
      (hkpTriggerVolume::EventInfo *)v4->vfptr,
      0,
      v6 - 1,
      hkpTriggerVolume::bodyOrderForQueues);
  v7 = (unsigned __int64)v4->vfptr;
  v8 = (hkpRigidBody **)v4->vfptr;
  v9 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v4->vfptr;
  v10 = (unsigned __int64)&v8[SLODWORD(v4->vfptr)];
  if ( v7 < v7 + 24i64 * SLODWORD(v4->m_overlappingBodies.m_data) )
  {
    do
    {
      v11 = *(hkpRigidBody **)(v7 + 8);
      v12 = v8 == (hkpRigidBody **)v10;
      if ( (unsigned __int64)v8 < v10 )
      {
        do
        {
          if ( !hkpTriggerVolume::bodyOrderForArrays((hkBool *)&result, *v8, v11)->m_bool )
            break;
          if ( LODWORD(v4->m_triggerBody) == (HIDWORD(v4->m_triggerBody) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v4->m_eventQueue.m_size,
              8);
          ++v8;
          *(_QWORD *)(*(_QWORD *)&v4->m_eventQueue.m_size + 8i64 * (signed int)LODWORD(v4->m_triggerBody)++) = *(v8 - 1);
        }
        while ( (unsigned __int64)v8 < v10 );
        v12 = v8 == (hkpRigidBody **)v10;
      }
      if ( v12 || hkpTriggerVolume::bodyOrderForArrays(&v20, v11, *v8)->m_bool )
      {
        v13 = 2;
        hkReferencedObject::addReference((hkReferencedObject *)&v11->vfptr);
      }
      else
      {
        v13 = 1;
        ++v8;
      }
      do
      {
        v13 = transitions[0][*(signed int *)(v7 + 16) + 4i64 * (signed int)v13];
        hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
        v7 += 24i64;
      }
      while ( (hkpEntityListenerVtbl *)v7 < (hkpEntityListenerVtbl *)((char *)v4->vfptr
                                                                    + 24 * SLODWORD(v4->m_overlappingBodies.m_data))
           && *(hkpRigidBody **)(v7 + 8) == v11 );
      v9 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v4->vfptr;
      switch ( 0x40000000 )
      {
        case 0:
          if ( LODWORD(v4->m_triggerBody) == (HIDWORD(v4->m_triggerBody) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v4->m_eventQueue.m_size,
              8);
          *(_QWORD *)(*(_QWORD *)&v4->m_eventQueue.m_size + 8i64 * (signed int)LODWORD(v4->m_triggerBody)++) = v11;
          break;
        case 1:
          goto $LN7_216;
        case 2:
        case 3:
          if ( LODWORD(v4->m_triggerBody) == (HIDWORD(v4->m_triggerBody) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v4->m_eventQueue.m_size,
              8);
          *(_QWORD *)(*(_QWORD *)&v4->m_eventQueue.m_size + 8i64 * (signed int)LODWORD(v4->m_triggerBody)++) = v11;
          if ( v4 == (hkpTriggerVolume *)24 )
            v14 = 0i64;
          else
            v14 = (hkpEntityListener *)&v4->m_memSizeAndFlags;
          hkpEntity::addEntityListener((hkpEntity *)&v11->vfptr, v14);
          (*(void (__fastcall **)(unsigned int *, hkpRigidBody *, signed __int64))(*(_QWORD *)&v4[-1].m_sequenceNumber
                                                                                 + 32i64))(
            &v4[-1].m_sequenceNumber,
            v11,
            1i64);
          v10 = (unsigned __int64)v9->m_data + 8 * SLODWORD(v4->vfptr);
          break;
        case 4:
          v15 = *(_QWORD *)&v4[-1].m_sequenceNumber;
          v16 = (signed __int64)&v4[-1].m_sequenceNumber;
          v17 = 3i64;
          goto LABEL_35;
        case 5:
          if ( v4 == (hkpTriggerVolume *)24 )
            v18 = 0i64;
          else
            v18 = (hkpEntityListener *)&v4->m_memSizeAndFlags;
          hkpEntity::removeEntityListener((hkpEntity *)&v11->vfptr, v18);
          v15 = *(_QWORD *)&v4[-1].m_sequenceNumber;
          v17 = 2i64;
          v16 = (signed __int64)&v4[-1].m_sequenceNumber;
LABEL_35:
          (*(void (__fastcall **)(signed __int64, hkpRigidBody *, signed __int64))(v15 + 32))(v16, v11, v17);
          v10 = (unsigned __int64)v9->m_data + 8 * SLODWORD(v4->vfptr);
$LN7_216:
          hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
          break;
        default:
          break;
      }
    }
    while ( (hkpEntityListenerVtbl *)v7 < (hkpEntityListenerVtbl *)((char *)v4->vfptr
                                                                  + 24 * SLODWORD(v4->m_overlappingBodies.m_data)) );
  }
  for ( ; (unsigned __int64)v8 < v10; ++LODWORD(v4->m_triggerBody) )
  {
    if ( LODWORD(v4->m_triggerBody) == (HIDWORD(v4->m_triggerBody) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_eventQueue.m_size,
        8);
    ++v8;
    *(_QWORD *)(*(_QWORD *)&v4->m_eventQueue.m_size + 8i64 * SLODWORD(v4->m_triggerBody)) = *(v8 - 1);
  }
  LODWORD(v4->m_overlappingBodies.m_data) = 0;
  LODWORD(v4->m_eventQueue.m_data) = 0;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v9,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v4->m_eventQueue.m_size);
  LODWORD(v4->m_triggerBody) = 0;
  BYTE4(v4->m_eventQueue.m_data) = 0;
}

// File Line: 476
// RVA: 0xE1A7B0
void __fastcall hkpTriggerVolume::updateOverlaps(hkpTriggerVolume *this)
{
  __int64 v1; // rdi
  hkpTriggerVolume *v2; // r14
  __int64 v3; // rbx
  hkpRigidBody *v4; // r15
  int v5; // ecx
  __int64 v6; // rsi
  __int64 v7; // rdi
  hkpLinkedCollidable::CollisionEntry *v8; // rdx
  hkpContactMgr *v9; // rax
  hkpLinkedCollidable *v10; // rax
  hkpRigidBody *v11; // rbx
  int v12; // er9
  int v13; // eax
  int v14; // eax
  hkpEntity **v15; // rdi
  hkReferencedObject **v16; // rsi
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // r13
  hkpRigidBody *v19; // r15
  hkpRigidBody *v20; // rbp
  unsigned __int64 v21; // rdi
  int v22; // er8
  hkpRigidBody **array; // [rsp+30h] [rbp-48h]
  int v24; // [rsp+38h] [rbp-40h]
  int v25; // [rsp+3Ch] [rbp-3Ch]
  hkResult result; // [rsp+80h] [rbp+8h]
  hkBool v27; // [rsp+88h] [rbp+10h]
  unsigned __int64 v28; // [rsp+90h] [rbp+18h]

  this->m_isProcessingBodyOverlaps.m_bool = 1;
  v1 = this->m_eventQueue.m_size;
  v2 = this;
  if ( v1 > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_eventQueue.m_data[v3].m_body->vfptr);
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  v2->m_eventQueue.m_size = 0;
  v4 = v2->m_triggerBody;
  v5 = 0;
  array = 0i64;
  v24 = 0;
  v25 = 2147483648;
  v6 = v4->m_collidable.m_collisionEntries.m_size;
  if ( v6 > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v4->m_collidable.m_collisionEntries.m_data;
      v9 = v8[v7].m_agentEntry->m_contactMgr;
      if ( v9->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR && *(_WORD *)(*(_QWORD *)&v9[4].m_memSizeAndFlags + 4i64) )
      {
        v10 = v8[v7].m_partner;
        if ( v10->m_broadPhaseHandle.m_type == 1 )
          v11 = (hkpRigidBody *)((char *)v10 + v10->m_ownerOffset);
        else
          v11 = 0i64;
        if ( v5 == (v25 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v5 = v24;
        }
        array[v5] = v11;
        v5 = v24++ + 1;
      }
      ++v7;
      --v6;
    }
    while ( v6 );
    if ( v5 > 1 )
    {
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        array,
        0,
        v5 - 1,
        hkpTriggerVolume::bodyOrderForArrays);
      v5 = v24;
    }
  }
  v12 = v2->m_overlappingBodies.m_size;
  v13 = v2->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_newOverlappingBodies,
      v12,
      8);
    v5 = v24;
  }
  v15 = (hkpEntity **)array;
  v16 = (hkReferencedObject **)v2->m_overlappingBodies.m_data;
  v17 = (unsigned __int64)&array[v5];
  v18 = (unsigned __int64)&v16[v2->m_overlappingBodies.m_size];
  v28 = v17;
  if ( (unsigned __int64)array < v17 )
  {
    while ( (unsigned __int64)v16 < v18 )
    {
      v19 = (hkpRigidBody *)*v16;
      v20 = (hkpRigidBody *)*v15;
      if ( hkpTriggerVolume::bodyOrderForArrays((hkBool *)&result, (hkpRigidBody *)*v15, (hkpRigidBody *)*v16)->m_bool )
      {
        hkReferencedObject::addReference((hkReferencedObject *)&v20->vfptr);
        hkpEntity::addEntityListener(*v15, (hkpEntityListener *)&v2->vfptr);
        if ( v2->m_newOverlappingBodies.m_size == (v2->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v2->m_newOverlappingBodies,
            8);
        v2->m_newOverlappingBodies.m_data[v2->m_newOverlappingBodies.m_size++] = (hkpRigidBody *)*v15;
        ((void (__fastcall *)(hkpTriggerVolume *, hkpEntity *, signed __int64))v2->vfptr[2].__vecDelDtor)(
          v2,
          *v15,
          1i64);
        v18 = (unsigned __int64)&v2->m_overlappingBodies.m_data[v2->m_overlappingBodies.m_size];
        ++v15;
      }
      else
      {
        if ( hkpTriggerVolume::bodyOrderForArrays(&v27, v19, v20)->m_bool )
        {
          hkpEntity::removeEntityListener((hkpEntity *)&v19->vfptr, (hkpEntityListener *)&v2->vfptr);
          ((void (__fastcall *)(hkpTriggerVolume *, hkpRigidBody *, signed __int64))v2->vfptr[2].__vecDelDtor)(
            v2,
            (hkpRigidBody *)*v16,
            2i64);
          v18 = (unsigned __int64)&v2->m_overlappingBodies.m_data[v2->m_overlappingBodies.m_size];
          hkReferencedObject::removeReference(*v16);
        }
        else
        {
          if ( v2->m_newOverlappingBodies.m_size == (v2->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v2->m_newOverlappingBodies,
              8);
          v2->m_newOverlappingBodies.m_data[v2->m_newOverlappingBodies.m_size++] = (hkpRigidBody *)*v15;
          ++v15;
        }
        ++v16;
      }
      v17 = v28;
      if ( (unsigned __int64)v15 >= v28 )
        goto LABEL_39;
    }
    for ( ;
          (unsigned __int64)v15 < v17;
          v18 = (unsigned __int64)&v2->m_overlappingBodies.m_data[v2->m_overlappingBodies.m_size] )
    {
      hkReferencedObject::addReference((hkReferencedObject *)&(*v15)->vfptr);
      hkpEntity::addEntityListener(*v15, (hkpEntityListener *)&v2->vfptr);
      if ( v2->m_newOverlappingBodies.m_size == (v2->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v2->m_newOverlappingBodies,
          8);
      v2->m_newOverlappingBodies.m_data[v2->m_newOverlappingBodies.m_size++] = (hkpRigidBody *)*v15;
      ((void (__fastcall *)(hkpTriggerVolume *, hkpEntity *, signed __int64))v2->vfptr[2].__vecDelDtor)(v2, *v15, 1i64);
      ++v15;
    }
  }
LABEL_39:
  if ( (unsigned __int64)v16 < v18 )
  {
    do
    {
      hkpEntity::removeEntityListener((hkpEntity *)*v16, (hkpEntityListener *)&v2->vfptr);
      ((void (__fastcall *)(hkpTriggerVolume *, hkReferencedObject *, signed __int64))v2->vfptr[2].__vecDelDtor)(
        v2,
        *v16,
        2i64);
      v21 = (unsigned __int64)&v2->m_overlappingBodies.m_data[v2->m_overlappingBodies.m_size];
      hkReferencedObject::removeReference(*v16);
      ++v16;
    }
    while ( (unsigned __int64)v16 < v21 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_overlappingBodies,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_newOverlappingBodies);
  v22 = v25;
  v2->m_newOverlappingBodies.m_size = 0;
  v24 = 0;
  v2->m_isProcessingBodyOverlaps.m_bool = 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v22);
}

