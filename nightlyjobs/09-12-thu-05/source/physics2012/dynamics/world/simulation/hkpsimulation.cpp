// File Line: 85
// RVA: 0xD69B20
void __fastcall hkpSimulation::hkpSimulation(hkpSimulation *this, hkpWorld *world)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_world = world;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimulation::`vftable;
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
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 99
// RVA: 0xD69B80
void __fastcall hkpSimulation::create(hkpWorld *world)
{
  _QWORD **Value; // rax
  hkpSimulation *v3; // rax

  hkOptionalComponent_hkpSimulation.m_isUsed.m_bool = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  if ( v3 )
    hkpSimulation::hkpSimulation(v3, world);
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
  _QWORD *Value; // r8
  _QWORD *v4; // rcx
  unsigned __int64 v5; // rax
  _QWORD *v6; // rcx
  float m_currentPsiTime; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  hkpWorld *m_world; // rax
  unsigned int v11; // edi
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkStepInfo stepInfoIn; // [rsp+20h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v4 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v4 < Value[3] )
  {
    *v4 = "TtPhysics 2012";
    v5 = __rdtsc();
    v6 = v4 + 2;
    *((_DWORD *)v6 - 2) = v5;
    Value[1] = v6;
  }
  m_currentPsiTime = this->m_currentPsiTime;
  this->m_physicsDeltaTime = physicsDeltaTime;
  stepInfoIn.m_startTime.m_storage = m_currentPsiTime;
  stepInfoIn.m_endTime.m_storage = m_currentPsiTime + physicsDeltaTime;
  v8 = (float)(m_currentPsiTime + physicsDeltaTime) - m_currentPsiTime;
  v9 = 0.0;
  stepInfoIn.m_deltaTime.m_storage = v8;
  if ( v8 != 0.0 )
    v9 = 1.0 / v8;
  m_world = this->m_world;
  stepInfoIn.m_invDeltaTime.m_storage = v9;
  m_world->m_dynamicsStepInfo.m_stepInfo = stepInfoIn;
  this->m_world->m_collisionInput->m_stepInfo = stepInfoIn;
  ((void (__fastcall *)(hkpWorldMaintenanceMgr *, hkpWorld *, hkStepInfo *))this->m_world->m_maintenanceMgr->vfptr[2].__vecDelDtor)(
    this->m_world->m_maintenanceMgr,
    this->m_world,
    &stepInfoIn);
  v11 = hkpSimulation::integrateInternal(this, &stepInfoIn);
  this->m_previousStepResult = v11;
  if ( !v11 )
    this->m_lastProcessingStep.m_storage = 0;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = v13 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v12[1] = v15;
  }
  return v11;
}

// File Line: 165
// RVA: 0xD69D70
__int64 __fastcall hkpSimulation::collide(hkpSimulation *this)
{
  _QWORD *Value; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  _QWORD *v5; // rcx
  unsigned int v6; // edi
  float v7; // xmm0_4
  hkBaseObjectVtbl *vfptr; // rax
  hkpWorld *m_world; // rcx
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
  hkStepInfo info; // [rsp+20h] [rbp-18h] BYREF

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
    v6 = hkpSimulation::reCollideAfterStepFailure(this);
  }
  else
  {
    info.m_startTime.m_storage = this->m_currentPsiTime;
    info.m_endTime.m_storage = info.m_startTime.m_storage + this->m_physicsDeltaTime;
    v7 = 0.0;
    info.m_deltaTime.m_storage = info.m_endTime.m_storage - info.m_startTime.m_storage;
    if ( (float)(info.m_endTime.m_storage - info.m_startTime.m_storage) != 0.0 )
      v7 = 1.0 / (float)(info.m_endTime.m_storage - info.m_startTime.m_storage);
    vfptr = this->vfptr;
    info.m_invDeltaTime.m_storage = v7;
    ((void (__fastcall *)(hkpSimulation *, hkStepInfo *, LPVOID))vfptr[8].__first_virtual_table_function__)(
      this,
      &info,
      Value);
    if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
    {
      v6 = 2;
    }
    else
    {
      m_world = this->m_world;
      this->m_currentPsiTime = this->m_physicsDeltaTime + this->m_currentPsiTime;
      hkpWorld::checkConstraintsViolated(m_world);
      if ( this->m_world->m_worldPostCollideListeners.m_size )
      {
        v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v11 = (_QWORD *)v10[1];
        if ( (unsigned __int64)v11 < v10[3] )
        {
          *v11 = "TtPostCollideCB";
          v12 = __rdtsc();
          v13 = v11 + 2;
          *((_DWORD *)v13 - 2) = v12;
          v10[1] = v13;
        }
        hkpWorldCallbackUtil::firePostCollideCallback(this->m_world, &info);
        v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v15 = (_QWORD *)v14[1];
        if ( (unsigned __int64)v15 < v14[3] )
        {
          *v15 = "Et";
          v16 = __rdtsc();
          v17 = v15 + 2;
          *((_DWORD *)v17 - 2) = v16;
          v14[1] = v17;
        }
      }
      this->m_lastProcessingStep.m_storage = 1;
      v6 = 0;
    }
    this->m_previousStepResult = v6;
  }
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  v20 = v18;
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v21 = __rdtsc();
    v22 = v19 + 2;
    *((_DWORD *)v22 - 2) = v21;
    v20[1] = v22;
  }
  return v6;
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
  float m_currentPsiTime; // xmm1_4
  float m_currentTime; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD *Value; // r8
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  hkpWorld *m_world; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax
  hkStepInfo info; // [rsp+20h] [rbp-18h] BYREF

  hkpWorld::updateCollisionFilterOnWorld(
    this->m_world,
    HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
    HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  if ( this->m_previousStepResult == 3 )
  {
    m_currentPsiTime = this->m_currentPsiTime;
    m_currentTime = this->m_currentTime;
  }
  else
  {
    m_currentTime = this->m_currentPsiTime;
    m_currentPsiTime = m_currentTime + this->m_physicsDeltaTime;
  }
  info.m_endTime.m_storage = m_currentPsiTime;
  v4 = m_currentPsiTime - m_currentTime;
  info.m_startTime.m_storage = m_currentTime;
  v5 = 0.0;
  info.m_deltaTime.m_storage = v4;
  if ( v4 != 0.0 )
    v5 = 1.0 / v4;
  vfptr = this->vfptr;
  info.m_invDeltaTime.m_storage = v5;
  ((void (__fastcall *)(hkpSimulation *, hkStepInfo *))vfptr[8].__first_virtual_table_function__)(this, &info);
  if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
  {
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v8 = Value[1];
    if ( v8 < Value[3] )
    {
      *(_QWORD *)v8 = "Et";
      v9 = __rdtsc();
      *(_DWORD *)(v8 + 8) = v9;
      Value[1] = v8 + 16;
    }
    return this->m_previousStepResult;
  }
  else
  {
    if ( this->m_previousStepResult == 2 )
    {
      m_world = this->m_world;
      this->m_currentPsiTime = this->m_physicsDeltaTime + this->m_currentPsiTime;
      if ( m_world->m_worldPostCollideListeners.m_size )
      {
        v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v13 = (_QWORD *)v12[1];
        if ( (unsigned __int64)v13 < v12[3] )
        {
          *v13 = "TtPostCollideCB";
          v14 = __rdtsc();
          v15 = v13 + 2;
          *((_DWORD *)v15 - 2) = v14;
          v12[1] = v15;
        }
        hkpWorldCallbackUtil::firePostCollideCallback(this->m_world, &info);
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
      this->m_lastProcessingStep.m_storage = 1;
    }
    this->m_previousStepResult = 0;
    return 0i64;
  }
}

// File Line: 300
// RVA: 0xD6B6F0
float __fastcall hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo(hkpSimulation *this)
{
  float m_simulateUntilTime; // xmm0_4
  float m_currentPsiTime; // xmm2_4
  float v3; // xmm0_4

  m_simulateUntilTime = this->m_simulateUntilTime;
  if ( m_simulateUntilTime != -1.0 )
  {
    m_currentPsiTime = this->m_currentPsiTime;
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(m_simulateUntilTime - m_currentPsiTime)) >> 1) < this->m_frameMarkerPsiSnap )
      this->m_simulateUntilTime = m_currentPsiTime;
  }
  v3 = this->m_simulateUntilTime;
  if ( v3 == -1.0 )
    return this->m_currentPsiTime;
  else
    return fminf(this->m_currentPsiTime, v3);
}

// File Line: 331
// RVA: 0xD69F30
__int64 __fastcall hkpSimulation::advanceTime(hkpSimulation *this)
{
  float TimeToAdvanceTo; // xmm0_4
  bool v3; // cf
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  __int64 result; // rax

  TimeToAdvanceTo = hkpSimulation::snapSimulateTimeAndGetTimeToAdvanceTo(this);
  v3 = TimeToAdvanceTo < this->m_simulateUntilTime;
  this->m_currentTime = TimeToAdvanceTo;
  if ( !v3 && this->m_world->m_worldPostSimulationListeners.m_size )
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
  result = 0i64;
  this->m_previousStepResult = 0;
  return result;
}

// File Line: 349
// RVA: 0xD69BD0
__int64 __fastcall hkpSimulation::stepDeltaTime(hkpSimulation *this, float physicsDeltaTime)
{
  unsigned int m_previousStepResult; // eax

  if ( this->m_previousStepResult <= 1 )
    ((void (__fastcall *)(hkpSimulation *))this->vfptr[2].__vecDelDtor)(this);
  if ( (this->m_previousStepResult & 0xFFFFFFFD) == 0 )
    this->vfptr[2].__first_virtual_table_function__(this);
  m_previousStepResult = this->m_previousStepResult;
  if ( !m_previousStepResult || m_previousStepResult == 3 )
    ((void (__fastcall *)(hkpSimulation *))this->vfptr[3].__vecDelDtor)(this);
  if ( this->m_previousStepResult && hkpWorld::getMemoryWatchDog(this->m_world) )
    hkpWorldMemoryUtil::tryToRecoverFromMemoryErrors(this->m_world);
  return this->m_previousStepResult;
}

// File Line: 383
// RVA: 0xD6A220
void __fastcall hkpSimulation::collideEntitiesBroadPhaseDiscrete(
        hkpEntity **entities,
        unsigned int numEntities,
        hkpWorld *world)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  int m_broadPhaseUpdateSize; // ebx
  hkLifoAllocator *v11; // rcx
  hkpBroadPhaseHandlePair *m_cur; // rax
  int v13; // edx
  char *v14; // r8
  int v15; // ebx
  hkLifoAllocator *v16; // rcx
  hkpBroadPhaseHandlePair *v17; // rax
  int v18; // edx
  char *v19; // r8
  hkLifoAllocator *v20; // rax
  char *v21; // r12
  int v22; // ebx
  char *v23; // rcx
  hkLifoAllocator *v24; // rax
  char *v25; // r15
  int v26; // edx
  char *v27; // rcx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  int v32; // r14d
  char *v33; // rdi
  signed __int64 v34; // r12
  hkpLinkedCollidable *p_m_collidable; // rbx
  char *v36; // rcx
  signed __int64 v37; // rbx
  __int64 v38; // rdx
  __int64 v39; // rax
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  hkLifoAllocator *v44; // rax
  int v45; // r8d
  hkLifoAllocator *v46; // rax
  int v47; // r8d
  _QWORD *v48; // r8
  _QWORD *v49; // rcx
  unsigned __int64 v50; // rax
  _QWORD *v51; // rcx
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  _QWORD *v55; // rcx
  int m_size; // ebx
  hkMemorySystem *Instance; // rax
  _QWORD *v58; // r8
  unsigned __int64 v59; // rcx
  unsigned __int64 v60; // rax
  int v61; // eax
  char *v62; // rdi
  signed int v63; // ebx
  hkLifoAllocator *v64; // rax
  int v65; // r8d
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidableCollidableFilter *v71; // r9
  int v72; // eax
  char *v73; // rdi
  signed int v74; // ebx
  hkLifoAllocator *v75; // rax
  int v76; // r8d
  hkpEntity *entityBatch; // [rsp+30h] [rbp-39h] BYREF
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+38h] [rbp-31h] BYREF
  void *p; // [rsp+48h] [rbp-21h]
  int v80; // [rsp+50h] [rbp-19h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+58h] [rbp-11h] BYREF
  void *v82; // [rsp+68h] [rbp-1h]
  int v83; // [rsp+70h] [rbp+7h]
  int v84; // [rsp+D0h] [rbp+67h]
  int v86; // [rsp+E0h] [rbp+77h]
  char *v87; // [rsp+E8h] [rbp+7Fh]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtBroadPhase";
    *(_QWORD *)(v7 + 16) = "StInitMem";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  m_broadPhaseUpdateSize = world->m_broadPhaseUpdateSize;
  newPairs.m_capacityAndFlags = 0x80000000;
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  v83 = m_broadPhaseUpdateSize;
  if ( m_broadPhaseUpdateSize )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpBroadPhaseHandlePair *)v11->m_cur;
    v13 = (16 * m_broadPhaseUpdateSize + 127) & 0xFFFFFF80;
    v14 = (char *)m_cur + v13;
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
      m_cur = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
    else
      v11->m_cur = v14;
  }
  else
  {
    m_cur = 0i64;
  }
  newPairs.m_data = m_cur;
  v82 = m_cur;
  newPairs.m_capacityAndFlags = m_broadPhaseUpdateSize | 0x80000000;
  v15 = world->m_broadPhaseUpdateSize;
  delPairs.m_data = 0i64;
  delPairs.m_size = 0;
  delPairs.m_capacityAndFlags = 0x80000000;
  v80 = v15;
  if ( v15 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkpBroadPhaseHandlePair *)v16->m_cur;
    v18 = (16 * v15 + 127) & 0xFFFFFF80;
    v19 = (char *)v17 + v18;
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
      v17 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
    else
      v16->m_cur = v19;
  }
  else
  {
    v17 = 0i64;
  }
  delPairs.m_data = v17;
  delPairs.m_capacityAndFlags = v15 | 0x80000000;
  p = v17;
  v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (char *)v20->m_cur;
  v87 = v21;
  v22 = (32 * numEntities + 127) & 0xFFFFFF80;
  v84 = v22;
  v23 = &v21[v22];
  if ( v22 > v20->m_slabSize || v23 > v20->m_end )
  {
    v21 = (char *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
    v87 = v21;
  }
  else
  {
    v20->m_cur = v23;
  }
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (char *)v24->m_cur;
  v26 = (8 * numEntities + 127) & 0xFFFFFF80;
  v86 = v26;
  v27 = &v25[v26];
  if ( v26 > v24->m_slabSize || v27 > v24->m_end )
    v25 = (char *)hkLifoAllocator::allocateFromNewSlab(v24, v26);
  else
    v24->m_cur = v27;
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "StCalcAabbs";
    v30 = __rdtsc();
    v31 = v29 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v28[1] = v31;
  }
  v32 = numEntities - 1;
  v33 = v21;
  if ( v32 >= 0 )
  {
    v34 = v25 - (char *)entities;
    do
    {
      entityBatch = *entities;
      p_m_collidable = &entityBatch->m_collidable;
      *(hkpEntity **)((char *)entities + v34) = (hkpEntity *)&entityBatch->m_collidable.m_broadPhaseHandle;
      if ( p_m_collidable->m_boundingVolumeData.m_min[0] > p_m_collidable->m_boundingVolumeData.m_max[0] )
        hkpEntityAabbUtil::entityBatchRecalcAabb(world->m_collisionInput, &entityBatch, 1);
      v36 = v33;
      v37 = (char *)p_m_collidable - v33;
      v38 = 4i64;
      do
      {
        v39 = *(_QWORD *)&v36[v37 + 48];
        v36 += 8;
        *((_QWORD *)v36 - 1) = v39;
        --v38;
      }
      while ( v38 );
      v33 += 32;
      ++entities;
      --v32;
    }
    while ( v32 >= 0 );
    v21 = v87;
    v22 = v84;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "St3AxisSweep";
    v42 = __rdtsc();
    v43 = v41 + 2;
    *((_DWORD *)v43 - 2) = v42;
    v40[1] = v43;
  }
  ((void (__fastcall *)(hkpBroadPhase *, char *, char *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkpEntity *))world->m_broadPhase->vfptr[6].__vecDelDtor)(
    world->m_broadPhase,
    v25,
    v21,
    numEntities,
    &newPairs,
    &delPairs,
    entityBatch);
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = (v86 + 15) & 0xFFFFFFF0;
  if ( v86 > v44->m_slabSize || &v25[v45] != v44->m_cur || v44->m_firstNonLifoEnd == v25 )
    hkLifoAllocator::slowBlockFree(v44, v25, v45);
  else
    v44->m_cur = v25;
  v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v47 = (v22 + 15) & 0xFFFFFFF0;
  if ( v22 > v46->m_slabSize || &v21[v47] != v46->m_cur || v46->m_firstNonLifoEnd == v21 )
    hkLifoAllocator::slowBlockFree(v46, v21, v47);
  else
    v46->m_cur = v21;
  if ( delPairs.m_size + newPairs.m_size > 0 )
  {
    v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v49 = (_QWORD *)v48[1];
    if ( (unsigned __int64)v49 < v48[3] )
    {
      *v49 = "StRemoveDup";
      v50 = __rdtsc();
      v51 = v49 + 2;
      *((_DWORD *)v51 - 2) = v50;
      v48[1] = v51;
    }
    hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &delPairs);
    v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v53 = (_QWORD *)v52[1];
    if ( (unsigned __int64)v53 < v52[3] )
    {
      *v53 = "StRemoveAgt";
      v54 = __rdtsc();
      v55 = v53 + 2;
      *((_DWORD *)v55 - 2) = v54;
      v52[1] = v55;
    }
    hkpTypedBroadPhaseDispatcher::removePairs(
      world->m_broadPhaseDispatcher,
      (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
      delPairs.m_size);
    m_size = newPairs.m_size;
    Instance = hkMemorySystem::getInstance();
    if ( !Instance->vfptr->heapCanAllocTotal(Instance, 640 * m_size) )
    {
      hkSetOutOfMemoryState(MEMORY_STATE_OUT_OF_MEMORY);
      v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v59 = v58[1];
      if ( v59 >= v58[3] )
        goto LABEL_53;
      goto LABEL_52;
    }
    v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v67 = (_QWORD *)v66[1];
    if ( (unsigned __int64)v67 < v66[3] )
    {
      *v67 = "StAddAgt";
      v68 = __rdtsc();
      v69 = v67 + 2;
      *((_DWORD *)v69 - 2) = v68;
      v66[1] = v69;
    }
    m_collisionFilter = world->m_collisionFilter;
    v71 = &m_collisionFilter->hkpCollidableCollidableFilter;
    if ( !m_collisionFilter )
      v71 = 0i64;
    hkpTypedBroadPhaseDispatcher::addPairs(
      world->m_broadPhaseDispatcher,
      (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
      newPairs.m_size,
      v71);
  }
  v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v59 = v58[1];
  if ( v59 < v58[3] )
  {
LABEL_52:
    *(_QWORD *)v59 = "lt";
    v60 = __rdtsc();
    *(_DWORD *)(v59 + 8) = v60;
    v58[1] = v59 + 16;
  }
LABEL_53:
  v61 = delPairs.m_size;
  v62 = (char *)p;
  if ( p == delPairs.m_data )
    v61 = 0;
  delPairs.m_size = v61;
  v63 = (16 * v80 + 127) & 0xFFFFFF80;
  v64 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (v63 + 15) & 0xFFFFFFF0;
  if ( v63 > v64->m_slabSize || &v62[v65] != v64->m_cur || v64->m_firstNonLifoEnd == v62 )
    hkLifoAllocator::slowBlockFree(v64, v62, v65);
  else
    v64->m_cur = v62;
  delPairs.m_size = 0;
  if ( delPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      delPairs.m_data,
      16 * delPairs.m_capacityAndFlags);
  v72 = newPairs.m_size;
  v73 = (char *)v82;
  delPairs.m_data = 0i64;
  if ( v82 == newPairs.m_data )
    v72 = 0;
  delPairs.m_capacityAndFlags = 0x80000000;
  newPairs.m_size = v72;
  v74 = (16 * v83 + 127) & 0xFFFFFF80;
  v75 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v76 = (v74 + 15) & 0xFFFFFFF0;
  if ( v74 > v75->m_slabSize || &v73[v76] != v75->m_cur || v75->m_firstNonLifoEnd == v73 )
    hkLifoAllocator::slowBlockFree(v75, v73, v76);
  else
    v75->m_cur = v73;
  newPairs.m_size = 0;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      16 * newPairs.m_capacityAndFlags);
}

// File Line: 487
// RVA: 0xD6AC70
void __fastcall hkpSimulation::collideInternal(hkpSimulation *this, hkStepInfo *stepInfoIn)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  int v9; // edi
  hkpWorld *m_world; // rax
  float m_numSteps; // xmm1_4
  hkpWorld *v12; // r14
  __int64 v13; // rsi
  hkpWorld *v14; // rdi
  bool v15; // zf
  int v16; // edi
  hkpWorld *v17; // r15
  __int64 v18; // rsi
  hkpSimulationIsland *v19; // rbp
  hkpProcessCollisionInput *m_collisionInput; // r14
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r9
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  __int64 v26; // rax
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  _QWORD *v31; // r8
  _QWORD *v32; // rcx
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  hkpWorld *v39; // rbx
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollide";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  v9 = 0;
  this->m_world->m_dynamicsStepInfo.m_stepInfo = *stepInfoIn;
  this->m_world->m_collisionInput->m_stepInfo = *stepInfoIn;
  m_world = this->m_world;
  m_numSteps = (float)m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  m_world->m_dynamicsStepInfo.m_solverInfo.m_deltaTime = m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps
                                                       * stepInfoIn->m_deltaTime.m_storage;
  m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime = m_numSteps * stepInfoIn->m_invDeltaTime.m_storage;
  ++this->m_world->m_criticalOperationsLockCount;
  v12 = this->m_world;
  if ( v12->m_activeSimulationIslands.m_size <= 0 )
  {
LABEL_7:
    v14 = this->m_world;
    v15 = v14->m_criticalOperationsLockCount-- == 1;
    if ( v15 && !v14->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v14->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v14);
      if ( v14->m_pendingOperationQueueCount == 1 && v14->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v14);
    }
    v16 = 0;
    ++this->m_world->m_criticalOperationsLockCount;
    v17 = this->m_world;
    if ( v17->m_activeSimulationIslands.m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        v19 = v17->m_activeSimulationIslands.m_data[v18];
        m_collisionInput = this->m_world->m_collisionInput;
        v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v22 = (_QWORD *)v21[1];
        v23 = v21;
        if ( (unsigned __int64)v22 < v21[3] )
        {
          *v22 = "TtNarrowPhase";
          v24 = __rdtsc();
          v25 = v22 + 2;
          *((_DWORD *)v25 - 2) = v24;
          v23[1] = v25;
        }
        v26 = (__int64)&m_collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[1];
        m_collisionInput->m_createPredictiveAgents.m_storage = 0;
        m_collisionInput->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v26;
        hkAgentNnMachine_ProcessTrack(v19, &v19->m_narrowphaseAgentTrack, m_collisionInput);
        hkAgentNnMachine_ProcessTrack(v19, &v19->m_midphaseAgentTrack, m_collisionInput);
        v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v28 = (_QWORD *)v27[1];
        if ( (unsigned __int64)v28 < v27[3] )
        {
          *v28 = "Et";
          v29 = __rdtsc();
          v30 = v28 + 2;
          *((_DWORD *)v30 - 2) = v29;
          v27[1] = v30;
        }
        if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
          break;
        if ( this->m_world->m_islandPostCollideListeners.m_size )
        {
          v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v32 = (_QWORD *)v31[1];
          if ( (unsigned __int64)v32 < v31[3] )
          {
            *v32 = "TtIslandPostCollideCb";
            v33 = __rdtsc();
            v34 = v32 + 2;
            *((_DWORD *)v34 - 2) = v33;
            v31[1] = v34;
          }
          hkpWorldCallbackUtil::fireIslandPostCollideCallback(this->m_world, v19, stepInfoIn);
          v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v36 = (_QWORD *)v35[1];
          if ( (unsigned __int64)v36 < v35[3] )
          {
            *v36 = "Et";
            v37 = __rdtsc();
            v38 = v36 + 2;
            *((_DWORD *)v38 - 2) = v37;
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
        this->m_world);
      if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
        break;
      ++v9;
      ++v13;
      if ( v9 >= v12->m_activeSimulationIslands.m_size )
        goto LABEL_7;
    }
  }
  v39 = this->m_world;
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
    v44 = v41 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v42[1] = v44;
  }
}

// File Line: 590
// RVA: 0xD6AFE0
__int64 __fastcall hkpSimulation::integrateInternal(hkpSimulation *this, hkStepInfo *stepInfoIn)
{
  _QWORD *Value; // r8
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rax
  hkpSolverInfo *p_m_solverInfo; // rcx
  float m_numSteps; // xmm1_4
  hkMemorySystem *Instance; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkpWorld *m_world; // rbx
  bool v15; // zf
  hkpWorld *v16; // rcx
  char v17; // al
  hkpSolverInfo *v18; // rcx
  hkpWorld *v19; // rcx
  hkpViolatedConstraintArray *m_violatedConstraintArray; // rax
  float m_damping; // xmm1_4
  float v22; // xmm1_4
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  hkpWorld *v27; // r14
  int v28; // eax
  __int64 i; // rbp
  hkpWorld *v30; // rsi
  hkpSimulationIsland *v31; // rbx
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  int v36; // esi
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  __int64 result; // rax
  hkpWorld *v42; // rcx
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  hkpWorld *v47; // rbx
  _QWORD *v48; // r8
  _QWORD *v49; // rcx
  unsigned __int64 v50; // rax
  _QWORD *v51; // rcx
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  _QWORD *v55; // rcx
  _QWORD *v56; // rax
  _QWORD *v57; // rcx
  _QWORD *v58; // r8
  unsigned __int64 v59; // rax
  _QWORD *v60; // rcx
  hkWorldMemoryAvailableWatchDog::MemUsageInfo infoOut; // [rsp+40h] [rbp-C8h] BYREF
  hkpConstraintQueryIn constraintQueryIn; // [rsp+50h] [rbp-B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = Value[1];
  if ( v5 < Value[3] )
  {
    *(_QWORD *)v5 = "LtIntegrate";
    *(_QWORD *)(v5 + 16) = "StInit";
    v6 = __rdtsc();
    *(_DWORD *)(v5 + 8) = v6;
    Value[1] = v5 + 24;
  }
  this->m_world->m_dynamicsStepInfo.m_stepInfo = *stepInfoIn;
  p_m_solverInfo = &this->m_world->m_dynamicsStepInfo.m_solverInfo;
  m_numSteps = (float)this->m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  p_m_solverInfo->m_deltaTime = p_m_solverInfo->m_invNumSteps * stepInfoIn->m_deltaTime.m_storage;
  p_m_solverInfo->m_invDeltaTime = m_numSteps * stepInfoIn->m_invDeltaTime.m_storage;
  p_m_solverInfo->m_globalAccelerationPerSubStep.m_quad = _mm_mul_ps(
                                                            _mm_shuffle_ps(
                                                              (__m128)LODWORD(p_m_solverInfo->m_deltaTime),
                                                              (__m128)LODWORD(p_m_solverInfo->m_deltaTime),
                                                              0),
                                                            this->m_world->m_gravity.m_quad);
  p_m_solverInfo->m_globalAccelerationPerStep.m_quad = _mm_mul_ps(
                                                         _mm_shuffle_ps(
                                                           (__m128)LODWORD(stepInfoIn->m_deltaTime.m_storage),
                                                           (__m128)LODWORD(stepInfoIn->m_deltaTime.m_storage),
                                                           0),
                                                         this->m_world->m_gravity.m_quad);
  hkpWorld::calcRequiredSolverBufferSize(this->m_world, &infoOut);
  Instance = hkMemorySystem::getInstance();
  if ( !Instance->vfptr->solverCanAllocSingleBlock(Instance, infoOut.m_maxRuntimeBlockSize) )
  {
    if ( !hkpWorld::getMemoryWatchDog(this->m_world) )
    {
      result = 1i64;
      this->m_previousStepResult = 1;
      return result;
    }
    hkpWorldMemoryUtil::checkMemoryForIntegration(this->m_world);
  }
  ++this->m_world->m_criticalOperationsLockCount;
  --this->m_world->m_criticalOperationsLockCountForPhantoms;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "StActions";
    v12 = __rdtsc();
    v13 = v11 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v10[1] = v13;
  }
  hkpSimulation::applyActions(this);
  ++this->m_world->m_criticalOperationsLockCountForPhantoms;
  m_world = this->m_world;
  v15 = m_world->m_criticalOperationsLockCount-- == 1;
  if ( v15 && !m_world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( m_world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(m_world);
    if ( m_world->m_pendingOperationQueueCount == 1 && m_world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(m_world);
  }
  ++this->m_world->m_criticalOperationsLockCount;
  v16 = this->m_world;
  v17 = ++v16->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
  v18 = &v16->m_dynamicsStepInfo.m_solverInfo;
  if ( ((v17 - 4) & 7) == 0 )
    v18->m_deactivationNumInactiveFramesSelectFlag[0] ^= 1u;
  if ( (v18->m_deactivationIntegrateCounter & 7) == 0 )
    v18->m_deactivationNumInactiveFramesSelectFlag[0] ^= 2u;
  if ( (v18->m_deactivationIntegrateCounter & 0xF) == 0 )
  {
    v18->m_deactivationNumInactiveFramesSelectFlag[1] = 1 - v18->m_deactivationNumInactiveFramesSelectFlag[1];
    v18->m_deactivationIntegrateCounter = 0;
  }
  v19 = this->m_world;
  constraintQueryIn.m_beginConstraints = hkpBeginConstraints;
  m_violatedConstraintArray = v19->m_violatedConstraintArray;
  constraintQueryIn.m_subStepDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
  constraintQueryIn.m_microStepDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_deltaTime
                                                   * v19->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps;
  constraintQueryIn.m_subStepInvDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
  constraintQueryIn.m_invNumSteps.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
  constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                           * v19->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
  constraintQueryIn.m_tau.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_tau;
  m_damping = v19->m_dynamicsStepInfo.m_solverInfo.m_damping;
  constraintQueryIn.m_violatedConstraints.m_storage = m_violatedConstraintArray;
  *(float *)&m_violatedConstraintArray = stepInfoIn->m_deltaTime.m_storage;
  constraintQueryIn.m_damping.m_storage = m_damping;
  constraintQueryIn.m_rhsFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                          * v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
  constraintQueryIn.m_virtMassFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_damping;
  v22 = v19->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp * v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
  LODWORD(constraintQueryIn.m_frameDeltaTime.m_storage) = (_DWORD)m_violatedConstraintArray;
  constraintQueryIn.m_frameInvDeltaTime.m_storage = stepInfoIn->m_invDeltaTime.m_storage;
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
    v26 = v24 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v23[1] = v26;
  }
  v27 = this->m_world;
  v28 = v27->m_activeSimulationIslands.m_size - 1;
  for ( i = v28; i >= 0; --i )
  {
    v30 = this->m_world;
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
        v35 = v33 + 2;
        *((_DWORD *)v35 - 2) = v34;
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
        v31->m_world->m_collisionInput,
        v31->m_entities.m_data,
        v31->m_entities.m_size);
      v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v38 = (_QWORD *)v37[1];
      if ( (unsigned __int64)v38 < v37[3] )
      {
        *v38 = "Et";
        v39 = __rdtsc();
        v40 = v38 + 2;
        *((_DWORD *)v40 - 2) = v39;
        v37[1] = v40;
      }
    }
    if ( v36 > 5 && (*((_BYTE *)v31 + 50) & 0xC) != 0 )
    {
      v42 = v31->m_world;
      if ( v42->m_wantDeactivation.m_bool )
        hkpWorldOperationUtil::markIslandInactive(v42, v31);
    }
    if ( this->m_world->m_islandPostIntegrateListeners.m_size )
    {
      v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v44 = (_QWORD *)v43[1];
      if ( (unsigned __int64)v44 < v43[3] )
      {
        *v44 = "StIslandPostIntegrateCb";
        v45 = __rdtsc();
        v46 = v44 + 2;
        *((_DWORD *)v46 - 2) = v45;
        v43[1] = v46;
      }
      hkpWorldCallbackUtil::fireIslandPostIntegrateCallback(this->m_world, v31, stepInfoIn);
    }
  }
  v47 = this->m_world;
  v15 = v47->m_criticalOperationsLockCount-- == 1;
  if ( v15 && !v47->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v47->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v47);
    if ( v47->m_pendingOperationQueueCount == 1 && v47->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v47);
  }
  if ( this->m_world->m_worldPostIntegrateListeners.m_size )
  {
    v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v49 = (_QWORD *)v48[1];
    if ( (unsigned __int64)v49 < v48[3] )
    {
      *v49 = "TtWorldPostIntegrateCb";
      v50 = __rdtsc();
      v51 = v49 + 2;
      *((_DWORD *)v51 - 2) = v50;
      v48[1] = v51;
    }
    hkpWorldCallbackUtil::firePostIntegrateCallback(this->m_world, stepInfoIn);
    v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v53 = (_QWORD *)v52[1];
    if ( (unsigned __int64)v53 < v52[3] )
    {
      *v53 = "Et";
      v54 = __rdtsc();
      v55 = v53 + 2;
      *((_DWORD *)v55 - 2) = v54;
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
    v60 = v57 + 2;
    *((_DWORD *)v60 - 2) = v59;
    v58[1] = v60;
  }
  return 0i64;
}

// File Line: 711
// RVA: 0xD6B650
void __fastcall hkpSimulation::applyActions(hkpSimulation *this)
{
  hkpWorld *m_world; // r15
  int v2; // ebp
  __int64 v4; // r14
  int v5; // esi
  hkpSimulationIsland *v6; // rbx
  __int64 v7; // rdi

  m_world = this->m_world;
  v2 = 0;
  if ( m_world->m_activeSimulationIslands.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = 0;
      v6 = m_world->m_activeSimulationIslands.m_data[v4];
      if ( v6->m_actions.m_size > 0 )
      {
        v7 = 0i64;
        do
        {
          ((void (__fastcall *)(hkpAction *, hkpWorldDynamicsStepInfo *))v6->m_actions.m_data[v7]->vfptr[1].__first_virtual_table_function__)(
            v6->m_actions.m_data[v7],
            &this->m_world->m_dynamicsStepInfo);
          ++v5;
          ++v7;
        }
        while ( v5 < v6->m_actions.m_size );
      }
      ++v2;
      ++v4;
    }
    while ( v2 < m_world->m_activeSimulationIslands.m_size );
  }
}

// File Line: 739
// RVA: 0xD6A050
void __fastcall hkpSimulation::collideEntitiesDiscrete(
        hkpSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpWorld *world,
        hkStepInfo *stepInfo,
        hkpSimulation::FindContacts findExtraContacts)
{
  hkpProcessCollisionInput *m_collisionInput; // r10
  hkVector4f v11; // xmm1
  hkStepInfo v12; // xmm0
  bool v13; // zf
  _QWORD **Value; // rax
  hkpProcessCollisionInput input; // [rsp+30h] [rbp-59h] BYREF

  m_collisionInput = world->m_collisionInput;
  *(_OWORD *)&input.m_dispatcher.m_storage = *(_OWORD *)&m_collisionInput->m_dispatcher.m_storage;
  *(_OWORD *)&input.m_tolerance.m_storage = *(_OWORD *)&m_collisionInput->m_tolerance.m_storage;
  *(_OWORD *)&input.m_convexListFilter.m_storage = *(_OWORD *)&m_collisionInput->m_convexListFilter.m_storage;
  input.m_aabb32Info.m_bitOffsetLow = m_collisionInput->m_aabb32Info.m_bitOffsetLow;
  input.m_aabb32Info.m_bitOffsetHigh = m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
  v11.m_quad = (__m128)m_collisionInput->m_aabb32Info.m_bitScale;
  input.m_spareAgentSector = 0i64;
  input.m_aabb32Info.m_bitScale = (hkVector4f)v11.m_quad;
  input.m_dispatcher.m_storage = m_collisionInput->m_dispatcher.m_storage;
  input.m_weldClosestPoints.m_storage = m_collisionInput->m_weldClosestPoints.m_storage;
  input.m_forceAcceptContactPoints.m_storage = m_collisionInput->m_forceAcceptContactPoints.m_storage;
  input.m_tolerance.m_storage = m_collisionInput->m_tolerance.m_storage;
  input.m_filter.m_storage = m_collisionInput->m_filter.m_storage;
  input.m_convexListFilter.m_storage = m_collisionInput->m_convexListFilter.m_storage;
  input.m_createPredictiveAgents.m_storage = m_collisionInput->m_createPredictiveAgents.m_storage;
  input.m_aabb32Info = m_collisionInput->m_aabb32Info;
  input.m_stepInfo = m_collisionInput->m_stepInfo;
  input.m_collisionQualityInfo.m_storage = m_collisionInput->m_collisionQualityInfo.m_storage;
  input.m_dynamicsInfo = m_collisionInput->m_dynamicsInfo;
  input.m_enableDeprecatedWelding.m_bool = m_collisionInput->m_enableDeprecatedWelding.m_bool;
  input.m_allowToSkipConfirmedCallbacks.m_bool = m_collisionInput->m_allowToSkipConfirmedCallbacks.m_bool;
  input.m_config = m_collisionInput->m_config;
  v12 = *stepInfo;
  ++world->m_criticalOperationsLockCount;
  input.m_stepInfo = v12;
  hkpSimulation::collideEntitiesBroadPhaseDiscrete(entities, numEntities, world);
  hkpSimulation::collideEntitiesNarrowPhaseDiscrete(this, entities, numEntities, &input, findExtraContacts);
  v13 = world->m_criticalOperationsLockCount-- == 1;
  if ( v13 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 && world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(world);
  }
  if ( input.m_spareAgentSector )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*Value[11] + 16i64))(
      Value[11],
      input.m_spareAgentSector,
      512i64);
  }
}

// File Line: 764
// RVA: 0xD6A870
void __fastcall hkpSimulation::collideEntitiesNarrowPhaseDiscrete(
        hkpSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpProcessCollisionInput *input,
        hkpSimulation::FindContacts findExtraContacts)
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
void __fastcall hkpSimulation::processAgentCollideDiscrete(
        hkpSimulation *this,
        hkpAgentNnEntry *entry,
        hkpProcessCollisionInput *processInput,
        hkpProcessCollisionOutput *processOutput)
{
  hkpProcessCdPoint *m_contactPoints; // rbp
  hkpCollisionDispatcher *m_storage; // rcx

  processOutput->m_toi.m_time.m_storage = 3.40282e38;
  processOutput->m_potentialContacts.m_storage = 0i64;
  m_contactPoints = processOutput->m_contactPoints;
  processOutput->m_firstFreeContactPoint.m_storage = processOutput->m_contactPoints;
  m_storage = processInput->m_dispatcher.m_storage;
  processInput->m_collisionQualityInfo.m_storage = &processInput->m_dispatcher.m_storage->m_collisionQualityInfo[1];
  processInput->m_createPredictiveAgents.m_storage = m_storage->m_collisionQualityInfo[(__int64)entry->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
  hkAgentNnMachine_ProcessAgent(entry, processInput, processOutput, entry->m_contactMgr);
  if ( hkOutOfMemoryState != MEMORY_STATE_OUT_OF_MEMORY
    && processOutput->m_firstFreeContactPoint.m_storage != m_contactPoints )
  {
    ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))entry->m_contactMgr->vfptr[3].__vecDelDtor)(
      entry->m_contactMgr,
      entry->m_collidable[0],
      entry->m_collidable[1],
      processInput,
      processOutput);
  }
}

// File Line: 795
// RVA: 0xD6C1F0
void __fastcall hkpSimulation::processAgentResetCollisionInformation(
        hkpSimulation *this,
        hkpAgentNnEntry *entry,
        hkpProcessCollisionInput *processInput,
        hkpProcessCollisionOutput *processOutput)
{
  hkAgentNnMachine_InvalidateTimInAgent(entry, processInput);
}

// File Line: 816
// RVA: 0xD6A8A0
void __fastcall hkpSimulation::resetCollisionInformationForEntities(
        hkpSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpWorld *world,
        hkpSimulation::ResetCollisionInformation resetInfo)
{
  if ( (resetInfo & 2) != 0 )
    hkpSimulation::processAgentsOfEntities(
      this,
      entities,
      numEntities,
      world->m_collisionInput,
      hkpSimulation::processAgentResetCollisionInformation,
      FIND_CONTACTS_DEFAULT);
  if ( (resetInfo & 4) != 0 )
    hkpEntityAabbUtil::entityBatchInvalidateAabb(entities, numEntities);
}

// File Line: 836
// RVA: 0xD6C440
void __fastcall setRotationAroundCentreOfMass(hkpRigidBody *rb, hkQuaternionf *newRotation)
{
  hkVector4f v3; // xmm1

  hkRotationf::set(&rb->m_motion.m_motionState.m_transform.m_rotation, newRotation);
  v3.m_quad = (__m128)rb->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  rb->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                  rb->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(v3.m_quad, v3.m_quad, 85),
                                                                        rb->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(v3.m_quad, v3.m_quad, 0),
                                                                        rb->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                                    _mm_mul_ps(
                                                                      _mm_shuffle_ps(v3.m_quad, v3.m_quad, 170),
                                                                      rb->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
}

// File Line: 845
// RVA: 0xD6B770
void __fastcall hkpSimulation::processAgentsOfEntities(
        hkpSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpProcessCollisionInput *processInput,
        void (__fastcall *processingFunction)(hkpSimulation *this, hkpAgentNnEntry *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *),
        hkpSimulation::FindContacts findExtraContacts)
{
  __int64 v7; // rbx
  hkpSimulation *v8; // rdi
  hkpEntity **v9; // r9
  hkpLinkedCollidable::CollisionEntry *v10; // rdx
  IAmdDxExt *v11; // rax
  int m_capacityAndFlags; // r8d
  hkpEntity *v13; // r15
  int v14; // r12d
  __int64 v15; // rbx
  hkpLinkedCollidable::CollisionEntry *m_data; // r14
  int Key; // eax
  hkpAgentNnEntry *m_agentEntry; // rsi
  hkpLinkedCollidable *v19; // rax
  __int64 m_ownerOffset; // rcx
  __int64 v21; // rcx
  hkpAgentNnEntry *v22; // rax
  __m128 v23; // xmm14
  __m128 *p_m_quad; // rdi
  __int128 m_col1; // xmm1
  __int128 m_col2; // xmm0
  __int128 m_translation; // xmm1
  __m128 v28; // xmm15
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm13
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm12
  hkpCollisionQualityInfo *m_storage; // rax
  float v42; // xmm11_4
  float m_create4dContact; // xmm9_4
  float m_createContact; // xmm10_4
  __m128 v45; // xmm12
  __m128 v46; // xmm7
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm5
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
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+20h] [rbp-E0h] BYREF
  AMD_HD3D v86; // [rsp+30h] [rbp-D0h] BYREF
  hkVector4f axis; // [rsp+50h] [rbp-B0h] BYREF
  hkQuaternionf v88; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v89; // [rsp+70h] [rbp-90h]
  hkSimdFloat32 angle; // [rsp+80h] [rbp-80h] BYREF
  hkQuaternionf v91; // [rsp+90h] [rbp-70h] BYREF
  hkQuaternionf qi; // [rsp+A0h] [rbp-60h] BYREF
  __m128 m_quad; // [rsp+B0h] [rbp-50h]
  hkQuaternionf v94; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f v95; // [rsp+D0h] [rbp-30h] BYREF
  __int128 v96[4]; // [rsp+E0h] [rbp-20h] BYREF
  __m128 *v97; // [rsp+120h] [rbp+20h] BYREF
  __int64 v98; // [rsp+128h] [rbp+28h]
  __m128 v99; // [rsp+130h] [rbp+30h] BYREF
  __m128 v100; // [rsp+140h] [rbp+40h]
  float v101; // [rsp+3150h] [rbp+3050h]
  __int64 v102; // [rsp+3170h] [rbp+3070h]

  v7 = numEntities;
  v8 = this;
  *(_QWORD *)&v86.mEnableStereo = 0i64;
  v86.mWidth = 0;
  v86.mHeight = -1;
  v9 = entities;
  if ( numEntities )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v86,
      &hkContainerHeapAllocator::s_alloc,
      numEntities);
    v9 = entities;
  }
  v10 = 0i64;
  v11 = 0i64;
  m_capacityAndFlags = 0x80000000;
  v102 = 0i64;
  v98 = 0i64;
  v101 = FLOAT_3_40282e38;
  entries.m_data = 0i64;
  entries.m_size = 0;
  v86.mExtension = 0i64;
  entries.m_capacityAndFlags = 0x80000000;
  v89 = v7;
  if ( (int)v7 > 0 )
  {
    while ( 1 )
    {
      v13 = v9[(_QWORD)v11];
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v86,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)&v13->m_collidable,
        0i64);
      hkpLinkedCollidable::getCollisionEntriesSorted(&v13->m_collidable, &entries);
      v14 = 0;
      if ( entries.m_size > 0 )
        break;
LABEL_20:
      v9 = entities;
      v11 = (IAmdDxExt *)((char *)&v86.mExtension->vfptr + 1);
      v86.mExtension = v11;
      if ( (__int64)v11 >= v89 )
        goto LABEL_21;
    }
    v15 = 0i64;
    while ( 1 )
    {
      m_data = entries.m_data;
      Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v86,
                            (unsigned __int64)entries.m_data[v15].m_partner);
      if ( Key > (int)v86.mHeight )
      {
        m_agentEntry = m_data[v15].m_agentEntry;
        v19 = m_agentEntry->m_collidable[0];
        m_ownerOffset = v19->m_ownerOffset;
        if ( *((_BYTE *)&v19[2].m_boundingVolumeData.m_childShapeKeys + m_ownerOffset) == 5 )
          v21 = *(_QWORD *)(&m_agentEntry->m_collidable[1][2].m_broadPhaseHandle.m_type
                          + m_agentEntry->m_collidable[1]->m_ownerOffset);
        else
          v21 = *(_QWORD *)(&v19[2].m_broadPhaseHandle.m_type + m_ownerOffset);
        v98 = v21;
        hkAgentNnMachine_InvalidateTimInAgent(m_agentEntry, processInput);
        processingFunction(v8, m_agentEntry, processInput, (hkpProcessCollisionOutput *)&v97);
        if ( findExtraContacts == FIND_CONTACTS_EXTRA && v97 != &v99 )
        {
          v22 = m_data[v15].m_agentEntry;
          v23 = v100;
          p_m_quad = &v13->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
          m_col1 = (__int128)v13->m_motion.m_motionState.m_transform.m_rotation.m_col1;
          m_quad = v13->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          v96[0] = (__int128)v13->m_motion.m_motionState.m_transform.m_rotation.m_col0;
          m_col2 = (__int128)v13->m_motion.m_motionState.m_transform.m_rotation.m_col2;
          v96[1] = m_col1;
          m_translation = (__int128)v13->m_motion.m_motionState.m_transform.m_translation;
          v96[2] = m_col2;
          v96[3] = m_translation;
          if ( v22->m_collidable[0] != &v13->m_collidable )
            v23 = _mm_xor_ps(v100, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
          v28 = _mm_shuffle_ps(v23, v23, 201);
          v29 = _mm_sub_ps(v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad, v99);
          v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v23), _mm_mul_ps(v28, v29));
          axis.m_quad = _mm_shuffle_ps(v30, v30, 201);
          v31 = _mm_mul_ps(axis.m_quad, axis.m_quad);
          v32 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                  _mm_shuffle_ps(v31, v31, 170));
          v33 = _mm_mul_ps(v29, v23);
          v34 = _mm_mul_ps(v29, v29);
          v35 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                  _mm_shuffle_ps(v33, v33, 170));
          v36 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                  _mm_shuffle_ps(v34, v34, 170));
          v37 = _mm_rsqrt_ps(v36);
          v38 = _mm_andnot_ps(
                  _mm_cmple_ps(v36, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                      _mm_mul_ps(*(__m128 *)_xmm, v37)),
                    v36));
          v39 = _mm_rcp_ps(v38);
          v40 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39), v35);
          if ( v32.m128_f32[0] <= _mm_shuffle_ps((__m128)0x2EDBE6FEu, (__m128)0x2EDBE6FEu, 0).m128_f32[0]
            || (HIDWORD(v86.mStereo) = 1065351538,
                v40.m128_f32[0] >= _mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0).m128_f32[0]) )
          {
            v8 = this;
          }
          else
          {
            m_storage = processInput->m_collisionQualityInfo.m_storage;
            v42 = processInput->m_tolerance.m_storage;
            processInput->m_tolerance.m_storage = v42 * 20.0;
            m_create4dContact = m_storage->m_create4dContact;
            m_createContact = m_storage->m_createContact;
            m_storage->m_create4dContact = v42 * 20.0;
            processInput->m_collisionQualityInfo.m_storage->m_createContact = v42 * 20.0;
            *(float *)&v86.mStereo = (float)(v42 * 20.0) * 0.050000001;
            v45 = _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      v40,
                      _mm_max_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39),
                          _mm_sub_ps(v35, _mm_shuffle_ps((__m128)LODWORD(v86.mStereo), (__m128)LODWORD(v86.mStereo), 0))),
                        aabbOut.m_quad)),
                    _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
            v46 = _mm_andnot_ps(*(__m128 *)_xmm, v45);
            v47 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v46), *(__m128 *)_xmm);
            v48 = _mm_cmplt_ps(*(__m128 *)_xmm, v46);
            v49 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v47), v48), _mm_andnot_ps(v48, v46));
            v50 = _mm_or_ps(_mm_andnot_ps(v48, _mm_mul_ps(v46, v46)), _mm_and_ps(v48, v47));
            v51 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v50, *(__m128 *)coeff4), *(__m128 *)coeff3), v50),
                                  *(__m128 *)coeff2),
                                v50),
                              *(__m128 *)coeff1),
                            v50),
                          *(__m128 *)coeff0),
                        v50),
                      v49),
                    v49);
            v52 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v51, v51)), v48);
            v53 = _mm_andnot_ps(v48, v51);
            v54 = _mm_cmplt_ps(v46, *(__m128 *)_xmm);
            v55 = _mm_xor_ps(
                    _mm_or_ps(_mm_andnot_ps(v54, _mm_or_ps(v52, v53)), _mm_and_ps(v54, v46)),
                    _mm_and_ps(v45, *(__m128 *)_xmm));
            angle.m_real = _mm_sub_ps(_mm_shuffle_ps(v55, v55, 0), _mm_shuffle_ps(v55, v55, 85));
            v56 = _mm_rsqrt_ps(v32);
            axis.m_quad = _mm_mul_ps(
                            axis.m_quad,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v32), v56)),
                              _mm_mul_ps(v56, *(__m128 *)_xmm)));
            hkQuaternionf::setAxisAngle(&v94, &axis, &angle);
            v57 = v13->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
            v58 = _mm_shuffle_ps(v94.m_vec.m_quad, v94.m_vec.m_quad, 255);
            v59 = _mm_shuffle_ps(v57, v57, 255);
            v60 = _mm_mul_ps(v94.m_vec.m_quad, v57);
            v61 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v94.m_vec.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v94.m_vec.m_quad, v94.m_vec.m_quad, 201), v57));
            v62 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v61, v61, 201), _mm_mul_ps(v58, v57)),
                    _mm_mul_ps(v59, v94.m_vec.m_quad));
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
                                                                                   _mm_shuffle_ps(v63, v63, 0),
                                                                                   *p_m_quad)),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v63, v63, 170),
                                                                                 v13->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
            hkAgentNnMachine_InvalidateTimInAgent(m_agentEntry, processInput);
            processingFunction(this, m_agentEntry, processInput, (hkpProcessCollisionOutput *)&v97);
            v64 = _mm_sub_ps(
                    _mm_mul_ps(v28, axis.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(axis.m_quad, axis.m_quad, 201), v23));
            v65 = _mm_shuffle_ps(v64, v64, 201);
            v66 = _mm_mul_ps(v65, v65);
            v67 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                    _mm_shuffle_ps(v66, v66, 170));
            v68 = _mm_rsqrt_ps(v67);
            v95.m_quad = _mm_mul_ps(
                           v65,
                           _mm_andnot_ps(
                             _mm_cmple_ps(v67, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                               _mm_mul_ps(v68, *(__m128 *)_xmm))));
            hkQuaternionf::setAxisAngle(&v91, &v95, &angle);
            v69 = m_quad;
            v70 = _mm_shuffle_ps(v91.m_vec.m_quad, v91.m_vec.m_quad, 255);
            v71 = _mm_shuffle_ps(m_quad, m_quad, 255);
            v72 = _mm_shuffle_ps(m_quad, m_quad, 201);
            v73 = _mm_sub_ps(
                    _mm_mul_ps(v91.m_vec.m_quad, v72),
                    _mm_mul_ps(_mm_shuffle_ps(v91.m_vec.m_quad, v91.m_vec.m_quad, 201), m_quad));
            v74 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v73, v73, 201), _mm_mul_ps(v70, m_quad)),
                    _mm_mul_ps(v71, v91.m_vec.m_quad));
            v75 = _mm_mul_ps(m_quad, v91.m_vec.m_quad);
            v88.m_vec.m_quad = _mm_shuffle_ps(
                                 v74,
                                 _mm_unpackhi_ps(
                                   v74,
                                   _mm_sub_ps(
                                     _mm_mul_ps(v71, v70),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                                       _mm_shuffle_ps(v75, v75, 170)))),
                                 196);
            hkRotationf::set(&v13->m_motion.m_motionState.m_transform.m_rotation, &v88);
            v76 = v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
            v13->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                             v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                             _mm_add_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v76, v76, 85),
                                                                                   v13->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v76, v76, 0),
                                                                                   *p_m_quad)),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v76, v76, 170),
                                                                                 v13->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
            hkAgentNnMachine_InvalidateTimInAgent(m_agentEntry, processInput);
            processingFunction(this, m_agentEntry, processInput, (hkpProcessCollisionOutput *)&v97);
            v77 = _mm_mul_ps(_mm_shuffle_ps(v91.m_vec.m_quad, v91.m_vec.m_quad, 201), v69);
            v78 = _mm_mul_ps(_mm_shuffle_ps(v91.m_vec.m_quad, v91.m_vec.m_quad, 255), v69);
            v79 = _mm_mul_ps(v69, v91.m_vec.m_quad);
            v80 = _mm_sub_ps(v77, _mm_mul_ps(v91.m_vec.m_quad, v72));
            v81 = _mm_sub_ps(_mm_add_ps(v78, _mm_shuffle_ps(v80, v80, 201)), _mm_mul_ps(v91.m_vec.m_quad, v71));
            v82 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 78), v79);
            v88.m_vec.m_quad = _mm_shuffle_ps(
                                 v81,
                                 _mm_unpackhi_ps(v81, _mm_add_ps(_mm_shuffle_ps(v82, v82, 177), v82)),
                                 196);
            hkRotationf::set(&v13->m_motion.m_motionState.m_transform.m_rotation, &v88);
            v83 = v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
            v13->m_motion.m_motionState.m_transform.m_translation.m_quad = _mm_sub_ps(
                                                                             v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad,
                                                                             _mm_add_ps(
                                                                               _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v83, v83, 85),
                                                                                   v13->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                                                 _mm_mul_ps(
                                                                                   _mm_shuffle_ps(v83, v83, 0),
                                                                                   *p_m_quad)),
                                                                               _mm_mul_ps(
                                                                                 _mm_shuffle_ps(v83, v83, 170),
                                                                                 v13->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)));
            hkAgentNnMachine_InvalidateTimInAgent(m_agentEntry, processInput);
            v8 = this;
            processingFunction(this, m_agentEntry, processInput, (hkpProcessCollisionOutput *)&v97);
            v84 = processInput->m_collisionQualityInfo.m_storage;
            processInput->m_tolerance.m_storage = v42;
            v84->m_create4dContact = m_create4dContact;
            processInput->m_collisionQualityInfo.m_storage->m_createContact = m_createContact;
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v13->m_motion.vfptr[8].__first_virtual_table_function__)(
              &v13->m_motion,
              v96);
            hkAgentNnMachine_InvalidateTimInAgent(m_agentEntry, processInput);
            processingFunction(this, m_agentEntry, processInput, (hkpProcessCollisionOutput *)&v97);
          }
        }
        if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
          break;
      }
      ++v14;
      ++v15;
      if ( v14 >= entries.m_size )
        goto LABEL_20;
    }
LABEL_21:
    m_capacityAndFlags = entries.m_capacityAndFlags;
    v10 = entries.m_data;
  }
  entries.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkpLinkedCollidable::CollisionEntry *, _QWORD, hkpEntity **))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v10,
      (unsigned int)(16 * m_capacityAndFlags),
      v9);
  entries.m_data = 0i64;
  entries.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v86,
    &hkContainerHeapAllocator::s_alloc);
  _(&v86);
}

// File Line: 1017
// RVA: 0xD6A900
void __fastcall hkpSimulation::reintegrateAndRecollideEntities(
        hkpSimulation *this,
        hkpMotion **entities,
        int numEntities,
        hkpWorld *world,
        char reintegrateRecollideMode)
{
  hkpSimulation *v5; // rbx
  __int64 v6; // r15
  float CurrentPsiTime; // xmm6_4
  float CurrentTime; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  hkpProcessCollisionInput *m_collisionInput; // rax
  __int64 v14; // rsi
  hkpEntity *v15; // rbx
  float v16; // xmm0_4
  bool v17; // zf
  hkStepInfo info; // [rsp+30h] [rbp-48h] BYREF

  ++world->m_criticalOperationsLockCount;
  v5 = this;
  v6 = numEntities;
  CurrentPsiTime = hkpWorld::getCurrentPsiTime(world);
  CurrentTime = hkpWorld::getCurrentTime(world);
  info.m_endTime.m_storage = CurrentPsiTime;
  v11 = CurrentPsiTime - CurrentTime;
  info.m_startTime.m_storage = CurrentTime;
  v12 = 0.0;
  info.m_deltaTime.m_storage = v11;
  if ( v11 != 0.0 )
    v12 = 1.0 / v11;
  m_collisionInput = world->m_collisionInput;
  info.m_invDeltaTime.m_storage = v12;
  m_collisionInput->m_stepInfo = info;
  if ( (reintegrateRecollideMode & 1) != 0 )
  {
    v14 = 0i64;
    if ( (int)v6 > 0 )
    {
      do
      {
        v15 = (hkpEntity *)entities[v14];
        if ( v15->m_motion.m_type.m_storage != 5 )
        {
          v16 = hkpWorld::getCurrentTime(world);
          hkSweptTransformUtil::backStepMotionState(v16, &v15->m_motion.m_motionState);
        }
        ++v14;
      }
      while ( v14 < v6 );
      v5 = this;
    }
    hkRigidMotionUtilStep(&info, entities, v6, 336);
    hkpEntityAabbUtil::entityBatchRecalcAabb(world->m_collisionInput, (hkpEntity *const *)entities, v6);
  }
  if ( (reintegrateRecollideMode & 2) != 0 )
    hkpSimulation::collideEntitiesBroadPhaseDiscrete((hkpEntity **)entities, v6, world);
  if ( (reintegrateRecollideMode & 4) != 0 )
  {
    hkpSimulation::collideEntitiesNarrowPhaseDiscrete(
      v5,
      (hkpEntity **)entities,
      v6,
      world->m_collisionInput,
      FIND_CONTACTS_DEFAULT);
  }
  else if ( (reintegrateRecollideMode & 1) != 0 )
  {
    ((void (__fastcall *)(hkpSimulation *, hkpMotion **, _QWORD, hkpWorld *, int))v5->vfptr[6].__vecDelDtor)(
      v5,
      entities,
      (unsigned int)v6,
      world,
      2);
  }
  v17 = world->m_criticalOperationsLockCount-- == 1;
  if ( v17 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 )
    {
      if ( world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 1074
// RVA: 0xD6C210
void __fastcall hkLs_doSimpleCollisionResponse(
        hkpWorld *world,
        hkpToiEvent *event,
        float rotateNormal,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *toBeActivated)
{
  hkpEntity *v4; // rsi
  hkpEntity *v5; // rdi
  unsigned __int8 m_value; // cl
  unsigned __int16 EncodedFloat; // ax
  unsigned __int8 v11; // cl
  unsigned __int16 v12; // ax
  hkpDynamicsContactMgr *m_contactMgr; // rax
  unsigned __int8 v14; // al
  __int64 m_size; // rcx
  hkpEntity **m_data; // rax
  bool v17; // cc
  hkpSimpleCollisionResponse::SolveSingleOutput output; // [rsp+18h] [rbp-29h] BYREF
  hkpSimpleConstraintUtilCollideParams params; // [rsp+28h] [rbp-19h] BYREF
  hkpContactImpulseLimitBreachedListenerInfo breachedContacts; // [rsp+48h] [rbp+7h] BYREF
  int v21; // [rsp+B8h] [rbp+77h]

  v4 = event->m_entities[0];
  v5 = event->m_entities[1];
  m_value = event->m_properties.m_friction.m_value;
  params.m_externalSeperatingVelocity = event->m_seperatingVelocity;
  params.m_extraSeparatingVelocity = FLOAT_0_1;
  params.m_extraSlope = rotateNormal;
  EncodedFloat = hkUFloat8::getEncodedFloat(m_value);
  v21 = (EncodedFloat + 243712) << 12;
  if ( EncodedFloat )
    LODWORD(params.m_friction) = v21;
  else
    params.m_friction = 0.0;
  v11 = event->m_properties.m_maxImpulse.m_value;
  params.m_restitution = (float)(unsigned __int8)event->m_properties.m_restitution * 0.0078125;
  if ( v11 )
  {
    v12 = hkUFloat8::getEncodedFloat(v11);
    v21 = (v12 + 243712) << 12;
    if ( v12 )
      LODWORD(params.m_maxImpulse) = v21;
    else
      params.m_maxImpulse = 0.0;
  }
  else
  {
    params.m_maxImpulse = FLOAT_3_40282e38;
  }
  hkpSimpleCollisionResponse::solveSingleContact(
    &event->m_contactPoint,
    event->m_time,
    &params,
    &v4->m_motion,
    &v5->m_motion,
    event->m_contactMgr,
    &output);
  if ( params.m_contactImpulseLimitBreached.m_bool )
  {
    m_contactMgr = event->m_contactMgr;
    *(_DWORD *)&breachedContacts.m_data.m_solver.m_type = 65538;
    breachedContacts.m_data.m_solver.m_constraintInstance = (hkpConstraintInstance *)&m_contactMgr[3].m_world;
    breachedContacts.m_data.m_single.m_contactPoint = &event->m_contactPoint;
    breachedContacts.m_data.m_solver.m_solverResult = &event->m_properties;
    hkpWorldCallbackUtil::fireContactImpulseLimitBreached(world, &breachedContacts, 1);
    return;
  }
  if ( output.m_velocityKeyframedA >= 0.0 )
  {
    if ( output.m_velocityKeyframedB < 0.0 )
    {
      m_size = toBeActivated->m_size;
      m_data = toBeActivated->m_data;
      if ( (unsigned __int8)(v5->m_motion.m_type.m_storage - 4) <= 1u )
      {
        m_data[m_size] = v4;
        goto LABEL_18;
      }
      goto LABEL_17;
    }
    if ( (unsigned __int8)(v4->m_motion.m_type.m_storage - 4) > 1u
      && ((unsigned __int8)(v5->m_motion.m_type.m_storage - 4) <= 1u
       || output.m_velocityKeyframedA <= output.m_velocityKeyframedB) )
    {
      toBeActivated->m_data[toBeActivated->m_size] = v4;
      goto LABEL_18;
    }
    goto LABEL_16;
  }
  v14 = v4->m_motion.m_type.m_storage - 4;
  if ( output.m_velocityKeyframedB >= 0.0 )
  {
    m_size = toBeActivated->m_size;
    v17 = v14 <= 1u;
    m_data = toBeActivated->m_data;
    if ( !v17 )
    {
      m_data[m_size] = v4;
      goto LABEL_18;
    }
LABEL_17:
    m_data[m_size] = v5;
LABEL_18:
    ++toBeActivated->m_size;
    return;
  }
  if ( v14 > 1u )
    toBeActivated->m_data[toBeActivated->m_size++] = v4;
  if ( (unsigned __int8)(v5->m_motion.m_type.m_storage - 4) > 1u )
  {
LABEL_16:
    m_size = toBeActivated->m_size;
    m_data = toBeActivated->m_data;
    goto LABEL_17;
  }
}

