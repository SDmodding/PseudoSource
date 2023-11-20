// File Line: 32
// RVA: 0xD8A8A0
void __fastcall hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr(hkpDefaultWorldMaintenanceMgr *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_minAllowedTimeValue = 33.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpDefaultWorldMaintenanceMgr::`vftable';
  this->m_maxAllowedTimeValue = 63.0;
}

// File Line: 38
// RVA: 0xD8A8D0
void __fastcall hkpDefaultWorldMaintenanceMgr::init(hkpDefaultWorldMaintenanceMgr *this, hkpWorld *world)
{
  hkpSimulation *v2; // r8

  v2 = world->m_simulation;
  v2->m_currentTime = this->m_minAllowedTimeValue;
  v2->m_currentPsiTime = this->m_minAllowedTimeValue;
}

// File Line: 46
// RVA: 0xD8AAB0
void __fastcall hkpDefaultWorldMaintenanceMgr::resetWorldTime(hkpDefaultWorldMaintenanceMgr *this, hkpWorld *world, hkStepInfo *stepInfo)
{
  hkStepInfo *v3; // rbp
  hkpWorld *v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm0_4
  hkpSimulation *v8; // rcx
  float v9; // xmm6_4
  float v10; // xmm0_4
  int v11; // esi
  __int64 v12; // rdi
  int v13; // er9
  hkpSimulationIsland *v14; // rcx
  __int64 v15; // r8
  hkpEntity *v16; // rdx

  v3 = stepInfo;
  v4 = world;
  v5 = stepInfo->m_endTime.m_storage - stepInfo->m_startTime.m_storage;
  world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage = this->m_minAllowedTimeValue;
  v6 = world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
  v7 = v5 + this->m_minAllowedTimeValue;
  world->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage = v5;
  world->m_dynamicsStepInfo.m_stepInfo.m_endTime.m_storage = v7;
  world->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage = 1.0 / v5;
  v8 = world->m_simulation;
  v9 = v6 - stepInfo->m_startTime.m_storage;
  v8->m_currentTime = v9 + v8->m_currentTime;
  v8->m_currentPsiTime = world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
  v10 = v8->m_simulateUntilTime;
  if ( v10 != -1.0 )
    v8->m_simulateUntilTime = v10 + v9;
  v11 = 0;
  if ( world->m_activeSimulationIslands.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = 0;
      v14 = v4->m_activeSimulationIslands.m_data[v12];
      if ( v14->m_entities.m_size > 0 )
      {
        v15 = 0i64;
        do
        {
          ++v13;
          v16 = v14->m_entities.m_data[v15];
          ++v15;
          v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3] = v9
                                                                                          + v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3];
        }
        while ( v13 < v14->m_entities.m_size );
      }
      hkpWorldAgentUtil::warpTime(
        v14,
        v3->m_endTime.m_storage,
        v4->m_dynamicsStepInfo.m_stepInfo.m_endTime.m_storage,
        (hkpCollisionInput *)&v4->m_collisionInput->m_dispatcher);
      ++v11;
      ++v12;
    }
    while ( v11 < v4->m_activeSimulationIslands.m_size );
  }
  ((void (*)(void))v4->m_simulation->vfptr[9].__vecDelDtor)();
  _mm_store_si128((__m128i *)v3, (__m128i)v4->m_dynamicsStepInfo.m_stepInfo);
  _mm_store_si128((__m128i *)&v4->m_collisionInput->m_stepInfo, (__m128i)v4->m_dynamicsStepInfo.m_stepInfo);
}

// File Line: 140
// RVA: 0xD8A8F0
void __fastcall hkpDefaultWorldMaintenanceMgr::performMaintenance(hkpDefaultWorldMaintenanceMgr *this, hkpWorld *world, hkStepInfo *stepInfo)
{
  hkpDefaultWorldMaintenanceMgr *v3; // rsi
  hkStepInfo *v4; // rbx
  hkpWorld *v5; // rdi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx

  v3 = this;
  v4 = stepInfo;
  v5 = world;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtMaintenance";
    *(_QWORD *)(v7 + 16) = "StSplit";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  hkpWorldOperationUtil::splitSimulationIslands(v5);
  if ( v3->m_maxAllowedTimeValue <= v4->m_startTime.m_storage )
  {
    v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v11 = (_QWORD *)v10[1];
    if ( (unsigned __int64)v11 < v10[3] )
    {
      *v11 = "StResetTime";
      v12 = __rdtsc();
      v13 = (signed __int64)(v11 + 2);
      *(_DWORD *)(v13 - 8) = v12;
      v10[1] = v13;
    }
    hkpDefaultWorldMaintenanceMgr::resetWorldTime(v3, v5, v4);
  }
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "lt";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
}

// File Line: 163
// RVA: 0xD8A9F0
void __fastcall hkpDefaultWorldMaintenanceMgr::performMaintenanceNoSplit(hkpDefaultWorldMaintenanceMgr *this, hkpWorld *world, hkStepInfo *stepInfo)
{
  hkpDefaultWorldMaintenanceMgr *v3; // rdi
  hkStepInfo *v4; // rbx
  hkpWorld *v5; // rsi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v3 = this;
  v4 = stepInfo;
  v5 = world;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtMaintenance";
    *(_QWORD *)(v7 + 16) = "StResetTime";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  if ( v3->m_maxAllowedTimeValue <= v4->m_startTime.m_storage )
    hkpDefaultWorldMaintenanceMgr::resetWorldTime(v3, v5, v4);
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "lt";
    v12 = __rdtsc();
    v13 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v10[1] = v13;
  }
}

