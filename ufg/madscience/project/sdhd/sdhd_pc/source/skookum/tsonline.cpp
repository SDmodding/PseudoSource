// File Line: 48
// RVA: 0x4D4BA0
void UFG::TSOnline::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Online");
  SSClass::register_method_func(v0, "has_new_challenge", UFG::TSOnline::MthdC_has_new_challenge, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "upload_race_result", UFG::TSOnline::MthdC_upload_race_result, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "update_stat_award", UFG::TSOnline::MthdC_update_stat_award, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "update_stat_game", UFG::TSOnline::MthdC_update_stat_game, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "end_stat_game", UFG::TSOnline::MthdC_end_stat_game, 1, rebindd);
}

// File Line: 61
// RVA: 0x4E8DD0
void __fastcall UFG::TSOnline::MthdC_has_new_challenge(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SocialLogDataManager *v3; // rax

  if ( ppResult )
  {
    v3 = UFG::SocialLogDataManager::Instance();
    *ppResult = SSBoolean::pool_new(v3->m_bHasNewChallengeMessage);
  }
}

// File Line: 70
// RVA: 0x4F2DF0
void __fastcall UFG::TSOnline::MthdC_upload_race_result(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  const char ***p_i_user_data; // r13
  bool v4; // r15
  int *v5; // r12
  float v6; // xmm6_4
  float v7; // xmm7_4
  const char ***v8; // r14
  const char *v9; // rbx
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::OSuiteLeaderboardData *v12; // rdi
  int v13; // esi
  UFG::GameStatTracker *v14; // rax
  int Stat; // eax
  UFG::OSuiteLeaderboardManager *v16; // rax
  UFG::OSuiteLeaderboardData *v17; // rax
  const char *carUsed; // rbx
  UFG::OSuiteLeaderboardManager *v19; // rax
  UFG::GameStatTracker *v20; // rax
  UFG::GameStatTracker *v21; // rax
  unsigned __int64 SystemTimeUTC; // rax
  UFG::SocialLogDataManager *v23; // rax
  unsigned int mUID; // edi
  UFG::qBaseTreeRB *v25; // rax
  __int64 *p_mNULL; // rax
  int v27; // eax
  int v28; // esi
  UFG::qMap<int> *v29; // rbx
  UFG::OSuiteDBLogger *v30; // rdi
  int v31; // ebx
  int v32; // ebx
  int v33; // ebx
  const char *v34; // rbx
  const char *v35; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp-98h] BYREF
  int i32Value; // [rsp+34h] [rbp-94h]
  int *v38; // [rsp+38h] [rbp-90h]
  UFG::qMap<int> *v39; // [rsp+40h] [rbp-88h]
  __int64 v40; // [rsp+48h] [rbp-80h]
  UFG::SocialLogData_NewHighScore v41; // [rsp+50h] [rbp-78h] BYREF
  UFG::qSymbol v42; // [rsp+148h] [rbp+80h] BYREF
  const char ***v43; // [rsp+158h] [rbp+90h] BYREF
  UFG::qSymbol v44; // [rsp+160h] [rbp+98h] BYREF

  v40 = -2i64;
  i_array_p = pScope->i_data.i_array_p;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  v43 = p_i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data != 0;
  i32Value = i_array_p[3]->i_data_p->i_user_data;
  v38 = (int *)&i_array_p[4]->i_data_p->i_user_data;
  v5 = (int *)&i_array_p[5]->i_data_p->i_user_data;
  v6 = *(float *)&i_array_p[6]->i_data_p->i_user_data;
  v7 = *(float *)&i_array_p[7]->i_data_p->i_user_data;
  v8 = (const char ***)&i_array_p[8]->i_data_p->i_user_data;
  UFG::TSOnline::s_LastRaceResult = 0;
  UFG::TSOnline::s_BrokenNewRecord = 0;
  v9 = **p_i_user_data;
  v10 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v10, v9);
  v12 = LeaderboardDataUsingLeaderboardName;
  if ( LeaderboardDataUsingLeaderboardName && LeaderboardDataUsingLeaderboardName->mCategory == LeaderboardCategory_Race )
  {
    if ( !v4 )
    {
      v13 = (int)(float)(v6 * 1000.0);
      v14 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v14, LeaderboardScoreIntList, &v12->mLeaderboardName);
      UFG::TSOnline::s_LastRaceResult = v13;
      if ( !Stat || v13 < Stat )
      {
        v16 = UFG::OSuiteLeaderboardManager::Instance();
        v17 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v16, "StatAwardsRacer");
        UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v17, 1);
        carUsed = **v8;
        v19 = UFG::OSuiteLeaderboardManager::Instance();
        UFG::OSuiteLeaderboardManager::UploadRaceResult(
          v19,
          v12,
          v13,
          1,
          carUsed,
          UFG::DataSynchronizer::UpdateLeaderboardCallback);
        v20 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v20, LeaderboardDirtyScoreBoolList, &v12->mLeaderboardName, 1);
        v21 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v21, LeaderboardScoreIntList, &v12->mLeaderboardName, v13);
        SystemTimeUTC = UFG::qGetSystemTimeUTC();
        UFG::SocialLogData_NewHighScore::SocialLogData_NewHighScore(
          &v41,
          (SystemTimeUTC - 116444736000000000i64) / 0x2710,
          v12->mLeaderboardId,
          v13);
        v23 = UFG::SocialLogDataManager::Instance();
        UFG::SocialLogDataManager::AddToSaveData(v23, &v41);
        UFG::TSOnline::s_BrokenNewRecord = 1;
        UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(&v41);
      }
      UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(v12, v13, 1);
      p_i_user_data = v43;
    }
    UFG::qSymbol::create_from_string(&result, "Failed");
    UFG::qSymbol::create_from_string(&v44, "Finished");
    LODWORD(v43) = 0;
    if ( (_S18_3 & 1) == 0 )
    {
      _S18_3 |= 1u;
      v39 = &_attemptNumberMap;
      UFG::qBaseTreeRB::qBaseTreeRB(&_attemptNumberMap.mTree.mTree);
      atexit(UFG::TSOnline::MthdC_upload_race_result_::_11_::_dynamic_atexit_destructor_for____attemptNumberMap__);
    }
    UFG::qSymbol::create_from_string(&v42, **p_i_user_data);
    mUID = v42.mUID;
    if ( v42.mUID && (v25 = UFG::qBaseTreeRB::Get(&_attemptNumberMap.mTree.mTree, v42.mUID), mUID = v42.mUID, v25) )
      p_mNULL = (__int64 *)&v25->mNULL;
    else
      p_mNULL = (__int64 *)&v43;
    v27 = *(_DWORD *)p_mNULL;
    LODWORD(v43) = v27;
    if ( v4 )
      v28 = v27 + 1;
    else
      v28 = 0;
    if ( !mUID || (v29 = (UFG::qMap<int> *)UFG::qBaseTreeRB::Get(&_attemptNumberMap.mTree.mTree, mUID)) == 0i64 )
    {
      v29 = (UFG::qMap<int> *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
      v39 = v29;
      if ( v29 )
      {
        v29->mTree.mTree.mRoot.mParent = 0i64;
        v29->mTree.mTree.mRoot.mChild[0] = 0i64;
        v29->mTree.mTree.mRoot.mChild[1] = 0i64;
        v29->mTree.mTree.mRoot.mUID = mUID;
        LODWORD(v29->mTree.mTree.mNULL.mParent) = v28;
      }
      else
      {
        v29 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&_attemptNumberMap.mTree.mTree, &v29->mTree.mTree.mRoot);
    }
    LODWORD(v29->mTree.mTree.mNULL.mParent) = v28;
    v30 = UFG::OSuiteDBLogger::Instance();
    if ( UFG::OSuiteDBLogger::CreateMetric(v30, "RaceEnd") )
    {
      v31 = v44.mUID;
      if ( v4 )
        v31 = result.mUID;
      UFG::qSPrintf((char *)&v41, 128, "i32_%s", "EndState");
      OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v31);
      UFG::qSPrintf((char *)&v41, 128, "i32_%s", "Position");
      OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, i32Value);
      if ( v38 )
      {
        v32 = *v38;
        UFG::qSPrintf((char *)&v41, 128, "i32_%s", "RaceClass");
        OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v32);
      }
      if ( v5 )
      {
        v33 = *v5;
        UFG::qSPrintf((char *)&v41, 128, "i32_%s", "RaceVehicleType");
        OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v33);
      }
      if ( v8 )
      {
        v34 = **v8;
        UFG::qSPrintf((char *)&v41, 128, "s_%s", "Vehicle");
        OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v34);
      }
      v35 = **p_i_user_data;
      UFG::qSPrintf((char *)&v41, 128, "s_%s", "Detail");
      OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v35);
      UFG::qSPrintf((char *)&v41, 128, "f_%s", "Distance");
      OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v7);
      UFG::qSPrintf((char *)&v41, 128, "f_%s", "Time");
      OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, v6);
      UFG::qSPrintf((char *)&v41, 128, "i32_%s", "AttemptNumber");
      OSuite::ZMetric::SetProperty(v30->m_pMetric, (const char *)&v41, (_DWORD)v43 + 1);
      UFG::OSuiteDBLogger::SubmitMetric(v30, 1);
    }
  }
}

// File Line: 158
// RVA: 0x4F2CB0
void __fastcall UFG::TSOnline::MthdC_update_stat_award(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rcx
  SSInstance *v4; // rdx
  const char *v5; // rbx
  int i_user_data; // edi
  UFG::OSuiteLeaderboardManager *v7; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  float v9; // xmm6_4
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p;
  v5 = *(const char **)i_data_p->i_user_data;
  if ( v4->i_class_p == SSBrain::c_integer_class_p )
  {
    i_user_data = v4->i_user_data;
    v7 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v7, v5);
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, i_user_data);
  }
  else
  {
    v9 = *(float *)&v4->i_user_data;
    v10 = UFG::OSuiteLeaderboardManager::Instance();
    v11 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v10, v5);
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v11, v9);
  }
}

// File Line: 185
// RVA: 0x4F2D40
void __fastcall UFG::TSOnline::MthdC_update_stat_game(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rcx
  bool v4; // si
  const char *v5; // rbx
  int i_user_data; // edi
  UFG::OSuiteLeaderboardManager *v7; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  float v9; // xmm6_4
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  v4 = i_array_p[2]->i_data_p->i_user_data != 0;
  v5 = *(const char **)(*i_array_p)->i_data_p->i_user_data;
  if ( i_data_p->i_class_p == SSBrain::c_integer_class_p )
  {
    i_user_data = i_data_p->i_user_data;
    v7 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v7, v5);
    UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, i_user_data, v4);
  }
  else
  {
    v9 = *(float *)&i_data_p->i_user_data;
    v10 = UFG::OSuiteLeaderboardManager::Instance();
    v11 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v10, v5);
    UFG::StatGameManager::UpdateScore(v11, v9, v4);
  }
}

// File Line: 213
// RVA: 0x4E55F0
void __fastcall UFG::TSOnline::MthdC_end_stat_game(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::OSuiteLeaderboardManager::Instance();
  LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, v2);
  UFG::StatGameManager::EndStatGame(LeaderboardDataUsingLeaderboardName);
}

