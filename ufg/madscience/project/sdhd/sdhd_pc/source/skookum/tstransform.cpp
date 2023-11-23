// File Line: 45
// RVA: 0x1531410
__int64 anonymous_namespace_::_dynamic_initializer_for__TSTransform_name_id_def__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Skookum.xformNode", 0xFFFFFFFF);
  `anonymous namespace::TSTransform_name_id_def = result;
  return result;
}

// File Line: 64
// RVA: 0x4CC6E0
SSInstance *__fastcall UFG::TSTransform::AsInstance(UFG::TransformNodeComponent *xformNode)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "Skookum.xformNode", 0i64, 1u);
  if ( v3 )
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v3,
      xformNode->m_NameUID,
      xformNode,
      0);
  return SSInstance::pool_new(UFG::SkookumMgr::mspTransformClass, (unsigned __int64)v3);
}

// File Line: 93
// RVA: 0x4D6F60
void UFG::TSTransform::BindAtomics(void)
{
  UFG::SkookumMgr::mspTransformClass = SSBrain::get_class("Transform");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    &ASymbolX_ctor,
    UFG::TSTransform::Mthd_ctor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    &ASymbolX_dtor,
    UFG::TSDynamicEncounter::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir",
    UFG::TSTransform::Mthd_get_dir,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_back",
    UFG::TSTransform::Mthd_get_dir_back,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_right",
    UFG::TSTransform::Mthd_get_dir_right,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_left",
    UFG::TSTransform::Mthd_get_dir_left,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_up",
    UFG::TSTransform::Mthd_get_dir_up,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_dir_down",
    UFG::TSTransform::Mthd_get_dir_down,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_pos",
    UFG::TSTransform::Mthd_get_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_yaw_angle",
    UFG::TSTransform::Mthd_get_yaw_angle,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos",
    UFG::TSTransform::Mthd_set_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_local",
    UFG::TSTransform::Mthd_set_pos_local,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_face_dir",
    UFG::TSTransform::Mthd_set_pos_face_dir,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_face_dir_local",
    UFG::TSTransform::Mthd_set_pos_face_dir_local,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_pos_face_pos",
    UFG::TSTransform::Mthd_set_pos_face_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "teleport_dir",
    UFG::TSTransform::Mthd_teleport_dir,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "teleport_pos",
    UFG::TSTransform::Mthd_teleport_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "teleport_xform",
    UFG::TSTransform::Mthd_teleport_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "clear_parent",
    UFG::TSTransform::Mthd_clear_parent,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "is_child",
    UFG::TSTransform::Mthd_is_child,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "is_parent",
    UFG::TSTransform::Mthd_is_parent,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "set_parent",
    UFG::TSTransform::Mthd_set_parent,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_first_child",
    UFG::TSTransform::Mthd_get_first_child,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "get_next",
    UFG::TSTransform::Mthd_get_next,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_marker",
    UFG::TSTransform::Mthd_as_marker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_ai_path_marker",
    UFG::TSTransform::Mthd_as_ai_path_marker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_spawn_point",
    UFG::TSTransform::Mthd_as_spawn_point,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_poi",
    UFG::TSTransform::Mthd_as_poi,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTransformClass,
    "as_combat_region",
    UFG::TSTransform::Mthd_as_combat_region,
    SSBindFlag_instance_no_rebind);
}

// File Line: 148
// RVA: 0x4F7310
void __fastcall UFG::TSTransform::Mthd_ctor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  SSObjectBaseVtbl *v5; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "Skookum.XformNode", 0i64, 1u);
  if ( v4 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v4,
      `anonymous namespace::TSTransform_name_id_def,
      0i64,
      0);
    i_obj_p[2].vfptr = v5;
  }
  else
  {
    i_obj_p[2].vfptr = 0i64;
  }
}

// File Line: 174
// RVA: 0x4FC500
void __fastcall UFG::TSTransform::Mthd_get_dir(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&vfptr[2]);
  }
}

// File Line: 188
// RVA: 0x4FC600
void __fastcall UFG::TSTransform::Mthd_get_dir_back(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  UFG::allocator::free_link *v8; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    v5 = LODWORD(vfptr[2].get_obj_type) ^ _xmm[0];
    v6 = HIDWORD(vfptr[2].__vecDelDtor) ^ _xmm[0];
    v7 = LODWORD(vfptr[2].__vecDelDtor) ^ _xmm[0];
    v8 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      LODWORD(v8->mNext) = v7;
      HIDWORD(v8->mNext) = v6;
      LODWORD(v8[1].mNext) = v5;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 202
// RVA: 0x4FC9D0
void __fastcall UFG::TSTransform::Mthd_get_dir_right(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  UFG::allocator::free_link *v8; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    v5 = LODWORD(vfptr[2].as_instance) ^ _xmm[0];
    v6 = HIDWORD(vfptr[2].is_actor) ^ _xmm[0];
    v7 = LODWORD(vfptr[2].is_actor) ^ _xmm[0];
    v8 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      LODWORD(v8->mNext) = v7;
      HIDWORD(v8->mNext) = v6;
      LODWORD(v8[1].mNext) = v5;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 216
// RVA: 0x4FC8D0
void __fastcall UFG::TSTransform::Mthd_get_dir_left(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&vfptr[2].is_actor);
  }
}

// File Line: 230
// RVA: 0x4FCB10
void __fastcall UFG::TSTransform::Mthd_get_dir_up(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&vfptr[2].get_data_by_name);
  }
}

// File Line: 244
// RVA: 0x4FC790
void __fastcall UFG::TSTransform::Mthd_get_dir_down(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx
  int v5; // xmm6_4
  int v6; // xmm7_4
  int v7; // xmm8_4
  UFG::allocator::free_link *v8; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    v5 = LODWORD(vfptr[2].set_data_by_name) ^ _xmm[0];
    v6 = HIDWORD(vfptr[2].get_data_by_name) ^ _xmm[0];
    v7 = LODWORD(vfptr[2].get_data_by_name) ^ _xmm[0];
    v8 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      LODWORD(v8->mNext) = v7;
      HIDWORD(v8->mNext) = v6;
      LODWORD(v8[1].mNext) = v5;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 258
// RVA: 0x4FDDF0
void __fastcall UFG::TSTransform::Mthd_get_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSObjectBaseVtbl *vfptr; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)vfptr);
    *ppResult = UFG::TSVector3::AsInstance((UFG::qVector3 *)&vfptr[2].get_scope_context);
  }
}

// File Line: 272
// RVA: 0x4FF7A0
void __fastcall UFG::TSTransform::Mthd_get_yaw_angle(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::TransformNodeComponent *i_user_data; // rbx
  float x; // xmm6_4
  float y; // xmm7_4
  SSObjectBase *i_obj_p; // rbx
  UFG::TransformNodeComponent *vfptr; // rbx
  float v9; // xmm0_4

  if ( result )
  {
    i_user_data = (UFG::TransformNodeComponent *)(*scope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform(i_user_data);
    x = i_user_data->mWorldTransform.v3.x;
    y = i_user_data->mWorldTransform.v3.y;
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
    UFG::TransformNodeComponent::UpdateWorldTransform(vfptr);
    v9 = atan2f(
           COERCE_FLOAT(COERCE_UNSIGNED_INT(x - vfptr->mWorldTransform.v3.x) ^ _xmm[0]),
           y - vfptr->mWorldTransform.v3.y);
    *result = SSInstance::pool_new(
                SSBrain::c_real_class_p,
                COERCE_UNSIGNED_INT((float)((float)(v9 - 1.5707964) * 180.0) * 0.31830987));
  }
}

// File Line: 291
// RVA: 0x5093F0
void __fastcall UFG::TSTransform::Mthd_set_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rsi
  SSObjectBase *i_obj_p; // rdx
  UFG::TransformNodeComponent *vfptr; // rdi
  UFG::TransformNodeComponent *mParent; // rbx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  UFG::TransformNodeComponent::SetWorldTranslation(mParent, (UFG::qVector3 *)i_data_p->i_user_data);
}

// File Line: 302
// RVA: 0x509D30
void __fastcall UFG::TSTransform::Mthd_set_pos_local(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::TransformNodeComponent *vfptr; // rbx
  UFG::TransformNodeComponent *mParent; // rdi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  UFG::TransformNodeComponent::SetLocalTranslation(
    mParent,
    (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 323
// RVA: 0x509460
void __fastcall UFG::TSTransform::Mthd_set_pos_face_dir(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  unsigned int *i_user_data; // rcx
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
  float v25; // xmm5_4
  __m128 v26; // xmm10
  float v27; // xmm3_4
  __m128 v28; // xmm6
  float v29; // xmm2_4
  SSObjectBase *i_obj_p; // rcx
  float v31; // xmm2_4
  float v32; // xmm0_4
  UFG::TransformNodeComponent *vfptr; // rdi
  UFG::TransformNodeComponent *mParent; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (unsigned int *)i_array_p[2]->i_data_p->i_user_data;
  v5 = (float *)i_array_p[1]->i_data_p->i_user_data;
  v6 = (float *)(*i_array_p)->i_data_p->i_user_data;
  v7 = v5[1];
  v8 = (__m128)*(unsigned int *)v5;
  v9 = v5[2];
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = v8.m128_f32[0] * v11;
  v13 = v7 * v11;
  v14 = v9 * v11;
  m.v0.w = 0.0;
  m.v0.x = v12;
  m.v0.y = v13;
  m.v0.z = v14;
  v15 = i_user_data[1];
  v16 = (__m128)*i_user_data;
  v17 = (__m128)i_user_data[2];
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(*(float *)&v15 * *(float *)&v15))
                  + (float)(v17.m128_f32[0] * v17.m128_f32[0]);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
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
    v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
  *(float *)&v21 = *(float *)&v21 * v24;
  m.v1.w = 0.0;
  m.v1.z = v22 * v24;
  m.v1.y = v17.m128_f32[0] * v24;
  LODWORD(m.v1.x) = v21;
  v26 = (__m128)v21;
  v25 = (float)((float)(v22 * v24) * v13) - (float)((float)(v17.m128_f32[0] * v24) * v14);
  v26.m128_f32[0] = (float)(*(float *)&v21 * v14) - (float)((float)(v22 * v24) * v12);
  v27 = (float)((float)(v17.m128_f32[0] * v24) * v12) - (float)(*(float *)&v21 * v13);
  v28 = v26;
  v28.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
  if ( v28.m128_f32[0] == 0.0 )
    v29 = 0.0;
  else
    v29 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
  i_obj_p = pScope->i_scope_p.i_obj_p;
  m.v2.w = 0.0;
  m.v2.x = v25 * v29;
  m.v2.y = v26.m128_f32[0] * v29;
  m.v2.z = v27 * v29;
  v31 = v6[2];
  v32 = *v6;
  m.v3.y = v6[1];
  m.v3.w = 1.0;
  m.v3.x = v32;
  m.v3.z = v31;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  UFG::TransformNodeComponent::SetWorldTransform(mParent, &m);
}

// File Line: 343
// RVA: 0x509740
void __fastcall UFG::TSTransform::Mthd_set_pos_face_dir_local(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  unsigned int *i_user_data; // rcx
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
  float v25; // xmm5_4
  __m128 v26; // xmm10
  float v27; // xmm3_4
  __m128 v28; // xmm6
  float v29; // xmm2_4
  SSObjectBase *i_obj_p; // rcx
  float v31; // xmm2_4
  float v32; // xmm0_4
  UFG::TransformNodeComponent *vfptr; // rdi
  UFG::TransformNodeComponent *mParent; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (unsigned int *)i_array_p[2]->i_data_p->i_user_data;
  v5 = (float *)i_array_p[1]->i_data_p->i_user_data;
  v6 = (float *)(*i_array_p)->i_data_p->i_user_data;
  v7 = v5[1];
  v8 = (__m128)*(unsigned int *)v5;
  v9 = v5[2];
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = v8.m128_f32[0] * v11;
  v13 = v7 * v11;
  v14 = v9 * v11;
  m.v0.w = 0.0;
  m.v0.x = v12;
  m.v0.y = v13;
  m.v0.z = v14;
  v15 = i_user_data[1];
  v16 = (__m128)*i_user_data;
  v17 = (__m128)i_user_data[2];
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(*(float *)&v15 * *(float *)&v15))
                  + (float)(v17.m128_f32[0] * v17.m128_f32[0]);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
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
    v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
  *(float *)&v21 = *(float *)&v21 * v24;
  m.v1.w = 0.0;
  m.v1.z = v22 * v24;
  m.v1.y = v17.m128_f32[0] * v24;
  LODWORD(m.v1.x) = v21;
  v26 = (__m128)v21;
  v25 = (float)((float)(v22 * v24) * v13) - (float)((float)(v17.m128_f32[0] * v24) * v14);
  v26.m128_f32[0] = (float)(*(float *)&v21 * v14) - (float)((float)(v22 * v24) * v12);
  v27 = (float)((float)(v17.m128_f32[0] * v24) * v12) - (float)(*(float *)&v21 * v13);
  v28 = v26;
  v28.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
  if ( v28.m128_f32[0] == 0.0 )
    v29 = 0.0;
  else
    v29 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
  i_obj_p = pScope->i_scope_p.i_obj_p;
  m.v2.w = 0.0;
  m.v2.x = v25 * v29;
  m.v2.y = v26.m128_f32[0] * v29;
  m.v2.z = v27 * v29;
  v31 = v6[2];
  v32 = *v6;
  m.v3.y = v6[1];
  m.v3.w = 1.0;
  m.v3.x = v32;
  m.v3.z = v31;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  UFG::TransformNodeComponent::SetLocalTransform(mParent, &m);
}

// File Line: 363
// RVA: 0x509A20
void __fastcall UFG::TSTransform::Mthd_set_pos_face_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  float *i_user_data; // rcx
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
  float v27; // xmm8_4
  __m128 v28; // xmm9
  float v29; // xmm4_4
  __m128 v30; // xmm5
  float v31; // xmm2_4
  SSObjectBase *i_obj_p; // rcx
  float v33; // xmm2_4
  float v34; // xmm0_4
  UFG::TransformNodeComponent *vfptr; // rdi
  UFG::TransformNodeComponent *mParent; // rbx
  UFG::qMatrix44 m; // [rsp+20h] [rbp-A8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (float *)i_array_p[2]->i_data_p->i_user_data;
  v5 = (unsigned int *)i_array_p[1]->i_data_p->i_user_data;
  v6 = (float *)(*i_array_p)->i_data_p->i_user_data;
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
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  *(float *)&v7 = *(float *)&v7 * v11;
  v12 = v8.m128_f32[0] * v11;
  *(float *)&v9 = *(float *)&v9 * v11;
  m.v0.w = 0.0;
  LODWORD(m.v0.x) = v7;
  m.v0.y = v12;
  LODWORD(m.v0.z) = v9;
  v13 = i_user_data[1];
  v14 = (__m128)*(unsigned int *)i_user_data;
  v15 = i_user_data[2];
  v16 = v14;
  v16.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
  if ( v16.m128_f32[0] == 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
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
    v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  *(float *)&v21 = *(float *)&v21 * v26;
  m.v1.w = 0.0;
  v28 = (__m128)v21;
  m.v1.y = v23.m128_f32[0] * v26;
  m.v1.z = v24 * v26;
  LODWORD(m.v1.x) = v21;
  v27 = (float)((float)(v24 * v26) * v12) - (float)((float)(v23.m128_f32[0] * v26) * *(float *)&v9);
  v28.m128_f32[0] = (float)(*(float *)&v21 * *(float *)&v9) - (float)((float)(v24 * v26) * *(float *)&v7);
  v29 = (float)((float)(v23.m128_f32[0] * v26) * *(float *)&v7) - (float)(*(float *)&v21 * v12);
  v30 = v28;
  v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  i_obj_p = pScope->i_scope_p.i_obj_p;
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
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  UFG::TransformNodeComponent::SetWorldTransform(mParent, &m);
}, &UFG::qMatrix44::msI

// File Line: 380
// RVA: 0x50C860
void __fastcall UFG::TSTransform::Mthd_teleport_dir(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  SSData **i_array_p; // rdx
  _DWORD *i_user_data; // r9
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

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
  if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
    set_data_by_name = vfptr;
  if ( set_data_by_name )
    set_data_by_name = (SSObjectBaseVtbl *)set_data_by_name->set_data_by_name;
  if ( set_data_by_name )
  {
    v6 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v6 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v6,
        (unsigned int)set_data_by_name[1].__vecDelDtor,
        0,
        UFG::TeleportEvent::m_Name);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (_DWORD *)(*i_array_p)->i_data_p->i_user_data;
    v11 = i_array_p[1]->i_data_p->i_user_data;
    v12 = (float *)i_array_p[2]->i_data_p->i_user_data;
    v13 = *(float *)v11;
    if ( *(float *)v11 == 0.0 && *(float *)(v11 + 4) == 0.0 && *(float *)(v11 + 8) == 0.0 )
    {
      UFG::qTranslationMatrix((UFG::qMatrix44 *)(v8 + 80), (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data);
    }
    else
    {
      v14 = (__m128)*(unsigned int *)(v11 + 4);
      v15 = *(float *)(v11 + 8);
      v16 = v14;
      v16.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
      if ( v16.m128_f32[0] == 0.0 )
        v17 = 0.0;
      else
        v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
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
        v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
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
        v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
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
        v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
      *(float *)(v8 + 112) = v39 * v35;
      *(float *)(v8 + 116) = v39 * v36.m128_f32[0];
      *(float *)(v8 + 120) = v39 * v37;
      *(_DWORD *)(v8 + 124) = 0;
      v40 = i_user_data[1];
      v41 = i_user_data[2];
      *(_DWORD *)(v8 + 128) = *i_user_data;
      *(_DWORD *)(v8 + 132) = v40;
      *(_DWORD *)(v8 + 136) = v41;
      *(_DWORD *)(v8 + 140) = 1065353216;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
  }
}

// File Line: 413
// RVA: 0x50D050
void __fastcall UFG::TSTransform::Mthd_teleport_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  SSData **i_array_p; // rdx
  float *i_user_data; // r8
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

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
  if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
    set_data_by_name = vfptr;
  if ( set_data_by_name )
    set_data_by_name = (SSObjectBaseVtbl *)set_data_by_name->set_data_by_name;
  if ( set_data_by_name )
  {
    v6 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
    if ( v6 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v6,
        (unsigned int)set_data_by_name[1].__vecDelDtor,
        0,
        UFG::TeleportEvent::m_Name);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    v11 = i_array_p[1]->i_data_p->i_user_data;
    v12 = (float *)i_array_p[2]->i_data_p->i_user_data;
    v13 = *(float *)v11;
    if ( *(float *)v11 == 0.0 && *(float *)(v11 + 4) == 0.0 && *(float *)(v11 + 8) == 0.0
      || *i_user_data == v13 && *(float *)(v11 + 4) == i_user_data[1] && *(float *)(v11 + 8) == i_user_data[2] )
    {
      UFG::qTranslationMatrix((UFG::qMatrix44 *)(v8 + 80), (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data);
    }
    else
    {
      v14 = v13 - *i_user_data;
      v15 = (__m128)*(unsigned int *)(v11 + 4);
      v15.m128_f32[0] = v15.m128_f32[0] - i_user_data[1];
      v16 = *(float *)(v11 + 8) - i_user_data[2];
      v17 = v15;
      v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
      if ( v17.m128_f32[0] == 0.0 )
      {
        v19 = 0i64;
      }
      else
      {
        v18 = _mm_sqrt_ps(v17).m128_f32[0];
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
        v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
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
        v35 = 1.0 / _mm_sqrt_ps(v34).m128_f32[0];
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
        v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
      *(float *)(v8 + 112) = v43 * v39;
      *(float *)(v8 + 116) = v43 * v40.m128_f32[0];
      *(float *)(v8 + 120) = v43 * v41;
      *(_DWORD *)(v8 + 124) = 0;
      v44 = *((_DWORD *)i_user_data + 1);
      v45 = *((_DWORD *)i_user_data + 2);
      *(float *)(v8 + 128) = *i_user_data;
      *(_DWORD *)(v8 + 132) = v44;
      *(_DWORD *)(v8 + 136) = v45;
      *(_DWORD *)(v8 + 140) = 1065353216;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
  }
}

// File Line: 446
// RVA: 0x50DAC0
void __fastcall UFG::TSTransform::Mthd_teleport_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::Event *v4; // rdi
  SSObjectBaseVtbl *vfptr; // rsi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  void (__fastcall *v7)(SSObjectBase *, ASymbol *, SSInstance *); // rsi
  unsigned __int64 i_user_data; // rbx
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
  UFG::qMatrix44 worldXform; // [rsp+40h] [rbp-48h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v4 = 0i64;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
  if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
    set_data_by_name = vfptr;
  if ( set_data_by_name )
    v7 = set_data_by_name->set_data_by_name;
  else
    v7 = 0i64;
  if ( v7 )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_user_data);
    v9 = *(float *)(i_user_data + 132);
    v10 = *(float *)(i_user_data + 136);
    v11 = *(float *)(i_user_data + 140);
    worldXform.v0.x = *(float *)(i_user_data + 128);
    worldXform.v0.y = v9;
    worldXform.v0.z = v10;
    worldXform.v0.w = v11;
    v12 = *(float *)(i_user_data + 148);
    v13 = *(float *)(i_user_data + 152);
    v14 = *(float *)(i_user_data + 156);
    worldXform.v1.x = *(float *)(i_user_data + 144);
    worldXform.v1.y = v12;
    worldXform.v1.z = v13;
    worldXform.v1.w = v14;
    v15 = *(float *)(i_user_data + 164);
    v16 = *(float *)(i_user_data + 168);
    v17 = *(float *)(i_user_data + 172);
    worldXform.v2.x = *(float *)(i_user_data + 160);
    worldXform.v2.y = v15;
    worldXform.v2.z = v16;
    worldXform.v2.w = v17;
    v18 = *(float *)(i_user_data + 180);
    v19 = *(float *)(i_user_data + 184);
    v20 = *(float *)(i_user_data + 188);
    worldXform.v3.x = *(float *)(i_user_data + 176);
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
  SSObjectBase *i_obj_p; // rdx
  UFG::TransformNodeComponent *vfptr; // rdi
  UFG::TransformNodeComponent *mParent; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    UFG::TransformNodeComponent::SetParentKeepWorld(mParent, 0i64, eInheritXform_Full);
  else
    UFG::TransformNodeComponent::SetParent(mParent, 0i64, eInheritXform_Full);
}

// File Line: 486
// RVA: 0x500FA0
void __fastcall UFG::TSTransform::Mthd_is_child(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rbx
  SSObjectBaseVtbl *set_data_by_name; // rdi

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    *ppResult = SSBoolean::pool_new(set_data_by_name[1].set_data_by_name != 0i64);
  }
}

// File Line: 501
// RVA: 0x502930
void __fastcall UFG::TSTransform::Mthd_is_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    *ppResult = SSBoolean::pool_new((char *)set_data_by_name[1].as_instance - 64 != (char *)&set_data_by_name->is_actor);
  }
}

// File Line: 517
// RVA: 0x509290
void __fastcall UFG::TSTransform::Mthd_set_parent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::TransformNodeComponent *v3; // rbx
  UFG::TransformNodeComponent *vfptr; // rsi
  UFG::TransformNodeComponent *mParent; // rdi
  SSData **i_array_p; // r14
  UFG::TransformNodeComponent *i_user_data; // rsi

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::TransformNodeComponent *)i_obj_p[2].vfptr;
  mParent = vfptr->mParent;
  if ( !mParent || !UFG::qMatrix44::operator==(&vfptr->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    mParent = vfptr;
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (UFG::TransformNodeComponent *)(*i_array_p)->i_data_p->i_user_data;
  if ( i_user_data )
  {
    v3 = i_user_data->mParent;
    if ( !v3 || !UFG::qMatrix44::operator==(&i_user_data->mLocalTransform, &UFG::qMatrix44::msIdentity) )
      v3 = i_user_data;
  }
  if ( i_array_p[1]->i_data_p->i_user_data )
    UFG::TransformNodeComponent::SetParentKeepWorld(mParent, v3, eInheritXform_Full);
  else
    UFG::TransformNodeComponent::SetParent(mParent, v3, eInheritXform_Full);
}

// File Line: 547
// RVA: 0x4FD020
void __fastcall UFG::TSTransform::Mthd_get_first_child(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rsi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::TransformNodeComponent *v6; // rcx

  if ( result )
  {
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    v6 = (UFG::TransformNodeComponent *)((char *)set_data_by_name[1].as_instance - 64);
    if ( v6 == (UFG::TransformNodeComponent *)&set_data_by_name->is_actor )
      *result = 0i64;
    else
      *result = UFG::TSTransform::AsInstance(v6);
  }
}

// File Line: 567
// RVA: 0x4FD750
void __fastcall UFG::TSTransform::Mthd_get_next(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rsi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  void (__fastcall *v6)(SSObjectBase *, ASymbol *, SSInstance *); // rax
  UFG::TransformNodeComponent *v7; // rcx

  if ( result )
  {
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    v6 = set_data_by_name[1].set_data_by_name;
    if ( v6 )
    {
      v7 = (UFG::TransformNodeComponent *)((char *)set_data_by_name[1].get_obj_type - 64);
      if ( v7 == (UFG::TransformNodeComponent *)((char *)v6 + 16) )
        *result = 0i64;
      else
        *result = UFG::TSTransform::AsInstance(v7);
    }
  }
}

// File Line: 592
// RVA: 0x4F5080
void __fastcall UFG::TSTransform::Mthd_as_marker(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::SimObject *v6; // rcx
  UFG::MarkerBase *ComponentOfType; // rax

  if ( result )
  {
    *result = 0i64;
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    if ( set_data_by_name )
    {
      v6 = (UFG::SimObject *)set_data_by_name->set_data_by_name;
      if ( v6 )
      {
        ComponentOfType = (UFG::MarkerBase *)UFG::SimObject::GetComponentOfType(v6, UFG::MarkerBase::_TypeUID);
        if ( ComponentOfType )
          *result = UFG::TSMarker::AsInstance(ComponentOfType);
      }
    }
  }
}

// File Line: 617
// RVA: 0x4F4F40
void __fastcall UFG::TSTransform::Mthd_as_ai_path_marker(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  if ( result )
  {
    *result = 0i64;
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    if ( set_data_by_name )
    {
      v6 = (UFG::SimObject *)set_data_by_name->set_data_by_name;
      if ( v6 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::AIMarker::_TypeUID);
        if ( ComponentOfType )
          *result = SSInstance::pool_new(UFG::TSAIPathMarker::mspClass, (unsigned __int64)ComponentOfType);
      }
    }
  }
}

// File Line: 642
// RVA: 0x4F52B0
void __fastcall UFG::TSTransform::Mthd_as_spawn_point(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  if ( result )
  {
    *result = 0i64;
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    if ( set_data_by_name )
    {
      v6 = (UFG::SimObject *)set_data_by_name->set_data_by_name;
      if ( v6 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::SpawnPoint::_TypeUID);
        if ( ComponentOfType )
          *result = SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)ComponentOfType);
      }
    }
  }
}

// File Line: 666
// RVA: 0x4F5210
void __fastcall UFG::TSTransform::Mthd_as_poi(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::SimObject *v6; // rcx
  UFG::InterestPoint *ComponentOfType; // rax

  if ( result )
  {
    *result = 0i64;
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    if ( set_data_by_name )
    {
      v6 = (UFG::SimObject *)set_data_by_name->set_data_by_name;
      if ( v6 )
      {
        ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
        if ( ComponentOfType )
          *result = UFG::TSInterestPoint::AsInstance(ComponentOfType);
      }
    }
  }
}

// File Line: 690
// RVA: 0x4F4FE0
void __fastcall UFG::TSTransform::Mthd_as_combat_region(SSInvokedMethod *scope, SSInstance **result)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rdi
  SSObjectBaseVtbl *set_data_by_name; // rbx
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  if ( result )
  {
    *result = 0i64;
    i_obj_p = scope->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    set_data_by_name = (SSObjectBaseVtbl *)vfptr[1].set_data_by_name;
    if ( !set_data_by_name || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)&vfptr[3], &UFG::qMatrix44::msIdentity) )
      set_data_by_name = vfptr;
    if ( set_data_by_name )
    {
      v6 = (UFG::SimObject *)set_data_by_name->set_data_by_name;
      if ( v6 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::CombatRegion::_TypeUID);
        if ( ComponentOfType )
          *result = SSInstance::pool_new(UFG::TSCombatRegion::mspCombatRegionClass, (unsigned __int64)ComponentOfType);
      }
    }
  }
}

