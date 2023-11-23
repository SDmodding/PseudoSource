// File Line: 53
// RVA: 0x4D3020
void UFG::TSEffect::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Effect");
  SSClass::register_method_func(v0, &ASymbolX_ctor, UFG::TSEffect::Mthd_constructor, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, &ASymbolX_dtor, UFG::TSEffect::Mthd_destructor, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "is_active", UFG::TSEffect::Mthd_is_active, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "is_looping", UFG::TSEffect::Mthd_is_looping, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "start_at_pos", UFG::TSEffect::Mthd_start_at_pos, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "start_at_actor", UFG::TSEffect::Mthd_start_at_actor, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "start_at_xform", UFG::TSEffect::Mthd_start_at_xform, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "stop", UFG::TSEffect::Mthd_stop, SSBindFlag_instance_no_rebind);
}

// File Line: 77
// RVA: 0x4F6A80
void __fastcall UFG::TSEffect::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdi
  __int64 v3; // r8
  SSObjectBaseVtbl *vfptr; // rbx
  SSInstance *v5; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p->vfptr;
  i_obj_p[2].vfptr = (SSObjectBaseVtbl *)0xFFFFFFFFi64;
  LOBYTE(v3) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64;
  *(_QWORD *)&i_obj_p[2].i_ptr_id = v3;
  v5 = SSString::as_instance((AString *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  vfptr->set_data_by_name(i_obj_p, (ASymbol *)&qSymbol_i_fx_type, v5);
}

// File Line: 97
// RVA: 0x4F7E80
void __fastcall UFG::TSEffect::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int vfptr; // eax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (unsigned int)i_obj_p[2].vfptr;
  if ( vfptr != -1 )
    Render::FXManager::KillEffect(&Render::gFXManager, vfptr, (Render::eFXKillOption)i_obj_p[2].i_ptr_id);
}

// File Line: 114
// RVA: 0x500880
void __fastcall UFG::TSEffect::Mthd_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::qBaseTreeRB *Effect; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    Effect = Render::FXManager::FindEffect(&Render::gFXManager, (unsigned int)i_obj_p[2].vfptr);
    *ppResult = SSBoolean::pool_new(Effect != 0i64);
  }
}

// File Line: 130
// RVA: 0x502670
void __fastcall UFG::TSEffect::Mthd_is_looping(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  bool IsEffectLooping; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    IsEffectLooping = Render::FXManager::IsEffectLooping(&Render::gFXManager, (unsigned int)i_obj_p[2].vfptr);
    *ppResult = SSBoolean::pool_new(IsEffectLooping);
  }
}

// File Line: 144
// RVA: 0x50BEA0
void __fastcall UFG::TSEffect::Mthd_start_at_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rsi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdi
  SSInstance *v6; // rbx
  __int64 v7; // rax
  unsigned int v8; // eax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  Render::FXManager::KillEffect(
    &Render::gFXManager,
    (unsigned int)i_obj_p[2].vfptr,
    (Render::eFXKillOption)i_obj_p[2].i_ptr_id);
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  v6 = (*i_array_p)->i_data_p;
  v7 = (__int64)i_obj_p->vfptr->get_data_by_name(i_obj_p, (ASymbol *)&qSymbol_i_fx_type);
  v8 = UFG::qStringHashUpper32(**(const char ***)(v7 + 32), -1);
  i_obj_p[2].vfptr = (SSObjectBaseVtbl *)(unsigned int)Render::FXManager::CreateEffect(
                                                         &Render::gFXManager,
                                                         v8,
                                                         (UFG::qVector3 *)v6->i_user_data,
                                                         (UFG::qVector3 *)i_data_p->i_user_data);
}

// File Line: 160
// RVA: 0x50BDC0
void __fastcall UFG::TSEffect::Mthd_start_at_actor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rsi
  __int64 v6; // rbx
  UFG::TransformNodeComponent *v7; // rbx
  __int64 v8; // rax
  unsigned int v9; // eax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  Render::FXManager::KillEffect(
    &Render::gFXManager,
    (unsigned int)i_obj_p[2].vfptr,
    (Render::eFXKillOption)i_obj_p[2].i_ptr_id);
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
    {
      if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
        return;
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
    }
    if ( i_data_p )
    {
      v6 = *(_QWORD *)&i_data_p[1].i_icoroutines_to_update.i_count;
      if ( v6 )
      {
        v7 = *(UFG::TransformNodeComponent **)(v6 + 88);
        v8 = (__int64)i_obj_p->vfptr->get_data_by_name(i_obj_p, (ASymbol *)&qSymbol_i_fx_type);
        v9 = UFG::qStringHashUpper32(**(const char ***)(v8 + 32), -1);
        i_obj_p[2].vfptr = (SSObjectBaseVtbl *)(unsigned int)Render::FXManager::CreateEffect(
                                                               &Render::gFXManager,
                                                               v9,
                                                               v7,
                                                               0xFFFFFFFF,
                                                               0i64);
      }
    }
  }
}

// File Line: 187
// RVA: 0x50BF50
void __fastcall UFG::TSEffect::Mthd_start_at_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  unsigned __int64 i_user_data; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  SSInstance *v6; // rax
  unsigned int v7; // eax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  Render::FXManager::KillEffect(
    &Render::gFXManager,
    (unsigned int)i_obj_p[2].vfptr,
    (Render::eFXKillOption)i_obj_p[2].i_ptr_id);
  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = *(UFG::TransformNodeComponent **)(i_user_data + 104);
  if ( !v5 || !UFG::qMatrix44::operator==((UFG::qMatrix44 *)(i_user_data + 192), &UFG::qMatrix44::msIdentity) )
    v5 = (UFG::TransformNodeComponent *)i_user_data;
  v6 = i_obj_p->vfptr->get_data_by_name(i_obj_p, (ASymbol *)&qSymbol_i_fx_type);
  v7 = UFG::qStringHashUpper32(*(const char **)v6->i_user_data, -1);
  i_obj_p[2].vfptr = (SSObjectBaseVtbl *)(unsigned int)Render::FXManager::CreateEffect(
                                                         &Render::gFXManager,
                                                         v7,
                                                         v5,
                                                         0xFFFFFFFF,
                                                         0i64);
}

// File Line: 206
// RVA: 0x50C110
void __fastcall UFG::TSEffect::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  Render::FXManager::KillEffect(
    &Render::gFXManager,
    (unsigned int)i_obj_p[2].vfptr,
    (Render::eFXKillOption)i_obj_p[2].i_ptr_id);
  i_obj_p[2].vfptr = (SSObjectBaseVtbl *)0xFFFFFFFFi64;
}

