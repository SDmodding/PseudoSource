// File Line: 38
// RVA: 0x15673B0
__int64 dynamic_initializer_for__UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue__);
}

// File Line: 40
// RVA: 0x156DBF0
__int64 UFG::_dynamic_initializer_for__gGlobalOverlaySentinel__()
{
  UFG::UIHKScreenGlobalOverlay::UIHKScreenGlobalOverlay(&gGlobalOverlaySentinel);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gGlobalOverlaySentinel__);
}

// File Line: 50
// RVA: 0x5C5620
void __fastcall UFG::UIHKScreenGlobalOverlay::UIHKScreenGlobalOverlay(UFG::UIHKScreenGlobalOverlay *this)
{
  UFG::OnlineManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGlobalOverlay::`vftable;
  UFG::UIHKTextOverlay::UIHKTextOverlay(&this->TextOverlay);
  this->NISOverlay.vfptr = (UFG::UIHK_NISOverlayVtbl *)&UFG::UIHK_NISOverlay::`vftable;
  *(_WORD *)&this->NISOverlay.FrameCounter.mChanged = 0;
  UFG::qString::qString(&this->NISOverlay.FrameCounter.mCaption);
  *(_WORD *)&this->NISOverlay.mActive = 0;
  this->NISOverlay.mShouldHideSkipButtonPrompt = 0;
  this->NISOverlay.mSkipButtonTimer = 0.0;
  this->MessageOverlay.mPrev = &this->MessageOverlay.UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->MessageOverlay.mNext = &this->MessageOverlay.UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->MessageOverlay.vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  this->MessageOverlay.vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKMessageOverlay::`vftable;
  this->MessageOverlay.m_bDisconnectedDialogUp = 0;
  v2 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v2, &this->MessageOverlay);
  this->SaveLoadOverlay.vfptr = (UFG::UIHKSaveLoadOverlayVtbl *)&UFG::UIHKSaveLoadOverlay::`vftable;
  this->SaveLoadOverlay.m_fTimeToHideOverlay = 0.0;
  *(_WORD *)&this->SaveLoadOverlay.m_bOverlayVisible = 0;
  this->LoadingOverlay.vfptr = (UFG::UIHKLoadingOverlayVtbl *)&UFG::UIHKLoadingOverlay::`vftable;
  this->PopUpOverlay.vfptr = (UFG::UIHKPopUpNotifierVtbl *)&UFG::UIHKPopUpNotifier::`vftable;
  this->PopUpOverlay.m_MessageQueue.mNode.mPrev = &this->PopUpOverlay.m_MessageQueue.mNode;
  this->PopUpOverlay.m_MessageQueue.mNode.mNext = &this->PopUpOverlay.m_MessageQueue.mNode;
  this->PopUpOverlay.m_eState = STATE_IDLE;
  *(_QWORD *)&this->PopUpOverlay.m_iNumMessages = 0i64;
  this->TutorialOverlay.vfptr = (UFG::UIHKTutorialOverlayVtbl *)&UFG::UIHKTutorialOverlay::`vftable;
  UFG::qString::qString(&this->TutorialOverlay.m_TitleTxt);
  UFG::qString::qString(&this->TutorialOverlay.m_BodyTxt);
  this->TutorialOverlay.m_eState = STATE_IDLE;
  UFG::UIHKHelpBarWidget::UIHKHelpBarWidget(&this->HelpBar);
  this->TimeOfDay.mLightingConditions = LIGHTING_INVALID;
  *(_WORD *)&this->m_skookum_dialog_active = 0;
  this->m_skookum_dialog_result = 0;
  this->m_bIsInactive = 0;
  this->m_iPreviousRichPresenceIndex = -1;
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( this != &gGlobalOverlaySentinel )
    v3 = this;
  UFG::UIHKScreenGlobalOverlay::mThis = v3;
  this->TextOverlay.mScreen = this;
}

// File Line: 62
// RVA: 0x5CAE60
void __fastcall UFG::UIHKScreenGlobalOverlay::~UIHKScreenGlobalOverlay(UFG::UIHKScreenGlobalOverlay *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mPrev; // rcx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mNext; // rax
  UFG::OnlineManager *v5; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v6; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v7; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGlobalOverlay::`vftable;
  UFG::UIHKScreenGlobalOverlay::mThis = 0i64;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "GlobalOverlay");
  UFG::UIHKHelpBarWidget::~UIHKHelpBarWidget(&this->HelpBar);
  this->TutorialOverlay.vfptr = (UFG::UIHKTutorialOverlayVtbl *)&UFG::UIHKTutorialOverlay::`vftable;
  UFG::qString::~qString(&this->TutorialOverlay.m_BodyTxt);
  UFG::qString::~qString(&this->TutorialOverlay.m_TitleTxt);
  this->PopUpOverlay.vfptr = (UFG::UIHKPopUpNotifierVtbl *)&UFG::UIHKPopUpNotifier::`vftable;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->PopUpOverlay.m_MessageQueue);
  mPrev = this->PopUpOverlay.m_MessageQueue.mNode.mPrev;
  mNext = this->PopUpOverlay.m_MessageQueue.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->PopUpOverlay.m_MessageQueue.mNode.mPrev = &this->PopUpOverlay.m_MessageQueue.mNode;
  this->PopUpOverlay.m_MessageQueue.mNode.mNext = &this->PopUpOverlay.m_MessageQueue.mNode;
  this->LoadingOverlay.vfptr = (UFG::UIHKLoadingOverlayVtbl *)&UFG::UIHKLoadingOverlay::`vftable;
  this->SaveLoadOverlay.vfptr = (UFG::UIHKSaveLoadOverlayVtbl *)&UFG::UIHKSaveLoadOverlay::`vftable;
  this->MessageOverlay.vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKMessageOverlay::`vftable;
  v5 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v5, &this->MessageOverlay);
  this->MessageOverlay.vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v6 = this->MessageOverlay.mPrev;
  v7 = this->MessageOverlay.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->MessageOverlay.mPrev = &this->MessageOverlay.UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->MessageOverlay.mNext = &this->MessageOverlay.UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->NISOverlay.vfptr = (UFG::UIHK_NISOverlayVtbl *)&UFG::UIHK_NISOverlay::`vftable;
  UFG::UIHK_NISOverlay::mLetterBoxActive = 0;
  UFG::UIHK_NISOverlay::m_curtains.m_state = STATE_CURTAIN_HIDDEN;
  UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  UFG::qString::~qString(&this->NISOverlay.FrameCounter.mCaption);
  UFG::UIHKTextOverlay::~UIHKTextOverlay(&this->TextOverlay);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 69
// RVA: 0x631EE0
void __fastcall UFG::UIHKScreenGlobalOverlay::init(UFG::UIHKScreenGlobalOverlay *this, UFG::UICommandData *data)
{
  UFG::UIScreen::init(this, data);
  this->HelpBar.mChanged = 1;
  UFG::UIHKHelpBarWidget::Update(&this->HelpBar, this);
}

// File Line: 79
// RVA: 0x63CFD0
void __fastcall UFG::UIHKScreenGlobalOverlay::update(UFG::UIHKScreenGlobalOverlay *this, float elapsed)
{
  char v3; // al
  bool v4; // dl

  if ( UFG::UI::gHandleControllerDisconnectHack )
  {
    v3 = UFG::UIHKMessageOverlay::HandleControllerDisconnect();
    v4 = UFG::UI::gHandleControllerDisconnectHack;
    if ( v3 == 1 )
      v4 = 0;
    UFG::UI::gHandleControllerDisconnectHack = v4;
  }
  ((void (__fastcall *)(UFG::UIHKTextOverlay *, UFG::UIHKScreenGlobalOverlay *))this->TextOverlay.vfptr->update)(
    &this->TextOverlay,
    this);
  ((void (__fastcall *)(UFG::UIHK_NISOverlay *, UFG::UIHKScreenGlobalOverlay *))this->NISOverlay.vfptr->update)(
    &this->NISOverlay,
    this);
  ((void (__fastcall *)(UFG::UIHKSaveLoadOverlay *, UFG::UIHKScreenGlobalOverlay *))this->SaveLoadOverlay.vfptr->update)(
    &this->SaveLoadOverlay,
    this);
  ((void (__fastcall *)(UFG::UIHKLoadingOverlay *, UFG::UIHKScreenGlobalOverlay *))this->LoadingOverlay.vfptr->update)(
    &this->LoadingOverlay,
    this);
  ((void (__fastcall *)(UFG::UIHKPopUpNotifier *, UFG::UIHKScreenGlobalOverlay *))this->PopUpOverlay.vfptr->update)(
    &this->PopUpOverlay,
    this);
  ((void (__fastcall *)(UFG::UIHKTutorialOverlay *, UFG::UIHKScreenGlobalOverlay *))this->TutorialOverlay.vfptr->update)(
    &this->TutorialOverlay,
    this);
  UFG::UIScreenInvokeQueue::Update(&UFG::UIHKScreenGlobalOverlay::mScreenInvokeQueue, this);
  UFG::UIHKHelpBarWidget::Update(&this->HelpBar, this);
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
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 166
// RVA: 0x623A10
char __fastcall UFG::UIHKScreenGlobalOverlay::handleMessage(
        UFG::UIHKScreenGlobalOverlay *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  this->TextOverlay.vfptr->handleMessage(&this->TextOverlay, this, msgId, msg);
  this->NISOverlay.vfptr->handleMessage(&this->NISOverlay, this, msgId, msg);
  ((void (__fastcall *)(UFG::UIHKMessageOverlay *, UFG::UIHKScreenGlobalOverlay *, _QWORD, UFG::UIMessage *))this->MessageOverlay.vfptr[1].__vecDelDtor)(
    &this->MessageOverlay,
    this,
    msgId,
    msg);
  this->SaveLoadOverlay.vfptr->handleMessage(&this->SaveLoadOverlay, this, msgId, msg);
  this->LoadingOverlay.vfptr->handleMessage(&this->LoadingOverlay, this, msgId, msg);
  this->PopUpOverlay.vfptr->handleMessage(&this->PopUpOverlay, this, msgId, msg);
  this->TutorialOverlay.vfptr->handleMessage(&this->TutorialOverlay, this, msgId, msg);
  UFG::UIHKHelpBarWidget::HandleMessage(&this->HelpBar, this, msgId, msg);
  if ( this->m_skookum_dialog_active
    && (msgId == UI_HASH_DIALOG_YES_30
     || msgId == UI_HASH_DIALOG_NO_30
     || msgId == UI_HASH_DIALOG_OK_30
     || msgId == UI_HASH_DIALOG_CANCEL_30
     || msgId == UI_DIALOG_RESULT_1_20
     || msgId == UI_DIALOG_RESULT_2_20
     || msgId == UI_DIALOG_RESULT_3_20) )
  {
    this->m_skookum_dialog_result = msgId;
    this->m_skookum_dialog_finished = 1;
    return 1;
  }
  else
  {
    if ( msgId == UI_HASH_GAME_PAUSE_20 )
      Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Race_CountdownFinished", 0i64, 0i64, 0);
    else
      UFG::UIScreen::handleMessage(this, msgId, msg);
    return 0;
  }
}

// File Line: 218
// RVA: 0x620830
UFG::UIHKScreenGlobalOverlay *__fastcall UFG::UIHKScreenGlobalOverlay::getInstance()
{
  UFG::UIHKScreenGlobalOverlay *result; // rax

  result = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    return &gGlobalOverlaySentinel;
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

