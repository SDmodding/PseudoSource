// File Line: 61
// RVA: 0x120ED0
void __fastcall SSReal::mthd_as_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   (unsigned int)(int)(float)(*(float *)&i_obj_p[2].vfptr + 0.5));
  }
}

// File Line: 82
// RVA: 0x121790
void __fastcall SSReal::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r9
  AString *v4; // rdi
  SSInstance *v5; // rax
  AStringRef *i_str_ref_p; // rcx
  AStringRef *v7; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString result; // [rsp+48h] [rbp+10h] BYREF
  SSInstance *v15; // [rsp+50h] [rbp+18h]
  unsigned __int64 *p_i_user_data; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4 = AString::ctor_float(&result, *(float *)&i_obj_p[2].vfptr, 6u);
    v5 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v15 = v5;
    p_i_user_data = &v5->i_user_data;
    if ( v5 != (SSInstance *)-32i64 )
    {
      i_str_ref_p = v4->i_str_ref_p;
      v5->i_user_data = (unsigned __int64)v4->i_str_ref_p;
      ++i_str_ref_p->i_ref_count;
    }
    *result_pp = v5;
    v7 = result.i_str_ref_p;
    if ( result.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( v7->i_deallocate )
        AMemory::c_free_func(v7->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v7 < i_objects_a
        || (v12 = (unsigned __int64)v7 < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v12) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, v7);
    }
  }
}

// File Line: 138
// RVA: 0x1240E0
void __fastcall SSReal::mthd_op_increment(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr + 1.0;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr + 1.0;
  }
}

// File Line: 170
// RVA: 0x1239B0
void __fastcall SSReal::mthd_op_decrement(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr - 1.0;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr - 1.0;
  }
}

// File Line: 202
// RVA: 0x123480
void __fastcall SSReal::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v4; // rax
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *result_pp = v4;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&v4->i_user_data = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data
                               + *(float *)&i_obj_p[2].vfptr;
  }
}

// File Line: 227
// RVA: 0x123660
void __fastcall SSReal::mthd_op_add_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data
                                + *(float *)&i_obj_p[2].vfptr;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data
                                + *(float *)&i_obj_p[2].vfptr;
  }
}

// File Line: 259
// RVA: 0x1248C0
void __fastcall SSReal::mthd_op_subtract(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v4; // rax
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *result_pp = v4;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&v4->i_user_data = *(float *)&i_obj_p[2].vfptr
                               - *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 284
// RVA: 0x124990
void __fastcall SSReal::mthd_op_subtract_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr
                                - *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr
                                - *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 316
// RVA: 0x124450
void __fastcall SSReal::mthd_op_multiply(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v4; // rax
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *result_pp = v4;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&v4->i_user_data = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data
                               * *(float *)&i_obj_p[2].vfptr;
  }
}

// File Line: 341
// RVA: 0x124530
void __fastcall SSReal::mthd_op_multiply_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data
                                * *(float *)&i_obj_p[2].vfptr;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data
                                * *(float *)&i_obj_p[2].vfptr;
  }
}

// File Line: 373
// RVA: 0x123A60
void __fastcall SSReal::mthd_op_divide(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance *v4; // rax
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *result_pp = v4;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&v4->i_user_data = *(float *)&i_obj_p[2].vfptr
                               / *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 398
// RVA: 0x123B40
void __fastcall SSReal::mthd_op_divide_assign(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr
                                / *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
  else
  {
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *(float *)&i_obj_p[2].vfptr = *(float *)&i_obj_p[2].vfptr
                                / *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 430
// RVA: 0x123CA0
void __fastcall SSReal::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    if ( *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data == *(float *)&i_obj_p[2].vfptr )
      *result_pp = SSBoolean::pool_new(1);
    else
      *result_pp = SSBoolean::pool_new(0);
  }
}

// File Line: 455
// RVA: 0x1246D0
void __fastcall SSReal::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    if ( *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data == *(float *)&i_obj_p[2].vfptr )
      *result_pp = SSBoolean::pool_new(0);
    else
      *result_pp = SSBoolean::pool_new(1);
  }
}

// File Line: 480
// RVA: 0x123E30
void __fastcall SSReal::mthd_op_greater(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(*(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data < *(float *)&i_obj_p[2].vfptr);
  }
}

// File Line: 505
// RVA: 0x123F90
void __fastcall SSReal::mthd_op_greater_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(*(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data <= *(float *)&i_obj_p[2].vfptr);
  }
}

// File Line: 530
// RVA: 0x124190
void __fastcall SSReal::mthd_op_less(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(*(float *)&i_obj_p[2].vfptr < *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 555
// RVA: 0x1242F0
void __fastcall SSReal::mthd_op_less_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *result_pp = SSBoolean::pool_new(*(float *)&i_obj_p[2].vfptr <= *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 574
// RVA: 0x121B50
void __fastcall SSReal::mthd_clamp(SSInvokedMethod *scope_p, SSObjectBase **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  SSData **i_array_p; // rdx
  float v5; // xmm1_4
  float v6; // xmm0_4

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = scope_p->i_data.i_array_p;
  v5 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  v6 = *(float *)&(*i_array_p)->i_data_p->i_user_data;
  if ( *(float *)&i_obj_p[2].vfptr >= v6 )
    v6 = *(float *)&i_obj_p[2].vfptr;
  if ( v6 <= v5 )
    v5 = v6;
  *(float *)&i_obj_p[2].vfptr = v5;
  if ( result_pp )
  {
    ++LODWORD(i_obj_p[1].vfptr);
    *result_pp = i_obj_p;
  }
}

// File Line: 593
// RVA: 0x138390
void __fastcall SSReal::register_atomic(__int64 a1, SSMethodBase **a2, __int64 a3, __int64 i_uid)
{
  SSMethodBase **i_array_p; // r8
  __int64 i_count; // rax
  SSMethodBase **v6; // r10
  _BOOL8 v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // r15
  SSParameters *v10; // rsi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  SSMethodBase **v15; // r10
  _BOOL8 v16; // rcx
  __int64 v17; // rbx
  __int64 v18; // r15
  SSParameters *v19; // rsi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  SSMethodBase **v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rbx
  __int64 v26; // r15
  SSParameters *v27; // rsi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  SSMethodBase **v31; // r10
  _BOOL8 v32; // rcx
  __int64 v33; // rbx
  __int64 v34; // r15
  SSParameters *v35; // rsi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  SSMethodBase **v39; // r10
  _BOOL8 v40; // rcx
  __int64 v41; // rbx
  __int64 v42; // r15
  SSParameters *v43; // rsi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  SSMethodBase **v47; // r10
  _BOOL8 v48; // rcx
  __int64 v49; // rbx
  __int64 v50; // r15
  SSParameters *v51; // rsi
  SSParameters *v52; // r14
  SSClass *v53; // rbx
  ASymbol *v54; // rax
  SSMethodBase **v55; // rdx
  __int64 v56; // r9
  SSMethodBase **v57; // r8
  __int64 v58; // rax
  SSMethodBase **v59; // r10
  _BOOL8 v60; // rcx
  __int64 v61; // rbx
  __int64 v62; // r15
  SSParameters *v63; // rsi
  SSParameters *v64; // r14
  SSMethodBase **v65; // r8
  __int64 v66; // rax
  SSMethodBase **v67; // r10
  _BOOL8 v68; // rcx
  __int64 v69; // rbx
  __int64 v70; // r15
  SSParameters *v71; // rsi
  SSParameters *v72; // r14
  SSMethodBase **v73; // r8
  __int64 v74; // rax
  SSMethodBase **v75; // r10
  _BOOL8 v76; // rcx
  __int64 v77; // rbx
  __int64 v78; // r15
  SSParameters *v79; // rsi
  SSParameters *v80; // r14
  SSMethodBase **v81; // r8
  __int64 v82; // rax
  SSMethodBase **v83; // r10
  _BOOL8 v84; // rcx
  __int64 v85; // rbx
  __int64 v86; // r15
  SSParameters *v87; // rsi
  SSParameters *v88; // r14
  SSMethodBase **v89; // r8
  __int64 v90; // rax
  SSMethodBase **v91; // r10
  _BOOL8 v92; // rcx
  __int64 v93; // rbx
  __int64 v94; // r15
  SSParameters *v95; // rsi
  SSParameters *v96; // r14
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v98; // [rsp+78h] [rbp+48h]
  __int64 v99; // [rsp+80h] [rbp+50h]

  i_array_p = (SSMethodBase **)SSBrain::c_real_class_p;
  i_count = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = SSBrain::c_real_class_p->i_methods.i_array_p;
    v6 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v6 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_ctor_copy.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v6 = a2 - 1;
      }
      v7 = ASymbolX_ctor_copy.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_ctor_copy.i_uid != (_DWORD)i_uid;
      if ( v7 )
        break;
      if ( v6 == a2 )
        goto LABEL_10;
      i_array_p = a2 + 1;
    }
    v8 = (__int64)*a2;
  }
  else
  {
LABEL_10:
    v8 = 0i64;
  }
  result = v8;
  if ( v8 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64, __int64))(*(_QWORD *)v8 + 16i64))(
           v8,
           a2,
           i_array_p,
           i_uid,
           -2i64) == 1 )
    {
      *(_QWORD *)(v8 + 32) = SSReal::mthd_ctor_copy;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v98 = v10;
      if ( v10 )
        ++v10->i_ref_count;
      v11 = *(SSParameters **)(v8 + 24);
      if ( v11 )
      {
        v12 = v11->i_ref_count-- == 1;
        if ( v12 )
        {
          v11->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v11);
          AMemory::c_free_func(v11);
        }
        *(_QWORD *)(v8 + 24) = 0i64;
      }
      v99 = v8;
      *(ASymbol *)(v8 + 8) = ASymbolX_ctor_copy;
      *(_QWORD *)(v8 + 16) = v9;
      *(_QWORD *)v8 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v8 + 24) = v10;
      if ( v10 )
        ++v10->i_ref_count;
      *(_QWORD *)v8 = &SSMethodBase::`vftable;
      *(_QWORD *)v8 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v8 + 32) = SSReal::mthd_ctor_copy;
      if ( v10 )
      {
        v12 = v10->i_ref_count-- == 1;
        if ( v12 )
        {
          v10->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v10);
          AMemory::c_free_func(v10);
        }
      }
    }
  }
  v13 = (SSMethodBase **)SSBrain::c_real_class_p;
  v14 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v14 )
  {
    v13 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v15 = &v13[v14 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v13[((char *)v15 - (char *)v13) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add.i_uid >= (unsigned int)i_uid )
          break;
        if ( v13 == a2 )
          goto LABEL_34;
        v15 = a2 - 1;
      }
      v16 = ASymbol_add.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add.i_uid != (_DWORD)i_uid;
      if ( v16 )
        break;
      if ( v15 == a2 )
        goto LABEL_34;
      v13 = a2 + 1;
    }
    v17 = (__int64)*a2;
  }
  else
  {
LABEL_34:
    v17 = 0i64;
  }
  result = v17;
  if ( v17 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v17 + 16i64))(
           v17,
           a2,
           v13,
           i_uid) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSReal::mthd_op_add;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v98 = v19;
      if ( v19 )
        ++v19->i_ref_count;
      v20 = *(SSParameters **)(v17 + 24);
      if ( v20 )
      {
        v12 = v20->i_ref_count-- == 1;
        if ( v12 )
        {
          v20->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
        *(_QWORD *)(v17 + 24) = 0i64;
      }
      v99 = v17;
      *(ASymbol *)(v17 + 8) = ASymbol_add;
      *(_QWORD *)(v17 + 16) = v18;
      *(_QWORD *)v17 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v17 + 24) = v19;
      if ( v19 )
        ++v19->i_ref_count;
      *(_QWORD *)v17 = &SSMethodBase::`vftable;
      *(_QWORD *)v17 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v17 + 32) = SSReal::mthd_op_add;
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
  v21 = (SSMethodBase **)SSBrain::c_real_class_p;
  v22 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    v21 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v23 = &v21[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v21[((char *)v23 - (char *)v21) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_add_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v21 == a2 )
          goto LABEL_58;
        v23 = a2 - 1;
      }
      v24 = ASymbol_add_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_add_assign.i_uid != (_DWORD)i_uid;
      if ( v24 )
        break;
      if ( v23 == a2 )
        goto LABEL_58;
      v21 = a2 + 1;
    }
    v25 = (__int64)*a2;
  }
  else
  {
LABEL_58:
    v25 = 0i64;
  }
  result = v25;
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           v21,
           i_uid) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSReal::mthd_op_add_assign;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v98 = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v28 = *(SSParameters **)(v25 + 24);
      if ( v28 )
      {
        v12 = v28->i_ref_count-- == 1;
        if ( v12 )
        {
          v28->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        *(_QWORD *)(v25 + 24) = 0i64;
      }
      v99 = v25;
      *(ASymbol *)(v25 + 8) = ASymbol_add_assign;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable;
      *(_QWORD *)v25 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v25 + 32) = SSReal::mthd_op_add_assign;
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
  v29 = (SSMethodBase **)SSBrain::c_real_class_p;
  v30 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v30 )
  {
    v29 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v31 = &v29[v30 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v29[((char *)v31 - (char *)v29) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Integer.i_uid >= (unsigned int)i_uid )
          break;
        if ( v29 == a2 )
          goto LABEL_82;
        v31 = a2 - 1;
      }
      v32 = ASymbol_Integer.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Integer.i_uid != (_DWORD)i_uid;
      if ( v32 )
        break;
      if ( v31 == a2 )
        goto LABEL_82;
      v29 = a2 + 1;
    }
    v33 = (__int64)*a2;
  }
  else
  {
LABEL_82:
    v33 = 0i64;
  }
  result = v33;
  if ( v33 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v33 + 16i64))(
           v33,
           a2,
           v29,
           i_uid) == 1 )
    {
      *(_QWORD *)(v33 + 32) = SSReal::mthd_as_int;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v98 = v35;
      if ( v35 )
        ++v35->i_ref_count;
      v36 = *(SSParameters **)(v33 + 24);
      if ( v36 )
      {
        v12 = v36->i_ref_count-- == 1;
        if ( v12 )
        {
          v36->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v36);
          AMemory::c_free_func(v36);
        }
        *(_QWORD *)(v33 + 24) = 0i64;
      }
      v99 = v33;
      *(ASymbol *)(v33 + 8) = ASymbol_Integer;
      *(_QWORD *)(v33 + 16) = v34;
      *(_QWORD *)v33 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v33 + 24) = v35;
      if ( v35 )
        ++v35->i_ref_count;
      *(_QWORD *)v33 = &SSMethodBase::`vftable;
      *(_QWORD *)v33 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v33 + 32) = SSReal::mthd_as_int;
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
  v37 = (SSMethodBase **)SSBrain::c_real_class_p;
  v38 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v38 )
  {
    v37 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v39 = &v37[v38 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v37[((char *)v39 - (char *)v37) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_String.i_uid >= (unsigned int)i_uid )
          break;
        if ( v37 == a2 )
          goto LABEL_106;
        v39 = a2 - 1;
      }
      v40 = ASymbol_String.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_String.i_uid != (_DWORD)i_uid;
      if ( v40 )
        break;
      if ( v39 == a2 )
        goto LABEL_106;
      v37 = a2 + 1;
    }
    v41 = (__int64)*a2;
  }
  else
  {
LABEL_106:
    v41 = 0i64;
  }
  result = v41;
  if ( v41 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v41 + 16i64))(
           v41,
           a2,
           v37,
           i_uid) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSReal::mthd_as_string;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v98 = v43;
      if ( v43 )
        ++v43->i_ref_count;
      v44 = *(SSParameters **)(v41 + 24);
      if ( v44 )
      {
        v12 = v44->i_ref_count-- == 1;
        if ( v12 )
        {
          v44->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v44);
          AMemory::c_free_func(v44);
        }
        *(_QWORD *)(v41 + 24) = 0i64;
      }
      v99 = v41;
      *(ASymbol *)(v41 + 8) = ASymbol_String;
      *(_QWORD *)(v41 + 16) = v42;
      *(_QWORD *)v41 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v41 + 24) = v43;
      if ( v43 )
        ++v43->i_ref_count;
      *(_QWORD *)v41 = &SSMethodBase::`vftable;
      *(_QWORD *)v41 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v41 + 32) = SSReal::mthd_as_string;
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
  v45 = (SSMethodBase **)SSBrain::c_real_class_p;
  v46 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v46 )
  {
    v45 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v47 = &v45[v46 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &v45[((char *)v47 - (char *)v45) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_assign.i_uid >= (unsigned int)i_uid )
          break;
        if ( v45 == a2 )
          goto LABEL_130;
        v47 = a2 - 1;
      }
      v48 = ASymbol_assign.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_assign.i_uid != (_DWORD)i_uid;
      if ( v48 )
        break;
      if ( v47 == a2 )
        goto LABEL_130;
      v45 = a2 + 1;
    }
    v49 = (__int64)*a2;
  }
  else
  {
LABEL_130:
    v49 = 0i64;
  }
  result = v49;
  if ( v49 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v49 + 16i64))(
           v49,
           a2,
           v45,
           i_uid) == 1 )
    {
      *(_QWORD *)(v49 + 32) = SSReal::mthd_op_assign;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v98 = v51;
      if ( v51 )
        ++v51->i_ref_count;
      v52 = *(SSParameters **)(v49 + 24);
      if ( v52 )
      {
        v12 = v52->i_ref_count-- == 1;
        if ( v12 )
        {
          v52->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v52);
          AMemory::c_free_func(v52);
        }
        *(_QWORD *)(v49 + 24) = 0i64;
      }
      v99 = v49;
      *(ASymbol *)(v49 + 8) = ASymbol_assign;
      *(_QWORD *)(v49 + 16) = v50;
      *(_QWORD *)v49 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v49 + 24) = v51;
      if ( v51 )
        ++v51->i_ref_count;
      *(_QWORD *)v49 = &SSMethodBase::`vftable;
      *(_QWORD *)v49 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v49 + 32) = SSReal::mthd_op_assign;
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
  v53 = SSBrain::c_real_class_p;
  v54 = ASymbol::create((ASymbol *)&result, "clamp", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(
    v53,
    v54,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSReal::mthd_clamp,
    SSBindFlag_instance_no_rebind);
  v57 = (SSMethodBase **)SSBrain::c_real_class_p;
  v58 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v58 )
  {
    v57 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v59 = &v57[v58 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v55 = &v57[((char *)v59 - (char *)v57) >> 4];
        v56 = (*v55)->i_name.i_uid;
        if ( ASymbol_decrement.i_uid >= (unsigned int)v56 )
          break;
        if ( v57 == v55 )
          goto LABEL_154;
        v59 = v55 - 1;
      }
      v60 = ASymbol_decrement.i_uid == (_DWORD)v56;
      v56 = ASymbol_decrement.i_uid != (_DWORD)v56;
      if ( v60 )
        break;
      if ( v59 == v55 )
        goto LABEL_154;
      v57 = v55 + 1;
    }
    v61 = (__int64)*v55;
  }
  else
  {
LABEL_154:
    v61 = 0i64;
  }
  result = v61;
  if ( v61 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v61 + 16i64))(
           v61,
           v55,
           v57,
           v56) == 1 )
    {
      *(_QWORD *)(v61 + 32) = SSReal::mthd_op_decrement;
    }
    else
    {
      v62 = *(_QWORD *)(v61 + 16);
      v63 = *(SSParameters **)(v61 + 24);
      v98 = v63;
      if ( v63 )
        ++v63->i_ref_count;
      v64 = *(SSParameters **)(v61 + 24);
      if ( v64 )
      {
        v12 = v64->i_ref_count-- == 1;
        if ( v12 )
        {
          v64->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v64);
          AMemory::c_free_func(v64);
        }
        *(_QWORD *)(v61 + 24) = 0i64;
      }
      v99 = v61;
      *(ASymbol *)(v61 + 8) = ASymbol_decrement;
      *(_QWORD *)(v61 + 16) = v62;
      *(_QWORD *)v61 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v61 + 24) = v63;
      if ( v63 )
        ++v63->i_ref_count;
      *(_QWORD *)v61 = &SSMethodBase::`vftable;
      *(_QWORD *)v61 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v61 + 32) = SSReal::mthd_op_decrement;
      if ( v63 )
      {
        v12 = v63->i_ref_count-- == 1;
        if ( v12 )
        {
          v63->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v63);
          AMemory::c_free_func(v63);
        }
      }
    }
  }
  v65 = (SSMethodBase **)SSBrain::c_real_class_p;
  v66 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v66 )
  {
    v65 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v67 = &v65[v66 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v55 = &v65[((char *)v67 - (char *)v65) >> 4];
        v56 = (*v55)->i_name.i_uid;
        if ( ASymbol_divide.i_uid >= (unsigned int)v56 )
          break;
        if ( v65 == v55 )
          goto LABEL_178;
        v67 = v55 - 1;
      }
      v68 = ASymbol_divide.i_uid == (_DWORD)v56;
      v56 = ASymbol_divide.i_uid != (_DWORD)v56;
      if ( v68 )
        break;
      if ( v67 == v55 )
        goto LABEL_178;
      v65 = v55 + 1;
    }
    v69 = (__int64)*v55;
  }
  else
  {
LABEL_178:
    v69 = 0i64;
  }
  result = v69;
  if ( v69 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v69 + 16i64))(
           v69,
           v55,
           v65,
           v56) == 1 )
    {
      *(_QWORD *)(v69 + 32) = SSReal::mthd_op_divide;
    }
    else
    {
      v70 = *(_QWORD *)(v69 + 16);
      v71 = *(SSParameters **)(v69 + 24);
      v98 = v71;
      if ( v71 )
        ++v71->i_ref_count;
      v72 = *(SSParameters **)(v69 + 24);
      if ( v72 )
      {
        v12 = v72->i_ref_count-- == 1;
        if ( v12 )
        {
          v72->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v72);
          AMemory::c_free_func(v72);
        }
        *(_QWORD *)(v69 + 24) = 0i64;
      }
      v99 = v69;
      *(ASymbol *)(v69 + 8) = ASymbol_divide;
      *(_QWORD *)(v69 + 16) = v70;
      *(_QWORD *)v69 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v69 + 24) = v71;
      if ( v71 )
        ++v71->i_ref_count;
      *(_QWORD *)v69 = &SSMethodBase::`vftable;
      *(_QWORD *)v69 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v69 + 32) = SSReal::mthd_op_divide;
      if ( v71 )
      {
        v12 = v71->i_ref_count-- == 1;
        if ( v12 )
        {
          v71->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v71);
          AMemory::c_free_func(v71);
        }
      }
    }
  }
  v73 = (SSMethodBase **)SSBrain::c_real_class_p;
  v74 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v74 )
  {
    v73 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v75 = &v73[v74 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v55 = &v73[((char *)v75 - (char *)v73) >> 4];
        v56 = (*v55)->i_name.i_uid;
        if ( ASymbol_divide_assign.i_uid >= (unsigned int)v56 )
          break;
        if ( v73 == v55 )
          goto LABEL_202;
        v75 = v55 - 1;
      }
      v76 = ASymbol_divide_assign.i_uid == (_DWORD)v56;
      v56 = ASymbol_divide_assign.i_uid != (_DWORD)v56;
      if ( v76 )
        break;
      if ( v75 == v55 )
        goto LABEL_202;
      v73 = v55 + 1;
    }
    v77 = (__int64)*v55;
  }
  else
  {
LABEL_202:
    v77 = 0i64;
  }
  result = v77;
  if ( v77 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v77 + 16i64))(
           v77,
           v55,
           v73,
           v56) == 1 )
    {
      *(_QWORD *)(v77 + 32) = SSReal::mthd_op_divide_assign;
    }
    else
    {
      v78 = *(_QWORD *)(v77 + 16);
      v79 = *(SSParameters **)(v77 + 24);
      v98 = v79;
      if ( v79 )
        ++v79->i_ref_count;
      v80 = *(SSParameters **)(v77 + 24);
      if ( v80 )
      {
        v12 = v80->i_ref_count-- == 1;
        if ( v12 )
        {
          v80->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v80);
          AMemory::c_free_func(v80);
        }
        *(_QWORD *)(v77 + 24) = 0i64;
      }
      v99 = v77;
      *(ASymbol *)(v77 + 8) = ASymbol_divide_assign;
      *(_QWORD *)(v77 + 16) = v78;
      *(_QWORD *)v77 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v77 + 24) = v79;
      if ( v79 )
        ++v79->i_ref_count;
      *(_QWORD *)v77 = &SSMethodBase::`vftable;
      *(_QWORD *)v77 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v77 + 32) = SSReal::mthd_op_divide_assign;
      if ( v79 )
      {
        v12 = v79->i_ref_count-- == 1;
        if ( v12 )
        {
          v79->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v79);
          AMemory::c_free_func(v79);
        }
      }
    }
  }
  v81 = (SSMethodBase **)SSBrain::c_real_class_p;
  v82 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v82 )
  {
    v81 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v83 = &v81[v82 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v55 = &v81[((char *)v83 - (char *)v81) >> 4];
        v56 = (*v55)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)v56 )
          break;
        if ( v81 == v55 )
          goto LABEL_226;
        v83 = v55 - 1;
      }
      v84 = ASymbol_equals.i_uid == (_DWORD)v56;
      v56 = ASymbol_equals.i_uid != (_DWORD)v56;
      if ( v84 )
        break;
      if ( v83 == v55 )
        goto LABEL_226;
      v81 = v55 + 1;
    }
    v85 = (__int64)*v55;
  }
  else
  {
LABEL_226:
    v85 = 0i64;
  }
  result = v85;
  if ( v85 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v85 + 16i64))(
           v85,
           v55,
           v81,
           v56) == 1 )
    {
      *(_QWORD *)(v85 + 32) = SSReal::mthd_op_equals;
    }
    else
    {
      v86 = *(_QWORD *)(v85 + 16);
      v87 = *(SSParameters **)(v85 + 24);
      v98 = v87;
      if ( v87 )
        ++v87->i_ref_count;
      v88 = *(SSParameters **)(v85 + 24);
      if ( v88 )
      {
        v12 = v88->i_ref_count-- == 1;
        if ( v12 )
        {
          v88->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v88);
          AMemory::c_free_func(v88);
        }
        *(_QWORD *)(v85 + 24) = 0i64;
      }
      v99 = v85;
      *(ASymbol *)(v85 + 8) = ASymbol_equals;
      *(_QWORD *)(v85 + 16) = v86;
      *(_QWORD *)v85 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v85 + 24) = v87;
      if ( v87 )
        ++v87->i_ref_count;
      *(_QWORD *)v85 = &SSMethodBase::`vftable;
      *(_QWORD *)v85 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v85 + 32) = SSReal::mthd_op_equals;
      if ( v87 )
      {
        v12 = v87->i_ref_count-- == 1;
        if ( v12 )
        {
          v87->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v87);
          AMemory::c_free_func(v87);
        }
      }
    }
  }
  v89 = (SSMethodBase **)SSBrain::c_real_class_p;
  v90 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v90 )
  {
    v89 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v91 = &v89[v90 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v55 = &v89[((char *)v91 - (char *)v89) >> 4];
        v56 = (*v55)->i_name.i_uid;
        if ( ASymbol_greater.i_uid >= (unsigned int)v56 )
          break;
        if ( v89 == v55 )
          goto LABEL_250;
        v91 = v55 - 1;
      }
      v92 = ASymbol_greater.i_uid == (_DWORD)v56;
      v56 = ASymbol_greater.i_uid != (_DWORD)v56;
      if ( v92 )
        break;
      if ( v91 == v55 )
        goto LABEL_250;
      v89 = v55 + 1;
    }
    v93 = (__int64)*v55;
  }
  else
  {
LABEL_250:
    v93 = 0i64;
  }
  result = v93;
  if ( v93 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSMethodBase **, SSMethodBase **, __int64))(*(_QWORD *)v93 + 16i64))(
           v93,
           v55,
           v89,
           v56) == 1 )
    {
      *(_QWORD *)(v93 + 32) = SSReal::mthd_op_greater;
    }
    else
    {
      v94 = *(_QWORD *)(v93 + 16);
      v95 = *(SSParameters **)(v93 + 24);
      v98 = v95;
      if ( v95 )
        ++v95->i_ref_count;
      v96 = *(SSParameters **)(v93 + 24);
      if ( v96 )
      {
        v12 = v96->i_ref_count-- == 1;
        if ( v12 )
        {
          v96->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v96);
          AMemory::c_free_func(v96);
        }
        *(_QWORD *)(v93 + 24) = 0i64;
      }
      v99 = v93;
      *(ASymbol *)(v93 + 8) = ASymbol_greater;
      *(_QWORD *)(v93 + 16) = v94;
      *(_QWORD *)v93 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v93 + 24) = v95;
      if ( v95 )
        ++v95->i_ref_count;
      *(_QWORD *)v93 = &SSMethodBase::`vftable;
      *(_QWORD *)v93 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v93 + 32) = SSReal::mthd_op_greater;
      if ( v95 )
      {
        v12 = v95->i_ref_count-- == 1;
        if ( v12 )
        {
          v95->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v95);
          AMemory::c_free_func(v95);
        }
      }
    }
  }
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_greater_or_equal,
    SSReal::mthd_op_greater_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_increment,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSReal::mthd_op_increment,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_less,
    SSReal::mthd_op_less,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_less_or_equal,
    SSReal::mthd_op_less_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_multiply,
    SSReal::mthd_op_multiply,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_multiply_assign,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSReal::mthd_op_multiply_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_not_equal,
    SSReal::mthd_op_not_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_subtract,
    SSReal::mthd_op_subtract,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_subtract_assign,
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))SSReal::mthd_op_subtract_assign,
    SSBindFlag_instance_no_rebind);
}  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_less_or_equal,
    SSReal::mthd_op_less_or_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    SSBrain::c_real_class_p,
    &ASymbol_multiply,
    SSReal::mthd_op_multiply,
    SSBindFlag_instance_no_rebind);
  SSClass::register

