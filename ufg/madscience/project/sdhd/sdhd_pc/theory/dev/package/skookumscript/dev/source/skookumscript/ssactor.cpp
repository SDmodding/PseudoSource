// File Line: 47
// RVA: 0x14615D0
__int64 dynamic_initializer_for__SSActor::c_update_actors__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSActor::c_update_actors__);
}

// File Line: 50
// RVA: 0x14615F0
__int64 dynamic_initializer_for__SSActor::c_updating_actors__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSActor::c_updating_actors__);
}

// File Line: 53
// RVA: 0x14614D0
__int64 dynamic_initializer_for__SSActor::c_icoroutines_updating__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSActor::c_icoroutines_updating__);
}

// File Line: 74
// RVA: 0x104140
void __fastcall SSActor::SSActor(SSActor *this, ASymbol *name, SSActorClass *class_p, bool add_to_instance_list)
{
  SSActorClass *v6; // rdx
  SSClass *i_class_p; // rbx

  this->i_name = (ASymbol)name->i_uid;
  v6 = SSBrain::c_actor_class_p;
  if ( class_p )
    v6 = class_p;
  SSDataInstance::SSDataInstance(this, v6);
  this->vfptr = (SSObjectBaseVtbl *)&SSActor::`vftable;
  this->i_icoroutines_to_update.i_count = 0;
  this->i_icoroutines_to_update.i_array_p = 0i64;
  this->i_icoroutines_to_update.i_size = 0;
  this->i_icoroutines_pending.i_count = 0;
  this->i_icoroutines_pending.i_array_p = 0i64;
  this->i_icoroutines_pending.i_size = 0;
  this->i_actor_flags = 4;
  if ( add_to_instance_list )
  {
    i_class_p = this->i_class_p;
    if ( this->i_name.i_uid != ASymbol::get_null()->i_uid )
    {
      APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
        (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&i_class_p[1],
        this,
        0i64);
      if ( i_class_p->i_superclass_p->vfptr->is_actor_class(i_class_p->i_superclass_p) )
        SSActorClass::append_instance((SSActorClass *)i_class_p->i_superclass_p, this);
    }
  }
}

// File Line: 90
// RVA: 0x106AB0
void __fastcall SSActor::~SSActor(SSActor *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSActor::`vftable;
  if ( (this->i_actor_flags & 1) != 0 )
  {
    this->i_actor_flags ^= 1u;
    SSActor::clear_coroutines(this);
    SSActor::enable_on_update(this, 0);
  }
  SSActorClass::remove_instance((SSActorClass *)this->i_class_p, this);
  AMemory::c_free_func(this->i_icoroutines_pending.i_array_p);
  AMemory::c_free_func(this->i_icoroutines_to_update.i_array_p);
  SSDataInstance::~SSDataInstance(this);
}

// File Line: 112
// RVA: 0x113E60
void __fastcall SSActor::enable_behavior(SSActor *this, bool activate)
{
  unsigned int i_ptr_id; // eax

  if ( activate != (this->i_actor_flags & 1) )
  {
    this->i_actor_flags ^= 1u;
    if ( activate )
    {
      i_ptr_id = this->i_ptr_id;
      if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
      {
        if ( this->i_icoroutines_to_update.i_count )
          SSActor::enable_on_update(this, 1);
      }
    }
    else
    {
      SSActor::clear_coroutines(this);
      SSActor::enable_on_update(this, 0);
    }
  }
}

// File Line: 174
// RVA: 0x113FB0
void __fastcall SSActor::enable_on_update(SSActor *this, bool activate)
{
  unsigned int i_actor_flags; // ecx
  int v4; // ecx
  unsigned int i_ptr_id; // eax
  char v6; // al
  char v7; // al
  unsigned int find_pos_p; // [rsp+48h] [rbp+10h] BYREF

  i_actor_flags = this->i_actor_flags;
  if ( activate != ((i_actor_flags & 2) != 0) )
  {
    v4 = i_actor_flags ^ 2;
    this->i_actor_flags = v4;
    if ( activate )
    {
      if ( (v4 & 1) != 0 )
      {
        i_ptr_id = this->i_ptr_id;
        if ( i_ptr_id )
        {
          if ( i_ptr_id <= SSObjectBase::c_ptr_id_prev )
          {
            APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(&SSActor::c_update_actors, this, 0i64);
            if ( SSActor::c_update_actors.i_count == 1 )
            {
              v6 = SkookumScript::c_flags | 2;
              SkookumScript::c_flags |= 2u;
              if ( SkookumScript::c_update_time_f )
              {
                SkookumScript::c_update_time_f();
                v6 = SkookumScript::c_flags;
              }
              if ( SkookumScript::c_on_update_request_f )
              {
                if ( (v6 & 1) != 0 )
                  SkookumScript::c_on_update_request_f(1);
              }
            }
          }
        }
      }
    }
    else
    {
      if ( APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::find_elem(
             &SSActor::c_update_actors,
             this,
             &find_pos_p,
             0,
             0xFFFFFFFF) )
      {
        memmove(
          &SSActor::c_update_actors.i_array_p[find_pos_p],
          &SSActor::c_update_actors.i_array_p[find_pos_p + 1],
          8i64 * (--SSActor::c_update_actors.i_count - find_pos_p));
      }
      if ( APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::find_elem(
             &SSActor::c_updating_actors,
             this,
             &find_pos_p,
             0,
             0xFFFFFFFF) )
      {
        memmove(
          &SSActor::c_updating_actors.i_array_p[find_pos_p],
          &SSActor::c_updating_actors.i_array_p[find_pos_p + 1],
          8i64 * (--SSActor::c_updating_actors.i_count - find_pos_p));
      }
      if ( !SSActor::c_update_actors.i_count )
      {
        v7 = SkookumScript::c_flags & 0xFD;
        SkookumScript::c_flags &= ~2u;
        if ( SkookumScript::c_update_time_f )
        {
          SkookumScript::c_update_time_f();
          v7 = SkookumScript::c_flags;
        }
        if ( SkookumScript::c_on_update_request_f && (v7 & 1) != 0 )
          SkookumScript::c_on_update_request_f(0);
      }
    }
  }
}

// File Line: 225
// RVA: 0x13BED0
void __fastcall SSActor::rename(SSActor *this, ASymbol *name)
{
  SSClass *i_class_p; // rbp
  char v5; // bl
  unsigned int i_actor_flags; // eax
  unsigned int i_uid; // r10d
  __int64 v8; // rbx
  SSActor **v9; // r9
  SSActor **i; // rcx
  SSActor **v11; // rdx
  unsigned int v12; // r8d
  unsigned int v13; // r10d
  __int64 v14; // rsi
  SSActor **v15; // r9
  SSActor **j; // rcx
  SSActor **v17; // rdx
  unsigned int v18; // r8d
  unsigned int v19; // eax
  unsigned int v20; // r10d
  __int64 v21; // r11
  SSActor **v22; // r9
  SSActor **k; // rcx
  SSActor **v24; // rdx
  unsigned int v25; // r8d

  i_class_p = this->i_class_p;
  v5 = 0;
  SSActorClass::remove_instance((SSActorClass *)i_class_p, this);
  i_actor_flags = this->i_actor_flags;
  if ( (i_actor_flags & 1) != 0 && (i_actor_flags & 2) != 0 )
  {
    if ( SSActor::c_update_actors.i_count )
    {
      i_uid = this->i_name.i_uid;
      v8 = SSActor::c_update_actors.i_count - 1;
      v9 = &SSActor::c_update_actors.i_array_p[v8];
      for ( i = SSActor::c_update_actors.i_array_p; ; i = v11 + 1 )
      {
        while ( 1 )
        {
          v11 = &i[((char *)v9 - (char *)i) >> 4];
          v12 = (*v11)->i_name.i_uid;
          if ( i_uid >= v12 )
            break;
          if ( i == v11 )
            goto LABEL_12;
          v9 = v11 - 1;
        }
        if ( i_uid == v12 )
          break;
        if ( v9 == v11 )
          goto LABEL_12;
      }
      --SSActor::c_update_actors.i_count;
      memmove(
        &SSActor::c_update_actors.i_array_p[(unsigned int)(v11 - SSActor::c_update_actors.i_array_p)],
        &SSActor::c_update_actors.i_array_p[(unsigned int)(v11 - SSActor::c_update_actors.i_array_p) + 1],
        8i64 * ((unsigned int)v8 - (unsigned int)(v11 - SSActor::c_update_actors.i_array_p)));
    }
LABEL_12:
    if ( SSActor::c_updating_actors.i_count )
    {
      v13 = this->i_name.i_uid;
      v14 = SSActor::c_updating_actors.i_count - 1;
      v15 = &SSActor::c_updating_actors.i_array_p[v14];
      for ( j = SSActor::c_updating_actors.i_array_p; ; j = v17 + 1 )
      {
        while ( 1 )
        {
          v17 = &j[((char *)v15 - (char *)j) >> 4];
          v18 = (*v17)->i_name.i_uid;
          if ( v13 >= v18 )
            break;
          if ( j == v17 )
            goto LABEL_21;
          v15 = v17 - 1;
        }
        if ( v13 == v18 )
          break;
        if ( v15 == v17 )
          goto LABEL_21;
      }
      --SSActor::c_updating_actors.i_count;
      v5 = 1;
      memmove(
        &SSActor::c_updating_actors.i_array_p[(unsigned int)(v17 - SSActor::c_updating_actors.i_array_p)],
        &SSActor::c_updating_actors.i_array_p[(unsigned int)(v17 - SSActor::c_updating_actors.i_array_p) + 1],
        8i64 * ((unsigned int)v14 - (unsigned int)(v17 - SSActor::c_updating_actors.i_array_p)));
    }
    else
    {
LABEL_21:
      v5 = 0;
    }
  }
  this->i_name = (ASymbol)name->i_uid;
  if ( this->i_name.i_uid != ASymbol::get_null()->i_uid )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&i_class_p[1],
      this,
      0i64);
    if ( i_class_p->i_superclass_p->vfptr->is_actor_class(i_class_p->i_superclass_p) )
      SSActorClass::append_instance((SSActorClass *)i_class_p->i_superclass_p, this);
  }
  v19 = this->i_actor_flags;
  if ( (v19 & 1) != 0 && (v19 & 2) != 0 )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(&SSActor::c_update_actors, this, 0i64);
    if ( v5 )
    {
      if ( SSActor::c_updating_actors.i_count )
      {
        v20 = this->i_name.i_uid;
        v21 = SSActor::c_updating_actors.i_count - 1;
        v22 = &SSActor::c_updating_actors.i_array_p[v21];
        for ( k = SSActor::c_updating_actors.i_array_p; ; k = v24 + 1 )
        {
          while ( 1 )
          {
            v24 = &k[((char *)v22 - (char *)k) >> 4];
            v25 = (*v24)->i_name.i_uid;
            if ( v20 >= v25 )
              break;
            if ( k == v24 )
              return;
            v22 = v24 - 1;
          }
          if ( v20 == v25 )
            break;
          if ( v22 == v24 )
            return;
        }
        --SSActor::c_updating_actors.i_count;
        memmove(
          &SSActor::c_updating_actors.i_array_p[(unsigned int)(v24 - SSActor::c_updating_actors.i_array_p)],
          &SSActor::c_updating_actors.i_array_p[(unsigned int)(v24 - SSActor::c_updating_actors.i_array_p) + 1],
          8i64 * ((unsigned int)v21 - (unsigned int)(v24 - SSActor::c_updating_actors.i_array_p)));
      }
    }
  }
}

// File Line: 308
// RVA: 0x130600
void __fastcall SSActor::pool_delete(SSActor *this)
{
  this->i_ptr_id = 0;
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 321
// RVA: 0x10F2A0
AString *__fastcall SSActor::as_string(SSActor *this, AString *result)
{
  __int64 v4; // rbx
  AStringRef *i_str_ref_p; // rdx
  unsigned int i_length; // esi
  unsigned int v7; // ebx
  AStringRef *v8; // rdx
  unsigned int v9; // ebx
  unsigned int v10; // esi
  __int64 v11; // rbx
  AStringRef *v12; // rbx
  bool v13; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *v19; // rbx
  AObjReusePool<AStringRef> *v20; // rax
  AObjBlock<AStringRef> *v21; // rcx
  unsigned __int64 v22; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AString v25; // [rsp+60h] [rbp+8h] BYREF
  AString *v26; // [rsp+68h] [rbp+10h]
  AString resulta; // [rsp+70h] [rbp+18h] BYREF

  v26 = result;
  ANamed::get_name_str_dbg(&this->i_class_p->ANamed, &resulta);
  ASymbol::as_str_dbg(&this->i_name, &v25);
  AString::AString(result, 0i64, resulta.i_str_ref_p->i_length + 6 + v25.i_str_ref_p->i_length, 0, 0);
  v4 = result->i_str_ref_p->i_length + 1;
  if ( (unsigned int)v4 >= result->i_str_ref_p->i_size
    || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
  {
    AString::set_size(result, v4);
  }
  result->i_str_ref_p->i_cstr_p[(unsigned int)(v4 - 1)] = 39;
  result->i_str_ref_p->i_cstr_p[v4] = 0;
  result->i_str_ref_p->i_length = v4;
  i_str_ref_p = v25.i_str_ref_p;
  i_length = v25.i_str_ref_p->i_length;
  if ( i_length )
  {
    v7 = i_length + result->i_str_ref_p->i_length;
    if ( v7 >= result->i_str_ref_p->i_size || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(result, v7);
      i_str_ref_p = v25.i_str_ref_p;
    }
    memmove(&result->i_str_ref_p->i_cstr_p[result->i_str_ref_p->i_length], i_str_ref_p->i_cstr_p, i_length + 1);
    result->i_str_ref_p->i_length = v7;
  }
  AString::append(result, " <", 3u);
  v8 = resulta.i_str_ref_p;
  v9 = resulta.i_str_ref_p->i_length;
  if ( v9 )
  {
    v10 = v9 + result->i_str_ref_p->i_length;
    if ( v10 >= result->i_str_ref_p->i_size || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(result, v10);
      v8 = resulta.i_str_ref_p;
    }
    memmove(&result->i_str_ref_p->i_cstr_p[result->i_str_ref_p->i_length], v8->i_cstr_p, v9 + 1);
    result->i_str_ref_p->i_length = v10;
  }
  v11 = result->i_str_ref_p->i_length + 1;
  if ( (unsigned int)v11 >= result->i_str_ref_p->i_size
    || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
  {
    AString::set_size(result, v11);
  }
  result->i_str_ref_p->i_cstr_p[(unsigned int)(v11 - 1)] = 62;
  result->i_str_ref_p->i_cstr_p[v11] = 0;
  result->i_str_ref_p->i_length = v11;
  v12 = v25.i_str_ref_p;
  v13 = v25.i_str_ref_p->i_ref_count-- == 1;
  if ( v13 )
  {
    if ( v12->i_deallocate )
      AMemory::c_free_func(v12->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)v12 < i_objects_a
      || (v17 = (unsigned __int64)v12 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v17) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v12);
  }
  v19 = resulta.i_str_ref_p;
  v13 = resulta.i_str_ref_p->i_ref_count-- == 1;
  if ( v13 )
  {
    if ( v19->i_deallocate )
      AMemory::c_free_func(v19->i_cstr_p);
    v20 = AStringRef::get_pool();
    v21 = v20->i_block_p;
    v22 = (unsigned __int64)v21->i_objects_a;
    if ( (unsigned __int64)v19 < v22
      || (v17 = (unsigned __int64)v19 < v22 + 24i64 * v21->i_size, p_i_pool = &v20->i_pool, !v17) )
    {
      p_i_pool = &v20->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v19);
  }
  return result;
}APArray<AStringRef,AStringRef,ACompareAddress<AS

// File Line: 341
// RVA: 0x121F50
void __fastcall SSActor::mthd_ctor_named(SSInvokedMethod *scope_p, SSActor **result_pp)
{
  SSActor *i_obj_p; // rbx
  SSClass *i_class_p; // rsi
  unsigned int i_ptr_id; // eax

  i_obj_p = (SSActor *)scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_obj_p->i_name.i_uid = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  i_class_p = i_obj_p->i_class_p;
  if ( i_obj_p->i_name.i_uid != ASymbol::get_null()->i_uid )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&i_class_p[1],
      i_obj_p,
      0i64);
    if ( i_class_p->i_superclass_p->vfptr->is_actor_class(i_class_p->i_superclass_p) )
      SSActorClass::append_instance((SSActorClass *)i_class_p->i_superclass_p, i_obj_p);
  }
  if ( (i_obj_p->i_actor_flags & 1) == 0 )
  {
    i_ptr_id = i_obj_p->i_ptr_id;
    i_obj_p->i_actor_flags ^= 1u;
    if ( i_ptr_id )
    {
      if ( i_ptr_id <= SSObjectBase::c_ptr_id_prev && i_obj_p->i_icoroutines_to_update.i_count )
        SSActor::enable_on_update(i_obj_p, 1);
    }
  }
  if ( result_pp )
  {
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
}

// File Line: 371
// RVA: 0x1266D0
void __fastcall SSActor::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p == (*scope_p->i_data.i_array_p)->i_data_p);
  }
}

// File Line: 394
// RVA: 0x126710
void __fastcall SSInstance::mthdc_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p != (*scope_p->i_data.i_array_p)->i_data_p);
  }
}

// File Line: 416
// RVA: 0x122860
void __fastcall SSActor::mthd_get_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rbx
  SSInstance *v4; // rax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    if ( v4 != (SSInstance *)-32i64 )
      LODWORD(v4->i_user_data) = i_obj_p[4].i_ptr_id;
    *result_pp = v4;
  }
}

// File Line: 438
// RVA: 0x122A50
void __fastcall SSActor::mthd_get_strategy_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ASymbol *null; // rdi
  SSInstance *v4; // rax

  if ( result_pp )
  {
    null = ASymbol::get_null();
    v4 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    if ( v4 != (SSInstance *)-32i64 )
      LODWORD(v4->i_user_data) = (ASymbol)null->i_uid;
    *result_pp = v4;
  }
}

// File Line: 484
// RVA: 0x125870
void __fastcall SSActor::mthd_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSActor *i_obj_p; // rcx
  AString *v5; // rdi
  SSInstance *v6; // rax
  AStringRef *i_str_ref_p; // rcx
  AStringRef *v8; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v13; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v16; // [rsp+50h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    i_obj_p = (SSActor *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v5 = SSActor::as_string(i_obj_p, &result);
    v6 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v16 = v6;
    p_i_user_data = &v6->i_user_data;
    if ( v6 != (SSInstance *)-32i64 )
    {
      i_str_ref_p = v5->i_str_ref_p;
      v6->i_user_data = (unsigned __int64)v5->i_str_ref_p;
      ++i_str_ref_p->i_ref_count;
    }
    *result_pp = v6;
    v8 = result.i_str_ref_p;
    if ( result.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( v8->i_deallocate )
        AMemory::c_free_func(v8->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v8 < i_objects_a
        || (v13 = (unsigned __int64)v8 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v13) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v8);
    }
  }
}

// File Line: 503
// RVA: 0x126130
void __fastcall SSActor::mthdc_find_named(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSActor *v3; // rax
  SSInstance *v4; // rcx

  if ( result_pp )
  {
    v3 = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
           &SSBrain::c_actor_class_p->i_instances,
           (ASymbol *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = SSBrain::c_nil_p;
    if ( v3 )
      v4 = v3;
    *result_pp = v4;
    ++v4->i_ref_count;
  }
}

// File Line: 520
// RVA: 0x1260C0
void __fastcall SSActor::mthdc_find_instance(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v4; // rax
  unsigned __int64 *p_i_user_data2; // r8
  SSActor *v6; // rax
  SSInstance *v7; // rcx

  if ( result_pp )
  {
    v4 = scope_p->vfptr->get_topmost_scope(scope_p);
    if ( v4 )
      p_i_user_data2 = &v4[-1].i_user_data2;
    else
      p_i_user_data2 = 0i64;
    v6 = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(p_i_user_data2[7] + 304),
           (ASymbol *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    v7 = SSBrain::c_nil_p;
    if ( v6 )
      v7 = v6;
    *result_pp = v7;
    ++v7->i_ref_count;
  }
}

// File Line: 539
// RVA: 0x126180
void __fastcall SSActor::mthdc_generate_name_str(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  AString *v3; // rdi
  SSInstance *v4; // rax
  AStringRef *i_str_ref_p; // rcx
  AStringRef *v6; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v11; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v14; // [rsp+50h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v3 = SSActor::generate_unique_name_str(
           &result,
           (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
           0i64);
    v4 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v14 = v4;
    p_i_user_data = &v4->i_user_data;
    if ( v4 != (SSInstance *)-32i64 )
    {
      i_str_ref_p = v3->i_str_ref_p;
      v4->i_user_data = (unsigned __int64)v3->i_str_ref_p;
      ++i_str_ref_p->i_ref_count;
    }
    *result_pp = v4;
    v6 = result.i_str_ref_p;
    if ( result.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( v6->i_deallocate )
        AMemory::c_free_func(v6->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v6 < i_objects_a
        || (v11 = (unsigned __int64)v6 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v11) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v6);
    }
  }
}

// File Line: 554
// RVA: 0x126250
void __fastcall SSActor::mthdc_generate_name_sym(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ASymbol *v3; // rdi
  SSInstance *v4; // rax
  ASymbol result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v6; // [rsp+50h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v3 = SSActor::generate_unique_name_sym(
           &result,
           (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
           0i64);
    v4 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    v6 = v4;
    p_i_user_data = &v4->i_user_data;
    if ( v4 != (SSInstance *)-32i64 )
      LODWORD(v4->i_user_data) = (ASymbol)v3->i_uid;
    *result_pp = v4;
  }
}

// File Line: 569
// RVA: 0x1262C0
void __fastcall SSActor::mthdc_get_instance(SSInvokedMethod *scope_p, SSActor **result_pp)
{
  SSInstance *i_data_p; // rdi
  SSInstance *v4; // rax
  unsigned __int64 *p_i_user_data2; // rax
  unsigned __int64 v6; // rcx
  SSActor *v7; // rax

  if ( result_pp )
  {
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = scope_p->vfptr->get_topmost_scope(scope_p);
    if ( v4 && (p_i_user_data2 = &v4[-1].i_user_data2) != 0i64 && (v6 = p_i_user_data2[7]) != 0 )
    {
      v7 = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(v6 + 304),
             (ASymbol *)&i_data_p->i_user_data);
      ++v7->i_ref_count;
      *result_pp = v7;
    }
    else
    {
      ++MEMORY[0x10];
      *result_pp = 0i64;
    }
  }
}

// File Line: 601
// RVA: 0x126370
void __fastcall SSActor::mthdc_get_instance_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v3; // rax
  SSInstance *v4; // rcx
  unsigned __int64 *p_i_user_data2; // rax
  unsigned __int64 v6; // rax

  if ( result_pp )
  {
    v3 = scope_p->vfptr->get_topmost_scope(scope_p);
    v4 = 0i64;
    if ( v3 )
      p_i_user_data2 = &v3[-1].i_user_data2;
    else
      p_i_user_data2 = 0i64;
    if ( p_i_user_data2 )
    {
      v6 = p_i_user_data2[7];
      if ( v6 )
      {
        if ( *(_DWORD *)(v6 + 304) )
          v4 = **(SSInstance ***)(v6 + 312);
      }
    }
    ++v4->i_ref_count;
    *result_pp = v4;
  }
}

// File Line: 637
// RVA: 0x126330
void __fastcall SSActor::mthdc_get_instance_count(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v3; // rax

  if ( result_pp )
  {
    v3 = scope_p->vfptr->get_topmost_scope(scope_p);
    if ( v3 )
      v3 = (SSInstance *)((char *)v3 - 8);
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   *(unsigned int *)(*(_QWORD *)&v3[1].i_ptr_id + 304i64));
  }
}

// File Line: 654
// RVA: 0x1263C0
void __fastcall SSActor::mthdc_get_instances(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v3; // rax
  unsigned __int64 *p_i_user_data2; // rax
  APArrayBase<SSInstance> *v5; // rsi
  unsigned int i_count; // ebx
  SSList *v7; // rax
  SSList *v8; // rdi
  SSInstance **v9; // rax
  __int64 v10; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  if ( result_pp )
  {
    v3 = scope_p->vfptr->get_topmost_scope(scope_p);
    if ( v3 )
      p_i_user_data2 = &v3[-1].i_user_data2;
    else
      p_i_user_data2 = 0i64;
    v5 = (APArrayBase<SSInstance> *)p_i_user_data2[7];
    i_count = v5[19].i_count;
    v7 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v8 = v7;
    if ( v7 )
    {
      v7->i_items.i_count = 0;
      v7->i_items.i_array_p = 0i64;
      v7->i_items.i_size = 0;
      if ( i_count )
      {
        v7->i_items.i_size = i_count;
        v9 = APArrayBase<SSInstance>::alloc_array(i_count);
      }
      else
      {
        v7->i_items.i_size = 0;
        v9 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v8->i_items.i_array_p = v9;
    }
    else
    {
      v8 = 0i64;
    }
    APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::operator=(&v8->i_items, v5 + 19);
    v10 = v8->i_items.i_count;
    if ( (_DWORD)v10 )
    {
      i_array_p = (ARefCountMix<SSInstance> **)v8->i_items.i_array_p;
      for ( i = &i_array_p[v10]; i_array_p < i; ++i_array_p )
        UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
    }
    *result_pp = SSList::as_instance(v8);
  }
}

// File Line: 679
// RVA: 0x132030
void SSActor::register_atomic(void)
{
  unsigned int v0; // eax
  SSActor **i_array_p; // rbx
  unsigned int v2; // eax
  SSActor **v3; // rbx
  SSActorClass *v4; // rbx
  ASymbol *v5; // rax
  SSMethodBase **v6; // rdx
  __int64 i_uid; // r9
  SSMethodBase **v8; // r8
  __int64 i_count; // rax
  SSMethodBase **v10; // r10
  _BOOL8 v11; // rcx
  __int64 v12; // rdi
  __int64 v13; // r15
  SSParameters *v14; // rsi
  SSParameters *v15; // r14
  bool v16; // zf
  SSMethodBase **v17; // r8
  __int64 v18; // rax
  SSMethodBase **v19; // r10
  _BOOL8 v20; // rcx
  __int64 v21; // rdi
  __int64 v22; // r15
  SSParameters *v23; // rsi
  SSParameters *v24; // r14
  SSMethodBase **v25; // r8
  __int64 v26; // rax
  SSMethodBase **v27; // r10
  _BOOL8 v28; // rcx
  __int64 v29; // rdi
  __int64 v30; // r15
  SSParameters *v31; // rsi
  SSParameters *v32; // r14
  SSMethodBase **v33; // r8
  __int64 v34; // rax
  SSMethodBase **v35; // r10
  _BOOL8 v36; // rcx
  __int64 v37; // rdi
  __int64 v38; // r15
  SSParameters *v39; // rsi
  SSParameters *v40; // r14
  SSMethodBase **v41; // r8
  __int64 v42; // rax
  SSMethodBase **v43; // r10
  _BOOL8 v44; // rcx
  __int64 v45; // rdi
  __int64 v46; // r15
  SSParameters *v47; // rsi
  SSParameters *v48; // r14
  SSMethodBase **v49; // r8
  __int64 v50; // rax
  SSMethodBase **v51; // r10
  _BOOL8 v52; // rcx
  __int64 v53; // rdi
  __int64 v54; // r15
  SSParameters *v55; // rsi
  SSParameters *v56; // r14
  SSActorClass *v57; // rbx
  ASymbol *v58; // rax
  SSActorClass *v59; // rbx
  ASymbol *v60; // rax
  SSActorClass *v61; // rbx
  ASymbol *v62; // rax
  SSActorClass *v63; // rbx
  ASymbol *v64; // rax
  SSActorClass *v65; // rbx
  ASymbol *v66; // rax
  SSActorClass *v67; // rbx
  ASymbol *v68; // rax
  SSActorClass *v69; // rbx
  ASymbol *v70; // rax
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v72; // [rsp+78h] [rbp+48h]
  __int64 v73; // [rsp+80h] [rbp+50h]

  if ( SSActor::c_update_actors.i_size < 0x200 )
  {
    v0 = AMemory::c_req_byte_size_func(0x1000u) >> 3;
    SSActor::c_update_actors.i_size = v0;
    if ( SSActor::c_update_actors.i_count )
    {
      i_array_p = SSActor::c_update_actors.i_array_p;
      SSActor::c_update_actors.i_array_p = APArrayBase<SSActor>::alloc_array(v0);
      memmove(SSActor::c_update_actors.i_array_p, i_array_p, 8i64 * SSActor::c_update_actors.i_count);
      AMemory::c_free_func(i_array_p);
    }
    else
    {
      AMemory::c_free_func(SSActor::c_update_actors.i_array_p);
      SSActor::c_update_actors.i_array_p = APArrayBase<SSActor>::alloc_array(SSActor::c_update_actors.i_size);
    }
  }
  if ( SSActor::c_updating_actors.i_size < 0x200 )
  {
    v2 = AMemory::c_req_byte_size_func(0x1000u) >> 3;
    SSActor::c_updating_actors.i_size = v2;
    if ( SSActor::c_updating_actors.i_count )
    {
      v3 = SSActor::c_updating_actors.i_array_p;
      SSActor::c_updating_actors.i_array_p = APArrayBase<SSActor>::alloc_array(v2);
      memmove(SSActor::c_updating_actors.i_array_p, v3, 8i64 * SSActor::c_updating_actors.i_count);
      AMemory::c_free_func(v3);
    }
    else
    {
      AMemory::c_free_func(SSActor::c_updating_actors.i_array_p);
      SSActor::c_updating_actors.i_array_p = APArrayBase<SSActor>::alloc_array(SSActor::c_updating_actors.i_size);
    }
  }
  v4 = SSBrain::c_actor_class_p;
  v5 = ASymbol::create((ASymbol *)&result, "!named", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v4,
    v5,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSActor::mthd_ctor_named,
    SSBindFlag_instance_no_rebind);
  v8 = (SSMethodBase **)SSBrain::c_actor_class_p;
  i_count = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    v8 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v10 = &v8[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &v8[((char *)v10 - (char *)v8) >> 4];
        i_uid = (*v6)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= (unsigned int)i_uid )
          break;
        if ( v8 == v6 )
          goto LABEL_18;
        v10 = v6 - 1;
      }
      v11 = ASymbol_String.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_String.i_uid != (_DWORD)i_uid;
      if ( v11 )
        break;
      if ( v10 == v6 )
        goto LABEL_18;
      v8 = v6 + 1;
    }
    v12 = (__int64)*v6;
  }
  else
  {
LABEL_18:
    v12 = 0i64;
  }
  result = v12;
  if ( v12 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64, __int64))(*(_QWORD *)v12 + 16i64))(
           v12,
           v6,
           v8,
           i_uid,
           -2i64) == 1 )
    {
      *(_QWORD *)(v12 + 32) = SSActor::mthd_string;
    }
    else
    {
      v13 = *(_QWORD *)(v12 + 16);
      v14 = *(SSParameters **)(v12 + 24);
      v72 = v14;
      if ( v14 )
        ++v14->i_ref_count;
      v15 = *(SSParameters **)(v12 + 24);
      if ( v15 )
      {
        v16 = v15->i_ref_count-- == 1;
        if ( v16 )
        {
          v15->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v15);
          AMemory::c_free_func(v15);
        }
        *(_QWORD *)(v12 + 24) = 0i64;
      }
      v73 = v12;
      *(ASymbol *)(v12 + 8) = ASymbol_String;
      *(_QWORD *)(v12 + 16) = v13;
      *(_QWORD *)v12 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v12 + 24) = v14;
      if ( v14 )
        ++v14->i_ref_count;
      *(_QWORD *)v12 = &SSMethodBase::`vftable;
      *(_QWORD *)v12 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v12 + 32) = SSActor::mthd_string;
      if ( v14 )
      {
        v16 = v14->i_ref_count-- == 1;
        if ( v16 )
        {
          v14->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v14);
          AMemory::c_free_func(v14);
        }
      }
    }
  }
  v17 = (SSMethodBase **)SSBrain::c_actor_class_p;
  v18 = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)v18 )
  {
    v17 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v19 = &v17[v18 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &v17[((char *)v19 - (char *)v17) >> 4];
        i_uid = (*v6)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)i_uid )
          break;
        if ( v17 == v6 )
          goto LABEL_42;
        v19 = v6 - 1;
      }
      v20 = ASymbol_equals.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals.i_uid != (_DWORD)i_uid;
      if ( v20 )
        break;
      if ( v19 == v6 )
        goto LABEL_42;
      v17 = v6 + 1;
    }
    v21 = (__int64)*v6;
  }
  else
  {
LABEL_42:
    v21 = 0i64;
  }
  result = v21;
  if ( v21 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v21 + 16i64))(
           v21,
           v6,
           v17,
           i_uid) == 1 )
    {
      *(_QWORD *)(v21 + 32) = SSActor::mthd_op_equals;
    }
    else
    {
      v22 = *(_QWORD *)(v21 + 16);
      v23 = *(SSParameters **)(v21 + 24);
      v72 = v23;
      if ( v23 )
        ++v23->i_ref_count;
      v24 = *(SSParameters **)(v21 + 24);
      if ( v24 )
      {
        v16 = v24->i_ref_count-- == 1;
        if ( v16 )
        {
          v24->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v24);
          AMemory::c_free_func(v24);
        }
        *(_QWORD *)(v21 + 24) = 0i64;
      }
      v73 = v21;
      *(ASymbol *)(v21 + 8) = ASymbol_equals;
      *(_QWORD *)(v21 + 16) = v22;
      *(_QWORD *)v21 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v21 + 24) = v23;
      if ( v23 )
        ++v23->i_ref_count;
      *(_QWORD *)v21 = &SSMethodBase::`vftable;
      *(_QWORD *)v21 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v21 + 32) = SSActor::mthd_op_equals;
      if ( v23 )
      {
        v16 = v23->i_ref_count-- == 1;
        if ( v16 )
        {
          v23->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v23);
          AMemory::c_free_func(v23);
        }
      }
    }
  }
  v25 = (SSMethodBase **)SSBrain::c_actor_class_p;
  v26 = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)v26 )
  {
    v25 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v27 = &v25[v26 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &v25[((char *)v27 - (char *)v25) >> 4];
        i_uid = (*v6)->i_name.i_uid;
        if ( ASymbol_get_name.i_uid >= (unsigned int)i_uid )
          break;
        if ( v25 == v6 )
          goto LABEL_66;
        v27 = v6 - 1;
      }
      v28 = ASymbol_get_name.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_get_name.i_uid != (_DWORD)i_uid;
      if ( v28 )
        break;
      if ( v27 == v6 )
        goto LABEL_66;
      v25 = v6 + 1;
    }
    v29 = (__int64)*v6;
  }
  else
  {
LABEL_66:
    v29 = 0i64;
  }
  result = v29;
  if ( v29 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v29 + 16i64))(
           v29,
           v6,
           v25,
           i_uid) == 1 )
    {
      *(_QWORD *)(v29 + 32) = SSActor::mthd_get_name;
    }
    else
    {
      v30 = *(_QWORD *)(v29 + 16);
      v31 = *(SSParameters **)(v29 + 24);
      v72 = v31;
      if ( v31 )
        ++v31->i_ref_count;
      v32 = *(SSParameters **)(v29 + 24);
      if ( v32 )
      {
        v16 = v32->i_ref_count-- == 1;
        if ( v16 )
        {
          v32->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v32);
          AMemory::c_free_func(v32);
        }
        *(_QWORD *)(v29 + 24) = 0i64;
      }
      v73 = v29;
      *(ASymbol *)(v29 + 8) = ASymbol_get_name;
      *(_QWORD *)(v29 + 16) = v30;
      *(_QWORD *)v29 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v29 + 24) = v31;
      if ( v31 )
        ++v31->i_ref_count;
      *(_QWORD *)v29 = &SSMethodBase::`vftable;
      *(_QWORD *)v29 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v29 + 32) = SSActor::mthd_get_name;
      if ( v31 )
      {
        v16 = v31->i_ref_count-- == 1;
        if ( v16 )
        {
          v31->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v31);
          AMemory::c_free_func(v31);
        }
      }
    }
  }
  v33 = (SSMethodBase **)SSBrain::c_actor_class_p;
  v34 = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)v34 )
  {
    v33 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v35 = &v33[v34 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &v33[((char *)v35 - (char *)v33) >> 4];
        i_uid = (*v6)->i_name.i_uid;
        if ( ASymbol_get_strategy_name.i_uid >= (unsigned int)i_uid )
          break;
        if ( v33 == v6 )
          goto LABEL_90;
        v35 = v6 - 1;
      }
      v36 = ASymbol_get_strategy_name.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_get_strategy_name.i_uid != (_DWORD)i_uid;
      if ( v36 )
        break;
      if ( v35 == v6 )
        goto LABEL_90;
      v33 = v6 + 1;
    }
    v37 = (__int64)*v6;
  }
  else
  {
LABEL_90:
    v37 = 0i64;
  }
  result = v37;
  if ( v37 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v37 + 16i64))(
           v37,
           v6,
           v33,
           i_uid) == 1 )
    {
      *(_QWORD *)(v37 + 32) = SSActor::mthd_get_strategy_name;
    }
    else
    {
      v38 = *(_QWORD *)(v37 + 16);
      v39 = *(SSParameters **)(v37 + 24);
      v72 = v39;
      if ( v39 )
        ++v39->i_ref_count;
      v40 = *(SSParameters **)(v37 + 24);
      if ( v40 )
      {
        v16 = v40->i_ref_count-- == 1;
        if ( v16 )
        {
          v40->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v40);
          AMemory::c_free_func(v40);
        }
        *(_QWORD *)(v37 + 24) = 0i64;
      }
      v73 = v37;
      *(ASymbol *)(v37 + 8) = ASymbol_get_strategy_name;
      *(_QWORD *)(v37 + 16) = v38;
      *(_QWORD *)v37 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v37 + 24) = v39;
      if ( v39 )
        ++v39->i_ref_count;
      *(_QWORD *)v37 = &SSMethodBase::`vftable;
      *(_QWORD *)v37 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v37 + 32) = SSActor::mthd_get_strategy_name;
      if ( v39 )
      {
        v16 = v39->i_ref_count-- == 1;
        if ( v16 )
        {
          v39->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v39);
          AMemory::c_free_func(v39);
        }
      }
    }
  }
  v41 = (SSMethodBase **)SSBrain::c_actor_class_p;
  v42 = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)v42 )
  {
    v41 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v43 = &v41[v42 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &v41[((char *)v43 - (char *)v41) >> 4];
        i_uid = (*v6)->i_name.i_uid;
        if ( ASymbol_not_equal.i_uid >= (unsigned int)i_uid )
          break;
        if ( v41 == v6 )
          goto LABEL_114;
        v43 = v6 - 1;
      }
      v44 = ASymbol_not_equal.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_not_equal.i_uid != (_DWORD)i_uid;
      if ( v44 )
        break;
      if ( v43 == v6 )
        goto LABEL_114;
      v41 = v6 + 1;
    }
    v45 = (__int64)*v6;
  }
  else
  {
LABEL_114:
    v45 = 0i64;
  }
  result = v45;
  if ( v45 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v45 + 16i64))(
           v45,
           v6,
           v41,
           i_uid) == 1 )
    {
      *(_QWORD *)(v45 + 32) = SSInstance::mthdc_op_not_equal;
    }
    else
    {
      v46 = *(_QWORD *)(v45 + 16);
      v47 = *(SSParameters **)(v45 + 24);
      v72 = v47;
      if ( v47 )
        ++v47->i_ref_count;
      v48 = *(SSParameters **)(v45 + 24);
      if ( v48 )
      {
        v16 = v48->i_ref_count-- == 1;
        if ( v16 )
        {
          v48->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v48);
          AMemory::c_free_func(v48);
        }
        *(_QWORD *)(v45 + 24) = 0i64;
      }
      v73 = v45;
      *(ASymbol *)(v45 + 8) = ASymbol_not_equal;
      *(_QWORD *)(v45 + 16) = v46;
      *(_QWORD *)v45 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v45 + 24) = v47;
      if ( v47 )
        ++v47->i_ref_count;
      *(_QWORD *)v45 = &SSMethodBase::`vftable;
      *(_QWORD *)v45 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v45 + 32) = SSInstance::mthdc_op_not_equal;
      if ( v47 )
      {
        v16 = v47->i_ref_count-- == 1;
        if ( v16 )
        {
          v47->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v47);
          AMemory::c_free_func(v47);
        }
      }
    }
  }
  v49 = (SSMethodBase **)SSBrain::c_actor_class_p;
  v50 = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)v50 )
  {
    v49 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v51 = &v49[v50 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &v49[((char *)v51 - (char *)v49) >> 4];
        i_uid = (*v6)->i_name.i_uid;
        if ( ASymbol_set_strategy.i_uid >= (unsigned int)i_uid )
          break;
        if ( v49 == v6 )
          goto LABEL_138;
        v51 = v6 - 1;
      }
      v52 = ASymbol_set_strategy.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_set_strategy.i_uid != (_DWORD)i_uid;
      if ( v52 )
        break;
      if ( v51 == v6 )
        goto LABEL_138;
      v49 = v6 + 1;
    }
    v53 = (__int64)*v6;
  }
  else
  {
LABEL_138:
    v53 = 0i64;
  }
  result = v53;
  if ( v53 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v53 + 16i64))(
           v53,
           v6,
           v49,
           i_uid) == 1 )
    {
      *(_QWORD *)(v53 + 32) = UFG::TSAudio::MthdC_get_named;
    }
    else
    {
      v54 = *(_QWORD *)(v53 + 16);
      v55 = *(SSParameters **)(v53 + 24);
      v72 = v55;
      if ( v55 )
        ++v55->i_ref_count;
      v56 = *(SSParameters **)(v53 + 24);
      if ( v56 )
      {
        v16 = v56->i_ref_count-- == 1;
        if ( v16 )
        {
          v56->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v56);
          AMemory::c_free_func(v56);
        }
        *(_QWORD *)(v53 + 24) = 0i64;
      }
      v73 = v53;
      *(ASymbol *)(v53 + 8) = ASymbol_set_strategy;
      *(_QWORD *)(v53 + 16) = v54;
      *(_QWORD *)v53 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v53 + 24) = v55;
      if ( v55 )
        ++v55->i_ref_count;
      *(_QWORD *)v53 = &SSMethodBase::`vftable;
      *(_QWORD *)v53 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v53 + 32) = UFG::TSAudio::MthdC_get_named;
      if ( v55 )
      {
        v16 = v55->i_ref_count-- == 1;
        if ( v16 )
        {
          v55->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v55);
          AMemory::c_free_func(v55);
        }
      }
    }
  }
  SSClass::register_method_func(
    SSBrain::c_actor_class_p,
    &ASymbol_find_named,
    SSActor::mthdc_find_named,
    SSBindFlag_class_no_rebind);
  v57 = SSBrain::c_actor_class_p;
  v58 = ASymbol::create((ASymbol *)&result, "find_instance", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v57, v58, SSActor::mthdc_find_instance, SSBindFlag_class_no_rebind);
  v59 = SSBrain::c_actor_class_p;
  v60 = ASymbol::create((ASymbol *)&result, "generate_name_str", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v59, v60, SSActor::mthdc_generate_name_str, SSBindFlag_class_no_rebind);
  v61 = SSBrain::c_actor_class_p;
  v62 = ASymbol::create((ASymbol *)&result, "generate_name_sym", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v61, v62, SSActor::mthdc_generate_name_sym, SSBindFlag_class_no_rebind);
  v63 = SSBrain::c_actor_class_p;
  v64 = ASymbol::create((ASymbol *)&result, "get_instance", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v63,
    v64,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSActor::mthdc_get_instance,
    SSBindFlag_class_no_rebind);
  v65 = SSBrain::c_actor_class_p;
  v66 = ASymbol::create((ASymbol *)&result, "get_instance_first", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v65, v66, SSActor::mthdc_get_instance_first, SSBindFlag_class_no_rebind);
  v67 = SSBrain::c_actor_class_p;
  v68 = ASymbol::create((ASymbol *)&result, "get_instance_count", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v67, v68, SSActor::mthdc_get_instance_count, SSBindFlag_class_no_rebind);
  v69 = SSBrain::c_actor_class_p;
  v70 = ASymbol::create((ASymbol *)&result, "get_instances", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v69, v70, SSActor::mthdc_get_instances, SSBindFlag_class_no_rebind);
}

// File Line: 708
// RVA: 0x112B00
void __fastcall SSActor::coroutine_track(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  if ( icoro_p->i_pending_count )
  {
    if ( (icoro_p->i_flags & 2) == 0 )
    {
      APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
        &this->i_icoroutines_pending,
        icoro_p);
      icoro_p->i_flags |= 2u;
    }
    SSActor::coroutine_track_updating_stop(this, icoro_p);
  }
  else
  {
    if ( (icoro_p->i_flags & 1) == 0 )
    {
      APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
        &this->i_icoroutines_to_update,
        icoro_p);
      icoro_p->i_flags |= 1u;
      if ( (this->i_actor_flags & 2) == 0 )
        SSActor::enable_on_update(this, 1);
    }
    SSActor::coroutine_track_pending_stop(this, icoro_p);
  }
}

// File Line: 727
// RVA: 0x112C20
void __fastcall SSActor::coroutine_track_updating(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  if ( (icoro_p->i_flags & 1) == 0 )
  {
    APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
      &this->i_icoroutines_to_update,
      icoro_p);
    icoro_p->i_flags |= 1u;
    if ( (this->i_actor_flags & 2) == 0 )
      SSActor::enable_on_update(this, 1);
  }
}

// File Line: 746
// RVA: 0x112C70
void __fastcall SSActor::coroutine_track_updating_stop(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  unsigned int i_count; // eax
  SSInvokedCoroutine **i_array_p; // r9
  __int64 v6; // r10
  SSInvokedCoroutine **v7; // rcx
  SSInvokedCoroutine **v8; // rdx
  __int64 v9; // r8
  SSInvokedCoroutine **v10; // rdx
  SSInvokedCoroutine **v11; // rax

  if ( (icoro_p->i_flags & 1) != 0 )
  {
    i_count = this->i_icoroutines_to_update.i_count;
    if ( i_count )
    {
      i_array_p = this->i_icoroutines_to_update.i_array_p;
      v6 = i_count - 1;
      v7 = &i_array_p[v6];
      v8 = i_array_p;
      if ( i_array_p <= v7 )
      {
        while ( icoro_p != *v8 )
        {
          if ( ++v8 > v7 )
            goto LABEL_7;
        }
        this->i_icoroutines_to_update.i_count = v6;
        memmove(
          &i_array_p[(unsigned int)(v8 - i_array_p)],
          &i_array_p[(unsigned int)(v8 - i_array_p) + 1],
          8i64 * ((unsigned int)v6 - (unsigned int)(v8 - i_array_p)));
      }
    }
LABEL_7:
    icoro_p->i_flags &= ~1u;
    if ( (this->i_actor_flags & 8) != 0 )
    {
      if ( SSActor::c_icoroutines_updating.i_count )
      {
        v9 = SSActor::c_icoroutines_updating.i_count - 1;
        v10 = &SSActor::c_icoroutines_updating.i_array_p[v9];
        v11 = SSActor::c_icoroutines_updating.i_array_p;
        if ( SSActor::c_icoroutines_updating.i_array_p <= v10 )
        {
          while ( icoro_p != *v11 )
          {
            if ( ++v11 > v10 )
              return;
          }
          --SSActor::c_icoroutines_updating.i_count;
          memmove(
            &SSActor::c_icoroutines_updating.i_array_p[(unsigned int)(v11 - SSActor::c_icoroutines_updating.i_array_p)],
            &SSActor::c_icoroutines_updating.i_array_p[(unsigned int)(v11 - SSActor::c_icoroutines_updating.i_array_p)
                                                     + 1],
            8i64 * ((unsigned int)v9 - (unsigned int)(v11 - SSActor::c_icoroutines_updating.i_array_p)));
        }
      }
    }
  }
}

// File Line: 777
// RVA: 0x112B90
void __fastcall SSActor::coroutine_track_pending_stop(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  unsigned int i_count; // eax
  SSInvokedCoroutine **i_array_p; // r11
  __int64 v5; // r10
  SSInvokedCoroutine **v6; // rdx
  SSInvokedCoroutine **v7; // rax

  if ( (icoro_p->i_flags & 2) != 0 )
  {
    i_count = this->i_icoroutines_pending.i_count;
    if ( i_count
      && (i_array_p = this->i_icoroutines_pending.i_array_p,
          v5 = i_count - 1,
          v6 = &i_array_p[v5],
          v7 = i_array_p,
          i_array_p <= v6) )
    {
      do
      {
        if ( icoro_p == *v7 )
        {
          this->i_icoroutines_pending.i_count = v5;
          memmove(
            &i_array_p[(unsigned int)(v7 - i_array_p)],
            &i_array_p[(unsigned int)(v7 - i_array_p) + 1],
            8i64 * ((unsigned int)v5 - (unsigned int)(v7 - i_array_p)));
          goto LABEL_8;
        }
        ++v7;
      }
      while ( v7 <= v6 );
      icoro_p->i_flags &= ~2u;
    }
    else
    {
LABEL_8:
      icoro_p->i_flags &= ~2u;
    }
  }
}

// File Line: 790
// RVA: 0x111F20
void __fastcall SSActor::clear_coroutines(SSActor *this)
{
  unsigned int i_count; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  SSInvokedCoroutine *i; // rsi
  unsigned int i_ptr_id; // eax
  AList<SSInvokedBase,SSInvokedBase> *p_i_calls; // rbx
  int v8; // edi
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  SSInvokedCoroutine *j; // rsi
  unsigned int v18; // eax
  AList<SSInvokedBase,SSInvokedBase> *v19; // rbx
  int v20; // edi
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v23; // rax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax

  i_count = SSActor::c_icoroutines_updating.i_count;
  if ( (this->i_actor_flags & 8) != 0 )
    i_count = 0;
  SSActor::c_icoroutines_updating.i_count = i_count;
  v3 = this->i_icoroutines_pending.i_count;
  if ( v3 )
  {
    v4 = v3 - 1;
    this->i_icoroutines_pending.i_count = v4;
    for ( i = this->i_icoroutines_pending.i_array_p[v4]; i; i = this->i_icoroutines_pending.i_array_p[v14] )
    {
      i_ptr_id = i->i_ptr_id;
      if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
      {
        i->i_flags &= ~2u;
        i->i_pending_count = 0;
        if ( i_ptr_id <= SSObjectBase::c_ptr_id_prev )
        {
          p_i_calls = &i->i_calls;
          v8 = 0;
          if ( (AList<SSInvokedBase,SSInvokedBase> *)p_i_calls->i_sentinel.i_next_p == p_i_calls )
            goto LABEL_15;
          do
          {
            i_next_p = p_i_calls->i_sentinel.i_next_p;
            v10 = p_i_calls->i_sentinel.i_next_p->i_next_p;
            i_prev_p = p_i_calls->i_sentinel.i_next_p->i_prev_p;
            v10->i_prev_p = i_prev_p;
            i_prev_p->i_next_p = v10;
            i_next_p->i_prev_p = i_next_p;
            i_next_p->i_next_p = i_next_p;
            v12 = (unsigned int)i_next_p[-1].i_prev_p;
            if ( v12 && v12 <= SSObjectBase::c_ptr_id_prev )
              ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, __int64))i_next_p[-1].i_next_p[5].i_prev_p)(
                &i_next_p[-1].i_next_p,
                0i64,
                1i64);
            --v8;
          }
          while ( (AList<SSInvokedBase,SSInvokedBase> *)p_i_calls->i_sentinel.i_next_p != p_i_calls );
          if ( v8 <= 0 )
LABEL_15:
            i->i_pending_count = 0;
          else
            i->i_pending_count = v8;
        }
        SSInvokedCoroutine::pool_delete(i);
      }
      v13 = this->i_icoroutines_pending.i_count;
      if ( !v13 )
        break;
      v14 = v13 - 1;
      this->i_icoroutines_pending.i_count = v14;
    }
  }
  v15 = this->i_icoroutines_to_update.i_count;
  if ( v15 )
  {
    v16 = v15 - 1;
    this->i_icoroutines_to_update.i_count = v16;
    for ( j = this->i_icoroutines_to_update.i_array_p[v16]; j; j = this->i_icoroutines_to_update.i_array_p[v26] )
    {
      v18 = j->i_ptr_id;
      if ( v18 && v18 <= SSObjectBase::c_ptr_id_prev )
      {
        j->i_flags &= ~1u;
        j->i_pending_count = 0;
        if ( v18 <= SSObjectBase::c_ptr_id_prev )
        {
          v19 = &j->i_calls;
          v20 = 0;
          if ( (AList<SSInvokedBase,SSInvokedBase> *)v19->i_sentinel.i_next_p == v19 )
            goto LABEL_31;
          do
          {
            v21 = v19->i_sentinel.i_next_p;
            v22 = v19->i_sentinel.i_next_p->i_next_p;
            v23 = v19->i_sentinel.i_next_p->i_prev_p;
            v22->i_prev_p = v23;
            v23->i_next_p = v22;
            v21->i_prev_p = v21;
            v21->i_next_p = v21;
            v24 = (unsigned int)v21[-1].i_prev_p;
            if ( v24 && v24 <= SSObjectBase::c_ptr_id_prev )
              ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, __int64))v21[-1].i_next_p[5].i_prev_p)(
                &v21[-1].i_next_p,
                0i64,
                1i64);
            --v20;
          }
          while ( (AList<SSInvokedBase,SSInvokedBase> *)v19->i_sentinel.i_next_p != v19 );
          if ( v20 <= 0 )
LABEL_31:
            j->i_pending_count = 0;
          else
            j->i_pending_count = v20;
        }
        SSInvokedCoroutine::pool_delete(j);
      }
      v25 = this->i_icoroutines_to_update.i_count;
      if ( !v25 )
        break;
      v26 = v25 - 1;
      this->i_icoroutines_to_update.i_count = v26;
    }
  }
  SSActor::enable_on_update(this, 0);
}

// File Line: 855
// RVA: 0x13CD50
void __fastcall SSActor::suspend_coroutines(SSActor *this)
{
  __int64 i_count; // rax
  SSInvokedCoroutine **i_array_p; // rbx
  SSInvokedCoroutine **i; // rdi
  __int64 v5; // rax
  SSInvokedCoroutine **v6; // rbx
  SSInvokedCoroutine **j; // rdi

  i_count = this->i_icoroutines_pending.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_icoroutines_pending.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
      SSInvokedCoroutine::suspend(*i_array_p);
  }
  v5 = this->i_icoroutines_to_update.i_count;
  if ( (_DWORD)v5 )
  {
    v6 = this->i_icoroutines_to_update.i_array_p;
    for ( j = &v6[v5]; v6 < j; ++v6 )
      SSInvokedCoroutine::suspend(*v6);
  }
}

// File Line: 880
// RVA: 0x114D00
SSActor *__fastcall SSActor::find(ASymbol *actor_name)
{
  return APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(&SSBrain::c_actor_class_p->i_instances, actor_name);
}

// File Line: 907
// RVA: 0x116DD0
AString *__fastcall SSActor::generate_unique_name_str(AString *result, AString *name_root, unsigned int *create_idx_p)
{
  unsigned int v6; // ebx
  const char *v7; // rax
  AStringRef *v8; // rax
  __int64 i_length; // rbp
  unsigned int v10; // r15d
  AStringRef *i_str_ref_p; // rdx
  __int64 v12; // rax
  AString *v13; // r14
  unsigned int v14; // edi
  unsigned int v15; // ebx
  AStringRef *v16; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v21; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  ASymbol *v23; // rax
  __int64 i_count; // rcx
  SSActor **i_array_p; // rdx
  SSActor **v26; // r9
  unsigned int i_uid; // r10d
  SSActor **v28; // rax
  unsigned int v29; // r8d
  ASymbol v31; // [rsp+88h] [rbp+10h] BYREF
  AString resulta; // [rsp+90h] [rbp+18h] BYREF

  v6 = AMemory::c_req_byte_size_func(name_root->i_str_ref_p->i_length + 4);
  v7 = (const char *)AMemory::c_malloc_func(v6, "AStringRef.buffer");
  v8 = AStringRef::pool_new(v7, name_root->i_str_ref_p->i_length, v6, 1u, 1, 0);
  result->i_str_ref_p = v8;
  memmove(v8->i_cstr_p, name_root->i_str_ref_p->i_cstr_p, v8->i_length + 1);
  i_length = name_root->i_str_ref_p->i_length;
  v10 = 0;
  do
  {
    ++v10;
    i_str_ref_p = result->i_str_ref_p;
    if ( (_DWORD)i_length == -1 )
    {
      v12 = -1i64;
      do
        ++v12;
      while ( i_str_ref_p->i_cstr_p[v12] );
      i_str_ref_p->i_length = v12;
    }
    else if ( i_str_ref_p->i_length != (_DWORD)i_length || i_str_ref_p->i_cstr_p[i_length] )
    {
      if ( (unsigned int)i_length >= i_str_ref_p->i_size || i_str_ref_p->i_ref_count + i_str_ref_p->i_read_only != 1 )
        AString::set_size(result, i_length);
      result->i_str_ref_p->i_length = i_length;
      result->i_str_ref_p->i_cstr_p[result->i_str_ref_p->i_length] = 0;
    }
    v13 = AString::ctor_uint(&resulta, v10, 0xAu);
    v14 = v13->i_str_ref_p->i_length;
    if ( v14 )
    {
      v15 = v14 + result->i_str_ref_p->i_length;
      if ( v15 >= result->i_str_ref_p->i_size
        || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(result, v15);
      }
      memmove(&result->i_str_ref_p->i_cstr_p[result->i_str_ref_p->i_length], v13->i_str_ref_p->i_cstr_p, v14 + 1);
      result->i_str_ref_p->i_length = v15;
    }
    v16 = resulta.i_str_ref_p;
    if ( resulta.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( v16->i_deallocate )
        AMemory::c_free_func(v16->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v16 < i_objects_a
        || (v21 = (unsigned __int64)v16 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v21) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v16);
    }
    v23 = ASymbol::create(&v31, result, ATerm_long);
    i_count = SSBrain::c_actor_class_p->i_instances.i_count;
    if ( !(_DWORD)i_count )
      break;
    i_array_p = SSBrain::c_actor_class_p->i_instances.i_array_p;
    v26 = &i_array_p[i_count - 1];
    i_uid = v23->i_uid;
    while ( 1 )
    {
      while ( 1 )
      {
        v28 = &i_array_p[((char *)v26 - (char *)i_array_p) >> 4];
        v29 = (*v28)->i_name.i_uid;
        if ( i_uid >= v29 )
          break;
        if ( i_array_p == v28 )
          goto LABEL_33;
        v26 = v28 - 1;
      }
      if ( i_uid == v29 )
        break;
      if ( v26 == v28 )
        goto LABEL_33;
      i_array_p = v28 + 1;
    }
  }
  while ( *v28 );
LABEL_33:
  if ( create_idx_p )
    *create_idx_p = v10;
  return result;
}

// File Line: 954
// RVA: 0x117040
ASymbol *__fastcall SSActor::generate_unique_name_sym(ASymbol *result, AString *name_root, unsigned int *create_idx_p)
{
  unsigned int v6; // ebx
  const char *v7; // rax
  __int64 i_length; // rdi
  unsigned int v9; // ebp
  AStringRef *i_str_ref_p; // rax
  __int64 v11; // rcx
  AString *v12; // r14
  unsigned int v13; // esi
  AStringRef *v14; // rcx
  unsigned int v15; // ebx
  AStringRef *v16; // rbx
  bool v17; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v21; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  ASymbol *v23; // rax
  unsigned int i_uid; // r10d
  __int64 i_count; // rax
  SSActor **i_array_p; // rdx
  SSActor **v27; // r9
  SSActor **v28; // rax
  unsigned int v29; // r8d
  AStringRef *v30; // rbx
  AObjReusePool<AStringRef> *v31; // rax
  AObjBlock<AStringRef> *v32; // rcx
  unsigned __int64 v33; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  ASymbol v36; // [rsp+80h] [rbp+8h] BYREF
  AString str; // [rsp+88h] [rbp+10h] BYREF
  AString resulta; // [rsp+90h] [rbp+18h] BYREF

  result->i_uid = -1;
  v6 = AMemory::c_req_byte_size_func(name_root->i_str_ref_p->i_length + 4);
  v7 = (const char *)AMemory::c_malloc_func(v6, "AStringRef.buffer");
  str.i_str_ref_p = AStringRef::pool_new(v7, name_root->i_str_ref_p->i_length, v6, 1u, 1, 0);
  memmove(str.i_str_ref_p->i_cstr_p, name_root->i_str_ref_p->i_cstr_p, str.i_str_ref_p->i_length + 1);
  i_length = name_root->i_str_ref_p->i_length;
  v9 = 0;
  do
  {
    ++v9;
    i_str_ref_p = str.i_str_ref_p;
    if ( (_DWORD)i_length == -1 )
    {
      v11 = -1i64;
      do
        ++v11;
      while ( str.i_str_ref_p->i_cstr_p[v11] );
      str.i_str_ref_p->i_length = v11;
    }
    else if ( str.i_str_ref_p->i_length != (_DWORD)i_length || str.i_str_ref_p->i_cstr_p[i_length] )
    {
      if ( (unsigned int)i_length >= str.i_str_ref_p->i_size
        || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, i_length);
        i_str_ref_p = str.i_str_ref_p;
      }
      i_str_ref_p->i_length = i_length;
      str.i_str_ref_p->i_cstr_p[i_length] = 0;
    }
    v12 = AString::ctor_uint(&resulta, v9, 0xAu);
    v13 = v12->i_str_ref_p->i_length;
    if ( v13 )
    {
      v14 = str.i_str_ref_p;
      v15 = v13 + str.i_str_ref_p->i_length;
      if ( v15 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v15);
        v14 = str.i_str_ref_p;
      }
      memmove(&v14->i_cstr_p[v14->i_length], v12->i_str_ref_p->i_cstr_p, v13 + 1);
      str.i_str_ref_p->i_length = v15;
    }
    v16 = resulta.i_str_ref_p;
    v17 = resulta.i_str_ref_p->i_ref_count-- == 1;
    if ( v17 )
    {
      if ( v16->i_deallocate )
        AMemory::c_free_func(v16->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v16 < i_objects_a
        || (v21 = (unsigned __int64)v16 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v21) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v16);
    }
    v23 = ASymbol::create(&v36, &str, ATerm_long);
    i_uid = v23->i_uid;
    result->i_uid = v23->i_uid;
    i_count = SSBrain::c_actor_class_p->i_instances.i_count;
    if ( !(_DWORD)i_count )
      break;
    i_array_p = SSBrain::c_actor_class_p->i_instances.i_array_p;
    v27 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v28 = &i_array_p[((char *)v27 - (char *)i_array_p) >> 4];
        v29 = (*v28)->i_name.i_uid;
        if ( i_uid >= v29 )
          break;
        if ( i_array_p == v28 )
          goto LABEL_33;
        v27 = v28 - 1;
      }
      if ( i_uid == v29 )
        break;
      if ( v27 == v28 )
        goto LABEL_33;
      i_array_p = v28 + 1;
    }
  }
  while ( *v28 );
LABEL_33:
  if ( create_idx_p )
    *create_idx_p = v9;
  v30 = str.i_str_ref_p;
  v17 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v17 )
  {
    if ( v30->i_deallocate )
      AMemory::c_free_func(v30->i_cstr_p);
    v31 = AStringRef::get_pool();
    v32 = v31->i_block_p;
    v33 = (unsigned __int64)v32->i_objects_a;
    if ( (unsigned __int64)v30 < v33
      || (v21 = (unsigned __int64)v30 < v33 + 24i64 * v32->i_size, p_i_pool = &v31->i_pool, !v21) )
    {
      p_i_pool = &v31->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v30);
  }
  return result;
}

// File Line: 994
// RVA: 0x126E10
void __fastcall SSActor::on_update(SSActor *this)
{
  __int64 i_count; // rdi
  SSInvokedCoroutine **i_array_p; // rax
  unsigned int v4; // eax
  SSInvokedCoroutine *v5; // rdx
  unsigned int v6; // eax

  if ( (this->i_actor_flags & 5) == 5 )
  {
    ++this->i_ref_count;
    i_count = this->i_icoroutines_to_update.i_count;
    if ( (_DWORD)i_count )
    {
      if ( (unsigned int)i_count <= SSActor::c_icoroutines_updating.i_size )
      {
        i_array_p = SSActor::c_icoroutines_updating.i_array_p;
      }
      else
      {
        AMemory::c_free_func(SSActor::c_icoroutines_updating.i_array_p);
        SSActor::c_icoroutines_updating.i_size = AMemory::c_req_byte_size_func(8 * i_count) >> 3;
        i_array_p = APArrayBase<SSInvokedCoroutine>::alloc_array(SSActor::c_icoroutines_updating.i_size);
        SSActor::c_icoroutines_updating.i_array_p = i_array_p;
      }
      SSActor::c_icoroutines_updating.i_count = i_count;
      memmove(i_array_p, this->i_icoroutines_to_update.i_array_p, 8 * i_count);
      v4 = SSActor::c_icoroutines_updating.i_count;
      if ( SSActor::c_icoroutines_updating.i_count )
      {
        --SSActor::c_icoroutines_updating.i_count;
        v5 = SSActor::c_icoroutines_updating.i_array_p[v4 - 1];
      }
      else
      {
        v5 = 0i64;
      }
      for ( this->i_actor_flags |= 8u; v5; v5 = SSActor::c_icoroutines_updating.i_array_p[v6 - 1] )
      {
        SSInvokedCoroutine::on_update(v5);
        v6 = SSActor::c_icoroutines_updating.i_count;
        if ( !SSActor::c_icoroutines_updating.i_count )
          break;
        --SSActor::c_icoroutines_updating.i_count;
      }
      this->i_actor_flags &= ~8u;
    }
    if ( !this->i_icoroutines_to_update.i_count )
      SSActor::enable_on_update(this, 0);
    if ( this->i_ref_count-- == 1 )
    {
      this->i_ref_count = 0x80000000;
      this->vfptr[1].get_scope_context(this);
    }
  }
}

// File Line: 1048
// RVA: 0x13EAD0
void SSActor::update_all(void)
{
  SSActor **i_array_p; // rcx
  unsigned int i_count; // eax
  unsigned int v2; // eax
  SSActor *i; // rdx
  unsigned int v4; // eax

  if ( (SkookumScript::c_flags & 4) == 0 )
  {
    i_array_p = SSActor::c_updating_actors.i_array_p;
    SkookumScript::c_flags += 4;
    i_count = SSActor::c_update_actors.i_count;
    SSActor::c_updating_actors.i_count = SSActor::c_update_actors.i_count;
    if ( SSActor::c_update_actors.i_count > SSActor::c_updating_actors.i_size )
    {
      AMemory::c_free_func(SSActor::c_updating_actors.i_array_p);
      SSActor::c_updating_actors.i_size = AMemory::c_req_byte_size_func(8 * SSActor::c_updating_actors.i_count) >> 3;
      i_array_p = APArrayBase<SSActor>::alloc_array(SSActor::c_updating_actors.i_size);
      SSActor::c_updating_actors.i_array_p = i_array_p;
      i_count = SSActor::c_updating_actors.i_count;
    }
    memmove(i_array_p, SSActor::c_update_actors.i_array_p, 8i64 * i_count);
    v2 = SSActor::c_updating_actors.i_count;
    if ( SSActor::c_updating_actors.i_count )
    {
      --SSActor::c_updating_actors.i_count;
      for ( i = SSActor::c_updating_actors.i_array_p[v2 - 1]; i; i = SSActor::c_updating_actors.i_array_p[v4 - 1] )
      {
        i->vfptr[2].get_obj_type(i);
        v4 = SSActor::c_updating_actors.i_count;
        if ( !SSActor::c_updating_actors.i_count )
          break;
        --SSActor::c_updating_actors.i_count;
      }
    }
    if ( (SkookumScript::c_flags & 4) != 0 )
      SkookumScript::c_flags -= 4;
  }
}

