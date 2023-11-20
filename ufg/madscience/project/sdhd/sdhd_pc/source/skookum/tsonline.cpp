// File Line: 48
// RVA: 0x4D4BA0
void UFG::TSOnline::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Online");
  SSClass::register_method_func(v0, "has_new_challenge", UFG::TSOnline::MthdC_has_new_challenge, 1, 0);
  SSClass::register_method_func(v0, "upload_race_result", UFG::TSOnline::MthdC_upload_race_result, 1, 0);
  SSClass::register_method_func(v0, "update_stat_award", UFG::TSOnline::MthdC_update_stat_award, 1, 0);
  SSClass::register_method_func(v0, "update_stat_game", UFG::TSOnline::MthdC_update_stat_game, 1, 0);
  SSClass::register_method_func(v0, "end_stat_game", UFG::TSOnline::MthdC_end_stat_game, 1, 0);
}

// File Line: 61
// RVA: 0x4E8DD0
void __fastcall UFG::TSOnline::MthdC_has_new_challenge(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::SocialLogDataManager *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SocialLogDataManager::Instance();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3->m_bHasNewChallengeMessage);
  }
}

// File Line: 70
// RVA: 0x4F2DF0
void __fastcall UFG::TSOnline::MthdC_upload_race_result(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  const char ***v3; // r13
  bool v4; // r15
  int *v5; // r12
  float v6; // xmm6_4
  float v7; // xmm7_4
  const char ***v8; // r14
  const char *v9; // rbx
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax
  UFG::OSuiteLeaderboardData *v12; // rdi
  int v13; // esi
  UFG::GameStatTracker *v14; // rax
  int v15; // eax
  UFG::OSuiteLeaderboardManager *v16; // rax
  UFG::OSuiteLeaderboardData *v17; // rax
  const char *carUsed; // rbx
  UFG::OSuiteLeaderboardManager *v19; // rax
  UFG::GameStatTracker *v20; // rax
  UFG::GameStatTracker *v21; // rax
  unsigned __int64 v22; // rax
  UFG::SocialLogDataManager *v23; // rax
  unsigned int v24; // edi
  UFG::qBaseTreeRB *v25; // rax
  __int64 *v26; // rax
  int v27; // eax
  int v28; // esi
  UFG::qMap<int> *v29; // rbx
  UFG::OSuiteDBLogger *v30; // rdi
  int v31; // ebx
  int v32; // ebx
  int v33; // ebx
  const char *v34; // rbx
  const char *v35; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp-98h]
  int i32Value; // [rsp+34h] [rbp-94h]
  int *v38; // [rsp+38h] [rbp-90h]
  UFG::qMap<int> *v39; // [rsp+40h] [rbp-88h]
  __int64 v40; // [rsp+48h] [rbp-80h]
  UFG::SocialLogData_NewHighScore v41; // [rsp+50h] [rbp-78h]
  UFG::qSymbol v42; // [rsp+148h] [rbp+80h]
  const char ***v43; // [rsp+158h] [rbp+90h]
  UFG::qSymbol v44; // [rsp+160h] [rbp+98h]

  v40 = -2i64;
  v2 = pScope->i_data.i_array_p;
  v3 = (const char ***)&(*v2)->i_data_p->i_user_data;
  v43 = v3;
  v4 = v2[1]->i_data_p->i_user_data != 0;
  i32Value = v2[3]->i_data_p->i_user_data;
  v38 = (int *)&v2[4]->i_data_p->i_user_data;
  v5 = (int *)&v2[5]->i_data_p->i_user_data;
  v6 = *(float *)&v2[6]->i_data_p->i_user_data;
  v7 = *(float *)&v2[7]->i_data_p->i_user_data;
  v8 = (const char ***)&v2[8]->i_data_p->i_user_data;
  UFG::TSOnline::s_LastRaceResult = 0;
  UFG::TSOnline::s_BrokenNewRecord = 0;
  v9 = **v3;
  v10 = UFG::OSuiteLeaderboardManager::Instance();
  v11 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v10, v9);
  v12 = v11;
  if ( v11 && v11->mCategory == 3 )
  {
    if ( !v4 )
    {
      v13 = (signed int)(float)(v6 * 1000.0);
      v14 = UFG::GameStatTracker::Instance();
      v15 = UFG::GameStatTracker::GetStat(v14, LeaderboardScoreIntList, &v12->mLeaderboardName);
      UFG::TSOnline::s_LastRaceResult = (signed int)(float)(v6 * 1000.0);
      if ( !v15 || v13 < v15 )
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
        v22 = UFG::qGetSystemTimeUTC();
        UFG::SocialLogData_NewHighScore::SocialLogData_NewHighScore(
          &v41,
          (unsigned __int64)((v22 - 116444736000000000i64) * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11,
          v12->mLeaderboardId,
          v13);
        v23 = UFG::SocialLogDataManager::Instance();
        UFG::SocialLogDataManager::AddToSaveData(v23, (UFG::SocialLogData *)&v41.vfptr);
        UFG::TSOnline::s_BrokenNewRecord = 1;
        UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(&v41);
      }
      UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(v12, v13, 1);
      v3 = v43;
    }
    UFG::qSymbol::create_from_string(&result, "Failed");
    UFG::qSymbol::create_from_string(&v44, "Finished");
    LODWORD(v43) = 0;
    if ( !(_S18_3 & 1) )
    {
      _S18_3 |= 1u;
      v39 = &_attemptNumberMap;
      UFG::qBaseTreeRB::qBaseTreeRB(&_attemptNumberMap.mTree.mTree);
      atexit(UFG::TSOnline::MthdC_upload_race_result_::_11_::_dynamic_atexit_destructor_for____attemptNumberMap__);
    }
    UFG::qSymbol::create_from_string(&v42, **v3);
    v24 = v42.mUID;
    if ( v42.mUID && (v25 = UFG::qBaseTreeRB::Get(&_attemptNumberMap.mTree.mTree, v42.mUID), v24 = v42.mUID, v25) )
      v26 = (__int64 *)&v25->mNULL;
    else
      v26 = (__int64 *)&v43;
    v27 = *(_DWORD *)v26;
    LODWORD(v43) = v27;
    if ( v4 )
      v28 = v27 + 1;
    else
      v28 = 0;
    if ( !v24 || (v29 = (UFG::qMap<int> *)UFG::qBaseTreeRB::Get(&_attemptNumberMap.mTree.mTree, v24)) == 0i64 )
    {
      v29 = (UFG::qMap<int> *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
      v39 = v29;
      if ( v29 )
      {
        v29->mTree.mTree.mRoot.mParent = 0i64;
        v29->mTree.mTree.mRoot.mChild[0] = 0i64;
        v29->mTree.mTree.mRoot.mChild[1] = 0i64;
        v29->mTree.mTree.mRoot.mUID = v24;
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
      v35 = **v3;
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
  SSData **v2; // rdx
  SSInstance *v3; // rcx
  SSInstance *v4; // rdx
  const char *v5; // rbx
  int v6; // edi
  UFG::OSuiteLeaderboardManager *v7; // rax
  UFG::OSuiteLeaderboardData *v8; // rax
  float v9; // xmm6_4
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p;
  v5 = *(const char **)v3->i_user_data;
  if ( v4->i_class_p == SSBrain::c_integer_class_p )
  {
    v6 = v4->i_user_data;
    v7 = UFG::OSuiteLeaderboardManager::Instance();
    v8 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v7, v5);
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v8, v6);
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
  SSData **v2; // rdx
  SSInstance *v3; // rcx
  bool v4; // si
  const char *v5; // rbx
  int v6; // edi
  UFG::OSuiteLeaderboardManager *v7; // rax
  UFG::OSuiteLeaderboardData *v8; // rax
  float v9; // xmm6_4
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p;
  v4 = v2[2]->i_data_p->i_user_data != 0;
  v5 = *(const char **)(*v2)->i_data_p->i_user_data;
  if ( v3->i_class_p == SSBrain::c_integer_class_p )
  {
    v6 = v3->i_user_data;
    v7 = UFG::OSuiteLeaderboardManager::Instance();
    v8 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v7, v5);
    UFG::StatGameManager::UpdateScore(v8, v6, v4);
  }
  else
  {
    v9 = *(float *)&v3->i_user_data;
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
  UFG::OSuiteLeaderboardData *v4; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::OSuiteLeaderboardManager::Instance();
  v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, v2);
  UFG::StatGameManager::EndStatGame(v4);
}

