// File Line: 93
// RVA: 0x156E160
__int64 UFG::_dynamic_initializer_for__mainFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Main", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::mainFlow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__mainFlow__);
}

// File Line: 94
// RVA: 0x156E110
__int64 UFG::_dynamic_initializer_for__ghostFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_Ghost", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::ghostFlow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__ghostFlow__);
}

// File Line: 95
// RVA: 0x156DB50
__int64 UFG::_dynamic_initializer_for__cnyFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_CNY", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::cnyFlow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__cnyFlow__);
}

// File Line: 124
// RVA: 0x5C5EA0
void __fastcall UFG::UIHKScreenMainMenu::UIHKScreenMainMenu(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::OnlineManagerObserver *v3; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v4; // rax
  UFG::OSuiteManagerObserver *v5; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v6; // rax
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *v7; // rbx
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *i; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v9; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v10; // rax

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
  v1->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMainMenu::`vftable'{for `UFG::UIScreen'};
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable'{for `UFG::OnlineManagerObserver'};
  v5->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable'{for `UFG::OSuiteManagerObserver'};
  v1->mInfoTickerSet = 0;
  UFG::UIPropertySetMenu::UIPropertySetMenu((UFG::UIPropertySetMenu *)&v1->mMenu.vfptr);
  v1->mMenu.vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenuMainNav::`vftable';
  *(_WORD *)&v1->mContinueEnabled = 0;
  v7 = &v1->mOnlineIdsToGetDisplayImageFor;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v1->mCurrentDisplayImageSlot = 0;
  v1->mSocialWidgetProperties.p = 0i64;
  *(_QWORD *)&v1->mSocialWidgetProperties.size = 0i64;
  v1->mFriendsListState = 0;
  v1->mIsHeaderLoadStarted = 0;
  v1->mHeaderInfo.p = 0i64;
  *(_QWORD *)&v1->mHeaderInfo.size = 0i64;
  `eh vector constructor iterator'(v1->mFlowList, 4ui64, 3, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v1->mCurrentFlowToCheck = 0;
  *(_WORD *)&v1->mIsLoadingSaveGame = 0;
  v1->mIsTransitionToGame = 0;
  v1->mFlowForContinue.mUID = -1;
  v1->mState = 0;
  UFG::MoviePlayer::MoviePlayer(&v1->HKUIMovie);
  v1->mInactivityTimer = 0.0;
  if ( v1->mSocialWidgetProperties.capacity < 0x100 )
    UFG::qArray<UFG::UIHKScreenMainMenu::SocialWidgetProperty,0>::Reallocate(
      &v1->mSocialWidgetProperties,
      0x100u,
      "qArray.Reallocate(Reserve)");
  for ( i = (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)v1->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
        i != v7;
        i = (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)v1->mOnlineIdsToGetDisplayImageFor.mNode.mNext )
  {
    v9 = i->mNode.mPrev;
    v10 = i->mNode.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
}

// File Line: 133
// RVA: 0x5CB400
void __fastcall UFG::UIHKScreenMainMenu::~UIHKScreenMainMenu(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rdi
  UFG::OnlineManagerObserver *v2; // r14
  UFG::OnlineManagerObserver *v3; // rsi
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  UFG::UIHKHelpBarWidget *v5; // rbx
  unsigned int v6; // eax
  UFG::OnlineManager *v7; // rax
  UFG::OnlineManager *v8; // rax
  UFG::UIScreenTextureManager *v9; // rax
  UFG::ProgressionTracker *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qPropertySet *v12; // rbx
  UFG::qSymbol *v13; // rax
  UFG::qWiseSymbol *v14; // rax
  unsigned int v15; // ecx
  UFG::OSuiteTickerManager *v16; // rax
  hkgpIndexedMeshDefinitions::Edge *v17; // rdx
  bool v18; // bl
  UFG::OSuiteTickerManager *v19; // rax
  UFG::OSuiteTickerManager *v20; // rax
  UFG::UIHKScreenMainMenu::HeaderInfo *v21; // rcx
  UFG::qSymbol *v22; // rbx
  UFG::UIHKScreenMainMenu::SocialWidgetProperty *v23; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v24; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v25; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v26; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v27; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v28; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v29; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v30; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v31; // rax
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMainMenu::`vftable'{for `UFG::UIScreen'};
  v2 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable'{for `UFG::OnlineManagerObserver'};
  v3 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::UIHKScreenMainMenu::`vftable'{for `UFG::OSuiteManagerObserver'};
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  v5 = &v4->HelpBar;
  v6 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v5, v6);
  v7 = (UFG::OnlineManager *)UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v7, v3);
  v8 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v8, v2);
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v9, "MainMenu");
  if ( UFG::UIHKScreenSplash::smMusicPlaying )
  {
    v10 = UFG::ProgressionTracker::Instance();
    v11 = UFG::ProgressionTracker::GetActiveFlow(v10);
    v12 = UFG::UI::GetDLCPropertyNode("UI-DLCSkins", "AudioProperties", "DLC", v11);
    if ( v12
      && (v13 = UFG::qSymbol::create_from_string(&result, "stop_mus_fe_lic"),
          (v14 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v12, v13, DEPTH_RECURSE)) != 0i64) )
    {
      v15 = v14->mUID;
    }
    else
    {
      if ( !(_S10_13 & 1) )
      {
        _S10_13 |= 1u;
        stop_mus_fe_lic.mUID = UFG::qWiseSymbolUIDFromString("stop_mus_fe_lic", 0x811C9DC5);
        _((AMD_HD3D *)stop_mus_fe_lic.mUID);
        atexit(UFG::UIHKScreenMainMenu::_UIHKScreenMainMenu_::_13_::_dynamic_atexit_destructor_for__stop_mus_fe_lic__);
      }
      v15 = stop_mus_fe_lic.mUID;
    }
    UFG::Music::MusicEvent(v15);
    UFG::StreamFileWrapper::EnableIncrementalMode(0);
    UFG::UIHKScreenSplash::smMusicPlaying = 0;
  }
  v16 = UFG::OSuiteTickerManager::Instance();
  v18 = UFG::OSuiteTickerManager::IsTickerAvailable(v16, v17);
  v19 = UFG::OSuiteTickerManager::Instance();
  if ( !v18 && !v19->m_downloadActive )
  {
    UFG::OSuiteTickerManager::Instance()->m_tickerType = 2;
    v20 = UFG::OSuiteTickerManager::Instance();
    UFG::OSuiteTickerManager::DownloadTicker(v20);
  }
  UFG::MoviePlayer::Close(&v1->HKUIMovie);
  UFG::MoviePlayer::~MoviePlayer(&v1->HKUIMovie);
  `eh vector destructor iterator'(v1->mFlowList, 4ui64, 3, (void (__fastcall *)(void *))_);
  v21 = v1->mHeaderInfo.p;
  if ( v21 )
  {
    v22 = &v21[-1].flow;
    `eh vector destructor iterator'(v21, 0x10ui64, v21[-1].flow.mUID, (void (__fastcall *)(void *))_);
    operator delete[](v22);
  }
  v1->mHeaderInfo.p = 0i64;
  *(_QWORD *)&v1->mHeaderInfo.size = 0i64;
  v23 = v1->mSocialWidgetProperties.p;
  if ( v23 )
    operator delete[](v23);
  v1->mSocialWidgetProperties.p = 0i64;
  *(_QWORD *)&v1->mSocialWidgetProperties.size = 0i64;
  *(_QWORD *)&result.mUID = (char *)v1 + 584;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mOnlineIdsToGetDisplayImageFor);
  v24 = v1->mOnlineIdsToGetDisplayImageFor.mNode.mPrev;
  v25 = v1->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v1->mOnlineIdsToGetDisplayImageFor.mNode.mPrev = &v1->mOnlineIdsToGetDisplayImageFor.mNode;
  v1->mOnlineIdsToGetDisplayImageFor.mNode.mNext = &v1->mOnlineIdsToGetDisplayImageFor.mNode;
  *(_QWORD *)&result.mUID = (char *)v1 + 200;
  UFG::UIPropertySetMenu::~UIPropertySetMenu((UFG::UIPropertySetMenu *)&v1->mMenu.vfptr);
  *(_QWORD *)&result.mUID = v3;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable';
  v26 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v3->mPrev;
  v27 = v3->mPrev;
  v28 = v3->mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  v26->mPrev = v26;
  v26->mNext = v26;
  *(_QWORD *)&result.mUID = v2;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v29 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v2->mPrev;
  v30 = v2->mPrev;
  v31 = v2->mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v29->mPrev = v29;
  v29->mNext = v29;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 180
// RVA: 0x632880
void __fastcall UFG::UIHKScreenMainMenu::init(UFG::UIHKScreenMainMenu *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenMainMenu *v2; // rbx
  Scaleform::GFx::Movie *v3; // rsi
  UFG::OnlineManagerObserver *v4; // rdi
  UFG::OnlineManager *v5; // rax
  UFG::OSuiteManagerObserver *v6; // rdi
  UFG::OSuiteManager *v7; // rax
  unsigned int v8; // eax
  UFG::UIGfxTranslator *v9; // rcx
  const char *v10; // rdx
  __int64 v11; // rdi
  int v12; // edx
  _BOOL8 v13; // rcx
  int v14; // er8
  char v15; // al
  int v16; // edx
  hkGeometryUtils::IVertices *v17; // rcx
  int v18; // er8
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
  void **v29; // [rsp+50h] [rbp-B8h]
  UFG::UIHKScreenMainMenu *v30; // [rsp+58h] [rbp-B0h]
  UFG::qString v31; // [rsp+60h] [rbp-A8h]
  UFG::qString v32; // [rsp+88h] [rbp-80h]
  UFG::qString v33; // [rsp+B0h] [rbp-58h]
  UFG::qSymbol flowId; // [rsp+110h] [rbp+8h]
  __int64 v35; // [rsp+120h] [rbp+18h]
  __int64 v36; // [rsp+128h] [rbp+20h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&v2->vfptr);
  v4 = (UFG::OnlineManagerObserver *)&v2->vfptr;
  if ( !v2 )
    v4 = 0i64;
  v5 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v5, v4);
  v6 = (UFG::OSuiteManagerObserver *)&v2->vfptr;
  if ( !v2 )
    v6 = 0i64;
  v7 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::RegisterObserver(v7, v6);
  v29 = &UFG::UIPropertySetMenuData::`vftable';
  UFG::qString::qString(&v31);
  UFG::qString::qString(&v32);
  v30 = v2;
  UFG::qString::Set(&v32, "MainMenu");
  UFG::qString::Set(&v31, "UI-MainMenu");
  (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, void ***))v2->mMenu.vfptr->gap8)(&v2->mMenu, &v29);
  v8 = UFG::qStringHashUpper32("PAUSE_CONTINUE_GAME", 0xFFFFFFFF);
  v9 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v9 || (v10 = (const char *)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0i64 )
    v10 = "PAUSE_CONTINUE_GAME";
  v2->mMenu.vfptr->setItemEnabled((UFG::UIPropertySetMenu *)&v2->mMenu.vfptr, v10, 0);
  v2->mContinueEnabled = 1;
  v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          32i64);
  v35 = v11;
  if ( v11 )
  {
    *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v11 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v11 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
    *(_QWORD *)v11 = &Scaleform::GFx::State::`vftable';
    *(_DWORD *)(v11 + 16) = 3;
    *(_QWORD *)v11 = &Scaleform::GFx::ActionControl::`vftable';
    *(_DWORD *)(v11 + 24) = 8;
  }
  else
  {
    v11 = 0i64;
  }
  v36 = v11;
  *(_DWORD *)(v11 + 24) |= 2u;
  v3->vfptr->SetState((Scaleform::GFx::StateBag *)&v3->vfptr, State_Filter, (Scaleform::GFx::State *)v11);
  UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  v2->mState = 1;
  if ( UFG::UIHKScreenMainMenu::mBinkEnabled )
    UFG::MoviePlayer::Init(&v2->HKUIMovie, UFG::UIHKScreenMainMenu::gLoopMovieFile, 0i64, 0x24u);
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
            UFG::UIScreenDialogBox::createOKDialog(0i64, &customWorldMapCaption, "$COMMON_TRC_PC_CONNECTION_FAILED", 0);
          hasBeenWarned = 1;
        }
        v2->mDisplaySocialHubWidget = 0;
      }
    }
    else if ( !UFG::UIHKScreenMainMenu::gNoOnlineAccountErrorInformed )
    {
      UFG::UIScreenManagerBase::queueMessage(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
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
  v2->mFlowList[0].mUID = UFG::mainFlow.mUID;
  v2->mFlowList[1].mUID = UFG::ghostFlow.mUID;
  v2->mFlowList[2].mUID = UFG::cnyFlow.mUID;
  v2->mState = 4;
  flowId.mUID = v2->mFlowList[v2->mCurrentFlowToCheck].mUID;
  v24 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v24);
  v25 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SetActiveFlow(v25, &flowId);
  v26 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v26);
  UFG::UIHKScreenMainMenu::PopulateSocialHubWidget(v2);
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v28, v27) )
  {
    _(0i64);
    UFG::qString::qString(&v33, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$KICKED_BACK_FROM_STREAMING_INSTALLER",
      v33.mData,
      UI_HASH_DIALOG_OK_30,
      1,
      "DialogBox");
    UFG::qString::~qString(&v33);
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  v29 = &UFG::UIPropertySetMenuData::`vftable';
  UFG::qString::~qString(&v32);
  UFG::qString::~qString(&v31);
}

// File Line: 361
// RVA: 0x5F23B0
void __fastcall UFG::UIHKScreenMainMenu::NetworkSignedIn(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rbx

  v1 = this;
  if ( UFG::OSuiteTickerManager::Instance()->m_tickerType )
  {
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_QWORD *)&v1[-1].HKUIMovie.mTargetTexture.mNameUID + 320i64),
      "MainMenu_HideTickerInfo",
      0i64,
      0i64,
      0);
    v1->m_screenName[24] = 0;
  }
}

// File Line: 404
// RVA: 0x5F28E0
void __fastcall UFG::UIHKScreenMainMenu::OSuiteManagerDisconnected(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rbx
  UFG::OnlineManager *v2; // rax
  Scaleform::GFx::Movie *v3; // rbx
  const char *v4; // rdi
  char *v5; // rbx
  UFG::qString v6; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::Value pargs; // [rsp+70h] [rbp-38h]

  v1 = this;
  v2 = UFG::OnlineManager::Instance();
  if ( UFG::OnlineManager::IsNetworkSignedIn(v2) && !UFG::UIHKScreenMainMenu::gOSuiteOfflineMessageInformed )
  {
    v3 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&v1[-1].mSocialWidgetProperties);
    UFG::qString::qString(&v6, "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW");
    if ( v3 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v4 = UFG::UI::LocalizeText(v6.mData);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = v4;
      Scaleform::GFx::Movie::Invoke(v3, "SetSocialHubMessage", 0i64, &pargs, 1u);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 0;
    }
    v5 = v6.mData;
    UFG::qString::qString((UFG::qString *)&pargs, "$COMMON_OK_UPPERCASE");
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      v5,
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
UFG::qString *__fastcall UFG::UIHKScreenMainMenu::ChooseSaveGameSetupFromFlow(UFG::UIHKScreenMainMenu *this, UFG::qString *result, __int64 flow)
{
  _DWORD *v3; // rbx
  UFG::qString *v4; // rdi
  const char *v5; // rdx

  v3 = (_DWORD *)flow;
  v4 = result;
  UFG::qString::qString(result);
  if ( *v3 == UFG::ghostFlow.mUID )
  {
    v5 = "gameSetupGameGhost_SaveGame";
  }
  else
  {
    v5 = "gameSetupGameCNY_SaveGame";
    if ( *v3 != UFG::cnyFlow.mUID )
      v5 = "gameSetupGame_SaveGame";
  }
  UFG::qString::Set(v4, v5);
  return v4;
}

// File Line: 488
// RVA: 0x63DD90
void __fastcall UFG::UIHKScreenMainMenu::update(UFG::UIHKScreenMainMenu *this, float elapsed)
{
  UFG::UIHKScreenMainMenu *v2; // rdi
  UFG::OSuiteTickerManager *v3; // rax
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  UFG::OSuiteTickerManager *v5; // rax
  UFG::GameSaveLoad *v6; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v7; // rax
  UFG::GameSaveLoad *v8; // rax
  UFG::GameSaveLoad *v9; // rax
  UFG::GameSaveLoad::eGameSlotNum v10; // ebx
  UFG::GameSaveLoad *v11; // rax
  UFG::ProgressionTracker *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qPropertySet *v14; // rsi
  UFG::qWiseSymbol *v15; // rax
  bool v16; // bl
  UFG::qSymbol *v17; // rax
  UFG::qWiseSymbol *v18; // rax
  unsigned int v19; // ecx
  UFG::UIScreenTextureManager *v20; // rax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h]
  UFG::qSymbol v22; // [rsp+70h] [rbp+18h]

  v2 = this;
  if ( this->mInactivityTimer > 2.0 && !UFG::OSuiteTickerManager::Instance()->m_downloadActive )
  {
    v3 = UFG::OSuiteTickerManager::Instance();
    if ( !UFG::OSuiteTickerManager::IsTickerAvailable(v3, v4) )
    {
      v5 = UFG::OSuiteTickerManager::Instance();
      UFG::OSuiteTickerManager::DownloadTicker(v5);
      Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "MainMenu_HideTickerInfo", 0i64, 0i64, 0);
    }
  }
  if ( v2->mCurrentFlowToCheck < 3 )
  {
    v6 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::IsLoadAvaliable(v6) == 1 && !v2->mIsHeaderLoadStarted )
    {
      UFG::UIHKScreenMainMenu::CheckAllHeadersForCurrentFlow(v2);
      v2->mIsHeaderLoadStarted = 1;
    }
  }
  if ( v2->mState == 1 )
  {
    if ( !UFG::UIHKScreenSplash::smMusicPlaying )
    {
      v12 = UFG::ProgressionTracker::Instance();
      v13 = UFG::ProgressionTracker::GetActiveFlow(v12);
      v14 = UFG::UI::GetDLCPropertyNode("UI-DLCSkins", "AudioProperties", "DLC", v13);
      v15 = UFG::qWiseSymbol::create_from_string(&result, "mus_music");
      v16 = UFG::TiDo::BankLoaded(v15->mUID);
      _((AMD_HD3D *)result.mUID);
      if ( v16 )
      {
        if ( v14
          && (v17 = UFG::qSymbol::create_from_string(&v22, "play_mus_fe_lic"),
              (v18 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v14, v17, DEPTH_RECURSE)) != 0i64) )
        {
          v19 = v18->mUID;
        }
        else
        {
          if ( !(_S11_10 & 1) )
          {
            _S11_10 |= 1u;
            play_mus_fe_lic.mUID = UFG::qWiseSymbolUIDFromString("play_mus_fe_lic", 0x811C9DC5);
            _((AMD_HD3D *)play_mus_fe_lic.mUID);
            atexit(UFG::UIHKScreenMainMenu::update_::_28_::_dynamic_atexit_destructor_for__play_mus_fe_lic__);
          }
          v19 = play_mus_fe_lic.mUID;
        }
        UFG::Music::MusicEvent(v19);
        UFG::StreamFileWrapper::EnableIncrementalMode(1);
        UFG::UIHKScreenSplash::smMusicPlaying = 1;
      }
    }
    if ( UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v2 )
      v2->mInactivityTimer = elapsed + v2->mInactivityTimer;
    if ( v2->mInactivityTimer > 60.0 )
    {
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
      UFG::UIHKScreenSplash::mUseAttractMode = 1;
      v20 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v20, "Splash", 0i64);
    }
  }
  else if ( v2->mState == 2 )
  {
    v8 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::IsLoadAvaliable(v8) )
    {
      v9 = UFG::GameSaveLoad::Instance();
      v10 = (unsigned int)UFG::GameSaveLoad::GetContinueGameSlot(v9);
      v11 = UFG::GameSaveLoad::Instance();
      if ( UFG::GameSaveLoad::LoadGameSlot(v11, v10) )
        v2->mState = 6;
    }
  }
  else if ( v2->mState == 8
         && !UFG::UIScreenManagerBase::areScreensPending((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr)
         && !UFG::UIScreenManagerBase::areOverlaysPending((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) )
  {
    v7 = UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 + 28) != v2->mScreenUID )
        v2->mState = 1;
    }
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 626
// RVA: 0x624970
bool __fastcall UFG::UIHKScreenMainMenu::handleMessage(UFG::UIHKScreenMainMenu *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // er14
  UFG::UIHKScreenMainMenu *v5; // rsi
  hkGeometryUtils::IVertices *v6; // rcx
  Scaleform::GFx::Movie *v7; // rdi
  int v8; // er8
  UFG::OnlineManager *v9; // rax
  char *v10; // rbx
  double v11; // xmm6_8
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v12; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v13; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v14; // rax
  UFG::OnlineManager *v15; // r8
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v16; // rcx
  int v17; // edx
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
  bool v28; // al
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
  UFG::GameSaveLoad *v50; // rax
  UFG::ProgressionTracker *v51; // rax
  UFG::qStaticSymbol *v52; // rdx
  UFG::GameSaveLoad *v53; // rax
  UFG::GameSaveLoad *v54; // rax
  UFG::GameSaveLoad *v55; // rax
  UFG::GameSaveLoad *v56; // rax
  UFG::GameSaveLoad *v57; // rax
  UFG::UIScreenTextureManager *v58; // rax
  UFG::qSymbol *v59; // rbx
  UFG::qSymbol *v60; // rbx
  unsigned int v61; // eax
  UFG::GameSaveLoad *v62; // rax
  UFG::UIPropertySetMenuVtbl *v63; // rdi
  const char *v64; // rax
  UFG::GameSaveLoad *v65; // rax
  __int64 v66; // rbx
  UFG::GameSaveLoad *v67; // rax
  __int128 v68; // xmm6
  __int128 v69; // xmm7
  __int128 v70; // xmm8
  __int128 v71; // xmm9
  __int128 v72; // xmm10
  hkGeometryUtils::IVertices *v73; // rcx
  int v74; // er8
  UFG::GameSaveLoad *v75; // rax
  __int64 *v76; // [rsp+30h] [rbp-98h]
  __int64 **v77; // [rsp+38h] [rbp-90h]
  unsigned __int64 v78; // [rsp+40h] [rbp-88h]
  char v79; // [rsp+48h] [rbp-80h]
  char ptr; // [rsp+50h] [rbp-78h]
  __int64 v81; // [rsp+58h] [rbp-70h]
  __int64 v82; // [rsp+60h] [rbp-68h]
  double v83; // [rsp+68h] [rbp-60h]
  char *v84; // [rsp+70h] [rbp-58h]
  UFG::qSymbol *v85; // [rsp+78h] [rbp-50h]
  __int64 v86; // [rsp+80h] [rbp-48h]
  char dest; // [rsp+88h] [rbp-40h]
  __int128 v88; // [rsp+A8h] [rbp-20h]
  __int128 v89; // [rsp+B8h] [rbp-10h]
  __int128 v90; // [rsp+C8h] [rbp+0h]
  __int128 v91; // [rsp+D8h] [rbp+10h]
  __int128 v92; // [rsp+E8h] [rbp+20h]
  __int128 v93; // [rsp+F8h] [rbp+30h]
  __int128 v94; // [rsp+108h] [rbp+40h]
  __int128 v95; // [rsp+118h] [rbp+50h]
  __int128 v96; // [rsp+128h] [rbp+60h]
  __int128 v97; // [rsp+138h] [rbp+70h]
  UFG::qString result; // [rsp+148h] [rbp+80h]
  UFG::qSymbol v99[2]; // [rsp+208h] [rbp+140h]
  UFG::qSymbol flow; // [rsp+210h] [rbp+148h]
  UFG::qSymbol v101; // [rsp+220h] [rbp+158h]

  v86 = -2i64;
  v3 = msg;
  v4 = msgId;
  v5 = this;
  v7 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v4 == UI_HASH_DISPLAY_IMAGE_LOADED_20 )
  {
    v9 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetRetreivedDisplayImage(v9, &result);
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v10 = result.mData;
    if ( (LODWORD(v83) >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v82 + 16i64))(v82, &ptr, v84);
      v82 = 0i64;
    }
    LODWORD(v83) = 6;
    v84 = v10;
    v11 = (double)v5->mCurrentDisplayImageSlot;
    if ( ((unsigned int)v82 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v81 + 16i64))(
        v81,
        &v79,
        COERCE_DOUBLE(*(_QWORD *)&v83));
      v81 = 0i64;
    }
    LODWORD(v82) = 5;
    v83 = v11;
    Scaleform::GFx::Movie::Invoke(v7, "SetSocialHubSlotPlayerDisplayImage", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    v12 = v5->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
    v13 = v12->mPrev;
    v14 = v12->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = v12;
    v12->mNext = v12;
    if ( (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)v5->mOnlineIdsToGetDisplayImageFor.mNode.mNext != &v5->mOnlineIdsToGetDisplayImageFor )
    {
      ++v5->mCurrentDisplayImageSlot;
      *(_QWORD *)&v99[0].mUID = &v76;
      v15 = UFG::OnlineManager::Instance();
      v16 = v5->mOnlineIdsToGetDisplayImageFor.mNode.mNext;
      v76 = (__int64 *)&v76;
      v77 = &v76;
      v78 = __PAIR__(HIDWORD(v78), 0) & 0xFF0FFFFF00000000ui64;
      HIBYTE(v78) = 0;
      HIDWORD(v78) &= 0xFFF00000;
      v78 = (unsigned __int64)v16[1].mPrev;
      ((void (__fastcall *)(UFG::OnlineManager *, __int64 **))v15->vfptr->RetreivePlayerDisplayImage)(v15, &v76);
    }
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&result);
  }
  v17 = 0x40000000;
  switch ( v5->mState )
  {
    case 0:
    case 2:
    case 5:
    case 8:
    case 0xA:
      if ( v4 != -339696135 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      v65 = UFG::GameSaveLoad::Instance();
      v66 = (signed int)UFG::GameSaveLoad::GetContinueGameSlot(v65);
      v67 = UFG::GameSaveLoad::Instance();
      v68 = *(_OWORD *)&v67->m_GameSlotHeaderInfo[v66].m_State;
      v69 = *(_OWORD *)v67->m_GameSlotHeaderInfo[v66].m_szLastMissionStringID;
      v70 = *(_OWORD *)&v67->m_GameSlotHeaderInfo[v66].m_szLastMissionStringID[16];
      v71 = *(_OWORD *)&v67->m_GameSlotHeaderInfo[v66].m_szLastMissionStringID[32];
      v72 = *(_OWORD *)&v67->m_GameSlotHeaderInfo[v66].m_szLastMissionStringID[48];
      if ( !Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v73, 10 * v66, v74) )
      {
        v88 = v68;
        v89 = v69;
        v90 = v70;
        v91 = v71;
        v92 = v72;
        v75 = UFG::GameSaveLoad::Instance();
        if ( !(unsigned __int8)UFG::GameSaveLoad::IsLaunchHeader(v75, (UFG::GameSaveLoad::tsSaveGameHeaderInfo *)&v88) )
        {
          if ( v5->mContinueEnabled )
          {
            UFG::UIPropertySetMenu::setSelectedMenuIndex(
              (UFG::UIPropertySetMenu *)&v5->mMenu.vfptr,
              (UFG::UIScreen *)&v5->vfptr,
              1);
            Scaleform::GFx::Movie::Invoke(v7, "MainMenu_Refresh", 0i64, 0i64, 0);
          }
        }
      }
      UFG::UIHKScreenMainMenu::SetFlowImage(v5);
      goto LABEL_117;
    case 1:
      if ( v5->mMenu.mState > 1u )
        goto LABEL_82;
      if ( v4 == UI_HASH_SCREEN_PUSH_20 )
      {
        UFG::qMemSet(&dest, 0, 0x20u);
        if ( v5->mMenu.mOpDependant.mLength )
          UFG::qMemCopy(&dest, v5->mMenu.mOpDependant.mData, 0x1Fu);
        v5->mState = 8;
        v18 = UFG::UIScreenTextureManager::Instance();
        v19 = &dest;
      }
      else
      {
        if ( v4 == UI_HASH_FLOW_MAIN_STORY_20 )
        {
          v20 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v20);
          v21 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SetActiveFlow(v21, (UFG::qSymbol *)&UFG::mainFlow.mUID);
          v22 = UFG::ProgressionTracker::Instance();
          v23 = &UFG::mainFlow;
        }
        else if ( v4 == UI_HASH_FLOW_GHOST_20 )
        {
          v24 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v24);
          v25 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SetActiveFlow(v25, (UFG::qSymbol *)&UFG::ghostFlow.mUID);
          v22 = UFG::ProgressionTracker::Instance();
          v23 = &UFG::ghostFlow;
        }
        else
        {
          if ( v4 != UI_HASH_FLOW_CNY_20 )
            goto LABEL_25;
          v26 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v26);
          v27 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SetActiveFlow(v27, (UFG::qSymbol *)&UFG::cnyFlow.mUID);
          v22 = UFG::ProgressionTracker::Instance();
          v23 = &UFG::cnyFlow;
        }
        UFG::ProgressionTracker::SetActiveFlow(v22, (UFG::qSymbol *)&v23->mUID);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xCCF5DDCu,
            0i64,
            0,
            0i64);
        v18 = UFG::UIScreenTextureManager::Instance();
        v19 = "StartFlowScreen";
      }
      UFG::UIScreenTextureManager::QueueLoadAndPush(v18, v19, 0i64);
LABEL_25:
      if ( v4 == UI_HASH_LOAD_FREEROAM_20 )
      {
        UFG::UIHKScreenMainMenu::CheckAutosaveOverwrite(v5);
        return 1;
      }
      if ( v4 == UI_HASH_RUNTEST_RELOAD_20 || v4 == UI_HASH_RUNTEST_ASIS_20 )
      {
        UFG::UIHKScreenMainMenu::CheckAutosaveOverwrite(v5);
        v59 = UFG::qSymbol::create_from_string(v99, v5->mMenu.mScriptFunc.mData);
        UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioScriptName = (UFG::qSymbol)v59->mUID;
        v60 = UFG::qSymbol::create_from_string(&v101, v5->mMenu.mOpDependant.mData);
        UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioParameter = (UFG::qSymbol)v60->mUID;
        return 1;
      }
      if ( v4 == UI_HASH_CONTROLLERS_20 )
      {
        v5->mState = 8;
        v29 = "Options_Controllers";
        if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
          v29 = "Options_ButtonMapping";
        v30 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v30, v29, 0i64);
      }
      else if ( v4 == UI_HASH_CREDITS_20 )
      {
        v5->mState = 8;
        v31 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v31, "Credits", 0i64);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xCCF5DDCu,
            0i64,
            0,
            0i64);
        UFG::UIScreenCredits::smTriggeredFromMainMenu = 1;
        return 1;
      }
      if ( v4 == UI_HASH_LOAD_SAVEGAME_20 )
      {
        v5->mIsTransitionToGame = 1;
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0x214376EEu,
            0i64,
            0,
            0i64);
        v5->mIsLoadingSaveGame = 1;
        return 1;
      }
      if ( v4 == UI_HASH_LOAD_OFFLINEINFOCAST_20 && v5->mInfoTickerSet )
      {
        UFG::OSuiteTickerManager::Instance()->m_tickerType = 2;
        v32 = UFG::OSuiteTickerManager::Instance();
        UFG::OSuiteTickerManager::DownloadTicker(v32);
        UFG::UIHKScreenMainMenu::HideInfoTicker(v5);
        v5->mInfoTickerSet = 0;
      }
      if ( v4 == UI_HASH_LOAD_STAGINGINFOCAST_20 && v5->mInfoTickerSet )
      {
        UFG::OSuiteTickerManager::Instance()->m_tickerType = 1;
        v33 = UFG::OSuiteTickerManager::Instance();
        UFG::OSuiteTickerManager::DownloadTicker(v33);
        UFG::UIHKScreenMainMenu::HideInfoTicker(v5);
        v5->mInfoTickerSet = 0;
      }
      if ( v4 == UI_HASH_LOAD_ACTIVEINFOCAST_20 && v5->mInfoTickerSet )
      {
        UFG::OSuiteTickerManager::Instance()->m_tickerType = 0;
        v34 = UFG::OSuiteTickerManager::Instance();
        UFG::OSuiteTickerManager::DownloadTicker(v34);
        UFG::UIHKScreenMainMenu::HideInfoTicker(v5);
        v5->mInfoTickerSet = 0;
      }
      if ( v4 == UI_HASH_GAME_RESUME_20 )
      {
LABEL_52:
        UFG::UIHKScreenMainMenu::PlayOutro(v5);
        return 1;
      }
      if ( v4 == UI_HASH_MEMCARD_SAVE_20 )
      {
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand((UFG::UIScreen *)&v5->vfptr, 1, 0);
        return 1;
      }
      if ( v4 == UI_HASH_MEMCARD_LOAD_20 )
      {
        v35 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v35);
        v36 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v36, (UFG::qSymbol *)&UFG::mainFlow.mUID);
        v37 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::SetActiveFlow(v37, (UFG::qSymbol *)&UFG::mainFlow.mUID);
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand((UFG::UIScreen *)&v5->vfptr, 0, 0);
        return 1;
      }
      if ( v4 == UI_HASH_MEMCARD_LOAD_GHOST_20 )
      {
        v38 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v38);
        v39 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v39, (UFG::qSymbol *)&UFG::ghostFlow.mUID);
        v40 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::SetActiveFlow(v40, (UFG::qSymbol *)&UFG::ghostFlow.mUID);
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand((UFG::UIScreen *)&v5->vfptr, 0, 0);
        return 1;
      }
      if ( v4 == UI_HASH_MEMCARD_LOAD_CNY_20 )
      {
        v41 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v41);
        v42 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v42, (UFG::qSymbol *)&UFG::cnyFlow.mUID);
        v43 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::SetActiveFlow(v43, (UFG::qSymbol *)&UFG::cnyFlow.mUID);
        UFG::UIHKScreenSaveLoad::queueSaveLoadCommand((UFG::UIScreen *)&v5->vfptr, 0, 0);
        return 1;
      }
      if ( v4 == UI_HASH_MEMCARD_CONTINUE_20 )
      {
        if ( !Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v6, v17, v8) )
        {
          v44 = UFG::GameSaveLoad::Instance();
          if ( (unsigned int)UFG::GameSaveLoad::GetContinueGameSlot(v44) != -1 )
          {
            v45 = UFG::GameSaveLoad::Instance();
            v46 = (signed int)UFG::GameSaveLoad::GetContinueGameSlot(v45);
            v47 = UFG::GameSaveLoad::Instance();
            v93 = *(_OWORD *)&v47->m_GameSlotHeaderInfo[v46].m_State;
            v94 = *(_OWORD *)v47->m_GameSlotHeaderInfo[v46].m_szLastMissionStringID;
            v95 = *(_OWORD *)&v47->m_GameSlotHeaderInfo[v46].m_szLastMissionStringID[16];
            v96 = *(_OWORD *)&v47->m_GameSlotHeaderInfo[v46].m_szLastMissionStringID[32];
            v97 = *(_OWORD *)&v47->m_GameSlotHeaderInfo[v46].m_szLastMissionStringID[48];
            v48 = UFG::GameSaveLoad::Instance();
            v28 = UFG::GameSaveLoad::IsLaunchHeader(v48, (UFG::GameSaveLoad::tsSaveGameHeaderInfo *)&v93);
            if ( !v28 )
              return v28;
          }
        }
        v5->mIsTransitionToGame = 1;
        v49 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v49);
        v50 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v50, &v5->mFlowForContinue);
        v51 = UFG::ProgressionTracker::Instance();
        v52 = (UFG::qStaticSymbol *)&v5->mFlowForContinue;
        goto LABEL_70;
      }
      if ( v4 == UI_HASH_MEMCARD_CONTINUE_GHOST_20 )
      {
        v5->mIsTransitionToGame = 1;
        v53 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v53);
        v54 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v54, (UFG::qSymbol *)&UFG::ghostFlow.mUID);
        v51 = UFG::ProgressionTracker::Instance();
        v52 = &UFG::ghostFlow;
LABEL_70:
        UFG::ProgressionTracker::SetActiveFlow(v51, (UFG::qSymbol *)&v52->mUID);
        v57 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::LoadAllHeaders(v57);
        v5->mIsContinue = 1;
        v5->mState = 3;
        goto LABEL_82;
      }
      if ( v4 == UI_HASH_MEMCARD_CONTINUE_CNY_20 )
      {
        v5->mIsTransitionToGame = 1;
        v55 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v55);
        v56 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SetActiveFlow(v56, (UFG::qSymbol *)&UFG::cnyFlow.mUID);
        v51 = UFG::ProgressionTracker::Instance();
        v52 = &UFG::cnyFlow;
        goto LABEL_70;
      }
      if ( v4 == UI_HASH_SAVE_COMPLETE_20 )
        return 1;
      if ( v4 == UI_HASH_LOAD_COMPLETE_20 )
        goto LABEL_52;
      if ( v4 == UI_HASH_DEBUG_LANGUAGE_LIST_20 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v5->mScreenUID);
        UFG::UIHKScreenDebugLanguageList::gReturnToMainMenu = 1;
        v5->mState = 8;
        v58 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v58, "DebugLanguageList", 0i64);
        return 1;
      }
      if ( v4 == UI_HASH_EXIT_20 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xCCF5DDCu,
            0i64,
            0,
            0i64);
        UFG::UIScreenDialogBox::createYesNoDialog(0i64, "QUIT_GAME_PROMPT", "$QUIT_GAME_DIALOG_MESSAGE", 0, 0);
        v5->mState = 11;
        return 1;
      }
      if ( v4 == UI_HASH_SELECTED_ITEM_CHANGED_20 )
        UFG::UIHKScreenMainMenu::SetFlowImage(v5);
LABEL_82:
      if ( !(*(unsigned __int8 (__fastcall **)(UFG::UIPropertySetMenuMainNav *, _QWORD, UFG::UIMessage *))&v5->mMenu.vfptr->gap8[8])(
              &v5->mMenu,
              v4,
              v3) )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      v5->mInactivityTimer = 0.0;
      if ( v4 != UI_HASH_DPAD_DOWN_PRESSED_30
        && v4 != UI_HASH_DPAD_DOWN_REPEAT_30
        && v4 != UI_HASH_THUMBSTICK_LEFT_DOWN_30
        && v4 != UI_HASH_DPAD_UP_PRESSED_30
        && v4 != UI_HASH_DPAD_UP_REPEAT_30
        && v4 != UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        return 1;
      }
      UFG::UIHKScreenMainMenu::SetFlowImage(v5);
      return 1;
    case 3:
      if ( v4 == 0xEBC0A5F9 )
      {
        v62 = UFG::GameSaveLoad::Instance();
        if ( (unsigned int)UFG::GameSaveLoad::GetContinueGameSlot(v62) == -1 )
        {
          v63 = v5->mMenu.vfptr;
          v64 = UFG::UI::LocalizeText(asc_1417E0780);
          v63->setItemEnabled((UFG::UIPropertySetMenu *)&v5->mMenu.vfptr, v64, 0);
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            UI_HASH_LOAD_OPERATION_INVALID_DEVICE_9,
            0xFFFFFFFF);
        }
        else
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0x214376EEu,
              0i64,
              0,
              0i64);
          UFG::UIScreenDialogBox::createZeroButtonDialog(
            (UFG::UIScreen *)&v5->vfptr,
            &customWorldMapCaption,
            "$COMMON_LOADING",
            0,
            "DialogBox");
          v5->mState = 2;
        }
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 4:
      if ( v4 == -339696135 )
      {
        v61 = v5->mFlowList[v5->mCurrentFlowToCheck].mUID;
        v85 = &flow;
        flow.mUID = v61;
        UFG::UIHKScreenMainMenu::FillHeaderInfoForFlow(v5, (__int64)&flow);
        if ( ++v5->mCurrentFlowToCheck >= 3 )
          UFG::UIHKScreenMainMenu::DetermineFlowForContinue(v5);
        else
          UFG::UIHKScreenMainMenu::CheckAllHeadersForCurrentFlow(v5);
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 6:
      if ( v4 == 1552074461 )
        goto LABEL_52;
      if ( v4 != 1323471633 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
      v5->mState = 1;
      return 1;
    case 7:
      if ( v4 != UI_HASH_DIALOG_YES_30 )
        goto LABEL_92;
      UFG::UIHKScreenMainMenu::PlayOutro(v5);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 9:
      if ( v4 != UI_HASH_OUTRO_COMPLETE_30 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      UFG::MoviePlayer::Close(&v5->HKUIMovie);
      UFG::UIHKScreenMainMenu::EnterGame(v5);
      v5->mState = 10;
      return 1;
    case 0xB:
      if ( v4 == UI_HASH_DIALOG_YES_30 )
      {
        gGameQuitEvent = 1;
        v5->mState = 10;
      }
      else
      {
LABEL_92:
        if ( v4 == UI_HASH_DIALOG_NO_30 )
LABEL_117:
          v5->mState = 1;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    default:
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
}

// File Line: 1098
// RVA: 0x5D4D50
void __fastcall UFG::UIHKScreenMainMenu::CheckAutosaveOverwrite(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rbx
  UFG::qString option2Text; // [rsp+58h] [rbp-60h]
  UFG::qString v3; // [rsp+80h] [rbp-38h]

  v1 = this;
  if ( UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[4].m_State == 5 )
  {
    if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xCCF5DDCu,
          0i64,
          0,
          0i64);
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
    v1->mState = 7;
  }
  else
  {
    v1->mIsTransitionToGame = 1;
    UFG::UIScreenDialogBox::createZeroButtonDialog(
      (UFG::UIScreen *)&v1->vfptr,
      &customWorldMapCaption,
      "$LOADING_POPUP",
      0,
      "DialogBox");
    v1->vfptr->outro((UFG::UIScreen *)&v1->vfptr, 0i64);
    if ( !UFG::UIHKScreenMainMenu::mBinkEnabled )
      UFG::UIHKScreenMainMenu::EnterGame(v1);
    v1->mState = 9;
    if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x214376EEu,
        0i64,
        0,
        0i64);
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
  UFG::UIHKScreenMainMenu *v1; // rbx

  v1 = this;
  UFG::UIScreenDialogBox::createZeroButtonDialog(
    (UFG::UIScreen *)&this->vfptr,
    &customWorldMapCaption,
    "$LOADING_POPUP",
    0,
    "DialogBox");
  v1->vfptr->outro((UFG::UIScreen *)&v1->vfptr, 0i64);
  if ( !UFG::UIHKScreenMainMenu::mBinkEnabled )
    UFG::UIHKScreenMainMenu::EnterGame(v1);
  v1->mState = 9;
}

// File Line: 1180
// RVA: 0x5D7210
void __fastcall UFG::UIHKScreenMainMenu::EnterGame(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rbx
  UFG::UI *v2; // rcx
  UFG::qSymbol *v3; // rdi
  UFG::ProgressionTracker *v4; // rax
  UFG::TimeOfDayManager *v5; // rax
  UFG::TimeOfDayManager *v6; // rsi
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax
  UFG::qColour *v9; // rcx
  UFG::TimeOfDayManager *v10; // rax
  UFG::TimeOfDayManager *v11; // rsi
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  unsigned int v14; // esi
  UFG::qString *v15; // rax
  UFG::qString *v16; // rax
  UFG::GameState *v17; // rax
  int lengthb; // [rsp+20h] [rbp-21h]
  float v19; // [rsp+24h] [rbp-1Dh]
  float v20; // [rsp+28h] [rbp-19h]
  int v21; // [rsp+2Ch] [rbp-15h]
  UFG::qString v22; // [rsp+30h] [rbp-11h]
  UFG::qString result; // [rsp+58h] [rbp+17h]
  UFG::qSymbol flow; // [rsp+A8h] [rbp+67h]
  UFG::qSymbol *vars0; // [rsp+B0h] [rbp+6Fh]

  v1 = this;
  UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  UFG::UI::UnpauseGame(v2);
  v3 = &v1->mFlowForContinue;
  if ( !v1->mIsContinue )
    v3 = &v1->mMenu.mProgressionFlow;
  v1->mIsContinue = 0;
  v4 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetActiveFlow(v4, v3);
  if ( v3->mUID == UFG::ghostFlow.mUID )
  {
    v5 = UFG::TimeOfDayManager::GetInstance();
    v6 = v5;
    v5->m_OverrideStateBlockAmount = 1.0;
    v7 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
    {
      v8 = UFG::qResourceWarehouse::Instance();
      v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v7;
    }
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v6->mOverrideStateBlockHandle.mPrev,
      0x4D04C7F2u,
      0x349DF3BEu,
      v7);
    Render::SkyMarshall::gSkyMarshall.mDebugDomeIndex = 2;
    UFG::SetGlobalEffectUID(0xFA64CB1u);
    UFG::EnableAltColorEffect(1);
    lengthb = LODWORD(FLOAT_0_23137255);
    v19 = FLOAT_0_56470591;
    v20 = FLOAT_0_82745099;
    v21 = (signed int)FLOAT_1_0;
    v9 = (UFG::qColour *)&lengthb;
  }
  else
  {
    v10 = UFG::TimeOfDayManager::GetInstance();
    v11 = v10;
    v10->m_OverrideStateBlockAmount = 0.0;
    v12 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
    {
      v13 = UFG::qResourceWarehouse::Instance();
      v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x4D04C7F2u);
      `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v12;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v11->mOverrideStateBlockHandle.mPrev, 0x4D04C7F2u, 0, v12);
    Render::SkyMarshall::gSkyMarshall.mDebugDomeIndex = -1;
    UFG::SetGlobalEffectUID(0);
    UFG::EnableAltColorEffect(0);
    v9 = &kMainSpinnerColour_1;
  }
  Render::SetLoadScreenSpinnerTint(v9);
  v14 = uidGameStateLoadGame_13;
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
  {
    UFG::qString::qString(&v22);
    if ( v1->mIsLoadingSaveGame )
    {
      vars0 = &flow;
      flow.mUID = v3->mUID;
      v15 = UFG::UIHKScreenMainMenu::ChooseSaveGameSetupFromFlow(v1, &result, (__int64)&flow);
      UFG::qString::Set(&v22, v15->mData, v15->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      v1->mIsLoadingSaveGame = 0;
    }
    else if ( v1->mMenu.mGameSetup.mLength )
    {
      UFG::qString::Set(&v22, v1->mMenu.mGameSetup.mData, v1->mMenu.mGameSetup.mLength, 0i64, 0);
    }
    else if ( v1->mMenu.mOpDependant.mLength )
    {
      UFG::qString::Set(&v22, v1->mMenu.mOpDependant.mData, v1->mMenu.mOpDependant.mLength, 0i64, 0);
    }
    else
    {
      vars0 = &flow;
      flow.mUID = v3->mUID;
      v16 = UFG::UIHKScreenMainMenu::ChooseSaveGameSetupFromFlow(v1, &result, (__int64)&flow);
      UFG::qString::Set(&v22, v16->mData, v16->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
    }
    v17 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v14);
    if ( v17 )
      UFG::qString::Set(&v17->mGameStateUserDataStr, v22.mData);
    UFG::qString::~qString(&v22);
  }
}

// File Line: 1260
// RVA: 0x605D50
void __fastcall UFG::UIHKScreenMainMenu::SetFlowImage(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // rsi
  Scaleform::GFx::Movie *v2; // rax
  Scaleform::GFx::Movie *v3; // rdi
  int v4; // edx
  hkGeometryUtils::IVertices *v5; // rcx
  int v6; // er8
  signed int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  const char *v10; // rdx
  unsigned int v11; // eax
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h]

  v1 = this;
  v2 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  v3 = v2;
  if ( v2 )
  {
    presult.pObjectInterface = 0i64;
    presult.Type = 0;
    Scaleform::GFx::Movie::Invoke(v2, "MainMenu_GetSelectedIndex", &presult, 0i64, 0);
    v7 = (signed int)presult.mValue.NValue;
    if ( !v1->mContinueEnabled && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v5, v4, v6) == 1 )
      ++v7;
    if ( v7 )
    {
      v8 = v7 - 1;
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
      v11 = v1->mFlowForContinue.mUID;
      if ( v11 == UFG::ghostFlow.mUID )
        goto LABEL_11;
      if ( v11 == UFG::cnyFlow.mUID )
      {
LABEL_13:
        v10 = "SetCNYFlowImage";
        goto LABEL_15;
      }
    }
    v10 = "SetMainStoryFlowImage";
LABEL_15:
    Scaleform::GFx::Movie::Invoke(v3, v10, 0i64, 0i64, 0);
    if ( ((unsigned int)presult.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&presult.pObjectInterface->vfptr->gap8[8])(
        presult.pObjectInterface,
        &presult,
        *(_QWORD *)&presult.mValue.NValue);
  }
}

// File Line: 1320
// RVA: 0x5D4CF0
void __fastcall UFG::UIHKScreenMainMenu::CheckAllHeadersForCurrentFlow(UFG::UIHKScreenMainMenu *this)
{
  __int64 v1; // rax
  UFG::GameSaveLoad *v2; // rax
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v4; // rax
  UFG::qSymbol flowId; // [rsp+30h] [rbp+8h]

  v1 = this->mCurrentFlowToCheck;
  this->mState = 4;
  flowId.mUID = this->mFlowList[v1].mUID;
  v2 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v2);
  v3 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SetActiveFlow(v3, &flowId);
  v4 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v4);
}

// File Line: 1331
// RVA: 0x5D8170
void __fastcall UFG::UIHKScreenMainMenu::FillHeaderInfoForFlow(UFG::UIHKScreenMainMenu *this, __int64 flow)
{
  int *v2; // r12
  UFG::UIHKScreenMainMenu *v3; // r13
  UFG::GameSaveLoad *v4; // rax
  __int128 v5; // ST30_16
  __int128 v6; // ST40_16
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __int64 v9; // rsi
  unsigned int v10; // edx
  int v11; // ebp
  unsigned int v12; // ebx
  unsigned int v13; // edx
  signed __int64 v14; // rcx
  hkMemoryResourceContainer *v15; // rax
  int v16; // eax
  __int64 v17; // rbp
  __int64 v18; // rsi
  UFG::GameSaveLoad *v19; // rax
  __int128 v20; // ST30_16
  __int128 v21; // ST40_16
  __int128 v22; // xmm0
  __int128 v23; // xmm1
  __int64 v24; // r14
  unsigned int v25; // edx
  int v26; // er15
  unsigned int v27; // ebx
  unsigned int v28; // edx
  signed __int64 v29; // rcx
  __m128i v30; // [rsp+20h] [rbp-78h]
  __m128i v31; // [rsp+20h] [rbp-78h]

  v2 = (int *)flow;
  v3 = this;
  v4 = UFG::GameSaveLoad::Instance();
  v5 = *(_OWORD *)v4->m_GameSlotHeaderInfo[4].m_szLastMissionStringID;
  v6 = *(_OWORD *)&v4->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[16];
  v30 = *(__m128i *)&v4->m_GameSlotHeaderInfo[4].m_State;
  v7 = *(_OWORD *)&v4->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[32];
  v8 = *(_OWORD *)&v4->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[48];
  if ( _mm_cvtsi128_si32(v30) == 5 )
  {
    v9 = v3->mHeaderInfo.size;
    v10 = v3->mHeaderInfo.capacity;
    v11 = *v2;
    v12 = v9 + 1;
    if ( (signed int)v9 + 1 > v10 )
    {
      if ( v10 )
        v13 = 2 * v10;
      else
        v13 = 1;
      for ( ; v13 < v12; v13 *= 2 )
        ;
      if ( v13 - v12 > 0x10000 )
        v13 = v9 + 65537;
      UFG::qArray<UFG::UIHKScreenMainMenu::HeaderInfo,0>::Reallocate(&v3->mHeaderInfo, v13, "qArray.Add");
    }
    v3->mHeaderInfo.size = v12;
    v14 = (signed __int64)&v3->mHeaderInfo.p[v9];
    *(_QWORD *)v14 = v30.m128i_i64[1];
    *(_DWORD *)(v14 + 8) = v11;
  }
  v15 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  v16 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v15);
  v17 = v16;
  if ( v16 > 0 )
  {
    v18 = 0i64;
    do
    {
      v19 = UFG::GameSaveLoad::Instance();
      v20 = *(_OWORD *)v19->m_GameSlotHeaderInfo[v18].m_szLastMissionStringID;
      v21 = *(_OWORD *)&v19->m_GameSlotHeaderInfo[v18].m_szLastMissionStringID[16];
      v31 = *(__m128i *)&v19->m_GameSlotHeaderInfo[v18].m_State;
      v22 = *(_OWORD *)&v19->m_GameSlotHeaderInfo[v18].m_szLastMissionStringID[32];
      v23 = *(_OWORD *)&v19->m_GameSlotHeaderInfo[v18].m_szLastMissionStringID[48];
      if ( _mm_cvtsi128_si32(v31) == 5 )
      {
        v24 = v3->mHeaderInfo.size;
        v25 = v3->mHeaderInfo.capacity;
        v26 = *v2;
        v27 = v24 + 1;
        if ( (signed int)v24 + 1 > v25 )
        {
          if ( v25 )
            v28 = 2 * v25;
          else
            v28 = 1;
          for ( ; v28 < v27; v28 *= 2 )
            ;
          if ( v28 - v27 > 0x10000 )
            v28 = v24 + 65537;
          UFG::qArray<UFG::UIHKScreenMainMenu::HeaderInfo,0>::Reallocate(&v3->mHeaderInfo, v28, "qArray.Add");
        }
        v3->mHeaderInfo.size = v27;
        v29 = (signed __int64)&v3->mHeaderInfo.p[v24];
        *(_QWORD *)v29 = v31.m128i_i64[1];
        *(_DWORD *)(v29 + 8) = v26;
      }
      ++v18;
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 1359
// RVA: 0x5D6380
void __fastcall UFG::UIHKScreenMainMenu::DetermineFlowForContinue(UFG::UIHKScreenMainMenu *this)
{
  __int64 v1; // rbx
  UFG::UIHKScreenMainMenu *v2; // rdi
  Scaleform::GFx::Movie *v3; // rsi
  unsigned int v4; // eax
  UFG::UIGfxTranslator *v5; // rcx
  const char *v6; // rdx
  unsigned __int64 v7; // rdx
  __int64 v8; // r9
  __int64 v9; // rcx
  UFG::UIHKScreenMainMenu::HeaderInfo *v10; // rax
  UFG::GameSaveLoad *v11; // rax
  UFG::GameSaveLoad *v12; // rax
  UFG::GameSaveLoad *v13; // rax
  unsigned int v14; // eax
  _BOOL8 v15; // r8
  UFG::UIGfxTranslator *v16; // rcx
  const char *v17; // rdx

  v1 = this->mHeaderInfo.size;
  v2 = this;
  this->mState = 5;
  v3 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( (signed int)v1 > 0 )
  {
    v7 = 0i64;
    v8 = v1;
    if ( v1 > 0 )
    {
      v9 = 0i64;
      do
      {
        v10 = v2->mHeaderInfo.p;
        if ( v10[v9].headerTimeStamp > v7 )
        {
          v7 = v10[v9].headerTimeStamp;
          v2->mFlowForContinue.mUID = v10[v9].flow.mUID;
        }
        ++v9;
        --v8;
      }
      while ( v8 );
    }
    v11 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v11);
    v12 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::SetActiveFlow(v12, &v2->mFlowForContinue);
    v13 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadAllHeaders(v13);
    v14 = UFG::qStringHashUpper32("PAUSE_CONTINUE_GAME", 0xFFFFFFFF);
    v16 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v16
      || (v17 = (const char *)v16->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v16->vfptr, v14)) == 0i64 )
    {
      v17 = "PAUSE_CONTINUE_GAME";
    }
    LOBYTE(v15) = 1;
    v2->mMenu.vfptr->setItemEnabled((UFG::UIPropertySetMenu *)&v2->mMenu.vfptr, v17, v15);
  }
  else
  {
    v4 = UFG::qStringHashUpper32("PAUSE_CONTINUE_GAME", 0xFFFFFFFF);
    v5 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v5 || (v6 = (const char *)v5->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, v4)) == 0i64 )
      v6 = "PAUSE_CONTINUE_GAME";
    v2->mMenu.vfptr->removeItem((UFG::UIPropertySetMenu *)&v2->mMenu.vfptr, v6);
    v2->mContinueEnabled = 0;
    if ( v3 )
      Scaleform::GFx::Movie::Invoke(v3, "MainMenu_Refresh", 0i64, 0i64, 0);
    v2->mState = 1;
    UFG::UIHKScreenMainMenu::SetFlowImage(v2);
  }
}

// File Line: 1406
// RVA: 0x5FCD90
void __fastcall UFG::UIHKScreenMainMenu::PopulateSocialHubWidget(UFG::UIHKScreenMainMenu *this)
{
  UFG::UIHKScreenMainMenu *v1; // r13
  Scaleform::GFx::Movie *v2; // rsi
  unsigned __int128 v3; // ax
  __int64 v4; // rbx
  UFG::OnlineManager *v5; // rax
  bool v6; // r12
  UFG::SocialLogDataManager *v7; // rax
  UFG::SocialLogDataManager *v8; // rax
  signed __int64 v9; // r15
  int v10; // edx
  signed __int64 v11; // rcx
  signed __int64 v12; // r8
  signed __int64 v13; // rdi
  unsigned __int64 v14; // rbx
  unsigned int v15; // eax
  UFG::UIGfxTranslator *v16; // rcx
  const char *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString *v19; // rcx
  unsigned int v20; // eax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rax
  UFG::qString *v23; // rax
  const char *v24; // rax
  unsigned int v25; // edx
  UFG::qString *v26; // rax
  const char *v27; // rax
  unsigned int v28; // edx
  UFG::qString *v29; // rax
  const char *v30; // rax
  unsigned int v31; // edx
  UFG::qString *v32; // rax
  char *v33; // r14
  char *v34; // rax
  UFG::OSuiteLeaderboardManager *v35; // rax
  UFG::OSuiteLeaderboardData *v36; // rax
  UFG::OSuiteLeaderboardData *v37; // rbx
  UFG::ProgressionTracker *v38; // rax
  __int64 v39; // rdx
  unsigned int v40; // er8
  UFG::UIHKScreenMainMenu::SocialWidgetProperty *v41; // r9
  const char *v42; // rsi
  const char *v43; // rax
  unsigned int v44; // eax
  UFG::UIGfxTranslator *v45; // rcx
  int v46; // eax
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
  const char *v59; // rax
  UFG::qString *v60; // rax
  char *v61; // rax
  unsigned int v62; // eax
  UFG::UIGfxTranslator *v63; // rcx
  const char *v64; // rdx
  UFG::qString *v65; // rax
  UFG::qString *v66; // rbx
  UFG::qString *v67; // rax
  char *v68; // rax
  unsigned int v69; // eax
  UFG::UIGfxTranslator *v70; // rcx
  const char *v71; // rdx
  UFG::qString *v72; // rax
  UFG::qString *v73; // rbx
  UFG::OnlineManager *v74; // rax
  UFG::OnlineId *v75; // rax
  UFG::qString *v76; // rax
  long double v77; // rcx
  long double *v78; // rax
  UFG::qString *v79; // rax
  double v80; // xmm6_8
  double v81; // xmm6_8
  Scaleform::GFx::Value::ObjectInterface *v82; // rbx
  char *v83; // rbx
  bool v84; // bl
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v85; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v86; // rax
  UFG::OnlineId result; // [rsp+30h] [rbp-98h]
  Scaleform::GFx::Value pargs; // [rsp+48h] [rbp-80h]
  __int64 v89; // [rsp+78h] [rbp-50h]
  UFG::qString v90; // [rsp+80h] [rbp-48h]
  UFG::qString v91; // [rsp+A8h] [rbp-20h]
  Scaleform::GFx::Value presult; // [rsp+D0h] [rbp+8h]
  UFG::qString v93; // [rsp+100h] [rbp+38h]
  UFG::qString formatted; // [rsp+128h] [rbp+60h]
  char ptr; // [rsp+158h] [rbp+90h]
  __int64 v96; // [rsp+168h] [rbp+A0h]
  unsigned int v97; // [rsp+170h] [rbp+A8h]
  double v98; // [rsp+178h] [rbp+B0h]
  char v99; // [rsp+188h] [rbp+C0h]
  __int64 v100; // [rsp+198h] [rbp+D0h]
  unsigned int v101; // [rsp+1A0h] [rbp+D8h]
  double v102; // [rsp+1A8h] [rbp+E0h]
  char v103; // [rsp+1B8h] [rbp+F0h]
  __int64 v104; // [rsp+1C8h] [rbp+100h]
  unsigned int v105; // [rsp+1D0h] [rbp+108h]
  Scaleform::GFx::Value::ObjectInterface *v106; // [rsp+1D8h] [rbp+110h]
  char v107; // [rsp+1E8h] [rbp+120h]
  __int64 v108; // [rsp+1F8h] [rbp+130h]
  unsigned int v109; // [rsp+200h] [rbp+138h]
  char *v110; // [rsp+208h] [rbp+140h]
  char v111; // [rsp+218h] [rbp+150h]
  __int64 v112; // [rsp+228h] [rbp+160h]
  unsigned int v113; // [rsp+230h] [rbp+168h]
  char *v114; // [rsp+238h] [rbp+170h]
  __int64 v115; // [rsp+248h] [rbp+180h]
  UFG::qString v116; // [rsp+250h] [rbp+188h]
  UFG::qString v117; // [rsp+278h] [rbp+1B0h]
  UFG::qString v118; // [rsp+2A0h] [rbp+1D8h]
  UFG::qString v119; // [rsp+2C8h] [rbp+200h]
  UFG::qString v120; // [rsp+2F0h] [rbp+228h]
  UFG::qString v121; // [rsp+318h] [rbp+250h]
  UFG::qString v122; // [rsp+340h] [rbp+278h]
  UFG::qString v123; // [rsp+368h] [rbp+2A0h]
  UFG::qString v124; // [rsp+390h] [rbp+2C8h]
  UFG::qString v125; // [rsp+3B8h] [rbp+2F0h]
  UFG::qString v126; // [rsp+3E0h] [rbp+318h]
  UFG::qString v127; // [rsp+408h] [rbp+340h]
  UFG::qString v128; // [rsp+430h] [rbp+368h]
  UFG::qString v129; // [rsp+458h] [rbp+390h]
  char putf8str; // [rsp+488h] [rbp+3C0h]
  char dest; // [rsp+588h] [rbp+4C0h]
  wchar_t pbuff; // [rsp+688h] [rbp+5C0h]
  wchar_t v133; // [rsp+888h] [rbp+7C0h]
  Scaleform::GFx::Movie *v134; // [rsp+AE0h] [rbp+A18h]
  UFG::SocialLogDataManager *v135; // [rsp+AE8h] [rbp+A20h]
  __int64 v136; // [rsp+AF0h] [rbp+A28h]

  v115 = -2i64;
  v1 = this;
  v2 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  v134 = v2;
  if ( v2 )
  {
    v3 = (UFG::qGetSystemTimeUTC() - 116444736000000000i64) * (unsigned __int128)0x346DC5D63886594Bui64;
    v4 = *((_QWORD *)&v3 + 1) >> 11;
    v136 = *((_QWORD *)&v3 + 1) >> 11;
    v5 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetOnlineId(v5, &result);
    v6 = 1;
    v7 = UFG::SocialLogDataManager::Instance();
    v8 = UFG::SocialLogDataManager::GetList(v7);
    v9 = 0i64;
    v10 = 0;
    v11 = (signed __int64)&v8->m_lSocialLogDataList.mNode.mNext[-2].mNext;
    v12 = (signed __int64)&v8[-1];
    v135 = v8 - 1;
    if ( (UFG::SocialLogDataManager *)v11 != &v8[-1] )
    {
      do
      {
        ++v10;
        v11 = *(_QWORD *)(v11 + 32) - 24i64;
      }
      while ( v11 != v12 );
      if ( v10 > 0 )
      {
        v13 = (signed __int64)&v8->m_lSocialLogDataList.mNode.mPrev[-2].mNext;
        if ( v13 != v12 )
        {
          while ( 1 )
          {
            if ( v6 != 1 )
              goto LABEL_97;
            UFG::qString::qString(&v90);
            v14 = (unsigned __int64)(((unsigned __int64)(v4 - *(_QWORD *)(v13 + 48))
                                    * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                                   + ((unsigned __int64)(v4
                                                       - *(_QWORD *)(v13 + 48)
                                                       - ((unsigned __int64)(v4 - *(_QWORD *)(v13 + 48))
                                                        * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
            if ( (v14 & 0x80000000) == 0i64 )
            {
              if ( (signed int)v14 >= 60 )
              {
                if ( (signed int)v14 >= 3600 )
                {
                  if ( (signed int)v14 >= 86400 )
                  {
                    v30 = UFG::UI::LocalizeText(asc_1417DE870);
                    v31 = (signed int)(v14 + ((unsigned __int64)(-1037155065i64 * (signed int)v14) >> 32)) >> 16;
                    v32 = UFG::qString::FormatEx(&v118, v30, v31 + (v31 >> 31));
                    UFG::qString::Set(&v90, v32->mData, v32->mLength, 0i64, 0);
                    v19 = &v118;
                  }
                  else
                  {
                    v27 = UFG::UI::LocalizeText(asc_1417DE848);
                    v28 = (signed int)(v14 + ((unsigned __int64)(-1851608123i64 * (signed int)v14) >> 32)) >> 11;
                    v29 = UFG::qString::FormatEx(&v125, v27, v28 + (v28 >> 31));
                    UFG::qString::Set(&v90, v29->mData, v29->mLength, 0i64, 0);
                    v19 = &v125;
                  }
                }
                else
                {
                  v24 = UFG::UI::LocalizeText(asc_1417DE820);
                  v25 = (signed int)(v14 + ((unsigned __int64)(-2004318071i64 * (signed int)v14) >> 32)) >> 5;
                  v26 = UFG::qString::FormatEx(&v123, v24, v25 + (v25 >> 31));
                  UFG::qString::Set(&v90, v26->mData, v26->mLength, 0i64, 0);
                  v19 = &v123;
                }
              }
              else
              {
                v20 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", 0xFFFFFFFF);
                v21 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v21
                  || (v22 = (const char *)v21->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, v20)) == 0i64 )
                {
                  v22 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
                }
                v23 = UFG::qString::FormatEx(&v121, v22, (unsigned int)v14);
                UFG::qString::Set(&v90, v23->mData, v23->mLength, 0i64, 0);
                v19 = &v121;
              }
            }
            else
            {
              v15 = UFG::qStringHashUpper32("SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT", 0xFFFFFFFF);
              v16 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v16
                || (v17 = (const char *)v16->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v16->vfptr, v15)) == 0i64 )
              {
                v17 = "SOCIAL_HUB_RECEIVED_TIME_SECOND_FORMAT";
              }
              v18 = UFG::qString::FormatEx(&v120, v17, 0i64);
              UFG::qString::Set(&v90, v18->mData, v18->mLength, 0i64, 0);
              v19 = &v120;
            }
            UFG::qString::~qString(v19);
            v33 = &customWorldMapCaption;
            UFG::qString::qString((UFG::qString *)&v89, (UFG::qString *)(v13 + 88));
            if ( !HIDWORD(pargs.pVoidNext) )
            {
              v34 = UFG::UI::GetPlayerDisplayName();
              UFG::qString::Set((UFG::qString *)&v89, v34);
            }
            UFG::qString::qString(&v91);
            v35 = UFG::OSuiteLeaderboardManager::Instance();
            v36 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(v35, *(_DWORD *)(v13 + 56));
            v37 = v36;
            if ( !v36 )
              goto LABEL_95;
            if ( v36->mFlow.mUID != -1 )
            {
              v38 = UFG::ProgressionTracker::Instance();
              if ( v37->mFlow.mUID != UFG::ProgressionTracker::GetActiveFlow(v38)->mUID )
                goto LABEL_95;
            }
            v1->mDisplaySocialHubWidget = 1;
            v39 = 0i64;
            v40 = v1->mSocialWidgetProperties.size;
            if ( v40 )
            {
              v41 = v1->mSocialWidgetProperties.p;
              while ( v41[v39].mLBD != v37 )
              {
                v39 = (unsigned int)(v39 + 1);
                if ( (unsigned int)v39 >= v40 )
                  goto LABEL_33;
              }
              v9 = (signed __int64)&v41[v39];
            }
LABEL_33:
            v42 = v37->mCaption.mData;
            if ( v42 )
            {
              if ( *v42 == 36 )
                ++v42;
              v44 = UFG::qStringHashUpper32(v42, 0xFFFFFFFF);
              v45 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v45
                || (v43 = (const char *)v45->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v45->vfptr, v44)) == 0i64 )
              {
                v43 = v42;
              }
            }
            else
            {
              v43 = 0i64;
            }
            UFG::qString::qString(&v93, v43);
            UFG::qString::qString(&formatted);
            UFG::UIHKScreenSocialHub::FormatScore(
              (UFG::UIHKScreenSocialHub *)v1,
              &formatted,
              v37,
              *(_DWORD *)(v13 + 60));
            v46 = *(_DWORD *)(v13 + 44);
            if ( !v46 )
              break;
            if ( v46 == 1 )
            {
              v51 = &customWorldMapCaption;
              v52 = *(_DWORD *)(v13 + 60);
              switch ( v52 )
              {
                case 3:
                  v33 = (char *)gIconSocialHubStatAward_G_21;
                  v53 = UFG::qStringHashUpper32("SOCIAL_HUB_GOLD", 0xFFFFFFFF);
                  v54 = UFG::UIScreenManager::s_instance->m_translator;
                  if ( !v54
                    || (v51 = (char *)v54->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v54->vfptr, v53)) == 0i64 )
                  {
                    v51 = "SOCIAL_HUB_GOLD";
                  }
                  break;
                case 2:
                  v33 = (char *)gIconSocialHubStatAward_S_21;
                  v55 = UFG::qStringHashUpper32("SOCIAL_HUB_SILVER", 0xFFFFFFFF);
                  v56 = UFG::UIScreenManager::s_instance->m_translator;
                  if ( !v56
                    || (v51 = (char *)v56->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v56->vfptr, v55)) == 0i64 )
                  {
                    v51 = "SOCIAL_HUB_SILVER";
                  }
                  break;
                case 1:
                  v33 = (char *)gIconSocialHubStatAward_B_21;
                  v51 = (char *)UFG::UI::LocalizeText(asc_1417DE8F0);
                  break;
              }
              v57 = UFG::qStringHashUpper32("SOCIAL_HUB_AWARDED_MESSAGE_FORMAT", 0xFFFFFFFF);
              v58 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v58
                || (v59 = (const char *)v58->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v58->vfptr, v57)) == 0i64 )
              {
                v59 = "SOCIAL_HUB_AWARDED_MESSAGE_FORMAT";
              }
              v60 = UFG::qString::FormatEx(&v116, v59, v51, v93.mData);
              v9 = 0i64;
              UFG::qString::Set(&v91, v60->mData, v60->mLength, 0i64, 0);
              UFG::qString::~qString(&v116);
              goto LABEL_80;
            }
            if ( v46 == 3 )
            {
              UFG::qStringCopy(&dest, 256, *(const char **)(v13 + 112), *(_DWORD *)(v13 + 108));
              UFG::qStringCopy(&putf8str, 256, *(const char **)(v13 + 176), *(_DWORD *)(v13 + 172));
              Scaleform::UTF8Util::DecodeString(&pbuff, &dest, -1i64);
              Scaleform::UTF8Util::DecodeString(&v133, &putf8str, -1i64);
              v61 = UFG::UI::GetPlayerDisplayName();
              UFG::qString::Set((UFG::qString *)&v89, v61);
              v62 = UFG::qStringHashUpper32("SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT", 0xFFFFFFFF);
              v63 = UFG::UIScreenManager::s_instance->m_translator;
              if ( !v63
                || (v64 = (const char *)v63->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v63->vfptr, v62)) == 0i64 )
              {
                v64 = "SOCIAL_HUB_BEAT_CHALLENGE_MESSAGE_FORMAT";
              }
              v65 = UFG::qString::FormatEx(&v129, v64, &dest, &putf8str, v93.mData, formatted.mData);
              v9 = 0i64;
              UFG::qString::Set(&v91, v65->mData, v65->mLength, 0i64, 0);
              UFG::qString::~qString(&v129);
              v66 = UFG::OnlineId::ToString((UFG::OnlineId *)(v13 + 64), &v128);
              v67 = UFG::OnlineId::ToString(&result, &v122);
              UFG::qStringCompare(v67->mData, v66->mData, -1);
              UFG::qString::~qString(&v122);
              UFG::qString::~qString(&v128);
              v33 = (char *)gIconSocialHubStatGame_21;
              goto LABEL_80;
            }
            if ( v46 != 4 )
              goto LABEL_79;
            UFG::qStringCopy(&putf8str, 256, *(const char **)(v13 + 112), *(_DWORD *)(v13 + 108));
            UFG::qStringCopy(&dest, 256, *(const char **)(v13 + 176), *(_DWORD *)(v13 + 172));
            Scaleform::UTF8Util::DecodeString(&v133, &putf8str, -1i64);
            Scaleform::UTF8Util::DecodeString(&pbuff, &dest, -1i64);
            v68 = UFG::UI::GetPlayerDisplayName();
            UFG::qString::Set((UFG::qString *)&v89, v68);
            v69 = UFG::qStringHashUpper32("SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT", 0xFFFFFFFF);
            v70 = UFG::UIScreenManager::s_instance->m_translator;
            if ( !v70
              || (v71 = (const char *)v70->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v70->vfptr, v69)) == 0i64 )
            {
              v71 = "SOCIAL_HUB_CHALLENGE_MESSAGE_FORMAT";
            }
            v72 = UFG::qString::FormatEx(&v124, v71, &putf8str, &dest, v93.mData, formatted.mData);
            UFG::qString::Set(&v91, v72->mData, v72->mLength, 0i64, 0);
            UFG::qString::~qString(&v124);
            v73 = UFG::OnlineId::ToString((UFG::OnlineId *)(v13 + 64), &v117);
            v74 = UFG::OnlineManager::Instance();
            v75 = UFG::OnlineManager::GetOnlineId(v74, (UFG::OnlineId *)&pargs.mValue);
            v76 = UFG::OnlineId::ToString(v75, &v127);
            LOBYTE(v73) = (unsigned int)UFG::qStringCompare(v76->mData, v73->mData, -1) == 0;
            UFG::qString::~qString(&v127);
            v77 = pargs.mValue.NValue;
            v78 = (long double *)pargs.DataAux;
            *(_QWORD *)(*(_QWORD *)&pargs.mValue.NValue + 8i64) = pargs.DataAux;
            *v78 = v77;
            *(_QWORD *)&pargs.mValue.NValue = (char *)&pargs + 32;
            pargs.DataAux = (unsigned __int64)&pargs.mValue;
            UFG::qString::~qString(&v117);
            if ( (_BYTE)v73 || !v9 || *(_DWORD *)(v9 + 8) >= 0 )
            {
              v33 = (char *)gIconSocialHubChallenge_21;
LABEL_79:
              v9 = 0i64;
              goto LABEL_80;
            }
            UFG::qString::~qString(&formatted);
            UFG::qString::~qString(&v93);
            UFG::qString::~qString(&v91);
            UFG::qString::~qString((UFG::qString *)&v89);
            UFG::qString::~qString(&v90);
            v2 = v134;
            v9 = 0i64;
LABEL_96:
            v13 = *(_QWORD *)(v13 + 24) - 24i64;
            v4 = v136;
            if ( (UFG::SocialLogDataManager *)v13 == v135 )
              goto LABEL_97;
          }
          v47 = UFG::qStringHashUpper32("SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT", 0xFFFFFFFF);
          v48 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v48
            || (v49 = (const char *)v48->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v48->vfptr, v47)) == 0i64 )
          {
            v49 = "SOCIAL_HUB_NEW_RECORD_MESSAGE_FORMAT";
          }
          v50 = UFG::qString::FormatEx(&v126, v49, v93.mData, formatted.mData);
          v9 = 0i64;
          UFG::qString::Set(&v91, v50->mData, v50->mLength, 0i64, 0);
          UFG::qString::~qString(&v126);
          switch ( v37->mCategory )
          {
            case 1u:
              v33 = (char *)gIconSocialHubStatGameGlow_21;
              break;
            case 2u:
              v33 = (char *)gIconSocialHubMission_21;
              break;
            case 3u:
              v33 = (char *)gIconSocialHubRace_21;
              break;
          }
LABEL_80:
          if ( SHIDWORD(pargs.pVoidNext) > 10 )
          {
            v79 = UFG::qString::Substring((UFG::qString *)&v89, &v119, 0, 7);
            UFG::qString::Set((UFG::qString *)&v89, v79->mData, v79->mLength, 0i64, 0);
            UFG::qString::~qString(&v119);
            UFG::qString::append((UFG::qString *)&v89, "...", 3u);
          }
          presult.pObjectInterface = 0i64;
          presult.Type = 0;
          `eh vector constructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v80 = (double)*(signed int *)(v13 + 44);
          if ( (v97 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v96 + 16i64))(
              v96,
              &ptr,
              COERCE_DOUBLE(*(_QWORD *)&v98));
            v96 = 0i64;
          }
          v97 = 5;
          v98 = v80;
          v81 = (double)*(signed int *)(v13 + 60);
          if ( (v101 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v100 + 16i64))(
              v100,
              &v99,
              COERCE_DOUBLE(*(_QWORD *)&v102));
            v100 = 0i64;
          }
          v101 = 5;
          v102 = v81;
          v82 = pargs.pObjectInterface;
          if ( (v105 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, Scaleform::GFx::Value::ObjectInterface *))(*(_QWORD *)v104 + 16i64))(
              v104,
              &v103,
              v106);
            v104 = 0i64;
          }
          v105 = 6;
          v106 = v82;
          if ( (v109 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v108 + 16i64))(v108, &v107, v110);
            v108 = 0i64;
          }
          v109 = 6;
          v110 = v33;
          v83 = v91.mData;
          if ( (v113 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v112 + 16i64))(v112, &v111, v114);
            v112 = 0i64;
          }
          v113 = 6;
          v114 = v83;
          v2 = v134;
          Scaleform::GFx::Movie::Invoke(v134, "SetSocialHubSlot", &presult, (Scaleform::GFx::Value *)&ptr, 5u);
          v6 = presult.mValue.BValue;
          `eh vector destructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          if ( ((unsigned int)presult.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&presult.pObjectInterface->vfptr->gap8[8])(
              presult.pObjectInterface,
              &presult,
              *(_QWORD *)&presult.mValue.NValue);
            presult.pObjectInterface = 0i64;
          }
          presult.Type = 0;
          UFG::qString::~qString(&formatted);
          UFG::qString::~qString(&v93);
LABEL_95:
          UFG::qString::~qString(&v91);
          UFG::qString::~qString((UFG::qString *)&v89);
          UFG::qString::~qString(&v90);
          goto LABEL_96;
        }
      }
    }
LABEL_97:
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v84 = v1->mDisplaySocialHubWidget;
    pargs.Type = 2;
    pargs.mValue.BValue = v84;
    Scaleform::GFx::Movie::Invoke(v2, "SetSocialHubWidgetVisible", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    v85 = result.mPrev;
    v86 = result.mNext;
    result.mPrev->mNext = result.mNext;
    v86->mPrev = v85;
  }
}

// File Line: 1693
// RVA: 0x5E6740
void __fastcall UFG::UIHKScreenSocialHub::FormatScore(UFG::UIHKScreenSocialHub *this, UFG::qString *formatted, UFG::OSuiteLeaderboardData *pLBD, int score)
{
  int v4; // edi
  UFG::OSuiteLeaderboardData *v5; // rbx
  UFG::qString *v6; // rsi
  UFG::LeaderboardCategory v7; // ecx
  int v8; // ecx
  int v9; // ecx
  UFG::qString *v10; // rax
  UFG::qString *v11; // rcx
  UFG::qString *v12; // rax
  UFG::StatGamePropertyManager *v13; // rax
  UFG::StatGamePropertyData *v14; // rax
  UFG::qString *v15; // rax
  UFG::StatGamePropertyManager *v16; // rax
  UFG::StatAwardPropertyData *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString result; // [rsp+38h] [rbp-B0h]
  UFG::qString v20; // [rsp+60h] [rbp-88h]
  char v21; // [rsp+88h] [rbp-60h]
  UFG::qString v22; // [rsp+B0h] [rbp-38h]

  v4 = score;
  v5 = pLBD;
  v6 = formatted;
  v7 = pLBD->mCategory;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 != 1 )
          return;
        v10 = UFG::UIGfxTranslator::getLocalizedTime(
                UFG::UIScreenManager::s_instance->m_translator,
                (UFG::qString *)&v21,
                (float)score,
                0);
        UFG::qString::Set(v6, v10->mData, v10->mLength, 0i64, 0);
        v11 = (UFG::qString *)&v21;
      }
      else
      {
        v12 = UFG::qString::FormatEx(&result, "%d", (unsigned int)score);
        UFG::qString::Set(v6, v12->mData, v12->mLength, 0i64, 0);
        v11 = &result;
      }
    }
    else
    {
      v13 = UFG::StatGamePropertyManager::Instance();
      v14 = UFG::StatGamePropertyManager::GetPropertyData(v13, v5);
      v15 = UFG::StatGamePropertyData::FormatScore(v14, &v20, v4);
      UFG::qString::Set(v6, v15->mData, v15->mLength, 0i64, 0);
      v11 = &v20;
    }
  }
  else
  {
    v16 = (UFG::StatGamePropertyManager *)UFG::StatAwardPropertyManager::Instance();
    v17 = (UFG::StatAwardPropertyData *)UFG::StatGamePropertyManager::GetPropertyData(v16, v5);
    v18 = UFG::StatAwardPropertyData::FormatScore(v17, &v22, v4);
    UFG::qString::Set(v6, v18->mData, v18->mLength, 0i64, 0);
    v11 = &v22;
  }
  UFG::qString::~qString(v11);
}

