// File Line: 32
// RVA: 0xD8A8A0
void __fastcall hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr(hkpDefaultWorldMaintenanceMgr *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_minAllowedTimeValue = 33.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDefaultWorldMaintenanceMgr::`vftable;
  this->m_maxAllowedTimeValue = 63.0;
}

// File Line: 38
// RVA: 0xD8A8D0
void __fastcall hkpDefaultWorldMaintenanceMgr::init(hkpDefaultWorldMaintenanceMgr *this, hkpWorld *world)
{
  hkpSimulation *m_simulation; // r8

  m_simulation = world->m_simulation;
  m_simulation->m_currentTime = this->m_minAllowedTimeValue;
  m_simulation->m_currentPsiTime = this->m_minAllowedTimeValue;
}

// File Line: 46
// RVA: 0xD8AAB0
void __fastcall hkpDefaultWorldMaintenanceMgr::resetWorldTime(
        hkpDefaultWorldMaintenanceMgr *this,
        hkpWorld *world,
        hkStepInfo *stepInfo)
{
  float v5; // xmm2_4
  float m_storage; // xmm6_4
  float v7; // xmm0_4
  hkpSimulation *m_simulation; // rcx
  float v9; // xmm6_4
  float m_simulateUntilTime; // xmm0_4
  int v11; // esi
  __int64 v12; // rdi
  int v13; // r9d
  hkpSimulationIsland *v14; // rcx
  __int64 v15; // r8
  hkpEntity *v16; // rdx

  v5 = stepInfo->m_endTime.m_storage - stepInfo->m_startTime.m_storage;
  world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage = this->m_minAllowedTimeValue;
  m_storage = world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
  v7 = v5 + this->m_minAllowedTimeValue;
  world->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage = v5;
  world->m_dynamicsStepInfo.m_stepInfo.m_endTime.m_storage = v7;
  world->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage = 1.0 / v5;
  m_simulation = world->m_simulation;
  v9 = m_storage - stepInfo->m_startTime.m_storage;
  m_simulation->m_currentTime = v9 + m_simulation->m_currentTime;
  m_simulation->m_currentPsiTime = world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
  m_simulateUntilTime = m_simulation->m_simulateUntilTime;
  if ( m_simulateUntilTime != -1.0 )
    m_simulation->m_simulateUntilTime = m_simulateUntilTime + v9;
  v11 = 0;
  if ( world->m_activeSimulationIslands.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = 0;
      v14 = world->m_activeSimulationIslands.m_data[v12];
      if ( v14->m_entities.m_size > 0 )
      {
        v15 = 0i64;
        do
        {
          ++v13;
          v16 = v14->m_entities.m_data[v15++];
          v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3] = v9
                                                                                          + v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3];
        }
        while ( v13 < v14->m_entities.m_size );
      }
      hkpWorldAgentUtil::warpTime(
        v14,
        stepInfo->m_endTime.m_storage,
        world->m_dynamicsStepInfo.m_stepInfo.m_endTime.m_storage,
        world->m_collisionInput);
      ++v11;
      ++v12;
    }
    while ( v11 < world->m_activeSimulationIslands.m_size );
  }
  ((void (__fastcall *)(hkpSimulation *))world->m_simulation->vfptr[9].__vecDelDtor)(world->m_simulation);
  *stepInfo = world->m_dynamicsStepInfo.m_stepInfo;
  world->m_collisionInput->m_stepInfo = world->m_dynamicsStepInfo.m_stepInfo;
}

// File Line: 140
// RVA: 0xD8A8F0
void __fastcall hkpDefaultWorldMaintenanceMgr::performMaintenance(
        hkpDefaultWorldMaintenanceMgr *this,
        hkpWorld *world,
        hkStepInfo *stepInfo)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtMaintenance";
    *(_QWORD *)(v7 + 16) = "StSplit";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  hkpWorldOperationUtil::splitSimulationIslands(world);
  if ( this->m_maxAllowedTimeValue <= stepInfo->m_startTime.m_storage )
  {
    v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = (_QWORD *)v10[1];
    if ( (unsigned __int64)v11 < v10[3] )
    {
      *v11 = "StResetTime";
      v12 = __rdtsc();
      v13 = v11 + 2;
      *((_DWORD *)v13 - 2) = v12;
      v10[1] = v13;
    }
    hkpDefaultWorldMaintenanceMgr::resetWorldTime(this, world, stepInfo);
  }
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "lt";
    v16 = __rdtsc();
    v17 = v15 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v14[1] = v17;
  }
}

// File Line: 163
// RVA: 0xD8A9F0
void __fastcall hkpDefaultWorldMaintenanceMgr::performMaintenanceNoSplit(
        hkpDefaultWorldMaintenanceMgr *this,
        hkpWorld *world,
        hkStepInfo *stepInfo)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtMaintenance";
    *(_QWORD *)(v7 + 16) = "StResetTime";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  if ( this->m_maxAllowedTimeValue <= stepInfo->m_startTime.m_storage )
    hkpDefaultWorldMaintenanceMgr::resetWorldTime(this, world, stepInfo);
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "lt";
    v12 = __rdtsc();
    v13 = v11 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v10[1] = v13;
  }
}

