// File Line: 18
// RVA: 0x3F1D40
void __fastcall UFG::CopSystem::UpdateTelemetryStatsNewLevel(UFG::CopSystem *this, UFG::HeatLevelEnum oldHeatLevel, UFG::HeatLevelEnum newHeatLevel)
{
  UFG::HeatLevelEnum v3; // esi
  int v4; // ebx
  UFG::CopSystem *v5; // rdi
  UFG::OSuiteDBLogger *v6; // rsi
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  float v10; // xmm0_4
  char dest; // [rsp+30h] [rbp-98h]

  v3 = newHeatLevel;
  v4 = oldHeatLevel;
  v5 = this;
  if ( !(_S9_10 & 1) )
  {
    _S9_10 |= 1u;
    UFG::SimpleTimer::SimpleTimer(&copChaseDurationTimer);
    atexit(UFG::CopSystem::UpdateTelemetryStatsNewLevel_::_2_::_dynamic_atexit_destructor_for__copChaseDurationTimer__);
  }
  if ( v4 )
  {
    if ( v3 == HEATLEVEL_NONE )
    {
      UFG::SimpleTimer::Stop(&copChaseDurationTimer);
      v6 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v6, "HeatLevel") )
      {
        UFG::qSPrintf(&dest, 128, "i32_%s", "EventType", -2i64);
        OSuite::ZMetric::SetProperty(v6->m_pMetric, &dest, 704217046);
        UFG::qSPrintf(&dest, 128, "i32_%s", "HeatLevel");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, &dest, v4);
        v7 = *(_DWORD *)&FinishedReasonU32[4 * v5->mStats.mFinishReason];
        UFG::qSPrintf(&dest, 128, "i32_%s", "Outcome");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, &dest, v7);
        v8 = ((__int64 (__fastcall *)(UFG::CopSystem *))v5->vfptr[31].__vecDelDtor)(v5);
        UFG::qSPrintf(&dest, 128, "i32_%s", "CopsKilled");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, &dest, v8);
        v9 = ((__int64 (__fastcall *)(UFG::CopSystem *))v5->vfptr[30].__vecDelDtor)(v5);
        UFG::qSPrintf(&dest, 128, "i32_%s", "CopsSpawned");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, &dest, v9);
        v10 = UFG::SimpleTimer::GetElapsedSeconds(&copChaseDurationTimer);
        UFG::qSPrintf(&dest, 128, "f_%s", "Duration");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, &dest, v10);
        UFG::OSuiteDBLogger::SubmitMetric(v6, 1);
      }
      *(_QWORD *)&v5->mStats.mFinishReason = 0i64;
      v5->mStats.mLastLevelKillCount = 0;
    }
  }
  else
  {
    UFG::SimpleTimer::SetElapsedTime(&copChaseDurationTimer, 0.0);
    UFG::SimpleTimer::Start(&copChaseDurationTimer);
  }
  v5->mStats.mLastLevelSpawnCount = ((__int64 (__fastcall *)(UFG::CopSystem *))v5->vfptr[30].__vecDelDtor)(v5);
  v5->mStats.mLastLevelKillCount = ((__int64 (__fastcall *)(UFG::CopSystem *))v5->vfptr[31].__vecDelDtor)(v5);
}

