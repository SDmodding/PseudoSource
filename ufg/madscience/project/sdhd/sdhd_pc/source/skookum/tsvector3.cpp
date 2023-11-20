// File Line: 47
// RVA: 0x4CC760
SSInstance *__fastcall UFG::TSVector3::AsInstance(UFG::qVector3 *vec)
{
  UFG::qVector3 *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  float v3; // xmm1_4
  float v4; // xmm2_4

  v1 = vec;
  v2 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v2 )
  {
    v3 = v1->y;
    v4 = v1->z;
    *(float *)&v2->mNext = v1->x;
    *((float *)&v2->mNext + 1) = v3;
    *(float *)&v2[1].mNext = v4;
  }
  return SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v2);
}

// File Line: 58
// RVA: 0x4D8130
void UFG::TSVector3::BindAtomics(void)
{
  UFG::SkookumMgr::mspVector3Class = SSBrain::get_class("Vector3");
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbolX_ctor, UFG::TSVector3::Mthd_constructor, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbolX_ctor_copy,
    UFG::TSVector3::Mthd_ctor_copy,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbolX_ctor_xyz,
    UFG::TSVector3::Mthd_ctor_xyz,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbolX_ctor_xy,
    UFG::TSVector3::Mthd_ctor_xy,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbolX_dtor, UFG::TSVector3::Mthd_destructor, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbol_String, UFG::TSVector3::Mthd_String, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbol_assign, UFG::TSVector3::Mthd_op_assign, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbol_equals, UFG::TSVector3::Mthd_op_equals, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_not_equal,
    UFG::TSVector3::Mthd_op_not_equal,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbol_add, UFG::TSVector3::Mthd_op_add, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_add_assign,
    UFG::TSVector3::Mthd_op_add_assign,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_subtract,
    UFG::TSVector3::Mthd_op_subtract,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_subtract_assign,
    UFG::TSVector3::Mthd_op_subtract_assign,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_multiply,
    UFG::TSVector3::Mthd_op_multiply,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_multiply_assign,
    UFG::TSVector3::Mthd_op_multiply_assign,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, &ASymbol_divide, UFG::TSVector3::Mthd_op_divide, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    &ASymbol_divide_assign,
    UFG::TSVector3::Mthd_op_divide_assign,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "get_x", UFG::TSVector3::Mthd_get_x, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "get_y", UFG::TSVector3::Mthd_get_y, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "get_z", UFG::TSVector3::Mthd_get_z, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "set_xyz", UFG::TSVector3::Mthd_set_xyz, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "set_x", UFG::TSVector3::Mthd_set_x, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "set_y", UFG::TSVector3::Mthd_set_y, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "set_z", UFG::TSVector3::Mthd_set_z, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "is_near", UFG::TSVector3::Mthd_is_near, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbol_is_zero,
    UFG::TSVector3::Mthd_is_zero,
    0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    (ASymbol *)&qSymbol_zero,
    UFG::TSVector3::Mthd_zero,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "angle", UFG::TSVector3::Mthd_angle, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "distance", UFG::TSVector3::Mthd_distance, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "distance_squared",
    UFG::TSVector3::Mthd_distance_squared,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "length", UFG::TSVector3::Mthd_length, 0);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspVector3Class,
    "length_squared",
    UFG::TSVector3::Mthd_length_squared,
    0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "normalize", UFG::TSVector3::Mthd_normalize, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "as_normalize", UFG::TSVector3::Mthd_as_normalize, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "dot", UFG::TSVector3::Mthd_dot, 0);
  SSClass::register_method_func(UFG::SkookumMgr::mspVector3Class, "cross", UFG::TSVector3::Mthd_cross, 0);
}

// File Line: 110
// RVA: 0x4F6D20
void __fastcall UFG::TSVector3::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  SSObjectBase *v5; // rcx

  v2 = pScope;
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
  v5 = v2->i_scope_p.i_obj_p;
  if ( v5 && v2->i_scope_p.i_ptr_id == v5->i_ptr_id )
    v5[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 121
// RVA: 0x4F74A0
void __fastcall UFG::TSVector3::Mthd_ctor_copy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // r8
  _DWORD *v5; // rcx
  int v6; // xmm1_4
  int v7; // xmm2_4
  SSObjectBase *v8; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v5 = (_DWORD *)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = v5[1];
    v7 = v5[2];
    LODWORD(v3->mNext) = *v5;
    HIDWORD(v3->mNext) = v6;
    LODWORD(v3[1].mNext) = v7;
  }
  else
  {
    v4 = 0i64;
  }
  v8 = v2->i_scope_p.i_obj_p;
  if ( v8 && v2->i_scope_p.i_ptr_id == v8->i_ptr_id )
    v8[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 132
// RVA: 0x4F7790
void __fastcall UFG::TSVector3::Mthd_ctor_xyz(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // r9
  SSData **v4; // rax
  int v5; // xmm1_4
  int v6; // xmm0_4
  SSObjectBase *v7; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v3 )
  {
    v4 = v2->i_data.i_array_p;
    v5 = v4[2]->i_data_p->i_user_data;
    v6 = v4[1]->i_data_p->i_user_data;
    LODWORD(v3->mNext) = (*v4)->i_data_p->i_user_data;
    HIDWORD(v3->mNext) = v6;
    LODWORD(v3[1].mNext) = v5;
  }
  else
  {
    v3 = 0i64;
  }
  v7 = v2->i_scope_p.i_obj_p;
  if ( v7 && v2->i_scope_p.i_ptr_id == v7->i_ptr_id )
    v7[2].vfptr = (SSObjectBaseVtbl *)v3;
  else
    *(_QWORD *)&MEMORY[0x20] = v3;
}

// File Line: 145
// RVA: 0x4F7590
void __fastcall UFG::TSVector3::Mthd_ctor_xy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // r9
  SSData **v4; // rcx
  int v5; // xmm0_4
  SSObjectBase *v6; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v3 )
  {
    v4 = v2->i_data.i_array_p;
    v5 = v4[1]->i_data_p->i_user_data;
    LODWORD(v3->mNext) = (*v4)->i_data_p->i_user_data;
    HIDWORD(v3->mNext) = v5;
    LODWORD(v3[1].mNext) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  v6 = v2->i_scope_p.i_obj_p;
  if ( v6 && v2->i_scope_p.i_ptr_id == v6->i_ptr_id )
    v6[2].vfptr = (SSObjectBaseVtbl *)v3;
  else
    *(_QWORD *)&MEMORY[0x20] = v3;
}

// File Line: 166
// RVA: 0x4F3690
void __fastcall UFG::TSVector3::Mthd_String(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  AStringRef *v4; // rbx
  bool v5; // zf
  AObjReusePool<AStringRef> *v6; // rax
  AObjBlock<AStringRef> *v7; // rcx
  unsigned __int64 v8; // rdx
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v10; // rcx
  AString str; // [rsp+58h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    AString::AString(
      &str,
      0x80u,
      "(%g, %g, %g)",
      *(float *)&v3[2].vfptr->__vecDelDtor,
      *((float *)&v3[2].vfptr->__vecDelDtor + 1),
      *(float *)&v3[2].vfptr->get_obj_type,
      -2i64);
    *v2 = SSString::as_instance(&str);
    v4 = str.i_str_ref_p;
    v5 = str.i_str_ref_p->i_ref_count == 1;
    --v4->i_ref_count;
    if ( v5 )
    {
      if ( v4->i_deallocate )
        AMemory::c_free_func(v4->i_cstr_p);
      v6 = AStringRef::get_pool();
      v7 = v6->i_block_p;
      v8 = (unsigned __int64)v7->i_objects_a;
      if ( (unsigned __int64)v4 < v8 || (v9 = (unsigned __int64)v4 < v8 + 24i64 * v7->i_size, v10 = &v6->i_pool, !v9) )
        v10 = &v6->i_exp_pool;
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v10, v4);
    }
  }
}

// File Line: 181
// RVA: 0x505490
void __fastcall UFG::TSVector3::Mthd_op_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r9
  SSObjectBaseVtbl *v4; // rdx
  _DWORD *v5; // rcx
  int v6; // xmm0_4
  int v7; // xmm1_4

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  v5 = (_DWORD *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v6 = v5[1];
  v7 = v5[2];
  LODWORD(v4->__vecDelDtor) = *v5;
  HIDWORD(v4->__vecDelDtor) = v6;
  LODWORD(v4->get_obj_type) = v7;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 198
// RVA: 0x505620
void __fastcall UFG::TSVector3::Mthd_op_equals(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // r9
  SSInstance *v4; // rdx
  SSObjectBase *v5; // r8
  bool v6; // cl
  float *v7; // rax
  float *v8; // rdx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = (*pScope->i_data.i_array_p)->i_data_p;
    v5 = pScope->i_scope_p.i_obj_p;
    v6 = 0;
    if ( !v5 || v3->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v7 = (float *)v4->i_user_data;
    v8 = (float *)v5[2].vfptr;
    if ( *v7 == *v8 && v7[1] == v8[1] && v7[2] == v8[2] )
      v6 = 1;
    *v2 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 210
// RVA: 0x5057B0
void __fastcall UFG::TSVector3::Mthd_op_not_equal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // r9
  SSInstance *v4; // rdx
  SSObjectBase *v5; // r8
  bool v6; // cl
  float *v7; // rax
  float *v8; // rdx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = (*pScope->i_data.i_array_p)->i_data_p;
    v5 = pScope->i_scope_p.i_obj_p;
    v6 = 0;
    if ( !v5 || v3->i_scope_p.i_ptr_id != v5->i_ptr_id )
      v5 = 0i64;
    v7 = (float *)v4->i_user_data;
    v8 = (float *)v5[2].vfptr;
    if ( *v7 != *v8 || v7[1] != v8[1] || v7[2] != v8[2] )
      v6 = 1;
    *v2 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 222
// RVA: 0x505360
void __fastcall UFG::TSVector3::Mthd_op_add(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  float *v4; // rax
  float *v5; // rcx
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float *v9; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (float *)v3[2].vfptr;
    v5 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = *v4 + *v5;
    v7 = v4[1] + v5[1];
    v8 = v4[2] + v5[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 238
// RVA: 0x505430
void __fastcall UFG::TSVector3::Mthd_op_add_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // r8
  float *v3; // rcx
  float *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4

  v2 = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = (float *)v2->i_user_data;
  v5 = v3[1] + v4[1];
  v6 = v3[2] + v4[2];
  *v4 = *v4 + *v3;
  v4[1] = v5;
  v4[2] = v6;
  if ( ppResult )
  {
    ++v2->i_ref_count;
    *ppResult = v2;
  }
}

// File Line: 255
// RVA: 0x505820
void __fastcall UFG::TSVector3::Mthd_op_subtract(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  float *v4; // rax
  float *v5; // rcx
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float *v9; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (float *)v3[2].vfptr;
    v5 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = *v4 - *v5;
    v7 = v4[1] - v5[1];
    v8 = v4[2] - v5[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 271
// RVA: 0x5058F0
void __fastcall UFG::TSVector3::Mthd_op_subtract_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // r8
  float *v3; // rcx
  float *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4

  v2 = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = (float *)v2->i_user_data;
  v5 = v4[1] - v3[1];
  v6 = v4[2] - v3[2];
  *v4 = *v4 - *v3;
  v4[1] = v5;
  v4[2] = v6;
  if ( ppResult )
  {
    ++v2->i_ref_count;
    *ppResult = v2;
  }
}

// File Line: 288
// RVA: 0x505690
void __fastcall UFG::TSVector3::Mthd_op_multiply(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // rdx
  float *v4; // rdx
  SSInstance *v5; // rax
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float *v9; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (float *)v3[2].vfptr;
    v5 = (*pScope->i_data.i_array_p)->i_data_p;
    v6 = *(float *)&v5->i_user_data * *v4;
    v7 = *(float *)&v5->i_user_data * v4[1];
    v8 = *(float *)&v5->i_user_data * v4[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 304
// RVA: 0x505750
void __fastcall UFG::TSVector3::Mthd_op_multiply_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r9
  float *v4; // rax
  SSInstance *v5; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (float *)v2[2].vfptr;
  v5 = (*pScope->i_data.i_array_p)->i_data_p;
  *v4 = *v4 * *(float *)&v5->i_user_data;
  v4[1] = *(float *)&v5->i_user_data * v4[1];
  v4[2] = *(float *)&v5->i_user_data * v4[2];
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 321
// RVA: 0x5054F0
void __fastcall UFG::TSVector3::Mthd_op_divide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // rdx
  float *v4; // rdx
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float *v9; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (float *)v3[2].vfptr;
    v5 = 1.0 / *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = v5 * *v4;
    v7 = v5 * v4[1];
    v8 = v5 * v4[2];
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v6;
      v9[1] = v7;
      v9[2] = v8;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

// File Line: 337
// RVA: 0x5055C0
void __fastcall UFG::TSVector3::Mthd_op_divide_assign(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r9
  float *v4; // rax
  SSInstance *v5; // rdx
  float v6; // xmm1_4
  float v7; // xmm0_4

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (float *)v2[2].vfptr;
  v5 = (*pScope->i_data.i_array_p)->i_data_p;
  v6 = v4[1];
  *v4 = *v4 / *(float *)&v5->i_user_data;
  v7 = v4[2];
  v4[1] = v6 / *(float *)&v5->i_user_data;
  v4[2] = v7 / *(float *)&v5->i_user_data;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 354
// RVA: 0x4FF630
void __fastcall UFG::TSVector3::Mthd_get_x(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned __int64)v2[2].vfptr->__vecDelDtor);
  }
}

// File Line: 366
// RVA: 0x4FF750
void __fastcall UFG::TSVector3::Mthd_get_y(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, HIDWORD(v2[2].vfptr->__vecDelDtor));
  }
}

// File Line: 378
// RVA: 0x4FF880
void __fastcall UFG::TSVector3::Mthd_get_z(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v2[2].vfptr->get_obj_type));
  }
}

// File Line: 390
// RVA: 0x50B3F0
void __fastcall UFG::TSVector3::Mthd_set_xyz(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r9
  SSInstance **v3; // r10
  SSData **v4; // rdx
  SSObjectBaseVtbl *v5; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = pScope->i_data.i_array_p;
  v5 = v2[2].vfptr;
  LODWORD(v5->__vecDelDtor) = (*v4)->i_data_p->i_user_data;
  HIDWORD(v5->__vecDelDtor) = v4[1]->i_data_p->i_user_data;
  LODWORD(v5->get_obj_type) = v4[2]->i_data_p->i_user_data;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 410
// RVA: 0x50B2E0
void __fastcall UFG::TSVector3::Mthd_set_x(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v2[2].vfptr->__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( ppResult )
  {
    ++LODWORD(v2[1].vfptr);
    *ppResult = (SSInstance *)v2;
  }
}

// File Line: 427
// RVA: 0x50B450
void __fastcall UFG::TSVector3::Mthd_set_y(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // r8

  v2 = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  *(_DWORD *)(v2->i_user_data + 4) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( ppResult )
  {
    ++v2->i_ref_count;
    *ppResult = v2;
  }
}

// File Line: 445
// RVA: 0x50B490
void __fastcall UFG::TSVector3::Mthd_set_z(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // r8

  v2 = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  *(_DWORD *)(v2->i_user_data + 8) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( ppResult )
  {
    ++v2->i_ref_count;
    *ppResult = v2;
  }
}

// File Line: 462
// RVA: 0x5027C0
void __fastcall UFG::TSVector3::Mthd_is_near(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  SSData **v4; // rdx
  float *v5; // rax
  float *v6; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    v4 = pScope->i_data.i_array_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = (float *)v2[2].vfptr;
    v6 = (float *)(*v4)->i_data_p->i_user_data;
    *v3 = (SSInstance *)SSBoolean::pool_new((float)((float)((float)((float)(v5[1] - v6[1]) * (float)(v5[1] - v6[1]))
                                                          + (float)((float)(*v5 - *v6) * (float)(*v5 - *v6)))
                                                  + (float)((float)(v5[2] - v6[2]) * (float)(v5[2] - v6[2]))) <= *(float *)&v4[1]->i_data_p->i_user_data);
  }
}

// File Line: 476
// RVA: 0x503EE0
void __fastcall UFG::TSVector3::Mthd_is_zero(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInvokedMethod *v3; // r9
  bool v4; // cl
  float *v5; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = pScope;
    v4 = 0;
    if ( !v2 || v3->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = (float *)v2[2].vfptr;
    if ( *v5 == 0.0 && 0.0 == v5[1] && 0.0 == v5[2] )
      v4 = 1;
    *ppResult = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 488
// RVA: 0x50E770
void __fastcall UFG::TSVector3::Mthd_zero(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // r8
  unsigned __int64 v3; // rax

  v2 = (SSInstance *)pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2->i_user_data;
  *(_QWORD *)v3 = 0i64;
  *(_DWORD *)(v3 + 8) = 0;
  if ( ppResult )
  {
    ++v2->i_ref_count;
    *ppResult = v2;
  }
}

// File Line: 508
// RVA: 0x4F4BB0
void __fastcall UFG::TSVector3::Mthd_angle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  SSInstance **v5; // rbx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = pScope;
    v4 = pScope->i_scope_p.i_obj_p;
    v5 = ppResult;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    user_data = UFG::qAngleBetween((UFG::qVector3 *)v4[2].vfptr, (UFG::qVector3 *)(*v2)->i_data_p->i_user_data);
    *v5 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 522
// RVA: 0x4F8610
void __fastcall UFG::TSVector3::Mthd_distance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  float *v3; // rcx
  SSObjectBaseVtbl *v4; // rax
  __m128 v5; // xmm2
  float v6; // xmm0_4

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = v2[2].vfptr;
    v5 = (__m128)HIDWORD(v4->__vecDelDtor);
    v6 = *(float *)&v4->get_obj_type - v3[2];
    v5.m128_f32[0] = (float)((float)((float)(v5.m128_f32[0] - v3[1]) * (float)(v5.m128_f32[0] - v3[1]))
                           + (float)((float)(*(float *)&v4->__vecDelDtor - *v3)
                                   * (float)(*(float *)&v4->__vecDelDtor - *v3)))
                   + (float)(v6 * v6);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)*(_OWORD *)&_mm_sqrt_ps(v5));
  }
}

// File Line: 536
// RVA: 0x4F86A0
void __fastcall UFG::TSVector3::Mthd_distance_squared(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  float *v3; // rcx
  float *v4; // rax
  float v5; // xmm2_4

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = (float *)v2[2].vfptr;
    v5 = v4[1] - v3[1];
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_real_class_p,
                  COERCE_UNSIGNED_INT(
                    (float)((float)(v5 * v5) + (float)((float)(*v4 - *v3) * (float)(*v4 - *v3)))
                  + (float)((float)(v4[2] - v3[2]) * (float)(v4[2] - v3[2]))));
  }
}

// File Line: 550
// RVA: 0x503F80
void __fastcall UFG::TSVector3::Mthd_length(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  float *v3; // rax
  __m128 v4; // xmm2

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = (float *)v2[2].vfptr;
    v4 = (__m128)*(unsigned int *)v3;
    v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3[1] * v3[1])) + (float)(v3[2] * v3[2]);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, (unsigned int)*(_OWORD *)&_mm_sqrt_ps(v4));
  }
}

// File Line: 562
// RVA: 0x503FF0
void __fastcall UFG::TSVector3::Mthd_length_squared(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  float *v3; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v3 = (float *)v2[2].vfptr;
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_real_class_p,
                  COERCE_UNSIGNED_INT((float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])) + (float)(v3[2] * v3[2])));
  }
}

// File Line: 574
// RVA: 0x4F5120
void __fastcall UFG::TSVector3::Mthd_as_normalize(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  float *v4; // rax
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
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (float *)v3[2].vfptr;
    v5 = v4[1];
    v6 = (__m128)*(unsigned int *)v4;
    v7 = v4[2];
    v8 = v6;
    v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
    v9 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data / COERCE_FLOAT(_mm_sqrt_ps(v8));
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
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v13);
  }
}

// File Line: 588
// RVA: 0x504F80
void __fastcall UFG::TSVector3::Mthd_normalize(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // r9
  float *v4; // rdx
  float v5; // xmm6_4
  __m128 v6; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm2
  float v9; // xmm3_4

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = (float *)v2[2].vfptr;
  v5 = v4[1];
  v6 = (__m128)*(unsigned int *)v4;
  v7 = v4[2];
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  v9 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data / COERCE_FLOAT(_mm_sqrt_ps(v8));
  *v4 = v6.m128_f32[0] * v9;
  v4[1] = v5 * v9;
  v4[2] = v7 * v9;
  if ( v3 )
  {
    ++LODWORD(v2[1].vfptr);
    *v3 = (SSInstance *)v2;
  }
}

// File Line: 606
// RVA: 0x4F8800
void __fastcall UFG::TSVector3::Mthd_dot(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSInstance *v3; // rdx
  SSObjectBase *v4; // r8

  if ( ppResult )
  {
    v2 = ppResult;
    v4 = pScope->i_scope_p.i_obj_p;
    if ( !v4 || pScope->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v3 = (*pScope->i_data.i_array_p)->i_data_p;
    *v2 = SSInstance::pool_new(
            SSBrain::c_real_class_p,
            COERCE_UNSIGNED_INT(
              (float)((float)(*((float *)&v4[2].vfptr->__vecDelDtor + 1) * *(float *)(v3->i_user_data + 4))
                    + (float)(*(float *)v3->i_user_data * *(float *)&v4[2].vfptr->__vecDelDtor))
            + (float)(*(float *)&v4[2].vfptr->get_obj_type * *(float *)(v3->i_user_data + 8))));
  }
}

// File Line: 620
// RVA: 0x4F7150
void __fastcall UFG::TSVector3::Mthd_cross(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  float *v4; // rcx
  float *v5; // rax
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float *v9; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = (float *)v3[2].vfptr;
    v6 = (float)(*v5 * v4[1]) - (float)(*v4 * v5[1]);
    v7 = (float)(v5[2] * *v4) - (float)(v4[2] * *v5);
    v8 = (float)(v4[2] * v5[1]) - (float)(v5[2] * v4[1]);
    v9 = (float *)UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v9 )
    {
      *v9 = v8;
      v9[1] = v7;
      v9[2] = v6;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v9);
  }
}

