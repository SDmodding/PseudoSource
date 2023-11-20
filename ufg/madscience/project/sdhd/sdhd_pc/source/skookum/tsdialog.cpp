// File Line: 42
// RVA: 0x1540840
__int64 UFG::_dynamic_initializer_for__qSymbol_is_race__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("is_race", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_is_race, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_is_race__);
}

// File Line: 48
// RVA: 0x50F130
void __fastcall UFG::TSDialog::PauseSim(bool pause)
{
  bool v1; // bl
  unsigned int v2; // eax
  UFG::GameState *v3; // rax

  v1 = pause;
  v2 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  v3 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v2);
  if ( v3 )
    v3->vfptr->ModeSet(v3, eGSM_PAUSED, v1);
}

// File Line: 60
// RVA: 0x4D2B70
void UFG::TSDialog::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Dialog");
  SSClass::register_coroutine_func(v0, "_show_yes_no", UFG::TSDialog::Coro_show_yes_no, 0);
  SSClass::register_coroutine_func(v0, "_show_ok", UFG::TSDialog::Coro_show_ok, 0);
  SSClass::register_coroutine_func(
    v0,
    "_show_mission_failed",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_mission_failed,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_show_player_died",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_player_died,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_show_two_button",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_two_button,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_show_three_button",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSDialog::Coro_show_three_button,
    0);
  SSClass::register_coroutine_func(v0, "_show_upgrades_select", UFG::TSDialog::Coro_show_upgrades_select, 0);
  SSClass::register_coroutine_func(v0, "_show_case_complete", UFG::TSDialog::Coro_show_case_complete, 0);
  SSClass::register_coroutine_func(v0, "_show_case_lead_complete", UFG::TSDialog::Coro_show_case_lead_complete, 0);
  SSClass::register_method_func(v0, "set_mission_failed_flag", UFG::TSDialog::MthdC_set_mission_failed_flag, 1, 0);
  SSClass::register_method_func(v0, "add_case_lead_info", UFG::TSDialog::MthdC_add_case_lead_info, 1, 0);
}

// File Line: 79
// RVA: 0x4DDD60
bool __fastcall UFG::TSDialog::Coro_show_yes_no(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdi
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIScreen *v3; // rbp
  bool result; // al
  unsigned int v5; // ebx
  SSData **v6; // rdx
  SSInstance *v7; // r14
  SSInstance *v8; // rsi
  bool v9; // di
  bool fullscreen; // bl

  v1 = pScope;
  v2 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = (UFG::UIScreen *)&v2->vfptr;
  if ( !v2 )
  {
    result = 1;
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 3) + 8i64) + 32i64) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 2) + 8i64)
                                                                                               + 32i64) != 0i64;
    return result;
  }
  if ( v2->m_skookum_dialog_active )
  {
    if ( v2->m_skookum_dialog_finished )
    {
      v5 = v2->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v2);
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 3) + 8i64) + 32i64) = v5 == UI_HASH_DIALOG_YES_23;
      return 1;
    }
  }
  else
  {
    v6 = v1->i_data.i_array_p;
    v7 = (*v6)->i_data_p;
    v8 = v6[1]->i_data_p;
    v9 = v6[2]->i_data_p->i_user_data != 0;
    fullscreen = v6[4]->i_data_p->i_user_data != 0;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v2);
    UFG::UIScreenDialogBox::createYesNoDialog(
      v3,
      *(const char **)v7->i_user_data,
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
  SSInvokedCoroutine *v1; // rbx
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIScreen *v3; // rsi
  SSData **v5; // rcx
  SSInstance *v6; // rdi
  SSInstance *v7; // rbx

  v1 = pScope;
  v2 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = (UFG::UIScreen *)&v2->vfptr;
  if ( !v2 )
    return 1;
  if ( v2->m_skookum_dialog_active )
  {
    if ( v2->m_skookum_dialog_finished )
    {
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v2);
      return 1;
    }
  }
  else
  {
    v5 = v1->i_data.i_array_p;
    v6 = (*v5)->i_data_p;
    v7 = v5[1]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v2);
    UFG::UIScreenDialogBox::createOKDialog(v3, *(const char **)v6->i_user_data, *(const char **)v7->i_user_data, 1);
  }
  return 0;
}

// File Line: 146
// RVA: 0x4DD690
char __fastcall UFG::TSDialog::Coro_show_mission_failed(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdi
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // r13
  unsigned int v4; // ebx
  unsigned int v6; // eax
  UFG::GameState *v7; // rax
  _BOOL8 v8; // r8
  SSData **v9; // rdx
  bool showRestoreCheckpointOption; // bp
  bool v11; // r15
  SSInstance *v12; // r14
  SSInstance *v13; // rsi
  SSInstance *v14; // rdi
  UFG::qSymbol *v15; // rbx
  UFG::GameStatTracker *v16; // rax
  UFG::GameStatTracker *v17; // rax
  UFG::qString string; // [rsp+38h] [rbp-50h]
  UFG::qWiseSymbol result; // [rsp+98h] [rbp+10h]

  v1 = pScope;
  v2 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = v2;
  if ( !v2 )
    return 1;
  if ( v2->m_skookum_dialog_active )
  {
    if ( v2->m_skookum_dialog_finished )
    {
      UFG::TSDialog::PauseSim(0);
      v4 = v3->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v3);
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 5) + 8i64) + 32i64) = v4 == UI_HASH_DIALOG_YES_23;
      return 1;
    }
  }
  else
  {
    v6 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    v7 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v6);
    if ( v7 )
    {
      LOBYTE(v8) = 1;
      v7->vfptr->ModeSet(v7, eGSM_PAUSED, v8);
    }
    v9 = v1->i_data.i_array_p;
    showRestoreCheckpointOption = (*v9)->i_data_p->i_user_data != 0;
    v11 = v9[1]->i_data_p->i_user_data != 0;
    v12 = v9[2]->i_data_p;
    v13 = v9[3]->i_data_p;
    v14 = v9[4]->i_data_p;
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
      *(const char **)v12->i_user_data,
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
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKScreenGlobalOverlay *v2; // rdi
  unsigned int v4; // eax
  UFG::GameState *v5; // rax
  _BOOL8 v6; // r8
  UFG::qSymbol *v7; // rbx
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::qString string; // [rsp+28h] [rbp-30h]
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]

  v1 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v2 = v1;
  if ( !v1 )
    return 1;
  if ( v1->m_skookum_dialog_active )
  {
    if ( v1->m_skookum_dialog_finished )
    {
      UFG::TSDialog::PauseSim(0);
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v2);
      return 1;
    }
  }
  else
  {
    v4 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    v5 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v4);
    if ( v5 )
    {
      LOBYTE(v6) = 1;
      v5->vfptr->ModeSet(v5, eGSM_PAUSED, v6);
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
  SSInvokedCoroutine *v1; // rdi
  ASymbol *v2; // rax
  SSInstance *v3; // rax
  __int64 v4; // rbx
  SSInstance *v5; // rsi
  _DWORD *v6; // rcx
  bool v7; // zf
  UFG::UIHKScreenGlobalOverlay *v8; // rax
  UFG::UIScreen *v9; // rbp
  unsigned int v10; // ebx
  ASymbol *v11; // rax
  SSInstance *v12; // rax
  __int64 v13; // rbx
  SSInstance *v14; // rsi
  _DWORD *v15; // rcx
  SSData **v17; // rcx
  SSInstance *v18; // r14
  SSInstance *v19; // rsi
  SSInstance *v20; // rdi
  SSInstance *v21; // rbx
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h]

  v1 = pScope;
  if ( !pScope->i_update_count )
  {
    v2 = (ASymbol *)UFG::qSymbol::qSymbol(&result, UI_DIALOG_RESULT_1_15);
    v3 = SSSymbol::as_instance(v2);
    v4 = *((_QWORD *)v1->i_data.i_array_p + 4);
    v5 = v3;
    v6 = *(_DWORD **)(v4 + 8);
    v7 = v6[4]-- == 1;
    if ( v7 )
    {
      v6[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v6 + 112i64))();
    }
    *(_QWORD *)(v4 + 8) = v5;
  }
  v8 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v9 = (UFG::UIScreen *)&v8->vfptr;
  if ( !v8 )
    return 1;
  if ( v8->m_skookum_dialog_active )
  {
    if ( v8->m_skookum_dialog_finished )
    {
      v10 = v8->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v8);
      v11 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v10);
      v12 = SSSymbol::as_instance(v11);
      v13 = *((_QWORD *)v1->i_data.i_array_p + 4);
      v14 = v12;
      v15 = *(_DWORD **)(v13 + 8);
      v7 = v15[4]-- == 1;
      if ( v7 )
      {
        v15[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v15 + 112i64))();
      }
      *(_QWORD *)(v13 + 8) = v14;
      return 1;
    }
  }
  else
  {
    v17 = v1->i_data.i_array_p;
    v18 = (*v17)->i_data_p;
    v19 = v17[1]->i_data_p;
    v20 = v17[2]->i_data_p;
    v21 = v17[3]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v8);
    UFG::UIScreenDialogBox::createTwoButtonDialog(
      v9,
      *(const char **)v18->i_user_data,
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
  SSInvokedCoroutine *v1; // rdi
  ASymbol *v2; // rax
  SSInstance *v3; // rax
  __int64 v4; // rbx
  SSInstance *v5; // rsi
  _DWORD *v6; // rcx
  bool v7; // zf
  UFG::UIHKScreenGlobalOverlay *v8; // rax
  UFG::UIScreen *v9; // rbp
  unsigned int v10; // ebx
  ASymbol *v11; // rax
  SSInstance *v12; // rax
  __int64 v13; // rbx
  SSInstance *v14; // rsi
  _DWORD *v15; // rcx
  SSData **v17; // rcx
  SSInstance *v18; // r15
  SSInstance *v19; // r14
  SSInstance *v20; // rsi
  SSInstance *v21; // rdi
  SSInstance *v22; // rbx
  UFG::qWiseSymbol result; // [rsp+80h] [rbp+8h]

  v1 = pScope;
  if ( !pScope->i_update_count )
  {
    v2 = (ASymbol *)UFG::qSymbol::qSymbol(&result, UI_DIALOG_RESULT_1_15);
    v3 = SSSymbol::as_instance(v2);
    v4 = *((_QWORD *)v1->i_data.i_array_p + 5);
    v5 = v3;
    v6 = *(_DWORD **)(v4 + 8);
    v7 = v6[4]-- == 1;
    if ( v7 )
    {
      v6[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v6 + 112i64))();
    }
    *(_QWORD *)(v4 + 8) = v5;
  }
  v8 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v9 = (UFG::UIScreen *)&v8->vfptr;
  if ( !v8 )
    return 1;
  if ( v8->m_skookum_dialog_active )
  {
    if ( v8->m_skookum_dialog_finished )
    {
      v10 = v8->m_skookum_dialog_result;
      UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v8);
      v11 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v10);
      v12 = SSSymbol::as_instance(v11);
      v13 = *((_QWORD *)v1->i_data.i_array_p + 5);
      v14 = v12;
      v15 = *(_DWORD **)(v13 + 8);
      v7 = v15[4]-- == 1;
      if ( v7 )
      {
        v15[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v15 + 112i64))();
      }
      *(_QWORD *)(v13 + 8) = v14;
      return 1;
    }
  }
  else
  {
    v17 = v1->i_data.i_array_p;
    v18 = (*v17)->i_data_p;
    v19 = v17[1]->i_data_p;
    v20 = v17[2]->i_data_p;
    v21 = v17[3]->i_data_p;
    v22 = v17[4]->i_data_p;
    UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v8);
    UFG::UIScreenDialogBox::createThreeButtonDialog(
      v9,
      *(const char **)v18->i_user_data,
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
  int v2; // er8
  bool result; // al
  UFG::UIScreen *v4; // rax

  v1 = 2;
  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v2 == qSymbol_Police_15.mUID )
  {
    v1 = 0;
  }
  else if ( v2 == qSymbol_Triad_15.mUID )
  {
    v1 = 1;
  }
  if ( pScope->i_update_count )
  {
    v4 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Upgrades");
    if ( gUIScreenSeen )
    {
      result = v4 == 0i64;
    }
    else
    {
      gUIScreenSeen = v4 != 0i64;
      result = 0;
    }
  }
  else
  {
    gUIScreenSeen = 0;
    UFG::UIHKScreenUpgrades::mMode = 1;
    UFG::UIHKScreenUpgrades::mUpgradesType = v1;
    UFG::UI::PauseGame("Upgrades");
    result = 0;
  }
  return result;
}

// File Line: 356
// RVA: 0x4DD320
bool __fastcall UFG::TSDialog::Coro_show_case_complete(SSInvokedCoroutine *pScope)
{
  UFG::UIScreenTextureManager *v1; // rax
  bool result; // al
  UFG::UIScreen *v3; // rax

  if ( pScope->i_update_count )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "CaseComplete");
    if ( gUIScreenSeen )
    {
      result = v3 == 0i64;
    }
    else
    {
      gUIScreenSeen = v3 != 0i64;
      result = 0;
    }
  }
  else
  {
    gUIScreenSeen = 0;
    UFG::UIHKScreenCaseComplete::mCaseType = 3;
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v1, "CaseComplete", 0i64);
    result = 0;
  }
  return result;
}

// File Line: 382
// RVA: 0x4DD3A0
bool __fastcall UFG::TSDialog::Coro_show_case_lead_complete(SSInvokedCoroutine *pScope)
{
  UFG::UIScreenTextureManager *v1; // rax
  bool result; // al
  UFG::UIScreen *v3; // rax

  if ( pScope->i_update_count )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "CaseComplete");
    if ( gUIScreenSeen )
    {
      result = v3 == 0i64;
    }
    else
    {
      gUIScreenSeen = v3 != 0i64;
      result = 0;
    }
  }
  else
  {
    gUIScreenSeen = 0;
    UFG::UIHKScreenCaseComplete::mCaseType = 2;
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v1, "CaseComplete", 0i64);
    result = 0;
  }
  return result;
}

// File Line: 408
// RVA: 0x4EE490
void __fastcall UFG::TSDialog::MthdC_set_mission_failed_flag(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx

  v2 = pScope->i_data.i_array_p;
  if ( LODWORD((*v2)->i_data_p->i_user_data) == qSymbol_is_race.mUID )
    UFG::UIHKScreenMissionFailed::gIsRace = v2[1]->i_data_p->i_user_data != 0;
}

// File Line: 424
// RVA: 0x4E2E20
void __fastcall UFG::TSDialog::MthdC_add_case_lead_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenCaseComplete::AddInfo(
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

