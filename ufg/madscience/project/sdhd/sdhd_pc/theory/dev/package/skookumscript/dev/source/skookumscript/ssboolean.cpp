// File Line: 56
// RVA: 0x130620
void __fastcall SSBoolean::pool_delete(SSBoolean *this)
{
  SSBoolean *v1; // rbx
  AObjReusePool<SSBoolean> *v2; // rax
  AObjBlock<SSBoolean> *v3; // rcx
  unsigned __int64 v4; // r9
  __int64 v5; // rdx
  APArray<SSBoolean,SSBoolean,ACompareAddress<SSBoolean> > *v6; // rcx

  v1 = this;
  this->i_ptr_id = 0;
  v2 = SSBoolean::get_pool();
  v3 = v2->i_block_p;
  v4 = (unsigned __int64)v3->i_objects_a;
  if ( (unsigned __int64)v1 < v4 || (v5 = v3->i_size, v6 = &v2->i_pool, (unsigned __int64)v1 >= v4 + 48 * v5) )
    v6 = &v2->i_exp_pool;
  APArray<SSBoolean,SSBoolean,ACompareAddress<SSBoolean>>::append(v6, v1);
}

// File Line: 67
// RVA: 0x126C50
void __fastcall SSBoolean::on_no_references(SSClosure *this)
{
  ((void (*)(void))this->vfptr[1].is_actor)();
}

// File Line: 84
// RVA: 0x118910
AObjReusePool<SSBoolean> *__fastcall SSBoolean::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSBoolean **v2; // rax

  if ( _S1_18 & 1 )
    return &s_pool;
  _S1_18 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_boolean;
  v1 = Skookum::get_lib_vals()->i_pool_init_boolean;
  s_pool.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175AA8 = 0i64;
  unk_142175AB0 = 0;
  if ( v1 )
  {
    unk_142175AB0 = v1;
    v2 = APArrayBase<SSBoolean>::alloc_array(v1);
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
  unk_142175AF0 = v0;
  AObjReusePool<SSBoolean>::append_block(&s_pool, v1);
  atexit(SSBoolean::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool;
}

// File Line: 126
// RVA: 0x11FE30
void __fastcall SSBoolean::method_invoke(SSBoolean *this, SSMethodCall *mcall, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  unsigned int v5; // eax
  SSExpressionBase *v6; // rbx
  unsigned __int64 v7; // rbx
  SSExpressionBase *v8; // rcx
  SSExpressionBase *v9; // rbx

  v5 = mcall->i_name.i_uid;
  switch ( v5 )
  {
    case 0x35E325B6u:
      if ( this->i_user_data )
      {
        if ( result_pp )
          *result_pp = (SSInstance *)SSBoolean::pool_new(1);
      }
      else
      {
        if ( mcall->i_arguments.i_count )
          v9 = *mcall->i_arguments.i_array_p;
        else
          v9 = 0i64;
        v9->vfptr->invoke(v9, (SSObjectBase *)&caller_p->vfptr, caller_p, result_pp);
      }
      break;
    case 0x38C7FC7Bu:
      if ( this->i_user_data )
      {
LABEL_16:
        v7 = 0i64;
        if ( mcall->i_arguments.i_count )
          v8 = *mcall->i_arguments.i_array_p;
        else
          v8 = 0i64;
        v8->vfptr->invoke(v8, (SSObjectBase *)&caller_p->vfptr, caller_p, result_pp);
        if ( result_pp )
        {
          LOBYTE(v7) = (*result_pp)->i_user_data == 0;
          (*result_pp)->i_user_data = v7;
        }
        return;
      }
      if ( result_pp )
        *result_pp = (SSInstance *)SSBoolean::pool_new(1);
      break;
    case 0x4A587672u:
      if ( !this->i_user_data )
      {
LABEL_7:
        if ( result_pp )
          *result_pp = (SSInstance *)SSBoolean::pool_new(0);
        return;
      }
      if ( mcall->i_arguments.i_count )
        v6 = *mcall->i_arguments.i_array_p;
      else
        v6 = 0i64;
      v6->vfptr->invoke(v6, (SSObjectBase *)&caller_p->vfptr, caller_p, result_pp);
      break;
    case 0xC51802C1:
      if ( !this->i_user_data )
        goto LABEL_7;
      goto LABEL_16;
    default:
      SSInstance::method_invoke((SSInstance *)&this->vfptr, mcall, scope_p, caller_p, result_pp);
      return;
  }
}

// File Line: 214
// RVA: 0x1201B0
void __fastcall SSInteger::mthd_as_copy(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(v2[2].vfptr));
  }
}

// File Line: 235
// RVA: 0x121020
void __fastcall SSBoolean::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // r8
  unsigned __int64 *v4; // rax
  unsigned __int64 *v5; // rsi
  char v6; // bl
  unsigned __int64 *v7; // rax
  SSInstance *v8; // rax
  unsigned __int64 v9; // rcx
  AStringRef *v10; // rdi
  bool v11; // zf
  AObjReusePool<AStringRef> *v12; // rax
  AObjBlock<AStringRef> *v13; // rcx
  unsigned __int64 v14; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v16; // rcx
  AStringRef *v17; // rbx
  AObjReusePool<AStringRef> *v18; // rax
  AObjBlock<AStringRef> *v19; // rcx
  unsigned __int64 v20; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v21; // rcx
  AString v22; // [rsp+68h] [rbp+10h]
  AString v23; // [rsp+70h] [rbp+18h]
  SSInstance *v24; // [rsp+78h] [rbp+20h]

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    if ( v3[2].vfptr )
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
    *v2 = v8;
    if ( v6 & 2 )
    {
      v6 &= 0xFDu;
      v10 = v22.i_str_ref_p;
      v11 = v22.i_str_ref_p->i_ref_count == 1;
      --v10->i_ref_count;
      if ( v11 )
      {
        if ( v10->i_deallocate )
          AMemory::c_free_func(v10->i_cstr_p);
        v12 = AStringRef::get_pool();
        v13 = v12->i_block_p;
        v14 = (unsigned __int64)v13->i_objects_a;
        if ( (unsigned __int64)v10 < v14
          || (v15 = (unsigned __int64)v10 < v14 + 24i64 * v13->i_size, v16 = &v12->i_pool, !v15) )
        {
          v16 = &v12->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v16, v10);
      }
    }
    if ( v6 & 1 )
    {
      v17 = v23.i_str_ref_p;
      v11 = v23.i_str_ref_p->i_ref_count == 1;
      --v17->i_ref_count;
      if ( v11 )
      {
        if ( v17->i_deallocate )
          AMemory::c_free_func(v17->i_cstr_p);
        v18 = AStringRef::get_pool();
        v19 = v18->i_block_p;
        v20 = (unsigned __int64)v19->i_objects_a;
        if ( (unsigned __int64)v17 < v20
          || (v15 = (unsigned __int64)v17 < v20 + 24i64 * v19->i_size, v21 = &v18->i_pool, !v15) )
        {
          v21 = &v18->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v21, v17);
      }
    }
  }
}

// File Line: 256
// RVA: 0x123740
void __fastcall SSBoolean::mthd_op_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v2; // r8
  SSObjectBase *v3; // r8

  if ( result_pp )
  {
    v2 = (SSInstance *)scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v2->i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++v2->i_ref_count;
    *result_pp = v2;
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
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2[2].vfptr == (SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 307
// RVA: 0x1245A0
void __fastcall SSBoolean::mthd_op_not(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2[2].vfptr == 0i64);
  }
}

// File Line: 328
// RVA: 0x1245E0
void __fastcall SSBoolean::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v2[2].vfptr != (SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 350
// RVA: 0x124820
void __fastcall SSBoolean::mthd_op_nxor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new((SSObjectBaseVtbl *)(*scope_p->i_data.i_array_p)->i_data_p->i_user_data == v2[2].vfptr);
  }
}

// File Line: 372
// RVA: 0x124A00
void __fastcall SSBoolean::mthd_op_xor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new((*scope_p->i_data.i_array_p)->i_data_p->i_user_data ^ (_QWORD)v2[2].vfptr);
  }
}

// File Line: 387
// RVA: 0x132A90
void __fastcall SSBoolean::register_atomic(__int64 a1, signed __int64 a2, __int64 a3, __int64 a4)
{
  SSMethodBase **v4; // r8
  __int64 v5; // rax
  signed __int64 v6; // r10
  _BOOL8 v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // r15
  SSParameters *v10; // rdi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  signed __int64 v15; // r10
  _BOOL8 v16; // rcx
  __int64 v17; // rbx
  __int64 v18; // r15
  SSParameters *v19; // rdi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  signed __int64 v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rbx
  __int64 v26; // r15
  SSParameters *v27; // rdi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  signed __int64 v31; // r10
  _BOOL8 v32; // rcx
  __int64 v33; // rbx
  __int64 v34; // r15
  SSParameters *v35; // rdi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  signed __int64 v39; // r10
  _BOOL8 v40; // rcx
  __int64 v41; // rbx
  __int64 v42; // r15
  SSParameters *v43; // rdi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  signed __int64 v47; // r10
  _BOOL8 v48; // rcx
  __int64 v49; // rbx
  __int64 v50; // r15
  SSParameters *v51; // rdi
  SSParameters *v52; // r14
  SSMethodBase **v53; // r8
  __int64 v54; // rax
  signed __int64 v55; // r10
  _BOOL8 v56; // rcx
  __int64 v57; // rbx
  __int64 v58; // r15
  SSParameters *v59; // rdi
  SSParameters *v60; // r14
  SSMethodBase **v61; // rdx
  __int64 v62; // rax
  signed __int64 v63; // r9
  signed __int64 v64; // rbx
  _BOOL8 v65; // rcx
  __int64 v66; // rbx
  __int64 v67; // r15
  SSParameters *v68; // rdi
  SSParameters *v69; // r14
  signed __int64 v70; // [rsp+20h] [rbp-10h]

  v70 = -2i64;
  v4 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v5 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v5 )
  {
    v4 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v6 = (signed __int64)&v4[v5 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v4[(v6 - (signed __int64)v4) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_Integer.i_uid < (unsigned int)a4 )
        goto LABEL_203;
      v7 = ASymbol_Integer.i_uid == (_DWORD)a4;
      a4 = ASymbol_Integer.i_uid != (_DWORD)a4;
      if ( v7 == 1 )
      {
        v8 = *(_QWORD *)a2;
        goto LABEL_12;
      }
      if ( a4 < 0 )
      {
LABEL_203:
        if ( v4 == (SSMethodBase **)a2 )
          break;
        v6 = a2 - 8;
      }
      else
      {
        if ( v6 == a2 )
          break;
        v4 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v8 = 0i64;
LABEL_12:
  if ( v8 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v8 + 16i64))(
           v8,
           a2,
           v4,
           a4,
           -2i64) == 1 )
    {
      *(_QWORD *)(v8 + 32) = SSInteger::mthd_as_copy;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      if ( v10 )
        ++v10->i_ref_count;
      v11 = *(SSParameters **)(v8 + 24);
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        *(_QWORD *)(v8 + 24) = 0i64;
      }
      *(ASymbol *)(v8 + 8) = ASymbol_Integer;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable;
      *(_QWORD *)v8 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v8 + 32) = SSInteger::mthd_as_copy;
      if ( v10 )
      {
        v12 = v10->i_ref_count-- == 1;
        if ( v12 )
        {
          v10->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v10);
          AMemory::c_free_func(v10);
        }
      }
    }
  }
  v13 = (SSMethodBase **)SSBrain::c_boolean_class_p;
  v14 = SSBrain::c_boolean_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_boolean_class_p->i_methods.i_array_p;
    v15 = (signed __int64)&v13[v14 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v13[(v15 - (signed __int64)v13) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_String.i_uid < (unsigned int)a4 )
        goto LABEL_204;
      v16 = ASymbol_String.i_uid == (_DWORD)a4;
      a4 = ASymbol_String.i_uid != (_DWORD)a4;
      if ( v16 == 1 )
      {
        v17 = *(_QWORD *)a2;
        goto LABEL_37;
      }
      if ( a4 < 0 )
      {
LABEL_204:
        if ( v13 == (SSMethodBase **)a2 )
          break;
        v15 = a2 - 8;
      }
      else
      {
        if ( v15 == a2 )
          break;
        v13 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v17 = 0i64;
LABEL_37:
  if ( v17 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v17 + 16i64))(
           v17,
           a2,
           v13,
           a4,
           v70) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSBoolean::mthd_as_string;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      if ( v19 )
        ++v19->i_ref_count;
      v20 = *(SSParameters **)(v17 + 24);
      if ( v20 )
      {
        v12 = v20->i_ref_count-- == 1;
        if ( v12 )
        {
          v20->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
        *(_QWORD *)(v17 + 24) = 0i64;
      }
      *(ASymbol *)(v17 + 8) = ASymbol_String;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable;
      *(_QWORD *)v17 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v17 + 32) = SSBoolean::mthd_as_string;
      if ( v19 )
      {
        v12 = v19->i_ref_count-- == 1;
        if ( v12 )
        {
          v19->i_ref_count = 2147483648;
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
    v23 = (signed __int64)&v21[v22 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v21[(v23 - (signed __int64)v21) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_assign.i_uid < (unsigned int)a4 )
        goto LABEL_205;
      v24 = ASymbol_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_assign.i_uid != (_DWORD)a4;
      if ( v24 == 1 )
      {
        v25 = *(_QWORD *)a2;
        goto LABEL_62;
      }
      if ( a4 < 0 )
      {
LABEL_205:
        if ( v21 == (SSMethodBase **)a2 )
          break;
        v23 = a2 - 8;
      }
      else
      {
        if ( v23 == a2 )
          break;
        v21 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v25 = 0i64;
LABEL_62:
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           v21,
           a4,
           v70) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSBoolean::mthd_op_assign;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      if ( v27 )
        ++v27->i_ref_count;
      v28 = *(SSParameters **)(v25 + 24);
      if ( v28 )
      {
        v12 = v28->i_ref_count-- == 1;
        if ( v12 )
        {
          v28->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        *(_QWORD *)(v25 + 24) = 0i64;
      }
      *(ASymbol *)(v25 + 8) = ASymbol_assign;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable;
      *(_QWORD *)v25 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v25 + 32) = SSBoolean::mthd_op_assign;
      if ( v27 )
      {
        v12 = v27->i_ref_count-- == 1;
        if ( v12 )
        {
          v27->i_ref_count = 2147483648;
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
    v31 = (signed __int64)&v29[v30 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v29[(v31 - (signed __int64)v29) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_equals.i_uid < (unsigned int)a4 )
        goto LABEL_206;
      v32 = ASymbol_equals.i_uid == (_DWORD)a4;
      a4 = ASymbol_equals.i_uid != (_DWORD)a4;
      if ( v32 == 1 )
      {
        v33 = *(_QWORD *)a2;
        goto LABEL_87;
      }
      if ( a4 < 0 )
      {
LABEL_206:
        if ( v29 == (SSMethodBase **)a2 )
          break;
        v31 = a2 - 8;
      }
      else
      {
        if ( v31 == a2 )
          break;
        v29 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v33 = 0i64;
LABEL_87:
  if ( v33 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v33 + 16i64))(
           v33,
           a2,
           v29,
           a4,
           v70) == 1 )
    {
      *(_QWORD *)(v33 + 32) = SSBoolean::mthd_op_equals;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      if ( v35 )
        ++v35->i_ref_count;
      v36 = *(SSParameters **)(v33 + 24);
      if ( v36 )
      {
        v12 = v36->i_ref_count-- == 1;
        if ( v12 )
        {
          v36->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v36);
          AMemory::c_free_func(v36);
        }
        *(_QWORD *)(v33 + 24) = 0i64;
      }
      *(ASymbol *)(v33 + 8) = ASymbol_equals;
      *(_QWORD *)(v33 + 16) = v34;
      *(_QWORD *)v33 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v33 + 24) = v35;
      if ( v35 )
        ++v35->i_ref_count;
      *(_QWORD *)v33 = &SSMethodBase::`vftable;
      *(_QWORD *)v33 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v33 + 32) = SSBoolean::mthd_op_equals;
      if ( v35 )
      {
        v12 = v35->i_ref_count-- == 1;
        if ( v12 )
        {
          v35->i_ref_count = 2147483648;
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
    v39 = (signed __int64)&v37[v38 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v37[(v39 - (signed __int64)v37) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_not.i_uid < (unsigned int)a4 )
        goto LABEL_207;
      v40 = ASymbol_not.i_uid == (_DWORD)a4;
      a4 = ASymbol_not.i_uid != (_DWORD)a4;
      if ( v40 == 1 )
      {
        v41 = *(_QWORD *)a2;
        goto LABEL_112;
      }
      if ( a4 < 0 )
      {
LABEL_207:
        if ( v37 == (SSMethodBase **)a2 )
          break;
        v39 = a2 - 8;
      }
      else
      {
        if ( v39 == a2 )
          break;
        v37 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v41 = 0i64;
LABEL_112:
  if ( v41 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v41 + 16i64))(
           v41,
           a2,
           v37,
           a4,
           v70) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSBoolean::mthd_op_not;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      if ( v43 )
        ++v43->i_ref_count;
      v44 = *(SSParameters **)(v41 + 24);
      if ( v44 )
      {
        v12 = v44->i_ref_count-- == 1;
        if ( v12 )
        {
          v44->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v44);
          AMemory::c_free_func(v44);
        }
        *(_QWORD *)(v41 + 24) = 0i64;
      }
      *(ASymbol *)(v41 + 8) = ASymbol_not;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable;
      *(_QWORD *)v41 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v41 + 32) = SSBoolean::mthd_op_not;
      if ( v43 )
      {
        v12 = v43->i_ref_count-- == 1;
        if ( v12 )
        {
          v43->i_ref_count = 2147483648;
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
    v47 = (signed __int64)&v45[v46 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v45[(v47 - (signed __int64)v45) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_not_equal.i_uid < (unsigned int)a4 )
        goto LABEL_208;
      v48 = ASymbol_not_equal.i_uid == (_DWORD)a4;
      a4 = ASymbol_not_equal.i_uid != (_DWORD)a4;
      if ( v48 == 1 )
      {
        v49 = *(_QWORD *)a2;
        goto LABEL_137;
      }
      if ( a4 < 0 )
      {
LABEL_208:
        if ( v45 == (SSMethodBase **)a2 )
          break;
        v47 = a2 - 8;
      }
      else
      {
        if ( v47 == a2 )
          break;
        v45 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v49 = 0i64;
LABEL_137:
  if ( v49 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v49 + 16i64))(
           v49,
           a2,
           v45,
           a4,
           v70) == 1 )
    {
      *(_QWORD *)(v49 + 32) = SSBoolean::mthd_op_not_equal;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      if ( v51 )
        ++v51->i_ref_count;
      v52 = *(SSParameters **)(v49 + 24);
      if ( v52 )
      {
        v12 = v52->i_ref_count-- == 1;
        if ( v12 )
        {
          v52->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v52);
          AMemory::c_free_func(v52);
        }
        *(_QWORD *)(v49 + 24) = 0i64;
      }
      *(ASymbol *)(v49 + 8) = ASymbol_not_equal;
      *(_QWORD *)(v49 + 16) = v50;
      *(_QWORD *)v49 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v49 + 24) = v51;
      if ( v51 )
        ++v51->i_ref_count;
      *(_QWORD *)v49 = &SSMethodBase::`vftable;
      *(_QWORD *)v49 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v49 + 32) = SSBoolean::mthd_op_not_equal;
      if ( v51 )
      {
        v12 = v51->i_ref_count-- == 1;
        if ( v12 )
        {
          v51->i_ref_count = 2147483648;
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
    v55 = (signed __int64)&v53[v54 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v53[(v55 - (signed __int64)v53) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_nxor.i_uid < (unsigned int)a4 )
        goto LABEL_209;
      v56 = ASymbol_nxor.i_uid == (_DWORD)a4;
      a4 = ASymbol_nxor.i_uid != (_DWORD)a4;
      if ( v56 == 1 )
      {
        v57 = *(_QWORD *)a2;
        goto LABEL_162;
      }
      if ( a4 < 0 )
      {
LABEL_209:
        if ( v53 == (SSMethodBase **)a2 )
          break;
        v55 = a2 - 8;
      }
      else
      {
        if ( v55 == a2 )
          break;
        v53 = (SSMethodBase **)(a2 + 8);
      }
    }
  }
  v57 = 0i64;
LABEL_162:
  if ( v57 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v57 + 16i64))(
           v57,
           a2,
           v53,
           a4,
           v70) == 1 )
    {
      *(_QWORD *)(v57 + 32) = SSBoolean::mthd_op_nxor;
    }
    else
    {
      v58 = *(_QWORD *)(v57 + 16);
      v59 = *(SSParameters **)(v57 + 24);
      if ( v59 )
        ++v59->i_ref_count;
      v60 = *(SSParameters **)(v57 + 24);
      if ( v60 )
      {
        v12 = v60->i_ref_count-- == 1;
        if ( v12 )
        {
          v60->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v60);
          AMemory::c_free_func(v60);
        }
        *(_QWORD *)(v57 + 24) = 0i64;
      }
      *(ASymbol *)(v57 + 8) = ASymbol_nxor;
      *(_QWORD *)(v57 + 16) = v58;
      *(_QWORD *)v57 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v57 + 24) = v59;
      if ( v59 )
        ++v59->i_ref_count;
      *(_QWORD *)v57 = &SSMethodBase::`vftable;
      *(_QWORD *)v57 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v57 + 32) = SSBoolean::mthd_op_nxor;
      if ( v59 )
      {
        v12 = v59->i_ref_count-- == 1;
        if ( v12 )
        {
          v59->i_ref_count = 2147483648;
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
    v63 = (signed __int64)&v61[v62 - 1];
    while ( 1 )
    {
      v64 = (signed __int64)&v61[(v63 - (signed __int64)v61) >> 4];
      v53 = (SSMethodBase **)*(unsigned int *)(*(_QWORD *)v64 + 8i64);
      if ( ASymbol_xor.i_uid < (unsigned int)v53 )
        goto LABEL_210;
      v65 = ASymbol_xor.i_uid == (_DWORD)v53;
      v53 = (SSMethodBase **)(ASymbol_xor.i_uid != (_DWORD)v53);
      if ( v65 == 1 )
      {
        v66 = *(_QWORD *)v64;
        goto LABEL_187;
      }
      if ( (signed __int64)v53 < 0 )
      {
LABEL_210:
        if ( v61 == (SSMethodBase **)v64 )
          break;
        v63 = v64 - 8;
      }
      else
      {
        if ( v63 == v64 )
          break;
        v61 = (SSMethodBase **)(v64 + 8);
      }
    }
  }
  v66 = 0i64;
LABEL_187:
  if ( v66 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **))(*(_QWORD *)v66 + 16i64))(
           v66,
           v61,
           v53) == 1 )
    {
      *(_QWORD *)(v66 + 32) = SSBoolean::mthd_op_xor;
    }
    else
    {
      v67 = *(_QWORD *)(v66 + 16);
      v68 = *(SSParameters **)(v66 + 24);
      if ( v68 )
        ++v68->i_ref_count;
      v69 = *(SSParameters **)(v66 + 24);
      if ( v69 )
      {
        v12 = v69->i_ref_count-- == 1;
        if ( v12 )
        {
          v69->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v69);
          AMemory::c_free_func(v69);
        }
        *(_QWORD *)(v66 + 24) = 0i64;
      }
      *(ASymbol *)(v66 + 8) = ASymbol_xor;
      *(_QWORD *)(v66 + 16) = v67;
      *(_QWORD *)v66 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v66 + 24) = v68;
      if ( v68 )
        ++v68->i_ref_count;
      *(_QWORD *)v66 = &SSMethodBase::`vftable;
      *(_QWORD *)v66 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v66 + 32) = SSBoolean::mthd_op_xor;
      if ( v68 )
      {
        v12 = v68->i_ref_count-- == 1;
        if ( v12 )
        {
          v68->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v68);
          AMemory::c_free_func(v68);
        }
      }
    }
  }
}Parameters::~SSParameters(v69);
          AMemory::c_free_func(v69);
        }
        *(_QWORD *)(v66 + 24) = 0i64;
      }
      *(ASymbol *)(v66 + 8) = ASymbol_xor;
      *(_QWORD *)(v66 + 16) = v67;
      *(_QWORD *)v66 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v66 + 24) = v68;
      if ( v68 )
        ++v68->i_ref_count;
      *(_QWORD *)v66 = &SSMethodBase::`vftable;
      *(_QWORD *)v66 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v66 + 32) = SSBoolean::mthd_op_xor;
      if ( v68 )
   

