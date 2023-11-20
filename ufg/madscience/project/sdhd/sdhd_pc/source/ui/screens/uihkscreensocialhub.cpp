// File Line: 122
// RVA: 0x1566DA0
__int64 dynamic_initializer_for__UFG::UIHKScreenSocialHub::gLeaderboardEntries__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenSocialHub::gLeaderboardEntries__);
}

// File Line: 137
// RVA: 0x156AA50
__int64 UFG::_dynamic_initializer_for__UI_HASH_CHALLENGE_BUTTON_ACCEPTED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CHALLENGE_BUTTON_ACCEPTED", 0xFFFFFFFF);
  UI_HASH_CHALLENGE_BUTTON_ACCEPTED = result;
  return result;
}

// File Line: 138
// RVA: 0x156AA70
__int64 UFG::_dynamic_initializer_for__UI_HASH_CHALLENGE_BUTTON_CANCELED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CHALLENGE_BUTTON_CANCELED", 0xFFFFFFFF);
  UI_HASH_CHALLENGE_BUTTON_CANCELED = result;
  return result;
}

// File Line: 139
// RVA: 0x156D670
__int64 UFG::_dynamic_initializer_for__UI_HASH_TAB_ANIM_COMPLETE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("TAB_ANIM_COMPLETE", 0xFFFFFFFF);
  UI_HASH_TAB_ANIM_COMPLETE = result;
  return result;
}

// File Line: 140
// RVA: 0x156DA10
__int64 UFG::_dynamic_initializer_for__UI_HASH_UPDATE_RHS__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("UPDATE_RHS", 0xFFFFFFFF);
  UI_HASH_UPDATE_RHS = result;
  return result;
}

// File Line: 141
// RVA: 0x156C1D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_MOVE_LEFT_LIST__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_MOVE_LEFT_LIST", 0xFFFFFFFF);
  UI_HASH_MOUSE_MOVE_LEFT_LIST = result;
  return result;
}

// File Line: 142
// RVA: 0x156C210
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_MOVE_RIGHT_LIST__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_MOVE_RIGHT_LIST", 0xFFFFFFFF);
  UI_HASH_MOUSE_MOVE_RIGHT_LIST = result;
  return result;
}

// File Line: 147
// RVA: 0x605700
void __fastcall UFG::UIHKScreenSocialHub::SocialHubProperty::SetCopTriadPercent(UFG::UIHKScreenSocialHub::SocialHubProperty *this, UFG::GameSlice *gameslice)
{
  UFG::GameSlice *v2; // rbx
  UFG::UIHKScreenSocialHub::SocialHubProperty *v3; // rdi
  UFG::qPropertySet *v4; // rsi
  UFG::qSymbol *v5; // rax
  int *v6; // rax
  signed int v7; // ebp
  UFG::qSymbol *v8; // rax
  int *v9; // rax
  signed int v10; // esi
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float v13; // xmm2_4
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = gameslice;
  v3 = this;
  this->mCopPercent = -1.0;
  this->mTriadPercent = -1.0;
  if ( gameslice )
  {
    v4 = UFG::GameSlice::GetRewardsProperties(gameslice);
    v5 = UFG::qSymbol::create_from_string(&result, "CopStartingScore");
    v6 = UFG::qPropertySet::Get<long>(v4, v5, DEPTH_RECURSE);
    if ( v6 )
      v7 = *v6;
    else
      v7 = 0;
    v8 = UFG::qSymbol::create_from_string(&result, "MaxTriadScore");
    v9 = UFG::qPropertySet::Get<long>(v4, v8, DEPTH_RECURSE);
    if ( v9 )
      v10 = *v9;
    else
      v10 = 0;
    v11 = UFG::GameStatTracker::Instance();
    v3->mCopPercent = (float)(signed int)UFG::GameStatTracker::GetStat(v11, CopScore, (UFG::qSymbol *)&v2->mNode.mUID);
    v12 = UFG::GameStatTracker::Instance();
    v13 = (float)(signed int)UFG::GameStatTracker::GetStat(v12, TriadScore, (UFG::qSymbol *)&v2->mNode.mUID);
    v3->mTriadPercent = v13;
    if ( v7 > 0 )
      v3->mCopPercent = v3->mCopPercent / (float)v7;
    else
      v3->mCopPercent = 0.0;
    if ( v10 > 0 )
      v3->mTriadPercent = v13 / (float)v10;
    else
      v3->mTriadPercent = 0.0;
  }
}

// File Line: 185
// RVA: 0x5F1AE0
void __fastcall UFG::UIHKScreenSocialHub::LoadTextures(void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *), void *callbackParam)
{
  void *v2; // rbx
  void (__fastcall *v3)(UFG::DataStreamer::Handle *, void *); // rdi
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax

  v2 = callbackParam;
  v3 = callback;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenSocialHub::gTexturePackFilename,
    HIGH_PRIORITY,
    v3,
    v2);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v5,
    UFG::UIHKScreenPauseMenu::gTexturePackFilename,
    HIGH_PRIORITY,
    v3,
    v2);
}

// File Line: 190
// RVA: 0x5D4140
__int64 __fastcall UFG::UIHKScreenSocialHub::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax
  _BOOL8 v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  v1 = UFG::UIScreenTextureManager::IsTexturePackLoaded(v0, UFG::UIHKScreenSocialHub::gTexturePackFilename);
  v2 = UFG::UIScreenTextureManager::Instance();
  return (unsigned __int8)v1 & UFG::UIScreenTextureManager::IsTexturePackLoaded(
                                 v2,
                                 UFG::UIHKScreenPauseMenu::gTexturePackFilename);
}

// File Line: 197
// RVA: 0x600DF0
void UFG::UIHKScreenSocialHub::ReleaseTextures(void)
{
  UFG::UIScreenTextureManager *v0; // rax
  UFG::UIScreenTextureManager *v1; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v0, UFG::UIHKScreenSocialHub::gTexturePackFilename);
  v1 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v1, UFG::UIHKScreenPauseMenu::gTexturePackFilename);
}

// File Line: 221
// RVA: 0x5C72F0
void __fastcall UFG::UIHKScreenSocialHub::UIHKScreenSocialHub(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::OnlineManagerObserver *v3; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v4; // rax
  UFG::OSuiteManagerObserver *v5; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v6; // rax
  UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *v7; // rcx
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *v8; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  v3 = (UFG::OnlineManagerObserver *)&this->vfptr;
  v4 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v5 = (UFG::OSuiteManagerObserver *)&this->vfptr;
  v6 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable';
  v1->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSocialHub::`vftable'{for `UFG::UIScreen'};
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable'{for `UFG::OnlineManagerObserver'};
  v5->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable'{for `UFG::OSuiteManagerObserver'};
  v7 = (UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *)&v1->mSocialHubProperties;
  v7->p = 0i64;
  *(_QWORD *)&v7->size = 0i64;
  v1->mCurrentIndex = -1;
  v1->mHandleMessageDisabled = 0;
  v1->mPopulateRhsListAsyncRequested = 0;
  *(_QWORD *)&v1->mTimeElapsedAfterMoving = 0i64;
  *(_QWORD *)&v1->mCurrentLeaderboardType = 0i64;
  *(_QWORD *)&v1->mMaxTabs = 3i64;
  v1->mLastListTouchedByMouse = -1;
  v8 = &v1->mChallengeDialogPopupEntries;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  if ( v1->mSocialHubProperties.capacity < 0x100 )
    UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0>::Reallocate(v7, 0x100u, "qArray.Reallocate(Reserve)");
}

// File Line: 229
// RVA: 0x5CC750
void __fastcall UFG::UIHKScreenSocialHub::~UIHKScreenSocialHub(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rdi
  UFG::OnlineManagerObserver *v2; // r14
  UFG::OnlineManagerObserver *v3; // rsi
  UFG::UIHKHelpBarWidget *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // eax
  UFG::OnlineManager *v7; // rax
  UFG::OnlineManager *v8; // rax
  UFG::UIScreenTextureManager *v9; // rax
  UFG::UI *v10; // rcx
  UFG::UIScreenTextureManager *v11; // rax
  ANTLR3_INPUT_STREAM_struct *v12; // rax
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v13; // rcx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v14; // rax
  UFG::UIHKScreenSocialHub::SocialHubProperty *v15; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v16; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v17; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v18; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v19; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v20; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v21; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSocialHub::`vftable'{for `UFG::UIScreen'};
  v2 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable'{for `UFG::OnlineManagerObserver'};
  v3 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable'{for `UFG::OSuiteManagerObserver'};
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v4 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v5 = UFG::qStringHash32("UIHKScreenSocialHub", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v4, v5);
  }
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v6 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v6 == 1) )
        UFG::UI::ResetGameplayInput((UFG::UI *)this);
    }
  }
  v7 = (UFG::OnlineManager *)UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v7, v3);
  v8 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v8, v2);
  UFG::UIHKScreenSocialHub::ReleaseTexturePack(v1);
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v9, "SocialHub");
  if ( UFG::UIHKScreenSocialHub::gPushedFromPauseMenu )
  {
    if ( v1->mLaunchingMissionReplay )
    {
      if ( UFG::UIHKPlayerObjectiveManager::mInstance )
        *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
      UFG::UIScreenManagerBase::queuePopOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        "OpeningCredits");
      UFG::UIHKScreenHud::ResetWidgets();
    }
    else
    {
      v11 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v11, "PauseMenu", 0i64);
    }
  }
  else
  {
    UFG::UI::UnpauseGame(v10);
  }
  if ( v1->mLaunchingMissionReplay )
  {
    UFG::UIHKScreenHud::ClearPDACache();
    v12 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::SetGameState(v12, 8u);
    UFG::LoadingLogic::SetForceLoadScreenOn(&UFG::gLoadingLogic);
  }
  UFG::UIHKScreenSocialHub::gPushedFromPauseMenu = 0;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->mChallengeDialogPopupEntries);
  v13 = v1->mChallengeDialogPopupEntries.mNode.mPrev;
  v14 = v1->mChallengeDialogPopupEntries.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v1->mChallengeDialogPopupEntries.mNode.mPrev = &v1->mChallengeDialogPopupEntries.mNode;
  v1->mChallengeDialogPopupEntries.mNode.mNext = &v1->mChallengeDialogPopupEntries.mNode;
  v15 = v1->mSocialHubProperties.p;
  if ( v15 )
    operator delete[](v15);
  v1->mSocialHubProperties.p = 0i64;
  *(_QWORD *)&v1->mSocialHubProperties.size = 0i64;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable';
  v16 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v3->mPrev;
  v17 = v3->mPrev;
  v18 = v3->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v16->mPrev = v16;
  v16->mNext = v16;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v19 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v2->mPrev;
  v20 = v2->mPrev;
  v21 = v2->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v19->mPrev = v19;
  v19->mNext = v19;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 264
// RVA: 0x636070
void __fastcall UFG::UIHKScreenSocialHub::init(UFG::UIHKScreenSocialHub *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenSocialHub *v2; // r15
  UFG::Controller *v3; // rcx
  UFG::OnlineManagerObserver *v4; // rbx
  UFG::OnlineManager *v5; // rax
  UFG::OSuiteManagerObserver *v6; // rbx
  UFG::OSuiteManager *v7; // rax
  int v8; // edx
  hkGeometryUtils::IVertices *v9; // rcx
  int v10; // er8
  UFG::OnlineManager *v11; // rax
  UFG::OnlineManager *v12; // rax
  UFG::OnlineManager *v13; // rax
  UFG::OSuiteManager *v14; // rax
  signed int v15; // er14
  UFG::OSuiteLeaderboardManager *v16; // r8
  __int64 v17; // rcx
  unsigned int v18; // edi
  __int64 v19; // r12
  signed __int64 v20; // r9
  UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *v21; // r15
  __int64 v22; // rdi
  unsigned int v23; // ebx
  unsigned int v24; // edx
  unsigned int v25; // edx
  UFG::UIHKScreenSocialHub::SocialHubProperty *v26; // rsi
  UFG::OSuiteLeaderboardData *v27; // rax
  unsigned int v28; // edi
  UFG::qBaseTreeRB *v29; // r13
  UFG::qSymbol *v30; // rbx
  UFG::ProgressionTracker *v31; // rax
  UFG::OSuiteLeaderboardData *v32; // rbx
  unsigned int v33; // ecx
  UFG::OSuiteLeaderboardManager *v34; // rax
  UFG::qSymbol *v35; // rbx
  UFG::GameStatTracker *v36; // rax
  UFG::qStaticSymbol *v37; // rbx
  UFG::ProgressionTracker *v38; // rax
  UFG::OSuiteLeaderboardData *v39; // rbx
  UFG::ProgressionTracker *v40; // rax
  int v41; // eax
  Scaleform::GFx::Movie *v42; // rbx
  __int64 v43; // rcx
  UFG::SocialLogDataManager *v44; // rax
  UFG::GameStatTracker *v45; // rax
  UFG::GameStatTracker *v46; // rax
  UFG::OSuiteLeaderboardManager *v47; // [rsp+30h] [rbp-99h]
  signed __int64 v48; // [rsp+38h] [rbp-91h]
  __int64 v49; // [rsp+40h] [rbp-89h]
  char ptr; // [rsp+50h] [rbp-79h]
  __int64 v51; // [rsp+60h] [rbp-69h]
  unsigned int v52; // [rsp+68h] [rbp-61h]
  const char *v53; // [rsp+70h] [rbp-59h]
  UFG::qSymbol *v54; // [rsp+E0h] [rbp+17h]
  __int64 v55; // [rsp+E8h] [rbp+1Fh]
  UFG::UIHKScreenSocialHub *v56; // [rsp+130h] [rbp+67h]
  UFG::qSymbol symGameSliceName; // [rsp+140h] [rbp+77h]
  int v58; // [rsp+148h] [rbp+7Fh]

  v56 = this;
  v55 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  if ( v2 )
    v4 = (UFG::OnlineManagerObserver *)&v2->vfptr;
  else
    v4 = 0i64;
  v5 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v5, v4);
  if ( v2 )
    v6 = (UFG::OSuiteManagerObserver *)&v2->vfptr;
  else
    v6 = 0i64;
  v7 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::RegisterObserver(v7, v6);
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v9, v8, v10) )
  {
    v11 = UFG::OnlineManager::Instance();
    if ( UFG::OnlineManager::IsNetworkSignedIn(v11) )
    {
      if ( !UFG::OSuiteManager::Instance()->m_bConnected
        && UFG::OnlineUtil::CurrentTimeMillis() - UFG::UIHKScreenSocialHub::gLastOSuiteErrorTime > 0xEA60 )
      {
        v14 = UFG::OSuiteManager::Instance();
        UFG::OSuiteManager::Connect(v14);
      }
    }
    else
    {
      v12 = UFG::OnlineManager::Instance();
      if ( (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(v12) == 1 )
      {
        v13 = UFG::OnlineManager::Instance();
        if ( !(unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(v13) )
          UFG::UIScreenDialogBox::createOKDialog(0i64, &customWorldMapCaption, gFirstPartySignedOut, 1);
      }
    }
  }
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v2);
  v15 = 0;
  v16 = UFG::OSuiteLeaderboardManager::Instance();
  v47 = v16;
  v17 = v16->mLeaderboardData.size;
  v58 = 0;
  v18 = 2;
  if ( (_DWORD)v17 )
  {
    v19 = 0i64;
    v20 = 0i64;
    v48 = 0i64;
    v49 = v17;
    v21 = (UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *)&v2->mSocialHubProperties;
    while ( 1 )
    {
      v22 = v21->size;
      v23 = v22 + 1;
      v24 = v21->capacity;
      if ( (signed int)v22 + 1 > v24 )
      {
        if ( v24 )
          v25 = 2 * v24;
        else
          v25 = 1;
        for ( ; v25 < v23; v25 *= 2 )
          ;
        if ( v25 - v23 > 0x10000 )
          v25 = v22 + 65537;
        UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0>::Reallocate(v21, v25, "qArray.Add");
        v16 = v47;
        v20 = v48 * 312;
      }
      v21->size = v23;
      v26 = (UFG::UIHKScreenSocialHub::SocialHubProperty *)&v21->p[v22];
      v27 = v16->mLeaderboardData.p;
      v28 = v27[v19].mCategory;
      v29 = 0i64;
      if ( v28 == 2 )
      {
        v30 = (UFG::qSymbol *)((char *)v27 + v20);
        v31 = UFG::ProgressionTracker::Instance();
        v29 = UFG::ProgressionTracker::Find(v31, v30 + 36, 0);
        v16 = v47;
      }
      v32 = v16->mLeaderboardData.p;
      v33 = v32[v19].mSliceName.mUID;
      if ( v33 != -1 )
        break;
LABEL_45:
      if ( v28 > 1
        || (v39 = v16->mLeaderboardData.p, v39[v19].mFlow.mUID != -1)
        && (v40 = UFG::ProgressionTracker::Instance(),
            v39[v19].mFlow.mUID != UFG::ProgressionTracker::GetActiveFlow(v40)->mUID) )
      {
        v26->mUIItemIndex = -1;
        goto LABEL_50;
      }
LABEL_48:
      v41 = v58;
      v26->mUIItemIndex = v58;
      v58 = v41 + 1;
LABEL_50:
      UFG::UIHKScreenSocialHub::SocialHubProperty::SetCopTriadPercent(v26, (UFG::GameSlice *)v29);
      v16 = v47;
      v26->mLBD = &v47->mLeaderboardData.p[v48];
      v20 = v48 * 312 + 312;
      ++v48;
      ++v19;
      if ( !--v49 )
      {
        v2 = v56;
        v18 = 2;
        goto LABEL_52;
      }
    }
    v54 = &symGameSliceName;
    symGameSliceName.mUID = v33;
    if ( UFG::GameStatAction::GameSliceAction::IsCompleted((__int64)&symGameSliceName) )
    {
      UFG::ProgressionTracker::Instance();
    }
    else
    {
      v34 = UFG::OSuiteLeaderboardManager::Instance();
      v35 = &UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(v34, &v32[v19].mSliceName)->mLeaderboardName;
      v36 = UFG::GameStatTracker::Instance();
      if ( (signed int)UFG::GameStatTracker::GetStat(v36, LeaderboardScoreIntList, v35) <= 0 )
      {
LABEL_44:
        v16 = v47;
        goto LABEL_45;
      }
    }
    v37 = UFG::ProgressionTracker::GetDefaultFlow();
    v38 = UFG::ProgressionTracker::Instance();
    if ( UFG::ProgressionTracker::GetActiveFlow(v38)->mUID == v37->mUID )
    {
      if ( v15 >= 1 || v28 != 2 )
      {
        if ( v15 < 2 && v28 == 3 )
          v15 = 2;
      }
      else
      {
        v15 = 1;
      }
      goto LABEL_48;
    }
    goto LABEL_44;
  }
LABEL_52:
  v42 = v2->mRenderable->m_movie.pObject;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v43 = v51;
  if ( (v52 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v51 + 16i64))(v51, &ptr, v53);
    v43 = 0i64;
    v51 = 0i64;
  }
  v52 = 2;
  LOBYTE(v53) = 0;
  v2->mMaxTabs += v15;
  if ( v15 >= 1 )
  {
    v52 = 6;
    v53 = "$HUD_SOCIAL_HD04";
    Scaleform::GFx::Movie::Invoke(v42, "SocialHub_AddTab", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    v18 = v52;
    v43 = v51;
  }
  if ( v15 >= 2 )
  {
    if ( (v18 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v43 + 16i64))(v43, &ptr, v53);
      v51 = 0i64;
    }
    v52 = 6;
    v53 = "$HUD_SOCIAL_HD05";
    Scaleform::GFx::Movie::Invoke(v42, "SocialHub_AddTab", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  }
  Scaleform::GFx::Movie::Invoke(v42, "SetupSocialLogView", 0i64, 0i64, 0);
  UFG::UIHKScreenSocialHub::PopulateLhsList(v2, 0);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v2, 0, 0);
  UFG::UIHKScreenSocialHub::UpdateOnlineName(v2);
  v44 = UFG::SocialLogDataManager::Instance();
  UFG::SocialLogDataManager::SetHasNewChallengeMessageFlag(v44, 0);
  v45 = UFG::GameStatTracker::Instance();
  if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v45, SocialHubVisited) )
  {
    v46 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v46, SocialHubVisited, 1);
    UFG::UIHKScreenSocialHub::ShowFirstTimeIntro(v2);
  }
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 386
// RVA: 0x63FAA0
void __fastcall UFG::UIHKScreenSocialHub::update(UFG::UIHKScreenSocialHub *this, float elapsed)
{
  UFG::UIHKScreenSocialHub *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  UFG::OSuiteManager *v4; // rax
  unsigned int v5; // edx
  UFG::InputActionData *v6; // rax
  UFG::InputActionData *v7; // rcx
  UFG::qString v8; // [rsp+48h] [rbp-70h]
  UFG::qString v9; // [rsp+70h] [rbp-48h]

  v2 = this;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  if ( v2->mHandleMessageDisabled && v2->mTimeElapsedAfterMoving > 10.0 )
  {
    v3 = v2->mRenderable->m_movie.pObject;
    Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v3, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
    v2->mHandleMessageDisabled = 0;
    v4 = UFG::OSuiteManager::Instance();
    UFG::OSuiteManager::Disconnect(v4);
    UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v2);
    UFG::UIHKScreenSocialHub::PopulateRhsListAsync(v2, v2->mCurrentScreenType, v2->mCurrentLeaderboardType);
  }
  if ( v2->mPopulateRhsListAsyncRequested && v2->mTimeElapsedAfterMoving > 0.40000001 )
  {
    UFG::UIHKScreenSocialHub::PopulateRhsListAsync(v2, v2->mCurrentScreenType, v2->mCurrentLeaderboardType);
    v2->mPopulateRhsListAsyncRequested = 0;
  }
  if ( UFG::UIHKScreenSocialHub::gCallPopulateChallengeList )
  {
    Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "SocialLogList_HideL1R1HelpButtons", 0i64, 0i64, 0);
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      UFG::UIHKScreenSocialHub::PopulateChallengeList(v2);
    }
    else
    {
      UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v2);
      v2->mHandleMessageDisabled = 0;
    }
    UFG::UIHKScreenSocialHub::gCallPopulateChallengeList = 0;
  }
  else if ( UFG::UIHKScreenSocialHub::gCallPopulateRhsList )
  {
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      UFG::UIHKScreenSocialHub::PopulateRhsList(v2);
    }
    else
    {
      UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v2);
      UFG::UIHKScreenSocialHub::PopulateRhsListAsync(v2, v2->mCurrentScreenType, v2->mCurrentLeaderboardType);
    }
    UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 0;
  }
  if ( UFG::UIHKScreenSocialHub::gPopupRequestStatus == 1 )
  {
    UFG::qString::qString(&v9, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$HUD_SOCIAL_SENDCJALLENGE",
      v9.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v9);
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = 0;
    v2->mHandleMessageDisabled = 0;
    UFG::UIHKScreenSocialHub::SetFlagAsSentForNewHighScoreSaveEntry(v2, UFG::UIHKScreenSocialHub::gOSuiteMessage);
    if ( UFG::UIHKScreenSocialHub::gOSuiteMessage )
      UFG::UIHKScreenSocialHub::gOSuiteMessage->vfptr->__vecDelDtor(UFG::UIHKScreenSocialHub::gOSuiteMessage, 1u);
    UFG::UIHKScreenSocialHub::gOSuiteMessage = 0i64;
    UFG::UIHKScreenSocialHub::FLASH_FocusTab(v2, v2->mCurrentScreenType);
    UFG::UIHKScreenSocialHub::PopulateLhsList(v2, v2->mCurrentScreenType);
    UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v2, v2->mCurrentScreenType, 0);
    goto LABEL_23;
  }
  if ( UFG::UIHKScreenSocialHub::gPopupRequestStatus == 2 )
  {
    UFG::qString::qString(&v8, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$HUD_SOCIAL_FAILSEND",
      v8.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v8);
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = 0;
    v2->mHandleMessageDisabled = 0;
LABEL_23:
    v2->mDisplayingChallengeDialog = 0;
  }
  if ( !v2->mHandleMessageDisabled && !v2->mPopupActive )
  {
    v5 = UFG::gActiveControllerNum;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v6 = UFG::ActionDef_UIUpPressed.mDataPerController[UFG::gActiveControllerNum];
      if ( v6 && v6->mActionTrue )
      {
        UFG::UIHKScreenSocialHub::OnScrollUpDown(v2, UI_HASH_THUMBSTICK_RIGHT_UP_30);
        v5 = UFG::gActiveControllerNum;
      }
      v7 = UFG::ActionDef_UIDownPressed.mDataPerController[v5];
      if ( v7 && v7->mActionTrue )
        UFG::UIHKScreenSocialHub::OnScrollUpDown(v2, UI_HASH_THUMBSTICK_RIGHT_DOWN_30);
    }
  }
  v2->mTimeElapsedAfterMoving = elapsed + v2->mTimeElapsedAfterMoving;
}

// File Line: 559
// RVA: 0x5F2430
void __fastcall UFG::UIHKScreenSocialHub::NetworkSignedIn(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx

  v1 = this;
  UFG::UIHKScreenSocialHub::UpdateOnlineName((UFG::UIHKScreenSocialHub *)((char *)this - 144));
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(
    (UFG::UIHKScreenSocialHub *)((char *)v1 - 144),
    *(_DWORD *)&v1->m_screenName[52],
    0);
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon((UFG::UIHKScreenSocialHub *)((char *)v1 - 144));
}

// File Line: 568
// RVA: 0x5F2590
void __fastcall UFG::UIHKScreenSocialHub::NetworkSignedOut(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rdi
  Scaleform::GFx::Movie *v2; // rsi
  const char *v3; // rbx
  UFG::OnlineManager *v4; // rax
  char *v5; // rbx
  char ptr; // [rsp+40h] [rbp-B8h]
  __int64 v7; // [rsp+50h] [rbp-A8h]
  unsigned int v8; // [rsp+58h] [rbp-A0h]
  __int64 v9; // [rsp+60h] [rbp-98h]
  char v10; // [rsp+70h] [rbp-88h]
  __int64 v11; // [rsp+78h] [rbp-80h]
  unsigned int v12; // [rsp+80h] [rbp-78h]
  const char *v13; // [rsp+88h] [rbp-70h]
  char v14; // [rsp+98h] [rbp-60h]
  __int64 v15; // [rsp+A8h] [rbp-50h]
  unsigned int v16; // [rsp+B0h] [rbp-48h]
  char *v17; // [rsp+B8h] [rbp-40h]
  __int64 v18; // [rsp+C8h] [rbp-30h]
  UFG::qString v19; // [rsp+D0h] [rbp-28h]
  UFG::qString result; // [rsp+F8h] [rbp+0h]

  v18 = -2i64;
  v1 = this;
  v2 = *(Scaleform::GFx::Movie **)(*(_QWORD *)&this[-1].mTimeElapsedAfterMoving + 320i64);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v7 + 16i64))(v7, &ptr, v9);
    v7 = 0i64;
  }
  v8 = 2;
  LOBYTE(v9) = 0;
  v3 = gIconSocialHubAvatarPlayer_21;
  if ( (v12 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &v10, v13);
    v11 = 0i64;
  }
  v12 = 6;
  v13 = v3;
  v4 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::GetOnlineName(v4, &result);
  v5 = result.mData;
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
    v15 = 0i64;
  }
  v16 = 6;
  v17 = v5;
  Scaleform::GFx::Movie::Invoke(v2, "SetIsOnline", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(
    (UFG::UIHKScreenSocialHub *)((char *)v1 - 144),
    *(_DWORD *)&v1->m_screenName[52],
    0);
  if ( UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)&v1[-1].mInputEnabled
    || *((_BYTE *)&v1->m_screenNameHash + 7) == 1 )
  {
    UFG::qString::qString(&v19, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      (UFG::UIScreen *)&v1[-1].mInputEnabled,
      &customWorldMapCaption,
      "$COMMON_TRC_PC_CONNECTION_FAILED",
      v19.mData,
      UI_HASH_DIALOG_OK_30,
      0,
      "DialogBox");
    UFG::qString::~qString(&v19);
  }
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon((UFG::UIHKScreenSocialHub *)((char *)v1 - 144));
  UFG::qString::~qString(&result);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 604
// RVA: 0x5F2A90
void __fastcall UFG::UIHKScreenSocialHub::OSuiteManagerConnected(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx

  v1 = (UFG::UIHKScreenSocialHub *)((char *)this - 168);
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon((UFG::UIHKScreenSocialHub *)((char *)this - 168));
  UFG::UIHKScreenSocialHub::RequestRhsListPopulation(v1);
}

// File Line: 670
// RVA: 0x60FFB0
void __fastcall UFG::UIHKScreenSocialHub::ShowHelpBarWidget(UFG::UIHKScreenSocialHub *this, int screenType, bool enableProfileButton)
{
  bool v3; // r15
  int v4; // ebx
  UFG::UIHKScreenSocialHub *v5; // r14
  int v6; // esi
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::MapBool *v8; // rax
  bool v9; // al
  UFG::qSymbol *v10; // rax
  const char *v11; // r8
  unsigned int v12; // er14
  int v13; // ecx
  __int64 v14; // rax
  __int64 v15; // rdi
  __int64 v16; // rbx
  unsigned int v17; // er14
  int v18; // ecx
  __int64 v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rbx
  unsigned int v22; // er14
  int v23; // ecx
  __int64 v24; // rax
  __int64 v25; // rdi
  __int64 v26; // rbx
  unsigned int v27; // er14
  __int64 v28; // rax
  unsigned int v29; // er14
  int v30; // ecx
  __int64 v31; // rax
  __int64 v32; // rdi
  __int64 v33; // rbx
  unsigned int v34; // er14
  int v35; // ecx
  __int64 v36; // rax
  __int64 v37; // rdi
  __int64 v38; // rbx
  unsigned int v39; // er14
  int v40; // ecx
  __int64 v41; // rax
  __int64 v42; // rdi
  __int64 v43; // rbx
  __int64 v44; // rax
  UFG::OnlineManager *v45; // rax
  UFG::SocialLogDataManager *v46; // rax
  UFG::SocialLogDataManager *v47; // rax
  unsigned int v48; // er15
  int v49; // ecx
  __int64 v50; // rax
  __int64 v51; // rdi
  __int64 v52; // rbx
  unsigned int v53; // er15
  int v54; // ecx
  __int64 v55; // rax
  __int64 v56; // rdi
  __int64 v57; // rbx
  UFG::OnlineManager *v58; // rax
  unsigned int v59; // er14
  int v60; // ecx
  __int64 v61; // rax
  __int64 v62; // rdi
  __int64 v63; // rbx
  unsigned int v64; // er14
  int v65; // ecx
  __int64 v66; // rax
  __int64 v67; // rdi
  __int64 v68; // rbx
  unsigned int v69; // er14
  __int64 v70; // rax
  UFG::UIHKScreenGlobalOverlay *v71; // rdi
  UFG::UIHKScreenGlobalOverlay *v72; // rax
  signed __int64 v73; // rbx
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-C8h]

  data.CustomTexturePack.mData = (char *)-2i64;
  v3 = enableProfileButton;
  v4 = screenType;
  v5 = this;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32("UIHKScreenSocialHub", 0xFFFFFFFF);
  v6 = 0;
  *(_QWORD *)&data.priority = 0i64;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    goto LABEL_90;
  v7 = UFG::GameStatTracker::Instance();
  v8 = UFG::GameStatTracker::GetMapBool(v7, Collectible_Safehouse);
  v9 = (unsigned int)UFG::PersistentData::MapBool::GetTrueCount(v8) != 0;
  if ( !v4 )
  {
    v46 = UFG::SocialLogDataManager::Instance();
    if ( (UFG::SocialLogDataManager *)&v46->m_lSocialLogDataList.mNode.mNext[-2].mNext != &v46[-1] )
    {
      v47 = UFG::SocialLogDataManager::Instance();
      if ( UFG::SocialLogDataManager::ListContainsActiveFlowEntries(v47) == 1 )
      {
        v48 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
        v49 = 0;
        v50 = 0i64;
        while ( data.Buttons[v50] )
        {
          ++v49;
          if ( ++v50 >= 6 )
            goto LABEL_62;
        }
        v51 = v49;
        data.Buttons[v49] = 1;
        v52 = v49;
        UFG::qString::Set(&data.Captions[v49], "$HELPBAR_MORE_INFO");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v52 + 5] + 16), &customWorldMapCaption);
        *(&data.Icons[5].mMagic + v51) = v48;
      }
    }
LABEL_62:
    v53 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v54 = 0;
    v55 = 0i64;
    while ( data.Buttons[v55] )
    {
      ++v54;
      if ( ++v55 >= 6 )
        goto LABEL_67;
    }
    v56 = v54;
    data.Buttons[v54] = 2;
    v57 = v54;
    UFG::qString::Set(&data.Captions[v54], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v57 + 5] + 16), &customWorldMapCaption);
    *(&data.Icons[5].mMagic + v56) = v53;
LABEL_67:
    if ( UFG::UIHKScreenSocialHub::IsChallengeableEntry(v5) )
    {
      v58 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v58) )
      {
        v59 = UI_HASH_BUTTON_BUTTON1_PRESSED_30;
        v60 = 0;
        v61 = 0i64;
        while ( data.Buttons[v61] )
        {
          ++v60;
          if ( ++v61 >= 6 )
            goto LABEL_74;
        }
        v62 = v60;
        data.Buttons[v60] = 3;
        v63 = v60;
        UFG::qString::Set(&data.Captions[v60], "$HUD_SOCIAL_CHALLENGE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v63 + 5] + 16), &customWorldMapCaption);
        *(&data.Icons[5].mMagic + v62) = v59;
      }
    }
LABEL_74:
    v64 = (unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
    v65 = 0;
    v66 = 0i64;
    while ( data.Buttons[v66] )
    {
      ++v65;
      if ( ++v66 >= 6 )
        goto LABEL_79;
    }
    v67 = v65;
    data.Buttons[v65] = 4;
    v68 = v65;
    UFG::qString::Set(&data.Captions[v65], "$BUTTON_SOCIAL_HELP");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v68 + 5] + 16), &customWorldMapCaption);
    *(&data.Icons[5].mMagic + v67) = v64;
LABEL_79:
    if ( gIsUIHighDef )
    {
      v69 = UI_HASH_BUTTON_R1_PRESSED_30;
      v70 = 0i64;
      while ( data.Buttons[v70] )
      {
        ++v6;
        if ( ++v70 >= 6 )
          goto LABEL_85;
      }
      data.Buttons[v6] = 13;
      UFG::qString::Set(&data.Captions[v6], "$HELPBAR_CHANGE_SECTION_UC");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v6 + 5] + 16), &customWorldMapCaption);
      *(&data.Icons[5].mMagic + v6) = v69;
    }
    goto LABEL_85;
  }
  if ( v4 > 0 )
  {
    if ( v4 <= 2 )
    {
      v29 = UI_HASH_BUTTON_BACK_PRESSED_30;
      v30 = 0;
      v31 = 0i64;
      while ( data.Buttons[v31] )
      {
        ++v30;
        if ( ++v31 >= 6 )
          goto LABEL_36;
      }
      v32 = v30;
      data.Buttons[v30] = 2;
      v33 = v30;
      UFG::qString::Set(&data.Captions[v30], "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v33 + 5] + 16), &customWorldMapCaption);
      *(&data.Icons[5].mMagic + v32) = v29;
LABEL_36:
      v34 = (unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
      v35 = 0;
      v36 = 0i64;
      while ( data.Buttons[v36] )
      {
        ++v35;
        if ( ++v36 >= 6 )
          goto LABEL_41;
      }
      v37 = v35;
      data.Buttons[v35] = 4;
      v38 = v35;
      UFG::qString::Set(&data.Captions[v35], "$BUTTON_SOCIAL_HELP");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v38 + 5] + 16), &customWorldMapCaption);
      *(&data.Icons[5].mMagic + v37) = v34;
LABEL_41:
      if ( gIsUIHighDef )
      {
        v39 = UI_HASH_BUTTON_R1_PRESSED_30;
        v40 = 0;
        v41 = 0i64;
        while ( data.Buttons[v41] )
        {
          ++v40;
          if ( ++v41 >= 6 )
            goto LABEL_47;
        }
        v42 = v40;
        data.Buttons[v40] = 13;
        v43 = v40;
        UFG::qString::Set(&data.Captions[v40], "$HELPBAR_CHANGE_SECTION_UC");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v43 + 5] + 16), &customWorldMapCaption);
        *(&data.Icons[5].mMagic + v42) = v39;
      }
LABEL_47:
      v27 = UI_HASH_BUTTON_R3_PRESSED_30;
      v44 = 0i64;
      while ( data.Buttons[v44] )
      {
        ++v6;
        if ( ++v44 >= 6 )
          goto LABEL_52;
      }
      goto LABEL_51;
    }
    if ( v4 <= 4 )
    {
      if ( v9 )
      {
        v10 = UFG::UIHKScreenSocialHub::GetCurrentItemGameSliceName(v5);
        if ( (unsigned int)UFG::UIHKScreenSocialHub::ShouldShowGameSlice(v5, v10) == 2 )
        {
          v11 = "$HUD_SOCIAL_REPLAYRACE";
          if ( v4 == 3 )
            v11 = "$HUD_SOCIAL_REPLAYMISSION";
          UFG::UIHKHelpBarData::Add(&data, ACCEPT_BUTTON, v11, UI_HASH_BUTTON_ACCEPT_PRESSED_30);
        }
      }
      v12 = UI_HASH_BUTTON_BACK_PRESSED_30;
      v13 = 0;
      v14 = 0i64;
      while ( data.Buttons[v14] )
      {
        ++v13;
        if ( ++v14 >= 6 )
          goto LABEL_16;
      }
      v15 = v13;
      data.Buttons[v13] = 2;
      v16 = v13;
      UFG::qString::Set(&data.Captions[v13], "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v16 + 5] + 16), &customWorldMapCaption);
      *(&data.Icons[5].mMagic + v15) = v12;
LABEL_16:
      v17 = (unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
      v18 = 0;
      v19 = 0i64;
      while ( data.Buttons[v19] )
      {
        ++v18;
        if ( ++v19 >= 6 )
          goto LABEL_21;
      }
      v20 = v18;
      data.Buttons[v18] = 4;
      v21 = v18;
      UFG::qString::Set(&data.Captions[v18], "$BUTTON_SOCIAL_HELP");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v21 + 5] + 16), &customWorldMapCaption);
      *(&data.Icons[5].mMagic + v20) = v17;
LABEL_21:
      if ( gIsUIHighDef )
      {
        v22 = UI_HASH_BUTTON_R1_PRESSED_30;
        v23 = 0;
        v24 = 0i64;
        while ( data.Buttons[v24] )
        {
          ++v23;
          if ( ++v24 >= 6 )
            goto LABEL_27;
        }
        v25 = v23;
        data.Buttons[v23] = 13;
        v26 = v23;
        UFG::qString::Set(&data.Captions[v23], "$HELPBAR_CHANGE_SECTION_UC");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v26 + 5] + 16), &customWorldMapCaption);
        *(&data.Icons[5].mMagic + v25) = v22;
      }
LABEL_27:
      v27 = UI_HASH_BUTTON_R3_PRESSED_30;
      v28 = 0i64;
      while ( data.Buttons[v28] )
      {
        ++v6;
        if ( ++v28 >= 6 )
          goto LABEL_52;
      }
LABEL_51:
      data.Buttons[v6] = 12;
      UFG::qString::Set(&data.Captions[v6], "$HUD_SOCIAL_TOGGLE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v6 + 5] + 16), &customWorldMapCaption);
      *(&data.Icons[5].mMagic + v6) = v27;
LABEL_52:
      v45 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v45) && v3 )
        UFG::UIHKHelpBarData::Add(&data, SELECT_BUTTON, gLocTag_Gamertag, UI_HASH_BUTTON_SELECT_PRESSED_30);
      goto LABEL_85;
    }
  }
LABEL_85:
  v71 = &gGlobalOverlaySentinel;
  v72 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v72 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v72->HelpBar, &data);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v71 = UFG::UIHKScreenGlobalOverlay::mThis;
  v73 = (signed __int64)&v71->HelpBar;
  *(_BYTE *)(v73 + 1) |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v71->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
  *(_DWORD *)(v73 + 612) = -1046478848;
LABEL_90:
  UFG::qString::~qString((UFG::qString *)data.MessageIds);
  `eh vector destructor iterator'(
    &data.Captions[5].mMagic,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 769
// RVA: 0x610830
void __fastcall UFG::UIHKScreenSocialHub::ShowHelpButtonsEx(UFG::UIHKScreenSocialHub *this)
{
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    Scaleform::GFx::Movie::Invoke(
      this->mRenderable->m_movie.pObject,
      "SocialLogList_ShowL1R1HelpButtons",
      0i64,
      0i64,
      0);
}

// File Line: 784
// RVA: 0x600590
void __fastcall UFG::UIHKScreenSocialHub::RefreshHelpButtonsEx(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  const char *v2; // rdx

  v1 = this->mRenderable->m_movie.pObject;
  v2 = "SocialLogList_HideL1R1HelpButtons";
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    v2 = "SocialLogList_ShowL1R1HelpButtons";
  Scaleform::GFx::Movie::Invoke(v1, v2, 0i64, 0i64, 0);
}

// File Line: 797
// RVA: 0x600970
void __fastcall UFG::UIHKScreenSocialHub::RefreshScreenType(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx

  v1 = this;
  UFG::UIHKScreenSocialHub::FLASH_FocusTab(this, this->mCurrentScreenType);
  UFG::UIHKScreenSocialHub::PopulateLhsList(v1, v1->mCurrentScreenType);
  UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(v1);
  UFG::UIHKScreenSocialHub::RequestRhsListPopulation(v1);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v1, v1->mCurrentScreenType, 0);
}

// File Line: 809
// RVA: 0x5F9D40
void __fastcall UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *v1; // rdi
  int v2; // edx
  hkGeometryUtils::IVertices *v3; // rcx
  int v4; // er8
  const char *v5; // rbx
  const char *v6; // rdx
  UFG::OnlineManager *v7; // rax
  UFG::OnlineManager *v8; // rax
  bool v9; // al
  const char *v10; // rcx
  const char *v11; // rax
  hkgpIndexedMeshDefinitions::Edge *v12; // rdx
  bool v13; // al
  char *v14; // rbx
  UFG::qString v15; // [rsp+28h] [rbp-49h]
  char ptr; // [rsp+58h] [rbp-19h]
  __int64 v17; // [rsp+68h] [rbp-9h]
  unsigned int v18; // [rsp+70h] [rbp-1h]
  const char *v19; // [rsp+78h] [rbp+7h]
  char v20; // [rsp+88h] [rbp+17h]
  __int64 v21; // [rsp+98h] [rbp+27h]
  unsigned int v22; // [rsp+A0h] [rbp+2Fh]
  char *v23; // [rsp+A8h] [rbp+37h]
  __int64 v24; // [rsp+B8h] [rbp+47h]

  v24 = -2i64;
  v1 = this->mRenderable->m_movie.pObject;
  if ( !v1 )
    return;
  UFG::qString::qString(&v15);
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v3, v2, v4) )
  {
    v7 = UFG::OnlineManager::Instance();
    if ( !UFG::OnlineManager::IsNetworkSignedIn(v7) )
    {
      v5 = "Red";
      v8 = UFG::OnlineManager::Instance();
      v9 = UFG::OnlineManager::IsNetworkAvailable(v8);
      v10 = gNetworkDisconnectedMessage;
      if ( v9 )
        v10 = gFirstPartySignedOut;
      v11 = UFG::UI::LocalizeText(v10);
      UFG::qString::operator+=(&v15, v11);
      goto LABEL_13;
    }
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      v13 = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, v12);
      v5 = "Green";
      v6 = gSocialHubParentalControlsMessage;
      if ( !v13 )
        v6 = "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_GREEN";
    }
    else
    {
      v5 = "Yellow";
      v6 = "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW";
    }
  }
  else
  {
    v5 = "Red";
    v6 = gSocialHubNoOnlineAccountMessage;
  }
  UFG::qString::Set(&v15, v6);
LABEL_13:
  `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v17 + 16i64))(v17, &ptr, v19);
    v17 = 0i64;
  }
  v18 = 6;
  v19 = v5;
  v14 = v15.mData;
  if ( (v22 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v21 + 16i64))(v21, &v20, v23);
    v21 = 0i64;
  }
  v22 = 6;
  v23 = v14;
  Scaleform::GFx::Movie::Invoke(v1, "SocialHubOnlineStatusIcon_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v15);
}

// File Line: 860
// RVA: 0x5F82F0
void __fastcall UFG::UIHKScreenSocialHub::PopulateLhsList(UFG::UIHKScreenSocialHub *this, int screenType)
{
  UFG::UIHKScreenSocialHub *v2; // rdi
  UFG::UIScreenRenderable *v3; // rax
  Scaleform::GFx::Movie *v4; // rcx
  signed __int64 v5; // r14
  unsigned __int128 v6; // ax
  __int64 v7; // rbx
  UFG::SocialLogDataManager *v8; // rax
  UFG::SocialLogDataManager *v9; // rax
  signed __int64 v10; // rsi
  unsigned __int64 v11; // rbx
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
  const char *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString *v16; // rcx
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  const char *v19; // rax
  UFG::qString *v20; // rax
  unsigned int v21; // eax
  UFG::UIGfxTranslator *v22; // rcx
  const char *v23; // rcx
  unsigned int v24; // edx
  UFG::qString *v25; // rax
  unsigned int v26; // eax
  UFG::UIGfxTranslator *v27; // rcx
  const char *v28; // rcx
  unsigned int v29; // edx
  UFG::qString *v30; // rax
  unsigned int v31; // eax
  UFG::UIGfxTranslator *v32; // rcx
  const char *v33; // rcx
  unsigned int v34; // edx
  UFG::qString *v35; // rax
  char *v36; // r12
  char *v37; // r15
  UFG::OSuiteLeaderboardManager *v38; // rax
  UFG::OSuiteLeaderboardData *v39; // rax
  UFG::OSuiteLeaderboardData *v40; // rbx
  UFG::ProgressionTracker *v41; // rax
  __int64 v42; // rdx
  unsigned int v43; // er8
  UFG::UIHKScreenSocialHub::SocialHubProperty *v44; // r9
  const char *v45; // rdi
  const char *v46; // rax
  unsigned int v47; // eax
  UFG::UIGfxTranslator *v48; // rcx
  int v49; // eax
  UFG::OnlineManager *v50; // rax
  char *v51; // r8
  unsigned int v52; // eax
  UFG::UIGfxTranslator *v53; // rcx
  const char *v54; // rax
  UFG::qString *v55; // rax
  char *v56; // rbx
  int v57; // eax
  unsigned int v58; // eax
  UFG::UIGfxTranslator *v59; // rcx
  unsigned int v60; // eax
  UFG::UIGfxTranslator *v61; // rcx
  unsigned int v62; // eax
  UFG::UIGfxTranslator *v63; // rcx
  UFG::OnlineManager *v64; // rax
  char *v65; // r8
  unsigned int v66; // eax
  UFG::UIGfxTranslator *v67; // rcx
  const char *v68; // rax
  UFG::qString *v69; // rax
  UFG::OnlineManager *v70; // rax
  char *v71; // r8
  unsigned int v72; // eax
  UFG::UIGfxTranslator *v73; // rcx
  const char *v74; // rdx
  UFG::qString *v75; // rax
  UFG::qString *v76; // rbx
  UFG::OnlineManager *v77; // rax
  UFG::OnlineId *v78; // rax
  UFG::qString *v79; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v80; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v81; // rcx
  char *v82; // rax
  unsigned int v83; // eax
  UFG::UIGfxTranslator *v84; // rcx
  const char *v85; // rdx
  UFG::qString *v86; // rax
  UFG::qString *v87; // rbx
  UFG::OnlineManager *v88; // rax
  UFG::OnlineId *v89; // rax
  UFG::qString *v90; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v91; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v92; // rax
  double v93; // xmm6_8
  double v94; // xmm6_8
  char *v95; // rbx
  char *v96; // rbx
  char *v97; // rbx
  signed int v98; // er13
  int v99; // edx
  int v100; // edx
  int v101; // edx
  unsigned int v102; // er14
  signed int v103; // edi
  __int64 v104; // rbx
  UFG::UIHKScreenSocialHub::SocialHubProperty *v105; // rsi
  __int64 v106; // rsi
  UFG::OnlineId v107; // [rsp+30h] [rbp-D0h]
  UFG::OnlineId v108; // [rsp+48h] [rbp-B8h]
  __int64 v109; // [rsp+60h] [rbp-A0h]
  UFG::qString v110; // [rsp+68h] [rbp-98h]
  UFG::qString v111; // [rsp+90h] [rbp-70h]
  UFG::qString v112; // [rsp+B8h] [rbp-48h]
  UFG::qString formatted; // [rsp+E0h] [rbp-20h]
  UFG::qString v114; // [rsp+108h] [rbp+8h]
  char ptr; // [rsp+130h] [rbp+30h]
  __int64 v116; // [rsp+140h] [rbp+40h]
  unsigned int v117; // [rsp+148h] [rbp+48h]
  double v118; // [rsp+150h] [rbp+50h]
  char v119; // [rsp+160h] [rbp+60h]
  __int64 v120; // [rsp+170h] [rbp+70h]
  unsigned int v121; // [rsp+178h] [rbp+78h]
  double v122; // [rsp+180h] [rbp+80h]
  char v123; // [rsp+190h] [rbp+90h]
  __int64 v124; // [rsp+1A0h] [rbp+A0h]
  unsigned int v125; // [rsp+1A8h] [rbp+A8h]
  double v126; // [rsp+1B0h] [rbp+B0h]
  char v127; // [rsp+1C0h] [rbp+C0h]
  __int64 v128; // [rsp+1D0h] [rbp+D0h]
  unsigned int v129; // [rsp+1D8h] [rbp+D8h]
  char *v130; // [rsp+1E0h] [rbp+E0h]
  char v131; // [rsp+1F0h] [rbp+F0h]
  __int64 v132; // [rsp+200h] [rbp+100h]
  unsigned int v133; // [rsp+208h] [rbp+108h]
  char *v134; // [rsp+210h] [rbp+110h]
  char v135; // [rsp+220h] [rbp+120h]
  __int64 v136; // [rsp+230h] [rbp+130h]
  unsigned int v137; // [rsp+238h] [rbp+138h]
  char *v138; // [rsp+240h] [rbp+140h]
  char v139; // [rsp+250h] [rbp+150h]
  __int64 v140; // [rsp+260h] [rbp+160h]
  unsigned int v141; // [rsp+268h] [rbp+168h]
  char *v142; // [rsp+270h] [rbp+170h]
  char v143; // [rsp+280h] [rbp+180h]
  __int64 v144; // [rsp+290h] [rbp+190h]
  unsigned int v145; // [rsp+298h] [rbp+198h]
  char *v146; // [rsp+2A0h] [rbp+1A0h]
  __int64 v147; // [rsp+2B0h] [rbp+1B0h]
  char putf8str; // [rsp+2C0h] [rbp+1C0h]
  __int64 v149; // [rsp+2D0h] [rbp+1D0h]
  unsigned int v150; // [rsp+2D8h] [rbp+1D8h]
  double v151; // [rsp+2E0h] [rbp+1E0h]
  char v152; // [rsp+2F0h] [rbp+1F0h]
  __int64 v153; // [rsp+300h] [rbp+200h]
  unsigned int v154; // [rsp+308h] [rbp+208h]
  __int64 v155; // [rsp+310h] [rbp+210h]
  char v156; // [rsp+320h] [rbp+220h]
  __int64 v157; // [rsp+330h] [rbp+230h]
  unsigned int v158; // [rsp+338h] [rbp+238h]
  const char *v159; // [rsp+340h] [rbp+240h]
  UFG::qString v160; // [rsp+3C0h] [rbp+2C0h]
  UFG::qString v161; // [rsp+3E8h] [rbp+2E8h]
  UFG::qString v162; // [rsp+410h] [rbp+310h]
  UFG::qString v163; // [rsp+438h] [rbp+338h]
  UFG::qString v164; // [rsp+460h] [rbp+360h]
  UFG::qString v165; // [rsp+488h] [rbp+388h]
  UFG::qString v166; // [rsp+4B0h] [rbp+3B0h]
  UFG::qString v167; // [rsp+4D8h] [rbp+3D8h]
  UFG::qString v168; // [rsp+500h] [rbp+400h]
  UFG::qString v169; // [rsp+528h] [rbp+428h]
  UFG::qString v170; // [rsp+550h] [rbp+450h]
  UFG::qString v171; // [rsp+578h] [rbp+478h]
  UFG::qString v172; // [rsp+5A0h] [rbp+4A0h]
  UFG::qString v173; // [rsp+5C8h] [rbp+4C8h]
  UFG::qString result; // [rsp+5F0h] [rbp+4F0h]
  UFG::qString v175; // [rsp+618h] [rbp+518h]
  char dest; // [rsp+640h] [rbp+540h]
  wchar_t pbuff; // [rsp+740h] [rbp+640h]
  wchar_t v178; // [rsp+940h] [rbp+840h]
  UFG::UIHKScreenSocialHub *v179; // [rsp+BA0h] [rbp+AA0h]
  signed int v180; // [rsp+BA8h] [rbp+AA8h]
  Scaleform::GFx::Movie *v181; // [rsp+BB0h] [rbp+AB0h]
  signed __int64 v182; // [rsp+BB8h] [rbp+AB8h]

  v179 = this;
  v147 = -2i64;
  v2 = this;
  v3 = this->mRenderable;
  v4 = v3->m_movie.pObject;
  v181 = v3->m_movie.pObject;
  v5 = 0i64;
  v2->mLHSItemCount = 0;
  if ( screenType )
  {
    v98 = -1;
    v99 = screenType - 1;
    if ( v99 )
    {
      v100 = v99 - 1;
      if ( v100 )
      {
        v101 = v100 - 1;
        if ( v101 )
        {
          if ( v101 == 1 )
            v98 = 3;
        }
        else
        {
          v98 = 2;
        }
      }
      else
      {
        v98 = 1;
      }
    }
    else
    {
      v98 = 0;
    }
    v102 = v2->mSocialHubProperties.size;
    v103 = 0;
    if ( v102 )
    {
      v104 = 0i64;
      do
      {
        v105 = v179->mSocialHubProperties.p;
        if ( v98 == v105[v104].mLBD->mCategory && v105[v104].mUIItemIndex != -1 )
        {
          `eh vector constructor iterator'(
            &putf8str,
            0x30ui64,
            3,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          if ( (v150 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v149 + 16i64))(
              v149,
              &putf8str,
              COERCE_DOUBLE(*(_QWORD *)&v151));
            v149 = 0i64;
          }
          v150 = 5;
          v151 = (double)v103;
          v106 = (__int64)v105[v104].mLBD->mCaption.mData;
          if ( (v154 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v153 + 16i64))(v153, &v152, v155);
            v153 = 0i64;
          }
          v154 = 6;
          v155 = v106;
          if ( (v158 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v157 + 16i64))(v157, &v156, v159);
            v157 = 0i64;
          }
          v158 = 6;
          v159 = "icon";
          Scaleform::GFx::Movie::Invoke(v181, "SocialHubLhsList_AddItem", 0i64, (Scaleform::GFx::Value *)&putf8str, 3u);
          ++v179->mLHSItemCount;
          `eh vector destructor iterator'(
            &putf8str,
            0x30ui64,
            3,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        }
        ++v103;
        ++v104;
      }
      while ( v103 < v102 );
      v4 = v181;
    }
    Scaleform::GFx::Movie::Invoke(v4, "SocialHubLhsList_Refresh", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v181, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
  }
  else
  {
    v6 = (UFG::qGetSystemTimeUTC() - 116444736000000000i64) * (unsigned __int128)0x346DC5D63886594Bui64;
    v7 = *((_QWORD *)&v6 + 1) >> 11;
    v109 = *((_QWORD *)&v6 + 1) >> 11;
    v8 = UFG::SocialLogDataManager::Instance();
    v9 = UFG::SocialLogDataManager::GetList(v8);
    v10 = (signed __int64)&v9->m_lSocialLogDataList.mNode.mPrev[-2].mNext;
    v182 = (signed __int64)&v9[-1];
    if ( (UFG::SocialLogDataManager *)v10 != &v9[-1] )
    {
      while ( 1 )
      {
        UFG::qString::qString(&v110);
        v11 = (unsigned __int64)(((unsigned __int64)(v7 - *(_QWORD *)(v10 + 48))
                                * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                               + ((unsigned __int64)(v7
                                                   - *(_QWORD *)(v10 + 48)
                                                   - ((unsigned __int64)(v7 - *(_QWORD *)(v10 + 48))
                                                    * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
        if ( (v11 & 0x80000000) == 0i64 )
        {
          if ( (signed int)v11 >= 60 )
          {
            if ( (signed int)v11 >= 3600 )
            {
              if ( (signed int)v11 >= 86400 )
              {
                v31 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_DAY_FORMAT", 0xFFFFFFFF);
                v32 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v32
                  || (v33 = (const char *)v32->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v32->vfptr, v31)) == 0i64 )
                {
                  v33 = "SOCIAL_HUB_RECEIVED_TIME_DAY_FORMAT";
                }
                v34 = (signed int)(v11 + ((unsigned __int64)(-1037155065i64 * (signed int)v11) >> 32)) >> 16;
                v35 = UFG::qString::FormatEx(&v173, v33, v34 + (v34 >> 31));
                UFG::qString::Set(&v110, v35->mData, v35->mLength, 0i64, 0);
                v16 = &v173;
              }
              else
              {
                v26 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_HOUR_FORMAT", 0xFFFFFFFF);
                v27 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v27
                  || (v28 = (const char *)v27->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, v26)) == 0i64 )
                {
                  v28 = "SOCIAL_HUB_RECEIVED_TIME_HOUR_FORMAT";
                }
                v29 = (signed int)(v11 + ((unsigned __int64)(-1851608123i64 * (signed int)v11) >> 32)) >> 11;
                v30 = UFG::qString::FormatEx(&v165, v28, v29 + (v29 >> 31));
                UFG::qString::Set(&v110, v30->mData, v30->mLength, 0i64, 0);
                v16 = &v165;
              }
            }
            else
            {
              v21 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_MINUTE_FORMAT", 0xFFFFFFFF);
              v22 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v22
                || (v23 = (const char *)v22->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, v21)) == 0i64 )
              {
                v23 = "SOCIAL_HUB_RECEIVED_TIME_MINUTE_FORMAT";
              }
              v24 = (signed int)(v11 + ((unsigned __int64)(-2004318071i64 * (signed int)v11) >> 32)) >> 5;
              v25 = UFG::qString::FormatEx(&v163, v23, v24 + (v24 >> 31));
              UFG::qString::Set(&v110, v25->mData, v25->mLength, 0i64, 0);
              v16 = &v163;
            }
          }
          else
          {
            v17 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", 0xFFFFFFFF);
            v18 = UFG::UIScreenManager::s_instance->m_translator;
            if ( !v18
              || (v19 = (const char *)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0i64 )
            {
              v19 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
            }
            v20 = UFG::qString::FormatEx(&v170, v19, (unsigned int)v11);
            UFG::qString::Set(&v110, v20->mData, v20->mLength, 0i64, 0);
            v16 = &v170;
          }
        }
        else
        {
          v12 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", 0xFFFFFFFF);
          v13 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v13
            || (v14 = (const char *)v13->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v12)) == 0i64 )
          {
            v14 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
          }
          v15 = UFG::qString::FormatEx(&result, v14, 0i64);
          UFG::qString::Set(&v110, v15->mData, v15->mLength, 0i64, 0);
          v16 = &result;
        }
        UFG::qString::~qString(v16);
        v36 = &customWorldMapCaption;
        v37 = &customWorldMapCaption;
        UFG::qString::qString(&v111);
        UFG::qString::qString(&v112);
        v38 = UFG::OSuiteLeaderboardManager::Instance();
        v39 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(v38, *(_DWORD *)(v10 + 56));
        v40 = v39;
        if ( !v39
          || v39->mFlow.mUID != -1
          && (v41 = UFG::ProgressionTracker::Instance(),
              v40->mFlow.mUID != UFG::ProgressionTracker::GetActiveFlow(v41)->mUID) )
        {
          UFG::qString::~qString(&v112);
          UFG::qString::~qString(&v111);
          UFG::qString::~qString(&v110);
          goto LABEL_113;
        }
        v180 = -1;
        v42 = 0i64;
        v43 = v2->mSocialHubProperties.size;
        if ( v43 )
        {
          v44 = v2->mSocialHubProperties.p;
          while ( v44[v42].mLBD != v40 )
          {
            v42 = (unsigned int)(v42 + 1);
            if ( (unsigned int)v42 >= v43 )
              goto LABEL_36;
          }
          v5 = (signed __int64)&v44[v42];
          v180 = v42;
        }
LABEL_36:
        v45 = v40->mCaption.mData;
        if ( v45 )
        {
          if ( *v45 == 36 )
            ++v45;
          v47 = UFG::qStringHashUpper32(v45, 0xFFFFFFFF);
          v48 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v48
            || (v46 = (const char *)v48->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v48->vfptr, v47)) == 0i64 )
          {
            v46 = v45;
          }
        }
        else
        {
          v46 = 0i64;
        }
        UFG::qString::qString(&v114, v46);
        UFG::qString::qString(&formatted);
        v2 = v179;
        UFG::UIHKScreenSocialHub::FormatScore(v179, &formatted, v40, *(_DWORD *)(v10 + 60));
        v49 = *(_DWORD *)(v10 + 44);
        if ( !v49 )
          break;
        if ( v49 == 1 )
        {
          v56 = &customWorldMapCaption;
          v36 = (char *)gIconSocialHubAvatarPlayer_21;
          v57 = *(_DWORD *)(v10 + 60);
          switch ( v57 )
          {
            case 3:
              v37 = (char *)gIconSocialHubStatAward_G_21;
              v58 = UFG::qStringHashUpper32("SOCIAL_HUB_GOLD", 0xFFFFFFFF);
              v59 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v59
                || (v56 = (char *)v59->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v59->vfptr, v58)) == 0i64 )
              {
                v56 = "SOCIAL_HUB_GOLD";
              }
              break;
            case 2:
              v37 = (char *)gIconSocialHubStatAward_S_21;
              v60 = UFG::qStringHashUpper32("SOCIAL_HUB_SILVER", 0xFFFFFFFF);
              v61 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v61
                || (v56 = (char *)v61->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v61->vfptr, v60)) == 0i64 )
              {
                v56 = "SOCIAL_HUB_SILVER";
              }
              break;
            case 1:
              v37 = (char *)gIconSocialHubStatAward_B_21;
              v62 = UFG::qStringHashUpper32("SOCIAL_HUB_BRONZE", 0xFFFFFFFF);
              v63 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v63
                || (v56 = (char *)v63->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v63->vfptr, v62)) == 0i64 )
              {
                v56 = "SOCIAL_HUB_BRONZE";
              }
              break;
          }
          v64 = UFG::OnlineManager::Instance();
          UFG::OnlineManager::GetOnlineName(v64, &v161);
          v65 = "Wei Shen";
          if ( v161.mLength )
            v65 = v161.mData;
          UFG::qStringCopy(displayName, 512, v65, -1);
          UFG::qString::~qString(&v161);
          UFG::qString::Set(&v111, displayName);
          v66 = UFG::qStringHashUpper32("SOCIAL_HUB_AWARDED_MESSAGE_FORMAT", 0xFFFFFFFF);
          v67 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v67
            || (v68 = (const char *)v67->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v67->vfptr, v66)) == 0i64 )
          {
            v68 = "SOCIAL_HUB_AWARDED_MESSAGE_FORMAT";
          }
          v69 = UFG::qString::FormatEx(&v175, v68, v56, v114.mData);
          UFG::qString::Set(&v112, v69->mData, v69->mLength, 0i64, 0);
          UFG::qString::~qString(&v175);
          goto LABEL_95;
        }
        if ( v49 == 3 )
        {
          UFG::qStringCopy(&dest, 256, *(const char **)(v10 + 112), *(_DWORD *)(v10 + 108));
          UFG::qStringCopy(&putf8str, 256, *(const char **)(v10 + 176), *(_DWORD *)(v10 + 172));
          Scaleform::UTF8Util::DecodeString(&pbuff, &dest, -1i64);
          Scaleform::UTF8Util::DecodeString(&v178, &putf8str, -1i64);
          v70 = UFG::OnlineManager::Instance();
          UFG::OnlineManager::GetOnlineName(v70, &v162);
          v71 = "Wei Shen";
          if ( v162.mLength )
            v71 = v162.mData;
          UFG::qStringCopy(displayName, 512, v71, -1);
          UFG::qString::~qString(&v162);
          UFG::qString::Set(&v111, displayName);
          v72 = UFG::qStringHashUpper32("SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT", 0xFFFFFFFF);
          v73 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v73
            || (v74 = (const char *)v73->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v73->vfptr, v72)) == 0i64 )
          {
            v74 = "SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT";
          }
          v75 = UFG::qString::FormatEx(&v169, v74, &dest, &putf8str, v114.mData, formatted.mData);
          UFG::qString::Set(&v112, v75->mData, v75->mLength, 0i64, 0);
          UFG::qString::~qString(&v169);
          v76 = UFG::OnlineId::ToString((UFG::OnlineId *)(v10 + 64), &v171);
          v77 = UFG::OnlineManager::Instance();
          v78 = UFG::OnlineManager::GetOnlineId(v77, &v107);
          v79 = UFG::OnlineId::ToString(v78, &v172);
          LOBYTE(v76) = UFG::qString::operator==(v79, v76);
          UFG::qString::~qString(&v172);
          v80 = v107.mPrev;
          v81 = v107.mNext;
          v107.mPrev->mNext = v107.mNext;
          v81->mPrev = v80;
          v107.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v107;
          v107.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v107;
          UFG::qString::~qString(&v171);
          v36 = (char *)gIconSocialHubAvatarFriend_21;
          if ( (_BYTE)v76 )
            v36 = (char *)gIconSocialHubAvatarPlayer_21;
          v37 = (char *)gIconSocialHubStatGame_21;
          goto LABEL_95;
        }
        if ( v49 != 4 )
          goto LABEL_95;
        UFG::qStringCopy(&putf8str, 256, *(const char **)(v10 + 112), *(_DWORD *)(v10 + 108));
        UFG::qStringCopy(&dest, 256, *(const char **)(v10 + 176), *(_DWORD *)(v10 + 172));
        Scaleform::UTF8Util::DecodeString(&v178, &putf8str, -1i64);
        Scaleform::UTF8Util::DecodeString(&pbuff, &dest, -1i64);
        v82 = UFG::UI::GetPlayerDisplayName();
        UFG::qString::Set(&v111, v82);
        v83 = UFG::qStringHashUpper32("SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT", 0xFFFFFFFF);
        v84 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v84
          || (v85 = (const char *)v84->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v84->vfptr, v83)) == 0i64 )
        {
          v85 = "SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT";
        }
        v86 = UFG::qString::FormatEx(&v164, v85, &putf8str, &dest, v114.mData, formatted.mData);
        UFG::qString::Set(&v112, v86->mData, v86->mLength, 0i64, 0);
        UFG::qString::~qString(&v164);
        v87 = UFG::OnlineId::ToString((UFG::OnlineId *)(v10 + 64), &v168);
        v88 = UFG::OnlineManager::Instance();
        v89 = UFG::OnlineManager::GetOnlineId(v88, &v108);
        v90 = UFG::OnlineId::ToString(v89, &v166);
        LOBYTE(v87) = (unsigned int)UFG::qStringCompare(v90->mData, v87->mData, -1) == 0;
        UFG::qString::~qString(&v166);
        v91 = v108.mPrev;
        v92 = v108.mNext;
        v108.mPrev->mNext = v108.mNext;
        v92->mPrev = v91;
        v108.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v108;
        v108.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v108;
        UFG::qString::~qString(&v168);
        if ( (_BYTE)v87 )
        {
          v36 = (char *)gIconSocialHubAvatarPlayer_21;
LABEL_94:
          v37 = (char *)gIconSocialHubChallenge_21;
LABEL_95:
          `eh vector constructor iterator'(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v93 = (double)*(signed int *)(v10 + 44);
          if ( (v117 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v116 + 16i64))(
              v116,
              &ptr,
              COERCE_DOUBLE(*(_QWORD *)&v118));
            v116 = 0i64;
          }
          v117 = 5;
          v118 = v93;
          if ( (v121 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v120 + 16i64))(
              v120,
              &v119,
              COERCE_DOUBLE(*(_QWORD *)&v122));
            v120 = 0i64;
          }
          v121 = 5;
          v122 = (double)v180;
          v94 = (double)*(signed int *)(v10 + 60);
          if ( (v125 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v124 + 16i64))(
              v124,
              &v123,
              COERCE_DOUBLE(*(_QWORD *)&v126));
            v124 = 0i64;
          }
          v125 = 5;
          v126 = v94;
          if ( (v129 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v128 + 16i64))(v128, &v127, v130);
            v128 = 0i64;
          }
          v129 = 6;
          v130 = v36;
          v95 = v111.mData;
          if ( (v133 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v132 + 16i64))(v132, &v131, v134);
            v132 = 0i64;
          }
          v133 = 6;
          v134 = v95;
          v96 = v110.mData;
          if ( (v137 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v136 + 16i64))(v136, &v135, v138);
            v136 = 0i64;
          }
          v137 = 6;
          v138 = v96;
          if ( (v141 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v140 + 16i64))(v140, &v139, v142);
            v140 = 0i64;
          }
          v141 = 6;
          v142 = v37;
          v97 = v112.mData;
          if ( (v145 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v144 + 16i64))(v144, &v143, v146);
            v144 = 0i64;
          }
          v145 = 6;
          v146 = v97;
          Scaleform::GFx::Movie::Invoke(v181, "SocialLogList_AddItem", 0i64, (Scaleform::GFx::Value *)&ptr, 8u);
          ++v179->mLHSItemCount;
          `eh vector destructor iterator'(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          goto LABEL_93;
        }
        v36 = (char *)gIconSocialHubAvatarFriend_ChallengeIncoming_21;
        if ( !v5 || *(_DWORD *)(v5 + 8) >= 0 )
          goto LABEL_94;
LABEL_93:
        UFG::qString::~qString(&formatted);
        UFG::qString::~qString(&v114);
        UFG::qString::~qString(&v112);
        UFG::qString::~qString(&v111);
        UFG::qString::~qString(&v110);
        v5 = 0i64;
LABEL_113:
        v10 = *(_QWORD *)(v10 + 24) - 24i64;
        v7 = v109;
        if ( v10 == v182 )
          goto LABEL_114;
      }
      v50 = UFG::OnlineManager::Instance();
      UFG::OnlineManager::GetOnlineName(v50, &v160);
      v51 = "Wei Shen";
      if ( v160.mLength )
        v51 = v160.mData;
      UFG::qStringCopy(displayName, 512, v51, -1);
      UFG::qString::~qString(&v160);
      UFG::qString::Set(&v111, displayName);
      v52 = UFG::qStringHashUpper32("SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT", 0xFFFFFFFF);
      v53 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v53
        || (v54 = (const char *)v53->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v53->vfptr, v52)) == 0i64 )
      {
        v54 = "SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT";
      }
      v55 = UFG::qString::FormatEx(&v167, v54, v114.mData, formatted.mData);
      UFG::qString::Set(&v112, v55->mData, v55->mLength, 0i64, 0);
      UFG::qString::~qString(&v167);
      v36 = (char *)gIconSocialHubAvatarPlayer_Challengeable_21;
      if ( *(_DWORD *)(v10 + 192) )
        v36 = (char *)gIconSocialHubAvatarPlayer_ChallengeOutgoing_21;
      switch ( v40->mCategory )
      {
        case 1u:
          v37 = (char *)gIconSocialHubStatGameGlow_21;
          break;
        case 2u:
          v37 = (char *)gIconSocialHubMission_21;
          break;
        case 3u:
          v37 = (char *)gIconSocialHubRace_21;
          break;
      }
      goto LABEL_95;
    }
LABEL_114:
    Scaleform::GFx::Movie::Invoke(v181, "SocialLogList_Refresh", 0i64, 0i64, 0);
  }
}

// File Line: 1143
// RVA: 0x5FCA80
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rdi
  Scaleform::GFx::Movie *v2; // rsi
  unsigned int v3; // ebx
  signed __int64 v4; // rbx
  const char *v5; // r14
  const char *v6; // r14
  double v7; // xmm6_8
  double v8; // xmm6_8
  char ptr; // [rsp+18h] [rbp-69h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-61h]
  __int64 v11; // [rsp+28h] [rbp-59h]
  unsigned int v12; // [rsp+30h] [rbp-51h]
  const char *v13; // [rsp+38h] [rbp-49h]
  char v14; // [rsp+48h] [rbp-39h]
  __int64 v15; // [rsp+58h] [rbp-29h]
  unsigned int v16; // [rsp+60h] [rbp-21h]
  double v17; // [rsp+68h] [rbp-19h]
  Scaleform::GFx::Value pval; // [rsp+78h] [rbp-9h]
  __int64 v19; // [rsp+A8h] [rbp+27h]

  v19 = -2i64;
  v1 = this;
  if ( this->mCurrentScreenType )
  {
    v2 = this->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "gLeaderboardId");
    v3 = (signed int)pval.mValue.NValue;
    UFG::UIHKScreenSocialHub::LoadTexturePack(v1, (signed int)pval.mValue.NValue);
    pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4 = v3;
    v5 = v1->mSocialHubProperties.p[v4].mLBD->mCaption.mData;
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = v5;
    Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsView_SetSubHeader", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = "-";
    Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsView_SetScore", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    v6 = v1->mSocialHubProperties.p[v4].mLBD->mDesc.mData;
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = v6;
    Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsView_SetDescription", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    v7 = v1->mSocialHubProperties.p[v4].mCopPercent;
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 5;
    v13 = *(const char **)&v7;
    v8 = v1->mSocialHubProperties.p[v4].mTriadPercent;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
        v15,
        &v14,
        COERCE_DOUBLE(*(_QWORD *)&v17));
      v15 = 0i64;
    }
    v16 = 5;
    v17 = v8;
    Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsView_SetMissionScore", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
  }
}

// File Line: 1176
// RVA: 0x5FC700
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsSocialAwardMedal(UFG::UIHKScreenSocialHub *this, UFG::OSuiteLeaderboardData *pLBD, int score)
{
  int v3; // esi
  UFG::OSuiteLeaderboardData *v4; // rbx
  Scaleform::GFx::Movie *v5; // r12
  UFG::StatGamePropertyManager *v6; // rax
  UFG::StatAwardPropertyData *v7; // rdi
  char *v8; // rbx
  unsigned int v9; // eax
  UFG::UIGfxTranslator *v10; // rcx
  const char *v11; // r15
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
  const char *v14; // r14
  unsigned int v15; // eax
  UFG::UIGfxTranslator *v16; // rcx
  const char *v17; // rsi
  char *v18; // rbx
  char *v19; // rbx
  char *v20; // rbx
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v22; // [rsp+40h] [rbp-A8h]
  unsigned int v23; // [rsp+48h] [rbp-A0h]
  char *v24; // [rsp+50h] [rbp-98h]
  char v25; // [rsp+60h] [rbp-88h]
  char *v26; // [rsp+68h] [rbp-80h]
  __int64 v27; // [rsp+70h] [rbp-78h]
  unsigned int v28; // [rsp+78h] [rbp-70h]
  __int64 v29; // [rsp+88h] [rbp-60h]
  unsigned int v30; // [rsp+90h] [rbp-58h]
  char *v31; // [rsp+98h] [rbp-50h]
  char v32; // [rsp+A8h] [rbp-40h]
  __int64 v33; // [rsp+B8h] [rbp-30h]
  unsigned int v34; // [rsp+C0h] [rbp-28h]
  char *v35; // [rsp+C8h] [rbp-20h]
  __int64 v36; // [rsp+D8h] [rbp-10h]
  UFG::qString v37; // [rsp+E0h] [rbp-8h]
  UFG::qString v38; // [rsp+108h] [rbp+20h]
  UFG::qString v39; // [rsp+130h] [rbp+48h]
  UFG::qString scoreStr; // [rsp+158h] [rbp+70h]
  UFG::qString v41; // [rsp+180h] [rbp+98h]
  UFG::qString v42; // [rsp+1A8h] [rbp+C0h]

  v36 = -2i64;
  v3 = score;
  v4 = pLBD;
  v5 = this->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    v6 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
    v7 = (UFG::StatAwardPropertyData *)UFG::StatGamePropertyManager::GetPropertyData(v6, v4);
    if ( v7 )
    {
      if ( v3 < v7->m_iGold )
      {
        if ( v3 < v7->m_iSilver )
        {
          v8 = "BRONZE";
          if ( v3 < v7->m_iBronze )
            v8 = &customWorldMapCaption;
        }
        else
        {
          v8 = "SILVER";
        }
      }
      else
      {
        v8 = "GOLD";
      }
      v9 = UFG::qStringHashUpper32("HUD_SOCIAL_AWARDFORBRONZE", 0xFFFFFFFF);
      v10 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v10
        || (v11 = (const char *)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v9)) == 0i64 )
      {
        v11 = "HUD_SOCIAL_AWARDFORBRONZE";
      }
      v12 = UFG::qStringHashUpper32("HUD_SOCIAL_AWARDFORSILVER", 0xFFFFFFFF);
      v13 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v13
        || (v14 = (const char *)v13->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v12)) == 0i64 )
      {
        v14 = "HUD_SOCIAL_AWARDFORSILVER";
      }
      v15 = UFG::qStringHashUpper32("HUD_SOCIAL_AWARDFORGOLD", 0xFFFFFFFF);
      v16 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v16
        || (v17 = (const char *)v16->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v16->vfptr, v15)) == 0i64 )
      {
        v17 = "HUD_SOCIAL_AWARDFORGOLD";
      }
      UFG::qString::qString(&scoreStr);
      UFG::qString::qString(&v38);
      UFG::qString::qString(&v41);
      UFG::StatAwardPropertyData::FormatScore(v7, &scoreStr, v7->m_iBronze);
      UFG::StatAwardPropertyData::FormatScore(v7, &v38, v7->m_iSilver);
      UFG::StatAwardPropertyData::FormatScore(v7, &v41, v7->m_iGold);
      UFG::qString::qString(&v37);
      UFG::qString::qString(&v42);
      UFG::qString::qString(&v39);
      UFG::qString::Format(&v37, v11, scoreStr.mData);
      UFG::qString::Format(&v42, v14, v38.mData);
      UFG::qString::Format(&v39, v17, v41.mData);
      `eh vector constructor iterator'(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v23 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v22 + 16i64))(v22, &ptr, v24);
        v22 = 0i64;
      }
      v23 = 6;
      v24 = v8;
      v18 = v37.mData;
      if ( (v28 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 16i64))(v27, &v25, v26);
        v27 = 0i64;
      }
      v28 = 6;
      v26 = v18;
      v19 = v42.mData;
      if ( (v30 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, char *))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
        v29 = 0i64;
      }
      v30 = 6;
      v31 = v19;
      v20 = v39.mData;
      if ( (v34 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v33 + 16i64))(v33, &v32, v35);
        v33 = 0i64;
      }
      v34 = 6;
      v35 = v20;
      Scaleform::GFx::Movie::Invoke(v5, "SocialHubRhsList_SetAwardIconDesc", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v39);
      UFG::qString::~qString(&v42);
      UFG::qString::~qString(&v37);
      UFG::qString::~qString(&v41);
      UFG::qString::~qString(&v38);
      UFG::qString::~qString(&scoreStr);
    }
  }
}

// File Line: 1221
// RVA: 0x5FC610
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsListHeader(UFG::UIHKScreenSocialHub *this, int leaderboardType)
{
  Scaleform::GFx::Movie *v2; // rdi
  char *v3; // rbx
  char ptr; // [rsp+38h] [rbp-40h]
  __int64 v5; // [rsp+48h] [rbp-30h]
  unsigned int v6; // [rsp+50h] [rbp-28h]
  char *v7; // [rsp+58h] [rbp-20h]

  v2 = this->mRenderable->m_movie.pObject;
  v3 = &customWorldMapCaption;
  if ( leaderboardType )
  {
    if ( leaderboardType == 1 )
      v3 = "$HUD_SOCIAL_GLOBALBOARD";
  }
  else
  {
    v3 = "$HUD_SOCIAL_FRIENDBOARD";
  }
  `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v6 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v5 + 16i64))(v5, &ptr, v7);
    v5 = 0i64;
  }
  v6 = 6;
  v7 = v3;
  Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsView_SetSubHeader2", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1240
// RVA: 0x5F54B0
void __fastcall UFG::UIHKScreenSocialHub::PopulateChallengeListAsync(UFG::UIHKScreenSocialHub *this, int screenType)
{
  UFG::UIHKScreenSocialHub *v2; // r14
  Scaleform::GFx::Movie *v3; // rbp
  unsigned int v4; // ebx
  int v5; // esi
  void (__fastcall *v6)(OSuite::fastdelegate::detail::GenericClass *); // rax
  signed __int64 v7; // rdi
  UFG::UIHKScreenSocialHub::SocialHubProperty *v8; // rbx
  UFG::OSuiteLeaderboardManager *v9; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::Value pval; // [rsp+48h] [rbp-50h]

  if ( !screenType )
  {
    v2 = this;
    this->mHandleMessageDisabled = 1;
    v3 = this->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v3, &pval, "gLeaderboardId");
    v4 = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v3, &pval, "gScore");
    v5 = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::Invoke(v3, "SocialHubTableLoadingIcon_Show", 0i64, 0i64, 0);
    v6 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::UIHKScreenSocialHub::PopulateChallengeListCallback )
      v6 = 0i64;
    callback.m_Closure.m_pFunction = v6;
    callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::UIHKScreenSocialHub::PopulateChallengeListCallback;
    v7 = v4;
    v8 = v2->mSocialHubProperties.p;
    v9 = UFG::OSuiteLeaderboardManager::Instance();
    if ( !UFG::OSuiteLeaderboardManager::GetChallengeFriends(v9, v8[v7].mLBD, v5, &callback) )
    {
      Scaleform::GFx::Movie::Invoke(v3, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
      UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries);
      UFG::UIHKScreenSocialHub::gCallPopulateChallengeList = 1;
    }
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
  }
}

// File Line: 1278
// RVA: 0x5F5610
void __fastcall UFG::UIHKScreenSocialHub::PopulateChallengeListCallback(OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZWebServiceClient *v2; // r14
  OSuite::SCallbackData *v3; // rsi
  int v4; // edi
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *i; // rbx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v6; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v7; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v8; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v9; // rax
  OSuite::ZOServiceOperationResult *v10; // rbx
  UFG::UIHKScreenSocialHub *v11; // rax
  OSuite::ZListBase *v12; // rbx
  unsigned __int64 v13; // r14
  unsigned __int64 v14; // rsi
  const char *v15; // r14
  char v16; // al
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v17; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v18; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v19; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v20; // rax
  char *v21; // rsi
  UFG::allocator::free_link *v22; // rbx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v23; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v24; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v25; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v26; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v27; // rax
  UFG::OSuiteManager *v28; // rax
  UFG::OnlineId id; // [rsp+28h] [rbp-D8h]
  UFG::OnlineFriend frnd; // [rsp+40h] [rbp-C0h]
  OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> result; // [rsp+A0h] [rbp-60h]
  __int64 v32; // [rsp+C0h] [rbp-40h]
  UFG::qString v33; // [rsp+C8h] [rbp-38h]
  UFG::qString text; // [rsp+F0h] [rbp-10h]

  v32 = -2i64;
  v2 = pWebServiceClient;
  v3 = pData;
  v4 = 0;
  for ( i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
        (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext )
  {
    v6 = i->mPrev;
    v7 = i->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString((UFG::qString *)&i[3].mNext);
    UFG::qString::~qString((UFG::qString *)&i[1]);
    v8 = i->mPrev;
    v9 = i->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  UFG::UIHKScreenSocialHub::gCallPopulateChallengeList = 1;
  if ( v3->Status.eError == HTTPERROR_OK
    && UFG::OSuiteManager::Instance()->m_bConnected
    && (v10 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOServiceOperationResult>(v2, &v3->URL)) != 0i64 )
  {
    v11 = (UFG::UIHKScreenSocialHub *)UFG::UIScreenManagerBase::getScreen(
                                        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                        "SocialHub");
    if ( v11 )
    {
      UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v11);
      OSuite::ZOServiceOperationResult::Values(v10, &result);
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd((OSuite::ZListBase::ZListIteratorBase *)&result.m_iterator.vfptr) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_iterator.m_pListBase);
        v12 = result.m_iterator.m_pListBase;
        v13 = result.m_iterator.m_nIndex;
        v14 = result.m_iterator.m_nIndex + 1;
        OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
          (OSuite::TList<OSuite::ZServiceOperationValue *> *)result.m_iterator.m_pListBase,
          result.m_iterator.m_nIndex + 1);
        if ( v13 >= v12->m_nTop )
          v12->m_nTop = v14;
        v15 = OSuite::ZString::c_str((OSuite::ZString *)(*(_QWORD *)(v12[1].m_nSize + 8 * v13) + 160i64));
        frnd.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
        frnd.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
        frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
        frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
        frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
        frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = __PAIR__(
                                                               HIDWORD(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits),
                                                               0) & 0xFF0FFFFF00000000ui64;
        HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
        *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
        UFG::qString::qString(&frnd.m_sOnlineName);
        id.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
        id.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
        id.m_SteamId.m_steamid.m_unAll64Bits = __PAIR__(HIDWORD(id.m_SteamId.m_steamid.m_unAll64Bits), 0) & 0xFF0FFFFF00000000ui64;
        HIBYTE(id.m_SteamId.m_steamid.m_unAll64Bits) = 0;
        *((_DWORD *)&id.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
        id.m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(v15, 0i64);
        v16 = UFG::OnlineFriendManager::FindFriend(&frnd, &id);
        v17 = id.mPrev;
        v18 = id.mNext;
        id.mPrev->mNext = id.mNext;
        v18->mPrev = v17;
        id.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
        id.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
        if ( v16 )
        {
          v21 = frnd.m_sOnlineName.mData;
          v22 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
          if ( v22 )
          {
            UFG::qString::qString(&v33, v21);
            UFG::qString::qString(&text, v15);
            v4 |= 3u;
            v22->mNext = v22;
            v22[1].mNext = v22;
            UFG::qString::qString((UFG::qString *)&v22[2], &text);
            UFG::qString::qString((UFG::qString *)&v22[7], &v33);
            LODWORD(v22[12].mNext) = 0;
          }
          else
          {
            v22 = 0i64;
          }
          v23 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev;
          UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev->mNext = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)v22;
          v22->mNext = (UFG::allocator::free_link *)v23;
          v22[1].mNext = (UFG::allocator::free_link *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
          UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)v22;
          if ( v4 & 2 )
          {
            v4 &= 0xFFFFFFFD;
            UFG::qString::~qString(&text);
          }
          if ( v4 & 1 )
          {
            v4 &= 0xFFFFFFFE;
            UFG::qString::~qString(&v33);
          }
          frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
          UFG::qString::~qString(&frnd.m_sOnlineName);
          v24 = frnd.m_cOnlineId.mPrev;
          v25 = frnd.m_cOnlineId.mNext;
          frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
          v25->mPrev = v24;
          frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
          frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
        }
        else
        {
          frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
          UFG::qString::~qString(&frnd.m_sOnlineName);
          v19 = frnd.m_cOnlineId.mPrev;
          v20 = frnd.m_cOnlineId.mNext;
          frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
          v20->mPrev = v19;
          frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
          frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
        }
        v26 = frnd.mPrev;
        v27 = frnd.mNext;
        frnd.mPrev->mNext = frnd.mNext;
        v27->mPrev = v26;
        frnd.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
        frnd.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
        OSuite::ZListBase::ZListIteratorBase::Next((OSuite::ZListBase::ZListIteratorBase *)&result.m_iterator.vfptr);
      }
      result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int>::`vftable';
      result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable';
    }
  }
  else
  {
    v28 = UFG::OSuiteManager::Instance();
    UFG::OSuiteManager::Disconnect(v28);
    UFG::UIHKScreenSocialHub::gLastOSuiteErrorTime = (unsigned __int64)((UFG::qGetSystemTimeUTC() - 116444736000000000i64)
                                                                      * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11;
  }
}

// File Line: 1329
// RVA: 0x5F5200
void __fastcall UFG::UIHKScreenSocialHub::PopulateChallengeList(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rsi
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *v2; // rbx
  int *v3; // rax
  int *v4; // rbp
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  unsigned int v8; // er14
  int score; // er15
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *i; // rdi
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v13; // rcx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v14; // rax
  const char *v15; // rdi
  const char *v16; // r8
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  UFG::qString v19; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::Value pval; // [rsp+70h] [rbp-58h]

  v1 = this;
  v2 = &this->mChallengeDialogPopupEntries;
  v3 = (int *)&this->mChallengeDialogPopupEntries.mNode.mNext[-1].mNext;
  v4 = &this->mLastListTouchedByMouse;
  if ( v3 != &this->mLastListTouchedByMouse )
  {
    do
    {
      v5 = v3 + 2;
      v6 = *((_QWORD *)v3 + 1);
      v7 = (_QWORD *)*((_QWORD *)v3 + 2);
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      *v5 = v5;
      v5[1] = v5;
      if ( v5 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v5 - 1))(v5 - 1, 1i64);
      v3 = (int *)&v2->mNode.mNext[-1].mNext;
    }
    while ( v3 != v4 );
  }
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1->mRenderable->m_movie.pObject, &pval, "gLeaderboardId");
  v8 = (signed int)pval.mValue.NValue;
  Scaleform::GFx::Movie::GetVariable(v1->mRenderable->m_movie.pObject, &pval, "gScore");
  score = (signed int)pval.mValue.NValue;
  for ( i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
        i != (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        i = i->mNext )
  {
    v11 = UFG::qMalloc(0x78ui64, "UIHKScreenSocialHub", 0i64);
    if ( v11 )
      UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry::ChallengeDialogPopupEntry(
        (UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry *)v11,
        (UFG::qString *)&i[1],
        (UFG::qString *)&i[3].mNext,
        v1->mSocialHubProperties.p[v8].mLBD->mLeaderboardId,
        score);
    else
      v12 = 0i64;
    v13 = (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *)(v12 + 8);
    v14 = v2->mNode.mPrev;
    v14->mNext = v13;
    v13->mPrev = v14;
    v13->mNext = &v2->mNode;
    v2->mNode.mPrev = v13;
  }
  if ( (int *)&v2->mNode.mNext[-1].mNext == v4 )
  {
    UFG::qString::qString(&v19, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$HUD_SOCIAL_NOFRIEND",
      v19.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v19);
  }
  else
  {
    v15 = v1->mSocialHubProperties.p[v8].mLBD->mCaption.mData;
    if ( v15 )
    {
      if ( *v15 == 36 )
        ++v15;
      v17 = UFG::qStringHashUpper32(v15, 0xFFFFFFFF);
      v18 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v18
        || (v16 = (const char *)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0i64 )
      {
        v16 = v15;
      }
    }
    else
    {
      v16 = 0i64;
    }
    UFG::UIHKScreenDialogPopup::createDialog(
      (UFG::UIScreen *)&v1->vfptr,
      v2,
      v16,
      UI_HASH_CHALLENGE_BUTTON_ACCEPTED,
      UI_HASH_CHALLENGE_BUTTON_CANCELED);
    v1->mDisplayingChallengeDialog = 1;
  }
  v1->mHandleMessageDisabled = 0;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
}ectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
 

// File Line: 1373
// RVA: 0x5FBF10
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsListAsync(UFG::UIHKScreenSocialHub *this, int screenType, int leaderboardType)
{
  UFG::UIHKScreenSocialHub *v3; // r14
  UFG::UIScreenRenderable *v4; // rax
  Scaleform::GFx::Movie *v5; // rdi
  Scaleform::GFx::Movie *v6; // rcx
  unsigned int v7; // ebx
  hkgpIndexedMeshDefinitions::Edge *v8; // rdx
  bool v9; // r13
  UFG::OnlineManager *v10; // rax
  _BOOL8 v11; // r12
  UFG::OnlineManager *v12; // rax
  bool v13; // al
  bool v14; // r15
  int v15; // eax
  void (__fastcall *v16)(OSuite::fastdelegate::detail::GenericClass *); // rax
  signed __int64 v17; // rdi
  UFG::UIHKScreenSocialHub::SocialHubProperty *v18; // rbx
  UFG::OSuiteLeaderboardManager *v19; // rax
  void (__fastcall *v20)(OSuite::fastdelegate::detail::GenericClass *); // rax
  signed __int64 v21; // rdi
  UFG::UIHKScreenSocialHub::SocialHubProperty *v22; // rbx
  UFG::OSuiteLeaderboardManager *v23; // rax
  signed __int64 v24; // r12
  UFG::qSymbol *v25; // rbx
  UFG::GameStatTracker *v26; // rax
  int v27; // ebx
  char *v28; // rbx
  int v29; // edx
  hkGeometryUtils::IVertices *v30; // rcx
  int v31; // er8
  const char *v32; // rbx
  unsigned int v33; // eax
  char ptr; // [rsp+8h] [rbp-79h]
  __int64 v35; // [rsp+18h] [rbp-69h]
  unsigned int numArgs[2]; // [rsp+20h] [rbp-61h]
  const char *v37; // [rsp+28h] [rbp-59h]
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-49h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v39; // [rsp+68h] [rbp-19h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+78h] [rbp-9h]
  UFG::qString formatted; // [rsp+88h] [rbp+7h]
  __int64 v42; // [rsp+B0h] [rbp+2Fh]
  bool v43; // [rsp+F0h] [rbp+6Fh]

  v42 = -2i64;
  v3 = this;
  v4 = this->mRenderable;
  v5 = v4->m_movie.pObject;
  v6 = v4->m_movie.pObject;
  numArgs[0] = 0;
  if ( !screenType )
  {
    Scaleform::GFx::Movie::Invoke(v6, "SocialHubLoadingIcon_Hide", 0i64, 0i64, numArgs[0]);
    return;
  }
  Scaleform::GFx::Movie::Invoke(v6, "SocialHubRhsList_ClearItem", 0i64, 0i64, numArgs[0]);
  Scaleform::GFx::Movie::Invoke(v5, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v5, &pval, "gLeaderboardId");
  v7 = (signed int)pval.mValue.NValue;
  v9 = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, v8);
  v10 = UFG::OnlineManager::Instance();
  v43 = UFG::OnlineManager::IsNetworkAvailable(v10);
  v11 = UFG::OSuiteManager::Instance()->m_bConnected;
  v12 = UFG::OnlineManager::Instance();
  v13 = UFG::OnlineManager::IsNetworkAvailable(v12);
  v14 = v13;
  if ( !v43 || !(_BYTE)v11 || v9 || !v13 )
  {
    *(_QWORD *)numArgs = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v24 = v7;
    v25 = (UFG::qSymbol *)v3->mSocialHubProperties.p[v7].mLBD;
    v26 = UFG::GameStatTracker::Instance();
    v27 = UFG::GameStatTracker::GetStat(v26, LeaderboardScoreIntList, v25 + 12);
    UFG::qString::qString(&formatted);
    if ( v27 )
      UFG::UIHKScreenSocialHub::FormatScore(v3, &formatted, v3->mSocialHubProperties.p[v24].mLBD, v27);
    else
      UFG::qString::Set(&formatted, "-");
    v28 = formatted.mData;
    if ( (numArgs[0] >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v35 + 16i64))(v35, &ptr, v37);
      v35 = 0i64;
    }
    v37 = v28;
    Scaleform::GFx::Movie::Invoke(v5, "SocialHubRhsView_SetScore", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v30, v29, v31) )
    {
      v33 = numArgs[0] >> 6;
      if ( v43 )
      {
        if ( v14 )
        {
          if ( v33 & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v35 + 16i64))(v35, &ptr, v37);
            v35 = 0i64;
          }
          v37 = "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW";
          goto LABEL_34;
        }
        v32 = gNetworkDisconnectedMessage;
      }
      else
      {
        v32 = gFirstPartySignedOut;
      }
    }
    else
    {
      v32 = gSocialHubNoOnlineAccountMessage;
      v33 = numArgs[0] >> 6;
    }
    if ( v33 & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v35 + 16i64))(v35, &ptr, v37);
      v35 = 0i64;
    }
    v37 = v32;
LABEL_34:
    numArgs[0] = 6;
    if ( v9 )
    {
      numArgs[0] = 6;
      v37 = gSocialHubParentalControlsMessage;
    }
    Scaleform::GFx::Movie::Invoke(v5, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v5, "SocialHubRhsList_SetErrorMessage", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    Scaleform::GFx::Movie::Invoke(v5, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
    UFG::qString::~qString(&formatted);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_37;
  }
  v3->mHandleMessageDisabled = 1;
  v15 = v3->mCurrentLeaderboardType;
  if ( v15 )
  {
    if ( v15 == 1 )
    {
      v20 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
      if ( !UFG::UIHKScreenSocialHub::PopulateRhsListCallback )
        v20 = 0i64;
      v39.m_Closure.m_pFunction = v20;
      v39.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::UIHKScreenSocialHub::PopulateRhsListCallback;
      v21 = v7;
      v22 = v3->mSocialHubProperties.p;
      v23 = UFG::OSuiteLeaderboardManager::Instance();
      if ( !UFG::OSuiteLeaderboardManager::GetResultGlobal(v23, v22[v21].mLBD, &v39) )
      {
        UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries);
        UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 1;
      }
    }
  }
  else
  {
    v16 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::UIHKScreenSocialHub::PopulateRhsListCallback )
      v16 = 0i64;
    callback.m_Closure.m_pFunction = v16;
    callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::UIHKScreenSocialHub::PopulateRhsListCallback;
    v17 = v7;
    v18 = v3->mSocialHubProperties.p;
    v19 = UFG::OSuiteLeaderboardManager::Instance();
    if ( !UFG::OSuiteLeaderboardManager::GetResultFriends(v19, v18[v17].mLBD, &callback) )
    {
      UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries);
      UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 1;
    }
  }
LABEL_37:
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
}

// File Line: 1472
// RVA: 0x5FC310
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsListCallback(OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZWebServiceClient *v2; // r14
  OSuite::SCallbackData *v3; // rdi
  int v4; // esi
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *i; // rbx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v6; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v7; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v8; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v9; // rax
  OSuite::ZOFeed *v10; // r13
  UFG::UIHKScreenSocialHub *v11; // rax
  int v12; // er15
  int j; // er14
  OSuite::ZAtomEntry *v14; // rbx
  OSuite::ZOEntry *v15; // rdi
  OSuite::ZOProperty *v16; // rax
  OSuite::ZOProperty *v17; // rax
  OSuite::ZOProperty *v18; // rax
  const char *v19; // rbx
  const char *v20; // r12
  UFG::allocator::free_link *v21; // rdi
  int v22; // ebx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v23; // rax
  UFG::OSuiteManager *v24; // rax
  OSuite::ZString v25; // [rsp+28h] [rbp-61h]
  OSuite::ZString outValue; // [rsp+40h] [rbp-49h]
  __int64 v27; // [rsp+58h] [rbp-31h]
  UFG::qString text; // [rsp+60h] [rbp-29h]
  UFG::qString v29; // [rsp+88h] [rbp-1h]
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v30; // [rsp+F0h] [rbp+67h]
  UFG::allocator::free_link *v31; // [rsp+100h] [rbp+77h]

  v27 = -2i64;
  v2 = pWebServiceClient;
  v3 = pData;
  v4 = 0;
  for ( i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
        (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext )
  {
    v6 = i->mPrev;
    v7 = i->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    i->mPrev = i;
    i->mNext = i;
    v30 = i;
    UFG::qString::~qString((UFG::qString *)&i[3].mNext);
    UFG::qString::~qString((UFG::qString *)&i[1]);
    v8 = i->mPrev;
    v9 = i->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  if ( v3->Status.eError == HTTPERROR_OK
    && UFG::OSuiteManager::Instance()->m_bConnected
    && (v10 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(v2, &v3->URL)) != 0i64 )
  {
    v11 = (UFG::UIHKScreenSocialHub *)UFG::UIScreenManagerBase::getScreen(
                                        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                        "SocialHub");
    if ( !v11 )
      return;
    UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v11);
    v12 = OSuite::ZAtomFeed::TotalEntries((OSuite::ZAtomFeed *)&v10->vfptr);
    for ( j = 0; j < v12; ++j )
    {
      v14 = OSuite::ZAtomFeed::GetEntry((OSuite::ZAtomFeed *)&v10->vfptr, j);
      v15 = 0i64;
      if ( v14->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v14->vfptr, OSuite::ZOEntry::s_nClassId) )
        v15 = (OSuite::ZOEntry *)v14;
      LODWORD(v30) = 0;
      OSuite::ZString::ZString(&outValue);
      OSuite::ZString::ZString(&v25);
      v16 = OSuite::ZOEntry::Property(v15, "s_Pid");
      OSuite::ZOProperty::GetValue(v16, &outValue);
      v17 = OSuite::ZOEntry::Property(v15, "i32_Score");
      OSuite::ZOProperty::GetValue(v17, (int *)&v30);
      v18 = OSuite::ZOEntry::Property(v15, "s_Name");
      OSuite::ZOProperty::GetValue(v18, &v25);
      v19 = OSuite::ZString::c_str(&outValue);
      v20 = OSuite::ZString::c_str(&v25);
      if ( v19 )
      {
        v21 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
        v31 = v21;
        if ( v21 )
        {
          UFG::qString::qString(&v29, v20);
          UFG::qString::qString(&text, v19);
          v4 |= 3u;
          v22 = (signed int)v30;
          v21->mNext = v21;
          v21[1].mNext = v21;
          UFG::qString::qString((UFG::qString *)&v21[2], &text);
          UFG::qString::qString((UFG::qString *)&v21[7], &v29);
          LODWORD(v21[12].mNext) = v22;
        }
        else
        {
          v21 = 0i64;
        }
        v23 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev;
        UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev->mNext = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)v21;
        v21->mNext = (UFG::allocator::free_link *)v23;
        v21[1].mNext = (UFG::allocator::free_link *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)v21;
        if ( v4 & 2 )
        {
          v4 &= 0xFFFFFFFD;
          UFG::qString::~qString(&text);
        }
        if ( v4 & 1 )
        {
          v4 &= 0xFFFFFFFE;
          UFG::qString::~qString(&v29);
        }
      }
      OSuite::ZString::~ZString(&v25);
      OSuite::ZString::~ZString(&outValue);
    }
  }
  else
  {
    v24 = UFG::OSuiteManager::Instance();
    UFG::OSuiteManager::Disconnect(v24);
    UFG::UIHKScreenSocialHub::gLastOSuiteErrorTime = (unsigned __int64)((UFG::qGetSystemTimeUTC() - 116444736000000000i64)
                                                                      * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11;
  }
  UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 1;
}

// File Line: 1636
// RVA: 0x61C760
void __fastcall UFG::UIHKScreenSocialHub::UpdateOnlineName(UFG::UIHKScreenSocialHub *this)
{
  hkgpIndexedMeshDefinitions::Edge *v1; // rdx
  Scaleform::GFx::Movie *v2; // rdi
  bool v3; // si
  UFG::OnlineManager *v4; // rax
  bool v5; // bl
  bool v6; // bl
  const char *v7; // rbx
  UFG::OnlineManager *v8; // rax
  char *v9; // rbx
  char ptr; // [rsp+28h] [rbp-69h]
  __int64 v11; // [rsp+38h] [rbp-59h]
  unsigned int v12; // [rsp+40h] [rbp-51h]
  __int64 v13; // [rsp+48h] [rbp-49h]
  char v14; // [rsp+58h] [rbp-39h]
  __int64 v15; // [rsp+68h] [rbp-29h]
  unsigned int v16; // [rsp+70h] [rbp-21h]
  const char *v17; // [rsp+78h] [rbp-19h]
  char v18; // [rsp+88h] [rbp-9h]
  __int64 v19; // [rsp+98h] [rbp+7h]
  unsigned int v20; // [rsp+A0h] [rbp+Fh]
  char *v21; // [rsp+A8h] [rbp+17h]
  __int64 v22; // [rsp+B8h] [rbp+27h]
  UFG::qString result; // [rsp+C0h] [rbp+2Fh]

  v22 = -2i64;
  v2 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v2 )
  {
    v3 = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, v1);
    v4 = UFG::OnlineManager::Instance();
    v5 = UFG::OnlineManager::IsNetworkSignedIn(v4);
    `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v6 = v5 && !v3;
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 2;
    LOBYTE(v13) = v6;
    v7 = gIconSocialHubAvatarPlayer_21;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
      v15 = 0i64;
    }
    v16 = 6;
    v17 = v7;
    v8 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetOnlineName(v8, &result);
    v9 = result.mData;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = 6;
    v21 = v9;
    Scaleform::GFx::Movie::Invoke(v2, "SetIsOnline", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    UFG::qString::~qString(&result);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 1658
// RVA: 0x5FADF0
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsList(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // r13
  signed int v2; // er15
  UFG::UIScreenRenderable *v3; // rax
  Scaleform::GFx::Movie *v4; // rdi
  unsigned int v5; // er12
  int v6; // ecx
  UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *v7; // rax
  UFG::qSymbol *v8; // rbx
  UFG::GameStatTracker *v9; // rax
  int v10; // esi
  UFG::OnlineManager *v11; // r14
  UFG::allocator::free_link *v12; // rdi
  UFG::qString *v13; // rbx
  UFG::OnlineId *v14; // rax
  UFG::qString *v15; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v16; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v17; // rbx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v18; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v19; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v20; // rax
  UFG::OnlineManager *v21; // rax
  UFG::qSymbol *v22; // rbx
  UFG::GameStatTracker *v23; // rax
  int v24; // er12
  char v25; // r14
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v26; // rsi
  const char *v27; // rcx
  bool v28; // dl
  __int64 *v29; // rcx
  __int64 **v30; // rax
  int v31; // eax
  UFG::allocator::free_link *v32; // rax
  __int64 v33; // rdi
  int v34; // ebx
  __int64 *v35; // rax
  UFG::allocator::free_link *v36; // rdi
  UFG::OnlineManager *v37; // rax
  UFG::qString *v38; // rbx
  UFG::OnlineManager *v39; // rax
  UFG::OnlineId *v40; // rax
  UFG::qString *v41; // rax
  __int64 *v42; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v43; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v44; // rax
  UFG::qSymbol *v45; // rbx
  UFG::GameStatTracker *v46; // rax
  bool (__fastcall *v47)(UFG::UIHKScreenSocialHub::LeaderboardEntry *, UFG::UIHKScreenSocialHub::LeaderboardEntry *); // r14
  __int64 *v48; // rsi
  __int64 *v49; // rbx
  __int64 *v50; // rdi
  __int64 v51; // rdx
  __int64 **v52; // r8
  __int64 *v53; // rax
  __int64 v54; // rcx
  __int64 *v55; // rax
  __int64 **v56; // rax
  __int64 v57; // rax
  __int64 *v58; // rdi
  __int64 v59; // rdx
  __int64 **v60; // r8
  __int64 *v61; // rax
  __int64 v62; // rcx
  __int64 *v63; // rax
  __int64 **v64; // rax
  __int64 v65; // rax
  unsigned int v66; // esi
  __int64 **v67; // rdi
  int v68; // ebx
  char v69; // dl
  __int64 *v70; // rcx
  __int64 **v71; // rax
  __int64 v72; // rax
  int v73; // eax
  bool v74; // dl
  __int64 *v75; // rcx
  __int64 **v76; // rax
  UFG::CachedLeaderboard::EntryType v77; // ebx
  const char *v78; // rcx
  char v79; // al
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v80; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v81; // rcx
  int v82; // eax
  int *v83; // rbx
  UFG::CachedLeaderboardManager *v84; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v85; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v86; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v87; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v88; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v89; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v90; // rax
  bool v91; // dl
  __int64 *v92; // rcx
  __int64 **v93; // rax
  UFG::OnlineManager *v94; // rax
  UFG::qString *v95; // rax
  char *v96; // rbx
  char *v97; // rbx
  const char *v98; // rbx
  __int64 *v99; // rcx
  __int64 **v100; // rax
  __int64 v101; // rbx
  char *v102; // rbx
  char *v103; // rbx
  char *i; // rbx
  __int64 v105; // rcx
  _QWORD *v106; // rax
  __int64 v107; // rdx
  _QWORD *v108; // rax
  __int64 *v109; // rcx
  _QWORD *v110; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v111; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v112; // rax
  __int64 *v113; // [rsp+38h] [rbp-C8h]
  void *mem; // [rsp+40h] [rbp-C0h]
  UFG::OnlineId id; // [rsp+48h] [rbp-B8h]
  __int64 *v116; // [rsp+60h] [rbp-A0h]
  __int64 **v117; // [rsp+68h] [rbp-98h]
  unsigned __int64 v118; // [rsp+70h] [rbp-90h]
  __int64 *v119; // [rsp+78h] [rbp-88h]
  __int64 **v120; // [rsp+80h] [rbp-80h]
  unsigned __int64 v121; // [rsp+88h] [rbp-78h]
  __int64 *v122; // [rsp+90h] [rbp-70h]
  __int64 **v123; // [rsp+98h] [rbp-68h]
  unsigned __int64 v124; // [rsp+A0h] [rbp-60h]
  __int64 *v125; // [rsp+A8h] [rbp-58h]
  __int64 **v126; // [rsp+B0h] [rbp-50h]
  unsigned __int64 v127; // [rsp+B8h] [rbp-48h]
  __int64 *v128; // [rsp+C0h] [rbp-40h]
  __int64 **v129; // [rsp+C8h] [rbp-38h]
  unsigned __int64 v130; // [rsp+D0h] [rbp-30h]
  UFG::OnlineId v131; // [rsp+D8h] [rbp-28h]
  UFG::OnlineFriend frnd; // [rsp+F0h] [rbp-10h]
  char ptr; // [rsp+150h] [rbp+50h]
  __int64 v134; // [rsp+160h] [rbp+60h]
  unsigned int v135; // [rsp+168h] [rbp+68h]
  const char *v136; // [rsp+170h] [rbp+70h]
  UFG::OnlineId v137; // [rsp+180h] [rbp+80h]
  UFG::OnlineId v138; // [rsp+198h] [rbp+98h]
  UFG::OnlineId *v139; // [rsp+1B0h] [rbp+B0h]
  unsigned __int64 v140; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::Value pval; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::Value v142; // [rsp+1F0h] [rbp+F0h]
  UFG::qString v143; // [rsp+220h] [rbp+120h]
  Scaleform::GFx::Value pargs; // [rsp+250h] [rbp+150h]
  char v145; // [rsp+280h] [rbp+180h]
  __int64 v146; // [rsp+290h] [rbp+190h]
  unsigned int v147; // [rsp+298h] [rbp+198h]
  char *v148; // [rsp+2A0h] [rbp+1A0h]
  char v149; // [rsp+2B0h] [rbp+1B0h]
  __int64 v150; // [rsp+2C0h] [rbp+1C0h]
  unsigned int v151; // [rsp+2C8h] [rbp+1C8h]
  const char *v152; // [rsp+2D0h] [rbp+1D0h]
  char v153; // [rsp+2E0h] [rbp+1E0h]
  __int64 v154; // [rsp+2F0h] [rbp+1F0h]
  unsigned int v155; // [rsp+2F8h] [rbp+1F8h]
  __int64 v156; // [rsp+300h] [rbp+200h]
  char v157; // [rsp+310h] [rbp+210h]
  __int64 v158; // [rsp+320h] [rbp+220h]
  unsigned int v159; // [rsp+328h] [rbp+228h]
  char *v160; // [rsp+330h] [rbp+230h]
  UFG::CachedLeaderboard::Entry entry; // [rsp+340h] [rbp+240h]
  UFG::qString formatted; // [rsp+3A0h] [rbp+2A0h]
  unsigned __int64 v163; // [rsp+3C8h] [rbp+2C8h]
  unsigned __int64 v164; // [rsp+3D0h] [rbp+2D0h]
  UFG::OnlineId *v165; // [rsp+3D8h] [rbp+2D8h]
  unsigned __int64 v166; // [rsp+3E0h] [rbp+2E0h]
  __int64 v167; // [rsp+3E8h] [rbp+2E8h]
  UFG::qString v168; // [rsp+3F0h] [rbp+2F0h]
  UFG::qString v169; // [rsp+418h] [rbp+318h]
  UFG::qString v170; // [rsp+440h] [rbp+340h]
  UFG::qString v171; // [rsp+468h] [rbp+368h]
  UFG::qString v172; // [rsp+490h] [rbp+390h]
  UFG::qString v173; // [rsp+4B8h] [rbp+3B8h]
  UFG::qString v174; // [rsp+4E0h] [rbp+3E0h]
  UFG::qString result; // [rsp+508h] [rbp+408h]
  int v176; // [rsp+580h] [rbp+480h]
  signed __int64 v177; // [rsp+588h] [rbp+488h]
  Scaleform::GFx::Movie *v178; // [rsp+590h] [rbp+490h]

  v167 = -2i64;
  v1 = this;
  v2 = 0;
  v3 = this->mRenderable;
  v4 = v3->m_movie.pObject;
  v178 = v3->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v4, &pval, "gLeaderboardId");
  v5 = (signed int)pval.mValue.NValue;
  v6 = 0;
  v7 = (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
  if ( (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext == &UFG::UIHKScreenSocialHub::gLeaderboardEntries )
    goto LABEL_115;
  do
  {
    ++v6;
    v7 = (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)v7->mNode.mNext;
  }
  while ( v7 != &UFG::UIHKScreenSocialHub::gLeaderboardEntries );
  if ( !v6 )
  {
LABEL_115:
    v8 = (UFG::qSymbol *)v1->mSocialHubProperties.p[v5].mLBD;
    v9 = UFG::GameStatTracker::Instance();
    v10 = UFG::GameStatTracker::GetStat(v9, LeaderboardScoreIntList, v8 + 12);
    if ( !v10 )
    {
      `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v135 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v134 + 16i64))(v134, &ptr, v136);
        v134 = 0i64;
      }
      v135 = 6;
      v136 = "-";
      Scaleform::GFx::Movie::Invoke(v4, "SocialHubRhsView_SetScore", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
      if ( (v135 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v134 + 16i64))(v134, &ptr, v136);
        v134 = 0i64;
      }
      v135 = 6;
      v136 = "$HUD_SOCIAL_NOENTRY";
      Scaleform::GFx::Movie::Invoke(v4, "SocialHubRhsList_SetErrorMessage", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
      Scaleform::GFx::Movie::Invoke(v4, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
      v1->mHandleMessageDisabled = 0;
      Scaleform::GFx::Movie::Invoke(v4, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      goto LABEL_111;
    }
    v11 = UFG::OnlineManager::Instance();
    v12 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
    if ( v12 )
    {
      v13 = UFG::OnlineManager::GetOnlineName(v11, &result);
      v14 = UFG::OnlineManager::GetOnlineId(v11, &v137);
      v15 = UFG::OnlineId::ToString(v14, &v170);
      v2 = 7;
      UFG::UIHKScreenSocialHub::LeaderboardEntry::LeaderboardEntry(
        (UFG::UIHKScreenSocialHub::LeaderboardEntry *)v12,
        v15,
        v13,
        v10);
      v17 = v16;
    }
    else
    {
      v17 = 0i64;
    }
    if ( v2 & 4 )
    {
      v2 &= 0xFFFFFFFB;
      UFG::qString::~qString(&v170);
    }
    if ( v2 & 2 )
    {
      v2 &= 0xFFFFFFFD;
      v18 = v137.mPrev;
      v19 = v137.mNext;
      v137.mPrev->mNext = v137.mNext;
      v19->mPrev = v18;
      v137.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v137;
      v137.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v137;
    }
    if ( v2 & 1 )
    {
      v2 &= 0xFFFFFFFE;
      UFG::qString::~qString(&result);
    }
    v20 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev;
    UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev->mNext = v17;
    v17->mPrev = v20;
    v17->mNext = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
    UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev = v17;
  }
  v21 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::GetOnlineId(v21, &v131);
  v113 = (__int64 *)&v113;
  mem = &v113;
  v177 = v5;
  v22 = (UFG::qSymbol *)v1->mSocialHubProperties.p[v5].mLBD;
  v23 = UFG::GameStatTracker::Instance();
  v24 = UFG::GameStatTracker::GetStat(v23, LeaderboardScoreIntList, v22 + 12);
  v176 = v24;
  v25 = 0;
  v26 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
  if ( (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries )
  {
    do
    {
      v27 = (const char *)v26[2].mNext;
      v125 = (__int64 *)&v125;
      v126 = &v125;
      v127 &= 0xFF0FFFFF00000000ui64;
      HIBYTE(v127) = 0;
      HIDWORD(v127) &= 0xFFF00000;
      v127 = UFG::qToUInt64(v27, 0i64);
      v28 = v127 == v131.m_SteamId.m_steamid.m_unAll64Bits;
      v29 = v125;
      v30 = v126;
      v125[1] = (__int64)v126;
      *v30 = v29;
      v125 = (__int64 *)&v125;
      v126 = &v125;
      if ( v28 )
      {
        if ( v1->mCurrentScreenType == 4 )
        {
          if ( v24 > 0 )
          {
            v31 = (int)v26[6].mPrev;
            if ( v31 > 0 && v24 > v31 )
            {
              v25 = 1;
              v24 = (int)v26[6].mPrev;
            }
          }
        }
        else if ( v24 < SLODWORD(v26[6].mPrev) )
        {
          v25 = 1;
          v24 = (int)v26[6].mPrev;
        }
      }
      else
      {
        v32 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
        v33 = (__int64)v32;
        if ( v32 )
        {
          v34 = (int)v26[6].mPrev;
          v32->mNext = v32;
          v32[1].mNext = v32;
          UFG::qString::qString((UFG::qString *)&v32[2], (UFG::qString *)&v26[1]);
          UFG::qString::qString((UFG::qString *)(v33 + 56), (UFG::qString *)&v26[3].mNext);
          *(_DWORD *)(v33 + 96) = v34;
        }
        else
        {
          v33 = 0i64;
        }
        v35 = v113;
        v113[1] = v33;
        *(_QWORD *)v33 = v35;
        *(_QWORD *)(v33 + 8) = &v113;
        v113 = (__int64 *)v33;
      }
      v26 = v26->mNext;
    }
    while ( v26 != (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries );
    v176 = v24;
  }
  if ( v24 )
  {
    v36 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
    v140 = (unsigned __int64)v36;
    if ( v36 )
    {
      v37 = UFG::OnlineManager::Instance();
      v38 = UFG::OnlineManager::GetOnlineName(v37, &v174);
      v39 = UFG::OnlineManager::Instance();
      v40 = UFG::OnlineManager::GetOnlineId(v39, &v138);
      v41 = UFG::OnlineId::ToString(v40, &v172);
      v2 |= 0x38u;
      v36->mNext = v36;
      v36[1].mNext = v36;
      UFG::qString::qString((UFG::qString *)&v36[2], v41);
      UFG::qString::qString((UFG::qString *)&v36[7], v38);
      LODWORD(v36[12].mNext) = v24;
    }
    else
    {
      v36 = 0i64;
    }
    v42 = v113;
    v113[1] = (__int64)v36;
    v36->mNext = (UFG::allocator::free_link *)v42;
    v36[1].mNext = (UFG::allocator::free_link *)&v113;
    v113 = (__int64 *)v36;
    if ( v2 & 0x20 )
    {
      v2 &= 0xFFFFFFDF;
      UFG::qString::~qString(&v172);
    }
    if ( v2 & 0x10 )
    {
      v2 &= 0xFFFFFFEF;
      v43 = v138.mPrev;
      v44 = v138.mNext;
      v138.mPrev->mNext = v138.mNext;
      v44->mPrev = v43;
      v138.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v138;
      v138.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v138;
    }
    if ( v2 & 8 )
    {
      v2 &= 0xFFFFFFF7;
      UFG::qString::~qString(&v174);
    }
    if ( v25 )
    {
      v45 = (UFG::qSymbol *)v1->mSocialHubProperties.p[v177].mLBD;
      v46 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v46, LeaderboardScoreIntList, v45 + 12, v24);
    }
  }
  v47 = UFG::UIHKScreenSocialHub::CompareDESC;
  if ( v1->mCurrentScreenType == 4 )
    v47 = UFG::UIHKScreenSocialHub::CompareASC;
  v48 = (__int64 *)mem;
  do
  {
    v49 = 0i64;
    while ( v48 != (__int64 *)&v113 )
    {
      v50 = (__int64 *)v48[1];
      if ( v50 == (__int64 *)&v113 )
        break;
      if ( v47((UFG::UIHKScreenSocialHub::LeaderboardEntry *)v48, (UFG::UIHKScreenSocialHub::LeaderboardEntry *)v48[1]) )
      {
        v48 = v50;
      }
      else
      {
        v51 = *v48;
        v52 = (__int64 **)v50[1];
        v53 = (__int64 *)v48[1];
        *(_QWORD *)(v51 + 8) = v53;
        *v53 = v51;
        *v48 = (__int64)v48;
        v48[1] = (__int64)v48;
        v54 = *v50;
        v55 = (__int64 *)v50[1];
        *(_QWORD *)(v54 + 8) = v55;
        *v55 = v54;
        *v50 = (__int64)v50;
        v50[1] = (__int64)v50;
        v56 = *(__int64 ***)(v51 + 8);
        *(_QWORD *)(v51 + 8) = v50;
        *v50 = v51;
        v50[1] = (__int64)v56;
        *v56 = v50;
        v57 = (__int64)*v52;
        *(_QWORD *)(v57 + 8) = v48;
        *v48 = v57;
        v48[1] = (__int64)v52;
        *v52 = v48;
        v49 = v50;
      }
    }
    v48 = 0i64;
    if ( !v49 || v49 == (__int64 *)&v113 )
      break;
    do
    {
      v58 = (__int64 *)*v49;
      if ( (__int64 **)*v49 == &v113 )
        break;
      if ( v47((UFG::UIHKScreenSocialHub::LeaderboardEntry *)*v49, (UFG::UIHKScreenSocialHub::LeaderboardEntry *)v49) )
      {
        v49 = v58;
      }
      else
      {
        v59 = *v58;
        v60 = (__int64 **)v49[1];
        v61 = (__int64 *)v58[1];
        *(_QWORD *)(v59 + 8) = v61;
        *v61 = v59;
        *v58 = (__int64)v58;
        v58[1] = (__int64)v58;
        v62 = *v49;
        v63 = (__int64 *)v49[1];
        *(_QWORD *)(v62 + 8) = v63;
        *v63 = v62;
        *v49 = (__int64)v49;
        v49[1] = (__int64)v49;
        v64 = *(__int64 ***)(v59 + 8);
        *(_QWORD *)(v59 + 8) = v49;
        *v49 = v59;
        v49[1] = (__int64)v64;
        *v64 = v49;
        v65 = (__int64)*v60;
        *(_QWORD *)(v65 + 8) = v58;
        *v58 = v65;
        v58[1] = (__int64)v60;
        *v60 = v58;
        v48 = v58;
      }
    }
    while ( v49 != (__int64 *)&v113 );
  }
  while ( v48 );
  v66 = 1;
  v67 = (__int64 **)mem;
  if ( mem != &v113 )
  {
    while ( 1 )
    {
      if ( v66 == 11 )
      {
LABEL_101:
        v24 = v176;
        break;
      }
      UFG::qString::qString(&v143, (UFG::qString *)(v67 + 2));
      UFG::qString::FormatEx(&v169, "%d", v66);
      if ( v66 == 10 )
      {
        v128 = (__int64 *)&v128;
        v129 = &v128;
        v68 = 0;
        v130 &= 0xFF0FFFFF00000000ui64;
        HIBYTE(v130) = 0;
        HIDWORD(v130) &= 0xFFF00000;
        v140 = UFG::qToUInt64(v143.mData, 0i64);
        v130 = v140;
        v2 |= 0x40u;
        if ( v140 == v131.m_SteamId.m_steamid.m_unAll64Bits )
        {
          v69 = 1;
          goto LABEL_71;
        }
      }
      else
      {
        v68 = 0;
      }
      v69 = 0;
LABEL_71:
      if ( v2 & 0x40 )
      {
        v2 &= 0xFFFFFFBF;
        v70 = v128;
        v71 = v129;
        v128[1] = (__int64)v129;
        *v71 = v70;
        v128 = (__int64 *)&v128;
        v129 = &v128;
      }
      if ( v69 )
      {
        UFG::qString::qString(&v171, "--");
        UFG::qString::Set(&v169, *(const char **)(v72 + 24), *(_DWORD *)(v72 + 20), 0i64, 0);
        UFG::qString::~qString(&v171);
      }
      UFG::qString::qString(&formatted);
      v73 = v1->mCurrentScreenType;
      if ( v73 != 1 )
      {
        if ( v73 == 2 )
        {
          v122 = (__int64 *)&v122;
          v123 = &v122;
          v124 = __PAIR__(HIDWORD(v124), 0) & 0xFF0FFFFF00000000ui64;
          HIBYTE(v124) = 0;
          HIDWORD(v124) &= 0xFFF00000;
          v164 = UFG::qToUInt64(v143.mData, 0i64);
          v124 = v164;
          v74 = v164 == v131.m_SteamId.m_steamid.m_unAll64Bits;
          v75 = v122;
          v76 = v123;
          v122[1] = (__int64)v123;
          *v76 = v75;
          v122 = (__int64 *)&v122;
          v123 = &v122;
          LOBYTE(v68) = v74 != 0;
          v77 = v68 + 1;
          if ( !v1->mCurrentLeaderboardType )
          {
            frnd.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
            frnd.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
            frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
            v139 = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
            frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
            frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits &= 0xFF0FFFFF00000000ui64;
            HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            UFG::qString::qString(&frnd.m_sOnlineName);
            v78 = (const char *)v67[5];
            id.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            id.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            id.m_SteamId.m_steamid.m_unAll64Bits &= 0xFF0FFFFF00000000ui64;
            HIBYTE(id.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&id.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            v139 = (UFG::OnlineId *)UFG::qToUInt64(v78, 0i64);
            id.m_SteamId.m_steamid.m_unAll64Bits = (unsigned __int64)v139;
            v79 = UFG::OnlineFriendManager::FindFriend(&frnd, &id);
            v80 = id.mPrev;
            v81 = id.mNext;
            id.mPrev->mNext = id.mNext;
            v81->mPrev = v80;
            id.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            id.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            if ( v79 )
            {
              v82 = *((_DWORD *)v67 + 24);
              entry.mPrev = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
              entry.mNext = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
              entry.m_iRating = v82;
              entry.m_uRank = 0;
              entry.m_eEntryType = v77;
              UFG::qStringCopy(entry.m_sUsername, 64, frnd.m_sOnlineName.mData, -1);
              v83 = &v1->mSocialHubProperties.p[v177].mLBD->mLeaderboardId;
              v84 = UFG::CachedLeaderboardManager::Instance();
              UFG::CachedLeaderboardManager::UpsertEntry(v84, *v83, &entry);
              v85 = entry.mPrev;
              v86 = entry.mNext;
              entry.mPrev->mNext = entry.mNext;
              v86->mPrev = v85;
              entry.mPrev = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
              entry.mNext = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
            }
            frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
            UFG::qString::~qString(&frnd.m_sOnlineName);
            v165 = &frnd.m_cOnlineId;
            v87 = frnd.m_cOnlineId.mPrev;
            v88 = frnd.m_cOnlineId.mNext;
            frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
            v88->mPrev = v87;
            frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
            frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
            v89 = frnd.mPrev;
            v90 = frnd.mNext;
            frnd.mPrev->mNext = frnd.mNext;
            v90->mPrev = v89;
            frnd.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
            frnd.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
          }
        }
        else if ( (unsigned int)(v73 - 3) > 1 )
        {
          goto LABEL_84;
        }
      }
      UFG::UIHKScreenSocialHub::FormatScore(
        v1,
        &formatted,
        v1->mSocialHubProperties.p[v177].mLBD,
        *((_DWORD *)v67 + 24));
LABEL_84:
      if ( *((_DWORD *)v67 + 19) )
      {
        v116 = (__int64 *)&v116;
        v117 = &v116;
        v118 &= 0xFF0FFFFF00000000ui64;
        HIBYTE(v118) = 0;
        HIDWORD(v118) &= 0xFFF00000;
        v166 = UFG::qToUInt64(v143.mData, 0i64);
        v118 = v166;
        v91 = v166 == v131.m_SteamId.m_steamid.m_unAll64Bits;
        v92 = v116;
        v93 = v117;
        v116[1] = (__int64)v117;
        *v93 = v92;
        v116 = (__int64 *)&v116;
        v117 = &v116;
        if ( v91 )
        {
          v94 = UFG::OnlineManager::Instance();
          v95 = UFG::OnlineManager::GetOnlineName(v94, &v173);
          UFG::qString::Set((UFG::qString *)(v67 + 7), v95->mData, v95->mLength, 0i64, 0);
          UFG::qString::~qString(&v173);
        }
        `eh vector constructor iterator'(&pargs, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v96 = v143.mData;
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        *(_QWORD *)&pargs.mValue.NValue = v96;
        v97 = v169.mData;
        if ( (v147 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v146 + 16i64))(v146, &v145, v148);
          v146 = 0i64;
        }
        v147 = 6;
        v148 = v97;
        v119 = (__int64 *)&v119;
        v120 = &v119;
        v121 &= 0xFF0FFFFF00000000ui64;
        HIBYTE(v121) = 0;
        HIDWORD(v121) &= 0xFFF00000;
        v163 = UFG::qToUInt64(v143.mData, 0i64);
        v121 = v163;
        v98 = gIconSocialHubAvatarFriend_21;
        if ( v163 == v131.m_SteamId.m_steamid.m_unAll64Bits )
          v98 = gIconSocialHubAvatarPlayer_21;
        if ( (v151 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v150 + 16i64))(v150, &v149, v152);
          v150 = 0i64;
        }
        v151 = 6;
        v152 = v98;
        v99 = v119;
        v100 = v120;
        v119[1] = (__int64)v120;
        *v100 = v99;
        v119 = (__int64 *)&v119;
        v120 = &v119;
        v101 = (__int64)v67[10];
        if ( (v155 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v154 + 16i64))(v154, &v153, v156);
          v154 = 0i64;
        }
        v155 = 6;
        v156 = v101;
        v102 = formatted.mData;
        if ( (v159 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v158 + 16i64))(v158, &v157, v160);
          v158 = 0i64;
        }
        v159 = 6;
        v160 = v102;
        Scaleform::GFx::Movie::Invoke(v178, "SocialHubRhsList_AddItem", 0i64, &pargs, 5u);
        ++v66;
        `eh vector destructor iterator'(&pargs, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
      UFG::qString::~qString(&formatted);
      UFG::qString::~qString(&v169);
      UFG::qString::~qString(&v143);
      v67 = (__int64 **)v67[1];
      if ( v67 == &v113 )
        goto LABEL_101;
    }
  }
  `eh vector constructor iterator'(&v142, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  UFG::qString::qString(&v168);
  UFG::UIHKScreenSocialHub::FormatScore(v1, &v168, v1->mSocialHubProperties.p[v177].mLBD, v24);
  v103 = "-";
  if ( v24 )
    v103 = v168.mData;
  if ( ((unsigned int)v142.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v142.pObjectInterface->vfptr->gap8[8])(
      v142.pObjectInterface,
      &v142,
      *(_QWORD *)&v142.mValue.NValue);
    v142.pObjectInterface = 0i64;
  }
  v142.Type = 6;
  *(_QWORD *)&v142.mValue.NValue = v103;
  Scaleform::GFx::Movie::Invoke(v178, "SocialHubRhsView_SetScore", 0i64, &v142, 1u);
  if ( v1->mCurrentScreenType == 1 )
    UFG::UIHKScreenSocialHub::PopulateRhsSocialAwardMedal(v1, v1->mSocialHubProperties.p[v177].mLBD, v24);
  Scaleform::GFx::Movie::Invoke(v178, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
  v1->mHandleMessageDisabled = 0;
  Scaleform::GFx::Movie::Invoke(v178, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v1, v1->mCurrentScreenType, 1);
  UFG::qString::~qString(&v168);
  `eh vector destructor iterator'(&v142, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  for ( i = (char *)mem; mem != &v113; i = (char *)mem )
  {
    v105 = *(_QWORD *)i;
    v106 = (_QWORD *)*((_QWORD *)i + 1);
    *(_QWORD *)(v105 + 8) = v106;
    *v106 = v105;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    UFG::qString::~qString((UFG::qString *)(i + 56));
    UFG::qString::~qString((UFG::qString *)(i + 16));
    v107 = *(_QWORD *)i;
    v108 = (_QWORD *)*((_QWORD *)i + 1);
    *(_QWORD *)(v107 + 8) = v108;
    *v108 = v107;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    operator delete[](i);
  }
  v109 = v113;
  v110 = mem;
  v113[1] = (__int64)mem;
  *v110 = v109;
  v113 = (__int64 *)&v113;
  mem = &v113;
  v111 = v131.mPrev;
  v112 = v131.mNext;
  v131.mPrev->mNext = v131.mNext;
  v112->mPrev = v111;
  v131.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v131;
  v131.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v131;
LABEL_111:
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
}*((_QWORD *)i + 1);
    *(_QWORD *)(v107 + 8) = v108;
    *v108 = v107;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    operator delet

// File Line: 1858
// RVA: 0x602730
void __fastcall UFG::UIHKScreenSocialHub::RequestRhsListPopulation(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rsi
  Scaleform::GFx::Movie *v2; // rbx
  signed __int64 v3; // rcx
  signed __int64 v4; // rdi
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rax
  int v7; // eax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-40h]

  v1 = this;
  UFG::UIHKScreenSocialHub::PopulateRhsListHeader(this, this->mCurrentLeaderboardType);
  if ( v1->mLHSItemCount )
  {
    v1->mPopulateRhsListAsyncRequested = 1;
    v1->mTimeElapsedAfterMoving = 0.0;
    v2 = v1->mRenderable->m_movie.pObject;
    Scaleform::GFx::Movie::Invoke(v1->mRenderable->m_movie.pObject, "SocialHubRhsList_ClearErrorMessage", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsList_ClearItem", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v2, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
    if ( v1->mCurrentScreenType )
    {
      Scaleform::GFx::Movie::Invoke(v2, "SocialHubLoadingIcon_Show", 0i64, 0i64, 0);
      Scaleform::GFx::Movie::Invoke(v2, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
    }
    else
    {
      Scaleform::GFx::Movie::Invoke(v2, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
    }
    if ( v1->mCurrentScreenType == 1 )
    {
      pval.pObjectInterface = 0i64;
      pval.Type = 0;
      Scaleform::GFx::Movie::GetVariable(v2, &pval, "gLeaderboardId");
      v3 = (unsigned int)(signed int)pval.mValue.NValue;
      v4 = v3;
      v5 = (UFG::qSymbol *)v1->mSocialHubProperties.p[v3].mLBD;
      v6 = UFG::GameStatTracker::Instance();
      v7 = UFG::GameStatTracker::GetStat(v6, LeaderboardScoreIntList, v5 + 12);
      UFG::UIHKScreenSocialHub::PopulateRhsSocialAwardMedal(v1, v1->mSocialHubProperties.p[v4].mLBD, v7);
      if ( ((unsigned int)pval.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          *(_QWORD *)&pval.mValue.NValue);
    }
  }
}

// File Line: 1898
// RVA: 0x604650
void __fastcall UFG::UIHKScreenSocialHub::SendMessageCallbackA(OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient, UFG::OSuiteMessage *msg)
{
  UFG::OSuiteMessage *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::OSuiteDBLogger *v5; // rdi
  UFG::OSuiteLeaderboardManager *v6; // rax
  UFG::OSuiteLeaderboardData *v7; // rax
  char dest; // [rsp+20h] [rbp-88h]

  v3 = msg;
  if ( !pData || pData->Status.eError )
  {
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = 2;
    if ( msg )
      msg->vfptr->__vecDelDtor(msg, 1u);
  }
  else
  {
    v4 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v4, SocialChallengeSent, 1);
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = 1;
    UFG::UIHKScreenSocialHub::gOSuiteMessage = v3;
    if ( v3 && HIDWORD(v3[1].mNext) == 4 )
    {
      v5 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v5, "SocialInteraction") )
      {
        UFG::qSPrintf(&dest, 128, "s_%s", "Event");
        OSuite::ZMetric::SetProperty(v5->m_pMetric, &dest, "Challenge Sent");
        v6 = UFG::OSuiteLeaderboardManager::Instance();
        v7 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(v6, (int)v3[2].mPrev);
        UFG::OSuiteDBLogger::AddValue(v5, "Leaderboard", v7->mLeaderboardNameStr.mData);
        UFG::OSuiteDBLogger::AddValue(v5, "Score", HIDWORD(v3[2].mPrev));
        UFG::OSuiteDBLogger::SubmitMetric(v5, 0);
      }
    }
  }
}

// File Line: 1942
// RVA: 0x60C9F0
signed __int64 __fastcall UFG::UIHKScreenSocialHub::ShouldShowGameSlice(UFG::UIHKScreenSocialHub *this, UFG::qSymbol *sliceName)
{
  UFG::qSymbol *v2; // rbx
  unsigned int v3; // eax
  signed __int64 result; // rax
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::qSymbol *v6; // rbx
  UFG::GameStatTracker *v7; // rax
  UFG::qSymbol symGameSliceName; // [rsp+48h] [rbp+10h]
  UFG::qSymbol *v9; // [rsp+50h] [rbp+18h]

  v2 = sliceName;
  v3 = sliceName->mUID;
  if ( sliceName->mUID == -1 )
    goto LABEL_9;
  v9 = &symGameSliceName;
  symGameSliceName.mUID = v3;
  if ( UFG::GameStatAction::GameSliceAction::IsCompleted((__int64)&symGameSliceName) )
    return (unsigned int)(UFG::ProgressionTracker::Instance()->mModeType != 2) + 1;
  v5 = UFG::OSuiteLeaderboardManager::Instance();
  v6 = &UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(v5, v2)->mLeaderboardName;
  v7 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v7, LeaderboardScoreIntList, v6) <= 0 )
LABEL_9:
    result = 0i64;
  else
    result = 1i64;
  return result;
}

// File Line: 1969
// RVA: 0x5E71A0
UFG::qSymbol *__fastcall UFG::UIHKScreenSocialHub::GetCurrentItemGameSliceName(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx
  UFG::qSymbol *v4; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( !v2 )
    return &UFG::gNullQSymbol;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v2, &pval, "gLeaderboardId");
  if ( (signed int)pval.mValue.NValue == -1 )
    v4 = &UFG::gNullQSymbol;
  else
    v4 = &v1->mSocialHubProperties.p[(signed int)pval.mValue.NValue].mLBD->mSliceName;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v4;
}

// File Line: 1993
// RVA: 0x62B360
char __fastcall UFG::UIHKScreenSocialHub::handleMessage(UFG::UIHKScreenSocialHub *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r12
  unsigned int v4; // er14
  UFG::UIHKScreenSocialHub *v5; // rsi
  UFG::OSuiteMessage *v6; // rdi
  Scaleform::GFx::Movie *v7; // r13
  UFG::SocialLogDataManager *v9; // rax
  UFG::SocialLogDataManager *v10; // rax
  UFG::SocialLogDataManager *v11; // rbx
  signed int v12; // er15
  int v13; // ecx
  signed __int64 i; // rax
  UFG::UIHKScreenSocialHub::SocialHubProperty *v15; // r8
  unsigned int v16; // er9
  unsigned int v17; // er10
  UFG::UIHKScreenSocialHub::SocialHubProperty *v18; // rbx
  signed int v19; // ebx
  UFG::LeaderboardCategory v20; // edx
  int v21; // edx
  int v22; // edx
  int v23; // er15
  UFG::GameStatTracker *v24; // rax
  UFG::PersistentData::MapBool *v25; // rax
  UFG::qSymbol *v26; // rax
  bool v27; // bl
  const char *v28; // r8
  unsigned int v29; // ebx
  const char *v30; // rbx
  UFG::ProgressionTracker *v31; // rax
  UFG::OnlineManager *v32; // rax
  const char *v33; // rbx
  __int64 v34; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v35; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v36; // rax
  bool v37; // sf
  unsigned int v38; // edx
  int v39; // eax
  UFG::UIHKScreenSocialHub *v40; // rcx
  int v41; // er13
  signed __int64 j; // rbx
  UFG::allocator::free_link *v43; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v44; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v45; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v46; // rax
  UFG::OnlineManager *v47; // rax
  int v48; // ecx
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *v49; // rax
  UFG::OnlineManager *v50; // rax
  UFG::qString *srcOnlineName; // rdi
  UFG::OnlineManager *v52; // rax
  UFG::OnlineId *v53; // rbx
  char v54; // r15
  unsigned __int64 v55; // rax
  UFG::OSuiteMessage *v56; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v57; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v58; // rax
  UFG::OSuiteMessenger *v59; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v60; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v61; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *k; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v63; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v64; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v65; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v66; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v67; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v68; // rax
  UFG::OnlineId *dstOnlineId; // [rsp+30h] [rbp-D0h]
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> receivers; // [rsp+48h] [rbp-B8h]
  UFG::OnlineId id; // [rsp+58h] [rbp-A8h]
  UFG::OnlineId v72; // [rsp+70h] [rbp-90h]
  char v73; // [rsp+88h] [rbp-78h]
  __int64 v74; // [rsp+98h] [rbp-68h]
  unsigned int v75; // [rsp+A0h] [rbp-60h]
  double v76; // [rsp+A8h] [rbp-58h]
  UFG::OnlineId v77; // [rsp+B8h] [rbp-48h]
  Scaleform::GFx::Value v78; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::Value pval; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::Value v80; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::Value v81; // [rsp+160h] [rbp+60h]
  __int64 v82; // [rsp+190h] [rbp+90h]
  UFG::qString dstOnlineName; // [rsp+198h] [rbp+98h]
  UFG::qString result; // [rsp+1C0h] [rbp+C0h]
  int score; // [rsp+230h] [rbp+130h]
  UFG::SocialLogData_Challenge *v86; // [rsp+248h] [rbp+148h]

  v82 = -2i64;
  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = 0i64;
  v7 = this->mRenderable->m_movie.pObject;
  if ( !v7 )
    return 0;
  if ( msgId == UI_HASH_TAB_ANIM_COMPLETE )
  {
    this->mbTabbingScrollLock = 0;
    return 1;
  }
  if ( msgId == UI_HASH_INPUT_SWAPPED_30 )
    UFG::UIHKScreenSocialHub::RefreshHelpButtonsEx(this);
  if ( v5->mHandleMessageDisabled )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  v5->mTimeElapsedAfterMoving = 0.0;
  if ( !v5->mPopupActive )
  {
    if ( v4 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x5958830u,
          0i64,
          0,
          0i64);
      UFG::UIHKScreenSocialHub::ShowFirstTimeIntro(v5);
      return 1;
    }
    if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xA4E5BFBD,
          0i64,
          0,
          0i64);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
      return 1;
    }
    if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      if ( v5->mCurrentScreenType
        || (v9 = UFG::SocialLogDataManager::Instance(), UFG::SocialLogDataManager::ListContainsActiveFlowEntries(v9) != 1) )
      {
        v24 = UFG::GameStatTracker::Instance();
        v25 = UFG::GameStatTracker::GetMapBool(v24, Collectible_Safehouse);
        if ( (unsigned int)UFG::PersistentData::MapBool::GetTrueCount(v25) )
        {
          if ( !v5->mPopulateRhsListAsyncRequested && (unsigned int)(v5->mCurrentScreenType - 3) <= 1 )
          {
            v26 = UFG::UIHKScreenSocialHub::GetCurrentItemGameSliceName(v5);
            if ( (unsigned int)UFG::UIHKScreenSocialHub::ShouldShowGameSlice(v5, v26) == 2 )
            {
              v27 = v5->mCurrentScreenType == 3;
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0x4A3D1F6Cu,
                  0i64,
                  0,
                  0i64);
              v28 = "$HUD_SOCIAL_REPLAYRACE";
              if ( v27 )
                v28 = "$HUD_SOCIAL_REPLAYMISSION";
              UFG::UIScreenDialogBox::createYesNoDialog((UFG::UIScreen *)&v5->vfptr, &customWorldMapCaption, v28, 0, 0);
            }
          }
        }
      }
      else
      {
        v10 = UFG::SocialLogDataManager::Instance();
        v11 = UFG::SocialLogDataManager::GetList(v10);
        if ( !(unsigned int)UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0>::Count(&v11->m_lSocialLogDataList) )
          return 1;
        pval.pObjectInterface = 0i64;
        pval.Type = 0;
        v74 = 0i64;
        v75 = 0;
        Scaleform::GFx::Movie::GetVariable(v7, &pval, "gSocialLogList");
        pval.pObjectInterface->vfptr->Invoke(
          pval.pObjectInterface,
          *(void **)&pval.mValue.NValue,
          (Scaleform::GFx::Value *)&v73,
          "SelectedIndex",
          0i64,
          0i64,
          (pval.Type & 0x8F) == 10);
        v12 = (signed int)v76;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xC415B16F,
            0i64,
            0,
            0i64);
        v13 = (unsigned __int64)UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0>::Count(&v11->m_lSocialLogDataList)
            - v12
            - 1;
        for ( i = (signed __int64)&v11->m_lSocialLogDataList.mNode.mNext[-2].mNext; v13 > 0; i = *(_QWORD *)(i + 32)
                                                                                               - 24i64 )
        {
          if ( (UFG::SocialLogDataManager *)i == &v11[-1] )
            break;
          --v13;
        }
        v15 = 0i64;
        v16 = 0;
        v17 = v5->mSocialHubProperties.size;
        if ( v17 )
        {
          do
          {
            v18 = v5->mSocialHubProperties.p;
            if ( *(_DWORD *)(i + 56) == v18[v16].mLBD->mLeaderboardId )
              v15 = &v18[v16];
            ++v16;
          }
          while ( v16 < v17 );
        }
        v19 = v15->mUIItemIndex;
        v20 = v15->mLBD->mCategory;
        if ( v20 )
        {
          v21 = v20 - 1;
          if ( v21 )
          {
            v22 = v21 - 1;
            if ( v22 )
            {
              if ( v22 == 1 )
                v23 = 4;
              else
                v23 = -1;
            }
            else
            {
              v23 = 3;
            }
          }
          else
          {
            v23 = 2;
          }
        }
        else
        {
          v23 = 1;
        }
        v5->mCurrentScreenType = v23;
        UFG::UIHKScreenSocialHub::FLASH_FocusTab(v5, v23);
        UFG::UIHKScreenSocialHub::PopulateLhsList(v5, v5->mCurrentScreenType);
        v78.pObjectInterface = 0i64;
        v78.Type = 0;
        Scaleform::GFx::Movie::GetVariable(v7, &v78, "gSocialHubLhsList");
        if ( (v75 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
            v74,
            &v73,
            COERCE_DOUBLE(*(_QWORD *)&v76));
          v74 = 0i64;
        }
        v75 = 5;
        v76 = (double)v19;
        LOBYTE(dstOnlineId) = (v78.Type & 0x8F) == 10;
        v78.pObjectInterface->vfptr->Invoke(
          v78.pObjectInterface,
          *(void **)&v78.mValue.NValue,
          0i64,
          "SetSelectedIndex",
          (Scaleform::GFx::Value *)&v73,
          1ui64,
          (bool)dstOnlineId);
        UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(v5);
        UFG::UIHKScreenSocialHub::RequestRhsListPopulation(v5);
        UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v5, v5->mCurrentScreenType, 0);
        if ( ((unsigned int)v78.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v78.pObjectInterface->vfptr->gap8[8])(
            v78.pObjectInterface,
            &v78,
            *(_QWORD *)&v78.mValue.NValue);
          v78.pObjectInterface = 0i64;
        }
        v78.Type = 0;
        if ( (v75 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
            v74,
            &v73,
            COERCE_DOUBLE(*(_QWORD *)&v76));
          v74 = 0i64;
        }
        v75 = 0;
        if ( ((unsigned int)pval.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            *(_QWORD *)&pval.mValue.NValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = 0;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    if ( v4 == UI_HASH_DIALOG_YES_30 )
    {
      v81.pObjectInterface = 0i64;
      v81.Type = 0;
      Scaleform::GFx::Movie::GetVariable(v7, &v81, "gLeaderboardId");
      v29 = (signed int)v81.mValue.NValue;
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
      v30 = v5->mSocialHubProperties.p[v29].mLBD->mSliceNameStr.mData;
      v31 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::BindChallengeGameSlice(v31, v30);
      v5->mLaunchingMissionReplay = 1;
      if ( ((unsigned int)v81.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v81.pObjectInterface->vfptr->gap8[8])(
          v81.pObjectInterface,
          &v81,
          *(_QWORD *)&v81.mValue.NValue);
        v81.pObjectInterface = 0i64;
      }
      v81.Type = 0;
      return 1;
    }
    if ( v4 == UI_HASH_DIALOG_NO_30 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    if ( v4 == UI_HASH_BUTTON_SELECT_PRESSED_30 )
    {
      v32 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v32)
        && v5->mCurrentScreenType
        && (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries )
      {
        v80.pObjectInterface = 0i64;
        v80.Type = 0;
        Scaleform::GFx::Movie::GetVariable(v7, &v80, "gOnlineId");
        if ( v80.Type & 0x8F )
        {
          v33 = ((unsigned int)v80.Type >> 6) & 1 ? *v80.mValue.pStringManaged : *(_QWORD *)&v80.mValue.NValue;
          if ( (unsigned int)UFG::qStringLength(v33) )
          {
            id.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            id.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            id.m_SteamId.m_steamid.m_unAll64Bits = __PAIR__(HIDWORD(id.m_SteamId.m_steamid.m_unAll64Bits), 0) & 0xFF0FFFFF00000000ui64;
            HIBYTE(id.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&id.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            id.m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(v33, 0i64);
            UFG::OnlineUtil::ShowGamerCard(&id, v34);
            v35 = id.mPrev;
            v36 = id.mNext;
            id.mPrev->mNext = id.mNext;
            v36->mPrev = v35;
            id.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
            id.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&id;
          }
        }
        if ( ((unsigned int)v80.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v80.pObjectInterface->vfptr->gap8[8])(
            v80.pObjectInterface,
            &v80,
            *(_QWORD *)&v80.mValue.NValue);
          v80.pObjectInterface = 0i64;
        }
        v80.Type = 0;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    if ( v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      UFG::UIHKScreenSocialHub::OnButton1Pressed(v5);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    if ( v4 == UI_HASH_BUTTON_R3_PRESSED_30 )
    {
      UFG::UIHKScreenSocialHub::OnR3Pressed(v5);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    if ( v4 == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      if ( !v5->mbTabbingScrollLock )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xC415B16F,
            0i64,
            0,
            0i64);
        v5->mCurrentScreenType = (v5->mCurrentScreenType + 1) % v5->mMaxTabs;
        UFG::UIHKScreenSocialHub::RefreshScreenType(v5);
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    if ( v4 == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( !v5->mbTabbingScrollLock )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xC415B16F,
            0i64,
            0,
            0i64);
        v37 = v5->mCurrentScreenType-- - 1 < 0;
        if ( v37 )
          v5->mCurrentScreenType += v5->mMaxTabs;
        UFG::UIHKScreenSocialHub::RefreshScreenType(v5);
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    if ( v4 != UI_HASH_THUMBSTICK_LEFT_UP_30
      && (v4 != UI_HASH_DPAD_UP_PRESSED_30
       || UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController)
      && v4 != UI_HASH_THUMBSTICK_LEFT_DOWN_30
      && (v4 != UI_HASH_DPAD_DOWN_PRESSED_30
       || UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController)
      && (v38 = UI_HASH_THUMBSTICK_RIGHT_UP_30, v4 != UI_HASH_THUMBSTICK_RIGHT_UP_30)
      && v4 != UI_HASH_THUMBSTICK_RIGHT_DOWN_30 )
    {
      if ( v4 == UI_HASH_MOUSE_MOVE_LEFT_LIST )
      {
        v5->mLastListTouchedByMouse = 0;
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      if ( v4 == UI_HASH_MOUSE_MOVE_RIGHT_LIST )
      {
        v5->mLastListTouchedByMouse = 1;
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      if ( v4 != UI_HASH_MOUSE_WHEEL_SCROLL_30 )
      {
        if ( v4 != UI_HASH_MOUSE_MOVE_30 )
        {
          if ( v4 != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
          {
            if ( v4 == UI_HASH_MOUSE_CHANGE_TAB_20 )
            {
              if ( !v5->mbTabbingScrollLock )
              {
                if ( UFG::HudAudio::m_instance )
                  UFG::AudioEntity::CreateAndPlayEvent(
                    (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                    0xC415B16F,
                    0i64,
                    0,
                    0i64);
                v5->mCurrentScreenType = UFG::UI::GetFlashArgsInt(v3);
                UFG::UIHKScreenSocialHub::RefreshScreenType(v5);
              }
            }
            else if ( v4 == UI_HASH_UPDATE_RHS )
            {
              UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(v5);
              UFG::UIHKScreenSocialHub::RequestRhsListPopulation(v5);
            }
            else if ( v4 == UI_HASH_CHALLENGE_BUTTON_ACCEPTED )
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0xCCF5DDCu,
                  0i64,
                  0,
                  0i64);
              receivers.mNode.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
              receivers.mNode.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
              v41 = -1;
              score = 0;
              for ( j = (signed __int64)&v5->mChallengeDialogPopupEntries.mNode.mNext[-1].mNext;
                    (int *)j != &v5->mLastListTouchedByMouse;
                    j = *(_QWORD *)(j + 16) - 8i64 )
              {
                if ( *(_BYTE *)(j + 64) )
                {
                  v43 = UFG::qMalloc(0x18ui64, "UIHKScreenSocialHub", 0i64);
                  if ( v43 )
                  {
                    UFG::OnlineId::OnlineId((UFG::OnlineId *)v43, *(const char **)(j + 96));
                    v45 = v44;
                  }
                  else
                  {
                    v45 = 0i64;
                  }
                  v46 = receivers.mNode.mPrev;
                  receivers.mNode.mPrev->mNext = v45;
                  v45->mPrev = v46;
                  v45->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
                  receivers.mNode.mPrev = v45;
                  v41 = *(_DWORD *)(j + 112);
                  score = *(_DWORD *)(j + 116);
                }
              }
              v47 = UFG::OnlineManager::Instance();
              if ( UFG::OnlineManager::IsNetworkSignedIn(v47) )
              {
                v48 = 0;
                v49 = (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)receivers.mNode.mNext;
                if ( (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)receivers.mNode.mNext != &receivers )
                {
                  do
                  {
                    ++v48;
                    v49 = (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)v49->mNode.mNext;
                  }
                  while ( v49 != &receivers );
                  if ( v48 )
                  {
                    v72.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v72;
                    v72.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v72;
                    v72.m_SteamId.m_steamid.m_unAll64Bits = __PAIR__(HIDWORD(v72.m_SteamId.m_steamid.m_unAll64Bits), 0) & 0xFF0FFFFF00000000ui64;
                    HIBYTE(v72.m_SteamId.m_steamid.m_unAll64Bits) = 0;
                    *((_DWORD *)&v72.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
                    UFG::qString::qString(&dstOnlineName, "Dummy");
                    v86 = (UFG::SocialLogData_Challenge *)UFG::qMalloc(0xD0ui64, "UIHKScreenSocialHub", 0i64);
                    if ( v86 )
                    {
                      v50 = UFG::OnlineManager::Instance();
                      srcOnlineName = UFG::OnlineManager::GetOnlineName(v50, &result);
                      v52 = UFG::OnlineManager::Instance();
                      v53 = UFG::OnlineManager::GetOnlineId(v52, &v77);
                      v54 = 3;
                      v55 = UFG::OnlineUtil::CurrentTimeMillis();
                      UFG::SocialLogData_Challenge::SocialLogData_Challenge(
                        v86,
                        v55,
                        v41,
                        score,
                        v53,
                        srcOnlineName,
                        &v72,
                        &dstOnlineName);
                      v6 = v56;
                    }
                    else
                    {
                      v54 = 0;
                    }
                    if ( v54 & 2 )
                    {
                      v54 &= 0xFDu;
                      v57 = v77.mPrev;
                      v58 = v77.mNext;
                      v77.mPrev->mNext = v77.mNext;
                      v58->mPrev = v57;
                      v77.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v77;
                      v77.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v77;
                    }
                    if ( v54 & 1 )
                      UFG::qString::~qString(&result);
                    v59 = UFG::OSuiteMessenger::Instance();
                    if ( UFG::OSuiteMessenger::Send(v59, v6, &receivers, UFG::UIHKScreenSocialHub::SendMessageCallbackA) )
                      v5->mHandleMessageDisabled = 1;
                    UFG::qString::~qString(&dstOnlineName);
                    v60 = v72.mPrev;
                    v61 = v72.mNext;
                    v72.mPrev->mNext = v72.mNext;
                    v61->mPrev = v60;
                    v72.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v72;
                    v72.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v72;
                  }
                }
              }
              else
              {
                UFG::UIScreenDialogBox::createOKDialog(0i64, &customWorldMapCaption, "$HUD_SOCIAL_FAILSEND", 1);
              }
              v5->mDisplayingChallengeDialog = 0;
              UFG::UIHKScreenSocialHub::ShowHelpButtonsEx(v5);
              for ( k = receivers.mNode.mNext;
                    (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)receivers.mNode.mNext != &receivers;
                    k = receivers.mNode.mNext )
              {
                v63 = k->mPrev;
                v64 = k->mNext;
                v63->mNext = v64;
                v64->mPrev = v63;
                k->mPrev = k;
                k->mNext = k;
                v65 = k->mPrev;
                v66 = k->mNext;
                v65->mNext = v66;
                v66->mPrev = v65;
                k->mPrev = k;
                k->mNext = k;
                operator delete[](k);
              }
              v67 = receivers.mNode.mPrev;
              v68 = receivers.mNode.mNext;
              receivers.mNode.mPrev->mNext = receivers.mNode.mNext;
              v68->mPrev = v67;
              receivers.mNode.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
              receivers.mNode.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
            }
            else if ( v4 == UI_HASH_CHALLENGE_BUTTON_CANCELED )
            {
              UFG::UIHKScreenSocialHub::ShowHelpButtonsEx(v5);
            }
            return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
          }
          goto LABEL_15;
        }
        goto LABEL_119;
      }
      v39 = v5->mLastListTouchedByMouse;
      if ( !v39 )
      {
        v40 = v5;
        if ( SLODWORD(v3[1].mPrev) <= 0 )
          v38 = UI_HASH_THUMBSTICK_LEFT_DOWN_30;
        else
          v38 = UI_HASH_THUMBSTICK_LEFT_UP_30;
        goto LABEL_160;
      }
      if ( v39 != 1 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      if ( SLODWORD(v3[1].mPrev) <= 0 )
        v38 = UI_HASH_THUMBSTICK_RIGHT_DOWN_30;
    }
    else
    {
      v38 = v4;
    }
    v40 = v5;
LABEL_160:
    UFG::UIHKScreenSocialHub::OnScrollUpDown(v40, v38);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( v4 != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    if ( v4 != UI_HASH_MOUSE_MOVE_30 )
    {
      if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
LABEL_15:
        UFG::UIHKScreenSocialHub::Flash_HandleMouseClick(v5, (float)SLODWORD(v3[1].vfptr), (float)SHIDWORD(v3[1].vfptr));
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
LABEL_119:
    UFG::UIHKScreenSocialHub::Flash_HandleMouseMove(v5, (float)SLODWORD(v3[1].vfptr), (float)SHIDWORD(v3[1].vfptr));
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  Scaleform::GFx::Movie::Invoke(v7, "HideFirstTimeIntro", 0i64, 0i64, 0);
  v5->mPopupActive = 0;
  if ( !UFG::HudAudio::m_instance )
    return 1;
  UFG::AudioEntity::CreateAndPlayEvent(
    (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
    0x4A3D1F6Cu,
    0i64,
    0,
    0i64);
  return 1;
}

// File Line: 2350
// RVA: 0x605AF0
void __fastcall UFG::UIHKScreenSocialHub::SetFlagAsSentForNewHighScoreSaveEntry(UFG::UIHKScreenSocialHub *this, UFG::OSuiteMessage *message)
{
  UFG::OSuiteMessage *v2; // rdi
  int v3; // eax
  UFG::allocator::free_link *v4; // rsi
  unsigned int v5; // ebx
  const char *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::MapFloat *v8; // r14
  char **v9; // rax
  char *v10; // rbx
  int v11; // eax
  UFG::allocator::free_link *v12; // rdi
  unsigned int v13; // ebx
  char *v14; // rax
  int v15; // eax
  UFG::PersistentData::KeyBinary *v16; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+20h] [rbp-C8h]
  UFG::PersistentData::Binary binary; // [rsp+30h] [rbp-B8h]
  __int64 v19; // [rsp+40h] [rbp-A8h]
  UFG::SocialLogData v20; // [rsp+50h] [rbp-98h]
  __int64 v21; // [rsp+120h] [rbp+38h]
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v22; // [rsp+140h] [rbp+58h]
  int v23; // [rsp+1C8h] [rbp+E0h]
  __int64 v24; // [rsp+1D0h] [rbp+E8h]
  int dest; // [rsp+200h] [rbp+118h]

  if ( !message )
    return;
  v19 = -2i64;
  v2 = message;
  UFG::SocialLogData::SocialLogData((UFG::SocialLogData *)&v21);
  *(_QWORD *)&v20.m_sDstOnlineName.mStringHash32 = &UFG::SocialLogData_Challenge::`vftable';
  v23 = 0;
  v24 = 0i64;
  v3 = ((__int64 (__fastcall *)(unsigned int *))*(&UFG::SocialLogData_Challenge::`vftable' + 4))(&v20.m_sDstOnlineName.mStringHash32);
  v4 = UFG::qMalloc(v3 + 8, "UIHKScreenSocialHub", 0i64);
  v5 = v2->vfptr->Size(v2);
  v6 = v2->vfptr->Serialize(v2);
  UFG::qMemCopy(v4, v6, v5);
  UFG::SocialLogData_Challenge::Deserialize(
    (UFG::SocialLogData_Challenge *)&v20.m_sDstOnlineName.mStringHash32,
    (char *)v4);
  v7 = UFG::GameStatTracker::Instance();
  v8 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBinary(v7, SocialLogBinaryList);
  UFG::PersistentData::MapInt::GetIterator(v8, &result);
  if ( !UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
    goto LABEL_11;
  while ( 1 )
  {
    v9 = (char **)UFG::PersistentData::MapBinary::Iterator::GetBinary((UFG::PersistentData::MapBinary::Iterator *)&result);
    if ( !v9 )
      goto LABEL_8;
    v10 = *v9;
    if ( !*v9 )
      goto LABEL_8;
    dest = 0;
    UFG::qMemCopy(&dest, v10 + 4, 4u);
    UFG::qEndianSwapBytes((char *)&dest, 4u);
    if ( dest )
      goto LABEL_8;
    UFG::SocialLogData::SocialLogData(&v20);
    v20.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable';
    v20.m_sDstOnlineName.mMagic = 0;
    v20.m_sDstOnlineName.mData = 0i64;
    UFG::SocialLogData_NewHighScore::Deserialize((UFG::SocialLogData_NewHighScore *)&v20, v10);
    if ( v20.mNext == v22 )
      break;
    UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore((UFG::SocialLogData_NewHighScore *)&v20);
LABEL_8:
    UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
    if ( !UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
      goto LABEL_11;
  }
  v20.m_sDstOnlineName.mMagic = 1;
  v11 = ((__int64 (__fastcall *)(UFG::SocialLogData *))v20.vfptr[1].__vecDelDtor)(&v20);
  v12 = UFG::qMalloc(v11 + 8, "UIHKScreenSocialHub", 0i64);
  v13 = (unsigned __int64)((__int64 (__fastcall *)(UFG::SocialLogData *))v20.vfptr[1].__vecDelDtor)(&v20) + 8;
  v14 = UFG::SocialLogData_NewHighScore::Serialize((UFG::SocialLogData_NewHighScore *)&v20);
  UFG::qMemCopy(v12, v14, v13);
  v15 = ((__int64 (__fastcall *)(UFG::SocialLogData *))v20.vfptr[1].__vecDelDtor)(&v20);
  binary.mpBuffer = v12;
  binary.mSize = v15 + 8;
  v16 = UFG::PersistentData::MapBinary::Iterator::GetName((UFG::PersistentData::MapBinary::Iterator *)&result);
  UFG::PersistentData::MapBinary::SetBinary((UFG::PersistentData::MapBinary *)v8, &v16->mKey, &binary);
  UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore((UFG::SocialLogData_NewHighScore *)&v20);
LABEL_11:
  operator delete[](v4);
  UFG::SocialLogData_Challenge::~SocialLogData_Challenge((UFG::SocialLogData_Challenge *)&v20.m_sDstOnlineName.mStringHash32);
}ogData_Challenge((UFG::SocialLogData_Challenge *)&v20.m_sDstOnlineNa

// File Line: 2402
// RVA: 0x5EE500
bool __fastcall UFG::UIHKScreenSocialHub::IsNewHighScoreEntryUsedForChallenge(UFG::UIHKScreenSocialHub *this, int index, int score)
{
  int v3; // edi
  __int64 v4; // rsi
  UFG::UIHKScreenSocialHub *v5; // rbp
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::MapFloat *v7; // rax
  char **v8; // rax
  char *v9; // rbx
  bool v10; // bl
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+20h] [rbp-108h]
  __int64 v13; // [rsp+30h] [rbp-F8h]
  UFG::SocialLogData v14; // [rsp+40h] [rbp-E8h]
  int v15; // [rsp+100h] [rbp-28h]
  __int64 v16; // [rsp+108h] [rbp-20h]
  int dest; // [rsp+148h] [rbp+20h]

  v13 = -2i64;
  v3 = score;
  v4 = (unsigned int)index;
  v5 = this;
  v6 = UFG::GameStatTracker::Instance();
  v7 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBinary(v6, SocialLogBinaryList);
  UFG::PersistentData::MapInt::GetIterator(v7, &result);
  while ( UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
  {
    v8 = (char **)UFG::PersistentData::MapBinary::Iterator::GetBinary((UFG::PersistentData::MapBinary::Iterator *)&result);
    if ( v8 )
    {
      v9 = *v8;
      if ( *v8 )
      {
        dest = 0;
        UFG::qMemCopy(&dest, v9 + 4, 4u);
        UFG::qEndianSwapBytes((char *)&dest, 4u);
        if ( !dest )
        {
          UFG::SocialLogData::SocialLogData(&v14);
          v14.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable';
          v15 = 0;
          v16 = 0i64;
          UFG::SocialLogData_NewHighScore::Deserialize((UFG::SocialLogData_NewHighScore *)&v14, v9);
          if ( v14.m_iLeaderboardId == v5->mSocialHubProperties.p[v4].mLBD->mLeaderboardId && v14.m_iScore == v3 )
          {
            v10 = v15 != 0;
            UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore((UFG::SocialLogData_NewHighScore *)&v14);
            return v10;
          }
          UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore((UFG::SocialLogData_NewHighScore *)&v14);
        }
      }
    }
    UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
  }
  return 0;
}

// File Line: 2438
// RVA: 0x5EE010
bool __fastcall UFG::UIHKScreenSocialHub::IsChallengeableEntry(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rdi
  Scaleform::GFx::Movie *v3; // rsi
  int v4; // ebx
  bool v5; // bl
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected || v1->mCurrentScreenType )
    return 0;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  v3 = v1->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::GetVariable(v3, &pval, "gCommId");
  v5 = 0;
  if ( pval.Type & 0x8F )
  {
    if ( !(signed int)pval.mValue.NValue )
    {
      Scaleform::GFx::Movie::GetVariable(v3, &pval, "gLeaderboardId");
      v4 = (signed int)pval.mValue.NValue;
      Scaleform::GFx::Movie::GetVariable(v3, &pval, "gScore");
      if ( !UFG::UIHKScreenSocialHub::IsNewHighScoreEntryUsedForChallenge(v1, v4, (signed int)pval.mValue.NValue) )
        v5 = 1;
    }
  }
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v5;
}

// File Line: 2483
// RVA: 0x5F2AC0
void __fastcall UFG::UIHKScreenSocialHub::OnButton1Pressed(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  bool v3; // di

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  v3 = (signed int)UFG::GameStatTracker::GetStat(v2, IsBannedByCommunityManager) > 0;
  if ( UFG::UIHKScreenSocialHub::IsChallengeableEntry(v1) && !v3 )
  {
    UFG::UIHKScreenSocialHub::PopulateChallengeListAsync(v1, v1->mCurrentScreenType);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xF41B2F0D,
        0i64,
        0,
        0i64);
  }
}

// File Line: 2495
// RVA: 0x5F2E80
void __fastcall UFG::UIHKScreenSocialHub::OnR3Pressed(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx

  v1 = this;
  if ( this->mCurrentScreenType )
  {
    this->mCurrentLeaderboardType = (this->mCurrentLeaderboardType + 1) % 2;
    UFG::UIHKScreenSocialHub::RequestRhsListPopulation(this);
    UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v1, v1->mCurrentScreenType, 0);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xF41B2F0D,
        0i64,
        0,
        0i64);
  }
}

// File Line: 2509
// RVA: 0x5F2F30
void __fastcall UFG::UIHKScreenSocialHub::OnScrollUpDown(UFG::UIHKScreenSocialHub *this, unsigned int msgId)
{
  unsigned int v2; // ebx
  UFG::UIHKScreenSocialHub *v3; // rdi
  Scaleform::GFx::Movie *v4; // r15
  const char *v5; // rbp
  const char *v6; // r14
  UFG::HudAudio *v7; // rcx
  unsigned int v8; // edx
  UFG::qString *v9; // rcx
  UFG::HudAudio *v10; // rcx
  unsigned int v11; // edx
  bool v12; // r8
  UFG::qString result; // [rsp+38h] [rbp-70h]
  UFG::qString v14; // [rsp+60h] [rbp-48h]

  v2 = msgId;
  v3 = this;
  v4 = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || (v5 = "Rhs", msgId == UI_HASH_DPAD_DOWN_PRESSED_30) )
  {
    v5 = "Lhs";
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_DPAD_UP_PRESSED_30
    || (v6 = "Next", msgId == UI_HASH_THUMBSTICK_RIGHT_UP_30) )
  {
    v6 = "Prev";
  }
  if ( this->mCurrentScreenType )
  {
    if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 || msgId == UI_HASH_DPAD_UP_PRESSED_30 )
    {
      v10 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_28;
      v11 = 1497067691;
    }
    else
    {
      v10 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_28;
      v11 = 192470248;
    }
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v10->vfptr, v11, 0i64, 0, 0i64);
LABEL_28:
    UFG::qString::FormatEx(&v14, "SocialHub%sList_Scroll%s", v5, v6);
    UFG::qString::FormatEx(&result, "SocialHub%sList_Refresh", v5);
    Scaleform::GFx::Movie::Invoke(v4, v14.mData, 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v4, result.mData, 0i64, 0i64, 0);
    if ( v2 == UI_HASH_THUMBSTICK_LEFT_UP_30
      || v2 == UI_HASH_DPAD_UP_PRESSED_30
      || v2 == UI_HASH_THUMBSTICK_LEFT_DOWN_30
      || v2 == UI_HASH_DPAD_DOWN_PRESSED_30 )
    {
      UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(v3);
      UFG::UIHKScreenSocialHub::RequestRhsListPopulation(v3);
    }
    UFG::qString::~qString(&result);
    v9 = &v14;
    goto LABEL_34;
  }
  if ( msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 && msgId != UI_HASH_DPAD_UP_PRESSED_30 )
  {
    if ( msgId != UI_HASH_THUMBSTICK_LEFT_DOWN_30 && msgId != UI_HASH_DPAD_DOWN_PRESSED_30 )
      goto LABEL_35;
    v7 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      goto LABEL_20;
    v8 = 192470248;
    goto LABEL_19;
  }
  v7 = UFG::HudAudio::m_instance;
  if ( UFG::HudAudio::m_instance )
  {
    v8 = 1497067691;
LABEL_19:
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v7->vfptr, v8, 0i64, 0, 0i64);
  }
LABEL_20:
  UFG::qString::FormatEx(&result, "SocialLogList_Scroll%s", v6);
  Scaleform::GFx::Movie::Invoke(v4, result.mData, 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(v4, "SocialLogList_Refresh", 0i64, 0i64, 0);
  v9 = &result;
LABEL_34:
  UFG::qString::~qString(v9);
LABEL_35:
  if ( (unsigned int)UFG::qStringCompare(v5, "Rhs", -1) )
    v12 = 0;
  else
    v12 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v3, v3->mCurrentScreenType, v12);
}

// File Line: 2582
// RVA: 0x5D7F10
void __fastcall UFG::UIHKScreenSocialHub::FLASH_FocusTab(UFG::UIHKScreenSocialHub *this, int screenType)
{
  int v2; // edi
  UFG::UIHKScreenSocialHub *v3; // rbx
  Scaleform::GFx::Movie *v4; // rbx
  const char *v5; // rdx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = screenType;
  v3 = this;
  this->mbTabbingScrollLock = 1;
  UFG::UIHKScreenSocialHub::ReleaseTexturePack(this);
  v4 = v3->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    switch ( v2 )
    {
      case 1:
        v5 = "SetupStatAwardsView";
        break;
      case 2:
        v5 = "SetupStatGamesView";
        break;
      case 3:
        v5 = "SetupMissionsView";
        break;
      case 4:
        v5 = "SetupRacesView";
        break;
      default:
        v5 = "Invalid_FuncName";
        break;
    }
  }
  else
  {
    v5 = "SetupSocialLogView";
  }
  Scaleform::GFx::Movie::Invoke(v4, v5, 0i64, 0i64, 0);
  pargs.pObjectInterface = 0i64;
  pargs.Type = 5;
  pargs.mValue.NValue = (double)v2;
  Scaleform::GFx::Movie::Invoke(v4, "FocusTab", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 2596
// RVA: 0x5D8020
void __fastcall UFG::UIHKScreenSocialHub::FLASH_LoadRHSTexture(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx
  signed int v2; // ecx
  __int64 v3; // rax
  char *v4; // rdi
  Scaleform::GFx::Movie *v5; // rbx
  UFG::qString v6; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h]

  v1 = this;
  v2 = UFG::OSuiteLeaderboardManager::Instance()->mLeaderboardData.size;
  v3 = (unsigned int)v1->mCurrentIndex;
  if ( (signed int)v3 >= 0 && (signed int)v3 < v2 )
  {
    v4 = v1->mSocialHubProperties.p[v3].mLBD->mImage.mData;
    v5 = v1->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      if ( v5 )
      {
        UFG::qString::qString(&v6);
        UFG::qString::Format(&v6, "img://%s", v4);
        pargs.pObjectInterface = 0i64;
        pargs.Type = 6;
        *(_QWORD *)&pargs.mValue.NValue = v6.mData;
        Scaleform::GFx::Movie::Invoke(v5, "SocialHubRhsView_SetTexture", 0i64, &pargs, 1u);
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 0;
        UFG::qString::~qString(&v6);
      }
    }
  }
}

// File Line: 2618
// RVA: 0x5DB4E0
void __fastcall UFG::UIHKScreenSocialHub::Flash_HandleMouseMove(UFG::UIHKScreenSocialHub *this, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v3 )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v6 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
      v5 = 0i64;
    }
    v6 = 5;
    v7 = mouseX;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = mouseY;
    Scaleform::GFx::Movie::Invoke(v3, "HandleMouseMove", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2631
// RVA: 0x5DAE90
void __fastcall UFG::UIHKScreenSocialHub::Flash_HandleMouseClick(UFG::UIHKScreenSocialHub *this, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v3 )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v6 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
      v5 = 0i64;
    }
    v6 = 5;
    v7 = mouseX;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = mouseY;
    Scaleform::GFx::Movie::Invoke(v3, "HandleMouseClick", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2646
// RVA: 0x5F14D0
void __fastcall UFG::UIHKScreenSocialHub::LoadTexturePack(UFG::UIHKScreenSocialHub *this, int index)
{
  __int64 v2; // rdi
  UFG::UIHKScreenSocialHub *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qString v5; // [rsp+38h] [rbp-30h]

  v2 = (unsigned int)index;
  v3 = this;
  UFG::UIHKScreenSocialHub::ReleaseTexturePack(this);
  if ( v3->mSocialHubProperties.p[v2].mLBD->mImage.mLength )
  {
    v3->mCurrentIndex = v2;
    UFG::qString::qString(&v5);
    UFG::qString::Format(&v5, "Data\\UI\\%s_TP.perm.bin", v3->mSocialHubProperties.p[v2].mLBD->mImage.mData);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v4,
      v5.mData,
      HIGH_PRIORITY,
      UFG::UIHKScreenSocialHub::TextureLoadedCallback,
      0i64);
    UFG::qString::~qString(&v5);
  }
}

// File Line: 2661
// RVA: 0x600C60
void __fastcall UFG::UIHKScreenSocialHub::ReleaseTexturePack(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx
  signed int v2; // ecx
  int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = UFG::OSuiteLeaderboardManager::Instance()->mLeaderboardData.size;
  v3 = v1->mCurrentIndex;
  if ( v3 > 0 && v3 < v2 )
  {
    UFG::qString::qString(&v5);
    UFG::qString::Format(
      &v5,
      "Data\\UI\\%s_TP.perm.bin",
      v1->mSocialHubProperties.p[v1->mCurrentIndex].mLBD->mImage.mData);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, v5.mData);
    v1->mCurrentIndex = -1;
    UFG::qString::~qString(&v5);
  }
}

// File Line: 2675
// RVA: 0x612910
void __fastcall UFG::UIHKScreenSocialHub::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenSocialHub *v2; // rax

  v2 = (UFG::UIHKScreenSocialHub *)UFG::UIScreenManagerBase::getScreen(
                                     (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                     "SocialHub");
  if ( v2 )
    UFG::UIHKScreenSocialHub::FLASH_LoadRHSTexture(v2);
}

// File Line: 2685
// RVA: 0x60D690
void __fastcall UFG::UIHKScreenSocialHub::ShowFirstTimeIntro(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v1 = this;
  `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2 = v1->mRenderable->m_movie.pObject;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = "$SOCIAL_HUB_INFO";
  Scaleform::GFx::Movie::Invoke(v2, "ShowFirstTimeIntro", 0i64, &pargs, 1u);
  v1->mPopupActive = 1;
  `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

