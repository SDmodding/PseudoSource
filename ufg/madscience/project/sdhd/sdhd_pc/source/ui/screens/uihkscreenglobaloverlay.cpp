// File Line: 38
// RVA: 0x15673B0
__int64 dynamic_initializer_for__UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue__);
}

// File Line: 40
// RVA: 0x156DBF0
__int64 UFG::_dynamic_initializer_for__gGlobalOverlaySentinel__()
{
  UFG::UIHKScreenGlobalOverlay::UIHKScreenGlobalOverlay(&gGlobalOverlaySentinel);
  return atexit(UFG::_dynamic_atexit_destructor_for__gGlobalOverlaySentinel__);
}

// File Line: 50
// RVA: 0x5C5620
void __fastcall UFG::UIHKScreenGlobalOverlay::UIHKScreenGlobalOverlay(UFG::UIHKScreenGlobalOverlay *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::UIHKMessageOverlay *v3; // rbx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v4; // rax
  UFG::OnlineManager *v5; // rax
  UFG::UIHKScreenGlobalOverlay *v6; // rax
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0> *v7; // [rsp+60h] [rbp+18h]

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGlobalOverlay::`vftable';
  UFG::UIHKTextOverlay::UIHKTextOverlay(&this->TextOverlay);
  v1->NISOverlay.vfptr = (UFG::UIHK_NISOverlayVtbl *)&UFG::UIHK_NISOverlay::`vftable';
  *(_WORD *)&v1->NISOverlay.FrameCounter.mChanged = 0;
  UFG::qString::qString(&v1->NISOverlay.FrameCounter.mCaption);
  *(_WORD *)&v1->NISOverlay.mActive = 0;
  v1->NISOverlay.mShouldHideSkipButtonPrompt = 0;
  v1->NISOverlay.mSkipButtonTimer = 0.0;
  v3 = &v1->MessageOverlay;
  v4 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v1->MessageOverlay.mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKMessageOverlay::`vftable';
  v1->MessageOverlay.m_bDisconnectedDialogUp = 0;
  v5 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v5, (UFG::OnlineManagerObserver *)&v1->MessageOverlay.vfptr);
  v1->SaveLoadOverlay.vfptr = (UFG::UIHKSaveLoadOverlayVtbl *)&UFG::UIHKSaveLoadOverlay::`vftable';
  v1->SaveLoadOverlay.m_fTimeToHideOverlay = 0.0;
  *(_WORD *)&v1->SaveLoadOverlay.m_bOverlayVisible = 0;
  v1->LoadingOverlay.vfptr = (UFG::UIHKLoadingOverlayVtbl *)&UFG::UIHKLoadingOverlay::`vftable';
  v1->PopUpOverlay.vfptr = (UFG::UIHKPopUpNotifierVtbl *)&UFG::UIHKPopUpNotifier::`vftable';
  v7 = &v1->PopUpOverlay.m_MessageQueue;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v1->PopUpOverlay.m_eState = 0;
  *(_QWORD *)&v1->PopUpOverlay.m_iNumMessages = 0i64;
  v1->TutorialOverlay.vfptr = (UFG::UIHKTutorialOverlayVtbl *)&UFG::UIHKTutorialOverlay::`vftable';
  UFG::qString::qString(&v1->TutorialOverlay.m_TitleTxt);
  UFG::qString::qString(&v1->TutorialOverlay.m_BodyTxt);
  v1->TutorialOverlay.m_eState = 0;
  UFG::UIHKHelpBarWidget::UIHKHelpBarWidget(&v1->HelpBar);
  v1->TimeOfDay.mLightingConditions = 0;
  *(_WORD *)&v1->m_skookum_dialog_active = 0;
  v1->m_skookum_dialog_result = 0;
  v1->m_bIsInactive = 0;
  v1->m_iPreviousRichPresenceIndex = -1;
  v6 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( v1 != &gGlobalOverlaySentinel )
    v6 = v1;
  UFG::UIHKScreenGlobalOverlay::mThis = v6;
  v1->TextOverlay.mScreen = (UFG::UIScreen *)&v1->vfptr;
}

// File Line: 62
// RVA: 0x5CAE60
void __fastcall UFG::UIHKScreenGlobalOverlay::~UIHKScreenGlobalOverlay(UFG::UIHKScreenGlobalOverlay *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v3; // rcx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v4; // rax
  UFG::UIHKMessageOverlay *v5; // rbx
  UFG::OnlineManager *v6; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v7; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v8; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGlobalOverlay::`vftable';
  UFG::UIHKScreenGlobalOverlay::mThis = 0i64;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "GlobalOverlay");
  UFG::UIHKHelpBarWidget::~UIHKHelpBarWidget(&v1->HelpBar);
  v1->TutorialOverlay.vfptr = (UFG::UIHKTutorialOverlayVtbl *)&UFG::UIHKTutorialOverlay::`vftable';
  UFG::qString::~qString(&v1->TutorialOverlay.m_BodyTxt);
  UFG::qString::~qString(&v1->TutorialOverlay.m_TitleTxt);
  v1->PopUpOverlay.vfptr = (UFG::UIHKPopUpNotifierVtbl *)&UFG::UIHKPopUpNotifier::`vftable';
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&v1->PopUpOverlay.m_MessageQueue);
  v3 = v1->PopUpOverlay.m_MessageQueue.mNode.mPrev;
  v4 = v1->PopUpOverlay.m_MessageQueue.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->PopUpOverlay.m_MessageQueue.mNode.mPrev = &v1->PopUpOverlay.m_MessageQueue.mNode;
  v1->PopUpOverlay.m_MessageQueue.mNode.mNext = &v1->PopUpOverlay.m_MessageQueue.mNode;
  v1->LoadingOverlay.vfptr = (UFG::UIHKLoadingOverlayVtbl *)&UFG::UIHKLoadingOverlay::`vftable';
  v1->SaveLoadOverlay.vfptr = (UFG::UIHKSaveLoadOverlayVtbl *)&UFG::UIHKSaveLoadOverlay::`vftable';
  v5 = &v1->MessageOverlay;
  v5->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKMessageOverlay::`vftable';
  v6 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v6, (UFG::OnlineManagerObserver *)&v1->MessageOverlay.vfptr);
  v5->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v7 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v1->MessageOverlay.mPrev;
  v8 = v1->MessageOverlay.mPrev;
  v9 = v1->MessageOverlay.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  v1->NISOverlay.vfptr = (UFG::UIHK_NISOverlayVtbl *)&UFG::UIHK_NISOverlay::`vftable';
  UFG::UIHK_NISOverlay::mLetterBoxActive = 0;
  UFG::UIHK_NISOverlay::m_curtains.m_state = 0;
  UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  UFG::qString::~qString(&v1->NISOverlay.FrameCounter.mCaption);
  UFG::UIHKTextOverlay::~UIHKTextOverlay(&v1->TextOverlay);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 69
// RVA: 0x631EE0
void __fastcall UFG::UIHKScreenGlobalOverlay::init(UFG::UIHKScreenGlobalOverlay *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rbx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->HelpBar.mChanged = 1;
  UFG::UIHKHelpBarWidget::Update(&v2->HelpBar, (UFG::UIScreen *)&v2->vfptr);
}

// File Line: 79
// RVA: 0x63CFD0
void __fastcall UFG::UIHKScreenGlobalOverlay::update(UFG::UIHKScreenGlobalOverlay *this, float elapsed)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rbx
  char v3; // al
  bool v4; // dl

  v2 = this;
  if ( UFG::UI::gHandleControllerDisconnectHack )
  {
    v3 = UFG::UIHKMessageOverlay::HandleControllerDisconnect();
    v4 = UFG::UI::gHandleControllerDisconnectHack;
    if ( v3 == 1 )
      v4 = 0;
    UFG::UI::gHandleControllerDisconnectHack = v4;
  }
  ((void (__fastcall *)(UFG::UIHKTextOverlay *, UFG::UIHKScreenGlobalOverlay *))v2->TextOverlay.vfptr->update)(
    &v2->TextOverlay,
    v2);
  ((void (__fastcall *)(UFG::UIHK_NISOverlay *, UFG::UIHKScreenGlobalOverlay *))v2->NISOverlay.vfptr->update)(
    &v2->NISOverlay,
    v2);
  ((void (__fastcall *)(UFG::UIHKSaveLoadOverlay *, UFG::UIHKScreenGlobalOverlay *))v2->SaveLoadOverlay.vfptr->update)(
    &v2->SaveLoadOverlay,
    v2);
  ((void (__fastcall *)(UFG::UIHKLoadingOverlay *, UFG::UIHKScreenGlobalOverlay *))v2->LoadingOverlay.vfptr->update)(
    &v2->LoadingOverlay,
    v2);
  ((void (__fastcall *)(UFG::UIHKPopUpNotifier *, UFG::UIHKScreenGlobalOverlay *))v2->PopUpOverlay.vfptr->update)(
    &v2->PopUpOverlay,
    v2);
  ((void (__fastcall *)(UFG::UIHKTutorialOverlay *, UFG::UIHKScreenGlobalOverlay *))v2->TutorialOverlay.vfptr->update)(
    &v2->TutorialOverlay,
    v2);
  UFG::UIScreenInvokeQueue::Update(&UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue, (UFG::UIScreen *)&v2->vfptr);
  UFG::UIHKHelpBarWidget::Update(&v2->HelpBar, (UFG::UIScreen *)&v2->vfptr);
  if ( gPauseVFXEnable != UFG::gTweakerRenderUI )
  {
    gPauseVFXEnable = UFG::gTweakerRenderUI;
    if ( gPauseVFXLock > 0 )
    {
      if ( UFG::gTweakerRenderUI )
        UFG::RenderWorld::FrontEndPauseEffect_Start(0xA6BF4F21);
      else
        UFG::RenderWorld::FrontEndPauseEffect_End(1);
    }
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 166
// RVA: 0x623A10
char __fastcall UFG::UIHKScreenGlobalOverlay::handleMessage(UFG::UIHKScreenGlobalOverlay *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenGlobalOverlay *v3; // rdi
  UFG::UIMessage *v4; // rsi
  unsigned int v5; // ebx
  char result; // al

  v3 = this;
  v4 = msg;
  v5 = msgId;
  this->TextOverlay.vfptr->handleMessage(&this->TextOverlay, (UFG::UIScreen *)this, msgId, msg);
  v3->NISOverlay.vfptr->handleMessage(&v3->NISOverlay, (UFG::UIScreen *)&v3->vfptr, v5, v4);
  ((void (__fastcall *)(UFG::UIHKMessageOverlay *, UFG::UIHKScreenGlobalOverlay *, _QWORD, UFG::UIMessage *))v3->MessageOverlay.vfptr[1].__vecDelDtor)(
    &v3->MessageOverlay,
    v3,
    v5,
    v4);
  v3->SaveLoadOverlay.vfptr->handleMessage(&v3->SaveLoadOverlay, (UFG::UIScreen *)&v3->vfptr, v5, v4);
  v3->LoadingOverlay.vfptr->handleMessage(&v3->LoadingOverlay, (UFG::UIScreen *)&v3->vfptr, v5, v4);
  v3->PopUpOverlay.vfptr->handleMessage(&v3->PopUpOverlay, (UFG::UIScreen *)&v3->vfptr, v5, v4);
  v3->TutorialOverlay.vfptr->handleMessage(&v3->TutorialOverlay, (UFG::UIScreen *)&v3->vfptr, v5, v4);
  UFG::UIHKHelpBarWidget::HandleMessage(&v3->HelpBar, (UFG::UIScreen *)&v3->vfptr, v5, v4);
  if ( v3->m_skookum_dialog_active
    && (v5 == UI_HASH_DIALOG_YES_30
     || v5 == UI_HASH_DIALOG_NO_30
     || v5 == UI_HASH_DIALOG_OK_30
     || v5 == UI_HASH_DIALOG_CANCEL_30
     || v5 == UI_DIALOG_RESULT_1_20
     || v5 == UI_DIALOG_RESULT_2_20
     || v5 == UI_DIALOG_RESULT_3_20) )
  {
    v3->m_skookum_dialog_result = v5;
    v3->m_skookum_dialog_finished = 1;
    result = 1;
  }
  else
  {
    if ( v5 == UI_HASH_GAME_PAUSE_20 )
      Scaleform::GFx::Movie::Invoke(v3->mRenderable->m_movie.pObject, "Race_CountdownFinished", 0i64, 0i64, 0);
    else
      UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
    result = 0;
  }
  return result;
}

// File Line: 218
// RVA: 0x620830
UFG::UIHKScreenGlobalOverlay *__fastcall UFG::UIHKScreenGlobalOverlay::getInstance()
{
  UFG::UIHKScreenGlobalOverlay *result; // rax

  result = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    result = &gGlobalOverlaySentinel;
  return result;
}

// File Line: 229
// RVA: 0x62FBE0
_BOOL8 __fastcall UFG::UIHKScreenGlobalOverlay::hasInstance()
{
  return UFG::UIHKScreenGlobalOverlay::mThis != 0i64;
}

// File Line: 235
// RVA: 0x5FECC0
void __fastcall UFG::UIHKScreenGlobalOverlay::QueueInvoke(UFG::UIScreenInvoke *cmd)
{
  UFG::UIScreenInvokeQueue::Add(&UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue, cmd);
}

// File Line: 241
// RVA: 0x612490
void __fastcall UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(UFG::UIHKScreenGlobalOverlay *this)
{
  *(_WORD *)&this->m_skookum_dialog_active = 1;
}

// File Line: 249
// RVA: 0x5D8A40
void __fastcall UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(UFG::UIHKScreenGlobalOverlay *this)
{
  this->m_skookum_dialog_active = 0;
}

