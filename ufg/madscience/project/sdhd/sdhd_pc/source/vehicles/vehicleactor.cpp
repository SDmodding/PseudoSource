// File Line: 84
// RVA: 0x6431C0
void __fastcall UFG::TSVehicle::TSVehicle(UFG::TSVehicle *this, ASymbol *name)
{
  UFG::TSActor::TSActor(this, name, UFG::TSVehicle::mClass);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSVehicle::`vftable;
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::RebindingComponentHandle<UFG::AiDriverComponent,0>(&this->mAIDriverComponent);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&this->mMoverComponent);
  this->bDelayedByNoDriver = 0;
}

// File Line: 96
// RVA: 0x64F350
UFG::qBaseNodeRB *__fastcall UFG::TSVehicle::GetSafeSimObjectVehicle(UFG::TSVehicle *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->mpComponent;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 101
// RVA: 0x645840
void UFG::TSVehicle::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-20h]
  ASymbol rebinda; // [rsp+20h] [rbp-20h]
  ASymbol rebindb; // [rsp+20h] [rbp-20h]
  ASymbol rebindc; // [rsp+20h] [rbp-20h]
  ASymbol rebindd; // [rsp+20h] [rbp-20h]
  ASymbol rebinde; // [rsp+20h] [rbp-20h]
  ASymbol rebindf; // [rsp+20h] [rbp-20h]
  ASymbol rebindg; // [rsp+20h] [rbp-20h]
  ASymbol rebindh; // [rsp+20h] [rbp-20h]
  char (__fastcall *v9)(UFG::TSActor *, SSInvokedCoroutine *); // [rsp+30h] [rbp-10h] BYREF
  int v10; // [rsp+38h] [rbp-8h]

  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_mission_fail_condition_commit_changes;
  v10 = 0;
  UFG::TSVehicle::mClass = (SSActorClass *)SSBrain::get_class("Vehicle");
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "mission_fail_condition_commit_changes",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_despawn;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "despawn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_has_fail_conditions;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "has_fail_conditions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_enable_door_lock;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_door_lock",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_mass_scale_for_collisions;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_mass_scaling_for_collisions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_clear_mass_scale_for_collisions;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_mass_scaling_for_collisions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_roll_stability;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_roll_stability",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_stop;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_chase;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "chase",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_wander;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "wander",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_follow;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "follow",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_escort;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "escort",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_clear_driver;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_create_ai_driver;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "create_ai_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_create_human_driver;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "create_human_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_slow_down_for_race_curvature;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_slow_down_for_race_curvature",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_avoid_objects_enabled;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_avoid_objects_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_avoid_geo_enabled;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_avoid_geo_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_road_speed_limit_scale;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_road_speed_limit_scale",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_desired_speed_limit_kph;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_desired_speed_limit_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_chase_speed_limit_kph;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_chase_speed_limit_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_override_speed_kph;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "override_speed_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_driving_role;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_driving_role",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_can_shove_cargo;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_can_shove_cargo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))_;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "create_sensor_phantom",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_race;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_race",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_steer_race;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "steer_race",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_start_racing;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "start_racing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_race_speed_limit;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_race_speed_limit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_race_index;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_race_index",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_race_point_index;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_race_point_index",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_race_time;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_race_time",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_catchup_target;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_katchup_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_clear_catchup_target;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_katchup_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_force_dock;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_force_dock",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_countdown_time;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_countdown_time",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_countdown_time;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_countdown_time",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_fraction_race_complete;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_fraction_race_complete",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_race_proximity;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_race_proximity",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Coro_path_to_xform;
  SSClass::register_coroutine_mthd(
    UFG::TSVehicle::mClass,
    "_path_to_xform",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Coro_stop_at;
  v10 = 0;
  SSClass::register_coroutine_mthd(
    UFG::TSVehicle::mClass,
    "_stop_at",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_take_camera;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "take_camera",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_follow_offset;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "follow_offset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_follow_debug;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "follow_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_avoidance_debug;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "avoidance_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_break_on_update;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "break_on_update",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_average_damage_rig_health;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_average_damage_rig_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_health_damage_rig;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_health_damage_rig",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_tire_damage;
  v10 = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_tire_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_engine_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_engine_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_engine_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_engine_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_tire_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_tire_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_repair_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "repair_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))_;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_highlight_tire",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_matching_class_type;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_of_class",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_driver;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_num_wheels;
  v10 = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_num_wheels",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_num_wheels_off_ground;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_num_wheels_off_ground",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_upright;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_upright",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_flip;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "flip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_in_deep_water;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_in_deep_water",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_boat_in_water;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_boat_in_water",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_trail_xform;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_trail_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_total_distance_driven_km;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_total_distance_driven_km",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_road_speed_limit_kph;
  v10 = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_road_speed_limit_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_passenger;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_passenger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_driver;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_type;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_speed;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_speed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_linear_velocity_magnitude;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_linear_velocity_magnitude",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_multiplier;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_multiplier",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_multiplier;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_multiplier_world_coll",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_multiplier_vehicle_coll;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_multiplier_vehicle_coll",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_multiplier_bullets;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_multiplier_bullets",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_multiplier_attack;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_multiplier_attack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_multiplier_tires;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_multiplier_tires",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_disable_flapping_attachments;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "disable_flapping_attachments",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_grime_value;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_grime_value",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_take_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_vehicle_collision_min_impulse_required_to_take_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_min_impulse;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_vehicle_collision_damage_dealt_at_min_impulse",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_max_impulse;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_vehicle_collision_damage_dealt_at_max_impulse",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_deal_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_vehicle_collision_min_impulse_required_to_deal_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_vehicle_collision_max_impulse_for_dealing_damage;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_vehicle_collision_max_impulse_for_dealing_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_vehicle_collision_force_damage_dealer;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_vehicle_collision_force_damage_dealer",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_enable_horn;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_horn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_enable_siren;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_siren",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_enable_cop_lights;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_cop_lights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_enable_head_lights;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_head_lights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_queue_head_light_flashes;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "queue_head_light_flashes",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_start_radio;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "start_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_stop_radio;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "stop_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_radio_station;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_radio_station",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_radio_station;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_radio_station",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_set_radio_is_enabled;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_radio_is_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_set_shutdown_on_exit;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_shutdown_on_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_clear_playlist;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_clear_recently_played;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_recently_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_add_asset_to_playlist;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "add_asset_to_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_randomize_player_playlist;
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "randomize_player_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_randomize_playlist;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "randomize_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_start_player_radio;
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "start_player_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebinda);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_stop_player_radio;
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "stop_player_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebindb);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_set_player_radio_station;
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_player_radio_station",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebindc);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_clear_player_playlist;
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_player_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebindd);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_clear_player_recently_played;
  v10 = 0;
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "clear_player_recently_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebinde);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_add_asset_to_player_playlist;
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "add_asset_to_player_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebindf);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_player_radio_next_track;
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "player_radio_next_track",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebindg);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_avoid_peds;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_avoid_peds",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_allowed_to_pass;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_allowed_to_pass",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_stay_off_sidewalk;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_stay_off_sidewalk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_respect_speed_limit;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_respect_speed_limit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_obey_traffic_lights;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_obey_traffic_lights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_can_turn_around;
  v10 = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_can_turn_around",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_init_audio;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "init_audio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_enable_player_control;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_player_control",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_number_seats;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_number_seats",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_number_occupants;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_number_occupants",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_reload_physics_property_set;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "reload_physics",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_matching_class_type;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_matching_class_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_reset_to_last_good;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "reset_to_last_good",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_cannot_explode;
  v10 = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_cannotexplode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_trigger_explosion;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "trigger_explosion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_damage_marker;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_damage_marker",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_all_damage_markers;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_all_damage_markers",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_get_vandalized_amount;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_vandalized_amount",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_usable_by_cop_system;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_usable_by_cop_system",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_attacked_via_formation;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_attacked_via_formation",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_formation_slot_availability;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_formation_slot_availability",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_parked;
  v10 = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_parked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_parked;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_parked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_occupying_selected_stop;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_occupying_selected_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_is_vehicle_in_opposite_lane;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "is_vehicle_in_opposite_lane",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_prevent_hijack;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_prevent_hijack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_audio_driver_type;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_audio_driver_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))_;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "enable_triggering_boost_regions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_add_steering_noise;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "add_steering_noise",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_attach_vehicle_across_street;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "attach_vehicle_across_street",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::MthdC_get_instances_of_type;
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "get_instances_of_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    1,
    rebindh);
  v10 = 0;
  v9 = (char (__fastcall *)(UFG::TSActor *, SSInvokedCoroutine *))UFG::TSVehicle::Mthd_set_untargetable;
  SSClass::register_method_mthd(
    UFG::TSVehicle::mClass,
    "set_untargetable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v9,
    SSBindFlag_instance_no_rebind);
  v10 = 0;
  v9 = UFG::TSActor::Coro_raycast_to_target;
  SSClass::register_coroutine_mthd(
    UFG::TSVehicle::mClass,
    "_raycast_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v9,
    SSBindFlag_instance_no_rebind);
}

// File Line: 276
// RVA: 0x656020
void __fastcall UFG::TSVehicle::Mthd_set_untargetable(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    BYTE1(m_pSimComponent[14].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 290
// RVA: 0x6534D0
void __fastcall UFG::TSVehicle::Mthd_cannot_explode(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::PhysicsMoverInterface::SetCannotExplode(
      m_pSimComponent,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 304
// RVA: 0x656500
void __fastcall UFG::TSVehicle::Mthd_trigger_explosion(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::PhysicsMoverInterface::TriggerExplosion(m_pSimComponent);
}

// File Line: 317
// RVA: 0x655100
void __fastcall UFG::TSVehicle::Mthd_set_all_damage_markers(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rdx
  DamageRig *mDamageRig; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
    if ( m_pComponent )
    {
      mDamageRig = m_pComponent->mDamageRig;
      if ( mDamageRig )
        DamageRig::SetAllDamageMarkers(
          mDamageRig,
          m_pComponent,
          *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64);
    }
  }
}

// File Line: 336
// RVA: 0x652A10
void __fastcall UFG::TSVehicle::MthdC_get_instances_of_type(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSList *v4; // rsi
  UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *i; // rbx
  UFG::SimObject *mNext; // rdi
  UFG::TSActorComponent *m_pComponent; // rcx
  UFG::TSActor *Actor; // rax
  UFG::qSymbol targetClassType; // [rsp+60h] [rbp+18h] BYREF
  SSList *v10; // [rsp+68h] [rbp+20h]

  if ( ppResult )
  {
    targetClassType.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v10 = v4;
    if ( v4 )
    {
      v4->i_items.i_count = 0;
      v4->i_items.i_array_p = 0i64;
      v4->i_items.i_size = 0;
      v4->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v4 = 0i64;
    }
    for ( i = (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext;
          i != (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152);
          i = (UFG::qList<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent,1,0> *)&i[10].mNode.mPrev[-10].mNext )
    {
      mNext = (UFG::SimObject *)i[2].mNode.mNext;
      if ( UFG::SimObjectUtility::IsClassType(mNext, &targetClassType) )
      {
        if ( mNext )
        {
          m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[4].m_pComponent;
          if ( m_pComponent )
          {
            Actor = UFG::TSActorComponent::GetActor(m_pComponent);
            if ( Actor )
              SSList::append(v4, Actor, 1);
          }
        }
      }
    }
    *ppResult = SSList::as_instance(v4);
  }
}

// File Line: 373
// RVA: 0x653D90
void __fastcall UFG::TSVehicle::Mthd_flip(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r9
  SSData **i_array_p; // r8
  UFG::PhysicsWheeledVehicle *v6; // rcx
  SSInstance *i_data_p; // rdx
  SSData *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  float v10; // xmm6_4
  UFG::PhysicsMoverInterface *v11; // rcx
  UFG::qVector3 collisionPoint; // [rsp+20h] [rbp-68h] BYREF
  UFG::qMatrix44 mat; // [rsp+30h] [rbp-58h] BYREF

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    i_array_p = pScope->i_data.i_array_p;
    v6 = 0i64;
    i_data_p = (*i_array_p)->i_data_p;
    v8 = i_array_p[1];
    mPrev = m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    v10 = *(float *)&v8->i_data_p->i_user_data;
    if ( mPrev )
    {
      if ( (BYTE4(mPrev[37].mNext) & 7) == 4 )
        v6 = (UFG::PhysicsWheeledVehicle *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    }
    UFG::PhysicsWheeledVehicle::GetWheelMatrix(v6, i_data_p->i_user_data, &mat);
    v11 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    collisionPoint.x = mat.v3.x;
    collisionPoint.y = mat.v3.y;
    collisionPoint.z = mat.v3.z;
    UFG::PhysicsMoverInterface::FlipVehicle(v11, v10, &collisionPoint);
  }
}

// File Line: 394
// RVA: 0x6557D0
void __fastcall UFG::TSVehicle::Mthd_set_damage_marker(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rbp
  DamageRig *mDamageRig; // r14
  AStringRef *i_user_data; // rbx
  SSData **i_array_p; // r8
  float v8; // xmm6_4
  bool suppress_effects; // si
  bool affect_triggers; // di
  unsigned int v11; // eax
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
    if ( m_pComponent )
    {
      mDamageRig = m_pComponent->mDamageRig;
      if ( mDamageRig )
      {
        i_user_data = (AStringRef *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
        ++i_user_data->i_ref_count;
        i_array_p = pScope->i_data.i_array_p;
        v8 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
        suppress_effects = i_array_p[2]->i_data_p->i_user_data != 0;
        affect_triggers = i_array_p[3]->i_data_p->i_user_data != 0;
        v11 = UFG::qStringHashUpper32(i_user_data->i_cstr_p, -1);
        DamageRig::SetDamageMarker(mDamageRig, m_pComponent, v11, v8, affect_triggers, suppress_effects);
        if ( i_user_data->i_ref_count-- == 1 )
        {
          if ( i_user_data->i_deallocate )
            AMemory::c_free_func(i_user_data->i_cstr_p);
          pool = AStringRef::get_pool();
          i_block_p = pool->i_block_p;
          i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
          if ( (unsigned __int64)i_user_data < i_objects_a
            || (v16 = (unsigned __int64)i_user_data < i_objects_a + 24i64 * i_block_p->i_size,
                p_i_exp_pool = &pool->i_pool,
                !v16) )
          {
            p_i_exp_pool = &pool->i_exp_pool;
          }
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_user_data);
        }
      }
    }
  }
}

// File Line: 419
// RVA: 0x654A60
void __fastcall UFG::TSVehicle::Mthd_get_vandalized_amount(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && ppResult )
  {
    m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
    if ( m_pComponent )
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)&m_pComponent[28].m_Flags);
  }
}

// File Line: 437
// RVA: 0x654F70
void __fastcall UFG::TSVehicle::Mthd_reload_physics_property_set(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  unsigned int i_user_data; // eax
  UFG::qSymbol propertySetName; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_propertySetName; // [rsp+48h] [rbp+10h]

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( this->mMoverComponent.m_pSimComponent )
  {
    p_propertySetName = &propertySetName;
    propertySetName.mUID = i_user_data;
    UFG::PhysicsMoverInterface::Reload(
      (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent,
      RELOAD_NAMED,
      (__int64)&propertySetName);
  }
}

// File Line: 447
// RVA: 0x654CF0
void __fastcall UFG::TSVehicle::Mthd_is_matching_class_type(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  char IsClassType; // al

  if ( ppResult )
  {
    IsClassType = UFG::SimObjectUtility::IsClassType(
                    this->mpSimObj.m_pPointer,
                    (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *ppResult = SSBoolean::pool_new(IsClassType);
  }
}

// File Line: 457
// RVA: 0x654FE0
void __fastcall UFG::TSVehicle::Mthd_reset_to_last_good(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  UFG::qMatrix44 v19; // [rsp+20h] [rbp-48h] BYREF

  if ( this->mMoverComponent.m_pSimComponent )
  {
    mPrev = this->mMoverComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v4 = *((float *)&mPrev[12].mPrev + 1);
      v19.v0.x = *(float *)&mPrev[12].mPrev;
      v5 = *(float *)&mPrev[12].mNext;
      v19.v0.y = v4;
      v6 = *((float *)&mPrev[12].mNext + 1);
      v19.v0.z = v5;
      v7 = *(float *)&mPrev[13].mPrev;
      v19.v0.w = v6;
      v8 = *((float *)&mPrev[13].mPrev + 1);
      v19.v1.x = v7;
      v9 = *(float *)&mPrev[13].mNext;
      v19.v1.y = v8;
      v10 = *((float *)&mPrev[13].mNext + 1);
      v19.v1.z = v9;
      v11 = *(float *)&mPrev[14].mPrev;
      v19.v1.w = v10;
      v12 = *((float *)&mPrev[14].mPrev + 1);
      v19.v2.x = v11;
      v13 = *(float *)&mPrev[14].mNext;
      v19.v2.y = v12;
      v14 = *((float *)&mPrev[14].mNext + 1);
      v19.v2.z = v13;
      v15 = *(float *)&mPrev[15].mPrev;
      v19.v2.w = v14;
      v16 = *((float *)&mPrev[15].mPrev + 1);
      v19.v3.x = v15;
      v17 = *(float *)&mPrev[15].mNext;
      v19.v3.y = v16;
      v18 = *((float *)&mPrev[15].mNext + 1);
      v19.v3.z = v17;
      v19.v3.w = v18;
      UFG::TSActor::TeleportToTransform(this, &v19);
    }
  }
}

// File Line: 474
// RVA: 0x653A60
void __fastcall UFG::TSVehicle::Mthd_enable_player_control(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleDriverInterface *m_pComponent; // rbx
  SSData **i_array_p; // r8
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx
  UFG::PhysicsMoverInterface *v8; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
    m_pComponent = (UFG::VehicleDriverInterface *)m_pPointer->m_Components.p[23].m_pComponent;
  else
    m_pComponent = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  if ( (*i_array_p)->i_data_p->i_user_data )
  {
    if ( m_pComponent )
      UFG::VehicleDriverInterface::SetDesiredState(m_pComponent, (UFG::VehicleState)2);
  }
  else
  {
    if ( i_array_p[1]->i_data_p->i_user_data )
    {
      m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
      if ( m_pSimComponent )
        UFG::PhysicsMoverInterface::OverrideSuperStopDrag(
          m_pSimComponent,
          1,
          *(float *)&i_array_p[2]->i_data_p->i_user_data);
    }
    v8 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    if ( v8 )
      UFG::PhysicsMoverInterface::EnableSuperStop(v8);
    if ( m_pComponent )
      UFG::VehicleDriverInterface::SetDesiredState(m_pComponent, (UFG::VehicleState)4);
  }
}

// File Line: 509
// RVA: 0x654EB0
void __fastcall UFG::TSVehicle::Mthd_mission_fail_condition_commit_changes(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rcx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
    i_data_p = (SSInstance *)((char *)i_data_p - 24);
  UFG::MissionFailConditionComponent::HandleAttachment(
    *(UFG::GameSlice **)&i_data_p[3].i_ptr_id,
    this->mpSimObj.m_pPointer,
    0i64);
}

// File Line: 515
// RVA: 0x654AB0
void __fastcall UFG::TSVehicle::Mthd_has_fail_conditions(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (UFG::SimObject *)m_pPointer->m_Components.p[8].m_pComponent;
    *ppResult = SSBoolean::pool_new(m_pPointer != 0i64);
  }
}

// File Line: 524
// RVA: 0x653820
void __fastcall UFG::TSVehicle::Mthd_despawn(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( !(*pScope->i_data.i_array_p)->i_data_p->i_user_data
      || ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                                    m_pPointer,
                                                                    UFG::StreamedResourceComponent::_TypeUID))
           : (ComponentOfType = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    m_pPointer,
                                                                    UFG::StreamedResourceComponent::_TypeUID)))
          : (ComponentOfType = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[7].m_pComponent))
         : (ComponentOfType = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent))
        : (ComponentOfType = (UFG::StreamedResourceComponent *)m_pPointer->m_Components.p[10].m_pComponent),
          UFG::StreamedResourceComponent::GetSpawnPriority(ComponentOfType, 0i64)->mUID != qSymbol_Critical.mUID) )
    {
      UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
    }
  }
}

// File Line: 556
// RVA: 0x653950
void __fastcall UFG::TSVehicle::Mthd_enable_door_lock(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  LOBYTE(this->mMoverComponent.m_pSimComponent[14].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 567
// RVA: 0x654500
void __fastcall UFG::TSVehicle::Mthd_get_number_seats(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleOccupantComponent *m_pComponent; // rcx
  unsigned __int64 NumberOfSeats; // rdx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent) != 0i64 )
    {
      NumberOfSeats = (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfSeats(m_pComponent);
    }
    else
    {
      NumberOfSeats = 0i64;
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, NumberOfSeats);
  }
}

// File Line: 589
// RVA: 0x6544B0
void __fastcall UFG::TSVehicle::Mthd_get_number_occupants(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleOccupantComponent *m_pComponent; // rcx
  unsigned int NumberOfOccupants; // eax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
      m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent;
    else
      m_pComponent = 0i64;
    NumberOfOccupants = UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, NumberOfOccupants);
  }
}

// File Line: 604
// RVA: 0x6541B0
void __fastcall UFG::TSVehicle::Mthd_get_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  hkSimpleLocalFrame *m_pComponent; // rcx
  UFG::SimObject *Texture; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer && (m_pComponent = (hkSimpleLocalFrame *)m_pPointer->m_Components.p[30].m_pComponent) != 0i64 )
    {
      Texture = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent);
      *ppResult = UFG::TSActor::SkookumObjFromSimObj(Texture);
    }
    else
    {
      *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    }
  }
}

// File Line: 623
// RVA: 0x654550
void __fastcall UFG::TSVehicle::Mthd_get_passenger(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleOccupantComponent *m_pComponent; // rcx
  UFG::SimObject *Passenger; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent) != 0i64 )
    {
      Passenger = UFG::VehicleOccupantComponent::GetPassenger(
                    m_pComponent,
                    (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                    1);
      *ppResult = UFG::TSActor::SkookumObjFromSimObj(Passenger);
    }
    else
    {
      *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    }
  }
}

// File Line: 636
// RVA: 0x6547B0
void __fastcall UFG::TSVehicle::Mthd_get_road_speed_limit_kph(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  float v6; // xmm0_4

  if ( ppResult )
  {
    m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      v4 = *(_QWORD *)&m_pSimComponent[5].m_TypeUID;
      if ( v4 && (v5 = v4 + 376) != 0 && *(_BYTE *)(v5 + 168) )
        v6 = *(float *)(v5 + 108);
      else
        v6 = FLOAT_N1_0;
      *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, COERCE_UNSIGNED_INT(v6 * 3.5999999));
    }
  }
}

// File Line: 648
// RVA: 0x6548B0
void __fastcall UFG::TSVehicle::Mthd_get_total_distance_driven_km(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      *ppResult = SSInstance::pool_new(
                    SSBrain::c_real_class_p,
                    COERCE_UNSIGNED_INT(*(float *)&m_pComponent[10].m_BoundComponentHandles.mNode.mNext * 0.001));
  }
}

// File Line: 663
// RVA: 0x654950
void __fastcall UFG::TSVehicle::Mthd_get_type(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectVehiclePropertiesComponent *v5; // rax
  UFG::eSimObjectVehicleTypeEnum m_eSimObjectVehicleType; // eax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        m_eSimObjectVehicleType = v5->m_eSimObjectVehicleType;
        switch ( m_eSimObjectVehicleType )
        {
          case eSIM_OBJ_VEHICLE_TYPE_MINIBUS:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Minibus);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_CAR:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Car);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_TRUCK:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Truck);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_VAN:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Van);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_BIKE:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Bike);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_SCOOTER:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Scooter);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_BOAT:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Boat_21);
            break;
          case eSIM_OBJ_VEHICLE_TYPE_TRAM:
            *ppResult = SSSymbol::as_instance((ASymbol *)&qSymbol_Tram);
            break;
        }
      }
    }
  }
}

// File Line: 701
// RVA: 0x654820
void __fastcall UFG::TSVehicle::Mthd_get_speed(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  if ( ppResult )
  {
    m_pSimComponent = this->mMoverComponent.m_pSimComponent;
    if ( m_pSimComponent )
      *ppResult = SSInstance::pool_new(
                    SSBrain::c_real_class_p,
                    COERCE_UNSIGNED_INT(3.5999999 * *((float *)&m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev
                                                    + 1)));
  }
}

// File Line: 719
// RVA: 0x654370
void __fastcall UFG::TSVehicle::Mthd_get_linear_velocity_magnitude(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx
  float user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      user_data = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(m_pSimComponent);
      *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
    }
  }
}

// File Line: 727
// RVA: 0x655A00
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      HIDWORD(m_pComponent[10].m_BoundComponentHandles.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 750
// RVA: 0x6559C0
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_vehicle_coll(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      LODWORD(m_pComponent[11].vfptr) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 759
// RVA: 0x6561F0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_take_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      HIDWORD(m_pComponent[13].vfptr) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 768
// RVA: 0x6560E0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_min_impulse(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      LODWORD(m_pComponent[13].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 777
// RVA: 0x6560A0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_max_impulse(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      HIDWORD(m_pComponent[13].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 786
// RVA: 0x6561B0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_deal_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::PhysicsMoverInterface *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      m_pComponent->mVehicleCollisionMinImpulseRequiredToDealDamage = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 795
// RVA: 0x656170
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_max_impulse_for_dealing_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      *(_DWORD *)&m_pComponent[13].m_Flags = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 804
// RVA: 0x656120
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_force_damage_dealer(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v4; // dl
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
    {
      BYTE4(m_pComponent[14].vfptr) &= ~1u;
      BYTE4(m_pComponent[14].vfptr) |= v4;
    }
  }
}

// File Line: 815
// RVA: 0x655940
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_bullets(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      LODWORD(m_pComponent[11].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 826
// RVA: 0x655900
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_attack(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::PhysicsMoverInterface *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      m_pComponent->mDamageMultiplierAttack = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 837
// RVA: 0x655980
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_tires(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
      HIDWORD(m_pComponent[11].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 848
// RVA: 0x6538E0
void __fastcall UFG::TSVehicle::Mthd_disable_flapping_attachments(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::CarPhysicsMoverComponent *v4; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(m_pPointer);
    if ( v4 )
      UFG::CarPhysicsMoverComponent::DisableFlappingAttachments(v4);
  }
}

// File Line: 857
// RVA: 0x655CB0
void __fastcall UFG::TSVehicle::Mthd_set_grime_value(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
    if ( m_pComponent )
      LODWORD(m_pComponent[28].m_BoundComponentHandles.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 873
// RVA: 0x654910
void __fastcall UFG::TSVehicle::Mthd_get_trail_xform(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::TransformNodeComponent *ChaseSpawnTransform; // rax

  if ( ppResult )
  {
    ChaseSpawnTransform = UFG::VehicleUtility::GetChaseSpawnTransform(this->mpSimObj.m_pPointer, 20.0);
    *ppResult = UFG::TSTransform::AsInstance(ChaseSpawnTransform);
  }
}

// File Line: 900
// RVA: 0x654B60
void __fastcall UFG::TSVehicle::Mthd_is_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v5; // bl
  UFG::TSActor *ArgByNameOrInstance; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimObjectGame *mNext; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx

  if ( ppResult )
  {
    v5 = 0;
    ArgByNameOrInstance = UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[23].m_pComponent;
      if ( m_pComponent )
      {
        mNext = (UFG::SimObjectGame *)m_pComponent[3].m_BoundComponentHandles.mNode.mNext;
        if ( ArgByNameOrInstance->mpSimObj.m_pPointer == mNext )
        {
          if ( mNext )
          {
            m_Flags = mNext->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              ComponentOfTypeHK = mNext->m_Components.p[44].m_pComponent;
            }
            else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    mNext,
                                    UFG::CharacterOccupantComponent::_TypeUID);
            }
            else
            {
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mNext, UFG::CharacterOccupantComponent::_TypeUID);
            }
          }
          else
          {
            ComponentOfTypeHK = 0i64;
          }
          v5 = LODWORD(ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext) == 4
            && !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)ComponentOfTypeHK);
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 927
// RVA: 0x6543B0
void __fastcall UFG::TSVehicle::Mthd_get_num_wheels(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
      if ( m_pComponent )
      {
        mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
        if ( mPrev )
        {
          v6 = 0i64;
          if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
            v6 = mPrev;
          if ( v6 )
            *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, HIDWORD(v6[37].mNext) & 7);
        }
      }
    }
  }
}

// File Line: 945
// RVA: 0x654420
void __fastcall UFG::TSVehicle::Mthd_get_num_wheels_off_ground(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  unsigned int v8; // ebx
  unsigned int NumWheelsOnGround; // eax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
      if ( m_pComponent )
      {
        mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
        if ( mPrev )
        {
          v7 = 0i64;
          if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
            v7 = mPrev;
          if ( v7 )
          {
            v8 = HIDWORD(v7[37].mNext) & 7;
            NumWheelsOnGround = UFG::PhysicsWheeledVehicle::GetNumWheelsOnGround((UFG::PhysicsWheeledVehicle *)v7);
            if ( NumWheelsOnGround <= v8 )
              *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v8 - NumWheelsOnGround);
          }
        }
      }
    }
  }
}

// File Line: 976
// RVA: 0x654D90
void __fastcall UFG::TSVehicle::Mthd_is_upright(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int VehicleOrientation; // eax

  if ( ppResult )
  {
    VehicleOrientation = UFG::VehicleUtility::GetVehicleOrientation(
                           (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer,
                           0,
                           0i64);
    *ppResult = SSBoolean::pool_new(VehicleOrientation == 0);
  }
}

// File Line: 984
// RVA: 0x654010
void __fastcall UFG::TSVehicle::Mthd_get_average_damage_rig_health(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  float v5; // xmm2_4
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimObject *m_pSimObject; // rdx
  int vfptr_high; // r8d
  unsigned int v9; // r10d
  __int64 v10; // rax
  __int64 v11; // rcx
  unsigned int v12; // eax
  __int64 v13; // r9
  __int64 v14; // rdx
  __int64 v15; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v5 = 0.0;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
      if ( m_pComponent )
      {
        m_pSimObject = m_pComponent[28].m_pSimObject;
        if ( m_pSimObject )
        {
          vfptr_high = HIDWORD(m_pSimObject->vfptr);
          v9 = 0;
          v10 = 0i64;
          if ( vfptr_high >= 4 )
          {
            v11 = (__int64)&m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext[3].mPrev
                + 4;
            v12 = ((unsigned int)(vfptr_high - 4) >> 2) + 1;
            v13 = v12;
            v9 = 4 * v12;
            v10 = 4i64 * v12;
            do
            {
              v11 += 192i64;
              v5 = (float)((float)((float)((float)(1.0 - *(float *)(v11 - 240)) + v5)
                                 + (float)(1.0 - *(float *)(v11 - 192)))
                         + (float)(1.0 - *(float *)(v11 - 144)))
                 + (float)(1.0 - *(float *)(v11 - 96));
              --v13;
            }
            while ( v13 );
          }
          if ( v9 < vfptr_high )
          {
            v14 = (__int64)&m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext[3 * v10].mPrev
                + 4;
            v15 = vfptr_high - v9;
            do
            {
              v14 += 48i64;
              v5 = v5 + (float)(1.0 - *(float *)(v14 - 48));
              --v15;
            }
            while ( v15 );
          }
          v5 = v5 / (float)vfptr_high;
        }
      }
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v5));
  }
}

// File Line: 1014
// RVA: 0x6542D0
void __fastcall UFG::TSVehicle::Mthd_get_health_damage_rig(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  float v4; // xmm6_4
  UFG::SimComponent *m_pComponent; // rcx
  DamageRig *m_pSimObject; // rcx
  float health_output; // [rsp+50h] [rbp+18h] BYREF
  unsigned __int64 user_data; // [rsp+58h] [rbp+20h]

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0.0;
    health_output = 0.0;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
      if ( m_pComponent )
      {
        m_pSimObject = (DamageRig *)m_pComponent[28].m_pSimObject;
        if ( m_pSimObject )
        {
          DamageRig::GetTriggerMarkerHealth(
            m_pSimObject,
            (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
            &health_output);
          if ( (float)(1.0 - health_output) > 0.0 )
            v4 = 1.0 - health_output;
          health_output = v4;
        }
      }
    }
    *(float *)&user_data = v4;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 1046
// RVA: 0x655B80
void __fastcall UFG::TSVehicle::Mthd_set_engine_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(
      m_pSimComponent,
      *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1068
// RVA: 0x654200
void __fastcall UFG::TSVehicle::Mthd_get_engine_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx
  float user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      user_data = UFG::PhysicsMoverInterface::GetEngineDamage(m_pSimComponent);
      *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
    }
  }
}

// File Line: 1081
// RVA: 0x655FF0
void __fastcall UFG::TSVehicle::Mthd_set_tire_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::PhysicsMoverInterface::DamageTire(
      m_pSimComponent,
      0i64,
      (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
      1.0);
}

// File Line: 1123
// RVA: 0x654870
void __fastcall UFG::TSVehicle::Mthd_get_tire_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx
  bool IsTireBlown; // al

  if ( ppResult )
  {
    m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      IsTireBlown = UFG::PhysicsMoverInterface::IsTireBlown(
                      m_pSimComponent,
                      (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      *ppResult = SSBoolean::pool_new(IsTireBlown);
    }
  }
}

// File Line: 1140
// RVA: 0x654FC0
void __fastcall UFG::TSVehicle::Mthd_repair_damage(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::PhysicsMoverInterface::RepairDamage(m_pSimComponent);
}

// File Line: 1149
// RVA: 0x656520
void __fastcall UFG::TSVehicle::Mthd_wander(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx
  SSData **i_array_p; // rax
  unsigned int v7; // edx
  UFG::SimComponent *m_pSimComponent; // rax

  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) )
    {
      m_pPointer = this->mpSimObj.m_pPointer;
      if ( m_pPointer )
      {
        m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
        if ( m_pComponent )
          LODWORD(m_pComponent[30].m_SafePointerList.mNode.mNext) = 2;
      }
    }
    i_array_p = pScope->i_data.i_array_p;
    v7 = 3;
    if ( (*i_array_p)->i_data_p->i_user_data )
      v7 = 0;
    UFG::AiDriverComponent::SetDrivingRole((UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent, v7);
    m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
    if ( LODWORD(m_pSimComponent[13].m_SafePointerList.mNode.mPrev) != 1 )
    {
      LODWORD(m_pSimComponent[13].m_SafePointerList.mNode.mPrev) = 1;
      HIDWORD(m_pSimComponent[19].m_SafePointerList.mNode.mPrev) = 0;
      HIDWORD(m_pSimComponent[24].m_SafePointerList.mNode.mPrev) = 0;
      BYTE4(m_pSimComponent[18].m_pSimObject) = 0;
      BYTE4(m_pSimComponent[18].m_BoundComponentHandles.mNode.mPrev) = 0;
      LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mNext) = 0;
    }
  }
}

// File Line: 1175
// RVA: 0x649D10
char __fastcall UFG::TSVehicle::Coro_path_to_xform(
        UFG::TSVehicle *this,
        UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::RoadSpaceComponent *m_pComponent; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rax
  UFG::SimComponent *v7; // rcx
  UFG::SimComponent *m_pSimComponent; // rcx
  unsigned __int64 mPrev; // rbp
  UFG::SimComponent *v11; // rax
  float *v12; // rcx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  UFG::qVector3 nodePos; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-18h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
  else
    m_pComponent = 0i64;
  if ( !this->mAIDriverComponent.m_pSimComponent )
  {
    this->bDelayedByNoDriver = 1;
    return 0;
  }
  if ( !LODWORD(pScope[7].mPrev) || this->bDelayedByNoDriver )
  {
    m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
    mPrev = (unsigned __int64)pScope[6].mPrev->mPrev->mNext[2].mPrev;
    m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext = pScope;
    LODWORD(m_pSimComponent[13].vfptr) = pScope->mNext;
    v11 = this->mAIDriverComponent.m_pSimComponent;
    if ( LODWORD(v11[13].m_SafePointerList.mNode.mPrev) != 2 )
    {
      v12 = *(float **)&v11[5].m_TypeUID;
      LODWORD(v11[13].m_SafePointerList.mNode.mPrev) = 2;
      HIDWORD(v11[19].m_SafePointerList.mNode.mPrev) = 0;
      HIDWORD(v11[24].m_SafePointerList.mNode.mPrev) = 0;
      BYTE4(v11[18].m_pSimObject) = 0;
      BYTE4(v11[18].m_BoundComponentHandles.mNode.mPrev) = 0;
      LOBYTE(v11[22].m_BoundComponentHandles.mNode.mNext) = 0;
      if ( !v12
        || (float)((float)((float)(v12[415] * v12[415]) + (float)(v12[416] * v12[416])) + (float)(v12[417] * v12[417])) < 0.0000010000001 )
      {
        LOBYTE(v11[22].m_BoundComponentHandles.mNode.mNext) = 1;
      }
    }
    if ( pScope[6].mPrev->mNext->mNext[2].mPrev )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mPrev);
      x = *(float *)(mPrev + 176);
      y = *(float *)(mPrev + 180);
      z = *(float *)(mPrev + 184);
      pos.x = x;
      pos.y = y;
      pos.z = z;
      if ( UFG::gpRoadNetworkResource )
      {
        nodePos.x = x;
        nodePos.y = y;
        nodePos.z = z;
        if ( UFG::RoadNetworkResource::GetClosestNode(UFG::gpRoadNetworkResource, &pos, 0, &nodePos, 0i64) )
        {
          x = nodePos.x;
          y = nodePos.y;
          z = nodePos.z;
        }
        else
        {
          z = pos.z;
          y = pos.y;
          x = pos.x;
        }
      }
      m_pComponent->mDestinationPosition.x = x;
      m_pComponent->mDestinationPosition.y = y;
      m_pComponent->mDestinationPosition.z = z;
      v16 = UFG::qVector3::msZero.z;
      v17 = UFG::qVector3::msZero.x;
      m_pComponent->mDestinationDirection.y = UFG::qVector3::msZero.y;
      m_pComponent->mDestinationDirection.z = v16;
      m_pComponent->mDestinationDirection.x = v17;
      ++LODWORD(pScope[5].mPrev);
      this->bDelayedByNoDriver = 0;
    }
    else
    {
      UFG::RoadSpaceComponent::SetCarDestination(m_pComponent, (UFG::TransformNodeComponent *)mPrev);
      ++LODWORD(pScope[5].mPrev);
      this->bDelayedByNoDriver = 0;
    }
    return 0;
  }
  p_mNext = &this->mAIDriverComponent.m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext;
  *p_mNext = 0i64;
  *((_DWORD *)p_mNext + 2) = 0;
  v7 = this->mAIDriverComponent.m_pSimComponent;
  if ( LODWORD(v7[13].m_SafePointerList.mNode.mPrev) != 5 )
  {
    LODWORD(v7[13].m_SafePointerList.mNode.mPrev) = 5;
    HIDWORD(v7[19].m_SafePointerList.mNode.mPrev) = 0;
    HIDWORD(v7[24].m_SafePointerList.mNode.mPrev) = 0;
    BYTE4(v7[18].m_pSimObject) = 0;
    BYTE4(v7[18].m_BoundComponentHandles.mNode.mPrev) = 0;
    LOBYTE(v7[22].m_BoundComponentHandles.mNode.mNext) = 0;
    UFG::AiDriverComponent::SetupStopAt((UFG::AiDriverComponent *)v7);
  }
  return 1;
}

// File Line: 1227
// RVA: 0x6563E0
void __fastcall UFG::TSVehicle::Mthd_stop(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax
  float v4; // xmm1_4
  UFG::SimComponent *v5; // rax

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    BYTE4(m_pSimComponent[24].vfptr) &= ~1u;
    *(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&m_pSimComponent[23].m_BoundComponentHandles.mNode.mNext
                                                                                        + 4) = 0i64;
    v4 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = this->mAIDriverComponent.m_pSimComponent;
    if ( v4 <= 0.0 )
    {
      if ( LODWORD(v5[13].m_SafePointerList.mNode.mPrev) )
      {
        LODWORD(v5[13].m_SafePointerList.mNode.mPrev) = 0;
        HIDWORD(v5[19].m_SafePointerList.mNode.mPrev) = 0;
        HIDWORD(v5[24].m_SafePointerList.mNode.mPrev) = 0;
        BYTE4(v5[18].m_pSimObject) = 0;
        BYTE4(v5[18].m_BoundComponentHandles.mNode.mPrev) = 0;
        LOBYTE(v5[22].m_BoundComponentHandles.mNode.mNext) = 0;
        if ( LOBYTE(v5[24].m_SafePointerList.mNode.mNext) )
          LODWORD(v5[24].m_SafePointerList.mNode.mPrev) = 1065353216;
      }
    }
    else
    {
      *((float *)&v5[24].m_SafePointerList.mNode.mPrev + 1) = v4 * -9.8000002;
    }
  }
}

// File Line: 1246
// RVA: 0x649FB0
char __fastcall UFG::TSVehicle::Coro_stop_at(
        UFG::TSVehicle *this,
        UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  int v3; // ebx
  UFG::RoadSpaceComponent *m_pComponent; // rbp
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v10; // rcx
  SSData **mPrev; // rdx
  int i_user_data; // xmm0_4
  char *v13; // rax
  char v14; // cl
  char v15; // [rsp+28h] [rbp-10h]

  m_pPointer = this->mpSimObj.m_pPointer;
  v3 = 0;
  if ( m_pPointer )
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
  else
    m_pComponent = 0i64;
  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( !m_pSimComponent )
  {
    this->bDelayedByNoDriver = 1;
    return 0;
  }
  if ( !LODWORD(pScope[7].mPrev) || this->bDelayedByNoDriver )
  {
    m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext = pScope;
    LODWORD(m_pSimComponent[13].vfptr) = pScope->mNext;
    v10 = this->mAIDriverComponent.m_pSimComponent;
    if ( LODWORD(v10[13].m_SafePointerList.mNode.mPrev) != 5 )
    {
      LODWORD(v10[13].m_SafePointerList.mNode.mPrev) = 5;
      HIDWORD(v10[19].m_SafePointerList.mNode.mPrev) = 0;
      HIDWORD(v10[24].m_SafePointerList.mNode.mPrev) = 0;
      BYTE4(v10[18].m_pSimObject) = 0;
      BYTE4(v10[18].m_BoundComponentHandles.mNode.mPrev) = 0;
      LOBYTE(v10[22].m_BoundComponentHandles.mNode.mNext) = 0;
      UFG::AiDriverComponent::SetupStopAt((UFG::AiDriverComponent *)v10);
    }
    UFG::RoadSpaceComponent::SetCarDestination(
      m_pComponent,
      (UFG::TransformNodeComponent *)pScope[6].mPrev->mPrev->mNext[2].mPrev);
    mPrev = (SSData **)pScope[6].mPrev;
    i_user_data = mPrev[3]->i_data_p->i_user_data;
    LOBYTE(v3) = mPrev[1]->i_data_p->i_user_data != 0;
    v13 = (char *)&this->mAIDriverComponent.m_pSimComponent[23].m_BoundComponentHandles.mNode.mNext + 4;
    v14 = ((v15 ^ (mPrev[2]->i_data_p->i_user_data != 0)) & 1 ^ v15) & 1;
    v13[8] &= ~1u;
    v13[8] |= v14;
    *(_DWORD *)v13 = v3;
    *((_DWORD *)v13 + 1) = i_user_data;
    LODWORD(this->mAIDriverComponent.m_pSimComponent[24].m_SafePointerList.mNode.mPrev) = pScope[6].mPrev[2].mPrev->mNext[2].mPrev;
    ++LODWORD(pScope[5].mPrev);
    this->bDelayedByNoDriver = 0;
    return 0;
  }
  m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext = 0i64;
  LODWORD(m_pSimComponent[13].vfptr) = 0;
  v8 = this->mAIDriverComponent.m_pSimComponent;
  if ( LODWORD(v8[13].m_SafePointerList.mNode.mPrev) )
  {
    LODWORD(v8[13].m_SafePointerList.mNode.mPrev) = 0;
    HIDWORD(v8[19].m_SafePointerList.mNode.mPrev) = 0;
    HIDWORD(v8[24].m_SafePointerList.mNode.mPrev) = 0;
    BYTE4(v8[18].m_pSimObject) = 0;
    BYTE4(v8[18].m_BoundComponentHandles.mNode.mPrev) = 0;
    LOBYTE(v8[22].m_BoundComponentHandles.mNode.mNext) = 0;
    if ( LOBYTE(v8[24].m_SafePointerList.mNode.mNext) )
      LODWORD(v8[24].m_SafePointerList.mNode.mPrev) = 1065353216;
  }
  return 1;
}

// File Line: 1294
// RVA: 0x653790
void __fastcall UFG::TSVehicle::Mthd_create_ai_driver(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::VehicleUtility::SetAIDriver((UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer, 0);
  if ( !this->mAIDriverComponent.m_pSimComponent )
    UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::Bind<UFG::SimObjectVehicle>(
      &this->mAIDriverComponent,
      (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer);
}

// File Line: 1303
// RVA: 0x6537D0
void __fastcall UFG::TSVehicle::Mthd_create_human_driver(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::VehicleDriverInterface *v3; // rax
  UFG::VehicleDriverInterface *v4; // rbx

  v3 = (UFG::VehicleDriverInterface *)UFG::VehicleUtility::SetPlayerDriver((UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer);
  v4 = v3;
  if ( v3 )
  {
    UFG::VehicleDriverInterface::SetDriver(v3, LocalPlayer);
    UFG::VehicleDriverInterface::SetDesiredState(v4, (UFG::VehicleState)2);
    UFG::VehicleDriverInterface::StartEngineAudio(v4);
  }
}

// File Line: 1317
// RVA: 0x6536A0
void __fastcall UFG::TSVehicle::Mthd_clear_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *p_mAIDriverComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::SimObjectVehicle *m_pPointer; // rcx

  p_mAIDriverComponent = &this->mAIDriverComponent;
  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    mPrev = p_mAIDriverComponent->mPrev;
    mNext = this->mAIDriverComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mAIDriverComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mAIDriverComponent->m_pSimObject = 0i64;
    p_mAIDriverComponent->mNext = p_mAIDriverComponent;
    p_mAIDriverComponent->mPrev = p_mAIDriverComponent;
    goto LABEL_8;
  }
  if ( this->mAIDriverComponent.m_pSimObject
    && (p_mAIDriverComponent->mPrev != p_mAIDriverComponent
     || this->mAIDriverComponent.mNext != &this->mAIDriverComponent) )
  {
    v7 = p_mAIDriverComponent->mPrev;
    v8 = p_mAIDriverComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mAIDriverComponent->m_Changed = 1;
  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  this->mAIDriverComponent.m_pSimComponent = 0i64;
  UFG::VehicleUtility::ClearDriver(m_pPointer);
}

// File Line: 1324
// RVA: 0x655A70
void __fastcall UFG::TSVehicle::Mthd_set_driving_role(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::qSymbol *v4; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    v4 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v4->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( CarAI::mRoleEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&CarAI::mRoleEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode;
      CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0xA )
      UFG::AiDriverComponent::SetDrivingRole(
        (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
        pTrackEnumBinding.m_EnumValue);
    v6 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v6;
  }
}

// File Line: 1337
// RVA: 0x655530
void __fastcall UFG::TSVehicle::Mthd_set_can_shove_cargo(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    if ( m_pComponent )
      BYTE1(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) ^= (BYTE1(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) ^ (8 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 8;
  }
}

// File Line: 1404
// RVA: 0x655DD0
void __fastcall UFG::TSVehicle::Mthd_set_race(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceTrail *v3; // r8
  __int64 i_user_data_low; // rdx
  int v5; // eax
  UFG::SimObject *m_pPointer; // rax
  UFG::RoadSpaceComponent *m_pComponent; // rcx

  v3 = 0i64;
  i_user_data_low = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    v5 = 0;
  }
  else
  {
    v5 = i_user_data_low;
    if ( (int)i_user_data_low >= 63 )
      v5 = 63;
  }
  if ( (_DWORD)i_user_data_low == v5 )
    v3 = UFG::RaceManager::aRaceTrails[i_user_data_low];
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
      UFG::RoadSpaceComponent::SetRaceTrail(m_pComponent, v3);
  }
}

// File Line: 1414
// RVA: 0x656380
void __fastcall UFG::TSVehicle::Mthd_steer_race(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceTrail *v3; // r8
  __int64 i_user_data_low; // rdx
  int v5; // eax
  UFG::SimObject *m_pPointer; // rax
  UFG::RoadSpaceComponent *m_pComponent; // rcx

  v3 = 0i64;
  i_user_data_low = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    v5 = 0;
  }
  else
  {
    v5 = i_user_data_low;
    if ( (int)i_user_data_low >= 63 )
      v5 = 63;
  }
  if ( (_DWORD)i_user_data_low == v5 )
    v3 = UFG::RaceManager::aRaceTrails[i_user_data_low];
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
      UFG::RoadSpaceComponent::SetRaceTrailSteer(m_pComponent, v3);
  }
}

// File Line: 1421
// RVA: 0x656230
void __fastcall UFG::TSVehicle::Mthd_start_racing(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // rax
  UFG::AiDriverComponent *v5; // rcx
  bool m_RoadRuleFlagsLocked; // al
  SSData **i_array_p; // rdx
  UFG::AiDriverComponent *v8; // r9
  UFG::SimObject *m_pPointer; // rax
  UFG::AiDriverComponent *m_pComponent; // rax
  UFG::PhysicsMoverInterface *mNext; // rax

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( m_pSimComponent->m_DrivingMode != 6 )
    {
      m_pSimComponent->m_DrivingMode = 6;
      m_pSimComponent->m_fReactionTime = 0.0;
      m_pSimComponent->m_fDelayedStopDecel = 0.0;
      m_pSimComponent->mModeSteeringLockEnabled = 0;
      m_pSimComponent->mModeGasBrakeLockEnabled = 0;
      m_pSimComponent->m_bIgnoreArrivalDirection = 0;
    }
    v5 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
    if ( v5->m_DrivingRole != 1 )
    {
      m_RoadRuleFlagsLocked = v5->m_RoadRuleFlagsLocked;
      v5->m_DrivingRole = 1;
      if ( !m_RoadRuleFlagsLocked )
      {
        v5->m_bAvoidPeds = 0;
        v5->m_fAvoidStopTimer = 0.0;
        v5->m_bAllowedToPass = 1;
        v5->m_bStayOffSidewalk = 0;
        v5->m_bRespectSpeedLimit = 0;
        v5->m_bCanTurnAround = 0;
      }
      v5->m_bSavedAvoidPeds = v5->m_bAvoidPeds;
    }
    i_array_p = pScope->i_data.i_array_p;
    v8 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
    v8->m_fRaceSpeedLimit = *(float *)&(*i_array_p)->i_data_p->i_user_data * 0.27777779;
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer && (m_pComponent = (UFG::AiDriverComponent *)m_pPointer->m_Components.p[24].m_pComponent) != 0i64 )
      mNext = (UFG::PhysicsMoverInterface *)m_pComponent[1].mMoverComponent.mNext;
    else
      mNext = 0i64;
    if ( mNext )
      HIDWORD(mNext->m_BoundComponentHandles.mNode.mNext) = 0;
    v8->m_RaceWanderAtEnd = i_array_p[1]->i_data_p->i_user_data != 0;
  }
}

// File Line: 1445
// RVA: 0x655E30
void __fastcall UFG::TSVehicle::Mthd_set_race_speed_limit(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r8

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_fRaceSpeedLimit = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * 0.27777779;
}

// File Line: 1458
// RVA: 0x655780
void __fastcall UFG::TSVehicle::Mthd_set_countdown_time(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pComponent = m_pPointer->m_Components.p[24].m_pComponent) != 0i64 )
    mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
  else
    mPrev = 0i64;
  if ( mPrev )
    LODWORD(mPrev[4].mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1466
// RVA: 0x6555C0
void __fastcall UFG::TSVehicle::Mthd_set_catchup_target(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r9
  SSData **i_array_p; // r8
  float v6; // xmm9_4
  float v7; // xmm10_4
  unsigned int i_user_data; // xmm11_4
  float v9; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm8_4
  float v12; // xmm1_4
  UFG::SimComponent *v13; // rax
  float v14; // xmm0_4

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return;
  i_array_p = pScope->i_data.i_array_p;
  v6 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  v7 = *(float *)&i_array_p[2]->i_data_p->i_user_data * 0.0099999998;
  i_user_data = i_array_p[3]->i_data_p->i_user_data;
  v9 = *(float *)&i_array_p[4]->i_data_p->i_user_data;
  if ( v9 >= 0.0 )
    v10 = v9 * 0.0099999998;
  else
    v10 = *(float *)&i_array_p[2]->i_data_p->i_user_data * 0.0099999998;
  v11 = *(float *)&i_array_p[5]->i_data_p->i_user_data;
  if ( v11 < 0.0 )
    v11 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  UFG::AiDriverComponent::SetChaseTarget(m_pSimComponent, *(UFG::SimObject **)&(*i_array_p)->i_data_p[4].i_ref_count);
  v12 = FLOAT_10_0;
  if ( v6 < 10.0 )
    v6 = FLOAT_10_0;
  *(float *)&this->mAIDriverComponent.m_pSimComponent[16].m_SafePointerList.mNode.mPrev = v6;
  UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -1.0 / v6;
  v13 = this->mAIDriverComponent.m_pSimComponent;
  if ( v7 < 0.0 )
    v7 = 0.0;
  *(float *)&v13[16].m_SafePointerList.mNode.mNext = v7;
  v13[16].m_TypeUID = i_user_data;
  if ( v10 <= 0.0 )
  {
    v10 = 0.0;
  }
  else
  {
    v14 = *(float *)&FLOAT_1_0;
    if ( v10 >= 1.0 )
      goto LABEL_16;
  }
  v14 = v10;
LABEL_16:
  *((float *)&v13[16].m_SafePointerList.mNode.mNext + 1) = v14;
  if ( v11 >= 10.0 )
    v12 = v11;
  *((float *)&v13[16].m_SafePointerList.mNode.mPrev + 1) = v12;
  UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -1.0 / v12;
}

// File Line: 1492
// RVA: 0x653630
void __fastcall UFG::TSVehicle::Mthd_clear_catchup_target(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // rcx
  UFG::SimComponent *v5; // rax

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    UFG::AiDriverComponent::SetChaseTarget(m_pSimComponent, 0i64);
    LODWORD(this->mAIDriverComponent.m_pSimComponent[16].m_SafePointerList.mNode.mPrev) = 1092616192;
    UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -0.1;
    v5 = this->mAIDriverComponent.m_pSimComponent;
    v5[16].m_SafePointerList.mNode.mNext = 0i64;
    v5[16].m_TypeUID = 0;
    HIDWORD(v5[16].m_SafePointerList.mNode.mPrev) = 1092616192;
    UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -0.1;
  }
}

// File Line: 1506
// RVA: 0x655BB0
void __fastcall UFG::TSVehicle::Mthd_set_force_dock(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LOBYTE(m_pSimComponent[4].m_TypeUID) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1515
// RVA: 0x6545C0
void __fastcall UFG::TSVehicle::Mthd_get_race_index(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  unsigned __int64 mNext_low; // rdx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  mNext_low = 0xFFFFFFFFi64;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
    {
      mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
      if ( mPrev )
      {
        v7 = mPrev[1].mPrev;
        if ( v7 )
          mNext_low = LODWORD(v7[2].mNext);
      }
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, mNext_low);
}

// File Line: 1528
// RVA: 0x654620
void __fastcall UFG::TSVehicle::Mthd_get_race_point_index(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  signed __int64 v4; // rdx
  UFG::RoadSpaceComponent *m_pComponent; // rax
  UFG::RacePosition *m_pRacePosition; // rax
  UFG::RaceTrail *v8; // r8
  UFG::RacePoint *pRacePoint; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  LODWORD(v4) = -1;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
    {
      m_pRacePosition = m_pComponent->m_pRacePosition;
      if ( m_pRacePosition )
      {
        v8 = m_pRacePosition->pRaceTrail.m_pPointer;
        if ( v8 )
        {
          pRacePoint = m_pRacePosition->pRacePoint;
          if ( pRacePoint )
            v4 = pRacePoint - v8->pRacePoints;
        }
      }
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)v4);
}

// File Line: 1541
// RVA: 0x654700
void __fastcall UFG::TSVehicle::Mthd_get_race_time(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  unsigned int mNext_high; // xmm0_4
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  mNext_high = 0;
  if ( m_pPointer && (m_pComponent = m_pPointer->m_Components.p[24].m_pComponent) != 0i64 )
    mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
  else
    mPrev = 0i64;
  if ( mPrev )
    mNext_high = HIDWORD(mPrev[3].mNext);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, mNext_high);
}

// File Line: 1550
// RVA: 0x654150
void __fastcall UFG::TSVehicle::Mthd_get_countdown_time(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  unsigned int v4; // xmm0_4
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 0;
  if ( m_pPointer && (m_pComponent = m_pPointer->m_Components.p[24].m_pComponent) != 0i64 )
    mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
  else
    mPrev = 0i64;
  if ( mPrev )
    v4 = (unsigned int)mPrev[4].mPrev;
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, v4);
}

// File Line: 1559
// RVA: 0x654240
void __fastcall UFG::TSVehicle::Mthd_get_fraction_race_complete(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  float v4; // xmm0_4
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  float mNext_low; // xmm1_4
  float v9; // xmm1_4

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 0.0;
  if ( m_pPointer && (m_pComponent = m_pPointer->m_Components.p[24].m_pComponent) != 0i64 )
    mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
  else
    mPrev = 0i64;
  if ( mPrev )
  {
    v7 = mPrev[1].mPrev;
    if ( v7 )
    {
      if ( LOBYTE(v7[2].mPrev) )
        mNext_low = (float)SLODWORD(v7[1].mNext);
      else
        mNext_low = *(float *)&FLOAT_1_0;
      v9 = mNext_low * *((float *)&v7[2].mPrev + 1);
      if ( v9 > 0.0 )
        v4 = *(float *)&mPrev[3].mPrev / v9;
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
}

// File Line: 1568
// RVA: 0x6546A0
void __fastcall UFG::TSVehicle::Mthd_get_race_proximity(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  unsigned int mPrev_high; // xmm0_4
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  mPrev_high = 0;
  if ( m_pPointer && (m_pComponent = m_pPointer->m_Components.p[24].m_pComponent) != 0i64 )
    mPrev = m_pComponent[26].m_SafePointerList.mNode.mPrev;
  else
    mPrev = 0i64;
  if ( mPrev )
    mPrev_high = HIDWORD(mPrev[3].mPrev);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, mPrev_high);
}

// File Line: 1578
// RVA: 0x653E40
void __fastcall UFG::TSVehicle::Mthd_follow(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rcx
  UFG::AiDriverComponent *m_pSimComponent; // r8
  SSInstance *i_data_p; // r9
  int i_user_data; // xmm6_4

  i_array_p = pScope->i_data.i_array_p;
  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  i_data_p = (*i_array_p)->i_data_p;
  if ( m_pSimComponent && i_data_p )
  {
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    if ( m_pSimComponent->m_DrivingMode != 4 )
    {
      m_pSimComponent->m_DrivingMode = 4;
      m_pSimComponent->m_bIgnoreArrivalDirection = 1;
      m_pSimComponent->m_fReactionTime = 0.0;
      m_pSimComponent->m_fDelayedStopDecel = 0.0;
      m_pSimComponent->mModeSteeringLockEnabled = 0;
      m_pSimComponent->mModeGasBrakeLockEnabled = 0;
    }
    UFG::AiDriverComponent::SetChaseTarget(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&i_data_p[4].i_ref_count);
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      COERCE_FLOAT(i_user_data ^ _xmm[0]),
      0.0,
      2.0);
  }
}

// File Line: 1591
// RVA: 0x653C40
void __fastcall UFG::TSVehicle::Mthd_escort(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::SimComponent *m_pSimComponent; // rcx
  SSInstance *i_data_p; // rdi
  SSInstance *v8; // rsi
  unsigned __int16 *p_m_Flags; // rcx
  SSData **v10; // rdx
  float v11; // xmm0_4
  UFG::SimComponent *v12; // rax
  float v13; // xmm1_4

  i_array_p = pScope->i_data.i_array_p;
  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  i_data_p = (*i_array_p)->i_data_p;
  v8 = i_array_p[1]->i_data_p;
  if ( m_pSimComponent && i_data_p && v8 )
  {
    if ( LODWORD(m_pSimComponent[13].m_SafePointerList.mNode.mPrev) != 7 )
    {
      LODWORD(m_pSimComponent[13].m_SafePointerList.mNode.mPrev) = 7;
      p_m_Flags = &m_pSimComponent[21].m_Flags;
      *((_DWORD *)p_m_Flags - 37) = 0;
      *((_DWORD *)p_m_Flags + 43) = 0;
      *((_BYTE *)p_m_Flags - 180) = 0;
      *((_BYTE *)p_m_Flags - 172) = 0;
      *((_BYTE *)p_m_Flags + 88) = 0;
      UFG::VehicleCombatStats::Reset((UFG::VehicleCombatStats *)p_m_Flags);
    }
    UFG::AiDriverComponent::SetEscortEnemy(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&v8[4].i_ref_count);
    UFG::AiDriverComponent::SetEscortObjective(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&i_data_p[4].i_ref_count);
    UFG::AiDriverComponent::SetChaseTarget(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&i_data_p[4].i_ref_count);
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      COERCE_FLOAT(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) ^ _xmm[0]),
      0.0,
      2.0);
    v10 = pScope->i_data.i_array_p;
    v11 = *(float *)&v10[3]->i_data_p->i_user_data;
    v12 = this->mAIDriverComponent.m_pSimComponent;
    v13 = *(float *)&v10[4]->i_data_p->i_user_data;
    *(float *)&v12[22].m_Flags = v11 * v11;
    v12[22].m_NameUID = 1;
    *(float *)(&v12[22].m_SimObjIndex + 1) = v13 * v13;
  }
}

// File Line: 1619
// RVA: 0x653F00
void __fastcall UFG::TSVehicle::Mthd_follow_debug(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r8

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_FollowDebug = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1628
// RVA: 0x653470
void __fastcall UFG::TSVehicle::Mthd_avoidance_debug(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    BYTE5(m_pSimComponent[16].m_BoundComponentHandles.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1636
// RVA: 0x6534A0
void __fastcall UFG::TSVehicle::Mthd_break_on_update(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LOBYTE(m_pSimComponent[4].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1646
// RVA: 0x6564B0
void __fastcall UFG::TSVehicle::Mthd_take_camera(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ChaseCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( m_pPointer )
        ComponentOfType->vfptr[16].__vecDelDtor(ComponentOfType, (unsigned int)m_pPointer);
    }
  }
}

// File Line: 1653
// RVA: 0x653F30
void __fastcall UFG::TSVehicle::Mthd_follow_offset(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  UFG::SimComponent *m_pSimComponent; // r8
  SSInstance *i_data_p; // r10
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4

  i_array_p = pScope->i_data.i_array_p;
  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  i_data_p = (*i_array_p)->i_data_p;
  if ( m_pSimComponent && i_data_p )
  {
    v7 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    v8 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
    v9 = *(float *)&i_array_p[3]->i_data_p->i_user_data;
    if ( LODWORD(m_pSimComponent[13].m_SafePointerList.mNode.mPrev) != 4 )
    {
      LODWORD(m_pSimComponent[13].m_SafePointerList.mNode.mPrev) = 4;
      LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mNext) = 1;
      HIDWORD(m_pSimComponent[19].m_SafePointerList.mNode.mPrev) = 0;
      HIDWORD(m_pSimComponent[24].m_SafePointerList.mNode.mPrev) = 0;
      BYTE4(m_pSimComponent[18].m_pSimObject) = 0;
      BYTE4(m_pSimComponent[18].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
    UFG::AiDriverComponent::SetChaseTarget(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&i_data_p[4].i_ref_count);
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      v7,
      v8,
      v9);
  }
}

// File Line: 1669
// RVA: 0x655F60
void __fastcall UFG::TSVehicle::Mthd_set_slow_down_for_race_curvature(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
      m_pComponent[30].m_TypeUID ^= (m_pComponent[30].m_TypeUID ^ (8
                                                                 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 8;
  }
}

// File Line: 1680
// RVA: 0x655490
void __fastcall UFG::TSVehicle::Mthd_set_avoid_objects_enabled(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r8

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_AvoidObjectsEnabled = (float)((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0) != 0.0;
}

// File Line: 1690
// RVA: 0x655440
void __fastcall UFG::TSVehicle::Mthd_set_avoid_geo_enabled(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    BYTE1(m_pSimComponent[23].m_SafePointerList.mNode.mNext) = (float)((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0) != 0.0;
}

// File Line: 1700
// RVA: 0x655EF0
void __fastcall UFG::TSVehicle::Mthd_set_road_speed_limit_scale(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LODWORD(m_pSimComponent[23].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1709
// RVA: 0x655A40
void __fastcall UFG::TSVehicle::Mthd_set_desired_speed_limit_kph(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    *((float *)&m_pSimComponent[23].m_SafePointerList.mNode.mPrev + 1) = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data
                                                                       * 0.27777779;
}

// File Line: 1718
// RVA: 0x655750
void __fastcall UFG::TSVehicle::Mthd_set_chase_speed_limit_kph(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r8

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_fChaseSpeedLimit = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * 0.27777779;
}

// File Line: 1727
// RVA: 0x654EE0
void __fastcall UFG::TSVehicle::Mthd_override_speed_kph(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::VehicleUtility::OverrideForwardSpeedKPH(
    (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer,
    *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1734
// RVA: 0x653500
void __fastcall UFG::TSVehicle::Mthd_chase(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  UFG::AiDriverComponent *m_pSimComponent; // rcx
  UFG::SimObjectGame *v6; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObject *CurrentVehicle; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
  {
    m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      if ( m_pSimComponent->m_DrivingMode != 3 )
      {
        m_pSimComponent->m_DrivingMode = 3;
        m_pSimComponent->m_bIgnoreArrivalDirection = 1;
        m_pSimComponent->m_fReactionTime = 0.0;
        m_pSimComponent->m_fDelayedStopDecel = 0.0;
        m_pSimComponent->mModeSteeringLockEnabled = 0;
        m_pSimComponent->mModeGasBrakeLockEnabled = 0;
        UFG::VehicleCombatStats::Reset(&m_pSimComponent->m_CombatStats);
      }
      v6 = *(UFG::SimObjectGame **)&i_data_p[4].i_ref_count;
      HIDWORD(this->mAIDriverComponent.m_pSimComponent[24].m_SafePointerList.mNode.mNext) = -1082130432;
      if ( !v6
        || ((m_Flags = v6->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v6,
                                                                     UFG::CharacterOccupantComponent::_TypeUID))
           : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v6,
                                                                     UFG::CharacterOccupantComponent::_TypeUID)))
          : (ComponentOfType = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent),
            !ComponentOfType
         || (CurrentVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType)) == 0i64) )
      {
        CurrentVehicle = *(UFG::SimObject **)&i_data_p[4].i_ref_count;
      }
      UFG::AiDriverComponent::SetChaseTarget(
        (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
        CurrentVehicle);
    }
  }
}

// File Line: 1752
// RVA: 0x653A00
void __fastcall UFG::TSVehicle::Mthd_enable_horn(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  bool v4; // bl
  UFG::VehicleAudioComponent *v5; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
    {
      if ( v4 )
        UFG::VehicleAudioComponent::StartHorn(v5, 1);
      else
        UFG::VehicleAudioComponent::StopHorn(v5, 1);
    }
  }
}

// File Line: 1766
// RVA: 0x653B20
void __fastcall UFG::TSVehicle::Mthd_enable_siren(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData *v4; // rdx
  bool v5; // si
  UFG::VehicleEffectsComponent *m_pComponent; // rbx
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v8; // rcx
  UFG::SimObject *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::CopUnitComponent *v11; // rcx
  UFG::SimObject *v12; // rax
  UFG::CopUnitComponent *v13; // rcx

  v4 = *pScope->i_data.i_array_p;
  v5 = v4->i_data_p->i_user_data != 0;
  m_pComponent = 0i64;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         (int)v4,
         (int)ppResult)
    && (m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer) != 0i64 )
  {
    v8 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
  }
  else
  {
    v8 = 0i64;
  }
  v9 = this->mpSimObj.m_pPointer;
  if ( v9 )
    m_pComponent = (UFG::VehicleEffectsComponent *)v9->m_Components.p[32].m_pComponent;
  if ( v5 )
  {
    if ( v8 )
      UFG::VehicleAudioComponent::StartSiren(v8, 1);
    v10 = this->mpSimObj.m_pPointer;
    if ( v10 && (v11 = (UFG::CopUnitComponent *)v10->m_Components.p[17].m_pComponent) != 0i64 )
    {
      UFG::CopUnitComponent::SetScriptedLightsOn(v11, 1);
    }
    else if ( m_pComponent )
    {
      UFG::VehicleEffectsComponent::TurnOnCopLights(m_pComponent);
    }
  }
  else
  {
    if ( v8 )
      UFG::VehicleAudioComponent::StopSiren(v8, 1);
    v12 = this->mpSimObj.m_pPointer;
    if ( v12 && (v13 = (UFG::CopUnitComponent *)v12->m_Components.p[17].m_pComponent) != 0i64 )
    {
      UFG::CopUnitComponent::SetScriptedLightsOn(v13, 0);
    }
    else if ( m_pComponent )
    {
      UFG::VehicleEffectsComponent::TurnOffCopLights(m_pComponent);
    }
  }
}

// File Line: 1808
// RVA: 0x653910
void __fastcall UFG::TSVehicle::Mthd_enable_cop_lights(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v4; // dl
  UFG::CopUnitComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::CopUnitComponent *)m_pPointer->m_Components.p[17].m_pComponent;
    if ( m_pComponent )
      UFG::CopUnitComponent::SetScriptedLightsOn(m_pComponent, v4);
  }
}

// File Line: 1820
// RVA: 0x653980
void __fastcall UFG::TSVehicle::Mthd_enable_head_lights(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v4; // dl
  UFG::VehicleEffectsComponent *m_pComponent; // rbx

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
  else
    m_pComponent = 0i64;
  if ( v4 )
  {
    if ( m_pComponent )
    {
      UFG::VehicleEffectsComponent::TurnOnScriptedLights(m_pComponent);
      UFG::VehicleEffectsComponent::TurnOnHeadlights(m_pComponent, 1);
    }
  }
  else if ( m_pComponent )
  {
    UFG::VehicleEffectsComponent::TurnOffHeadlights(m_pComponent);
    UFG::VehicleEffectsComponent::TurnOffScriptedLights(m_pComponent);
  }
}

// File Line: 1843
// RVA: 0x654F00
void __fastcall UFG::TSVehicle::Mthd_queue_head_light_flashes(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // rdx
  SSInstance *v5; // r8
  UFG::SimObject *m_pPointer; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::VehicleEffectsComponent *)m_pPointer->m_Components.p[32].m_pComponent;
    if ( m_pComponent )
      UFG::VehicleEffectsComponent::QueueHeadlightFlashes(
        m_pComponent,
        i_data_p->i_user_data,
        *(float *)&v5->i_user_data);
  }
}

// File Line: 1855
// RVA: 0x656350
void __fastcall UFG::TSVehicle::Mthd_start_radio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v4 )
      UFG::VehicleAudioComponent::TurnOnRadio(v4);
  }
}

// File Line: 1865
// RVA: 0x652F60
void __fastcall UFG::TSVehicle::MthdC_start_player_radio(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    ((void (__fastcall *)(UFG::RadioFullyControlled *, SSInvokedMethod *, SSInstance **))UFG::RadioFullyControlled::sm_playerRadio->vfptr[1].AudioEntityUpdate)(
      UFG::RadioFullyControlled::sm_playerRadio,
      pScope,
      ppResult);
}

// File Line: 1871
// RVA: 0x652F80
void __fastcall UFG::TSVehicle::MthdC_stop_player_radio(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    ((void (__fastcall *)(UFG::RadioFullyControlled *, _QWORD, SSInstance **))UFG::RadioFullyControlled::sm_playerRadio->vfptr[1].CountNumPlayingEvents)(
      UFG::RadioFullyControlled::sm_playerRadio,
      0i64,
      ppResult);
}

// File Line: 1877
// RVA: 0x656480
void __fastcall UFG::TSVehicle::Mthd_stop_radio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v4; // rax
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v4 )
      UFG::VehicleAudioComponent::StopRadio(v4, v5);
  }
}

// File Line: 1887
// RVA: 0x655E60
void __fastcall UFG::TSVehicle::Mthd_set_radio_station(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  SSInstance *i_data_p; // rbx
  UFG::VehicleAudioComponent *v5; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
      UFG::VehicleAudioComponent::SetRadioStation(v5, (int)*(float *)&i_data_p->i_user_data);
  }
}

// File Line: 1897
// RVA: 0x654760
void __fastcall UFG::TSVehicle::Mthd_get_radio_station(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v5; // rax
  unsigned int user_data; // [rsp+30h] [rbp+8h]

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
    {
      *(float *)&user_data = (float)(int)UFG::VehicleAudioComponent::GetRadioStation(v5);
      *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, user_data);
    }
  }
}

// File Line: 1906
// RVA: 0x652F10
void __fastcall UFG::TSVehicle::MthdC_set_shutdown_on_exit(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  bool v4; // bl
  UFG::VehicleAudioComponent *v5; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
      UFG::VehicleAudioComponent::SetShutdownOnExit(v5, v4);
  }
}

// File Line: 1918
// RVA: 0x652EC0
void __fastcall UFG::TSVehicle::MthdC_set_radio_is_enabled(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  bool v4; // bl
  UFG::VehicleAudioComponent *v5; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
      UFG::VehicleAudioComponent::SetRadioIsEnabled(v5, v4);
  }
}

// File Line: 1929
// RVA: 0x653730
void __fastcall UFG::TSVehicle::Mthd_clear_playlist(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v4 )
      UFG::VehicleAudioComponent::ClearRadioPlaylist(v4);
  }
}

// File Line: 1938
// RVA: 0x653760
void __fastcall UFG::TSVehicle::Mthd_clear_recently_played(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v4 )
      UFG::VehicleAudioComponent::ClearRadioHistory(v4);
  }
}

// File Line: 1947
// RVA: 0x653210
void __fastcall UFG::TSVehicle::Mthd_add_asset_to_playlist(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  SSInstance *i_data_p; // rbx
  UFG::VehicleAudioComponent *v5; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
      UFG::VehicleAudioComponent::AddTrackToPlaylist(v5, *(const char **)i_data_p->i_user_data);
  }
}

// File Line: 1957
// RVA: 0x654F40
void __fastcall UFG::TSVehicle::Mthd_randomize_playlist(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v4; // rax
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v4 )
      UFG::VehicleAudioComponent::RandomizeRadioPlaylist(v4, v5);
  }
}

// File Line: 1966
// RVA: 0x652E70
void __fastcall UFG::TSVehicle::MthdC_randomize_player_playlist(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::RadioStation *m_curStation; // rcx

  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    m_curStation = UFG::RadioFullyControlled::sm_playerRadio->m_curStation;
    if ( m_curStation )
      UFG::RadioStation::RandomizePlaylist(m_curStation);
  }
}

// File Line: 1972
// RVA: 0x652E90
void __fastcall UFG::TSVehicle::MthdC_set_player_radio_station(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    UFG::Radio::SetStation(
      UFG::RadioFullyControlled::sm_playerRadio,
      (int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1979
// RVA: 0x6529B0
void __fastcall UFG::TSVehicle::MthdC_clear_player_playlist(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    UFG::Radio::ClearAllPlaylists(UFG::RadioFullyControlled::sm_playerRadio);
}

// File Line: 1985
// RVA: 0x6529D0
void __fastcall UFG::TSVehicle::MthdC_clear_player_recently_played(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::RadioStation *m_curStation; // rbx

  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    m_curStation = UFG::RadioFullyControlled::sm_playerRadio->m_curStation;
    if ( m_curStation )
    {
      UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&m_curStation->m_prevPlayed);
      m_curStation->m_numRecentlyPlayed = 0;
    }
  }
}

// File Line: 1991
// RVA: 0x652970
void __fastcall UFG::TSVehicle::MthdC_add_asset_to_player_playlist(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::RadioStation *m_curStation; // rcx

  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    m_curStation = UFG::RadioFullyControlled::sm_playerRadio->m_curStation;
    if ( m_curStation )
      UFG::RadioStation::AddToPlaylist(
        m_curStation,
        *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
        0);
  }
}

// File Line: 1998
// RVA: 0x652B30
void __fastcall UFG::TSVehicle::MthdC_player_radio_next_track(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    UFG::RadioFullyControlled::NextTrack(UFG::RadioFullyControlled::sm_playerRadio);
}

// File Line: 2004
// RVA: 0x654AF0
void __fastcall UFG::TSVehicle::Mthd_init_audio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v4 )
      UFG::VehicleAudioComponent::EngineStart(v4);
  }
}

// File Line: 2013
// RVA: 0x656E20
void __fastcall UFG::TSVehicle::OnInit(UFG::TSVehicle *this, UFG::SimObjectVehicle *pSimObj)
{
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *p_mAIDriverComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  void (__fastcall *v9)(fastdelegate::detail::GenericClass *); // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v10; // [rsp+30h] [rbp-28h] BYREF
  void (__fastcall *v11)(UFG::Event *); // [rsp+40h] [rbp-18h]
  void (__fastcall *v12)(fastdelegate::detail::GenericClass *); // [rsp+48h] [rbp-10h]

  UFG::TSActor::OnInit(this, pSimObj);
  p_mAIDriverComponent = &this->mAIDriverComponent;
  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    mPrev = p_mAIDriverComponent->mPrev;
    mNext = this->mAIDriverComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mAIDriverComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->mAIDriverComponent.m_pSimObject = 0i64;
    this->mAIDriverComponent.mNext = &this->mAIDriverComponent;
    p_mAIDriverComponent->mPrev = p_mAIDriverComponent;
    goto LABEL_8;
  }
  if ( this->mAIDriverComponent.m_pSimObject
    && (p_mAIDriverComponent->mPrev != p_mAIDriverComponent
     || this->mAIDriverComponent.mNext != &this->mAIDriverComponent) )
  {
    v7 = p_mAIDriverComponent->mPrev;
    v8 = this->mAIDriverComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->mAIDriverComponent.m_Changed = 1;
  this->mAIDriverComponent.m_pSimObject = pSimObj;
  this->mAIDriverComponent.m_TypeUID = UFG::AiDriverComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    p_mAIDriverComponent,
    pSimObj);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::Bind<UFG::SimObjectVehicle>(
    &this->mMoverComponent,
    pSimObj);
  if ( !registeredStaticEventHandlers_1 )
  {
    v9 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    v11 = UFG::TSVehicle::EntityDeathHandler;
    v10.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TSVehicle::EntityDeathHandler;
    if ( !UFG::TSVehicle::EntityDeathHandler )
      v9 = 0i64;
    v12 = v9;
    v10.m_Closure.m_pFunction = v9;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v10, 0x514B87Fu, 0i64, 0);
    registeredStaticEventHandlers_1 = 1;
  }
  this->bDelayedByNoDriver = 0;
}

// File Line: 2036
// RVA: 0x65EDB0
void __fastcall UFG::TSVehicle::UnlockDoors(UFG::TSVehicle *this, bool enable)
{
  LOBYTE(this->mMoverComponent.m_pSimComponent[14].m_SafePointerList.mNode.mNext) = !enable;
}

// File Line: 2045
// RVA: 0x64C920
void __fastcall UFG::TSVehicle::EntityDeathHandler(UFG::Event *thisEvent)
{
  UFG::SimObjectGame *mNext; // rbx
  __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax
  __int16 v4; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  mNext = (UFG::SimObjectGame *)thisEvent[1].mNext;
  if ( mNext )
  {
    m_Flags = mNext->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[4].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[3].m_pComponent;
      else
        m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                               ? mNext->m_Components.p[2].m_pComponent
                                               : UFG::SimObject::GetComponentOfType(
                                                   mNext,
                                                   UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[4].m_pComponent;
    }
    if ( m_pComponent
      && UFG::TSActorComponent::GetActor(m_pComponent)->i_class_p == UFG::TSVehicle::mClass
      && mNext->m_pSceneObj )
    {
      v4 = mNext->m_Flags;
      if ( (v4 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = mNext->m_Components.p[8].m_pComponent;
      }
      else if ( v4 >= 0 )
      {
        if ( (v4 & 0x2000) != 0 || (v4 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                mNext,
                                UFG::MissionFailConditionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mNext, UFG::MissionFailConditionComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = mNext->m_Components.p[8].m_pComponent;
      }
      if ( ComponentOfTypeHK )
      {
        if ( BYTE5(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev) )
          UFG::MissionFailConditionComponent::FailObject(mNext, &qSymbol_DeathFailCaption);
      }
    }
  }
}

// File Line: 2076
// RVA: 0x655F20
void __fastcall UFG::TSVehicle::Mthd_set_roll_stability(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    mPrev = m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      if ( (HIDWORD(mPrev[37].mNext) & 7) == 4 )
        LODWORD(mPrev[36].mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    }
  }
}

// File Line: 2097
// RVA: 0x655CF0
void __fastcall UFG::TSVehicle::Mthd_set_mass_scale_for_collisions(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::PhysicsVehicle *mPrev; // rcx
  float v5; // xmm2_4

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    mPrev = (UFG::PhysicsVehicle *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      v5 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      UFG::PhysicsVehicle::SetMassScaleForCollisions(mPrev, v5, v5);
    }
  }
}

// File Line: 2118
// RVA: 0x653710
void __fastcall UFG::TSVehicle::Mthd_clear_mass_scale_for_collisions(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  m_pSimComponent = this->mMoverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::PhysicsVehicle::ClearMassScaleForCollisions((UFG::PhysicsVehicle *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev);
}

// File Line: 2127
// RVA: 0x6554E0
void __fastcall UFG::TSVehicle::Mthd_set_avoid_peds(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8
  bool v4; // al

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
    if ( !LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mPrev) )
    {
      LOBYTE(m_pSimComponent[22].m_pSimObject) = v4;
      if ( !v4 )
        HIDWORD(m_pSimComponent[19].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 2132
// RVA: 0x655180
void __fastcall UFG::TSVehicle::Mthd_set_allowed_to_pass(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( !LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE1(m_pSimComponent[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2137
// RVA: 0x655FB0
void __fastcall UFG::TSVehicle::Mthd_set_stay_off_sidewalk(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( !LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE2(m_pSimComponent[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2142
// RVA: 0x655EB0
void __fastcall UFG::TSVehicle::Mthd_set_respect_speed_limit(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( !LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE3(m_pSimComponent[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2147
// RVA: 0x655D30
void __fastcall UFG::TSVehicle::Mthd_set_obey_traffic_lights(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( !LOBYTE(m_pSimComponent[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE4(m_pSimComponent[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2153
// RVA: 0x655580
void __fastcall UFG::TSVehicle::Mthd_set_can_turn_around(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r8

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( !m_pSimComponent->m_RoadRuleFlagsLocked )
      m_pSimComponent->m_bCanTurnAround = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2164
// RVA: 0x655D70
void __fastcall UFG::TSVehicle::Mthd_set_parked(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AiDriverComponent::SetParked(m_pSimComponent, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 2173
// RVA: 0x654D50
void __fastcall UFG::TSVehicle::Mthd_is_parked(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char v4; // cl
  UFG::SimComponent *m_pSimComponent; // rax

  if ( ppResult )
  {
    v4 = 1;
    m_pSimComponent = this->mAIDriverComponent.m_pSimComponent;
    if ( m_pSimComponent )
      v4 = BYTE1(m_pSimComponent[22].m_BoundComponentHandles.mNode.mNext);
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 2186
// RVA: 0x656050
void __fastcall UFG::TSVehicle::Mthd_set_usable_by_cop_system(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[17].m_pComponent;
    if ( m_pComponent )
      LOBYTE(m_pComponent[7].m_Flags) ^= (LOBYTE(m_pComponent[7].m_Flags) ^ (2
                                                                           * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 2;
  }
}

// File Line: 2196
// RVA: 0x6551C0
void __fastcall UFG::TSVehicle::Mthd_set_attacked_via_formation(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v4; // dl
  UFG::SimComponent *m_pComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
    {
      m_pComponent[30].m_TypeUID &= ~2u;
      m_pComponent[30].m_TypeUID |= 2 * v4;
      mPrev = m_pComponent[26].m_BoundComponentHandles.mNode.mPrev;
      if ( mPrev )
        BYTE4(mPrev[38].mPrev) = v4;
    }
  }
}

// File Line: 2212
// RVA: 0x655BE0
void __fastcall UFG::TSVehicle::Mthd_set_formation_slot_availability(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  const char **v5; // rbx
  SSInstance *i_data_p; // rsi
  bool v7; // r14
  CarCombat::Position v8; // edi
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rcx
  UFG::VehicleFormations *mPrev; // rcx

  i_array_p = pScope->i_data.i_array_p;
  v5 = CarCombat::mPositionName;
  i_data_p = (*i_array_p)->i_data_p;
  v7 = i_array_p[1]->i_data_p->i_user_data != 0;
  v8 = Follow;
  while ( stricmp(*(const char **)i_data_p->i_user_data, *v5) )
  {
    ++v5;
    ++v8;
    if ( (__int64)v5 >= (__int64)&CarStopTrack::sClassName )
      return;
  }
  if ( v8 != NumPositions )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
      if ( m_pComponent )
      {
        mPrev = (UFG::VehicleFormations *)m_pComponent[26].m_BoundComponentHandles.mNode.mPrev;
        if ( mPrev )
          UFG::VehicleFormations::SetSlotUsability(mPrev, v8, v7);
      }
    }
  }
}

// File Line: 2250
// RVA: 0x654C70
void __fastcall UFG::TSVehicle::Mthd_is_in_deep_water(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::PhysicsWheeledVehicle *v7; // rcx
  bool v8; // al

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( !m_pPointer )
      goto LABEL_9;
    m_pComponent = m_pPointer->m_Components.p[34].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_9;
    mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
    if ( !mPrev )
      goto LABEL_9;
    v7 = 0i64;
    if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
      v7 = (UFG::PhysicsWheeledVehicle *)mPrev;
    if ( v7 )
    {
      v8 = UFG::PhysicsWheeledVehicle::IsInDeepWater(v7);
      *ppResult = SSBoolean::pool_new(v8);
    }
    else
    {
LABEL_9:
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 2269
// RVA: 0x654B20
void __fastcall UFG::TSVehicle::Mthd_is_boat_in_water(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  char IsBoatInWater; // al

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    IsBoatInWater = 0;
    if ( m_pPointer )
      IsBoatInWater = UFG::SimObjectUtility::IsBoatInWater(m_pPointer);
    *ppResult = SSBoolean::pool_new(IsBoatInWater);
  }
}

// File Line: 2287
// RVA: 0x654D30
void __fastcall UFG::TSVehicle::Mthd_is_occupying_selected_stop(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(0);
}

// File Line: 2297
// RVA: 0x655220
void __fastcall UFG::TSVehicle::Mthd_set_audio_driver_type(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  UFG::VehicleAudioComponent *v5; // r8
  SSInstance *i_data_p; // r10
  unsigned __int64 i_user_data; // rcx
  _BYTE *v8; // rdx
  unsigned __int64 v9; // r9
  char *v10; // rcx
  unsigned __int64 v11; // rax
  _BYTE *v12; // rcx
  unsigned __int64 v13; // r9
  char *v14; // rdx
  unsigned __int64 v15; // rax
  _BYTE *v16; // rcx
  unsigned __int64 v17; // r9
  char *v18; // rdx
  unsigned __int64 v19; // rax
  _BYTE *v20; // rcx
  unsigned __int64 v21; // r9
  char *v22; // rdx
  unsigned __int64 v23; // rax
  _BYTE *v24; // rcx
  unsigned __int64 v25; // r9
  char *v26; // rdx
  unsigned __int64 v27; // rax
  _BYTE *v28; // rcx
  unsigned __int64 v29; // r9
  char *v30; // rdx
  unsigned __int64 v31; // rax
  _BYTE *v32; // rcx
  unsigned __int64 v33; // r9
  char *v34; // rdx

  m_pPointer = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    if ( v5 )
    {
      i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
      i_user_data = i_data_p->i_user_data;
      v8 = *(_BYTE **)i_user_data;
      v9 = *(unsigned int *)(i_user_data + 8) + *(_QWORD *)i_user_data + 1i64;
      if ( *(_QWORD *)i_user_data >= v9 )
      {
LABEL_7:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = eDriverType_Traffic;
      }
      else
      {
        v10 = (char *)("Traffic" - v8);
        while ( *v8 == v8[(_QWORD)v10] )
        {
          if ( (unsigned __int64)++v8 >= v9 )
            goto LABEL_7;
        }
      }
      v11 = i_data_p->i_user_data;
      v12 = *(_BYTE **)v11;
      v13 = *(unsigned int *)(v11 + 8) + *(_QWORD *)v11 + 1i64;
      if ( *(_QWORD *)v11 >= v13 )
      {
LABEL_12:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = eDriverType_Script;
      }
      else
      {
        v14 = (char *)("Script" - v12);
        while ( *v12 == v12[(_QWORD)v14] )
        {
          if ( (unsigned __int64)++v12 >= v13 )
            goto LABEL_12;
        }
      }
      v15 = i_data_p->i_user_data;
      v16 = *(_BYTE **)v15;
      v17 = *(unsigned int *)(v15 + 8) + *(_QWORD *)v15 + 1i64;
      if ( *(_QWORD *)v15 >= v17 )
      {
LABEL_17:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = eDriverType_Player;
      }
      else
      {
        v18 = (char *)("Player" - v16);
        while ( *v16 == v16[(_QWORD)v18] )
        {
          if ( (unsigned __int64)++v16 >= v17 )
            goto LABEL_17;
        }
      }
      v19 = i_data_p->i_user_data;
      v20 = *(_BYTE **)v19;
      v21 = *(unsigned int *)(v19 + 8) + *(_QWORD *)v19 + 1i64;
      if ( *(_QWORD *)v19 >= v21 )
      {
LABEL_22:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = eDriverType_PlayerPassenger;
      }
      else
      {
        v22 = (char *)("PlayerPassenger" - v20);
        while ( *v20 == v20[(_QWORD)v22] )
        {
          if ( (unsigned __int64)++v20 >= v21 )
            goto LABEL_22;
        }
      }
      v23 = i_data_p->i_user_data;
      v24 = *(_BYTE **)v23;
      v25 = *(unsigned int *)(v23 + 8) + *(_QWORD *)v23 + 1i64;
      if ( *(_QWORD *)v23 >= v25 )
      {
LABEL_27:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = eDriverType_Racer;
      }
      else
      {
        v26 = (char *)("Racer" - v24);
        while ( *v24 == v24[(_QWORD)v26] )
        {
          if ( (unsigned __int64)++v24 >= v25 )
            goto LABEL_27;
        }
      }
      v27 = i_data_p->i_user_data;
      v28 = *(_BYTE **)v27;
      v29 = *(unsigned int *)(v27 + 8) + *(_QWORD *)v27 + 1i64;
      if ( *(_QWORD *)v27 >= v29 )
      {
LABEL_32:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = eDriverType_Cop;
      }
      else
      {
        v30 = (char *)("Cop" - v28);
        while ( *v28 == v28[(_QWORD)v30] )
        {
          if ( (unsigned __int64)++v28 >= v29 )
            goto LABEL_32;
        }
      }
      v31 = i_data_p->i_user_data;
      v32 = *(_BYTE **)v31;
      v33 = *(unsigned int *)(v31 + 8) + *(_QWORD *)v31 + 1i64;
      if ( *(_QWORD *)v31 >= v33 )
      {
LABEL_37:
        v5->m_bOverrideDriverType = 0;
        v5->m_eOverridenDriverType = eDriverType_Uninitialized;
      }
      else
      {
        v34 = (char *)("Default" - v32);
        while ( *v32 == v32[(_QWORD)v34] )
        {
          if ( (unsigned __int64)++v32 >= v33 )
            goto LABEL_37;
        }
      }
    }
  }
}

// File Line: 2347
// RVA: 0x653260
void __fastcall UFG::TSVehicle::Mthd_add_steering_noise(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AiDriverComponent *v5; // rbx
  SSData **i_array_p; // rax
  float v7; // xmm6_4
  float m_fSteeringNoiseAmplitude; // xmm0_4

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    if ( v5 )
    {
      i_array_p = pScope->i_data.i_array_p;
      if ( (*i_array_p)->i_data_p->i_user_data )
      {
        v7 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
        UFG::AiDriverComponent::AddSteeringNoise(v5, v7);
        if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) )
        {
          v5->m_fSteeringNoiseAmplitudeMin = v7;
          m_fSteeringNoiseAmplitude = v5->m_fSteeringNoiseAmplitude;
          if ( m_fSteeringNoiseAmplitude <= v7 )
            m_fSteeringNoiseAmplitude = v7;
          v5->m_fSteeringNoiseAmplitude = m_fSteeringNoiseAmplitude;
        }
      }
      else
      {
        *(_QWORD *)&v5->m_fSteeringNoiseAmplitude = 0i64;
      }
    }
  }
}

// File Line: 2373
// RVA: 0x653310
void __fastcall UFG::TSVehicle::Mthd_attach_vehicle_across_street(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  UFG::SimObject *m_pSimObject; // rdi
  UFG::RoadNetworkGuide *p_mGuide; // rsi
  UFG::RoadNetworkLocation *Name; // rbx
  UFG::RoadNetworkNode *RoadNetworkNode; // rax
  UFG::RoadNetworkLane *m_CurrentLane; // r15
  double v10; // xmm6_8
  UFG::RoadNetworkSegment *v11; // rdi
  UFG::RoadNetworkLane *Lane; // r14
  UFG::RoadNetworkLane *v13; // rbp
  bool IsReversedInNode; // bl
  bool v15; // bl
  UFG::RoadNetworkLane *ClosestLaneToCenter; // rbx
  float laneT; // xmm0_4

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    if ( m_pComponent )
    {
      m_pSimObject = m_pComponent->m_pSimObject;
      if ( m_pSimObject )
        m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
      UFG::RoadSpaceComponent::AttachToRoadNetwork(m_pComponent, (UFG::qVector3 *)m_pSimObject[1].mNode.mChild, 0i64);
      p_mGuide = &m_pComponent->mGuide;
      Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&m_pComponent->mGuide);
      RoadNetworkNode = UFG::RoadNetworkLocation::GetRoadNetworkNode(Name);
      m_CurrentLane = Name->m_CurrentLane;
      *(_QWORD *)&v10 = LODWORD(Name->m_LaneT);
      v11 = (UFG::RoadNetworkSegment *)RoadNetworkNode;
      if ( RoadNetworkNode->mNumLanes > 1u && !RoadNetworkNode->mType.mValue )
      {
        Lane = UFG::RoadNetworkNode::GetLane(RoadNetworkNode, 0);
        v13 = UFG::RoadNetworkNode::GetLane(v11, (unsigned int)(unsigned __int8)v11->mNumLanes - 1);
        IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(v13);
        if ( UFG::RoadNetworkLane::IsReversedInNode(Lane) != IsReversedInNode )
        {
          v15 = UFG::RoadNetworkLane::IsReversedInNode(Lane);
          if ( v15 != UFG::RoadNetworkLane::IsReversedInNode(m_CurrentLane) )
            v13 = Lane;
          ClosestLaneToCenter = UFG::RoadNetworkSegment::GetClosestLaneToCenter(v11, v13->mLaneIndex);
          laneT = UFG::RoadNetworkSegment::GetMatchingT(
                    v11,
                    m_CurrentLane->mLaneIndex,
                    v10,
                    ClosestLaneToCenter->mLaneIndex);
          UFG::RoadNetworkGuide::AttachToNetwork(
            p_mGuide,
            p_mGuide->m_SimObj,
            v11,
            ClosestLaneToCenter->mLaneIndex,
            laneT);
        }
      }
    }
  }
}

// File Line: 2423
// RVA: 0x655DA0
void __fastcall UFG::TSVehicle::Mthd_set_prevent_hijack(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AiDriverComponent *m_pSimComponent; // r8

  m_pSimComponent = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_bDeniesHijack = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 2438
// RVA: 0x654DD0
void __fastcall UFG::TSVehicle::Mthd_is_vehicle_in_opposite_lane(
        UFG::TSVehicle *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::TransformNodeComponent *v4; // rbx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::RoadNetworkGuide *p_mNext; // rdi
  UFG::RoadNetworkLocation *Name; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0i64;
    if ( m_pPointer )
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    else
      m_pComponent = 0i64;
    if ( m_pPointer )
      v4 = (UFG::TransformNodeComponent *)m_pPointer->m_Components.p[2].m_pComponent;
    if ( m_pComponent )
    {
      if ( v4 )
      {
        p_mNext = (UFG::RoadNetworkGuide *)&m_pComponent[5].m_BoundComponentHandles.mNode.mNext;
        if ( m_pComponent != (UFG::SimComponent *)-376i64
          && UFG::RoadNetworkGuide::IsCurrentLocationValid((UFG::RoadNetworkGuide *)&m_pComponent[5].m_BoundComponentHandles.mNode.mNext) )
        {
          Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
          UFG::RoadNetworkLocation::GetTangent(Name, &result);
          UFG::TransformNodeComponent::UpdateWorldTransform(v4);
          *ppResult = SSBoolean::pool_new((float)((float)((float)(result.y * v4->mWorldTransform.v0.y)
                                                        + (float)(result.x * v4->mWorldTransform.v0.x))
                                                + (float)(result.z * v4->mWorldTransform.v0.z)) < 0.0);
        }
      }
    }
  }
}

