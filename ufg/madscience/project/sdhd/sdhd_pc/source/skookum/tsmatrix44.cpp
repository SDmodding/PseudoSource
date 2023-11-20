// File Line: 36
// RVA: 0x4D43A0
void __fastcall UFG::TSMatrix44::BindAtomics(UFG::TSMatrix44 *this)
{
  sMatrix44Class = SSBrain::get_class("Matrix44");
  SSClass::register_method_func(sMatrix44Class, &ASymbolX_ctor, UFG::TSMatrix44::Mthd_constructor, 0);
  SSClass::register_method_func(sMatrix44Class, &ASymbolX_ctor_copy, UFG::TSMatrix44::Mthd_ctor_copy, 0);
  SSClass::register_method_func(sMatrix44Class, "!xyz", UFG::TSMatrix44::Mthd_ctor_xyz, 0);
  SSClass::register_method_func(sMatrix44Class, &ASymbolX_dtor, UFG::TSVector3::Mthd_destructor, 0);
}

// File Line: 48
// RVA: 0x4F6B00
void __fastcall UFG::TSMatrix44::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  SSObjectBase *v17; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0x40ui64, "Skookum.qMatrix44", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v5 = UFG::qMatrix44::msIdentity.v0.y;
    v6 = UFG::qMatrix44::msIdentity.v0.z;
    v7 = UFG::qMatrix44::msIdentity.v0.w;
    *(float *)&v3->mNext = UFG::qMatrix44::msIdentity.v0.x;
    *((float *)&v3->mNext + 1) = v5;
    *(float *)&v3[1].mNext = v6;
    *((float *)&v3[1].mNext + 1) = v7;
    v8 = UFG::qMatrix44::msIdentity.v1.y;
    v9 = UFG::qMatrix44::msIdentity.v1.z;
    v10 = UFG::qMatrix44::msIdentity.v1.w;
    *(float *)&v3[2].mNext = UFG::qMatrix44::msIdentity.v1.x;
    *((float *)&v3[2].mNext + 1) = v8;
    *(float *)&v3[3].mNext = v9;
    *((float *)&v3[3].mNext + 1) = v10;
    v11 = UFG::qMatrix44::msIdentity.v2.y;
    v12 = UFG::qMatrix44::msIdentity.v2.z;
    v13 = UFG::qMatrix44::msIdentity.v2.w;
    *(float *)&v3[4].mNext = UFG::qMatrix44::msIdentity.v2.x;
    *((float *)&v3[4].mNext + 1) = v11;
    *(float *)&v3[5].mNext = v12;
    *((float *)&v3[5].mNext + 1) = v13;
    v14 = UFG::qMatrix44::msIdentity.v3.y;
    v15 = UFG::qMatrix44::msIdentity.v3.z;
    v16 = UFG::qMatrix44::msIdentity.v3.w;
    *(float *)&v3[6].mNext = UFG::qMatrix44::msIdentity.v3.x;
    *((float *)&v3[6].mNext + 1) = v14;
    *(float *)&v3[7].mNext = v15;
    *((float *)&v3[7].mNext + 1) = v16;
  }
  else
  {
    v4 = 0i64;
  }
  v17 = v2->i_scope_p.i_obj_p;
  if ( v17 && v2->i_scope_p.i_ptr_id == v17->i_ptr_id )
    v17[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 55
// RVA: 0x4F7390
void __fastcall UFG::TSMatrix44::Mthd_ctor_copy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // r8
  _DWORD *v5; // rcx
  int v6; // xmm1_4
  int v7; // xmm2_4
  int v8; // xmm3_4
  int v9; // xmm1_4
  int v10; // xmm2_4
  int v11; // xmm3_4
  int v12; // xmm1_4
  int v13; // xmm2_4
  int v14; // xmm3_4
  int v15; // xmm1_4
  int v16; // xmm2_4
  int v17; // xmm3_4
  SSObjectBase *v18; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0x40ui64, "Skookum.qMatrix44", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v5 = (_DWORD *)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
    v6 = v5[1];
    v7 = v5[2];
    v8 = v5[3];
    LODWORD(v3->mNext) = *v5;
    HIDWORD(v3->mNext) = v6;
    LODWORD(v3[1].mNext) = v7;
    HIDWORD(v3[1].mNext) = v8;
    v9 = v5[5];
    v10 = v5[6];
    v11 = v5[7];
    LODWORD(v3[2].mNext) = v5[4];
    HIDWORD(v3[2].mNext) = v9;
    LODWORD(v3[3].mNext) = v10;
    HIDWORD(v3[3].mNext) = v11;
    v12 = v5[9];
    v13 = v5[10];
    v14 = v5[11];
    LODWORD(v3[4].mNext) = v5[8];
    HIDWORD(v3[4].mNext) = v12;
    LODWORD(v3[5].mNext) = v13;
    HIDWORD(v3[5].mNext) = v14;
    v15 = v5[13];
    v16 = v5[14];
    v17 = v5[15];
    LODWORD(v3[6].mNext) = v5[12];
    HIDWORD(v3[6].mNext) = v15;
    LODWORD(v3[7].mNext) = v16;
    HIDWORD(v3[7].mNext) = v17;
  }
  else
  {
    v4 = 0i64;
  }
  v18 = v2->i_scope_p.i_obj_p;
  if ( v18 && v2->i_scope_p.i_ptr_id == v18->i_ptr_id )
    v18[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 62
// RVA: 0x4F7620
void __fastcall UFG::TSMatrix44::Mthd_ctor_xyz(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  SSObjectBase *v17; // rcx

  v2 = pScope;
  v3 = UFG::qMalloc(0x40ui64, "Skookum.qMatrix44", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v5 = UFG::qMatrix44::msIdentity.v0.y;
    v6 = UFG::qMatrix44::msIdentity.v0.z;
    v7 = UFG::qMatrix44::msIdentity.v0.w;
    *(float *)&v3->mNext = UFG::qMatrix44::msIdentity.v0.x;
    *((float *)&v3->mNext + 1) = v5;
    *(float *)&v3[1].mNext = v6;
    *((float *)&v3[1].mNext + 1) = v7;
    v8 = UFG::qMatrix44::msIdentity.v1.y;
    v9 = UFG::qMatrix44::msIdentity.v1.z;
    v10 = UFG::qMatrix44::msIdentity.v1.w;
    *(float *)&v3[2].mNext = UFG::qMatrix44::msIdentity.v1.x;
    *((float *)&v3[2].mNext + 1) = v8;
    *(float *)&v3[3].mNext = v9;
    *((float *)&v3[3].mNext + 1) = v10;
    v11 = UFG::qMatrix44::msIdentity.v2.y;
    v12 = UFG::qMatrix44::msIdentity.v2.z;
    v13 = UFG::qMatrix44::msIdentity.v2.w;
    *(float *)&v3[4].mNext = UFG::qMatrix44::msIdentity.v2.x;
    *((float *)&v3[4].mNext + 1) = v11;
    *(float *)&v3[5].mNext = v12;
    *((float *)&v3[5].mNext + 1) = v13;
    v14 = UFG::qMatrix44::msIdentity.v3.y;
    v15 = UFG::qMatrix44::msIdentity.v3.z;
    v16 = UFG::qMatrix44::msIdentity.v3.w;
    *(float *)&v3[6].mNext = UFG::qMatrix44::msIdentity.v3.x;
    *((float *)&v3[6].mNext + 1) = v14;
    *(float *)&v3[7].mNext = v15;
    *((float *)&v3[7].mNext + 1) = v16;
  }
  else
  {
    v4 = 0i64;
  }
  LODWORD(v4[6].mNext) = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
  HIDWORD(v4[6].mNext) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
  LODWORD(v4[7].mNext) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64) + 32i64);
  v17 = v2->i_scope_p.i_obj_p;
  if ( v17 && v2->i_scope_p.i_ptr_id == v17->i_ptr_id )
    v17[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 74
// RVA: 0x4F7F20
void __fastcall UFG::TSVector3::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  operator delete[](v3[2].vfptr);
}

