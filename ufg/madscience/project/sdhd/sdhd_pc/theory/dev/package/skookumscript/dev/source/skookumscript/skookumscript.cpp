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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SkookumScript::c_world_class_name__);
}

// File Line: 116
// RVA: 0x113F60
void __fastcall SkookumScript::enable_flag(__int32 flag, bool enable_b)
{
  __int32 v2; // eax
  char v3; // r9

  if ( ((SkookumScript::c_flags & flag) != 0) != enable_b )
  {
    v2 = flag;
    if ( !enable_b )
      v2 = -flag;
    v3 = v2 + SkookumScript::c_flags;
    SkookumScript::c_flags += v2;
    if ( flag == 1 && SkookumScript::c_on_update_request_f && (v3 & 2) != 0 )
      SkookumScript::c_on_update_request_f(enable_b);
  }
}

// File Line: 214
// RVA: 0x13EBD0
void __fastcall SkookumScript::update_delta(float sim_delta)
{
  unsigned __int64 v1; // rcx
  double v2; // xmm1_8

  SkookumScript::c_sim_delta = sim_delta;
  v1 = 0i64;
  SkookumScript::c_sim_time = SkookumScript::c_sim_time + sim_delta;
  v2 = SkookumScript::c_sim_time * 1000.0 + 0.5;
  if ( v2 >= 9.223372036854776e18 )
  {
    v2 = v2 - 9.223372036854776e18;
    if ( v2 < 9.223372036854776e18 )
      v1 = 0x8000000000000000ui64;
  }
  SkookumScript::c_sim_ticks += v1 + (unsigned int)(int)v2;
  if ( (SkookumScript::c_flags & 3) == 3 )
    SSActor::update_all();
}

// File Line: 315
// RVA: 0x11BA40
void SkookumScript::initialize_pre_load(void)
{
  ASymbol *null; // rax
  unsigned int i_uid; // ecx

  null = ASymbol::get_null();
  i_uid = SkookumScript::c_world_class_name.i_uid;
  if ( SkookumScript::c_world_class_name.i_uid == null->i_uid )
    i_uid = ASymbol_World.i_uid;
  SkookumScript::c_world_class_name.i_uid = i_uid;
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
  SSClass **i_array_p; // r8
  SSClass **v3; // r10
  SSClass **v4; // rdx
  unsigned int i_uid; // r9d
  SSActorClass *v6; // rax
  SSActor *v7; // rbx
  SSActorClass *v8; // rcx
  SSActorClass *v9; // rdx
  SSClass *i_class_p; // rdi
  SSActor *v11; // rcx
  unsigned int i_ptr_id; // eax

  SSClass::invoke_class_ctor_recurse(SSBrain::c_object_class_p);
  if ( create_world )
  {
    if ( SSBrain::c_classes.i_count )
    {
      i_array_p = SSBrain::c_classes.i_array_p;
      v3 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
      while ( 1 )
      {
        while ( 1 )
        {
          v4 = &i_array_p[((char *)v3 - (char *)i_array_p) >> 4];
          i_uid = (*v4)->i_name.i_uid;
          if ( SkookumScript::c_world_class_name.i_uid >= i_uid )
            break;
          if ( i_array_p == v4 )
            goto LABEL_11;
          v3 = v4 - 1;
        }
        if ( SkookumScript::c_world_class_name.i_uid == i_uid )
          break;
        if ( v3 == v4 )
          goto LABEL_11;
        i_array_p = v4 + 1;
      }
      v6 = (SSActorClass *)*v4;
    }
    else
    {
LABEL_11:
      v6 = 0i64;
    }
    if ( !v6 )
      v6 = SSBrain::c_world_class_p;
    SkookumScript::c_world_class_p = v6;
    v7 = (SSActor *)AMemory::c_malloc_func(0x80ui64, "SSActor");
    if ( v7 )
    {
      v8 = SkookumScript::c_world_class_p;
      v7->i_name = ASymbol_World;
      v9 = SSBrain::c_actor_class_p;
      if ( v8 )
        v9 = v8;
      SSDataInstance::SSDataInstance(v7, v9);
      v7->vfptr = (SSObjectBaseVtbl *)&SSActor::`vftable;
      v7->i_icoroutines_to_update.i_count = 0;
      v7->i_icoroutines_to_update.i_array_p = 0i64;
      v7->i_icoroutines_to_update.i_size = 0;
      v7->i_icoroutines_pending.i_count = 0;
      v7->i_icoroutines_pending.i_array_p = 0i64;
      v7->i_icoroutines_pending.i_size = 0;
      v7->i_actor_flags = 4;
      i_class_p = v7->i_class_p;
      if ( v7->i_name.i_uid != ASymbol::get_null()->i_uid )
      {
        APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
          (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&i_class_p[1],
          v7,
          0i64);
        if ( i_class_p->i_superclass_p->vfptr->is_actor_class(i_class_p->i_superclass_p) )
          SSActorClass::append_instance((SSActorClass *)i_class_p->i_superclass_p, v7);
      }
    }
    else
    {
      v7 = 0i64;
    }
    SkookumScript::c_world_p = v7;
    ++v7->i_ref_count;
    v11 = SkookumScript::c_world_p;
    if ( (SkookumScript::c_world_p->i_actor_flags & 1) == 0 )
    {
      SkookumScript::c_world_p->i_actor_flags ^= 1u;
      i_ptr_id = v11->i_ptr_id;
      if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
      {
        if ( v11->i_icoroutines_to_update.i_count )
          SSActor::enable_on_update(v11, 1);
      }
      v11 = SkookumScript::c_world_p;
    }
    SSInstance::call_default_constructor(v11);
  }
}

// File Line: 431
// RVA: 0x113EC0
void __fastcall SkookumScript::enable_behavior(bool enable_b)
{
  SSActor **i_array_p; // rdi
  SSActor **i; // rbp
  SSActor *v4; // rbx
  unsigned int i_ptr_id; // eax
  bool v6; // dl

  i_array_p = SSBrain::c_actor_class_p->i_instances.i_array_p;
  for ( i = &i_array_p[SSBrain::c_actor_class_p->i_instances.i_count]; i_array_p < i; ++i_array_p )
  {
    v4 = *i_array_p;
    if ( enable_b != ((*i_array_p)->i_actor_flags & 1) )
    {
      v4->i_actor_flags ^= 1u;
      if ( enable_b )
      {
        i_ptr_id = v4->i_ptr_id;
        if ( !i_ptr_id || i_ptr_id > SSObjectBase::c_ptr_id_prev || !v4->i_icoroutines_to_update.i_count )
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
    SkookumScript::c_world_p->vfptr->__vecDelDtor(SkookumScript::c_world_p, 1i64);
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

