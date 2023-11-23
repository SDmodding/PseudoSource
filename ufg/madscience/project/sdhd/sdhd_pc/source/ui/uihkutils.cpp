// File Line: 100
// RVA: 0x156DC70
__int64 UFG::UI::_dynamic_initializer_for__gOldFocus__()
{
  Render::DepthOfField::Focus::Focus(&gOldFocus);
  return atexit((int (__fastcall *)())UFG::UI::_dynamic_atexit_destructor_for__gOldFocus__);
}

// File Line: 133
// RVA: 0x5E79A0
char *__fastcall UFG::UI::GetGamepadButtonTextureName(UFG::UI::eButtons button, bool remappable)
{
  char *result; // rax

  switch ( button )
  {
    case ACCEPT_BUTTON:
      if ( remappable )
        goto $LN44_3;
      result = "BUTTON_BACK";
      if ( !gButtonsSwapped )
        goto $LN44_3;
      break;
    case BACK_BUTTON:
      if ( remappable )
        goto $LN46_5;
      result = "BUTTON_ACCEPT";
      if ( !gButtonsSwapped )
        goto $LN46_5;
      break;
    case BUTTON1_BUTTON:
    case BUTTON1_BUTTON_HOLD:
      result = "BUTTON_BUTTON1";
      break;
    case BUTTON2_BUTTON:
    case BUTTON2_BUTTON_HOLD:
      result = "BUTTON_BUTTON2";
      break;
    case START_BUTTON:
      result = "BUTTON_START";
      break;
    case SELECT_BUTTON:
      result = "BUTTON_SELECT";
      break;
    case L1_BUTTON:
    case L1_BUTTON_HOLD:
      result = "BUTTON_L1";
      break;
    case R1_BUTTON:
    case R1_BUTTON_HOLD:
      result = "BUTTON_R1";
      break;
    case L2_BUTTON:
    case L2_BUTTON_HOLD:
      result = "BUTTON_L2";
      break;
    case R2_BUTTON:
    case R2_BUTTON_HOLD:
      result = "BUTTON_R2";
      break;
    case L3_BUTTON:
      result = "BUTTON_L3";
      break;
    case R3_BUTTON:
      result = "BUTTON_R3";
      break;
    case L1R1_BUTTON:
      result = "BUTTON_L1R1";
      break;
    case L2R2_BUTTON:
      result = "BUTTON_L2R2";
      break;
    case DPAD_UP_BUTTON:
      result = "BUTTON_DPAD_UP";
      break;
    case DPAD_DOWN_BUTTON:
      result = "BUTTON_DPAD_DOWN";
      break;
    case DPAD_LEFT_BUTTON:
      result = "BUTTON_DPAD_LEFT";
      break;
    case DPAD_RIGHT_BUTTON:
      result = "BUTTON_DPAD_RIGHT";
      break;
    case DPAD_LR_BUTTON:
      result = "BUTTON_DPAD_LR";
      break;
    case DPAD_UD_BUTTON:
      result = "BUTTON_DPAD_UD";
      break;
    case L_STICK_BUTTON:
      result = "BUTTON_L_STICK";
      break;
    case R_STICK_BUTTON:
      result = "BUTTON_R_STICK";
      break;
    case L_STICK_LR_BUTTON:
      result = "BUTTON_L_STICK_LR";
      break;
    case L_STICK_UD_BUTTON:
      result = "BUTTON_L_STICK_UD";
      break;
    case R_STICK_LR_BUTTON:
      result = "BUTTON_R_STICK_LR";
      break;
    case R_STICK_UD_BUTTON:
      result = "BUTTON_R_STICK_UD";
      break;
    case ACCEPT_BUTTON_HOLD:
$LN44_3:
      result = "BUTTON_ACCEPT";
      break;
    case BACK_BUTTON_HOLD:
$LN46_5:
      result = "BUTTON_BACK";
      break;
    case F1_BUTTON:
      result = "BUTTON_F1";
      break;
    case WHEEL_UP_BUTTON:
    case WHEEL_DOWN_BUTTON:
      result = "INVALID";
      break;
    default:
      result = &customCaption;
      break;
  }
  return result;
}

// File Line: 191
// RVA: 0x5E80C0
char *__fastcall UFG::UI::GetKeyboardButtonTextureNameNonRemappable(UFG::UI::eButtons button)
{
  char *result; // rax

  switch ( button )
  {
    case ACCEPT_BUTTON:
    case START_BUTTON:
    case ACCEPT_BUTTON_HOLD:
      result = "BUTTON_ENTER";
      break;
    case BACK_BUTTON:
    case BACK_BUTTON_HOLD:
      result = "BUTTON_BACKSPACE";
      break;
    case BUTTON1_BUTTON:
    case BUTTON1_BUTTON_HOLD:
      result = "BUTTON_Q";
      break;
    case BUTTON2_BUTTON:
    case BUTTON2_BUTTON_HOLD:
      result = "BUTTON_E";
      break;
    case SELECT_BUTTON:
      result = "BUTTON_TAB";
      break;
    case L1_BUTTON:
    case L2_BUTTON:
    case L1_BUTTON_HOLD:
    case L2_BUTTON_HOLD:
      result = "BUTTON_LCTRL";
      break;
    case R1_BUTTON:
    case R1_BUTTON_HOLD:
      result = "BUTTON_RCTRL";
      break;
    case R2_BUTTON:
    case R2_BUTTON_HOLD:
      result = "BUTTON_LSHIFT";
      break;
    case L3_BUTTON:
      result = "BUTTON_M";
      break;
    case R3_BUTTON:
      result = "BUTTON_T";
      break;
    case L1R1_BUTTON:
      result = "BUTTON_CTRL";
      break;
    case L2R2_BUTTON:
      result = "BUTTON_MOUSE_M";
      break;
    case DPAD_UP_BUTTON:
      result = "BUTTON_ARROW_U";
      break;
    case DPAD_DOWN_BUTTON:
      result = "BUTTON_ARROW_D";
      break;
    case DPAD_LEFT_BUTTON:
      result = "BUTTON_ARROW_L";
      break;
    case DPAD_RIGHT_BUTTON:
      result = "BUTTON_ARROW_R";
      break;
    case DPAD_LR_BUTTON:
    case L_STICK_LR_BUTTON:
    case R_STICK_LR_BUTTON:
      result = "BUTTON_ARROW_LR";
      break;
    case DPAD_UD_BUTTON:
    case L_STICK_UD_BUTTON:
    case R_STICK_UD_BUTTON:
      result = "BUTTON_ARROW_UD";
      break;
    case L_STICK_BUTTON:
    case R_STICK_BUTTON:
      result = "BUTTON_MOUSE";
      break;
    case F1_BUTTON:
      result = "BUTTON_F1";
      break;
    case WHEEL_UP_BUTTON:
      result = "BUTTON_MOUSE_M_U";
      break;
    case WHEEL_DOWN_BUTTON:
      result = "BUTTON_MOUSE_M_D";
      break;
    default:
      result = &customCaption;
      break;
  }
  return result;
}

// File Line: 286
// RVA: 0x5E6DC0
__int64 __fastcall UFG::UI::GetButton(const char *text)
{
  int v3; // eax
  unsigned int v4; // ecx

  if ( !text )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_ACCEPT", -1) )
    return 1i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_BACK", -1) )
    return 2i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_BUTTON1", -1) )
    return 3i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_BUTTON2", -1) )
    return 4i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L1", -1) )
    return 7i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L2", -1) )
    return 9i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_R1", -1) )
    return 8i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_R2", -1) )
    return 10i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L1R1", -1) )
    return 13i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L2R2", -1) )
    return 14i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_DPAD_UP", -1) )
    return 15i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_DPAD_DOWN", -1) )
    return 16i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_DPAD_LEFT", -1) )
    return 17i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_DPAD_RIGHT", -1) )
    return 18i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_DPAD_LR", -1) )
    return 19i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_DPAD_UD", -1) )
    return 20i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L_STICK", -1) )
    return 21i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_R_STICK", -1) )
    return 22i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_SELECT", -1) )
    return 6i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_START", -1) )
    return 5i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_ACCEPT_HOLD", -1) )
    return 27i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_BACK_HOLD", -1) )
    return 28i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_BUTTON1_HOLD", -1) )
    return 29i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_BUTTON2_HOLD", -1) )
    return 30i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L1_HOLD", -1) )
    return 31i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_R1_HOLD", -1) )
    return 32i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_L2_HOLD", -1) )
    return 33i64;
  v3 = UFG::qStringCompare(text, "BUTTON_R2_HOLD", -1);
  v4 = 0;
  if ( !v3 )
    return 34;
  return v4;
}

// File Line: 427
// RVA: 0x5ED5D0
void __fastcall UFG::UI::InitHDSettings(UFG::UI *this)
{
  gUIHorizontalResolution = (float)Render::GetBackBufferTarget()->mWidth;
  gUIVerticalResolution = (float)Render::GetBackBufferTarget()->mHeight;
  gIsUIHighDef = gUIVerticalResolution >= 720.0;
}

// File Line: 478
// RVA: 0x5EE290
_BOOL8 __fastcall UFG::UI::IsInHDMode()
{
  return gIsUIHighDef;
}

// File Line: 496
// RVA: 0x6008B0
void __fastcall UFG::UI::RefreshScreenHD(UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Boolean;
  pargs.mValue.BValue = gIsUIHighDef;
  Scaleform::GFx::Movie::Invoke(pObject, "HandleHighDef", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 505
// RVA: 0x603B50
void __fastcall UFG::UI::ScreenInitCallback(UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v3; // xmm6_8
  double v4; // xmm6_8
  UFG::GameStatTracker *v5; // rax
  Scaleform::GFx::Value::ValueUnion v6; // xmm6_8
  const char *LanguageString; // rdi
  bool v8; // di
  Scaleform::GFx::Value pargs; // [rsp+28h] [rbp-59h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+58h] [rbp-29h] BYREF
  char v11[16]; // [rsp+88h] [rbp+7h] BYREF
  __int64 v12; // [rsp+98h] [rbp+17h]
  int v13; // [rsp+A0h] [rbp+1Fh]
  double v14; // [rsp+A8h] [rbp+27h]
  __int64 v15; // [rsp+B8h] [rbp+37h]

  v15 = -2i64;
  UFG::UI::RefreshScreenHD(screen);
  pObject = screen->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Undefined;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3.NValue = gUIHorizontalResolution;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue = v3;
  v4 = gUIVerticalResolution;
  if ( (v13 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(v12, v11, COERCE_DOUBLE(*(_QWORD *)&v14));
    v12 = 0i64;
  }
  v13 = 5;
  v14 = v4;
  Scaleform::GFx::Movie::Invoke(pObject, "HandleResolution", 0i64, &ptr, 2u);
  v5 = UFG::GameStatTracker::Instance();
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (float)((float)((float)((float)(int)UFG::GameStatTracker::GetStat(v5, UIScale) * 0.1)
                                      * 0.15000001)
                              + 0.85000002);
  Scaleform::GFx::Movie::Invoke(pObject, "HandleUIScale", 0i64, &pargs, 1u);
  v6.NValue = (double)UFG::UI::gPlatform;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v6;
  Scaleform::GFx::Movie::Invoke(pObject, "HandlePlatform", 0i64, &pargs, 1u);
  LanguageString = UFG::UIGfxTranslator::getLanguageString(UFG::UIScreenManager::s_instance->m_translator);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_String;
  pargs.mValue.pString = LanguageString;
  Scaleform::GFx::Movie::Invoke(pObject, "HandleLanguage", 0i64, &pargs, 1u);
  v8 = gButtonsSwapped;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Boolean;
  pargs.mValue.BValue = v8;
  Scaleform::GFx::Movie::Invoke(pObject, "HandleButtonsSwapped", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 532
// RVA: 0x5FF020
void __fastcall UFG::UI::QuitGame(const char *frontEndScreen)
{
  const char *v1; // rbx
  UFG::ProgressionTracker *v2; // rax
  UFG::GameSetup *GameSetup; // rax

  v1 = "MainMenu";
  if ( frontEndScreen )
    v1 = frontEndScreen;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_QUIT_TO_MAIN_MENU_20, 0xFFFFFFFF);
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
  UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "OpeningCredits");
  UFG::UIHKScreenHud::ResetWidgets();
  if ( (unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_13) )
  {
    UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, v1, -1);
  }
  else
  {
    v2 = UFG::ProgressionTracker::Instance();
    GameSetup = UFG::ProgressionTracker::GetGameSetup(v2);
    UFG::GameSetup::SetInitMenu(GameSetup, v1);
  }
}

// File Line: 552
// RVA: 0x5F3910
char __fastcall UFG::UI::PauseGame(const char *pauseScreen)
{
  unsigned int CurrentState; // ebx
  UFG::GameState *GameStateObj; // rax
  UFG::GameState *v4; // rsi
  ANTLR3_INPUT_STREAM_struct *v6; // rax
  unsigned int v7; // edx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::SimComponent *CurrentGameCamera; // rax
  UFG::SimComponent *v10; // rbx
  _BOOL8 v11; // r8

  CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
  v4 = GameStateObj;
  if ( CurrentState != uidGameStateInGame_13 || !GameStateObj )
    return 0;
  if ( (unsigned int)UFG::qStringCompare(pauseScreen, "NISPause", -1) )
  {
    v6 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    v7 = 16;
  }
  else
  {
    v6 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    v7 = 32;
  }
  UFG::UIScreenTextureManager::SetGameState(v6, v7);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_GAME_PAUSE_20, 0xFFFFFFFF);
  if ( pauseScreen )
  {
    UFG::qString::Set(&v4->mGameStateUserDataStr, pauseScreen);
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v8, pauseScreen, 0i64);
  }
  CurrentGameCamera = (UFG::SimComponent *)UFG::GetCurrentGameCamera();
  v10 = CurrentGameCamera;
  if ( CurrentGameCamera )
  {
    if ( UFG::SimComponent::IsType(CurrentGameCamera, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
      v10->vfptr[20].__vecDelDtor(v10, 0);
  }
  UFG::InputSystem::SetShouldRestrictCursor(0, 0, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 0, 1, 0);
  UFG::InputSystem::msRelativeMouseMode = 0;
  LOBYTE(v11) = 1;
  v4->vfptr->ModeSet(v4, eGSM_PAUSED, v11);
  return 1;
}

// File Line: 605
// RVA: 0x6132A0
void __fastcall UFG::UI::UnpauseGame(UFG::UI *this)
{
  unsigned int CurrentState; // eax
  UFG::GameState *GameStateObj; // rax
  UFG::SimComponent *CurrentGameCamera; // rax
  UFG::SimComponent *v4; // rbx
  __int64 v5; // rdx
  ANTLR3_INPUT_STREAM_struct *v6; // rax

  CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
  ((void (__fastcall *)(UFG::GameState *, __int64))GameStateObj->vfptr->ModeSet)(GameStateObj, 1i64);
  UFG::InputSystem::SetShouldRestrictCursor(0, 1, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
  UFG::InputSystem::msRelativeMouseMode = 1;
  CurrentGameCamera = (UFG::SimComponent *)UFG::GetCurrentGameCamera();
  v4 = CurrentGameCamera;
  if ( CurrentGameCamera
    && UFG::SimComponent::IsType(CurrentGameCamera, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
  {
    LOBYTE(v5) = 1;
    v4->vfptr[20].__vecDelDtor(v4, v5);
  }
  v6 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::SetGameState(v6, 2u);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_GAME_UNPAUSE_20, 0xFFFFFFFF);
}

// File Line: 637
// RVA: 0x5EE1B0
UFG::GameState *__fastcall UFG::UI::IsGamePaused()
{
  unsigned int CurrentState; // eax
  UFG::GameState *result; // rax
  UFG::GameState *v2; // rdi
  unsigned __int8 v3; // bl

  CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  result = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
  v2 = result;
  if ( result )
  {
    if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
      return 0;
    v3 = 1;
    if ( !v2->vfptr->ModeIsSet(v2, eGSM_PAUSED) )
      return 0;
    return (UFG::GameState *)v3;
  }
  return result;
}

// File Line: 669
// RVA: 0x613010
char __fastcall UFG::UI::TryNISPause()
{
  if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateInGame_13 )
    return 0;
  if ( (unsigned __int8)UFG::UI::IsGamePaused()
    || UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    return 1;
  }
  return UFG::UI::PauseGame("NISPause");
}

// File Line: 686
// RVA: 0x5F1CC0
void __fastcall UFG::UI::LockGameplayInput(UFG::UI *this)
{
  UFG::Controller *v1; // rdx

  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v1 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v1->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v1->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
}

// File Line: 703
// RVA: 0x613270
void __fastcall UFG::UI::UnlockGameplayInput(UFG::UI *this)
{
  unsigned int v1; // eax

  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v1 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v1 == 1) )
        UFG::UI::ResetGameplayInput(this);
    }
  }
}

// File Line: 725
// RVA: 0x602930
void __fastcall UFG::UI::ResetInputCounterHack(UFG::UI *counter)
{
  UFG::UI::gUIInputLocked = (unsigned int)counter;
  if ( !(_DWORD)counter )
    UFG::UI::ResetGameplayInput(counter);
}

// File Line: 736
// RVA: 0x6028C0
void __fastcall UFG::UI::ResetGameplayInput(UFG::UI *this)
{
  UFG::Controller *v1; // rdx

  UFG::UI::gUIInputLocked = 0;
  if ( UFG::gInputSystem )
  {
    v1 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( g_saved_gameplay_controller_mode )
    {
      UFG::SetInputMode(g_saved_gameplay_controller_mode, v1->mControllerIndex);
      g_saved_gameplay_controller_mode = IM_INVALID;
    }
    else if ( v1->m_ActiveMapSet == 8 )
    {
      UFG::SetInputMode(IM_ON_FOOT, v1->mControllerIndex);
    }
  }
}

// File Line: 767
// RVA: 0x5E89E0
char __fastcall UFG::UI::GetPlayerWorldPosition(UFG::qVector3 *pos, UFG::qVector3 *dir)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  char result; // al
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float x; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4

  if ( UFG::UI::gUpdateWorldPos )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    if ( !LocalPlayer )
      return 0;
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    if ( !m_pTransformNodeComponent )
      return 0;
    UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    cachedPos.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    cachedPos.y = y;
    cachedPos.z = z;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v9 = m_pTransformNodeComponent->mWorldTransform.v0.y;
    v10 = m_pTransformNodeComponent->mWorldTransform.v0.z;
    x = m_pTransformNodeComponent->mWorldTransform.v0.x;
    UFG::UI::gUpdateWorldPos = 0;
    cachedDir.x = x;
    cachedDir.y = v9;
    cachedDir.z = v10;
  }
  v12 = cachedPos.y;
  v13 = cachedPos.z;
  result = 1;
  pos->x = cachedPos.x;
  pos->y = v12;
  pos->z = v13;
  v14 = cachedDir.y;
  v15 = cachedDir.z;
  dir->x = cachedDir.x;
  dir->y = v14;
  dir->z = v15;
  return result;
}

// File Line: 828
// RVA: 0x5F1C00
const char *__fastcall UFG::UI::LocalizeText(const char *tag)
{
  const char *v1; // rbx
  const char *result; // rax
  unsigned int v3; // eax
  UFG::UIGfxTranslator *m_translator; // rcx

  v1 = tag;
  if ( !tag )
    return 0i64;
  if ( *tag == 36 )
    v1 = tag + 1;
  v3 = UFG::qStringHashUpper32(v1, -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator )
    return v1;
  result = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v3);
  if ( !result )
    return v1;
  return result;
}

// File Line: 849
// RVA: 0x5E8980
char *__fastcall UFG::UI::GetPlayerDisplayName()
{
  UFG::OnlineManager *v0; // rax
  char *mData; // r8
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v0 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::GetOnlineName(v0, &result);
  mData = "Wei Shen";
  if ( result.mLength )
    mData = result.mData;
  UFG::qStringCopy(displayName, 512, mData, -1);
  UFG::qString::~qString(&result);
  return displayName;
}

// File Line: 863
// RVA: 0x5EE420
UFG::GameSlice *__fastcall UFG::UI::IsMissionActive(bool includeEvents)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::GameSlice *result; // rax
  UFG::GameSlice *v4; // rdx

  v2 = UFG::ProgressionTracker::Instance();
  result = UFG::ProgressionTracker::GetActiveMaster(v2);
  v4 = result;
  if ( result )
  {
    LOBYTE(result) = !result->mInternalSlice && (unsigned int)(result->mType - 6) <= 5;
    if ( includeEvents && v4->mType == 5 )
      return (UFG::GameSlice *)((unsigned __int8)result | 1u);
    else
      return (UFG::GameSlice *)(unsigned __int8)result;
  }
  return result;
}

// File Line: 888
// RVA: 0x5EE490
unsigned __int8 __fastcall UFG::UI::IsMissionWithCheckpointsActive(bool includeEvents)
{
  unsigned __int8 result; // al
  UFG::ProgressionTracker *v2; // rbx
  UFG::GameSlice *ActiveMaster; // rdi
  UFG::GameSlice *LastCheckpoint; // rax

  result = (unsigned __int8)UFG::UI::IsMissionActive(includeEvents);
  if ( result )
  {
    v2 = UFG::ProgressionTracker::Instance();
    ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v2);
    LastCheckpoint = UFG::ProgressionTracker::GetLastCheckpoint(v2);
    return ActiveMaster
        && LastCheckpoint
        && (LastCheckpoint == ActiveMaster || UFG::GameSlice::GetParent(LastCheckpoint) == ActiveMaster);
  }
  return result;
}

// File Line: 913
// RVA: 0x5EE720
char __fastcall UFG::UI::IsPlayerInWater()
{
  return UFG::SimObjectUtility::IsInWater(LocalPlayer);
}

// File Line: 919
// RVA: 0x5EE690
bool __fastcall UFG::UI::IsPlayerInVehicle()
{
  signed __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfType; // rax

  if ( LocalPlayer
    && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                LocalPlayer,
                                                                UFG::CharacterSubjectComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                LocalPlayer,
                                                                UFG::CharacterSubjectComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer)),
        ComponentOfType) )
  {
    return ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))ComponentOfType->vfptr[42].__vecDelDtor)(ComponentOfType);
  }
  else
  {
    return 0;
  }
}

// File Line: 926
// RVA: 0x5EE730
bool __fastcall UFG::UI::IsPlayerVehiclePassenger()
{
  signed __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  unsigned int mTargetType; // ecx
  int v3; // eax
  bool result; // al

  result = 0;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      mTargetType = m_pComponent->mTargetType;
      if ( mTargetType > eTARGET_TYPE_VEHICLE_PASSENGER_TRUNK )
        return 1;
      v3 = 0x2210;
      if ( !_bittest(&v3, mTargetType) )
        return 1;
    }
  }
  return result;
}

// File Line: 933
// RVA: 0x5EE680
bool __fastcall UFG::UI::IsPlayerInCombat()
{
  return UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0);
}

// File Line: 939
// RVA: 0x5E7950
__int64 __fastcall UFG::UI::GetFlashArgsInt(UFG::UIMessage *msg)
{
  unsigned int v2; // ebx
  UFG::qString v3; // [rsp+28h] [rbp-30h] BYREF

  if ( !msg )
    return 0i64;
  UFG::qString::qString(&v3, (UFG::qString *)&msg[1]);
  v2 = UFG::qToInt32(v3.mData, 0);
  UFG::qString::~qString(&v3);
  return v2;
}

// File Line: 963
// RVA: 0x603AB0
void __fastcall UFG::UI::ScaleViewCoordsToUIScreen(UFG::UIScreen *screen, float *posX, float *posY)
{
  Illusion::Target *BackBufferTarget; // rsi
  float v7; // xmm0_4
  Scaleform::GFx::MovieDef *pObject; // rcx
  Scaleform::GFx::ResourceVtbl *vfptr; // rax

  BackBufferTarget = Render::GetBackBufferTarget();
  v7 = ((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)(screen->mRenderable->m_movieDef.pObject);
  pObject = screen->mRenderable->m_movieDef.pObject;
  vfptr = pObject->Scaleform::GFx::Resource::vfptr;
  *posX = (float)((float)(int)v7 / (float)BackBufferTarget->mWidth) * *posX;
  *posY = (float)((float)(int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))vfptr[1].GetResourceReport)(pObject)
                / (float)BackBufferTarget->mHeight)
        * *posY;
}

// File Line: 1123
// RVA: 0x5E6640
void __fastcall UFG::UI::FormatMoneyStr(int money, UFG::qString *string)
{
  int v2; // r9d
  unsigned int v3; // r9d
  int v4; // [rsp+20h] [rbp-18h]

  v2 = abs32(money);
  if ( v2 < 1000000 )
  {
    if ( v2 < 1000 )
      UFG::qString::Format(string, "%d", (unsigned int)money);
    else
      UFG::qString::Format(string, "%d,%03d", (unsigned int)(money / 1000), (unsigned int)(v2 % 1000));
  }
  else
  {
    v4 = v2 % 1000;
    v3 = (int)((unsigned __int64)(274877907i64 * (v2 % 1000000)) >> 32) >> 6;
    UFG::qString::Format(string, "%d,%03d,%03d", (unsigned int)(money / 1000000), (v3 >> 31) + v3, v4);
  }
}

// File Line: 1148
// RVA: 0x5E7550
UFG::qString *__fastcall UFG::UI::GetDateString(UFG::qString *result, unsigned __int64 systemTime, bool includeSeconds)
{
  __int64 mDay; // r9
  __int64 mMonth; // r8
  int mYear; // r10d
  const char *v7; // rdx
  int v9; // [rsp+20h] [rbp-40h]
  int mHour; // [rsp+28h] [rbp-38h]
  int mMinute; // [rsp+30h] [rbp-30h]
  int mSecond; // [rsp+38h] [rbp-28h]
  int v13; // [rsp+40h] [rbp-20h]
  UFG::qDateTime date_time; // [rsp+50h] [rbp-10h] BYREF

  UFG::qConvertSystemTimeToDateTime(&date_time, systemTime);
  UFG::qString::qString(result);
  v13 = 1;
  switch ( UFG::UIScreenManager::s_instance->m_translator->mLanguage )
  {
    case eLang_English:
      mDay = date_time.mDay;
      mMonth = date_time.mMonth;
      goto LABEL_5;
    case eLang_Japanese:
      mYear = date_time.mDay;
      mDay = date_time.mMonth;
      mMonth = date_time.mYear;
      mSecond = date_time.mSecond;
      mMinute = date_time.mMinute;
      mHour = date_time.mHour;
      v7 = "%04d/%02d/%02d %02d:%02d:%02d";
      break;
    default:
      mDay = date_time.mMonth;
      mMonth = date_time.mDay;
LABEL_5:
      mSecond = date_time.mSecond;
      mMinute = date_time.mMinute;
      mHour = date_time.mHour;
      mYear = date_time.mYear;
      v7 = "%02d/%02d/%04d %02d:%02d:%02d";
      break;
  }
  v9 = mYear;
  UFG::qString::Format(result, v7, mMonth, mDay, v9, mHour, mMinute, mSecond, v13, -2i64);
  return result;
}

// File Line: 1244
// RVA: 0x5EB870
void __fastcall UFG::UI::HandleGameCheckpointRestore(UFG::UI *this)
{
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
  UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "OpeningCredits");
  UFG::UIHKScreenHud::ResetWidgets();
}

// File Line: 1257
// RVA: 0x612150
void __fastcall UFG::UI::StartPauseVFX(unsigned int hashID)
{
  if ( gPauseVFXLock < 1 && gPauseVFXEnable )
  {
    UFG::RenderWorld::FrontEndPauseEffect_Start(hashID);
    ++gPauseVFXLock;
  }
  else
  {
    ++gPauseVFXLock;
  }
}

// File Line: 1270
// RVA: 0x612670
void __fastcall UFG::UI::StopPauseVFX(bool fade)
{
  if ( --gPauseVFXLock < 1 && gPauseVFXEnable )
    UFG::RenderWorld::FrontEndPauseEffect_End(fade);
}

// File Line: 1303
// RVA: 0x5ED4C0
bool __fastcall UFG::UI::InGameIntroChapter()
{
  UFG::ProgressionTracker *v0; // rax
  UFG::qBaseTreeRB *v1; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string(&result, "M_NMC");
  v0 = UFG::ProgressionTracker::Instance();
  v1 = UFG::ProgressionTracker::Find(v0, &result, 0);
  if ( v1 )
    LOBYTE(v1) = LODWORD(v1[3].mNULL.mChild[1]) != 8;
  return (char)v1;
}

// File Line: 1330
// RVA: 0x5ED510
_BOOL8 __fastcall UFG::UI::InMinigame()
{
  return UFG::UIHKMinigameScreen::mNumMinigameScreens != 0;
}

// File Line: 1336
// RVA: 0x5D6670
void __fastcall UFG::UI::DisplayChangeCallback(Render::RenderOutputParams *settings)
{
  UFG::UIScreen *Screen; // rax
  bool mEnableFullscreen; // cl

  if ( UFG::UIScreenManager::s_instance )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "Options");
    if ( Screen )
    {
      mEnableFullscreen = settings->mEnableFullscreen;
      Screen[11].m_screenName[56] = 1;
      Screen[13].m_screenName[8] = mEnableFullscreen;
    }
  }
}

// File Line: 1366
// RVA: 0x5E7340
UFG::qPropertySet *__fastcall UFG::UI::GetDLCPropertyNode(
        const char *rootName,
        const char *listName,
        const char *nodeName,
        UFG::qSymbol *nodeCompare)
{
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v8; // rax
  char *MemImagePtr; // rax
  char *v10; // rcx
  __int64 v11; // rax
  UFG::qPropertyList *v12; // rbp
  unsigned int mNumElements; // esi
  unsigned int v14; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v16; // rbx
  UFG::qSymbol *v17; // rax
  UFG::qSymbol *v18; // rdx
  UFG::qArray<unsigned long,0> name; // [rsp+20h] [rbp-28h] BYREF

  v6 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.capacity, rootName);
  PropertySet = UFG::PropertySetManager::FindPropertySet(v6);
  if ( !PropertySet )
    return 0i64;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
         DEPTH_RECURSE);
  if ( !v8 )
    return 0i64;
  MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v8);
  v10 = MemImagePtr;
  if ( !MemImagePtr )
    return 0i64;
  v11 = *((_QWORD *)MemImagePtr + 1);
  if ( !v11 )
    return 0i64;
  v12 = (UFG::qPropertyList *)&v10[v11 + 8];
  if ( !v12 )
    return 0i64;
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, nodeName);
  mNumElements = v12->mNumElements;
  v14 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v14);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v16 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v16 = 0i64;
    v17 = UFG::qPropertySet::Get<UFG::qSymbol>(v16, &name, DEPTH_RECURSE);
    v18 = &UFG::gNullQSymbol;
    if ( v17 )
      v18 = v17;
    if ( v18->mUID == nodeCompare->mUID )
      break;
    if ( ++v14 >= mNumElements )
      return 0i64;
  }
  return v16;
}

// File Line: 1391
// RVA: 0x5E7480
UFG::qPropertySet *__fastcall UFG::UI::GetDLCPropertyNode(const char *rootName, const char *listName)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol *ActiveFlow; // rax

  v4 = UFG::ProgressionTracker::Instance();
  ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v4);
  return UFG::UI::GetDLCPropertyNode(rootName, listName, "DLC", ActiveFlow);
}

