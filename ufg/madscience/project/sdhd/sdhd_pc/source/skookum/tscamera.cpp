// File Line: 50
// RVA: 0x1531030
__int64 dynamic_initializer_for__UFG::TSCamera::gCCTVColourCubeUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("COLOURCUBE_BLACKANDWHITE", 0xFFFFFFFF);
  UFG::TSCamera::gCCTVColourCubeUID = result;
  return result;
}

// File Line: 61
// RVA: 0x4CE910
void UFG::TSCamera::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Camera");
  SSClass::register_method_func(v0, "is_using_high_zoom", UFG::TSCamera::MthdC_is_using_high_zoom, 1, 0);
  SSClass::register_method_func(v0, "set_animated_marker_xform", UFG::TSCamera::MthdC_set_animated_marker_xform, 1, 0);
  SSClass::register_method_func(
    v0,
    "set_xform",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))UFG::TSCamera::MthdC_set_xform,
    1,
    0);
  SSClass::register_method_func(v0, "set_fov", UFG::TSCamera::MthdC_set_fov, 1, 0);
  SSClass::register_method_func(v0, "release_camera", UFG::TSCamera::MthdC_release_camera, 1, 0);
  SSClass::register_method_func(v0, "set_target", UFG::TSCamera::MthdC_set_target, 1, 0);
  SSClass::register_method_func(v0, "set_look_offset", UFG::TSCamera::MthdC_set_look_offset, 1, 0);
  SSClass::register_method_func(v0, "set_eye_offset_from_target", UFG::TSCamera::MthdC_set_eye_offset_from_target, 1, 0);
  SSClass::register_method_func(v0, "attach_to_xform", UFG::TSCamera::MthdC_set_following, 1, 0);
  SSClass::register_method_func(v0, "target_xform", UFG::TSCamera::MthdC_target_xform, 1, 0);
  SSClass::register_method_func(v0, "pan_to_xform", UFG::TSCamera::MthdC_pan_to_xform, 1, 0);
  SSClass::register_method_func(v0, "get_xform", UFG::TSCamera::MthdC_get_debug_xform, 1, 0);
  SSClass::register_method_func(
    v0,
    "set_allow_script_camera_super_wide_aspect",
    UFG::TSCamera::MthdC_set_allow_script_camera_super_wide_aspect,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "return_xform_relative_player",
    UFG::TSCamera::MthdC_return_xform_relative_player,
    1,
    0);
  SSClass::register_method_func(v0, "reset", UFG::TSCamera::MthdC_reset, 1, 0);
  SSClass::register_method_func(v0, "set_dof", UFG::TSCamera::MthdC_set_dof, 1, 0);
  SSClass::register_method_func(v0, "reset_dof", UFG::TSCamera::MthdC_reset_dof, 1, 0);
  SSClass::register_method_func(v0, "start_dynamic_dof", UFG::TSCamera::MthdC_start_dynamic_dof, 1, 0);
  SSClass::register_method_func(v0, "stop_dynamic_dof", UFG::TSCamera::MthdC_stop_dynamic_dof, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dof_focal_dist", UFG::TSCamera::MthdC_set_dynamic_dof_focal_dist, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dof_range", UFG::TSCamera::MthdC_set_dynamic_dof_range, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dof_near_blend", UFG::TSCamera::MthdC_set_dynamic_dof_near_blend, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dof_near_blur", UFG::TSCamera::MthdC_set_dynamic_dof_near_blur, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dof_far_blend", UFG::TSCamera::MthdC_set_dynamic_dof_far_blend, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dof_far_blur", UFG::TSCamera::MthdC_set_dynamic_dof_far_blur, 1, 0);
  SSClass::register_method_func(v0, "set_dutch", UFG::TSCamera::MthdC_set_dutch, 1, 0);
  SSClass::register_method_func(v0, "reset_dutch", UFG::TSCamera::MthdC_reset_dutch, 1, 0);
  SSClass::register_method_func(v0, "set_dynamic_dutch", UFG::TSCamera::MthdC_set_dynamic_dutch, 1, 0);
  SSClass::register_method_func(v0, "set_override_max_radius", UFG::TSCamera::MthdC_set_override_max_radius, 1, 0);
  SSClass::register_method_func(v0, "clear_override_max_radius", UFG::TSCamera::MthdC_clear_override_max_radius, 1, 0);
  SSClass::register_method_func(v0, "set_override_rise", UFG::TSCamera::MthdC_set_override_rise, 1, 0);
  SSClass::register_method_func(v0, "clear_override_rise", UFG::TSCamera::MthdC_clear_override_rise, 1, 0);
  SSClass::register_method_func(v0, "goto_angle", UFG::TSCamera::MthdC_goto_angle, 1, 0);
  SSClass::register_method_func(v0, "goto_angle_snap", UFG::TSCamera::MthdC_goto_angle_snap, 1, 0);
  SSClass::register_method_func(v0, "goto_rise", UFG::TSCamera::MthdC_goto_rise, 1, 0);
  SSClass::register_method_func(v0, "goto_rise_snap", UFG::TSCamera::MthdC_goto_rise_snap, 1, 0);
  SSClass::register_method_func(v0, "goto_radius", UFG::TSCamera::MthdC_goto_radius, 1, 0);
  SSClass::register_method_func(v0, "enable_constrain_yaw", UFG::TSCamera::MthdC_enable_constrain_yaw, 1, 0);
  SSClass::register_method_func(v0, "disable_constrain_yaw", UFG::TSCamera::MthdC_disable_constrain_yaw, 1, 0);
  SSClass::register_method_func(v0, "enable_combat_system", UFG::TSCamera::MthdC_enable_combat_system, 1, 0);
  SSClass::register_method_func(v0, "disable_combat_system", UFG::TSCamera::MthdC_disable_combat_system, 1, 0);
  SSClass::register_method_func(
    v0,
    "combat_system_snap_next_auto_frame",
    UFG::TSCamera::MthdC_combat_system_snap_next_auto_frame,
    1,
    0);
  SSClass::register_method_func(v0, "set_allow_targeted", UFG::TSCamera::MthdC_set_allow_targeted, 1, 0);
  SSClass::register_method_func(v0, "set_allow_desaturation", UFG::TSCamera::MthdC_set_allow_desaturation, 1, 0);
  SSClass::register_method_func(v0, "set_eye_look_noise", UFG::TSCamera::MthdC_set_eye_look_noise, 1, 0);
  SSClass::register_method_func(v0, "impact", UFG::TSCamera::MthdC_impact, 1, 0);
  SSClass::register_method_func(v0, "unlock_chase_camera", UFG::TSCamera::MthdC_unlock_chase_camera, 1, 0);
  SSClass::register_method_func(v0, "set_context_override_tow", UFG::TSCamera::MthdC_set_context_override_tow, 1, 0);
  SSClass::register_method_func(v0, "set_context_override_aim", UFG::TSCamera::MthdC_set_context_override_aim, 1, 0);
  SSClass::register_method_func(v0, "set_context_override_focus", UFG::TSCamera::MthdC_set_context_override_focus, 1, 0);
  SSClass::register_method_func(
    v0,
    "set_context_override_grapple",
    UFG::TSCamera::MthdC_set_context_override_grapple,
    1,
    0);
  SSClass::register_method_func(v0, "clear_context_override_tow", UFG::TSCamera::MthdC_clear_context_override_tow, 1, 0);
  SSClass::register_method_func(v0, "clear_context_override_aim", UFG::TSCamera::MthdC_clear_context_override_aim, 1, 0);
  SSClass::register_method_func(
    v0,
    "clear_context_override_focus",
    UFG::TSCamera::MthdC_clear_context_override_focus,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "clear_context_override_grapple",
    UFG::TSCamera::MthdC_clear_context_override_grapple,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "set_context_override_local_tow",
    UFG::TSCamera::MthdC_set_context_override_local_tow,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "set_context_override_local_aim",
    UFG::TSCamera::MthdC_set_context_override_local_aim,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "set_context_override_local_focus",
    UFG::TSCamera::MthdC_set_context_override_local_focus,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "set_context_override_local_grapple",
    UFG::TSCamera::MthdC_set_context_override_local_grapple,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_tow",
    UFG::TSCamera::MthdC_clear_context_override_local_tow,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_aim",
    UFG::TSCamera::MthdC_clear_context_override_local_aim,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_focus",
    UFG::TSCamera::MthdC_clear_context_override_local_focus,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "clear_context_override_local_grapple",
    UFG::TSCamera::MthdC_clear_context_override_local_grapple,
    1,
    0);
  SSClass::register_method_func(v0, "set_social_target", UFG::TSCamera::MthdC_set_social_target, 1, 0);
  SSClass::register_method_func(v0, "clear_social_target", UFG::TSCamera::MthdC_clear_social_target, 1, 0);
  SSClass::register_method_func(v0, "set_birds_eye", (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_, 1, 0);
  SSClass::register_method_func(
    v0,
    "progression_set_monotonically_increasing",
    UFG::TSCamera::MthdC_progression_set_monotonically_increasing,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "progression_set_window_size",
    UFG::TSCamera::MthdC_progression_set_window_size,
    1,
    0);
  SSClass::register_method_func(v0, "progression_set_duration", UFG::TSCamera::MthdC_progression_set_duration, 1, 0);
  SSClass::register_method_func(v0, "progression_begin", UFG::TSCamera::MthdC_progression_begin, 1, 0);
  SSClass::register_method_func(v0, "progression_end", UFG::TSCamera::MthdC_progression_end, 1, 0);
  SSClass::register_method_func(
    v0,
    "progression_set_progress_transforms",
    UFG::TSCamera::MthdC_progression_set_progress_transforms,
    1,
    0);
  SSClass::register_method_func(v0, "animation_begin", UFG::TSCamera::MthdC_animation_begin, 1, 0);
  SSClass::register_method_func(v0, "animation_end", UFG::TSCamera::MthdC_animation_end, 1, 0);
}

// File Line: 163
// RVA: 0x4E9D60
void __fastcall UFG::TSCamera::MthdC_is_using_high_zoom(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  bool v3; // al

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::IsCameraUsingHighZoom();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
  }
}

// File Line: 176
// RVA: 0x4ED2B0
void __fastcall UFG::TSCamera::MthdC_set_animated_marker_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 v2; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  UFG::qVector4 v6; // xmm0

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = *(UFG::TransformNodeComponent **)(v2 + 104);
  if ( !v3 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(v2 + 192), &UFG::qMatrix44::msIdentity) )
    v3 = (UFG::TransformNodeComponent *)v2;
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
void __usercall UFG::TSCamera::MthdC_set_xform(SSInvokedMethod *pScope@<rcx>, SSInstance **ppResult@<rdx>, float *a3@<r13>)
{
  SSInvokedMethod *v3; // rsi
  UFG::SimObject *v4; // rcx
  UFG::ScriptCameraComponent *v5; // rbp
  SSData **v6; // rsi
  UFG::TransformNodeComponent *v7; // rbx
  UFG::TransformNodeComponent *v8; // rdi

  v3 = pScope;
  v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v4 )
  {
    v5 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::ScriptCameraComponent::_TypeUID);
    if ( v5 )
    {
      v6 = v3->i_data.i_array_p;
      v7 = (UFG::TransformNodeComponent *)(*v6)->i_data_p->i_user_data;
      v8 = v7->mParent;
      if ( !v8 || !UFG::qMatrix44::operator==(&v7->mLocalTransform, &UFG::qMatrix44::msIdentity) )
        v8 = v7;
      UFG::ScriptCameraComponent::SwitchToScriptCam(
        v5,
        v8,
        v6[1]->i_data_p->i_user_data != 0,
        *(float *)&v6[2]->i_data_p->i_user_data,
        a3);
    }
  }
}

// File Line: 205
// RVA: 0x4EDE40
void __fastcall UFG::TSCamera::MthdC_set_fov(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  signed __int64 v5; // rbx

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = (signed __int64)&v4[21].m_pSimObject + 4;
      LODWORD(v4[22].m_SafePointerList.mNode.mPrev) = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)((char *)&v4[21].m_pSimObject + 4));
      *(_DWORD *)(v5 + 4) = 0;
      *(_DWORD *)(v5 + 24) = *(_DWORD *)(v5 + 28);
      *(_DWORD *)(v5 + 32) = *(_DWORD *)(v5 + 36);
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)v5);
      *(_DWORD *)(v5 + 4) = 0;
    }
  }
}

// File Line: 216
// RVA: 0x4EC140
void __fastcall UFG::TSCamera::MthdC_release_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rax

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
      UFG::ScriptCameraComponent::ReleaseCamera(v4, (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 231
// RVA: 0x4EF2C0
void __fastcall UFG::TSCamera::MthdC_set_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *v2; // rbx
  SSClass *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::SimObject *v5; // rcx
  UFG::ScriptCameraComponent *v6; // rax

  v2 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v2 )
    goto LABEL_12;
  v3 = v2->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))v3->vfptr->is_actor_class)(v3, ppResult) )
    goto LABEL_7;
  if ( v3 == SSBrain::c_symbol_class_p && LODWORD(v2->i_user_data) != -1 )
    v2 = SSActor::find((ASymbol *)&v2->i_user_data);
  else
LABEL_12:
    v2 = 0i64;
LABEL_7:
  v4 = (UFG::TransformNodeComponent *)v2[1].i_class_p;
  v5 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v5 )
  {
    v6 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v5, UFG::ScriptCameraComponent::_TypeUID);
    if ( v6 )
      UFG::ScriptCameraComponent::SetTarget(v6, v4);
  }
}

// File Line: 244
// RVA: 0x4EE270
void __fastcall UFG::TSCamera::MthdC_set_look_offset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  SSData **v5; // r8
  int v6; // xmm1_4
  int v7; // xmm0_4

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      v6 = v5[1]->i_data_p->i_user_data;
      v7 = v5[2]->i_data_p->i_user_data;
      HIDWORD(v4[28].vfptr) = (*v5)->i_data_p->i_user_data;
      LODWORD(v4[28].m_SafePointerList.mNode.mPrev) = v6;
      HIDWORD(v4[28].m_SafePointerList.mNode.mPrev) = v7;
    }
  }
}

// File Line: 255
// RVA: 0x4EDCC0
void __fastcall UFG::TSCamera::MthdC_set_eye_offset_from_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rax
  SSData **v5; // r8
  float v6; // xmm2_4
  float v7; // xmm0_4
  UFG::qVector3 offset; // [rsp+20h] [rbp-18h]

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      v6 = *(float *)&v5[2]->i_data_p->i_user_data;
      v7 = *(float *)&(*v5)->i_data_p->i_user_data;
      offset.y = *(float *)&v5[1]->i_data_p->i_user_data;
      offset.x = v7;
      offset.z = v6;
      UFG::ScriptCameraComponent::SetEyeOffsetFromTarget(v4, &offset);
    }
  }
}

// File Line: 267
// RVA: 0x4F2800
void __fastcall UFG::TSCamera::MthdC_target_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rsi
  UFG::TransformNodeComponent *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = (UFG::TransformNodeComponent *)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
      v6 = v5->mParent;
      if ( !v6 || !UFG::qMatrix44::operator==(&v5->mLocalTransform, &UFG::qMatrix44::msIdentity) )
        v6 = v5;
      UFG::ScriptCameraComponent::SetTarget(v4, v6);
    }
  }
}

// File Line: 279
// RVA: 0x4EDDA0
void __fastcall UFG::TSCamera::MthdC_set_following(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rsi
  UFG::TransformNodeComponent *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = (UFG::TransformNodeComponent *)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
      v6 = v5->mParent;
      if ( !v6 || !UFG::qMatrix44::operator==(&v5->mLocalTransform, &UFG::qMatrix44::msIdentity) )
        v6 = v5;
      UFG::ScriptCameraComponent::SetEyeAttachment(v4, v6);
    }
  }
}

// File Line: 291
// RVA: 0x4EB150
void __fastcall UFG::TSCamera::MthdC_pan_to_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rbp
  SSData **v5; // rsi
  UFG::TransformNodeComponent *v6; // rbx
  UFG::TransformNodeComponent *v7; // rdi

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      v6 = (UFG::TransformNodeComponent *)(*v5)->i_data_p->i_user_data;
      v7 = v6->mParent;
      if ( !v7 || !UFG::qMatrix44::operator==(&v6->mLocalTransform, &UFG::qMatrix44::msIdentity) )
        v7 = v6;
      UFG::ScriptCameraComponent::PanToTransform(
        v4,
        v7,
        *(float *)&v5[1]->i_data_p->i_user_data,
        *(float *)&v5[2]->i_data_p->i_user_data);
    }
  }
}

// File Line: 307
// RVA: 0x4E75B0
void __fastcall UFG::TSCamera::MthdC_get_debug_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::BaseCameraComponent *v3; // rcx
  UFG::TransformNodeComponent *v4; // rbx
  UFG::Camera *v5; // rcx
  UFG::qMatrix44 *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
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
  _DWORD *v20; // rax
  int v21; // xmm2_4
  int v22; // xmm1_4
  UFG::BaseCameraComponent *v23; // rax
  _DWORD *v24; // rax
  int v25; // xmm2_4
  int v26; // xmm1_4
  UFG::BaseCameraComponent *v27; // rax
  signed __int64 v28; // rax
  float v29; // xmm1_4
  float v30; // xmm2_4
  UFG::BaseCameraComponent *v31; // rax
  signed __int64 v32; // rax
  float v33; // xmm1_4
  float v34; // xmm2_4
  UFG::qMemoryPool *v35; // rax
  UFG::allocator::free_link *v36; // rdi
  unsigned int v37; // eax
  UFG::TransformNodeComponent *v38; // rax
  UFG::qMatrix44 m; // [rsp+38h] [rbp+7h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::Director::Get()->mCurrentCamera;
    v4 = 0i64;
    if ( v3 )
      v5 = &v3->mCamera;
    else
      v5 = 0i64;
    v6 = UFG::Camera::GetViewWorld(v5);
    v7 = v6->v0.y;
    v8 = v6->v0.z;
    v9 = v6->v0.w;
    m.v0.x = v6->v0.x;
    m.v0.y = v7;
    m.v0.z = v8;
    m.v0.w = v9;
    v10 = v6->v1.y;
    v11 = v6->v1.z;
    v12 = v6->v1.w;
    m.v1.x = v6->v1.x;
    m.v1.y = v10;
    m.v1.z = v11;
    m.v1.w = v12;
    v13 = v6->v2.y;
    v14 = v6->v2.z;
    v15 = v6->v2.w;
    m.v2.x = v6->v2.x;
    m.v2.y = v13;
    m.v2.z = v14;
    m.v2.w = v15;
    v16 = v6->v3.y;
    v17 = v6->v3.z;
    v18 = v6->v3.w;
    m.v3.x = v6->v3.x;
    m.v3.y = v16;
    m.v3.z = v17;
    m.v3.w = v18;
    v19 = UFG::Director::Get()->mCurrentCamera;
    if ( v19 )
      v20 = (_DWORD *)&v19->mCamera.mFOVOffset;
    else
      v20 = 0i64;
    v21 = v20[42] ^ _xmm[0];
    v22 = v20[41] ^ _xmm[0];
    LODWORD(m.v0.x) = v20[40] ^ _xmm[0];
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
      v28 = (signed __int64)&v27->mCamera;
    else
      v28 = 0i64;
    v29 = *(float *)(v28 + 148);
    v30 = *(float *)(v28 + 152);
    m.v2.x = *(float *)(v28 + 144);
    m.v2.y = v29;
    m.v2.z = v30;
    m.v2.w = 0.0;
    v31 = UFG::Director::Get()->mCurrentCamera;
    if ( v31 )
      v32 = (signed __int64)&v31->mCamera;
    else
      v32 = 0i64;
    v33 = *(float *)(v32 + 180);
    v34 = *(float *)(v32 + 184);
    m.v3.x = *(float *)(v32 + 176);
    m.v3.y = v33;
    m.v3.z = v34;
    LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
    v35 = UFG::GetSimulationMemoryPool();
    v36 = UFG::qMemoryPool::Allocate(v35, 0x110ui64, "TSCamera", 0i64, 1u);
    if ( v36 )
    {
      v37 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v36, v37, 0i64, 0);
      v4 = v38;
    }
    if ( v4 )
    {
      UFG::TransformNodeComponent::SetWorldTransform(v4, &m);
      *v2 = UFG::TSTransform::AsInstance(v4);
    }
  }
}

// File Line: 329
// RVA: 0x4ED210
void __fastcall UFG::TSCamera::MthdC_set_allow_script_camera_super_wide_aspect(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
      v4->bAllowWideAspectDisplay = (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 345
// RVA: 0x4ED760
void __fastcall UFG::TSCamera::MthdC_set_dof(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rbx
  SSData **v5; // rax

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      UFG::ScriptCameraComponent::SetDOF(
        v4,
        *(float *)&(*v5)->i_data_p->i_user_data,
        *(float *)&v5[1]->i_data_p->i_user_data,
        *(float *)&v5[2]->i_data_p->i_user_data,
        *(float *)&v5[3]->i_data_p->i_user_data,
        *(float *)&v5[4]->i_data_p->i_user_data,
        *(float *)&v5[5]->i_data_p->i_user_data,
        1);
    }
  }
}

// File Line: 352
// RVA: 0x4EC360
void __fastcall UFG::TSCamera::MthdC_reset_dof(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::SimObject *v2; // rcx
  UFG::ScriptCameraComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::ScriptCameraComponent::_TypeUID);
    if ( v3 )
      UFG::ScriptCameraComponent::ResetDOF(v3);
  }
}

// File Line: 361
// RVA: 0x4F2560
void __fastcall UFG::TSCamera::MthdC_start_dynamic_dof(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::GameCameraComponent::StartDynamicDof();
}

// File Line: 366
// RVA: 0x4F26E0
void __fastcall UFG::TSCamera::MthdC_stop_dynamic_dof(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::GameCameraComponent::StopDynamicDof();
}

// File Line: 371
// RVA: 0x4ED980
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_focal_dist(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // r8

  v2 = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    0,
    *(float *)&(*v2)->i_data_p->i_user_data,
    *(float *)&v2[1]->i_data_p->i_user_data,
    *(float *)&v2[2]->i_data_p->i_user_data,
    *(float *)&v2[3]->i_data_p->i_user_data,
    *(float *)&v2[4]->i_data_p->i_user_data,
    *(float *)&v2[5]->i_data_p->i_user_data);
}

// File Line: 381
// RVA: 0x4EDB00
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_range(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // r8

  v2 = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FocusHalfRange,
    *(float *)&(*v2)->i_data_p->i_user_data,
    *(float *)&v2[1]->i_data_p->i_user_data,
    *(float *)&v2[2]->i_data_p->i_user_data,
    *(float *)&v2[3]->i_data_p->i_user_data,
    *(float *)&v2[4]->i_data_p->i_user_data,
    *(float *)&v2[5]->i_data_p->i_user_data);
}

// File Line: 391
// RVA: 0x4EDA00
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_near_blend(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // r8

  v2 = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_NearBlendRange,
    *(float *)&(*v2)->i_data_p->i_user_data,
    *(float *)&v2[1]->i_data_p->i_user_data,
    *(float *)&v2[2]->i_data_p->i_user_data,
    *(float *)&v2[3]->i_data_p->i_user_data,
    *(float *)&v2[4]->i_data_p->i_user_data,
    *(float *)&v2[5]->i_data_p->i_user_data);
}

// File Line: 401
// RVA: 0x4EDA80
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_near_blur(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // r8

  v2 = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_NearBlendRadius,
    *(float *)&(*v2)->i_data_p->i_user_data,
    *(float *)&v2[1]->i_data_p->i_user_data,
    *(float *)&v2[2]->i_data_p->i_user_data,
    *(float *)&v2[3]->i_data_p->i_user_data,
    *(float *)&v2[4]->i_data_p->i_user_data,
    *(float *)&v2[5]->i_data_p->i_user_data);
}

// File Line: 411
// RVA: 0x4ED880
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_far_blend(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // r8

  v2 = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FarBlendRange,
    *(float *)&(*v2)->i_data_p->i_user_data,
    *(float *)&v2[1]->i_data_p->i_user_data,
    *(float *)&v2[2]->i_data_p->i_user_data,
    *(float *)&v2[3]->i_data_p->i_user_data,
    *(float *)&v2[4]->i_data_p->i_user_data,
    *(float *)&v2[5]->i_data_p->i_user_data);
}

// File Line: 421
// RVA: 0x4ED900
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dof_far_blur(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // r8

  v2 = scope->i_data.i_array_p;
  UFG::GameCameraComponent::SetDynamicDOFParam(
    DynamicDofParamType_FarBlendRadius,
    *(float *)&(*v2)->i_data_p->i_user_data,
    *(float *)&v2[1]->i_data_p->i_user_data,
    *(float *)&v2[2]->i_data_p->i_user_data,
    *(float *)&v2[3]->i_data_p->i_user_data,
    *(float *)&v2[4]->i_data_p->i_user_data,
    *(float *)&v2[5]->i_data_p->i_user_data);
}

// File Line: 434
// RVA: 0x4ED820
void __fastcall UFG::TSCamera::MthdC_set_dutch(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx

  v2 = scope;
  if ( UFG::GetCurrentGameCamera() )
    UFG::GameCameraComponent::SetDutch(
      (float)(*(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 443
// RVA: 0x4EC3A0
void __fastcall UFG::TSCamera::MthdC_reset_dutch(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx

  v2 = scope;
  if ( UFG::GetCurrentGameCamera() )
    UFG::GameCameraComponent::ResetDutch((*v2->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 452
// RVA: 0x4EDB80
void __fastcall UFG::TSCamera::MthdC_set_dynamic_dutch(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // r10

  v2 = scope;
  if ( UFG::GetCurrentGameCamera() )
  {
    v3 = v2->i_data.i_array_p;
    UFG::GameCameraComponent::SetDynamicDutch(
      *(float *)&(*v3)->i_data_p->i_user_data,
      *(float *)&v3[1]->i_data_p->i_user_data,
      (float)(*(float *)&v3[2]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      (float)(*(float *)&v3[3]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      *(float *)&v3[4]->i_data_p->i_user_data,
      *(float *)&v3[5]->i_data_p->i_user_data,
      (float)(*(float *)&v3[6]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
      (float)(*(float *)&v3[7]->i_data_p->i_user_data * 3.1415927) * 0.0055555557);
  }
}

// File Line: 467
// RVA: 0x4EE5B0
void __fastcall UFG::TSCamera::MthdC_set_override_max_radius(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
      UFG::FollowCameraComponent::SetOverrideMaxRadius(v4, *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 477
// RVA: 0x4E4570
void __fastcall UFG::TSCamera::MthdC_clear_override_max_radius(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    if ( v3 )
      LOBYTE(v3[110].m_SafePointerList.mNode.mNext) = 0;
  }
}

// File Line: 486
// RVA: 0x4EE600
void __fastcall UFG::TSCamera::MthdC_set_override_rise(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
      UFG::FollowCameraComponent::SetOverrideRise(v4, *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 496
// RVA: 0x4E45B0
void __fastcall UFG::TSCamera::MthdC_clear_override_rise(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    if ( v3 )
      LOBYTE(v3[110].m_NameUID) = 0;
  }
}

// File Line: 505
// RVA: 0x4E8A70
void __fastcall UFG::TSCamera::MthdC_goto_angle(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // r10
  SSData **v5; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      UFG::FollowCameraComponent::GotoAngle(
        v4,
        (float)(*(float *)&(*v5)->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
        (float)(*(float *)&v5[1]->i_data_p->i_user_data * 3.1415927) * 0.0055555557,
        *(float *)&v5[2]->i_data_p->i_user_data,
        v5[3]->i_data_p->i_user_data != 0);
    }
  }
}

// File Line: 519
// RVA: 0x4E8B10
void __fastcall UFG::TSCamera::MthdC_goto_angle_snap(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSData **v2; // rdx
  float v3; // xmm6_4
  bool v4; // bl
  UFG::SimObject *v5; // rcx
  UFG::FollowCameraComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  UFG::ChaseCameraComponent *v8; // rax

  v2 = scope->i_data.i_array_p;
  v3 = *(float *)&(*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data != 0;
  v5 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v5 )
  {
    v6 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v5, UFG::FollowCameraComponent::_TypeUID);
    if ( v6 )
      UFG::FollowCameraComponent::GotoAngleSnap(v6, (float)(v3 * 3.1415927) * 0.0055555557, v4);
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
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
      UFG::FollowCameraComponent::GotoRise(
        v4,
        *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
        *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64),
        *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64) + 32i64));
  }
}

// File Line: 546
// RVA: 0x4E8CB0
void __fastcall UFG::TSCamera::MthdC_goto_rise_snap(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
      UFG::FollowCameraComponent::GotoRiseSnap(v4, *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 556
// RVA: 0x4E8BD0
void __fastcall UFG::TSCamera::MthdC_goto_radius(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
      UFG::FollowCameraComponent::GotoRadius(
        v4,
        *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data,
        *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64),
        *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64) + 32i64));
  }
}

// File Line: 569
// RVA: 0x4E4D30
void __fastcall UFG::TSCamera::MthdC_enable_constrain_yaw(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  SSData **v5; // r8
  float v6; // xmm3_4
  float v7; // xmm4_4

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      v6 = (float)(*(float *)&v5[1]->i_data_p->i_user_data * 3.1415927) * 0.0055555557;
      v7 = *(float *)&v5[2]->i_data_p->i_user_data;
      *((float *)&v4[128].m_BoundComponentHandles.mNode.mPrev + 1) = (float)(*(float *)&(*v5)->i_data_p->i_user_data
                                                                           * 3.1415927)
                                                                   * 0.0055555557;
      LOBYTE(v4[128].m_BoundComponentHandles.mNode.mPrev) = 1;
      *(float *)&v4[128].m_BoundComponentHandles.mNode.mNext = v6;
      *((float *)&v4[128].m_BoundComponentHandles.mNode.mNext + 1) = (float)(v7 * 3.1415927) * 0.0055555557;
    }
  }
}

// File Line: 582
// RVA: 0x4E4B90
void __fastcall UFG::TSCamera::MthdC_disable_constrain_yaw(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    if ( v3 )
      LOBYTE(v3[128].m_BoundComponentHandles.mNode.mPrev) = 0;
  }
}

// File Line: 591
// RVA: 0x4E4CF0
void __fastcall UFG::TSCamera::MthdC_enable_combat_system(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    if ( v3 )
      LOBYTE(v3[110].m_pSimObject) = 1;
  }
}

// File Line: 600
// RVA: 0x4E4B50
void __fastcall UFG::TSCamera::MthdC_disable_combat_system(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    if ( v3 )
      LOBYTE(v3[110].m_pSimObject) = 0;
  }
}

// File Line: 609
// RVA: 0x4E4820
void __fastcall UFG::TSCamera::MthdC_combat_system_snap_next_auto_frame(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax
  UFG::SimComponent *v4; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rdx

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    v4 = v3;
    if ( v3 )
    {
      v5 = v3->vfptr;
      LOBYTE(v3[110].m_BoundComponentHandles.mNode.mPrev) = 1;
      ((void (__fastcall *)(UFG::SimComponent *))v5[15].__vecDelDtor)(v3);
      ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[31].__vecDelDtor)(v4);
      LOBYTE(v4[110].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 621
// RVA: 0x4F2AF0
void __fastcall UFG::TSCamera::MthdC_unlock_chase_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v2; // rcx
  UFG::ChaseCameraComponent *v3; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::ChaseCameraComponent::_TypeUID);
    if ( v3 )
      UFG::ChaseCameraComponent::LockEye(v3, 0);
  }
}

// File Line: 628
// RVA: 0x4EDC60
void __fastcall UFG::TSCamera::MthdC_set_eye_look_noise(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rax
  SSData **v5; // r8
  float v6; // ecx

  v2 = pScope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
    {
      v5 = v2->i_data.i_array_p;
      v6 = *(float *)&(*v5)->i_data_p->i_user_data;
      v4->mLookNoiseMagnitude = *(float *)&v5[1]->i_data_p->i_user_data;
      v4->mEyeNoiseMagnitude = v6;
    }
  }
}

// File Line: 634
// RVA: 0x4E90E0
void __fastcall UFG::TSCamera::MthdC_impact(SSInvokedMethod *scope, SSInstance **__formal)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameCameraComponent *v3; // rax

  v2 = scope;
  v3 = (UFG::GameCameraComponent *)UFG::GetCurrentGameCamera();
  if ( v3 )
    UFG::GameCameraComponent::AddShakeAmplitude(v3, *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 647
// RVA: 0x4ED260
void __fastcall UFG::TSCamera::MthdC_set_allow_targeted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::SimObject *v3; // rcx
  UFG::FollowCameraComponent *v4; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::FollowCameraComponent::_TypeUID);
    if ( v4 )
      v4->bAllowTargeted = v2;
  }
}

// File Line: 654
// RVA: 0x4ED170
void __fastcall UFG::TSCamera::MthdC_set_allow_desaturation(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // si
  UFG::ChaseCameraComponent *v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::FollowCameraComponent *v5; // rdi
  UFG::SimObject *v6; // rcx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = 0i64;
  v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v4 )
    v5 = (UFG::FollowCameraComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::FollowCameraComponent::_TypeUID);
  else
    v5 = 0i64;
  v6 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v6 )
    v3 = (UFG::ChaseCameraComponent *)UFG::SimObject::GetComponentOfType(v6, UFG::ChaseCameraComponent::_TypeUID);
  if ( v5 )
    v5->bAllowDesaturation = v2;
  if ( v3 )
    v3->mAllowDesaturation = v2;
}

// File Line: 663
// RVA: 0x4ED4E0
void __fastcall UFG::TSCamera::MthdC_set_context_override(int follow_camera_type, SSInvokedMethod *pScope)
{
  int v2; // ebp
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v3; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *v6; // rbx
  UFG::qSymbol v7; // eax
  UFG::qString result; // [rsp+28h] [rbp-40h]
  UFG::qSymbol v9; // [rsp+78h] [rbp+10h]
  UFG::qSymbol *v10; // [rsp+80h] [rbp+18h]

  v2 = follow_camera_type;
  UFG::qString::FormatEx(&result, "Cameras-%s", *(_QWORD *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v3 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&v3[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v3->mPrev[8].mNext)(v3) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v3->mPrev[8].mNext)(v3);
        v6 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 v5,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
        if ( v6 )
        {
          v10 = &v9;
          v7.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v9, result.mData);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v6, v2, v7);
        }
      }
      v3 = &v4->mNode;
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
  int v2; // ebp
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v3; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *v6; // rbx
  UFG::qSymbol v7; // eax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+18h]
  UFG::qWiseSymbol *v9; // [rsp+68h] [rbp+20h]

  v2 = follow_camera_type;
  v3 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&v3[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *, SSInvokedMethod *))v3->mPrev[8].mNext)(
             v3,
             pScope) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v3->mPrev[8].mNext)(v3);
        v6 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 v5,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
        if ( v6 )
        {
          v9 = &result;
          v7.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v6, v2, v7);
        }
      }
      v3 = &v4->mNode;
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
  int v2; // ebp
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v3; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *v6; // rbx
  UFG::qSymbol v7; // eax
  UFG::qString result; // [rsp+28h] [rbp-40h]
  UFG::qSymbol v9; // [rsp+78h] [rbp+10h]
  UFG::qSymbol *v10; // [rsp+80h] [rbp+18h]

  v2 = follow_camera_type;
  UFG::qString::FormatEx(&result, "Cameras-%s", *(_QWORD *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v3 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&v3[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v3->mPrev[8].mNext)(v3) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v3->mPrev[8].mNext)(v3);
        v6 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 v5,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
        if ( v6 )
        {
          v10 = &v9;
          v7.mUID = (unsigned int)UFG::qSymbol::create_from_string(&v9, result.mData);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v6, v2, v7);
        }
      }
      v3 = &v4->mNode;
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
  int v2; // ebp
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v3; // rbx
  UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::CharacterSubjectComponent *v6; // rbx
  UFG::qSymbol v7; // eax
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+18h]
  UFG::qWiseSymbol *v9; // [rsp+68h] [rbp+20h]

  v2 = follow_camera_type;
  v3 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext - 78;
  if ( (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mNext[-78] != &UFG::FollowCameraComponent::s_FollowCameraComponentList - 78 )
  {
    do
    {
      v4 = (UFG::qList<UFG::FollowCameraComponent,UFG::FollowCameraComponent,1,0> *)&v3[78].mNext[-78];
      if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *, SSInvokedMethod *))v3->mPrev[8].mNext)(
             v3,
             pScope) )
      {
        v5 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *))v3->mPrev[8].mNext)(v3);
        v6 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 v5,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
        if ( v6 )
        {
          v9 = &result;
          v7.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v6, v2, v7);
        }
      }
      v3 = &v4->mNode;
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
void __fastcall UFG::TSCamera::MthdC_clear_context_override_local_grapple(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCamera::MthdC_clear_context_override_local(3, pScope);
}

// File Line: 807
// RVA: 0x4EEF80
void __fastcall UFG::TSCamera::MthdC_set_social_target(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::CharacterSubjectComponent *v2; // rsi
  SSActor *v3; // rbx
  SSClass *v4; // rdi
  UFG::SimObject *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *v9; // rax
  UFG::SimComponent *v10; // rdi

  v2 = 0i64;
  v3 = (SSActor *)(*scope->i_data.i_array_p)->i_data_p;
  if ( !v3 )
    goto LABEL_8;
  v4 = v3->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))v4->vfptr->is_actor_class)(v4, result) )
  {
    if ( v4 != SSBrain::c_symbol_class_p || LODWORD(v3->i_user_data) == -1 )
      goto LABEL_8;
    v3 = SSActor::find((ASymbol *)&v3->i_user_data);
  }
  if ( !v3 )
  {
LABEL_8:
    v5 = 0i64;
    goto LABEL_9;
  }
  v5 = *(UFG::SimObject **)&v3[1].i_icoroutines_to_update.i_count;
LABEL_9:
  v6 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v6 )
  {
    v7 = UFG::SimObject::GetComponentOfType(v6, UFG::FollowCameraComponent::_TypeUID);
    v8 = v7;
    if ( v7 )
    {
      if ( ((__int64 (__fastcall *)(UFG::SimComponent *))v7->vfptr[17].__vecDelDtor)(v7) )
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
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax
  UFG::SimComponent *v4; // rbx
  UFG::SimObject *v5; // rax
  UFG::SimComponent *v6; // rax

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
    v4 = v3;
    if ( v3 )
    {
      if ( ((__int64 (__fastcall *)(UFG::SimComponent *))v3->vfptr[17].__vecDelDtor)(v3) )
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
void __fastcall UFG::TSCamera::MthdC_progression_set_monotonically_increasing(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::ProgressionCameraComponent::_TypeUID);
    if ( v4 )
      BYTE1(v4[22].vfptr) = (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 860
// RVA: 0x4EB900
void __fastcall UFG::TSCamera::MthdC_progression_set_window_size(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::ProgressionCameraComponent::_TypeUID);
    if ( v4 )
      HIDWORD(v4[22].vfptr) = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 869
// RVA: 0x4EB740
void __fastcall UFG::TSCamera::MthdC_progression_set_duration(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::ProgressionCameraComponent::_TypeUID);
    if ( v4 )
      LODWORD(v4[22].m_SafePointerList.mNode.mPrev) = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 878
// RVA: 0x4EB7E0
void __fastcall UFG::TSCamera::MthdC_progression_set_progress_transforms(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // rdi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  UFG::SimObject *v7; // rcx
  UFG::SimComponent *v8; // rbx
  int v9; // xmm0_4
  int v10; // xmm1_4
  int v11; // xmm2_4
  int v12; // xmm0_4

  v2 = scope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = *(_QWORD *)(v3 + 104);
  if ( !v4 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(v3 + 192), &UFG::qMatrix44::msIdentity) )
    v4 = v3;
  v5 = v2[1]->i_data_p->i_user_data;
  v6 = *(_QWORD *)(v5 + 104);
  if ( !v6 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(v5 + 192), &UFG::qMatrix44::msIdentity) )
    v6 = v5;
  v7 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v7 )
    v8 = UFG::SimObject::GetComponentOfType(v7, UFG::ProgressionCameraComponent::_TypeUID);
  else
    v8 = 0i64;
  if ( v4 && v6 )
  {
    if ( v8 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
      v9 = *(_DWORD *)(v4 + 180);
      v10 = *(_DWORD *)(v4 + 184);
      HIDWORD(v8[22].m_BoundComponentHandles.mNode.mPrev) = *(_DWORD *)(v4 + 176);
      LODWORD(v8[22].m_BoundComponentHandles.mNode.mNext) = v9;
      HIDWORD(v8[22].m_BoundComponentHandles.mNode.mNext) = v10;
      v11 = *(_DWORD *)(v6 + 184);
      v12 = *(_DWORD *)(v6 + 180);
      LODWORD(v8[23].vfptr) = *(_DWORD *)(v6 + 176);
      HIDWORD(v8[23].vfptr) = v12;
      LODWORD(v8[23].m_SafePointerList.mNode.mPrev) = v11;
    }
  }
}

// File Line: 889
// RVA: 0x4EB5F0
void __fastcall UFG::TSCamera::MthdC_progression_begin(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rdi
  UFG::SimObject *v3; // rcx
  UFG::ProgressionCameraComponent *v4; // rax
  UFG::ProgressionCameraComponent *v5; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rax
  UFG::qSymbolUC resulta; // [rsp+40h] [rbp+18h]

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ProgressionCameraComponent *)UFG::SimObject::GetComponentOfType(
                                              v3,
                                              UFG::ProgressionCameraComponent::_TypeUID);
    v5 = v4;
    if ( v4 )
    {
      UFG::gProgressionCameraComponent = v4;
      UFG::gPreviousCameraComponent = UFG::GetCurrentBaseCamera();
      UFG::qSymbolUC::create_from_string(&resulta, *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
      v6 = v5->vfptr;
      v5->mFov = 70.0;
      v6[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)LocalPlayer);
      *(_WORD *)&v5->bTargetSpace = 0;
      v5->bSingleBone = 0;
      UFG::AttachCameraToView((UFG::BaseCameraComponent *)&v5->vfptr);
      UFG::ProgressionCameraComponent::Play(v5, &resulta, 0.0);
    }
  }
}

// File Line: 917
// RVA: 0x4EC820
void __fastcall UFG::TSCamera::MthdC_return_xform_relative_player(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rdi
  UFG::SimComponent *v5; // rbx
  unsigned int v6; // xmm1_4
  unsigned int v7; // xmm2_4
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
  UFG::qMemoryPool *v30; // rax
  UFG::allocator::free_link *v31; // rbx
  unsigned int v32; // eax
  UFG::TransformNodeComponent *v33; // rax
  UFG::TransformNodeComponent *v34; // rbx
  UFG::qVector4 v35; // xmm6
  UFG::qVector4 v36; // xmm7
  UFG::qVector4 v37; // xmm9
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h]
  __m128 v39; // [rsp+70h] [rbp-88h]
  int v40; // [rsp+80h] [rbp-78h]
  int v41; // [rsp+84h] [rbp-74h]
  __m128 v42; // [rsp+88h] [rbp-70h]
  __m128 v43; // [rsp+98h] [rbp-60h]
  __int64 v44; // [rsp+A8h] [rbp-50h]

  if ( ppResult )
  {
    v44 = -2i64;
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = *(_QWORD *)(v3 + 104);
    if ( !v4 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(v3 + 192), &UFG::qMatrix44::msIdentity) )
      v4 = v3;
    v5 = UFG::SimObject::GetComponentOfType(
           (UFG::SimObject *)&LocalPlayer->vfptr,
           UFG::TransformNodeComponent::_TransformNodeComponentTypeUID);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v6 = *(_DWORD *)(v4 + 132);
    v7 = *(_DWORD *)(v4 + 136);
    v8 = *(_DWORD *)(v4 + 140);
    v39.m128_i32[0] = *(_DWORD *)(v4 + 128);
    *(unsigned __int64 *)((char *)v39.m128_u64 + 4) = __PAIR__(v7, v6);
    v39.m128_i32[3] = v8;
    v9 = *(_DWORD *)(v4 + 148);
    v10 = *(_DWORD *)(v4 + 152);
    v11 = *(_DWORD *)(v4 + 156);
    v39.m128_i32[2] = *(_DWORD *)(v4 + 144);
    v39.m128_i32[3] = v9;
    v40 = v10;
    v41 = v11;
    v12 = *(_DWORD *)(v4 + 164);
    v13 = *(_DWORD *)(v4 + 168);
    v14 = *(_DWORD *)(v4 + 172);
    v42.m128_i32[0] = *(_DWORD *)(v4 + 160);
    *(unsigned __int64 *)((char *)v42.m128_u64 + 4) = __PAIR__(v13, v12);
    v42.m128_i32[3] = v14;
    v15 = *(_DWORD *)(v4 + 180);
    v16 = *(_DWORD *)(v4 + 184);
    v17 = *(_DWORD *)(v4 + 188);
    v43.m128_i32[0] = *(_DWORD *)(v4 + 176);
    *(unsigned __int64 *)((char *)v43.m128_u64 + 4) = __PAIR__(v16, v15);
    v43.m128_i32[3] = v17;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
    v18 = *((float *)&v5[2].vfptr + 1);
    v19 = *(float *)&v5[2].m_SafePointerList.mNode.mPrev;
    v20 = *((float *)&v5[2].m_SafePointerList.mNode.mPrev + 1);
    m.v0.x = *(float *)&v5[2].vfptr;
    m.v0.y = v18;
    m.v0.z = v19;
    m.v0.w = v20;
    v21 = *((float *)&v5[2].m_SafePointerList.mNode.mNext + 1);
    v22 = *(float *)&v5[2].m_TypeUID;
    v23 = *(float *)&v5[2].m_NameUID;
    m.v1.x = *(float *)&v5[2].m_SafePointerList.mNode.mNext;
    m.v1.y = v21;
    m.v1.z = v22;
    m.v1.w = v23;
    v24 = *(float *)(&v5[2].m_SimObjIndex + 1);
    v25 = *(float *)&v5[2].m_pSimObject;
    v26 = *((float *)&v5[2].m_pSimObject + 1);
    m.v2.x = *(float *)&v5[2].m_Flags;
    m.v2.y = v24;
    m.v2.z = v25;
    m.v2.w = v26;
    v27 = *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v28 = *(float *)&v5[2].m_BoundComponentHandles.mNode.mNext;
    v29 = *((float *)&v5[2].m_BoundComponentHandles.mNode.mNext + 1);
    m.v3.x = *(float *)&v5[2].m_BoundComponentHandles.mNode.mPrev;
    m.v3.y = v27;
    m.v3.z = v28;
    m.v3.w = v29;
    v30 = UFG::GetSimulationMemoryPool();
    v31 = UFG::qMemoryPool::Allocate(v30, 0x110ui64, "TSCamera", 0i64, 1u);
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
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), (__m128)m.v0), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), (__m128)m.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), (__m128)m.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v39, v39, 255), (__m128)m.v3));
    m.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)((char *)&v39 + 8), *(__m128 *)((char *)&v39 + 8), 0),
                                    (__m128)v35),
                                  (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)((char *)&v39 + 8), *(__m128 *)((char *)&v39 + 8), 85),
                                  (__m128)m.v1)),
                              _mm_mul_ps(
                                _mm_shuffle_ps(*(__m128 *)((char *)&v39 + 8), *(__m128 *)((char *)&v39 + 8), 170),
                                (__m128)m.v2)),
                            _mm_mul_ps(
                              _mm_shuffle_ps(*(__m128 *)((char *)&v39 + 8), *(__m128 *)((char *)&v39 + 8), 255),
                              (__m128)m.v3));
    m.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), (__m128)v35), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), (__m128)v36)),
                              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), (__m128)m.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 255), (__m128)m.v3));
    m.v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), (__m128)v35), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), (__m128)v36)),
                              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), (__m128)v37)),
                            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 255), (__m128)m.v3));
    UFG::TransformNodeComponent::SetWorldTransform(v34, &m);
    *v2 = UFG::TSTransform::AsInstance(v34);
  }
}

// File Line: 934
// RVA: 0x4EC2F0
void __fastcall UFG::TSCamera::MthdC_reset(SSInvokedMethod *scope, SSInstance **__formal)
{
  UFG::BaseCameraComponent *v2; // rax

  v2 = UFG::GetCurrentBaseCamera();
  if ( v2 )
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v2->vfptr[14].__vecDelDtor)(v2);
}

// File Line: 947
// RVA: 0x4EB6B0
void __fastcall UFG::TSCamera::MthdC_progression_end(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::ProgressionCameraComponent *v2; // rbx
  AnimationNode *v3; // rcx
  UFG::qSafePointer<AnimationNode,AnimationNode> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rax

  if ( UFG::gProgressionCameraComponent )
  {
    UFG::gPreviousCameraComponent->vfptr[14].__vecDelDtor(
      (UFG::qSafePointerNode<UFG::SimComponent> *)UFG::gPreviousCameraComponent,
      (unsigned int)result);
    UFG::AttachCameraToView(UFG::gPreviousCameraComponent);
    v2 = UFG::gProgressionCameraComponent;
    v3 = UFG::gProgressionCameraComponent->mAnimationNode.m_pPointer;
    if ( v3 )
      v3->vfptr->__vecDelDtor((Expression::IMemberMap *)&v3->vfptr, 1u);
    v4 = &v2->mAnimationNode;
    if ( v2->mAnimationNode.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v2->mAnimationNode.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v2->mAnimationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mAnimationNode.mPrev;
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gAnimatedCameraController__);
}

// File Line: 963
// RVA: 0x4E3390
void __fastcall UFG::TSCamera::MthdC_animation_begin(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rdi
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::BaseCameraComponent *v5; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rax
  AnimationNode *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v11; // rax
  SSData **v12; // rax
  Creature *v13; // rdi
  __int64 v14; // r8
  __int64 v15; // rdx
  __int64 v16; // rdx
  __int64 v17; // r8
  UFG::SimObjectGame *v18; // rcx
  UFG::SimComponent *v19; // rax
  UFG::qSymbolUC resulta; // [rsp+70h] [rbp+18h]

  v2 = scope;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::AnimatedCameraComponent::_TypeUID);
    if ( v4 )
    {
      if ( !UFG::gAnimatedCameraComponent )
      {
        v5 = UFG::GetCurrentBaseCamera();
        UFG::gAnimatedCameraComponent = (UFG::AnimatedCameraComponent *)v4;
        UFG::gPreviousCameraComponent = v5;
        UFG::qSymbolUC::create_from_string(&resulta, *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
        v6 = v4->vfptr;
        LODWORD(v4[22].vfptr) = 1117126656;
        v6[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, (unsigned int)LocalPlayer);
        LODWORD(v4[22].m_SafePointerList.mNode.mNext) = 0;
        BYTE4(v4[22].m_SafePointerList.mNode.mNext) = 1;
        UFG::AnimatedCameraComponent::SetDofParameters(
          (UFG::AnimatedCameraComponent *)v4,
          20.0,
          5.0,
          0.0,
          4.0,
          0.0,
          4.0);
        UFG::AttachCameraToView((UFG::BaseCameraComponent *)v4);
        v7 = UFG::AnimatedCameraComponent::Play((UFG::AnimatedCameraComponent *)v4, &resulta, 0.0);
        if ( UFG::gAnimatedCameraController.m_pPointer )
        {
          v8 = UFG::gAnimatedCameraController.mPrev;
          v9 = UFG::gAnimatedCameraController.mNext;
          UFG::gAnimatedCameraController.mPrev->mNext = UFG::gAnimatedCameraController.mNext;
          v9->mPrev = v8;
          UFG::gAnimatedCameraController.mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&UFG::gAnimatedCameraController;
          UFG::gAnimatedCameraController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&UFG::gAnimatedCameraController;
        }
        UFG::gAnimatedCameraController.m_pPointer = v7;
        if ( v7 )
        {
          v10 = &v7->m_SafePointerList.mNode;
          v11 = v7->m_SafePointerList.mNode.mPrev;
          v11->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&UFG::gAnimatedCameraController;
          UFG::gAnimatedCameraController.mNext = v10;
          UFG::gAnimatedCameraController.mPrev = v11;
          v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&UFG::gAnimatedCameraController;
          if ( UFG::gAnimatedCameraController.m_pPointer )
          {
            v12 = v2->i_data.i_array_p;
            v13 = 0i64;
            UFG::gAnimatedCameraController.m_pPointer->vfptr[2].FindWithOldPath(
              (Expression::IMemberMap *)UFG::gAnimatedCameraController.m_pPointer,
              (const char *)((unsigned int)(v12[1]->i_data_p->i_user_data == 0) + 1));
            LOBYTE(v14) = 1;
            ((void (__fastcall *)(AnimationNode *, __int64, __int64))UFG::gAnimatedCameraController.m_pPointer->vfptr[1].GetClassNameUID)(
              UFG::gAnimatedCameraController.m_pPointer,
              v15,
              v14);
            v18 = (UFG::SimObjectGame *)v4->m_pSimObject;
            if ( v18 )
            {
              v16 = v18->m_Flags;
              if ( ((unsigned __int16)v16 >> 14) & 1 )
              {
                v19 = v18->m_Components.p[9].m_pComponent;
              }
              else if ( (v16 & 0x8000u) == 0i64 )
              {
                if ( ((unsigned __int16)v16 >> 13) & 1 )
                {
                  v19 = v18->m_Components.p[8].m_pComponent;
                }
                else if ( ((unsigned __int16)v16 >> 12) & 1 )
                {
                  v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::BaseAnimationComponent::_TypeUID);
                }
                else
                {
                  v19 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v18->vfptr,
                          UFG::BaseAnimationComponent::_TypeUID);
                }
              }
              else
              {
                v19 = v18->m_Components.p[9].m_pComponent;
              }
              if ( v19 )
                v13 = *(Creature **)&v19[2].m_TypeUID;
            }
            if ( v13 )
            {
              Creature::Update(v13, 0.0, v16, v17);
              Creature::UpdateTransforms(v13);
              ((void (__fastcall *)(UFG::SimComponent *))v4->vfptr[15].__vecDelDtor)(v4);
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
  AnimationNode *v3; // rcx
  UFG::qSafePointer<AnimationNode,AnimationNode> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx

  if ( UFG::gAnimatedCameraComponent )
  {
    UFG::gPreviousCameraComponent->vfptr[14].__vecDelDtor(
      (UFG::qSafePointerNode<UFG::SimComponent> *)UFG::gPreviousCameraComponent,
      (unsigned int)result);
    UFG::AttachCameraToView(UFG::gPreviousCameraComponent);
    ((void (*)(void))UFG::gPreviousCameraComponent->vfptr[15].__vecDelDtor)();
    v2 = UFG::gAnimatedCameraComponent;
    v3 = UFG::gAnimatedCameraComponent->mAnimationNode.m_pPointer;
    if ( v3 )
      v3->vfptr->__vecDelDtor((Expression::IMemberMap *)&v3->vfptr, 1u);
    v4 = &v2->mAnimationNode;
    if ( v2->mAnimationNode.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v2->mAnimationNode.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v2->mAnimationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mAnimationNode.mPrev;
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
      UFG::gAnimatedCameraController.mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&UFG::gAnimatedCameraController;
      UFG::gAnimatedCameraController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&UFG::gAnimatedCameraController;
    }
    UFG::gAnimatedCameraController.m_pPointer = 0i64;
  }
}

