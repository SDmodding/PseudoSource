// File Line: 85
// RVA: 0xD69B20
void __fastcall hkpSimulation::hkpSimulation(hkpSimulation *this, hkpWorld *world)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = world;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimulation::`vftable';
  this->m_simulateUntilTime = -1.0;
  *(_QWORD *)&this->m_currentTime = 0i64;
  this->m_determinismCheckFrameCounter = 0;
  *(_QWORD *)&this->m_frameMarkerPsiSnap = 953267991i64;
  this->m_lastProcessingStep.m_storage = 1;
}

// File Line: 91
// RVA: 0xD69B60
void __fastcall hkpSimulation::~hkpSimulation(hkpSimulation *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 99
// RVA: 0xD69B80
void __fastcall hkpSimulation::create(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  _QWORD **v2; // rax
  hkpSimulation *v3; // rax

  v1 = world;
  hkOptionalComponent_hkpSimulation.m_isUsed.m_bool = 1;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 64i64);
  if ( v3 )
    hkpSimulation::hkpSimulation(v3, v1);
}

// File Line: 103
// RVA: 0x15D2160
void dynamic_initializer_for__hkOptionalComponent_hkpSimulation__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpSimulation,
    "hkpSimulation",
    (void **)&hkpSimulation::createDiscrete,
    hkpSimulation::create);
}

// File Line: 107
// RVA: 0xD69FF0
void __fastcall hkpSimulation::setFrameTimeMarker(hkpSimulation *this, float frameDeltaTime)
{
  this->m_simulateUntilTime = frameDeltaTime + this->m_currentTime;
}

// File Line: 115
// RVA: 0xD6A010
bool __fastcall hkpSimulation::isSimulationAtMarker(hkpSimulation *this)
{
  return this->m_simulateUntilTime == this->m_currentTime;
}

// File Line: 120
// RVA: 0xD6A030
bool __fastcall hkpSimulation::isSimulationAtPsi(hkpSimulation *this)
{
  return this->m_currentTime == this->m_currentPsiTime;
}

// File Line: 126
// RVA: 0xD69C40
__int64 __fastcall hkpSimulation::integrate(hkpSimulation *this, float physicsDeltaTime)
{
  hkpSimulation *v2; // rbx
  _QWORD *v3; // r8
  _QWORD *v4; // rcx
  unsigned __int64 v5; // rax
  signed __int64 v6; // rcx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  __m128i *v10; // rax
  hkpStepResult v11; // edi
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkStepInfo stepInfoIn; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v4 = (_QWORD *)v3[1];
  if ( (unsigned __int64)v4 < v3[3] )
  {
    *v4 = "TtPhysics 2012";
    v5 = __rdtsc();
    v6 = (signed __int64)(v4 + 2);
    *(_DWORD *)(v6 - 8) = v5;
    v3[1] = v6;
  }
  v7 = v2->m_currentPsiTime;
  v2->m_physicsDeltaTime = physicsDeltaTime;
  stepInfoIn.m_startTime.m_storage = v7;
  stepInfoIn.m_endTime.m_storage = v7 + physicsDeltaTime;
  v8 = (float)(v7 + physicsDeltaTime) - v7;
  v9 = 0.0;
  stepInfoIn.m_deltaTime.m_storage = v8;
  if ( v8 != 0.0 )
    v9 = 1.0 / v8;
  v10 = (__m128i *)v2->m_world;
  stepInfoIn.m_invDeltaTime.m_storage = v9;
  _mm_store_si128(v10 + 42, (__m128i)stepInfoIn);
  _mm_store_si128((__m128i *)&v2->m_world->m_collisionInput->m_stepInfo, (__m128i)stepInfoIn);
  ((void (__fastcall *)(hkpWorldMaintenanceMgr *, hkpWorld *, hkStepInfo *))v2->m_world->m_maintenanceMgr->vfptr[2].__vecDelDtor)(
    v2->m_world->m_maintenanceMgr,
    v2->m_world,
    &stepInfoIn);
  v11 = hkpSimulation::integrateInternal(v2, &stepInfoIn);
  v2->m_previousStepResult = v11;
  if ( v11 == HK_STEP_RESULT_SUCCESS )
    v2->m_lastProcessingStep.m_storage = 0;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v12[1] = v15;
  }
  return (unsigned int)v11;
}

// File Line: 165
// RVA: 0xD69D70
__int64 __fastcall hkpSimulation::collide(hkpSimulation *this)
{
  hkpSimulation *v1; // rbx
  _QWORD *v2; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  hkpStepResult v6; // edi
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  hkBaseObjectVtbl *v10; // rax
  hkpWorld *v11; // rcx
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  hkStepInfo info; // [rsp+20h] [rbp-18h]

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
    v6 = hkpSimulation::reCollideAfterStepFailure(v1);
  }
  else
  {
    info.m_startTime.m_storage = v1->m_currentPsiTime;
    v7 = info.m_startTime.m_storage + v1->m_physicsDeltaTime;
    info.m_endTime.m_storage = v7;
    v8 = v7 - info.m_startTime.m_storage;
    v9 = 0.0;
    info.m_deltaTime.m_storage = v8;
    if ( v8 != 0.0 )
      v9 = 1.0 / v8;
    v10 = v1->vfptr;
    info.m_invDeltaTime.m_storage = v9;
    ((void (__fastcall *)(hkpSimulation *, hkStepInfo *, _QWORD *))v10[8].__first_virtual_table_function__)(
      v1,
      &info,
      v2);
    if ( hkOutOfMemoryState == 1 )
    {
      v6 = 2;
    }
    else
    {
      v11 = v1->m_world;
      v1->m_currentPsiTime = v1->m_physicsDeltaTime + v1->m_currentPsiTime;
      hkpWorld::checkConstraintsViolated(v11);
      if ( v1->m_world->m_worldPostCollideListeners.m_size )
      {
        v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v13 = (_QWORD *)v12[1];
        if ( (unsigned __int64)v13 < v12[3] )
        {
          *v13 = "TtPostCollideCB";
          v14 = __rdtsc();
          v15 = (signed __int64)(v13 + 2);
          *(_DWORD *)(v15 - 8) = v14;
          v12[1] = v15;
        }
        hkpWorldCallbackUtil::firePostCollideCallback(v1->m_world, &info);
        v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v17 = (_QWORD *)v16[1];
        if ( (unsigned __int64)v17 < v16[3] )
        {
          *v17 = "Et";
          v18 = __rdtsc();
          v19 = (signed __int64)(v17 + 2);
          *(_DWORD *)(v19 - 8) = v18;
          v16[1] = v19;
        }
      }
      v1->m_lastProcessingStep.m_storage = 1;
      v6 = 0;
    }
    v1->m_previousStepResult = v6;
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
  return (unsigned int)v6;
}

// File Line: 218
// RVA: 0xD6AAE0
void __fastcall hkpSimulation::checkDeltaTimeIsOk(hkpSimulation *this, float deltaTime)
{
  ;
}

// File Line: 233
// RVA: 0xD6AAF0
__int64 __fastcall hkpSimulation::reCollideAfterStepFailure(hkpSimulation *this)
{
  hkpSimulation *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  hkBaseObjectVtbl *v6; // rax
  _QWORD *v7; // r8
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  __int64 result; // rax
  hkpWorld *v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax
  hkStepInfo info; // [rsp+20h] [rbp-18h]

  v1 = this;
  hkpWorld::updateCollisionFilterOnWorld(this->m_world, 0, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  if ( v1->m_previousStepResult == 3 )
  {
    v2 = v1->m_currentPsiTime;
    v3 = v1->m_currentTime;
  }
  else
  {
    v3 = v1->m_currentPsiTime;
    v2 = v1->m_currentPsiTime + v1->m_physicsDeltaTime;
  }
  info.m_endTime.m_storage = v2;
  v4 = v2 - v3;
  info.m_startTime.m_storage = v3;
  v5 = 0.0;
  info.m_deltaTime.m_storage = v4;
  if ( v4 != 0.0 )
    v5 = 1.0 / v4;
  v6 = v1->vfptr;
  info.m_invDeltaTime.m_storage = v5;
  ((void (__fastcall *)(hkpSimulation *, hkStepInfo *))v6[8].__first_virtual_table_function__)(v1, &info);
  if ( hkOutOfMemoryState == 1 )
  {
    v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v8 = v7[1];
    if ( v8 < v7[3] )
    {
      *(_QWORD *)v8 = "Et";
      v9 = __rdtsc();
      *(_DWORD *)(v8 + 8) = v9;
      v7[1] = v8 + 16;
    }
    result = v1->m_previousStepResult;
  }
  else
  {
    if ( v1->m_previousStepResult == 2 )
    {
      v11 = v1->m_world;
      v1->m_currentPsiTime = v1->m_physicsDeltaTime + v1->m_currentPsiTime;
      if ( v11->m_worldPostCollideListeners.m_size )
      {
        v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v13 = (_QWORD *)v12[1];
        if ( (unsigned __int64)v13 < v12[3] )
        {
          *v13 = "TtPostCollideCB";
          v14 = __rdtsc();
          v15 = (signed __int64)(v13 + 2);
          *(_DWORD *)(v15 - 8) = v14;
          v12[1] = v15;
        }
        hkpWorldCallbackUtil::firePostCollideCallback(v1->m_world, &info);
        v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v17 = v16[1];
        if ( v17 < v16[3] )
        {
          *(_QWORD *)v17 = "Et";
          v18 = __rdtsc();
          *(_DWORD *)(v17 + 8) = v18;
          v16[1] = v17 + 16;
        }
      }
      v1->m_lastProcessingStep.m_storage = 1;
    }
    v1->m_previousStepResult = 0;
    result = 0i64;
  }
  return result;
}

// File Line: 300
// RVA: 0xD6B6F0
float __fastcall hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo(hkpSimulation *this)
{
  float v1; // xmm0_4
  float v2; // xmm2_4
  float v3; // xmm0_4
  float result; // xmm0_4

  v1 = this->m_simulateUntilTime;
  if ( v1 != -1.0 )
  {
    v2 = this->m_currentPsiTime;
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v1 - v2)) >> 1) < this->m_frameMarkerPsiSnap )
      this->m_simulateUntilTime = v2;
  }
  v3 = this->m_simulateUntilTime;
  if ( v3 == -1.0 )
    result = this->m_currentPsiTime;
  else
    result = fminf(this->m_currentPsiTime, v3);
  return result;
}

// File Line: 331
// RVA: 0xD69F30
__int64 __fastcall hkpSimulation::advanceTime(hkpSimulation *this)
{
  hkpSimulation *v1; // rbx
  float v2; // xmm0_4
  bool v3; // cf
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __int64 result; // rax

  v1 = this;
  v2 = hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo(this);
  v3 = v2 < v1->m_simulateUntilTime;
  v1->m_currentTime = v2;
  if ( !v3 && v1->m_world->m_worldPostSimulationListeners.m_size )
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
  result = 0i64;
  v1->m_previousStepResult = 0;
  return result;
}

// File Line: 349
// RVA: 0xD69BD0
__int64 __fastcall hkpSimulation::stepDeltaTime(hkpSimulation *this, float physicsDeltaTime)
{
  hkpSimulation *v2; // rbx
  unsigned int v3; // eax

  v2 = this;
  if ( this->m_previousStepResult <= 1 )
    ((void (*)(void))this->vfptr[2].__vecDelDtor)();
  if ( !(v2->m_previousStepResult & 0xFFFFFFFD) )
    v2->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v2->vfptr);
  v3 = v2->m_previousStepResult;
  if ( !v3 || v3 == 3 )
    ((void (__fastcall *)(hkpSimulation *))v2->vfptr[3].__vecDelDtor)(v2);
  if ( v2->m_previousStepResult && hkpWorld::getMemoryWatchDog(v2->m_world) )
    hkpWorldMemoryUtil::tryToRecoverFromMemoryErrors(v2->m_world);
  return v2->m_previousStepResult;
}

// File Line: 383
// RVA: 0xD6A220
void __fastcall hkpSimulation::collideEntitiesBroadPhaseDiscrete(hkpEntity **entities, int numEntities, hkpWorld *world)
{
  hkpEntity **v3; // rsi
  hkpWorld *v4; // r13
  int v5; // er14
  _QWORD *v6; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  int v10; // ebx
  LPVOID v11; // rax
  hkLifoAllocator *v12; // rcx
  hkpBroadPhaseHandlePair *v13; // rax
  int v14; // edx
  char *v15; // r8
  int v16; // ebx
  LPVOID v17; // rax
  hkLifoAllocator *v18; // rcx
  hkpBroadPhaseHandlePair *v19; // rax
  int v20; // edx
  char *v21; // r8
  hkLifoAllocator *v22; // rax
  char *v23; // r12
  int v24; // ebx
  char *v25; // rcx
  hkLifoAllocator *v26; // rax
  _BYTE *v27; // r15
  int v28; // edx
  char *v29; // rcx
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  int v34; // er14
  char *v35; // rdi
  signed __int64 v36; // r12
  hkpEntity *v37; // rax
  signed __int64 v38; // rbx
  char *v39; // rcx
  signed __int64 v40; // rbx
  signed __int64 v41; // rdx
  __int64 v42; // rax
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  hkLifoAllocator *v47; // rax
  int v48; // er8
  hkLifoAllocator *v49; // rax
  int v50; // er8
  _QWORD *v51; // r8
  _QWORD *v52; // rcx
  unsigned __int64 v53; // rax
  signed __int64 v54; // rcx
  _QWORD *v55; // r8
  _QWORD *v56; // rcx
  unsigned __int64 v57; // rax
  signed __int64 v58; // rcx
  int v59; // ebx
  hkMemorySystem *v60; // rax
  _QWORD *v61; // r8
  unsigned __int64 v62; // rcx
  unsigned __int64 v63; // rax
  int v64; // eax
  char *v65; // rdi
  signed int v66; // ebx
  hkLifoAllocator *v67; // rax
  int v68; // er8
  _QWORD *v69; // r8
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  signed __int64 v72; // rcx
  hkpCollisionFilter *v73; // rax
  hkpCollidableCollidableFilter *v74; // r9
  _QWORD *v75; // r8
  unsigned __int64 v76; // rcx
  unsigned __int64 v77; // rax
  int v78; // eax
  char *v79; // rdi
  signed int v80; // ebx
  hkLifoAllocator *v81; // rax
  int v82; // er8
  hkpEntity *entityBatch; // [rsp+30h] [rbp-39h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+38h] [rbp-31h]
  void *p; // [rsp+48h] [rbp-21h]
  int v86; // [rsp+50h] [rbp-19h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+58h] [rbp-11h]
  void *v88; // [rsp+68h] [rbp-1h]
  int v89; // [rsp+70h] [rbp+7h]
  unsigned int v90; // [rsp+D0h] [rbp+67h]
  unsigned int v91; // [rsp+D8h] [rbp+6Fh]
  signed int v92; // [rsp+E0h] [rbp+77h]
  char *v93; // [rsp+E8h] [rbp+7Fh]

  v91 = numEntities;
  v3 = entities;
  v4 = world;
  v5 = numEntities;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtBroadPhase";
    *(_QWORD *)(v7 + 16) = "StInitMem";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = v4->m_broadPhaseUpdateSize;
  newPairs.m_capacityAndFlags = 2147483648;
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  v89 = v10;
  if ( v10 )
  {
    v11 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkLifoAllocator *)v11;
    v13 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v11 + 3);
    v14 = (16 * v10 + 127) & 0xFFFFFF80;
    v15 = (char *)v13 + v14;
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      v13 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
  }
  else
  {
    v13 = 0i64;
  }
  newPairs.m_data = v13;
  v88 = v13;
  newPairs.m_capacityAndFlags = v10 | 0x80000000;
  v16 = v4->m_broadPhaseUpdateSize;
  delPairs.m_data = 0i64;
  delPairs.m_size = 0;
  delPairs.m_capacityAndFlags = 2147483648;
  v86 = v16;
  if ( v16 )
  {
    v17 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkLifoAllocator *)v17;
    v19 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v17 + 3);
    v20 = (16 * v16 + 127) & 0xFFFFFF80;
    v21 = (char *)v19 + v20;
    if ( v20 > v18->m_slabSize || v21 > v18->m_end )
      v19 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
    else
      v18->m_cur = v21;
  }
  else
  {
    v19 = 0i64;
  }
  delPairs.m_data = v19;
  delPairs.m_capacityAndFlags = v16 | 0x80000000;
  p = v19;
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (char *)v22->m_cur;
  v93 = v23;
  v24 = (32 * v5 + 127) & 0xFFFFFF80;
  v90 = (32 * v5 + 127) & 0xFFFFFF80;
  v25 = &v23[v24];
  if ( v24 > v22->m_slabSize || v25 > v22->m_end )
  {
    v23 = (char *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
    v93 = v23;
  }
  else
  {
    v22->m_cur = v25;
  }
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = v26->m_cur;
  v28 = (8 * v5 + 127) & 0xFFFFFF80;
  v92 = (8 * v5 + 127) & 0xFFFFFF80;
  v29 = &v27[v28];
  if ( v28 > v26->m_slabSize || v29 > v26->m_end )
    v27 = hkLifoAllocator::allocateFromNewSlab(v26, v28);
  else
    v26->m_cur = v29;
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "StCalcAabbs";
    v32 = __rdtsc();
    v33 = (signed __int64)(v31 + 2);
    *(_DWORD *)(v33 - 8) = v32;
    v30[1] = v33;
  }
  v34 = v5 - 1;
  v35 = v23;
  if ( v34 >= 0 )
  {
    v36 = v27 - (_BYTE *)v3;
    do
    {
      v37 = *v3;
      entityBatch = v37;
      v38 = (signed __int64)&v37->m_collidable;
      *(char **)((char *)v3 + v36) = (char *)v37 + 68;
      if ( v37->m_collidable.m_boundingVolumeData.m_min[0] > v37->m_collidable.m_boundingVolumeData.m_max[0] )
        hkpEntityAabbUtil::entityBatchRecalcAabb(
          (hkpCollisionInput *)&v4->m_collisionInput->m_dispatcher,
          &entityBatch,
          1);
      v39 = v35;
      v40 = v38 - (_QWORD)v35;
      v41 = 4i64;
      do
      {
        v42 = *(_QWORD *)&v39[v40 + 48];
        v39 += 8;
        *((_QWORD *)v39 - 1) = v42;
        --v41;
      }
      while ( v41 );
      v35 += 32;
      ++v3;
      --v34;
    }
    while ( v34 >= 0 );
    v23 = v93;
    v24 = v90;
  }
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = (_QWORD *)v43[1];
  if ( (unsigned __int64)v44 < v43[3] )
  {
    *v44 = "St3AxisSweep";
    v45 = __rdtsc();
    v46 = (signed __int64)(v44 + 2);
    *(_DWORD *)(v46 - 8) = v45;
    v43[1] = v46;
  }
  ((void (__fastcall *)(hkpBroadPhase *, _BYTE *, char *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkpEntity *))v4->m_broadPhase->vfptr[6].__vecDelDtor)(
    v4->m_broadPhase,
    v27,
    v23,
    v91,
    &newPairs,
    &delPairs,
    entityBatch);
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v48 = (v92 + 15) & 0xFFFFFFF0;
  if ( v92 > v47->m_slabSize || &v27[v48] != v47->m_cur || v47->m_firstNonLifoEnd == v27 )
    hkLifoAllocator::slowBlockFree(v47, v27, v48);
  else
    v47->m_cur = v27;
  v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (v24 + 15) & 0xFFFFFFF0;
  if ( v24 > v49->m_slabSize || &v23[v50] != v49->m_cur || v49->m_firstNonLifoEnd == v23 )
    hkLifoAllocator::slowBlockFree(v49, v23, v50);
  else
    v49->m_cur = v23;
  if ( delPairs.m_size + newPairs.m_size > 0 )
  {
    v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v52 = (_QWORD *)v51[1];
    if ( (unsigned __int64)v52 < v51[3] )
    {
      *v52 = "StRemoveDup";
      v53 = __rdtsc();
      v54 = (signed __int64)(v52 + 2);
      *(_DWORD *)(v54 - 8) = v53;
      v51[1] = v54;
    }
    hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &delPairs);
    v55 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v56 = (_QWORD *)v55[1];
    if ( (unsigned __int64)v56 < v55[3] )
    {
      *v56 = "StRemoveAgt";
      v57 = __rdtsc();
      v58 = (signed __int64)(v56 + 2);
      *(_DWORD *)(v58 - 8) = v57;
      v55[1] = v58;
    }
    hkpTypedBroadPhaseDispatcher::removePairs(
      v4->m_broadPhaseDispatcher,
      (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
      delPairs.m_size);
    v59 = newPairs.m_size;
    v60 = hkMemorySystem::getInstance();
    if ( !v60->vfptr->heapCanAllocTotal(v60, 640 * v59) )
    {
      hkSetOutOfMemoryState(MEMORY_STATE_OUT_OF_MEMORY);
      v61 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v62 = v61[1];
      if ( v62 < v61[3] )
      {
        *(_QWORD *)v62 = "lt";
        v63 = __rdtsc();
        *(_DWORD *)(v62 + 8) = v63;
        v61[1] = v62 + 16;
      }
      goto LABEL_53;
    }
    v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v70 = (_QWORD *)v69[1];
    if ( (unsigned __int64)v70 < v69[3] )
    {
      *v70 = "StAddAgt";
      v71 = __rdtsc();
      v72 = (signed __int64)(v70 + 2);
      *(_DWORD *)(v72 - 8) = v71;
      v69[1] = v72;
    }
    v73 = v4->m_collisionFilter;
    v74 = (hkpCollidableCollidableFilter *)&v73->vfptr;
    if ( !v73 )
      v74 = 0i64;
    hkpTypedBroadPhaseDispatcher::addPairs(
      v4->m_broadPhaseDispatcher,
      (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
      newPairs.m_size,
      v74);
  }
  v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v76 = v75[1];
  if ( v76 < v75[3] )
  {
    *(_QWORD *)v76 = "lt";
    v77 = __rdtsc();
    *(_DWORD *)(v76 + 8) = v77;
    v75[1] = v76 + 16;
  }
LABEL_53:
  v64 = delPairs.m_size;
  v65 = (char *)p;
  if ( p == delPairs.m_data )
    v64 = 0;
  delPairs.m_size = v64;
  v66 = (16 * v86 + 127) & 0xFFFFFF80;
  v67 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v68 = (v66 + 15) & 0xFFFFFFF0;
  if ( v66 > v67->m_slabSize || &v65[v68] != v67->m_cur || v67->m_firstNonLifoEnd == v65 )
    hkLifoAllocator::slowBlockFree(v67, v65, v68);
  else
    v67->m_cur = v65;
  delPairs.m_size = 0;
  if ( delPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      delPairs.m_data,
      16 * delPairs.m_capacityAndFlags);
  v78 = newPairs.m_size;
  v79 = (char *)v88;
  delPairs.m_data = 0i64;
  if ( v88 == newPairs.m_data )
    v78 = 0;
  delPairs.m_capacityAndFlags = 2147483648;
  newPairs.m_size = v78;
  v80 = (16 * v89 + 127) & 0xFFFFFF80;
  v81 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v82 = (v80 + 15) & 0xFFFFFFF0;
  if ( v80 > v81->m_slabSize || &v79[v82] != v81->m_cur || v81->m_firstNonLifoEnd == v79 )
    hkLifoAllocator::slowBlockFree(v81, v79, v82);
  else
    v81->m_cur = v79;
  newPairs.m_size = 0;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      16 * newPairs.m_capacityAndFlags);
}

// File Line: 487
// RVA: 0xD6AC70
void __fastcall hkpSimulation::collideInternal(hkpSimulation *this, hkStepInfo *stepInfoIn)
{
  hkpSimulation *v2; // rbx
  hkStepInfo *v3; // r12
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  int v9; // edi
  float *v10; // rax
  float v11; // xmm1_4
  hkpWorld *v12; // r14
  __int64 v13; // rsi
  hkpWorld *v14; // rdi
  bool v15; // zf
  int v16; // edi
  hkpWorld *v17; // r15
  __int64 v18; // rsi
  hkpSimulationIsland *v19; // rbp
  hkpProcessCollisionInput *v20; // r14
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r9
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  signed __int64 v26; // rax
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  signed __int64 v30; // rcx
  _QWORD *v31; // r8
  _QWORD *v32; // rcx
  unsigned __int64 v33; // rax
  signed __int64 v34; // rcx
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  signed __int64 v38; // rcx
  hkpWorld *v39; // rbx
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx

  v2 = this;
  v3 = stepInfoIn;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollide";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = 0;
  _mm_store_si128((__m128i *)&v2->m_world->m_dynamicsStepInfo, *(__m128i *)v3);
  _mm_store_si128((__m128i *)&v2->m_world->m_collisionInput->m_stepInfo, *(__m128i *)v3);
  v10 = (float *)v2->m_world;
  v11 = (float)v2->m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  v10[245] = v10[250] * v3->m_deltaTime.m_storage;
  v10[246] = v11 * v3->m_invDeltaTime.m_storage;
  ++v2->m_world->m_criticalOperationsLockCount;
  v12 = v2->m_world;
  if ( v12->m_activeSimulationIslands.m_size <= 0 )
  {
LABEL_7:
    v14 = v2->m_world;
    v15 = v14->m_criticalOperationsLockCount-- == 1;
    if ( v15 && !v14->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v14->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v14);
      if ( v14->m_pendingOperationQueueCount == 1 && v14->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v14);
    }
    v16 = 0;
    ++v2->m_world->m_criticalOperationsLockCount;
    v17 = v2->m_world;
    if ( v17->m_activeSimulationIslands.m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        v19 = v17->m_activeSimulationIslands.m_data[v18];
        v20 = v2->m_world->m_collisionInput;
        v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v22 = (_QWORD *)v21[1];
        v23 = v21;
        if ( (unsigned __int64)v22 < v21[3] )
        {
          *v22 = "TtNarrowPhase";
          v24 = __rdtsc();
          v25 = (signed __int64)(v22 + 2);
          *(_DWORD *)(v25 - 8) = v24;
          v23[1] = v25;
        }
        v26 = (signed __int64)&v20->m_dispatcher.m_storage->m_collisionQualityInfo[1];
        v20->m_createPredictiveAgents.m_storage = 0;
        v20->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v26;
        hkAgentNnMachine_ProcessTrack((hkpConstraintOwner *)&v19->vfptr, &v19->m_narrowphaseAgentTrack, v20);
        hkAgentNnMachine_ProcessTrack((hkpConstraintOwner *)&v19->vfptr, &v19->m_midphaseAgentTrack, v20);
        v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v28 = (_QWORD *)v27[1];
        if ( (unsigned __int64)v28 < v27[3] )
        {
          *v28 = "Et";
          v29 = __rdtsc();
          v30 = (signed __int64)(v28 + 2);
          *(_DWORD *)(v30 - 8) = v29;
          v27[1] = v30;
        }
        if ( hkOutOfMemoryState == 1 )
          break;
        if ( v2->m_world->m_islandPostCollideListeners.m_size )
        {
          v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v32 = (_QWORD *)v31[1];
          if ( (unsigned __int64)v32 < v31[3] )
          {
            *v32 = "TtIslandPostCollideCb";
            v33 = __rdtsc();
            v34 = (signed __int64)(v32 + 2);
            *(_DWORD *)(v34 - 8) = v33;
            v31[1] = v34;
          }
          hkpWorldCallbackUtil::fireIslandPostCollideCallback(v2->m_world, v19, v3);
          v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v36 = (_QWORD *)v35[1];
          if ( (unsigned __int64)v36 < v35[3] )
          {
            *v36 = "Et";
            v37 = __rdtsc();
            v38 = (signed __int64)(v36 + 2);
            *(_DWORD *)(v38 - 8) = v37;
            v35[1] = v38;
          }
        }
        ++v16;
        ++v18;
      }
      while ( v16 < v17->m_activeSimulationIslands.m_size );
    }
  }
  else
  {
    v13 = 0i64;
    while ( 1 )
    {
      hkpSimulation::collideEntitiesBroadPhaseDiscrete(
        v12->m_activeSimulationIslands.m_data[v13]->m_entities.m_data,
        v12->m_activeSimulationIslands.m_data[v13]->m_entities.m_size,
        v2->m_world);
      if ( hkOutOfMemoryState == 1 )
        break;
      ++v9;
      ++v13;
      if ( v9 >= v12->m_activeSimulationIslands.m_size )
        goto LABEL_7;
    }
  }
  v39 = v2->m_world;
  v15 = v39->m_criticalOperationsLockCount-- == 1;
  if ( v15 && !v39->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v39->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v39);
    if ( v39->m_pendingOperationQueueCount == 1 && v39->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v39);
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v41 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v42[1] = v44;
  }
}

// File Line: 590
// RVA: 0xD6AFE0
signed __int64 __fastcall hkpSimulation::integrateInternal(hkpSimulation *this, hkStepInfo *stepInfoIn)
{
  hkpSimulation *v2; // rdi
  hkStepInfo *v3; // r15
  _QWORD *v4; // r8
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rax
  __m128 *v7; // rcx
  float v8; // xmm1_4
  hkMemorySystem *v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkpWorld *v14; // rbx
  bool v15; // zf
  hkpWorld *v16; // rcx
  char v17; // al
  hkpSolverInfo *v18; // rcx
  hkpWorld *v19; // rcx
  hkpViolatedConstraintArray *v20; // rax
  float v21; // xmm1_4
  float v22; // xmm1_4
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  hkpWorld *v27; // r14
  int v28; // eax
  __int64 i; // rbp
  hkpWorld *v30; // rsi
  hkpSimulationIsland *v31; // rbx
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  int v36; // esi
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  signed __int64 v40; // rcx
  signed __int64 result; // rax
  hkpWorld *v42; // rcx
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  hkpWorld *v47; // rbx
  _QWORD *v48; // r8
  _QWORD *v49; // rcx
  unsigned __int64 v50; // rax
  signed __int64 v51; // rcx
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  signed __int64 v55; // rcx
  _QWORD *v56; // rax
  _QWORD *v57; // rcx
  _QWORD *v58; // r8
  unsigned __int64 v59; // rax
  signed __int64 v60; // rcx
  hkWorldMemoryAvailableWatchDog::MemUsageInfo infoOut; // [rsp+40h] [rbp-C8h]
  hkpConstraintQueryIn constraintQueryIn; // [rsp+50h] [rbp-B8h]

  v2 = this;
  v3 = stepInfoIn;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = v4[1];
  if ( v5 < v4[3] )
  {
    *(_QWORD *)v5 = "LtIntegrate";
    *(_QWORD *)(v5 + 16) = "StInit";
    v6 = __rdtsc();
    *(_DWORD *)(v5 + 8) = v6;
    v4[1] = v5 + 24;
  }
  _mm_store_si128((__m128i *)&v2->m_world->m_dynamicsStepInfo, *(__m128i *)v3);
  v7 = (__m128 *)&v2->m_world->m_dynamicsStepInfo.m_solverInfo;
  v8 = (float)v2->m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  v7[18].m128_f32[1] = v7[19].m128_f32[2] * v3->m_deltaTime.m_storage;
  v7[18].m128_f32[2] = v8 * v3->m_invDeltaTime.m_storage;
  v7[1] = _mm_mul_ps(
            _mm_shuffle_ps((__m128)v7[18].m128_u32[1], (__m128)v7[18].m128_u32[1], 0),
            v2->m_world->m_gravity.m_quad);
  v7[2] = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(v3->m_deltaTime.m_storage), (__m128)LODWORD(v3->m_deltaTime.m_storage), 0),
            v2->m_world->m_gravity.m_quad);
  hkpWorld::calcRequiredSolverBufferSize(v2->m_world, &infoOut);
  v9 = hkMemorySystem::getInstance();
  if ( !v9->vfptr->solverCanAllocSingleBlock(v9, infoOut.m_maxRuntimeBlockSize) )
  {
    if ( !hkpWorld::getMemoryWatchDog(v2->m_world) )
    {
      result = 1i64;
      v2->m_previousStepResult = 1;
      return result;
    }
    hkpWorldMemoryUtil::checkMemoryForIntegration(v2->m_world);
  }
  ++v2->m_world->m_criticalOperationsLockCount;
  --v2->m_world->m_criticalOperationsLockCountForPhantoms;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "StActions";
    v12 = __rdtsc();
    v13 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v10[1] = v13;
  }
  hkpSimulation::applyActions(v2);
  ++v2->m_world->m_criticalOperationsLockCountForPhantoms;
  v14 = v2->m_world;
  v15 = v14->m_criticalOperationsLockCount-- == 1;
  if ( v15 && !v14->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v14->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v14);
    if ( v14->m_pendingOperationQueueCount == 1 && v14->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v14);
  }
  ++v2->m_world->m_criticalOperationsLockCount;
  v16 = v2->m_world;
  v17 = ++v16->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
  v18 = &v16->m_dynamicsStepInfo.m_solverInfo;
  if ( !((v17 - 4) & 7) )
    v18->m_deactivationNumInactiveFramesSelectFlag[0] ^= 1u;
  if ( !(v18->m_deactivationIntegrateCounter & 7) )
    v18->m_deactivationNumInactiveFramesSelectFlag[0] ^= 2u;
  if ( !(v18->m_deactivationIntegrateCounter & 0xF) )
  {
    v18->m_deactivationNumInactiveFramesSelectFlag[1] = 1 - v18->m_deactivationNumInactiveFramesSelectFlag[1];
    v18->m_deactivationIntegrateCounter = 0;
  }
  v19 = v2->m_world;
  constraintQueryIn.m_beginConstraints = hkpBeginConstraints;
  v20 = v19->m_violatedConstraintArray;
  constraintQueryIn.m_subStepDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
  constraintQueryIn.m_microStepDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_deltaTime
                                                   * v19->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps;
  constraintQueryIn.m_subStepInvDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
  constraintQueryIn.m_invNumSteps.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
  constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                           * v19->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
  constraintQueryIn.m_tau.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_tau;
  v21 = v19->m_dynamicsStepInfo.m_solverInfo.m_damping;
  constraintQueryIn.m_violatedConstraints.m_storage = v20;
  *(float *)&v20 = v3->m_deltaTime.m_storage;
  constraintQueryIn.m_damping.m_storage = v21;
  constraintQueryIn.m_rhsFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                          * v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
  constraintQueryIn.m_virtMassFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_damping;
  v22 = v19->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp * v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
  LODWORD(constraintQueryIn.m_frameDeltaTime.m_storage) = (_DWORD)v20;
  constraintQueryIn.m_frameInvDeltaTime.m_storage = v3->m_invDeltaTime.m_storage;
  constraintQueryIn.m_frictionRhsFactor.m_storage = v22;
  constraintQueryIn.m_maxConstraintViolationSqrd.m_real = _mm_shuffle_ps(
                                                            (__m128)LODWORD(v19->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd),
                                                            (__m128)LODWORD(v19->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd),
                                                            0);
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "StIntegrate";
    v25 = __rdtsc();
    v26 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v23[1] = v26;
  }
  v27 = v2->m_world;
  v28 = v27->m_activeSimulationIslands.m_size - 1;
  for ( i = v28; i >= 0; --i )
  {
    v30 = v2->m_world;
    v31 = v27->m_activeSimulationIslands.m_data[i];
    if ( v31->m_constraintInfo.m_sizeOfSchemas )
    {
      v36 = hkpConstraintSolverSetup::solve(
              &v30->m_dynamicsStepInfo.m_stepInfo,
              &v30->m_dynamicsStepInfo.m_solverInfo,
              &constraintQueryIn,
              v31,
              0i64,
              0,
              v31->m_entities.m_data,
              v31->m_entities.m_size);
    }
    else
    {
      v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v33 = (_QWORD *)v32[1];
      if ( (unsigned __int64)v33 < v32[3] )
      {
        *v33 = "TtSingleObj";
        v34 = __rdtsc();
        v35 = (signed __int64)(v33 + 2);
        *(_DWORD *)(v35 - 8) = v34;
        v32[1] = v35;
      }
      v36 = hkRigidMotionUtilApplyForcesAndStep(
              &v30->m_dynamicsStepInfo.m_solverInfo,
              &v30->m_dynamicsStepInfo.m_stepInfo,
              &v30->m_dynamicsStepInfo.m_solverInfo.m_globalAccelerationPerStep,
              (hkpMotion *const *)v31->m_entities.m_data,
              v31->m_entities.m_size,
              336);
      hkpEntityAabbUtil::entityBatchRecalcAabb(
        (hkpCollisionInput *)&v31->m_world->m_collisionInput->m_dispatcher,
        v31->m_entities.m_data,
        v31->m_entities.m_size);
      v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v38 = (_QWORD *)v37[1];
      if ( (unsigned __int64)v38 < v37[3] )
      {
        *v38 = "Et";
        v39 = __rdtsc();
        v40 = (signed __int64)(v38 + 2);
        *(_DWORD *)(v40 - 8) = v39;
        v37[1] = v40;
      }
    }
    if ( v36 > 5 )
    {
      if ( *((_BYTE *)v31 + 50) & 0xC )
      {
        v42 = v31->m_world;
        if ( v42->m_wantDeactivation.m_bool )
          hkpWorldOperationUtil::markIslandInactive(v42, v31);
      }
    }
    if ( v2->m_world->m_islandPostIntegrateListeners.m_size )
    {
      v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v44 = (_QWORD *)v43[1];
      if ( (unsigned __int64)v44 < v43[3] )
      {
        *v44 = "StIslandPostIntegrateCb";
        v45 = __rdtsc();
        v46 = (signed __int64)(v44 + 2);
        *(_DWORD *)(v46 - 8) = v45;
        v43[1] = v46;
      }
      hkpWorldCallbackUtil::fireIslandPostIntegrateCallback(v2->m_world, v31, v3);
    }
  }
  v47 = v2->m_world;
  v15 = v47->m_criticalOperationsLockCount-- == 1;
  if ( v15 && !v47->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v47->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v47);
    if ( v47->m_pendingOperationQueueCount == 1 && v47->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v47);
  }
  if ( v2->m_world->m_worldPostIntegrateListeners.m_size )
  {
    v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v49 = (_QWORD *)v48[1];
    if ( (unsigned __int64)v49 < v48[3] )
    {
      *v49 = "TtWorldPostIntegrateCb";
      v50 = __rdtsc();
      v51 = (signed __int64)(v49 + 2);
      *(_DWORD *)(v51 - 8) = v50;
      v48[1] = v51;
    }
    hkpWorldCallbackUtil::firePostIntegrateCallback(v2->m_world, v3);
    v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v53 = (_QWORD *)v52[1];
    if ( (unsigned __int64)v53 < v52[3] )
    {
      *v53 = "Et";
      v54 = __rdtsc();
      v55 = (signed __int64)(v53 + 2);
      *(_DWORD *)(v55 - 8) = v54;
      v52[1] = v55;
    }
  }
  v56 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v57 = (_QWORD *)v56[1];
  v58 = v56;
  if ( (unsigned __int64)v57 < v56[3] )
  {
    *v57 = "lt";
    v59 = __rdtsc();
    v60 = (signed __int64)(v57 + 2);
    *(_DWORD *)(v60 - 8) = v59;
    v58[1] = v60;
  }
  return 0i64;
}

// File Line: 711
// RVA: 0xD6B650
void __fastcall hkpSimulation::applyActions(hkpSimulation *this)
{
  hkpWorld *v1; // r15
  int v2; // ebp
  hkpSimulation *v3; // r13
  __int64 v4; // r14
  int v5; // esi
  hkpSimulationIsland *v6; // rbx
  __int64 v7; // rdi

  v1 = this->m_world;
  v2 = 0;
  v3 = this;
  if ( v1->m_activeSimulationIslands.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = 0;
      v6 = v1->m_activeSimulationIslands.m_data[v4];
      if ( v6->m_actions.m_size > 0 )
      {
        v7 = 0i64;
        do
        {
          ((void (__fastcall *)(hkpAction *, hkpWorldDynamicsStepInfo *))v6->m_actions.m_data[v7]->vfptr[1].__first_virtual_table_function__)(
            v6->m_actions.m_data[v7],
            &v3->m_world->m_dynamicsStepInfo);
          ++v5;
          ++v7;
        }
        while ( v5 < v6->m_actions.m_size );
      }
      ++v2;
      ++v4;
    }
    while ( v2 < v1->m_activeSimulationIslands.m_size );
  }
}

// File Line: 739
// RVA: 0xD6A050
void __fastcall hkpSimulation::collideEntitiesDiscrete(hkpSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, hkStepInfo *stepInfo, hkpSimulation::FindContacts findExtraContacts)
{
  hkpProcessCollisionInput *v6; // r10
  int v7; // ebx
  hkpEntity **v8; // rdi
  hkpSimulation *v9; // rsi
  hkpWorld *v10; // r14
  hkVector4f v11; // xmm1
  hkStepInfo v12; // xmm0
  bool v13; // zf
  _QWORD **v14; // rax
  hkpProcessCollisionInput input; // [rsp+30h] [rbp-59h]

  v6 = world->m_collisionInput;
  v7 = numEntities;
  v8 = entities;
  v9 = this;
  v10 = world;
  *(_OWORD *)&input.m_dispatcher.m_storage = *(_OWORD *)&v6->m_dispatcher.m_storage;
  *(_OWORD *)&input.m_tolerance.m_storage = *(_OWORD *)&v6->m_tolerance.m_storage;
  *(_OWORD *)&input.m_convexListFilter.m_storage = *(_OWORD *)&v6->m_convexListFilter.m_storage;
  input.m_aabb32Info.m_bitOffsetLow = v6->m_aabb32Info.m_bitOffsetLow;
  input.m_aabb32Info.m_bitOffsetHigh = v6->m_aabb32Info.m_bitOffsetHigh;
  v11.m_quad = (__m128)v6->m_aabb32Info.m_bitScale;
  input.m_spareAgentSector = 0i64;
  input.m_aabb32Info.m_bitScale = (hkVector4f)v11.m_quad;
  input.m_dispatcher.m_storage = v6->m_dispatcher.m_storage;
  input.m_weldClosestPoints.m_storage = v6->m_weldClosestPoints.m_storage;
  input.m_forceAcceptContactPoints.m_storage = v6->m_forceAcceptContactPoints.m_storage;
  input.m_tolerance.m_storage = v6->m_tolerance.m_storage;
  input.m_filter.m_storage = v6->m_filter.m_storage;
  input.m_convexListFilter.m_storage = v6->m_convexListFilter.m_storage;
  input.m_createPredictiveAgents.m_storage = v6->m_createPredictiveAgents.m_storage;
  input.m_aabb32Info.m_bitOffsetLow = v6->m_aabb32Info.m_bitOffsetLow;
  input.m_aabb32Info.m_bitOffsetHigh = v6->m_aabb32Info.m_bitOffsetHigh;
  input.m_aabb32Info.m_bitScale = v6->m_aabb32Info.m_bitScale;
  _mm_store_si128((__m128i *)&input.m_stepInfo, (__m128i)v6->m_stepInfo);
  input.m_collisionQualityInfo.m_storage = v6->m_collisionQualityInfo.m_storage;
  input.m_dynamicsInfo = v6->m_dynamicsInfo;
  input.m_enableDeprecatedWelding.m_bool = v6->m_enableDeprecatedWelding.m_bool;
  input.m_allowToSkipConfirmedCallbacks.m_bool = v6->m_allowToSkipConfirmedCallbacks.m_bool;
  input.m_config = v6->m_config;
  v12 = *stepInfo;
  ++world->m_criticalOperationsLockCount;
  _mm_store_si128((__m128i *)&input.m_stepInfo, (__m128i)v12);
  hkpSimulation::collideEntitiesBroadPhaseDiscrete(entities, numEntities, world);
  hkpSimulation::collideEntitiesNarrowPhaseDiscrete(v9, v8, v7, &input, findExtraContacts);
  v13 = v10->m_criticalOperationsLockCount-- == 1;
  if ( v13 && !v10->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v10->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v10);
    if ( v10->m_pendingOperationQueueCount == 1 && v10->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v10);
  }
  if ( input.m_spareAgentSector )
  {
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v14[11] + 16i64))(
      v14[11],
      input.m_spareAgentSector,
      512i64);
  }
}

// File Line: 764
// RVA: 0xD6A870
void __fastcall hkpSimulation::collideEntitiesNarrowPhaseDiscrete(hkpSimulation *this, hkpEntity **entities, int numEntities, hkpProcessCollisionInput *input, hkpSimulation::FindContacts findExtraContacts)
{
  hkpSimulation::processAgentsOfEntities(
    this,
    entities,
    numEntities,
    input,
    hkpSimulation::processAgentCollideDiscrete,
    findExtraContacts);
}

// File Line: 772
// RVA: 0xD6C130
void __usercall hkpSimulation::processAgentCollideDiscrete(hkpSimulation *this@<rcx>, hkpAgentNnEntry *entry@<rdx>, hkpProcessCollisionInput *processInput@<r8>, hkpProcessCollisionOutput *processOutput@<r9>, __int64 a5@<r12>)
{
  hkpProcessCdPoint *v5; // rbp
  hkpCollisionDispatcher *v6; // rcx
  hkpProcessCollisionOutput *v7; // rbx
  hkpProcessCollisionInput *v8; // rsi
  hkpAgentNnEntry *v9; // rdi

  processOutput->m_toi.m_time.m_storage = 3.40282e38;
  processOutput->m_potentialContacts.m_storage = 0i64;
  v5 = processOutput->m_contactPoints;
  processOutput->m_firstFreeContactPoint.m_storage = processOutput->m_contactPoints;
  v6 = processInput->m_dispatcher.m_storage;
  v7 = processOutput;
  v8 = processInput;
  v9 = entry;
  processInput->m_collisionQualityInfo.m_storage = &processInput->m_dispatcher.m_storage->m_collisionQualityInfo[1];
  processInput->m_createPredictiveAgents.m_storage = v6->m_collisionQualityInfo[(signed __int64)entry->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
  hkAgentNnMachine_ProcessAgent(entry, processInput, processOutput, entry->m_contactMgr, a5);
  if ( hkOutOfMemoryState != 1 && v7->m_firstFreeContactPoint.m_storage != v5 )
    ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v9->m_contactMgr->vfptr[3].__vecDelDtor)(
      v9->m_contactMgr,
      v9->m_collidable[0],
      v9->m_collidable[1],
      v8,
      v7);
}

// File Line: 795
// RVA: 0xD6C1F0
void __fastcall hkpSimulation::processAgentResetCollisionInformation(hkpSimulation *this, hkpAgentNnEntry *entry, hkpProcessCollisionInput *processInput, hkpProcessCollisionOutput *processOutput)
{
  hkAgentNnMachine_InvalidateTimInAgent(entry, (hkpCollisionInput *)&processInput->m_dispatcher);
}

// File Line: 816
// RVA: 0xD6A8A0
void __fastcall hkpSimulation::resetCollisionInformationForEntities(hkpSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, hkpSimulation::ResetCollisionInformation resetInfo)
{
  int v5; // ebx
  hkpEntity **v6; // rdi

  v5 = numEntities;
  v6 = entities;
  if ( resetInfo & 2 )
    hkpSimulation::processAgentsOfEntities(
      this,
      entities,
      numEntities,
      world->m_collisionInput,
      hkpSimulation::processAgentResetCollisionInformation,
      0);
  if ( resetInfo & 4 )
    hkpEntityAabbUtil::entityBatchInvalidateAabb(v6, v5);
}

// File Line: 836
// RVA: 0xD6C440
void __fastcall setRotationAroundCentreOfMass(hkpRigidBody *rb, hkQuaternionf *newRotation)
{
  hkpRigidBody *v2; // rbx
  __m128 v3; // xmm1

  v2 = rb;
  hkRotationf::set(&rb->m_motion.m_motionState.m_transform.m_rotation, newRotation);
  v3 = v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
  v2->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                  v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(v3, v3, 85),
                                                                        v2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(
                                                                          v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad,
                                                                          v3,
                                                                          0),
                                                                        v2->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                                    _mm_mul_ps(
                                                                      _mm_shuffle_ps(v3, v3, 170),
                                                                      v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
}

// File Line: 845
// RVA: 0xD6B770
void __fastcall hkpSimulation::processAgentsOfEntities(hkpSimulation *this, hkpEntity **entities, int numEntities, hkpProcessCollisionInput *processInput, void (__fastcall *processingFunction)(hkpSimulation *this, hkpAgentNnEntry *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *), hkpSimulation::FindContacts findExtraContacts)
{
  hkpProcessCollisionInput *v6; // r13
  __int64 v7; // rbx
  hkpSimulation *v8; // rdi
  hkpEntity **v9; // r9
  hkpLinkedCollidable::CollisionEntry *v10; // rdx
  __int64 v11; // rax
  int v12; // er8
  hkpEntity *v13; // r15
  int v14; // er12
  __int64 v15; // rbx
  hkpLinkedCollidable::CollisionEntry *v16; // r14
  int v17; // eax
  hkpAgentNnEntry *v18; // rsi
  hkpLinkedCollidable *v19; // rax
  __int64 v20; // rcx
  __int64 v21; // rcx
  hkpAgentNnEntry *v22; // rax
  __m128 v23; // xmm14
  __m128 *v24; // rdi
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  __int128 v27; // xmm1
  __m128 v28; // xmm15
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm13
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm12
  hkpCollisionQualityInfo *v42; // rax
  float v43; // xmm11_4
  float v44; // xmm0_4
  float v45; // xmm9_4
  float v46; // xmm10_4
  __m128 v47; // xmm12
  __m128 v48; // xmm7
  __m128 v49; // xmm6
  __m128 v50; // xmm2
  __m128 v51; // xmm5
  __m128 v52; // xmm4
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  __m128 v56; // xmm2
  __m128 v57; // xmm2
  __m128 v58; // xmm4
  __m128 v59; // xmm5
  __m128 v60; // xmm3
  __m128 v61; // xmm6
  __m128 v62; // xmm6
  __m128 v63; // xmm1
  __m128 v64; // xmm15
  __m128 v65; // xmm15
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm8
  __m128 v70; // xmm4
  __m128 v71; // xmm7
  __m128 v72; // xmm6
  __m128 v73; // xmm3
  __m128 v74; // xmm3
  __m128 v75; // xmm1
  __m128 v76; // xmm1
  __m128 v77; // xmm1
  __m128 v78; // xmm3
  __m128 v79; // xmm8
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  hkpCollisionQualityInfo *v84; // rax
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+20h] [rbp-E0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v86; // [rsp+30h] [rbp-D0h]
  float v87; // [rsp+40h] [rbp-C0h]
  int v88; // [rsp+44h] [rbp-BCh]
  __int64 v89; // [rsp+48h] [rbp-B8h]
  hkVector4f axis; // [rsp+50h] [rbp-B0h]
  hkQuaternionf v91; // [rsp+60h] [rbp-A0h]
  __int64 v92; // [rsp+70h] [rbp-90h]
  hkSimdFloat32 angle; // [rsp+80h] [rbp-80h]
  hkQuaternionf v94; // [rsp+90h] [rbp-70h]
  hkQuaternionf qi; // [rsp+A0h] [rbp-60h]
  __m128 v96; // [rsp+B0h] [rbp-50h]
  hkQuaternionf v97; // [rsp+C0h] [rbp-40h]
  hkVector4f v98; // [rsp+D0h] [rbp-30h]
  hkVector4f v99; // [rsp+E0h] [rbp-20h]
  __int128 v100; // [rsp+F0h] [rbp-10h]
  __int128 v101; // [rsp+100h] [rbp+0h]
  __int128 v102; // [rsp+110h] [rbp+10h]
  __int128 *v103; // [rsp+120h] [rbp+20h]
  __int64 v104; // [rsp+128h] [rbp+28h]
  __m128 v105; // [rsp+130h] [rbp+30h]
  __m128 v106; // [rsp+140h] [rbp+40h]
  float v107; // [rsp+3150h] [rbp+3050h]
  __int64 v108; // [rsp+3170h] [rbp+3070h]
  hkpSimulation *v109; // [rsp+32A0h] [rbp+31A0h]
  hkpEntity **v110; // [rsp+32A8h] [rbp+31A8h]
  signed int v111; // [rsp+32B0h] [rbp+31B0h]

  v110 = entities;
  v109 = this;
  v6 = processInput;
  v7 = numEntities;
  v8 = this;
  v86.m_elem = 0i64;
  v86.m_numElems = 0;
  v86.m_hashMod = -1;
  v9 = entities;
  if ( numEntities )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &v86,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      numEntities);
    v9 = v110;
  }
  v10 = 0i64;
  v11 = 0i64;
  v12 = 2147483648;
  v108 = 0i64;
  v104 = 0i64;
  v107 = FLOAT_3_40282e38;
  entries.m_data = 0i64;
  entries.m_size = 0;
  v89 = 0i64;
  entries.m_capacityAndFlags = 2147483648;
  v92 = v7;
  if ( (signed int)v7 > 0 )
  {
    while ( 1 )
    {
      v13 = v9[v11];
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v86,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)&v13->m_collidable,
        0i64);
      hkpLinkedCollidable::getCollisionEntriesSorted(&v13->m_collidable, &entries);
      v14 = 0;
      if ( entries.m_size > 0 )
        break;
LABEL_20:
      v9 = v110;
      v11 = v89 + 1;
      v89 = v11;
      if ( v11 >= v92 )
        goto LABEL_21;
    }
    v15 = 0i64;
    while ( 1 )
    {
      v16 = entries.m_data;
      v17 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                &v86,
                                (unsigned __int64)entries.m_data[v15].m_partner);
      if ( v17 > v86.m_hashMod )
      {
        v18 = v16[v15].m_agentEntry;
        v19 = v18->m_collidable[0];
        v20 = v19->m_ownerOffset;
        if ( *((_BYTE *)&v19[2].m_boundingVolumeData.m_childShapeKeys + v20) == 5 )
          v21 = *(_QWORD *)(&v18->m_collidable[1][2].m_broadPhaseHandle.m_type + v18->m_collidable[1]->m_ownerOffset);
        else
          v21 = *(_QWORD *)(&v19[2].m_broadPhaseHandle.m_type + v20);
        v104 = v21;
        hkAgentNnMachine_InvalidateTimInAgent(v18, (hkpCollisionInput *)&v6->m_dispatcher);
        processingFunction(v8, v18, v6, (hkpProcessCollisionOutput *)&v103);
        if ( findExtraContacts == 1 && v103 != (__int128 *)&v105 )
        {
          v22 = v16[v15].m_agentEntry;
          v23 = v106;
          v24 = &v13->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
          v25 = (__int128)v13->m_motion.m_motionState.m_transform.m_rotation.m_col1;
          v96 = v13->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          v99.m_quad = (__m128)v13->m_motion.m_motionState.m_transform.m_rotation.m_col0;
          v26 = (__int128)v13->m_motion.m_motionState.m_transform.m_rotation.m_col2;
          v100 = v25;
          v27 = (__int128)v13->m_motion.m_motionState.m_transform.m_translation;
          v101 = v26;
          v102 = v27;
          if ( v22->m_collidable[0] != &v13->m_collidable )
            v23 = _mm_xor_ps(v106, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
          v111 = 786163454;
          v28 = _mm_shuffle_ps(v23, v23, 201);
          v29 = _mm_sub_ps(v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad, v105);
          v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v23), _mm_mul_ps(v28, v29));
          v31 = _mm_shuffle_ps(v30, v30, 201);
          axis.m_quad = v31;
          v32 = _mm_mul_ps(v31, v31);
          v33 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                  _mm_shuffle_ps(v32, v32, 170));
          v34 = _mm_mul_ps(v29, v23);
          v35 = _mm_mul_ps(v29, v29);
          v36 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                  _mm_shuffle_ps(v34, v34, 170));
          v37 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                  _mm_shuffle_ps(v35, v35, 170));
          v38 = _mm_rsqrt_ps(v37);
          v39 = _mm_andnot_ps(
                  _mm_cmpleps(v37, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                      _mm_mul_ps(*(__m128 *)_xmm, v38)),
                    v37));
          v40 = _mm_rcp_ps(v39);
          v41 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v39)), v40), v36);
          if ( v33.m128_f32[0] <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x2EDBE6FEu, (__m128)0x2EDBE6FEu, 0))
            || (v88 = 1065351538,
                v41.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0))) )
          {
            v8 = v109;
          }
          else
          {
            v42 = v6->m_collisionQualityInfo.m_storage;
            v43 = v6->m_tolerance.m_storage;
            v44 = v6->m_tolerance.m_storage * 20.0;
            v6->m_tolerance.m_storage = v44;
            v45 = v42->m_create4dContact;
            v46 = v42->m_createContact;
            v42->m_create4dContact = v44;
            v6->m_collisionQualityInfo.m_storage->m_createContact = v44;
            v87 = v44 * 0.050000001;
            v47 = _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      v41,
                      _mm_max_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v39)), v40),
                          _mm_sub_ps(
                            v36,
                            _mm_shuffle_ps(
                              (__m128)COERCE_UNSIGNED_INT(v44 * 0.050000001),
                              (__m128)COERCE_UNSIGNED_INT(v44 * 0.050000001),
                              0))),
                        aabbOut.m_quad)),
                    _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
            v48 = _mm_andnot_ps(*(__m128 *)_xmm, v47);
            v49 = _mm_cmpltps(v48, *(__m128 *)_xmm);
            v50 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v48), *(__m128 *)_xmm);
            v51 = _mm_cmpltps(*(__m128 *)_xmm, v48);
            v52 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v50), v51), _mm_andnot_ps(v51, v48));
            v53 = _mm_or_ps(_mm_andnot_ps(v51, _mm_mul_ps(v48, v48)), _mm_and_ps(v51, v50));
            v54 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v53, *(__m128 *)coeff4), *(__m128 *)coeff3), v53),
                                  *(__m128 *)coeff2),
                                v53),
                              *(__m128 *)coeff1),
                            v53),
                          *(__m128 *)coeff0),
                        v53),
                      v52),
                    v52);
            v55 = _mm_xor_ps(
                    _mm_or_ps(
                      _mm_andnot_ps(
                        v49,
                        _mm_or_ps(
                          _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v54, v54)), v51),
                          _mm_andnot_ps(v51, v54))),
                      _mm_and_ps(v49, v48)),
                    _mm_and_ps(v47, *(__m128 *)_xmm));
            angle.m_real = _mm_sub_ps(_mm_shuffle_ps(v55, v55, 0), _mm_shuffle_ps(v55, v55, 85));
            v56 = _mm_rsqrt_ps(v33);
            axis.m_quad = _mm_mul_ps(
                            axis.m_quad,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v33), v56)),
                              _mm_mul_ps(v56, *(__m128 *)_xmm)));
            hkQuaternionf::setAxisAngle(&v97, &axis, &angle);
            v57 = v13->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
            v58 = _mm_shuffle_ps(v97.m_vec.m_quad, v97.m_vec.m_quad, 255);
            v59 = _mm_shuffle_ps(
                    v13->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                    v13->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                    255);
            v60 = _mm_mul_ps(v97.m_vec.m_quad, v57);
            v61 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v97.m_vec.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v97.m_vec.m_quad, v97.m_vec.m_quad, 201), v57));
            v62 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v61, v61, 201), _mm_mul_ps(v58, v57)),
                    _mm_mul_ps(v59, v97.m_vec.m_quad));
            qi.m_vec.m_quad = _mm_shuffle_ps(
                                v62,
                                _mm_unpackhi_ps(
                                  v62,
                                  _mm_sub_ps(
                                    _mm_mul_ps(v59, v58),
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                                      _mm_shuffle_ps(v60, v60, 170)))),
                                196);
            hkRotationf::set(&v13->m_motion.m_motionState.m_transform.m_rotation, &qi);
            v63 = v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
            v13->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                             v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                             _mm_add_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v63, v63, 85),
                                                                                   v13->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(
                                                                                     v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad,
                                                                                     v63,
                                                                                     0),
                                                                                   *v24)),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v63, v63, 170),
                                                                                 v13->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
            hkAgentNnMachine_InvalidateTimInAgent(v18, (hkpCollisionInput *)&v6->m_dispatcher);
            processingFunction(v109, v18, v6, (hkpProcessCollisionOutput *)&v103);
            v64 = _mm_sub_ps(
                    _mm_mul_ps(v28, axis.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(axis.m_quad, axis.m_quad, 201), v23));
            v65 = _mm_shuffle_ps(v64, v64, 201);
            v66 = _mm_mul_ps(v65, v65);
            v67 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                    _mm_shuffle_ps(v66, v66, 170));
            v68 = _mm_rsqrt_ps(v67);
            v98.m_quad = _mm_mul_ps(
                           v65,
                           _mm_andnot_ps(
                             _mm_cmpleps(v67, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                               _mm_mul_ps(v68, *(__m128 *)_xmm))));
            hkQuaternionf::setAxisAngle(&v94, &v98, &angle);
            v69 = v96;
            v70 = _mm_shuffle_ps(v94.m_vec.m_quad, v94.m_vec.m_quad, 255);
            v71 = _mm_shuffle_ps(v96, v96, 255);
            v72 = _mm_shuffle_ps(v96, v96, 201);
            v73 = _mm_sub_ps(
                    _mm_mul_ps(v94.m_vec.m_quad, v72),
                    _mm_mul_ps(_mm_shuffle_ps(v94.m_vec.m_quad, v94.m_vec.m_quad, 201), v96));
            v74 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v73, v73, 201), _mm_mul_ps(v70, v96)),
                    _mm_mul_ps(v71, v94.m_vec.m_quad));
            v75 = _mm_mul_ps(v96, v94.m_vec.m_quad);
            v91.m_vec.m_quad = _mm_shuffle_ps(
                                 v74,
                                 _mm_unpackhi_ps(
                                   v74,
                                   _mm_sub_ps(
                                     _mm_mul_ps(v71, v70),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                                       _mm_shuffle_ps(v75, v75, 170)))),
                                 196);
            hkRotationf::set(&v13->m_motion.m_motionState.m_transform.m_rotation, &v91);
            v76 = v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
            v13->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                             v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                             _mm_add_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v76, v76, 85),
                                                                                   v13->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(
                                                                                     v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad,
                                                                                     v76,
                                                                                     0),
                                                                                   *v24)),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v76, v76, 170),
                                                                                 v13->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
            hkAgentNnMachine_InvalidateTimInAgent(v18, (hkpCollisionInput *)&v6->m_dispatcher);
            processingFunction(v109, v18, v6, (hkpProcessCollisionOutput *)&v103);
            v77 = _mm_mul_ps(_mm_shuffle_ps(v94.m_vec.m_quad, v94.m_vec.m_quad, 201), v69);
            v78 = _mm_mul_ps(_mm_shuffle_ps(v94.m_vec.m_quad, v94.m_vec.m_quad, 255), v69);
            v79 = _mm_mul_ps(v69, v94.m_vec.m_quad);
            v80 = _mm_sub_ps(v77, _mm_mul_ps(v94.m_vec.m_quad, v72));
            v81 = _mm_sub_ps(_mm_add_ps(v78, _mm_shuffle_ps(v80, v80, 201)), _mm_mul_ps(v94.m_vec.m_quad, v71));
            v82 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 78), v79);
            v91.m_vec.m_quad = _mm_shuffle_ps(
                                 v81,
                                 _mm_unpackhi_ps(v81, _mm_add_ps(_mm_shuffle_ps(v82, v82, 177), v82)),
                                 196);
            hkRotationf::set(&v13->m_motion.m_motionState.m_transform.m_rotation, &v91);
            v83 = v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
            v13->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                             v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                             _mm_add_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v83, v83, 85),
                                                                                   v13->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(
                                                                                     v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad,
                                                                                     v83,
                                                                                     0),
                                                                                   *v24)),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v83, v83, 170),
                                                                                 v13->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
            hkAgentNnMachine_InvalidateTimInAgent(v18, (hkpCollisionInput *)&v6->m_dispatcher);
            v8 = v109;
            processingFunction(v109, v18, v6, (hkpProcessCollisionOutput *)&v103);
            v84 = v6->m_collisionQualityInfo.m_storage;
            v6->m_tolerance.m_storage = v43;
            v84->m_create4dContact = v45;
            v6->m_collisionQualityInfo.m_storage->m_createContact = v46;
            ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v13->m_motion.vfptr[8].__first_virtual_table_function__)(
              &v13->m_motion,
              &v99);
            hkAgentNnMachine_InvalidateTimInAgent(v18, (hkpCollisionInput *)&v6->m_dispatcher);
            processingFunction(v109, v18, v6, (hkpProcessCollisionOutput *)&v103);
          }
        }
        if ( hkOutOfMemoryState == 1 )
          break;
      }
      ++v14;
      ++v15;
      if ( v14 >= entries.m_size )
        goto LABEL_20;
    }
LABEL_21:
    v12 = entries.m_capacityAndFlags;
    v10 = entries.m_data;
  }
  entries.m_size = 0;
  if ( v12 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkpLinkedCollidable::CollisionEntry *, _QWORD, hkpEntity **))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v10,
      (unsigned int)(16 * v12),
      v9);
  entries.m_data = 0i64;
  entries.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v86,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v86);
}

// File Line: 1017
// RVA: 0xD6A900
void __fastcall hkpSimulation::reintegrateAndRecollideEntities(hkpSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world, int reintegrateRecollideMode)
{
  hkpSimulation *v5; // rbx
  __int64 v6; // r15
  hkpWorld *v7; // rdi
  hkpEntity **v8; // r14
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  __m128i *v13; // rax
  __int64 v14; // rsi
  hkpEntity *v15; // rbx
  float v16; // xmm0_4
  hkpSimulation::FindContacts findExtraContacts; // ST20_4
  bool v18; // zf
  hkStepInfo info; // [rsp+30h] [rbp-48h]
  hkpSimulation *v20; // [rsp+80h] [rbp+8h]

  v20 = this;
  ++world->m_criticalOperationsLockCount;
  v5 = this;
  v6 = numEntities;
  v7 = world;
  v8 = entities;
  v9 = hkpWorld::getCurrentPsiTime(world);
  v10 = hkpWorld::getCurrentTime(v7);
  info.m_endTime.m_storage = v9;
  v11 = v9 - v10;
  info.m_startTime.m_storage = v10;
  v12 = 0.0;
  info.m_deltaTime.m_storage = v11;
  if ( v11 != 0.0 )
    v12 = 1.0 / v11;
  v13 = (__m128i *)v7->m_collisionInput;
  info.m_invDeltaTime.m_storage = v12;
  _mm_store_si128(v13 + 6, (__m128i)info);
  if ( reintegrateRecollideMode & 1 )
  {
    v14 = 0i64;
    if ( (signed int)v6 > 0 )
    {
      do
      {
        v15 = v8[v14];
        if ( v15->m_motion.m_type.m_storage != 5 )
        {
          v16 = hkpWorld::getCurrentTime(v7);
          hkSweptTransformUtil::backStepMotionState(v16, &v15->m_motion.m_motionState);
        }
        ++v14;
      }
      while ( v14 < v6 );
      v5 = v20;
    }
    hkRigidMotionUtilStep(&info, (hkpMotion *const *)v8, v6, 336);
    hkpEntityAabbUtil::entityBatchRecalcAabb((hkpCollisionInput *)&v7->m_collisionInput->m_dispatcher, v8, v6);
  }
  if ( reintegrateRecollideMode & 2 )
    hkpSimulation::collideEntitiesBroadPhaseDiscrete(v8, v6, v7);
  if ( reintegrateRecollideMode & 4 )
  {
    hkpSimulation::collideEntitiesNarrowPhaseDiscrete(v5, v8, v6, v7->m_collisionInput, 0);
  }
  else if ( reintegrateRecollideMode & 1 )
  {
    findExtraContacts = 2;
    ((void (__fastcall *)(hkpSimulation *, hkpEntity **, _QWORD, hkpWorld *, hkpSimulation::FindContacts))v5->vfptr[6].__vecDelDtor)(
      v5,
      v8,
      (unsigned int)v6,
      v7,
      findExtraContacts);
  }
  v18 = v7->m_criticalOperationsLockCount-- == 1;
  if ( v18 && !v7->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v7->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v7);
    if ( v7->m_pendingOperationQueueCount == 1 )
    {
      if ( v7->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v7);
    }
  }
}

// File Line: 1074
// RVA: 0xD6C210
void __fastcall hkLs_doSimpleCollisionResponse(hkpWorld *world, hkpToiEvent *event, float rotateNormal, hkArray<hkpEntity *,hkContainerHeapAllocator> *toBeActivated)
{
  hkpEntity *v4; // rsi
  hkpEntity *v5; // rdi
  hkpWorld *v6; // r12
  char v7; // cl
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v8; // rbx
  hkpToiEvent *v9; // r14
  unsigned __int16 v10; // ax
  char v11; // cl
  unsigned __int16 v12; // ax
  hkpDynamicsContactMgr *v13; // rax
  unsigned __int8 v14; // al
  __int64 v15; // rcx
  hkpEntity **v16; // rax
  bool v17; // cf
  bool v18; // zf
  unsigned __int8 v19; // al
  hkpSimpleCollisionResponse::SolveSingleOutput output; // [rsp+18h] [rbp-29h]
  hkpSimpleConstraintUtilCollideParams params; // [rsp+28h] [rbp-19h]
  hkpContactImpulseLimitBreachedListenerInfo breachedContacts; // [rsp+48h] [rbp+7h]
  int v23; // [rsp+B8h] [rbp+77h]

  v4 = event->m_entities[0];
  v5 = event->m_entities[1];
  v6 = world;
  v7 = event->m_properties.m_friction.m_value;
  params.m_externalSeperatingVelocity = event->m_seperatingVelocity;
  params.m_extraSeparatingVelocity = FLOAT_0_1;
  params.m_extraSlope = rotateNormal;
  v8 = toBeActivated;
  v9 = event;
  v10 = hkUFloat8::getEncodedFloat(v7);
  v23 = (v10 + 243712) << 12;
  if ( v10 )
    LODWORD(params.m_friction) = v23;
  else
    params.m_friction = 0.0;
  v11 = v9->m_properties.m_maxImpulse.m_value;
  params.m_restitution = (float)(unsigned __int8)v9->m_properties.m_restitution * 0.0078125;
  if ( v11 )
  {
    v12 = hkUFloat8::getEncodedFloat(v11);
    v23 = (v12 + 243712) << 12;
    if ( v12 )
      LODWORD(params.m_maxImpulse) = v23;
    else
      params.m_maxImpulse = 0.0;
  }
  else
  {
    params.m_maxImpulse = FLOAT_3_40282e38;
  }
  hkpSimpleCollisionResponse::solveSingleContact(
    &v9->m_contactPoint,
    v9->m_time,
    &params,
    (hkpMotion *)&v4->m_motion.vfptr,
    (hkpMotion *)&v5->m_motion.vfptr,
    v9->m_contactMgr,
    &output);
  if ( params.m_contactImpulseLimitBreached.m_bool )
  {
    v13 = v9->m_contactMgr;
    *(_DWORD *)&breachedContacts.m_data.m_solver.m_type = 65538;
    breachedContacts.m_data.m_solver.m_constraintInstance = (hkpConstraintInstance *)&v13[3].m_world;
    breachedContacts.m_data.m_single.m_contactPoint = &v9->m_contactPoint;
    breachedContacts.m_data.m_solver.m_solverResult = &v9->m_properties.0;
    hkpWorldCallbackUtil::fireContactImpulseLimitBreached(v6, &breachedContacts, 1);
    return;
  }
  if ( output.m_velocityKeyframedA >= 0.0 )
  {
    if ( output.m_velocityKeyframedB < 0.0 )
    {
      v15 = v8->m_size;
      v19 = v5->m_motion.m_type.m_storage - 4;
      v17 = v19 < 1u;
      v18 = v19 == 1;
      v16 = v8->m_data;
      if ( v17 || v18 )
      {
        v16[v15] = v4;
        goto LABEL_18;
      }
      goto LABEL_17;
    }
    if ( (unsigned __int8)(v4->m_motion.m_type.m_storage - 4) > 1u
      && ((unsigned __int8)(v5->m_motion.m_type.m_storage - 4) <= 1u
       || output.m_velocityKeyframedA <= output.m_velocityKeyframedB) )
    {
      v8->m_data[v8->m_size] = v4;
      goto LABEL_18;
    }
    goto LABEL_16;
  }
  v14 = v4->m_motion.m_type.m_storage - 4;
  if ( output.m_velocityKeyframedB >= 0.0 )
  {
    v15 = v8->m_size;
    v17 = v14 < 1u;
    v18 = v14 == 1;
    v16 = v8->m_data;
    if ( !v17 && !v18 )
    {
      v16[v15] = v4;
      goto LABEL_18;
    }
LABEL_17:
    v16[v15] = v5;
LABEL_18:
    ++v8->m_size;
    return;
  }
  if ( v14 > 1u )
    v8->m_data[v8->m_size++] = v4;
  if ( (unsigned __int8)(v5->m_motion.m_type.m_storage - 4) > 1u )
  {
LABEL_16:
    v15 = v8->m_size;
    v16 = v8->m_data;
    goto LABEL_17;
  }
}

