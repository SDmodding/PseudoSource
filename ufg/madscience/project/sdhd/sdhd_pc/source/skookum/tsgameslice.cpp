// File Line: 92
// RVA: 0x1531080
__int64 dynamic_initializer_for__UFG::TSGameSlice::msInteriorTriggerData__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TSGameSlice::msInteriorTriggerData__);
}

// File Line: 117
// RVA: 0x4D3110
void UFG::TSGameSlice::BindAtomics(void)
{
  SSClass *v0; // rax
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

  UFG::SkookumMgr::mspGameSliceClass = (SSActorClass *)SSBrain::get_class("GameSlice");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_name",
    UFG::TSGameSlice::Mthd_gameslice_get_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_layer_name",
    UFG::TSGameSlice::Mthd_gameslice_get_layer_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "start_gameslice",
    UFG::TSGameSlice::Mthd_start_gameslice,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "complete_gameslice",
    UFG::TSGameSlice::Mthd_complete_gameslice,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_fail_gameslice",
    UFG::TSGameSlice::Coro_fail_gameslice,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_gameslice_restoring",
    UFG::TSGameSlice::Mthd_is_gameslice_restoring,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_gameslice_exclusive",
    UFG::TSGameSlice::Mthd_is_gameslice_exclusive,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_gameslice_random_exclusive",
    UFG::TSGameSlice::Mthd_is_gameslice_random_exclusive,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_challenge_mode",
    UFG::TSGameSlice::Mthd_is_challenge_mode,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_gameslice_single_container",
    UFG::TSGameSlice::Mthd_is_gameslice_single_container,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_gameslice_active_master",
    UFG::TSGameSlice::Mthd_is_gameslice_active_master,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_gameslice_failed",
    UFG::TSGameSlice::Mthd_is_gameslice_failed,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_progression_fail_pending",
    UFG::TSGameSlice::Mthd_is_progression_fail_pending,
    1,
    rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_target_gameslice_completed",
    UFG::TSGameSlice::Mthd_is_target_gameslice_completed,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_exit_challenge_private",
    UFG::TSGameSlice::Mthd_gameslice_exit_challenge_private,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_restore_checkpoint_private",
    UFG::TSGameSlice::Mthd_gameslice_restore_checkpoint_private,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_cancel_mission_private",
    UFG::TSGameSlice::Mthd_gameslice_cancel_mission_private,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_enable_on_enter_trigger",
    UFG::TSGameSlice::Mthd_gameslice_enable_on_enter_trigger,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_enable_on_exit_trigger",
    UFG::TSGameSlice::Mthd_gameslice_enable_on_exit_trigger,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_disable_on_enter_trigger",
    UFG::TSGameSlice::Mthd_gameslice_disable_on_enter_trigger,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_disable_on_exit_trigger",
    UFG::TSGameSlice::Mthd_gameslice_disable_on_exit_trigger,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_type",
    UFG::TSGameSlice::Mthd_gameslice_get_type,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "get_active_master",
    UFG::TSGameSlice::MthdC_get_active_master,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "reset_gameslice_fail_timer_debug",
    UFG::TSGameSlice::MthdC_reset_gameslice_fail_timer_debug,
    1,
    rebindb);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_progression_trigger",
    UFG::TSGameSlice::Mthd_gameslice_get_progression_trigger,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_rewards_properties",
    UFG::TSGameSlice::Mthd_gameslice_get_rewards_properties,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_restore_vehicle",
    UFG::TSGameSlice::Mthd_gameslice_get_restore_vehicle,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_gameslice_play_intro_nis",
    UFG::TSGameSlice::Coro_gameslice_play_intro_nis,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_gameslice_code_setup",
    UFG::TSGameSlice::Coro_gameslice_code_setup,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_code_cleanup",
    UFG::TSGameSlice::Mthd_gameslice_code_cleanup,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_claim_exclusive",
    UFG::TSGameSlice::Mthd_gameslice_claim_exclusive,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_get_completion_count",
    UFG::TSGameSlice::Mthd_gameslice_get_completion_count,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_gameslice_wait_progression_trigger_private",
    UFG::TSGameSlice::Coro_gameslice_wait_progression_trigger_private,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_gameslice_wait_case_open_private",
    UFG::TSGameSlice::Coro_gameslice_wait_case_open_private,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_gameslice_wait_until_in_game_state",
    UFG::TSWorld::Coro_wait_until_in_game_state,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_gameslice_wait_until_tracker_running",
    UFG::TSGameSlice::Coro_gameslice_wait_until_tracker_running,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "enable_objective",
    UFG::TSGameSlice::Mthd_enable_objective,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "disable_objective",
    UFG::TSGameSlice::Mthd_disable_objective,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "set_objective_caption",
    UFG::TSGameSlice::Mthd_set_objective_caption,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "set_objective_status",
    UFG::TSGameSlice::Mthd_set_objective_status,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_objective_complete",
    UFG::TSGameSlice::Mthd_is_objective_complete,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "is_single_character_sprinkle",
    UFG::TSGameSlice::Mthd_is_single_character_sprinkle,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "get_override_for_sprinkle_character",
    UFG::TSGameSlice::Mthd_get_override_for_sprinkle_character,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "attach_to_objective",
    UFG::TSGameSlice::Mthd_attach_to_objective,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "remove_from_objective",
    UFG::TSGameSlice::Mthd_remove_from_objective,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "faction_get_standing",
    UFG::TSGameSlice::Mthd_faction_get_standing,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "set_battle_type",
    UFG::TSGameSlice::Mthd_set_battle_type,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "set_dialogue_state",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindc);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "load_audio_resources",
    UFG::TSGameSlice::Mthd_load_audio_resources,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "unload_audio_resources",
    UFG::TSGameSlice::Mthd_unload_audio_resources,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_enable_ambient_units",
    UFG::TSGameSlice::Mthd_cops_enable_ambient_units,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_enable",
    UFG::TSGameSlice::Mthd_cops_enable,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_get_ratio_for_current_heat_level",
    UFG::TSGameSlice::Mthd_cops_get_ratio_for_current_heat_level,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_get_heat_level",
    UFG::TSGameSlice::Mthd_cops_get_heat_level,
    1,
    rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_set_heat_level",
    UFG::TSGameSlice::Mthd_cops_set_heat_level,
    1,
    rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_exclude_player_for_rest_of_chase",
    UFG::TSGameSlice::Mthd_cops_exclude_player_for_rest_of_chase,
    1,
    rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_escalate_to_minimum_heat_level",
    UFG::TSGameSlice::Mthd_cops_escalate_to_minimum_heat_level,
    1,
    rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_get_enabled",
    UFG::TSGameSlice::Mthd_cops_get_enabled,
    1,
    rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_trigger_instant_cooldown",
    UFG::TSGameSlice::Mthd_cops_trigger_instant_cooldown,
    1,
    rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_is_cooling_down",
    UFG::TSGameSlice::Mthd_cops_is_cooling_down,
    1,
    rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "cops_debug_cap_heat_level",
    UFG::TSGameSlice::Mthd_cops_debug_cap_heat_level,
    1,
    rebindn);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_wait_until_cops_heat_level_below",
    UFG::TSGameSlice::Coro_wait_until_cops_heat_level_below,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_camera_raycast_to_target",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSGameSlice::Coro_camera_raycast_to_target,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_async_is_target_occluded",
    UFG::TSGameSlice::Coro_async_is_target_occluded,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "_launch_store_front",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSGameSlice::Coro_launch_store_front,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_set_restore_vehicle_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_restore_vehicle_location_marker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_set_restore_location_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_restore_location_marker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_set_cancel_location_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_cancel_location_marker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_set_complete_location_marker",
    UFG::TSGameSlice::Mthd_gameslice_set_complete_location_marker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "gameslice_set_restore_location",
    UFG::TSGameSlice::Mthd_gameslice_set_restore_location,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "missionscoring_add_cop_event",
    UFG::TSGameSlice::Mthd_missionscoring_add_cop_event,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "missionscoring_add_triad_event",
    UFG::TSGameSlice::Mthd_missionscoring_add_triad_event,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "borrow_ambient_actor",
    UFG::TSGameSlice::Mthd_borrow_ambient_actor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "despawn_npc",
    UFG::TSGameSlice::Mthd_despawn_npc,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "send_collectible_telemetry_stat",
    UFG::TSGameSlice::Mthd_send_collectible_telemetry_stat,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "release_interior_triggers",
    UFG::TSGameSlice::Mthd_release_interior_triggers,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspGameSliceClass,
    "setup_interior_triggers",
    UFG::TSGameSlice::Mthd_setup_interior_triggers,
    SSBindFlag_instance_no_rebind);
  v0 = SSBrain::get_class("ScriptTests");
  SSClass::register_method_func(
    v0,
    "launch_if_available",
    UFG::TSGameSlice::Mthd_ScriptTest_launch_if_available,
    SSBindFlag_instance_no_rebind);
}

// File Line: 230
// RVA: 0x4FA8A0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax
  AString *v5; // rax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v11; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString v13; // [rsp+48h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    AString::AString(&v13, *(const char **)(*((_QWORD *)p_i_ptr_id + 19) + 32i64), 0);
    *ppResult = SSString::as_instance(v5);
    i_str_ref_p = v13.i_str_ref_p;
    if ( v13.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v11 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v11) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

// File Line: 242
// RVA: 0x4FA850
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_layer_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)(*((_QWORD *)p_i_ptr_id + 19) + 168i64));
  }
}

// File Line: 254
// RVA: 0x50C010
void __fastcall UFG::TSGameSlice::Mthd_start_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::GameSlice **p_i_ptr_id; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = (UFG::GameSlice **)&i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  UFG::GameSlice::SetState(p_i_ptr_id[19], STATE_STARTED);
}

// File Line: 269
// RVA: 0x4F6920
void __fastcall UFG::TSGameSlice::Mthd_complete_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    UFG::GameSlice::CompleteSlice((UFG::GameSlice *)i_obj_p[8].vfptr);
  else
    UFG::GameSlice::CompleteSlice(MEMORY[0x98]);
}

// File Line: 278
// RVA: 0x4FAC90
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_restore_vehicle_location_marker(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v4; // r8
  SSData **i_array_p; // rdx
  int i_user_data; // xmm0_4

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = *((_QWORD *)p_i_ptr_id + 19);
  if ( v4 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    *(_DWORD *)(v4 + 180) = (*i_array_p)->i_data_p->i_user_data;
    *(_DWORD *)(v4 + 192) = i_user_data;
  }
}

// File Line: 290
// RVA: 0x4FAC50
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_restore_location_marker(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v4; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = *((_QWORD *)p_i_ptr_id + 19);
  if ( v4 )
    *(_DWORD *)(v4 + 176) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 302
// RVA: 0x4FABA0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_cancel_location_marker(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v4; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = *((_QWORD *)p_i_ptr_id + 19);
  if ( v4 )
    *(_DWORD *)(v4 + 196) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 314
// RVA: 0x4FABE0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_complete_location_marker(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v4; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = *((_QWORD *)p_i_ptr_id + 19);
  if ( v4 )
    *(_DWORD *)(v4 + 200) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 327
// RVA: 0x4FAC20
void __fastcall UFG::TSGameSlice::Mthd_gameslice_set_restore_location(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qVector3 *i_user_data; // rbx
  UFG::ProgressionTracker *v3; // rax

  i_user_data = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetScriptRestoreLocation(v3, i_user_data);
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
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rax
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // r8
  UFG::GameSlice *v6; // rcx

  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  if ( ArgByNameOrInstance )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v6 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
    if ( v6 )
      UFG::GameSlice::BorrowAmbientActor(v6, (UFG::SimObjectCharacter *)ArgByNameOrInstance);
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
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *Parent; // rbx
  SSInstance *i; // rdi
  UFG::ProgressionTracker *v5; // rax
  UFG::qString caption; // [rsp+28h] [rbp-30h] BYREF

  if ( !pScope->i_update_count )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    Parent = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
    for ( i = (*pScope->i_data.i_array_p)->i_data_p; Parent; Parent = UFG::GameSlice::GetParent(Parent) )
    {
      if ( !UFG::GameSlice::GetParent(Parent) )
        break;
    }
    UFG::qString::qString(&caption, *(const char **)i->i_user_data);
    v5 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::OnFailGameSlice(v5, Parent, &caption);
    UFG::qString::~qString(&caption);
  }
  return 0;
}

// File Line: 404
// RVA: 0x501580
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_restoring(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax
  __int64 v5; // rax
  bool v6; // bl
  UFG::GameStatTracker *v7; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v5 = *((_QWORD *)p_i_ptr_id + 19);
    v6 = *(_DWORD *)(v5 + 264) == 2;
    if ( *(_DWORD *)(v5 + 264) == 2 && !*(_QWORD *)(v5 + 368) && *(int *)(v5 + 268) > 0 )
    {
      v7 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v7, RestoreUsed, 1);
    }
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 421
// RVA: 0x501490
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_exclusive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    *ppResult = SSBoolean::pool_new(*(_BYTE *)(*((_QWORD *)p_i_ptr_id + 19) + 324i64) != 0);
  }
}

// File Line: 433
// RVA: 0x501530
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_random_exclusive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    *ppResult = SSBoolean::pool_new(*(_BYTE *)(*((_QWORD *)p_i_ptr_id + 19) + 327i64) != 0);
  }
}

// File Line: 445
// RVA: 0x500F70
void __fastcall UFG::TSGameSlice::Mthd_is_challenge_mode(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v3; // rax

  if ( ppResult )
  {
    v3 = UFG::ProgressionTracker::Instance();
    *ppResult = SSBoolean::pool_new((unsigned int)(v3->mModeType - 1) <= 1);
  }
}

// File Line: 457
// RVA: 0x501610
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_single_container(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *v5; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v5 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
    if ( !v5 || UFG::GameSlice::GetParent(v5) || (unsigned int)UFG::GameSlice::GetNumChildren(v5) )
      *ppResult = SSBoolean::pool_new(0);
    else
      *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 469
// RVA: 0x501410
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_active_master(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // r8
  UFG::GameSlice *v5; // rbx
  UFG::ProgressionTracker *v6; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v5 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
    if ( v5 && (v6 = UFG::ProgressionTracker::Instance(), v5 == UFG::ProgressionTracker::GetActiveMaster(v6)) )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 481
// RVA: 0x4FAAE0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *Parent; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    Parent = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
    if ( !Parent )
      goto LABEL_9;
    while ( UFG::GameSlice::GetParent(Parent) )
    {
      Parent = UFG::GameSlice::GetParent(Parent);
      if ( !Parent )
        goto LABEL_9;
    }
    if ( Parent )
      *ppResult = SSSymbol::as_instance((ASymbol *)UFG::gGameSliceTypeSymbols[Parent->mType]);
    else
LABEL_9:
      *ppResult = SSSymbol::as_instance((ASymbol *)UFG::gGameSliceTypeSymbols[0]);
  }
}

// File Line: 500
// RVA: 0x4E7180
void __fastcall UFG::TSGameSlice::MthdC_get_active_master(SSInvokedMethod *pScope, SSActor **ppResult)
{
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSlice *ActiveMaster; // rax
  UFG::SSGameSlice *mScript; // rax

  if ( ppResult )
  {
    v3 = UFG::ProgressionTracker::Instance();
    ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v3);
    if ( ActiveMaster )
    {
      mScript = ActiveMaster->mScript;
      if ( mScript )
      {
        ++mScript->i_ref_count;
        *ppResult = &mScript->SSActor;
      }
      else
      {
        *ppResult = 0i64;
      }
    }
    else
    {
      *ppResult = (SSActor *)SSBrain::c_nil_p;
    }
  }
}

// File Line: 513
// RVA: 0x4EC3E0
void __fastcall UFG::TSGameSlice::MthdC_reset_gameslice_fail_timer_debug(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSlice *Parent; // rbx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::ProgressionTracker::Instance();
  Parent = (UFG::GameSlice *)UFG::ProgressionTracker::Find(v3, (UFG::qSymbol *)&i_data_p->i_user_data, 0);
  if ( Parent )
  {
    do
    {
      if ( !UFG::GameSlice::GetParent(Parent) )
        break;
      Parent = UFG::GameSlice::GetParent(Parent);
    }
    while ( Parent );
    Parent->mCompletionStatusTimestamp = 0i64;
  }
}

// File Line: 535
// RVA: 0x5014E0
void __fastcall UFG::TSGameSlice::Mthd_is_gameslice_failed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    *ppResult = SSBoolean::pool_new(((*(_DWORD *)(*((_QWORD *)p_i_ptr_id + 19) + 272i64) - 1) & 0xFFFFFFFD) == 0);
  }
}

// File Line: 548
// RVA: 0x503030
void __fastcall UFG::TSGameSlice::Mthd_is_progression_fail_pending(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v3; // rax

  if ( ppResult )
  {
    v3 = UFG::ProgressionTracker::Instance();
    *ppResult = SSBoolean::pool_new(v3->mState == 10);
  }
}

// File Line: 562
// RVA: 0x503450
void __fastcall UFG::TSGameSlice::Mthd_is_target_gameslice_completed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qBaseTreeRB *v5; // rax

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    v4 = UFG::ProgressionTracker::Instance();
    v5 = UFG::ProgressionTracker::Find(v4, (UFG::qSymbol *)&i_data_p->i_user_data, 0);
    if ( v5 )
      *ppResult = SSBoolean::pool_new(LODWORD(v5[3].mNULL.mChild[1]) == 8);
    else
      *ppResult = SSBoolean::pool_new(0);
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
void __fastcall UFG::TSGameSlice::Mthd_gameslice_restore_checkpoint_private(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::RestoreCheckpoint(v2);
}

// File Line: 601
// RVA: 0x4FA210
void __fastcall UFG::TSGameSlice::Mthd_gameslice_cancel_mission_private(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::ProgressionTracker::RestoreType v3; // ebx
  unsigned int *p_i_ptr_id; // rdx
  UFG::GameSlice *v5; // rsi
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  bool v8; // bp
  UFG::qBaseTreeRB *Named; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::ProgressionTracker *v11; // rax
  UFG::ProgressionTracker *v12; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = RestoreType_Unknown;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v5 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  v8 = (*i_array_p)->i_data_p->i_user_data != 0;
  if ( LODWORD(i_data_p->i_user_data) == UFG::qSymbol::create_from_string(&result, "safehouse")->mUID )
    goto LABEL_18;
  if ( LODWORD(i_data_p->i_user_data) == UFG::qSymbol::create_from_string(&result, "hospital")->mUID )
  {
    v3 = RestoreType_Hospital;
    goto LABEL_19;
  }
  if ( LODWORD(i_data_p->i_user_data) == UFG::qSymbol::create_from_string(&result, "policestation")->mUID )
  {
    v3 = RestoreType_PoliceStation;
    goto LABEL_19;
  }
  if ( LODWORD(i_data_p->i_user_data) != UFG::qSymbol::create_from_string(&result, "cancelmarker")->mUID )
  {
    if ( LODWORD(i_data_p->i_user_data) != UFG::qSymbol::create_from_string(&result, "currentlocation")->mUID )
      goto LABEL_19;
    if ( LocalPlayer )
    {
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
        goto LABEL_14;
    }
LABEL_18:
    v3 = RestoreType_SafehouseFailure;
    goto LABEL_19;
  }
  result.mUID = UFG::GameSlice::GetCancelLocationMarker(v5)->mUID;
  if ( result.mUID != -1 )
  {
    Named = UFG::MarkerBase::GetNamed(&result);
    if ( Named )
    {
      m_pTransformNodeComponent = (UFG::TransformNodeComponent *)Named[1].mNULL.mParent;
LABEL_14:
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v11 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::SetScriptRestoreLocation(
        v11,
        (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3);
      v3 = RestoreType_ScriptLocation;
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
  SSObjectBase *i_obj_p; // r8
  UFG::GameSlice **p_i_ptr_id; // rcx
  UFG::qPropertySet *RewardsProperties; // rax
  unsigned __int64 v6; // rdi

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = (UFG::GameSlice **)&i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    RewardsProperties = UFG::GameSlice::GetRewardsProperties(p_i_ptr_id[19]);
    v6 = (unsigned __int64)RewardsProperties;
    if ( RewardsProperties )
    {
      UFG::qPropertySet::AddRef(RewardsProperties);
      *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, v6);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 675
// RVA: 0x4FA9A0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_restore_vehicle(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax
  UFG::SimObject *v5; // rcx
  UFG::TSActorComponent *ComponentOfType; // rax
  SSActorClass *v7; // rsi
  UFG::TSActorComponent *v8; // rdi
  SSClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  UFG::TSActor *Actor; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v5 = *(UFG::SimObject **)(*((_QWORD *)p_i_ptr_id + 19) + 512i64);
    if ( v5
      && ((ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                        v5,
                                                        UFG::TSActorComponent::_TypeUID),
           v7 = UFG::TSVehicle::mClass,
           v8 = ComponentOfType,
           i_class_p = UFG::TSActorComponent::GetActor(ComponentOfType)->i_class_p,
           v7 == i_class_p)
       || (i_superclass_p = i_class_p->i_superclass_p) != 0i64 && SSClass::is_class(i_superclass_p, v7)) )
    {
      Actor = UFG::TSActorComponent::GetActor(v8);
      ++Actor->i_ref_count;
      *ppResult = Actor;
    }
    else
    {
      *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    }
  }
}

// File Line: 735
// RVA: 0x4FA530
void __fastcall UFG::TSGameSlice::Mthd_gameslice_enable_on_enter_trigger(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  fastdelegate::detail::GenericClass *v5; // r14
  SSInstance *i_data_p; // rdx
  UFG::TriggerRegion *i_user_data; // rdi
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  __int64 v10; // rcx
  UFG::TriggerTarget *mNext; // rbx
  __int64 i; // rbp
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mPrev; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v14; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v5 = (fastdelegate::detail::GenericClass *)*((_QWORD *)p_i_ptr_id + 19);
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_11;
  if ( i_data_p->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    i_user_data = (UFG::TriggerRegion *)i_data_p->i_user_data;
    goto LABEL_12;
  }
  v8 = i_data_p->i_user_data;
  if ( !v8
    || (v9 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v8)) == 0i64
    || (i_user_data = (UFG::TriggerRegion *)&v9[-2].mNULL, v9 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_11:
    i_user_data = 0i64;
  }
LABEL_12:
  v10 = *((_QWORD *)pScope->i_data.i_array_p + 1);
  mNext = (UFG::TriggerTarget *)i_user_data->mTrackList.mNode.mNext;
  for ( i = *(_QWORD *)(v10 + 8);
        mNext != (UFG::TriggerTarget *)&i_user_data->mTrackList;
        mNext = (UFG::TriggerTarget *)i_user_data->mTrackList.mNode.mNext )
  {
    mPrev = mNext->mPrev;
    v14 = mNext->mNext;
    mPrev->mNext = v14;
    v14->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::TriggerTarget::~TriggerTarget(mNext);
    operator delete[](mNext);
  }
  UFG::TriggerRegion::ResetEvents(i_user_data);
  UFG::TriggerRegion::TrackTarget(i_user_data, *(UFG::SimObject **)(i + 208), 0i64);
  i_user_data->mOnEnteredDelegate.m_Closure.m_pthis = v5;
  i_user_data->mOnEnteredDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::GameSlice::OnEnterTrigger;
  UFG::TriggerRegion::EnableHot(i_user_data, 1);
}

// File Line: 755
// RVA: 0x4FA660
void __fastcall UFG::TSGameSlice::Mthd_gameslice_enable_on_exit_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  fastdelegate::detail::GenericClass *v5; // r14
  SSInstance *i_data_p; // rdx
  UFG::TriggerRegion *i_user_data; // rdi
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  __int64 v10; // rcx
  UFG::TriggerTarget *mNext; // rbx
  __int64 i; // rbp
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mPrev; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v14; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v5 = (fastdelegate::detail::GenericClass *)*((_QWORD *)p_i_ptr_id + 19);
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_11;
  if ( i_data_p->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    i_user_data = (UFG::TriggerRegion *)i_data_p->i_user_data;
    goto LABEL_12;
  }
  v8 = i_data_p->i_user_data;
  if ( !v8
    || (v9 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v8)) == 0i64
    || (i_user_data = (UFG::TriggerRegion *)&v9[-2].mNULL, v9 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_11:
    i_user_data = 0i64;
  }
LABEL_12:
  v10 = *((_QWORD *)pScope->i_data.i_array_p + 1);
  mNext = (UFG::TriggerTarget *)i_user_data->mTrackList.mNode.mNext;
  for ( i = *(_QWORD *)(v10 + 8);
        mNext != (UFG::TriggerTarget *)&i_user_data->mTrackList;
        mNext = (UFG::TriggerTarget *)i_user_data->mTrackList.mNode.mNext )
  {
    mPrev = mNext->mPrev;
    v14 = mNext->mNext;
    mPrev->mNext = v14;
    v14->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::TriggerTarget::~TriggerTarget(mNext);
    operator delete[](mNext);
  }
  UFG::TriggerRegion::ResetEvents(i_user_data);
  UFG::TriggerRegion::TrackTarget(i_user_data, *(UFG::SimObject **)(i + 208), 0i64);
  i_user_data->mOnExitedDelegate.m_Closure.m_pthis = v5;
  i_user_data->mOnExitedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::GameSlice::OnExitTrigger;
  UFG::TriggerRegion::EnableHot(i_user_data, 1);
}

// File Line: 775
// RVA: 0x4FA450
void __fastcall UFG::TSGameSlice::Mthd_gameslice_disable_on_enter_trigger(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdx
  UFG::TriggerRegion *i_user_data; // rcx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_7;
  if ( i_data_p->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    i_user_data = (UFG::TriggerRegion *)i_data_p->i_user_data;
    goto LABEL_8;
  }
  v4 = i_data_p->i_user_data;
  if ( !v4
    || (v5 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v4)) == 0i64
    || (i_user_data = (UFG::TriggerRegion *)&v5[-2].mNULL, v5 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_7:
    i_user_data = 0i64;
  }
LABEL_8:
  i_user_data->mOnEnteredDelegate.m_Closure.m_pFunction = 0i64;
  i_user_data->mOnEnteredDelegate.m_Closure.m_pthis = 0i64;
  UFG::TriggerRegion::EnableHot(i_user_data, 0);
}

// File Line: 787
// RVA: 0x4FA4C0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_disable_on_exit_trigger(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdx
  UFG::TriggerRegion *i_user_data; // rcx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_7;
  if ( i_data_p->i_class_p == UFG::TSTriggerRegion::mspTriggerRegionClass )
  {
    i_user_data = (UFG::TriggerRegion *)i_data_p->i_user_data;
    goto LABEL_8;
  }
  v4 = i_data_p->i_user_data;
  if ( !v4
    || (v5 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v4)) == 0i64
    || (i_user_data = (UFG::TriggerRegion *)&v5[-2].mNULL, v5 == (UFG::qBaseTreeRB *)112) )
  {
LABEL_7:
    i_user_data = 0i64;
  }
LABEL_8:
  i_user_data->mOnExitedDelegate.m_Closure.m_pFunction = 0i64;
  i_user_data->mOnExitedDelegate.m_Closure.m_pthis = 0i64;
  UFG::TriggerRegion::EnableHot(i_user_data, 0);
}

// File Line: 799
// RVA: 0x4FA950
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_progression_trigger(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)(*((_QWORD *)p_i_ptr_id + 19) + 172i64));
  }
}

// File Line: 811
// RVA: 0x4DB2D0
bool __fastcall UFG::TSGameSlice::Coro_gameslice_play_intro_nis(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v4; // rbp
  UFG::qSharedStringData *v5; // rbx
  const char *v7; // rbx
  NISManager *Instance; // rax
  NISInstance *v9; // rbx
  NISManager *v10; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = *((_QWORD *)p_i_ptr_id + 19);
  v5 = (UFG::qSharedStringData *)(*(_QWORD *)(v4 + 64) - 48i64);
  if ( v5 == UFG::qSharedStringData::GetEmptyString() )
    return 1;
  if ( pScope->i_update_count || NISManager::GetInstance()->mState )
    return NISManager::GetInstance()->mState == STATE_INVALID;
  v7 = *(const char **)(v4 + 64);
  Instance = NISManager::GetInstance();
  v9 = NISManager::CreateInstance(Instance, v7);
  v9->mbDestroyOnUnload = 1;
  v9->mbIntermediateNIS = *(_BYTE *)(v4 + 81);
  v9->mbPostNISFadeIn = *(_BYTE *)(v4 + 80);
  v9->mpPostNISSceneSettings = *(UFG::SceneSettings **)(v4 + 72);
  v10 = NISManager::GetInstance();
  NISManager::Play(v10, v9);
  return 0;
}

// File Line: 841
// RVA: 0x4DB1B0
bool __fastcall UFG::TSGameSlice::Coro_gameslice_code_setup(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rcx
  unsigned int *p_i_ptr_id; // rdi
  __int64 v4; // rdi
  int v5; // ebx
  UFG::CopSystem *v6; // rax
  UFG::SceneSettings *v7; // rbx
  UFG::ProgressionTracker *v8; // rax
  UFG::ProgressionTracker *v9; // rax
  UFG::SceneSettings *v10; // rbx
  UFG::ProgressionTracker *v11; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || (p_i_ptr_id = &i_obj_p[-2].i_ptr_id, pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id) )
    p_i_ptr_id = 0i64;
  v4 = *((_QWORD *)p_i_ptr_id + 19);
  if ( !pScope->i_update_count )
  {
    v5 = *(_DWORD *)(v4 + 208);
    if ( v5 > 0 )
    {
      v6 = UFG::CopSystem::Instance();
      v6->vfptr[100].__vecDelDtor(v6, v5);
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
  if ( *(_DWORD *)(v4 + 268) == 4 || !UFG::GameSlice::ShouldTeleportOnStart((UFG::GameSlice *)v4) )
  {
    UFG::GameSlice::SetupTimeAndWeather((UFG::GameSlice *)v4, 0);
    return 1;
  }
  else if ( pScope->i_update_count )
  {
    return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_10;
  }
  else
  {
    v10 = *(UFG::SceneSettings **)(v4 + 352);
    v11 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ApplySceneSettings(v11, v10);
    return 0;
  }
}

// File Line: 897
// RVA: 0x4FA3F0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_code_cleanup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *v4; // rbx
  UFG::CopSystem *v5; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
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
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *v5; // rbx
  bool v6; // cl

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v5 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  if ( UFG::GameSlice::IsExclusiveAvailable(v5) )
  {
    UFG::GameSlice::ClaimExclusive(v5);
    v6 = 1;
  }
  else
  {
    v6 = v5->mExclusiveChild == v5;
  }
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v6);
}

// File Line: 948
// RVA: 0x4FA7C0
void __fastcall UFG::TSGameSlice::Mthd_gameslice_get_completion_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int mCompletionCount; // edi
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *Parent; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    mCompletionCount = 0;
    if ( !i_obj_p || (p_i_ptr_id = &i_obj_p[-2].i_ptr_id, pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id) )
      p_i_ptr_id = 0i64;
    Parent = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
    if ( Parent )
    {
      while ( UFG::GameSlice::GetParent(Parent) )
      {
        Parent = UFG::GameSlice::GetParent(Parent);
        if ( !Parent )
          goto LABEL_10;
      }
      mCompletionCount = Parent->mCompletionCount;
    }
LABEL_10:
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, mCompletionCount);
  }
}

// File Line: 966
// RVA: 0x4DB400
bool __fastcall UFG::TSGameSlice::Coro_gameslice_wait_progression_trigger_private(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rdx
  bool v2; // zf
  UFG::GameSlice **p_i_ptr_id; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p
    || (v2 = pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id, p_i_ptr_id = (UFG::GameSlice **)&i_obj_p[-2].i_ptr_id, !v2) )
  {
    p_i_ptr_id = 0i64;
  }
  return !UFG::GameSlice::IsWaitingForTrigger(p_i_ptr_id[19]);
}

// File Line: 973
// RVA: 0x4DB3A0
bool __fastcall UFG::TSGameSlice::Coro_gameslice_wait_case_open_private(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::CaseInfo *Case; // rax
  bool result; // al

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v3 = *((_QWORD *)p_i_ptr_id + 19);
  result = *(_DWORD *)(v3 + 268) != 10
        || (v4 = UFG::ProgressionTracker::Instance(),
            (Case = UFG::CaseTracker::GetCase(&v4->mCaseTracker, (UFG::GameSlice *)v3)) == 0i64)
        || UFG::CaseInfo::IsOpened(Case);
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
  return !v1->mDirty && v1->mState == STATE_COMPLETE;
}

// File Line: 998
// RVA: 0x4F8D40
void __fastcall UFG::TSGameSlice::Mthd_enable_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdi
  UFG::GameSlice *v4; // rdi
  UFG::ObjectiveTracker *p_mObjectiveTracker; // rbx
  UFG::Objective *Objective; // rdi
  UFG::qSharedStringData *v7; // rbx
  const char *mData; // rbx
  UFG::GameLogManager *Instance; // rcx
  UFG::qString identifier; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol log_type; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol *p_log_type; // [rsp+70h] [rbp+18h]

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  p_mObjectiveTracker = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
  UFG::ObjectiveTracker::UpdateStatus(p_mObjectiveTracker, &identifier, STATUS_ACTIVE, v4);
  Objective = UFG::ObjectiveTracker::FindObjective(p_mObjectiveTracker, &identifier);
  p_log_type = &log_type;
  log_type.mUID = qSymbol_GameLogType_Objective_15.mUID;
  v7 = (UFG::qSharedStringData *)(Objective->mLog.mText - 48);
  if ( v7 == UFG::qSharedStringData::GetEmptyString() )
    mData = Objective->mCaption.mData;
  else
    mData = Objective->mLog.mText;
  Instance = UFG::GameLogManager::getInstance();
  UFG::GameLogManager::LogItem(Instance, (UFG::qSymbol)&log_type, mData);
  UFG::qString::~qString(&identifier);
}

// File Line: 1009
// RVA: 0x4F8500
void __fastcall UFG::TSGameSlice::Mthd_disable_objective(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *v4; // rbx
  UFG::ProgressionTracker *v5; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v5 = UFG::ProgressionTracker::Instance();
  UFG::ObjectiveTracker::UpdateStatus(&v5->mObjectiveTracker, &identifier, STATUS_INACTIVE, v4);
  UFG::qString::~qString(&identifier);
}

// File Line: 1017
// RVA: 0x509060
void __fastcall UFG::TSGameSlice::Mthd_set_objective_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rbx
  UFG::GameSlice *v5; // rbx
  UFG::ProgressionTracker *v6; // rax
  UFG::qString caption; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString identifier; // [rsp+50h] [rbp-38h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v5 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::qString::qString(
    &caption,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  v6 = UFG::ProgressionTracker::Instance();
  UFG::ObjectiveTracker::UpdateCaption(&v6->mObjectiveTracker, &identifier, &caption, v5);
  UFG::qString::~qString(&caption);
  UFG::qString::~qString(&identifier);
}

// File Line: 1026
// RVA: 0x509120
void __fastcall UFG::TSGameSlice::Mthd_set_objective_status(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdi
  UFG::GameSlice *v5; // rdi
  UFG::Objective::Status v6; // ebx
  UFG::ProgressionTracker *v7; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v5 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v6 = (unsigned int)UFG::Objective::MapSymbolToStatus((ASymbol *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1)
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
  SSData **i_array_p; // rdx
  bool v4; // si
  SSInstance *i_data_p; // rbx
  SSClass *i_class_p; // rcx
  UFG::ObjectiveTracker *p_mObjectiveTracker; // rdi
  UFG::Objective *Objective; // rax
  UFG::Objective *v9; // rbx
  UFG::qString blip; // [rsp+38h] [rbp-B0h] BYREF
  UFG::qString identifier; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString corona; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v13; // [rsp+B0h] [rbp-38h] BYREF
  UFG::qSymbol v14; // [rsp+F0h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+100h] [rbp+18h] BYREF

  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::qString::qString(
    &blip,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
  UFG::qString::qString(
    &corona,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64));
  i_array_p = pScope->i_data.i_array_p;
  v4 = i_array_p[4]->i_data_p->i_user_data != 0;
  v14.mUID = -1;
  i_data_p = i_array_p[1]->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( i_class_p == SSBrain::c_string_class_p )
    {
      UFG::qString::qString(&v13, *(const char **)i_data_p->i_user_data);
      v14.mUID = UFG::qSymbol::create_from_string(&result, v13.mData)->mUID;
      UFG::qString::~qString(&v13);
    }
    else if ( i_class_p == SSBrain::c_symbol_class_p )
    {
      v14.mUID = i_data_p->i_user_data;
    }
    else
    {
      if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
        goto LABEL_10;
      v14.mUID = *(_DWORD *)(*(_QWORD *)&i_data_p[4].i_ref_count + 72i64);
    }
    p_mObjectiveTracker = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
    Objective = UFG::ObjectiveTracker::FindObjective(p_mObjectiveTracker, &identifier);
    v9 = Objective;
    if ( Objective )
    {
      UFG::Objective::AddIndicator(Objective, (UFG::qSymbolUC *)&v14, &blip, &corona, 1);
      UFG::ObjectiveTracker::UpdateStatus(p_mObjectiveTracker, v9, v4);
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
  __int64 v3; // rbx
  SSClass *v4; // rcx
  UFG::ObjectiveTracker *p_mObjectiveTracker; // rdi
  UFG::Objective *Objective; // rax
  UFG::Objective *v7; // rbx
  UFG::qString identifier; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v9; // [rsp+50h] [rbp-38h] BYREF
  UFG::qSymbol name; // [rsp+90h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+A0h] [rbp+18h] BYREF

  UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  name.mUID = -1;
  v3 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( v3 )
  {
    v4 = *(SSClass **)(v3 + 24);
    if ( v4 == SSBrain::c_string_class_p )
    {
      UFG::qString::qString(&v9, **(const char ***)(v3 + 32));
      name.mUID = UFG::qSymbol::create_from_string(&result, v9.mData)->mUID;
      UFG::qString::~qString(&v9);
    }
    else if ( v4 == SSBrain::c_symbol_class_p )
    {
      name.mUID = *(_DWORD *)(v3 + 32);
    }
    else
    {
      if ( !v4->vfptr->is_actor_class(v4) )
        goto LABEL_10;
      name.mUID = *(_DWORD *)(*(_QWORD *)(v3 + 208) + 72i64);
    }
    p_mObjectiveTracker = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
    Objective = UFG::ObjectiveTracker::FindObjective(p_mObjectiveTracker, &identifier);
    v7 = Objective;
    if ( Objective )
    {
      UFG::Objective::RemoveIndicator(Objective, &name, 1);
      UFG::ObjectiveTracker::UpdateStatus(p_mObjectiveTracker, v7, 0);
    }
  }
LABEL_10:
  UFG::qString::~qString(&identifier);
}

// File Line: 1094
// RVA: 0x502850
void __fastcall UFG::TSGameSlice::Mthd_is_objective_complete(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // di
  UFG::ProgressionTracker *v4; // rax
  UFG::Objective *Objective; // rax
  UFG::qString identifier; // [rsp+28h] [rbp-30h] BYREF

  if ( ppResult )
  {
    v3 = 0;
    UFG::qString::qString(&identifier, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = UFG::ProgressionTracker::Instance();
    Objective = UFG::ObjectiveTracker::FindObjective(&v4->mObjectiveTracker, &identifier);
    if ( Objective )
      v3 = Objective->mStatus == STATUS_COMPLETED;
    *ppResult = SSBoolean::pool_new(v3);
    UFG::qString::~qString(&identifier);
  }
}

// File Line: 1129
// RVA: 0x503170
void __fastcall UFG::TSGameSlice::Mthd_is_single_character_sprinkle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // r8
  __int64 v4; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v4 = *((_QWORD *)p_i_ptr_id + 19);
    if ( *(_DWORD *)(v4 + 268) == 4 && *(_BYTE *)(v4 + 481) )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 1147
// RVA: 0x4FDAE0
void __fastcall UFG::TSGameSlice::Mthd_get_override_for_sprinkle_character(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  int i_user_data; // edx
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rax
  ASymbol *v6; // rax
  ASymbol *v7; // rcx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v6 = (ASymbol *)*((_QWORD *)p_i_ptr_id + 19);
    v7 = v6 + 121;
    if ( i_user_data )
      v7 = v6 + 122;
    *ppResult = SSSymbol::as_instance(v7);
  }
}

// File Line: 1162
// RVA: 0x4F9C90
void __fastcall UFG::TSGameSlice::Mthd_faction_get_standing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::qSymbol *i_data_p; // rdi
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rsi
  UFG::eFactionClassEnum v7; // eax
  UFG::eFactionStandingEnum Standing; // eax
  UFG::qStaticSymbol *v9; // rax

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (UFG::qSymbol *)(*i_array_p)->i_data_p;
    v5 = (UFG::qSymbol *)i_array_p[1]->i_data_p;
    v6 = UFG::FactionInterface::Get();
    LODWORD(v5) = UFG::FactionInterface::MapSymbolToFaction(v5 + 8);
    v7 = (unsigned int)UFG::FactionInterface::MapSymbolToFaction(i_data_p + 8);
    Standing = (unsigned int)UFG::FactionInterface::GetStanding(&v6->mFactionInterface, v7, (UFG::eFactionClassEnum)v5);
    v9 = UFG::FactionInterface::MapStandingToSymbol(&v6->mFactionInterface, Standing);
    *ppResult = SSSymbol::as_instance((ASymbol *)v9);
  }
}

// File Line: 1177
// RVA: 0x507380
void __fastcall UFG::TSGameSlice::Mthd_set_battle_type(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::eBattleType BattleTypeFromName; // eax
  char *v4; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  BattleTypeFromName = (unsigned int)UFG::GetBattleTypeFromName((UFG::qSymbol *)&i_data_p->i_user_data);
  if ( BattleTypeFromName == eBATTLE_TYPE_NONE )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_data_p->i_user_data);
    UFG::qPrintf("Script error: invalid battle type %s\n", v4);
  }
  else
  {
    UFG::BattleManager::s_pInstance->m_CurrentBattleType = BattleTypeFromName;
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
  v3->vfptr[85].__vecDelDtor(v3, v2);
}

// File Line: 1201
// RVA: 0x4F6DF0
void __fastcall UFG::TSGameSlice::Mthd_cops_enable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax
  bool v3; // bl
  UFG::CopSystem *v4; // rax
  UFG::CopSystem *v5; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = i_data_p->i_user_data != 0;
  if ( !i_data_p->i_user_data )
  {
    v4 = UFG::CopSystem::Instance();
    if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v4->vfptr[89].__vecDelDtor)(v4) )
      UFG::CopSystem::Instance()->mStats.mFinishReason = eFinishReason_Script;
  }
  v5 = UFG::CopSystem::Instance();
  v5->vfptr[4].__vecDelDtor(v5, v3);
}

// File Line: 1213
// RVA: 0x4F7070
void __fastcall UFG::TSGameSlice::Mthd_cops_set_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edi
  UFG::CopSystem *v4; // rax
  UFG::CopSystem *v5; // rbx
  __int64 v6; // rax
  UFG::CopSystem *v7; // rax
  UFG::qString v8; // [rsp+28h] [rbp-30h] BYREF

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v4->vfptr[89].__vecDelDtor)(v4) && !i_user_data )
    UFG::CopSystem::Instance()->mStats.mFinishReason = eFinishReason_Script;
  v5 = UFG::CopSystem::Instance();
  UFG::qString::qString(&v8, **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  LODWORD(v5) = v5->vfptr[109].__vecDelDtor(v5, v6);
  UFG::qString::~qString(&v8);
  v7 = UFG::CopSystem::Instance();
  ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v7->vfptr[88].__vecDelDtor)(v7, i_user_data, (unsigned int)v5);
}

// File Line: 1227
// RVA: 0x4F6D90
void __fastcall UFG::TSGameSlice::Mthd_cops_debug_cap_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // ebx
  UFG::CopSystem *v3; // rax
  UFG::CopSystem *v4; // rax

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) && !i_user_data )
    UFG::CopSystem::Instance()->mStats.mFinishReason = eFinishReason_Script;
  v4 = UFG::CopSystem::Instance();
  v4->vfptr[100].__vecDelDtor(v4, i_user_data);
}

// File Line: 1240
// RVA: 0x4F6F40
void __fastcall UFG::TSGameSlice::Mthd_cops_exclude_player_for_rest_of_chase(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
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
void __fastcall UFG::TSGameSlice::Mthd_cops_escalate_to_minimum_heat_level(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  int i_user_data; // esi
  UFG::CopSystem *v4; // rdi
  __int64 v5; // rax
  unsigned int v6; // ebx
  UFG::CopSystem *v7; // rax
  UFG::CopSystem *v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h] BYREF

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = UFG::CopSystem::Instance();
  UFG::qString::qString(&v9, **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  v6 = (unsigned int)v4->vfptr[109].__vecDelDtor(v4, v5);
  UFG::qString::~qString(&v9);
  v7 = UFG::CopSystem::Instance();
  if ( ((int (__fastcall *)(UFG::CopSystem *))v7->vfptr[89].__vecDelDtor)(v7) < i_user_data )
  {
    v8 = UFG::CopSystem::Instance();
    ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v8->vfptr[88].__vecDelDtor)(
      v8,
      (unsigned int)i_user_data,
      v6);
  }
}

// File Line: 1265
// RVA: 0x4F7000
void __fastcall UFG::TSGameSlice::Mthd_cops_get_ratio_for_current_heat_level(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::CopSystem *v3; // rax
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v3 = UFG::CopSystem::Instance();
    user_data = ((float (__fastcall *)(UFG::CopSystem *))v3->vfptr[90].__vecDelDtor)(v3);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 1274
// RVA: 0x4F6FC0
void __fastcall UFG::TSGameSlice::Mthd_cops_get_heat_level(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CopSystem *v3; // rax
  unsigned int v4; // eax

  if ( ppResult )
  {
    v3 = UFG::CopSystem::Instance();
    v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
  }
}

// File Line: 1283
// RVA: 0x4F6F90
void __fastcall UFG::TSGameSlice::Mthd_cops_get_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CopSystem *v3; // rax
  char v4; // al

  if ( ppResult )
  {
    v3 = UFG::CopSystem::Instance();
    v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[7].__vecDelDtor)(v3);
    *ppResult = SSBoolean::pool_new(v4);
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
  UFG::CopSystem *v3; // rax
  char v4; // al

  if ( ppResult )
  {
    v3 = UFG::CopSystem::Instance();
    v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[8].__vecDelDtor)(v3);
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 1304
// RVA: 0x4DEC80
bool __fastcall UFG::TSGameSlice::Coro_wait_until_cops_heat_level_below(SSInvokedCoroutine *pScope)
{
  int i_user_data; // ebx
  UFG::CopSystem *v3; // rax

  if ( pScope->i_update_count < 0xA )
    return 0;
  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::CopSystem::Instance();
  return ((int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) < i_user_data;
}

// File Line: 1325
// RVA: 0x50F490
void __fastcall UFG::RayCastToTargetAsyncRayCallback(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *simComponent,
        _DWORD *callbackUserData)
{
  SSInvokedContextBase *v3; // rbx
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rax
  unsigned __int64 IsVisible; // r8
  SSData *v7; // rdx
  SSInstance *i_data_p; // rax
  UFG::SimObject *ray_hit_object; // [rsp+40h] [rbp+18h] BYREF

  v3 = *(SSInvokedContextBase **)callbackUserData;
  if ( !*(_QWORD *)callbackUserData || callbackUserData[2] != v3->i_ptr_id )
    v3 = 0i64;
  operator delete[](callbackUserData);
  if ( v3 )
  {
    ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(v3, 1u);
    ray_hit_object = 0i64;
    IsVisible = (unsigned __int8)UFG::TargetIsVisible(
                                   raycastData,
                                   (UFG::SimObjectGame *)ArgByNameOrInstance,
                                   (UFG::VehicleOccupantComponent **)&ray_hit_object);
    v7 = *v3->i_data.i_array_p;
    i_data_p = v7->i_data_p;
    LOBYTE(v7) = 1;
    i_data_p->i_user_data = IsVisible;
    ((void (__fastcall *)(SSInvokedContextBase *, SSData *))v3->vfptr[1].get_topmost_scope)(v3, v7);
  }
}

// File Line: 1350
// RVA: 0x4DA620
char __fastcall UFG::TSGameSlice::Coro_camera_raycast_to_target(SSInvokedCoroutine *pScope)
{
  UFG::SimObjectCVBase *ArgByNameOrInstance; // r14
  Render::DebugDrawContext *Context; // r15
  __int64 v4; // rdx
  bool v5; // di
  bool v6; // bp
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::BaseCameraComponent *p_mCamera; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdi
  bool v13; // al
  UFG::qColour *v15; // r9
  UFG::qVector3 p0; // [rsp+48h] [rbp-40h] BYREF
  UFG::qVector3 raycastPosition; // [rsp+58h] [rbp-30h] BYREF

  ArgByNameOrInstance = (UFG::SimObjectCVBase *)UFG::TSSimObject::GetArgByNameOrInstance(pScope, 1u);
  if ( ArgByNameOrInstance )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64);
    v5 = *(_QWORD *)(v4 + 32) != 0i64;
    v6 = *(_QWORD *)(v4 + 32) || !pScope->i_update_count;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mCamera = (UFG::BaseCameraComponent *)&mCurrentCamera->mCamera;
    else
      p_mCamera = 0i64;
    y = p_mCamera->mCamera.mView.v2.y;
    z = p_mCamera->mCamera.mView.v2.z;
    p0.x = p_mCamera->mCamera.mView.v2.x;
    p0.y = y;
    p0.z = z;
    if ( v6 )
      UFG::ComputeObjectRaycastPosition(ArgByNameOrInstance, &raycastPosition);
    if ( pScope->i_update_count )
    {
      if ( v5 )
      {
        v15 = &UFG::qColour::Green;
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v15 = &UFG::qColour::Red;
        Render::DebugDrawContext::DrawLine(Context, &p0, &raycastPosition, v15, &UFG::qMatrix44::msIdentity, 0i64, 0);
      }
    }
    else
    {
      if ( v5 )
        Render::DebugDrawContext::DrawLine(
          Context,
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
        v11->mNext = (UFG::allocator::free_link *)pScope;
        LODWORD(v11[1].mNext) = pScope->i_ptr_id;
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
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
      if ( v13 )
      {
        ++pScope->i_pending_count;
        return 0;
      }
      operator delete[](v12);
    }
  }
  else
  {
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data = 0i64;
  }
  return 1;
}

// File Line: 1421
// RVA: 0x4D9F70
char __fastcall UFG::TSGameSlice::Coro_async_is_target_occluded(SSInvokedCoroutine *pScope)
{
  unsigned __int64 v2; // rsi
  UFG::SimObjectVehicle *ArgByNameOrInstance; // rbx
  __int64 v4; // rax
  bool v5; // r14
  bool v6; // bp
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  __int16 m_Flags; // cx
  float v12; // xmm6_4
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  __int16 v14; // cx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  double v16; // xmm0_8
  float v17; // xmm6_4
  Render::DebugDrawContext *Context; // rax
  UFG::SimAsyncOcclusionQueryManager *v19; // rax
  UFG::SimAsyncOcclusionQueryManager *v20; // rax
  SSObjectBase *i_obj_p; // rdx
  unsigned int i_update_count; // ecx
  SSObjectBase *v24; // rbx
  UFG::SimAsyncOcclusionQuery *vfptr; // rbx
  SSObjectBase *v26; // rcx
  UFG::SimAsyncOcclusionQueryManager *v27; // rax
  UFG::qVector3 p0; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 raycastPosition; // [rsp+50h] [rbp-28h] BYREF

  v2 = 0i64;
  ArgByNameOrInstance = (UFG::SimObjectVehicle *)UFG::TSSimObject::GetArgByNameOrInstance(pScope, 1u);
  if ( !ArgByNameOrInstance )
    goto LABEL_40;
  v4 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64);
  v5 = *(_QWORD *)(v4 + 32) != 0i64;
  v6 = *(_QWORD *)(v4 + 32) || !pScope->i_update_count;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  y = p_mCamera->mTransformation.v3.y;
  z = p_mCamera->mTransformation.v3.z;
  p0.x = p_mCamera->mTransformation.v3.x;
  p0.y = y;
  p0.z = z;
  if ( v6 )
    UFG::ComputeObjectRaycastPosition(ArgByNameOrInstance, &raycastPosition);
  m_Flags = ArgByNameOrInstance->m_Flags;
  v12 = FLOAT_0_5;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)ArgByNameOrInstance->m_Components.p[44].m_pComponent;
  }
  else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        ArgByNameOrInstance,
                                                        UFG::CharacterOccupantComponent::_TypeUID);
  }
  else
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                        ArgByNameOrInstance,
                                                        UFG::CharacterOccupantComponent::_TypeUID);
  }
  if ( m_pComponent )
    ArgByNameOrInstance = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
  if ( ArgByNameOrInstance )
  {
    v14 = ArgByNameOrInstance->m_Flags;
    if ( (v14 & 0x4000) != 0 )
      goto LABEL_28;
    if ( v14 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(ArgByNameOrInstance);
      goto LABEL_30;
    }
    if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
LABEL_28:
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            ArgByNameOrInstance,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            ArgByNameOrInstance,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
LABEL_30:
    if ( ComponentOfTypeHK )
    {
      v16 = ((double (__fastcall *)(UFG::VehicleSubjectComponent *))ComponentOfTypeHK->vfptr[21].__vecDelDtor)(ComponentOfTypeHK);
      v12 = *(float *)&v16;
    }
  }
  v17 = v12 + 1.0;
  if ( !pScope->i_update_count )
  {
    if ( v5 )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              2u);
      Render::DebugDrawContext::DrawLine(
        Context,
        &p0,
        &raycastPosition,
        &UFG::qColour::Blue,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
    }
    v19 = UFG::SimAsyncOcclusionQueryManager::Get();
    v20 = UFG::SimAsyncOcclusionQueryManager::CreateQuery(v19, &raycastPosition, v17);
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v20;
    return 0;
  }
LABEL_40:
  i_update_count = pScope->i_update_count;
  if ( !i_update_count )
    goto LABEL_50;
  v24 = pScope->i_scope_p.i_obj_p;
  if ( !v24 || pScope->i_scope_p.i_ptr_id != v24->i_ptr_id )
    v24 = 0i64;
  vfptr = (UFG::SimAsyncOcclusionQuery *)v24[2].vfptr;
  if ( !vfptr )
  {
LABEL_50:
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data = 1i64;
    v26 = pScope->i_scope_p.i_obj_p;
    if ( !v26 || pScope->i_scope_p.i_ptr_id != v26->i_ptr_id )
      v26 = 0i64;
    vfptr = (UFG::SimAsyncOcclusionQuery *)v26[2].vfptr;
    if ( !vfptr )
      return 1;
    goto LABEL_54;
  }
  if ( i_update_count <= 0x14 )
  {
    if ( !vfptr->mQueryCompleted )
      return 0;
    goto LABEL_49;
  }
  if ( vfptr->mQueryCompleted )
  {
LABEL_49:
    LOBYTE(v2) = vfptr->mVisibility > 0.0;
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data = v2;
    goto LABEL_54;
  }
  (*pScope->i_data.i_array_p)->i_data_p->i_user_data = 1i64;
LABEL_54:
  v27 = UFG::SimAsyncOcclusionQueryManager::Get();
  UFG::SimAsyncOcclusionQueryManager::ReleaseQuery(v27, vfptr);
  return 1;
}

// File Line: 1521
// RVA: 0x4DB950
char __fastcall UFG::TSGameSlice::Coro_launch_store_front(SSInvokedCoroutine *pScope)
{
  SSActor *v2; // rbx
  SSClass *i_class_p; // rdi
  __int64 v4; // r15
  UFG::StoreFrontTracker *v5; // rax
  SSData **i_array_p; // r8
  UFG::StoreFrontTracker *v7; // rsi
  UFG::qPropertySet *i_user_data; // rbp
  bool v9; // bl
  SSInstance *i_data_p; // r14
  SSInstance *v11; // r12
  UFG::qArray<unsigned long,0> *v12; // rax
  UFG::qSymbol *v13; // rdi
  UFG::qPropertySet *v14; // rdx
  UFG::qPropertySet *v15; // rdi
  UFG::qArray<unsigned long,0> *v16; // rax
  UFG::qArray<unsigned long,0> *v17; // rax
  UFG::qArray<unsigned long,0> *v18; // rax
  unsigned __int64 v19; // rbx
  char *v20; // rbx
  UFG::qArray<unsigned long,0> *v21; // rax
  char *v22; // rbx
  UFG::qArray<unsigned long,0> *v23; // rax
  UFG::qArray<unsigned long,0> *v24; // rax
  UFG::qSymbol *v25; // rax
  hkpCollidable *v26; // rdx
  hkpCollidable *v27; // r8
  hkpCollisionInput *v28; // r9
  hkpNullContactMgr *ContactMgr; // rbx
  UFG::UIScreen *Screen; // rax
  UFG::StoreFrontTracker *v32; // rax
  UFG::qSymbol v; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol v34; // [rsp+68h] [rbp+10h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol v36; // [rsp+78h] [rbp+20h] BYREF

  if ( pScope->i_update_count )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "Wardrobe");
    if ( !Screen || !LOBYTE(Screen[1].vfptr) )
    {
      Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "GarageBrowser");
      if ( !Screen || !LOBYTE(Screen[1].vfptr) )
        return 0;
    }
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, Screen->mScreenUID);
    v32 = UFG::StoreFrontTracker::Instance();
    UFG::StoreFrontTracker::UnloadStoreData(v32);
    return 1;
  }
  v2 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( !v2 )
    goto LABEL_7;
  i_class_p = v2->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    goto LABEL_8;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(v2->i_user_data) != -1 )
    v2 = SSActor::find((ASymbol *)&v2->i_user_data);
  else
LABEL_7:
    v2 = 0i64;
LABEL_8:
  v4 = *(_QWORD *)&v2[1].i_icoroutines_to_update.i_count;
  v5 = UFG::StoreFrontTracker::Instance();
  i_array_p = pScope->i_data.i_array_p;
  v7 = v5;
  i_user_data = (UFG::qPropertySet *)(*i_array_p)->i_data_p->i_user_data;
  v9 = i_array_p[2]->i_data_p->i_user_data != 0;
  v.mUID = i_array_p[3]->i_data_p->i_user_data;
  v34.mUID = i_array_p[4]->i_data_p->i_user_data;
  i_data_p = i_array_p[5]->i_data_p;
  v11 = i_array_p[6]->i_data_p;
  v12 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "InventoryType");
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(i_user_data, v12, DEPTH_RECURSE);
  if ( v.mUID == UFG::gNullQSymbol.mUID && v34.mUID == UFG::gNullQSymbol.mUID )
  {
    UFG::qSymbol::create_from_string(&v36, "Clothing");
    UFG::StoreFrontTracker::LoadStoreData(v7, v13);
    v14 = i_user_data;
  }
  else
  {
    UFG::qSymbol::create_from_string(&result, "store_front_set");
    v15 = UFG::qPropertySet::CreateContainedSet(&result, "temp_store_front");
    UFG::PSWrapper::AppendParentLocal(v15, i_user_data);
    if ( v9 )
    {
      v16 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v36, "HasInventoryUI");
      PropertyUtils::Set<bool>(v15, v16, v9);
    }
    v17 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v36, "StoreType");
    PropertyUtils::Set<UFG::qSymbol>(v15, v17, &v);
    v18 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v36, "StoreId");
    PropertyUtils::Set<UFG::qSymbol>(v15, v18, &v34);
    v19 = i_data_p->i_user_data;
    if ( *(_DWORD *)(v19 + 8) > 1u )
    {
      v20 = *(char **)v19;
      v21 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v36, "StorePreviewMarker");
      UFG::qPropertySet::Set<char const *>(v15, v21, v20);
      v22 = *(char **)v11->i_user_data;
      v23 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v36, "StoreCameraMarker");
      UFG::qPropertySet::Set<char const *>(v15, v23, v22);
    }
    v24 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v36, "InventoryType");
    v25 = UFG::qPropertySet::Get<UFG::qSymbol>(i_user_data, v24, DEPTH_RECURSE);
    UFG::StoreFrontTracker::LoadStoreData(v7, v25);
    v14 = v15;
  }
  UFG::StoreFrontTracker::SetCurrentStore(v7, v14);
  ContactMgr = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v7, v26, v27, v28);
  if ( *(_DWORD *)&ContactMgr[1].m_memSizeAndFlags == 61 )
  {
    UFG::UIHKScreenWardrobe::QueuePush();
  }
  else if ( (unsigned int)(*(_DWORD *)&ContactMgr[1].m_memSizeAndFlags - 62) <= 1 )
  {
    UFG::UIHKScreenGarageBrowser::QueuePush();
    *(_QWORD *)&ContactMgr->m_type = v4;
    return 0;
  }
  *(_QWORD *)&ContactMgr->m_type = v4;
  return 0;
}

// File Line: 1637
// RVA: 0x504A40
void __fastcall UFG::TSGameSlice::Mthd_load_audio_resources(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    UFG::TidoGame::LoadGameSliceAudioResources((UFG::GameSlice *)i_obj_p[8].vfptr);
  else
    UFG::TidoGame::LoadGameSliceAudioResources(MEMORY[0x98]);
}

// File Line: 1647
// RVA: 0x50E2D0
void __fastcall UFG::TSGameSlice::Mthd_unload_audio_resources(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    UFG::TidoGame::UnloadGameSliceAudioResources((UFG::GameSlice *)i_obj_p[8].vfptr);
  else
    UFG::TidoGame::UnloadGameSliceAudioResources(MEMORY[0x98]);
}

// File Line: 1661
// RVA: 0x4F7BD0
void __fastcall UFG::TSGameSlice::Mthd_despawn_npc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *i_data_p; // rbx
  SSActorClass *i_class_p; // rdi
  SSClass *v5; // rcx
  SSClass *i_superclass_p; // rcx
  SSObjectBase *i_obj_p; // rcx
  unsigned int *p_i_ptr_id; // rdi
  __int64 v9; // rcx
  UFG::GameSlice *Parent; // rax

  i_data_p = (UFG::TSCharacter *)(*pScope->i_data.i_array_p)->i_data_p;
  i_class_p = (SSActorClass *)i_data_p->i_class_p;
  if ( UFG::SkookumMgr::mspCharacterClass == i_class_p
    || (v5 = i_class_p->i_superclass_p) != 0i64 && SSClass::is_class(v5, UFG::SkookumMgr::mspCharacterClass) )
  {
    if ( UFG::SkookumMgr::mspPlayerClass == i_class_p )
      return;
    i_superclass_p = i_class_p->i_superclass_p;
    if ( i_superclass_p )
    {
      if ( SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspPlayerClass) )
        return;
    }
  }
  else
  {
    if ( i_class_p != SSBrain::c_symbol_class_p )
      return;
    i_data_p = UFG::TSCharacter::find_instance((UFG::qSymbol *)&i_data_p->i_user_data);
  }
  if ( i_data_p )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v9 = (*(__int64 (__fastcall **)(char *, UFG::TSCharacter *))(*((_QWORD *)p_i_ptr_id + 3) + 120i64))(
           (char *)p_i_ptr_id + 24,
           i_data_p);
    if ( v9
      || (Parent = UFG::GameSlice::GetParent(*((UFG::GameSlice **)p_i_ptr_id + 19))) != 0i64
      && (v9 = ((__int64 (__fastcall *)(SSActor *, UFG::TSCharacter *))Parent->mScript->vfptr[1].get_topmost_scope)(
                 &Parent->mScript->SSActor,
                 i_data_p)) != 0 )
    {
      *(_QWORD *)(v9 + 8) = SSBrain::c_nil_p;
      if ( i_data_p->i_ref_count-- == 1 )
      {
        i_data_p->i_ref_count = 0x80000000;
        i_data_p->vfptr[1].get_scope_context(i_data_p);
      }
    }
    UFG::TSCharacter::Despawn(i_data_p, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 1719
// RVA: 0x15364A0
__int64 UFG::_dynamic_initializer_for__nullSym__()
{
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym, 0xFFFFFFFF);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__nullSym__);
}

// File Line: 1722
// RVA: 0x4E2820
void __fastcall UFG::InteriorTriggerProperties::LoadFromProperties(
        UFG::InteriorTriggerProperties *this,
        UFG::qPropertySet *trigger_prop_set)
{
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
  UFG::InteriorTriggerProperties::tri_state v35; // ecx
  bool *v36; // rax
  UFG::InteriorTriggerProperties::tri_state v37; // ecx
  bool *v38; // rax
  UFG::InteriorTriggerProperties::tri_state v39; // ecx
  bool *v40; // rax
  UFG::InteriorTriggerProperties::tri_state v41; // ecx
  bool *v42; // rax
  UFG::InteriorTriggerProperties::tri_state v43; // ecx
  bool *v44; // rax

  v4 = &nullSym_0;
  if ( (_S12_7 & 1) == 0 )
  {
    _S12_7 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_0, 0xFFFFFFFF);
    atexit(UFG::InteriorTriggerProperties::LoadFromProperties_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  v5 = PropertyUtils::Get<UFG::qSymbol>(
         trigger_prop_set,
         (UFG::qArray<unsigned long,0> *)&qSymbol_TriggerName,
         DEPTH_RECURSE);
  v6 = &nullSym_0;
  if ( v5 )
    v6 = v5;
  this->mTriggerName = (UFG::qSymbol)v6->mUID;
  v7 = PropertyUtils::Get<UFG::qSymbol>(
         trigger_prop_set,
         (UFG::qArray<unsigned long,0> *)&qSymbol_Category,
         DEPTH_RECURSE);
  v8 = &nullSym_0;
  if ( v7 )
    v8 = v7;
  this->mCategory = (UFG::qSymbol)v8->mUID;
  v9 = PropertyUtils::Get<UFG::qSymbol>(
         trigger_prop_set,
         (UFG::qArray<unsigned long,0> *)&qSymbol_Environment,
         DEPTH_RECURSE);
  v10 = &nullSym_0;
  if ( v9 )
    v10 = v9;
  this->mEnvironment = (UFG::qSymbol)v10->mUID;
  v11 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnvironmentApplyAmount,
          DEPTH_RECURSE);
  v12 = FLOAT_3_4028235e38;
  if ( v11 )
    v13 = *v11;
  else
    v13 = FLOAT_3_4028235e38;
  this->mEnvironmentApplyAmount = v13;
  v14 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnvironmentTransition,
          DEPTH_RECURSE);
  if ( v14 )
    v15 = *v14;
  else
    v15 = FLOAT_3_4028235e38;
  this->mEnvironmentTransition = v15;
  v16 = PropertyUtils::Get<UFG::qSymbol>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnterEnvironment,
          DEPTH_RECURSE);
  v17 = &nullSym_0;
  if ( v16 )
    v17 = v16;
  this->mEnterEnvironment = (UFG::qSymbol)v17->mUID;
  v18 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnterEnvironmentApplyAmount,
          DEPTH_RECURSE);
  if ( v18 )
    v19 = *v18;
  else
    v19 = FLOAT_3_4028235e38;
  this->mEnterEnvironmentApplyAmount = v19;
  v20 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnterEnvironmentTransition,
          DEPTH_RECURSE);
  if ( v20 )
    v21 = *v20;
  else
    v21 = FLOAT_3_4028235e38;
  this->mEnterEnvironmentTransition = v21;
  v22 = PropertyUtils::Get<UFG::qSymbol>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_ExitEnvironment,
          DEPTH_RECURSE);
  if ( v22 )
    v4 = v22;
  this->mExitEnvironment = (UFG::qSymbol)v4->mUID;
  v23 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_ExitEnvironmentApplyAmount,
          DEPTH_RECURSE);
  if ( v23 )
    v24 = *v23;
  else
    v24 = FLOAT_3_4028235e38;
  this->mExitEnvironmentApplyAmount = v24;
  v25 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_ExitEnvironmentTransition,
          DEPTH_RECURSE);
  if ( v25 )
    v26 = *v25;
  else
    v26 = FLOAT_3_4028235e38;
  this->mExitEnvironmentTransition = v26;
  v27 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnvironmentTransitionOn,
          DEPTH_RECURSE);
  if ( v27 )
    v28 = *v27;
  else
    v28 = FLOAT_3_4028235e38;
  this->mEnvironmentTransitionOn = v28;
  v29 = PropertyUtils::Get<float>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_EnvironmentTransitionOff,
          DEPTH_RECURSE);
  if ( v29 )
    v12 = *v29;
  this->mEnvironmentTransitionOff = v12;
  v30 = PropertyUtils::Get<UFG::qSymbol>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_PhysicsActiveRegionMode,
          DEPTH_RECURSE);
  if ( v30 )
    this->mPhysicsActiveRegionMode = (UFG::qSymbol)v30->mUID;
  else
    UFG::qSymbol::set_null(&this->mPhysicsActiveRegionMode);
  v31 = PropertyUtils::Get<char const *>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_CameraContextOverrideTow,
          DEPTH_RECURSE);
  UFG::qString::Set(&this->mCameraContextOverrideTow, v31);
  v32 = PropertyUtils::Get<char const *>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_CameraContextLocalOverrideTow,
          DEPTH_RECURSE);
  UFG::qString::Set(&this->mCameraContextLocalOverrideTow, v32);
  v33 = PropertyUtils::Get<bool>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_NestedEnvironment,
          DEPTH_RECURSE);
  v34 = set_false;
  if ( v33 )
    v35 = *v33;
  else
    v35 = set_none;
  this->mNestedEnvironment = v35;
  v36 = PropertyUtils::Get<bool>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_DisableProxyPeds,
          DEPTH_RECURSE);
  if ( v36 )
    v37 = *v36;
  else
    v37 = set_none;
  this->mDisableProxyPeds = v37;
  v38 = PropertyUtils::Get<bool>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_DisableTraffic,
          DEPTH_RECURSE);
  if ( v38 )
    v39 = *v38;
  else
    v39 = set_none;
  this->mDisableTraffic = v39;
  v40 = PropertyUtils::Get<bool>(trigger_prop_set, (UFG::qArray<unsigned long,0> *)&qSymbol_OnEnterOnly, DEPTH_RECURSE);
  if ( v40 )
    v41 = *v40;
  else
    v41 = set_none;
  this->mOnEnterOnly = v41;
  v42 = PropertyUtils::Get<bool>(
          trigger_prop_set,
          (UFG::qArray<unsigned long,0> *)&qSymbol_SpecialTrigger,
          DEPTH_RECURSE);
  if ( v42 )
    v43 = *v42;
  else
    v43 = set_none;
  this->mSpecialTrigger = v43;
  v44 = PropertyUtils::Get<bool>(trigger_prop_set, (UFG::qArray<unsigned long,0> *)&qSymbol_ForceWalk, DEPTH_RECURSE);
  if ( v44 )
  {
    LOBYTE(v34) = *v44;
    this->mForceWalk = v34;
  }
  else
  {
    this->mForceWalk = set_none;
  }
}

// File Line: 1803
// RVA: 0x4E17A0
void __fastcall UFG::TSGameSlice::InteriorExterior_OnEnterHandler(UFG::TriggerRegion *trigger_region)
{
  int v1; // r9d
  unsigned int v2; // eax
  unsigned int mUID; // r8d
  UFG::qSymbol *p_mTriggerName; // rcx
  UFG::InteriorTriggerProperties *v5; // rbx
  SSClass *v6; // rsi
  AObjReusePool<SSInstance> *pool; // rdi
  unsigned int i_count; // eax
  unsigned int v9; // eax
  __int64 v10; // rcx
  SSInstance **i_array_p; // rax
  SSInstance *v12; // rdx
  unsigned int v13; // eax
  SSClass *v14; // rdi
  AObjReusePool<SSInstance> *v15; // rbx
  unsigned int v16; // eax
  unsigned int v17; // eax
  __int64 v18; // rcx
  SSInstance **v19; // rax
  SSInstance *v20; // rdx
  unsigned int v21; // eax
  UFG::TSActor *v22; // r11
  UFG::qBaseNodeRB *SimObject; // rax
  bool v24; // cl
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *p_mNode; // rdi
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v26; // rsi
  UFG::SimObject *v27; // rax
  UFG::CharacterSubjectComponent *ComponentOfType; // rdi
  unsigned int v29; // eax
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v30; // rdi
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v31; // rsi
  UFG::SimObject *v32; // rax
  UFG::CharacterSubjectComponent *v33; // rdi
  unsigned int v34; // eax
  UFG::InteriorTriggerProperties::tri_state mDisableProxyPeds; // eax
  UFG::PedSpawnManager *Instance; // rax
  UFG::PedSpawnManager *v37; // rax
  UFG::qString args_pp; // [rsp+48h] [rbp-28h] BYREF
  __int64 result; // [rsp+A8h] [rbp+38h] BYREF
  __int64 *p_result; // [rsp+B0h] [rbp+40h]

  v1 = 99999;
  v2 = 0;
  if ( UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    mUID = trigger_region->i_name.mUID;
    p_mTriggerName = &UFG::TSGameSlice::msInteriorTriggerData.p->mTriggerName;
    while ( p_mTriggerName->mUID != mUID )
    {
      ++v2;
      p_mTriggerName += 42;
      if ( v2 >= UFG::TSGameSlice::msInteriorTriggerData.size )
        goto LABEL_7;
    }
    v1 = v2;
  }
LABEL_7:
  v5 = &UFG::TSGameSlice::msInteriorTriggerData.p[v1];
  if ( v5->mNestedEnvironment == set_true )
  {
    args_pp.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)SSSymbol::as_instance((ASymbol *)&v5->mEnterEnvironment);
    *(float *)&result = v5->mEnterEnvironmentApplyAmount;
    v6 = SSBrain::c_real_class_p;
    pool = SSInstance::get_pool();
    if ( pool->i_pool.i_count )
    {
      v13 = pool->i_pool.i_count - 1;
      pool->i_pool.i_count = v13;
      v10 = v13;
      i_array_p = pool->i_pool.i_array_p;
    }
    else
    {
      if ( !pool->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
      i_count = pool->i_exp_pool.i_count;
      if ( !i_count )
      {
        v12 = 0i64;
        goto LABEL_16;
      }
      v9 = i_count - 1;
      pool->i_exp_pool.i_count = v9;
      v10 = v9;
      i_array_p = pool->i_exp_pool.i_array_p;
    }
    v12 = i_array_p[v10];
LABEL_16:
    v12->i_class_p = v6;
    v12->i_user_data = (unsigned int)result;
    v12->i_ref_count = 1;
    v12->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
    args_pp.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v12;
    *(float *)&result = v5->mEnterEnvironmentTransition;
    v14 = SSBrain::c_real_class_p;
    v15 = SSInstance::get_pool();
    if ( v15->i_pool.i_count )
    {
      v21 = v15->i_pool.i_count - 1;
      v15->i_pool.i_count = v21;
      v18 = v21;
      v19 = v15->i_pool.i_array_p;
    }
    else
    {
      if ( !v15->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v15, v15->i_expand_size);
      v16 = v15->i_exp_pool.i_count;
      if ( !v16 )
      {
        v20 = 0i64;
        goto LABEL_24;
      }
      v17 = v16 - 1;
      v15->i_exp_pool.i_count = v17;
      v18 = v17;
      v19 = v15->i_exp_pool.i_array_p;
    }
    v20 = v19[v18];
LABEL_24:
    v20->i_class_p = v14;
    v20->i_user_data = (unsigned int)result;
    v20->i_ref_count = 1;
    v20->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
    *(_QWORD *)&args_pp.mMagic = v20;
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        SkookumScript::c_world_p,
        (ASymbol *)&qSymbol__render_override_environment_named,
        (SSInstance **)&args_pp,
        3u,
        1,
        0.0,
        0i64,
        0i64);
    return;
  }
  if ( v5->mForceWalk != set_none )
  {
    v22 = (UFG::TSActor *)SSActor::find((ASymbol *)&qSymbol_PlayerOne_Havok);
    if ( !v22 )
    {
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &qSymbol_PlayerOne_Havok);
      v22 = UFG::TSActor::FromSimObject((UFG::SimObject *)SimObject);
    }
    v24 = v5->mForceWalk == set_true;
    result = 0i64;
    if ( v24 )
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))v22->vfptr[1].set_data_by_name)(
        v22,
        &qSymbol_start_force_walk,
        &result,
        0i64,
        0i64,
        0i64);
    else
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))v22->vfptr[1].set_data_by_name)(
        v22,
        &qSymbol_stop_force_walk,
        &result,
        0i64,
        0i64,
        0i64);
  }
  if ( v5->mCameraContextOverrideTow.mLength )
  {
    UFG::qString::FormatEx(&args_pp, "Cameras-%s", v5->mCameraContextOverrideTow.mData);
    p_mNode = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
    if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
    {
      do
      {
        v26 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&p_mNode[78].mNext[-78];
        if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode) )
        {
          v27 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode);
          ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                v27,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
          if ( ComponentOfType )
          {
            p_result = &result;
            v29 = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, args_pp.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(ComponentOfType, 0, (UFG::qSymbol)v29);
          }
        }
        p_mNode = &v26->mNode;
      }
      while ( v26 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
    }
    UFG::qString::~qString(&args_pp);
  }
  if ( v5->mCameraContextLocalOverrideTow.mLength )
  {
    UFG::qString::FormatEx(&args_pp, "Cameras-%s", v5->mCameraContextLocalOverrideTow.mData);
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
            p_result = &result;
            v34 = (unsigned int)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, args_pp.mData);
            UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v33, 0, (UFG::qSymbol)v34);
          }
        }
        v30 = &v31->mNode;
      }
      while ( v31 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
    }
    UFG::qString::~qString(&args_pp);
  }
  if ( v5->mEnvironment.mUID != nullSym.mUID )
  {
    args_pp.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)SSSymbol::as_instance((ASymbol *)&v5->mEnvironment);
    *(float *)&result = v5->mEnvironmentApplyAmount;
    args_pp.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)SSInstance::pool_new(
                                                               SSBrain::c_real_class_p,
                                                               (unsigned int)result);
    *(float *)&result = v5->mEnvironmentTransitionOn;
    *(_QWORD *)&args_pp.mMagic = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)result);
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        SkookumScript::c_world_p,
        (ASymbol *)&qSymbol__render_override_environment_named,
        (SSInstance **)&args_pp,
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
  mDisableProxyPeds = v5->mDisableProxyPeds;
  if ( mDisableProxyPeds == set_true )
  {
    Instance = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::DisableProxyPeds(Instance);
  }
  else if ( mDisableProxyPeds == set_false )
  {
    v37 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::EnableProxyPeds(v37);
  }
  if ( v5->mDisableTraffic == set_true )
    UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 0);
  if ( v5->mSpecialTrigger != set_true && v5->mEnvironment.mUID == nullSym.mUID )
  {
    UFG::RenderWorld::SetFlags(0);
    UFG::GeographicalLayerManager::SetActiveCategory(&v5->mCategory);
  }
}

// File Line: 1930
// RVA: 0x4E1C80
void __fastcall UFG::TSGameSlice::InteriorExterior_OnExitHandler(UFG::TriggerRegion *trigger_region)
{
  __int64 size; // rsi
  __int64 v2; // rbx
  int v4; // r9d
  unsigned int v5; // eax
  UFG::qSymbol *p_mTriggerName; // rdx
  UFG::InteriorTriggerProperties *v7; // rdi
  SSInstance *v8; // rax
  SSClass *v9; // rbp
  AObjReusePool<SSInstance> *pool; // rsi
  unsigned int i_count; // eax
  unsigned int v12; // eax
  __int64 v13; // rcx
  SSInstance **i_array_p; // rax
  __int64 v15; // rdx
  unsigned int v16; // eax
  __int64 v17; // rax
  SSClass *v18; // rsi
  AObjReusePool<SSInstance> *v19; // rdi
  unsigned int v20; // eax
  unsigned int v21; // eax
  __int64 v22; // rcx
  SSInstance **v23; // rax
  __int64 v24; // rdx
  unsigned int v25; // eax
  __int64 v26; // rax
  UFG::TSActor *v27; // rcx
  UFG::qBaseNodeRB *SimObject; // rax
  bool v29; // zf
  SSInstance *v30; // rax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v32; // rax
  UFG::qBaseNodeRB *p_mNULL; // rax
  int v34; // ecx
  UFG::PedSpawnManager *Instance; // rax
  SSInstance *args_pp; // [rsp+40h] [rbp-38h] BYREF
  __int64 v37; // [rsp+48h] [rbp-30h]
  SSInstance *v38; // [rsp+50h] [rbp-28h]
  unsigned __int64 user_data; // [rsp+88h] [rbp+10h] BYREF

  size = UFG::TSGameSlice::msInteriorTriggerData.size;
  v2 = 0i64;
  v4 = 99999;
  v5 = 0;
  if ( UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    p_mTriggerName = &UFG::TSGameSlice::msInteriorTriggerData.p->mTriggerName;
    while ( p_mTriggerName->mUID != trigger_region->i_name.mUID )
    {
      ++v5;
      p_mTriggerName += 42;
      if ( v5 >= UFG::TSGameSlice::msInteriorTriggerData.size )
        goto LABEL_7;
    }
    v4 = v5;
  }
LABEL_7:
  v7 = &UFG::TSGameSlice::msInteriorTriggerData.p[v4];
  if ( v7->mNestedEnvironment == set_true )
  {
    v8 = SSSymbol::as_instance((ASymbol *)&v7->mExitEnvironment);
    v9 = SSBrain::c_real_class_p;
    *(float *)&user_data = v7->mExitEnvironmentApplyAmount;
    args_pp = v8;
    pool = SSInstance::get_pool();
    if ( pool->i_pool.i_count )
    {
      v16 = pool->i_pool.i_count - 1;
      pool->i_pool.i_count = v16;
      v13 = v16;
      i_array_p = pool->i_pool.i_array_p;
    }
    else
    {
      if ( !pool->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
      i_count = pool->i_exp_pool.i_count;
      if ( !i_count )
      {
        v15 = 0i64;
        goto LABEL_16;
      }
      v12 = i_count - 1;
      pool->i_exp_pool.i_count = v12;
      v13 = v12;
      i_array_p = pool->i_exp_pool.i_array_p;
    }
    v15 = (__int64)i_array_p[v13];
LABEL_16:
    v17 = (unsigned int)user_data;
    *(_QWORD *)(v15 + 24) = v9;
    *(_DWORD *)(v15 + 16) = 1;
    *(_QWORD *)(v15 + 32) = v17;
    *(_DWORD *)(v15 + 8) = ++SSObjectBase::c_ptr_id_prev;
    v18 = SSBrain::c_real_class_p;
    *(float *)&user_data = v7->mExitEnvironmentTransition;
    v37 = v15;
    v19 = SSInstance::get_pool();
    if ( v19->i_pool.i_count )
    {
      v25 = v19->i_pool.i_count - 1;
      v19->i_pool.i_count = v25;
      v22 = v25;
      v23 = v19->i_pool.i_array_p;
    }
    else
    {
      if ( !v19->i_exp_pool.i_count )
        AObjReusePool<SSInstance>::append_block(v19, v19->i_expand_size);
      v20 = v19->i_exp_pool.i_count;
      if ( !v20 )
      {
        v24 = 0i64;
        goto LABEL_24;
      }
      v21 = v20 - 1;
      v19->i_exp_pool.i_count = v21;
      v22 = v21;
      v23 = v19->i_exp_pool.i_array_p;
    }
    v24 = (__int64)v23[v22];
LABEL_24:
    v26 = (unsigned int)user_data;
    *(_QWORD *)(v24 + 24) = v18;
    *(_DWORD *)(v24 + 16) = 1;
    *(_QWORD *)(v24 + 32) = v26;
    *(_DWORD *)(v24 + 8) = ++SSObjectBase::c_ptr_id_prev;
    v38 = (SSInstance *)v24;
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        SkookumScript::c_world_p,
        (ASymbol *)&qSymbol__render_override_environment_named,
        &args_pp,
        3u,
        1,
        0.0,
        0i64,
        0i64);
    return;
  }
  if ( v7->mForceWalk != set_none )
  {
    v27 = (UFG::TSActor *)SSActor::find((ASymbol *)&qSymbol_PlayerOne_Havok);
    if ( !v27 )
    {
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &qSymbol_PlayerOne_Havok);
      v27 = UFG::TSActor::FromSimObject((UFG::SimObject *)SimObject);
    }
    v29 = v7->mForceWalk == set_true;
    user_data = 0i64;
    if ( v29 )
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, unsigned __int64 *, _QWORD, _QWORD, _QWORD))v27->vfptr[1].set_data_by_name)(
        v27,
        &qSymbol_stop_force_walk,
        &user_data,
        0i64,
        0i64,
        0i64);
    else
      ((void (__fastcall *)(UFG::TSActor *, UFG::qStaticSymbol *, unsigned __int64 *, _QWORD, _QWORD, _QWORD))v27->vfptr[1].set_data_by_name)(
        v27,
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
    v30 = SSInstance::pool_new(SSBrain::c_real_class_p, 0i64);
    *(float *)&user_data = v7->mEnvironmentTransitionOff;
    v37 = (__int64)v30;
    v38 = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)user_data);
    if ( SkookumScript::c_world_p )
      SSInstance::coroutine_call(
        SkookumScript::c_world_p,
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
    if ( (_DWORD)size )
    {
      do
      {
        mUID = UFG::TSGameSlice::msInteriorTriggerData.p[v2].mTriggerName.mUID;
        if ( mUID != trigger_region->i_name.mUID )
        {
          if ( mUID )
          {
            v32 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, mUID);
            if ( v32 )
            {
              p_mNULL = &v32[-2].mNULL;
              if ( p_mNULL )
              {
                if ( ((__int64)p_mNULL[6].mParent & 0x10012) == 65554 )
                {
                  v34 = user_data;
                  if ( UFG::TSGameSlice::msInteriorTriggerData.p[v2].mPhysicsActiveRegionMode.mUID != -1 )
                    v34 = UFG::TSGameSlice::msInteriorTriggerData.p[v2].mPhysicsActiveRegionMode.mUID;
                  LODWORD(user_data) = v34;
                }
              }
            }
          }
        }
        ++v2;
        --size;
      }
      while ( size );
    }
    UFG::ActiveRegionManager::SetModeFromSymbol(
      &UFG::BasePhysicsSystem::mInstance->mActiveRegionManager,
      (UFG::qSymbol *)&user_data);
  }
  if ( v7->mDisableTraffic == set_true )
  {
    UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 1);
    UFG::PedSpawnManager::msRequestEmergencyDump = 1;
  }
  if ( v7->mSpecialTrigger != set_true && v7->mEnvironment.mUID == nullSym.mUID )
  {
    UFG::RenderWorld::SetFlags(1u);
    UFG::GeographicalLayerManager::SetActiveCategory(&v7->mCategory);
    Instance = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::EnableProxyPeds(Instance);
    UFG::GeographicalLayerManager::SetActiveCategory(&nullSym);
  }
}

// File Line: 2055
// RVA: 0x510140
void __fastcall UFG::TSGameSlice::SetupTriggersFromList(
        UFG::qPropertyList *pTriggerDataList,
        UFG::GameSlice *pGameSlice)
{
  unsigned int mNumElements; // r12d
  UFG::GameSlice *v3; // rsi
  unsigned int i; // r15d
  char *ValuePtr; // rax
  UFG::qPropertySet *v7; // rdi
  unsigned int v8; // ebx
  unsigned int v9; // edx
  __int64 v10; // r14
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::TriggerRegion *p_mNULL; // rdi
  UFG::SimObjectCharacter *v14; // rbp
  UFG::TriggerTarget *j; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mPrev; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mNext; // rax
  void (__fastcall *v18)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  void (__fastcall *v19)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax

  mNumElements = pTriggerDataList->mNumElements;
  v3 = pGameSlice;
  for ( i = 0; i < mNumElements; ++i )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(pTriggerDataList, 0x1Au, i);
    if ( !ValuePtr || (v7 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
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
    mUID = UFG::TSGameSlice::msInteriorTriggerData.p[v10].mTriggerName.mUID;
    if ( !mUID
      || (v12 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, mUID),
          p_mNULL = (UFG::TriggerRegion *)&v12[-2].mNULL,
          !v12) )
    {
      p_mNULL = 0i64;
    }
    v14 = LocalPlayer;
    if ( p_mNULL )
    {
      for ( j = (UFG::TriggerTarget *)p_mNULL->mTrackList.mNode.mNext;
            j != (UFG::TriggerTarget *)&p_mNULL->mTrackList;
            j = (UFG::TriggerTarget *)p_mNULL->mTrackList.mNode.mNext )
      {
        mPrev = j->mPrev;
        mNext = j->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        j->mPrev = j;
        j->mNext = j;
        UFG::TriggerTarget::~TriggerTarget(j);
        operator delete[](j);
      }
      UFG::TriggerRegion::ResetEvents(p_mNULL);
      UFG::TriggerRegion::TrackTarget(p_mNULL, v14, 0i64);
      v18 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
      p_mNULL->mOnEnteredDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TSGameSlice::InteriorExterior_OnEnterHandler;
      if ( !UFG::TSGameSlice::InteriorExterior_OnEnterHandler )
        v18 = 0i64;
      p_mNULL->mOnEnteredDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v18;
      if ( UFG::TSGameSlice::msInteriorTriggerData.p[v10].mOnEnterOnly != set_true )
      {
        v19 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
        p_mNULL->mOnExitedDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TSGameSlice::InteriorExterior_OnExitHandler;
        if ( !UFG::TSGameSlice::InteriorExterior_OnExitHandler )
          v19 = 0i64;
        p_mNULL->mOnExitedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v19;
      }
      UFG::TriggerRegion::EnableHot(p_mNULL, 1);
      v3 = pGameSlice;
    }
  }
}  }
      UFG::TriggerRegion::EnableHot(p_mNULL, 1);
      v3 = pGameSlice;
    }
  }


// File Line: 2097
// RVA: 0x506B70
void __fastcall UFG::TSGameSlice::Mthd_send_collectible_telemetry_stat(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  int i_user_data; // ebx
  int v4; // edi
  int v5; // r14d
  UFG::GameStatTracker *v6; // rax
  UFG::GameStat::Int32Stat v7; // edx
  int Stat; // r15d
  UFG::OSuiteDBLogger *v9; // rbp
  unsigned __int64 v10; // rsi
  UFG::OnlineManager *v11; // rax
  __int64 SystemTimeUTC; // rbx
  __int64 mSimTimeMSec; // rbx
  char dest[128]; // [rsp+20h] [rbp-98h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data;
  if ( i_array_p[2]->i_data_p->i_user_data )
  {
    v5 = -1923866446;
    v6 = UFG::GameStatTracker::Instance();
    v7 = StatueOffensiveStage;
  }
  else
  {
    v5 = -46881340;
    v6 = UFG::GameStatTracker::Instance();
    v7 = StatueDefensiveStage;
  }
  Stat = UFG::GameStatTracker::GetStat(v6, v7);
  v9 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v9, "StatueUpgrade") )
  {
    v10 = UFG::Metrics::msRealTimeMSec;
    UFG::qSPrintf(dest, 128, "i64_%s", "CollectibleId");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, v10);
    v11 = UFG::OnlineManager::Instance();
    LODWORD(v10) = UFG::OnlineManager::GetOnlineIdStringHash32(v11);
    UFG::qSPrintf(dest, 128, "i32_%s", "PlayerId");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, v10);
    UFG::qSPrintf(dest, 128, "i32_%s", "EventType");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, v5);
    UFG::qSPrintf(dest, 128, "i32_%s", "CollectibleType");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, i_user_data);
    UFG::qSPrintf(dest, 128, "i32_%s", "CollectibleName");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, v4);
    UFG::qSPrintf(dest, 128, "i32_%s", "NewStage");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, Stat);
    SystemTimeUTC = UFG::qGetSystemTimeUTC();
    UFG::qSPrintf(dest, 128, "i64_%s", "Timestamp");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, SystemTimeUTC);
    mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
    UFG::qSPrintf(dest, 128, "i64_%s", "SimTime");
    OSuite::ZMetric::SetProperty(v9->m_pMetric, dest, mSimTimeMSec);
    UFG::OSuiteDBLogger::SubmitMetric(v9, 1);
  }
}

// File Line: 2129
// RVA: 0x5063D0
void __fastcall UFG::TSGameSlice::Mthd_release_interior_triggers(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i; // ebp
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::TriggerRegion *p_mNULL; // rdi
  UFG::TriggerTarget *j; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mPrev; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mNext; // rax
  UFG::InteriorTriggerProperties::tri_state *p_mOnEnterOnly; // rbx

  for ( i = 0; i < UFG::TSGameSlice::msInteriorTriggerData.size; ++i )
  {
    mUID = UFG::TSGameSlice::msInteriorTriggerData.p[i].mTriggerName.mUID;
    if ( mUID )
    {
      v4 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, mUID);
      if ( v4 )
      {
        p_mNULL = (UFG::TriggerRegion *)&v4[-2].mNULL;
        if ( v4 != (UFG::qBaseTreeRB *)112 )
        {
          if ( (p_mNULL->mModeFlags & 0x10012) == 65554 )
            ((void (__fastcall *)(UFG::TriggerRegion *))p_mNULL->vfptr[19].__vecDelDtor)(p_mNULL);
          for ( j = (UFG::TriggerTarget *)p_mNULL->mTrackList.mNode.mNext;
                j != (UFG::TriggerTarget *)&p_mNULL->mTrackList;
                j = (UFG::TriggerTarget *)p_mNULL->mTrackList.mNode.mNext )
          {
            mPrev = j->mPrev;
            mNext = j->mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            j->mPrev = j;
            j->mNext = j;
            UFG::TriggerTarget::~TriggerTarget(j);
            operator delete[](j);
          }
          UFG::TriggerRegion::ResetEvents(p_mNULL);
          UFG::TriggerRegion::EnableHot(p_mNULL, 0);
        }
      }
    }
  }
  if ( UFG::TSGameSlice::msInteriorTriggerData.p )
  {
    p_mOnEnterOnly = &UFG::TSGameSlice::msInteriorTriggerData.p[-1].mOnEnterOnly;
    `eh vector destructor iterator(
      UFG::TSGameSlice::msInteriorTriggerData.p,
      0xA8ui64,
      UFG::TSGameSlice::msInteriorTriggerData.p[-1].mOnEnterOnly,
      (void (__fastcall *)(void *))UFG::InteriorTriggerProperties::~InteriorTriggerProperties);
    operator delete[](p_mOnEnterOnly);
  }
  UFG::TSGameSlice::msInteriorTriggerData.p = 0i64;
  *(_QWORD *)&UFG::TSGameSlice::msInteriorTriggerData.size = 0i64;
}

// File Line: 2161
// RVA: 0x50B590
void __fastcall UFG::TSGameSlice::Mthd_setup_interior_triggers(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  UFG::GameSlice *v4; // rsi
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qSymbol *v7; // rax
  UFG::qPropertySet *v8; // rbx
  UFG::qPropertyList *v9; // rdi
  UFG::qPropertyList *v10; // rbx
  unsigned int v11; // edx
  UFG::qArray<unsigned long,0> result; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol v13; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol v14; // [rsp+58h] [rbp+20h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    p_i_ptr_id = &i_obj_p[-2].i_ptr_id;
  else
    p_i_ptr_id = 0i64;
  v4 = (UFG::GameSlice *)*((_QWORD *)p_i_ptr_id + 19);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "List");
  v5 = UFG::qSymbol::create_from_string(&v13, "default-interiors-list");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v5);
  v7 = UFG::qSymbol::create_from_string(&v14, "default-interiors-lighting");
  v8 = UFG::PropertySetManager::GetPropertySet(v7);
  v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &result, DEPTH_RECURSE);
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
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::qPropertyList *v4; // rdi
  UFG::qPropertyList *v5; // rbx
  unsigned int v6; // edx
  UFG::qArray<unsigned long,0> result; // [rsp+30h] [rbp+8h] BYREF
  UFG::qSymbol v8; // [rsp+40h] [rbp+18h] BYREF

  if ( !UFG::TSGameSlice::msInteriorTriggerData.size )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "List");
    v0 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result.p, "default-interiors-list");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v0);
    v2 = UFG::qSymbol::create_from_string(&v8, "default-interiors-lighting");
    v3 = UFG::PropertySetManager::GetPropertySet(v2);
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &result, DEPTH_RECURSE);
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

