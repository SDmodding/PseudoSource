// File Line: 42
// RVA: 0x5C4EE0
void __fastcall UFG::UIHKScreenDemoClosing::UIHKScreenDemoClosing(UFG::UIHKScreenDemoClosing *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDemoClosing::`vftable';
  this->mPushHudOnExit = 0;
}

// File Line: 47
// RVA: 0x5CA750
void __fastcall UFG::UIHKScreenDemoClosing::~UIHKScreenDemoClosing(UFG::UIHKScreenDemoClosing *this)
{
  UFG::UIHKScreenDemoClosing *v1; // rbx
  UFG::UI *v2; // rcx
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDemoClosing::`vftable';
  UFG::UI::UnpauseGame((UFG::UI *)this);
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v3 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v3 == 1) )
        UFG::UI::ResetGameplayInput(v2);
    }
  }
  UFG::UIHKScreenDemoClosing::EntryPoint = 0;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v4, "DemoClosing");
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 59
// RVA: 0x630560
void __fastcall UFG::UIHKScreenDemoClosing::init(UFG::UIHKScreenDemoClosing *this, UFG::UICommandData *data)
{
  UFG::UICommandData *v2; // rsi
  UFG::UIHKScreenDemoClosing *v3; // rdi
  UFG::Controller *v4; // rdx
  Scaleform::GFx::Movie *v5; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h]

  v2 = data;
  v3 = this;
  UFG::UI::PauseGame(0i64);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v4->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v4->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v5 = v3->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 0;
  if ( UFG::UIHKScreenDemoClosing::EntryPoint == 1 )
  {
    value.Type = 2;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(v5, "mc_playMore._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.mValue.BValue = 0;
  }
  else
  {
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v5, "mc_playMore._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.mValue.BValue = 1;
  }
  value.Type = 2;
  Scaleform::GFx::Movie::SetVariable(v5, "mc_comingSummer._visible", &value, 1i64);
  UFG::UIScreen::init((UFG::UIScreen *)&v3->vfptr, v2);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 97
// RVA: 0x63A1C0
void __fastcall UFG::UIHKScreenDemoClosing::render(UFG::UIScreen *this)
{
  UFG::UIScreenRenderable::render(this->mRenderable);
}

// File Line: 103
// RVA: 0x6225A0
bool __fastcall UFG::UIHKScreenDemoClosing::handleMessage(UFG::UIHKScreenDemoClosing *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIHKScreenDemoClosing *v5; // rbx
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSetup *v8; // rax

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
    if ( UFG::UIHKScreenDemoClosing::EntryPoint == 1 )
    {
      v5->mPushHudOnExit = 1;
      return 1;
    }
    goto LABEL_7;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 && UFG::UIHKScreenDemoClosing::EntryPoint == 1 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
LABEL_7:
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UI_HASH_QUIT_TO_MAIN_MENU_20,
      0xFFFFFFFF);
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
      *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      "OpeningCredits");
    UFG::UIHKScreenHud::ResetWidgets();
    if ( (unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_13) )
    {
      UFG::UIScreenManagerBase::queuePushScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        "MainMenu",
        -1);
    }
    else
    {
      v7 = UFG::ProgressionTracker::Instance();
      v8 = UFG::ProgressionTracker::GetGameSetup(v7);
      UFG::GameSetup::SetInitMenu(v8, "MainMenu");
    }
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

