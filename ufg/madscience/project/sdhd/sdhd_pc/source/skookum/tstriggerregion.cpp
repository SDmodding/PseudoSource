// File Line: 65
// RVA: 0x4CC750
SSInstance *__fastcall UFG::TSTriggerRegion::AsInstance(UFG::TriggerRegion *trigger)
{
  return SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)trigger);
}

// File Line: 83
// RVA: 0x4E1040
UFG::qBaseNodeRB *__fastcall UFG::TSTriggerRegion::GetArgByNameOrInstance(
        SSInvokedContextBase *pScope,
        unsigned int argPos)
{
  SSInstance *i_data_p; // rbx
  SSClass *i_class_p; // rax
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v5; // rax
  SSClass *i_superclass_p; // rcx

  i_data_p = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( i_class_p == SSBrain::c_symbol_class_p )
    {
      i_user_data = i_data_p->i_user_data;
      if ( i_user_data )
      {
        v5 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, i_user_data);
        if ( v5 )
          return &v5[-2].mNULL;
      }
    }
    else
    {
      if ( UFG::TSTriggerRegion::mspTriggerRegionClass == i_class_p )
        return (UFG::qBaseNodeRB *)i_data_p->i_user_data;
      i_superclass_p = i_class_p->i_superclass_p;
      if ( i_superclass_p )
      {
        if ( SSClass::is_class(i_superclass_p, UFG::TSTriggerRegion::mspTriggerRegionClass) )
          return (UFG::qBaseNodeRB *)i_data_p->i_user_data;
      }
    }
  }
  return 0i64;
}

// File Line: 115
// RVA: 0x4FBA10
void __fastcall UFG::TSTriggerRegion::Mthd_get_bounding_box(SSInvokedMethod *pScope, SSInstance **ppResult)
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
  UFG::RegionComponent::GetBoundingBox((UFG::RegionComponent *)i_obj_p[2].vfptr[3].as_instance, &pBox);
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

// File Line: 129
// RVA: 0x4FBBD0
void __fastcall UFG::TSTriggerRegion::Mthd_get_bounding_radius(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  __int64 v4; // rcx
  float user_data; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    v4 = *((_QWORD *)i_obj_p[2].vfptr[3].as_instance + 10);
    user_data = (*(float (__fastcall **)(__int64))(*(_QWORD *)v4 + 32i64))(v4);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  }
}

// File Line: 143
// RVA: 0x4FBEE0
void __fastcall UFG::TSTriggerRegion::Mthd_get_center(SSInvokedMethod *pScope, SSInstance **ppResult)
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
    UFG::RegionComponent::GetCenter((UFG::RegionComponent *)i_obj_p[2].vfptr[3].as_instance, &pPos);
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

// File Line: 157
// RVA: 0x501870
void __fastcall UFG::TSTriggerRegion::Mthd_is_hit_pos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax
  bool IsHitPoint; // dl
  UFG::RegionComponent *as_instance; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    IsHitPoint = 0;
    if ( vfptr )
    {
      as_instance = (UFG::RegionComponent *)vfptr[3].as_instance;
      if ( as_instance )
        IsHitPoint = UFG::RegionComponent::IsHitPoint(
                       as_instance,
                       (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    }
    *ppResult = SSBoolean::pool_new(IsHitPoint);
  }
}

// File Line: 185
// RVA: 0x5018E0
void __fastcall UFG::TSTriggerRegion::Mthd_is_hit_segment(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBase *v5; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdx
  SSInstance *v8; // rcx
  bool IsHitSegment; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
      v5 = pScope->i_scope_p.i_obj_p;
    else
      v5 = 0i64;
    if ( v5[2].vfptr[3].as_instance )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_data_p = i_array_p[1]->i_data_p;
      v8 = (*i_array_p)->i_data_p;
      if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        i_obj_p = 0i64;
      IsHitSegment = UFG::RegionComponent::IsHitSegment(
                       (UFG::RegionComponent *)i_obj_p[2].vfptr[3].as_instance,
                       (UFG::qVector3 *)v8->i_user_data,
                       (UFG::qVector3 *)i_data_p->i_user_data,
                       0i64);
      *ppResult = SSBoolean::pool_new(IsHitSegment);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 203
// RVA: 0x5019E0
void __fastcall UFG::TSTriggerRegion::Mthd_is_hot_tracking(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(((__int64)i_obj_p[2].vfptr[3].__vecDelDtor & 0x12) == 18);
  }
}

// File Line: 218
// RVA: 0x503A50
void __fastcall UFG::TSTriggerRegion::Mthd_is_tracking(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(((__int64)i_obj_p[2].vfptr[3].__vecDelDtor & 0x10) != 0);
  }
}

// File Line: 233
// RVA: 0x503A00
void __fastcall UFG::TSTriggerRegion::Mthd_is_tracked_inside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSBoolean::pool_new(((__int64)i_obj_p[2].vfptr[3].__vecDelDtor & 0x10012) == 65554);
  }
}

// File Line: 251
// RVA: 0x503E60
void __fastcall UFG::TSTriggerRegion::Mthd_is_visible_on_screen(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  bool IsVisibleOnScreen; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    IsVisibleOnScreen = UFG::TriggerRegion::IsVisibleOnScreen((UFG::TriggerRegion *)i_obj_p[2].vfptr);
    *ppResult = SSBoolean::pool_new(IsVisibleOnScreen);
  }
}

// File Line: 268
// RVA: 0x4E6750
void __fastcall UFG::TSTriggerRegion::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, i_user_data)) != 0i64
      && v4 != (UFG::qBaseTreeRB *)112 )
    {
      *ppResult = SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)&v4[-2].mNULL);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 286
// RVA: 0x4E8450
void __fastcall UFG::TSTriggerRegion::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax
  unsigned __int64 p_mNULL; // rdx

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data && (v4 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, i_user_data)) != 0i64 )
      p_mNULL = (unsigned __int64)&v4[-2].mNULL;
    else
      p_mNULL = 0i64;
    *ppResult = SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, p_mNULL);
  }
}

// File Line: 319
// RVA: 0x50E7E0
SSInstance *__fastcall UFG::TSTriggerRegion::ObjectIdLookup(SSObjectId *pObjId)
{
  unsigned int i_uid; // edx
  UFG::qBaseTreeRB *v3; // rax
  SSInstance *result; // rax

  i_uid = pObjId->i_name.i_uid;
  if ( i_uid
    && (v3 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, i_uid)) != 0i64
    && v3 != (UFG::qBaseTreeRB *)112 )
  {
    result = SSInstance::pool_new(UFG::TSTriggerRegion::mspTriggerRegionClass, (unsigned __int64)&v3[-2].mNULL);
    --result->i_ref_count;
    pObjId->i_obj_p.i_obj_p = result;
    pObjId->i_obj_p.i_ptr_id = result->i_ptr_id;
    pObjId->i_flags |= 4u;
  }
  else
  {
    pObjId->i_flags &= ~4u;
    return 0i64;
  }
  return result;
}

// File Line: 345
// RVA: 0x4D72C0
void UFG::TSTriggerRegion::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  UFG::TSTriggerRegion::mspTriggerRegionClass = SSBrain::get_class("TriggerRegion");
  SSClass::set_object_id_lookup_func(UFG::TSTriggerRegion::mspTriggerRegionClass, UFG::TSTriggerRegion::ObjectIdLookup);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_bounding_box",
    UFG::TSTriggerRegion::Mthd_get_bounding_box,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_bounding_radius",
    UFG::TSTriggerRegion::Mthd_get_bounding_radius,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_center",
    UFG::TSTriggerRegion::Mthd_get_center,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_hit_pos",
    UFG::TSTriggerRegion::Mthd_is_hit_pos,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_hit_segment",
    UFG::TSTriggerRegion::Mthd_is_hit_segment,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_hot_tracking",
    UFG::TSTriggerRegion::Mthd_is_hot_tracking,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_tracking",
    UFG::TSTriggerRegion::Mthd_is_tracking,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_tracked_inside",
    UFG::TSTriggerRegion::Mthd_is_tracked_inside,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "is_visible_on_screen",
    UFG::TSTriggerRegion::Mthd_is_visible_on_screen,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "find_named",
    UFG::TSTriggerRegion::MthdC_find_named,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSTriggerRegion::mspTriggerRegionClass,
    "get_named",
    UFG::TSTriggerRegion::MthdC_get_named,
    1,
    rebinda);
}

