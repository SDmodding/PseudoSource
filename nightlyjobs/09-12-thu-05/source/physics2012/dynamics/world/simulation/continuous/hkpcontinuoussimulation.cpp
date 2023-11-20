// File Line: 167
// RVA: 0xD6C540
void __fastcall hkpContinuousSimulation::hkpContinuousSimulation(hkpContinuousSimulation *this, hkpWorld *world)
{
  hkpWorld *v2; // rsi
  hkpContinuousSimulation *v3; // rbx
  _QWORD **v4; // rax
  hkpDefaultToiResourceMgr *v5; // rax
  hkpToiResourceMgr *v6; // rax
  int v7; // er9
  int v8; // eax
  int v9; // eax
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = world;
  v3 = this;
  hkpSimulation::hkpSimulation((hkpSimulation *)&this->vfptr, world);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpContinuousSimulation::`vftable';
  v3->m_toiEvents.m_data = 0i64;
  v3->m_toiEvents.m_size = 0;
  v3->m_toiEvents.m_capacityAndFlags = 2147483648;
  v3->m_entitiesNeedingPsiCollisionDetection.m_map.m_elem = 0i64;
  v3->m_entitiesNeedingPsiCollisionDetection.m_map.m_numElems = 0;
  v3->m_entitiesNeedingPsiCollisionDetection.m_map.m_hashMod = -1;
  v3->m_lastProcessingStep.m_storage = 1;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpDefaultToiResourceMgr *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 24i64);
  if ( v5 )
    hkpDefaultToiResourceMgr::hkpDefaultToiResourceMgr(v5);
  else
    v6 = 0i64;
  v3->m_toiResourceMgr = v6;
  v3->m_toiCounter = 0;
  v7 = v2->m_sizeOfToiEventQueue;
  v8 = v3->m_toiEvents.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_toiEvents,
      v7,
      144);
  }
}

// File Line: 231
// RVA: 0xD6C620
void __fastcall hkpContinuousSimulation::~hkpContinuousSimulation(hkpContinuousSimulation *this)
{
  hkpContinuousSimulation *v1; // rdi
  hkpToiResourceMgr *v2; // rcx
  int v3; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpContinuousSimulation::`vftable';
  v2 = this->m_toiResourceMgr;
  if ( v2 )
    v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_entitiesNeedingPsiCollisionDetection.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_entitiesNeedingPsiCollisionDetection);
  v3 = v1->m_toiEvents.m_capacityAndFlags;
  v1->m_toiEvents.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_toiEvents.m_data,
      144 * (v3 & 0x3FFFFFFF));
  v1->m_toiEvents.m_data = 0i64;
  v1->m_toiEvents.m_capacityAndFlags = 2147483648;
  hkpSimulation::~hkpSimulation((hkpSimulation *)&v1->vfptr);
}

// File Line: 246
// RVA: 0xD6C6C0
void __fastcall hkpContinuousSimulation::create(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  _QWORD **v2; // rax
  hkpContinuousSimulation *v3; // rax

  v1 = world;
  hkOptionalComponent_hkpContinuousSimulation.m_isUsed.m_bool = 1;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpContinuousSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 112i64);
  if ( v3 )
    hkpContinuousSimulation::hkpContinuousSimulation(v3, v1);
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
  hkpContinuousSimulation *v2; // rdi
  unsigned int v3; // esi
  float v4; // xmm6_4
  hkpWorld *v5; // rax
  signed int v6; // er14
  signed __int64 v7; // rbx
  int v8; // er12
  float v9; // xmm1_4
  signed int v10; // edx
  signed __int64 v11; // r8
  hkpToiEvent *v12; // r13
  signed __int64 v13; // r9
  hkpToiEvent *v14; // rcx
  unsigned int v15; // er10
  unsigned int v16; // er11
  signed __int64 v17; // r8
  __int64 v18; // rcx
  __int64 v19; // rax
  hkpToiEvent *v20; // rcx
  signed __int64 v21; // rdx
  signed __int64 v22; // r8
  signed __int64 v23; // rcx
  signed __int64 v24; // r8
  __int64 v25; // rax
  hkpToiEvent *v26; // rax
  hkVector4f v27; // xmm0
  __int64 v28; // rax
  signed __int64 v29; // rdx
  signed __int64 v30; // rcx
  signed __int64 v31; // r8
  __int64 v32; // rax
  int v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  hkpWorld *v37; // rdx
  hkpWorld *v38; // rbx
  bool v39; // zf
  hkpWorld *v40; // rbx
  __int64 rotateNormal; // [rsp+20h] [rbp-81h]
  __int128 v43; // [rsp+28h] [rbp-79h]
  hkpToiEvent event; // [rsp+38h] [rbp-69h]
  float v45; // [rsp+108h] [rbp+67h]
  char v46; // [rsp+110h] [rbp+6Fh]
  hkpWorld *v47; // [rsp+118h] [rbp+77h]

  v2 = this;
  v3 = 0;
  v4 = minTime;
LABEL_2:
  v5 = v2->m_world;
  v6 = -1;
  v7 = -1i64;
  ++v5->m_criticalOperationsLockCount;
  v47 = v5;
  while ( 1 )
  {
    v8 = v2->m_toiEvents.m_size;
    v9 = v4;
    v10 = 0;
    v11 = 0i64;
    v45 = v2->m_world->m_toiCollisionResponseRotateNormal;
    if ( v8 <= 0 )
      break;
    v12 = v2->m_toiEvents.m_data;
    v13 = -144i64;
    v14 = v2->m_toiEvents.m_data;
    do
    {
      if ( v14->m_time < v9
        || v14->m_time == v9
        && v7 != -1
        && ((v15 = v14->m_entities[0]->m_uid, v16 = (*(hkpEntity **)((char *)v12->m_entities + v13))->m_uid, v15 < v16)
         || v15 == v16 && v14->m_entities[1]->m_uid < (*(hkpEntity **)((char *)&v12->m_entities[1] + v13))->m_uid) )
      {
        v9 = v14->m_time;
        v13 = (char *)v14 - (char *)v12;
        v7 = v11;
        v6 = v10;
      }
      ++v10;
      ++v11;
      ++v14;
    }
    while ( v10 < v8 );
    if ( v7 < 0 )
    {
      v3 = 0;
      break;
    }
    v17 = (signed __int64)&v12[v7];
    v18 = *(_QWORD *)(v17 + 32);
    *(_BYTE *)(v17 + 59) |= 1u;
    if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, signed __int64, float *, __int64, _QWORD))(*(_QWORD *)v18 + 136i64))(
                     v18,
                     &v46,
                     v17,
                     &v45,
                     rotateNormal,
                     v43) )
    {
      v26 = v2->m_toiEvents.m_data;
      *(_OWORD *)&event.m_useSimpleHandling.m_bool = *(_OWORD *)&v26[v7].m_time;
      *(_OWORD *)&event.m_entities[1] = *(_OWORD *)v26[v7].m_entities;
      v43 = *(_OWORD *)&v26[v7].m_contactMgr;
      *(hkContactPointMaterial *)&event.m_time = v26[v7].m_properties.8;
      *(_OWORD *)event.m_entities = *(_OWORD *)&v26[v7].m_properties.m_internalDataA;
      *(_OWORD *)&event.m_contactMgr = *(_OWORD *)&v26[v7].m_extendedUserDatas[2];
      event.m_properties.8 = *(hkContactPointMaterial *)&v26[v7].m_extendedUserDatas[6];
      *(hkVector4f *)&event.m_properties.m_internalDataA = v26[v7].m_contactPoint.m_position;
      v27.m_quad = (__m128)v26[v7].m_contactPoint.m_separatingNormal;
      v28 = --v2->m_toiEvents.m_size;
      *(hkVector4f *)&event.m_extendedUserDatas[2] = (hkVector4f)v27.m_quad;
      if ( (_DWORD)v28 != v6 )
      {
        v29 = (signed __int64)&v2->m_toiEvents.m_data[v7];
        v30 = 18i64;
        v31 = (signed __int64)&v2->m_toiEvents.m_data[v28] - v29;
        do
        {
          v32 = *(_QWORD *)(v31 + v29);
          v29 += 8i64;
          *(_QWORD *)(v29 - 8) = v32;
          --v30;
        }
        while ( v30 );
      }
      v33 = *(_DWORD *)&event.m_useSimpleHandling.m_bool;
      v34 = v2->m_currentPsiTime;
      *((float *)&v43 + 3) = v34;
      v35 = v34 - *(float *)&event.m_useSimpleHandling.m_bool;
      v2->m_currentTime = *(float *)&event.m_useSimpleHandling.m_bool;
      DWORD2(v43) = v33;
      event.m_time = v35;
      if ( v35 == 0.0 )
        v36 = 0.0;
      else
        v36 = 1.0 / v35;
      event.m_seperatingVelocity = v36;
      _mm_store_si128((__m128i *)&v2->m_world->m_dynamicsStepInfo, *(__m128i *)((char *)&v43 + 8));
      _mm_store_si128((__m128i *)&v2->m_world->m_collisionInput->m_stepInfo, *(__m128i *)((char *)&v43 + 8));
      v37 = v2->m_world;
      *(float *)&rotateNormal = v45;
      if ( LOBYTE(event.m_entities[0]) )
        hkpContinuousSimulation::handleSimpleToi(
          v2,
          v37,
          (hkpToiEvent *)((char *)&event + 8),
          v2->m_physicsDeltaTime,
          v45);
      else
        ((void (__fastcall *)(hkpContinuousSimulation *, hkpWorld *, hkBool *))v2->vfptr[10].__first_virtual_table_function__)(
          v2,
          v37,
          &event.m_useSimpleHandling);
      ++v2->m_toiCounter;
      if ( hkOutOfMemoryState == 1 )
      {
        v3 = 3;
        break;
      }
      v38 = v47;
      v3 = 0;
      v39 = v47->m_criticalOperationsLockCount == 1;
      --v38->m_criticalOperationsLockCount;
      if ( v39 && !v38->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v38->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v38);
        if ( v38->m_pendingOperationQueueCount == 1 && v38->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v38);
      }
      goto LABEL_2;
    }
    v19 = --v2->m_toiEvents.m_size;
    if ( (_DWORD)v19 != v6 )
    {
      v20 = v2->m_toiEvents.m_data;
      v21 = (signed __int64)&v20[v7];
      v22 = (signed __int64)&v20[v19];
      v23 = 18i64;
      v24 = v22 - v21;
      do
      {
        v25 = *(_QWORD *)(v24 + v21);
        v21 += 8i64;
        *(_QWORD *)(v21 - 8) = v25;
        --v23;
      }
      while ( v23 );
    }
    v6 = -1;
    v7 = -1i64;
    v3 = 0;
  }
  v40 = v47;
  v39 = v47->m_criticalOperationsLockCount == 1;
  --v40->m_criticalOperationsLockCount;
  if ( v39 && !v40->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v40->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v40);
    if ( v40->m_pendingOperationQueueCount == 1 && v40->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v40);
  }
  return v3;
}

// File Line: 395
// RVA: 0xD6C710
signed __int64 __fastcall hkpContinuousSimulation::advanceTime(hkpContinuousSimulation *this)
{
  hkpContinuousSimulation *v1; // rbx
  hkpStepResult v2; // edi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx

  v1 = this;
  v2 = hkpContinuousSimulation::advanceTimeInternal(this);
  if ( v1->m_entitiesNeedingPsiCollisionDetection.m_map.m_numElems & 0x7FFFFFFF )
    ((void (__fastcall *)(hkpContinuousSimulation *, hkpProcessCollisionInput *, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *))v1->vfptr[10].__vecDelDtor)(
      v1,
      v1->m_world->m_collisionInput,
      &v1->m_entitiesNeedingPsiCollisionDetection);
  if ( hkOutOfMemoryState == 1 )
    return 3i64;
  if ( v1->m_simulateUntilTime <= v1->m_currentTime )
  {
    hkpWorld::checkConstraintsViolated(v1->m_world);
    if ( v1->m_world->m_worldPostSimulationListeners.m_size )
    {
      v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v5 = (_QWORD *)v4[1];
      if ( (unsigned __int64)v5 < v4[3] )
      {
        *v5 = "TtPostSimCb";
        v6 = __rdtsc();
        v7 = (signed __int64)(v5 + 2);
        *(_DWORD *)(v7 - 8) = v6;
        v4[1] = v7;
      }
      hkpWorldCallbackUtil::firePostSimulationCallback(v1->m_world);
      v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = (_QWORD *)v8[1];
      if ( (unsigned __int64)v9 < v8[3] )
      {
        *v9 = "Et";
        v10 = __rdtsc();
        v11 = (signed __int64)(v9 + 2);
        *(_DWORD *)(v11 - 8) = v10;
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
  hkpContinuousSimulation *v1; // rdi
  _QWORD *v2; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  unsigned int v10; // ebx
  _QWORD *v11; // rax
  unsigned __int64 v12; // rcx
  _QWORD *v13; // r8
  unsigned __int64 v14; // rax
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  float v19; // xmm6_4
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  hkpStepResult v24; // eax
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx

  v1 = this;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)v2[1];
  if ( (unsigned __int64)v3 < v2[3] )
  {
    *v3 = "TtPhysics 2012";
    v4 = __rdtsc();
    v5 = (signed __int64)(v3 + 2);
    *(_DWORD *)(v5 - 8) = v4;
    v2[1] = v5;
  }
  if ( v1->m_previousStepResult )
  {
    v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = (_QWORD *)v6[1];
    if ( (unsigned __int64)v7 < v6[3] )
    {
      *v7 = "TtreCollideAfterStepFailure";
      v8 = __rdtsc();
      v9 = (signed __int64)(v7 + 2);
      *(_DWORD *)(v9 - 8) = v8;
      v6[1] = v9;
    }
    v10 = hkpSimulation::reCollideAfterStepFailure((hkpSimulation *)&v1->vfptr);
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
      v18 = (signed __int64)(v16 + 2);
      *(_DWORD *)(v18 - 8) = v17;
      v15[1] = v18;
    }
  }
  v19 = hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo((hkpSimulation *)&v1->vfptr);
  if ( !v1->m_toiEvents.m_size )
  {
LABEL_19:
    v10 = 0;
    v1->m_currentTime = v19;
    v1->m_previousStepResult = 0;
    goto LABEL_20;
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "TtTOIs";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
  v24 = hkpContinuousSimulation::handleAllToisTill(v1, v19);
  v10 = v24;
  if ( v24 == HK_STEP_RESULT_SUCCESS )
  {
    v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v30 = (_QWORD *)v29[1];
    if ( (unsigned __int64)v30 < v29[3] )
    {
      *v30 = "Et";
      v31 = __rdtsc();
      v32 = (signed __int64)(v30 + 2);
      *(_DWORD *)(v32 - 8) = v31;
      v29[1] = v32;
    }
    goto LABEL_19;
  }
  v1->m_previousStepResult = v24;
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
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
    v37 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v37 - 8) = v36;
    v35[1] = v37;
  }
  return v10;
}

// File Line: 477
// RVA: 0xD6CA60
void __fastcall hkpContinuousSimulation::resetCollisionInformationForEntities(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, hkpSimulation::ResetCollisionInformation resetInfo)
{
  int v5; // edi
  hkpEntity **v6; // rsi
  hkpContinuousSimulation *v7; // rbp

  v5 = numEntities;
  v6 = entities;
  v7 = this;
  hkpSimulation::resetCollisionInformationForEntities(
    (hkpSimulation *)&this->vfptr,
    entities,
    numEntities,
    world,
    resetInfo);
  if ( resetInfo & 1 )
  {
    if ( v5 == 1 )
      hkpContinuousSimulation::removeToiEventsOfEntity(v7, *v6);
    else
      hkpContinuousSimulation::removeToiEventsOfEntities(v7, v6, v5);
  }
}

// File Line: 497
// RVA: 0xD6C820
void __fastcall hkpContinuousSimulation::reintegrateAndRecollideEntities(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, int reintegrateRecollideMode)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  __m128i *v7; // rax
  hkpWorld *v8; // rbx
  __int64 v9; // r15
  hkpEntity **v10; // r14
  __m128i v11; // xmm6
  float v12; // xmm1_4
  hkpContinuousSimulation *v13; // rsi
  float v14; // xmm0_4
  __int64 v15; // rdi
  hkpEntity *v16; // rdx
  signed int v17; // ST20_4
  bool v18; // zf
  char *exportFinished; // [rsp+20h] [rbp-48h]
  hkStepInfo info; // [rsp+30h] [rbp-38h]

  ++world->m_criticalOperationsLockCount;
  v5 = this->m_currentTime;
  v6 = this->m_currentPsiTime;
  v7 = (__m128i *)world->m_collisionInput;
  v8 = world;
  v9 = numEntities;
  v10 = entities;
  v11 = v7[6];
  info.m_endTime.m_storage = v6;
  v12 = v6 - v5;
  info.m_startTime.m_storage = v5;
  v13 = this;
  info.m_deltaTime.m_storage = v12;
  v14 = 0.0;
  if ( v12 != 0.0 )
    v14 = 1.0 / v12;
  info.m_invDeltaTime.m_storage = v14;
  _mm_store_si128(v7 + 6, (__m128i)info);
  if ( reintegrateRecollideMode & 1 )
  {
    v15 = 0i64;
    if ( numEntities > 0 )
    {
      do
      {
        v16 = v10[v15];
        if ( v16->m_motion.m_type.m_storage != 5 )
          hkSweptTransformUtil::backStepMotionState(v13->m_currentTime, &v16->m_motion.m_motionState);
        ++v15;
      }
      while ( v15 < v9 );
    }
    hkRigidMotionUtilStep(&info, (hkpMotion *const *)v10, v9, 336);
    hkpEntityAabbUtil::entityBatchRecalcAabb((hkpCollisionInput *)&v8->m_collisionInput->m_dispatcher, v10, v9);
  }
  v17 = 1;
  ((void (__fastcall *)(hkpContinuousSimulation *, hkpEntity **, _QWORD, hkpWorld *, signed int))v13->vfptr[6].__vecDelDtor)(
    v13,
    v10,
    (unsigned int)v9,
    v8,
    v17);
  if ( reintegrateRecollideMode & 2 )
    hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(v13, v10, v9, v8, 0i64);
  if ( reintegrateRecollideMode & 4 )
  {
    hkpContinuousSimulation::collideEntitiesNarrowPhaseContinuous(v13, v10, v9, v8->m_collisionInput);
  }
  else if ( reintegrateRecollideMode & 1 )
  {
    LODWORD(exportFinished) = 2;
    ((void (__fastcall *)(hkpContinuousSimulation *, hkpEntity **, _QWORD, hkpWorld *, char *))v13->vfptr[6].__vecDelDtor)(
      v13,
      v10,
      (unsigned int)v9,
      v8,
      exportFinished);
  }
  v18 = v8->m_criticalOperationsLockCount-- == 1;
  if ( v18 && !v8->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v8->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v8);
    if ( v8->m_pendingOperationQueueCount == 1 && v8->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v8);
  }
  _mm_store_si128((__m128i *)&v8->m_collisionInput->m_stepInfo, v11);
}

// File Line: 565
// RVA: 0xD6CAD0
void __fastcall hkpContinuousSimulation::assertThereIsNoCollisionInformationForEntities(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world)
{
  ;
}

// File Line: 604
// RVA: 0xD6CAE0
void __fastcall hkpContinuousSimulation::removeCollisionInformationForAgent(hkpContinuousSimulation *this, hkpAgentNnEntry *agent)
{
  hkpAgentNnEntry *v2; // rdi
  hkpContinuousSimulation *v3; // r9
  int v4; // er11
  __int64 v5; // rbx
  signed __int64 v6; // r10
  hkpToiEvent *v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // r8
  signed __int64 v10; // rax
  signed __int64 v11; // rdx
  signed __int64 v12; // r8
  __int64 v13; // rcx

  v2 = agent;
  v3 = this;
  v4 = this->m_toiEvents.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = v4;
    do
    {
      v7 = v3->m_toiEvents.m_data;
      if ( v7[v6].m_contactMgr == (hkpDynamicsContactMgr *)v2->m_contactMgr )
      {
        v8 = --v3->m_toiEvents.m_size;
        if ( (_DWORD)v8 != v4 )
        {
          v9 = 9 * v8;
          v10 = (signed __int64)&v7[v6];
          v11 = 18i64;
          v12 = 16 * v9 - v6 * 144;
          do
          {
            v13 = *(_QWORD *)(v12 + v10);
            v10 += 8i64;
            *(_QWORD *)(v10 - 8) = v13;
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
void __fastcall hkpContinuousSimulation::assertThereIsNoCollisionInformationForAgent(hkpContinuousSimulation *this, hkpAgentNnEntry *agent)
{
  ;
}

// File Line: 627
// RVA: 0xD6CA10
void __fastcall hkpContinuousSimulation::warpTime(hkpContinuousSimulation *this, float warpDeltaTime)
{
  int v2; // edx
  hkpSimulation *v3; // r8
  __int64 v4; // rcx

  v2 = 0;
  v3 = this->m_world->m_simulation;
  if ( *(_DWORD *)&v3[1].m_memSizeAndFlags > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v2;
      v4 += 9i64;
      *(float *)&v3[1].vfptr[v4 - 9].__vecDelDtor = warpDeltaTime + *(float *)&v3[1].vfptr[v4 - 9].__vecDelDtor;
    }
    while ( v2 < *(_DWORD *)&v3[1].m_memSizeAndFlags );
  }
}

// File Line: 649
// RVA: 0xD6DAA0
void __fastcall hkpContinuousSimulation::collideInternal(hkpContinuousSimulation *this, hkStepInfo *stepInfoIn)
{
  hkpContinuousSimulation *v2; // rbx
  hkStepInfo *v3; // r12
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  int v8; // esi
  int v9; // eax
  __int64 v10; // r14
  signed __int64 v11; // rdi
  hkpToiEvent *v12; // rdx
  hkpEntity *v13; // rax
  int v14; // edi
  float *v15; // rax
  float v16; // xmm1_4
  hkpWorld *v17; // r15
  __int64 v18; // r14
  hkpWorld *v19; // rdi
  bool v20; // zf
  hkpWorld *v21; // r14
  __int64 v22; // rdi
  hkpSimulationIsland **v23; // rax
  hkpSimulationIsland *v24; // rbp
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  hkpWorld *v33; // rbx
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx
  hkpWorld *v38; // rbx
  _QWORD *v39; // r8
  unsigned __int64 v40; // rcx
  unsigned __int64 v41; // rax

  v2 = this;
  v3 = stepInfoIn;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollide";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = 0;
  if ( v2->m_previousStepResult )
  {
    v9 = v2->m_toiEvents.m_size - 1;
    v10 = v9;
    if ( v9 >= 0 )
    {
      v11 = v9;
      do
      {
        v12 = v2->m_toiEvents.m_data;
        v13 = v12[v11].m_entities[0];
        if ( v13->m_motion.m_type.m_storage == 5 )
          v13 = v12[v11].m_entities[1];
        ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v12[v11].m_contactMgr->vfptr[4].__vecDelDtor)(
          v12[v11].m_contactMgr,
          v13->m_simulationIsland,
          &v12[v11].m_properties);
        --v11;
        --v10;
      }
      while ( v10 >= 0 );
    }
    v2->m_toiEvents.m_size = 0;
  }
  v14 = 0;
  _mm_store_si128((__m128i *)&v2->m_world->m_dynamicsStepInfo, *(__m128i *)v3);
  _mm_store_si128((__m128i *)&v2->m_world->m_collisionInput->m_stepInfo, *(__m128i *)v3);
  v15 = (float *)v2->m_world;
  v16 = (float)v2->m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  v15[245] = v15[250] * v3->m_deltaTime.m_storage;
  v15[246] = v16 * v3->m_invDeltaTime.m_storage;
  ++v2->m_world->m_criticalOperationsLockCount;
  v17 = v2->m_world;
  if ( v17->m_activeSimulationIslands.m_size <= 0 )
  {
LABEL_14:
    v19 = v2->m_world;
    v20 = v19->m_criticalOperationsLockCount-- == 1;
    if ( v20 && !v19->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v19->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v19);
      if ( v19->m_pendingOperationQueueCount == 1 && v19->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v19);
    }
    ++v2->m_world->m_criticalOperationsLockCount;
    v21 = v2->m_world;
    if ( v21->m_activeSimulationIslands.m_size > 0 )
    {
      v22 = 0i64;
      do
      {
        v23 = v21->m_activeSimulationIslands.m_data;
        v24 = v23[v22];
        hkpContinuousSimulation::collideIslandNarrowPhaseContinuous(v2, v23[v22], v2->m_world->m_collisionInput);
        if ( hkOutOfMemoryState == 1 )
          break;
        if ( v2->m_world->m_islandPostCollideListeners.m_size )
        {
          v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v26 = (_QWORD *)v25[1];
          if ( (unsigned __int64)v26 < v25[3] )
          {
            *v26 = "TtIslandPostCollideCb";
            v27 = __rdtsc();
            v28 = (signed __int64)(v26 + 2);
            *(_DWORD *)(v28 - 8) = v27;
            v25[1] = v28;
          }
          hkpWorldCallbackUtil::fireIslandPostCollideCallback(v2->m_world, v24, v3);
          v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v30 = (_QWORD *)v29[1];
          if ( (unsigned __int64)v30 < v29[3] )
          {
            *v30 = "Et";
            v31 = __rdtsc();
            v32 = (signed __int64)(v30 + 2);
            *(_DWORD *)(v32 - 8) = v31;
            v29[1] = v32;
          }
        }
        ++v8;
        ++v22;
      }
      while ( v8 < v21->m_activeSimulationIslands.m_size );
    }
    v33 = v2->m_world;
    v20 = v33->m_criticalOperationsLockCount-- == 1;
    if ( v20 && !v33->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v33->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v33);
      if ( v33->m_pendingOperationQueueCount == 1 && v33->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v33);
    }
    v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v35 = (_QWORD *)v34[1];
    if ( (unsigned __int64)v35 < v34[3] )
    {
      v36 = __rdtsc();
      *v35 = "Et";
      v37 = (signed __int64)(v35 + 2);
      *(_DWORD *)(v37 - 8) = v36;
      v34[1] = v37;
    }
  }
  else
  {
    v18 = 0i64;
    while ( 1 )
    {
      hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(
        v2,
        v17->m_activeSimulationIslands.m_data[v18]->m_entities.m_data,
        v17->m_activeSimulationIslands.m_data[v18]->m_entities.m_size,
        v2->m_world,
        0i64);
      if ( hkOutOfMemoryState == 1 )
        break;
      ++v14;
      ++v18;
      if ( v14 >= v17->m_activeSimulationIslands.m_size )
        goto LABEL_14;
    }
    v38 = v2->m_world;
    v20 = v38->m_criticalOperationsLockCount-- == 1;
    if ( v20 && !v38->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v38->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v38);
      if ( v38->m_pendingOperationQueueCount == 1 && v38->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v38);
    }
    v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v40 = v39[1];
    if ( v40 < v39[3] )
    {
      *(_QWORD *)v40 = "Et";
      v41 = __rdtsc();
      *(_DWORD *)(v40 + 8) = v41;
      v39[1] = v40 + 16;
    }
  }
}

// File Line: 735
// RVA: 0xD6D330
void __fastcall hkpContinuousSimulation::collideEntitiesBroadPhaseContinuousFindPairs(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairs)
{
  hkpWorld *v6; // r13
  unsigned int v7; // ebx
  hkpEntity **v8; // r12
  _QWORD *v9; // r8
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  hkLifoAllocator *v12; // rax
  char *v13; // r14
  int v14; // esi
  char *v15; // rcx
  hkLifoAllocator *v16; // rax
  _BYTE *v17; // rbp
  int v18; // er15
  char *v19; // rcx
  int v20; // eax
  signed __int64 v21; // rcx
  signed __int64 v22; // r12
  _QWORD *v23; // rbx
  unsigned int *v24; // rdi
  __m128i v26; // xmm4
  unsigned int v27; // eax
  __m128i v28; // xmm3
  __m128i v29; // xmm0
  bool v30; // sf
  __m128i v31; // xmm3
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  hkpBroadPhase *v36; // rcx
  hkpBroadPhase *v37; // rcx
  hkLifoAllocator *v38; // rax
  int v39; // er8
  hkLifoAllocator *v40; // rax
  int v41; // er8
  _QWORD *v42; // r9
  _QWORD *v43; // r8
  unsigned __int64 v44; // rax
  signed __int64 v45; // r8
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  int v51; // [rsp+30h] [rbp-58h]
  signed __int64 v52; // [rsp+38h] [rbp-50h]
  hkpEntity *entityBatch; // [rsp+40h] [rbp-48h]
  int v54; // [rsp+A0h] [rbp+18h]

  if ( numEntities )
  {
    v54 = numEntities;
    v6 = world;
    v7 = numEntities;
    v8 = entities;
    v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = v9[1];
    if ( v10 < v9[3] )
    {
      *(_QWORD *)v10 = "LtBroadPhase";
      *(_QWORD *)(v10 + 16) = "StGatherAabbs";
      v11 = __rdtsc();
      *(_DWORD *)(v10 + 8) = v11;
      v9[1] = v10 + 24;
    }
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (char *)v12->m_cur;
    v14 = (32 * v7 + 127) & 0xFFFFFF80;
    v15 = &v13[v14];
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = v16->m_cur;
    v18 = (8 * v7 + 127) & 0xFFFFFF80;
    v19 = &v17[v18];
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
      v17 = hkLifoAllocator::allocateFromNewSlab(v16, v18);
    else
      v16->m_cur = v19;
    v20 = v7 - 1;
    v51 = v7 - 1;
    if ( (signed int)(v7 - 1) >= 0 )
    {
      v21 = (signed __int64)(v13 + 8);
      v22 = (char *)v8 - v17;
      v23 = v17;
      v52 = (signed __int64)(v13 + 8);
      do
      {
        v24 = *(unsigned int **)((char *)v23 + v22);
        entityBatch = *(hkpEntity **)((char *)v23 + v22);
        if ( v20 >= 4 )
        {
          _RAX = *(_QWORD *)((char *)v23 + v22 + 32);
          __asm { prefetchnta byte ptr [rax+20h]; Prefetch to L1 cache }
        }
        *v23 = v24 + 17;
        if ( v24[20] > v24[24] )
        {
          hkpEntityAabbUtil::entityBatchRecalcAabb(
            (hkpCollisionInput *)&v6->m_collisionInput->m_dispatcher,
            &entityBatch,
            1);
          v21 = v52;
        }
        v21 += 32i64;
        ++v23;
        v52 = v21;
        v26 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v24[23], (__m128i)0i64), (__m128i)0i64);
        v27 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v26, 255));
        v28 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v24[20]), _mm_cvtsi32_si128(v24[22])),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v24[21]), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v26, v27));
        _mm_storel_epi64((__m128i *)(v21 - 40), v28);
        *(_DWORD *)(v21 - 32) = (unsigned __int128)_mm_shuffle_epi32(v28, 170);
        v29 = _mm_cvtsi32_si128(v27);
        v30 = v51 - 1 < 0;
        v20 = v51-- - 1;
        v31 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v24[24]), _mm_cvtsi32_si128(v24[26])),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v24[25]), _mm_cvtsi32_si128(0))),
                _mm_sll_epi32(
                  _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v24[27], (__m128i)0i64), (__m128i)0i64),
                  v29));
        _mm_storel_epi64((__m128i *)(v21 - 24), v31);
        *(_DWORD *)(v21 - 16) = (unsigned __int128)_mm_shuffle_epi32(v31, 170);
      }
      while ( !v30 );
      v7 = v54;
    }
    v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v33 = (_QWORD *)v32[1];
    if ( (unsigned __int64)v33 < v32[3] )
    {
      *v33 = "St3AxisSweep";
      v34 = __rdtsc();
      v35 = (signed __int64)(v33 + 2);
      *(_DWORD *)(v35 - 8) = v34;
      v32[1] = v35;
    }
    v36 = v6->m_broadPhase;
    if ( v36->m_criticalSection )
      hkpBroadPhase::lockImplementation(v36);
    ((void (__fastcall *)(hkpBroadPhase *, _BYTE *, char *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v6->m_broadPhase->vfptr[6].__vecDelDtor)(
      v6->m_broadPhase,
      v17,
      v13,
      v7,
      newPairs,
      delPairs);
    v37 = v6->m_broadPhase;
    if ( v37->m_criticalSection )
      hkpBroadPhase::unlockImplementation(v37);
    v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v39 = (v18 + 15) & 0xFFFFFFF0;
    if ( v18 > v38->m_slabSize || &v17[v39] != v38->m_cur || v38->m_firstNonLifoEnd == v17 )
      hkLifoAllocator::slowBlockFree(v38, v17, v39);
    else
      v38->m_cur = v17;
    v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v41 = (v14 + 15) & 0xFFFFFFF0;
    if ( v14 > v40->m_slabSize || &v13[v41] != v40->m_cur || v40->m_firstNonLifoEnd == v13 )
      hkLifoAllocator::slowBlockFree(v40, v13, v41);
    else
      v40->m_cur = v13;
    if ( delPairs->m_size + newPairs->m_size > 0 )
    {
      v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v43 = (_QWORD *)v42[1];
      if ( (unsigned __int64)v43 < v42[3] )
      {
        *v43 = "StRemoveDup";
        v44 = __rdtsc();
        v45 = (signed __int64)(v43 + 2);
        *(_DWORD *)(v45 - 8) = v44;
        v42[1] = v45;
      }
      hkpTypedBroadPhaseDispatcher::removeDuplicates(newPairs, delPairs);
    }
    v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v47 = (_QWORD *)v46[1];
    v48 = v46;
    if ( (unsigned __int64)v47 < v46[3] )
    {
      *v47 = "lt";
      v49 = __rdtsc();
      v50 = (signed __int64)(v47 + 2);
      *(_DWORD *)(v50 - 8) = v49;
      v48[1] = v50;
    }
  }
}

// File Line: 841
// RVA: 0xD6CBA0
void __fastcall hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, char *exportFinished)
{
  hkpWorld *v5; // rdi
  unsigned int v6; // esi
  hkpEntity **v7; // r12
  _QWORD *v8; // rax
  unsigned __int64 v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  int v12; // ebx
  LPVOID v13; // rax
  hkLifoAllocator *v14; // rcx
  hkpBroadPhaseHandlePair *v15; // rax
  int v16; // edx
  char *v17; // r8
  int v18; // ebx
  LPVOID v19; // rax
  hkLifoAllocator *v20; // rcx
  hkpBroadPhaseHandlePair *v21; // rax
  int v22; // edx
  char *v23; // r8
  hkLifoAllocator *v24; // rax
  char *v25; // r13
  int v26; // er14
  char *v27; // rcx
  hkLifoAllocator *v28; // rax
  _BYTE *v29; // r15
  int v30; // ebx
  char *v31; // rcx
  int v32; // eax
  signed __int64 v33; // rcx
  signed __int64 v34; // r12
  _QWORD *v35; // rsi
  unsigned int *v36; // rbx
  signed __int64 v38; // ST18_8
  __m128i v39; // xmm4
  unsigned int v40; // eax
  __m128i v41; // xmm3
  __m128i v42; // xmm0
  bool v43; // sf
  __m128i v44; // xmm3
  _QWORD *v45; // r8
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rax
  signed __int64 v48; // rcx
  hkpBroadPhase *v49; // rcx
  hkpBroadPhase *v50; // rcx
  hkBaseObjectVtbl *v51; // rax
  hkpBroadPhase *v52; // rcx
  hkLifoAllocator *v53; // rax
  int v54; // er8
  hkLifoAllocator *v55; // rax
  int v56; // er8
  _QWORD *v57; // r8
  _QWORD *v58; // rcx
  unsigned __int64 v59; // rax
  signed __int64 v60; // rcx
  _QWORD *v61; // r8
  _QWORD *v62; // rcx
  unsigned __int64 v63; // rax
  signed __int64 v64; // rcx
  _QWORD *v65; // r8
  _QWORD *v66; // rcx
  unsigned __int64 v67; // rax
  signed __int64 v68; // rcx
  _QWORD *v69; // r8
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  signed __int64 v72; // rcx
  int v73; // ebx
  hkMemorySystem *v74; // rax
  _QWORD *v75; // r8
  _QWORD *v76; // rcx
  unsigned __int64 v77; // rax
  signed __int64 v78; // rcx
  int v79; // eax
  char *v80; // rdi
  signed int v81; // ebx
  hkLifoAllocator *v82; // rax
  int v83; // er8
  _QWORD *v84; // r8
  _QWORD *v85; // rcx
  unsigned __int64 v86; // rax
  signed __int64 v87; // rcx
  hkpCollisionFilter *v88; // rax
  hkpCollidableCollidableFilter *v89; // r9
  int v90; // eax
  char *v91; // rdi
  signed int v92; // ebx
  hkLifoAllocator *v93; // rax
  int v94; // er8
  int v95; // [rsp+10h] [rbp-51h]
  unsigned int v96; // [rsp+14h] [rbp-4Dh]
  hkpEntity *entityBatch; // [rsp+20h] [rbp-41h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+28h] [rbp-39h]
  void *p; // [rsp+38h] [rbp-29h]
  int v100; // [rsp+40h] [rbp-21h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+48h] [rbp-19h]
  void *v102; // [rsp+58h] [rbp-9h]
  int v103; // [rsp+60h] [rbp-1h]
  hkpEntity **v104; // [rsp+C8h] [rbp+67h]
  unsigned int vars0; // [rsp+D0h] [rbp+6Fh]
  _BYTE *v106; // [rsp+E0h] [rbp+7Fh]

  if ( numEntities )
  {
    v5 = world;
    v6 = numEntities;
    v7 = entities;
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = v8[1];
    v10 = v8;
    if ( v9 < v8[3] )
    {
      *(_QWORD *)v9 = "LtBroadPhase";
      *(_QWORD *)(v9 + 16) = "StGatherAabbs";
      v11 = __rdtsc();
      *(_DWORD *)(v9 + 8) = v11;
      v10[1] = v9 + 24;
    }
    v12 = v5->m_broadPhaseUpdateSize;
    newPairs.m_capacityAndFlags = 2147483648;
    newPairs.m_data = 0i64;
    newPairs.m_size = 0;
    v103 = v12;
    if ( v12 )
    {
      v13 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v14 = (hkLifoAllocator *)v13;
      v15 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v13 + 3);
      v16 = (16 * v12 + 127) & 0xFFFFFF80;
      v17 = (char *)v15 + v16;
      if ( v16 > v14->m_slabSize || v17 > v14->m_end )
        v15 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
      else
        v14->m_cur = v17;
    }
    else
    {
      v15 = 0i64;
    }
    newPairs.m_data = v15;
    v102 = v15;
    newPairs.m_capacityAndFlags = v12 | 0x80000000;
    v18 = v5->m_broadPhaseUpdateSize;
    delPairs.m_data = 0i64;
    delPairs.m_size = 0;
    delPairs.m_capacityAndFlags = 2147483648;
    v100 = v18;
    if ( v18 )
    {
      v19 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (hkLifoAllocator *)v19;
      v21 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v19 + 3);
      v22 = (16 * v18 + 127) & 0xFFFFFF80;
      v23 = (char *)v21 + v22;
      if ( v22 > v20->m_slabSize || v23 > v20->m_end )
        v21 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
      else
        v20->m_cur = v23;
    }
    else
    {
      v21 = 0i64;
    }
    delPairs.m_data = v21;
    delPairs.m_capacityAndFlags = v18 | 0x80000000;
    p = v21;
    v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (char *)v24->m_cur;
    v26 = (32 * v6 + 127) & 0xFFFFFF80;
    v27 = &v25[v26];
    if ( v26 > v24->m_slabSize || v27 > v24->m_end )
      v25 = (char *)hkLifoAllocator::allocateFromNewSlab(v24, v26);
    else
      v24->m_cur = v27;
    v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = v28->m_cur;
    v30 = (8 * v6 + 127) & 0xFFFFFF80;
    v96 = (8 * v6 + 127) & 0xFFFFFF80;
    v31 = &v29[v30];
    if ( v30 > v28->m_slabSize || v31 > v28->m_end )
      v29 = hkLifoAllocator::allocateFromNewSlab(v28, v30);
    else
      v28->m_cur = v31;
    v32 = v6 - 1;
    v95 = v6 - 1;
    if ( (signed int)(v6 - 1) >= 0 )
    {
      v33 = (signed __int64)(v25 + 8);
      v34 = (char *)v7 - v29;
      v35 = v29;
      do
      {
        v36 = *(unsigned int **)((char *)v35 + v34);
        entityBatch = *(hkpEntity **)((char *)v35 + v34);
        if ( v32 >= 4 )
        {
          _RAX = *(_QWORD *)((char *)v35 + v34 + 32);
          __asm { prefetchnta byte ptr [rax+20h]; Prefetch to L1 cache }
        }
        *v35 = v36 + 17;
        if ( v36[20] > v36[24] )
        {
          hkpEntityAabbUtil::entityBatchRecalcAabb(
            (hkpCollisionInput *)&v5->m_collisionInput->m_dispatcher,
            &entityBatch,
            1);
          v33 = v38;
        }
        v33 += 32i64;
        ++v35;
        v39 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v36[23], (__m128i)0i64), (__m128i)0i64);
        v40 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v39, 255));
        v41 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v36[20]), _mm_cvtsi32_si128(v36[22])),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v36[21]), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v39, v40));
        _mm_storel_epi64((__m128i *)(v33 - 40), v41);
        *(_DWORD *)(v33 - 32) = (unsigned __int128)_mm_shuffle_epi32(v41, 170);
        v42 = _mm_cvtsi32_si128(v40);
        v43 = v95 - 1 < 0;
        v32 = v95-- - 1;
        v44 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v36[24]), _mm_cvtsi32_si128(v36[26])),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(v36[25]), _mm_cvtsi32_si128(0))),
                _mm_sll_epi32(
                  _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v36[27], (__m128i)0i64), (__m128i)0i64),
                  v42));
        _mm_storel_epi64((__m128i *)(v33 - 24), v44);
        *(_DWORD *)(v33 - 16) = (unsigned __int128)_mm_shuffle_epi32(v44, 170);
      }
      while ( !v43 );
      v30 = v96;
      v6 = vars0;
      v7 = v104;
    }
    v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v46 = (_QWORD *)v45[1];
    if ( (unsigned __int64)v46 < v45[3] )
    {
      *v46 = "St3AxisSweep";
      v47 = __rdtsc();
      v48 = (signed __int64)(v46 + 2);
      *(_DWORD *)(v48 - 8) = v47;
      v45[1] = v48;
    }
    v49 = v5->m_broadPhase;
    if ( v49->m_criticalSection )
      hkpBroadPhase::lockImplementation(v49);
    v50 = v5->m_broadPhase;
    v51 = v50->vfptr;
    delPairs.m_data = (hkpBroadPhaseHandlePair *)&delPairs;
    entityBatch = (hkpEntity *)&newPairs;
    ((void (__fastcall *)(hkpBroadPhase *, _BYTE *, char *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v51[6].__vecDelDtor)(
      v50,
      v29,
      v25,
      v6,
      &newPairs);
    v52 = v5->m_broadPhase;
    if ( v52->m_criticalSection )
      hkpBroadPhase::unlockImplementation(v52);
    v53 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v54 = (v30 + 15) & 0xFFFFFFF0;
    if ( v30 > v53->m_slabSize || &v29[v54] != v53->m_cur || v53->m_firstNonLifoEnd == v29 )
      hkLifoAllocator::slowBlockFree(v53, v29, v54);
    else
      v53->m_cur = v29;
    v55 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v56 = (v26 + 15) & 0xFFFFFFF0;
    if ( v26 > v55->m_slabSize || &v25[v56] != v55->m_cur || v55->m_firstNonLifoEnd == v25 )
      hkLifoAllocator::slowBlockFree(v55, v25, v56);
    else
      v55->m_cur = v25;
    if ( delPairs.m_size + newPairs.m_size > 0 )
    {
      v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v58 = (_QWORD *)v57[1];
      if ( (unsigned __int64)v58 < v57[3] )
      {
        *v58 = "StRemoveDup";
        v59 = __rdtsc();
        v60 = (signed __int64)(v58 + 2);
        *(_DWORD *)(v60 - 8) = v59;
        v57[1] = v60;
      }
      hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &delPairs);
    }
    if ( v106 )
    {
      v61 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v62 = (_QWORD *)v61[1];
      if ( (unsigned __int64)v62 < v61[3] )
      {
        *v62 = "TtWaitForExport";
        v63 = __rdtsc();
        v64 = (signed __int64)(v62 + 2);
        *(_DWORD *)(v64 - 8) = v63;
        v61[1] = v64;
      }
      while ( *v106 != 1 && *v106 != 2 )
        ;
      v65 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v66 = (_QWORD *)v65[1];
      if ( (unsigned __int64)v66 < v65[3] )
      {
        *v66 = "Et";
        v67 = __rdtsc();
        v68 = (signed __int64)(v66 + 2);
        *(_DWORD *)(v68 - 8) = v67;
        v65[1] = v68;
      }
    }
    if ( delPairs.m_size + newPairs.m_size > 0 )
    {
      v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v70 = (_QWORD *)v69[1];
      if ( (unsigned __int64)v70 < v69[3] )
      {
        *v70 = "StRemoveAgt";
        v71 = __rdtsc();
        v72 = (signed __int64)(v70 + 2);
        *(_DWORD *)(v72 - 8) = v71;
        v69[1] = v72;
      }
      hkpWorld::lockIslandForConstraintUpdate(v5, (*v7)->m_simulationIsland);
      hkpTypedBroadPhaseDispatcher::removePairs(
        v5->m_broadPhaseDispatcher,
        (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
        delPairs.m_size);
      v73 = newPairs.m_size;
      v74 = hkMemorySystem::getInstance();
      if ( v74->vfptr->heapCanAllocTotal(v74, v73 << 10) )
      {
        v84 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v85 = (_QWORD *)v84[1];
        if ( (unsigned __int64)v85 < v84[3] )
        {
          *v85 = "StAddAgt";
          v86 = __rdtsc();
          v87 = (signed __int64)(v85 + 2);
          *(_DWORD *)(v87 - 8) = v86;
          v84[1] = v87;
        }
        v88 = v5->m_collisionFilter;
        v89 = (hkpCollidableCollidableFilter *)&v88->vfptr;
        if ( !v88 )
          v89 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          v5->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v89);
        hkpWorld::unlockIslandForConstraintUpdate(v5, (*v7)->m_simulationIsland);
      }
      else
      {
        hkpWorld::unlockIslandForConstraintUpdate(v5, (*v7)->m_simulationIsland);
      }
    }
    v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v76 = (_QWORD *)v75[1];
    if ( (unsigned __int64)v76 < v75[3] )
    {
      *v76 = "lt";
      v77 = __rdtsc();
      v78 = (signed __int64)(v76 + 2);
      *(_DWORD *)(v78 - 8) = v77;
      v75[1] = v78;
    }
    v79 = delPairs.m_size;
    v80 = (char *)p;
    if ( p == delPairs.m_data )
      v79 = 0;
    delPairs.m_size = v79;
    v81 = (16 * v100 + 127) & 0xFFFFFF80;
    v82 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v83 = (v81 + 15) & 0xFFFFFFF0;
    if ( v81 > v82->m_slabSize || &v80[v83] != v82->m_cur || v82->m_firstNonLifoEnd == v80 )
      hkLifoAllocator::slowBlockFree(v82, v80, v83);
    else
      v82->m_cur = v80;
    delPairs.m_size = 0;
    if ( delPairs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        delPairs.m_data,
        16 * delPairs.m_capacityAndFlags);
    v90 = newPairs.m_size;
    v91 = (char *)v102;
    delPairs.m_data = 0i64;
    if ( v102 == newPairs.m_data )
      v90 = 0;
    delPairs.m_capacityAndFlags = 2147483648;
    newPairs.m_size = v90;
    v92 = (16 * v103 + 127) & 0xFFFFFF80;
    v93 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v94 = (v92 + 15) & 0xFFFFFFF0;
    if ( v92 > v93->m_slabSize || &v91[v94] != v93->m_cur || v93->m_firstNonLifoEnd == v91 )
      hkLifoAllocator::slowBlockFree(v93, v91, v94);
    else
      v93->m_cur = v91;
    newPairs.m_size = 0;
    if ( newPairs.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        newPairs.m_data,
        16 * newPairs.m_capacityAndFlags);
  }
}

// File Line: 956
// RVA: 0xD6D720
void __fastcall hkpContinuousSimulation::collideIslandNarrowPhaseContinuous(hkpContinuousSimulation *this, hkpSimulationIsland *isle, hkpProcessCollisionInput *input)
{
  hkpContinuousSimulation *v3; // r12
  hkpProcessCollisionInput *v4; // rsi
  hkpSimulationIsland *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  signed __int64 v11; // rax
  unsigned __int16 *v12; // r13
  int v13; // er15
  int v14; // ecx
  __int64 v15; // rdx
  hkpAgentNnEntry *v17; // rdi
  hkpLinkedCollidable *v18; // rbp
  hkpLinkedCollidable *v19; // r14
  signed __int64 v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  hkpAgentNnTrack *v25; // [rsp+30h] [rbp-30F8h]
  hkpAgentNnTrack *v26; // [rsp+38h] [rbp-30F0h]
  hkpProcessCollisionOutput output; // [rsp+40h] [rbp-30E8h]
  signed __int64 v28; // [rsp+3138h] [rbp+10h]
  __int64 v29; // [rsp+3148h] [rbp+20h]

  v3 = this;
  v4 = input;
  v5 = isle;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtNarrowPhase";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  output.m_toi.m_time.m_storage = 3.40282e38;
  v25 = &v5->m_narrowphaseAgentTrack;
  output.m_toi.m_properties.0 = 0i64;
  v26 = &v5->m_midphaseAgentTrack;
  v11 = 0i64;
  output.m_constraintOwner.m_storage = (hkpConstraintOwner *)&v5->vfptr;
  v28 = 0i64;
  while ( 1 )
  {
    v12 = (unsigned __int16 *)*(&v25 + v11);
    v13 = 0;
    v14 = *((_DWORD *)v12 + 4);
    if ( v14 > 0 )
      break;
LABEL_19:
    v28 = ++v11;
    if ( v11 >= 2 )
      goto LABEL_20;
  }
  v15 = 0i64;
  while ( 1 )
  {
    v15 += 8i64;
    ++v13;
    _RBX = *(hkpAgentNnEntry **)(v15 + *((_QWORD *)v12 + 1) - 8);
    v29 = v15;
    v17 = v13 == v14 ? (hkpAgentNnEntry *)((char *)_RBX + *v12) : &_RBX[24];
    if ( _RBX < v17 )
      break;
LABEL_17:
    v14 = *((_DWORD *)v12 + 4);
    if ( v13 >= v14 )
    {
      v11 = v28;
      goto LABEL_19;
    }
  }
  while ( 1 )
  {
    v18 = _RBX->m_collidable[0];
    v19 = _RBX->m_collidable[1];
    _RAX = _RBX->m_contactMgr;
    __asm
    {
      prefetchnta byte ptr [rax]; Prefetch to L1 cache
      prefetchnta byte ptr [rbx+80h]; Prefetch to L1 cache
    }
    v21 = (signed __int64)v4->m_dispatcher.m_storage + 64 * (_RBX->m_collisionQualityIndex + 161i64);
    v4->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v21;
    LODWORD(_RAX) = *(_DWORD *)(v21 + 16);
    output.m_toi.m_time.m_storage = 3.40282e38;
    output.m_potentialContacts.m_storage = 0i64;
    v4->m_createPredictiveAgents.m_storage = (unsigned int)_RAX;
    output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
    hkAgentNnMachine_ProcessAgent(_RBX, v4, &output, _RBX->m_contactMgr, (__int64)v3);
    if ( hkOutOfMemoryState == 1 )
      break;
    if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
      ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))_RBX->m_contactMgr->vfptr[3].__vecDelDtor)(
        _RBX->m_contactMgr,
        v18,
        v19,
        v4,
        &output);
    if ( output.m_toi.m_time.m_storage != 3.40282e38 )
      hkpContinuousSimulation::addToiEvent(v3, &output, _RBX);
    _RBX = (hkpAgentNnEntry *)((char *)_RBX + (unsigned __int8)_RBX->m_size);
    if ( _RBX >= v17 )
    {
      v15 = v29;
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
void __fastcall hkpContinuousSimulation::collideEntitiesNarrowPhaseContinuous(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpProcessCollisionInput *input)
{
  hkpSimulation::processAgentsOfEntities(
    (hkpSimulation *)&this->vfptr,
    entities,
    numEntities,
    input,
    (void (__fastcall *)(hkpSimulation *, hkpAgentNnEntry *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))hkpContinuousSimulation::processAgentCollideContinuous,
    0);
}

// File Line: 1063
// RVA: 0xD6D9C0
void __usercall hkpContinuousSimulation::processAgentCollideContinuous(hkpContinuousSimulation *this@<rcx>, hkpAgentNnEntry *entry@<rdx>, hkpProcessCollisionInput *processInput@<r8>, hkpProcessCollisionOutput *processOutput@<r9>, __int64 a5@<r12>)
{
  hkpProcessCdPoint *v5; // rbp
  hkpProcessCollisionOutput *v6; // rbx
  hkpProcessCollisionInput *v7; // rsi
  hkpAgentNnEntry *v8; // rdi
  hkpContinuousSimulation *v9; // r14
  hkpCollisionQualityInfo *v10; // r9

  processOutput->m_toi.m_time.m_storage = 3.40282e38;
  processOutput->m_potentialContacts.m_storage = 0i64;
  v5 = processOutput->m_contactPoints;
  processOutput->m_firstFreeContactPoint.m_storage = processOutput->m_contactPoints;
  v6 = processOutput;
  v7 = processInput;
  v8 = entry;
  v9 = this;
  v10 = (hkpCollisionQualityInfo *)((char *)processInput->m_dispatcher.m_storage
                                  + 64 * (entry->m_collisionQualityIndex + 161i64));
  processInput->m_collisionQualityInfo.m_storage = v10;
  processInput->m_createPredictiveAgents.m_storage = v10->m_useContinuousPhysics.m_storage;
  hkAgentNnMachine_ProcessAgent(entry, processInput, v6, entry->m_contactMgr, a5);
  if ( hkOutOfMemoryState != 1 )
  {
    if ( v6->m_firstFreeContactPoint.m_storage != v5 )
      ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v8->m_contactMgr->vfptr[3].__vecDelDtor)(
        v8->m_contactMgr,
        v8->m_collidable[0],
        v8->m_collidable[1],
        v7,
        v6);
    if ( 3.40282e38 != v6->m_toi.m_time.m_storage )
      hkpContinuousSimulation::addToiEvent(v9, v6, v8);
  }
}

// File Line: 1104
// RVA: 0xD6E080
void __fastcall hkpContinuousSimulation::addToiEvent(hkpContinuousSimulation *this, hkpProcessCollisionOutput *processOutput, hkpAgentNnEntry *entry)
{
  hkpAgentNnEntry *v3; // r11
  hkpContinuousSimulation *v4; // r9
  __int64 v5; // rcx
  signed __int64 v6; // r8
  hkErrStream v7; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v3 = entry;
  v4 = this;
  if ( this->m_toiEvents.m_size == (this->m_toiEvents.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkErrStream::hkErrStream(&v7, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v7.vfptr,
      "TOI event queue full, consider using HK_COLLIDABLE_QUALITY_DEBRIS for some objects or increase hkpWorldCinfo::m_si"
      "zeOfToiEventQueue");
    hkError::messageWarning(-265145260, &buf, "World\\Simulation\\Continuous\\hkpContinuousSimulation.cpp", 1107);
    hkOstream::~hkOstream((hkOstream *)&v7.vfptr);
  }
  else
  {
    v5 = this->m_toiEvents.m_size;
    v4->m_toiEvents.m_size = v5 + 1;
    v6 = (signed __int64)&v4->m_toiEvents.m_data[v5];
    *(float *)v6 = processOutput->m_toi.m_time.m_storage;
    *(_BYTE *)(v6 + 8) = v4->m_world->m_collisionDispatcher->m_collisionQualityInfo[(signed __int64)v3->m_collisionQualityIndex].m_useSimpleToiHandling.m_bool;
    *(float *)(v6 + 4) = processOutput->m_toi.m_seperatingVelocity.m_storage;
    *(hkVector4f *)(v6 + 112) = processOutput->m_toi.m_contactPoint.m_position;
    *(hkVector4f *)(v6 + 128) = processOutput->m_toi.m_contactPoint.m_separatingNormal;
    *(_QWORD *)(v6 + 16) = (char *)v3->m_collidable[0] + v3->m_collidable[0]->m_ownerOffset;
    *(_QWORD *)(v6 + 24) = (char *)v3->m_collidable[1] + v3->m_collidable[1]->m_ownerOffset;
    *(hkpSolverResults *)(v6 + 40) = processOutput->m_toi.m_properties.0;
    *(_QWORD *)(v6 + 48) = processOutput->m_toi.m_properties.m_userData;
    *(_QWORD *)(v6 + 56) = *(_QWORD *)&processOutput->m_toi.m_properties.m_friction.m_value;
    *(_QWORD *)(v6 + 64) = *(_QWORD *)&processOutput->m_toi.m_properties.m_internalDataA;
    *(_QWORD *)(v6 + 32) = v3->m_contactMgr;
    *(_DWORD *)(v6 + 72) = processOutput->m_toi.m_properties.m_extendedUserDatas[0];
    *(_DWORD *)(v6 + 76) = processOutput->m_toi.m_properties.m_extendedUserDatas[1];
    *(_DWORD *)(v6 + 80) = processOutput->m_toi.m_properties.m_extendedUserDatas[2];
    *(_DWORD *)(v6 + 84) = processOutput->m_toi.m_properties.m_extendedUserDatas[3];
    *(_DWORD *)(v6 + 88) = processOutput->m_toi.m_properties.m_extendedUserDatas[4];
    *(_DWORD *)(v6 + 92) = processOutput->m_toi.m_properties.m_extendedUserDatas[5];
    *(_DWORD *)(v6 + 96) = processOutput->m_toi.m_properties.m_extendedUserDatas[6];
  }
}

// File Line: 1132
// RVA: 0xD6E210
void __fastcall hkpContinuousSimulation::removeToiEventsOfEntities(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities)
{
  __int64 v3; // rsi
  hkpEntity **v4; // r15
  hkpContinuousSimulation *v5; // r14
  int v6; // edi
  __int64 i; // rbx
  __int64 v8; // rsi
  hkpToiEvent *v9; // rbp
  int v10; // ebx
  int v11; // eax
  hkpEntity *v12; // rax
  __int64 v13; // rax
  signed __int64 v14; // rdx
  signed __int64 v15; // r8
  hkpToiEvent *v16; // rax
  signed __int64 v17; // r8
  unsigned __int64 v18; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v19; // [rsp+20h] [rbp-28h]

  v3 = numEntities;
  v4 = entities;
  v5 = this;
  if ( this->m_toiEvents.m_size )
  {
    v6 = 0;
    v19.m_hashMod = -1;
    v19.m_elem = 0i64;
    v19.m_numElems = 0;
    if ( numEntities )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        &v19,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        numEntities);
    for ( i = 0i64; i < v3; ++i )
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v19,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v4[i],
        0i64);
    if ( v5->m_toiEvents.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = &v5->m_toiEvents.m_data[v8];
        v10 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v19,
                                  (unsigned __int64)v9->m_entities[0]);
        v11 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v19,
                                  (unsigned __int64)v9->m_entities[1]);
        if ( v10 <= v19.m_hashMod || v11 <= v19.m_hashMod )
        {
          v12 = v9->m_entities[0];
          if ( v12->m_motion.m_type.m_storage == 5 )
            v12 = v9->m_entities[1];
          ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v9->m_contactMgr->vfptr[4].__vecDelDtor)(
            v9->m_contactMgr,
            v12->m_simulationIsland,
            &v9->m_properties);
          v13 = --v5->m_toiEvents.m_size;
          if ( (_DWORD)v13 != v6 )
          {
            v14 = 18i64;
            v15 = 144 * v13;
            v16 = &v5->m_toiEvents.m_data[v8];
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
      while ( v6 < v5->m_toiEvents.m_size );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v19,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v19);
  }
}

// File Line: 1176
// RVA: 0xD6E3A0
void __fastcall hkpContinuousSimulation::removeToiEventsOfEntity(hkpContinuousSimulation *this, hkpEntity *entity)
{
  int v2; // ebx
  hkpEntity *v3; // rbp
  hkpContinuousSimulation *v4; // rsi
  __int64 v5; // rdi
  hkpToiEvent *v6; // r8
  hkpEntity *v7; // rax
  __int64 v8; // rax
  signed __int64 v9; // rdx
  signed __int64 v10; // r8
  hkpToiEvent *v11; // rax
  signed __int64 v12; // r8
  unsigned __int64 v13; // rcx

  v2 = 0;
  v3 = entity;
  v4 = this;
  if ( this->m_toiEvents.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = &v4->m_toiEvents.m_data[v5];
      if ( v6->m_entities[0] == v3 || v6->m_entities[1] == v3 )
      {
        v7 = v6->m_entities[0];
        if ( v7->m_motion.m_type.m_storage == 5 )
          v7 = v6->m_entities[1];
        ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v6->m_contactMgr->vfptr[4].__vecDelDtor)(
          v6->m_contactMgr,
          v7->m_simulationIsland,
          &v6->m_properties);
        v8 = --v4->m_toiEvents.m_size;
        if ( (_DWORD)v8 != v2 )
        {
          v9 = 18i64;
          v10 = 144 * v8;
          v11 = &v4->m_toiEvents.m_data[v5];
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
    while ( v2 < v4->m_toiEvents.m_size );
  }
}

// File Line: 1200
// RVA: 0xD6E820
void __fastcall hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(hkpContinuousSimulation *this, hkpEntity **entities, int numEntities, hkpProcessCollisionInput *input, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection)
{
  hkpProcessCollisionInput *v5; // r12
  hkpSimulationIsland *v6; // rdi
  __int64 v7; // rbx
  hkpContinuousSimulation *v8; // r13
  int v9; // er14
  hkLifoAllocator *v10; // rax
  char *v11; // r15
  int v12; // edx
  char *v13; // rcx
  signed int v14; // esi
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // rdi
  unsigned __int64 v20; // rsi
  int v21; // er14
  __int64 v22; // rdi
  hkpSimulationIsland **v23; // rcx
  hkpAgentNnEntry *v24; // rbx
  hkpCollisionDispatcher *v25; // rdx
  signed __int64 v26; // rcx
  signed __int64 v27; // rcx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  signed int v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // er8
  int v35; // [rsp+30h] [rbp-D0h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+38h] [rbp-C8h]
  __int64 v37; // [rsp+48h] [rbp-B8h]
  hkpSimulationIsland *v38; // [rsp+50h] [rbp-B0h]
  __int64 v39; // [rsp+58h] [rbp-A8h]
  hkpProcessCollisionOutput output; // [rsp+60h] [rbp-A0h]
  hkpEntity **v41; // [rsp+3158h] [rbp+3058h]
  unsigned int v42; // [rsp+3160h] [rbp+3060h]

  v41 = entities;
  v5 = input;
  v6 = (*entities)->m_simulationIsland;
  v7 = numEntities;
  v8 = this;
  v9 = v6->m_entities.m_size;
  v38 = (*entities)->m_simulationIsland;
  v35 = v9;
  if ( v9 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (char *)v10->m_cur;
    v12 = (v9 + 127) & 0xFFFFFF80;
    v13 = &v11[v12];
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
    else
      v10->m_cur = v13;
  }
  else
  {
    v11 = 0i64;
  }
  v14 = v9 | 0x80000000;
  v42 = v9 | 0x80000000;
  hkString::memSet(v11, 0, v9);
  output.m_toi.m_time.m_storage = 3.40282e38;
  output.m_toi.m_properties.0 = 0i64;
  output.m_constraintOwner.m_storage = (hkpConstraintOwner *)&v6->vfptr;
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "TtNarrowPhaseTOI";
    v17 = __rdtsc();
    v18 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v15[1] = v18;
  }
  v19 = 0i64;
  v39 = v7;
  v37 = 0i64;
  if ( v7 <= 0 )
    goto $END_4;
  while ( 1 )
  {
    v20 = (unsigned __int64)v41[v19];
    v11[*(unsigned __int16 *)(v20 + 244)] = 1;
    entries.m_data = 0i64;
    entries.m_size = 0;
    entries.m_capacityAndFlags = 2147483648;
    hkpLinkedCollidable::getCollisionEntriesSorted((hkpLinkedCollidable *)(v20 + 32), &entries);
    v21 = 0;
    if ( entries.m_size > 0 )
      break;
LABEL_25:
    entries.m_size = 0;
    if ( entries.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entries.m_data,
        16 * entries.m_capacityAndFlags);
    ++v19;
    entries.m_data = 0i64;
    entries.m_capacityAndFlags = 2147483648;
    v37 = v19;
    if ( v19 >= v7 )
      goto LABEL_31;
  }
  v22 = 0i64;
  while ( 1 )
  {
    v23 = (hkpSimulationIsland **)((char *)entries.m_data[v22].m_partner + entries.m_data[v22].m_partner->m_ownerOffset);
    if ( v23[37] != v38 || !v11[*((unsigned __int16 *)v23 + 122)] )
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
  v24 = entries.m_data[v22].m_agentEntry;
  v25 = v8->m_world->m_collisionDispatcher;
  v26 = (signed __int64)v24->m_collisionQualityIndex << 6;
  if ( !*(unsigned int *)((char *)&v25->m_collisionQualityInfo[0].m_useContinuousPhysics.m_storage + v26)
    || *(&v25->m_collisionQualityInfo[0].m_useSimpleToiHandling.m_bool + v26) )
  {
    if ( !hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&entitiesNeedingPsiCollisionDetection->m_map.m_elem,
            *(unsigned int *)(v20 + 308),
            0i64) )
    {
      hkReferencedObject::addReference((hkReferencedObject *)v20);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&entitiesNeedingPsiCollisionDetection->m_map.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        *(unsigned int *)(v20 + 308),
        v20);
    }
    goto LABEL_23;
  }
  output.m_toi.m_time.m_storage = 3.40282e38;
  output.m_potentialContacts.m_storage = 0i64;
  output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
  v27 = (signed __int64)v5->m_dispatcher.m_storage + 64 * (v24->m_collisionQualityIndex + 161i64);
  v5->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v27;
  v5->m_createPredictiveAgents.m_storage = *(_DWORD *)(v27 + 16);
  hkAgentNnMachine_ProcessAgent(v24, v5, &output, v24->m_contactMgr, (__int64)v5);
  if ( hkOutOfMemoryState != 1 )
  {
    if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
      ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v24->m_contactMgr->vfptr[3].__vecDelDtor)(
        v24->m_contactMgr,
        v24->m_collidable[0],
        v24->m_collidable[1],
        v5,
        &output);
    if ( output.m_toi.m_time.m_storage != 3.40282e38 )
      hkpContinuousSimulation::addToiEvent(v8, &output, v24);
    goto LABEL_23;
  }
  entries.m_size = 0;
  if ( entries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      entries.m_data,
      16 * entries.m_capacityAndFlags);
LABEL_31:
  v14 = v42;
  v9 = v35;
$END_4:
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v30 = __rdtsc();
    v31 = (signed __int64)(v29 + 2);
    *(_DWORD *)(v31 - 8) = v30;
    v28[1] = v31;
  }
  v32 = (v9 + 127) & 0xFFFFFF80;
  v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v34 = (v32 + 15) & 0xFFFFFFF0;
  if ( v32 > v33->m_slabSize || &v11[v34] != v33->m_cur || v33->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v33, v11, v34);
  else
    v33->m_cur = v11;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v11,
      v14 & 0x3FFFFFFF);
}

// File Line: 1306
// RVA: 0xD6EC60
void __usercall hkpContinuousSimulation::collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(hkpContinuousSimulation *this@<rcx>, hkpProcessCollisionInput *input@<rdx>, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection@<r8>, __int64 a4@<r12>)
{
  hkpContinuousSimulation *v4; // rsi
  hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *v5; // rbx
  hkpProcessCollisionInput *v6; // r14
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r9
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 v12; // r9
  signed int v13; // edx
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v15; // rax
  signed int v16; // er12
  unsigned __int64 v17; // rdi
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v18; // r13
  __int64 v19; // r15
  __int64 v20; // r14
  unsigned __int64 v21; // rbx
  signed __int64 v22; // rcx
  unsigned __int64 v23; // rsi
  int v24; // ecx
  unsigned __int64 *v25; // rax
  __int64 v26; // r9
  int v27; // edx
  __int64 v28; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v29; // rax
  __int64 v30; // r12
  int v31; // ebx
  __int64 v32; // rdi
  hkpAgentNnEntry *v33; // rsi
  hkpConstraintOwner *v34; // rcx
  hkpCollisionDispatcher *v35; // rcx
  hkpWorld *v36; // rbx
  bool v37; // zf
  _QWORD *v38; // rax
  _QWORD *v39; // rcx
  _QWORD *v40; // r8
  unsigned __int64 v41; // rax
  signed __int64 v42; // rcx
  char *array; // [rsp+30h] [rbp-D0h]
  int v44; // [rsp+38h] [rbp-C8h]
  int v45; // [rsp+3Ch] [rbp-C4h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v46; // [rsp+40h] [rbp-C0h]
  hkpProcessCollisionOutput output; // [rsp+50h] [rbp-B0h]
  __int64 v48; // [rsp+3100h] [rbp+3000h]
  hkpContinuousSimulation *v49; // [rsp+3130h] [rbp+3030h]
  hkpProcessCollisionInput *v50; // [rsp+3138h] [rbp+3038h]
  hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *v51; // [rsp+3140h] [rbp+3040h]

  v51 = entitiesNeedingPsiCollisionDetection;
  v50 = input;
  v49 = this;
  v4 = this;
  v48 = a4;
  v5 = entitiesNeedingPsiCollisionDetection;
  v6 = input;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtRecollide PSI";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  ++v4->m_world->m_criticalOperationsLockCount;
  v12 = v5->m_map.m_hashMod;
  v46.m_elem = 0i64;
  v46.m_numElems = 0;
  v46.m_hashMod = -1;
  array = 0i64;
  v44 = 0;
  v45 = 2147483648;
  v13 = 0;
  v14 = 0i64;
  if ( (signed int)v12 >= 0 )
  {
    v15 = v5->m_map.m_elem;
    do
    {
      if ( v15->key != -1i64 )
        break;
      ++v14;
      ++v13;
      ++v15;
    }
    while ( v14 <= v12 );
  }
  v16 = v13;
  if ( v13 <= (signed int)v12 )
  {
    do
    {
      v17 = v5->m_map.m_elem[v16].val;
      v18 = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked((hkpLinkedCollidable *)(v17 + 32));
      v19 = v18->m_size;
      if ( v19 > 0 )
      {
        v20 = 0i64;
        do
        {
          v21 = (unsigned __int64)v18->m_data[v20].m_agentEntry;
          if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                &v46,
                                (unsigned __int64)v18->m_data[v20].m_agentEntry,
                                0i64) )
          {
            v22 = (signed __int64)v4->m_world->m_collisionDispatcher + 64 * (*(char *)(v21 + 16) + 161i64);
            if ( !*(_DWORD *)(v22 + 16)
              || *(_BYTE *)(v22 + 20)
              && COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)(v17 + 448), *(__m128 *)(v17 + 448), 255)) == 0.0 )
            {
              v23 = *(_QWORD *)(v17 + 296);
              if ( *(_BYTE *)(v17 + 352) == 5 )
                v23 = *(_QWORD *)((v17 ^ (*(_QWORD *)(v21 + 32) + *(char *)(*(_QWORD *)(v21 + 32) + 32i64)) ^ (*(_QWORD *)(v21 + 24) + *(char *)(*(_QWORD *)(v21 + 24) + 32i64)))
                                + 0x128);
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                &v46,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v21,
                1ui64);
              v24 = v44;
              if ( v44 == (v45 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                v24 = v44;
              }
              v25 = (unsigned __int64 *)&array[16 * v24];
              v44 = v24 + 1;
              v25[1] = v23;
              v4 = v49;
              *v25 = v21;
            }
          }
          ++v20;
          --v19;
        }
        while ( v19 );
        v5 = v51;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)v17);
      v26 = v5->m_map.m_hashMod;
      v27 = v16 + 1;
      v28 = v16 + 1;
      if ( v28 <= v26 )
      {
        v29 = &v5->m_map.m_elem[v27];
        do
        {
          if ( v29->key != -1i64 )
            break;
          ++v28;
          ++v27;
          ++v29;
        }
        while ( v28 <= v26 );
      }
      v16 = v27;
    }
    while ( v27 <= (signed int)v26 );
    v6 = v50;
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v5->m_map.m_elem);
  v30 = v48;
  v31 = 0;
  if ( v44 > 0 )
  {
    v32 = 0i64;
    do
    {
      v33 = *(hkpAgentNnEntry **)&array[v32];
      v34 = *(hkpConstraintOwner **)&array[v32 + 8];
      output.m_toi.m_properties.0 = 0i64;
      output.m_constraintOwner.m_storage = v34;
      v35 = v6->m_dispatcher.m_storage;
      output.m_toi.m_time.m_storage = 3.40282e38;
      output.m_potentialContacts.m_storage = 0i64;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      v6->m_collisionQualityInfo.m_storage = &v35->m_collisionQualityInfo[1];
      v6->m_createPredictiveAgents.m_storage = v35->m_collisionQualityInfo[(signed __int64)v33->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
      hkAgentNnMachine_ProcessAgent(v33, v6, &output, v33->m_contactMgr, v30);
      if ( hkOutOfMemoryState == 1 )
        break;
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v33->m_contactMgr->vfptr[3].__vecDelDtor)(
          v33->m_contactMgr,
          v33->m_collidable[0],
          v33->m_collidable[1],
          v6,
          &output);
      ++v31;
      v32 += 16i64;
    }
    while ( v31 < v44 );
  }
  v36 = v49->m_world;
  v37 = v36->m_criticalOperationsLockCount-- == 1;
  if ( v37 && !v36->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v36->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v36);
    if ( v36->m_pendingOperationQueueCount == 1 && v36->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v36);
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  v40 = v38;
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "Et";
    v41 = __rdtsc();
    v42 = (signed __int64)(v39 + 2);
    *(_DWORD *)(v42 - 8) = v41;
    v40[1] = v42;
  }
  v44 = 0;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v45);
  array = 0i64;
  v45 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v46,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v46);
}
  v45 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned 

// File Line: 1590
// RVA: 0xD6F0E0
void __fastcall hkpContinuousSimulation::handleSimpleToi(hkpContinuousSimulation *this, hkpWorld *world, hkpToiEvent *event, float physicsDeltaTime)
{
  hkpContinuousSimulation *v4; // r14
  hkpToiEvent *v5; // r13
  hkpWorld *v6; // rbx
  _QWORD *v7; // rax
  __int64 v8; // r8
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpDynamicsContactMgr *v13; // rcx
  signed __int64 v14; // r15
  signed __int64 v15; // r12
  hkpEntity *v16; // rbp
  int v17; // esi
  __int64 v18; // rdi
  signed __int64 v19; // rbx
  hkpToiEvent *v20; // rdx
  hkpEntity *v21; // rax
  __int64 v22; // rax
  hkpToiEvent *v23; // rcx
  signed __int64 v24; // rdx
  signed __int64 v25; // r8
  signed __int64 v26; // rcx
  signed __int64 v27; // r8
  __int64 v28; // rax
  hkpEntity *v29; // rax
  hkpWorld *v31; // rbx
  bool v32; // zf
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  unsigned int v37; // [rsp+38h] [rbp-60h]
  char v38[16]; // [rsp+40h] [rbp-58h]
  char *v39; // [rsp+50h] [rbp-48h]
  int v40; // [rsp+58h] [rbp-40h]
  int v41; // [rsp+5Ch] [rbp-3Ch]
  char v42; // [rsp+60h] [rbp-38h]
  hkpWorld *v43; // [rsp+A8h] [rbp+10h]

  v43 = world;
  v4 = this;
  v5 = event;
  v6 = world;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v7[1];
  v10 = v7;
  if ( (unsigned __int64)v9 < v7[3] )
  {
    *v9 = "TtSimpleTOI";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  ++v4->m_world->m_criticalOperationsLockCount;
  v13 = v5->m_contactMgr;
  v39 = &v42;
  v40 = 0;
  v41 = -2147483646;
  ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpToiEvent *, __int64, char **))v13->vfptr[9].__vecDelDtor)(
    v13,
    v5,
    v8,
    &v39);
  v37 = 0;
  v14 = (signed __int64)v5->m_entities;
  v15 = 2i64;
  do
  {
    v16 = *(hkpEntity **)v14;
    if ( *(_BYTE *)(*(_QWORD *)v14 + 74i64) == 3 )
    {
      hkSweptTransformUtil::freezeMotionState(v5->m_time, &v16->m_motion.m_motionState);
      hkpWorldAgentUtil::invalidateTim(v16, (hkpCollisionInput *)&v6->m_collisionInput->m_dispatcher);
      v17 = v4->m_toiEvents.m_size - 1;
      v18 = v17;
      if ( v17 >= 0 )
      {
        v19 = v17;
        do
        {
          v20 = v4->m_toiEvents.m_data;
          v21 = v20[v19].m_entities[0];
          if ( v21 == v16 || v20[v19].m_entities[1] == v16 )
          {
            if ( v21->m_motion.m_type.m_storage == 5 )
              v21 = v20[v19].m_entities[1];
            ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v20[v19].m_contactMgr->vfptr[4].__vecDelDtor)(
              v20[v19].m_contactMgr,
              v21->m_simulationIsland,
              &v20[v19].m_properties);
            v22 = --v4->m_toiEvents.m_size;
            if ( (_DWORD)v22 != v17 )
            {
              v23 = v4->m_toiEvents.m_data;
              v24 = (signed __int64)&v23[v19];
              v25 = (signed __int64)&v23[v22];
              v26 = 18i64;
              v27 = v25 - v24;
              do
              {
                v28 = *(_QWORD *)(v27 + v24);
                v24 += 8i64;
                *(_QWORD *)(v24 - 8) = v28;
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
        v6 = v43;
      }
      *(_QWORD *)&v38[8 * v37++] = v16;
    }
    v14 += 8i64;
    --v15;
  }
  while ( v15 );
  v29 = v5->m_entities[0];
  if ( v29->m_motion.m_type.m_storage == 5 )
    v29 = v5->m_entities[1];
  ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v5->m_contactMgr->vfptr[4].__vecDelDtor)(
    v5->m_contactMgr,
    v29->m_simulationIsland,
    &v5->m_properties);
  if ( v37 )
    ((void (__fastcall *)(hkpContinuousSimulation *, char *, _QWORD, hkpProcessCollisionInput *, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *))v4->vfptr[9].__first_virtual_table_function__)(
      v4,
      v38,
      v37,
      v6->m_collisionInput,
      &v4->m_entitiesNeedingPsiCollisionDetection);
  v40 = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v39,
      8 * v41);
  v31 = v4->m_world;
  v32 = v31->m_criticalOperationsLockCount-- == 1;
  if ( v32 && !v31->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v31->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v31);
    if ( v31->m_pendingOperationQueueCount == 1 && v31->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v31);
  }
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v35 = __rdtsc();
    v36 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v36 - 8) = v35;
    v33[1] = v36;
  }
}

// File Line: 1663
// RVA: 0xD6F410
void __fastcall hkpContinuousSimulation::simulateToi(hkpContinuousSimulation *this, hkpWorld *world, hkpToiEvent *event, float physicsDeltaTime, float rotateNormal)
{
  hkpContinuousSimulation *v5; // r15
  hkpToiResourceMgr *v6; // rcx
  hkpWorld *v7; // rbx
  signed __int64 v8; // rdi
  hkpToiEvent *v9; // r12
  _QWORD *v10; // r8
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rax
  hkpEntity *v13; // r13
  hkpSimulationIsland *v14; // r13
  int v15; // er14
  hkLifoAllocator *v16; // rax
  char *v17; // rsi
  int v18; // ebx
  char *v19; // rcx
  hkpEntity *v20; // rdx
  hkpSimulationIsland *v21; // rdx
  int v22; // er15
  __int64 v23; // r14
  signed __int64 v24; // rbx
  __int64 v25; // rdx
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  signed __int64 v30; // rdx
  signed __int64 v31; // rcx
  signed __int64 v32; // r8
  __int64 v33; // rax
  hkLifoAllocator *v34; // rax
  int v35; // er8
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  signed __int64 v43; // rcx
  unsigned int v44; // ebx
  hkpEntity **v45; // rdi
  int v46; // er14
  __int64 i; // rsi
  hkReferencedObject *v48; // rcx
  int v49; // ebx
  hkpProcessCollisionInput *v50; // rsi
  hkpWorld *v51; // rbx
  bool v52; // zf
  _QWORD *v53; // r8
  _QWORD *v54; // rcx
  unsigned __int64 v55; // rax
  signed __int64 v56; // rcx
  unsigned int v57; // [rsp+50h] [rbp-80h]
  hkResult result; // [rsp+54h] [rbp-7Ch]
  char *buffer; // [rsp+58h] [rbp-78h]
  hkStepInfo stepInfo; // [rsp+60h] [rbp-70h]
  hkpToiResources toiResources; // [rsp+70h] [rbp-60h]
  float v62; // [rsp+A8h] [rbp-28h]
  float v63; // [rsp+B0h] [rbp-20h]
  int v64; // [rsp+B4h] [rbp-1Ch]
  float v65; // [rsp+B8h] [rbp-18h]
  int v66; // [rsp+E0h] [rbp+10h]
  int v67; // [rsp+E4h] [rbp+14h]
  __m128 v68; // [rsp+F0h] [rbp+20h]
  hkpViolatedConstraintArray *v69; // [rsp+108h] [rbp+38h]
  void (__fastcall *v70)(hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkpSolverResults *, int); // [rsp+118h] [rbp+48h]
  hkpSolverInfo solverInfo; // [rsp+120h] [rbp+50h]
  hkArray<hkpEntity *,hkContainerHeapAllocator> activeEntities; // [rsp+270h] [rbp+1A0h]
  char v73; // [rsp+280h] [rbp+1B0h]
  hkpConstraintSolverResources solverResources; // [rsp+480h] [rbp+3B0h]
  hkpContinuousSimulation *v75; // [rsp+5B0h] [rbp+4E0h]
  hkpWorld *worlda; // [rsp+5B8h] [rbp+4E8h]
  float vars0; // [rsp+5D0h] [rbp+500h]

  v5 = this;
  v6 = this->m_toiResourceMgr;
  v7 = world;
  toiResources.m_maxNumActiveEntities = 1000;
  toiResources.m_maxNumConstraints = 1000;
  v57 = 4;
  result.m_enum = 4;
  buffer = 0i64;
  stepInfo.m_startTime.m_storage = 0.0;
  *(_QWORD *)&stepInfo.m_deltaTime.m_storage = 0i64;
  *(_QWORD *)&toiResources.m_minPriorityToProcess = 0i64;
  v8 = (signed __int64)&v5->m_toiEvents;
  v9 = event;
  if ( *(_DWORD *)((__int64 (__fastcall *)(hkpToiResourceMgr *, unsigned int *, hkpToiEvent *, hkArray<hkpToiEvent,hkContainerHeapAllocator> *, hkpToiResources *))v6->vfptr[1].__first_virtual_table_function__)(
                    v6,
                    &v57,
                    event,
                    &v5->m_toiEvents,
                    &toiResources) != 1 )
  {
    ++v5->m_world->m_criticalOperationsLockCount;
    stepInfo.m_startTime.m_storage = v9->m_time;
    activeEntities.m_data = (hkpEntity **)&v73;
    activeEntities.m_size = 0;
    v70 = hkpBeginConstraints;
    activeEntities.m_capacityAndFlags = -2147483584;
    stepInfo.m_endTime.m_storage = hkpWorld::getCurrentPsiTime(v7);
    stepInfo.m_deltaTime.m_storage = stepInfo.m_endTime.m_storage - stepInfo.m_startTime.m_storage;
    stepInfo.m_invDeltaTime.m_storage = 1.0 / (float)(stepInfo.m_endTime.m_storage - stepInfo.m_startTime.m_storage);
    hkpSolverInfo::operator=(&solverInfo, &v7->m_dynamicsStepInfo.m_solverInfo);
    v69 = v7->m_violatedConstraintArray;
    solverInfo.m_globalAccelerationPerSubStep = 0i64;
    solverInfo.m_globalAccelerationPerStep = 0i64;
    solverInfo.m_frictionTau = FLOAT_0_25;
    HIDWORD(toiResources.m_priorityClassMap) = LODWORD(stepInfo.m_deltaTime.m_storage);
    solverInfo.m_numSteps = 1;
    solverInfo.m_dampDivFrictionTau = FLOAT_5_5999999;
    solverInfo.m_invDeltaTime = 1.0 / physicsDeltaTime;
    *(float *)&toiResources.m_priorityClassMap = 1.0 / physicsDeltaTime;
    solverInfo.m_integrateVelocityFactor = (hkVector4f)_xmm;
    toiResources.m_priorityClassRatios = (const float *)__PAIR__(1065353216, LODWORD(stepInfo.m_invDeltaTime.m_storage));
    solverInfo.m_dampDivTau = FLOAT_2_8;
    solverInfo.m_deltaTime = physicsDeltaTime;
    solverInfo.m_numMicroSteps = 1;
    *((float *)&toiResources.m_scratchpadSize + 1) = solverInfo.m_invNumMicroSteps * physicsDeltaTime;
    *(float *)&toiResources.m_scratchpadSize = physicsDeltaTime;
    v62 = solverInfo.m_invNumMicroSteps;
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
    v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = v10[1];
    if ( v11 < v10[3] )
    {
      *(_QWORD *)v11 = "LtTOI";
      *(_QWORD *)(v11 + 16) = "StSolveToi";
      v12 = __rdtsc();
      *(_DWORD *)(v11 + 8) = v12;
      v10[1] = v11 + 24;
    }
    v13 = v9->m_entities[0];
    if ( v13->m_motion.m_type.m_storage == 5 )
      v14 = v9->m_entities[1]->m_simulationIsland;
    else
      v14 = v13->m_simulationIsland;
    v15 = v14->m_entities.m_size;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (char *)v16->m_cur;
    v18 = (v15 + 127) & 0xFFFFFF80;
    v57 = (v15 + 127) & 0xFFFFFF80;
    v19 = &v17[v18];
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
      v17 = (char *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
    else
      v16->m_cur = v19;
    *(_QWORD *)&toiResources.m_maxNumActiveEntities = v17;
    toiResources.m_numToiSolverIterations = v15;
    hkString::memSet(v17, 0, v15);
    hkLs_localizedSolveToi(
      &result,
      &toiResources,
      &solverResources,
      v9,
      v5->m_toiResourceMgr,
      worlda,
      &activeEntities,
      (hkFixedArray<unsigned char> *)&toiResources.m_maxNumActiveEntities,
      vars0);
    hkpConstraintSolverSetup::shutdownSolver(&solverResources);
    v20 = v9->m_entities[0];
    if ( v20->m_motion.m_type.m_storage == 5 )
      v21 = v9->m_entities[1]->m_simulationIsland;
    else
      v21 = v20->m_simulationIsland;
    ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpSimulationIsland *, hkpContactPointProperties *))v9->m_contactMgr->vfptr[4].__vecDelDtor)(
      v9->m_contactMgr,
      v21,
      &v9->m_properties);
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
        v24 = 144i64 * v22;
        do
        {
          v25 = *(_QWORD *)v8;
          v26 = *(_QWORD *)(v24 + *(_QWORD *)v8 + 16);
          if ( *(hkpSimulationIsland **)(v26 + 296) == v14 && v17[*(unsigned __int16 *)(v26 + 244)] == 16
            || (v27 = *(_QWORD *)(v24 + v25 + 24), *(hkpSimulationIsland **)(v27 + 296) == v14)
            && v17[*(unsigned __int16 *)(v27 + 244)] == 16 )
          {
            v28 = *(_QWORD *)(v24 + v25 + 16);
            if ( *(_BYTE *)(v28 + 352) == 5 )
              v28 = *(_QWORD *)(v24 + v25 + 24);
            (*(void (__fastcall **)(_QWORD, _QWORD, signed __int64))(**(_QWORD **)(v24 + v25 + 32) + 64i64))(
              *(_QWORD *)(v24 + v25 + 32),
              *(_QWORD *)(v28 + 296),
              v24 + v25 + 40);
            v29 = (signed int)--*(_DWORD *)(v8 + 8);
            if ( (_DWORD)v29 != v22 )
            {
              v30 = v24 + *(_QWORD *)v8;
              v31 = 18i64;
              v32 = *(_QWORD *)v8 + 144 * v29 - v30;
              do
              {
                v33 = *(_QWORD *)(v32 + v30);
                v30 += 8i64;
                *(_QWORD *)(v30 - 8) = v33;
                --v31;
              }
              while ( v31 );
            }
          }
          --v22;
          v24 -= 144i64;
          --v23;
        }
        while ( v23 >= 0 );
        v18 = v57;
      }
      hkReferencedObject::addReferences((hkReferencedObject *const *)activeEntities.m_data, activeEntities.m_size, 8);
      v5 = v75;
    }
    v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = (v18 + 15) & 0xFFFFFFF0;
    if ( v18 > v34->m_slabSize || &v17[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v17 )
      hkLifoAllocator::slowBlockFree(v34, v17, v35);
    else
      v34->m_cur = v17;
    ((void (__fastcall *)(hkpToiResourceMgr *, hkpToiEvent *, signed __int64, hkpToiResources *))v5->m_toiResourceMgr->vfptr[3].__vecDelDtor)(
      v5->m_toiResourceMgr,
      v9,
      v8,
      &toiResources);
    v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v37 = (_QWORD *)v36[1];
    if ( (unsigned __int64)v37 < v36[3] )
    {
      *v37 = "StPendingOperations";
      v38 = __rdtsc();
      v39 = (signed __int64)(v37 + 2);
      *(_DWORD *)(v39 - 8) = v38;
      v36[1] = v39;
    }
    v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v41 = (_QWORD *)v40[1];
    if ( (unsigned __int64)v41 < v40[3] )
    {
      *v41 = "StCollide";
      v42 = __rdtsc();
      v43 = (signed __int64)(v41 + 2);
      *(_DWORD *)(v43 - 8) = v42;
      v40[1] = v43;
    }
    v44 = activeEntities.m_size;
    if ( activeEntities.m_size )
    {
      v45 = activeEntities.m_data;
      v46 = activeEntities.m_size - 1;
      for ( i = activeEntities.m_size - 1; i >= 0; --i )
      {
        v48 = (hkReferencedObject *)&v45[i]->vfptr;
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
      v50 = worlda->m_collisionInput;
      if ( v44 )
      {
        hkpContinuousSimulation::collideEntitiesBroadPhaseContinuous(v5, v45, v44, worlda, 0i64);
        if ( hkOutOfMemoryState != 1 )
          ((void (__fastcall *)(hkpContinuousSimulation *, hkpEntity **, _QWORD, hkpProcessCollisionInput *, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *))v5->vfptr[9].__first_virtual_table_function__)(
            v5,
            v45,
            v44,
            v50,
            &v5->m_entitiesNeedingPsiCollisionDetection);
        v45 = activeEntities.m_data;
        v44 = activeEntities.m_size;
      }
      hkReferencedObject::removeReferences((hkReferencedObject *const *)v45, v44, 8);
    }
    v51 = v5->m_world;
    v52 = v51->m_criticalOperationsLockCount-- == 1;
    if ( v52 && !v51->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v51->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v51);
      if ( v51->m_pendingOperationQueueCount == 1 && v51->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v51);
    }
    v53 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v54 = (_QWORD *)v53[1];
    if ( (unsigned __int64)v54 < v53[3] )
    {
      *v54 = "lt";
      v55 = __rdtsc();
      v56 = (signed __int64)(v54 + 2);
      *(_DWORD *)(v56 - 8) = v55;
      v53[1] = v56;
    }
    activeEntities.m_size = 0;
    if ( activeEntities.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        activeEntities.m_data,
        8 * activeEntities.m_capacityAndFlags);
  }
}

// File Line: 1798
// RVA: 0xD6FB90
void __fastcall hkpContinuousSimulation::processAgentNnEntries(hkpContinuousSimulation *this, hkpAgentNnEntry *const *entries, int numEntries, hkpProcessCollisionInput *collisionInput, hkpSimulationIsland *island, hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride)
{
  hkpContinuousSimulation *v6; // r13
  hkpProcessCollisionInput *v7; // rbx
  __int64 v8; // rdi
  hkpAgentNnEntry *const *v9; // r12
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r9
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rsi
  __int64 v16; // r14
  hkpAgentNnEntry *v17; // rdi
  hkpCollisionDispatcher *v18; // rcx
  signed __int64 v19; // rax
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  hkpProcessCollisionOutput output; // [rsp+30h] [rbp-30D8h]

  v6 = this;
  v7 = collisionInput;
  v8 = numEntries;
  v9 = entries;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtNarrowPhaseTOI";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = 0i64;
  v16 = v8;
  if ( (signed int)v8 > 0 )
  {
    do
    {
      v17 = v9[v15];
      output.m_toi.m_properties.0 = 0i64;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      output.m_constraintOwner.m_storage = (hkpConstraintOwner *)&island->vfptr;
      output.m_toi.m_time.m_storage = 3.40282e38;
      output.m_potentialContacts.m_storage = 0i64;
      if ( collisionQualityOverride )
      {
        if ( collisionQualityOverride == 1 )
        {
          v19 = (signed __int64)&v7->m_dispatcher.m_storage->m_collisionQualityInfo[1];
        }
        else
        {
          if ( collisionQualityOverride != 2 )
            goto LABEL_12;
          v18 = v7->m_dispatcher.m_storage;
          v7->m_collisionQualityInfo.m_storage = &v7->m_dispatcher.m_storage->m_collisionQualityInfo[7];
          if ( v17->m_collisionQualityIndex != 6 )
            goto LABEL_12;
          v19 = (signed __int64)&v18->m_collisionQualityInfo[6];
        }
      }
      else
      {
        v19 = (signed __int64)v7->m_dispatcher.m_storage + 64 * (v17->m_collisionQualityIndex + 161i64);
      }
      v7->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v19;
LABEL_12:
      v7->m_createPredictiveAgents.m_storage = v7->m_dispatcher.m_storage->m_collisionQualityInfo[(signed __int64)v17->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
      hkAgentNnMachine_ProcessAgent(v17, v7, &output, v17->m_contactMgr, (__int64)v9);
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v17->m_contactMgr->vfptr[3].__vecDelDtor)(
          v17->m_contactMgr,
          v17->m_collidable[0],
          v17->m_collidable[1],
          v7,
          &output);
      if ( output.m_toi.m_time.m_storage != 3.40282e38 )
        hkpContinuousSimulation::addToiEvent(v6, &output, v17);
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
    v24 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v24 - 8) = v23;
    v22[1] = v24;
  }
}

// File Line: 1866
// RVA: 0xD719D0
void __fastcall hkLs_collectAgentEntriesToProcess(hkpEntity *entity, hkpConstraintInstance::ConstraintPriority minPriorityToProcess, float time, hkFixedArray<unsigned char> *entityState, hkLocalArray<hkpAgentNnEntry *> *entriesOut)
{
  hkpConstraintInstance::ConstraintPriority v5; // er15
  hkFixedArray<unsigned char> *v6; // r14
  int v7; // er9
  int v8; // esi
  __int64 v9; // rdi
  char *v10; // rbp
  __int64 v11; // r8
  char v12; // dl
  __int64 v13; // rax
  char *v14; // [rsp+20h] [rbp-38h]
  int v15; // [rsp+28h] [rbp-30h]
  int v16; // [rsp+2Ch] [rbp-2Ch]

  v5 = minPriorityToProcess;
  v6 = entityState;
  v14 = 0i64;
  v15 = 0;
  v16 = 2147483648;
  hkpLinkedCollidable::getCollisionEntriesSorted(
    &entity->m_collidable,
    (hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *)&v14);
  v7 = v15;
  v8 = 0;
  if ( v15 > 0 )
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = v14;
      if ( v5 <= *(unsigned __int8 *)(*(_QWORD *)&v14[v9] + 16i64) )
      {
        v11 = *(_QWORD *)&v14[v9 + 8] + *(char *)(*(_QWORD *)&v14[v9 + 8] + 32i64);
        v12 = *(_BYTE *)(v11 + 352);
        if ( v12 == 5 )
          goto LABEL_9;
        if ( v6->m_data.m_storage[*(unsigned __int16 *)(v11 + 244)] < 8u )
          break;
      }
LABEL_12:
      ++v8;
      v9 += 16i64;
      if ( v8 >= v7 )
        goto LABEL_13;
    }
    if ( v12 != 5 )
    {
      v13 = *(unsigned __int16 *)(v11 + 244);
      if ( !v6->m_data.m_storage[v13] )
      {
        v6->m_data.m_storage[v13] = 1;
        hkSweptTransformUtil::lerp2((hkSweptTransformf *)(v11 + 432), time, (hkTransformf *)(v11 + 368));
      }
    }
LABEL_9:
    if ( entriesOut->m_size == (entriesOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, entriesOut, 8);
    entriesOut->m_data[entriesOut->m_size++] = *(hkpAgentNnEntry **)&v10[v9];
    v7 = v15;
    goto LABEL_12;
  }
LABEL_13:
  v15 = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v14,
      16 * v16);
}

// File Line: 1929
// RVA: 0xD70E50
signed __int64 __fastcall hkLs_areVelocitiesOk(float psiTimeLeft, hkpConstraintSchemaInfo *constraintStatus, const float *velocities, int numVelocities, hkpProcessCollisionInput *processInput)
{
  signed __int64 result; // rax
  int v6; // ecx
  float i; // xmm2_4

  result = 0xFFFFFFFFi64;
  v6 = 0;
  for ( i = processInput->m_dispatcher.m_storage->m_collisionQualityInfo[(signed __int64)constraintStatus->m_constraint->m_priority.m_storage].m_maxContraintViolation
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
void __fastcall hkLs_toiCheckValidityOfConstraints(hkpConstraintSolverResources *solverResources, hkpProcessCollisionInput *processInput, hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus, int *firstNonActiveConstraintStatus, hkpConstraintInstance::ConstraintPriority minPriorityToProcess, hkFixedArray<unsigned char> *entityState, hkArray<hkpEntity *,hkContainerHeapAllocator> *touchedEntities, hkArray<hkpEntity *,hkContainerHeapAllocator> *toBeActivated)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v8; // rsi
  hkpConstraintSolverResources *v9; // r12
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v10; // r13
  int v11; // ebx
  hkLifoAllocator *v12; // rax
  _OWORD *v13; // r14
  int v14; // ebx
  char *v15; // rcx
  int v16; // edi
  _OWORD *v17; // r8
  int v18; // er9
  __int64 v19; // r10
  _OWORD *v20; // rax
  hkpEntity *v21; // rdx
  char *v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  int *v25; // r11
  signed __int64 v26; // rbp
  signed __int64 v27; // rbx
  hkpConstraintSchemaInfo *v28; // r14
  __int64 v29; // rcx
  int v30; // eax
  hkpConstraintSchemaInfo *v31; // r10
  hkpConstraintInstance *v32; // rdx
  hkpJacobianSchema *v33; // r8
  __int64 v34; // r9
  int v35; // eax
  __int128 *v36; // rdx
  __int64 v37; // r8
  __int128 v38; // xmm0
  hkpEntity *v39; // rcx
  char *v40; // rax
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // er8
  hkpEntity *v44; // [rsp+30h] [rbp-448h]
  float velocities; // [rsp+40h] [rbp-438h]
  hkpProcessCollisionInput *processInputa; // [rsp+488h] [rbp+10h]
  _OWORD *v47; // [rsp+490h] [rbp+18h]
  int *v48; // [rsp+498h] [rbp+20h]

  v48 = firstNonActiveConstraintStatus;
  processInputa = processInput;
  v8 = touchedEntities;
  v9 = solverResources;
  v10 = constraintStatus;
  v11 = 2 * touchedEntities->m_size;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = v12->m_cur;
  v14 = (16 * v11 + 127) & 0xFFFFFF80;
  v47 = v13;
  v15 = (char *)v13 + v14;
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
  {
    v13 = hkLifoAllocator::allocateFromNewSlab(v12, v14);
    v47 = v13;
  }
  else
  {
    v12->m_cur = v15;
  }
  v16 = 0;
  v17 = v13;
  v18 = 0;
  if ( touchedEntities->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v17 + 1;
      ++v18;
      v21 = touchedEntities->m_data[v19];
      v17 += 2;
      ++v19;
      v22 = &v9->m_accumulators->m_type.m_storage + v21->m_solverData;
      *(v17 - 2) = *((_OWORD *)v22 + 1);
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
  v25 = v48;
  v26 = *v48;
  if ( (signed int)v26 < v10->m_size )
  {
    v27 = v26;
    while ( 1 )
    {
      v28 = &v10->m_data[v27];
      if ( minPriorityToProcess <= (unsigned __int8)v28->m_constraint->m_priority.m_storage )
      {
        v44 = v28->m_constraint->m_internal->m_entities[entityState->m_data.m_storage[v28->m_constraint->m_internal->m_entities[0]->m_storageIndex] == 16];
        if ( !(entityState->m_data.m_storage[v44->m_storageIndex] & 4) )
        {
          v35 = hkSolveGetToiViolatingConstraintVelocity(
                  v9->m_solverInfo,
                  v28->m_schema,
                  v9->m_accumulators,
                  256,
                  &velocities);
          if ( hkLs_areVelocitiesOk(v9->m_stepInfo->m_deltaTime.m_storage, v28, &velocities, v35, processInputa) == -1 )
          {
            v25 = v48;
            goto LABEL_18;
          }
          entityState->m_data.m_storage[v44->m_storageIndex] |= 4u;
          if ( toBeActivated->m_size == (toBeActivated->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, toBeActivated, 8);
          v25 = v48;
          toBeActivated->m_data[toBeActivated->m_size++] = v44;
        }
        v29 = *v25;
        v30 = v29 + 1;
        v29 *= 3i64;
        *v25 = v30;
        v31 = v10->m_data;
        v32 = (hkpConstraintInstance *)*((_QWORD *)&v10->m_data->m_constraint + v29);
        v33 = (&v10->m_data->m_schema)[v29];
        v34 = *((_QWORD *)&v10->m_data->m_allowedPenetrationDepth + v29);
        *((_QWORD *)&v31->m_constraint + v29) = v10->m_data[v27].m_constraint;
        (&v31->m_schema)[v29] = v31[v27].m_schema;
        *((_QWORD *)&v31->m_allowedPenetrationDepth + v29) = *(_QWORD *)&v31[v27].m_allowedPenetrationDepth;
        v31[v27].m_constraint = v32;
        v31[v27].m_schema = v33;
        *(_QWORD *)&v31[v27].m_allowedPenetrationDepth = v34;
      }
LABEL_18:
      LODWORD(v26) = v26 + 1;
      ++v27;
      if ( (signed int)v26 >= v10->m_size )
      {
        v8 = touchedEntities;
        v13 = v47;
        break;
      }
    }
  }
  v36 = v13;
  if ( v8->m_size > 0 )
  {
    v37 = 0i64;
    do
    {
      v38 = *v36;
      ++v16;
      v39 = v8->m_data[v37];
      v36 += 2;
      ++v37;
      v40 = &v9->m_accumulators->m_type.m_storage + v39->m_solverData;
      *((_OWORD *)v40 + 1) = v38;
      *((_OWORD *)v40 + 2) = *(v36 - 1);
    }
    while ( v16 < v8->m_size );
  }
  v41 = (32 * v8->m_size + 127) & 0xFFFFFF80;
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v41 + 15) & 0xFFFFFFF0;
  if ( v41 > v42->m_slabSize || (char *)v13 + v43 != v42->m_cur || v42->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v42, v13, v43);
  else
    v42->m_cur = v13;
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
  hkConstraintInternal *v3; // r11
  hkConstraintInternal *v4; // r10
  hkBool *v5; // rax

  v3 = b->m_internal;
  v4 = a->m_internal;
  if ( v4->m_entities[(unsigned __int8)v4->m_whoIsMaster]->m_uid >= v3->m_entities[(unsigned __int8)v3->m_whoIsMaster]->m_uid )
  {
    if ( v4->m_entities[(unsigned __int8)v4->m_whoIsMaster]->m_uid == v3->m_entities[(unsigned __int8)v3->m_whoIsMaster]->m_uid )
      result->m_bool = v4 < v3;
    else
      result->m_bool = 0;
    v5 = result;
  }
  else
  {
    result->m_bool = 1;
    v5 = result;
  }
  return v5;
}

// File Line: 2193
// RVA: 0xD70EC0
void __fastcall hkLs_toiActivateEntitiesAndCheckConstraints(hkpProcessCollisionInput *collisionInput, hkpConstraintInstance::ConstraintPriority minPriorityToProcess, float time, hkArray<hkpEntity *,hkContainerHeapAllocator> *toBeActivated, hkFixedArray<unsigned char> *entityState, hkArray<hkpEntity *,hkContainerHeapAllocator> *newTouchedEntities, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *newTouchedConstraints)
{
  hkpProcessCollisionInput *v7; // rbp
  __int64 v8; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v9; // r15
  hkpConstraintInstance::ConstraintPriority v10; // er14
  hkLifoAllocator *v11; // rax
  hkpAgentNnEntry **v12; // rdx
  unsigned __int64 v13; // rcx
  int v14; // esi
  hkpEntity *v15; // rbx
  __int64 v16; // rax
  __m128i v17; // xmm6
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // er8
  int v21; // eax
  hkpAgentNnEntry **v22; // rdi
  __int64 v23; // rsi
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // er8
  signed __int64 v27; // rcx
  hkpEntity **v28; // rax
  signed int v29; // er15
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
  int v41; // er8
  int v42; // er8
  int v43; // [rsp+30h] [rbp-98h]
  __int64 v44; // [rsp+38h] [rbp-90h]
  hkLocalArray<hkpAgentNnEntry *> entriesOut; // [rsp+40h] [rbp-88h]
  int v46; // [rsp+D0h] [rbp+8h]
  hkpConstraintInstance::ConstraintPriority v47; // [rsp+D8h] [rbp+10h]
  int v48; // [rsp+E0h] [rbp+18h]
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v49; // [rsp+E8h] [rbp+20h]

  v49 = toBeActivated;
  v47 = minPriorityToProcess;
  v7 = collisionInput;
  v8 = 0i64;
  v9 = toBeActivated;
  entriesOut.m_data = 0i64;
  v10 = minPriorityToProcess;
  entriesOut.m_size = 0;
  entriesOut.m_capacityAndFlags = 2147483648;
  entriesOut.m_initialCapacity = 1000;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpAgentNnEntry **)v11->m_cur;
  v13 = (unsigned __int64)(v12 + 1008);
  if ( v11->m_slabSize < 8064 || (void *)v13 > v11->m_end )
    v12 = (hkpAgentNnEntry **)hkLifoAllocator::allocateFromNewSlab(v11, 8064);
  else
    v11->m_cur = (void *)v13;
  entriesOut.m_data = v12;
  entriesOut.m_capacityAndFlags = -2147482648;
  entriesOut.m_localMemory = v12;
  v14 = 0;
  if ( v9->m_size > 0 )
  {
    do
    {
      v15 = v9->m_data[v8];
      v16 = v15->m_storageIndex;
      if ( !entityState->m_data.m_storage[v16] )
      {
        entityState->m_data.m_storage[v16] = 1;
        hkSweptTransformUtil::lerp2(
          &v15->m_motion.m_motionState.m_sweptTransform,
          time,
          &v15->m_motion.m_motionState.m_transform);
      }
      entityState->m_data.m_storage[v15->m_storageIndex] = 8;
      hkLs_collectAgentEntriesToProcess(v15, v10, time, entityState, &entriesOut);
      ++v14;
      ++v8;
    }
    while ( v14 < v9->m_size );
    v12 = entriesOut.m_data;
  }
  v17 = (__m128i)v7->m_stepInfo;
  v18 = 0.0;
  v7->m_stepInfo.m_endTime.m_storage = time;
  v19 = time - v7->m_stepInfo.m_startTime.m_storage;
  v7->m_stepInfo.m_deltaTime.m_storage = v19;
  if ( v19 > 0.0 )
    v18 = 1.0 / v19;
  v20 = entriesOut.m_size;
  v7->m_stepInfo.m_invDeltaTime.m_storage = v18;
  hkpContinuousSimulation::processAgentNnEntries(
    (hkpContinuousSimulation *)(*v9->m_data)->m_world->m_simulation,
    v12,
    v20,
    v7,
    (*v9->m_data)->m_simulationIsland,
    DISABLE_TOIS_AND_EXPAND_MANIFOLD);
  v21 = entriesOut.m_size;
  v22 = entriesOut.m_localMemory;
  _mm_store_si128((__m128i *)&v7->m_stepInfo, v17);
  v23 = 0i64;
  if ( v22 == entriesOut.m_data )
    v21 = 0;
  entriesOut.m_size = v21;
  v24 = (8 * entriesOut.m_initialCapacity + 127) & 0xFFFFFF80;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (v24 + 15) & 0xFFFFFFF0;
  if ( v24 > v25->m_slabSize || (char *)v22 + v26 != v25->m_cur || v25->m_firstNonLifoEnd == v22 )
    hkLifoAllocator::slowBlockFree(v25, v22, v26);
  else
    v25->m_cur = v22;
  entriesOut.m_size = 0;
  if ( entriesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      entriesOut.m_data,
      8 * entriesOut.m_capacityAndFlags);
  v48 = 0;
  if ( v9->m_size > 0 )
  {
    v27 = 0i64;
    v44 = 0i64;
    do
    {
      v28 = v9->m_data;
      v29 = v23;
      v30 = *(__int64 *)((char *)v28 + v27);
      entityState->m_data.m_storage[*(unsigned __int16 *)(v30 + 244)] = 16;
      if ( (unsigned __int16)v23 < *(_WORD *)(v30 + 256) )
      {
        do
        {
          v31 = *(_QWORD *)(v30 + 248);
          if ( v47 <= *(unsigned __int8 *)(*(_QWORD *)(v23 + v31) + 56i64) )
          {
            v32 = (hkpEntity *)(v30 ^ *(_QWORD *)(v23 + v31 + 8) ^ *(_QWORD *)(v23 + v31 + 16));
            if ( *(_BYTE *)((v30 ^ *(_QWORD *)(v23 + v31 + 8) ^ *(_QWORD *)(v23 + v31 + 16)) + 0x160) == 5 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  newTouchedConstraints,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = *(hkpConstraintInstance **)(v23 + v31);
            }
            else if ( entityState->m_data.m_storage[*(unsigned __int16 *)((v30 ^ *(_QWORD *)(v23 + v31 + 8) ^ *(_QWORD *)(v23 + v31 + 16))
                                                                        + 0xF4)] != 16 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  newTouchedConstraints,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = *(hkpConstraintInstance **)(v23 + v31);
              if ( entityState->m_data.m_storage[v32->m_storageIndex] < 2u )
              {
                if ( newTouchedEntities->m_size == (newTouchedEntities->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    newTouchedEntities,
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
      v46 = newTouchedConstraints->m_size;
      v43 = newTouchedEntities->m_size;
      v36 = v23;
      if ( *(_DWORD *)(v30 + 272) > 0 )
      {
        v37 = 0i64;
        do
        {
          v38 = *(_QWORD **)(*(_QWORD *)(v37 + *(_QWORD *)(v30 + 264)) + 96i64);
          if ( v47 <= *(unsigned __int8 *)(*v38 + 56i64) )
          {
            v39 = (hkpEntity *)(v30 ^ v38[1] ^ v38[2]);
            if ( *(_BYTE *)((v30 ^ v38[1] ^ v38[2]) + 0x160) == 5 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  newTouchedConstraints,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = (hkpConstraintInstance *)*v38;
            }
            else if ( entityState->m_data.m_storage[*(unsigned __int16 *)((v30 ^ v38[1] ^ v38[2]) + 0xF4)] != 16 )
            {
              if ( newTouchedConstraints->m_size == (newTouchedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  newTouchedConstraints,
                  8);
              newTouchedConstraints->m_data[newTouchedConstraints->m_size++] = (hkpConstraintInstance *)*v38;
              if ( entityState->m_data.m_storage[v39->m_storageIndex] < 2u )
              {
                if ( newTouchedEntities->m_size == (newTouchedEntities->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    newTouchedEntities,
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
      v9 = v49;
      v27 = v44 + 8;
      ++v48;
      v44 += 8i64;
    }
    while ( v48 < v49->m_size );
  }
}

// File Line: 2361
// RVA: 0xD714A0
void __fastcall hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities(hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus, int *firstNonActiveConstraintStatus, int numOfConstraintsToCheckAtTheEndOfTheList)
{
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v3; // rdi
  int *v4; // rsi
  int v5; // er11
  signed __int64 v6; // rbx
  hkConstraintInternal *v7; // rax
  __int64 v8; // rcx
  int v9; // eax
  hkpConstraintSchemaInfo *v10; // rdx
  hkpConstraintInstance *v11; // r8
  hkpJacobianSchema *v12; // r9
  __int64 v13; // r10

  v3 = constraintStatus;
  v4 = firstNonActiveConstraintStatus;
  v5 = constraintStatus->m_size - numOfConstraintsToCheckAtTheEndOfTheList;
  if ( v5 < constraintStatus->m_size )
  {
    v6 = v5;
    do
    {
      v7 = v3->m_data[v6].m_constraint->m_internal;
      if ( (unsigned __int8)(v7->m_entities[0]->m_motion.m_type.m_storage - 4) <= 1u
        || (unsigned __int8)(v7->m_entities[1]->m_motion.m_type.m_storage - 4) <= 1u )
      {
        v8 = *v4;
        v9 = v8 + 1;
        v8 *= 3i64;
        *v4 = v9;
        v10 = v3->m_data;
        v11 = (hkpConstraintInstance *)*((_QWORD *)&v3->m_data->m_constraint + v8);
        v12 = (&v3->m_data->m_schema)[v8];
        v13 = *((_QWORD *)&v3->m_data->m_allowedPenetrationDepth + v8);
        *((_QWORD *)&v10->m_constraint + v8) = v3->m_data[v6].m_constraint;
        (&v10->m_schema)[v8] = v10[v6].m_schema;
        *((_QWORD *)&v10->m_allowedPenetrationDepth + v8) = *(_QWORD *)&v10[v6].m_allowedPenetrationDepth;
        v10[v6].m_constraint = v11;
        v10[v6].m_schema = v12;
        *(_QWORD *)&v10[v6].m_allowedPenetrationDepth = v13;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v3->m_size );
  }
}

// File Line: 2378
// RVA: 0xD71570
void __fastcall hkLs_toiActivateConstraintsLinkingActivatedEntities(hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus, int *firstNonActiveConstraintStatus, hkFixedArray<unsigned char> *entityState)
{
  signed __int64 v3; // rbx
  hkFixedArray<unsigned char> *v4; // rsi
  int *v5; // r14
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v6; // rdi
  signed __int64 v7; // r11
  hkConstraintInternal *v8; // rax
  __int64 v9; // rcx
  int v10; // eax
  hkpConstraintSchemaInfo *v11; // rdx
  hkpConstraintInstance *v12; // r8
  hkpJacobianSchema *v13; // r9
  __int64 v14; // r10

  v3 = *firstNonActiveConstraintStatus;
  v4 = entityState;
  v5 = firstNonActiveConstraintStatus;
  v6 = constraintStatus;
  if ( (signed int)v3 < constraintStatus->m_size )
  {
    v7 = v3;
    do
    {
      v8 = v6->m_data[v7].m_constraint->m_internal;
      if ( v4->m_data.m_storage[v8->m_entities[0]->m_storageIndex] == 16
        && v4->m_data.m_storage[v8->m_entities[1]->m_storageIndex] == 16 )
      {
        v9 = *v5;
        v10 = v9 + 1;
        v9 *= 3i64;
        *v5 = v10;
        v11 = v6->m_data;
        v12 = (hkpConstraintInstance *)*((_QWORD *)&v6->m_data->m_constraint + v9);
        v13 = (&v6->m_data->m_schema)[v9];
        v14 = *((_QWORD *)&v6->m_data->m_allowedPenetrationDepth + v9);
        *((_QWORD *)&v11->m_constraint + v9) = v6->m_data[v7].m_constraint;
        (&v11->m_schema)[v9] = v11[v7].m_schema;
        *((_QWORD *)&v11->m_allowedPenetrationDepth + v9) = *(_QWORD *)&v11[v7].m_allowedPenetrationDepth;
        v11[v7].m_constraint = v12;
        v11[v7].m_schema = v13;
        *(_QWORD *)&v11[v7].m_allowedPenetrationDepth = v14;
      }
      LODWORD(v3) = v3 + 1;
      ++v7;
    }
    while ( (signed int)v3 < v6->m_size );
  }
}

// File Line: 2393
// RVA: 0xD71650
void __fastcall hkLs_toiResetVelocityAccumulatorsForEntities(hkpConstraintSolverResources *solverResources, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities)
{
  int v2; // er9
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v3; // r10
  hkpConstraintSolverResources *v4; // rbx
  __int64 v5; // r11
  hkpEntity *v6; // rcx
  char *v7; // r8
  __m128 v8; // xmm1
  __m128 *v9; // rdx

  v2 = 0;
  v3 = entities;
  v4 = solverResources;
  if ( entities->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v2;
      ++v5;
      v6 = v3->m_data[v5 - 1];
      v7 = &v4->m_accumulators->m_type.m_storage + v6->m_solverData;
      *((_OWORD *)v7 + 1) = v6->m_motion.m_linearVelocity;
      v8 = v6->m_motion.m_angularVelocity.m_quad;
      v9 = &v4->m_accumulatorsBackup[(unsigned __int64)v6->m_solverData >> 7].m_coreTworldRotation.m_col0.m_quad;
      *((__m128 *)v7 + 2) = _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v9[1]),
                                _mm_mul_ps(_mm_shuffle_ps(v6->m_motion.m_angularVelocity.m_quad, v8, 0), *v9)),
                              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v9[2]));
    }
    while ( v2 < v3->m_size );
  }
}

// File Line: 2419
// RVA: 0xD718B0
void __fastcall hkLs_backstepAndFreezeEntireIsland(float time, hkpSimulationIsland *island, hkFixedArray<unsigned char> *entityState, hkArray<hkpEntity *,hkContainerHeapAllocator> *activeEntities)
{
  int v4; // er15
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v5; // rbx
  __int64 v6; // rsi
  hkFixedArray<unsigned char> *v7; // r12
  hkpSimulationIsland *v8; // rbp
  float i; // xmm6_4
  hkpEntity *v10; // r14
  hkQuaternionf v11; // xmm1

  v4 = 0;
  v5 = activeEntities;
  v6 = 0i64;
  v7 = entityState;
  v8 = island;
  for ( i = time;
        v4 < v8->m_entities.m_size;
        v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[3] = 1.0
                                                                                        / (float)(hkpWorld::getCurrentPsiTime(v8->m_world)
                                                                                                - i) )
  {
    v10 = v8->m_entities.m_data[v6];
    hkSweptTransformUtil::backStepMotionState(i, &v10->m_motion.m_motionState);
    if ( v7->m_data.m_storage[v6] != 16 )
    {
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
      v5->m_data[v5->m_size++] = v10;
      v7->m_data.m_storage[v6] = 16;
    }
    v11.m_vec.m_quad = (__m128)v10->m_motion.m_motionState.m_sweptTransform.m_rotation1;
    v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0 = v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
    v10->m_motion.m_motionState.m_sweptTransform.m_rotation0 = (hkQuaternionf)v11.m_vec.m_quad;
    v10->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3] = i;
    ++v4;
    ++v6;
  }
}

// File Line: 2452
// RVA: 0xD71C00
void __fastcall hkLs_restoreTransformOnBodiesWithUpdatedTransform(hkpSimulationIsland *island, hkFixedArray<unsigned char> *entityState, hkpConstraintSolverResources *solverResources)
{
  int v3; // ebp
  hkpConstraintSolverResources *v4; // r13
  hkFixedArray<unsigned char> *v5; // r15
  __int64 v6; // rsi
  hkpSimulationIsland *i; // r14
  int v8; // ebx
  hkRotationf *v9; // rdi
  __m128 v10; // xmm1
  hkpEntity *v11; // r8
  unsigned __int64 v12; // rcx
  hkpVelocityAccumulator *v13; // rax
  signed __int64 v14; // rdx
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm1

  v3 = 0;
  v4 = solverResources;
  v5 = entityState;
  v6 = 0i64;
  for ( i = island; v3 < i->m_entities.m_size; ++v6 )
  {
    v8 = (unsigned __int8)v5->m_data.m_storage[v6];
    if ( (unsigned int)(v8 - 1) <= 1 )
    {
      v9 = &i->m_entities.m_data[v6]->m_motion.m_motionState.m_transform.m_rotation;
      hkRotationf::set(v9, &i->m_entities.m_data[v6]->m_motion.m_motionState.m_sweptTransform.m_rotation1);
      v10 = v9[2].m_col2.m_quad;
      v9[1].m_col0.m_quad = _mm_sub_ps(
                              v9[1].m_col2.m_quad,
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v9->m_col1.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v9[2].m_col2.m_quad, v10, 0), v9->m_col0.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v9->m_col2.m_quad)));
    }
    if ( v8 == 8 || v8 == 2 )
    {
      v11 = i->m_entities.m_data[v6];
      v12 = v11->m_solverData;
      v13 = v4->m_accumulators;
      v14 = (signed __int64)&v4->m_accumulatorsBackup[v12 >> 7];
      v11->m_motion.m_linearVelocity = *(hkVector4f *)((char *)&v13->m_linearVel + v12);
      v15 = *(__m128 *)(v14 + 32);
      v16 = _mm_unpacklo_ps(*(__m128 *)v14, *(__m128 *)(v14 + 16));
      v17 = _mm_movelh_ps(v16, v15);
      v18 = _mm_movehl_ps(v17, v16);
      v19 = *(__m128 *)((char *)&v13->m_angularVel.m_quad + v12);
      v11->m_motion.m_angularVelocity.m_quad = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v19, v19, 85),
                                                     _mm_shuffle_ps(v18, v15, 212)),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       *(__m128 *)((char *)&v13->m_angularVel.m_quad + v12),
                                                       v19,
                                                       0),
                                                     v17)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     _mm_unpackhi_ps(*(__m128 *)v14, *(__m128 *)(v14 + 16)),
                                                     v15,
                                                     228),
                                                   _mm_shuffle_ps(v19, v19, 170)));
    }
    ++v3;
  }
}

// File Line: 2485
// RVA: 0xD716F0
hkBool *__fastcall hkLs_toiCheckFinalValidityOfCriticalConstraints(hkBool *result, hkpConstraintSolverResources *solverResources, hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus, hkpProcessCollisionInput *processInput, hkArray<hkpToiResourceMgr::ConstraintViolationInfo,hkContainerHeapAllocator> *violatedConstraints)
{
  hkBool *v5; // rsi
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v6; // r13
  hkpConstraintSolverResources *v7; // r14
  char v8; // bl
  int v9; // ebp
  __int64 v10; // r12
  hkpConstraintSchemaInfo *v11; // r15
  int v12; // eax
  signed __int64 v13; // rcx
  hkpToiResourceMgr::ConstraintViolationInfo *v14; // r14
  signed __int64 v15; // rsi
  hkpConstraintData *v16; // rdx
  signed __int64 v17; // rcx
  float velocities; // [rsp+30h] [rbp-448h]
  hkBool *v20; // [rsp+480h] [rbp+8h]
  hkpConstraintSolverResources *v21; // [rsp+488h] [rbp+10h]
  int v22; // [rsp+490h] [rbp+18h]
  hkpProcessCollisionInput *processInputa; // [rsp+498h] [rbp+20h]

  processInputa = processInput;
  v21 = solverResources;
  v20 = result;
  v5 = result;
  v6 = constraintStatus;
  v7 = solverResources;
  v8 = 1;
  v9 = 0;
  if ( constraintStatus->m_size > 0 )
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = &v6->m_data[v10];
      if ( v11->m_constraint->m_priority.m_storage == 5 )
      {
        v12 = hkSolveGetToiViolatingConstraintVelocity(
                v7->m_solverInfo,
                v11->m_schema,
                v7->m_accumulators,
                256,
                &velocities);
        v22 = hkLs_areVelocitiesOk(v7->m_stepInfo->m_deltaTime.m_storage, v11, &velocities, v12, processInputa);
        if ( v22 >= 0 )
        {
          if ( !violatedConstraints )
          {
            v5 = v20;
            v20->m_bool = 0;
            return v5;
          }
          v8 = 0;
          if ( violatedConstraints->m_size == (violatedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              violatedConstraints,
              24);
          v13 = violatedConstraints->m_size;
          v14 = violatedConstraints->m_data;
          v15 = v13;
          violatedConstraints->m_size = v13 + 1;
          v14[v13].m_constraint = v11->m_constraint;
          if ( ((unsigned int (*)(void))v11->m_constraint->m_data->vfptr[1].__first_virtual_table_function__)() == 11 )
          {
            v16 = v11->m_constraint->m_data;
            v14[v15].m_contactPoint = (hkContactPoint *)(v16[2].m_userData + 32i64 * v22 + 48);
            v17 = v16[2].m_userData
                + *(unsigned __int8 *)(v16[2].m_userData + 10) * (signed int)(signed __int16)v22
                + 48i64
                + 32i64 * *(unsigned __int16 *)(v16[2].m_userData + 6);
          }
          else
          {
            v17 = 0i64;
            v14[v15].m_contactPoint = 0i64;
          }
          v14[v15].m_contactPointProperties = (hkpContactPointProperties *)v17;
          v7 = v21;
        }
      }
      ++v9;
      ++v10;
      if ( v9 >= v6->m_size )
      {
        v5 = v20;
        break;
      }
    }
  }
  v5->m_bool = v8;
  return v5;
}

// File Line: 2553
// RVA: 0xD6FDF0
hkResult *__fastcall hkLs_localizedSolveToi(hkResult *result, hkpToiResources *toiResources, hkpConstraintSolverResources *solverResources, hkpToiEvent *event, hkpToiResourceMgr *toiResourceMgr, hkpWorld *world, hkArray<hkpEntity *,hkContainerHeapAllocator> *activeEntities, hkFixedArray<unsigned char> *entityState, float rotateNormal)
{
  int v9; // edi
  hkpEntity *v10; // rax
  hkpToiEvent *v11; // r12
  hkpConstraintSolverResources *v12; // r15
  hkResult *v13; // rsi
  hkpSimulationIsland *v14; // rax
  int v15; // ebx
  int v16; // eax
  hkLifoAllocator *v17; // rax
  hkpEntity **v18; // rcx
  int v19; // edx
  hkpEntity *v20; // rdx
  hkFixedArray<unsigned char> *v21; // r14
  hkpEntity *v22; // r8
  float v23; // xmm1_4
  hkpEntity *v24; // rdx
  hkpEntity *v25; // r8
  float v26; // xmm1_4
  hkpDynamicsContactMgr *v27; // rcx
  hkpEntity *v28; // rbx
  signed __int64 v29; // rbx
  __m128 v30; // xmm1
  hkpEntity *v31; // rbx
  signed __int64 v32; // rbx
  __m128 v33; // xmm1
  int v34; // er8
  int v35; // eax
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // er8
  hkClass *v39; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v40; // rsi
  hkpWorld *v41; // r13
  char v42; // bl
  hkpConstraintInstance::ConstraintPriority *v43; // rax
  int v44; // ecx
  int v45; // edi
  hkpConstraintInstance::ConstraintPriority minPriorityToProcess; // eax
  hkpProcessCollisionInput *v47; // rdx
  __int64 v48; // r8
  __int64 v49; // rdx
  int v50; // er9
  int v51; // edx
  hkpEntity **v52; // r10
  __int64 v53; // r8
  int v54; // edx
  int v55; // ecx
  int v56; // er9
  int v57; // er9
  __int64 v58; // r8
  hkpEntity *v59; // rax
  int v60; // er9
  __int64 v61; // r9
  __int64 v62; // rbx
  char v63; // al
  int v64; // ebx
  hkpProcessCollisionInput *v65; // r9
  __int64 v66; // rbx
  int v67; // eax
  bool v68; // zf
  bool v69; // sf
  __int64 v70; // rbx
  int v71; // edi
  __int64 v72; // rbx
  int v73; // eax
  char *v74; // rdi
  signed int v75; // ebx
  hkLifoAllocator *v76; // rax
  int v77; // er8
  hkpEntity **entities; // [rsp+40h] [rbp-C0h]
  int numEntities; // [rsp+48h] [rbp-B8h]
  int v81; // [rsp+4Ch] [rbp-B4h]
  void *p; // [rsp+50h] [rbp-B0h]
  int v83; // [rsp+58h] [rbp-A8h]
  int v84; // [rsp+60h] [rbp-A0h]
  hkBool v85; // [rsp+64h] [rbp-9Ch]
  int v86; // [rsp+68h] [rbp-98h]
  int firstNonActiveConstraintStatus; // [rsp+6Ch] [rbp-94h]
  hkpSimulationIsland *island; // [rsp+70h] [rbp-90h]
  hkResult v89; // [rsp+78h] [rbp-88h]
  hkClass *v90; // [rsp+80h] [rbp-80h]
  hkClass *t; // [rsp+88h] [rbp-78h]
  hkClass *v92; // [rsp+90h] [rbp-70h]
  hkArray<hkpEntity *,hkContainerHeapAllocator> toBeActivated; // [rsp+A0h] [rbp-60h]
  char v94; // [rsp+B0h] [rbp-50h]
  hkArray<hkpEntity *,hkContainerHeapAllocator> newTouchedEntities; // [rsp+2B0h] [rbp+1B0h]
  char v96; // [rsp+2C0h] [rbp+1C0h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> newTouchedConstraints; // [rsp+4C0h] [rbp+3C0h]
  char v98; // [rsp+4D0h] [rbp+3D0h]
  hkArray<hkpToiResourceMgr::ConstraintViolationInfo,hkContainerHeapAllocator> violatedConstraints; // [rsp+6D0h] [rbp+5D0h]
  char v100; // [rsp+6E0h] [rbp+5E0h]
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> constraintStatus; // [rsp+9E0h] [rbp+8E0h]
  char v102; // [rsp+9F0h] [rbp+8F0h]
  hkResult *v103; // [rsp+1030h] [rbp+F30h]
  hkpToiResources *v104; // [rsp+1038h] [rbp+F38h]
  hkBool resulta; // [rsp+1048h] [rbp+F48h]

  v104 = toiResources;
  v103 = result;
  v9 = 0;
  constraintStatus.m_capacityAndFlags = -2147483584;
  constraintStatus.m_data = (hkpConstraintSchemaInfo *)&v102;
  v10 = event->m_entities[0];
  constraintStatus.m_size = 0;
  v68 = v10->m_motion.m_type.m_storage == 5;
  v11 = event;
  v12 = solverResources;
  v13 = result;
  v84 = 0;
  if ( v68 )
    v10 = event->m_entities[1];
  v14 = v10->m_simulationIsland;
  island = v14;
  v15 = v14->m_entities.m_size;
  v16 = 0;
  entities = 0i64;
  numEntities = 0;
  v81 = 2147483648;
  v83 = v15;
  if ( v15 )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpEntity **)v17->m_cur;
    v19 = (8 * v15 + 127) & 0xFFFFFF80;
    solverResources = (hkpConstraintSolverResources *)((char *)v18 + v19);
    if ( v19 > v17->m_slabSize || solverResources > v17->m_end )
    {
      v18 = (hkpEntity **)hkLifoAllocator::allocateFromNewSlab(v17, v19);
      v16 = numEntities;
    }
    else
    {
      v17->m_cur = solverResources;
      v16 = numEntities;
    }
  }
  else
  {
    v18 = 0i64;
  }
  v20 = v11->m_entities[0];
  v21 = entityState;
  entities = v18;
  v81 = v15 | 0x80000000;
  p = v18;
  if ( v20->m_motion.m_type.m_storage != 5 )
  {
    v18[v16] = v20;
    v22 = v11->m_entities[0];
    v23 = v11->m_time;
    ++numEntities;
    hkSweptTransformUtil::lerp2(
      &v22->m_motion.m_motionState.m_sweptTransform,
      v23,
      &v22->m_motion.m_motionState.m_transform);
    v21->m_data.m_storage[v11->m_entities[0]->m_storageIndex] = 2;
    v16 = numEntities;
    v18 = entities;
  }
  v24 = v11->m_entities[1];
  if ( v24->m_motion.m_type.m_storage != 5 )
  {
    v18[v16] = v24;
    v25 = v11->m_entities[1];
    v26 = v11->m_time;
    ++numEntities;
    hkSweptTransformUtil::lerp2(
      &v25->m_motion.m_motionState.m_sweptTransform,
      v26,
      &v25->m_motion.m_motionState.m_transform);
    v21->m_data.m_storage[v11->m_entities[1]->m_storageIndex] = 2;
  }
  v27 = v11->m_contactMgr;
  toBeActivated.m_size = 0;
  toBeActivated.m_capacityAndFlags = -2147483584;
  toBeActivated.m_data = (hkpEntity **)&v94;
  ((void (__fastcall *)(hkpDynamicsContactMgr *, hkpToiEvent *, hkpConstraintSolverResources *, hkArray<hkpEntity *,hkContainerHeapAllocator> *))v27->vfptr[9].__vecDelDtor)(
    v27,
    v11,
    solverResources,
    &toBeActivated);
  if ( !toBeActivated.m_size )
  {
    v28 = v11->m_entities[0];
    if ( v28->m_motion.m_type.m_storage != 5 )
    {
      v29 = (signed __int64)&v28->m_motion.m_motionState;
      hkRotationf::set((hkRotationf *)v29, (hkQuaternionf *)(v29 + 112));
      v30 = *(__m128 *)(v29 + 128);
      *(__m128 *)(v29 + 48) = _mm_sub_ps(
                                *(__m128 *)(v29 + 80),
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), *(__m128 *)(v29 + 16)),
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v29 + 128), v30, 0), *(__m128 *)v29)),
                                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), *(__m128 *)(v29 + 32))));
    }
    v31 = v11->m_entities[1];
    if ( v31->m_motion.m_type.m_storage != 5 )
    {
      v32 = (signed __int64)&v31->m_motion.m_motionState;
      hkRotationf::set((hkRotationf *)v32, (hkQuaternionf *)(v32 + 112));
      v33 = *(__m128 *)(v32 + 128);
      *(__m128 *)(v32 + 48) = _mm_sub_ps(
                                *(__m128 *)(v32 + 80),
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), *(__m128 *)(v32 + 16)),
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v32 + 128), v33, 0), *(__m128 *)v32)),
                                  _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), *(__m128 *)(v32 + 32))));
    }
    v34 = toBeActivated.m_capacityAndFlags;
    v13->m_enum = 1;
    toBeActivated.m_size = 0;
    if ( v34 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        toBeActivated.m_data,
        8 * v34);
    v35 = numEntities;
    toBeActivated.m_data = 0i64;
    toBeActivated.m_capacityAndFlags = 2147483648;
    if ( p == entities )
      v35 = 0;
    numEntities = v35;
    v36 = (8 * v83 + 127) & 0xFFFFFF80;
    v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v38 = (v36 + 15) & 0xFFFFFFF0;
    if ( v36 > v37->m_slabSize || (char *)p + v38 != v37->m_cur || v37->m_firstNonLifoEnd == p )
      hkLifoAllocator::slowBlockFree(v37, p, v38);
    else
      v37->m_cur = p;
    numEntities = 0;
    if ( v81 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entities,
        8 * v81);
    entities = 0i64;
    v81 = 2147483648;
    constraintStatus.m_size = 0;
    if ( constraintStatus.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        constraintStatus.m_data,
        24 * (constraintStatus.m_capacityAndFlags & 0x3FFFFFFF));
    return v13;
  }
  t = (hkClass *)*toBeActivated.m_data;
  if ( toBeActivated.m_size <= 1 )
  {
    v90 = 0i64;
    v92 = 0i64;
  }
  else
  {
    v39 = (hkClass *)*((_QWORD *)toBeActivated.m_data + 1);
    v90 = v39;
    v92 = v39;
    v9 = 0;
  }
  hkpConstraintSolverSetup::internalAddAccumulators(v12, entities, numEntities);
  v40 = activeEntities;
  v41 = world;
  v42 = 1;
  newTouchedEntities.m_size = 0;
  newTouchedEntities.m_data = (hkpEntity **)&v96;
  newTouchedEntities.m_capacityAndFlags = -2147483584;
  newTouchedConstraints.m_data = (hkpConstraintInstance **)&v98;
  v43 = &v104->m_minPriorityToProcess;
  newTouchedConstraints.m_size = 0;
  v44 = v104->m_numToiSolverIterations;
  newTouchedConstraints.m_capacityAndFlags = -2147483584;
  v86 = v44;
  if ( v44 <= 0 )
  {
LABEL_79:
    if ( v12->m_schemas[2].m_begin != v12->m_schemas[2].m_current )
    {
      hkLs_toiResetVelocityAccumulatorsForEntities(v12, (hkArray<hkpEntity *,hkContainerHeapAllocator> *)&entities);
      hkLs_toiCheckFinalValidityOfCriticalConstraints(&resulta, v12, &constraintStatus, v41->m_collisionInput, 0i64);
      v63 = resulta.m_bool;
      if ( !resulta.m_bool )
      {
        v64 = v104->m_numForcedToiFinalSolverIterations;
        while ( --v64 >= 0 )
        {
          hkSolveStepJacobians(v12->m_solverInfo, v12->m_schemas[2].m_begin, v12->m_accumulators, v12->m_elemTemp);
          hkLs_toiResetVelocityAccumulatorsForEntities(v12, (hkArray<hkpEntity *,hkContainerHeapAllocator> *)&entities);
          v63 = hkLs_toiCheckFinalValidityOfCriticalConstraints(
                  &resulta,
                  v12,
                  &constraintStatus,
                  v41->m_collisionInput,
                  0i64)->m_bool;
          if ( v63 )
            goto LABEL_95;
        }
        if ( !v63 )
        {
          v65 = v41->m_collisionInput;
          violatedConstraints.m_data = (hkpToiResourceMgr::ConstraintViolationInfo *)&v100;
          violatedConstraints.m_size = 0;
          violatedConstraints.m_capacityAndFlags = -2147483616;
          hkLs_toiCheckFinalValidityOfCriticalConstraints(&resulta, v12, &constraintStatus, v65, &violatedConstraints);
          if ( (unsigned int)toiResourceMgr->vfptr[2].__vecDelDtor(
                               (hkBaseObject *)toiResourceMgr,
                               (unsigned int)&violatedConstraints) == 2 )
          {
            hkLs_backstepAndFreezeEntireIsland(v11->m_time, island, v21, v40);
            if ( v40->m_size > 0 )
            {
              v66 = 0i64;
              do
              {
                hkpWorldAgentUtil::invalidateTim(
                  v40->m_data[v66],
                  (hkpCollisionInput *)&v41->m_collisionInput->m_dispatcher);
                ++v9;
                ++v66;
              }
              while ( v9 < v40->m_size );
            }
            v67 = violatedConstraints.m_capacityAndFlags;
            v40->m_size = 0;
            v13 = v103;
            violatedConstraints.m_size = 0;
            v103->m_enum = 0;
            if ( v67 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                violatedConstraints.m_data,
                24 * (v67 & 0x3FFFFFFF));
            violatedConstraints.m_data = 0i64;
            violatedConstraints.m_capacityAndFlags = 2147483648;
            goto LABEL_106;
          }
          violatedConstraints.m_size = 0;
          if ( violatedConstraints.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              violatedConstraints.m_data,
              24 * (violatedConstraints.m_capacityAndFlags & 0x3FFFFFFF));
        }
      }
    }
LABEL_95:
    v68 = v40->m_size == 0;
    v69 = v40->m_size < 0;
    if ( !v40->m_size )
    {
      hkArrayBase<hkClass *>::_insertAt(
        (hkArrayBase<hkClass *> *)v40,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        0,
        &t);
      v68 = v90 == 0i64;
      v21->m_data.m_storage[(*v40->m_data)->m_storageIndex] = 16;
      if ( !v68 )
      {
        hkArrayBase<hkClass *>::_insertAt(
          (hkArrayBase<hkClass *> *)v40,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          1,
          &v92);
        v21->m_data.m_storage[*(unsigned __int16 *)(*((_QWORD *)v40->m_data + 1) + 244i64)] = 16;
      }
      v68 = v40->m_size == 0;
      v69 = v40->m_size < 0;
    }
    if ( !v69 && !v68 )
    {
      v70 = 0i64;
      do
      {
        hkSweptTransformUtil::backStepMotionState(v11->m_time, &v40->m_data[v70]->m_motion.m_motionState);
        ++v9;
        ++v70;
      }
      while ( v9 < v40->m_size );
    }
    hkpConstraintSolverSetup::oneStepIntegrate(
      v12->m_solverInfo,
      v12->m_stepInfo,
      v12->m_accumulators,
      v40->m_data,
      v40->m_size);
    hkLs_restoreTransformOnBodiesWithUpdatedTransform(island, v21, v12);
    v71 = 0;
    if ( v40->m_size > 0 )
    {
      v72 = 0i64;
      do
      {
        hkpWorldAgentUtil::invalidateTim(v40->m_data[v72], (hkpCollisionInput *)&v41->m_collisionInput->m_dispatcher);
        ++v71;
        ++v72;
      }
      while ( v71 < v40->m_size );
    }
    goto LABEL_105;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      newTouchedConstraints.m_size = 0;
      newTouchedEntities.m_size = 0;
      v45 = v84;
      firstNonActiveConstraintStatus = v84;
      if ( v42 )
        break;
      if ( v84 >= constraintStatus.m_size )
      {
        v9 = 0;
        goto $RUN_FULL_SOLVER;
      }
      minPriorityToProcess = *v43;
      v47 = v41->m_collisionInput;
      v9 = 0;
      toBeActivated.m_size = 0;
      hkLs_toiCheckValidityOfConstraints(
        v12,
        v47,
        &constraintStatus,
        &firstNonActiveConstraintStatus,
        minPriorityToProcess,
        v21,
        (hkArray<hkpEntity *,hkContainerHeapAllocator> *)&entities,
        &toBeActivated);
      if ( toBeActivated.m_size )
      {
        v45 = firstNonActiveConstraintStatus;
        v43 = &v104->m_minPriorityToProcess;
        break;
      }
$RUN_FULL_SOLVER:
      hkpConstraintSolverSetup::subSolve(v12, 0);
      v43 = &v104->m_minPriorityToProcess;
      if ( --v86 <= 0 )
        goto LABEL_79;
    }
    hkLs_toiActivateEntitiesAndCheckConstraints(
      v41->m_collisionInput,
      *v43,
      v11->m_time,
      &toBeActivated,
      v21,
      &newTouchedEntities,
      &newTouchedConstraints);
    v42 = 0;
    if ( !hkpConstraintSolverSetup::internalIsMemoryOkForNewAccumulators(
            &resulta,
            v12,
            newTouchedEntities.m_data,
            newTouchedEntities.m_size)->m_bool
      || !hkpConstraintSolverSetup::internalIsMemoryOkForNewJacobianSchemas(
            &v85,
            v12,
            newTouchedConstraints.m_data,
            newTouchedConstraints.m_size)->m_bool
      || v104->m_maxNumConstraints < newTouchedConstraints.m_size + constraintStatus.m_size )
    {
      break;
    }
    v49 = (unsigned int)newTouchedEntities.m_size;
    v48 = (unsigned int)v40->m_size;
    if ( v104->m_maxNumEntities < (signed int)v48 + newTouchedEntities.m_size + numEntities
      || v104->m_maxNumActiveEntities < (signed int)v48 + toBeActivated.m_size )
    {
      goto LABEL_65;
    }
    hkpConstraintSolverSetup::internalAddAccumulators(v12, newTouchedEntities.m_data, newTouchedEntities.m_size);
    hkpConstraintSolverSetup::internalAddJacobianSchemas(
      v12,
      newTouchedConstraints.m_data,
      newTouchedConstraints.m_size,
      &constraintStatus);
    v50 = numEntities;
    v84 = v45;
    v9 = 0;
    v51 = 0;
    if ( numEntities > 0 )
    {
      v52 = entities;
      v53 = 0i64;
      do
      {
        if ( v21->m_data.m_storage[v52[v53]->m_storageIndex] == 16 )
        {
          numEntities = --v50;
          if ( v50 != v51 )
          {
            v52[v53] = v52[v50];
            v50 = numEntities;
            v52 = entities;
          }
          --v51;
          --v53;
        }
        ++v51;
        ++v53;
      }
      while ( v51 < v50 );
    }
    hkArrayBase<hkpEntity *>::_insertAt(
      (hkArrayBase<hkProcess *> *)v40,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v40->m_size,
      (hkProcess *const *)toBeActivated.m_data,
      toBeActivated.m_size);
    v54 = newTouchedEntities.m_size;
    v55 = numEntities;
    v56 = newTouchedEntities.m_size + numEntities;
    if ( (v81 & 0x3FFFFFFF) >= newTouchedEntities.m_size + numEntities )
    {
      v89.m_enum = 0;
    }
    else
    {
      if ( v56 < 2 * (v81 & 0x3FFFFFFF) )
        v56 = 2 * (v81 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v89, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &entities, v56, 8);
      v55 = numEntities;
      v54 = newTouchedEntities.m_size;
    }
    v57 = 0;
    if ( v54 > 0 )
    {
      v58 = 0i64;
      do
      {
        v59 = newTouchedEntities.m_data[v58];
        if ( v59->m_motion.m_type.m_storage != 4 )
        {
          entities[v55] = v59;
          v54 = newTouchedEntities.m_size;
          v55 = numEntities++ + 1;
        }
        ++v57;
        ++v58;
      }
      while ( v57 < v54 );
    }
    hkLs_toiActivateConstraintsLinkingToFixedAndKeyframedEntities(&constraintStatus, &v84, newTouchedConstraints.m_size);
    hkLs_toiActivateConstraintsLinkingActivatedEntities(&constraintStatus, &v84, v21);
    hkpConstraintSolverSetup::subSolve(v12, SOLVER_MODE_INCREMENTAL_CONTINUE);
    v43 = &v104->m_minPriorityToProcess;
    if ( !newTouchedConstraints.m_size && !newTouchedEntities.m_size )
      goto $RUN_FULL_SOLVER;
  }
  v49 = (unsigned int)newTouchedEntities.m_size;
LABEL_65:
  v9 = 0;
  v60 = 0;
  if ( toBeActivated.m_size > 0 )
  {
    v48 = 0i64;
    do
    {
      ++v60;
      v48 += 8i64;
      v21->m_data.m_storage[(*(hkpEntity **)((char *)toBeActivated.m_data + v48 - 8))->m_storageIndex] = 8;
    }
    while ( v60 < toBeActivated.m_size );
    v49 = (unsigned int)newTouchedEntities.m_size;
  }
  v61 = 0i64;
  if ( (signed int)v49 > 0 )
  {
    v48 = 0i64;
    do
    {
      v61 = (unsigned int)(v61 + 1);
      v48 += 8i64;
      v49 = (*(hkpEntity **)((char *)newTouchedEntities.m_data + v48 - 8))->m_storageIndex;
      v21->m_data.m_storage[v49] = 1;
    }
    while ( (signed int)v61 < newTouchedEntities.m_size );
  }
  if ( ((unsigned int (__fastcall *)(hkpToiResourceMgr *, __int64, __int64, __int64))toiResourceMgr->vfptr[2].__first_virtual_table_function__)(
         toiResourceMgr,
         v49,
         v48,
         v61) != 2 )
    goto $RUN_FULL_SOLVER;
  hkLs_backstepAndFreezeEntireIsland(v11->m_time, island, v21, v40);
  if ( v40->m_size > 0 )
  {
    v62 = 0i64;
    do
    {
      hkpWorldAgentUtil::invalidateTim(v40->m_data[v62], (hkpCollisionInput *)&v41->m_collisionInput->m_dispatcher);
      ++v9;
      ++v62;
    }
    while ( v9 < v40->m_size );
  }
  v40->m_size = 0;
LABEL_105:
  v13 = v103;
  v103->m_enum = 0;
LABEL_106:
  newTouchedConstraints.m_size = 0;
  if ( newTouchedConstraints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newTouchedConstraints.m_data,
      8 * newTouchedConstraints.m_capacityAndFlags);
  newTouchedConstraints.m_data = 0i64;
  newTouchedConstraints.m_capacityAndFlags = 2147483648;
  newTouchedEntities.m_size = 0;
  if ( newTouchedEntities.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newTouchedEntities.m_data,
      8 * newTouchedEntities.m_capacityAndFlags);
  newTouchedEntities.m_data = 0i64;
  newTouchedEntities.m_capacityAndFlags = 2147483648;
  toBeActivated.m_size = 0;
  if ( toBeActivated.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      toBeActivated.m_data,
      8 * toBeActivated.m_capacityAndFlags);
  v73 = numEntities;
  v74 = (char *)p;
  toBeActivated.m_data = 0i64;
  toBeActivated.m_capacityAndFlags = 2147483648;
  if ( p == entities )
    v73 = 0;
  numEntities = v73;
  v75 = (8 * v83 + 127) & 0xFFFFFF80;
  v76 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v77 = (v75 + 15) & 0xFFFFFFF0;
  if ( v75 > v76->m_slabSize || &v74[v77] != v76->m_cur || v76->m_firstNonLifoEnd == v74 )
    hkLifoAllocator::slowBlockFree(v76, v74, v77);
  else
    v76->m_cur = v74;
  numEntities = 0;
  if ( v81 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      entities,
      8 * v81);
  entities = 0i64;
  v81 = 2147483648;
  constraintStatus.m_size = 0;
  if ( constraintStatus.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      constraintStatus.m_data,
      24 * (constraintStatus.m_capacityAndFlags & 0x3FFFFFFF));
  return v13;
}

