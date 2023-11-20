// File Line: 45
// RVA: 0x1531410
__int64 anonymous_namespace_::_dynamic_initializer_for__TSTransform_name_id_def__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Skookum.xformNode", 0xFFFFFFFF);
  `anonymous namespace'::TSTransform_name_id_def = result;
  return result;
}

// File Line: 64
// RVA: 0x4CC6E0
SSInstance *__fastcall UFG::TSTransform::AsInstance(UFG::TransformNodeComponent *xformNode)
{
  UFG::TransformNodeComponent *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax

  v1 = xformNode;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x110ui64, "Skookum.xformNode", 0i64, 1u);
  if ( v3 )
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v3, v1->m_NameUID, v1, 0);
  return SSInstance::pool_new(UFG::SkookumMgr::mspTransformClass, (unsigned __int64)v3);
}

// File Line: 93
// RVA: 0x4D6F60
void UFG::TSTransform::BindAtomics(void)
{
  UFG::SkookumMgr::mspTransformClass = SSBrain::get_class("Transform");
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, &ASymbolX_ctor, UFG::TSTransform::Mthd_ctor, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    &ASymbolX_dtor,
    UFG::TSDynamicEncounter::Mthd_destructor,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "get_dir", UFG::TSTransform::Mthd_get_dir, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_back",
    UFG::TSTransform::Mthd_get_dir_back,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_right",
    UFG::TSTransform::Mthd_get_dir_right,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_left",
    UFG::TSTransform::Mthd_get_dir_left,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "get_dir_up", UFG::TSTransform::Mthd_get_dir_up, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_down",
    UFG::TSTransform::Mthd_get_dir_down,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "get_pos", UFG::TSTransform::Mthd_get_pos, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_yaw_angle",
    UFG::TSTransform::Mthd_get_yaw_angle,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "set_pos", UFG::TSTransform::Mthd_set_pos, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_local",
    UFG::TSTransform::Mthd_set_pos_local,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_face_dir",
    UFG::TSTransform::Mthd_set_pos_face_dir,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_face_dir_local",
    UFG::TSTransform::Mthd_set_pos_face_dir_local,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_face_pos",
    UFG::TSTransform::Mthd_set_pos_face_pos,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "teleport_dir",
    UFG::TSTransform::Mthd_teleport_dir,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "teleport_pos",
    UFG::TSTransform::Mthd_teleport_pos,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "teleport_xform",
    UFG::TSTransform::Mthd_teleport_xform,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "clear_parent",
    UFG::TSTransform::Mthd_clear_parent,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "is_child", UFG::TSTransform::Mthd_is_child, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "is_parent", UFG::TSTransform::Mthd_is_parent, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "set_parent", UFG::TSTransform::Mthd_set_parent, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_first_child",
    UFG::TSTransform::Mthd_get_first_child,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "get_next", UFG::TSTransform::Mthd_get_next, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "as_marker", UFG::TSTransform::Mthd_as_marker, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_ai_path_marker",
    UFG::TSTransform::Mthd_as_ai_path_marker,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_spawn_point",
    UFG::TSTransform::Mthd_as_spawn_point,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspTransformClass, "as_poi", UFG::TSTransform::Mthd_as_poi, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_combat_region",
    UFG::TSTransform::Mthd_as_combat_region,
    0);
}r::mspTransformClass,
    "as_combat_region",
    UFG:

// File Line: 148
// RVA: 0x4F7310
void __fastcall UFG::TSTransform::Mthd_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  SSObjectBaseVtbl *v5; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x110ui64, "Skookum.XformNode", 0i64, 1u);
  if ( v4 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v4,
      `anonymous namespace'::TSTransform_name_id_def,
      0i64,
      0);
    v2[2].vfptr = v5;
  }
  else
  {
    v2[2].vfptr = 0i64;
  }
}

// File Line: 174
// RVA: 0x4FC500
void __fastcall UFG::TSTransform::Mthd_get_dir(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    *v3 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v4[2]);
  }
}

// File Line: 188
// RVA: 0x4FC600
void __fastcall UFG::TSTransform::Mthd_get_dir_back(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // rbx
  SSObjectBaseVtbl *v4; // rbx
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  UFG::allocator::free_link *v8; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v5 = LODWORD(v4[2].get_obj_type) ^ _xmm[0];
    v6 = HIDWORD(v4[2].__vecDelDtor) ^ _xmm[0];
    v7 = LODWORD(v4[2].__vecDelDtor) ^ _xmm[0];
    v8 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      LODWORD(v8->mNext) = v7;
      HIDWORD(v8->mNext) = v6;
      LODWORD(v8[1].mNext) = v5;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 202
// RVA: 0x4FC9D0
void __fastcall UFG::TSTransform::Mthd_get_dir_right(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // rbx
  SSObjectBaseVtbl *v4; // rbx
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  UFG::allocator::free_link *v8; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v5 = LODWORD(v4[2].as_instance) ^ _xmm[0];
    v6 = HIDWORD(v4[2].is_actor) ^ _xmm[0];
    v7 = LODWORD(v4[2].is_actor) ^ _xmm[0];
    v8 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      LODWORD(v8->mNext) = v7;
      HIDWORD(v8->mNext) = v6;
      LODWORD(v8[1].mNext) = v5;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 216
// RVA: 0x4FC8D0
void __fastcall UFG::TSTransform::Mthd_get_dir_left(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    *v3 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v4[2].is_actor);
  }
}

// File Line: 230
// RVA: 0x4FCB10
void __fastcall UFG::TSTransform::Mthd_get_dir_up(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    *v3 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v4[2].get_data_by_name);
  }
}

// File Line: 244
// RVA: 0x4FC790
void __fastcall UFG::TSTransform::Mthd_get_dir_down(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // rbx
  SSObjectBaseVtbl *v4; // rbx
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  UFG::allocator::free_link *v8; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = v3[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v5 = LODWORD(v4[2].set_data_by_name) ^ _xmm[0];
    v6 = HIDWORD(v4[2].get_data_by_name) ^ _xmm[0];
    v7 = LODWORD(v4[2].get_data_by_name) ^ _xmm[0];
    v8 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      LODWORD(v8->mNext) = v7;
      HIDWORD(v8->mNext) = v6;
      LODWORD(v8[1].mNext) = v5;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 258
// RVA: 0x4FDDF0
void __fastcall UFG::TSTransform::Mthd_get_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    *v3 = UFG::TSVector3::AsInstance((UFG::qVector3 *)&v4[2].get_scope_context);
  }
}

// File Line: 272
// RVA: 0x4FF7A0
void __fastcall UFG::TSTransform::Mthd_get_yaw_angle(SSInvokedMethod *scope, SSInstance **result)
{
  SSInvokedMethod *v2; // rdi
  SSInstance **v3; // rsi
  UFG::TransformNodeComponent *v4; // rbx
  float v5; // xmm6_4
  float v6; // xmm7_4
  SSObjectBase *v7; // rbx
  UFG::TransformNodeComponent *v8; // rbx
  float v9; // xmm0_4

  if ( result )
  {
    v2 = scope;
    v3 = result;
    v4 = (UFG::TransformNodeComponent *)(*scope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = v4->mWorldTransform.v3.x;
    v6 = v4->mWorldTransform.v3.y;
    v7 = v2->i_scope_p.i_obj_p;
    if ( !v7 || v2->i_scope_p.i_ptr_id != v7->i_ptr_id )
      v7 = 0i64;
    v8 = (UFG::TransformNodeComponent *)v7[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    v9 = atan2f(
           COERCE_FLOAT(COERCE_UNSIGNED_INT(v5 - v8->mWorldTransform.v3.x) ^ _xmm[0]),
           v6 - v8->mWorldTransform.v3.y);
    *v3 = SSInstance::pool_new(
            SSBrain::c_real_class_p,
            COERCE_UNSIGNED_INT((float)((float)(v9 - 1.5707964) * 180.0) * 0.31830987));
  }
}

// File Line: 291
// RVA: 0x5093F0
void __fastcall UFG::TSTransform::Mthd_set_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rsi
  SSObjectBase *v3; // rdx
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = (UFG::TransformNodeComponent *)v3[2].vfptr;
  v5 = v4->mParent;
  if ( !v5 || !UFG::qMatrix44::operator==(&v4->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v5 = v4;
  UFG::TransformNodeComponent::SetWorldTranslation(v5, (UFG::qVector3 *)v2->i_user_data);
}

// File Line: 302
// RVA: 0x509D30
void __fastcall UFG::TSTransform::Mthd_set_pos_local(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // rsi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::TransformNodeComponent *v5; // rdi

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (UFG::TransformNodeComponent *)v2[2].vfptr;
  v5 = v4->mParent;
  if ( !v5 || !UFG::qMatrix44::operator==(&v4->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v5 = v4;
  UFG::TransformNodeComponent::SetLocalTranslation(v5, (UFG::qVector3 *)(*v3->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 323
// RVA: 0x509460
void __fastcall UFG::TSTransform::Mthd_set_pos_face_dir(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInvokedMethod *v3; // r10
  unsigned int *v4; // rcx
  float *v5; // r8
  float *v6; // rax
  float v7; // xmm8_4
  __m128 v8; // xmm7
  float v9; // xmm9_4
  __m128 v10; // xmm3
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  __int128 v15; // xmm10
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm5
  float v19; // xmm1_4
  float v20; // xmm6_4
  __int128 v21; // xmm11
  float v22; // xmm6_4
  __m128 v23; // xmm5
  float v24; // xmm1_4
  float v25; // xmm6_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  __m128 v28; // xmm10
  float v29; // xmm3_4
  __m128 v30; // xmm6
  float v31; // xmm2_4
  SSObjectBase *v32; // rcx
  float v33; // xmm2_4
  float v34; // xmm0_4
  UFG::TransformNodeComponent *v35; // rdi
  UFG::TransformNodeComponent *v36; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h]

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = (unsigned int *)v2[2]->i_data_p->i_user_data;
  v5 = (float *)v2[1]->i_data_p->i_user_data;
  v6 = (float *)(*v2)->i_data_p->i_user_data;
  v7 = v5[1];
  v8 = (__m128)*(unsigned int *)v5;
  v9 = v5[2];
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v12 = v8.m128_f32[0] * v11;
  v13 = v7 * v11;
  v14 = v9 * v11;
  m.v0.w = 0.0;
  m.v0.x = v12;
  m.v0.y = v13;
  m.v0.z = v14;
  v15 = v4[1];
  v16 = (__m128)*v4;
  v17 = (__m128)v4[2];
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(*(float *)&v15 * *(float *)&v15))
                  + (float)(v17.m128_f32[0] * v17.m128_f32[0]);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  v17.m128_f32[0] = v17.m128_f32[0] * v19;
  v20 = v16.m128_f32[0] * v19;
  *(float *)&v15 = *(float *)&v15 * v19;
  v21 = v15;
  *(float *)&v21 = (float)(*(float *)&v15 * v14) - (float)(v17.m128_f32[0] * v13);
  v17.m128_f32[0] = (float)(v17.m128_f32[0] * v12) - (float)(v20 * v14);
  v22 = (float)(v20 * v13) - (float)(*(float *)&v15 * v12);
  v23 = v17;
  v23.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(*(float *)&v21 * *(float *)&v21))
                  + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v25 = v22 * v24;
  v26 = v17.m128_f32[0] * v24;
  *(float *)&v21 = *(float *)&v21 * v24;
  m.v1.w = 0.0;
  m.v1.z = v25;
  m.v1.y = v26;
  LODWORD(m.v1.x) = v21;
  v28 = (__m128)v21;
  v27 = (float)(v25 * v13) - (float)(v26 * v14);
  v28.m128_f32[0] = (float)(*(float *)&v21 * v14) - (float)(v25 * v12);
  v29 = (float)(v26 * v12) - (float)(*(float *)&v21 * v13);
  v30 = v28;
  v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
  v32 = v3->i_scope_p.i_obj_p;
  m.v2.w = 0.0;
  m.v2.x = v27 * v31;
  m.v2.y = v28.m128_f32[0] * v31;
  m.v2.z = v29 * v31;
  v33 = v6[2];
  v34 = *v6;
  m.v3.y = v6[1];
  m.v3.w = 1.0;
  m.v3.x = v34;
  m.v3.z = v33;
  if ( !v32 || v3->i_scope_p.i_ptr_id != v32->i_ptr_id )
    v32 = 0i64;
  v35 = (UFG::TransformNodeComponent *)v32[2].vfptr;
  v36 = v35->mParent;
  if ( !v36 || !UFG::qMatrix44::operator==(&v35->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v36 = v35;
  UFG::TransformNodeComponent::SetWorldTransform(v36, &m);
}

// File Line: 343
// RVA: 0x509740
void __fastcall UFG::TSTransform::Mthd_set_pos_face_dir_local(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r9
  SSInvokedMethod *v3; // r10
  unsigned int *v4; // rcx
  float *v5; // r8
  float *v6; // rax
  float v7; // xmm8_4
  __m128 v8; // xmm7
  float v9; // xmm9_4
  __m128 v10; // xmm3
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  __int128 v15; // xmm10
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm5
  float v19; // xmm1_4
  float v20; // xmm6_4
  __int128 v21; // xmm11
  float v22; // xmm6_4
  __m128 v23; // xmm5
  float v24; // xmm1_4
  float v25; // xmm6_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  __m128 v28; // xmm10
  float v29; // xmm3_4
  __m128 v30; // xmm6
  float v31; // xmm2_4
  SSObjectBase *v32; // rcx
  float v33; // xmm2_4
  float v34; // xmm0_4
  UFG::TransformNodeComponent *v35; // rdi
  UFG::TransformNodeComponent *v36; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h]

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = (unsigned int *)v2[2]->i_data_p->i_user_data;
  v5 = (float *)v2[1]->i_data_p->i_user_data;
  v6 = (float *)(*v2)->i_data_p->i_user_data;
  v7 = v5[1];
  v8 = (__m128)*(unsigned int *)v5;
  v9 = v5[2];
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v12 = v8.m128_f32[0] * v11;
  v13 = v7 * v11;
  v14 = v9 * v11;
  m.v0.w = 0.0;
  m.v0.x = v12;
  m.v0.y = v13;
  m.v0.z = v14;
  v15 = v4[1];
  v16 = (__m128)*v4;
  v17 = (__m128)v4[2];
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(*(float *)&v15 * *(float *)&v15))
                  + (float)(v17.m128_f32[0] * v17.m128_f32[0]);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  v17.m128_f32[0] = v17.m128_f32[0] * v19;
  v20 = v16.m128_f32[0] * v19;
  *(float *)&v15 = *(float *)&v15 * v19;
  v21 = v15;
  *(float *)&v21 = (float)(*(float *)&v15 * v14) - (float)(v17.m128_f32[0] * v13);
  v17.m128_f32[0] = (float)(v17.m128_f32[0] * v12) - (float)(v20 * v14);
  v22 = (float)(v20 * v13) - (float)(*(float *)&v15 * v12);
  v23 = v17;
  v23.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(*(float *)&v21 * *(float *)&v21))
                  + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v25 = v22 * v24;
  v26 = v17.m128_f32[0] * v24;
  *(float *)&v21 = *(float *)&v21 * v24;
  m.v1.w = 0.0;
  m.v1.z = v25;
  m.v1.y = v26;
  LODWORD(m.v1.x) = v21;
  v28 = (__m128)v21;
  v27 = (float)(v25 * v13) - (float)(v26 * v14);
  v28.m128_f32[0] = (float)(*(float *)&v21 * v14) - (float)(v25 * v12);
  v29 = (float)(v26 * v12) - (float)(*(float *)&v21 * v13);
  v30 = v28;
  v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
  v32 = v3->i_scope_p.i_obj_p;
  m.v2.w = 0.0;
  m.v2.x = v27 * v31;
  m.v2.y = v28.m128_f32[0] * v31;
  m.v2.z = v29 * v31;
  v33 = v6[2];
  v34 = *v6;
  m.v3.y = v6[1];
  m.v3.w = 1.0;
  m.v3.x = v34;
  m.v3.z = v33;
  if ( !v32 || v3->i_scope_p.i_ptr_id != v32->i_ptr_id )
    v32 = 0i64;
  v35 = (UFG::TransformNodeComponent *)v32[2].vfptr;
  v36 = v35->mParent;
  if ( !v36 || !UFG::qMatrix44::operator==(&v35->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v36 = v35;
  UFG::TransformNodeComponent::SetLocalTransform(v36, &m);
}

// File Line: 363
// RVA: 0x509A20
void __fastcall UFG::TSTransform::Mthd_set_pos_face_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInvokedMethod *v3; // r10
  float *v4; // rcx
  unsigned int *v5; // r9
  float *v6; // rax
  __int128 v7; // xmm5
  __m128 v8; // xmm6
  __int128 v9; // xmm7
  __m128 v10; // xmm4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm9_4
  __m128 v14; // xmm8
  float v15; // xmm11_4
  __m128 v16; // xmm4
  float v17; // xmm1_4
  float v18; // xmm8_4
  float v19; // xmm11_4
  float v20; // xmm9_4
  __int128 v21; // xmm10
  float v22; // xmm11_4
  __m128 v23; // xmm4
  float v24; // xmm11_4
  __m128 v25; // xmm8
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm8_4
  __m128 v29; // xmm9
  float v30; // xmm4_4
  __m128 v31; // xmm5
  float v32; // xmm2_4
  SSObjectBase *v33; // rcx
  float v34; // xmm2_4
  float v35; // xmm0_4
  UFG::TransformNodeComponent *v36; // rdi
  UFG::TransformNodeComponent *v37; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h]

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = (float *)v2[2]->i_data_p->i_user_data;
  v5 = (unsigned int *)v2[1]->i_data_p->i_user_data;
  v6 = (float *)(*v2)->i_data_p->i_user_data;
  v7 = *v5;
  v8 = (__m128)v5[1];
  v9 = v5[2];
  *(float *)&v7 = *(float *)&v7 - *v6;
  v8.m128_f32[0] = v8.m128_f32[0] - v6[1];
  *(float *)&v9 = *(float *)&v9 - v6[2];
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(*(float *)&v7 * *(float *)&v7))
                  + (float)(*(float *)&v9 * *(float *)&v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  *(float *)&v7 = *(float *)&v7 * v11;
  v12 = v8.m128_f32[0] * v11;
  *(float *)&v9 = *(float *)&v9 * v11;
  m.v0.w = 0.0;
  LODWORD(m.v0.x) = v7;
  m.v0.y = v12;
  LODWORD(m.v0.z) = v9;
  v13 = v4[1];
  v14 = (__m128)*(unsigned int *)v4;
  v15 = v4[2];
  v16 = v14;
  v16.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
  if ( v16.m128_f32[0] == 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
  v18 = v14.m128_f32[0] * v17;
  v19 = v15 * v17;
  v20 = v13 * v17;
  v21 = v9;
  v23 = (__m128)v7;
  v23.m128_f32[0] = *(float *)&v7 * v19;
  *(float *)&v21 = (float)(*(float *)&v9 * v20) - (float)(v12 * v19);
  v22 = v12 * v18;
  v23.m128_f32[0] = v23.m128_f32[0] - (float)(*(float *)&v9 * v18);
  v25 = v23;
  v24 = v22 - (float)(*(float *)&v7 * v20);
  v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(*(float *)&v21 * *(float *)&v21))
                  + (float)(v24 * v24);
  if ( v25.m128_f32[0] == 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
  v27 = v23.m128_f32[0] * v26;
  *(float *)&v21 = *(float *)&v21 * v26;
  m.v1.w = 0.0;
  v29 = (__m128)v21;
  m.v1.y = v27;
  m.v1.z = v24 * v26;
  LODWORD(m.v1.x) = v21;
  v28 = (float)((float)(v24 * v26) * v12) - (float)(v27 * *(float *)&v9);
  v29.m128_f32[0] = (float)(*(float *)&v21 * *(float *)&v9) - (float)((float)(v24 * v26) * *(float *)&v7);
  v30 = (float)(v27 * *(float *)&v7) - (float)(*(float *)&v21 * v12);
  v31 = v29;
  v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28)) + (float)(v30 * v30);
  if ( v31.m128_f32[0] == 0.0 )
    v32 = 0.0;
  else
    v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
  v33 = v3->i_scope_p.i_obj_p;
  m.v2.w = 0.0;
  m.v2.x = v28 * v32;
  m.v2.y = v29.m128_f32[0] * v32;
  m.v2.z = v30 * v32;
  v34 = v6[2];
  v35 = *v6;
  m.v3.y = v6[1];
  m.v3.w = 1.0;
  m.v3.x = v35;
  m.v3.z = v34;
  if ( !v33 || v3->i_scope_p.i_ptr_id != v33->i_ptr_id )
    v33 = 0i64;
  v36 = (UFG::TransformNodeComponent *)v33[2].vfptr;
  v37 = v36->mParent;
  if ( !v37 || !UFG::qMatrix44::operator==(&v36->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v37 = v36;
  UFG::TransformNodeComponent::SetWorldTransform(v37, &m);
}

// File Line: 380
// RVA: 0x50C860
void __fastcall UFG::TSTransform::Mthd_teleport_dir(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSObjectBase *v3; // rdx
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  SSData **v9; // rdx
  _DWORD *v10; // r9
  unsigned __int64 v11; // r8
  float *v12; // rax
  float v13; // xmm3_4
  __m128 v14; // xmm6
  float v15; // xmm7_4
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm10_4
  __m128 v22; // xmm8
  __m128 v23; // xmm9
  __m128 v24; // xmm2
  float v25; // xmm1_4
  float v26; // xmm8_4
  float v27; // xmm10_4
  float v28; // xmm11_4
  float v29; // xmm8_4
  __m128 v30; // xmm2
  float v31; // xmm6_4
  float v32; // xmm3_4
  float v33; // xmm2_4
  float v34; // xmm6_4
  float v35; // xmm9_4
  __m128 v36; // xmm8
  float v37; // xmm7_4
  __m128 v38; // xmm2
  float v39; // xmm4_4
  int v40; // xmm0_4
  int v41; // xmm1_4

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v3[2].vfptr;
  v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
  if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
    v5 = v4;
  if ( v5 )
    v5 = (SSObjectBaseVtbl *)v5->set_data_by_name;
  if ( v5 )
  {
    v6 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v6 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v6,
        (unsigned int)v5[1].__vecDelDtor,
        0,
        UFG::TeleportEvent::m_Name);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = v2->i_data.i_array_p;
    v10 = (_DWORD *)(*v9)->i_data_p->i_user_data;
    v11 = v9[1]->i_data_p->i_user_data;
    v12 = (float *)v9[2]->i_data_p->i_user_data;
    v13 = *(float *)v11;
    if ( *(float *)v11 != 0.0 || 0.0 != *(float *)(v11 + 4) || 0.0 != *(float *)(v11 + 8) )
    {
      v14 = (__m128)*(unsigned int *)(v11 + 4);
      v15 = *(float *)(v11 + 8);
      v16 = v14;
      v16.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
      if ( v16.m128_f32[0] == 0.0 )
        v17 = 0.0;
      else
        v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
      v18 = v13 * v17;
      v19 = v14.m128_f32[0] * v17;
      v20 = v15 * v17;
      *(float *)(v8 + 80) = v18;
      *(float *)(v8 + 84) = v19;
      *(float *)(v8 + 88) = v20;
      *(_DWORD *)(v8 + 92) = 0;
      v21 = v12[1];
      v22 = (__m128)*(unsigned int *)v12;
      v23 = (__m128)*((unsigned int *)v12 + 2);
      v24 = v22;
      v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21))
                      + (float)(v23.m128_f32[0] * v23.m128_f32[0]);
      if ( v24.m128_f32[0] == 0.0 )
        v25 = 0.0;
      else
        v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
      v26 = v22.m128_f32[0] * v25;
      v27 = v21 * v25;
      v23.m128_f32[0] = v23.m128_f32[0] * v25;
      v28 = (float)(v27 * v20) - (float)(v23.m128_f32[0] * v19);
      v23.m128_f32[0] = (float)(v23.m128_f32[0] * v18) - (float)(v26 * v20);
      v29 = (float)(v26 * v19) - (float)(v27 * v18);
      v30 = v23;
      v30.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v28 * v28)) + (float)(v29 * v29);
      if ( v30.m128_f32[0] == 0.0 )
        v31 = 0.0;
      else
        v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
      v32 = v31 * v28;
      v33 = v31 * v23.m128_f32[0];
      v34 = v31 * v29;
      *(float *)(v8 + 96) = v32;
      *(float *)(v8 + 100) = v33;
      *(float *)(v8 + 104) = v34;
      *(_DWORD *)(v8 + 108) = 0;
      v36 = (__m128)*(unsigned int *)(v8 + 88);
      v35 = (float)(*(float *)(v8 + 84) * v34) - (float)(*(float *)(v8 + 88) * v33);
      v36.m128_f32[0] = (float)(v36.m128_f32[0] * v32) - (float)(*(float *)(v8 + 80) * v34);
      v37 = (float)(*(float *)(v8 + 80) * v33) - (float)(*(float *)(v8 + 84) * v32);
      v38 = v36;
      v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
      if ( v38.m128_f32[0] == 0.0 )
        v39 = 0.0;
      else
        v39 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v38));
      *(float *)(v8 + 112) = v39 * v35;
      *(float *)(v8 + 116) = v39 * v36.m128_f32[0];
      *(float *)(v8 + 120) = v39 * v37;
      *(_DWORD *)(v8 + 124) = 0;
      v40 = v10[1];
      v41 = v10[2];
      *(_DWORD *)(v8 + 128) = *v10;
      *(_DWORD *)(v8 + 132) = v40;
      *(_DWORD *)(v8 + 136) = v41;
      *(_DWORD *)(v8 + 140) = 1065353216;
    }
    else
    {
      UFG::qTranslationMatrix((UFG::qMatrix44 *)(v8 + 80), (UFG::qVector3 *)(*v9)->i_data_p->i_user_data);
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
  }
}

// File Line: 413
// RVA: 0x50D050
void __fastcall UFG::TSTransform::Mthd_teleport_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSObjectBase *v3; // rdx
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  SSData **v9; // rdx
  float *v10; // r8
  unsigned __int64 v11; // r9
  float *v12; // rax
  float v13; // xmm5_4
  float v14; // xmm5_4
  __m128 v15; // xmm6
  float v16; // xmm7_4
  __m128 v17; // xmm4
  float v18; // xmm0_4
  __m128 v19; // xmm4
  __m128 v20; // xmm9
  float v21; // xmm8_4
  float v22; // xmm4_4
  float v23; // xmm7_4
  __m128 v24; // xmm6
  float v25; // xmm10_4
  __m128 v26; // xmm5
  float v27; // xmm1_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm10_4
  float v31; // xmm11_4
  __m128 v32; // xmm12
  float v33; // xmm8_4
  __m128 v34; // xmm4
  float v35; // xmm1_4
  float v36; // xmm11_4
  float v37; // xmm12_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  __m128 v40; // xmm6
  float v41; // xmm5_4
  __m128 v42; // xmm4
  float v43; // xmm2_4
  int v44; // xmm0_4
  int v45; // xmm1_4

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = v3[2].vfptr;
  v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
  if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
    v5 = v4;
  if ( v5 )
    v5 = (SSObjectBaseVtbl *)v5->set_data_by_name;
  if ( v5 )
  {
    v6 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v6 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v6,
        (unsigned int)v5[1].__vecDelDtor,
        0,
        UFG::TeleportEvent::m_Name);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = v2->i_data.i_array_p;
    v10 = (float *)(*v9)->i_data_p->i_user_data;
    v11 = v9[1]->i_data_p->i_user_data;
    v12 = (float *)v9[2]->i_data_p->i_user_data;
    v13 = *(float *)v11;
    if ( (*(float *)v11 != 0.0 || 0.0 != *(float *)(v11 + 4) || 0.0 != *(float *)(v11 + 8))
      && (*v10 != v13 || *(float *)(v11 + 4) != v10[1] || *(float *)(v11 + 8) != v10[2]) )
    {
      v14 = v13 - *v10;
      v15 = (__m128)*(unsigned int *)(v11 + 4);
      v15.m128_f32[0] = v15.m128_f32[0] - v10[1];
      v16 = *(float *)(v11 + 8) - v10[2];
      v17 = v15;
      v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
      if ( v17.m128_f32[0] == 0.0 )
      {
        v19 = 0i64;
      }
      else
      {
        LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
        v19 = (__m128)(unsigned int)FLOAT_1_0;
        v19.m128_f32[0] = 1.0 / v18;
      }
      v20 = v19;
      v20.m128_f32[0] = v19.m128_f32[0] * v14;
      v21 = v19.m128_f32[0] * v15.m128_f32[0];
      v22 = v19.m128_f32[0] * v16;
      *(_DWORD *)(v8 + 80) = v20.m128_i32[0];
      *(float *)(v8 + 84) = v21;
      *(float *)(v8 + 88) = v22;
      *(_DWORD *)(v8 + 92) = 0;
      v23 = v12[1];
      v24 = (__m128)*(unsigned int *)v12;
      v25 = v12[2];
      v26 = v24;
      v26.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23)) + (float)(v25 * v25);
      if ( v26.m128_f32[0] == 0.0 )
        v27 = 0.0;
      else
        v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
      v28 = v24.m128_f32[0] * v27;
      v29 = v23 * v27;
      v30 = v25 * v27;
      v31 = (float)(v22 * v29) - (float)(v21 * v30);
      v32 = v20;
      v32.m128_f32[0] = (float)(v20.m128_f32[0] * v30) - (float)(v22 * v28);
      v33 = (float)(v21 * v28) - (float)(v20.m128_f32[0] * v29);
      v34 = v32;
      v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v31 * v31)) + (float)(v33 * v33);
      if ( v34.m128_f32[0] == 0.0 )
        v35 = 0.0;
      else
        v35 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v34));
      v36 = v31 * v35;
      v37 = v32.m128_f32[0] * v35;
      v38 = v33 * v35;
      *(float *)(v8 + 96) = v36;
      *(float *)(v8 + 100) = v37;
      *(float *)(v8 + 104) = v38;
      *(_DWORD *)(v8 + 108) = 0;
      v40 = (__m128)*(unsigned int *)(v8 + 88);
      v39 = (float)(*(float *)(v8 + 84) * v38) - (float)(*(float *)(v8 + 88) * v37);
      v40.m128_f32[0] = (float)(v40.m128_f32[0] * v36) - (float)(*(float *)(v8 + 80) * v38);
      v41 = (float)(*(float *)(v8 + 80) * v37) - (float)(*(float *)(v8 + 84) * v36);
      v42 = v40;
      v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
      if ( v42.m128_f32[0] == 0.0 )
        v43 = 0.0;
      else
        v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
      *(float *)(v8 + 112) = v43 * v39;
      *(float *)(v8 + 116) = v43 * v40.m128_f32[0];
      *(float *)(v8 + 120) = v43 * v41;
      *(_DWORD *)(v8 + 124) = 0;
      v44 = *((_DWORD *)v10 + 1);
      v45 = *((_DWORD *)v10 + 2);
      *(float *)(v8 + 128) = *v10;
      *(_DWORD *)(v8 + 132) = v44;
      *(_DWORD *)(v8 + 136) = v45;
      *(_DWORD *)(v8 + 140) = 1065353216;
    }
    else
    {
      UFG::qTranslationMatrix((UFG::qMatrix44 *)(v8 + 80), (UFG::qVector3 *)(*v9)->i_data_p->i_user_data);
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
  }
}

// File Line: 446
// RVA: 0x50DAC0
void __fastcall UFG::TSTransform::Mthd_teleport_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbp
  SSObjectBase *v3; // rdx
  UFG::Event *v4; // rdi
  SSObjectBaseVtbl *v5; // rsi
  SSObjectBaseVtbl *v6; // rbx
  void (__fastcall *v7)(SSObjectBase *, ASymbol *, SSInstance *); // rsi
  UFG::TransformNodeComponent *v8; // rbx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  UFG::allocator::free_link *v21; // rax
  UFG::Event *v22; // rax
  UFG::qMatrix44 worldXform; // [rsp+40h] [rbp-48h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  v4 = 0i64;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v5 = v3[2].vfptr;
  v6 = (SSObjectBaseVtbl *)v5[1].set_data_by_name;
  if ( !v6 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v5[3], &UFG::qMatrix44::msIdentity) )
    v6 = v5;
  if ( v6 )
    v7 = v6->set_data_by_name;
  else
    v7 = 0i64;
  if ( v7 )
  {
    v8 = (UFG::TransformNodeComponent *)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    v9 = v8->mWorldTransform.v0.y;
    v10 = v8->mWorldTransform.v0.z;
    v11 = v8->mWorldTransform.v0.w;
    worldXform.v0.x = v8->mWorldTransform.v0.x;
    worldXform.v0.y = v9;
    worldXform.v0.z = v10;
    worldXform.v0.w = v11;
    v12 = v8->mWorldTransform.v1.y;
    v13 = v8->mWorldTransform.v1.z;
    v14 = v8->mWorldTransform.v1.w;
    worldXform.v1.x = v8->mWorldTransform.v1.x;
    worldXform.v1.y = v12;
    worldXform.v1.z = v13;
    worldXform.v1.w = v14;
    v15 = v8->mWorldTransform.v2.y;
    v16 = v8->mWorldTransform.v2.z;
    v17 = v8->mWorldTransform.v2.w;
    worldXform.v2.x = v8->mWorldTransform.v2.x;
    worldXform.v2.y = v15;
    worldXform.v2.z = v16;
    worldXform.v2.w = v17;
    v18 = v8->mWorldTransform.v3.y;
    v19 = v8->mWorldTransform.v3.z;
    v20 = v8->mWorldTransform.v3.w;
    worldXform.v3.x = v8->mWorldTransform.v3.x;
    worldXform.v3.y = v18;
    worldXform.v3.z = v19;
    worldXform.v3.w = v20;
    v21 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v21 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v21,
        &worldXform,
        *((_DWORD *)v7 + 16),
        0,
        UFG::TeleportEvent::m_Name,
        0);
      v4 = v22;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v4);
  }
}

// File Line: 465
// RVA: 0x4F6580
void __fastcall UFG::TSTransform::Mthd_clear_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSInvokedMethod *v3; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (UFG::TransformNodeComponent *)v2[2].vfptr;
  v5 = v4->mParent;
  if ( !v5 || !UFG::qMatrix44::operator==(&v4->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v5 = v4;
  if ( (*v3->i_data.i_array_p)->i_data_p->i_user_data )
    UFG::TransformNodeComponent::SetParentKeepWorld(v5, 0i64, 0);
  else
    UFG::TransformNodeComponent::SetParent(v5, 0i64, 0);
}

// File Line: 486
// RVA: 0x500FA0
void __fastcall UFG::TSTransform::Mthd_is_child(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rbx
  SSObjectBaseVtbl *v5; // rdi

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    *v3 = (SSInstance *)SSBoolean::pool_new(v5[1].set_data_by_name != 0i64);
  }
}

// File Line: 501
// RVA: 0x502930
void __fastcall UFG::TSTransform::Mthd_is_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    *v3 = (SSInstance *)SSBoolean::pool_new((char *)v5[1].as_instance - 64 != (char *)&v5->is_actor);
  }
}

// File Line: 517
// RVA: 0x509290
void __fastcall UFG::TSTransform::Mthd_set_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::TransformNodeComponent *v3; // rbx
  SSInvokedMethod *v4; // rbp
  UFG::TransformNodeComponent *v5; // rsi
  UFG::TransformNodeComponent *v6; // rdi
  SSData **v7; // r14
  UFG::TransformNodeComponent *v8; // rsi

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  v4 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v5 = (UFG::TransformNodeComponent *)v2[2].vfptr;
  v6 = v5->mParent;
  if ( !v6 || !UFG::qMatrix44::operator==(&v5->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v6 = v5;
  v7 = v4->i_data.i_array_p;
  v8 = (UFG::TransformNodeComponent *)(*v7)->i_data_p->i_user_data;
  if ( v8 )
  {
    v3 = v8->mParent;
    if ( !v3 || !UFG::qMatrix44::operator==(&v8->mLocalTransform, &UFG::qMatrix44::msIdentity) )
      v3 = v8;
  }
  if ( v7[1]->i_data_p->i_user_data )
    UFG::TransformNodeComponent::SetParentKeepWorld(v6, v3, 0);
  else
    UFG::TransformNodeComponent::SetParent(v6, v3, 0);
}

// File Line: 547
// RVA: 0x4FD020
void __fastcall UFG::TSTransform::Mthd_get_first_child(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rsi
  SSObjectBaseVtbl *v5; // rbx
  UFG::TransformNodeComponent *v6; // rcx

  if ( result )
  {
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    v6 = (UFG::TransformNodeComponent *)((char *)v5[1].as_instance - 64);
    if ( v6 == (UFG::TransformNodeComponent *)&v5->is_actor )
      *v3 = 0i64;
    else
      *v3 = UFG::TSTransform::AsInstance(v6);
  }
}

// File Line: 567
// RVA: 0x4FD750
void __fastcall UFG::TSTransform::Mthd_get_next(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rsi
  SSObjectBaseVtbl *v5; // rbx
  void (__fastcall *v6)(SSObjectBase *, ASymbol *, SSInstance *); // rax
  UFG::TransformNodeComponent *v7; // rcx

  if ( result )
  {
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    v6 = v5[1].set_data_by_name;
    if ( v6 )
    {
      v7 = (UFG::TransformNodeComponent *)((char *)v5[1].get_obj_type - 64);
      if ( v7 == (UFG::TransformNodeComponent *)((char *)v6 + 16) )
        *v3 = 0i64;
      else
        *v3 = UFG::TSTransform::AsInstance(v7);
    }
  }
}

// File Line: 592
// RVA: 0x4F5080
void __fastcall UFG::TSTransform::Mthd_as_marker(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::MarkerBase *v7; // rax

  if ( result )
  {
    *result = 0i64;
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    if ( v5 )
    {
      v6 = (UFG::SimObject *)v5->set_data_by_name;
      if ( v6 )
      {
        v7 = (UFG::MarkerBase *)UFG::SimObject::GetComponentOfType(v6, UFG::MarkerBase::_TypeUID);
        if ( v7 )
          *v3 = UFG::TSMarker::AsInstance(v7);
      }
    }
  }
}

// File Line: 617
// RVA: 0x4F4F40
void __fastcall UFG::TSTransform::Mthd_as_ai_path_marker(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *v7; // rax

  if ( result )
  {
    *result = 0i64;
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    if ( v5 )
    {
      v6 = (UFG::SimObject *)v5->set_data_by_name;
      if ( v6 )
      {
        v7 = UFG::SimObject::GetComponentOfType(v6, UFG::AIMarker::_TypeUID);
        if ( v7 )
          *v3 = SSInstance::pool_new(UFG::TSAIPathMarker::mspClass, (unsigned __int64)v7);
      }
    }
  }
}

// File Line: 642
// RVA: 0x4F52B0
void __fastcall UFG::TSTransform::Mthd_as_spawn_point(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *v7; // rax

  if ( result )
  {
    *result = 0i64;
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    if ( v5 )
    {
      v6 = (UFG::SimObject *)v5->set_data_by_name;
      if ( v6 )
      {
        v7 = UFG::SimObject::GetComponentOfType(v6, UFG::SpawnPoint::_TypeUID);
        if ( v7 )
          *v3 = SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)v7);
      }
    }
  }
}

// File Line: 666
// RVA: 0x4F5210
void __fastcall UFG::TSTransform::Mthd_as_poi(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::InterestPoint *v7; // rax

  if ( result )
  {
    *result = 0i64;
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    if ( v5 )
    {
      v6 = (UFG::SimObject *)v5->set_data_by_name;
      if ( v6 )
      {
        v7 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
        if ( v7 )
          *v3 = UFG::TSInterestPoint::AsInstance(v7);
      }
    }
  }
}

// File Line: 690
// RVA: 0x4F4FE0
void __fastcall UFG::TSTransform::Mthd_as_combat_region(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rsi
  SSObjectBaseVtbl *v4; // rdi
  SSObjectBaseVtbl *v5; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *v7; // rax

  if ( result )
  {
    *result = 0i64;
    v2 = scope->i_scope_p.i_obj_p;
    v3 = result;
    if ( !v2 || scope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = (SSObjectBaseVtbl *)v4[1].set_data_by_name;
    if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&v4[3], &UFG::qMatrix44::msIdentity) )
      v5 = v4;
    if ( v5 )
    {
      v6 = (UFG::SimObject *)v5->set_data_by_name;
      if ( v6 )
      {
        v7 = UFG::SimObject::GetComponentOfType(v6, UFG::CombatRegion::_TypeUID);
        if ( v7 )
          *v3 = SSInstance::pool_new(UFG::TSCombatRegion::mspCombatRegionClass, (unsigned __int64)v7);
      }
    }
  }
}

