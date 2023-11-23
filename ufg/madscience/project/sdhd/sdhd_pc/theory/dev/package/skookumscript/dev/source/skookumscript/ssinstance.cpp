// File Line: 48
// RVA: 0x117AE0
SSClass *__fastcall SSInstance::get_key_class(SSInstance *this)
{
  if ( ((unsigned __int8 (__fastcall *)(SSInstance *))this->vfptr[1].__vecDelDtor)(this) )
    return (SSClass *)(*(__int64 (__fastcall **)(unsigned __int64 *))(this[-1].i_user_data2 + 120))(&this[-1].i_user_data2);
  else
    return this->i_class_p;
}

// File Line: 71
// RVA: 0x11FF90
void __fastcall SSInstance::method_invoke(
        SSInstance *this,
        SSMethodCall *mcall,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSClass *i_scope_p; // rcx
  SSMethodBase *method_inherited_receiver; // rax
  SSInvokableBase *v11; // rsi
  SSInvokedMethod *v12; // rbx
  SSInstance *receiver_pp; // [rsp+40h] [rbp+8h] BYREF

  receiver_pp = this;
  i_scope_p = mcall->i_scope_p;
  if ( !i_scope_p )
    i_scope_p = this->i_class_p;
  method_inherited_receiver = SSClass::get_method_inherited_receiver(
                                i_scope_p,
                                &mcall->i_name,
                                (SSInstanceUnreffed **)&receiver_pp,
                                caller_p);
  v11 = method_inherited_receiver;
  if ( method_inherited_receiver )
  {
    v12 = SSInvokedMethod::pool_new(caller_p, receiver_pp, method_inherited_receiver);
    SSInvokedContextBase::data_append_args_exprs(v12, &mcall->i_arguments, v11, scope_p);
    ((void (__fastcall *)(SSInvokableBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v11->vfptr[1].get_custom_expr)(
      v11,
      v12,
      caller_p,
      result_pp);
    SSInvokedContextBase::data_bind_return_args(v12, &mcall->i_return_args, v11);
    SSInvokedMethod::pool_delete(v12);
  }
  else if ( result_pp )
  {
    *result_pp = SSBrain::c_nil_p;
  }
}

// File Line: 143
// RVA: 0x11FCD0
void __fastcall SSInstance::method_call(
        SSInstance *this,
        ASymbol *method_name,
        SSInstance **args_pp,
        unsigned int arg_count,
        SSInstance **result_pp,
        SSInvokedBase *caller_p)
{
  SSMethodBase *method_inherited_receiver; // rdi
  SSInvokedMethod *v9; // rbx
  SSInstance *receiver_pp; // [rsp+30h] [rbp+8h] BYREF

  receiver_pp = this;
  method_inherited_receiver = SSClass::get_method_inherited_receiver(
                                this->i_class_p,
                                method_name,
                                (SSInstanceUnreffed **)&receiver_pp,
                                caller_p);
  v9 = SSInvokedMethod::pool_new(caller_p, receiver_pp, method_inherited_receiver);
  SSInvokedContextBase::data_append_args(v9, args_pp, arg_count, method_inherited_receiver);
  ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))method_inherited_receiver->vfptr[1].get_custom_expr)(
    method_inherited_receiver,
    v9,
    caller_p,
    result_pp);
  SSInvokedMethod::pool_delete(v9);
}

// File Line: 220
// RVA: 0x1118A0
void __fastcall SSInstance::call_default_constructor(SSInstance *this)
{
  SSClass *i_class_p; // r11
  SSMethodBase *instance_method_inherited; // rbx
  __int64 i_count; // rax
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v6; // r10
  SSMethodBase **v7; // rdx
  unsigned int i_uid; // r9d
  SSClass *i_superclass_p; // rcx
  SSInvokedMethod *v10; // rax
  SSInvokedMethod *v11; // rdi

  i_class_p = this->i_class_p;
  instance_method_inherited = 0i64;
  i_count = i_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = i_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v7 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*v7)->i_name.i_uid;
        if ( ASymbolX_ctor.i_uid >= i_uid )
          break;
        if ( i_array_p == v7 )
          goto LABEL_10;
        v6 = v7 - 1;
      }
      if ( ASymbolX_ctor.i_uid == i_uid )
        break;
      if ( v6 == v7 )
        goto LABEL_10;
      i_array_p = v7 + 1;
    }
    instance_method_inherited = *v7;
    if ( *v7 )
      goto LABEL_13;
  }
LABEL_10:
  i_superclass_p = i_class_p->i_superclass_p;
  if ( i_superclass_p )
    instance_method_inherited = SSClass::get_instance_method_inherited(i_superclass_p, &ASymbolX_ctor);
  if ( instance_method_inherited )
  {
LABEL_13:
    v10 = SSInvokedMethod::pool_new(0i64, this, instance_method_inherited);
    v11 = v10;
    if ( instance_method_inherited->i_params_p.i_obj_p->i_params.i_count )
      SSInvokedContextBase::data_append_args(v10, 0i64, 0, instance_method_inherited);
    ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, _QWORD))instance_method_inherited->vfptr[1].get_custom_expr)(
      instance_method_inherited,
      v11,
      0i64,
      0i64);
    SSInvokedMethod::pool_delete(v11);
  }
}

// File Line: 253
// RVA: 0x111990
void __fastcall SSInstance::call_destructor(SSInstance *this)
{
  SSClass *i_class_p; // rax
  SSMethodBase *i_destructor_p; // rdi
  SSInvokedMethod *v3; // rbx

  i_class_p = this->i_class_p;
  i_destructor_p = i_class_p->i_destructor_p;
  if ( i_destructor_p )
  {
    v3 = SSInvokedMethod::pool_new(0i64, this, i_class_p->i_destructor_p);
    ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, _QWORD))i_destructor_p->vfptr[1].get_custom_expr)(
      i_destructor_p,
      v3,
      0i64,
      0i64);
    SSInvokedMethod::pool_delete(v3);
  }
}

// File Line: 344
// RVA: 0x1129C0
SSCoroutineBase *__fastcall SSInstance::coroutine_call(
        SSInstance *this,
        ASymbol *coroutine_name,
        SSInstance **args_pp,
        unsigned int arg_count,
        bool immediate,
        float update_interval,
        SSInvokedBase *caller_p,
        SSActor *updater_p)
{
  SSCoroutineBase *result; // rax
  SSInvokableBase *v12; // rdi
  AObjReusePool<SSInvokedCoroutine> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v15; // eax
  __int64 v16; // rcx
  SSInvokedCoroutine **i_array_p; // rax
  SSInvokedCoroutine *v18; // rbx
  unsigned int v19; // eax
  SSActor *i_obj_p; // rdi

  result = this->i_class_p->vfptr->get_coroutine_inherited(this->i_class_p, coroutine_name);
  v12 = result;
  if ( !result )
    return result;
  pool = SSInvokedCoroutine::get_pool();
  if ( pool->i_pool.i_count )
  {
    v19 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v19;
    v16 = v19;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_9;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInvokedCoroutine>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v15 = i_count - 1;
    pool->i_exp_pool.i_count = v15;
    v16 = v15;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_9:
    v18 = i_array_p[v16];
    goto LABEL_10;
  }
  v18 = 0i64;
LABEL_10:
  v18->i_coroutine_p = (SSCoroutineBase *)v12;
  SSInvokedCoroutine::reset(v18, update_interval, caller_p, this, updater_p, 0i64);
  SSInvokedContextBase::data_append_args(v18, args_pp, arg_count, v12);
  if ( immediate )
  {
    if ( SSInvokedCoroutine::on_update(v18) )
      return 0i64;
  }
  else
  {
    i_obj_p = v18->i_updater_p.i_obj_p;
    if ( !i_obj_p || v18->i_updater_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    if ( (v18->i_flags & 1) == 0 )
    {
      APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
        &i_obj_p->i_icoroutines_to_update,
        v18);
      v18->i_flags |= 1u;
      if ( (i_obj_p->i_actor_flags & 2) == 0 )
        SSActor::enable_on_update(i_obj_p, 1);
    }
  }
  return (SSCoroutineBase *)v18;
}

// File Line: 447
// RVA: 0x10E530
void __fastcall SSInstance::as_code_append(
        SSInstance *this,
        AString *str_p,
        bool break_new_lines,
        SSInvokedBase *caller_p)
{
  unsigned int v7; // r8d
  const char *v8; // rdx
  unsigned int i_length; // edi
  SSClass *i_class_p; // r11
  unsigned int i_uid; // eax
  unsigned int v12; // edx
  AStringRef *v13; // rbx
  bool v14; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  AString *v18; // rax
  unsigned int v19; // edx
  AString *v20; // rax
  unsigned int v21; // edx
  __int64 v22; // rdi
  AStringRef *i_str_ref_p; // rdx
  unsigned int v24; // esi
  unsigned int v25; // edi
  __int64 v26; // rdi
  __int64 i_count; // rax
  SSMethodBase *instance_method_inherited; // rdi
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v30; // r10
  SSMethodBase **v31; // rdx
  unsigned int v32; // r9d
  SSClass *i_superclass_p; // rcx
  SSInvokedMethod *v34; // rbp
  _DWORD *v35; // rcx
  __int64 v36; // [rsp+20h] [rbp-28h] BYREF
  AString v37; // [rsp+28h] [rbp-20h] BYREF
  AString v38; // [rsp+30h] [rbp-18h] BYREF
  __int64 v39; // [rsp+38h] [rbp-10h]
  AString result; // [rsp+50h] [rbp+8h] BYREF

  v39 = -2i64;
  if ( !this )
  {
LABEL_2:
    v7 = 3;
    v8 = "nil";
LABEL_63:
    AString::append(str_p, v8, v7);
    return;
  }
  i_length = str_p->i_str_ref_p->i_length;
  i_class_p = this->i_class_p;
  i_uid = i_class_p->i_name.i_uid;
  if ( i_uid > 0x9693548A )
  {
    switch ( i_uid )
    {
      case 0xC26E4D96:
        if ( this->i_user_data )
        {
          v7 = 4;
          v8 = "true";
        }
        else
        {
          v7 = 5;
          v8 = "false";
        }
        goto LABEL_63;
      case 0xDCF92817:
        goto LABEL_2;
      case 0xE646BE1C:
        v7 = 14;
        v8 = "Closure object";
        goto LABEL_63;
    }
    goto LABEL_45;
  }
  switch ( i_uid )
  {
    case 0x9693548A:
      ASymbol::as_str_dbg((ASymbol *)&this->i_user_data, &result);
      v21 = i_length + result.i_str_ref_p->i_length + 2;
      if ( v21 >= str_p->i_str_ref_p->i_size || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
        AString::set_size(str_p, v21);
      v22 = str_p->i_str_ref_p->i_length + 1;
      if ( (unsigned int)v22 >= str_p->i_str_ref_p->i_size
        || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(str_p, v22);
      }
      str_p->i_str_ref_p->i_cstr_p[(unsigned int)(v22 - 1)] = 39;
      str_p->i_str_ref_p->i_cstr_p[v22] = 0;
      str_p->i_str_ref_p->i_length = v22;
      i_str_ref_p = result.i_str_ref_p;
      v24 = result.i_str_ref_p->i_length;
      if ( v24 )
      {
        v25 = v24 + str_p->i_str_ref_p->i_length;
        if ( v25 >= str_p->i_str_ref_p->i_size || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
        {
          AString::set_size(str_p, v25);
          i_str_ref_p = result.i_str_ref_p;
        }
        memmove(&str_p->i_str_ref_p->i_cstr_p[str_p->i_str_ref_p->i_length], i_str_ref_p->i_cstr_p, v24 + 1);
        str_p->i_str_ref_p->i_length = v25;
      }
      v26 = str_p->i_str_ref_p->i_length + 1;
      if ( (unsigned int)v26 >= str_p->i_str_ref_p->i_size
        || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(str_p, v26);
      }
      str_p->i_str_ref_p->i_cstr_p[(unsigned int)(v26 - 1)] = 39;
      str_p->i_str_ref_p->i_cstr_p[v26] = 0;
      str_p->i_str_ref_p->i_length = v26;
      goto LABEL_13;
    case 0x3CC821AAu:
      v20 = AString::ctor_float(&v38, *(float *)&this->i_user_data, 6u);
      AString::append(str_p, v20);
      v13 = v38.i_str_ref_p;
LABEL_14:
      v14 = v13->i_ref_count-- == 1;
      if ( v14 )
      {
        if ( v13->i_deallocate )
          AMemory::c_free_func(v13->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)v13 < i_objects_a || (unsigned __int64)v13 >= i_objects_a + 24i64 * i_block_p->i_size )
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&pool->i_exp_pool, v13);
        else
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&pool->i_pool, v13);
      }
      return;
    case 0x5901674Cu:
      SSParser::string_to_esacpe_string(&result, (AString *)&this->i_user_data, break_new_lines);
      v19 = i_length + result.i_str_ref_p->i_length + 2;
      if ( v19 >= str_p->i_str_ref_p->i_size || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
        AString::set_size(str_p, v19);
      AString::append(str_p, 34);
      AString::append(str_p, &result);
      AString::append(str_p, 34);
      goto LABEL_13;
    case 0x78A518A8u:
      v18 = AString::ctor_int(&v37, this->i_user_data, 0xAu);
      AString::append(str_p, v18);
      v13 = v37.i_str_ref_p;
      goto LABEL_14;
    case 0x8666AACD:
      ANamed::get_name_str_dbg((ANamed *)&this[1].vfptr->get_obj_type, &result);
      v12 = i_length + result.i_str_ref_p->i_length + 2;
      if ( v12 >= str_p->i_str_ref_p->i_size || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
        AString::set_size(str_p, v12);
      AString::append(str_p, 60);
      AString::append(str_p, &result);
      AString::append(str_p, 62);
LABEL_13:
      v13 = result.i_str_ref_p;
      goto LABEL_14;
  }
LABEL_45:
  i_count = i_class_p->i_methods.i_count;
  instance_method_inherited = 0i64;
  if ( !(_DWORD)i_count )
    goto LABEL_54;
  i_array_p = i_class_p->i_methods.i_array_p;
  v30 = &i_array_p[i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v31 = &i_array_p[((char *)v30 - (char *)i_array_p) >> 4];
      v32 = (*v31)->i_name.i_uid;
      if ( ASymbol_String.i_uid >= v32 )
        break;
      if ( i_array_p == v31 )
        goto LABEL_54;
      v30 = v31 - 1;
    }
    if ( ASymbol_String.i_uid == v32 )
      break;
    if ( v30 == v31 )
      goto LABEL_54;
    i_array_p = v31 + 1;
  }
  instance_method_inherited = *v31;
  if ( !*v31 )
  {
LABEL_54:
    i_superclass_p = i_class_p->i_superclass_p;
    if ( i_superclass_p )
      instance_method_inherited = SSClass::get_instance_method_inherited(i_superclass_p, &ASymbol_String);
  }
  v34 = SSInvokedMethod::pool_new(caller_p, this, instance_method_inherited);
  ++this->i_ref_count;
  ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, __int64 *))instance_method_inherited->vfptr[1].get_custom_expr)(
    instance_method_inherited,
    v34,
    0i64,
    &v36);
  AString::append(str_p, (AString *)(v36 + 32));
  v35 = (_DWORD *)v36;
  v14 = (*(_DWORD *)(v36 + 16))-- == 1;
  if ( v14 )
  {
    v35[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v35 + 112i64))(v35);
  }
  --this->i_ref_count;
  SSInvokedMethod::pool_delete(v34);
}

// File Line: 561
// RVA: 0x118C10
AObjReusePool<SSInstance> *__fastcall SSInstance::get_pool()
{
  unsigned int i_pool_incr_instance; // edi
  unsigned int i_pool_init_instance; // ebx
  SSInstance **v2; // rax

  if ( (_S5_3 & 1) != 0 )
    return &s_pool_1;
  _S5_3 |= 1u;
  i_pool_incr_instance = Skookum::get_lib_vals()->i_pool_incr_instance;
  i_pool_init_instance = Skookum::get_lib_vals()->i_pool_init_instance;
  s_pool_1.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175BC8 = 0i64;
  unk_142175BD0 = 0;
  if ( i_pool_init_instance )
  {
    unk_142175BD0 = i_pool_init_instance;
    v2 = APArrayBase<SSInstance>::alloc_array(i_pool_init_instance);
  }
  else
  {
    unk_142175BD0 = 0;
    v2 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175BC8 = v2;
  qword_142175BD8 = 0i64;
  unk_142175BE0 = 0;
  qword_142175BE8 = 0i64;
  unk_142175BF0 = 0;
  stru_142175BF8.i_count = 0;
  stru_142175BF8.i_array_p = 0i64;
  stru_142175BF8.i_size = 0;
  unk_142175C10 = i_pool_incr_instance;
  AObjReusePool<SSInstance>::append_block(&s_pool_1, i_pool_init_instance);
  atexit(SSInstance::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_1;
}

// File Line: 575
// RVA: 0x117800
SSInstance *__fastcall SSInstance::get_data_by_name(SSInstance *this, ASymbol *name)
{
  SSMetaClass *v3; // rax

  v3 = this->i_class_p->vfptr->get_metaclass(this->i_class_p);
  return v3->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->get_data_by_name(&v3->SSInstanceUnreffed, name);
}

// File Line: 594
// RVA: 0x13C4E0
void __fastcall SSInstance::set_data_by_name(SSInstance *this, ASymbol *name, SSInstance *obj_p)
{
  SSMetaClass *v5; // rax

  v5 = this->i_class_p->vfptr->get_metaclass(this->i_class_p);
  v5->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->set_data_by_name(&v5->SSInstanceUnreffed, name, obj_p);
}

// File Line: 637
// RVA: 0x1215E0
void __fastcall SSInstance::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rcx
  AString *name_str_dbg; // rdi
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
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    name_str_dbg = ANamed::get_name_str_dbg((ANamed *)(*(_QWORD *)&i_obj_p[1].i_ptr_id + 8i64), &result);
    v6 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v16 = v6;
    p_i_user_data = &v6->i_user_data;
    if ( v6 != (SSInstance *)-32i64 )
    {
      i_str_ref_p = name_str_dbg->i_str_ref_p;
      v6->i_user_data = (unsigned __int64)name_str_dbg->i_str_ref_p;
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

// File Line: 657
// RVA: 0x125F30
void __fastcall SSInstance::mthdc_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rcx
  AString *name_str_dbg; // rdi
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
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-1].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    name_str_dbg = ANamed::get_name_str_dbg((ANamed *)(*((_QWORD *)p_i_ptr_id + 7) + 8i64), &result);
    v6 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v16 = v6;
    p_i_user_data = &v6->i_user_data;
    if ( v6 != (SSInstance *)-32i64 )
    {
      i_str_ref_p = name_str_dbg->i_str_ref_p;
      v6->i_user_data = (unsigned __int64)name_str_dbg->i_str_ref_p;
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

// File Line: 727
// RVA: 0x1264C0
void __fastcall SSInstance::mthdc_is_class(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  bool v2; // bl
  SSInstance *i_data_p; // rax
  unsigned __int64 *p_i_user_data2; // r8
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  __int64 v8; // rax
  SSClass *v9; // rcx

  if ( result_pp )
  {
    v2 = 0;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    p_i_user_data2 = &i_data_p[-1].i_user_data2;
    if ( !i_data_p )
      p_i_user_data2 = 0i64;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-1].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v8 = *((_QWORD *)p_i_ptr_id + 7);
    if ( p_i_user_data2[7] == v8
      || (v9 = *(SSClass **)(v8 + 16)) != 0i64 && SSClass::is_class(v9, (SSClass *)p_i_user_data2[7]) )
    {
      v2 = 1;
    }
    *result_pp = SSBoolean::pool_new(v2);
  }
}

// File Line: 753
// RVA: 0x126550
void __fastcall SSInstance::mthdc_is_class_actor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int *p_i_ptr_id; // rcx
  char v5; // al

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-1].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v5 = (*(__int64 (__fastcall **)(_QWORD))(**((_QWORD **)p_i_ptr_id + 7) + 64i64))(*((_QWORD *)p_i_ptr_id + 7));
    *result_pp = SSBoolean::pool_new(v5);
  }
}

// File Line: 779
// RVA: 0x1265D0
void __fastcall SSInstance::mthdc_is_subclass(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  bool v2; // bl
  SSInstance *i_data_p; // rax
  unsigned __int64 *p_i_user_data2; // r8
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rax
  SSClass *v8; // rdx
  SSClass *v9; // rcx

  if ( result_pp )
  {
    v2 = 0;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    p_i_user_data2 = &i_data_p[-1].i_user_data2;
    if ( !i_data_p )
      p_i_user_data2 = 0i64;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || (p_i_ptr_id = &i_obj_p[-1].i_ptr_id, scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id) )
      p_i_ptr_id = 0i64;
    v8 = (SSClass *)p_i_user_data2[7];
    v9 = *(SSClass **)(*((_QWORD *)p_i_ptr_id + 7) + 16i64);
    if ( v9 == v8 || v9 && SSClass::is_subclass(v9, v8) )
      v2 = 1;
    *result_pp = SSBoolean::pool_new(v2);
  }
}

// File Line: 806
// RVA: 0x126650
void __fastcall SSInstance::mthdc_is_superclass(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  bool v2; // bl
  SSInstance *i_data_p; // rax
  unsigned __int64 *p_i_user_data2; // r8
  SSObjectBase *i_obj_p; // rdx
  unsigned int *p_i_ptr_id; // rdx
  SSClass *v8; // rcx
  SSClass *v9; // rdx

  if ( result_pp )
  {
    v2 = 0;
    i_data_p = (*scope_p->i_data.i_array_p)->i_data_p;
    p_i_user_data2 = &i_data_p[-1].i_user_data2;
    if ( !i_data_p )
      p_i_user_data2 = 0i64;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      p_i_ptr_id = &i_obj_p[-1].i_ptr_id;
    else
      p_i_ptr_id = 0i64;
    v8 = (SSClass *)*((_QWORD *)p_i_ptr_id + 7);
    v9 = *(SSClass **)(p_i_user_data2[7] + 16);
    if ( v9 == v8 || v9 && SSClass::is_superclass(v8, v9) )
      v2 = 1;
    *result_pp = SSBoolean::pool_new(v2);
  }
}

// File Line: 832
// RVA: 0x126750
void __fastcall SSInstance::mthdc_set_data_untyped(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  scope_p->vfptr->set_data_by_name(
    scope_p,
    (ASymbol *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data,
    *(SSInstance **)(*((_QWORD *)scope_p->i_data.i_array_p + 1) + 8i64));
}

// File Line: 858
// RVA: 0x112950
bool __fastcall SSInstance::coro_wait(SSInstance *this, SSInvokedCoroutine *scope_p)
{
  float v2; // xmm1_4

  if ( scope_p->i_update_count )
    return 1;
  v2 = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  scope_p->i_update_next = v2 + SkookumScript::c_sim_time;
  return v2 < 0.0;
}

// File Line: 898
// RVA: 0x112990
char __fastcall SSInstance::coro_wait_until(SSInstance *this, SSInvokedCoroutine *scope_p)
{
  char result; // al

  if ( scope_p->i_update_count )
    return 1;
  result = 0;
  scope_p->i_update_next = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  return result;
}

// File Line: 915
// RVA: 0x13B1A0
void SSInstance::register_bindings(void)
{
  __int64 i_count; // rax
  SSMethodBase **i_array_p; // r8
  SSMethodBase **v2; // r10
  SSMethodBase **v3; // rdx
  unsigned int i_uid; // r9d
  __int64 v5; // rbx
  __int64 v6; // rbp
  SSParameters *v7; // rsi
  SSParameters *v8; // r14
  bool v9; // zf
  __int64 v10; // rax
  SSMethodBase **v11; // r8
  SSMethodBase **v12; // r10
  SSMethodBase **v13; // rdx
  unsigned int v14; // r9d
  __int64 v15; // rbx
  __int64 v16; // rbp
  SSParameters *v17; // rsi
  SSParameters *v18; // r14
  SSClass *v19; // rbx
  ASymbol *v20; // rax
  SSClass *v21; // r11
  __int64 v22; // rax
  SSCoroutineBase **v23; // r8
  SSCoroutineBase **v24; // r10
  SSCoroutineBase **v25; // rdx
  unsigned int v26; // r9d
  SSCoroutineBase *v27; // rcx
  __int64 v28; // rax
  SSCoroutineBase **v29; // r8
  SSCoroutineBase **v30; // r10
  SSCoroutineBase **v31; // rdx
  unsigned int v32; // r9d
  SSCoroutineBase *v33; // rcx
  __int64 v34; // [rsp+30h] [rbp-48h]
  __int64 result; // [rsp+80h] [rbp+8h] BYREF
  SSParameters *v36; // [rsp+88h] [rbp+10h]
  __int64 v37; // [rsp+90h] [rbp+18h]

  i_count = SSBrain::c_object_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_object_class_p->i_methods.i_array_p;
    v2 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v3 = &i_array_p[((char *)v2 - (char *)i_array_p) >> 4];
        i_uid = (*v3)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= i_uid )
          break;
        if ( i_array_p == v3 )
          goto LABEL_10;
        v2 = v3 - 1;
      }
      if ( ASymbol_String.i_uid == i_uid )
        break;
      if ( v2 == v3 )
        goto LABEL_10;
      i_array_p = v3 + 1;
    }
    v5 = (__int64)*v3;
  }
  else
  {
LABEL_10:
    v5 = 0i64;
  }
  result = v5;
  if ( v5 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5) == 1 )
    {
      *(_QWORD *)(v5 + 32) = SSInstance::mthd_as_string;
    }
    else
    {
      v6 = *(_QWORD *)(v5 + 16);
      v7 = *(SSParameters **)(v5 + 24);
      v36 = v7;
      if ( v7 )
        ++v7->i_ref_count;
      v8 = *(SSParameters **)(v5 + 24);
      if ( v8 )
      {
        v9 = v8->i_ref_count-- == 1;
        if ( v9 )
        {
          v8->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v8);
          AMemory::c_free_func(v8);
        }
        *(_QWORD *)(v5 + 24) = 0i64;
      }
      v37 = v5;
      *(ASymbol *)(v5 + 8) = ASymbol_String;
      *(_QWORD *)(v5 + 16) = v6;
      *(_QWORD *)v5 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v5 + 24) = v7;
      if ( v7 )
        ++v7->i_ref_count;
      *(_QWORD *)v5 = &SSMethodBase::`vftable;
      *(_QWORD *)v5 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v5 + 32) = SSInstance::mthd_as_string;
      if ( v7 )
      {
        v9 = v7->i_ref_count-- == 1;
        if ( v9 )
        {
          v7->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v7);
          AMemory::c_free_func(v7);
        }
      }
    }
  }
  v10 = SSBrain::c_object_class_p->i_methods.i_count;
  if ( (_DWORD)v10 )
  {
    v11 = SSBrain::c_object_class_p->i_methods.i_array_p;
    v12 = &v11[v10 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v13 = &v11[((char *)v12 - (char *)v11) >> 4];
        v14 = (*v13)->i_name.i_uid;
        if ( ASymbol_is.i_uid >= v14 )
          break;
        if ( v11 == v13 )
          goto LABEL_34;
        v12 = v13 - 1;
      }
      if ( ASymbol_is.i_uid == v14 )
        break;
      if ( v12 == v13 )
        goto LABEL_34;
      v11 = v13 + 1;
    }
    v15 = (__int64)*v13;
  }
  else
  {
LABEL_34:
    v15 = 0i64;
  }
  result = v15;
  if ( v15 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15) == 1 )
    {
      *(_QWORD *)(v15 + 32) = SSActor::mthd_op_equals;
    }
    else
    {
      v16 = *(_QWORD *)(v15 + 16);
      v17 = *(SSParameters **)(v15 + 24);
      v36 = v17;
      if ( v17 )
        ++v17->i_ref_count;
      v18 = *(SSParameters **)(v15 + 24);
      if ( v18 )
      {
        v9 = v18->i_ref_count-- == 1;
        if ( v9 )
        {
          v18->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v18);
          AMemory::c_free_func(v18);
        }
        *(_QWORD *)(v15 + 24) = 0i64;
      }
      v37 = v15;
      *(ASymbol *)(v15 + 8) = ASymbol_is;
      *(_QWORD *)(v15 + 16) = v16;
      *(_QWORD *)v15 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v15 + 24) = v17;
      if ( v17 )
        ++v17->i_ref_count;
      *(_QWORD *)v15 = &SSMethodBase::`vftable;
      *(_QWORD *)v15 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v15 + 32) = SSActor::mthd_op_equals;
      if ( v17 )
      {
        v9 = v17->i_ref_count-- == 1;
        if ( v9 )
        {
          v17->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v17);
          AMemory::c_free_func(v17);
        }
      }
    }
  }
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_String,
    SSInstance::mthdc_as_string,
    SSBindFlag_class_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_is_class,
    SSInstance::mthdc_is_class,
    SSBindFlag_class_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_is_class_actor,
    SSInstance::mthdc_is_class_actor,
    SSBindFlag_class_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_is_subclass,
    SSInstance::mthdc_is_subclass,
    SSBindFlag_class_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_is_superclass,
    SSInstance::mthdc_is_superclass,
    SSBindFlag_class_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_equals,
    SSActor::mthd_op_equals,
    SSBindFlag_class_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_object_class_p,
    &ASymbol_not_equal,
    SSInstance::mthdc_op_not_equal,
    SSBindFlag_class_no_rebind);
  v19 = SSBrain::c_object_class_p;
  v20 = ASymbol::create((ASymbol *)&result, "set_data_untyped", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v19, v20, SSInstance::mthdc_set_data_untyped, SSBindFlag_class_no_rebind);
  LODWORD(v34) = 0;
  v21 = SSBrain::c_object_class_p;
  v22 = SSBrain::c_object_class_p->i_coroutines.i_count;
  if ( (_DWORD)v22 )
  {
    v23 = SSBrain::c_object_class_p->i_coroutines.i_array_p;
    v24 = &v23[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v25 = &v23[((char *)v24 - (char *)v23) >> 4];
        v26 = (*v25)->i_name.i_uid;
        if ( ASymbol__wait.i_uid >= v26 )
          break;
        if ( v23 == v25 )
          goto LABEL_59;
        v24 = v25 - 1;
      }
      if ( ASymbol__wait.i_uid == v26 )
        break;
      if ( v24 == v25 )
        goto LABEL_59;
      v23 = v25 + 1;
    }
    v27 = *v25;
    if ( *v25 )
    {
      v27[1].vfptr = (SSInvokableBaseVtbl *)SSInstance::coro_wait;
      *(_QWORD *)&v27[1].i_name.i_uid = v34;
      v21 = SSBrain::c_object_class_p;
    }
  }
LABEL_59:
  LODWORD(v34) = 0;
  v28 = v21->i_coroutines.i_count;
  if ( (_DWORD)v28 )
  {
    v29 = v21->i_coroutines.i_array_p;
    v30 = &v29[v28 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v31 = &v29[((char *)v30 - (char *)v29) >> 4];
        v32 = (*v31)->i_name.i_uid;
        if ( ASymbol__wait_until.i_uid >= v32 )
          break;
        if ( v29 == v31 )
          return;
        v30 = v31 - 1;
      }
      if ( ASymbol__wait_until.i_uid == v32 )
        break;
      if ( v30 == v31 )
        return;
      v29 = v31 + 1;
    }
    v33 = *v31;
    if ( *v31 )
    {
      v33[1].vfptr = (SSInvokableBaseVtbl *)SSInstance::coro_wait_until;
      *(_QWORD *)&v33[1].i_name.i_uid = v34;
    }
  }
}
    {
      v33[1].vfptr = (SSInvokableBaseVtbl *)SSInstance::coro_wait_until;
      *(_QWORD *)&v33[1].i_name.i_uid = v34;
    }
  }
}

