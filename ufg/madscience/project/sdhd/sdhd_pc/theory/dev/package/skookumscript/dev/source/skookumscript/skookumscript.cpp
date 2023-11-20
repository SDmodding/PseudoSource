// File Line: 78
// RVA: 0x106790
void __fastcall SkookumVals::SkookumVals(SkookumVals *this)
{
  this->i_using_defaults = 1;
  this->i_pool_init_boolean = 512;
  this->i_pool_incr_boolean = 64;
  this->i_pool_init_data = 4000;
  this->i_pool_incr_data = 256;
  this->i_pool_init_data_instance = 16;
  this->i_pool_incr_data_instance = 16;
  this->i_pool_init_instance = 3000;
  this->i_pool_incr_instance = 256;
  this->i_pool_init_iexpr = 1152;
  this->i_pool_incr_iexpr = 128;
  this->i_pool_init_imethod = 16;
  this->i_pool_incr_imethod = 16;
  this->i_pool_init_icoroutine = 896;
  this->i_pool_incr_icoroutine = 128;
}

// File Line: 86
// RVA: 0x1461610
__int64 dynamic_initializer_for__SkookumScript::c_world_class_name__()
{
  return atexit(dynamic_atexit_destructor_for__SkookumScript::c_world_class_name__);
}

// File Line: 116
// RVA: 0x113F60
void __fastcall SkookumScript::enable_flag(SkookumScript::eFlag flag, bool enable_b)
{
  SkookumScript::eFlag v2; // eax
  char v3; // r9

  if ( ((SkookumScript::c_flags & flag) != 0) != enable_b )
  {
    v2 = flag;
    if ( !enable_b )
      v2 = -(signed int)flag;
    v3 = v2 + SkookumScript::c_flags;
    SkookumScript::c_flags += v2;
    if ( flag == 1 && SkookumScript::c_on_update_request_f )
    {
      if ( v3 & 2 )
        SkookumScript::c_on_update_request_f(enable_b);
    }
  }
}

// File Line: 214
// RVA: 0x13EBD0
void __fastcall SkookumScript::update_delta(float sim_delta)
{
  signed __int64 v1; // rcx
  long double v2; // xmm1_8
  double v3; // xmm1_8

  SkookumScript::c_sim_delta = sim_delta;
  v1 = 0i64;
  v2 = SkookumScript::c_sim_time + sim_delta;
  SkookumScript::c_sim_time = v2;
  v3 = v2 * 1000.0 + 0.5;
  if ( v3 >= 9.223372036854776e18 )
  {
    v3 = v3 - 9.223372036854776e18;
    if ( v3 < 9.223372036854776e18 )
      v1 = 0x8000000000000000i64;
  }
  SkookumScript::c_sim_ticks += v1 + (unsigned int)(signed int)v3;
  JUMPOUT(SkookumScript::c_flags & 3, 3, SSActor::update_all);
}

// File Line: 315
// RVA: 0x11BA40
void SkookumScript::initialize_pre_load(void)
{
  ASymbol *v0; // rax
  unsigned int v1; // ecx

  v0 = ASymbol::get_null();
  v1 = SkookumScript::c_world_class_name.i_uid;
  if ( SkookumScript::c_world_class_name.i_uid == v0->i_uid )
    v1 = ASymbol_World.i_uid;
  SkookumScript::c_world_class_name.i_uid = v1;
  SSInstance::get_pool();
  SSData::get_pool();
  SSInvokedMethod::get_pool();
  SSInvokedExpression::get_pool();
  SSBoolean::get_pool();
  SSInvokedCoroutine::get_pool();
  SSParser::initialize_pre_load();
}

// File Line: 354
// RVA: 0x11A3D0
void SkookumScript::initialize_post_load(void)
{
  SSBrain::initialize_post_load();
  SkookumScript::c_sim_ticks = 0i64;
  SkookumScript::c_sim_time = 0.0;
  SkookumScript::c_sim_delta = 0.0;
}

// File Line: 379
// RVA: 0x11BA90
void __fastcall SkookumScript::initialize_session(bool create_world)
{
  bool v1; // bl
  SSClass **v2; // r8
  SSClass **v3; // r10
  signed __int64 v4; // rdx
  unsigned int v5; // er9
  _BOOL8 v6; // rcx
  _BOOL8 v7; // r9
  SSActorClass *v8; // rax
  SSActor *v9; // rbx
  SSActorClass *v10; // rcx
  SSActorClass *v11; // rdx
  SSClass *v12; // rdi
  SSActor *v13; // rcx
  unsigned int v14; // eax

  v1 = create_world;
  SSClass::invoke_class_ctor_recurse(SSBrain::c_object_class_p);
  if ( v1 )
  {
    if ( SSBrain::c_classes.i_count )
    {
      v2 = SSBrain::c_classes.i_array_p;
      v3 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
      while ( 1 )
      {
        v4 = (signed __int64)&v2[((char *)v3 - (char *)v2) >> 4];
        v5 = *(_DWORD *)(*(_QWORD *)v4 + 8i64);
        if ( SkookumScript::c_world_class_name.i_uid < v5 )
          goto LABEL_32;
        v6 = SkookumScript::c_world_class_name.i_uid == v5;
        v7 = SkookumScript::c_world_class_name.i_uid != v5;
        if ( v6 == 1 )
        {
          v8 = *(SSActorClass **)v4;
          goto LABEL_13;
        }
        if ( v7 < 0 )
        {
LABEL_32:
          if ( v2 == (SSClass **)v4 )
            break;
          v3 = (SSClass **)(v4 - 8);
        }
        else
        {
          if ( v3 == (SSClass **)v4 )
            break;
          v2 = (SSClass **)(v4 + 8);
        }
      }
    }
    v8 = 0i64;
LABEL_13:
    if ( !v8 )
      v8 = SSBrain::c_world_class_p;
    SkookumScript::c_world_class_p = v8;
    v9 = (SSActor *)AMemory::c_malloc_func(0x80ui64, "SSActor");
    if ( v9 )
    {
      v10 = SkookumScript::c_world_class_p;
      v9->i_name = ASymbol_World;
      v11 = SSBrain::c_actor_class_p;
      if ( v10 )
        v11 = v10;
      SSDataInstance::SSDataInstance((SSDataInstance *)&v9->vfptr, (SSClass *)&v11->vfptr);
      v9->vfptr = (SSObjectBaseVtbl *)&SSActor::`vftable';
      v9->i_icoroutines_to_update.i_count = 0;
      v9->i_icoroutines_to_update.i_array_p = 0i64;
      v9->i_icoroutines_to_update.i_size = 0;
      v9->i_icoroutines_pending.i_count = 0;
      v9->i_icoroutines_pending.i_array_p = 0i64;
      v9->i_icoroutines_pending.i_size = 0;
      v9->i_actor_flags = 4;
      v12 = v9->i_class_p;
      if ( v9->i_name.i_uid != ASymbol::get_null()->i_uid )
      {
        APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
          (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&v12[1],
          v9,
          0i64);
        if ( ((unsigned __int8 (__cdecl *)(SSClass *))v12->i_superclass_p->vfptr->is_actor_class)(v12->i_superclass_p) )
          SSActorClass::append_instance((SSActorClass *)v12->i_superclass_p, v9);
      }
    }
    else
    {
      v9 = 0i64;
    }
    SkookumScript::c_world_p = v9;
    ++v9->i_ref_count;
    v13 = SkookumScript::c_world_p;
    if ( !(SkookumScript::c_world_p->i_actor_flags & 1) )
    {
      SkookumScript::c_world_p->i_actor_flags ^= 1u;
      v14 = v13->i_ptr_id;
      if ( v14 && v14 <= SSObjectBase::c_ptr_id_prev )
      {
        if ( v13->i_icoroutines_to_update.i_count )
          SSActor::enable_on_update(v13, 1);
      }
      v13 = SkookumScript::c_world_p;
    }
    SSInstance::call_default_constructor((SSInstance *)&v13->vfptr);
  }
}

// File Line: 431
// RVA: 0x113EC0
void __fastcall SkookumScript::enable_behavior(bool enable_b)
{
  bool v1; // si
  SSActor **v2; // rdi
  unsigned __int64 i; // rbp
  SSActor *v4; // rbx
  unsigned int v5; // eax
  bool v6; // dl

  v1 = enable_b;
  v2 = SSBrain::c_actor_class_p->i_instances.i_array_p;
  for ( i = (unsigned __int64)&v2[SSBrain::c_actor_class_p->i_instances.i_count]; (unsigned __int64)v2 < i; ++v2 )
  {
    v4 = *v2;
    if ( v1 != ((*v2)->i_actor_flags & 1) )
    {
      v4->i_actor_flags ^= 1u;
      if ( v1 )
      {
        v5 = v4->i_ptr_id;
        if ( !v5 || v5 > SSObjectBase::c_ptr_id_prev || !v4->i_icoroutines_to_update.i_count )
          continue;
        v6 = 1;
      }
      else
      {
        SSActor::clear_coroutines(v4);
        v6 = 0;
      }
      SSActor::enable_on_update(v4, v6);
    }
  }
}

// File Line: 457
// RVA: 0x1139F0
void SkookumScript::deinitialize_session(void)
{
  SSClass::recurse_class_dtor(SSBrain::c_object_class_p);
  if ( SkookumScript::c_world_p )
  {
    SkookumScript::c_world_p->vfptr->__vecDelDtor((SSObjectBase *)SkookumScript::c_world_p, 1u);
    SkookumScript::c_world_p = 0i64;
  }
}

// File Line: 487
// RVA: 0x1139E0
void SkookumScript::deinitialize(void)
{
  SkookumScript::c_world_class_p = 0i64;
  SSBrain::deinitialize();
}

