// File Line: 62
// RVA: 0x14614C0
SSExpressionBase *dynamic_initializer_for__SSDebugInfo::c_expr_p__()
{
  SSExpressionBase *result; // rax

  result = SSDebugInfo::c_expr_default_p;
  SSDebugInfo::c_expr_p = SSDebugInfo::c_expr_default_p;
  return result;
}

// File Line: 615
// RVA: 0x1461500
__int64 dynamic_initializer_for__SSDebug::c_print_mem_ext_p__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSDebug::c_print_mem_ext_p__);
}

// File Line: 1085
// RVA: 0x11A260
void SSDebug::info(void)
{
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v5; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+40h] [rbp+8h] BYREF

  str.i_str_ref_p = AStringRef::get_empty();
  ++str.i_str_ref_p->i_ref_count;
  AString::append(&str, "\n[Skookum call stack not available.]\n", 0x25u);
  ADebug::print(&str, 1);
  i_str_ref_p = str.i_str_ref_p;
  if ( str.i_str_ref_p->i_ref_count-- == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v5 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool,
                                                                                        !v5) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
}

// File Line: 1229
// RVA: 0x1316E0
void __fastcall SSDebug::print_error(AString *err_msg, int level)
{
  int v4; // esi
  unsigned int i_length; // ebx
  AStringRef *i_str_ref_p; // rax
  unsigned int v7; // edi
  AStringRef *v8; // rbx
  bool v9; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  AStringRef *v13; // rbx
  AObjReusePool<AStringRef> *v14; // rax
  AObjBlock<AStringRef> *v15; // rcx
  unsigned __int64 v16; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *elem; // [rsp+30h] [rbp-828h] BYREF
  int v20; // [rsp+38h] [rbp-820h]
  __int64 v21; // [rsp+40h] [rbp-818h]
  char buffer_p[2048]; // [rsp+50h] [rbp-808h] BYREF
  AString str; // [rsp+860h] [rbp+8h] BYREF

  v21 = -2i64;
  AString::AString(&str, buffer_p, 0x800u, 0, 0);
  if ( level < 3 )
  {
    AString::append(&str, "\nWARNING (Skookum): ", 0x14u);
    v4 = 3;
  }
  else
  {
    AString::append(&str, "\nERROR (Skookum): ", 0x12u);
    v4 = 2;
  }
  i_length = err_msg->i_str_ref_p->i_length;
  if ( i_length )
  {
    i_str_ref_p = str.i_str_ref_p;
    v7 = i_length + str.i_str_ref_p->i_length;
    if ( v7 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(&str, v7);
      i_str_ref_p = str.i_str_ref_p;
    }
    memmove(&i_str_ref_p->i_cstr_p[i_str_ref_p->i_length], err_msg->i_str_ref_p->i_cstr_p, i_length + 1);
    str.i_str_ref_p->i_length = v7;
  }
  AString::append(&str, "\n\n", 2u);
  if ( SSDebug::c_log_func_p )
  {
    elem = str.i_str_ref_p;
    ++str.i_str_ref_p->i_ref_count;
    v20 = v4;
    SSDebug::c_log_func_p->vfptr->invoke(SSDebug::c_log_func_p, (SSPrintInfo *)&elem);
    v8 = elem;
    v9 = elem->i_ref_count-- == 1;
    if ( v9 )
    {
      if ( v8->i_deallocate )
        AMemory::c_free_func(v8->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v8 < i_objects_a || (unsigned __int64)v8 >= i_objects_a + 24i64 * i_block_p->i_size )
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&pool->i_exp_pool, v8);
      else
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&pool->i_pool, v8);
    }
  }
  else
  {
    ADebug::print(&str, 0);
  }
  v13 = str.i_str_ref_p;
  v9 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v9 )
  {
    if ( v13->i_deallocate )
      AMemory::c_free_func(v13->i_cstr_p);
    v14 = AStringRef::get_pool();
    v15 = v14->i_block_p;
    v16 = (unsigned __int64)v15->i_objects_a;
    if ( (unsigned __int64)v13 < v16
      || (v17 = (unsigned __int64)v13 < v16 + 24i64 * v15->i_size, p_i_exp_pool = &v14->i_pool, !v17) )
    {
      p_i_exp_pool = &v14->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v13);
  }
}

// File Line: 1311
// RVA: 0x1318E0
void __fastcall SSDebug::print_error(
        SSParser::eResult result,
        AString *path,
        AString *code_p,
        unsigned int result_pos,
        unsigned int result_start,
        unsigned int start_pos)
{
  unsigned int v10; // r15d
  AString *result_context_string; // rsi
  unsigned int i_length; // edi
  AStringRef *i_str_ref_p; // rcx
  unsigned int v14; // ebx
  AStringRef *v15; // rbx
  bool v16; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v20; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *v22; // rax
  __int64 v23; // rbx
  AString *result_string; // rsi
  unsigned int v25; // edi
  AStringRef *v26; // rcx
  unsigned int v27; // ebx
  AStringRef *v28; // rbx
  AObjReusePool<AStringRef> *v29; // rax
  AObjBlock<AStringRef> *v30; // rcx
  unsigned __int64 v31; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  unsigned int v33; // edi
  AStringRef *v34; // rax
  unsigned int v35; // ebx
  AStringRef *v36; // rbx
  AObjReusePool<AStringRef> *v37; // rax
  AObjBlock<AStringRef> *v38; // rcx
  unsigned __int64 v39; // rdx
  AStringRef *v40; // rbx
  AObjReusePool<AStringRef> *v41; // rax
  AObjBlock<AStringRef> *v42; // rcx
  unsigned __int64 v43; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v44; // rcx
  AStringRef *elem; // [rsp+30h] [rbp-D0h] BYREF
  int v46; // [rsp+38h] [rbp-C8h]
  __int64 v47; // [rsp+40h] [rbp-C0h]
  char buffer_p[2096]; // [rsp+50h] [rbp-B0h] BYREF
  AString str; // [rsp+898h] [rbp+798h] BYREF
  AString resulta; // [rsp+8A0h] [rbp+7A0h] BYREF

  v47 = -2i64;
  AString::AString(&str, buffer_p, 0x800u, 0, 0);
  AString::append(&str, "\n\n", 0xFFFFFFFF);
  v10 = result_start;
  if ( code_p )
  {
    result_context_string = SSParser::get_result_context_string(
                              &resulta,
                              code_p,
                              result,
                              result_pos,
                              result_start,
                              start_pos);
    i_length = result_context_string->i_str_ref_p->i_length;
    if ( i_length )
    {
      i_str_ref_p = str.i_str_ref_p;
      v14 = i_length + str.i_str_ref_p->i_length;
      if ( v14 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v14);
        i_str_ref_p = str.i_str_ref_p;
      }
      memmove(&i_str_ref_p->i_cstr_p[i_str_ref_p->i_length], result_context_string->i_str_ref_p->i_cstr_p, i_length + 1);
      str.i_str_ref_p->i_length = v14;
    }
    v15 = resulta.i_str_ref_p;
    v16 = resulta.i_str_ref_p->i_ref_count-- == 1;
    if ( v16 )
    {
      if ( v15->i_deallocate )
        AMemory::c_free_func(v15->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v15 < i_objects_a
        || (v20 = (unsigned __int64)v15 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v20) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v15);
    }
    v22 = str.i_str_ref_p;
    v23 = str.i_str_ref_p->i_length + 1;
    if ( (unsigned int)v23 >= str.i_str_ref_p->i_size
      || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(&str, v23);
      v22 = str.i_str_ref_p;
    }
    v22->i_cstr_p[(unsigned int)(v23 - 1)] = 10;
    str.i_str_ref_p->i_cstr_p[v23] = 0;
    str.i_str_ref_p->i_length = v23;
  }
  else
  {
    AString::append(&str, "\nERROR: ", 0xFFFFFFFF);
    result_string = SSParser::get_result_string(&resulta, (unsigned int)result);
    v25 = result_string->i_str_ref_p->i_length;
    if ( v25 )
    {
      v26 = str.i_str_ref_p;
      v27 = v25 + str.i_str_ref_p->i_length;
      if ( v27 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v27);
        v26 = str.i_str_ref_p;
      }
      memmove(&v26->i_cstr_p[v26->i_length], result_string->i_str_ref_p->i_cstr_p, v25 + 1);
      str.i_str_ref_p->i_length = v27;
    }
    v28 = resulta.i_str_ref_p;
    v16 = resulta.i_str_ref_p->i_ref_count-- == 1;
    if ( v16 )
    {
      if ( v28->i_deallocate )
        AMemory::c_free_func(v28->i_cstr_p);
      v29 = AStringRef::get_pool();
      v30 = v29->i_block_p;
      v31 = (unsigned __int64)v30->i_objects_a;
      if ( (unsigned __int64)v28 < v31
        || (v20 = (unsigned __int64)v28 < v31 + 24i64 * v30->i_size, p_i_pool = &v29->i_pool, !v20) )
      {
        p_i_pool = &v29->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v28);
    }
    AString::append(&str, "\n\n", 2u);
  }
  if ( path->i_str_ref_p->i_length )
  {
    AString::append(&str, "File: ", 6u);
    v33 = path->i_str_ref_p->i_length;
    if ( v33 )
    {
      v34 = str.i_str_ref_p;
      v35 = v33 + str.i_str_ref_p->i_length;
      if ( v35 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v35);
        v34 = str.i_str_ref_p;
      }
      memmove(&v34->i_cstr_p[v34->i_length], path->i_str_ref_p->i_cstr_p, v33 + 1);
      str.i_str_ref_p->i_length = v35;
    }
  }
  else
  {
    if ( !code_p )
      goto LABEL_46;
    AString::append(&str, "Script code index: ", 0x13u);
  }
  if ( code_p && (!path->i_str_ref_p->i_length || result_pos) )
  {
    if ( v10 == -1 || result_pos == v10 )
      AString::append_format(&str, "[%u]\n", result_pos);
    else
      AString::append_format(&str, "[%u-%u]\n", v10, result_pos);
  }
LABEL_46:
  if ( SSDebug::c_log_func_p )
  {
    elem = str.i_str_ref_p;
    ++str.i_str_ref_p->i_ref_count;
    v46 = (result < Result_err__start) + 2;
    SSDebug::c_log_func_p->vfptr->invoke(SSDebug::c_log_func_p, (SSPrintInfo *)&elem);
    v36 = elem;
    v16 = elem->i_ref_count-- == 1;
    if ( v16 )
    {
      if ( v36->i_deallocate )
        AMemory::c_free_func(v36->i_cstr_p);
      v37 = AStringRef::get_pool();
      v38 = v37->i_block_p;
      v39 = (unsigned __int64)v38->i_objects_a;
      if ( (unsigned __int64)v36 < v39 || (unsigned __int64)v36 >= v39 + 24i64 * v38->i_size )
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v37->i_exp_pool, v36);
      else
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v37->i_pool, v36);
    }
  }
  else
  {
    ADebug::print(&str, 0);
  }
  v40 = str.i_str_ref_p;
  v16 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v16 )
  {
    if ( v40->i_deallocate )
      AMemory::c_free_func(v40->i_cstr_p);
    v41 = AStringRef::get_pool();
    v42 = v41->i_block_p;
    v43 = (unsigned __int64)v42->i_objects_a;
    if ( (unsigned __int64)v40 < v43
      || (v20 = (unsigned __int64)v40 < v43 + 24i64 * v42->i_size, v44 = &v41->i_pool, !v20) )
    {
      v44 = &v41->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v44, v40);
  }
}

// File Line: 2718
// RVA: 0x126010
void __fastcall SSDebug::mthdc_get_hook_names(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  AStringRef *empty; // rbx
  SSInstance *v4; // rax
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  if ( result_pp )
  {
    empty = AStringRef::get_empty();
    ++empty->i_ref_count;
    v4 = SSInstance::pool_new(SSBrain::c_string_class_p);
    if ( v4 != (SSInstance *)-32i64 )
    {
      v4->i_user_data = (unsigned __int64)empty;
      ++empty->i_ref_count;
    }
    *result_pp = v4;
    if ( empty->i_ref_count-- == 1 )
    {
      if ( empty->i_deallocate )
        AMemory::c_free_func(empty->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)empty < i_objects_a
        || (v9 = (unsigned __int64)empty < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v9) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, empty);
    }
  }
}

// File Line: 2815
// RVA: 0x1265A0
void __fastcall SSDebug::mthdc_is_engine_present(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  if ( result_pp )
    *result_pp = SSBoolean::pool_new(SSDebug::c_engine_present_b);
}

// File Line: 2950
// RVA: 0x126770
void __fastcall SSDebug::mthdc_sym_to_str(SSInvokedMethod *scope_p, SSInstance **result_pp)
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
    v3 = ASymbol::as_str_dbg((ASymbol *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data, &result);
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

// File Line: 2964
// RVA: 0x133470
void SSDebug::register_atomic(void)
{
  SSClass *v0; // rbx
  ASymbol *v1; // rax
  SSClass *v2; // rbx
  ASymbol *v3; // rax
  SSClass *v4; // rbx
  ASymbol *v5; // rax
  SSClass *v6; // rbx
  ASymbol *v7; // rax
  SSClass *v8; // rbx
  ASymbol *v9; // rax
  SSClass *v10; // rbx
  ASymbol *v11; // rax
  SSClass *v12; // rbx
  ASymbol *v13; // rax
  SSClass *v14; // rbx
  ASymbol *v15; // rax
  SSClass *v16; // rbx
  ASymbol *v17; // rax
  SSClass *v18; // rbx
  ASymbol *v19; // rax
  SSClass *v20; // rbx
  ASymbol *v21; // rax
  SSClass *v22; // rbx
  ASymbol *v23; // rax
  SSClass *v24; // rbx
  ASymbol *v25; // rax
  SSClass *v26; // rbx
  ASymbol *v27; // rax
  ASymbol result; // [rsp+30h] [rbp+8h] BYREF

  v0 = SSBrain::create_class(&ASymbol_Debug, SSBrain::c_object_class_p, 0xFFFFFFFF, 0);
  SSBrain::c_debug_class_p = v0;
  v1 = ASymbol::create(&result, "break", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v0,
    v1,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v2 = SSBrain::c_debug_class_p;
  v3 = ASymbol::create(&result, "callstack", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v2,
    v3,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v4 = SSBrain::c_debug_class_p;
  v5 = ASymbol::create(&result, "callstack_str", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v4, v5, SSDebug::mthdc_get_hook_names, SSBindFlag_class_no_rebind);
  v6 = SSBrain::c_debug_class_p;
  v7 = ASymbol::create(&result, "copy_hook", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v6,
    v7,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v8 = SSBrain::c_debug_class_p;
  v9 = ASymbol::create(&result, "enable_hook", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v8,
    v9,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v10 = SSBrain::c_debug_class_p;
  v11 = ASymbol::create(&result, "get_hook_names", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v10, v11, SSDebug::mthdc_get_hook_names, SSBindFlag_class_no_rebind);
  v12 = SSBrain::c_debug_class_p;
  v13 = ASymbol::create(&result, "hook_condition_scope_actor", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v12,
    v13,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v14 = SSBrain::c_debug_class_p;
  v15 = ASymbol::create(&result, "hook_condition_invoked_caller", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v14,
    v15,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v16 = SSBrain::c_debug_class_p;
  v17 = ASymbol::create(&result, "hook_condition_updater_class", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v16,
    v17,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v18 = SSBrain::c_debug_class_p;
  v19 = ASymbol::create(&result, "is_engine_present", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v18, v19, SSDebug::mthdc_is_engine_present, SSBindFlag_class_no_rebind);
  v20 = SSBrain::c_debug_class_p;
  v21 = ASymbol::create(&result, "is_hook_enabled", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v20, v21, UFG::TSSmoketest::MthdC_start_ai_test, SSBindFlag_class_no_rebind);
  v22 = SSBrain::c_debug_class_p;
  v23 = ASymbol::create(&result, "print", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v22,
    v23,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v24 = SSBrain::c_debug_class_p;
  v25 = ASymbol::create(&result, "println", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v24,
    v25,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_class_no_rebind);
  v26 = SSBrain::c_debug_class_p;
  v27 = ASymbol::create(&result, "sym_to_str", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v26, v27, SSDebug::mthdc_sym_to_str, SSBindFlag_class_no_rebind);
  if ( !SSBrain::c_debug_class_p )
    SSDebug::info();
}

