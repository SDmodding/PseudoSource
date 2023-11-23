// File Line: 54
// RVA: 0xA36A20
void __fastcall UFG::AchievementTrophyManager::OnUserStatsReceived(
        UFG::AchievementTrophyManager *this,
        UserStatsReceived_t *param)
{
  __int64 v4; // rax
  int v5; // ebx
  bool *v6; // rdi
  __int64 v7; // rdx
  __int64 v8; // rcx
  ISteamUserStats *v9; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF
  bool v11; // [rsp+68h] [rbp+10h] BYREF

  v4 = SteamUtils(this);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v4 + 72i64))(v4) == param->m_nGameID
    && param->m_eResult == k_EResultOK )
  {
    v5 = 1;
    if ( this->mLastUnlockableTrophyID >= 1 )
    {
      v6 = &this->mTrophyUnlockedFlag[1];
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
      while ( v5 <= this->mLastUnlockableTrophyID );
    }
    g_bInitialized = 1;
  }
}

// File Line: 77
// RVA: 0xA36AE0
void __fastcall UFG::AchievementTrophyManager::OnUserStatsStored(
        UFG::AchievementTrophyManager *this,
        UserStatsStored_t *param)
{
  __int64 v4; // rax
  __int64 v5; // rcx
  __int64 v6; // rax
  UserStatsReceived_t parama; // [rsp+20h] [rbp-28h] BYREF

  v4 = SteamUtils(this);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v4 + 72i64))(v4) == param->m_nGameID
    && param->m_eResult == k_EResultInvalidParam )
  {
    *((_DWORD *)&parama.m_steamIDUser.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
    HIBYTE(parama.m_steamIDUser.m_steamid.m_unAll64Bits) = 0;
    *((_DWORD *)&parama.m_steamIDUser.m_steamid.m_comp + 1) &= 0xFFF00000;
    *(_QWORD *)&parama.m_eResult = 1i64;
    v6 = SteamUtils(v5);
    parama.m_nGameID = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 72i64))(v6);
    UFG::AchievementTrophyManager::OnUserStatsReceived(this, &parama);
  }
}

// File Line: 98
// RVA: 0xA36A00
void __fastcall UFG::AchievementTrophyManager::OnAchievementStored(
        UFG::AchievementTrophyManager *this,
        UserAchievementStored_t *param)
{
  __int64 v2; // rax

  v2 = SteamUtils(this);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 72i64))(v2);
}

// File Line: 109
// RVA: 0xA36960
void __fastcall UFG::AchievementTrophyManager::Init(int lastUnlockableTrophyID)
{
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

  if ( !UFG::AchievementTrophyManager::mInstance )
  {
    v2 = (UFG::AchievementTrophyManager *)UFG::qMalloc(0x170ui64, "AchievementTrophyManager", 0i64);
    if ( v2 )
      UFG::AchievementTrophyManager::AchievementTrophyManager(v2);
    UFG::AchievementTrophyManager::mInstance = v2;
    v2->mLastUnlockableTrophyID = lastUnlockableTrophyID;
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
  UFG::AchievementTrophyManagerBase::AchievementTrophyManagerBase(this);
  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManager::`vftable;
  this->mUserStatsReceivedCB.m_nCallbackFlags = 0;
  this->mUserStatsReceivedCB.m_iCallback = 0;
  this->mUserStatsReceivedCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsReceived_t,0>::`vftable;
  this->mUserStatsReceivedCB.m_pObj = 0i64;
  this->mUserStatsReceivedCB.m_Func = 0i64;
  this->mUserStatsReceivedCB.vfptr = (CCallbackBaseVtbl *)&CCallbackManual<UFG::AchievementTrophyManager,UserStatsReceived_t,0>::`vftable;
  this->mUserStatsStoredCB.m_nCallbackFlags = 0;
  this->mUserStatsStoredCB.m_iCallback = 0;
  this->mUserStatsStoredCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable;
  this->mUserStatsStoredCB.m_pObj = 0i64;
  this->mUserStatsStoredCB.m_Func = 0i64;
  this->mUserStatsStoredCB.vfptr = (CCallbackBaseVtbl *)&CCallbackManual<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable;
  this->mAchievementStoredCB.m_nCallbackFlags = 0;
  this->mAchievementStoredCB.m_iCallback = 0;
  this->mAchievementStoredCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserAchievementStored_t,0>::`vftable;
  this->mAchievementStoredCB.m_pObj = 0i64;
  this->mAchievementStoredCB.m_Func = 0i64;
  this->mAchievementStoredCB.vfptr = (CCallbackBaseVtbl *)&CCallbackManual<UFG::AchievementTrophyManager,UserAchievementStored_t,0>::`vftable;
  if ( UFG::AchievementTrophyManager::OnUserStatsReceived )
  {
    if ( (this->mUserStatsReceivedCB.m_nCallbackFlags & 1) != 0 )
      SteamAPI_UnregisterCallback(&this->mUserStatsReceivedCB);
    this->mUserStatsReceivedCB.m_pObj = this;
    this->mUserStatsReceivedCB.m_Func = UFG::AchievementTrophyManager::OnUserStatsReceived;
    SteamAPI_RegisterCallback(&this->mUserStatsReceivedCB, 1101i64);
  }
  if ( UFG::AchievementTrophyManager::OnUserStatsStored )
  {
    if ( (this->mUserStatsStoredCB.m_nCallbackFlags & 1) != 0 )
      SteamAPI_UnregisterCallback(&this->mUserStatsStoredCB);
    this->mUserStatsStoredCB.m_pObj = this;
    this->mUserStatsStoredCB.m_Func = UFG::AchievementTrophyManager::OnUserStatsStored;
    SteamAPI_RegisterCallback(&this->mUserStatsStoredCB, 1102i64);
  }
  if ( UFG::AchievementTrophyManager::OnAchievementStored )
  {
    if ( (this->mAchievementStoredCB.m_nCallbackFlags & 1) != 0 )
      SteamAPI_UnregisterCallback(&this->mAchievementStoredCB);
    this->mAchievementStoredCB.m_pObj = this;
    this->mAchievementStoredCB.m_Func = UFG::AchievementTrophyManager::OnAchievementStored;
    SteamAPI_RegisterCallback(&this->mAchievementStoredCB, 1103i64);
  }
}

// File Line: 155
// RVA: 0xA36880
void __fastcall UFG::AchievementTrophyManager::~AchievementTrophyManager(UFG::AchievementTrophyManager *this)
{
  CCallbackManual<UFG::AchievementTrophyManager,UserAchievementStored_t,0> *p_mAchievementStoredCB; // rcx

  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManager::`vftable;
  p_mAchievementStoredCB = &this->mAchievementStoredCB;
  p_mAchievementStoredCB->vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserAchievementStored_t,0>::`vftable;
  if ( (p_mAchievementStoredCB->m_nCallbackFlags & 1) != 0 )
    SteamAPI_UnregisterCallback(p_mAchievementStoredCB);
  this->mUserStatsStoredCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable;
  if ( (this->mUserStatsStoredCB.m_nCallbackFlags & 1) != 0 )
    SteamAPI_UnregisterCallback(&this->mUserStatsStoredCB);
  this->mUserStatsReceivedCB.vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsReceived_t,0>::`vftable;
  if ( (this->mUserStatsReceivedCB.m_nCallbackFlags & 1) != 0 )
    SteamAPI_UnregisterCallback(&this->mUserStatsReceivedCB);
  UFG::AchievementTrophyManagerBase::~AchievementTrophyManagerBase(this);
}

// File Line: 159
// RVA: 0xA36B70
char __fastcall UFG::AchievementTrophyManager::UnlockAchievementTrophy(int type)
{
  if ( g_bInitialized && UFG::AchievementTrophyManager::mInstance )
    return UFG::AchievementTrophyManagerBase::UnlockTrophyBase(UFG::AchievementTrophyManager::mInstance, type);
  else
    return 0;
}

// File Line: 175
// RVA: 0xA36B90
bool __fastcall UFG::AchievementTrophyManager::UnlockTrophyInternal(
        UFG::AchievementTrophyManager *this,
        unsigned int trophyId)
{
  __int64 v3; // rdx
  __int64 v4; // rcx
  ISteamUserStats *v5; // rax
  __int64 v6; // rdx
  __int64 v7; // rcx
  ISteamUserStats *v8; // rax
  bool v9; // bl
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  if ( !g_bInitialized )
    return 0;
  UFG::qString::FormatEx(&v10, ACHIEVEMENT_NAME_FORMAT, trophyId);
  v5 = (ISteamUserStats *)SteamUserStats(v4, v3);
  v5->vfptr->SetAchievement(v5, v10.mData);
  v8 = (ISteamUserStats *)SteamUserStats(v7, v6);
  v9 = v8->vfptr->StoreStats(v8);
  UFG::qString::~qString(&v10);
  return v9;
}

