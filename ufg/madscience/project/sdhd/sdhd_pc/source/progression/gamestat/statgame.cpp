// File Line: 207
// RVA: 0x4A0B90
UFG::StatGame *__fastcall UFG::StatGame::FirstRequest(UFG::StatGame *this, UFG::OSuiteLeaderboardData *lbd, int score)
{
  unsigned int v3; // ebp
  UFG::OSuiteLeaderboardData *v4; // rdi
  UFG::StatGame *v5; // rsi
  UFG::CachedLeaderboardManager *v6; // rbx
  UFG::StatGamePropertyManager *v7; // rax
  UFG::StatGame *result; // rax
  char *v9; // rbx
  UFG::OnlineManager *v10; // rax
  bool v11; // al

  v3 = score;
  v4 = lbd;
  v5 = this;
  if ( !(_S15_1 & 1) )
  {
    _S15_1 |= 1u;
    instance_5.m_lLeaderboards.mNode.mPrev = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_lLeaderboards.mNode.mNext = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_bIsCachedLeaderboardBuilt = 0;
    atexit(UFG::CachedLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  v6 = (UFG::CachedLeaderboardManager *)instance_5.m_lLeaderboards.mNode.mNext;
  if ( (UFG::CachedLeaderboardManager *)instance_5.m_lLeaderboards.mNode.mNext == &instance_5 )
  {
LABEL_6:
    v6 = 0i64;
  }
  else
  {
    while ( v6[1].m_lLeaderboards.mNode.mNext[1].mNext->mPrev != (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)v4->mLeaderboardId )
    {
      v6 = (UFG::CachedLeaderboardManager *)v6->m_lLeaderboards.mNode.mNext;
      if ( v6 == &instance_5 )
        goto LABEL_6;
    }
  }
  if ( !(_S18_2 & 1) )
  {
    _S18_2 |= 1u;
    UFG::StatGamePropertyManager::StatGamePropertyManager(&instance_8);
    atexit(UFG::StatGamePropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  v7 = (UFG::StatGamePropertyManager *)&instance_8.m_lProperties.mNode.mNext[-1].mNext;
  if ( &instance_8.m_lProperties.mNode.mNext[-1].mNext == (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)((char *)&instance_8 - 8) )
    goto LABEL_15;
  while ( (UFG::OSuiteLeaderboardData *)v7[1].m_lProperties.mNode.mNext != v4 )
  {
    v7 = (UFG::StatGamePropertyManager *)&v7[1].m_lProperties.mNode.mPrev[-1].mNext;
    if ( v7 == (UFG::StatGamePropertyManager *)((char *)&instance_8 - 8) )
      goto LABEL_15;
  }
  if ( v6 )
  {
    v5->mPlayingIndex = -1;
    v5->mStatGameProp = (UFG::StatGamePropertyData *)v7;
    v5->mScore = v3;
    v5->mDeltaTime = (int)v7[1].m_lProperties.mNode.mNext[16].mPrev;
    v5->mLeaderboard = (UFG::CachedLeaderboard *)v6;
    v5->mCurrentScoreToBeat = 0i64;
    v5->mLBD = v4;
    UFG::StatGame::UpdateShouldStart(v5);
    result = v5;
  }
  else
  {
LABEL_15:
    v9 = v4->mLeaderboardNameStr.mData;
    v10 = UFG::OnlineManager::Instance();
    v11 = UFG::OnlineManager::IsNetworkSignedIn(v10);
    UFG::qPrintf(
      "====== YL:ASSERT:FixMe  Invalid leaderboard is requested for the stat game(%s, score: %d, online_connected: %d)\n",
      v9,
      v3,
      v11,
      -2i64);
    result = 0i64;
  }
  return result;
}

// File Line: 236
// RVA: 0x4C7E50
void __fastcall UFG::StatGame::UpdateScore(UFG::StatGame *this, int iScore)
{
  int v2; // edi
  UFG::StatGamePropertyData *v3; // rdx
  UFG::StatGame *v4; // rbx
  __int64 v5; // r8
  int v6; // eax

  v2 = iScore;
  v3 = this->mStatGameProp;
  v4 = this;
  if ( v3 )
  {
    v5 = (unsigned int)this->mScore;
    if ( (signed int)v5 > v2 )
      UFG::qPrintf(
        "====== YL:ASSERT:FixMe  somehow new score is lower than old score eh??? (%s, old:%d  new:%d)\n",
        v3->m_pLBD->mCaption.mData,
        v5,
        (unsigned int)v2);
    v6 = v4->mStatGameProp->m_pLBD->mDeltaTime;
    v4->mScore = v2;
    v4->mDeltaTime = v6;
    UFG::StatGame::UpdateShouldStart(v4);
  }
}

// File Line: 267
// RVA: 0x4BC6E0
void __fastcall UFG::StatGame::SetFinalScore(UFG::StatGame *this)
{
  UFG::StatGame *v1; // rbp
  UFG::GameStatTracker *v2; // rdi
  UFG::GameStatTracker *v3; // rcx
  UFG::PersistentData::MapInt *v4; // rcx
  __int64 v5; // rdx
  UFG::PersistentData::KeyValue *v6; // rax
  int v7; // ecx
  int v8; // esi
  UFG::qSymbol *v9; // rbx
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rcx
  UFG::StatGamePropertyData *v12; // rbx
  UFG::OSuiteLeaderboardManager *v13; // rax
  UFG::qSymbol *v14; // rbx
  UFG::GameStatTracker *v15; // rax
  unsigned int v16; // ecx
  UFG::GameStatTracker *v17; // r8
  __int64 v18; // rax
  unsigned __int64 v19; // rbx
  int v20; // esi
  int v21; // edi
  UFG::SocialLogDataManager *v22; // rax
  UFG::SocialLogData data; // [rsp+30h] [rbp-D8h]
  int v24; // [rsp+F0h] [rbp-18h]
  void *mem; // [rsp+F8h] [rbp-10h]

  v1 = this;
  UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(this->mStatGameProp->m_pLBD, this->mScore, 0);
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  v4 = v3->mpSnapshots[0]->mpMapInts[29];
  v5 = 0i64;
  if ( !v4->mValues.size )
    goto LABEL_12;
  v6 = v4->mValues.p;
  while ( v6->mKey.mUID != v1->mStatGameProp->m_pLBD->mLeaderboardName.mUID )
  {
    v5 = (unsigned int)(v5 + 1);
    ++v6;
    if ( (unsigned int)v5 >= v4->mValues.size )
      goto LABEL_12;
  }
  if ( (_DWORD)v5 != -1 )
    v7 = v4->mValues.p[v5].mIntValue;
  else
LABEL_12:
    v7 = 0;
  v8 = v1->mScore;
  if ( v7 < v8 )
  {
    v9 = (UFG::qSymbol *)v1->mStatGameProp->m_pLBD;
    v10 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v10 + 6216) & 1) )
    {
      UFG::PersistentData::MapInt::SetStatus(v10->mpSnapshots[0]->mpMapInts[29], v9 + 12, v8);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        }
        v11 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v11 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v11;
      }
    }
    v12 = v1->mStatGameProp;
    v13 = UFG::OSuiteLeaderboardManager::Instance();
    UFG::OSuiteLeaderboardManager::UploadStatGameResult(
      v13,
      v12->m_pLBD,
      v1->mScore,
      UFG::DataSynchronizer::UpdateLeaderboardCallback);
    v14 = (UFG::qSymbol *)v1->mStatGameProp->m_pLBD;
    v15 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v15 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v15->mpSnapshots[0]->mpMapBools[79], v14 + 12, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v16 = _S12_6;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v16 = _S12_6;
        }
        v17 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v17 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v17;
        if ( !(v16 & 1) )
        {
          _S12_6 = v16 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v17 = UFG::GameStatTracker::mspInstance;
        }
        if ( v17 )
          v2 = v17;
        UFG::GameStatTracker::mspInstance = v2;
        v18 = v2->mpSnapshots[0]->mpMapBools[79]->mKeepType;
      }
    }
    v19 = UFG::qGetSystemTimeUTC();
    v20 = v1->mScore;
    v21 = v1->mStatGameProp->m_pLBD->mLeaderboardId;
    UFG::SocialLogData::SocialLogData(&data);
    data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable';
    v24 = 0;
    mem = 0i64;
    data.m_iCommId = 0;
    data.m_iTimeStamp = (unsigned __int64)((v19 - 116444736000000000i64) * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11;
    data.m_iLeaderboardId = v21;
    data.m_iScore = v20;
    v22 = UFG::SocialLogDataManager::Instance();
    UFG::SocialLogDataManager::AddToSaveData(v22, &data);
    data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable';
    if ( mem )
      operator delete[](mem);
    UFG::SocialLogData::~SocialLogData(&data);
  }
}

// File Line: 297
// RVA: 0x4BE950
void __fastcall UFG::StatGame::ShowFinalScore(UFG::StatGame *this)
{
  UFG::StatGame *v1; // rsi
  UFG::StatGamePropertyData *v2; // r14
  UFG::CachedLeaderboard *v3; // r8
  int v4; // edi
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v5; // rax
  int v6; // ecx
  UFG::qSymbol *v7; // rbx
  UFG::GameStatTracker *v8; // rax
  unsigned int v9; // ecx
  UFG::GameStatTracker *v10; // rbx
  UFG::GameStatTracker *v11; // r8
  __int64 v12; // rax
  UFG::PersistentData::MapInt *v13; // rax
  unsigned int v14; // er8
  int v15; // edi
  unsigned int v16; // edx
  UFG::PersistentData::KeyValue *v17; // r9
  UFG::PersistentData::KeyValue *v18; // rax
  int v19; // ecx
  UFG::UIHKScreenHud *v20; // rbp
  int v21; // ebx
  UFG::qString str; // [rsp+38h] [rbp-40h]

  v1 = this;
  v2 = this->mStatGameProp;
  v3 = this->mLeaderboard;
  if ( v3 )
  {
    v4 = 1;
    v5 = v3->m_lEntries.mNode.mNext;
    if ( v5 != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&v3->m_lEntries )
    {
      v6 = this->mScore;
      do
      {
        if ( SLODWORD(v5[1].mPrev) <= v6 )
          break;
        ++v4;
        v5 = v5->mNext;
      }
      while ( v5 != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&v3->m_lEntries );
    }
    v7 = (UFG::qSymbol *)v3->m_pPropertyData->m_pLBD;
    v8 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v8 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v8->mpSnapshots[0]->mpMapBools[55], v7 + 12, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v9 = _S12_6;
        v10 = &sGameStatTracker;
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v9 = _S12_6;
        }
        v11 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v11 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v11;
        if ( !(v9 & 1) )
        {
          _S12_6 = v9 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v11 = UFG::GameStatTracker::mspInstance;
        }
        if ( v11 )
          v10 = v11;
        UFG::GameStatTracker::mspInstance = v10;
        v12 = v10->mpSnapshots[0]->mpMapBools[55]->mKeepType;
      }
    }
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      if ( v4 < 1 )
        return;
    }
    else
    {
      v13 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapInts[29];
      v14 = v13->mValues.size;
      v15 = 0;
      v16 = 0;
      if ( !v13->mValues.size )
        goto LABEL_25;
      v17 = v13->mValues.p;
      v18 = v13->mValues.p;
      while ( v18->mKey.mUID != v1->mLeaderboard->m_pPropertyData->m_pLBD->mLeaderboardName.mUID )
      {
        ++v16;
        ++v18;
        if ( v16 >= v14 )
          goto LABEL_25;
      }
      if ( v16 != -1 )
        v19 = v17[v16].mIntValue;
      else
LABEL_25:
        v19 = 0;
      LOBYTE(v15) = v1->mScore < v19;
      v4 = v15 + 1;
    }
    v20 = UFG::UIHKScreenHud::getInstance();
    if ( v20 )
    {
      if ( v2 )
      {
        v21 = UFG::StatGameManager::GetPlayingIndex(UFG::StatGameManager::sInstance, v1);
        UFG::qString::qString(&str);
        UFG::StatGamePropertyData::FormatScore(v2, &str, (unsigned int)v1->mScore);
        UFG::UIHKScreenHud::SetStatGameFinalScore(v20, v21, v2->m_pLBD->mRankDesc.mData, v4, str.mData);
        UFG::qString::~qString(&str);
      }
    }
  }
}

// File Line: 333
// RVA: 0x4B3800
void __fastcall UFG::StatGame::PushToHud(UFG::StatGame *this)
{
  UFG::StatGame *v1; // rbp
  UFG::CachedLeaderboard *v2; // rax
  signed int v3; // esi
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v4; // rdx
  signed __int64 v5; // rax
  int v6; // ecx
  char *v7; // r10
  UFG::GameStatTracker *v8; // rbx
  UFG::PersistentData::MapInt *v9; // rcx
  __int64 v10; // rdx
  UFG::PersistentData::KeyValue *v11; // rax
  int v12; // edi
  UFG::CachedLeaderboard::Entry *v13; // r13
  UFG::qList<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry,1,0> *v14; // rax
  UFG::CachedLeaderboard::Entry *v15; // rbx
  const char *leader; // r12
  UFG::UIHKScreenHud *v17; // r15
  UFG::StatGamePropertyData *v18; // r14
  UFG::qString leaderscore; // [rsp+38h] [rbp-D0h]
  UFG::qString v20; // [rsp+60h] [rbp-A8h]
  UFG::qString v21; // [rsp+88h] [rbp-80h]
  UFG::qString str; // [rsp+B0h] [rbp-58h]
  char *myname; // [rsp+110h] [rbp+8h]

  v1 = this;
  v2 = this->mLeaderboard;
  v3 = 1;
  v4 = v2->m_lEntries.mNode.mNext;
  v5 = (signed __int64)&v2->m_lEntries;
  if ( v4 != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)v5 )
  {
    v6 = this->mScore;
    do
    {
      if ( SLODWORD(v4[1].mPrev) <= v6 )
        break;
      ++v3;
      v4 = v4->mNext;
    }
    while ( v4 != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)v5 );
  }
  v7 = UFG::UI::GetPlayerDisplayName();
  myname = v7;
  v8 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v7 = myname;
  }
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  v9 = v8->mpSnapshots[0]->mpMapInts[29];
  v10 = 0i64;
  if ( !v9->mValues.size )
    goto LABEL_16;
  v11 = v9->mValues.p;
  while ( v11->mKey.mUID != v1->mLeaderboard->m_pPropertyData->m_pLBD->mLeaderboardName.mUID )
  {
    v10 = (unsigned int)(v10 + 1);
    ++v11;
    if ( (unsigned int)v10 >= v9->mValues.size )
      goto LABEL_16;
  }
  if ( (_DWORD)v10 != -1 )
    v12 = v9->mValues.p[v10].mIntValue;
  else
LABEL_16:
    v12 = 0;
  if ( v1->mScore > v12 )
    v12 = v1->mScore;
  v13 = v1->mCurrentScoreToBeat;
  v14 = &v1->mLeaderboard->m_lEntries;
  v15 = (UFG::CachedLeaderboard::Entry *)v14->mNode.mPrev;
  if ( (UFG::qList<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry,1,0> *)v14->mNode.mPrev == v14 )
  {
LABEL_25:
    v15 = 0i64;
LABEL_26:
    leader = v7;
    goto LABEL_27;
  }
  while ( v15->m_iRating <= v12 )
  {
    v15 = (UFG::CachedLeaderboard::Entry *)v15->mPrev;
    if ( v15 == (UFG::CachedLeaderboard::Entry *)v14 )
      goto LABEL_25;
  }
  if ( !v15 )
    goto LABEL_26;
  leader = v15->m_sUsername;
  v12 = v15->m_iRating;
LABEL_27:
  v17 = UFG::UIHKScreenHud::getInstance();
  v18 = v1->mStatGameProp;
  if ( v17 && v18 )
  {
    UFG::qString::qString(&str);
    UFG::qString::qString(&leaderscore);
    UFG::StatGamePropertyData::FormatScore(v18, &str, (unsigned int)v1->mScore);
    if ( v13 != v15 )
    {
      if ( v13 && v13->m_iRating < v1->mScore )
      {
        UFG::qString::qString(&v21);
        UFG::qString::qString(&v20);
        UFG::StatGamePropertyData::FormatScore(v18, &v21, (unsigned int)v13->m_iRating);
        UFG::qString::Format(&v20, "%d: %s", v13->m_uRank, v13->m_sUsername);
        UFG::UIHKScreenHud::SetStatGameBeatHim(v17, v20.mData, v21.mData);
        UFG::qString::~qString(&v20);
        UFG::qString::~qString(&v21);
      }
      v1->mCurrentScoreToBeat = v15;
    }
    if ( v12 )
      UFG::StatGamePropertyData::FormatScore(v18, &leaderscore, (unsigned int)v12);
    else
      UFG::qString::Set(&leaderscore, &customWorldMapCaption);
    UFG::UIHKScreenHud::SetStatGameInfo(v17, v18->m_pLBD->mCaption.mData, myname, str.mData, leader, leaderscore.mData);
    if ( v3 == 1 )
      UFG::UIHKScreenHud::SetStatMakingNewRecord(v17);
    UFG::qString::~qString(&leaderscore);
    UFG::qString::~qString(&str);
  }
}

// File Line: 399
// RVA: 0x4C81C0
void __fastcall UFG::StatGame::UpdateShouldStart(UFG::StatGame *this)
{
  int v1; // eax

  if ( this->mPlayingIndex < 0 && this->mScore >= this->mStatGameProp->m_pLBD->mAttemptCount )
  {
    v1 = 0;
    if ( UFG::StatGameManager::sInstance->mQueue[0].mPlayingIndex >= 0 )
      v1 = 1;
    if ( UFG::StatGameManager::sInstance->mQueue[1].mPlayingIndex >= 0 )
      ++v1;
    if ( UFG::StatGameManager::sInstance->mQueue[2].mPlayingIndex >= 0 )
      ++v1;
    if ( UFG::StatGameManager::sInstance->mQueue[3].mPlayingIndex >= 0 )
      ++v1;
    if ( UFG::StatGameManager::sInstance->mQueue[4].mPlayingIndex >= 0 )
      ++v1;
    if ( v1 < 1 )
      this->mPlayingIndex = v1;
  }
}

// File Line: 425
// RVA: 0x4AB990
void UFG::StatGameManager::Instantiate(void)
{
  UFG::allocator::free_link *v0; // rax

  if ( !UFG::StatGameManager::sInstance )
  {
    v0 = UFG::qMalloc(0x100ui64, "StatGameManager", 0i64);
    if ( v0 )
      UFG::StatGameManager::StatGameManager((UFG::StatGameManager *)v0);
    UFG::StatGameManager::sInstance = (UFG::StatGameManager *)v0;
    LOBYTE(v0->mNext) = 1;
  }
}

// File Line: 453
// RVA: 0x48DC60
void __fastcall UFG::StatGameManager::StatGameManager(UFG::StatGameManager *this)
{
  *(_WORD *)&this->mDefaultFlowGamesAreEnabled = 257;
  this->mQueue[0].mPlayingIndex = -1;
  this->mQueue[0].mLeaderboard = 0i64;
  this->mQueue[0].mCurrentScoreToBeat = 0i64;
  this->mQueue[0].mStatGameProp = 0i64;
  *(_QWORD *)&this->mQueue[0].mScore = 0i64;
  this->mQueue[0].mLBD = 0i64;
  this->mQueue[1].mLeaderboard = 0i64;
  this->mQueue[1].mCurrentScoreToBeat = 0i64;
  this->mQueue[1].mStatGameProp = 0i64;
  *(_QWORD *)&this->mQueue[1].mScore = 0i64;
  this->mQueue[1].mLBD = 0i64;
  this->mQueue[2].mLeaderboard = 0i64;
  this->mQueue[2].mCurrentScoreToBeat = 0i64;
  this->mQueue[2].mStatGameProp = 0i64;
  *(_QWORD *)&this->mQueue[2].mScore = 0i64;
  this->mQueue[2].mLBD = 0i64;
  this->mQueue[3].mLeaderboard = 0i64;
  this->mQueue[3].mCurrentScoreToBeat = 0i64;
  this->mQueue[3].mStatGameProp = 0i64;
  *(_QWORD *)&this->mQueue[3].mScore = 0i64;
  this->mQueue[3].mLBD = 0i64;
  this->mQueue[4].mLeaderboard = 0i64;
  this->mQueue[4].mCurrentScoreToBeat = 0i64;
  this->mQueue[4].mStatGameProp = 0i64;
  *(_QWORD *)&this->mQueue[4].mScore = 0i64;
  this->mQueue[4].mLBD = 0i64;
  this->mQueue[1].mPlayingIndex = -1;
  this->mQueue[2].mPlayingIndex = -1;
  this->mQueue[3].mPlayingIndex = -1;
  this->mQueue[4].mPlayingIndex = -1;
}

// File Line: 457
// RVA: 0x4C7EB0
void __fastcall UFG::StatGameManager::UpdateScore(UFG::OSuiteLeaderboardData *lbd, int point, bool bDelta)
{
  UFG::StatGameManager *v3; // rdi
  bool v4; // bp
  int v5; // esi
  UFG::OSuiteLeaderboardData *v6; // rbx
  UFG::StatGame *v7; // r10
  UFG::OSuiteLeaderboardData **v8; // rax
  int v9; // edx
  signed __int64 v10; // rcx

  v3 = UFG::StatGameManager::sInstance;
  v4 = bDelta;
  v5 = point;
  v6 = lbd;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1
     || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID
     && (UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID != gDefaultFlowId.mUID
      || v6->mFlow.mUID != gDefaultFlowId.mUID
      || v3->mDefaultFlowGamesAreEnabled)) )
  {
    v7 = 0i64;
    v8 = &v3->mQueue[0].mLBD;
    v9 = 0;
    v10 = 0i64;
    while ( *v8 != v6 )
    {
      ++v10;
      ++v9;
      v8 += 6;
      if ( v10 >= 5 )
        goto LABEL_14;
    }
    v7 = &v3->mQueue[v9];
    if ( v7 )
    {
      if ( v4 )
      {
        v7->mScore += v5;
        v5 = v7->mScore;
      }
    }
LABEL_14:
    UFG::StatGameManager::UpdateScoreWithStatGame(v3, v7, v6, v5);
  }
}

// File Line: 491
// RVA: 0x4C7F90
void __fastcall UFG::StatGameManager::UpdateScore(UFG::OSuiteLeaderboardData *lbd, float point, bool bDelta)
{
  UFG::StatGameManager *v3; // rdi
  bool v4; // si
  UFG::OSuiteLeaderboardData *v5; // rbx
  UFG::StatGame *v6; // r10
  UFG::OSuiteLeaderboardData **v7; // rax
  int v8; // edx
  signed __int64 v9; // rcx
  int v10; // er9

  v3 = UFG::StatGameManager::sInstance;
  v4 = bDelta;
  v5 = lbd;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1
     || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID
     && (UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID != gDefaultFlowId.mUID
      || v5->mFlow.mUID != gDefaultFlowId.mUID
      || v3->mDefaultFlowGamesAreEnabled)) )
  {
    v6 = 0i64;
    v7 = &v3->mQueue[0].mLBD;
    v8 = 0;
    v9 = 0i64;
    while ( *v7 != v5 )
    {
      ++v9;
      ++v8;
      v7 += 6;
      if ( v9 >= 5 )
        goto LABEL_12;
    }
    v6 = &v3->mQueue[v8];
LABEL_12:
    v10 = (signed int)(float)(point * 1000.0);
    if ( v6 )
    {
      if ( v4 )
      {
        v6->mScore += v10;
        v10 = v6->mScore;
      }
    }
    UFG::StatGameManager::UpdateScoreWithStatGame(v3, v6, v5, v10);
  }
}

// File Line: 526
// RVA: 0x4C8090
void __fastcall UFG::StatGameManager::UpdateScoreWithStatGame(UFG::StatGameManager *this, UFG::StatGame *pSG, UFG::OSuiteLeaderboardData *lbd, int score)
{
  int v4; // edi
  int v5; // ebp
  UFG::StatGame *v6; // rbx
  UFG::StatGameManager *v7; // rsi
  UFG::StatGamePropertyData *v8; // rdx
  __int64 v9; // r8
  int v10; // eax
  int v11; // edx
  signed __int64 v12; // rcx
  UFG::StatGamePropertyData **v13; // rax
  signed int v14; // edx
  UFG::StatGame *v15; // r8
  signed __int64 v16; // rcx

  v4 = 0;
  v5 = score;
  v6 = pSG;
  v7 = this;
  if ( pSG )
  {
    v8 = pSG->mStatGameProp;
    if ( v8 )
    {
      v9 = (unsigned int)v6->mScore;
      if ( (signed int)v9 > score )
        UFG::qPrintf(
          "====== YL:ASSERT:FixMe  somehow new score is lower than old score eh??? (%s, old:%d  new:%d)\n",
          v8->m_pLBD->mCaption.mData,
          v9,
          (unsigned int)score);
      v10 = v6->mStatGameProp->m_pLBD->mDeltaTime;
      v6->mScore = v5;
      v6->mDeltaTime = v10;
      UFG::StatGame::UpdateShouldStart(v6);
    }
LABEL_12:
    if ( v6->mPlayingIndex >= 0 )
    {
      v14 = 0;
      v15 = v7->mQueue;
      do
      {
        if ( &v7->mQueue[v14] == v6 )
          break;
        if ( v15->mPlayingIndex >= 0 )
          ++v4;
        ++v14;
        ++v15;
      }
      while ( v14 < 5 );
      if ( !v4 )
        UFG::StatGame::PushToHud(v6);
    }
    return;
  }
  v11 = 0;
  v12 = 0i64;
  v13 = &v7->mQueue[0].mStatGameProp;
  while ( *v13 )
  {
    ++v12;
    ++v11;
    v13 += 6;
    if ( v12 >= 5 )
    {
      v6 = 0i64;
LABEL_10:
      UFG::qPrintf(
        "StatGameAddRequest Error Queue full (discarding request id:%s(%d))\n",
        lbd->mLeaderboardNameStr.mData,
        (unsigned int)score);
      goto LABEL_11;
    }
  }
  v16 = v11;
  v6 = &v7->mQueue[v16];
  if ( !v6 )
    goto LABEL_10;
  v6 = UFG::StatGame::FirstRequest(&v7->mQueue[v16], lbd, score);
LABEL_11:
  if ( v6 )
    goto LABEL_12;
}

// File Line: 543
// RVA: 0x49DF60
void __fastcall UFG::StatGameManager::EndStatGame(UFG::OSuiteLeaderboardData *lbd)
{
  UFG::StatGameManager *v1; // rbx
  UFG::OSuiteLeaderboardData *v2; // rdi
  UFG::OSuiteLeaderboardData **v3; // rax
  int v4; // edx
  signed __int64 v5; // rcx
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **v6; // rax
  signed __int64 i; // rcx
  UFG::StatGame *v8; // rbx

  v1 = UFG::StatGameManager::sInstance;
  v2 = lbd;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1 || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID) )
  {
    v3 = &v1->mQueue[0].mLBD;
    v4 = 0;
    v5 = 0i64;
    while ( *v3 != v2 )
    {
      ++v5;
      ++v4;
      v3 += 6;
      if ( v5 >= 5 )
        goto LABEL_7;
    }
    v8 = &v1->mQueue[v4];
    if ( !v8 )
    {
LABEL_7:
      v6 = &UFG::StatGamePropertyManager::Instance()[-1].m_lProperties.mNode.mNext;
      for ( i = (signed __int64)&v6[2][-1].mNext;
            (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)i != v6;
            i = *(_QWORD *)(i + 16) - 8i64 )
      {
        if ( *(UFG::OSuiteLeaderboardData **)(i + 24) == v2 )
          break;
      }
      return;
    }
    if ( v8->mPlayingIndex >= 0 )
    {
      UFG::StatGame::SetFinalScore(v8);
      UFG::StatGame::ShowFinalScore(v8);
    }
    v8->mStatGameProp = 0i64;
    v8->mScore = 0;
    v8->mLeaderboard = 0i64;
    v8->mCurrentScoreToBeat = 0i64;
    v8->mLBD = 0i64;
    v8->mPlayingIndex = -1;
  }
}

// File Line: 563
// RVA: 0x49E050
void __fastcall UFG::StatGameManager::EndStatGame(UFG::OSuiteLeaderboardData *lbd, int points)
{
  UFG::StatGameManager *v2; // rbx
  int v3; // esi
  UFG::OSuiteLeaderboardData *v4; // rdi
  UFG::OSuiteLeaderboardData **v5; // rax
  int v6; // edx
  signed __int64 v7; // rcx
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **v8; // rax
  signed __int64 i; // rcx
  UFG::StatGame *v10; // rbx

  v2 = UFG::StatGameManager::sInstance;
  v3 = points;
  v4 = lbd;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1 || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID) )
  {
    v5 = &v2->mQueue[0].mLBD;
    v6 = 0;
    v7 = 0i64;
    while ( *v5 != v4 )
    {
      ++v7;
      ++v6;
      v5 += 6;
      if ( v7 >= 5 )
        goto LABEL_7;
    }
    v10 = &v2->mQueue[v6];
    if ( !v10 )
    {
LABEL_7:
      v8 = &UFG::StatGamePropertyManager::Instance()[-1].m_lProperties.mNode.mNext;
      for ( i = (signed __int64)&v8[2][-1].mNext;
            (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)i != v8;
            i = *(_QWORD *)(i + 16) - 8i64 )
      {
        if ( *(UFG::OSuiteLeaderboardData **)(i + 24) == v4 )
          break;
      }
      return;
    }
    if ( v10->mPlayingIndex >= 0 )
    {
      UFG::StatGame::UpdateScore(v10, v3);
      if ( v10->mPlayingIndex >= 0 )
      {
        UFG::StatGame::SetFinalScore(v10);
        UFG::StatGame::ShowFinalScore(v10);
      }
    }
    v10->mStatGameProp = 0i64;
    v10->mScore = 0;
    v10->mLeaderboard = 0i64;
    v10->mCurrentScoreToBeat = 0i64;
    v10->mPlayingIndex = -1;
    v10->mLBD = 0i64;
  }
}

// File Line: 589
// RVA: 0x4C4950
void __fastcall UFG::StatGameManager::Update(UFG::StatGameManager *this, float deltaT)
{
  signed __int64 v2; // rsi
  UFG::StatGameManager *v3; // r14
  int v4; // ebp
  int *v5; // rbx
  __int64 v6; // rax
  signed int v7; // eax

  v2 = 5i64;
  v3 = this;
  v4 = LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(this->mPrevTime);
  v5 = &this->mQueue[0].mDeltaTime;
  do
  {
    v6 = *(_QWORD *)(v5 - 3);
    if ( v6 )
    {
      *v5 -= v4;
      if ( *v5 > 0 )
      {
        if ( *(v5 - 9) < 0 && *(v5 - 1) >= *(_DWORD *)(*(_QWORD *)(v6 + 24) + 260i64) )
        {
          v7 = 0;
          if ( UFG::StatGameManager::sInstance->mQueue[0].mPlayingIndex >= 0 )
            v7 = 1;
          if ( UFG::StatGameManager::sInstance->mQueue[1].mPlayingIndex >= 0 )
            ++v7;
          if ( UFG::StatGameManager::sInstance->mQueue[2].mPlayingIndex >= 0 )
            ++v7;
          if ( UFG::StatGameManager::sInstance->mQueue[3].mPlayingIndex >= 0 )
            ++v7;
          if ( UFG::StatGameManager::sInstance->mQueue[4].mPlayingIndex >= 0 )
            ++v7;
          if ( v7 < 1 )
            *(v5 - 9) = v7;
        }
      }
      else
      {
        if ( *(v5 - 9) >= 0 )
        {
          UFG::StatGame::SetFinalScore((UFG::StatGame *)(v5 - 9));
          UFG::StatGame::ShowFinalScore((UFG::StatGame *)(v5 - 9));
        }
        *(_QWORD *)(v5 - 3) = 0i64;
        *(v5 - 1) = 0;
        *(_QWORD *)(v5 - 7) = 0i64;
        *(_QWORD *)(v5 - 5) = 0i64;
        *(v5 - 9) = -1;
        *(_QWORD *)(v5 + 1) = 0i64;
      }
    }
    v5 += 12;
    --v2;
  }
  while ( v2 );
  v3->mPrevTime = UFG::Metrics::msInstance.mSimTimeMSec;
}

// File Line: 631
// RVA: 0x4A0A60
void __fastcall UFG::StatGameManager::FinishCurrentStats(UFG::StatGameManager *this)
{
  int *v1; // rbx
  signed __int64 v2; // rsi

  v1 = &this->mQueue[0].mScore;
  v2 = 5i64;
  do
  {
    if ( *(v1 - 8) >= 0 && *(_DWORD *)(*((_QWORD *)v1 + 1) + 304i64) == gDefaultFlowId.mUID )
    {
      UFG::StatGame::SetFinalScore((UFG::StatGame *)(v1 - 8));
      UFG::StatGame::ShowFinalScore((UFG::StatGame *)(v1 - 8));
      *((_QWORD *)v1 - 1) = 0i64;
      *v1 = 0;
      *((_QWORD *)v1 - 3) = 0i64;
      *((_QWORD *)v1 - 2) = 0i64;
      *(v1 - 8) = -1;
      *((_QWORD *)v1 + 1) = 0i64;
    }
    v1 += 12;
    --v2;
  }
  while ( v2 );
}

// File Line: 652
// RVA: 0x4A5EC0
__int64 __fastcall UFG::StatGameManager::GetPlayingIndex(UFG::StatGameManager *this, UFG::StatGame *me)
{
  unsigned int v2; // er11
  UFG::StatGame *v3; // r10
  signed int v4; // er8

  v2 = 0;
  v3 = this->mQueue;
  v4 = 0;
  do
  {
    if ( &this->mQueue[v4] == me )
      break;
    if ( v3->mPlayingIndex >= 0 )
      ++v2;
    ++v4;
    ++v3;
  }
  while ( v4 < 5 );
  return v2;
}

