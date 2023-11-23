// File Line: 42
// RVA: 0x1540840
__int64 UFG::_dynamic_initializer_for__qSymbol_is_race__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("is_race", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_is_race, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_is_race__);
}

// File Line: 48
// RVA: 0x50F130
void __fastcall UFG::TSDialog::PauseSim(bool pause)
{
  unsigned int CurrentState; // eax
  UFG::GameState *GameStateObj; // rax

  CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
  if ( GameStateObj )
    GameStateObj->vfptr->ModeSet(GameStateObj, eGSM_PAUSED, pause);
}

// File Line: 60
// RVA: 0x4D2B70
void UFG::TSDialog::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  v0 = SSBrain::get_class("Dialog");
  SSClass::register_coroutine_func(v0, "_show_yes_no", UFG::TSDialog::Coro_show_yes_no, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(v0, "_show_ok", UFG::TSDialog::Coro_show_ok, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_mission_failed",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_mission_failed,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_player_died",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_player_died,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_two_button",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_two_button,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_three_button",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_three_button,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_upgrades_select",
    UFG::TSDialog::Coro_show_upgrades_select,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_case_complete",
    UFG::TSDialog::Coro_show_case_complete,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_case_lead_complete",
    UFG::TSDialog::Coro_show_case_lead_complete,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(v0, "set_mission_failed_flag", UFG::TSDialog::MthdC_set_mission_failed_flag, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "add_case_lead_info", UFG::TSDialog::MthdC_add_case_lead_info, 1, rebinda);
}

// File Line: 79
// RVA: 0x4DDD60
bool __fastcall UFG::TSDialog::Coro_show_yes_no(SSInvokedCoroutine *pScope)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIScreen *v3; // rbp
  bool result; // al
  unsigned int m_skookum_dialog_result; // ebx
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // r14
  SSInstance *v8; // rsi
  bool v9; // di
  bool fullscreen; // bl

  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = Instance;
  if ( !Instance )
  {
    result = 1;
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64;
    return result;
  }
  if ( Instance->m_skookum_dialog_active )
  {
    if ( Instance->m_skookum_dialog_finished )
    {
      m_skookum_dialog_result = Instance->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(Instance);
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64) = m_skookum_dialog_result == UI_HASH_DIALOG_YES_23;
      return 1;
    }
  }
  else
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v8 = i_array_p[1]->i_data_p;
    v9 = i_array_p[2]->i_data_p->i_user_data != 0;
    fullscreen = i_array_p[4]->i_data_p->i_user_data != 0;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(Instance);
    UFG::UIScreenDialogBox::createYesNoDialog(
      v3,
      *(const char **)i_data_p->i_user_data,
      *(const char **)v8->i_user_data,
      v9,
      fullscreen);
  }
  return 0;
}

// File Line: 116
// RVA: 0x4DD820
char __fastcall UFG::TSDialog::Coro_show_ok(SSInvokedCoroutine *pScope)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIScreen *v3; // rsi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdi
  SSInstance *v7; // rbx

  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = Instance;
  if ( !Instance )
    return 1;
  if ( Instance->m_skookum_dialog_active )
  {
    if ( Instance->m_skookum_dialog_finished )
    {
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(Instance);
      return 1;
    }
  }
  else
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v7 = i_array_p[1]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(Instance);
    UFG::UIScreenDialogBox::createOKDialog(
      v3,
      *(const char **)i_data_p->i_user_data,
      *(const char **)v7->i_user_data,
      1);
  }
  return 0;
}

// File Line: 146
// RVA: 0x4DD690
char __fastcall UFG::TSDialog::Coro_show_mission_failed(SSInvokedCoroutine *pScope)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // r13
  unsigned int m_skookum_dialog_result; // ebx
  unsigned int CurrentState; // eax
  UFG::GameState *GameStateObj; // rax
  _BOOL8 v8; // r8
  SSData **i_array_p; // rdx
  bool showRestoreCheckpointOption; // bp
  bool v11; // r15
  SSInstance *i_data_p; // r14
  SSInstance *v13; // rsi
  SSInstance *v14; // rdi
  UFG::qSymbol *v15; // rbx
  UFG::GameStatTracker *v16; // rax
  UFG::GameStatTracker *v17; // rax
  UFG::qString string; // [rsp+38h] [rbp-50h] BYREF
  UFG::qWiseSymbol result; // [rsp+98h] [rbp+10h] BYREF

  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = Instance;
  if ( !Instance )
    return 1;
  if ( Instance->m_skookum_dialog_active )
  {
    if ( Instance->m_skookum_dialog_finished )
    {
      UFG::TSDialog::PauseSim(0);
      m_skookum_dialog_result = v3->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v3);
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) = m_skookum_dialog_result == UI_HASH_DIALOG_YES_23;
      return 1;
    }
  }
  else
  {
    CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
    if ( GameStateObj )
    {
      LOBYTE(v8) = 1;
      GameStateObj->vfptr->ModeSet(GameStateObj, eGSM_PAUSED, v8);
    }
    i_array_p = pScope->i_data.i_array_p;
    showRestoreCheckpointOption = (*i_array_p)->i_data_p->i_user_data != 0;
    v11 = i_array_p[1]->i_data_p->i_user_data != 0;
    i_data_p = i_array_p[2]->i_data_p;
    v13 = i_array_p[3]->i_data_p;
    v14 = i_array_p[4]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v3);
    v15 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0xEF305CE5);
    v16 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v16, MissionFinishedReason, v15);
    UFG::qString::qString(&string, *(const char **)v13->i_user_data);
    v17 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v17, MissionFinishedCaption, &string);
    UFG::qString::~qString(&string);
    UFG::UIHKScreenMissionFailed::createScreen(
      v11,
      *(const char **)i_data_p->i_user_data,
      *(const char **)v13->i_user_data,
      *(const char **)v14->i_user_data,
      showRestoreCheckpointOption);
  }
  return 0;
}

// File Line: 190
// RVA: 0x4DD8B0
char __fastcall UFG::TSDialog::Coro_show_player_died(SSInvokedCoroutine *pScope)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIHKScreenGlobalOverlay *v2; // rdi
  unsigned int CurrentState; // eax
  UFG::GameState *GameStateObj; // rax
  _BOOL8 v6; // r8
  UFG::qSymbol *v7; // rbx
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::qString string; // [rsp+28h] [rbp-30h] BYREF
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF

  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v2 = Instance;
  if ( !Instance )
    return 1;
  if ( Instance->m_skookum_dialog_active )
  {
    if ( Instance->m_skookum_dialog_finished )
    {
      UFG::TSDialog::PauseSim(0);
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v2);
      return 1;
    }
  }
  else
  {
    CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
    if ( GameStateObj )
    {
      LOBYTE(v6) = 1;
      GameStateObj->vfptr->ModeSet(GameStateObj, eGSM_PAUSED, v6);
    }
    v7 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0x897ED0Fu);
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v8, MissionFinishedReason, v7);
    UFG::qString::qString(&string, "Death");
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v9, MissionFinishedCaption, &string);
    UFG::qString::~qString(&string);
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v2);
    UFG::UIHKScreenMissionFailed::createPlayerDiedDialog();
  }
  return 0;
}

// File Line: 224
// RVA: 0x4DDB50
char __fastcall UFG::TSDialog::Coro_show_two_button(SSInvokedCoroutine *pScope)
{
  ASymbol *v2; // rax
  SSInstance *v3; // rax
  __int64 v4; // rbx
  SSInstance *v5; // rsi
  _DWORD *v6; // rcx
  bool v7; // zf
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIScreen *v9; // rbp
  unsigned int m_skookum_dialog_result; // ebx
  ASymbol *v11; // rax
  SSInstance *v12; // rax
  __int64 v13; // rbx
  SSInstance *v14; // rsi
  _DWORD *v15; // rcx
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r14
  SSInstance *v19; // rsi
  SSInstance *v20; // rdi
  SSInstance *v21; // rbx
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h] BYREF

  if ( !pScope->i_update_count )
  {
    v2 = (ASymbol *)UFG::qSymbol::qSymbol(&result, UI_DIALOG_RESULT_1_15);
    v3 = SSSymbol::as_instance(v2);
    v4 = *((_QWORD *)pScope->i_data.i_array_p + 4);
    v5 = v3;
    v6 = *(_DWORD **)(v4 + 8);
    v7 = v6[4]-- == 1;
    if ( v7 )
    {
      v6[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v6 + 112i64))(v6);
    }
    *(_QWORD *)(v4 + 8) = v5;
  }
  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v9 = Instance;
  if ( !Instance )
    return 1;
  if ( Instance->m_skookum_dialog_active )
  {
    if ( Instance->m_skookum_dialog_finished )
    {
      m_skookum_dialog_result = Instance->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(Instance);
      v11 = (ASymbol *)UFG::qSymbol::qSymbol(&result, m_skookum_dialog_result);
      v12 = SSSymbol::as_instance(v11);
      v13 = *((_QWORD *)pScope->i_data.i_array_p + 4);
      v14 = v12;
      v15 = *(_DWORD **)(v13 + 8);
      v7 = v15[4]-- == 1;
      if ( v7 )
      {
        v15[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v15 + 112i64))(v15);
      }
      *(_QWORD *)(v13 + 8) = v14;
      return 1;
    }
  }
  else
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v19 = i_array_p[1]->i_data_p;
    v20 = i_array_p[2]->i_data_p;
    v21 = i_array_p[3]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(Instance);
    UFG::UIScreenDialogBox::createTwoButtonDialog(
      v9,
      *(const char **)i_data_p->i_user_data,
      *(const char **)v19->i_user_data,
      *(const char **)v20->i_user_data,
      UI_DIALOG_RESULT_1_15,
      *(const char **)v21->i_user_data,
      UI_DIALOG_RESULT_2_15,
      DIALOG_BUTTON1,
      1,
      "DialogBox");
  }
  return 0;
}

// File Line: 270
// RVA: 0x4DD9B0
char __fastcall UFG::TSDialog::Coro_show_three_button(SSInvokedCoroutine *pScope)
{
  ASymbol *v2; // rax
  SSInstance *v3; // rax
  __int64 v4; // rbx
  SSInstance *v5; // rsi
  _DWORD *v6; // rcx
  bool v7; // zf
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIScreen *v9; // rbp
  unsigned int m_skookum_dialog_result; // ebx
  ASymbol *v11; // rax
  SSInstance *v12; // rax
  __int64 v13; // rbx
  SSInstance *v14; // rsi
  _DWORD *v15; // rcx
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r15
  SSInstance *v19; // r14
  SSInstance *v20; // rsi
  SSInstance *v21; // rdi
  SSInstance *v22; // rbx
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h] BYREF

  if ( !pScope->i_update_count )
  {
    v2 = (ASymbol *)UFG::qSymbol::qSymbol(&result, UI_DIALOG_RESULT_1_15);
    v3 = SSSymbol::as_instance(v2);
    v4 = *((_QWORD *)pScope->i_data.i_array_p + 5);
    v5 = v3;
    v6 = *(_DWORD **)(v4 + 8);
    v7 = v6[4]-- == 1;
    if ( v7 )
    {
      v6[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v6 + 112i64))(v6);
    }
    *(_QWORD *)(v4 + 8) = v5;
  }
  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v9 = Instance;
  if ( !Instance )
    return 1;
  if ( Instance->m_skookum_dialog_active )
  {
    if ( Instance->m_skookum_dialog_finished )
    {
      m_skookum_dialog_result = Instance->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(Instance);
      v11 = (ASymbol *)UFG::qSymbol::qSymbol(&result, m_skookum_dialog_result);
      v12 = SSSymbol::as_instance(v11);
      v13 = *((_QWORD *)pScope->i_data.i_array_p + 5);
      v14 = v12;
      v15 = *(_DWORD **)(v13 + 8);
      v7 = v15[4]-- == 1;
      if ( v7 )
      {
        v15[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v15 + 112i64))(v15);
      }
      *(_QWORD *)(v13 + 8) = v14;
      return 1;
    }
  }
  else
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v19 = i_array_p[1]->i_data_p;
    v20 = i_array_p[2]->i_data_p;
    v21 = i_array_p[3]->i_data_p;
    v22 = i_array_p[4]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(Instance);
    UFG::UIScreenDialogBox::createThreeButtonDialog(
      v9,
      *(const char **)i_data_p->i_user_data,
      *(const char **)v19->i_user_data,
      *(const char **)v20->i_user_data,
      UI_DIALOG_RESULT_1_15,
      *(const char **)v21->i_user_data,
      UI_DIALOG_RESULT_2_15,
      *(const char **)v22->i_user_data,
      UI_DIALOG_RESULT_3_15,
      DIALOG_BUTTON1,
      "DialogBox");
  }
  return 0;
}

// File Line: 317
// RVA: 0x4DDCC0
bool __fastcall UFG::TSDialog::Coro_show_upgrades_select(SSInvokedCoroutine *pScope)
{
  UFG::UIHKScreenUpgrades::eUpgradesType v1; // edx
  int i_user_data; // r8d
  UFG::UIScreen *Screen; // rax

  v1 = UPGRADES_TYPE_MELEE;
  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( i_user_data == qSymbol_Police_15.mUID )
  {
    v1 = UPGRADES_TYPE_POLICE;
  }
  else if ( i_user_data == qSymbol_Triad_15.mUID )
  {
    v1 = UPGRADES_TYPE_TRIAD;
  }
  if ( pScope->i_update_count )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "Upgrades");
    if ( gUIScreenSeen )
    {
      return Screen == 0i64;
    }
    else
    {
      gUIScreenSeen = Screen != 0i64;
      return 0;
    }
  }
  else
  {
    gUIScreenSeen = 0;
    UFG::UIHKScreenUpgrades::mMode = MODE_MODAL;
    UFG::UIHKScreenUpgrades::mUpgradesType = v1;
    UFG::UI::PauseGame("Upgrades");
    return 0;
  }
}

// File Line: 356
// RVA: 0x4DD320
bool __fastcall UFG::TSDialog::Coro_show_case_complete(SSInvokedCoroutine *pScope)
{
  UFG::UIScreenTextureManager *v1; // rax
  UFG::UIScreen *Screen; // rax

  if ( pScope->i_update_count )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CaseComplete");
    if ( gUIScreenSeen )
    {
      return Screen == 0i64;
    }
    else
    {
      gUIScreenSeen = Screen != 0i64;
      return 0;
    }
  }
  else
  {
    gUIScreenSeen = 0;
    UFG::UIHKScreenCaseComplete::mCaseType = CASE_TYPE_COMPLETE;
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v1, "CaseComplete", 0i64);
    return 0;
  }
}

// File Line: 382
// RVA: 0x4DD3A0
bool __fastcall UFG::TSDialog::Coro_show_case_lead_complete(SSInvokedCoroutine *pScope)
{
  UFG::UIScreenTextureManager *v1; // rax
  UFG::UIScreen *Screen; // rax

  if ( pScope->i_update_count )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CaseComplete");
    if ( gUIScreenSeen )
    {
      return Screen == 0i64;
    }
    else
    {
      gUIScreenSeen = Screen != 0i64;
      return 0;
    }
  }
  else
  {
    gUIScreenSeen = 0;
    UFG::UIHKScreenCaseComplete::mCaseType = CASE_TYPE_LEAD;
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v1, "CaseComplete", 0i64);
    return 0;
  }
}

// File Line: 408
// RVA: 0x4EE490
void __fastcall UFG::TSDialog::MthdC_set_mission_failed_flag(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx

  i_array_p = pScope->i_data.i_array_p;
  if ( LODWORD((*i_array_p)->i_data_p->i_user_data) == qSymbol_is_race.mUID )
    UFG::UIHKScreenMissionFailed::gIsRace = i_array_p[1]->i_data_p->i_user_data != 0;
}

// File Line: 424
// RVA: 0x4E2E20
void __fastcall UFG::TSDialog::MthdC_add_case_lead_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenCaseComplete::AddInfo(
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

