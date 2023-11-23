// File Line: 18
// RVA: 0x3F1D40
void __fastcall UFG::CopSystem::UpdateTelemetryStatsNewLevel(
        UFG::CopSystem *this,
        int oldHeatLevel,
        UFG::HeatLevelEnum newHeatLevel)
{
  UFG::OSuiteDBLogger *v6; // rsi
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  float ElapsedSeconds; // xmm0_4
  char dest[144]; // [rsp+30h] [rbp-98h] BYREF

  if ( (_S9_10 & 1) == 0 )
  {
    _S9_10 |= 1u;
    UFG::SimpleTimer::SimpleTimer(&copChaseDurationTimer);
    atexit(UFG::CopSystem::UpdateTelemetryStatsNewLevel_::_2_::_dynamic_atexit_destructor_for__copChaseDurationTimer__);
  }
  if ( oldHeatLevel )
  {
    if ( newHeatLevel == HEATLEVEL_NONE )
    {
      UFG::SimpleTimer::Stop(&copChaseDurationTimer);
      v6 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v6, "HeatLevel") )
      {
        UFG::qSPrintf(dest, 128, "i32_%s", "EventType");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, dest, 704217046);
        UFG::qSPrintf(dest, 128, "i32_%s", "HeatLevel");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, dest, oldHeatLevel);
        v7 = *(_DWORD *)&FinishedReasonU32[4 * this->mStats.mFinishReason];
        UFG::qSPrintf(dest, 128, "i32_%s", "Outcome");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, dest, v7);
        v8 = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[31].__vecDelDtor)(this);
        UFG::qSPrintf(dest, 128, "i32_%s", "CopsKilled");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, dest, v8);
        v9 = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[30].__vecDelDtor)(this);
        UFG::qSPrintf(dest, 128, "i32_%s", "CopsSpawned");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, dest, v9);
        ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&copChaseDurationTimer);
        UFG::qSPrintf(dest, 128, "f_%s", "Duration");
        OSuite::ZMetric::SetProperty(v6->m_pMetric, dest, ElapsedSeconds);
        UFG::OSuiteDBLogger::SubmitMetric(v6, 1);
      }
      *(_QWORD *)&this->mStats.mFinishReason = 0i64;
      this->mStats.mLastLevelKillCount = 0;
    }
  }
  else
  {
    UFG::SimpleTimer::SetElapsedTime(&copChaseDurationTimer, 0.0);
    UFG::SimpleTimer::Start(&copChaseDurationTimer);
  }
  this->mStats.mLastLevelSpawnCount = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[30].__vecDelDtor)(this);
  this->mStats.mLastLevelKillCount = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[31].__vecDelDtor)(this);
}

