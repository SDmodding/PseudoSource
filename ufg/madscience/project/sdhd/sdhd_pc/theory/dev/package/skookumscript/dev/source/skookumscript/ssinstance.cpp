// File Line: 48
// RVA: 0x117AE0
SSClass *__fastcall SSInstance::get_key_class(SSInstance *this)
{
  SSInstance *v1; // rbx
  SSClass *result; // rax

  v1 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[1].__vecDelDtor)() )
    result = (SSClass *)(*(__int64 (__fastcall **)(unsigned __int64 *))(v1[-1].i_user_data2 + 120))(&v1[-1].i_user_data2);
  else
    result = v1->i_class_p;
  return result;
}

// File Line: 71
// RVA: 0x11FF90
void __fastcall SSInstance::method_invoke(SSInstance *this, SSMethodCall *mcall, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance *v5; // rax
  SSClass *v6; // rcx
  SSInvokedBase *v7; // rbp
  SSObjectBase *v8; // r14
  SSMethodCall *v9; // rdi
  SSMethodBase *v10; // rax
  SSInvokableBase *v11; // rsi
  SSInvokedMethod *v12; // rbx
  SSInstance *receiver_pp; // [rsp+40h] [rbp+8h]

  v5 = this;
  receiver_pp = this;
  v6 = mcall->i_scope_p;
  v7 = caller_p;
  v8 = scope_p;
  v9 = mcall;
  if ( !v6 )
    v6 = v5->i_class_p;
  v10 = SSClass::get_method_inherited_receiver(v6, &mcall->i_name, &receiver_pp, caller_p);
  v11 = (SSInvokableBase *)&v10->vfptr;
  if ( v10 )
  {
    v12 = SSInvokedMethod::pool_new(v7, (SSObjectBase *)&receiver_pp->vfptr, v10);
    SSInvokedContextBase::data_append_args_exprs(
      (SSInvokedContextBase *)&v12->vfptr,
      (APArrayBase<SSExpressionBase> *)&v9->i_arguments.i_count,
      v11,
      v8);
    ((void (__fastcall *)(SSInvokableBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v11->vfptr[1].get_custom_expr)(
      v11,
      v12,
      v7,
      result_pp);
    SSInvokedContextBase::data_bind_return_args(
      (SSInvokedContextBase *)&v12->vfptr,
      (APArrayBase<SSIdentifier> *)&v9->i_return_args.i_count,
      v11);
    SSInvokedMethod::pool_delete(v12);
  }
  else if ( result_pp )
  {
    *result_pp = SSBrain::c_nil_p;
  }
}

// File Line: 143
// RVA: 0x11FCD0
void __fastcall SSInstance::method_call(SSInstance *this, ASymbol *method_name, SSInstance **args_pp, unsigned int arg_count, SSInstance **result_pp, SSInvokedBase *caller_p)
{
  unsigned int v6; // esi
  SSInstance **v7; // rbp
  SSMethodBase *v8; // rdi
  SSInvokedMethod *v9; // rbx
  SSInstance *receiver_pp; // [rsp+30h] [rbp+8h]

  v6 = arg_count;
  receiver_pp = this;
  v7 = args_pp;
  v8 = SSClass::get_method_inherited_receiver(this->i_class_p, method_name, &receiver_pp, caller_p);
  v9 = SSInvokedMethod::pool_new(caller_p, (SSObjectBase *)&receiver_pp->vfptr, v8);
  SSInvokedContextBase::data_append_args((SSInvokedContextBase *)&v9->vfptr, v7, v6, (SSInvokableBase *)&v8->vfptr);
  ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, SSInstance **))v8->vfptr[1].get_custom_expr)(
    v8,
    v9,
    caller_p,
    result_pp);
  SSInvokedMethod::pool_delete(v9);
}

// File Line: 220
// RVA: 0x1118A0
void __fastcall SSInstance::call_default_constructor(SSInstance *this)
{
  SSClass *v1; // r11
  SSMethodBase *v2; // rbx
  SSInstance *v3; // rdi
  __int64 v4; // rax
  signed __int64 v5; // r8
  signed __int64 v6; // r10
  signed __int64 v7; // rdx
  unsigned int v8; // er9
  _BOOL8 v9; // rcx
  _BOOL8 v10; // r9
  SSClass *v11; // rcx
  SSInvokedMethod *v12; // rax
  SSInvokedMethod *v13; // rdi

  v1 = this->i_class_p;
  v2 = 0i64;
  v3 = this;
  v4 = v1->i_methods.i_count;
  if ( !(_DWORD)v4 )
  {
LABEL_11:
    v11 = v1->i_superclass_p;
    if ( v11 )
      v2 = SSClass::get_instance_method_inherited(v11, &ASymbolX_ctor);
    if ( v2 )
      goto LABEL_14;
    return;
  }
  v5 = (signed __int64)v1->i_methods.i_array_p;
  v6 = v5 + 8 * (v4 - 1);
  while ( 1 )
  {
    v7 = v5 + 8 * ((v6 - v5) >> 4);
    v8 = *(_DWORD *)(*(_QWORD *)v7 + 8i64);
    if ( ASymbolX_ctor.i_uid < v8 )
      goto LABEL_8;
    v9 = ASymbolX_ctor.i_uid == v8;
    v10 = ASymbolX_ctor.i_uid != v8;
    if ( v9 == 1 )
      break;
    if ( v10 < 0 )
    {
LABEL_8:
      if ( v5 == v7 )
        goto LABEL_11;
      v6 = v7 - 8;
    }
    else
    {
      if ( v6 == v7 )
        goto LABEL_11;
      v5 = v7 + 8;
    }
  }
  v2 = *(SSMethodBase **)v7;
  if ( !*(_QWORD *)v7 )
    goto LABEL_11;
LABEL_14:
  v12 = SSInvokedMethod::pool_new(0i64, (SSObjectBase *)&v3->vfptr, v2);
  v13 = v12;
  if ( v2->i_params_p.i_obj_p->i_params.i_count )
    SSInvokedContextBase::data_append_args((SSInvokedContextBase *)&v12->vfptr, 0i64, 0, (SSInvokableBase *)&v2->vfptr);
  ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, _QWORD))v2->vfptr[1].get_custom_expr)(
    v2,
    v13,
    0i64,
    0i64);
  SSInvokedMethod::pool_delete(v13);
}

// File Line: 253
// RVA: 0x111990
void __fastcall SSInstance::call_destructor(SSInstance *this)
{
  SSClass *v1; // rax
  SSMethodBase *v2; // rdi
  SSInvokedMethod *v3; // rbx

  v1 = this->i_class_p;
  v2 = v1->i_destructor_p;
  if ( v2 )
  {
    v3 = SSInvokedMethod::pool_new(0i64, (SSObjectBase *)&this->vfptr, v1->i_destructor_p);
    ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, _QWORD))v2->vfptr[1].get_custom_expr)(
      v2,
      v3,
      0i64,
      0i64);
    SSInvokedMethod::pool_delete(v3);
  }
}

// File Line: 344
// RVA: 0x1129C0
SSInvokedCoroutine *__fastcall SSInstance::coroutine_call(SSInstance *this, ASymbol *coroutine_name, SSInstance **args_pp, unsigned int arg_count, bool immediate, float update_interval, SSInvokedBase *caller_p, SSActor *updater_p)
{
  SSInstance *v8; // rsi
  unsigned int v9; // ebp
  SSInstance **v10; // r14
  SSInvokedCoroutine *result; // rax
  SSInvokableBase *v12; // rdi
  AObjReusePool<SSInvokedCoroutine> *v13; // rax
  AObjReusePool<SSInvokedCoroutine> *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  __int64 v18; // rcx
  SSInvokedCoroutine **v19; // rax
  SSInvokedCoroutine *v20; // rbx
  unsigned int v21; // eax
  SSActor *v22; // rdi

  v8 = this;
  v9 = arg_count;
  v10 = args_pp;
  result = (SSInvokedCoroutine *)this->i_class_p->vfptr->get_coroutine_inherited(
                                   (SSClassDescBase *)this->i_class_p,
                                   coroutine_name);
  v12 = (SSInvokableBase *)result;
  if ( !result )
    return result;
  v13 = SSInvokedCoroutine::get_pool();
  v14 = v13;
  v15 = v13->i_pool.i_count;
  if ( v15 )
  {
    v21 = v15 - 1;
    v14->i_pool.i_count = v21;
    v18 = v21;
    v19 = v14->i_pool.i_array_p;
    goto LABEL_9;
  }
  if ( !v14->i_exp_pool.i_count )
    AObjReusePool<SSInvokedCoroutine>::append_block(v14, v14->i_expand_size);
  v16 = v14->i_exp_pool.i_count;
  if ( v16 )
  {
    v17 = v16 - 1;
    v14->i_exp_pool.i_count = v17;
    v18 = v17;
    v19 = v14->i_exp_pool.i_array_p;
LABEL_9:
    v20 = v19[v18];
    goto LABEL_10;
  }
  v20 = 0i64;
LABEL_10:
  v20->i_coroutine_p = (SSCoroutineBase *)v12;
  SSInvokedCoroutine::reset(v20, update_interval, caller_p, v8, updater_p, 0i64);
  SSInvokedContextBase::data_append_args((SSInvokedContextBase *)&v20->vfptr, v10, v9, v12);
  if ( immediate )
  {
    if ( SSInvokedCoroutine::on_update(v20) )
      return 0i64;
  }
  else
  {
    v22 = v20->i_updater_p.i_obj_p;
    if ( !v22 || v20->i_updater_p.i_ptr_id != v22->i_ptr_id )
      v22 = 0i64;
    if ( !(v20->i_flags & 1) )
    {
      APArray<SSInvokedCoroutine,SSInvokedCoroutine,ACompareAddress<SSInvokedCoroutine>>::append(
        &v22->i_icoroutines_to_update,
        v20);
      v20->i_flags |= 1u;
      if ( !(v22->i_actor_flags & 2) )
        SSActor::enable_on_update(v22, 1);
    }
  }
  return v20;
}

// File Line: 447
// RVA: 0x10E530
void __fastcall SSInstance::as_code_append(SSInstance *this, AString *str_p, bool break_new_lines, SSInvokedBase *caller_p)
{
  SSInvokedBase *v4; // rbp
  AString *v5; // rbx
  SSInstance *v6; // rsi
  unsigned int v7; // er8
  const char *v8; // rdx
  unsigned int v9; // edi
  SSClass *v10; // r11
  unsigned int v11; // eax
  unsigned int v12; // edx
  AStringRef *v13; // rbx
  bool v14; // zf
  AObjReusePool<AStringRef> *v15; // rax
  AObjBlock<AStringRef> *v16; // rcx
  unsigned __int64 v17; // rdx
  AString *v18; // rax
  unsigned int v19; // edx
  AString *v20; // rax
  unsigned int v21; // edx
  __int64 v22; // rdi
  AStringRef *v23; // rdx
  unsigned int v24; // esi
  unsigned int v25; // edi
  __int64 v26; // rdi
  __int64 v27; // rax
  SSMethodBase *v28; // rdi
  signed __int64 v29; // r8
  signed __int64 v30; // r10
  signed __int64 v31; // rdx
  unsigned int v32; // er9
  _BOOL8 v33; // rcx
  _BOOL8 v34; // r9
  SSClass *v35; // rcx
  SSInvokedMethod *v36; // rbp
  _DWORD *v37; // rcx
  __int64 v38; // [rsp+20h] [rbp-28h]
  AString v39; // [rsp+28h] [rbp-20h]
  AString v40; // [rsp+30h] [rbp-18h]
  __int64 v41; // [rsp+38h] [rbp-10h]
  AString result; // [rsp+50h] [rbp+8h]

  v41 = -2i64;
  v4 = caller_p;
  v5 = str_p;
  v6 = this;
  if ( !this )
  {
LABEL_2:
    v7 = 3;
    v8 = "nil";
LABEL_64:
    AString::append(v5, v8, v7);
    return;
  }
  v9 = str_p->i_str_ref_p->i_length;
  v10 = this->i_class_p;
  v11 = v10->i_name.i_uid;
  if ( v11 <= 0x9693548A )
  {
    switch ( v11 )
    {
      case 0x9693548A:
        ASymbol::as_str_dbg((ASymbol *)&this->i_user_data, &result);
        v21 = v9 + result.i_str_ref_p->i_length + 2;
        if ( v21 >= v5->i_str_ref_p->i_size || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
          AString::set_size(v5, v21);
        v22 = v5->i_str_ref_p->i_length + 1;
        if ( (unsigned int)v22 >= v5->i_str_ref_p->i_size
          || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
        {
          AString::set_size(v5, v22);
        }
        v5->i_str_ref_p->i_cstr_p[(unsigned int)(v22 - 1)] = 39;
        v5->i_str_ref_p->i_cstr_p[v22] = 0;
        v5->i_str_ref_p->i_length = v22;
        v23 = result.i_str_ref_p;
        v24 = result.i_str_ref_p->i_length;
        if ( v24 )
        {
          v25 = v24 + v5->i_str_ref_p->i_length;
          if ( v25 >= v5->i_str_ref_p->i_size || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
          {
            AString::set_size(v5, v25);
            v23 = result.i_str_ref_p;
          }
          memmove(&v5->i_str_ref_p->i_cstr_p[v5->i_str_ref_p->i_length], v23->i_cstr_p, v24 + 1);
          v5->i_str_ref_p->i_length = v25;
        }
        v26 = v5->i_str_ref_p->i_length + 1;
        if ( (unsigned int)v26 >= v5->i_str_ref_p->i_size
          || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
        {
          AString::set_size(v5, v26);
        }
        v5->i_str_ref_p->i_cstr_p[(unsigned int)(v26 - 1)] = 39;
        v5->i_str_ref_p->i_cstr_p[v26] = 0;
        v5->i_str_ref_p->i_length = v26;
        goto LABEL_13;
      case 0x3CC821AAu:
        v20 = AString::ctor_float(&v40, *(float *)&this->i_user_data, 6u);
        AString::append(v5, v20);
        v13 = v40.i_str_ref_p;
        break;
      case 0x5901674Cu:
        SSParser::string_to_esacpe_string(&result, (AString *)&this->i_user_data, break_new_lines);
        v19 = v9 + result.i_str_ref_p->i_length + 2;
        if ( v19 >= v5->i_str_ref_p->i_size || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
          AString::set_size(v5, v19);
        AString::append(v5, 34);
        AString::append(v5, &result);
        AString::append(v5, 34);
        goto LABEL_13;
      case 0x78A518A8u:
        v18 = AString::ctor_int(&v39, this->i_user_data, 0xAu);
        AString::append(v5, v18);
        v13 = v39.i_str_ref_p;
        break;
      case 0x8666AACD:
        ANamed::get_name_str_dbg((ANamed *)&this[1].vfptr->get_obj_type, &result);
        v12 = v9 + result.i_str_ref_p->i_length + 2;
        if ( v12 >= v5->i_str_ref_p->i_size || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
          AString::set_size(v5, v12);
        AString::append(v5, 60);
        AString::append(v5, &result);
        AString::append(v5, 62);
LABEL_13:
        v13 = result.i_str_ref_p;
        break;
      default:
        goto LABEL_45;
    }
    v14 = v13->i_ref_count-- == 1;
    if ( v14 )
    {
      if ( v13->i_deallocate )
        AMemory::c_free_func(v13->i_cstr_p);
      v15 = AStringRef::get_pool();
      v16 = v15->i_block_p;
      v17 = (unsigned __int64)v16->i_objects_a;
      if ( (unsigned __int64)v13 < v17 || (unsigned __int64)v13 >= v17 + 24i64 * v16->i_size )
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v15->i_exp_pool, v13);
      else
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v15->i_pool, v13);
    }
    return;
  }
  switch ( v11 )
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
      goto LABEL_64;
    case 0xDCF92817:
      goto LABEL_2;
    case 0xE646BE1C:
      v7 = 14;
      v8 = "Closure object";
      goto LABEL_64;
  }
LABEL_45:
  v27 = v10->i_methods.i_count;
  v28 = 0i64;
  if ( !(_DWORD)v27 )
  {
LABEL_55:
    v35 = v10->i_superclass_p;
    if ( v35 )
      v28 = SSClass::get_instance_method_inherited(v35, &ASymbol_String);
    goto LABEL_57;
  }
  v29 = (signed __int64)v10->i_methods.i_array_p;
  v30 = v29 + 8 * (v27 - 1);
  while ( 1 )
  {
    v31 = v29 + 8 * ((v30 - v29) >> 4);
    v32 = *(_DWORD *)(*(_QWORD *)v31 + 8i64);
    if ( ASymbol_String.i_uid < v32 )
      goto LABEL_52;
    v33 = ASymbol_String.i_uid == v32;
    v34 = ASymbol_String.i_uid != v32;
    if ( v33 == 1 )
      break;
    if ( v34 < 0 )
    {
LABEL_52:
      if ( v29 == v31 )
        goto LABEL_55;
      v30 = v31 - 8;
    }
    else
    {
      if ( v30 == v31 )
        goto LABEL_55;
      v29 = v31 + 8;
    }
  }
  v28 = *(SSMethodBase **)v31;
  if ( !*(_QWORD *)v31 )
    goto LABEL_55;
LABEL_57:
  v36 = SSInvokedMethod::pool_new(v4, (SSObjectBase *)&v6->vfptr, v28);
  ++v6->i_ref_count;
  ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, _QWORD, __int64 *))v28->vfptr[1].get_custom_expr)(
    v28,
    v36,
    0i64,
    &v38);
  AString::append(v5, (AString *)(v38 + 32));
  v37 = (_DWORD *)v38;
  v14 = *(_DWORD *)(v38 + 16) == 1;
  --v37[4];
  if ( v14 )
  {
    v37[4] = 2147483648;
    (*(void (**)(void))(*(_QWORD *)v37 + 112i64))();
  }
  --v6->i_ref_count;
  SSInvokedMethod::pool_delete(v36);
}

// File Line: 561
// RVA: 0x118C10
AObjReusePool<SSInstance> *__fastcall SSInstance::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSInstance **v2; // rax

  if ( _S5_3 & 1 )
    return &s_pool_1;
  _S5_3 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_instance;
  v1 = Skookum::get_lib_vals()->i_pool_init_instance;
  s_pool_1.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175BC8 = 0i64;
  unk_142175BD0 = 0;
  if ( v1 )
  {
    unk_142175BD0 = v1;
    v2 = APArrayBase<SSInstance>::alloc_array(v1);
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
  unk_142175C10 = v0;
  AObjReusePool<SSInstance>::append_block(&s_pool_1, v1);
  atexit(SSInstance::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_1;
}

// File Line: 575
// RVA: 0x117800
SSInstance *__fastcall SSInstance::get_data_by_name(SSInstance *this, ASymbol *name)
{
  ASymbol *v2; // rbx
  __int64 v3; // rax

  v2 = name;
  v3 = ((__int64 (*)(void))this->i_class_p->vfptr->get_metaclass)();
  return (SSInstance *)(*(__int64 (__fastcall **)(__int64, ASymbol *))(*(_QWORD *)(v3 + 8) + 32i64))(v3 + 8, v2);
}

// File Line: 594
// RVA: 0x13C4E0
void __fastcall SSInstance::set_data_by_name(SSInstance *this, ASymbol *name, SSInstance *obj_p)
{
  SSInstance *v3; // rbx
  ASymbol *v4; // rdi
  __int64 v5; // rax

  v3 = obj_p;
  v4 = name;
  v5 = ((__int64 (*)(void))this->i_class_p->vfptr->get_metaclass)();
  (*(void (__fastcall **)(__int64, ASymbol *, SSInstance *))(*(_QWORD *)(v5 + 8) + 40i64))(v5 + 8, v4, v3);
}

// File Line: 637
// RVA: 0x1215E0
void __fastcall SSInstance::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // r8
  SSObjectBase *v4; // rcx
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
    v4 = scope_p->i_scope_p.i_obj_p;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v5 = ANamed::get_name_str_dbg((ANamed *)(*(_QWORD *)&v4[1].i_ptr_id + 8i64), &result);
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

// File Line: 657
// RVA: 0x125F30
void __fastcall SSInstance::mthdc_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  signed __int64 v4; // rcx
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
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( v3 && scope_p->i_scope_p.i_ptr_id == v3->i_ptr_id )
      v4 = (signed __int64)&v3[-1].i_ptr_id;
    else
      v4 = 0i64;
    v5 = ANamed::get_name_str_dbg((ANamed *)(*(_QWORD *)(v4 + 56) + 8i64), &result);
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

// File Line: 727
// RVA: 0x1264C0
void __fastcall SSInstance::mthdc_is_class(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  bool v2; // bl
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  signed __int64 v5; // r8
  SSObjectBase *v6; // rdx
  signed __int64 v7; // rdx
  __int64 v8; // rax
  SSClass *v9; // rcx

  if ( result_pp )
  {
    v2 = 0;
    v3 = result_pp;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p;
    v5 = (signed __int64)&v4[-1].i_user_data2;
    if ( !v4 )
      v5 = 0i64;
    v6 = scope_p->i_scope_p.i_obj_p;
    if ( v6 && scope_p->i_scope_p.i_ptr_id == v6->i_ptr_id )
      v7 = (signed __int64)&v6[-1].i_ptr_id;
    else
      v7 = 0i64;
    v8 = *(_QWORD *)(v7 + 56);
    if ( *(_QWORD *)(v5 + 56) == v8
      || (v9 = *(SSClass **)(v8 + 16)) != 0i64 && SSClass::is_class(v9, *(SSClass **)(v5 + 56)) )
    {
      v2 = 1;
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v2);
  }
}

// File Line: 753
// RVA: 0x126550
void __fastcall SSInstance::mthdc_is_class_actor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  signed __int64 v4; // rcx
  char v5; // al

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = result_pp;
    if ( v2 && scope_p->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v4 = (signed __int64)&v2[-1].i_ptr_id;
    else
      v4 = 0i64;
    v5 = (*(__int64 (**)(void))(**(_QWORD **)(v4 + 56) + 64i64))();
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 779
// RVA: 0x1265D0
void __fastcall SSInstance::mthdc_is_subclass(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  bool v2; // bl
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  signed __int64 v5; // r8
  SSObjectBase *v6; // rdx
  signed __int64 v7; // rax
  SSClass *v8; // rdx
  SSClass *v9; // rcx

  if ( result_pp )
  {
    v2 = 0;
    v3 = result_pp;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p;
    v5 = (signed __int64)&v4[-1].i_user_data2;
    if ( !v4 )
      v5 = 0i64;
    v6 = scope_p->i_scope_p.i_obj_p;
    if ( !v6 || (v7 = (signed __int64)&v6[-1].i_ptr_id, scope_p->i_scope_p.i_ptr_id != v6->i_ptr_id) )
      v7 = 0i64;
    v8 = *(SSClass **)(v5 + 56);
    v9 = *(SSClass **)(*(_QWORD *)(v7 + 56) + 16i64);
    if ( v9 == v8 || v9 && SSClass::is_subclass(v9, v8) )
      v2 = 1;
    *v3 = (SSInstance *)SSBoolean::pool_new(v2);
  }
}

// File Line: 806
// RVA: 0x126650
void __fastcall SSInstance::mthdc_is_superclass(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  bool v2; // bl
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  signed __int64 v5; // r8
  SSObjectBase *v6; // rdx
  signed __int64 v7; // rdx
  SSClass *v8; // rcx
  SSClass *v9; // rdx

  if ( result_pp )
  {
    v2 = 0;
    v3 = result_pp;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p;
    v5 = (signed __int64)&v4[-1].i_user_data2;
    if ( !v4 )
      v5 = 0i64;
    v6 = scope_p->i_scope_p.i_obj_p;
    if ( v6 && scope_p->i_scope_p.i_ptr_id == v6->i_ptr_id )
      v7 = (signed __int64)&v6[-1].i_ptr_id;
    else
      v7 = 0i64;
    v8 = *(SSClass **)(v7 + 56);
    v9 = *(SSClass **)(*(_QWORD *)(v5 + 56) + 16i64);
    if ( v9 == v8 || v9 && SSClass::is_superclass(v8, v9) )
      v2 = 1;
    *v3 = (SSInstance *)SSBoolean::pool_new(v2);
  }
}

// File Line: 832
// RVA: 0x126750
void __fastcall SSInstance::mthdc_set_data_untyped(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  scope_p->vfptr->set_data_by_name(
    (SSObjectBase *)scope_p,
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
  __int64 v0; // rax
  SSMethodBase **v1; // r8
  signed __int64 v2; // r10
  signed __int64 v3; // rdx
  unsigned int v4; // er9
  _BOOL8 v5; // r9
  __int64 v6; // rbx
  __int64 v7; // rbp
  SSParameters *v8; // rsi
  SSParameters *v9; // r14
  bool v10; // zf
  __int64 v11; // rax
  SSMethodBase **v12; // r8
  signed __int64 v13; // r10
  signed __int64 v14; // rdx
  unsigned int v15; // er9
  _BOOL8 v16; // r9
  __int64 v17; // rbx
  __int64 v18; // rbp
  SSParameters *v19; // rsi
  SSParameters *v20; // r14
  SSClass *v21; // rbx
  ASymbol *v22; // rax
  SSClass *v23; // r11
  __int64 v24; // rax
  SSCoroutineBase **v25; // r8
  signed __int64 v26; // r10
  signed __int64 v27; // rdx
  unsigned int v28; // er9
  _BOOL8 v29; // r9
  __int64 v30; // rcx
  __int64 v31; // rax
  signed __int64 v32; // r8
  signed __int64 v33; // r10
  signed __int64 v34; // rdx
  unsigned int v35; // er9
  _BOOL8 v36; // r9
  __int64 v37; // rcx
  __int64 v38; // [rsp+30h] [rbp-48h]
  __int64 result; // [rsp+80h] [rbp+8h]
  SSParameters *v40; // [rsp+88h] [rbp+10h]
  __int64 v41; // [rsp+90h] [rbp+18h]

  v0 = SSBrain::c_object_class_p->i_methods.i_count;
  if ( (_DWORD)v0 )
  {
    v1 = SSBrain::c_object_class_p->i_methods.i_array_p;
    v2 = (signed __int64)&v1[v0 - 1];
    while ( 1 )
    {
      v3 = (signed __int64)&v1[(v2 - (signed __int64)v1) >> 4];
      v4 = *(_DWORD *)(*(_QWORD *)v3 + 8i64);
      if ( ASymbol_String.i_uid < v4 )
        goto LABEL_75;
      v5 = ASymbol_String.i_uid != v4;
      if ( !v5 )
      {
        v6 = *(_QWORD *)v3;
        goto LABEL_12;
      }
      if ( v5 < 0 )
      {
LABEL_75:
        if ( v1 == (SSMethodBase **)v3 )
          break;
        v2 = v3 - 8;
      }
      else
      {
        if ( v2 == v3 )
          break;
        v1 = (SSMethodBase **)(v3 + 8);
      }
    }
  }
  v6 = 0i64;
LABEL_12:
  result = v6;
  if ( v6 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6) == 1 )
    {
      *(_QWORD *)(v6 + 32) = SSInstance::mthd_as_string;
    }
    else
    {
      v7 = *(_QWORD *)(v6 + 16);
      v8 = *(SSParameters **)(v6 + 24);
      v40 = v8;
      if ( v8 )
        ++v8->i_ref_count;
      v9 = *(SSParameters **)(v6 + 24);
      if ( v9 )
      {
        v10 = v9->i_ref_count-- == 1;
        if ( v10 )
        {
          v9->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v9);
          AMemory::c_free_func(v9);
        }
        *(_QWORD *)(v6 + 24) = 0i64;
      }
      v41 = v6;
      *(ASymbol *)(v6 + 8) = ASymbol_String;
      *(_QWORD *)(v6 + 16) = v7;
      *(_QWORD *)v6 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v6 + 24) = v8;
      if ( v8 )
        ++v8->i_ref_count;
      *(_QWORD *)v6 = &SSMethodBase::`vftable';
      *(_QWORD *)v6 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v6 + 32) = SSInstance::mthd_as_string;
      if ( v8 )
      {
        v10 = v8->i_ref_count-- == 1;
        if ( v10 )
        {
          v8->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v8);
          AMemory::c_free_func(v8);
        }
      }
    }
  }
  v11 = SSBrain::c_object_class_p->i_methods.i_count;
  if ( (_DWORD)v11 )
  {
    v12 = SSBrain::c_object_class_p->i_methods.i_array_p;
    v13 = (signed __int64)&v12[v11 - 1];
    while ( 1 )
    {
      v14 = (signed __int64)&v12[(v13 - (signed __int64)v12) >> 4];
      v15 = *(_DWORD *)(*(_QWORD *)v14 + 8i64);
      if ( ASymbol_is.i_uid < v15 )
        goto LABEL_76;
      v16 = ASymbol_is.i_uid != v15;
      if ( !v16 )
      {
        v17 = *(_QWORD *)v14;
        goto LABEL_37;
      }
      if ( v16 < 0 )
      {
LABEL_76:
        if ( v12 == (SSMethodBase **)v14 )
          break;
        v13 = v14 - 8;
      }
      else
      {
        if ( v13 == v14 )
          break;
        v12 = (SSMethodBase **)(v14 + 8);
      }
    }
  }
  v17 = 0i64;
LABEL_37:
  result = v17;
  if ( v17 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSActor::mthd_op_equals;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v40 = v19;
      if ( v19 )
        ++v19->i_ref_count;
      v20 = *(SSParameters **)(v17 + 24);
      if ( v20 )
      {
        v10 = v20->i_ref_count-- == 1;
        if ( v10 )
        {
          v20->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
        *(_QWORD *)(v17 + 24) = 0i64;
      }
      v41 = v17;
      *(ASymbol *)(v17 + 8) = ASymbol_is;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable';
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable';
      *(_QWORD *)v17 = &SSMethodFunc::`vftable';
      *(_QWORD *)(v17 + 32) = SSActor::mthd_op_equals;
      if ( v19 )
      {
        v10 = v19->i_ref_count-- == 1;
        if ( v10 )
        {
          v19->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v19);
          AMemory::c_free_func(v19);
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
  v21 = SSBrain::c_object_class_p;
  v22 = ASymbol::create((ASymbol *)&result, "set_data_untyped", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v21, v22, SSInstance::mthdc_set_data_untyped, SSBindFlag_class_no_rebind);
  LODWORD(v38) = 0;
  v23 = SSBrain::c_object_class_p;
  v24 = SSBrain::c_object_class_p->i_coroutines.i_count;
  if ( (_DWORD)v24 )
  {
    v25 = SSBrain::c_object_class_p->i_coroutines.i_array_p;
    v26 = (signed __int64)&v25[v24 - 1];
    while ( 1 )
    {
      v27 = (signed __int64)&v25[(v26 - (signed __int64)v25) >> 4];
      v28 = *(_DWORD *)(*(_QWORD *)v27 + 8i64);
      if ( ASymbol__wait.i_uid < v28 )
        goto LABEL_77;
      v29 = ASymbol__wait.i_uid != v28;
      if ( !v29 )
      {
        v30 = *(_QWORD *)v27;
        if ( *(_QWORD *)v27 )
        {
          *(_QWORD *)(v30 + 32) = SSInstance::coro_wait;
          *(_QWORD *)(v30 + 40) = v38;
          v23 = SSBrain::c_object_class_p;
        }
        break;
      }
      if ( v29 < 0 )
      {
LABEL_77:
        if ( v25 == (SSCoroutineBase **)v27 )
          break;
        v26 = v27 - 8;
      }
      else
      {
        if ( v26 == v27 )
          break;
        v25 = (SSCoroutineBase **)(v27 + 8);
      }
    }
  }
  LODWORD(v38) = 0;
  v31 = v23->i_coroutines.i_count;
  if ( !(_DWORD)v31 )
    return;
  v32 = (signed __int64)v23->i_coroutines.i_array_p;
  v33 = v32 + 8 * (v31 - 1);
  while ( 1 )
  {
    v34 = v32 + 8 * ((v33 - v32) >> 4);
    v35 = *(_DWORD *)(*(_QWORD *)v34 + 8i64);
    if ( ASymbol__wait_until.i_uid < v35 )
      goto LABEL_69;
    v36 = ASymbol__wait_until.i_uid != v35;
    if ( !v36 )
      break;
    if ( v36 < 0 )
    {
LABEL_69:
      if ( v32 == v34 )
        return;
      v33 = v34 - 8;
    }
    else
    {
      if ( v33 == v34 )
        return;
      v32 = v34 + 8;
    }
  }
  v37 = *(_QWORD *)v34;
  if ( *(_QWORD *)v34 )
  {
    *(_QWORD *)(v37 + 32) = SSInstance::coro_wait_until;
    *(_QWORD *)(v37 + 40) = v38;
  }
}

