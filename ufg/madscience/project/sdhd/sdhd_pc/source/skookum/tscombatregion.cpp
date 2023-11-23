// File Line: 64
// RVA: 0x4D2AA0
void UFG::TSCombatRegion::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  UFG::TSCombatRegion::mspCombatRegionClass = SSBrain::get_class("CombatRegion");
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_bounding_box",
    UFG::TSCombatRegion::Mthd_get_bounding_box,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_bounding_radius",
    UFG::TSCombatRegion::Mthd_get_bounding_radius,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_center",
    UFG::TSCombatRegion::Mthd_get_center,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "is_hit_pos",
    UFG::TSCombatRegion::Mthd_is_hit_pos,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "find_named",
    UFG::TSCombatRegion::MthdC_find_named,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSCombatRegion::mspCombatRegionClass,
    "get_named",
    UFG::TSCombatRegion::MthdC_get_named,
    1,
    rebinda);
}

// File Line: 87
// RVA: 0x4FB8B0
void __fastcall UFG::TSCombatRegion::Mthd_get_bounding_box(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::allocator::free_link *v4; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  SSInstance *v7; // rsi
  SSData *v8; // rdi
  SSInstance *i_data_p; // rcx
  bool v10; // zf
  UFG::allocator::free_link *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  SSInstance *v14; // rax
  SSInstance *v15; // rdi
  __int64 v16; // rbx
  _DWORD *v17; // rcx
  UFG::qBox pBox; // [rsp+28h] [rbp-20h] BYREF

  memset(&pBox, 0, sizeof(pBox));
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::RegionComponent::GetBoundingBox((UFG::RegionComponent *)i_obj_p[2].vfptr[2].set_data_by_name, &pBox);
  v4 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v4 )
  {
    y = pBox.mMin.y;
    z = pBox.mMin.z;
    *(float *)&v4->mNext = pBox.mMin.x;
    *((float *)&v4->mNext + 1) = y;
    *(float *)&v4[1].mNext = z;
  }
  v7 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v4);
  v8 = *pScope->i_data.i_array_p;
  i_data_p = v8->i_data_p;
  v10 = i_data_p->i_ref_count-- == 1;
  if ( v10 )
  {
    i_data_p->i_ref_count = 0x80000000;
    i_data_p->vfptr[1].get_scope_context(i_data_p);
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
  v16 = *((_QWORD *)pScope->i_data.i_array_p + 1);
  v17 = *(_DWORD **)(v16 + 8);
  v10 = v17[4]-- == 1;
  if ( v10 )
  {
    v17[4] = 0x80000000;
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v17 + 112i64))(v17);
    *(_QWORD *)(v16 + 8) = v15;
  }
  else
  {
    *(_QWORD *)(v16 + 8) = v14;
  }
}

// File Line: 101
// RVA: 0x4FBB70
void __fastcall UFG::TSCombatRegion::Mthd_get_bounding_radius(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  __int64 v4; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4 = *((_QWORD *)i_obj_p[2].vfptr[2].set_data_by_name + 10);
    user_data = (*(float (__fastcall **)(__int64))(*(_QWORD *)v4 + 32i64))(v4);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 115
// RVA: 0x4FBE40
void __fastcall UFG::TSCombatRegion::Mthd_get_center(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::allocator::free_link *v4; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 pPos; // [rsp+28h] [rbp-20h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    UFG::RegionComponent::GetCenter((UFG::RegionComponent *)i_obj_p[2].vfptr[2].set_data_by_name, &pPos);
    v4 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
    if ( v4 )
    {
      y = pPos.y;
      z = pPos.z;
      *(float *)&v4->mNext = pPos.x;
      *((float *)&v4->mNext + 1) = y;
      *(float *)&v4[1].mNext = z;
    }
    *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v4);
  }
}

// File Line: 129
// RVA: 0x501810
void __fastcall UFG::TSCombatRegion::Mthd_is_hit_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  bool IsHitPoint; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    IsHitPoint = UFG::RegionComponent::IsHitPoint(
                   (UFG::RegionComponent *)i_obj_p[2].vfptr[2].set_data_by_name,
                   (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *ppResult = SSBoolean::pool_new(IsHitPoint);
  }
}

// File Line: 147
// RVA: 0x4E6420
void __fastcall UFG::TSCombatRegion::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::CombatRegion::msCombatRegions.mTree, i_user_data)) != 0i64
      && v4 != (UFG::qBaseTreeRB *)136 )
    {
      *ppResult = SSInstance::pool_new(UFG::TSCombatRegion::mspCombatRegionClass, (unsigned __int64)v4[-2].mRoot.mChild);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 165
// RVA: 0x4E81C0
void __fastcall UFG::TSCombatRegion::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax
  unsigned __int64 mChild; // rdx

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data && (v4 = UFG::qBaseTreeRB::Get(&UFG::CombatRegion::msCombatRegions.mTree, i_user_data)) != 0i64 )
      mChild = (unsigned __int64)v4[-2].mRoot.mChild;
    else
      mChild = 0i64;
    *ppResult = SSInstance::pool_new(UFG::TSCombatRegion::mspCombatRegionClass, mChild);
  }
}

