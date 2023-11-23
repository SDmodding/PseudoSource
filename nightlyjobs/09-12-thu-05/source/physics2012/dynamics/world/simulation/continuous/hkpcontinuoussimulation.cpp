// File Line: 167
// RVA: 0xD6C540
void __fastcall hkpContinuousSimulation::hkpContinuousSimulation(hkpContinuousSimulation *this, hkpWorld *world)
{
  _QWORD **Value; // rax
  hkpDefaultToiResourceMgr *v5; // rax
  hkpToiResourceMgr *v6; // rax
  int m_sizeOfToiEventQueue; // r9d
  int v8; // eax
  int v9; // eax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  hkpSimulation::hkpSimulation(this, world);
  this->vfptr = (hkBaseObjectVtbl *)&hkpContinuousSimulation::`vftable;
  this->m_toiEvents.m_data = 0i64;
  this->m_toiEvents.m_size = 0;
  this->m_toiEvents.m_capacityAndFlags = 0x80000000;
  this->m_entitiesNeedingPsiCollisionDetection.m_map.m_elem = 0i64;
  this->m_entitiesNeedingPsiCollisionDetection.m_map.m_numElems = 0;
  this->m_entitiesNeedingPsiCollisionDetection.m_map.m_hashMod = -1;
  this->m_lastProcessingStep.m_storage = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpDefaultToiResourceMgr *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 24i64);
  if ( v5 )
    hkpDefaultToiResourceMgr::hkpDefaultToiResourceMgr(v5);
  else
    v6 = 0i64;
  this->m_toiResourceMgr = v6;
  this->m_toiCounter = 0;
  m_sizeOfToiEventQueue = world->m_sizeOfToiEventQueue;
  v8 = this->m_toiEvents.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < m_sizeOfToiEventQueue )
  {
    v9 = 2 * v8;
    if ( m_sizeOfToiEventQueue < v9 )
      m_sizeOfToiEventQueue = v9;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_toiEvents.m_data,
      m_sizeOfToiEventQueue,
      144);
  }
}

// File Line: 231
// RVA: 0xD6C620
void __fastcall hkpContinuousSimulation::~hkpContinuousSimulation(hkpContinuousSimulation *this)
{
  hkpToiResourceMgr *m_toiResourceMgr; // rcx
  int m_capacityAndFlags; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkpContinuousSimulation::`vftable;
  m_toiResourceMgr = this->m_toiResourceMgr;
  if ( m_toiResourceMgr )
    m_toiResourceMgr->vfptr->__vecDelDtor(m_toiResourceMgr, 1u);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_entitiesNeedingPsiCollisionDetection.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_entitiesNeedingPsiCollisionDetection);
  m_capacityAndFlags = this->m_toiEvents.m_capacityAndFlags;
  this->m_toiEvents.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_toiEvents.m_data,
      144 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_toiEvents.m_data = 0i64;
  this->m_toiEvents.m_capacityAndFlags = 0x80000000;
  hkpSimulation::~hkpSimulation(this);
}

// File Line: 246
// RVA: 0xD6C6C0
void __fastcall hkpContinuousSimulation::create(hkpWorld *world)
{
  _QWORD **Value; // rax
  hkpContinuousSimulation *v3; // rax

  hkOptionalComponent_hkpContinuousSimulation.m_isUsed.m_bool = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpContinuousSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  if ( v3 )
    hkpContinuousSimulation::hkpContinuousSimulation(v3, world);
}

// File Line: 250
// RVA: 0x15D2190
void dynamic_initializer_for__hkOptionalComponent_hkpContinuousSimulation__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpContinuousSimulation,
    "hkpContinuousSimulation",
    (void **)&hkpSimulation::createContinuous,
    hkpContinuousSimulation::create);
}

// File Line: 277
// RVA: 0xD6E480
__int64 __fastcall hkpContinuousSimulation::handleAllToisTill(hkpContinuousSimulation *this, float minTime)
{
  unsigned int v3; // esi
  hkpWorld *m_world; // rax
  int v6; // r14d
  __int64 v7; // rbx
  int m_size; // r12d
  float m_time; // xmm1_4
  int v10; // edx
  __int64 v11; // r8
  hkpToiEvent *m_data; // r13
  __int64 v13; // r9
  hkpToiEvent *v14; // rcx
  unsigned int m_uid; // r10d
  unsigned int v16; // r11d
  hkpToiEvent *v17; // r8
  hkpDynamicsContactMgr *m_contactMgr; // rcx
  __int64 v19; // rax
  hkpToiEvent *v20; // rcx
  hkpToiEvent *v21; // rdx
  hkpToiEvent *v22; // r8
  __int64 v23; // rcx
  signed __int64 v24; // r8
  unsigned __int64 v25; // rax
  hkpToiEvent *v26; // rax
  hkVector4f v27; // xmm0
  __int64 v28; // rax
  hkpToiEvent *v29; // rdx
  __int64 v30; // rcx
  char *v31; // r8
  unsigned __int64 v32; // rax
  int v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  hkpWorld *v36; // rdx
  hkpWorld *v37; // rbx
  bool v38; // zf
  hkpWorld *v39; // rbx
  _BYTE v41[56]; // [rsp+30h] [rbp-71h] BYREF
  __int128 event_48; // [rsp+68h] [rbp-39h]
  hkVector4f event_64; // [rsp+78h] [rbp-29h]
  __m128 event_80; // [rsp+88h] [rbp-19h]
  float rotateNormal; // [rsp+108h] [rbp+67h] BYREF
  char v46[8]; // [rsp+110h] [rbp+6Fh] BYREF
  hkpWorld *v47; // [rsp+118h] [rbp+77h]

  v3 = 0;
LABEL_2:
  m_world = this->m_world;
  v6 = -1;
  v7 = -1i64;
  ++m_world->m_criticalOperationsLockCount;
  v47 = m_world;
  while ( 1 )
  {
    m_size = this->m_toiEvents.m_size;
    m_time = minTime;
    v10 = 0;
    v11 = 0i64;
    rotateNormal = this->m_world->m_toiCollisionResponseRotateNormal;
    if ( m_size <= 0 )
      break;
    m_data = this->m_toiEvents.m_data;
    v13 = -144i64;
    v14 = m_data;
    do
    {
      if ( v14->m_time < m_time
        || v14->m_time == m_time
        && v7 != -1
        && ((m_uid = v14->m_entities[0]->m_uid,
             v16 = (*(hkpEntity **)((char *)m_data->m_entities + v13))->m_uid,
             m_uid < v16)
         || m_uid == v16 && v14->m_entities[1]->m_uid < (*(hkpEntity **)((char *)&m_data->m_entities[1] + v13))->m_uid) )
      {
        m_time = v14->m_time;
        v13 = (char *)v14 - (char *)m_data;
        v7 = v11;
        v6 = v10;
      }
      ++v10;
      ++v11;
      ++v14;
    }
    while ( v10 < m_size );
    if ( v7 < 0 )
    {
      v3 = 0;
      break;
    }
    v17 = &m_data[v7];
    m_contactMgr = v17->m_contactMgr;
    v17->m_properties.m_flags |= 1u;
    if ( *(_BYTE *)((__int64 (__fastcall *)(hkpDynamicsContactMgr *, char *, hkpToiEvent *, float *))m_contactMgr->vfptr[8].__first_virtual_table_function__)(
                     m_contactMgr,
                     v46,
                     v17,
                     &rotateNormal) )
    {
      v26 = this->m_toiEvents.m_data;
      *(_OWORD *)&v41[16] = *(_OWORD *)&v26[v7].m_time;
      *(_OWORD *)&v41[32] = *(_OWORD *)v26[v7].m_entities;
      *(hkContactPointMaterial *)&v41[8] = v26[v7].m_properties.hkContactPointMaterial;
      *(_OWORD *)&v41[24] = *(_OWORD *)&v26[v7].m_properties.m_internalDataA;
      *(_OWORD *)&v41[40] = *(_OWORD *)&v26[v7].m_extendedUserDatas[2];
      event_48 = *(_OWORD *)&v26[v7].m_extendedUserDatas[6];
      event_64.m_quad = (__m128)v26[v7].m_contactPoint.m_position;
      v27.m_quad = (__m128)v26[v7].m_contactPoint.m_separatingNormal;
      v28 = --this->m_toiEvents.m_size;
      event_80 = v27.m_quad;
      if ( (_DWORD)v28 != v6 )
      {
        v29 = &this->m_toiEvents.m_data[v7];
        v30 = 18i64;
        v31 = (char *)((char *)&this->m_toiEvents.m_data[v28] - (char *)v29);
        do
        {
          v32 = *(_QWORD *)((char *)&v29->m_time + (_QWORD)v31);
          v29 = (hkpToiEvent *)((char *)v29 + 8);
          v29[-1].m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] = v32;
          --v30;
        }
        while ( v30 );
      }
      v33 = *(_DWORD *)&v41[16];
      *(float *)&v41[4] = this->m_currentPsiTime;
      v34 = *(float *)&v41[4] - *(float *)&v41[16];
      this->m_currentTime = *(float *)&v41[16];
      *(_DWORD *)v41 = v33;
      *(float *)&v41[8] = v34;
      if ( v34 == 0.0 )
        v35 = 0.0;
      else
        v35 = 1.0 / v34;
      *(float *)&v41[12] = v35;
      this->m_world->m_dynamicsStepInfo.m_stepInfo = *(hkStepInfo *)v41;
      this->m_world->m_collisionInput->m_stepInfo = *(hkStepInfo *)v41;
      v36 = this->m_world;
      if ( v41[24] )
        hkpContinuousSimulation::handleSimpleToi(
          this,
          v36,
          (hkpToiEvent *)&v41[16],
          this->m_physicsDeltaTime,
          rotateNormal);
      else
        ((void (__fastcall *)(hkpContinuousSimulation *, hkpWorld *, _BYTE *))this->vfptr[10].__first_virtual_table_function__)(
          this,
          v36,
          &v41[16]);
      ++this->m_toiCounter;
      if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
      {
        v3 = 3;
        break;
      }
      v37 = v47;
      v3 = 0;
      v38 = v47->m_criticalOperationsLockCount-- == 1;
      if ( v38 && !v37->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v37->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v37);
        if ( v37->m_pendingOperationQueueCount == 1 && v37->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v37);
      }
      goto LABEL_2;
    }
    v19 = --this->m_toiEvents.m_size;
    if ( (_DWORD)v19 != v6 )
    {
      v20 = this->m_toiEvents.m_data;
      v21 = &v20[v7];
      v22 = &v20[v19];
      v23 = 18i64;
      v24 = (char *)v22 - (char *)v21;
      do
      {
        v25 = *(_QWORD *)((char *)&v21->m_time + v24);
        v21 = (hkpToiEvent *)((char *)v21 + 8);
        v21[-1].m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] = v25;
        --v23;
      }
      while ( v23 );
    }
    v6 = -1;
    v7 = -1i64;
    v3 = 0;
  }
  v39 = v47;
  v38 = v47->m_criticalOperationsLockCount-- == 1;
  if ( v38 && !v39->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v39->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v39);
    if ( v39->m_pendingOperationQueueCount == 1 && v39->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v39);
  }
  return v3;
}

// File Line: 395
// RVA: 0xD6C710
__int64 __fastcall hkpContinuousSimulation::advanceTime(hkpContinuousSimulation *this)
{
  hkpStepResult v2; // edi
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx

  v2 = hkpContinuousSimulation::advanceTimeInternal(this);
  if ( (this->m_entitiesNeedingPsiCollisionDetection.m_map.m_numElems & 0x7FFFFFFF) != 0 )
    ((void (__fastcall *)(hkpContinuousSimulation *, hkpProcessCollisionInput *, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *))this->vfptr[10].__vecDelDtor)(
      this,
      this->m_world->m_collisionInput,
      &this->m_entitiesNeedingPsiCollisionDetection);
  if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
    return 3i64;
  if ( this->m_simulateUntilTime <= this->m_currentTime )
  {
    hkpWorld::checkConstraintsViolated(this->m_world);
    if ( this->m_world->m_worldPostSimulationListeners.m_size )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v5 < Value[3] )
      {
        *v5 = "TtPostSimCb";
        v6 = __rdtsc();
        v7 = v5 + 2;
        *((_DWORD *)v7 - 2) = v6;
        Value[1] = v7;
      }
      hkpWorldCallbackUtil::firePostSimulationCallback(this->m_world);
      v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = (_QWORD *)v8[1];
      if ( (unsigned __int64)v9 < v8[3] )
      {
        *v9 = "Et";
        v10 = __rdtsc();
        v11 = v9 + 2;
        *((_DWORD *)v11 - 2) = v10;
        v8[1] = v11;
      }
    }
  }
  return (unsigned int)v2;
}

// File Line: 439
// RVA: 0xD6DE50
__int64 __fastcall hkpContinuousSimulation::advanceTimeInternal(hkpContinuousSimulation *this)
{
  _QWORD *Value; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  unsigned int v10; // ebx
  _QWORD *v11; // rax
  unsigned __int64 v12; // rcx
  _QWORD *v13; // r8
  unsigned __int64 v14; // rax
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  float TimeToAdvanceTo; // xmm0_4
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  unsigned int v24; // eax
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v3 < Value[3] )
  {
    *v3 = "TtPhysics 2012";
    v4 = __rdtsc();
    v5 = v3 + 2;
    *((_DWORD *)v5 - 2) = v4;
    Value[1] = v5;
  }
  if ( this->m_previousStepResult )
  {
    v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = (_QWORD *)v6[1];
    if ( (unsigned __int64)v7 < v6[3] )
    {
      *v7 = "TtreCollideAfterStepFailure";
      v8 = __rdtsc();
      v9 = v7 + 2;
      *((_DWORD *)v9 - 2) = v8;
      v6[1] = v9;
    }
    v10 = hkpSimulation::reCollideAfterStepFailure(this);
    if ( v10 )
    {
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = v11[1];
      v13 = v11;
      if ( v12 < v11[3] )
      {
        *(_QWORD *)v12 = "Et";
        v14 = __rdtsc();
        *(_DWORD *)(v12 + 8) = v14;
        v13[1] = v12 + 16;
      }
      goto LABEL_20;
    }
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Et";
      v17 = __rdtsc();
      v18 = v16 + 2;
      *((_DWORD *)v18 - 2) = v17;
      v15[1] = v18;
    }
  }
  TimeToAdvanceTo = hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo(this);
  if ( !this->m_toiEvents.m_size )
  {
LABEL_19:
    v10 = 0;
    this->m_currentTime = TimeToAdvanceTo;
    this->m_previousStepResult = 0;
    goto LABEL_20;
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "TtTOIs";
    v22 = __rdtsc();
    v23 = v21 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v20[1] = v23;
  }
  v24 = hkpContinuousSimulation::handleAllToisTill(this, TimeToAdvanceTo);
  v10 = v24;
  if ( !v24 )
  {
    v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v30 = (_QWORD *)v29[1];
    if ( (unsigned __int64)v30 < v29[3] )
    {
      *v30 = "Et";
      v31 = __rdtsc();
      v32 = v30 + 2;
      *((_DWORD *)v32 - 2) = v31;
      v29[1] = v32;
    }
    goto LABEL_19;
  }
  this->m_previousStepResult = v24;
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
LABEL_20:
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  v35 = v33;
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v36 = __rdtsc();
    v37 = v34 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v35[1] = v37;
  }
  return v10;
}

// File Line: 477
// RVA: 0xD6CA60
void __fastcall hkpContinuousSimulation::resetCollisionInformationForEntities(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpWorld *world,
        hkpSimulation::ResetCollisionInformation resetInfo)
{
  hkpSimulation::resetCollisionInformationForEntities(this, entities, numEntities, world, resetInfo);
  if ( (resetInfo & 1) != 0 )
  {
    if ( numEntities == 1 )
      hkpContinuousSimulation::removeToiEventsOfEntity(this, *entities);
    else
      hkpContinuousSimulation::removeToiEventsOfEntities(this, entities, numEntities);
  }
}

// File Line: 497
// RVA: 0xD6C820
void __fastcall hkpContinuousSimulation::reintegrateAndRecollideEntities(
        hkpContinuousSimulation *this,
        hkpMotion **entities,
        int numEntities,
        hkpWorld *world,
        char reintegrateRecollideMode)
{
  float m_currentTime; // xmm0_4
  hkpProcessCollisionInput *m_collisionInput; // rax
  __int64 v8; // r15
  hkStepInfo m_stepInfo; // xmm6
  float v11; // xmm1_4
  float v13; // xmm0_4
  __int64 v14; // rdi
  hkpEntity *v15; // rdx
  bool v16; // zf
  hkStepInfo info; // [rsp+30h] [rbp-38h] BYREF

  ++world->m_criticalOperationsLockCount;
  m_currentTime = this->m_currentTime;
  m_collisionInput = world->m_collisionInput;
  v8 = numEntities;
  m_stepInfo = m_collisionInput->m_stepInfo;
  info.m_endTime.m_storage = this->m_currentPsiTime;
  v11 = info.m_endTime.m_storage - m_currentTime;
  info.m_startTime.m_storage = m_currentTime;
  info.m_deltaTime.m_storage = v11;
  v13 = 0.0;
  if ( v11 != 0.0 )
    v13 = 1.0 / v11;
  info.m_invDeltaTime.m_storage = v13;
  m_collisionInput->m_stepInfo = info;
  if ( (reintegrateRecollideMode & 1) != 0 )
  {
    v14 = 0i64;
    if ( numEntities > 0 )
    {
      do
      {
        v15 = (hkpEntity *)entities[v14];
        if ( v15->m_motion.m_type.m_storage != 5 )
          hkSweptTransformUtil::backStepMotionState(this->m_currentTime, &v15->m_motion.m_motionState);
        ++v14;
      }
      while ( v14 < v8 );
    }
    hkRigidMotionUtilStep(&info, entities, v8, 336);
    hkpEntityAabbUtil::entityBatchRecalcAabb(world->m_collisionInput, (hkpEntity *const *)entities, v8);
  }
  ((void (__fastcall *)(hkpContinuousSimulation *, hkpMotion **, _QWORD, hkpWorld *, int))this->vfptr[6].__vecDelDtor)(
    this,
    entities,
    (unsigned int)v8,
    world,
    1);
  if ( (reintegrateRecollideMode & 2) != 0 )
    hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(this, (hkpEntity **)entities, v8, world, 0i64);
  if ( (reintegrateRecollideMode & 4) != 0 )
  {
    hkpContinuousSimulation::collideEntitiesNarrowPhaseContinuous(
      this,
      (hkpEntity **)entities,
      v8,
      world->m_collisionInput);
  }
  else if ( (reintegrateRecollideMode & 1) != 0 )
  {
    ((void (__fastcall *)(hkpContinuousSimulation *, hkpMotion **, _QWORD, hkpWorld *, int))this->vfptr[6].__vecDelDtor)(
      this,
      entities,
      (unsigned int)v8,
      world,
      2);
  }
  v16 = world->m_criticalOperationsLockCount-- == 1;
  if ( v16 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 && world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(world);
  }
  world->m_collisionInput->m_stepInfo = m_stepInfo;
}

// File Line: 565
// RVA: 0xD6CAD0
void __fastcall hkpContinuousSimulation::assertThereIsNoCollisionInformationForEntities(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpWorld *world)
{
  ;
}

// File Line: 604
// RVA: 0xD6CAE0
void __fastcall hkpContinuousSimulation::removeCollisionInformationForAgent(
        hkpContinuousSimulation *this,
        hkpAgentNnEntry *agent)
{
  int v4; // r11d
  __int64 v5; // rbx
  __int64 v6; // r10
  hkpToiEvent *m_data; // rcx
  __int64 v8; // rax
  __int64 v9; // r8
  hkpToiEvent *v10; // rax
  __int64 v11; // rdx
  __int64 v12; // r8
  unsigned __int64 v13; // rcx

  v4 = this->m_toiEvents.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = v4;
    do
    {
      m_data = this->m_toiEvents.m_data;
      if ( m_data[v6].m_contactMgr == agent->m_contactMgr )
      {
        v8 = --this->m_toiEvents.m_size;
        if ( (_DWORD)v8 != v4 )
        {
          v9 = 9 * v8;
          v10 = &m_data[v6];
          v11 = 18i64;
          v12 = 16 * v9 - v6 * 144;
          do
          {
            v13 = *(_QWORD *)((char *)&v10->m_time + v12);
            v10 = (hkpToiEvent *)((char *)v10 + 8);
            v10[-1].m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] = v13;
            --v11;
          }
          while ( v11 );
        }
      }
      --v4;
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
  }
}

// File Line: 618
// RVA: 0xD6CB90
void __fastcall hkpContinuousSimulation::assertThereIsNoCollisionInformationForAgent(
        hkpContinuousSimulation *this,
        hkpAgentNnEntry *agent)
{
  ;
}

// File Line: 627
// RVA: 0xD6CA10
void __fastcall hkpContinuousSimulation::warpTime(hkpContinuousSimulation *this, float warpDeltaTime)
{
  int v2; // edx
  hkpSimulation *m_simulation; // r8
  __int64 v4; // rcx

  v2 = 0;
  m_simulation = this->m_world->m_simulation;
  if ( *(int *)&m_simulation[1].m_memSizeAndFlags > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v2;
      v4 += 9i64;
      *(float *)&m_simulation[1].vfptr[v4 - 9].__vecDelDtor = warpDeltaTime
                                                            + *(float *)&m_simulation[1].vfptr[v4 - 9].__vecDelDtor;
    }
    while ( v2 < *(_DWORD *)&m_simulation[1].m_memSizeAndFlags );
  }
}

// File Line: 649
// RVA: 0xD6DAA0
void __fastcall hkpContinuousSimulation::collideInternal(hkpContinuousSimulation *this, hkStepInfo *stepInfoIn)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  int v8; // esi
  int v9; // eax
  __int64 v10; // r14
  __int64 v11; // rdi
  hkpToiEvent *m_data; // rdx
  hkpEntity *v13; // rax
  int v14; // edi
  hkpWorld *m_world; // rax
  float m_numSteps; // xmm1_4
  hkpWorld *v17; // r15
  __int64 v18; // r14
  hkpWorld *v19; // rdi
  bool v20; // zf
  hkpWorld *v21; // r14
  __int64 v22; // rdi
  hkpSimulationIsland *v23; // rbp
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  hkpWorld *v32; // rbx
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  _QWORD *v36; // rcx
  hkpWorld *v37; // rbx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // rax

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollide";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  v8 = 0;
  if ( this->m_previousStepResult )
  {
    v9 = this->m_toiEvents.m_size - 1;
    v10 = v9;
    if ( v9 >= 0 )
    {
      v11 = v9;
      do
      {
        m_data = this->m_toiEvents.m_data;
        v13 = m_data[v11].m_entities[0];
        if ( v13->m_motion.m_type.m_storage == 5 )
          v13 = m_data[v11].m_entities[1];
        ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))m_data[v11].m_contactMgr->vfptr[4].__vecDelDtor)(
          m_data[v11].m_contactMgr,
          v13->m_simulationIsland,
          &m_data[v11].m_properties);
        --v11;
        --v10;
      }
      while ( v10 >= 0 );
    }
    this->m_toiEvents.m_size = 0;
  }
  v14 = 0;
  this->m_world->m_dynamicsStepInfo.m_stepInfo = *stepInfoIn;
  this->m_world->m_collisionInput->m_stepInfo = *stepInfoIn;
  m_world = this->m_world;
  m_numSteps = (float)m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  m_world->m_dynamicsStepInfo.m_solverInfo.m_deltaTime = m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps
                                                       * stepInfoIn->m_deltaTime.m_storage;
  m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime = m_numSteps * stepInfoIn->m_invDeltaTime.m_storage;
  ++this->m_world->m_criticalOperationsLockCount;
  v17 = this->m_world;
  if ( v17->m_activeSimulationIslands.m_size <= 0 )
  {
LABEL_14:
    v19 = this->m_world;
    v20 = v19->m_criticalOperationsLockCount-- == 1;
    if ( v20 && !v19->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v19->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v19);
      if ( v19->m_pendingOperationQueueCount == 1 && v19->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v19);
    }
    ++this->m_world->m_criticalOperationsLockCount;
    v21 = this->m_world;
    if ( v21->m_activeSimulationIslands.m_size > 0 )
    {
      v22 = 0i64;
      do
      {
        v23 = v21->m_activeSimulationIslands.m_data[v22];
        hkpContinuousSimulation::collideIslandNarrowPhaseContinuous(this, v23, this->m_world->m_collisionInput);
        if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
          break;
        if ( this->m_world->m_islandPostCollideListeners.m_size )
        {
          v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v25 = (_QWORD *)v24[1];
          if ( (unsigned __int64)v25 < v24[3] )
          {
            *v25 = "TtIslandPostCollideCb";
            v26 = __rdtsc();
            v27 = v25 + 2;
            *((_DWORD *)v27 - 2) = v26;
            v24[1] = v27;
          }
          hkpWorldCallbackUtil::fireIslandPostCollideCallback(this->m_world, v23, stepInfoIn);
          v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v29 = (_QWORD *)v28[1];
          if ( (unsigned __int64)v29 < v28[3] )
          {
            *v29 = "Et";
            v30 = __rdtsc();
            v31 = v29 + 2;
            *((_DWORD *)v31 - 2) = v30;
            v28[1] = v31;
          }
        }
        ++v8;
        ++v22;
      }
      while ( v8 < v21->m_activeSimulationIslands.m_size );
    }
    v32 = this->m_world;
    v20 = v32->m_criticalOperationsLockCount-- == 1;
    if ( v20 && !v32->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v32->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v32);
      if ( v32->m_pendingOperationQueueCount == 1 && v32->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v32);
    }
    v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v34 = (_QWORD *)v33[1];
    if ( (unsigned __int64)v34 < v33[3] )
    {
      v35 = __rdtsc();
      *v34 = "Et";
      v36 = v34 + 2;
      *((_DWORD *)v36 - 2) = v35;
      v33[1] = v36;
    }
  }
  else
  {
    v18 = 0i64;
    while ( 1 )
    {
      hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(
        this,
        v17->m_activeSimulationIslands.m_data[v18]->m_entities.m_data,
        v17->m_activeSimulationIslands.m_data[v18]->m_entities.m_size,
        this->m_world,
        0i64);
      if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
        break;
      ++v14;
      ++v18;
      if ( v14 >= v17->m_activeSimulationIslands.m_size )
        goto LABEL_14;
    }
    v37 = this->m_world;
    v20 = v37->m_criticalOperationsLockCount-- == 1;
    if ( v20 && !v37->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v37->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v37);
      if ( v37->m_pendingOperationQueueCount == 1 && v37->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v37);
    }
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = v38[1];
    if ( v39 < v38[3] )
    {
      *(_QWORD *)v39 = "Et";
      v40 = __rdtsc();
      *(_DWORD *)(v39 + 8) = v40;
      v38[1] = v39 + 16;
    }
  }
}

// File Line: 735
// RVA: 0xD6D330
void __fastcall hkpContinuousSimulation::collideEntitiesBroadPhaseContinuousFindPairs(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        unsigned int numEntities,
        hkpWorld *world,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairs)
{
  unsigned int v7; // ebx
  _QWORD *Value; // r8
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  hkLifoAllocator *v12; // rax
  char *m_cur; // r14
  int v14; // esi
  char *v15; // rcx
  hkLifoAllocator *v16; // rax
  char *v17; // rbp
  int v18; // r15d
  char *v19; // rcx
  int v20; // eax
  char *v21; // rcx
  char *v22; // r12
  _QWORD *v23; // rbx
  __int64 v24; // rdi
  __m128i v25; // xmm4
  unsigned int v26; // eax
  __m128i v27; // xmm3
  __m128i v28; // xmm0
  bool v29; // sf
  __m128i v30; // xmm3
  _QWORD *v31; // r8
  _QWORD *v32; // rcx
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx
  hkpBroadPhase *m_broadPhase; // rcx
  hkpBroadPhase *v36; // rcx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  hkLifoAllocator *v39; // rax
  int v40; // r8d
  _QWORD *v41; // r9
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // r8
  _QWORD *v45; // rax
  _QWORD *v46; // rcx
  _QWORD *v47; // r8
  unsigned __int64 v48; // rax
  _QWORD *v49; // rcx
  unsigned int v50; // [rsp+30h] [rbp-58h]
  char *v51; // [rsp+38h] [rbp-50h]
  hkpEntity *entityBatch; // [rsp+40h] [rbp-48h] BYREF

  if ( numEntities )
  {
    v7 = numEntities;
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = Value[1];
    if ( v10 < Value[3] )
    {
      *(_QWORD *)v10 = "LtBroadPhase";
      *(_QWORD *)(v10 + 16) = "StGatherAabbs";
      v11 = __rdtsc();
      *(_DWORD *)(v10 + 8) = v11;
      Value[1] = v10 + 24;
    }
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)v12->m_cur;
    v14 = (32 * v7 + 127) & 0xFFFFFF80;
    v15 = &m_cur[v14];
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (char *)v16->m_cur;
    v18 = (8 * v7 + 127) & 0xFFFFFF80;
    v19 = &v17[v18];
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
      v17 = (char *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
    else
      v16->m_cur = v19;
    v20 = v7 - 1;
    v50 = v7 - 1;
    if ( (int)(v7 - 1) >= 0 )
    {
      v21 = m_cur + 8;
      v22 = (char *)((char *)entities - v17);
      v23 = v17;
      v51 = m_cur + 8;
      do
      {
        v24 = *(_QWORD *)((char *)v23 + (_QWORD)v22);
        entityBatch = (hkpEntity *)v24;
        if ( v20 >= 4 )
          _mm_prefetch((const char *)(*(_QWORD *)((char *)v23 + (_QWORD)v22 + 32) + 32i64), 0);
        *v23 = v24 + 68;
        if ( *(_DWORD *)(v24 + 80) > *(_DWORD *)(v24 + 96) )
        {
          hkpEntityAabbUtil::entityBatchRecalcAabb(world->m_collisionInput, &entityBatch, 1);
          v21 = v51;
        }
        v21 += 32;
        ++v23;
        v51 = v21;
        v25 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*(unsigned int *)(v24 + 92), (__m128i)0i64), (__m128i)0i64);
        v26 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v25, 255));
        v27 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v24 + 80)), _mm_cvtsi32_si128(*(_DWORD *)(v24 + 88))),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v24 + 84)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v25, v26));
        *((_QWORD *)v21 - 5) = v27.m128i_i64[0];
        *((_DWORD *)v21 - 8) = _mm_shuffle_epi32(v27, 170).m128i_u32[0];
        v28 = _mm_cvtsi32_si128(v26);
        v29 = (int)(v50 - 1) < 0;
        v20 = --v50;
        v30 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128(*(_DWORD *)(v24 + 96)),
                    _mm_cvtsi32_si128(*(_DWORD *)(v24 + 104))),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v24 + 100)), _mm_cvtsi32_si128(0))),
                _mm_sll_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(unsigned int *)(v24 + 108), (__m128i)0i64),
                    (__m128i)0i64),
                  v28));
        *((_QWORD *)v21 - 3) = v30.m128i_i64[0];
        *((_DWORD *)v21 - 4) = _mm_shuffle_epi32(v30, 170).m128i_u32[0];
      }
      while ( !v29 );
      v7 = numEntities;
    }
    v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v32 = (_QWORD *)v31[1];
    if ( (unsigned __int64)v32 < v31[3] )
    {
      *v32 = "St3AxisSweep";
      v33 = __rdtsc();
      v34 = v32 + 2;
      *((_DWORD *)v34 - 2) = v33;
      v31[1] = v34;
    }
    m_broadPhase = world->m_broadPhase;
    if ( m_broadPhase->m_criticalSection )
      hkpBroadPhase::lockImplementation(m_broadPhase);
    ((void (__fastcall *)(hkpBroadPhase *, char *, char *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))world->m_broadPhase->vfptr[6].__vecDelDtor)(
      world->m_broadPhase,
      v17,
      m_cur,
      v7,
      newPairs,
      delPairs);
    v36 = world->m_broadPhase;
    if ( v36->m_criticalSection )
      hkpBroadPhase::unlockImplementation(v36);
    v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v38 = (v18 + 15) & 0xFFFFFFF0;
    if ( v18 > v37->m_slabSize || &v17[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v17 )
      hkLifoAllocator::slowBlockFree(v37, v17, v38);
    else
      v37->m_cur = v17;
    v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v40 = (v14 + 15) & 0xFFFFFFF0;
    if ( v14 > v39->m_slabSize || &m_cur[v40] != v39->m_cur || v39->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v39, m_cur, v40);
    else
      v39->m_cur = m_cur;
    if ( delPairs->m_size + newPairs->m_size > 0 )
    {
      v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)v41[1];
      if ( (unsigned __int64)v42 < v41[3] )
      {
        *v42 = "StRemoveDup";
        v43 = __rdtsc();
        v44 = v42 + 2;
        *((_DWORD *)v44 - 2) = v43;
        v41[1] = v44;
      }
      hkpTypedBroadPhaseDispatcher::removeDuplicates(newPairs, delPairs);
    }
    v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v46 = (_QWORD *)v45[1];
    v47 = v45;
    if ( (unsigned __int64)v46 < v45[3] )
    {
      *v46 = "lt";
      v48 = __rdtsc();
      v49 = v46 + 2;
      *((_DWORD *)v49 - 2) = v48;
      v47[1] = v49;
    }
  }
}

// File Line: 841
// RVA: 0xD6CBA0
void __fastcall hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        unsigned int numEntities,
        hkpWorld *world,
        char *exportFinished)
{
  _BYTE *v5; // rbx
  unsigned int v7; // esi
  _QWORD *Value; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // r9
  unsigned __int64 v12; // rax
  int m_broadPhaseUpdateSize; // ebx
  hkLifoAllocator *v14; // rcx
  hkpBroadPhaseHandlePair *m_cur; // rax
  int v16; // edx
  char *v17; // r8
  int v18; // ebx
  hkLifoAllocator *v19; // rcx
  hkpBroadPhaseHandlePair *v20; // rax
  int v21; // edx
  char *v22; // r8
  hkLifoAllocator *v23; // rax
  char *v24; // r13
  int v25; // r14d
  char *v26; // rcx
  hkLifoAllocator *v27; // rax
  char *v28; // r15
  int v29; // ebx
  char *v30; // rcx
  int v31; // eax
  char *v32; // rcx
  char *v33; // r12
  _QWORD *v34; // rsi
  __int64 v35; // rbx
  __m128i v36; // xmm4
  unsigned int v37; // eax
  __m128i v38; // xmm3
  __m128i v39; // xmm0
  bool v40; // sf
  __m128i v41; // xmm3
  _QWORD *v42; // r8
  _QWORD *v43; // rcx
  unsigned __int64 v44; // rax
  _QWORD *v45; // rcx
  hkpBroadPhase *m_broadPhase; // rcx
  hkpBroadPhase *v47; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  hkpBroadPhase *v49; // rcx
  hkLifoAllocator *v50; // rax
  int v51; // r8d
  hkLifoAllocator *v52; // rax
  int v53; // r8d
  _QWORD *v54; // r8
  _QWORD *v55; // rcx
  unsigned __int64 v56; // rax
  _QWORD *v57; // rcx
  _QWORD *v58; // r8
  _QWORD *v59; // rcx
  unsigned __int64 v60; // rax
  _QWORD *v61; // rcx
  _QWORD *v62; // r8
  _QWORD *v63; // rcx
  unsigned __int64 v64; // rax
  _QWORD *v65; // rcx
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  int m_size; // ebx
  hkMemorySystem *Instance; // rax
  _QWORD *v72; // r8
  _QWORD *v73; // rcx
  unsigned __int64 v74; // rax
  _QWORD *v75; // rcx
  int v76; // eax
  char *v77; // rdi
  signed int v78; // ebx
  hkLifoAllocator *v79; // rax
  int v80; // r8d
  _QWORD *v81; // r8
  _QWORD *v82; // rcx
  unsigned __int64 v83; // rax
  _QWORD *v84; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidableCollidableFilter *v86; // r9
  int v87; // eax
  char *v88; // rdi
  signed int v89; // ebx
  hkLifoAllocator *v90; // rax
  int v91; // r8d
  unsigned int v92; // [rsp+10h] [rbp-51h]
  int v93; // [rsp+14h] [rbp-4Dh]
  char *v94; // [rsp+18h] [rbp-49h]
  hkpEntity *entityBatch; // [rsp+20h] [rbp-41h] BYREF
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+28h] [rbp-39h] BYREF
  void *p; // [rsp+38h] [rbp-29h]
  int v98; // [rsp+40h] [rbp-21h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+48h] [rbp-19h] BYREF
  void *v100; // [rsp+58h] [rbp-9h]
  int v101; // [rsp+60h] [rbp-1h]
  hkpEntity **v102; // [rsp+C8h] [rbp+67h]
  unsigned int vars0; // [rsp+D0h] [rbp+6Fh]
  _BYTE *v104; // [rsp+E0h] [rbp+7Fh]

  if ( numEntities )
  {
    v104 = v5;
    v7 = numEntities;
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = Value[1];
    v11 = Value;
    if ( v10 < Value[3] )
    {
      *(_QWORD *)v10 = "LtBroadPhase";
      *(_QWORD *)(v10 + 16) = "StGatherAabbs";
      v12 = __rdtsc();
      *(_DWORD *)(v10 + 8) = v12;
      v11[1] = v10 + 24;
    }
    m_broadPhaseUpdateSize = world->m_broadPhaseUpdateSize;
    newPairs.m_capacityAndFlags = 0x80000000;
    newPairs.m_data = 0i64;
    newPairs.m_size = 0;
    v101 = m_broadPhaseUpdateSize;
    if ( m_broadPhaseUpdateSize )
    {
      v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkpBroadPhaseHandlePair *)v14->m_cur;
      v16 = (16 * m_broadPhaseUpdateSize + 127) & 0xFFFFFF80;
      v17 = (char *)m_cur + v16;
      if ( v16 > v14->m_slabSize || v17 > v14->m_end )
        m_cur = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
      else
        v14->m_cur = v17;
    }
    else
    {
      m_cur = 0i64;
    }
    newPairs.m_data = m_cur;
    v100 = m_cur;
    newPairs.m_capacityAndFlags = m_broadPhaseUpdateSize | 0x80000000;
    v18 = world->m_broadPhaseUpdateSize;
    delPairs.m_data = 0i64;
    delPairs.m_size = 0;
    delPairs.m_capacityAndFlags = 0x80000000;
    v98 = v18;
    if ( v18 )
    {
      v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkpBroadPhaseHandlePair *)v19->m_cur;
      v21 = (16 * v18 + 127) & 0xFFFFFF80;
      v22 = (char *)v20 + v21;
      if ( v21 > v19->m_slabSize || v22 > v19->m_end )
        v20 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
      else
        v19->m_cur = v22;
    }
    else
    {
      v20 = 0i64;
    }
    delPairs.m_data = v20;
    delPairs.m_capacityAndFlags = v18 | 0x80000000;
    p = v20;
    v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (char *)v23->m_cur;
    v25 = (32 * v7 + 127) & 0xFFFFFF80;
    v26 = &v24[v25];
    if ( v25 > v23->m_slabSize || v26 > v23->m_end )
      v24 = (char *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
    else
      v23->m_cur = v26;
    v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v28 = (char *)v27->m_cur;
    v29 = (8 * v7 + 127) & 0xFFFFFF80;
    v93 = v29;
    v30 = &v28[v29];
    if ( v29 > v27->m_slabSize || v30 > v27->m_end )
      v28 = (char *)hkLifoAllocator::allocateFromNewSlab(v27, v29);
    else
      v27->m_cur = v30;
    v31 = v7 - 1;
    v92 = v7 - 1;
    if ( (int)(v7 - 1) >= 0 )
    {
      v32 = v24 + 8;
      v33 = (char *)((char *)entities - v28);
      v34 = v28;
      do
      {
        v35 = *(_QWORD *)((char *)v34 + (_QWORD)v33);
        entityBatch = (hkpEntity *)v35;
        if ( v31 >= 4 )
          _mm_prefetch((const char *)(*(_QWORD *)((char *)v34 + (_QWORD)v33 + 32) + 32i64), 0);
        *v34 = v35 + 68;
        if ( *(_DWORD *)(v35 + 80) > *(_DWORD *)(v35 + 96) )
        {
          hkpEntityAabbUtil::entityBatchRecalcAabb(world->m_collisionInput, &entityBatch, 1);
          v32 = v94;
        }
        v32 += 32;
        ++v34;
        v36 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*(unsigned int *)(v35 + 92), (__m128i)0i64), (__m128i)0i64);
        v37 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v36, 255));
        v38 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v35 + 80)), _mm_cvtsi32_si128(*(_DWORD *)(v35 + 88))),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v35 + 84)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v36, v37));
        *((_QWORD *)v32 - 5) = v38.m128i_i64[0];
        *((_DWORD *)v32 - 8) = _mm_shuffle_epi32(v38, 170).m128i_u32[0];
        v39 = _mm_cvtsi32_si128(v37);
        v40 = (int)(v92 - 1) < 0;
        v31 = --v92;
        v41 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128(*(_DWORD *)(v35 + 96)),
                    _mm_cvtsi32_si128(*(_DWORD *)(v35 + 104))),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)(v35 + 100)), _mm_cvtsi32_si128(0))),
                _mm_sll_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(unsigned int *)(v35 + 108), (__m128i)0i64),
                    (__m128i)0i64),
                  v39));
        *((_QWORD *)v32 - 3) = v41.m128i_i64[0];
        *((_DWORD *)v32 - 4) = _mm_shuffle_epi32(v41, 170).m128i_u32[0];
      }
      while ( !v40 );
      v29 = v93;
      v7 = vars0;
      entities = v102;
    }
    v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v43 = (_QWORD *)v42[1];
    if ( (unsigned __int64)v43 < v42[3] )
    {
      *v43 = "St3AxisSweep";
      v44 = __rdtsc();
      v45 = v43 + 2;
      *((_DWORD *)v45 - 2) = v44;
      v42[1] = v45;
    }
    m_broadPhase = world->m_broadPhase;
    if ( m_broadPhase->m_criticalSection )
      hkpBroadPhase::lockImplementation(m_broadPhase);
    v47 = world->m_broadPhase;
    vfptr = v47->vfptr;
    delPairs.m_data = (hkpBroadPhaseHandlePair *)&delPairs;
    ((void (__fastcall *)(hkpBroadPhase *, char *, char *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))vfptr[6].__vecDelDtor)(
      v47,
      v28,
      v24,
      v7,
      &newPairs);
    v49 = world->m_broadPhase;
    if ( v49->m_criticalSection )
      hkpBroadPhase::unlockImplementation(v49);
    v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v51 = (v29 + 15) & 0xFFFFFFF0;
    if ( v29 > v50->m_slabSize || &v28[v51] != v50->m_cur || v50->m_firstNonLifoEnd == v28 )
      hkLifoAllocator::slowBlockFree(v50, v28, v51);
    else
      v50->m_cur = v28;
    v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v53 = (v25 + 15) & 0xFFFFFFF0;
    if ( v25 > v52->m_slabSize || &v24[v53] != v52->m_cur || v52->m_firstNonLifoEnd == v24 )
      hkLifoAllocator::slowBlockFree(v52, v24, v53);
    else
      v52->m_cur = v24;
    if ( delPairs.m_size + newPairs.m_size > 0 )
    {
      v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v55 = (_QWORD *)v54[1];
      if ( (unsigned __int64)v55 < v54[3] )
      {
        *v55 = "StRemoveDup";
        v56 = __rdtsc();
        v57 = v55 + 2;
        *((_DWORD *)v57 - 2) = v56;
        v54[1] = v57;
      }
      hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &delPairs);
    }
    if ( v104 )
    {
      v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v59 = (_QWORD *)v58[1];
      if ( (unsigned __int64)v59 < v58[3] )
      {
        *v59 = "TtWaitForExport";
        v60 = __rdtsc();
        v61 = v59 + 2;
        *((_DWORD *)v61 - 2) = v60;
        v58[1] = v61;
      }
      while ( *v104 != 1 && *v104 != 2 )
        ;
      v62 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v63 = (_QWORD *)v62[1];
      if ( (unsigned __int64)v63 < v62[3] )
      {
        *v63 = "Et";
        v64 = __rdtsc();
        v65 = v63 + 2;
        *((_DWORD *)v65 - 2) = v64;
        v62[1] = v65;
      }
    }
    if ( delPairs.m_size + newPairs.m_size > 0 )
    {
      v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v67 = (_QWORD *)v66[1];
      if ( (unsigned __int64)v67 < v66[3] )
      {
        *v67 = "StRemoveAgt";
        v68 = __rdtsc();
        v69 = v67 + 2;
        *((_DWORD *)v69 - 2) = v68;
        v66[1] = v69;
      }
      hkpWorld::lockIslandForConstraintUpdate(world, (*entities)->m_simulationIsland);
      hkpTypedBroadPhaseDispatcher::removePairs(
        world->m_broadPhaseDispatcher,
        (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
        delPairs.m_size);
      m_size = newPairs.m_size;
      Instance = hkMemorySystem::getInstance();
      if ( Instance->vfptr->heapCanAllocTotal(Instance, m_size << 10) )
      {
        v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v82 = (_QWORD *)v81[1];
        if ( (unsigned __int64)v82 < v81[3] )
        {
          *v82 = "StAddAgt";
          v83 = __rdtsc();
          v84 = v82 + 2;
          *((_DWORD *)v84 - 2) = v83;
          v81[1] = v84;
        }
        m_collisionFilter = world->m_collisionFilter;
        v86 = &m_collisionFilter->hkpCollidableCollidableFilter;
        if ( !m_collisionFilter )
          v86 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          world->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v86);
        hkpWorld::unlockIslandForConstraintUpdate(world, (*entities)->m_simulationIsland);
      }
      else
      {
        hkpWorld::unlockIslandForConstraintUpdate(world, (*entities)->m_simulationIsland);
      }
    }
    v72 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v73 = (_QWORD *)v72[1];
    if ( (unsigned __int64)v73 < v72[3] )
    {
      *v73 = "lt";
      v74 = __rdtsc();
      v75 = v73 + 2;
      *((_DWORD *)v75 - 2) = v74;
      v72[1] = v75;
    }
    v76 = delPairs.m_size;
    v77 = (char *)p;
    if ( p == delPairs.m_data )
      v76 = 0;
    delPairs.m_size = v76;
    v78 = (16 * v98 + 127) & 0xFFFFFF80;
    v79 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v80 = (v78 + 15) & 0xFFFFFFF0;
    if ( v78 > v79->m_slabSize || &v77[v80] != v79->m_cur || v79->m_firstNonLifoEnd == v77 )
      hkLifoAllocator::slowBlockFree(v79, v77, v80);
    else
      v79->m_cur = v77;
    delPairs.m_size = 0;
    if ( delPairs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        delPairs.m_data,
        16 * delPairs.m_capacityAndFlags);
    v87 = newPairs.m_size;
    v88 = (char *)v100;
    delPairs.m_data = 0i64;
    if ( v100 == newPairs.m_data )
      v87 = 0;
    delPairs.m_capacityAndFlags = 0x80000000;
    newPairs.m_size = v87;
    v89 = (16 * v101 + 127) & 0xFFFFFF80;
    v90 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v91 = (v89 + 15) & 0xFFFFFFF0;
    if ( v89 > v90->m_slabSize || &v88[v91] != v90->m_cur || v90->m_firstNonLifoEnd == v88 )
      hkLifoAllocator::slowBlockFree(v90, v88, v91);
    else
      v90->m_cur = v88;
    newPairs.m_size = 0;
    if ( newPairs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        newPairs.m_data,
        16 * newPairs.m_capacityAndFlags);
  }
}

// File Line: 956
// RVA: 0xD6D720
void __fastcall hkpContinuousSimulation::collideIslandNarrowPhaseContinuous(
        hkpContinuousSimulation *this,
        hkpSimulationIsland *isle,
        hkpProcessCollisionInput *input)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  __int64 v11; // rax
  unsigned __int16 *v12; // r13
  int v13; // r15d
  int v14; // ecx
  __int64 v15; // rdx
  unsigned __int64 v16; // rbx
  unsigned __int64 v17; // rdi
  __int64 v18; // rbp
  __int64 v19; // r14
  hkpCollisionQualityInfo *v20; // rcx
  unsigned int m_storage; // eax
  _QWORD *v22; // r8
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  __int64 v25[2]; // [rsp+30h] [rbp-30F8h]
  hkpProcessCollisionOutput output; // [rsp+40h] [rbp-30E8h] BYREF
  __int64 v27; // [rsp+3138h] [rbp+10h]
  __int64 v28; // [rsp+3148h] [rbp+20h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtNarrowPhase";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  output.m_toi.m_time.m_storage = 3.40282e38;
  v25[0] = (__int64)&isle->m_narrowphaseAgentTrack;
  output.m_toi.m_properties.hkpSolverResults = 0i64;
  v25[1] = (__int64)&isle->m_midphaseAgentTrack;
  v11 = 0i64;
  output.m_constraintOwner.m_storage = isle;
  v27 = 0i64;
  while ( 1 )
  {
    v12 = (unsigned __int16 *)v25[v11];
    v13 = 0;
    v14 = *((_DWORD *)v12 + 4);
    if ( v14 > 0 )
      break;
LABEL_19:
    v27 = ++v11;
    if ( v11 >= 2 )
      goto LABEL_20;
  }
  v15 = 0i64;
  while ( 1 )
  {
    v15 += 8i64;
    ++v13;
    v16 = *(_QWORD *)(v15 + *((_QWORD *)v12 + 1) - 8);
    v28 = v15;
    v17 = v13 == v14 ? v16 + *v12 : v16 + 960;
    if ( v16 < v17 )
      break;
LABEL_17:
    v14 = *((_DWORD *)v12 + 4);
    if ( v13 >= v14 )
    {
      v11 = v27;
      goto LABEL_19;
    }
  }
  while ( 1 )
  {
    v18 = *(_QWORD *)(v16 + 24);
    v19 = *(_QWORD *)(v16 + 32);
    _mm_prefetch(*(const char **)(v16 + 8), 0);
    _mm_prefetch((const char *)(v16 + 128), 0);
    v20 = &input->m_dispatcher.m_storage->m_collisionQualityInfo[*(char *)(v16 + 16)];
    input->m_collisionQualityInfo.m_storage = v20;
    m_storage = v20->m_useContinuousPhysics.m_storage;
    output.m_toi.m_time.m_storage = 3.40282e38;
    output.m_potentialContacts.m_storage = 0i64;
    input->m_createPredictiveAgents.m_storage = m_storage;
    output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
    hkAgentNnMachine_ProcessAgent((hkpAgentNnEntry *)v16, input, &output, *(hkpContactMgr **)(v16 + 8));
    if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
      break;
    if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
      (*(void (__fastcall **)(_QWORD, __int64, __int64, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))(**(_QWORD **)(v16 + 8) + 48i64))(
        *(_QWORD *)(v16 + 8),
        v18,
        v19,
        input,
        &output);
    if ( output.m_toi.m_time.m_storage != 3.40282e38 )
      hkpContinuousSimulation::addToiEvent(this, &output, (hkpAgentNnEntry *)v16);
    v16 += *(unsigned __int8 *)(v16 + 3);
    if ( v16 >= v17 )
    {
      v15 = v28;
      goto LABEL_17;
    }
  }
LABEL_20:
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = v22[1];
  if ( v23 < v22[3] )
  {
    *(_QWORD *)v23 = "Et";
    v24 = __rdtsc();
    *(_DWORD *)(v23 + 8) = v24;
    v22[1] = v23 + 16;
  }
}

// File Line: 1027
// RVA: 0xD6D990
void __fastcall hkpContinuousSimulation::collideEntitiesNarrowPhaseContinuous(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpProcessCollisionInput *input)
{
  hkpSimulation::processAgentsOfEntities(
    this,
    entities,
    numEntities,
    input,
    (void (__fastcall *)(hkpSimulation *, hkpAgentNnEntry *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))hkpContinuousSimulation::processAgentCollideContinuous,
    FIND_CONTACTS_DEFAULT);
}

// File Line: 1063
// RVA: 0xD6D9C0
void __fastcall hkpContinuousSimulation::processAgentCollideContinuous(
        hkpContinuousSimulation *this,
        hkpAgentNnEntry *entry,
        hkpProcessCollisionInput *processInput,
        hkpProcessCollisionOutput *processOutput)
{
  hkpProcessCdPoint *m_contactPoints; // rbp
  hkpCollisionQualityInfo *v9; // r9

  processOutput->m_toi.m_time.m_storage = 3.40282e38;
  processOutput->m_potentialContacts.m_storage = 0i64;
  m_contactPoints = processOutput->m_contactPoints;
  processOutput->m_firstFreeContactPoint.m_storage = processOutput->m_contactPoints;
  v9 = &processInput->m_dispatcher.m_storage->m_collisionQualityInfo[entry->m_collisionQualityIndex];
  processInput->m_collisionQualityInfo.m_storage = v9;
  processInput->m_createPredictiveAgents.m_storage = v9->m_useContinuousPhysics.m_storage;
  hkAgentNnMachine_ProcessAgent(entry, processInput, processOutput, entry->m_contactMgr);
  if ( hkOutOfMemoryState != MEMORY_STATE_OUT_OF_MEMORY )
  {
    if ( processOutput->m_firstFreeContactPoint.m_storage != m_contactPoints )
      ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))entry->m_contactMgr->vfptr[3].__vecDelDtor)(
        entry->m_contactMgr,
        entry->m_collidable[0],
        entry->m_collidable[1],
        processInput,
        processOutput);
    if ( 3.40282e38 != processOutput->m_toi.m_time.m_storage )
      hkpContinuousSimulation::addToiEvent(this, processOutput, entry);
  }
}

// File Line: 1104
// RVA: 0xD6E080
void __fastcall hkpContinuousSimulation::addToiEvent(
        hkpContinuousSimulation *this,
        hkpProcessCollisionOutput *processOutput,
        hkpAgentNnEntry *entry)
{
  __int64 m_size; // rcx
  hkpToiEvent *v6; // r8
  hkErrStream v7; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  if ( this->m_toiEvents.m_size == (this->m_toiEvents.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkErrStream::hkErrStream(&v7, buf, 512);
    hkOstream::operator<<(
      &v7,
      "TOI event queue full, consider using HK_COLLIDABLE_QUALITY_DEBRIS for some objects or increase hkpWorldCinfo::m_si"
      "zeOfToiEventQueue");
    hkError::messageWarning(0xF0323454, buf, "World\\Simulation\\Continuous\\hkpContinuousSimulation.cpp", 1107);
    hkOstream::~hkOstream(&v7);
  }
  else
  {
    m_size = this->m_toiEvents.m_size;
    this->m_toiEvents.m_size = m_size + 1;
    v6 = &this->m_toiEvents.m_data[m_size];
    v6->m_time = processOutput->m_toi.m_time.m_storage;
    v6->m_useSimpleHandling.m_bool = this->m_world->m_collisionDispatcher->m_collisionQualityInfo[(__int64)entry->m_collisionQualityIndex].m_useSimpleToiHandling.m_bool;
    v6->m_seperatingVelocity = processOutput->m_toi.m_seperatingVelocity.m_storage;
    v6->m_contactPoint.m_position = processOutput->m_toi.m_contactPoint.m_position;
    v6->m_contactPoint.m_separatingNormal = processOutput->m_toi.m_contactPoint.m_separatingNormal;
    v6->m_entities[0] = (hkpEntity *)((char *)entry->m_collidable[0] + entry->m_collidable[0]->m_ownerOffset);
    v6->m_entities[1] = (hkpEntity *)((char *)entry->m_collidable[1] + entry->m_collidable[1]->m_ownerOffset);
    v6->m_properties.hkpSolverResults = processOutput->m_toi.m_properties.hkpSolverResults;
    v6->m_properties.hkContactPointMaterial = processOutput->m_toi.m_properties.hkContactPointMaterial;
    *(_QWORD *)&v6->m_properties.m_internalDataA = *(_QWORD *)&processOutput->m_toi.m_properties.m_internalDataA;
    v6->m_contactMgr = (hkpDynamicsContactMgr *)entry->m_contactMgr;
    v6->m_extendedUserDatas[0] = processOutput->m_toi.m_properties.m_extendedUserDatas[0];
    v6->m_extendedUserDatas[1] = processOutput->m_toi.m_properties.m_extendedUserDatas[1];
    v6->m_extendedUserDatas[2] = processOutput->m_toi.m_properties.m_extendedUserDatas[2];
    v6->m_extendedUserDatas[3] = processOutput->m_toi.m_properties.m_extendedUserDatas[3];
    v6->m_extendedUserDatas[4] = processOutput->m_toi.m_properties.m_extendedUserDatas[4];
    v6->m_extendedUserDatas[5] = processOutput->m_toi.m_properties.m_extendedUserDatas[5];
    v6->m_extendedUserDatas[6] = processOutput->m_toi.m_properties.m_extendedUserDatas[6];
  }
}

// File Line: 1132
// RVA: 0xD6E210
void __fastcall hkpContinuousSimulation::removeToiEventsOfEntities(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        int numEntities)
{
  __int64 v3; // rsi
  int v6; // edi
  __int64 i; // rbx
  __int64 v8; // rsi
  hkpToiEvent *v9; // rbp
  int Key; // ebx
  int v11; // eax
  hkpEntity *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // r8
  hkpToiEvent *v16; // rax
  __int64 v17; // r8
  unsigned __int64 v18; // rcx
  AMD_HD3D v19; // [rsp+20h] [rbp-28h] BYREF

  v3 = numEntities;
  if ( this->m_toiEvents.m_size )
  {
    v6 = 0;
    v19.mHeight = -1;
    *(_QWORD *)&v19.mEnableStereo = 0i64;
    v19.mWidth = 0;
    if ( numEntities )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v19,
        &hkContainerHeapAllocator::s_alloc,
        numEntities);
    for ( i = 0i64; i < v3; ++i )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v19,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)entities[i],
        0i64);
    if ( this->m_toiEvents.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = &this->m_toiEvents.m_data[v8];
        Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v19,
                              (unsigned __int64)v9->m_entities[0]);
        v11 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v19,
                              (unsigned __int64)v9->m_entities[1]);
        if ( Key <= (int)v19.mHeight || v11 <= (int)v19.mHeight )
        {
          v12 = v9->m_entities[0];
          if ( v12->m_motion.m_type.m_storage == 5 )
            v12 = v9->m_entities[1];
          ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v9->m_contactMgr->vfptr[4].__vecDelDtor)(
            v9->m_contactMgr,
            v12->m_simulationIsland,
            &v9->m_properties);
          v13 = --this->m_toiEvents.m_size;
          if ( (_DWORD)v13 != v6 )
          {
            v14 = 18i64;
            v15 = 144 * v13;
            v16 = &this->m_toiEvents.m_data[v8];
            v17 = v15 - v8 * 144;
            do
            {
              v18 = *(_QWORD *)((char *)&v16->m_time + v17);
              v16 = (hkpToiEvent *)((char *)v16 + 8);
              v16[-1].m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] = v18;
              --v14;
            }
            while ( v14 );
          }
          --v6;
          --v8;
        }
        ++v6;
        ++v8;
      }
      while ( v6 < this->m_toiEvents.m_size );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v19,
      &hkContainerHeapAllocator::s_alloc);
    _(&v19);
  }
}

// File Line: 1176
// RVA: 0xD6E3A0
void __fastcall hkpContinuousSimulation::removeToiEventsOfEntity(hkpContinuousSimulation *this, hkpEntity *entity)
{
  int v2; // ebx
  __int64 v5; // rdi
  hkpToiEvent *v6; // r8
  hkpEntity *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdx
  __int64 v10; // r8
  hkpToiEvent *v11; // rax
  __int64 v12; // r8
  unsigned __int64 v13; // rcx

  v2 = 0;
  if ( this->m_toiEvents.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = &this->m_toiEvents.m_data[v5];
      if ( v6->m_entities[0] == entity || v6->m_entities[1] == entity )
      {
        v7 = v6->m_entities[0];
        if ( v7->m_motion.m_type.m_storage == 5 )
          v7 = v6->m_entities[1];
        ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v6->m_contactMgr->vfptr[4].__vecDelDtor)(
          v6->m_contactMgr,
          v7->m_simulationIsland,
          &v6->m_properties);
        v8 = --this->m_toiEvents.m_size;
        if ( (_DWORD)v8 != v2 )
        {
          v9 = 18i64;
          v10 = 144 * v8;
          v11 = &this->m_toiEvents.m_data[v5];
          v12 = v10 - v5 * 144;
          do
          {
            v13 = *(_QWORD *)((char *)&v11->m_time + v12);
            v11 = (hkpToiEvent *)((char *)v11 + 8);
            v11[-1].m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] = v13;
            --v9;
          }
          while ( v9 );
        }
        --v2;
        --v5;
      }
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_toiEvents.m_size );
  }
}

// File Line: 1200
// RVA: 0xD6E820
void __fastcall hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(
        hkpContinuousSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpProcessCollisionInput *input,
        hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection)
{
  hkpSimulationIsland *m_simulationIsland; // rdi
  __int64 v7; // rbx
  unsigned int m_size; // r14d
  hkLifoAllocator *Value; // rax
  char *m_cur; // r15
  int v12; // edx
  char *v13; // rcx
  signed int v14; // esi
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  __int64 v19; // rdi
  hkpEntity *v20; // rsi
  int v21; // r14d
  __int64 v22; // rdi
  hkpSimulationIsland **v23; // rcx
  hkpAgentNnEntry *m_agentEntry; // rbx
  hkpCollisionDispatcher *m_collisionDispatcher; // rdx
  __int64 v26; // rcx
  hkpCollisionQualityInfo *v27; // rcx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  signed int v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // r8d
  unsigned int v35; // [rsp+30h] [rbp-D0h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v37; // [rsp+48h] [rbp-B8h]
  hkpSimulationIsland *v38; // [rsp+50h] [rbp-B0h]
  __int64 v39; // [rsp+58h] [rbp-A8h]
  hkpProcessCollisionOutput output; // [rsp+60h] [rbp-A0h] BYREF
  unsigned int v42; // [rsp+3160h] [rbp+3060h]

  m_simulationIsland = (*entities)->m_simulationIsland;
  v7 = numEntities;
  m_size = m_simulationIsland->m_entities.m_size;
  v38 = m_simulationIsland;
  v35 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v12 = (m_size + 127) & 0xFFFFFF80;
    v13 = &m_cur[v12];
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
    else
      Value->m_cur = v13;
  }
  else
  {
    m_cur = 0i64;
  }
  v14 = m_size | 0x80000000;
  v42 = m_size | 0x80000000;
  hkString::memSet(m_cur, 0, m_size);
  output.m_toi.m_time.m_storage = 3.40282e38;
  output.m_toi.m_properties.hkpSolverResults = 0i64;
  output.m_constraintOwner.m_storage = m_simulationIsland;
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "TtNarrowPhaseTOI";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v15[1] = v18;
  }
  v19 = 0i64;
  v39 = v7;
  v37 = 0i64;
  if ( v7 <= 0 )
    goto $END_4;
  while ( 1 )
  {
    v20 = entities[v19];
    m_cur[v20->m_storageIndex] = 1;
    entries.m_data = 0i64;
    entries.m_size = 0;
    entries.m_capacityAndFlags = 0x80000000;
    hkpLinkedCollidable::getCollisionEntriesSorted(&v20->m_collidable, &entries);
    v21 = 0;
    if ( entries.m_size > 0 )
      break;
LABEL_25:
    entries.m_size = 0;
    if ( entries.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        entries.m_data,
        16 * entries.m_capacityAndFlags);
    ++v19;
    entries.m_data = 0i64;
    entries.m_capacityAndFlags = 0x80000000;
    v37 = v19;
    if ( v19 >= v7 )
      goto LABEL_31;
  }
  v22 = 0i64;
  while ( 1 )
  {
    v23 = (hkpSimulationIsland **)((char *)entries.m_data[v22].m_partner + entries.m_data[v22].m_partner->m_ownerOffset);
    if ( v23[37] != v38 || !m_cur[*((unsigned __int16 *)v23 + 122)] )
      break;
LABEL_23:
    ++v21;
    ++v22;
    if ( v21 >= entries.m_size )
    {
      v19 = v37;
      v7 = v39;
      goto LABEL_25;
    }
  }
  m_agentEntry = entries.m_data[v22].m_agentEntry;
  m_collisionDispatcher = this->m_world->m_collisionDispatcher;
  v26 = (__int64)m_agentEntry->m_collisionQualityIndex << 6;
  if ( !*(unsigned int *)((char *)&m_collisionDispatcher->m_collisionQualityInfo[0].m_useContinuousPhysics.m_storage
                        + v26)
    || *(&m_collisionDispatcher->m_collisionQualityInfo[0].m_useSimpleToiHandling.m_bool + v26) )
  {
    if ( !hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            &entitiesNeedingPsiCollisionDetection->m_map,
            v20->m_uid,
            0i64) )
    {
      hkReferencedObject::addReference(v20);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &entitiesNeedingPsiCollisionDetection->m_map,
        &hkContainerHeapAllocator::s_alloc,
        v20->m_uid,
        (unsigned __int64)v20);
    }
    goto LABEL_23;
  }
  output.m_toi.m_time.m_storage = 3.40282e38;
  output.m_potentialContacts.m_storage = 0i64;
  output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
  v27 = &input->m_dispatcher.m_storage->m_collisionQualityInfo[m_agentEntry->m_collisionQualityIndex];
  input->m_collisionQualityInfo.m_storage = v27;
  input->m_createPredictiveAgents.m_storage = v27->m_useContinuousPhysics.m_storage;
  hkAgentNnMachine_ProcessAgent(m_agentEntry, input, &output, m_agentEntry->m_contactMgr);
  if ( hkOutOfMemoryState != MEMORY_STATE_OUT_OF_MEMORY )
  {
    if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
      ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))m_agentEntry->m_contactMgr->vfptr[3].__vecDelDtor)(
        m_agentEntry->m_contactMgr,
        m_agentEntry->m_collidable[0],
        m_agentEntry->m_collidable[1],
        input,
        &output);
    if ( output.m_toi.m_time.m_storage != 3.40282e38 )
      hkpContinuousSimulation::addToiEvent(this, &output, m_agentEntry);
    goto LABEL_23;
  }
  entries.m_size = 0;
  if ( entries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      entries.m_data,
      16 * entries.m_capacityAndFlags);
LABEL_31:
  v14 = v42;
  m_size = v35;
$END_4:
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v30 = __rdtsc();
    v31 = v29 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v28[1] = v31;
  }
  v32 = (m_size + 127) & 0xFFFFFF80;
  v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v34 = (v32 + 15) & 0xFFFFFFF0;
  if ( v32 > v33->m_slabSize || &m_cur[v34] != v33->m_cur || v33->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v33, m_cur, v34);
  else
    v33->m_cur = m_cur;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, v14 & 0x3FFFFFFF);
}

// File Line: 1306
// RVA: 0xD6EC60
void __fastcall hkpContinuousSimulation::collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(
        hkpContinuousSimulation *this,
        hkpProcessCollisionInput *input,
        hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection)
{
  hkpContinuousSimulation *v3; // rsi
  hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *v4; // rbx
  hkpProcessCollisionInput *v5; // r14
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  __int64 m_hashMod; // r9
  int v12; // edx
  __int64 v13; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v15; // r12d
  unsigned __int64 val; // rdi
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *CollisionEntriesDeterministicUnchecked; // r13
  __int64 m_size; // r15
  __int64 v19; // r14
  unsigned __int64 m_agentEntry; // rbx
  __int64 v21; // rcx
  unsigned __int64 v22; // rsi
  int v23; // ecx
  unsigned __int64 *v24; // rax
  __int64 v25; // r9
  int v26; // edx
  __int64 v27; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v28; // rax
  int v29; // ebx
  __int64 v30; // rdi
  hkpAgentNnEntry *v31; // rsi
  hkpConstraintOwner *v32; // rcx
  hkpCollisionDispatcher *m_storage; // rcx
  hkpWorld *m_world; // rbx
  bool v35; // zf
  _QWORD *v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  char *array; // [rsp+30h] [rbp-D0h] BYREF
  int v42; // [rsp+38h] [rbp-C8h]
  int v43; // [rsp+3Ch] [rbp-C4h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v44; // [rsp+40h] [rbp-C0h] BYREF
  hkpProcessCollisionOutput output; // [rsp+50h] [rbp-B0h] BYREF

  v3 = this;
  v4 = entitiesNeedingPsiCollisionDetection;
  v5 = input;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtRecollide PSI";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  ++v3->m_world->m_criticalOperationsLockCount;
  m_hashMod = v4->m_map.m_hashMod;
  v44.m_elem = 0i64;
  v44.m_numElems = 0;
  v44.m_hashMod = -1;
  array = 0i64;
  v42 = 0;
  v43 = 0x80000000;
  v12 = 0;
  v13 = 0i64;
  if ( (int)m_hashMod >= 0 )
  {
    m_elem = v4->m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v13;
      ++v12;
      ++m_elem;
    }
    while ( v13 <= m_hashMod );
  }
  v15 = v12;
  if ( v12 <= (int)m_hashMod )
  {
    do
    {
      val = v4->m_map.m_elem[v15].val;
      CollisionEntriesDeterministicUnchecked = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked((hkpLinkedCollidable *)(val + 32));
      m_size = CollisionEntriesDeterministicUnchecked->m_size;
      if ( m_size > 0 )
      {
        v19 = 0i64;
        do
        {
          m_agentEntry = (unsigned __int64)CollisionEntriesDeterministicUnchecked->m_data[v19].m_agentEntry;
          if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                &v44,
                                m_agentEntry,
                                0i64) )
          {
            v21 = (__int64)&v3->m_world->m_collisionDispatcher->m_collisionQualityInfo[*(char *)(m_agentEntry + 16)];
            if ( !*(_DWORD *)(v21 + 16)
              || *(_BYTE *)(v21 + 20)
              && _mm_shuffle_ps(*(__m128 *)(val + 448), *(__m128 *)(val + 448), 255).m128_f32[0] == 0.0 )
            {
              v22 = *(_QWORD *)(val + 296);
              if ( *(_BYTE *)(val + 352) == 5 )
                v22 = *(_QWORD *)((val ^ (*(_QWORD *)(m_agentEntry + 32)
                                        + *(char *)(*(_QWORD *)(m_agentEntry + 32) + 32i64)) ^ (*(_QWORD *)(m_agentEntry + 24)
                                                                                              + *(char *)(*(_QWORD *)(m_agentEntry + 24) + 32i64)))
                                + 0x128);
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                &v44,
                &hkContainerHeapAllocator::s_alloc,
                m_agentEntry,
                1ui64);
              v23 = v42;
              if ( v42 == (v43 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                v23 = v42;
              }
              v24 = (unsigned __int64 *)&array[16 * v23];
              v42 = v23 + 1;
              v24[1] = v22;
              v3 = this;
              *v24 = m_agentEntry;
            }
          }
          ++v19;
          --m_size;
        }
        while ( m_size );
        v4 = entitiesNeedingPsiCollisionDetection;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)val);
      v25 = v4->m_map.m_hashMod;
      v26 = v15 + 1;
      v27 = v15 + 1;
      if ( v27 <= v25 )
      {
        v28 = &v4->m_map.m_elem[v26];
        do
        {
          if ( v28->key != -1i64 )
            break;
          ++v27;
          ++v26;
          ++v28;
        }
        while ( v27 <= v25 );
      }
      v15 = v26;
    }
    while ( v26 <= (int)v25 );
    v5 = input;
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&v4->m_map);
  v29 = 0;
  if ( v42 > 0 )
  {
    v30 = 0i64;
    do
    {
      v31 = *(hkpAgentNnEntry **)&array[v30];
      v32 = *(hkpConstraintOwner **)&array[v30 + 8];
      output.m_toi.m_properties.hkpSolverResults = 0i64;
      output.m_constraintOwner.m_storage = v32;
      m_storage = v5->m_dispatcher.m_storage;
      output.m_toi.m_time.m_storage = 3.40282e38;
      output.m_potentialContacts.m_storage = 0i64;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      v5->m_collisionQualityInfo.m_storage = &m_storage->m_collisionQualityInfo[1];
      v5->m_createPredictiveAgents.m_storage = m_storage->m_collisionQualityInfo[(__int64)v31->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
      hkAgentNnMachine_ProcessAgent(v31, v5, &output, v31->m_contactMgr);
      if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
        break;
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v31->m_contactMgr->vfptr[3].__vecDelDtor)(
          v31->m_contactMgr,
          v31->m_collidable[0],
          v31->m_collidable[1],
          v5,
          &output);
      ++v29;
      v30 += 16i64;
    }
    while ( v29 < v42 );
  }
  m_world = this->m_world;
  v35 = m_world->m_criticalOperationsLockCount-- == 1;
  if ( v35 && !m_world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( m_world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(m_world);
    if ( m_world->m_pendingOperationQueueCount == 1 && m_world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(m_world);
  }
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  v38 = v36;
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "Et";
    v39 = __rdtsc();
    v40 = v37 + 2;
    *((_DWORD *)v40 - 2) = v39;
    v38[1] = v40;
  }
  v42 = 0;
  if ( v43 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v43);
  array = 0i64;
  v43 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v44,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v44);
}__int64>>::clearAndDeallocate(
    &v44,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v44);
}

// File Line: 1590
// RVA: 0xD6F0E0
void __fastcall hkpContinuousSimulation::handleSimpleToi(
        hkpContinuousSimulation *this,
        hkpWorld *world,
        hkpToiEvent *event,
        float physicsDeltaTime)
{
  hkpWorld *v6; // rbx
  _QWORD *Value; // rax
  __int64 v8; // r8
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpDynamicsContactMgr *m_contactMgr; // rcx
  hkpEntity **m_entities; // r15
  __int64 v15; // r12
  hkpEntity *v16; // rbp
  int v17; // esi
  __int64 v18; // rdi
  __int64 v19; // rbx
  hkpToiEvent *m_data; // rdx
  hkpEntity *v21; // rax
  __int64 v22; // rax
  hkpToiEvent *v23; // rcx
  hkpToiEvent *v24; // rdx
  hkpToiEvent *v25; // r8
  __int64 v26; // rcx
  signed __int64 v27; // r8
  unsigned __int64 v28; // rax
  hkpEntity *v29; // rax
  hkpWorld *m_world; // rbx
  bool v31; // zf
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  unsigned int v36; // [rsp+38h] [rbp-60h]
  _QWORD v37[2]; // [rsp+40h] [rbp-58h] BYREF
  char *v38; // [rsp+50h] [rbp-48h] BYREF
  int v39; // [rsp+58h] [rbp-40h]
  int v40; // [rsp+5Ch] [rbp-3Ch]
  char v41; // [rsp+60h] [rbp-38h] BYREF

  v6 = world;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtSimpleTOI";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  ++this->m_world->m_criticalOperationsLockCount;
  m_contactMgr = event->m_contactMgr;
  v38 = &v41;
  v39 = 0;
  v40 = -2147483646;
  ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpToiEvent *, __int64, char **))m_contactMgr->vfptr[9].__vecDelDtor)(
    m_contactMgr,
    event,
    v8,
    &v38);
  v36 = 0;
  m_entities = event->m_entities;
  v15 = 2i64;
  do
  {
    v16 = *m_entities;
    if ( (*m_entities)->m_collidable.m_broadPhaseHandle.m_objectQualityType == 3 )
    {
      hkSweptTransformUtil::freezeMotionState(event->m_time, &v16->m_motion.m_motionState);
      hkpWorldAgentUtil::invalidateTim(v16, v6->m_collisionInput);
      v17 = this->m_toiEvents.m_size - 1;
      v18 = v17;
      if ( v17 >= 0 )
      {
        v19 = v17;
        do
        {
          m_data = this->m_toiEvents.m_data;
          v21 = m_data[v19].m_entities[0];
          if ( v21 == v16 || m_data[v19].m_entities[1] == v16 )
          {
            if ( v21->m_motion.m_type.m_storage == 5 )
              v21 = m_data[v19].m_entities[1];
            ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))m_data[v19].m_contactMgr->vfptr[4].__vecDelDtor)(
              m_data[v19].m_contactMgr,
              v21->m_simulationIsland,
              &m_data[v19].m_properties);
            v22 = --this->m_toiEvents.m_size;
            if ( (_DWORD)v22 != v17 )
            {
              v23 = this->m_toiEvents.m_data;
              v24 = &v23[v19];
              v25 = &v23[v22];
              v26 = 18i64;
              v27 = (char *)v25 - (char *)v24;
              do
              {
                v28 = *(_QWORD *)((char *)&v24->m_time + v27);
                v24 = (hkpToiEvent *)((char *)v24 + 8);
                v24[-1].m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] = v28;
                --v26;
              }
              while ( v26 );
            }
          }
          --v17;
          --v19;
          --v18;
        }
        while ( v18 >= 0 );
        v6 = world;
      }
      v37[v36++] = v16;
    }
    ++m_entities;
    --v15;
  }
  while ( v15 );
  v29 = event->m_entities[0];
  if ( v29->m_motion.m_type.m_storage == 5 )
    v29 = event->m_entities[1];
  ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))event->m_contactMgr->vfptr[4].__vecDelDtor)(
    event->m_contactMgr,
    v29->m_simulationIsland,
    &event->m_properties);
  if ( v36 )
    ((void (__fastcall *)(hkpContinuousSimulation *, _QWORD *, _QWORD, hkpProcessCollisionInput *, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *))this->vfptr[9].__first_virtual_table_function__)(
      this,
      v37,
      v36,
      v6->m_collisionInput,
      &this->m_entitiesNeedingPsiCollisionDetection);
  v39 = 0;
  if ( v40 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v38, 8 * v40);
  m_world = this->m_world;
  v31 = m_world->m_criticalOperationsLockCount-- == 1;
  if ( v31 && !m_world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( m_world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(m_world);
    if ( m_world->m_pendingOperationQueueCount == 1 && m_world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(m_world);
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = v33 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v32[1] = v35;
  }
}

// File Line: 1663
// RVA: 0xD6F410
void __fastcall hkpContinuousSimulation::simulateToi(
        hkpContinuousSimulation *this,
        hkpWorld *world,
        hkpToiEvent *event,
        float physicsDeltaTime,
        float rotateNormal)
{
  hkpContinuousSimulation *v5; // r15
  hkpToiResourceMgr *m_toiResourceMgr; // rcx
  hkArray<hkpToiEvent,hkContainerHeapAllocator> *p_m_toiEvents; // rdi
  _QWORD *Value; // r8
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rax
  hkpEntity *v13; // r13
  hkpSimulationIsland *m_simulationIsland; // r13
  unsigned int m_size; // r14d
  hkLifoAllocator *v16; // rax
  char *m_cur; // rsi
  int v18; // ebx
  char *v19; // rcx
  hkpEntity *v20; // rdx
  hkpSimulationIsland *v21; // rdx
  int v22; // r15d
  __int64 v23; // r14
  __int64 v24; // rbx
  hkpToiEvent *m_data; // rdx
  hkpEntity *v26; // rax
  hkpEntity *v27; // rax
  hkpEntity *v28; // rax
  __int64 v29; // rax
  __int64 v30; // rdx
  __int64 v31; // rcx
  char *v32; // r8
  __int64 v33; // rax
  hkLifoAllocator *v34; // rax
  int v35; // r8d
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  _QWORD *v39; // rcx
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  unsigned int v44; // ebx
  hkpEntity **v45; // rdi
  int v46; // r14d
  __int64 i; // rsi
  hkReferencedObject *v48; // rcx
  int v49; // ebx
  hkpProcessCollisionInput *m_collisionInput; // rsi
  hkpWorld *m_world; // rbx
  bool v52; // zf
  _QWORD *v53; // r8
  _QWORD *v54; // rcx
  unsigned __int64 v55; // rax
  _QWORD *v56; // rcx
  int v57; // [rsp+50h] [rbp-80h] BYREF
  hkResult result; // [rsp+54h] [rbp-7Ch] BYREF
  char *buffer; // [rsp+58h] [rbp-78h]
  hkStepInfo stepInfo; // [rsp+60h] [rbp-70h] BYREF
  hkpToiResources toiResources; // [rsp+70h] [rbp-60h] BYREF
  float m_invNumMicroSteps; // [rsp+A8h] [rbp-28h]
  float v63; // [rsp+B0h] [rbp-20h]
  int v64; // [rsp+B4h] [rbp-1Ch]
  float v65; // [rsp+B8h] [rbp-18h]
  int v66; // [rsp+E0h] [rbp+10h]
  int v67; // [rsp+E4h] [rbp+14h]
  __m128 v68; // [rsp+F0h] [rbp+20h]
  hkpViolatedConstraintArray *m_violatedConstraintArray; // [rsp+108h] [rbp+38h]
  void (__fastcall *v70)(hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkpSolverResults *, int); // [rsp+118h] [rbp+48h]
  hkpSolverInfo solverInfo; // [rsp+120h] [rbp+50h] BYREF
  hkArray<hkpEntity *,hkContainerHeapAllocator> activeEntities; // [rsp+270h] [rbp+1A0h] BYREF
  char v73; // [rsp+280h] [rbp+1B0h] BYREF
  hkpConstraintSolverResources solverResources; // [rsp+480h] [rbp+3B0h] BYREF
  hkpContinuousSimulation *v75; // [rsp+5B0h] [rbp+4E0h]
  hkpWorld *worlda; // [rsp+5B8h] [rbp+4E8h]
  float vars0; // [rsp+5D0h] [rbp+500h]

  v5 = this;
  m_toiResourceMgr = this->m_toiResourceMgr;
  toiResources.m_maxNumActiveEntities = 1000;
  toiResources.m_maxNumConstraints = 1000;
  v57 = 4;
  result.m_enum = 4;
  buffer = 0i64;
  stepInfo.m_startTime.m_storage = 0.0;
  *(_QWORD *)&stepInfo.m_deltaTime.m_storage = 0i64;
  *(_QWORD *)&toiResources.m_minPriorityToProcess = 0i64;
  p_m_toiEvents = &v5->m_toiEvents;
  if ( *(_DWORD *)((__int64 (__fastcall *)(hkpToiResourceMgr *, int *, hkpToiEvent *, hkArray<hkpToiEvent,hkContainerHeapAllocator> *, hkpToiResources *))m_toiResourceMgr->vfptr[1].__first_virtual_table_function__)(
                    m_toiResourceMgr,
                    &v57,
                    event,
                    &v5->m_toiEvents,
                    &toiResources) != 1 )
  {
    ++v5->m_world->m_criticalOperationsLockCount;
    stepInfo.m_startTime.m_storage = event->m_time;
    activeEntities.m_data = (hkpEntity **)&v73;
    activeEntities.m_size = 0;
    v70 = hkpBeginConstraints;
    activeEntities.m_capacityAndFlags = -2147483584;
    stepInfo.m_endTime.m_storage = hkpWorld::getCurrentPsiTime(world);
    stepInfo.m_deltaTime.m_storage = stepInfo.m_endTime.m_storage - stepInfo.m_startTime.m_storage;
    stepInfo.m_invDeltaTime.m_storage = 1.0 / (float)(stepInfo.m_endTime.m_storage - stepInfo.m_startTime.m_storage);
    hkpSolverInfo::operator=(&solverInfo, &world->m_dynamicsStepInfo.m_solverInfo);
    m_violatedConstraintArray = world->m_violatedConstraintArray;
    memset(&solverInfo.m_globalAccelerationPerSubStep, 0, 32);
    solverInfo.m_frictionTau = FLOAT_0_25;
    HIDWORD(toiResources.m_priorityClassMap) = LODWORD(stepInfo.m_deltaTime.m_storage);
    solverInfo.m_numSteps = 1;
    solverInfo.m_dampDivFrictionTau = FLOAT_5_5999999;
    solverInfo.m_invDeltaTime = 1.0 / physicsDeltaTime;
    *(float *)&toiResources.m_priorityClassMap = 1.0 / physicsDeltaTime;
    solverInfo.m_integrateVelocityFactor = (hkVector4f)_xmm;
    toiResources.m_priorityClassRatios = (const float *)(LODWORD(stepInfo.m_invDeltaTime.m_storage) | 0x3F80000000000000i64);
    solverInfo.m_dampDivTau = FLOAT_2_8;
    solverInfo.m_deltaTime = physicsDeltaTime;
    solverInfo.m_numMicroSteps = 1;
    *((float *)&toiResources.m_scratchpadSize + 1) = solverInfo.m_invNumMicroSteps * physicsDeltaTime;
    *(float *)&toiResources.m_scratchpadSize = physicsDeltaTime;
    m_invNumMicroSteps = solverInfo.m_invNumMicroSteps;
    solverInfo.m_invIntegrateVelocityFactor = (hkVector4f)_xmm;
    v65 = (float)(1.0 / physicsDeltaTime) * 0.17857143;
    solverInfo.m_invNumSteps = 1.0;
    v63 = (float)(1.0 / physicsDeltaTime) * 0.35714287;
    v68 = _mm_shuffle_ps(
            (__m128)LODWORD(solverInfo.m_maxConstraintViolationSqrd),
            (__m128)LODWORD(solverInfo.m_maxConstraintViolationSqrd),
            0);
    solverInfo.m_tau = 0.5;
    solverInfo.m_damping = 1.4;
    solverInfo.m_tauDivDamp = 0.35714287;
    solverInfo.m_frictionTauDivDamp = 0.17857143;
    v66 = 1056964608;
    v67 = 1068708659;
    v64 = 1068708659;
    hkpConstraintSolverSetup::initializeSolverState(
      &stepInfo,
      &solverInfo,
      (hkpConstraintQueryIn *)&toiResources.m_scratchpadSize,
      buffer,
      SLODWORD(stepInfo.m_startTime.m_storage),
      *(const char **)&stepInfo.m_deltaTime.m_storage,
      *(const float **)&toiResources.m_minPriorityToProcess,
      &solverResources);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = Value[1];
    if ( v11 < Value[3] )
    {
      *(_QWORD *)v11 = "LtTOI";
      *(_QWORD *)(v11 + 16) = "StSolveToi";
      v12 = __rdtsc();
      *(_DWORD *)(v11 + 8) = v12;
      Value[1] = v11 + 24;
    }
    v13 = event->m_entities[0];
    if ( v13->m_motion.m_type.m_storage == 5 )
      m_simulationIsland = event->m_entities[1]->m_simulationIsland;
    else
      m_simulationIsland = v13->m_simulationIsland;
    m_size = m_simulationIsland->m_entities.m_size;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)v16->m_cur;
    v18 = (m_size + 127) & 0xFFFFFF80;
    v57 = v18;
    v19 = &m_cur[v18];
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
    else
      v16->m_cur = v19;
    *(_QWORD *)&toiResources.m_maxNumActiveEntities = m_cur;
    toiResources.m_numToiSolverIterations = m_size;
    hkString::memSet(m_cur, 0, m_size);
    hkLs_localizedSolveToi(
      &result,
      &toiResources,
      &solverResources,
      event,
      v5->m_toiResourceMgr,
      worlda,
      &activeEntities,
      (hkFixedArray<unsigned char> *)&toiResources.m_maxNumActiveEntities,
      vars0);
    hkpConstraintSolverSetup::shutdownSolver(&solverResources);
    v20 = event->m_entities[0];
    if ( v20->m_motion.m_type.m_storage == 5 )
      v21 = event->m_entities[1]->m_simulationIsland;
    else
      v21 = v20->m_simulationIsland;
    ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))event->m_contactMgr->vfptr[4].__vecDelDtor)(
      event->m_contactMgr,
      v21,
      &event->m_properties);
    if ( result.m_enum )
    {
      activeEntities.m_size = 0;
    }
    else
    {
      v22 = v5->m_toiEvents.m_size - 1;
      v23 = v22;
      if ( v22 >= 0 )
      {
        v24 = v22;
        do
        {
          m_data = p_m_toiEvents->m_data;
          v26 = p_m_toiEvents->m_data[v24].m_entities[0];
          if ( v26->m_simulationIsland == m_simulationIsland && m_cur[v26->m_storageIndex] == 16
            || (v27 = m_data[v24].m_entities[1], v27->m_simulationIsland == m_simulationIsland)
            && m_cur[v27->m_storageIndex] == 16 )
          {
            v28 = m_data[v24].m_entities[0];
            if ( v28->m_motion.m_type.m_storage == 5 )
              v28 = m_data[v24].m_entities[1];
            ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))m_data[v24].m_contactMgr->vfptr[4].__vecDelDtor)(
              m_data[v24].m_contactMgr,
              v28->m_simulationIsland,
              &m_data[v24].m_properties);
            v29 = --p_m_toiEvents->m_size;
            if ( (_DWORD)v29 != v22 )
            {
              v30 = (__int64)&p_m_toiEvents->m_data[v24];
              v31 = 18i64;
              v32 = (char *)&p_m_toiEvents->m_data[v29] - v30;
              do
              {
                v33 = *(_QWORD *)&v32[v30];
                v30 += 8i64;
                *(_QWORD *)(v30 - 8) = v33;
                --v31;
              }
              while ( v31 );
            }
          }
          --v22;
          --v24;
          --v23;
        }
        while ( v23 >= 0 );
        v18 = v57;
      }
      hkReferencedObject::addReferences(activeEntities.m_data, activeEntities.m_size, 8);
      v5 = v75;
    }
    v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = (v18 + 15) & 0xFFFFFFF0;
    if ( v18 > v34->m_slabSize || &m_cur[v35] != v34->m_cur || v34->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v34, m_cur, v35);
    else
      v34->m_cur = m_cur;
    ((void (__fastcall *)(hkpToiResourceMgr *, hkpToiEvent *, hkArray<hkpToiEvent,hkContainerHeapAllocator> *, hkpToiResources *))v5->m_toiResourceMgr->vfptr[3].__vecDelDtor)(
      v5->m_toiResourceMgr,
      event,
      p_m_toiEvents,
      &toiResources);
    v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v37 = (_QWORD *)v36[1];
    if ( (unsigned __int64)v37 < v36[3] )
    {
      *v37 = "StPendingOperations";
      v38 = __rdtsc();
      v39 = v37 + 2;
      *((_DWORD *)v39 - 2) = v38;
      v36[1] = v39;
    }
    v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v41 = (_QWORD *)v40[1];
    if ( (unsigned __int64)v41 < v40[3] )
    {
      *v41 = "StCollide";
      v42 = __rdtsc();
      v43 = v41 + 2;
      *((_DWORD *)v43 - 2) = v42;
      v40[1] = v43;
    }
    v44 = activeEntities.m_size;
    if ( activeEntities.m_size )
    {
      v45 = activeEntities.m_data;
      v46 = activeEntities.m_size - 1;
      for ( i = activeEntities.m_size - 1; i >= 0; --i )
      {
        v48 = v45[i];
        if ( !v48[1].vfptr )
        {
          v49 = v44 - 1;
          activeEntities.m_size = v49;
          if ( v49 != v46 )
            v45[i] = v45[v49];
          hkReferencedObject::removeReference(v48);
          v44 = activeEntities.m_size;
          v45 = activeEntities.m_data;
        }
        --v46;
      }
      m_collisionInput = worlda->m_collisionInput;
      if ( v44 )
      {
        hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(v5, v45, v44, worlda, 0i64);
        if ( hkOutOfMemoryState != MEMORY_STATE_OUT_OF_MEMORY )
          ((void (__fastcall *)(hkpContinuousSimulation *, hkpEntity **, _QWORD, hkpProcessCollisionInput *, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *))v5->vfptr[9].__first_virtual_table_function__)(
            v5,
            v45,
            v44,
            m_collisionInput,
            &v5->m_entitiesNeedingPsiCollisionDetection);
        v45 = activeEntities.m_data;
        v44 = activeEntities.m_size;
      }
      hkReferencedObject::removeReferences(v45, v44, 8);
    }
    m_world = v5->m_world;
    v52 = m_world->m_criticalOperationsLockCount-- == 1;
    if ( v52 && !m_world->m_blockExecutingPendingOperations.m_bool )
    {
      if ( m_world->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(m_world);
      if ( m_world->m_pendingOperationQueueCount == 1 && m_world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(m_world);
    }
    v53 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v54 = (_QWORD *)v53[1];
    if ( (unsigned __int64)v54 < v53[3] )
    {
      *v54 = "lt";
      v55 = __rdtsc();
      v56 = v54 + 2;
      *((_DWORD *)v56 - 2) = v55;
      v53[1] = v56;
    }
    activeEntities.m_size = 0;
    if ( activeEntities.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        activeEntities.m_data,
        8 * activeEntities.m_capacityAndFlags);
  }
}

// File Line: 1798
// RVA: 0xD6FB90
void __fastcall hkpContinuousSimulation::processAgentNnEntries(
        hkpContinuousSimulation *this,
        hkpAgentNnEntry *const *entries,
        int numEntries,
        hkpProcessCollisionInput *collisionInput,
        hkpSimulationIsland *island,
        hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride)
{
  __int64 v8; // rdi
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r9
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  __int64 v15; // rsi
  __int64 v16; // r14
  hkpAgentNnEntry *v17; // rdi
  hkpCollisionDispatcher *m_storage; // rcx
  hkpCollisionQualityInfo *v19; // rax
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  hkpProcessCollisionOutput output; // [rsp+30h] [rbp-30D8h] BYREF

  v8 = numEntries;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtNarrowPhaseTOI";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  v15 = 0i64;
  v16 = v8;
  if ( (int)v8 > 0 )
  {
    do
    {
      v17 = entries[v15];
      output.m_toi.m_properties.hkpSolverResults = 0i64;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      output.m_constraintOwner.m_storage = island;
      output.m_toi.m_time.m_storage = 3.40282e38;
      output.m_potentialContacts.m_storage = 0i64;
      if ( collisionQualityOverride )
      {
        if ( collisionQualityOverride == DISABLE_TOIS )
        {
          v19 = &collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[1];
        }
        else
        {
          if ( collisionQualityOverride != DISABLE_TOIS_AND_EXPAND_MANIFOLD )
            goto LABEL_12;
          m_storage = collisionInput->m_dispatcher.m_storage;
          collisionInput->m_collisionQualityInfo.m_storage = &collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[7];
          if ( v17->m_collisionQualityIndex != 6 )
            goto LABEL_12;
          v19 = &m_storage->m_collisionQualityInfo[6];
        }
      }
      else
      {
        v19 = &collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[v17->m_collisionQualityIndex];
      }
      collisionInput->m_collisionQualityInfo.m_storage = v19;
LABEL_12:
      collisionInput->m_createPredictiveAgents.m_storage = collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[(__int64)v17->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
      hkAgentNnMachine_ProcessAgent(v17, collisionInput, &output, v17->m_contactMgr);
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v17->m_contactMgr->vfptr[3].__vecDelDtor)(
          v17->m_contactMgr,
          v17->m_collidable[0],
          v17->m_collidable[1],
          collisionInput,
          &output);
      if ( output.m_toi.m_time.m_storage != 3.40282e38 )
        hkpContinuousSimulation::addToiEvent(this, &output, v17);
      ++v15;
    }
    while ( v15 < v16 );
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
}

// File Line: 1866
// RVA: 0xD719D0
void __fastcall hkLs_collectAgentEntriesToProcess(
        hkpEntity *entity,
        hkpConstraintInstance::ConstraintPriority minPriorityToProcess,
        float time,
        hkFixedArray<unsigned char> *entityState,
        hkLocalArray<hkpAgentNnEntry *> *entriesOut)
{
  int m_size; // r9d
  int v8; // esi
  __int64 v9; // rdi
  hkpLinkedCollidable::CollisionEntry *m_data; // rbp
  char *v11; // r8
  __int64 v12; // rax
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> v13; // [rsp+20h] [rbp-38h] BYREF

  v13.m_data = 0i64;
  v13.m_size = 0;
  v13.m_capacityAndFlags = 0x80000000;
  hkpLinkedCollidable::getCollisionEntriesSorted(&entity->m_collidable, &v13);
  m_size = v13.m_size;
  v8 = 0;
  if ( v13.m_size > 0 )
  {
    v9 = 0i64;
    while ( 1 )
    {
      m_data = v13.m_data;
      if ( minPriorityToProcess <= (unsigned __int8)v13.m_data[v9].m_agentEntry->m_collisionQualityIndex )
      {
        v11 = (char *)v13.m_data[v9].m_partner + v13.m_data[v9].m_partner->m_ownerOffset;
        if ( v11[352] == 5 )
          goto LABEL_8;
        if ( entityState->m_data.m_storage[*((unsigned __int16 *)v11 + 122)] < 8u )
          break;
      }
LABEL_11:
      ++v8;
      ++v9;
      if ( v8 >= m_size )
        goto LABEL_12;
    }
    v12 = *((unsigned __int16 *)v11 + 122);
    if ( !entityState->m_data.m_storage[v12] )
    {
      entityState->m_data.m_storage[v12] = 1;
      hkSweptTransformUtil::lerp2((hkSweptTransformf *)(v11 + 432), time, (hkTransformf *)(v11 + 368));
    }
LABEL_8:
    if ( entriesOut->m_size == (entriesOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&entriesOut->m_data, 8);
    entriesOut->m_data[entriesOut->m_size++] = m_data[v9].m_agentEntry;
    m_size = v13.m_size;
    goto LABEL_11;
  }
LABEL_12:
  v13.m_size = 0;
  if ( v13.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v13.m_data,
      16 * v13.m_capacityAndFlags);
}

// File Line: 1929
// RVA: 0xD70E50
__int64 __fastcall hkLs_areVelocitiesOk(
        float psiTimeLeft,
        hkpConstraintSchemaInfo *constraintStatus,
        const float *velocities,
        int numVelocities,
        hkpProcessCollisionInput *processInput)
{
  __int64 result; // rax
  int v6; // ecx
  float i; // xmm2_4

  result = 0xFFFFFFFFi64;
  v6 = 0;
  for ( i = processInput->m_dispatcher.m_storage->m_collisionQualityInfo[(__int64)constraintStatus->m_constraint->m_priority.m_storage].m_maxContraintViolation
          * constraintStatus->m_allowedPenetrationDepth; v6 < numVelocities; ++velocities )
  {
    if ( (float)(COERCE_FLOAT((unsigned int)(2 * *(_DWORD *)velocities) >> 1) * psiTimeLeft) > i )
    {
      i = COERCE_FLOAT((unsigned int)(2 * *(_DWORD *)velocities) >> 1) * psiTimeLeft;
      result = (unsigned int)v6;
    }
    ++v6;
  }
  return result;
}

// File Line: 1995
// RVA: 0xD70AC0
void __fastcall hkLs_toiCheckValidityOfConstraints(
        hkpConstraintSolverResources *solverResources,
        hkpProcessCollisionInput *processInput,
        hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus,
        int *firstNonActiveConstraintStatus,
        hkpConstraintInstance::ConstraintPriority minPriorityToProcess,
        hkFixedArray<unsigned char> *entityState,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *touchedEntities,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *toBeActivated)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v8; // rsi
  int v11; // ebx
  hkLifoAllocator *Value; // rax
  char *m_cur; // r14
  int v14; // ebx
  char *v15; // rcx
  int v16; // edi
  char *v17; // r8
  int v18; // r9d
  __int64 v19; // r10
  _OWORD *v20; // rax
  hkpEntity *v21; // rdx
  char *v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  int *v25; // r11
  unsigned __int64 v26; // rbp
  unsigned __int64 v27; // rbx
  hkpConstraintSchemaInfo *v28; // r14
  __int64 v29; // rcx
  int v30; // eax
  hkpConstraintSchemaInfo *m_data; // r10
  hkpConstraintInstance *v32; // rdx
  hkpJacobianSchema *v33; // r8
  __int64 v34; // r9
  int ToiViolatingConstraintVelocity; // eax
  char *v36; // rdx
  __int64 v37; // r8
  __int128 v38; // xmm0
  hkpEntity *v39; // rcx
  char *v40; // rax
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  hkpEntity *v44; // [rsp+30h] [rbp-448h]
  float velocities[256]; // [rsp+40h] [rbp-438h] BYREF
  char *v47; // [rsp+490h] [rbp+18h]

  v8 = touchedEntities;
  v11 = 2 * touchedEntities->m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v14 = (16 * v11 + 127) & 0xFFFFFF80;
  v47 = m_cur;
  v15 = &m_cur[v14];
  if ( v14 > Value->m_slabSize || v15 > Value->m_end )
  {
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v14);
    v47 = m_cur;
  }
  else
  {
    Value->m_cur = v15;
  }
  v16 = 0;
  v17 = m_cur;
  v18 = 0;
  if ( touchedEntities->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v17 + 16;
      ++v18;
      v21 = touchedEntities->m_data[v19];
      v17 += 32;
      ++v19;
      v22 = &solverResources->m_accumulators->m_type.m_storage + v21->m_solverData;
      *((_OWORD *)v17 - 2) = *((_OWORD *)v22 + 1);
      *v20 = *((_OWORD *)v22 + 2);
      v23 = _mm_sub_ps(
              v21->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
              v21->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad);
      *((__m128 *)v22 + 1) = v23;
      v24 = _mm_shuffle_ps(
              v21->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
              v21->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
              255);
      *((__m128 *)v22 + 1) = _mm_mul_ps(v23, v24);
      *((__m128 *)v22 + 2) = _mm_mul_ps(v21->m_motion.m_motionState.m_deltaAngle.m_quad, v24);
    }
    while ( v18 < touchedEntities->m_size );
  }
  v25 = firstNonActiveConstraintStatus;
  v26 = *firstNonActiveConstraintStatus;
  if ( (int)v26 < constraintStatus->m_size )
  {
    v27 = v26;
    while ( 1 )
    {
      v28 = &constraintStatus->m_data[v27];
      if ( minPriorityToProcess <= (unsigned __int8)v28->m_constraint->m_priority.m_storage )
      {
        v44 = v28->m_constraint->m_internal->m_entities[entityState->m_data.m_storage[v28->m_constraint->m_internal->m_entities[0]->m_storageIndex] == 16];
        if ( (entityState->m_data.m_storage[v44->m_storageIndex] & 4) == 0 )
        {
          ToiViolatingConstraintVelocity = hkSolveGetToiViolatingConstraintVelocity(
                                             solverResources->m_solverInfo,
                                             v28->m_schema,
                                             solverResources->m_accumulators,
                                             256,
                                             velocities);
          if ( hkLs_areVelocitiesOk(
                 solverResources->m_stepInfo->m_deltaTime.m_storage,
                 v28,
                 velocities,
                 ToiViolatingConstraintVelocity,
                 processInput) == -1 )
          {
            v25 = firstNonActiveConstraintStatus;
            goto LABEL_18;
          }
          entityState->m_data.m_storage[v44->m_storageIndex] |= 4u;
          if ( toBeActivated->m_size == (toBeActivated->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&toBeActivated->m_data, 8);
          v25 = firstNonActiveConstraintStatus;
          toBeActivated->m_data[toBeActivated->m_size++] = v44;
        }
        v29 = *v25;
        v30 = v29 + 1;
        v29 *= 3i64;
        *v25 = v30;
        m_data = constraintStatus->m_data;
        v32 = (hkpConstraintInstance *)*((_QWORD *)&constraintStatus->m_data->m_constraint + v29);
        v33 = (&constraintStatus->m_data->m_schema)[v29];
        v34 = *((_QWORD *)&constraintStatus->m_data->m_allowedPenetrationDepth + v29);
        *((_QWORD *)&m_data->m_constraint + v29) = constraintStatus->m_data[v27].m_constraint;
        (&m_data->m_schema)[v29] = m_data[v27].m_schema;
        *((_QWORD *)&m_data->m_allowedPenetrationDepth + v29) = *(_QWORD *)&m_data[v27].m_allowedPenetrationDepth;
        m_data[v27].m_constraint = v32;
        m_data[v27].m_schema = v33;
        *(_QWORD *)&m_data[v27].m_allowedPenetrationDepth = v34;
      }
LABEL_18:
      LODWORD(v26) = v26 + 1;
      ++v27;
      if ( (int)v26 >= constraintStatus->m_size )
      {
        v8 = touchedEntities;
        m_cur = v47;
        break;
      }
    }
  }
  v36 = m_cur;
  if ( v8->m_size > 0 )
  {
    v37 = 0i64;
    do
    {
      v38 = *(_OWORD *)v36;
      ++v16;
      v39 = v8->m_data[v37];
      v36 += 32;
      ++v37;
      v40 = &solverResources->m_accumulators->m_type.m_storage + v39->m_solverData;
      *((_OWORD *)v40 + 1) = v38;
      *((_OWORD *)v40 + 2) = *((_OWORD *)v36 - 1);
    }
    while ( v16 < v8->m_size );
  }
  v41 = (32 * v8->m_size + 127) & 0xFFFFFF80;
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v41 + 15) & 0xFFFFFFF0;
  if ( v41 > v42->m_slabSize || &m_cur[v43] != v42->m_cur || v42->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v42, m_cur, v43);
  else
    v42->m_cur = m_cur;
}

// File Line: 2167
// RVA: 0xD71B60
hkBool *__fastcall less_EntityPtr(hkBool *result, hkpEntity *a, hkpEntity *b)
{
  result->m_bool = a->m_uid < b->m_uid;
  return result;
}

// File Line: 2172
// RVA: 0xD71B80
hkBool *__fastcall less_ConstraintPtr(hkBool *result, hkpConstraintInstance *a, hkpConstraintInstance *b)
{
  hkConstraintInternal *m_internal; // r11
  hkConstraintInternal *v4; // r10

  m_internal = b->m_internal;
  v4 = a->m_internal;
  if ( v4->m_entities[(unsigned __int8)v4->m_whoIsMaster]->m_uid >= m_internal->m_entities[(unsigned __int8)m_internal->m_whoIsMaster]->m_uid )
  {
    result->m_bool = v4->m_entities[(unsigned __int8)v4->m_whoIsMaster]->m_uid == m_internal->m_entities[(unsigned __int8)m_internal->m_whoIsMaster]->m_uid
                  && v4 < m_internal;
    return result;
  }
  else
  {
    result->m_bool = 1;
    return result;
  }
}

// File Line: 2193
// RVA: 0xD70EC0
void __fastcall hkLs_toiActivateEntitiesAndCheckConstraints(
        hkpProcessCollisionInput *collisionInput,
        hkpConstraintInstance::ConstraintPriority minPriorityToProcess,
        float time,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *toBeActivated,
        hkFixedArray<unsigned char> *entityState,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newTouchedEntities,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *newTouchedConstraints)
{
  __int64 v8; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v9; // r15
  hkLifoAllocator *Value; // rax
  hkpAgentNnEntry **m_cur; // rdx
  hkpAgentNnEntry **v13; // rcx
  int v14; // esi
  hkpEntity *v15; // rbx
  __int64 m_storageIndex; // rax
  hkStepInfo m_stepInfo; // xmm6
  float v18; // xmm1_4
  float v19; // xmm0_4
  int m_size; // r8d
  int v21; // eax
  hkpAgentNnEntry **m_localMemory; // rdi
  __int64 v23; // rsi
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // r8d
  __int64 v27; // rcx
  hkpEntity **m_data; // rax
  int v29; // r15d
  __int64 v30; // r13
  __int64 v31; // rbp
  hkpEntity *v32; // rdi
  __int64 v33; // rax
  int v34; // eax
  int v35; // edi
  int v36; // ebp
  __int64 v37; // r15
  _QWORD *v38; // rsi
  hkpEntity *v39; // rdi
  __int64 v40; // rax
  int v41; // r8d
  int v42; // r8d
  int v43; // [rsp+30h] [rbp-98h]
  __int64 v44; // [rsp+38h] [rbp-90h]
  hkLocalArray<hkpAgentNnEntry *> entriesOut; // [rsp+40h] [rbp-88h] BYREF
  int v46; // [rsp+D0h] [rbp+8h]
  int v48; // [rsp+E0h] [rbp+18h]

  v8 = 0i64;
  v9 = toBeActivated;
  entriesOut.m_data = 0i64;
  entriesOut.m_size = 0;
  entriesOut.m_capacityAndFlags = 0x80000000;
  entriesOut.m_initialCapacity = 1000;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpAgentNnEntry **)Value->m_cur;
  v13 = m_cur + 1008;
  if ( Value->m_slabSize < 8064 || v13 > Value->m_end )
    m_cur = (hkpAgentNnEntry **)hkLifoAllocator::allocateFromNewSlab(Value, 8064);
  else
    Value->m_cur = v13;
  entriesOut.m_data = m_cur;
  entriesOut.m_capacityAndFlags = -2147482648;
  entriesOut.m_localMemory = m_cur;
  v14 = 0;
  if ( v9->m_size > 0 )
  {
    do
    {
      v15 = v9->m_data[v8];
      m_storageIndex = v15->m_storageIndex;
      if ( !entityState->m_data.m_storage[m_storageIndex] )
      {
        entityState->m_data.m_storage[m_storageIndex] = 1;
        hkSweptTransformUtil::lerp2(
          &v15->m_motion.m_motionState.m_sweptTransform,
          time,
          &v15->m_motion.m_motionState.m_transform);
      }
      entityState->m_data.m_storage[v15->m_storageIndex] = 8;
      hkLs_collectAgentEntriesToProcess(v15, minPriorityToProcess, time, entityState, &entriesOut);
      ++v14;
      ++v8;
    }
    while ( v14 < v9->m_size );
    m_cur = entriesOut.m_data;
  }
  m_stepInfo = collisionInput->m_stepInfo;
  v18 = 0.0;
  collisionInput->m_stepInfo.m_endTime.m_storage = time;
  v19 = time - collisionInput->m_stepInfo.m_startTime.m_storage;
  collisionInput->m_stepInfo.m_deltaTime.m_storage = v19;
  if ( v19 > 0.0 )
    v18 = 1.0 / v19;
  m_size = entriesOut.m_size;
  collisionInput->m_stepInfo.m_invDeltaTime.m_storage = v18;
  hkpContinuousSimulation::processAgentNnEntries(
    (hkpContinuousSimulation *)(*v9->m_data)->m_world->m_simulation,
    m_cur,
    m_size,
    collisionInput,
    (*v9->m_data)->m_simulationIsland,
    DISABLE_TOIS_AND_EXPAND_MANIFOLD);
  v21 = entriesOut.m_size;
  m_localMemory = entriesOut.m_localMemory;
  collisionInput->m_stepInfo = m_stepInfo;
  v23 = 0i64;
  if ( m_localMemory == entriesOut.m_data )
    v21 = 0;
  entriesOut.m_size = v21;
  v24 = (8 * entriesOut.m_initialCapacity + 127) & 0xFFFFFF80;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (v24 + 15) & 0xFFFFFFF0;
  if ( v24 > v25->m_slabSize || (char *)m_localMemory + v26 != v25->m_cur || v25->m_firstNonLifoEnd == m_localMemory )
    hkLifoAllocator::slowBlockFree(v25, (char *)m_localMemory, v26);
  else
    v25->m_cur = m_localMemory;
  entriesOut.m_size = 0;
  if ( entriesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      entriesOut.m_data,
      8 * entriesOut.m_capacityAndFlags);
  v48 = 0;
  if ( v9->m_size > 0 )
  {
    v27 = 0i64;
    v44 = 0i64;
    do
    {
      m_data = v9->m_data;
      v29 = 0;
      v30 = *(__int64 *)((char *)m_data + v27);
      entityState->m_data.m_storage[*(unsigned __int16 *)(v30 + 244)] = 16;
      if ( *(_WORD *)(v30 + 256) )
      {
        do
        {
          v31 = *(_QWORD *)(v30 + 248);
          if ( minPriorityToProcess <= *(unsigned __int8 *)(*(_QWORD *)(v23 + v31) + 56i64) )
          {
            v32 = (hkpEntity *)(v30 ^ *(_QWORD *)(v23 + v31 + 8) ^ *(_QWORD *)(v23 + v31 + 16));
            if ( v32->m_motion.m_type.m_storage == 5 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&newTouchedConstraints->m_data,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = *(hkpConstraintInstance **)(v23 + v31);
            }
            else if ( entityState->m_data.m_storage[*(unsigned __int16 *)((v30 ^ *(_QWORD *)(v23 + v31 + 8) ^ *(_QWORD *)(v23 + v31 + 16))
                                                                        + 0xF4)] != 16 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&newTouchedConstraints->m_data,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = *(hkpConstraintInstance **)(v23 + v31);
              if ( entityState->m_data.m_storage[v32->m_storageIndex] < 2u )
              {
                if ( newTouchedEntities->m_size == (newTouchedEntities->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    &hkContainerHeapAllocator::s_alloc,
                    (const void **)&newTouchedEntities->m_data,
                    8);
                newTouchedEntities->m_data[newTouchedEntities->m_size++] = v32;
                v33 = v32->m_storageIndex;
                if ( !entityState->m_data.m_storage[v33] )
                {
                  entityState->m_data.m_storage[v33] = 1;
                  hkSweptTransformUtil::lerp2(
                    &v32->m_motion.m_motionState.m_sweptTransform,
                    time,
                    &v32->m_motion.m_motionState.m_transform);
                }
                entityState->m_data.m_storage[v32->m_storageIndex] = 2;
              }
            }
          }
          ++v29;
          v23 += 64i64;
        }
        while ( v29 < *(unsigned __int16 *)(v30 + 256) );
        v23 = 0i64;
      }
      v34 = newTouchedConstraints->m_size;
      v35 = newTouchedEntities->m_size;
      v46 = v34;
      v43 = v35;
      v36 = 0;
      if ( *(int *)(v30 + 272) > 0 )
      {
        v37 = 0i64;
        do
        {
          v38 = *(_QWORD **)(*(_QWORD *)(v37 + *(_QWORD *)(v30 + 264)) + 96i64);
          if ( minPriorityToProcess <= *(unsigned __int8 *)(*v38 + 56i64) )
          {
            v39 = (hkpEntity *)(v30 ^ v38[1] ^ v38[2]);
            if ( v39->m_motion.m_type.m_storage == 5 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&newTouchedConstraints->m_data,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = (hkpConstraintInstance *)*v38;
            }
            else if ( entityState->m_data.m_storage[*(unsigned __int16 *)((v30 ^ v38[1] ^ v38[2]) + 0xF4)] != 16 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&newTouchedConstraints->m_data,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = (hkpConstraintInstance *)*v38;
              if ( entityState->m_data.m_storage[v39->m_storageIndex] < 2u )
              {
                if ( newTouchedEntities->m_size == (newTouchedEntities->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    &hkContainerHeapAllocator::s_alloc,
                    (const void **)&newTouchedEntities->m_data,
                    8);
                newTouchedEntities->m_data[newTouchedEntities->m_size++] = v39;
                v40 = v39->m_storageIndex;
                if ( !entityState->m_data.m_storage[v40] )
                {
                  entityState->m_data.m_storage[v40] = 1;
                  hkSweptTransformUtil::lerp2(
                    &v39->m_motion.m_motionState.m_sweptTransform,
                    time,
                    &v39->m_motion.m_motionState.m_transform);
                }
                entityState->m_data.m_storage[v39->m_storageIndex] = 2;
              }
            }
          }
          ++v36;
          v37 += 8i64;
        }
        while ( v36 < *(_DWORD *)(v30 + 272) );
        v34 = v46;
        v35 = v43;
        v23 = 0i64;
      }
      v41 = newTouchedConstraints->m_size - v34;
      if ( v41 > 1 )
        hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
          (hkpRigidBody **)&newTouchedConstraints->m_data[v34],
          0,
          v41 - 1,
          (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))less_ConstraintPtr);
      v42 = newTouchedEntities->m_size - v35;
      if ( v42 > 1 )
        hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
          (hkpRigidBody **)&newTouchedEntities->m_data[v35],
          0,
          v42 - 1,
          (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))less_EntityPtr);
      v9 = toBeActivated;
      v27 = v44 + 8;
      ++v48;
      v44 += 8i64;
    }
    while ( v48 < toBeActivated->m_size );
  }
}

// File Line: 2361
// RVA: 0xD714A0
void __fastcall hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities(
        hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus,
        int *firstNonActiveConstraintStatus,
        int numOfConstraintsToCheckAtTheEndOfTheList)
{
  int v5; // r11d
  unsigned __int64 v6; // rbx
  hkConstraintInternal *m_internal; // rax
  __int64 v8; // rcx
  int v9; // eax
  hkpConstraintSchemaInfo *m_data; // rdx
  hkpConstraintInstance *v11; // r8
  hkpJacobianSchema *v12; // r9
  __int64 v13; // r10

  v5 = constraintStatus->m_size - numOfConstraintsToCheckAtTheEndOfTheList;
  if ( v5 < constraintStatus->m_size )
  {
    v6 = v5;
    do
    {
      m_internal = constraintStatus->m_data[v6].m_constraint->m_internal;
      if ( (unsigned __int8)(m_internal->m_entities[0]->m_motion.m_type.m_storage - 4) <= 1u
        || (unsigned __int8)(m_internal->m_entities[1]->m_motion.m_type.m_storage - 4) <= 1u )
      {
        v8 = *firstNonActiveConstraintStatus;
        v9 = v8 + 1;
        v8 *= 3i64;
        *firstNonActiveConstraintStatus = v9;
        m_data = constraintStatus->m_data;
        v11 = (hkpConstraintInstance *)*((_QWORD *)&constraintStatus->m_data->m_constraint + v8);
        v12 = (&constraintStatus->m_data->m_schema)[v8];
        v13 = *((_QWORD *)&constraintStatus->m_data->m_allowedPenetrationDepth + v8);
        *((_QWORD *)&m_data->m_constraint + v8) = constraintStatus->m_data[v6].m_constraint;
        (&m_data->m_schema)[v8] = m_data[v6].m_schema;
        *((_QWORD *)&m_data->m_allowedPenetrationDepth + v8) = *(_QWORD *)&m_data[v6].m_allowedPenetrationDepth;
        m_data[v6].m_constraint = v11;
        m_data[v6].m_schema = v12;
        *(_QWORD *)&m_data[v6].m_allowedPenetrationDepth = v13;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < constraintStatus->m_size );
  }
}

// File Line: 2378
// RVA: 0xD71570
void __fastcall hkLs_toiActivateConstraintsLinkingActivatedEntities(
        hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus,
        int *firstNonActiveConstraintStatus,
        hkFixedArray<unsigned char> *entityState)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 v7; // r11
  hkConstraintInternal *m_internal; // rax
  __int64 v9; // rcx
  int v10; // eax
  hkpConstraintSchemaInfo *m_data; // rdx
  hkpConstraintInstance *v12; // r8
  hkpJacobianSchema *v13; // r9
  __int64 v14; // r10

  v3 = *firstNonActiveConstraintStatus;
  if ( (int)v3 < constraintStatus->m_size )
  {
    v7 = v3;
    do
    {
      m_internal = constraintStatus->m_data[v7].m_constraint->m_internal;
      if ( entityState->m_data.m_storage[m_internal->m_entities[0]->m_storageIndex] == 16
        && entityState->m_data.m_storage[m_internal->m_entities[1]->m_storageIndex] == 16 )
      {
        v9 = *firstNonActiveConstraintStatus;
        v10 = v9 + 1;
        v9 *= 3i64;
        *firstNonActiveConstraintStatus = v10;
        m_data = constraintStatus->m_data;
        v12 = (hkpConstraintInstance *)*((_QWORD *)&constraintStatus->m_data->m_constraint + v9);
        v13 = (&constraintStatus->m_data->m_schema)[v9];
        v14 = *((_QWORD *)&constraintStatus->m_data->m_allowedPenetrationDepth + v9);
        *((_QWORD *)&m_data->m_constraint + v9) = constraintStatus->m_data[v7].m_constraint;
        (&m_data->m_schema)[v9] = m_data[v7].m_schema;
        *((_QWORD *)&m_data->m_allowedPenetrationDepth + v9) = *(_QWORD *)&m_data[v7].m_allowedPenetrationDepth;
        m_data[v7].m_constraint = v12;
        m_data[v7].m_schema = v13;
        *(_QWORD *)&m_data[v7].m_allowedPenetrationDepth = v14;
      }
      LODWORD(v3) = v3 + 1;
      ++v7;
    }
    while ( (int)v3 < constraintStatus->m_size );
  }
}

// File Line: 2393
// RVA: 0xD71650
void __fastcall hkLs_toiResetVelocityAccumulatorsForEntities(
        hkpConstraintSolverResources *solverResources,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities)
{
  int v2; // r9d
  __int64 v5; // r11
  hkpEntity *v6; // rcx
  char *v7; // r8
  __m128 m_quad; // xmm1
  hkpConstraintSolverResources::VelocityAccumTransformBackup *v9; // rdx

  v2 = 0;
  if ( entities->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v2;
      v6 = entities->m_data[v5++];
      v7 = &solverResources->m_accumulators->m_type.m_storage + v6->m_solverData;
      *((_OWORD *)v7 + 1) = v6->m_motion.m_linearVelocity;
      m_quad = v6->m_motion.m_angularVelocity.m_quad;
      v9 = &solverResources->m_accumulatorsBackup[(unsigned __int64)v6->m_solverData >> 7];
      *((__m128 *)v7 + 2) = _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v9->m_coreTworldRotation.m_col1.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v9->m_coreTworldRotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v9->m_coreTworldRotation.m_col2.m_quad));
    }
    while ( v2 < entities->m_size );
  }
}

// File Line: 2419
// RVA: 0xD718B0
void __fastcall hkLs_backstepAndFreezeEntireIsland(
        float time,
        hkpSimulationIsland *island,
        hkFixedArray<unsigned char> *entityState,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *activeEntities)
{
  int v4; // r15d
  __int64 i; // rsi
  hkpEntity *v10; // r14
  hkQuaternionf v11; // xmm1

  v4 = 0;
  for ( i = 0i64;
        v4 < island->m_entities.m_size;
        v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[3] = 1.0
                                                                                        / (float)(hkpWorld::getCurrentPsiTime(island->m_world)
                                                                                                - time) )
  {
    v10 = island->m_entities.m_data[i];
    hkSweptTransformUtil::backStepMotionState(time, &v10->m_motion.m_motionState);
    if ( entityState->m_data.m_storage[i] != 16 )
    {
      if ( activeEntities->m_size == (activeEntities->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&activeEntities->m_data, 8);
      activeEntities->m_data[activeEntities->m_size++] = v10;
      entityState->m_data.m_storage[i] = 16;
    }
    v11.m_vec.m_quad = (__m128)v10->m_motion.m_motionState.m_sweptTransform.m_rotation1;
    v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0 = v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
    v10->m_motion.m_motionState.m_sweptTransform.m_rotation0 = (hkQuaternionf)v11.m_vec.m_quad;
    v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3] = time;
    ++v4;
    ++i;
  }
}

// File Line: 2452
// RVA: 0xD71C00
void __fastcall hkLs_restoreTransformOnBodiesWithUpdatedTransform(
        hkpSimulationIsland *island,
        hkFixedArray<unsigned char> *entityState,
        hkpConstraintSolverResources *solverResources)
{
  int v3; // ebp
  __int64 i; // rsi
  int v8; // ebx
  hkMotionState *p_m_motionState; // rdi
  __m128 m_quad; // xmm1
  hkpEntity *v11; // r8
  unsigned __int64 m_solverData; // rcx
  hkpVelocityAccumulator *m_accumulators; // rax
  hkpConstraintSolverResources::VelocityAccumTransformBackup *v14; // rdx
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm1

  v3 = 0;
  for ( i = 0i64; v3 < island->m_entities.m_size; ++i )
  {
    v8 = (unsigned __int8)entityState->m_data.m_storage[i];
    if ( (unsigned int)(v8 - 1) <= 1 )
    {
      p_m_motionState = &island->m_entities.m_data[i]->m_motion.m_motionState;
      hkRotationf::set(
        &p_m_motionState->m_transform.m_rotation,
        &island->m_entities.m_data[i]->m_motion.m_motionState.m_sweptTransform.m_rotation1);
      m_quad = p_m_motionState->m_sweptTransform.m_centerOfMassLocal.m_quad;
      p_m_motionState->m_transform.m_translation.m_quad = _mm_sub_ps(
                                                            p_m_motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps(m_quad, m_quad, 85),
                                                                  p_m_motionState->m_transform.m_rotation.m_col1.m_quad),
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps(m_quad, m_quad, 0),
                                                                  p_m_motionState->m_transform.m_rotation.m_col0.m_quad)),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps(m_quad, m_quad, 170),
                                                                p_m_motionState->m_transform.m_rotation.m_col2.m_quad)));
    }
    if ( v8 == 8 || v8 == 2 )
    {
      v11 = island->m_entities.m_data[i];
      m_solverData = v11->m_solverData;
      m_accumulators = solverResources->m_accumulators;
      v14 = &solverResources->m_accumulatorsBackup[m_solverData >> 7];
      v11->m_motion.m_linearVelocity = *(hkVector4f *)((char *)&m_accumulators->m_linearVel + m_solverData);
      v15 = v14->m_coreTworldRotation.m_col2.m_quad;
      v16 = _mm_unpacklo_ps(v14->m_coreTworldRotation.m_col0.m_quad, v14->m_coreTworldRotation.m_col1.m_quad);
      v17 = _mm_movelh_ps(v16, v15);
      v18 = _mm_movehl_ps(v17, v16);
      v19 = *(__m128 *)((char *)&m_accumulators->m_angularVel.m_quad + m_solverData);
      v11->m_motion.m_angularVelocity.m_quad = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v19, v19, 85),
                                                     _mm_shuffle_ps(v18, v15, 212)),
                                                   _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v17)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_unpackhi_ps(
                                                       v14->m_coreTworldRotation.m_col0.m_quad,
                                                       v14->m_coreTworldRotation.m_col1.m_quad),
                                                     v15,
                                                     228),
                                                   _mm_shuffle_ps(v19, v19, 170)));
    }
    ++v3;
  }
}

// File Line: 2485
// RVA: 0xD716F0
hkBool *__fastcall hkLs_toiCheckFinalValidityOfCriticalConstraints(
        hkBool *result,
        hkpConstraintSolverResources *solverResources,
        hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus,
        hkpProcessCollisionInput *processInput,
        hkArray<hkpToiResourceMgr::ConstraintViolationInfo,hkContainerHeapAllocator> *violatedConstraints)
{
  hkBool *v5; // rsi
  hkpConstraintSolverResources *v7; // r14
  char v8; // bl
  int v9; // ebp
  __int64 v10; // r12
  hkpConstraintSchemaInfo *v11; // r15
  int ToiViolatingConstraintVelocity; // eax
  __int64 m_size; // rcx
  hkpToiResourceMgr::ConstraintViolationInfo *m_data; // r14
  __int64 v15; // rsi
  hkpConstraintData *v16; // rdx
  __int64 v17; // rcx
  float velocities[274]; // [rsp+30h] [rbp-448h] BYREF
  int v22; // [rsp+490h] [rbp+18h]

  v5 = result;
  v7 = solverResources;
  v8 = 1;
  v9 = 0;
  if ( constraintStatus->m_size > 0 )
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = &constraintStatus->m_data[v10];
      if ( v11->m_constraint->m_priority.m_storage == 5 )
      {
        ToiViolatingConstraintVelocity = hkSolveGetToiViolatingConstraintVelocity(
                                           v7->m_solverInfo,
                                           v11->m_schema,
                                           v7->m_accumulators,
                                           256,
                                           velocities);
        v22 = hkLs_areVelocitiesOk(
                v7->m_stepInfo->m_deltaTime.m_storage,
                v11,
                velocities,
                ToiViolatingConstraintVelocity,
                processInput);
        if ( v22 >= 0 )
        {
          if ( !violatedConstraints )
          {
            v5 = result;
            result->m_bool = 0;
            return v5;
          }
          v8 = 0;
          if ( violatedConstraints->m_size == (violatedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&violatedConstraints->m_data,
              24);
          m_size = violatedConstraints->m_size;
          m_data = violatedConstraints->m_data;
          v15 = m_size;
          violatedConstraints->m_size = m_size + 1;
          m_data[m_size].m_constraint = v11->m_constraint;
          if ( ((unsigned int (__fastcall *)(hkpConstraintData *))v11->m_constraint->m_data->vfptr[1].__first_virtual_table_function__)(v11->m_constraint->m_data) == 11 )
          {
            v16 = v11->m_constraint->m_data;
            m_data[v15].m_contactPoint = (hkContactPoint *)(v16[2].m_userData + 32i64 * v22 + 48);
            v17 = v16[2].m_userData
                + *(unsigned __int8 *)(v16[2].m_userData + 10) * (__int16)v22
                + 48i64
                + 32i64 * *(unsigned __int16 *)(v16[2].m_userData + 6);
          }
          else
          {
            v17 = 0i64;
            m_data[v15].m_contactPoint = 0i64;
          }
          m_data[v15].m_contactPointProperties = (hkpContactPointProperties *)v17;
          v7 = solverResources;
        }
      }
      ++v9;
      ++v10;
      if ( v9 >= constraintStatus->m_size )
      {
        v5 = result;
        break;
      }
    }
  }
  v5->m_bool = v8;
  return v5;
}

// File Line: 2553
// RVA: 0xD6FDF0
hkResult *__fastcall hkLs_localizedSolveToi(
        hkResult *result,
        hkpToiResources *toiResources,
        hkpConstraintSolverResources *solverResources,
        hkpToiEvent *event,
        hkpToiResourceMgr *toiResourceMgr,
        hkpWorld *world,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *activeEntities,
        hkFixedArray<unsigned char> *entityState,
        float rotateNormal)
{
  int v9; // edi
  hkpEntity *v10; // rax
  bool v11; // zf
  hkpConstraintSolverResources *v13; // r15
  hkResult *v14; // rsi
  int m_size; // ebx
  int v16; // eax
  hkLifoAllocator *Value; // rax
  hkpEntity **m_cur; // rcx
  int v19; // edx
  hkpEntity *v20; // rdx
  hkFixedArray<unsigned char> *v21; // r14
  hkpEntity *v22; // r8
  float m_time; // xmm1_4
  hkpEntity *v24; // rdx
  hkpEntity *v25; // r8
  float v26; // xmm1_4
  hkpDynamicsContactMgr *m_contactMgr; // rcx
  hkpEntity *v28; // rbx
  hkMotionState *p_m_motionState; // rbx
  __m128 m_quad; // xmm1
  hkpEntity *v31; // rbx
  hkMotionState *v32; // rbx
  __m128 v33; // xmm1
  int m_capacityAndFlags; // r8d
  int v35; // eax
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v39; // rsi
  hkpWorld *v40; // r13
  char v41; // bl
  hkpToiResources *v42; // rax
  int m_numToiSolverIterations; // ecx
  int v44; // edi
  hkpConstraintInstance::ConstraintPriority minPriorityToProcess; // eax
  hkpProcessCollisionInput *v46; // rdx
  __int64 v47; // r8
  __int64 m_storageIndex; // rdx
  int v49; // r9d
  int v50; // edx
  hkpEntity **m_data; // r10
  __int64 v52; // r8
  int v53; // edx
  int v54; // ecx
  int v55; // r9d
  int v56; // r9d
  __int64 v57; // r8
  hkpEntity *v58; // rax
  int v59; // r9d
  __int64 v60; // r9
  __int64 v61; // rbx
  int m_numForcedToiFinalSolverIterations; // ebx
  hkpProcessCollisionInput *m_collisionInput; // r9
  __int64 v64; // rbx
  int v65; // eax
  bool v66; // cc
  __int64 v67; // rbx
  int v68; // edi
  __int64 v69; // rbx
  int v70; // eax
  char *v71; // rdi
  signed int v72; // ebx
  hkLifoAllocator *v73; // rax
  int v74; // r8d
  hkArray<hkpEntity *,hkContainerHeapAllocator> entities; // [rsp+40h] [rbp-C0h] BYREF
  void *p; // [rsp+50h] [rbp-B0h]
  int v78; // [rsp+58h] [rbp-A8h]
  int v79; // [rsp+60h] [rbp-A0h] BYREF
  hkBool v80; // [rsp+64h] [rbp-9Ch] BYREF
  int v81; // [rsp+68h] [rbp-98h]
  int firstNonActiveConstraintStatus; // [rsp+6Ch] [rbp-94h] BYREF
  hkpSimulationIsland *island; // [rsp+70h] [rbp-90h]
  hkResult v84; // [rsp+78h] [rbp-88h] BYREF
  hkClass *v85; // [rsp+80h] [rbp-80h]
  hkClass *t; // [rsp+88h] [rbp-78h] BYREF
  hkClass *v87; // [rsp+90h] [rbp-70h] BYREF
  hkArray<hkpEntity *,hkContainerHeapAllocator> toBeActivated; // [rsp+A0h] [rbp-60h] BYREF
  char v89; // [rsp+B0h] [rbp-50h] BYREF
  hkArray<hkpEntity *,hkContainerHeapAllocator> newTouchedEntities; // [rsp+2B0h] [rbp+1B0h] BYREF
  char v91; // [rsp+2C0h] [rbp+1C0h] BYREF
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> newTouchedConstraints; // [rsp+4C0h] [rbp+3C0h] BYREF
  char v93; // [rsp+4D0h] [rbp+3D0h] BYREF
  hkArray<hkpToiResourceMgr::ConstraintViolationInfo,hkContainerHeapAllocator> violatedConstraints; // [rsp+6D0h] [rbp+5D0h] BYREF
  char v95; // [rsp+6E0h] [rbp+5E0h] BYREF
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> constraintStatus; // [rsp+9E0h] [rbp+8E0h] BYREF
  char v97; // [rsp+9F0h] [rbp+8F0h] BYREF
  hkBool resulta; // [rsp+1048h] [rbp+F48h] BYREF

  v9 = 0;
  constraintStatus.m_capacityAndFlags = -2147483584;
  constraintStatus.m_data = (hkpConstraintSchemaInfo *)&v97;
  v10 = event->m_entities[0];
  constraintStatus.m_size = 0;
  v11 = v10->m_motion.m_type.m_storage == 5;
  v13 = solverResources;
  v14 = result;
  v79 = 0;
  if ( v11 )
    v10 = event->m_entities[1];
  island = v10->m_simulationIsland;
  m_size = island->m_entities.m_size;
  v16 = 0;
  entities.m_data = 0i64;
  entities.m_size = 0;
  entities.m_capacityAndFlags = 0x80000000;
  v78 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpEntity **)Value->m_cur;
    v19 = (8 * m_size + 127) & 0xFFFFFF80;
    solverResources = (hkpConstraintSolverResources *)((char *)m_cur + v19);
    if ( v19 > Value->m_slabSize || solverResources > Value->m_end )
    {
      m_cur = (hkpEntity **)hkLifoAllocator::allocateFromNewSlab(Value, v19);
      v16 = entities.m_size;
    }
    else
    {
      Value->m_cur = solverResources;
      v16 = entities.m_size;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  v20 = event->m_entities[0];
  v21 = entityState;
  entities.m_data = m_cur;
  entities.m_capacityAndFlags = m_size | 0x80000000;
  p = m_cur;
  if ( v20->m_motion.m_type.m_storage != 5 )
  {
    m_cur[v16] = v20;
    v22 = event->m_entities[0];
    m_time = event->m_time;
    ++entities.m_size;
    hkSweptTransformUtil::lerp2(
      &v22->m_motion.m_motionState.m_sweptTransform,
      m_time,
      &v22->m_motion.m_motionState.m_transform);
    v21->m_data.m_storage[event->m_entities[0]->m_storageIndex] = 2;
    v16 = entities.m_size;
    m_cur = entities.m_data;
  }
  v24 = event->m_entities[1];
  if ( v24->m_motion.m_type.m_storage != 5 )
  {
    m_cur[v16] = v24;
    v25 = event->m_entities[1];
    v26 = event->m_time;
    ++entities.m_size;
    hkSweptTransformUtil::lerp2(
      &v25->m_motion.m_motionState.m_sweptTransform,
      v26,
      &v25->m_motion.m_motionState.m_transform);
    v21->m_data.m_storage[event->m_entities[1]->m_storageIndex] = 2;
  }
  m_contactMgr = event->m_contactMgr;
  toBeActivated.m_size = 0;
  toBeActivated.m_capacityAndFlags = -2147483584;
  toBeActivated.m_data = (hkpEntity **)&v89;
  ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpToiEvent *, hkpConstraintSolverResources *, hkArray<hkpEntity *,hkContainerHeapAllocator> *))m_contactMgr->vfptr[9].__vecDelDtor)(
    m_contactMgr,
    event,
    solverResources,
    &toBeActivated);
  if ( !toBeActivated.m_size )
  {
    v28 = event->m_entities[0];
    if ( v28->m_motion.m_type.m_storage != 5 )
    {
      p_m_motionState = &v28->m_motion.m_motionState;
      hkRotationf::set(&p_m_motionState->m_transform.m_rotation, &p_m_motionState->m_sweptTransform.m_rotation1);
      m_quad = p_m_motionState->m_sweptTransform.m_centerOfMassLocal.m_quad;
      p_m_motionState->m_transform.m_translation.m_quad = _mm_sub_ps(
                                                            p_m_motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps(m_quad, m_quad, 85),
                                                                  p_m_motionState->m_transform.m_rotation.m_col1.m_quad),
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps(m_quad, m_quad, 0),
                                                                  p_m_motionState->m_transform.m_rotation.m_col0.m_quad)),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps(m_quad, m_quad, 170),
                                                                p_m_motionState->m_transform.m_rotation.m_col2.m_quad)));
    }
    v31 = event->m_entities[1];
    if ( v31->m_motion.m_type.m_storage != 5 )
    {
      v32 = &v31->m_motion.m_motionState;
      hkRotationf::set(&v32->m_transform.m_rotation, &v32->m_sweptTransform.m_rotation1);
      v33 = v32->m_sweptTransform.m_centerOfMassLocal.m_quad;
      v32->m_transform.m_translation.m_quad = _mm_sub_ps(
                                                v32->m_sweptTransform.m_centerOfMass1.m_quad,
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(v33, v33, 85),
                                                      v32->m_transform.m_rotation.m_col1.m_quad),
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(v33, v33, 0),
                                                      v32->m_transform.m_rotation.m_col0.m_quad)),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(v33, v33, 170),
                                                    v32->m_transform.m_rotation.m_col2.m_quad)));
    }
    m_capacityAndFlags = toBeActivated.m_capacityAndFlags;
    v14->m_enum = HK_FAILURE;
    toBeActivated.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        toBeActivated.m_data,
        8 * m_capacityAndFlags);
    v35 = entities.m_size;
    toBeActivated.m_data = 0i64;
    toBeActivated.m_capacityAndFlags = 0x80000000;
    if ( p == entities.m_data )
      v35 = 0;
    entities.m_size = v35;
    v36 = (8 * v78 + 127) & 0xFFFFFF80;
    v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v38 = (v36 + 15) & 0xFFFFFFF0;
    if ( v36 > v37->m_slabSize || (char *)p + v38 != v37->m_cur || v37->m_firstNonLifoEnd == p )
      hkLifoAllocator::slowBlockFree(v37, (char *)p, v38);
    else
      v37->m_cur = p;
    entities.m_size = 0;
    if ( entities.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        entities.m_data,
        8 * entities.m_capacityAndFlags);
    entities.m_data = 0i64;
    entities.m_capacityAndFlags = 0x80000000;
    constraintStatus.m_size = 0;
    if ( constraintStatus.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        constraintStatus.m_data,
        24 * (constraintStatus.m_capacityAndFlags & 0x3FFFFFFF));
    return v14;
  }
  t = (hkClass *)*toBeActivated.m_data;
  if ( toBeActivated.m_size <= 1 )
  {
    v85 = 0i64;
    v87 = 0i64;
  }
  else
  {
    v85 = (hkClass *)*((_QWORD *)toBeActivated.m_data + 1);
    v87 = v85;
    v9 = 0;
  }
  hkpConstraintSolverSetup::internalAddAccumulators(v13, entities.m_data, entities.m_size);
  v39 = activeEntities;
  v40 = world;
  v41 = 1;
  newTouchedEntities.m_size = 0;
  newTouchedEntities.m_data = (hkpEntity **)&v91;
  newTouchedEntities.m_capacityAndFlags = -2147483584;
  newTouchedConstraints.m_data = (hkpConstraintInstance **)&v93;
  v42 = toiResources;
  newTouchedConstraints.m_size = 0;
  m_numToiSolverIterations = toiResources->m_numToiSolverIterations;
  newTouchedConstraints.m_capacityAndFlags = -2147483584;
  v81 = m_numToiSolverIterations;
  if ( m_numToiSolverIterations <= 0 )
  {
LABEL_79:
    if ( v13->m_schemas[2].m_begin != v13->m_schemas[2].m_current )
    {
      hkLs_toiResetVelocityAccumulatorsForEntities(v13, &entities);
      hkLs_toiCheckFinalValidityOfCriticalConstraints(&resulta, v13, &constraintStatus, v40->m_collisionInput, 0i64);
      if ( !resulta.m_bool )
      {
        m_numForcedToiFinalSolverIterations = toiResources->m_numForcedToiFinalSolverIterations;
        while ( --m_numForcedToiFinalSolverIterations >= 0 )
        {
          hkSolveStepJacobians(v13->m_solverInfo, v13->m_schemas[2].m_begin, v13->m_accumulators, v13->m_elemTemp);
          hkLs_toiResetVelocityAccumulatorsForEntities(v13, &entities);
          if ( hkLs_toiCheckFinalValidityOfCriticalConstraints(
                 &resulta,
                 v13,
                 &constraintStatus,
                 v40->m_collisionInput,
                 0i64)->m_bool )
            goto LABEL_94;
        }
        m_collisionInput = v40->m_collisionInput;
        violatedConstraints.m_data = (hkpToiResourceMgr::ConstraintViolationInfo *)&v95;
        violatedConstraints.m_size = 0;
        violatedConstraints.m_capacityAndFlags = -2147483616;
        hkLs_toiCheckFinalValidityOfCriticalConstraints(
          &resulta,
          v13,
          &constraintStatus,
          m_collisionInput,
          &violatedConstraints);
        if ( toiResourceMgr->vfptr[2].__vecDelDtor(toiResourceMgr, &violatedConstraints) == (void *)2 )
        {
          hkLs_backstepAndFreezeEntireIsland(event->m_time, island, v21, v39);
          if ( v39->m_size > 0 )
          {
            v64 = 0i64;
            do
            {
              hkpWorldAgentUtil::invalidateTim(v39->m_data[v64], v40->m_collisionInput);
              ++v9;
              ++v64;
            }
            while ( v9 < v39->m_size );
          }
          v65 = violatedConstraints.m_capacityAndFlags;
          v39->m_size = 0;
          v14 = result;
          violatedConstraints.m_size = 0;
          result->m_enum = HK_SUCCESS;
          if ( v65 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              violatedConstraints.m_data,
              24 * (v65 & 0x3FFFFFFF));
          violatedConstraints.m_data = 0i64;
          violatedConstraints.m_capacityAndFlags = 0x80000000;
          goto LABEL_105;
        }
        violatedConstraints.m_size = 0;
        if ( violatedConstraints.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            violatedConstraints.m_data,
            24 * (violatedConstraints.m_capacityAndFlags & 0x3FFFFFFF));
      }
    }
LABEL_94:
    v66 = v39->m_size <= 0;
    if ( !v39->m_size )
    {
      hkArrayBase<hkClass *>::_insertAt((hkArrayBase<hkClass *> *)v39, &hkContainerHeapAllocator::s_alloc, 0, &t);
      v11 = v85 == 0i64;
      v21->m_data.m_storage[(*v39->m_data)->m_storageIndex] = 16;
      if ( !v11 )
      {
        hkArrayBase<hkClass *>::_insertAt((hkArrayBase<hkClass *> *)v39, &hkContainerHeapAllocator::s_alloc, 1, &v87);
        v21->m_data.m_storage[*(unsigned __int16 *)(*((_QWORD *)v39->m_data + 1) + 244i64)] = 16;
      }
      v66 = v39->m_size <= 0;
    }
    if ( !v66 )
    {
      v67 = 0i64;
      do
      {
        hkSweptTransformUtil::backStepMotionState(event->m_time, &v39->m_data[v67]->m_motion.m_motionState);
        ++v9;
        ++v67;
      }
      while ( v9 < v39->m_size );
    }
    hkpConstraintSolverSetup::oneStepIntegrate(
      v13->m_solverInfo,
      v13->m_stepInfo,
      v13->m_accumulators,
      v39->m_data,
      v39->m_size);
    hkLs_restoreTransformOnBodiesWithUpdatedTransform(island, v21, v13);
    v68 = 0;
    if ( v39->m_size > 0 )
    {
      v69 = 0i64;
      do
      {
        hkpWorldAgentUtil::invalidateTim(v39->m_data[v69], v40->m_collisionInput);
        ++v68;
        ++v69;
      }
      while ( v68 < v39->m_size );
    }
    goto LABEL_104;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      newTouchedConstraints.m_size = 0;
      newTouchedEntities.m_size = 0;
      v44 = v79;
      firstNonActiveConstraintStatus = v79;
      if ( v41 )
        break;
      if ( v79 >= constraintStatus.m_size )
      {
        v9 = 0;
        goto $RUN_FULL_SOLVER;
      }
      minPriorityToProcess = v42->m_minPriorityToProcess;
      v46 = v40->m_collisionInput;
      v9 = 0;
      toBeActivated.m_size = 0;
      hkLs_toiCheckValidityOfConstraints(
        v13,
        v46,
        &constraintStatus,
        &firstNonActiveConstraintStatus,
        minPriorityToProcess,
        v21,
        &entities,
        &toBeActivated);
      if ( toBeActivated.m_size )
      {
        v44 = firstNonActiveConstraintStatus;
        v42 = toiResources;
        break;
      }
$RUN_FULL_SOLVER:
      hkpConstraintSolverSetup::subSolve(v13, SOLVER_MODE_PROCESS_ALL);
      v42 = toiResources;
      if ( --v81 <= 0 )
        goto LABEL_79;
    }
    hkLs_toiActivateEntitiesAndCheckConstraints(
      v40->m_collisionInput,
      v42->m_minPriorityToProcess,
      event->m_time,
      &toBeActivated,
      v21,
      &newTouchedEntities,
      &newTouchedConstraints);
    v41 = 0;
    if ( !hkpConstraintSolverSetup::internalIsMemoryOkForNewAccumulators(
            &resulta,
            v13,
            newTouchedEntities.m_data,
            newTouchedEntities.m_size)->m_bool
      || !hkpConstraintSolverSetup::internalIsMemoryOkForNewJacobianSchemas(
            &v80,
            v13,
            newTouchedConstraints.m_data,
            newTouchedConstraints.m_size)->m_bool
      || toiResources->m_maxNumConstraints < newTouchedConstraints.m_size + constraintStatus.m_size )
    {
      break;
    }
    m_storageIndex = (unsigned int)newTouchedEntities.m_size;
    v47 = (unsigned int)v39->m_size;
    if ( toiResources->m_maxNumEntities < (int)v47 + newTouchedEntities.m_size + entities.m_size
      || toiResources->m_maxNumActiveEntities < (int)v47 + toBeActivated.m_size )
    {
      goto LABEL_65;
    }
    hkpConstraintSolverSetup::internalAddAccumulators(v13, newTouchedEntities.m_data, newTouchedEntities.m_size);
    hkpConstraintSolverSetup::internalAddJacobianSchemas(
      v13,
      newTouchedConstraints.m_data,
      newTouchedConstraints.m_size,
      &constraintStatus);
    v49 = entities.m_size;
    v79 = v44;
    v9 = 0;
    v50 = 0;
    if ( entities.m_size > 0 )
    {
      m_data = entities.m_data;
      v52 = 0i64;
      do
      {
        if ( v21->m_data.m_storage[m_data[v52]->m_storageIndex] == 16 )
        {
          entities.m_size = --v49;
          if ( v49 != v50 )
          {
            m_data[v52] = m_data[v49];
            v49 = entities.m_size;
            m_data = entities.m_data;
          }
          --v50;
          --v52;
        }
        ++v50;
        ++v52;
      }
      while ( v50 < v49 );
    }
    hkArrayBase<hkpEntity *>::_insertAt(
      (hkArrayBase<hkProcess *> *)v39,
      &hkContainerHeapAllocator::s_alloc,
      v39->m_size,
      (hkProcess *const *)toBeActivated.m_data,
      toBeActivated.m_size);
    v53 = newTouchedEntities.m_size;
    v54 = entities.m_size;
    v55 = newTouchedEntities.m_size + entities.m_size;
    if ( (entities.m_capacityAndFlags & 0x3FFFFFFF) >= newTouchedEntities.m_size + entities.m_size )
    {
      v84.m_enum = HK_SUCCESS;
    }
    else
    {
      if ( v55 < 2 * (entities.m_capacityAndFlags & 0x3FFFFFFF) )
        v55 = 2 * (entities.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v84, &hkContainerHeapAllocator::s_alloc, (const void **)&entities.m_data, v55, 8);
      v54 = entities.m_size;
      v53 = newTouchedEntities.m_size;
    }
    v56 = 0;
    if ( v53 > 0 )
    {
      v57 = 0i64;
      do
      {
        v58 = newTouchedEntities.m_data[v57];
        if ( v58->m_motion.m_type.m_storage != 4 )
        {
          entities.m_data[v54] = v58;
          v53 = newTouchedEntities.m_size;
          v54 = ++entities.m_size;
        }
        ++v56;
        ++v57;
      }
      while ( v56 < v53 );
    }
    hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities(&constraintStatus, &v79, newTouchedConstraints.m_size);
    hkLs_toiActivateConstraintsLinkingActivatedEntities(&constraintStatus, &v79, v21);
    hkpConstraintSolverSetup::subSolve(v13, SOLVER_MODE_INCREMENTAL_CONTINUE);
    v42 = toiResources;
    if ( !newTouchedConstraints.m_size && !newTouchedEntities.m_size )
      goto $RUN_FULL_SOLVER;
  }
  m_storageIndex = (unsigned int)newTouchedEntities.m_size;
LABEL_65:
  v9 = 0;
  v59 = 0;
  if ( toBeActivated.m_size > 0 )
  {
    v47 = 0i64;
    do
    {
      ++v59;
      v47 += 8i64;
      v21->m_data.m_storage[(*(hkpEntity **)((char *)toBeActivated.m_data + v47 - 8))->m_storageIndex] = 8;
    }
    while ( v59 < toBeActivated.m_size );
    m_storageIndex = (unsigned int)newTouchedEntities.m_size;
  }
  v60 = 0i64;
  if ( (int)m_storageIndex > 0 )
  {
    v47 = 0i64;
    do
    {
      v60 = (unsigned int)(v60 + 1);
      v47 += 8i64;
      m_storageIndex = (*(hkpEntity **)((char *)newTouchedEntities.m_data + v47 - 8))->m_storageIndex;
      v21->m_data.m_storage[m_storageIndex] = 1;
    }
    while ( (int)v60 < newTouchedEntities.m_size );
  }
  if ( ((unsigned int (__fastcall *)(hkpToiResourceMgr *, __int64, __int64, __int64))toiResourceMgr->vfptr[2].__first_virtual_table_function__)(
         toiResourceMgr,
         m_storageIndex,
         v47,
         v60) != 2 )
    goto $RUN_FULL_SOLVER;
  hkLs_backstepAndFreezeEntireIsland(event->m_time, island, v21, v39);
  if ( v39->m_size > 0 )
  {
    v61 = 0i64;
    do
    {
      hkpWorldAgentUtil::invalidateTim(v39->m_data[v61], v40->m_collisionInput);
      ++v9;
      ++v61;
    }
    while ( v9 < v39->m_size );
  }
  v39->m_size = 0;
LABEL_104:
  v14 = result;
  result->m_enum = HK_SUCCESS;
LABEL_105:
  newTouchedConstraints.m_size = 0;
  if ( newTouchedConstraints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newTouchedConstraints.m_data,
      8 * newTouchedConstraints.m_capacityAndFlags);
  newTouchedConstraints.m_data = 0i64;
  newTouchedConstraints.m_capacityAndFlags = 0x80000000;
  newTouchedEntities.m_size = 0;
  if ( newTouchedEntities.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newTouchedEntities.m_data,
      8 * newTouchedEntities.m_capacityAndFlags);
  newTouchedEntities.m_data = 0i64;
  newTouchedEntities.m_capacityAndFlags = 0x80000000;
  toBeActivated.m_size = 0;
  if ( toBeActivated.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      toBeActivated.m_data,
      8 * toBeActivated.m_capacityAndFlags);
  v70 = entities.m_size;
  v71 = (char *)p;
  toBeActivated.m_data = 0i64;
  toBeActivated.m_capacityAndFlags = 0x80000000;
  if ( p == entities.m_data )
    v70 = 0;
  entities.m_size = v70;
  v72 = (8 * v78 + 127) & 0xFFFFFF80;
  v73 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v74 = (v72 + 15) & 0xFFFFFFF0;
  if ( v72 > v73->m_slabSize || &v71[v74] != v73->m_cur || v73->m_firstNonLifoEnd == v71 )
    hkLifoAllocator::slowBlockFree(v73, v71, v74);
  else
    v73->m_cur = v71;
  entities.m_size = 0;
  if ( entities.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      entities.m_data,
      8 * entities.m_capacityAndFlags);
  entities.m_data = 0i64;
  entities.m_capacityAndFlags = 0x80000000;
  constraintStatus.m_size = 0;
  if ( constraintStatus.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      constraintStatus.m_data,
      24 * (constraintStatus.m_capacityAndFlags & 0x3FFFFFFF));
  return v14;
}

