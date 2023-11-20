// File Line: 64
// RVA: 0x4D2AA0
void UFG::TSCombatRegion::BindAtomics(void)
{
  UFG::TSCombatRegion::mspCombatRegionClass = SSBrain::get_class("CombatRegion");
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_bounding_box",
    UFG::TSCombatRegion::Mthd_get_bounding_box,
    0);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_bounding_radius",
    UFG::TSCombatRegion::Mthd_get_bounding_radius,
    0);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_center",
    UFG::TSCombatRegion::Mthd_get_center,
    0);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "is_hit_pos",
    UFG::TSCombatRegion::Mthd_is_hit_pos,
    0);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "find_named",
    UFG::TSCombatRegion::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_named",
    UFG::TSCombatRegion::MthdC_get_named,
    1,
    0);
}

// File Line: 87
// RVA: 0x4FB8B0
void __fastcall UFG::TSCombatRegion::Mthd_get_bounding_box(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSObjectBase *v3; // rdx
  UFG::allocator::free_link *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  SSInstance *v7; // rsi
  SSData *v8; // rdi
  SSInstance *v9; // rcx
  bool v10; // zf
  UFG::allocator::free_link *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  SSInstance *v14; // rax
  SSInstance *v15; // rdi
  __int64 v16; // rbx
  _DWORD *v17; // rcx
  UFG::qBox pBox; // [rsp+28h] [rbp-20h]

  v2 = pScope;
  *(_QWORD *)&pBox.mMin.x = 0i64;
  *(_QWORD *)&pBox.mMin.z = 0i64;
  *(_QWORD *)&pBox.mMax.y = 0i64;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::RegionComponent::GetBoundingBox((UFG::RegionComponent *)v3[2].vfptr[2].set_data_by_name, &pBox);
  v4 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v4 )
  {
    v5 = pBox.mMin.y;
    v6 = pBox.mMin.z;
    *(float *)&v4->mNext = pBox.mMin.x;
    *((float *)&v4->mNext + 1) = v5;
    *(float *)&v4[1].mNext = v6;
  }
  v7 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v4);
  v8 = *v2->i_data.i_array_p;
  v9 = v8->i_data_p;
  v10 = v9->i_ref_count-- == 1;
  if ( v10 )
  {
    v9->i_ref_count = 2147483648;
    ((void (__cdecl *)(SSInstance *))v9->vfptr[1].get_scope_context)(v9);
  }
  v8->i_data_p = v7;
  v11 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v11 )
  {
    v12 = pBox.mMax.y;
    v13 = pBox.mMax.z;
    *(float *)&v11->mNext = pBox.mMax.x;
    *((float *)&v11->mNext + 1) = v12;
    *(float *)&v11[1].mNext = v13;
  }
  v14 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v11);
  v15 = v14;
  v16 = *((_QWORD *)v2->i_data.i_array_p + 1);
  v17 = *(_DWORD **)(v16 + 8);
  v10 = v17[4]-- == 1;
  if ( v10 )
  {
    v17[4] = 2147483648;
    (*(void (__cdecl **)(_DWORD *))(*(_QWORD *)v17 + 112i64))(v17);
    *(_QWORD *)(v16 + 8) = v15;
  }
  else
  {
    *(_QWORD *)(v16 + 8) = v14;
  }
}

// File Line: 101
// RVA: 0x4FBB70
void __usercall UFG::TSCombatRegion::Mthd_get_bounding_radius(SSInvokedMethod *pScope@<rcx>, SSInstance **ppResult@<rdx>, unsigned int a3@<xmm0>)
{
  SSObjectBase *v3; // r8
  SSInstance **v4; // rbx

  if ( ppResult )
  {
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = ppResult;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    (*(void (**)(void))(**((_QWORD **)v3[2].vfptr[2].set_data_by_name + 10) + 32i64))();
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, a3);
  }
}

// File Line: 115
// RVA: 0x4FBE40
void __fastcall UFG::TSCombatRegion::Mthd_get_center(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  UFG::allocator::free_link *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::qVector3 pPos; // [rsp+28h] [rbp-20h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    UFG::RegionComponent::GetCenter((UFG::RegionComponent *)v3[2].vfptr[2].set_data_by_name, &pPos);
    v4 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v4 )
    {
      v5 = pPos.y;
      v6 = pPos.z;
      *(float *)&v4->mNext = pPos.x;
      *((float *)&v4->mNext + 1) = v5;
      *(float *)&v4[1].mNext = v6;
    }
    *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v4);
  }
}

// File Line: 129
// RVA: 0x501810
void __fastcall UFG::TSCombatRegion::Mthd_is_hit_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  bool v4; // al

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = UFG::RegionComponent::IsHitPoint(
           (UFG::RegionComponent *)v2[2].vfptr[2].set_data_by_name,
           (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 147
// RVA: 0x4E6420
void __fastcall UFG::TSCombatRegion::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::CombatRegion::msCombatRegions.mTree, v3)) != 0i64
      && v4 != (UFG::qBaseTreeRB *)136 )
    {
      *v2 = SSInstance::pool_new(UFG::TSCombatRegion::mspCombatRegionClass, (unsigned __int64)v4[-2].mRoot.mChild);
    }
    else
    {
      *v2 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 165
// RVA: 0x4E81C0
void __fastcall UFG::TSCombatRegion::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  unsigned __int64 v5; // rdx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3 && (v4 = UFG::qBaseTreeRB::Get(&UFG::CombatRegion::msCombatRegions.mTree, v3)) != 0i64 )
      v5 = (unsigned __int64)v4[-2].mRoot.mChild;
    else
      v5 = 0i64;
    *v2 = SSInstance::pool_new(UFG::TSCombatRegion::mspCombatRegionClass, v5);
  }
}

