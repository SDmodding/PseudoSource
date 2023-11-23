// File Line: 42
// RVA: 0x1463360
__int64 dynamic_initializer_for__ASymbol_is__()
{
  ASymbol::create(&ASymbol_is, "is", 0xFFFFFFFF, ATerm_long);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ASymbol_is__);
}

// File Line: 43
// RVA: 0x1461B60
__int64 dynamic_initializer_for__ASymbolX_op_not__()
{
  ASymbol::create(&ASymbolX_op_not, "~", 0xFFFFFFFF, ATerm_long);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ASymbolX_op_not__);
}

// File Line: 59
// RVA: 0x10F260
SSInstance *__fastcall SSSymbol::as_instance(ASymbol *sym)
{
  SSInstance *result; // rax

  result = SSInstance::pool_new(SSBrain::c_symbol_class_p);
  if ( result != (SSInstance *)-32i64 )
    LODWORD(result->i_user_data) = (ASymbol)sym->i_uid;
  return result;
}

// File Line: 97
// RVA: 0x123570
void __fastcall SSSymbol::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  unsigned __int64 *p_i_user_data; // r8
  ASymbol *i_obj_p; // rcx
  ASymbol *v6; // rdi
  SSInstance *v7; // rax
  ASymbol result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v9; // [rsp+50h] [rbp+18h]
  unsigned __int64 *v10; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    p_i_user_data = &(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    i_obj_p = (ASymbol *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_uid )
      i_obj_p = 0i64;
    v6 = ASymbol::create_add(i_obj_p + 8, &result, (AString *)p_i_user_data);
    v7 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
    v9 = v7;
    v10 = &v7->i_user_data;
    if ( v7 != (SSInstance *)-32i64 )
      LODWORD(v7->i_user_data) = (ASymbol)v6->i_uid;
    *result_pp = v7;
  }
}

// File Line: 115
// RVA: 0x1236D0
void __fastcall SSSymbol::mthd_op_add_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // rdi
  ASymbol result; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  LODWORD(i_obj_p[2].vfptr) = (ASymbol)ASymbol::create_add(
                                         (ASymbol *)&i_obj_p[2],
                                         &result,
                                         (AString *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data)->i_uid;
  if ( result_pp )
  {
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
}

// File Line: 176
// RVA: 0x123D90
void __fastcall SSSymbol::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) == LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 201
// RVA: 0x1247D0
void __fastcall SSSymbol::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) != LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 226
// RVA: 0x123EF0
void __fastcall SSSymbol::mthd_op_greater(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) > LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 251
// RVA: 0x124050
void __fastcall SSSymbol::mthd_op_greater_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) >= LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 276
// RVA: 0x124250
void __fastcall SSSymbol::mthd_op_less(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) < LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 301
// RVA: 0x1243B0
void __fastcall SSSymbol::mthd_op_less_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(LODWORD(i_obj_p[2].vfptr) <= LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 316
// RVA: 0x120740
void __fastcall SSSymbol::mthd_String(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ASymbol *i_obj_p; // rcx
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
    i_obj_p = (ASymbol *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_uid )
      i_obj_p = 0i64;
    v5 = ASymbol::as_str_dbg(i_obj_p + 8, &result);
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

// File Line: 330
// RVA: 0x120810
void __fastcall SSSymbol::mthd_Symbol(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = i_obj_p;
    ++i_obj_p->i_ref_count;
  }
}

// File Line: 345
// RVA: 0x13A160
void __fastcall SSSymbol::register_atomic(__int64 a1, SSMethodBase **a2, __int64 a3, __int64 i_uid)
{
  SSMethodBase **i_array_p; // r8
  __int64 i_count; // rax
  SSMethodBase **v6; // r10
  _BOOL8 v7; // rcx
  SSMethodBase *v8; // rbx
  SSClass *i_scope_p; // r15
  SSParameters *i_obj_p; // rsi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  SSMethodBase **v15; // r10
  _BOOL8 v16; // rcx
  SSMethodBase *v17; // rbx
  SSClass *v18; // r15
  SSParameters *v19; // rsi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  SSMethodBase **v23; // r10
  _BOOL8 v24; // rcx
  SSMethodBase *v25; // rbx
  SSClass *v26; // r15
  SSParameters *v27; // rsi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  SSMethodBase **v31; // r10
  _BOOL8 v32; // rcx
  SSMethodBase *v33; // rbx
  SSClass *v34; // r15
  SSParameters *v35; // rsi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  SSMethodBase **v39; // r10
  _BOOL8 v40; // rcx
  SSMethodBase *v41; // rbx
  SSClass *v42; // r15
  SSParameters *v43; // rsi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  SSMethodBase **v47; // r10
  _BOOL8 v48; // rcx
  SSMethodBase *v49; // rbx
  SSClass *v50; // r15
  SSParameters *v51; // rsi
  SSParameters *v52; // r14
  SSMethodBase **v53; // r8
  __int64 v54; // rax
  SSMethodBase **v55; // r10
  _BOOL8 v56; // rcx
  SSMethodBase *v57; // rbx
  SSClass *v58; // r15
  SSParameters *v59; // rsi
  SSParameters *v60; // r14
  SSMethodBase **v61; // r8
  __int64 v62; // rax
  SSMethodBase **v63; // r10
  _BOOL8 v64; // rcx
  SSMethodBase *v65; // rbx
  SSClass *v66; // r15
  SSParameters *v67; // rsi
  SSParameters *v68; // r14
  SSMethodBase **v69; // r8
  __int64 v70; // rax
  SSMethodBase **v71; // r10
  _BOOL8 v72; // rcx
  SSMethodBase *v73; // rbx
  SSClass *v74; // r15
  SSParameters *v75; // rsi
  SSParameters *v76; // r14
  SSMethodBase **v77; // r8
  __int64 v78; // rax
  SSMethodBase **v79; // r10
  _BOOL8 v80; // rcx
  SSMethodBase *v81; // rbx
  SSClass *v82; // r15
  SSParameters *v83; // rsi
  SSParameters *v84; // r14
  SSMethodBase **v85; // rdx
  __int64 v86; // rax
  SSMethodBase **v87; // r9
  SSMethodBase **v88; // rbx
  _BOOL8 v89; // rcx
  SSMethodBase *v90; // rbx
  SSClass *v91; // r15
  SSParameters *v92; // rsi
  SSParameters *v93; // r14

  i_array_p = (SSMethodBase **)SSBrain::c_symbol_class_p;
  i_count = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_dtor.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v6 = a2 - 1;
      }
      v7 = ASymbolX_dtor.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_dtor.i_uid != (_DWORD)i_uid;
      if ( v7 )
        break;
      if ( v6 == a2 )
        goto LABEL_10;
      i_array_p = a2 + 1;
    }
    v8 = *a2;
  }
  else
  {
LABEL_10:
    v8 = 0i64;
  }
  if ( v8 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64, __int64))v8->vfptr->get_invoke_type)(
           v8,
           a2,
           i_array_p,
           i_uid,
           -2i64) == 1 )
    {
      v8[1].vfptr = (SSInvokableBaseVtbl *)_;
    }
    else
    {
      i_scope_p = v8->i_scope_p;
      i_obj_p = v8->i_params_p.i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v11 = v8->i_params_p.i_obj_p;
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        v8->i_params_p.i_obj_p = 0i64;
      }
      v8->i_name = ASymbolX_dtor;
      v8->i_scope_p = i_scope_p;
      v8->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v8->i_params_p.i_obj_p = i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v8->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v8->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v8[1].vfptr = (SSInvokableBaseVtbl *)_;
      if ( i_obj_p )
      {
        v12 = i_obj_p->i_ref_count-- == 1;
        if ( v12 )
        {
          i_obj_p->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(i_obj_p);
          AMemory::c_free_func(i_obj_p);
        }
      }
    }
  }
  v13 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v14 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v15 = &v13[v14 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v13[((char *)v15 - (char *)v13) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= (unsigned int)i_uid )
          break;
        if ( v13 == a2 )
          goto LABEL_34;
        v15 = a2 - 1;
      }
      v16 = ASymbol_String.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_String.i_uid != (_DWORD)i_uid;
      if ( v16 )
        break;
      if ( v15 == a2 )
        goto LABEL_34;
      v13 = a2 + 1;
    }
    v17 = *a2;
  }
  else
  {
LABEL_34:
    v17 = 0i64;
  }
  if ( v17 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v17->vfptr->get_invoke_type)(
           v17,
           a2,
           v13,
           i_uid) == 1 )
    {
      v17[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_String;
    }
    else
    {
      v18 = v17->i_scope_p;
      v19 = v17->i_params_p.i_obj_p;
      if ( v19 )
        ++v19->i_ref_count;
      v20 = v17->i_params_p.i_obj_p;
      if ( v20 )
      {
        v12 = v20->i_ref_count-- == 1;
        if ( v12 )
        {
          v20->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
        v17->i_params_p.i_obj_p = 0i64;
      }
      v17->i_name = ASymbol_String;
      v17->i_scope_p = v18;
      v17->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v17->i_params_p.i_obj_p = v19;
      if ( v19 )
        ++v19->i_ref_count;
      v17->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v17->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v17[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_String;
      if ( v19 )
      {
        v12 = v19->i_ref_count-- == 1;
        if ( v12 )
        {
          v19->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v19);
          AMemory::c_free_func(v19);
        }
      }
    }
  }
  v21 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v22 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v23 = &v21[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v21[((char *)v23 - (char *)v21) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Symbol.i_uid >= (unsigned int)i_uid )
          break;
        if ( v21 == a2 )
          goto LABEL_58;
        v23 = a2 - 1;
      }
      v24 = ASymbol_Symbol.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Symbol.i_uid != (_DWORD)i_uid;
      if ( v24 )
        break;
      if ( v23 == a2 )
        goto LABEL_58;
      v21 = a2 + 1;
    }
    v25 = *a2;
  }
  else
  {
LABEL_58:
    v25 = 0i64;
  }
  if ( v25 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v25->vfptr->get_invoke_type)(
           v25,
           a2,
           v21,
           i_uid) == 1 )
    {
      v25[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_Symbol;
    }
    else
    {
      v26 = v25->i_scope_p;
      v27 = v25->i_params_p.i_obj_p;
      if ( v27 )
        ++v27->i_ref_count;
      v28 = v25->i_params_p.i_obj_p;
      if ( v28 )
      {
        v12 = v28->i_ref_count-- == 1;
        if ( v12 )
        {
          v28->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        v25->i_params_p.i_obj_p = 0i64;
      }
      v25->i_name = ASymbol_Symbol;
      v25->i_scope_p = v26;
      v25->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v25->i_params_p.i_obj_p = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v25->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v25->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v25[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_Symbol;
      if ( v27 )
      {
        v12 = v27->i_ref_count-- == 1;
        if ( v12 )
        {
          v27->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v27);
          AMemory::c_free_func(v27);
        }
      }
    }
  }
  v29 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v30 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v31 = &v29[v30 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v29[((char *)v31 - (char *)v29) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add.i_uid >= (unsigned int)i_uid )
          break;
        if ( v29 == a2 )
          goto LABEL_82;
        v31 = a2 - 1;
      }
      v32 = ASymbol_add.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add.i_uid != (_DWORD)i_uid;
      if ( v32 )
        break;
      if ( v31 == a2 )
        goto LABEL_82;
      v29 = a2 + 1;
    }
    v33 = *a2;
  }
  else
  {
LABEL_82:
    v33 = 0i64;
  }
  if ( v33 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v33->vfptr->get_invoke_type)(
           v33,
           a2,
           v29,
           i_uid) == 1 )
    {
      v33[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_add;
    }
    else
    {
      v34 = v33->i_scope_p;
      v35 = v33->i_params_p.i_obj_p;
      if ( v35 )
        ++v35->i_ref_count;
      v36 = v33->i_params_p.i_obj_p;
      if ( v36 )
      {
        v12 = v36->i_ref_count-- == 1;
        if ( v12 )
        {
          v36->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v36);
          AMemory::c_free_func(v36);
        }
        v33->i_params_p.i_obj_p = 0i64;
      }
      v33->i_name = ASymbol_add;
      v33->i_scope_p = v34;
      v33->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v33->i_params_p.i_obj_p = v35;
      if ( v35 )
        ++v35->i_ref_count;
      v33->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v33->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v33[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_add;
      if ( v35 )
      {
        v12 = v35->i_ref_count-- == 1;
        if ( v12 )
        {
          v35->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v35);
          AMemory::c_free_func(v35);
        }
      }
    }
  }
  v37 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v38 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v39 = &v37[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v37[((char *)v39 - (char *)v37) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v37 == a2 )
          goto LABEL_106;
        v39 = a2 - 1;
      }
      v40 = ASymbol_add_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add_assign.i_uid != (_DWORD)i_uid;
      if ( v40 )
        break;
      if ( v39 == a2 )
        goto LABEL_106;
      v37 = a2 + 1;
    }
    v41 = *a2;
  }
  else
  {
LABEL_106:
    v41 = 0i64;
  }
  if ( v41 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v41->vfptr->get_invoke_type)(
           v41,
           a2,
           v37,
           i_uid) == 1 )
    {
      v41[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_add_assign;
    }
    else
    {
      v42 = v41->i_scope_p;
      v43 = v41->i_params_p.i_obj_p;
      if ( v43 )
        ++v43->i_ref_count;
      v44 = v41->i_params_p.i_obj_p;
      if ( v44 )
      {
        v12 = v44->i_ref_count-- == 1;
        if ( v12 )
        {
          v44->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v44);
          AMemory::c_free_func(v44);
        }
        v41->i_params_p.i_obj_p = 0i64;
      }
      v41->i_name = ASymbol_add_assign;
      v41->i_scope_p = v42;
      v41->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v41->i_params_p.i_obj_p = v43;
      if ( v43 )
        ++v43->i_ref_count;
      v41->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v41->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v41[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_add_assign;
      if ( v43 )
      {
        v12 = v43->i_ref_count-- == 1;
        if ( v12 )
        {
          v43->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v43);
          AMemory::c_free_func(v43);
        }
      }
    }
  }
  v45 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v46 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v47 = &v45[v46 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v45[((char *)v47 - (char *)v45) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_append.i_uid >= (unsigned int)i_uid )
          break;
        if ( v45 == a2 )
          goto LABEL_130;
        v47 = a2 - 1;
      }
      v48 = ASymbol_append.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_append.i_uid != (_DWORD)i_uid;
      if ( v48 )
        break;
      if ( v47 == a2 )
        goto LABEL_130;
      v45 = a2 + 1;
    }
    v49 = *a2;
  }
  else
  {
LABEL_130:
    v49 = 0i64;
  }
  if ( v49 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v49->vfptr->get_invoke_type)(
           v49,
           a2,
           v45,
           i_uid) == 1 )
    {
      v49[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_add_assign;
    }
    else
    {
      v50 = v49->i_scope_p;
      v51 = v49->i_params_p.i_obj_p;
      if ( v51 )
        ++v51->i_ref_count;
      v52 = v49->i_params_p.i_obj_p;
      if ( v52 )
      {
        v12 = v52->i_ref_count-- == 1;
        if ( v12 )
        {
          v52->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v52);
          AMemory::c_free_func(v52);
        }
        v49->i_params_p.i_obj_p = 0i64;
      }
      v49->i_name = ASymbol_append;
      v49->i_scope_p = v50;
      v49->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v49->i_params_p.i_obj_p = v51;
      if ( v51 )
        ++v51->i_ref_count;
      v49->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v49->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v49[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_add_assign;
      if ( v51 )
      {
        v12 = v51->i_ref_count-- == 1;
        if ( v12 )
        {
          v51->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v51);
          AMemory::c_free_func(v51);
        }
      }
    }
  }
  v53 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v54 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v54 )
  {
    v53 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v55 = &v53[v54 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v53[((char *)v55 - (char *)v53) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v53 == a2 )
          goto LABEL_154;
        v55 = a2 - 1;
      }
      v56 = ASymbol_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_assign.i_uid != (_DWORD)i_uid;
      if ( v56 )
        break;
      if ( v55 == a2 )
        goto LABEL_154;
      v53 = a2 + 1;
    }
    v57 = *a2;
  }
  else
  {
LABEL_154:
    v57 = 0i64;
  }
  if ( v57 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v57->vfptr->get_invoke_type)(
           v57,
           a2,
           v53,
           i_uid) == 1 )
    {
      v57[1].vfptr = (SSInvokableBaseVtbl *)SSReal::mthd_op_assign;
    }
    else
    {
      v58 = v57->i_scope_p;
      v59 = v57->i_params_p.i_obj_p;
      if ( v59 )
        ++v59->i_ref_count;
      v60 = v57->i_params_p.i_obj_p;
      if ( v60 )
      {
        v12 = v60->i_ref_count-- == 1;
        if ( v12 )
        {
          v60->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v60);
          AMemory::c_free_func(v60);
        }
        v57->i_params_p.i_obj_p = 0i64;
      }
      v57->i_name = ASymbol_assign;
      v57->i_scope_p = v58;
      v57->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v57->i_params_p.i_obj_p = v59;
      if ( v59 )
        ++v59->i_ref_count;
      v57->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v57->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v57[1].vfptr = (SSInvokableBaseVtbl *)SSReal::mthd_op_assign;
      if ( v59 )
      {
        v12 = v59->i_ref_count-- == 1;
        if ( v12 )
        {
          v59->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v59);
          AMemory::c_free_func(v59);
        }
      }
    }
  }
  v61 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v62 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v62 )
  {
    v61 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v63 = &v61[v62 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v61[((char *)v63 - (char *)v61) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)i_uid )
          break;
        if ( v61 == a2 )
          goto LABEL_178;
        v63 = a2 - 1;
      }
      v64 = ASymbol_equals.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals.i_uid != (_DWORD)i_uid;
      if ( v64 )
        break;
      if ( v63 == a2 )
        goto LABEL_178;
      v61 = a2 + 1;
    }
    v65 = *a2;
  }
  else
  {
LABEL_178:
    v65 = 0i64;
  }
  if ( v65 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v65->vfptr->get_invoke_type)(
           v65,
           a2,
           v61,
           i_uid) == 1 )
    {
      v65[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_equals;
    }
    else
    {
      v66 = v65->i_scope_p;
      v67 = v65->i_params_p.i_obj_p;
      if ( v67 )
        ++v67->i_ref_count;
      v68 = v65->i_params_p.i_obj_p;
      if ( v68 )
      {
        v12 = v68->i_ref_count-- == 1;
        if ( v12 )
        {
          v68->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v68);
          AMemory::c_free_func(v68);
        }
        v65->i_params_p.i_obj_p = 0i64;
      }
      v65->i_name = ASymbol_equals;
      v65->i_scope_p = v66;
      v65->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v65->i_params_p.i_obj_p = v67;
      if ( v67 )
        ++v67->i_ref_count;
      v65->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v65->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v65[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_equals;
      if ( v67 )
      {
        v12 = v67->i_ref_count-- == 1;
        if ( v12 )
        {
          v67->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v67);
          AMemory::c_free_func(v67);
        }
      }
    }
  }
  v69 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v70 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v70 )
  {
    v69 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v71 = &v69[v70 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v69[((char *)v71 - (char *)v69) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_greater.i_uid >= (unsigned int)i_uid )
          break;
        if ( v69 == a2 )
          goto LABEL_202;
        v71 = a2 - 1;
      }
      v72 = ASymbol_greater.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_greater.i_uid != (_DWORD)i_uid;
      if ( v72 )
        break;
      if ( v71 == a2 )
        goto LABEL_202;
      v69 = a2 + 1;
    }
    v73 = *a2;
  }
  else
  {
LABEL_202:
    v73 = 0i64;
  }
  if ( v73 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v73->vfptr->get_invoke_type)(
           v73,
           a2,
           v69,
           i_uid) == 1 )
    {
      v73[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_greater;
    }
    else
    {
      v74 = v73->i_scope_p;
      v75 = v73->i_params_p.i_obj_p;
      if ( v75 )
        ++v75->i_ref_count;
      v76 = v73->i_params_p.i_obj_p;
      if ( v76 )
      {
        v12 = v76->i_ref_count-- == 1;
        if ( v12 )
        {
          v76->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v76);
          AMemory::c_free_func(v76);
        }
        v73->i_params_p.i_obj_p = 0i64;
      }
      v73->i_name = ASymbol_greater;
      v73->i_scope_p = v74;
      v73->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v73->i_params_p.i_obj_p = v75;
      if ( v75 )
        ++v75->i_ref_count;
      v73->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v73->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v73[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_greater;
      if ( v75 )
      {
        v12 = v75->i_ref_count-- == 1;
        if ( v12 )
        {
          v75->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v75);
          AMemory::c_free_func(v75);
        }
      }
    }
  }
  v77 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v78 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    v77 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v79 = &v77[v78 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v77[((char *)v79 - (char *)v77) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_greater_or_equal.i_uid >= (unsigned int)i_uid )
          break;
        if ( v77 == a2 )
          goto LABEL_226;
        v79 = a2 - 1;
      }
      v80 = ASymbol_greater_or_equal.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_greater_or_equal.i_uid != (_DWORD)i_uid;
      if ( v80 )
        break;
      if ( v79 == a2 )
        goto LABEL_226;
      v77 = a2 + 1;
    }
    v81 = *a2;
  }
  else
  {
LABEL_226:
    v81 = 0i64;
  }
  if ( v81 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **, __int64))v81->vfptr->get_invoke_type)(
           v81,
           a2,
           v77,
           i_uid) == 1 )
    {
      v81[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_greater_or_equal;
    }
    else
    {
      v82 = v81->i_scope_p;
      v83 = v81->i_params_p.i_obj_p;
      if ( v83 )
        ++v83->i_ref_count;
      v84 = v81->i_params_p.i_obj_p;
      if ( v84 )
      {
        v12 = v84->i_ref_count-- == 1;
        if ( v12 )
        {
          v84->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v84);
          AMemory::c_free_func(v84);
        }
        v81->i_params_p.i_obj_p = 0i64;
      }
      v81->i_name = ASymbol_greater_or_equal;
      v81->i_scope_p = v82;
      v81->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v81->i_params_p.i_obj_p = v83;
      if ( v83 )
        ++v83->i_ref_count;
      v81->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v81->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v81[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_greater_or_equal;
      if ( v83 )
      {
        v12 = v83->i_ref_count-- == 1;
        if ( v12 )
        {
          v83->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v83);
          AMemory::c_free_func(v83);
        }
      }
    }
  }
  v85 = (SSMethodBase **)SSBrain::c_symbol_class_p;
  v86 = SSBrain::c_symbol_class_p->i_methods.i_count;
  if ( (_DWORD)v86 )
  {
    v85 = SSBrain::c_symbol_class_p->i_methods.i_array_p;
    v87 = &v85[v86 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v88 = &v85[((char *)v87 - (char *)v85) >> 4];
        v77 = (SSMethodBase **)(*v88)->i_name.i_uid;
        if ( ASymbol_less.i_uid >= (unsigned int)v77 )
          break;
        if ( v85 == v88 )
          goto LABEL_250;
        v87 = v88 - 1;
      }
      v89 = ASymbol_less.i_uid == (_DWORD)v77;
      v77 = (SSMethodBase **)(ASymbol_less.i_uid != (_DWORD)v77);
      if ( v89 )
        break;
      if ( v87 == v88 )
        goto LABEL_250;
      v85 = v88 + 1;
    }
    v90 = *v88;
  }
  else
  {
LABEL_250:
    v90 = 0i64;
  }
  if ( v90 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **))v90->vfptr->get_invoke_type)(
           v90,
           v85,
           v77) == 1 )
    {
      v90[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_less;
    }
    else
    {
      v91 = v90->i_scope_p;
      v92 = v90->i_params_p.i_obj_p;
      if ( v92 )
        ++v92->i_ref_count;
      v93 = v90->i_params_p.i_obj_p;
      if ( v93 )
      {
        v12 = v93->i_ref_count-- == 1;
        if ( v12 )
        {
          v93->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v93);
          AMemory::c_free_func(v93);
        }
        v90->i_params_p.i_obj_p = 0i64;
      }
      v90->i_name = ASymbol_less;
      v90->i_scope_p = v91;
      v90->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v90->i_params_p.i_obj_p = v92;
      if ( v92 )
        ++v92->i_ref_count;
      v90->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v90->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v90[1].vfptr = (SSInvokableBaseVtbl *)SSSymbol::mthd_op_less;
      if ( v92 )
      {
        v12 = v92->i_ref_count-- == 1;
        if ( v12 )
        {
          v92->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v92);
          AMemory::c_free_func(v92);
        }
      }
    }
  }
  SSClass::register_method_func(
    SSBrain::c_symbol_class_p,
    &ASymbol_less_or_equal,
    SSSymbol::mthd_op_less_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_symbol_class_p,
    &ASymbol_not_equal,
    SSSymbol::mthd_op_not_equal,
    SSBindFlag_instance_no_rebind);
}mbol_class_p,
    &ASymbol_not_equal,
    SSSymbol::mthd_op_not_equal,
    SSBindFlag_instance_no_rebind);
}

