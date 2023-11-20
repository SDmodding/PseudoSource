// File Line: 54
// RVA: 0xA36A20
void __fastcall UFG::AchievementTrophyManager::OnUserStatsReceived(UFG::AchievementTrophyManager *this, UserStatsReceived_t *param)
{
  UserStatsReceived_t *v2; // rbx
  UFG::AchievementTrophyManager *v3; // rsi
  __int64 v4; // rax
  signed int v5; // ebx
  bool *v6; // rdi
  __int64 v7; // rdx
  __int64 v8; // rcx
  ISteamUserStats *v9; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]
  bool v11; // [rsp+68h] [rbp+10h]

  v2 = param;
  v3 = this;
  v4 = SteamUtils(this);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v4 + 72i64))(v4) == v2->m_nGameID && v2->m_eResult == 1 )
  {
    v5 = 1;
    if ( v3->mLastUnlockableTrophyID >= 1 )
    {
      v6 = &v3->mTrophyUnlockedFlag[1];
      do
      {
        v11 = 0;
        UFG::qString::FormatEx(&result, ACHIEVEMENT_NAME_FORMAT, (unsigned int)v5);
        v9 = (ISteamUserStats *)SteamUserStats(v8, v7);
        v9->vfptr->GetAchievement(v9, result.mData, &v11);
        *v6 = v11;
        UFG::qString::~qString(&result);
        ++v5;
        ++v6;
      }
      while ( v5 <= v3->mLastUnlockableTrophyID );
    }
    g_bInitialized = 1;
  }
}

// File Line: 77
// RVA: 0xA36AE0
void __fastcall UFG::AchievementTrophyManager::OnUserStatsStored(UFG::AchievementTrophyManager *this, UserStatsStored_t *param)
{
  UserStatsStored_t *v2; // rbx
  UFG::AchievementTrophyManager *v3; // rdi
  __int64 v4; // rax
  __int64 v5; // rcx
  __int64 v6; // rax
  UserStatsReceived_t parama; // [rsp+20h] [rbp-28h]

  v2 = param;
  v3 = this;
  v4 = SteamUtils(this);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v4 + 72i64))(v4) == v2->m_nGameID && v2->m_eResult == 8 )
  {
    *((_DWORD *)&parama.m_steamIDUser.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
    HIBYTE(parama.m_steamIDUser.m_steamid.m_unAll64Bits) = 0;
    *((_DWORD *)&parama.m_steamIDUser.m_steamid.m_comp + 1) &= 0xFFF00000;
    *(_QWORD *)&parama.m_eResult = 1i64;
    v6 = SteamUtils(v5);
    parama.m_nGameID = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 72i64))(v6);
    UFG::AchievementTrophyManager::OnUserStatsReceived(v3, &parama);
  }
}

// File Line: 98
// RVA: 0xA36A00
void __fastcall UFG::AchievementTrophyManager::OnAchievementStored(UFG::AchievementTrophyManager *this, UserAchievementStored_t *param)
{
  __int64 v2; // rax

  v2 = SteamUtils(this);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 72i64))(v2);
}

// File Line: 109
// RVA: 0xA36960
void __fastcall UFG::AchievementTrophyManager::Init(int lastUnlockableTrophyID)
{
  int v1; // ebx
  UFG::AchievementTrophyManager *v2; // rax
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // rcx
  __int64 v7; // rdx
  __int64 v8; // rcx
  ISteamUser *v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  void (__fastcall ***v12)(_QWORD); // rax

  v1 = lastUnlockableTrophyID;
  if ( !UFG::AchievementTrophyManager::mInstance )
  {
    v2 = (UFG::AchievementTrophyManager *)UFG::qMalloc(0x170ui64, "AchievementTrophyManager", 0i64);
    if ( v2 )
      UFG::AchievementTrophyManager::AchievementTrophyManager(v2);
    UFG::AchievementTrophyManager::mInstance = v2;
    v2->mLastUnlockableTrophyID = v1;
    if ( SteamUserStats(v4, v3) && SteamUser(v6, v5) )
    {
      v9 = (ISteamUser *)SteamUser(v8, v7);
      if ( (*(unsigned __int8 (__fastcall **)(ISteamUser *))v9->vfptr->gap8)(v9) )
      {
        v12 = (void (__fastcall ***)(_QWORD))SteamUserStats(v11, v10);
        (**v12)(v12);
      }
    }
  }
}

// File Line: 148
// RVA: 0xA365F0
void __fastcall UFG::AchievementTrophyManager::AchievementTrophyManager(UFG::AchievementTrophyManager *this)
{
  UFG::AchievementTrophyManager *v1; // r14
  signed __int64 v2; // rsi
  signed __int64 v3; // rdi
  signed __int64 v4; // [rsp+58h] [rbp+10h]

  v1 = this;
  UFG::AchievementTrophyManagerBase::AchievementTrophyManagerBase((UFG::AchievementTrophyManagerBase *)&this->vfptr);
  v1->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManager::`vftable';
  v2 = (signed __int64)&v1->mUserStatsReceivedCB;
  *(_BYTE *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_QWORD *)v2 = &CCallback<UFG::AchievementTrophyManager,UserStatsReceived_t,0>::`vftable';
  *(_QWORD *)(v2 + 16) = 0i64;
  *(_QWORD *)(v2 + 24) = 0i64;
  *(_QWORD *)v2 = &CCallbackManual<UFG::AchievementTrophyManager,UserStatsReceived_t,0>::`vftable';
  v3 = (signed __int64)&v1->mUserStatsStoredCB;
  *(_BYTE *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_QWORD *)v3 = &CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable';
  *(_QWORD *)(v3 + 16) = 0i64;
  *(_QWORD *)(v3 + 24) = 0i64;
  *(_QWORD *)v3 = &CCallbackManual<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable';
  v4 = (signed __int64)&v1->mAchievementStoredCB;
  *(_BYTE *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_QWORD *)v4 = &CCallback<UFG::AchievementTrophyManager,UserAchievementStored_t,0>::`vftable';
  *(_QWORD *)(v4 + 16) = 0i64;
  *(_QWORD *)(v4 + 24) = 0i64;
  *(_QWORD *)v4 = &CCallbackManual<UFG::AchievementTrophyManager,UserAchievementStored_t,0>::`vftable';
  if ( UFG::AchievementTrophyManager::OnUserStatsReceived )
  {
    if ( v1->mUserStatsReceivedCB.m_nCallbackFlags & 1 )
      SteamAPI_UnregisterCallback(&v1->mUserStatsReceivedCB);
    v1->mUserStatsReceivedCB.m_pObj = v1;
    v1->mUserStatsReceivedCB.m_Func = UFG::AchievementTrophyManager::OnUserStatsReceived;
    SteamAPI_RegisterCallback(&v1->mUserStatsReceivedCB, 1101i64);
  }
  if ( UFG::AchievementTrophyManager::OnUserStatsStored )
  {
    if ( v1->mUserStatsStoredCB.m_nCallbackFlags & 1 )
      SteamAPI_UnregisterCallback(&v1->mUserStatsStoredCB);
    v1->mUserStatsStoredCB.m_pObj = v1;
    v1->mUserStatsStoredCB.m_Func = UFG::AchievementTrophyManager::OnUserStatsStored;
    SteamAPI_RegisterCallback(&v1->mUserStatsStoredCB, 1102i64);
  }
  if ( UFG::AchievementTrophyManager::OnAchievementStored )
  {
    if ( v1->mAchievementStoredCB.m_nCallbackFlags & 1 )
      SteamAPI_UnregisterCallback(&v1->mAchievementStoredCB);
    v1->mAchievementStoredCB.m_pObj = v1;
    v1->mAchievementStoredCB.m_Func = UFG::AchievementTrophyManager::OnAchievementStored;
    SteamAPI_RegisterCallback(&v1->mAchievementStoredCB, 1103i64);
  }
}

// File Line: 155
// RVA: 0xA36880
void __fastcall UFG::AchievementTrophyManager::~AchievementTrophyManager(UFG::AchievementTrophyManager *this)
{
  UFG::AchievementTrophyManager *v1; // rbx
  CCallbackManual<UFG::AchievementTrophyManager,UserAchievementStored_t,0> *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManager::`vftable';
  v2 = &this->mAchievementStoredCB;
  v2->vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserAchievementStored_t,0>::`vftable';
  if ( v2->m_nCallbackFlags & 1 )
    SteamAPI_UnregisterCallback(v2);
  v1->mUserStatsStoredCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable';
  if ( v1->mUserStatsStoredCB.m_nCallbackFlags & 1 )
    SteamAPI_UnregisterCallback(&v1->mUserStatsStoredCB);
  v1->mUserStatsReceivedCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsReceived_t,0>::`vftable';
  if ( v1->mUserStatsReceivedCB.m_nCallbackFlags & 1 )
    SteamAPI_UnregisterCallback(&v1->mUserStatsReceivedCB);
  UFG::AchievementTrophyManagerBase::~AchievementTrophyManagerBase((UFG::AchievementTrophyManagerBase *)&v1->vfptr);
}

// File Line: 159
// RVA: 0xA36B70
bool __fastcall UFG::AchievementTrophyManager::UnlockAchievementTrophy(int type)
{
  if ( g_bInitialized )
    JUMPOUT(UFG::AchievementTrophyManager::mInstance, 0i64, UFG::AchievementTrophyManagerBase::UnlockTrophyBase);
  return 0;
}

// File Line: 175
// RVA: 0xA36B90
bool __fastcall UFG::AchievementTrophyManager::UnlockTrophyInternal(UFG::AchievementTrophyManager *this, int trophyId)
{
  __int64 v3; // rdx
  __int64 v4; // rcx
  ISteamUserStats *v5; // rax
  __int64 v6; // rdx
  __int64 v7; // rcx
  ISteamUserStats *v8; // rax
  bool v9; // bl
  UFG::qString result; // [rsp+28h] [rbp-30h]

  if ( !g_bInitialized )
    return 0;
  UFG::qString::FormatEx(&result, ACHIEVEMENT_NAME_FORMAT, (unsigned int)trophyId);
  v5 = (ISteamUserStats *)SteamUserStats(v4, v3);
  v5->vfptr->SetAchievement(v5, result.mData);
  v8 = (ISteamUserStats *)SteamUserStats(v7, v6);
  v9 = v8->vfptr->StoreStats(v8) != 0;
  UFG::qString::~qString(&result);
  return v9;
}

