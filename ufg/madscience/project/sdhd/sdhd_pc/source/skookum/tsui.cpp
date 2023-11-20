// File Line: 46
// RVA: 0x4D7440
void UFG::TSUI::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("UI");
  SSClass::register_method_func(v0, "localize_string", UFG::TSUI::MthdC_localize_string, 1, 0);
  SSClass::register_method_func(v0, "queue_broadcast_msg", UFG::TSUI::MthdC_queue_broadcast_msg, 1, 0);
  SSClass::register_method_func(v0, "update_objectives", UFG::TSUI::MthdC_update_objectives, 1, 0);
  SSClass::register_method_func(v0, "push_screen", UFG::TSUI::MthdC_push_overlay, 1, 0);
  SSClass::register_method_func(v0, "pop_screen", UFG::TSUI::MthdC_pop_screen, 1, 0);
  SSClass::register_method_func(v0, "push_overlay", UFG::TSUI::MthdC_push_overlay, 1, 0);
  SSClass::register_method_func(v0, "pop_overlay", UFG::TSUI::MthdC_pop_overlay, 1, 0);
  SSClass::register_method_func(v0, "pop_hud", UFG::TSUI::MthdC_pop_hud, 1, 0);
  SSClass::register_method_func(v0, "push_hud", UFG::TSUI::MthdC_push_hud, 1, 0);
  SSClass::register_method_func(v0, "is_player_using_keyboard", UFG::TSUI::MthdC_is_player_using_keyboard, 1, 0);
  SSClass::register_method_func(v0, "is_screen_up", UFG::TSUI::MthdC_is_screen_up, 1, 0);
  SSClass::register_method_func(v0, "gameslice_force_progress", UFG::TSUI::MthdC_gameslice_force_progress, 1, 0);
  SSClass::register_method_func(v0, "game_quit", UFG::TSUI::MthdC_game_quit, 1, 0);
  SSClass::register_method_func(v0, "game_load", UFG::TSUI::MthdC_game_load, 1, 0);
  SSClass::register_method_func(v0, "game_restart", UFG::TSUI::MthdC_game_restart, 1, 0);
  SSClass::register_method_func(v0, "game_pause", UFG::TSUI::MthdC_game_pause, 1, 0);
  SSClass::register_method_func(v0, "opening_credits_set_sequence", UFG::TSUI::MthdC_opening_credits_set_sequence, 1, 0);
  SSClass::register_method_func(v0, "taxi_map_did_player_cancel", UFG::TSUI::MthdC_taxi_map_did_player_cancel, 1, 0);
}

// File Line: 86
// RVA: 0x4EB3F0
void __fastcall UFG::TSUI::MthdC_pop_screen(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
}

// File Line: 92
// RVA: 0x4EABD0
void __fastcall UFG::TSUI::MthdC_localize_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSData **v3; // rcx
  SSInstance *v4; // rsi
  SSInstance *v5; // rdi
  SSInstance *v6; // rbx
  const char *v7; // rax
  AString *v8; // rax
  AStringRef *v9; // rbx
  bool v10; // zf
  AObjReusePool<AStringRef> *v11; // rax
  AObjBlock<AStringRef> *v12; // rcx
  unsigned __int64 v13; // rdx
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v15; // rcx
  UFG::qString v16; // [rsp+38h] [rbp-30h]
  AString v17; // [rsp+78h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_data.i_array_p;
    v4 = v3[1]->i_data_p;
    v5 = v3[2]->i_data_p;
    v6 = v3[3]->i_data_p;
    v7 = UFG::UI::LocalizeText(*(const char **)(*v3)->i_data_p->i_user_data);
    UFG::qString::qString(&v16, v7, *(_QWORD *)v4->i_user_data, *(_QWORD *)v5->i_user_data, *(_QWORD *)v6->i_user_data);
    AString::AString(&v17, v16.mData, 0);
    *v2 = SSString::as_instance(v8);
    v9 = v17.i_str_ref_p;
    v10 = v17.i_str_ref_p->i_ref_count == 1;
    --v9->i_ref_count;
    if ( v10 )
    {
      if ( v9->i_deallocate )
        AMemory::c_free_func(v9->i_cstr_p);
      v11 = AStringRef::get_pool();
      v12 = v11->i_block_p;
      v13 = (unsigned __int64)v12->i_objects_a;
      if ( (unsigned __int64)v9 < v13
        || (v14 = (unsigned __int64)v9 < v13 + 24i64 * v12->i_size, v15 = &v11->i_pool, !v14) )
      {
        v15 = &v11->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v15, v9);
    }
    UFG::qString::~qString(&v16);
  }
}

// File Line: 108
// RVA: 0x4EBBC0
void __fastcall UFG::TSUI::MthdC_queue_broadcast_msg(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // eax

  if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v2 = UFG::qStringHashUpper32(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 0xFFFFFFFF);
    UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, v2, 0);
  }
}

// File Line: 120
// RVA: 0x4F2C90
void __fastcall UFG::TSUI::MthdC_update_objectives(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(UFG::UIHKPlayerObjectiveManager::mInstance, 0i64, UFG::UIHKPlayerObjectiveManager::UpdateObjectives);
}

// File Line: 131
// RVA: 0x4EB3A0
void __fastcall UFG::TSUI::MthdC_pop_hud(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenManagerBase::queuePopOverlay(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 139
// RVA: 0x4EB950
void __fastcall UFG::TSUI::MthdC_push_hud(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v3, v2, 0i64);
}

// File Line: 147
// RVA: 0x4E97C0
void __fastcall UFG::TSUI::MthdC_is_player_using_keyboard(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController);
}

// File Line: 156
// RVA: 0x4E9970
void __fastcall UFG::TSUI::MthdC_is_screen_up(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInstance *v3; // rbx
  UFG::UIScreen *v4; // rax
  bool v5; // zf

  v2 = ppResult;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( UFG::UIScreenManagerBase::areScreensPending((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr)
    || UFG::UIScreenManagerBase::areOverlaysPending((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) )
  {
    *v2 = (SSInstance *)SSBoolean::pool_new(0);
  }
  else
  {
    v4 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           *(const char **)v3->i_user_data);
    v5 = v4 == 0i64;
    if ( !v4 )
      v5 = UFG::UIScreenManagerBase::getOverlay(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             *(const char **)v3->i_user_data) == 0i64;
    *v2 = (SSInstance *)SSBoolean::pool_new(!v5);
  }
}

// File Line: 177
// RVA: 0x4E6F00
void __fastcall UFG::TSUI::MthdC_gameslice_force_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v2 = UFG::ProgressionTracker::Instance();
  v3 = UFG::ProgressionTracker::Find(v2, &name, 0);
  v4 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ForceProgress(v4, (UFG::GameSlice *)v3, 0);
}

// File Line: 188
// RVA: 0x4E6E60
void __fastcall UFG::TSUI::MthdC_game_quit(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UI::QuitGame(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 196
// RVA: 0x4E6DC0
void __fastcall UFG::TSUI::MthdC_game_load(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::GameState *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_10) )
  {
    UFG::qStringCopy(UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName, 100, *(const char **)v2->i_user_data, -1);
    v3 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_10);
    if ( v3 )
      UFG::qString::Set(&v3->mGameStateUserDataStr, UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName);
  }
}

// File Line: 216
// RVA: 0x4E6E80
void __fastcall UFG::TSUI::MthdC_game_restart(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSetup *v4; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_QUIT_TO_MAIN_MENU_15,
    0xFFFFFFFF);
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_10) )
  {
    UFG::qStringCopy(UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName, 100, *(const char **)v2->i_user_data, -1);
    v3 = UFG::ProgressionTracker::Instance();
    v4 = UFG::ProgressionTracker::GetGameSetup(v3);
    UFG::GameSetup::SetInitMenu(v4, "DemoHack_SkipGameslice");
  }
}

// File Line: 234
// RVA: 0x4E6E40
void __fastcall UFG::TSUI::MthdC_game_pause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax

  v2 = pScope->i_data.i_array_p;
  if ( (*v2)->i_data_p != (SSInstance *)-32i64 )
    UFG::UI::PauseGame(*(const char **)(*v2)->i_data_p->i_user_data);
}

// File Line: 245
// RVA: 0x4EB980
void __fastcall UFG::TSUI::MthdC_push_overlay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax

  if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v2 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v3, v2, 0i64);
  }
}

// File Line: 256
// RVA: 0x4EB3C0
void __fastcall UFG::TSUI::MthdC_pop_overlay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax

  v2 = pScope->i_data.i_array_p;
  if ( (*v2)->i_data_p != (SSInstance *)-32i64 )
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      *(const char **)(*v2)->i_data_p->i_user_data);
}

// File Line: 267
// RVA: 0x4EB130
void __fastcall UFG::TSUI::MthdC_opening_credits_set_sequence(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenOpeningCredits::gSequence = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 275
// RVA: 0x4F2890
void __fastcall UFG::TSUI::MthdC_taxi_map_did_player_cancel(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi);
}

