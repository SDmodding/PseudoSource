// File Line: 92
// RVA: 0x1531080
__int64 dynamic_initializer_for__UFG::TSGameSlice::msInteriorTriggerData__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TSGameSlice::msInteriorTriggerData__);
}

// File Line: 117
// RVA: 0x4D3110
void UFG::TSGameSlice::BindAtomics(void)
{
  SSClass *v0; // rax

  UFG::SkookumMgr::mspGameSliceClass = (SSActorClass *)SSBrain::get_class("GameSlice");
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_name",
    UFG::TSGameSlice::Mthd_gameslice_get_name,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_layer_name",
    UFG::TSGameSlice::Mthd_gameslice_get_layer_name,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "start_gameslice",
    UFG::TSGameSlice::Mthd_start_gameslice,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "complete_gameslice",
    UFG::TSGameSlice::Mthd_complete_gameslice,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_fail_gameslice",
    UFG::TSGameSlice::Coro_fail_gameslice,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_gameslice_restoring",
    UFG::TSGameSlice::Mthd_is_gameslice_restoring,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_gameslice_exclusive",
    UFG::TSGameSlice::Mthd_is_gameslice_exclusive,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_gameslice_random_exclusive",
    UFG::TSGameSlice::Mthd_is_gameslice_random_exclusive,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_challenge_mode",
    UFG::TSGameSlice::Mthd_is_challenge_mode,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_gameslice_single_container",
    UFG::TSGameSlice::Mthd_is_gameslice_single_container,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_gameslice_active_master",
    UFG::TSGameSlice::Mthd_is_gameslice_active_master,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_gameslice_failed",
    UFG::TSGameSlice::Mthd_is_gameslice_failed,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_progression_fail_pending",
    UFG::TSGameSlice::Mthd_is_progression_fail_pending,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_target_gameslice_completed",
    UFG::TSGameSlice::Mthd_is_target_gameslice_completed,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_exit_challenge_private",
    UFG::TSGameSlice::Mthd_gameslice_exit_challenge_private,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_restore_checkpoint_private",
    UFG::TSGameSlice::Mthd_gameslice_restore_checkpoint_private,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_cancel_mission_private",
    UFG::TSGameSlice::Mthd_gameslice_cancel_mission_private,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_enable_on_enter_trigger",
    UFG::TSGameSlice::Mthd_gameslice_enable_on_enter_trigger,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_enable_on_exit_trigger",
    UFG::TSGameSlice::Mthd_gameslice_enable_on_exit_trigger,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_disable_on_enter_trigger",
    UFG::TSGameSlice::Mthd_gameslice_disable_on_enter_trigger,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_disable_on_exit_trigger",
    UFG::TSGameSlice::Mthd_gameslice_disable_on_exit_trigger,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_type",
    UFG::TSGameSlice::Mthd_gameslice_get_type,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "get_active_master",
    UFG::TSGameSlice::MthdC_get_active_master,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "reset_gameslice_fail_timer_debug",
    UFG::TSGameSlice::MthdC_reset_gameslice_fail_timer_debug,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_progression_trigger",
    UFG::TSGameSlice::Mthd_gameslice_get_progression_trigger,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_rewards_properties",
    UFG::TSGameSlice::Mthd_gameslice_get_rewards_properties,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_restore_vehicle",
    UFG::TSGameSlice::Mthd_gameslice_get_restore_vehicle,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_gameslice_play_intro_nis",
    UFG::TSGameSlice::Coro_gameslice_play_intro_nis,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_gameslice_code_setup",
    UFG::TSGameSlice::Coro_gameslice_code_setup,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_code_cleanup",
    UFG::TSGameSlice::Mthd_gameslice_code_cleanup,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_claim_exclusive",
    UFG::TSGameSlice::Mthd_gameslice_claim_exclusive,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_get_completion_count",
    UFG::TSGameSlice::Mthd_gameslice_get_completion_count,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_gameslice_wait_progression_trigger_private",
    UFG::TSGameSlice::Coro_gameslice_wait_progression_trigger_private,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_gameslice_wait_case_open_private",
    UFG::TSGameSlice::Coro_gameslice_wait_case_open_private,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_gameslice_wait_until_in_game_state",
    UFG::TSWorld::Coro_wait_until_in_game_state,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_gameslice_wait_until_tracker_running",
    UFG::TSGameSlice::Coro_gameslice_wait_until_tracker_running,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "enable_objective",
    UFG::TSGameSlice::Mthd_enable_objective,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "disable_objective",
    UFG::TSGameSlice::Mthd_disable_objective,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "set_objective_caption",
    UFG::TSGameSlice::Mthd_set_objective_caption,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "set_objective_status",
    UFG::TSGameSlice::Mthd_set_objective_status,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_objective_complete",
    UFG::TSGameSlice::Mthd_is_objective_complete,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "is_single_character_sprinkle",
    UFG::TSGameSlice::Mthd_is_single_character_sprinkle,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "get_override_for_sprinkle_character",
    UFG::TSGameSlice::Mthd_get_override_for_sprinkle_character,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "attach_to_objective",
    UFG::TSGameSlice::Mthd_attach_to_objective,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "remove_from_objective",
    UFG::TSGameSlice::Mthd_remove_from_objective,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "faction_get_standing",
    UFG::TSGameSlice::Mthd_faction_get_standing,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "set_battle_type",
    UFG::TSGameSlice::Mthd_set_battle_type,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "set_dialogue_state",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "load_audio_resources",
    UFG::TSGameSlice::Mthd_load_audio_resources,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "unload_audio_resources",
    UFG::TSGameSlice::Mthd_unload_audio_resources,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_enable_ambient_units",
    UFG::TSGameSlice::Mthd_cops_enable_ambient_units,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_enable",
    UFG::TSGameSlice::Mthd_cops_enable,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_get_ratio_for_current_heat_level",
    UFG::TSGameSlice::Mthd_cops_get_ratio_for_current_heat_level,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_get_heat_level",
    UFG::TSGameSlice::Mthd_cops_get_heat_level,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_set_heat_level",
    UFG::TSGameSlice::Mthd_cops_set_heat_level,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_exclude_player_for_rest_of_chase",
    UFG::TSGameSlice::Mthd_cops_exclude_player_for_rest_of_chase,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_escalate_to_minimum_heat_level",
    UFG::TSGameSlice::Mthd_cops_escalate_to_minimum_heat_level,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_get_enabled",
    UFG::TSGameSlice::Mthd_cops_get_enabled,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_trigger_instant_cooldown",
    UFG::TSGameSlice::Mthd_cops_trigger_instant_cooldown,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_is_cooling_down",
    UFG::TSGameSlice::Mthd_cops_is_cooling_down,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "cops_debug_cap_heat_level",
    UFG::TSGameSlice::Mthd_cops_debug_cap_heat_level,
    1,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_wait_until_cops_heat_level_below",
    UFG::TSGameSlice::Coro_wait_until_cops_heat_level_below,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_camera_raycast_to_target",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSGameSlice::Coro_camera_raycast_to_target,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_async_is_target_occluded",
    UFG::TSGameSlice::Coro_async_is_target_occluded,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "_launch_store_front",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSGameSlice::Coro_launch_store_front,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_set_restore_vehicle_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_restore_vehicle_location_marker,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_set_restore_location_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_restore_location_marker,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_set_cancel_location_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_cancel_location_marker,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_set_complete_location_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_complete_location_marker,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "gameslice_set_restore_location",
    UFG::TSGameSlice::Mthd_gameslice_set_restore_location,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "missionscoring_add_cop_event",
    UFG::TSGameSlice::Mthd_missionscoring_add_cop_event,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "missionscoring_add_triad_event",
    UFG::TSGameSlice::Mthd_missionscoring_add_triad_event,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "borrow_ambient_actor",
    UFG::TSGameSlice::Mthd_borrow_ambient_actor,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "despawn_npc",
    UFG::TSGameSlice::Mthd_despawn_npc,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "send_collectible_telemetry_stat",
    UFG::TSGameSlice::Mthd_send_collectible_telemetry_stat,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "release_interior_triggers",
    UFG::TSGameSlice::Mthd_release_interior_triggers,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::SkookumMgr::mspGameSliceClass->vfptr,
    "setup_interior_triggers",
    UFG::TSGameSlice::Mthd_setup_interior_triggers,
    0);
  v0 = SSBrain::get_class("ScriptTests");
  SSClass::register_method_func(v0, "launch_if_available", UFG::TSGameSlice::Mthd_ScriptTest_launch_if_available, 0);
}

// File Line: 230
// RVA: 0x4FA8A0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  signed __int64 v4; // rax
  AString *v5; // rax
  AStringRef *v6; // rbx
  bool v7; // zf
  AObjReusePool<AStringRef> *v8; // rax
  AObjBlock<AStringRef> *v9; // rcx
  unsigned __int64 v10; // rdx
  bool v11; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v12; // rcx
  AString v13; // [rsp+48h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( v3 && pScope->i_scope_p.i_ptr_id == v3->i_ptr_id )
      v4 = (signed __int64)&v3[-2].i_ptr_id;
    else
      v4 = 0i64;
    AString::AString(&v13, *(const char **)(*(_QWORD *)(v4 + 152) + 32i64), 0);
    *v2 = SSString::as_instance(v5);
    v6 = v13.i_str_ref_p;
    v7 = v13.i_str_ref_p->i_ref_count == 1;
    --v6->i_ref_count;
    if ( v7 )
    {
      if ( v6->i_deallocate )
        AMemory::c_free_func(v6->i_cstr_p);
      v8 = AStringRef::get_pool();
      v9 = v8->i_block_p;
      v10 = (unsigned __int64)v9->i_objects_a;
      if ( (unsigned __int64)v6 < v10
        || (v11 = (unsigned __int64)v6 < v10 + 24i64 * v9->i_size, v12 = &v8->i_pool, !v11) )
      {
        v12 = &v8->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v12, v6);
    }
  }
}

// File Line: 242
// RVA: 0x4FA850
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_layer_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  signed __int64 v3; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v3 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v3 = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)(*(_QWORD *)(v3 + 152) + 168i64));
  }
}

// File Line: 254
// RVA: 0x50C010
void __fastcall UFG::TSGameSlice::Mthd_start_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rcx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  UFG::GameSlice::SetState(*(UFG::GameSlice **)(v3 + 152), STATE_STARTED);
}

// File Line: 269
// RVA: 0x4F6920
void __fastcall UFG::TSGameSlice::Mthd_complete_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( v3 && v2->i_scope_p.i_ptr_id == v3->i_ptr_id )
    UFG::GameSlice::CompleteSlice((UFG::GameSlice *)v3[8].vfptr);
  else
    UFG::GameSlice::CompleteSlice(MEMORY[0x98]);
}

// File Line: 278
// RVA: 0x4FAC90
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_restore_vehicle_location_marker(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rdx
  __int64 v4; // r8
  SSData **v5; // rdx
  int v6; // xmm0_4

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(_QWORD *)(v3 + 152);
  if ( v4 )
  {
    v5 = pScope->i_data.i_array_p;
    v6 = v5[1]->i_data_p->i_user_data;
    *(_DWORD *)(v4 + 180) = (*v5)->i_data_p->i_user_data;
    *(_DWORD *)(v4 + 192) = v6;
  }
}

// File Line: 290
// RVA: 0x4FAC50
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_restore_location_marker(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rdx
  __int64 v4; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(_QWORD *)(v3 + 152);
  if ( v4 )
    *(_DWORD *)(v4 + 176) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 302
// RVA: 0x4FABA0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_cancel_location_marker(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rdx
  __int64 v4; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(_QWORD *)(v3 + 152);
  if ( v4 )
    *(_DWORD *)(v4 + 196) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 314
// RVA: 0x4FABE0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_complete_location_marker(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rdx
  __int64 v4; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(_QWORD *)(v3 + 152);
  if ( v4 )
    *(_DWORD *)(v4 + 200) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 327
// RVA: 0x4FAC20
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_restore_location(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qVector3 *v2; // rbx
  UFG::ProgressionTracker *v3; // rax

  v2 = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetScriptRestoreLocation(v3, v2);
}

// File Line: 337
// RVA: 0x4F3630
void __fastcall UFG::TSGameSlice::Mthd_ScriptTest_launch_if_available(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::DEBUG_LaunchTestScenarioIfAvailable(v2);
}

// File Line: 342
// RVA: 0x4F61C0
void __fastcall UFG::TSGameSlice::Mthd_borrow_ambient_actor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  SSObjectBase *v4; // r8
  signed __int64 v5; // r8
  UFG::GameSlice *v6; // rcx

  v2 = pScope;
  v3 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  if ( v3 )
  {
    v4 = v2->i_scope_p.i_obj_p;
    if ( v4 && v2->i_scope_p.i_ptr_id == v4->i_ptr_id )
      v5 = (signed __int64)&v4[-2].i_ptr_id;
    else
      v5 = 0i64;
    v6 = *(UFG::GameSlice **)(v5 + 152);
    if ( v6 )
      UFG::GameSlice::BorrowAmbientActor(v6, (UFG::SimObject *)v3);
  }
}

// File Line: 363
// RVA: 0x504D80
void __fastcall UFG::TSGameSlice::Mthd_missionscoring_add_cop_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatAction::MissionScoring::LogCopEvent(
    COP_SCRIPT_EVENT,
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 370
// RVA: 0x504DB0
void __fastcall UFG::TSGameSlice::Mthd_missionscoring_add_triad_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatAction::MissionScoring::LogTriadEvent(
    TRIAD_SCRIPT_EVENT,
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 381
// RVA: 0x4DA830
bool __fastcall UFG::TSGameSlice::Coro_fail_gameslice(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rdx
  signed __int64 v2; // rbx
  UFG::GameSlice *v3; // rbx
  SSInstance *i; // rdi
  UFG::ProgressionTracker *v5; // rax
  UFG::qString caption; // [rsp+28h] [rbp-30h]

  if ( !pScope->i_update_count )
  {
    v1 = pScope->i_scope_p.i_obj_p;
    if ( v1 && pScope->i_scope_p.i_ptr_id == v1->i_ptr_id )
      v2 = (signed __int64)&v1[-2].i_ptr_id;
    else
      v2 = 0i64;
    v3 = *(UFG::GameSlice **)(v2 + 152);
    for ( i = (*pScope->i_data.i_array_p)->i_data_p; v3; v3 = UFG::GameSlice::GetParent(v3) )
    {
      if ( !UFG::GameSlice::GetParent(v3) )
        break;
    }
    UFG::qString::qString(&caption, *(const char **)i->i_user_data);
    v5 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::OnFailGameSlice(v5, v3, &caption);
    UFG::qString::~qString(&caption);
  }
  return 0;
}

// File Line: 404
// RVA: 0x501580
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_restoring(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  signed __int64 v4; // rax
  __int64 v5; // rax
  bool v6; // bl
  UFG::GameStatTracker *v7; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v4 = 0i64;
    v5 = *(_QWORD *)(v4 + 152);
    v6 = *(_DWORD *)(v5 + 264) == 2;
    if ( *(_DWORD *)(v5 + 264) == 2 && !*(_QWORD *)(v5 + 368) && *(_DWORD *)(v5 + 268) > 0 )
    {
      v7 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v7, RestoreUsed, 1);
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 421
// RVA: 0x501490
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_exclusive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  signed __int64 v3; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v3 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v3 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(*(_BYTE *)(*(_QWORD *)(v3 + 152) + 324i64) != 0);
  }
}

// File Line: 433
// RVA: 0x501530
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_random_exclusive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  signed __int64 v3; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v3 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v3 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(*(_BYTE *)(*(_QWORD *)(v3 + 152) + 327i64) != 0);
  }
}

// File Line: 445
// RVA: 0x500F70
void __fastcall UFG::TSGameSlice::Mthd_is_challenge_mode(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::ProgressionTracker *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::ProgressionTracker::Instance();
    *v2 = (SSInstance *)SSBoolean::pool_new((unsigned int)(v3->mModeType - 1) <= 1);
  }
}

// File Line: 457
// RVA: 0x501610
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_single_container(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  signed __int64 v4; // rbx
  UFG::GameSlice *v5; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v4 = 0i64;
    v5 = *(UFG::GameSlice **)(v4 + 152);
    if ( !v5 || UFG::GameSlice::GetParent(v5) || (unsigned int)UFG::GameSlice::GetNumChildren(v5) )
      *v3 = (SSInstance *)SSBoolean::pool_new(0);
    else
      *v3 = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 469
// RVA: 0x501410
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_active_master(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  signed __int64 v4; // r8
  UFG::GameSlice *v5; // rbx
  UFG::ProgressionTracker *v6; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v4 = 0i64;
    v5 = *(UFG::GameSlice **)(v4 + 152);
    if ( v5 && (v6 = UFG::ProgressionTracker::Instance(), v5 == UFG::ProgressionTracker::GetActiveMaster(v6)) )
      *v3 = (SSInstance *)SSBoolean::pool_new(1);
    else
      *v3 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 481
// RVA: 0x4FAAE0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  signed __int64 v4; // rbx
  UFG::GameSlice *v5; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v4 = 0i64;
    v5 = *(UFG::GameSlice **)(v4 + 152);
    if ( !v5 )
      goto LABEL_9;
    while ( UFG::GameSlice::GetParent(v5) )
    {
      v5 = UFG::GameSlice::GetParent(v5);
      if ( !v5 )
        goto LABEL_9;
    }
    if ( v5 )
      *v3 = SSSymbol::as_instance((ASymbol *)UFG::gGameSliceTypeSymbols[v5->mType]);
    else
LABEL_9:
      *v3 = SSSymbol::as_instance((ASymbol *)UFG::gGameSliceTypeSymbols[0]);
  }
}

// File Line: 500
// RVA: 0x4E7180
void __fastcall UFG::TSGameSlice::MthdC_get_active_master(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSlice *v4; // rax
  UFG::SSGameSlice *v5; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::ProgressionTracker::Instance();
    v4 = UFG::ProgressionTracker::GetActiveMaster(v3);
    if ( v4 )
    {
      v5 = v4->mScript;
      if ( v5 )
      {
        ++v5->i_ref_count;
        *v2 = (SSInstance *)&v5->vfptr;
      }
      else
      {
        *v2 = 0i64;
      }
    }
    else
    {
      *v2 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 513
// RVA: 0x4EC3E0
void __fastcall UFG::TSGameSlice::MthdC_reset_gameslice_fail_timer_debug(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSlice *v4; // rbx

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::ProgressionTracker::Instance();
  v4 = (UFG::GameSlice *)UFG::ProgressionTracker::Find(v3, (UFG::qSymbol *)&v2->i_user_data, 0);
  if ( v4 )
  {
    do
    {
      if ( !UFG::GameSlice::GetParent(v4) )
        break;
      v4 = UFG::GameSlice::GetParent(v4);
    }
    while ( v4 );
    v4->mCompletionStatusTimestamp = 0i64;
  }
}

// File Line: 535
// RVA: 0x5014E0
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_failed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  signed __int64 v3; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v3 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v3 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(((*(_DWORD *)(*(_QWORD *)(v3 + 152) + 272i64) - 1) & 0xFFFFFFFD) == 0);
  }
}

// File Line: 548
// RVA: 0x503030
void __fastcall UFG::TSGameSlice::Mthd_is_progression_fail_pending(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::ProgressionTracker *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::ProgressionTracker::Instance();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3->mState == 10);
  }
}

// File Line: 562
// RVA: 0x503450
void __fastcall UFG::TSGameSlice::Mthd_is_target_gameslice_completed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInstance *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qBaseTreeRB *v5; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p;
    v4 = UFG::ProgressionTracker::Instance();
    v5 = UFG::ProgressionTracker::Find(v4, (UFG::qSymbol *)&v3->i_user_data, 0);
    if ( v5 )
      *v2 = (SSInstance *)SSBoolean::pool_new(LODWORD(v5[3].mNULL.mChild[1]) == 8);
    else
      *v2 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 583
// RVA: 0x4FA790
void __fastcall UFG::TSGameSlice::Mthd_gameslice_exit_challenge_private(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::ProgressionTracker *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ExitChallenge(v3, v2);
}

// File Line: 593
// RVA: 0x4FAB80
void __fastcall UFG::TSGameSlice::Mthd_gameslice_restore_checkpoint_private(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::RestoreCheckpoint(v2);
}

// File Line: 601
// RVA: 0x4FA210
void __fastcall UFG::TSGameSlice::Mthd_gameslice_cancel_mission_private(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::ProgressionTracker::RestoreType v3; // ebx
  signed __int64 v4; // rdx
  UFG::GameSlice *v5; // rsi
  SSData **v6; // rdx
  SSInstance *v7; // rdi
  bool v8; // bp
  UFG::qBaseTreeRB *v9; // rax
  UFG::TransformNodeComponent *v10; // rbx
  UFG::ProgressionTracker *v11; // rax
  UFG::ProgressionTracker *v12; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v4 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v4 = 0i64;
  v5 = *(UFG::GameSlice **)(v4 + 152);
  v6 = pScope->i_data.i_array_p;
  v7 = v6[1]->i_data_p;
  v8 = (*v6)->i_data_p->i_user_data != 0;
  if ( LODWORD(v7->i_user_data) == UFG::qSymbol::create_from_string(&result, "safehouse")->mUID )
    goto LABEL_18;
  if ( LODWORD(v7->i_user_data) == UFG::qSymbol::create_from_string(&result, "hospital")->mUID )
  {
    v3 = 5;
    goto LABEL_19;
  }
  if ( LODWORD(v7->i_user_data) == UFG::qSymbol::create_from_string(&result, "policestation")->mUID )
  {
    v3 = 6;
    goto LABEL_19;
  }
  if ( LODWORD(v7->i_user_data) != UFG::qSymbol::create_from_string(&result, "cancelmarker")->mUID )
  {
    if ( LODWORD(v7->i_user_data) != UFG::qSymbol::create_from_string(&result, "currentlocation")->mUID )
      goto LABEL_19;
    if ( LocalPlayer )
    {
      v10 = LocalPlayer->m_pTransformNodeComponent;
      if ( v10 )
        goto LABEL_14;
    }
LABEL_18:
    v3 = 3;
    goto LABEL_19;
  }
  result.mUID = UFG::GameSlice::GetCancelLocationMarker(v5)->mUID;
  if ( result.mUID != -1 )
  {
    v9 = UFG::MarkerBase::GetNamed(&result);
    if ( v9 )
    {
      v10 = (UFG::TransformNodeComponent *)v9[1].mNULL.mParent;
LABEL_14:
      UFG::TransformNodeComponent::UpdateWorldTransform(v10);
      v11 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::SetScriptRestoreLocation(v11, (UFG::qVector3 *)&v10->mWorldTransform.v3);
      v3 = 7;
      goto LABEL_19;
    }
  }
LABEL_19:
  v12 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::CancelMission(v12, v5, v8, v3);
}

// File Line: 662
// RVA: 0x4FAA60
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_rewards_properties(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  signed __int64 v4; // rcx
  UFG::qPropertySet *v5; // rax
  unsigned __int64 v6; // rdi

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v4 = 0i64;
    v5 = UFG::GameSlice::GetRewardsProperties(*(UFG::GameSlice **)(v4 + 152));
    v6 = (unsigned __int64)v5;
    if ( v5 )
    {
      UFG::qPropertySet::AddRef(v5);
      *v3 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, v6);
    }
    else
    {
      *v3 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 675
// RVA: 0x4FA9A0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_restore_vehicle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  signed __int64 v4; // rax
  UFG::SimObject *v5; // rcx
  UFG::TSActorComponent *v6; // rax
  SSActorClass *v7; // rsi
  UFG::TSActorComponent *v8; // rdi
  SSClass *v9; // rcx
  SSClass *v10; // rcx
  UFG::TSActor *v11; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v4 = 0i64;
    v5 = *(UFG::SimObject **)(*(_QWORD *)(v4 + 152) + 512i64);
    if ( v5
      && ((v6 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v5, UFG::TSActorComponent::_TypeUID),
           v7 = UFG::TSVehicle::mClass,
           v8 = v6,
           v9 = UFG::TSActorComponent::GetActor(v6)->i_class_p,
           v7 == (SSActorClass *)v9)
       || (v10 = v9->i_superclass_p) != 0i64 && SSClass::is_class(v10, (SSClass *)&v7->vfptr)) )
    {
      v11 = UFG::TSActorComponent::GetActor(v8);
      ++v11->i_ref_count;
      *v3 = (SSInstance *)&v11->vfptr;
    }
    else
    {
      *v3 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 735
// RVA: 0x4FA530
void __fastcall UFG::TSGameSlice::Mthd_gameslice_enable_on_enter_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // rbx
  signed __int64 v4; // rdx
  fastdelegate::detail::GenericClass *v5; // r14
  SSInstance *v6; // rdx
  UFG::TriggerRegion *v7; // rdi
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  __int64 v10; // rcx
  UFG::TriggerTarget *v11; // rbx
  __int64 i; // rbp
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v13; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v14; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v4 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v4 = 0i64;
  v5 = *(fastdelegate::detail::GenericClass **)(v4 + 152);
  v6 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !v6 )
    goto LABEL_17;
  if ( v6->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    v7 = (UFG::TriggerRegion *)v6->i_user_data;
    goto LABEL_12;
  }
  v8 = v6->i_user_data;
  if ( !v8
    || (v9 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v8)) == 0i64
    || (v7 = (UFG::TriggerRegion *)&v9[-2].mNULL, v9 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_17:
    v7 = 0i64;
  }
LABEL_12:
  v10 = *((_QWORD *)v3->i_data.i_array_p + 1);
  v11 = (UFG::TriggerTarget *)v7->mTrackList.mNode.mNext;
  for ( i = *(_QWORD *)(v10 + 8);
        v11 != (UFG::TriggerTarget *)&v7->mTrackList;
        v11 = (UFG::TriggerTarget *)v7->mTrackList.mNode.mNext )
  {
    v13 = v11->mPrev;
    v14 = v11->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v11->mPrev = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&v11->mPrev;
    v11->mNext = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&v11->mPrev;
    UFG::TriggerTarget::~TriggerTarget(v11);
    operator delete[](v11);
  }
  UFG::TriggerRegion::ResetEvents(v7);
  UFG::TriggerRegion::TrackTarget(v7, *(UFG::SimObject **)(i + 208), 0i64);
  v7->mOnEnteredDelegate.m_Closure.m_pthis = v5;
  v7->mOnEnteredDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::GameSlice::OnEnterTrigger;
  UFG::TriggerRegion::EnableHot(v7, 1);
}

// File Line: 755
// RVA: 0x4FA660
void __fastcall UFG::TSGameSlice::Mthd_gameslice_enable_on_exit_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // rbx
  signed __int64 v4; // rdx
  fastdelegate::detail::GenericClass *v5; // r14
  SSInstance *v6; // rdx
  UFG::TriggerRegion *v7; // rdi
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  __int64 v10; // rcx
  UFG::TriggerTarget *v11; // rbx
  __int64 i; // rbp
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v13; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v14; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v4 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v4 = 0i64;
  v5 = *(fastdelegate::detail::GenericClass **)(v4 + 152);
  v6 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !v6 )
    goto LABEL_17;
  if ( v6->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    v7 = (UFG::TriggerRegion *)v6->i_user_data;
    goto LABEL_12;
  }
  v8 = v6->i_user_data;
  if ( !v8
    || (v9 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v8)) == 0i64
    || (v7 = (UFG::TriggerRegion *)&v9[-2].mNULL, v9 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_17:
    v7 = 0i64;
  }
LABEL_12:
  v10 = *((_QWORD *)v3->i_data.i_array_p + 1);
  v11 = (UFG::TriggerTarget *)v7->mTrackList.mNode.mNext;
  for ( i = *(_QWORD *)(v10 + 8);
        v11 != (UFG::TriggerTarget *)&v7->mTrackList;
        v11 = (UFG::TriggerTarget *)v7->mTrackList.mNode.mNext )
  {
    v13 = v11->mPrev;
    v14 = v11->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v11->mPrev = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&v11->mPrev;
    v11->mNext = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&v11->mPrev;
    UFG::TriggerTarget::~TriggerTarget(v11);
    operator delete[](v11);
  }
  UFG::TriggerRegion::ResetEvents(v7);
  UFG::TriggerRegion::TrackTarget(v7, *(UFG::SimObject **)(i + 208), 0i64);
  v7->mOnExitedDelegate.m_Closure.m_pthis = v5;
  v7->mOnExitedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::GameSlice::OnExitTrigger;
  UFG::TriggerRegion::EnableHot(v7, 1);
}

// File Line: 775
// RVA: 0x4FA450
void __fastcall UFG::TSGameSlice::Mthd_gameslice_disable_on_enter_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdx
  UFG::TriggerRegion *v3; // rcx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !v2 )
    goto LABEL_11;
  if ( v2->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    v3 = (UFG::TriggerRegion *)v2->i_user_data;
    goto LABEL_8;
  }
  v4 = v2->i_user_data;
  if ( !v4
    || (v5 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v4)) == 0i64
    || (v3 = (UFG::TriggerRegion *)&v5[-2].mNULL, v5 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_11:
    v3 = 0i64;
  }
LABEL_8:
  v3->mOnEnteredDelegate.m_Closure.m_pFunction = 0i64;
  v3->mOnEnteredDelegate.m_Closure.m_pthis = 0i64;
  UFG::TriggerRegion::EnableHot(v3, 0);
}

// File Line: 787
// RVA: 0x4FA4C0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_disable_on_exit_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdx
  UFG::TriggerRegion *v3; // rcx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !v2 )
    goto LABEL_11;
  if ( v2->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    v3 = (UFG::TriggerRegion *)v2->i_user_data;
    goto LABEL_8;
  }
  v4 = v2->i_user_data;
  if ( !v4
    || (v5 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v4)) == 0i64
    || (v3 = (UFG::TriggerRegion *)&v5[-2].mNULL, v5 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_11:
    v3 = 0i64;
  }
LABEL_8:
  v3->mOnExitedDelegate.m_Closure.m_pFunction = 0i64;
  v3->mOnExitedDelegate.m_Closure.m_pthis = 0i64;
  UFG::TriggerRegion::EnableHot(v3, 0);
}

// File Line: 799
// RVA: 0x4FA950
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_progression_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  signed __int64 v3; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v3 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v3 = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)(*(_QWORD *)(v3 + 152) + 172i64));
  }
}

// File Line: 811
// RVA: 0x4DB2D0
bool __fastcall UFG::TSGameSlice::Coro_gameslice_play_intro_nis(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rdx
  SSInvokedCoroutine *v2; // rsi
  signed __int64 v3; // rdx
  __int64 v4; // rbp
  UFG::qSharedStringData *v5; // rbx
  const char *v7; // rbx
  NISManager *v8; // rax
  NISInstance *v9; // rax
  NISInstance *v10; // rbx
  NISManager *v11; // rax

  v1 = pScope->i_scope_p.i_obj_p;
  v2 = pScope;
  if ( v1 && pScope->i_scope_p.i_ptr_id == v1->i_ptr_id )
    v3 = (signed __int64)&v1[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(_QWORD *)(v3 + 152);
  v5 = (UFG::qSharedStringData *)(*(_QWORD *)(v4 + 64) - 48i64);
  if ( v5 == UFG::qSharedStringData::GetEmptyString() )
    return 1;
  if ( v2->i_update_count || NISManager::GetInstance()->mState )
    return NISManager::GetInstance()->mState == 0;
  v7 = *(const char **)(v4 + 64);
  v8 = NISManager::GetInstance();
  v9 = NISManager::CreateInstance(v8, v7);
  v10 = v9;
  v9->mbDestroyOnUnload = 1;
  v9->mbIntermediateNIS = *(_BYTE *)(v4 + 81);
  v9->mbPostNISFadeIn = *(_BYTE *)(v4 + 80);
  v9->mpPostNISSceneSettings = *(UFG::SceneSettings **)(v4 + 72);
  v11 = NISManager::GetInstance();
  NISManager::Play(v11, v10);
  return 0;
}

// File Line: 841
// RVA: 0x4DB1B0
bool __fastcall UFG::TSGameSlice::Coro_gameslice_code_setup(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rsi
  SSObjectBase *v2; // rcx
  signed __int64 v3; // rdi
  __int64 v4; // rdi
  signed int v5; // ebx
  UFG::CopSystem *v6; // rax
  UFG::SceneSettings *v7; // rbx
  UFG::ProgressionTracker *v8; // rax
  UFG::ProgressionTracker *v9; // rax
  UFG::SceneSettings *v10; // rbx
  UFG::ProgressionTracker *v11; // rax
  bool result; // al

  v1 = pScope;
  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || (v3 = (signed __int64)&v2[-2].i_ptr_id, v1->i_scope_p.i_ptr_id != v2->i_ptr_id) )
    v3 = 0i64;
  v4 = *(_QWORD *)(v3 + 152);
  if ( !v1->i_update_count )
  {
    v5 = *(_DWORD *)(v4 + 208);
    if ( v5 > 0 )
    {
      v6 = UFG::CopSystem::Instance();
      v6->vfptr[100].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v6->vfptr, v5);
    }
  }
  if ( UFG::GameSlice::ShouldTeleportVehicleOnStart((UFG::GameSlice *)v4) )
  {
    v7 = *(UFG::SceneSettings **)(v4 + 352);
    v8 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::TeleportVehicle(v8, v7);
  }
  if ( UFG::GameSlice::ShouldDestroyVehicleOnStart((UFG::GameSlice *)v4) )
  {
    v9 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::DestroyVehicle(v9);
  }
  UFG::GameSlice::SetupPedsAndVehicles((UFG::GameSlice *)v4);
  UFG::GameSlice::SetupSceneLayers((UFG::GameSlice *)v4);
  if ( *(_DWORD *)(v4 + 268) != 4 && UFG::GameSlice::ShouldTeleportOnStart((UFG::GameSlice *)v4) )
  {
    if ( v1->i_update_count )
    {
      result = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_10;
    }
    else
    {
      v10 = *(UFG::SceneSettings **)(v4 + 352);
      v11 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::ApplySceneSettings(v11, v10);
      result = 0;
    }
  }
  else
  {
    UFG::GameSlice::SetupTimeAndWeather((UFG::GameSlice *)v4, 0);
    result = 1;
  }
  return result;
}

// File Line: 897
// RVA: 0x4FA3F0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_code_cleanup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  signed __int64 v3; // rbx
  UFG::GameSlice *v4; // rbx
  UFG::CopSystem *v5; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(UFG::GameSlice **)(v3 + 152);
  if ( v4->mMaxHeatLevel > 0 )
  {
    v5 = UFG::CopSystem::Instance();
    ((void (__fastcall *)(UFG::CopSystem *))v5->vfptr[101].__vecDelDtor)(v5);
  }
  UFG::GameSlice::CleanupTimeAndWeather(v4);
  UFG::GameSlice::CleanupPedsAndVehicles(v4);
  UFG::GameSlice::CleanupSceneLayers(v4);
}

// File Line: 922
// RVA: 0x4FA380
void __fastcall UFG::TSGameSlice::Mthd_gameslice_claim_exclusive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  signed __int64 v4; // rbx
  UFG::GameSlice *v5; // rbx
  char v6; // cl

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v4 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v4 = 0i64;
  v5 = *(UFG::GameSlice **)(v4 + 152);
  if ( (unsigned __int8)UFG::GameSlice::IsExclusiveAvailable(v5) )
  {
    UFG::GameSlice::ClaimExclusive(v5);
    v6 = 1;
  }
  else
  {
    v6 = v5->mExclusiveChild == v5;
  }
  if ( v3 )
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 948
// RVA: 0x4FA7C0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_completion_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // edi
  SSInstance **v4; // rsi
  signed __int64 v5; // rbx
  UFG::GameSlice *v6; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    if ( !v2 || (v5 = (signed __int64)&v2[-2].i_ptr_id, pScope->i_scope_p.i_ptr_id != v2->i_ptr_id) )
      v5 = 0i64;
    v6 = *(UFG::GameSlice **)(v5 + 152);
    if ( v6 )
    {
      while ( UFG::GameSlice::GetParent(v6) )
      {
        v6 = UFG::GameSlice::GetParent(v6);
        if ( !v6 )
          goto LABEL_11;
      }
      if ( v6 )
        v3 = v6->mCompletionCount;
    }
LABEL_11:
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
  }
}

// File Line: 966
// RVA: 0x4DB400
bool __fastcall UFG::TSGameSlice::Coro_gameslice_wait_progression_trigger_private(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rdx
  bool v2; // zf
  signed __int64 v3; // rcx

  v1 = pScope->i_scope_p.i_obj_p;
  if ( !v1 || (v2 = pScope->i_scope_p.i_ptr_id == v1->i_ptr_id, v3 = (signed __int64)&v1[-2].i_ptr_id, !v2) )
    v3 = 0i64;
  return (unsigned __int8)UFG::GameSlice::IsWaitingForTrigger(*(UFG::GameSlice **)(v3 + 152)) == 0;
}

// File Line: 973
// RVA: 0x4DB3A0
bool __fastcall UFG::TSGameSlice::Coro_gameslice_wait_case_open_private(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rdx
  signed __int64 v2; // rdx
  __int64 v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::CaseInfo *v5; // rax
  bool result; // al

  v1 = pScope->i_scope_p.i_obj_p;
  if ( v1 && pScope->i_scope_p.i_ptr_id == v1->i_ptr_id )
    v2 = (signed __int64)&v1[-2].i_ptr_id;
  else
    v2 = 0i64;
  v3 = *(_QWORD *)(v2 + 152);
  if ( *(_DWORD *)(v3 + 268) == 10
    && (v4 = UFG::ProgressionTracker::Instance(),
        (v5 = UFG::CaseTracker::GetCase(&v4->mCaseTracker, (UFG::GameSlice *)v3)) != 0i64) )
  {
    result = UFG::CaseInfo::IsOpened(v5);
  }
  else
  {
    result = 1;
  }
  return result;
}

// File Line: 987
// RVA: 0x4DB440
bool __fastcall UFG::TSWorld::Coro_wait_until_in_game_state(SSInvokedCoroutine *pScope)
{
  return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_10;
}

// File Line: 992
// RVA: 0x4DB460
bool __fastcall UFG::TSGameSlice::Coro_gameslice_wait_until_tracker_running(SSInvokedCoroutine *pScope)
{
  UFG::ProgressionTracker *v1; // rax

  v1 = UFG::ProgressionTracker::Instance();
  return !v1->mDirty && v1->mState == 3;
}

// File Line: 998
// RVA: 0x4F8D40
void __fastcall UFG::TSGameSlice::Mthd_enable_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rdi
  UFG::GameSlice *v4; // rdi
  UFG::ObjectiveTracker *v5; // rbx
  UFG::Objective *v6; // rdi
  UFG::qSharedStringData *v7; // rbx
  const char *v8; // rbx
  UFG::GameLogManager *v9; // rcx
  UFG::qString identifier; // [rsp+28h] [rbp-30h]
  UFG::qSymbol log_type; // [rsp+60h] [rbp+8h]
  UFG::qSymbol *v12; // [rsp+70h] [rbp+18h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(UFG::GameSlice **)(v3 + 152);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v5 = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
  UFG::ObjectiveTracker::UpdateStatus(v5, &identifier, STATUS_ACTIVE, v4);
  v6 = UFG::ObjectiveTracker::FindObjective(v5, &identifier);
  v12 = &log_type;
  log_type.mUID = qSymbol_GameLogType_Objective_15.mUID;
  v7 = (UFG::qSharedStringData *)(v6->mLog.mText - 48);
  if ( v7 == UFG::qSharedStringData::GetEmptyString() )
    v8 = v6->mCaption.mData;
  else
    v8 = v6->mLog.mText;
  v9 = UFG::GameLogManager::getInstance();
  UFG::GameLogManager::LogItem(v9, (UFG::qSymbol)&log_type, v8);
  UFG::qString::~qString(&identifier);
}

// File Line: 1009
// RVA: 0x4F8500
void __fastcall UFG::TSGameSlice::Mthd_disable_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rbx
  UFG::GameSlice *v4; // rbx
  UFG::ProgressionTracker *v5; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(UFG::GameSlice **)(v3 + 152);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v5 = UFG::ProgressionTracker::Instance();
  UFG::ObjectiveTracker::UpdateStatus(&v5->mObjectiveTracker, &identifier, 0, v4);
  UFG::qString::~qString(&identifier);
}

// File Line: 1017
// RVA: 0x509060
void __fastcall UFG::TSGameSlice::Mthd_set_objective_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  SSObjectBase *v3; // rdx
  signed __int64 v4; // rbx
  UFG::GameSlice *v5; // rbx
  UFG::ProgressionTracker *v6; // rax
  UFG::qString caption; // [rsp+28h] [rbp-60h]
  UFG::qString identifier; // [rsp+50h] [rbp-38h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( v3 && pScope->i_scope_p.i_ptr_id == v3->i_ptr_id )
    v4 = (signed __int64)&v3[-2].i_ptr_id;
  else
    v4 = 0i64;
  v5 = *(UFG::GameSlice **)(v4 + 152);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::qString::qString(&caption, **(const char ***)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
  v6 = UFG::ProgressionTracker::Instance();
  UFG::ObjectiveTracker::UpdateCaption(&v6->mObjectiveTracker, &identifier, &caption, v5);
  UFG::qString::~qString(&caption);
  UFG::qString::~qString(&identifier);
}

// File Line: 1026
// RVA: 0x509120
void __fastcall UFG::TSGameSlice::Mthd_set_objective_status(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSObjectBase *v3; // rdx
  signed __int64 v4; // rdi
  UFG::GameSlice *v5; // rdi
  UFG::Objective::Status v6; // ebx
  UFG::ProgressionTracker *v7; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( v3 && pScope->i_scope_p.i_ptr_id == v3->i_ptr_id )
    v4 = (signed __int64)&v3[-2].i_ptr_id;
  else
    v4 = 0i64;
  v5 = *(UFG::GameSlice **)(v4 + 152);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v6 = (unsigned int)UFG::Objective::MapSymbolToStatus((ASymbol *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1)
                                                                             + 8i64)
                                                                 + 32i64));
  v7 = UFG::ProgressionTracker::Instance();
  UFG::ObjectiveTracker::UpdateStatus(&v7->mObjectiveTracker, &identifier, v6, v5);
  UFG::qString::~qString(&identifier);
}

// File Line: 1035
// RVA: 0x4F59A0
void __fastcall UFG::TSGameSlice::Mthd_attach_to_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // rdx
  bool v4; // si
  SSInstance *v5; // rbx
  SSClass *v6; // rcx
  UFG::ProgressionTracker *v7; // rax
  UFG::ObjectiveTracker *v8; // rdi
  UFG::Objective *v9; // rax
  UFG::Objective *v10; // rbx
  UFG::qString blip; // [rsp+38h] [rbp-B0h]
  UFG::qString identifier; // [rsp+60h] [rbp-88h]
  UFG::qString corona; // [rsp+88h] [rbp-60h]
  UFG::qString v14; // [rsp+B0h] [rbp-38h]
  UFG::qSymbol v15; // [rsp+F0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+100h] [rbp+18h]

  v2 = pScope;
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::qString::qString(&blip, **(const char ***)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64) + 32i64));
  UFG::qString::qString(&corona, **(const char ***)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64) + 32i64));
  v3 = v2->i_data.i_array_p;
  v4 = v3[4]->i_data_p->i_user_data != 0;
  v15.mUID = -1;
  v5 = v3[1]->i_data_p;
  if ( v5 )
  {
    v6 = v5->i_class_p;
    if ( v6 == SSBrain::c_string_class_p )
    {
      UFG::qString::qString(&v14, *(const char **)v5->i_user_data);
      v15.mUID = UFG::qSymbol::create_from_string(&result, v14.mData)->mUID;
      UFG::qString::~qString(&v14);
    }
    else if ( v6 == SSBrain::c_symbol_class_p )
    {
      v15.mUID = v5->i_user_data;
    }
    else
    {
      if ( !((unsigned __int8 (*)(void))v6->vfptr->is_actor_class)() )
        goto LABEL_10;
      v15.mUID = *(_DWORD *)(*(_QWORD *)&v5[4].i_ref_count + 72i64);
    }
    v7 = UFG::ProgressionTracker::Instance();
    v8 = &v7->mObjectiveTracker;
    v9 = UFG::ObjectiveTracker::FindObjective(&v7->mObjectiveTracker, &identifier);
    v10 = v9;
    if ( v9 )
    {
      UFG::Objective::AddIndicator(v9, &v15, &blip, &corona, 1);
      UFG::ObjectiveTracker::UpdateStatus(v8, v10, v4);
    }
  }
LABEL_10:
  UFG::qString::~qString(&corona);
  UFG::qString::~qString(&blip);
  UFG::qString::~qString(&identifier);
}

// File Line: 1063
// RVA: 0x506520
void __fastcall UFG::TSGameSlice::Mthd_remove_from_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  __int64 v3; // rbx
  SSClass *v4; // rcx
  UFG::ProgressionTracker *v5; // rax
  UFG::ObjectiveTracker *v6; // rdi
  UFG::Objective *v7; // rax
  UFG::Objective *v8; // rbx
  UFG::qString identifier; // [rsp+28h] [rbp-60h]
  UFG::qString v10; // [rsp+50h] [rbp-38h]
  UFG::qSymbol name; // [rsp+90h] [rbp+8h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+18h]

  v2 = pScope;
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  name.mUID = -1;
  v3 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  if ( v3 )
  {
    v4 = *(SSClass **)(v3 + 24);
    if ( v4 == SSBrain::c_string_class_p )
    {
      UFG::qString::qString(&v10, **(const char ***)(v3 + 32));
      name.mUID = UFG::qSymbol::create_from_string(&result, v10.mData)->mUID;
      UFG::qString::~qString(&v10);
    }
    else if ( v4 == SSBrain::c_symbol_class_p )
    {
      name.mUID = *(_DWORD *)(v3 + 32);
    }
    else
    {
      if ( !((unsigned __int8 (*)(void))v4->vfptr->is_actor_class)() )
        goto LABEL_10;
      name.mUID = *(_DWORD *)(*(_QWORD *)(v3 + 208) + 72i64);
    }
    v5 = UFG::ProgressionTracker::Instance();
    v6 = &v5->mObjectiveTracker;
    v7 = UFG::ObjectiveTracker::FindObjective(&v5->mObjectiveTracker, &identifier);
    v8 = v7;
    if ( v7 )
    {
      UFG::Objective::RemoveIndicator(v7, &name, 1);
      UFG::ObjectiveTracker::UpdateStatus(v6, v8, 0);
    }
  }
LABEL_10:
  UFG::qString::~qString(&identifier);
}

// File Line: 1094
// RVA: 0x502850
void __fastcall UFG::TSGameSlice::Mthd_is_objective_complete(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  bool v3; // di
  UFG::ProgressionTracker *v4; // rax
  UFG::Objective *v5; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = 0;
    UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = UFG::ProgressionTracker::Instance();
    v5 = UFG::ObjectiveTracker::FindObjective(&v4->mObjectiveTracker, &identifier);
    if ( v5 )
      v3 = v5->mStatus == 3;
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
    UFG::qString::~qString(&identifier);
  }
}

// File Line: 1129
// RVA: 0x503170
void __fastcall UFG::TSGameSlice::Mthd_is_single_character_sprinkle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  signed __int64 v3; // r8
  __int64 v4; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v3 = (signed __int64)&v2[-2].i_ptr_id;
    else
      v3 = 0i64;
    v4 = *(_QWORD *)(v3 + 152);
    if ( *(_DWORD *)(v4 + 268) == 4 && *(_BYTE *)(v4 + 481) )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 1147
// RVA: 0x4FDAE0
void __fastcall UFG::TSGameSlice::Mthd_get_override_for_sprinkle_character(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  int v3; // edx
  SSObjectBase *v4; // r8
  signed __int64 v5; // rax
  ASymbol *v6; // rax
  ASymbol *v7; // rcx

  v2 = ppResult;
  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v2 )
  {
    v4 = pScope->i_scope_p.i_obj_p;
    if ( v4 && pScope->i_scope_p.i_ptr_id == v4->i_ptr_id )
      v5 = (signed __int64)&v4[-2].i_ptr_id;
    else
      v5 = 0i64;
    v6 = *(ASymbol **)(v5 + 152);
    v7 = v6 + 121;
    if ( v3 )
      v7 = v6 + 122;
    *v2 = SSSymbol::as_instance(v7);
  }
}

// File Line: 1162
// RVA: 0x4F9C90
void __fastcall UFG::TSGameSlice::Mthd_faction_get_standing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // r14
  UFG::qSymbol *v4; // rdi
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rsi
  UFG::eFactionClassEnum v7; // eax
  UFG::eFactionStandingEnum v8; // eax
  UFG::qStaticSymbol *v9; // rax

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = (UFG::qSymbol *)(*v2)->i_data_p;
    v5 = (UFG::qSymbol *)v2[1]->i_data_p;
    v6 = UFG::FactionInterface::Get();
    LODWORD(v5) = UFG::FactionInterface::MapSymbolToFaction(v5 + 8);
    v7 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(v4 + 8);
    v8 = (unsigned int)UFG::FactionInterface::GetStanding(&v6->mFactionInterface, v7, (UFG::eFactionClassEnum)v5);
    v9 = UFG::FactionInterface::MapStandingToSymbol(&v6->mFactionInterface, v8);
    *v3 = SSSymbol::as_instance((ASymbol *)v9);
  }
}

// File Line: 1177
// RVA: 0x507380
void __fastcall UFG::TSGameSlice::Mthd_set_battle_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::eBattleType v3; // eax
  char *v4; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = (unsigned int)UFG::GetBattleTypeFromName((UFG::qSymbol *)&v2->i_user_data);
  if ( v3 == -1 )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->i_user_data);
    UFG::qPrintf("Script error: invalid battle type '%s'\n", v4);
  }
  else
  {
    UFG::BattleManager::s_pInstance->m_CurrentBattleType = v3;
  }
}

// File Line: 1194
// RVA: 0x4F6E50
void __fastcall UFG::TSGameSlice::Mthd_cops_enable_ambient_units(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::CopSystem *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = UFG::CopSystem::Instance();
  v3->vfptr[85].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, v2);
}

// File Line: 1201
// RVA: 0x4F6DF0
void __fastcall UFG::TSGameSlice::Mthd_cops_enable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rax
  bool v3; // bl
  UFG::CopSystem *v4; // rax
  UFG::CopSystem *v5; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = v2->i_user_data != 0;
  if ( !v2->i_user_data )
  {
    v4 = UFG::CopSystem::Instance();
    if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v4->vfptr[89].__vecDelDtor)(v4) )
      UFG::CopSystem::Instance()->mStats.mFinishReason = 4;
  }
  v5 = UFG::CopSystem::Instance();
  v5->vfptr[4].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v3);
}

// File Line: 1213
// RVA: 0x4F7070
void __fastcall UFG::TSGameSlice::Mthd_cops_set_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  unsigned int v3; // edi
  UFG::CopSystem *v4; // rax
  UFG::CopSystem *v5; // rbx
  __int64 v6; // rax
  UFG::CopSystem *v7; // rax
  UFG::qString v8; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v4->vfptr[89].__vecDelDtor)(v4) && !v3 )
    UFG::CopSystem::Instance()->mStats.mFinishReason = 4;
  v5 = UFG::CopSystem::Instance();
  UFG::qString::qString(&v8, **(const char ***)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
  LODWORD(v5) = (__int64)v5->vfptr[109].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v5->vfptr, v6);
  UFG::qString::~qString(&v8);
  v7 = UFG::CopSystem::Instance();
  ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v7->vfptr[88].__vecDelDtor)(v7, v3, (unsigned int)v5);
}

// File Line: 1227
// RVA: 0x4F6D90
void __fastcall UFG::TSGameSlice::Mthd_cops_debug_cap_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // ebx
  UFG::CopSystem *v3; // rax
  UFG::CopSystem *v4; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) && !v2 )
    UFG::CopSystem::Instance()->mStats.mFinishReason = 4;
  v4 = UFG::CopSystem::Instance();
  v4->vfptr[100].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, v2);
}

// File Line: 1240
// RVA: 0x4F6F40
void __fastcall UFG::TSGameSlice::Mthd_cops_exclude_player_for_rest_of_chase(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CopSystem *v2; // rax
  UFG::CopSystem *v3; // rax

  if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
  {
    v2 = UFG::CopSystem::Instance();
    ((void (__fastcall *)(UFG::CopSystem *))v2->vfptr[102].__vecDelDtor)(v2);
  }
  else
  {
    v3 = UFG::CopSystem::Instance();
    ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[103].__vecDelDtor)(v3);
  }
}

// File Line: 1253
// RVA: 0x4F6E90
void __fastcall UFG::TSGameSlice::Mthd_cops_escalate_to_minimum_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  signed int v3; // esi
  UFG::CopSystem *v4; // rdi
  __int64 v5; // rax
  unsigned int v6; // ebx
  UFG::CopSystem *v7; // rax
  UFG::CopSystem *v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = UFG::CopSystem::Instance();
  UFG::qString::qString(&v9, **(const char ***)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
  v6 = (__int64)v4->vfptr[109].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, v5);
  UFG::qString::~qString(&v9);
  v7 = UFG::CopSystem::Instance();
  if ( ((signed int (__fastcall *)(UFG::CopSystem *))v7->vfptr[89].__vecDelDtor)(v7) < v3 )
  {
    v8 = UFG::CopSystem::Instance();
    ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v8->vfptr[88].__vecDelDtor)(v8, (unsigned int)v3, v6);
  }
}

// File Line: 1265
// RVA: 0x4F7000
void __usercall UFG::TSGameSlice::Mthd_cops_get_ratio_for_current_heat_level(SSInvokedMethod *pScope@<rcx>, SSInstance **ppResult@<rdx>, unsigned int a3@<xmm0>)
{
  SSInstance **v3; // rbx
  UFG::CopSystem *v4; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::CopSystem::Instance();
    ((void (__fastcall *)(UFG::CopSystem *))v4->vfptr[90].__vecDelDtor)(v4);
    *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, a3);
  }
}

// File Line: 1274
// RVA: 0x4F6FC0
void __fastcall UFG::TSGameSlice::Mthd_cops_get_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::CopSystem *v3; // rax
  unsigned int v4; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::CopSystem::Instance();
    v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3);
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
  }
}

// File Line: 1283
// RVA: 0x4F6F90
void __fastcall UFG::TSGameSlice::Mthd_cops_get_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::CopSystem *v3; // rax
  char v4; // al

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::CopSystem::Instance();
    v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[7].__vecDelDtor)(v3);
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 1291
// RVA: 0x4F7130
void __fastcall UFG::TSGameSlice::Mthd_cops_trigger_instant_cooldown(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  ((void (__fastcall *)(UFG::CopSystem *))v2->vfptr[9].__vecDelDtor)(v2);
}

// File Line: 1296
// RVA: 0x4F7040
void __fastcall UFG::TSGameSlice::Mthd_cops_is_cooling_down(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::CopSystem *v3; // rax
  char v4; // al

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::CopSystem::Instance();
    v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[8].__vecDelDtor)(v3);
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 1304
// RVA: 0x4DEC80
bool __fastcall UFG::TSGameSlice::Coro_wait_until_cops_heat_level_below(SSInvokedCoroutine *pScope)
{
  signed int v2; // ebx
  UFG::CopSystem *v3; // rax

  if ( pScope->i_update_count < 0xA )
    return 0;
  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::CopSystem::Instance();
  return ((signed int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) < v2;
}

// File Line: 1325
// RVA: 0x50F490
void __fastcall UFG::RayCastToTargetAsyncRayCallback(UFG::RayCastData *raycastData, UFG::SimComponent *simComponent, void *callbackUserData)
{
  SSInvokedContextBase *v3; // rbx
  UFG::RayCastData *v4; // rdi
  UFG::qBaseNodeRB *v5; // rax
  _BOOL8 v6; // r8
  SSData *v7; // rdx
  SSInstance *v8; // rax
  UFG::SimObject *ray_hit_object; // [rsp+40h] [rbp+18h]

  v3 = *(SSInvokedContextBase **)callbackUserData;
  v4 = raycastData;
  if ( !*(_QWORD *)callbackUserData || *((_DWORD *)callbackUserData + 2) != v3->i_ptr_id )
    v3 = 0i64;
  operator delete[](callbackUserData);
  if ( v3 )
  {
    v5 = UFG::TSSimObject::GetArgByNameOrInstance(v3, 1u);
    ray_hit_object = 0i64;
    v6 = UFG::TargetIsVisible(v4, (UFG::SimObject *)v5, &ray_hit_object);
    v7 = *v3->i_data.i_array_p;
    v8 = v7->i_data_p;
    LOBYTE(v7) = 1;
    v8->i_user_data = v6;
    ((void (__fastcall *)(SSInvokedContextBase *, SSData *))v3->vfptr[1].get_topmost_scope)(v3, v7);
  }
}

// File Line: 1350
// RVA: 0x4DA620
char __fastcall UFG::TSGameSlice::Coro_camera_raycast_to_target(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  UFG::SimObject *v2; // r14
  Render::DebugDrawContext *v3; // r15
  __int64 v4; // rdx
  bool v5; // di
  bool v6; // bp
  UFG::BaseCameraComponent *v7; // rax
  UFG::BaseCameraComponent *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdi
  bool v13; // al
  UFG::qColour *v15; // r9
  UFG::qVector3 p0; // [rsp+48h] [rbp-40h]
  UFG::qVector3 raycastPosition; // [rsp+58h] [rbp-30h]

  v1 = pScope;
  v2 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 1u);
  if ( v2 )
  {
    v3 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v4 = *(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 2) + 8i64);
    v5 = *(_QWORD *)(v4 + 32) != 0i64;
    v6 = *(_QWORD *)(v4 + 32) || !v1->i_update_count;
    v7 = UFG::Director::Get()->mCurrentCamera;
    if ( v7 )
      v8 = (UFG::BaseCameraComponent *)((char *)v7 + 80);
    else
      v8 = 0i64;
    v9 = v8->mCamera.mView.v2.y;
    v10 = v8->mCamera.mView.v2.z;
    p0.x = v8->mCamera.mView.v2.x;
    p0.y = v9;
    p0.z = v10;
    if ( v6 )
      UFG::ComputeObjectRaycastPosition(v2, &raycastPosition);
    if ( v1->i_update_count )
    {
      if ( v5 )
      {
        v15 = &UFG::qColour::Green;
        if ( (*v1->i_data.i_array_p)->i_data_p->i_user_data > 0 )
          v15 = &UFG::qColour::Red;
        Render::DebugDrawContext::DrawLine(v3, &p0, &raycastPosition, v15, &UFG::qMatrix44::msIdentity, 0i64, 0);
      }
    }
    else
    {
      if ( v5 )
        Render::DebugDrawContext::DrawLine(
          v3,
          &p0,
          &raycastPosition,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
      v11 = UFG::qMalloc(0x10ui64, "TSGameSlice::Coro_camera_raycast_to_target", 0i64);
      v12 = v11;
      if ( v11 )
      {
        v11->mNext = (UFG::allocator::free_link *)v1;
        LODWORD(v11[1].mNext) = v1->i_ptr_id;
      }
      else
      {
        v12 = 0i64;
      }
      v13 = UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
              UFG::BasePhysicsSystem::mInstance,
              &p0,
              &raycastPosition,
              0x12u,
              UFG::RayCastToTargetAsyncRayCallback,
              0i64,
              v12);
      (*v1->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
      if ( v13 )
      {
        ++v1->i_pending_count;
        return 0;
      }
      operator delete[](v12);
    }
  }
  else
  {
    (*v1->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
  }
  return 1;
}

// File Line: 1421
// RVA: 0x4D9F70
char __fastcall UFG::TSGameSlice::Coro_async_is_target_occluded(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdi
  unsigned __int64 v2; // rsi
  UFG::SimObjectVehicle *v3; // rbx
  __int64 v4; // rax
  bool v5; // r14
  bool v6; // bp
  UFG::BaseCameraComponent *v7; // rax
  signed __int64 v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  unsigned __int16 v12; // cx
  float v13; // xmm6_4
  UFG::CharacterOccupantComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::VehicleSubjectComponent *v16; // rax
  float v17; // xmm6_4
  Render::DebugDrawContext *v18; // rax
  UFG::SimAsyncOcclusionQueryManager *v19; // rax
  UFG::SimAsyncOcclusionQueryManager *v20; // rax
  SSObjectBase *v21; // rdx
  unsigned int v23; // ecx
  SSObjectBase *v24; // rbx
  UFG::SimAsyncOcclusionQuery *v25; // rbx
  SSObjectBase *v26; // rcx
  UFG::SimAsyncOcclusionQueryManager *v27; // rax
  UFG::qVector3 p0; // [rsp+40h] [rbp-38h]
  UFG::qVector3 raycastPosition; // [rsp+50h] [rbp-28h]

  v1 = pScope;
  v2 = 0i64;
  v3 = (UFG::SimObjectVehicle *)UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 1u);
  if ( v3 )
  {
    v4 = *(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 2) + 8i64);
    v5 = *(_QWORD *)(v4 + 32) > 0ui64;
    v6 = *(_QWORD *)(v4 + 32) > 0ui64 || !v1->i_update_count;
    v7 = UFG::Director::Get()->mCurrentCamera;
    if ( v7 )
      v8 = (signed __int64)&v7->mCamera;
    else
      v8 = 0i64;
    v9 = *(float *)(v8 + 180);
    v10 = *(float *)(v8 + 184);
    v11 = *(float *)(v8 + 176);
    p0.x = *(float *)(v8 + 176);
    p0.y = v9;
    p0.z = v10;
    if ( v6 )
      UFG::ComputeObjectRaycastPosition((UFG::SimObject *)&v3->vfptr, &raycastPosition);
    v12 = v3->m_Flags;
    v13 = FLOAT_0_5;
    if ( (v12 >> 14) & 1 )
    {
      v14 = (UFG::CharacterOccupantComponent *)v3->m_Components.p[44].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
      else
      {
        v14 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      }
    }
    else
    {
      v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v14 )
      v3 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v14);
    if ( v3 )
    {
      v15 = v3->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v3->vfptr,
                                                UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
          v16 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v3->vfptr,
                                                  UFG::VehicleSubjectComponent::_TypeUID);
        else
          v16 = (UFG::VehicleSubjectComponent *)((v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v3->vfptr,
                                                                     UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
      }
      else
      {
        v16 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v3);
      }
      if ( v16 )
      {
        ((void (__fastcall *)(UFG::VehicleSubjectComponent *))v16->vfptr[21].__vecDelDtor)(v16);
        v13 = v11;
      }
    }
    v17 = v13 + 1.0;
    if ( !v1->i_update_count )
    {
      if ( v5 )
      {
        v18 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
        Render::DebugDrawContext::DrawLine(
          v18,
          &p0,
          &raycastPosition,
          &UFG::qColour::Blue,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
      }
      v19 = UFG::SimAsyncOcclusionQueryManager::Get();
      v20 = UFG::SimAsyncOcclusionQueryManager::CreateQuery(v19, &raycastPosition, v17);
      v21 = v1->i_scope_p.i_obj_p;
      if ( !v21 || v1->i_scope_p.i_ptr_id != v21->i_ptr_id )
        v21 = 0i64;
      v21[2].vfptr = (SSObjectBaseVtbl *)v20;
      return 0;
    }
  }
  v23 = v1->i_update_count;
  if ( !v23 )
    goto LABEL_60;
  v24 = v1->i_scope_p.i_obj_p;
  if ( !v24 || v1->i_scope_p.i_ptr_id != v24->i_ptr_id )
    v24 = 0i64;
  v25 = (UFG::SimAsyncOcclusionQuery *)v24[2].vfptr;
  if ( !v25 )
  {
LABEL_60:
    (*v1->i_data.i_array_p)->i_data_p->i_user_data = 1i64;
    v26 = v1->i_scope_p.i_obj_p;
    if ( !v26 || v1->i_scope_p.i_ptr_id != v26->i_ptr_id )
      v26 = 0i64;
    v25 = (UFG::SimAsyncOcclusionQuery *)v26[2].vfptr;
    if ( !v25 )
      return 1;
    goto LABEL_56;
  }
  if ( v23 <= 0x14 )
  {
    if ( !v25->mQueryCompleted )
      return 0;
    goto LABEL_51;
  }
  if ( v25->mQueryCompleted )
  {
LABEL_51:
    LOBYTE(v2) = v25->mVisibility > 0.0;
    (*v1->i_data.i_array_p)->i_data_p->i_user_data = v2;
    goto LABEL_56;
  }
  (*v1->i_data.i_array_p)->i_data_p->i_user_data = 1i64;
LABEL_56:
  v27 = UFG::SimAsyncOcclusionQueryManager::Get();
  UFG::SimAsyncOcclusionQueryManager::ReleaseQuery(v27, v25);
  return 1;
}

// File Line: 1521
// RVA: 0x4DB950
char __fastcall UFG::TSGameSlice::Coro_launch_store_front(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbp
  SSActor *v2; // rbx
  SSClass *v3; // rdi
  __int64 v4; // r15
  UFG::StoreFrontTracker *v5; // rax
  SSData **v6; // r8
  UFG::StoreFrontTracker *v7; // rsi
  UFG::qPropertySet *v8; // rbp
  bool v9; // bl
  SSInstance *v10; // r14
  SSInstance *v11; // r12
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rdi
  UFG::qPropertySet *v14; // rdx
  UFG::qPropertySet *v15; // rdi
  UFG::qSymbol *v16; // rax
  UFG::qSymbol *v17; // rax
  UFG::qSymbol *v18; // rax
  unsigned __int64 v19; // rbx
  const char *v20; // rbx
  UFG::qSymbol *v21; // rax
  const char *v22; // rbx
  UFG::qSymbol *v23; // rax
  UFG::qSymbol *v24; // rax
  UFG::qSymbol *v25; // rax
  hkpCollidable *v26; // rdx
  hkpCollidable *v27; // r8
  hkpCollisionInput *v28; // r9
  hkpNullContactMgr *v29; // rbx
  UFG::UIScreen *v31; // rax
  UFG::StoreFrontTracker *v32; // rax
  UFG::qSymbol v; // [rsp+60h] [rbp+8h]
  UFG::qSymbol v34; // [rsp+68h] [rbp+10h]
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]
  UFG::qSymbol v36; // [rsp+78h] [rbp+20h]

  v1 = pScope;
  if ( pScope->i_update_count )
  {
    v31 = UFG::UIScreenManagerBase::getScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            "Wardrobe");
    if ( !v31 || !LOBYTE(v31[1].vfptr) )
    {
      v31 = UFG::UIScreenManagerBase::getScreen(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              "GarageBrowser");
      if ( !v31 || !LOBYTE(v31[1].vfptr) )
        return 0;
    }
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      v31->mScreenUID);
    v32 = UFG::StoreFrontTracker::Instance();
    UFG::StoreFrontTracker::UnloadStoreData(v32);
    return 1;
  }
  v2 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( !v2 )
    goto LABEL_30;
  v3 = v2->i_class_p;
  if ( v3->vfptr->is_actor_class((SSClassDescBase *)&v3->vfptr) )
    goto LABEL_8;
  if ( v3 == SSBrain::c_symbol_class_p && LODWORD(v2->i_user_data) != -1 )
    v2 = SSActor::find((ASymbol *)&v2->i_user_data);
  else
LABEL_30:
    v2 = 0i64;
LABEL_8:
  v4 = *(_QWORD *)&v2[1].i_icoroutines_to_update.i_count;
  v5 = UFG::StoreFrontTracker::Instance();
  v6 = v1->i_data.i_array_p;
  v7 = v5;
  v8 = (UFG::qPropertySet *)(*v6)->i_data_p->i_user_data;
  v9 = v6[2]->i_data_p->i_user_data != 0;
  v.mUID = v6[3]->i_data_p->i_user_data;
  v34.mUID = v6[4]->i_data_p->i_user_data;
  v10 = v6[5]->i_data_p;
  v11 = v6[6]->i_data_p;
  v12 = UFG::qSymbol::create_from_string(&result, "InventoryType");
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(v8, v12, DEPTH_RECURSE);
  if ( v.mUID != UFG::gNullQSymbol.mUID || v34.mUID != UFG::gNullQSymbol.mUID )
  {
    UFG::qSymbol::create_from_string(&result, "store_front_set");
    v15 = UFG::qPropertySet::CreateContainedSet(&result, "temp_store_front");
    UFG::PSWrapper::AppendParentLocal(v15, v8);
    if ( v9 )
    {
      v16 = UFG::qSymbol::create_from_string(&v36, "HasInventoryUI");
      PropertyUtils::Set<bool>(v15, v16, v9);
    }
    v17 = UFG::qSymbol::create_from_string(&v36, "StoreType");
    PropertyUtils::Set<UFG::qSymbol>(v15, v17, &v);
    v18 = UFG::qSymbol::create_from_string(&v36, "StoreId");
    PropertyUtils::Set<UFG::qSymbol>(v15, v18, &v34);
    v19 = v10->i_user_data;
    if ( *(_DWORD *)(v19 + 8) > 1u )
    {
      v20 = *(const char **)v19;
      v21 = UFG::qSymbol::create_from_string(&v36, "StorePreviewMarker");
      UFG::qPropertySet::Set<char const *>(v15, v21, v20);
      v22 = *(const char **)v11->i_user_data;
      v23 = UFG::qSymbol::create_from_string(&v36, "StoreCameraMarker");
      UFG::qPropertySet::Set<char const *>(v15, v23, v22);
    }
    v24 = UFG::qSymbol::create_from_string(&v36, "InventoryType");
    v25 = UFG::qPropertySet::Get<UFG::qSymbol>(v8, v24, DEPTH_RECURSE);
    UFG::StoreFrontTracker::LoadStoreData(v7, v25);
    v14 = v15;
  }
  else
  {
    UFG::qSymbol::create_from_string(&v36, "Clothing");
    UFG::StoreFrontTracker::LoadStoreData(v7, v13);
    v14 = v8;
  }
  UFG::StoreFrontTracker::SetCurrentStore(v7, v14);
  v29 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v7, v26, v27, v28);
  if ( *(_DWORD *)&v29[1].m_memSizeAndFlags == 61 )
  {
    UFG::UIHKScreenWardrobe::QueuePush();
  }
  else if ( *(_DWORD *)&v29[1].m_memSizeAndFlags == 62 || *(_DWORD *)&v29[1].m_memSizeAndFlags == 63 )
  {
    UFG::UIHKScreenGarageBrowser::QueuePush();
    *(_QWORD *)&v29->m_type = v4;
    return 0;
  }
  *(_QWORD *)&v29->m_type = v4;
  return 0;
}

// File Line: 1637
// RVA: 0x504A40
void __fastcall UFG::TSGameSlice::Mthd_load_audio_resources(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( v3 && v2->i_scope_p.i_ptr_id == v3->i_ptr_id )
    UFG::TidoGame::LoadGameSliceAudioResources((UFG::GameSlice *)v3[8].vfptr);
  else
    UFG::TidoGame::LoadGameSliceAudioResources(MEMORY[0x98]);
}

// File Line: 1647
// RVA: 0x50E2D0
void __fastcall UFG::TSGameSlice::Mthd_unload_audio_resources(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( v3 && v2->i_scope_p.i_ptr_id == v3->i_ptr_id )
    UFG::TidoGame::UnloadGameSliceAudioResources((UFG::GameSlice *)v3[8].vfptr);
  else
    UFG::TidoGame::UnloadGameSliceAudioResources(MEMORY[0x98]);
}

// File Line: 1661
// RVA: 0x4F7BD0
void __fastcall UFG::TSGameSlice::Mthd_despawn_npc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  UFG::TSCharacter *v3; // rbx
  SSActorClass *v4; // rdi
  SSClass *v5; // rcx
  SSClass *v6; // rcx
  SSObjectBase *v7; // rcx
  signed __int64 v8; // rdi
  __int64 v9; // rcx
  UFG::GameSlice *v10; // rax
  bool v11; // zf

  v2 = pScope;
  v3 = (UFG::TSCharacter *)(*pScope->i_data.i_array_p)->i_data_p;
  v4 = (SSActorClass *)v3->i_class_p;
  if ( UFG::SkookumMgr::mspCharacterClass == v4
    || (v5 = v4->i_superclass_p) != 0i64 && SSClass::is_class(v5, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
  {
    if ( UFG::SkookumMgr::mspPlayerClass == v4 )
      return;
    v6 = v4->i_superclass_p;
    if ( v6 )
    {
      if ( SSClass::is_class(v6, (SSClass *)&UFG::SkookumMgr::mspPlayerClass->vfptr) )
        return;
    }
  }
  else
  {
    if ( v4 != (SSActorClass *)SSBrain::c_symbol_class_p )
      return;
    v3 = UFG::TSCharacter::find_instance((UFG::qSymbol *)&v3->i_user_data);
  }
  if ( v3 )
  {
    v7 = v2->i_scope_p.i_obj_p;
    if ( v7 && v2->i_scope_p.i_ptr_id == v7->i_ptr_id )
      v8 = (signed __int64)&v7[-2].i_ptr_id;
    else
      v8 = 0i64;
    v9 = (*(__int64 (__fastcall **)(signed __int64, UFG::TSCharacter *))(*(_QWORD *)(v8 + 24) + 120i64))(v8 + 24, v3);
    if ( v9
      || (v10 = UFG::GameSlice::GetParent(*(UFG::GameSlice **)(v8 + 152))) != 0i64
      && (v9 = ((__int64 (__fastcall *)(SSObjectBaseVtbl **, UFG::TSCharacter *))v10->mScript->vfptr[1].get_topmost_scope)(
                 &v10->mScript->vfptr,
                 v3)) != 0 )
    {
      *(_QWORD *)(v9 + 8) = SSBrain::c_nil_p;
      v11 = v3->i_ref_count-- == 1;
      if ( v11 )
      {
        v3->i_ref_count = 2147483648;
        v3->vfptr[1].get_scope_context((SSObjectBase *)&v3->vfptr);
      }
    }
    UFG::TSCharacter::Despawn(v3, (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 1719
// RVA: 0x15364A0
__int64 UFG::_dynamic_initializer_for__nullSym__()
{
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym, 0xFFFFFFFF);
  return atexit(UFG::_dynamic_atexit_destructor_for__nullSym__);
}

// File Line: 1722
// RVA: 0x4E2820
void __fastcall UFG::InteriorTriggerProperties::LoadFromProperties(UFG::InteriorTriggerProperties *this, UFG::qPropertySet *trigger_prop_set)
{
  UFG::qPropertySet *v2; // rdi
  UFG::InteriorTriggerProperties *v3; // rbx
  UFG::qSymbol *v4; // rsi
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rcx
  UFG::qSymbol *v7; // rax
  UFG::qSymbol *v8; // rcx
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rcx
  float *v11; // rax
  float v12; // xmm6_4
  float v13; // xmm0_4
  float *v14; // rax
  float v15; // xmm0_4
  UFG::qSymbol *v16; // rax
  UFG::qSymbol *v17; // rcx
  float *v18; // rax
  float v19; // xmm0_4
  float *v20; // rax
  float v21; // xmm0_4
  UFG::qSymbol *v22; // rax
  float *v23; // rax
  float v24; // xmm0_4
  float *v25; // rax
  float v26; // xmm0_4
  float *v27; // rax
  float v28; // xmm0_4
  float *v29; // rax
  UFG::qSymbol *v30; // rax
  char *v31; // rax
  char *v32; // rax
  bool *v33; // rax
  UFG::InteriorTriggerProperties::tri_state v34; // esi
  signed int v35; // ecx
  bool *v36; // rax
  signed int v37; // ecx
  bool *v38; // rax
  signed int v39; // ecx
  bool *v40; // rax
  signed int v41; // ecx
  bool *v42; // rax
  signed int v43; // ecx
  bool *v44; // rax

  v2 = trigger_prop_set;
  v3 = this;
  v4 = &nullSym_0;
  if ( !(_S12_7 & 1) )
  {
    _S12_7 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_0, 0xFFFFFFFF);
    atexit(UFG::InteriorTriggerProperties::LoadFromProperties_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  v5 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_TriggerName.mUID, DEPTH_RECURSE);
  v6 = &nullSym_0;
  if ( v5 )
    v6 = v5;
  v3->mTriggerName = (UFG::qSymbol)v6->mUID;
  v7 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_Category.mUID, DEPTH_RECURSE);
  v8 = &nullSym_0;
  if ( v7 )
    v8 = v7;
  v3->mCategory = (UFG::qSymbol)v8->mUID;
  v9 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_Environment.mUID, DEPTH_RECURSE);
  v10 = &nullSym_0;
  if ( v9 )
    v10 = v9;
  v3->mEnvironment = (UFG::qSymbol)v10->mUID;
  v11 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_EnvironmentApplyAmount.mUID, DEPTH_RECURSE);
  v12 = FLOAT_3_4028235e38;
  if ( v11 )
    v13 = *v11;
  else
    v13 = FLOAT_3_4028235e38;
  v3->mEnvironmentApplyAmount = v13;
  v14 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_EnvironmentTransition.mUID, DEPTH_RECURSE);
  if ( v14 )
    v15 = *v14;
  else
    v15 = FLOAT_3_4028235e38;
  v3->mEnvironmentTransition = v15;
  v16 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_EnterEnvironment.mUID, DEPTH_RECURSE);
  v17 = &nullSym_0;
  if ( v16 )
    v17 = v16;
  v3->mEnterEnvironment = (UFG::qSymbol)v17->mUID;
  v18 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_EnterEnvironmentApplyAmount.mUID, DEPTH_RECURSE);
  if ( v18 )
    v19 = *v18;
  else
    v19 = FLOAT_3_4028235e38;
  v3->mEnterEnvironmentApplyAmount = v19;
  v20 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_EnterEnvironmentTransition.mUID, DEPTH_RECURSE);
  if ( v20 )
    v21 = *v20;
  else
    v21 = FLOAT_3_4028235e38;
  v3->mEnterEnvironmentTransition = v21;
  v22 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_ExitEnvironment.mUID, DEPTH_RECURSE);
  if ( v22 )
    v4 = v22;
  v3->mExitEnvironment = (UFG::qSymbol)v4->mUID;
  v23 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_ExitEnvironmentApplyAmount.mUID, DEPTH_RECURSE);
  if ( v23 )
    v24 = *v23;
  else
    v24 = FLOAT_3_4028235e38;
  v3->mExitEnvironmentApplyAmount = v24;
  v25 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_ExitEnvironmentTransition.mUID, DEPTH_RECURSE);
  if ( v25 )
    v26 = *v25;
  else
    v26 = FLOAT_3_4028235e38;
  v3->mExitEnvironmentTransition = v26;
  v27 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_EnvironmentTransitionOn.mUID, DEPTH_RECURSE);
  if ( v27 )
    v28 = *v27;
  else
    v28 = FLOAT_3_4028235e38;
  v3->mEnvironmentTransitionOn = v28;
  v29 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_EnvironmentTransitionOff.mUID, DEPTH_RECURSE);
  if ( v29 )
    v12 = *v29;
  v3->mEnvironmentTransitionOff = v12;
  v30 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_PhysicsActiveRegionMode.mUID, DEPTH_RECURSE);
  if ( v30 )
    v3->mPhysicsActiveRegionMode = (UFG::qSymbol)v30->mUID;
  else
    UFG::qSymbol::set_null(&v3->mPhysicsActiveRegionMode);
  v31 = PropertyUtils::Get<char const *>(v2, (UFG::qSymbol *)&qSymbol_CameraContextOverrideTow.mUID, DEPTH_RECURSE);
  UFG::qString::Set(&v3->mCameraContextOverrideTow, v31);
  v32 = PropertyUtils::Get<char const *>(v2, (UFG::qSymbol *)&qSymbol_CameraContextLocalOverrideTow.mUID, DEPTH_RECURSE);
  UFG::qString::Set(&v3->mCameraContextLocalOverrideTow, v32);
  v33 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_NestedEnvironment.mUID, DEPTH_RECURSE);
  v34 = 0;
  if ( v33 )
    v35 = *v33 != 0;
  else
    v35 = -1;
  v3->mNestedEnvironment = v35;
  v36 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_DisableProxyPeds.mUID, DEPTH_RECURSE);
  if ( v36 )
    v37 = *v36 != 0;
  else
    v37 = -1;
  v3->mDisableProxyPeds = v37;
  v38 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_DisableTraffic.mUID, DEPTH_RECURSE);
  if ( v38 )
    v39 = *v38 != 0;
  else
    v39 = -1;
  v3->mDisableTraffic = v39;
  v40 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_OnEnterOnly.mUID, DEPTH_RECURSE);
  if ( v40 )
    v41 = *v40 != 0;
  else
    v41 = -1;
  v3->mOnEnterOnly = v41;
  v42 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_SpecialTrigger.mUID, DEPTH_RECURSE);
  if ( v42 )
    v43 = *v42 != 0;
  else
    v43 = -1;
  v3->mSpecialTrigger = v43;
  v44 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_ForceWalk.mUID, DEPTH_RECURSE);
  if ( v44 )
  {
    LOBYTE(v34) = *v44 != 0;
    v3->mForceWalk = v34;
  }
  else
  {
    v3->mForceWalk = -1;
  }
}

// File Line: 1803
// RVA: 0x4E17A0
void __fastcall UFG::TSGameSlice::InteriorExterior_OnEnterHandler(UFG::TriggerRegion *trigger_region)
{
  signed int v1; // er9
  unsigned int v2; // eax
  unsigned int v3; // er8
  UFG::qSymbol *v4; // rcx
  UFG::InteriorTriggerProperties *v5; // rbx
  SSClass *v6; // rsi
  AObjReusePool<SSInstance> *v7; // rax
  AObjReusePool<SSInstance> *v8; // rdi
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  __int64 v12; // rcx
  SSInstance **v13; // rax
  __int64 v14; // rdx
  unsigned int v15; // eax
  unsigned int v16; // eax
  SSClass *v17; // rdi
  AObjReusePool<SSInstance> *v18; // rax
  AObjReusePool<SSInstance> *v19; // rbx
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  __int64 v23; // rcx
  SSInstance **v24; // rax
  __int64 v25; // rdx
  unsigned int v26; // eax
  UFG::TSActor *v27; // r11
  UFG::qBaseNodeRB *v28; // rax
  bool v29; // cl
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v30; // rdi
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v31; // rsi
  UFG::SimObject *v32; // rax
  UFG::CharacterSubjectComponent *v33; // rdi
  UFG::qSymbol v34; // eax
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v35; // rdi
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v36; // rsi
  UFG::SimObject *v37; // rax
  UFG::CharacterSubjectComponent *v38; // rdi
  UFG::qSymbol v39; // eax
  UFG::InteriorTriggerProperties::tri_state v40; // eax
  UFG::PedSpawnManager *v41; // rax
  UFG::PedSpawnManager *v42; // rax
  SSInstance *args_pp; // [rsp+48h] [rbp-28h]
  SSInstance *v44; // [rsp+50h] [rbp-20h]
  SSInstance *v45; // [rsp+58h] [rbp-18h]
  char *pszSymbolString; // [rsp+60h] [rbp-10h]
  UFG::qSymbol result; // [rsp+A8h] [rbp+38h]
  UFG::qSymbol *v48; // [rsp+B0h] [rbp+40h]

  v1 = 99999;
  v2 = 0;
  if ( UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    v3 = trigger_region->i_name.mUID;
    v4 = &UFG::TSGameSlice::msInteriorTriggerData.p->mTriggerName;
    while ( v4->mUID != v3 )
    {
      ++v2;
      v4 += 42;
      if ( v2 >= UFG::TSGameSlice::msInteriorTriggerData.size )
        goto LABEL_7;
    }
    v1 = v2;
  }
LABEL_7:
  v5 = &UFG::TSGameSlice::msInteriorTriggerData.p[v1];
  if ( v5->mNestedEnvironment == 1 )
  {
    args_pp = SSSymbol::as_instance((ASymbol *)&v5->mEnterEnvironment);
    result.mUID = LODWORD(v5->mEnterEnvironmentApplyAmount);
    v6 = SSBrain::c_real_class_p;
    v7 = SSInstance::get_pool();
    v8 = v7;
    v9 = v7->i_pool.i_count;
    if ( v9 )
    {
      v15 = v9 - 1;
      v8->i_pool.i_count = v15;
      v12 = v15;
      v13 = v8->i_pool.i_array_p;
    }
    else
    {
      if ( !v8->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v8, v8->i_expand_size);
      v10 = v8->i_exp_pool.i_count;
      if ( !v10 )
      {
        v14 = 0i64;
        goto LABEL_16;
      }
      v11 = v10 - 1;
      v8->i_exp_pool.i_count = v11;
      v12 = v11;
      v13 = v8->i_exp_pool.i_array_p;
    }
    v14 = (__int64)v13[v12];
LABEL_16:
    *(_QWORD *)(v14 + 24) = v6;
    *(_QWORD *)(v14 + 32) = result.mUID;
    *(_DWORD *)(v14 + 16) = 1;
    v16 = SSObjectBase::c_ptr_id_prev + 1;
    SSObjectBase::c_ptr_id_prev = v16;
    *(_DWORD *)(v14 + 8) = v16;
    v44 = (SSInstance *)v14;
    result.mUID = LODWORD(v5->mEnterEnvironmentTransition);
    v17 = SSBrain::c_real_class_p;
    v18 = SSInstance::get_pool();
    v19 = v18;
    v20 = v18->i_pool.i_count;
    if ( v20 )
    {
      v26 = v20 - 1;
      v19->i_pool.i_count = v26;
      v23 = v26;
      v24 = v19->i_pool.i_array_p;
    }
    else
    {
      if ( !v19->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v19, v19->i_expand_size);
      v21 = v19->i_exp_pool.i_count;
      if ( !v21 )
      {
        v25 = 0i64;
        goto LABEL_24;
      }
      v22 = v21 - 1;
      v19->i_exp_pool.i_count = v22;
      v23 = v22;
      v24 = v19->i_exp_pool.i_array_p;
    }
    v25 = (__int64)v24[v23];
LABEL_24:
    *(_QWORD *)(v25 + 24) = v17;
    *(_QWORD *)(v25 + 32) = result.mUID;
    *(_DWORD *)(v25 + 16) = 1;
    *(_DWORD *)(v25 + 8) = ++SSObjectBase::c_ptr_id_prev;
    v45 = (SSInstance *)v25;
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        (SSInstance *)&SkookumScript::c_world_p->vfptr,
        (ASymbol *)&qSymbol__render_override_environment_named,
        &args_pp,
        3u,
        1,
        0.0,
        0i64,
        0i64);
    return;
  }
  if ( v5->mForceWalk != -1 )
  {
    v27 = (UFG::TSActor *)SSActor::find((ASymbol *)&qSymbol_PlayerOne_Havok);
    if ( !v27 )
    {
      v28 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&qSymbol_PlayerOne_Havok.mUID);
      v27 = UFG::TSActor::FromSimObject((UFG::SimObject *)v28);
    }
    v29 = v5->mForceWalk == 1;
    *(_QWORD *)&result.mUID = 0i64;
    if ( v29 )
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, UFG::qSymbol *, _QWORD, _QWORD, _QWORD))v27->vfptr[1].set_data_by_name)(
        v27,
        &qSymbol_start_force_walk,
        &result,
        0i64,
        0i64,
        0i64);
    else
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, UFG::qSymbol *, _QWORD, _QWORD, _QWORD))v27->vfptr[1].set_data_by_name)(
        v27,
        &qSymbol_stop_force_walk,
        &result,
        0i64,
        0i64,
        0i64);
  }
  if ( v5->mCameraContextOverrideTow.mLength )
  {
    UFG::qString::FormatEx((UFG::qString *)&args_pp, "Cameras-%s", v5->mCameraContextOverrideTow.mData);
    v30 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
    if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
    {
      do
      {
        v31 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&v30[78].mNext[-78];
        if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v30->mPrev[8].mNext)(v30) )
        {
          v32 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v30->mPrev[8].mNext)(v30);
          v33 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                    v32,
                                                    UFG::CharacterSubjectComponent::_TypeUID);
          if ( v33 )
          {
            v48 = &result;
            v34.mUID = (unsigned int)UFG::qSymbol::create_from_string(&result, pszSymbolString);
            UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v33, 0, v34);
          }
        }
        v30 = &v31->mNode;
      }
      while ( v31 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
    }
    UFG::qString::~qString((UFG::qString *)&args_pp);
  }
  if ( v5->mCameraContextLocalOverrideTow.mLength )
  {
    UFG::qString::FormatEx((UFG::qString *)&args_pp, "Cameras-%s", v5->mCameraContextLocalOverrideTow.mData);
    v35 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
    if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
    {
      do
      {
        v36 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&v35[78].mNext[-78];
        if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v35->mPrev[8].mNext)(v35) )
        {
          v37 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v35->mPrev[8].mNext)(v35);
          v38 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                    v37,
                                                    UFG::CharacterSubjectComponent::_TypeUID);
          if ( v38 )
          {
            v48 = &result;
            v39.mUID = (unsigned int)UFG::qSymbol::create_from_string(&result, pszSymbolString);
            UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v38, 0, v39);
          }
        }
        v35 = &v36->mNode;
      }
      while ( v36 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
    }
    UFG::qString::~qString((UFG::qString *)&args_pp);
  }
  if ( v5->mEnvironment.mUID != nullSym.mUID )
  {
    args_pp = SSSymbol::as_instance((ASymbol *)&v5->mEnvironment);
    result.mUID = LODWORD(v5->mEnvironmentApplyAmount);
    v44 = SSInstance::pool_new(SSBrain::c_real_class_p, result.mUID);
    result.mUID = LODWORD(v5->mEnvironmentTransitionOn);
    v45 = SSInstance::pool_new(SSBrain::c_real_class_p, result.mUID);
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        (SSInstance *)&SkookumScript::c_world_p->vfptr,
        (ASymbol *)&qSymbol__render_override_environment_named,
        &args_pp,
        3u,
        1,
        0.0,
        0i64,
        0i64);
  }
  if ( v5->mPhysicsActiveRegionMode.mUID != -1 )
    UFG::ActiveRegionManager::SetModeFromSymbol(
      &UFG::BasePhysicsSystem::mInstance->mActiveRegionManager,
      &v5->mPhysicsActiveRegionMode);
  v40 = v5->mDisableProxyPeds;
  if ( v40 == 1 )
  {
    v41 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::DisableProxyPeds(v41);
  }
  else if ( v40 == set_false )
  {
    v42 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::EnableProxyPeds(v42);
  }
  if ( v5->mDisableTraffic == 1 )
    UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 0);
  if ( v5->mSpecialTrigger != 1 && v5->mEnvironment.mUID == nullSym.mUID )
  {
    UFG::RenderWorld::SetFlags(0);
    UFG::GeographicalLayerManager::SetActiveCategory(&v5->mCategory);
  }
}

// File Line: 1930
// RVA: 0x4E1C80
void __fastcall UFG::TSGameSlice::InteriorExterior_OnExitHandler(UFG::TriggerRegion *trigger_region)
{
  __int64 v1; // rsi
  __int64 v2; // rbx
  UFG::TriggerRegion *v3; // rbp
  signed int v4; // er9
  unsigned int v5; // eax
  UFG::qSymbol *v6; // rdx
  UFG::InteriorTriggerProperties *v7; // rdi
  SSInstance *v8; // rax
  SSClass *v9; // rbp
  AObjReusePool<SSInstance> *v10; // rax
  AObjReusePool<SSInstance> *v11; // rsi
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // rcx
  SSInstance **v16; // rax
  __int64 v17; // rdx
  unsigned int v18; // eax
  __int64 v19; // rax
  SSClass *v20; // rsi
  AObjReusePool<SSInstance> *v21; // rax
  AObjReusePool<SSInstance> *v22; // rdi
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  __int64 v26; // rcx
  SSInstance **v27; // rax
  __int64 v28; // rdx
  unsigned int v29; // eax
  __int64 v30; // rax
  UFG::TSActor *v31; // rcx
  UFG::qBaseNodeRB *v32; // rax
  bool v33; // zf
  SSInstance *v34; // rax
  unsigned int v35; // edx
  UFG::qBaseTreeRB *v36; // rax
  signed __int64 v37; // rax
  int v38; // ecx
  UFG::PedSpawnManager *v39; // rax
  SSInstance *args_pp; // [rsp+40h] [rbp-38h]
  __int64 v41; // [rsp+48h] [rbp-30h]
  SSInstance *v42; // [rsp+50h] [rbp-28h]
  unsigned __int64 user_data; // [rsp+88h] [rbp+10h]

  v1 = UFG::TSGameSlice::msInteriorTriggerData.size;
  v2 = 0i64;
  v3 = trigger_region;
  v4 = 99999;
  v5 = 0;
  if ( UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    v6 = &UFG::TSGameSlice::msInteriorTriggerData.p->mTriggerName;
    while ( v6->mUID != trigger_region->i_name.mUID )
    {
      ++v5;
      v6 += 42;
      if ( v5 >= UFG::TSGameSlice::msInteriorTriggerData.size )
        goto LABEL_7;
    }
    v4 = v5;
  }
LABEL_7:
  v7 = &UFG::TSGameSlice::msInteriorTriggerData.p[v4];
  if ( v7->mNestedEnvironment == 1 )
  {
    v8 = SSSymbol::as_instance((ASymbol *)&v7->mExitEnvironment);
    v9 = SSBrain::c_real_class_p;
    *(float *)&user_data = v7->mExitEnvironmentApplyAmount;
    args_pp = v8;
    v10 = SSInstance::get_pool();
    v11 = v10;
    v12 = v10->i_pool.i_count;
    if ( v12 )
    {
      v18 = v12 - 1;
      v11->i_pool.i_count = v18;
      v15 = v18;
      v16 = v11->i_pool.i_array_p;
    }
    else
    {
      if ( !v11->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v11, v11->i_expand_size);
      v13 = v11->i_exp_pool.i_count;
      if ( !v13 )
      {
        v17 = 0i64;
        goto LABEL_16;
      }
      v14 = v13 - 1;
      v11->i_exp_pool.i_count = v14;
      v15 = v14;
      v16 = v11->i_exp_pool.i_array_p;
    }
    v17 = (__int64)v16[v15];
LABEL_16:
    v19 = (unsigned int)user_data;
    *(_QWORD *)(v17 + 24) = v9;
    *(_DWORD *)(v17 + 16) = 1;
    *(_QWORD *)(v17 + 32) = v19;
    LODWORD(v19) = SSObjectBase::c_ptr_id_prev + 1;
    SSObjectBase::c_ptr_id_prev = v19;
    *(_DWORD *)(v17 + 8) = v19;
    v20 = SSBrain::c_real_class_p;
    *(float *)&user_data = v7->mExitEnvironmentTransition;
    v41 = v17;
    v21 = SSInstance::get_pool();
    v22 = v21;
    v23 = v21->i_pool.i_count;
    if ( v23 )
    {
      v29 = v23 - 1;
      v22->i_pool.i_count = v29;
      v26 = v29;
      v27 = v22->i_pool.i_array_p;
    }
    else
    {
      if ( !v22->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v22, v22->i_expand_size);
      v24 = v22->i_exp_pool.i_count;
      if ( !v24 )
      {
        v28 = 0i64;
        goto LABEL_24;
      }
      v25 = v24 - 1;
      v22->i_exp_pool.i_count = v25;
      v26 = v25;
      v27 = v22->i_exp_pool.i_array_p;
    }
    v28 = (__int64)v27[v26];
LABEL_24:
    v30 = (unsigned int)user_data;
    *(_QWORD *)(v28 + 24) = v20;
    *(_DWORD *)(v28 + 16) = 1;
    *(_QWORD *)(v28 + 32) = v30;
    *(_DWORD *)(v28 + 8) = ++SSObjectBase::c_ptr_id_prev;
    v42 = (SSInstance *)v28;
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        (SSInstance *)&SkookumScript::c_world_p->vfptr,
        (ASymbol *)&qSymbol__render_override_environment_named,
        &args_pp,
        3u,
        1,
        0.0,
        0i64,
        0i64);
    return;
  }
  if ( v7->mForceWalk != -1 )
  {
    v31 = (UFG::TSActor *)SSActor::find((ASymbol *)&qSymbol_PlayerOne_Havok);
    if ( !v31 )
    {
      v32 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&qSymbol_PlayerOne_Havok.mUID);
      v31 = UFG::TSActor::FromSimObject((UFG::SimObject *)v32);
    }
    v33 = v7->mForceWalk == 1;
    user_data = 0i64;
    if ( v33 )
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, unsigned __int64 *, _QWORD, _QWORD, _QWORD))v31->vfptr[1].set_data_by_name)(
        v31,
        &qSymbol_stop_force_walk,
        &user_data,
        0i64,
        0i64,
        0i64);
    else
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, unsigned __int64 *, _QWORD, _QWORD, _QWORD))v31->vfptr[1].set_data_by_name)(
        v31,
        &qSymbol_start_force_walk,
        &user_data,
        0i64,
        0i64,
        0i64);
  }
  UFG::TSCamera::MthdC_clear_context_override(0, 0i64);
  UFG::TSCamera::MthdC_clear_context_override_local(0, 0i64);
  UFG::TSCamera::MthdC_clear_context_override(1, 0i64);
  UFG::TSCamera::MthdC_clear_context_override(2, 0i64);
  UFG::TSCamera::MthdC_clear_context_override(3, 0i64);
  if ( v7->mEnvironment.mUID != nullSym.mUID )
  {
    args_pp = SSSymbol::as_instance((ASymbol *)&v7->mEnvironment);
    LODWORD(user_data) = 0;
    v34 = SSInstance::pool_new(SSBrain::c_real_class_p, 0i64);
    *(float *)&user_data = v7->mEnvironmentTransitionOff;
    v41 = (__int64)v34;
    v42 = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)user_data);
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        (SSInstance *)&SkookumScript::c_world_p->vfptr,
        (ASymbol *)&qSymbol__render_override_environment_named,
        &args_pp,
        3u,
        1,
        0.0,
        0i64,
        0i64);
  }
  if ( v7->mPhysicsActiveRegionMode.mUID != -1 )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&user_data, "ARM_EXTERIOR");
    if ( (_DWORD)v1 )
    {
      do
      {
        v35 = UFG::TSGameSlice::msInteriorTriggerData.p[v2].mTriggerName.mUID;
        if ( v35 != v3->i_name.mUID )
        {
          if ( v35 )
          {
            v36 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v35);
            if ( v36 )
            {
              v37 = (signed __int64)&v36[-2].mNULL;
              if ( v37 )
              {
                if ( (*(_DWORD *)(v37 + 192) & 0x10012) == 65554 )
                {
                  v38 = user_data;
                  if ( UFG::TSGameSlice::msInteriorTriggerData.p[v2].mPhysicsActiveRegionMode.mUID != -1 )
                    v38 = UFG::TSGameSlice::msInteriorTriggerData.p[v2].mPhysicsActiveRegionMode.mUID;
                  LODWORD(user_data) = v38;
                }
              }
            }
          }
        }
        ++v2;
        --v1;
      }
      while ( v1 );
    }
    UFG::ActiveRegionManager::SetModeFromSymbol(
      &UFG::BasePhysicsSystem::mInstance->mActiveRegionManager,
      (UFG::qSymbol *)&user_data);
  }
  if ( v7->mDisableTraffic == 1 )
  {
    UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 1);
    UFG::PedSpawnManager::msRequestEmergencyDump = 1;
  }
  if ( v7->mSpecialTrigger != 1 && v7->mEnvironment.mUID == nullSym.mUID )
  {
    UFG::RenderWorld::SetFlags(1u);
    UFG::GeographicalLayerManager::SetActiveCategory(&v7->mCategory);
    v39 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::EnableProxyPeds(v39);
    UFG::GeographicalLayerManager::SetActiveCategory(&nullSym);
  }
}

// File Line: 2055
// RVA: 0x510140
void __fastcall UFG::TSGameSlice::SetupTriggersFromList(UFG::qPropertyList *pTriggerDataList, UFG::GameSlice *pGameSlice)
{
  unsigned int v2; // er12
  UFG::GameSlice *v3; // rsi
  UFG::qPropertyList *v4; // r13
  unsigned int v5; // er15
  char *v6; // rax
  UFG::qPropertySet *v7; // rdi
  unsigned int v8; // ebx
  unsigned int v9; // edx
  __int64 v10; // r14
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::TriggerRegion *v13; // rdi
  UFG::SimObjectCharacter *v14; // rbp
  UFG::TriggerTarget *i; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v16; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v17; // rax
  void (__fastcall *v18)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  void (__fastcall *v19)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  UFG::GameSlice *v20; // [rsp+58h] [rbp+10h]

  v20 = pGameSlice;
  v2 = pTriggerDataList->mNumElements;
  v3 = pGameSlice;
  v4 = pTriggerDataList;
  v5 = 0;
  if ( v2 )
  {
    do
    {
      v6 = UFG::qPropertyList::GetValuePtr(v4, 0x1Au, v5);
      if ( !v6 || (v7 = (UFG::qPropertySet *)&v6[*(_QWORD *)v6], !*(_QWORD *)v6) )
        v7 = 0i64;
      v8 = UFG::TSGameSlice::msInteriorTriggerData.size + 1;
      if ( UFG::TSGameSlice::msInteriorTriggerData.size + 1 > UFG::TSGameSlice::msInteriorTriggerData.capacity )
      {
        if ( UFG::TSGameSlice::msInteriorTriggerData.capacity )
          v9 = 2 * UFG::TSGameSlice::msInteriorTriggerData.capacity;
        else
          v9 = 1;
        for ( ; v9 < v8; v9 *= 2 )
          ;
        if ( v9 - v8 > 0x10000 )
          v9 = UFG::TSGameSlice::msInteriorTriggerData.size + 65537;
        UFG::qArray<UFG::InteriorTriggerProperties,0>::Reallocate(
          &UFG::TSGameSlice::msInteriorTriggerData,
          v9,
          "qArray.Add");
      }
      UFG::TSGameSlice::msInteriorTriggerData.size = v8;
      v10 = v8 - 1;
      UFG::InteriorTriggerProperties::LoadFromProperties(&UFG::TSGameSlice::msInteriorTriggerData.p[v10], v7);
      UFG::TSGameSlice::msInteriorTriggerData.p[v10].mGameSlicePtr = v3;
      v11 = UFG::TSGameSlice::msInteriorTriggerData.p[v10].mTriggerName.mUID;
      if ( !v11
        || (v12 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v11),
            v13 = (UFG::TriggerRegion *)&v12[-2].mNULL,
            !v12) )
      {
        v13 = 0i64;
      }
      v14 = LocalPlayer;
      if ( v13 )
      {
        for ( i = (UFG::TriggerTarget *)v13->mTrackList.mNode.mNext;
              i != (UFG::TriggerTarget *)&v13->mTrackList;
              i = (UFG::TriggerTarget *)v13->mTrackList.mNode.mNext )
        {
          v16 = i->mPrev;
          v17 = i->mNext;
          v16->mNext = v17;
          v17->mPrev = v16;
          i->mPrev = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&i->mPrev;
          i->mNext = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&i->mPrev;
          UFG::TriggerTarget::~TriggerTarget(i);
          operator delete[](i);
        }
        UFG::TriggerRegion::ResetEvents(v13);
        UFG::TriggerRegion::TrackTarget(v13, (UFG::SimObject *)&v14->vfptr, 0i64);
        v18 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
        v13->mOnEnteredDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TSGameSlice::InteriorExterior_OnEnterHandler;
        if ( !UFG::TSGameSlice::InteriorExterior_OnEnterHandler )
          v18 = 0i64;
        v13->mOnEnteredDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v18;
        if ( UFG::TSGameSlice::msInteriorTriggerData.p[v10].mOnEnterOnly != 1 )
        {
          v19 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
          v13->mOnExitedDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TSGameSlice::InteriorExterior_OnExitHandler;
          if ( !UFG::TSGameSlice::InteriorExterior_OnExitHandler )
            v19 = 0i64;
          v13->mOnExitedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v19;
        }
        UFG::TriggerRegion::EnableHot(v13, 1);
        v3 = v20;
      }
      ++v5;
    }
    while ( v5 < v2 );
  }
}

// File Line: 2097
// RVA: 0x506B70
void __fastcall UFG::TSGameSlice::Mthd_send_collectible_telemetry_stat(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  int v3; // ebx
  int v4; // edi
  int v5; // er14
  UFG::GameStatTracker *v6; // rax
  UFG::GameStat::Int32Stat v7; // edx
  int v8; // er15
  UFG::OSuiteDBLogger *v9; // rbp
  unsigned __int64 v10; // rsi
  UFG::OnlineManager *v11; // rax
  __int64 v12; // rbx
  __int64 v13; // rbx
  char dest; // [rsp+20h] [rbp-98h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data;
  if ( v2[2]->i_data_p->i_user_data )
  {
    v5 = -1923866446;
    v6 = UFG::GameStatTracker::Instance();
    v7 = 23;
  }
  else
  {
    v5 = -46881340;
    v6 = UFG::GameStatTracker::Instance();
    v7 = 22;
  }
  v8 = UFG::GameStatTracker::GetStat(v6, v7);
  v9 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v9, "StatueUpgrade") )
  {
    v10 = UFG::Metrics::msRealTimeMSec;
    UFG::qSPrintf(&dest, 128, "i64_%s", "CollectibleId");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v10);
    v11 = UFG::OnlineManager::Instance();
    LODWORD(v10) = UFG::OnlineManager::GetOnlineIdStringHash32(v11);
    UFG::qSPrintf(&dest, 128, "i32_%s", "PlayerId");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v10);
    UFG::qSPrintf(&dest, 128, "i32_%s", "EventType");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v5);
    UFG::qSPrintf(&dest, 128, "i32_%s", "CollectibleType");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v3);
    UFG::qSPrintf(&dest, 128, "i32_%s", "CollectibleName");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v4);
    UFG::qSPrintf(&dest, 128, "i32_%s", "NewStage");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v8);
    v12 = UFG::qGetSystemTimeUTC();
    UFG::qSPrintf(&dest, 128, "i64_%s", "Timestamp");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v12);
    v13 = UFG::Metrics::msInstance.mSimTimeMSec;
    UFG::qSPrintf(&dest, 128, "i64_%s", "SimTime");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, &dest, v13);
    UFG::OSuiteDBLogger::SubmitMetric(v9, 1);
  }
}

// File Line: 2129
// RVA: 0x5063D0
void __fastcall UFG::TSGameSlice::Mthd_release_interior_triggers(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // ebp
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::TriggerRegion *v5; // rdi
  UFG::TriggerTarget *i; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v7; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v8; // rax
  UFG::InteriorTriggerProperties::tri_state *v9; // rbx

  v2 = 0;
  if ( UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    do
    {
      v3 = UFG::TSGameSlice::msInteriorTriggerData.p[v2].mTriggerName.mUID;
      if ( v3 )
      {
        v4 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v3);
        if ( v4 )
        {
          v5 = (UFG::TriggerRegion *)&v4[-2].mNULL;
          if ( v4 != (UFG::qBaseTreeRB *)112 )
          {
            if ( (v5->mModeFlags & 0x10012) == 65554 )
              ((void (__fastcall *)(UFG::TriggerRegion *))v5->vfptr[19].__vecDelDtor)(v5);
            for ( i = (UFG::TriggerTarget *)v5->mTrackList.mNode.mNext;
                  i != (UFG::TriggerTarget *)&v5->mTrackList;
                  i = (UFG::TriggerTarget *)v5->mTrackList.mNode.mNext )
            {
              v7 = i->mPrev;
              v8 = i->mNext;
              v7->mNext = v8;
              v8->mPrev = v7;
              i->mPrev = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&i->mPrev;
              i->mNext = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&i->mPrev;
              UFG::TriggerTarget::~TriggerTarget(i);
              operator delete[](i);
            }
            UFG::TriggerRegion::ResetEvents(v5);
            UFG::TriggerRegion::EnableHot(v5, 0);
          }
        }
      }
      ++v2;
    }
    while ( v2 < UFG::TSGameSlice::msInteriorTriggerData.size );
  }
  if ( UFG::TSGameSlice::msInteriorTriggerData.p )
  {
    v9 = &UFG::TSGameSlice::msInteriorTriggerData.p[-1].mOnEnterOnly;
    `eh vector destructor iterator'(
      UFG::TSGameSlice::msInteriorTriggerData.p,
      0xA8ui64,
      UFG::TSGameSlice::msInteriorTriggerData.p[-1].mOnEnterOnly,
      (void (__fastcall *)(void *))UFG::InteriorTriggerProperties::~InteriorTriggerProperties);
    operator delete[](v9);
  }
  UFG::TSGameSlice::msInteriorTriggerData.p = 0i64;
  *(_QWORD *)&UFG::TSGameSlice::msInteriorTriggerData.size = 0i64;
}

// File Line: 2161
// RVA: 0x50B590
void __fastcall UFG::TSGameSlice::Mthd_setup_interior_triggers(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  signed __int64 v3; // rdx
  UFG::GameSlice *v4; // rsi
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rdi
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rbx
  UFG::qPropertyList *v9; // rdi
  UFG::qPropertyList *v10; // rbx
  unsigned int v11; // edx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]
  UFG::qSymbol v13; // [rsp+50h] [rbp+18h]
  UFG::qSymbol v14; // [rsp+58h] [rbp+20h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
    v3 = (signed __int64)&v2[-2].i_ptr_id;
  else
    v3 = 0i64;
  v4 = *(UFG::GameSlice **)(v3 + 152);
  UFG::qSymbol::create_from_string(&result, "List");
  v5 = UFG::qSymbol::create_from_string(&v13, "default-interiors-list");
  v6 = UFG::PropertySetManager::GetPropertySet(v5);
  v7 = UFG::qSymbol::create_from_string(&v14, "default-interiors-lighting");
  v8 = UFG::PropertySetManager::GetPropertySet(v7);
  v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, &result, DEPTH_RECURSE);
  v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(v8, &result, DEPTH_RECURSE);
  v11 = v9->mNumElements + v10->mNumElements;
  if ( v11 > UFG::TSGameSlice::msInteriorTriggerData.capacity )
    UFG::qArray<UFG::InteriorTriggerProperties,0>::Reallocate(
      &UFG::TSGameSlice::msInteriorTriggerData,
      v11,
      "msInteriorTriggerData");
  UFG::TSGameSlice::SetupTriggersFromList(v9, v4);
  UFG::TSGameSlice::SetupTriggersFromList(v10, v4);
}

// File Line: 2190
// RVA: 0x4E0AE0
void UFG::TSGameSlice::FromCPP_setup_interior_triggers(void)
{
  UFG::qSymbol *v0; // rax
  UFG::qPropertySet *v1; // rdi
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::qPropertyList *v4; // rdi
  UFG::qPropertyList *v5; // rbx
  unsigned int v6; // edx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]
  UFG::qSymbol v8; // [rsp+38h] [rbp+10h]
  UFG::qSymbol v9; // [rsp+40h] [rbp+18h]

  if ( !UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    UFG::qSymbol::create_from_string(&result, "List");
    v0 = UFG::qSymbol::create_from_string(&v8, "default-interiors-list");
    v1 = UFG::PropertySetManager::GetPropertySet(v0);
    v2 = UFG::qSymbol::create_from_string(&v9, "default-interiors-lighting");
    v3 = UFG::PropertySetManager::GetPropertySet(v2);
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v1, &result, DEPTH_RECURSE);
    v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, &result, DEPTH_RECURSE);
    v6 = v4->mNumElements + v5->mNumElements;
    if ( v6 > UFG::TSGameSlice::msInteriorTriggerData.capacity )
      UFG::qArray<UFG::InteriorTriggerProperties,0>::Reallocate(
        &UFG::TSGameSlice::msInteriorTriggerData,
        v6,
        "msInteriorTriggerData");
    UFG::TSGameSlice::SetupTriggersFromList(v4, 0i64);
    UFG::TSGameSlice::SetupTriggersFromList(v5, 0i64);
  }
}

