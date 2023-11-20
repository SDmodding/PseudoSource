// File Line: 84
// RVA: 0x6431C0
void __fastcall UFG::TSVehicle::TSVehicle(UFG::TSVehicle *this, ASymbol *name)
{
  UFG::TSVehicle *v2; // rbx

  v2 = this;
  UFG::TSActor::TSActor((UFG::TSActor *)&this->vfptr, name, UFG::TSVehicle::mClass);
  v2->vfptr = (SSObjectBaseVtbl *)&UFG::TSVehicle::`vftable';
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::RebindingComponentHandle<UFG::AiDriverComponent,0>(&v2->mAIDriverComponent);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&v2->mMoverComponent);
  v2->bDelayedByNoDriver = 0;
}

// File Line: 96
// RVA: 0x64F350
UFG::SimObjectVehicle *__fastcall UFG::TSVehicle::GetSafeSimObjectVehicle(UFG::TSVehicle *this)
{
  UFG::SimObjectVehicle *result; // rax

  result = (UFG::SimObjectVehicle *)this->mpComponent;
  if ( result )
    result = (UFG::SimObjectVehicle *)result->mNode.mParent;
  return result;
}

// File Line: 101
// RVA: 0x645840
void UFG::TSVehicle::BindAtomics(void)
{
  SSActorClass *v0; // rax
  SSActorClass *v1; // rcx
  SSActorClass *v2; // rcx
  SSActorClass *v3; // rcx
  SSActorClass *v4; // rcx
  SSActorClass *v5; // rcx
  SSActorClass *v6; // rcx
  SSActorClass *v7; // rcx
  SSActorClass *v8; // rcx
  SSActorClass *v9; // rcx
  SSActorClass *v10; // rcx
  SSActorClass *v11; // rcx
  SSActorClass *v12; // rcx
  SSActorClass *v13; // rcx
  SSActorClass *v14; // rcx
  SSActorClass *v15; // rcx
  SSActorClass *v16; // rcx
  SSActorClass *v17; // rcx
  SSActorClass *v18; // rcx
  SSActorClass *v19; // rcx
  SSActorClass *v20; // rcx
  SSActorClass *v21; // rcx
  SSActorClass *v22; // rcx
  SSActorClass *v23; // rcx
  SSActorClass *v24; // rcx
  SSActorClass *v25; // rcx
  SSActorClass *v26; // rcx
  SSActorClass *v27; // rcx
  SSActorClass *v28; // rcx
  SSActorClass *v29; // rcx
  SSActorClass *v30; // rcx
  SSActorClass *v31; // rcx
  SSActorClass *v32; // rcx
  SSActorClass *v33; // rcx
  SSActorClass *v34; // rcx
  SSActorClass *v35; // rcx
  SSActorClass *v36; // rcx
  SSActorClass *v37; // rcx
  SSActorClass *v38; // rcx
  SSActorClass *v39; // rcx
  SSActorClass *v40; // rcx
  SSActorClass *v41; // rcx
  SSActorClass *v42; // rcx
  SSActorClass *v43; // rcx
  SSActorClass *v44; // rcx
  SSActorClass *v45; // rcx
  SSActorClass *v46; // rcx
  SSActorClass *v47; // rcx
  SSActorClass *v48; // rcx
  SSActorClass *v49; // rcx
  SSActorClass *v50; // rcx
  SSActorClass *v51; // rcx
  SSActorClass *v52; // rcx
  SSActorClass *v53; // rcx
  SSActorClass *v54; // rcx
  SSActorClass *v55; // rcx
  SSActorClass *v56; // rcx
  SSActorClass *v57; // rcx
  SSActorClass *v58; // rcx
  SSActorClass *v59; // rcx
  SSActorClass *v60; // rcx
  SSActorClass *v61; // rcx
  SSActorClass *v62; // rcx
  SSActorClass *v63; // rcx
  SSActorClass *v64; // rcx
  SSActorClass *v65; // rcx
  SSActorClass *v66; // rcx
  SSActorClass *v67; // rcx
  SSActorClass *v68; // rcx
  SSActorClass *v69; // rcx
  SSActorClass *v70; // rcx
  SSActorClass *v71; // rcx
  SSActorClass *v72; // rcx
  SSActorClass *v73; // rcx
  SSActorClass *v74; // rcx
  SSActorClass *v75; // rcx
  SSActorClass *v76; // rcx
  SSActorClass *v77; // rcx
  SSActorClass *v78; // rcx
  SSActorClass *v79; // rcx
  SSActorClass *v80; // rcx
  SSActorClass *v81; // rcx
  SSActorClass *v82; // rcx
  SSActorClass *v83; // rcx
  SSActorClass *v84; // rcx
  SSActorClass *v85; // rcx
  SSActorClass *v86; // rcx
  SSActorClass *v87; // rcx
  SSActorClass *v88; // rcx
  SSActorClass *v89; // rcx
  SSActorClass *v90; // rcx
  SSActorClass *v91; // rcx
  SSActorClass *v92; // rcx
  SSActorClass *v93; // rcx
  SSActorClass *v94; // rcx
  SSActorClass *v95; // rcx
  SSActorClass *v96; // rcx
  SSActorClass *v97; // rcx
  SSActorClass *v98; // rcx
  SSActorClass *v99; // rcx
  SSActorClass *v100; // rcx
  SSActorClass *v101; // rcx
  SSActorClass *v102; // rcx
  SSActorClass *v103; // rcx
  SSActorClass *v104; // rcx
  SSActorClass *v105; // rcx
  SSActorClass *v106; // rcx
  SSActorClass *v107; // rcx
  SSActorClass *v108; // rcx
  SSActorClass *v109; // rcx
  SSActorClass *v110; // rcx
  SSActorClass *v111; // rcx
  SSActorClass *v112; // rcx
  SSActorClass *v113; // rcx
  SSActorClass *v114; // rcx
  SSActorClass *v115; // rcx
  SSActorClass *v116; // rcx
  SSActorClass *v117; // rcx
  SSActorClass *v118; // rcx
  SSActorClass *v119; // rcx
  SSActorClass *v120; // rcx
  SSActorClass *v121; // rcx
  SSActorClass *v122; // rcx
  SSActorClass *v123; // rcx
  SSActorClass *v124; // rcx
  SSActorClass *v125; // rcx
  SSActorClass *v126; // rcx
  SSActorClass *v127; // rcx
  SSActorClass *v128; // rcx
  SSActorClass *v129; // rcx
  SSActorClass *v130; // rcx
  SSActorClass *v131; // rcx
  SSActorClass *v132; // rcx
  __m128i v133; // [rsp+30h] [rbp-10h]

  v0 = (SSActorClass *)SSBrain::get_class("Vehicle");
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_mission_fail_condition_commit_changes;
  v133.m128i_i32[2] = 0;
  _mm_store_si128(&v133, v133);
  UFG::TSVehicle::mClass = v0;
  SSClass::register_method_mthd(
    (SSClass *)&v0->vfptr,
    "mission_fail_condition_commit_changes",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v1 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_despawn;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v1->vfptr,
    "despawn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v2 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_has_fail_conditions;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v2->vfptr,
    "has_fail_conditions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v3 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_enable_door_lock;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v3->vfptr,
    "enable_door_lock",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v4 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_mass_scale_for_collisions;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v4->vfptr,
    "set_mass_scaling_for_collisions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v5 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_clear_mass_scale_for_collisions;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v5->vfptr,
    "clear_mass_scaling_for_collisions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v6 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_roll_stability;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v6->vfptr,
    "set_roll_stability",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_stop;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v7 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_chase;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v7->vfptr,
    "chase",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v8 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_wander;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v8->vfptr,
    "wander",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v9 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_follow;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v9->vfptr,
    "follow",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v10 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_escort;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v10->vfptr,
    "escort",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v11 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_clear_driver;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v11->vfptr,
    "clear_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v12 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_create_ai_driver;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v12->vfptr,
    "create_ai_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v13 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_create_human_driver;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v13->vfptr,
    "create_human_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_slow_down_for_race_curvature;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "set_slow_down_for_race_curvature",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v14 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_avoid_objects_enabled;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v14->vfptr,
    "set_avoid_objects_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v15 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_avoid_geo_enabled;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v15->vfptr,
    "set_avoid_geo_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v16 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_road_speed_limit_scale;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v16->vfptr,
    "set_road_speed_limit_scale",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v17 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_desired_speed_limit_kph;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v17->vfptr,
    "set_desired_speed_limit_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v18 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_chase_speed_limit_kph;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v18->vfptr,
    "set_chase_speed_limit_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v19 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_override_speed_kph;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v19->vfptr,
    "override_speed_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v20 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_driving_role;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v20->vfptr,
    "set_driving_role",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v21 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_can_shove_cargo;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v21->vfptr,
    "set_can_shove_cargo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v22 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v22->vfptr,
    "create_sensor_phantom",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v23 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_race;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v23->vfptr,
    "set_race",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v24 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_steer_race;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v24->vfptr,
    "steer_race",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v25 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_start_racing;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v25->vfptr,
    "start_racing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v26 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_race_speed_limit;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v26->vfptr,
    "set_race_speed_limit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v27 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_race_index;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v27->vfptr,
    "get_race_index",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v28 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_race_point_index;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v28->vfptr,
    "get_race_point_index",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v29 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_race_time;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v29->vfptr,
    "get_race_time",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v30 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_catchup_target;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v30->vfptr,
    "set_katchup_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v31 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_clear_catchup_target;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v31->vfptr,
    "clear_katchup_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v32 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_force_dock;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v32->vfptr,
    "set_force_dock",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v33 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_countdown_time;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v33->vfptr,
    "get_countdown_time",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v34 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_countdown_time;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v34->vfptr,
    "set_countdown_time",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v35 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_fraction_race_complete;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v35->vfptr,
    "get_fraction_race_complete",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v36 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_race_proximity;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v36->vfptr,
    "get_race_proximity",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v37 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Coro_path_to_xform;
  _mm_store_si128(&v133, v133);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v37->vfptr,
    "_path_to_xform",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v133,
    0);
  v38 = UFG::TSVehicle::mClass;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Coro_stop_at;
  v133.m128i_i32[2] = 0;
  _mm_store_si128(&v133, v133);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v38->vfptr,
    "_stop_at",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v133,
    0);
  v39 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_take_camera;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v39->vfptr,
    "take_camera",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v40 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_follow_offset;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v40->vfptr,
    "follow_offset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v41 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_follow_debug;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v41->vfptr,
    "follow_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v42 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_avoidance_debug;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v42->vfptr,
    "avoidance_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v43 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_break_on_update;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v43->vfptr,
    "break_on_update",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v44 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_average_damage_rig_health;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v44->vfptr,
    "get_average_damage_rig_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v45 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_health_damage_rig;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v45->vfptr,
    "get_health_damage_rig",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_tire_damage;
  v46 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v46->vfptr,
    "set_tire_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v47 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_engine_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v47->vfptr,
    "set_engine_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v48 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_engine_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v48->vfptr,
    "get_engine_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v49 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_tire_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v49->vfptr,
    "get_tire_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v50 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_repair_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v50->vfptr,
    "repair_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v51 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v51->vfptr,
    "enable_highlight_tire",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v52 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_matching_class_type;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v52->vfptr,
    "is_of_class",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v53 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_driver;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v53->vfptr,
    "is_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_num_wheels;
  v133.m128i_i32[2] = 0;
  v54 = UFG::TSVehicle::mClass;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v54->vfptr,
    "get_num_wheels",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v55 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_num_wheels_off_ground;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v55->vfptr,
    "get_num_wheels_off_ground",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v56 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_upright;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v56->vfptr,
    "is_upright",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v57 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_flip;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v57->vfptr,
    "flip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v58 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_in_deep_water;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v58->vfptr,
    "is_in_deep_water",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v59 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_boat_in_water;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v59->vfptr,
    "is_boat_in_water",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v60 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_trail_xform;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v60->vfptr,
    "get_trail_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v61 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_total_distance_driven_km;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v61->vfptr,
    "get_total_distance_driven_km",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_road_speed_limit_kph;
  v133.m128i_i32[2] = 0;
  v62 = UFG::TSVehicle::mClass;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v62->vfptr,
    "get_road_speed_limit_kph",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v63 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_passenger;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v63->vfptr,
    "get_passenger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v64 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_driver;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v64->vfptr,
    "get_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v65 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_type;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v65->vfptr,
    "get_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v66 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_speed;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v66->vfptr,
    "get_speed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v67 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_linear_velocity_magnitude;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v67->vfptr,
    "get_linear_velocity_magnitude",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v68 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_multiplier;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v68->vfptr,
    "set_damage_multiplier",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v69 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_multiplier;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v69->vfptr,
    "set_damage_multiplier_world_coll",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_multiplier_vehicle_coll;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "set_damage_multiplier_vehicle_coll",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v70 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_multiplier_bullets;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v70->vfptr,
    "set_damage_multiplier_bullets",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v71 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_multiplier_attack;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v71->vfptr,
    "set_damage_multiplier_attack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v72 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_multiplier_tires;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v72->vfptr,
    "set_damage_multiplier_tires",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v73 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_disable_flapping_attachments;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v73->vfptr,
    "disable_flapping_attachments",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v74 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_grime_value;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v74->vfptr,
    "set_grime_value",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v75 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_take_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v75->vfptr,
    "set_vehicle_collision_min_impulse_required_to_take_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v76 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_min_impulse;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v76->vfptr,
    "set_vehicle_collision_damage_dealt_at_min_impulse",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_max_impulse;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "set_vehicle_collision_damage_dealt_at_max_impulse",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v77 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_deal_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v77->vfptr,
    "set_vehicle_collision_min_impulse_required_to_deal_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v78 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_vehicle_collision_max_impulse_for_dealing_damage;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v78->vfptr,
    "set_vehicle_collision_max_impulse_for_dealing_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v79 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_vehicle_collision_force_damage_dealer;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v79->vfptr,
    "set_vehicle_collision_force_damage_dealer",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v80 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_enable_horn;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v80->vfptr,
    "enable_horn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v81 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_enable_siren;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v81->vfptr,
    "enable_siren",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v82 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_enable_cop_lights;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v82->vfptr,
    "enable_cop_lights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v83 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_enable_head_lights;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v83->vfptr,
    "enable_head_lights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_queue_head_light_flashes;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "queue_head_light_flashes",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v84 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_start_radio;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v84->vfptr,
    "start_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v85 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_stop_radio;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v85->vfptr,
    "stop_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v86 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_radio_station;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v86->vfptr,
    "set_radio_station",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v87 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_radio_station;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v87->vfptr,
    "get_radio_station",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v88 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_set_radio_is_enabled;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v88->vfptr,
    "set_radio_is_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v89 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_set_shutdown_on_exit;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v89->vfptr,
    "set_shutdown_on_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v90 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_clear_playlist;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v90->vfptr,
    "clear_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_clear_recently_played;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "clear_recently_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v91 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_add_asset_to_playlist;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v91->vfptr,
    "add_asset_to_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v92 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_randomize_player_playlist;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v92->vfptr,
    "randomize_player_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v93 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_randomize_playlist;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v93->vfptr,
    "randomize_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v94 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_start_player_radio;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v94->vfptr,
    "start_player_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v95 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_stop_player_radio;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v95->vfptr,
    "stop_player_radio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v96 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_set_player_radio_station;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v96->vfptr,
    "set_player_radio_station",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v97 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_clear_player_playlist;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v97->vfptr,
    "clear_player_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_clear_player_recently_played;
  v133.m128i_i32[2] = 0;
  v98 = UFG::TSVehicle::mClass;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v98->vfptr,
    "clear_player_recently_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v99 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_add_asset_to_player_playlist;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v99->vfptr,
    "add_asset_to_player_playlist",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v100 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_player_radio_next_track;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v100->vfptr,
    "player_radio_next_track",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v101 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_avoid_peds;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v101->vfptr,
    "set_avoid_peds",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v102 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_allowed_to_pass;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v102->vfptr,
    "set_allowed_to_pass",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v103 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_stay_off_sidewalk;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v103->vfptr,
    "set_stay_off_sidewalk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v104 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_respect_speed_limit;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v104->vfptr,
    "set_respect_speed_limit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v105 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_obey_traffic_lights;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v105->vfptr,
    "set_obey_traffic_lights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_can_turn_around;
  v106 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v106->vfptr,
    "set_can_turn_around",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v107 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_init_audio;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v107->vfptr,
    "init_audio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v108 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_enable_player_control;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v108->vfptr,
    "enable_player_control",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v109 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_number_seats;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v109->vfptr,
    "get_number_seats",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v110 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_number_occupants;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v110->vfptr,
    "get_number_occupants",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v111 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_reload_physics_property_set;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v111->vfptr,
    "reload_physics",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v112 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_matching_class_type;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v112->vfptr,
    "is_matching_class_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v113 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_reset_to_last_good;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v113->vfptr,
    "reset_to_last_good",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_cannot_explode;
  v133.m128i_i32[2] = 0;
  v114 = UFG::TSVehicle::mClass;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v114->vfptr,
    "set_cannotexplode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v115 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_trigger_explosion;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v115->vfptr,
    "trigger_explosion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v116 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_damage_marker;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v116->vfptr,
    "set_damage_marker",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v117 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_all_damage_markers;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v117->vfptr,
    "set_all_damage_markers",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v118 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_get_vandalized_amount;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v118->vfptr,
    "get_vandalized_amount",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v119 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_usable_by_cop_system;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v119->vfptr,
    "set_usable_by_cop_system",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v120 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_attacked_via_formation;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v120->vfptr,
    "set_attacked_via_formation",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v121 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_formation_slot_availability;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v121->vfptr,
    "set_formation_slot_availability",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_parked;
  v133.m128i_i32[2] = 0;
  v122 = UFG::TSVehicle::mClass;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v122->vfptr,
    "set_parked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v123 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_parked;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v123->vfptr,
    "is_parked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v124 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_occupying_selected_stop;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v124->vfptr,
    "is_occupying_selected_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v125 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_is_vehicle_in_opposite_lane;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v125->vfptr,
    "is_vehicle_in_opposite_lane",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v126 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_prevent_hijack;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v126->vfptr,
    "set_prevent_hijack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v127 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_audio_driver_type;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v127->vfptr,
    "set_audio_driver_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v128 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v128->vfptr,
    "enable_triggering_boost_regions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v129 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_add_steering_noise;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v129->vfptr,
    "add_steering_noise",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_attach_vehicle_across_street;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::TSVehicle::mClass->vfptr,
    "attach_vehicle_across_street",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v130 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::MthdC_get_instances_of_type;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v130->vfptr,
    "get_instances_of_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    1,
    0);
  v131 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSVehicle::Mthd_set_untargetable;
  _mm_store_si128(&v133, v133);
  SSClass::register_method_mthd(
    (SSClass *)&v131->vfptr,
    "set_untargetable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v133,
    0);
  v132 = UFG::TSVehicle::mClass;
  v133.m128i_i32[2] = 0;
  v133.m128i_i64[0] = (__int64)UFG::TSActor::Coro_raycast_to_target;
  _mm_store_si128(&v133, v133);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v132->vfptr,
    "_raycast_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v133,
    0);
}to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v133,
    0);
}

// File Line: 276
// RVA: 0x656020
void __fastcall UFG::TSVehicle::Mthd_set_untargetable(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mMoverComponent.m_pSimComponent;
  if ( v3 )
    BYTE1(v3[14].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 290
// RVA: 0x6534D0
void __fastcall UFG::TSVehicle::Mthd_cannot_explode(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *v3; // rcx

  v3 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( v3 )
    UFG::PhysicsMoverInterface::SetCannotExplode(v3, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 304
// RVA: 0x656500
void __fastcall UFG::TSVehicle::Mthd_trigger_explosion(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(this->mMoverComponent.m_pSimComponent, 0i64, UFG::PhysicsMoverInterface::TriggerExplosion);
}

// File Line: 317
// RVA: 0x655100
void __fastcall UFG::TSVehicle::Mthd_set_all_damage_markers(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInvokedMethod *v4; // r11
  UFG::VehicleEffectsComponent *v5; // rdx
  DamageRig *v6; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
    if ( v5 )
    {
      v6 = v5->mDamageRig;
      if ( v6 )
        DamageRig::SetAllDamageMarkers(
          v6,
          v5,
          *(float *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64,
          *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64);
    }
  }
}

// File Line: 336
// RVA: 0x652A10
void __fastcall UFG::TSVehicle::MthdC_get_instances_of_type(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // r14
  SSList *v4; // rsi
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> **i; // rbx
  UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> *v6; // rdi
  UFG::TSActorComponent *v7; // rcx
  UFG::TSActor *v8; // rax
  UFG::qSymbol targetClassType; // [rsp+60h] [rbp+18h]
  SSList *v10; // [rsp+68h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
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
    for ( i = &UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList.mNode.mNext[-10].mNext;
          i != (UFG::qNode<UFG::SimObjectVehiclePropertiesComponent,UFG::SimObjectVehiclePropertiesComponent> **)((char *)&UFG::SimObjectVehiclePropertiesComponent::s_SimObjectVehiclePropertiesComponentList - 152);
          i = &i[20][-10].mNext )
    {
      v6 = i[5];
      if ( UFG::SimObjectUtility::IsClassType((UFG::SimObject *)i[5], &targetClassType) )
      {
        if ( v6 )
        {
          v7 = (UFG::TSActorComponent *)v6[6].mNext[4].mPrev;
          if ( v7 )
          {
            v8 = UFG::TSActorComponent::GetActor(v7);
            if ( v8 )
              SSList::append(v4, (SSInstance *)&v8->vfptr, 1);
          }
        }
      }
    }
    *v3 = SSList::as_instance(v4);
  }
}

// File Line: 373
// RVA: 0x653D90
void __fastcall UFG::TSVehicle::Mthd_flip(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r9
  UFG::TSVehicle *v4; // rbx
  SSData **v5; // r8
  UFG::PhysicsWheeledVehicle *v6; // rcx
  SSInstance *v7; // rdx
  SSData *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // r8
  float v10; // xmm6_4
  UFG::PhysicsMoverInterface *v11; // rcx
  UFG::qVector3 collisionPoint; // [rsp+20h] [rbp-68h]
  UFG::qMatrix44 mat; // [rsp+30h] [rbp-58h]

  v3 = this->mMoverComponent.m_pSimComponent;
  v4 = this;
  if ( v3 )
  {
    v5 = pScope->i_data.i_array_p;
    v6 = 0i64;
    v7 = (*v5)->i_data_p;
    v8 = v5[1];
    v9 = v3[10].m_SafePointerList.mNode.mPrev;
    v10 = *(float *)&v8->i_data_p->i_user_data;
    if ( v9 )
    {
      if ( (BYTE4(v9[37].mNext) & 7) == 4 )
        v6 = (UFG::PhysicsWheeledVehicle *)v3[10].m_SafePointerList.mNode.mPrev;
    }
    UFG::PhysicsWheeledVehicle::GetWheelMatrix(v6, v7->i_user_data, &mat);
    v11 = (UFG::PhysicsMoverInterface *)v4->mMoverComponent.m_pSimComponent;
    collisionPoint = *(UFG::qVector3 *)&mat.v3.x;
    UFG::PhysicsMoverInterface::FlipVehicle(v11, v10, &collisionPoint);
  }
}

// File Line: 394
// RVA: 0x6557D0
void __fastcall UFG::TSVehicle::Mthd_set_damage_marker(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::VehicleEffectsComponent *v4; // rbp
  DamageRig *v5; // r14
  AStringRef *v6; // rbx
  SSData **v7; // r8
  float v8; // xmm6_4
  bool suppress_effects; // si
  bool affect_triggers; // di
  unsigned int v11; // eax
  bool v12; // zf
  AObjReusePool<AStringRef> *v13; // rax
  AObjBlock<AStringRef> *v14; // rcx
  unsigned __int64 v15; // r8
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v17; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
    if ( v4 )
    {
      v5 = v4->mDamageRig;
      if ( v5 )
      {
        v6 = (AStringRef *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
        ++v6->i_ref_count;
        v7 = pScope->i_data.i_array_p;
        v8 = *(float *)&v7[1]->i_data_p->i_user_data;
        suppress_effects = v7[2]->i_data_p->i_user_data != 0;
        affect_triggers = v7[3]->i_data_p->i_user_data != 0;
        v11 = UFG::qStringHashUpper32(v6->i_cstr_p, 0xFFFFFFFF);
        DamageRig::SetDamageMarker(v5, v4, v11, v8, affect_triggers, suppress_effects);
        v12 = v6->i_ref_count-- == 1;
        if ( v12 )
        {
          if ( v6->i_deallocate )
            AMemory::c_free_func(v6->i_cstr_p);
          v13 = AStringRef::get_pool();
          v14 = v13->i_block_p;
          v15 = (unsigned __int64)v14->i_objects_a;
          if ( (unsigned __int64)v6 < v15
            || (v16 = (unsigned __int64)v6 < v15 + 24i64 * v14->i_size, v17 = &v13->i_pool, !v16) )
          {
            v17 = &v13->i_exp_pool;
          }
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v17, v6);
        }
      }
    }
  }
}

// File Line: 419
// RVA: 0x654A60
void __fastcall UFG::TSVehicle::Mthd_get_vandalized_amount(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && ppResult )
  {
    v4 = v3->m_Components.p[32].m_pComponent;
    if ( v4 )
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)&v4[28].m_Flags);
  }
}

// File Line: 437
// RVA: 0x654F70
void __fastcall UFG::TSVehicle::Mthd_reload_physics_property_set(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v3; // eax
  UFG::qSymbol propertySetName; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v5; // [rsp+48h] [rbp+10h]

  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( this->mMoverComponent.m_pSimComponent )
  {
    v5 = &propertySetName;
    propertySetName.mUID = v3;
    UFG::PhysicsMoverInterface::Reload(
      (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent,
      RELOAD_NAMED,
      (__int64)&propertySetName);
  }
}

// File Line: 447
// RVA: 0x654CF0
void __fastcall UFG::TSVehicle::Mthd_is_matching_class_type(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  char v4; // al

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::SimObjectUtility::IsClassType(
           this->mpSimObj.m_pPointer,
           (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 457
// RVA: 0x654FE0
void __fastcall UFG::TSVehicle::Mthd_reset_to_last_good(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rdx
  int v4; // xmm1_4
  int v5; // xmm0_4
  int v6; // xmm1_4
  int v7; // xmm0_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  int v10; // xmm1_4
  int v11; // xmm0_4
  int v12; // xmm1_4
  int v13; // xmm0_4
  int v14; // xmm1_4
  int v15; // xmm0_4
  int v16; // xmm1_4
  int v17; // xmm0_4
  int v18; // xmm1_4
  int v19; // [rsp+20h] [rbp-48h]
  int v20; // [rsp+24h] [rbp-44h]
  int v21; // [rsp+28h] [rbp-40h]
  int v22; // [rsp+2Ch] [rbp-3Ch]
  int v23; // [rsp+30h] [rbp-38h]
  int v24; // [rsp+34h] [rbp-34h]
  int v25; // [rsp+38h] [rbp-30h]
  int v26; // [rsp+3Ch] [rbp-2Ch]
  int v27; // [rsp+40h] [rbp-28h]
  int v28; // [rsp+44h] [rbp-24h]
  int v29; // [rsp+48h] [rbp-20h]
  int v30; // [rsp+4Ch] [rbp-1Ch]
  int v31; // [rsp+50h] [rbp-18h]
  int v32; // [rsp+54h] [rbp-14h]
  int v33; // [rsp+58h] [rbp-10h]
  int v34; // [rsp+5Ch] [rbp-Ch]

  if ( this->mMoverComponent.m_pSimComponent )
  {
    v3 = this->mMoverComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( v3 )
    {
      v4 = HIDWORD(v3[12].mPrev);
      v19 = (int)v3[12].mPrev;
      v5 = (int)v3[12].mNext;
      v20 = v4;
      v6 = HIDWORD(v3[12].mNext);
      v21 = v5;
      v7 = (int)v3[13].mPrev;
      v22 = v6;
      v8 = HIDWORD(v3[13].mPrev);
      v23 = v7;
      v9 = (int)v3[13].mNext;
      v24 = v8;
      v10 = HIDWORD(v3[13].mNext);
      v25 = v9;
      v11 = (int)v3[14].mPrev;
      v26 = v10;
      v12 = HIDWORD(v3[14].mPrev);
      v27 = v11;
      v13 = (int)v3[14].mNext;
      v28 = v12;
      v14 = HIDWORD(v3[14].mNext);
      v29 = v13;
      v15 = (int)v3[15].mPrev;
      v30 = v14;
      v16 = HIDWORD(v3[15].mPrev);
      v31 = v15;
      v17 = (int)v3[15].mNext;
      v32 = v16;
      v18 = HIDWORD(v3[15].mNext);
      v33 = v17;
      v34 = v18;
      UFG::TSActor::TeleportToTransform((UFG::TSActor *)&this->vfptr, (UFG::qMatrix44 *)&v19);
    }
  }
}

// File Line: 474
// RVA: 0x653A60
void __fastcall UFG::TSVehicle::Mthd_enable_player_control(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::TSVehicle *v4; // rdi
  UFG::VehicleDriverInterface *v5; // rbx
  SSData **v6; // r8
  UFG::PhysicsMoverInterface *v7; // rcx
  UFG::PhysicsMoverInterface *v8; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = this;
  if ( v3 )
    v5 = (UFG::VehicleDriverInterface *)v3->m_Components.p[23].m_pComponent;
  else
    v5 = 0i64;
  v6 = pScope->i_data.i_array_p;
  if ( (*v6)->i_data_p->i_user_data )
  {
    if ( v5 )
      UFG::VehicleDriverInterface::SetDesiredState(v5, (UFG::VehicleState)2);
  }
  else
  {
    if ( v6[1]->i_data_p->i_user_data )
    {
      v7 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
      if ( v7 )
        UFG::PhysicsMoverInterface::OverrideSuperStopDrag(v7, 1, *(float *)&v6[2]->i_data_p->i_user_data);
    }
    v8 = (UFG::PhysicsMoverInterface *)v4->mMoverComponent.m_pSimComponent;
    if ( v8 )
      UFG::PhysicsMoverInterface::EnableSuperStop(v8);
    if ( v5 )
      UFG::VehicleDriverInterface::SetDesiredState(v5, (UFG::VehicleState)4);
  }
}

// File Line: 509
// RVA: 0x654EB0
void __fastcall UFG::TSVehicle::Mthd_mission_fail_condition_commit_changes(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // r9
  SSInstance *v4; // rcx

  v3 = this;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v4 )
    v4 = (SSInstance *)((char *)v4 - 24);
  UFG::MissionFailConditionComponent::HandleAttachment(
    *(UFG::GameSlice **)&v4[3].i_ptr_id,
    v3->mpSimObj.m_pPointer,
    0i64);
}

// File Line: 515
// RVA: 0x654AB0
void __fastcall UFG::TSVehicle::Mthd_has_fail_conditions(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 )
      v3 = (UFG::SimObject *)v3->m_Components.p[8].m_pComponent;
    *ppResult = (SSInstance *)SSBoolean::pool_new(v3 != 0i64);
  }
}

// File Line: 524
// RVA: 0x653820
void __fastcall UFG::TSVehicle::Mthd_despawn(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rbx
  unsigned __int16 v4; // cx
  UFG::StreamedResourceComponent *v5; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(*pScope->i_data.i_array_p)->i_data_p->i_user_data
      || ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::StreamedResourceComponent::_TypeUID)) : (v5 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::StreamedResourceComponent::_TypeUID))) : (v5 = (UFG::StreamedResourceComponent *)v3->m_Components.p[7].m_pComponent)) : (v5 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent)) : (v5 = (UFG::StreamedResourceComponent *)v3->m_Components.p[10].m_pComponent),
          UFG::StreamedResourceComponent::GetSpawnPriority(v5, 0i64)->mUID != qSymbol_Critical.mUID) )
    {
      UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)&v3->vfptr);
    }
  }
}

// File Line: 556
// RVA: 0x653950
void __fastcall UFG::TSVehicle::Mthd_enable_door_lock(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  LOBYTE(this->mMoverComponent.m_pSimComponent[14].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 567
// RVA: 0x654500
void __fastcall UFG::TSVehicle::Mthd_get_number_seats(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rbx
  UFG::VehicleOccupantComponent *v5; // rcx
  unsigned __int64 v6; // rdx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 && (v5 = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent) != 0i64 )
      v6 = (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfSeats(v5);
    else
      v6 = 0i64;
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 589
// RVA: 0x6544B0
void __fastcall UFG::TSVehicle::Mthd_get_number_occupants(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rbx
  UFG::VehicleOccupantComponent *v5; // rcx
  unsigned int v6; // eax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
      v5 = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent;
    else
      v5 = 0i64;
    v6 = UFG::VehicleOccupantComponent::GetNumberOfOccupants(v5);
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 604
// RVA: 0x6541B0
void __fastcall UFG::TSVehicle::Mthd_get_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rbx
  hkSimpleLocalFrame *v5; // rcx
  UFG::SimObject *v6; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 && (v5 = (hkSimpleLocalFrame *)v3->m_Components.p[30].m_pComponent) != 0i64 )
    {
      v6 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v5);
      *v4 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v6);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 623
// RVA: 0x654550
void __fastcall UFG::TSVehicle::Mthd_get_passenger(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rbx
  UFG::VehicleOccupantComponent *v5; // rcx
  UFG::SimObject *v6; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 && (v5 = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent) != 0i64 )
    {
      v6 = UFG::VehicleOccupantComponent::GetPassenger(v5, (*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
      *v4 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v6);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 636
// RVA: 0x6547B0
void __fastcall UFG::TSVehicle::Mthd_get_road_speed_limit_kph(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax
  __int64 v4; // rax
  signed __int64 v5; // rax
  float v6; // xmm0_4

  if ( ppResult )
  {
    v3 = this->mAIDriverComponent.m_pSimComponent;
    if ( v3 )
    {
      v4 = *(_QWORD *)&v3[5].m_TypeUID;
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
void __fastcall UFG::TSVehicle::Mthd_get_total_distance_driven_km(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      *ppResult = SSInstance::pool_new(
                    SSBrain::c_real_class_p,
                    COERCE_UNSIGNED_INT(*(float *)&v4[10].m_BoundComponentHandles.mNode.mNext * 0.001));
  }
}

// File Line: 663
// RVA: 0x654950
void __fastcall UFG::TSVehicle::Mthd_get_type(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectVehiclePropertiesComponent *v5; // rax
  UFG::eSimObjectVehicleTypeEnum v6; // eax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v3);
      if ( v5 )
      {
        v6 = v5->m_eSimObjectVehicleType;
        switch ( v6 )
        {
          case 7:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Minibus);
            break;
          case 2:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Car);
            break;
          case 5:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Truck);
            break;
          case 4:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Van);
            break;
          case 1:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Bike);
            break;
          case 6:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Scooter);
            break;
          case 3:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Boat_21);
            break;
          case 9:
            *v4 = SSSymbol::as_instance((ASymbol *)&qSymbol_Tram);
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
  UFG::SimComponent *v3; // rax

  if ( ppResult )
  {
    v3 = this->mMoverComponent.m_pSimComponent;
    if ( v3 )
      *ppResult = SSInstance::pool_new(
                    SSBrain::c_real_class_p,
                    COERCE_UNSIGNED_INT(3.5999999 * *((float *)&v3[10].m_BoundComponentHandles.mNode.mPrev + 1)));
  }
}

// File Line: 719
// RVA: 0x654370
void __fastcall UFG::TSVehicle::Mthd_get_linear_velocity_magnitude(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *v3; // rcx
  SSInstance **v4; // rbx
  float user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      user_data = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v3);
      *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
    }
  }
}

// File Line: 727
// RVA: 0x655A00
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      HIDWORD(v4[10].m_BoundComponentHandles.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 750
// RVA: 0x6559C0
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_vehicle_coll(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      LODWORD(v4[11].vfptr) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 759
// RVA: 0x6561F0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_take_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      HIDWORD(v4[13].vfptr) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 768
// RVA: 0x6560E0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_min_impulse(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      LODWORD(v4[13].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 777
// RVA: 0x6560A0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_damage_dealt_at_max_impulse(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      HIDWORD(v4[13].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 786
// RVA: 0x6561B0
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_min_impulse_required_to_deal_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::PhysicsMoverInterface *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      v4->mVehicleCollisionMinImpulseRequiredToDealDamage = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 795
// RVA: 0x656170
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_max_impulse_for_dealing_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      *(_DWORD *)&v4[13].m_Flags = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 804
// RVA: 0x656120
void __fastcall UFG::TSVehicle::Mthd_set_vehicle_collision_force_damage_dealer(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  bool v4; // dl
  UFG::SimComponent *v5; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = v3->m_Components.p[34].m_pComponent;
    if ( v5 )
    {
      BYTE4(v5[14].vfptr) &= 0xFEu;
      BYTE4(v5[14].vfptr) |= v4;
    }
  }
}

// File Line: 815
// RVA: 0x655940
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_bullets(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      LODWORD(v4[11].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 826
// RVA: 0x655900
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_attack(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::PhysicsMoverInterface *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      v4->mDamageMultiplierAttack = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 837
// RVA: 0x655980
void __fastcall UFG::TSVehicle::Mthd_set_damage_multiplier_tires(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[34].m_pComponent;
    if ( v4 )
      HIDWORD(v4[11].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 848
// RVA: 0x6538E0
void __fastcall UFG::TSVehicle::Mthd_disable_flapping_attachments(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::CarPhysicsMoverComponent *v4; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(v3);
    if ( v4 )
      UFG::CarPhysicsMoverComponent::DisableFlappingAttachments(v4);
  }
}

// File Line: 857
// RVA: 0x655CB0
void __fastcall UFG::TSVehicle::Mthd_set_grime_value(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[32].m_pComponent;
    if ( v4 )
      LODWORD(v4[28].m_BoundComponentHandles.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 873
// RVA: 0x654910
void __fastcall UFG::TSVehicle::Mthd_get_trail_xform(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::TransformNodeComponent *v4; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::VehicleUtility::GetChaseSpawnTransform(this->mpSimObj.m_pPointer, 20.0);
    *v3 = UFG::TSTransform::AsInstance(v4);
  }
}

// File Line: 900
// RVA: 0x654B60
void __fastcall UFG::TSVehicle::Mthd_is_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rsi
  SSInstance **v4; // rdi
  bool v5; // bl
  UFG::TSActor *v6; // rax
  UFG::SimObject *v7; // rcx
  UFG::SimComponent *v8; // rcx
  UFG::SimObjectGame *v9; // rcx
  UFG::SimComponent *v10; // rax
  unsigned __int16 v11; // dx

  if ( ppResult )
  {
    v3 = this;
    v4 = ppResult;
    v5 = 0;
    v6 = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
    v7 = v3->mpSimObj.m_pPointer;
    if ( v7 )
    {
      v8 = v7->m_Components.p[23].m_pComponent;
      if ( v8 )
      {
        v9 = (UFG::SimObjectGame *)v8[3].m_BoundComponentHandles.mNode.mNext;
        if ( (UFG::SimObjectGame *)v6->mpSimObj.m_pPointer == v9 )
        {
          if ( v9 )
          {
            v11 = v9->m_Flags;
            if ( (v11 >> 14) & 1 )
            {
              v10 = v9->m_Components.p[44].m_pComponent;
            }
            else if ( (v11 & 0x8000u) == 0 )
            {
              if ( (v11 >> 13) & 1 )
              {
                v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
              }
              else if ( (v11 >> 12) & 1 )
              {
                v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
              }
              else
              {
                v10 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v9->vfptr,
                        UFG::CharacterOccupantComponent::_TypeUID);
              }
            }
            else
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::CharacterOccupantComponent::_TypeUID);
            }
          }
          else
          {
            v10 = 0i64;
          }
          v5 = LODWORD(v10[1].m_SafePointerList.mNode.mNext) == 4
            && !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v10);
        }
      }
    }
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 927
// RVA: 0x6543B0
void __fastcall UFG::TSVehicle::Mthd_get_num_wheels(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Components.p[34].m_pComponent;
      if ( v4 )
      {
        v5 = v4[10].m_SafePointerList.mNode.mPrev;
        if ( v5 )
        {
          v6 = 0i64;
          if ( BYTE4(v5[37].mNext) & 7 )
            v6 = v5;
          if ( v6 )
            *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, HIDWORD(v6[37].mNext) & 7);
        }
      }
    }
  }
}

// File Line: 945
// RVA: 0x654420
void __fastcall UFG::TSVehicle::Mthd_get_num_wheels_off_ground(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rdi
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  int v8; // ebx
  unsigned int v9; // eax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      v5 = v3->m_Components.p[34].m_pComponent;
      if ( v5 )
      {
        v6 = v5[10].m_SafePointerList.mNode.mPrev;
        if ( v6 )
        {
          v7 = 0i64;
          if ( BYTE4(v6[37].mNext) & 7 )
            v7 = v6;
          if ( v7 )
          {
            v8 = HIDWORD(v7[37].mNext) & 7;
            if ( v8 >= 0 )
            {
              v9 = UFG::PhysicsWheeledVehicle::GetNumWheelsOnGround((UFG::PhysicsWheeledVehicle *)v7);
              if ( v9 <= v8 )
                *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v8 - v9);
            }
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
  SSInstance **v3; // rbx
  int v4; // eax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::VehicleUtility::GetVehicleOrientation((UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer, 0, 0i64);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4 == 0);
  }
}

// File Line: 984
// RVA: 0x654010
void __fastcall UFG::TSVehicle::Mthd_get_average_damage_rig_health(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rbx
  float v5; // xmm2_4
  UFG::SimComponent *v6; // rdx
  UFG::SimObject *v7; // rdx
  signed int v8; // er8
  unsigned int v9; // er10
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  unsigned int v12; // eax
  __int64 v13; // r9
  signed __int64 v14; // rdx
  __int64 v15; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = 0.0;
    if ( v3 )
    {
      v6 = v3->m_Components.p[32].m_pComponent;
      if ( v6 )
      {
        v7 = v6[28].m_pSimObject;
        if ( v7 )
        {
          v8 = HIDWORD(v7->vfptr);
          v9 = 0;
          v10 = 0i64;
          if ( v8 >= 4 )
          {
            v11 = (signed __int64)&v7->m_SafePointerList.mNode.mNext[3].mPrev + 4;
            v12 = ((unsigned int)(v8 - 4) >> 2) + 1;
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
          if ( v9 < v8 )
          {
            v14 = (signed __int64)&v7->m_SafePointerList.mNode.mNext[3 * v10].mPrev + 4;
            v15 = v8 - v9;
            do
            {
              v14 += 48i64;
              v5 = v5 + (float)(1.0 - *(float *)(v14 - 48));
              --v15;
            }
            while ( v15 );
          }
          v5 = v5 / (float)v8;
        }
      }
    }
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v5));
  }
}

// File Line: 1014
// RVA: 0x6542D0
void __fastcall UFG::TSVehicle::Mthd_get_health_damage_rig(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  float v4; // xmm6_4
  SSInstance **v5; // rbx
  UFG::SimComponent *v6; // rcx
  DamageRig *v7; // rcx
  float health_output; // [rsp+50h] [rbp+18h]
  unsigned __int64 user_data; // [rsp+58h] [rbp+20h]

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0.0;
    v5 = ppResult;
    health_output = 0.0;
    if ( v3 )
    {
      v6 = v3->m_Components.p[32].m_pComponent;
      if ( v6 )
      {
        v7 = (DamageRig *)v6[28].m_pSimObject;
        if ( v7 )
        {
          DamageRig::GetTriggerMarkerHealth(v7, (*pScope->i_data.i_array_p)->i_data_p->i_user_data, &health_output);
          if ( (float)(1.0 - health_output) > 0.0 )
            v4 = 1.0 - health_output;
          health_output = v4;
        }
      }
    }
    *(float *)&user_data = v4;
    *v5 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 1046
// RVA: 0x655B80
void __fastcall UFG::TSVehicle::Mthd_set_engine_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *v3; // rcx

  v3 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( v3 )
    UFG::PhysicsMoverInterface::SetDamageStateEngineDamage(
      v3,
      *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1068
// RVA: 0x654200
void __fastcall UFG::TSVehicle::Mthd_get_engine_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *v3; // rcx
  SSInstance **v4; // rbx
  float user_data; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    v4 = ppResult;
    if ( v3 )
    {
      user_data = UFG::PhysicsMoverInterface::GetEngineDamage(v3);
      *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
    }
  }
}

// File Line: 1081
// RVA: 0x655FF0
void __fastcall UFG::TSVehicle::Mthd_set_tire_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *v3; // rcx

  v3 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
  if ( v3 )
    UFG::PhysicsMoverInterface::DamageTire(v3, 0i64, (*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1.0);
}

// File Line: 1123
// RVA: 0x654870
void __fastcall UFG::TSVehicle::Mthd_get_tire_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhysicsMoverInterface *v3; // rcx
  SSInstance **v4; // rbx
  SSInstance *v5; // rax
  bool v6; // al

  if ( ppResult )
  {
    v3 = (UFG::PhysicsMoverInterface *)this->mMoverComponent.m_pSimComponent;
    v4 = ppResult;
    v5 = (*pScope->i_data.i_array_p)->i_data_p;
    if ( v3 )
    {
      v6 = UFG::PhysicsMoverInterface::IsTireBlown(v3, v5->i_user_data);
      *v4 = (SSInstance *)SSBoolean::pool_new(v6);
    }
  }
}

// File Line: 1140
// RVA: 0x654FC0
void __fastcall UFG::TSVehicle::Mthd_repair_damage(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(this->mMoverComponent.m_pSimComponent, 0i64, UFG::PhysicsMoverInterface::RepairDamage);
}

// File Line: 1149
// RVA: 0x656520
void __fastcall UFG::TSVehicle::Mthd_wander(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::SimComponent *v5; // rcx
  SSData **v6; // rax
  unsigned int v7; // edx
  UFG::SimComponent *v8; // rax

  v3 = this;
  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) )
    {
      v4 = this->mpSimObj.m_pPointer;
      if ( v4 )
      {
        v5 = v4->m_Components.p[24].m_pComponent;
        if ( v5 )
          LODWORD(v5[30].m_SafePointerList.mNode.mNext) = 2;
      }
    }
    v6 = pScope->i_data.i_array_p;
    v7 = 3;
    if ( (*v6)->i_data_p->i_user_data )
      v7 = 0;
    UFG::AiDriverComponent::SetDrivingRole((UFG::AiDriverComponent *)v3->mAIDriverComponent.m_pSimComponent, v7);
    v8 = v3->mAIDriverComponent.m_pSimComponent;
    if ( LODWORD(v8[13].m_SafePointerList.mNode.mPrev) != 1 )
    {
      LODWORD(v8[13].m_SafePointerList.mNode.mPrev) = 1;
      HIDWORD(v8[19].m_SafePointerList.mNode.mPrev) = 0;
      HIDWORD(v8[24].m_SafePointerList.mNode.mPrev) = 0;
      BYTE4(v8[18].m_pSimObject) = 0;
      BYTE4(v8[18].m_BoundComponentHandles.mNode.mPrev) = 0;
      LOBYTE(v8[22].m_BoundComponentHandles.mNode.mNext) = 0;
    }
  }
}

// File Line: 1175
// RVA: 0x649D10
char __fastcall UFG::TSVehicle::Coro_path_to_xform(UFG::TSVehicle *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *v2; // rax
  SSInvokedCoroutine *v3; // rsi
  UFG::TSVehicle *v4; // rbx
  UFG::RoadSpaceComponent *v5; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v6; // rax
  UFG::SimComponent *v7; // rcx
  UFG::SimComponent *v9; // rcx
  unsigned __int64 v10; // rbp
  UFG::SimComponent *v11; // rax
  float *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  UFG::qVector3 nodePos; // [rsp+30h] [rbp-28h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-18h]

  v2 = this->mpSimObj.m_pPointer;
  v3 = pScope;
  v4 = this;
  if ( v2 )
    v5 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent;
  else
    v5 = 0i64;
  if ( !this->mAIDriverComponent.m_pSimComponent )
  {
    this->bDelayedByNoDriver = 1;
    return 0;
  }
  if ( !pScope->i_update_count || this->bDelayedByNoDriver )
  {
    v9 = this->mAIDriverComponent.m_pSimComponent;
    v10 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v9[12].m_BoundComponentHandles.mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)pScope;
    LODWORD(v9[13].vfptr) = pScope->i_ptr_id;
    v11 = v4->mAIDriverComponent.m_pSimComponent;
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
    if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) <= 0ui64 )
    {
      UFG::RoadSpaceComponent::SetCarDestination(v5, (UFG::TransformNodeComponent *)v10);
      ++v3->i_pending_count;
      v4->bDelayedByNoDriver = 0;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10);
      v13 = *(float *)(v10 + 176);
      v14 = *(float *)(v10 + 180);
      v15 = *(float *)(v10 + 184);
      pos.x = *(float *)(v10 + 176);
      pos.y = v14;
      pos.z = v15;
      if ( UFG::gpRoadNetworkResource )
      {
        nodePos.x = v13;
        nodePos.y = v14;
        nodePos.z = v15;
        if ( UFG::RoadNetworkResource::GetClosestNode(UFG::gpRoadNetworkResource, &pos, 0, &nodePos, 0i64) )
        {
          v13 = nodePos.x;
          v14 = nodePos.y;
          v15 = nodePos.z;
        }
        else
        {
          v15 = pos.z;
          v14 = pos.y;
          v13 = pos.x;
        }
      }
      v5->mDestinationPosition.x = v13;
      v5->mDestinationPosition.y = v14;
      v5->mDestinationPosition.z = v15;
      v16 = UFG::qVector3::msZero.z;
      v17 = UFG::qVector3::msZero.x;
      v5->mDestinationDirection.y = UFG::qVector3::msZero.y;
      v5->mDestinationDirection.z = v16;
      v5->mDestinationDirection.x = v17;
      ++v3->i_pending_count;
      v4->bDelayedByNoDriver = 0;
    }
    return 0;
  }
  v6 = &this->mAIDriverComponent.m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext;
  *v6 = 0i64;
  *((_DWORD *)v6 + 2) = 0;
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
  UFG::SimComponent *v3; // rax
  float v4; // xmm1_4
  UFG::SimComponent *v5; // rax

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    BYTE4(v3[24].vfptr) &= 0xFEu;
    *(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&v3[23].m_BoundComponentHandles.mNode.mNext
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
char __fastcall UFG::TSVehicle::Coro_stop_at(UFG::TSVehicle *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *v2; // rax
  int v3; // ebx
  SSInvokedCoroutine *v4; // rsi
  UFG::TSVehicle *v5; // rdi
  UFG::RoadSpaceComponent *v6; // rbp
  UFG::SimComponent *v7; // rcx
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v10; // rcx
  SSData **v11; // rdx
  int v12; // xmm0_4
  signed __int64 v13; // rax
  char v14; // cl
  char v15; // [rsp+28h] [rbp-10h]

  v2 = this->mpSimObj.m_pPointer;
  v3 = 0;
  v4 = pScope;
  v5 = this;
  if ( v2 )
    v6 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent;
  else
    v6 = 0i64;
  v7 = this->mAIDriverComponent.m_pSimComponent;
  if ( !v7 )
  {
    v5->bDelayedByNoDriver = 1;
    return 0;
  }
  if ( !pScope->i_update_count || v5->bDelayedByNoDriver )
  {
    v7[12].m_BoundComponentHandles.mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)pScope;
    LODWORD(v7[13].vfptr) = pScope->i_ptr_id;
    v10 = v5->mAIDriverComponent.m_pSimComponent;
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
      v6,
      (UFG::TransformNodeComponent *)(*v4->i_data.i_array_p)->i_data_p->i_user_data);
    v11 = v4->i_data.i_array_p;
    v12 = v11[3]->i_data_p->i_user_data;
    LOBYTE(v3) = v11[1]->i_data_p->i_user_data > 0;
    v13 = (signed __int64)&v5->mAIDriverComponent.m_pSimComponent[23].m_BoundComponentHandles.mNode.mNext + 4;
    v14 = ((v15 ^ (v11[2]->i_data_p->i_user_data != 0)) & 1 ^ v15) & 1;
    *(_BYTE *)(v13 + 8) &= 0xFEu;
    *(_BYTE *)(v13 + 8) |= v14;
    *(_DWORD *)v13 = v3;
    *(_DWORD *)(v13 + 4) = v12;
    LODWORD(v5->mAIDriverComponent.m_pSimComponent[24].m_SafePointerList.mNode.mPrev) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 4) + 8i64)
                                                                                                  + 32i64);
    ++v4->i_pending_count;
    v5->bDelayedByNoDriver = 0;
    return 0;
  }
  v7[12].m_BoundComponentHandles.mNode.mNext = 0i64;
  LODWORD(v7[13].vfptr) = 0;
  v8 = v5->mAIDriverComponent.m_pSimComponent;
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
void __fastcall UFG::TSVehicle::Mthd_create_ai_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rbx

  v3 = this;
  UFG::VehicleUtility::SetAIDriver((UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer, 0);
  if ( !v3->mAIDriverComponent.m_pSimComponent )
    UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::Bind<UFG::SimObjectVehicle>(
      &v3->mAIDriverComponent,
      (UFG::SimObjectVehicle *)v3->mpSimObj.m_pPointer);
}

// File Line: 1303
// RVA: 0x6537D0
void __fastcall UFG::TSVehicle::Mthd_create_human_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::VehicleDriverInterface *v3; // rax
  UFG::VehicleDriverInterface *v4; // rbx

  v3 = (UFG::VehicleDriverInterface *)UFG::VehicleUtility::SetPlayerDriver((UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer);
  v4 = v3;
  if ( v3 )
  {
    UFG::VehicleDriverInterface::SetDriver(v3, (UFG::SimObject *)&LocalPlayer->vfptr);
    UFG::VehicleDriverInterface::SetDesiredState(v4, (UFG::VehicleState)2);
    UFG::VehicleDriverInterface::StartEngineAudio(v4);
  }
}

// File Line: 1317
// RVA: 0x6536A0
void __fastcall UFG::TSVehicle::Mthd_clear_driver(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *v3; // r8
  UFG::TSVehicle *v4; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::SimObjectVehicle *v9; // rcx

  v3 = &this->mAIDriverComponent;
  v4 = this;
  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = this->mAIDriverComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    this->mAIDriverComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( this->mAIDriverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)this->mAIDriverComponent.mNext != &this->mAIDriverComponent) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v9 = (UFG::SimObjectVehicle *)v4->mpSimObj.m_pPointer;
  v4->mAIDriverComponent.m_pSimComponent = 0i64;
  UFG::VehicleUtility::ClearDriver(v9);
}

// File Line: 1324
// RVA: 0x655A70
void __fastcall UFG::TSVehicle::Mthd_set_driving_role(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v3 = this;
  if ( this->mAIDriverComponent.m_pSimComponent )
  {
    v4 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v5 = CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v5;
      pTrackEnumBinding.mNext = &CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode;
      CarAI::mRoleEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0xA )
      UFG::AiDriverComponent::SetDrivingRole(
        (UFG::AiDriverComponent *)v3->mAIDriverComponent.m_pSimComponent,
        pTrackEnumBinding.m_EnumValue);
    v6 = pTrackEnumBinding.mPrev;
    v7 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v7->mPrev = v6;
  }
}

// File Line: 1337
// RVA: 0x655530
void __fastcall UFG::TSVehicle::Mthd_set_can_shove_cargo(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[5].m_pComponent;
    if ( v4 )
      BYTE1(v4[32].m_BoundComponentHandles.mNode.mPrev) ^= (BYTE1(v4[32].m_BoundComponentHandles.mNode.mPrev) ^ 8 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 8;
  }
}

// File Line: 1404
// RVA: 0x655DD0
void __fastcall UFG::TSVehicle::Mthd_set_race(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceTrail *v3; // r8
  __int64 v4; // rdx
  signed int v5; // eax
  UFG::SimObject *v6; // rax
  UFG::RoadSpaceComponent *v7; // rcx

  v3 = 0i64;
  v4 = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (signed int)v4 <= 0 )
  {
    v5 = 0;
  }
  else
  {
    v5 = v4;
    if ( (signed int)v4 >= 63 )
      v5 = 63;
  }
  if ( (_DWORD)v4 == v5 )
    v3 = UFG::RaceManager::aRaceTrails[v4];
  v6 = this->mpSimObj.m_pPointer;
  if ( v6 )
  {
    v7 = (UFG::RoadSpaceComponent *)v6->m_Components.p[24].m_pComponent;
    if ( v7 )
      UFG::RoadSpaceComponent::SetRaceTrail(v7, v3);
  }
}

// File Line: 1414
// RVA: 0x656380
void __fastcall UFG::TSVehicle::Mthd_steer_race(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceTrail *v3; // r8
  __int64 v4; // rdx
  signed int v5; // eax
  UFG::SimObject *v6; // rax
  UFG::RoadSpaceComponent *v7; // rcx

  v3 = 0i64;
  v4 = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (signed int)v4 <= 0 )
  {
    v5 = 0;
  }
  else
  {
    v5 = v4;
    if ( (signed int)v4 >= 63 )
      v5 = 63;
  }
  if ( (_DWORD)v4 == v5 )
    v3 = UFG::RaceManager::aRaceTrails[v4];
  v6 = this->mpSimObj.m_pPointer;
  if ( v6 )
  {
    v7 = (UFG::RoadSpaceComponent *)v6->m_Components.p[24].m_pComponent;
    if ( v7 )
      UFG::RoadSpaceComponent::SetRaceTrailSteer(v7, v3);
  }
}

// File Line: 1421
// RVA: 0x656230
void __fastcall UFG::TSVehicle::Mthd_start_racing(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // rax
  UFG::TSVehicle *v4; // r8
  UFG::AiDriverComponent *v5; // rcx
  bool v6; // al
  SSData **v7; // rdx
  UFG::AiDriverComponent *v8; // r9
  UFG::SimObject *v9; // rax
  UFG::AiDriverComponent *v10; // rax
  UFG::PhysicsMoverInterface *v11; // rax

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  v4 = this;
  if ( v3 )
  {
    if ( v3->m_DrivingMode != 6 )
    {
      v3->m_DrivingMode = 6;
      v3->m_fReactionTime = 0.0;
      v3->m_fDelayedStopDecel = 0.0;
      v3->mModeSteeringLockEnabled = 0;
      v3->mModeGasBrakeLockEnabled = 0;
      v3->m_bIgnoreArrivalDirection = 0;
    }
    v5 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
    if ( v5->m_DrivingRole != 1 )
    {
      v6 = v5->m_RoadRuleFlagsLocked;
      v5->m_DrivingRole = 1;
      if ( !v6 )
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
    v7 = pScope->i_data.i_array_p;
    v8 = (UFG::AiDriverComponent *)v4->mAIDriverComponent.m_pSimComponent;
    v8->m_fRaceSpeedLimit = *(float *)&(*v7)->i_data_p->i_user_data * 0.27777779;
    v9 = v4->mpSimObj.m_pPointer;
    if ( v9 && (v10 = (UFG::AiDriverComponent *)v9->m_Components.p[24].m_pComponent) != 0i64 )
      v11 = (UFG::PhysicsMoverInterface *)v10[1].mMoverComponent.mNext;
    else
      v11 = 0i64;
    if ( v11 )
      HIDWORD(v11->m_BoundComponentHandles.mNode.mNext) = 0;
    v8->m_RaceWanderAtEnd = v7[1]->i_data_p->i_user_data > 0;
  }
}

// File Line: 1445
// RVA: 0x655E30
void __fastcall UFG::TSVehicle::Mthd_set_race_speed_limit(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // r8

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    v3->m_fRaceSpeedLimit = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * 0.27777779;
}

// File Line: 1458
// RVA: 0x655780
void __fastcall UFG::TSVehicle::Mthd_set_countdown_time(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v4 = v3->m_Components.p[24].m_pComponent) != 0i64 )
    v5 = v4[26].m_SafePointerList.mNode.mPrev;
  else
    v5 = 0i64;
  if ( v5 )
    LODWORD(v5[4].mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1466
// RVA: 0x6555C0
void __fastcall UFG::TSVehicle::Mthd_set_catchup_target(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // r9
  UFG::TSVehicle *v4; // rbx
  SSData **v5; // r8
  float v6; // xmm9_4
  float v7; // xmm10_4
  unsigned int v8; // xmm11_4
  float v9; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm8_4
  float v12; // xmm1_4
  UFG::SimComponent *v13; // rax
  float v14; // xmm0_4

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  v4 = this;
  if ( !v3 )
    return;
  v5 = pScope->i_data.i_array_p;
  v6 = *(float *)&v5[1]->i_data_p->i_user_data;
  v7 = *(float *)&v5[2]->i_data_p->i_user_data * 0.0099999998;
  v8 = v5[3]->i_data_p->i_user_data;
  v9 = *(float *)&v5[4]->i_data_p->i_user_data;
  if ( v9 >= 0.0 )
    v10 = v9 * 0.0099999998;
  else
    v10 = *(float *)&v5[2]->i_data_p->i_user_data * 0.0099999998;
  v11 = *(float *)&v5[5]->i_data_p->i_user_data;
  if ( v11 < 0.0 )
    v11 = *(float *)&v5[1]->i_data_p->i_user_data;
  UFG::AiDriverComponent::SetChaseTarget(v3, *(UFG::SimObject **)&(*v5)->i_data_p[4].i_ref_count);
  v12 = FLOAT_10_0;
  if ( v6 < 10.0 )
    v6 = FLOAT_10_0;
  *(float *)&v4->mAIDriverComponent.m_pSimComponent[16].m_SafePointerList.mNode.mPrev = v6;
  UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -1.0 / v6;
  v13 = v4->mAIDriverComponent.m_pSimComponent;
  if ( v7 < 0.0 )
    v7 = 0.0;
  *(float *)&v13[16].m_SafePointerList.mNode.mNext = v7;
  v13[16].m_TypeUID = v8;
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
void __fastcall UFG::TSVehicle::Mthd_clear_catchup_target(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rbx
  UFG::AiDriverComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v3 = this;
  v4 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v4 )
  {
    UFG::AiDriverComponent::SetChaseTarget(v4, 0i64);
    LODWORD(v3->mAIDriverComponent.m_pSimComponent[16].m_SafePointerList.mNode.mPrev) = 1092616192;
    UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -0.1;
    v5 = v3->mAIDriverComponent.m_pSimComponent;
    v5[16].m_SafePointerList.mNode.mNext = 0i64;
    v5[16].m_TypeUID = 0;
    HIDWORD(v5[16].m_SafePointerList.mNode.mPrev) = 1092616192;
    UFG::AiDriverComponent::m_CatchupParams.m_P_Coefficient = -0.1;
  }
}

// File Line: 1506
// RVA: 0x655BB0
void __fastcall UFG::TSVehicle::Mthd_set_force_dock(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    LOBYTE(v3[4].m_TypeUID) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1515
// RVA: 0x6545C0
void __fastcall UFG::TSVehicle::Mthd_get_race_index(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  unsigned __int64 v4; // rdx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0xFFFFFFFFi64;
  if ( v3 )
  {
    v5 = v3->m_Components.p[24].m_pComponent;
    if ( v5 )
    {
      v6 = v5[26].m_SafePointerList.mNode.mPrev;
      if ( v6 )
      {
        v7 = v6[1].mPrev;
        if ( v7 )
          v4 = LODWORD(v7[2].mNext);
      }
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 1528
// RVA: 0x654620
void __fastcall UFG::TSVehicle::Mthd_get_race_point_index(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  unsigned int v4; // edx
  SSInstance **v5; // rbx
  UFG::RoadSpaceComponent *v6; // rax
  UFG::RacePosition *v7; // rax
  UFG::RaceTrail *v8; // r8
  UFG::RacePoint *v9; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = -1;
  v5 = ppResult;
  if ( v3 )
  {
    v6 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
    if ( v6 )
    {
      v7 = v6->m_pRacePosition;
      if ( v7 )
      {
        v8 = v7->pRaceTrail.m_pPointer;
        if ( v8 )
        {
          v9 = v7->pRacePoint;
          if ( v9 )
            v4 = ((unsigned __int64)((unsigned __int128)(((char *)v9 - (char *)v8->pRacePoints)
                                                       * (signed __int128)0x4924924924924925i64) >> 64) >> 63)
               + ((signed __int64)((unsigned __int128)(((char *)v9 - (char *)v8->pRacePoints)
                                                     * (signed __int128)0x4924924924924925i64) >> 64) >> 4);
        }
      }
    }
  }
  *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 1541
// RVA: 0x654700
void __fastcall UFG::TSVehicle::Mthd_get_race_time(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  unsigned int v4; // xmm0_4
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  if ( v3 && (v5 = v3->m_Components.p[24].m_pComponent) != 0i64 )
    v6 = v5[26].m_SafePointerList.mNode.mPrev;
  else
    v6 = 0i64;
  if ( v6 )
    v4 = HIDWORD(v6[3].mNext);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, v4);
}

// File Line: 1550
// RVA: 0x654150
void __fastcall UFG::TSVehicle::Mthd_get_countdown_time(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  unsigned int v4; // xmm0_4
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  if ( v3 && (v5 = v3->m_Components.p[24].m_pComponent) != 0i64 )
    v6 = v5[26].m_SafePointerList.mNode.mPrev;
  else
    v6 = 0i64;
  if ( v6 )
    v4 = (unsigned int)v6[4].mPrev;
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, v4);
}

// File Line: 1559
// RVA: 0x654240
void __fastcall UFG::TSVehicle::Mthd_get_fraction_race_complete(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  float v4; // xmm0_4
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  float v8; // xmm1_4
  float v9; // xmm1_4

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0.0;
  if ( v3 && (v5 = v3->m_Components.p[24].m_pComponent) != 0i64 )
    v6 = v5[26].m_SafePointerList.mNode.mPrev;
  else
    v6 = 0i64;
  if ( v6 )
  {
    v7 = v6[1].mPrev;
    if ( v7 )
    {
      if ( LOBYTE(v7[2].mPrev) )
        v8 = (float)SLODWORD(v7[1].mNext);
      else
        v8 = *(float *)&FLOAT_1_0;
      v9 = v8 * *((float *)&v7[2].mPrev + 1);
      if ( v9 > 0.0 )
        v4 = *(float *)&v6[3].mPrev / v9;
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
}

// File Line: 1568
// RVA: 0x6546A0
void __fastcall UFG::TSVehicle::Mthd_get_race_proximity(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  unsigned int v4; // xmm0_4
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  if ( v3 && (v5 = v3->m_Components.p[24].m_pComponent) != 0i64 )
    v6 = v5[26].m_SafePointerList.mNode.mPrev;
  else
    v6 = 0i64;
  if ( v6 )
    v4 = HIDWORD(v6[3].mPrev);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, v4);
}

// File Line: 1578
// RVA: 0x653E40
void __fastcall UFG::TSVehicle::Mthd_follow(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rbx
  SSData **v4; // rcx
  UFG::AiDriverComponent *v5; // r8
  SSInstance *v6; // r9
  int v7; // xmm6_4

  v3 = this;
  v4 = pScope->i_data.i_array_p;
  v5 = (UFG::AiDriverComponent *)v3->mAIDriverComponent.m_pSimComponent;
  v6 = (*v4)->i_data_p;
  if ( v5 && v6 )
  {
    v7 = v4[1]->i_data_p->i_user_data;
    if ( v5->m_DrivingMode != 4 )
    {
      v5->m_DrivingMode = 4;
      v5->m_bIgnoreArrivalDirection = 1;
      v5->m_fReactionTime = 0.0;
      v5->m_fDelayedStopDecel = 0.0;
      v5->mModeSteeringLockEnabled = 0;
      v5->mModeGasBrakeLockEnabled = 0;
    }
    UFG::AiDriverComponent::SetChaseTarget(
      (UFG::AiDriverComponent *)v3->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&v6[4].i_ref_count);
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)v3->mAIDriverComponent.m_pSimComponent,
      COERCE_FLOAT(v7 ^ _xmm[0]),
      0.0,
      2.0);
  }
}

// File Line: 1591
// RVA: 0x653C40
void __fastcall UFG::TSVehicle::Mthd_escort(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::TSVehicle *v4; // rbx
  UFG::SimComponent *v5; // rcx
  SSInvokedMethod *v6; // rbp
  SSInstance *v7; // rdi
  SSInstance *v8; // rsi
  signed __int64 v9; // rcx
  SSData **v10; // rdx
  float v11; // xmm0_4
  UFG::SimComponent *v12; // rax
  float v13; // xmm1_4

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = this->mAIDriverComponent.m_pSimComponent;
  v6 = pScope;
  v7 = (*v3)->i_data_p;
  v8 = v3[1]->i_data_p;
  if ( v5 && v7 && v8 )
  {
    if ( LODWORD(v5[13].m_SafePointerList.mNode.mPrev) != 7 )
    {
      LODWORD(v5[13].m_SafePointerList.mNode.mPrev) = 7;
      v9 = (signed __int64)&v5[21].m_Flags;
      *(_DWORD *)(v9 - 148) = 0;
      *(_DWORD *)(v9 + 172) = 0;
      *(_BYTE *)(v9 - 180) = 0;
      *(_BYTE *)(v9 - 172) = 0;
      *(_BYTE *)(v9 + 88) = 0;
      UFG::VehicleCombatStats::Reset((UFG::VehicleCombatStats *)v9);
    }
    UFG::AiDriverComponent::SetEscortEnemy(
      (UFG::AiDriverComponent *)v4->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&v8[4].i_ref_count);
    UFG::AiDriverComponent::SetEscortObjective(
      (UFG::AiDriverComponent *)v4->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&v7[4].i_ref_count);
    UFG::AiDriverComponent::SetChaseTarget(
      (UFG::AiDriverComponent *)v4->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&v7[4].i_ref_count);
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)v4->mAIDriverComponent.m_pSimComponent,
      COERCE_FLOAT(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)v6->i_data.i_array_p + 2) + 8i64) + 32i64) ^ _xmm[0]),
      0.0,
      2.0);
    v10 = v6->i_data.i_array_p;
    v11 = *(float *)&v10[3]->i_data_p->i_user_data;
    v12 = v4->mAIDriverComponent.m_pSimComponent;
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
  UFG::AiDriverComponent *v3; // r8

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    v3->m_FollowDebug = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1628
// RVA: 0x653470
void __fastcall UFG::TSVehicle::Mthd_avoidance_debug(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    BYTE5(v3[16].m_BoundComponentHandles.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1636
// RVA: 0x6534A0
void __fastcall UFG::TSVehicle::Mthd_break_on_update(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    LOBYTE(v3[4].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1646
// RVA: 0x6564B0
void __fastcall UFG::TSVehicle::Mthd_take_camera(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v4 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v4, UFG::ChaseCameraComponent::_TypeUID);
    if ( v5 )
    {
      if ( v3 )
        v5->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)v3);
    }
  }
}

// File Line: 1653
// RVA: 0x653F30
void __fastcall UFG::TSVehicle::Mthd_follow_offset(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r9
  UFG::SimComponent *v4; // r8
  UFG::TSVehicle *v5; // rbx
  SSInstance *v6; // r10
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4

  v3 = pScope->i_data.i_array_p;
  v4 = this->mAIDriverComponent.m_pSimComponent;
  v5 = this;
  v6 = (*v3)->i_data_p;
  if ( v4 && v6 )
  {
    v7 = *(float *)&v3[1]->i_data_p->i_user_data;
    v8 = *(float *)&v3[2]->i_data_p->i_user_data;
    v9 = *(float *)&v3[3]->i_data_p->i_user_data;
    if ( LODWORD(v4[13].m_SafePointerList.mNode.mPrev) != 4 )
    {
      LODWORD(v4[13].m_SafePointerList.mNode.mPrev) = 4;
      LOBYTE(v4[22].m_BoundComponentHandles.mNode.mNext) = 1;
      HIDWORD(v4[19].m_SafePointerList.mNode.mPrev) = 0;
      HIDWORD(v4[24].m_SafePointerList.mNode.mPrev) = 0;
      BYTE4(v4[18].m_pSimObject) = 0;
      BYTE4(v4[18].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
    UFG::AiDriverComponent::SetChaseTarget(
      (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent,
      *(UFG::SimObject **)&v6[4].i_ref_count);
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)v5->mAIDriverComponent.m_pSimComponent,
      v7,
      v8,
      v9);
  }
}

// File Line: 1669
// RVA: 0x655F60
void __fastcall UFG::TSVehicle::Mthd_set_slow_down_for_race_curvature(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[24].m_pComponent;
    if ( v4 )
      v4[30].m_TypeUID ^= (v4[30].m_TypeUID ^ 8 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 8;
  }
}

// File Line: 1680
// RVA: 0x655490
void __fastcall UFG::TSVehicle::Mthd_set_avoid_objects_enabled(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // r8

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    v3->m_AvoidObjectsEnabled = (float)((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0) != 0.0;
}

// File Line: 1690
// RVA: 0x655440
void __fastcall UFG::TSVehicle::Mthd_set_avoid_geo_enabled(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    BYTE1(v3[23].m_SafePointerList.mNode.mNext) = (float)((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0) != 0.0;
}

// File Line: 1700
// RVA: 0x655EF0
void __fastcall UFG::TSVehicle::Mthd_set_road_speed_limit_scale(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    LODWORD(v3[23].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1709
// RVA: 0x655A40
void __fastcall UFG::TSVehicle::Mthd_set_desired_speed_limit_kph(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    *((float *)&v3[23].m_SafePointerList.mNode.mPrev + 1) = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data
                                                          * 0.27777779;
}

// File Line: 1718
// RVA: 0x655750
void __fastcall UFG::TSVehicle::Mthd_set_chase_speed_limit_kph(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // r8

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    v3->m_fChaseSpeedLimit = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * 0.27777779;
}

// File Line: 1727
// RVA: 0x654EE0
void __fastcall UFG::TSVehicle::Mthd_override_speed_kph(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::VehicleUtility::OverrideForwardSpeedKPH(
    (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer,
    *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1734
// RVA: 0x653500
void __fastcall UFG::TSVehicle::Mthd_chase(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rbx
  SSInstance *v4; // rdi
  UFG::AiDriverComponent *v5; // rcx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::CharacterOccupantComponent *v8; // rax
  UFG::SimObject *v9; // rax

  v3 = this;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v4 )
  {
    v5 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
    if ( v5 )
    {
      if ( v5->m_DrivingMode != 3 )
      {
        v5->m_DrivingMode = 3;
        v5->m_bIgnoreArrivalDirection = 1;
        v5->m_fReactionTime = 0.0;
        v5->m_fDelayedStopDecel = 0.0;
        v5->mModeSteeringLockEnabled = 0;
        v5->mModeGasBrakeLockEnabled = 0;
        UFG::VehicleCombatStats::Reset(&v5->m_CombatStats);
      }
      v6 = *(UFG::SimObjectGame **)&v4[4].i_ref_count;
      HIDWORD(v3->mAIDriverComponent.m_pSimComponent[24].m_SafePointerList.mNode.mNext) = -1082130432;
      if ( !v6
        || ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID))) : (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID))) : (v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::CharacterOccupantComponent::_TypeUID))) : (v8 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent),
            !v8 || (v9 = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v8)) == 0i64) )
      {
        v9 = *(UFG::SimObject **)&v4[4].i_ref_count;
      }
      UFG::AiDriverComponent::SetChaseTarget((UFG::AiDriverComponent *)v3->mAIDriverComponent.m_pSimComponent, v9);
    }
  }
}

// File Line: 1752
// RVA: 0x653A00
void __fastcall UFG::TSVehicle::Mthd_enable_horn(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  bool v4; // bl
  UFG::VehicleAudioComponent *v5; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
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
  UFG::TSVehicle *v3; // rdi
  SSData *v4; // rdx
  bool v5; // si
  UFG::VehicleEffectsComponent *v6; // rbx
  UFG::SimObjectVehicle *v7; // rcx
  UFG::VehicleAudioComponent *v8; // rcx
  UFG::SimObject *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::CopUnitComponent *v11; // rcx
  UFG::SimObject *v12; // rax
  UFG::CopUnitComponent *v13; // rcx

  v3 = this;
  v4 = *pScope->i_data.i_array_p;
  v5 = v4->i_data_p->i_user_data != 0;
  v6 = 0i64;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         (int)v4,
         (int)ppResult)
    && (v7 = (UFG::SimObjectVehicle *)v3->mpSimObj.m_pPointer) != 0i64 )
  {
    v8 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v7);
  }
  else
  {
    v8 = 0i64;
  }
  v9 = v3->mpSimObj.m_pPointer;
  if ( v9 )
    v6 = (UFG::VehicleEffectsComponent *)v9->m_Components.p[32].m_pComponent;
  if ( v5 )
  {
    if ( v8 )
      UFG::VehicleAudioComponent::StartSiren(v8, 1);
    v10 = v3->mpSimObj.m_pPointer;
    if ( v10 && (v11 = (UFG::CopUnitComponent *)v10->m_Components.p[17].m_pComponent) != 0i64 )
    {
      UFG::CopUnitComponent::SetScriptedLightsOn(v11, 1);
    }
    else if ( v6 )
    {
      UFG::VehicleEffectsComponent::TurnOnCopLights(v6);
    }
  }
  else
  {
    if ( v8 )
      UFG::VehicleAudioComponent::StopSiren(v8, 1);
    v12 = v3->mpSimObj.m_pPointer;
    if ( v12 && (v13 = (UFG::CopUnitComponent *)v12->m_Components.p[17].m_pComponent) != 0i64 )
    {
      UFG::CopUnitComponent::SetScriptedLightsOn(v13, 0);
    }
    else if ( v6 )
    {
      UFG::VehicleEffectsComponent::TurnOffCopLights(v6);
    }
  }
}

// File Line: 1808
// RVA: 0x653910
void __fastcall UFG::TSVehicle::Mthd_enable_cop_lights(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  bool v4; // dl

  v3 = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
    JUMPOUT(v3->m_Components.p[17].m_pComponent, 0i64, UFG::CopUnitComponent::SetScriptedLightsOn);
}

// File Line: 1820
// RVA: 0x653980
void __fastcall UFG::TSVehicle::Mthd_enable_head_lights(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  bool v4; // dl
  UFG::VehicleEffectsComponent *v5; // rbx

  v3 = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
    v5 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
  else
    v5 = 0i64;
  if ( v4 )
  {
    if ( v5 )
    {
      UFG::VehicleEffectsComponent::TurnOnScriptedLights(v5);
      UFG::VehicleEffectsComponent::TurnOnHeadlights(v5, 1);
    }
  }
  else if ( v5 )
  {
    UFG::VehicleEffectsComponent::TurnOffHeadlights(v5);
    UFG::VehicleEffectsComponent::TurnOffScriptedLights(v5);
  }
}

// File Line: 1843
// RVA: 0x654F00
void __fastcall UFG::TSVehicle::Mthd_queue_head_light_flashes(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  SSInstance *v4; // rdx
  SSInstance *v5; // r8
  UFG::SimObject *v6; // rax
  UFG::VehicleEffectsComponent *v7; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = v3[1]->i_data_p;
  v6 = this->mpSimObj.m_pPointer;
  if ( v6 )
  {
    v7 = (UFG::VehicleEffectsComponent *)v6->m_Components.p[32].m_pComponent;
    if ( v7 )
      UFG::VehicleEffectsComponent::QueueHeadlightFlashes(v7, v4->i_user_data, *(float *)&v5->i_user_data);
  }
}

// File Line: 1855
// RVA: 0x656350
void __fastcall UFG::TSVehicle::Mthd_start_radio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v4 )
      UFG::VehicleAudioComponent::TurnOnRadio(v4);
  }
}

// File Line: 1865
// RVA: 0x652F60
void __fastcall UFG::TSVehicle::MthdC_start_player_radio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    ((void (__fastcall *)(UFG::RadioFullyControlled *, SSInvokedMethod *, SSInstance **))UFG::RadioFullyControlled::sm_playerRadio->vfptr[1].AudioEntityUpdate)(
      UFG::RadioFullyControlled::sm_playerRadio,
      pScope,
      ppResult);
}

// File Line: 1871
// RVA: 0x652F80
void __fastcall UFG::TSVehicle::MthdC_stop_player_radio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
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
  UFG::SimObjectVehicle *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v4 )
      UFG::VehicleAudioComponent::StopRadio(v4, v5);
  }
}

// File Line: 1887
// RVA: 0x655E60
void __fastcall UFG::TSVehicle::Mthd_set_radio_station(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  SSInstance *v4; // rbx
  UFG::VehicleAudioComponent *v5; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v5 )
      UFG::VehicleAudioComponent::SetRadioStation(v5, (signed int)*(float *)&v4->i_user_data);
  }
}

// File Line: 1897
// RVA: 0x654760
void __fastcall UFG::TSVehicle::Mthd_get_radio_station(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  SSInstance **v4; // rbx
  UFG::VehicleAudioComponent *v5; // rax
  signed int v6; // eax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = ppResult;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v5 )
    {
      v6 = UFG::VehicleAudioComponent::GetRadioStation(v5);
      *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, COERCE_UNSIGNED_INT((float)v6));
    }
  }
}

// File Line: 1906
// RVA: 0x652F10
void __fastcall UFG::TSVehicle::MthdC_set_shutdown_on_exit(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  bool v4; // bl
  UFG::VehicleAudioComponent *v5; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v5 )
      UFG::VehicleAudioComponent::SetShutdownOnExit(v5, v4);
  }
}

// File Line: 1918
// RVA: 0x652EC0
void __fastcall UFG::TSVehicle::MthdC_set_radio_is_enabled(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  bool v4; // bl
  UFG::VehicleAudioComponent *v5; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v5 )
      UFG::VehicleAudioComponent::SetRadioIsEnabled(v5, v4);
  }
}

// File Line: 1929
// RVA: 0x653730
void __fastcall UFG::TSVehicle::Mthd_clear_playlist(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v4 )
      UFG::VehicleAudioComponent::ClearRadioPlaylist(v4);
  }
}

// File Line: 1938
// RVA: 0x653760
void __fastcall UFG::TSVehicle::Mthd_clear_recently_played(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v4 )
      UFG::VehicleAudioComponent::ClearRadioHistory(v4);
  }
}

// File Line: 1947
// RVA: 0x653210
void __fastcall UFG::TSVehicle::Mthd_add_asset_to_playlist(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  SSInstance *v4; // rbx
  UFG::VehicleAudioComponent *v5; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v5 )
      UFG::VehicleAudioComponent::AddTrackToPlaylist(v5, *(const char **)v4->i_user_data);
  }
}

// File Line: 1957
// RVA: 0x654F40
void __fastcall UFG::TSVehicle::Mthd_randomize_playlist(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v4 )
      UFG::VehicleAudioComponent::RandomizeRadioPlaylist(v4, v5);
  }
}

// File Line: 1966
// RVA: 0x652E70
void __fastcall UFG::TSVehicle::MthdC_randomize_player_playlist(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    JUMPOUT(UFG::RadioFullyControlled::sm_playerRadio->m_curStation, 0i64, UFG::RadioStation::RandomizePlaylist);
}

// File Line: 1972
// RVA: 0x652E90
void __fastcall UFG::TSVehicle::MthdC_set_player_radio_station(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( UFG::RadioFullyControlled::sm_playerRadio )
    UFG::Radio::SetStation(
      (UFG::Radio *)&UFG::RadioFullyControlled::sm_playerRadio->vfptr,
      (signed int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1979
// RVA: 0x6529B0
void __fastcall UFG::TSVehicle::MthdC_clear_player_playlist(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(UFG::RadioFullyControlled::sm_playerRadio, 0i64, UFG::Radio::ClearAllPlaylists);
}

// File Line: 1985
// RVA: 0x6529D0
void __fastcall UFG::TSVehicle::MthdC_clear_player_recently_played(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RadioStation *v3; // rbx

  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    v3 = UFG::RadioFullyControlled::sm_playerRadio->m_curStation;
    if ( v3 )
    {
      UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v3->m_prevPlayed);
      v3->m_numRecentlyPlayed = 0;
    }
  }
}

// File Line: 1991
// RVA: 0x652970
void __fastcall UFG::TSVehicle::MthdC_add_asset_to_player_playlist(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RadioStation *v3; // rcx

  if ( UFG::RadioFullyControlled::sm_playerRadio )
  {
    v3 = UFG::RadioFullyControlled::sm_playerRadio->m_curStation;
    if ( v3 )
      UFG::RadioStation::AddToPlaylist(v3, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 0);
  }
}

// File Line: 1998
// RVA: 0x652B30
void __fastcall UFG::TSVehicle::MthdC_player_radio_next_track(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(UFG::RadioFullyControlled::sm_playerRadio, 0i64, UFG::RadioFullyControlled::NextTrack);
}

// File Line: 2004
// RVA: 0x654AF0
void __fastcall UFG::TSVehicle::Mthd_init_audio(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  UFG::VehicleAudioComponent *v4; // rax

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v4 )
      UFG::VehicleAudioComponent::EngineStart(v4);
  }
}

// File Line: 2013
// RVA: 0x656E20
void __fastcall UFG::TSVehicle::OnInit(UFG::TSVehicle *this, UFG::SimObject *pSimObj)
{
  UFG::SimObjectVehicle *v2; // rdi
  UFG::TSVehicle *v3; // rbx
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  void (__fastcall *v9)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  void (__fastcall *v10)(UFG::Event *); // [rsp+30h] [rbp-28h]
  void (__fastcall *v11)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+38h] [rbp-20h]
  void (__fastcall *v12)(UFG::Event *); // [rsp+40h] [rbp-18h]
  void (__fastcall *v13)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+48h] [rbp-10h]

  v2 = (UFG::SimObjectVehicle *)pSimObj;
  v3 = this;
  UFG::TSActor::OnInit((UFG::TSActor *)&this->vfptr, pSimObj);
  v4 = &v3->mAIDriverComponent;
  if ( v3->mAIDriverComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v3->mAIDriverComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mAIDriverComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->mAIDriverComponent.m_pSimObject = 0i64;
    v3->mAIDriverComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mAIDriverComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->mAIDriverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v3->mAIDriverComponent.mNext != &v3->mAIDriverComponent) )
  {
    v7 = v4->mPrev;
    v8 = v3->mAIDriverComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->mAIDriverComponent.m_Changed = 1;
  v3->mAIDriverComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->mAIDriverComponent.m_TypeUID = UFG::AiDriverComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::BindInternal<UFG::SimObjectVehicle>(v4, v2);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::Bind<UFG::SimObjectVehicle>(&v3->mMoverComponent, v2);
  if ( !registeredStaticEventHandlers_1 )
  {
    v9 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    v12 = UFG::TSVehicle::EntityDeathHandler;
    v10 = UFG::TSVehicle::EntityDeathHandler;
    if ( !UFG::TSVehicle::EntityDeathHandler )
      v9 = 0i64;
    v13 = v9;
    v11 = v9;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
      0x514B87Fu,
      0i64,
      0);
    registeredStaticEventHandlers_1 = 1;
  }
  v3->bDelayedByNoDriver = 0;
}

// File Line: 2036
// RVA: 0x65EDB0
void __fastcall UFG::TSVehicle::UnlockDoors(UFG::TSVehicle *this, bool enable)
{
  LOBYTE(this->mMoverComponent.m_pSimComponent[14].m_SafePointerList.mNode.mNext) = enable == 0;
}

// File Line: 2045
// RVA: 0x64C920
void __fastcall UFG::TSVehicle::EntityDeathHandler(UFG::Event *thisEvent)
{
  UFG::SimObjectGame *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::TSActorComponent *v3; // rax
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax

  v1 = (UFG::SimObjectGame *)thisEvent[1].mNext;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
        v3 = (UFG::TSActorComponent *)v1->m_Components.p[3].m_pComponent;
      else
        v3 = (UFG::TSActorComponent *)((v2 >> 12) & 1 ? v1->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v1->vfptr,
                                                                                               UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      v3 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    if ( v3
      && (SSActorClass *)UFG::TSActorComponent::GetActor(v3)->i_class_p == UFG::TSVehicle::mClass
      && v1->m_pSceneObj )
    {
      v4 = v1->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v1->m_Components.p[8].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::MissionFailConditionComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::MissionFailConditionComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v1->vfptr,
                 UFG::MissionFailConditionComponent::_TypeUID);
        }
      }
      else
      {
        v5 = v1->m_Components.p[8].m_pComponent;
      }
      if ( v5 )
      {
        if ( BYTE5(v5[1].m_BoundComponentHandles.mNode.mPrev) )
          UFG::MissionFailConditionComponent::FailObject(
            (UFG::SimObject *)&v1->vfptr,
            (UFG::qSymbol *)&qSymbol_DeathFailCaption.mUID);
      }
    }
  }
}

// File Line: 2076
// RVA: 0x655F20
void __fastcall UFG::TSVehicle::Mthd_set_roll_stability(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // r8

  v3 = this->mMoverComponent.m_pSimComponent;
  if ( v3 )
  {
    v4 = v3[10].m_SafePointerList.mNode.mPrev;
    if ( v4 )
    {
      if ( (HIDWORD(v4[37].mNext) & 7) == 4 )
        LODWORD(v4[36].mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    }
  }
}

// File Line: 2097
// RVA: 0x655CF0
void __fastcall UFG::TSVehicle::Mthd_set_mass_scale_for_collisions(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax
  UFG::PhysicsVehicle *v4; // rcx
  SSInstance *v5; // rax

  v3 = this->mMoverComponent.m_pSimComponent;
  if ( v3 )
  {
    v4 = (UFG::PhysicsVehicle *)v3[10].m_SafePointerList.mNode.mPrev;
    if ( v4 )
    {
      v5 = (*pScope->i_data.i_array_p)->i_data_p;
      UFG::PhysicsVehicle::SetMassScaleForCollisions(v4, *(float *)&v5->i_user_data, *(float *)&v5->i_user_data);
    }
  }
}

// File Line: 2118
// RVA: 0x653710
void __fastcall UFG::TSVehicle::Mthd_clear_mass_scale_for_collisions(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rcx

  v3 = this->mMoverComponent.m_pSimComponent;
  if ( v3 )
    UFG::PhysicsVehicle::ClearMassScaleForCollisions((UFG::PhysicsVehicle *)v3[10].m_SafePointerList.mNode.mPrev);
}

// File Line: 2127
// RVA: 0x6554E0
void __fastcall UFG::TSVehicle::Mthd_set_avoid_peds(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8
  bool v4; // al

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
    if ( !LOBYTE(v3[22].m_BoundComponentHandles.mNode.mPrev) )
    {
      LOBYTE(v3[22].m_pSimObject) = v4;
      if ( !v4 )
        HIDWORD(v3[19].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 2132
// RVA: 0x655180
void __fastcall UFG::TSVehicle::Mthd_set_allowed_to_pass(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( !LOBYTE(v3[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE1(v3[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2137
// RVA: 0x655FB0
void __fastcall UFG::TSVehicle::Mthd_set_stay_off_sidewalk(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( !LOBYTE(v3[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE2(v3[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2142
// RVA: 0x655EB0
void __fastcall UFG::TSVehicle::Mthd_set_respect_speed_limit(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( !LOBYTE(v3[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE3(v3[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2147
// RVA: 0x655D30
void __fastcall UFG::TSVehicle::Mthd_set_obey_traffic_lights(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( !LOBYTE(v3[22].m_BoundComponentHandles.mNode.mPrev) )
      BYTE4(v3[22].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2153
// RVA: 0x655580
void __fastcall UFG::TSVehicle::Mthd_set_can_turn_around(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // r8

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( !v3->m_RoadRuleFlagsLocked )
      v3->m_bCanTurnAround = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 2164
// RVA: 0x655D70
void __fastcall UFG::TSVehicle::Mthd_set_parked(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // rcx

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    UFG::AiDriverComponent::SetParked(v3, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 2173
// RVA: 0x654D50
void __fastcall UFG::TSVehicle::Mthd_is_parked(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSVehicle *v3; // rax
  char v4; // cl
  UFG::SimComponent *v5; // rax

  if ( ppResult )
  {
    v3 = this;
    v4 = 1;
    v5 = v3->mAIDriverComponent.m_pSimComponent;
    if ( v5 )
      v4 = BYTE1(v5[22].m_BoundComponentHandles.mNode.mNext);
    *ppResult = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 2186
// RVA: 0x656050
void __fastcall UFG::TSVehicle::Mthd_set_usable_by_cop_system(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Components.p[17].m_pComponent;
    if ( v4 )
      LOBYTE(v4[7].m_Flags) ^= (LOBYTE(v4[7].m_Flags) ^ 2 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 2;
  }
}

// File Line: 2196
// RVA: 0x6551C0
void __fastcall UFG::TSVehicle::Mthd_set_attacked_via_formation(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  bool v4; // dl
  UFG::SimComponent *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = v3->m_Components.p[24].m_pComponent;
    if ( v5 )
    {
      v5[30].m_TypeUID &= 0xFFFFFFFD;
      v5[30].m_TypeUID |= 2 * (v4 != 0);
      v6 = v5[26].m_BoundComponentHandles.mNode.mPrev;
      if ( v6 )
        BYTE4(v6[38].mPrev) = v4;
    }
  }
}

// File Line: 2212
// RVA: 0x655BE0
void __fastcall UFG::TSVehicle::Mthd_set_formation_slot_availability(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::TSVehicle *v4; // rbp
  const char **v5; // rbx
  SSInstance *v6; // rsi
  bool v7; // r14
  CarCombat::Position v8; // edi
  int v9; // eax
  UFG::SimObject *v10; // rax
  UFG::SimComponent *v11; // rcx
  UFG::VehicleFormations *v12; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = CarCombat::mPositionName;
  v6 = (*v3)->i_data_p;
  v7 = v3[1]->i_data_p->i_user_data != 0;
  v8 = 0;
  while ( 1 )
  {
    v9 = stricmp(*(const char **)v6->i_user_data, *v5);
    if ( v9 <= 0 && v9 >= 0 )
      break;
    ++v5;
    ++v8;
    if ( (signed __int64)v5 >= (signed __int64)&CarStopTrack::sClassName )
      return;
  }
  if ( v8 != 7 )
  {
    v10 = v4->mpSimObj.m_pPointer;
    if ( v10 )
    {
      v11 = v10->m_Components.p[24].m_pComponent;
      if ( v11 )
      {
        v12 = (UFG::VehicleFormations *)v11[26].m_BoundComponentHandles.mNode.mPrev;
        if ( v12 )
          UFG::VehicleFormations::SetSlotUsability(v12, v8, v7);
      }
    }
  }
}

// File Line: 2250
// RVA: 0x654C70
void __fastcall UFG::TSVehicle::Mthd_is_in_deep_water(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance **v4; // rbx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::PhysicsWheeledVehicle *v7; // rcx
  bool v8; // al

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 )
      goto LABEL_12;
    v5 = v3->m_Components.p[34].m_pComponent;
    if ( !v5 )
      goto LABEL_12;
    v6 = v5[10].m_SafePointerList.mNode.mPrev;
    if ( !v6 )
      goto LABEL_12;
    v7 = 0i64;
    if ( BYTE4(v6[37].mNext) & 7 )
      v7 = (UFG::PhysicsWheeledVehicle *)v6;
    if ( v7 )
    {
      v8 = UFG::PhysicsWheeledVehicle::IsInDeepWater(v7);
      *v4 = (SSInstance *)SSBoolean::pool_new(v8);
    }
    else
    {
LABEL_12:
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 2269
// RVA: 0x654B20
void __fastcall UFG::TSVehicle::Mthd_is_boat_in_water(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  char v4; // al
  SSInstance **v5; // rbx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 )
      v4 = UFG::SimObjectUtility::IsBoatInWater(v3);
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 2287
// RVA: 0x654D30
void __fastcall UFG::TSVehicle::Mthd_is_occupying_selected_stop(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(0);
}

// File Line: 2297
// RVA: 0x655220
void __fastcall UFG::TSVehicle::Mthd_set_audio_driver_type(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectVehicle *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::VehicleAudioComponent *v5; // r8
  SSInstance *v6; // r10
  unsigned __int64 v7; // rcx
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

  v3 = (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    if ( v5 )
    {
      v6 = (*v4->i_data.i_array_p)->i_data_p;
      v7 = v6->i_user_data;
      v8 = *(_BYTE **)v7;
      v9 = *(unsigned int *)(v7 + 8) + *(_QWORD *)v7 + 1i64;
      if ( *(_QWORD *)v7 >= v9 )
      {
LABEL_7:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = 2;
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
      v11 = v6->i_user_data;
      v12 = *(_BYTE **)v11;
      v13 = *(unsigned int *)(v11 + 8) + *(_QWORD *)v11 + 1i64;
      if ( *(_QWORD *)v11 >= v13 )
      {
LABEL_12:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = 4;
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
      v15 = v6->i_user_data;
      v16 = *(_BYTE **)v15;
      v17 = *(unsigned int *)(v15 + 8) + *(_QWORD *)v15 + 1i64;
      if ( *(_QWORD *)v15 >= v17 )
      {
LABEL_17:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = 0;
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
      v19 = v6->i_user_data;
      v20 = *(_BYTE **)v19;
      v21 = *(unsigned int *)(v19 + 8) + *(_QWORD *)v19 + 1i64;
      if ( *(_QWORD *)v19 >= v21 )
      {
LABEL_22:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = 1;
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
      v23 = v6->i_user_data;
      v24 = *(_BYTE **)v23;
      v25 = *(unsigned int *)(v23 + 8) + *(_QWORD *)v23 + 1i64;
      if ( *(_QWORD *)v23 >= v25 )
      {
LABEL_27:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = 3;
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
      v27 = v6->i_user_data;
      v28 = *(_BYTE **)v27;
      v29 = *(unsigned int *)(v27 + 8) + *(_QWORD *)v27 + 1i64;
      if ( *(_QWORD *)v27 >= v29 )
      {
LABEL_32:
        v5->m_bOverrideDriverType = 1;
        v5->m_eOverridenDriverType = 5;
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
      v31 = v6->i_user_data;
      v32 = *(_BYTE **)v31;
      v33 = *(unsigned int *)(v31 + 8) + *(_QWORD *)v31 + 1i64;
      if ( *(_QWORD *)v31 >= v33 )
      {
LABEL_37:
        v5->m_bOverrideDriverType = 0;
        v5->m_eOverridenDriverType = -1;
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
void __fastcall UFG::TSVehicle::Mthd_add_steering_noise(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rdi
  UFG::AiDriverComponent *v5; // rbx
  SSData **v6; // rax
  float v7; // xmm6_4
  float v8; // xmm0_4

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    if ( v5 )
    {
      v6 = v4->i_data.i_array_p;
      if ( (*v6)->i_data_p->i_user_data )
      {
        v7 = *(float *)&v6[1]->i_data_p->i_user_data;
        UFG::AiDriverComponent::AddSteeringNoise(v5, v7);
        if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 2) + 8i64) + 32i64) )
        {
          v5->m_fSteeringNoiseAmplitudeMin = v7;
          v8 = v5->m_fSteeringNoiseAmplitude;
          if ( v8 <= v7 )
            v8 = v7;
          v5->m_fSteeringNoiseAmplitude = v8;
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
void __fastcall UFG::TSVehicle::Mthd_attach_vehicle_across_street(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::RoadSpaceComponent *v4; // rbx
  UFG::SimObject *v5; // rdi
  UFG::RoadNetworkGuide *v6; // rsi
  UFG::RoadNetworkLocation *v7; // rax
  UFG::RoadNetworkLocation *v8; // rbx
  UFG::RoadNetworkNode *v9; // rax
  UFG::RoadNetworkLane *v10; // r15
  float v11; // xmm6_4
  UFG::RoadNetworkSegment *v12; // rdi
  UFG::RoadNetworkLane *v13; // r14
  UFG::RoadNetworkLane *v14; // rbp
  bool v15; // bl
  bool v16; // bl
  UFG::RoadNetworkLane *v17; // rbx
  float laneT; // xmm0_4

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    v4 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
    if ( v4 )
    {
      v5 = v4->m_pSimObject;
      if ( v5 )
        v5 = (UFG::SimObject *)v5->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
      UFG::RoadSpaceComponent::AttachToRoadNetwork(v4, (UFG::qVector3 *)v5[1].mNode.mChild, 0i64);
      v6 = &v4->mGuide;
      v7 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&v4->mGuide);
      v8 = v7;
      v9 = UFG::RoadNetworkLocation::GetRoadNetworkNode(v7);
      v10 = v8->m_CurrentLane;
      v11 = v8->m_LaneT;
      v12 = (UFG::RoadNetworkSegment *)v9;
      if ( v9->mNumLanes > 1u && !v9->mType.mValue )
      {
        v13 = UFG::RoadNetworkNode::GetLane(v9, 0);
        v14 = UFG::RoadNetworkNode::GetLane(
                (UFG::RoadNetworkNode *)&v12->mType,
                (unsigned int)(unsigned __int8)v12->mNumLanes - 1);
        v15 = UFG::RoadNetworkLane::IsReversedInNode(v14);
        if ( UFG::RoadNetworkLane::IsReversedInNode(v13) != v15 )
        {
          v16 = UFG::RoadNetworkLane::IsReversedInNode(v13);
          if ( v16 != UFG::RoadNetworkLane::IsReversedInNode(v10) )
            v14 = v13;
          v17 = UFG::RoadNetworkSegment::GetClosestLaneToCenter(v12, v14->mLaneIndex);
          laneT = UFG::RoadNetworkSegment::GetMatchingT(v12, v10->mLaneIndex, v11, v17->mLaneIndex);
          UFG::RoadNetworkGuide::AttachToNetwork(
            v6,
            v6->m_SimObj,
            (UFG::RoadNetworkNode *)&v12->mType,
            v17->mLaneIndex,
            laneT);
        }
      }
    }
  }
}

// File Line: 2423
// RVA: 0x655DA0
void __fastcall UFG::TSVehicle::Mthd_set_prevent_hijack(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AiDriverComponent *v3; // r8

  v3 = (UFG::AiDriverComponent *)this->mAIDriverComponent.m_pSimComponent;
  if ( v3 )
    v3->m_bDeniesHijack = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 2438
// RVA: 0x654DD0
void __fastcall UFG::TSVehicle::Mthd_is_vehicle_in_opposite_lane(UFG::TSVehicle *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::TransformNodeComponent *v4; // rbx
  SSInstance **v5; // rsi
  UFG::SimComponent *v6; // rdx
  UFG::RoadNetworkGuide *v7; // rdi
  UFG::RoadNetworkLocation *v8; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0i64;
    v5 = ppResult;
    if ( v3 )
      v6 = v3->m_Components.p[24].m_pComponent;
    else
      v6 = 0i64;
    if ( v3 )
      v4 = (UFG::TransformNodeComponent *)v3->m_Components.p[2].m_pComponent;
    if ( v6 )
    {
      if ( v4 )
      {
        v7 = (UFG::RoadNetworkGuide *)&v6[5].m_BoundComponentHandles.mNode.mNext;
        if ( v6 != (UFG::SimComponent *)-376i64 )
        {
          if ( (unsigned __int8)UFG::RoadNetworkGuide::IsCurrentLocationValid((UFG::RoadNetworkGuide *)&v6[5].m_BoundComponentHandles.mNode.mNext) )
          {
            v8 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v7);
            UFG::RoadNetworkLocation::GetTangent(v8, &result);
            UFG::TransformNodeComponent::UpdateWorldTransform(v4);
            *v5 = (SSInstance *)SSBoolean::pool_new((float)((float)((float)(result.y * v4->mWorldTransform.v0.y)
                                                                  + (float)(result.x * v4->mWorldTransform.v0.x))
                                                          + (float)(result.z * v4->mWorldTransform.v0.z)) < 0.0);
          }
        }
      }
    }
  }
}

