// File Line: 42
// RVA: 0x5C4EE0
void __fastcall UFG::UIHKScreenDemoClosing::UIHKScreenDemoClosing(UFG::UIHKScreenDemoClosing *this)
{
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDemoClosing::`vftable;
  this->mPushHudOnExit = 0;
}

// File Line: 47
// RVA: 0x5CA750
void __fastcall UFG::UIHKScreenDemoClosing::~UIHKScreenDemoClosing(UFG::UIHKScreenDemoClosing *this)
{
  UFG::UI *v2; // rcx
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDemoClosing::`vftable;
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
  UFG::UIHKScreenDemoClosing::EntryPoint = ENTRY_DEMO_OVER;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v4, "DemoClosing");
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 59
// RVA: 0x630560
void __fastcall UFG::UIHKScreenDemoClosing::init(UFG::UIHKScreenDemoClosing *this, UFG::UICommandData *data)
{
  UFG::Controller *v4; // rdx
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h] BYREF

  UFG::UI::PauseGame(0i64);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v4->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v4->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Undefined;
  if ( UFG::UIHKScreenDemoClosing::EntryPoint == ENTRY_MORE_PROMPT )
  {
    value.Type = VT_Boolean;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_playMore._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.mValue.BValue = 0;
  }
  else
  {
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_playMore._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.mValue.BValue = 1;
  }
  value.Type = VT_Boolean;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_comingSummer._visible", &value, 1i64);
  UFG::UIScreen::init(this, data);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 97
// RVA: 0x63A1C0
void __fastcall UFG::UIHKScreenDemoClosing::render(UFG::UIScreen *this)
{
  UFG::UIScreenRenderable::render(this->mRenderable);
}

// File Line: 103
// RVA: 0x6225A0
bool __fastcall UFG::UIHKScreenDemoClosing::handleMessage(
        UFG::UIHKScreenDemoClosing *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSetup *GameSetup; // rax

  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
    if ( UFG::UIHKScreenDemoClosing::EntryPoint == ENTRY_MORE_PROMPT )
    {
      this->mPushHudOnExit = 1;
      return 1;
    }
    goto LABEL_7;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 && UFG::UIHKScreenDemoClosing::EntryPoint == ENTRY_MORE_PROMPT )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
LABEL_7:
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_QUIT_TO_MAIN_MENU_20, 0xFFFFFFFF);
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
      *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
    UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "OpeningCredits");
    UFG::UIHKScreenHud::ResetWidgets();
    if ( (unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_13) )
    {
      UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, "MainMenu", -1);
    }
    else
    {
      v7 = UFG::ProgressionTracker::Instance();
      GameSetup = UFG::ProgressionTracker::GetGameSetup(v7);
      UFG::GameSetup::SetInitMenu(GameSetup, "MainMenu");
    }
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

