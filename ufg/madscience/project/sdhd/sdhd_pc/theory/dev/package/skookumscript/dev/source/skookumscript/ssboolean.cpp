// File Line: 56
// RVA: 0x130620
void __fastcall SSBoolean::pool_delete(SSBoolean *this)
{
  AObjReusePool<SSBoolean> *pool; // rax
  AObjBlock<SSBoolean> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r9
  __int64 i_size; // rdx
  APArray<SSBoolean,SSBoolean,ACompareAddress<SSBoolean> > *p_i_exp_pool; // rcx

  this->i_ptr_id = 0;
  pool = SSBoolean::get_pool();
  i_block_p = pool->i_block_p;
  i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
  if ( (unsigned __int64)this < i_objects_a
    || (i_size = i_block_p->i_size, p_i_exp_pool = &pool->i_pool, (unsigned __int64)this >= i_objects_a + 48 * i_size) )
  {
    p_i_exp_pool = &pool->i_exp_pool;
  }
  APArray<SSBoolean,SSBoolean,ACompareAddress<SSBoolean>>::append(p_i_exp_pool, this);
}

// File Line: 67
// RVA: 0x126C50
void __fastcall SSBoolean::on_no_references(SSClosure *this)
{
  this->vfptr[1].is_actor(this);
}

// File Line: 84
// RVA: 0x118910
AObjReusePool<SSBoolean> *__fastcall SSBoolean::get_pool()
{
  unsigned int i_pool_incr_boolean; // edi
  unsigned int i_pool_init_boolean; // ebx
  SSBoolean **v2; // rax

  if ( (_S1_18 & 1) != 0 )
    return &s_pool;
  _S1_18 |= 1u;
  i_pool_incr_boolean = Skookum::get_lib_vals()->i_pool_incr_boolean;
  i_pool_init_boolean = Skookum::get_lib_vals()->i_pool_init_boolean;
  s_pool.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175AA8 = 0i64;
  unk_142175AB0 = 0;
  if ( i_pool_init_boolean )
  {
    unk_142175AB0 = i_pool_init_boolean;
    v2 = APArrayBase<SSBoolean>::alloc_array(i_pool_init_boolean);
  }
  else
  {
    unk_142175AB0 = 0;
    v2 = (SSBoolean **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175AA8 = v2;
  qword_142175AB8 = 0i64;
  unk_142175AC0 = 0;
  qword_142175AC8 = 0i64;
  unk_142175AD0 = 0;
  stru_142175AD8.i_count = 0;
  stru_142175AD8.i_array_p = 0i64;
  stru_142175AD8.i_size = 0;
  unk_142175AF0 = i_pool_incr_boolean;
  AObjReusePool<SSBoolean>::append_block(&s_pool, i_pool_init_boolean);
  atexit(SSBoolean::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool;
}

// File Line: 126
// RVA: 0x11FE30
void __fastcall SSBoolean::method_invoke(
        SSBoolean *this,
        SSMethodCall *mcall,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  unsigned int i_uid; // eax
  SSExpressionBase *v6; // rbx
  unsigned __int64 v7; // rbx
  SSExpressionBase *v8; // rcx
  SSInstance **v9; // rbx

  i_uid = mcall->i_name.i_uid;
  switch ( i_uid )
  {
    case 0x35E325B6u:
      if ( !this->i_user_data )
      {
        if ( mcall->i_arguments.i_count )
          v6 = *mcall->i_arguments.i_array_p;
        else
          v6 = 0i64;
        goto LABEL_14;
      }
      v9 = result_pp;
      if ( !result_pp )
        return;
LABEL_28:
      *v9 = SSBoolean::pool_new(1);
      return;
    case 0x38C7FC7Bu:
      if ( this->i_user_data )
        goto LABEL_16;
      v9 = result_pp;
      if ( !result_pp )
        return;
      goto LABEL_28;
    case 0x4A587672u:
      if ( !this->i_user_data )
      {
LABEL_7:
        if ( result_pp )
          *result_pp = SSBoolean::pool_new(0);
        return;
      }
      if ( mcall->i_arguments.i_count )
        v6 = *mcall->i_arguments.i_array_p;
      else
        v6 = 0i64;
LABEL_14:
      v6->vfptr->invoke(v6, caller_p, caller_p, result_pp);
      return;
  }
  if ( i_uid != -988282175 )
  {
    SSInstance::method_invoke(this, mcall, scope_p, caller_p, result_pp);
    return;
  }
  if ( !this->i_user_data )
    goto LABEL_7;
LABEL_16:
  v7 = 0i64;
  if ( mcall->i_arguments.i_count )
    v8 = *mcall->i_arguments.i_array_p;
  else
    v8 = 0i64;
  v8->vfptr->invoke(v8, caller_p, caller_p, result_pp);
  if ( result_pp )
  {
    LOBYTE(v7) = (*result_pp)->i_user_data == 0;
    (*result_pp)->i_user_data = v7;
  }
}

// File Line: 214
// RVA: 0x1201B0
void __fastcall SSInteger::mthd_as_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(i_obj_p[2].vfptr));
  }
}

// File Line: 235
// RVA: 0x121020
void __fastcall SSBoolean::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned __int64 *v4; // rax
  unsigned __int64 *v5; // rsi
  char v6; // bl
  unsigned __int64 *v7; // rax
  SSInstance *v8; // rax
  unsigned __int64 v9; // rcx
  AStringRef *i_str_ref_p; // rdi
  bool v11; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *v17; // rbx
  AObjReusePool<AStringRef> *v18; // rax
  AObjBlock<AStringRef> *v19; // rcx
  unsigned __int64 v20; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AString v22; // [rsp+68h] [rbp+10h] BYREF
  AString v23; // [rsp+70h] [rbp+18h] BYREF
  SSInstance *v24; // [rsp+78h] [rbp+20h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    if ( i_obj_p[2].vfptr )
    {
      AString::AString(&v23, "true", 4u, 1);
      v5 = v4;
      v6 = 1;
    }
    else
    {
      AString::AString(&v22, "false", 5u, 1);
      v5 = v7;
      v6 = 2;
    }
    v8 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v24 = v8;
    if ( v8 != (SSInstance *)-32i64 )
    {
      v9 = *v5;
      v8->i_user_data = *v5;
      ++*(_WORD *)(v9 + 16);
    }
    *result_pp = v8;
    if ( (v6 & 2) != 0 )
    {
      v6 &= ~2u;
      i_str_ref_p = v22.i_str_ref_p;
      v11 = v22.i_str_ref_p->i_ref_count-- == 1;
      if ( v11 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < i_objects_a
          || (v15 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
              p_i_exp_pool = &pool->i_pool,
              !v15) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
      }
    }
    if ( (v6 & 1) != 0 )
    {
      v17 = v23.i_str_ref_p;
      v11 = v23.i_str_ref_p->i_ref_count-- == 1;
      if ( v11 )
      {
        if ( v17->i_deallocate )
          AMemory::c_free_func(v17->i_cstr_p);
        v18 = AStringRef::get_pool();
        v19 = v18->i_block_p;
        v20 = (unsigned __int64)v19->i_objects_a;
        if ( (unsigned __int64)v17 < v20
          || (v15 = (unsigned __int64)v17 < v20 + 24i64 * v19->i_size, p_i_pool = &v18->i_pool, !v15) )
        {
          p_i_pool = &v18->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v17);
      }
    }
  }
}

// File Line: 256
// RVA: 0x123740
void __fastcall SSBoolean::mthd_op_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *i_obj_p; // r8
  SSObjectBase *v3; // r8

  if ( result_pp )
  {
    i_obj_p = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_obj_p->i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++i_obj_p->i_ref_count;
    *result_pp = i_obj_p;
  }
  else
  {
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v3[2].vfptr = (SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 285
// RVA: 0x123BB0
void __fastcall SSBoolean::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p[2].vfptr == (SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 307
// RVA: 0x1245A0
void __fastcall SSBoolean::mthd_op_not(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p[2].vfptr == 0i64);
  }
}

// File Line: 328
// RVA: 0x1245E0
void __fastcall SSBoolean::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(i_obj_p[2].vfptr != (SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 350
// RVA: 0x124820
void __fastcall SSBoolean::mthd_op_nxor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new((SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data == i_obj_p[2].vfptr);
  }
}

// File Line: 372
// RVA: 0x124A00
void __fastcall SSBoolean::mthd_op_xor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new((*scope_p->i_data.i_array_p)->i_data_p->i_user_data ^ (unsigned __int64)i_obj_p[2].vfptr);
  }
}

// File Line: 387
// RVA: 0x132A90
void __fastcall SSBoolean::register_atomic(__int64 a1, SSMethodBase **a2, __int64 a3, __int64 i_uid)
{
  SSMethodBase **i_array_p; // r8
  __int64 i_count; // rax
  SSMethodBase **v6; // r10
  _BOOL8 v7; // rcx
  SSMethodBase *v8; // rbx
  SSClass *i_scope_p; // r15
  SSParameters *i_obj_p; // rdi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  SSMethodBase **v15; // r10
  _BOOL8 v16; // rcx
  SSMethodBase *v17; // rbx
  SSClass *v18; // r15
  SSParameters *v19; // rdi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  SSMethodBase **v23; // r10
  _BOOL8 v24; // rcx
  SSMethodBase *v25; // rbx
  SSClass *v26; // r15
  SSParameters *v27; // rdi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  SSMethodBase **v31; // r10
  _BOOL8 v32; // rcx
  SSMethodBase *v33; // rbx
  SSClass *v34; // r15
  SSParameters *v35; // rdi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  SSMethodBase **v39; // r10
  _BOOL8 v40; // rcx
  SSMethodBase *v41; // rbx
  SSClass *v42; // r15
  SSParameters *v43; // rdi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  SSMethodBase **v47; // r10
  _BOOL8 v48; // rcx
  SSMethodBase *v49; // rbx
  SSClass *v50; // r15
  SSParameters *v51; // rdi
  SSParameters *v52; // r14
  SSMethodBase **v53; // r8
  __int64 v54; // rax
  SSMethodBase **v55; // r10
  _BOOL8 v56; // rcx
  SSMethodBase *v57; // rbx
  SSClass *v58; // r15
  SSParameters *v59; // rdi
  SSParameters *v60; // r14
  SSMethodBase **v61; // rdx
  __int64 v62; // rax
  SSMethodBase **v63; // r9
  SSMethodBase **v64; // rbx
  _BOOL8 v65; // rcx
  SSMethodBase *v66; // rbx
  SSClass *v67; // r15
  SSParameters *v68; // rdi
  SSParameters *v69; // r14

  i_array_p = (SSMethodBase **)SSBrain::c_boolean_class_p;
  i_count = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Integer.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v6 = a2 - 1;
      }
      v7 = ASymbol_Integer.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Integer.i_uid != (_DWORD)i_uid;
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
      v8[1].vfptr = (SSInvokableBaseVtbl *)SSInteger::mthd_as_copy;
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
      v8->i_name = ASymbol_Integer;
      v8->i_scope_p = i_scope_p;
      v8->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v8->i_params_p.i_obj_p = i_obj_p;
      if ( i_obj_p )
        ++i_obj_p->i_ref_count;
      v8->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v8->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v8[1].vfptr = (SSInvokableBaseVtbl *)SSInteger::mthd_as_copy;
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
  v13 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v14 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
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
      v17[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_as_string;
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
      v17[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_as_string;
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
  v21 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v22 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v23 = &v21[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v21[((char *)v23 - (char *)v21) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v21 == a2 )
          goto LABEL_58;
        v23 = a2 - 1;
      }
      v24 = ASymbol_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_assign.i_uid != (_DWORD)i_uid;
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
      v25[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_assign;
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
      v25->i_name = ASymbol_assign;
      v25->i_scope_p = v26;
      v25->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v25->i_params_p.i_obj_p = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v25->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v25->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v25[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_assign;
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
  v29 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v30 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v31 = &v29[v30 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v29[((char *)v31 - (char *)v29) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)i_uid )
          break;
        if ( v29 == a2 )
          goto LABEL_82;
        v31 = a2 - 1;
      }
      v32 = ASymbol_equals.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals.i_uid != (_DWORD)i_uid;
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
      v33[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_equals;
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
      v33->i_name = ASymbol_equals;
      v33->i_scope_p = v34;
      v33->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v33->i_params_p.i_obj_p = v35;
      if ( v35 )
        ++v35->i_ref_count;
      v33->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v33->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v33[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_equals;
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
  v37 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v38 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v39 = &v37[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v37[((char *)v39 - (char *)v37) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_not.i_uid >= (unsigned int)i_uid )
          break;
        if ( v37 == a2 )
          goto LABEL_106;
        v39 = a2 - 1;
      }
      v40 = ASymbol_not.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_not.i_uid != (_DWORD)i_uid;
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
      v41[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_not;
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
      v41->i_name = ASymbol_not;
      v41->i_scope_p = v42;
      v41->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v41->i_params_p.i_obj_p = v43;
      if ( v43 )
        ++v43->i_ref_count;
      v41->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v41->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v41[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_not;
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
  v45 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v46 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v47 = &v45[v46 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v45[((char *)v47 - (char *)v45) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_not_equal.i_uid >= (unsigned int)i_uid )
          break;
        if ( v45 == a2 )
          goto LABEL_130;
        v47 = a2 - 1;
      }
      v48 = ASymbol_not_equal.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_not_equal.i_uid != (_DWORD)i_uid;
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
      v49[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_not_equal;
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
      v49->i_name = ASymbol_not_equal;
      v49->i_scope_p = v50;
      v49->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v49->i_params_p.i_obj_p = v51;
      if ( v51 )
        ++v51->i_ref_count;
      v49->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v49->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v49[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_not_equal;
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
  v53 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v54 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v54 )
  {
    v53 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v55 = &v53[v54 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v53[((char *)v55 - (char *)v53) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_nxor.i_uid >= (unsigned int)i_uid )
          break;
        if ( v53 == a2 )
          goto LABEL_154;
        v55 = a2 - 1;
      }
      v56 = ASymbol_nxor.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_nxor.i_uid != (_DWORD)i_uid;
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
      v57[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_nxor;
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
      v57->i_name = ASymbol_nxor;
      v57->i_scope_p = v58;
      v57->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v57->i_params_p.i_obj_p = v59;
      if ( v59 )
        ++v59->i_ref_count;
      v57->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v57->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v57[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_nxor;
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
  v61 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v62 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v62 )
  {
    v61 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v63 = &v61[v62 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v64 = &v61[((char *)v63 - (char *)v61) >> 4];
        v53 = (SSMethodBase **)(*v64)->i_name.i_uid;
        if ( ASymbol_xor.i_uid >= (unsigned int)v53 )
          break;
        if ( v61 == v64 )
          goto LABEL_178;
        v63 = v64 - 1;
      }
      v65 = ASymbol_xor.i_uid == (_DWORD)v53;
      v53 = (SSMethodBase **)(ASymbol_xor.i_uid != (_DWORD)v53);
      if ( v65 )
        break;
      if ( v63 == v64 )
        goto LABEL_178;
      v61 = v64 + 1;
    }
    v66 = *v64;
  }
  else
  {
LABEL_178:
    v66 = 0i64;
  }
  if ( v66 )
  {
    if ( ((unsigned int (__fastcall *)(SSMethodBase *, SSMethodBase **, SSMethodBase **))v66->vfptr->get_invoke_type)(
           v66,
           v61,
           v53) == 1 )
    {
      v66[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_xor;
    }
    else
    {
      v67 = v66->i_scope_p;
      v68 = v66->i_params_p.i_obj_p;
      if ( v68 )
        ++v68->i_ref_count;
      v69 = v66->i_params_p.i_obj_p;
      if ( v69 )
      {
        v12 = v69->i_ref_count-- == 1;
        if ( v12 )
        {
          v69->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v69);
          AMemory::c_free_func(v69);
        }
        v66->i_params_p.i_obj_p = 0i64;
      }
      v66->i_name = ASymbol_xor;
      v66->i_scope_p = v67;
      v66->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
      v66->i_params_p.i_obj_p = v68;
      if ( v68 )
        ++v68->i_ref_count;
      v66->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
      v66->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable;
      v66[1].vfptr = (SSInvokableBaseVtbl *)SSBoolean::mthd_op_xor;
      if ( v68 )
      {
        v12 = v68->i_ref_count-- == 1;
        if ( v12 )
        {
          v68->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v68);
          AMemory::c_free_func(v68);
        }
      }
    }
  }
} = 0x80000000;
          SSParameters::~SSParameters(v68);
          AMemory::c_free_func(v68);
        }
      }
    }
  }
}

