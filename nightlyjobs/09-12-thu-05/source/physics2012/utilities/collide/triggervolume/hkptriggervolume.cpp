// File Line: 22
// RVA: 0xE1A680
void __fastcall hkpTriggerVolume::hkpTriggerVolume(hkpTriggerVolume *this, hkpRigidBody *triggerBody)
{
  hkpWorld *m_world; // rdx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpTriggerVolume::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpContactListener};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpWorldPostSimulationListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpEntityListener};
  this->m_overlappingBodies.m_capacityAndFlags = 0x80000000;
  this->m_overlappingBodies.m_data = 0i64;
  this->m_overlappingBodies.m_size = 0;
  this->m_eventQueue.m_data = 0i64;
  this->m_eventQueue.m_size = 0;
  this->m_eventQueue.m_capacityAndFlags = 0x80000000;
  this->m_triggerBody = triggerBody;
  this->m_sequenceNumber = 0;
  this->m_isProcessingBodyOverlaps.m_bool = 0;
  this->m_newOverlappingBodies.m_data = 0i64;
  this->m_newOverlappingBodies.m_size = 0;
  this->m_newOverlappingBodies.m_capacityAndFlags = 0x80000000;
  hkpEntity::addContactListener(triggerBody, &this->hkpContactListener);
  hkpEntity::addEntityListener(triggerBody, &this->hkpEntityListener);
  hkpWorldObject::addProperty(triggerBody, 0x1310u, (hkSimplePropertyValue)this);
  hkpWorldObject::addProperty(triggerBody, 0x1130u, (hkSimplePropertyValue)(int)HK_TRIGGER_VOLUME_DEBUG_COLOR_0);
  m_world = triggerBody->m_world;
  if ( m_world )
    hkpTriggerVolume::triggerBodyEnteredWorld(this, m_world);
  hkReferencedObject::addReference(this);
}

// File Line: 38
// RVA: 0xE1A770
void __fastcall hkpTriggerVolume::hkpTriggerVolume(hkpTriggerVolume *this, hkFinishLoadedObjectFlag f)
{
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpTriggerVolume::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpContactListener};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpWorldPostSimulationListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpEntityListener};
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
  hkpWorldPostSimulationListener *v3; // rdx
  hkpWorld *v4; // rdx

  if ( this )
    v3 = &this->hkpWorldPostSimulationListener;
  else
    v3 = 0i64;
  hkpWorld::addWorldPostSimulationListener(world, v3);
  hkpWorldExtension::requireExtension<hkpCollisionCallbackUtil>((hkpWorldExtension *)world, v4);
}

// File Line: 102
// RVA: 0xE1B780
void __fastcall hkpTriggerVolume::triggerBodyLeftWorld(hkpTriggerVolume *this)
{
  hkpWorld *m_world; // rdi
  hkpWorld *v3; // rdx
  __int64 m_size; // rsi
  __int64 i; // rdi
  __int64 v6; // rsi
  __int64 v7; // rdi

  m_world = this->m_triggerBody->m_world;
  hkpWorld::removeWorldPostSimulationListener(m_world, &this->hkpWorldPostSimulationListener);
  hkpWorldExtension::releaseExtension<hkpCollisionCallbackUtil>((hkpWorldExtension *)m_world, v3);
  m_size = this->m_overlappingBodies.m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    hkpEntity::removeEntityListener(this->m_overlappingBodies.m_data[i], &this->hkpEntityListener);
    ((void (__fastcall *)(hkpTriggerVolume *, hkpRigidBody *, __int64))this->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(
      this,
      this->m_overlappingBodies.m_data[i],
      6i64);
    hkReferencedObject::removeReference(this->m_overlappingBodies.m_data[i]);
  }
  v6 = this->m_eventQueue.m_size;
  if ( v6 > 0 )
  {
    v7 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_eventQueue.m_data[v7++].m_body);
      --v6;
    }
    while ( v6 );
  }
  this->m_eventQueue.m_size = 0;
  this->m_overlappingBodies.m_size = 0;
}

// File Line: 123
// RVA: 0xE1B710
void __fastcall hkpTriggerVolume::entityShapeSetCallback(hkpTriggerVolume *this, hkpEntity *entity)
{
  __int64 vfptr_low; // rax

  vfptr_low = SLODWORD(this->hkpEntityListener::vfptr);
  if ( (_DWORD)vfptr_low )
  {
    if ( LODWORD(this->hkpWorldPostSimulationListener::vfptr[vfptr_low - 1].inactiveEntityMovedCallback) == 1 )
      this->hkReferencedObject::hkBaseObject::vfptr[1].__vecDelDtor(this, (unsigned int)entity);
  }
}

// File Line: 137
// RVA: 0xE1B270
void __fastcall hkpTriggerVolume::entityRemovedCallback(hkpTriggerVolume *this, hkpRigidBody *entity)
{
  hkpEntityListener *v4; // r13
  int v5; // r15d
  hkpTriggerVolume::EventInfo *m_data; // r12
  int v7; // ebp
  int v8; // r14d
  int v9; // ebx
  hkpRigidBody *v10; // rbx
  unsigned __int64 *v11; // rcx
  int v12; // edx
  __int64 v13; // rdx
  unsigned __int64 v14; // rax
  __int64 v15; // r12
  int v16; // ebx
  int v17; // r14d
  int v18; // ebp
  hkpRigidBody *v19; // rbp
  __int64 v20; // rdx
  int v21; // r9d
  __int64 v22; // rcx
  __int64 v23; // rax
  int v24; // ebx
  __int64 v25; // rdx
  hkpEntity **v26; // r8
  int v27; // ebp
  __int64 v28; // rdx
  hkpEntity **v29; // r8
  int v30; // ebx
  __int64 v31; // r14
  int v32; // r9d
  hkpWorldPostSimulationListenerVtbl *v33; // rcx
  __int64 v34; // rdx
  void (__fastcall *v35)(hkpWorldPostSimulationListener *, hkpEntity *); // rax
  __int64 v36; // rbx
  hkpWorldPostSimulationListenerVtbl *v37; // rcx
  int v38; // edx
  __int64 v39; // rdx
  void (__fastcall *vecDelDtor)(hkpWorldPostSimulationListener *, hkpEntity *); // rax
  __int64 v41; // r12
  int v42; // ebx
  int v43; // r14d
  int v44; // ebp
  hkpRigidBody *v45; // rbp
  __int64 v46; // rdx
  int v47; // r9d
  __int64 v48; // rcx
  __int64 v49; // rax
  __int64 v50; // r14
  __int64 v51; // rbx
  hkpEntity *postSimulationCallback; // rcx
  __int64 v53; // rax
  hkpWorldPostSimulationListenerVtbl *vfptr; // rdx
  hkpWorldPostSimulationListenerVtbl *v55; // r8
  hkpWorldPostSimulationListenerVtbl *v56; // rcx
  __int64 v57; // rdx
  signed __int64 v58; // r8
  void (__fastcall *v59)(hkpWorldPostSimulationListener *, hkpEntity *); // rax
  hkBool result; // [rsp+50h] [rbp+8h] BYREF

  if ( entity == (hkpRigidBody *)this->m_overlappingBodies.m_data )
  {
    hkpTriggerVolume::triggerBodyLeftWorld((hkpTriggerVolume *)((char *)this - 32));
  }
  else
  {
    v4 = 0i64;
    v5 = LODWORD(this->hkpEntityListener::vfptr) - 1;
    if ( LOBYTE(this->m_overlappingBodies.m_capacityAndFlags) )
    {
      m_data = this->m_eventQueue.m_data;
      v7 = 0;
      v8 = this->m_eventQueue.m_size - 1;
      if ( v8 > 0 )
      {
        do
        {
          v9 = (v8 + v7) >> 1;
          if ( hkpTriggerVolume::bodyOrderForArrays(&result, *((hkpRigidBody **)&m_data->m_sortValue + v9), entity)->m_bool )
            v7 = v9 + 1;
          else
            v8 = (v8 + v7) >> 1;
        }
        while ( v8 > v7 );
      }
      if ( v7 != v8
        || (v10 = (hkpRigidBody *)*(&m_data->m_sortValue + v7),
            hkpTriggerVolume::bodyOrderForArrays(&result, v10, entity)->m_bool)
        || hkpTriggerVolume::bodyOrderForArrays(&result, entity, v10)->m_bool
        || v7 < 0 )
      {
        v15 = *(_QWORD *)&this->m_memSizeAndFlags;
        v16 = 0;
        v17 = LODWORD(this->hkpContactListener::vfptr) - 1;
        if ( v17 > 0 )
        {
          do
          {
            v18 = (v17 + v16) >> 1;
            if ( hkpTriggerVolume::bodyOrderForArrays(&result, *(hkpRigidBody **)(v15 + 8i64 * v18), entity)->m_bool )
              v16 = v18 + 1;
            else
              v17 = (v17 + v16) >> 1;
          }
          while ( v17 > v16 );
        }
        if ( v16 != v17
          || (v19 = *(hkpRigidBody **)(v15 + 8i64 * v16),
              hkpTriggerVolume::bodyOrderForArrays(&result, v19, entity)->m_bool)
          || hkpTriggerVolume::bodyOrderForArrays(&result, entity, v19)->m_bool )
        {
          v16 = -1;
        }
        --LODWORD(this->hkpContactListener::vfptr);
        v20 = v15 + 8i64 * v16;
        v21 = 8 * (LODWORD(this->hkpContactListener::vfptr) - v16);
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
          v26 = (hkpEntity **)(&this->hkpWorldPostSimulationListener::vfptr->postSimulationCallback + 2 * v24 + v24);
          do
          {
            if ( *v26 == entity )
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
              v29 = (hkpEntity **)((char *)this->hkpWorldPostSimulationListener::vfptr + 16 * v24 + 8 * v24 - 16);
              do
              {
                if ( *v29 != entity )
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
                hkReferencedObject::removeReference(entity);
                --v31;
              }
              while ( v31 );
            }
            LODWORD(this->hkpEntityListener::vfptr) -= v30;
            v32 = 24 * (LODWORD(this->hkpEntityListener::vfptr) - v27);
            v33 = &this->hkpWorldPostSimulationListener::vfptr[v27];
            if ( v32 > 0 )
            {
              v34 = ((unsigned int)(v32 - 1) >> 3) + 1;
              do
              {
                v35 = *(void (__fastcall **)(hkpWorldPostSimulationListener *, hkpEntity *))((char *)&v33->__vecDelDtor
                                                                                           + 24 * (v27 + (__int64)v30)
                                                                                           - 24i64 * v27);
                v33 = (hkpWorldPostSimulationListenerVtbl *)((char *)v33 + 8);
                v33[-1].inactiveEntityMovedCallback = v35;
                --v34;
              }
              while ( v34 );
            }
          }
        }
      }
      else
      {
        --this->m_eventQueue.m_size;
        v11 = &m_data->m_sortValue + v7;
        v12 = 8 * (this->m_eventQueue.m_size - v7);
        if ( v12 > 0 )
        {
          v13 = ((unsigned int)(v12 - 1) >> 3) + 1;
          do
          {
            v14 = v11[1];
            *v11++ = v14;
            --v13;
          }
          while ( v13 );
        }
      }
      v36 = v5;
      hkReferencedObject::removeReference((hkReferencedObject *)this->hkpWorldPostSimulationListener::vfptr[v36].postSimulationCallback);
      --LODWORD(this->hkpEntityListener::vfptr);
      v37 = &this->hkpWorldPostSimulationListener::vfptr[v36];
      v38 = 24 * (LODWORD(this->hkpEntityListener::vfptr) - v5);
      if ( v38 > 0 )
      {
        v39 = ((unsigned int)(v38 - 1) >> 3) + 1;
        do
        {
          vecDelDtor = (void (__fastcall *)(hkpWorldPostSimulationListener *, hkpEntity *))v37[1].__vecDelDtor;
          v37 = (hkpWorldPostSimulationListenerVtbl *)((char *)v37 + 8);
          v37[-1].inactiveEntityMovedCallback = vecDelDtor;
          --v39;
        }
        while ( v39 );
      }
    }
    else
    {
      v41 = *(_QWORD *)&this->m_memSizeAndFlags;
      v42 = 0;
      v43 = LODWORD(this->hkpContactListener::vfptr) - 1;
      if ( v43 > 0 )
      {
        do
        {
          v44 = (v43 + v42) >> 1;
          if ( hkpTriggerVolume::bodyOrderForArrays(&result, *(hkpRigidBody **)(v41 + 8i64 * v44), entity)->m_bool )
            v42 = v44 + 1;
          else
            v43 = (v43 + v42) >> 1;
        }
        while ( v43 > v42 );
      }
      if ( v42 != v43
        || (v45 = *(hkpRigidBody **)(v41 + 8i64 * v42),
            hkpTriggerVolume::bodyOrderForArrays(&result, v45, entity)->m_bool)
        || hkpTriggerVolume::bodyOrderForArrays(&result, entity, v45)->m_bool )
      {
        v42 = -1;
      }
      --LODWORD(this->hkpContactListener::vfptr);
      v46 = v41 + 8i64 * v42;
      v47 = 8 * (LODWORD(this->hkpContactListener::vfptr) - v42);
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
          postSimulationCallback = (hkpEntity *)this->hkpWorldPostSimulationListener::vfptr[v51].postSimulationCallback;
          if ( postSimulationCallback == entity )
          {
            hkReferencedObject::removeReference(postSimulationCallback);
            v53 = (int)--LODWORD(this->hkpEntityListener::vfptr);
            if ( (_DWORD)v53 != v5 )
            {
              vfptr = this->hkpWorldPostSimulationListener::vfptr;
              v55 = &vfptr[v53];
              v56 = &vfptr[v51];
              v57 = 3i64;
              v58 = (char *)v55 - (char *)v56;
              do
              {
                v59 = *(void (__fastcall **)(hkpWorldPostSimulationListener *, hkpEntity *))((char *)&v56->__vecDelDtor
                                                                                           + v58);
                v56 = (hkpWorldPostSimulationListenerVtbl *)((char *)v56 + 8);
                v56[-1].inactiveEntityMovedCallback = v59;
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
    ((void (__fastcall *)(hkpRigidBody **, hkpRigidBody *, __int64))this[-1].m_triggerBody->m_collidable.m_shape)(
      &this[-1].m_triggerBody,
      entity,
      2i64);
    if ( this != (hkpTriggerVolume *)32 )
      v4 = (hkpEntityListener *)this;
    hkpEntity::removeEntityListener(entity, v4);
    hkReferencedObject::removeReference(entity);
  }
}

// File Line: 255
// RVA: 0xE1B1D0
void __fastcall hkpTriggerVolume::entityDeletedCallback(hkpTriggerVolume *this, hkpEntity *entity)
{
  hkpEntityListener *v4; // rdx
  hkpContactListener *p_m_newOverlappingBodies; // rdx

  if ( *((_QWORD *)this->m_overlappingBodies.m_data + 2) )
    hkpTriggerVolume::triggerBodyLeftWorld((hkpTriggerVolume *)((char *)this - 32));
  v4 = 0i64;
  if ( this != (hkpTriggerVolume *)32 )
    v4 = (hkpEntityListener *)this;
  hkpEntity::removeEntityListener(entity, v4);
  if ( this == (hkpTriggerVolume *)32 )
    p_m_newOverlappingBodies = 0i64;
  else
    p_m_newOverlappingBodies = (hkpContactListener *)&this[-1].m_newOverlappingBodies;
  hkpEntity::removeContactListener(entity, p_m_newOverlappingBodies);
  this->m_overlappingBodies.m_data = 0i64;
  hkReferencedObject::removeReference((hkpTriggerVolume *)((char *)this - 32));
}

// File Line: 269
// RVA: 0xE1ABA0
void __fastcall hkpTriggerVolume::~hkpTriggerVolume(hkpTriggerVolume *this)
{
  hkpRigidBody *m_triggerBody; // rcx
  hkpEntity **m_data; // rdi
  __int64 m_size; // rsi
  __int64 v5; // rdi
  int m_capacityAndFlags; // r8d
  int v7; // eax
  int v8; // r8d
  hkSimplePropertyValue result; // [rsp+40h] [rbp+8h] BYREF

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpTriggerVolume::`vftable{for `hkReferencedObject};
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpContactListener};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpWorldPostSimulationListener};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpTriggerVolume::`vftable{for `hkpEntityListener};
  m_triggerBody = this->m_triggerBody;
  if ( m_triggerBody )
  {
    hkpWorldObject::removeProperty(m_triggerBody, &result, 0x1130u);
    hkpWorldObject::removeProperty(this->m_triggerBody, &result, 0x1310u);
    hkpEntity::removeEntityListener(this->m_triggerBody, &this->hkpEntityListener);
    hkpEntity::removeContactListener(this->m_triggerBody, &this->hkpContactListener);
  }
  m_data = this->m_overlappingBodies.m_data;
  if ( m_data < &m_data[this->m_overlappingBodies.m_size] )
  {
    do
      hkpEntity::removeEntityListener(*m_data++, &this->hkpEntityListener);
    while ( m_data < &this->m_overlappingBodies.m_data[this->m_overlappingBodies.m_size] );
  }
  hkReferencedObject::removeReferences(this->m_overlappingBodies.m_data, this->m_overlappingBodies.m_size, 8);
  m_size = this->m_eventQueue.m_size;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_eventQueue.m_data[v5++].m_body);
      --m_size;
    }
    while ( m_size );
  }
  this->m_eventQueue.m_size = 0;
  m_capacityAndFlags = this->m_newOverlappingBodies.m_capacityAndFlags;
  this->m_newOverlappingBodies.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_newOverlappingBodies.m_data,
      8 * m_capacityAndFlags);
  this->m_newOverlappingBodies.m_data = 0i64;
  this->m_newOverlappingBodies.m_capacityAndFlags = 0x80000000;
  v7 = this->m_eventQueue.m_capacityAndFlags;
  this->m_eventQueue.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_eventQueue.m_data,
      24 * (v7 & 0x3FFFFFFF));
  this->m_eventQueue.m_data = 0i64;
  this->m_eventQueue.m_capacityAndFlags = 0x80000000;
  v8 = this->m_overlappingBodies.m_capacityAndFlags;
  this->m_overlappingBodies.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_overlappingBodies.m_data,
      8 * v8);
  this->m_overlappingBodies.m_data = 0i64;
  this->m_overlappingBodies.m_capacityAndFlags = 0x80000000;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  this->hkpContactListener::vfptr = (hkpContactListenerVtbl *)&hkpContactListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 290
// RVA: 0xE1AD90
void __fastcall hkpTriggerVolume::contactPointCallback(hkpTriggerVolume *this, hkpContactPointEvent *event)
{
  hkpRigidBody *v2; // r9
  hkpContactPointEvent::Type m_type; // eax

  event->m_contactPointProperties->m_flags |= 8u;
  v2 = (hkpRigidBody *)*((_QWORD *)&event->m_source + 2i64 - (int)event->m_source);
  m_type = event->m_type;
  if ( m_type )
  {
    if ( m_type == TYPE_MANIFOLD )
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
  hkpConstraintInstance *v4; // rax

  v4 = (hkpConstraintInstance *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))event->m_contactMgr->vfptr[8].__vecDelDtor)(event->m_contactMgr);
  hkpResponseModifier::disableConstraint(v4, v4->m_owner);
  hkpTriggerVolume::addEvent(
    (hkpTriggerVolume *)((char *)this - 16),
    *((hkpRigidBody **)&event->m_source + 2i64 - (int)event->m_source),
    ADDED_OP);
}

// File Line: 326
// RVA: 0xE1AE40
void __fastcall hkpTriggerVolume::collisionRemovedCallback(hkpTriggerVolume *this, hkpCollisionEvent *event)
{
  hkpTriggerVolume::addEvent(
    (hkpTriggerVolume *)((char *)this - 16),
    *((hkpRigidBody **)&event->m_source + 2i64 - (int)event->m_source),
    REMOVED_OP);
}

// File Line: 332
// RVA: 0xE1B850
hkBool *__fastcall hkpTriggerVolume::bodyOrderForQueues(
        hkBool *result,
        hkpTriggerVolume::EventInfo *infoA,
        hkpTriggerVolume::EventInfo *infoB)
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
  int vfptr; // r9d
  int v3; // eax
  int v5; // eax
  int m_data; // r8d
  hkpEntityListenerVtbl *v7; // r14
  hkpRigidBody **v8; // rdi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v9; // r13
  unsigned __int64 v10; // r12
  hkpRigidBody *entityAddedCallback; // rsi
  bool v12; // zf
  hkpTriggerVolume::postSimulationCallback::__l2::States v13; // r15d
  unsigned __int16 *p_m_memSizeAndFlags; // rdx
  __int64 v15; // rax
  unsigned int *p_m_sequenceNumber; // rcx
  __int64 v17; // r8
  unsigned __int16 *v18; // rdx
  hkResult result; // [rsp+70h] [rbp+8h] BYREF
  hkBool v20; // [rsp+80h] [rbp+18h] BYREF

  BYTE4(this->m_eventQueue.m_data) = 1;
  vfptr = (int)this->hkpWorldPostSimulationListener::vfptr;
  v3 = HIDWORD(this->m_triggerBody) & 0x3FFFFFFF;
  if ( v3 < vfptr )
  {
    v5 = 2 * v3;
    if ( vfptr < v5 )
      vfptr = v5;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_eventQueue.m_size,
      vfptr,
      8);
  }
  m_data = (int)this->m_overlappingBodies.m_data;
  if ( m_data > 1 )
    hkAlgorithm::quickSortRecursive<hkpTriggerVolume::EventInfo,hkBool (*)(hkpTriggerVolume::EventInfo const &,hkpTriggerVolume::EventInfo const &)>(
      (hkpTriggerVolume::EventInfo *)this->hkpEntityListener::vfptr,
      0,
      m_data - 1,
      hkpTriggerVolume::bodyOrderForQueues);
  v7 = this->hkpEntityListener::vfptr;
  v8 = (hkpRigidBody **)this->hkpContactListener::vfptr;
  v9 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->hkpContactListener;
  v10 = (unsigned __int64)&v8[SLODWORD(this->hkpWorldPostSimulationListener::vfptr)];
  if ( v7 < (hkpEntityListenerVtbl *)((char *)v7 + 24 * SLODWORD(this->m_overlappingBodies.m_data)) )
  {
    do
    {
      entityAddedCallback = (hkpRigidBody *)v7->entityAddedCallback;
      v12 = v8 == (hkpRigidBody **)v10;
      if ( (unsigned __int64)v8 < v10 )
      {
        do
        {
          if ( !hkpTriggerVolume::bodyOrderForArrays((hkBool *)&result, *v8, entityAddedCallback)->m_bool )
            break;
          if ( LODWORD(this->m_triggerBody) == (HIDWORD(this->m_triggerBody) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_eventQueue.m_size, 8);
          *(_QWORD *)(*(_QWORD *)&this->m_eventQueue.m_size + 8i64 * (int)LODWORD(this->m_triggerBody)++) = *v8++;
        }
        while ( (unsigned __int64)v8 < v10 );
        v12 = v8 == (hkpRigidBody **)v10;
      }
      if ( v12 || hkpTriggerVolume::bodyOrderForArrays(&v20, entityAddedCallback, *v8)->m_bool )
      {
        v13 = ERROR_STATE;
        hkReferencedObject::addReference(entityAddedCallback);
      }
      else
      {
        v13 = READY_STATE;
        ++v8;
      }
      do
      {
        v13 = transitions[v13][SLODWORD(v7->entityRemovedCallback)];
        hkReferencedObject::removeReference(entityAddedCallback);
        v7 = (hkpEntityListenerVtbl *)((char *)v7 + 24);
      }
      while ( v7 < (hkpEntityListenerVtbl *)((char *)this->hkpEntityListener::vfptr
                                           + 24 * SLODWORD(this->m_overlappingBodies.m_data))
           && (hkpRigidBody *)v7->entityAddedCallback == entityAddedCallback );
      v9 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->hkpContactListener;
      switch ( v13 )
      {
        case 1:
          if ( LODWORD(this->m_triggerBody) == (HIDWORD(this->m_triggerBody) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_eventQueue.m_size, 8);
          *(_QWORD *)(*(_QWORD *)&this->m_eventQueue.m_size + 8i64 * (int)LODWORD(this->m_triggerBody)++) = entityAddedCallback;
          break;
        case 2:
          goto $LN7_216;
        case 3:
        case 4:
          if ( LODWORD(this->m_triggerBody) == (HIDWORD(this->m_triggerBody) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_eventQueue.m_size, 8);
          *(_QWORD *)(*(_QWORD *)&this->m_eventQueue.m_size + 8i64 * (int)LODWORD(this->m_triggerBody)++) = entityAddedCallback;
          if ( this == (hkpTriggerVolume *)24 )
            p_m_memSizeAndFlags = 0i64;
          else
            p_m_memSizeAndFlags = &this->m_memSizeAndFlags;
          hkpEntity::addEntityListener(entityAddedCallback, (hkpEntityListener *)p_m_memSizeAndFlags);
          (*(void (__fastcall **)(unsigned int *, hkpRigidBody *, __int64))(*(_QWORD *)&this[-1].m_sequenceNumber + 32i64))(
            &this[-1].m_sequenceNumber,
            entityAddedCallback,
            1i64);
          v10 = (unsigned __int64)v9->m_data + 8 * SLODWORD(this->hkpWorldPostSimulationListener::vfptr);
          break;
        case 5:
          v15 = *(_QWORD *)&this[-1].m_sequenceNumber;
          p_m_sequenceNumber = &this[-1].m_sequenceNumber;
          v17 = 3i64;
          goto LABEL_35;
        case 6:
          if ( this == (hkpTriggerVolume *)24 )
            v18 = 0i64;
          else
            v18 = &this->m_memSizeAndFlags;
          hkpEntity::removeEntityListener(entityAddedCallback, (hkpEntityListener *)v18);
          v15 = *(_QWORD *)&this[-1].m_sequenceNumber;
          v17 = 2i64;
          p_m_sequenceNumber = &this[-1].m_sequenceNumber;
LABEL_35:
          (*(void (__fastcall **)(unsigned int *, hkpRigidBody *, __int64))(v15 + 32))(
            p_m_sequenceNumber,
            entityAddedCallback,
            v17);
          v10 = (unsigned __int64)v9->m_data + 8 * SLODWORD(this->hkpWorldPostSimulationListener::vfptr);
$LN7_216:
          hkReferencedObject::removeReference(entityAddedCallback);
          break;
        default:
          break;
      }
    }
    while ( v7 < (hkpEntityListenerVtbl *)((char *)this->hkpEntityListener::vfptr
                                         + 24 * SLODWORD(this->m_overlappingBodies.m_data)) );
  }
  for ( ; (unsigned __int64)v8 < v10; ++LODWORD(this->m_triggerBody) )
  {
    if ( LODWORD(this->m_triggerBody) == (HIDWORD(this->m_triggerBody) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_eventQueue.m_size, 8);
    *(_QWORD *)(*(_QWORD *)&this->m_eventQueue.m_size + 8i64 * SLODWORD(this->m_triggerBody)) = *v8++;
  }
  LODWORD(this->m_overlappingBodies.m_data) = 0;
  LODWORD(this->m_eventQueue.m_data) = 0;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v9,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_eventQueue.m_size);
  LODWORD(this->m_triggerBody) = 0;
  BYTE4(this->m_eventQueue.m_data) = 0;
}

// File Line: 476
// RVA: 0xE1A7B0
void __fastcall hkpTriggerVolume::updateOverlaps(hkpTriggerVolume *this)
{
  __int64 m_size; // rdi
  __int64 v3; // rbx
  hkpRigidBody *m_triggerBody; // r15
  int v5; // ecx
  __int64 v6; // rsi
  __int64 v7; // rdi
  hkpLinkedCollidable::CollisionEntry *m_data; // rdx
  hkpContactMgr *m_contactMgr; // rax
  hkpLinkedCollidable *m_partner; // rax
  hkpRigidBody *v11; // rbx
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  hkpEntity **v15; // rdi
  hkReferencedObject **v16; // rsi
  hkpEntity **v17; // r15
  hkpRigidBody **v18; // r13
  hkpRigidBody *v19; // r15
  hkpRigidBody *v20; // rbp
  hkpRigidBody **v21; // rdi
  int v22; // r8d
  hkpRigidBody **array; // [rsp+30h] [rbp-48h] BYREF
  int v24; // [rsp+38h] [rbp-40h]
  int v25; // [rsp+3Ch] [rbp-3Ch]
  hkResult result; // [rsp+80h] [rbp+8h] BYREF
  hkBool v27; // [rsp+88h] [rbp+10h] BYREF
  unsigned __int64 v28; // [rsp+90h] [rbp+18h]

  this->m_isProcessingBodyOverlaps.m_bool = 1;
  m_size = this->m_eventQueue.m_size;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_eventQueue.m_data[v3++].m_body);
      --m_size;
    }
    while ( m_size );
  }
  this->m_eventQueue.m_size = 0;
  m_triggerBody = this->m_triggerBody;
  v5 = 0;
  array = 0i64;
  v24 = 0;
  v25 = 0x80000000;
  v6 = m_triggerBody->m_collidable.m_collisionEntries.m_size;
  if ( v6 > 0 )
  {
    v7 = 0i64;
    do
    {
      m_data = m_triggerBody->m_collidable.m_collisionEntries.m_data;
      m_contactMgr = m_data[v7].m_agentEntry->m_contactMgr;
      if ( m_contactMgr->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR
        && *(_WORD *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) )
      {
        m_partner = m_data[v7].m_partner;
        if ( m_partner->m_broadPhaseHandle.m_type == 1 )
          v11 = (hkpRigidBody *)((char *)m_partner + m_partner->m_ownerOffset);
        else
          v11 = 0i64;
        if ( v5 == (v25 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v5 = v24;
        }
        array[v5] = v11;
        v5 = ++v24;
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
  v12 = this->m_overlappingBodies.m_size;
  v13 = this->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_newOverlappingBodies.m_data,
      v12,
      8);
    v5 = v24;
  }
  v15 = array;
  v16 = this->m_overlappingBodies.m_data;
  v17 = &array[v5];
  v18 = (hkpRigidBody **)&v16[this->m_overlappingBodies.m_size];
  v28 = (unsigned __int64)v17;
  if ( array < v17 )
  {
    while ( v16 < v18 )
    {
      v19 = (hkpRigidBody *)*v16;
      v20 = (hkpRigidBody *)*v15;
      if ( hkpTriggerVolume::bodyOrderForArrays((hkBool *)&result, (hkpRigidBody *)*v15, (hkpRigidBody *)*v16)->m_bool )
      {
        hkReferencedObject::addReference(v20);
        hkpEntity::addEntityListener(*v15, &this->hkpEntityListener);
        if ( this->m_newOverlappingBodies.m_size == (this->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_newOverlappingBodies.m_data,
            8);
        this->m_newOverlappingBodies.m_data[this->m_newOverlappingBodies.m_size++] = (hkpRigidBody *)*v15;
        ((void (__fastcall *)(hkpTriggerVolume *, hkpEntity *, __int64))this->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(
          this,
          *v15,
          1i64);
        v18 = &this->m_overlappingBodies.m_data[this->m_overlappingBodies.m_size];
        ++v15;
      }
      else
      {
        if ( hkpTriggerVolume::bodyOrderForArrays(&v27, v19, v20)->m_bool )
        {
          hkpEntity::removeEntityListener(v19, &this->hkpEntityListener);
          ((void (__fastcall *)(hkpTriggerVolume *, hkReferencedObject *, __int64))this->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(
            this,
            *v16,
            2i64);
          v18 = &this->m_overlappingBodies.m_data[this->m_overlappingBodies.m_size];
          hkReferencedObject::removeReference(*v16);
        }
        else
        {
          if ( this->m_newOverlappingBodies.m_size == (this->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&this->m_newOverlappingBodies.m_data,
              8);
          this->m_newOverlappingBodies.m_data[this->m_newOverlappingBodies.m_size++] = (hkpRigidBody *)*v15++;
        }
        ++v16;
      }
      v17 = (hkpEntity **)v28;
      if ( (unsigned __int64)v15 >= v28 )
        goto LABEL_39;
    }
    for ( ; v15 < v17; v18 = &this->m_overlappingBodies.m_data[this->m_overlappingBodies.m_size] )
    {
      hkReferencedObject::addReference(*v15);
      hkpEntity::addEntityListener(*v15, &this->hkpEntityListener);
      if ( this->m_newOverlappingBodies.m_size == (this->m_newOverlappingBodies.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&this->m_newOverlappingBodies.m_data,
          8);
      this->m_newOverlappingBodies.m_data[this->m_newOverlappingBodies.m_size++] = (hkpRigidBody *)*v15;
      ((void (__fastcall *)(hkpTriggerVolume *, _QWORD, __int64))this->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(
        this,
        *v15++,
        1i64);
    }
  }
LABEL_39:
  if ( v16 < v18 )
  {
    do
    {
      hkpEntity::removeEntityListener((hkpEntity *)*v16, &this->hkpEntityListener);
      ((void (__fastcall *)(hkpTriggerVolume *, hkReferencedObject *, __int64))this->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(
        this,
        *v16,
        2i64);
      v21 = &this->m_overlappingBodies.m_data[this->m_overlappingBodies.m_size];
      hkReferencedObject::removeReference(*v16++);
    }
    while ( v16 < v21 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_overlappingBodies,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_newOverlappingBodies);
  v22 = v25;
  this->m_newOverlappingBodies.m_size = 0;
  v24 = 0;
  this->m_isProcessingBodyOverlaps.m_bool = 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v22);
}

