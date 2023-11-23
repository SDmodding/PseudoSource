// File Line: 93
// RVA: 0x156E160
__int64 UFG::_dynamic_initializer_for__mainFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Main", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::mainFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__mainFlow__);
}

// File Line: 94
// RVA: 0x156E110
__int64 UFG::_dynamic_initializer_for__ghostFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_Ghost", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ghostFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ghostFlow__);
}

// File Line: 95
// RVA: 0x156DB50
__int64 UFG::_dynamic_initializer_for__cnyFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_CNY", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::cnyFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__cnyFlow__);
}

// File Line: 124
// RVA: 0x5C5EA0
void __fastcall UFG::UIHKScreenMainMenu::UIHKScreenMainMenu(UFG::UIHKScreenMainMenu *this)
{
  UFG::OnlineManagerObserver *v2; // rdx
  UFG::OSuiteManagerObserver *v3; // rcx
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *p_mOnlineIdsToGetDisplayImageFor; // rbx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *i; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax

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
  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMainMenu::`vftable{for `UFG::UIScreen};
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable{for `UFG::OnlineManagerObserver};
  v3->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable{for `UFG::OSuiteManagerObserver};
  this->mInfoTickerSet = 0;
  UFG::UIPropertySetMenu::UIPropertySetMenu(&this->mMenu);
  this->mMenu.vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenuMainNav::`vftable;
  *(_WORD *)&this->mContinueEnabled = 0;
  p_mOnlineIdsToGetDisplayImageFor = &this->mOnlineIdsToGetDisplayImageFor;
  this->mOnlineIdsToGetDisplayImageFor.mNode.mPrev = &this->mOnlineIdsToGetDisplayImageFor.mNode;
  this->mOnlineIdsToGetDisplayImageFor.mNode.mNext = &this->mOnlineIdsToGetDisplayImageFor.mNode;
  this->mCurrentDisplayImageSlot = 0;
  this->mSocialWidgetProperties.p = 0i64;
  *(_QWORD *)&this->mSocialWidgetProperties.size = 0i64;
  this->mFriendsListState = FL_STATE_WAITING;
  this->mIsHeaderLoadStarted = 0;
  this->mHeaderInfo.p = 0i64;
  *(_QWORD *)&this->mHeaderInfo.size = 0i64;
  `eh vector constructor iterator(this->mFlowList, 4ui64, 3, (void (__fastcall *)(void *))BackInfo::BackInfo);
  this->mCurrentFlowToCheck = 0;
  *(_WORD *)&this->mIsLoadingSaveGame = 0;
  this->mIsTransitionToGame = 0;
  this->mFlowForContinue.mUID = -1;
  this->mState = STATE_INIT;
  UFG::MoviePlayer::MoviePlayer(&this->HKUIMovie);
  this->mInactivityTimer = 0.0;
  if ( this->mSocialWidgetProperties.capacity < 0x100 )
    UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0>::Reallocate(
      &this->mSocialWidgetProperties,
      0x100u,
      "qArray.Reallocate(Reserve)");
  for ( i = this->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
        i != (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)p_mOnlineIdsToGetDisplayImageFor;
        i = this->mOnlineIdsToGetDisplayImageFor.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
}

// File Line: 133
// RVA: 0x5CB400
void __fastcall UFG::UIHKScreenMainMenu::~UIHKScreenMainMenu(UFG::UIHKScreenMainMenu *this)
{
  UFG::OnlineManagerObserver *v2; // r14
  UFG::OnlineManagerObserver *v3; // rsi
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v6; // eax
  UFG::OnlineManager *v7; // rax
  UFG::OnlineManager *v8; // rax
  UFG::UIScreenTextureManager *v9; // rax
  UFG::ProgressionTracker *v10; // rax
  UFG::qSymbol *ActiveFlow; // rax
  UFG::qPropertySet *DLCPropertyNode; // rbx
  UFG::qArray<unsigned long,0> *v13; // rax
  UFG::qWiseSymbol *v14; // rax
  unsigned int mUID; // ecx
  UFG::OSuiteTickerManager *v16; // rax
  hkgpIndexedMeshDefinitions::Edge *v17; // rdx
  bool IsTickerAvailable; // bl
  UFG::OSuiteTickerManager *v19; // rax
  UFG::OSuiteTickerManager *v20; // rax
  UFG::UIHKScreenMainMenu::HeaderInfo *p; // rcx
  UFG::qSymbol *p_flow; // rbx
  UFG::UIHKScreenMainMenu::SocialWidgetProperty *v23; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v26; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v27; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v28; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v29; // rax
  void *result; // [rsp+58h] [rbp+10h] BYREF

  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMainMenu::`vftable{for `UFG::UIScreen};
  v2 = &this->UFG::OnlineManagerObserver;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable{for `UFG::OnlineManagerObserver};
  v3 = (UFG::OnlineManagerObserver *)&this->UFG::OSuiteManagerObserver;
  this->UFG::OSuiteManagerObserver::vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable{for `UFG::OSuiteManagerObserver};
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  p_HelpBar = &v4->HelpBar;
  v6 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v6);
  v7 = (UFG::OnlineManager *)UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v7, v3);
  v8 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v8, v2);
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v9, "MainMenu");
  if ( UFG::UIHKScreenSplash::smMusicPlaying )
  {
    v10 = UFG::ProgressionTracker::Instance();
    ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v10);
    DLCPropertyNode = UFG::UI::GetDLCPropertyNode("UI-DLCSkins", "AudioProperties", "DLC", ActiveFlow);
    if ( DLCPropertyNode
      && (v13 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                                  (UFG::qSymbol *)&result,
                                                  "stop_mus_fe_lic"),
          (v14 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(DLCPropertyNode, v13, DEPTH_RECURSE)) != 0i64) )
    {
      mUID = v14->mUID;
    }
    else
    {
      if ( (_S10_13 & 1) == 0 )
      {
        _S10_13 |= 1u;
        stop_mus_fe_lic.mUID = UFG::qWiseSymbolUIDFromString("stop_mus_fe_lic", 0x811C9DC5);
        _((AMD_HD3D *)stop_mus_fe_lic.mUID);
        atexit(UFG::UIHKScreenMainMenu::_UIHKScreenMainMenu_::_13_::_dynamic_atexit_destructor_for__stop_mus_fe_lic__);
      }
      mUID = stop_mus_fe_lic.mUID;
    }
    UFG::Music::MusicEvent(mUID);
    UFG::StreamFileWrapper::EnableIncrementalMode(0);
    UFG::UIHKScreenSplash::smMusicPlaying = 0;
  }
  v16 = UFG::OSuiteTickerManager::Instance();
  IsTickerAvailable = UFG::OSuiteTickerManager::IsTickerAvailable(v16, v17);
  v19 = UFG::OSuiteTickerManager::Instance();
  if ( !IsTickerAvailable && !v19->m_downloadActive )
  {
    UFG::OSuiteTickerManager::Instance()->m_tickerType = TICKER_OFFLINE;
    v20 = UFG::OSuiteTickerManager::Instance();
    UFG::OSuiteTickerManager::DownloadTicker(v20);
  }
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::MoviePlayer::~MoviePlayer(&this->HKUIMovie);
  `eh vector destructor iterator(this->mFlowList, 4ui64, 3, (void (__fastcall *)(void *))_);
  p = this->mHeaderInfo.p;
  if ( p )
  {
    p_flow = &p[-1].flow;
    `eh vector destructor iterator(p, 0x10ui64, p[-1].flow.mUID, (void (__fastcall *)(void *))_);
    operator delete[](p_flow);
  }
  this->mHeaderInfo.p = 0i64;
  *(_QWORD *)&this->mHeaderInfo.size = 0i64;
  v23 = this->mSocialWidgetProperties.p;
  if ( v23 )
    operator delete[](v23);
  this->mSocialWidgetProperties.p = 0i64;
  *(_QWORD *)&this->mSocialWidgetProperties.size = 0i64;
  result = &this->mOnlineIdsToGetDisplayImageFor;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mOnlineIdsToGetDisplayImageFor);
  mPrev = this->mOnlineIdsToGetDisplayImageFor.mNode.mPrev;
  mNext = this->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mOnlineIdsToGetDisplayImageFor.mNode.mPrev = &this->mOnlineIdsToGetDisplayImageFor.mNode;
  this->mOnlineIdsToGetDisplayImageFor.mNode.mNext = &this->mOnlineIdsToGetDisplayImageFor.mNode;
  result = &this->mMenu;
  UFG::UIPropertySetMenu::~UIPropertySetMenu(&this->mMenu);
  result = v3;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v26 = v3->mPrev;
  v27 = v3->mNext;
  v26->mNext = v27;
  v27->mPrev = v26;
  v3->mPrev = &v3->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v3->mNext = &v3->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  result = v2;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v28 = v2->mPrev;
  v29 = v2->mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  v2->mPrev = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->mNext = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 180
// RVA: 0x632880
void __fastcall UFG::UIHKScreenMainMenu::init(UFG::UIHKScreenMainMenu *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *MovieSafe; // rsi
  UFG::OnlineManagerObserver *v4; // rdi
  UFG::OnlineManager *v5; // rax
  UFG::OSuiteManagerObserver *v6; // rdi
  UFG::OSuiteManager *v7; // rax
  unsigned int v8; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v10; // rdx
  __int64 v11; // rdi
  int v12; // edx
  _BOOL8 v13; // rcx
  int v14; // r8d
  char v15; // al
  int v16; // edx
  hkGeometryUtils::IVertices *v17; // rcx
  int v18; // r8d
  UFG::OnlineManager *v19; // rax
  UFG::OnlineManager *v20; // rax
  UFG::OnlineManager *v21; // rax
  UFG::OnlineManager *v22; // rax
  UFG::OSuiteManager *v23; // rax
  UFG::GameSaveLoad *v24; // rax
  UFG::GameSaveLoad *v25; // rax
  UFG::GameSaveLoad *v26; // rax
  hkgpIndexedMeshDefinitions::Edge *v27; // rdx
  hkgpIndexedMesh::EdgeBarrier *v28; // rcx
  __int64 v29[2]; // [rsp+50h] [rbp-B8h] BYREF
  UFG::qString v30; // [rsp+60h] [rbp-A8h] BYREF
  UFG::qString v31; // [rsp+88h] [rbp-80h] BYREF
  UFG::qString v32; // [rsp+B0h] [rbp-58h] BYREF
  UFG::qArray<unsigned long,0> flowId; // [rsp+110h] [rbp+8h] BYREF
  __int64 v34; // [rsp+120h] [rbp+18h]
  __int64 v35; // [rsp+128h] [rbp+20h]

  UFG::UIScreen::init(this, data);
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  v4 = &this->UFG::OnlineManagerObserver;
  if ( !this )
    v4 = 0i64;
  v5 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v5, v4);
  v6 = &this->UFG::OSuiteManagerObserver;
  if ( !this )
    v6 = 0i64;
  v7 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::RegisterObserver(v7, v6);
  v29[0] = (__int64)&UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::qString(&v30);
  UFG::qString::qString(&v31);
  v29[1] = (__int64)this;
  UFG::qString::Set(&v31, "MainMenu");
  UFG::qString::Set(&v30, "UI-MainMenu");
  (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, __int64 *))this->mMenu.vfptr->gap8)(&this->mMenu, v29);
  v8 = UFG::qStringHashUpper32("PAUSE_CONTINUE_GAME", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v10 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v8)) == 0i64 )
    v10 = "PAUSE_CONTINUE_GAME";
  this->mMenu.vfptr->setItemEnabled(&this->mMenu, v10, 0);
  this->mContinueEnabled = 1;
  v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          32i64);
  v34 = v11;
  if ( v11 )
  {
    *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v11 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v11 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
    *(_QWORD *)v11 = &Scaleform::GFx::State::`vftable;
    *(_DWORD *)(v11 + 16) = 3;
    *(_QWORD *)v11 = &Scaleform::GFx::ActionControl::`vftable;
    *(_DWORD *)(v11 + 24) = 8;
  }
  else
  {
    v11 = 0i64;
  }
  v35 = v11;
  *(_DWORD *)(v11 + 24) |= 2u;
  MovieSafe->Scaleform::GFx::StateBag::vfptr->SetState(
    &MovieSafe->Scaleform::GFx::StateBag,
    State_Filter,
    (Scaleform::GFx::State *)v11);
  UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  this->mState = STATE_BRIGHTNESS;
  if ( UFG::UIHKScreenMainMenu::mBinkEnabled )
    UFG::MoviePlayer::Init(&this->HKUIMovie, UFG::UIHKScreenMainMenu::gLoopMovieFile, 0i64, 0x24u);
  if ( UFG::UI::gHandleControllerDisconnectHack )
  {
    v15 = UFG::UIHKMessageOverlay::HandleControllerDisconnect();
    v13 = UFG::UI::gHandleControllerDisconnectHack;
    if ( v15 )
      v13 = 0i64;
    UFG::UI::gHandleControllerDisconnectHack = v13;
  }
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)v13, v12, v14) )
  {
    if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v17, v16, v18) )
    {
      v19 = UFG::OnlineManager::Instance();
      if ( !UFG::OnlineManager::IsNetworkSignedIn(v19) )
      {
        if ( !hasBeenWarned )
        {
          v20 = UFG::OnlineManager::Instance();
          UFG::OnlineManager::SignInNetwork(v20);
          v21 = UFG::OnlineManager::Instance();
          if ( !UFG::OnlineManager::IsNetworkSignedIn(v21) )
            UFG::UIScreenDialogBox::createOKDialog(0i64, &customCaption, "$COMMON_TRC_PC_CONNECTION_FAILED", 0);
          hasBeenWarned = 1;
        }
        this->mDisplaySocialHubWidget = 0;
      }
    }
    else if ( !UFG::UIHKScreenMainMenu::gNoOnlineAccountErrorInformed )
    {
      UFG::UIScreenManagerBase::queueMessage(
        UFG::UIScreenManager::s_instance,
        UI_HASH_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT_9,
        0xFFFFFFFF);
      UFG::UIHKScreenMainMenu::gNoOnlineAccountErrorInformed = 1;
    }
  }
  v22 = UFG::OnlineManager::Instance();
  if ( UFG::OnlineManager::IsNetworkSignedIn(v22) )
  {
    v23 = UFG::OSuiteManager::Instance();
    UFG::OSuiteManager::Connect(v23);
  }
  this->mFlowList[0].mUID = UFG::mainFlow.mUID;
  this->mFlowList[1].mUID = UFG::ghostFlow.mUID;
  this->mFlowList[2].mUID = UFG::cnyFlow.mUID;
  this->mState = NUM_CALIBRATION_STATES;
  flowId.size = this->mFlowList[this->mCurrentFlowToCheck].mUID;
  v24 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v24);
  v25 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SetActiveFlow(v25, &flowId);
  v26 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v26);
  UFG::UIHKScreenMainMenu::PopulateSocialHubWidget(this);
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v28, v27) )
  {
    _(0i64);
    UFG::qString::qString(&v32, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customCaption,
      "$KICKED_BACK_FROM_STREAMING_INSTALLER",
      v32.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v32);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  v29[0] = (__int64)&UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::~qString(&v31);
  UFG::qString::~qString(&v30);
}

// File Line: 361
// RVA: 0x5F23B0
void __fastcall UFG::UIHKScreenMainMenu::NetworkSignedIn(UFG::UIHKScreenMainMenu *this)
{
  if ( UFG::OSuiteTickerManager::Instance()->m_tickerType )
  {
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_QWORD *)&this[-1].HKUIMovie.mTargetTexture.mNameUID + 320i64),
      "MainMenu_HideTickerInfo",
      0i64,
      0i64,
      0);
    this->m_screenName[24] = 0;
  }
}

// File Line: 404
// RVA: 0x5F28E0
void __fastcall UFG::UIHKScreenMainMenu::OSuiteManagerDisconnected(UFG::UIHKScreenMainMenu *this)
{
  UFG::OnlineManager *v2; // rax
  Scaleform::GFx::Movie *MovieSafe; // rbx
  const char *v4; // rdi
  char *mData; // rbx
  UFG::qString v6; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+70h] [rbp-38h] BYREF

  v2 = UFG::OnlineManager::Instance();
  if ( UFG::OnlineManager::IsNetworkSignedIn(v2) && !UFG::UIHKScreenMainMenu::gOSuiteOfflineMessageInformed )
  {
    MovieSafe = UFG::UIScreen::getMovieSafe((UFG::UIHKScreenMainMenu *)((char *)this - 168));
    UFG::qString::qString(&v6, "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW");
    if ( MovieSafe )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Undefined;
      v4 = UFG::UI::LocalizeText(v6.mData);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_String;
      pargs.mValue.pString = v4;
      Scaleform::GFx::Movie::Invoke(MovieSafe, "SetSocialHubMessage", 0i64, &pargs, 1u);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Undefined;
    }
    mData = v6.mData;
    UFG::qString::qString((UFG::qString *)&pargs, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customCaption,
      mData,
      *(const char **)&pargs.Type,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString((UFG::qString *)&pargs);
    UFG::UIHKScreenMainMenu::gOSuiteOfflineMessageInformed = 1;
    UFG::qString::~qString(&v6);
  }
}

// File Line: 466
// RVA: 0x5D4EE0
UFG::qString *__fastcall UFG::UIHKScreenMainMenu::ChooseSaveGameSetupFromFlow(
        UFG::UIHKScreenMainMenu *this,
        UFG::qString *result,
        _DWORD *flow)
{
  const char *v5; // rdx

  UFG::qString::qString(result);
  if ( *flow == UFG::ghostFlow.mUID )
  {
    v5 = "gameSetupGameGhost_SaveGame";
  }
  else
  {
    v5 = "gameSetupGameCNY_SaveGame";
    if ( *flow != UFG::cnyFlow.mUID )
      v5 = "gameSetupGame_SaveGame";
  }
  UFG::qString::Set(result, v5);
  return result;
}

// File Line: 488
// RVA: 0x63DD90
void __fastcall UFG::UIHKScreenMainMenu::update(UFG::UIHKScreenMainMenu *this, float elapsed)
{
  UFG::OSuiteTickerManager *v3; // rax
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  UFG::OSuiteTickerManager *v5; // rax
  UFG::GameSaveLoad *v6; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **TopScreen; // rax
  UFG::GameSaveLoad *v8; // rax
  UFG::GameSaveLoad *v9; // rax
  UFG::GameSaveLoad::eGameSlotNum ContinueGameSlot; // ebx
  UFG::GameSaveLoad *v11; // rax
  UFG::ProgressionTracker *v12; // rax
  UFG::qSymbol *ActiveFlow; // rax
  UFG::qPropertySet *DLCPropertyNode; // rsi
  UFG::qWiseSymbol *v15; // rax
  bool v16; // bl
  UFG::qArray<unsigned long,0> *v17; // rax
  UFG::qWiseSymbol *v18; // rax
  unsigned int mUID; // ecx
  UFG::UIScreenTextureManager *v20; // rax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol v22; // [rsp+70h] [rbp+18h] BYREF

  if ( this->mInactivityTimer > 2.0 && !UFG::OSuiteTickerManager::Instance()->m_downloadActive )
  {
    v3 = UFG::OSuiteTickerManager::Instance();
    if ( !UFG::OSuiteTickerManager::IsTickerAvailable(v3, v4) )
    {
      v5 = UFG::OSuiteTickerManager::Instance();
      UFG::OSuiteTickerManager::DownloadTicker(v5);
      Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "MainMenu_HideTickerInfo", 0i64, 0i64, 0);
    }
  }
  if ( this->mCurrentFlowToCheck < 3 )
  {
    v6 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::IsLoadAvaliable(v6) && !this->mIsHeaderLoadStarted )
    {
      UFG::UIHKScreenMainMenu::CheckAllHeadersForCurrentFlow(this);
      this->mIsHeaderLoadStarted = 1;
    }
  }
  if ( this->mState == STATE_BRIGHTNESS )
  {
    if ( !UFG::UIHKScreenSplash::smMusicPlaying )
    {
      v12 = UFG::ProgressionTracker::Instance();
      ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v12);
      DLCPropertyNode = UFG::UI::GetDLCPropertyNode("UI-DLCSkins", "AudioProperties", "DLC", ActiveFlow);
      v15 = UFG::qWiseSymbol::create_from_string(&result, "mus_music");
      v16 = UFG::TiDo::BankLoaded(v15->mUID);
      _((AMD_HD3D *)result.mUID);
      if ( v16 )
      {
        if ( DLCPropertyNode
          && (v17 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v22, "play_mus_fe_lic"),
              (v18 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(DLCPropertyNode, v17, DEPTH_RECURSE)) != 0i64) )
        {
          mUID = v18->mUID;
        }
        else
        {
          if ( (_S11_10 & 1) == 0 )
          {
            _S11_10 |= 1u;
            play_mus_fe_lic.mUID = UFG::qWiseSymbolUIDFromString("play_mus_fe_lic", 0x811C9DC5);
            _((AMD_HD3D *)play_mus_fe_lic.mUID);
            atexit(UFG::UIHKScreenMainMenu::update_::_28_::_dynamic_atexit_destructor_for__play_mus_fe_lic__);
          }
          mUID = play_mus_fe_lic.mUID;
        }
        UFG::Music::MusicEvent(mUID);
        UFG::StreamFileWrapper::EnableIncrementalMode(1);
        UFG::UIHKScreenSplash::smMusicPlaying = 1;
      }
    }
    if ( UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
      this->mInactivityTimer = elapsed + this->mInactivityTimer;
    if ( this->mInactivityTimer > 60.0 )
    {
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      UFG::UIHKScreenSplash::mUseAttractMode = 1;
      v20 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v20, "Splash", 0i64);
    }
  }
  else if ( this->mState == STATE_VOLUME )
  {
    v8 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::IsLoadAvaliable(v8) )
    {
      v9 = UFG::GameSaveLoad::Instance();
      ContinueGameSlot = (unsigned int)UFG::GameSaveLoad::GetContinueGameSlot(v9);
      v11 = UFG::GameSaveLoad::Instance();
      if ( UFG::GameSaveLoad::LoadGameSlot(v11, ContinueGameSlot) )
        this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
    }
  }
  else if ( this->mState == 8
         && !UFG::UIScreenManagerBase::areScreensPending(UFG::UIScreenManager::s_instance)
         && !UFG::UIScreenManagerBase::areOverlaysPending(UFG::UIScreenManager::s_instance) )
  {
    TopScreen = UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance);
    if ( TopScreen )
    {
      if ( *((_DWORD *)TopScreen + 28) != this->mScreenUID )
        this->mState = STATE_BRIGHTNESS;
    }
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 626
// RVA: 0x624970
bool __fastcall UFG::UIHKScreenMainMenu::handleMessage(
        UFG::UIHKScreenMainMenu *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  hkGeometryUtils::IVertices *v6; // rcx
  Scaleform::GFx::Movie *MovieSafe; // rdi
  int v8; // r8d
  UFG::OnlineManager *v9; // rax
  char *mData; // rbx
  double mCurrentDisplayImageSlot; // xmm6_8
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v14; // rax
  UFG::OnlineManager *v15; // r8
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v16; // rcx
  unsigned __int64 v17; // rdx
  UFG::UIScreenTextureManager *v18; // rax
  const char *v19; // rdx
  UFG::GameSaveLoad *v20; // rax
  UFG::GameSaveLoad *v21; // rax
  UFG::ProgressionTracker *v22; // rax
  UFG::qStaticSymbol *v23; // rdx
  UFG::GameSaveLoad *v24; // rax
  UFG::GameSaveLoad *v25; // rax
  UFG::GameSaveLoad *v26; // rax
  UFG::GameSaveLoad *v27; // rax
  bool IsLaunchHeader; // al
  const char *v29; // rbx
  UFG::UIScreenTextureManager *v30; // rax
  UFG::UIScreenTextureManager *v31; // rax
  UFG::OSuiteTickerManager *v32; // rax
  UFG::OSuiteTickerManager *v33; // rax
  UFG::OSuiteTickerManager *v34; // rax
  UFG::GameSaveLoad *v35; // rax
  UFG::GameSaveLoad *v36; // rax
  UFG::ProgressionTracker *v37; // rax
  UFG::GameSaveLoad *v38; // rax
  UFG::GameSaveLoad *v39; // rax
  UFG::ProgressionTracker *v40; // rax
  UFG::GameSaveLoad *v41; // rax
  UFG::GameSaveLoad *v42; // rax
  UFG::ProgressionTracker *v43; // rax
  UFG::GameSaveLoad *v44; // rax
  UFG::GameSaveLoad *v45; // rax
  __int64 v46; // rbx
  UFG::GameSaveLoad *v47; // rax
  UFG::GameSaveLoad *v48; // rax
  UFG::GameSaveLoad *v49; // rax
  UFG::ProgressionTracker *v50; // rax
  UFG::qStaticSymbol *p_mFlowForContinue; // rdx
  UFG::GameSaveLoad *v52; // rax
  UFG::GameSaveLoad *v53; // rax
  UFG::GameSaveLoad *v54; // rax
  UFG::GameSaveLoad *v55; // rax
  UFG::GameSaveLoad *v56; // rax
  UFG::UIScreenTextureManager *v57; // rax
  UFG::qSymbol *v58; // rbx
  UFG::qSymbol *v59; // rbx
  unsigned int mUID; // eax
  UFG::GameSaveLoad *v61; // rax
  UFG::UIPropertySetMenuVtbl *vfptr; // rdi
  const char *v63; // rax
  UFG::GameSaveLoad *v64; // rax
  __int64 ContinueGameSlot; // rbx
  UFG::GameSaveLoad *v66; // rax
  __int128 v67; // xmm6
  __int128 v68; // xmm7
  __int128 v69; // xmm8
  __int128 v70; // xmm9
  __int128 v71; // xmm10
  hkGeometryUtils::IVertices *v72; // rcx
  int v73; // r8d
  UFG::GameSaveLoad *v74; // rax
  __int64 v75[2]; // [rsp+30h] [rbp-98h] BYREF
  unsigned __int64 v76; // [rsp+40h] [rbp-88h]
  char v77[8]; // [rsp+48h] [rbp-80h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+50h] [rbp-78h] BYREF
  __int64 v79; // [rsp+80h] [rbp-48h]
  char dest[32]; // [rsp+88h] [rbp-40h] BYREF
  UFG::GameSaveLoad::tsSaveGameHeaderInfo v81; // [rsp+A8h] [rbp-20h] BYREF
  UFG::GameSaveLoad::tsSaveGameHeaderInfo v82; // [rsp+F8h] [rbp+30h] BYREF
  UFG::qString result; // [rsp+148h] [rbp+80h] BYREF
  UFG::qSymbol v84[2]; // [rsp+208h] [rbp+140h] BYREF
  UFG::qSymbol flow; // [rsp+210h] [rbp+148h] BYREF
  UFG::qSymbol v86; // [rsp+220h] [rbp+158h] BYREF

  v79 = -2i64;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( msgId == UI_HASH_DISPLAY_IMAGE_LOADED_20 )
  {
    v9 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetRetreivedDisplayImage(v9, &result);
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = result.mData;
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
    mCurrentDisplayImageSlot = (double)this->mCurrentDisplayImageSlot;
    if ( ((__int64)ptr.pObjectInterface & 0x40) != 0 )
    {
      ((void (__fastcall *)(Scaleform::GFx::Value *, char *, _QWORD))ptr.pNext->Scaleform::ListNode<Scaleform::GFx::Value>::$41EDDC8CC4664C9FE26D4D23F9ACAEE4::pPrev->pObjectInterface)(
        ptr.pNext,
        v77,
        *(_QWORD *)&ptr.Type);
      ptr.pNext = 0i64;
    }
    LODWORD(ptr.pObjectInterface) = 5;
    *(double *)&ptr.Type = mCurrentDisplayImageSlot;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "SetSocialHubSlotPlayerDisplayImage", 0i64, &ptr, 2u);
    mNext = this->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
    mPrev = mNext->mPrev;
    v14 = mNext->mNext;
    mPrev->mNext = v14;
    v14->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    if ( (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)this->mOnlineIdsToGetDisplayImageFor.mNode.mNext != &this->mOnlineIdsToGetDisplayImageFor )
    {
      ++this->mCurrentDisplayImageSlot;
      *(_QWORD *)&v84[0].mUID = v75;
      v15 = UFG::OnlineManager::Instance();
      v16 = this->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
      v75[0] = (__int64)v75;
      v75[1] = (__int64)v75;
      v76 = __PAIR64__(HIDWORD(v76), 0) & 0xFF0FFFFF00000000ui64;
      HIBYTE(v76) = 0;
      HIDWORD(v76) &= 0xFFF00000;
      v76 = (unsigned __int64)v16[1].mPrev;
      ((void (__fastcall *)(UFG::OnlineManager *, __int64 *))v15->vfptr->RetreivePlayerDisplayImage)(v15, v75);
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&result);
  }
  v17 = 0x140000000ui64;
  switch ( this->mState )
  {
    case 0:
    case 2:
    case 5:
    case 8:
    case 0xA:
      if ( msgId != -339696135 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      v64 = UFG::GameSaveLoad::Instance();
      ContinueGameSlot = (int)UFG::GameSaveLoad::GetContinueGameSlot(v64);
      v66 = UFG::GameSaveLoad::Instance();
      v67 = *(_OWORD *)&v66->m_GameSlotHeaderInfo[ContinueGameSlot].m_State;
      v68 = *(_OWORD *)v66->m_GameSlotHeaderInfo[ContinueGameSlot].m_szLastMissionStringID;
      v69 = *(_OWORD *)&v66->m_GameSlotHeaderInfo[ContinueGameSlot].m_szLastMissionStringID[16];
      v70 = *(_OWORD *)&v66->m_GameSlotHeaderInfo[ContinueGameSlot].m_szLastMissionStringID[32];
      v71 = *(_OWORD *)&v66->m_GameSlotHeaderInfo[ContinueGameSlot].m_szLastMissionStringID[48];
      if ( !Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v72, 10 * ContinueGameSlot, v73) )
      {
        *(_OWORD *)&v81.m_State = v67;
        *(_OWORD *)v81.m_szLastMissionStringID = v68;
        *(_OWORD *)&v81.m_szLastMissionStringID[16] = v69;
        *(_OWORD *)&v81.m_szLastMissionStringID[32] = v70;
        *(_OWORD *)&v81.m_szLastMissionStringID[48] = v71;
        v74 = UFG::GameSaveLoad::Instance();
        if ( !UFG::GameSaveLoad::IsLaunchHeader(v74, &v81) && this->mContinueEnabled )
        {
          UFG::UIPropertySetMenu::setSelectedMenuIndex(&this->mMenu, this, 1);
          Scaleform::GFx::Movie::Invoke(MovieSafe, "MainMenu_Refresh", 0i64, 0i64, 0);
        }
      }
      UFG::UIHKScreenMainMenu::SetFlowImage(this);
      goto LABEL_117;
    case 1:
      if ( this->mMenu.mState > (unsigned int)STATE_BRIGHTNESS )
        goto LABEL_82;
      if ( msgId == UI_HASH_SCREEN_PUSH_20 )
      {
        UFG::qMemSet(dest, 0, 0x20u);
        if ( this->mMenu.mOpDependant.mLength )
          UFG::qMemCopy(dest, this->mMenu.mOpDependant.mData, 0x1Fu);
        this->mState = 8;
        v18 = UFG::UIScreenTextureManager::Instance();
        v19 = dest;
      }
      else
      {
        if ( msgId == UI_HASH_FLOW_MAIN_STORY_20 )
        {
          v20 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v20);
          v21 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SetActiveFlow(v21, (UFG::qArray<unsigned long,0> *)&UFG::mainFlow);
          v22 = UFG::ProgressionTracker::Instance();
          v23 = &UFG::mainFlow;
        }
        else if ( msgId == UI_HASH_FLOW_GHOST_20 )
        {
          v24 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v24);
          v25 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SetActiveFlow(v25, (UFG::qArray<unsigned long,0> *)&UFG::ghostFlow);
          v22 = UFG::ProgressionTracker::Instance();
          v23 = &UFG::ghostFlow;
        }
        else
        {
          if ( msgId != UI_HASH_FLOW_CNY_20 )
            goto LABEL_25;
          v26 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v26);
          v27 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SetActiveFlow(v27, (UFG::qArray<unsigned long,0> *)&UFG::cnyFlow);
          v22 = UFG::ProgressionTracker::Instance();
          v23 = &UFG::cnyFlow;
        }
        UFG::ProgressionTracker::SetActiveFlow(v22, (UFG::qArray<unsigned long,0> *)v23);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
        v18 = UFG::UIScreenTextureManager::Instance();
        v19 = "StartFlowScreen";
      }
      UFG::UIScreenTextureManager::QueueLoadAndPush(v18, v19, 0i64);
LABEL_25:
      if ( msgId == UI_HASH_LOAD_FREEROAM_20 )
      {
        UFG::UIHKScreenMainMenu::CheckAutosaveOverwrite(this);
        return 1;
      }
      if ( msgId == UI_HASH_RUNTEST_RELOAD_20 || msgId == UI_HASH_RUNTEST_ASIS_20 )
      {
        UFG::UIHKScreenMainMenu::CheckAutosaveOverwrite(this);
        v58 = UFG::qSymbol::create_from_string(v84, this->mMenu.mScriptFunc.mData);
        UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioScriptName = (UFG::qSymbol)v58->mUID;
        v59 = UFG::qSymbol::create_from_string(&v86, this->mMenu.mOpDependant.mData);
        UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioParameter = (UFG::qSymbol)v59->mUID;
        return 1;
      }
      if ( msgId == UI_HASH_CONTROLLERS_20 )
      {
        this->mState = 8;
        v29 = "Options_Controllers";
        if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
          v29 = "Options_ButtonMapping";
        v30 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v30, v29, 0i64);
      }
      else if ( msgId == UI_HASH_CREDITS_20 )
      {
        this->mState = 8;
        v31 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v31, "Credits", 0i64);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
        UFG::UIScreenCredits::smTriggeredFromMainMenu = 1;
        return 1;
      }
      if ( msgId == UI_HASH_LOAD_SAVEGAME_20 )
      {
        this->mIsTransitionToGame = 1;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x214376EEu, 0i64, 0, 0i64);
        this->mIsLoadingSaveGame = 1;
        return 1;
      }
      if ( msgId == UI_HASH_LOAD_OFFLINEINFOCAST_20 && this->mInfoTickerSet )
      {
        UFG::OSuiteTickerManager::Instance()->m_tickerType = TICKER_OFFLINE;
        v32 = UFG::OSuiteTickerManager::Instance();
        UFG::OSuiteTickerManager::DownloadTicker(v32);
        UFG::UIHKScreenMainMenu::HideInfoTicker(this);
        this->mInfoTickerSet = 0;
      }
      if ( msgId == UI_HASH_LOAD_STAGINGINFOCAST_20 && this->mInfoTickerSet )
      {
        UFG::OSuiteTickerManager::Instance()->m_tickerType = TICKER_STAGING;
        v33 = UFG::OSuiteTickerManager::Instance();
        UFG::OSuiteTickerManager::DownloadTicker(v33);
        UFG::UIHKScreenMainMenu::HideInfoTicker(this);
        this->mInfoTickerSet = 0;
      }
      if ( msgId == UI_HASH_LOAD_ACTIVEINFOCAST_20 && this->mInfoTickerSet )
      {
        UFG::OSuiteTickerManager::Instance()->m_tickerType = TICKER_ACTIVE;
        v34 = UFG::OSuiteTickerManager::Instance();
        UFG::OSuiteTickerManager::DownloadTicker(v34);
        UFG::UIHKScreenMainMenu::HideInfoTicker(this);
        this->mInfoTickerSet = 0;
      }
      if ( msgId == UI_HASH_GAME_RESUME_20 )
      {
LABEL_52:
        UFG::UIHKScreenMainMenu::PlayOutro(this);
        return 1;
      }
      if ( msgId == UI_HASH_MEMCARD_SAVE_20 )
      {
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(this, 1, 0);
        return 1;
      }
      if ( msgId == UI_HASH_MEMCARD_LOAD_20 )
      {
        v35 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v35);
        v36 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v36, (UFG::qArray<unsigned long,0> *)&UFG::mainFlow);
        v37 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::SetActiveFlow(v37, (UFG::qArray<unsigned long,0> *)&UFG::mainFlow);
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(this, 0, 0);
        return 1;
      }
      if ( msgId == UI_HASH_MEMCARD_LOAD_GHOST_20 )
      {
        v38 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v38);
        v39 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v39, (UFG::qArray<unsigned long,0> *)&UFG::ghostFlow);
        v40 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::SetActiveFlow(v40, (UFG::qArray<unsigned long,0> *)&UFG::ghostFlow);
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(this, 0, 0);
        return 1;
      }
      if ( msgId == UI_HASH_MEMCARD_LOAD_CNY_20 )
      {
        v41 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v41);
        v42 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v42, (UFG::qArray<unsigned long,0> *)&UFG::cnyFlow);
        v43 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::SetActiveFlow(v43, (UFG::qArray<unsigned long,0> *)&UFG::cnyFlow);
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(this, 0, 0);
        return 1;
      }
      if ( msgId == UI_HASH_MEMCARD_CONTINUE_20 )
      {
        if ( !Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v6, v17, v8) )
        {
          v44 = UFG::GameSaveLoad::Instance();
          if ( (unsigned int)UFG::GameSaveLoad::GetContinueGameSlot(v44) != -1 )
          {
            v45 = UFG::GameSaveLoad::Instance();
            v46 = (int)UFG::GameSaveLoad::GetContinueGameSlot(v45);
            v82 = UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[v46];
            v47 = UFG::GameSaveLoad::Instance();
            IsLaunchHeader = UFG::GameSaveLoad::IsLaunchHeader(v47, &v82);
            if ( !IsLaunchHeader )
              return IsLaunchHeader;
          }
        }
        this->mIsTransitionToGame = 1;
        v48 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v48);
        v49 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v49, (UFG::qArray<unsigned long,0> *)&this->mFlowForContinue);
        v50 = UFG::ProgressionTracker::Instance();
        p_mFlowForContinue = (UFG::qStaticSymbol *)&this->mFlowForContinue;
        goto LABEL_70;
      }
      if ( msgId == UI_HASH_MEMCARD_CONTINUE_GHOST_20 )
      {
        this->mIsTransitionToGame = 1;
        v52 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v52);
        v53 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v53, (UFG::qArray<unsigned long,0> *)&UFG::ghostFlow);
        v50 = UFG::ProgressionTracker::Instance();
        p_mFlowForContinue = &UFG::ghostFlow;
LABEL_70:
        UFG::ProgressionTracker::SetActiveFlow(v50, (UFG::qArray<unsigned long,0> *)p_mFlowForContinue);
        v56 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::LoadAllHeaders(v56);
        this->mIsContinue = 1;
        this->mState = STATE_UISCALE;
        goto LABEL_82;
      }
      if ( msgId == UI_HASH_MEMCARD_CONTINUE_CNY_20 )
      {
        this->mIsTransitionToGame = 1;
        v54 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v54);
        v55 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v55, (UFG::qArray<unsigned long,0> *)&UFG::cnyFlow);
        v50 = UFG::ProgressionTracker::Instance();
        p_mFlowForContinue = &UFG::cnyFlow;
        goto LABEL_70;
      }
      if ( msgId == UI_HASH_SAVE_COMPLETE_20 )
        return 1;
      if ( msgId == UI_HASH_LOAD_COMPLETE_20 )
        goto LABEL_52;
      if ( msgId == UI_HASH_DEBUG_LANGUAGE_LIST_20 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
        UFG::UIHKScreenDebugLanguageList::gReturnToMainMenu = 1;
        this->mState = 8;
        v57 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v57, "DebugLanguageList", 0i64);
        return 1;
      }
      if ( msgId == UI_HASH_EXIT_20 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
        UFG::UIScreenDialogBox::createYesNoDialog(0i64, "QUIT_GAME_PROMPT", "$QUIT_GAME_DIALOG_MESSAGE", 0, 0);
        this->mState = STATE_UISCALE|0x8;
        return 1;
      }
      if ( msgId == UI_HASH_SELECTED_ITEM_CHANGED_20 )
        UFG::UIHKScreenMainMenu::SetFlowImage(this);
LABEL_82:
      if ( !(*(unsigned __int8 (__fastcall **)(UFG::UIPropertySetMenuMainNav *, _QWORD, UFG::UIMessage *))&this->mMenu.vfptr->gap8[8])(
              &this->mMenu,
              msgId,
              msg) )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      this->mInactivityTimer = 0.0;
      if ( msgId != UI_HASH_DPAD_DOWN_PRESSED_30
        && msgId != UI_HASH_DPAD_DOWN_REPEAT_30
        && msgId != UI_HASH_THUMBSTICK_LEFT_DOWN_30
        && msgId != UI_HASH_DPAD_UP_PRESSED_30
        && msgId != UI_HASH_DPAD_UP_REPEAT_30
        && msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        return 1;
      }
      UFG::UIHKScreenMainMenu::SetFlowImage(this);
      return 1;
    case 3:
      if ( msgId == 0xEBC0A5F9 )
      {
        v61 = UFG::GameSaveLoad::Instance();
        if ( (unsigned int)UFG::GameSaveLoad::GetContinueGameSlot(v61) == -1 )
        {
          vfptr = this->mMenu.vfptr;
          v63 = UFG::UI::LocalizeText("$PAUSE_CONTINUE_GAME");
          vfptr->setItemEnabled(&this->mMenu, v63, 0);
          UFG::UIScreenManagerBase::queueMessage(
            UFG::UIScreenManager::s_instance,
            UI_HASH_LOAD_OPERATION_INVALID_DEVICE_9,
            0xFFFFFFFF);
        }
        else
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x214376EEu, 0i64, 0, 0i64);
          UFG::UIScreenDialogBox::createZeroButtonDialog(this, &customCaption, "$COMMON_LOADING", 0, "DialogBox");
          this->mState = STATE_VOLUME;
        }
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 4:
      if ( msgId == -339696135 )
      {
        mUID = this->mFlowList[this->mCurrentFlowToCheck].mUID;
        ptr.DataAux = (unsigned __int64)&flow;
        flow.mUID = mUID;
        UFG::UIHKScreenMainMenu::FillHeaderInfoForFlow(this, &flow.mUID);
        if ( ++this->mCurrentFlowToCheck >= 3 )
          UFG::UIHKScreenMainMenu::DetermineFlowForContinue(this);
        else
          UFG::UIHKScreenMainMenu::CheckAllHeadersForCurrentFlow(this);
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 6:
      if ( msgId == 1552074461 )
        goto LABEL_52;
      if ( msgId != 1323471633 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      this->mState = STATE_BRIGHTNESS;
      return 1;
    case 7:
      if ( msgId != UI_HASH_DIALOG_YES_30 )
        goto LABEL_92;
      UFG::UIHKScreenMainMenu::PlayOutro(this);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 9:
      if ( msgId != UI_HASH_OUTRO_COMPLETE_30 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      UFG::MoviePlayer::Close(&this->HKUIMovie);
      UFG::UIHKScreenMainMenu::EnterGame(this);
      this->mState = 10;
      return 1;
    case 0xB:
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        gGameQuitEvent = 1;
        this->mState = 10;
      }
      else
      {
LABEL_92:
        if ( msgId == UI_HASH_DIALOG_NO_30 )
LABEL_117:
          this->mState = STATE_BRIGHTNESS;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    default:
      return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
}

// File Line: 1098
// RVA: 0x5D4D50
void __fastcall UFG::UIHKScreenMainMenu::CheckAutosaveOverwrite(UFG::UIHKScreenMainMenu *this)
{
  UFG::qString option2Text; // [rsp+58h] [rbp-60h] BYREF
  UFG::qString v3; // [rsp+80h] [rbp-38h] BYREF

  if ( UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[4].m_State == SAVE_GAME_HEADER_STATE_VALID )
  {
    if ( UFG::TiDo::GetIsInstantiated() )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
    }
    UFG::qString::qString(&v3, "$OPTIONS_YES");
    UFG::qString::qString(&option2Text, "$OPTIONS_NO");
    UFG::UIScreenDialogBox::createTwoButtonDialog(
      0i64,
      "OverwriteAutosave",
      "$COMMON_TRC_OVERWRITE_AUTOSAVE",
      v3.mData,
      UI_HASH_DIALOG_YES_30,
      option2Text.mData,
      UI_HASH_DIALOG_NO_30,
      DIALOG_BUTTON2,
      0,
      "DialogBox");
    UFG::qString::~qString(&option2Text);
    UFG::qString::~qString(&v3);
    this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
  }
  else
  {
    this->mIsTransitionToGame = 1;
    UFG::UIScreenDialogBox::createZeroButtonDialog(this, &customCaption, "$LOADING_POPUP", 0, "DialogBox");
    this->UFG::UIScreen::vfptr->outro(this, 0i64);
    if ( !UFG::UIHKScreenMainMenu::mBinkEnabled )
      UFG::UIHKScreenMainMenu::EnterGame(this);
    this->mState = 9;
    if ( UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x214376EEu, 0i64, 0, 0i64);
  }
}

// File Line: 1153
// RVA: 0x5ED080
void __fastcall UFG::UIHKScreenMainMenu::HideInfoTicker(UFG::UIHKScreenMainMenu *this)
{
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "MainMenu_HideTickerInfo", 0i64, 0i64, 0);
}

// File Line: 1159
// RVA: 0x5F4030
void __fastcall UFG::UIHKScreenMainMenu::PlayOutro(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIScreenDialogBox::createZeroButtonDialog(this, &customCaption, "$LOADING_POPUP", 0, "DialogBox");
  this->UFG::UIScreen::vfptr->outro(this, 0i64);
  if ( !UFG::UIHKScreenMainMenu::mBinkEnabled )
    UFG::UIHKScreenMainMenu::EnterGame(this);
  this->mState = 9;
}

// File Line: 1180
// RVA: 0x5D7210
void __fastcall UFG::UIHKScreenMainMenu::EnterGame(UFG::UIHKScreenMainMenu *this)
{
  UFG::UI *v2; // rcx
  UFG::qSymbol *p_mFlowForContinue; // rdi
  UFG::ProgressionTracker *v4; // rax
  UFG::TimeOfDayManager *Instance; // rsi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qColour *v8; // rcx
  UFG::TimeOfDayManager *v9; // rsi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  unsigned int v12; // esi
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  UFG::GameState *GameStateObj; // rax
  int lengthb[4]; // [rsp+20h] [rbp-21h] BYREF
  UFG::qString v17; // [rsp+30h] [rbp-11h] BYREF
  UFG::qString result; // [rsp+58h] [rbp+17h] BYREF
  UFG::qSymbol flow; // [rsp+A8h] [rbp+67h] BYREF
  UFG::qSymbol *p_flow; // [rsp+B0h] [rbp+6Fh]

  UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  UFG::UI::UnpauseGame(v2);
  p_mFlowForContinue = &this->mFlowForContinue;
  if ( !this->mIsContinue )
    p_mFlowForContinue = &this->mMenu.mProgressionFlow;
  this->mIsContinue = 0;
  v4 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetActiveFlow(v4, (UFG::qArray<unsigned long,0> *)p_mFlowForContinue);
  if ( p_mFlowForContinue->mUID == UFG::ghostFlow.mUID )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    Instance->m_OverrideStateBlockAmount = 1.0;
    Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&Instance->mOverrideStateBlockHandle, 0x4D04C7F2u, 0x349DF3BEu, Inventory);
    Render::SkyMarshall::gSkyMarshall.mDebugDomeIndex = 2;
    UFG::SetGlobalEffectUID(0xFA64CB1u);
    UFG::EnableAltColorEffect(1);
    *(float *)lengthb = FLOAT_0_23137255;
    *(float *)&lengthb[1] = FLOAT_0_56470591;
    *(float *)&lengthb[2] = FLOAT_0_82745099;
    lengthb[3] = (int)FLOAT_1_0;
    v8 = (UFG::qColour *)lengthb;
  }
  else
  {
    v9 = UFG::TimeOfDayManager::GetInstance();
    v9->m_OverrideStateBlockAmount = 0.0;
    v10 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v10;
    }
    UFG::qResourceHandle::Init(&v9->mOverrideStateBlockHandle, 0x4D04C7F2u, 0, v10);
    Render::SkyMarshall::gSkyMarshall.mDebugDomeIndex = -1;
    UFG::SetGlobalEffectUID(0);
    UFG::EnableAltColorEffect(0);
    v8 = &kMainSpinnerColour_1;
  }
  Render::SetLoadScreenSpinnerTint(v8);
  v12 = uidGameStateLoadGame_13;
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
  {
    UFG::qString::qString(&v17);
    if ( this->mIsLoadingSaveGame )
    {
      p_flow = &flow;
      flow.mUID = p_mFlowForContinue->mUID;
      v13 = UFG::UIHKScreenMainMenu::ChooseSaveGameSetupFromFlow(this, &result, &flow);
      UFG::qString::Set(&v17, v13->mData, v13->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      this->mIsLoadingSaveGame = 0;
    }
    else if ( this->mMenu.mGameSetup.mLength )
    {
      UFG::qString::Set(&v17, this->mMenu.mGameSetup.mData, this->mMenu.mGameSetup.mLength, 0i64, 0);
    }
    else if ( this->mMenu.mOpDependant.mLength )
    {
      UFG::qString::Set(&v17, this->mMenu.mOpDependant.mData, this->mMenu.mOpDependant.mLength, 0i64, 0);
    }
    else
    {
      p_flow = &flow;
      flow.mUID = p_mFlowForContinue->mUID;
      v14 = UFG::UIHKScreenMainMenu::ChooseSaveGameSetupFromFlow(this, &result, &flow);
      UFG::qString::Set(&v17, v14->mData, v14->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
    }
    GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v12);
    if ( GameStateObj )
      UFG::qString::Set(&GameStateObj->mGameStateUserDataStr, v17.mData);
    UFG::qString::~qString(&v17);
  }
}

// File Line: 1260
// RVA: 0x605D50
void __fastcall UFG::UIHKScreenMainMenu::SetFlowImage(UFG::UIHKScreenMainMenu *this)
{
  Scaleform::GFx::Movie *MovieSafe; // rax
  Scaleform::GFx::Movie *v3; // rdi
  int v4; // edx
  hkGeometryUtils::IVertices *v5; // rcx
  int v6; // r8d
  int NValue; // ebx
  int v8; // ebx
  int v9; // ebx
  const char *v10; // rdx
  unsigned int mUID; // eax
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h] BYREF

  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  v3 = MovieSafe;
  if ( MovieSafe )
  {
    presult.pObjectInterface = 0i64;
    presult.Type = VT_Undefined;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "MainMenu_GetSelectedIndex", &presult, 0i64, 0);
    NValue = (int)presult.mValue.NValue;
    if ( !this->mContinueEnabled && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v5, v4, v6) )
      ++NValue;
    if ( NValue )
    {
      v8 = NValue - 1;
      if ( v8 )
      {
        v9 = v8 - 1;
        if ( v9 )
        {
          if ( v9 != 1 )
          {
            v10 = "SetNoImage";
            goto LABEL_15;
          }
          goto LABEL_13;
        }
LABEL_11:
        v10 = "SetGhostFlowImage";
        goto LABEL_15;
      }
    }
    else
    {
      mUID = this->mFlowForContinue.mUID;
      if ( mUID == UFG::ghostFlow.mUID )
        goto LABEL_11;
      if ( mUID == UFG::cnyFlow.mUID )
      {
LABEL_13:
        v10 = "SetCNYFlowImage";
        goto LABEL_15;
      }
    }
    v10 = "SetMainStoryFlowImage";
LABEL_15:
    Scaleform::GFx::Movie::Invoke(v3, v10, 0i64, 0i64, 0);
    if ( (presult.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&presult.pObjectInterface->vfptr->gap8[8])(
        presult.pObjectInterface,
        &presult,
        presult.mValue);
  }
}

// File Line: 1320
// RVA: 0x5D4CF0
void __fastcall UFG::UIHKScreenMainMenu::CheckAllHeadersForCurrentFlow(UFG::UIHKScreenMainMenu *this)
{
  __int64 mCurrentFlowToCheck; // rax
  UFG::GameSaveLoad *v2; // rax
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v4; // rax
  UFG::qArray<unsigned long,0> flowId; // [rsp+30h] [rbp+8h] BYREF

  mCurrentFlowToCheck = this->mCurrentFlowToCheck;
  this->mState = NUM_CALIBRATION_STATES;
  flowId.size = this->mFlowList[mCurrentFlowToCheck].mUID;
  v2 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v2);
  v3 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SetActiveFlow(v3, &flowId);
  v4 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v4);
}

// File Line: 1331
// RVA: 0x5D8170
void __fastcall UFG::UIHKScreenMainMenu::FillHeaderInfoForFlow(UFG::UIHKScreenMainMenu *this, unsigned int *flow)
{
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::UIHKScreenMainMenu::HeaderInfo *v9; // rcx
  hkMemoryResourceContainer *v10; // rax
  int StartingPos; // eax
  __int64 v12; // rbp
  __int64 v13; // rsi
  __int64 v14; // r14
  unsigned int v15; // edx
  unsigned int v16; // r15d
  unsigned int v17; // ebx
  unsigned int v18; // edx
  UFG::UIHKScreenMainMenu::HeaderInfo *v19; // rcx
  __m128i v20; // [rsp+20h] [rbp-78h]
  __m128i v21; // [rsp+20h] [rbp-78h]

  v20 = *(__m128i *)&UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[4].m_State;
  if ( _mm_cvtsi128_si32(v20) == 5 )
  {
    size = this->mHeaderInfo.size;
    capacity = this->mHeaderInfo.capacity;
    v6 = *flow;
    v7 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v8 = 2 * capacity;
      else
        v8 = 1;
      for ( ; v8 < v7; v8 *= 2 )
        ;
      if ( v8 - v7 > 0x10000 )
        v8 = size + 65537;
      UFG::qArray<UFG::UIHKScreenMainMenu::HeaderInfo,0>::Reallocate(&this->mHeaderInfo, v8, "qArray.Add");
    }
    this->mHeaderInfo.size = v7;
    v9 = &this->mHeaderInfo.p[size];
    v9->headerTimeStamp = v20.m128i_u64[1];
    v9->flow.mUID = v6;
  }
  v10 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v10);
  v12 = StartingPos;
  if ( StartingPos > 0 )
  {
    v13 = 0i64;
    do
    {
      v21 = *(__m128i *)&UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[v13].m_State;
      if ( _mm_cvtsi128_si32(v21) == 5 )
      {
        v14 = this->mHeaderInfo.size;
        v15 = this->mHeaderInfo.capacity;
        v16 = *flow;
        v17 = v14 + 1;
        if ( (int)v14 + 1 > v15 )
        {
          if ( v15 )
            v18 = 2 * v15;
          else
            v18 = 1;
          for ( ; v18 < v17; v18 *= 2 )
            ;
          if ( v18 - v17 > 0x10000 )
            v18 = v14 + 65537;
          UFG::qArray<UFG::UIHKScreenMainMenu::HeaderInfo,0>::Reallocate(&this->mHeaderInfo, v18, "qArray.Add");
        }
        this->mHeaderInfo.size = v17;
        v19 = &this->mHeaderInfo.p[v14];
        v19->headerTimeStamp = v21.m128i_u64[1];
        v19->flow.mUID = v16;
      }
      ++v13;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 1359
// RVA: 0x5D6380
void __fastcall UFG::UIHKScreenMainMenu::DetermineFlowForContinue(UFG::UIHKScreenMainMenu *this)
{
  __int64 size; // rbx
  Scaleform::GFx::Movie *MovieSafe; // rsi
  unsigned int v4; // eax
  UFG::UIGfxTranslator *v5; // rcx
  const char *v6; // rdx
  unsigned __int64 headerTimeStamp; // rdx
  __int64 v8; // r9
  __int64 v9; // rcx
  UFG::UIHKScreenMainMenu::HeaderInfo *p; // rax
  UFG::GameSaveLoad *v11; // rax
  UFG::GameSaveLoad *v12; // rax
  UFG::GameSaveLoad *v13; // rax
  unsigned int v14; // eax
  _BOOL8 v15; // r8
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v17; // rdx

  size = this->mHeaderInfo.size;
  this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( (int)size > 0 )
  {
    headerTimeStamp = 0i64;
    v8 = size;
    v9 = 0i64;
    do
    {
      p = this->mHeaderInfo.p;
      if ( p[v9].headerTimeStamp > headerTimeStamp )
      {
        headerTimeStamp = p[v9].headerTimeStamp;
        this->mFlowForContinue.mUID = p[v9].flow.mUID;
      }
      ++v9;
      --v8;
    }
    while ( v8 );
    v11 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v11);
    v12 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::SetActiveFlow(v12, (UFG::qArray<unsigned long,0> *)&this->mFlowForContinue);
    v13 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadAllHeaders(v13);
    v14 = UFG::qStringHashUpper32("PAUSE_CONTINUE_GAME", -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v17 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v14)) == 0i64 )
      v17 = "PAUSE_CONTINUE_GAME";
    LOBYTE(v15) = 1;
    this->mMenu.vfptr->setItemEnabled(&this->mMenu, v17, v15);
  }
  else
  {
    v4 = UFG::qStringHashUpper32("PAUSE_CONTINUE_GAME", -1);
    v5 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v5 || (v6 = (const char *)v5->vfptr[5].__vecDelDtor(v5, v4)) == 0i64 )
      v6 = "PAUSE_CONTINUE_GAME";
    this->mMenu.vfptr->removeItem(&this->mMenu, v6);
    this->mContinueEnabled = 0;
    if ( MovieSafe )
      Scaleform::GFx::Movie::Invoke(MovieSafe, "MainMenu_Refresh", 0i64, 0i64, 0);
    this->mState = STATE_BRIGHTNESS;
    UFG::UIHKScreenMainMenu::SetFlowImage(this);
  }
}

// File Line: 1406
// RVA: 0x5FCD90
void __fastcall UFG::UIHKScreenMainMenu::PopulateSocialHubWidget(UFG::UIHKScreenMainMenu *this)
{
  Scaleform::GFx::Movie *MovieSafe; // rsi
  unsigned __int64 v3; // rbx
  UFG::OnlineManager *v4; // rax
  bool BValue; // r12
  UFG::SocialLogDataManager *v6; // rax
  UFG::SocialLogDataManager *List; // rax
  UFG::UIHKScreenMainMenu::SocialWidgetProperty *v8; // r15
  int v9; // edx
  __int64 p_mNext; // rcx
  UFG::SocialLogDataManager *v11; // r8
  __int64 v12; // rdi
  unsigned __int64 v13; // rbx
  unsigned int v14; // eax
  UFG::UIGfxTranslator *v15; // rcx
  const char *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString *v18; // rcx
  unsigned int v19; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v21; // rax
  UFG::qString *v22; // rax
  const char *v23; // rax
  UFG::qString *v24; // rax
  const char *v25; // rax
  UFG::qString *v26; // rax
  const char *v27; // rax
  UFG::qString *v28; // rax
  char *v29; // r14
  char *PlayerDisplayName; // rax
  UFG::OSuiteLeaderboardManager *v31; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingId; // rax
  UFG::OSuiteLeaderboardData *v33; // rbx
  UFG::ProgressionTracker *v34; // rax
  __int64 v35; // rdx
  unsigned int size; // r8d
  UFG::UIHKScreenMainMenu::SocialWidgetProperty *p; // r9
  const char *mData; // rsi
  unsigned int v39; // eax
  UFG::UIGfxTranslator *v40; // rcx
  const char *v41; // rax
  int v42; // eax
  unsigned int v43; // eax
  UFG::UIGfxTranslator *v44; // rcx
  const char *v45; // rax
  UFG::qString *v46; // rax
  char *v47; // rbx
  int v48; // eax
  unsigned int v49; // eax
  UFG::UIGfxTranslator *v50; // rcx
  unsigned int v51; // eax
  UFG::UIGfxTranslator *v52; // rcx
  unsigned int v53; // eax
  UFG::UIGfxTranslator *v54; // rcx
  const char *v55; // rax
  UFG::qString *v56; // rax
  char *v57; // rax
  unsigned int v58; // eax
  UFG::UIGfxTranslator *v59; // rcx
  const char *v60; // rdx
  UFG::qString *v61; // rax
  UFG::qString *v62; // rbx
  UFG::qString *v63; // rax
  char *v64; // rax
  unsigned int v65; // eax
  UFG::UIGfxTranslator *v66; // rcx
  const char *v67; // rdx
  UFG::qString *v68; // rax
  UFG::qString *v69; // rbx
  UFG::OnlineManager *v70; // rax
  UFG::OnlineId *OnlineId; // rax
  UFG::qString *v72; // rax
  Scaleform::GFx::Value::ValueUnion mValue; // rcx
  _QWORD *DataAux; // rax
  UFG::qString *v75; // rax
  Scaleform::GFx::Value::ValueUnion v76; // xmm6_8
  double v77; // xmm6_8
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rbx
  char *v79; // rbx
  bool mDisplaySocialHubWidget; // bl
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::OnlineId result; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+48h] [rbp-80h] BYREF
  __int64 v85; // [rsp+78h] [rbp-50h] BYREF
  UFG::qString v86; // [rsp+80h] [rbp-48h] BYREF
  UFG::qString v87; // [rsp+A8h] [rbp-20h] BYREF
  Scaleform::GFx::Value presult; // [rsp+D0h] [rbp+8h] BYREF
  UFG::qString v89; // [rsp+100h] [rbp+38h] BYREF
  UFG::qString formatted; // [rsp+128h] [rbp+60h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+158h] [rbp+90h] BYREF
  char v92[16]; // [rsp+188h] [rbp+C0h] BYREF
  __int64 v93; // [rsp+198h] [rbp+D0h]
  int v94; // [rsp+1A0h] [rbp+D8h]
  double v95; // [rsp+1A8h] [rbp+E0h]
  char v96[16]; // [rsp+1B8h] [rbp+F0h] BYREF
  __int64 v97; // [rsp+1C8h] [rbp+100h]
  int v98; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::Value::ObjectInterface *v99; // [rsp+1D8h] [rbp+110h]
  char v100[16]; // [rsp+1E8h] [rbp+120h] BYREF
  __int64 v101; // [rsp+1F8h] [rbp+130h]
  int v102; // [rsp+200h] [rbp+138h]
  char *v103; // [rsp+208h] [rbp+140h]
  char v104[16]; // [rsp+218h] [rbp+150h] BYREF
  __int64 v105; // [rsp+228h] [rbp+160h]
  int v106; // [rsp+230h] [rbp+168h]
  char *v107; // [rsp+238h] [rbp+170h]
  __int64 v108; // [rsp+248h] [rbp+180h]
  UFG::qString v109; // [rsp+250h] [rbp+188h] BYREF
  UFG::qString v110; // [rsp+278h] [rbp+1B0h] BYREF
  UFG::qString v111; // [rsp+2A0h] [rbp+1D8h] BYREF
  UFG::qString v112; // [rsp+2C8h] [rbp+200h] BYREF
  UFG::qString v113; // [rsp+2F0h] [rbp+228h] BYREF
  UFG::qString v114; // [rsp+318h] [rbp+250h] BYREF
  UFG::qString v115; // [rsp+340h] [rbp+278h] BYREF
  UFG::qString v116; // [rsp+368h] [rbp+2A0h] BYREF
  UFG::qString v117; // [rsp+390h] [rbp+2C8h] BYREF
  UFG::qString v118; // [rsp+3B8h] [rbp+2F0h] BYREF
  UFG::qString v119; // [rsp+3E0h] [rbp+318h] BYREF
  UFG::qString v120; // [rsp+408h] [rbp+340h] BYREF
  UFG::qString v121; // [rsp+430h] [rbp+368h] BYREF
  UFG::qString v122; // [rsp+458h] [rbp+390h] BYREF
  char putf8str[256]; // [rsp+488h] [rbp+3C0h] BYREF
  char dest[256]; // [rsp+588h] [rbp+4C0h] BYREF
  wchar_t pbuff[256]; // [rsp+688h] [rbp+5C0h] BYREF
  wchar_t v126[284]; // [rsp+888h] [rbp+7C0h] BYREF
  Scaleform::GFx::Movie *v127; // [rsp+AE0h] [rbp+A18h]
  UFG::SocialLogDataManager *v128; // [rsp+AE8h] [rbp+A20h]
  unsigned __int64 v129; // [rsp+AF0h] [rbp+A28h]

  v108 = -2i64;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  v127 = MovieSafe;
  if ( MovieSafe )
  {
    v3 = (UFG::qGetSystemTimeUTC() - 116444736000000000i64) / 0x2710;
    v129 = v3;
    v4 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetOnlineId(v4, &result);
    BValue = 1;
    v6 = UFG::SocialLogDataManager::Instance();
    List = UFG::SocialLogDataManager::GetList(v6);
    v8 = 0i64;
    v9 = 0;
    p_mNext = (__int64)&List->m_lSocialLogDataList.mNode.mNext[-2].mNext;
    v11 = List - 1;
    v128 = List - 1;
    if ( (UFG::SocialLogDataManager *)p_mNext != &List[-1] )
    {
      do
      {
        ++v9;
        p_mNext = *(_QWORD *)(p_mNext + 32) - 24i64;
      }
      while ( (UFG::SocialLogDataManager *)p_mNext != v11 );
      if ( v9 > 0 )
      {
        v12 = (__int64)&List->m_lSocialLogDataList.mNode.mPrev[-2].mNext;
        if ( (UFG::SocialLogDataManager *)v12 != v11 )
        {
          while ( 1 )
          {
            if ( !BValue )
              goto LABEL_98;
            UFG::qString::qString(&v86);
            v13 = (v3 - *(_QWORD *)(v12 + 48)) / 0x3E8;
            if ( (v13 & 0x80000000) == 0i64 )
            {
              if ( (int)v13 >= 60 )
              {
                if ( (int)v13 >= 3600 )
                {
                  if ( (int)v13 >= 86400 )
                  {
                    v27 = UFG::UI::LocalizeText("$SOCIAL_HUB_RECEIVED_TIME_DAY_FORMAT");
                    v28 = UFG::qString::FormatEx(&v111, v27, (unsigned int)((int)v13 / 86400));
                    UFG::qString::Set(&v86, v28->mData, v28->mLength, 0i64, 0);
                    v18 = &v111;
                  }
                  else
                  {
                    v25 = UFG::UI::LocalizeText("$SOCIAL_HUB_RECEIVED_TIME_HOUR_FORMAT");
                    v26 = UFG::qString::FormatEx(&v118, v25, (unsigned int)((int)v13 / 3600));
                    UFG::qString::Set(&v86, v26->mData, v26->mLength, 0i64, 0);
                    v18 = &v118;
                  }
                }
                else
                {
                  v23 = UFG::UI::LocalizeText("$SOCIAL_HUB_RECEIVED_TIME_MINUTE_FORMAT");
                  v24 = UFG::qString::FormatEx(&v116, v23, (unsigned int)((int)v13 / 60));
                  UFG::qString::Set(&v86, v24->mData, v24->mLength, 0i64, 0);
                  v18 = &v116;
                }
              }
              else
              {
                v19 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", -1);
                m_translator = UFG::UIScreenManager::s_instance->m_translator;
                if ( !m_translator
                  || (v21 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v19)) == 0i64 )
                {
                  v21 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
                }
                v22 = UFG::qString::FormatEx(&v114, v21, (unsigned int)v13);
                UFG::qString::Set(&v86, v22->mData, v22->mLength, 0i64, 0);
                v18 = &v114;
              }
            }
            else
            {
              v14 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", -1);
              v15 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v15 || (v16 = (const char *)v15->vfptr[5].__vecDelDtor(v15, v14)) == 0i64 )
                v16 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
              v17 = UFG::qString::FormatEx(&v113, v16, 0i64);
              UFG::qString::Set(&v86, v17->mData, v17->mLength, 0i64, 0);
              v18 = &v113;
            }
            UFG::qString::~qString(v18);
            v29 = &customCaption;
            UFG::qString::qString((UFG::qString *)&v85, (UFG::qString *)(v12 + 88));
            if ( !HIDWORD(pargs.pVoidNext) )
            {
              PlayerDisplayName = UFG::UI::GetPlayerDisplayName();
              UFG::qString::Set((UFG::qString *)&v85, PlayerDisplayName);
            }
            UFG::qString::qString(&v87);
            v31 = UFG::OSuiteLeaderboardManager::Instance();
            LeaderboardDataUsingId = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(
                                       v31,
                                       *(_DWORD *)(v12 + 56));
            v33 = LeaderboardDataUsingId;
            if ( !LeaderboardDataUsingId )
              goto LABEL_96;
            if ( LeaderboardDataUsingId->mFlow.mUID != -1 )
            {
              v34 = UFG::ProgressionTracker::Instance();
              if ( v33->mFlow.mUID != UFG::ProgressionTracker::GetActiveFlow(v34)->mUID )
                goto LABEL_96;
            }
            this->mDisplaySocialHubWidget = 1;
            v35 = 0i64;
            size = this->mSocialWidgetProperties.size;
            if ( size )
            {
              p = this->mSocialWidgetProperties.p;
              while ( p[v35].mLBD != v33 )
              {
                v35 = (unsigned int)(v35 + 1);
                if ( (unsigned int)v35 >= size )
                  goto LABEL_33;
              }
              v8 = &p[v35];
            }
LABEL_33:
            mData = v33->mCaption.mData;
            if ( mData )
            {
              if ( *mData == 36 )
                ++mData;
              v39 = UFG::qStringHashUpper32(mData, -1);
              v40 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v40 || (v41 = (const char *)v40->vfptr[5].__vecDelDtor(v40, v39)) == 0i64 )
                v41 = mData;
              UFG::qString::qString(&v89, v41);
            }
            else
            {
              UFG::qString::qString(&v89, 0i64);
            }
            UFG::qString::qString(&formatted);
            UFG::UIHKScreenSocialHub::FormatScore(
              (UFG::UIHKScreenSocialHub *)this,
              &formatted,
              v33,
              *(_DWORD *)(v12 + 60));
            v42 = *(_DWORD *)(v12 + 44);
            if ( !v42 )
              break;
            if ( v42 == 1 )
            {
              v47 = &customCaption;
              v48 = *(_DWORD *)(v12 + 60);
              switch ( v48 )
              {
                case 3:
                  v29 = (char *)gIconSocialHubStatAward_G_21;
                  v49 = UFG::qStringHashUpper32("SOCIAL_HUB_GOLD", -1);
                  v50 = UFG::UIScreenManager::s_instance->m_translator;
                  if ( !v50 || (v47 = (char *)v50->vfptr[5].__vecDelDtor(v50, v49)) == 0i64 )
                    v47 = "SOCIAL_HUB_GOLD";
                  break;
                case 2:
                  v29 = (char *)gIconSocialHubStatAward_S_21;
                  v51 = UFG::qStringHashUpper32("SOCIAL_HUB_SILVER", -1);
                  v52 = UFG::UIScreenManager::s_instance->m_translator;
                  if ( !v52 || (v47 = (char *)v52->vfptr[5].__vecDelDtor(v52, v51)) == 0i64 )
                    v47 = "SOCIAL_HUB_SILVER";
                  break;
                case 1:
                  v29 = (char *)gIconSocialHubStatAward_B_21;
                  v47 = (char *)UFG::UI::LocalizeText("$SOCIAL_HUB_BRONZE");
                  break;
              }
              v53 = UFG::qStringHashUpper32("SOCIAL_HUB_AWARDED_MESSAGE_FORMAT", -1);
              v54 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v54 || (v55 = (const char *)v54->vfptr[5].__vecDelDtor(v54, v53)) == 0i64 )
                v55 = "SOCIAL_HUB_AWARDED_MESSAGE_FORMAT";
              v56 = UFG::qString::FormatEx(&v109, v55, v47, v89.mData);
              v8 = 0i64;
              UFG::qString::Set(&v87, v56->mData, v56->mLength, 0i64, 0);
              UFG::qString::~qString(&v109);
              goto LABEL_81;
            }
            if ( v42 == 3 )
            {
              UFG::qStringCopy(dest, 256, *(char **)(v12 + 112), *(_DWORD *)(v12 + 108));
              UFG::qStringCopy(putf8str, 256, *(char **)(v12 + 176), *(_DWORD *)(v12 + 172));
              Scaleform::UTF8Util::DecodeString(pbuff, dest, -1i64);
              Scaleform::UTF8Util::DecodeString(v126, putf8str, -1i64);
              v57 = UFG::UI::GetPlayerDisplayName();
              UFG::qString::Set((UFG::qString *)&v85, v57);
              v58 = UFG::qStringHashUpper32("SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT", -1);
              v59 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v59 || (v60 = (const char *)v59->vfptr[5].__vecDelDtor(v59, v58)) == 0i64 )
                v60 = "SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT";
              v61 = UFG::qString::FormatEx(&v122, v60, dest, putf8str, v89.mData, formatted.mData);
              v8 = 0i64;
              UFG::qString::Set(&v87, v61->mData, v61->mLength, 0i64, 0);
              UFG::qString::~qString(&v122);
              v62 = UFG::OnlineId::ToString((UFG::OnlineId *)(v12 + 64), &v121);
              v63 = UFG::OnlineId::ToString(&result, &v115);
              UFG::qStringCompare(v63->mData, v62->mData, -1);
              UFG::qString::~qString(&v115);
              UFG::qString::~qString(&v121);
              v29 = (char *)gIconSocialHubStatGame_21;
              goto LABEL_81;
            }
            if ( v42 != 4 )
              goto LABEL_80;
            UFG::qStringCopy(putf8str, 256, *(char **)(v12 + 112), *(_DWORD *)(v12 + 108));
            UFG::qStringCopy(dest, 256, *(char **)(v12 + 176), *(_DWORD *)(v12 + 172));
            Scaleform::UTF8Util::DecodeString(v126, putf8str, -1i64);
            Scaleform::UTF8Util::DecodeString(pbuff, dest, -1i64);
            v64 = UFG::UI::GetPlayerDisplayName();
            UFG::qString::Set((UFG::qString *)&v85, v64);
            v65 = UFG::qStringHashUpper32("SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT", -1);
            v66 = UFG::UIScreenManager::s_instance->m_translator;
            if ( !v66 || (v67 = (const char *)v66->vfptr[5].__vecDelDtor(v66, v65)) == 0i64 )
              v67 = "SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT";
            v68 = UFG::qString::FormatEx(&v117, v67, putf8str, dest, v89.mData, formatted.mData);
            UFG::qString::Set(&v87, v68->mData, v68->mLength, 0i64, 0);
            UFG::qString::~qString(&v117);
            v69 = UFG::OnlineId::ToString((UFG::OnlineId *)(v12 + 64), &v110);
            v70 = UFG::OnlineManager::Instance();
            OnlineId = UFG::OnlineManager::GetOnlineId(v70, (UFG::OnlineId *)&pargs.mValue);
            v72 = UFG::OnlineId::ToString(OnlineId, &v120);
            LOBYTE(v69) = (unsigned int)UFG::qStringCompare(v72->mData, v69->mData, -1) == 0;
            UFG::qString::~qString(&v120);
            mValue = pargs.mValue;
            DataAux = (_QWORD *)pargs.DataAux;
            *((_QWORD *)pargs.mValue.pString + 1) = pargs.DataAux;
            *DataAux = mValue.pString;
            pargs.mValue.pString = (const char *)&pargs.mValue;
            pargs.DataAux = (unsigned __int64)&pargs.mValue;
            UFG::qString::~qString(&v110);
            if ( (_BYTE)v69 || !v8 || v8->mUIItemIndex >= 0 )
            {
              v29 = (char *)gIconSocialHubChallenge_21;
LABEL_80:
              v8 = 0i64;
              goto LABEL_81;
            }
            UFG::qString::~qString(&formatted);
            UFG::qString::~qString(&v89);
            UFG::qString::~qString(&v87);
            UFG::qString::~qString((UFG::qString *)&v85);
            UFG::qString::~qString(&v86);
            MovieSafe = v127;
            v8 = 0i64;
LABEL_97:
            v12 = *(_QWORD *)(v12 + 24) - 24i64;
            v3 = v129;
            if ( (UFG::SocialLogDataManager *)v12 == v128 )
              goto LABEL_98;
          }
          v43 = UFG::qStringHashUpper32("SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT", -1);
          v44 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v44 || (v45 = (const char *)v44->vfptr[5].__vecDelDtor(v44, v43)) == 0i64 )
            v45 = "SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT";
          v46 = UFG::qString::FormatEx(&v119, v45, v89.mData, formatted.mData);
          v8 = 0i64;
          UFG::qString::Set(&v87, v46->mData, v46->mLength, 0i64, 0);
          UFG::qString::~qString(&v119);
          switch ( v33->mCategory )
          {
            case LeaderboardCategory_StatGame:
              v29 = (char *)gIconSocialHubStatGameGlow_21;
              break;
            case LeaderboardCategory_Mission:
              v29 = (char *)gIconSocialHubMission_21;
              break;
            case LeaderboardCategory_Race:
              v29 = (char *)gIconSocialHubRace_21;
              break;
          }
LABEL_81:
          if ( SHIDWORD(pargs.pVoidNext) > 10 )
          {
            v75 = UFG::qString::Substring((UFG::qString *)&v85, &v112, 0, 7);
            UFG::qString::Set((UFG::qString *)&v85, v75->mData, v75->mLength, 0i64, 0);
            UFG::qString::~qString(&v112);
            UFG::qString::append((UFG::qString *)&v85, "...", 3);
          }
          presult.pObjectInterface = 0i64;
          presult.Type = VT_Undefined;
          `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v76.NValue = (double)*(int *)(v12 + 44);
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_Number;
          ptr.mValue = v76;
          v77 = (double)*(int *)(v12 + 60);
          if ( (v94 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v93 + 16i64))(
              v93,
              v92,
              COERCE_DOUBLE(*(_QWORD *)&v95));
            v93 = 0i64;
          }
          v94 = 5;
          v95 = v77;
          pObjectInterface = pargs.pObjectInterface;
          if ( (v98 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, Scaleform::GFx::Value::ObjectInterface *))(*(_QWORD *)v97 + 16i64))(
              v97,
              v96,
              v99);
            v97 = 0i64;
          }
          v98 = 6;
          v99 = pObjectInterface;
          if ( (v102 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v101 + 16i64))(v101, v100, v103);
            v101 = 0i64;
          }
          v102 = 6;
          v103 = v29;
          v79 = v87.mData;
          if ( (v106 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v105 + 16i64))(v105, v104, v107);
            v105 = 0i64;
          }
          v106 = 6;
          v107 = v79;
          MovieSafe = v127;
          Scaleform::GFx::Movie::Invoke(v127, "SetSocialHubSlot", &presult, &ptr, 5u);
          BValue = presult.mValue.BValue;
          `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          if ( (presult.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&presult.pObjectInterface->vfptr->gap8[8])(
              presult.pObjectInterface,
              &presult,
              presult.mValue);
            presult.pObjectInterface = 0i64;
          }
          presult.Type = VT_Undefined;
          UFG::qString::~qString(&formatted);
          UFG::qString::~qString(&v89);
LABEL_96:
          UFG::qString::~qString(&v87);
          UFG::qString::~qString((UFG::qString *)&v85);
          UFG::qString::~qString(&v86);
          goto LABEL_97;
        }
      }
    }
LABEL_98:
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    mDisplaySocialHubWidget = this->mDisplaySocialHubWidget;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = mDisplaySocialHubWidget;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "SetSocialHubWidgetVisible", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    mPrev = result.mPrev;
    mNext = result.mNext;
    result.mPrev->mNext = result.mNext;
    mNext->mPrev = mPrev;
  }
}

// File Line: 1693
// RVA: 0x5E6740
void __fastcall UFG::UIHKScreenSocialHub::FormatScore(
        UFG::UIHKScreenSocialHub *this,
        UFG::qString *formatted,
        UFG::OSuiteLeaderboardData *pLBD,
        unsigned int score)
{
  UFG::LeaderboardCategory mCategory; // ecx
  __int32 v8; // ecx
  __int32 v9; // ecx
  UFG::qString *LocalizedTime; // rax
  UFG::qString *p_result; // rcx
  UFG::qString *v12; // rax
  UFG::StatGamePropertyManager *v13; // rax
  UFG::StatGamePropertyData *PropertyData; // rax
  UFG::qString *v15; // rax
  UFG::StatGamePropertyManager *v16; // rax
  UFG::StatAwardPropertyData *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString result; // [rsp+38h] [rbp-B0h] BYREF
  UFG::qString v20; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString v21; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v22; // [rsp+B0h] [rbp-38h] BYREF

  mCategory = pLBD->mCategory;
  if ( mCategory )
  {
    v8 = mCategory - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 != 1 )
          return;
        LocalizedTime = UFG::UIGfxTranslator::getLocalizedTime(
                          UFG::UIScreenManager::s_instance->m_translator,
                          &v21,
                          (float)(int)score,
                          eTS_MILLISECONDS);
        UFG::qString::Set(formatted, LocalizedTime->mData, LocalizedTime->mLength, 0i64, 0);
        p_result = &v21;
      }
      else
      {
        v12 = UFG::qString::FormatEx(&result, "%d", score);
        UFG::qString::Set(formatted, v12->mData, v12->mLength, 0i64, 0);
        p_result = &result;
      }
    }
    else
    {
      v13 = UFG::StatGamePropertyManager::Instance();
      PropertyData = UFG::StatGamePropertyManager::GetPropertyData(v13, pLBD);
      v15 = UFG::StatGamePropertyData::FormatScore(PropertyData, &v20, score);
      UFG::qString::Set(formatted, v15->mData, v15->mLength, 0i64, 0);
      p_result = &v20;
    }
  }
  else
  {
    v16 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
    v17 = (UFG::StatAwardPropertyData *)UFG::StatGamePropertyManager::GetPropertyData(v16, pLBD);
    v18 = UFG::StatAwardPropertyData::FormatScore(v17, &v22, score);
    UFG::qString::Set(formatted, v18->mData, v18->mLength, 0i64, 0);
    p_result = &v22;
  }
  UFG::qString::~qString(p_result);
}

