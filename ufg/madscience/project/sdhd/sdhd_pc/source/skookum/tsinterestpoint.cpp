// File Line: 65
// RVA: 0x4CC630
SSInstance *__fastcall UFG::TSInterestPoint::AsInstance(UFG::InterestPoint *poi)
{
  UFG::CollectibleComponent *CollectibleComponent; // rax
  SSClass *v3; // rcx

  CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(poi->m_pSimObject);
  v3 = UFG::TSCollectible::mspCollectibleClass;
  if ( !CollectibleComponent )
    v3 = UFG::TSInterestPoint::mspInterestPointClass;
  return SSInstance::pool_new(v3, (unsigned __int64)poi);
}

// File Line: 122
// RVA: 0x4D4020
void UFG::TSInterestPoint::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]

  UFG::TSInterestPoint::mspInterestPointClass = SSBrain::get_class("InterestPoint");
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "enable_interest_point",
    UFG::TSInterestPoint::Mthd_enable_interest_point,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_child_poi",
    UFG::TSInterestPoint::Mthd_get_child_poi,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_parent_poi",
    UFG::TSInterestPoint::Mthd_get_parent_poi,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "enable_child_pois",
    UFG::TSInterestPoint::Mthd_enable_child_pois,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "finish",
    UFG::TSInterestPoint::Mthd_finish,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "is_active",
    UFG::TSInterestPoint::Mthd_is_active,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "is_in_use",
    UFG::TSInterestPoint::Mthd_is_in_use,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_user",
    UFG::TSInterestPoint::Mthd_get_user,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_named",
    UFG::TSInterestPoint::MthdC_find_named,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_nearest_min",
    UFG::TSInterestPoint::MthdC_find_nearest_min,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_nearest_max",
    UFG::TSInterestPoint::MthdC_find_nearest_max,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_nearest_min_max",
    UFG::TSInterestPoint::MthdC_find_nearest_min_max,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_named",
    UFG::TSInterestPoint::MthdC_get_named,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "list_parents",
    UFG::TSInterestPoint::MthdC_list_parents,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "force_update_can_path_to",
    UFG::TSInterestPoint::MthdC_force_update_can_path_to,
    1,
    rebindf);
}

// File Line: 156
// RVA: 0x4E6490
void __fastcall UFG::TSInterestPoint::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::InterestPoint *Named; // rax
  unsigned __int64 v4; // rbx

  if ( ppResult )
  {
    Named = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = (unsigned __int64)Named;
    if ( Named )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(Named->m_pSimObject) )
        *ppResult = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v4);
      else
        *ppResult = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v4);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 174
// RVA: 0x4E6870
void __fastcall UFG::TSInterestPoint::MthdC_find_nearest_min(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  float v4; // xmm2_4
  UFG::InterestPoint *NearestMinOfType; // rax
  unsigned __int64 v6; // rbx

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    v4 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
    NearestMinOfType = UFG::InterestPoint::FindNearestMinOfType(
                         (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
                         (UFG::qSymbol *)&i_array_p[1]->i_data_p->i_user_data,
                         v4 * v4,
                         3.4028235e38,
                         0i64);
    v6 = (unsigned __int64)NearestMinOfType;
    if ( NearestMinOfType )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(NearestMinOfType->m_pSimObject) )
        *ppResult = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v6);
      else
        *ppResult = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v6);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 198
// RVA: 0x4E67B0
void __fastcall UFG::TSInterestPoint::MthdC_find_nearest_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  float v4; // xmm3_4
  UFG::InterestPoint *NearestMaxOfType; // rax
  unsigned __int64 v6; // rbx

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    v4 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
    NearestMaxOfType = UFG::InterestPoint::FindNearestMaxOfType(
                         (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
                         (UFG::qSymbol *)&i_array_p[1]->i_data_p->i_user_data,
                         0.0,
                         v4 * v4,
                         0i64);
    v6 = (unsigned __int64)NearestMaxOfType;
    if ( NearestMaxOfType )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(NearestMaxOfType->m_pSimObject) )
        *ppResult = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v6);
      else
        *ppResult = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v6);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 223
// RVA: 0x4E6930
void __fastcall UFG::TSInterestPoint::MthdC_find_nearest_min_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r10
  float v4; // xmm1_4
  float v5; // xmm0_4
  UFG::InterestPoint *NearestMinMaxOfType; // rax
  unsigned __int64 v7; // rbx

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    v4 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
    v5 = *(float *)&i_array_p[3]->i_data_p->i_user_data;
    NearestMinMaxOfType = UFG::InterestPoint::FindNearestMinMaxOfType(
                            (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
                            i_array_p[4]->i_data_p->i_user_data != 0,
                            i_array_p[5]->i_data_p->i_user_data != 0,
                            (UFG::qSymbol *)&i_array_p[1]->i_data_p->i_user_data,
                            v4 * v4,
                            v5 * v5,
                            0i64);
    v7 = (unsigned __int64)NearestMinMaxOfType;
    if ( NearestMinMaxOfType )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(NearestMinMaxOfType->m_pSimObject) )
        *ppResult = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v7);
      else
        *ppResult = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v7);
    }
    else
    {
      *ppResult = SSBrain::c_nil_p;
    }
  }
}

// File Line: 251
// RVA: 0x4E8220
void __fastcall UFG::TSInterestPoint::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::InterestPoint *Named; // rdi
  UFG::CollectibleComponent *CollectibleComponent; // rax
  SSClass *v5; // rcx

  if ( ppResult )
  {
    Named = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(Named->m_pSimObject);
    v5 = UFG::TSCollectible::mspCollectibleClass;
    if ( !CollectibleComponent )
      v5 = UFG::TSInterestPoint::mspInterestPointClass;
    *ppResult = SSInstance::pool_new(v5, (unsigned __int64)Named);
  }
}

// File Line: 277
// RVA: 0x4F8BD0
void __fastcall UFG::TSInterestPoint::Mthd_enable_interest_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSObjectBase *i_obj_p; // rcx
  bool v5; // r10
  bool v6; // r8

  i_array_p = pScope->i_data.i_array_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  v5 = (*i_array_p)->i_data_p->i_user_data != 0;
  v6 = i_array_p[1]->i_data_p->i_user_data != 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::InterestPoint::SetActive((UFG::InterestPoint *)i_obj_p[2].vfptr, v5, v6);
}

// File Line: 290
// RVA: 0x4F9D70
void __fastcall UFG::TSInterestPoint::Mthd_finish(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::InterestPoint *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::InterestPoint *)i_obj_p[2].vfptr;
  UFG::InterestPoint::FinishUsing(vfptr);
  UFG::InterestPoint::EndReservation(vfptr);
}

// File Line: 299
// RVA: 0x5008D0
void __fastcall UFG::TSInterestPoint::Mthd_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  *ppResult = SSBoolean::pool_new(BYTE6(i_obj_p[2].vfptr[6].set_data_by_name) != 0);
}

// File Line: 310
// RVA: 0x501CB0
void __fastcall UFG::TSInterestPoint::Mthd_is_in_use(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  bool IsReservationMatch; // al

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  IsReservationMatch = UFG::InterestPoint::IsReservationMatch(
                         (UFG::InterestPoint *)i_obj_p[2].vfptr,
                         2u,
                         ReserveReason_normal);
  *ppResult = SSBoolean::pool_new(IsReservationMatch);
}

// File Line: 321
// RVA: 0x4FC110
void __fastcall UFG::TSInterestPoint::Mthd_get_child_poi(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int i_user_data; // edx
  void (__fastcall *set_data_by_name)(SSObjectBase *, ASymbol *, SSInstance *); // rcx
  UFG::SimObject *ChildAsSimObject; // rax
  UFG::SimComponent *ComponentOfType; // rax
  unsigned __int64 v8; // rbx
  UFG::CollectibleComponent *CollectibleComponent; // rax
  SSClass *v10; // rcx

  if ( ppResult )
  {
    *ppResult = SSBrain::c_nil_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    set_data_by_name = i_obj_p[2].vfptr->set_data_by_name;
    if ( set_data_by_name )
    {
      ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject(
                           *((UFG::SceneObjectProperties **)set_data_by_name + 10),
                           i_user_data);
      if ( ChildAsSimObject )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(ChildAsSimObject, UFG::InterestPoint::_TypeUID);
        v8 = (unsigned __int64)ComponentOfType;
        if ( ComponentOfType )
        {
          CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(ComponentOfType->m_pSimObject);
          v10 = UFG::TSCollectible::mspCollectibleClass;
          if ( !CollectibleComponent )
            v10 = UFG::TSInterestPoint::mspInterestPointClass;
          *ppResult = SSInstance::pool_new(v10, v8);
        }
      }
    }
  }
}

// File Line: 347
// RVA: 0x4FDCF0
void __fastcall UFG::TSInterestPoint::Mthd_get_parent_poi(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::InterestPoint *vfptr; // rdi
  UFG::SimObject *Parent; // rax
  UFG::SimComponent *ComponentOfType; // rax
  unsigned __int64 v7; // rdi
  UFG::CollectibleComponent *CollectibleComponent; // rax
  SSClass *v9; // rcx

  if ( ppResult )
  {
    *ppResult = SSBrain::c_nil_p;
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::InterestPoint *)i_obj_p[2].vfptr;
    if ( UFG::InterestPoint::GetParent(vfptr) )
    {
      Parent = UFG::InterestPoint::GetParent(vfptr);
      ComponentOfType = UFG::SimObject::GetComponentOfType(Parent, UFG::InterestPoint::_TypeUID);
      v7 = (unsigned __int64)ComponentOfType;
      if ( ComponentOfType )
      {
        CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(ComponentOfType->m_pSimObject);
        v9 = UFG::TSCollectible::mspCollectibleClass;
        if ( !CollectibleComponent )
          v9 = UFG::TSInterestPoint::mspInterestPointClass;
        *ppResult = SSInstance::pool_new(v9, v7);
      }
    }
  }
}

// File Line: 366
// RVA: 0x4F8970
void __fastcall UFG::TSInterestPoint::Mthd_enable_child_pois(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  unsigned int v3; // ebx
  void (__fastcall *set_data_by_name)(SSObjectBase *, ASymbol *, SSInstance *); // rdi
  bool v5; // si
  UFG::SceneObjectProperties *v6; // rax
  UFG::SimObject *ChildAsSimObject; // rax
  UFG::InterestPoint *ComponentOfType; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  set_data_by_name = i_obj_p[2].vfptr->set_data_by_name;
  v5 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( set_data_by_name )
  {
    v6 = (UFG::SceneObjectProperties *)*((_QWORD *)set_data_by_name + 10);
    if ( v6->mChildren.mCount )
    {
      do
      {
        ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject(v6, v3);
        if ( ChildAsSimObject )
        {
          ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(
                                                    ChildAsSimObject,
                                                    UFG::InterestPoint::_TypeUID);
          if ( ComponentOfType )
            UFG::InterestPoint::SetActive(ComponentOfType, v5, 1);
        }
        v6 = (UFG::SceneObjectProperties *)*((_QWORD *)set_data_by_name + 10);
        ++v3;
      }
      while ( v3 < v6->mChildren.mCount );
    }
  }
}

// File Line: 391
// RVA: 0x4FF2D0
void __fastcall UFG::TSInterestPoint::Mthd_get_user(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rcx
  SSInstance *(__fastcall *get_topmost_scope)(SSObjectBase *); // rcx
  UFG::TSActorComponent *ComponentOfType; // rax
  UFG::TSActorComponent *v7; // rbx
  SSActorClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  UFG::TSActor *Actor; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( ppResult )
  {
    *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    get_topmost_scope = vfptr[5].get_topmost_scope;
    if ( get_topmost_scope )
    {
      if ( (*((_BYTE *)get_topmost_scope + 76) & 2) == 0 )
      {
        ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)get_topmost_scope,
                                                     UFG::TSActorComponent::_TypeUID);
        v7 = ComponentOfType;
        if ( ComponentOfType )
        {
          if ( UFG::TSActorComponent::GetActor(ComponentOfType) )
          {
            if ( UFG::TSActorComponent::GetActor(v7)->i_class_p )
            {
              i_class_p = (SSActorClass *)UFG::TSActorComponent::GetActor(v7)->i_class_p;
              if ( UFG::SkookumMgr::mspCharacterClass == i_class_p
                || (i_superclass_p = i_class_p->i_superclass_p) != 0i64
                && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass) )
              {
                Actor = UFG::TSActorComponent::GetActor(v7);
                ++Actor->i_ref_count;
                *ppResult = Actor;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 437
// RVA: 0x4EAA60
void __fastcall UFG::TSInterestPoint::MthdC_list_parents(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::InterestPoint::ListParents((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 447
// RVA: 0x4E6DB0
// attributes: thunk
void __fastcall UFG::TSInterestPoint::MthdC_force_update_can_path_to(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::InterestPoint::ForceUpdateCanPathTo();
}

