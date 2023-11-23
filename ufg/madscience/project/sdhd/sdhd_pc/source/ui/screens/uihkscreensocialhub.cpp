// File Line: 122
// RVA: 0x1566DA0
__int64 dynamic_initializer_for__UFG::UIHKScreenSocialHub::gLeaderboardEntries__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenSocialHub::gLeaderboardEntries__);
}

// File Line: 137
// RVA: 0x156AA50
__int64 UFG::_dynamic_initializer_for__UI_HASH_CHALLENGE_BUTTON_ACCEPTED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CHALLENGE_BUTTON_ACCEPTED", -1);
  UI_HASH_CHALLENGE_BUTTON_ACCEPTED = result;
  return result;
}

// File Line: 138
// RVA: 0x156AA70
__int64 UFG::_dynamic_initializer_for__UI_HASH_CHALLENGE_BUTTON_CANCELED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("CHALLENGE_BUTTON_CANCELED", -1);
  UI_HASH_CHALLENGE_BUTTON_CANCELED = result;
  return result;
}

// File Line: 139
// RVA: 0x156D670
__int64 UFG::_dynamic_initializer_for__UI_HASH_TAB_ANIM_COMPLETE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("TAB_ANIM_COMPLETE", -1);
  UI_HASH_TAB_ANIM_COMPLETE = result;
  return result;
}

// File Line: 140
// RVA: 0x156DA10
__int64 UFG::_dynamic_initializer_for__UI_HASH_UPDATE_RHS__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("UPDATE_RHS", -1);
  UI_HASH_UPDATE_RHS = result;
  return result;
}

// File Line: 141
// RVA: 0x156C1D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_MOVE_LEFT_LIST__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_MOVE_LEFT_LIST", -1);
  UI_HASH_MOUSE_MOVE_LEFT_LIST = result;
  return result;
}

// File Line: 142
// RVA: 0x156C210
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_MOVE_RIGHT_LIST__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_MOVE_RIGHT_LIST", -1);
  UI_HASH_MOUSE_MOVE_RIGHT_LIST = result;
  return result;
}

// File Line: 147
// RVA: 0x605700
void __fastcall UFG::UIHKScreenSocialHub::SocialHubProperty::SetCopTriadPercent(
        UFG::UIHKScreenSocialHub::SocialHubProperty *this,
        UFG::GameSlice *gameslice)
{
  UFG::qPropertySet *RewardsProperties; // rsi
  UFG::qArray<unsigned long,0> *v5; // rax
  int *v6; // rax
  int v7; // ebp
  UFG::qArray<unsigned long,0> *v8; // rax
  int *v9; // rax
  int v10; // esi
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float Stat; // xmm2_4
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  this->mCopPercent = -1.0;
  this->mTriadPercent = -1.0;
  if ( gameslice )
  {
    RewardsProperties = UFG::GameSlice::GetRewardsProperties(gameslice);
    v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "CopStartingScore");
    v6 = UFG::qPropertySet::Get<long>(RewardsProperties, v5, DEPTH_RECURSE);
    if ( v6 )
      v7 = *v6;
    else
      v7 = 0;
    v8 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "MaxTriadScore");
    v9 = UFG::qPropertySet::Get<long>(RewardsProperties, v8, DEPTH_RECURSE);
    if ( v9 )
      v10 = *v9;
    else
      v10 = 0;
    v11 = UFG::GameStatTracker::Instance();
    this->mCopPercent = (float)(int)UFG::GameStatTracker::GetStat(v11, CopScore, (UFG::qSymbol *)&gameslice->mNode.mUID);
    v12 = UFG::GameStatTracker::Instance();
    Stat = (float)(int)UFG::GameStatTracker::GetStat(v12, TriadScore, (UFG::qSymbol *)&gameslice->mNode.mUID);
    this->mTriadPercent = Stat;
    if ( v7 > 0 )
      this->mCopPercent = this->mCopPercent / (float)v7;
    else
      this->mCopPercent = 0.0;
    if ( v10 > 0 )
      this->mTriadPercent = Stat / (float)v10;
    else
      this->mTriadPercent = 0.0;
  }
}

// File Line: 185
// RVA: 0x5F1AE0
void __fastcall UFG::UIHKScreenSocialHub::LoadTextures(
        UFG::qReflectInventoryBase *callback,
        UFG::qReflectInventoryBase *callbackParam)
{
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax

  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenSocialHub::gTexturePackFilename,
    HIGH_PRIORITY,
    callback,
    callbackParam);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v5,
    UFG::UIHKScreenPauseMenu::gTexturePackFilename,
    HIGH_PRIORITY,
    callback,
    callbackParam);
}

// File Line: 190
// RVA: 0x5D4140
__int64 __fastcall UFG::UIHKScreenSocialHub::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax
  bool IsTexturePackLoaded; // bl
  UFG::UIScreenTextureManager *v2; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  IsTexturePackLoaded = UFG::UIScreenTextureManager::IsTexturePackLoaded(
                          v0,
                          UFG::UIHKScreenSocialHub::gTexturePackFilename);
  v2 = UFG::UIScreenTextureManager::Instance();
  return IsTexturePackLoaded & (unsigned __int8)UFG::UIScreenTextureManager::IsTexturePackLoaded(
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
  UFG::OnlineManagerObserver *v2; // rdx
  UFG::OSuiteManagerObserver *v3; // rcx

  this->UFG::UIScreen::UFG::qNode<UFG::UIScreen,UFG::UIScreen>::mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->UFG::UIScreen::UFG::qNode<UFG::UIScreen,UFG::UIScreen>::mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  v2 = &this->UFG::OnlineManagerObserver;
  this->UFG::OnlineManagerObserver::UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>::mPrev = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->UFG::OnlineManagerObserver::UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>::mNext = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v3 = &this->UFG::OSuiteManagerObserver;
  v3->mPrev = &v3->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  v3->mNext = &v3->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  v3->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSocialHub::`vftable{for `UFG::UIScreen};
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable{for `UFG::OnlineManagerObserver};
  v3->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable{for `UFG::OSuiteManagerObserver};
  this->mSocialHubProperties.p = 0i64;
  *(_QWORD *)&this->mSocialHubProperties.size = 0i64;
  this->mCurrentIndex = -1;
  this->mHandleMessageDisabled = 0;
  this->mPopulateRhsListAsyncRequested = 0;
  *(_QWORD *)&this->mTimeElapsedAfterMoving = 0i64;
  *(_QWORD *)&this->mCurrentLeaderboardType = 0i64;
  *(_QWORD *)&this->mMaxTabs = 3i64;
  this->mLastListTouchedByMouse = -1;
  this->mChallengeDialogPopupEntries.mNode.mPrev = &this->mChallengeDialogPopupEntries.mNode;
  this->mChallengeDialogPopupEntries.mNode.mNext = &this->mChallengeDialogPopupEntries.mNode;
  if ( this->mSocialHubProperties.capacity < 0x100 )
    UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0>::Reallocate(
      (UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *)&this->mSocialHubProperties,
      0x100u,
      "qArray.Reallocate(Reserve)");
}

// File Line: 229
// RVA: 0x5CC750
void __fastcall UFG::UIHKScreenSocialHub::~UIHKScreenSocialHub(UFG::UIHKScreenSocialHub *this)
{
  UFG::OnlineManagerObserver *v2; // r14
  UFG::OnlineManagerObserver *v3; // rsi
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v5; // eax
  unsigned int v6; // eax
  UFG::OnlineManager *v7; // rax
  UFG::OnlineManager *v8; // rax
  UFG::UIScreenTextureManager *v9; // rax
  UFG::UI *v10; // rcx
  UFG::UIScreenTextureManager *v11; // rax
  ANTLR3_INPUT_STREAM_struct *v12; // rax
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *mPrev; // rcx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *mNext; // rax
  UFG::UIHKScreenSocialHub::SocialHubProperty *p; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v16; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v17; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v18; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v19; // rax

  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSocialHub::`vftable{for `UFG::UIScreen};
  v2 = &this->UFG::OnlineManagerObserver;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable{for `UFG::OnlineManagerObserver};
  v3 = (UFG::OnlineManagerObserver *)&this->UFG::OSuiteManagerObserver;
  this->UFG::OSuiteManagerObserver::vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenSocialHub::`vftable{for `UFG::OSuiteManagerObserver};
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v5 = UFG::qStringHash32("UIHKScreenSocialHub", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
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
  UFG::UIHKScreenSocialHub::ReleaseTexturePack(this);
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v9, "SocialHub");
  if ( UFG::UIHKScreenSocialHub::gPushedFromPauseMenu )
  {
    if ( this->mLaunchingMissionReplay )
    {
      if ( UFG::UIHKPlayerObjectiveManager::mInstance )
        *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
      UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "OpeningCredits");
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
  if ( this->mLaunchingMissionReplay )
  {
    UFG::UIHKScreenHud::ClearPDACache();
    v12 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::SetGameState(v12, 8u);
    UFG::LoadingLogic::SetForceLoadScreenOn(&UFG::gLoadingLogic);
  }
  UFG::UIHKScreenSocialHub::gPushedFromPauseMenu = 0;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mChallengeDialogPopupEntries);
  mPrev = this->mChallengeDialogPopupEntries.mNode.mPrev;
  mNext = this->mChallengeDialogPopupEntries.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mChallengeDialogPopupEntries.mNode.mPrev = &this->mChallengeDialogPopupEntries.mNode;
  this->mChallengeDialogPopupEntries.mNode.mNext = &this->mChallengeDialogPopupEntries.mNode;
  p = this->mSocialHubProperties.p;
  if ( p )
    operator delete[](p);
  this->mSocialHubProperties.p = 0i64;
  *(_QWORD *)&this->mSocialHubProperties.size = 0i64;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v16 = v3->mPrev;
  v17 = v3->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v3->mPrev = &v3->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v3->mNext = &v3->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v18 = v2->mPrev;
  v19 = v2->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v2->mPrev = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->mNext = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  UFG::UIScreen::~UIScreen(this);
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
  int v10; // r8d
  UFG::OnlineManager *v11; // rax
  UFG::OnlineManager *v12; // rax
  UFG::OnlineManager *v13; // rax
  UFG::OSuiteManager *v14; // rax
  int v15; // r14d
  UFG::OSuiteLeaderboardManager *v16; // r8
  __int64 size; // rcx
  char Type; // di
  __int64 v19; // r12
  __int64 v20; // r9
  UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *p_mSocialHubProperties; // r15
  __int64 v22; // rdi
  unsigned int v23; // ebx
  unsigned int capacity; // edx
  unsigned int v25; // edx
  UFG::UIHKScreenSocialHub::SocialHubProperty *v26; // rsi
  UFG::OSuiteLeaderboardData *p; // rax
  unsigned int mCategory; // edi
  UFG::qBaseTreeRB *v29; // r13
  UFG::qSymbol *v30; // rbx
  UFG::ProgressionTracker *v31; // rax
  UFG::OSuiteLeaderboardData *v32; // rbx
  unsigned int mUID; // ecx
  UFG::OSuiteLeaderboardManager *v34; // rax
  UFG::qSymbol *p_mLeaderboardName; // rbx
  UFG::GameStatTracker *v36; // rax
  UFG::qStaticSymbol *DefaultFlow; // rbx
  UFG::ProgressionTracker *v38; // rax
  UFG::OSuiteLeaderboardData *v39; // rbx
  UFG::ProgressionTracker *v40; // rax
  int v41; // eax
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rcx
  UFG::SocialLogDataManager *v44; // rax
  UFG::GameStatTracker *v45; // rax
  UFG::GameStatTracker *v46; // rax
  UFG::OSuiteLeaderboardManager *v47; // [rsp+30h] [rbp-99h]
  __int64 v48; // [rsp+38h] [rbp-91h]
  __int64 v49; // [rsp+40h] [rbp-89h]
  Scaleform::GFx::Value ptr[3]; // [rsp+50h] [rbp-79h] BYREF
  UFG::qSymbol *p_symGameSliceName; // [rsp+E0h] [rbp+17h]
  __int64 v52; // [rsp+E8h] [rbp+1Fh]
  UFG::qSymbol symGameSliceName; // [rsp+140h] [rbp+77h] BYREF
  int v55; // [rsp+148h] [rbp+7Fh]

  v52 = -2i64;
  v2 = this;
  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  if ( v2 )
    v4 = &v2->UFG::OnlineManagerObserver;
  else
    v4 = 0i64;
  v5 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v5, v4);
  if ( v2 )
    v6 = &v2->UFG::OSuiteManagerObserver;
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
      if ( UFG::OnlineManager::IsNetworkAvailable(v12) )
      {
        v13 = UFG::OnlineManager::Instance();
        if ( !UFG::OnlineManager::IsNetworkAvailable(v13) )
          UFG::UIScreenDialogBox::createOKDialog(0i64, &customCaption, gFirstPartySignedOut, 1);
      }
    }
  }
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(v2);
  v15 = 0;
  v16 = UFG::OSuiteLeaderboardManager::Instance();
  v47 = v16;
  size = v16->mLeaderboardData.size;
  v55 = 0;
  Type = 2;
  if ( (_DWORD)size )
  {
    v19 = 0i64;
    v20 = 0i64;
    v48 = 0i64;
    v49 = size;
    p_mSocialHubProperties = (UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0> *)&v2->mSocialHubProperties;
    while ( 1 )
    {
      v22 = p_mSocialHubProperties->size;
      v23 = v22 + 1;
      capacity = p_mSocialHubProperties->capacity;
      if ( (int)v22 + 1 > capacity )
      {
        if ( capacity )
          v25 = 2 * capacity;
        else
          v25 = 1;
        for ( ; v25 < v23; v25 *= 2 )
          ;
        if ( v25 - v23 > 0x10000 )
          v25 = v22 + 65537;
        UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0>::Reallocate(
          p_mSocialHubProperties,
          v25,
          "qArray.Add");
        v16 = v47;
        v20 = v48 * 312;
      }
      p_mSocialHubProperties->size = v23;
      v26 = (UFG::UIHKScreenSocialHub::SocialHubProperty *)&p_mSocialHubProperties->p[v22];
      p = v16->mLeaderboardData.p;
      mCategory = p[v19].mCategory;
      v29 = 0i64;
      if ( mCategory == 2 )
      {
        v30 = (UFG::qSymbol *)((char *)p + v20);
        v31 = UFG::ProgressionTracker::Instance();
        v29 = UFG::ProgressionTracker::Find(v31, v30 + 36, 0);
        v16 = v47;
      }
      v32 = v16->mLeaderboardData.p;
      mUID = v32[v19].mSliceName.mUID;
      if ( mUID != -1 )
        break;
LABEL_45:
      if ( mCategory > 1
        || (v39 = v16->mLeaderboardData.p, v39[v19].mFlow.mUID != -1)
        && (v40 = UFG::ProgressionTracker::Instance(),
            v39[v19].mFlow.mUID != UFG::ProgressionTracker::GetActiveFlow(v40)->mUID) )
      {
        v26->mUIItemIndex = -1;
        goto LABEL_50;
      }
LABEL_48:
      v41 = v55;
      v26->mUIItemIndex = v55;
      v55 = v41 + 1;
LABEL_50:
      UFG::UIHKScreenSocialHub::SocialHubProperty::SetCopTriadPercent(v26, (UFG::GameSlice *)v29);
      v16 = v47;
      v26->mLBD = &v47->mLeaderboardData.p[v48];
      v20 = v48 * 312 + 312;
      ++v48;
      ++v19;
      if ( !--v49 )
      {
        v2 = this;
        Type = 2;
        goto LABEL_52;
      }
    }
    p_symGameSliceName = &symGameSliceName;
    symGameSliceName.mUID = mUID;
    if ( UFG::GameStatAction::GameSliceAction::IsCompleted(&symGameSliceName.mUID) )
    {
      UFG::ProgressionTracker::Instance();
    }
    else
    {
      v34 = UFG::OSuiteLeaderboardManager::Instance();
      p_mLeaderboardName = &UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(v34, &v32[v19].mSliceName)->mLeaderboardName;
      v36 = UFG::GameStatTracker::Instance();
      if ( (int)UFG::GameStatTracker::GetStat(v36, LeaderboardScoreIntList, p_mLeaderboardName) <= 0 )
      {
LABEL_44:
        v16 = v47;
        goto LABEL_45;
      }
    }
    DefaultFlow = UFG::ProgressionTracker::GetDefaultFlow();
    v38 = UFG::ProgressionTracker::Instance();
    if ( UFG::ProgressionTracker::GetActiveFlow(v38)->mUID == DefaultFlow->mUID )
    {
      if ( v15 < 1 && mCategory == 2 )
      {
        v15 = 1;
      }
      else if ( v15 < 2 && mCategory == 3 )
      {
        v15 = 2;
      }
      goto LABEL_48;
    }
    goto LABEL_44;
  }
LABEL_52:
  pObject = v2->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  pObjectInterface = ptr[0].pObjectInterface;
  if ( (ptr[0].Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr[0].pObjectInterface->vfptr->gap8[8])(
      ptr[0].pObjectInterface,
      ptr,
      ptr[0].mValue);
    pObjectInterface = 0i64;
    ptr[0].pObjectInterface = 0i64;
  }
  ptr[0].Type = VT_Boolean;
  ptr[0].mValue.BValue = 0;
  v2->mMaxTabs += v15;
  if ( v15 >= 1 )
  {
    ptr[0].Type = VT_String;
    ptr[0].mValue.pString = "$HUD_SOCIAL_HD04";
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHub_AddTab", 0i64, ptr, 1u);
    Type = ptr[0].Type;
    pObjectInterface = ptr[0].pObjectInterface;
  }
  if ( v15 >= 2 )
  {
    if ( (Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pObjectInterface->vfptr->gap8[8])(
        pObjectInterface,
        ptr,
        ptr[0].mValue);
      ptr[0].pObjectInterface = 0i64;
    }
    ptr[0].Type = VT_String;
    ptr[0].mValue.pString = "$HUD_SOCIAL_HD05";
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHub_AddTab", 0i64, ptr, 1u);
  }
  Scaleform::GFx::Movie::Invoke(pObject, "SetupSocialLogView", 0i64, 0i64, 0);
  UFG::UIHKScreenSocialHub::PopulateLhsList(v2, 0);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(v2, 0, 0);
  UFG::UIHKScreenSocialHub::UpdateOnlineName(v2);
  v44 = UFG::SocialLogDataManager::Instance();
  UFG::SocialLogDataManager::SetHasNewChallengeMessageFlag(v44, 0);
  v45 = UFG::GameStatTracker::Instance();
  if ( !UFG::GameStatTracker::GetStat(v45, SocialHubVisited) )
  {
    v46 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v46, SocialHubVisited, 1);
    UFG::UIHKScreenSocialHub::ShowFirstTimeIntro(v2);
  }
  `eh vector destructor iterator(ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 386
// RVA: 0x63FAA0
void __fastcall UFG::UIHKScreenSocialHub::update(UFG::UIHKScreenSocialHub *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::OSuiteManager *v4; // rax
  unsigned int v5; // edx
  UFG::InputActionData *v6; // rax
  UFG::InputActionData *v7; // rcx
  UFG::qString v8; // [rsp+48h] [rbp-70h] BYREF
  UFG::qString v9; // [rsp+70h] [rbp-48h] BYREF

  UFG::UIScreen::update(this, elapsed);
  if ( this->mHandleMessageDisabled && this->mTimeElapsedAfterMoving > 10.0 )
  {
    pObject = this->mRenderable->m_movie.pObject;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
    this->mHandleMessageDisabled = 0;
    v4 = UFG::OSuiteManager::Instance();
    UFG::OSuiteManager::Disconnect(v4);
    UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(this);
    UFG::UIHKScreenSocialHub::PopulateRhsListAsync(this, this->mCurrentScreenType, this->mCurrentLeaderboardType);
  }
  if ( this->mPopulateRhsListAsyncRequested && this->mTimeElapsedAfterMoving > 0.40000001 )
  {
    UFG::UIHKScreenSocialHub::PopulateRhsListAsync(this, this->mCurrentScreenType, this->mCurrentLeaderboardType);
    this->mPopulateRhsListAsyncRequested = 0;
  }
  if ( UFG::UIHKScreenSocialHub::gCallPopulateChallengeList )
  {
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(
      this->mRenderable->m_movie.pObject,
      "SocialLogList_HideL1R1HelpButtons",
      0i64,
      0i64,
      0);
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      UFG::UIHKScreenSocialHub::PopulateChallengeList(this);
    }
    else
    {
      UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(this);
      this->mHandleMessageDisabled = 0;
    }
    UFG::UIHKScreenSocialHub::gCallPopulateChallengeList = 0;
  }
  else if ( UFG::UIHKScreenSocialHub::gCallPopulateRhsList )
  {
    if ( UFG::OSuiteManager::Instance()->m_bConnected )
    {
      UFG::UIHKScreenSocialHub::PopulateRhsList(this);
    }
    else
    {
      UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(this);
      UFG::UIHKScreenSocialHub::PopulateRhsListAsync(this, this->mCurrentScreenType, this->mCurrentLeaderboardType);
    }
    UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 0;
  }
  if ( UFG::UIHKScreenSocialHub::gPopupRequestStatus == PopupRequestStatus_SendMessageSucceeded )
  {
    UFG::qString::qString(&v9, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customCaption,
      "$HUD_SOCIAL_SENDCJALLENGE",
      v9.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v9);
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = PopupRequestStatus_None;
    this->mHandleMessageDisabled = 0;
    UFG::UIHKScreenSocialHub::SetFlagAsSentForNewHighScoreSaveEntry(this, UFG::UIHKScreenSocialHub::gOSuiteMessage);
    if ( UFG::UIHKScreenSocialHub::gOSuiteMessage )
      UFG::UIHKScreenSocialHub::gOSuiteMessage->vfptr->__vecDelDtor(UFG::UIHKScreenSocialHub::gOSuiteMessage, 1i64);
    UFG::UIHKScreenSocialHub::gOSuiteMessage = 0i64;
    UFG::UIHKScreenSocialHub::FLASH_FocusTab(this, this->mCurrentScreenType);
    UFG::UIHKScreenSocialHub::PopulateLhsList(this, this->mCurrentScreenType);
    UFG::UIHKScreenSocialHub::ShowHelpBarWidget(this, this->mCurrentScreenType, 0);
    goto LABEL_23;
  }
  if ( UFG::UIHKScreenSocialHub::gPopupRequestStatus == PopupRequestStatus_SendMessageFailed )
  {
    UFG::qString::qString(&v8, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customCaption,
      "$HUD_SOCIAL_FAILSEND",
      v8.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v8);
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = PopupRequestStatus_None;
    this->mHandleMessageDisabled = 0;
LABEL_23:
    this->mDisplayingChallengeDialog = 0;
  }
  if ( !this->mHandleMessageDisabled && !this->mPopupActive )
  {
    v5 = UFG::gActiveControllerNum;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v6 = UFG::ActionDef_UIUpPressed.mDataPerController[UFG::gActiveControllerNum];
      if ( v6 && v6->mActionTrue )
      {
        UFG::UIHKScreenSocialHub::OnScrollUpDown(this, UI_HASH_THUMBSTICK_RIGHT_UP_30);
        v5 = UFG::gActiveControllerNum;
      }
      v7 = UFG::ActionDef_UIDownPressed.mDataPerController[v5];
      if ( v7 && v7->mActionTrue )
        UFG::UIHKScreenSocialHub::OnScrollUpDown(this, UI_HASH_THUMBSTICK_RIGHT_DOWN_30);
    }
  }
  this->mTimeElapsedAfterMoving = elapsed + this->mTimeElapsedAfterMoving;
}

// File Line: 559
// RVA: 0x5F2430
void __fastcall UFG::UIHKScreenSocialHub::NetworkSignedIn(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub::UpdateOnlineName((UFG::UIHKScreenSocialHub *)((char *)this - 144));
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(
    (UFG::UIHKScreenSocialHub *)((char *)this - 144),
    *(_DWORD *)&this->m_screenName[52],
    0);
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon((UFG::UIHKScreenSocialHub *)((char *)this - 144));
}

// File Line: 568
// RVA: 0x5F2590
void __fastcall UFG::UIHKScreenSocialHub::NetworkSignedOut(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *v2; // rsi
  const char *v3; // rbx
  UFG::OnlineManager *v4; // rax
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-B8h] BYREF
  char v7[8]; // [rsp+70h] [rbp-88h] BYREF
  __int64 v8; // [rsp+78h] [rbp-80h]
  int v9; // [rsp+80h] [rbp-78h]
  const char *v10; // [rsp+88h] [rbp-70h]
  char v11[16]; // [rsp+98h] [rbp-60h] BYREF
  __int64 v12; // [rsp+A8h] [rbp-50h]
  int v13; // [rsp+B0h] [rbp-48h]
  char *v14; // [rsp+B8h] [rbp-40h]
  __int64 v15; // [rsp+C8h] [rbp-30h]
  UFG::qString v16; // [rsp+D0h] [rbp-28h] BYREF
  UFG::qString result; // [rsp+F8h] [rbp+0h] BYREF

  v15 = -2i64;
  v2 = *(Scaleform::GFx::Movie **)(*(_QWORD *)&this[-1].mTimeElapsedAfterMoving + 320i64);
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Boolean;
  ptr.mValue.BValue = 0;
  v3 = gIconSocialHubAvatarPlayer_21;
  if ( (v9 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v8 + 16i64))(v8, v7, v10);
    v8 = 0i64;
  }
  v9 = 6;
  v10 = v3;
  v4 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::GetOnlineName(v4, &result);
  mData = result.mData;
  if ( (v13 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
    v12 = 0i64;
  }
  v13 = 6;
  v14 = mData;
  Scaleform::GFx::Movie::Invoke(v2, "SetIsOnline", 0i64, &ptr, 3u);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(
    (UFG::UIHKScreenSocialHub *)((char *)this - 144),
    *(_DWORD *)&this->m_screenName[52],
    0);
  if ( UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)&this[-1].mInputEnabled
    || *((_BYTE *)&this->m_screenNameHash + 7) == 1 )
  {
    UFG::qString::qString(&v16, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      (UFG::UIHKScreenSocialHub *)((char *)this - 144),
      &customCaption,
      "$COMMON_TRC_PC_CONNECTION_FAILED",
      v16.mData,
      UI_HASH_DIALOG_OK_30,
      0,
      "DialogBox");
    UFG::qString::~qString(&v16);
  }
  UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon((UFG::UIHKScreenSocialHub *)((char *)this - 144));
  UFG::qString::~qString(&result);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
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
void __fastcall UFG::UIHKScreenSocialHub::ShowHelpBarWidget(
        UFG::UIHKScreenSocialHub *this,
        int screenType,
        bool enableProfileButton)
{
  int v6; // esi
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  bool v9; // al
  UFG::qSymbol *CurrentItemGameSliceName; // rax
  const char *v11; // r8
  unsigned int v12; // r14d
  int v13; // ecx
  __int64 v14; // rax
  __int64 v15; // rdi
  __int64 v16; // rbx
  unsigned int v17; // r14d
  int v18; // ecx
  __int64 v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rbx
  unsigned int v22; // r14d
  int v23; // ecx
  __int64 v24; // rax
  __int64 v25; // rdi
  __int64 v26; // rbx
  unsigned int v27; // r14d
  __int64 v28; // rax
  unsigned int v29; // r14d
  int v30; // ecx
  __int64 v31; // rax
  __int64 v32; // rdi
  __int64 v33; // rbx
  unsigned int v34; // r14d
  int v35; // ecx
  __int64 v36; // rax
  __int64 v37; // rdi
  __int64 v38; // rbx
  unsigned int v39; // r14d
  int v40; // ecx
  __int64 v41; // rax
  __int64 v42; // rdi
  __int64 v43; // rbx
  __int64 v44; // rax
  UFG::OnlineManager *v45; // rax
  UFG::SocialLogDataManager *v46; // rax
  UFG::SocialLogDataManager *v47; // rax
  unsigned int v48; // r15d
  int v49; // ecx
  __int64 v50; // rax
  __int64 v51; // rdi
  __int64 v52; // rbx
  unsigned int v53; // r15d
  int v54; // ecx
  __int64 v55; // rax
  __int64 v56; // rdi
  __int64 v57; // rbx
  UFG::OnlineManager *v58; // rax
  unsigned int v59; // r14d
  int v60; // ecx
  __int64 v61; // rax
  __int64 v62; // rdi
  __int64 v63; // rbx
  unsigned int v64; // r14d
  int v65; // ecx
  __int64 v66; // rax
  __int64 v67; // rdi
  __int64 v68; // rbx
  unsigned int v69; // r14d
  __int64 v70; // rax
  UFG::UIHKScreenGlobalOverlay *v71; // rdi
  UFG::UIHKScreenGlobalOverlay *v72; // rax
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-C8h] BYREF

  data.CustomTexturePack.mData = (char *)-2i64;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32("UIHKScreenSocialHub", 0xFFFFFFFF);
  v6 = 0;
  *(_QWORD *)&data.priority = 0i64;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    goto LABEL_90;
  v7 = UFG::GameStatTracker::Instance();
  MapBool = UFG::GameStatTracker::GetMapBool(v7, Collectible_Safehouse);
  v9 = (unsigned int)UFG::PersistentData::MapBool::GetTrueCount(MapBool) != 0;
  if ( !screenType )
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
        data.Buttons[v49] = ACCEPT_BUTTON;
        v52 = v49;
        UFG::qString::Set(&data.Captions[v49], "$HELPBAR_MORE_INFO");
        UFG::qString::Set((UFG::qString *)&data.Captions[v52 + 5].mMagic, &customCaption);
        data.MessageIds[v51 - 6] = v48;
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
    data.Buttons[v54] = BACK_BUTTON;
    v57 = v54;
    UFG::qString::Set(&data.Captions[v54], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v57 + 5].mMagic, &customCaption);
    data.MessageIds[v56 - 6] = v53;
LABEL_67:
    if ( UFG::UIHKScreenSocialHub::IsChallengeableEntry(this) )
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
        data.Buttons[v60] = BUTTON1_BUTTON;
        v63 = v60;
        UFG::qString::Set(&data.Captions[v60], "$HUD_SOCIAL_CHALLENGE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v63 + 5].mMagic, &customCaption);
        data.MessageIds[v62 - 6] = v59;
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
    data.Buttons[v65] = BUTTON2_BUTTON;
    v68 = v65;
    UFG::qString::Set(&data.Captions[v65], "$BUTTON_SOCIAL_HELP");
    UFG::qString::Set((UFG::qString *)&data.Captions[v68 + 5].mMagic, &customCaption);
    data.MessageIds[v67 - 6] = v64;
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
      data.Buttons[v6] = L1R1_BUTTON;
      UFG::qString::Set(&data.Captions[v6], "$HELPBAR_CHANGE_SECTION_UC");
      UFG::qString::Set((UFG::qString *)&data.Captions[v6 + 5].mMagic, &customCaption);
      data.MessageIds[v6 - 6] = v69;
    }
    goto LABEL_85;
  }
  if ( screenType > 0 )
  {
    if ( screenType <= 2 )
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
      data.Buttons[v30] = BACK_BUTTON;
      v33 = v30;
      UFG::qString::Set(&data.Captions[v30], "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[v33 + 5].mMagic, &customCaption);
      data.MessageIds[v32 - 6] = v29;
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
      data.Buttons[v35] = BUTTON2_BUTTON;
      v38 = v35;
      UFG::qString::Set(&data.Captions[v35], "$BUTTON_SOCIAL_HELP");
      UFG::qString::Set((UFG::qString *)&data.Captions[v38 + 5].mMagic, &customCaption);
      data.MessageIds[v37 - 6] = v34;
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
        data.Buttons[v40] = L1R1_BUTTON;
        v43 = v40;
        UFG::qString::Set(&data.Captions[v40], "$HELPBAR_CHANGE_SECTION_UC");
        UFG::qString::Set((UFG::qString *)&data.Captions[v43 + 5].mMagic, &customCaption);
        data.MessageIds[v42 - 6] = v39;
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
    if ( screenType <= 4 )
    {
      if ( v9 )
      {
        CurrentItemGameSliceName = UFG::UIHKScreenSocialHub::GetCurrentItemGameSliceName(this);
        if ( (unsigned int)UFG::UIHKScreenSocialHub::ShouldShowGameSlice(this, CurrentItemGameSliceName) == 2 )
        {
          v11 = "$HUD_SOCIAL_REPLAYRACE";
          if ( screenType == 3 )
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
      data.Buttons[v13] = BACK_BUTTON;
      v16 = v13;
      UFG::qString::Set(&data.Captions[v13], "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[v16 + 5].mMagic, &customCaption);
      data.MessageIds[v15 - 6] = v12;
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
      data.Buttons[v18] = BUTTON2_BUTTON;
      v21 = v18;
      UFG::qString::Set(&data.Captions[v18], "$BUTTON_SOCIAL_HELP");
      UFG::qString::Set((UFG::qString *)&data.Captions[v21 + 5].mMagic, &customCaption);
      data.MessageIds[v20 - 6] = v17;
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
        data.Buttons[v23] = L1R1_BUTTON;
        v26 = v23;
        UFG::qString::Set(&data.Captions[v23], "$HELPBAR_CHANGE_SECTION_UC");
        UFG::qString::Set((UFG::qString *)&data.Captions[v26 + 5].mMagic, &customCaption);
        data.MessageIds[v25 - 6] = v22;
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
      data.Buttons[v6] = R3_BUTTON;
      UFG::qString::Set(&data.Captions[v6], "$HUD_SOCIAL_TOGGLE");
      UFG::qString::Set((UFG::qString *)&data.Captions[v6 + 5].mMagic, &customCaption);
      data.MessageIds[v6 - 6] = v27;
LABEL_52:
      v45 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v45) && enableProfileButton )
        UFG::UIHKHelpBarData::Add(&data, SELECT_BUTTON, gLocTag_Gamertag, UI_HASH_BUTTON_SELECT_PRESSED_30);
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
  v71->HelpBar.mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v71->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
  v71->HelpBar.mYOffset = -20.0;
LABEL_90:
  UFG::qString::~qString((UFG::qString *)data.MessageIds);
  `eh vector destructor iterator(
    &data.Captions[5].mMagic,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
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
  Scaleform::GFx::Movie *pObject; // rcx
  const char *v2; // rdx

  pObject = this->mRenderable->m_movie.pObject;
  v2 = "SocialLogList_HideL1R1HelpButtons";
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    v2 = "SocialLogList_ShowL1R1HelpButtons";
  Scaleform::GFx::Movie::Invoke(pObject, v2, 0i64, 0i64, 0);
}

// File Line: 797
// RVA: 0x600970
void __fastcall UFG::UIHKScreenSocialHub::RefreshScreenType(UFG::UIHKScreenSocialHub *this)
{
  UFG::UIHKScreenSocialHub::FLASH_FocusTab(this, this->mCurrentScreenType);
  UFG::UIHKScreenSocialHub::PopulateLhsList(this, this->mCurrentScreenType);
  UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(this);
  UFG::UIHKScreenSocialHub::RequestRhsListPopulation(this);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(this, this->mCurrentScreenType, 0);
}

// File Line: 809
// RVA: 0x5F9D40
void __fastcall UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  int v2; // edx
  hkGeometryUtils::IVertices *v3; // rcx
  int v4; // r8d
  const char *v5; // rbx
  const char *v6; // rdx
  UFG::OnlineManager *v7; // rax
  UFG::OnlineManager *v8; // rax
  bool IsNetworkAvailable; // al
  const char *v10; // rcx
  const char *v11; // rax
  hkgpIndexedMeshDefinitions::Edge *v12; // rdx
  bool v13; // al
  char *mData; // rbx
  UFG::qString v15; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+58h] [rbp-19h] BYREF
  char v17[16]; // [rsp+88h] [rbp+17h] BYREF
  __int64 v18; // [rsp+98h] [rbp+27h]
  int v19; // [rsp+A0h] [rbp+2Fh]
  char *v20; // [rsp+A8h] [rbp+37h]
  __int64 v21; // [rsp+B8h] [rbp+47h]

  v21 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  UFG::qString::qString(&v15);
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v3, v2, v4) )
  {
    v7 = UFG::OnlineManager::Instance();
    if ( !UFG::OnlineManager::IsNetworkSignedIn(v7) )
    {
      v5 = "Red";
      v8 = UFG::OnlineManager::Instance();
      IsNetworkAvailable = UFG::OnlineManager::IsNetworkAvailable(v8);
      v10 = gNetworkDisconnectedMessage;
      if ( IsNetworkAvailable )
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
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = v5;
  mData = v15.mData;
  if ( (v19 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
    v18 = 0i64;
  }
  v19 = 6;
  v20 = mData;
  Scaleform::GFx::Movie::Invoke(pObject, "SocialHubOnlineStatusIcon_Show", 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v15);
}

// File Line: 860
// RVA: 0x5F82F0
void __fastcall UFG::UIHKScreenSocialHub::PopulateLhsList(UFG::UIHKScreenSocialHub *this, int screenType)
{
  UFG::UIHKScreenSocialHub *v2; // rdi
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UIHKScreenSocialHub::SocialHubProperty *v4; // r14
  unsigned __int64 v5; // rbx
  UFG::SocialLogDataManager *v6; // rax
  UFG::SocialLogDataManager *List; // rax
  __int64 p_mNext; // rsi
  unsigned __int64 v9; // rbx
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  const char *v12; // rax
  UFG::qString *v13; // rax
  UFG::qString *p_result; // rcx
  unsigned int v15; // eax
  UFG::UIGfxTranslator *v16; // rcx
  const char *v17; // rax
  UFG::qString *v18; // rax
  unsigned int v19; // eax
  UFG::UIGfxTranslator *v20; // rcx
  const char *v21; // rcx
  UFG::qString *v22; // rax
  unsigned int v23; // eax
  UFG::UIGfxTranslator *v24; // rcx
  const char *v25; // rcx
  UFG::qString *v26; // rax
  unsigned int v27; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v29; // rcx
  UFG::qString *v30; // rax
  char *v31; // r12
  char *v32; // r15
  UFG::OSuiteLeaderboardManager *v33; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingId; // rax
  UFG::OSuiteLeaderboardData *v35; // rbx
  UFG::ProgressionTracker *v36; // rax
  __int64 v37; // rdx
  unsigned int v38; // r8d
  UFG::UIHKScreenSocialHub::SocialHubProperty *v39; // r9
  const char *v40; // rdi
  unsigned int v41; // eax
  UFG::UIGfxTranslator *v42; // rcx
  const char *v43; // rax
  int v44; // eax
  UFG::OnlineManager *v45; // rax
  char *v46; // r8
  unsigned int v47; // eax
  UFG::UIGfxTranslator *v48; // rcx
  const char *v49; // rax
  UFG::qString *v50; // rax
  char *v51; // rbx
  int v52; // eax
  unsigned int v53; // eax
  UFG::UIGfxTranslator *v54; // rcx
  unsigned int v55; // eax
  UFG::UIGfxTranslator *v56; // rcx
  unsigned int v57; // eax
  UFG::UIGfxTranslator *v58; // rcx
  UFG::OnlineManager *v59; // rax
  char *v60; // r8
  unsigned int v61; // eax
  UFG::UIGfxTranslator *v62; // rcx
  const char *v63; // rax
  UFG::qString *v64; // rax
  UFG::OnlineManager *v65; // rax
  char *v66; // r8
  unsigned int v67; // eax
  UFG::UIGfxTranslator *v68; // rcx
  const char *v69; // rdx
  UFG::qString *v70; // rax
  UFG::qString *v71; // rbx
  UFG::OnlineManager *v72; // rax
  UFG::OnlineId *OnlineId; // rax
  UFG::qString *v74; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rcx
  char *PlayerDisplayName; // rax
  unsigned int v78; // eax
  UFG::UIGfxTranslator *v79; // rcx
  const char *v80; // rdx
  UFG::qString *v81; // rax
  UFG::qString *v82; // rbx
  UFG::OnlineManager *v83; // rax
  UFG::OnlineId *v84; // rax
  UFG::qString *v85; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v86; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v87; // rax
  Scaleform::GFx::Value::ValueUnion v88; // xmm6_8
  double v89; // xmm6_8
  char *v90; // rbx
  char *v91; // rbx
  char *v92; // rbx
  int v93; // r13d
  int v94; // edx
  int v95; // edx
  int v96; // edx
  unsigned int size; // r14d
  int v98; // edi
  __int64 v99; // rbx
  UFG::UIHKScreenSocialHub::SocialHubProperty *p; // rsi
  __int64 mData; // rsi
  UFG::OnlineId v102; // [rsp+30h] [rbp-D0h] BYREF
  UFG::OnlineId v103; // [rsp+48h] [rbp-B8h] BYREF
  unsigned __int64 v104; // [rsp+60h] [rbp-A0h]
  UFG::qString v105; // [rsp+68h] [rbp-98h] BYREF
  UFG::qString v106; // [rsp+90h] [rbp-70h] BYREF
  UFG::qString v107; // [rsp+B8h] [rbp-48h] BYREF
  UFG::qString formatted; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qString v109; // [rsp+108h] [rbp+8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+130h] [rbp+30h] BYREF
  char v111[16]; // [rsp+160h] [rbp+60h] BYREF
  __int64 v112; // [rsp+170h] [rbp+70h]
  int v113; // [rsp+178h] [rbp+78h]
  double v114; // [rsp+180h] [rbp+80h]
  char v115[16]; // [rsp+190h] [rbp+90h] BYREF
  __int64 v116; // [rsp+1A0h] [rbp+A0h]
  int v117; // [rsp+1A8h] [rbp+A8h]
  double v118; // [rsp+1B0h] [rbp+B0h]
  char v119[16]; // [rsp+1C0h] [rbp+C0h] BYREF
  __int64 v120; // [rsp+1D0h] [rbp+D0h]
  int v121; // [rsp+1D8h] [rbp+D8h]
  char *v122; // [rsp+1E0h] [rbp+E0h]
  char v123[16]; // [rsp+1F0h] [rbp+F0h] BYREF
  __int64 v124; // [rsp+200h] [rbp+100h]
  int v125; // [rsp+208h] [rbp+108h]
  char *v126; // [rsp+210h] [rbp+110h]
  char v127[16]; // [rsp+220h] [rbp+120h] BYREF
  __int64 v128; // [rsp+230h] [rbp+130h]
  int v129; // [rsp+238h] [rbp+138h]
  char *v130; // [rsp+240h] [rbp+140h]
  char v131[16]; // [rsp+250h] [rbp+150h] BYREF
  __int64 v132; // [rsp+260h] [rbp+160h]
  int v133; // [rsp+268h] [rbp+168h]
  char *v134; // [rsp+270h] [rbp+170h]
  char v135[16]; // [rsp+280h] [rbp+180h] BYREF
  __int64 v136; // [rsp+290h] [rbp+190h]
  int v137; // [rsp+298h] [rbp+198h]
  char *v138; // [rsp+2A0h] [rbp+1A0h]
  __int64 v139; // [rsp+2B0h] [rbp+1B0h]
  Scaleform::GFx::Value putf8str; // [rsp+2C0h] [rbp+1C0h] BYREF
  char v141[16]; // [rsp+2F0h] [rbp+1F0h] BYREF
  __int64 v142; // [rsp+300h] [rbp+200h]
  int v143; // [rsp+308h] [rbp+208h]
  __int64 v144; // [rsp+310h] [rbp+210h]
  char v145[16]; // [rsp+320h] [rbp+220h] BYREF
  __int64 v146; // [rsp+330h] [rbp+230h]
  int v147; // [rsp+338h] [rbp+238h]
  const char *v148; // [rsp+340h] [rbp+240h]
  UFG::qString v149; // [rsp+3C0h] [rbp+2C0h] BYREF
  UFG::qString v150; // [rsp+3E8h] [rbp+2E8h] BYREF
  UFG::qString v151; // [rsp+410h] [rbp+310h] BYREF
  UFG::qString v152; // [rsp+438h] [rbp+338h] BYREF
  UFG::qString v153; // [rsp+460h] [rbp+360h] BYREF
  UFG::qString v154; // [rsp+488h] [rbp+388h] BYREF
  UFG::qString v155; // [rsp+4B0h] [rbp+3B0h] BYREF
  UFG::qString v156; // [rsp+4D8h] [rbp+3D8h] BYREF
  UFG::qString v157; // [rsp+500h] [rbp+400h] BYREF
  UFG::qString v158; // [rsp+528h] [rbp+428h] BYREF
  UFG::qString v159; // [rsp+550h] [rbp+450h] BYREF
  UFG::qString v160; // [rsp+578h] [rbp+478h] BYREF
  UFG::qString v161; // [rsp+5A0h] [rbp+4A0h] BYREF
  UFG::qString v162; // [rsp+5C8h] [rbp+4C8h] BYREF
  UFG::qString result; // [rsp+5F0h] [rbp+4F0h] BYREF
  UFG::qString v164; // [rsp+618h] [rbp+518h] BYREF
  char dest[256]; // [rsp+640h] [rbp+540h] BYREF
  wchar_t pbuff[256]; // [rsp+740h] [rbp+640h] BYREF
  wchar_t v167[256]; // [rsp+940h] [rbp+840h] BYREF
  int v169; // [rsp+BA8h] [rbp+AA8h]
  Scaleform::GFx::Movie *v170; // [rsp+BB0h] [rbp+AB0h]
  UFG::SocialLogDataManager *v171; // [rsp+BB8h] [rbp+AB8h]

  v139 = -2i64;
  v2 = this;
  pObject = this->mRenderable->m_movie.pObject;
  v170 = pObject;
  v4 = 0i64;
  v2->mLHSItemCount = 0;
  if ( screenType )
  {
    v93 = -1;
    v94 = screenType - 1;
    if ( v94 )
    {
      v95 = v94 - 1;
      if ( v95 )
      {
        v96 = v95 - 1;
        if ( v96 )
        {
          if ( v96 == 1 )
            v93 = 3;
        }
        else
        {
          v93 = 2;
        }
      }
      else
      {
        v93 = 1;
      }
    }
    else
    {
      v93 = 0;
    }
    size = v2->mSocialHubProperties.size;
    v98 = 0;
    if ( size )
    {
      v99 = 0i64;
      do
      {
        p = this->mSocialHubProperties.p;
        if ( v93 == p[v99].mLBD->mCategory && p[v99].mUIItemIndex != -1 )
        {
          `eh vector constructor iterator(
            &putf8str,
            0x30ui64,
            3,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          if ( (putf8str.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&putf8str.pObjectInterface->vfptr->gap8[8])(
              putf8str.pObjectInterface,
              &putf8str,
              putf8str.mValue);
            putf8str.pObjectInterface = 0i64;
          }
          putf8str.Type = VT_Number;
          putf8str.mValue.NValue = (double)v98;
          mData = (__int64)p[v99].mLBD->mCaption.mData;
          if ( (v143 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v142 + 16i64))(v142, v141, v144);
            v142 = 0i64;
          }
          v143 = 6;
          v144 = mData;
          if ( (v147 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v146 + 16i64))(v146, v145, v148);
            v146 = 0i64;
          }
          v147 = 6;
          v148 = "icon";
          Scaleform::GFx::Movie::Invoke(v170, "SocialHubLhsList_AddItem", 0i64, &putf8str, 3u);
          ++this->mLHSItemCount;
          `eh vector destructor iterator(
            &putf8str,
            0x30ui64,
            3,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        }
        ++v98;
        ++v99;
      }
      while ( v98 < size );
      pObject = v170;
    }
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLhsList_Refresh", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v170, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
  }
  else
  {
    v5 = (UFG::qGetSystemTimeUTC() - 116444736000000000i64) / 0x2710;
    v104 = v5;
    v6 = UFG::SocialLogDataManager::Instance();
    List = UFG::SocialLogDataManager::GetList(v6);
    p_mNext = (__int64)&List->m_lSocialLogDataList.mNode.mPrev[-2].mNext;
    v171 = List - 1;
    if ( (UFG::SocialLogDataManager *)p_mNext != &List[-1] )
    {
      while ( 1 )
      {
        UFG::qString::qString(&v105);
        v9 = (v5 - *(_QWORD *)(p_mNext + 48)) / 0x3E8;
        if ( (v9 & 0x80000000) == 0i64 )
        {
          if ( (int)v9 >= 60 )
          {
            if ( (int)v9 >= 3600 )
            {
              if ( (int)v9 >= 86400 )
              {
                v27 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_DAY_FORMAT", -1);
                m_translator = UFG::UIScreenManager::s_instance->m_translator;
                if ( !m_translator
                  || (v29 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v27)) == 0i64 )
                {
                  v29 = "SOCIAL_HUB_RECEIVED_TIME_DAY_FORMAT";
                }
                v30 = UFG::qString::FormatEx(&v162, v29, (unsigned int)((int)v9 / 86400));
                UFG::qString::Set(&v105, v30->mData, v30->mLength, 0i64, 0);
                p_result = &v162;
              }
              else
              {
                v23 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_HOUR_FORMAT", -1);
                v24 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v24 || (v25 = (const char *)v24->vfptr[5].__vecDelDtor(v24, v23)) == 0i64 )
                  v25 = "SOCIAL_HUB_RECEIVED_TIME_HOUR_FORMAT";
                v26 = UFG::qString::FormatEx(&v154, v25, (unsigned int)((int)v9 / 3600));
                UFG::qString::Set(&v105, v26->mData, v26->mLength, 0i64, 0);
                p_result = &v154;
              }
            }
            else
            {
              v19 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_MINUTE_FORMAT", -1);
              v20 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v20 || (v21 = (const char *)v20->vfptr[5].__vecDelDtor(v20, v19)) == 0i64 )
                v21 = "SOCIAL_HUB_RECEIVED_TIME_MINUTE_FORMAT";
              v22 = UFG::qString::FormatEx(&v152, v21, (unsigned int)((int)v9 / 60));
              UFG::qString::Set(&v105, v22->mData, v22->mLength, 0i64, 0);
              p_result = &v152;
            }
          }
          else
          {
            v15 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", -1);
            v16 = UFG::UIScreenManager::s_instance->m_translator;
            if ( !v16 || (v17 = (const char *)v16->vfptr[5].__vecDelDtor(v16, v15)) == 0i64 )
              v17 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
            v18 = UFG::qString::FormatEx(&v159, v17, (unsigned int)v9);
            UFG::qString::Set(&v105, v18->mData, v18->mLength, 0i64, 0);
            p_result = &v159;
          }
        }
        else
        {
          v10 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", -1);
          v11 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v11 || (v12 = (const char *)v11->vfptr[5].__vecDelDtor(v11, v10)) == 0i64 )
            v12 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
          v13 = UFG::qString::FormatEx(&result, v12, 0i64);
          UFG::qString::Set(&v105, v13->mData, v13->mLength, 0i64, 0);
          p_result = &result;
        }
        UFG::qString::~qString(p_result);
        v31 = &customCaption;
        v32 = &customCaption;
        UFG::qString::qString(&v106);
        UFG::qString::qString(&v107);
        v33 = UFG::OSuiteLeaderboardManager::Instance();
        LeaderboardDataUsingId = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(
                                   v33,
                                   *(_DWORD *)(p_mNext + 56));
        v35 = LeaderboardDataUsingId;
        if ( !LeaderboardDataUsingId
          || LeaderboardDataUsingId->mFlow.mUID != -1
          && (v36 = UFG::ProgressionTracker::Instance(),
              v35->mFlow.mUID != UFG::ProgressionTracker::GetActiveFlow(v36)->mUID) )
        {
          UFG::qString::~qString(&v107);
          UFG::qString::~qString(&v106);
          UFG::qString::~qString(&v105);
          goto LABEL_114;
        }
        v169 = -1;
        v37 = 0i64;
        v38 = v2->mSocialHubProperties.size;
        if ( v38 )
        {
          v39 = v2->mSocialHubProperties.p;
          while ( v39[v37].mLBD != v35 )
          {
            v37 = (unsigned int)(v37 + 1);
            if ( (unsigned int)v37 >= v38 )
              goto LABEL_36;
          }
          v4 = &v39[v37];
          v169 = v37;
        }
LABEL_36:
        v40 = v35->mCaption.mData;
        if ( v40 )
        {
          if ( *v40 == 36 )
            ++v40;
          v41 = UFG::qStringHashUpper32(v40, -1);
          v42 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v42 || (v43 = (const char *)v42->vfptr[5].__vecDelDtor(v42, v41)) == 0i64 )
            v43 = v40;
          UFG::qString::qString(&v109, v43);
        }
        else
        {
          UFG::qString::qString(&v109, 0i64);
        }
        UFG::qString::qString(&formatted);
        v2 = this;
        UFG::UIHKScreenSocialHub::FormatScore(this, &formatted, v35, *(_DWORD *)(p_mNext + 60));
        v44 = *(_DWORD *)(p_mNext + 44);
        if ( !v44 )
          break;
        if ( v44 == 1 )
        {
          v51 = &customCaption;
          v31 = (char *)gIconSocialHubAvatarPlayer_21;
          v52 = *(_DWORD *)(p_mNext + 60);
          switch ( v52 )
          {
            case 3:
              v32 = (char *)gIconSocialHubStatAward_G_21;
              v53 = UFG::qStringHashUpper32("SOCIAL_HUB_GOLD", -1);
              v54 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v54 || (v51 = (char *)v54->vfptr[5].__vecDelDtor(v54, v53)) == 0i64 )
                v51 = "SOCIAL_HUB_GOLD";
              break;
            case 2:
              v32 = (char *)gIconSocialHubStatAward_S_21;
              v55 = UFG::qStringHashUpper32("SOCIAL_HUB_SILVER", -1);
              v56 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v56 || (v51 = (char *)v56->vfptr[5].__vecDelDtor(v56, v55)) == 0i64 )
                v51 = "SOCIAL_HUB_SILVER";
              break;
            case 1:
              v32 = (char *)gIconSocialHubStatAward_B_21;
              v57 = UFG::qStringHashUpper32("SOCIAL_HUB_BRONZE", -1);
              v58 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v58 || (v51 = (char *)v58->vfptr[5].__vecDelDtor(v58, v57)) == 0i64 )
                v51 = "SOCIAL_HUB_BRONZE";
              break;
          }
          v59 = UFG::OnlineManager::Instance();
          UFG::OnlineManager::GetOnlineName(v59, &v150);
          v60 = "Wei Shen";
          if ( v150.mLength )
            v60 = v150.mData;
          UFG::qStringCopy(displayName, 512, v60, -1);
          UFG::qString::~qString(&v150);
          UFG::qString::Set(&v106, displayName);
          v61 = UFG::qStringHashUpper32("SOCIAL_HUB_AWARDED_MESSAGE_FORMAT", -1);
          v62 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v62 || (v63 = (const char *)v62->vfptr[5].__vecDelDtor(v62, v61)) == 0i64 )
            v63 = "SOCIAL_HUB_AWARDED_MESSAGE_FORMAT";
          v64 = UFG::qString::FormatEx(&v164, v63, v51, v109.mData);
          UFG::qString::Set(&v107, v64->mData, v64->mLength, 0i64, 0);
          UFG::qString::~qString(&v164);
          goto LABEL_96;
        }
        if ( v44 == 3 )
        {
          UFG::qStringCopy(dest, 256, *(char **)(p_mNext + 112), *(_DWORD *)(p_mNext + 108));
          UFG::qStringCopy((char *)&putf8str, 256, *(char **)(p_mNext + 176), *(_DWORD *)(p_mNext + 172));
          Scaleform::UTF8Util::DecodeString(pbuff, dest, -1i64);
          Scaleform::UTF8Util::DecodeString(v167, (const char *)&putf8str, -1i64);
          v65 = UFG::OnlineManager::Instance();
          UFG::OnlineManager::GetOnlineName(v65, &v151);
          v66 = "Wei Shen";
          if ( v151.mLength )
            v66 = v151.mData;
          UFG::qStringCopy(displayName, 512, v66, -1);
          UFG::qString::~qString(&v151);
          UFG::qString::Set(&v106, displayName);
          v67 = UFG::qStringHashUpper32("SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT", -1);
          v68 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v68 || (v69 = (const char *)v68->vfptr[5].__vecDelDtor(v68, v67)) == 0i64 )
            v69 = "SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT";
          v70 = UFG::qString::FormatEx(&v158, v69, dest, &putf8str, v109.mData, formatted.mData);
          UFG::qString::Set(&v107, v70->mData, v70->mLength, 0i64, 0);
          UFG::qString::~qString(&v158);
          v71 = UFG::OnlineId::ToString((UFG::OnlineId *)(p_mNext + 64), &v160);
          v72 = UFG::OnlineManager::Instance();
          OnlineId = UFG::OnlineManager::GetOnlineId(v72, &v102);
          v74 = UFG::OnlineId::ToString(OnlineId, &v161);
          LOBYTE(v71) = UFG::qString::operator==(v74, v71);
          UFG::qString::~qString(&v161);
          mPrev = v102.mPrev;
          mNext = v102.mNext;
          v102.mPrev->mNext = v102.mNext;
          mNext->mPrev = mPrev;
          v102.mPrev = &v102;
          v102.mNext = &v102;
          UFG::qString::~qString(&v160);
          v31 = (char *)gIconSocialHubAvatarFriend_21;
          if ( (_BYTE)v71 )
            v31 = (char *)gIconSocialHubAvatarPlayer_21;
          v32 = (char *)gIconSocialHubStatGame_21;
          goto LABEL_96;
        }
        if ( v44 != 4 )
          goto LABEL_96;
        UFG::qStringCopy((char *)&putf8str, 256, *(char **)(p_mNext + 112), *(_DWORD *)(p_mNext + 108));
        UFG::qStringCopy(dest, 256, *(char **)(p_mNext + 176), *(_DWORD *)(p_mNext + 172));
        Scaleform::UTF8Util::DecodeString(v167, (const char *)&putf8str, -1i64);
        Scaleform::UTF8Util::DecodeString(pbuff, dest, -1i64);
        PlayerDisplayName = UFG::UI::GetPlayerDisplayName();
        UFG::qString::Set(&v106, PlayerDisplayName);
        v78 = UFG::qStringHashUpper32("SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT", -1);
        v79 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v79 || (v80 = (const char *)v79->vfptr[5].__vecDelDtor(v79, v78)) == 0i64 )
          v80 = "SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT";
        v81 = UFG::qString::FormatEx(&v153, v80, &putf8str, dest, v109.mData, formatted.mData);
        UFG::qString::Set(&v107, v81->mData, v81->mLength, 0i64, 0);
        UFG::qString::~qString(&v153);
        v82 = UFG::OnlineId::ToString((UFG::OnlineId *)(p_mNext + 64), &v157);
        v83 = UFG::OnlineManager::Instance();
        v84 = UFG::OnlineManager::GetOnlineId(v83, &v103);
        v85 = UFG::OnlineId::ToString(v84, &v155);
        LOBYTE(v82) = (unsigned int)UFG::qStringCompare(v85->mData, v82->mData, -1) == 0;
        UFG::qString::~qString(&v155);
        v86 = v103.mPrev;
        v87 = v103.mNext;
        v103.mPrev->mNext = v103.mNext;
        v87->mPrev = v86;
        v103.mPrev = &v103;
        v103.mNext = &v103;
        UFG::qString::~qString(&v157);
        if ( (_BYTE)v82 )
        {
          v31 = (char *)gIconSocialHubAvatarPlayer_21;
LABEL_95:
          v32 = (char *)gIconSocialHubChallenge_21;
LABEL_96:
          `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v88.NValue = (double)*(int *)(p_mNext + 44);
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_Number;
          ptr.mValue = v88;
          if ( (v113 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v112 + 16i64))(
              v112,
              v111,
              COERCE_DOUBLE(*(_QWORD *)&v114));
            v112 = 0i64;
          }
          v113 = 5;
          v114 = (double)v169;
          v89 = (double)*(int *)(p_mNext + 60);
          if ( (v117 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v116 + 16i64))(
              v116,
              v115,
              COERCE_DOUBLE(*(_QWORD *)&v118));
            v116 = 0i64;
          }
          v117 = 5;
          v118 = v89;
          if ( (v121 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v120 + 16i64))(v120, v119, v122);
            v120 = 0i64;
          }
          v121 = 6;
          v122 = v31;
          v90 = v106.mData;
          if ( (v125 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v124 + 16i64))(v124, v123, v126);
            v124 = 0i64;
          }
          v125 = 6;
          v126 = v90;
          v91 = v105.mData;
          if ( (v129 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v128 + 16i64))(v128, v127, v130);
            v128 = 0i64;
          }
          v129 = 6;
          v130 = v91;
          if ( (v133 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v132 + 16i64))(v132, v131, v134);
            v132 = 0i64;
          }
          v133 = 6;
          v134 = v32;
          v92 = v107.mData;
          if ( (v137 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v136 + 16i64))(v136, v135, v138);
            v136 = 0i64;
          }
          v137 = 6;
          v138 = v92;
          Scaleform::GFx::Movie::Invoke(v170, "SocialLogList_AddItem", 0i64, &ptr, 8u);
          ++this->mLHSItemCount;
          `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          goto LABEL_94;
        }
        v31 = (char *)gIconSocialHubAvatarFriend_ChallengeIncoming_21;
        if ( !v4 || v4->mUIItemIndex >= 0 )
          goto LABEL_95;
LABEL_94:
        UFG::qString::~qString(&formatted);
        UFG::qString::~qString(&v109);
        UFG::qString::~qString(&v107);
        UFG::qString::~qString(&v106);
        UFG::qString::~qString(&v105);
        v4 = 0i64;
LABEL_114:
        p_mNext = *(_QWORD *)(p_mNext + 24) - 24i64;
        v5 = v104;
        if ( (UFG::SocialLogDataManager *)p_mNext == v171 )
          goto LABEL_115;
      }
      v45 = UFG::OnlineManager::Instance();
      UFG::OnlineManager::GetOnlineName(v45, &v149);
      v46 = "Wei Shen";
      if ( v149.mLength )
        v46 = v149.mData;
      UFG::qStringCopy(displayName, 512, v46, -1);
      UFG::qString::~qString(&v149);
      UFG::qString::Set(&v106, displayName);
      v47 = UFG::qStringHashUpper32("SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT", -1);
      v48 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v48 || (v49 = (const char *)v48->vfptr[5].__vecDelDtor(v48, v47)) == 0i64 )
        v49 = "SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT";
      v50 = UFG::qString::FormatEx(&v156, v49, v109.mData, formatted.mData);
      UFG::qString::Set(&v107, v50->mData, v50->mLength, 0i64, 0);
      UFG::qString::~qString(&v156);
      v31 = (char *)gIconSocialHubAvatarPlayer_Challengeable_21;
      if ( *(_DWORD *)(p_mNext + 192) )
        v31 = (char *)gIconSocialHubAvatarPlayer_ChallengeOutgoing_21;
      switch ( v35->mCategory )
      {
        case LeaderboardCategory_StatGame:
          v32 = (char *)gIconSocialHubStatGameGlow_21;
          break;
        case LeaderboardCategory_Mission:
          v32 = (char *)gIconSocialHubMission_21;
          break;
        case LeaderboardCategory_Race:
          v32 = (char *)gIconSocialHubRace_21;
          break;
      }
      goto LABEL_96;
    }
LABEL_115:
    Scaleform::GFx::Movie::Invoke(v170, "SocialLogList_Refresh", 0i64, 0i64, 0);
  }
}

// File Line: 1143
// RVA: 0x5FCA80
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *pObject; // rsi
  unsigned int NValue; // ebx
  __int64 v4; // rbx
  char *mData; // r14
  char *v6; // r14
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
  double mTriadPercent; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+18h] [rbp-69h] BYREF
  char v10[16]; // [rsp+48h] [rbp-39h] BYREF
  __int64 v11; // [rsp+58h] [rbp-29h]
  int v12; // [rsp+60h] [rbp-21h]
  double v13; // [rsp+68h] [rbp-19h]
  Scaleform::GFx::Value pval; // [rsp+78h] [rbp-9h] BYREF
  __int64 v15; // [rsp+A8h] [rbp+27h]

  v15 = -2i64;
  if ( this->mCurrentScreenType )
  {
    pObject = this->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
    NValue = (int)pval.mValue.NValue;
    UFG::UIHKScreenSocialHub::LoadTexturePack(this, (int)pval.mValue.NValue);
    ptr.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4 = NValue;
    mData = this->mSocialHubProperties.p[v4].mLBD->mCaption.mData;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = mData;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetSubHeader", 0i64, &ptr, 1u);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = "-";
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetScore", 0i64, &ptr, 1u);
    v6 = this->mSocialHubProperties.p[v4].mLBD->mDesc.mData;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = v6;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetDescription", 0i64, &ptr, 1u);
    v7.NValue = this->mSocialHubProperties.p[v4].mCopPercent;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue = v7;
    mTriadPercent = this->mSocialHubProperties.p[v4].mTriadPercent;
    if ( (v12 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
        v11,
        v10,
        COERCE_DOUBLE(*(_QWORD *)&v13));
      v11 = 0i64;
    }
    v12 = 5;
    v13 = mTriadPercent;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetMissionScore", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( (pval.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
  }
}

// File Line: 1176
// RVA: 0x5FC700
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsSocialAwardMedal(
        UFG::UIHKScreenSocialHub *this,
        UFG::OSuiteLeaderboardData *pLBD,
        int score)
{
  Scaleform::GFx::Movie *pObject; // r12
  UFG::StatGamePropertyManager *v6; // rax
  UFG::StatAwardPropertyData *PropertyData; // rdi
  char *v8; // rbx
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v11; // r15
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
  const char *v14; // r14
  unsigned int v15; // eax
  UFG::UIGfxTranslator *v16; // rcx
  const char *v17; // rsi
  char *mData; // rbx
  char *v19; // rbx
  char *v20; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v22[8]; // [rsp+60h] [rbp-88h] BYREF
  char *v23; // [rsp+68h] [rbp-80h]
  __int64 v24; // [rsp+70h] [rbp-78h]
  int v25[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v26; // [rsp+88h] [rbp-60h]
  int v27; // [rsp+90h] [rbp-58h]
  char *v28; // [rsp+98h] [rbp-50h]
  char v29[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v30; // [rsp+B8h] [rbp-30h]
  int v31; // [rsp+C0h] [rbp-28h]
  char *v32; // [rsp+C8h] [rbp-20h]
  __int64 v33; // [rsp+D8h] [rbp-10h]
  UFG::qString v34; // [rsp+E0h] [rbp-8h] BYREF
  UFG::qString v35; // [rsp+108h] [rbp+20h] BYREF
  UFG::qString v36; // [rsp+130h] [rbp+48h] BYREF
  UFG::qString scoreStr; // [rsp+158h] [rbp+70h] BYREF
  UFG::qString v38; // [rsp+180h] [rbp+98h] BYREF
  UFG::qString v39; // [rsp+1A8h] [rbp+C0h] BYREF

  v33 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v6 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
    PropertyData = (UFG::StatAwardPropertyData *)UFG::StatGamePropertyManager::GetPropertyData(v6, pLBD);
    if ( PropertyData )
    {
      if ( score < PropertyData->m_iGold )
      {
        if ( score < PropertyData->m_iSilver )
        {
          v8 = "BRONZE";
          if ( score < PropertyData->m_iBronze )
            v8 = &customCaption;
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
      v9 = UFG::qStringHashUpper32("HUD_SOCIAL_AWARDFORBRONZE", -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v11 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
        v11 = "HUD_SOCIAL_AWARDFORBRONZE";
      v12 = UFG::qStringHashUpper32("HUD_SOCIAL_AWARDFORSILVER", -1);
      v13 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v13 || (v14 = (const char *)v13->vfptr[5].__vecDelDtor(v13, v12)) == 0i64 )
        v14 = "HUD_SOCIAL_AWARDFORSILVER";
      v15 = UFG::qStringHashUpper32("HUD_SOCIAL_AWARDFORGOLD", -1);
      v16 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v16 || (v17 = (const char *)v16->vfptr[5].__vecDelDtor(v16, v15)) == 0i64 )
        v17 = "HUD_SOCIAL_AWARDFORGOLD";
      UFG::qString::qString(&scoreStr);
      UFG::qString::qString(&v35);
      UFG::qString::qString(&v38);
      UFG::StatAwardPropertyData::FormatScore(PropertyData, &scoreStr, (unsigned int)PropertyData->m_iBronze);
      UFG::StatAwardPropertyData::FormatScore(PropertyData, &v35, (unsigned int)PropertyData->m_iSilver);
      UFG::StatAwardPropertyData::FormatScore(PropertyData, &v38, (unsigned int)PropertyData->m_iGold);
      UFG::qString::qString(&v34);
      UFG::qString::qString(&v39);
      UFG::qString::qString(&v36);
      UFG::qString::Format(&v34, v11, scoreStr.mData);
      UFG::qString::Format(&v39, v14, v35.mData);
      UFG::qString::Format(&v36, v17, v38.mData);
      `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = v8;
      mData = v34.mData;
      if ( (v25[0] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v24 + 16i64))(v24, v22, v23);
        v24 = 0i64;
      }
      v25[0] = 6;
      v23 = mData;
      v19 = v39.mData;
      if ( (v27 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, char *))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
        v26 = 0i64;
      }
      v27 = 6;
      v28 = v19;
      v20 = v36.mData;
      if ( (v31 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v30 + 16i64))(v30, v29, v32);
        v30 = 0i64;
      }
      v31 = 6;
      v32 = v20;
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_SetAwardIconDesc", 0i64, &ptr, 4u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v36);
      UFG::qString::~qString(&v39);
      UFG::qString::~qString(&v34);
      UFG::qString::~qString(&v38);
      UFG::qString::~qString(&v35);
      UFG::qString::~qString(&scoreStr);
    }
  }
}

// File Line: 1221
// RVA: 0x5FC610
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsListHeader(UFG::UIHKScreenSocialHub *this, int leaderboardType)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *v3; // rbx
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  v3 = &customCaption;
  if ( leaderboardType )
  {
    if ( leaderboardType == 1 )
      v3 = "$HUD_SOCIAL_GLOBALBOARD";
  }
  else
  {
    v3 = "$HUD_SOCIAL_FRIENDBOARD";
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = v3;
  Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetSubHeader2", 0i64, &ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1240
// RVA: 0x5F54B0
void __fastcall UFG::UIHKScreenSocialHub::PopulateChallengeListAsync(UFG::UIHKScreenSocialHub *this, int screenType)
{
  Scaleform::GFx::Movie *pObject; // rbp
  unsigned int NValue; // ebx
  int v5; // esi
  void (__fastcall *v6)(OSuite::fastdelegate::detail::GenericClass *); // rax
  __int64 v7; // rdi
  UFG::UIHKScreenSocialHub::SocialHubProperty *p; // rbx
  UFG::OSuiteLeaderboardManager *v9; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value pval; // [rsp+48h] [rbp-50h] BYREF

  if ( !screenType )
  {
    this->mHandleMessageDisabled = 1;
    pObject = this->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
    NValue = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gScore");
    v5 = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubTableLoadingIcon_Show", 0i64, 0i64, 0);
    v6 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::UIHKScreenSocialHub::PopulateChallengeListCallback )
      v6 = 0i64;
    callback.m_Closure.m_pFunction = v6;
    callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::UIHKScreenSocialHub::PopulateChallengeListCallback;
    v7 = NValue;
    p = this->mSocialHubProperties.p;
    v9 = UFG::OSuiteLeaderboardManager::Instance();
    if ( !UFG::OSuiteLeaderboardManager::GetChallengeFriends(v9, (UFG::allocator::free_link *)p[v7].mLBD, v5, &callback) )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
      UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries);
      UFG::UIHKScreenSocialHub::gCallPopulateChallengeList = 1;
    }
    if ( (pval.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
  }
}

// File Line: 1278
// RVA: 0x5F5610
void __fastcall UFG::UIHKScreenSocialHub::PopulateChallengeListCallback(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  int v4; // edi
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *i; // rbx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *mPrev; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *mNext; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v8; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v9; // rax
  OSuite::ZOServiceOperationResult *v10; // rbx
  UFG::UIHKScreenSocialHub *Screen; // rax
  OSuite::ZListBase *m_pListBase; // rbx
  unsigned __int64 m_nIndex; // r14
  unsigned __int64 v14; // rsi
  const char *v15; // r14
  char Friend; // al
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v17; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v18; // rcx
  char *mData; // rsi
  UFG::allocator::free_link *v20; // rbx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v21; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v22; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v23; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v24; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v25; // rax
  UFG::OSuiteManager *v26; // rax
  UFG::OnlineId id; // [rsp+28h] [rbp-D8h] BYREF
  UFG::OnlineFriend frnd; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int> result; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v30; // [rsp+C0h] [rbp-40h]
  UFG::qString v31; // [rsp+C8h] [rbp-38h] BYREF
  UFG::qString text; // [rsp+F0h] [rbp-10h] BYREF

  v30 = -2i64;
  v4 = 0;
  for ( i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
        (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
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
  if ( pData->Status.eError == HTTPERROR_OK
    && UFG::OSuiteManager::Instance()->m_bConnected
    && (v10 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOServiceOperationResult>(
                pWebServiceClient,
                &pData->URL)) != 0i64 )
  {
    Screen = (UFG::UIHKScreenSocialHub *)UFG::UIScreenManagerBase::getScreen(
                                           UFG::UIScreenManager::s_instance,
                                           "SocialHub");
    if ( Screen )
    {
      UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(Screen);
      OSuite::ZOServiceOperationResult::Values(v10, &result);
      while ( !OSuite::ZListBase::ZListIteratorBase::AtEnd(&result.m_iterator) )
      {
        OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)result.m_iterator.m_pListBase);
        m_pListBase = result.m_iterator.m_pListBase;
        m_nIndex = result.m_iterator.m_nIndex;
        v14 = result.m_iterator.m_nIndex + 1;
        OSuite::TList<OSuite::ZServiceOperationValue *>::Grow(
          (OSuite::TList<OSuite::ZServiceOperationValue *> *)result.m_iterator.m_pListBase,
          result.m_iterator.m_nIndex + 1);
        if ( m_nIndex >= m_pListBase->m_nTop )
          m_pListBase->m_nTop = v14;
        v15 = OSuite::ZString::c_str((OSuite::ZString *)(*(_QWORD *)(m_pListBase[1].m_nSize + 8 * m_nIndex) + 160i64));
        frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
        frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(
                                                               HIDWORD(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits),
                                                               0) & 0xFF0FFFFF00000000ui64;
        HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
        *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
        UFG::qString::qString(&frnd.m_sOnlineName);
        id.mPrev = &id;
        id.mNext = &id;
        id.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(HIDWORD(id.m_SteamId.m_steamid.m_unAll64Bits), 0) & 0xFF0FFFFF00000000ui64;
        HIBYTE(id.m_SteamId.m_steamid.m_unAll64Bits) = 0;
        *((_DWORD *)&id.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
        id.m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(v15, 0i64);
        Friend = UFG::OnlineFriendManager::FindFriend((UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)&frnd, &id);
        v17 = id.mPrev;
        v18 = id.mNext;
        id.mPrev->mNext = id.mNext;
        v18->mPrev = v17;
        id.mPrev = &id;
        id.mNext = &id;
        if ( Friend )
        {
          mData = frnd.m_sOnlineName.mData;
          v20 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
          if ( v20 )
          {
            UFG::qString::qString(&v31, mData);
            UFG::qString::qString(&text, v15);
            v4 |= 3u;
            v20->mNext = v20;
            v20[1].mNext = v20;
            UFG::qString::qString((UFG::qString *)&v20[2], &text);
            UFG::qString::qString((UFG::qString *)&v20[7], &v31);
            LODWORD(v20[12].mNext) = 0;
          }
          else
          {
            v20 = 0i64;
          }
          v21 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev;
          UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev->mNext = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)v20;
          v20->mNext = (UFG::allocator::free_link *)v21;
          v20[1].mNext = (UFG::allocator::free_link *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
          UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)v20;
          if ( (v4 & 2) != 0 )
          {
            v4 &= ~2u;
            UFG::qString::~qString(&text);
          }
          if ( (v4 & 1) != 0 )
          {
            v4 &= ~1u;
            UFG::qString::~qString(&v31);
          }
        }
        frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
        UFG::qString::~qString(&frnd.m_sOnlineName);
        v22 = frnd.m_cOnlineId.mPrev;
        v23 = frnd.m_cOnlineId.mNext;
        frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
        v23->mPrev = v22;
        frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
        frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
        v24 = frnd.mPrev;
        v25 = frnd.mNext;
        frnd.mPrev->mNext = frnd.mNext;
        v25->mPrev = v24;
        frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
        OSuite::ZListBase::ZListIteratorBase::Next(&result.m_iterator);
      }
      result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TConstIterator<OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator,OSuite::ZServiceOperationValue *,int>::`vftable;
      result.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZServiceOperationValue *>::ZIterator::`vftable;
    }
  }
  else
  {
    v26 = UFG::OSuiteManager::Instance();
    UFG::OSuiteManager::Disconnect(v26);
    UFG::UIHKScreenSocialHub::gLastOSuiteErrorTime = (UFG::qGetSystemTimeUTC() - 116444736000000000i64) / 0x2710;
  }
}

// File Line: 1329
// RVA: 0x5F5200
void __fastcall UFG::UIHKScreenSocialHub::PopulateChallengeList(UFG::UIHKScreenSocialHub *this)
{
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *p_mChallengeDialogPopupEntries; // rbx
  int *p_mNext; // rax
  int *i; // rbp
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  int NValue; // r14d
  int score; // r15d
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *j; // rdi
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v13; // rcx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *mPrev; // rax
  char *mData; // rdi
  const char *v16; // r8
  unsigned int v17; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  UFG::qString v19; // [rsp+48h] [rbp-80h] BYREF
  Scaleform::GFx::Value pval; // [rsp+70h] [rbp-58h] BYREF

  p_mChallengeDialogPopupEntries = &this->mChallengeDialogPopupEntries;
  p_mNext = (int *)&this->mChallengeDialogPopupEntries.mNode.mNext[-1].mNext;
  for ( i = &this->mLastListTouchedByMouse;
        p_mNext != i;
        p_mNext = (int *)&p_mChallengeDialogPopupEntries->mNode.mNext[-1].mNext )
  {
    v5 = p_mNext + 2;
    v6 = *((_QWORD *)p_mNext + 1);
    v7 = (_QWORD *)*((_QWORD *)p_mNext + 2);
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    *v5 = v5;
    v5[1] = v5;
    if ( v5 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v5 - 1))(v5 - 1, 1i64);
  }
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(this->mRenderable->m_movie.pObject, &pval, "gLeaderboardId");
  NValue = (int)pval.mValue.NValue;
  Scaleform::GFx::Movie::GetVariable(this->mRenderable->m_movie.pObject, &pval, "gScore");
  score = (int)pval.mValue.NValue;
  for ( j = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
        j != (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        j = j->mNext )
  {
    v11 = UFG::qMalloc(0x78ui64, "UIHKScreenSocialHub", 0i64);
    if ( v11 )
      UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry::ChallengeDialogPopupEntry(
        (UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry *)v11,
        (UFG::qString *)&j[1],
        (UFG::qString *)&j[3].mNext,
        this->mSocialHubProperties.p[NValue].mLBD->mLeaderboardId,
        score);
    else
      v12 = 0i64;
    v13 = (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *)(v12 + 8);
    mPrev = p_mChallengeDialogPopupEntries->mNode.mPrev;
    mPrev->mNext = v13;
    v13->mPrev = mPrev;
    v13->mNext = &p_mChallengeDialogPopupEntries->mNode;
    p_mChallengeDialogPopupEntries->mNode.mPrev = v13;
  }
  if ( (int *)&p_mChallengeDialogPopupEntries->mNode.mNext[-1].mNext == i )
  {
    UFG::qString::qString(&v19, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customCaption,
      "$HUD_SOCIAL_NOFRIEND",
      v19.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v19);
  }
  else
  {
    mData = this->mSocialHubProperties.p[NValue].mLBD->mCaption.mData;
    if ( mData )
    {
      if ( *mData == 36 )
        ++mData;
      v17 = UFG::qStringHashUpper32(mData, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v16 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v17)) == 0i64 )
        v16 = mData;
    }
    else
    {
      v16 = 0i64;
    }
    UFG::UIHKScreenDialogPopup::createDialog(
      this,
      p_mChallengeDialogPopupEntries,
      v16,
      UI_HASH_CHALLENGE_BUTTON_ACCEPTED,
      UI_HASH_CHALLENGE_BUTTON_CANCELED);
    this->mDisplayingChallengeDialog = 1;
  }
  this->mHandleMessageDisabled = 0;
  if ( (pval.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
}

// File Line: 1373
// RVA: 0x5FBF10
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsListAsync(
        UFG::UIHKScreenSocialHub *this,
        int screenType,
        int leaderboardType)
{
  Scaleform::GFx::Movie *pObject; // rdi
  unsigned int NValue; // ebx
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  bool v7; // r13
  UFG::OnlineManager *v8; // rax
  bool m_bConnected; // r12
  UFG::OnlineManager *v10; // rax
  bool v11; // al
  bool v12; // r15
  int mCurrentLeaderboardType; // eax
  void (__fastcall *v14)(OSuite::fastdelegate::detail::GenericClass *); // rax
  __int64 v15; // rdi
  UFG::UIHKScreenSocialHub::SocialHubProperty *v16; // rbx
  UFG::OSuiteLeaderboardManager *v17; // rax
  void (__fastcall *v18)(OSuite::fastdelegate::detail::GenericClass *); // rax
  __int64 v19; // rdi
  UFG::UIHKScreenSocialHub::SocialHubProperty *p; // rbx
  UFG::OSuiteLeaderboardManager *v21; // rax
  __int64 v22; // r12
  UFG::OSuiteLeaderboardData *mLBD; // rbx
  UFG::GameStatTracker *v24; // rax
  unsigned int Stat; // ebx
  char *mData; // rbx
  int v27; // edx
  hkGeometryUtils::IVertices *v28; // rcx
  int v29; // r8d
  const char *v30; // rbx
  unsigned int v31; // eax
  Scaleform::GFx::Value ptr; // [rsp+8h] [rbp-79h] BYREF
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-49h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v34; // [rsp+68h] [rbp-19h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+78h] [rbp-9h] BYREF
  UFG::qString formatted; // [rsp+88h] [rbp+7h] BYREF
  __int64 v37; // [rsp+B0h] [rbp+2Fh]
  bool IsNetworkAvailable; // [rsp+F0h] [rbp+6Fh]

  v37 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  ptr.Type = VT_Undefined;
  if ( !screenType )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLoadingIcon_Hide", 0i64, 0i64, ptr.Type);
    return;
  }
  Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_ClearItem", 0i64, 0i64, ptr.Type);
  Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
  NValue = (int)pval.mValue.NValue;
  v7 = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, v6);
  v8 = UFG::OnlineManager::Instance();
  IsNetworkAvailable = UFG::OnlineManager::IsNetworkAvailable(v8);
  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v10 = UFG::OnlineManager::Instance();
  v11 = UFG::OnlineManager::IsNetworkAvailable(v10);
  v12 = v11;
  if ( !IsNetworkAvailable || !m_bConnected || v7 || !v11 )
  {
    *(_QWORD *)&ptr.Type = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v22 = NValue;
    mLBD = this->mSocialHubProperties.p[NValue].mLBD;
    v24 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v24, LeaderboardScoreIntList, &mLBD->mLeaderboardName);
    UFG::qString::qString(&formatted);
    if ( Stat )
      UFG::UIHKScreenSocialHub::FormatScore(this, &formatted, this->mSocialHubProperties.p[v22].mLBD, Stat);
    else
      UFG::qString::Set(&formatted, "-");
    mData = formatted.mData;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.mValue.pString = mData;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetScore", 0i64, &ptr, 1u);
    if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v28, v27, v29) )
    {
      v31 = (unsigned int)ptr.Type >> 6;
      if ( IsNetworkAvailable )
      {
        if ( v12 )
        {
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.mValue.pString = "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW";
          goto LABEL_34;
        }
        v30 = gNetworkDisconnectedMessage;
      }
      else
      {
        v30 = gFirstPartySignedOut;
      }
    }
    else
    {
      v30 = gSocialHubNoOnlineAccountMessage;
      v31 = (unsigned int)ptr.Type >> 6;
    }
    if ( (v31 & 1) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.mValue.pString = v30;
LABEL_34:
    ptr.Type = VT_String;
    if ( v7 )
    {
      ptr.Type = VT_String;
      ptr.mValue.pString = gSocialHubParentalControlsMessage;
    }
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_SetErrorMessage", 0i64, &ptr, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
    UFG::qString::~qString(&formatted);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_37;
  }
  this->mHandleMessageDisabled = 1;
  mCurrentLeaderboardType = this->mCurrentLeaderboardType;
  if ( mCurrentLeaderboardType )
  {
    if ( mCurrentLeaderboardType != 1 )
      goto LABEL_37;
    v18 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::UIHKScreenSocialHub::PopulateRhsListCallback )
      v18 = 0i64;
    v34.m_Closure.m_pFunction = v18;
    v34.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::UIHKScreenSocialHub::PopulateRhsListCallback;
    v19 = NValue;
    p = this->mSocialHubProperties.p;
    v21 = UFG::OSuiteLeaderboardManager::Instance();
    if ( UFG::OSuiteLeaderboardManager::GetResultGlobal(v21, (UFG::allocator::free_link *)p[v19].mLBD, &v34) )
      goto LABEL_37;
  }
  else
  {
    v14 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::UIHKScreenSocialHub::PopulateRhsListCallback )
      v14 = 0i64;
    callback.m_Closure.m_pFunction = v14;
    callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::UIHKScreenSocialHub::PopulateRhsListCallback;
    v15 = NValue;
    v16 = this->mSocialHubProperties.p;
    v17 = UFG::OSuiteLeaderboardManager::Instance();
    if ( UFG::OSuiteLeaderboardManager::GetResultFriends(v17, (UFG::allocator::free_link *)v16[v15].mLBD, &callback) )
      goto LABEL_37;
  }
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries);
  UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 1;
LABEL_37:
  if ( (pval.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
}

// File Line: 1472
// RVA: 0x5FC310
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsListCallback(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  int v4; // esi
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *i; // rbx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *mPrev; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *mNext; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v8; // rcx
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v9; // rax
  OSuite::ZOFeed *v10; // r13
  UFG::UIHKScreenSocialHub *Screen; // rax
  int v12; // r15d
  int j; // r14d
  OSuite::ZAtomEntry *Entry; // rbx
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
  OSuite::ZString v25; // [rsp+28h] [rbp-61h] BYREF
  OSuite::ZString outValue; // [rsp+40h] [rbp-49h] BYREF
  __int64 v27; // [rsp+58h] [rbp-31h]
  UFG::qString text; // [rsp+60h] [rbp-29h] BYREF
  UFG::qString v29; // [rsp+88h] [rbp-1h] BYREF
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v30; // [rsp+F0h] [rbp+67h] BYREF
  UFG::allocator::free_link *v31; // [rsp+100h] [rbp+77h]

  v27 = -2i64;
  v4 = 0;
  for ( i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
        (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries;
        i = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
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
  if ( pData->Status.eError == HTTPERROR_OK
    && UFG::OSuiteManager::Instance()->m_bConnected
    && (v10 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(pWebServiceClient, &pData->URL)) != 0i64 )
  {
    Screen = (UFG::UIHKScreenSocialHub *)UFG::UIScreenManagerBase::getScreen(
                                           UFG::UIScreenManager::s_instance,
                                           "SocialHub");
    if ( !Screen )
      return;
    UFG::UIHKScreenSocialHub::PopulateOnlineStatusIcon(Screen);
    v12 = OSuite::ZAtomFeed::TotalEntries(v10);
    for ( j = 0; j < v12; ++j )
    {
      Entry = OSuite::ZAtomFeed::GetEntry(v10, j);
      v15 = 0i64;
      if ( Entry->vfptr[1].__vecDelDtor(Entry, OSuite::ZOEntry::s_nClassId) )
        v15 = (OSuite::ZOEntry *)Entry;
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
          v22 = (int)v30;
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
        if ( (v4 & 2) != 0 )
        {
          v4 &= ~2u;
          UFG::qString::~qString(&text);
        }
        if ( (v4 & 1) != 0 )
        {
          v4 &= ~1u;
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
    UFG::UIHKScreenSocialHub::gLastOSuiteErrorTime = (UFG::qGetSystemTimeUTC() - 116444736000000000i64) / 0x2710;
  }
  UFG::UIHKScreenSocialHub::gCallPopulateRhsList = 1;
}

// File Line: 1636
// RVA: 0x61C760
void __fastcall UFG::UIHKScreenSocialHub::UpdateOnlineName(UFG::UIHKScreenSocialHub *this)
{
  hkgpIndexedMeshDefinitions::Edge *v1; // rdx
  Scaleform::GFx::Movie *MovieSafe; // rdi
  bool v3; // si
  UFG::OnlineManager *v4; // rax
  bool IsNetworkSignedIn; // bl
  bool v6; // bl
  const char *v7; // rbx
  UFG::OnlineManager *v8; // rax
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-69h] BYREF
  char v11[16]; // [rsp+58h] [rbp-39h] BYREF
  __int64 v12; // [rsp+68h] [rbp-29h]
  int v13; // [rsp+70h] [rbp-21h]
  const char *v14; // [rsp+78h] [rbp-19h]
  char v15[16]; // [rsp+88h] [rbp-9h] BYREF
  __int64 v16; // [rsp+98h] [rbp+7h]
  int v17; // [rsp+A0h] [rbp+Fh]
  char *v18; // [rsp+A8h] [rbp+17h]
  __int64 v19; // [rsp+B8h] [rbp+27h]
  UFG::qString result; // [rsp+C0h] [rbp+2Fh] BYREF

  v19 = -2i64;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( MovieSafe )
  {
    v3 = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, v1);
    v4 = UFG::OnlineManager::Instance();
    IsNetworkSignedIn = UFG::OnlineManager::IsNetworkSignedIn(v4);
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v6 = IsNetworkSignedIn && !v3;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Boolean;
    ptr.mValue.BValue = v6;
    v7 = gIconSocialHubAvatarPlayer_21;
    if ( (v13 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
      v12 = 0i64;
    }
    v13 = 6;
    v14 = v7;
    v8 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetOnlineName(v8, &result);
    mData = result.mData;
    if ( (v17 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
      v16 = 0i64;
    }
    v17 = 6;
    v18 = mData;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "SetIsOnline", 0i64, &ptr, 3u);
    UFG::qString::~qString(&result);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 1658
// RVA: 0x5FADF0
void __fastcall UFG::UIHKScreenSocialHub::PopulateRhsList(UFG::UIHKScreenSocialHub *this)
{
  int v2; // r15d
  Scaleform::GFx::Movie *pObject; // rdi
  unsigned int NValue; // r12d
  int v5; // ecx
  UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *mNext; // rax
  UFG::OSuiteLeaderboardData *mLBD; // rbx
  UFG::GameStatTracker *v8; // rax
  int Stat; // esi
  UFG::OnlineManager *v10; // r14
  UFG::allocator::free_link *v11; // rdi
  UFG::qString *OnlineName; // rbx
  UFG::OnlineId *OnlineId; // rax
  UFG::qString *v14; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v15; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v16; // rbx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v18; // rax
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v19; // rax
  UFG::OnlineManager *v20; // rax
  UFG::OSuiteLeaderboardData *v21; // rbx
  UFG::GameStatTracker *v22; // rax
  int v23; // r12d
  char v24; // r14
  UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *v25; // rsi
  const char *v26; // rcx
  bool v27; // dl
  __int64 *v28; // rcx
  __int64 **v29; // rax
  int v30; // eax
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rdi
  int v33; // ebx
  __int64 *v34; // rax
  UFG::allocator::free_link *v35; // rdi
  UFG::OnlineManager *v36; // rax
  UFG::qString *v37; // rbx
  UFG::OnlineManager *v38; // rax
  UFG::OnlineId *v39; // rax
  UFG::qString *v40; // rax
  __int64 *v41; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v42; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v43; // rax
  UFG::OSuiteLeaderboardData *v44; // rbx
  UFG::GameStatTracker *v45; // rax
  bool (__fastcall *v46)(UFG::UIHKScreenSocialHub::LeaderboardEntry *, UFG::UIHKScreenSocialHub::LeaderboardEntry *); // r14
  __int64 *v47; // rsi
  __int64 *v48; // rbx
  __int64 *v49; // rdi
  __int64 v50; // rdx
  __int64 **v51; // r8
  __int64 *v52; // rax
  __int64 v53; // rcx
  __int64 *v54; // rax
  __int64 **v55; // rax
  __int64 v56; // rax
  __int64 *v57; // rdi
  __int64 v58; // rdx
  __int64 **v59; // r8
  __int64 *v60; // rax
  __int64 v61; // rcx
  __int64 *v62; // rax
  __int64 **v63; // rax
  __int64 v64; // rax
  unsigned int v65; // esi
  __int64 **v66; // rdi
  int v67; // ebx
  char v68; // dl
  __int64 *v69; // rcx
  __int64 **v70; // rax
  __int64 v71; // rax
  int mCurrentScreenType; // eax
  bool v73; // dl
  __int64 *v74; // rcx
  __int64 **v75; // rax
  UFG::CachedLeaderboard::EntryType v76; // ebx
  const char *v77; // rcx
  char Friend; // al
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v79; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v80; // rcx
  int v81; // eax
  UFG::OSuiteLeaderboardData *v82; // rbx
  UFG::CachedLeaderboardManager *v83; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v84; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v85; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v86; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v87; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v88; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v89; // rax
  bool v90; // dl
  __int64 *v91; // rcx
  __int64 **v92; // rax
  UFG::OnlineManager *v93; // rax
  UFG::qString *v94; // rax
  char *mData; // rbx
  char *v96; // rbx
  const char *v97; // rbx
  __int64 *v98; // rcx
  __int64 **v99; // rax
  __int64 v100; // rbx
  char *v101; // rbx
  char *v102; // rbx
  char *i; // rbx
  __int64 v104; // rcx
  _QWORD *v105; // rax
  __int64 v106; // rdx
  _QWORD *v107; // rax
  __int64 *v108; // rcx
  _QWORD *v109; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v110; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v111; // rax
  __int64 *v112; // [rsp+38h] [rbp-C8h] BYREF
  void *mem; // [rsp+40h] [rbp-C0h]
  UFG::OnlineId id; // [rsp+48h] [rbp-B8h] BYREF
  __int64 *v115; // [rsp+60h] [rbp-A0h] BYREF
  __int64 **v116; // [rsp+68h] [rbp-98h]
  unsigned __int64 v117; // [rsp+70h] [rbp-90h]
  __int64 *v118; // [rsp+78h] [rbp-88h] BYREF
  __int64 **v119; // [rsp+80h] [rbp-80h]
  unsigned __int64 v120; // [rsp+88h] [rbp-78h]
  __int64 *v121; // [rsp+90h] [rbp-70h] BYREF
  __int64 **v122; // [rsp+98h] [rbp-68h]
  unsigned __int64 v123; // [rsp+A0h] [rbp-60h]
  __int64 *v124; // [rsp+A8h] [rbp-58h] BYREF
  __int64 **v125; // [rsp+B0h] [rbp-50h]
  unsigned __int64 v126; // [rsp+B8h] [rbp-48h]
  __int64 *v127; // [rsp+C0h] [rbp-40h] BYREF
  __int64 **v128; // [rsp+C8h] [rbp-38h]
  unsigned __int64 v129; // [rsp+D0h] [rbp-30h]
  UFG::OnlineId v130; // [rsp+D8h] [rbp-28h] BYREF
  UFG::OnlineFriend frnd; // [rsp+F0h] [rbp-10h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+150h] [rbp+50h] BYREF
  UFG::OnlineId v133; // [rsp+180h] [rbp+80h] BYREF
  UFG::OnlineId v134; // [rsp+198h] [rbp+98h] BYREF
  UFG::OnlineId *p_m_cOnlineId; // [rsp+1B0h] [rbp+B0h]
  unsigned __int64 v136; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::Value pval; // [rsp+1C0h] [rbp+C0h] BYREF
  Scaleform::GFx::Value v138; // [rsp+1F0h] [rbp+F0h] BYREF
  UFG::qString v139; // [rsp+220h] [rbp+120h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+250h] [rbp+150h] BYREF
  char v141[16]; // [rsp+280h] [rbp+180h] BYREF
  __int64 v142; // [rsp+290h] [rbp+190h]
  int v143; // [rsp+298h] [rbp+198h]
  char *v144; // [rsp+2A0h] [rbp+1A0h]
  char v145[8]; // [rsp+2B0h] [rbp+1B0h] BYREF
  __int64 v146; // [rsp+2C0h] [rbp+1C0h]
  int v147; // [rsp+2C8h] [rbp+1C8h]
  const char *v148; // [rsp+2D0h] [rbp+1D0h]
  char v149[16]; // [rsp+2E0h] [rbp+1E0h] BYREF
  __int64 v150; // [rsp+2F0h] [rbp+1F0h]
  int v151; // [rsp+2F8h] [rbp+1F8h]
  __int64 v152; // [rsp+300h] [rbp+200h]
  char v153[16]; // [rsp+310h] [rbp+210h] BYREF
  __int64 v154; // [rsp+320h] [rbp+220h]
  int v155; // [rsp+328h] [rbp+228h]
  char *v156; // [rsp+330h] [rbp+230h]
  UFG::CachedLeaderboard::Entry entry; // [rsp+340h] [rbp+240h] BYREF
  UFG::qString formatted; // [rsp+3A0h] [rbp+2A0h] BYREF
  unsigned __int64 v159; // [rsp+3C8h] [rbp+2C8h]
  unsigned __int64 v160; // [rsp+3D0h] [rbp+2D0h]
  UFG::OnlineId *v161; // [rsp+3D8h] [rbp+2D8h]
  unsigned __int64 v162; // [rsp+3E0h] [rbp+2E0h]
  __int64 v163; // [rsp+3E8h] [rbp+2E8h]
  UFG::qString v164; // [rsp+3F0h] [rbp+2F0h] BYREF
  UFG::qString v165; // [rsp+418h] [rbp+318h] BYREF
  UFG::qString v166; // [rsp+440h] [rbp+340h] BYREF
  UFG::qString v167; // [rsp+468h] [rbp+368h] BYREF
  UFG::qString v168; // [rsp+490h] [rbp+390h] BYREF
  UFG::qString v169; // [rsp+4B8h] [rbp+3B8h] BYREF
  UFG::qString v170; // [rsp+4E0h] [rbp+3E0h] BYREF
  UFG::qString result; // [rsp+508h] [rbp+408h] BYREF
  int v172; // [rsp+580h] [rbp+480h]
  __int64 v173; // [rsp+588h] [rbp+488h]
  Scaleform::GFx::Movie *v174; // [rsp+590h] [rbp+490h]

  v163 = -2i64;
  v2 = 0;
  pObject = this->mRenderable->m_movie.pObject;
  v174 = pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
  NValue = (int)pval.mValue.NValue;
  v5 = 0;
  mNext = (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
  if ( (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext == &UFG::UIHKScreenSocialHub::gLeaderboardEntries )
    goto LABEL_4;
  do
  {
    ++v5;
    mNext = (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)mNext->mNode.mNext;
  }
  while ( mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries );
  if ( !v5 )
  {
LABEL_4:
    mLBD = this->mSocialHubProperties.p[NValue].mLBD;
    v8 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v8, LeaderboardScoreIntList, &mLBD->mLeaderboardName);
    if ( !Stat )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = "-";
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetScore", 0i64, &ptr, 1u);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = "$HUD_SOCIAL_NOENTRY";
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_SetErrorMessage", 0i64, &ptr, 1u);
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
      this->mHandleMessageDisabled = 0;
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
      `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      goto LABEL_111;
    }
    v10 = UFG::OnlineManager::Instance();
    v11 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
    if ( v11 )
    {
      OnlineName = UFG::OnlineManager::GetOnlineName(v10, &result);
      OnlineId = UFG::OnlineManager::GetOnlineId(v10, &v133);
      v14 = UFG::OnlineId::ToString(OnlineId, &v166);
      v2 = 7;
      UFG::UIHKScreenSocialHub::LeaderboardEntry::LeaderboardEntry(
        (UFG::UIHKScreenSocialHub::LeaderboardEntry *)v11,
        v14,
        OnlineName,
        Stat);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    if ( (v2 & 4) != 0 )
    {
      v2 &= ~4u;
      UFG::qString::~qString(&v166);
    }
    if ( (v2 & 2) != 0 )
    {
      v2 &= ~2u;
      mPrev = v133.mPrev;
      v18 = v133.mNext;
      v133.mPrev->mNext = v133.mNext;
      v18->mPrev = mPrev;
      v133.mPrev = &v133;
      v133.mNext = &v133;
    }
    if ( (v2 & 1) != 0 )
    {
      v2 &= ~1u;
      UFG::qString::~qString(&result);
    }
    v19 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev;
    UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev->mNext = v16;
    v16->mPrev = v19;
    v16->mNext = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
    UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mPrev = v16;
  }
  v20 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::GetOnlineId(v20, &v130);
  v112 = (__int64 *)&v112;
  mem = &v112;
  v173 = NValue;
  v21 = this->mSocialHubProperties.p[NValue].mLBD;
  v22 = UFG::GameStatTracker::Instance();
  v23 = UFG::GameStatTracker::GetStat(v22, LeaderboardScoreIntList, &v21->mLeaderboardName);
  v172 = v23;
  v24 = 0;
  v25 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext;
  if ( (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries )
  {
    do
    {
      v26 = (const char *)v25[2].mNext;
      v124 = (__int64 *)&v124;
      v125 = &v124;
      v126 &= 0xFF0FFFFF00000000ui64;
      HIBYTE(v126) = 0;
      HIDWORD(v126) &= 0xFFF00000;
      v126 = UFG::qToUInt64(v26, 0i64);
      v27 = v126 == v130.m_SteamId.m_steamid.m_unAll64Bits;
      v28 = v124;
      v29 = v125;
      v124[1] = (__int64)v125;
      *v29 = v28;
      v124 = (__int64 *)&v124;
      v125 = &v124;
      if ( v27 )
      {
        if ( this->mCurrentScreenType == 4 )
        {
          if ( v23 > 0 )
          {
            v30 = (int)v25[6].mPrev;
            if ( v30 > 0 && v23 > v30 )
            {
              v24 = 1;
              v23 = (int)v25[6].mPrev;
            }
          }
        }
        else if ( v23 < SLODWORD(v25[6].mPrev) )
        {
          v24 = 1;
          v23 = (int)v25[6].mPrev;
        }
      }
      else
      {
        v31 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
        v32 = (__int64)v31;
        if ( v31 )
        {
          v33 = (int)v25[6].mPrev;
          v31->mNext = v31;
          v31[1].mNext = v31;
          UFG::qString::qString((UFG::qString *)&v31[2], (UFG::qString *)&v25[1]);
          UFG::qString::qString((UFG::qString *)(v32 + 56), (UFG::qString *)&v25[3].mNext);
          *(_DWORD *)(v32 + 96) = v33;
        }
        else
        {
          v32 = 0i64;
        }
        v34 = v112;
        v112[1] = v32;
        *(_QWORD *)v32 = v34;
        *(_QWORD *)(v32 + 8) = &v112;
        v112 = (__int64 *)v32;
      }
      v25 = v25->mNext;
    }
    while ( v25 != (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries );
    v172 = v23;
  }
  if ( v23 )
  {
    v35 = UFG::qMalloc(0x68ui64, "UIHKScreenSocialHub", 0i64);
    v136 = (unsigned __int64)v35;
    if ( v35 )
    {
      v36 = UFG::OnlineManager::Instance();
      v37 = UFG::OnlineManager::GetOnlineName(v36, &v170);
      v38 = UFG::OnlineManager::Instance();
      v39 = UFG::OnlineManager::GetOnlineId(v38, &v134);
      v40 = UFG::OnlineId::ToString(v39, &v168);
      v2 |= 0x38u;
      v35->mNext = v35;
      v35[1].mNext = v35;
      UFG::qString::qString((UFG::qString *)&v35[2], v40);
      UFG::qString::qString((UFG::qString *)&v35[7], v37);
      LODWORD(v35[12].mNext) = v23;
    }
    else
    {
      v35 = 0i64;
    }
    v41 = v112;
    v112[1] = (__int64)v35;
    v35->mNext = (UFG::allocator::free_link *)v41;
    v35[1].mNext = (UFG::allocator::free_link *)&v112;
    v112 = (__int64 *)v35;
    if ( (v2 & 0x20) != 0 )
    {
      v2 &= ~0x20u;
      UFG::qString::~qString(&v168);
    }
    if ( (v2 & 0x10) != 0 )
    {
      v2 &= ~0x10u;
      v42 = v134.mPrev;
      v43 = v134.mNext;
      v134.mPrev->mNext = v134.mNext;
      v43->mPrev = v42;
      v134.mPrev = &v134;
      v134.mNext = &v134;
    }
    if ( (v2 & 8) != 0 )
    {
      v2 &= ~8u;
      UFG::qString::~qString(&v170);
    }
    if ( v24 )
    {
      v44 = this->mSocialHubProperties.p[v173].mLBD;
      v45 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v45, LeaderboardScoreIntList, &v44->mLeaderboardName, v23);
    }
  }
  v46 = UFG::UIHKScreenSocialHub::CompareDESC;
  if ( this->mCurrentScreenType == 4 )
    v46 = UFG::UIHKScreenSocialHub::CompareASC;
  v47 = (__int64 *)mem;
  do
  {
    v48 = 0i64;
    while ( v47 != (__int64 *)&v112 )
    {
      v49 = (__int64 *)v47[1];
      if ( v49 == (__int64 *)&v112 )
        break;
      if ( v46((UFG::UIHKScreenSocialHub::LeaderboardEntry *)v47, (UFG::UIHKScreenSocialHub::LeaderboardEntry *)v47[1]) )
      {
        v47 = v49;
      }
      else
      {
        v50 = *v47;
        v51 = (__int64 **)v49[1];
        v52 = (__int64 *)v47[1];
        *(_QWORD *)(v50 + 8) = v52;
        *v52 = v50;
        *v47 = (__int64)v47;
        v47[1] = (__int64)v47;
        v53 = *v49;
        v54 = (__int64 *)v49[1];
        *(_QWORD *)(v53 + 8) = v54;
        *v54 = v53;
        *v49 = (__int64)v49;
        v49[1] = (__int64)v49;
        v55 = *(__int64 ***)(v50 + 8);
        *(_QWORD *)(v50 + 8) = v49;
        *v49 = v50;
        v49[1] = (__int64)v55;
        *v55 = v49;
        v56 = (__int64)*v51;
        *(_QWORD *)(v56 + 8) = v47;
        *v47 = v56;
        v47[1] = (__int64)v51;
        *v51 = v47;
        v48 = v49;
      }
    }
    v47 = 0i64;
    if ( !v48 || v48 == (__int64 *)&v112 )
      break;
    do
    {
      v57 = (__int64 *)*v48;
      if ( (__int64 **)*v48 == &v112 )
        break;
      if ( v46((UFG::UIHKScreenSocialHub::LeaderboardEntry *)*v48, (UFG::UIHKScreenSocialHub::LeaderboardEntry *)v48) )
      {
        v48 = v57;
      }
      else
      {
        v58 = *v57;
        v59 = (__int64 **)v48[1];
        v60 = (__int64 *)v57[1];
        *(_QWORD *)(v58 + 8) = v60;
        *v60 = v58;
        *v57 = (__int64)v57;
        v57[1] = (__int64)v57;
        v61 = *v48;
        v62 = (__int64 *)v48[1];
        *(_QWORD *)(v61 + 8) = v62;
        *v62 = v61;
        *v48 = (__int64)v48;
        v48[1] = (__int64)v48;
        v63 = *(__int64 ***)(v58 + 8);
        *(_QWORD *)(v58 + 8) = v48;
        *v48 = v58;
        v48[1] = (__int64)v63;
        *v63 = v48;
        v64 = (__int64)*v59;
        *(_QWORD *)(v64 + 8) = v57;
        *v57 = v64;
        v57[1] = (__int64)v59;
        *v59 = v57;
        v47 = v57;
      }
    }
    while ( v48 != (__int64 *)&v112 );
  }
  while ( v47 );
  v65 = 1;
  v66 = (__int64 **)mem;
  if ( mem != &v112 )
  {
    while ( 1 )
    {
      if ( v65 == 11 )
      {
LABEL_101:
        v23 = v172;
        break;
      }
      UFG::qString::qString(&v139, (UFG::qString *)(v66 + 2));
      UFG::qString::FormatEx(&v165, "%d", v65);
      if ( v65 == 10 )
      {
        v127 = (__int64 *)&v127;
        v128 = &v127;
        v67 = 0;
        v129 &= 0xFF0FFFFF00000000ui64;
        HIBYTE(v129) = 0;
        HIDWORD(v129) &= 0xFFF00000;
        v136 = UFG::qToUInt64(v139.mData, 0i64);
        v129 = v136;
        v2 |= 0x40u;
        if ( v136 == v130.m_SteamId.m_steamid.m_unAll64Bits )
        {
          v68 = 1;
          goto LABEL_71;
        }
      }
      else
      {
        v67 = 0;
      }
      v68 = 0;
LABEL_71:
      if ( (v2 & 0x40) != 0 )
      {
        v2 &= ~0x40u;
        v69 = v127;
        v70 = v128;
        v127[1] = (__int64)v128;
        *v70 = v69;
        v127 = (__int64 *)&v127;
        v128 = &v127;
      }
      if ( v68 )
      {
        UFG::qString::qString(&v167, "--");
        UFG::qString::Set(&v165, *(const char **)(v71 + 24), *(_DWORD *)(v71 + 20), 0i64, 0);
        UFG::qString::~qString(&v167);
      }
      UFG::qString::qString(&formatted);
      mCurrentScreenType = this->mCurrentScreenType;
      if ( mCurrentScreenType != 1 )
      {
        if ( mCurrentScreenType == 2 )
        {
          v121 = (__int64 *)&v121;
          v122 = &v121;
          v123 = __PAIR64__(HIDWORD(v123), 0) & 0xFF0FFFFF00000000ui64;
          HIBYTE(v123) = 0;
          HIDWORD(v123) &= 0xFFF00000;
          v160 = UFG::qToUInt64(v139.mData, 0i64);
          v123 = v160;
          v73 = v160 == v130.m_SteamId.m_steamid.m_unAll64Bits;
          v74 = v121;
          v75 = v122;
          v121[1] = (__int64)v122;
          *v75 = v74;
          v121 = (__int64 *)&v121;
          v122 = &v121;
          LOBYTE(v67) = v73;
          v76 = v67 + 1;
          if ( !this->mCurrentLeaderboardType )
          {
            frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
            frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
            frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
            p_m_cOnlineId = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits &= 0xFF0FFFFF00000000ui64;
            HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            UFG::qString::qString(&frnd.m_sOnlineName);
            v77 = (const char *)v66[5];
            id.mPrev = &id;
            id.mNext = &id;
            id.m_SteamId.m_steamid.m_unAll64Bits &= 0xFF0FFFFF00000000ui64;
            HIBYTE(id.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&id.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            p_m_cOnlineId = (UFG::OnlineId *)UFG::qToUInt64(v77, 0i64);
            id.m_SteamId.m_steamid.m_unAll64Bits = (unsigned __int64)p_m_cOnlineId;
            Friend = UFG::OnlineFriendManager::FindFriend(
                       (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)&frnd,
                       &id);
            v79 = id.mPrev;
            v80 = id.mNext;
            id.mPrev->mNext = id.mNext;
            v80->mPrev = v79;
            id.mPrev = &id;
            id.mNext = &id;
            if ( Friend )
            {
              v81 = *((_DWORD *)v66 + 24);
              entry.mPrev = &entry;
              entry.mNext = &entry;
              entry.m_iRating = v81;
              entry.m_uRank = 0;
              entry.m_eEntryType = v76;
              UFG::qStringCopy(entry.m_sUsername, 64, frnd.m_sOnlineName.mData, -1);
              v82 = this->mSocialHubProperties.p[v173].mLBD;
              v83 = UFG::CachedLeaderboardManager::Instance();
              UFG::CachedLeaderboardManager::UpsertEntry(v83, v82->mLeaderboardId, &entry);
              v84 = entry.mPrev;
              v85 = entry.mNext;
              entry.mPrev->mNext = entry.mNext;
              v85->mPrev = v84;
              entry.mPrev = &entry;
              entry.mNext = &entry;
            }
            frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
            UFG::qString::~qString(&frnd.m_sOnlineName);
            v161 = &frnd.m_cOnlineId;
            v86 = frnd.m_cOnlineId.mPrev;
            v87 = frnd.m_cOnlineId.mNext;
            frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
            v87->mPrev = v86;
            frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
            frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
            v88 = frnd.mPrev;
            v89 = frnd.mNext;
            frnd.mPrev->mNext = frnd.mNext;
            v89->mPrev = v88;
            frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
            frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
          }
        }
        else if ( (unsigned int)(mCurrentScreenType - 3) > 1 )
        {
          goto LABEL_84;
        }
      }
      UFG::UIHKScreenSocialHub::FormatScore(
        this,
        &formatted,
        this->mSocialHubProperties.p[v173].mLBD,
        *((_DWORD *)v66 + 24));
LABEL_84:
      if ( *((_DWORD *)v66 + 19) )
      {
        v115 = (__int64 *)&v115;
        v116 = &v115;
        v117 &= 0xFF0FFFFF00000000ui64;
        HIBYTE(v117) = 0;
        HIDWORD(v117) &= 0xFFF00000;
        v162 = UFG::qToUInt64(v139.mData, 0i64);
        v117 = v162;
        v90 = v162 == v130.m_SteamId.m_steamid.m_unAll64Bits;
        v91 = v115;
        v92 = v116;
        v115[1] = (__int64)v116;
        *v92 = v91;
        v115 = (__int64 *)&v115;
        v116 = &v115;
        if ( v90 )
        {
          v93 = UFG::OnlineManager::Instance();
          v94 = UFG::OnlineManager::GetOnlineName(v93, &v169);
          UFG::qString::Set((UFG::qString *)(v66 + 7), v94->mData, v94->mLength, 0i64, 0);
          UFG::qString::~qString(&v169);
        }
        `eh vector constructor iterator(&pargs, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        mData = v139.mData;
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_String;
        pargs.mValue.pString = mData;
        v96 = v165.mData;
        if ( (v143 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v142 + 16i64))(v142, v141, v144);
          v142 = 0i64;
        }
        v143 = 6;
        v144 = v96;
        v118 = (__int64 *)&v118;
        v119 = &v118;
        v120 &= 0xFF0FFFFF00000000ui64;
        HIBYTE(v120) = 0;
        HIDWORD(v120) &= 0xFFF00000;
        v159 = UFG::qToUInt64(v139.mData, 0i64);
        v120 = v159;
        v97 = gIconSocialHubAvatarFriend_21;
        if ( v159 == v130.m_SteamId.m_steamid.m_unAll64Bits )
          v97 = gIconSocialHubAvatarPlayer_21;
        if ( (v147 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v146 + 16i64))(v146, v145, v148);
          v146 = 0i64;
        }
        v147 = 6;
        v148 = v97;
        v98 = v118;
        v99 = v119;
        v118[1] = (__int64)v119;
        *v99 = v98;
        v118 = (__int64 *)&v118;
        v119 = &v118;
        v100 = (__int64)v66[10];
        if ( (v151 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v150 + 16i64))(v150, v149, v152);
          v150 = 0i64;
        }
        v151 = 6;
        v152 = v100;
        v101 = formatted.mData;
        if ( (v155 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v154 + 16i64))(v154, v153, v156);
          v154 = 0i64;
        }
        v155 = 6;
        v156 = v101;
        Scaleform::GFx::Movie::Invoke(v174, "SocialHubRhsList_AddItem", 0i64, &pargs, 5u);
        ++v65;
        `eh vector destructor iterator(&pargs, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
      UFG::qString::~qString(&formatted);
      UFG::qString::~qString(&v165);
      UFG::qString::~qString(&v139);
      v66 = (__int64 **)v66[1];
      if ( v66 == &v112 )
        goto LABEL_101;
    }
  }
  `eh vector constructor iterator(&v138, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  UFG::qString::qString(&v164);
  UFG::UIHKScreenSocialHub::FormatScore(this, &v164, this->mSocialHubProperties.p[v173].mLBD, v23);
  v102 = "-";
  if ( v23 )
    v102 = v164.mData;
  if ( (v138.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v138.pObjectInterface->vfptr->gap8[8])(
      v138.pObjectInterface,
      &v138,
      v138.mValue);
    v138.pObjectInterface = 0i64;
  }
  v138.Type = VT_String;
  v138.mValue.pString = v102;
  Scaleform::GFx::Movie::Invoke(v174, "SocialHubRhsView_SetScore", 0i64, &v138, 1u);
  if ( this->mCurrentScreenType == 1 )
    UFG::UIHKScreenSocialHub::PopulateRhsSocialAwardMedal(this, this->mSocialHubProperties.p[v173].mLBD, v23);
  Scaleform::GFx::Movie::Invoke(v174, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
  this->mHandleMessageDisabled = 0;
  Scaleform::GFx::Movie::Invoke(v174, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(this, this->mCurrentScreenType, 1);
  UFG::qString::~qString(&v164);
  `eh vector destructor iterator(&v138, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  for ( i = (char *)mem; mem != &v112; i = (char *)mem )
  {
    v104 = *(_QWORD *)i;
    v105 = (_QWORD *)*((_QWORD *)i + 1);
    *(_QWORD *)(v104 + 8) = v105;
    *v105 = v104;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    UFG::qString::~qString((UFG::qString *)(i + 56));
    UFG::qString::~qString((UFG::qString *)(i + 16));
    v106 = *(_QWORD *)i;
    v107 = (_QWORD *)*((_QWORD *)i + 1);
    *(_QWORD *)(v106 + 8) = v107;
    *v107 = v106;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    operator delete[](i);
  }
  v108 = v112;
  v109 = mem;
  v112[1] = (__int64)mem;
  *v109 = v108;
  v112 = (__int64 *)&v112;
  mem = &v112;
  v110 = v130.mPrev;
  v111 = v130.mNext;
  v130.mPrev->mNext = v130.mNext;
  v111->mPrev = v110;
  v130.mPrev = &v130;
  v130.mNext = &v130;
LABEL_111:
  if ( (pval.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
}ring::~qString((UFG::qString *)(i + 16));
    v106 = *(_QWORD *)i;
    v107 = (_QWORD *)*((_QWORD *)i + 1);
    *(_QWORD *)(v106 + 8) = v107;
    *v107 = v106;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    operator delete[](i);
  }
  v108 = v112;
  v109 = mem;
  v112[1] = (__int64)mem;
  *v109 = v108;
  v112 = (__int64 *)&v112;
  mem = &v112;
  v110 = v130.mPrev;
  v111 = v130.mNext;
  v130.mPrev->mNe

// File Line: 1858
// RVA: 0x602730
void __fastcall UFG::UIHKScreenSocialHub::RequestRhsListPopulation(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  __int64 NValue; // rcx
  __int64 v4; // rdi
  UFG::OSuiteLeaderboardData *mLBD; // rbx
  UFG::GameStatTracker *v6; // rax
  int Stat; // eax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-40h] BYREF

  UFG::UIHKScreenSocialHub::PopulateRhsListHeader(this, this->mCurrentLeaderboardType);
  if ( this->mLHSItemCount )
  {
    this->mPopulateRhsListAsyncRequested = 1;
    this->mTimeElapsedAfterMoving = 0.0;
    pObject = this->mRenderable->m_movie.pObject;
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_ClearErrorMessage", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_ClearItem", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsList_Refresh", 0i64, 0i64, 0);
    if ( this->mCurrentScreenType )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLoadingIcon_Show", 0i64, 0i64, 0);
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubTableLoadingIcon_Hide", 0i64, 0i64, 0);
    }
    else
    {
      Scaleform::GFx::Movie::Invoke(pObject, "SocialHubLoadingIcon_Hide", 0i64, 0i64, 0);
    }
    if ( this->mCurrentScreenType == 1 )
    {
      pval.pObjectInterface = 0i64;
      pval.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
      NValue = (unsigned int)(int)pval.mValue.NValue;
      v4 = NValue;
      mLBD = this->mSocialHubProperties.p[NValue].mLBD;
      v6 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v6, LeaderboardScoreIntList, &mLBD->mLeaderboardName);
      UFG::UIHKScreenSocialHub::PopulateRhsSocialAwardMedal(this, this->mSocialHubProperties.p[v4].mLBD, Stat);
      if ( (pval.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          pval.mValue);
    }
  }
}

// File Line: 1898
// RVA: 0x604650
void __fastcall UFG::UIHKScreenSocialHub::SendMessageCallbackA(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient,
        UFG::OSuiteMessage *msg)
{
  UFG::GameStatTracker *v4; // rax
  UFG::OSuiteDBLogger *v5; // rdi
  UFG::OSuiteLeaderboardManager *v6; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingId; // rax
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  if ( !pData || pData->Status.eError )
  {
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = PopupRequestStatus_SendMessageFailed;
    if ( msg )
      msg->vfptr->__vecDelDtor(msg, 1i64);
  }
  else
  {
    v4 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v4, SocialChallengeSent, 1);
    UFG::UIHKScreenSocialHub::gPopupRequestStatus = PopupRequestStatus_SendMessageSucceeded;
    UFG::UIHKScreenSocialHub::gOSuiteMessage = msg;
    if ( msg && HIDWORD(msg[1].mNext) == 4 )
    {
      v5 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v5, "SocialInteraction") )
      {
        UFG::qSPrintf(dest, 128, "s_%s", "Event");
        OSuite::ZMetric::SetProperty(v5->m_pMetric, dest, "Challenge Sent");
        v6 = UFG::OSuiteLeaderboardManager::Instance();
        LeaderboardDataUsingId = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(
                                   v6,
                                   (unsigned int)msg[2].mPrev);
        UFG::OSuiteDBLogger::AddValue(v5, "Leaderboard", LeaderboardDataUsingId->mLeaderboardNameStr.mData);
        UFG::OSuiteDBLogger::AddValue(v5, "Score", HIDWORD(msg[2].mPrev));
        UFG::OSuiteDBLogger::SubmitMetric(v5, 0);
      }
    }
  }
}

// File Line: 1942
// RVA: 0x60C9F0
__int64 __fastcall UFG::UIHKScreenSocialHub::ShouldShowGameSlice(
        UFG::UIHKScreenSocialHub *this,
        UFG::qSymbol *sliceName)
{
  unsigned int mUID; // eax
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::qSymbol *p_mLeaderboardName; // rbx
  UFG::GameStatTracker *v7; // rax
  UFG::qSymbol symGameSliceName; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol *p_symGameSliceName; // [rsp+50h] [rbp+18h]

  mUID = sliceName->mUID;
  if ( sliceName->mUID == -1 )
    return 0i64;
  p_symGameSliceName = &symGameSliceName;
  symGameSliceName.mUID = mUID;
  if ( UFG::GameStatAction::GameSliceAction::IsCompleted(&symGameSliceName.mUID) )
    return (unsigned int)(UFG::ProgressionTracker::Instance()->mModeType != ModeType_Challenge) + 1;
  v5 = UFG::OSuiteLeaderboardManager::Instance();
  p_mLeaderboardName = &UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(v5, sliceName)->mLeaderboardName;
  v7 = UFG::GameStatTracker::Instance();
  return (int)UFG::GameStatTracker::GetStat(v7, LeaderboardScoreIntList, p_mLeaderboardName) > 0;
}

// File Line: 1969
// RVA: 0x5E71A0
UFG::qSymbol *__fastcall UFG::UIHKScreenSocialHub::GetCurrentItemGameSliceName(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::qSymbol *p_mSliceName; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return &UFG::gNullQSymbol;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
  if ( (int)pval.mValue.NValue == -1 )
    p_mSliceName = &UFG::gNullQSymbol;
  else
    p_mSliceName = &this->mSocialHubProperties.p[(int)pval.mValue.NValue].mLBD->mSliceName;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return p_mSliceName;
}

// File Line: 1993
// RVA: 0x62B360
bool __fastcall UFG::UIHKScreenSocialHub::handleMessage(
        UFG::UIHKScreenSocialHub *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::OSuiteMessage *v6; // rdi
  Scaleform::GFx::Movie *pObject; // r13
  UFG::SocialLogDataManager *v9; // rax
  UFG::SocialLogDataManager *v10; // rax
  UFG::SocialLogDataManager *List; // rbx
  int v12; // r15d
  int v13; // ecx
  __int64 i; // rax
  UFG::UIHKScreenSocialHub::SocialHubProperty *v15; // r8
  unsigned int v16; // r9d
  unsigned int size; // r10d
  UFG::UIHKScreenSocialHub::SocialHubProperty *p; // rbx
  int mUIItemIndex; // ebx
  UFG::LeaderboardCategory mCategory; // edx
  __int32 v21; // edx
  int v22; // edx
  int v23; // r15d
  UFG::GameStatTracker *v24; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  UFG::qSymbol *CurrentItemGameSliceName; // rax
  bool v27; // bl
  const char *v28; // r8
  int NValue; // ebx
  char *mData; // rbx
  UFG::ProgressionTracker *v31; // rax
  UFG::OnlineManager *v32; // rax
  const char *v33; // rbx
  __int64 v34; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  unsigned int v38; // edx
  int mLastListTouchedByMouse; // eax
  UFG::UIHKScreenSocialHub *v40; // rcx
  int v41; // r13d
  int *j; // rbx
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
  UFG::OnlineId *OnlineId; // rbx
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
  BOOL dstOnlineId; // [rsp+30h] [rbp-D0h]
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> receivers; // [rsp+48h] [rbp-B8h] BYREF
  UFG::OnlineId id; // [rsp+58h] [rbp-A8h] BYREF
  UFG::OnlineId v72; // [rsp+70h] [rbp-90h] BYREF
  char v73[16]; // [rsp+88h] [rbp-78h] BYREF
  __int64 v74; // [rsp+98h] [rbp-68h]
  int v75; // [rsp+A0h] [rbp-60h]
  double v76; // [rsp+A8h] [rbp-58h]
  UFG::OnlineId v77; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::GFx::Value v78; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::Value pval; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::GFx::Value v80; // [rsp+130h] [rbp+30h] BYREF
  Scaleform::GFx::Value v81; // [rsp+160h] [rbp+60h] BYREF
  __int64 v82; // [rsp+190h] [rbp+90h]
  UFG::qString dstOnlineName; // [rsp+198h] [rbp+98h] BYREF
  UFG::qString result; // [rsp+1C0h] [rbp+C0h] BYREF
  int score; // [rsp+230h] [rbp+130h]
  UFG::SocialLogData_Challenge *v86; // [rsp+248h] [rbp+148h]

  v82 = -2i64;
  v6 = 0i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0;
  if ( msgId == UI_HASH_TAB_ANIM_COMPLETE )
  {
    this->mbTabbingScrollLock = 0;
    return 1;
  }
  if ( msgId == UI_HASH_INPUT_SWAPPED_30 )
    UFG::UIHKScreenSocialHub::RefreshHelpButtonsEx(this);
  if ( this->mHandleMessageDisabled )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  this->mTimeElapsedAfterMoving = 0.0;
  if ( !this->mPopupActive )
  {
    if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x5958830u, 0i64, 0, 0i64);
      UFG::UIHKScreenSocialHub::ShowFirstTimeIntro(this);
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      if ( this->mCurrentScreenType
        || (v9 = UFG::SocialLogDataManager::Instance(), UFG::SocialLogDataManager::ListContainsActiveFlowEntries(v9) != 1) )
      {
        v24 = UFG::GameStatTracker::Instance();
        MapBool = UFG::GameStatTracker::GetMapBool(v24, Collectible_Safehouse);
        if ( (unsigned int)UFG::PersistentData::MapBool::GetTrueCount(MapBool) )
        {
          if ( !this->mPopulateRhsListAsyncRequested && (unsigned int)(this->mCurrentScreenType - 3) <= 1 )
          {
            CurrentItemGameSliceName = UFG::UIHKScreenSocialHub::GetCurrentItemGameSliceName(this);
            if ( (unsigned int)UFG::UIHKScreenSocialHub::ShouldShowGameSlice(this, CurrentItemGameSliceName) == 2 )
            {
              v27 = this->mCurrentScreenType == 3;
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
              v28 = "$HUD_SOCIAL_REPLAYRACE";
              if ( v27 )
                v28 = "$HUD_SOCIAL_REPLAYMISSION";
              UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, v28, 0, 0);
            }
          }
        }
      }
      else
      {
        v10 = UFG::SocialLogDataManager::Instance();
        List = UFG::SocialLogDataManager::GetList(v10);
        if ( !(unsigned int)UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0>::Count(&List->m_lSocialLogDataList) )
          return 1;
        pval.pObjectInterface = 0i64;
        pval.Type = VT_Undefined;
        v74 = 0i64;
        v75 = 0;
        Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gSocialLogList");
        pval.pObjectInterface->vfptr->Invoke(
          pval.pObjectInterface,
          (void *)pval.mValue.pString,
          (Scaleform::GFx::Value *)v73,
          "SelectedIndex",
          0i64,
          0i64,
          (pval.Type & 0x8F) == 10);
        v12 = (int)v76;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
        v13 = UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0>::Count(&List->m_lSocialLogDataList) - v12 - 1;
        for ( i = (__int64)&List->m_lSocialLogDataList.mNode.mNext[-2].mNext; v13 > 0; i = *(_QWORD *)(i + 32) - 24i64 )
        {
          if ( (UFG::SocialLogDataManager *)i == &List[-1] )
            break;
          --v13;
        }
        v15 = 0i64;
        v16 = 0;
        size = this->mSocialHubProperties.size;
        if ( size )
        {
          do
          {
            p = this->mSocialHubProperties.p;
            if ( *(_DWORD *)(i + 56) == p[v16].mLBD->mLeaderboardId )
              v15 = &p[v16];
            ++v16;
          }
          while ( v16 < size );
        }
        mUIItemIndex = v15->mUIItemIndex;
        mCategory = v15->mLBD->mCategory;
        if ( mCategory )
        {
          v21 = mCategory - 1;
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
        this->mCurrentScreenType = v23;
        UFG::UIHKScreenSocialHub::FLASH_FocusTab(this, v23);
        UFG::UIHKScreenSocialHub::PopulateLhsList(this, this->mCurrentScreenType);
        v78.pObjectInterface = 0i64;
        v78.Type = VT_Undefined;
        Scaleform::GFx::Movie::GetVariable(pObject, &v78, "gSocialHubLhsList");
        if ( (v75 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
            v74,
            v73,
            COERCE_DOUBLE(*(_QWORD *)&v76));
          v74 = 0i64;
        }
        v75 = 5;
        v76 = (double)mUIItemIndex;
        LOBYTE(dstOnlineId) = (v78.Type & 0x8F) == 10;
        v78.pObjectInterface->vfptr->Invoke(
          v78.pObjectInterface,
          (void *)v78.mValue.pString,
          0i64,
          "SetSelectedIndex",
          (Scaleform::GFx::Value *)v73,
          1ui64,
          dstOnlineId);
        UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(this);
        UFG::UIHKScreenSocialHub::RequestRhsListPopulation(this);
        UFG::UIHKScreenSocialHub::ShowHelpBarWidget(this, this->mCurrentScreenType, 0);
        if ( (v78.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v78.pObjectInterface->vfptr->gap8[8])(
            v78.pObjectInterface,
            &v78,
            v78.mValue);
          v78.pObjectInterface = 0i64;
        }
        v78.Type = VT_Undefined;
        if ( (v75 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
            v74,
            v73,
            COERCE_DOUBLE(*(_QWORD *)&v76));
          v74 = 0i64;
        }
        v75 = 0;
        if ( (pval.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            pval.mValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = VT_Undefined;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_DIALOG_YES_30 )
    {
      v81.pObjectInterface = 0i64;
      v81.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &v81, "gLeaderboardId");
      NValue = (int)v81.mValue.NValue;
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      mData = this->mSocialHubProperties.p[NValue].mLBD->mSliceNameStr.mData;
      v31 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::BindChallengeGameSlice(v31, mData);
      this->mLaunchingMissionReplay = 1;
      if ( (v81.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v81.pObjectInterface->vfptr->gap8[8])(
          v81.pObjectInterface,
          &v81,
          v81.mValue);
        v81.pObjectInterface = 0i64;
      }
      v81.Type = VT_Undefined;
      return 1;
    }
    if ( msgId == UI_HASH_DIALOG_NO_30 )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    if ( msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 )
    {
      v32 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v32)
        && this->mCurrentScreenType
        && (UFG::qList<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry,1,0> *)UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != &UFG::UIHKScreenSocialHub::gLeaderboardEntries )
      {
        v80.pObjectInterface = 0i64;
        v80.Type = VT_Undefined;
        Scaleform::GFx::Movie::GetVariable(pObject, &v80, "gOnlineId");
        if ( (v80.Type & 0x8F) != 0 )
        {
          v33 = (v80.Type & 0x40) != 0 ? *v80.mValue.pStringManaged : v80.mValue.pString;
          if ( (unsigned int)UFG::qStringLength(v33) )
          {
            id.mPrev = &id;
            id.mNext = &id;
            id.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(HIDWORD(id.m_SteamId.m_steamid.m_unAll64Bits), 0) & 0xFF0FFFFF00000000ui64;
            HIBYTE(id.m_SteamId.m_steamid.m_unAll64Bits) = 0;
            *((_DWORD *)&id.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
            id.m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(v33, 0i64);
            UFG::OnlineUtil::ShowGamerCard(&id, v34);
            mPrev = id.mPrev;
            mNext = id.mNext;
            id.mPrev->mNext = id.mNext;
            mNext->mPrev = mPrev;
            id.mPrev = &id;
            id.mNext = &id;
          }
        }
        if ( (v80.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v80.pObjectInterface->vfptr->gap8[8])(
            v80.pObjectInterface,
            &v80,
            v80.mValue);
          v80.pObjectInterface = 0i64;
        }
        v80.Type = VT_Undefined;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      UFG::UIHKScreenSocialHub::OnButton1Pressed(this);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_BUTTON_R3_PRESSED_30 )
    {
      UFG::UIHKScreenSocialHub::OnR3Pressed(this);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      if ( !this->mbTabbingScrollLock )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
        this->mCurrentScreenType = (this->mCurrentScreenType + 1) % this->mMaxTabs;
        UFG::UIHKScreenSocialHub::RefreshScreenType(this);
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( !this->mbTabbingScrollLock )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
        if ( --this->mCurrentScreenType < 0 )
          this->mCurrentScreenType += this->mMaxTabs;
        UFG::UIHKScreenSocialHub::RefreshScreenType(this);
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
      || msgId == UI_HASH_DPAD_UP_PRESSED_30
      && !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
      || msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      && !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController
      || (v38 = UI_HASH_THUMBSTICK_RIGHT_UP_30, msgId == UI_HASH_THUMBSTICK_RIGHT_UP_30)
      || msgId == UI_HASH_THUMBSTICK_RIGHT_DOWN_30 )
    {
      v38 = msgId;
    }
    else
    {
      if ( msgId == UI_HASH_MOUSE_MOVE_LEFT_LIST )
      {
        this->mLastListTouchedByMouse = 0;
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId == UI_HASH_MOUSE_MOVE_RIGHT_LIST )
      {
        this->mLastListTouchedByMouse = 1;
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId != UI_HASH_MOUSE_WHEEL_SCROLL_30 )
      {
        if ( msgId != UI_HASH_MOUSE_MOVE_30 )
        {
          if ( msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
          {
            if ( msgId == UI_HASH_MOUSE_CHANGE_TAB_20 )
            {
              if ( !this->mbTabbingScrollLock )
              {
                if ( UFG::HudAudio::m_instance )
                  UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
                this->mCurrentScreenType = UFG::UI::GetFlashArgsInt(msg);
                UFG::UIHKScreenSocialHub::RefreshScreenType(this);
              }
            }
            else if ( msgId == UI_HASH_UPDATE_RHS )
            {
              UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(this);
              UFG::UIHKScreenSocialHub::RequestRhsListPopulation(this);
            }
            else if ( msgId == UI_HASH_CHALLENGE_BUTTON_ACCEPTED )
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
              receivers.mNode.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
              receivers.mNode.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
              v41 = -1;
              score = 0;
              for ( j = (int *)&this->mChallengeDialogPopupEntries.mNode.mNext[-1].mNext;
                    j != &this->mLastListTouchedByMouse;
                    j = (int *)(*((_QWORD *)j + 2) - 8i64) )
              {
                if ( *((_BYTE *)j + 64) )
                {
                  v43 = UFG::qMalloc(0x18ui64, "UIHKScreenSocialHub", 0i64);
                  if ( v43 )
                  {
                    UFG::OnlineId::OnlineId((UFG::OnlineId *)v43, *((const char **)j + 12));
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
                  v41 = j[28];
                  score = j[29];
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
                    v72.mPrev = &v72;
                    v72.mNext = &v72;
                    v72.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(
                                                              HIDWORD(v72.m_SteamId.m_steamid.m_unAll64Bits),
                                                              0) & 0xFF0FFFFF00000000ui64;
                    HIBYTE(v72.m_SteamId.m_steamid.m_unAll64Bits) = 0;
                    *((_DWORD *)&v72.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
                    UFG::qString::qString(&dstOnlineName, "Dummy");
                    v86 = (UFG::SocialLogData_Challenge *)UFG::qMalloc(0xD0ui64, "UIHKScreenSocialHub", 0i64);
                    if ( v86 )
                    {
                      v50 = UFG::OnlineManager::Instance();
                      srcOnlineName = UFG::OnlineManager::GetOnlineName(v50, &result);
                      v52 = UFG::OnlineManager::Instance();
                      OnlineId = UFG::OnlineManager::GetOnlineId(v52, &v77);
                      v54 = 3;
                      v55 = UFG::OnlineUtil::CurrentTimeMillis();
                      UFG::SocialLogData_Challenge::SocialLogData_Challenge(
                        v86,
                        v55,
                        v41,
                        score,
                        OnlineId,
                        srcOnlineName,
                        &v72,
                        &dstOnlineName);
                      v6 = v56;
                    }
                    else
                    {
                      v54 = 0;
                    }
                    if ( (v54 & 2) != 0 )
                    {
                      v54 &= ~2u;
                      v57 = v77.mPrev;
                      v58 = v77.mNext;
                      v77.mPrev->mNext = v77.mNext;
                      v58->mPrev = v57;
                      v77.mPrev = &v77;
                      v77.mNext = &v77;
                    }
                    if ( (v54 & 1) != 0 )
                      UFG::qString::~qString(&result);
                    v59 = UFG::OSuiteMessenger::Instance();
                    if ( UFG::OSuiteMessenger::Send(v59, v6, &receivers, UFG::UIHKScreenSocialHub::SendMessageCallbackA) )
                      this->mHandleMessageDisabled = 1;
                    UFG::qString::~qString(&dstOnlineName);
                    v60 = v72.mPrev;
                    v61 = v72.mNext;
                    v72.mPrev->mNext = v72.mNext;
                    v61->mPrev = v60;
                    v72.mPrev = &v72;
                    v72.mNext = &v72;
                  }
                }
              }
              else
              {
                UFG::UIScreenDialogBox::createOKDialog(0i64, &customCaption, "$HUD_SOCIAL_FAILSEND", 1);
              }
              this->mDisplayingChallengeDialog = 0;
              UFG::UIHKScreenSocialHub::ShowHelpButtonsEx(this);
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
            else if ( msgId == UI_HASH_CHALLENGE_BUTTON_CANCELED )
            {
              UFG::UIHKScreenSocialHub::ShowHelpButtonsEx(this);
            }
            return UFG::UIScreen::handleMessage(this, msgId, msg);
          }
          goto LABEL_15;
        }
        goto LABEL_119;
      }
      mLastListTouchedByMouse = this->mLastListTouchedByMouse;
      if ( !mLastListTouchedByMouse )
      {
        v40 = this;
        if ( SLODWORD(msg[1].mPrev) <= 0 )
          v38 = UI_HASH_THUMBSTICK_LEFT_DOWN_30;
        else
          v38 = UI_HASH_THUMBSTICK_LEFT_UP_30;
        goto LABEL_160;
      }
      if ( mLastListTouchedByMouse != 1 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      if ( SLODWORD(msg[1].mPrev) <= 0 )
        v38 = UI_HASH_THUMBSTICK_RIGHT_DOWN_30;
    }
    v40 = this;
LABEL_160:
    UFG::UIHKScreenSocialHub::OnScrollUpDown(v40, v38);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    if ( msgId != UI_HASH_MOUSE_MOVE_30 )
    {
      if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
LABEL_15:
        UFG::UIHKScreenSocialHub::Flash_HandleMouseClick(
          this,
          (float)SLODWORD(msg[1].vfptr),
          (float)SHIDWORD(msg[1].vfptr));
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
LABEL_119:
    UFG::UIHKScreenSocialHub::Flash_HandleMouseMove(this, (float)SLODWORD(msg[1].vfptr), (float)SHIDWORD(msg[1].vfptr));
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  Scaleform::GFx::Movie::Invoke(pObject, "HideFirstTimeIntro", 0i64, 0i64, 0);
  this->mPopupActive = 0;
  if ( !UFG::HudAudio::m_instance )
    return 1;
  UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
  return 1;
}DWORD(msg[1].vfptr),
          (float)SHIDWORD(msg[1].vfptr));
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
LABEL_119:
    UFG::UIHKScreenSocialHub::Flash_HandleMouseMove(this, (float)SLODWORD(msg[1].vfptr), (float)SHIDWORD(msg[1].vfptr));
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  Scaleform::GFx::Movie::Invoke(pObject, "HideFirstTimeIntro", 0i64, 0i64, 0);
  this->mPopupActive = 0;
  if ( !UFG::HudAu

// File Line: 2350
// RVA: 0x605AF0
void __fastcall UFG::UIHKScreenSocialHub::SetFlagAsSentForNewHighScoreSaveEntry(
        UFG::UIHKScreenSocialHub *this,
        UFG::OSuiteMessage *message)
{
  int v3; // eax
  UFG::allocator::free_link *v4; // rsi
  unsigned int v5; // ebx
  const char *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::PersistentData::MapFloat *MapBinary; // r14
  char **v9; // rax
  char *v10; // rbx
  int v11; // eax
  UFG::allocator::free_link *v12; // rdi
  unsigned int v13; // ebx
  char *v14; // rax
  int v15; // eax
  UFG::PersistentData::KeyBinary *Name; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+20h] [rbp-C8h] BYREF
  UFG::PersistentData::Binary binary; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v19; // [rsp+40h] [rbp-A8h]
  UFG::SocialLogData_NewHighScore v20; // [rsp+50h] [rbp-98h] BYREF
  UFG::SocialLogData v21; // [rsp+120h] [rbp+38h] BYREF
  int dest; // [rsp+200h] [rbp+118h] BYREF

  if ( !message )
    return;
  v19 = -2i64;
  UFG::SocialLogData::SocialLogData(&v21);
  *(_QWORD *)&v20.m_sDstOnlineName.mStringHash32 = &UFG::SocialLogData_Challenge::`vftable;
  v21.m_sDstOnlineName.mMagic = 0;
  v21.m_sDstOnlineName.mData = 0i64;
  v3 = ((__int64 (__fastcall *)(unsigned int *))*(&UFG::SocialLogData_Challenge::`vftable + 4))(&v20.m_sDstOnlineName.mStringHash32);
  v4 = UFG::qMalloc(v3 + 8, "UIHKScreenSocialHub", 0i64);
  v5 = message->vfptr->Size(message);
  v6 = message->vfptr->Serialize(message);
  UFG::qMemCopy(v4, v6, v5);
  UFG::SocialLogData_Challenge::Deserialize(
    (UFG::SocialLogData_Challenge *)&v20.m_sDstOnlineName.mStringHash32,
    (char *)v4);
  v7 = UFG::GameStatTracker::Instance();
  MapBinary = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBinary(v7, SocialLogBinaryList);
  UFG::PersistentData::MapInt::GetIterator(MapBinary, &result);
  if ( !UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
    goto LABEL_10;
  while ( 1 )
  {
    v9 = (char **)UFG::PersistentData::MapBinary::Iterator::GetBinary((UFG::PersistentData::MapBinary::Iterator *)&result);
    if ( !v9 )
      goto LABEL_9;
    v10 = *v9;
    if ( !*v9 )
      goto LABEL_9;
    dest = 0;
    UFG::qMemCopy(&dest, v10 + 4, 4u);
    UFG::qEndianSwapBytes((char *)&dest, 4u);
    if ( dest )
      goto LABEL_9;
    UFG::SocialLogData::SocialLogData(&v20);
    v20.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
    v20.m_sDstOnlineName.mMagic = 0;
    v20.m_sDstOnlineName.mData = 0i64;
    UFG::SocialLogData_NewHighScore::Deserialize(&v20, v10);
    if ( v20.UFG::SocialLogData::UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mNext == v21.UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mNext )
      break;
    UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(&v20);
LABEL_9:
    UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
    if ( !UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
      goto LABEL_10;
  }
  v20.m_sDstOnlineName.mMagic = 1;
  v11 = ((__int64 (__fastcall *)(UFG::SocialLogData_NewHighScore *))v20.vfptr[1].__vecDelDtor)(&v20);
  v12 = UFG::qMalloc(v11 + 8, "UIHKScreenSocialHub", 0i64);
  v13 = ((__int64 (__fastcall *)(UFG::SocialLogData_NewHighScore *))v20.vfptr[1].__vecDelDtor)(&v20) + 8;
  v14 = UFG::SocialLogData_NewHighScore::Serialize(&v20);
  UFG::qMemCopy(v12, v14, v13);
  v15 = ((__int64 (__fastcall *)(UFG::SocialLogData_NewHighScore *))v20.vfptr[1].__vecDelDtor)(&v20);
  binary.mpBuffer = v12;
  binary.mSize = v15 + 8;
  Name = UFG::PersistentData::MapBinary::Iterator::GetName((UFG::PersistentData::MapBinary::Iterator *)&result);
  UFG::PersistentData::MapBinary::SetBinary((UFG::PersistentData::MapBinary *)MapBinary, &Name->mKey, &binary);
  UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(&v20);
LABEL_10:
  operator delete[](v4);
  UFG::SocialLogData_Challenge::~SocialLogData_Challenge((UFG::SocialLogData_Challenge *)&v20.m_sDstOnlineName.mStringHash32);
}

// File Line: 2402
// RVA: 0x5EE500
bool __fastcall UFG::UIHKScreenSocialHub::IsNewHighScoreEntryUsedForChallenge(
        UFG::UIHKScreenSocialHub *this,
        unsigned int index,
        int score)
{
  __int64 v4; // rsi
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::MapFloat *MapBinary; // rax
  char **Binary; // rax
  char *v9; // rbx
  bool v10; // bl
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+20h] [rbp-108h] BYREF
  __int64 v13; // [rsp+30h] [rbp-F8h]
  UFG::SocialLogData_NewHighScore v14; // [rsp+40h] [rbp-E8h] BYREF
  int dest; // [rsp+148h] [rbp+20h] BYREF

  v13 = -2i64;
  v4 = index;
  v6 = UFG::GameStatTracker::Instance();
  MapBinary = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBinary(v6, SocialLogBinaryList);
  UFG::PersistentData::MapInt::GetIterator(MapBinary, &result);
  while ( UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
  {
    Binary = (char **)UFG::PersistentData::MapBinary::Iterator::GetBinary((UFG::PersistentData::MapBinary::Iterator *)&result);
    if ( Binary )
    {
      v9 = *Binary;
      if ( *Binary )
      {
        dest = 0;
        UFG::qMemCopy(&dest, v9 + 4, 4u);
        UFG::qEndianSwapBytes((char *)&dest, 4u);
        if ( !dest )
        {
          UFG::SocialLogData::SocialLogData(&v14);
          v14.vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData_NewHighScore::`vftable;
          v14.m_iHasSent = 0;
          v14.m_aData = 0i64;
          UFG::SocialLogData_NewHighScore::Deserialize(&v14, v9);
          if ( v14.m_iLeaderboardId == this->mSocialHubProperties.p[v4].mLBD->mLeaderboardId && v14.m_iScore == score )
          {
            v10 = v14.m_iHasSent != 0;
            UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(&v14);
            return v10;
          }
          UFG::SocialLogData_NewHighScore::~SocialLogData_NewHighScore(&v14);
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
  Scaleform::GFx::Movie *pObject; // rsi
  int NValue; // ebx
  bool v5; // bl
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  if ( !UFG::OSuiteManager::Instance()->m_bConnected || this->mCurrentScreenType )
    return 0;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gCommId");
  v5 = 0;
  if ( (pval.Type & 0x8F) != 0 && !(int)pval.mValue.NValue )
  {
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gLeaderboardId");
    NValue = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gScore");
    if ( !UFG::UIHKScreenSocialHub::IsNewHighScoreEntryUsedForChallenge(this, NValue, (int)pval.mValue.NValue) )
      v5 = 1;
  }
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return v5;
}

// File Line: 2483
// RVA: 0x5F2AC0
void __fastcall UFG::UIHKScreenSocialHub::OnButton1Pressed(UFG::UIHKScreenSocialHub *this)
{
  UFG::GameStatTracker *v2; // rax
  bool v3; // di

  v2 = UFG::GameStatTracker::Instance();
  v3 = (int)UFG::GameStatTracker::GetStat(v2, IsBannedByCommunityManager) > 0;
  if ( UFG::UIHKScreenSocialHub::IsChallengeableEntry(this) && !v3 )
  {
    UFG::UIHKScreenSocialHub::PopulateChallengeListAsync(this, this->mCurrentScreenType);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
  }
}

// File Line: 2495
// RVA: 0x5F2E80
void __fastcall UFG::UIHKScreenSocialHub::OnR3Pressed(UFG::UIHKScreenSocialHub *this)
{
  if ( this->mCurrentScreenType )
  {
    this->mCurrentLeaderboardType = (this->mCurrentLeaderboardType + 1) % 2;
    UFG::UIHKScreenSocialHub::RequestRhsListPopulation(this);
    UFG::UIHKScreenSocialHub::ShowHelpBarWidget(this, this->mCurrentScreenType, 0);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
  }
}

// File Line: 2509
// RVA: 0x5F2F30
void __fastcall UFG::UIHKScreenSocialHub::OnScrollUpDown(UFG::UIHKScreenSocialHub *this, unsigned int msgId)
{
  Scaleform::GFx::Movie *pObject; // r15
  const char *v5; // rbp
  const char *v6; // r14
  UFG::HudAudio *v7; // rcx
  unsigned int v8; // edx
  UFG::qString *p_result; // rcx
  UFG::HudAudio *v10; // rcx
  unsigned int v11; // edx
  bool v12; // r8
  UFG::qString result; // [rsp+38h] [rbp-70h] BYREF
  UFG::qString v14; // [rsp+60h] [rbp-48h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
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
    UFG::AudioEntity::CreateAndPlayEvent(v10, v11, 0i64, 0, 0i64);
LABEL_28:
    UFG::qString::FormatEx(&v14, "SocialHub%sList_Scroll%s", v5, v6);
    UFG::qString::FormatEx(&result, "SocialHub%sList_Refresh", v5);
    Scaleform::GFx::Movie::Invoke(pObject, v14.mData, 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, result.mData, 0i64, 0i64, 0);
    if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
      || msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
      || msgId == UI_HASH_DPAD_DOWN_PRESSED_30 )
    {
      UFG::UIHKScreenSocialHub::PopulateRhsSubHeadDesc(this);
      UFG::UIHKScreenSocialHub::RequestRhsListPopulation(this);
    }
    UFG::qString::~qString(&result);
    p_result = &v14;
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
    UFG::AudioEntity::CreateAndPlayEvent(v7, v8, 0i64, 0, 0i64);
  }
LABEL_20:
  UFG::qString::FormatEx(&result, "SocialLogList_Scroll%s", v6);
  Scaleform::GFx::Movie::Invoke(pObject, result.mData, 0i64, 0i64, 0);
  Scaleform::GFx::Movie::Invoke(pObject, "SocialLogList_Refresh", 0i64, 0i64, 0);
  p_result = &result;
LABEL_34:
  UFG::qString::~qString(p_result);
LABEL_35:
  if ( (unsigned int)UFG::qStringCompare(v5, "Rhs", -1) )
    v12 = 0;
  else
    v12 = UFG::UIHKScreenSocialHub::gLeaderboardEntries.mNode.mNext != (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&UFG::UIHKScreenSocialHub::gLeaderboardEntries;
  UFG::UIHKScreenSocialHub::ShowHelpBarWidget(this, this->mCurrentScreenType, v12);
}

// File Line: 2582
// RVA: 0x5D7F10
void __fastcall UFG::UIHKScreenSocialHub::FLASH_FocusTab(UFG::UIHKScreenSocialHub *this, int screenType)
{
  Scaleform::GFx::Movie *pObject; // rbx
  const char *v5; // rdx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  this->mbTabbingScrollLock = 1;
  UFG::UIHKScreenSocialHub::ReleaseTexturePack(this);
  pObject = this->mRenderable->m_movie.pObject;
  if ( screenType )
  {
    switch ( screenType )
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
  Scaleform::GFx::Movie::Invoke(pObject, v5, 0i64, 0i64, 0);
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)screenType;
  Scaleform::GFx::Movie::Invoke(pObject, "FocusTab", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 2596
// RVA: 0x5D8020
void __fastcall UFG::UIHKScreenSocialHub::FLASH_LoadRHSTexture(UFG::UIHKScreenSocialHub *this)
{
  signed int size; // ecx
  __int64 mCurrentIndex; // rax
  char *mData; // rdi
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString v6; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h] BYREF

  size = UFG::OSuiteLeaderboardManager::Instance()->mLeaderboardData.size;
  mCurrentIndex = (unsigned int)this->mCurrentIndex;
  if ( (int)mCurrentIndex >= 0 && (int)mCurrentIndex < size )
  {
    mData = this->mSocialHubProperties.p[mCurrentIndex].mLBD->mImage.mData;
    pObject = this->mRenderable->m_movie.pObject;
    if ( mData )
    {
      if ( pObject )
      {
        UFG::qString::qString(&v6);
        UFG::qString::Format(&v6, "img://%s", mData);
        pargs.pObjectInterface = 0i64;
        pargs.Type = VT_String;
        pargs.mValue.pString = v6.mData;
        Scaleform::GFx::Movie::Invoke(pObject, "SocialHubRhsView_SetTexture", 0i64, &pargs, 1u);
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_Undefined;
        UFG::qString::~qString(&v6);
      }
    }
  }
}

// File Line: 2618
// RVA: 0x5DB4E0
void __fastcall UFG::UIHKScreenSocialHub::Flash_HandleMouseMove(
        UFG::UIHKScreenSocialHub *this,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *MovieSafe; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( MovieSafe )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseY;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "HandleMouseMove", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2631
// RVA: 0x5DAE90
void __fastcall UFG::UIHKScreenSocialHub::Flash_HandleMouseClick(
        UFG::UIHKScreenSocialHub *this,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *MovieSafe; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( MovieSafe )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseY;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "HandleMouseClick", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2646
// RVA: 0x5F14D0
void __fastcall UFG::UIHKScreenSocialHub::LoadTexturePack(UFG::UIHKScreenSocialHub *this, unsigned int index)
{
  __int64 v2; // rdi
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qString v5; // [rsp+38h] [rbp-30h] BYREF

  v2 = index;
  UFG::UIHKScreenSocialHub::ReleaseTexturePack(this);
  if ( this->mSocialHubProperties.p[v2].mLBD->mImage.mLength )
  {
    this->mCurrentIndex = v2;
    UFG::qString::qString(&v5);
    UFG::qString::Format(&v5, "Data\\UI\\%s_TP.perm.bin", this->mSocialHubProperties.p[v2].mLBD->mImage.mData);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v4,
      v5.mData,
      HIGH_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHKScreenSocialHub::TextureLoadedCallback,
      0i64);
    UFG::qString::~qString(&v5);
  }
}

// File Line: 2661
// RVA: 0x600C60
void __fastcall UFG::UIHKScreenSocialHub::ReleaseTexturePack(UFG::UIHKScreenSocialHub *this)
{
  signed int size; // ecx
  int mCurrentIndex; // eax
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  size = UFG::OSuiteLeaderboardManager::Instance()->mLeaderboardData.size;
  mCurrentIndex = this->mCurrentIndex;
  if ( mCurrentIndex > 0 && mCurrentIndex < size )
  {
    UFG::qString::qString(&v5);
    UFG::qString::Format(
      &v5,
      "Data\\UI\\%s_TP.perm.bin",
      this->mSocialHubProperties.p[this->mCurrentIndex].mLBD->mImage.mData);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, v5.mData);
    this->mCurrentIndex = -1;
    UFG::qString::~qString(&v5);
  }
}

// File Line: 2675
// RVA: 0x612910
void __fastcall UFG::UIHKScreenSocialHub::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenSocialHub *Screen; // rax

  Screen = (UFG::UIHKScreenSocialHub *)UFG::UIScreenManagerBase::getScreen(
                                         UFG::UIScreenManager::s_instance,
                                         "SocialHub");
  if ( Screen )
    UFG::UIHKScreenSocialHub::FLASH_LoadRHSTexture(Screen);
}

// File Line: 2685
// RVA: 0x60D690
void __fastcall UFG::UIHKScreenSocialHub::ShowFirstTimeIntro(UFG::UIHKScreenSocialHub *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  pObject = this->mRenderable->m_movie.pObject;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_String;
  pargs.mValue.pString = "$SOCIAL_HUB_INFO";
  Scaleform::GFx::Movie::Invoke(pObject, "ShowFirstTimeIntro", 0i64, &pargs, 1u);
  this->mPopupActive = 1;
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

