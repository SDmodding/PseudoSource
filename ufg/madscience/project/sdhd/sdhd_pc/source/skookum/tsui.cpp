// File Line: 46
// RVA: 0x4D7440
void UFG::TSUI::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]
  ASymbol rebindl; // [rsp+20h] [rbp-18h]
  ASymbol rebindm; // [rsp+20h] [rbp-18h]
  ASymbol rebindn; // [rsp+20h] [rbp-18h]
  ASymbol rebindo; // [rsp+20h] [rbp-18h]
  ASymbol rebindp; // [rsp+20h] [rbp-18h]
  ASymbol rebindq; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("UI");
  SSClass::register_method_func(v0, "localize_string", UFG::TSUI::MthdC_localize_string, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "queue_broadcast_msg", UFG::TSUI::MthdC_queue_broadcast_msg, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "update_objectives", UFG::TSUI::MthdC_update_objectives, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "push_screen", UFG::TSUI::MthdC_push_overlay, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "pop_screen", UFG::TSUI::MthdC_pop_screen, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "push_overlay", UFG::TSUI::MthdC_push_overlay, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "pop_overlay", UFG::TSUI::MthdC_pop_overlay, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "pop_hud", UFG::TSUI::MthdC_pop_hud, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "push_hud", UFG::TSUI::MthdC_push_hud, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "is_player_using_keyboard", UFG::TSUI::MthdC_is_player_using_keyboard, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "is_screen_up", UFG::TSUI::MthdC_is_screen_up, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(v0, "gameslice_force_progress", UFG::TSUI::MthdC_gameslice_force_progress, 1, rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(v0, "game_quit", UFG::TSUI::MthdC_game_quit, 1, rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "game_load", UFG::TSUI::MthdC_game_load, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(v0, "game_restart", UFG::TSUI::MthdC_game_restart, 1, rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(v0, "game_pause", UFG::TSUI::MthdC_game_pause, 1, rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "opening_credits_set_sequence",
    UFG::TSUI::MthdC_opening_credits_set_sequence,
    1,
    rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "taxi_map_did_player_cancel",
    UFG::TSUI::MthdC_taxi_map_did_player_cancel,
    1,
    rebindq);
}

// File Line: 86
// RVA: 0x4EB3F0
void __fastcall UFG::TSUI::MthdC_pop_screen(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
}

// File Line: 92
// RVA: 0x4EABD0
void __fastcall UFG::TSUI::MthdC_localize_string(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rsi
  SSInstance *v5; // rdi
  SSInstance *v6; // rbx
  const char *v7; // rax
  AString *v8; // rax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  UFG::qString v16; // [rsp+38h] [rbp-30h] BYREF
  AString v17; // [rsp+78h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = i_array_p[1]->i_data_p;
    v5 = i_array_p[2]->i_data_p;
    v6 = i_array_p[3]->i_data_p;
    v7 = UFG::UI::LocalizeText(*(const char **)(*i_array_p)->i_data_p->i_user_data);
    UFG::qString::qString(
      &v16,
      v7,
      *(_QWORD *)i_data_p->i_user_data,
      *(_QWORD *)v5->i_user_data,
      *(_QWORD *)v6->i_user_data);
    AString::AString(&v17, v16.mData, 0);
    *ppResult = SSString::as_instance(v8);
    i_str_ref_p = v17.i_str_ref_p;
    if ( v17.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v14 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v14) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
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
    v2 = UFG::qStringHashUpper32(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, -1);
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v2, 0);
  }
}

// File Line: 120
// RVA: 0x4F2C90
void __fastcall UFG::TSUI::MthdC_update_objectives(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
}

// File Line: 131
// RVA: 0x4EB3A0
void __fastcall UFG::TSUI::MthdC_pop_hud(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenManagerBase::queuePopOverlay(
    UFG::UIScreenManager::s_instance,
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
    *ppResult = SSBoolean::pool_new(UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController);
}

// File Line: 156
// RVA: 0x4E9970
void __fastcall UFG::TSUI::MthdC_is_screen_up(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::UIScreen *Screen; // rax
  bool v5; // zf

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( UFG::UIScreenManagerBase::areScreensPending(UFG::UIScreenManager::s_instance)
    || UFG::UIScreenManagerBase::areOverlaysPending(UFG::UIScreenManager::s_instance) )
  {
    *ppResult = SSBoolean::pool_new(0);
  }
  else
  {
    Screen = UFG::UIScreenManagerBase::getScreen(
               UFG::UIScreenManager::s_instance,
               *(const char **)i_data_p->i_user_data);
    v5 = Screen == 0i64;
    if ( !Screen )
      v5 = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, *(const char **)i_data_p->i_user_data) == 0i64;
    *ppResult = SSBoolean::pool_new(!v5);
  }
}

// File Line: 177
// RVA: 0x4E6F00
void __fastcall UFG::TSUI::MthdC_gameslice_force_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

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
  SSInstance *i_data_p; // rbx
  UFG::GameState *GameStateObj; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_10) )
  {
    UFG::qStringCopy(UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName, 100, *(char **)i_data_p->i_user_data, -1);
    GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_10);
    if ( GameStateObj )
      UFG::qString::Set(&GameStateObj->mGameStateUserDataStr, UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName);
  }
}

// File Line: 216
// RVA: 0x4E6E80
void __fastcall UFG::TSUI::MthdC_game_restart(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSetup *GameSetup; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_QUIT_TO_MAIN_MENU_15, 0xFFFFFFFF);
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_10) )
  {
    UFG::qStringCopy(UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName, 100, *(char **)i_data_p->i_user_data, -1);
    v3 = UFG::ProgressionTracker::Instance();
    GameSetup = UFG::ProgressionTracker::GetGameSetup(v3);
    UFG::GameSetup::SetInitMenu(GameSetup, "DemoHack_SkipGameslice");
  }
}

// File Line: 234
// RVA: 0x4E6E40
void __fastcall UFG::TSUI::MthdC_game_pause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax

  i_array_p = pScope->i_data.i_array_p;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
    UFG::UI::PauseGame(*(const char **)(*i_array_p)->i_data_p->i_user_data);
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
  SSData **i_array_p; // rax

  i_array_p = pScope->i_data.i_array_p;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
    UFG::UIScreenManagerBase::queuePopOverlay(
      UFG::UIScreenManager::s_instance,
      *(const char **)(*i_array_p)->i_data_p->i_user_data);
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
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi);
}

