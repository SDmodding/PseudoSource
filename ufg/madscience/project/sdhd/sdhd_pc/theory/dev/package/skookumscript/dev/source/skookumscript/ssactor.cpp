// File Line: 47
// RVA: 0x14615D0
__int64 dynamic_initializer_for__SSActor::c_update_actors__()
{
  return atexit(dynamic_atexit_destructor_for__SSActor::c_update_actors__);
}

// File Line: 50
// RVA: 0x14615F0
__int64 dynamic_initializer_for__SSActor::c_updating_actors__()
{
  return atexit(dynamic_atexit_destructor_for__SSActor::c_updating_actors__);
}

// File Line: 53
// RVA: 0x14614D0
__int64 dynamic_initializer_for__SSActor::c_icoroutines_updating__()
{
  return atexit(dynamic_atexit_destructor_for__SSActor::c_icoroutines_updating__);
}

// File Line: 74
// RVA: 0x104140
void __fastcall SSActor::SSActor(SSActor *this, ASymbol *name, SSActorClass *class_p, bool add_to_instance_list)
{
  bool v4; // bl
  SSActor *v5; // rdi
  SSActorClass *v6; // rdx
  SSClass *v7; // rbx

  v4 = add_to_instance_list;
  v5 = this;
  this->i_name = (ASymbol)name->i_uid;
  v6 = SSBrain::c_actor_class_p;
  if ( class_p )
    v6 = class_p;
  SSDataInstance::SSDataInstance((SSDataInstance *)&this->vfptr, (SSClass *)&v6->vfptr);
  v5->vfptr = (SSObjectBaseVtbl *)&SSActor::`vftable;
  v5->i_icoroutines_to_update.i_count = 0;
  v5->i_icoroutines_to_update.i_array_p = 0i64;
  v5->i_icoroutines_to_update.i_size = 0;
  v5->i_icoroutines_pending.i_count = 0;
  v5->i_icoroutines_pending.i_array_p = 0i64;
  v5->i_icoroutines_pending.i_size = 0;
  v5->i_actor_flags = 4;
  if ( v4 )
  {
    v7 = v5->i_class_p;
    if ( v5->i_name.i_uid != ASymbol::get_null()->i_uid )
    {
      APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
        (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&v7[1],
        v5,
        0i64);
      if ( ((unsigned __int8 (__cdecl *)(SSClass *))v7->i_superclass_p->vfptr->is_actor_class)(v7->i_superclass_p) )
        SSActorClass::append_instance((SSActorClass *)v7->i_superclass_p, v5);
    }
  }
}

// File Line: 90
// RVA: 0x106AB0
void __fastcall SSActor::~SSActor(SSActor *this)
{
  SSActor *v1; // rbx

  v1 = this;
  this->vfptr = (SSObjectBaseVtbl *)&SSActor::`vftable;
  if ( this->i_actor_flags & 1 )
  {
    this->i_actor_flags ^= 1u;
    SSActor::clear_coroutines(this);
    SSActor::enable_on_update(v1, 0);
  }
  SSActorClass::remove_instance((SSActorClass *)v1->i_class_p, v1);
  AMemory::c_free_func(v1->i_icoroutines_pending.i_array_p);
  AMemory::c_free_func(v1->i_icoroutines_to_update.i_array_p);
  SSDataInstance::~SSDataInstance((SSDataInstance *)&v1->vfptr);
}

// File Line: 112
// RVA: 0x113E60
void __fastcall SSActor::enable_behavior(SSActor *this, bool activate)
{
  SSActor *v2; // rbx
  unsigned int v3; // eax

  v2 = this;
  if ( activate != (this->i_actor_flags & 1) )
  {
    this->i_actor_flags ^= 1u;
    if ( activate )
    {
      v3 = this->i_ptr_id;
      if ( v3 && v3 <= SSObjectBase::c_ptr_id_prev )
      {
        if ( this->i_icoroutines_to_update.i_count )
          SSActor::enable_on_update(this, 1);
      }
    }
    else
    {
      SSActor::clear_coroutines(this);
      SSActor::enable_on_update(v2, 0);
    }
  }
}

// File Line: 174
// RVA: 0x113FB0
void __fastcall SSActor::enable_on_update(SSActor *this, bool activate)
{
  SSActor *v2; // rbx
  unsigned int v3; // ecx
  int v4; // ecx
  unsigned int v5; // eax
  char v6; // al
  char v7; // al
  unsigned int find_pos_p; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = this->i_actor_flags;
  if ( activate != ((v3 >> 1) & 1) )
  {
    v4 = v3 ^ 2;
    v2->i_actor_flags = v4;
    if ( activate )
    {
      if ( v4 & 1 )
      {
        v5 = v2->i_ptr_id;
        if ( v5 )
        {
          if ( v5 <= SSObjectBase::c_ptr_id_prev )
          {
            APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
              (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSActor::c_update_actors.i_count,
              v2,
              0i64);
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
                if ( v6 & 1 )
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
             (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSActor::c_update_actors.i_count,
             v2,
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
             (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSActor::c_updating_actors.i_count,
             v2,
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
        SkookumScript::c_flags &= 0xFFFFFFFD;
        if ( SkookumScript::c_update_time_f )
        {
          SkookumScript::c_update_time_f();
          v7 = SkookumScript::c_flags;
        }
        if ( SkookumScript::c_on_update_request_f && v7 & 1 )
          SkookumScript::c_on_update_request_f(0);
      }
    }
  }
}

// File Line: 225
// RVA: 0x13BED0
void __fastcall SSActor::rename(SSActor *this, ASymbol *name)
{
  SSClass *v2; // rbp
  SSActor *v3; // rdi
  ASymbol *v4; // r14
  char v5; // bl
  unsigned int v6; // eax
  unsigned int v7; // er10
  __int64 v8; // rbx
  SSActor **v9; // r9
  SSActor **i; // rcx
  signed __int64 v11; // rdx
  unsigned int v12; // er8
  _BOOL8 v13; // r8
  unsigned int v14; // er10
  __int64 v15; // rsi
  SSActor **v16; // r9
  SSActor **j; // rcx
  signed __int64 v18; // rdx
  unsigned int v19; // er8
  _BOOL8 v20; // r8
  unsigned int v21; // eax
  unsigned int v22; // er10
  __int64 v23; // r11
  SSActor **v24; // r9
  SSActor **k; // rcx
  signed __int64 v26; // rdx
  unsigned int v27; // er8
  _BOOL8 v28; // r8

  v2 = this->i_class_p;
  v3 = this;
  v4 = name;
  v5 = 0;
  SSActorClass::remove_instance((SSActorClass *)v2, this);
  v6 = v3->i_actor_flags;
  if ( v6 & 1 && v6 & 2 )
  {
    if ( SSActor::c_update_actors.i_count )
    {
      v7 = v3->i_name.i_uid;
      v8 = SSActor::c_update_actors.i_count - 1;
      v9 = &SSActor::c_update_actors.i_array_p[v8];
      for ( i = SSActor::c_update_actors.i_array_p; ; i = (SSActor **)(v11 + 8) )
      {
        while ( 1 )
        {
          v11 = (signed __int64)&i[((char *)v9 - (char *)i) >> 4];
          v12 = *(_DWORD *)(*(_QWORD *)v11 + 72i64);
          if ( v7 >= v12 )
          {
            v13 = v7 != v12;
            if ( v13 >= 0 )
              break;
          }
          if ( i == (SSActor **)v11 )
            goto LABEL_13;
          v9 = (SSActor **)(v11 - 8);
        }
        if ( v13 <= 0 )
          break;
        if ( v9 == (SSActor **)v11 )
          goto LABEL_13;
      }
      SSActor::c_update_actors.i_count = v8;
      memmove(
        &SSActor::c_update_actors.i_array_p[(unsigned int)((signed __int64)(v11
                                                                          - (unsigned __int64)SSActor::c_update_actors.i_array_p) >> 3)],
        &SSActor::c_update_actors.i_array_p[(unsigned int)((signed __int64)(v11
                                                                          - (unsigned __int64)SSActor::c_update_actors.i_array_p) >> 3)
                                          + 1],
        8i64
      * ((unsigned int)v8
       - (unsigned int)((signed __int64)(v11 - (unsigned __int64)SSActor::c_update_actors.i_array_p) >> 3)));
    }
LABEL_13:
    if ( SSActor::c_updating_actors.i_count )
    {
      v14 = v3->i_name.i_uid;
      v15 = SSActor::c_updating_actors.i_count - 1;
      v16 = &SSActor::c_updating_actors.i_array_p[v15];
      for ( j = SSActor::c_updating_actors.i_array_p; ; j = (SSActor **)(v18 + 8) )
      {
        while ( 1 )
        {
          v18 = (signed __int64)&j[((char *)v16 - (char *)j) >> 4];
          v19 = *(_DWORD *)(*(_QWORD *)v18 + 72i64);
          if ( v14 >= v19 )
          {
            v20 = v14 != v19;
            if ( v20 >= 0 )
              break;
          }
          if ( j == (SSActor **)v18 )
            goto LABEL_23;
          v16 = (SSActor **)(v18 - 8);
        }
        if ( v20 <= 0 )
          break;
        if ( v16 == (SSActor **)v18 )
          goto LABEL_23;
      }
      SSActor::c_updating_actors.i_count = v15;
      v5 = 1;
      memmove(
        &SSActor::c_updating_actors.i_array_p[(unsigned int)((signed __int64)(v18
                                                                            - (unsigned __int64)SSActor::c_updating_actors.i_array_p) >> 3)],
        &SSActor::c_updating_actors.i_array_p[(unsigned int)((signed __int64)(v18
                                                                            - (unsigned __int64)SSActor::c_updating_actors.i_array_p) >> 3)
                                            + 1],
        8i64
      * ((unsigned int)v15
       - (unsigned int)((signed __int64)(v18 - (unsigned __int64)SSActor::c_updating_actors.i_array_p) >> 3)));
    }
    else
    {
LABEL_23:
      v5 = 0;
    }
  }
  v3->i_name = (ASymbol)v4->i_uid;
  if ( v3->i_name.i_uid != ASymbol::get_null()->i_uid )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&v2[1],
      v3,
      0i64);
    if ( ((unsigned __int8 (*)(void))v2->i_superclass_p->vfptr->is_actor_class)() )
      SSActorClass::append_instance((SSActorClass *)v2->i_superclass_p, v3);
  }
  v21 = v3->i_actor_flags;
  if ( v21 & 1 )
  {
    if ( v21 & 2 )
    {
      APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
        (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSActor::c_update_actors.i_count,
        v3,
        0i64);
      if ( v5 )
      {
        if ( SSActor::c_updating_actors.i_count )
        {
          v22 = v3->i_name.i_uid;
          v23 = SSActor::c_updating_actors.i_count - 1;
          v24 = &SSActor::c_updating_actors.i_array_p[v23];
          for ( k = SSActor::c_updating_actors.i_array_p; ; k = (SSActor **)(v26 + 8) )
          {
            while ( 1 )
            {
              v26 = (signed __int64)&k[((char *)v24 - (char *)k) >> 4];
              v27 = *(_DWORD *)(*(_QWORD *)v26 + 72i64);
              if ( v22 >= v27 )
              {
                v28 = v22 != v27;
                if ( v28 >= 0 )
                  break;
              }
              if ( k == (SSActor **)v26 )
                return;
              v24 = (SSActor **)(v26 - 8);
            }
            if ( v28 <= 0 )
              break;
            if ( v24 == (SSActor **)v26 )
              return;
          }
          SSActor::c_updating_actors.i_count = v23;
          memmove(
            &SSActor::c_updating_actors.i_array_p[(unsigned int)((signed __int64)(v26
                                                                                - (unsigned __int64)SSActor::c_updating_actors.i_array_p) >> 3)],
            &SSActor::c_updating_actors.i_array_p[(unsigned int)((signed __int64)(v26
                                                                                - (unsigned __int64)SSActor::c_updating_actors.i_array_p) >> 3)
                                                + 1],
            8i64
          * ((unsigned int)v23
           - (unsigned int)((signed __int64)(v26 - (unsigned __int64)SSActor::c_updating_actors.i_array_p) >> 3)));
        }
      }
    }
  }
}

// File Line: 308
// RVA: 0x130600
void __fastcall SSActor::pool_delete(SSActor *this)
{
  this->i_ptr_id = 0;
  this->vfptr->__vecDelDtor((SSObjectBase *)this, 1u);
}

// File Line: 321
// RVA: 0x10F2A0
AString *__fastcall SSActor::as_string(SSActor *this, AString *result)
{
  AString *v2; // rdi
  SSActor *v3; // rbx
  __int64 v4; // rbx
  AStringRef *v5; // rdx
  unsigned int v6; // esi
  unsigned int v7; // ebx
  AStringRef *v8; // rdx
  unsigned int v9; // ebx
  unsigned int v10; // esi
  __int64 v11; // rbx
  AStringRef *v12; // rbx
  bool v13; // zf
  AObjReusePool<AStringRef> *v14; // rax
  AObjBlock<AStringRef> *v15; // rcx
  unsigned __int64 v16; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v18; // rcx
  AStringRef *v19; // rbx
  AObjReusePool<AStringRef> *v20; // rax
  AObjBlock<AStringRef> *v21; // rcx
  unsigned __int64 v22; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v23; // rcx
  AString v25; // [rsp+60h] [rbp+8h]
  AString *v26; // [rsp+68h] [rbp+10h]
  AString resulta; // [rsp+70h] [rbp+18h]

  v26 = result;
  v2 = result;
  v3 = this;
  ANamed::get_name_str_dbg((ANamed *)&this->i_class_p->i_name, &resulta);
  ASymbol::as_str_dbg(&v3->i_name, &v25);
  AString::AString(v2, 0i64, resulta.i_str_ref_p->i_length + 6 + v25.i_str_ref_p->i_length, 0, 0);
  v4 = v2->i_str_ref_p->i_length + 1;
  if ( (unsigned int)v4 >= v2->i_str_ref_p->i_size || v2->i_str_ref_p->i_ref_count + v2->i_str_ref_p->i_read_only != 1 )
    AString::set_size(v2, v4);
  v2->i_str_ref_p->i_cstr_p[(unsigned int)(v4 - 1)] = 39;
  v2->i_str_ref_p->i_cstr_p[v4] = 0;
  v2->i_str_ref_p->i_length = v4;
  v5 = v25.i_str_ref_p;
  v6 = v25.i_str_ref_p->i_length;
  if ( v6 )
  {
    v7 = v6 + v2->i_str_ref_p->i_length;
    if ( v7 >= v2->i_str_ref_p->i_size || v2->i_str_ref_p->i_ref_count + v2->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(v2, v7);
      v5 = v25.i_str_ref_p;
    }
    memmove(&v2->i_str_ref_p->i_cstr_p[v2->i_str_ref_p->i_length], v5->i_cstr_p, v6 + 1);
    v2->i_str_ref_p->i_length = v7;
  }
  AString::append(v2, " <", 3u);
  v8 = resulta.i_str_ref_p;
  v9 = resulta.i_str_ref_p->i_length;
  if ( v9 )
  {
    v10 = v9 + v2->i_str_ref_p->i_length;
    if ( v10 >= v2->i_str_ref_p->i_size || v2->i_str_ref_p->i_ref_count + v2->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(v2, v10);
      v8 = resulta.i_str_ref_p;
    }
    memmove(&v2->i_str_ref_p->i_cstr_p[v2->i_str_ref_p->i_length], v8->i_cstr_p, v9 + 1);
    v2->i_str_ref_p->i_length = v10;
  }
  v11 = v2->i_str_ref_p->i_length + 1;
  if ( (unsigned int)v11 >= v2->i_str_ref_p->i_size || v2->i_str_ref_p->i_ref_count + v2->i_str_ref_p->i_read_only != 1 )
    AString::set_size(v2, v11);
  v2->i_str_ref_p->i_cstr_p[(unsigned int)(v11 - 1)] = 62;
  v2->i_str_ref_p->i_cstr_p[v11] = 0;
  v2->i_str_ref_p->i_length = v11;
  v12 = v25.i_str_ref_p;
  v13 = v25.i_str_ref_p->i_ref_count == 1;
  --v12->i_ref_count;
  if ( v13 )
  {
    if ( v12->i_deallocate )
      AMemory::c_free_func(v12->i_cstr_p);
    v14 = AStringRef::get_pool();
    v15 = v14->i_block_p;
    v16 = (unsigned __int64)v15->i_objects_a;
    if ( (unsigned __int64)v12 < v16
      || (v17 = (unsigned __int64)v12 < v16 + 24i64 * v15->i_size, v18 = &v14->i_pool, !v17) )
    {
      v18 = &v14->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v18, v12);
  }
  v19 = resulta.i_str_ref_p;
  v13 = resulta.i_str_ref_p->i_ref_count == 1;
  --v19->i_ref_count;
  if ( v13 )
  {
    if ( v19->i_deallocate )
      AMemory::c_free_func(v19->i_cstr_p);
    v20 = AStringRef::get_pool();
    v21 = v20->i_block_p;
    v22 = (unsigned __int64)v21->i_objects_a;
    if ( (unsigned __int64)v19 < v22
      || (v17 = (unsigned __int64)v19 < v22 + 24i64 * v21->i_size, v23 = &v20->i_pool, !v17) )
    {
      v23 = &v20->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v23, v19);
  }
  return v2;
}

// File Line: 341
// RVA: 0x121F50
void __fastcall SSActor::mthd_ctor_named(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSActor *v2; // rbx
  SSInstance **v3; // rdi
  SSClass *v4; // rsi
  unsigned int v5; // eax

  v2 = (SSActor *)scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v2->i_name.i_uid = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = v2->i_class_p;
  if ( v2->i_name.i_uid != ASymbol::get_null()->i_uid )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&v4[1],
      v2,
      0i64);
    if ( ((unsigned __int8 (*)(void))v4->i_superclass_p->vfptr->is_actor_class)() )
      SSActorClass::append_instance((SSActorClass *)v4->i_superclass_p, v2);
  }
  if ( !(v2->i_actor_flags & 1) )
  {
    v5 = v2->i_ptr_id;
    v2->i_actor_flags ^= 1u;
    if ( v5 )
    {
      if ( v5 <= SSObjectBase::c_ptr_id_prev && v2->i_icoroutines_to_update.i_count )
        SSActor::enable_on_update(v2, 1);
    }
  }
  if ( v3 )
  {
    ++v2->i_ref_count;
    *v3 = (SSInstance *)&v2->vfptr;
  }
}

// File Line: 371
// RVA: 0x1266D0
void __fastcall SSActor::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v2; // r8

  if ( result_pp )
  {
    v2 = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2 == (*scope_p->i_data.i_array_p)->i_data_p);
  }
}

// File Line: 394
// RVA: 0x126710
void __fastcall SSInstance::mthdc_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v2; // r8

  if ( result_pp )
  {
    v2 = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2 != (*scope_p->i_data.i_array_p)->i_data_p);
  }
}

// File Line: 416
// RVA: 0x122860
void __fastcall SSActor::mthd_get_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // rbx
  SSInstance *v4; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    if ( v4 != (SSInstance *)-32i64 )
      LODWORD(v4->i_user_data) = v3[4].i_ptr_id;
    *v2 = v4;
  }
}

// File Line: 438
// RVA: 0x122A50
void __fastcall SSActor::mthd_get_strategy_name(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  ASymbol *v3; // rdi
  SSInstance *v4; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = ASymbol::get_null();
    v4 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    if ( v4 != (SSInstance *)-32i64 )
      LODWORD(v4->i_user_data) = (ASymbol)v3->i_uid;
    *v2 = v4;
  }
}

// File Line: 484
// RVA: 0x125870
void __fastcall SSActor::mthd_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // r8
  SSActor *v4; // rcx
  AString *v5; // rdi
  SSInstance *v6; // rax
  AStringRef *v7; // rcx
  AStringRef *v8; // rbx
  bool v9; // zf
  AObjReusePool<AStringRef> *v10; // rax
  AObjBlock<AStringRef> *v11; // rcx
  unsigned __int64 v12; // rdx
  bool v13; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v14; // rcx
  AString result; // [rsp+48h] [rbp+10h]
  SSInstance *v16; // [rsp+50h] [rbp+18h]
  unsigned __int64 *v17; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p;
    v4 = (SSActor *)scope_p->i_scope_p.i_obj_p;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v5 = SSActor::as_string(v4, &result);
    v6 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v16 = v6;
    v17 = &v6->i_user_data;
    if ( v6 != (SSInstance *)-32i64 )
    {
      v7 = v5->i_str_ref_p;
      v6->i_user_data = (unsigned __int64)v5->i_str_ref_p;
      ++v7->i_ref_count;
    }
    *v2 = v6;
    v8 = result.i_str_ref_p;
    v9 = result.i_str_ref_p->i_ref_count == 1;
    --v8->i_ref_count;
    if ( v9 )
    {
      if ( v8->i_deallocate )
        AMemory::c_free_func(v8->i_cstr_p);
      v10 = AStringRef::get_pool();
      v11 = v10->i_block_p;
      v12 = (unsigned __int64)v11->i_objects_a;
      if ( (unsigned __int64)v8 < v12
        || (v13 = (unsigned __int64)v8 < v12 + 24i64 * v11->i_size, v14 = &v10->i_pool, !v13) )
      {
        v14 = &v10->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v14, v8);
    }
  }
}

// File Line: 503
// RVA: 0x126130
void __fastcall SSActor::mthdc_find_named(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSActor *v3; // rax
  SSInstance *v4; // rcx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_actor_class_p->i_instances.i_count,
           (ASymbol *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = SSBrain::c_nil_p;
    if ( v3 )
      v4 = (SSInstance *)&v3->vfptr;
    *v2 = v4;
    ++v4->i_ref_count;
  }
}

// File Line: 520
// RVA: 0x1260C0
void __fastcall SSActor::mthdc_find_instance(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rdi
  SSInvokedMethod *v3; // rbx
  __int64 v4; // rax
  signed __int64 v5; // r8
  SSActor *v6; // rax
  SSInstance *v7; // rcx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p;
    v4 = ((__int64 (*)(void))scope_p->vfptr->get_topmost_scope)();
    if ( v4 )
      v5 = v4 - 8;
    else
      v5 = 0i64;
    v6 = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(*(_QWORD *)(v5 + 56) + 304i64),
           (ASymbol *)&(*v3->i_data.i_array_p)->i_data_p->i_user_data);
    v7 = SSBrain::c_nil_p;
    if ( v6 )
      v7 = (SSInstance *)&v6->vfptr;
    *v2 = v7;
    ++v7->i_ref_count;
  }
}

// File Line: 539
// RVA: 0x126180
void __fastcall SSActor::mthdc_generate_name_str(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  AString *v3; // rdi
  SSInstance *v4; // rax
  AStringRef *v5; // rcx
  AStringRef *v6; // rbx
  bool v7; // zf
  AObjReusePool<AStringRef> *v8; // rax
  AObjBlock<AStringRef> *v9; // rcx
  unsigned __int64 v10; // rdx
  bool v11; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v12; // rcx
  AString result; // [rsp+48h] [rbp+10h]
  SSInstance *v14; // [rsp+50h] [rbp+18h]
  unsigned __int64 *v15; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = SSActor::generate_unique_name_str(
           &result,
           (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
           0i64);
    v4 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v14 = v4;
    v15 = &v4->i_user_data;
    if ( v4 != (SSInstance *)-32i64 )
    {
      v5 = v3->i_str_ref_p;
      v4->i_user_data = (unsigned __int64)v3->i_str_ref_p;
      ++v5->i_ref_count;
    }
    *v2 = v4;
    v6 = result.i_str_ref_p;
    v7 = result.i_str_ref_p->i_ref_count == 1;
    --v6->i_ref_count;
    if ( v7 )
    {
      if ( v6->i_deallocate )
        AMemory::c_free_func(v6->i_cstr_p);
      v8 = AStringRef::get_pool();
      v9 = v8->i_block_p;
      v10 = (unsigned __int64)v9->i_objects_a;
      if ( (unsigned __int64)v6 < v10
        || (v11 = (unsigned __int64)v6 < v10 + 24i64 * v9->i_size, v12 = &v8->i_pool, !v11) )
      {
        v12 = &v8->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v12, v6);
    }
  }
}

// File Line: 554
// RVA: 0x126250
void __fastcall SSActor::mthdc_generate_name_sym(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  ASymbol *v3; // rdi
  SSInstance *v4; // rax
  ASymbol result; // [rsp+48h] [rbp+10h]
  SSInstance *v6; // [rsp+50h] [rbp+18h]
  unsigned __int64 *v7; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = SSActor::generate_unique_name_sym(
           &result,
           (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
           0i64);
    v4 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    v6 = v4;
    v7 = &v4->i_user_data;
    if ( v4 != (SSInstance *)-32i64 )
      LODWORD(v4->i_user_data) = (ASymbol)v3->i_uid;
    *v2 = v4;
  }
}

// File Line: 569
// RVA: 0x1262C0
void __fastcall SSActor::mthdc_get_instance(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // rdi
  __int64 v4; // rax
  signed __int64 v5; // rax
  __int64 v6; // rcx
  SSActor *v7; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = (*scope_p->i_data.i_array_p)->i_data_p;
    v4 = ((__int64 (*)(void))scope_p->vfptr->get_topmost_scope)();
    if ( v4 && (v5 = v4 - 8) != 0 && (v6 = *(_QWORD *)(v5 + 56)) != 0 )
    {
      v7 = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)(v6 + 304),
             (ASymbol *)&v3->i_user_data);
      ++v7->i_ref_count;
      *v2 = (SSInstance *)&v7->vfptr;
    }
    else
    {
      ++MEMORY[0x10];
      *v2 = 0i64;
    }
  }
}

// File Line: 601
// RVA: 0x126370
void __fastcall SSActor::mthdc_get_instance_first(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  __int64 v3; // rax
  SSInstance *v4; // rcx
  signed __int64 v5; // rax
  __int64 v6; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = ((__int64 (*)(void))scope_p->vfptr->get_topmost_scope)();
    v4 = 0i64;
    if ( v3 )
      v5 = v3 - 8;
    else
      v5 = 0i64;
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 56);
      if ( v6 )
      {
        if ( *(_DWORD *)(v6 + 304) )
          v4 = **(SSInstance ***)(v6 + 312);
      }
    }
    ++v4->i_ref_count;
    *v2 = v4;
  }
}

// File Line: 637
// RVA: 0x126330
void __fastcall SSActor::mthdc_get_instance_count(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  __int64 v3; // rax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = ((__int64 (*)(void))scope_p->vfptr->get_topmost_scope)();
    if ( v3 )
      v3 -= 8i64;
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)(*(_QWORD *)(v3 + 56) + 304i64));
  }
}

// File Line: 654
// RVA: 0x1263C0
void __fastcall SSActor::mthdc_get_instances(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // r14
  __int64 v3; // rax
  signed __int64 v4; // rax
  APArrayBase<SSInstance> *v5; // rsi
  unsigned int v6; // ebx
  SSList *v7; // rax
  SSList *v8; // rdi
  SSInstance **v9; // rax
  __int64 v10; // rax
  ARefCountMix<SSInstance> **v11; // rbx
  unsigned __int64 i; // rsi

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = ((__int64 (__cdecl *)(SSInvokedMethod *))scope_p->vfptr->get_topmost_scope)(scope_p);
    if ( v3 )
      v4 = v3 - 8;
    else
      v4 = 0i64;
    v5 = *(APArrayBase<SSInstance> **)(v4 + 56);
    v6 = v5[19].i_count;
    v7 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v8 = v7;
    if ( v7 )
    {
      v7->i_items.i_count = 0;
      v7->i_items.i_array_p = 0i64;
      v7->i_items.i_size = 0;
      if ( v6 )
      {
        v7->i_items.i_size = v6;
        v9 = APArrayBase<SSInstance>::alloc_array(v6);
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
      v11 = (ARefCountMix<SSInstance> **)v8->i_items.i_array_p;
      for ( i = (unsigned __int64)&v11[v10]; (unsigned __int64)v11 < i; ++v11 )
        UFG::PersistentData::MapFloat::Iterator::Next(*v11 + 4);
    }
    *v2 = SSList::as_instance(v8);
  }
}

// File Line: 679
// RVA: 0x132030
void SSActor::register_atomic(void)
{
  unsigned int v0; // eax
  SSActor **v1; // rbx
  unsigned int v2; // eax
  SSActor **v3; // rbx
  SSActorClass *v4; // rbx
  ASymbol *v5; // rax
  signed __int64 v6; // rdx
  __int64 v7; // r9
  SSMethodBase **v8; // r8
  __int64 v9; // rax
  signed __int64 v10; // r10
  _BOOL8 v11; // rcx
  __int64 v12; // rdi
  __int64 v13; // r15
  SSParameters *v14; // rsi
  SSParameters *v15; // r14
  bool v16; // zf
  SSMethodBase **v17; // r8
  __int64 v18; // rax
  signed __int64 v19; // r10
  _BOOL8 v20; // rcx
  __int64 v21; // rdi
  __int64 v22; // r15
  SSParameters *v23; // rsi
  SSParameters *v24; // r14
  SSMethodBase **v25; // r8
  __int64 v26; // rax
  signed __int64 v27; // r10
  _BOOL8 v28; // rcx
  __int64 v29; // rdi
  __int64 v30; // r15
  SSParameters *v31; // rsi
  SSParameters *v32; // r14
  SSMethodBase **v33; // r8
  __int64 v34; // rax
  signed __int64 v35; // r10
  _BOOL8 v36; // rcx
  __int64 v37; // rdi
  __int64 v38; // r15
  SSParameters *v39; // rsi
  SSParameters *v40; // r14
  SSMethodBase **v41; // r8
  __int64 v42; // rax
  signed __int64 v43; // r10
  _BOOL8 v44; // rcx
  __int64 v45; // rdi
  __int64 v46; // r15
  SSParameters *v47; // rsi
  SSParameters *v48; // r14
  SSMethodBase **v49; // r8
  __int64 v50; // rax
  signed __int64 v51; // r10
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
  signed __int64 v71; // [rsp+20h] [rbp-10h]
  ASymbol result; // [rsp+70h] [rbp+40h]
  SSParameters *v73; // [rsp+78h] [rbp+48h]
  __int64 v74; // [rsp+80h] [rbp+50h]

  v71 = -2i64;
  if ( SSActor::c_update_actors.i_size < 0x200 )
  {
    v0 = AMemory::c_req_byte_size_func(0x1000u) >> 3;
    SSActor::c_update_actors.i_size = v0;
    if ( SSActor::c_update_actors.i_count )
    {
      v1 = SSActor::c_update_actors.i_array_p;
      SSActor::c_update_actors.i_array_p = APArrayBase<SSActor>::alloc_array(v0);
      memmove(SSActor::c_update_actors.i_array_p, v1, 8i64 * SSActor::c_update_actors.i_count);
      AMemory::c_free_func(v1);
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
  v5 = ASymbol::create(&result, "!named", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func((SSClass *)&v4->vfptr, v5, SSActor::mthd_ctor_named, 0);
  v8 = (SSMethodBase **)SSBrain::c_actor_class_p;
  v9 = SSBrain::c_actor_class_p->i_methods.i_count;
  if ( (_DWORD)v9 )
  {
    v8 = SSBrain::c_actor_class_p->i_methods.i_array_p;
    v10 = (signed __int64)&v8[v9 - 1];
    while ( 1 )
    {
      v6 = (signed __int64)&v8[(v10 - (signed __int64)v8) >> 4];
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 8i64);
      if ( ASymbol_String.i_uid < (unsigned int)v7 )
        goto LABEL_162;
      v11 = ASymbol_String.i_uid == (_DWORD)v7;
      v7 = ASymbol_String.i_uid != (_DWORD)v7;
      if ( v11 == 1 )
      {
        v12 = *(_QWORD *)v6;
        goto LABEL_20;
      }
      if ( v7 < 0 )
      {
LABEL_162:
        if ( v8 == (SSMethodBase **)v6 )
          break;
        v10 = v6 - 8;
      }
      else
      {
        if ( v10 == v6 )
          break;
        v8 = (SSMethodBase **)(v6 + 8);
      }
    }
  }
  v12 = 0i64;
LABEL_20:
  *(_QWORD *)&result.i_uid = v12;
  if ( v12 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v12 + 16i64))(
           v12,
           v6,
           v8,
           v7,
           -2i64) == 1 )
    {
      *(_QWORD *)(v12 + 32) = SSActor::mthd_string;
    }
    else
    {
      v13 = *(_QWORD *)(v12 + 16);
      v14 = *(SSParameters **)(v12 + 24);
      v73 = v14;
      if ( v14 )
        ++v14->i_ref_count;
      v15 = *(SSParameters **)(v12 + 24);
      if ( v15 )
      {
        v16 = v15->i_ref_count-- == 1;
        if ( v16 )
        {
          v15->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v15);
          AMemory::c_free_func(v15);
        }
        *(_QWORD *)(v12 + 24) = 0i64;
      }
      v74 = v12;
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
          v14->i_ref_count = 2147483648;
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
    v19 = (signed __int64)&v17[v18 - 1];
    while ( 1 )
    {
      v6 = (signed __int64)&v17[(v19 - (signed __int64)v17) >> 4];
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 8i64);
      if ( ASymbol_equals.i_uid < (unsigned int)v7 )
        goto LABEL_163;
      v20 = ASymbol_equals.i_uid == (_DWORD)v7;
      v7 = ASymbol_equals.i_uid != (_DWORD)v7;
      if ( v20 == 1 )
      {
        v21 = *(_QWORD *)v6;
        goto LABEL_45;
      }
      if ( v7 < 0 )
      {
LABEL_163:
        if ( v17 == (SSMethodBase **)v6 )
          break;
        v19 = v6 - 8;
      }
      else
      {
        if ( v19 == v6 )
          break;
        v17 = (SSMethodBase **)(v6 + 8);
      }
    }
  }
  v21 = 0i64;
LABEL_45:
  *(_QWORD *)&result.i_uid = v21;
  if ( v21 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v21 + 16i64))(
           v21,
           v6,
           v17,
           v7,
           v71) == 1 )
    {
      *(_QWORD *)(v21 + 32) = SSActor::mthd_op_equals;
    }
    else
    {
      v22 = *(_QWORD *)(v21 + 16);
      v23 = *(SSParameters **)(v21 + 24);
      v73 = v23;
      if ( v23 )
        ++v23->i_ref_count;
      v24 = *(SSParameters **)(v21 + 24);
      if ( v24 )
      {
        v16 = v24->i_ref_count-- == 1;
        if ( v16 )
        {
          v24->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v24);
          AMemory::c_free_func(v24);
        }
        *(_QWORD *)(v21 + 24) = 0i64;
      }
      v74 = v21;
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
          v23->i_ref_count = 2147483648;
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
    v27 = (signed __int64)&v25[v26 - 1];
    while ( 1 )
    {
      v6 = (signed __int64)&v25[(v27 - (signed __int64)v25) >> 4];
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 8i64);
      if ( ASymbol_get_name.i_uid < (unsigned int)v7 )
        goto LABEL_164;
      v28 = ASymbol_get_name.i_uid == (_DWORD)v7;
      v7 = ASymbol_get_name.i_uid != (_DWORD)v7;
      if ( v28 == 1 )
      {
        v29 = *(_QWORD *)v6;
        goto LABEL_70;
      }
      if ( v7 < 0 )
      {
LABEL_164:
        if ( v25 == (SSMethodBase **)v6 )
          break;
        v27 = v6 - 8;
      }
      else
      {
        if ( v27 == v6 )
          break;
        v25 = (SSMethodBase **)(v6 + 8);
      }
    }
  }
  v29 = 0i64;
LABEL_70:
  *(_QWORD *)&result.i_uid = v29;
  if ( v29 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v29 + 16i64))(
           v29,
           v6,
           v25,
           v7,
           v71) == 1 )
    {
      *(_QWORD *)(v29 + 32) = SSActor::mthd_get_name;
    }
    else
    {
      v30 = *(_QWORD *)(v29 + 16);
      v31 = *(SSParameters **)(v29 + 24);
      v73 = v31;
      if ( v31 )
        ++v31->i_ref_count;
      v32 = *(SSParameters **)(v29 + 24);
      if ( v32 )
      {
        v16 = v32->i_ref_count-- == 1;
        if ( v16 )
        {
          v32->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v32);
          AMemory::c_free_func(v32);
        }
        *(_QWORD *)(v29 + 24) = 0i64;
      }
      v74 = v29;
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
          v31->i_ref_count = 2147483648;
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
    v35 = (signed __int64)&v33[v34 - 1];
    while ( 1 )
    {
      v6 = (signed __int64)&v33[(v35 - (signed __int64)v33) >> 4];
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 8i64);
      if ( ASymbol_get_strategy_name.i_uid < (unsigned int)v7 )
        goto LABEL_165;
      v36 = ASymbol_get_strategy_name.i_uid == (_DWORD)v7;
      v7 = ASymbol_get_strategy_name.i_uid != (_DWORD)v7;
      if ( v36 == 1 )
      {
        v37 = *(_QWORD *)v6;
        goto LABEL_95;
      }
      if ( v7 < 0 )
      {
LABEL_165:
        if ( v33 == (SSMethodBase **)v6 )
          break;
        v35 = v6 - 8;
      }
      else
      {
        if ( v35 == v6 )
          break;
        v33 = (SSMethodBase **)(v6 + 8);
      }
    }
  }
  v37 = 0i64;
LABEL_95:
  *(_QWORD *)&result.i_uid = v37;
  if ( v37 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v37 + 16i64))(
           v37,
           v6,
           v33,
           v7,
           v71) == 1 )
    {
      *(_QWORD *)(v37 + 32) = SSActor::mthd_get_strategy_name;
    }
    else
    {
      v38 = *(_QWORD *)(v37 + 16);
      v39 = *(SSParameters **)(v37 + 24);
      v73 = v39;
      if ( v39 )
        ++v39->i_ref_count;
      v40 = *(SSParameters **)(v37 + 24);
      if ( v40 )
      {
        v16 = v40->i_ref_count-- == 1;
        if ( v16 )
        {
          v40->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v40);
          AMemory::c_free_func(v40);
        }
        *(_QWORD *)(v37 + 24) = 0i64;
      }
      v74 = v37;
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
          v39->i_ref_count = 2147483648;
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
    v43 = (signed __int64)&v41[v42 - 1];
    while ( 1 )
    {
      v6 = (signed __int64)&v41[(v43 - (signed __int64)v41) >> 4];
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 8i64);
      if ( ASymbol_not_equal.i_uid < (unsigned int)v7 )
        goto LABEL_166;
      v44 = ASymbol_not_equal.i_uid == (_DWORD)v7;
      v7 = ASymbol_not_equal.i_uid != (_DWORD)v7;
      if ( v44 == 1 )
      {
        v45 = *(_QWORD *)v6;
        goto LABEL_120;
      }
      if ( v7 < 0 )
      {
LABEL_166:
        if ( v41 == (SSMethodBase **)v6 )
          break;
        v43 = v6 - 8;
      }
      else
      {
        if ( v43 == v6 )
          break;
        v41 = (SSMethodBase **)(v6 + 8);
      }
    }
  }
  v45 = 0i64;
LABEL_120:
  *(_QWORD *)&result.i_uid = v45;
  if ( v45 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v45 + 16i64))(
           v45,
           v6,
           v41,
           v7,
           v71) == 1 )
    {
      *(_QWORD *)(v45 + 32) = SSInstance::mthdc_op_not_equal;
    }
    else
    {
      v46 = *(_QWORD *)(v45 + 16);
      v47 = *(SSParameters **)(v45 + 24);
      v73 = v47;
      if ( v47 )
        ++v47->i_ref_count;
      v48 = *(SSParameters **)(v45 + 24);
      if ( v48 )
      {
        v16 = v48->i_ref_count-- == 1;
        if ( v16 )
        {
          v48->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v48);
          AMemory::c_free_func(v48);
        }
        *(_QWORD *)(v45 + 24) = 0i64;
      }
      v74 = v45;
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
          v47->i_ref_count = 2147483648;
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
    v51 = (signed __int64)&v49[v50 - 1];
    while ( 1 )
    {
      v6 = (signed __int64)&v49[(v51 - (signed __int64)v49) >> 4];
      v7 = *(unsigned int *)(*(_QWORD *)v6 + 8i64);
      if ( ASymbol_set_strategy.i_uid < (unsigned int)v7 )
        goto LABEL_167;
      v52 = ASymbol_set_strategy.i_uid == (_DWORD)v7;
      v7 = ASymbol_set_strategy.i_uid != (_DWORD)v7;
      if ( v52 == 1 )
      {
        v53 = *(_QWORD *)v6;
        goto LABEL_145;
      }
      if ( v7 < 0 )
      {
LABEL_167:
        if ( v49 == (SSMethodBase **)v6 )
          break;
        v51 = v6 - 8;
      }
      else
      {
        if ( v51 == v6 )
          break;
        v49 = (SSMethodBase **)(v6 + 8);
      }
    }
  }
  v53 = 0i64;
LABEL_145:
  *(_QWORD *)&result.i_uid = v53;
  if ( v53 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v53 + 16i64))(
           v53,
           v6,
           v49,
           v7,
           v71) == 1 )
    {
      *(_QWORD *)(v53 + 32) = UFG::TSAudio::MthdC_get_named;
    }
    else
    {
      v54 = *(_QWORD *)(v53 + 16);
      v55 = *(SSParameters **)(v53 + 24);
      v73 = v55;
      if ( v55 )
        ++v55->i_ref_count;
      v56 = *(SSParameters **)(v53 + 24);
      if ( v56 )
      {
        v16 = v56->i_ref_count-- == 1;
        if ( v16 )
        {
          v56->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v56);
          AMemory::c_free_func(v56);
        }
        *(_QWORD *)(v53 + 24) = 0i64;
      }
      v74 = v53;
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
          v55->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v55);
          AMemory::c_free_func(v55);
        }
      }
    }
  }
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_actor_class_p->vfptr,
    &ASymbol_find_named,
    SSActor::mthdc_find_named,
    SSBindFlag_class_no_rebind);
  v57 = SSBrain::c_actor_class_p;
  v58 = ASymbol::create(&result, "find_instance", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func((SSClass *)&v57->vfptr, v58, SSActor::mthdc_find_instance, SSBindFlag_class_no_rebind);
  v59 = SSBrain::c_actor_class_p;
  v60 = ASymbol::create(&result, "generate_name_str", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    (SSClass *)&v59->vfptr,
    v60,
    SSActor::mthdc_generate_name_str,
    SSBindFlag_class_no_rebind);
  v61 = SSBrain::c_actor_class_p;
  v62 = ASymbol::create(&result, "generate_name_sym", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    (SSClass *)&v61->vfptr,
    v62,
    SSActor::mthdc_generate_name_sym,
    SSBindFlag_class_no_rebind);
  v63 = SSBrain::c_actor_class_p;
  v64 = ASymbol::create(&result, "get_instance", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func((SSClass *)&v63->vfptr, v64, SSActor::mthdc_get_instance, SSBindFlag_class_no_rebind);
  v65 = SSBrain::c_actor_class_p;
  v66 = ASymbol::create(&result, "get_instance_first", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    (SSClass *)&v65->vfptr,
    v66,
    SSActor::mthdc_get_instance_first,
    SSBindFlag_class_no_rebind);
  v67 = SSBrain::c_actor_class_p;
  v68 = ASymbol::create(&result, "get_instance_count", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    (SSClass *)&v67->vfptr,
    v68,
    SSActor::mthdc_get_instance_count,
    SSBindFlag_class_no_rebind);
  v69 = SSBrain::c_actor_class_p;
  v70 = ASymbol::create(&result, "get_instances", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func((SSClass *)&v69->vfptr, v70, SSActor::mthdc_get_instances, SSBindFlag_class_no_rebind);
}Class::register_method_func((SSClass *)&v69->vfptr, v70, SSActor::mthdc_get_instances, SSBindFlag_class_no_rebind);
}

// File Line: 708
// RVA: 0x112B00
void __fastcall SSActor::coroutine_track(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  SSInvokedCoroutine *v2; // rbx
  SSActor *v3; // rdi

  v2 = icoro_p;
  v3 = this;
  if ( icoro_p->i_pending_count )
  {
    if ( !(icoro_p->i_flags & 2) )
    {
      APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
        &this->i_icoroutines_pending,
        icoro_p);
      v2->i_flags |= 2u;
    }
    SSActor::coroutine_track_updating_stop(v3, v2);
  }
  else
  {
    if ( !(icoro_p->i_flags & 1) )
    {
      APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
        &this->i_icoroutines_to_update,
        icoro_p);
      v2->i_flags |= 1u;
      if ( !(v3->i_actor_flags & 2) )
        SSActor::enable_on_update(v3, 1);
    }
    SSActor::coroutine_track_pending_stop(v3, v2);
  }
}

// File Line: 727
// RVA: 0x112C20
void __fastcall SSActor::coroutine_track_updating(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  SSInvokedCoroutine *v2; // rbx
  SSActor *v3; // rdi

  v2 = icoro_p;
  v3 = this;
  if ( !(icoro_p->i_flags & 1) )
  {
    APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
      &this->i_icoroutines_to_update,
      icoro_p);
    v2->i_flags |= 1u;
    if ( !(v3->i_actor_flags & 2) )
      SSActor::enable_on_update(v3, 1);
  }
}

// File Line: 746
// RVA: 0x112C70
void __fastcall SSActor::coroutine_track_updating_stop(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  SSInvokedCoroutine *v2; // rdi
  SSActor *v3; // rsi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // er8
  SSInvokedCoroutine **v7; // r9
  __int64 v8; // r10
  unsigned __int64 v9; // rcx
  SSInvokedCoroutine **v10; // rdx
  __int64 v11; // r8
  SSInvokedCoroutine **v12; // rdx
  SSInvokedCoroutine **v13; // rax

  v2 = icoro_p;
  v3 = this;
  if ( !(icoro_p->i_flags & 1) )
    return;
  v4 = this->i_icoroutines_to_update.i_count;
  v5 = 0;
  v6 = 0;
  if ( !v4 )
    goto LABEL_10;
  v7 = this->i_icoroutines_to_update.i_array_p;
  v8 = v4 - 1;
  v9 = (unsigned __int64)&v7[v8];
  v10 = v7;
  if ( (unsigned __int64)v7 > v9 )
    goto LABEL_10;
  while ( v2 != *v10 )
  {
LABEL_7:
    ++v10;
    if ( (unsigned __int64)v10 > v9 )
      goto LABEL_10;
  }
  if ( v6 >= 2 )
  {
    --v6;
    goto LABEL_7;
  }
  v3->i_icoroutines_to_update.i_count = v8;
  memmove(
    &v7[(unsigned int)(v10 - v7)],
    &v7[(unsigned int)(v10 - v7) + 1],
    8i64 * ((unsigned int)v8 - (unsigned int)(v10 - v7)));
LABEL_10:
  v2->i_flags &= 0xFFFFFFFE;
  if ( v3->i_actor_flags & 8 )
  {
    if ( SSActor::c_icoroutines_updating.i_count )
    {
      v11 = SSActor::c_icoroutines_updating.i_count - 1;
      v12 = &SSActor::c_icoroutines_updating.i_array_p[v11];
      v13 = SSActor::c_icoroutines_updating.i_array_p;
      if ( SSActor::c_icoroutines_updating.i_array_p <= v12 )
      {
        do
        {
          if ( v2 == *v13 )
          {
            if ( v5 < 2 )
            {
              SSActor::c_icoroutines_updating.i_count = v11;
              memmove(
                &SSActor::c_icoroutines_updating.i_array_p[(unsigned int)(v13 - SSActor::c_icoroutines_updating.i_array_p)],
                &SSActor::c_icoroutines_updating.i_array_p[(unsigned int)(v13 - SSActor::c_icoroutines_updating.i_array_p)
                                                         + 1],
                8i64 * ((unsigned int)v11 - (unsigned int)(v13 - SSActor::c_icoroutines_updating.i_array_p)));
              return;
            }
            --v5;
          }
          ++v13;
        }
        while ( v13 <= v12 );
      }
    }
  }
}

// File Line: 777
// RVA: 0x112B90
void __fastcall SSActor::coroutine_track_pending_stop(SSActor *this, SSInvokedCoroutine *icoro_p)
{
  SSInvokedCoroutine *v2; // rbx
  unsigned int v3; // eax
  unsigned int v4; // er8
  SSInvokedCoroutine **v5; // r11
  __int64 v6; // r10
  unsigned __int64 v7; // rdx
  SSInvokedCoroutine **v8; // rax

  v2 = icoro_p;
  if ( icoro_p->i_flags & 2 )
  {
    v3 = this->i_icoroutines_pending.i_count;
    v4 = 0;
    if ( v3 )
    {
      v5 = this->i_icoroutines_pending.i_array_p;
      v6 = v3 - 1;
      v7 = (unsigned __int64)&v5[v6];
      v8 = this->i_icoroutines_pending.i_array_p;
      if ( (unsigned __int64)v5 <= v7 )
      {
        while ( 1 )
        {
          if ( v2 == *v8 )
          {
            if ( v4 < 2 )
            {
              this->i_icoroutines_pending.i_count = v6;
              memmove(
                &v5[(unsigned int)(v8 - v5)],
                &v5[(unsigned int)(v8 - v5) + 1],
                8i64 * ((unsigned int)v6 - (unsigned int)(v8 - v5)));
              break;
            }
            --v4;
          }
          ++v8;
          if ( (unsigned __int64)v8 > v7 )
          {
            v2->i_flags &= 0xFFFFFFFD;
            return;
          }
        }
      }
    }
    v2->i_flags &= 0xFFFFFFFD;
  }
}

// File Line: 790
// RVA: 0x111F20
void __fastcall SSActor::clear_coroutines(SSActor *this)
{
  unsigned int v1; // eax
  SSActor *v2; // rbp
  unsigned int v3; // eax
  unsigned int v4; // eax
  SSInvokedCoroutine *i; // rsi
  unsigned int v6; // eax
  AList<SSInvokedBase,SSInvokedBase> *v7; // rbx
  signed int v8; // edi
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // rax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  SSInvokedCoroutine *j; // rsi
  unsigned int v18; // eax
  AList<SSInvokedBase,SSInvokedBase> *v19; // rbx
  signed int v20; // edi
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v23; // rax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax

  v1 = SSActor::c_icoroutines_updating.i_count;
  if ( this->i_actor_flags & 8 )
    v1 = 0;
  v2 = this;
  SSActor::c_icoroutines_updating.i_count = v1;
  v3 = this->i_icoroutines_pending.i_count;
  if ( v3 )
  {
    v4 = v3 - 1;
    this->i_icoroutines_pending.i_count = v4;
    for ( i = this->i_icoroutines_pending.i_array_p[v4]; i; i = v2->i_icoroutines_pending.i_array_p[v14] )
    {
      v6 = i->i_ptr_id;
      if ( v6 && v6 <= SSObjectBase::c_ptr_id_prev )
      {
        i->i_flags &= 0xFFFFFFFD;
        i->i_pending_count = 0;
        if ( v6 <= SSObjectBase::c_ptr_id_prev )
        {
          v7 = &i->i_calls;
          v8 = 0;
          if ( (AList<SSInvokedBase,SSInvokedBase> *)v7->i_sentinel.i_next_p == v7 )
            goto LABEL_38;
          do
          {
            v9 = v7->i_sentinel.i_next_p;
            v10 = v7->i_sentinel.i_next_p->i_next_p;
            v11 = v7->i_sentinel.i_next_p->i_prev_p;
            v10->i_prev_p = v11;
            v11->i_next_p = v10;
            v9->i_prev_p = v9;
            v9->i_next_p = v9;
            v12 = (unsigned int)v9[-1].i_prev_p;
            if ( v12 && v12 <= SSObjectBase::c_ptr_id_prev )
              ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, signed __int64))v9[-1].i_next_p[5].i_prev_p)(
                &v9[-1].i_next_p,
                0i64,
                1i64);
            --v8;
          }
          while ( (AList<SSInvokedBase,SSInvokedBase> *)v7->i_sentinel.i_next_p != v7 );
          if ( v8 <= 0 )
LABEL_38:
            i->i_pending_count = 0;
          else
            i->i_pending_count = v8;
        }
        SSInvokedCoroutine::pool_delete(i);
      }
      v13 = v2->i_icoroutines_pending.i_count;
      if ( !v13 )
        break;
      v14 = v13 - 1;
      v2->i_icoroutines_pending.i_count = v14;
    }
  }
  v15 = v2->i_icoroutines_to_update.i_count;
  if ( v15 )
  {
    v16 = v15 - 1;
    v2->i_icoroutines_to_update.i_count = v16;
    for ( j = v2->i_icoroutines_to_update.i_array_p[v16]; j; j = v2->i_icoroutines_to_update.i_array_p[v26] )
    {
      v18 = j->i_ptr_id;
      if ( v18 && v18 <= SSObjectBase::c_ptr_id_prev )
      {
        j->i_flags &= 0xFFFFFFFE;
        j->i_pending_count = 0;
        if ( v18 <= SSObjectBase::c_ptr_id_prev )
        {
          v19 = &j->i_calls;
          v20 = 0;
          if ( (AList<SSInvokedBase,SSInvokedBase> *)v19->i_sentinel.i_next_p == v19 )
            goto LABEL_39;
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
              ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, signed __int64))v21[-1].i_next_p[5].i_prev_p)(
                &v21[-1].i_next_p,
                0i64,
                1i64);
            --v20;
          }
          while ( (AList<SSInvokedBase,SSInvokedBase> *)v19->i_sentinel.i_next_p != v19 );
          if ( v20 <= 0 )
LABEL_39:
            j->i_pending_count = 0;
          else
            j->i_pending_count = v20;
        }
        SSInvokedCoroutine::pool_delete(j);
      }
      v25 = v2->i_icoroutines_to_update.i_count;
      if ( !v25 )
        break;
      v26 = v25 - 1;
      v2->i_icoroutines_to_update.i_count = v26;
    }
  }
  SSActor::enable_on_update(v2, 0);
}

// File Line: 855
// RVA: 0x13CD50
void __fastcall SSActor::suspend_coroutines(SSActor *this)
{
  __int64 v1; // rax
  SSActor *v2; // rsi
  SSInvokedCoroutine **v3; // rbx
  unsigned __int64 i; // rdi
  __int64 v5; // rax
  SSInvokedCoroutine **v6; // rbx
  unsigned __int64 j; // rdi

  v1 = this->i_icoroutines_pending.i_count;
  v2 = this;
  if ( (_DWORD)v1 )
  {
    v3 = this->i_icoroutines_pending.i_array_p;
    for ( i = (unsigned __int64)&v3[v1]; (unsigned __int64)v3 < i; ++v3 )
      SSInvokedCoroutine::suspend(*v3);
  }
  v5 = v2->i_icoroutines_to_update.i_count;
  if ( (_DWORD)v5 )
  {
    v6 = v2->i_icoroutines_to_update.i_array_p;
    for ( j = (unsigned __int64)&v6[v5]; (unsigned __int64)v6 < j; ++v6 )
      SSInvokedCoroutine::suspend(*v6);
  }
}

// File Line: 880
// RVA: 0x114D00
SSActor *__fastcall SSActor::find(ASymbol *actor_name)
{
  return APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_actor_class_p->i_instances.i_count,
           actor_name);
}

// File Line: 907
// RVA: 0x116DD0
AString *__fastcall SSActor::generate_unique_name_str(AString *result, AString *name_root, unsigned int *create_idx_p)
{
  unsigned int *v3; // r12
  const void ***v4; // rdi
  AString *v5; // rsi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  const char *v8; // rax
  AStringRef *v9; // rax
  __int64 v10; // rbp
  unsigned int v11; // er15
  AStringRef *v12; // rdx
  signed __int64 v13; // rax
  const void ***v14; // r14
  int v15; // edi
  unsigned int v16; // ebx
  AStringRef *v17; // rbx
  bool v18; // zf
  AObjReusePool<AStringRef> *v19; // rax
  AObjBlock<AStringRef> *v20; // rcx
  unsigned __int64 v21; // rdx
  bool v22; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v23; // rcx
  ASymbol *v24; // rax
  __int64 v25; // rcx
  SSActor **v26; // rdx
  signed __int64 v27; // r9
  unsigned int v28; // er10
  signed __int64 v29; // rax
  unsigned int v30; // er8
  _BOOL8 v31; // r8
  ASymbol v33; // [rsp+88h] [rbp+10h]
  AString resulta; // [rsp+90h] [rbp+18h]

  v3 = create_idx_p;
  v4 = (const void ***)name_root;
  v5 = result;
  v6 = AMemory::c_req_byte_size_func(name_root->i_str_ref_p->i_length + 4);
  v7 = v6;
  v8 = (const char *)AMemory::c_malloc_func(v6, "AStringRef.buffer");
  v9 = AStringRef::pool_new(v8, *((_DWORD *)*v4 + 2), v7, 1u, 1, 0);
  v5->i_str_ref_p = v9;
  memmove(v9->i_cstr_p, **v4, v9->i_length + 1);
  v10 = *((unsigned int *)*v4 + 2);
  v11 = 0;
  do
  {
    ++v11;
    v12 = v5->i_str_ref_p;
    if ( (_DWORD)v10 == -1 )
    {
      v13 = -1i64;
      do
        ++v13;
      while ( v12->i_cstr_p[v13] );
      v12->i_length = v13;
    }
    else if ( v12->i_length != (_DWORD)v10 || v12->i_cstr_p[v10] )
    {
      if ( (unsigned int)v10 >= v12->i_size || v12->i_ref_count + v12->i_read_only != 1 )
        AString::set_size(v5, v10);
      v5->i_str_ref_p->i_length = v10;
      v5->i_str_ref_p->i_cstr_p[v5->i_str_ref_p->i_length] = 0;
    }
    v14 = (const void ***)AString::ctor_uint(&resulta, v11, 0xAu);
    v15 = *((_DWORD *)*v14 + 2);
    if ( v15 )
    {
      v16 = v15 + v5->i_str_ref_p->i_length;
      if ( v16 >= v5->i_str_ref_p->i_size || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
        AString::set_size(v5, v16);
      memmove(&v5->i_str_ref_p->i_cstr_p[v5->i_str_ref_p->i_length], **v14, (unsigned int)(v15 + 1));
      v5->i_str_ref_p->i_length = v16;
    }
    v17 = resulta.i_str_ref_p;
    v18 = resulta.i_str_ref_p->i_ref_count == 1;
    --v17->i_ref_count;
    if ( v18 )
    {
      if ( v17->i_deallocate )
        AMemory::c_free_func(v17->i_cstr_p);
      v19 = AStringRef::get_pool();
      v20 = v19->i_block_p;
      v21 = (unsigned __int64)v20->i_objects_a;
      if ( (unsigned __int64)v17 < v21
        || (v22 = (unsigned __int64)v17 < v21 + 24i64 * v20->i_size, v23 = &v19->i_pool, !v22) )
      {
        v23 = &v19->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v23, v17);
    }
    v24 = ASymbol::create(&v33, v5, ATerm_long);
    v25 = SSBrain::c_actor_class_p->i_instances.i_count;
    if ( !(_DWORD)v25 )
      break;
    v26 = SSBrain::c_actor_class_p->i_instances.i_array_p;
    v27 = (signed __int64)&v26[v25 - 1];
    v28 = v24->i_uid;
    while ( 1 )
    {
      v29 = (signed __int64)&v26[(v27 - (signed __int64)v26) >> 4];
      v30 = *(_DWORD *)(*(_QWORD *)v29 + 72i64);
      if ( v28 < v30 )
        goto LABEL_31;
      v31 = v28 != v30;
      if ( !v31 )
        break;
      if ( v31 < 0 )
      {
LABEL_31:
        if ( v26 == (SSActor **)v29 )
          goto LABEL_34;
        v27 = v29 - 8;
      }
      else
      {
        if ( v27 == v29 )
          goto LABEL_34;
        v26 = (SSActor **)(v29 + 8);
      }
    }
  }
  while ( *(_QWORD *)v29 );
LABEL_34:
  if ( v3 )
    *v3 = v11;
  return v5;
}

// File Line: 954
// RVA: 0x117040
ASymbol *__fastcall SSActor::generate_unique_name_sym(ASymbol *result, AString *name_root, unsigned int *create_idx_p)
{
  unsigned int *v3; // r12
  const void ***v4; // rdi
  ASymbol *v5; // r15
  unsigned int v6; // eax
  unsigned int v7; // ebx
  const char *v8; // rax
  __int64 v9; // rdi
  unsigned int v10; // ebp
  AStringRef *v11; // rax
  signed __int64 v12; // rcx
  const void ***v13; // r14
  int v14; // esi
  AStringRef *v15; // rcx
  unsigned int v16; // ebx
  AStringRef *v17; // rbx
  bool v18; // zf
  AObjReusePool<AStringRef> *v19; // rax
  AObjBlock<AStringRef> *v20; // rcx
  unsigned __int64 v21; // rdx
  bool v22; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v23; // rcx
  ASymbol *v24; // rax
  unsigned int v25; // er10
  __int64 v26; // rax
  SSActor **v27; // rdx
  signed __int64 v28; // r9
  signed __int64 v29; // rax
  unsigned int v30; // er8
  _BOOL8 v31; // r8
  AStringRef *v32; // rbx
  AObjReusePool<AStringRef> *v33; // rax
  AObjBlock<AStringRef> *v34; // rcx
  unsigned __int64 v35; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v36; // rcx
  ASymbol v38; // [rsp+80h] [rbp+8h]
  AString str; // [rsp+88h] [rbp+10h]
  AString resulta; // [rsp+90h] [rbp+18h]

  v3 = create_idx_p;
  v4 = (const void ***)name_root;
  v5 = result;
  result->i_uid = -1;
  v6 = AMemory::c_req_byte_size_func(name_root->i_str_ref_p->i_length + 4);
  v7 = v6;
  v8 = (const char *)AMemory::c_malloc_func(v6, "AStringRef.buffer");
  str.i_str_ref_p = AStringRef::pool_new(v8, *((_DWORD *)*v4 + 2), v7, 1u, 1, 0);
  memmove(str.i_str_ref_p->i_cstr_p, **v4, str.i_str_ref_p->i_length + 1);
  v9 = *((unsigned int *)*v4 + 2);
  v10 = 0;
  do
  {
    ++v10;
    v11 = str.i_str_ref_p;
    if ( (_DWORD)v9 == -1 )
    {
      v12 = -1i64;
      do
        ++v12;
      while ( str.i_str_ref_p->i_cstr_p[v12] );
      str.i_str_ref_p->i_length = v12;
    }
    else if ( str.i_str_ref_p->i_length != (_DWORD)v9 || str.i_str_ref_p->i_cstr_p[v9] )
    {
      if ( (unsigned int)v9 >= str.i_str_ref_p->i_size
        || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v9);
        v11 = str.i_str_ref_p;
      }
      v11->i_length = v9;
      str.i_str_ref_p->i_cstr_p[v9] = 0;
    }
    v13 = (const void ***)AString::ctor_uint(&resulta, v10, 0xAu);
    v14 = *((_DWORD *)*v13 + 2);
    if ( v14 )
    {
      v15 = str.i_str_ref_p;
      v16 = v14 + str.i_str_ref_p->i_length;
      if ( v16 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v16);
        v15 = str.i_str_ref_p;
      }
      memmove(&v15->i_cstr_p[v15->i_length], **v13, (unsigned int)(v14 + 1));
      str.i_str_ref_p->i_length = v16;
    }
    v17 = resulta.i_str_ref_p;
    v18 = resulta.i_str_ref_p->i_ref_count == 1;
    --v17->i_ref_count;
    if ( v18 )
    {
      if ( v17->i_deallocate )
        AMemory::c_free_func(v17->i_cstr_p);
      v19 = AStringRef::get_pool();
      v20 = v19->i_block_p;
      v21 = (unsigned __int64)v20->i_objects_a;
      if ( (unsigned __int64)v17 < v21
        || (v22 = (unsigned __int64)v17 < v21 + 24i64 * v20->i_size, v23 = &v19->i_pool, !v22) )
      {
        v23 = &v19->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v23, v17);
    }
    v24 = ASymbol::create(&v38, &str, ATerm_long);
    v25 = v24->i_uid;
    v5->i_uid = v24->i_uid;
    v26 = SSBrain::c_actor_class_p->i_instances.i_count;
    if ( !(_DWORD)v26 )
      break;
    v27 = SSBrain::c_actor_class_p->i_instances.i_array_p;
    v28 = (signed __int64)&v27[v26 - 1];
    while ( 1 )
    {
      v29 = (signed __int64)&v27[(v28 - (signed __int64)v27) >> 4];
      v30 = *(_DWORD *)(*(_QWORD *)v29 + 72i64);
      if ( v25 < v30 )
        goto LABEL_31;
      v31 = v25 != v30;
      if ( !v31 )
        break;
      if ( v31 < 0 )
      {
LABEL_31:
        if ( v27 == (SSActor **)v29 )
          goto LABEL_34;
        v28 = v29 - 8;
      }
      else
      {
        if ( v28 == v29 )
          goto LABEL_34;
        v27 = (SSActor **)(v29 + 8);
      }
    }
  }
  while ( *(_QWORD *)v29 );
LABEL_34:
  if ( v3 )
    *v3 = v10;
  v32 = str.i_str_ref_p;
  v18 = str.i_str_ref_p->i_ref_count == 1;
  --v32->i_ref_count;
  if ( v18 )
  {
    if ( v32->i_deallocate )
      AMemory::c_free_func(v32->i_cstr_p);
    v33 = AStringRef::get_pool();
    v34 = v33->i_block_p;
    v35 = (unsigned __int64)v34->i_objects_a;
    if ( (unsigned __int64)v32 < v35
      || (v22 = (unsigned __int64)v32 < v35 + 24i64 * v34->i_size, v36 = &v33->i_pool, !v22) )
    {
      v36 = &v33->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v36, v32);
  }
  return v5;
}

// File Line: 994
// RVA: 0x126E10
void __fastcall SSActor::on_update(SSActor *this)
{
  SSActor *v1; // rbx
  __int64 v2; // rdi
  unsigned int v3; // eax
  SSInvokedCoroutine **v4; // rax
  unsigned int v5; // eax
  SSInvokedCoroutine *v6; // rdx
  unsigned int v7; // eax
  bool v8; // zf

  v1 = this;
  if ( (this->i_actor_flags & 5) == 5 )
  {
    ++this->i_ref_count;
    v2 = this->i_icoroutines_to_update.i_count;
    if ( (_DWORD)v2 )
    {
      if ( (unsigned int)v2 <= SSActor::c_icoroutines_updating.i_size )
      {
        v4 = SSActor::c_icoroutines_updating.i_array_p;
      }
      else
      {
        AMemory::c_free_func(SSActor::c_icoroutines_updating.i_array_p);
        v3 = AMemory::c_req_byte_size_func(8 * v2);
        SSActor::c_icoroutines_updating.i_size = v3 >> 3;
        v4 = APArrayBase<SSInvokedCoroutine>::alloc_array(v3 >> 3);
        SSActor::c_icoroutines_updating.i_array_p = v4;
      }
      SSActor::c_icoroutines_updating.i_count = v2;
      memmove(v4, v1->i_icoroutines_to_update.i_array_p, 8 * v2);
      v5 = SSActor::c_icoroutines_updating.i_count;
      if ( SSActor::c_icoroutines_updating.i_count )
      {
        --SSActor::c_icoroutines_updating.i_count;
        v6 = SSActor::c_icoroutines_updating.i_array_p[v5 - 1];
      }
      else
      {
        v6 = 0i64;
      }
      for ( v1->i_actor_flags |= 8u; v6; v6 = SSActor::c_icoroutines_updating.i_array_p[v7 - 1] )
      {
        SSInvokedCoroutine::on_update(v6);
        v7 = SSActor::c_icoroutines_updating.i_count;
        if ( !SSActor::c_icoroutines_updating.i_count )
          break;
        --SSActor::c_icoroutines_updating.i_count;
      }
      v1->i_actor_flags &= 0xFFFFFFF7;
    }
    if ( !v1->i_icoroutines_to_update.i_count )
      SSActor::enable_on_update(v1, 0);
    v8 = v1->i_ref_count-- == 1;
    if ( v8 )
    {
      v1->i_ref_count = 2147483648;
      v1->vfptr[1].get_scope_context((SSObjectBase *)&v1->vfptr);
    }
  }
}

// File Line: 1048
// RVA: 0x13EAD0
void SSActor::update_all(void)
{
  SSActor **v0; // rcx
  unsigned int v1; // eax
  unsigned int v2; // eax
  SSActor **v3; // rax
  unsigned int v4; // eax
  SSActor *i; // rdx
  unsigned int v6; // eax

  if ( !((SkookumScript::c_flags >> 2) & 1) )
  {
    v0 = SSActor::c_updating_actors.i_array_p;
    SkookumScript::c_flags += 4;
    v1 = SSActor::c_update_actors.i_count;
    SSActor::c_updating_actors.i_count = SSActor::c_update_actors.i_count;
    if ( SSActor::c_update_actors.i_count > SSActor::c_updating_actors.i_size )
    {
      AMemory::c_free_func(SSActor::c_updating_actors.i_array_p);
      v2 = AMemory::c_req_byte_size_func(8 * SSActor::c_updating_actors.i_count);
      SSActor::c_updating_actors.i_size = v2 >> 3;
      v3 = APArrayBase<SSActor>::alloc_array(v2 >> 3);
      v0 = v3;
      SSActor::c_updating_actors.i_array_p = v3;
      v1 = SSActor::c_updating_actors.i_count;
    }
    memmove(v0, SSActor::c_update_actors.i_array_p, 8i64 * v1);
    v4 = SSActor::c_updating_actors.i_count;
    if ( SSActor::c_updating_actors.i_count )
    {
      --SSActor::c_updating_actors.i_count;
      for ( i = SSActor::c_updating_actors.i_array_p[v4 - 1]; i; i = SSActor::c_updating_actors.i_array_p[v6 - 1] )
      {
        i->vfptr[2].get_obj_type((SSObjectBase *)&i->vfptr);
        v6 = SSActor::c_updating_actors.i_count;
        if ( !SSActor::c_updating_actors.i_count )
          break;
        --SSActor::c_updating_actors.i_count;
      }
    }
    if ( SkookumScript::c_flags & 4 )
      SkookumScript::c_flags -= 4;
  }
}

