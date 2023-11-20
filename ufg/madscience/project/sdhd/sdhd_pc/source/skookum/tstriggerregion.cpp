// File Line: 65
// RVA: 0x4CC750
SSInstance *__fastcall UFG::TSTriggerRegion::AsInstance(UFG::TriggerRegion *trigger)
{
  return SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)trigger);
}

// File Line: 83
// RVA: 0x4E1040
UFG::qBaseNodeRB *__fastcall UFG::TSTriggerRegion::GetArgByNameOrInstance(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSInstance *v2; // rbx
  SSClass *v3; // rax
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  SSClass *v7; // rcx

  v2 = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( v2 )
  {
    v3 = v2->i_class_p;
    if ( v3 == SSBrain::c_symbol_class_p )
    {
      v4 = v2->i_user_data;
      if ( v4 )
      {
        v5 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v4);
        if ( v5 )
          return &v5[-2].mNULL;
      }
    }
    else
    {
      if ( UFG::TSTriggerRegion::mspTriggerRegionClass == v3 )
        return (UFG::qBaseNodeRB *)v2->i_user_data;
      v7 = v3->i_superclass_p;
      if ( v7 )
      {
        if ( SSClass::is_class(v7, UFG::TSTriggerRegion::mspTriggerRegionClass) )
          return (UFG::qBaseNodeRB *)v2->i_user_data;
      }
    }
  }
  return 0i64;
}

// File Line: 115
// RVA: 0x4FBA10
void __fastcall UFG::TSTriggerRegion::Mthd_get_bounding_box(SSInvokedMethod *pScope, SSInstance **ppResult)
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
  UFG::RegionComponent::GetBoundingBox((UFG::RegionComponent *)v3[2].vfptr[3].as_instance, &pBox);
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

// File Line: 129
// RVA: 0x4FBBD0
void __usercall UFG::TSTriggerRegion::Mthd_get_bounding_radius(SSInvokedMethod *pScope@<rcx>, SSInstance **ppResult@<rdx>, unsigned int a3@<xmm0>)
{
  SSObjectBase *v3; // r8
  SSInstance **v4; // rbx

  if ( ppResult )
  {
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = ppResult;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    (*(void (**)(void))(**((_QWORD **)v3[2].vfptr[3].as_instance + 10) + 32i64))();
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, a3);
  }
}

// File Line: 143
// RVA: 0x4FBEE0
void __fastcall UFG::TSTriggerRegion::Mthd_get_center(SSInvokedMethod *pScope, SSInstance **ppResult)
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
    UFG::RegionComponent::GetCenter((UFG::RegionComponent *)v3[2].vfptr[3].as_instance, &pPos);
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

// File Line: 157
// RVA: 0x501870
void __fastcall UFG::TSTriggerRegion::Mthd_is_hit_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  SSObjectBaseVtbl *v4; // rax
  bool v5; // dl
  UFG::RegionComponent *v6; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    v5 = 0;
    if ( v4 )
    {
      v6 = (UFG::RegionComponent *)v4[3].as_instance;
      if ( v6 )
        v5 = UFG::RegionComponent::IsHitPoint(v6, (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 185
// RVA: 0x5018E0
void __fastcall UFG::TSTriggerRegion::Mthd_is_hit_segment(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // r9
  SSObjectBase *v5; // rax
  SSData **v6; // rcx
  SSInstance *v7; // rdx
  SSInstance *v8; // rcx
  bool v9; // al

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    v4 = pScope;
    if ( v2 && pScope->i_scope_p.i_ptr_id == v2->i_ptr_id )
      v5 = pScope->i_scope_p.i_obj_p;
    else
      v5 = 0i64;
    if ( v5[2].vfptr[3].as_instance )
    {
      v6 = pScope->i_data.i_array_p;
      v7 = v6[1]->i_data_p;
      v8 = (*v6)->i_data_p;
      if ( !v2 || v4->i_scope_p.i_ptr_id != v2->i_ptr_id )
        v2 = 0i64;
      v9 = UFG::RegionComponent::IsHitSegment(
             (UFG::RegionComponent *)v2[2].vfptr[3].as_instance,
             (UFG::qVector3 *)v8->i_user_data,
             (UFG::qVector3 *)v7->i_user_data,
             0i64);
      *v3 = (SSInstance *)SSBoolean::pool_new(v9);
    }
    else
    {
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 203
// RVA: 0x5019E0
void __fastcall UFG::TSTriggerRegion::Mthd_is_hot_tracking(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(((_QWORD)v2[2].vfptr[3].__vecDelDtor & 0x12) == 18);
  }
}

// File Line: 218
// RVA: 0x503A50
void __fastcall UFG::TSTriggerRegion::Mthd_is_tracking(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new((LODWORD(v2[2].vfptr[3].__vecDelDtor) >> 4) & 1);
  }
}

// File Line: 233
// RVA: 0x503A00
void __fastcall UFG::TSTriggerRegion::Mthd_is_tracked_inside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(((_QWORD)v2[2].vfptr[3].__vecDelDtor & 0x10012) == 65554);
  }
}

// File Line: 251
// RVA: 0x503E60
void __fastcall UFG::TSTriggerRegion::Mthd_is_visible_on_screen(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSInstance **v4; // rbx
  bool v5; // al

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    v4 = ppResult;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v5 = UFG::TriggerRegion::IsVisibleOnScreen((UFG::TriggerRegion *)v3[2].vfptr);
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 268
// RVA: 0x4E6750
void __fastcall UFG::TSTriggerRegion::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v3)) != 0i64
      && v4 != (UFG::qBaseTreeRB *)112 )
    {
      *v2 = SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)&v4[-2].mNULL);
    }
    else
    {
      *v2 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 286
// RVA: 0x4E8450
void __fastcall UFG::TSTriggerRegion::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  unsigned __int64 v5; // rdx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3 && (v4 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v3)) != 0i64 )
      v5 = (unsigned __int64)&v4[-2].mNULL;
    else
      v5 = 0i64;
    *v2 = SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, v5);
  }
}

// File Line: 319
// RVA: 0x50E7E0
SSInstance *__fastcall UFG::TSTriggerRegion::ObjectIdLookup(SSObjectId *pObjId)
{
  unsigned int v1; // edx
  SSObjectId *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  SSInstance *result; // rax

  v1 = pObjId->i_name.i_uid;
  v2 = pObjId;
  if ( v1
    && (v3 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v1)) != 0i64
    && v3 != (UFG::qBaseTreeRB *)112 )
  {
    result = SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)&v3[-2].mNULL);
    --result->i_ref_count;
    v2->i_obj_p.i_obj_p = result;
    v2->i_obj_p.i_ptr_id = result->i_ptr_id;
    v2->i_flags |= 4u;
  }
  else
  {
    v2->i_flags &= 0xFFFFFFFB;
    result = 0i64;
  }
  return result;
}

// File Line: 345
// RVA: 0x4D72C0
void UFG::TSTriggerRegion::BindAtomics(void)
{
  UFG::TSTriggerRegion::mspTriggerRegionClass = SSBrain::get_class("TriggerRegion");
  SSClass::set_object_id_lookup_func(UFG::TSTriggerRegion::mspTriggerRegionClass, UFG::TSTriggerRegion::ObjectIdLookup);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_bounding_box",
    UFG::TSTriggerRegion::Mthd_get_bounding_box,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_bounding_radius",
    UFG::TSTriggerRegion::Mthd_get_bounding_radius,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_center",
    UFG::TSTriggerRegion::Mthd_get_center,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_hit_pos",
    UFG::TSTriggerRegion::Mthd_is_hit_pos,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_hit_segment",
    UFG::TSTriggerRegion::Mthd_is_hit_segment,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_hot_tracking",
    UFG::TSTriggerRegion::Mthd_is_hot_tracking,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_tracking",
    UFG::TSTriggerRegion::Mthd_is_tracking,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_tracked_inside",
    UFG::TSTriggerRegion::Mthd_is_tracked_inside,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_visible_on_screen",
    UFG::TSTriggerRegion::Mthd_is_visible_on_screen,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "find_named",
    UFG::TSTriggerRegion::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_named",
    UFG::TSTriggerRegion::MthdC_get_named,
    1,
    0);
}

