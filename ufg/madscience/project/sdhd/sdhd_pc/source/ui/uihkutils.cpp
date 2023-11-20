// File Line: 100
// RVA: 0x156DC70
__int64 UFG::UI::_dynamic_initializer_for__gOldFocus__()
{
  Render::DepthOfField::Focus::Focus(&gOldFocus);
  return atexit(UFG::UI::_dynamic_atexit_destructor_for__gOldFocus__);
}

// File Line: 133
// RVA: 0x5E79A0
char *__fastcall UFG::UI::GetGamepadButtonTextureName(UFG::UI::eButtons button, bool remappable)
{
  char *result; // rax

  switch ( button )
  {
    case 1:
      if ( remappable )
        goto $LN44_3;
      result = "BUTTON_BACK";
      if ( !gButtonsSwapped )
        goto $LN44_3;
      break;
    case 2:
      if ( remappable )
        goto $LN46_5;
      result = "BUTTON_ACCEPT";
      if ( !gButtonsSwapped )
        goto $LN46_5;
      break;
    case 3:
    case 29:
      result = "BUTTON_BUTTON1";
      break;
    case 4:
    case 30:
      result = "BUTTON_BUTTON2";
      break;
    case 5:
      result = "BUTTON_START";
      break;
    case 6:
      result = "BUTTON_SELECT";
      break;
    case 7:
    case 31:
      result = "BUTTON_L1";
      break;
    case 8:
    case 32:
      result = "BUTTON_R1";
      break;
    case 9:
    case 33:
      result = "BUTTON_L2";
      break;
    case 10:
    case 34:
      result = "BUTTON_R2";
      break;
    case 11:
      result = "BUTTON_L3";
      break;
    case 12:
      result = "BUTTON_R3";
      break;
    case 13:
      result = "BUTTON_L1R1";
      break;
    case 14:
      result = "BUTTON_L2R2";
      break;
    case 15:
      result = "BUTTON_DPAD_UP";
      break;
    case 16:
      result = "BUTTON_DPAD_DOWN";
      break;
    case 17:
      result = "BUTTON_DPAD_LEFT";
      break;
    case 18:
      result = "BUTTON_DPAD_RIGHT";
      break;
    case 19:
      result = "BUTTON_DPAD_LR";
      break;
    case 20:
      result = "BUTTON_DPAD_UD";
      break;
    case 21:
      result = "BUTTON_L_STICK";
      break;
    case 22:
      result = "BUTTON_R_STICK";
      break;
    case 23:
      result = "BUTTON_L_STICK_LR";
      break;
    case 24:
      result = "BUTTON_L_STICK_UD";
      break;
    case 25:
      result = "BUTTON_R_STICK_LR";
      break;
    case 26:
      result = "BUTTON_R_STICK_UD";
      break;
    case 27:
$LN44_3:
      result = "BUTTON_ACCEPT";
      break;
    case 28:
$LN46_5:
      result = "BUTTON_BACK";
      break;
    case 35:
      result = "BUTTON_F1";
      break;
    case 36:
    case 37:
      result = "INVALID";
      break;
    default:
      result = &customWorldMapCaption;
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
    case 1:
    case 5:
    case 27:
      result = "BUTTON_ENTER";
      break;
    case 2:
    case 28:
      result = "BUTTON_BACKSPACE";
      break;
    case 3:
    case 29:
      result = "BUTTON_Q";
      break;
    case 4:
    case 30:
      result = "BUTTON_E";
      break;
    case 6:
      result = "BUTTON_TAB";
      break;
    case 7:
    case 9:
    case 31:
    case 33:
      result = "BUTTON_LCTRL";
      break;
    case 8:
    case 32:
      result = "BUTTON_RCTRL";
      break;
    case 10:
    case 34:
      result = "BUTTON_LSHIFT";
      break;
    case 11:
      result = "BUTTON_M";
      break;
    case 12:
      result = "BUTTON_T";
      break;
    case 13:
      result = "BUTTON_CTRL";
      break;
    case 14:
      result = "BUTTON_MOUSE_M";
      break;
    case 15:
      result = "BUTTON_ARROW_U";
      break;
    case 16:
      result = "BUTTON_ARROW_D";
      break;
    case 17:
      result = "BUTTON_ARROW_L";
      break;
    case 18:
      result = "BUTTON_ARROW_R";
      break;
    case 19:
    case 23:
    case 25:
      result = "BUTTON_ARROW_LR";
      break;
    case 20:
    case 24:
    case 26:
      result = "BUTTON_ARROW_UD";
      break;
    case 21:
    case 22:
      result = "BUTTON_MOUSE";
      break;
    case 35:
      result = "BUTTON_F1";
      break;
    case 36:
      result = "BUTTON_MOUSE_M_U";
      break;
    case 37:
      result = "BUTTON_MOUSE_M_D";
      break;
    default:
      result = &customWorldMapCaption;
      break;
  }
  return result;
}

// File Line: 286
// RVA: 0x5E6DC0
signed __int64 __fastcall UFG::UI::GetButton(const char *text)
{
  const char *v1; // rbx
  int v3; // eax
  unsigned int v4; // ecx

  v1 = text;
  if ( !text )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "BUTTON_ACCEPT", -1) )
    return 1i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_BACK", -1) )
    return 2i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_BUTTON1", -1) )
    return 3i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_BUTTON2", -1) )
    return 4i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L1", -1) )
    return 7i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L2", -1) )
    return 9i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_R1", -1) )
    return 8i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_R2", -1) )
    return 10i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L1R1", -1) )
    return 13i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L2R2", -1) )
    return 14i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_DPAD_UP", -1) )
    return 15i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_DPAD_DOWN", -1) )
    return 16i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_DPAD_LEFT", -1) )
    return 17i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_DPAD_RIGHT", -1) )
    return 18i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_DPAD_LR", -1) )
    return 19i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_DPAD_UD", -1) )
    return 20i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L_STICK", -1) )
    return 21i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_R_STICK", -1) )
    return 22i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_SELECT", -1) )
    return 6i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_START", -1) )
    return 5i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_ACCEPT_HOLD", -1) )
    return 27i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_BACK_HOLD", -1) )
    return 28i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_BUTTON1_HOLD", -1) )
    return 29i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_BUTTON2_HOLD", -1) )
    return 30i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L1_HOLD", -1) )
    return 31i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_R1_HOLD", -1) )
    return 32i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "BUTTON_L2_HOLD", -1) )
    return 33i64;
  v3 = UFG::qStringCompare(v1, "BUTTON_R2_HOLD", -1);
  v4 = 0;
  if ( !v3 )
    v4 = 34;
  return v4;
}

// File Line: 427
// RVA: 0x5ED5D0
void __fastcall UFG::UI::InitHDSettings(UFG::UI *this)
{
  Illusion::Target *v1; // rax
  float v2; // xmm0_4

  gUIHorizontalResolution = (float)Render::GetBackBufferTarget()->mWidth;
  v1 = Render::GetBackBufferTarget();
  v2 = (float)v1->mHeight;
  gUIVerticalResolution = (float)v1->mHeight;
  gIsUIHighDef = v2 >= 720.0;
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
  Scaleform::GFx::Movie *v1; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v1 = screen->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 2;
  pargs.mValue.BValue = gIsUIHighDef;
  Scaleform::GFx::Movie::Invoke(v1, "HandleHighDef", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 505
// RVA: 0x603B50
void __fastcall UFG::UI::ScreenInitCallback(UFG::UIScreen *screen)
{
  UFG::UIScreen *v1; // rbx
  Scaleform::GFx::Movie *v2; // rbx
  double v3; // xmm6_8
  double v4; // xmm6_8
  UFG::GameStatTracker *v5; // rax
  signed int v6; // edi
  double v7; // xmm6_8
  const char *v8; // rdi
  bool v9; // di
  Scaleform::GFx::Value pargs; // [rsp+28h] [rbp-59h]
  char ptr; // [rsp+58h] [rbp-29h]
  __int64 v12; // [rsp+68h] [rbp-19h]
  unsigned int v13; // [rsp+70h] [rbp-11h]
  double v14; // [rsp+78h] [rbp-9h]
  char v15; // [rsp+88h] [rbp+7h]
  __int64 v16; // [rsp+98h] [rbp+17h]
  unsigned int v17; // [rsp+A0h] [rbp+1Fh]
  double v18; // [rsp+A8h] [rbp+27h]
  __int64 v19; // [rsp+B8h] [rbp+37h]

  v19 = -2i64;
  v1 = screen;
  UFG::UI::RefreshScreenHD(screen);
  v2 = v1->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = gUIHorizontalResolution;
  if ( (v13 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(
      v12,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v14));
    v12 = 0i64;
  }
  v13 = 5;
  v14 = v3;
  v4 = gUIVerticalResolution;
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
      v16,
      &v15,
      COERCE_DOUBLE(*(_QWORD *)&v18));
    v16 = 0i64;
  }
  v17 = 5;
  v18 = v4;
  Scaleform::GFx::Movie::Invoke(v2, "HandleResolution", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  v5 = UFG::GameStatTracker::Instance();
  v6 = UFG::GameStatTracker::GetStat(v5, UIScale);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = (float)((float)((float)((float)v6 * 0.1) * 0.15000001) + 0.85000002);
  Scaleform::GFx::Movie::Invoke(v2, "HandleUIScale", 0i64, &pargs, 1u);
  v7 = (double)UFG::UI::gPlatform;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v7;
  Scaleform::GFx::Movie::Invoke(v2, "HandlePlatform", 0i64, &pargs, 1u);
  v8 = UFG::UIGfxTranslator::getLanguageString(UFG::UIScreenManager::s_instance->m_translator);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = v8;
  Scaleform::GFx::Movie::Invoke(v2, "HandleLanguage", 0i64, &pargs, 1u);
  v9 = gButtonsSwapped;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 2;
  pargs.mValue.BValue = v9;
  Scaleform::GFx::Movie::Invoke(v2, "HandleButtonsSwapped", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}>vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_Q

// File Line: 532
// RVA: 0x5FF020
void __fastcall UFG::UI::QuitGame(const char *frontEndScreen)
{
  const char *v1; // rbx
  UFG::ProgressionTracker *v2; // rax
  UFG::GameSetup *v3; // rax

  v1 = "MainMenu";
  if ( frontEndScreen )
    v1 = frontEndScreen;
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
      v1,
      -1);
  }
  else
  {
    v2 = UFG::ProgressionTracker::Instance();
    v3 = UFG::ProgressionTracker::GetGameSetup(v2);
    UFG::GameSetup::SetInitMenu(v3, v1);
  }
}

// File Line: 552
// RVA: 0x5F3910
char __fastcall UFG::UI::PauseGame(const char *pauseScreen)
{
  const char *v1; // rdi
  unsigned int v2; // eax
  unsigned int v3; // ebx
  UFG::GameState *v4; // rax
  UFG::GameState *v5; // rsi
  ANTLR3_INPUT_STREAM_struct *v7; // rax
  unsigned int v8; // edx
  UFG::UIScreenTextureManager *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rbx
  _BOOL8 v12; // r8

  v1 = pauseScreen;
  v2 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  v3 = v2;
  v4 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v2);
  v5 = v4;
  if ( v3 != uidGameStateInGame_13 || !v4 )
    return 0;
  if ( (unsigned int)UFG::qStringCompare(v1, "NISPause", -1) )
  {
    v7 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    v8 = 16;
  }
  else
  {
    v7 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    v8 = 32;
  }
  UFG::UIScreenTextureManager::SetGameState(v7, v8);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_GAME_PAUSE_20,
    0xFFFFFFFF);
  if ( v1 )
  {
    UFG::qString::Set(&v5->mGameStateUserDataStr, v1);
    v9 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v9, v1, 0i64);
  }
  v10 = UFG::GetCurrentGameCamera();
  v11 = v10;
  if ( v10 )
  {
    if ( UFG::SimComponent::IsType(v10, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
      v11->vfptr[20].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v11->vfptr, 0);
  }
  UFG::InputSystem::SetShouldRestrictCursor(0, 0, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 0, 1, 0);
  UFG::InputSystem::msRelativeMouseMode = 0;
  LOBYTE(v12) = 1;
  v5->vfptr->ModeSet(v5, eGSM_PAUSED, v12);
  return 1;
}

// File Line: 605
// RVA: 0x6132A0
void __fastcall UFG::UI::UnpauseGame(UFG::UI *this)
{
  unsigned int v1; // eax
  UFG::GameState *v2; // rax
  UFG::SimComponent *v3; // rax
  UFG::SimComponent *v4; // rbx
  __int64 v5; // rdx
  ANTLR3_INPUT_STREAM_struct *v6; // rax

  v1 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  v2 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v1);
  ((void (__fastcall *)(UFG::GameState *, signed __int64))v2->vfptr->ModeSet)(v2, 1i64);
  UFG::InputSystem::SetShouldRestrictCursor(0, 1, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
  UFG::InputSystem::msRelativeMouseMode = 1;
  v3 = UFG::GetCurrentGameCamera();
  v4 = v3;
  if ( v3 && UFG::SimComponent::IsType(v3, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
  {
    LOBYTE(v5) = 1;
    v4->vfptr[20].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, v5);
  }
  v6 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::SetGameState(v6, 2u);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_GAME_UNPAUSE_20,
    0xFFFFFFFF);
}

// File Line: 637
// RVA: 0x5EE1B0
UFG::GameState *__fastcall UFG::UI::IsGamePaused()
{
  unsigned int v0; // eax
  UFG::GameState *result; // rax
  UFG::GameState *v2; // rdi
  unsigned __int8 v3; // bl

  v0 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  result = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v0);
  v2 = result;
  if ( result )
  {
    if ( UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "NISPause")
      || (v3 = 1, !v2->vfptr->ModeIsSet(v2, eGSM_PAUSED)) )
    {
      v3 = 0;
    }
    result = (UFG::GameState *)v3;
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
    || UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "NISPause") )
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
void __fastcall UFG::UI::ResetInputCounterHack(int counter)
{
  UFG::UI::gUIInputLocked = counter;
  JUMPOUT(counter, 0, UFG::UI::ResetGameplayInput);
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
      g_saved_gameplay_controller_mode = 0;
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
  UFG::qVector3 *v2; // rdi
  UFG::qVector3 *v3; // rsi
  UFG::SimObjectCharacter *v4; // rax
  char result; // al
  UFG::TransformNodeComponent *v6; // rbx
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4

  v2 = dir;
  v3 = pos;
  if ( UFG::UI::gUpdateWorldPos )
  {
    v4 = UFG::GetLocalPlayer();
    if ( !v4 )
      return 0;
    v6 = v4->m_pTransformNodeComponent;
    if ( !v6 )
      return 0;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4->m_pTransformNodeComponent);
    v7 = v6->mWorldTransform.v3.y;
    v8 = v6->mWorldTransform.v3.z;
    cachedPos.x = v6->mWorldTransform.v3.x;
    cachedPos.y = v7;
    cachedPos.z = v8;
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v9 = v6->mWorldTransform.v0.y;
    v10 = v6->mWorldTransform.v0.z;
    v11 = v6->mWorldTransform.v0.x;
    UFG::UI::gUpdateWorldPos = 0;
    cachedDir.x = v11;
    cachedDir.y = v9;
    cachedDir.z = v10;
  }
  v12 = cachedPos.y;
  v13 = cachedPos.z;
  result = 1;
  v3->x = cachedPos.x;
  v3->y = v12;
  v3->z = v13;
  v14 = cachedDir.y;
  v15 = cachedDir.z;
  v2->x = cachedDir.x;
  v2->y = v14;
  v2->z = v15;
  return result;
}

// File Line: 828
// RVA: 0x5F1C00
const char *__fastcall UFG::UI::LocalizeText(const char *tag)
{
  const char *v1; // rbx
  const char *result; // rax
  unsigned int v3; // eax
  UFG::UIGfxTranslator *v4; // rcx

  v1 = tag;
  if ( !tag )
    return 0i64;
  if ( *tag == 36 )
    v1 = tag + 1;
  v3 = UFG::qStringHashUpper32(v1, 0xFFFFFFFF);
  v4 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v4 || (result = (const char *)v4->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, v3)) == 0i64 )
    result = v1;
  return result;
}

// File Line: 849
// RVA: 0x5E8980
char *__fastcall UFG::UI::GetPlayerDisplayName()
{
  UFG::OnlineManager *v0; // rax
  char *v1; // r8
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v0 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::GetOnlineName(v0, &result);
  v1 = "Wei Shen";
  if ( result.mLength )
    v1 = result.mData;
  UFG::qStringCopy(displayName, 512, v1, -1);
  UFG::qString::~qString(&result);
  return displayName;
}

// File Line: 863
// RVA: 0x5EE420
unsigned __int64 __fastcall UFG::UI::IsMissionActive(bool includeEvents)
{
  bool v1; // bl
  UFG::ProgressionTracker *v2; // rax
  unsigned __int64 result; // rax
  UFG::GameSlice *v4; // rdx

  v1 = includeEvents;
  v2 = UFG::ProgressionTracker::Instance();
  result = (unsigned __int64)UFG::ProgressionTracker::GetActiveMaster(v2);
  v4 = (UFG::GameSlice *)result;
  if ( result )
  {
    LOBYTE(result) = !*(_BYTE *)(result + 331) && (unsigned int)(*(_DWORD *)(result + 268) - 6) <= 5;
    if ( v1 && v4->mType == 5 )
      result = (unsigned __int8)result | 1u;
    else
      result = (unsigned __int8)result;
  }
  return result;
}

// File Line: 888
// RVA: 0x5EE490
bool __fastcall UFG::UI::IsMissionWithCheckpointsActive(bool includeEvents)
{
  bool result; // al
  UFG::ProgressionTracker *v2; // rbx
  UFG::GameSlice *v3; // rdi
  UFG::GameSlice *v4; // rax

  result = UFG::UI::IsMissionActive(includeEvents);
  if ( result )
  {
    v2 = UFG::ProgressionTracker::Instance();
    v3 = UFG::ProgressionTracker::GetActiveMaster(v2);
    v4 = UFG::ProgressionTracker::GetLastCheckpoint(v2);
    result = v3 && v4 && (v4 == v3 || UFG::GameSlice::GetParent(v4) == v3);
  }
  return result;
}

// File Line: 913
// RVA: 0x5EE720
char __fastcall UFG::UI::IsPlayerInWater()
{
  return UFG::SimObjectUtility::IsInWater((UFG::SimObject *)&LocalPlayer->vfptr);
}

// File Line: 919
// RVA: 0x5EE690
bool __fastcall UFG::UI::IsPlayerInVehicle()
{
  unsigned __int16 v0; // dx
  UFG::CharacterSubjectComponent *v1; // rax
  bool result; // al

  if ( LocalPlayer
    && ((v0 = LocalPlayer->m_Flags, !((v0 >> 14) & 1)) ? ((v0 & 0x8000u) == 0 ? (!((v0 >> 13) & 1) ? (!((v0 >> 12) & 1) ? (v1 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID)) : (v1 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v1 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v1 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v1 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer)),
        v1) )
  {
    result = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v1->vfptr[42].__vecDelDtor)(v1);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 926
// RVA: 0x5EE730
bool __fastcall UFG::UI::IsPlayerVehiclePassenger()
{
  unsigned __int16 v0; // dx
  UFG::CharacterOccupantComponent *v1; // rax
  unsigned int v2; // ecx
  signed int v3; // eax
  bool result; // al

  result = 0;
  if ( LocalPlayer )
  {
    v0 = LocalPlayer->m_Flags;
    if ( (v0 >> 14) & 1 )
    {
      v1 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else if ( (v0 & 0x8000u) == 0 )
    {
      if ( (v0 >> 13) & 1 )
        v1 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v1 = (UFG::CharacterOccupantComponent *)((v0 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v1 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v1 )
    {
      v2 = v1->mTargetType;
      if ( v2 > eTARGET_TYPE_VEHICLE_PASSENGER_TRUNK || (v3 = 0x2210, !_bittest(&v3, v2)) )
        result = 1;
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
  UFG::qString v3; // [rsp+28h] [rbp-30h]

  if ( !msg )
    return 0i64;
  UFG::qString::qString(&v3, (UFG::qString *)&msg[1]);
  v2 = UFG::qToInt32(v3.mData, 0);
  UFG::qString::~qString(&v3);
  return v2;
}

// File Line: 963
// RVA: 0x603AB0
void __usercall UFG::UI::ScaleViewCoordsToUIScreen(UFG::UIScreen *screen@<rcx>, float *posX@<rdx>, float *posY@<r8>, float a4@<xmm0>)
{
  float *v4; // rbp
  float *v5; // rbx
  UFG::UIScreen *v6; // rdi
  Illusion::Target *v7; // rsi
  Scaleform::GFx::ResourceVtbl *v8; // rax

  v4 = posY;
  v5 = posX;
  v6 = screen;
  v7 = Render::GetBackBufferTarget();
  ((void (*)(void))v6->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)();
  v8 = v6->mRenderable->m_movieDef.pObject->vfptr;
  *v5 = (float)((float)(signed int)a4 / (float)v7->mWidth) * *v5;
  ((void (*)(void))v8[1].GetResourceReport)();
  *v4 = (float)((float)(signed int)a4 / (float)v7->mHeight) * *v4;
}

// File Line: 1123
// RVA: 0x5E6640
void __fastcall UFG::UI::FormatMoneyStr(int money, UFG::qString *string)
{
  signed int v2; // er9
  unsigned int v3; // er9
  _QWORD v4[3]; // [rsp+20h] [rbp-18h]

  v2 = abs(money);
  if ( v2 < 1000000 )
  {
    if ( v2 < 1000 )
      UFG::qString::Format(string, "%d", (unsigned int)money);
    else
      UFG::qString::Format(string, "%d,%03d", money / 1000, (unsigned int)(v2 % 1000));
  }
  else
  {
    LODWORD(v4[0]) = v2 % 1000;
    v3 = (signed int)((unsigned __int64)(274877907i64 * (v2 % 1000000)) >> 32) >> 6;
    UFG::qString::Format(string, "%d,%03d,%03d", money / 1000000, (v3 >> 31) + v3, v4[0]);
  }
}

// File Line: 1148
// RVA: 0x5E7550
UFG::qString *__fastcall UFG::UI::GetDateString(UFG::qString *result, unsigned __int64 systemTime, bool includeSeconds)
{
  UFG::qString *v3; // rbx
  __int64 v4; // r9
  __int64 v5; // r8
  int v6; // er10
  const char *v7; // rdx
  __int64 v9; // [rsp+20h] [rbp-40h]
  __int64 v10; // [rsp+28h] [rbp-38h]
  __int64 v11; // [rsp+30h] [rbp-30h]
  __int64 v12; // [rsp+38h] [rbp-28h]
  __int64 v13; // [rsp+40h] [rbp-20h]
  UFG::qDateTime date_time; // [rsp+50h] [rbp-10h]

  v3 = result;
  UFG::qConvertSystemTimeToDateTime(&date_time, systemTime);
  UFG::qString::qString(v3);
  LODWORD(v13) = 1;
  switch ( UFG::UIScreenManager::s_instance->m_translator->mLanguage )
  {
    case 7u:
      v4 = date_time.mDay;
      v5 = date_time.mMonth;
      goto LABEL_5;
    case 0xEu:
      v6 = date_time.mDay;
      v4 = date_time.mMonth;
      v5 = date_time.mYear;
      LODWORD(v12) = date_time.mSecond;
      LODWORD(v11) = date_time.mMinute;
      LODWORD(v10) = date_time.mHour;
      v7 = "%04d/%02d/%02d %02d:%02d:%02d";
      break;
    default:
      v4 = date_time.mMonth;
      v5 = date_time.mDay;
LABEL_5:
      LODWORD(v12) = date_time.mSecond;
      LODWORD(v11) = date_time.mMinute;
      LODWORD(v10) = date_time.mHour;
      v6 = date_time.mYear;
      v7 = "%02d/%02d/%04d %02d:%02d:%02d";
      break;
  }
  LODWORD(v9) = v6;
  UFG::qString::Format(v3, v7, v5, v4, v9, v10, v11, v12, v13, -2i64);
  return v3;
}

// File Line: 1244
// RVA: 0x5EB870
void __fastcall UFG::UI::HandleGameCheckpointRestore(UFG::UI *this)
{
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
  UFG::UIScreenManagerBase::queuePopOverlay(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    "OpeningCredits");
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
  if ( --gPauseVFXLock < 1 )
    JUMPOUT(gPauseVFXEnable, 0, UFG::RenderWorld::FrontEndPauseEffect_End);
}

// File Line: 1303
// RVA: 0x5ED4C0
bool __fastcall UFG::UI::InGameIntroChapter()
{
  UFG::ProgressionTracker *v0; // rax
  UFG::qBaseTreeRB *v1; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  UFG::qSymbol::create_from_string(&result, "M_NMC");
  v0 = UFG::ProgressionTracker::Instance();
  v1 = UFG::ProgressionTracker::Find(v0, &result, 0);
  if ( v1 )
    LOBYTE(v1) = LODWORD(v1[3].mNULL.mChild[1]) != 8;
  return (char)v1;
}

// File Line: 1330
// RVA: 0x5ED510
bool __fastcall UFG::UI::InMinigame()
{
  return UFG::UIHKMinigameScreen::mNumMinigameScreens != 0;
}

// File Line: 1336
// RVA: 0x5D6670
void __fastcall UFG::UI::DisplayChangeCallback(Render::RenderOutputParams *settings)
{
  Render::RenderOutputParams *v1; // rbx
  UFG::UIScreen *v2; // rax
  bool v3; // cl

  v1 = settings;
  if ( UFG::UIScreenManager::s_instance )
  {
    v2 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Options");
    if ( v2 )
    {
      v3 = v1->mEnableFullscreen;
      v2[11].m_screenName[56] = 1;
      v2[13].m_screenName[8] = v3;
    }
  }
}

// File Line: 1366
// RVA: 0x5E7340
UFG::qPropertySet *__fastcall UFG::UI::GetDLCPropertyNode(const char *rootName, const char *listName, const char *nodeName, UFG::qSymbol *nodeCompare)
{
  UFG::qSymbol *v4; // r14
  const char *v5; // rbx
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rax
  char *v9; // rax
  char *v10; // rcx
  __int64 v11; // rax
  UFG::qPropertyList *v12; // rbp
  unsigned int v13; // esi
  unsigned int v14; // edi
  char *v15; // rax
  UFG::qPropertySet *v16; // rbx
  UFG::qSymbol *v17; // rax
  UFG::qSymbol *v18; // rdx
  UFG::qSymbol name; // [rsp+20h] [rbp-28h]
  UFG::qSymbol result; // [rsp+24h] [rbp-24h]

  v4 = nodeCompare;
  v5 = nodeName;
  v6 = UFG::qSymbol::create_from_string(&result, rootName);
  v7 = UFG::PropertySetManager::FindPropertySet(v6);
  if ( !v7 )
    return 0i64;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v7,
         (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( !v8 )
    return 0i64;
  v9 = UFG::qPropertySet::GetMemImagePtr(v8);
  v10 = v9;
  if ( !v9 )
    return 0i64;
  v11 = *((_QWORD *)v9 + 1);
  if ( !v11 )
    return 0i64;
  v12 = (UFG::qPropertyList *)&v10[v11 + 8];
  if ( !v12 )
    return 0i64;
  UFG::qSymbol::create_from_string(&name, v5);
  v13 = v12->mNumElements;
  v14 = 0;
  if ( !v13 )
    return 0i64;
  while ( 1 )
  {
    v15 = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v14);
    if ( v15 && *(_QWORD *)v15 )
      v16 = (UFG::qPropertySet *)&v15[*(_QWORD *)v15];
    else
      v16 = 0i64;
    v17 = UFG::qPropertySet::Get<UFG::qSymbol>(v16, &name, DEPTH_RECURSE);
    v18 = &UFG::gNullQSymbol;
    if ( v17 )
      v18 = v17;
    if ( v18->mUID == v4->mUID )
      break;
    if ( ++v14 >= v13 )
      return 0i64;
  }
  return v16;
}

// File Line: 1391
// RVA: 0x5E7480
UFG::qPropertySet *__fastcall UFG::UI::GetDLCPropertyNode(const char *rootName, const char *listName)
{
  const char *v2; // rbx
  const char *v3; // rdi
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol *v5; // rax

  v2 = listName;
  v3 = rootName;
  v4 = UFG::ProgressionTracker::Instance();
  v5 = UFG::ProgressionTracker::GetActiveFlow(v4);
  return UFG::UI::GetDLCPropertyNode(v3, v2, "DLC", v5);
}

