// File Line: 207
// RVA: 0x4A0B90
UFG::StatGame *__fastcall UFG::StatGame::FirstRequest(
        UFG::StatGame *this,
        UFG::OSuiteLeaderboardData *lbd,
        unsigned int score)
{
  UFG::CachedLeaderboardManager *mNext; // rbx
  UFG::StatGamePropertyData *p_mNext; // rax
  char *mData; // rbx
  UFG::OnlineManager *v10; // rax
  bool IsNetworkSignedIn; // al

  if ( (_S15_1 & 1) == 0 )
  {
    _S15_1 |= 1u;
    instance_5.m_lLeaderboards.mNode.mPrev = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_lLeaderboards.mNode.mNext = (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)&instance_5;
    instance_5.m_bIsCachedLeaderboardBuilt = 0;
    atexit(UFG::CachedLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  mNext = (UFG::CachedLeaderboardManager *)instance_5.m_lLeaderboards.mNode.mNext;
  if ( (UFG::CachedLeaderboardManager *)instance_5.m_lLeaderboards.mNode.mNext == &instance_5 )
  {
LABEL_6:
    mNext = 0i64;
  }
  else
  {
    while ( mNext[1].m_lLeaderboards.mNode.mNext[1].mNext->mPrev != (UFG::qNode<UFG::CachedLeaderboard,UFG::CachedLeaderboard> *)lbd->mLeaderboardId )
    {
      mNext = (UFG::CachedLeaderboardManager *)mNext->m_lLeaderboards.mNode.mNext;
      if ( mNext == &instance_5 )
        goto LABEL_6;
    }
  }
  if ( (_S18_2 & 1) == 0 )
  {
    _S18_2 |= 1u;
    UFG::StatGamePropertyManager::StatGamePropertyManager(&instance_8);
    atexit(UFG::StatGamePropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  p_mNext = (UFG::StatGamePropertyData *)&instance_8.m_lProperties.mNode.mNext[-1].mNext;
  if ( &instance_8.m_lProperties.mNode.mNext[-1].mNext == (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)((char *)&instance_8 - 8) )
    goto LABEL_15;
  while ( p_mNext->m_pLBD != lbd )
  {
    p_mNext = (UFG::StatGamePropertyData *)&p_mNext->mNext[-1].mNext;
    if ( p_mNext == (UFG::StatGamePropertyData *)((char *)&instance_8 - 8) )
      goto LABEL_15;
  }
  if ( !mNext )
  {
LABEL_15:
    mData = lbd->mLeaderboardNameStr.mData;
    v10 = UFG::OnlineManager::Instance();
    IsNetworkSignedIn = UFG::OnlineManager::IsNetworkSignedIn(v10);
    UFG::qPrintf(
      "====== YL:ASSERT:FixMe  Invalid leaderboard is requested for the stat game(%s, score: %d, online_connected: %d)\n",
      mData,
      score,
      IsNetworkSignedIn);
    return 0i64;
  }
  else
  {
    this->mPlayingIndex = -1;
    this->mStatGameProp = p_mNext;
    this->mScore = score;
    this->mDeltaTime = p_mNext->m_pLBD->mDeltaTime;
    this->mLeaderboard = (UFG::CachedLeaderboard *)mNext;
    this->mCurrentScoreToBeat = 0i64;
    this->mLBD = lbd;
    UFG::StatGame::UpdateShouldStart(this);
    return this;
  }
}

// File Line: 236
// RVA: 0x4C7E50
void __fastcall UFG::StatGame::UpdateScore(UFG::StatGame *this, int iScore)
{
  UFG::StatGamePropertyData *mStatGameProp; // rdx
  __int64 mScore; // r8
  int mDeltaTime; // eax

  mStatGameProp = this->mStatGameProp;
  if ( mStatGameProp )
  {
    mScore = (unsigned int)this->mScore;
    if ( (int)mScore > iScore )
      UFG::qPrintf(
        "====== YL:ASSERT:FixMe  somehow new score is lower than old score eh??? (%s, old:%d  new:%d)\n",
        mStatGameProp->m_pLBD->mCaption.mData,
        mScore,
        (unsigned int)iScore);
    mDeltaTime = this->mStatGameProp->m_pLBD->mDeltaTime;
    this->mScore = iScore;
    this->mDeltaTime = mDeltaTime;
    UFG::StatGame::UpdateShouldStart(this);
  }
}

// File Line: 267
// RVA: 0x4BC6E0
void __fastcall UFG::StatGame::SetFinalScore(UFG::StatGame *this)
{
  UFG::GameStatTracker *v2; // rdi
  UFG::GameStatTracker *v3; // rcx
  UFG::PersistentData::MapInt *v4; // rcx
  __int64 v5; // rdx
  UFG::PersistentData::KeyValue *p; // rax
  int mIntValue; // ecx
  int mScore; // esi
  UFG::OSuiteLeaderboardData *m_pLBD; // rbx
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rcx
  UFG::StatGamePropertyData *mStatGameProp; // rbx
  UFG::OSuiteLeaderboardManager *v13; // rax
  UFG::OSuiteLeaderboardData *v14; // rbx
  UFG::GameStatTracker *v15; // rax
  unsigned int v16; // ecx
  UFG::GameStatTracker *v17; // r8
  unsigned __int64 SystemTimeUTC; // rbx
  int v19; // esi
  int mLeaderboardId; // edi
  UFG::SocialLogDataManager *v21; // rax
  UFG::SocialLogData data; // [rsp+30h] [rbp-D8h] BYREF
  int v23; // [rsp+F0h] [rbp-18h]
  void *mem; // [rsp+F8h] [rbp-10h]

  UFG::DataSynchronizer::SendBeatChallengeMessageIfNeeded(this->mStatGameProp->m_pLBD, this->mScore, 0);
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
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
  p = v4->mValues.p;
  while ( p->mKey.mUID != this->mStatGameProp->m_pLBD->mLeaderboardName.mUID )
  {
    v5 = (unsigned int)(v5 + 1);
    ++p;
    if ( (unsigned int)v5 >= v4->mValues.size )
      goto LABEL_12;
  }
  if ( (_DWORD)v5 == -1 )
LABEL_12:
    mIntValue = 0;
  else
    mIntValue = v4->mValues.p[v5].mIntValue;
  mScore = this->mScore;
  if ( mIntValue < mScore )
  {
    m_pLBD = this->mStatGameProp->m_pLBD;
    v10 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v10 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapInt::SetStatus(v10->mpSnapshots[0]->mpMapInts[29], &m_pLBD->mLeaderboardName, mScore);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        if ( (_S12_6 & 1) == 0 )
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
    mStatGameProp = this->mStatGameProp;
    v13 = UFG::OSuiteLeaderboardManager::Instance();
    UFG::OSuiteLeaderboardManager::UploadStatGameResult(
      v13,
      (UFG::allocator::free_link *)mStatGameProp->m_pLBD,
      this->mScore,
      (UFG::allocator::free_link *)UFG::DataSynchronizer::UpdateLeaderboardCallback);
    v14 = this->mStatGameProp->m_pLBD;
    v15 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v15 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v15->mpSnapshots[0]->mpMapBools[79], &v14->mLeaderboardName, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v16 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
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
        if ( (v16 & 1) == 0 )
        {
          _S12_6 = v16 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v17 = UFG::GameStatTracker::mspInstance;
        }
        if ( v17 )
          v2 = v17;
        UFG::GameStatTracker::mspInstance = v2;
      }
    }
    SystemTimeUTC = UFG::qGetSystemTimeUTC();
    v19 = this->mScore;
    mLeaderboardId = this->mStatGameProp->m_pLBD->mLeaderboardId;
    UFG::SocialLogData::SocialLogData(&data);
    data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
    v23 = 0;
    mem = 0i64;
    data.m_iCommId = CommId_NewHighScore;
    data.m_iTimeStamp = (SystemTimeUTC - 116444736000000000i64) / 0x2710;
    data.m_iLeaderboardId = mLeaderboardId;
    data.m_iScore = v19;
    v21 = UFG::SocialLogDataManager::Instance();
    UFG::SocialLogDataManager::AddToSaveData(v21, &data);
    data.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
    if ( mem )
      operator delete[](mem);
    UFG::SocialLogData::~SocialLogData(&data);
  }
}

// File Line: 297
// RVA: 0x4BE950
void __fastcall UFG::StatGame::ShowFinalScore(UFG::StatGame *this)
{
  UFG::StatGamePropertyData *mStatGameProp; // r14
  UFG::CachedLeaderboard *mLeaderboard; // r8
  int v4; // edi
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *mNext; // rax
  int mScore; // ecx
  UFG::qSymbol *m_pLBD; // rbx
  UFG::GameStatTracker *v8; // rax
  unsigned int v9; // ecx
  UFG::GameStatTracker *v10; // rbx
  UFG::GameStatTracker *v11; // r8
  UFG::PersistentData::MapInt *v12; // rax
  unsigned int size; // r8d
  int v14; // edi
  unsigned int v15; // edx
  UFG::PersistentData::KeyValue *p; // r9
  UFG::PersistentData::KeyValue *v17; // rax
  int mIntValue; // ecx
  UFG::UIHKScreenHud *Instance; // rbp
  int PlayingIndex; // ebx
  UFG::qString str; // [rsp+38h] [rbp-40h] BYREF

  mStatGameProp = this->mStatGameProp;
  mLeaderboard = this->mLeaderboard;
  if ( mLeaderboard )
  {
    v4 = 1;
    mNext = mLeaderboard->m_lEntries.mNode.mNext;
    if ( mNext != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&mLeaderboard->m_lEntries )
    {
      mScore = this->mScore;
      do
      {
        if ( SLODWORD(mNext[1].mPrev) <= mScore )
          break;
        ++v4;
        mNext = mNext->mNext;
      }
      while ( mNext != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&mLeaderboard->m_lEntries );
    }
    m_pLBD = (UFG::qSymbol *)mLeaderboard->m_pPropertyData->m_pLBD;
    v8 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v8->mpSnapshots[0]->mpMapBools[55], m_pLBD + 12, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v9 = _S12_6;
        v10 = &sGameStatTracker;
        if ( (_S12_6 & 1) == 0 )
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
        if ( (v9 & 1) == 0 )
        {
          _S12_6 = v9 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v11 = UFG::GameStatTracker::mspInstance;
        }
        if ( v11 )
          v10 = v11;
        UFG::GameStatTracker::mspInstance = v10;
      }
    }
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      if ( v4 < 1 )
        return;
    }
    else
    {
      v12 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapInts[29];
      size = v12->mValues.size;
      v14 = 0;
      v15 = 0;
      if ( !v12->mValues.size )
        goto LABEL_25;
      p = v12->mValues.p;
      v17 = p;
      while ( v17->mKey.mUID != this->mLeaderboard->m_pPropertyData->m_pLBD->mLeaderboardName.mUID )
      {
        ++v15;
        ++v17;
        if ( v15 >= size )
          goto LABEL_25;
      }
      if ( v15 == -1 )
LABEL_25:
        mIntValue = 0;
      else
        mIntValue = p[v15].mIntValue;
      LOBYTE(v14) = this->mScore < mIntValue;
      v4 = v14 + 1;
    }
    Instance = UFG::UIHKScreenHud::getInstance();
    if ( Instance )
    {
      if ( mStatGameProp )
      {
        PlayingIndex = UFG::StatGameManager::GetPlayingIndex(UFG::StatGameManager::sInstance, this);
        UFG::qString::qString(&str);
        UFG::StatGamePropertyData::FormatScore(mStatGameProp, &str, (unsigned int)this->mScore);
        UFG::UIHKScreenHud::SetStatGameFinalScore(
          Instance,
          PlayingIndex,
          mStatGameProp->m_pLBD->mRankDesc.mData,
          v4,
          str.mData);
        UFG::qString::~qString(&str);
      }
    }
  }
}

// File Line: 333
// RVA: 0x4B3800
void __fastcall UFG::StatGame::PushToHud(UFG::StatGame *this)
{
  UFG::CachedLeaderboard *mLeaderboard; // rax
  int v3; // esi
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *mNext; // rdx
  UFG::qList<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry,1,0> *p_m_lEntries; // rax
  int mScore; // ecx
  char *PlayerDisplayName; // r10
  UFG::GameStatTracker *v8; // rbx
  UFG::PersistentData::MapInt *v9; // rcx
  __int64 v10; // rdx
  UFG::PersistentData::KeyValue *p; // rax
  int mIntValue; // edi
  UFG::CachedLeaderboard::Entry *mCurrentScoreToBeat; // r13
  UFG::qList<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry,1,0> *v14; // rax
  UFG::CachedLeaderboard::Entry *mPrev; // rbx
  const char *leader; // r12
  UFG::UIHKScreenHud *Instance; // r15
  UFG::StatGamePropertyData *mStatGameProp; // r14
  UFG::qString leaderscore; // [rsp+38h] [rbp-D0h] BYREF
  UFG::qString v20; // [rsp+60h] [rbp-A8h] BYREF
  UFG::qString v21; // [rsp+88h] [rbp-80h] BYREF
  UFG::qString str; // [rsp+B0h] [rbp-58h] BYREF
  char *myname; // [rsp+110h] [rbp+8h]

  mLeaderboard = this->mLeaderboard;
  v3 = 1;
  mNext = mLeaderboard->m_lEntries.mNode.mNext;
  p_m_lEntries = &mLeaderboard->m_lEntries;
  if ( mNext != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)p_m_lEntries )
  {
    mScore = this->mScore;
    do
    {
      if ( SLODWORD(mNext[1].mPrev) <= mScore )
        break;
      ++v3;
      mNext = mNext->mNext;
    }
    while ( mNext != (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)p_m_lEntries );
  }
  PlayerDisplayName = UFG::UI::GetPlayerDisplayName();
  myname = PlayerDisplayName;
  v8 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    PlayerDisplayName = myname;
  }
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  v9 = v8->mpSnapshots[0]->mpMapInts[29];
  v10 = 0i64;
  if ( !v9->mValues.size )
    goto LABEL_16;
  p = v9->mValues.p;
  while ( p->mKey.mUID != this->mLeaderboard->m_pPropertyData->m_pLBD->mLeaderboardName.mUID )
  {
    v10 = (unsigned int)(v10 + 1);
    ++p;
    if ( (unsigned int)v10 >= v9->mValues.size )
      goto LABEL_16;
  }
  if ( (_DWORD)v10 == -1 )
LABEL_16:
    mIntValue = 0;
  else
    mIntValue = v9->mValues.p[v10].mIntValue;
  if ( this->mScore > mIntValue )
    mIntValue = this->mScore;
  mCurrentScoreToBeat = this->mCurrentScoreToBeat;
  v14 = &this->mLeaderboard->m_lEntries;
  mPrev = (UFG::CachedLeaderboard::Entry *)v14->mNode.mPrev;
  if ( (UFG::qList<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry,1,0> *)v14->mNode.mPrev == v14 )
  {
LABEL_25:
    mPrev = 0i64;
LABEL_26:
    leader = PlayerDisplayName;
    goto LABEL_27;
  }
  while ( mPrev->m_iRating <= mIntValue )
  {
    mPrev = (UFG::CachedLeaderboard::Entry *)mPrev->mPrev;
    if ( mPrev == (UFG::CachedLeaderboard::Entry *)v14 )
      goto LABEL_25;
  }
  if ( !mPrev )
    goto LABEL_26;
  leader = mPrev->m_sUsername;
  mIntValue = mPrev->m_iRating;
LABEL_27:
  Instance = UFG::UIHKScreenHud::getInstance();
  mStatGameProp = this->mStatGameProp;
  if ( Instance && mStatGameProp )
  {
    UFG::qString::qString(&str);
    UFG::qString::qString(&leaderscore);
    UFG::StatGamePropertyData::FormatScore(mStatGameProp, &str, (unsigned int)this->mScore);
    if ( mCurrentScoreToBeat != mPrev )
    {
      if ( mCurrentScoreToBeat && mCurrentScoreToBeat->m_iRating < this->mScore )
      {
        UFG::qString::qString(&v21);
        UFG::qString::qString(&v20);
        UFG::StatGamePropertyData::FormatScore(mStatGameProp, &v21, (unsigned int)mCurrentScoreToBeat->m_iRating);
        UFG::qString::Format(&v20, "%d: %s", mCurrentScoreToBeat->m_uRank, mCurrentScoreToBeat->m_sUsername);
        UFG::UIHKScreenHud::SetStatGameBeatHim(Instance, v20.mData, v21.mData);
        UFG::qString::~qString(&v20);
        UFG::qString::~qString(&v21);
      }
      this->mCurrentScoreToBeat = mPrev;
    }
    if ( mIntValue )
      UFG::StatGamePropertyData::FormatScore(mStatGameProp, &leaderscore, (unsigned int)mIntValue);
    else
      UFG::qString::Set(&leaderscore, &customCaption);
    UFG::UIHKScreenHud::SetStatGameInfo(
      Instance,
      mStatGameProp->m_pLBD->mCaption.mData,
      myname,
      str.mData,
      leader,
      leaderscore.mData);
    if ( v3 == 1 )
      UFG::UIHKScreenHud::SetStatMakingNewRecord(Instance);
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
    v1 = UFG::StatGameManager::sInstance->mQueue[0].mPlayingIndex >= 0;
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
  UFG::StatGame *v7; // r10
  UFG::OSuiteLeaderboardData **p_mLBD; // rax
  int v9; // edx
  __int64 v10; // rcx

  v3 = UFG::StatGameManager::sInstance;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1
     || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID
     && (UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID != gDefaultFlowId.mUID
      || lbd->mFlow.mUID != gDefaultFlowId.mUID
      || v3->mDefaultFlowGamesAreEnabled)) )
  {
    v7 = 0i64;
    p_mLBD = &v3->mQueue[0].mLBD;
    v9 = 0;
    v10 = 0i64;
    while ( *p_mLBD != lbd )
    {
      ++v10;
      ++v9;
      p_mLBD += 6;
      if ( v10 >= 5 )
        goto LABEL_14;
    }
    v7 = &v3->mQueue[v9];
    if ( v7 )
    {
      if ( bDelta )
      {
        v7->mScore += point;
        point = v7->mScore;
      }
    }
LABEL_14:
    UFG::StatGameManager::UpdateScoreWithStatGame(v3, v7, lbd, point);
  }
}

// File Line: 491
// RVA: 0x4C7F90
void __fastcall UFG::StatGameManager::UpdateScore(UFG::OSuiteLeaderboardData *lbd, float point, bool bDelta)
{
  UFG::StatGameManager *v3; // rdi
  UFG::StatGame *v6; // r10
  UFG::OSuiteLeaderboardData **p_mLBD; // rax
  int v8; // edx
  __int64 v9; // rcx
  int mScore; // r9d

  v3 = UFG::StatGameManager::sInstance;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1
     || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID
     && (UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID != gDefaultFlowId.mUID
      || lbd->mFlow.mUID != gDefaultFlowId.mUID
      || v3->mDefaultFlowGamesAreEnabled)) )
  {
    v6 = 0i64;
    p_mLBD = &v3->mQueue[0].mLBD;
    v8 = 0;
    v9 = 0i64;
    while ( *p_mLBD != lbd )
    {
      ++v9;
      ++v8;
      p_mLBD += 6;
      if ( v9 >= 5 )
        goto LABEL_12;
    }
    v6 = &v3->mQueue[v8];
LABEL_12:
    mScore = (int)(float)(point * 1000.0);
    if ( v6 )
    {
      if ( bDelta )
      {
        v6->mScore += mScore;
        mScore = v6->mScore;
      }
    }
    UFG::StatGameManager::UpdateScoreWithStatGame(v3, v6, lbd, mScore);
  }
}

// File Line: 526
// RVA: 0x4C8090
void __fastcall UFG::StatGameManager::UpdateScoreWithStatGame(
        UFG::StatGameManager *this,
        UFG::StatGame *pSG,
        UFG::OSuiteLeaderboardData *lbd,
        unsigned int score)
{
  int v4; // edi
  UFG::StatGame *Request; // rbx
  UFG::StatGamePropertyData *mStatGameProp; // rdx
  __int64 mScore; // r8
  int mDeltaTime; // eax
  int v11; // edx
  __int64 v12; // rcx
  UFG::StatGamePropertyData **p_mStatGameProp; // rax
  int v14; // edx
  UFG::StatGame *mQueue; // r8
  __int64 v16; // rcx

  v4 = 0;
  Request = pSG;
  if ( pSG )
  {
    mStatGameProp = pSG->mStatGameProp;
    if ( mStatGameProp )
    {
      mScore = (unsigned int)Request->mScore;
      if ( (int)mScore > (int)score )
        UFG::qPrintf(
          "====== YL:ASSERT:FixMe  somehow new score is lower than old score eh??? (%s, old:%d  new:%d)\n",
          mStatGameProp->m_pLBD->mCaption.mData,
          mScore,
          score);
      mDeltaTime = Request->mStatGameProp->m_pLBD->mDeltaTime;
      Request->mScore = score;
      Request->mDeltaTime = mDeltaTime;
      UFG::StatGame::UpdateShouldStart(Request);
    }
LABEL_12:
    if ( Request->mPlayingIndex >= 0 )
    {
      v14 = 0;
      mQueue = this->mQueue;
      do
      {
        if ( &this->mQueue[v14] == Request )
          break;
        if ( mQueue->mPlayingIndex >= 0 )
          ++v4;
        ++v14;
        ++mQueue;
      }
      while ( v14 < 5 );
      if ( !v4 )
        UFG::StatGame::PushToHud(Request);
    }
    return;
  }
  v11 = 0;
  v12 = 0i64;
  p_mStatGameProp = &this->mQueue[0].mStatGameProp;
  while ( *p_mStatGameProp )
  {
    ++v12;
    ++v11;
    p_mStatGameProp += 6;
    if ( v12 >= 5 )
    {
      Request = 0i64;
LABEL_10:
      UFG::qPrintf(
        "StatGameAddRequest Error Queue full (discarding request id:%s(%d))\n",
        lbd->mLeaderboardNameStr.mData,
        score);
      goto LABEL_11;
    }
  }
  v16 = v11;
  Request = &this->mQueue[v16];
  if ( !Request )
    goto LABEL_10;
  Request = UFG::StatGame::FirstRequest(&this->mQueue[v16], lbd, score);
LABEL_11:
  if ( Request )
    goto LABEL_12;
}

// File Line: 543
// RVA: 0x49DF60
void __fastcall UFG::StatGameManager::EndStatGame(UFG::OSuiteLeaderboardData *lbd)
{
  UFG::StatGameManager *v1; // rbx
  UFG::OSuiteLeaderboardData **p_mLBD; // rax
  int v4; // edx
  __int64 v5; // rcx
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **p_mNext; // rax
  __int64 i; // rcx
  UFG::StatGame *v8; // rbx

  v1 = UFG::StatGameManager::sInstance;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1 || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID) )
  {
    p_mLBD = &v1->mQueue[0].mLBD;
    v4 = 0;
    v5 = 0i64;
    while ( *p_mLBD != lbd )
    {
      ++v5;
      ++v4;
      p_mLBD += 6;
      if ( v5 >= 5 )
        goto LABEL_7;
    }
    v8 = &v1->mQueue[v4];
    if ( !v8 )
    {
LABEL_7:
      p_mNext = &UFG::StatGamePropertyManager::Instance()[-1].m_lProperties.mNode.mNext;
      for ( i = (__int64)&p_mNext[2][-1].mNext;
            (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)i != p_mNext;
            i = *(_QWORD *)(i + 16) - 8i64 )
      {
        if ( *(UFG::OSuiteLeaderboardData **)(i + 24) == lbd )
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
  UFG::OSuiteLeaderboardData **p_mLBD; // rax
  int v6; // edx
  __int64 v7; // rcx
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **p_mNext; // rax
  __int64 i; // rcx
  UFG::StatGame *v10; // rbx

  v2 = UFG::StatGameManager::sInstance;
  if ( UFG::StatGameManager::sInstance
    && (lbd->mFlow.mUID == -1 || lbd->mFlow.mUID == UFG::ProgressionTracker::Instance()->mActiveFlowId.mUID) )
  {
    p_mLBD = &v2->mQueue[0].mLBD;
    v6 = 0;
    v7 = 0i64;
    while ( *p_mLBD != lbd )
    {
      ++v7;
      ++v6;
      p_mLBD += 6;
      if ( v7 >= 5 )
        goto LABEL_7;
    }
    v10 = &v2->mQueue[v6];
    if ( !v10 )
    {
LABEL_7:
      p_mNext = &UFG::StatGamePropertyManager::Instance()[-1].m_lProperties.mNode.mNext;
      for ( i = (__int64)&p_mNext[2][-1].mNext;
            (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> **)i != p_mNext;
            i = *(_QWORD *)(i + 16) - 8i64 )
      {
        if ( *(UFG::OSuiteLeaderboardData **)(i + 24) == lbd )
          break;
      }
      return;
    }
    if ( v10->mPlayingIndex >= 0 )
    {
      UFG::StatGame::UpdateScore(v10, points);
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
  __int64 v2; // rsi
  int v4; // ebp
  int *p_mDeltaTime; // rbx
  __int64 v6; // rax
  int v7; // eax

  v2 = 5i64;
  v4 = LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(this->mPrevTime);
  p_mDeltaTime = &this->mQueue[0].mDeltaTime;
  do
  {
    v6 = *(_QWORD *)(p_mDeltaTime - 3);
    if ( v6 )
    {
      *p_mDeltaTime -= v4;
      if ( *p_mDeltaTime > 0 )
      {
        if ( *(p_mDeltaTime - 9) < 0 && *(p_mDeltaTime - 1) >= *(_DWORD *)(*(_QWORD *)(v6 + 24) + 260i64) )
        {
          v7 = UFG::StatGameManager::sInstance->mQueue[0].mPlayingIndex >= 0;
          if ( UFG::StatGameManager::sInstance->mQueue[1].mPlayingIndex >= 0 )
            ++v7;
          if ( UFG::StatGameManager::sInstance->mQueue[2].mPlayingIndex >= 0 )
            ++v7;
          if ( UFG::StatGameManager::sInstance->mQueue[3].mPlayingIndex >= 0 )
            ++v7;
          if ( UFG::StatGameManager::sInstance->mQueue[4].mPlayingIndex >= 0 )
            ++v7;
          if ( v7 < 1 )
            *(p_mDeltaTime - 9) = v7;
        }
      }
      else
      {
        if ( *(p_mDeltaTime - 9) >= 0 )
        {
          UFG::StatGame::SetFinalScore((UFG::StatGame *)(p_mDeltaTime - 9));
          UFG::StatGame::ShowFinalScore((UFG::StatGame *)(p_mDeltaTime - 9));
        }
        *(_QWORD *)(p_mDeltaTime - 3) = 0i64;
        *(p_mDeltaTime - 1) = 0;
        *(_QWORD *)(p_mDeltaTime - 7) = 0i64;
        *(_QWORD *)(p_mDeltaTime - 5) = 0i64;
        *(p_mDeltaTime - 9) = -1;
        *(_QWORD *)(p_mDeltaTime + 1) = 0i64;
      }
    }
    p_mDeltaTime += 12;
    --v2;
  }
  while ( v2 );
  this->mPrevTime = UFG::Metrics::msInstance.mSimTimeMSec;
}

// File Line: 631
// RVA: 0x4A0A60
void __fastcall UFG::StatGameManager::FinishCurrentStats(UFG::StatGameManager *this)
{
  int *p_mScore; // rbx
  __int64 v2; // rsi

  p_mScore = &this->mQueue[0].mScore;
  v2 = 5i64;
  do
  {
    if ( *(p_mScore - 8) >= 0 && *(_DWORD *)(*((_QWORD *)p_mScore + 1) + 304i64) == gDefaultFlowId.mUID )
    {
      UFG::StatGame::SetFinalScore((UFG::StatGame *)(p_mScore - 8));
      UFG::StatGame::ShowFinalScore((UFG::StatGame *)(p_mScore - 8));
      *((_QWORD *)p_mScore - 1) = 0i64;
      *p_mScore = 0;
      *((_QWORD *)p_mScore - 3) = 0i64;
      *((_QWORD *)p_mScore - 2) = 0i64;
      *(p_mScore - 8) = -1;
      *((_QWORD *)p_mScore + 1) = 0i64;
    }
    p_mScore += 12;
    --v2;
  }
  while ( v2 );
}

// File Line: 652
// RVA: 0x4A5EC0
__int64 __fastcall UFG::StatGameManager::GetPlayingIndex(UFG::StatGameManager *this, UFG::StatGame *me)
{
  unsigned int v2; // r11d
  UFG::StatGame *mQueue; // r10
  int i; // r8d

  v2 = 0;
  mQueue = this->mQueue;
  for ( i = 0; i < 5; ++i )
  {
    if ( &this->mQueue[i] == me )
      break;
    if ( mQueue->mPlayingIndex >= 0 )
      ++v2;
    ++mQueue;
  }
  return v2;
}

