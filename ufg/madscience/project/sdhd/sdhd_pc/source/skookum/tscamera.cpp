// File Line: 50
// RVA: 0x1531030
__int64 dynamic_initializer_for__UFG::TSCamera::gCCTVColourCubeUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("COLOURCUBE_BLACKANDWHITE", -1);
  UFG::TSCamera::gCCTVColourCubeUID = result;
  return result;
}

// File Line: 61
// RVA: 0x4CE910
void UFG::TSCamera::BindAtomics(void)
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
  ASymbol rebindr; // [rsp+20h] [rbp-18h]
  ASymbol rebinds; // [rsp+20h] [rbp-18h]
  ASymbol rebindt; // [rsp+20h] [rbp-18h]
  ASymbol rebindu; // [rsp+20h] [rbp-18h]
  ASymbol rebindv; // [rsp+20h] [rbp-18h]
  ASymbol rebindw; // [rsp+20h] [rbp-18h]
  ASymbol rebindx; // [rsp+20h] [rbp-18h]
  ASymbol rebindy; // [rsp+20h] [rbp-18h]
  ASymbol rebindz; // [rsp+20h] [rbp-18h]
  ASymbol rebindba; // [rsp+20h] [rbp-18h]
  ASymbol rebindbb; // [rsp+20h] [rbp-18h]
  ASymbol rebindbc; // [rsp+20h] [rbp-18h]
  ASymbol rebindbd; // [rsp+20h] [rbp-18h]
  ASymbol rebindbe; // [rsp+20h] [rbp-18h]
  ASymbol rebindbf; // [rsp+20h] [rbp-18h]
  ASymbol rebindbg; // [rsp+20h] [rbp-18h]
  ASymbol rebindbh; // [rsp+20h] [rbp-18h]
  ASymbol rebindbi; // [rsp+20h] [rbp-18h]
  ASymbol rebindbj; // [rsp+20h] [rbp-18h]
  ASymbol rebindbk; // [rsp+20h] [rbp-18h]
  ASymbol rebindbl; // [rsp+20h] [rbp-18h]
  ASymbol rebindbm; // [rsp+20h] [rbp-18h]
  ASymbol rebindbn; // [rsp+20h] [rbp-18h]
  ASymbol rebindbo; // [rsp+20h] [rbp-18h]
  ASymbol rebindbp; // [rsp+20h] [rbp-18h]
  ASymbol rebindbq; // [rsp+20h] [rbp-18h]
  ASymbol rebindbr; // [rsp+20h] [rbp-18h]
  ASymbol rebindbs; // [rsp+20h] [rbp-18h]
  ASymbol rebindbt; // [rsp+20h] [rbp-18h]
  ASymbol rebindbu; // [rsp+20h] [rbp-18h]
  ASymbol rebindbv; // [rsp+20h] [rbp-18h]
  ASymbol rebindbw; // [rsp+20h] [rbp-18h]
  ASymbol rebindbx; // [rsp+20h] [rbp-18h]
  ASymbol rebindby; // [rsp+20h] [rbp-18h]
  ASymbol rebindbz; // [rsp+20h] [rbp-18h]
  ASymbol rebindca; // [rsp+20h] [rbp-18h]
  ASymbol rebindcb; // [rsp+20h] [rbp-18h]
  ASymbol rebindcc; // [rsp+20h] [rbp-18h]
  ASymbol rebindcd; // [rsp+20h] [rbp-18h]
  ASymbol rebindce; // [rsp+20h] [rbp-18h]
  ASymbol rebindcf; // [rsp+20h] [rbp-18h]
  ASymbol rebindcg; // [rsp+20h] [rbp-18h]
  ASymbol rebindch; // [rsp+20h] [rbp-18h]
  ASymbol rebindci; // [rsp+20h] [rbp-18h]
  ASymbol rebindcj; // [rsp+20h] [rbp-18h]
  ASymbol rebindck; // [rsp+20h] [rbp-18h]
  ASymbol rebindcl; // [rsp+20h] [rbp-18h]
  ASymbol rebindcm; // [rsp+20h] [rbp-18h]
  ASymbol rebindcn; // [rsp+20h] [rbp-18h]
  ASymbol rebindco; // [rsp+20h] [rbp-18h]
  ASymbol rebindcp; // [rsp+20h] [rbp-18h]
  ASymbol rebindcq; // [rsp+20h] [rbp-18h]
  ASymbol rebindcr; // [rsp+20h] [rbp-18h]
  ASymbol rebindcs; // [rsp+20h] [rbp-18h]
  ASymbol rebindct; // [rsp+20h] [rbp-18h]
  ASymbol rebindcu; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Camera");
  SSClass::register_method_func(v0, "is_using_high_zoom", UFG::TSCamera::MthdC_is_using_high_zoom, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_animated_marker_xform",
    UFG::TSCamera::MthdC_set_animated_marker_xform,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_xform",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))UFG::TSCamera::MthdC_set_xform,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_fov", UFG::TSCamera::MthdC_set_fov, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "release_camera", UFG::TSCamera::MthdC_release_camera, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "set_target", UFG::TSCamera::MthdC_set_target, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "set_look_offset", UFG::TSCamera::MthdC_set_look_offset, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_eye_offset_from_target",
    UFG::TSCamera::MthdC_set_eye_offset_from_target,
    1,
    rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "attach_to_xform", UFG::TSCamera::MthdC_set_following, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "target_xform", UFG::TSCamera::MthdC_target_xform, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "pan_to_xform", UFG::TSCamera::MthdC_pan_to_xform, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(v0, "get_xform", UFG::TSCamera::MthdC_get_debug_xform, 1, rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_allow_script_camera_super_wide_aspect",
    UFG::TSCamera::MthdC_set_allow_script_camera_super_wide_aspect,
    1,
    rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "return_xform_relative_player",
    UFG::TSCamera::MthdC_return_xform_relative_player,
    1,
    rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(v0, "reset", UFG::TSCamera::MthdC_reset, 1, rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(v0, "set_dof", UFG::TSCamera::MthdC_set_dof, 1, rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(v0, "reset_dof", UFG::TSCamera::MthdC_reset_dof, 1, rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(v0, "start_dynamic_dof", UFG::TSCamera::MthdC_start_dynamic_dof, 1, rebindq);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(v0, "stop_dynamic_dof", UFG::TSCamera::MthdC_stop_dynamic_dof, 1, rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_dynamic_dof_focal_dist",
    UFG::TSCamera::MthdC_set_dynamic_dof_focal_dist,
    1,
    rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(v0, "set_dynamic_dof_range", UFG::TSCamera::MthdC_set_dynamic_dof_range, 1, rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_dynamic_dof_near_blend",
    UFG::TSCamera::MthdC_set_dynamic_dof_near_blend,
    1,
    rebindu);
  LOBYTE(rebindv.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_dynamic_dof_near_blur",
    UFG::TSCamera::MthdC_set_dynamic_dof_near_blur,
    1,
    rebindv);
  LOBYTE(rebindw.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_dynamic_dof_far_blend",
    UFG::TSCamera::MthdC_set_dynamic_dof_far_blend,
    1,
    rebindw);
  LOBYTE(rebindx.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_dynamic_dof_far_blur",
    UFG::TSCamera::MthdC_set_dynamic_dof_far_blur,
    1,
    rebindx);
  LOBYTE(rebindy.i_uid) = 0;
  SSClass::register_method_func(v0, "set_dutch", UFG::TSCamera::MthdC_set_dutch, 1, rebindy);
  LOBYTE(rebindz.i_uid) = 0;
  SSClass::register_method_func(v0, "reset_dutch", UFG::TSCamera::MthdC_reset_dutch, 1, rebindz);
  LOBYTE(rebindba.i_uid) = 0;
  SSClass::register_method_func(v0, "set_dynamic_dutch", UFG::TSCamera::MthdC_set_dynamic_dutch, 1, rebindba);
  LOBYTE(rebindbb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_override_max_radius",
    UFG::TSCamera::MthdC_set_override_max_radius,
    1,
    rebindbb);
  LOBYTE(rebindbc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_override_max_radius",
    UFG::TSCamera::MthdC_clear_override_max_radius,
    1,
    rebindbc);
  LOBYTE(rebindbd.i_uid) = 0;
  SSClass::register_method_func(v0, "set_override_rise", UFG::TSCamera::MthdC_set_override_rise, 1, rebindbd);
  LOBYTE(rebindbe.i_uid) = 0;
  SSClass::register_method_func(v0, "clear_override_rise", UFG::TSCamera::MthdC_clear_override_rise, 1, rebindbe);
  LOBYTE(rebindbf.i_uid) = 0;
  SSClass::register_method_func(v0, "goto_angle", UFG::TSCamera::MthdC_goto_angle, 1, rebindbf);
  LOBYTE(rebindbg.i_uid) = 0;
  SSClass::register_method_func(v0, "goto_angle_snap", UFG::TSCamera::MthdC_goto_angle_snap, 1, rebindbg);
  LOBYTE(rebindbh.i_uid) = 0;
  SSClass::register_method_func(v0, "goto_rise", UFG::TSCamera::MthdC_goto_rise, 1, rebindbh);
  LOBYTE(rebindbi.i_uid) = 0;
  SSClass::register_method_func(v0, "goto_rise_snap", UFG::TSCamera::MthdC_goto_rise_snap, 1, rebindbi);
  LOBYTE(rebindbj.i_uid) = 0;
  SSClass::register_method_func(v0, "goto_radius", UFG::TSCamera::MthdC_goto_radius, 1, rebindbj);
  LOBYTE(rebindbk.i_uid) = 0;
  SSClass::register_method_func(v0, "enable_constrain_yaw", UFG::TSCamera::MthdC_enable_constrain_yaw, 1, rebindbk);
  LOBYTE(rebindbl.i_uid) = 0;
  SSClass::register_method_func(v0, "disable_constrain_yaw", UFG::TSCamera::MthdC_disable_constrain_yaw, 1, rebindbl);
  LOBYTE(rebindbm.i_uid) = 0;
  SSClass::register_method_func(v0, "enable_combat_system", UFG::TSCamera::MthdC_enable_combat_system, 1, rebindbm);
  LOBYTE(rebindbn.i_uid) = 0;
  SSClass::register_method_func(v0, "disable_combat_system", UFG::TSCamera::MthdC_disable_combat_system, 1, rebindbn);
  LOBYTE(rebindbo.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "combat_system_snap_next_auto_frame",
    UFG::TSCamera::MthdC_combat_system_snap_next_auto_frame,
    1,
    rebindbo);
  LOBYTE(rebindbp.i_uid) = 0;
  SSClass::register_method_func(v0, "set_allow_targeted", UFG::TSCamera::MthdC_set_allow_targeted, 1, rebindbp);
  LOBYTE(rebindbq.i_uid) = 0;
  SSClass::register_method_func(v0, "set_allow_desaturation", UFG::TSCamera::MthdC_set_allow_desaturation, 1, rebindbq);
  LOBYTE(rebindbr.i_uid) = 0;
  SSClass::register_method_func(v0, "set_eye_look_noise", UFG::TSCamera::MthdC_set_eye_look_noise, 1, rebindbr);
  LOBYTE(rebindbs.i_uid) = 0;
  SSClass::register_method_func(v0, "impact", UFG::TSCamera::MthdC_impact, 1, rebindbs);
  LOBYTE(rebindbt.i_uid) = 0;
  SSClass::register_method_func(v0, "unlock_chase_camera", UFG::TSCamera::MthdC_unlock_chase_camera, 1, rebindbt);
  LOBYTE(rebindbu.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_tow",
    UFG::TSCamera::MthdC_set_context_override_tow,
    1,
    rebindbu);
  LOBYTE(rebindbv.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_aim",
    UFG::TSCamera::MthdC_set_context_override_aim,
    1,
    rebindbv);
  LOBYTE(rebindbw.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_focus",
    UFG::TSCamera::MthdC_set_context_override_focus,
    1,
    rebindbw);
  LOBYTE(rebindbx.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_grapple",
    UFG::TSCamera::MthdC_set_context_override_grapple,
    1,
    rebindbx);
  LOBYTE(rebindby.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_tow",
    UFG::TSCamera::MthdC_clear_context_override_tow,
    1,
    rebindby);
  LOBYTE(rebindbz.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_aim",
    UFG::TSCamera::MthdC_clear_context_override_aim,
    1,
    rebindbz);
  LOBYTE(rebindca.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_focus",
    UFG::TSCamera::MthdC_clear_context_override_focus,
    1,
    rebindca);
  LOBYTE(rebindcb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_grapple",
    UFG::TSCamera::MthdC_clear_context_override_grapple,
    1,
    rebindcb);
  LOBYTE(rebindcc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_local_tow",
    UFG::TSCamera::MthdC_set_context_override_local_tow,
    1,
    rebindcc);
  LOBYTE(rebindcd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_local_aim",
    UFG::TSCamera::MthdC_set_context_override_local_aim,
    1,
    rebindcd);
  LOBYTE(rebindce.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_local_focus",
    UFG::TSCamera::MthdC_set_context_override_local_focus,
    1,
    rebindce);
  LOBYTE(rebindcf.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_context_override_local_grapple",
    UFG::TSCamera::MthdC_set_context_override_local_grapple,
    1,
    rebindcf);
  LOBYTE(rebindcg.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_tow",
    UFG::TSCamera::MthdC_clear_context_override_local_tow,
    1,
    rebindcg);
  LOBYTE(rebindch.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_aim",
    UFG::TSCamera::MthdC_clear_context_override_local_aim,
    1,
    rebindch);
  LOBYTE(rebindci.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_focus",
    UFG::TSCamera::MthdC_clear_context_override_local_focus,
    1,
    rebindci);
  LOBYTE(rebindcj.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_grapple",
    UFG::TSCamera::MthdC_clear_context_override_local_grapple,
    1,
    rebindcj);
  LOBYTE(rebindck.i_uid) = 0;
  SSClass::register_method_func(v0, "set_social_target", UFG::TSCamera::MthdC_set_social_target, 1, rebindck);
  LOBYTE(rebindcl.i_uid) = 0;
  SSClass::register_method_func(v0, "clear_social_target", UFG::TSCamera::MthdC_clear_social_target, 1, rebindcl);
  LOBYTE(rebindcm.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_birds_eye",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindcm);
  LOBYTE(rebindcn.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "progression_set_monotonically_increasing",
    UFG::TSCamera::MthdC_progression_set_monotonically_increasing,
    1,
    rebindcn);
  LOBYTE(rebindco.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "progression_set_window_size",
    UFG::TSCamera::MthdC_progression_set_window_size,
    1,
    rebindco);
  LOBYTE(rebindcp.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "progression_set_duration",
    UFG::TSCamera::MthdC_progression_set_duration,
    1,
    rebindcp);
  LOBYTE(rebindcq.i_uid) = 0;
  SSClass::register_method_func(v0, "progression_begin", UFG::TSCamera::MthdC_progression_begin, 1, rebindcq);
  LOBYTE(rebindcr.i_uid) = 0;
  SSClass::register_method_func(v0, "progression_end", UFG::TSCamera::MthdC_progression_end, 1, rebindcr);
  LOBYTE(rebindcs.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "progression_set_progress_transforms",
    UFG::TSCamera::MthdC_progression_set_progress_transforms,
    1,
    rebindcs);
  LOBYTE(rebindct.i_uid) = 0;
  SSClass::register_method_func(v0, "animation_begin", UFG::TSCamera::MthdC_animation_begin, 1, rebindct);
  LOBYTE(rebindcu.i_uid) = 0;
  SSClass::register_method_func(v0, "animation_end", UFG::TSCamera::MthdC_animation_end, 1, rebindcu);
}

// File Line: 163
// RVA: 0x4E9D60
void __fastcall UFG::TSCamera::MthdC_is_using_high_zoom(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool IsCameraUsingHighZoom; // al

  if ( ppResult )
  {
    IsCameraUsingHighZoom = UFG::IsCameraUsingHighZoom();
    *ppResult = SSBoolean::pool_new(IsCameraUsingHighZoom);
  }
}

// File Line: 176
// RVA: 0x4ED2B0
void __fastcall UFG::TSCamera::MthdC_set_animated_marker_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 i_user_data; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  UFG::qVector4 v6; // xmm0

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(UFG::TransformNodeComponent **)(i_user_data + 104);
  if ( !v3 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
    v3 = (UFG::TransformNodeComponent *)i_user_data;
  if ( v3 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v4 = v3->mWorldTransform.v2;
    v5 = v3->mWorldTransform.v3;
    v6 = v3->mWorldTransform.v0;
    UFG::AnimatedCameraComponent::mMarkerTransform.v1 = v3->mWorldTransform.v1;
    UFG::AnimatedCameraComponent::mMarkerTransform.v2 = v4;
    UFG::AnimatedCameraComponent::mMarkerTransform.v0 = v6;
    UFG::AnimatedCameraComponent::mMarkerTransform.v3 = v5;
  }
}

// File Line: 190
// RVA: 0x4EF760
void __fastcall UFG::TSCamera::MthdC_set_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rbp
  SSData **i_array_p; // rsi
  UFG::TransformNodeComponent *i_user_data; // rbx
  UFG::TransformNodeComponent *mParent; // rdi

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_user_data = (UFG::TransformNodeComponent *)(*i_array_p)->i_data_p->i_user_data;
      mParent = i_user_data->mParent;
      if ( !mParent || !UFG::qMatrix44::operator==(&i_user_data->mLocalTransform, &UFG::qMatrix44::msIdentity) )
        mParent = i_user_data;
      UFG::ScriptCameraComponent::SwitchToScriptCam(
        ComponentOfType,
        mParent,
        i_array_p[1]->i_data_p->i_user_data != 0,
        *(float *)&i_array_p[2]->i_data_p->i_user_data);
    }
  }
}

// File Line: 205
// RVA: 0x4EDE40
void __fastcall UFG::TSCamera::MthdC_set_fov(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  char *v5; // rbx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      v5 = (char *)&ComponentOfType[21].m_pSimObject + 4;
      LODWORD(ComponentOfType[22].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)((char *)&ComponentOfType[21].m_pSimObject + 4));
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 6) = *((_DWORD *)v5 + 7);
      *((_DWORD *)v5 + 8) = *((_DWORD *)v5 + 9);
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)v5);
      *((_DWORD *)v5 + 1) = 0;
    }
  }
}

// File Line: 216
// RVA: 0x4EC140
void __fastcall UFG::TSCamera::MthdC_release_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ScriptCameraComponent::ReleaseCamera(
        ComponentOfType,
        (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 231
// RVA: 0x4EF2C0
void __fastcall UFG::TSCamera::MthdC_set_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax

  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))i_class_p->vfptr->is_actor_class)(i_class_p, ppResult) )
    goto LABEL_7;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_6:
    i_data_p = 0i64;
LABEL_7:
  v4 = (UFG::TransformNodeComponent *)i_data_p[1].i_class_p;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ScriptCameraComponent::SetTarget(ComponentOfType, v4);
  }
}

// File Line: 244
// RVA: 0x4EE270
void __fastcall UFG::TSCamera::MthdC_set_look_offset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  SSData **i_array_p; // r8
  int i_user_data; // xmm1_4
  int v7; // xmm0_4

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_user_data = i_array_p[1]->i_data_p->i_user_data;
      v7 = i_array_p[2]->i_data_p->i_user_data;
      HIDWORD(ComponentOfType[28].vfptr) = (*i_array_p)->i_data_p->i_user_data;
      LODWORD(ComponentOfType[28].m_SafePointerList.mNode.mPrev) = i_user_data;
      HIDWORD(ComponentOfType[28].m_SafePointerList.mNode.mPrev) = v7;
    }
  }
}

// File Line: 255
// RVA: 0x4EDCC0
void __fastcall UFG::TSCamera::MthdC_set_eye_offset_from_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax
  SSData **i_array_p; // r8
  float v6; // xmm2_4
  float v7; // xmm0_4
  UFG::qVector3 offset; // [rsp+20h] [rbp-18h] BYREF

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      v6 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
      v7 = *(float *)&(*i_array_p)->i_data_p->i_user_data;
      offset.y = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      offset.x = v7;
      offset.z = v6;
      UFG::ScriptCameraComponent::SetEyeOffsetFromTarget(ComponentOfType, &offset);
    }
  }
}

// File Line: 267
// RVA: 0x4F2800
void __fastcall UFG::TSCamera::MthdC_target_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rsi
  unsigned __int64 i_user_data; // rdi
  UFG::TransformNodeComponent *v6; // rbx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      v6 = *(UFG::TransformNodeComponent **)(i_user_data + 104);
      if ( !v6 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
        v6 = (UFG::TransformNodeComponent *)i_user_data;
      UFG::ScriptCameraComponent::SetTarget(ComponentOfType, v6);
    }
  }
}

// File Line: 279
// RVA: 0x4EDDA0
void __fastcall UFG::TSCamera::MthdC_set_following(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rsi
  unsigned __int64 i_user_data; // rdi
  UFG::TransformNodeComponent *v6; // rbx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      v6 = *(UFG::TransformNodeComponent **)(i_user_data + 104);
      if ( !v6 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
        v6 = (UFG::TransformNodeComponent *)i_user_data;
      UFG::ScriptCameraComponent::SetEyeAttachment(ComponentOfType, v6);
    }
  }
}

// File Line: 291
// RVA: 0x4EB150
void __fastcall UFG::TSCamera::MthdC_pan_to_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rbp
  SSData **i_array_p; // rsi
  UFG::TransformNodeComponent *i_user_data; // rbx
  UFG::TransformNodeComponent *mParent; // rdi

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_user_data = (UFG::TransformNodeComponent *)(*i_array_p)->i_data_p->i_user_data;
      mParent = i_user_data->mParent;
      if ( !mParent || !UFG::qMatrix44::operator==(&i_user_data->mLocalTransform, &UFG::qMatrix44::msIdentity) )
        mParent = i_user_data;
      UFG::ScriptCameraComponent::PanToTransform(
        ComponentOfType,
        mParent,
        *(float *)&i_array_p[1]->i_data_p->i_user_data,
        *(float *)&i_array_p[2]->i_data_p->i_user_data);
    }
  }
}

// File Line: 307
// RVA: 0x4E75B0
void __fastcall UFG::TSCamera::MthdC_get_debug_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::TransformNodeComponent *v4; // rbx
  UFG::Camera *p_mCamera; // rcx
  UFG::qMatrix44 *ViewWorld; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  UFG::BaseCameraComponent *v19; // rax
  _DWORD *p_mFOVOffset; // rax
  int v21; // xmm2_4
  int v22; // xmm1_4
  UFG::BaseCameraComponent *v23; // rax
  _DWORD *v24; // rax
  int v25; // xmm2_4
  int v26; // xmm1_4
  UFG::BaseCameraComponent *v27; // rax
  UFG::Camera *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm2_4
  UFG::BaseCameraComponent *v31; // rax
  UFG::Camera *v32; // rax
  float v33; // xmm1_4
  float v34; // xmm2_4
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v36; // rdi
  unsigned int v37; // eax
  UFG::TransformNodeComponent *v38; // rax
  UFG::qMatrix44 m; // [rsp+38h] [rbp+7h] BYREF

  if ( ppResult )
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    v4 = 0i64;
    if ( mCurrentCamera )
      p_mCamera = &mCurrentCamera->mCamera;
    else
      p_mCamera = 0i64;
    ViewWorld = UFG::Camera::GetViewWorld(p_mCamera);
    y = ViewWorld->v0.y;
    z = ViewWorld->v0.z;
    w = ViewWorld->v0.w;
    m.v0.x = ViewWorld->v0.x;
    m.v0.y = y;
    m.v0.z = z;
    m.v0.w = w;
    v10 = ViewWorld->v1.y;
    v11 = ViewWorld->v1.z;
    v12 = ViewWorld->v1.w;
    m.v1.x = ViewWorld->v1.x;
    m.v1.y = v10;
    m.v1.z = v11;
    m.v1.w = v12;
    v13 = ViewWorld->v2.y;
    v14 = ViewWorld->v2.z;
    v15 = ViewWorld->v2.w;
    m.v2.x = ViewWorld->v2.x;
    m.v2.y = v13;
    m.v2.z = v14;
    m.v2.w = v15;
    v16 = ViewWorld->v3.y;
    v17 = ViewWorld->v3.z;
    v18 = ViewWorld->v3.w;
    m.v3.x = ViewWorld->v3.x;
    m.v3.y = v16;
    m.v3.z = v17;
    m.v3.w = v18;
    v19 = UFG::Director::Get()->mCurrentCamera;
    if ( v19 )
      p_mFOVOffset = (_DWORD *)&v19->mCamera.mFOVOffset;
    else
      p_mFOVOffset = 0i64;
    v21 = p_mFOVOffset[42] ^ _xmm[0];
    v22 = p_mFOVOffset[41] ^ _xmm[0];
    LODWORD(m.v0.x) = p_mFOVOffset[40] ^ _xmm[0];
    LODWORD(m.v0.y) = v22;
    LODWORD(m.v0.z) = v21;
    m.v0.w = 0.0;
    v23 = UFG::Director::Get()->mCurrentCamera;
    if ( v23 )
      v24 = (_DWORD *)&v23->mCamera.mFOVOffset;
    else
      v24 = 0i64;
    v25 = v24[34] ^ _xmm[0];
    v26 = v24[33] ^ _xmm[0];
    LODWORD(m.v1.x) = v24[32] ^ _xmm[0];
    LODWORD(m.v1.y) = v26;
    LODWORD(m.v1.z) = v25;
    m.v1.w = 0.0;
    v27 = UFG::Director::Get()->mCurrentCamera;
    if ( v27 )
      v28 = &v27->mCamera;
    else
      v28 = 0i64;
    v29 = v28->mTransformation.v1.y;
    v30 = v28->mTransformation.v1.z;
    m.v2.x = v28->mTransformation.v1.x;
    m.v2.y = v29;
    m.v2.z = v30;
    m.v2.w = 0.0;
    v31 = UFG::Director::Get()->mCurrentCamera;
    if ( v31 )
      v32 = &v31->mCamera;
    else
      v32 = 0i64;
    v33 = v32->mTransformation.v3.y;
    v34 = v32->mTransformation.v3.z;
    m.v3.x = v32->mTransformation.v3.x;
    m.v3.y = v33;
    m.v3.z = v34;
    LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v36 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TSCamera", 0i64, 1u);
    if ( v36 )
    {
      v37 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v36, v37, 0i64, 0);
      v4 = v38;
    }
    if ( v4 )
    {
      UFG::TransformNodeComponent::SetWorldTransform(v4, &m);
      *ppResult = UFG::TSTransform::AsInstance(v4);
    }
  }
}

// File Line: 329
// RVA: 0x4ED210
void __fastcall UFG::TSCamera::MthdC_set_allow_script_camera_super_wide_aspect(
        SSInvokedMethod *scope,
        SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
      ComponentOfType->bAllowWideAspectDisplay = (*scope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 345
// RVA: 0x4ED760
void __fastcall UFG::TSCamera::MthdC_set_dof(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rbx
  SSData **i_array_p; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      UFG::ScriptCameraComponent::SetDOF(
        ComponentOfType,
        *(float *)&(*i_array_p)->i_data_p->i_user_data,
        *(float *)&i_array_p[1]->i_data_p->i_user_data,
        *(float *)&i_array_p[2]->i_data_p->i_user_data,
        *(float *)&i_array_p[3]->i_data_p->i_user_data,
        *(float *)&i_array_p[4]->i_data_p->i_user_data,
        *(float *)&i_array_p[5]->i_data_p->i_user_data,
        1);
    }
  }
}

// File Line: 352
// RVA: 0x4EC360
void __fastcall UFG::TSCamera::MthdC_reset_dof(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ScriptCameraComponent::ResetDOF(ComponentOfType);
  }
}

// File Line: 361
// RVA: 0x4F2560
// attributes: thunk
void __fastcall UFG::TSCamera::MthdC_start_dynamic_dof(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::GameCameraComponent::StartDynamicDof();
}

// File Line: 366
// RVA: 0x4F26E0
// attributes: thunk
void __fastcall UFG::TSCamera::MthdC_stop_dynamic_dof(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::GameCameraComponent::StopDynamicDof();
}

// File Line: 371
// RVA: 0x4ED980
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_focal_dist(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8

  i_array_p = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FocalDistance,
    *(float *)&(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    *(float *)&i_array_p[2]->i_data_p->i_user_data,
    *(float *)&i_array_p[3]->i_data_p->i_user_data,
    *(float *)&i_array_p[4]->i_data_p->i_user_data,
    *(float *)&i_array_p[5]->i_data_p->i_user_data);
}

// File Line: 381
// RVA: 0x4EDB00
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_range(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8

  i_array_p = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FocusHalfRange,
    *(float *)&(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    *(float *)&i_array_p[2]->i_data_p->i_user_data,
    *(float *)&i_array_p[3]->i_data_p->i_user_data,
    *(float *)&i_array_p[4]->i_data_p->i_user_data,
    *(float *)&i_array_p[5]->i_data_p->i_user_data);
}

// File Line: 391
// RVA: 0x4EDA00
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_near_blend(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8

  i_array_p = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_NearBlendRange,
    *(float *)&(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    *(float *)&i_array_p[2]->i_data_p->i_user_data,
    *(float *)&i_array_p[3]->i_data_p->i_user_data,
    *(float *)&i_array_p[4]->i_data_p->i_user_data,
    *(float *)&i_array_p[5]->i_data_p->i_user_data);
}

// File Line: 401
// RVA: 0x4EDA80
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_near_blur(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8

  i_array_p = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_NearBlendRadius,
    *(float *)&(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    *(float *)&i_array_p[2]->i_data_p->i_user_data,
    *(float *)&i_array_p[3]->i_data_p->i_user_data,
    *(float *)&i_array_p[4]->i_data_p->i_user_data,
    *(float *)&i_array_p[5]->i_data_p->i_user_data);
}

// File Line: 411
// RVA: 0x4ED880
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_far_blend(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8

  i_array_p = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FarBlendRange,
    *(float *)&(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    *(float *)&i_array_p[2]->i_data_p->i_user_data,
    *(float *)&i_array_p[3]->i_data_p->i_user_data,
    *(float *)&i_array_p[4]->i_data_p->i_user_data,
    *(float *)&i_array_p[5]->i_data_p->i_user_data);
}

// File Line: 421
// RVA: 0x4ED900
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_far_blur(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8

  i_array_p = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FarBlendRadius,
    *(float *)&(*i_array_p)->i_data_p->i_user_data,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    *(float *)&i_array_p[2]->i_data_p->i_user_data,
    *(float *)&i_array_p[3]->i_data_p->i_user_data,
    *(float *)&i_array_p[4]->i_data_p->i_user_data,
    *(float *)&i_array_p[5]->i_data_p->i_user_data);
}

// File Line: 434
// RVA: 0x4ED820
void __fastcall UFG::TSCamera::MthdC_set_dutch(SSInvokedMethod *scope, SSInstance **result)
{
  if ( UFG::GetCurrentGameCamera() )
    UFG::GameCameraComponent::SetDutch(
      (float)(*(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)scope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 443
// RVA: 0x4EC3A0
void __fastcall UFG::TSCamera::MthdC_reset_dutch(SSInvokedMethod *scope, SSInstance **result)
{
  if ( UFG::GetCurrentGameCamera() )
    UFG::GameCameraComponent::ResetDutch((*scope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 452
// RVA: 0x4EDB80
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dutch(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r10

  if ( UFG::GetCurrentGameCamera() )
  {
    i_array_p = scope->i_data.i_array_p;
    UFG::GameCameraComponent::SetDynamicDutch(
      *(float *)&(*i_array_p)->i_data_p->i_user_data,
      *(float *)&i_array_p[1]->i_data_p->i_user_data,
      (float)(*(float *)&i_array_p[2]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      (float)(*(float *)&i_array_p[3]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      *(float *)&i_array_p[4]->i_data_p->i_user_data,
      *(float *)&i_array_p[5]->i_data_p->i_user_data,
      (float)(*(float *)&i_array_p[6]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      (float)(*(float *)&i_array_p[7]->i_data_p->i_user_data * 3.1415927) * 0.0055555557);
  }
}

// File Line: 467
// RVA: 0x4EE5B0
void __fastcall UFG::TSCamera::MthdC_set_override_max_radius(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::FollowCameraComponent::SetOverrideMaxRadius(
        ComponentOfType,
        *(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 477
// RVA: 0x4E4570
void __fastcall UFG::TSCamera::MthdC_clear_override_max_radius(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[110].m_SafePointerList.mNode.mNext) = 0;
  }
}

// File Line: 486
// RVA: 0x4EE600
void __fastcall UFG::TSCamera::MthdC_set_override_rise(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::FollowCameraComponent::SetOverrideRise(
        ComponentOfType,
        *(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 496
// RVA: 0x4E45B0
void __fastcall UFG::TSCamera::MthdC_clear_override_rise(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[110].m_NameUID) = 0;
  }
}

// File Line: 505
// RVA: 0x4E8A70
void __fastcall UFG::TSCamera::MthdC_goto_angle(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // r10
  SSData **i_array_p; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = scope->i_data.i_array_p;
      UFG::FollowCameraComponent::GotoAngle(
        ComponentOfType,
        (float)(*(float *)&(*i_array_p)->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
        (float)(*(float *)&i_array_p[1]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
        *(float *)&i_array_p[2]->i_data_p->i_user_data,
        i_array_p[3]->i_data_p->i_user_data != 0);
    }
  }
}

// File Line: 519
// RVA: 0x4E8B10
void __fastcall UFG::TSCamera::MthdC_goto_angle_snap(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSData **i_array_p; // rdx
  float v3; // xmm6_4
  bool v4; // bl
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax
  UFG::SimObject *v7; // rcx
  UFG::ChaseCameraComponent *v8; // rax

  i_array_p = scope->i_data.i_array_p;
  v3 = *(float *)&(*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data != 0;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::FollowCameraComponent::GotoAngleSnap(ComponentOfType, (float)(v3 * 3.1415927) * 0.0055555557, v4);
  }
  v7 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v7 )
  {
    v8 = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::ChaseCameraComponent::_TypeUID);
    if ( v8 )
      UFG::ChaseCameraComponent::GotoAngleSnap(v8, (float)(v3 * 3.1415927) * 0.0055555557, v4);
  }
}

// File Line: 533
// RVA: 0x4E8C40
void __fastcall UFG::TSCamera::MthdC_goto_rise(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::FollowCameraComponent::GotoRise(
        ComponentOfType,
        *(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data,
        *(float *)(*(_QWORD *)(*((_QWORD *)scope->i_data.i_array_p + 1) + 8i64) + 32i64),
        *(float *)(*(_QWORD *)(*((_QWORD *)scope->i_data.i_array_p + 2) + 8i64) + 32i64));
  }
}

// File Line: 546
// RVA: 0x4E8CB0
void __fastcall UFG::TSCamera::MthdC_goto_rise_snap(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::FollowCameraComponent::GotoRiseSnap(
        ComponentOfType,
        *(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 556
// RVA: 0x4E8BD0
void __fastcall UFG::TSCamera::MthdC_goto_radius(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::FollowCameraComponent::GotoRadius(
        ComponentOfType,
        *(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data,
        *(float *)(*(_QWORD *)(*((_QWORD *)scope->i_data.i_array_p + 1) + 8i64) + 32i64),
        *(float *)(*(_QWORD *)(*((_QWORD *)scope->i_data.i_array_p + 2) + 8i64) + 32i64));
  }
}

// File Line: 569
// RVA: 0x4E4D30
void __fastcall UFG::TSCamera::MthdC_enable_constrain_yaw(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  SSData **i_array_p; // r8
  float v6; // xmm3_4
  float v7; // xmm4_4

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = scope->i_data.i_array_p;
      v6 = (float)(*(float *)&i_array_p[1]->i_data_p->i_user_data * 3.1415927) * 0.0055555557;
      v7 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
      *((float *)&ComponentOfType[128].m_BoundComponentHandles.mNode.mPrev + 1) = (float)(*(float *)&(*i_array_p)->i_data_p->i_user_data
                                                                                        * 3.1415927)
                                                                                * 0.0055555557;
      LOBYTE(ComponentOfType[128].m_BoundComponentHandles.mNode.mPrev) = 1;
      *(float *)&ComponentOfType[128].m_BoundComponentHandles.mNode.mNext = v6;
      *((float *)&ComponentOfType[128].m_BoundComponentHandles.mNode.mNext + 1) = (float)(v7 * 3.1415927) * 0.0055555557;
    }
  }
}

// File Line: 582
// RVA: 0x4E4B90
void __fastcall UFG::TSCamera::MthdC_disable_constrain_yaw(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[128].m_BoundComponentHandles.mNode.mPrev) = 0;
  }
}

// File Line: 591
// RVA: 0x4E4CF0
void __fastcall UFG::TSCamera::MthdC_enable_combat_system(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[110].m_pSimObject) = 1;
  }
}

// File Line: 600
// RVA: 0x4E4B50
void __fastcall UFG::TSCamera::MthdC_disable_combat_system(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      LOBYTE(ComponentOfType[110].m_pSimObject) = 0;
  }
}

// File Line: 609
// RVA: 0x4E4820
void __fastcall UFG::TSCamera::MthdC_combat_system_snap_next_auto_frame(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v4; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rdx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    v4 = ComponentOfType;
    if ( ComponentOfType )
    {
      vfptr = ComponentOfType->vfptr;
      LOBYTE(ComponentOfType[110].m_BoundComponentHandles.mNode.mPrev) = 1;
      ((void (__fastcall *)(UFG::SimComponent *))vfptr[15].__vecDelDtor)(ComponentOfType);
      ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[31].__vecDelDtor)(v4);
      LOBYTE(v4[110].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 621
// RVA: 0x4F2AF0
void __fastcall UFG::TSCamera::MthdC_unlock_chase_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ChaseCameraComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pSimObject,
                                                     UFG::ChaseCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ChaseCameraComponent::LockEye(ComponentOfType, 0);
  }
}

// File Line: 628
// RVA: 0x4EDC60
void __fastcall UFG::TSCamera::MthdC_set_eye_look_noise(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax
  SSData **i_array_p; // r8
  float v6; // ecx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      i_array_p = pScope->i_data.i_array_p;
      v6 = *(float *)&(*i_array_p)->i_data_p->i_user_data;
      ComponentOfType->mLookNoiseMagnitude = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      ComponentOfType->mEyeNoiseMagnitude = v6;
    }
  }
}

// File Line: 634
// RVA: 0x4E90E0
void __fastcall UFG::TSCamera::MthdC_impact(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  if ( CurrentGameCamera )
    UFG::GameCameraComponent::AddShakeAmplitude(
      (UFG::GameCameraComponent *)CurrentGameCamera,
      *(float *)&(*scope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 647
// RVA: 0x4ED260
void __fastcall UFG::TSCamera::MthdC_set_allow_targeted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
      ComponentOfType->bAllowTargeted = v2;
  }
}

// File Line: 654
// RVA: 0x4ED170
void __fastcall UFG::TSCamera::MthdC_set_allow_desaturation(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // si
  UFG::ChaseCameraComponent *v3; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::FollowCameraComponent *ComponentOfType; // rdi
  UFG::SimObject *v6; // rcx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = 0i64;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::FollowCameraComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  v6 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v6 )
    v3 = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(v6, UFG::ChaseCameraComponent::_TypeUID);
  if ( ComponentOfType )
    ComponentOfType->bAllowDesaturation = v2;
  if ( v3 )
    v3->mAllowDesaturation = v2;
}

// File Line: 663
// RVA: 0x4ED4E0
void __fastcall UFG::TSCamera::MthdC_set_context_override(int follow_camera_type, SSInvokedMethod *pScope)
{
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *p_mNode; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *ComponentOfType; // rbx
  unsigned int v7; // eax
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol v9; // [rsp+78h] [rbp+10h] BYREF
  UFG::qSymbol *v10; // [rsp+80h] [rbp+18h]

  UFG::qString::FormatEx(&result, "Cameras-%s", *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  p_mNode = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&p_mNode[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode);
        ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              v5,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
        if ( ComponentOfType )
        {
          v10 = &v9;
          v7 = (unsigned int)UFG::qSymbol::create_from_string(&v9, result.mData);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(
            ComponentOfType,
            follow_camera_type,
            (UFG::qSymbol)v7);
        }
      }
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
  }
  UFG::qString::~qString(&result);
}

// File Line: 677
// RVA: 0x4ED5D0
void __fastcall UFG::TSCamera::MthdC_set_context_override_aim(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override(1, pScope);
}

// File Line: 683
// RVA: 0x4ED730
void __fastcall UFG::TSCamera::MthdC_set_context_override_tow(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override(0, pScope);
}

// File Line: 689
// RVA: 0x4ED5E0
void __fastcall UFG::TSCamera::MthdC_set_context_override_focus(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override(2, pScope);
}

// File Line: 695
// RVA: 0x4ED5F0
void __fastcall UFG::TSCamera::MthdC_set_context_override_grapple(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override(3, pScope);
}

// File Line: 700
// RVA: 0x4E4370
void __fastcall UFG::TSCamera::MthdC_clear_context_override(int follow_camera_type, SSInvokedMethod *pScope)
{
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *p_mNode; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *ComponentOfType; // rbx
  unsigned int v7; // eax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+18h] BYREF
  UFG::qWiseSymbol *p_result; // [rsp+68h] [rbp+20h]

  p_mNode = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&p_mNode[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *, SSInvokedMethod *))p_mNode->mPrev[8].mNext)(
             p_mNode,
             pScope) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode);
        ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              v5,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
        if ( ComponentOfType )
        {
          p_result = &result;
          v7 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(
            ComponentOfType,
            follow_camera_type,
            (UFG::qSymbol)v7);
        }
      }
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
  }
}

// File Line: 711
// RVA: 0x4E4430
void __fastcall UFG::TSCamera::MthdC_clear_context_override_aim(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override(1, pScope);
}

// File Line: 717
// RVA: 0x4E4560
void __fastcall UFG::TSCamera::MthdC_clear_context_override_tow(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override(0, pScope);
}

// File Line: 723
// RVA: 0x4E4440
void __fastcall UFG::TSCamera::MthdC_clear_context_override_focus(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override(2, pScope);
}

// File Line: 729
// RVA: 0x4E4450
void __fastcall UFG::TSCamera::MthdC_clear_context_override_grapple(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override(3, pScope);
}

// File Line: 735
// RVA: 0x4ED600
void __fastcall UFG::TSCamera::MthdC_set_context_override_local(int follow_camera_type, SSInvokedMethod *pScope)
{
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *p_mNode; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *ComponentOfType; // rbx
  unsigned int v7; // eax
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol v9; // [rsp+78h] [rbp+10h] BYREF
  UFG::qSymbol *v10; // [rsp+80h] [rbp+18h]

  UFG::qString::FormatEx(&result, "Cameras-%s", *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  p_mNode = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&p_mNode[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode);
        ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              v5,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
        if ( ComponentOfType )
        {
          v10 = &v9;
          v7 = (unsigned int)UFG::qSymbol::create_from_string(&v9, result.mData);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(
            ComponentOfType,
            follow_camera_type,
            (UFG::qSymbol)v7);
        }
      }
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
  }
  UFG::qString::~qString(&result);
}

// File Line: 749
// RVA: 0x4ED6F0
void __fastcall UFG::TSCamera::MthdC_set_context_override_local_aim(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override_local(1, pScope);
}

// File Line: 755
// RVA: 0x4ED720
void __fastcall UFG::TSCamera::MthdC_set_context_override_local_tow(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override_local(0, pScope);
}

// File Line: 761
// RVA: 0x4ED700
void __fastcall UFG::TSCamera::MthdC_set_context_override_local_focus(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override_local(2, pScope);
}

// File Line: 767
// RVA: 0x4ED710
void __fastcall UFG::TSCamera::MthdC_set_context_override_local_grapple(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_set_context_override_local(3, pScope);
}

// File Line: 772
// RVA: 0x4E4460
void __fastcall UFG::TSCamera::MthdC_clear_context_override_local(int follow_camera_type, SSInvokedMethod *pScope)
{
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *p_mNode; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *ComponentOfType; // rbx
  unsigned int v7; // eax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+18h] BYREF
  UFG::qWiseSymbol *p_result; // [rsp+68h] [rbp+20h]

  p_mNode = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&p_mNode[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *, SSInvokedMethod *))p_mNode->mPrev[8].mNext)(
             p_mNode,
             pScope) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))p_mNode->mPrev[8].mNext)(p_mNode);
        ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              v5,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
        if ( ComponentOfType )
        {
          p_result = &result;
          v7 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(
            ComponentOfType,
            follow_camera_type,
            (UFG::qSymbol)v7);
        }
      }
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 );
  }
}

// File Line: 783
// RVA: 0x4E4520
void __fastcall UFG::TSCamera::MthdC_clear_context_override_local_aim(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override_local(1, pScope);
}

// File Line: 789
// RVA: 0x4E4550
void __fastcall UFG::TSCamera::MthdC_clear_context_override_local_tow(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override_local(0, pScope);
}

// File Line: 795
// RVA: 0x4E4530
void __fastcall UFG::TSCamera::MthdC_clear_context_override_local_focus(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override_local(2, pScope);
}

// File Line: 801
// RVA: 0x4E4540
void __fastcall UFG::TSCamera::MthdC_clear_context_override_local_grapple(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override_local(3, pScope);
}

// File Line: 807
// RVA: 0x4EEF80
void __fastcall UFG::TSCamera::MthdC_set_social_target(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::CharacterSubjectComponent *v2; // rsi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *v5; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *v9; // rax
  UFG::SimComponent *v10; // rdi

  v2 = 0i64;
  i_data_p = (SSActor *)(*scope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_8;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))i_class_p->vfptr->is_actor_class)(i_class_p, result) )
  {
    if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
      goto LABEL_8;
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  }
  if ( !i_data_p )
  {
LABEL_8:
    v5 = 0i64;
    goto LABEL_9;
  }
  v5 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
LABEL_9:
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    v8 = ComponentOfType;
    if ( ComponentOfType )
    {
      if ( ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType) )
      {
        v9 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v8->vfptr[17].__vecDelDtor)(v8);
        v10 = UFG::SimObject::GetComponentOfType(v9, UFG::CharacterSubjectComponent::_TypeUID);
        if ( v10 )
        {
          if ( v5 )
            v2 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                     v5,
                                                     UFG::CharacterSubjectComponent::_TypeUID);
          UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::Set(
            (UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0> *)&v10[18].m_pSimObject,
            v2);
        }
      }
    }
  }
}

// File Line: 825
// RVA: 0x4E4610
void __fastcall UFG::TSCamera::MthdC_clear_social_target(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v4; // rbx
  UFG::SimObject *v5; // rax
  UFG::SimComponent *v6; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    v4 = ComponentOfType;
    if ( ComponentOfType )
    {
      if ( ((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v4->vfptr[17].__vecDelDtor)(v4);
        v6 = UFG::SimObject::GetComponentOfType(v5, UFG::CharacterSubjectComponent::_TypeUID);
        if ( v6 )
          UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::Set(
            (UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0> *)&v6[18].m_pSimObject,
            0i64);
      }
    }
  }
}

// File Line: 851
// RVA: 0x4EB790
void __fastcall UFG::TSCamera::MthdC_progression_set_monotonically_increasing(
        SSInvokedMethod *scope,
        SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ProgressionCameraComponent::_TypeUID);
    if ( ComponentOfType )
      BYTE1(ComponentOfType[22].vfptr) = (*scope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 860
// RVA: 0x4EB900
void __fastcall UFG::TSCamera::MthdC_progression_set_window_size(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ProgressionCameraComponent::_TypeUID);
    if ( ComponentOfType )
      HIDWORD(ComponentOfType[22].vfptr) = (*scope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 869
// RVA: 0x4EB740
void __fastcall UFG::TSCamera::MthdC_progression_set_duration(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ProgressionCameraComponent::_TypeUID);
    if ( ComponentOfType )
      LODWORD(ComponentOfType[22].m_SafePointerList.mNode.mPrev) = (*scope->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 878
// RVA: 0x4EB7E0
void __fastcall UFG::TSCamera::MthdC_progression_set_progress_transforms(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // rdi
  unsigned __int64 i_user_data; // rbx
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rbx
  int v9; // xmm0_4
  int v10; // xmm1_4
  int v11; // xmm2_4
  int v12; // xmm0_4

  i_array_p = scope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = *(_QWORD *)(i_user_data + 104);
  if ( !v4 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
    v4 = i_user_data;
  v5 = i_array_p[1]->i_data_p->i_user_data;
  v6 = *(_QWORD *)(v5 + 104);
  if ( !v6 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(v5 + 192), &UFG::qMatrix44::msIdentity) )
    v6 = v5;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ProgressionCameraComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  if ( v4 && v6 )
  {
    if ( ComponentOfType )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
      v9 = *(_DWORD *)(v4 + 180);
      v10 = *(_DWORD *)(v4 + 184);
      HIDWORD(ComponentOfType[22].m_BoundComponentHandles.mNode.mPrev) = *(_DWORD *)(v4 + 176);
      LODWORD(ComponentOfType[22].m_BoundComponentHandles.mNode.mNext) = v9;
      HIDWORD(ComponentOfType[22].m_BoundComponentHandles.mNode.mNext) = v10;
      v11 = *(_DWORD *)(v6 + 184);
      v12 = *(_DWORD *)(v6 + 180);
      LODWORD(ComponentOfType[23].vfptr) = *(_DWORD *)(v6 + 176);
      HIDWORD(ComponentOfType[23].vfptr) = v12;
      LODWORD(ComponentOfType[23].m_SafePointerList.mNode.mPrev) = v11;
    }
  }
}

// File Line: 889
// RVA: 0x4EB5F0
void __fastcall UFG::TSCamera::MthdC_progression_begin(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ProgressionCameraComponent *ComponentOfType; // rax
  UFG::ProgressionCameraComponent *v5; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  UFG::qSymbolUC resulta; // [rsp+40h] [rbp+18h] BYREF

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ProgressionCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                           m_pSimObject,
                                                           UFG::ProgressionCameraComponent::_TypeUID);
    v5 = ComponentOfType;
    if ( ComponentOfType )
    {
      UFG::gProgressionCameraComponent = ComponentOfType;
      UFG::gPreviousCameraComponent = UFG::GetCurrentBaseCamera();
      UFG::qSymbolUC::create_from_string(&resulta, *(const char **)(*scope->i_data.i_array_p)->i_data_p->i_user_data);
      vfptr = v5->vfptr;
      v5->mFov = 70.0;
      vfptr[16].__vecDelDtor(v5, (unsigned int)LocalPlayer);
      *(_WORD *)&v5->bTargetSpace = 0;
      v5->bSingleBone = 0;
      UFG::AttachCameraToView(v5);
      UFG::ProgressionCameraComponent::Play(v5, &resulta, 0.0);
    }
  }
}

// File Line: 917
// RVA: 0x4EC820
void __fastcall UFG::TSCamera::MthdC_return_xform_relative_player(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 i_user_data; // rbx
  unsigned __int64 v4; // rdi
  UFG::SimComponent *ComponentOfType; // rbx
  int v6; // xmm1_4
  int v7; // xmm2_4
  int v8; // xmm3_4
  int v9; // xmm1_4
  int v10; // xmm2_4
  int v11; // xmm3_4
  unsigned int v12; // xmm1_4
  unsigned int v13; // xmm2_4
  int v14; // xmm3_4
  unsigned int v15; // xmm1_4
  unsigned int v16; // xmm2_4
  int v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v31; // rbx
  unsigned int v32; // eax
  UFG::TransformNodeComponent *v33; // rax
  UFG::TransformNodeComponent *v34; // rbx
  UFG::qVector4 v35; // xmm6
  UFG::qVector4 v36; // xmm7
  UFG::qVector4 v37; // xmm9
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h] BYREF
  _BYTE v39[24]; // [rsp+70h] [rbp-88h]
  __m128 v40; // [rsp+88h] [rbp-70h]
  __m128 v41; // [rsp+98h] [rbp-60h]
  __int64 v42; // [rsp+A8h] [rbp-50h]

  if ( ppResult )
  {
    v42 = -2i64;
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = *(_QWORD *)(i_user_data + 104);
    if ( !v4 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
      v4 = i_user_data;
    ComponentOfType = UFG::SimObject::GetComponentOfType(
                        LocalPlayer,
                        UFG::TransformNodeComponent::_TransformNodeComponentTypeUID);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v6 = *(_DWORD *)(v4 + 132);
    v7 = *(_DWORD *)(v4 + 136);
    v8 = *(_DWORD *)(v4 + 140);
    *(_DWORD *)v39 = *(_DWORD *)(v4 + 128);
    *(_DWORD *)&v39[4] = v6;
    *(_DWORD *)&v39[8] = v7;
    *(_DWORD *)&v39[12] = v8;
    v9 = *(_DWORD *)(v4 + 148);
    v10 = *(_DWORD *)(v4 + 152);
    v11 = *(_DWORD *)(v4 + 156);
    *(_DWORD *)&v39[8] = *(_DWORD *)(v4 + 144);
    *(_DWORD *)&v39[12] = v9;
    *(_DWORD *)&v39[16] = v10;
    *(_DWORD *)&v39[20] = v11;
    v12 = *(_DWORD *)(v4 + 164);
    v13 = *(_DWORD *)(v4 + 168);
    v14 = *(_DWORD *)(v4 + 172);
    v40.m128_i32[0] = *(_DWORD *)(v4 + 160);
    *(unsigned __int64 *)((char *)v40.m128_u64 + 4) = __PAIR64__(v13, v12);
    v40.m128_i32[3] = v14;
    v15 = *(_DWORD *)(v4 + 180);
    v16 = *(_DWORD *)(v4 + 184);
    v17 = *(_DWORD *)(v4 + 188);
    v41.m128_i32[0] = *(_DWORD *)(v4 + 176);
    *(unsigned __int64 *)((char *)v41.m128_u64 + 4) = __PAIR64__(v16, v15);
    v41.m128_i32[3] = v17;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)ComponentOfType);
    v18 = *((float *)&ComponentOfType[2].vfptr + 1);
    v19 = *(float *)&ComponentOfType[2].m_SafePointerList.mNode.mPrev;
    v20 = *((float *)&ComponentOfType[2].m_SafePointerList.mNode.mPrev + 1);
    m.v0.x = *(float *)&ComponentOfType[2].vfptr;
    m.v0.y = v18;
    m.v0.z = v19;
    m.v0.w = v20;
    v21 = *((float *)&ComponentOfType[2].m_SafePointerList.mNode.mNext + 1);
    v22 = *(float *)&ComponentOfType[2].m_TypeUID;
    v23 = *(float *)&ComponentOfType[2].m_NameUID;
    m.v1.x = *(float *)&ComponentOfType[2].m_SafePointerList.mNode.mNext;
    m.v1.y = v21;
    m.v1.z = v22;
    m.v1.w = v23;
    v24 = *(float *)(&ComponentOfType[2].m_SimObjIndex + 1);
    v25 = *(float *)&ComponentOfType[2].m_pSimObject;
    v26 = *((float *)&ComponentOfType[2].m_pSimObject + 1);
    m.v2.x = *(float *)&ComponentOfType[2].m_Flags;
    m.v2.y = v24;
    m.v2.z = v25;
    m.v2.w = v26;
    v27 = *((float *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v28 = *(float *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mNext;
    v29 = *((float *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mNext + 1);
    m.v3.x = *(float *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mPrev;
    m.v3.y = v27;
    m.v3.z = v28;
    m.v3.w = v29;
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v31 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TSCamera", 0i64, 1u);
    if ( v31 )
    {
      v32 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v31, v32, 0i64, 0);
      v34 = v33;
    }
    else
    {
      v34 = 0i64;
    }
    v35 = m.v0;
    v36 = m.v1;
    v37 = m.v2;
    m.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v39, *(__m128 *)v39, 0), (__m128)m.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v39, *(__m128 *)v39, 85), (__m128)m.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v39, *(__m128 *)v39, 170), (__m128)m.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v39, *(__m128 *)v39, 255), (__m128)m.v3));
    m.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39[8], *(__m128 *)&v39[8], 0), (__m128)v35),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39[8], *(__m128 *)&v39[8], 85), (__m128)m.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39[8], *(__m128 *)&v39[8], 170), (__m128)m.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39[8], *(__m128 *)&v39[8], 255), (__m128)m.v3));
    m.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), (__m128)v35), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), (__m128)v36)),
                              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), (__m128)m.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), (__m128)m.v3));
    m.v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), (__m128)v35), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), (__m128)v36)),
                              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), (__m128)v37)),
                            _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), (__m128)m.v3));
    UFG::TransformNodeComponent::SetWorldTransform(v34, &m);
    *ppResult = UFG::TSTransform::AsInstance(v34);
  }
}

// File Line: 934
// RVA: 0x4EC2F0
void __fastcall UFG::TSCamera::MthdC_reset(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax

  CurrentBaseCamera = UFG::GetCurrentBaseCamera();
  if ( CurrentBaseCamera )
    ((void (__fastcall *)(UFG::BaseCameraComponent *))CurrentBaseCamera->vfptr[14].__vecDelDtor)(CurrentBaseCamera);
}

// File Line: 947
// RVA: 0x4EB6B0
void __fastcall UFG::TSCamera::MthdC_progression_end(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::ProgressionCameraComponent *v2; // rbx
  AnimationNode *m_pPointer; // rcx
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mAnimationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( UFG::gProgressionCameraComponent )
  {
    UFG::gPreviousCameraComponent->vfptr[14].__vecDelDtor(UFG::gPreviousCameraComponent, (unsigned int)result);
    UFG::AttachCameraToView(UFG::gPreviousCameraComponent);
    v2 = UFG::gProgressionCameraComponent;
    m_pPointer = UFG::gProgressionCameraComponent->mAnimationNode.m_pPointer;
    if ( m_pPointer )
      m_pPointer->PoseNode::Expression::IMemberMap::vfptr->__vecDelDtor(m_pPointer, 1u);
    p_mAnimationNode = &v2->mAnimationNode;
    if ( v2->mAnimationNode.m_pPointer )
    {
      mPrev = p_mAnimationNode->mPrev;
      mNext = v2->mAnimationNode.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mAnimationNode->mPrev = p_mAnimationNode;
      v2->mAnimationNode.mNext = &v2->mAnimationNode;
    }
    v2->mAnimationNode.m_pPointer = 0i64;
    UFG::gProgressionCameraComponent = 0i64;
    UFG::gPreviousCameraComponent = 0i64;
  }
}

// File Line: 960
// RVA: 0x1536310
__int64 UFG::_dynamic_initializer_for__gAnimatedCameraController__()
{
  UFG::gAnimatedCameraController.m_pPointer = 0i64;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gAnimatedCameraController__);
}

// File Line: 963
// RVA: 0x4E3390
void __fastcall UFG::TSCamera::MthdC_animation_begin(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rbx
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  AnimationNode *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v11; // rax
  SSData **i_array_p; // rax
  Creature *v13; // rdi
  __int64 v14; // r8
  __int64 v15; // rdx
  __int64 v16; // r8
  UFG::SimObjectGame *v17; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSymbolUC resulta; // [rsp+70h] [rbp+18h] BYREF

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AnimatedCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( !UFG::gAnimatedCameraComponent )
      {
        CurrentBaseCamera = UFG::GetCurrentBaseCamera();
        UFG::gAnimatedCameraComponent = (UFG::AnimatedCameraComponent *)ComponentOfType;
        UFG::gPreviousCameraComponent = CurrentBaseCamera;
        UFG::qSymbolUC::create_from_string(&resulta, *(const char **)(*scope->i_data.i_array_p)->i_data_p->i_user_data);
        vfptr = ComponentOfType->vfptr;
        LODWORD(ComponentOfType[22].vfptr) = 1117126656;
        vfptr[16].__vecDelDtor(ComponentOfType, (unsigned int)LocalPlayer);
        LODWORD(ComponentOfType[22].m_SafePointerList.mNode.mNext) = 0;
        BYTE4(ComponentOfType[22].m_SafePointerList.mNode.mNext) = 1;
        UFG::AnimatedCameraComponent::SetDofParameters(
          (UFG::AnimatedCameraComponent *)ComponentOfType,
          20.0,
          5.0,
          0.0,
          4.0,
          0.0,
          4.0);
        UFG::AttachCameraToView((UFG::BaseCameraComponent *)ComponentOfType);
        v7 = UFG::AnimatedCameraComponent::Play((UFG::AnimatedCameraComponent *)ComponentOfType, &resulta, 0.0);
        if ( UFG::gAnimatedCameraController.m_pPointer )
        {
          mPrev = UFG::gAnimatedCameraController.mPrev;
          mNext = UFG::gAnimatedCameraController.mNext;
          UFG::gAnimatedCameraController.mPrev->mNext = UFG::gAnimatedCameraController.mNext;
          mNext->mPrev = mPrev;
          UFG::gAnimatedCameraController.mPrev = &UFG::gAnimatedCameraController;
          UFG::gAnimatedCameraController.mNext = &UFG::gAnimatedCameraController;
        }
        UFG::gAnimatedCameraController.m_pPointer = v7;
        if ( v7 )
        {
          p_mNode = &v7->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode;
          v11 = v7->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev;
          v11->mNext = &UFG::gAnimatedCameraController;
          UFG::gAnimatedCameraController.mNext = p_mNode;
          UFG::gAnimatedCameraController.mPrev = v11;
          p_mNode->mPrev = &UFG::gAnimatedCameraController;
          if ( UFG::gAnimatedCameraController.m_pPointer )
          {
            i_array_p = scope->i_data.i_array_p;
            v13 = 0i64;
            UFG::gAnimatedCameraController.m_pPointer->vfptr[2].FindWithOldPath(
              UFG::gAnimatedCameraController.m_pPointer,
              (const char *)((unsigned int)(i_array_p[1]->i_data_p->i_user_data == 0) + 1));
            LOBYTE(v14) = 1;
            ((void (__fastcall *)(AnimationNode *, __int64, __int64))UFG::gAnimatedCameraController.m_pPointer->vfptr[1].GetClassNameUID)(
              UFG::gAnimatedCameraController.m_pPointer,
              v15,
              v14);
            v17 = (UFG::SimObjectGame *)ComponentOfType->m_pSimObject;
            if ( v17 )
            {
              m_Flags = v17->m_Flags;
              if ( (m_Flags & 0x4000) != 0 )
              {
                m_pComponent = v17->m_Components.p[9].m_pComponent;
              }
              else if ( m_Flags >= 0 )
              {
                if ( (m_Flags & 0x2000) != 0 )
                {
                  m_pComponent = v17->m_Components.p[8].m_pComponent;
                }
                else if ( (m_Flags & 0x1000) != 0 )
                {
                  m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::BaseAnimationComponent::_TypeUID);
                }
                else
                {
                  m_pComponent = UFG::SimObject::GetComponentOfType(v17, UFG::BaseAnimationComponent::_TypeUID);
                }
              }
              else
              {
                m_pComponent = v17->m_Components.p[9].m_pComponent;
              }
              if ( m_pComponent )
                v13 = *(Creature **)&m_pComponent[2].m_TypeUID;
            }
            if ( v13 )
            {
              Creature::Update(v13, 0.0, v16);
              Creature::UpdateTransforms(v13);
              ((void (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[15].__vecDelDtor)(ComponentOfType);
            }
          }
        }
      }
    }
  }
}

// File Line: 1018
// RVA: 0x4E35F0
void __fastcall UFG::TSCamera::MthdC_animation_end(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::AnimatedCameraComponent *v2; // rbx
  AnimationNode *m_pPointer; // rcx
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mAnimationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx

  if ( UFG::gAnimatedCameraComponent )
  {
    UFG::gPreviousCameraComponent->vfptr[14].__vecDelDtor(UFG::gPreviousCameraComponent, (unsigned int)result);
    UFG::AttachCameraToView(UFG::gPreviousCameraComponent);
    ((void (__fastcall *)(UFG::BaseCameraComponent *))UFG::gPreviousCameraComponent->vfptr[15].__vecDelDtor)(UFG::gPreviousCameraComponent);
    v2 = UFG::gAnimatedCameraComponent;
    m_pPointer = UFG::gAnimatedCameraComponent->mAnimationNode.m_pPointer;
    if ( m_pPointer )
      m_pPointer->PoseNode::Expression::IMemberMap::vfptr->__vecDelDtor(m_pPointer, 1u);
    p_mAnimationNode = &v2->mAnimationNode;
    if ( v2->mAnimationNode.m_pPointer )
    {
      mPrev = p_mAnimationNode->mPrev;
      mNext = v2->mAnimationNode.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mAnimationNode->mPrev = p_mAnimationNode;
      v2->mAnimationNode.mNext = &v2->mAnimationNode;
    }
    v2->mAnimationNode.m_pPointer = 0i64;
    UFG::gAnimatedCameraComponent = 0i64;
    UFG::gPreviousCameraComponent = 0i64;
    if ( UFG::gAnimatedCameraController.m_pPointer )
    {
      v7 = UFG::gAnimatedCameraController.mNext;
      v8 = UFG::gAnimatedCameraController.mPrev;
      UFG::gAnimatedCameraController.mPrev->mNext = UFG::gAnimatedCameraController.mNext;
      v7->mPrev = v8;
      UFG::gAnimatedCameraController.mPrev = &UFG::gAnimatedCameraController;
      UFG::gAnimatedCameraController.mNext = &UFG::gAnimatedCameraController;
    }
    UFG::gAnimatedCameraController.m_pPointer = 0i64;
  }
}

