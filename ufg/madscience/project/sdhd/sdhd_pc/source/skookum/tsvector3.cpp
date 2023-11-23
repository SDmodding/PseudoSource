// File Line: 47
// RVA: 0x4CC760
SSInstance *__fastcall UFG::TSVector3::AsInstance(UFG::qVector3 *vec)
{
  UFG::allocator::free_link *v2; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  v2 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v2 )
  {
    y = vec->y;
    z = vec->z;
    *(float *)&v2->mNext = vec->x;
    *((float *)&v2->mNext + 1) = y;
    *(float *)&v2[1].mNext = z;
  }
  return SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v2);
}

// File Line: 58
// RVA: 0x4D8130
void UFG::TSVector3::BindAtomics(void)
{
  UFG::SkookumMgr::mspVector3Class = SSBrain::get_class("Vector3");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbolX_ctor,
    UFG::TSVector3::Mthd_constructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbolX_ctor_copy,
    UFG::TSVector3::Mthd_ctor_copy,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbolX_ctor_xyz,
    UFG::TSVector3::Mthd_ctor_xyz,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbolX_ctor_xy,
    UFG::TSVector3::Mthd_ctor_xy,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbolX_dtor,
    UFG::TSVector3::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_String,
    UFG::TSVector3::Mthd_String,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_assign,
    UFG::TSVector3::Mthd_op_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_equals,
    UFG::TSVector3::Mthd_op_equals,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_not_equal,
    UFG::TSVector3::Mthd_op_not_equal,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_add,
    UFG::TSVector3::Mthd_op_add,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_add_assign,
    UFG::TSVector3::Mthd_op_add_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_subtract,
    UFG::TSVector3::Mthd_op_subtract,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_subtract_assign,
    UFG::TSVector3::Mthd_op_subtract_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_multiply,
    UFG::TSVector3::Mthd_op_multiply,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_multiply_assign,
    UFG::TSVector3::Mthd_op_multiply_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_divide,
    UFG::TSVector3::Mthd_op_divide,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_divide_assign,
    UFG::TSVector3::Mthd_op_divide_assign,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "get_x",
    UFG::TSVector3::Mthd_get_x,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "get_y",
    UFG::TSVector3::Mthd_get_y,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "get_z",
    UFG::TSVector3::Mthd_get_z,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "set_xyz",
    UFG::TSVector3::Mthd_set_xyz,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "set_x",
    UFG::TSVector3::Mthd_set_x,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "set_y",
    UFG::TSVector3::Mthd_set_y,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "set_z",
    UFG::TSVector3::Mthd_set_z,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "is_near",
    UFG::TSVector3::Mthd_is_near,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbol_is_zero,
    UFG::TSVector3::Mthd_is_zero,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbol_zero,
    UFG::TSVector3::Mthd_zero,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "angle",
    UFG::TSVector3::Mthd_angle,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "distance",
    UFG::TSVector3::Mthd_distance,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "distance_squared",
    UFG::TSVector3::Mthd_distance_squared,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "length",
    UFG::TSVector3::Mthd_length,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "length_squared",
    UFG::TSVector3::Mthd_length_squared,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "normalize",
    UFG::TSVector3::Mthd_normalize,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "as_normalize",
    UFG::TSVector3::Mthd_as_normalize,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "dot",
    UFG::TSVector3::Mthd_dot,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "cross",
    UFG::TSVector3::Mthd_cross,
    SSBindFlag_instance_no_rebind);
}

// File Line: 110
// RVA: 0x4F6D20
void __fastcall UFG::TSVector3::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  SSObjectBase *i_obj_p; // rcx

  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v3->mNext = 0i64;
    LODWORD(v3[1].mNext) = 0;
  }
  else
  {
    v4 = 0i64;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 121
// RVA: 0x4F74A0
void __fastcall UFG::TSVector3::Mthd_ctor_copy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // r8
  _DWORD *i_user_data; // rcx
  int v6; // xmm1_4
  int v7; // xmm2_4
  SSObjectBase *i_obj_p; // rcx

  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  v4 = v3;
  if ( v3 )
  {
    i_user_data = (_DWORD *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = i_user_data[1];
    v7 = i_user_data[2];
    LODWORD(v3->mNext) = *i_user_data;
    HIDWORD(v3->mNext) = v6;
    LODWORD(v3[1].mNext) = v7;
  }
  else
  {
    v4 = 0i64;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 132
// RVA: 0x4F7790
void __fastcall UFG::TSVector3::Mthd_ctor_xyz(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v3; // r9
  SSData **i_array_p; // rax
  int i_user_data; // xmm1_4
  int v6; // xmm0_4
  SSObjectBase *i_obj_p; // rcx

  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v3 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = i_array_p[2]->i_data_p->i_user_data;
    v6 = i_array_p[1]->i_data_p->i_user_data;
    LODWORD(v3->mNext) = (*i_array_p)->i_data_p->i_user_data;
    HIDWORD(v3->mNext) = v6;
    LODWORD(v3[1].mNext) = i_user_data;
  }
  else
  {
    v3 = 0i64;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v3;
  else
    *(_QWORD *)&MEMORY[0x20] = v3;
}

// File Line: 145
// RVA: 0x4F7590
void __fastcall UFG::TSVector3::Mthd_ctor_xy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v3; // r9
  SSData **i_array_p; // rcx
  int i_user_data; // xmm0_4
  SSObjectBase *i_obj_p; // rcx

  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v3 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    LODWORD(v3->mNext) = (*i_array_p)->i_data_p->i_user_data;
    HIDWORD(v3->mNext) = i_user_data;
    LODWORD(v3[1].mNext) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v3;
  else
    *(_QWORD *)&MEMORY[0x20] = v3;
}

// File Line: 166
// RVA: 0x4F3690
void __fastcall UFG::TSVector3::Mthd_String(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+58h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    AString::AString(
      &str,
      0x80u,
      "(%g, %g, %g)",
      *(float *)&i_obj_p[2].vfptr->__vecDelDtor,
      *((float *)&i_obj_p[2].vfptr->__vecDelDtor + 1),
      *(float *)&i_obj_p[2].vfptr->get_obj_type,
      -2i64);
    *ppResult = SSString::as_instance(&str);
    i_str_ref_p = str.i_str_ref_p;
    if ( str.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v9 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v9) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

// File Line: 181
// RVA: 0x505490
void __fastcall UFG::TSVector3::Mthd_op_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  _DWORD *i_user_data; // rdx
  _DWORD *v5; // rcx
  int v6; // xmm0_4
  int v7; // xmm1_4

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (_DWORD *)i_obj_p->i_user_data;
  v5 = (_DWORD *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = v5[1];
  v7 = v5[2];
  *i_user_data = *v5;
  i_user_data[1] = v6;
  i_user_data[2] = v7;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 198
// RVA: 0x505620
void __fastcall UFG::TSVector3::Mthd_op_equals(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdx
  SSObjectBase *i_obj_p; // r8
  bool v6; // cl
  float *i_user_data; // rax
  float *vfptr; // rdx

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v6 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (float *)i_data_p->i_user_data;
    vfptr = (float *)i_obj_p[2].vfptr;
    if ( *i_user_data == *vfptr && i_user_data[1] == vfptr[1] && i_user_data[2] == vfptr[2] )
      v6 = 1;
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 210
// RVA: 0x5057B0
void __fastcall UFG::TSVector3::Mthd_op_not_equal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdx
  SSObjectBase *i_obj_p; // r8
  bool v6; // cl
  float *i_user_data; // rax
  float *vfptr; // rdx

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v6 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (float *)i_data_p->i_user_data;
    vfptr = (float *)i_obj_p[2].vfptr;
    if ( *i_user_data != *vfptr || i_user_data[1] != vfptr[1] || i_user_data[2] != vfptr[2] )
      v6 = 1;
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 222
// RVA: 0x505360
void __fastcall UFG::TSVector3::Mthd_op_add(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *vfptr; // rax
  float *i_user_data; // rcx
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float *v9; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = *vfptr + *i_user_data;
    v7 = vfptr[1] + i_user_data[1];
    v8 = vfptr[2] + i_user_data[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 238
// RVA: 0x505430
void __fastcall UFG::TSVector3::Mthd_op_add_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  float *i_user_data; // rcx
  float *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = (float *)i_obj_p->i_user_data;
  v5 = i_user_data[1] + v4[1];
  v6 = i_user_data[2] + v4[2];
  *v4 = *v4 + *i_user_data;
  v4[1] = v5;
  v4[2] = v6;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 255
// RVA: 0x505820
void __fastcall UFG::TSVector3::Mthd_op_subtract(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *vfptr; // rax
  float *i_user_data; // rcx
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float *v9; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = *vfptr - *i_user_data;
    v7 = vfptr[1] - i_user_data[1];
    v8 = vfptr[2] - i_user_data[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 271
// RVA: 0x5058F0
void __fastcall UFG::TSVector3::Mthd_op_subtract_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  float *i_user_data; // rcx
  float *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = (float *)i_obj_p->i_user_data;
  v5 = v4[1] - i_user_data[1];
  v6 = v4[2] - i_user_data[2];
  *v4 = *v4 - *i_user_data;
  v4[1] = v5;
  v4[2] = v6;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 288
// RVA: 0x505690
void __fastcall UFG::TSVector3::Mthd_op_multiply(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  float *vfptr; // rdx
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm6_4
  float *v8; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    v5 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * *vfptr;
    v6 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * vfptr[1];
    v7 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data * vfptr[2];
    v8 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v8 )
    {
      *v8 = v5;
      v8[1] = v6;
      v8[2] = v7;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v8);
  }
}

// File Line: 304
// RVA: 0x505750
void __fastcall UFG::TSVector3::Mthd_op_multiply_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  float *i_user_data; // rax
  SSInstance *i_data_p; // rdx

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (float *)i_obj_p->i_user_data;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  *i_user_data = *i_user_data * *(float *)&i_data_p->i_user_data;
  i_user_data[1] = *(float *)&i_data_p->i_user_data * i_user_data[1];
  i_user_data[2] = *(float *)&i_data_p->i_user_data * i_user_data[2];
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 321
// RVA: 0x5054F0
void __fastcall UFG::TSVector3::Mthd_op_divide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  float *vfptr; // rdx
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float *v9; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    v5 = 1.0 / *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = v5 * *vfptr;
    v7 = v5 * vfptr[1];
    v8 = v5 * vfptr[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 337
// RVA: 0x5055C0
void __fastcall UFG::TSVector3::Mthd_op_divide_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  float *i_user_data; // rax
  SSInstance *i_data_p; // rdx
  float v6; // xmm1_4
  float v7; // xmm0_4

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (float *)i_obj_p->i_user_data;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v6 = i_user_data[1];
  *i_user_data = *i_user_data / *(float *)&i_data_p->i_user_data;
  v7 = i_user_data[2];
  i_user_data[1] = v6 / *(float *)&i_data_p->i_user_data;
  i_user_data[2] = v7 / *(float *)&i_data_p->i_user_data;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 354
// RVA: 0x4FF630
void __fastcall UFG::TSVector3::Mthd_get_x(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned __int64)i_obj_p[2].vfptr->__vecDelDtor);
  }
}

// File Line: 366
// RVA: 0x4FF750
void __fastcall UFG::TSVector3::Mthd_get_y(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, HIDWORD(i_obj_p[2].vfptr->__vecDelDtor));
  }
}

// File Line: 378
// RVA: 0x4FF880
void __fastcall UFG::TSVector3::Mthd_get_z(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(i_obj_p[2].vfptr->get_obj_type));
  }
}

// File Line: 390
// RVA: 0x50B3F0
void __fastcall UFG::TSVector3::Mthd_set_xyz(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r9
  SSData **i_array_p; // rdx
  _DWORD *i_user_data; // r8

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (_DWORD *)i_obj_p->i_user_data;
  *i_user_data = (*i_array_p)->i_data_p->i_user_data;
  i_user_data[1] = i_array_p[1]->i_data_p->i_user_data;
  i_user_data[2] = i_array_p[2]->i_data_p->i_user_data;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 410
// RVA: 0x50B2E0
void __fastcall UFG::TSVector3::Mthd_set_x(SSInvokedMethod *pScope, SSObjectBase **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  LODWORD(i_obj_p[2].vfptr->__vecDelDtor) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( ppResult )
  {
    ++LODWORD(i_obj_p[1].vfptr);
    *ppResult = i_obj_p;
  }
}

// File Line: 427
// RVA: 0x50B450
void __fastcall UFG::TSVector3::Mthd_set_y(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  *(_DWORD *)(i_obj_p->i_user_data + 4) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 445
// RVA: 0x50B490
void __fastcall UFG::TSVector3::Mthd_set_z(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  *(_DWORD *)(i_obj_p->i_user_data + 8) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 462
// RVA: 0x5027C0
void __fastcall UFG::TSVector3::Mthd_is_near(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSData **i_array_p; // rdx
  float *vfptr; // rax
  float *i_user_data; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    i_array_p = pScope->i_data.i_array_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    *ppResult = SSBoolean::pool_new((float)((float)((float)((float)(vfptr[1] - i_user_data[1])
                                                          * (float)(vfptr[1] - i_user_data[1]))
                                                  + (float)((float)(*vfptr - *i_user_data)
                                                          * (float)(*vfptr - *i_user_data)))
                                          + (float)((float)(vfptr[2] - i_user_data[2])
                                                  * (float)(vfptr[2] - i_user_data[2]))) <= *(float *)&i_array_p[1]->i_data_p->i_user_data);
  }
}

// File Line: 476
// RVA: 0x503EE0
void __fastcall UFG::TSVector3::Mthd_is_zero(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  bool v4; // cl
  float *vfptr; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v4 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    if ( *vfptr == 0.0 && vfptr[1] == 0.0 && vfptr[2] == 0.0 )
      v4 = 1;
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 488
// RVA: 0x50E770
void __fastcall UFG::TSVector3::Mthd_zero(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  unsigned __int64 i_user_data; // rax

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = i_obj_p->i_user_data;
  *(_QWORD *)i_user_data = 0i64;
  *(_DWORD *)(i_user_data + 8) = 0;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 508
// RVA: 0x4F4BB0
void __fastcall UFG::TSVector3::Mthd_angle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSObjectBase *i_obj_p; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    user_data = UFG::qAngleBetween(
                  (UFG::qVector3 *)i_obj_p[2].vfptr,
                  (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 522
// RVA: 0x4F8610
void __fastcall UFG::TSVector3::Mthd_distance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *i_user_data; // rcx
  SSObjectBaseVtbl *vfptr; // rax
  __m128 vecDelDtor_high; // xmm2
  float v6; // xmm0_4

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    vfptr = i_obj_p[2].vfptr;
    vecDelDtor_high = (__m128)HIDWORD(vfptr->__vecDelDtor);
    v6 = *(float *)&vfptr->get_obj_type - i_user_data[2];
    vecDelDtor_high.m128_f32[0] = (float)((float)((float)(vecDelDtor_high.m128_f32[0] - i_user_data[1])
                                                * (float)(vecDelDtor_high.m128_f32[0] - i_user_data[1]))
                                        + (float)((float)(*(float *)&vfptr->__vecDelDtor - *i_user_data)
                                                * (float)(*(float *)&vfptr->__vecDelDtor - *i_user_data)))
                                + (float)(v6 * v6);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, _mm_sqrt_ps(vecDelDtor_high).m128_u32[0]);
  }
}

// File Line: 536
// RVA: 0x4F86A0
void __fastcall UFG::TSVector3::Mthd_distance_squared(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *i_user_data; // rcx
  float *vfptr; // rax
  float v5; // xmm2_4

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    vfptr = (float *)i_obj_p[2].vfptr;
    v5 = vfptr[1] - i_user_data[1];
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_real_class_p,
                  COERCE_UNSIGNED_INT(
                    (float)((float)(v5 * v5) + (float)((float)(*vfptr - *i_user_data) * (float)(*vfptr - *i_user_data)))
                  + (float)((float)(vfptr[2] - i_user_data[2]) * (float)(vfptr[2] - i_user_data[2]))));
  }
}

// File Line: 550
// RVA: 0x503F80
void __fastcall UFG::TSVector3::Mthd_length(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *vfptr; // rax
  __m128 v4; // xmm2

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    v4 = (__m128)*(unsigned int *)vfptr;
    v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(vfptr[1] * vfptr[1]))
                   + (float)(vfptr[2] * vfptr[2]);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, _mm_sqrt_ps(v4).m128_u32[0]);
  }
}

// File Line: 562
// RVA: 0x503FF0
void __fastcall UFG::TSVector3::Mthd_length_squared(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *vfptr; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_real_class_p,
                  COERCE_UNSIGNED_INT((float)((float)(*vfptr * *vfptr) + (float)(vfptr[1] * vfptr[1])) + (float)(vfptr[2] * vfptr[2])));
  }
}

// File Line: 574
// RVA: 0x4F5120
void __fastcall UFG::TSVector3::Mthd_as_normalize(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *vfptr; // rax
  float v5; // xmm4_4
  __m128 v6; // xmm5
  float v7; // xmm3_4
  __m128 v8; // xmm2
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm6_4
  float *v13; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (float *)i_obj_p[2].vfptr;
    v5 = vfptr[1];
    v6 = (__m128)*(unsigned int *)vfptr;
    v7 = vfptr[2];
    v8 = v6;
    v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
    v9 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data / _mm_sqrt_ps(v8).m128_f32[0];
    v10 = v9 * v7;
    v11 = v9 * v5;
    v12 = v9 * v6.m128_f32[0];
    v13 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v13 )
    {
      *v13 = v12;
      v13[1] = v11;
      v13[2] = v10;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v13);
  }
}

// File Line: 588
// RVA: 0x504F80
void __fastcall UFG::TSVector3::Mthd_normalize(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_obj_p; // r8
  float *i_user_data; // rdx
  float v5; // xmm6_4
  __m128 v6; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm2
  float v9; // xmm3_4

  i_obj_p = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_user_data = (float *)i_obj_p->i_user_data;
  v5 = i_user_data[1];
  v6 = (__m128)*(unsigned int *)i_user_data;
  v7 = i_user_data[2];
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  v9 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data / _mm_sqrt_ps(v8).m128_f32[0];
  *i_user_data = v6.m128_f32[0] * v9;
  i_user_data[1] = v5 * v9;
  i_user_data[2] = v7 * v9;
  if ( ppResult )
  {
    ++i_obj_p->i_ref_count;
    *ppResult = i_obj_p;
  }
}

// File Line: 606
// RVA: 0x4F8800
void __fastcall UFG::TSVector3::Mthd_dot(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdx
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_real_class_p,
                  COERCE_UNSIGNED_INT(
                    (float)((float)(*((float *)&i_obj_p[2].vfptr->__vecDelDtor + 1)
                                  * *(float *)(i_data_p->i_user_data + 4))
                          + (float)(*(float *)i_data_p->i_user_data * *(float *)&i_obj_p[2].vfptr->__vecDelDtor))
                  + (float)(*(float *)&i_obj_p[2].vfptr->get_obj_type * *(float *)(i_data_p->i_user_data + 8))));
  }
}

// File Line: 620
// RVA: 0x4F7150
void __fastcall UFG::TSVector3::Mthd_cross(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  float *i_user_data; // rcx
  float *vfptr; // rax
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float *v9; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    vfptr = (float *)i_obj_p[2].vfptr;
    v6 = (float)(*vfptr * i_user_data[1]) - (float)(*i_user_data * vfptr[1]);
    v7 = (float)(vfptr[2] * *i_user_data) - (float)(i_user_data[2] * *vfptr);
    v8 = (float)(i_user_data[2] * vfptr[1]) - (float)(vfptr[2] * i_user_data[1]);
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v8;
      v9[1] = v7;
      v9[2] = v6;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

