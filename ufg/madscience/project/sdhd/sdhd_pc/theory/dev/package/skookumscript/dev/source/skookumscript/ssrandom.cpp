// File Line: 58
// RVA: 0x121C90
void __fastcall SSRandom::mthd_constructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  int v3; // eax
  SSObjectBase *i_obj_p; // rdx
  unsigned int v5; // r8d

  v3 = time64(0i64);
  i_obj_p = scope_p->i_scope_p.i_obj_p;
  v5 = 1664525 * v3 + 1013904223;
  if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v5;
  else
    *(_QWORD *)&MEMORY[0x20] = v5;
}

// File Line: 86
// RVA: 0x122010
void __fastcall SSRandom::mthd_ctor_seed(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_obj_p[2].vfptr = (SSObjectBaseVtbl *)LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 157
// RVA: 0x121BB0
void __fastcall SSRandom::mthd_coin_toss(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  int v3; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v3 = 1664525 * LODWORD(i_obj_p[2].vfptr);
    LODWORD(i_obj_p[2].vfptr) = v3 + 1013904223;
    *result_pp = SSBoolean::pool_new(v3 + 1013904223 < 0);
  }
}

// File Line: 195
// RVA: 0x125CF0
void __fastcall SSRandom::mthd_uniform_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  int i_user_data; // edx
  unsigned int v5; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = 1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v5;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)(HIWORD(v5) * i_user_data) >> 16);
  }
}

// File Line: 232
// RVA: 0x125B60
void __fastcall SSRandom::mthd_triangle_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  int i_user_data; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 16;
    v6 = 1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v6;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, ((v5 + HIWORD(v6)) * i_user_data) >> 17);
  }
}

// File Line: 268
// RVA: 0x1230E0
void __fastcall SSRandom::mthd_normal_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r9
  int i_user_data; // r8d
  unsigned int v5; // edx
  unsigned int v6; // ecx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = ((unsigned int)(1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223) >> 16)
       + ((unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 16);
    v6 = 1664525 * (1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v6;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, i_user_data * (v5 + HIWORD(v6)) / 0x30000);
  }
}

// File Line: 304
// RVA: 0x125E20
void __fastcall SSRandom::mthd_up_slope_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int i_user_data; // r9d
  unsigned int v5; // ecx
  int v6; // eax
  unsigned __int64 v7; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 16;
    v6 = 1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223);
    LODWORD(i_obj_p[2].vfptr) = v6 + 1013904223;
    v7 = (i_user_data * (v5 + ((unsigned int)(v6 + 1013904223) >> 16))) >> 16;
    if ( (unsigned int)v7 >= i_user_data )
      v7 = 2 * i_user_data - (unsigned int)v7 - 1;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v7);
  }
}

// File Line: 340
// RVA: 0x122290
void __fastcall SSRandom::mthd_down_slope_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int i_user_data; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned __int64 v8; // rdx

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 16;
    v6 = 1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v6;
    v7 = (i_user_data * (v5 + HIWORD(v6))) >> 16;
    if ( v7 >= i_user_data )
      v8 = v7 - i_user_data;
    else
      v8 = i_user_data - v7 - 1;
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v8);
  }
}

// File Line: 376
// RVA: 0x125A60
void __fastcall SSRandom::mthd_thorn_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  ARandom *i_obj_p; // rcx
  unsigned int v6; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = (ARandom *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_seed )
      i_obj_p = 0i64;
    v6 = ARandom::thorn(i_obj_p + 8, (*i_array_p)->i_data_p->i_user_data);
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 413
// RVA: 0x1231D0
void __fastcall SSRandom::mthd_nose_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // rax
  ARandom *i_obj_p; // rcx
  unsigned int v6; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = (ARandom *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_seed )
      i_obj_p = 0i64;
    v6 = ARandom::nose(i_obj_p + 8, (*i_array_p)->i_data_p->i_user_data);
    *result_pp = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 447
// RVA: 0x125C80
void __fastcall SSRandom::mthd_uniform(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int v3; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v3 = 1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT(COERCE_FLOAT((v3 >> 9) | 0x3F800000) - 1.0));
  }
}

// File Line: 462
// RVA: 0x109430
void __fastcall SSRandom_mthd_uniform_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **i_array_p; // r8
  SSObjectBase *i_obj_p; // rcx
  SSInstance *i_data_p; // rdx
  SSInstance *v7; // r8
  float v8; // xmm2_4
  float v9; // xmm1_4
  unsigned int v10; // eax

  if ( result_pp )
  {
    i_array_p = scope_p->i_data.i_array_p;
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    i_data_p = i_array_p[1]->i_data_p;
    v7 = (*i_array_p)->i_data_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v8 = *(float *)&i_data_p->i_user_data;
    v9 = *(float *)&v7->i_user_data;
    v10 = 1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v10;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT((float)((float)(v8 - v9) * (float)(COERCE_FLOAT((v10 >> 9) | 0x3F800000) - 1.0)) + v9));
  }
}

// File Line: 498
// RVA: 0x125D60
void __fastcall SSRandom::mthd_uniform_symm(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int v3; // eax

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v3 = 1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT(COERCE_FLOAT((v3 >> 9) | 0x40000000) - 3.0));
  }
}

// File Line: 531
// RVA: 0x125AC0
void __fastcall SSRandom::mthd_triangle(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int v3; // eax
  float v4; // [rsp+40h] [rbp+18h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(v4) = ((unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 9) | 0x3F800000;
    v3 = 1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT((float)((float)(COERCE_FLOAT((v3 >> 9) | 0x3F800000) + v4) - 2.0) * 0.5));
  }
}

// File Line: 564
// RVA: 0x125BE0
void __fastcall SSRandom::mthd_triangle_symm(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int v3; // eax
  float v4; // [rsp+40h] [rbp+18h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    LODWORD(v4) = ((unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 9) | 0x3F800000;
    v3 = 1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT((float)(COERCE_FLOAT((v3 >> 9) | 0x3F800000) + v4) - 3.0));
  }
}

// File Line: 596
// RVA: 0x123020
void __fastcall SSRandom::mthd_normal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int v3; // ecx
  unsigned int v4; // eax
  float v5; // [rsp+40h] [rbp+18h]

  if ( result_pp )
  {
    i_obj_p = scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v3 = 1664525 * (1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(v5) = ((unsigned int)(1664525 * LODWORD(i_obj_p[2].vfptr) + 1013904223) >> 9) | 0x3F800000;
    v4 = 1664525 * v3 + 1013904223;
    LODWORD(i_obj_p[2].vfptr) = v4;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT(
                     (float)((float)((float)(COERCE_FLOAT((v3 >> 9) | 0x3F800000) + v5)
                                   + COERCE_FLOAT((v4 >> 9) | 0x3F800000))
                           - 3.0)
                   * 0.33333334));
  }
}

// File Line: 628
// RVA: 0x125DD0
void __fastcall SSRandom::mthd_up_slope(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ARandom *i_obj_p; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    i_obj_p = (ARandom *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_seed )
      i_obj_p = 0i64;
    user_data = ARandom::up_slope(i_obj_p + 8);
    *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 660
// RVA: 0x122240
void __fastcall SSRandom::mthd_down_slope(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ARandom *i_obj_p; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    i_obj_p = (ARandom *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_seed )
      i_obj_p = 0i64;
    user_data = ARandom::down_slope(i_obj_p + 8);
    *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 692
// RVA: 0x125A10
void __fastcall SSRandom::mthd_thorn(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ARandom *i_obj_p; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    i_obj_p = (ARandom *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_seed )
      i_obj_p = 0i64;
    user_data = ARandom::thorn(i_obj_p + 8);
    *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 725
// RVA: 0x123180
void __fastcall SSRandom::mthd_nose(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  ARandom *i_obj_p; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    i_obj_p = (ARandom *)scope_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p[2].i_seed )
      i_obj_p = 0i64;
    user_data = ARandom::nose(i_obj_p + 8);
    *result_pp = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 739
// RVA: 0x137480
void __fastcall SSRandom::register_atomic(__int64 a1, SSClass **a2, SSClass **i_array_p, __int64 i_uid)
{
  SSClass **v4; // r10
  _BOOL8 v5; // rcx
  SSClass *v6; // r14
  __int64 i_count; // rax
  SSClass **v8; // r10
  _BOOL8 v9; // rcx
  __int64 v10; // rdi
  __int64 v11; // r12
  SSParameters *v12; // rsi
  SSParameters *v13; // r15
  bool v14; // zf
  __int64 v15; // rax
  SSClass **v16; // r10
  _BOOL8 v17; // rcx
  __int64 v18; // rdi
  __int64 v19; // r12
  SSParameters *v20; // rsi
  SSParameters *v21; // r15
  __int64 v22; // rax
  SSClass **v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rdi
  __int64 v26; // r12
  SSParameters *v27; // rsi
  SSParameters *v28; // r15
  __int64 v29; // rax
  SSClass **v30; // r10
  _BOOL8 v31; // rcx
  __int64 v32; // rdi
  __int64 v33; // r12
  SSParameters *v34; // rsi
  SSParameters *v35; // r15
  __int64 v36; // rax
  SSClass **v37; // r10
  _BOOL8 v38; // rcx
  __int64 v39; // rdi
  __int64 v40; // r12
  SSParameters *v41; // rsi
  SSParameters *v42; // r15
  __int64 v43; // rax
  SSClass **v44; // r10
  _BOOL8 v45; // rcx
  __int64 v46; // rdi
  __int64 v47; // r12
  SSParameters *v48; // rsi
  SSParameters *v49; // r15
  __int64 v50; // rax
  SSClass **v51; // r10
  _BOOL8 v52; // rcx
  __int64 v53; // rdi
  __int64 v54; // r12
  SSParameters *v55; // rsi
  SSParameters *v56; // r15
  __int64 v57; // rax
  SSClass **v58; // r10
  _BOOL8 v59; // rcx
  __int64 v60; // rdi
  __int64 v61; // r12
  SSParameters *v62; // rsi
  SSParameters *v63; // r15
  __int64 v64; // rax
  SSClass **v65; // r10
  _BOOL8 v66; // rcx
  __int64 v67; // rdi
  __int64 v68; // r12
  SSParameters *v69; // rsi
  SSParameters *v70; // r15
  __int64 v71; // rax
  SSClass **v72; // r10
  _BOOL8 v73; // rcx
  __int64 v74; // rdi
  __int64 v75; // r12
  SSParameters *v76; // rsi
  SSParameters *v77; // r15
  __int64 v78; // rax
  SSClass **v79; // r10
  _BOOL8 v80; // rcx
  __int64 v81; // rdi
  __int64 v82; // r12
  SSParameters *v83; // rsi
  SSParameters *v84; // r15
  ASymbol *v85; // rax
  __int64 result; // [rsp+70h] [rbp+40h] BYREF
  SSParameters *v87; // [rsp+78h] [rbp+48h]
  __int64 v88; // [rsp+80h] [rbp+50h]

  if ( SSBrain::c_classes.i_count )
  {
    i_array_p = SSBrain::c_classes.i_array_p;
    v4 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v4 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_Random.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_10;
        v4 = a2 - 1;
      }
      v5 = ASymbol_Random.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_Random.i_uid != (_DWORD)i_uid;
      if ( v5 )
        break;
      if ( v4 == a2 )
        goto LABEL_10;
      i_array_p = a2 + 1;
    }
    v6 = *a2;
  }
  else
  {
LABEL_10:
    v6 = 0i64;
  }
  i_count = v6->i_methods.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v8 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v8 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_ctor.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_20;
        v8 = a2 - 1;
      }
      v9 = ASymbolX_ctor.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_ctor.i_uid != (_DWORD)i_uid;
      if ( v9 )
        break;
      if ( v8 == a2 )
        goto LABEL_20;
      i_array_p = a2 + 1;
    }
    v10 = (__int64)*a2;
  }
  else
  {
LABEL_20:
    v10 = 0i64;
  }
  result = v10;
  if ( v10 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64, __int64))(*(_QWORD *)v10 + 16i64))(
           v10,
           a2,
           i_array_p,
           i_uid,
           -2i64) == 1 )
    {
      *(_QWORD *)(v10 + 32) = SSRandom::mthd_constructor;
    }
    else
    {
      v11 = *(_QWORD *)(v10 + 16);
      v12 = *(SSParameters **)(v10 + 24);
      v87 = v12;
      if ( v12 )
        ++v12->i_ref_count;
      v13 = *(SSParameters **)(v10 + 24);
      if ( v13 )
      {
        v14 = v13->i_ref_count-- == 1;
        if ( v14 )
        {
          v13->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v13);
          AMemory::c_free_func(v13);
        }
        *(_QWORD *)(v10 + 24) = 0i64;
      }
      v88 = v10;
      *(ASymbol *)(v10 + 8) = ASymbolX_ctor;
      *(_QWORD *)(v10 + 16) = v11;
      *(_QWORD *)v10 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v10 + 24) = v12;
      if ( v12 )
        ++v12->i_ref_count;
      *(_QWORD *)v10 = &SSMethodBase::`vftable;
      *(_QWORD *)v10 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v10 + 32) = SSRandom::mthd_constructor;
      if ( v12 )
      {
        v14 = v12->i_ref_count-- == 1;
        if ( v14 )
        {
          v12->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v12);
          AMemory::c_free_func(v12);
        }
      }
    }
  }
  v15 = v6->i_methods.i_count;
  if ( (_DWORD)v15 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v16 = &i_array_p[v15 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v16 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbolX_ctor_seed.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_44;
        v16 = a2 - 1;
      }
      v17 = ASymbolX_ctor_seed.i_uid == (_DWORD)i_uid;
      i_uid = ASymbolX_ctor_seed.i_uid != (_DWORD)i_uid;
      if ( v17 )
        break;
      if ( v16 == a2 )
        goto LABEL_44;
      i_array_p = a2 + 1;
    }
    v18 = (__int64)*a2;
  }
  else
  {
LABEL_44:
    v18 = 0i64;
  }
  result = v18;
  if ( v18 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v18 + 16i64))(
           v18,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v18 + 32) = SSRandom::mthd_ctor_seed;
    }
    else
    {
      v19 = *(_QWORD *)(v18 + 16);
      v20 = *(SSParameters **)(v18 + 24);
      v87 = v20;
      if ( v20 )
        ++v20->i_ref_count;
      v21 = *(SSParameters **)(v18 + 24);
      if ( v21 )
      {
        v14 = v21->i_ref_count-- == 1;
        if ( v14 )
        {
          v21->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v21);
          AMemory::c_free_func(v21);
        }
        *(_QWORD *)(v18 + 24) = 0i64;
      }
      v88 = v18;
      *(ASymbol *)(v18 + 8) = ASymbolX_ctor_seed;
      *(_QWORD *)(v18 + 16) = v19;
      *(_QWORD *)v18 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v18 + 24) = v20;
      if ( v20 )
        ++v20->i_ref_count;
      *(_QWORD *)v18 = &SSMethodBase::`vftable;
      *(_QWORD *)v18 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v18 + 32) = SSRandom::mthd_ctor_seed;
      if ( v20 )
      {
        v14 = v20->i_ref_count-- == 1;
        if ( v14 )
        {
          v20->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
      }
    }
  }
  v22 = v6->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v23 = &i_array_p[v22 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v23 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_get_seed.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_68;
        v23 = a2 - 1;
      }
      v24 = ASymbol_get_seed.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_get_seed.i_uid != (_DWORD)i_uid;
      if ( v24 )
        break;
      if ( v23 == a2 )
        goto LABEL_68;
      i_array_p = a2 + 1;
    }
    v25 = (__int64)*a2;
  }
  else
  {
LABEL_68:
    v25 = 0i64;
  }
  result = v25;
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSInteger::mthd_as_copy;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v87 = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v28 = *(SSParameters **)(v25 + 24);
      if ( v28 )
      {
        v14 = v28->i_ref_count-- == 1;
        if ( v14 )
        {
          v28->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        *(_QWORD *)(v25 + 24) = 0i64;
      }
      v88 = v25;
      *(ASymbol *)(v25 + 8) = ASymbol_get_seed;
      *(_QWORD *)(v25 + 16) = v26;
      *(_QWORD *)v25 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v25 + 24) = v27;
      if ( v27 )
        ++v27->i_ref_count;
      *(_QWORD *)v25 = &SSMethodBase::`vftable;
      *(_QWORD *)v25 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v25 + 32) = SSInteger::mthd_as_copy;
      if ( v27 )
      {
        v14 = v27->i_ref_count-- == 1;
        if ( v14 )
        {
          v27->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v27);
          AMemory::c_free_func(v27);
        }
      }
    }
  }
  v29 = v6->i_methods.i_count;
  if ( (_DWORD)v29 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v30 = &i_array_p[v29 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v30 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_set_seed.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_92;
        v30 = a2 - 1;
      }
      v31 = ASymbol_set_seed.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_set_seed.i_uid != (_DWORD)i_uid;
      if ( v31 )
        break;
      if ( v30 == a2 )
        goto LABEL_92;
      i_array_p = a2 + 1;
    }
    v32 = (__int64)*a2;
  }
  else
  {
LABEL_92:
    v32 = 0i64;
  }
  result = v32;
  if ( v32 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v32 + 16i64))(
           v32,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v32 + 32) = SSReal::mthd_ctor_copy;
    }
    else
    {
      v33 = *(_QWORD *)(v32 + 16);
      v34 = *(SSParameters **)(v32 + 24);
      v87 = v34;
      if ( v34 )
        ++v34->i_ref_count;
      v35 = *(SSParameters **)(v32 + 24);
      if ( v35 )
      {
        v14 = v35->i_ref_count-- == 1;
        if ( v14 )
        {
          v35->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v35);
          AMemory::c_free_func(v35);
        }
        *(_QWORD *)(v32 + 24) = 0i64;
      }
      v88 = v32;
      *(ASymbol *)(v32 + 8) = ASymbol_set_seed;
      *(_QWORD *)(v32 + 16) = v33;
      *(_QWORD *)v32 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v32 + 24) = v34;
      if ( v34 )
        ++v34->i_ref_count;
      *(_QWORD *)v32 = &SSMethodBase::`vftable;
      *(_QWORD *)v32 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v32 + 32) = SSReal::mthd_ctor_copy;
      if ( v34 )
      {
        v14 = v34->i_ref_count-- == 1;
        if ( v14 )
        {
          v34->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v34);
          AMemory::c_free_func(v34);
        }
      }
    }
  }
  v36 = v6->i_methods.i_count;
  if ( (_DWORD)v36 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v37 = &i_array_p[v36 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v37 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_coin_toss.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_116;
        v37 = a2 - 1;
      }
      v38 = ASymbol_coin_toss.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_coin_toss.i_uid != (_DWORD)i_uid;
      if ( v38 )
        break;
      if ( v37 == a2 )
        goto LABEL_116;
      i_array_p = a2 + 1;
    }
    v39 = (__int64)*a2;
  }
  else
  {
LABEL_116:
    v39 = 0i64;
  }
  result = v39;
  if ( v39 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v39 + 16i64))(
           v39,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v39 + 32) = SSRandom::mthd_coin_toss;
    }
    else
    {
      v40 = *(_QWORD *)(v39 + 16);
      v41 = *(SSParameters **)(v39 + 24);
      v87 = v41;
      if ( v41 )
        ++v41->i_ref_count;
      v42 = *(SSParameters **)(v39 + 24);
      if ( v42 )
      {
        v14 = v42->i_ref_count-- == 1;
        if ( v14 )
        {
          v42->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v42);
          AMemory::c_free_func(v42);
        }
        *(_QWORD *)(v39 + 24) = 0i64;
      }
      v88 = v39;
      *(ASymbol *)(v39 + 8) = ASymbol_coin_toss;
      *(_QWORD *)(v39 + 16) = v40;
      *(_QWORD *)v39 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v39 + 24) = v41;
      if ( v41 )
        ++v41->i_ref_count;
      *(_QWORD *)v39 = &SSMethodBase::`vftable;
      *(_QWORD *)v39 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v39 + 32) = SSRandom::mthd_coin_toss;
      if ( v41 )
      {
        v14 = v41->i_ref_count-- == 1;
        if ( v14 )
        {
          v41->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v41);
          AMemory::c_free_func(v41);
        }
      }
    }
  }
  v43 = v6->i_methods.i_count;
  if ( (_DWORD)v43 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v44 = &i_array_p[v43 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v44 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_uniform_int.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_140;
        v44 = a2 - 1;
      }
      v45 = ASymbol_uniform_int.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_uniform_int.i_uid != (_DWORD)i_uid;
      if ( v45 )
        break;
      if ( v44 == a2 )
        goto LABEL_140;
      i_array_p = a2 + 1;
    }
    v46 = (__int64)*a2;
  }
  else
  {
LABEL_140:
    v46 = 0i64;
  }
  result = v46;
  if ( v46 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v46 + 16i64))(
           v46,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v46 + 32) = SSRandom::mthd_uniform_int;
    }
    else
    {
      v47 = *(_QWORD *)(v46 + 16);
      v48 = *(SSParameters **)(v46 + 24);
      v87 = v48;
      if ( v48 )
        ++v48->i_ref_count;
      v49 = *(SSParameters **)(v46 + 24);
      if ( v49 )
      {
        v14 = v49->i_ref_count-- == 1;
        if ( v14 )
        {
          v49->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v49);
          AMemory::c_free_func(v49);
        }
        *(_QWORD *)(v46 + 24) = 0i64;
      }
      v88 = v46;
      *(ASymbol *)(v46 + 8) = ASymbol_uniform_int;
      *(_QWORD *)(v46 + 16) = v47;
      *(_QWORD *)v46 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v46 + 24) = v48;
      if ( v48 )
        ++v48->i_ref_count;
      *(_QWORD *)v46 = &SSMethodBase::`vftable;
      *(_QWORD *)v46 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v46 + 32) = SSRandom::mthd_uniform_int;
      if ( v48 )
      {
        v14 = v48->i_ref_count-- == 1;
        if ( v14 )
        {
          v48->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v48);
          AMemory::c_free_func(v48);
        }
      }
    }
  }
  v50 = v6->i_methods.i_count;
  if ( (_DWORD)v50 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v51 = &i_array_p[v50 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v51 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_triangle_int.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_164;
        v51 = a2 - 1;
      }
      v52 = ASymbol_triangle_int.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_triangle_int.i_uid != (_DWORD)i_uid;
      if ( v52 )
        break;
      if ( v51 == a2 )
        goto LABEL_164;
      i_array_p = a2 + 1;
    }
    v53 = (__int64)*a2;
  }
  else
  {
LABEL_164:
    v53 = 0i64;
  }
  result = v53;
  if ( v53 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v53 + 16i64))(
           v53,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v53 + 32) = SSRandom::mthd_triangle_int;
    }
    else
    {
      v54 = *(_QWORD *)(v53 + 16);
      v55 = *(SSParameters **)(v53 + 24);
      v87 = v55;
      if ( v55 )
        ++v55->i_ref_count;
      v56 = *(SSParameters **)(v53 + 24);
      if ( v56 )
      {
        v14 = v56->i_ref_count-- == 1;
        if ( v14 )
        {
          v56->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v56);
          AMemory::c_free_func(v56);
        }
        *(_QWORD *)(v53 + 24) = 0i64;
      }
      v88 = v53;
      *(ASymbol *)(v53 + 8) = ASymbol_triangle_int;
      *(_QWORD *)(v53 + 16) = v54;
      *(_QWORD *)v53 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v53 + 24) = v55;
      if ( v55 )
        ++v55->i_ref_count;
      *(_QWORD *)v53 = &SSMethodBase::`vftable;
      *(_QWORD *)v53 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v53 + 32) = SSRandom::mthd_triangle_int;
      if ( v55 )
      {
        v14 = v55->i_ref_count-- == 1;
        if ( v14 )
        {
          v55->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v55);
          AMemory::c_free_func(v55);
        }
      }
    }
  }
  v57 = v6->i_methods.i_count;
  if ( (_DWORD)v57 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v58 = &i_array_p[v57 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v58 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_normal_int.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_188;
        v58 = a2 - 1;
      }
      v59 = ASymbol_normal_int.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_normal_int.i_uid != (_DWORD)i_uid;
      if ( v59 )
        break;
      if ( v58 == a2 )
        goto LABEL_188;
      i_array_p = a2 + 1;
    }
    v60 = (__int64)*a2;
  }
  else
  {
LABEL_188:
    v60 = 0i64;
  }
  result = v60;
  if ( v60 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v60 + 16i64))(
           v60,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v60 + 32) = SSRandom::mthd_normal_int;
    }
    else
    {
      v61 = *(_QWORD *)(v60 + 16);
      v62 = *(SSParameters **)(v60 + 24);
      v87 = v62;
      if ( v62 )
        ++v62->i_ref_count;
      v63 = *(SSParameters **)(v60 + 24);
      if ( v63 )
      {
        v14 = v63->i_ref_count-- == 1;
        if ( v14 )
        {
          v63->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v63);
          AMemory::c_free_func(v63);
        }
        *(_QWORD *)(v60 + 24) = 0i64;
      }
      v88 = v60;
      *(ASymbol *)(v60 + 8) = ASymbol_normal_int;
      *(_QWORD *)(v60 + 16) = v61;
      *(_QWORD *)v60 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v60 + 24) = v62;
      if ( v62 )
        ++v62->i_ref_count;
      *(_QWORD *)v60 = &SSMethodBase::`vftable;
      *(_QWORD *)v60 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v60 + 32) = SSRandom::mthd_normal_int;
      if ( v62 )
      {
        v14 = v62->i_ref_count-- == 1;
        if ( v14 )
        {
          v62->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v62);
          AMemory::c_free_func(v62);
        }
      }
    }
  }
  v64 = v6->i_methods.i_count;
  if ( (_DWORD)v64 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v65 = &i_array_p[v64 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v65 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_up_slope_int.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_212;
        v65 = a2 - 1;
      }
      v66 = ASymbol_up_slope_int.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_up_slope_int.i_uid != (_DWORD)i_uid;
      if ( v66 )
        break;
      if ( v65 == a2 )
        goto LABEL_212;
      i_array_p = a2 + 1;
    }
    v67 = (__int64)*a2;
  }
  else
  {
LABEL_212:
    v67 = 0i64;
  }
  result = v67;
  if ( v67 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v67 + 16i64))(
           v67,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v67 + 32) = SSRandom::mthd_up_slope_int;
    }
    else
    {
      v68 = *(_QWORD *)(v67 + 16);
      v69 = *(SSParameters **)(v67 + 24);
      v87 = v69;
      if ( v69 )
        ++v69->i_ref_count;
      v70 = *(SSParameters **)(v67 + 24);
      if ( v70 )
      {
        v14 = v70->i_ref_count-- == 1;
        if ( v14 )
        {
          v70->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v70);
          AMemory::c_free_func(v70);
        }
        *(_QWORD *)(v67 + 24) = 0i64;
      }
      v88 = v67;
      *(ASymbol *)(v67 + 8) = ASymbol_up_slope_int;
      *(_QWORD *)(v67 + 16) = v68;
      *(_QWORD *)v67 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v67 + 24) = v69;
      if ( v69 )
        ++v69->i_ref_count;
      *(_QWORD *)v67 = &SSMethodBase::`vftable;
      *(_QWORD *)v67 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v67 + 32) = SSRandom::mthd_up_slope_int;
      if ( v69 )
      {
        v14 = v69->i_ref_count-- == 1;
        if ( v14 )
        {
          v69->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v69);
          AMemory::c_free_func(v69);
        }
      }
    }
  }
  v71 = v6->i_methods.i_count;
  if ( (_DWORD)v71 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v72 = &i_array_p[v71 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v72 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_down_slope_int.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_236;
        v72 = a2 - 1;
      }
      v73 = ASymbol_down_slope_int.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_down_slope_int.i_uid != (_DWORD)i_uid;
      if ( v73 )
        break;
      if ( v72 == a2 )
        goto LABEL_236;
      i_array_p = a2 + 1;
    }
    v74 = (__int64)*a2;
  }
  else
  {
LABEL_236:
    v74 = 0i64;
  }
  result = v74;
  if ( v74 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v74 + 16i64))(
           v74,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v74 + 32) = SSRandom::mthd_down_slope_int;
    }
    else
    {
      v75 = *(_QWORD *)(v74 + 16);
      v76 = *(SSParameters **)(v74 + 24);
      v87 = v76;
      if ( v76 )
        ++v76->i_ref_count;
      v77 = *(SSParameters **)(v74 + 24);
      if ( v77 )
      {
        v14 = v77->i_ref_count-- == 1;
        if ( v14 )
        {
          v77->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v77);
          AMemory::c_free_func(v77);
        }
        *(_QWORD *)(v74 + 24) = 0i64;
      }
      v88 = v74;
      *(ASymbol *)(v74 + 8) = ASymbol_down_slope_int;
      *(_QWORD *)(v74 + 16) = v75;
      *(_QWORD *)v74 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v74 + 24) = v76;
      if ( v76 )
        ++v76->i_ref_count;
      *(_QWORD *)v74 = &SSMethodBase::`vftable;
      *(_QWORD *)v74 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v74 + 32) = SSRandom::mthd_down_slope_int;
      if ( v76 )
      {
        v14 = v76->i_ref_count-- == 1;
        if ( v14 )
        {
          v76->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v76);
          AMemory::c_free_func(v76);
        }
      }
    }
  }
  v78 = v6->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    i_array_p = (SSClass **)v6->i_methods.i_array_p;
    v79 = &i_array_p[v78 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        a2 = &i_array_p[((char *)v79 - (char *)i_array_p) >> 4];
        i_uid = (*a2)->i_name.i_uid;
        if ( ASymbol_thorn_int.i_uid >= (unsigned int)i_uid )
          break;
        if ( i_array_p == a2 )
          goto LABEL_260;
        v79 = a2 - 1;
      }
      v80 = ASymbol_thorn_int.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_thorn_int.i_uid != (_DWORD)i_uid;
      if ( v80 )
        break;
      if ( v79 == a2 )
        goto LABEL_260;
      i_array_p = a2 + 1;
    }
    v81 = (__int64)*a2;
  }
  else
  {
LABEL_260:
    v81 = 0i64;
  }
  result = v81;
  if ( v81 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, SSClass **, SSClass **, __int64))(*(_QWORD *)v81 + 16i64))(
           v81,
           a2,
           i_array_p,
           i_uid) == 1 )
    {
      *(_QWORD *)(v81 + 32) = SSRandom::mthd_thorn_int;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v87 = v83;
      if ( v83 )
        ++v83->i_ref_count;
      v84 = *(SSParameters **)(v81 + 24);
      if ( v84 )
      {
        v14 = v84->i_ref_count-- == 1;
        if ( v14 )
        {
          v84->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v84);
          AMemory::c_free_func(v84);
        }
        *(_QWORD *)(v81 + 24) = 0i64;
      }
      v88 = v81;
      *(ASymbol *)(v81 + 8) = ASymbol_thorn_int;
      *(_QWORD *)(v81 + 16) = v82;
      *(_QWORD *)v81 = &SSInvokableBase::`vftable;
      *(_QWORD *)(v81 + 24) = v83;
      if ( v83 )
        ++v83->i_ref_count;
      *(_QWORD *)v81 = &SSMethodBase::`vftable;
      *(_QWORD *)v81 = &SSMethodFunc::`vftable;
      *(_QWORD *)(v81 + 32) = SSRandom::mthd_thorn_int;
      if ( v83 )
      {
        v14 = v83->i_ref_count-- == 1;
        if ( v14 )
        {
          v83->i_ref_count = 0x80000000;
          SSParameters::~SSParameters(v83);
          AMemory::c_free_func(v83);
        }
      }
    }
  }
  SSClass::register_method_func(v6, &ASymbol_nose_int, SSRandom::mthd_nose_int, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_uniform, SSRandom::mthd_uniform, SSBindFlag_instance_no_rebind);
  v85 = ASymbol::create((ASymbol *)&result, "uniform_range", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v6, v85, SSRandom_mthd_uniform_range, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_uniform_symm, SSRandom::mthd_uniform_symm, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_triangle, SSRandom::mthd_triangle, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_triangle_symm, SSRandom::mthd_triangle_symm, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_normal, SSRandom::mthd_normal, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_up_slope, SSRandom::mthd_up_slope, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_down_slope, SSRandom::mthd_down_slope, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_thorn, SSRandom::mthd_thorn, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_nose, SSRandom::mthd_nose, SSBindFlag_instance_no_rebind);
} "uniform_range", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v6, v85, SSRandom_mthd_uniform_range, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_uniform_symm, SSRandom::mthd_uniform_symm, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_triangle, SSRandom::mthd_triangle, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_triangle_symm, SSRandom::mthd_triangle_symm, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_normal, SSRandom::mthd_normal, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_up_slope, SSRandom::mthd_up_slope, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_down_slope, SSRandom::mthd_down_slope, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v6, &ASymbol_thorn, SS

