// File Line: 53
// RVA: 0x4D3020
void UFG::TSEffect::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Effect");
  SSClass::register_method_func(v0, &ASymbolX_ctor, UFG::TSEffect::Mthd_constructor, 0);
  SSClass::register_method_func(v0, &ASymbolX_dtor, UFG::TSEffect::Mthd_destructor, 0);
  SSClass::register_method_func(v0, "is_active", UFG::TSEffect::Mthd_is_active, 0);
  SSClass::register_method_func(v0, "is_looping", UFG::TSEffect::Mthd_is_looping, 0);
  SSClass::register_method_func(v0, "start_at_pos", UFG::TSEffect::Mthd_start_at_pos, 0);
  SSClass::register_method_func(v0, "start_at_actor", UFG::TSEffect::Mthd_start_at_actor, 0);
  SSClass::register_method_func(v0, "start_at_xform", UFG::TSEffect::Mthd_start_at_xform, 0);
  SSClass::register_method_func(v0, "stop", UFG::TSEffect::Mthd_stop, 0);
}

// File Line: 77
// RVA: 0x4F6A80
void __fastcall UFG::TSEffect::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdi
  __int64 v3; // r8
  SSObjectBaseVtbl *v4; // rbx
  SSInstance *v5; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0i64;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2->vfptr;
  v2[2].vfptr = (SSObjectBaseVtbl *)0xFFFFFFFFi64;
  LOBYTE(v3) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) > 0ui64;
  *(_QWORD *)&v2[2].i_ptr_id = v3;
  v5 = SSString::as_instance((AString *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v4->set_data_by_name(v2, (ASymbol *)&qSymbol_i_fx_type, v5);
}

// File Line: 97
// RVA: 0x4F7E80
void __fastcall UFG::TSEffect::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  unsigned int v3; // eax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (unsigned int)v2[2].vfptr;
  if ( v3 != -1 )
    Render::FXManager::KillEffect(&Render::gFXManager, v3, (Render::eFXKillOption)v2[2].i_ptr_id);
}

// File Line: 114
// RVA: 0x500880
void __fastcall UFG::TSEffect::Mthd_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  Render::FXInstance *v4; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = Render::FXManager::FindEffect(&Render::gFXManager, (unsigned int)v2[2].vfptr);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4 != 0i64);
  }
}

// File Line: 130
// RVA: 0x502670
void __fastcall UFG::TSEffect::Mthd_is_looping(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  bool v4; // al

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = Render::FXManager::IsEffectLooping(&Render::gFXManager, (unsigned int)v2[2].vfptr);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 144
// RVA: 0x50BEA0
void __fastcall UFG::TSEffect::Mthd_start_at_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rsi
  SSInvokedMethod *v3; // rbx
  SSData **v4; // rcx
  SSInstance *v5; // rdi
  SSInstance *v6; // rbx
  __int64 v7; // rax
  unsigned int v8; // eax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  Render::FXManager::KillEffect(&Render::gFXManager, (unsigned int)v2[2].vfptr, (Render::eFXKillOption)v2[2].i_ptr_id);
  v4 = v3->i_data.i_array_p;
  v5 = v4[1]->i_data_p;
  v6 = (*v4)->i_data_p;
  v7 = (__int64)v2->vfptr->get_data_by_name(v2, (ASymbol *)&qSymbol_i_fx_type);
  v8 = UFG::qStringHashUpper32(**(const char ***)(v7 + 32), 0xFFFFFFFF);
  v2[2].vfptr = (SSObjectBaseVtbl *)(unsigned int)Render::FXManager::CreateEffect(
                                                    &Render::gFXManager,
                                                    v8,
                                                    (UFG::qVector3 *)v6->i_user_data,
                                                    (UFG::qVector3 *)v5->i_user_data);
}

// File Line: 160
// RVA: 0x50BDC0
void __fastcall UFG::TSEffect::Mthd_start_at_actor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdi
  SSInvokedMethod *v3; // rbx
  SSActor *v4; // rbx
  SSClass *v5; // rsi
  __int64 v6; // rbx
  UFG::TransformNodeComponent *v7; // rbx
  __int64 v8; // rax
  unsigned int v9; // eax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  Render::FXManager::KillEffect(&Render::gFXManager, (unsigned int)v2[2].vfptr, (Render::eFXKillOption)v2[2].i_ptr_id);
  v4 = (SSActor *)(*v3->i_data.i_array_p)->i_data_p;
  if ( v4 )
  {
    v5 = v4->i_class_p;
    if ( !v5->vfptr->is_actor_class((SSClassDescBase *)v4->i_class_p) )
    {
      if ( v5 != SSBrain::c_symbol_class_p || LODWORD(v4->i_user_data) == -1 )
        return;
      v4 = SSActor::find((ASymbol *)&v4->i_user_data);
    }
    if ( v4 )
    {
      v6 = *(_QWORD *)&v4[1].i_icoroutines_to_update.i_count;
      if ( v6 )
      {
        v7 = *(UFG::TransformNodeComponent **)(v6 + 88);
        v8 = (__int64)v2->vfptr->get_data_by_name(v2, (ASymbol *)&qSymbol_i_fx_type);
        v9 = UFG::qStringHashUpper32(**(const char ***)(v8 + 32), 0xFFFFFFFF);
        v2[2].vfptr = (SSObjectBaseVtbl *)(unsigned int)Render::FXManager::CreateEffect(
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
  SSObjectBase *v2; // rbx
  SSInvokedMethod *v3; // rdi
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  SSInstance *v6; // rax
  unsigned int v7; // eax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = pScope;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  Render::FXManager::KillEffect(&Render::gFXManager, (unsigned int)v2[2].vfptr, (Render::eFXKillOption)v2[2].i_ptr_id);
  v4 = (UFG::TransformNodeComponent *)(*v3->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = v4->mParent;
  if ( !v5 || !UFG::qMatrix44::operator==(&v4->mLocalTransform, &UFG::qMatrix44::msIdentity) )
    v5 = v4;
  v6 = v2->vfptr->get_data_by_name(v2, (ASymbol *)&qSymbol_i_fx_type);
  v7 = UFG::qStringHashUpper32(*(const char **)v6->i_user_data, 0xFFFFFFFF);
  v2[2].vfptr = (SSObjectBaseVtbl *)(unsigned int)Render::FXManager::CreateEffect(
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
  SSObjectBase *v2; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  Render::FXManager::KillEffect(&Render::gFXManager, (unsigned int)v2[2].vfptr, (Render::eFXKillOption)v2[2].i_ptr_id);
  v2[2].vfptr = (SSObjectBaseVtbl *)0xFFFFFFFFi64;
}

