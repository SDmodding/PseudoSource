// File Line: 61
// RVA: 0x120ED0
void __fastcall SSReal::mthd_as_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_integer_class_p,
                   (unsigned int)(signed int)(float)(*(float *)&v2[2].vfptr + 0.5));
  }
}

// File Line: 82
// RVA: 0x121790
void __fastcall SSReal::mthd_as_string(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r9
  AString *v4; // rdi
  SSInstance *v5; // rax
  AStringRef *v6; // rcx
  AStringRef *v7; // rbx
  bool v8; // zf
  AObjReusePool<AStringRef> *v9; // rax
  AObjBlock<AStringRef> *v10; // rcx
  unsigned __int64 v11; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v13; // rcx
  AString result; // [rsp+48h] [rbp+10h]
  SSInstance *v15; // [rsp+50h] [rbp+18h]
  unsigned __int64 *v16; // [rsp+58h] [rbp+20h]

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = AString::ctor_float(&result, *(float *)&v3[2].vfptr, 6u);
    v5 = SSInstance::pool_new(SSBrain::c_string_class_p);
    v15 = v5;
    v16 = &v5->i_user_data;
    if ( v5 != (SSInstance *)-32i64 )
    {
      v6 = v4->i_str_ref_p;
      v5->i_user_data = (unsigned __int64)v4->i_str_ref_p;
      ++v6->i_ref_count;
    }
    *v2 = v5;
    v7 = result.i_str_ref_p;
    v8 = result.i_str_ref_p->i_ref_count == 1;
    --v7->i_ref_count;
    if ( v8 )
    {
      if ( v7->i_deallocate )
        AMemory::c_free_func(v7->i_cstr_p);
      v9 = AStringRef::get_pool();
      v10 = v9->i_block_p;
      v11 = (unsigned __int64)v10->i_objects_a;
      if ( (unsigned __int64)v7 < v11
        || (v12 = (unsigned __int64)v7 < v11 + 24i64 * v10->i_size, v13 = &v9->i_pool, !v12) )
      {
        v13 = &v9->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v13, v7);
    }
  }
}

// File Line: 138
// RVA: 0x1240E0
void __fastcall SSReal::mthd_op_increment(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr + 1.0;
    ++LODWORD(v2[1].vfptr);
    *result_pp = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr + 1.0;
  }
}

// File Line: 170
// RVA: 0x1239B0
void __fastcall SSReal::mthd_op_decrement(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr - 1.0;
    ++LODWORD(v2[1].vfptr);
    *result_pp = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr - 1.0;
  }
}

// File Line: 202
// RVA: 0x123480
void __fastcall SSReal::mthd_op_add(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // rbx
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  SSObjectBase *v5; // r8

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = result_pp;
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *v3 = v4;
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    *(float *)&v4->i_user_data = *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data + *(float *)&v5[2].vfptr;
  }
}

// File Line: 227
// RVA: 0x123660
void __fastcall SSReal::mthd_op_add_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data + *(float *)&v2[2].vfptr;
    ++LODWORD(v2[1].vfptr);
    *result_pp = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data + *(float *)&v2[2].vfptr;
  }
}

// File Line: 259
// RVA: 0x1248C0
void __fastcall SSReal::mthd_op_subtract(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // rbx
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  SSObjectBase *v5; // r8

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = result_pp;
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *v3 = v4;
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    *(float *)&v4->i_user_data = *(float *)&v5[2].vfptr - *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 284
// RVA: 0x124990
void __fastcall SSReal::mthd_op_subtract_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr - *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++LODWORD(v2[1].vfptr);
    *result_pp = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr - *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 316
// RVA: 0x124450
void __fastcall SSReal::mthd_op_multiply(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // rbx
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  SSObjectBase *v5; // r8

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = result_pp;
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *v3 = v4;
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    *(float *)&v4->i_user_data = *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data * *(float *)&v5[2].vfptr;
  }
}

// File Line: 341
// RVA: 0x124530
void __fastcall SSReal::mthd_op_multiply_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data * *(float *)&v2[2].vfptr;
    ++LODWORD(v2[1].vfptr);
    *result_pp = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data * *(float *)&v2[2].vfptr;
  }
}

// File Line: 373
// RVA: 0x123A60
void __fastcall SSReal::mthd_op_divide(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // rbx
  SSInstance **v3; // rdi
  SSInstance *v4; // rax
  SSObjectBase *v5; // r8

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = result_pp;
    v4 = SSInstance::pool_new(SSBrain::c_real_class_p);
    *v3 = v4;
    v5 = v2->i_scope_p.i_obj_p;
    if ( !v5 || v2->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    *(float *)&v4->i_user_data = *(float *)&v5[2].vfptr / *(float *)&(*v2->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 398
// RVA: 0x123B40
void __fastcall SSReal::mthd_op_divide_assign(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( result_pp )
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr / *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    ++LODWORD(v2[1].vfptr);
    *result_pp = (SSInstance *)v2;
  }
  else
  {
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *(float *)&v2[2].vfptr = *(float *)&v2[2].vfptr / *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
  }
}

// File Line: 430
// RVA: 0x123CA0
void __fastcall SSReal::mthd_op_equals(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    if ( *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data == *(float *)&v2[2].vfptr )
      *result_pp = (SSInstance *)SSBoolean::pool_new(1);
    else
      *result_pp = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 455
// RVA: 0x1246D0
void __fastcall SSReal::mthd_op_not_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    if ( *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data == *(float *)&v2[2].vfptr )
      *result_pp = (SSInstance *)SSBoolean::pool_new(0);
    else
      *result_pp = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 480
// RVA: 0x123E30
void __fastcall SSReal::mthd_op_greater(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(*(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data < *(float *)&v2[2].vfptr);
  }
}

// File Line: 505
// RVA: 0x123F90
void __fastcall SSReal::mthd_op_greater_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(*(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data <= *(float *)&v2[2].vfptr);
  }
}

// File Line: 530
// RVA: 0x124190
void __fastcall SSReal::mthd_op_less(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(*(float *)&v2[2].vfptr < *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 555
// RVA: 0x1242F0
void __fastcall SSReal::mthd_op_less_or_equal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *result_pp = (SSInstance *)SSBoolean::pool_new(*(float *)&v2[2].vfptr <= *(float *)&(*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 574
// RVA: 0x121B50
void __fastcall SSReal::mthd_clamp(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r9
  SSData **v4; // rdx
  float v5; // xmm1_4
  float v6; // xmm0_4

  v2 = scope_p->i_scope_p.i_obj_p;
  v3 = result_pp;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = scope_p->i_data.i_array_p;
  v5 = *(float *)&v4[1]->i_data_p->i_user_data;
  v6 = *(float *)&(*v4)->i_data_p->i_user_data;
  if ( *(float *)&v2[2].vfptr >= v6 )
    v6 = *(float *)&v2[2].vfptr;
  if ( v6 <= v5 )
    v5 = v6;
  *(float *)&v2[2].vfptr = v5;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 593
// RVA: 0x138390
void __fastcall SSReal::register_atomic(__int64 a1, signed __int64 a2, __int64 a3, __int64 a4)
{
  SSMethodBase **v4; // r8
  __int64 v5; // rax
  signed __int64 v6; // r10
  _BOOL8 v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // r15
  SSParameters *v10; // rsi
  SSParameters *v11; // r14
  bool v12; // zf
  SSMethodBase **v13; // r8
  __int64 v14; // rax
  signed __int64 v15; // r10
  _BOOL8 v16; // rcx
  __int64 v17; // rbx
  __int64 v18; // r15
  SSParameters *v19; // rsi
  SSParameters *v20; // r14
  SSMethodBase **v21; // r8
  __int64 v22; // rax
  signed __int64 v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rbx
  __int64 v26; // r15
  SSParameters *v27; // rsi
  SSParameters *v28; // r14
  SSMethodBase **v29; // r8
  __int64 v30; // rax
  signed __int64 v31; // r10
  _BOOL8 v32; // rcx
  __int64 v33; // rbx
  __int64 v34; // r15
  SSParameters *v35; // rsi
  SSParameters *v36; // r14
  SSMethodBase **v37; // r8
  __int64 v38; // rax
  signed __int64 v39; // r10
  _BOOL8 v40; // rcx
  __int64 v41; // rbx
  __int64 v42; // r15
  SSParameters *v43; // rsi
  SSParameters *v44; // r14
  SSMethodBase **v45; // r8
  __int64 v46; // rax
  signed __int64 v47; // r10
  _BOOL8 v48; // rcx
  __int64 v49; // rbx
  __int64 v50; // r15
  SSParameters *v51; // rsi
  SSParameters *v52; // r14
  SSClass *v53; // rbx
  ASymbol *v54; // rax
  signed __int64 v55; // rdx
  __int64 v56; // r9
  SSMethodBase **v57; // r8
  __int64 v58; // rax
  signed __int64 v59; // r10
  _BOOL8 v60; // rcx
  __int64 v61; // rbx
  __int64 v62; // r15
  SSParameters *v63; // rsi
  SSParameters *v64; // r14
  SSMethodBase **v65; // r8
  __int64 v66; // rax
  signed __int64 v67; // r10
  _BOOL8 v68; // rcx
  __int64 v69; // rbx
  __int64 v70; // r15
  SSParameters *v71; // rsi
  SSParameters *v72; // r14
  SSMethodBase **v73; // r8
  __int64 v74; // rax
  signed __int64 v75; // r10
  _BOOL8 v76; // rcx
  __int64 v77; // rbx
  __int64 v78; // r15
  SSParameters *v79; // rsi
  SSParameters *v80; // r14
  SSMethodBase **v81; // r8
  __int64 v82; // rax
  signed __int64 v83; // r10
  _BOOL8 v84; // rcx
  __int64 v85; // rbx
  __int64 v86; // r15
  SSParameters *v87; // rsi
  SSParameters *v88; // r14
  SSMethodBase **v89; // r8
  __int64 v90; // rax
  signed __int64 v91; // r10
  _BOOL8 v92; // rcx
  __int64 v93; // rbx
  __int64 v94; // r15
  SSParameters *v95; // rsi
  SSParameters *v96; // r14
  signed __int64 v97; // [rsp+20h] [rbp-10h]
  __int64 result; // [rsp+70h] [rbp+40h]
  SSParameters *v99; // [rsp+78h] [rbp+48h]
  __int64 v100; // [rsp+80h] [rbp+50h]

  v97 = -2i64;
  v4 = (SSMethodBase **)SSBrain::c_real_class_p;
  v5 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v5 )
  {
    v4 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v6 = (signed __int64)&v4[v5 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v4[(v6 - (signed __int64)v4) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_ctor_copy.i_uid < (unsigned int)a4 )
        goto LABEL_279;
      v7 = ASymbolX_ctor_copy.i_uid == (_DWORD)a4;
      a4 = ASymbolX_ctor_copy.i_uid != (_DWORD)a4;
      if ( v7 == 1 )
      {
        v8 = *(_QWORD *)a2;
        goto LABEL_12;
      }
      if ( a4 < 0 )
      {
LABEL_279:
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
  result = v8;
  if ( v8 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v8 + 16i64))(
           v8,
           a2,
           v4,
           a4,
           -2i64) == 1 )
    {
      *(_QWORD *)(v8 + 32) = SSReal::mthd_ctor_copy;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 16);
      v10 = *(SSParameters **)(v8 + 24);
      v99 = v10;
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
      v100 = v8;
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
          v10->i_ref_count = 2147483648;
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
    v15 = (signed __int64)&v13[v14 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v13[(v15 - (signed __int64)v13) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_add.i_uid < (unsigned int)a4 )
        goto LABEL_280;
      v16 = ASymbol_add.i_uid == (_DWORD)a4;
      a4 = ASymbol_add.i_uid != (_DWORD)a4;
      if ( v16 == 1 )
      {
        v17 = *(_QWORD *)a2;
        goto LABEL_37;
      }
      if ( a4 < 0 )
      {
LABEL_280:
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
  result = v17;
  if ( v17 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v17 + 16i64))(
           v17,
           a2,
           v13,
           a4,
           v97) == 1 )
    {
      *(_QWORD *)(v17 + 32) = SSReal::mthd_op_add;
    }
    else
    {
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(SSParameters **)(v17 + 24);
      v99 = v19;
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
      v100 = v17;
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
          v19->i_ref_count = 2147483648;
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
    v23 = (signed __int64)&v21[v22 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v21[(v23 - (signed __int64)v21) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_add_assign.i_uid < (unsigned int)a4 )
        goto LABEL_281;
      v24 = ASymbol_add_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_add_assign.i_uid != (_DWORD)a4;
      if ( v24 == 1 )
      {
        v25 = *(_QWORD *)a2;
        goto LABEL_62;
      }
      if ( a4 < 0 )
      {
LABEL_281:
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
  result = v25;
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           v21,
           a4,
           v97) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSReal::mthd_op_add_assign;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v99 = v27;
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
      v100 = v25;
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
          v27->i_ref_count = 2147483648;
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
    v31 = (signed __int64)&v29[v30 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v29[(v31 - (signed __int64)v29) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_Integer.i_uid < (unsigned int)a4 )
        goto LABEL_282;
      v32 = ASymbol_Integer.i_uid == (_DWORD)a4;
      a4 = ASymbol_Integer.i_uid != (_DWORD)a4;
      if ( v32 == 1 )
      {
        v33 = *(_QWORD *)a2;
        goto LABEL_87;
      }
      if ( a4 < 0 )
      {
LABEL_282:
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
  result = v33;
  if ( v33 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v33 + 16i64))(
           v33,
           a2,
           v29,
           a4,
           v97) == 1 )
    {
      *(_QWORD *)(v33 + 32) = SSReal::mthd_as_int;
    }
    else
    {
      v34 = *(_QWORD *)(v33 + 16);
      v35 = *(SSParameters **)(v33 + 24);
      v99 = v35;
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
      v100 = v33;
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
          v35->i_ref_count = 2147483648;
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
    v39 = (signed __int64)&v37[v38 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v37[(v39 - (signed __int64)v37) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_String.i_uid < (unsigned int)a4 )
        goto LABEL_283;
      v40 = ASymbol_String.i_uid == (_DWORD)a4;
      a4 = ASymbol_String.i_uid != (_DWORD)a4;
      if ( v40 == 1 )
      {
        v41 = *(_QWORD *)a2;
        goto LABEL_112;
      }
      if ( a4 < 0 )
      {
LABEL_283:
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
  result = v41;
  if ( v41 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v41 + 16i64))(
           v41,
           a2,
           v37,
           a4,
           v97) == 1 )
    {
      *(_QWORD *)(v41 + 32) = SSReal::mthd_as_string;
    }
    else
    {
      v42 = *(_QWORD *)(v41 + 16);
      v43 = *(SSParameters **)(v41 + 24);
      v99 = v43;
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
      v100 = v41;
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
          v43->i_ref_count = 2147483648;
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
    v47 = (signed __int64)&v45[v46 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&v45[(v47 - (signed __int64)v45) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_assign.i_uid < (unsigned int)a4 )
        goto LABEL_284;
      v48 = ASymbol_assign.i_uid == (_DWORD)a4;
      a4 = ASymbol_assign.i_uid != (_DWORD)a4;
      if ( v48 == 1 )
      {
        v49 = *(_QWORD *)a2;
        goto LABEL_137;
      }
      if ( a4 < 0 )
      {
LABEL_284:
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
  result = v49;
  if ( v49 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v49 + 16i64))(
           v49,
           a2,
           v45,
           a4,
           v97) == 1 )
    {
      *(_QWORD *)(v49 + 32) = SSReal::mthd_op_assign;
    }
    else
    {
      v50 = *(_QWORD *)(v49 + 16);
      v51 = *(SSParameters **)(v49 + 24);
      v99 = v51;
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
      v100 = v49;
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
          v51->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v51);
          AMemory::c_free_func(v51);
        }
      }
    }
  }
  v53 = SSBrain::c_real_class_p;
  v54 = ASymbol::create((ASymbol *)&result, "clamp", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v53, v54, SSReal::mthd_clamp, 0);
  v57 = (SSMethodBase **)SSBrain::c_real_class_p;
  v58 = SSBrain::c_real_class_p->i_methods.i_count;
  if ( (_DWORD)v58 )
  {
    v57 = SSBrain::c_real_class_p->i_methods.i_array_p;
    v59 = (signed __int64)&v57[v58 - 1];
    while ( 1 )
    {
      v55 = (signed __int64)&v57[(v59 - (signed __int64)v57) >> 4];
      v56 = *(unsigned int *)(*(_QWORD *)v55 + 8i64);
      if ( ASymbol_decrement.i_uid < (unsigned int)v56 )
        goto LABEL_285;
      v60 = ASymbol_decrement.i_uid == (_DWORD)v56;
      v56 = ASymbol_decrement.i_uid != (_DWORD)v56;
      if ( v60 == 1 )
      {
        v61 = *(_QWORD *)v55;
        goto LABEL_162;
      }
      if ( v56 < 0 )
      {
LABEL_285:
        if ( v57 == (SSMethodBase **)v55 )
          break;
        v59 = v55 - 8;
      }
      else
      {
        if ( v59 == v55 )
          break;
        v57 = (SSMethodBase **)(v55 + 8);
      }
    }
  }
  v61 = 0i64;
LABEL_162:
  result = v61;
  if ( v61 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v61 + 16i64))(
           v61,
           v55,
           v57,
           v56,
           v97) == 1 )
    {
      *(_QWORD *)(v61 + 32) = SSReal::mthd_op_decrement;
    }
    else
    {
      v62 = *(_QWORD *)(v61 + 16);
      v63 = *(SSParameters **)(v61 + 24);
      v99 = v63;
      if ( v63 )
        ++v63->i_ref_count;
      v64 = *(SSParameters **)(v61 + 24);
      if ( v64 )
      {
        v12 = v64->i_ref_count-- == 1;
        if ( v12 )
        {
          v64->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v64);
          AMemory::c_free_func(v64);
        }
        *(_QWORD *)(v61 + 24) = 0i64;
      }
      v100 = v61;
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
          v63->i_ref_count = 2147483648;
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
    v67 = (signed __int64)&v65[v66 - 1];
    while ( 1 )
    {
      v55 = (signed __int64)&v65[(v67 - (signed __int64)v65) >> 4];
      v56 = *(unsigned int *)(*(_QWORD *)v55 + 8i64);
      if ( ASymbol_divide.i_uid < (unsigned int)v56 )
        goto LABEL_286;
      v68 = ASymbol_divide.i_uid == (_DWORD)v56;
      v56 = ASymbol_divide.i_uid != (_DWORD)v56;
      if ( v68 == 1 )
      {
        v69 = *(_QWORD *)v55;
        goto LABEL_187;
      }
      if ( v56 < 0 )
      {
LABEL_286:
        if ( v65 == (SSMethodBase **)v55 )
          break;
        v67 = v55 - 8;
      }
      else
      {
        if ( v67 == v55 )
          break;
        v65 = (SSMethodBase **)(v55 + 8);
      }
    }
  }
  v69 = 0i64;
LABEL_187:
  result = v69;
  if ( v69 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v69 + 16i64))(
           v69,
           v55,
           v65,
           v56,
           v97) == 1 )
    {
      *(_QWORD *)(v69 + 32) = SSReal::mthd_op_divide;
    }
    else
    {
      v70 = *(_QWORD *)(v69 + 16);
      v71 = *(SSParameters **)(v69 + 24);
      v99 = v71;
      if ( v71 )
        ++v71->i_ref_count;
      v72 = *(SSParameters **)(v69 + 24);
      if ( v72 )
      {
        v12 = v72->i_ref_count-- == 1;
        if ( v12 )
        {
          v72->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v72);
          AMemory::c_free_func(v72);
        }
        *(_QWORD *)(v69 + 24) = 0i64;
      }
      v100 = v69;
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
          v71->i_ref_count = 2147483648;
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
    v75 = (signed __int64)&v73[v74 - 1];
    while ( 1 )
    {
      v55 = (signed __int64)&v73[(v75 - (signed __int64)v73) >> 4];
      v56 = *(unsigned int *)(*(_QWORD *)v55 + 8i64);
      if ( ASymbol_divide_assign.i_uid < (unsigned int)v56 )
        goto LABEL_287;
      v76 = ASymbol_divide_assign.i_uid == (_DWORD)v56;
      v56 = ASymbol_divide_assign.i_uid != (_DWORD)v56;
      if ( v76 == 1 )
      {
        v77 = *(_QWORD *)v55;
        goto LABEL_212;
      }
      if ( v56 < 0 )
      {
LABEL_287:
        if ( v73 == (SSMethodBase **)v55 )
          break;
        v75 = v55 - 8;
      }
      else
      {
        if ( v75 == v55 )
          break;
        v73 = (SSMethodBase **)(v55 + 8);
      }
    }
  }
  v77 = 0i64;
LABEL_212:
  result = v77;
  if ( v77 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v77 + 16i64))(
           v77,
           v55,
           v73,
           v56,
           v97) == 1 )
    {
      *(_QWORD *)(v77 + 32) = SSReal::mthd_op_divide_assign;
    }
    else
    {
      v78 = *(_QWORD *)(v77 + 16);
      v79 = *(SSParameters **)(v77 + 24);
      v99 = v79;
      if ( v79 )
        ++v79->i_ref_count;
      v80 = *(SSParameters **)(v77 + 24);
      if ( v80 )
      {
        v12 = v80->i_ref_count-- == 1;
        if ( v12 )
        {
          v80->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v80);
          AMemory::c_free_func(v80);
        }
        *(_QWORD *)(v77 + 24) = 0i64;
      }
      v100 = v77;
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
          v79->i_ref_count = 2147483648;
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
    v83 = (signed __int64)&v81[v82 - 1];
    while ( 1 )
    {
      v55 = (signed __int64)&v81[(v83 - (signed __int64)v81) >> 4];
      v56 = *(unsigned int *)(*(_QWORD *)v55 + 8i64);
      if ( ASymbol_equals.i_uid < (unsigned int)v56 )
        goto LABEL_288;
      v84 = ASymbol_equals.i_uid == (_DWORD)v56;
      v56 = ASymbol_equals.i_uid != (_DWORD)v56;
      if ( v84 == 1 )
      {
        v85 = *(_QWORD *)v55;
        goto LABEL_237;
      }
      if ( v56 < 0 )
      {
LABEL_288:
        if ( v81 == (SSMethodBase **)v55 )
          break;
        v83 = v55 - 8;
      }
      else
      {
        if ( v83 == v55 )
          break;
        v81 = (SSMethodBase **)(v55 + 8);
      }
    }
  }
  v85 = 0i64;
LABEL_237:
  result = v85;
  if ( v85 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v85 + 16i64))(
           v85,
           v55,
           v81,
           v56,
           v97) == 1 )
    {
      *(_QWORD *)(v85 + 32) = SSReal::mthd_op_equals;
    }
    else
    {
      v86 = *(_QWORD *)(v85 + 16);
      v87 = *(SSParameters **)(v85 + 24);
      v99 = v87;
      if ( v87 )
        ++v87->i_ref_count;
      v88 = *(SSParameters **)(v85 + 24);
      if ( v88 )
      {
        v12 = v88->i_ref_count-- == 1;
        if ( v12 )
        {
          v88->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v88);
          AMemory::c_free_func(v88);
        }
        *(_QWORD *)(v85 + 24) = 0i64;
      }
      v100 = v85;
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
          v87->i_ref_count = 2147483648;
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
    v91 = (signed __int64)&v89[v90 - 1];
    while ( 1 )
    {
      v55 = (signed __int64)&v89[(v91 - (signed __int64)v89) >> 4];
      v56 = *(unsigned int *)(*(_QWORD *)v55 + 8i64);
      if ( ASymbol_greater.i_uid < (unsigned int)v56 )
        goto LABEL_289;
      v92 = ASymbol_greater.i_uid == (_DWORD)v56;
      v56 = ASymbol_greater.i_uid != (_DWORD)v56;
      if ( v92 == 1 )
      {
        v93 = *(_QWORD *)v55;
        goto LABEL_262;
      }
      if ( v56 < 0 )
      {
LABEL_289:
        if ( v89 == (SSMethodBase **)v55 )
          break;
        v91 = v55 - 8;
      }
      else
      {
        if ( v91 == v55 )
          break;
        v89 = (SSMethodBase **)(v55 + 8);
      }
    }
  }
  v93 = 0i64;
LABEL_262:
  result = v93;
  if ( v93 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSMethodBase **, __int64, signed __int64))(*(_QWORD *)v93 + 16i64))(
           v93,
           v55,
           v89,
           v56,
           v97) == 1 )
    {
      *(_QWORD *)(v93 + 32) = SSReal::mthd_op_greater;
    }
    else
    {
      v94 = *(_QWORD *)(v93 + 16);
      v95 = *(SSParameters **)(v93 + 24);
      v99 = v95;
      if ( v95 )
        ++v95->i_ref_count;
      v96 = *(SSParameters **)(v93 + 24);
      if ( v96 )
      {
        v12 = v96->i_ref_count-- == 1;
        if ( v12 )
        {
          v96->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v96);
          AMemory::c_free_func(v96);
        }
        *(_QWORD *)(v93 + 24) = 0i64;
      }
      v100 = v93;
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
          v95->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v95);
          AMemory::c_free_func(v95);
        }
      }
    }
  }
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_greater_or_equal, SSReal::mthd_op_greater_or_equal, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_increment, SSReal::mthd_op_increment, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_less, SSReal::mthd_op_less, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_less_or_equal, SSReal::mthd_op_less_or_equal, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_multiply, SSReal::mthd_op_multiply, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_multiply_assign, SSReal::mthd_op_multiply_assign, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_not_equal, SSReal::mthd_op_not_equal, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_subtract, SSReal::mthd_op_subtract, 0);
  SSClass::register_method_func(SSBrain::c_real_class_p, &ASymbol_subtract_assign, SSReal::mthd_op_subtract_assign, 0);
}

