// File Line: 58
// RVA: 0x121C90
void __fastcall SSRandom::mthd_constructor(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // rbx
  int v3; // eax
  SSObjectBase *v4; // rdx
  unsigned int v5; // er8

  v2 = scope_p;
  v3 = time64(0i64);
  v4 = v2->i_scope_p.i_obj_p;
  v5 = 1664525 * v3 + 1013904223;
  if ( v4 && v2->i_scope_p.i_ptr_id == v4->i_ptr_id )
    v4[2].vfptr = (SSObjectBaseVtbl *)v5;
  else
    *(_QWORD *)&MEMORY[0x20] = v5;
}

// File Line: 86
// RVA: 0x122010
void __fastcall SSRandom::mthd_ctor_seed(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // rdx

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v2[2].vfptr = (SSObjectBaseVtbl *)LODWORD((*scope_p->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 157
// RVA: 0x121BB0
void __fastcall SSRandom::mthd_coin_toss(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  int v3; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = 1664525 * LODWORD(v2[2].vfptr);
    LODWORD(v2[2].vfptr) = v3 + 1013904223;
    *result_pp = (SSInstance *)SSBoolean::pool_new(v3 + 1013904223 < 0);
  }
}

// File Line: 195
// RVA: 0x125CF0
void __fastcall SSRandom::mthd_uniform_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  int v4; // edx
  unsigned int v5; // eax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = 1664525 * LODWORD(v3[2].vfptr) + 1013904223;
    LODWORD(v3[2].vfptr) = v5;
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, (v5 >> 16) * v4 >> 16);
  }
}

// File Line: 232
// RVA: 0x125B60
void __fastcall SSRandom::mthd_triangle_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (unsigned int)(1664525 * LODWORD(v3[2].vfptr) + 1013904223) >> 16;
    v6 = 1664525 * (1664525 * LODWORD(v3[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(v3[2].vfptr) = v6;
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, (v5 + (v6 >> 16)) * v4 >> 17);
  }
}

// File Line: 268
// RVA: 0x1230E0
void __fastcall SSRandom::mthd_normal_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r9
  SSInstance **v3; // rbx
  int v4; // er8
  unsigned int v5; // edx
  unsigned int v6; // ecx

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    v3 = result_pp;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = ((unsigned int)(1664525 * (1664525 * LODWORD(v2[2].vfptr) + 1013904223) + 1013904223) >> 16)
       + ((unsigned int)(1664525 * LODWORD(v2[2].vfptr) + 1013904223) >> 16);
    v6 = 1664525 * (1664525 * (1664525 * LODWORD(v2[2].vfptr) + 1013904223) + 1013904223) + 1013904223;
    LODWORD(v2[2].vfptr) = v6;
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4 * (v5 + (v6 >> 16)) / 0x30000);
  }
}

// File Line: 304
// RVA: 0x125E20
void __fastcall SSRandom::mthd_up_slope_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  unsigned int v4; // er9
  unsigned int v5; // ecx
  int v6; // eax
  unsigned __int64 v7; // rdx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (unsigned int)(1664525 * LODWORD(v3[2].vfptr) + 1013904223) >> 16;
    v6 = 1664525 * (1664525 * LODWORD(v3[2].vfptr) + 1013904223);
    LODWORD(v3[2].vfptr) = v6 + 1013904223;
    v7 = v4 * (v5 + ((unsigned int)(v6 + 1013904223) >> 16)) >> 16;
    if ( (unsigned int)v7 >= v4 )
      v7 = 2 * v4 - (unsigned int)v7 - 1;
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v7);
  }
}

// File Line: 340
// RVA: 0x122290
void __fastcall SSRandom::mthd_down_slope_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned __int64 v8; // rdx

  if ( result_pp )
  {
    v2 = result_pp;
    v3 = scope_p->i_scope_p.i_obj_p;
    if ( !v3 || scope_p->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (*scope_p->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (unsigned int)(1664525 * LODWORD(v3[2].vfptr) + 1013904223) >> 16;
    v6 = 1664525 * (1664525 * LODWORD(v3[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(v3[2].vfptr) = v6;
    v7 = v4 * (v5 + (v6 >> 16)) >> 16;
    if ( v7 >= v4 )
      v8 = v7 - v4;
    else
      v8 = v4 - v7 - 1;
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v8);
  }
}

// File Line: 376
// RVA: 0x125A60
void __fastcall SSRandom::mthd_thorn_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  ARandom *v4; // rcx
  SSInstance **v5; // rbx
  unsigned int v6; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = scope_p;
    v4 = (ARandom *)scope_p->i_scope_p.i_obj_p;
    v5 = result_pp;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4[2].i_seed )
      v4 = 0i64;
    v6 = ARandom::thorn(v4 + 8, (*v2)->i_data_p->i_user_data);
    *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 413
// RVA: 0x1231D0
void __fastcall SSRandom::mthd_nose_int(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  ARandom *v4; // rcx
  SSInstance **v5; // rbx
  unsigned int v6; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = scope_p;
    v4 = (ARandom *)scope_p->i_scope_p.i_obj_p;
    v5 = result_pp;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4[2].i_seed )
      v4 = 0i64;
    v6 = ARandom::nose(v4 + 8, (*v2)->i_data_p->i_user_data);
    *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
  }
}

// File Line: 447
// RVA: 0x125C80
void __fastcall SSRandom::mthd_uniform(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = 1664525 * LODWORD(v2[2].vfptr) + 1013904223;
    LODWORD(v2[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT(COERCE_FLOAT((v3 >> 9) | 0x3F800000) - 1.0));
  }
}

// File Line: 462
// RVA: 0x109430
void __fastcall SSRandom_mthd_uniform_range(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // r9
  SSObjectBase *v5; // rcx
  SSInstance *v6; // rdx
  SSInstance *v7; // r8
  float v8; // xmm2_4
  float v9; // xmm1_4
  unsigned int v10; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_data.i_array_p;
    v3 = result_pp;
    v4 = scope_p;
    v5 = scope_p->i_scope_p.i_obj_p;
    v6 = v2[1]->i_data_p;
    v7 = (*v2)->i_data_p;
    if ( !v5 || v4->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v8 = *(float *)&v6->i_user_data;
    v9 = *(float *)&v7->i_user_data;
    v10 = 1664525 * LODWORD(v5[2].vfptr) + 1013904223;
    LODWORD(v5[2].vfptr) = v10;
    *v3 = SSInstance::pool_new(
            SSBrain::c_real_class_p,
            COERCE_UNSIGNED_INT((float)((float)(v8 - v9) * (float)(COERCE_FLOAT((v10 >> 9) | 0x3F800000) - 1.0)) + v9));
  }
}

// File Line: 498
// RVA: 0x125D60
void __fastcall SSRandom::mthd_uniform_symm(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // eax

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = 1664525 * LODWORD(v2[2].vfptr) + 1013904223;
    LODWORD(v2[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT(COERCE_FLOAT((v3 >> 9) | 0x40000000) - 3.0));
  }
}

// File Line: 531
// RVA: 0x125AC0
void __fastcall SSRandom::mthd_triangle(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // eax
  float v4; // [rsp+40h] [rbp+18h]

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    LODWORD(v4) = ((unsigned int)(1664525 * LODWORD(v2[2].vfptr) + 1013904223) >> 9) | 0x3F800000;
    v3 = 1664525 * (1664525 * LODWORD(v2[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(v2[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT((float)((float)(COERCE_FLOAT((v3 >> 9) | 0x3F800000) + v4) - 2.0) * 0.5));
  }
}

// File Line: 564
// RVA: 0x125BE0
void __fastcall SSRandom::mthd_triangle_symm(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // eax
  float v4; // [rsp+40h] [rbp+18h]

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    LODWORD(v4) = ((unsigned int)(1664525 * LODWORD(v2[2].vfptr) + 1013904223) >> 9) | 0x3F800000;
    v3 = 1664525 * (1664525 * LODWORD(v2[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(v2[2].vfptr) = v3;
    *result_pp = SSInstance::pool_new(
                   SSBrain::c_real_class_p,
                   COERCE_UNSIGNED_INT((float)(COERCE_FLOAT((v3 >> 9) | 0x3F800000) + v4) - 3.0));
  }
}

// File Line: 596
// RVA: 0x123020
void __fastcall SSRandom::mthd_normal(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // ecx
  unsigned int v4; // eax
  float v5; // [rsp+40h] [rbp+18h]

  if ( result_pp )
  {
    v2 = scope_p->i_scope_p.i_obj_p;
    if ( !v2 || scope_p->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = 1664525 * (1664525 * LODWORD(v2[2].vfptr) + 1013904223) + 1013904223;
    LODWORD(v5) = ((unsigned int)(1664525 * LODWORD(v2[2].vfptr) + 1013904223) >> 9) | 0x3F800000;
    v4 = 1664525 * v3 + 1013904223;
    LODWORD(v2[2].vfptr) = v4;
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
  SSInvokedMethod *v2; // r8
  ARandom *v3; // rcx
  SSInstance **v4; // rbx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = (ARandom *)scope_p->i_scope_p.i_obj_p;
    v4 = result_pp;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3[2].i_seed )
      v3 = 0i64;
    user_data = ARandom::up_slope(v3 + 8);
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 660
// RVA: 0x122240
void __fastcall SSRandom::mthd_down_slope(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // r8
  ARandom *v3; // rcx
  SSInstance **v4; // rbx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = (ARandom *)scope_p->i_scope_p.i_obj_p;
    v4 = result_pp;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3[2].i_seed )
      v3 = 0i64;
    user_data = ARandom::down_slope(v3 + 8);
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 692
// RVA: 0x125A10
void __fastcall SSRandom::mthd_thorn(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // r8
  ARandom *v3; // rcx
  SSInstance **v4; // rbx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = (ARandom *)scope_p->i_scope_p.i_obj_p;
    v4 = result_pp;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3[2].i_seed )
      v3 = 0i64;
    user_data = ARandom::thorn(v3 + 8);
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 725
// RVA: 0x123180
void __fastcall SSRandom::mthd_nose(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  SSInvokedMethod *v2; // r8
  ARandom *v3; // rcx
  SSInstance **v4; // rbx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( result_pp )
  {
    v2 = scope_p;
    v3 = (ARandom *)scope_p->i_scope_p.i_obj_p;
    v4 = result_pp;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3[2].i_seed )
      v3 = 0i64;
    user_data = ARandom::nose(v3 + 8);
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 739
// RVA: 0x137480
void __fastcall SSRandom::register_atomic(__int64 a1, signed __int64 a2, SSClass **a3, __int64 a4)
{
  SSClass **v4; // r10
  _BOOL8 v5; // rcx
  SSClass *v6; // r14
  __int64 v7; // rax
  signed __int64 v8; // r10
  _BOOL8 v9; // rcx
  __int64 v10; // rdi
  __int64 v11; // r12
  SSParameters *v12; // rsi
  SSParameters *v13; // r15
  bool v14; // zf
  __int64 v15; // rax
  signed __int64 v16; // r10
  _BOOL8 v17; // rcx
  __int64 v18; // rdi
  __int64 v19; // r12
  SSParameters *v20; // rsi
  SSParameters *v21; // r15
  __int64 v22; // rax
  signed __int64 v23; // r10
  _BOOL8 v24; // rcx
  __int64 v25; // rdi
  __int64 v26; // r12
  SSParameters *v27; // rsi
  SSParameters *v28; // r15
  __int64 v29; // rax
  signed __int64 v30; // r10
  _BOOL8 v31; // rcx
  __int64 v32; // rdi
  __int64 v33; // r12
  SSParameters *v34; // rsi
  SSParameters *v35; // r15
  __int64 v36; // rax
  signed __int64 v37; // r10
  _BOOL8 v38; // rcx
  __int64 v39; // rdi
  __int64 v40; // r12
  SSParameters *v41; // rsi
  SSParameters *v42; // r15
  __int64 v43; // rax
  signed __int64 v44; // r10
  _BOOL8 v45; // rcx
  __int64 v46; // rdi
  __int64 v47; // r12
  SSParameters *v48; // rsi
  SSParameters *v49; // r15
  __int64 v50; // rax
  signed __int64 v51; // r10
  _BOOL8 v52; // rcx
  __int64 v53; // rdi
  __int64 v54; // r12
  SSParameters *v55; // rsi
  SSParameters *v56; // r15
  __int64 v57; // rax
  signed __int64 v58; // r10
  _BOOL8 v59; // rcx
  __int64 v60; // rdi
  __int64 v61; // r12
  SSParameters *v62; // rsi
  SSParameters *v63; // r15
  __int64 v64; // rax
  signed __int64 v65; // r10
  _BOOL8 v66; // rcx
  __int64 v67; // rdi
  __int64 v68; // r12
  SSParameters *v69; // rsi
  SSParameters *v70; // r15
  __int64 v71; // rax
  signed __int64 v72; // r10
  _BOOL8 v73; // rcx
  __int64 v74; // rdi
  __int64 v75; // r12
  SSParameters *v76; // rsi
  SSParameters *v77; // r15
  __int64 v78; // rax
  signed __int64 v79; // r10
  _BOOL8 v80; // rcx
  __int64 v81; // rdi
  __int64 v82; // r12
  SSParameters *v83; // rsi
  SSParameters *v84; // r15
  ASymbol *v85; // rax
  signed __int64 v86; // [rsp+20h] [rbp-10h]
  __int64 result; // [rsp+70h] [rbp+40h]
  SSParameters *v88; // [rsp+78h] [rbp+48h]
  __int64 v89; // [rsp+80h] [rbp+50h]

  v86 = -2i64;
  if ( SSBrain::c_classes.i_count )
  {
    a3 = SSBrain::c_classes.i_array_p;
    v4 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[((char *)v4 - (char *)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_Random.i_uid < (unsigned int)a4 )
        goto LABEL_290;
      v5 = ASymbol_Random.i_uid == (_DWORD)a4;
      a4 = ASymbol_Random.i_uid != (_DWORD)a4;
      if ( v5 == 1 )
      {
        v6 = *(SSClass **)a2;
        goto LABEL_12;
      }
      if ( a4 < 0 )
      {
LABEL_290:
        if ( a3 == (SSClass **)a2 )
          break;
        v4 = (SSClass **)(a2 - 8);
      }
      else
      {
        if ( v4 == (SSClass **)a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v6 = 0i64;
LABEL_12:
  v7 = v6->i_methods.i_count;
  if ( (_DWORD)v7 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v8 = (signed __int64)&a3[v7 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v8 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_ctor.i_uid < (unsigned int)a4 )
        goto LABEL_291;
      v9 = ASymbolX_ctor.i_uid == (_DWORD)a4;
      a4 = ASymbolX_ctor.i_uid != (_DWORD)a4;
      if ( v9 == 1 )
      {
        v10 = *(_QWORD *)a2;
        goto LABEL_23;
      }
      if ( a4 < 0 )
      {
LABEL_291:
        if ( a3 == (SSClass **)a2 )
          break;
        v8 = a2 - 8;
      }
      else
      {
        if ( v8 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v10 = 0i64;
LABEL_23:
  result = v10;
  if ( v10 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v10 + 16i64))(
           v10,
           a2,
           a3,
           a4,
           -2i64) == 1 )
    {
      *(_QWORD *)(v10 + 32) = SSRandom::mthd_constructor;
    }
    else
    {
      v11 = *(_QWORD *)(v10 + 16);
      v12 = *(SSParameters **)(v10 + 24);
      v88 = v12;
      if ( v12 )
        ++v12->i_ref_count;
      v13 = *(SSParameters **)(v10 + 24);
      if ( v13 )
      {
        v14 = v13->i_ref_count-- == 1;
        if ( v14 )
        {
          v13->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v13);
          AMemory::c_free_func(v13);
        }
        *(_QWORD *)(v10 + 24) = 0i64;
      }
      v89 = v10;
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
          v12->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v12);
          AMemory::c_free_func(v12);
        }
      }
    }
  }
  v15 = v6->i_methods.i_count;
  if ( (_DWORD)v15 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v16 = (signed __int64)&a3[v15 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v16 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbolX_ctor_seed.i_uid < (unsigned int)a4 )
        goto LABEL_292;
      v17 = ASymbolX_ctor_seed.i_uid == (_DWORD)a4;
      a4 = ASymbolX_ctor_seed.i_uid != (_DWORD)a4;
      if ( v17 == 1 )
      {
        v18 = *(_QWORD *)a2;
        goto LABEL_48;
      }
      if ( a4 < 0 )
      {
LABEL_292:
        if ( a3 == (SSClass **)a2 )
          break;
        v16 = a2 - 8;
      }
      else
      {
        if ( v16 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v18 = 0i64;
LABEL_48:
  result = v18;
  if ( v18 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v18 + 16i64))(
           v18,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v18 + 32) = SSRandom::mthd_ctor_seed;
    }
    else
    {
      v19 = *(_QWORD *)(v18 + 16);
      v20 = *(SSParameters **)(v18 + 24);
      v88 = v20;
      if ( v20 )
        ++v20->i_ref_count;
      v21 = *(SSParameters **)(v18 + 24);
      if ( v21 )
      {
        v14 = v21->i_ref_count-- == 1;
        if ( v14 )
        {
          v21->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v21);
          AMemory::c_free_func(v21);
        }
        *(_QWORD *)(v18 + 24) = 0i64;
      }
      v89 = v18;
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
          v20->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v20);
          AMemory::c_free_func(v20);
        }
      }
    }
  }
  v22 = v6->i_methods.i_count;
  if ( (_DWORD)v22 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v23 = (signed __int64)&a3[v22 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v23 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_get_seed.i_uid < (unsigned int)a4 )
        goto LABEL_293;
      v24 = ASymbol_get_seed.i_uid == (_DWORD)a4;
      a4 = ASymbol_get_seed.i_uid != (_DWORD)a4;
      if ( v24 == 1 )
      {
        v25 = *(_QWORD *)a2;
        goto LABEL_73;
      }
      if ( a4 < 0 )
      {
LABEL_293:
        if ( a3 == (SSClass **)a2 )
          break;
        v23 = a2 - 8;
      }
      else
      {
        if ( v23 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v25 = 0i64;
LABEL_73:
  result = v25;
  if ( v25 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v25 + 16i64))(
           v25,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v25 + 32) = SSInteger::mthd_as_copy;
    }
    else
    {
      v26 = *(_QWORD *)(v25 + 16);
      v27 = *(SSParameters **)(v25 + 24);
      v88 = v27;
      if ( v27 )
        ++v27->i_ref_count;
      v28 = *(SSParameters **)(v25 + 24);
      if ( v28 )
      {
        v14 = v28->i_ref_count-- == 1;
        if ( v14 )
        {
          v28->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v28);
          AMemory::c_free_func(v28);
        }
        *(_QWORD *)(v25 + 24) = 0i64;
      }
      v89 = v25;
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
          v27->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v27);
          AMemory::c_free_func(v27);
        }
      }
    }
  }
  v29 = v6->i_methods.i_count;
  if ( (_DWORD)v29 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v30 = (signed __int64)&a3[v29 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v30 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_set_seed.i_uid < (unsigned int)a4 )
        goto LABEL_294;
      v31 = ASymbol_set_seed.i_uid == (_DWORD)a4;
      a4 = ASymbol_set_seed.i_uid != (_DWORD)a4;
      if ( v31 == 1 )
      {
        v32 = *(_QWORD *)a2;
        goto LABEL_98;
      }
      if ( a4 < 0 )
      {
LABEL_294:
        if ( a3 == (SSClass **)a2 )
          break;
        v30 = a2 - 8;
      }
      else
      {
        if ( v30 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v32 = 0i64;
LABEL_98:
  result = v32;
  if ( v32 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v32 + 16i64))(
           v32,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v32 + 32) = SSReal::mthd_ctor_copy;
    }
    else
    {
      v33 = *(_QWORD *)(v32 + 16);
      v34 = *(SSParameters **)(v32 + 24);
      v88 = v34;
      if ( v34 )
        ++v34->i_ref_count;
      v35 = *(SSParameters **)(v32 + 24);
      if ( v35 )
      {
        v14 = v35->i_ref_count-- == 1;
        if ( v14 )
        {
          v35->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v35);
          AMemory::c_free_func(v35);
        }
        *(_QWORD *)(v32 + 24) = 0i64;
      }
      v89 = v32;
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
          v34->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v34);
          AMemory::c_free_func(v34);
        }
      }
    }
  }
  v36 = v6->i_methods.i_count;
  if ( (_DWORD)v36 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v37 = (signed __int64)&a3[v36 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v37 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_coin_toss.i_uid < (unsigned int)a4 )
        goto LABEL_295;
      v38 = ASymbol_coin_toss.i_uid == (_DWORD)a4;
      a4 = ASymbol_coin_toss.i_uid != (_DWORD)a4;
      if ( v38 == 1 )
      {
        v39 = *(_QWORD *)a2;
        goto LABEL_123;
      }
      if ( a4 < 0 )
      {
LABEL_295:
        if ( a3 == (SSClass **)a2 )
          break;
        v37 = a2 - 8;
      }
      else
      {
        if ( v37 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v39 = 0i64;
LABEL_123:
  result = v39;
  if ( v39 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v39 + 16i64))(
           v39,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v39 + 32) = SSRandom::mthd_coin_toss;
    }
    else
    {
      v40 = *(_QWORD *)(v39 + 16);
      v41 = *(SSParameters **)(v39 + 24);
      v88 = v41;
      if ( v41 )
        ++v41->i_ref_count;
      v42 = *(SSParameters **)(v39 + 24);
      if ( v42 )
      {
        v14 = v42->i_ref_count-- == 1;
        if ( v14 )
        {
          v42->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v42);
          AMemory::c_free_func(v42);
        }
        *(_QWORD *)(v39 + 24) = 0i64;
      }
      v89 = v39;
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
          v41->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v41);
          AMemory::c_free_func(v41);
        }
      }
    }
  }
  v43 = v6->i_methods.i_count;
  if ( (_DWORD)v43 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v44 = (signed __int64)&a3[v43 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v44 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_uniform_int.i_uid < (unsigned int)a4 )
        goto LABEL_296;
      v45 = ASymbol_uniform_int.i_uid == (_DWORD)a4;
      a4 = ASymbol_uniform_int.i_uid != (_DWORD)a4;
      if ( v45 == 1 )
      {
        v46 = *(_QWORD *)a2;
        goto LABEL_148;
      }
      if ( a4 < 0 )
      {
LABEL_296:
        if ( a3 == (SSClass **)a2 )
          break;
        v44 = a2 - 8;
      }
      else
      {
        if ( v44 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v46 = 0i64;
LABEL_148:
  result = v46;
  if ( v46 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v46 + 16i64))(
           v46,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v46 + 32) = SSRandom::mthd_uniform_int;
    }
    else
    {
      v47 = *(_QWORD *)(v46 + 16);
      v48 = *(SSParameters **)(v46 + 24);
      v88 = v48;
      if ( v48 )
        ++v48->i_ref_count;
      v49 = *(SSParameters **)(v46 + 24);
      if ( v49 )
      {
        v14 = v49->i_ref_count-- == 1;
        if ( v14 )
        {
          v49->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v49);
          AMemory::c_free_func(v49);
        }
        *(_QWORD *)(v46 + 24) = 0i64;
      }
      v89 = v46;
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
          v48->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v48);
          AMemory::c_free_func(v48);
        }
      }
    }
  }
  v50 = v6->i_methods.i_count;
  if ( (_DWORD)v50 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v51 = (signed __int64)&a3[v50 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v51 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_triangle_int.i_uid < (unsigned int)a4 )
        goto LABEL_297;
      v52 = ASymbol_triangle_int.i_uid == (_DWORD)a4;
      a4 = ASymbol_triangle_int.i_uid != (_DWORD)a4;
      if ( v52 == 1 )
      {
        v53 = *(_QWORD *)a2;
        goto LABEL_173;
      }
      if ( a4 < 0 )
      {
LABEL_297:
        if ( a3 == (SSClass **)a2 )
          break;
        v51 = a2 - 8;
      }
      else
      {
        if ( v51 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v53 = 0i64;
LABEL_173:
  result = v53;
  if ( v53 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v53 + 16i64))(
           v53,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v53 + 32) = SSRandom::mthd_triangle_int;
    }
    else
    {
      v54 = *(_QWORD *)(v53 + 16);
      v55 = *(SSParameters **)(v53 + 24);
      v88 = v55;
      if ( v55 )
        ++v55->i_ref_count;
      v56 = *(SSParameters **)(v53 + 24);
      if ( v56 )
      {
        v14 = v56->i_ref_count-- == 1;
        if ( v14 )
        {
          v56->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v56);
          AMemory::c_free_func(v56);
        }
        *(_QWORD *)(v53 + 24) = 0i64;
      }
      v89 = v53;
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
          v55->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v55);
          AMemory::c_free_func(v55);
        }
      }
    }
  }
  v57 = v6->i_methods.i_count;
  if ( (_DWORD)v57 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v58 = (signed __int64)&a3[v57 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v58 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_normal_int.i_uid < (unsigned int)a4 )
        goto LABEL_298;
      v59 = ASymbol_normal_int.i_uid == (_DWORD)a4;
      a4 = ASymbol_normal_int.i_uid != (_DWORD)a4;
      if ( v59 == 1 )
      {
        v60 = *(_QWORD *)a2;
        goto LABEL_198;
      }
      if ( a4 < 0 )
      {
LABEL_298:
        if ( a3 == (SSClass **)a2 )
          break;
        v58 = a2 - 8;
      }
      else
      {
        if ( v58 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v60 = 0i64;
LABEL_198:
  result = v60;
  if ( v60 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v60 + 16i64))(
           v60,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v60 + 32) = SSRandom::mthd_normal_int;
    }
    else
    {
      v61 = *(_QWORD *)(v60 + 16);
      v62 = *(SSParameters **)(v60 + 24);
      v88 = v62;
      if ( v62 )
        ++v62->i_ref_count;
      v63 = *(SSParameters **)(v60 + 24);
      if ( v63 )
      {
        v14 = v63->i_ref_count-- == 1;
        if ( v14 )
        {
          v63->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v63);
          AMemory::c_free_func(v63);
        }
        *(_QWORD *)(v60 + 24) = 0i64;
      }
      v89 = v60;
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
          v62->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v62);
          AMemory::c_free_func(v62);
        }
      }
    }
  }
  v64 = v6->i_methods.i_count;
  if ( (_DWORD)v64 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v65 = (signed __int64)&a3[v64 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v65 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_up_slope_int.i_uid < (unsigned int)a4 )
        goto LABEL_299;
      v66 = ASymbol_up_slope_int.i_uid == (_DWORD)a4;
      a4 = ASymbol_up_slope_int.i_uid != (_DWORD)a4;
      if ( v66 == 1 )
      {
        v67 = *(_QWORD *)a2;
        goto LABEL_223;
      }
      if ( a4 < 0 )
      {
LABEL_299:
        if ( a3 == (SSClass **)a2 )
          break;
        v65 = a2 - 8;
      }
      else
      {
        if ( v65 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v67 = 0i64;
LABEL_223:
  result = v67;
  if ( v67 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v67 + 16i64))(
           v67,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v67 + 32) = SSRandom::mthd_up_slope_int;
    }
    else
    {
      v68 = *(_QWORD *)(v67 + 16);
      v69 = *(SSParameters **)(v67 + 24);
      v88 = v69;
      if ( v69 )
        ++v69->i_ref_count;
      v70 = *(SSParameters **)(v67 + 24);
      if ( v70 )
      {
        v14 = v70->i_ref_count-- == 1;
        if ( v14 )
        {
          v70->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v70);
          AMemory::c_free_func(v70);
        }
        *(_QWORD *)(v67 + 24) = 0i64;
      }
      v89 = v67;
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
          v69->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v69);
          AMemory::c_free_func(v69);
        }
      }
    }
  }
  v71 = v6->i_methods.i_count;
  if ( (_DWORD)v71 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v72 = (signed __int64)&a3[v71 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v72 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_down_slope_int.i_uid < (unsigned int)a4 )
        goto LABEL_300;
      v73 = ASymbol_down_slope_int.i_uid == (_DWORD)a4;
      a4 = ASymbol_down_slope_int.i_uid != (_DWORD)a4;
      if ( v73 == 1 )
      {
        v74 = *(_QWORD *)a2;
        goto LABEL_248;
      }
      if ( a4 < 0 )
      {
LABEL_300:
        if ( a3 == (SSClass **)a2 )
          break;
        v72 = a2 - 8;
      }
      else
      {
        if ( v72 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v74 = 0i64;
LABEL_248:
  result = v74;
  if ( v74 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v74 + 16i64))(
           v74,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v74 + 32) = SSRandom::mthd_down_slope_int;
    }
    else
    {
      v75 = *(_QWORD *)(v74 + 16);
      v76 = *(SSParameters **)(v74 + 24);
      v88 = v76;
      if ( v76 )
        ++v76->i_ref_count;
      v77 = *(SSParameters **)(v74 + 24);
      if ( v77 )
      {
        v14 = v77->i_ref_count-- == 1;
        if ( v14 )
        {
          v77->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v77);
          AMemory::c_free_func(v77);
        }
        *(_QWORD *)(v74 + 24) = 0i64;
      }
      v89 = v74;
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
          v76->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v76);
          AMemory::c_free_func(v76);
        }
      }
    }
  }
  v78 = v6->i_methods.i_count;
  if ( (_DWORD)v78 )
  {
    a3 = (SSClass **)v6->i_methods.i_array_p;
    v79 = (signed __int64)&a3[v78 - 1];
    while ( 1 )
    {
      a2 = (signed __int64)&a3[(v79 - (signed __int64)a3) >> 4];
      a4 = *(unsigned int *)(*(_QWORD *)a2 + 8i64);
      if ( ASymbol_thorn_int.i_uid < (unsigned int)a4 )
        goto LABEL_301;
      v80 = ASymbol_thorn_int.i_uid == (_DWORD)a4;
      a4 = ASymbol_thorn_int.i_uid != (_DWORD)a4;
      if ( v80 == 1 )
      {
        v81 = *(_QWORD *)a2;
        goto LABEL_273;
      }
      if ( a4 < 0 )
      {
LABEL_301:
        if ( a3 == (SSClass **)a2 )
          break;
        v79 = a2 - 8;
      }
      else
      {
        if ( v79 == a2 )
          break;
        a3 = (SSClass **)(a2 + 8);
      }
    }
  }
  v81 = 0i64;
LABEL_273:
  result = v81;
  if ( v81 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64, signed __int64, SSClass **, __int64, signed __int64))(*(_QWORD *)v81 + 16i64))(
           v81,
           a2,
           a3,
           a4,
           v86) == 1 )
    {
      *(_QWORD *)(v81 + 32) = SSRandom::mthd_thorn_int;
    }
    else
    {
      v82 = *(_QWORD *)(v81 + 16);
      v83 = *(SSParameters **)(v81 + 24);
      v88 = v83;
      if ( v83 )
        ++v83->i_ref_count;
      v84 = *(SSParameters **)(v81 + 24);
      if ( v84 )
      {
        v14 = v84->i_ref_count-- == 1;
        if ( v14 )
        {
          v84->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v84);
          AMemory::c_free_func(v84);
        }
        *(_QWORD *)(v81 + 24) = 0i64;
      }
      v89 = v81;
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
          v83->i_ref_count = 2147483648;
          SSParameters::~SSParameters(v83);
          AMemory::c_free_func(v83);
        }
      }
    }
  }
  SSClass::register_method_func(v6, &ASymbol_nose_int, SSRandom::mthd_nose_int, 0);
  SSClass::register_method_func(v6, &ASymbol_uniform, SSRandom::mthd_uniform, 0);
  v85 = ASymbol::create((ASymbol *)&result, "uniform_range", 0xFFFFFFFF, ATerm_long);
  SSClass::register_method_func(v6, v85, SSRandom_mthd_uniform_range, 0);
  SSClass::register_method_func(v6, &ASymbol_uniform_symm, SSRandom::mthd_uniform_symm, 0);
  SSClass::register_method_func(v6, &ASymbol_triangle, SSRandom::mthd_triangle, 0);
  SSClass::register_method_func(v6, &ASymbol_triangle_symm, SSRandom::mthd_triangle_symm, 0);
  SSClass::register_method_func(v6, &ASymbol_normal, SSRandom::mthd_normal, 0);
  SSClass::register_method_func(v6, &ASymbol_up_slope, SSRandom::mthd_up_slope, 0);
  SSClass::register_method_func(v6, &ASymbol_down_slope, SSRandom::mthd_down_slope, 0);
  SSClass::register_method_func(v6, &ASymbol_thorn, SSRandom::mthd_thorn, 0);
  SSClass::register_method_func(v6, &ASymbol_nose, SSRandom::mthd_nose, 0);
}SParameters(v83);
 

